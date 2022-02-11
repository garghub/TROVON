static inline int F_1 ( int V_1 )
{
return F_2 ( V_1 * 1000 , 512 ) + 2500 ;
}
static inline int F_3 ( int V_1 )
{
return F_2 ( V_1 * 2500 , 1023 ) ;
}
static inline int F_4 ( int V_1 )
{
return F_2 ( V_1 * 2500 , 512 ) ;
}
static int F_5 ( struct V_2 * V_2 )
{
int V_3 ;
V_3 = F_6 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_5 ;
return F_7 ( V_2 , V_4 , V_3 ) ;
}
static int F_8 ( struct V_2 * V_2 )
{
int V_3 ;
V_3 = F_6 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_5 ;
return F_7 ( V_2 , V_4 , V_3 ) ;
}
static T_1 F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_3 , V_13 ;
F_11 ( & V_12 -> V_14 ) ;
V_3 = F_5 ( V_12 -> V_2 ) ;
if ( V_3 < 0 )
goto V_15;
V_13 = F_6 ( V_12 -> V_2 , V_16 ) ;
if ( V_13 < 0 ) {
V_3 = V_13 ;
goto V_17;
}
V_3 = F_8 ( V_12 -> V_2 ) ;
if ( V_3 < 0 )
goto V_15;
F_12 ( & V_12 -> V_14 ) ;
return sprintf ( V_10 , L_1 , F_1 ( V_13 ) ) ;
V_17:
F_8 ( V_12 -> V_2 ) ;
V_15:
F_12 ( & V_12 -> V_14 ) ;
return V_3 ;
}
static T_1 F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_3 ;
V_3 = F_6 ( V_12 -> V_2 , V_18 ) ;
if ( V_3 < 0 )
return V_3 ;
return sprintf ( V_10 , L_1 , F_2 ( V_3 * 39 , 10 ) ) ;
}
static T_1 F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_15 ( V_12 -> V_2 ) ) ;
}
static T_1 F_16 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_3 ;
V_3 = F_17 ( V_12 -> V_2 , V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
return sprintf ( V_10 , L_1 , F_1 ( V_3 ) ) ;
}
static T_1 F_18 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_20 = F_19 ( V_9 ) -> V_21 ;
int V_3 ;
V_3 = F_17 ( V_12 -> V_2 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
return sprintf ( V_10 , L_1 , F_3 ( V_3 ) ) ;
}
static T_1 F_20 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_22 ;
int V_23 ;
V_22 = F_6 ( V_12 -> V_2 , V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
V_23 = F_6 ( V_12 -> V_2 , V_25 ) ;
if ( V_23 < 0 )
return V_23 ;
return sprintf ( V_10 , L_1 , 1708 * ( V_22 - V_23 ) - 108800 ) ;
}
static T_1 F_21 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_3 ;
V_3 = F_17 ( V_12 -> V_2 , V_26 ) ;
if ( V_3 < 0 )
return V_3 ;
return sprintf ( V_10 , L_1 , F_4 ( V_3 ) ) ;
}
static T_1 F_22 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
return sprintf ( V_10 , L_2 ) ;
}
static T_1 F_23 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
return sprintf ( V_10 , L_3 ,
V_27 [ F_19 ( V_9 ) -> V_21 ] ) ;
}
static int T_2 F_24 ( struct V_28 * V_29 )
{
struct V_11 * V_12 ;
int V_3 ;
V_12 = F_25 ( & V_29 -> V_7 , sizeof( struct V_11 ) ,
V_30 ) ;
if ( ! V_12 )
return - V_31 ;
F_26 ( & V_12 -> V_14 ) ;
V_12 -> V_2 = F_10 ( V_29 -> V_7 . V_32 ) ;
F_27 ( V_29 , V_12 ) ;
V_3 = F_28 ( & V_29 -> V_7 . V_33 , & V_34 ) ;
if ( V_3 )
goto V_35;
V_12 -> V_36 = F_29 ( & V_29 -> V_7 ) ;
if ( F_30 ( V_12 -> V_36 ) ) {
V_3 = F_31 ( V_12 -> V_36 ) ;
goto V_37;
}
return 0 ;
V_37:
F_32 ( & V_29 -> V_7 . V_33 , & V_34 ) ;
V_35:
return V_3 ;
}
static int T_3 F_33 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = F_34 ( V_29 ) ;
F_35 ( V_12 -> V_36 ) ;
F_32 ( & V_29 -> V_7 . V_33 , & V_34 ) ;
return 0 ;
}
