static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = - V_5 ;
unsigned long V_6 ;
char * V_7 = NULL ;
char * V_8 = NULL ;
#ifdef F_2
char * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
#endif
V_6 = V_3 * 2 ;
if ( V_6 < 576 * 2 )
V_6 = 576 * 2 ;
V_7 = F_3 ( V_6 + 4 , V_12 ) ;
if ( V_7 == NULL )
goto V_13;
V_8 = F_3 ( V_6 + 4 , V_12 ) ;
if ( V_8 == NULL )
goto V_13;
#ifdef F_2
V_9 = F_3 ( V_6 + 4 , V_12 ) ;
if ( V_9 == NULL )
goto V_13;
V_11 = F_4 ( 16 , 16 ) ;
if ( V_11 == NULL )
goto V_13;
#endif
F_5 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL ) {
F_6 ( & V_2 -> V_14 ) ;
V_4 = - V_16 ;
goto V_13;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_17 = V_6 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_7 = F_7 ( & V_2 -> V_7 , V_7 ) ;
V_8 = F_7 ( & V_2 -> V_8 , V_8 ) ;
#ifdef F_2
V_9 = F_7 ( & V_2 -> V_9 , V_9 ) ;
V_11 = F_7 ( & V_2 -> V_11 , V_11 ) ;
#endif
#ifdef F_8
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
#endif
F_6 ( & V_2 -> V_14 ) ;
V_4 = 0 ;
V_13:
#ifdef F_2
F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
#endif
F_9 ( V_8 ) ;
F_9 ( V_7 ) ;
return V_4 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_9 ( F_7 ( & V_2 -> V_7 , NULL ) ) ;
F_9 ( F_7 ( & V_2 -> V_8 , NULL ) ) ;
#ifdef F_2
F_9 ( F_7 ( & V_2 -> V_9 , NULL ) ) ;
F_10 ( F_7 ( & V_2 -> V_11 , NULL ) ) ;
#endif
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_22 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_23 * V_22 = V_2 -> V_22 ;
struct V_24 * V_25 ;
int V_26 ;
V_26 = V_2 -> V_18 ;
#ifdef F_2
if ( V_2 -> V_27 & ( V_28 | V_29 ) ) {
unsigned char V_30 = V_2 -> V_7 [ 0 ] ;
if ( V_30 & V_31 ) {
if ( ! ( V_2 -> V_27 & V_29 ) ) {
F_17 ( V_32 L_1 , V_22 -> V_33 ) ;
return;
}
if ( V_26 + 80 > V_2 -> V_17 ) {
V_22 -> V_34 . V_35 ++ ;
return;
}
V_26 = F_18 ( V_2 -> V_11 , V_2 -> V_7 , V_26 ) ;
if ( V_26 <= 0 )
return;
} else if ( V_30 >= V_36 ) {
if ( ! ( V_2 -> V_27 & V_29 ) ) {
V_2 -> V_27 |= V_29 ;
V_2 -> V_27 &= ~ V_28 ;
F_17 ( V_37 L_2 , V_22 -> V_33 ) ;
}
V_2 -> V_7 [ 0 ] &= 0x4f ;
if ( F_19 ( V_2 -> V_11 , V_2 -> V_7 , V_26 ) <= 0 )
return;
}
}
#endif
V_22 -> V_34 . V_38 += V_26 ;
V_25 = F_20 ( V_26 ) ;
if ( V_25 == NULL ) {
F_17 ( V_32 L_3 , V_22 -> V_33 ) ;
V_22 -> V_34 . V_39 ++ ;
return;
}
V_25 -> V_22 = V_22 ;
memcpy ( F_21 ( V_25 , V_26 ) , V_2 -> V_7 , V_26 ) ;
F_22 ( V_25 ) ;
V_25 -> V_40 = F_23 ( V_41 ) ;
F_24 ( V_25 ) ;
V_22 -> V_34 . V_42 ++ ;
}
static void F_25 ( struct V_1 * V_2 , unsigned char * V_43 , int V_6 )
{
unsigned char * V_44 ;
int V_45 , V_26 ;
if ( V_6 > V_2 -> V_3 ) {
F_17 ( V_32 L_4 , V_2 -> V_22 -> V_33 ) ;
V_2 -> V_22 -> V_34 . V_46 ++ ;
F_14 ( V_2 ) ;
return;
}
V_44 = V_43 ;
#ifdef F_2
if ( V_2 -> V_27 & V_29 )
V_6 = F_26 ( V_2 -> V_11 , V_44 , V_6 , V_2 -> V_9 , & V_44 , 1 ) ;
#endif
#ifdef F_8
if ( V_2 -> V_27 & V_47 )
V_26 = F_27 ( V_44 , ( unsigned char * ) V_2 -> V_8 , V_6 ) ;
else
#endif
V_26 = F_28 ( V_44 , ( unsigned char * ) V_2 -> V_8 , V_6 ) ;
F_29 ( V_48 , & V_2 -> V_15 -> V_49 ) ;
V_45 = V_2 -> V_15 -> V_50 -> V_51 ( V_2 -> V_15 , V_2 -> V_8 , V_26 ) ;
#ifdef F_30
V_2 -> V_22 -> V_52 = V_53 ;
#endif
V_2 -> V_19 = V_26 - V_45 ;
V_2 -> V_54 = V_2 -> V_8 + V_45 ;
#ifdef F_31
F_32 ( V_55 , & V_2 -> V_49 ) ;
#endif
}
static void F_33 ( struct V_56 * V_15 )
{
int V_45 ;
struct V_1 * V_2 = V_15 -> V_57 ;
if ( ! V_2 || V_2 -> V_58 != V_59 || ! F_34 ( V_2 -> V_22 ) )
return;
if ( V_2 -> V_19 <= 0 ) {
V_2 -> V_22 -> V_34 . V_60 ++ ;
F_32 ( V_48 , & V_15 -> V_49 ) ;
F_14 ( V_2 ) ;
return;
}
V_45 = V_15 -> V_50 -> V_51 ( V_15 , V_2 -> V_54 , V_2 -> V_19 ) ;
V_2 -> V_19 -= V_45 ;
V_2 -> V_54 += V_45 ;
}
static void F_35 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_37 ( & V_2 -> V_14 ) ;
if ( F_38 ( V_22 ) ) {
if ( ! F_34 ( V_22 ) )
goto V_61;
#ifdef F_30
if ( F_39 ( V_53 , F_40 ( V_22 ) + 20 * V_62 ) ) {
goto V_61;
}
F_17 ( V_32 L_5 ,
V_22 -> V_33 ,
( F_41 ( V_2 -> V_15 ) || V_2 -> V_19 ) ?
L_6 : L_7 ) ;
V_2 -> V_19 = 0 ;
F_32 ( V_48 , & V_2 -> V_15 -> V_49 ) ;
F_14 ( V_2 ) ;
#endif
}
V_61:
F_42 ( & V_2 -> V_14 ) ;
}
static T_1
F_43 ( struct V_24 * V_25 , struct V_23 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_37 ( & V_2 -> V_14 ) ;
if ( ! F_34 ( V_22 ) ) {
F_42 ( & V_2 -> V_14 ) ;
F_17 ( V_32 L_8 , V_22 -> V_33 ) ;
F_44 ( V_25 ) ;
return V_63 ;
}
if ( V_2 -> V_15 == NULL ) {
F_42 ( & V_2 -> V_14 ) ;
F_44 ( V_25 ) ;
return V_63 ;
}
F_12 ( V_2 ) ;
V_22 -> V_34 . V_64 += V_25 -> V_6 ;
F_25 ( V_2 , V_25 -> V_65 , V_25 -> V_6 ) ;
F_42 ( & V_2 -> V_14 ) ;
F_44 ( V_25 ) ;
return V_63 ;
}
static int
F_45 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_5 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 )
F_32 ( V_48 , & V_2 -> V_15 -> V_49 ) ;
F_13 ( V_22 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
F_6 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int F_46 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
if ( V_2 -> V_15 == NULL )
return - V_16 ;
V_2 -> V_49 &= ( 1 << V_66 ) ;
F_47 ( V_22 ) ;
return 0 ;
}
static int F_48 ( struct V_23 * V_22 , int V_67 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
if ( V_67 < 68 || V_67 > 65534 )
return - V_68 ;
if ( V_67 != V_22 -> V_3 )
return F_49 ( V_2 , V_67 ) ;
return 0 ;
}
static struct V_69 *
F_50 ( struct V_23 * V_22 , struct V_69 * V_34 )
{
struct V_70 * V_71 = & V_22 -> V_34 ;
unsigned long V_72 = 0 ;
#ifdef F_2
unsigned long V_73 = 0 ;
unsigned long V_74 = 0 ;
unsigned long V_75 = 0 ;
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_10 * V_76 = V_2 -> V_11 ;
if ( V_76 ) {
V_73 = V_76 -> V_77 ;
V_72 = V_76 -> V_78 ;
V_74 = V_76 -> V_79 ;
V_75 = V_76 -> V_80 ;
}
V_34 -> V_81 = V_2 -> V_82 + V_73 ;
V_34 -> V_83 = V_2 -> V_84 + V_74 ;
V_34 -> V_85 = V_2 -> V_86 + V_75 ;
#endif
V_34 -> V_42 = V_71 -> V_42 ;
V_34 -> V_60 = V_71 -> V_60 ;
V_34 -> V_38 = V_71 -> V_38 ;
V_34 -> V_64 = V_71 -> V_64 ;
V_34 -> V_39 = V_71 -> V_39 + V_72 ;
V_34 -> V_46 = V_71 -> V_46 ;
V_34 -> V_87 = V_71 -> V_87 ;
V_34 -> V_88 = V_71 -> V_88 ;
V_34 -> V_35 = V_71 -> V_35 ;
return V_34 ;
}
static int F_51 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
V_22 -> V_3 = V_2 -> V_3 ;
V_22 -> type = V_89 + V_2 -> V_27 ;
#ifdef F_30
V_22 -> V_90 = 20 * V_62 ;
#endif
return 0 ;
}
static void F_52 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_11 ( V_2 ) ;
}
static void F_53 ( struct V_23 * V_22 )
{
int V_91 = V_22 -> V_92 ;
F_54 ( V_22 ) ;
V_93 [ V_91 ] = NULL ;
}
static void F_55 ( struct V_23 * V_22 )
{
V_22 -> V_94 = & V_95 ;
V_22 -> V_96 = F_53 ;
V_22 -> V_97 = 0 ;
V_22 -> V_98 = 0 ;
V_22 -> V_99 = 10 ;
V_22 -> V_49 = V_100 | V_101 | V_102 ;
}
static void F_56 ( struct V_56 * V_15 , const unsigned char * V_103 ,
char * V_104 , int V_26 )
{
struct V_1 * V_2 = V_15 -> V_57 ;
if ( ! V_2 || V_2 -> V_58 != V_59 || ! F_34 ( V_2 -> V_22 ) )
return;
while ( V_26 -- ) {
if ( V_104 && * V_104 ++ ) {
if ( ! F_57 ( V_105 , & V_2 -> V_49 ) )
V_2 -> V_22 -> V_34 . V_88 ++ ;
V_103 ++ ;
continue;
}
#ifdef F_8
if ( V_2 -> V_27 & V_47 )
F_58 ( V_2 , * V_103 ++ ) ;
else
#endif
F_59 ( V_2 , * V_103 ++ ) ;
}
}
static void F_60 ( void )
{
int V_91 ;
struct V_23 * V_22 ;
struct V_1 * V_2 ;
for ( V_91 = 0 ; V_91 < V_106 ; V_91 ++ ) {
V_22 = V_93 [ V_91 ] ;
if ( V_22 == NULL )
break;
V_2 = F_36 ( V_22 ) ;
if ( V_2 -> V_15 || V_2 -> V_107 )
continue;
if ( V_22 -> V_49 & V_108 )
F_61 ( V_22 ) ;
}
}
static struct V_1 * F_62 ( T_2 line )
{
int V_91 ;
char V_33 [ V_109 ] ;
struct V_23 * V_22 = NULL ;
struct V_1 * V_2 ;
for ( V_91 = 0 ; V_91 < V_106 ; V_91 ++ ) {
V_22 = V_93 [ V_91 ] ;
if ( V_22 == NULL )
break;
}
if ( V_91 >= V_106 )
return NULL ;
sprintf ( V_33 , L_9 , V_91 ) ;
V_22 = F_63 ( sizeof( * V_2 ) , V_33 , F_55 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_92 = V_91 ;
V_2 = F_36 ( V_22 ) ;
V_2 -> V_58 = V_59 ;
V_2 -> V_22 = V_22 ;
F_64 ( & V_2 -> V_14 ) ;
V_2 -> V_27 = V_110 ;
#ifdef F_31
F_65 ( & V_2 -> V_111 ) ;
V_2 -> V_111 . V_65 = ( unsigned long ) V_2 ;
V_2 -> V_111 . V_112 = V_113 ;
F_65 ( & V_2 -> V_114 ) ;
V_2 -> V_114 . V_65 = ( unsigned long ) V_2 ;
V_2 -> V_114 . V_112 = V_115 ;
#endif
V_93 [ V_91 ] = V_22 ;
return V_2 ;
}
static int F_66 ( struct V_56 * V_15 )
{
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_67 ( V_116 ) )
return - V_117 ;
if ( V_15 -> V_50 -> V_51 == NULL )
return - V_118 ;
F_68 () ;
F_60 () ;
V_2 = V_15 -> V_57 ;
V_4 = - V_119 ;
if ( V_2 && V_2 -> V_58 == V_59 )
goto V_13;
V_4 = - V_120 ;
V_2 = F_62 ( F_69 ( V_15 ) ) ;
if ( V_2 == NULL )
goto V_13;
V_2 -> V_15 = V_15 ;
V_15 -> V_57 = V_2 ;
V_2 -> V_121 = V_122 -> V_121 ;
if ( ! F_70 ( V_66 , & V_2 -> V_49 ) ) {
V_4 = F_1 ( V_2 , V_123 ) ;
if ( V_4 )
goto V_124;
F_29 ( V_66 , & V_2 -> V_49 ) ;
V_4 = F_71 ( V_2 -> V_22 ) ;
if ( V_4 )
goto V_125;
}
#ifdef F_31
if ( V_2 -> V_126 ) {
V_2 -> V_111 . V_127 = V_53 + V_2 -> V_126 * V_62 ;
F_72 ( & V_2 -> V_111 ) ;
}
if ( V_2 -> V_128 ) {
V_2 -> V_114 . V_127 = V_53 + V_2 -> V_128 * V_62 ;
F_72 ( & V_2 -> V_114 ) ;
}
#endif
F_73 () ;
V_15 -> V_129 = 65536 ;
return 0 ;
V_125:
F_11 ( V_2 ) ;
V_124:
V_2 -> V_15 = NULL ;
V_15 -> V_57 = NULL ;
F_32 ( V_66 , & V_2 -> V_49 ) ;
V_13:
F_73 () ;
return V_4 ;
}
static void F_74 ( struct V_56 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_57 ;
if ( ! V_2 || V_2 -> V_58 != V_59 || V_2 -> V_15 != V_15 )
return;
V_15 -> V_57 = NULL ;
V_2 -> V_15 = NULL ;
#ifdef F_31
F_75 ( & V_2 -> V_111 ) ;
F_75 ( & V_2 -> V_114 ) ;
#endif
F_76 ( V_2 -> V_22 ) ;
}
static int F_77 ( struct V_56 * V_15 )
{
F_74 ( V_15 ) ;
return 0 ;
}
static int F_28 ( unsigned char * V_130 , unsigned char * V_131 , int V_6 )
{
unsigned char * V_132 = V_131 ;
unsigned char V_30 ;
* V_132 ++ = V_133 ;
while ( V_6 -- > 0 ) {
switch ( V_30 = * V_130 ++ ) {
case V_133 :
* V_132 ++ = V_134 ;
* V_132 ++ = V_135 ;
break;
case V_134 :
* V_132 ++ = V_134 ;
* V_132 ++ = V_136 ;
break;
default:
* V_132 ++ = V_30 ;
break;
}
}
* V_132 ++ = V_133 ;
return V_132 - V_131 ;
}
static void F_59 ( struct V_1 * V_2 , unsigned char V_130 )
{
switch ( V_130 ) {
case V_133 :
#ifdef F_31
if ( F_70 ( V_137 , & V_2 -> V_49 ) )
F_32 ( V_137 , & V_2 -> V_49 ) ;
#endif
if ( ! F_78 ( V_105 , & V_2 -> V_49 ) &&
( V_2 -> V_18 > 2 ) )
F_16 ( V_2 ) ;
F_32 ( V_138 , & V_2 -> V_49 ) ;
V_2 -> V_18 = 0 ;
return;
case V_134 :
F_29 ( V_138 , & V_2 -> V_49 ) ;
return;
case V_136 :
if ( F_78 ( V_138 , & V_2 -> V_49 ) )
V_130 = V_134 ;
break;
case V_135 :
if ( F_78 ( V_138 , & V_2 -> V_49 ) )
V_130 = V_133 ;
break;
}
if ( ! F_70 ( V_105 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_18 < V_2 -> V_17 ) {
V_2 -> V_7 [ V_2 -> V_18 ++ ] = V_130 ;
return;
}
V_2 -> V_22 -> V_34 . V_35 ++ ;
F_29 ( V_105 , & V_2 -> V_49 ) ;
}
}
static int F_27 ( unsigned char * V_130 , unsigned char * V_131 , int V_6 )
{
unsigned char * V_132 = V_131 ;
unsigned char V_30 ;
int V_91 ;
unsigned short V_139 = 0 ;
short V_140 = 0 ;
* V_132 ++ = 0x70 ;
for ( V_91 = 0 ; V_91 < V_6 ; ++ V_91 ) {
V_139 = ( V_139 << 8 ) | V_130 [ V_91 ] ;
V_140 += 8 ;
while ( V_140 >= 6 ) {
V_140 -= 6 ;
V_30 = 0x30 + ( ( V_139 >> V_140 ) & 0x3F ) ;
* V_132 ++ = V_30 ;
}
}
if ( V_140 ) {
V_30 = 0x30 + ( ( V_139 << ( 6 - V_140 ) ) & 0x3F ) ;
* V_132 ++ = V_30 ;
}
* V_132 ++ = 0x70 ;
return V_132 - V_131 ;
}
static void F_58 ( struct V_1 * V_2 , unsigned char V_130 )
{
unsigned char V_30 ;
if ( V_130 == 0x70 ) {
#ifdef F_31
if ( F_70 ( V_137 , & V_2 -> V_49 ) )
F_32 ( V_137 , & V_2 -> V_49 ) ;
#endif
if ( ! F_78 ( V_105 , & V_2 -> V_49 ) &&
( V_2 -> V_18 > 2 ) )
F_16 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_20 = 0 ;
} else if ( V_130 >= 0x30 && V_130 < 0x70 ) {
V_2 -> V_20 = ( V_2 -> V_20 << 6 ) | ( ( V_130 - 0x30 ) & 0x3F ) ;
V_2 -> V_21 += 6 ;
if ( V_2 -> V_21 >= 8 ) {
V_2 -> V_21 -= 8 ;
V_30 = ( unsigned char ) ( V_2 -> V_20 >> V_2 -> V_21 ) ;
if ( ! F_70 ( V_105 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_18 < V_2 -> V_17 ) {
V_2 -> V_7 [ V_2 -> V_18 ++ ] = V_30 ;
return;
}
V_2 -> V_22 -> V_34 . V_35 ++ ;
F_29 ( V_105 , & V_2 -> V_49 ) ;
}
}
}
}
static int F_79 ( struct V_56 * V_15 , struct V_141 * V_141 ,
unsigned int V_142 , unsigned long V_143 )
{
struct V_1 * V_2 = V_15 -> V_57 ;
unsigned int V_144 ;
int T_3 * V_44 = ( int T_3 * ) V_143 ;
if ( ! V_2 || V_2 -> V_58 != V_59 )
return - V_68 ;
switch ( V_142 ) {
case V_145 :
V_144 = strlen ( V_2 -> V_22 -> V_33 ) + 1 ;
if ( F_80 ( ( void T_3 * ) V_143 , V_2 -> V_22 -> V_33 , V_144 ) )
return - V_146 ;
return 0 ;
case V_147 :
if ( F_81 ( V_2 -> V_27 , V_44 ) )
return - V_146 ;
return 0 ;
case V_148 :
if ( F_82 ( V_144 , V_44 ) )
return - V_146 ;
#ifndef F_2
if ( V_144 & ( V_29 | V_28 ) )
return - V_68 ;
#else
if ( ( V_144 & ( V_28 | V_29 ) ) ==
( V_28 | V_29 ) )
V_144 &= ~ V_28 ;
#endif
#ifndef F_8
if ( V_144 & V_47 )
return - V_68 ;
#endif
V_2 -> V_27 = V_144 ;
V_2 -> V_22 -> type = V_89 + V_2 -> V_27 ;
return 0 ;
case V_149 :
return - V_68 ;
#ifdef F_31
case V_150 :
if ( F_82 ( V_144 , V_44 ) )
return - V_146 ;
if ( V_144 > 255 )
return - V_68 ;
F_5 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_6 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
V_2 -> V_126 = ( V_151 ) V_144 ;
if ( V_2 -> V_126 != 0 ) {
F_83 ( & V_2 -> V_111 ,
V_53 + V_2 -> V_126 * V_62 ) ;
F_29 ( V_137 , & V_2 -> V_49 ) ;
} else
F_84 ( & V_2 -> V_111 ) ;
F_6 ( & V_2 -> V_14 ) ;
return 0 ;
case V_152 :
if ( F_81 ( V_2 -> V_126 , V_44 ) )
return - V_146 ;
return 0 ;
case V_153 :
if ( F_82 ( V_144 , V_44 ) )
return - V_146 ;
if ( V_144 > 255 )
return - V_68 ;
F_5 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_6 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
V_2 -> V_128 = ( V_151 ) V_144 ;
if ( V_2 -> V_128 != 0 ) {
F_83 ( & V_2 -> V_114 ,
V_53 + V_2 -> V_128 * V_62 ) ;
F_29 ( V_55 , & V_2 -> V_49 ) ;
} else
F_84 ( & V_2 -> V_114 ) ;
F_6 ( & V_2 -> V_14 ) ;
return 0 ;
case V_154 :
if ( F_81 ( V_2 -> V_128 , V_44 ) )
return - V_146 ;
return 0 ;
#endif
default:
return F_85 ( V_15 , V_141 , V_142 , V_143 ) ;
}
}
static long F_86 ( struct V_56 * V_15 , struct V_141 * V_141 ,
unsigned int V_142 , unsigned long V_143 )
{
switch ( V_142 ) {
case V_145 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_152 :
case V_153 :
case V_154 :
return F_79 ( V_15 , V_141 , V_142 ,
( unsigned long ) F_87 ( V_143 ) ) ;
}
return - V_155 ;
}
static int F_88 ( struct V_23 * V_22 , struct V_156 * V_157 , int V_142 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
unsigned long * V_44 = ( unsigned long * ) & V_157 -> V_158 ;
if ( V_2 == NULL )
return - V_16 ;
F_5 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_6 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
switch ( V_142 ) {
case V_150 :
if ( ( unsigned ) * V_44 > 255 ) {
F_6 ( & V_2 -> V_14 ) ;
return - V_68 ;
}
V_2 -> V_126 = ( V_151 ) * V_44 ;
if ( V_2 -> V_126 != 0 ) {
V_2 -> V_111 . V_127 =
V_53 + V_2 -> V_126 * V_62 ;
F_83 ( & V_2 -> V_111 ,
V_53 + V_2 -> V_126 * V_62 ) ;
F_29 ( V_137 , & V_2 -> V_49 ) ;
} else
F_84 ( & V_2 -> V_111 ) ;
break;
case V_152 :
* V_44 = V_2 -> V_126 ;
break;
case V_153 :
if ( ( unsigned ) * V_44 > 255 ) {
F_6 ( & V_2 -> V_14 ) ;
return - V_68 ;
}
V_2 -> V_128 = ( V_151 ) * V_44 ;
if ( V_2 -> V_128 != 0 ) {
F_83 ( & V_2 -> V_114 ,
V_53 + V_2 -> V_128 * V_62 ) ;
F_29 ( V_55 , & V_2 -> V_49 ) ;
} else
F_84 ( & V_2 -> V_114 ) ;
break;
case V_154 :
* V_44 = V_2 -> V_128 ;
break;
case V_159 :
if ( V_2 -> V_15 != V_122 -> signal -> V_15 &&
V_2 -> V_121 != V_122 -> V_121 ) {
F_6 ( & V_2 -> V_14 ) ;
return - V_117 ;
}
V_2 -> V_107 = 0 ;
if ( * V_44 )
V_2 -> V_107 = 1 ;
break;
case V_160 :
* V_44 = V_2 -> V_107 ;
}
F_6 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int T_4 F_89 ( void )
{
int V_161 ;
if ( V_106 < 4 )
V_106 = 4 ;
F_17 ( V_37 L_10
#ifdef F_8
L_11
#endif
L_12 ,
V_162 , V_106 ) ;
#if F_90 ( F_2 )
F_17 ( V_37 L_13 ) ;
#endif
#ifdef F_31
F_17 ( V_37 L_14 ) ;
#endif
V_93 = F_91 ( sizeof( struct V_23 * ) * V_106 ,
V_12 ) ;
if ( ! V_93 ) {
F_17 ( V_163 L_15 ) ;
return - V_164 ;
}
V_161 = F_92 ( V_165 , & V_166 ) ;
if ( V_161 != 0 ) {
F_17 ( V_163 L_16 , V_161 ) ;
F_9 ( V_93 ) ;
}
return V_161 ;
}
static void T_5 F_93 ( void )
{
int V_91 ;
struct V_23 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_167 = V_53 + V_62 ;
int V_168 = 0 ;
if ( V_93 == NULL )
return;
do {
if ( V_168 )
F_94 ( 100 ) ;
V_168 = 0 ;
for ( V_91 = 0 ; V_91 < V_106 ; V_91 ++ ) {
V_22 = V_93 [ V_91 ] ;
if ( ! V_22 )
continue;
V_2 = F_36 ( V_22 ) ;
F_5 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 ) {
V_168 ++ ;
F_95 ( V_2 -> V_15 ) ;
}
F_6 ( & V_2 -> V_14 ) ;
}
} while ( V_168 && F_39 ( V_53 , V_167 ) );
for ( V_91 = 0 ; V_91 < V_106 ; V_91 ++ ) {
V_22 = V_93 [ V_91 ] ;
if ( ! V_22 )
continue;
V_93 [ V_91 ] = NULL ;
V_2 = F_36 ( V_22 ) ;
if ( V_2 -> V_15 ) {
F_17 ( V_163 L_17 ,
V_22 -> V_33 ) ;
V_22 -> V_96 = NULL ;
}
F_76 ( V_22 ) ;
}
F_9 ( V_93 ) ;
V_93 = NULL ;
V_91 = F_96 ( V_165 ) ;
if ( V_91 != 0 )
F_17 ( V_163 L_18 , V_91 ) ;
}
static void V_115 ( unsigned long V_169 )
{
struct V_1 * V_2 = (struct V_1 * ) V_169 ;
F_37 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL )
goto V_61;
if ( V_2 -> V_128 ) {
if ( F_70 ( V_55 , & V_2 -> V_49 ) ) {
#ifdef F_8
unsigned char V_130 = ( V_2 -> V_27 & V_47 ) ? 0x70 : V_133 ;
#else
unsigned char V_130 = V_133 ;
#endif
if ( ! F_38 ( V_2 -> V_22 ) ) {
V_2 -> V_15 -> V_50 -> V_51 ( V_2 -> V_15 , & V_130 , 1 ) ;
}
} else
F_29 ( V_55 , & V_2 -> V_49 ) ;
F_83 ( & V_2 -> V_114 , V_53 + V_2 -> V_128 * V_62 ) ;
}
V_61:
F_42 ( & V_2 -> V_14 ) ;
}
static void V_113 ( unsigned long V_169 )
{
struct V_1 * V_2 = (struct V_1 * ) V_169 ;
F_37 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL )
goto V_61;
if ( V_2 -> V_126 ) {
if ( F_70 ( V_137 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_128 )
( void ) F_84 ( & V_2 -> V_114 ) ;
F_17 ( V_170 L_19 , V_2 -> V_22 -> V_33 ) ;
F_95 ( V_2 -> V_15 ) ;
goto V_61;
} else
F_29 ( V_137 , & V_2 -> V_49 ) ;
F_83 ( & V_2 -> V_111 , V_53 + V_2 -> V_126 * V_62 ) ;
}
V_61:
F_42 ( & V_2 -> V_14 ) ;
}
