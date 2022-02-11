static inline int F_1 ( int V_1 )
{
return F_2 ( V_1 * 2000 , 1023 ) + 2500 ;
}
static inline int F_3 ( int V_1 )
{
return F_2 ( V_1 * 2500 , 1023 ) ;
}
static inline int F_4 ( int V_1 )
{
return F_2 ( V_1 * 5000 , 1023 ) ;
}
static inline int F_5 ( struct V_2 * V_2 )
{
return F_6 ( V_2 , V_3 ,
V_4 ,
V_4 ) ;
}
static inline int F_7 ( struct V_2 * V_2 )
{
return F_6 ( V_2 , V_3 ,
V_4 , 0 ) ;
}
static T_1 F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_12 , V_13 ;
F_10 ( & V_11 -> V_14 ) ;
V_12 = F_5 ( V_11 -> V_2 ) ;
if ( V_12 < 0 )
goto V_15;
V_13 = F_11 ( V_11 -> V_2 , V_16 ) ;
if ( V_13 < 0 ) {
V_12 = V_13 ;
goto V_17;
}
V_12 = F_7 ( V_11 -> V_2 ) ;
if ( V_12 < 0 )
goto V_15;
F_12 ( & V_11 -> V_14 ) ;
return sprintf ( V_9 , L_1 , F_1 ( V_13 ) ) ;
V_17:
F_7 ( V_11 -> V_2 ) ;
V_15:
F_12 ( & V_11 -> V_14 ) ;
return V_12 ;
}
static T_1 F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_12 ;
V_12 = F_11 ( V_11 -> V_2 , V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_9 , L_1 , F_2 ( V_12 * 39 , 10 ) ) ;
}
static T_1 F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_15 ( V_11 -> V_2 ) ) ;
}
static T_1 F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_12 ;
V_12 = F_17 ( V_11 -> V_2 , V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_9 , L_1 , F_1 ( V_12 ) ) ;
}
static T_1 F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_20 = F_19 ( V_8 ) -> V_21 ;
int V_12 ;
V_12 = F_17 ( V_11 -> V_2 , V_20 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_9 , L_1 , F_3 ( V_12 ) ) ;
}
static T_1 F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_22 ;
int V_23 ;
V_22 = F_11 ( V_11 -> V_2 , V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
V_23 = F_11 ( V_11 -> V_2 , V_25 ) ;
if ( V_23 < 0 )
return V_23 ;
return sprintf ( V_9 , L_1 , 1708 * ( V_22 - V_23 ) - 108800 ) ;
}
static T_1 F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_12 ;
V_12 = F_17 ( V_11 -> V_2 , V_26 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_9 , L_1 , F_4 ( V_12 ) ) ;
}
static T_1 F_22 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
return sprintf ( V_9 , L_2 ,
V_27 [ F_19 ( V_8 ) -> V_21 ] ) ;
}
static int F_23 ( struct V_28 * V_29 )
{
struct V_5 * V_6 = & V_29 -> V_6 ;
struct V_10 * V_11 ;
struct V_5 * V_30 ;
V_11 = F_24 ( V_6 , sizeof( struct V_10 ) , V_31 ) ;
if ( ! V_11 )
return - V_32 ;
F_25 ( & V_11 -> V_14 ) ;
V_11 -> V_2 = F_9 ( V_29 -> V_6 . V_33 ) ;
V_30 = F_26 ( V_6 , L_3 ,
V_11 ,
V_34 ) ;
return F_27 ( V_30 ) ;
}
