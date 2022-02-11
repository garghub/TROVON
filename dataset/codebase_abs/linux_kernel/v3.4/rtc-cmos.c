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
static int F_34 ( struct V_12 * V_13 , unsigned int V_37 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned long V_44 ;
if ( ! F_22 ( V_18 -> V_20 ) )
return - V_45 ;
F_35 ( & V_24 , V_44 ) ;
if ( V_37 )
F_29 ( V_18 , V_38 ) ;
else
F_31 ( V_18 , V_38 ) ;
F_36 ( & V_24 , V_44 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , struct V_46 * V_47 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_19 , V_48 ;
F_23 ( & V_24 ) ;
V_19 = F_24 ( V_33 ) ;
V_48 = F_24 ( V_49 ) ;
F_25 ( & V_24 ) ;
return F_38 ( V_47 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7 ,
( V_19 & V_50 ) ? L_8 : L_9 ,
( V_19 & V_51 ) ? L_8 : L_9 ,
F_2 () ? L_8 : L_9 ,
( V_19 & V_34 ) ? L_9 : L_8 ,
( V_19 & V_52 ) ? L_8 : L_9 ,
V_18 -> V_41 -> V_53 ,
( V_48 & V_54 ) ? L_10 : L_11 ) ;
}
static T_3
F_39 ( struct V_55 * V_56 , struct V_57 * V_58 ,
struct V_59 * V_60 ,
char * V_61 , T_4 V_62 , T_5 V_63 )
{
int V_64 ;
if ( F_40 ( V_62 >= V_60 -> V_65 ) )
return 0 ;
if ( F_40 ( V_62 < 0 ) )
return - V_45 ;
if ( ( V_62 + V_63 ) > V_60 -> V_65 )
V_63 = V_60 -> V_65 - V_62 ;
V_62 += V_66 ;
F_23 ( & V_24 ) ;
for ( V_64 = 0 ; V_63 ; V_63 -- , V_62 ++ , V_64 ++ ) {
if ( V_62 < 128 )
* V_61 ++ = F_24 ( V_62 ) ;
else if ( V_67 )
* V_61 ++ = F_11 ( V_62 ) ;
else
break;
}
F_25 ( & V_24 ) ;
return V_64 ;
}
static T_3
F_41 ( struct V_55 * V_56 , struct V_57 * V_58 ,
struct V_59 * V_60 ,
char * V_61 , T_4 V_62 , T_5 V_63 )
{
struct V_17 * V_18 ;
int V_64 ;
V_18 = F_21 ( F_42 ( V_58 , struct V_12 , V_58 ) ) ;
if ( F_40 ( V_62 >= V_60 -> V_65 ) )
return - V_68 ;
if ( F_40 ( V_62 < 0 ) )
return - V_45 ;
if ( ( V_62 + V_63 ) > V_60 -> V_65 )
V_63 = V_60 -> V_65 - V_62 ;
V_62 += V_66 ;
F_23 ( & V_24 ) ;
for ( V_64 = 0 ; V_63 ; V_63 -- , V_62 ++ , V_64 ++ ) {
if ( V_62 == V_18 -> V_31
|| V_62 == V_18 -> V_32
|| V_62 == V_18 -> V_69 )
V_61 ++ ;
else if ( V_62 < 128 )
F_30 ( * V_61 ++ , V_62 ) ;
else if ( V_67 )
F_15 ( * V_61 ++ , V_62 ) ;
else
break;
}
F_25 ( & V_24 ) ;
return V_64 ;
}
static T_6 F_43 ( int V_20 , void * V_70 )
{
T_1 V_71 ;
T_1 V_19 ;
F_44 ( & V_24 ) ;
V_71 = F_24 ( V_40 ) ;
V_19 = F_24 ( V_33 ) ;
if ( F_2 () )
V_71 = ( unsigned long ) V_20 & 0xF0 ;
V_71 &= ( V_19 & V_3 ) | V_2 ;
if ( V_71 & V_38 ) {
V_19 &= ~ V_38 ;
F_30 ( V_19 , V_33 ) ;
F_3 ( V_38 ) ;
F_24 ( V_40 ) ;
}
F_45 ( & V_24 ) ;
if ( F_1 ( V_71 ) ) {
F_28 ( V_70 , 1 , V_71 ) ;
return V_72 ;
} else
return V_73 ;
}
static int T_7
F_46 ( struct V_12 * V_13 , struct V_74 * V_75 , int V_76 )
{
struct V_77 * V_78 = V_13 -> V_79 ;
int V_64 = 0 ;
unsigned char V_19 ;
unsigned V_80 ;
if ( V_17 . V_13 )
return - V_81 ;
if ( ! V_75 )
return - V_82 ;
V_75 = F_47 ( V_75 -> V_83 ,
F_48 ( V_75 ) ,
V_84 ) ;
if ( ! V_75 ) {
F_49 ( V_13 , L_12 ) ;
return - V_81 ;
}
V_17 . V_20 = V_76 ;
V_17 . V_85 = V_75 ;
#if F_50 ( V_86 )
V_80 = 64 ;
#elif F_50 ( V_87 ) || F_50 ( V_88 ) || F_50 ( V_89 ) \
|| F_50 ( V_90 ) || F_50 ( V_91 ) \
|| F_50 ( V_92 )
V_80 = 128 ;
#else
#warning Assuming 128 bytes of RTC+NVRAM address space, not 64 bytes.
V_80 = 128 ;
#endif
if ( V_67 && V_75 -> V_93 > ( V_75 -> V_83 + 1 ) )
V_80 = 256 ;
if ( V_78 ) {
if ( V_78 -> V_94 && V_78 -> V_94 < 128 )
V_17 . V_31 = V_78 -> V_94 ;
if ( V_78 -> V_95 && V_78 -> V_95 < 128 )
V_17 . V_32 = V_78 -> V_95 ;
if ( V_78 -> V_96 && V_78 -> V_96 < 128 )
V_17 . V_69 = V_78 -> V_96 ;
if ( V_78 -> V_97 && V_78 -> V_98 ) {
V_17 . V_97 = V_78 -> V_97 ;
V_17 . V_98 = V_78 -> V_98 ;
}
}
V_17 . V_13 = V_13 ;
F_51 ( V_13 , & V_17 ) ;
V_17 . V_41 = F_52 ( V_84 , V_13 ,
& V_99 , V_100 ) ;
if ( F_53 ( V_17 . V_41 ) ) {
V_64 = F_54 ( V_17 . V_41 ) ;
goto V_101;
}
F_55 ( V_75 , F_56 ( & V_17 . V_41 -> V_13 ) ) ;
F_23 ( & V_24 ) ;
V_17 . V_41 -> V_53 = 1024 ;
F_6 ( V_17 . V_41 -> V_53 ) ;
F_30 ( V_102 | 0x06 , V_103 ) ;
F_31 ( & V_17 , V_50 | V_38 | V_51 ) ;
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_24 ) ;
if ( F_22 ( V_76 ) && ! ( V_19 & V_104 ) ) {
F_57 ( V_13 , L_13 ) ;
V_64 = - V_105 ;
goto V_106;
}
if ( F_22 ( V_76 ) ) {
T_2 V_107 ;
if ( F_2 () ) {
int V_108 ;
V_107 = V_109 ;
V_108 = F_9 ( F_43 ) ;
if ( V_108 != 0 ) {
F_58 ( V_110 L_14
L_15 ) ;
goto V_106;
}
} else
V_107 = F_43 ;
V_64 = F_59 ( V_76 , V_107 ,
0 , F_56 ( & V_17 . V_41 -> V_13 ) ,
V_17 . V_41 ) ;
if ( V_64 < 0 ) {
F_49 ( V_13 , L_16 , V_76 ) ;
goto V_106;
}
}
F_8 () ;
V_111 . V_65 = V_80 - V_66 ;
V_64 = F_60 ( & V_13 -> V_58 , & V_111 ) ;
if ( V_64 < 0 ) {
F_49 ( V_13 , L_17 , V_64 ) ;
goto V_112;
}
F_61 ( L_18 ,
F_56 ( & V_17 . V_41 -> V_13 ) ,
! F_22 ( V_76 ) ? L_19 :
V_17 . V_32 ? L_20 :
V_17 . V_31 ? L_21 :
L_22 ,
V_17 . V_69 ? L_23 : L_24 ,
V_111 . V_65 ,
F_2 () ? L_25 : L_24 ) ;
return 0 ;
V_112:
if ( F_22 ( V_76 ) )
F_62 ( V_76 , V_17 . V_41 ) ;
V_106:
V_17 . V_13 = NULL ;
F_63 ( V_17 . V_41 ) ;
V_101:
F_64 ( V_75 -> V_83 , F_48 ( V_75 ) ) ;
return V_64 ;
}
static void F_65 ( void )
{
F_23 ( & V_24 ) ;
F_31 ( & V_17 , V_3 ) ;
F_25 ( & V_24 ) ;
}
static void T_8 F_66 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
struct V_74 * V_75 ;
F_65 () ;
F_67 ( & V_13 -> V_58 , & V_111 ) ;
if ( F_22 ( V_18 -> V_20 ) ) {
F_62 ( V_18 -> V_20 , V_18 -> V_41 ) ;
F_10 ( F_43 ) ;
}
F_63 ( V_18 -> V_41 ) ;
V_18 -> V_41 = NULL ;
V_75 = V_18 -> V_85 ;
F_64 ( V_75 -> V_83 , F_48 ( V_75 ) ) ;
V_18 -> V_85 = NULL ;
V_18 -> V_13 = NULL ;
F_51 ( V_13 , NULL ) ;
}
static int F_68 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_113 ;
F_23 ( & V_24 ) ;
V_18 -> V_114 = V_113 = F_24 ( V_33 ) ;
if ( V_113 & ( V_50 | V_38 | V_51 ) ) {
unsigned char V_4 ;
if ( F_69 ( V_13 ) )
V_4 = V_3 & ~ V_38 ;
else
V_4 = V_3 ;
V_113 &= ~ V_4 ;
F_30 ( V_113 , V_33 ) ;
F_3 ( V_50 | V_38 | V_51 ) ;
F_27 ( V_18 , V_113 ) ;
}
F_25 ( & V_24 ) ;
if ( V_113 & V_38 ) {
V_18 -> V_115 = 1 ;
if ( V_18 -> V_97 )
V_18 -> V_97 ( V_13 ) ;
else
F_70 ( V_18 -> V_20 ) ;
}
F_71 ( L_26 ,
F_56 ( & V_17 . V_41 -> V_13 ) ,
( V_113 & V_38 ) ? L_27 : L_24 ,
V_113 ) ;
return 0 ;
}
static inline int F_72 ( struct V_12 * V_13 )
{
return F_68 ( V_13 ) ;
}
static int F_73 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_113 = V_18 -> V_114 ;
if ( V_113 & V_3 ) {
unsigned char V_4 ;
if ( V_18 -> V_115 ) {
if ( V_18 -> V_98 )
V_18 -> V_98 ( V_13 ) ;
else
F_74 ( V_18 -> V_20 ) ;
V_18 -> V_115 = 0 ;
}
F_23 ( & V_24 ) ;
do {
F_30 ( V_113 , V_33 ) ;
F_4 ( V_113 & V_3 ) ;
V_4 = F_24 ( V_40 ) ;
V_4 &= ( V_113 & V_3 ) | V_2 ;
if ( ! F_2 () || ! F_1 ( V_4 ) )
break;
F_28 ( V_18 -> V_41 , 1 , V_4 ) ;
V_113 &= ~ V_38 ;
F_3 ( V_38 ) ;
} while ( V_4 & V_38 );
F_25 ( & V_24 ) ;
}
F_71 ( L_28 ,
F_56 ( & V_17 . V_41 -> V_13 ) ,
V_113 ) ;
return 0 ;
}
static inline int F_72 ( struct V_12 * V_13 )
{
return - V_116 ;
}
static T_9 F_75 ( void * V_117 )
{
F_76 ( V_118 ) ;
F_77 ( V_118 , 0 ) ;
return V_119 ;
}
static inline void F_78 ( void )
{
F_79 ( V_118 , F_75 , NULL ) ;
F_76 ( V_118 ) ;
F_77 ( V_118 , 0 ) ;
}
static void F_80 ( struct V_12 * V_13 )
{
F_76 ( V_118 ) ;
F_81 ( V_118 , 0 ) ;
}
static void F_82 ( struct V_12 * V_13 )
{
F_77 ( V_118 , 0 ) ;
}
static void T_10
F_83 ( struct V_12 * V_13 )
{
if ( V_120 )
return;
F_78 () ;
V_121 . V_97 = F_80 ;
V_121 . V_98 = F_82 ;
if ( V_122 . V_123 && ! V_122 . V_124 ) {
F_49 ( V_13 , L_29 ,
V_122 . V_123 ) ;
V_122 . V_123 = 0 ;
}
V_121 . V_94 = V_122 . V_124 ;
V_121 . V_95 = V_122 . V_123 ;
V_121 . V_96 = V_122 . V_69 ;
if ( V_122 . V_44 & V_125 )
F_84 ( V_13 , L_30 ) ;
V_13 -> V_79 = & V_121 ;
F_85 ( V_13 , 1 ) ;
}
static void T_10
F_83 ( struct V_12 * V_13 )
{
}
static int T_10
F_86 ( struct V_126 * V_127 , const struct V_128 * V_129 )
{
F_83 ( & V_127 -> V_13 ) ;
if ( F_87 ( V_127 , 0 ) == 0x70 && ! F_88 ( V_127 , 0 ) )
return F_46 ( & V_127 -> V_13 ,
F_89 ( V_127 , V_130 , 0 ) , 8 ) ;
else
return F_46 ( & V_127 -> V_13 ,
F_89 ( V_127 , V_130 , 0 ) ,
F_90 ( V_127 , 0 ) ) ;
}
static void T_8 F_91 ( struct V_126 * V_127 )
{
F_66 ( & V_127 -> V_13 ) ;
}
static int F_92 ( struct V_126 * V_127 , T_11 V_131 )
{
return F_68 ( & V_127 -> V_13 ) ;
}
static int F_93 ( struct V_126 * V_127 )
{
return F_73 ( & V_127 -> V_13 ) ;
}
static void F_94 ( struct V_126 * V_127 )
{
if ( V_132 == V_133 && ! F_72 ( & V_127 -> V_13 ) )
return;
F_65 () ;
}
static T_12 void F_95 ( struct V_134 * V_135 )
{
struct V_136 * V_137 = V_135 -> V_13 . V_138 ;
struct V_14 time ;
int V_139 ;
const T_13 * V_11 ;
if ( ! V_137 )
return;
V_11 = F_96 ( V_137 , L_31 , NULL ) ;
if ( V_11 )
F_30 ( F_97 ( V_11 ) , V_33 ) ;
V_11 = F_96 ( V_137 , L_32 , NULL ) ;
if ( V_11 )
F_30 ( F_97 ( V_11 ) , V_103 ) ;
F_17 ( & time ) ;
V_139 = F_98 ( & time ) ;
if ( V_139 ) {
struct V_14 V_140 = {
. V_36 = 1 ,
. V_22 = 1 ,
} ;
F_19 ( & V_140 ) ;
}
}
static inline void F_95 ( struct V_134 * V_135 ) {}
static int T_12 F_99 ( struct V_134 * V_135 )
{
F_95 ( V_135 ) ;
F_83 ( & V_135 -> V_13 ) ;
return F_46 ( & V_135 -> V_13 ,
F_100 ( V_135 , V_130 , 0 ) ,
F_101 ( V_135 , 0 ) ) ;
}
static int T_8 F_102 ( struct V_134 * V_135 )
{
F_66 ( & V_135 -> V_13 ) ;
return 0 ;
}
static void F_103 ( struct V_134 * V_135 )
{
if ( V_132 == V_133 && ! F_72 ( & V_135 -> V_13 ) )
return;
F_65 () ;
}
static int T_12 F_104 ( void )
{
int V_64 = 0 ;
#ifdef F_105
V_64 = F_106 ( & V_141 ) ;
if ( V_64 == 0 )
V_142 = true ;
#endif
if ( ! V_17 . V_13 ) {
V_64 = F_107 ( & V_143 ,
F_99 ) ;
if ( V_64 == 0 )
V_144 = true ;
}
if ( V_64 == 0 )
return 0 ;
#ifdef F_105
if ( V_142 )
F_108 ( & V_141 ) ;
#endif
return V_64 ;
}
static void T_8 F_109 ( void )
{
#ifdef F_105
if ( V_142 )
F_108 ( & V_141 ) ;
#endif
if ( V_144 )
F_110 ( & V_143 ) ;
}
