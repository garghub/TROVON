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
: "d" (__fc), "d" (__schid), "d" (__mask) : "cc");
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
int V_6 ;
asm volatile(
" siga 0\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc), "+d" (__fc), "+d" (__aob)
: "d" (__schid), "d" (__mask)
: "cc");
* V_8 = T_1 >> 31 ;
return V_6 ;
}
static inline int F_4 ( struct V_10 * V_11 , unsigned int V_12 )
{
if ( V_12 == 0 || V_12 == 32 )
return 0 ;
if ( V_12 == 97 )
return 1 ;
if ( V_12 == 96 )
return 2 ;
F_5 ( L_5 , F_6 ( V_11 ) , V_12 ) ;
return - V_13 ;
}
static int F_7 ( struct V_10 * V_11 , unsigned char * V_14 ,
int V_15 , int V_16 , int V_17 )
{
int V_18 , V_19 = V_16 , V_20 = V_15 , V_21 = V_11 -> V_21 , V_22 = 0 ;
unsigned int V_12 = 0 ;
F_8 ( ! V_11 -> V_23 -> V_24 ) ;
F_9 ( V_11 , V_25 ) ;
if ( ! V_11 -> V_26 )
V_21 += V_11 -> V_23 -> V_27 ;
V_28:
V_12 = F_10 ( V_11 -> V_23 -> V_24 , V_14 , V_21 , & V_20 , & V_19 ,
V_17 ) ;
V_18 = F_4 ( V_11 , V_12 ) ;
if ( ! V_18 )
return V_16 - V_19 ;
if ( V_18 == 1 ) {
F_11 ( V_29 , V_11 -> V_23 , L_6 , V_12 ) ;
goto V_28;
}
if ( V_18 == 2 ) {
F_8 ( V_19 == V_16 ) ;
F_9 ( V_11 , V_30 ) ;
F_11 ( V_29 , V_11 -> V_23 , L_7 ,
V_19 ) ;
if ( ! V_22 ++ )
goto V_28;
else
return V_16 - V_19 ;
}
F_5 ( L_8 , F_6 ( V_11 ) ) ;
F_5 ( L_9 , V_16 , V_19 , V_21 ) ;
V_11 -> V_31 ( V_11 -> V_23 -> V_32 , V_33 ,
V_11 -> V_21 , V_11 -> V_34 , V_16 , V_11 -> V_23 -> V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 , unsigned char V_14 , int V_15 ,
int V_16 )
{
unsigned int V_12 = 0 ;
int V_19 = V_16 , V_20 = V_15 ;
int V_21 = V_11 -> V_21 ;
int V_18 ;
if ( ! V_16 )
return 0 ;
F_8 ( ! V_11 -> V_23 -> V_24 ) ;
F_9 ( V_11 , V_36 ) ;
if ( ! V_11 -> V_26 )
V_21 += V_11 -> V_23 -> V_27 ;
V_28:
V_12 = F_13 ( V_11 -> V_23 -> V_24 , V_14 , V_21 , & V_20 , & V_19 ) ;
V_18 = F_4 ( V_11 , V_12 ) ;
if ( ! V_18 ) {
F_14 ( V_19 ) ;
return V_16 - V_19 ;
}
if ( V_18 == 1 || V_18 == 2 ) {
F_11 ( V_37 , V_11 -> V_23 , L_10 , V_12 ) ;
F_9 ( V_11 , V_38 ) ;
goto V_28;
}
F_5 ( L_11 , F_6 ( V_11 ) ) ;
F_5 ( L_9 , V_16 , V_19 , V_21 ) ;
V_11 -> V_31 ( V_11 -> V_23 -> V_32 , V_39 ,
V_11 -> V_21 , V_11 -> V_34 , V_16 , V_11 -> V_23 -> V_35 ) ;
return 0 ;
}
static inline int F_15 ( struct V_10 * V_11 , unsigned int V_40 ,
unsigned char * V_14 , unsigned int V_16 ,
int V_17 , int V_41 )
{
unsigned char V_42 = 0 ;
int V_43 ;
F_8 ( V_40 > V_44 ) ;
F_8 ( V_16 > V_45 ) ;
if ( F_16 ( V_11 ) )
return F_7 ( V_11 , V_14 , V_40 , V_16 , V_17 ) ;
for ( V_43 = 0 ; V_43 < V_16 ; V_43 ++ ) {
if ( ! V_42 ) {
V_42 = V_11 -> V_46 . V_47 [ V_40 ] ;
if ( V_41 && V_42 == V_48 )
V_42 = V_49 ;
} else if ( V_41 ) {
if ( ( V_11 -> V_46 . V_47 [ V_40 ] & V_42 ) != V_42 )
break;
} else if ( V_11 -> V_46 . V_47 [ V_40 ] != V_42 )
break;
V_40 = F_17 ( V_40 ) ;
}
* V_14 = V_42 ;
return V_43 ;
}
static inline int F_18 ( struct V_10 * V_11 , unsigned int V_40 ,
unsigned char * V_14 , int V_17 )
{
return F_15 ( V_11 , V_40 , V_14 , 1 , V_17 , 0 ) ;
}
static inline int F_19 ( struct V_10 * V_11 , int V_40 ,
unsigned char V_14 , int V_16 )
{
int V_43 ;
F_8 ( V_40 > V_44 ) ;
F_8 ( V_16 > V_45 ) ;
if ( F_16 ( V_11 ) )
return F_12 ( V_11 , V_14 , V_40 , V_16 ) ;
for ( V_43 = 0 ; V_43 < V_16 ; V_43 ++ ) {
F_20 ( & V_11 -> V_46 . V_47 [ V_40 ] , V_14 ) ;
V_40 = F_17 ( V_40 ) ;
}
return V_16 ;
}
static inline int F_21 ( struct V_10 * V_11 , int V_40 ,
unsigned char V_14 )
{
return F_19 ( V_11 , V_40 , V_14 , 1 ) ;
}
static void F_22 ( struct V_50 * V_23 )
{
struct V_10 * V_11 ;
int V_43 ;
F_23 (irq_ptr, q, i)
F_19 ( V_11 , 0 , V_51 ,
V_45 ) ;
F_24 (irq_ptr, q, i)
F_19 ( V_11 , 0 , V_52 ,
V_45 ) ;
}
static inline int F_25 ( struct V_10 * V_11 , unsigned int V_53 ,
unsigned int V_54 )
{
unsigned long V_1 = * ( ( V_55 * ) & V_11 -> V_23 -> V_1 ) ;
unsigned int V_4 = V_56 ;
int V_6 ;
F_11 ( V_37 , V_11 -> V_23 , L_12 , V_11 -> V_21 ) ;
F_9 ( V_11 , V_57 ) ;
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_23 -> V_24 ;
V_4 |= V_58 ;
}
V_6 = F_1 ( V_1 , V_53 , V_54 , V_4 ) ;
if ( F_26 ( V_6 ) )
F_5 ( L_13 , F_6 ( V_11 ) , V_6 ) ;
return ( V_6 ) ? - V_13 : 0 ;
}
static inline int F_27 ( struct V_10 * V_11 )
{
if ( V_11 -> V_26 )
return F_25 ( V_11 , 0 , V_11 -> V_7 ) ;
else
return F_25 ( V_11 , V_11 -> V_7 , 0 ) ;
}
static int F_28 ( struct V_10 * V_11 , unsigned int * V_59 ,
unsigned long V_9 )
{
unsigned long V_1 = * ( ( V_55 * ) & V_11 -> V_23 -> V_1 ) ;
unsigned int V_4 = V_60 ;
T_7 V_61 = 0 ;
int V_62 = 0 , V_6 ;
unsigned long V_63 = 0 ;
if ( V_11 -> V_64 . T_3 . V_65 && V_9 != 0 ) {
V_4 = V_66 ;
V_63 = V_9 ;
}
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_23 -> V_24 ;
V_4 |= V_58 ;
}
V_28:
F_29 ( ( V_9 && F_30 ( V_11 ) != V_67 ) ||
( V_9 && V_4 != V_66 ) ) ;
V_6 = F_3 ( V_1 , V_11 -> V_7 , V_59 , V_4 , V_63 ) ;
if ( F_26 ( * V_59 ) ) {
F_14 ( F_30 ( V_11 ) != V_67 || V_6 != 2 ) ;
V_62 ++ ;
if ( ! V_61 ) {
V_61 = F_31 () ;
goto V_28;
}
if ( ( F_31 () - V_61 ) < V_68 )
goto V_28;
}
if ( V_62 ) {
F_11 ( V_29 , V_11 -> V_23 ,
L_14 , F_6 ( V_11 ) , V_11 -> V_21 ) ;
F_11 ( V_29 , V_11 -> V_23 , L_15 , V_62 ) ;
}
return V_6 ;
}
static inline int F_32 ( struct V_10 * V_11 )
{
unsigned long V_1 = * ( ( V_55 * ) & V_11 -> V_23 -> V_1 ) ;
unsigned int V_4 = V_69 ;
int V_6 ;
F_11 ( V_37 , V_11 -> V_23 , L_16 , V_11 -> V_21 ) ;
F_9 ( V_11 , V_70 ) ;
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_23 -> V_24 ;
V_4 |= V_58 ;
}
V_6 = F_2 ( V_1 , V_11 -> V_7 , V_4 ) ;
if ( F_26 ( V_6 ) )
F_5 ( L_17 , F_6 ( V_11 ) , V_6 ) ;
return ( V_6 ) ? - V_13 : 0 ;
}
static inline void F_33 ( struct V_10 * V_11 )
{
if ( F_34 ( V_11 ) )
F_35 ( V_11 ) ;
else
F_27 ( V_11 ) ;
}
int F_36 ( struct V_10 * V_11 , unsigned int V_40 ,
unsigned char * V_14 )
{
if ( F_37 ( V_11 ) )
F_27 ( V_11 ) ;
return F_15 ( V_11 , V_40 , V_14 , 1 , 0 , 0 ) ;
}
static inline void F_38 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_64 . T_4 . V_71 )
return;
V_11 -> V_64 . T_4 . V_71 = 0 ;
F_9 ( V_11 , V_72 ) ;
if ( F_16 ( V_11 ) ) {
F_19 ( V_11 , V_11 -> V_64 . T_4 . V_73 , V_51 ,
V_11 -> V_64 . T_4 . V_74 ) ;
V_11 -> V_64 . T_4 . V_74 = 0 ;
} else
F_21 ( V_11 , V_11 -> V_64 . T_4 . V_73 , V_51 ) ;
}
static inline void F_39 ( struct V_10 * V_11 , int V_16 )
{
int V_75 = 0 ;
V_11 -> V_76 . V_77 += V_16 ;
if ( V_16 == V_44 ) {
V_11 -> V_76 . V_78 [ 7 ] ++ ;
return;
}
while ( V_16 >>= 1 )
V_75 ++ ;
V_11 -> V_76 . V_78 [ V_75 ] ++ ;
}
static void F_40 ( struct V_10 * V_11 , int V_16 )
{
unsigned char V_14 = ( V_11 -> V_26 ) ? V_51 :
V_52 ;
V_11 -> V_79 = V_80 ;
if ( ( ! V_11 -> V_26 &&
( V_11 -> V_81 [ V_11 -> V_82 ] -> V_83 [ 15 ] . V_84 ) == 0x10 ) ) {
F_9 ( V_11 , V_85 ) ;
F_11 ( V_37 , V_11 -> V_23 , L_18 ,
V_11 -> V_82 ) ;
goto V_86;
}
F_5 ( L_19 , F_6 ( V_11 ) ) ;
F_5 ( ( V_11 -> V_26 ) ? L_20 : L_21 , V_11 -> V_21 ) ;
F_5 ( L_22 , V_11 -> V_82 , V_16 ) ;
F_5 ( L_23 ,
V_11 -> V_81 [ V_11 -> V_82 ] -> V_83 [ 14 ] . V_84 ,
V_11 -> V_81 [ V_11 -> V_82 ] -> V_83 [ 15 ] . V_84 ) ;
V_86:
F_19 ( V_11 , V_11 -> V_82 , V_14 , V_16 ) ;
}
static inline void F_41 ( struct V_10 * V_11 , int V_16 )
{
int V_87 ;
F_11 ( V_37 , V_11 -> V_23 , L_24 , V_16 ) ;
if ( F_16 ( V_11 ) ) {
if ( ! V_11 -> V_64 . T_4 . V_71 ) {
V_11 -> V_64 . T_4 . V_71 = 1 ;
V_11 -> V_64 . T_4 . V_74 = V_16 ;
V_11 -> V_64 . T_4 . V_73 = V_11 -> V_82 ;
return;
}
F_19 ( V_11 , V_11 -> V_64 . T_4 . V_73 , V_51 ,
V_11 -> V_64 . T_4 . V_74 ) ;
V_11 -> V_64 . T_4 . V_74 = V_16 ;
V_11 -> V_64 . T_4 . V_73 = V_11 -> V_82 ;
return;
}
V_87 = F_42 ( V_11 -> V_82 , V_16 - 1 ) ;
if ( V_11 -> V_64 . T_4 . V_71 ) {
F_21 ( V_11 , V_87 , V_88 ) ;
F_21 ( V_11 , V_11 -> V_64 . T_4 . V_73 , V_51 ) ;
} else {
V_11 -> V_64 . T_4 . V_71 = 1 ;
F_21 ( V_11 , V_87 , V_88 ) ;
}
V_11 -> V_64 . T_4 . V_73 = V_87 ;
V_16 -- ;
if ( ! V_16 )
return;
F_19 ( V_11 , V_11 -> V_82 , V_51 , V_16 ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
int V_16 , V_89 ;
unsigned char V_14 = 0 ;
V_11 -> V_90 = F_31 () ;
V_16 = F_44 ( F_45 ( & V_11 -> V_91 ) , V_44 ) ;
V_89 = F_42 ( V_11 -> V_82 , V_16 ) ;
if ( V_11 -> V_82 == V_89 )
goto T_3;
V_16 = F_15 ( V_11 , V_11 -> V_82 , & V_14 , V_16 , 1 , 0 ) ;
if ( ! V_16 )
goto T_3;
switch ( V_14 ) {
case V_92 :
F_41 ( V_11 , V_16 ) ;
V_11 -> V_82 = F_42 ( V_11 -> V_82 , V_16 ) ;
if ( F_46 ( V_16 , & V_11 -> V_91 ) == 0 )
F_9 ( V_11 , V_93 ) ;
if ( V_11 -> V_23 -> V_94 )
F_39 ( V_11 , V_16 ) ;
break;
case V_95 :
F_40 ( V_11 , V_16 ) ;
V_11 -> V_82 = F_42 ( V_11 -> V_82 , V_16 ) ;
F_46 ( V_16 , & V_11 -> V_91 ) ;
if ( V_11 -> V_23 -> V_94 )
F_47 ( V_11 , V_16 ) ;
break;
case V_96 :
case V_51 :
case V_88 :
if ( V_11 -> V_23 -> V_94 )
V_11 -> V_76 . V_97 ++ ;
F_11 ( V_37 , V_11 -> V_23 , L_25 ) ;
break;
default:
F_48 () ;
}
T_3:
return V_11 -> V_82 ;
}
static int F_49 ( struct V_10 * V_11 )
{
int V_40 ;
V_40 = F_43 ( V_11 ) ;
if ( V_40 != V_11 -> V_98 ) {
V_11 -> V_98 = V_40 ;
if ( ! F_50 ( V_11 -> V_23 ) && V_99 )
V_11 -> V_64 . T_4 . V_90 = F_31 () ;
return 1 ;
} else
return 0 ;
}
static inline int F_51 ( struct V_10 * V_11 )
{
unsigned char V_14 = 0 ;
if ( ! F_45 ( & V_11 -> V_91 ) )
return 1 ;
if ( F_37 ( V_11 ) )
F_27 ( V_11 ) ;
F_18 ( V_11 , V_11 -> V_82 , & V_14 , 0 ) ;
if ( V_14 == V_92 || V_14 == V_95 )
return 0 ;
if ( F_50 ( V_11 -> V_23 ) )
return 1 ;
if ( V_100 )
return 1 ;
if ( F_31 () > V_11 -> V_64 . T_4 . V_90 + V_101 ) {
F_11 ( V_37 , V_11 -> V_23 , L_26 ,
V_11 -> V_82 ) ;
return 1 ;
} else
return 0 ;
}
static inline int F_52 ( struct V_10 * V_11 )
{
return ! V_11 -> V_26 && V_11 -> V_64 . T_3 . V_65 ;
}
static inline void F_53 ( struct V_50 * V_102 , struct V_10 * V_11 ,
int V_43 , struct V_103 * V_9 )
{
int V_104 ;
F_11 ( V_37 , V_102 , L_27 , V_43 ,
( unsigned long ) F_54 ( V_9 ) ) ;
F_11 ( V_37 , V_102 , L_28 ,
( unsigned long ) V_9 -> V_105 [ 0 ] ) ;
F_11 ( V_37 , V_102 , L_29 ,
( unsigned long ) V_9 -> V_105 [ 1 ] ) ;
F_11 ( V_37 , V_102 , L_30 ,
( unsigned long ) V_9 -> V_105 [ 2 ] ) ;
F_11 ( V_37 , V_102 , L_31 ,
( unsigned long ) V_9 -> V_105 [ 3 ] ) ;
F_11 ( V_37 , V_102 , L_32 ,
( unsigned long ) V_9 -> V_105 [ 4 ] ) ;
F_11 ( V_37 , V_102 , L_33 ,
( unsigned long ) V_9 -> V_105 [ 5 ] ) ;
F_11 ( V_37 , V_102 , L_34 , V_9 -> V_106 ) ;
F_11 ( V_37 , V_102 , L_35 , V_9 -> V_107 ) ;
F_11 ( V_37 , V_102 , L_36 , V_9 -> V_108 ) ;
F_11 ( V_37 , V_102 , L_37 , V_9 -> V_109 ) ;
F_11 ( V_37 , V_102 , L_38 , V_9 -> V_110 ) ;
F_11 ( V_37 , V_102 , L_39 , V_9 -> V_111 ) ;
F_11 ( V_37 , V_102 , L_40 , V_9 -> V_112 ) ;
for ( V_104 = 0 ; V_104 < V_113 ; ++ V_104 ) {
F_11 ( V_37 , V_102 , L_41 , V_104 ,
( unsigned long ) V_9 -> V_114 [ V_104 ] ) ;
F_11 ( V_37 , V_102 , L_42 , V_104 ,
( unsigned long ) V_11 -> V_81 [ V_43 ] -> V_83 [ V_104 ] . V_115 ) ;
F_11 ( V_37 , V_102 , L_43 , V_104 , V_9 -> V_116 [ V_104 ] ) ;
F_11 ( V_37 , V_102 , L_44 , V_104 ,
V_11 -> V_81 [ V_43 ] -> V_83 [ V_104 ] . V_117 ) ;
}
F_11 ( V_37 , V_102 , L_45 , ( unsigned long ) V_9 -> V_118 ) ;
for ( V_104 = 0 ; V_104 < 2 ; ++ V_104 ) {
F_11 ( V_37 , V_102 , L_46 , V_104 ,
( unsigned long ) V_9 -> V_119 [ V_104 ] ) ;
}
F_11 ( V_37 , V_102 , L_47 , ( unsigned long ) V_9 -> V_120 ) ;
F_11 ( V_37 , V_102 , L_48 , ( unsigned long ) V_9 -> V_121 ) ;
}
static inline void F_55 ( struct V_10 * V_11 , int V_15 , int V_16 )
{
unsigned char V_14 = 0 ;
int V_122 , V_123 = V_15 ;
if ( ! F_52 ( V_11 ) )
return;
for ( V_122 = 0 ; V_122 < V_16 ; ++ V_122 ) {
F_18 ( V_11 , V_123 , & V_14 , 0 ) ;
if ( V_14 == V_48 ) {
struct V_103 * V_9 = V_11 -> V_64 . T_3 . V_124 [ V_123 ] ;
if ( V_9 == NULL )
continue;
F_8 ( V_11 -> V_64 . T_3 . V_125 == NULL ) ;
V_11 -> V_64 . T_3 . V_125 [ V_123 ] . V_110 |=
V_126 ;
V_11 -> V_64 . T_3 . V_124 [ V_123 ] = NULL ;
} else if ( V_14 == V_49 ) {
F_8 ( V_11 -> V_64 . T_3 . V_125 == NULL ) ;
V_11 -> V_64 . T_3 . V_125 [ V_123 ] . V_9 = NULL ;
}
V_123 = F_17 ( V_123 ) ;
}
}
static inline unsigned long F_56 ( struct V_127 * V_11 ,
int V_40 )
{
unsigned long V_128 = 0 ;
if ( ! V_11 -> V_65 )
goto T_3;
if ( ! V_11 -> V_124 [ V_40 ] ) {
struct V_103 * V_9 = F_57 () ;
V_11 -> V_124 [ V_40 ] = V_9 ;
}
if ( V_11 -> V_124 [ V_40 ] ) {
F_8 ( V_11 -> V_125 == NULL ) ;
V_11 -> V_125 [ V_40 ] . V_110 = V_129 ;
V_11 -> V_125 [ V_40 ] . V_9 = V_11 -> V_124 [ V_40 ] ;
V_11 -> V_124 [ V_40 ] -> V_120 = ( T_7 ) V_11 -> V_125 [ V_40 ] . V_130 ;
V_128 = F_54 ( V_11 -> V_124 [ V_40 ] ) ;
F_8 ( V_128 & 0xFF ) ;
}
T_3:
return V_128 ;
}
static void F_58 ( struct V_10 * V_11 )
{
int V_15 = V_11 -> V_34 ;
int V_131 = V_11 -> V_82 ;
int V_16 ;
if ( F_26 ( V_11 -> V_23 -> V_14 != V_132 ) )
return;
V_16 = F_59 ( V_131 , V_15 ) ;
if ( V_11 -> V_26 ) {
F_9 ( V_11 , V_133 ) ;
F_11 ( V_37 , V_11 -> V_23 , L_49 , V_15 , V_16 ) ;
} else {
F_9 ( V_11 , V_134 ) ;
F_11 ( V_37 , V_11 -> V_23 , L_50 ,
V_15 , V_16 ) ;
}
F_55 ( V_11 , V_15 , V_16 ) ;
V_11 -> V_31 ( V_11 -> V_23 -> V_32 , V_11 -> V_79 , V_11 -> V_21 , V_15 , V_16 ,
V_11 -> V_23 -> V_35 ) ;
V_11 -> V_34 = V_131 ;
V_11 -> V_79 = 0 ;
}
static void F_60 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_135 ) ;
if ( ! F_49 ( V_11 ) )
return;
F_58 ( V_11 ) ;
if ( ! F_51 ( V_11 ) ) {
F_9 ( V_11 , V_136 ) ;
if ( F_61 ( V_11 -> V_23 -> V_14 != V_137 ) ) {
F_62 ( & V_11 -> V_138 ) ;
return;
}
}
F_38 ( V_11 ) ;
if ( ! F_51 ( V_11 ) ) {
F_9 ( V_11 , V_139 ) ;
if ( F_61 ( V_11 -> V_23 -> V_14 != V_137 ) )
F_62 ( & V_11 -> V_138 ) ;
}
}
void F_63 ( unsigned long V_140 )
{
struct V_10 * V_11 = (struct V_10 * ) V_140 ;
F_60 ( V_11 ) ;
}
static int F_64 ( struct V_10 * V_11 )
{
int V_16 , V_89 ;
unsigned char V_14 = 0 ;
V_11 -> V_90 = F_31 () ;
if ( F_37 ( V_11 ) )
if ( ( ( F_30 ( V_11 ) != V_67 ) &&
! F_34 ( V_11 ) ) ||
( F_30 ( V_11 ) == V_67 &&
F_65 ( V_11 ) ) )
F_27 ( V_11 ) ;
V_16 = F_44 ( F_45 ( & V_11 -> V_91 ) , V_44 ) ;
V_89 = F_42 ( V_11 -> V_82 , V_16 ) ;
if ( V_11 -> V_82 == V_89 )
goto T_3;
V_16 = F_15 ( V_11 , V_11 -> V_82 , & V_14 , V_16 , 0 , 1 ) ;
if ( ! V_16 )
goto T_3;
switch ( V_14 ) {
case V_48 :
F_48 () ;
case V_49 :
F_11 ( V_37 , V_11 -> V_23 ,
L_51 , V_11 -> V_21 , V_16 ) ;
F_46 ( V_16 , & V_11 -> V_91 ) ;
V_11 -> V_82 = F_42 ( V_11 -> V_82 , V_16 ) ;
if ( V_11 -> V_23 -> V_94 )
F_39 ( V_11 , V_16 ) ;
break;
case V_141 :
F_40 ( V_11 , V_16 ) ;
V_11 -> V_82 = F_42 ( V_11 -> V_82 , V_16 ) ;
F_46 ( V_16 , & V_11 -> V_91 ) ;
if ( V_11 -> V_23 -> V_94 )
F_47 ( V_11 , V_16 ) ;
break;
case V_142 :
if ( V_11 -> V_23 -> V_94 )
V_11 -> V_76 . V_97 ++ ;
F_11 ( V_37 , V_11 -> V_23 , L_52 ,
V_11 -> V_21 ) ;
break;
case V_52 :
case V_143 :
break;
default:
F_48 () ;
}
T_3:
return V_11 -> V_82 ;
}
static inline int F_66 ( struct V_10 * V_11 )
{
return F_45 ( & V_11 -> V_91 ) == 0 ;
}
static inline int F_67 ( struct V_10 * V_11 )
{
int V_40 ;
V_40 = F_64 ( V_11 ) ;
if ( V_40 != V_11 -> V_98 ) {
V_11 -> V_98 = V_40 ;
F_11 ( V_37 , V_11 -> V_23 , L_53 , V_11 -> V_21 ) ;
return 1 ;
} else
return 0 ;
}
static int F_68 ( struct V_10 * V_11 , unsigned long V_9 )
{
int V_62 = 0 , V_6 ;
unsigned int V_59 ;
if ( ! F_69 ( V_11 ) )
return 0 ;
F_11 ( V_37 , V_11 -> V_23 , L_54 , V_11 -> V_21 ) ;
V_144:
F_9 ( V_11 , V_145 ) ;
V_6 = F_28 ( V_11 , & V_59 , V_9 ) ;
switch ( V_6 ) {
case 0 :
break;
case 2 :
if ( V_59 ) {
while ( ++ V_62 < V_146 ) {
F_70 ( V_147 ) ;
goto V_144;
}
F_5 ( L_55 , F_6 ( V_11 ) , V_11 -> V_21 ) ;
V_6 = - V_148 ;
} else {
F_11 ( V_37 , V_11 -> V_23 , L_56 , V_11 -> V_21 ) ;
V_6 = - V_149 ;
}
break;
case 1 :
case 3 :
F_5 ( L_57 , F_6 ( V_11 ) , V_6 ) ;
V_6 = - V_13 ;
break;
}
if ( V_62 ) {
F_5 ( L_58 , F_6 ( V_11 ) , V_11 -> V_21 ) ;
F_5 ( L_15 , V_62 ) ;
}
return V_6 ;
}
static void F_71 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_150 ) ;
F_8 ( F_45 ( & V_11 -> V_91 ) < 0 ) ;
if ( F_67 ( V_11 ) )
F_58 ( V_11 ) ;
if ( F_30 ( V_11 ) == V_151 )
if ( ! F_34 ( V_11 ) && ! F_66 ( V_11 ) )
goto V_152;
if ( V_11 -> V_64 . T_3 . V_153 )
return;
if ( F_66 ( V_11 ) )
F_72 ( & V_11 -> V_64 . T_3 . V_154 ) ;
else
if ( ! F_73 ( & V_11 -> V_64 . T_3 . V_154 ) )
F_74 ( & V_11 -> V_64 . T_3 . V_154 , V_155 + 10 * V_156 ) ;
return;
V_152:
if ( F_26 ( V_11 -> V_23 -> V_14 == V_137 ) )
return;
F_62 ( & V_11 -> V_138 ) ;
}
void F_75 ( unsigned long V_140 )
{
struct V_10 * V_11 = (struct V_10 * ) V_140 ;
F_71 ( V_11 ) ;
}
void F_76 ( unsigned long V_140 )
{
struct V_10 * V_11 = (struct V_10 * ) V_140 ;
if ( F_26 ( V_11 -> V_23 -> V_14 == V_137 ) )
return;
F_62 ( & V_11 -> V_138 ) ;
}
static inline void F_77 ( struct V_10 * V_11 )
{
struct V_10 * T_3 ;
int V_43 ;
if ( ! F_34 ( V_11 ) )
return;
F_24 (q->irq_ptr, out, i)
if ( ! F_66 ( T_3 ) )
F_62 ( & T_3 -> V_138 ) ;
}
static void F_78 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_135 ) ;
if ( F_37 ( V_11 ) && F_79 ( V_11 ) )
F_33 ( V_11 ) ;
F_77 ( V_11 ) ;
if ( ! F_49 ( V_11 ) )
return;
F_58 ( V_11 ) ;
if ( ! F_51 ( V_11 ) ) {
F_9 ( V_11 , V_136 ) ;
if ( F_61 ( V_11 -> V_23 -> V_14 != V_137 ) ) {
F_62 ( & V_11 -> V_138 ) ;
return;
}
}
F_38 ( V_11 ) ;
if ( ! F_51 ( V_11 ) ) {
F_9 ( V_11 , V_139 ) ;
if ( F_61 ( V_11 -> V_23 -> V_14 != V_137 ) )
F_62 ( & V_11 -> V_138 ) ;
}
}
void F_80 ( unsigned long V_140 )
{
struct V_10 * V_11 = (struct V_10 * ) V_140 ;
F_78 ( V_11 ) ;
}
static inline void F_81 ( struct V_50 * V_23 ,
enum V_157 V_14 )
{
F_11 ( V_37 , V_23 , L_59 , V_14 ) ;
V_23 -> V_14 = V_14 ;
F_82 () ;
}
static void F_83 ( struct V_50 * V_23 , struct V_158 * V_158 )
{
if ( V_158 -> V_159 . V_160 . V_161 . V_162 ) {
F_5 ( L_60 , V_23 -> V_1 . V_163 ) ;
F_84 ( V_158 , 64 ) ;
F_84 ( V_158 -> V_164 , 64 ) ;
}
}
static void F_85 ( struct V_50 * V_23 )
{
int V_43 ;
struct V_10 * V_11 ;
if ( F_26 ( V_23 -> V_14 == V_137 ) )
return;
F_23 (irq_ptr, q, i) {
if ( V_11 -> V_64 . T_4 . V_165 ) {
if ( F_86 ( V_166 ,
& V_11 -> V_64 . T_4 . V_167 ) ) {
F_9 ( V_11 , V_168 ) ;
continue;
}
V_11 -> V_64 . T_4 . V_165 ( V_11 -> V_23 -> V_32 , V_11 -> V_21 ,
V_11 -> V_23 -> V_35 ) ;
} else {
F_62 ( & V_11 -> V_138 ) ;
}
}
if ( ! F_34 ( V_11 ) )
return;
F_24 (irq_ptr, q, i) {
if ( F_66 ( V_11 ) )
continue;
if ( F_37 ( V_11 ) && F_87 ( V_11 ) )
F_27 ( V_11 ) ;
F_62 ( & V_11 -> V_138 ) ;
}
}
static void F_88 ( struct V_169 * V_32 ,
unsigned long V_170 , int V_171 , int V_172 )
{
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
struct V_10 * V_11 ;
int V_16 ;
F_5 ( L_61 , V_23 -> V_1 . V_163 ) ;
F_5 ( L_62 , V_170 ) ;
F_5 ( L_63 , V_172 , V_171 ) ;
if ( V_23 -> V_27 ) {
V_11 = V_23 -> V_175 [ 0 ] ;
} else if ( V_23 -> V_176 ) {
V_11 = V_23 -> V_177 [ 0 ] ;
} else {
F_89 () ;
goto V_178;
}
V_16 = F_59 ( V_11 -> V_82 , V_11 -> V_34 ) ;
V_11 -> V_31 ( V_11 -> V_23 -> V_32 , V_179 ,
V_11 -> V_21 , V_11 -> V_34 , V_16 , V_23 -> V_35 ) ;
V_178:
F_81 ( V_23 , V_137 ) ;
F_90 () ;
}
static void F_91 ( struct V_169 * V_32 , int V_171 ,
int V_172 )
{
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
F_11 ( V_37 , V_23 , L_64 ) ;
if ( V_171 )
goto error;
if ( V_172 & ~ ( V_180 | V_181 ) )
goto error;
if ( ! ( V_172 & V_180 ) )
goto error;
F_81 ( V_23 , V_182 ) ;
return;
error:
F_5 ( L_65 , V_23 -> V_1 . V_163 ) ;
F_5 ( L_63 , V_172 , V_171 ) ;
F_81 ( V_23 , V_183 ) ;
}
void F_92 ( struct V_169 * V_32 , unsigned long V_170 ,
struct V_158 * V_158 )
{
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
int V_171 , V_172 ;
if ( ! V_170 || ! V_23 ) {
F_5 ( L_66 , V_32 -> V_173 -> V_1 . V_163 ) ;
return;
}
if ( V_23 -> V_94 )
V_23 -> V_184 . V_185 ++ ;
if ( F_93 ( V_158 ) ) {
switch ( F_94 ( V_158 ) ) {
case - V_13 :
F_5 ( L_67 , V_23 -> V_1 . V_163 ) ;
F_81 ( V_23 , V_183 ) ;
F_95 ( & V_32 -> V_173 -> V_186 ) ;
return;
default:
F_14 ( 1 ) ;
return;
}
}
F_83 ( V_23 , V_158 ) ;
V_171 = V_158 -> V_187 . V_188 . V_171 ;
V_172 = V_158 -> V_187 . V_188 . V_172 ;
switch ( V_23 -> V_14 ) {
case V_189 :
F_91 ( V_32 , V_171 , V_172 ) ;
break;
case V_190 :
F_81 ( V_23 , V_189 ) ;
break;
case V_182 :
case V_132 :
if ( V_171 & V_191 ) {
F_85 ( V_23 ) ;
return;
}
if ( V_171 || V_172 )
F_88 ( V_32 , V_170 , V_171 ,
V_172 ) ;
break;
case V_137 :
break;
default:
F_14 ( 1 ) ;
}
F_95 ( & V_32 -> V_173 -> V_186 ) ;
}
int F_96 ( struct V_169 * V_32 ,
struct V_192 * V_140 )
{
if ( ! V_32 || ! V_32 -> V_173 )
return - V_193 ;
F_97 ( L_68 , V_32 -> V_173 -> V_1 . V_163 ) ;
return F_98 ( NULL , & V_32 -> V_173 -> V_1 , V_140 ) ;
}
static void F_99 ( struct V_169 * V_32 )
{
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
struct V_10 * V_11 ;
int V_43 ;
F_23 (irq_ptr, q, i)
F_100 ( & V_11 -> V_138 ) ;
F_24 (irq_ptr, q, i) {
F_72 ( & V_11 -> V_64 . T_3 . V_154 ) ;
F_100 ( & V_11 -> V_138 ) ;
}
}
int F_101 ( struct V_169 * V_32 , int V_194 )
{
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
int V_18 ;
unsigned long V_110 ;
if ( ! V_23 )
return - V_195 ;
F_8 ( F_102 () ) ;
F_97 ( L_69 , V_32 -> V_173 -> V_1 . V_163 ) ;
F_103 ( & V_23 -> V_196 ) ;
if ( V_23 -> V_14 == V_189 ) {
F_104 ( & V_23 -> V_196 ) ;
return 0 ;
}
F_81 ( V_23 , V_137 ) ;
F_105 ( V_23 ) ;
F_99 ( V_32 ) ;
F_106 ( V_23 , V_32 ) ;
F_107 ( F_108 ( V_32 ) , V_110 ) ;
if ( V_194 & V_197 )
V_18 = F_109 ( V_32 , V_198 ) ;
else
V_18 = F_110 ( V_32 , V_198 ) ;
if ( V_18 ) {
F_5 ( L_70 , V_23 -> V_1 . V_163 ) ;
F_5 ( L_71 , V_18 ) ;
goto V_199;
}
F_81 ( V_23 , V_190 ) ;
F_111 ( F_108 ( V_32 ) , V_110 ) ;
F_112 ( V_32 -> V_173 -> V_186 ,
V_23 -> V_14 == V_189 ||
V_23 -> V_14 == V_183 ,
10 * V_156 ) ;
F_107 ( F_108 ( V_32 ) , V_110 ) ;
V_199:
F_113 ( V_23 ) ;
if ( ( void * ) V_32 -> V_31 == ( void * ) F_92 )
V_32 -> V_31 = V_23 -> V_200 ;
F_111 ( F_108 ( V_32 ) , V_110 ) ;
F_81 ( V_23 , V_189 ) ;
F_104 ( & V_23 -> V_196 ) ;
if ( V_18 )
return V_18 ;
return 0 ;
}
int F_114 ( struct V_169 * V_32 )
{
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
if ( ! V_23 )
return - V_195 ;
F_97 ( L_72 , V_32 -> V_173 -> V_1 . V_163 ) ;
F_103 ( & V_23 -> V_196 ) ;
if ( V_23 -> V_201 != NULL ) {
F_115 ( V_23 -> V_201 ) ;
V_23 -> V_201 = NULL ;
}
V_32 -> V_173 -> V_174 = NULL ;
F_104 ( & V_23 -> V_196 ) ;
F_116 ( V_23 ) ;
return 0 ;
}
int F_117 ( struct V_202 * V_203 )
{
struct V_50 * V_23 ;
F_97 ( L_73 , V_203 -> V_32 -> V_173 -> V_1 . V_163 ) ;
if ( ( V_203 -> V_204 && ! V_203 -> V_205 ) ||
( V_203 -> V_206 && ! V_203 -> V_207 ) )
return - V_193 ;
if ( ( V_203 -> V_204 > V_208 ) ||
( V_203 -> V_206 > V_208 ) )
return - V_193 ;
if ( ( ! V_203 -> V_209 ) ||
( ! V_203 -> V_210 ) )
return - V_193 ;
V_23 = ( void * ) F_118 ( V_211 | V_212 ) ;
if ( ! V_23 )
goto V_213;
F_119 ( & V_23 -> V_196 ) ;
F_120 ( V_203 , V_23 ) ;
V_23 -> V_214 = F_118 ( V_211 ) ;
if ( ! V_23 -> V_214 )
goto V_215;
V_23 -> V_216 = (struct V_216 * ) F_118 ( V_211 | V_212 ) ;
if ( ! V_23 -> V_216 )
goto V_215;
F_14 ( ( unsigned long ) V_23 -> V_216 & 0xfff ) ;
if ( F_121 ( V_23 , V_203 -> V_204 ,
V_203 -> V_206 ) )
goto V_215;
V_203 -> V_32 -> V_173 -> V_174 = V_23 ;
F_81 ( V_23 , V_189 ) ;
return 0 ;
V_215:
F_116 ( V_23 ) ;
V_213:
return - V_217 ;
}
static void F_122 ( struct V_50 * V_23 )
{
struct V_10 * V_11 = V_23 -> V_175 [ 0 ] ;
int V_43 , V_65 = 0 ;
if ( V_23 -> V_27 > 1 && F_30 ( V_11 ) == V_67 )
V_65 = 1 ;
F_24 (irq_ptr, q, i) {
if ( V_65 ) {
if ( F_123 ( & V_11 -> V_64 . T_3 ) < 0 ) {
V_65 = 0 ;
continue;
}
} else
F_124 ( & V_11 -> V_64 . T_3 ) ;
}
F_97 ( L_74 , V_65 ) ;
}
int F_125 ( struct V_202 * V_203 )
{
struct V_50 * V_23 ;
struct V_169 * V_32 = V_203 -> V_32 ;
unsigned long V_218 ;
int V_18 ;
F_97 ( L_75 , V_32 -> V_173 -> V_1 . V_163 ) ;
V_23 = V_32 -> V_173 -> V_174 ;
if ( ! V_23 )
return - V_195 ;
if ( V_32 -> V_173 -> V_14 != V_219 )
return - V_193 ;
F_103 ( & V_23 -> V_196 ) ;
F_126 ( V_203 ) ;
V_18 = F_127 ( V_23 ) ;
if ( V_18 ) {
F_104 ( & V_23 -> V_196 ) ;
F_101 ( V_32 , V_197 ) ;
return V_18 ;
}
V_23 -> V_220 . V_221 = V_23 -> V_222 . V_188 ;
V_23 -> V_220 . V_110 = V_223 ;
V_23 -> V_220 . V_16 = V_23 -> V_222 . V_16 ;
V_23 -> V_220 . V_224 = ( V_55 ) ( ( V_225 ) V_23 -> V_216 ) ;
F_107 ( F_108 ( V_32 ) , V_218 ) ;
F_128 ( V_32 , 0 ) ;
V_18 = F_129 ( V_32 , & V_23 -> V_220 , V_226 , 0 , 0 ) ;
if ( V_18 ) {
F_5 ( L_76 , V_23 -> V_1 . V_163 ) ;
F_5 ( L_77 , V_18 ) ;
}
F_111 ( F_108 ( V_32 ) , V_218 ) ;
if ( V_18 ) {
F_104 ( & V_23 -> V_196 ) ;
F_101 ( V_32 , V_197 ) ;
return V_18 ;
}
F_112 ( V_32 -> V_173 -> V_186 ,
V_23 -> V_14 == V_182 ||
V_23 -> V_14 == V_183 , V_156 ) ;
if ( V_23 -> V_14 != V_182 ) {
F_104 ( & V_23 -> V_196 ) ;
F_101 ( V_32 , V_197 ) ;
return - V_13 ;
}
F_130 ( V_23 ) ;
F_122 ( V_23 ) ;
F_22 ( V_23 ) ;
F_104 ( & V_23 -> V_196 ) ;
F_131 ( V_23 , V_32 ) ;
F_132 ( V_23 , V_32 ) ;
return 0 ;
}
int F_133 ( struct V_169 * V_32 )
{
struct V_50 * V_23 ;
int V_18 ;
unsigned long V_218 ;
F_97 ( L_78 , V_32 -> V_173 -> V_1 . V_163 ) ;
V_23 = V_32 -> V_173 -> V_174 ;
if ( ! V_23 )
return - V_195 ;
if ( V_32 -> V_173 -> V_14 != V_219 )
return - V_193 ;
F_103 ( & V_23 -> V_196 ) ;
if ( V_23 -> V_14 == V_189 ) {
V_18 = - V_148 ;
goto T_3;
}
V_23 -> V_220 . V_221 = V_23 -> V_227 . V_188 ;
V_23 -> V_220 . V_110 = V_223 ;
V_23 -> V_220 . V_16 = V_23 -> V_227 . V_16 ;
V_23 -> V_220 . V_224 = 0 ;
F_107 ( F_108 ( V_32 ) , V_218 ) ;
F_134 ( V_32 , V_228 ) ;
V_18 = F_129 ( V_32 , & V_23 -> V_220 , V_229 ,
0 , V_230 ) ;
if ( V_18 ) {
F_5 ( L_79 , V_23 -> V_1 . V_163 ) ;
F_5 ( L_77 , V_18 ) ;
}
F_111 ( F_108 ( V_32 ) , V_218 ) ;
if ( V_18 )
goto T_3;
if ( F_50 ( V_23 ) )
F_135 ( V_23 ) ;
F_136 ( 5 ) ;
switch ( V_23 -> V_14 ) {
case V_137 :
case V_183 :
V_18 = - V_13 ;
break;
default:
F_81 ( V_23 , V_132 ) ;
V_18 = 0 ;
}
T_3:
F_104 ( & V_23 -> V_196 ) ;
return V_18 ;
}
static inline int F_137 ( int V_40 , int V_15 , int V_16 )
{
int V_131 = F_42 ( V_15 , V_16 ) ;
if ( V_131 > V_15 ) {
if ( V_40 >= V_15 && V_40 < V_131 )
return 1 ;
else
return 0 ;
}
if ( ( V_40 >= V_15 && V_40 <= V_45 ) ||
( V_40 < V_131 ) )
return 1 ;
else
return 0 ;
}
static int F_138 ( struct V_10 * V_11 , unsigned int V_231 ,
int V_40 , int V_16 )
{
int V_232 , V_233 ;
F_9 ( V_11 , V_234 ) ;
if ( ! V_11 -> V_64 . T_4 . V_71 )
goto V_86;
if ( V_16 == V_45 ) {
V_11 -> V_64 . T_4 . V_71 = 0 ;
V_11 -> V_64 . T_4 . V_74 = 0 ;
goto V_86;
} else if ( F_137 ( V_11 -> V_64 . T_4 . V_73 , V_40 , V_16 ) ) {
if ( F_16 ( V_11 ) ) {
V_233 = F_42 ( V_40 , V_16 ) ;
V_233 = F_59 ( V_233 , V_11 -> V_64 . T_4 . V_73 ) ;
V_11 -> V_64 . T_4 . V_74 -= V_233 ;
if ( V_11 -> V_64 . T_4 . V_74 <= 0 ) {
V_11 -> V_64 . T_4 . V_71 = 0 ;
V_11 -> V_64 . T_4 . V_74 = 0 ;
goto V_86;
}
V_11 -> V_64 . T_4 . V_73 = F_42 ( V_11 -> V_64 . T_4 . V_73 , V_233 ) ;
}
else
V_11 -> V_64 . T_4 . V_71 = 0 ;
}
V_86:
V_16 = F_19 ( V_11 , V_40 , V_96 , V_16 ) ;
V_232 = F_139 ( V_16 , & V_11 -> V_91 ) - V_16 ;
F_8 ( V_232 + V_16 > V_45 ) ;
if ( F_140 ( V_11 ) )
return F_32 ( V_11 ) ;
return 0 ;
}
static int F_141 ( struct V_10 * V_11 , unsigned int V_231 ,
int V_40 , int V_16 )
{
unsigned char V_14 = 0 ;
int V_232 , V_18 = 0 ;
F_9 ( V_11 , V_235 ) ;
V_16 = F_19 ( V_11 , V_40 , V_142 , V_16 ) ;
V_232 = F_139 ( V_16 , & V_11 -> V_91 ) ;
F_8 ( V_232 > V_45 ) ;
if ( V_232 == V_45 )
F_9 ( V_11 , V_236 ) ;
if ( V_231 & V_237 ) {
V_11 -> V_64 . T_3 . V_153 = 1 ;
F_9 ( V_11 , V_238 ) ;
} else
V_11 -> V_64 . T_3 . V_153 = 0 ;
if ( F_30 ( V_11 ) == V_67 ) {
unsigned long V_128 = 0 ;
F_29 ( V_16 > 1 && ! F_65 ( V_11 ) ) ;
V_128 = F_56 ( & V_11 -> V_64 . T_3 , V_40 ) ;
V_18 = F_68 ( V_11 , V_128 ) ;
} else if ( F_37 ( V_11 ) ) {
V_18 = F_27 ( V_11 ) ;
} else {
F_18 ( V_11 , F_142 ( V_40 ) , & V_14 , 0 ) ;
if ( V_14 != V_142 )
V_18 = F_68 ( V_11 , 0 ) ;
else
F_9 ( V_11 , V_239 ) ;
}
if ( V_232 >= V_11 -> V_64 . T_3 . V_240 || V_18 )
F_62 ( & V_11 -> V_138 ) ;
else
if ( ! F_73 ( & V_11 -> V_64 . T_3 . V_154 ) )
F_74 ( & V_11 -> V_64 . T_3 . V_154 , V_155 + V_156 ) ;
return V_18 ;
}
int F_143 ( struct V_169 * V_32 , unsigned int V_231 ,
int V_241 , unsigned int V_40 , unsigned int V_16 )
{
struct V_50 * V_23 ;
if ( V_40 >= V_45 || V_16 > V_45 )
return - V_193 ;
V_23 = V_32 -> V_173 -> V_174 ;
if ( ! V_23 )
return - V_195 ;
F_11 ( V_37 , V_23 ,
L_80 , V_231 , V_40 , V_16 ) ;
if ( V_23 -> V_14 != V_132 )
return - V_13 ;
if ( ! V_16 )
return 0 ;
if ( V_231 & V_242 )
return F_138 ( V_23 -> V_175 [ V_241 ] ,
V_231 , V_40 , V_16 ) ;
else if ( V_231 & V_243 )
return F_141 ( V_23 -> V_177 [ V_241 ] ,
V_231 , V_40 , V_16 ) ;
return - V_193 ;
}
int F_144 ( struct V_169 * V_32 , int V_21 )
{
struct V_10 * V_11 ;
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
if ( ! V_23 )
return - V_195 ;
V_11 = V_23 -> V_175 [ V_21 ] ;
F_14 ( F_145 ( V_11 ) ) ;
F_146 ( V_23 ) ;
F_38 ( V_11 ) ;
F_147 ( V_166 , & V_11 -> V_64 . T_4 . V_167 ) ;
if ( F_148 ( V_23 ) )
goto V_244;
if ( ! F_51 ( V_11 ) )
goto V_244;
return 0 ;
V_244:
if ( F_86 ( V_166 ,
& V_11 -> V_64 . T_4 . V_167 ) )
return 0 ;
else
return 1 ;
}
int F_149 ( struct V_169 * V_32 , int V_21 , int * V_40 ,
int * error )
{
struct V_10 * V_11 ;
int V_15 , V_131 ;
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
if ( ! V_23 )
return - V_195 ;
V_11 = V_23 -> V_175 [ V_21 ] ;
F_14 ( F_145 ( V_11 ) ) ;
if ( F_37 ( V_11 ) )
F_33 ( V_11 ) ;
F_77 ( V_11 ) ;
if ( ! F_49 ( V_11 ) )
return 0 ;
if ( F_26 ( V_11 -> V_23 -> V_14 != V_132 ) )
return - V_13 ;
V_15 = V_11 -> V_34 ;
V_131 = V_11 -> V_82 ;
* V_40 = V_15 ;
* error = V_11 -> V_79 ;
V_11 -> V_34 = V_131 ;
V_11 -> V_79 = 0 ;
return F_59 ( V_131 , V_15 ) ;
}
int F_150 ( struct V_169 * V_32 , int V_21 )
{
struct V_10 * V_11 ;
struct V_50 * V_23 = V_32 -> V_173 -> V_174 ;
if ( ! V_23 )
return - V_195 ;
V_11 = V_23 -> V_175 [ V_21 ] ;
if ( F_86 ( V_166 ,
& V_11 -> V_64 . T_4 . V_167 ) )
return 0 ;
else
return 1 ;
}
static int T_8 F_151 ( void )
{
int V_18 ;
V_18 = F_152 () ;
if ( V_18 )
return V_18 ;
V_18 = F_153 () ;
if ( V_18 )
goto V_245;
V_18 = F_154 () ;
if ( V_18 )
goto V_246;
V_18 = F_155 () ;
if ( V_18 )
goto V_247;
return 0 ;
V_247:
F_156 () ;
V_246:
F_157 () ;
V_245:
F_158 () ;
return V_18 ;
}
static void T_9 F_159 ( void )
{
F_160 () ;
F_156 () ;
F_157 () ;
F_158 () ;
}
