int F_1 ( int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 ) ;
if ( ( F_3 () & V_3 ) == V_4 )
V_2 = ( V_2 >> 8 ) & 0xff ;
else
V_2 = ( ( V_2 >> 8 ) & 0xff ) - 100 ;
return ( int ) V_2 * 1000 ;
}
static T_2 F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
return sprintf ( V_9 , L_1 ) ;
}
static T_2 F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
return sprintf ( V_9 , L_2 ) ;
}
static T_2 F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
return sprintf ( V_9 , L_3 ) ;
}
static T_2 F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_10 = F_1 ( 0 ) ;
return sprintf ( V_9 , L_4 , V_10 ) ;
}
static T_2 F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_10 = F_1 ( 1 ) ;
return sprintf ( V_9 , L_4 , V_10 ) ;
}
static int F_9 ( struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_10 ( V_12 , V_14 ) ;
if ( V_13 )
goto V_15;
if ( V_16 . V_17 <= V_16 . V_18 )
return 0 ;
V_13 = F_10 ( V_12 , V_19 ) ;
if ( V_13 )
goto V_20;
return 0 ;
V_20:
F_11 ( V_12 , V_14 ) ;
V_15:
return - 1 ;
}
static void F_12 ( struct V_11 * V_12 )
{
F_11 ( & V_21 -> V_12 , V_14 ) ;
if ( V_16 . V_17 > V_16 . V_18 )
F_11 ( & V_21 -> V_12 , V_19 ) ;
}
static void F_13 ( struct V_22 * V_23 )
{
int V_10 = F_1 ( 0 ) ;
if ( V_10 <= V_24 )
F_14 ( & V_25 , F_15 ( 5000 ) ) ;
else
F_16 ( true ) ;
}
static int T_3 F_17 ( void )
{
int V_13 ;
F_18 ( L_5 ) ;
V_21 = F_19 ( NULL ) ;
if ( F_20 ( V_21 ) ) {
V_13 = - V_26 ;
F_21 ( L_6 ) ;
goto V_27;
}
V_13 = F_22 ( & V_21 -> V_12 ,
& V_28 ) ;
if ( V_13 ) {
F_21 ( L_7 ) ;
goto V_29;
}
V_13 = F_9 ( & V_21 -> V_12 ) ;
if ( V_13 ) {
F_21 ( L_8 ) ;
goto V_30;
}
F_23 ( & V_25 , F_13 ) ;
F_14 ( & V_25 , F_15 ( 20000 ) ) ;
return V_13 ;
V_30:
F_24 ( & V_21 -> V_12 ,
& V_28 ) ;
V_29:
F_25 ( V_21 ) ;
V_27:
return V_13 ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_25 ) ;
F_12 ( & V_21 -> V_12 ) ;
F_24 ( & V_21 -> V_12 ,
& V_28 ) ;
F_25 ( V_21 ) ;
}
