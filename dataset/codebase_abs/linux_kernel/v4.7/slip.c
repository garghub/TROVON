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
memcpy ( F_22 ( V_25 , V_26 ) , V_2 -> V_7 , V_26 ) ;
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
if ( V_69 < 68 || V_69 > 65534 )
return - V_70 ;
if ( V_69 != V_22 -> V_3 )
return F_54 ( V_2 , V_69 ) ;
return 0 ;
}
static struct V_71 *
F_55 ( struct V_23 * V_22 , struct V_71 * V_34 )
{
struct V_72 * V_73 = & V_22 -> V_34 ;
#ifdef F_2
struct V_1 * V_2 = F_41 ( V_22 ) ;
struct V_10 * V_74 = V_2 -> V_11 ;
#endif
V_34 -> V_42 = V_73 -> V_42 ;
V_34 -> V_59 = V_73 -> V_59 ;
V_34 -> V_38 = V_73 -> V_38 ;
V_34 -> V_66 = V_73 -> V_66 ;
V_34 -> V_39 = V_73 -> V_39 ;
V_34 -> V_46 = V_73 -> V_46 ;
V_34 -> V_75 = V_73 -> V_75 ;
V_34 -> V_76 = V_73 -> V_76 ;
V_34 -> V_35 = V_73 -> V_35 ;
#ifdef F_2
if ( V_74 ) {
V_34 -> V_77 = V_74 -> V_78 ;
V_34 -> V_79 = V_74 -> V_80 ;
V_34 -> V_81 += V_74 -> V_78 ;
V_34 -> V_39 += V_74 -> V_82 ;
V_34 -> V_83 += V_74 -> V_80 ;
V_34 -> V_84 += V_74 -> V_85 ;
}
#endif
return V_34 ;
}
static int F_56 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
V_22 -> V_3 = V_2 -> V_3 ;
V_22 -> type = V_86 + V_2 -> V_27 ;
#ifdef F_31
V_22 -> V_87 = 20 * V_64 ;
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
int V_88 = V_22 -> V_89 ;
F_59 ( V_22 ) ;
V_90 [ V_88 ] = NULL ;
}
static void F_60 ( struct V_23 * V_22 )
{
V_22 -> V_91 = & V_92 ;
V_22 -> V_93 = F_58 ;
V_22 -> V_94 = 0 ;
V_22 -> V_95 = 0 ;
V_22 -> V_96 = 10 ;
V_22 -> V_49 = V_97 | V_98 | V_99 ;
}
static void F_61 ( struct V_60 * V_15 , const unsigned char * V_100 ,
char * V_101 , int V_26 )
{
struct V_1 * V_2 = V_15 -> V_61 ;
if ( ! V_2 || V_2 -> V_57 != V_58 || ! F_37 ( V_2 -> V_22 ) )
return;
while ( V_26 -- ) {
if ( V_101 && * V_101 ++ ) {
if ( ! F_62 ( V_102 , & V_2 -> V_49 ) )
V_2 -> V_22 -> V_34 . V_76 ++ ;
V_100 ++ ;
continue;
}
#ifdef F_9
if ( V_2 -> V_27 & V_47 )
F_63 ( V_2 , * V_100 ++ ) ;
else
#endif
F_64 ( V_2 , * V_100 ++ ) ;
}
}
static void F_65 ( void )
{
int V_88 ;
struct V_23 * V_22 ;
struct V_1 * V_2 ;
for ( V_88 = 0 ; V_88 < V_103 ; V_88 ++ ) {
V_22 = V_90 [ V_88 ] ;
if ( V_22 == NULL )
break;
V_2 = F_41 ( V_22 ) ;
if ( V_2 -> V_15 || V_2 -> V_104 )
continue;
if ( V_22 -> V_49 & V_105 )
F_66 ( V_22 ) ;
}
}
static struct V_1 * F_67 ( T_2 line )
{
int V_88 ;
char V_33 [ V_106 ] ;
struct V_23 * V_22 = NULL ;
struct V_1 * V_2 ;
for ( V_88 = 0 ; V_88 < V_103 ; V_88 ++ ) {
V_22 = V_90 [ V_88 ] ;
if ( V_22 == NULL )
break;
}
if ( V_88 >= V_103 )
return NULL ;
sprintf ( V_33 , L_9 , V_88 ) ;
V_22 = F_68 ( sizeof( * V_2 ) , V_33 , V_107 , F_60 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_89 = V_88 ;
V_2 = F_41 ( V_22 ) ;
V_2 -> V_57 = V_58 ;
V_2 -> V_22 = V_22 ;
F_69 ( & V_2 -> V_14 ) ;
F_70 ( & V_2 -> V_56 , F_35 ) ;
V_2 -> V_27 = V_108 ;
#ifdef F_33
F_71 ( & V_2 -> V_109 ) ;
V_2 -> V_109 . V_67 = ( unsigned long ) V_2 ;
V_2 -> V_109 . V_110 = V_111 ;
F_71 ( & V_2 -> V_112 ) ;
V_2 -> V_112 . V_67 = ( unsigned long ) V_2 ;
V_2 -> V_112 . V_110 = V_113 ;
#endif
V_90 [ V_88 ] = V_22 ;
return V_2 ;
}
static int F_72 ( struct V_60 * V_15 )
{
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_73 ( V_114 ) )
return - V_115 ;
if ( V_15 -> V_50 -> V_51 == NULL )
return - V_116 ;
F_74 () ;
F_65 () ;
V_2 = V_15 -> V_61 ;
V_4 = - V_117 ;
if ( V_2 && V_2 -> V_57 == V_58 )
goto V_13;
V_4 = - V_118 ;
V_2 = F_67 ( F_75 ( V_15 ) ) ;
if ( V_2 == NULL )
goto V_13;
V_2 -> V_15 = V_15 ;
V_15 -> V_61 = V_2 ;
V_2 -> V_119 = V_120 -> V_119 ;
if ( ! F_76 ( V_68 , & V_2 -> V_49 ) ) {
V_4 = F_1 ( V_2 , V_121 ) ;
if ( V_4 )
goto V_122;
F_30 ( V_68 , & V_2 -> V_49 ) ;
V_4 = F_77 ( V_2 -> V_22 ) ;
if ( V_4 )
goto V_123;
}
#ifdef F_33
if ( V_2 -> V_124 ) {
V_2 -> V_109 . V_125 = V_63 + V_2 -> V_124 * V_64 ;
F_78 ( & V_2 -> V_109 ) ;
}
if ( V_2 -> V_126 ) {
V_2 -> V_112 . V_125 = V_63 + V_2 -> V_126 * V_64 ;
F_78 ( & V_2 -> V_112 ) ;
}
#endif
F_79 () ;
V_15 -> V_127 = 65536 ;
return 0 ;
V_123:
F_12 ( V_2 ) ;
V_122:
V_2 -> V_15 = NULL ;
V_15 -> V_61 = NULL ;
F_34 ( V_68 , & V_2 -> V_49 ) ;
V_13:
F_79 () ;
return V_4 ;
}
static void F_80 ( struct V_60 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_61 ;
if ( ! V_2 || V_2 -> V_57 != V_58 || V_2 -> V_15 != V_15 )
return;
F_6 ( & V_2 -> V_14 ) ;
V_15 -> V_61 = NULL ;
V_2 -> V_15 = NULL ;
F_7 ( & V_2 -> V_14 ) ;
F_81 ( & V_2 -> V_56 ) ;
#ifdef F_33
F_82 ( & V_2 -> V_109 ) ;
F_82 ( & V_2 -> V_112 ) ;
#endif
F_83 ( V_2 -> V_22 ) ;
}
static int F_84 ( struct V_60 * V_15 )
{
F_80 ( V_15 ) ;
return 0 ;
}
static int F_29 ( unsigned char * V_128 , unsigned char * V_129 , int V_6 )
{
unsigned char * V_130 = V_129 ;
unsigned char V_30 ;
* V_130 ++ = V_131 ;
while ( V_6 -- > 0 ) {
switch ( V_30 = * V_128 ++ ) {
case V_131 :
* V_130 ++ = V_132 ;
* V_130 ++ = V_133 ;
break;
case V_132 :
* V_130 ++ = V_132 ;
* V_130 ++ = V_134 ;
break;
default:
* V_130 ++ = V_30 ;
break;
}
}
* V_130 ++ = V_131 ;
return V_130 - V_129 ;
}
static void F_64 ( struct V_1 * V_2 , unsigned char V_128 )
{
switch ( V_128 ) {
case V_131 :
#ifdef F_33
if ( F_76 ( V_135 , & V_2 -> V_49 ) )
F_34 ( V_135 , & V_2 -> V_49 ) ;
#endif
if ( ! F_85 ( V_102 , & V_2 -> V_49 ) &&
( V_2 -> V_18 > 2 ) )
F_17 ( V_2 ) ;
F_34 ( V_136 , & V_2 -> V_49 ) ;
V_2 -> V_18 = 0 ;
return;
case V_132 :
F_30 ( V_136 , & V_2 -> V_49 ) ;
return;
case V_134 :
if ( F_85 ( V_136 , & V_2 -> V_49 ) )
V_128 = V_132 ;
break;
case V_133 :
if ( F_85 ( V_136 , & V_2 -> V_49 ) )
V_128 = V_131 ;
break;
}
if ( ! F_76 ( V_102 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_18 < V_2 -> V_17 ) {
V_2 -> V_7 [ V_2 -> V_18 ++ ] = V_128 ;
return;
}
V_2 -> V_22 -> V_34 . V_35 ++ ;
F_30 ( V_102 , & V_2 -> V_49 ) ;
}
}
static int F_28 ( unsigned char * V_128 , unsigned char * V_129 , int V_6 )
{
unsigned char * V_130 = V_129 ;
unsigned char V_30 ;
int V_88 ;
unsigned short V_137 = 0 ;
short V_138 = 0 ;
* V_130 ++ = 0x70 ;
for ( V_88 = 0 ; V_88 < V_6 ; ++ V_88 ) {
V_137 = ( V_137 << 8 ) | V_128 [ V_88 ] ;
V_138 += 8 ;
while ( V_138 >= 6 ) {
V_138 -= 6 ;
V_30 = 0x30 + ( ( V_137 >> V_138 ) & 0x3F ) ;
* V_130 ++ = V_30 ;
}
}
if ( V_138 ) {
V_30 = 0x30 + ( ( V_137 << ( 6 - V_138 ) ) & 0x3F ) ;
* V_130 ++ = V_30 ;
}
* V_130 ++ = 0x70 ;
return V_130 - V_129 ;
}
static void F_63 ( struct V_1 * V_2 , unsigned char V_128 )
{
unsigned char V_30 ;
if ( V_128 == 0x70 ) {
#ifdef F_33
if ( F_76 ( V_135 , & V_2 -> V_49 ) )
F_34 ( V_135 , & V_2 -> V_49 ) ;
#endif
if ( ! F_85 ( V_102 , & V_2 -> V_49 ) &&
( V_2 -> V_18 > 2 ) )
F_17 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_20 = 0 ;
} else if ( V_128 >= 0x30 && V_128 < 0x70 ) {
V_2 -> V_20 = ( V_2 -> V_20 << 6 ) | ( ( V_128 - 0x30 ) & 0x3F ) ;
V_2 -> V_21 += 6 ;
if ( V_2 -> V_21 >= 8 ) {
V_2 -> V_21 -= 8 ;
V_30 = ( unsigned char ) ( V_2 -> V_20 >> V_2 -> V_21 ) ;
if ( ! F_76 ( V_102 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_18 < V_2 -> V_17 ) {
V_2 -> V_7 [ V_2 -> V_18 ++ ] = V_30 ;
return;
}
V_2 -> V_22 -> V_34 . V_35 ++ ;
F_30 ( V_102 , & V_2 -> V_49 ) ;
}
}
}
}
static int F_86 ( struct V_60 * V_15 , struct V_139 * V_139 ,
unsigned int V_140 , unsigned long V_141 )
{
struct V_1 * V_2 = V_15 -> V_61 ;
unsigned int V_142 ;
int T_3 * V_44 = ( int T_3 * ) V_141 ;
if ( ! V_2 || V_2 -> V_57 != V_58 )
return - V_70 ;
switch ( V_140 ) {
case V_143 :
V_142 = strlen ( V_2 -> V_22 -> V_33 ) + 1 ;
if ( F_87 ( ( void T_3 * ) V_141 , V_2 -> V_22 -> V_33 , V_142 ) )
return - V_144 ;
return 0 ;
case V_145 :
if ( F_88 ( V_2 -> V_27 , V_44 ) )
return - V_144 ;
return 0 ;
case V_146 :
if ( F_89 ( V_142 , V_44 ) )
return - V_144 ;
#ifndef F_2
if ( V_142 & ( V_29 | V_28 ) )
return - V_70 ;
#else
if ( ( V_142 & ( V_28 | V_29 ) ) ==
( V_28 | V_29 ) )
V_142 &= ~ V_28 ;
#endif
#ifndef F_9
if ( V_142 & V_47 )
return - V_70 ;
#endif
V_2 -> V_27 = V_142 ;
V_2 -> V_22 -> type = V_86 + V_2 -> V_27 ;
return 0 ;
case V_147 :
return - V_70 ;
#ifdef F_33
case V_148 :
if ( F_89 ( V_142 , V_44 ) )
return - V_144 ;
if ( V_142 > 255 )
return - V_70 ;
F_6 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
V_2 -> V_124 = ( V_149 ) V_142 ;
if ( V_2 -> V_124 != 0 ) {
F_90 ( & V_2 -> V_109 ,
V_63 + V_2 -> V_124 * V_64 ) ;
F_30 ( V_135 , & V_2 -> V_49 ) ;
} else
F_91 ( & V_2 -> V_109 ) ;
F_7 ( & V_2 -> V_14 ) ;
return 0 ;
case V_150 :
if ( F_88 ( V_2 -> V_124 , V_44 ) )
return - V_144 ;
return 0 ;
case V_151 :
if ( F_89 ( V_142 , V_44 ) )
return - V_144 ;
if ( V_142 > 255 )
return - V_70 ;
F_6 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
V_2 -> V_126 = ( V_149 ) V_142 ;
if ( V_2 -> V_126 != 0 ) {
F_90 ( & V_2 -> V_112 ,
V_63 + V_2 -> V_126 * V_64 ) ;
F_30 ( V_53 , & V_2 -> V_49 ) ;
} else
F_91 ( & V_2 -> V_112 ) ;
F_7 ( & V_2 -> V_14 ) ;
return 0 ;
case V_152 :
if ( F_88 ( V_2 -> V_126 , V_44 ) )
return - V_144 ;
return 0 ;
#endif
default:
return F_92 ( V_15 , V_139 , V_140 , V_141 ) ;
}
}
static long F_93 ( struct V_60 * V_15 , struct V_139 * V_139 ,
unsigned int V_140 , unsigned long V_141 )
{
switch ( V_140 ) {
case V_143 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_150 :
case V_151 :
case V_152 :
return F_86 ( V_15 , V_139 , V_140 ,
( unsigned long ) F_94 ( V_141 ) ) ;
}
return - V_153 ;
}
static int F_95 ( struct V_23 * V_22 , struct V_154 * V_155 , int V_140 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
unsigned long * V_44 = ( unsigned long * ) & V_155 -> V_156 ;
if ( V_2 == NULL )
return - V_16 ;
F_6 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_15 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_16 ;
}
switch ( V_140 ) {
case V_148 :
if ( ( unsigned ) * V_44 > 255 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_70 ;
}
V_2 -> V_124 = ( V_149 ) * V_44 ;
if ( V_2 -> V_124 != 0 ) {
V_2 -> V_109 . V_125 =
V_63 + V_2 -> V_124 * V_64 ;
F_90 ( & V_2 -> V_109 ,
V_63 + V_2 -> V_124 * V_64 ) ;
F_30 ( V_135 , & V_2 -> V_49 ) ;
} else
F_91 ( & V_2 -> V_109 ) ;
break;
case V_150 :
* V_44 = V_2 -> V_124 ;
break;
case V_151 :
if ( ( unsigned ) * V_44 > 255 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_70 ;
}
V_2 -> V_126 = ( V_149 ) * V_44 ;
if ( V_2 -> V_126 != 0 ) {
F_90 ( & V_2 -> V_112 ,
V_63 + V_2 -> V_126 * V_64 ) ;
F_30 ( V_53 , & V_2 -> V_49 ) ;
} else
F_91 ( & V_2 -> V_112 ) ;
break;
case V_152 :
* V_44 = V_2 -> V_126 ;
break;
case V_157 :
if ( V_2 -> V_15 != V_120 -> signal -> V_15 &&
V_2 -> V_119 != V_120 -> V_119 ) {
F_7 ( & V_2 -> V_14 ) ;
return - V_115 ;
}
V_2 -> V_104 = 0 ;
if ( * V_44 )
V_2 -> V_104 = 1 ;
break;
case V_158 :
* V_44 = V_2 -> V_104 ;
}
F_7 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int T_4 F_96 ( void )
{
int V_159 ;
if ( V_103 < 4 )
V_103 = 4 ;
F_18 ( V_37 L_10
#ifdef F_9
L_11
#endif
L_12 ,
V_160 , V_103 ) ;
#if F_97 ( F_2 )
F_18 ( V_37 L_13 ) ;
#endif
#ifdef F_33
F_18 ( V_37 L_14 ) ;
#endif
V_90 = F_98 ( sizeof( struct V_23 * ) * V_103 ,
V_12 ) ;
if ( ! V_90 )
return - V_161 ;
V_159 = F_99 ( V_162 , & V_163 ) ;
if ( V_159 != 0 ) {
F_18 ( V_164 L_15 , V_159 ) ;
F_10 ( V_90 ) ;
}
return V_159 ;
}
static void T_5 F_100 ( void )
{
int V_88 ;
struct V_23 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_165 = V_63 + V_64 ;
int V_166 = 0 ;
if ( V_90 == NULL )
return;
do {
if ( V_166 )
F_101 ( 100 ) ;
V_166 = 0 ;
for ( V_88 = 0 ; V_88 < V_103 ; V_88 ++ ) {
V_22 = V_90 [ V_88 ] ;
if ( ! V_22 )
continue;
V_2 = F_41 ( V_22 ) ;
F_6 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 ) {
V_166 ++ ;
F_102 ( V_2 -> V_15 ) ;
}
F_7 ( & V_2 -> V_14 ) ;
}
} while ( V_166 && F_44 ( V_63 , V_165 ) );
for ( V_88 = 0 ; V_88 < V_103 ; V_88 ++ ) {
V_22 = V_90 [ V_88 ] ;
if ( ! V_22 )
continue;
V_90 [ V_88 ] = NULL ;
V_2 = F_41 ( V_22 ) ;
if ( V_2 -> V_15 ) {
F_18 ( V_164 L_16 ,
V_22 -> V_33 ) ;
V_22 -> V_93 = NULL ;
}
F_83 ( V_22 ) ;
}
F_10 ( V_90 ) ;
V_90 = NULL ;
V_88 = F_103 ( V_162 ) ;
if ( V_88 != 0 )
F_18 ( V_164 L_17 , V_88 ) ;
}
static void V_113 ( unsigned long V_167 )
{
struct V_1 * V_2 = (struct V_1 * ) V_167 ;
F_42 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL )
goto V_62;
if ( V_2 -> V_126 ) {
if ( F_76 ( V_53 , & V_2 -> V_49 ) ) {
#ifdef F_9
unsigned char V_128 = ( V_2 -> V_27 & V_47 ) ? 0x70 : V_131 ;
#else
unsigned char V_128 = V_131 ;
#endif
if ( ! F_43 ( V_2 -> V_22 ) ) {
V_2 -> V_15 -> V_50 -> V_51 ( V_2 -> V_15 , & V_128 , 1 ) ;
}
} else
F_30 ( V_53 , & V_2 -> V_49 ) ;
F_90 ( & V_2 -> V_112 , V_63 + V_2 -> V_126 * V_64 ) ;
}
V_62:
F_47 ( & V_2 -> V_14 ) ;
}
static void V_111 ( unsigned long V_167 )
{
struct V_1 * V_2 = (struct V_1 * ) V_167 ;
F_42 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL )
goto V_62;
if ( V_2 -> V_124 ) {
if ( F_76 ( V_135 , & V_2 -> V_49 ) ) {
if ( V_2 -> V_126 )
( void ) F_91 ( & V_2 -> V_112 ) ;
F_18 ( V_168 L_18 , V_2 -> V_22 -> V_33 ) ;
F_102 ( V_2 -> V_15 ) ;
goto V_62;
} else
F_30 ( V_135 , & V_2 -> V_49 ) ;
F_90 ( & V_2 -> V_109 , V_63 + V_2 -> V_124 * V_64 ) ;
}
V_62:
F_47 ( & V_2 -> V_14 ) ;
}
