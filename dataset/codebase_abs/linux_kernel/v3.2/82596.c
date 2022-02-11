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
#ifdef F_4
if ( V_9 ) {
F_5 ( 0 , ( short ) ( V_2 -> V_5 ) + 4 ) ;
}
#endif
}
static inline void F_6 ( struct V_1 * V_2 , int V_10 , volatile void * V_11 )
{
#ifdef F_2
if ( V_3 ) {
struct V_4 * V_12 = (struct V_4 * ) ( V_2 -> V_5 ) ;
V_12 -> V_13 = ( ( V_10 ) | ( T_1 ) ( V_11 ) ) & 0xffff ;
V_12 -> V_14 = ( ( V_10 ) | ( T_1 ) ( V_11 ) ) >> 16 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
T_1 V_15 = ( T_1 ) ( V_10 ) | ( T_1 ) ( V_11 ) ;
V_15 = ( ( T_1 ) ( V_15 ) << 16 ) | ( ( T_1 ) ( V_15 ) >> 16 ) ;
* ( volatile T_1 * ) V_2 -> V_5 = V_15 ;
F_7 ( 1 ) ;
* ( volatile T_1 * ) V_2 -> V_5 = V_15 ;
}
#endif
}
static inline int F_8 ( struct V_1 * V_2 , struct V_16 * V_17 , int V_18 , char * V_19 )
{
while ( -- V_18 && V_17 -> V_20 . V_21 )
F_7 ( 10 ) ;
if ( ! V_18 ) {
F_9 ( V_22 L_1 ,
V_2 -> V_23 , V_19 , V_17 -> V_24 . V_25 , V_17 -> V_24 . V_26 ) ;
return - 1 ;
}
else
return 0 ;
}
static inline int F_10 ( struct V_1 * V_2 , struct V_16 * V_17 , int V_18 , char * V_19 )
{
while ( -- V_18 && V_17 -> V_24 . V_26 )
F_7 ( 10 ) ;
if ( ! V_18 ) {
F_9 ( V_22 L_1 ,
V_2 -> V_23 , V_19 , V_17 -> V_24 . V_25 , V_17 -> V_24 . V_26 ) ;
return - 1 ;
}
else
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 , struct V_27 * V_28 , int V_18 , char * V_19 )
{
volatile struct V_27 * V_10 = V_28 ;
while ( -- V_18 && V_10 -> V_26 )
F_7 ( 10 ) ;
if ( ! V_18 ) {
F_9 ( V_22 L_2 , V_2 -> V_23 , V_19 ) ;
return - 1 ;
}
else
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
struct V_27 * V_28 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
F_9 ( V_22 L_3 ,
& V_17 -> V_34 , V_17 -> V_34 . V_35 , V_17 -> V_34 . V_20 ) ;
F_9 ( V_22 L_4 ,
& V_17 -> V_20 , V_17 -> V_20 . V_21 , V_17 -> V_20 . V_24 ) ;
F_9 ( V_22 L_5
L_6 ,
& V_17 -> V_24 , V_17 -> V_24 . V_25 , V_17 -> V_24 . V_26 ,
V_17 -> V_24 . V_28 , V_17 -> V_24 . V_31 ) ;
F_9 ( V_22 L_7
L_8 ,
V_17 -> V_24 . V_36 , V_17 -> V_24 . V_37 , V_17 -> V_24 . V_38 ,
V_17 -> V_24 . V_39 , V_17 -> V_24 . V_40 , V_17 -> V_24 . V_41 ) ;
V_28 = V_17 -> V_42 ;
while ( V_28 != V_43 ) {
F_9 ( V_22 L_9 ,
V_28 , V_28 -> V_25 , V_28 -> V_26 , V_28 -> V_44 ) ;
V_28 = V_28 -> V_45 ;
}
V_31 = V_17 -> V_46 ;
F_9 ( V_22 L_10 , V_31 ) ;
do {
F_9 ( V_22 L_11
L_12 ,
V_31 , V_31 -> V_21 , V_31 -> V_28 , V_31 -> V_44 , V_31 -> V_33 ,
V_31 -> V_47 ) ;
V_31 = V_31 -> V_45 ;
} while ( V_31 != V_17 -> V_46 );
V_33 = V_17 -> V_48 ;
F_9 ( V_22 L_13 , V_33 ) ;
do {
F_9 ( V_22 L_14 ,
V_33 , V_33 -> V_47 , V_33 -> V_44 , V_33 -> V_49 , V_33 -> V_50 ) ;
V_33 = V_33 -> V_45 ;
} while ( V_33 != V_17 -> V_48 );
}
static T_2 F_13 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_53 = ( unsigned char * ) 0xfff42000 ;
V_53 [ 0x28 ] = 1 ;
V_53 [ 0x2b ] = 0x1d ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_54 = ( unsigned char * ) V_55 ;
* V_54 = 1 ;
* V_54 = 3 ;
}
#endif
F_9 ( V_22 L_15 , V_2 -> V_23 ) ;
F_12 ( V_2 ) ;
return V_56 ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
struct V_32 * V_33 ;
int V_8 ;
for ( V_8 = 0 , V_33 = V_17 -> V_57 ; V_8 < V_58 ; V_8 ++ , V_33 ++ ) {
if ( V_33 -> V_59 == NULL )
break;
F_15 ( V_33 -> V_59 ) ;
V_33 -> V_59 = NULL ;
}
}
static inline int F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
int V_8 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
for ( V_8 = 0 , V_33 = V_17 -> V_57 ; V_8 < V_58 ; V_8 ++ , V_33 ++ ) {
struct V_60 * V_59 = F_17 ( V_61 ) ;
if ( V_59 == NULL ) {
F_14 ( V_2 ) ;
return - V_62 ;
}
V_59 -> V_2 = V_2 ;
V_33 -> V_45 = V_33 + 1 ;
V_33 -> V_44 = F_18 ( F_19 ( V_33 + 1 ) ) ;
V_33 -> V_63 = F_18 ( F_19 ( V_33 ) ) ;
V_33 -> V_59 = V_59 ;
V_33 -> V_64 = V_59 -> V_65 ;
V_33 -> V_49 = F_20 ( F_19 ( V_59 -> V_65 ) ) ;
V_33 -> V_50 = V_61 ;
#ifdef F_21
F_22 ( F_23 ( V_59 -> V_65 ) , V_61 ) ;
#endif
}
V_17 -> V_48 = V_17 -> V_57 ;
V_33 = V_17 -> V_57 + V_58 - 1 ;
V_33 -> V_45 = V_17 -> V_57 ;
V_33 -> V_44 = F_18 ( F_19 ( V_17 -> V_57 ) ) ;
for ( V_8 = 0 , V_31 = V_17 -> V_66 ; V_8 < V_58 ; V_8 ++ , V_31 ++ ) {
V_31 -> V_33 = V_43 ;
V_31 -> V_45 = V_31 + 1 ;
V_31 -> V_67 = V_31 - 1 ;
V_31 -> V_44 = F_24 ( F_19 ( V_31 + 1 ) ) ;
V_31 -> V_28 = V_68 ;
}
V_17 -> V_46 = V_17 -> V_66 ;
V_17 -> V_24 . V_31 = F_24 ( F_19 ( V_17 -> V_66 ) ) ;
V_31 = V_17 -> V_66 ;
V_31 -> V_33 = V_17 -> V_48 ;
V_31 -> V_67 = V_17 -> V_66 + V_58 - 1 ;
V_31 = V_17 -> V_66 + V_58 - 1 ;
V_31 -> V_45 = V_17 -> V_66 ;
V_31 -> V_44 = F_24 ( F_19 ( V_17 -> V_66 ) ) ;
V_31 -> V_28 = V_69 | V_68 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_58 ; V_8 ++ ) {
V_17 -> V_66 [ V_8 ] . V_33 = V_43 ;
V_17 -> V_66 [ V_8 ] . V_28 = V_68 ;
}
V_17 -> V_66 [ V_58 - 1 ] . V_28 = V_69 | V_68 ;
V_17 -> V_46 = V_17 -> V_66 ;
V_17 -> V_24 . V_31 = F_24 ( F_19 ( V_17 -> V_66 ) ) ;
V_17 -> V_48 = V_17 -> V_57 ;
V_17 -> V_66 [ 0 ] . V_33 = F_18 ( F_19 ( V_17 -> V_57 ) ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
#if ! F_27 ( F_2 ) && ! F_27 ( F_3 ) || F_27 ( F_4 )
short V_70 = V_2 -> V_5 ;
#endif
unsigned long V_71 ;
F_6 ( V_2 , V_72 , NULL ) ;
F_7 ( 100 ) ;
#if F_27 ( F_2 ) || F_27 ( F_3 )
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_53 = ( unsigned char * ) 0xfff42000 ;
V_53 [ 0x28 ] = 1 ;
V_53 [ 0x2a ] = 0x48 ;
V_53 [ 0x2b ] = 0x08 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_54 = ( unsigned char * ) V_55 ;
* V_54 = 1 ;
}
#endif
F_6 ( V_2 , V_73 , ( void * ) F_19 ( ( void * ) & V_17 -> V_34 ) ) ;
#elif F_27 ( F_4 )
{
T_1 V_34 = F_19 ( & V_17 -> V_34 ) ;
F_5 ( 0 , V_70 ) ;
F_5 ( 0 , V_70 ) ;
F_28 ( 4 , V_70 + 0xf ) ;
F_5 ( V_34 | 2 , V_70 ) ;
F_5 ( V_34 >> 16 , V_70 ) ;
}
#endif
V_17 -> V_74 = V_75 ;
#ifdef F_2
if ( V_3 )
V_17 -> V_34 . V_35 = 0x00000054 ;
#endif
#ifdef F_3
if ( V_7 )
V_17 -> V_34 . V_35 = 0x0000004c ;
#endif
#ifdef F_4
if ( V_9 )
V_17 -> V_34 . V_35 = 0x00440000 ;
#endif
V_17 -> V_34 . V_20 = F_29 ( F_19 ( ( void * ) & V_17 -> V_20 ) ) ;
V_17 -> V_20 . V_24 = F_30 ( F_19 ( ( void * ) & V_17 -> V_24 ) ) ;
V_17 -> V_20 . V_21 = V_76 ;
V_17 -> V_77 = 0 ;
V_17 -> V_42 = V_17 -> V_24 . V_28 = V_43 ;
#ifdef F_3
if ( V_7 ) {
V_17 -> V_24 . V_78 = 7 * 25 ;
V_17 -> V_24 . V_79 = 1 * 25 ;
}
#endif
F_31 ( V_80 , F_9 ( V_81 L_16 , V_2 -> V_23 ) ) ;
#if F_27 ( F_4 )
( void ) F_32 ( V_70 + 0x10 ) ;
F_28 ( 4 , V_70 + 0xf ) ;
#endif
F_1 ( V_2 ) ;
if ( F_8 ( V_2 , V_17 , 1000 , L_17 ) )
goto V_82;
F_31 ( V_80 , F_9 ( V_81 L_18 , V_2 -> V_23 ) ) ;
F_25 ( V_2 ) ;
V_17 -> V_24 . V_26 = 0 ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_53 = ( unsigned char * ) 0xfff42000 ;
V_53 [ 0x2a ] = 0x55 ;
V_53 [ 0x2b ] = 0x15 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_54 = ( unsigned char * ) V_55 ;
* V_54 = 3 ;
}
#endif
F_31 ( V_80 , F_9 ( V_81 L_19 , V_2 -> V_23 ) ) ;
memcpy ( V_17 -> V_83 . V_84 , V_85 , 14 ) ;
V_17 -> V_83 . V_28 . V_26 = V_86 ;
F_33 ( V_2 , & V_17 -> V_83 . V_28 ) ;
F_31 ( V_80 , F_9 ( V_81 L_20 , V_2 -> V_23 ) ) ;
memcpy ( V_17 -> V_87 . V_88 , V_2 -> V_89 , 6 ) ;
V_17 -> V_87 . V_28 . V_26 = V_90 ;
F_33 ( V_2 , & V_17 -> V_87 . V_28 ) ;
F_31 ( V_80 , F_9 ( V_81 L_21 , V_2 -> V_23 ) ) ;
V_17 -> V_91 . V_28 . V_26 = V_92 ;
F_33 ( V_2 , & V_17 -> V_91 . V_28 ) ;
F_34 ( & V_17 -> V_93 , V_71 ) ;
if ( F_10 ( V_2 , V_17 , 1000 , L_22 ) ) {
F_35 ( & V_17 -> V_93 , V_71 ) ;
goto V_82;
}
F_31 ( V_80 , F_9 ( V_81 L_23 , V_2 -> V_23 ) ) ;
V_17 -> V_24 . V_26 = V_94 ;
F_1 ( V_2 ) ;
F_35 ( & V_17 -> V_93 , V_71 ) ;
if ( F_10 ( V_2 , V_17 , 1000 , L_24 ) )
goto V_82;
F_31 ( V_80 , F_9 ( V_81 L_25 , V_2 -> V_23 ) ) ;
return 0 ;
V_82:
F_9 ( V_95 L_26 , V_2 -> V_23 ) ;
F_6 ( V_2 , V_72 , NULL ) ;
return - 1 ;
}
static inline int F_36 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
int V_96 = 0 ;
F_31 ( V_97 , F_9 ( V_81 L_27 ,
V_17 -> V_46 , V_17 -> V_48 ) ) ;
V_31 = V_17 -> V_46 ;
while ( ( V_31 -> V_21 ) & V_98 ) {
if ( V_31 -> V_33 == V_43 )
V_33 = V_43 ;
else if ( V_31 -> V_33 == V_17 -> V_48 -> V_63 )
V_33 = V_17 -> V_48 ;
else {
F_9 ( V_95 L_28 , V_2 -> V_23 ) ;
V_33 = V_43 ;
}
F_31 ( V_97 , F_9 ( V_81 L_29 ,
V_31 , V_31 -> V_33 , V_31 -> V_21 ) ) ;
if ( V_33 != V_43 && ( ( V_31 -> V_21 ) & V_99 ) ) {
int V_100 = V_33 -> V_47 & 0x3fff ;
struct V_60 * V_59 = V_33 -> V_59 ;
int V_101 = 0 ;
F_31 ( V_102 , F_37 ( V_33 -> V_64 , L_30 ) ) ;
V_96 ++ ;
if ( V_100 > V_103 ) {
struct V_60 * V_104 ;
V_104 = F_17 ( V_61 ) ;
if ( V_104 == NULL ) {
V_59 = NULL ;
goto V_105;
}
F_38 ( V_59 , V_100 ) ;
V_101 = 1 ;
V_33 -> V_59 = V_104 ;
V_104 -> V_2 = V_2 ;
V_33 -> V_64 = V_104 -> V_65 ;
V_33 -> V_49 = F_20 ( F_19 ( V_104 -> V_65 ) ) ;
#ifdef F_21
F_22 ( F_23 ( V_104 -> V_65 ) , V_61 ) ;
#endif
}
else
V_59 = F_17 ( V_100 + 2 ) ;
V_105:
if ( V_59 == NULL ) {
F_9 ( V_106 L_31 , V_2 -> V_23 ) ;
V_2 -> V_107 . V_108 ++ ;
}
else {
if ( ! V_101 ) {
F_39 ( V_59 , 2 ) ;
memcpy ( F_38 ( V_59 , V_100 ) , V_33 -> V_64 , V_100 ) ;
}
V_59 -> V_109 = F_40 ( V_59 , V_2 ) ;
V_59 -> V_110 = V_100 ;
#ifdef F_21
F_22 ( F_23 ( V_33 -> V_59 -> V_65 ) ,
V_100 ) ;
#endif
F_41 ( V_59 ) ;
V_2 -> V_107 . V_111 ++ ;
V_2 -> V_107 . V_112 += V_100 ;
}
}
else {
F_31 ( V_113 , F_9 ( V_81 L_32 ,
V_2 -> V_23 , V_31 -> V_21 ) ) ;
V_2 -> V_107 . V_114 ++ ;
if ( ( V_31 -> V_21 ) & 0x0001 )
V_2 -> V_107 . V_115 ++ ;
if ( ( V_31 -> V_21 ) & 0x0080 )
V_2 -> V_107 . V_116 ++ ;
if ( ( V_31 -> V_21 ) & 0x0100 )
V_2 -> V_107 . V_117 ++ ;
if ( ( V_31 -> V_21 ) & 0x0200 )
V_2 -> V_107 . V_118 ++ ;
if ( ( V_31 -> V_21 ) & 0x0400 )
V_2 -> V_107 . V_119 ++ ;
if ( ( V_31 -> V_21 ) & 0x0800 )
V_2 -> V_107 . V_120 ++ ;
if ( ( V_31 -> V_21 ) & 0x1000 )
V_2 -> V_107 . V_116 ++ ;
}
if ( V_33 != V_43 && ( V_33 -> V_47 & 0x4000 ) ) {
V_33 -> V_47 = 0 ;
V_17 -> V_48 = V_33 -> V_45 ;
}
V_31 -> V_33 = V_43 ;
V_31 -> V_21 = 0 ;
V_31 -> V_28 = V_69 | V_68 ;
V_31 -> V_47 = 0 ;
V_31 -> V_67 -> V_28 = V_68 ;
V_17 -> V_24 . V_31 = V_31 -> V_44 ;
V_17 -> V_46 = V_31 -> V_45 ;
V_31 = V_17 -> V_46 ;
}
F_31 ( V_97 , F_9 ( V_81 L_33 , V_96 ) ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_27 * V_121 ;
while ( V_17 -> V_42 != V_43 ) {
V_121 = V_17 -> V_42 ;
V_17 -> V_42 = V_121 -> V_45 ;
V_17 -> V_77 -- ;
switch ( ( V_121 -> V_26 ) & 0x7 ) {
case V_122 :
{
struct V_123 * V_123 = (struct V_123 * ) V_121 ;
struct V_60 * V_59 = V_123 -> V_59 ;
F_15 ( V_59 ) ;
V_2 -> V_107 . V_124 ++ ;
V_2 -> V_107 . V_125 ++ ;
V_121 -> V_45 = V_121 -> V_44 = V_43 ;
V_123 -> V_28 . V_26 = 0 ;
break;
}
default:
V_121 -> V_45 = V_121 -> V_44 = V_43 ;
}
}
F_10 ( V_2 , V_17 , 100 , L_34 ) ;
V_17 -> V_24 . V_28 = V_43 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_16 * V_17 ,
int V_70 )
{
unsigned long V_71 ;
F_31 ( V_126 , F_9 ( V_81 L_35 ) ) ;
F_34 ( & V_17 -> V_93 , V_71 ) ;
F_10 ( V_2 , V_17 , 100 , L_36 ) ;
F_44 ( V_2 ) ;
V_17 -> V_24 . V_26 = V_127 | V_128 ;
F_1 ( V_2 ) ;
F_10 ( V_2 , V_17 , 1000 , L_37 ) ;
F_35 ( & V_17 -> V_93 , V_71 ) ;
F_42 ( V_2 , V_17 ) ;
F_36 ( V_2 ) ;
F_45 ( V_2 ) ;
F_26 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
int V_70 = V_2 -> V_5 ;
unsigned long V_71 ;
F_31 ( V_129 , F_9 ( V_81 L_38 ) ) ;
V_28 -> V_25 = 0 ;
V_28 -> V_26 |= ( V_69 | V_130 ) ;
V_28 -> V_45 = V_28 -> V_44 = V_43 ;
F_34 ( & V_17 -> V_93 , V_71 ) ;
if ( V_17 -> V_42 != V_43 ) {
V_17 -> V_131 -> V_45 = V_28 ;
V_17 -> V_131 -> V_44 = F_46 ( F_19 ( & V_28 -> V_25 ) ) ;
} else {
V_17 -> V_42 = V_28 ;
F_10 ( V_2 , V_17 , 100 , L_39 ) ;
V_17 -> V_24 . V_28 = F_46 ( F_19 ( & V_28 -> V_25 ) ) ;
V_17 -> V_24 . V_26 = V_132 ;
F_1 ( V_2 ) ;
}
V_17 -> V_131 = V_28 ;
V_17 -> V_77 ++ ;
F_35 ( & V_17 -> V_93 , V_71 ) ;
if ( V_17 -> V_77 > V_133 ) {
unsigned long V_134 = V_75 - V_17 -> V_74 ;
if ( V_134 < V_135 )
return;
F_9 ( V_136 L_40 , V_2 -> V_23 ) ;
F_43 ( V_2 , V_17 , V_70 ) ;
}
}
static int F_47 ( struct V_1 * V_2 )
{
int V_137 = 0 ;
F_31 ( V_138 , F_9 ( V_81 L_41 , V_2 -> V_23 , V_2 -> V_51 ) ) ;
if ( F_48 ( V_2 -> V_51 , V_139 , 0 , L_42 , V_2 ) ) {
F_9 ( V_22 L_43 , V_2 -> V_23 , V_2 -> V_51 ) ;
return - V_140 ;
}
#ifdef F_2
if ( V_3 ) {
if ( F_48 ( 0x56 , F_13 , 0 , L_44 , V_2 ) ) {
V_137 = - V_140 ;
goto V_141;
}
}
#endif
V_137 = F_16 ( V_2 ) ;
if ( V_137 )
goto V_142;
F_45 ( V_2 ) ;
if ( F_26 ( V_2 ) ) {
V_137 = - V_140 ;
goto V_143;
}
return 0 ;
V_143:
F_44 ( V_2 ) ;
F_14 ( V_2 ) ;
V_142:
#ifdef F_2
F_49 ( 0x56 , V_2 ) ;
V_141:
#endif
F_49 ( V_2 -> V_51 , V_2 ) ;
return V_137 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
int V_70 = V_2 -> V_5 ;
F_31 ( V_113 , F_9 ( V_22 L_45 ,
V_2 -> V_23 ) ) ;
V_2 -> V_107 . V_124 ++ ;
if ( V_17 -> V_144 == V_2 -> V_107 . V_145 ) {
F_31 ( V_113 , F_9 ( V_22 L_46 ) ) ;
F_43 ( V_2 , V_17 , V_70 ) ;
} else {
F_31 ( V_113 , F_9 ( V_22 L_47 ) ) ;
V_17 -> V_24 . V_26 = V_132 | V_94 ;
F_1 ( V_2 ) ;
V_17 -> V_144 = V_2 -> V_107 . V_145 ;
}
V_2 -> V_146 = V_75 ;
F_51 ( V_2 ) ;
}
static T_3 F_52 ( struct V_60 * V_59 , struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
struct V_123 * V_123 ;
struct V_147 * V_148 ;
short V_149 = V_59 -> V_110 ;
F_31 ( V_150 , F_9 ( V_81 L_48 ,
V_2 -> V_23 , V_59 -> V_110 , V_59 -> V_65 ) ) ;
if ( V_59 -> V_110 < V_151 ) {
if ( F_53 ( V_59 , V_151 ) )
return V_152 ;
V_149 = V_151 ;
}
F_44 ( V_2 ) ;
V_123 = V_17 -> V_153 + V_17 -> V_154 ;
V_148 = V_17 -> V_155 + V_17 -> V_154 ;
if ( V_123 -> V_28 . V_26 ) {
F_9 ( V_136 L_49 ,
V_2 -> V_23 ) ;
V_2 -> V_107 . V_156 ++ ;
F_15 ( V_59 ) ;
} else {
if ( ++ V_17 -> V_154 == V_157 )
V_17 -> V_154 = 0 ;
V_123 -> V_148 = F_54 ( F_19 ( V_148 ) ) ;
V_148 -> V_158 = V_43 ;
V_123 -> V_28 . V_26 = V_68 | V_122 ;
V_123 -> V_59 = V_59 ;
V_123 -> V_159 = 0 ;
V_123 -> V_50 = 0 ;
V_148 -> V_159 = 0 ;
V_148 -> V_50 = V_160 | V_149 ;
V_148 -> V_65 = F_20 ( F_19 ( V_59 -> V_65 ) ) ;
#ifdef F_21
F_55 ( F_23 ( V_59 -> V_65 ) , V_149 ) ;
#endif
F_31 ( V_161 , F_37 ( V_59 -> V_65 , L_50 ) ) ;
F_33 ( V_2 , & V_123 -> V_28 ) ;
V_2 -> V_107 . V_145 ++ ;
V_2 -> V_107 . V_162 += V_149 ;
}
F_45 ( V_2 ) ;
return V_152 ;
}
static void F_37 ( unsigned char * V_163 , char * V_19 )
{
F_9 ( V_81 L_51 ,
V_163 , V_163 + 6 , V_163 , V_163 [ 12 ] , V_163 [ 13 ] , V_19 ) ;
}
struct V_1 * T_4 F_56 ( int V_164 )
{
struct V_1 * V_2 ;
int V_8 ;
struct V_16 * V_17 ;
char V_88 [ 8 ] ;
static int V_165 ;
int V_166 ;
if ( V_165 )
return F_57 ( - V_167 ) ;
V_165 ++ ;
V_2 = F_58 ( 0 ) ;
if ( ! V_2 )
return F_57 ( - V_62 ) ;
if ( V_164 >= 0 ) {
sprintf ( V_2 -> V_23 , L_52 , V_164 ) ;
F_59 ( V_2 ) ;
} else {
V_2 -> V_5 = V_168 ;
V_2 -> V_51 = V_51 ;
}
#ifdef F_2
if ( V_3 ) {
if ( V_169 & V_170 ) {
F_9 ( V_136 L_53 ) ;
V_166 = - V_167 ;
goto V_171;
}
memcpy ( V_88 , ( void * ) 0xfffc1f2c , 6 ) ;
V_2 -> V_5 = V_172 ;
V_2 -> V_51 = ( unsigned ) V_173 ;
goto V_174;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_175 = ( unsigned char * ) V_176 ;
unsigned char V_177 = V_175 [ 3 ] ;
int V_8 ;
V_175 [ 3 ] |= 0x80 ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ )
V_88 [ V_8 ] = V_175 [ V_8 * 4 + 7 ] ;
V_175 [ 3 ] = V_177 ;
V_2 -> V_5 = V_178 ;
V_2 -> V_51 = ( unsigned ) V_179 ;
goto V_174;
}
#endif
#ifdef F_4
{
int V_180 = 0 ;
int V_70 = 0x300 ;
if ( ! F_60 ( V_70 , V_181 , V_182 ) ) {
F_9 ( V_22 L_54 , V_70 ) ;
V_166 = - V_183 ;
goto V_171;
}
V_2 -> V_5 = V_70 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_88 [ V_8 ] = F_32 ( V_70 + 8 + V_8 ) ;
V_180 += V_88 [ V_8 ] ;
}
if ( ( V_180 % 0x100 ) ||
( memcmp ( V_88 , L_55 , 3 ) != 0 ) ) {
V_166 = - V_167 ;
goto V_184;
}
V_2 -> V_51 = 10 ;
goto V_174;
}
#endif
V_166 = - V_167 ;
goto V_171;
V_174:
V_2 -> V_185 = ( int ) F_61 ( V_186 , 0 ) ;
if ( ! V_2 -> V_185 ) {
V_166 = - V_62 ;
goto V_184;
}
F_31 ( V_187 , F_9 ( V_188 L_56 , V_2 -> V_23 , V_2 -> V_5 ) ) ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ )
F_31 ( V_187 , F_9 ( L_57 , V_2 -> V_89 [ V_8 ] = V_88 [ V_8 ] ) ) ;
F_31 ( V_187 , F_9 ( L_58 , V_2 -> V_51 ) ) ;
F_31 ( V_187 , F_9 ( V_188 L_59 , V_189 ) ) ;
V_2 -> V_190 = & V_191 ;
V_2 -> V_192 = V_193 ;
V_2 -> V_29 = ( void * ) ( V_2 -> V_185 ) ;
V_17 = V_2 -> V_29 ;
F_31 ( V_80 , F_9 ( V_81 L_60
L_61 ,
V_2 -> V_23 , ( unsigned long ) V_17 ,
sizeof( struct V_16 ) , ( unsigned long ) & V_17 -> V_24 ) ) ;
memset ( ( void * ) V_17 , 0 , sizeof( struct V_16 ) ) ;
#ifdef F_21
F_55 ( F_23 ( ( void * ) ( V_2 -> V_185 ) ) , 4096 ) ;
F_22 ( F_23 ( ( void * ) ( V_2 -> V_185 ) ) , 4096 ) ;
F_62 ( ( void * ) ( V_2 -> V_185 ) , 4096 , V_194 ) ;
#endif
V_17 -> V_24 . V_26 = 0 ;
V_17 -> V_24 . V_28 = V_43 ;
V_17 -> V_24 . V_31 = V_43 ;
F_63 ( & V_17 -> V_93 ) ;
V_166 = F_64 ( V_2 ) ;
if ( V_166 )
goto V_195;
return V_2 ;
V_195:
#ifdef F_21
F_62 ( ( void * ) ( V_2 -> V_185 ) , 4096 ,
V_196 ) ;
#endif
F_65 ( ( T_1 ) ( V_2 -> V_185 ) ) ;
V_184:
#ifdef F_4
F_66 ( V_2 -> V_5 , V_181 ) ;
#endif
V_171:
F_67 ( V_2 ) ;
return F_57 ( V_166 ) ;
}
static T_2 V_139 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_16 * V_17 ;
short V_70 ;
unsigned short V_25 , V_197 = 0 ;
int V_198 = 0 ;
#ifdef F_3
if ( V_7 ) {
if ( * ( char * ) V_199 & V_200 ) {
F_13 ( V_51 , V_52 ) ;
return V_56 ;
}
}
#endif
if ( V_2 == NULL ) {
F_9 ( V_22 L_62 , V_51 ) ;
return V_201 ;
}
V_70 = V_2 -> V_5 ;
V_17 = V_2 -> V_29 ;
F_68 ( & V_17 -> V_93 ) ;
F_10 ( V_2 , V_17 , 100 , L_63 ) ;
V_25 = V_17 -> V_24 . V_25 ;
F_31 ( V_202 , F_9 ( V_81 L_64 ,
V_2 -> V_23 , V_51 , V_25 ) ) ;
V_197 = V_25 & 0xf000 ;
if ( ( V_25 & 0x8000 ) || ( V_25 & 0x2000 ) ) {
struct V_27 * V_121 ;
V_198 = 1 ;
if ( ( V_25 & 0x8000 ) )
F_31 ( V_202 , F_9 ( V_81 L_65 , V_2 -> V_23 ) ) ;
if ( ( V_25 & 0x2000 ) )
F_31 ( V_202 , F_9 ( V_81 L_66 , V_2 -> V_23 , V_25 & 0x0700 ) ) ;
while ( ( V_17 -> V_42 != V_43 ) && ( V_17 -> V_42 -> V_25 & V_98 ) ) {
V_121 = V_17 -> V_42 ;
F_31 ( V_203 , F_9 ( V_81 L_67 ,
V_17 -> V_42 -> V_25 , V_17 -> V_42 -> V_26 ) ) ;
V_17 -> V_42 = V_121 -> V_45 ;
V_17 -> V_77 -- ;
switch ( ( V_121 -> V_26 ) & 0x7 ) {
case V_122 :
{
struct V_123 * V_123 = (struct V_123 * ) V_121 ;
struct V_60 * V_59 = V_123 -> V_59 ;
if ( ( V_121 -> V_25 ) & V_99 ) {
F_31 ( V_161 , F_37 ( V_59 -> V_65 , L_68 ) ) ;
} else {
V_2 -> V_107 . V_124 ++ ;
if ( ( V_121 -> V_25 ) & 0x0020 )
V_2 -> V_107 . V_115 ++ ;
if ( ! ( ( V_121 -> V_25 ) & 0x0040 ) )
V_2 -> V_107 . V_204 ++ ;
if ( ( V_121 -> V_25 ) & 0x0400 )
V_2 -> V_107 . V_205 ++ ;
if ( ( V_121 -> V_25 ) & 0x0800 )
V_2 -> V_107 . V_115 ++ ;
if ( ( V_121 -> V_25 ) & 0x1000 )
V_2 -> V_107 . V_125 ++ ;
}
F_69 ( V_59 ) ;
V_123 -> V_28 . V_26 = 0 ;
break;
}
case V_92 :
{
unsigned short V_25 = ( (struct V_91 * ) V_121 ) -> V_25 ;
if ( V_25 & 0x8000 ) {
F_31 ( V_206 , F_9 ( V_188 L_69 , V_2 -> V_23 ) ) ;
} else {
if ( V_25 & 0x4000 )
F_9 ( V_22 L_70 , V_2 -> V_23 ) ;
if ( V_25 & 0x2000 )
F_9 ( V_22 L_71 , V_2 -> V_23 ) ;
if ( V_25 & 0x1000 )
F_9 ( V_22 L_72 , V_2 -> V_23 ) ;
F_31 ( V_206 , F_9 ( V_188 L_73 , V_2 -> V_23 , V_25 & 0x07ff ) ) ;
}
break;
}
case V_86 :
case V_207 :
V_121 -> V_26 = 0 ;
break;
}
V_121 -> V_45 = V_121 -> V_44 = V_43 ;
V_17 -> V_74 = V_75 ;
}
V_121 = V_17 -> V_42 ;
while ( ( V_121 != V_43 ) && ( V_121 != V_17 -> V_131 ) ) {
V_121 -> V_26 &= 0x1fff ;
V_121 = V_121 -> V_45 ;
}
if ( ( V_17 -> V_42 != V_43 ) )
V_197 |= V_132 ;
V_17 -> V_24 . V_28 = F_46 ( F_19 ( & V_17 -> V_42 -> V_25 ) ) ;
}
if ( ( V_25 & 0x1000 ) || ( V_25 & 0x4000 ) ) {
if ( ( V_25 & 0x4000 ) )
F_31 ( V_202 , F_9 ( V_81 L_74 , V_2 -> V_23 ) ) ;
F_36 ( V_2 ) ;
if ( V_25 & 0x1000 ) {
if ( F_70 ( V_2 ) ) {
F_31 ( V_113 , F_9 ( V_22 L_75 , V_2 -> V_23 , V_25 ) ) ;
V_197 |= V_94 ;
V_2 -> V_107 . V_114 ++ ;
V_2 -> V_107 . V_118 ++ ;
F_25 ( V_2 ) ;
}
}
}
F_10 ( V_2 , V_17 , 100 , L_63 ) ;
V_17 -> V_24 . V_26 = V_197 ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_53 = ( unsigned char * ) 0xfff42000 ;
V_53 [ 0x2a ] |= 0x08 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_54 = ( unsigned char * ) V_55 ;
* V_54 = 1 ;
* V_54 = 3 ;
}
#endif
#ifdef F_4
( void ) F_32 ( V_70 + 0x10 ) ;
F_28 ( 4 , V_70 + 0xf ) ;
#endif
F_1 ( V_2 ) ;
F_31 ( V_202 , F_9 ( V_81 L_76 , V_2 -> V_23 ) ) ;
F_71 ( & V_17 -> V_93 ) ;
return F_72 ( V_198 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
unsigned long V_71 ;
F_44 ( V_2 ) ;
F_31 ( V_80 , F_9 ( V_81 L_77 ,
V_2 -> V_23 , V_17 -> V_24 . V_25 ) ) ;
F_34 ( & V_17 -> V_93 , V_71 ) ;
F_10 ( V_2 , V_17 , 100 , L_78 ) ;
V_17 -> V_24 . V_26 = V_127 | V_128 ;
F_1 ( V_2 ) ;
F_10 ( V_2 , V_17 , 100 , L_79 ) ;
F_35 ( & V_17 -> V_93 , V_71 ) ;
F_31 ( V_208 , F_12 ( V_2 ) ) ;
F_42 ( V_2 , V_17 ) ;
#ifdef F_2
if ( V_3 ) {
volatile unsigned char * V_53 = ( unsigned char * ) 0xfff42000 ;
V_53 [ 0x28 ] = 1 ;
V_53 [ 0x2a ] = 0x40 ;
V_53 [ 0x2b ] = 0x40 ;
}
#endif
#ifdef F_3
if ( V_7 ) {
volatile unsigned char * V_54 = ( unsigned char * ) V_55 ;
* V_54 = 1 ;
}
#endif
#ifdef F_2
F_49 ( 0x56 , V_2 ) ;
#endif
F_49 ( V_2 -> V_51 , V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_29 ;
int V_209 = 0 , V_210 ;
F_31 ( V_211 , F_9 ( V_81 L_80 ,
V_2 -> V_23 , F_75 ( V_2 ) ,
V_2 -> V_71 & V_212 ? L_81 : L_82 ,
V_2 -> V_71 & V_213 ? L_81 : L_82 ) ) ;
if ( F_11 ( V_2 , & V_17 -> V_83 . V_28 , 1000 , L_83 ) )
return;
if ( ( V_2 -> V_71 & V_212 ) && ! ( V_17 -> V_83 . V_84 [ 8 ] & 0x01 ) ) {
V_17 -> V_83 . V_84 [ 8 ] |= 0x01 ;
V_209 = 1 ;
}
if ( ! ( V_2 -> V_71 & V_212 ) && ( V_17 -> V_83 . V_84 [ 8 ] & 0x01 ) ) {
V_17 -> V_83 . V_84 [ 8 ] &= ~ 0x01 ;
V_209 = 1 ;
}
if ( ( V_2 -> V_71 & V_213 ) && ( V_17 -> V_83 . V_84 [ 11 ] & 0x20 ) ) {
V_17 -> V_83 . V_84 [ 11 ] &= ~ 0x20 ;
V_209 = 1 ;
}
if ( ! ( V_2 -> V_71 & V_213 ) && ! ( V_17 -> V_83 . V_84 [ 11 ] & 0x20 ) ) {
V_17 -> V_83 . V_84 [ 11 ] |= 0x20 ;
V_209 = 1 ;
}
if ( V_209 ) {
V_17 -> V_83 . V_28 . V_26 = V_86 ;
F_33 ( V_2 , & V_17 -> V_83 . V_28 ) ;
}
V_210 = F_75 ( V_2 ) ;
if ( V_210 > V_214 )
{
V_210 = V_214 ;
F_9 ( V_22 L_84 ,
V_2 -> V_23 , V_210 ) ;
}
if ( ! F_76 ( V_2 ) ) {
struct V_215 * V_216 ;
unsigned char * V_217 ;
struct V_218 * V_28 ;
if ( F_11 ( V_2 , & V_17 -> V_218 . V_28 , 1000 , L_85 ) )
return;
V_28 = & V_17 -> V_218 ;
V_28 -> V_28 . V_26 = V_207 ;
V_28 -> V_219 = V_210 * V_220 ;
V_217 = V_28 -> V_221 ;
F_77 (ha, dev) {
if ( ! V_210 -- )
break;
memcpy ( V_217 , V_216 -> V_222 , V_220 ) ;
if ( V_223 > 1 )
F_31 ( V_211 , F_9 ( V_188 L_86 ,
V_2 -> V_23 , V_217 ) ) ;
V_217 += V_220 ;
}
F_33 ( V_2 , & V_28 -> V_28 ) ;
}
}
int T_4 F_78 ( void )
{
if ( V_224 >= 0 )
V_223 = V_224 ;
V_225 = F_56 ( - 1 ) ;
if ( F_79 ( V_225 ) )
return F_80 ( V_225 ) ;
return 0 ;
}
void T_5 F_81 ( void )
{
F_82 ( V_225 ) ;
#ifdef F_21
F_62 ( ( void * ) ( V_225 -> V_185 ) , 4096 ,
V_196 ) ;
#endif
F_65 ( ( T_1 ) ( V_225 -> V_185 ) ) ;
#ifdef F_4
F_66 ( V_225 -> V_5 , V_181 ) ;
#endif
F_67 ( V_225 ) ;
}
