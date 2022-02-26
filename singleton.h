class Singleton
{
    public:
        Singleton(const Singleton& src) = delete;
        Singleton& operator=(const Singleton& rhs) = delete;
    public:
        static Singleton* getInstance();
        int getValue() const;
        void setValue (const int val);
    public: 
        ~Singleton();
    private:
        static Singleton* instance;

    private:
        Singleton() = default;
        int m_value{};
};