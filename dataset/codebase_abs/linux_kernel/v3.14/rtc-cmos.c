static inline int F_1 ( T_1 V_1 )
{
if ( ! ( V_1 & V_2 ) )
return 0 ;
return V_1 & V_3 ;
}
static inline int F_2 ( void )
{
return 0 ;
}
static inline int F_3 ( unsigned long V_4 )
{
return 0 ;
}
static inline int F_4 ( unsigned long V_4 )
{
return 0 ;
}
static inline int
F_5 ( unsigned char V_5 , unsigned char V_6 , unsigned char V_7 )
{
return 0 ;
}
static inline int F_6 ( unsigned long V_8 )
{
return 0 ;
}
static inline int F_7 ( void )
{
return 0 ;
}
static inline int F_8 ( void )
{
return 0 ;
}
static inline int F_9 ( T_2 V_9 )
{
return 0 ;
}
static inline int F_10 ( T_2 V_9 )
{
return 0 ;
}
static inline unsigned char F_11 ( unsigned char V_10 )
{
F_12 ( V_10 , F_13 ( 2 ) ) ;
return F_14 ( F_13 ( 3 ) ) ;
}
static inline void F_15 ( unsigned char V_11 , unsigned char V_10 )
{
F_12 ( V_10 , F_13 ( 2 ) ) ;
F_12 ( V_11 , F_13 ( 3 ) ) ;
}
static inline unsigned char F_11 ( unsigned char V_10 )
{
return 0 ;
}
static inline void F_15 ( unsigned char V_11 , unsigned char V_10 )
{
}
static int F_16 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
F_17 ( V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
return F_19 ( V_15 ) ;
}
static int F_20 ( struct V_12 * V_13 , struct V_16 * V_15 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_19 ;
if ( ! F_22 ( V_18 -> V_20 ) )
return - V_21 ;
V_15 -> time . V_22 = - 1 ;
V_15 -> time . V_23 = - 1 ;
F_23 ( & V_24 ) ;
V_15 -> time . V_25 = F_24 ( V_26 ) ;
V_15 -> time . V_27 = F_24 ( V_28 ) ;
V_15 -> time . V_29 = F_24 ( V_30 ) ;
if ( V_18 -> V_31 ) {
V_15 -> time . V_22 = F_24 ( V_18 -> V_31 ) & 0x3f ;
if ( ! V_15 -> time . V_22 )
V_15 -> time . V_22 = - 1 ;
if ( V_18 -> V_32 ) {
V_15 -> time . V_23 = F_24 ( V_18 -> V_32 ) ;
if ( ! V_15 -> time . V_23 )
V_15 -> time . V_23 = - 1 ;
}
}
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_24 ) ;
if ( ! ( V_19 & V_34 ) || V_35 ) {
if ( ( ( unsigned ) V_15 -> time . V_25 ) < 0x60 )
V_15 -> time . V_25 = F_26 ( V_15 -> time . V_25 ) ;
else
V_15 -> time . V_25 = - 1 ;
if ( ( ( unsigned ) V_15 -> time . V_27 ) < 0x60 )
V_15 -> time . V_27 = F_26 ( V_15 -> time . V_27 ) ;
else
V_15 -> time . V_27 = - 1 ;
if ( ( ( unsigned ) V_15 -> time . V_29 ) < 0x24 )
V_15 -> time . V_29 = F_26 ( V_15 -> time . V_29 ) ;
else
V_15 -> time . V_29 = - 1 ;
if ( V_18 -> V_31 ) {
if ( ( ( unsigned ) V_15 -> time . V_22 ) <= 0x31 )
V_15 -> time . V_22 = F_26 ( V_15 -> time . V_22 ) ;
else
V_15 -> time . V_22 = - 1 ;
if ( V_18 -> V_32 ) {
if ( ( ( unsigned ) V_15 -> time . V_23 ) <= 0x12 )
V_15 -> time . V_23 = F_26 ( V_15 -> time . V_23 ) - 1 ;
else
V_15 -> time . V_23 = - 1 ;
}
}
}
V_15 -> time . V_36 = - 1 ;
V_15 -> V_37 = ! ! ( V_19 & V_38 ) ;
V_15 -> V_39 = 0 ;
return 0 ;
}
static void F_27 ( struct V_17 * V_18 , unsigned char V_19 )
{
unsigned char V_1 ;
V_1 = F_24 ( V_40 ) ;
if ( F_2 () )
return;
V_1 &= ( V_19 & V_3 ) | V_2 ;
if ( F_1 ( V_1 ) )
F_28 ( V_18 -> V_41 , 1 , V_1 ) ;
}
static void F_29 ( struct V_17 * V_18 , unsigned char V_4 )
{
unsigned char V_19 ;
V_19 = F_24 ( V_33 ) ;
F_27 ( V_18 , V_19 ) ;
V_19 |= V_4 ;
F_30 ( V_19 , V_33 ) ;
F_4 ( V_4 ) ;
F_27 ( V_18 , V_19 ) ;
}
static void F_31 ( struct V_17 * V_18 , unsigned char V_4 )
{
unsigned char V_19 ;
V_19 = F_24 ( V_33 ) ;
V_19 &= ~ V_4 ;
F_30 ( V_19 , V_33 ) ;
F_3 ( V_4 ) ;
F_27 ( V_18 , V_19 ) ;
}
static int F_32 ( struct V_12 * V_13 , struct V_16 * V_15 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_42 , V_43 , V_5 , V_6 , V_7 , V_19 ;
if ( ! F_22 ( V_18 -> V_20 ) )
return - V_21 ;
V_42 = V_15 -> time . V_23 + 1 ;
V_43 = V_15 -> time . V_22 ;
V_5 = V_15 -> time . V_29 ;
V_6 = V_15 -> time . V_27 ;
V_7 = V_15 -> time . V_25 ;
V_19 = F_24 ( V_33 ) ;
if ( ! ( V_19 & V_34 ) || V_35 ) {
V_42 = ( V_42 <= 12 ) ? F_33 ( V_42 ) : 0xff ;
V_43 = ( V_43 >= 1 && V_43 <= 31 ) ? F_33 ( V_43 ) : 0xff ;
V_5 = ( V_5 < 24 ) ? F_33 ( V_5 ) : 0xff ;
V_6 = ( V_6 < 60 ) ? F_33 ( V_6 ) : 0xff ;
V_7 = ( V_7 < 60 ) ? F_33 ( V_7 ) : 0xff ;
}
F_23 ( & V_24 ) ;
F_31 ( V_18 , V_38 ) ;
F_30 ( V_5 , V_30 ) ;
F_30 ( V_6 , V_28 ) ;
F_30 ( V_7 , V_26 ) ;
if ( V_18 -> V_31 ) {
F_30 ( V_43 , V_18 -> V_31 ) ;
if ( V_18 -> V_32 )
F_30 ( V_42 , V_18 -> V_32 ) ;
}
F_5 ( V_15 -> time . V_29 , V_15 -> time . V_27 , V_15 -> time . V_25 ) ;
if ( V_15 -> V_37 )
F_29 ( V_18 , V_38 ) ;
F_25 ( & V_24 ) ;
return 0 ;
}
static int T_3 F_34 ( const struct V_44 * V_45 )
{
V_46 = true ;
F_35 ( L_1 ) ;
F_35 ( L_2 ) ;
return 0 ;
}
static int F_36 ( struct V_12 * V_13 , unsigned int V_37 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned long V_47 ;
if ( ! F_22 ( V_18 -> V_20 ) )
return - V_48 ;
if ( V_46 )
return 0 ;
F_37 ( & V_24 , V_47 ) ;
if ( V_37 )
F_29 ( V_18 , V_38 ) ;
else
F_31 ( V_18 , V_38 ) ;
F_38 ( & V_24 , V_47 ) ;
return 0 ;
}
static int F_39 ( struct V_12 * V_13 , struct V_49 * V_50 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_19 , V_51 ;
F_23 ( & V_24 ) ;
V_19 = F_24 ( V_33 ) ;
V_51 = F_24 ( V_52 ) ;
F_25 ( & V_24 ) ;
return F_40 ( V_50 ,
L_3
L_4
L_5
L_6
L_7
L_8
L_9 ,
( V_19 & V_53 ) ? L_10 : L_11 ,
( V_19 & V_54 ) ? L_10 : L_11 ,
F_2 () ? L_10 : L_11 ,
( V_19 & V_34 ) ? L_11 : L_10 ,
( V_19 & V_55 ) ? L_10 : L_11 ,
V_18 -> V_41 -> V_56 ,
( V_51 & V_57 ) ? L_12 : L_13 ) ;
}
static T_4
F_41 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_62 * V_63 ,
char * V_64 , T_5 V_65 , T_6 V_66 )
{
int V_67 ;
if ( F_42 ( V_65 >= V_63 -> V_68 ) )
return 0 ;
if ( F_42 ( V_65 < 0 ) )
return - V_48 ;
if ( ( V_65 + V_66 ) > V_63 -> V_68 )
V_66 = V_63 -> V_68 - V_65 ;
V_65 += V_69 ;
F_23 ( & V_24 ) ;
for ( V_67 = 0 ; V_66 ; V_66 -- , V_65 ++ , V_67 ++ ) {
if ( V_65 < 128 )
* V_64 ++ = F_24 ( V_65 ) ;
else if ( V_70 )
* V_64 ++ = F_11 ( V_65 ) ;
else
break;
}
F_25 ( & V_24 ) ;
return V_67 ;
}
static T_4
F_43 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_62 * V_63 ,
char * V_64 , T_5 V_65 , T_6 V_66 )
{
struct V_17 * V_18 ;
int V_67 ;
V_18 = F_21 ( F_44 ( V_61 , struct V_12 , V_61 ) ) ;
if ( F_42 ( V_65 >= V_63 -> V_68 ) )
return - V_71 ;
if ( F_42 ( V_65 < 0 ) )
return - V_48 ;
if ( ( V_65 + V_66 ) > V_63 -> V_68 )
V_66 = V_63 -> V_68 - V_65 ;
V_65 += V_69 ;
F_23 ( & V_24 ) ;
for ( V_67 = 0 ; V_66 ; V_66 -- , V_65 ++ , V_67 ++ ) {
if ( V_65 == V_18 -> V_31
|| V_65 == V_18 -> V_32
|| V_65 == V_18 -> V_72 )
V_64 ++ ;
else if ( V_65 < 128 )
F_30 ( * V_64 ++ , V_65 ) ;
else if ( V_70 )
F_15 ( * V_64 ++ , V_65 ) ;
else
break;
}
F_25 ( & V_24 ) ;
return V_67 ;
}
static T_7 F_45 ( int V_20 , void * V_73 )
{
T_1 V_74 ;
T_1 V_19 ;
F_46 ( & V_24 ) ;
V_74 = F_24 ( V_40 ) ;
V_19 = F_24 ( V_33 ) ;
if ( F_2 () )
V_74 = ( unsigned long ) V_20 & 0xF0 ;
if ( ! V_17 . V_75 )
V_74 &= ( V_19 & V_3 ) | V_2 ;
else
V_74 &= ( V_17 . V_75 & V_3 ) | V_2 ;
if ( V_74 & V_38 ) {
V_17 . V_75 &= ~ V_38 ;
V_19 &= ~ V_38 ;
F_30 ( V_19 , V_33 ) ;
F_3 ( V_38 ) ;
F_24 ( V_40 ) ;
}
F_47 ( & V_24 ) ;
if ( F_1 ( V_74 ) ) {
F_28 ( V_73 , 1 , V_74 ) ;
return V_76 ;
} else
return V_77 ;
}
static int T_8
F_48 ( struct V_12 * V_13 , struct V_78 * V_79 , int V_80 )
{
struct V_81 * V_82 = F_49 ( V_13 ) ;
int V_67 = 0 ;
unsigned char V_19 ;
unsigned V_83 ;
if ( V_17 . V_13 )
return - V_84 ;
if ( ! V_79 )
return - V_85 ;
V_79 = F_50 ( V_79 -> V_86 ,
F_51 ( V_79 ) ,
V_87 ) ;
if ( ! V_79 ) {
F_52 ( V_13 , L_14 ) ;
return - V_84 ;
}
V_17 . V_20 = V_80 ;
V_17 . V_88 = V_79 ;
#if F_53 ( V_89 )
V_83 = 64 ;
#elif F_53 ( V_90 ) || F_53 ( V_91 ) || F_53 ( V_92 ) \
|| F_53 ( V_93 ) || F_53 ( V_94 ) \
|| F_53 ( V_95 )
V_83 = 128 ;
#else
#warning Assuming 128 bytes of RTC+NVRAM address space, not 64 bytes.
V_83 = 128 ;
#endif
if ( V_70 && V_79 -> V_96 > ( V_79 -> V_86 + 1 ) )
V_83 = 256 ;
if ( V_82 ) {
if ( V_82 -> V_97 && V_82 -> V_97 < 128 )
V_17 . V_31 = V_82 -> V_97 ;
if ( V_82 -> V_98 && V_82 -> V_98 < 128 )
V_17 . V_32 = V_82 -> V_98 ;
if ( V_82 -> V_99 && V_82 -> V_99 < 128 )
V_17 . V_72 = V_82 -> V_99 ;
if ( V_82 -> V_100 && V_82 -> V_101 ) {
V_17 . V_100 = V_82 -> V_100 ;
V_17 . V_101 = V_82 -> V_101 ;
}
}
V_17 . V_13 = V_13 ;
F_54 ( V_13 , & V_17 ) ;
V_17 . V_41 = F_55 ( V_87 , V_13 ,
& V_102 , V_103 ) ;
if ( F_56 ( V_17 . V_41 ) ) {
V_67 = F_57 ( V_17 . V_41 ) ;
goto V_104;
}
F_58 ( V_79 , F_59 ( & V_17 . V_41 -> V_13 ) ) ;
F_23 ( & V_24 ) ;
V_17 . V_41 -> V_56 = 1024 ;
F_6 ( V_17 . V_41 -> V_56 ) ;
F_30 ( V_105 | 0x06 , V_106 ) ;
F_31 ( & V_17 , V_53 | V_38 | V_54 ) ;
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_24 ) ;
if ( F_22 ( V_80 ) && ! ( V_19 & V_107 ) ) {
F_60 ( V_13 , L_15 ) ;
V_67 = - V_108 ;
goto V_109;
}
if ( F_22 ( V_80 ) ) {
T_2 V_110 ;
if ( F_2 () ) {
V_110 = V_111 ;
V_67 = F_9 ( F_45 ) ;
if ( V_67 ) {
F_60 ( V_13 , L_16
L_17 ) ;
goto V_109;
}
} else
V_110 = F_45 ;
V_67 = F_61 ( V_80 , V_110 ,
0 , F_59 ( & V_17 . V_41 -> V_13 ) ,
V_17 . V_41 ) ;
if ( V_67 < 0 ) {
F_52 ( V_13 , L_18 , V_80 ) ;
goto V_109;
}
}
F_8 () ;
V_112 . V_68 = V_83 - V_69 ;
V_67 = F_62 ( & V_13 -> V_61 , & V_112 ) ;
if ( V_67 < 0 ) {
F_52 ( V_13 , L_19 , V_67 ) ;
goto V_113;
}
F_63 ( V_13 , L_20 ,
! F_22 ( V_80 ) ? L_21 :
V_17 . V_32 ? L_22 :
V_17 . V_31 ? L_23 :
L_24 ,
V_17 . V_72 ? L_25 : L_26 ,
V_112 . V_68 ,
F_2 () ? L_27 : L_26 ) ;
return 0 ;
V_113:
if ( F_22 ( V_80 ) )
F_64 ( V_80 , V_17 . V_41 ) ;
V_109:
V_17 . V_13 = NULL ;
F_65 ( V_17 . V_41 ) ;
V_104:
F_66 ( V_79 -> V_86 , F_51 ( V_79 ) ) ;
return V_67 ;
}
static void F_67 ( void )
{
F_23 ( & V_24 ) ;
F_31 ( & V_17 , V_3 ) ;
F_25 ( & V_24 ) ;
}
static void T_9 F_68 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
struct V_78 * V_79 ;
F_67 () ;
F_69 ( & V_13 -> V_61 , & V_112 ) ;
if ( F_22 ( V_18 -> V_20 ) ) {
F_64 ( V_18 -> V_20 , V_18 -> V_41 ) ;
F_10 ( F_45 ) ;
}
F_65 ( V_18 -> V_41 ) ;
V_18 -> V_41 = NULL ;
V_79 = V_18 -> V_88 ;
F_66 ( V_79 -> V_86 , F_51 ( V_79 ) ) ;
V_18 -> V_88 = NULL ;
V_18 -> V_13 = NULL ;
}
static int F_70 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_114 ;
F_23 ( & V_24 ) ;
V_18 -> V_75 = V_114 = F_24 ( V_33 ) ;
if ( V_114 & ( V_53 | V_38 | V_54 ) ) {
unsigned char V_4 ;
if ( F_71 ( V_13 ) )
V_4 = V_3 & ~ V_38 ;
else
V_4 = V_3 ;
V_114 &= ~ V_4 ;
F_30 ( V_114 , V_33 ) ;
F_3 ( V_4 ) ;
F_27 ( V_18 , V_114 ) ;
}
F_25 ( & V_24 ) ;
if ( V_114 & V_38 ) {
V_18 -> V_115 = 1 ;
if ( V_18 -> V_100 )
V_18 -> V_100 ( V_13 ) ;
else
F_72 ( V_18 -> V_20 ) ;
}
F_52 ( V_13 , L_28 ,
( V_114 & V_38 ) ? L_29 : L_26 ,
V_114 ) ;
return 0 ;
}
static inline int F_73 ( struct V_12 * V_13 )
{
return F_70 ( V_13 ) ;
}
static int F_74 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_114 ;
if ( V_18 -> V_115 ) {
if ( V_18 -> V_101 )
V_18 -> V_101 ( V_13 ) ;
else
F_75 ( V_18 -> V_20 ) ;
V_18 -> V_115 = 0 ;
}
F_23 ( & V_24 ) ;
V_114 = V_18 -> V_75 ;
V_18 -> V_75 = 0 ;
if ( V_114 & V_3 ) {
unsigned char V_4 ;
if ( F_71 ( V_13 ) )
F_8 () ;
do {
F_30 ( V_114 , V_33 ) ;
F_4 ( V_114 & V_3 ) ;
V_4 = F_24 ( V_40 ) ;
V_4 &= ( V_114 & V_3 ) | V_2 ;
if ( ! F_2 () || ! F_1 ( V_4 ) )
break;
F_28 ( V_18 -> V_41 , 1 , V_4 ) ;
V_114 &= ~ V_38 ;
F_3 ( V_38 ) ;
} while ( V_4 & V_38 );
}
F_25 ( & V_24 ) ;
F_52 ( V_13 , L_30 , V_114 ) ;
return 0 ;
}
static inline int F_73 ( struct V_12 * V_13 )
{
return - V_116 ;
}
static T_10 F_76 ( void * V_117 )
{
struct V_12 * V_13 = V_117 ;
F_77 ( V_13 , 0 ) ;
F_78 ( V_118 ) ;
F_79 ( V_118 , 0 ) ;
return V_119 ;
}
static inline void F_80 ( struct V_12 * V_13 )
{
F_81 ( V_118 , F_76 , V_13 ) ;
F_78 ( V_118 ) ;
F_79 ( V_118 , 0 ) ;
}
static void F_82 ( struct V_12 * V_13 )
{
F_78 ( V_118 ) ;
F_83 ( V_118 , 0 ) ;
}
static void F_84 ( struct V_12 * V_13 )
{
F_79 ( V_118 , 0 ) ;
}
static void F_85 ( struct V_12 * V_13 )
{
if ( V_120 )
return;
F_80 ( V_13 ) ;
V_121 . V_100 = F_82 ;
V_121 . V_101 = F_84 ;
if ( V_122 . V_123 && ! V_122 . V_124 ) {
F_52 ( V_13 , L_31 ,
V_122 . V_123 ) ;
V_122 . V_123 = 0 ;
}
V_121 . V_97 = V_122 . V_124 ;
V_121 . V_98 = V_122 . V_123 ;
V_121 . V_99 = V_122 . V_72 ;
if ( V_122 . V_47 & V_125 )
F_63 ( V_13 , L_32 ) ;
V_13 -> V_126 = & V_121 ;
F_86 ( V_13 , 1 ) ;
}
static void F_85 ( struct V_12 * V_13 )
{
}
static int F_87 ( struct V_127 * V_128 , const struct V_129 * V_45 )
{
F_85 ( & V_128 -> V_13 ) ;
if ( F_88 ( V_128 , 0 ) == 0x70 && ! F_89 ( V_128 , 0 ) )
return F_48 ( & V_128 -> V_13 ,
F_90 ( V_128 , V_130 , 0 ) , 8 ) ;
else
return F_48 ( & V_128 -> V_13 ,
F_90 ( V_128 , V_130 , 0 ) ,
F_91 ( V_128 , 0 ) ) ;
}
static void T_9 F_92 ( struct V_127 * V_128 )
{
F_68 ( & V_128 -> V_13 ) ;
}
static void F_93 ( struct V_127 * V_128 )
{
if ( V_131 == V_132 && ! F_73 ( & V_128 -> V_13 ) )
return;
F_67 () ;
}
static T_3 void F_94 ( struct V_133 * V_134 )
{
struct V_135 * V_136 = V_134 -> V_13 . V_137 ;
struct V_14 time ;
int V_138 ;
const T_11 * V_11 ;
if ( ! V_136 )
return;
V_11 = F_95 ( V_136 , L_33 , NULL ) ;
if ( V_11 )
F_30 ( F_96 ( V_11 ) , V_33 ) ;
V_11 = F_95 ( V_136 , L_34 , NULL ) ;
if ( V_11 )
F_30 ( F_96 ( V_11 ) , V_106 ) ;
F_17 ( & time ) ;
V_138 = F_97 ( & time ) ;
if ( V_138 ) {
struct V_14 V_139 = {
. V_36 = 1 ,
. V_22 = 1 ,
} ;
F_19 ( & V_139 ) ;
}
}
static inline void F_94 ( struct V_133 * V_134 ) {}
static int T_3 F_98 ( struct V_133 * V_134 )
{
F_94 ( V_134 ) ;
F_85 ( & V_134 -> V_13 ) ;
return F_48 ( & V_134 -> V_13 ,
F_99 ( V_134 , V_130 , 0 ) ,
F_100 ( V_134 , 0 ) ) ;
}
static int T_9 F_101 ( struct V_133 * V_134 )
{
F_68 ( & V_134 -> V_13 ) ;
return 0 ;
}
static void F_102 ( struct V_133 * V_134 )
{
if ( V_131 == V_132 && ! F_73 ( & V_134 -> V_13 ) )
return;
F_67 () ;
}
static int T_3 F_103 ( void )
{
int V_67 = 0 ;
#ifdef F_104
V_67 = F_105 ( & V_140 ) ;
if ( V_67 == 0 )
V_141 = true ;
#endif
if ( ! V_17 . V_13 ) {
V_67 = F_106 ( & V_142 ,
F_98 ) ;
if ( V_67 == 0 )
V_143 = true ;
}
F_107 ( V_144 ) ;
if ( V_67 == 0 )
return 0 ;
#ifdef F_104
if ( V_141 )
F_108 ( & V_140 ) ;
#endif
return V_67 ;
}
static void T_9 F_109 ( void )
{
#ifdef F_104
if ( V_141 )
F_108 ( & V_140 ) ;
#endif
if ( V_143 )
F_110 ( & V_142 ) ;
}
