#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,              //无错误
    LEPT_PARSE_EXPECT_VALUE,        //若json只含有空白
    LEPT_PARSE_INVALID_VALUE,       //若不是其他三种字面值，返回此错误
    LEPT_PARSE_ROOT_NOT_SINGULAR    //若一个值之后，在空白之后还有其他字符
};

/*解析json*/
int lept_parse(lept_value* v, const char* json);

/*获取返回结果*/
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
