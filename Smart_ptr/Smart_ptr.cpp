#include <iostream>
template <typename T>
class shared_ptr
{
public:
explicit shared_ptr(T* rhs)
	:m_counter(0)
{ 
	m_ptr = rhs;
	m_counter++;
	}

	~shared_ptr() 
	{
		m_counter--;
		if(m_counter ==0)
		delete m_ptr;
	}

	shared_ptr(const shared_ptr<T>& rhs)
	{
		m_ptr = rhs.m_ptr;
		m_counter = rhs.m_counter;
		m_counter++;
	}
	shared_ptr&	operator=(const shared_ptr<T>& rhs)
	{
		m_ptr = rhs.m_ptr;
		m_counter = rhs.m_counter;
		m_counter++;
		return *this;
	}
	T& operator*()
	{
		return *m_ptr;
	}
	T* operator->()
	{
		return m_ptr;
	}
	
private:
	T* m_ptr;
 static	unsigned int m_counter;
	
};











int main()
{
   
}

