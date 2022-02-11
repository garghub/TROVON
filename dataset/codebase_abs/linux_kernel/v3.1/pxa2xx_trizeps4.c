static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
switch ( V_2 -> V_5 ) {
case 0 :
if ( F_2 ( V_6 , L_1 ) < 0 ) {
F_3 ( L_2 , V_7 ,
V_2 -> V_5 , V_6 ) ;
return - V_8 ;
}
if ( F_4 ( V_6 ) < 0 ) {
F_3 ( L_3 , V_7 ,
V_2 -> V_5 , V_6 ) ;
F_5 ( V_6 ) ;
return - V_9 ;
}
V_2 -> V_10 . V_11 = F_6 ( V_6 ) ;
break;
default:
break;
}
F_7 ( L_4 , V_7 , V_2 -> V_5 , V_2 -> V_10 . V_11 ) ;
for ( V_4 = 0 ; V_4 < F_8 ( V_12 ) ; V_4 ++ ) {
if ( V_12 [ V_4 ] . V_13 != V_2 -> V_5 )
continue;
if ( F_2 ( F_9 ( V_12 [ V_4 ] . V_14 ) , V_12 [ V_4 ] . V_15 ) < 0 ) {
F_3 ( L_2 ,
V_7 , V_2 -> V_5 , F_9 ( V_12 [ V_4 ] . V_14 ) ) ;
V_3 = - V_8 ;
goto error;
}
if ( F_4 ( F_9 ( V_12 [ V_4 ] . V_14 ) ) < 0 ) {
F_3 ( L_3 ,
V_7 , V_2 -> V_5 , F_9 ( V_12 [ V_4 ] . V_14 ) ) ;
V_3 = - V_9 ;
goto error;
}
}
return F_10 ( V_2 , V_12 , F_8 ( V_12 ) ) ;
error:
for (; V_4 >= 0 ; V_4 -- ) {
F_5 ( F_9 ( V_12 [ V_4 ] . V_14 ) ) ;
}
return ( V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_4 ;
F_5 ( V_6 ) ;
for ( V_4 = 0 ; V_4 < F_8 ( V_12 ) ; V_4 ++ )
F_5 ( F_9 ( V_12 [ V_4 ] . V_14 ) ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
unsigned short V_18 = 0 , V_19 ;
V_18 = F_13 () ;
V_19 = ( V_18 ^ V_20 [ V_2 -> V_5 ] ) &
V_21 ;
if ( V_19 ) {
V_20 [ V_2 -> V_5 ] = V_18 ;
if ( V_18 & V_22 ) {
} else {
}
}
switch ( V_2 -> V_5 ) {
case 0 :
V_17 -> V_23 = F_14 ( V_24 ) ? 0 : 1 ;
V_17 -> V_25 = F_14 ( V_6 ) ? 1 : 0 ;
V_17 -> V_26 = ( V_18 & V_22 ) ? 1 : 0 ;
V_17 -> V_27 = ( V_18 & V_28 ) ? 1 : 0 ;
V_17 -> V_29 = ( V_18 & V_30 ) ? 0 : 1 ;
V_17 -> V_31 = ( V_18 & V_32 ) ? 0 : 1 ;
V_17 -> V_33 = 0 ;
break;
#ifndef F_15
case 1 :
V_17 -> V_23 = 0 ;
V_17 -> V_25 = 0 ;
V_17 -> V_26 = 0 ;
V_17 -> V_27 = 0 ;
V_17 -> V_29 = 0 ;
V_17 -> V_31 = 0 ;
V_17 -> V_33 = 0 ;
break;
#endif
}
}
static int F_16 ( struct V_1 * V_2 ,
const T_1 * V_17 )
{
int V_3 = 0 ;
unsigned short V_34 = 0 ;
switch ( V_17 -> V_35 ) {
case 0 : V_34 &= 0xfc ; break;
case 33 : V_34 |= V_36 ; break;
case 50 :
F_3 ( L_5 , V_7 ) ;
break;
default:
F_3 ( L_6 , V_7 , V_17 -> V_35 ) ;
V_3 = - 1 ;
}
switch ( V_17 -> V_37 ) {
case 0 : V_34 &= 0xf3 ; break;
case 33 : V_34 |= V_38 ; break;
case 120 :
F_3 ( L_7 , V_7 ) ;
break;
default:
if ( V_17 -> V_37 != V_17 -> V_35 ) {
F_3 ( L_8 , V_7 , V_17 -> V_37 ) ;
V_3 = - 1 ;
}
}
switch ( V_2 -> V_5 ) {
case 0 :
F_17 ( V_34 ) ;
break;
#ifndef F_15
case 1 :
#endif
default:
break;
}
return V_3 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_17 ( 0x9 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_17 ( 0x0 ) ;
}
static int T_2 F_20 ( void )
{
int V_3 ;
if ( ! F_21 () && ! F_22 () )
return - V_39 ;
V_40 = F_23 ( L_9 , - 1 ) ;
if ( ! V_40 )
return - V_41 ;
V_3 = F_24 ( V_40 ,
& V_42 , sizeof( V_42 ) ) ;
if ( V_3 == 0 )
V_3 = F_25 ( V_40 ) ;
if ( V_3 )
F_26 ( V_40 ) ;
return V_3 ;
}
static void T_3 F_27 ( void )
{
F_28 ( V_40 ) ;
}
