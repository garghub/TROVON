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
static inline struct V_10 *
F_5 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_10 , V_13 ) ;
}
STATIC T_1
F_7 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_10 * V_14 = F_5 ( V_4 ) ;
int V_15 ;
int V_16 ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 == 1 )
V_14 -> V_17 = true ;
else if ( V_16 == 0 )
V_14 -> V_17 = false ;
else
return - V_18 ;
return V_8 ;
}
STATIC T_1
F_9 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_10 * V_14 = F_5 ( V_4 ) ;
return snprintf ( V_5 , V_19 , L_1 , V_14 -> V_17 ? 1 : 0 ) ;
}
STATIC T_1
F_10 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_15 ;
int V_16 ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 0 || V_16 > 60 )
return - V_18 ;
V_20 . V_21 = V_16 ;
return V_8 ;
}
STATIC T_1
F_11 (
struct V_4 * V_4 ,
char * V_5 )
{
return snprintf ( V_5 , V_19 , L_1 , V_20 . V_21 ) ;
}
static inline struct V_22 *
F_12 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_22 , V_23 ) ;
}
STATIC T_1
F_13 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_22 * V_24 = F_12 ( V_4 ) ;
return F_14 ( V_24 -> V_25 , V_5 ) ;
}
STATIC T_1
F_15 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_15 ;
int V_16 ;
struct V_22 * V_24 = F_12 ( V_4 ) ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 != 1 )
return - V_18 ;
F_16 ( V_24 -> V_25 ) ;
return V_8 ;
}
static inline struct V_26 *
F_17 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_26 , V_27 ) ;
}
STATIC T_1
F_18 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_29 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_19 ( & log -> V_30 ) ;
V_28 = log -> V_31 ;
V_29 = log -> V_32 ;
F_20 ( & log -> V_30 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_29 ) ;
}
STATIC T_1
F_21 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_29 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_22 ( & log -> V_33 , & V_28 , & V_29 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_29 ) ;
}
STATIC T_1
F_23 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_34 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_24 ( & log -> V_35 . V_36 , & V_28 , & V_34 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_34 ) ;
}
STATIC T_1
F_25 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_34 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_24 ( & log -> V_37 . V_36 , & V_28 , & V_34 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_34 ) ;
}
STATIC T_1
F_26 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_26 * log = F_17 ( V_4 ) ;
int V_15 ;
T_3 V_16 ;
V_15 = F_27 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
log -> V_38 = V_16 ;
return V_8 ;
}
STATIC T_1
F_28 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_26 * log = F_17 ( V_4 ) ;
return snprintf ( V_5 , V_19 , L_1 , log -> V_38 ) ;
}
