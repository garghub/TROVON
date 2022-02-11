static void F_1 ( void * V_1 , const void T_1 * V_2 , T_2 V_3 )
{
int V_4 ;
T_3 * V_5 = V_1 ;
const T_1 T_3 * V_6 = V_2 ;
for ( V_4 = 0 ; V_4 < ( V_3 >> 2 ) ; V_4 ++ )
* V_5 ++ = F_2 ( V_6 ++ ) ;
}
static void F_3 ( void * V_1 , const void T_1 * V_2 , T_2 V_3 )
{
int V_4 ;
T_4 * V_5 = V_1 ;
const T_1 T_4 * V_6 = V_2 ;
if ( F_4 ( V_1 , 4 ) == V_1 && F_5 ( V_3 , 4 ) ) {
F_1 ( V_1 , V_2 , V_3 ) ;
return;
}
for ( V_4 = 0 ; V_4 < ( V_3 >> 1 ) ; V_4 ++ )
* V_5 ++ = F_6 ( V_6 ++ ) ;
}
static inline void F_7 ( void T_1 * V_1 , const void * V_2 , int V_3 )
{
F_8 ( V_1 , V_2 , V_3 / 4 ) ;
}
static void F_9 ( void T_1 * V_1 , const void * V_2 , int V_3 )
{
int V_4 ;
T_1 T_4 * V_5 = V_1 ;
const T_4 * V_6 = V_2 ;
if ( F_4 ( V_2 , 4 ) == V_2 && F_5 ( V_3 , 4 ) ) {
F_7 ( V_1 , V_2 , V_3 ) ;
return;
}
for ( V_4 = 0 ; V_4 < ( V_3 >> 1 ) ; V_4 ++ )
F_10 ( * V_6 ++ , V_5 ++ ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
T_5 V_9 ;
V_9 = F_12 ( V_10 ) ;
if ( ! ( V_9 & V_11 ) )
return 0 ;
V_9 &= ~ V_11 ;
F_13 ( V_9 , V_10 ) ;
return 1 ;
}
static int F_14 ( struct V_7 * V_8 )
{
T_5 V_9 ;
V_9 = F_15 ( V_12 ) ;
if ( ! ( V_9 & V_13 ) )
return 0 ;
if ( ! V_8 -> V_14 -> V_15 )
F_16 ( V_9 & ~ V_13 , V_12 ) ;
return 1 ;
}
static void F_17 ( struct V_7 * V_8 , int V_16 )
{
T_6 V_9 ;
V_9 = F_15 ( V_17 ) ;
if ( V_16 )
V_9 &= ~ V_18 ;
else
V_9 |= V_18 ;
F_16 ( V_9 , V_17 ) ;
}
static void F_18 ( struct V_7 * V_8 , int V_16 )
{
T_5 V_9 ;
V_9 = F_12 ( V_19 ) ;
if ( V_16 )
V_9 &= ~ V_20 ;
else
V_9 |= V_20 ;
F_13 ( V_9 , V_19 ) ;
}
static void F_19 ( struct V_7 * V_8 , int V_16 )
{
if ( V_8 -> V_14 -> V_15 ) {
if ( V_16 )
F_20 ( V_8 -> V_21 ) ;
else
F_21 ( V_8 -> V_21 ) ;
} else {
V_8 -> V_14 -> F_19 ( V_8 , V_16 ) ;
}
}
static T_3 F_22 ( struct V_7 * V_8 )
{
return F_15 ( V_22 ) ;
}
static T_3 F_23 ( struct V_7 * V_8 )
{
return F_12 ( V_22 ) ;
}
static T_3 F_24 ( struct V_7 * V_8 )
{
return F_12 ( V_23 ) ;
}
static T_7 F_25 ( int V_21 , void * V_24 )
{
struct V_7 * V_8 = V_24 ;
if ( ! V_8 -> V_14 -> V_25 ( V_8 ) )
return V_26 ;
F_19 ( V_8 , 0 ) ;
F_26 ( & V_8 -> V_27 ) ;
return V_28 ;
}
static int F_27 ( struct V_7 * V_8 , int V_29 )
{
int V_30 = 0 ;
if ( V_8 -> V_14 -> V_25 ( V_8 ) )
return 0 ;
if ( V_29 ) {
unsigned long V_31 ;
F_28 ( & V_8 -> V_27 ) ;
F_19 ( V_8 , 1 ) ;
V_31 = F_29 ( & V_8 -> V_27 , V_32 ) ;
if ( ! V_31 && ! V_8 -> V_14 -> V_25 ( V_8 ) ) {
F_30 ( V_8 -> V_33 , L_1 ) ;
V_30 = - V_34 ;
}
} else {
int V_35 = 8000 ;
int V_36 ;
do {
F_31 ( 1 ) ;
V_36 = V_8 -> V_14 -> V_25 ( V_8 ) ;
if ( V_36 )
break;
} while ( -- V_35 );
if ( ! V_36 ) {
F_30 ( V_8 -> V_33 , L_2 ) ;
V_30 = - V_34 ;
}
}
F_32 ( V_30 < 0 , L_3 , V_29 ) ;
return V_30 ;
}
static void F_33 ( struct V_7 * V_8 , T_6 V_37 , int V_29 )
{
F_13 ( V_37 , V_38 ) ;
F_13 ( V_39 , V_40 ) ;
F_27 ( V_8 , V_29 ) ;
}
static void F_34 ( struct V_7 * V_8 , T_6 V_37 , int V_29 )
{
F_35 ( L_4 , V_37 , V_29 ) ;
F_16 ( V_37 , V_41 ) ;
F_16 ( V_39 , V_12 ) ;
if ( V_8 -> V_14 -> V_15 && ( V_37 == V_42 ) ) {
int V_35 = 100 ;
while ( V_35 -- > 0 ) {
if ( F_15 ( V_12 ) == 0 ) {
break;
}
F_31 ( 1 ) ;
}
if ( V_35 < 0 )
F_35 ( L_5 , V_43 ) ;
} else {
F_27 ( V_8 , V_29 ) ;
}
}
static void F_36 ( struct V_7 * V_8 , T_6 V_44 , int V_45 )
{
F_13 ( V_44 , V_46 ) ;
F_13 ( V_47 , V_40 ) ;
F_27 ( V_8 , 0 ) ;
}
static void F_37 ( struct V_7 * V_8 , T_6 V_44 , int V_45 )
{
F_35 ( L_6 , V_44 , V_45 ) ;
F_16 ( V_44 , V_48 ) ;
F_16 ( V_47 , V_12 ) ;
F_27 ( V_8 , V_45 ) ;
}
static void F_38 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_5 V_9 ;
V_9 = F_12 ( V_53 ) ;
V_9 &= ~ ( 7 << 4 ) ;
F_13 ( V_9 , V_53 ) ;
F_13 ( V_51 , V_40 ) ;
F_27 ( V_8 , false ) ;
}
static void F_41 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
F_16 ( V_51 , V_12 ) ;
F_27 ( V_8 , true ) ;
}
static void F_42 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
int V_56 , V_4 ;
if ( V_50 -> V_57 > 512 )
V_56 = 4 ;
else
V_56 = 1 ;
for ( V_4 = 0 ; V_4 < V_56 ; V_4 ++ ) {
F_16 ( ( V_8 -> V_54 << 4 ) | V_4 , V_55 ) ;
F_16 ( V_51 , V_12 ) ;
F_27 ( V_8 , true ) ;
}
}
static void F_43 ( struct V_7 * V_8 )
{
F_13 ( V_58 , V_40 ) ;
F_27 ( V_8 , true ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 , 16 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
F_16 ( V_58 , V_12 ) ;
F_27 ( V_8 , true ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 , 16 ) ;
}
static T_6 F_45 ( struct V_7 * V_8 )
{
F_16 ( V_61 , V_40 ) ;
F_27 ( V_8 , true ) ;
return F_12 ( V_53 ) >> 16 ;
}
static T_6 F_46 ( struct V_7 * V_8 )
{
void T_1 * V_62 = V_8 -> V_60 ;
T_5 V_63 ;
T_6 V_30 ;
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
V_63 = F_12 ( V_62 ) ;
F_16 ( V_61 , V_12 ) ;
F_27 ( V_8 , true ) ;
V_30 = F_15 ( V_62 ) ;
F_13 ( V_63 , V_62 ) ;
return V_30 ;
}
static int F_47 ( struct V_49 * V_50 )
{
return 1 ;
}
static void F_48 ( struct V_49 * V_50 , int V_64 )
{
}
static int F_49 ( struct V_49 * V_50 , T_8 * V_65 ,
T_8 * V_66 , T_8 * V_67 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_68 = F_22 ( V_8 ) ;
if ( ( ( V_68 & 0x3 ) == 2 ) || ( ( V_68 >> 2 ) == 2 ) ) {
F_35 ( L_7 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_50 ( struct V_49 * V_50 , T_8 * V_65 ,
T_8 * V_66 , T_8 * V_67 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_3 V_70 , V_71 ;
int V_72 = 1 ;
int V_30 = 0 ;
T_9 V_73 , V_74 ;
V_73 = ( V_8 -> V_75 == 4 ) ? 0x7 : 0xf ;
V_74 = ( V_8 -> V_75 == 4 ) ? 0x4 : 0x8 ;
V_72 = V_50 -> V_57 >> 9 ;
V_70 = V_8 -> V_14 -> V_76 ( V_8 ) ;
do {
V_71 = V_70 & V_73 ;
if ( V_71 > V_74 ) {
F_51 ( V_77 L_8 ) ;
return - V_69 ;
} else {
V_30 += V_71 ;
}
V_70 >>= 4 ;
} while ( -- V_72 );
F_35 ( L_9 , V_30 ) ;
return V_30 ;
}
static int F_52 ( struct V_49 * V_50 , const T_8 * V_65 ,
T_8 * V_78 )
{
return 0 ;
}
static T_8 F_53 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_10 V_30 ;
if ( V_8 -> V_79 )
return V_8 -> V_14 -> V_80 ( V_8 ) & 0xFF ;
if ( V_52 -> V_81 & V_82 ) {
V_30 = * ( T_6 * ) ( V_8 -> V_59 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
} else {
V_30 = * ( T_10 * ) ( V_8 -> V_59 + V_8 -> V_83 ) ;
V_8 -> V_83 ++ ;
}
F_35 ( L_10 , V_43 , V_30 , V_8 -> V_83 ) ;
return V_30 ;
}
static T_6 F_54 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_30 ;
V_30 = * ( T_6 * ) ( V_8 -> V_59 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
return V_30 ;
}
static void F_55 ( struct V_49 * V_50 ,
const T_8 * V_84 , int V_85 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_4 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_57 - V_86 ;
V_87 = F_56 ( V_87 , V_85 ) ;
memcpy ( V_8 -> V_59 + V_86 , V_84 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_57 ( struct V_49 * V_50 , T_8 * V_84 , int V_85 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_4 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_57 - V_86 ;
V_87 = F_56 ( V_87 , V_85 ) ;
memcpy ( V_84 , V_8 -> V_59 + V_86 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_58 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_59 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_60 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
}
static void F_61 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_59 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_60 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
V_8 -> V_54 = V_89 ;
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
}
static void F_62 ( struct V_49 * V_50 , bool V_92 )
{
struct V_52 * V_93 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_93 ) ;
T_4 V_4 , V_94 ;
T_4 V_95 = V_50 -> V_57 / 512 ;
T_9 * V_96 = V_8 -> V_59 + V_50 -> V_57 ;
T_9 T_1 * V_6 = V_8 -> V_97 ;
T_4 V_98 = V_8 -> V_14 -> V_99 ;
V_94 = ( V_8 -> V_100 / V_95 ) & ~ 1 ;
if ( V_92 ) {
for ( V_4 = 0 ; V_4 < V_95 - 1 ; V_4 ++ )
F_3 ( V_96 + V_4 * V_94 ,
V_6 + V_4 * V_98 ,
V_94 ) ;
F_3 ( V_96 + V_4 * V_94 ,
V_6 + V_4 * V_98 ,
V_8 -> V_100 - V_4 * V_94 ) ;
} else {
for ( V_4 = 0 ; V_4 < V_95 - 1 ; V_4 ++ )
F_9 ( & V_6 [ V_4 * V_98 ] ,
& V_96 [ V_4 * V_94 ] ,
V_94 ) ;
F_9 ( & V_6 [ V_4 * V_98 ] ,
& V_96 [ V_4 * V_94 ] ,
V_8 -> V_100 - V_4 * V_94 ) ;
}
}
static void F_63 ( struct V_49 * V_50 , int V_101 , int V_102 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
if ( V_101 != - 1 ) {
V_8 -> V_14 -> V_103 ( V_8 , V_101 & 0xff ,
V_102 == - 1 ) ;
if ( V_50 -> V_57 > 512 )
V_8 -> V_14 -> V_103 ( V_8 ,
( V_101 >> 8 ) & 0xff ,
false ) ;
}
if ( V_102 != - 1 ) {
V_8 -> V_14 -> V_103 ( V_8 , ( V_102 & 0xff ) , false ) ;
if ( V_50 -> V_57 > 512 ) {
if ( V_50 -> V_3 >= 0x10000000 ) {
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff , true ) ;
} else {
if ( V_50 -> V_3 >= 0x4000000 ) {
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff , true ) ;
}
}
}
static int F_64 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
if ( V_104 >= V_52 -> V_107 . V_108 )
return - V_109 ;
V_106 -> V_110 = ( V_104 * 16 ) + 6 ;
V_106 -> V_111 = V_52 -> V_107 . V_112 ;
return 0 ;
}
static int F_65 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
if ( V_104 > V_52 -> V_107 . V_108 )
return - V_109 ;
if ( ! V_104 ) {
if ( V_50 -> V_57 <= 512 ) {
V_106 -> V_110 = 0 ;
V_106 -> V_111 = 5 ;
} else {
V_106 -> V_110 = 2 ;
V_106 -> V_111 = 4 ;
}
} else {
V_106 -> V_110 = ( ( V_104 - 1 ) * 16 ) +
V_52 -> V_107 . V_112 + 6 ;
if ( V_104 < V_52 -> V_107 . V_108 )
V_106 -> V_111 = ( V_104 * 16 ) + 6 -
V_106 -> V_110 ;
else
V_106 -> V_111 = V_50 -> V_88 - V_106 -> V_110 ;
}
return 0 ;
}
static int F_66 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
int V_113 = V_52 -> V_107 . V_112 == 9 ? 16 : 26 ;
if ( V_104 >= V_52 -> V_107 . V_108 )
return - V_109 ;
V_106 -> V_110 = ( V_104 * V_113 ) + 7 ;
V_106 -> V_111 = V_52 -> V_107 . V_112 ;
return 0 ;
}
static int F_67 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
int V_113 = V_52 -> V_107 . V_112 == 9 ? 16 : 26 ;
if ( V_104 > V_52 -> V_107 . V_108 )
return - V_109 ;
if ( ! V_104 ) {
if ( V_50 -> V_57 <= 512 ) {
V_106 -> V_110 = 0 ;
V_106 -> V_111 = 5 ;
} else {
V_106 -> V_110 = 2 ;
V_106 -> V_111 = 4 ;
}
} else {
V_106 -> V_110 = V_104 * V_113 ;
V_106 -> V_111 = 7 ;
}
return 0 ;
}
static int F_68 ( struct V_49 * V_50 )
{
int V_114 = 0 ;
V_114 = V_50 -> V_88 * 512 / V_50 -> V_57 ;
if ( V_114 < 26 )
return 4 ;
else
return 8 ;
}
static void F_69 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_115 = 0 ;
if ( V_52 -> V_107 . V_64 == V_116 && V_50 -> V_57 )
V_115 |= V_117 ;
if ( ! V_8 -> V_14 -> V_15 )
V_115 |= V_18 ;
V_8 -> V_75 = 1 ;
F_16 ( V_115 , V_17 ) ;
F_16 ( 0x2 , V_118 ) ;
F_16 ( 0x0 , V_119 ) ;
F_16 ( 0xffff , V_120 ) ;
F_16 ( 0x4 , V_121 ) ;
}
static void F_70 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_115 = 0 ;
V_115 |= V_122 ;
if ( ! V_8 -> V_14 -> V_15 )
V_115 |= V_18 ;
if ( V_50 -> V_57 ) {
T_6 V_123 = V_50 -> V_124 / V_50 -> V_57 ;
if ( V_52 -> V_107 . V_64 == V_116 )
V_115 |= V_117 ;
V_8 -> V_75 = F_68 ( V_50 ) ;
if ( V_8 -> V_75 == 4 )
V_115 |= V_125 ;
V_115 |= F_71 ( F_72 ( V_123 ) - 6 ) ;
} else {
V_8 -> V_75 = 1 ;
}
F_16 ( V_115 , V_17 ) ;
F_16 ( 0x2 , V_118 ) ;
F_16 ( 0x0 , V_126 ) ;
F_16 ( 0x0 , V_127 ) ;
F_16 ( 0x0 , V_128 ) ;
F_16 ( 0x0 , V_129 ) ;
F_16 ( 0xffff , V_130 ) ;
F_16 ( 0xffff , V_131 ) ;
F_16 ( 0xffff , V_132 ) ;
F_16 ( 0xffff , V_133 ) ;
F_16 ( 0x4 , V_121 ) ;
}
static void F_73 ( struct V_49 * V_50 )
{
struct V_52 * V_89 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_89 ) ;
T_5 V_134 , V_135 ;
int V_4 , V_136 ;
F_13 ( F_74 ( 0 ) , V_53 ) ;
F_13 ( V_137 , V_10 ) ;
F_13 ( V_138 | V_139 ,
V_140 ) ;
for ( V_4 = 0 ; V_4 < V_141 ; V_4 ++ )
F_13 ( 0xffff << 16 , V_142 + ( V_4 << 2 ) ) ;
F_13 ( 0 , V_10 ) ;
V_134 = V_143 |
V_144 |
F_75 ( V_50 -> V_88 >> 1 ) |
F_76 ( 0x70 ) |
V_20 |
V_145 ;
V_136 = F_77 ( V_89 -> V_146 ) >> 3 ;
if ( V_50 -> V_57 == 2048 ) {
V_134 |= V_147 ;
V_134 |= F_78 ( V_136 ) ;
} else if ( V_50 -> V_57 == 4096 ) {
V_134 |= V_148 ;
V_134 |= F_78 ( V_136 ) ;
} else {
V_134 |= V_149 ;
V_134 |= F_78 ( V_136 - 1 ) ;
}
if ( V_50 -> V_57 ) {
if ( V_89 -> V_107 . V_64 == V_116 )
V_134 |= V_150 ;
V_134 |= F_79 (
F_72 ( V_50 -> V_124 / V_50 -> V_57 ) - 6 ,
V_8 -> V_14 -> V_151 ) ;
V_8 -> V_75 = F_68 ( V_50 ) ;
if ( V_8 -> V_75 == 8 )
V_134 |= V_152 ;
}
F_13 ( V_134 , V_19 ) ;
V_135 = F_80 ( 0 ) |
V_153 |
V_154 |
F_81 ( 6 ) |
F_82 ( 0 ) ;
if ( ! ( V_89 -> V_81 & V_82 ) )
V_135 |= V_155 ;
F_13 ( V_135 , V_156 ) ;
F_13 ( 0 , V_157 ) ;
}
static void F_83 ( struct V_49 * V_50 , unsigned V_158 ,
int V_101 , int V_102 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
F_35 ( L_11 ,
V_158 , V_101 , V_102 ) ;
V_8 -> V_79 = false ;
switch ( V_158 ) {
case V_42 :
V_8 -> V_14 -> V_159 ( V_50 ) ;
V_8 -> V_14 -> V_160 ( V_8 , V_158 , false ) ;
break;
case V_161 :
V_8 -> V_83 = 0 ;
V_8 -> V_79 = true ;
V_8 -> V_14 -> V_160 ( V_8 , V_158 , true ) ;
F_32 ( V_101 != - 1 || V_102 != - 1 ,
L_12 ,
V_158 , V_101 , V_102 ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
break;
case V_162 :
case V_163 :
if ( V_158 == V_162 )
V_8 -> V_83 = V_101 ;
else
V_8 -> V_83 = V_101 + V_50 -> V_57 ;
V_158 = V_162 ;
V_8 -> V_14 -> V_160 ( V_8 , V_158 , false ) ;
F_32 ( V_101 < 0 ,
L_12 ,
V_158 , V_101 , V_102 ) ;
F_63 ( V_50 , 0 , V_102 ) ;
if ( V_50 -> V_57 > 512 )
V_8 -> V_14 -> V_160 ( V_8 ,
V_164 , true ) ;
V_8 -> V_14 -> V_165 ( V_50 , V_166 ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 ,
V_50 -> V_57 ) ;
F_62 ( V_50 , true ) ;
break;
case V_167 :
if ( V_101 >= V_50 -> V_57 )
F_83 ( V_50 , V_162 , 0 , V_102 ) ;
V_8 -> V_83 = V_101 ;
V_8 -> V_14 -> V_160 ( V_8 , V_158 , false ) ;
F_32 ( V_101 < - 1 ,
L_12 ,
V_158 , V_101 , V_102 ) ;
F_63 ( V_50 , 0 , V_102 ) ;
break;
case V_168 :
F_7 ( V_8 -> V_60 , V_8 -> V_59 , V_50 -> V_57 ) ;
F_62 ( V_50 , false ) ;
V_8 -> V_14 -> V_165 ( V_50 , V_169 ) ;
V_8 -> V_14 -> V_160 ( V_8 , V_158 , true ) ;
F_32 ( V_101 != - 1 || V_102 != - 1 ,
L_12 ,
V_158 , V_101 , V_102 ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
break;
case V_170 :
V_8 -> V_14 -> V_160 ( V_8 , V_158 , true ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
V_8 -> V_14 -> V_171 ( V_8 ) ;
V_8 -> V_83 = 0 ;
break;
case V_172 :
case V_173 :
V_8 -> V_14 -> V_160 ( V_8 , V_158 , false ) ;
F_32 ( V_101 != - 1 ,
L_13 ,
V_158 , V_101 ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
break;
case V_174 :
V_8 -> V_14 -> V_160 ( V_8 , V_158 , false ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
V_8 -> V_14 -> V_165 ( V_50 , V_166 ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 , 512 ) ;
V_8 -> V_83 = 0 ;
break;
default:
F_32 ( 1 , L_14 ,
V_158 ) ;
break;
}
}
static inline int F_84 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_175 ;
}
static inline int F_85 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_176 ;
}
static inline int F_86 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_177 ;
}
static inline int F_87 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_178 ;
}
static inline int F_88 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_179 ;
}
static int T_11 F_89 ( struct V_7 * V_8 )
{
struct V_180 * V_181 = V_8 -> V_33 -> V_182 ;
const struct V_183 * V_184 =
F_90 ( V_185 , V_8 -> V_33 ) ;
if ( ! V_181 )
return 1 ;
V_8 -> V_14 = V_184 -> V_186 ;
return 0 ;
}
static int T_11 F_89 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_91 ( struct V_187 * V_188 )
{
struct V_52 * V_93 ;
struct V_49 * V_50 ;
struct V_7 * V_8 ;
struct V_189 * V_190 ;
int V_71 = 0 ;
V_8 = F_92 ( & V_188 -> V_33 , sizeof( struct V_7 ) ,
V_191 ) ;
if ( ! V_8 )
return - V_192 ;
V_8 -> V_59 = F_92 ( & V_188 -> V_33 , V_193 , V_191 ) ;
if ( ! V_8 -> V_59 )
return - V_192 ;
V_8 -> V_33 = & V_188 -> V_33 ;
V_93 = & V_8 -> V_194 ;
V_50 = F_93 ( V_93 ) ;
V_50 -> V_33 . V_195 = & V_188 -> V_33 ;
V_50 -> V_196 = V_197 ;
V_93 -> V_198 = 5 ;
F_94 ( V_93 , V_8 ) ;
F_95 ( V_93 , V_188 -> V_33 . V_182 ) ,
V_93 -> V_199 = F_47 ;
V_93 -> V_200 = F_83 ;
V_93 -> V_201 = F_53 ;
V_93 -> V_202 = F_54 ;
V_93 -> V_203 = F_55 ;
V_93 -> V_204 = F_57 ;
V_8 -> V_91 = F_96 ( & V_188 -> V_33 , NULL ) ;
if ( F_97 ( V_8 -> V_91 ) )
return F_98 ( V_8 -> V_91 ) ;
V_71 = F_89 ( V_8 ) ;
if ( V_71 > 0 ) {
struct V_205 * V_206 =
F_99 ( & V_188 -> V_33 ) ;
if ( V_206 ) {
V_8 -> V_206 = * V_206 ;
V_8 -> V_14 = (struct V_207 * )
V_188 -> V_208 -> V_209 ;
} else {
V_71 = - V_210 ;
}
}
if ( V_71 < 0 )
return V_71 ;
if ( V_8 -> V_14 -> V_211 ) {
V_190 = F_100 ( V_188 , V_212 , 0 ) ;
V_8 -> V_213 = F_101 ( & V_188 -> V_33 , V_190 ) ;
if ( F_97 ( V_8 -> V_213 ) )
return F_98 ( V_8 -> V_213 ) ;
V_190 = F_100 ( V_188 , V_212 , 1 ) ;
} else {
V_190 = F_100 ( V_188 , V_212 , 0 ) ;
}
V_8 -> V_214 = F_101 ( & V_188 -> V_33 , V_190 ) ;
if ( F_97 ( V_8 -> V_214 ) )
return F_98 ( V_8 -> V_214 ) ;
V_8 -> V_60 = V_8 -> V_214 ;
if ( V_8 -> V_14 -> V_215 )
V_8 -> V_216 = V_8 -> V_214 + V_8 -> V_14 -> V_215 ;
V_8 -> V_97 = V_8 -> V_214 + V_8 -> V_14 -> V_217 ;
if ( V_8 -> V_14 -> V_218 )
V_8 -> V_219 = V_8 -> V_214 + V_8 -> V_14 -> V_218 ;
V_93 -> V_107 . V_112 = V_8 -> V_14 -> V_220 ;
V_8 -> V_75 = V_8 -> V_14 -> V_75 ;
V_93 -> V_221 = V_8 -> V_14 -> V_221 ;
V_93 -> V_107 . V_3 = 512 ;
F_102 ( V_50 , V_8 -> V_14 -> V_222 ) ;
if ( V_8 -> V_206 . V_223 ) {
V_93 -> V_107 . V_64 = V_116 ;
} else {
V_93 -> V_107 . V_64 = V_224 ;
V_93 -> V_107 . V_225 = V_226 ;
}
if ( V_8 -> V_206 . V_227 == 2 )
V_93 -> V_81 |= V_82 ;
if ( V_8 -> V_206 . V_228 )
V_93 -> V_229 |= V_230 ;
F_103 ( & V_8 -> V_27 ) ;
V_8 -> V_21 = F_104 ( V_188 , 0 ) ;
if ( V_8 -> V_21 < 0 )
return V_8 -> V_21 ;
V_8 -> V_14 -> F_19 ( V_8 , 0 ) ;
V_71 = F_105 ( & V_188 -> V_33 , V_8 -> V_21 , F_25 ,
0 , V_197 , V_8 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_60 ( V_8 -> V_91 ) ;
if ( V_71 )
return V_71 ;
V_8 -> V_90 = 1 ;
if ( V_8 -> V_14 -> V_15 ) {
F_21 ( V_8 -> V_21 ) ;
V_8 -> V_14 -> F_19 ( V_8 , 1 ) ;
}
if ( F_106 ( V_50 , F_86 ( V_8 ) ? 4 : 1 , NULL ) ) {
V_71 = - V_231 ;
goto V_232;
}
switch ( V_93 -> V_107 . V_64 ) {
case V_116 :
V_93 -> V_107 . V_233 = F_52 ;
V_93 -> V_107 . V_234 = F_48 ;
V_93 -> V_107 . V_235 = V_8 -> V_14 -> V_236 ;
break;
case V_224 :
break;
default:
V_71 = - V_237 ;
goto V_232;
}
if ( V_93 -> V_229 & V_230 ) {
V_93 -> V_238 = & V_239 ;
V_93 -> V_240 = & V_241 ;
}
F_107 ( & V_188 -> V_33 , ( void * ) V_8 -> V_59 ) ;
V_8 -> V_59 = F_92 ( & V_188 -> V_33 , V_50 -> V_57 + V_50 -> V_88 ,
V_191 ) ;
if ( ! V_8 -> V_59 ) {
V_71 = - V_192 ;
goto V_232;
}
V_8 -> V_14 -> V_159 ( V_50 ) ;
if ( ! V_93 -> V_107 . V_112 ) {
if ( V_8 -> V_75 == 8 )
V_93 -> V_107 . V_112 = 18 ;
else if ( V_8 -> V_75 == 4 )
V_93 -> V_107 . V_112 = 9 ;
}
V_8 -> V_100 = F_56 ( V_50 -> V_88 , 218U ) ;
if ( V_93 -> V_107 . V_64 == V_116 ) {
if ( F_84 ( V_8 ) || F_85 ( V_8 ) )
V_93 -> V_107 . V_242 = 1 ;
else
V_93 -> V_107 . V_242 = ( V_8 -> V_75 == 4 ) ? 4 : 8 ;
}
if ( F_108 ( V_50 ) ) {
V_71 = - V_231 ;
goto V_232;
}
F_109 ( V_50 , V_243 ,
NULL ,
V_8 -> V_206 . V_244 ,
V_8 -> V_206 . V_245 ) ;
F_110 ( V_188 , V_8 ) ;
return 0 ;
V_232:
if ( V_8 -> V_90 )
F_59 ( V_8 -> V_91 ) ;
return V_71 ;
}
static int F_111 ( struct V_187 * V_188 )
{
struct V_7 * V_8 = F_112 ( V_188 ) ;
F_113 ( F_93 ( & V_8 -> V_194 ) ) ;
if ( V_8 -> V_90 )
F_59 ( V_8 -> V_91 ) ;
return 0 ;
}
