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
if ( F_5 ( V_11 ) )
goto V_13;
#endif
F_6 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL ) {
F_7 ( & V_2 -> V_14 ) ;
V_4 = - V_16 ;
goto V_13;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_17 = V_6 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_7 = F_8 ( & V_2 -> V_7 , V_7 ) ;
V_8 = F_8 ( & V_2 -> V_8 , V_8 ) ;
#ifdef F_2
V_9 = F_8 ( & V_2 -> V_9 , V_9 ) ;
V_11 = F_8 ( & V_2 -> V_11 , V_11 ) ;
#endif
#ifdef F_9
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
#endif
F_7 ( & V_2 -> V_14 ) ;
V_4 = 0 ;
V_13:
#ifdef F_2
F_10 ( V_9 ) ;
F_11 ( V_11 ) ;
#endif
F_10 ( V_8 ) ;
F_10 ( V_7 ) ;
return V_4 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_10 ( F_8 ( & V_2 -> V_7 , NULL ) ) ;
F_10 ( F_8 ( & V_2 -> V_8 , NULL ) ) ;
#ifdef F_2
F_10 ( F_8 ( & V_2 -> V_9 , NULL ) ) ;
F_11 ( F_8 ( & V_2 -> V_11 , NULL ) ) ;
#endif
}
static inline void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_22 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_22 ) ;
}
static void F_17 ( struct V_1 * V_2 )
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
F_18 ( V_32 L_1 , V_22 -> V_33 ) ;
return;
}
if ( V_26 + 80 > V_2 -> V_17 ) {
V_22 -> V_34 . V_35 ++ ;
return;
}
V_26 = F_19 ( V_2 -> V_11 , V_2 -> V_7 , V_26 ) ;
if ( V_26 <= 0 )
return;
} else if ( V_30 >= V_36 ) {
if ( ! ( V_2 -> V_27 & V_29 ) ) {
V_2 -> V_27 |= V_29 ;
V_2 -> V_27 &= ~ V_28 ;
F_18 ( V_37 L_2 , V_22 -> V_33 ) ;
}
V_2 -> V_7 [ 0 ] &= 0x4f ;
if ( F_20 ( V_2 -> V_11 , V_2 -> V_7 , V_26 ) <= 0 )
return;
}
}
#endif
V_22 -> V_34 . V_38 += V_26 ;
V_25 = F_21 ( V_26 ) ;
if ( V_25 == NULL ) {
F_18 ( V_32 L_3 , V_22 -> V_33 ) ;
V_22 -> V_34 . V_39 ++ ;
return;
}
V_25 -> V_22 = V_22 ;
F_22 ( V_25 , V_2 -> V_7 , V_26 ) ;
F_23 ( V_25 ) ;
V_25 -> V_40 = F_24 ( V_41 ) ;
F_25 ( V_25 ) ;
V_22 -> V_34 . V_42 ++ ;
}
static void F_26 ( struct V_1 * V_2 , unsigned char * V_43 , int V_6 )
{
unsigned char * V_44 ;
int V_45 , V_26 ;
if ( V_6 > V_2 -> V_3 ) {
F_18 ( V_32 L_4 , V_2 -> V_22 -> V_33 ) ;
V_2 -> V_22 -> V_34 . V_46 ++ ;
F_15 ( V_2 ) ;
return;
}
V_44 = V_43 ;
#ifdef F_2
if ( V_2 -> V_27 & V_29 )
V_6 = F_27 ( V_2 -> V_11 , V_44 , V_6 , V_2 -> V_9 , & V_44 , 1 ) ;
#endif
#ifdef F_9
if ( V_2 -> V_27 & V_47 )
V_26 = F_28 ( V_44 , V_2 -> V_8 , V_6 ) ;
else
#endif
V_26 = F_29 ( V_44 , V_2 -> V_8 , V_6 ) ;
F_30 ( V_48 , & V_2 -> V_15 -> V_49 ) ;
V_45 = V_2 -> V_15 -> V_50 -> V_51 ( V_2 -> V_15 , V_2 -> V_8 , V_26 ) ;
#ifdef F_31
F_32 ( V_2 -> V_22 ) ;
#endif
V_2 -> V_19 = V_26 - V_45 ;
V_2 -> V_52 = V_2 -> V_8 + V_45 ;
#ifdef F_33
F_34 ( V_53 , & V_2 -> V_49 ) ;
#endif
}
static void F_35 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_36 ( V_55 , struct V_1 , V_56 ) ;
int V_45 ;
F_6 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 || V_2 -> V_57 != V_58 || ! F_37 ( V_2 -> V_22 ) ) {
F_7 ( & V_2 -> V_14 ) ;
return;
}
if ( V_2 -> V_19 <= 0 ) {
V_2 -> V_22 -> V_34 . V_59 ++ ;
F_34 ( V_48 , & V_2 -> V_15 -> V_49 ) ;
F_7 ( & V_2 -> V_14 ) ;
F_15 ( V_2 ) ;
return;
}
V_45 = V_2 -> V_15 -> V_50 -> V_51 ( V_2 -> V_15 , V_2 -> V_52 , V_2 -> V_19 ) ;
V_2 -> V_19 -= V_45 ;
V_2 -> V_52 += V_45 ;
F_7 ( & V_2 -> V_14 ) ;
}
static void F_38 ( struct V_60 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_61 ;
F_39 ( & V_2 -> V_56 ) ;
}
static void F_40 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
F_42 ( & V_2 -> V_14 ) ;
if ( F_43 ( V_22 ) ) {
if ( ! F_37 ( V_22 ) )
goto V_62;
#ifdef F_31
if ( F_44 ( V_63 , F_45 ( V_22 ) + 20 * V_64 ) ) {
goto V_62;
}
F_18 ( V_32 L_5 ,
V_22 -> V_33 ,
( F_46 ( V_2 -> V_15 ) || V_2 -> V_19 ) ?
L_6 : L_7 ) ;
V_2 -> V_19 = 0 ;
F_34 ( V_48 , & V_2 -> V_15 -> V_49 ) ;
F_15 ( V_2 ) ;
#endif
}
V_62:
F_47 ( & V_2 -> V_14 ) ;
}
static T_1
F_48 ( struct V_24 * V_25 , struct V_23 * V_22 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
F_42 ( & V_2 -> V_14 ) ;
if ( ! F_37 ( V_22 ) ) {
F_47 ( & V_2 -> V_14 ) ;
F_18 ( V_32 L_8 , V_22 -> V_33 ) ;
F_49 ( V_25 ) ;
return V_65 ;
}
if ( V_2 -> V_15 == NULL ) {
F_47 ( & V_2 -> V_14 ) ;
F_49 ( V_25 ) ;
return V_65 ;
}
F_13 ( V_2 ) ;
V_22 -> V_34 . V_66 += V_25 -> V_6 ;
F_26 ( V_2 , V_25 -> V_67 , V_25 -> V_6 ) ;
F_47 ( & V_2 -> V_14 ) ;
F_49 ( V_25 ) ;
return V_65 ;
}
static int
F_50 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
F_6 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 )
F_34 ( V_48 , & V_2 -> V_15 -> V_49 ) ;
F_14 ( V_22 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
F_7 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int F_51 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
if ( V_2 -> V_15 == NULL )
return - V_16 ;
V_2 -> V_49 &= ( 1 << V_68 ) ;
F_52 ( V_22 ) ;
return 0 ;
}
static int F_53 ( struct V_23 * V_22 , int V_69 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
return F_54 ( V_2 , V_69 ) ;
}
static void
F_55 ( struct V_23 * V_22 , struct V_70 * V_34 )
{
struct V_71 * V_72 = & V_22 -> V_34 ;
#ifdef F_2
struct V_1 * V_2 = F_41 ( V_22 ) ;
struct V_10 * V_73 = V_2 -> V_11 ;
#endif
V_34 -> V_42 = V_72 -> V_42 ;
V_34 -> V_59 = V_72 -> V_59 ;
V_34 -> V_38 = V_72 -> V_38 ;
V_34 -> V_66 = V_72 -> V_66 ;
V_34 -> V_39 = V_72 -> V_39 ;
V_34 -> V_46 = V_72 -> V_46 ;
V_34 -> V_74 = V_72 -> V_74 ;
V_34 -> V_75 = V_72 -> V_75 ;
V_34 -> V_35 = V_72 -> V_35 ;
#ifdef F_2
if ( V_73 ) {
V_34 -> V_76 = V_73 -> V_77 ;
V_34 -> V_78 = V_73 -> V_79 ;
V_34 -> V_80 += V_73 -> V_77 ;
V_34 -> V_39 += V_73 -> V_81 ;
V_34 -> V_82 += V_73 -> V_79 ;
V_34 -> V_83 += V_73 -> V_84 ;
}
#endif
}
static int F_56 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
V_22 -> V_3 = V_2 -> V_3 ;
V_22 -> type = V_85 + V_2 -> V_27 ;
#ifdef F_31
V_22 -> V_86 = 20 * V_64 ;
#endif
return 0 ;
}
static void F_57 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
F_12 ( V_2 ) ;
}
static void F_58 ( struct V_23 * V_22 )
{
int V_87 = V_22 -> V_88 ;
V_89 [ V_87 ] = NULL ;
}
static void F_59 ( struct V_23 * V_22 )
{
V_22 -> V_90 = & V_91 ;
V_22 -> V_92 = true ;
V_22 -> V_93 = F_58 ;
V_22 -> V_94 = 0 ;
V_22 -> V_95 = 0 ;
V_22 -> V_96 = 10 ;
V_22 -> V_97 = 68 ;
V_22 -> V_98 = 65534 ;
V_22 -> V_49 = V_99 | V_100 | V_101 ;
}
static void F_60 ( struct V_60 * V_15 , const unsigned char * V_102 ,
char * V_103 , int V_26 )
{
struct V_1 * V_2 = V_15 -> V_61 ;
if ( ! V_2 || V_2 -> V_57 != V_58 || ! F_37 ( V_2 -> V_22 ) )
return;
while ( V_26 -- ) {
if ( V_103 && * V_103 ++ ) {
if ( ! F_61 ( V_104 , & V_2 -> V_49 ) )
V_2 -> V_22 -> V_34 . V_75 ++ ;
V_102 ++ ;
continue;
}
#ifdef F_9
if ( V_2 -> V_27 & V_47 )
F_62 ( V_2 , * V_102 ++ ) ;
else
#endif
F_63 ( V_2 , * V_102 ++ ) ;
}
}
static void F_64 ( void )
{
int V_87 ;
struct V_23 * V_22 ;
struct V_1 * V_2 ;
for ( V_87 = 0 ; V_87 < V_105 ; V_87 ++ ) {
V_22 = V_89 [ V_87 ] ;
if ( V_22 == NULL )
break;
V_2 = F_41 ( V_22 ) ;
if ( V_2 -> V_15 || V_2 -> V_106 )
continue;
if ( V_22 -> V_49 & V_107 )
F_65 ( V_22 ) ;
}
}
static struct V_1 * F_66 ( T_2 line )
{
int V_87 ;
char V_33 [ V_108 ] ;
struct V_23 * V_22 = NULL ;
struct V_1 * V_2 ;
for ( V_87 = 0 ; V_87 < V_105 ; V_87 ++ ) {
V_22 = V_89 [ V_87 ] ;
if ( V_22 == NULL )
break;
}
if ( V_87 >= V_105 )
return NULL ;
sprintf ( V_33 , L_9 , V_87 ) ;
V_22 = F_67 ( sizeof( * V_2 ) , V_33 , V_109 , F_59 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_88 = V_87 ;
V_2 = F_41 ( V_22 ) ;
V_2 -> V_57 = V_58 ;
V_2 -> V_22 = V_22 ;
F_68 ( & V_2 -> V_14 ) ;
F_69 ( & V_2 -> V_56 , F_35 ) ;
V_2 -> V_27 = V_110 ;
#ifdef F_33
F_70 ( & V_2 -> V_111 ) ;
V_2 -> V_111 . V_67 = ( unsigned long ) V_2 ;
V_2 -> V_111 . V_112 = V_113 ;
F_70 ( & V_2 -> V_114 ) ;
V_2 -> V_114 . V_67 = ( unsigned long ) V_2 ;
V_2 -> V_114 . V_112 = V_115 ;
#endif
V_89 [ V_87 ] = V_22 ;
return V_2 ;
}
static int F_71 ( struct V_60 * V_15 )
{
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_72 ( V_116 ) )
return - V_117 ;
if ( V_15 -> V_50 -> V_51 == NULL )
return - V_118 ;
F_73 () ;
F_64 () ;
V_2 = V_15 -> V_61 ;
V_4 = - V_119 ;
if ( V_2 && V_2 -> V_57 == V_58 )
goto V_13;
V_4 = - V_120 ;
V_2 = F_66 ( F_74 ( V_15 ) ) ;
if ( V_2 == NULL )
goto V_13;
V_2 -> V_15 = V_15 ;
V_15 -> V_61 = V_2 ;
V_2 -> V_121 = V_122 -> V_121 ;
if ( ! F_75 ( V_68 , & V_2 -> V_49 ) ) {
V_4 = F_1 ( V_2 , V_123 ) ;
if ( V_4 )
goto V_124;
F_30 ( V_68 , & V_2 -> V_49 ) ;
V_4 = F_76 ( V_2 -> V_22 ) ;
if ( V_4 )
goto V_125;
}
#ifdef F_33
if ( V_2 -> V_126 ) {
V_2 -> V_111 . V_127 = V_63 + V_2 -> V_126 * V_64 ;
F_77 ( & V_2 -> V_111 ) ;
}
if ( V_2 -> V_128 ) {
V_2 -> V_114 . V_127 = V_63 + V_2 -> V_128 * V_64 ;
F_77 ( & V_2 -> V_114 ) ;
}
#endif
F_78 () ;
V_15 -> V_129 = 65536 ;
return 0 ;
V_125:
F_12 ( V_2 ) ;
V_124:
V_2 -> V_15 = NULL ;
V_15 -> V_61 = NULL ;
F_34 ( V_68 , & V_2 -> V_49 ) ;
V_13:
F_78 () ;
return V_4 ;
}
static void F_79 ( struct V_60 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_61 ;
if ( ! V_2 || V_2 -> V_57 != V_58 || V_2 -> V_15 != V_15 )
return;
F_6 ( & V_2 -> V_14 ) ;
V_15 -> V_61 = NULL ;
V_2 -> V_15 = NULL ;
F_7 ( & V_2 -> V_14 ) ;
F_80 ( & V_2 -> V_56 ) ;
#ifdef F_33
F_81 ( & V_2 -> V_111 ) ;
F_81 ( & V_2 -> V_114 ) ;
#endif
F_82 ( V_2 -> V_22 ) ;
}
static int F_83 ( struct V_60 * V_15 )
{
F_79 ( V_15 ) ;
return 0 ;
}
static int F_29 ( unsigned char * V_130 , unsigned char * V_131 , int V_6 )
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
static void F_63 ( struct V_1 * V_2 , unsigned char V_130 )
{
switch ( V_130 ) {
case V_133 :
#ifdef F_33
if ( F_75 ( V_137 , & V_2 -> V_49 ) )
F_34 ( V_137 , & V_2 -> V_49 ) ;
#endif
if ( ! F_84 ( V_104 , & V_2 -> V_49 ) &&
( V_2 -> V_18 > 2 ) )
F_17 ( V_2 ) ;
F_34 ( V_138 , & V_2 -> V_49 ) ;
V_2 -> V_18 = 0 ;
return;
case V_134 :
F_30 ( V_138 , & V_2 -> V_49 ) ;
return;
case V_136 :
if ( F_84 ( V_138 , & V_2 -> V_49 ) )
V_130 = V_134 ;
break;
case V_135 :
if ( F_84 ( V_138 , & V_2 -> V_49 ) )
V_130 = V_133 ;
break;
}
if ( ! F_75 ( V_104 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_18 < V_2 -> V_17 ) {
V_2 -> V_7 [ V_2 -> V_18 ++ ] = V_130 ;
return;
}
V_2 -> V_22 -> V_34 . V_35 ++ ;
F_30 ( V_104 , & V_2 -> V_49 ) ;
}
}
static int F_28 ( unsigned char * V_130 , unsigned char * V_131 , int V_6 )
{
unsigned char * V_132 = V_131 ;
unsigned char V_30 ;
int V_87 ;
unsigned short V_139 = 0 ;
short V_140 = 0 ;
* V_132 ++ = 0x70 ;
for ( V_87 = 0 ; V_87 < V_6 ; ++ V_87 ) {
V_139 = ( V_139 << 8 ) | V_130 [ V_87 ] ;
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
static void F_62 ( struct V_1 * V_2 , unsigned char V_130 )
{
unsigned char V_30 ;
if ( V_130 == 0x70 ) {
#ifdef F_33
if ( F_75 ( V_137 , & V_2 -> V_49 ) )
F_34 ( V_137 , & V_2 -> V_49 ) ;
#endif
if ( ! F_84 ( V_104 , & V_2 -> V_49 ) &&
( V_2 -> V_18 > 2 ) )
F_17 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_20 = 0 ;
} else if ( V_130 >= 0x30 && V_130 < 0x70 ) {
V_2 -> V_20 = ( V_2 -> V_20 << 6 ) | ( ( V_130 - 0x30 ) & 0x3F ) ;
V_2 -> V_21 += 6 ;
if ( V_2 -> V_21 >= 8 ) {
V_2 -> V_21 -= 8 ;
V_30 = ( unsigned char ) ( V_2 -> V_20 >> V_2 -> V_21 ) ;
if ( ! F_75 ( V_104 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_18 < V_2 -> V_17 ) {
V_2 -> V_7 [ V_2 -> V_18 ++ ] = V_30 ;
return;
}
V_2 -> V_22 -> V_34 . V_35 ++ ;
F_30 ( V_104 , & V_2 -> V_49 ) ;
}
}
}
}
static int F_85 ( struct V_60 * V_15 , struct V_141 * V_141 ,
unsigned int V_142 , unsigned long V_143 )
{
struct V_1 * V_2 = V_15 -> V_61 ;
unsigned int V_144 ;
int T_3 * V_44 = ( int T_3 * ) V_143 ;
if ( ! V_2 || V_2 -> V_57 != V_58 )
return - V_145 ;
switch ( V_142 ) {
case V_146 :
V_144 = strlen ( V_2 -> V_22 -> V_33 ) + 1 ;
if ( F_86 ( ( void T_3 * ) V_143 , V_2 -> V_22 -> V_33 , V_144 ) )
return - V_147 ;
return 0 ;
case V_148 :
if ( F_87 ( V_2 -> V_27 , V_44 ) )
return - V_147 ;
return 0 ;
case V_149 :
if ( F_88 ( V_144 , V_44 ) )
return - V_147 ;
#ifndef F_2
if ( V_144 & ( V_29 | V_28 ) )
return - V_145 ;
#else
if ( ( V_144 & ( V_28 | V_29 ) ) ==
( V_28 | V_29 ) )
V_144 &= ~ V_28 ;
#endif
#ifndef F_9
if ( V_144 & V_47 )
return - V_145 ;
#endif
V_2 -> V_27 = V_144 ;
V_2 -> V_22 -> type = V_85 + V_2 -> V_27 ;
return 0 ;
case V_150 :
return - V_145 ;
#ifdef F_33
case V_151 :
if ( F_88 ( V_144 , V_44 ) )
return - V_147 ;
if ( V_144 > 255 )
return - V_145 ;
F_6 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
V_2 -> V_126 = ( V_152 ) V_144 ;
if ( V_2 -> V_126 != 0 ) {
F_89 ( & V_2 -> V_111 ,
V_63 + V_2 -> V_126 * V_64 ) ;
F_30 ( V_137 , & V_2 -> V_49 ) ;
} else
F_90 ( & V_2 -> V_111 ) ;
F_7 ( & V_2 -> V_14 ) ;
return 0 ;
case V_153 :
if ( F_87 ( V_2 -> V_126 , V_44 ) )
return - V_147 ;
return 0 ;
case V_154 :
if ( F_88 ( V_144 , V_44 ) )
return - V_147 ;
if ( V_144 > 255 )
return - V_145 ;
F_6 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
V_2 -> V_128 = ( V_152 ) V_144 ;
if ( V_2 -> V_128 != 0 ) {
F_89 ( & V_2 -> V_114 ,
V_63 + V_2 -> V_128 * V_64 ) ;
F_30 ( V_53 , & V_2 -> V_49 ) ;
} else
F_90 ( & V_2 -> V_114 ) ;
F_7 ( & V_2 -> V_14 ) ;
return 0 ;
case V_155 :
if ( F_87 ( V_2 -> V_128 , V_44 ) )
return - V_147 ;
return 0 ;
#endif
default:
return F_91 ( V_15 , V_141 , V_142 , V_143 ) ;
}
}
static long F_92 ( struct V_60 * V_15 , struct V_141 * V_141 ,
unsigned int V_142 , unsigned long V_143 )
{
switch ( V_142 ) {
case V_146 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_153 :
case V_154 :
case V_155 :
return F_85 ( V_15 , V_141 , V_142 ,
( unsigned long ) F_93 ( V_143 ) ) ;
}
return - V_156 ;
}
static int F_94 ( struct V_23 * V_22 , struct V_157 * V_158 , int V_142 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
unsigned long * V_44 = ( unsigned long * ) & V_158 -> V_159 ;
if ( V_2 == NULL )
return - V_16 ;
F_6 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
switch ( V_142 ) {
case V_151 :
if ( ( unsigned ) * V_44 > 255 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_145 ;
}
V_2 -> V_126 = ( V_152 ) * V_44 ;
if ( V_2 -> V_126 != 0 ) {
V_2 -> V_111 . V_127 =
V_63 + V_2 -> V_126 * V_64 ;
F_89 ( & V_2 -> V_111 ,
V_63 + V_2 -> V_126 * V_64 ) ;
F_30 ( V_137 , & V_2 -> V_49 ) ;
} else
F_90 ( & V_2 -> V_111 ) ;
break;
case V_153 :
* V_44 = V_2 -> V_126 ;
break;
case V_154 :
if ( ( unsigned ) * V_44 > 255 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_145 ;
}
V_2 -> V_128 = ( V_152 ) * V_44 ;
if ( V_2 -> V_128 != 0 ) {
F_89 ( & V_2 -> V_114 ,
V_63 + V_2 -> V_128 * V_64 ) ;
F_30 ( V_53 , & V_2 -> V_49 ) ;
} else
F_90 ( & V_2 -> V_114 ) ;
break;
case V_155 :
* V_44 = V_2 -> V_128 ;
break;
case V_160 :
if ( V_2 -> V_15 != V_122 -> signal -> V_15 &&
V_2 -> V_121 != V_122 -> V_121 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_117 ;
}
V_2 -> V_106 = 0 ;
if ( * V_44 )
V_2 -> V_106 = 1 ;
break;
case V_161 :
* V_44 = V_2 -> V_106 ;
}
F_7 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int T_4 F_95 ( void )
{
int V_162 ;
if ( V_105 < 4 )
V_105 = 4 ;
F_18 ( V_37 L_10
#ifdef F_9
L_11
#endif
L_12 ,
V_163 , V_105 ) ;
#if F_96 ( F_2 )
F_18 ( V_37 L_13 ) ;
#endif
#ifdef F_33
F_18 ( V_37 L_14 ) ;
#endif
V_89 = F_97 ( sizeof( struct V_23 * ) * V_105 ,
V_12 ) ;
if ( ! V_89 )
return - V_164 ;
V_162 = F_98 ( V_165 , & V_166 ) ;
if ( V_162 != 0 ) {
F_18 ( V_167 L_15 , V_162 ) ;
F_10 ( V_89 ) ;
}
return V_162 ;
}
static void T_5 F_99 ( void )
{
int V_87 ;
struct V_23 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_168 = V_63 + V_64 ;
int V_169 = 0 ;
if ( V_89 == NULL )
return;
do {
if ( V_169 )
F_100 ( 100 ) ;
V_169 = 0 ;
for ( V_87 = 0 ; V_87 < V_105 ; V_87 ++ ) {
V_22 = V_89 [ V_87 ] ;
if ( ! V_22 )
continue;
V_2 = F_41 ( V_22 ) ;
F_6 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 ) {
V_169 ++ ;
F_101 ( V_2 -> V_15 ) ;
}
F_7 ( & V_2 -> V_14 ) ;
}
} while ( V_169 && F_44 ( V_63 , V_168 ) );
for ( V_87 = 0 ; V_87 < V_105 ; V_87 ++ ) {
V_22 = V_89 [ V_87 ] ;
if ( ! V_22 )
continue;
V_89 [ V_87 ] = NULL ;
V_2 = F_41 ( V_22 ) ;
if ( V_2 -> V_15 ) {
F_18 ( V_167 L_16 ,
V_22 -> V_33 ) ;
}
F_82 ( V_22 ) ;
}
F_10 ( V_89 ) ;
V_89 = NULL ;
V_87 = F_102 ( V_165 ) ;
if ( V_87 != 0 )
F_18 ( V_167 L_17 , V_87 ) ;
}
static void V_115 ( unsigned long V_170 )
{
struct V_1 * V_2 = (struct V_1 * ) V_170 ;
F_42 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL )
goto V_62;
if ( V_2 -> V_128 ) {
if ( F_75 ( V_53 , & V_2 -> V_49 ) ) {
#ifdef F_9
unsigned char V_130 = ( V_2 -> V_27 & V_47 ) ? 0x70 : V_133 ;
#else
unsigned char V_130 = V_133 ;
#endif
if ( ! F_43 ( V_2 -> V_22 ) ) {
V_2 -> V_15 -> V_50 -> V_51 ( V_2 -> V_15 , & V_130 , 1 ) ;
}
} else
F_30 ( V_53 , & V_2 -> V_49 ) ;
F_89 ( & V_2 -> V_114 , V_63 + V_2 -> V_128 * V_64 ) ;
}
V_62:
F_47 ( & V_2 -> V_14 ) ;
}
static void V_113 ( unsigned long V_170 )
{
struct V_1 * V_2 = (struct V_1 * ) V_170 ;
F_42 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL )
goto V_62;
if ( V_2 -> V_126 ) {
if ( F_75 ( V_137 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_128 )
( void ) F_90 ( & V_2 -> V_114 ) ;
F_18 ( V_171 L_18 , V_2 -> V_22 -> V_33 ) ;
F_101 ( V_2 -> V_15 ) ;
goto V_62;
} else
F_30 ( V_137 , & V_2 -> V_49 ) ;
F_89 ( & V_2 -> V_111 , V_63 + V_2 -> V_126 * V_64 ) ;
}
V_62:
F_47 ( & V_2 -> V_14 ) ;
}
