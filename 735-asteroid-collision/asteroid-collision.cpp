class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && asteroid < 0) {
                if (st.back() < -asteroid) {
                    st.pop_back();           // right asteroid explodes
                }
                else if (st.back() == -asteroid) {
                    st.pop_back();           // both explode
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;        // current explodes
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(asteroid);
            }
        }

        return st;
    }
};