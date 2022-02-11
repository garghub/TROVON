static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
V_4 = V_3 -> V_6 ;
if ( V_4 != NULL )
F_3 ( & V_4 -> V_7 ) ;
F_4 ( & V_5 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_4 )
{
if ( F_6 ( & V_4 -> V_7 ) )
F_7 ( & V_4 -> V_8 ) ;
}
static int
F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_9 ;
int V_10 ;
if ( V_3 -> V_11 -> V_12 == NULL )
return - V_13 ;
V_9 = - V_14 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_15 ) ;
if ( ! V_4 )
goto V_16;
V_4 -> V_3 = V_3 ;
V_4 -> V_17 = V_18 ;
F_10 ( & V_4 -> V_19 ) ;
F_10 ( & V_4 -> V_20 ) ;
V_4 -> V_21 [ 0 ] = ~ 0U ;
V_4 -> V_21 [ 3 ] = 0x60000000U ;
V_4 -> V_22 = ~ 0U ;
V_4 -> V_23 = V_4 -> V_24 ;
V_4 -> V_25 = V_4 -> V_24 ;
V_4 -> V_26 = - 1 ;
F_11 ( & V_4 -> V_27 ) ;
F_12 ( & V_4 -> V_28 , V_29 , ( unsigned long ) V_4 ) ;
F_13 ( & V_4 -> V_7 , 1 ) ;
F_14 ( & V_4 -> V_8 , 0 ) ;
V_4 -> V_30 . V_31 = V_4 ;
V_4 -> V_30 . V_11 = & V_32 ;
V_4 -> V_30 . V_33 = V_18 ;
V_10 = F_15 ( V_3 ) ;
V_4 -> V_30 . V_10 = V_10 ;
V_9 = F_16 ( & V_4 -> V_30 ) ;
if ( V_9 )
goto V_34;
V_3 -> V_6 = V_4 ;
V_3 -> V_35 = 65536 ;
return 0 ;
V_34:
F_17 ( V_4 ) ;
V_16:
return V_9 ;
}
static void
F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_19 ( & V_5 ) ;
V_4 = V_3 -> V_6 ;
V_3 -> V_6 = NULL ;
F_20 ( & V_5 ) ;
if ( ! V_4 )
return;
if ( ! F_6 ( & V_4 -> V_7 ) )
F_21 ( & V_4 -> V_8 ) ;
F_22 ( & V_4 -> V_28 ) ;
F_23 ( & V_4 -> V_30 ) ;
F_24 ( V_4 -> V_36 ) ;
F_25 ( & V_4 -> V_27 ) ;
F_24 ( V_4 -> V_37 ) ;
F_17 ( V_4 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
F_18 ( V_3 ) ;
return 0 ;
}
static T_1
F_27 ( struct V_2 * V_3 , struct V_38 * V_38 ,
unsigned char T_2 * V_39 , T_3 V_40 )
{
return - V_41 ;
}
static T_1
F_28 ( struct V_2 * V_3 , struct V_38 * V_38 ,
const unsigned char * V_39 , T_3 V_40 )
{
return - V_41 ;
}
static int
F_29 ( struct V_2 * V_3 , struct V_38 * V_38 ,
unsigned int V_42 , unsigned long V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_9 , V_44 ;
int T_2 * V_45 = ( int T_2 * ) V_43 ;
if ( ! V_4 )
return - V_46 ;
V_9 = - V_47 ;
switch ( V_42 ) {
case V_48 :
V_9 = - V_47 ;
if ( F_30 ( F_31 ( & V_4 -> V_30 ) , V_45 ) )
break;
V_9 = 0 ;
break;
case V_49 :
V_9 = - V_47 ;
if ( F_30 ( F_32 ( & V_4 -> V_30 ) , V_45 ) )
break;
V_9 = 0 ;
break;
case V_50 :
if ( V_43 == V_51 || V_43 == V_52 )
F_33 ( V_4 ) ;
V_9 = F_34 ( V_3 , V_38 , V_42 , V_43 ) ;
break;
case V_53 :
V_44 = 0 ;
if ( F_30 ( V_44 , V_45 ) )
break;
V_9 = 0 ;
break;
default:
V_9 = F_35 ( V_3 , V_38 , V_42 , V_43 ) ;
}
F_5 ( V_4 ) ;
return V_9 ;
}
static unsigned int
F_36 ( struct V_2 * V_3 , struct V_38 * V_38 , T_4 * V_54 )
{
return 0 ;
}
static void
F_37 ( struct V_2 * V_3 , const unsigned char * V_39 ,
char * V_55 , int V_40 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_56 ;
if ( ! V_4 )
return;
F_38 ( & V_4 -> V_20 , V_56 ) ;
F_39 ( V_4 , V_39 , V_55 , V_40 ) ;
F_40 ( & V_4 -> V_20 , V_56 ) ;
if ( ! F_41 ( & V_4 -> V_27 ) )
F_42 ( & V_4 -> V_28 ) ;
F_5 ( V_4 ) ;
F_43 ( V_3 ) ;
}
static void
F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_45 ( V_57 , & V_3 -> V_56 ) ;
if ( ! V_4 )
return;
F_46 ( V_58 , & V_4 -> V_59 ) ;
F_42 ( & V_4 -> V_28 ) ;
F_5 ( V_4 ) ;
}
static int T_5
F_47 ( void )
{
int V_9 ;
V_9 = F_48 ( V_60 , & V_61 ) ;
if ( V_9 != 0 )
F_49 ( V_62 L_1 ,
V_9 ) ;
return V_9 ;
}
static int
F_50 ( struct V_63 * V_30 , unsigned int V_42 , unsigned long V_43 )
{
struct V_1 * V_4 = V_30 -> V_31 ;
void T_2 * V_64 = ( void T_2 * ) V_43 ;
int T_2 * V_45 = V_64 ;
int V_9 , V_44 ;
T_6 V_65 [ 8 ] ;
V_9 = - V_47 ;
switch ( V_42 ) {
case V_66 :
V_44 = V_4 -> V_56 | V_4 -> V_67 ;
if ( F_30 ( V_44 , V_45 ) )
break;
V_9 = 0 ;
break;
case V_68 :
if ( F_51 ( V_44 , V_45 ) )
break;
V_4 -> V_56 = V_44 & ~ V_69 ;
F_52 ( & V_4 -> V_20 ) ;
V_4 -> V_67 = V_44 & V_69 ;
F_53 ( & V_4 -> V_20 ) ;
V_9 = 0 ;
break;
case V_70 :
if ( F_30 ( V_4 -> V_21 [ 0 ] , ( T_6 T_2 * ) V_64 ) )
break;
V_9 = 0 ;
break;
case V_71 :
if ( F_51 ( V_4 -> V_21 [ 0 ] , ( T_6 T_2 * ) V_64 ) )
break;
V_9 = 0 ;
break;
case V_72 :
if ( F_30 ( V_4 -> V_22 , ( T_6 T_2 * ) V_64 ) )
break;
V_9 = 0 ;
break;
case V_73 :
if ( F_51 ( V_4 -> V_22 , ( T_6 T_2 * ) V_64 ) )
break;
V_9 = 0 ;
break;
case V_74 :
if ( F_54 ( V_64 , V_4 -> V_21 , sizeof( V_4 -> V_21 ) ) )
break;
V_9 = 0 ;
break;
case V_75 :
if ( F_55 ( V_65 , V_64 , sizeof( V_65 ) ) )
break;
V_65 [ 2 ] &= ~ 0x40000000U ;
V_65 [ 3 ] |= 0x60000000U ;
memcpy ( V_4 -> V_21 , V_65 , sizeof( V_4 -> V_21 ) ) ;
V_9 = 0 ;
break;
case V_76 :
if ( F_30 ( V_4 -> V_17 , V_45 ) )
break;
V_9 = 0 ;
break;
case V_77 :
if ( F_51 ( V_44 , V_45 ) )
break;
if ( V_44 < V_18 )
V_44 = V_18 ;
V_4 -> V_17 = V_44 ;
V_9 = 0 ;
break;
default:
V_9 = - V_78 ;
}
return V_9 ;
}
static void V_29 ( unsigned long V_43 )
{
struct V_1 * V_4 = (struct V_1 * ) V_43 ;
struct V_79 * V_80 ;
while ( ( V_80 = F_56 ( & V_4 -> V_27 ) ) != NULL ) {
if ( V_80 -> V_81 [ 0 ] )
F_57 ( & V_4 -> V_30 , 0 ) ;
F_58 ( & V_4 -> V_30 , V_80 ) ;
}
if ( F_59 ( V_58 , & V_4 -> V_59 ) && F_60 ( V_4 ) )
F_61 ( & V_4 -> V_30 ) ;
}
static int
F_62 ( struct V_1 * V_4 )
{
int V_82 , V_83 , V_40 , V_84 , V_85 ;
unsigned char * V_39 , * V_86 ;
unsigned char * V_87 ;
int V_88 ;
V_39 = V_4 -> V_24 ;
V_4 -> V_25 = V_39 ;
V_4 -> V_23 = V_39 ;
V_83 = V_4 -> V_89 ;
V_87 = V_4 -> V_37 -> V_87 ;
V_40 = V_4 -> V_37 -> V_90 ;
V_82 = V_4 -> V_91 ;
V_85 = F_63 ( V_87 ) ;
V_88 = V_85 == V_92 && 1 <= V_87 [ 2 ] && V_87 [ 2 ] <= 7 ;
if ( V_83 == 0 ) {
if ( V_88 )
F_64 ( V_4 , V_87 , V_40 , 0 ) ;
if ( V_88 || V_93 == 0 ||
F_65 ( V_94 , V_4 -> V_95 + V_93 ) )
* V_39 ++ = V_96 ;
V_4 -> V_95 = V_94 ;
V_82 = V_97 ;
if ( ( V_4 -> V_56 & V_98 ) == 0 || V_88 ) {
F_66 ( V_4 , V_39 , 0xff , V_88 ) ;
V_82 = F_67 ( V_82 , 0xff ) ;
F_66 ( V_4 , V_39 , 0x03 , V_88 ) ;
V_82 = F_67 ( V_82 , 0x03 ) ;
}
}
V_86 = V_4 -> V_24 + V_99 - 6 ;
while ( V_83 < V_40 && V_39 < V_86 ) {
V_84 = V_87 [ V_83 ++ ] ;
if ( V_83 == 1 && V_84 == 0 && ( V_4 -> V_56 & V_100 ) )
continue;
V_82 = F_67 ( V_82 , V_84 ) ;
F_66 ( V_4 , V_39 , V_84 , V_88 ) ;
}
if ( V_83 < V_40 ) {
V_4 -> V_25 = V_39 ;
V_4 -> V_89 = V_83 ;
V_4 -> V_91 = V_82 ;
return 0 ;
}
V_82 = ~ V_82 ;
V_84 = V_82 & 0xff ;
F_66 ( V_4 , V_39 , V_84 , V_88 ) ;
V_84 = ( V_82 >> 8 ) & 0xff ;
F_66 ( V_4 , V_39 , V_84 , V_88 ) ;
* V_39 ++ = V_96 ;
V_4 -> V_25 = V_39 ;
F_68 ( V_4 -> V_37 ) ;
V_4 -> V_37 = NULL ;
return 1 ;
}
static int
F_69 ( struct V_63 * V_30 , struct V_79 * V_80 )
{
struct V_1 * V_4 = V_30 -> V_31 ;
F_60 ( V_4 ) ;
if ( F_70 ( V_101 , & V_4 -> V_59 ) )
return 0 ;
V_4 -> V_37 = V_80 ;
V_4 -> V_89 = 0 ;
F_60 ( V_4 ) ;
return 1 ;
}
static int
F_60 ( struct V_1 * V_4 )
{
int V_102 , V_103 , V_104 = 0 ;
struct V_2 * V_3 = V_4 -> V_3 ;
int V_105 = 0 ;
if ( F_70 ( V_106 , & V_4 -> V_59 ) )
return 0 ;
F_71 ( & V_4 -> V_19 ) ;
for (; ; ) {
if ( F_72 ( V_58 , & V_4 -> V_59 ) )
V_105 = 0 ;
if ( ! V_105 && V_4 -> V_23 < V_4 -> V_25 ) {
V_102 = V_4 -> V_25 - V_4 -> V_23 ;
F_46 ( V_57 , & V_3 -> V_56 ) ;
V_103 = V_3 -> V_11 -> V_12 ( V_3 , V_4 -> V_23 , V_102 ) ;
if ( V_103 < 0 )
goto V_107;
V_4 -> V_23 += V_103 ;
if ( V_103 < V_102 )
V_105 = 1 ;
continue;
}
if ( V_4 -> V_23 >= V_4 -> V_25 && V_4 -> V_37 ) {
if ( F_62 ( V_4 ) ) {
F_45 ( V_101 , & V_4 -> V_59 ) ;
V_104 = 1 ;
}
continue;
}
F_45 ( V_106 , & V_4 -> V_59 ) ;
if ( ! ( F_59 ( V_58 , & V_4 -> V_59 ) ||
( ! V_105 && V_4 -> V_37 ) ) )
break;
if ( F_70 ( V_106 , & V_4 -> V_59 ) )
break;
}
F_73 ( & V_4 -> V_19 ) ;
return V_104 ;
V_107:
F_45 ( V_106 , & V_4 -> V_59 ) ;
if ( V_4 -> V_37 ) {
F_24 ( V_4 -> V_37 ) ;
V_4 -> V_37 = NULL ;
F_45 ( V_101 , & V_4 -> V_59 ) ;
V_104 = 1 ;
}
V_4 -> V_23 = V_4 -> V_25 ;
F_73 ( & V_4 -> V_19 ) ;
return V_104 ;
}
static void
F_33 ( struct V_1 * V_4 )
{
int V_104 = 0 ;
F_71 ( & V_4 -> V_19 ) ;
V_4 -> V_23 = V_4 -> V_25 ;
if ( V_4 -> V_37 != NULL ) {
F_24 ( V_4 -> V_37 ) ;
V_4 -> V_37 = NULL ;
F_45 ( V_101 , & V_4 -> V_59 ) ;
V_104 = 1 ;
}
F_73 ( & V_4 -> V_19 ) ;
if ( V_104 )
F_61 ( & V_4 -> V_30 ) ;
}
static inline int
F_74 ( struct V_1 * V_4 , const unsigned char * V_39 , int V_40 )
{
int V_83 , V_84 ;
for ( V_83 = 0 ; V_83 < V_40 ; ++ V_83 ) {
V_84 = V_39 [ V_83 ] ;
if ( V_84 == V_108 || V_84 == V_96 ||
( V_84 < 0x20 && ( V_4 -> V_22 & ( 1 << V_84 ) ) != 0 ) )
break;
}
return V_83 ;
}
static void
F_75 ( struct V_1 * V_4 )
{
struct V_79 * V_80 ;
unsigned char * V_45 ;
unsigned int V_90 , V_82 , V_85 ;
V_80 = V_4 -> V_36 ;
if ( V_4 -> V_109 & ( V_110 | V_111 ) )
goto V_9;
if ( V_80 == NULL )
return;
V_45 = V_80 -> V_87 ;
V_90 = V_80 -> V_90 ;
if ( V_90 < 3 )
goto V_9;
V_82 = V_97 ;
for (; V_90 > 0 ; -- V_90 )
V_82 = F_67 ( V_82 , * V_45 ++ ) ;
if ( V_82 != V_112 )
goto V_9;
F_76 ( V_80 , V_80 -> V_90 - 2 ) ;
V_45 = V_80 -> V_87 ;
if ( V_45 [ 0 ] == V_113 ) {
if ( V_45 [ 1 ] != V_114 || V_80 -> V_90 < 3 )
goto V_9;
V_45 = F_77 ( V_80 , 2 ) ;
}
V_85 = V_45 [ 0 ] ;
if ( V_85 & 1 ) {
* ( V_115 * ) F_78 ( V_80 , 1 ) = 0 ;
} else {
if ( V_80 -> V_90 < 2 )
goto V_9;
V_85 = ( V_85 << 8 ) + V_45 [ 1 ] ;
if ( V_85 == V_92 )
F_64 ( V_4 , V_45 , V_80 -> V_90 , 1 ) ;
}
V_80 -> V_81 [ 0 ] = V_4 -> V_109 ;
F_79 ( & V_4 -> V_27 , V_80 ) ;
V_4 -> V_36 = NULL ;
V_4 -> V_109 = 0 ;
return;
V_9:
V_4 -> V_109 = V_116 ;
if ( V_80 ) {
F_76 ( V_80 , 0 ) ;
F_80 ( V_80 , - F_81 ( V_80 ) ) ;
}
}
static void
F_39 ( struct V_1 * V_4 , const unsigned char * V_39 ,
char * V_56 , int V_40 )
{
struct V_79 * V_80 ;
int V_84 , V_83 , V_117 , V_118 , V_119 , V_120 ;
unsigned char * V_121 ;
if ( ~ V_4 -> V_67 & V_69 ) {
V_119 = 0 ;
for ( V_83 = 0 ; V_83 < V_40 ; ++ V_83 ) {
V_84 = V_39 [ V_83 ] ;
if ( V_56 && V_56 [ V_83 ] != 0 )
continue;
V_119 |= ( V_84 & 0x80 ) ? V_122 : V_123 ;
V_84 = ( ( V_84 >> 4 ) ^ V_84 ) & 0xf ;
V_119 |= ( 0x6996 & ( 1 << V_84 ) ) ? V_124 : V_125 ;
}
V_4 -> V_67 |= V_119 ;
}
while ( V_40 > 0 ) {
if ( ( V_4 -> V_109 & V_111 ) && V_39 [ 0 ] == V_108 )
V_118 = 1 ;
else
V_118 = F_74 ( V_4 , V_39 , V_40 ) ;
V_120 = 0 ;
if ( V_56 && ( V_4 -> V_109 & V_110 ) == 0 ) {
for ( V_117 = 0 ; V_117 < V_118 ; ++ V_117 )
if ( ( V_120 = V_56 [ V_117 ] ) != 0 )
break;
}
if ( V_120 != 0 ) {
V_4 -> V_109 |= V_110 ;
} else if ( V_118 > 0 && ( V_4 -> V_109 & V_110 ) == 0 ) {
V_80 = V_4 -> V_36 ;
if ( ! V_80 ) {
V_80 = F_82 ( V_4 -> V_17 + V_126 + 2 ) ;
if ( ! V_80 )
goto V_127;
V_4 -> V_36 = V_80 ;
}
if ( V_80 -> V_90 == 0 ) {
if ( V_39 [ 0 ] != V_113 )
F_80 ( V_80 , 2 + ( V_39 [ 0 ] & 1 ) ) ;
}
if ( V_118 > F_83 ( V_80 ) ) {
V_4 -> V_109 |= V_110 ;
} else {
V_121 = F_84 ( V_80 , V_39 , V_118 ) ;
if ( V_4 -> V_109 & V_111 ) {
V_121 [ 0 ] ^= V_128 ;
V_4 -> V_109 &= ~ V_111 ;
}
}
}
if ( V_118 >= V_40 )
break;
V_84 = V_39 [ V_118 ] ;
if ( V_56 != NULL && V_56 [ V_118 ] != 0 ) {
V_4 -> V_109 |= V_110 ;
} else if ( V_84 == V_96 ) {
F_75 ( V_4 ) ;
} else if ( V_84 == V_108 ) {
V_4 -> V_109 |= V_111 ;
} else if ( F_85 ( V_4 -> V_3 ) ) {
if ( V_84 == F_86 ( V_4 -> V_3 ) )
F_87 ( V_4 -> V_3 ) ;
else if ( V_84 == F_88 ( V_4 -> V_3 ) )
F_89 ( V_4 -> V_3 ) ;
}
++ V_118 ;
V_39 += V_118 ;
if ( V_56 )
V_56 += V_118 ;
V_40 -= V_118 ;
}
return;
V_127:
F_49 ( V_62 L_2 ) ;
V_4 -> V_109 |= V_110 ;
}
static void F_64 ( struct V_1 * V_4 , unsigned char * V_87 ,
int V_90 , int V_129 )
{
int V_130 , V_82 , V_83 , V_131 ;
T_6 V_44 ;
V_87 += 2 ;
V_90 -= 2 ;
if ( V_90 < 4 )
return;
V_131 = V_87 [ 0 ] ;
if ( V_131 != V_132 && V_131 != V_133 )
return;
V_130 = F_63 ( V_87 + 2 ) ;
if ( V_90 < V_130 )
return;
if ( V_131 == ( V_129 ? V_132 : V_133 ) ) {
V_82 = V_97 ;
for ( V_83 = 1 ; V_83 < V_130 ; ++ V_83 )
V_82 = F_67 ( V_82 , V_87 [ V_83 ] ) ;
if ( ! V_129 ) {
V_4 -> V_26 = V_82 ;
return;
}
V_82 ^= V_4 -> V_26 ;
V_4 -> V_26 = - 1 ;
if ( V_82 != 0 )
return;
} else if ( V_129 )
return;
V_87 += 4 ;
V_130 -= 4 ;
while ( V_130 >= 2 && V_130 >= V_87 [ 1 ] && V_87 [ 1 ] >= 2 ) {
switch ( V_87 [ 0 ] ) {
case V_134 :
V_44 = F_63 ( V_87 + 2 ) ;
if ( V_129 )
V_4 -> V_17 = V_44 ;
else
V_4 -> V_30 . V_33 = V_44 ;
break;
case V_135 :
V_44 = F_90 ( V_87 + 2 ) ;
if ( V_129 )
V_4 -> V_22 = V_44 ;
else
V_4 -> V_21 [ 0 ] = V_44 ;
break;
}
V_130 -= V_87 [ 1 ] ;
V_87 += V_87 [ 1 ] ;
}
}
static void T_7 F_91 ( void )
{
if ( F_92 ( V_60 ) != 0 )
F_49 ( V_62 L_3 ) ;
}
