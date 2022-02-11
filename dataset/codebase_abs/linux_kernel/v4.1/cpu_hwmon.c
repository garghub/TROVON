int F_1 ( int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 ) ;
if ( V_3 . V_4 == V_5 )
V_2 = ( V_2 >> 8 ) & 0xff ;
else if ( V_3 . V_4 == V_6 )
V_2 = ( ( V_2 >> 8 ) & 0xff ) - 100 ;
return ( int ) V_2 * 1000 ;
}
static T_2 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
return sprintf ( V_11 , L_1 ) ;
}
static T_2 F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
return sprintf ( V_11 , L_2 ) ;
}
static T_2 F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
return sprintf ( V_11 , L_3 ) ;
}
static T_2 F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
int V_12 = F_1 ( 0 ) ;
return sprintf ( V_11 , L_4 , V_12 ) ;
}
static T_2 F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
int V_12 = F_1 ( 1 ) ;
return sprintf ( V_11 , L_4 , V_12 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
int V_15 ;
V_15 = F_9 ( V_14 , V_16 ) ;
if ( V_15 )
goto V_17;
if ( V_3 . V_18 <= V_3 . V_19 )
return 0 ;
V_15 = F_9 ( V_14 , V_20 ) ;
if ( V_15 )
goto V_21;
return 0 ;
V_21:
F_10 ( V_14 , V_16 ) ;
V_17:
return - 1 ;
}
static void F_11 ( struct V_13 * V_14 )
{
F_10 ( & V_22 -> V_14 , V_16 ) ;
if ( V_3 . V_18 > V_3 . V_19 )
F_10 ( & V_22 -> V_14 , V_20 ) ;
}
static void F_12 ( struct V_23 * V_24 )
{
int V_12 = F_1 ( 0 ) ;
if ( V_12 <= V_25 )
F_13 ( & V_26 , F_14 ( 5000 ) ) ;
else
F_15 ( true ) ;
}
static int T_3 F_16 ( void )
{
int V_15 ;
F_17 ( L_5 ) ;
V_22 = F_18 ( NULL ) ;
if ( F_19 ( V_22 ) ) {
V_15 = - V_27 ;
F_20 ( L_6 ) ;
goto V_28;
}
V_15 = F_21 ( & V_22 -> V_14 ,
& V_29 ) ;
if ( V_15 ) {
F_20 ( L_7 ) ;
goto V_30;
}
V_15 = F_8 ( & V_22 -> V_14 ) ;
if ( V_15 ) {
F_20 ( L_8 ) ;
goto V_31;
}
F_22 ( & V_26 , F_12 ) ;
F_13 ( & V_26 , F_14 ( 20000 ) ) ;
return V_15 ;
V_31:
F_23 ( & V_22 -> V_14 ,
& V_29 ) ;
V_30:
F_24 ( V_22 ) ;
V_28:
return V_15 ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_26 ) ;
F_11 ( & V_22 -> V_14 ) ;
F_23 ( & V_22 -> V_14 ,
& V_29 ) ;
F_24 ( V_22 ) ;
}
