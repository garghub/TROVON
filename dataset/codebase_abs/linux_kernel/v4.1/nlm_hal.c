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
return 125 ;
case V_13 :
return 126 ;
case V_14 :
return 127 ;
case V_15 :
return 128 ;
case V_16 :
return 114 ;
case V_17 :
return 115 ;
case V_18 :
return 116 ;
case V_19 :
return 133 ;
case V_20 :
return 134 ;
case V_21 :
return 143 ;
case V_22 :
return 152 ;
case V_23 :
return 153 ;
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
return 191 + V_10 - V_24 ;
}
return - 1 ;
}
static int F_11 ( int V_10 )
{
T_1 V_25 ;
int V_26 , V_27 ;
V_26 = 0 ;
switch ( V_10 ) {
case V_19 :
V_26 = F_12 ( 0 ) ;
break;
case V_20 :
V_26 = F_13 ( 0 ) ;
break;
case V_23 :
V_26 = F_14 ( 0 ) ;
break;
case V_12 :
case V_13 :
case V_14 :
case V_15 :
if ( F_15 () )
V_26 = F_16 ( 0 ) ;
else
V_26 = F_17 ( 0 ) ;
break;
case V_21 :
V_26 = F_18 ( 0 ) ;
break;
case V_11 :
V_26 = F_19 ( 0 ) ;
break;
case V_28 :
V_26 = F_20 ( 0 ) ;
break;
case V_22 :
V_26 = F_21 ( 0 ) ;
break;
default:
if ( F_15 () ) {
switch ( V_10 ) {
case V_29 :
V_26 = F_22 ( 0 ) ;
break;
case V_30 :
V_26 = F_23 ( 0 ) ;
break;
case V_31 :
V_26 = F_24 ( 0 ) ;
break;
}
} else {
switch ( V_10 ) {
case V_32 :
V_26 = F_25 ( 0 ) ;
break;
case V_33 :
V_26 = F_26 ( 0 ) ;
break;
case V_34 :
V_26 = F_27 ( 0 ) ;
break;
case V_35 :
V_26 = F_28 ( 0 ) ;
break;
case V_36 :
V_26 = F_29 ( 0 ) ;
break;
case V_37 :
V_26 = F_30 ( 0 ) ;
break;
}
}
}
if ( V_26 != 0 ) {
T_2 V_38 ;
V_25 = F_31 ( V_26 ) ;
V_38 = F_32 ( V_25 , V_39 ) ;
if ( V_38 == 0xffffffff ) {
V_27 = - 1 ;
} else {
V_27 = V_38 & 0xffff ;
switch ( V_10 ) {
case V_13 :
V_27 = V_27 + 1 ; break;
case V_14 :
V_27 = V_27 + 2 ; break;
case V_15 :
V_27 = V_27 + 3 ; break;
}
}
} else if ( V_10 >= F_10 ( 0 ) &&
V_10 <= F_10 ( 3 ) ) {
V_27 = F_33 ( V_10 -
V_24 ) ;
} else {
V_27 = - 1 ;
}
return V_27 ;
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
static unsigned int F_37 ( int V_1 , int V_40 )
{
unsigned int V_41 , V_42 , V_43 , V_44 ;
T_1 V_45 , V_5 , V_46 ;
if ( F_6 () ) {
V_46 = F_38 ( V_1 ) ;
V_42 = F_39 ( V_46 ,
F_40 ( V_40 ) ) ;
V_43 = F_39 ( V_46 ,
F_41 ( V_40 ) ) ;
} else {
V_5 = F_2 ( V_1 ) -> V_5 ;
V_42 = F_39 ( V_5 ,
F_42 ( V_40 ) ) ;
V_43 = F_39 ( V_5 ,
F_43 ( V_40 ) ) ;
}
switch ( ( V_42 >> 24 ) & 0x7 ) {
case 1 :
V_41 = 2 ;
break;
case 3 :
V_41 = 4 ;
break;
case 7 :
V_41 = 8 ;
break;
case 6 :
V_41 = 16 ;
break;
case 0 :
default:
V_41 = 1 ;
break;
}
V_45 = 1000000ULL * ( 400 * 3 + 100 * ( V_43 & 0x3f ) ) ;
V_44 = 3 * V_41 ;
F_44 ( V_45 , V_44 ) ;
return ( unsigned int ) V_45 ;
}
static unsigned int F_45 ( int V_1 , int V_40 )
{
unsigned int V_47 , V_48 , V_49 , V_50 ;
unsigned int V_51 , V_52 , V_44 ;
T_1 V_45 , V_5 ;
V_5 = F_2 ( V_1 ) -> V_5 ;
V_51 = F_39 ( V_5 , V_53 ) ;
V_52 = F_39 ( V_5 , V_54 ) ;
V_47 = ( ( V_51 >> 10 ) & 0x7f ) + 1 ;
V_48 = ( ( V_51 >> 8 ) & 0x3 ) + 1 ;
V_50 = ( ( V_51 >> 30 ) & 0x3 ) + 1 ;
V_49 = ( ( V_52 >> ( V_40 * 4 ) ) & 0xf ) + 1 ;
V_45 = 800000000ULL * V_47 ;
V_44 = 3 * V_48 * V_50 * V_49 ;
F_44 ( V_45 , V_44 ) ;
return ( unsigned int ) V_45 ;
}
unsigned int F_46 ( int V_1 , int V_40 )
{
if ( F_15 () )
return F_37 ( V_1 , V_40 ) ;
else
return F_45 ( V_1 , V_40 ) ;
}
static unsigned int F_47 ( int V_1 )
{
T_3 V_42 , V_55 , V_56 , V_41 , V_57 ;
T_3 V_58 , V_59 , V_60 , V_61 , V_62 , V_63 ;
T_4 V_5 , V_64 , V_65 , V_46 , V_66 ;
V_5 = F_2 ( V_1 ) -> V_5 ;
V_46 = F_38 ( V_1 ) ;
V_57 = F_6 () ;
if ( V_57 )
V_65 = ( F_39 ( V_5 ,
V_67 ) >> 18 ) & 0x3 ;
else
V_65 = ( F_39 ( V_5 ,
V_53 ) >> 18 ) & 0x3 ;
switch ( V_65 ) {
case 0 :
V_66 = 200000000ULL ;
V_62 = 3 ;
break;
case 1 :
V_66 = 100000000ULL ;
V_62 = 1 ;
break;
case 2 :
V_66 = 125000000ULL ;
V_62 = 1 ;
break;
case 3 :
V_66 = 400000000ULL ;
V_62 = 3 ;
break;
}
if ( V_57 ) {
V_61 = F_39 ( V_46 ,
V_68 ) & 0x3 ;
switch ( V_61 ) {
case 0 :
V_42 = F_39 ( V_46 ,
V_69 ) ;
V_55 = F_39 ( V_46 ,
V_70 ) ;
break;
case 1 :
V_42 = F_39 ( V_46 ,
F_48 ( 0 ) ) ;
V_55 = F_39 ( V_46 ,
F_49 ( 0 ) ) ;
break;
case 2 :
V_42 = F_39 ( V_46 ,
F_48 ( 1 ) ) ;
V_55 = F_39 ( V_46 ,
F_49 ( 1 ) ) ;
break;
case 3 :
V_42 = F_39 ( V_46 ,
F_48 ( 2 ) ) ;
V_55 = F_39 ( V_46 ,
F_49 ( 2 ) ) ;
break;
}
} else {
V_61 = ( F_39 ( V_5 ,
V_71 ) >> 22 ) & 0x3 ;
switch ( V_61 ) {
case 0 :
V_42 = F_39 ( V_5 ,
V_72 ) ;
V_55 = F_39 ( V_5 ,
V_73 ) ;
break;
case 1 :
V_42 = F_39 ( V_5 ,
F_50 ( 0 ) ) ;
V_55 = F_39 ( V_5 ,
F_51 ( 0 ) ) ;
break;
case 2 :
V_42 = F_39 ( V_5 ,
F_50 ( 1 ) ) ;
V_55 = F_39 ( V_5 ,
F_51 ( 1 ) ) ;
break;
case 3 :
V_42 = F_39 ( V_5 ,
F_50 ( 2 ) ) ;
V_55 = F_39 ( V_5 ,
F_51 ( 2 ) ) ;
break;
}
}
V_56 = ( V_42 >> 5 ) & 0x7 ;
V_41 = ( V_42 >> 24 ) & 0x7 ;
V_58 = V_55 & 0xff ;
V_59 = ( V_55 >> 8 ) & 0x1fff ;
switch ( V_41 ) {
case 1 :
V_41 = 2 ;
break;
case 3 :
V_41 = 4 ;
break;
case 7 :
V_41 = 8 ;
break;
case 6 :
V_41 = 16 ;
break;
case 0 :
default:
V_41 = 1 ;
break;
}
V_59 = V_59 / ( 1 << 13 ) ;
V_64 = ( ( V_66 >> 1 ) * ( 6 + V_58 ) ) + V_59 ;
V_60 = ( 1 << V_56 ) * V_41 * V_62 ;
if ( V_60 > 0 )
F_44 ( V_64 , V_60 ) ;
if ( V_57 )
V_63 = F_39 ( V_46 ,
V_74 ) & 0x3 ;
else
V_63 = ( F_39 ( V_5 ,
V_75 ) >> 22 ) & 0x3 ;
F_44 ( V_64 , 1 << V_63 ) ;
return V_64 ;
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
int F_54 ( int V_1 , T_1 * V_76 , int V_77 )
{
T_1 V_78 , V_79 , V_80 ;
T_2 V_38 ;
unsigned int V_81 , V_82 , V_83 ;
int V_84 , V_85 , V_86 ;
V_78 = F_55 ( 0 ) ;
V_86 = 0 ;
for ( V_84 = 0 ; V_84 < 8 ; V_84 ++ ) {
if ( V_86 + 1 >= V_77 )
break;
if ( F_6 () ) {
V_81 = F_56 ( V_84 ) ;
V_82 = F_57 ( V_84 ) ;
V_83 = F_58 ( V_84 ) ;
} else {
V_81 = F_59 ( V_84 ) ;
V_82 = F_60 ( V_84 ) ;
V_83 = F_61 ( V_84 ) ;
}
if ( V_1 >= 0 ) {
V_38 = F_62 ( V_78 , V_83 ) ;
V_85 = ( V_38 >> 1 ) & 0x3 ;
if ( V_85 != V_1 )
continue;
}
V_38 = F_62 ( V_78 , V_81 ) ;
V_38 = ( V_38 >> 12 ) & 0xfffff ;
V_79 = ( T_1 ) V_38 << 20 ;
V_38 = F_62 ( V_78 , V_82 ) ;
V_38 = ( V_38 >> 12 ) & 0xfffff ;
if ( V_38 == 0 )
continue;
V_80 = ( ( T_1 ) V_38 + 1 ) << 20 ;
V_76 [ V_86 ] = V_79 ;
V_76 [ V_86 + 1 ] = V_80 ;
V_86 += 2 ;
}
return V_86 ;
}
