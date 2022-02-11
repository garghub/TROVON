static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
STATIC T_1
F_3 (
char * V_4 ,
void * V_5 )
{
struct V_6 * log = V_5 ;
int V_7 ;
int V_8 ;
F_4 ( & log -> V_9 ) ;
V_7 = log -> V_10 ;
V_8 = log -> V_11 ;
F_5 ( & log -> V_9 ) ;
return snprintf ( V_4 , V_12 , L_1 , V_7 , V_8 ) ;
}
STATIC T_1
F_6 (
char * V_4 ,
void * V_5 )
{
struct V_6 * log = V_5 ;
int V_7 ;
int V_8 ;
F_7 ( & log -> V_13 , & V_7 , & V_8 ) ;
return snprintf ( V_4 , V_12 , L_1 , V_7 , V_8 ) ;
}
STATIC T_1
F_8 (
char * V_4 ,
void * V_5 )
{
struct V_6 * log = V_5 ;
int V_7 ;
int V_14 ;
F_9 ( & log -> V_15 . V_16 , & V_7 , & V_14 ) ;
return snprintf ( V_4 , V_12 , L_1 , V_7 , V_14 ) ;
}
STATIC T_1
F_10 (
char * V_4 ,
void * V_5 )
{
struct V_6 * log = V_5 ;
int V_7 ;
int V_14 ;
F_9 ( & log -> V_17 . V_16 , & V_7 , & V_14 ) ;
return snprintf ( V_4 , V_12 , L_1 , V_7 , V_14 ) ;
}
static inline struct V_6 *
F_11 ( struct V_18 * V_18 )
{
struct V_19 * V_20 = F_12 ( V_18 ) ;
return F_2 ( V_20 , struct V_6 , V_21 ) ;
}
STATIC T_1
F_13 (
struct V_18 * V_18 ,
struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * log = F_11 ( V_18 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
return V_22 -> V_23 ? V_22 -> V_23 ( V_4 , log ) : 0 ;
}
STATIC T_1
F_14 (
struct V_18 * V_18 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_2 V_24 )
{
struct V_6 * log = F_11 ( V_18 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
return V_22 -> V_25 ? V_22 -> V_25 ( V_4 , V_24 , log ) : 0 ;
}
