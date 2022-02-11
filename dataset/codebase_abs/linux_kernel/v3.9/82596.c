static inline void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
if ( V_3 ) {
( (struct V_4 * ) V_2 -> V_5 ) -> V_6 = 1 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile T_1 V_8 ;
V_8 = * ( volatile T_1 * ) ( V_2 -> V_5 ) ;
}
#endif
}
static inline void F_4 ( struct V_1 * V_2 , int V_9 , volatile void * V_10 )
{
#ifdef F_2
if ( V_3 ) {
struct V_4 * V_11 = (struct V_4 * ) ( V_2 -> V_5 ) ;
V_11 -> V_12 = ( ( V_9 ) | ( T_1 ) ( V_10 ) ) & 0xffff ;
V_11 -> V_13 = ( ( V_9 ) | ( T_1 ) ( V_10 ) ) >> 16 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
T_1 V_14 = ( T_1 ) ( V_9 ) | ( T_1 ) ( V_10 ) ;
V_14 = ( ( T_1 ) ( V_14 ) << 16 ) | ( ( T_1 ) ( V_14 ) >> 16 ) ;
* ( volatile T_1 * ) V_2 -> V_5 = V_14 ;
F_5 ( 1 ) ;
* ( volatile T_1 * ) V_2 -> V_5 = V_14 ;
}
#endif
}
static inline int F_6 ( struct V_1 * V_2 , struct V_15 * V_16 , int V_17 , char * V_18 )
{
while ( -- V_17 && V_16 -> V_19 . V_20 )
F_5 ( 10 ) ;
if ( ! V_17 ) {
F_7 ( V_21 L_1 ,
V_2 -> V_22 , V_18 , V_16 -> V_23 . V_24 , V_16 -> V_23 . V_25 ) ;
return - 1 ;
}
else
return 0 ;
}
static inline int F_8 ( struct V_1 * V_2 , struct V_15 * V_16 , int V_17 , char * V_18 )
{
while ( -- V_17 && V_16 -> V_23 . V_25 )
F_5 ( 10 ) ;
if ( ! V_17 ) {
F_7 ( V_21 L_1 ,
V_2 -> V_22 , V_18 , V_16 -> V_23 . V_24 , V_16 -> V_23 . V_25 ) ;
return - 1 ;
}
else
return 0 ;
}
static inline int F_9 ( struct V_1 * V_2 , struct V_26 * V_27 , int V_17 , char * V_18 )
{
volatile struct V_26 * V_9 = V_27 ;
while ( -- V_17 && V_9 -> V_25 )
F_5 ( 10 ) ;
if ( ! V_17 ) {
F_7 ( V_21 L_2 , V_2 -> V_22 , V_18 ) ;
return - 1 ;
}
else
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
struct V_26 * V_27 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
F_7 ( V_21 L_3 ,
& V_16 -> V_33 , V_16 -> V_33 . V_34 , V_16 -> V_33 . V_19 ) ;
F_7 ( V_21 L_4 ,
& V_16 -> V_19 , V_16 -> V_19 . V_20 , V_16 -> V_19 . V_23 ) ;
F_7 ( V_21 L_5
L_6 ,
& V_16 -> V_23 , V_16 -> V_23 . V_24 , V_16 -> V_23 . V_25 ,
V_16 -> V_23 . V_27 , V_16 -> V_23 . V_30 ) ;
F_7 ( V_21 L_7
L_8 ,
V_16 -> V_23 . V_35 , V_16 -> V_23 . V_36 , V_16 -> V_23 . V_37 ,
V_16 -> V_23 . V_38 , V_16 -> V_23 . V_39 , V_16 -> V_23 . V_40 ) ;
V_27 = V_16 -> V_41 ;
while ( V_27 != V_42 ) {
F_7 ( V_21 L_9 ,
V_27 , V_27 -> V_24 , V_27 -> V_25 , V_27 -> V_43 ) ;
V_27 = V_27 -> V_44 ;
}
V_30 = V_16 -> V_45 ;
F_7 ( V_21 L_10 , V_30 ) ;
do {
F_7 ( V_21 L_11
L_12 ,
V_30 , V_30 -> V_20 , V_30 -> V_27 , V_30 -> V_43 , V_30 -> V_32 ,
V_30 -> V_46 ) ;
V_30 = V_30 -> V_44 ;
} while ( V_30 != V_16 -> V_45 );
V_32 = V_16 -> V_47 ;
F_7 ( V_21 L_13 , V_32 ) ;
do {
F_7 ( V_21 L_14 ,
V_32 , V_32 -> V_46 , V_32 -> V_43 , V_32 -> V_48 , V_32 -> V_49 ) ;
V_32 = V_32 -> V_44 ;
} while ( V_32 != V_16 -> V_47 );
}
static T_2 F_11 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_52 = ( unsigned char * ) 0xfff42000 ;
V_52 [ 0x28 ] = 1 ;
V_52 [ 0x2b ] = 0x1d ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_53 = ( unsigned char * ) V_54 ;
* V_53 = 1 ;
* V_53 = 3 ;
}
#endif
F_7 ( V_21 L_15 , V_2 -> V_22 ) ;
F_10 ( V_2 ) ;
return V_55 ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
struct V_31 * V_32 ;
int V_8 ;
for ( V_8 = 0 , V_32 = V_16 -> V_56 ; V_8 < V_57 ; V_8 ++ , V_32 ++ ) {
if ( V_32 -> V_58 == NULL )
break;
F_13 ( V_32 -> V_58 ) ;
V_32 -> V_58 = NULL ;
}
}
static inline int F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_8 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
for ( V_8 = 0 , V_32 = V_16 -> V_56 ; V_8 < V_57 ; V_8 ++ , V_32 ++ ) {
struct V_59 * V_58 = F_15 ( V_2 , V_60 ) ;
if ( V_58 == NULL ) {
F_12 ( V_2 ) ;
return - V_61 ;
}
V_32 -> V_44 = V_32 + 1 ;
V_32 -> V_43 = F_16 ( F_17 ( V_32 + 1 ) ) ;
V_32 -> V_62 = F_16 ( F_17 ( V_32 ) ) ;
V_32 -> V_58 = V_58 ;
V_32 -> V_63 = V_58 -> V_64 ;
V_32 -> V_48 = F_18 ( F_17 ( V_58 -> V_64 ) ) ;
V_32 -> V_49 = V_60 ;
#ifdef F_19
F_20 ( F_21 ( V_58 -> V_64 ) , V_60 ) ;
#endif
}
V_16 -> V_47 = V_16 -> V_56 ;
V_32 = V_16 -> V_56 + V_57 - 1 ;
V_32 -> V_44 = V_16 -> V_56 ;
V_32 -> V_43 = F_16 ( F_17 ( V_16 -> V_56 ) ) ;
for ( V_8 = 0 , V_30 = V_16 -> V_65 ; V_8 < V_57 ; V_8 ++ , V_30 ++ ) {
V_30 -> V_32 = V_42 ;
V_30 -> V_44 = V_30 + 1 ;
V_30 -> V_66 = V_30 - 1 ;
V_30 -> V_43 = F_22 ( F_17 ( V_30 + 1 ) ) ;
V_30 -> V_27 = V_67 ;
}
V_16 -> V_45 = V_16 -> V_65 ;
V_16 -> V_23 . V_30 = F_22 ( F_17 ( V_16 -> V_65 ) ) ;
V_30 = V_16 -> V_65 ;
V_30 -> V_32 = V_16 -> V_47 ;
V_30 -> V_66 = V_16 -> V_65 + V_57 - 1 ;
V_30 = V_16 -> V_65 + V_57 - 1 ;
V_30 -> V_44 = V_16 -> V_65 ;
V_30 -> V_43 = F_22 ( F_17 ( V_16 -> V_65 ) ) ;
V_30 -> V_27 = V_68 | V_67 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_57 ; V_8 ++ ) {
V_16 -> V_65 [ V_8 ] . V_32 = V_42 ;
V_16 -> V_65 [ V_8 ] . V_27 = V_67 ;
}
V_16 -> V_65 [ V_57 - 1 ] . V_27 = V_68 | V_67 ;
V_16 -> V_45 = V_16 -> V_65 ;
V_16 -> V_23 . V_30 = F_22 ( F_17 ( V_16 -> V_65 ) ) ;
V_16 -> V_47 = V_16 -> V_56 ;
V_16 -> V_65 [ 0 ] . V_32 = F_16 ( F_17 ( V_16 -> V_56 ) ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
unsigned long V_69 ;
F_4 ( V_2 , V_70 , NULL ) ;
F_5 ( 100 ) ;
#if F_25 ( F_2 ) || F_25 ( F_3 )
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_52 = ( unsigned char * ) 0xfff42000 ;
V_52 [ 0x28 ] = 1 ;
V_52 [ 0x2a ] = 0x48 ;
V_52 [ 0x2b ] = 0x08 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_53 = ( unsigned char * ) V_54 ;
* V_53 = 1 ;
}
#endif
F_4 ( V_2 , V_71 , ( void * ) F_17 ( ( void * ) & V_16 -> V_33 ) ) ;
#endif
V_16 -> V_72 = V_73 ;
#ifdef F_2
if ( V_3 )
V_16 -> V_33 . V_34 = 0x00000054 ;
#endif
#ifdef F_3
if ( V_7 )
V_16 -> V_33 . V_34 = 0x0000004c ;
#endif
V_16 -> V_33 . V_19 = F_26 ( F_17 ( ( void * ) & V_16 -> V_19 ) ) ;
V_16 -> V_19 . V_23 = F_27 ( F_17 ( ( void * ) & V_16 -> V_23 ) ) ;
V_16 -> V_19 . V_20 = V_74 ;
V_16 -> V_75 = 0 ;
V_16 -> V_41 = V_16 -> V_23 . V_27 = V_42 ;
#ifdef F_3
if ( V_7 ) {
V_16 -> V_23 . V_76 = 7 * 25 ;
V_16 -> V_23 . V_77 = 1 * 25 ;
}
#endif
F_28 ( V_78 , F_7 ( V_79 L_16 , V_2 -> V_22 ) ) ;
F_1 ( V_2 ) ;
if ( F_6 ( V_2 , V_16 , 1000 , L_17 ) )
goto V_80;
F_28 ( V_78 , F_7 ( V_79 L_18 , V_2 -> V_22 ) ) ;
F_23 ( V_2 ) ;
V_16 -> V_23 . V_25 = 0 ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_52 = ( unsigned char * ) 0xfff42000 ;
V_52 [ 0x2a ] = 0x55 ;
V_52 [ 0x2b ] = 0x15 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_53 = ( unsigned char * ) V_54 ;
* V_53 = 3 ;
}
#endif
F_28 ( V_78 , F_7 ( V_79 L_19 , V_2 -> V_22 ) ) ;
memcpy ( V_16 -> V_81 . V_82 , V_83 , 14 ) ;
V_16 -> V_81 . V_27 . V_25 = V_84 ;
F_29 ( V_2 , & V_16 -> V_81 . V_27 ) ;
F_28 ( V_78 , F_7 ( V_79 L_20 , V_2 -> V_22 ) ) ;
memcpy ( V_16 -> V_85 . V_86 , V_2 -> V_87 , 6 ) ;
V_16 -> V_85 . V_27 . V_25 = V_88 ;
F_29 ( V_2 , & V_16 -> V_85 . V_27 ) ;
F_28 ( V_78 , F_7 ( V_79 L_21 , V_2 -> V_22 ) ) ;
V_16 -> V_89 . V_27 . V_25 = V_90 ;
F_29 ( V_2 , & V_16 -> V_89 . V_27 ) ;
F_30 ( & V_16 -> V_91 , V_69 ) ;
if ( F_8 ( V_2 , V_16 , 1000 , L_22 ) ) {
F_31 ( & V_16 -> V_91 , V_69 ) ;
goto V_80;
}
F_28 ( V_78 , F_7 ( V_79 L_23 , V_2 -> V_22 ) ) ;
V_16 -> V_23 . V_25 = V_92 ;
F_1 ( V_2 ) ;
F_31 ( & V_16 -> V_91 , V_69 ) ;
if ( F_8 ( V_2 , V_16 , 1000 , L_24 ) )
goto V_80;
F_28 ( V_78 , F_7 ( V_79 L_25 , V_2 -> V_22 ) ) ;
return 0 ;
V_80:
F_7 ( V_93 L_26 , V_2 -> V_22 ) ;
F_4 ( V_2 , V_70 , NULL ) ;
return - 1 ;
}
static inline int F_32 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_94 = 0 ;
F_28 ( V_95 , F_7 ( V_79 L_27 ,
V_16 -> V_45 , V_16 -> V_47 ) ) ;
V_30 = V_16 -> V_45 ;
while ( ( V_30 -> V_20 ) & V_96 ) {
if ( V_30 -> V_32 == V_42 )
V_32 = V_42 ;
else if ( V_30 -> V_32 == V_16 -> V_47 -> V_62 )
V_32 = V_16 -> V_47 ;
else {
F_7 ( V_93 L_28 , V_2 -> V_22 ) ;
V_32 = V_42 ;
}
F_28 ( V_95 , F_7 ( V_79 L_29 ,
V_30 , V_30 -> V_32 , V_30 -> V_20 ) ) ;
if ( V_32 != V_42 && ( ( V_30 -> V_20 ) & V_97 ) ) {
int V_98 = V_32 -> V_46 & 0x3fff ;
struct V_59 * V_58 = V_32 -> V_58 ;
int V_99 = 0 ;
F_28 ( V_100 , F_33 ( V_32 -> V_63 , L_30 ) ) ;
V_94 ++ ;
if ( V_98 > V_101 ) {
struct V_59 * V_102 ;
V_102 = F_15 ( V_2 , V_60 ) ;
if ( V_102 == NULL ) {
V_58 = NULL ;
goto V_103;
}
F_34 ( V_58 , V_98 ) ;
V_99 = 1 ;
V_32 -> V_58 = V_102 ;
V_32 -> V_63 = V_102 -> V_64 ;
V_32 -> V_48 = F_18 ( F_17 ( V_102 -> V_64 ) ) ;
#ifdef F_19
F_20 ( F_21 ( V_102 -> V_64 ) , V_60 ) ;
#endif
}
else
V_58 = F_15 ( V_2 , V_98 + 2 ) ;
V_103:
if ( V_58 == NULL ) {
F_7 ( V_104 L_31 , V_2 -> V_22 ) ;
V_2 -> V_105 . V_106 ++ ;
}
else {
if ( ! V_99 ) {
F_35 ( V_58 , 2 ) ;
memcpy ( F_34 ( V_58 , V_98 ) , V_32 -> V_63 , V_98 ) ;
}
V_58 -> V_107 = F_36 ( V_58 , V_2 ) ;
V_58 -> V_108 = V_98 ;
#ifdef F_19
F_20 ( F_21 ( V_32 -> V_58 -> V_64 ) ,
V_98 ) ;
#endif
F_37 ( V_58 ) ;
V_2 -> V_105 . V_109 ++ ;
V_2 -> V_105 . V_110 += V_98 ;
}
}
else {
F_28 ( V_111 , F_7 ( V_79 L_32 ,
V_2 -> V_22 , V_30 -> V_20 ) ) ;
V_2 -> V_105 . V_112 ++ ;
if ( ( V_30 -> V_20 ) & 0x0001 )
V_2 -> V_105 . V_113 ++ ;
if ( ( V_30 -> V_20 ) & 0x0080 )
V_2 -> V_105 . V_114 ++ ;
if ( ( V_30 -> V_20 ) & 0x0100 )
V_2 -> V_105 . V_115 ++ ;
if ( ( V_30 -> V_20 ) & 0x0200 )
V_2 -> V_105 . V_116 ++ ;
if ( ( V_30 -> V_20 ) & 0x0400 )
V_2 -> V_105 . V_117 ++ ;
if ( ( V_30 -> V_20 ) & 0x0800 )
V_2 -> V_105 . V_118 ++ ;
if ( ( V_30 -> V_20 ) & 0x1000 )
V_2 -> V_105 . V_114 ++ ;
}
if ( V_32 != V_42 && ( V_32 -> V_46 & 0x4000 ) ) {
V_32 -> V_46 = 0 ;
V_16 -> V_47 = V_32 -> V_44 ;
}
V_30 -> V_32 = V_42 ;
V_30 -> V_20 = 0 ;
V_30 -> V_27 = V_68 | V_67 ;
V_30 -> V_46 = 0 ;
V_30 -> V_66 -> V_27 = V_67 ;
V_16 -> V_23 . V_30 = V_30 -> V_43 ;
V_16 -> V_45 = V_30 -> V_44 ;
V_30 = V_16 -> V_45 ;
}
F_28 ( V_95 , F_7 ( V_79 L_33 , V_94 ) ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_26 * V_119 ;
while ( V_16 -> V_41 != V_42 ) {
V_119 = V_16 -> V_41 ;
V_16 -> V_41 = V_119 -> V_44 ;
V_16 -> V_75 -- ;
switch ( ( V_119 -> V_25 ) & 0x7 ) {
case V_120 :
{
struct V_121 * V_121 = (struct V_121 * ) V_119 ;
struct V_59 * V_58 = V_121 -> V_58 ;
F_13 ( V_58 ) ;
V_2 -> V_105 . V_122 ++ ;
V_2 -> V_105 . V_123 ++ ;
V_119 -> V_44 = V_119 -> V_43 = V_42 ;
V_121 -> V_27 . V_25 = 0 ;
break;
}
default:
V_119 -> V_44 = V_119 -> V_43 = V_42 ;
}
}
F_8 ( V_2 , V_16 , 100 , L_34 ) ;
V_16 -> V_23 . V_27 = V_42 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_124 )
{
unsigned long V_69 ;
F_28 ( V_125 , F_7 ( V_79 L_35 ) ) ;
F_30 ( & V_16 -> V_91 , V_69 ) ;
F_8 ( V_2 , V_16 , 100 , L_36 ) ;
F_40 ( V_2 ) ;
V_16 -> V_23 . V_25 = V_126 | V_127 ;
F_1 ( V_2 ) ;
F_8 ( V_2 , V_16 , 1000 , L_37 ) ;
F_31 ( & V_16 -> V_91 , V_69 ) ;
F_38 ( V_2 , V_16 ) ;
F_32 ( V_2 ) ;
F_41 ( V_2 ) ;
F_24 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_124 = V_2 -> V_5 ;
unsigned long V_69 ;
F_28 ( V_128 , F_7 ( V_79 L_38 ) ) ;
V_27 -> V_24 = 0 ;
V_27 -> V_25 |= ( V_68 | V_129 ) ;
V_27 -> V_44 = V_27 -> V_43 = V_42 ;
F_30 ( & V_16 -> V_91 , V_69 ) ;
if ( V_16 -> V_41 != V_42 ) {
V_16 -> V_130 -> V_44 = V_27 ;
V_16 -> V_130 -> V_43 = F_42 ( F_17 ( & V_27 -> V_24 ) ) ;
} else {
V_16 -> V_41 = V_27 ;
F_8 ( V_2 , V_16 , 100 , L_39 ) ;
V_16 -> V_23 . V_27 = F_42 ( F_17 ( & V_27 -> V_24 ) ) ;
V_16 -> V_23 . V_25 = V_131 ;
F_1 ( V_2 ) ;
}
V_16 -> V_130 = V_27 ;
V_16 -> V_75 ++ ;
F_31 ( & V_16 -> V_91 , V_69 ) ;
if ( V_16 -> V_75 > V_132 ) {
unsigned long V_133 = V_73 - V_16 -> V_72 ;
if ( V_133 < V_134 )
return;
F_7 ( V_135 L_40 , V_2 -> V_22 ) ;
F_39 ( V_2 , V_16 , V_124 ) ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
int V_136 = 0 ;
F_28 ( V_137 , F_7 ( V_79 L_41 , V_2 -> V_22 , V_2 -> V_50 ) ) ;
if ( F_44 ( V_2 -> V_50 , V_138 , 0 , L_42 , V_2 ) ) {
F_7 ( V_21 L_43 , V_2 -> V_22 , V_2 -> V_50 ) ;
return - V_139 ;
}
#ifdef F_2
if ( V_3 ) {
if ( F_44 ( 0x56 , F_11 , 0 , L_44 , V_2 ) ) {
V_136 = - V_139 ;
goto V_140;
}
}
#endif
V_136 = F_14 ( V_2 ) ;
if ( V_136 )
goto V_141;
F_41 ( V_2 ) ;
if ( F_24 ( V_2 ) ) {
V_136 = - V_139 ;
goto V_142;
}
return 0 ;
V_142:
F_40 ( V_2 ) ;
F_12 ( V_2 ) ;
V_141:
#ifdef F_2
F_45 ( 0x56 , V_2 ) ;
V_140:
#endif
F_45 ( V_2 -> V_50 , V_2 ) ;
return V_136 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_124 = V_2 -> V_5 ;
F_28 ( V_111 , F_7 ( V_21 L_45 ,
V_2 -> V_22 ) ) ;
V_2 -> V_105 . V_122 ++ ;
if ( V_16 -> V_143 == V_2 -> V_105 . V_144 ) {
F_28 ( V_111 , F_7 ( V_21 L_46 ) ) ;
F_39 ( V_2 , V_16 , V_124 ) ;
} else {
F_28 ( V_111 , F_7 ( V_21 L_47 ) ) ;
V_16 -> V_23 . V_25 = V_131 | V_92 ;
F_1 ( V_2 ) ;
V_16 -> V_143 = V_2 -> V_105 . V_144 ;
}
V_2 -> V_145 = V_73 ;
F_47 ( V_2 ) ;
}
static T_3 F_48 ( struct V_59 * V_58 , struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
struct V_121 * V_121 ;
struct V_146 * V_147 ;
short V_148 = V_58 -> V_108 ;
F_28 ( V_149 , F_7 ( V_79 L_48 ,
V_2 -> V_22 , V_58 -> V_108 , V_58 -> V_64 ) ) ;
if ( V_58 -> V_108 < V_150 ) {
if ( F_49 ( V_58 , V_150 ) )
return V_151 ;
V_148 = V_150 ;
}
F_40 ( V_2 ) ;
V_121 = V_16 -> V_152 + V_16 -> V_153 ;
V_147 = V_16 -> V_154 + V_16 -> V_153 ;
if ( V_121 -> V_27 . V_25 ) {
F_7 ( V_135 L_49 ,
V_2 -> V_22 ) ;
V_2 -> V_105 . V_155 ++ ;
F_13 ( V_58 ) ;
} else {
if ( ++ V_16 -> V_153 == V_156 )
V_16 -> V_153 = 0 ;
V_121 -> V_147 = F_50 ( F_17 ( V_147 ) ) ;
V_147 -> V_157 = V_42 ;
V_121 -> V_27 . V_25 = V_67 | V_120 ;
V_121 -> V_58 = V_58 ;
V_121 -> V_158 = 0 ;
V_121 -> V_49 = 0 ;
V_147 -> V_158 = 0 ;
V_147 -> V_49 = V_159 | V_148 ;
V_147 -> V_64 = F_18 ( F_17 ( V_58 -> V_64 ) ) ;
#ifdef F_19
F_51 ( F_21 ( V_58 -> V_64 ) , V_148 ) ;
#endif
F_28 ( V_160 , F_33 ( V_58 -> V_64 , L_50 ) ) ;
F_29 ( V_2 , & V_121 -> V_27 ) ;
V_2 -> V_105 . V_144 ++ ;
V_2 -> V_105 . V_161 += V_148 ;
}
F_41 ( V_2 ) ;
return V_151 ;
}
static void F_33 ( unsigned char * V_162 , char * V_18 )
{
F_7 ( V_79 L_51 ,
V_162 , V_162 + 6 , V_162 , V_162 [ 12 ] , V_162 [ 13 ] , V_18 ) ;
}
struct V_1 * T_4 F_52 ( int V_163 )
{
struct V_1 * V_2 ;
int V_8 ;
struct V_15 * V_16 ;
char V_86 [ 8 ] ;
static int V_164 ;
int V_165 ;
if ( V_164 )
return F_53 ( - V_166 ) ;
V_164 ++ ;
V_2 = F_54 ( 0 ) ;
if ( ! V_2 )
return F_53 ( - V_61 ) ;
if ( V_163 >= 0 ) {
sprintf ( V_2 -> V_22 , L_52 , V_163 ) ;
F_55 ( V_2 ) ;
} else {
V_2 -> V_5 = V_167 ;
V_2 -> V_50 = V_50 ;
}
#ifdef F_2
if ( V_3 ) {
if ( V_168 & V_169 ) {
F_7 ( V_135 L_53 ) ;
V_165 = - V_166 ;
goto V_170;
}
memcpy ( V_86 , ( void * ) 0xfffc1f2c , 6 ) ;
V_2 -> V_5 = V_171 ;
V_2 -> V_50 = ( unsigned ) V_172 ;
goto V_173;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_174 = ( unsigned char * ) V_175 ;
unsigned char V_176 = V_174 [ 3 ] ;
int V_8 ;
V_174 [ 3 ] |= 0x80 ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ )
V_86 [ V_8 ] = V_174 [ V_8 * 4 + 7 ] ;
V_174 [ 3 ] = V_176 ;
V_2 -> V_5 = V_177 ;
V_2 -> V_50 = ( unsigned ) V_178 ;
goto V_173;
}
#endif
V_165 = - V_166 ;
goto V_170;
V_173:
V_2 -> V_179 = ( int ) F_56 ( V_180 , 0 ) ;
if ( ! V_2 -> V_179 ) {
V_165 = - V_61 ;
goto V_181;
}
F_28 ( V_182 , F_7 ( V_183 L_54 , V_2 -> V_22 , V_2 -> V_5 ) ) ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ )
F_28 ( V_182 , F_7 ( L_55 , V_2 -> V_87 [ V_8 ] = V_86 [ V_8 ] ) ) ;
F_28 ( V_182 , F_7 ( L_56 , V_2 -> V_50 ) ) ;
F_28 ( V_182 , F_7 ( V_183 L_57 , V_184 ) ) ;
V_2 -> V_185 = & V_186 ;
V_2 -> V_187 = V_188 ;
V_2 -> V_28 = ( void * ) ( V_2 -> V_179 ) ;
V_16 = V_2 -> V_28 ;
F_28 ( V_78 , F_7 ( V_79 L_58
L_59 ,
V_2 -> V_22 , ( unsigned long ) V_16 ,
sizeof( struct V_15 ) , ( unsigned long ) & V_16 -> V_23 ) ) ;
memset ( ( void * ) V_16 , 0 , sizeof( struct V_15 ) ) ;
#ifdef F_19
F_51 ( F_21 ( ( void * ) ( V_2 -> V_179 ) ) , 4096 ) ;
F_20 ( F_21 ( ( void * ) ( V_2 -> V_179 ) ) , 4096 ) ;
F_57 ( ( void * ) ( V_2 -> V_179 ) , 4096 , V_189 ) ;
#endif
V_16 -> V_23 . V_25 = 0 ;
V_16 -> V_23 . V_27 = V_42 ;
V_16 -> V_23 . V_30 = V_42 ;
F_58 ( & V_16 -> V_91 ) ;
V_165 = F_59 ( V_2 ) ;
if ( V_165 )
goto V_190;
return V_2 ;
V_190:
#ifdef F_19
F_57 ( ( void * ) ( V_2 -> V_179 ) , 4096 ,
V_191 ) ;
#endif
F_60 ( ( T_1 ) ( V_2 -> V_179 ) ) ;
V_181:
V_170:
F_61 ( V_2 ) ;
return F_53 ( V_165 ) ;
}
static T_2 V_138 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_15 * V_16 ;
short V_124 ;
unsigned short V_24 , V_192 = 0 ;
int V_193 = 0 ;
#ifdef F_3
if ( V_7 ) {
if ( * ( char * ) V_194 & V_195 ) {
F_11 ( V_50 , V_51 ) ;
return V_55 ;
}
}
#endif
if ( V_2 == NULL ) {
F_7 ( V_21 L_60 , V_50 ) ;
return V_196 ;
}
V_124 = V_2 -> V_5 ;
V_16 = V_2 -> V_28 ;
F_62 ( & V_16 -> V_91 ) ;
F_8 ( V_2 , V_16 , 100 , L_61 ) ;
V_24 = V_16 -> V_23 . V_24 ;
F_28 ( V_197 , F_7 ( V_79 L_62 ,
V_2 -> V_22 , V_50 , V_24 ) ) ;
V_192 = V_24 & 0xf000 ;
if ( ( V_24 & 0x8000 ) || ( V_24 & 0x2000 ) ) {
struct V_26 * V_119 ;
V_193 = 1 ;
if ( ( V_24 & 0x8000 ) )
F_28 ( V_197 , F_7 ( V_79 L_63 , V_2 -> V_22 ) ) ;
if ( ( V_24 & 0x2000 ) )
F_28 ( V_197 , F_7 ( V_79 L_64 , V_2 -> V_22 , V_24 & 0x0700 ) ) ;
while ( ( V_16 -> V_41 != V_42 ) && ( V_16 -> V_41 -> V_24 & V_96 ) ) {
V_119 = V_16 -> V_41 ;
F_28 ( V_198 , F_7 ( V_79 L_65 ,
V_16 -> V_41 -> V_24 , V_16 -> V_41 -> V_25 ) ) ;
V_16 -> V_41 = V_119 -> V_44 ;
V_16 -> V_75 -- ;
switch ( ( V_119 -> V_25 ) & 0x7 ) {
case V_120 :
{
struct V_121 * V_121 = (struct V_121 * ) V_119 ;
struct V_59 * V_58 = V_121 -> V_58 ;
if ( ( V_119 -> V_24 ) & V_97 ) {
F_28 ( V_160 , F_33 ( V_58 -> V_64 , L_66 ) ) ;
} else {
V_2 -> V_105 . V_122 ++ ;
if ( ( V_119 -> V_24 ) & 0x0020 )
V_2 -> V_105 . V_113 ++ ;
if ( ! ( ( V_119 -> V_24 ) & 0x0040 ) )
V_2 -> V_105 . V_199 ++ ;
if ( ( V_119 -> V_24 ) & 0x0400 )
V_2 -> V_105 . V_200 ++ ;
if ( ( V_119 -> V_24 ) & 0x0800 )
V_2 -> V_105 . V_113 ++ ;
if ( ( V_119 -> V_24 ) & 0x1000 )
V_2 -> V_105 . V_123 ++ ;
}
F_63 ( V_58 ) ;
V_121 -> V_27 . V_25 = 0 ;
break;
}
case V_90 :
{
unsigned short V_24 = ( (struct V_89 * ) V_119 ) -> V_24 ;
if ( V_24 & 0x8000 ) {
F_28 ( V_201 , F_7 ( V_183 L_67 , V_2 -> V_22 ) ) ;
} else {
if ( V_24 & 0x4000 )
F_7 ( V_21 L_68 , V_2 -> V_22 ) ;
if ( V_24 & 0x2000 )
F_7 ( V_21 L_69 , V_2 -> V_22 ) ;
if ( V_24 & 0x1000 )
F_7 ( V_21 L_70 , V_2 -> V_22 ) ;
F_28 ( V_201 , F_7 ( V_183 L_71 , V_2 -> V_22 , V_24 & 0x07ff ) ) ;
}
break;
}
case V_84 :
case V_202 :
V_119 -> V_25 = 0 ;
break;
}
V_119 -> V_44 = V_119 -> V_43 = V_42 ;
V_16 -> V_72 = V_73 ;
}
V_119 = V_16 -> V_41 ;
while ( ( V_119 != V_42 ) && ( V_119 != V_16 -> V_130 ) ) {
V_119 -> V_25 &= 0x1fff ;
V_119 = V_119 -> V_44 ;
}
if ( ( V_16 -> V_41 != V_42 ) )
V_192 |= V_131 ;
V_16 -> V_23 . V_27 = F_42 ( F_17 ( & V_16 -> V_41 -> V_24 ) ) ;
}
if ( ( V_24 & 0x1000 ) || ( V_24 & 0x4000 ) ) {
if ( ( V_24 & 0x4000 ) )
F_28 ( V_197 , F_7 ( V_79 L_72 , V_2 -> V_22 ) ) ;
F_32 ( V_2 ) ;
if ( V_24 & 0x1000 ) {
if ( F_64 ( V_2 ) ) {
F_28 ( V_111 , F_7 ( V_21 L_73 , V_2 -> V_22 , V_24 ) ) ;
V_192 |= V_92 ;
V_2 -> V_105 . V_112 ++ ;
V_2 -> V_105 . V_116 ++ ;
F_23 ( V_2 ) ;
}
}
}
F_8 ( V_2 , V_16 , 100 , L_61 ) ;
V_16 -> V_23 . V_25 = V_192 ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_52 = ( unsigned char * ) 0xfff42000 ;
V_52 [ 0x2a ] |= 0x08 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_53 = ( unsigned char * ) V_54 ;
* V_53 = 1 ;
* V_53 = 3 ;
}
#endif
F_1 ( V_2 ) ;
F_28 ( V_197 , F_7 ( V_79 L_74 , V_2 -> V_22 ) ) ;
F_65 ( & V_16 -> V_91 ) ;
return F_66 ( V_193 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
unsigned long V_69 ;
F_40 ( V_2 ) ;
F_28 ( V_78 , F_7 ( V_79 L_75 ,
V_2 -> V_22 , V_16 -> V_23 . V_24 ) ) ;
F_30 ( & V_16 -> V_91 , V_69 ) ;
F_8 ( V_2 , V_16 , 100 , L_76 ) ;
V_16 -> V_23 . V_25 = V_126 | V_127 ;
F_1 ( V_2 ) ;
F_8 ( V_2 , V_16 , 100 , L_77 ) ;
F_31 ( & V_16 -> V_91 , V_69 ) ;
F_28 ( V_203 , F_10 ( V_2 ) ) ;
F_38 ( V_2 , V_16 ) ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_52 = ( unsigned char * ) 0xfff42000 ;
V_52 [ 0x28 ] = 1 ;
V_52 [ 0x2a ] = 0x40 ;
V_52 [ 0x2b ] = 0x40 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_53 = ( unsigned char * ) V_54 ;
* V_53 = 1 ;
}
#endif
#ifdef F_2
F_45 ( 0x56 , V_2 ) ;
#endif
F_45 ( V_2 -> V_50 , V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_204 = 0 , V_205 ;
F_28 ( V_206 , F_7 ( V_79 L_78 ,
V_2 -> V_22 , F_69 ( V_2 ) ,
V_2 -> V_69 & V_207 ? L_79 : L_80 ,
V_2 -> V_69 & V_208 ? L_79 : L_80 ) ) ;
if ( F_9 ( V_2 , & V_16 -> V_81 . V_27 , 1000 , L_81 ) )
return;
if ( ( V_2 -> V_69 & V_207 ) && ! ( V_16 -> V_81 . V_82 [ 8 ] & 0x01 ) ) {
V_16 -> V_81 . V_82 [ 8 ] |= 0x01 ;
V_204 = 1 ;
}
if ( ! ( V_2 -> V_69 & V_207 ) && ( V_16 -> V_81 . V_82 [ 8 ] & 0x01 ) ) {
V_16 -> V_81 . V_82 [ 8 ] &= ~ 0x01 ;
V_204 = 1 ;
}
if ( ( V_2 -> V_69 & V_208 ) && ( V_16 -> V_81 . V_82 [ 11 ] & 0x20 ) ) {
V_16 -> V_81 . V_82 [ 11 ] &= ~ 0x20 ;
V_204 = 1 ;
}
if ( ! ( V_2 -> V_69 & V_208 ) && ! ( V_16 -> V_81 . V_82 [ 11 ] & 0x20 ) ) {
V_16 -> V_81 . V_82 [ 11 ] |= 0x20 ;
V_204 = 1 ;
}
if ( V_204 ) {
V_16 -> V_81 . V_27 . V_25 = V_84 ;
F_29 ( V_2 , & V_16 -> V_81 . V_27 ) ;
}
V_205 = F_69 ( V_2 ) ;
if ( V_205 > V_209 )
{
V_205 = V_209 ;
F_7 ( V_21 L_82 ,
V_2 -> V_22 , V_205 ) ;
}
if ( ! F_70 ( V_2 ) ) {
struct V_210 * V_211 ;
unsigned char * V_212 ;
struct V_213 * V_27 ;
if ( F_9 ( V_2 , & V_16 -> V_213 . V_27 , 1000 , L_83 ) )
return;
V_27 = & V_16 -> V_213 ;
V_27 -> V_27 . V_25 = V_202 ;
V_27 -> V_214 = V_205 * V_215 ;
V_212 = V_27 -> V_216 ;
F_71 (ha, dev) {
if ( ! V_205 -- )
break;
memcpy ( V_212 , V_211 -> V_217 , V_215 ) ;
if ( V_218 > 1 )
F_28 ( V_206 , F_7 ( V_183 L_84 ,
V_2 -> V_22 , V_212 ) ) ;
V_212 += V_215 ;
}
F_29 ( V_2 , & V_27 -> V_27 ) ;
}
}
int T_4 F_72 ( void )
{
if ( V_219 >= 0 )
V_218 = V_219 ;
V_220 = F_52 ( - 1 ) ;
if ( F_73 ( V_220 ) )
return F_74 ( V_220 ) ;
return 0 ;
}
void T_5 F_75 ( void )
{
F_76 ( V_220 ) ;
#ifdef F_19
F_57 ( ( void * ) ( V_220 -> V_179 ) , 4096 ,
V_191 ) ;
#endif
F_60 ( ( T_1 ) ( V_220 -> V_179 ) ) ;
F_61 ( V_220 ) ;
}
