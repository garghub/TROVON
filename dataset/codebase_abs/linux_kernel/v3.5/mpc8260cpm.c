static unsigned long * F_1 ( int V_1 )
{
switch ( V_1 ) {
case 0 :
return & V_2 -> V_3 ;
case 1 :
return & V_2 -> V_4 ;
case 2 :
return & V_2 -> V_5 ;
case 3 :
return & V_2 -> V_6 ;
}
}
static int F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 , unsigned int * V_13 )
{
int V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
int V_1 ;
V_1 = ( int ) V_10 -> V_17 ;
V_16 = 1 << F_3 ( V_12 -> V_18 ) ;
if ( V_16 & V_19 [ V_1 ] ) {
return - V_20 ;
}
switch ( V_13 [ 0 ] ) {
case V_21 :
V_10 -> V_22 |= V_16 ;
break;
case V_23 :
V_10 -> V_22 &= ~ V_16 ;
break;
case V_24 :
V_13 [ 1 ] = ( V_10 -> V_22 & V_16 ) ? V_25 : V_26 ;
return V_12 -> V_14 ;
break;
default:
return - V_20 ;
}
switch ( V_1 ) {
case 0 :
return & V_2 -> V_27 ;
case 1 :
return & V_2 -> V_28 ;
case 2 :
return & V_2 -> V_29 ;
case 3 :
return & V_2 -> V_30 ;
}
return 1 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 , unsigned int * V_13 )
{
int V_1 ;
unsigned long * V_31 ;
V_31 = F_1 ( ( int ) V_10 -> V_17 ) ;
return 2 ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 ;
int V_34 ;
F_6 ( L_1 , V_8 -> V_35 ) ;
V_8 -> V_36 = V_37 + V_8 -> V_38 ;
V_8 -> V_39 = V_40 -> V_41 ;
if ( F_7 ( V_8 , sizeof( struct V_42 ) ) < 0 )
return - V_43 ;
if ( F_8 ( V_8 , 4 ) < 0 )
return - V_43 ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_10 = V_8 -> V_44 + V_34 ;
V_10 -> type = V_45 ;
V_10 -> V_46 = V_47 | V_48 ;
V_10 -> V_49 = 32 ;
V_10 -> V_50 = 1 ;
V_10 -> V_51 = & V_52 ;
V_10 -> V_53 = F_2 ;
V_10 -> V_54 = F_4 ;
}
return 1 ;
}
static void F_9 ( struct V_7 * V_8 )
{
}
