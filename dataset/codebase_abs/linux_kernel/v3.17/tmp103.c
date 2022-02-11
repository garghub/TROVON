static inline int F_1 ( T_1 V_1 )
{
return V_1 * 1000 ;
}
static inline T_2 F_2 ( int V_1 )
{
return F_3 ( V_1 , 1000 ) ;
}
static T_3 F_4 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_9 * V_9 = F_6 ( V_3 ) ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_7 ( V_9 , V_8 -> V_12 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_6 , L_1 , F_1 ( V_10 ) ) ;
}
static T_3 F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_4 V_13 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_9 * V_9 = F_6 ( V_3 ) ;
long V_1 ;
int V_11 ;
if ( F_9 ( V_6 , 10 , & V_1 ) < 0 )
return - V_14 ;
V_1 = F_10 ( V_1 , - 55000 , 127000 ) ;
V_11 = F_11 ( V_9 , V_8 -> V_12 , F_2 ( V_1 ) ) ;
return V_11 ? V_11 : V_13 ;
}
static bool F_12 ( struct V_2 * V_3 , unsigned int V_15 )
{
return V_15 == V_16 ;
}
static int F_13 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_2 * V_21 ;
struct V_9 * V_9 ;
int V_11 ;
V_9 = F_14 ( V_18 , & V_22 ) ;
if ( F_15 ( V_9 ) ) {
F_16 ( V_3 , L_2 ) ;
return F_17 ( V_9 ) ;
}
V_11 = F_18 ( V_9 , V_23 , V_24 ,
V_25 ) ;
if ( V_11 < 0 ) {
F_16 ( & V_18 -> V_3 , L_3 ) ;
return V_11 ;
}
F_19 ( V_18 , V_9 ) ;
V_21 = F_20 ( V_3 , V_18 -> V_26 ,
V_9 , V_27 ) ;
return F_21 ( V_21 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_6 ( V_3 ) ;
return F_18 ( V_9 , V_23 ,
V_28 , 0 ) ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_6 ( V_3 ) ;
return F_18 ( V_9 , V_23 ,
V_28 , V_29 ) ;
}
