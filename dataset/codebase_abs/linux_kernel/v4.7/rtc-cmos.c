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
V_18 -> V_44 = F_34 ( & V_15 -> time ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 , unsigned int V_37 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned long V_45 ;
if ( ! F_22 ( V_18 -> V_20 ) )
return - V_46 ;
F_36 ( & V_24 , V_45 ) ;
if ( V_37 )
F_29 ( V_18 , V_38 ) ;
else
F_31 ( V_18 , V_38 ) ;
F_37 ( & V_24 , V_45 ) ;
return 0 ;
}
static int F_38 ( struct V_12 * V_13 , struct V_47 * V_48 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_19 , V_49 ;
F_23 ( & V_24 ) ;
V_19 = F_24 ( V_33 ) ;
V_49 = F_24 ( V_50 ) ;
F_25 ( & V_24 ) ;
F_39 ( V_48 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7 ,
( V_19 & V_51 ) ? L_8 : L_9 ,
( V_19 & V_52 ) ? L_8 : L_9 ,
F_2 () ? L_8 : L_9 ,
( V_19 & V_34 ) ? L_9 : L_8 ,
( V_19 & V_53 ) ? L_8 : L_9 ,
V_18 -> V_41 -> V_54 ,
( V_49 & V_55 ) ? L_10 : L_11 ) ;
return 0 ;
}
static T_3
F_40 ( struct V_56 * V_57 , struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 , T_4 V_63 , T_5 V_64 )
{
int V_65 ;
V_63 += V_66 ;
F_23 ( & V_24 ) ;
for ( V_65 = 0 ; V_64 ; V_64 -- , V_63 ++ , V_65 ++ ) {
if ( V_63 < 128 )
* V_62 ++ = F_24 ( V_63 ) ;
else if ( V_67 )
* V_62 ++ = F_11 ( V_63 ) ;
else
break;
}
F_25 ( & V_24 ) ;
return V_65 ;
}
static T_3
F_41 ( struct V_56 * V_57 , struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 , T_4 V_63 , T_5 V_64 )
{
struct V_17 * V_18 ;
int V_65 ;
V_18 = F_21 ( F_42 ( V_59 , struct V_12 , V_59 ) ) ;
V_63 += V_66 ;
F_23 ( & V_24 ) ;
for ( V_65 = 0 ; V_64 ; V_64 -- , V_63 ++ , V_65 ++ ) {
if ( V_63 == V_18 -> V_31
|| V_63 == V_18 -> V_32
|| V_63 == V_18 -> V_68 )
V_62 ++ ;
else if ( V_63 < 128 )
F_30 ( * V_62 ++ , V_63 ) ;
else if ( V_67 )
F_15 ( * V_62 ++ , V_63 ) ;
else
break;
}
F_25 ( & V_24 ) ;
return V_65 ;
}
static T_6 F_43 ( int V_20 , void * V_69 )
{
T_1 V_70 ;
T_1 V_19 ;
F_44 ( & V_24 ) ;
V_70 = F_24 ( V_40 ) ;
V_19 = F_24 ( V_33 ) ;
if ( F_2 () )
V_70 = ( unsigned long ) V_20 & 0xF0 ;
if ( ! V_17 . V_71 )
V_70 &= ( V_19 & V_3 ) | V_2 ;
else
V_70 &= ( V_17 . V_71 & V_3 ) | V_2 ;
if ( V_70 & V_38 ) {
V_17 . V_71 &= ~ V_38 ;
V_19 &= ~ V_38 ;
F_30 ( V_19 , V_33 ) ;
F_3 ( V_38 ) ;
F_24 ( V_40 ) ;
}
F_45 ( & V_24 ) ;
if ( F_1 ( V_70 ) ) {
F_28 ( V_69 , 1 , V_70 ) ;
return V_72 ;
} else
return V_73 ;
}
static int T_7
F_46 ( struct V_12 * V_13 , struct V_74 * V_75 , int V_76 )
{
struct V_77 * V_78 = F_47 ( V_13 ) ;
int V_65 = 0 ;
unsigned char V_19 ;
unsigned V_79 ;
T_8 V_45 = 0 ;
if ( V_17 . V_13 )
return - V_80 ;
if ( ! V_75 )
return - V_81 ;
if ( V_82 )
V_75 = F_48 ( V_75 -> V_83 , F_49 ( V_75 ) ,
V_84 ) ;
else
V_75 = F_50 ( V_75 -> V_83 , F_49 ( V_75 ) ,
V_84 ) ;
if ( ! V_75 ) {
F_51 ( V_13 , L_12 ) ;
return - V_80 ;
}
V_17 . V_20 = V_76 ;
V_17 . V_85 = V_75 ;
#if F_52 ( V_86 )
V_79 = 64 ;
#elif F_52 ( V_87 ) || F_52 ( V_88 ) || F_52 ( V_89 ) \
|| F_52 ( V_90 ) || F_52 ( V_91 ) \
|| F_52 ( V_92 )
V_79 = 128 ;
#else
#warning Assuming 128 bytes of RTC+NVRAM address space, not 64 bytes.
V_79 = 128 ;
#endif
if ( V_67 && V_75 -> V_93 > ( V_75 -> V_83 + 1 ) )
V_79 = 256 ;
if ( V_78 ) {
if ( V_78 -> V_45 )
V_45 = V_78 -> V_45 ;
if ( V_78 -> V_79 )
V_79 = V_78 -> V_79 ;
if ( V_78 -> V_94 && V_78 -> V_94 < 128 )
V_17 . V_31 = V_78 -> V_94 ;
if ( V_78 -> V_95 && V_78 -> V_95 < 128 )
V_17 . V_32 = V_78 -> V_95 ;
if ( V_78 -> V_96 && V_78 -> V_96 < 128 )
V_17 . V_68 = V_78 -> V_96 ;
if ( V_78 -> V_97 && V_78 -> V_98 ) {
V_17 . V_97 = V_78 -> V_97 ;
V_17 . V_98 = V_78 -> V_98 ;
}
}
V_17 . V_13 = V_13 ;
F_53 ( V_13 , & V_17 ) ;
V_17 . V_41 = F_54 ( V_84 , V_13 ,
& V_99 , V_100 ) ;
if ( F_55 ( V_17 . V_41 ) ) {
V_65 = F_56 ( V_17 . V_41 ) ;
goto V_101;
}
F_57 ( V_75 , F_58 ( & V_17 . V_41 -> V_13 ) ) ;
F_23 ( & V_24 ) ;
if ( ! ( V_45 & V_102 ) ) {
V_17 . V_41 -> V_54 = 1024 ;
F_6 ( V_17 . V_41 -> V_54 ) ;
F_30 ( V_103 | 0x06 , V_104 ) ;
}
if ( F_22 ( V_76 ) )
F_31 ( & V_17 , V_51 | V_38 | V_52 ) ;
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_24 ) ;
if ( F_22 ( V_76 ) && ! ( V_19 & V_105 ) ) {
F_59 ( V_13 , L_13 ) ;
V_65 = - V_106 ;
goto V_107;
}
if ( F_22 ( V_76 ) ) {
T_2 V_108 ;
if ( F_2 () ) {
V_108 = V_109 ;
V_65 = F_9 ( F_43 ) ;
if ( V_65 ) {
F_59 ( V_13 , L_14
L_15 ) ;
goto V_107;
}
} else
V_108 = F_43 ;
V_65 = F_60 ( V_76 , V_108 ,
V_110 , F_58 ( & V_17 . V_41 -> V_13 ) ,
V_17 . V_41 ) ;
if ( V_65 < 0 ) {
F_51 ( V_13 , L_16 , V_76 ) ;
goto V_107;
}
}
F_8 () ;
V_111 . V_112 = V_79 - V_66 ;
V_65 = F_61 ( & V_13 -> V_59 , & V_111 ) ;
if ( V_65 < 0 ) {
F_51 ( V_13 , L_17 , V_65 ) ;
goto V_113;
}
F_62 ( V_13 , L_18 ,
! F_22 ( V_76 ) ? L_19 :
V_17 . V_32 ? L_20 :
V_17 . V_31 ? L_21 :
L_22 ,
V_17 . V_68 ? L_23 : L_24 ,
V_111 . V_112 ,
F_2 () ? L_25 : L_24 ) ;
return 0 ;
V_113:
if ( F_22 ( V_76 ) )
F_63 ( V_76 , V_17 . V_41 ) ;
V_107:
V_17 . V_13 = NULL ;
F_64 ( V_17 . V_41 ) ;
V_101:
if ( V_82 )
F_65 ( V_75 -> V_83 , F_49 ( V_75 ) ) ;
else
F_66 ( V_75 -> V_83 , F_49 ( V_75 ) ) ;
return V_65 ;
}
static void F_67 ( int V_76 )
{
F_23 ( & V_24 ) ;
if ( F_22 ( V_76 ) )
F_31 ( & V_17 , V_3 ) ;
F_25 ( & V_24 ) ;
}
static void T_9 F_68 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
struct V_74 * V_75 ;
F_67 ( V_18 -> V_20 ) ;
F_69 ( & V_13 -> V_59 , & V_111 ) ;
if ( F_22 ( V_18 -> V_20 ) ) {
F_63 ( V_18 -> V_20 , V_18 -> V_41 ) ;
F_10 ( F_43 ) ;
}
F_64 ( V_18 -> V_41 ) ;
V_18 -> V_41 = NULL ;
V_75 = V_18 -> V_85 ;
if ( V_82 )
F_65 ( V_75 -> V_83 , F_49 ( V_75 ) ) ;
else
F_66 ( V_75 -> V_83 , F_49 ( V_75 ) ) ;
V_18 -> V_85 = NULL ;
V_18 -> V_13 = NULL ;
}
static int F_70 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
struct V_14 V_114 ;
T_10 V_115 ;
int V_65 = 0 ;
unsigned char V_19 ;
if ( ! V_18 -> V_44 )
return - V_46 ;
F_23 ( & V_24 ) ;
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_24 ) ;
if ( V_19 & V_38 )
return - V_80 ;
F_16 ( V_13 , & V_114 ) ;
V_115 = F_34 ( & V_114 ) ;
if ( V_18 -> V_44 == V_115 + 1 ) {
struct V_16 V_116 ;
F_71 ( V_115 - 1 , & V_116 . time ) ;
V_116 . V_37 = 0 ;
V_65 = F_32 ( V_13 , & V_116 ) ;
} else if ( V_18 -> V_44 > V_115 + 1 ) {
V_65 = - V_80 ;
}
return V_65 ;
}
static int F_72 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_117 ;
F_23 ( & V_24 ) ;
V_18 -> V_71 = V_117 = F_24 ( V_33 ) ;
if ( V_117 & ( V_51 | V_38 | V_52 ) ) {
unsigned char V_4 ;
if ( F_73 ( V_13 ) )
V_4 = V_3 & ~ V_38 ;
else
V_4 = V_3 ;
V_117 &= ~ V_4 ;
F_30 ( V_117 , V_33 ) ;
F_3 ( V_4 ) ;
F_27 ( V_18 , V_117 ) ;
}
F_25 ( & V_24 ) ;
if ( V_117 & V_38 ) {
V_18 -> V_118 = 1 ;
if ( V_18 -> V_97 )
V_18 -> V_97 ( V_13 ) ;
else
F_74 ( V_18 -> V_20 ) ;
}
F_51 ( V_13 , L_26 ,
( V_117 & V_38 ) ? L_27 : L_24 ,
V_117 ) ;
return 0 ;
}
static inline int F_75 ( struct V_12 * V_13 )
{
return F_72 ( V_13 ) ;
}
static int F_76 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_117 ;
if ( V_18 -> V_118 ) {
if ( V_18 -> V_98 )
V_18 -> V_98 ( V_13 ) ;
else
F_77 ( V_18 -> V_20 ) ;
V_18 -> V_118 = 0 ;
}
F_23 ( & V_24 ) ;
V_117 = V_18 -> V_71 ;
V_18 -> V_71 = 0 ;
if ( V_117 & V_3 ) {
unsigned char V_4 ;
if ( F_73 ( V_13 ) )
F_8 () ;
do {
F_30 ( V_117 , V_33 ) ;
F_4 ( V_117 & V_3 ) ;
V_4 = F_24 ( V_40 ) ;
V_4 &= ( V_117 & V_3 ) | V_2 ;
if ( ! F_2 () || ! F_1 ( V_4 ) )
break;
F_28 ( V_18 -> V_41 , 1 , V_4 ) ;
V_117 &= ~ V_38 ;
F_3 ( V_38 ) ;
} while ( V_4 & V_38 );
}
F_25 ( & V_24 ) ;
F_51 ( V_13 , L_28 , V_117 ) ;
return 0 ;
}
static inline int F_75 ( struct V_12 * V_13 )
{
return - V_119 ;
}
static T_8 F_78 ( void * V_120 )
{
struct V_12 * V_13 = V_120 ;
F_79 ( V_13 , 0 ) ;
F_80 ( V_121 ) ;
F_81 ( V_121 , 0 ) ;
return V_122 ;
}
static inline void F_82 ( struct V_12 * V_13 )
{
F_83 ( V_121 , F_78 , V_13 ) ;
F_80 ( V_121 ) ;
F_81 ( V_121 , 0 ) ;
}
static void F_84 ( struct V_12 * V_13 )
{
F_80 ( V_121 ) ;
F_85 ( V_121 , 0 ) ;
}
static void F_86 ( struct V_12 * V_13 )
{
F_81 ( V_121 , 0 ) ;
}
static void F_87 ( struct V_12 * V_13 )
{
if ( V_123 )
return;
F_82 ( V_13 ) ;
V_124 . V_97 = F_84 ;
V_124 . V_98 = F_86 ;
if ( V_125 . V_126 && ! V_125 . V_127 ) {
F_51 ( V_13 , L_29 ,
V_125 . V_126 ) ;
V_125 . V_126 = 0 ;
}
V_124 . V_94 = V_125 . V_127 ;
V_124 . V_95 = V_125 . V_126 ;
V_124 . V_96 = V_125 . V_68 ;
if ( V_125 . V_45 & V_128 )
F_62 ( V_13 , L_30 ) ;
V_13 -> V_129 = & V_124 ;
F_88 ( V_13 , 1 ) ;
}
static void F_87 ( struct V_12 * V_13 )
{
}
static int F_89 ( struct V_130 * V_131 , const struct V_132 * V_133 )
{
F_87 ( & V_131 -> V_13 ) ;
if ( F_90 ( V_131 , 0 ) == 0x70 && ! F_91 ( V_131 , 0 ) )
return F_46 ( & V_131 -> V_13 ,
F_92 ( V_131 , V_134 , 0 ) , 8 ) ;
else
return F_46 ( & V_131 -> V_13 ,
F_92 ( V_131 , V_134 , 0 ) ,
F_93 ( V_131 , 0 ) ) ;
}
static void T_9 F_94 ( struct V_130 * V_131 )
{
F_68 ( & V_131 -> V_13 ) ;
}
static void F_95 ( struct V_130 * V_131 )
{
struct V_12 * V_13 = & V_131 -> V_13 ;
struct V_17 * V_18 = F_21 ( V_13 ) ;
if ( V_135 == V_136 ) {
int V_65 = F_75 ( V_13 ) ;
if ( F_70 ( V_13 ) < 0 && ! V_65 )
return;
}
F_67 ( V_18 -> V_20 ) ;
}
static T_11 void F_96 ( struct V_137 * V_138 )
{
struct V_139 * V_140 = V_138 -> V_13 . V_141 ;
struct V_14 time ;
int V_142 ;
const T_12 * V_11 ;
if ( ! V_140 )
return;
V_11 = F_97 ( V_140 , L_31 , NULL ) ;
if ( V_11 )
F_30 ( F_98 ( V_11 ) , V_33 ) ;
V_11 = F_97 ( V_140 , L_32 , NULL ) ;
if ( V_11 )
F_30 ( F_98 ( V_11 ) , V_104 ) ;
F_17 ( & time ) ;
V_142 = F_99 ( & time ) ;
if ( V_142 ) {
struct V_14 V_143 = {
. V_36 = 1 ,
. V_22 = 1 ,
} ;
F_19 ( & V_143 ) ;
}
}
static inline void F_96 ( struct V_137 * V_138 ) {}
static int T_11 F_100 ( struct V_137 * V_138 )
{
struct V_74 * V_74 ;
int V_20 ;
F_96 ( V_138 ) ;
F_87 ( & V_138 -> V_13 ) ;
if ( V_82 )
V_74 = F_101 ( V_138 , V_134 , 0 ) ;
else
V_74 = F_101 ( V_138 , V_144 , 0 ) ;
V_20 = F_102 ( V_138 , 0 ) ;
if ( V_20 < 0 )
V_20 = - 1 ;
return F_46 ( & V_138 -> V_13 , V_74 , V_20 ) ;
}
static int T_9 F_103 ( struct V_137 * V_138 )
{
F_68 ( & V_138 -> V_13 ) ;
return 0 ;
}
static void F_104 ( struct V_137 * V_138 )
{
struct V_12 * V_13 = & V_138 -> V_13 ;
struct V_17 * V_18 = F_21 ( V_13 ) ;
if ( V_135 == V_136 ) {
int V_65 = F_75 ( V_13 ) ;
if ( F_70 ( V_13 ) < 0 && ! V_65 )
return;
}
F_67 ( V_18 -> V_20 ) ;
}
static int T_11 F_105 ( void )
{
int V_65 = 0 ;
#ifdef F_106
V_65 = F_107 ( & V_145 ) ;
if ( V_65 == 0 )
V_146 = true ;
#endif
if ( ! V_17 . V_13 ) {
V_65 = F_108 ( & V_147 ,
F_100 ) ;
if ( V_65 == 0 )
V_148 = true ;
}
if ( V_65 == 0 )
return 0 ;
#ifdef F_106
if ( V_146 )
F_109 ( & V_145 ) ;
#endif
return V_65 ;
}
static void T_9 F_110 ( void )
{
#ifdef F_106
if ( V_146 )
F_109 ( & V_145 ) ;
#endif
if ( V_148 )
F_111 ( & V_147 ) ;
}
