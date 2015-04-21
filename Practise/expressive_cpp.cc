#include <string>
#include <iostream>
#include <boost/proto/proto.hpp>

struct map_ {};
boost::proto::terminal<map_>::type map = {};

template<class Exp>
void format(const std::string& fmt, const Exp& exp)
{
    boost::proto::display_expr(exp);

    using boost::proto::value;
    using boost::proto::child_c;

    std::cout << "key:" << value(child_c<1>(exp)) << ", value:"
            << value(child_c<2>(exp)) << std::endl;
    format(fmt, child_c<0>(exp));
}

void format(const std::string& s, boost::proto::terminal<map_>::type&)
{
}

int main()
{
    format("there are ...", map("place", "heaven and earth")("thing", "philosophy"));
    // format("there are ...", map["place"]("heaven and earth")["thing"]("philosophy"));

    return 0;
}

