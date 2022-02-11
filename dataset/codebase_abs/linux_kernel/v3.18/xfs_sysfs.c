static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
STATIC T_1
F_3 (
const char * V_4 ,
T_2 V_5 ,
void * V_6 )
{
int V_7 ;
int V_8 ;
V_7 = F_4 ( V_4 , 0 , & V_8 ) ;
if ( V_7 )
return V_7 ;
if ( V_8 < 0 || V_8 > 60 )
return - V_9 ;
V_10 . V_11 = V_8 ;
return V_5 ;
}
STATIC T_1
F_5 (
char * V_4 ,
void * V_6 )
{
return snprintf ( V_4 , V_12 , L_1 , V_10 . V_11 ) ;
}
STATIC T_1
F_6 (
struct V_13 * V_13 ,
struct V_2 * V_3 ,
char * V_4 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
return V_14 -> V_15 ? V_14 -> V_15 ( V_4 , NULL ) : 0 ;
}
STATIC T_1
F_7 (
struct V_13 * V_13 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_2 V_5 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
return V_14 -> V_16 ? V_14 -> V_16 ( V_4 , V_5 , NULL ) : 0 ;
}
STATIC T_1
F_8 (
char * V_4 ,
void * V_6 )
{
struct V_17 * log = V_6 ;
int V_18 ;
int V_19 ;
F_9 ( & log -> V_20 ) ;
V_18 = log -> V_21 ;
V_19 = log -> V_22 ;
F_10 ( & log -> V_20 ) ;
return snprintf ( V_4 , V_12 , L_2 , V_18 , V_19 ) ;
}
STATIC T_1
F_11 (
char * V_4 ,
void * V_6 )
{
struct V_17 * log = V_6 ;
int V_18 ;
int V_19 ;
F_12 ( & log -> V_23 , & V_18 , & V_19 ) ;
return snprintf ( V_4 , V_12 , L_2 , V_18 , V_19 ) ;
}
STATIC T_1
F_13 (
char * V_4 ,
void * V_6 )
{
struct V_17 * log = V_6 ;
int V_18 ;
int V_24 ;
F_14 ( & log -> V_25 . V_26 , & V_18 , & V_24 ) ;
return snprintf ( V_4 , V_12 , L_2 , V_18 , V_24 ) ;
}
STATIC T_1
F_15 (
char * V_4 ,
void * V_6 )
{
struct V_17 * log = V_6 ;
int V_18 ;
int V_24 ;
F_14 ( & log -> V_27 . V_26 , & V_18 , & V_24 ) ;
return snprintf ( V_4 , V_12 , L_2 , V_18 , V_24 ) ;
}
static inline struct V_17 *
F_16 ( struct V_13 * V_13 )
{
struct V_28 * V_29 = F_17 ( V_13 ) ;
return F_2 ( V_29 , struct V_17 , V_30 ) ;
}
STATIC T_1
F_18 (
struct V_13 * V_13 ,
struct V_2 * V_3 ,
char * V_4 )
{
struct V_17 * log = F_16 ( V_13 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
return V_14 -> V_15 ? V_14 -> V_15 ( V_4 , log ) : 0 ;
}
STATIC T_1
F_19 (
struct V_13 * V_13 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_2 V_5 )
{
struct V_17 * log = F_16 ( V_13 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
return V_14 -> V_16 ? V_14 -> V_16 ( V_4 , V_5 , log ) : 0 ;
}
