static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
STATIC T_1
F_3 (
struct V_4 * V_4 ,
struct V_2 * V_3 ,
char * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return V_6 -> V_7 ? V_6 -> V_7 ( V_4 , V_5 ) : 0 ;
}
STATIC T_1
F_4 (
struct V_4 * V_4 ,
struct V_2 * V_3 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return V_6 -> V_9 ? V_6 -> V_9 ( V_4 , V_5 , V_8 ) : 0 ;
}
STATIC T_1
F_5 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_10 ;
int V_11 ;
V_10 = F_6 ( V_5 , 0 , & V_11 ) ;
if ( V_10 )
return V_10 ;
if ( V_11 < 0 || V_11 > 60 )
return - V_12 ;
V_13 . V_14 = V_11 ;
return V_8 ;
}
STATIC T_1
F_7 (
struct V_4 * V_4 ,
char * V_5 )
{
return snprintf ( V_5 , V_15 , L_1 , V_13 . V_14 ) ;
}
static inline struct V_16 *
F_8 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = F_9 ( V_4 ) ;
return F_2 ( V_18 , struct V_16 , V_19 ) ;
}
STATIC T_1
F_10 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_16 * V_20 = F_8 ( V_4 ) ;
return F_11 ( V_20 -> V_21 , V_5 ) ;
}
STATIC T_1
F_12 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_10 ;
int V_11 ;
struct V_16 * V_20 = F_8 ( V_4 ) ;
V_10 = F_6 ( V_5 , 0 , & V_11 ) ;
if ( V_10 )
return V_10 ;
if ( V_11 != 1 )
return - V_12 ;
F_13 ( V_20 -> V_21 ) ;
return V_8 ;
}
static inline struct V_22 *
F_14 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = F_9 ( V_4 ) ;
return F_2 ( V_18 , struct V_22 , V_23 ) ;
}
STATIC T_1
F_15 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_24 ;
int V_25 ;
struct V_22 * log = F_14 ( V_4 ) ;
F_16 ( & log -> V_26 ) ;
V_24 = log -> V_27 ;
V_25 = log -> V_28 ;
F_17 ( & log -> V_26 ) ;
return snprintf ( V_5 , V_15 , L_2 , V_24 , V_25 ) ;
}
STATIC T_1
F_18 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_24 ;
int V_25 ;
struct V_22 * log = F_14 ( V_4 ) ;
F_19 ( & log -> V_29 , & V_24 , & V_25 ) ;
return snprintf ( V_5 , V_15 , L_2 , V_24 , V_25 ) ;
}
STATIC T_1
F_20 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_24 ;
int V_30 ;
struct V_22 * log = F_14 ( V_4 ) ;
F_21 ( & log -> V_31 . V_32 , & V_24 , & V_30 ) ;
return snprintf ( V_5 , V_15 , L_2 , V_24 , V_30 ) ;
}
STATIC T_1
F_22 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_24 ;
int V_30 ;
struct V_22 * log = F_14 ( V_4 ) ;
F_21 ( & log -> V_33 . V_32 , & V_24 , & V_30 ) ;
return snprintf ( V_5 , V_15 , L_2 , V_24 , V_30 ) ;
}
