static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_4 ( & V_8 -> V_9 ) ;
V_8 -> V_10 [ 0 ] = V_3 >> 8 ;
V_8 -> V_10 [ 1 ] = V_3 ;
V_4 = F_5 ( V_8 -> V_11 , V_8 -> V_10 , 2 ) ;
F_6 ( & V_8 -> V_9 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_4 ( & V_8 -> V_9 ) ;
V_4 = F_8 ( V_8 -> V_11 , V_8 -> V_10 , 2 ) ;
if ( V_4 == 0 )
* V_3 = ( ( V_8 -> V_10 [ 0 ] & 0xF ) << 8 ) | V_8 -> V_10 [ 1 ] ;
F_6 ( & V_8 -> V_9 ) ;
return V_4 ;
}
static T_2 F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
char * V_10 )
{
struct V_14 * V_15 = F_10 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_3 = 0 ;
T_2 V_4 ;
F_4 ( & V_6 -> V_16 ) ;
V_4 = F_1 ( V_2 ,
V_15 -> V_17 | V_18 ) ;
if ( V_4 < 0 )
goto V_19;
V_4 = F_7 ( V_2 , & V_3 ) ;
V_19:
F_6 ( & V_6 -> V_16 ) ;
if ( V_4 == 0 )
return sprintf ( V_10 , L_1 , V_3 ) ;
else
return V_4 ;
}
static int T_3 F_11 ( struct V_20 * V_21 )
{
int V_4 , V_22 = 0 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
V_6 = F_12 ( sizeof( * V_8 ) ) ;
if ( V_6 == NULL ) {
V_4 = - V_23 ;
goto V_19;
}
V_8 = F_3 ( V_6 ) ;
F_13 ( V_21 , V_6 ) ;
V_8 -> V_11 = V_21 ;
F_14 ( & V_8 -> V_9 ) ;
V_6 -> V_24 = V_21 -> V_2 . V_25 -> V_24 ;
V_6 -> V_2 . V_26 = & V_21 -> V_2 ;
V_6 -> V_27 = & V_28 ;
V_6 -> V_29 = V_30 ;
V_4 = F_15 ( V_6 ) ;
if ( V_4 )
goto V_31;
V_22 = 1 ;
return 0 ;
V_31:
if ( V_22 )
F_16 ( V_6 ) ;
else
F_17 ( V_6 ) ;
V_19:
return V_4 ;
}
static int F_18 ( struct V_20 * V_21 )
{
F_16 ( F_19 ( V_21 ) ) ;
return 0 ;
}
static T_4 int F_20 ( void )
{
return F_21 ( & V_32 ) ;
}
static T_5 void F_22 ( void )
{
F_23 ( & V_32 ) ;
}
