static void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_1 >> 8 , V_2 + 1 ) ;
F_2 ( V_1 >> 16 , V_2 + 2 ) ;
F_2 ( V_1 >> 24 , V_2 + 3 ) ;
}
static void F_3 ( struct V_3 * V_4 ,
T_3 V_5 , T_3 V_6 )
{
T_1 * V_7 = V_4 -> V_8 + V_5 ;
T_1 * V_9 = V_4 -> V_10 + V_5 ;
T_1 * V_11 = V_4 -> V_8 + V_5 + V_6 ;
do {
T_1 V_12 , V_13 = * V_7 ++ ;
V_12 = ( V_13 & 8 ) << ( 28 - 3 ) ;
V_13 >>= 4 ;
* V_9 ++ = V_13 | V_12 ;
} while ( V_7 < V_11 );
}
static T_1 F_4 ( T_1 V_13 )
{
V_13 ^= V_13 >> 16 ;
V_13 ^= V_13 >> 8 ;
V_13 ^= V_13 >> 4 ;
V_13 ^= V_13 >> 2 ;
V_13 ^= V_13 >> 1 ;
return ( V_13 & 1 ) << 27 ;
}
static void F_5 ( struct V_3 * V_4 ,
T_3 V_5 , T_3 V_6 )
{
T_1 * V_7 = V_4 -> V_8 + V_5 ;
T_1 * V_9 = V_4 -> V_10 + V_5 ;
T_1 * V_11 = V_4 -> V_8 + V_5 + V_6 ;
do {
unsigned V_14 ;
T_4 * V_15 ;
V_15 = V_4 -> V_15 [ V_4 -> V_16 ++ ] ;
if ( V_4 -> V_16 >= 192 )
V_4 -> V_16 = 0 ;
V_14 = V_4 -> V_17 ;
do {
T_1 V_13 = * V_7 ++ ;
V_13 &= ~ 0xff000000 ;
V_13 |= * V_15 ++ << 24 ;
V_13 |= F_4 ( V_13 & ~ 0xf8000000 ) ;
* V_9 ++ = V_13 ;
} while ( -- V_14 );
} while ( V_7 < V_11 );
}
static void F_6 ( struct V_3 * V_4 ,
struct V_18 * V_19 )
{
T_4 V_15 [ 4 ] ;
unsigned V_20 , V_14 , V_21 ;
F_7 ( V_19 , V_15 , sizeof( V_15 ) ) ;
memset ( V_4 -> V_15 , 0 , sizeof( V_4 -> V_15 ) ) ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
V_15 [ 2 ] &= ~ V_22 ;
V_15 [ 2 ] |= ( V_20 + 1 ) << 4 ;
for ( V_14 = 0 ; V_14 < F_8 ( V_15 ) ; V_14 ++ ) {
unsigned V_23 = V_15 [ V_14 ] ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ , V_23 >>= 1 )
V_4 -> V_15 [ V_14 * 8 + V_21 ] [ V_20 ] = ( V_23 & 1 ) << 2 ;
}
}
V_4 -> V_15 [ 0 ] [ 0 ] |= F_9 ( 4 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
void T_2 * V_24 = V_4 -> V_25 . V_24 ;
unsigned V_5 = V_4 -> V_26 ;
unsigned V_27 = V_4 -> V_28 ;
T_1 V_29 , V_30 ;
V_4 -> V_31 ( V_4 , V_5 , V_27 ) ;
F_2 ( V_32 ,
V_24 + V_33 ) ;
V_29 = V_4 -> V_34 + V_5 ;
V_30 = V_29 + V_27 - 1 ;
F_1 ( V_29 , V_24 + V_35 ) ;
F_1 ( V_30 , V_24 + V_36 ) ;
F_2 ( ( T_4 ) ~ V_37 , V_24 + V_38 ) ;
F_11 ( V_39 , V_24 + V_40 ) ;
V_5 += V_27 ;
if ( V_5 >= V_4 -> V_41 )
V_5 = 0 ;
V_4 -> V_26 = V_5 ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_2 ( ~ 0 , V_4 -> V_25 . V_24 + V_38 ) ;
F_2 ( V_42 , V_4 -> V_25 . V_24 + V_43 ) ;
}
static T_5 F_13 ( int V_44 , void * V_25 )
{
struct V_3 * V_4 = V_25 ;
struct V_45 * V_46 ;
unsigned V_47 ;
V_47 = F_14 ( V_4 -> V_25 . V_24 + V_33 ) ;
if ( ! V_47 )
return V_48 ;
F_2 ( V_47 , V_4 -> V_25 . V_24 + V_33 ) ;
V_46 = V_4 -> V_46 ;
if ( V_47 & V_49 && V_46 ) {
F_15 ( V_46 ) ;
F_16 ( & V_4 -> V_50 ) ;
if ( V_4 -> V_46 )
F_10 ( V_4 ) ;
F_17 ( & V_4 -> V_50 ) ;
}
return V_51 ;
}
static int F_18 ( struct V_45 * V_46 )
{
struct V_18 * V_19 = V_46 -> V_19 ;
struct V_3 * V_4 = V_46 -> V_52 ;
void T_2 * V_24 = V_4 -> V_25 . V_24 ;
int V_53 ;
V_19 -> V_54 = V_55 ;
V_53 = F_19 ( V_19 , V_4 -> V_25 . V_56 ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 = F_20 ( V_19 ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 = F_21 ( V_19 ,
V_57 ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 = F_22 ( V_19 ,
V_58 ,
0 , V_46 -> V_59 . V_6 ) ;
if ( V_53 < 0 )
return V_53 ;
F_2 ( V_60 ,
V_24 + V_61 ) ;
F_2 ( ~ 0 , V_24 + V_62 ) ;
F_2 ( ~ 0 , V_24 + V_63 ) ;
F_2 ( ~ 0 , V_24 + V_38 ) ;
F_2 ( ~ 0 , V_24 + V_33 ) ;
V_53 = F_23 ( V_4 -> V_25 . V_44 , F_13 , V_64 ,
L_1 , V_4 ) ;
if ( V_53 )
return V_53 ;
F_2 ( V_65 &
~ V_66 ,
V_24 + V_67 ) ;
return 0 ;
}
static int F_24 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = V_46 -> V_52 ;
F_2 ( V_65 ,
V_4 -> V_25 . V_24 + V_67 ) ;
F_25 ( V_4 -> V_25 . V_44 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 )
{
return F_27 ( V_46 ) ;
}
static int F_28 ( struct V_45 * V_46 ,
struct V_68 * V_69 )
{
return F_29 ( V_46 ,
F_30 ( V_69 ) ) ;
}
static int F_31 ( struct V_45 * V_46 )
{
struct V_18 * V_19 = V_46 -> V_19 ;
struct V_3 * V_4 = V_46 -> V_52 ;
T_4 V_70 , V_71 , V_72 , V_73 , V_74 ;
switch ( V_4 -> V_75 ) {
case 0x0a :
V_71 = V_76 |
V_77 ;
if ( V_19 -> V_17 == 2 )
V_70 = 126 ;
else
V_70 = 124 ;
break;
case 0x1a :
V_71 = V_76 |
V_78 ;
V_70 = 128 ;
break;
default:
return - V_79 ;
}
F_32 ( V_4 -> V_25 . V_80 , V_19 -> V_81 ) ;
V_19 -> V_54 . V_82 = V_70 * 32 ;
V_71 |= V_83 ;
V_72 = V_84 [ V_19 -> V_17 - 2 ] . V_72 ;
V_74 = V_84 [ V_19 -> V_17 - 2 ] . V_74 ;
if ( V_19 -> V_17 > 2 )
V_73 = V_85 ;
else
V_73 = V_86 ;
F_2 ( V_70 , V_4 -> V_25 . V_24 + V_87 ) ;
F_2 ( V_71 , V_4 -> V_25 . V_24 + V_61 ) ;
F_2 ( V_72 , V_4 -> V_25 . V_24 + V_88 ) ;
F_2 ( V_73 , V_4 -> V_25 . V_24 + V_89 ) ;
F_2 ( V_74 , V_4 -> V_25 . V_24 + V_90 ) ;
switch ( V_19 -> V_91 ) {
case V_92 :
V_4 -> V_31 = F_3 ;
break;
case V_93 :
F_6 ( V_4 , V_19 ) ;
V_4 -> V_31 = F_5 ;
break;
}
V_4 -> V_16 = 0 ;
V_4 -> V_17 = V_19 -> V_17 ;
V_4 -> V_8 = V_19 -> V_94 ;
V_4 -> V_10 = V_46 -> V_59 . V_95 ;
V_4 -> V_34 = V_46 -> V_59 . V_96 ;
V_4 -> V_28 = F_33 ( V_46 ) ;
V_4 -> V_41 = F_34 ( V_46 ) ;
return 0 ;
}
static int F_35 ( struct V_45 * V_46 , int V_97 )
{
struct V_3 * V_4 = V_46 -> V_52 ;
unsigned long V_98 ;
int V_53 = 0 ;
switch ( V_97 ) {
case V_99 :
F_36 ( & V_4 -> V_50 , V_98 ) ;
V_4 -> V_26 = 0 ;
V_4 -> V_46 = V_46 ;
F_10 ( V_4 ) ;
F_37 ( V_4 -> V_25 . V_80 ) ;
F_38 ( & V_4 -> V_50 , V_98 ) ;
V_46 -> V_19 -> V_100 = V_46 -> V_19 -> V_101 ;
break;
case V_102 :
F_36 ( & V_4 -> V_50 , V_98 ) ;
V_4 -> V_46 = NULL ;
F_12 ( V_4 ) ;
F_39 ( V_4 -> V_25 . V_80 ) ;
F_38 ( & V_4 -> V_50 , V_98 ) ;
break;
default:
V_53 = - V_79 ;
break;
}
return V_53 ;
}
static T_6 F_40 ( struct V_45 * V_46 )
{
struct V_18 * V_19 = V_46 -> V_19 ;
struct V_3 * V_4 = V_46 -> V_52 ;
return F_41 ( V_19 , V_4 -> V_26 ) ;
}
static int F_42 ( struct V_103 * V_104 )
{
const struct V_105 * V_25 = V_104 -> V_106 . V_107 ;
struct V_108 * V_106 = V_104 -> V_106 . V_109 ;
struct V_3 * V_4 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
unsigned V_75 ;
int V_53 ;
F_2 ( V_65 ,
V_25 -> V_24 + V_67 ) ;
V_75 = F_14 ( V_25 -> V_24 + V_114 ) ;
if ( V_75 != 0x0a && V_75 != 0x1a ) {
F_43 ( V_106 , L_2 ,
V_75 ) ;
return - V_115 ;
}
V_53 = F_44 ( V_106 , V_116 , V_117 ,
V_118 , sizeof( struct V_3 ) , & V_111 ) ;
if ( V_53 < 0 )
return V_53 ;
F_45 ( V_111 -> V_119 , V_120 , sizeof( V_111 -> V_119 ) ) ;
F_45 ( V_111 -> V_121 , L_3 , sizeof( V_111 -> V_121 ) ) ;
snprintf ( V_111 -> V_122 , sizeof( V_111 -> V_122 ) ,
L_4 , V_111 -> V_121 , V_75 ,
V_25 -> V_44 ) ;
V_4 = V_111 -> V_52 ;
V_4 -> V_111 = V_111 ;
V_4 -> V_25 = * V_25 ;
V_4 -> V_75 = V_75 ;
F_46 ( & V_4 -> V_50 ) ;
V_53 = F_47 ( V_111 , L_5 , 0 , 1 , 0 , & V_113 ) ;
if ( V_53 < 0 )
goto V_123;
V_4 -> V_113 = V_113 ;
V_113 -> V_52 = V_4 ;
F_45 ( V_113 -> V_124 , V_120 , sizeof( V_113 -> V_124 ) ) ;
F_48 ( V_113 , V_125 , & V_126 ) ;
F_49 ( V_113 , V_127 ,
V_106 , 128 * 1024 , 1024 * 1024 ) ;
V_53 = F_50 ( V_111 ) ;
if ( V_53 < 0 )
goto V_123;
F_51 ( V_104 , V_4 ) ;
return 0 ;
V_123:
F_52 ( V_111 ) ;
return V_53 ;
}
static int F_53 ( struct V_103 * V_104 )
{
struct V_3 * V_4 = F_54 ( V_104 ) ;
F_52 ( V_4 -> V_111 ) ;
return 0 ;
}
static int F_55 ( struct V_108 * V_106 )
{
struct V_3 * V_4 = F_56 ( V_106 ) ;
F_57 ( V_4 -> V_111 , V_128 ) ;
F_58 ( V_4 -> V_113 ) ;
return 0 ;
}
static int F_59 ( struct V_108 * V_106 )
{
struct V_3 * V_4 = F_56 ( V_106 ) ;
F_57 ( V_4 -> V_111 , V_129 ) ;
return 0 ;
}
