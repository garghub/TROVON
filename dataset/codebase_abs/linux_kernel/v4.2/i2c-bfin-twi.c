static void F_1 ( struct V_1 * V_2 ,
unsigned short V_3 )
{
unsigned short V_4 = F_2 ( V_2 ) ;
if ( V_3 & V_5 ) {
if ( V_2 -> V_6 <= 0 ) {
if ( V_2 -> V_7 == V_8 )
F_3 ( V_2 ,
F_4 ( V_2 ) | V_9 ) ;
else if ( V_2 -> V_10 )
F_3 ( V_2 ,
F_4 ( V_2 ) | V_11 ) ;
else if ( V_2 -> V_7 == V_12 &&
V_2 -> V_13 + 1 < V_2 -> V_14 ) {
if ( V_2 -> V_15 [ V_2 -> V_13 + 1 ] . V_16 &
V_17 )
F_3 ( V_2 ,
F_4 ( V_2 ) |
V_9 ) ;
else
F_3 ( V_2 ,
F_4 ( V_2 ) &
~ V_9 ) ;
}
}
while ( V_2 -> V_6 > 0 &&
( F_5 ( V_2 ) & V_18 ) != V_19 ) {
F_6 ( V_2 , * ( V_2 -> V_20 ++ ) ) ;
V_2 -> V_6 -- ;
}
}
if ( V_3 & V_21 ) {
while ( V_2 -> V_22 > 0 &&
( F_5 ( V_2 ) & V_23 ) ) {
* ( V_2 -> V_20 ) = F_7 ( V_2 ) ;
if ( V_2 -> V_7 == V_8 ) {
V_2 -> V_7 = V_24 ;
if ( V_2 -> V_22 == 1 && V_2 -> V_10 )
V_2 -> V_22 = * V_2 -> V_20 + 1 ;
}
V_2 -> V_20 ++ ;
V_2 -> V_22 -- ;
}
if ( V_2 -> V_22 == 0 ) {
if ( V_2 -> V_10 ) {
F_8 ( V_2 ) ;
F_3 ( V_2 ,
F_4 ( V_2 ) | V_11 ) ;
} else if ( V_2 -> V_7 == V_12 &&
V_2 -> V_13 + 1 < V_2 -> V_14 ) {
if ( V_2 -> V_15 [ V_2 -> V_13 + 1 ] . V_16 & V_17 )
F_3 ( V_2 ,
F_4 ( V_2 ) | V_9 ) ;
else
F_3 ( V_2 ,
F_4 ( V_2 ) & ~ V_9 ) ;
}
}
}
if ( V_3 & V_25 ) {
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0x3e ) ;
F_3 ( V_2 , 0 ) ;
V_2 -> V_26 = - V_27 ;
if ( V_4 & V_28 )
F_11 ( & V_2 -> V_29 . V_30 , L_1 ) ;
if ( V_4 & V_31 )
F_11 ( & V_2 -> V_29 . V_30 , L_2 ) ;
if ( V_4 & V_32 )
F_11 ( & V_2 -> V_29 . V_30 , L_3 ) ;
if ( V_4 & V_33 )
F_11 ( & V_2 -> V_29 . V_30 , L_4 ) ;
if ( V_4 & V_34 )
F_11 ( & V_2 -> V_29 . V_30 , L_5 ) ;
if ( F_2 ( V_2 ) & V_35 ) {
int V_36 = 9 ;
do {
F_3 ( V_2 , V_37 ) ;
F_12 ( 6 ) ;
F_3 ( V_2 , 0 ) ;
F_12 ( 6 ) ;
} while ( ( F_2 ( V_2 ) & V_35 ) && V_36 -- );
F_3 ( V_2 , V_38 | V_37 ) ;
F_12 ( 6 ) ;
F_3 ( V_2 , V_38 ) ;
F_12 ( 6 ) ;
F_3 ( V_2 , 0 ) ;
}
if ( V_2 -> V_7 == V_39 &&
V_2 -> V_20 == NULL &&
( V_3 & V_40 ) && ( V_4 & V_32 ) )
V_2 -> V_26 = 1 ;
F_13 ( & V_2 -> F_13 ) ;
return;
}
if ( V_3 & V_40 ) {
if ( V_3 & ( V_5 | V_21 ) &&
( F_4 ( V_2 ) & V_41 ) == 0 &&
( V_2 -> V_7 == V_12 ||
V_2 -> V_7 == V_8 ) ) {
V_2 -> V_26 = - 1 ;
F_9 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
} else if ( V_2 -> V_7 == V_8 ) {
if ( V_2 -> V_22 == 0 ) {
V_2 -> V_22 = 1 ;
V_2 -> V_10 = 1 ;
F_3 ( V_2 ,
F_4 ( V_2 ) | ( 0xff << 6 ) ) ;
} else {
F_3 ( V_2 ,
( F_4 ( V_2 ) &
( ~ ( 0xff << 6 ) ) ) |
( V_2 -> V_22 << 6 ) ) ;
}
F_3 ( V_2 ,
F_4 ( V_2 ) & ~ V_42 ) ;
} else if ( V_2 -> V_7 == V_12 &&
V_2 -> V_13 + 1 < V_2 -> V_14 ) {
V_2 -> V_13 ++ ;
V_2 -> V_20 = V_2 -> V_15 [ V_2 -> V_13 ] . V_43 ;
V_2 -> V_6 = V_2 -> V_22 =
V_2 -> V_15 [ V_2 -> V_13 ] . V_44 ;
F_14 ( V_2 ,
V_2 -> V_15 [ V_2 -> V_13 ] . V_45 ) ;
if ( V_2 -> V_15 [ V_2 -> V_13 ] . V_16 & V_17 )
V_2 -> V_46 = V_47 ;
else {
V_2 -> V_46 = V_48 ;
if ( V_2 -> V_6 > 0 ) {
F_6 ( V_2 ,
* ( V_2 -> V_20 ++ ) ) ;
V_2 -> V_6 -- ;
}
}
if ( V_2 -> V_15 [ V_2 -> V_13 ] . V_44 <= 255 ) {
F_3 ( V_2 ,
( F_4 ( V_2 ) &
( ~ ( 0xff << 6 ) ) ) |
( V_2 -> V_15 [ V_2 -> V_13 ] . V_44 << 6 ) ) ;
V_2 -> V_10 = 0 ;
} else {
F_3 ( V_2 ,
( F_4 ( V_2 ) |
( 0xff << 6 ) ) ) ;
V_2 -> V_10 = 1 ;
}
if ( V_2 -> V_13 + 1 == V_2 -> V_14 )
F_3 ( V_2 ,
F_4 ( V_2 ) & ~ V_42 ) ;
} else {
V_2 -> V_26 = 1 ;
F_9 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
}
F_13 ( & V_2 -> F_13 ) ;
}
}
static T_1 F_15 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
unsigned long V_16 ;
unsigned short V_3 ;
F_16 ( & V_2 -> V_51 , V_16 ) ;
while ( 1 ) {
V_3 = F_17 ( V_2 ) ;
if ( ! V_3 )
break;
F_18 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 ) ;
}
F_19 ( & V_2 -> V_51 , V_16 ) ;
return V_52 ;
}
static int F_20 ( struct V_53 * V_29 ,
struct V_54 * V_55 , int V_56 )
{
struct V_1 * V_2 = V_29 -> V_57 ;
struct V_54 * V_15 ;
int V_58 = 0 ;
if ( ! ( F_21 ( V_2 ) & V_59 ) )
return - V_60 ;
if ( F_2 ( V_2 ) & V_61 )
return - V_62 ;
V_2 -> V_15 = V_55 ;
V_2 -> V_14 = V_56 ;
V_2 -> V_13 = 0 ;
V_15 = & V_55 [ 0 ] ;
if ( V_15 -> V_16 & V_63 ) {
F_22 ( & V_29 -> V_30 , L_6 ) ;
return - V_64 ;
}
if ( V_2 -> V_14 > 1 )
V_2 -> V_7 = V_12 ;
V_2 -> V_10 = 0 ;
V_2 -> V_20 = V_15 -> V_43 ;
V_2 -> V_6 = V_2 -> V_22 = V_15 -> V_44 ;
V_2 -> V_26 = 0 ;
F_23 ( & ( V_2 -> F_13 ) ) ;
F_14 ( V_2 , V_15 -> V_45 ) ;
F_24 ( V_2 , 0x3 ) ;
F_24 ( V_2 , 0 ) ;
if ( V_15 -> V_16 & V_17 )
V_2 -> V_46 = V_47 ;
else {
V_2 -> V_46 = V_48 ;
if ( V_2 -> V_6 > 0 ) {
F_6 ( V_2 , * ( V_2 -> V_20 ++ ) ) ;
V_2 -> V_6 -- ;
}
}
F_18 ( V_2 , V_25 | V_40 | V_5 | V_21 ) ;
F_9 ( V_2 , V_40 | V_25 | V_21 | V_5 ) ;
if ( V_15 -> V_44 <= 255 )
F_3 ( V_2 , V_15 -> V_44 << 6 ) ;
else {
F_3 ( V_2 , 0xff << 6 ) ;
V_2 -> V_10 = 1 ;
}
F_3 ( V_2 , F_4 ( V_2 ) | V_41 |
( V_2 -> V_14 > 1 ? V_42 : 0 ) |
( ( V_2 -> V_46 == V_47 ) ? V_9 : 0 ) |
( ( V_65 > 100 ) ? V_66 : 0 ) ) ;
while ( ! V_2 -> V_26 ) {
if ( ! F_25 ( & V_2 -> F_13 ,
V_29 -> V_67 ) ) {
V_2 -> V_26 = - 1 ;
F_22 ( & V_29 -> V_30 , L_7 ) ;
}
}
if ( V_2 -> V_26 == 1 )
V_58 = V_2 -> V_13 + 1 ;
else
V_58 = V_2 -> V_26 ;
return V_58 ;
}
static int F_26 ( struct V_53 * V_29 ,
struct V_54 * V_55 , int V_56 )
{
return F_20 ( V_29 , V_55 , V_56 ) ;
}
int F_27 ( struct V_53 * V_29 , T_2 V_45 ,
unsigned short V_16 , char V_46 ,
T_3 V_68 , int V_69 , union V_70 * V_71 )
{
struct V_1 * V_2 = V_29 -> V_57 ;
int V_58 = 0 ;
if ( ! ( F_21 ( V_2 ) & V_59 ) )
return - V_60 ;
if ( F_2 ( V_2 ) & V_61 )
return - V_62 ;
V_2 -> V_6 = 0 ;
V_2 -> V_22 = 0 ;
switch ( V_69 ) {
case V_72 :
V_2 -> V_20 = NULL ;
V_2 -> V_7 = V_39 ;
break;
case V_73 :
if ( V_71 == NULL )
V_2 -> V_20 = NULL ;
else {
if ( V_46 == V_47 )
V_2 -> V_22 = 1 ;
else
V_2 -> V_6 = 1 ;
V_2 -> V_20 = & V_71 -> V_74 ;
}
V_2 -> V_7 = V_39 ;
break;
case V_75 :
if ( V_46 == V_47 ) {
V_2 -> V_22 = 1 ;
V_2 -> V_7 = V_8 ;
} else {
V_2 -> V_6 = 1 ;
V_2 -> V_7 = V_24 ;
}
V_2 -> V_20 = & V_71 -> V_74 ;
break;
case V_76 :
if ( V_46 == V_47 ) {
V_2 -> V_22 = 2 ;
V_2 -> V_7 = V_8 ;
} else {
V_2 -> V_6 = 2 ;
V_2 -> V_7 = V_24 ;
}
V_2 -> V_20 = ( T_3 * ) & V_71 -> V_77 ;
break;
case V_78 :
V_2 -> V_6 = 2 ;
V_2 -> V_22 = 2 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_20 = ( T_3 * ) & V_71 -> V_77 ;
break;
case V_79 :
if ( V_46 == V_47 ) {
V_2 -> V_22 = 0 ;
V_2 -> V_7 = V_8 ;
} else {
V_2 -> V_6 = V_71 -> V_80 [ 0 ] + 1 ;
V_2 -> V_7 = V_24 ;
}
V_2 -> V_20 = V_71 -> V_80 ;
break;
case V_81 :
if ( V_46 == V_47 ) {
V_2 -> V_22 = V_71 -> V_80 [ 0 ] ;
V_2 -> V_7 = V_8 ;
} else {
V_2 -> V_6 = V_71 -> V_80 [ 0 ] ;
V_2 -> V_7 = V_24 ;
}
V_2 -> V_20 = ( T_3 * ) & V_71 -> V_80 [ 1 ] ;
break;
default:
return - 1 ;
}
V_2 -> V_26 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_68 = V_68 ;
F_23 ( & ( V_2 -> F_13 ) ) ;
F_24 ( V_2 , 0x3 ) ;
F_24 ( V_2 , 0 ) ;
F_18 ( V_2 , V_25 | V_40 | V_5 | V_21 ) ;
F_14 ( V_2 , V_45 ) ;
switch ( V_2 -> V_7 ) {
case V_24 :
F_6 ( V_2 , V_2 -> V_68 ) ;
F_9 ( V_2 , V_40 | V_25 |
( ( V_2 -> V_46 == V_47 ) ?
V_21 : V_5 ) ) ;
if ( V_2 -> V_6 + 1 <= 255 )
F_3 ( V_2 , ( V_2 -> V_6 + 1 ) << 6 ) ;
else {
F_3 ( V_2 , 0xff << 6 ) ;
V_2 -> V_10 = 1 ;
}
F_3 ( V_2 , F_4 ( V_2 ) | V_41 |
( ( V_65 > 100 ) ? V_66 : 0 ) ) ;
break;
case V_8 :
F_6 ( V_2 , V_2 -> V_68 ) ;
F_9 ( V_2 , V_40 | V_25 | V_21 | V_5 ) ;
if ( V_2 -> V_6 > 0 )
F_3 ( V_2 , ( V_2 -> V_6 + 1 ) << 6 ) ;
else
F_3 ( V_2 , 0x1 << 6 ) ;
F_3 ( V_2 , F_4 ( V_2 ) | V_41 | V_42 |
( ( V_65 > 100 ) ? V_66 : 0 ) ) ;
break;
default:
F_3 ( V_2 , 0 ) ;
if ( V_69 != V_72 ) {
if ( V_2 -> V_46 != V_47 ) {
if ( V_2 -> V_6 > 0 ) {
F_6 ( V_2 ,
* ( V_2 -> V_20 ++ ) ) ;
if ( V_2 -> V_6 <= 255 )
F_3 ( V_2 ,
V_2 -> V_6 << 6 ) ;
else {
F_3 ( V_2 ,
0xff << 6 ) ;
V_2 -> V_10 = 1 ;
}
V_2 -> V_6 -- ;
} else {
F_6 ( V_2 , V_2 -> V_68 ) ;
F_3 ( V_2 , 1 << 6 ) ;
}
} else {
if ( V_2 -> V_22 > 0 && V_2 -> V_22 <= 255 )
F_3 ( V_2 ,
V_2 -> V_22 << 6 ) ;
else if ( V_2 -> V_22 > 255 ) {
F_3 ( V_2 , 0xff << 6 ) ;
V_2 -> V_10 = 1 ;
} else
break;
}
}
F_9 ( V_2 , V_40 | V_25 |
( ( V_2 -> V_46 == V_47 ) ?
V_21 : V_5 ) ) ;
F_3 ( V_2 , F_4 ( V_2 ) | V_41 |
( ( V_2 -> V_46 == V_47 ) ? V_9 : 0 ) |
( ( V_65 > 100 ) ? V_66 : 0 ) ) ;
break;
}
while ( ! V_2 -> V_26 ) {
if ( ! F_25 ( & V_2 -> F_13 ,
V_29 -> V_67 ) ) {
V_2 -> V_26 = - 1 ;
F_22 ( & V_29 -> V_30 , L_8 ) ;
}
}
V_58 = ( V_2 -> V_26 >= 0 ) ? 0 : - 1 ;
return V_58 ;
}
int F_28 ( struct V_53 * V_29 , T_2 V_45 ,
unsigned short V_16 , char V_46 ,
T_3 V_68 , int V_69 , union V_70 * V_71 )
{
return F_27 ( V_29 , V_45 , V_16 ,
V_46 , V_68 , V_69 , V_71 ) ;
}
static T_4 F_29 ( struct V_53 * V_29 )
{
return V_82 | V_83 |
V_84 | V_85 |
V_86 | V_87 |
V_88 | V_89 ;
}
static int F_30 ( struct V_90 * V_30 )
{
struct V_1 * V_2 = F_31 ( V_30 ) ;
V_2 -> V_91 = F_32 ( V_2 ) ;
V_2 -> V_92 = F_21 ( V_2 ) ;
F_33 ( V_2 -> V_49 , V_2 ) ;
F_34 ( V_2 , V_2 -> V_92 & ~ V_59 ) ;
return 0 ;
}
static int F_35 ( struct V_90 * V_30 )
{
struct V_1 * V_2 = F_31 ( V_30 ) ;
int V_58 = F_36 ( V_2 -> V_49 , F_15 ,
0 , F_37 ( V_30 ) -> V_93 , V_2 ) ;
if ( V_58 ) {
F_22 ( V_30 , L_9 , V_2 -> V_49 ) ;
return - V_94 ;
}
F_38 ( V_2 , V_2 -> V_91 ) ;
F_34 ( V_2 , V_2 -> V_92 ) ;
return 0 ;
}
static int F_39 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
struct V_53 * V_97 ;
struct V_98 * V_99 ;
int V_58 ;
unsigned int V_100 ;
V_2 = F_40 ( & V_96 -> V_30 , sizeof( struct V_1 ) ,
V_101 ) ;
if ( ! V_2 ) {
F_22 ( & V_96 -> V_30 , L_10 ) ;
return - V_102 ;
}
F_41 ( & ( V_2 -> V_51 ) ) ;
V_99 = F_42 ( V_96 , V_103 , 0 ) ;
V_2 -> V_104 = F_43 ( & V_96 -> V_30 , V_99 ) ;
if ( F_44 ( V_2 -> V_104 ) ) {
F_22 ( & V_96 -> V_30 , L_11 ) ;
return F_45 ( V_2 -> V_104 ) ;
}
V_2 -> V_49 = F_46 ( V_96 , 0 ) ;
if ( V_2 -> V_49 < 0 ) {
F_22 ( & V_96 -> V_30 , L_12 ) ;
return - V_105 ;
}
V_97 = & V_2 -> V_29 ;
V_97 -> V_106 = V_96 -> V_107 ;
F_47 ( V_97 -> V_93 , V_96 -> V_93 , sizeof( V_97 -> V_93 ) ) ;
V_97 -> V_108 = & V_109 ;
V_97 -> V_57 = V_2 ;
V_97 -> V_110 = V_111 ;
V_97 -> V_30 . V_112 = & V_96 -> V_30 ;
V_97 -> V_67 = 5 * V_113 ;
V_97 -> V_114 = 3 ;
V_58 = F_48 (
F_49 ( & V_96 -> V_30 ) ,
L_13 ) ;
if ( V_58 ) {
F_22 ( & V_96 -> V_30 , L_14 ) ;
return - V_115 ;
}
V_58 = F_50 ( & V_96 -> V_30 , V_2 -> V_49 , F_15 ,
0 , V_96 -> V_93 , V_2 ) ;
if ( V_58 ) {
F_22 ( & V_96 -> V_30 , L_9 , V_2 -> V_49 ) ;
V_58 = - V_94 ;
goto V_116;
}
F_34 ( V_2 , ( ( F_51 () / 1000 / 1000 + 5 ) / 10 ) & 0x7F ) ;
V_100 = ( ( 10 * 1000 / V_65 ) + 1 ) / 2 ;
F_38 ( V_2 , ( V_100 << 8 ) | V_100 ) ;
F_34 ( V_2 , F_21 ( V_2 ) | V_59 ) ;
V_58 = F_52 ( V_97 ) ;
if ( V_58 < 0 ) {
F_22 ( & V_96 -> V_30 , L_15 ) ;
goto V_116;
}
F_53 ( V_96 , V_2 ) ;
F_54 ( & V_96 -> V_30 , L_16
L_17 , V_2 -> V_104 ) ;
return 0 ;
V_116:
F_55 ( F_49 ( & V_96 -> V_30 ) ) ;
return V_58 ;
}
static int F_56 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_57 ( V_96 ) ;
F_58 ( & ( V_2 -> V_29 ) ) ;
F_55 ( F_49 ( & V_96 -> V_30 ) ) ;
return 0 ;
}
static int T_5 F_59 ( void )
{
return F_60 ( & V_117 ) ;
}
static void T_6 F_61 ( void )
{
F_62 ( & V_117 ) ;
}
