static int F_1 ( T_1 V_1 , int V_2 , unsigned int V_3 )
{
T_1 V_4 ;
V_4 = 0 ;
switch ( V_3 ) {
case 1 :
V_4 = ( V_1 >> ( ( V_2 & 3 ) << 3 ) ) & 0xff ;
break;
case 2 :
V_4 = ( V_1 >> ( ( V_2 & 3 ) << 3 ) ) & 0xffff ;
break;
case 4 :
V_4 = V_1 ;
break;
}
return V_4 ;
}
static int F_2 ( T_1 V_5 , T_1 V_6 , int V_2 ,
unsigned int V_3 )
{
T_1 V_4 ;
V_4 = 0 ;
switch ( V_3 ) {
case 1 :
V_4 = ( V_5 & ~ ( 0xff << ( ( V_2 & 3 ) << 3 ) ) ) |
( V_6 << ( ( V_2 & 3 ) << 3 ) ) ;
break;
case 2 :
V_4 = ( V_5 & ~ ( 0xffff << ( ( V_2 & 3 ) << 3 ) ) ) |
( V_6 << ( ( V_2 & 3 ) << 3 ) ) ;
break;
case 4 :
V_4 = V_6 ;
break;
}
return V_4 ;
}
static int F_3 ( int type , unsigned int V_7 ,
unsigned int V_8 , int V_2 )
{
unsigned int V_9 , V_10 , V_11 ;
T_1 V_6 ;
V_9 = F_4 ( V_8 ) ;
V_10 = F_5 ( V_8 ) ;
V_11 = V_2 >> 2 ;
if ( V_9 > ( V_12 >> V_13 ) )
return 1 ;
if ( V_10 > ( V_14 >> V_15 ) )
return 1 ;
if ( V_11 > ( V_16 >> V_17 ) )
return 1 ;
V_6 = ( V_11 << V_17 ) ;
V_6 |= ( V_10 << V_15 ) ;
V_6 |= ( V_9 << V_13 ) ;
V_6 |= V_18 ;
V_6 |= V_19 ;
if ( type != 0 ) {
V_6 |= ( 1 << V_20 ) ;
}
F_6 ( V_6 , V_21 ) ;
return 0 ;
}
static int F_7 ( int type , unsigned int V_7 ,
unsigned int V_8 , int V_2 , int V_3 ,
T_1 * V_6 )
{
T_1 V_1 ;
if ( F_3 ( type , V_7 , V_8 , V_2 ) )
return V_22 ;
F_8 () ;
V_1 = F_9 ( F_10 ( V_23 ) ) ;
F_6 ( 0 , V_21 ) ;
* V_6 = F_1 ( V_1 , V_2 , V_3 ) ;
return V_24 ;
}
static int F_11 ( int type , unsigned int V_7 ,
unsigned int V_8 , int V_2 , int V_3 ,
T_1 V_6 )
{
T_1 V_1 ;
if ( F_3 ( type , V_7 , V_8 , V_2 ) )
return V_22 ;
F_8 () ;
V_1 = F_9 ( F_10 ( V_23 ) ) ;
V_1 = F_2 ( V_1 , V_6 , V_2 , V_3 ) ;
F_12 ( F_13 ( V_1 ) , V_23 ) ;
F_14 () ;
F_15 ( 500 ) ;
F_6 ( 0 , V_21 ) ;
return V_24 ;
}
static int F_16 ( struct V_25 * V_26 , unsigned int V_8 ,
int V_2 , int V_3 , T_1 * V_6 )
{
int type ;
type = V_26 -> V_27 ? 1 : 0 ;
if ( type == 0 && F_4 ( V_8 ) == V_28 )
return V_22 ;
return F_7 ( type , V_26 -> V_29 , V_8 ,
V_2 , V_3 , V_6 ) ;
}
static int F_17 ( struct V_25 * V_26 , unsigned int V_8 ,
int V_2 , int V_3 , T_1 V_6 )
{
int type ;
type = V_26 -> V_27 ? 1 : 0 ;
if ( type == 0 && F_4 ( V_8 ) == V_28 )
return V_22 ;
return F_11 ( type , V_26 -> V_29 , V_8 ,
V_2 , V_3 , V_6 ) ;
}
static int F_18 ( int V_2 , int V_3 , T_1 * V_6 )
{
unsigned int V_11 ;
T_1 V_1 ;
V_1 = 0 ;
V_11 = V_2 >> 2 ;
switch ( V_11 ) {
case ( V_30 >> 2 ) :
case ( V_31 >> 2 ) :
V_1 = ( F_19 () << 16 ) | V_32 ;
break;
case ( V_33 >> 2 ) :
V_1 = ( V_34 << 16 ) ;
V_1 |= V_35 . V_36 ;
break;
case ( V_37 >> 2 ) :
V_1 = ( V_38 << 16 ) ;
break;
case ( V_39 >> 2 ) :
V_1 = ( V_40 << 16 ) ;
break;
case ( V_41 >> 2 ) :
V_1 = ( V_35 . V_42 << 16 ) ;
V_1 |= ( 0x1 << 8 ) | 0xff ;
break;
case ( V_43 >> 2 ) :
V_1 = ( V_35 . V_44 << 24 ) ;
V_1 |= ( V_35 . V_45 << 16 ) ;
V_1 |= ( V_35 . V_46 << 8 ) ;
V_1 |= V_35 . V_47 ;
break;
case ( V_48 >> 2 ) :
V_1 = V_35 . V_49 ;
break;
case ( V_50 >> 2 ) :
V_1 = V_35 . V_51 ;
break;
case ( V_52 >> 2 ) :
V_1 = V_35 . V_53 ;
break;
case ( V_54 >> 2 ) :
V_1 = V_35 . V_55 ;
break;
case ( V_56 >> 2 ) :
V_1 = V_35 . V_57 | 0x1 ;
break;
case ( V_58 >> 2 ) :
V_1 = V_35 . V_59 ;
break;
case ( V_60 >> 2 ) :
V_1 = V_35 . V_61 | 0x1 ;
break;
case ( V_62 >> 2 ) :
V_1 = V_35 . V_63 ;
break;
}
* V_6 = F_1 ( V_1 , V_2 , V_3 ) ;
return V_24 ;
}
static int F_20 ( int V_2 , int V_3 , T_1 V_6 )
{
unsigned int V_11 ;
T_1 V_1 , V_64 ;
int V_4 ;
V_4 = F_18 ( ( V_2 & ~ 0x3 ) , 4 , & V_1 ) ;
if ( V_4 != V_24 )
return V_4 ;
V_1 = F_2 ( V_1 , V_6 , V_2 , V_3 ) ;
V_11 = V_2 >> 2 ;
switch ( V_11 ) {
case ( V_33 >> 2 ) :
V_35 . V_36 = ( V_1 & 0xffff ) ;
break;
case ( V_43 >> 2 ) :
V_35 . V_44 = ( V_1 >> 24 ) & 0xff ;
V_35 . V_45 = ( V_1 >> 16 ) & 0xff ;
V_35 . V_46 = ( V_1 >> 8 ) & 0xff ;
V_35 . V_47 = V_1 & 0xff ;
if ( V_35 . V_46 )
V_35 . V_65 = 1 ;
break;
case ( V_41 >> 2 ) :
V_64 = ( V_1 >> 16 ) & 0xffff ;
V_64 &= ~ V_66 ;
V_64 &= ~ V_67 ;
V_35 . V_42 = V_64 ;
break;
case ( V_48 >> 2 ) :
V_35 . V_49 = V_1 ;
break;
case ( V_50 >> 2 ) :
V_35 . V_51 = V_1 ;
break;
case ( V_52 >> 2 ) :
V_35 . V_53 = V_1 ;
break;
case ( V_54 >> 2 ) :
V_35 . V_55 = V_1 ;
break;
case ( V_56 >> 2 ) :
V_35 . V_57 = V_1 ;
break;
case ( V_58 >> 2 ) :
V_35 . V_59 = V_1 ;
break;
case ( V_60 >> 2 ) :
V_35 . V_61 = V_1 ;
break;
case ( V_62 >> 2 ) :
V_35 . V_63 = V_1 ;
break;
}
return V_24 ;
}
static int F_21 ( struct V_25 * V_26 , unsigned int V_8 ,
int V_2 , int V_3 , T_1 * V_6 )
{
if ( ! V_26 -> V_27 && F_4 ( V_8 ) == V_68 ) {
V_69 = V_26 -> V_29 ;
return F_18 ( V_2 , V_3 , V_6 ) ;
}
if ( V_35 . V_65 &&
V_26 -> V_29 == V_35 . V_46 &&
F_4 ( V_8 ) == 0 )
return F_7 ( 0 , 0 ,
F_22 ( V_28 , 0 ) ,
V_2 , V_3 , V_6 ) ;
return V_22 ;
}
static int F_23 ( struct V_25 * V_26 , unsigned int V_8 ,
int V_2 , int V_3 , T_1 V_6 )
{
if ( ! V_26 -> V_27 && F_4 ( V_8 ) == V_68 ) {
V_69 = V_26 -> V_29 ;
return F_20 ( V_2 , V_3 , V_6 ) ;
}
if ( V_35 . V_65 &&
V_26 -> V_29 == V_35 . V_46 &&
F_4 ( V_8 ) == 0 )
return F_11 ( 0 , 0 ,
F_22 ( V_28 , 0 ) ,
V_2 , V_3 , V_6 ) ;
return V_22 ;
}
static void F_24 ( struct V_70 * V_71 )
{
static int V_72 = - 1 ;
int V_73 , V_74 , V_75 ;
T_1 V_6 ;
V_74 = 0 ;
for ( V_73 = 0 ; V_73 < V_76 ; V_73 ++ ) {
if ( F_25 ( V_71 , V_73 ) & V_77 ) {
V_74 = 1 ;
break;
}
}
if ( ! V_74 )
return;
if ( V_71 -> V_26 -> V_29 == V_69 )
return;
if ( V_35 . V_65 &&
V_71 -> V_26 -> V_29 == V_35 . V_46 &&
F_4 ( V_71 -> V_8 ) == 0 )
V_75 = 1 ;
else
V_75 = 0 ;
if ( V_75 == V_72 )
return;
if ( V_72 != - 1 ) {
F_26 ( V_78 L_1
L_2 ) ;
return;
}
F_26 ( V_79 L_3 ,
( V_75 == 0 ) ? L_4 : L_5 ) ;
V_6 = F_27 ( V_80 ) ;
if ( V_72 )
V_6 |= V_81 ;
else
V_6 &= ~ V_81 ;
F_6 ( V_6 , V_80 ) ;
V_72 = V_75 ;
}
