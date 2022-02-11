static inline int F_1 ( unsigned long V_1 ,
unsigned int V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
register unsigned long T_1 V_5 ( L_1 ) = V_4 ;
register unsigned long T_2 V_5 ( L_2 ) = V_1 ;
register unsigned long T_3 V_5 ( L_3 ) = V_2 ;
register unsigned long T_4 V_5 ( L_4 ) = V_3 ;
int V_6 ;
asm volatile(
" siga 0\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc)
: "d" (__fc), "d" (__schid), "d" (out), "d" (in) : "cc");
return V_6 ;
}
static inline int F_2 ( unsigned long V_1 , unsigned int V_7 ,
unsigned int V_4 )
{
register unsigned long T_1 V_5 ( L_1 ) = V_4 ;
register unsigned long T_2 V_5 ( L_2 ) = V_1 ;
register unsigned long T_5 V_5 ( L_3 ) = V_7 ;
int V_6 ;
asm volatile(
" siga 0\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc)
: "d" (__fc), "d" (__schid), "d" (__mask) : "cc", "memory");
return V_6 ;
}
static inline int F_3 ( unsigned long V_1 , unsigned long V_7 ,
unsigned int * V_8 , unsigned int V_4 ,
unsigned long V_9 )
{
register unsigned long T_1 V_5 ( L_1 ) = V_4 ;
register unsigned long T_2 V_5 ( L_2 ) = V_1 ;
register unsigned long T_5 V_5 ( L_3 ) = V_7 ;
register unsigned long T_6 V_5 ( L_4 ) = V_9 ;
int V_6 = V_10 ;
asm volatile(
" siga 0\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (cc), "+d" (__fc), "+d" (__schid), "+d" (__mask),
"+d" (__aob)
: : "cc", "memory");
* V_8 = ( ( unsigned int ) T_1 ) >> 31 ;
return V_6 ;
}
static inline int F_4 ( struct V_11 * V_12 , unsigned int V_13 )
{
if ( V_13 == 0 || V_13 == 32 )
return 0 ;
if ( V_13 == 97 )
return 1 ;
if ( V_13 == 96 )
return 2 ;
F_5 ( L_5 , F_6 ( V_12 ) , V_13 ) ;
return - V_14 ;
}
static int F_7 ( struct V_11 * V_12 , unsigned char * V_15 ,
int V_16 , int V_17 , int V_18 )
{
int V_19 , V_20 = V_17 , V_21 = V_16 , V_22 = V_12 -> V_22 , V_23 = 0 ;
unsigned int V_13 = 0 ;
F_8 ( ! V_12 -> V_24 -> V_25 ) ;
F_9 ( V_12 , V_26 ) ;
if ( ! V_12 -> V_27 )
V_22 += V_12 -> V_24 -> V_28 ;
V_29:
V_13 = F_10 ( V_12 -> V_24 -> V_25 , V_15 , V_22 , & V_21 , & V_20 ,
V_18 ) ;
V_19 = F_4 ( V_12 , V_13 ) ;
if ( ! V_19 )
return V_17 - V_20 ;
if ( V_19 == 1 ) {
F_11 ( V_30 , V_12 -> V_24 , L_6 , V_13 ) ;
goto V_29;
}
if ( V_19 == 2 ) {
F_8 ( V_20 == V_17 ) ;
F_9 ( V_12 , V_31 ) ;
F_11 ( V_30 , V_12 -> V_24 , L_7 ,
V_20 ) ;
if ( ! V_23 ++ )
goto V_29;
else
return V_17 - V_20 ;
}
F_5 ( L_8 , F_6 ( V_12 ) ) ;
F_5 ( L_9 , V_17 , V_20 , V_22 ) ;
V_12 -> V_32 ( V_12 -> V_24 -> V_33 , V_34 ,
V_12 -> V_22 , V_12 -> V_35 , V_17 , V_12 -> V_24 -> V_36 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , unsigned char V_15 , int V_16 ,
int V_17 )
{
unsigned int V_13 = 0 ;
int V_20 = V_17 , V_21 = V_16 ;
int V_22 = V_12 -> V_22 ;
int V_19 ;
if ( ! V_17 )
return 0 ;
F_8 ( ! V_12 -> V_24 -> V_25 ) ;
F_9 ( V_12 , V_37 ) ;
if ( ! V_12 -> V_27 )
V_22 += V_12 -> V_24 -> V_28 ;
V_29:
V_13 = F_13 ( V_12 -> V_24 -> V_25 , V_15 , V_22 , & V_21 , & V_20 ) ;
V_19 = F_4 ( V_12 , V_13 ) ;
if ( ! V_19 ) {
F_14 ( V_20 ) ;
return V_17 - V_20 ;
}
if ( V_19 == 1 || V_19 == 2 ) {
F_11 ( V_38 , V_12 -> V_24 , L_10 , V_13 ) ;
F_9 ( V_12 , V_39 ) ;
goto V_29;
}
F_5 ( L_11 , F_6 ( V_12 ) ) ;
F_5 ( L_9 , V_17 , V_20 , V_22 ) ;
V_12 -> V_32 ( V_12 -> V_24 -> V_33 , V_34 ,
V_12 -> V_22 , V_12 -> V_35 , V_17 , V_12 -> V_24 -> V_36 ) ;
return 0 ;
}
static inline int F_15 ( struct V_11 * V_12 , unsigned int V_40 ,
unsigned char * V_15 , unsigned int V_17 ,
int V_18 , int V_41 )
{
unsigned char V_42 = 0 ;
int V_43 ;
F_8 ( V_40 > V_44 ) ;
F_8 ( V_17 > V_45 ) ;
if ( F_16 ( V_12 ) )
return F_7 ( V_12 , V_15 , V_40 , V_17 , V_18 ) ;
for ( V_43 = 0 ; V_43 < V_17 ; V_43 ++ ) {
if ( ! V_42 ) {
V_42 = V_12 -> V_46 . V_47 [ V_40 ] ;
if ( V_41 && V_42 == V_48 )
V_42 = V_49 ;
} else if ( V_41 ) {
if ( ( V_12 -> V_46 . V_47 [ V_40 ] & V_42 ) != V_42 )
break;
} else if ( V_12 -> V_46 . V_47 [ V_40 ] != V_42 )
break;
V_40 = F_17 ( V_40 ) ;
}
* V_15 = V_42 ;
return V_43 ;
}
static inline int F_18 ( struct V_11 * V_12 , unsigned int V_40 ,
unsigned char * V_15 , int V_18 )
{
return F_15 ( V_12 , V_40 , V_15 , 1 , V_18 , 0 ) ;
}
static inline int F_19 ( struct V_11 * V_12 , int V_40 ,
unsigned char V_15 , int V_17 )
{
int V_43 ;
F_8 ( V_40 > V_44 ) ;
F_8 ( V_17 > V_45 ) ;
if ( F_16 ( V_12 ) )
return F_12 ( V_12 , V_15 , V_40 , V_17 ) ;
for ( V_43 = 0 ; V_43 < V_17 ; V_43 ++ ) {
F_20 ( & V_12 -> V_46 . V_47 [ V_40 ] , V_15 ) ;
V_40 = F_17 ( V_40 ) ;
}
return V_17 ;
}
static inline int F_21 ( struct V_11 * V_12 , int V_40 ,
unsigned char V_15 )
{
return F_19 ( V_12 , V_40 , V_15 , 1 ) ;
}
static void F_22 ( struct V_50 * V_24 )
{
struct V_11 * V_12 ;
int V_43 ;
F_23 (irq_ptr, q, i)
F_19 ( V_12 , 0 , V_51 ,
V_45 ) ;
F_24 (irq_ptr, q, i)
F_19 ( V_12 , 0 , V_52 ,
V_45 ) ;
}
static inline int F_25 ( struct V_11 * V_12 , unsigned int V_53 ,
unsigned int V_54 )
{
unsigned long V_1 = * ( ( V_55 * ) & V_12 -> V_24 -> V_1 ) ;
unsigned int V_4 = V_56 ;
int V_6 ;
F_11 ( V_38 , V_12 -> V_24 , L_12 , V_12 -> V_22 ) ;
F_9 ( V_12 , V_57 ) ;
if ( F_16 ( V_12 ) ) {
V_1 = V_12 -> V_24 -> V_25 ;
V_4 |= V_58 ;
}
V_6 = F_1 ( V_1 , V_53 , V_54 , V_4 ) ;
if ( F_26 ( V_6 ) )
F_5 ( L_13 , F_6 ( V_12 ) , V_6 ) ;
return V_6 ;
}
static inline int F_27 ( struct V_11 * V_12 )
{
if ( V_12 -> V_27 )
return F_25 ( V_12 , 0 , V_12 -> V_7 ) ;
else
return F_25 ( V_12 , V_12 -> V_7 , 0 ) ;
}
static int F_28 ( struct V_11 * V_12 , unsigned int * V_59 ,
unsigned long V_9 )
{
unsigned long V_1 = * ( ( V_55 * ) & V_12 -> V_24 -> V_1 ) ;
unsigned int V_4 = V_60 ;
T_7 V_61 = 0 ;
int V_62 = 0 , V_6 ;
unsigned long V_63 = 0 ;
if ( V_12 -> V_64 . T_3 . V_65 && V_9 != 0 ) {
V_4 = V_66 ;
V_63 = V_9 ;
}
if ( F_16 ( V_12 ) ) {
V_1 = V_12 -> V_24 -> V_25 ;
V_4 |= V_58 ;
}
V_29:
F_29 ( ( V_9 && F_30 ( V_12 ) != V_67 ) ||
( V_9 && V_4 != V_66 ) ) ;
V_6 = F_3 ( V_1 , V_12 -> V_7 , V_59 , V_4 , V_63 ) ;
if ( F_26 ( * V_59 ) ) {
F_14 ( F_30 ( V_12 ) != V_67 || V_6 != 2 ) ;
V_62 ++ ;
if ( ! V_61 ) {
V_61 = F_31 () ;
goto V_29;
}
if ( ( F_31 () - V_61 ) < V_68 )
goto V_29;
}
if ( V_62 ) {
F_11 ( V_30 , V_12 -> V_24 ,
L_14 , F_6 ( V_12 ) , V_12 -> V_22 ) ;
F_11 ( V_30 , V_12 -> V_24 , L_15 , V_62 ) ;
}
return V_6 ;
}
static inline int F_32 ( struct V_11 * V_12 )
{
unsigned long V_1 = * ( ( V_55 * ) & V_12 -> V_24 -> V_1 ) ;
unsigned int V_4 = V_69 ;
int V_6 ;
F_11 ( V_38 , V_12 -> V_24 , L_16 , V_12 -> V_22 ) ;
F_9 ( V_12 , V_70 ) ;
if ( F_16 ( V_12 ) ) {
V_1 = V_12 -> V_24 -> V_25 ;
V_4 |= V_58 ;
}
V_6 = F_2 ( V_1 , V_12 -> V_7 , V_4 ) ;
if ( F_26 ( V_6 ) )
F_5 ( L_17 , F_6 ( V_12 ) , V_6 ) ;
return V_6 ;
}
static inline void F_33 ( struct V_11 * V_12 )
{
if ( F_34 ( V_12 ) )
F_35 ( V_12 ) ;
else
F_27 ( V_12 ) ;
}
int F_36 ( struct V_11 * V_12 , unsigned int V_40 ,
unsigned char * V_15 )
{
if ( F_37 ( V_12 ) )
F_27 ( V_12 ) ;
return F_15 ( V_12 , V_40 , V_15 , 1 , 0 , 0 ) ;
}
static inline void F_38 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_64 . T_4 . V_71 )
return;
V_12 -> V_64 . T_4 . V_71 = 0 ;
F_9 ( V_12 , V_72 ) ;
if ( F_16 ( V_12 ) ) {
F_19 ( V_12 , V_12 -> V_64 . T_4 . V_73 , V_51 ,
V_12 -> V_64 . T_4 . V_74 ) ;
V_12 -> V_64 . T_4 . V_74 = 0 ;
} else
F_21 ( V_12 , V_12 -> V_64 . T_4 . V_73 , V_51 ) ;
}
static inline void F_39 ( struct V_11 * V_12 , int V_17 )
{
int V_75 = 0 ;
V_12 -> V_76 . V_77 += V_17 ;
if ( V_17 == V_44 ) {
V_12 -> V_76 . V_78 [ 7 ] ++ ;
return;
}
while ( V_17 >>= 1 )
V_75 ++ ;
V_12 -> V_76 . V_78 [ V_75 ] ++ ;
}
static void F_40 ( struct V_11 * V_12 , int V_17 )
{
unsigned char V_15 = ( V_12 -> V_27 ) ? V_51 :
V_52 ;
V_12 -> V_79 |= V_80 ;
if ( ( ! V_12 -> V_27 &&
( V_12 -> V_81 [ V_12 -> V_82 ] -> V_83 [ 15 ] . V_84 ) == 0x10 ) ) {
F_9 ( V_12 , V_85 ) ;
F_11 ( V_38 , V_12 -> V_24 , L_18 ,
V_12 -> V_82 ) ;
goto V_86;
}
F_5 ( L_19 , F_6 ( V_12 ) ) ;
F_5 ( ( V_12 -> V_27 ) ? L_20 : L_21 , V_12 -> V_22 ) ;
F_5 ( L_22 , V_12 -> V_82 , V_17 ) ;
F_5 ( L_23 ,
V_12 -> V_81 [ V_12 -> V_82 ] -> V_83 [ 14 ] . V_84 ,
V_12 -> V_81 [ V_12 -> V_82 ] -> V_83 [ 15 ] . V_84 ) ;
V_86:
F_19 ( V_12 , V_12 -> V_82 , V_15 , V_17 ) ;
}
static inline void F_41 ( struct V_11 * V_12 , int V_17 )
{
int V_87 ;
F_11 ( V_38 , V_12 -> V_24 , L_24 , V_17 ) ;
if ( F_16 ( V_12 ) ) {
if ( ! V_12 -> V_64 . T_4 . V_71 ) {
V_12 -> V_64 . T_4 . V_71 = 1 ;
V_12 -> V_64 . T_4 . V_74 = V_17 ;
V_12 -> V_64 . T_4 . V_73 = V_12 -> V_82 ;
return;
}
F_19 ( V_12 , V_12 -> V_64 . T_4 . V_73 , V_51 ,
V_12 -> V_64 . T_4 . V_74 ) ;
V_12 -> V_64 . T_4 . V_74 = V_17 ;
V_12 -> V_64 . T_4 . V_73 = V_12 -> V_82 ;
return;
}
V_87 = F_42 ( V_12 -> V_82 , V_17 - 1 ) ;
if ( V_12 -> V_64 . T_4 . V_71 ) {
F_21 ( V_12 , V_87 , V_88 ) ;
F_21 ( V_12 , V_12 -> V_64 . T_4 . V_73 , V_51 ) ;
} else {
V_12 -> V_64 . T_4 . V_71 = 1 ;
F_21 ( V_12 , V_87 , V_88 ) ;
}
V_12 -> V_64 . T_4 . V_73 = V_87 ;
V_17 -- ;
if ( ! V_17 )
return;
F_19 ( V_12 , V_12 -> V_82 , V_51 , V_17 ) ;
}
static int F_43 ( struct V_11 * V_12 )
{
int V_17 , V_89 ;
unsigned char V_15 = 0 ;
V_12 -> V_90 = F_44 () ;
V_17 = F_45 ( F_46 ( & V_12 -> V_91 ) , V_44 ) ;
V_89 = F_42 ( V_12 -> V_82 , V_17 ) ;
if ( V_12 -> V_82 == V_89 )
goto T_3;
V_17 = F_15 ( V_12 , V_12 -> V_82 , & V_15 , V_17 , 1 , 0 ) ;
if ( ! V_17 )
goto T_3;
switch ( V_15 ) {
case V_92 :
F_41 ( V_12 , V_17 ) ;
V_12 -> V_82 = F_42 ( V_12 -> V_82 , V_17 ) ;
if ( F_47 ( V_17 , & V_12 -> V_91 ) == 0 )
F_9 ( V_12 , V_93 ) ;
if ( V_12 -> V_24 -> V_94 )
F_39 ( V_12 , V_17 ) ;
break;
case V_95 :
F_40 ( V_12 , V_17 ) ;
V_12 -> V_82 = F_42 ( V_12 -> V_82 , V_17 ) ;
F_47 ( V_17 , & V_12 -> V_91 ) ;
if ( V_12 -> V_24 -> V_94 )
F_48 ( V_12 , V_17 ) ;
break;
case V_96 :
case V_51 :
case V_88 :
if ( V_12 -> V_24 -> V_94 )
V_12 -> V_76 . V_97 ++ ;
F_11 ( V_38 , V_12 -> V_24 , L_25 ) ;
break;
default:
F_49 () ;
}
T_3:
return V_12 -> V_82 ;
}
static int F_50 ( struct V_11 * V_12 )
{
int V_40 ;
V_40 = F_43 ( V_12 ) ;
if ( ( V_40 != V_12 -> V_98 ) || V_12 -> V_79 ) {
V_12 -> V_98 = V_40 ;
if ( ! F_51 ( V_12 -> V_24 ) && V_99 )
V_12 -> V_64 . T_4 . V_90 = F_31 () ;
return 1 ;
} else
return 0 ;
}
static inline int F_52 ( struct V_11 * V_12 )
{
unsigned char V_15 = 0 ;
if ( ! F_46 ( & V_12 -> V_91 ) )
return 1 ;
if ( F_37 ( V_12 ) )
F_27 ( V_12 ) ;
F_18 ( V_12 , V_12 -> V_82 , & V_15 , 0 ) ;
if ( V_15 == V_92 || V_15 == V_95 )
return 0 ;
if ( F_51 ( V_12 -> V_24 ) )
return 1 ;
if ( V_100 )
return 1 ;
if ( F_31 () > V_12 -> V_64 . T_4 . V_90 + V_101 ) {
F_11 ( V_38 , V_12 -> V_24 , L_26 ,
V_12 -> V_82 ) ;
return 1 ;
} else
return 0 ;
}
static inline int F_53 ( struct V_11 * V_12 )
{
return ! V_12 -> V_27 && V_12 -> V_64 . T_3 . V_65 ;
}
static inline void F_54 ( struct V_50 * V_102 , struct V_11 * V_12 ,
int V_43 , struct V_103 * V_9 )
{
int V_104 ;
F_11 ( V_38 , V_102 , L_27 , V_43 ,
( unsigned long ) F_55 ( V_9 ) ) ;
F_11 ( V_38 , V_102 , L_28 ,
( unsigned long ) V_9 -> V_105 [ 0 ] ) ;
F_11 ( V_38 , V_102 , L_29 ,
( unsigned long ) V_9 -> V_105 [ 1 ] ) ;
F_11 ( V_38 , V_102 , L_30 ,
( unsigned long ) V_9 -> V_105 [ 2 ] ) ;
F_11 ( V_38 , V_102 , L_31 ,
( unsigned long ) V_9 -> V_105 [ 3 ] ) ;
F_11 ( V_38 , V_102 , L_32 ,
( unsigned long ) V_9 -> V_105 [ 4 ] ) ;
F_11 ( V_38 , V_102 , L_33 ,
( unsigned long ) V_9 -> V_105 [ 5 ] ) ;
F_11 ( V_38 , V_102 , L_34 , V_9 -> V_106 ) ;
F_11 ( V_38 , V_102 , L_35 , V_9 -> V_107 ) ;
F_11 ( V_38 , V_102 , L_36 , V_9 -> V_108 ) ;
F_11 ( V_38 , V_102 , L_37 , V_9 -> V_109 ) ;
F_11 ( V_38 , V_102 , L_38 , V_9 -> V_110 ) ;
F_11 ( V_38 , V_102 , L_39 , V_9 -> V_111 ) ;
F_11 ( V_38 , V_102 , L_40 , V_9 -> V_112 ) ;
for ( V_104 = 0 ; V_104 < V_113 ; ++ V_104 ) {
F_11 ( V_38 , V_102 , L_41 , V_104 ,
( unsigned long ) V_9 -> V_114 [ V_104 ] ) ;
F_11 ( V_38 , V_102 , L_42 , V_104 ,
( unsigned long ) V_12 -> V_81 [ V_43 ] -> V_83 [ V_104 ] . V_115 ) ;
F_11 ( V_38 , V_102 , L_43 , V_104 , V_9 -> V_116 [ V_104 ] ) ;
F_11 ( V_38 , V_102 , L_44 , V_104 ,
V_12 -> V_81 [ V_43 ] -> V_83 [ V_104 ] . V_117 ) ;
}
F_11 ( V_38 , V_102 , L_45 , ( unsigned long ) V_9 -> V_118 ) ;
for ( V_104 = 0 ; V_104 < 2 ; ++ V_104 ) {
F_11 ( V_38 , V_102 , L_46 , V_104 ,
( unsigned long ) V_9 -> V_119 [ V_104 ] ) ;
}
F_11 ( V_38 , V_102 , L_47 , ( unsigned long ) V_9 -> V_120 ) ;
F_11 ( V_38 , V_102 , L_48 , ( unsigned long ) V_9 -> V_121 ) ;
}
static inline void F_56 ( struct V_11 * V_12 , int V_16 , int V_17 )
{
unsigned char V_15 = 0 ;
int V_122 , V_123 = V_16 ;
if ( ! F_53 ( V_12 ) )
return;
for ( V_122 = 0 ; V_122 < V_17 ; ++ V_122 ) {
F_18 ( V_12 , V_123 , & V_15 , 0 ) ;
if ( V_15 == V_48 ) {
struct V_103 * V_9 = V_12 -> V_64 . T_3 . V_124 [ V_123 ] ;
if ( V_9 == NULL )
continue;
F_8 ( V_12 -> V_64 . T_3 . V_125 == NULL ) ;
V_12 -> V_64 . T_3 . V_125 [ V_123 ] . V_110 |=
V_126 ;
V_12 -> V_64 . T_3 . V_124 [ V_123 ] = NULL ;
} else if ( V_15 == V_49 ) {
F_8 ( V_12 -> V_64 . T_3 . V_125 == NULL ) ;
V_12 -> V_64 . T_3 . V_125 [ V_123 ] . V_9 = NULL ;
}
V_123 = F_17 ( V_123 ) ;
}
}
static inline unsigned long F_57 ( struct V_127 * V_12 ,
int V_40 )
{
unsigned long V_128 = 0 ;
if ( ! V_12 -> V_65 )
goto T_3;
if ( ! V_12 -> V_124 [ V_40 ] ) {
struct V_103 * V_9 = F_58 () ;
V_12 -> V_124 [ V_40 ] = V_9 ;
}
if ( V_12 -> V_124 [ V_40 ] ) {
F_8 ( V_12 -> V_125 == NULL ) ;
V_12 -> V_125 [ V_40 ] . V_110 = V_129 ;
V_12 -> V_125 [ V_40 ] . V_9 = V_12 -> V_124 [ V_40 ] ;
V_12 -> V_124 [ V_40 ] -> V_120 = ( T_7 ) V_12 -> V_125 [ V_40 ] . V_130 ;
V_128 = F_55 ( V_12 -> V_124 [ V_40 ] ) ;
F_8 ( V_128 & 0xFF ) ;
}
T_3:
return V_128 ;
}
static void F_59 ( struct V_11 * V_12 )
{
int V_16 = V_12 -> V_35 ;
int V_131 = V_12 -> V_82 ;
int V_17 ;
if ( F_26 ( V_12 -> V_24 -> V_15 != V_132 ) )
return;
V_17 = F_60 ( V_131 , V_16 ) ;
if ( V_12 -> V_27 ) {
F_9 ( V_12 , V_133 ) ;
F_11 ( V_38 , V_12 -> V_24 , L_49 , V_16 , V_17 ) ;
} else {
F_9 ( V_12 , V_134 ) ;
F_11 ( V_38 , V_12 -> V_24 , L_50 ,
V_16 , V_17 ) ;
}
F_56 ( V_12 , V_16 , V_17 ) ;
V_12 -> V_32 ( V_12 -> V_24 -> V_33 , V_12 -> V_79 , V_12 -> V_22 , V_16 , V_17 ,
V_12 -> V_24 -> V_36 ) ;
V_12 -> V_35 = V_131 ;
V_12 -> V_79 = 0 ;
}
static void F_61 ( struct V_11 * V_12 )
{
F_9 ( V_12 , V_135 ) ;
if ( ! F_50 ( V_12 ) )
return;
F_59 ( V_12 ) ;
if ( ! F_52 ( V_12 ) ) {
F_9 ( V_12 , V_136 ) ;
if ( F_62 ( V_12 -> V_24 -> V_15 != V_137 ) ) {
F_63 ( & V_12 -> V_138 ) ;
return;
}
}
F_38 ( V_12 ) ;
if ( ! F_52 ( V_12 ) ) {
F_9 ( V_12 , V_139 ) ;
if ( F_62 ( V_12 -> V_24 -> V_15 != V_137 ) )
F_63 ( & V_12 -> V_138 ) ;
}
}
void F_64 ( unsigned long V_140 )
{
struct V_11 * V_12 = (struct V_11 * ) V_140 ;
F_61 ( V_12 ) ;
}
static int F_65 ( struct V_11 * V_12 )
{
int V_17 , V_89 ;
unsigned char V_15 = 0 ;
V_12 -> V_90 = F_44 () ;
if ( F_37 ( V_12 ) )
if ( ( ( F_30 ( V_12 ) != V_67 ) &&
! F_34 ( V_12 ) ) ||
( F_30 ( V_12 ) == V_67 &&
F_66 ( V_12 ) ) )
F_27 ( V_12 ) ;
V_17 = F_45 ( F_46 ( & V_12 -> V_91 ) , V_44 ) ;
V_89 = F_42 ( V_12 -> V_82 , V_17 ) ;
if ( V_12 -> V_82 == V_89 )
goto T_3;
V_17 = F_15 ( V_12 , V_12 -> V_82 , & V_15 , V_17 , 0 , 1 ) ;
if ( ! V_17 )
goto T_3;
switch ( V_15 ) {
case V_48 :
F_49 () ;
case V_49 :
F_11 ( V_38 , V_12 -> V_24 ,
L_51 , V_12 -> V_22 , V_17 ) ;
F_47 ( V_17 , & V_12 -> V_91 ) ;
V_12 -> V_82 = F_42 ( V_12 -> V_82 , V_17 ) ;
if ( V_12 -> V_24 -> V_94 )
F_39 ( V_12 , V_17 ) ;
break;
case V_141 :
F_40 ( V_12 , V_17 ) ;
V_12 -> V_82 = F_42 ( V_12 -> V_82 , V_17 ) ;
F_47 ( V_17 , & V_12 -> V_91 ) ;
if ( V_12 -> V_24 -> V_94 )
F_48 ( V_12 , V_17 ) ;
break;
case V_142 :
if ( V_12 -> V_24 -> V_94 )
V_12 -> V_76 . V_97 ++ ;
F_11 ( V_38 , V_12 -> V_24 , L_52 ,
V_12 -> V_22 ) ;
break;
case V_52 :
case V_143 :
break;
default:
F_49 () ;
}
T_3:
return V_12 -> V_82 ;
}
static inline int F_67 ( struct V_11 * V_12 )
{
return F_46 ( & V_12 -> V_91 ) == 0 ;
}
static inline int F_68 ( struct V_11 * V_12 )
{
int V_40 ;
V_40 = F_65 ( V_12 ) ;
if ( ( V_40 != V_12 -> V_98 ) || V_12 -> V_79 ) {
V_12 -> V_98 = V_40 ;
F_11 ( V_38 , V_12 -> V_24 , L_53 , V_12 -> V_22 ) ;
return 1 ;
} else
return 0 ;
}
static int F_69 ( struct V_11 * V_12 , unsigned long V_9 )
{
int V_62 = 0 , V_6 ;
unsigned int V_59 ;
if ( ! F_70 ( V_12 ) )
return 0 ;
F_11 ( V_38 , V_12 -> V_24 , L_54 , V_12 -> V_22 ) ;
V_144:
F_9 ( V_12 , V_145 ) ;
V_6 = F_28 ( V_12 , & V_59 , V_9 ) ;
switch ( V_6 ) {
case 0 :
break;
case 2 :
if ( V_59 ) {
while ( ++ V_62 < V_146 ) {
F_71 ( V_147 ) ;
goto V_144;
}
F_5 ( L_55 , F_6 ( V_12 ) , V_12 -> V_22 ) ;
V_6 |= V_148 ;
} else
F_11 ( V_38 , V_12 -> V_24 , L_56 , V_12 -> V_22 ) ;
break;
case 1 :
case 3 :
F_5 ( L_57 , F_6 ( V_12 ) , V_6 ) ;
break;
}
if ( V_62 ) {
F_5 ( L_58 , F_6 ( V_12 ) , V_12 -> V_22 ) ;
F_5 ( L_15 , V_62 ) ;
}
return V_6 ;
}
static void F_72 ( struct V_11 * V_12 )
{
F_9 ( V_12 , V_149 ) ;
F_8 ( F_46 ( & V_12 -> V_91 ) < 0 ) ;
if ( F_68 ( V_12 ) )
F_59 ( V_12 ) ;
if ( F_30 ( V_12 ) == V_150 )
if ( ! F_34 ( V_12 ) && ! F_67 ( V_12 ) )
goto V_151;
if ( V_12 -> V_64 . T_3 . V_152 )
return;
if ( F_67 ( V_12 ) )
F_73 ( & V_12 -> V_64 . T_3 . V_153 ) ;
else
if ( ! F_74 ( & V_12 -> V_64 . T_3 . V_153 ) )
F_75 ( & V_12 -> V_64 . T_3 . V_153 , V_154 + 10 * V_155 ) ;
return;
V_151:
if ( F_26 ( V_12 -> V_24 -> V_15 == V_137 ) )
return;
F_63 ( & V_12 -> V_138 ) ;
}
void F_76 ( unsigned long V_140 )
{
struct V_11 * V_12 = (struct V_11 * ) V_140 ;
F_72 ( V_12 ) ;
}
void F_77 ( unsigned long V_140 )
{
struct V_11 * V_12 = (struct V_11 * ) V_140 ;
if ( F_26 ( V_12 -> V_24 -> V_15 == V_137 ) )
return;
F_63 ( & V_12 -> V_138 ) ;
}
static inline void F_78 ( struct V_11 * V_12 )
{
struct V_11 * T_3 ;
int V_43 ;
if ( ! F_34 ( V_12 ) )
return;
F_24 (q->irq_ptr, out, i)
if ( ! F_67 ( T_3 ) )
F_63 ( & T_3 -> V_138 ) ;
}
static void F_79 ( struct V_11 * V_12 )
{
F_9 ( V_12 , V_135 ) ;
if ( F_37 ( V_12 ) && F_80 ( V_12 ) )
F_33 ( V_12 ) ;
F_78 ( V_12 ) ;
if ( ! F_50 ( V_12 ) )
return;
F_59 ( V_12 ) ;
if ( ! F_52 ( V_12 ) ) {
F_9 ( V_12 , V_136 ) ;
if ( F_62 ( V_12 -> V_24 -> V_15 != V_137 ) ) {
F_63 ( & V_12 -> V_138 ) ;
return;
}
}
F_38 ( V_12 ) ;
if ( ! F_52 ( V_12 ) ) {
F_9 ( V_12 , V_139 ) ;
if ( F_62 ( V_12 -> V_24 -> V_15 != V_137 ) )
F_63 ( & V_12 -> V_138 ) ;
}
}
void F_81 ( unsigned long V_140 )
{
struct V_11 * V_12 = (struct V_11 * ) V_140 ;
F_79 ( V_12 ) ;
}
static inline void F_82 ( struct V_50 * V_24 ,
enum V_156 V_15 )
{
F_11 ( V_38 , V_24 , L_59 , V_15 ) ;
V_24 -> V_15 = V_15 ;
F_83 () ;
}
static void F_84 ( struct V_50 * V_24 , struct V_157 * V_157 )
{
if ( V_157 -> V_158 . V_159 . V_160 . V_161 ) {
F_5 ( L_60 , V_24 -> V_1 . V_162 ) ;
F_85 ( V_157 , 64 ) ;
F_85 ( V_157 -> V_163 , 64 ) ;
}
}
static void F_86 ( struct V_50 * V_24 )
{
int V_43 ;
struct V_11 * V_12 ;
if ( F_26 ( V_24 -> V_15 == V_137 ) )
return;
F_23 (irq_ptr, q, i) {
if ( V_12 -> V_64 . T_4 . V_164 ) {
if ( F_87 ( V_165 ,
& V_12 -> V_64 . T_4 . V_166 ) ) {
F_9 ( V_12 , V_167 ) ;
continue;
}
V_12 -> V_64 . T_4 . V_164 ( V_12 -> V_24 -> V_33 , V_12 -> V_22 ,
V_12 -> V_24 -> V_36 ) ;
} else {
F_63 ( & V_12 -> V_138 ) ;
}
}
if ( ! F_34 ( V_12 ) )
return;
F_24 (irq_ptr, q, i) {
if ( F_67 ( V_12 ) )
continue;
if ( F_37 ( V_12 ) && F_88 ( V_12 ) )
F_27 ( V_12 ) ;
F_63 ( & V_12 -> V_138 ) ;
}
}
static void F_89 ( struct V_168 * V_33 ,
unsigned long V_169 , int V_170 , int V_171 )
{
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
struct V_11 * V_12 ;
int V_17 ;
F_5 ( L_61 , V_24 -> V_1 . V_162 ) ;
F_5 ( L_62 , V_169 ) ;
F_5 ( L_63 , V_171 , V_170 ) ;
if ( V_24 -> V_28 ) {
V_12 = V_24 -> V_174 [ 0 ] ;
} else if ( V_24 -> V_175 ) {
V_12 = V_24 -> V_176 [ 0 ] ;
} else {
F_90 () ;
goto V_177;
}
V_17 = F_60 ( V_12 -> V_82 , V_12 -> V_35 ) ;
V_12 -> V_32 ( V_12 -> V_24 -> V_33 , V_34 ,
V_12 -> V_22 , V_12 -> V_35 , V_17 , V_24 -> V_36 ) ;
V_177:
F_82 ( V_24 , V_137 ) ;
F_91 () ;
}
static void F_92 ( struct V_168 * V_33 , int V_170 ,
int V_171 )
{
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
F_11 ( V_38 , V_24 , L_64 ) ;
if ( V_170 )
goto error;
if ( V_171 & ~ ( V_178 | V_179 ) )
goto error;
if ( ! ( V_171 & V_178 ) )
goto error;
F_82 ( V_24 , V_180 ) ;
return;
error:
F_5 ( L_65 , V_24 -> V_1 . V_162 ) ;
F_5 ( L_63 , V_171 , V_170 ) ;
F_82 ( V_24 , V_181 ) ;
}
void F_93 ( struct V_168 * V_33 , unsigned long V_169 ,
struct V_157 * V_157 )
{
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
int V_170 , V_171 ;
if ( ! V_169 || ! V_24 ) {
F_5 ( L_66 , V_33 -> V_172 -> V_1 . V_162 ) ;
return;
}
if ( V_24 -> V_94 )
V_24 -> V_182 . V_183 ++ ;
if ( F_94 ( V_157 ) ) {
switch ( F_95 ( V_157 ) ) {
case - V_14 :
F_5 ( L_67 , V_24 -> V_1 . V_162 ) ;
F_82 ( V_24 , V_181 ) ;
F_96 ( & V_33 -> V_172 -> V_184 ) ;
return;
default:
F_14 ( 1 ) ;
return;
}
}
F_84 ( V_24 , V_157 ) ;
V_170 = V_157 -> V_185 . V_186 . V_170 ;
V_171 = V_157 -> V_185 . V_186 . V_171 ;
switch ( V_24 -> V_15 ) {
case V_187 :
F_92 ( V_33 , V_170 , V_171 ) ;
break;
case V_188 :
F_82 ( V_24 , V_187 ) ;
break;
case V_180 :
case V_132 :
if ( V_170 & V_189 ) {
F_86 ( V_24 ) ;
return;
}
if ( V_170 || V_171 )
F_89 ( V_33 , V_169 , V_170 ,
V_171 ) ;
break;
case V_137 :
break;
default:
F_14 ( 1 ) ;
}
F_96 ( & V_33 -> V_172 -> V_184 ) ;
}
int F_97 ( struct V_168 * V_33 ,
struct V_190 * V_140 )
{
if ( ! V_33 || ! V_33 -> V_172 )
return - V_191 ;
F_98 ( L_68 , V_33 -> V_172 -> V_1 . V_162 ) ;
return F_99 ( NULL , & V_33 -> V_172 -> V_1 , V_140 ) ;
}
static void F_100 ( struct V_168 * V_33 )
{
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
struct V_11 * V_12 ;
int V_43 ;
F_23 (irq_ptr, q, i)
F_101 ( & V_12 -> V_138 ) ;
F_24 (irq_ptr, q, i) {
F_73 ( & V_12 -> V_64 . T_3 . V_153 ) ;
F_101 ( & V_12 -> V_138 ) ;
}
}
int F_102 ( struct V_168 * V_33 , int V_192 )
{
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
int V_19 ;
unsigned long V_110 ;
if ( ! V_24 )
return - V_193 ;
F_8 ( F_103 () ) ;
F_98 ( L_69 , V_33 -> V_172 -> V_1 . V_162 ) ;
F_104 ( & V_24 -> V_194 ) ;
if ( V_24 -> V_15 == V_187 ) {
F_105 ( & V_24 -> V_194 ) ;
return 0 ;
}
F_82 ( V_24 , V_137 ) ;
F_106 ( V_24 ) ;
F_100 ( V_33 ) ;
F_107 ( V_24 , V_33 ) ;
F_108 ( F_109 ( V_33 ) , V_110 ) ;
if ( V_192 & V_195 )
V_19 = F_110 ( V_33 , V_196 ) ;
else
V_19 = F_111 ( V_33 , V_196 ) ;
if ( V_19 ) {
F_5 ( L_70 , V_24 -> V_1 . V_162 ) ;
F_5 ( L_71 , V_19 ) ;
goto V_197;
}
F_82 ( V_24 , V_188 ) ;
F_112 ( F_109 ( V_33 ) , V_110 ) ;
F_113 ( V_33 -> V_172 -> V_184 ,
V_24 -> V_15 == V_187 ||
V_24 -> V_15 == V_181 ,
10 * V_155 ) ;
F_108 ( F_109 ( V_33 ) , V_110 ) ;
V_197:
F_114 ( V_24 ) ;
if ( ( void * ) V_33 -> V_32 == ( void * ) F_93 )
V_33 -> V_32 = V_24 -> V_198 ;
F_112 ( F_109 ( V_33 ) , V_110 ) ;
F_82 ( V_24 , V_187 ) ;
F_105 ( & V_24 -> V_194 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
int F_115 ( struct V_168 * V_33 )
{
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
if ( ! V_24 )
return - V_193 ;
F_98 ( L_72 , V_33 -> V_172 -> V_1 . V_162 ) ;
F_104 ( & V_24 -> V_194 ) ;
if ( V_24 -> V_199 != NULL ) {
F_116 ( V_24 -> V_199 ) ;
V_24 -> V_199 = NULL ;
}
V_33 -> V_172 -> V_173 = NULL ;
F_105 ( & V_24 -> V_194 ) ;
F_117 ( V_24 ) ;
return 0 ;
}
int F_118 ( struct V_200 * V_201 )
{
struct V_50 * V_24 ;
F_98 ( L_73 , V_201 -> V_33 -> V_172 -> V_1 . V_162 ) ;
if ( ( V_201 -> V_202 && ! V_201 -> V_203 ) ||
( V_201 -> V_204 && ! V_201 -> V_205 ) )
return - V_191 ;
if ( ( V_201 -> V_202 > V_206 ) ||
( V_201 -> V_204 > V_206 ) )
return - V_191 ;
if ( ( ! V_201 -> V_207 ) ||
( ! V_201 -> V_208 ) )
return - V_191 ;
V_24 = ( void * ) F_119 ( V_209 | V_210 ) ;
if ( ! V_24 )
goto V_211;
F_120 ( & V_24 -> V_194 ) ;
F_121 ( V_201 , V_24 ) ;
V_24 -> V_212 = F_119 ( V_209 ) ;
if ( ! V_24 -> V_212 )
goto V_213;
V_24 -> V_214 = (struct V_214 * ) F_119 ( V_209 | V_210 ) ;
if ( ! V_24 -> V_214 )
goto V_213;
F_14 ( ( unsigned long ) V_24 -> V_214 & 0xfff ) ;
if ( F_122 ( V_24 , V_201 -> V_202 ,
V_201 -> V_204 ) )
goto V_213;
V_201 -> V_33 -> V_172 -> V_173 = V_24 ;
F_82 ( V_24 , V_187 ) ;
return 0 ;
V_213:
F_117 ( V_24 ) ;
V_211:
return - V_215 ;
}
static void F_123 ( struct V_50 * V_24 )
{
struct V_11 * V_12 = V_24 -> V_174 [ 0 ] ;
int V_43 , V_65 = 0 ;
if ( V_24 -> V_28 > 1 && F_30 ( V_12 ) == V_67 )
V_65 = 1 ;
F_24 (irq_ptr, q, i) {
if ( V_65 ) {
if ( F_124 ( & V_12 -> V_64 . T_3 ) < 0 ) {
V_65 = 0 ;
continue;
}
} else
F_125 ( & V_12 -> V_64 . T_3 ) ;
}
F_98 ( L_74 , V_65 ) ;
}
int F_126 ( struct V_200 * V_201 )
{
struct V_50 * V_24 ;
struct V_168 * V_33 = V_201 -> V_33 ;
unsigned long V_216 ;
int V_19 ;
F_98 ( L_75 , V_33 -> V_172 -> V_1 . V_162 ) ;
V_24 = V_33 -> V_172 -> V_173 ;
if ( ! V_24 )
return - V_193 ;
if ( V_33 -> V_172 -> V_15 != V_217 )
return - V_191 ;
F_104 ( & V_24 -> V_194 ) ;
F_127 ( V_201 ) ;
V_19 = F_128 ( V_24 ) ;
if ( V_19 ) {
F_105 ( & V_24 -> V_194 ) ;
F_102 ( V_33 , V_195 ) ;
return V_19 ;
}
V_24 -> V_218 . V_219 = V_24 -> V_220 . V_186 ;
V_24 -> V_218 . V_110 = V_221 ;
V_24 -> V_218 . V_17 = V_24 -> V_220 . V_17 ;
V_24 -> V_218 . V_222 = ( V_55 ) ( ( V_223 ) V_24 -> V_214 ) ;
F_108 ( F_109 ( V_33 ) , V_216 ) ;
F_129 ( V_33 , 0 ) ;
V_19 = F_130 ( V_33 , & V_24 -> V_218 , V_224 , 0 , 0 ) ;
if ( V_19 ) {
F_5 ( L_76 , V_24 -> V_1 . V_162 ) ;
F_5 ( L_77 , V_19 ) ;
}
F_112 ( F_109 ( V_33 ) , V_216 ) ;
if ( V_19 ) {
F_105 ( & V_24 -> V_194 ) ;
F_102 ( V_33 , V_195 ) ;
return V_19 ;
}
F_113 ( V_33 -> V_172 -> V_184 ,
V_24 -> V_15 == V_180 ||
V_24 -> V_15 == V_181 , V_155 ) ;
if ( V_24 -> V_15 != V_180 ) {
F_105 ( & V_24 -> V_194 ) ;
F_102 ( V_33 , V_195 ) ;
return - V_14 ;
}
F_131 ( V_24 ) ;
F_123 ( V_24 ) ;
F_22 ( V_24 ) ;
F_105 ( & V_24 -> V_194 ) ;
F_132 ( V_24 , V_33 ) ;
F_133 ( V_24 , V_33 ) ;
return 0 ;
}
int F_134 ( struct V_168 * V_33 )
{
struct V_50 * V_24 ;
int V_19 ;
unsigned long V_216 ;
F_98 ( L_78 , V_33 -> V_172 -> V_1 . V_162 ) ;
V_24 = V_33 -> V_172 -> V_173 ;
if ( ! V_24 )
return - V_193 ;
if ( V_33 -> V_172 -> V_15 != V_217 )
return - V_191 ;
F_104 ( & V_24 -> V_194 ) ;
if ( V_24 -> V_15 == V_187 ) {
V_19 = - V_225 ;
goto T_3;
}
V_24 -> V_218 . V_219 = V_24 -> V_226 . V_186 ;
V_24 -> V_218 . V_110 = V_221 ;
V_24 -> V_218 . V_17 = V_24 -> V_226 . V_17 ;
V_24 -> V_218 . V_222 = 0 ;
F_108 ( F_109 ( V_33 ) , V_216 ) ;
F_135 ( V_33 , V_227 ) ;
V_19 = F_130 ( V_33 , & V_24 -> V_218 , V_228 ,
0 , V_229 ) ;
if ( V_19 ) {
F_5 ( L_79 , V_24 -> V_1 . V_162 ) ;
F_5 ( L_77 , V_19 ) ;
}
F_112 ( F_109 ( V_33 ) , V_216 ) ;
if ( V_19 )
goto T_3;
if ( F_51 ( V_24 ) )
F_136 ( V_24 ) ;
F_137 ( 5 ) ;
switch ( V_24 -> V_15 ) {
case V_137 :
case V_181 :
V_19 = - V_14 ;
break;
default:
F_82 ( V_24 , V_132 ) ;
V_19 = 0 ;
}
T_3:
F_105 ( & V_24 -> V_194 ) ;
return V_19 ;
}
static inline int F_138 ( int V_40 , int V_16 , int V_17 )
{
int V_131 = F_42 ( V_16 , V_17 ) ;
if ( V_131 > V_16 ) {
if ( V_40 >= V_16 && V_40 < V_131 )
return 1 ;
else
return 0 ;
}
if ( ( V_40 >= V_16 && V_40 <= V_45 ) ||
( V_40 < V_131 ) )
return 1 ;
else
return 0 ;
}
static int F_139 ( struct V_11 * V_12 , unsigned int V_230 ,
int V_40 , int V_17 )
{
int V_231 , V_232 ;
F_9 ( V_12 , V_233 ) ;
if ( ! V_12 -> V_64 . T_4 . V_71 )
goto V_86;
if ( V_17 == V_45 ) {
V_12 -> V_64 . T_4 . V_71 = 0 ;
V_12 -> V_64 . T_4 . V_74 = 0 ;
goto V_86;
} else if ( F_138 ( V_12 -> V_64 . T_4 . V_73 , V_40 , V_17 ) ) {
if ( F_16 ( V_12 ) ) {
V_232 = F_42 ( V_40 , V_17 ) ;
V_232 = F_60 ( V_232 , V_12 -> V_64 . T_4 . V_73 ) ;
V_12 -> V_64 . T_4 . V_74 -= V_232 ;
if ( V_12 -> V_64 . T_4 . V_74 <= 0 ) {
V_12 -> V_64 . T_4 . V_71 = 0 ;
V_12 -> V_64 . T_4 . V_74 = 0 ;
goto V_86;
}
V_12 -> V_64 . T_4 . V_73 = F_42 ( V_12 -> V_64 . T_4 . V_73 , V_232 ) ;
}
else
V_12 -> V_64 . T_4 . V_71 = 0 ;
}
V_86:
V_17 = F_19 ( V_12 , V_40 , V_96 , V_17 ) ;
V_231 = F_140 ( V_17 , & V_12 -> V_91 ) - V_17 ;
F_8 ( V_231 + V_17 > V_45 ) ;
if ( F_141 ( V_12 ) )
return F_32 ( V_12 ) ;
return 0 ;
}
static int F_142 ( struct V_11 * V_12 , unsigned int V_230 ,
int V_40 , int V_17 )
{
unsigned char V_15 = 0 ;
int V_231 , V_19 = 0 ;
F_9 ( V_12 , V_234 ) ;
V_17 = F_19 ( V_12 , V_40 , V_142 , V_17 ) ;
V_231 = F_140 ( V_17 , & V_12 -> V_91 ) ;
F_8 ( V_231 > V_45 ) ;
if ( V_231 == V_45 )
F_9 ( V_12 , V_235 ) ;
if ( V_230 & V_236 ) {
V_12 -> V_64 . T_3 . V_152 = 1 ;
F_9 ( V_12 , V_237 ) ;
} else
V_12 -> V_64 . T_3 . V_152 = 0 ;
if ( F_30 ( V_12 ) == V_67 ) {
unsigned long V_128 = 0 ;
F_29 ( V_17 > 1 && ! F_66 ( V_12 ) ) ;
V_128 = F_57 ( & V_12 -> V_64 . T_3 , V_40 ) ;
V_19 = F_69 ( V_12 , V_128 ) ;
} else if ( F_37 ( V_12 ) ) {
V_19 = F_27 ( V_12 ) ;
} else {
F_18 ( V_12 , F_143 ( V_40 ) , & V_15 , 0 ) ;
if ( V_15 != V_142 )
V_19 = F_69 ( V_12 , 0 ) ;
else
F_9 ( V_12 , V_238 ) ;
}
if ( V_231 >= V_12 -> V_64 . T_3 . V_239 || V_19 )
F_63 ( & V_12 -> V_138 ) ;
else
if ( ! F_74 ( & V_12 -> V_64 . T_3 . V_153 ) )
F_75 ( & V_12 -> V_64 . T_3 . V_153 , V_154 + V_155 ) ;
return V_19 ;
}
int F_144 ( struct V_168 * V_33 , unsigned int V_230 ,
int V_240 , unsigned int V_40 , unsigned int V_17 )
{
struct V_50 * V_24 ;
if ( V_40 >= V_45 || V_17 > V_45 )
return - V_191 ;
V_24 = V_33 -> V_172 -> V_173 ;
if ( ! V_24 )
return - V_193 ;
F_11 ( V_38 , V_24 ,
L_80 , V_230 , V_40 , V_17 ) ;
if ( V_24 -> V_15 != V_132 )
return - V_225 ;
if ( ! V_17 )
return 0 ;
if ( V_230 & V_241 )
return F_139 ( V_24 -> V_174 [ V_240 ] ,
V_230 , V_40 , V_17 ) ;
else if ( V_230 & V_242 )
return F_142 ( V_24 -> V_176 [ V_240 ] ,
V_230 , V_40 , V_17 ) ;
return - V_191 ;
}
int F_145 ( struct V_168 * V_33 , int V_22 )
{
struct V_11 * V_12 ;
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
if ( ! V_24 )
return - V_193 ;
V_12 = V_24 -> V_174 [ V_22 ] ;
F_14 ( F_146 ( V_12 ) ) ;
F_147 ( V_24 ) ;
F_38 ( V_12 ) ;
F_148 ( V_165 , & V_12 -> V_64 . T_4 . V_166 ) ;
if ( F_149 ( V_24 ) )
goto V_243;
if ( ! F_52 ( V_12 ) )
goto V_243;
return 0 ;
V_243:
if ( F_87 ( V_165 ,
& V_12 -> V_64 . T_4 . V_166 ) )
return 0 ;
else
return 1 ;
}
int F_150 ( struct V_168 * V_33 , int V_22 , int * V_40 ,
int * error )
{
struct V_11 * V_12 ;
int V_16 , V_131 ;
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
if ( ! V_24 )
return - V_193 ;
V_12 = V_24 -> V_174 [ V_22 ] ;
F_14 ( F_146 ( V_12 ) ) ;
if ( F_37 ( V_12 ) )
F_33 ( V_12 ) ;
F_78 ( V_12 ) ;
if ( ! F_50 ( V_12 ) )
return 0 ;
if ( F_26 ( V_12 -> V_24 -> V_15 != V_132 ) )
return - V_14 ;
V_16 = V_12 -> V_35 ;
V_131 = V_12 -> V_82 ;
* V_40 = V_16 ;
* error = V_12 -> V_79 ;
V_12 -> V_35 = V_131 ;
V_12 -> V_79 = 0 ;
return F_60 ( V_131 , V_16 ) ;
}
int F_151 ( struct V_168 * V_33 , int V_22 )
{
struct V_11 * V_12 ;
struct V_50 * V_24 = V_33 -> V_172 -> V_173 ;
if ( ! V_24 )
return - V_193 ;
V_12 = V_24 -> V_174 [ V_22 ] ;
if ( F_87 ( V_165 ,
& V_12 -> V_64 . T_4 . V_166 ) )
return 0 ;
else
return 1 ;
}
static int T_8 F_152 ( void )
{
int V_19 ;
V_19 = F_153 () ;
if ( V_19 )
return V_19 ;
V_19 = F_154 () ;
if ( V_19 )
goto V_244;
V_19 = F_155 () ;
if ( V_19 )
goto V_245;
V_19 = F_156 () ;
if ( V_19 )
goto V_246;
return 0 ;
V_246:
F_157 () ;
V_245:
F_158 () ;
V_244:
F_159 () ;
return V_19 ;
}
static void T_9 F_160 ( void )
{
F_161 () ;
F_157 () ;
F_158 () ;
F_159 () ;
}
