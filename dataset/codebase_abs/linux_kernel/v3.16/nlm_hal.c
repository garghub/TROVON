void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 ) ;
if ( V_1 == 0 )
V_3 -> V_4 = 1 ;
V_3 -> V_5 = F_3 ( V_1 ) ;
V_3 -> V_6 = F_4 ( V_1 ) ;
V_3 -> V_7 = F_5 () & ( ~ ( ( 1 << 12 ) - 1 ) ) ;
if ( F_6 () )
V_3 -> V_8 = F_7 ( V_1 ) ;
else
V_3 -> V_8 = 0 ;
F_8 ( & V_3 -> V_9 ) ;
}
static int F_9 ( int V_10 )
{
switch ( V_10 ) {
case V_11 :
return 12 ;
case V_12 :
return 114 ;
case V_13 :
return 115 ;
case V_14 :
return 133 ;
case V_15 :
return 134 ;
case V_16 :
return 143 ;
case V_17 :
return 152 ;
case V_18 :
return 153 ;
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
return 191 + V_10 - V_19 ;
}
return - 1 ;
}
static int F_11 ( int V_10 )
{
T_1 V_20 ;
int V_21 , V_22 ;
V_21 = 0 ;
switch ( V_10 ) {
case V_14 :
V_21 = F_12 ( 0 ) ;
break;
case V_15 :
V_21 = F_13 ( 0 ) ;
break;
case V_18 :
V_21 = F_14 ( 0 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
if ( F_15 () )
V_21 = F_16 ( 0 ) ;
else
V_21 = F_17 ( 0 ) ;
break;
case V_16 :
V_21 = F_18 ( 0 ) ;
break;
case V_11 :
V_21 = F_19 ( 0 ) ;
break;
case V_27 :
V_21 = F_20 ( 0 ) ;
break;
case V_17 :
V_21 = F_21 ( 0 ) ;
break;
default:
if ( F_15 () ) {
switch ( V_10 ) {
case V_28 :
V_21 = F_22 ( 0 ) ;
break;
case V_29 :
V_21 = F_23 ( 0 ) ;
break;
case V_30 :
V_21 = F_24 ( 0 ) ;
break;
}
} else {
switch ( V_10 ) {
case V_31 :
V_21 = F_25 ( 0 ) ;
break;
case V_32 :
V_21 = F_26 ( 0 ) ;
break;
case V_33 :
V_21 = F_27 ( 0 ) ;
break;
case V_34 :
V_21 = F_28 ( 0 ) ;
break;
case V_35 :
V_21 = F_29 ( 0 ) ;
break;
case V_36 :
V_21 = F_30 ( 0 ) ;
break;
}
}
}
if ( V_21 != 0 ) {
V_20 = F_31 ( V_21 ) ;
V_22 = F_32 ( V_20 , V_37 ) & 0xffff ;
switch ( V_10 ) {
case V_24 :
V_22 = V_22 + 1 ; break;
case V_25 :
V_22 = V_22 + 2 ; break;
case V_26 :
V_22 = V_22 + 3 ; break;
}
} else if ( V_10 >= F_10 ( 0 ) &&
V_10 <= F_10 ( 3 ) ) {
V_22 = F_33 ( V_10 -
V_19 ) ;
} else {
V_22 = - 1 ;
}
return V_22 ;
}
int F_34 ( int V_10 )
{
if ( V_10 >= F_35 ( 0 ) && V_10 <= F_35 ( 3 ) )
return - 2 ;
if ( V_10 >= F_36 ( 0 ) && V_10 <= F_36 ( 3 ) )
return - 2 ;
if ( F_6 () )
return F_9 ( V_10 ) ;
else
return F_11 ( V_10 ) ;
}
static unsigned int F_37 ( int V_1 , int V_38 )
{
unsigned int V_39 , V_40 , V_41 , V_42 ;
T_1 V_43 , V_5 , V_44 ;
if ( F_6 () ) {
V_44 = F_38 ( V_1 ) ;
V_40 = F_39 ( V_44 ,
F_40 ( V_38 ) ) ;
V_41 = F_39 ( V_44 ,
F_41 ( V_38 ) ) ;
} else {
V_5 = F_2 ( V_1 ) -> V_5 ;
V_40 = F_39 ( V_5 ,
F_42 ( V_38 ) ) ;
V_41 = F_39 ( V_5 ,
F_43 ( V_38 ) ) ;
}
switch ( ( V_40 >> 24 ) & 0x7 ) {
case 1 :
V_39 = 2 ;
break;
case 3 :
V_39 = 4 ;
break;
case 7 :
V_39 = 8 ;
break;
case 6 :
V_39 = 16 ;
break;
case 0 :
default:
V_39 = 1 ;
break;
}
V_43 = 1000000ULL * ( 400 * 3 + 100 * ( V_41 & 0x3f ) ) ;
V_42 = 3 * V_39 ;
F_44 ( V_43 , V_42 ) ;
return ( unsigned int ) V_43 ;
}
static unsigned int F_45 ( int V_1 , int V_38 )
{
unsigned int V_45 , V_46 , V_47 , V_48 ;
unsigned int V_49 , V_50 , V_42 ;
T_1 V_43 , V_5 ;
V_5 = F_2 ( V_1 ) -> V_5 ;
V_49 = F_39 ( V_5 , V_51 ) ;
V_50 = F_39 ( V_5 , V_52 ) ;
V_45 = ( ( V_49 >> 10 ) & 0x7f ) + 1 ;
V_46 = ( ( V_49 >> 8 ) & 0x3 ) + 1 ;
V_48 = ( ( V_49 >> 30 ) & 0x3 ) + 1 ;
V_47 = ( ( V_50 >> ( V_38 * 4 ) ) & 0xf ) + 1 ;
V_43 = 800000000ULL * V_45 ;
V_42 = 3 * V_46 * V_48 * V_47 ;
F_44 ( V_43 , V_42 ) ;
return ( unsigned int ) V_43 ;
}
unsigned int F_46 ( int V_1 , int V_38 )
{
if ( F_15 () )
return F_37 ( V_1 , V_38 ) ;
else
return F_45 ( V_1 , V_38 ) ;
}
static unsigned int F_47 ( int V_1 )
{
T_2 V_40 , V_53 , V_54 , V_39 , V_55 ;
T_2 V_56 , V_57 , V_58 , V_59 , V_60 , V_61 ;
T_3 V_5 , V_62 , V_63 , V_44 , V_64 ;
V_5 = F_2 ( V_1 ) -> V_5 ;
V_44 = F_38 ( V_1 ) ;
V_55 = F_6 () ;
if ( V_55 )
V_63 = ( F_39 ( V_5 ,
V_65 ) >> 18 ) & 0x3 ;
else
V_63 = ( F_39 ( V_5 ,
V_51 ) >> 18 ) & 0x3 ;
switch ( V_63 ) {
case 0 :
V_64 = 200000000ULL ;
V_60 = 3 ;
break;
case 1 :
V_64 = 100000000ULL ;
V_60 = 1 ;
break;
case 2 :
V_64 = 125000000ULL ;
V_60 = 1 ;
break;
case 3 :
V_64 = 400000000ULL ;
V_60 = 3 ;
break;
}
if ( V_55 ) {
V_59 = F_39 ( V_44 ,
V_66 ) & 0x3 ;
switch ( V_59 ) {
case 0 :
V_40 = F_39 ( V_44 ,
V_67 ) ;
V_53 = F_39 ( V_44 ,
V_68 ) ;
break;
case 1 :
V_40 = F_39 ( V_44 ,
F_48 ( 0 ) ) ;
V_53 = F_39 ( V_44 ,
F_49 ( 0 ) ) ;
break;
case 2 :
V_40 = F_39 ( V_44 ,
F_48 ( 1 ) ) ;
V_53 = F_39 ( V_44 ,
F_49 ( 1 ) ) ;
break;
case 3 :
V_40 = F_39 ( V_44 ,
F_48 ( 2 ) ) ;
V_53 = F_39 ( V_44 ,
F_49 ( 2 ) ) ;
break;
}
} else {
V_59 = ( F_39 ( V_5 ,
V_69 ) >> 22 ) & 0x3 ;
switch ( V_59 ) {
case 0 :
V_40 = F_39 ( V_5 ,
V_70 ) ;
V_53 = F_39 ( V_5 ,
V_71 ) ;
break;
case 1 :
V_40 = F_39 ( V_5 ,
F_50 ( 0 ) ) ;
V_53 = F_39 ( V_5 ,
F_51 ( 0 ) ) ;
break;
case 2 :
V_40 = F_39 ( V_5 ,
F_50 ( 1 ) ) ;
V_53 = F_39 ( V_5 ,
F_51 ( 1 ) ) ;
break;
case 3 :
V_40 = F_39 ( V_5 ,
F_50 ( 2 ) ) ;
V_53 = F_39 ( V_5 ,
F_51 ( 2 ) ) ;
break;
}
}
V_54 = ( V_40 >> 5 ) & 0x7 ;
V_39 = ( V_40 >> 24 ) & 0x7 ;
V_56 = V_53 & 0xff ;
V_57 = ( V_53 >> 8 ) & 0x1fff ;
switch ( V_39 ) {
case 1 :
V_39 = 2 ;
break;
case 3 :
V_39 = 4 ;
break;
case 7 :
V_39 = 8 ;
break;
case 6 :
V_39 = 16 ;
break;
case 0 :
default:
V_39 = 1 ;
break;
}
V_57 = V_57 / ( 1 << 13 ) ;
V_62 = ( ( V_64 >> 1 ) * ( 6 + V_56 ) ) + V_57 ;
V_58 = ( 1 << V_54 ) * V_39 * 3 ;
if ( V_58 > 0 )
F_44 ( V_62 , V_58 ) ;
if ( V_55 )
V_61 = F_39 ( V_44 ,
V_72 ) & 0x3 ;
else
V_61 = ( F_39 ( V_5 ,
V_73 ) >> 22 ) & 0x3 ;
F_44 ( V_62 , 1 << V_61 ) ;
return V_62 ;
}
unsigned int F_52 ( int V_1 )
{
if ( F_15 () )
return F_47 ( V_1 ) ;
else
return 133333333 ;
}
unsigned int F_53 ( void )
{
return F_46 ( 0 , 0 ) ;
}
int F_54 ( int V_74 , T_1 * V_75 )
{
T_1 V_76 , V_77 , V_78 ;
T_4 V_79 ;
unsigned int V_80 , V_81 , V_82 ;
int V_83 , V_1 , V_84 ;
V_76 = F_55 ( 0 ) ;
V_84 = 0 ;
for ( V_83 = 0 ; V_83 < 8 ; V_83 ++ ) {
if ( F_6 () ) {
V_80 = F_56 ( V_83 ) ;
V_81 = F_57 ( V_83 ) ;
V_82 = F_58 ( V_83 ) ;
} else {
V_80 = F_59 ( V_83 ) ;
V_81 = F_60 ( V_83 ) ;
V_82 = F_61 ( V_83 ) ;
}
if ( V_74 >= 0 ) {
V_79 = F_62 ( V_76 , V_82 ) ;
V_1 = ( V_79 >> 1 ) & 0x3 ;
if ( V_74 != V_1 )
continue;
}
V_79 = F_62 ( V_76 , V_80 ) ;
V_79 = ( V_79 >> 12 ) & 0xfffff ;
V_77 = ( T_1 ) V_79 << 20 ;
V_79 = F_62 ( V_76 , V_81 ) ;
V_79 = ( V_79 >> 12 ) & 0xfffff ;
if ( V_79 == 0 )
continue;
V_78 = ( ( T_1 ) V_79 + 1 ) << 20 ;
V_75 [ V_84 ] = V_77 ;
V_75 [ V_84 + 1 ] = V_78 ;
V_84 += 2 ;
}
return V_84 ;
}
