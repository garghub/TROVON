static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
F_6 ( L_1 , V_3 -> V_9 ) ;
V_3 -> V_10 = V_11 + V_3 -> V_12 ;
V_3 -> V_13 = V_14 -> V_15 ;
if ( F_7 ( V_3 , sizeof( struct V_16 ) ) < 0 )
return - V_17 ;
if ( F_8 ( V_3 , 4 ) < 0 )
return - V_17 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_7 = V_3 -> V_18 + V_8 ;
V_7 -> type = V_19 ;
V_7 -> V_20 = V_21 | V_22 ;
V_7 -> V_23 = 32 ;
V_7 -> V_24 = 1 ;
V_7 -> V_25 = & V_26 ;
V_7 -> V_27 = V_28 ;
V_7 -> V_29 = V_30 ;
}
return 1 ;
}
static int F_9 ( struct V_2 * V_3 )
{
F_6 ( L_2 , V_3 -> V_9 ) ;
return 0 ;
}
static unsigned long * F_10 ( int V_31 )
{
switch ( V_31 ) {
case 0 :
return & V_32 -> V_33 ;
case 1 :
return & V_32 -> V_34 ;
case 2 :
return & V_32 -> V_35 ;
case 3 :
return & V_32 -> V_36 ;
}
}
static int V_28 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_37 * V_38 , unsigned int * V_39 )
{
int V_40 ;
unsigned int V_41 ;
unsigned int V_42 ;
int V_31 ;
V_31 = ( int ) V_7 -> V_43 ;
V_42 = 1 << F_11 ( V_38 -> V_44 ) ;
if ( V_42 & V_45 [ V_31 ] ) {
return - V_46 ;
}
switch ( V_39 [ 0 ] ) {
case V_47 :
V_7 -> V_48 |= V_42 ;
break;
case V_49 :
V_7 -> V_48 &= ~ V_42 ;
break;
case V_50 :
V_39 [ 1 ] = ( V_7 -> V_48 & V_42 ) ? V_51 : V_52 ;
return V_38 -> V_40 ;
break;
default:
return - V_46 ;
}
switch ( V_31 ) {
case 0 :
return & V_32 -> V_53 ;
case 1 :
return & V_32 -> V_54 ;
case 2 :
return & V_32 -> V_55 ;
case 3 :
return & V_32 -> V_56 ;
}
return 1 ;
}
static int V_30 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_37 * V_38 , unsigned int * V_39 )
{
int V_31 ;
unsigned long * V_57 ;
V_57 = F_10 ( ( int ) V_7 -> V_43 ) ;
return 2 ;
}
