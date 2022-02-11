static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , F_3 ( V_4 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_5 ;
int V_6 ;
char V_7 [ 8 ] ;
for ( V_5 = 0 ; V_5 < F_5 ( V_8 ) ; V_5 ++ ) {
V_6 = F_6 ( V_8 [ V_5 ] , V_9 [ V_5 ] ) ;
if ( V_6 ) {
F_7 ( & V_10 -> V_11 , L_1
L_2 , V_9 [ V_5 ] , V_6 ) ;
goto V_12;
}
}
for ( V_5 = V_13 ; V_5 <= V_14 ; V_5 ++ ) {
sprintf ( V_7 , L_3 , V_5 ) ;
V_6 = F_6 ( V_5 , V_7 ) ;
if ( V_6 ) {
F_7 ( & V_10 -> V_11 , L_1
L_4 , V_5 , V_6 ) ;
goto V_15;
}
}
F_8 ( V_16 , 0 ) ;
F_8 ( V_17 , 1 ) ;
F_8 ( V_18 , 0 ) ;
F_8 ( V_19 , 1 ) ;
F_8 ( V_20 , 1 ) ;
F_8 ( V_21 , 1 ) ;
F_8 ( V_22 , 0 ) ;
F_9 ( V_4 ) ;
F_9 ( V_23 ) ;
for ( V_5 = V_13 ; V_5 <= V_14 ; V_5 ++ )
F_8 ( V_5 , 0 ) ;
F_10 ( V_17 , 1 ) ;
F_10 ( V_22 , 0 ) ;
F_11 ( 10 ) ;
F_10 ( V_22 , 1 ) ;
F_11 ( 10 ) ;
F_1 ( V_2 ) ;
return 0 ;
V_15:
while ( -- V_5 >= V_13 )
F_12 ( V_5 ) ;
V_5 = F_5 ( V_8 ) ;
V_12:
while ( -- V_5 >= 0 )
F_12 ( V_8 [ V_5 ] ) ;
return V_6 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_5 ;
F_15 ( F_16 ( V_4 ) , V_2 ) ;
for ( V_5 = 0 ; V_5 < F_5 ( V_8 ) ; V_5 ++ )
F_12 ( V_8 [ V_5 ] ) ;
for ( V_5 = V_13 ; V_5 <= V_14 ; V_5 ++ )
F_12 ( V_5 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
T_1 V_24 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 <= ( V_14 - V_13 ) ; V_5 ++ )
V_24 |= ( F_3 ( V_13 + V_5 ) ) ? ( 1 << V_5 ) : 0 ;
return V_24 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_25 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 <= ( V_14 - V_13 ) ; V_5 ++ )
F_10 ( V_13 + V_5 , ( V_25 >> V_5 ) & 0x01 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned char V_26 ,
T_2 V_27 )
{
switch ( V_26 ) {
case V_28 :
F_10 ( V_21 , V_27 ) ;
break;
case V_29 :
F_10 ( V_18 , V_27 ) ;
break;
case V_30 :
F_10 ( V_20 , V_27 ) ;
break;
}
}
static int F_20 ( void )
{
return V_31 ;
}
static T_3 F_21 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
F_22 ( & V_2 -> V_3 ) ;
return V_34 ;
}
static int F_23 ( struct V_35 * V_36 )
{
int V_37 ;
struct V_1 * V_2 = V_36 -> V_2 ;
V_37 = F_24 ( F_16 ( V_4 ) , F_21 ,
V_38 | V_39 ,
L_5 , V_2 ) ;
if ( V_37 )
F_7 ( & V_10 -> V_11 , L_6 , V_37 ) ;
return V_37 ;
}
int T_4 F_25 ( void )
{
int V_37 ;
F_26 ( F_27 ( V_40 ) ) ;
F_28 ( L_7 ) ;
V_10 = F_29 ( L_7 , - 1 ) ;
if ( ! V_10 )
return - V_41 ;
F_30 ( V_10 , & V_42 ,
sizeof( V_42 ) ) ;
V_37 = F_31 ( V_10 ) ;
if ( V_37 ) {
F_32 ( V_10 ) ;
return V_37 ;
}
return 0 ;
}
