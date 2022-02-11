void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 ) ;
if ( V_1 == 0 )
V_3 -> V_4 = 1 ;
V_3 -> V_5 = F_3 ( V_1 ) ;
V_3 -> V_6 = F_4 ( V_1 ) ;
V_3 -> V_7 = F_5 () & V_8 ;
if ( F_6 () )
V_3 -> V_9 = F_7 ( V_1 ) ;
else
V_3 -> V_9 = 0 ;
F_8 ( & V_3 -> V_10 ) ;
}
static int F_9 ( int V_11 )
{
switch ( V_11 ) {
case V_12 :
return 12 ;
case V_13 :
return 125 ;
case V_14 :
return 126 ;
case V_15 :
return 127 ;
case V_16 :
return 128 ;
case V_17 :
return 114 ;
case V_18 :
return 115 ;
case V_19 :
return 116 ;
case V_20 :
return 133 ;
case V_21 :
return 134 ;
case V_22 :
return 143 ;
case V_23 :
return 151 ;
case V_24 :
return 152 ;
case V_25 :
return 153 ;
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
return 191 + V_11 - V_26 ;
}
return - 1 ;
}
static int F_11 ( int V_11 )
{
T_1 V_27 ;
int V_28 , V_29 ;
V_28 = 0 ;
switch ( V_11 ) {
case V_20 :
V_28 = F_12 ( 0 ) ;
break;
case V_21 :
V_28 = F_13 ( 0 ) ;
break;
case V_25 :
V_28 = F_14 ( 0 ) ;
break;
case V_13 :
case V_14 :
case V_15 :
case V_16 :
if ( F_15 () )
V_28 = F_16 ( 0 ) ;
else
V_28 = F_17 ( 0 ) ;
break;
case V_22 :
V_28 = F_18 ( 0 ) ;
break;
case V_12 :
V_28 = F_19 ( 0 ) ;
break;
case V_23 :
V_28 = F_20 ( 0 ) ;
break;
case V_24 :
V_28 = F_21 ( 0 ) ;
break;
default:
if ( F_15 () ) {
switch ( V_11 ) {
case V_30 :
V_28 = F_22 ( 0 ) ;
break;
case V_31 :
V_28 = F_23 ( 0 ) ;
break;
case V_32 :
V_28 = F_24 ( 0 ) ;
break;
}
} else {
switch ( V_11 ) {
case V_33 :
V_28 = F_25 ( 0 ) ;
break;
case V_34 :
V_28 = F_26 ( 0 ) ;
break;
case V_35 :
V_28 = F_27 ( 0 ) ;
break;
case V_36 :
V_28 = F_28 ( 0 ) ;
break;
case V_37 :
V_28 = F_29 ( 0 ) ;
break;
case V_38 :
V_28 = F_30 ( 0 ) ;
break;
}
}
}
if ( V_28 != 0 ) {
T_2 V_39 ;
V_27 = F_31 ( V_28 ) ;
V_39 = F_32 ( V_27 , V_40 ) ;
if ( V_39 == 0xffffffff ) {
V_29 = - 1 ;
} else {
V_29 = V_39 & 0xffff ;
switch ( V_11 ) {
case V_14 :
V_29 = V_29 + 1 ; break;
case V_15 :
V_29 = V_29 + 2 ; break;
case V_16 :
V_29 = V_29 + 3 ; break;
}
}
} else if ( V_11 >= F_10 ( 0 ) &&
V_11 <= F_10 ( 3 ) ) {
V_29 = F_33 ( V_11 -
V_26 ) ;
} else {
V_29 = - 1 ;
}
return V_29 ;
}
int F_34 ( int V_11 )
{
if ( V_11 >= F_35 ( 0 ) && V_11 <= F_35 ( 3 ) )
return - 2 ;
if ( V_11 >= F_36 ( 0 ) && V_11 <= F_36 ( 3 ) )
return - 2 ;
if ( F_6 () )
return F_9 ( V_11 ) ;
else
return F_11 ( V_11 ) ;
}
static unsigned int F_37 ( int V_1 , int V_41 )
{
unsigned int V_42 , V_43 , V_44 , V_45 ;
T_1 V_46 , V_5 , V_47 ;
if ( F_6 () ) {
V_47 = F_38 ( V_1 ) ;
V_43 = F_39 ( V_47 ,
F_40 ( V_41 ) ) ;
V_44 = F_39 ( V_47 ,
F_41 ( V_41 ) ) ;
} else {
V_5 = F_2 ( V_1 ) -> V_5 ;
V_43 = F_39 ( V_5 ,
F_42 ( V_41 ) ) ;
V_44 = F_39 ( V_5 ,
F_43 ( V_41 ) ) ;
}
switch ( ( V_43 >> 24 ) & 0x7 ) {
case 1 :
V_42 = 2 ;
break;
case 3 :
V_42 = 4 ;
break;
case 7 :
V_42 = 8 ;
break;
case 6 :
V_42 = 16 ;
break;
case 0 :
default:
V_42 = 1 ;
break;
}
V_46 = 1000000ULL * ( 400 * 3 + 100 * ( V_44 & 0x3f ) ) ;
V_45 = 3 * V_42 ;
F_44 ( V_46 , V_45 ) ;
return ( unsigned int ) V_46 ;
}
static unsigned int F_45 ( int V_1 , int V_41 )
{
unsigned int V_48 , V_49 , V_50 , V_51 ;
unsigned int V_52 , V_53 , V_45 ;
T_1 V_46 , V_5 ;
V_5 = F_2 ( V_1 ) -> V_5 ;
V_52 = F_39 ( V_5 , V_54 ) ;
V_53 = F_39 ( V_5 , V_55 ) ;
V_48 = ( ( V_52 >> 10 ) & 0x7f ) + 1 ;
V_49 = ( ( V_52 >> 8 ) & 0x3 ) + 1 ;
V_51 = ( ( V_52 >> 30 ) & 0x3 ) + 1 ;
V_50 = ( ( V_53 >> ( V_41 * 4 ) ) & 0xf ) + 1 ;
V_46 = 800000000ULL * V_48 ;
V_45 = 3 * V_49 * V_51 * V_50 ;
F_44 ( V_46 , V_45 ) ;
return ( unsigned int ) V_46 ;
}
unsigned int F_46 ( int V_1 , int V_41 )
{
if ( F_15 () )
return F_37 ( V_1 , V_41 ) ;
else
return F_45 ( V_1 , V_41 ) ;
}
static unsigned int F_47 ( int V_1 )
{
T_3 V_43 , V_56 , V_57 , V_42 , V_58 ;
T_3 V_59 , V_60 , V_61 , V_62 , V_63 , V_64 ;
T_4 V_5 , V_65 , V_66 , V_47 , V_67 ;
V_5 = F_2 ( V_1 ) -> V_5 ;
V_47 = F_38 ( V_1 ) ;
V_58 = F_6 () ;
if ( V_58 )
V_66 = ( F_39 ( V_5 ,
V_68 ) >> 18 ) & 0x3 ;
else
V_66 = ( F_39 ( V_5 ,
V_54 ) >> 18 ) & 0x3 ;
switch ( V_66 ) {
case 0 :
V_67 = 200000000ULL ;
V_63 = 3 ;
break;
case 1 :
V_67 = 100000000ULL ;
V_63 = 1 ;
break;
case 2 :
V_67 = 125000000ULL ;
V_63 = 1 ;
break;
case 3 :
V_67 = 400000000ULL ;
V_63 = 3 ;
break;
}
if ( V_58 ) {
V_62 = F_39 ( V_47 ,
V_69 ) & 0x3 ;
switch ( V_62 ) {
case 0 :
V_43 = F_39 ( V_47 ,
V_70 ) ;
V_56 = F_39 ( V_47 ,
V_71 ) ;
break;
case 1 :
V_43 = F_39 ( V_47 ,
F_48 ( 0 ) ) ;
V_56 = F_39 ( V_47 ,
F_49 ( 0 ) ) ;
break;
case 2 :
V_43 = F_39 ( V_47 ,
F_48 ( 1 ) ) ;
V_56 = F_39 ( V_47 ,
F_49 ( 1 ) ) ;
break;
case 3 :
V_43 = F_39 ( V_47 ,
F_48 ( 2 ) ) ;
V_56 = F_39 ( V_47 ,
F_49 ( 2 ) ) ;
break;
}
} else {
V_62 = ( F_39 ( V_5 ,
V_72 ) >> 22 ) & 0x3 ;
switch ( V_62 ) {
case 0 :
V_43 = F_39 ( V_5 ,
V_73 ) ;
V_56 = F_39 ( V_5 ,
V_74 ) ;
break;
case 1 :
V_43 = F_39 ( V_5 ,
F_50 ( 0 ) ) ;
V_56 = F_39 ( V_5 ,
F_51 ( 0 ) ) ;
break;
case 2 :
V_43 = F_39 ( V_5 ,
F_50 ( 1 ) ) ;
V_56 = F_39 ( V_5 ,
F_51 ( 1 ) ) ;
break;
case 3 :
V_43 = F_39 ( V_5 ,
F_50 ( 2 ) ) ;
V_56 = F_39 ( V_5 ,
F_51 ( 2 ) ) ;
break;
}
}
V_57 = ( V_43 >> 5 ) & 0x7 ;
V_42 = ( V_43 >> 24 ) & 0x7 ;
V_59 = V_56 & 0xff ;
V_60 = ( V_56 >> 8 ) & 0x1fff ;
switch ( V_42 ) {
case 1 :
V_42 = 2 ;
break;
case 3 :
V_42 = 4 ;
break;
case 7 :
V_42 = 8 ;
break;
case 6 :
V_42 = 16 ;
break;
case 0 :
default:
V_42 = 1 ;
break;
}
V_60 = V_60 / ( 1 << 13 ) ;
V_65 = ( ( V_67 >> 1 ) * ( 6 + V_59 ) ) + V_60 ;
V_61 = ( 1 << V_57 ) * V_42 * V_63 ;
if ( V_61 > 0 )
F_44 ( V_65 , V_61 ) ;
if ( V_58 )
V_64 = F_39 ( V_47 ,
V_75 ) & 0x3 ;
else
V_64 = ( F_39 ( V_5 ,
V_76 ) >> 22 ) & 0x3 ;
F_44 ( V_65 , 1 << V_64 ) ;
return V_65 ;
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
int F_54 ( int V_1 , T_1 * V_77 , int V_78 )
{
T_1 V_79 , V_80 , V_81 ;
T_2 V_39 ;
unsigned int V_82 , V_83 , V_84 ;
int V_85 , V_86 , V_87 ;
V_79 = F_55 ( 0 ) ;
V_87 = 0 ;
for ( V_85 = 0 ; V_85 < 8 ; V_85 ++ ) {
if ( V_87 + 1 >= V_78 )
break;
if ( F_6 () ) {
V_82 = F_56 ( V_85 ) ;
V_83 = F_57 ( V_85 ) ;
V_84 = F_58 ( V_85 ) ;
} else {
V_82 = F_59 ( V_85 ) ;
V_83 = F_60 ( V_85 ) ;
V_84 = F_61 ( V_85 ) ;
}
if ( V_1 >= 0 ) {
V_39 = F_62 ( V_79 , V_84 ) ;
V_86 = ( V_39 >> 1 ) & 0x3 ;
if ( V_86 != V_1 )
continue;
}
V_39 = F_62 ( V_79 , V_82 ) ;
V_39 = ( V_39 >> 12 ) & 0xfffff ;
V_80 = ( T_1 ) V_39 << 20 ;
V_39 = F_62 ( V_79 , V_83 ) ;
V_39 = ( V_39 >> 12 ) & 0xfffff ;
if ( V_39 == 0 )
continue;
V_81 = ( ( T_1 ) V_39 + 1 ) << 20 ;
V_77 [ V_87 ] = V_80 ;
V_77 [ V_87 + 1 ] = V_81 ;
V_87 += 2 ;
}
return V_87 ;
}
