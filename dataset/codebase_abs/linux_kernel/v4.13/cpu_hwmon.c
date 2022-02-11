int F_1 ( int V_1 )
{
T_1 V_2 , V_3 ;
V_2 = F_2 ( V_1 ) ;
V_3 = F_3 () & V_4 ;
switch ( V_3 ) {
case V_5 :
V_2 = ( V_2 >> 8 ) & 0xff ;
break;
case V_6 :
case V_7 :
case V_8 :
V_2 = ( ( V_2 >> 8 ) & 0xff ) - 100 ;
break;
case V_9 :
V_2 = ( V_2 & 0xffff ) * 731 / 0x4000 - 273 ;
break;
}
return ( int ) V_2 * 1000 ;
}
static T_2 F_4 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
return sprintf ( V_14 , L_1 ) ;
}
static T_2 F_5 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = ( F_6 ( V_13 ) ) -> V_16 - 1 ;
return sprintf ( V_14 , L_2 , V_15 ) ;
}
static T_2 F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = ( F_6 ( V_13 ) ) -> V_16 - 1 ;
int V_17 = F_1 ( V_15 ) ;
return sprintf ( V_14 , L_3 , V_17 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
int V_20 , V_21 = 0 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
V_21 = F_9 ( V_19 , V_23 [ V_20 ] ) ;
return V_21 ;
}
static void F_10 ( struct V_18 * V_19 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
F_11 ( V_19 , V_23 [ V_20 ] ) ;
}
static void F_12 ( struct V_24 * V_25 )
{
int V_20 , V_17 , V_26 = 0 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_17 = F_1 ( V_20 ) ;
if ( V_17 > V_26 )
V_26 = V_17 ;
}
if ( V_26 <= V_27 )
F_13 ( & V_28 , F_14 ( 5000 ) ) ;
else
F_15 ( true ) ;
}
static int T_3 F_16 ( void )
{
int V_21 ;
F_17 ( L_4 ) ;
V_29 = F_18 ( NULL ) ;
if ( F_19 ( V_29 ) ) {
V_21 = - V_30 ;
F_20 ( L_5 ) ;
goto V_31;
}
V_22 = V_32 . V_33 /
V_32 . V_34 ;
V_21 = F_21 ( & V_29 -> V_19 ,
& V_35 ) ;
if ( V_21 ) {
F_20 ( L_6 ) ;
goto V_36;
}
V_21 = F_8 ( & V_29 -> V_19 ) ;
if ( V_21 ) {
F_20 ( L_7 ) ;
goto V_37;
}
F_22 ( & V_28 , F_12 ) ;
F_13 ( & V_28 , F_14 ( 20000 ) ) ;
return V_21 ;
V_37:
F_23 ( & V_29 -> V_19 ,
& V_35 ) ;
V_36:
F_24 ( V_29 ) ;
V_31:
return V_21 ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_28 ) ;
F_10 ( & V_29 -> V_19 ) ;
F_23 ( & V_29 -> V_19 ,
& V_35 ) ;
F_24 ( V_29 ) ;
}
