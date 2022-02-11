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
F_23 ( & V_22 ) ;
V_15 -> time . V_23 = F_24 ( V_24 ) ;
V_15 -> time . V_25 = F_24 ( V_26 ) ;
V_15 -> time . V_27 = F_24 ( V_28 ) ;
if ( V_18 -> V_29 ) {
V_15 -> time . V_30 = F_24 ( V_18 -> V_29 ) & 0x3f ;
if ( ! V_15 -> time . V_30 )
V_15 -> time . V_30 = - 1 ;
if ( V_18 -> V_31 ) {
V_15 -> time . V_32 = F_24 ( V_18 -> V_31 ) ;
if ( ! V_15 -> time . V_32 )
V_15 -> time . V_32 = - 1 ;
}
}
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_22 ) ;
if ( ! ( V_19 & V_34 ) || V_35 ) {
if ( ( ( unsigned ) V_15 -> time . V_23 ) < 0x60 )
V_15 -> time . V_23 = F_26 ( V_15 -> time . V_23 ) ;
else
V_15 -> time . V_23 = - 1 ;
if ( ( ( unsigned ) V_15 -> time . V_25 ) < 0x60 )
V_15 -> time . V_25 = F_26 ( V_15 -> time . V_25 ) ;
else
V_15 -> time . V_25 = - 1 ;
if ( ( ( unsigned ) V_15 -> time . V_27 ) < 0x24 )
V_15 -> time . V_27 = F_26 ( V_15 -> time . V_27 ) ;
else
V_15 -> time . V_27 = - 1 ;
if ( V_18 -> V_29 ) {
if ( ( ( unsigned ) V_15 -> time . V_30 ) <= 0x31 )
V_15 -> time . V_30 = F_26 ( V_15 -> time . V_30 ) ;
else
V_15 -> time . V_30 = - 1 ;
if ( V_18 -> V_31 ) {
if ( ( ( unsigned ) V_15 -> time . V_32 ) <= 0x12 )
V_15 -> time . V_32 = F_26 ( V_15 -> time . V_32 ) - 1 ;
else
V_15 -> time . V_32 = - 1 ;
}
}
}
V_15 -> V_36 = ! ! ( V_19 & V_37 ) ;
V_15 -> V_38 = 0 ;
return 0 ;
}
static void F_27 ( struct V_17 * V_18 , unsigned char V_19 )
{
unsigned char V_1 ;
V_1 = F_24 ( V_39 ) ;
if ( F_2 () )
return;
V_1 &= ( V_19 & V_3 ) | V_2 ;
if ( F_1 ( V_1 ) )
F_28 ( V_18 -> V_40 , 1 , V_1 ) ;
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
unsigned char V_41 , V_42 , V_5 , V_6 , V_7 , V_19 ;
if ( ! F_22 ( V_18 -> V_20 ) )
return - V_21 ;
V_41 = V_15 -> time . V_32 + 1 ;
V_42 = V_15 -> time . V_30 ;
V_5 = V_15 -> time . V_27 ;
V_6 = V_15 -> time . V_25 ;
V_7 = V_15 -> time . V_23 ;
V_19 = F_24 ( V_33 ) ;
if ( ! ( V_19 & V_34 ) || V_35 ) {
V_41 = ( V_41 <= 12 ) ? F_33 ( V_41 ) : 0xff ;
V_42 = ( V_42 >= 1 && V_42 <= 31 ) ? F_33 ( V_42 ) : 0xff ;
V_5 = ( V_5 < 24 ) ? F_33 ( V_5 ) : 0xff ;
V_6 = ( V_6 < 60 ) ? F_33 ( V_6 ) : 0xff ;
V_7 = ( V_7 < 60 ) ? F_33 ( V_7 ) : 0xff ;
}
F_23 ( & V_22 ) ;
F_31 ( V_18 , V_37 ) ;
F_30 ( V_5 , V_28 ) ;
F_30 ( V_6 , V_26 ) ;
F_30 ( V_7 , V_24 ) ;
if ( V_18 -> V_29 ) {
F_30 ( V_42 , V_18 -> V_29 ) ;
if ( V_18 -> V_31 )
F_30 ( V_41 , V_18 -> V_31 ) ;
}
F_5 ( V_15 -> time . V_27 , V_15 -> time . V_25 , V_15 -> time . V_23 ) ;
if ( V_15 -> V_36 )
F_29 ( V_18 , V_37 ) ;
F_25 ( & V_22 ) ;
V_18 -> V_43 = F_34 ( & V_15 -> time ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 , unsigned int V_36 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned long V_44 ;
if ( ! F_22 ( V_18 -> V_20 ) )
return - V_45 ;
F_36 ( & V_22 , V_44 ) ;
if ( V_36 )
F_29 ( V_18 , V_37 ) ;
else
F_31 ( V_18 , V_37 ) ;
F_37 ( & V_22 , V_44 ) ;
return 0 ;
}
static int F_38 ( struct V_12 * V_13 , struct V_46 * V_47 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_19 , V_48 ;
F_23 ( & V_22 ) ;
V_19 = F_24 ( V_33 ) ;
V_48 = F_24 ( V_49 ) ;
F_25 ( & V_22 ) ;
F_39 ( V_47 ,
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
V_18 -> V_40 -> V_53 ,
( V_48 & V_54 ) ? L_10 : L_11 ) ;
return 0 ;
}
static T_3
F_40 ( struct V_55 * V_56 , struct V_57 * V_58 ,
struct V_59 * V_60 ,
char * V_61 , T_4 V_62 , T_5 V_63 )
{
int V_64 ;
V_62 += V_65 ;
F_23 ( & V_22 ) ;
for ( V_64 = 0 ; V_63 ; V_63 -- , V_62 ++ , V_64 ++ ) {
if ( V_62 < 128 )
* V_61 ++ = F_24 ( V_62 ) ;
else if ( V_66 )
* V_61 ++ = F_11 ( V_62 ) ;
else
break;
}
F_25 ( & V_22 ) ;
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
V_62 += V_65 ;
F_23 ( & V_22 ) ;
for ( V_64 = 0 ; V_63 ; V_63 -- , V_62 ++ , V_64 ++ ) {
if ( V_62 == V_18 -> V_29
|| V_62 == V_18 -> V_31
|| V_62 == V_18 -> V_67 )
V_61 ++ ;
else if ( V_62 < 128 )
F_30 ( * V_61 ++ , V_62 ) ;
else if ( V_66 )
F_15 ( * V_61 ++ , V_62 ) ;
else
break;
}
F_25 ( & V_22 ) ;
return V_64 ;
}
static T_6 F_43 ( int V_20 , void * V_68 )
{
T_1 V_69 ;
T_1 V_19 ;
F_44 ( & V_22 ) ;
V_69 = F_24 ( V_39 ) ;
V_19 = F_24 ( V_33 ) ;
if ( F_2 () )
V_69 = ( unsigned long ) V_20 & 0xF0 ;
if ( ! V_17 . V_70 )
V_69 &= ( V_19 & V_3 ) | V_2 ;
else
V_69 &= ( V_17 . V_70 & V_3 ) | V_2 ;
if ( V_69 & V_37 ) {
V_17 . V_70 &= ~ V_37 ;
V_19 &= ~ V_37 ;
F_30 ( V_19 , V_33 ) ;
F_3 ( V_37 ) ;
F_24 ( V_39 ) ;
}
F_45 ( & V_22 ) ;
if ( F_1 ( V_69 ) ) {
F_28 ( V_68 , 1 , V_69 ) ;
return V_71 ;
} else
return V_72 ;
}
static int T_7
F_46 ( struct V_12 * V_13 , struct V_73 * V_74 , int V_75 )
{
struct V_76 * V_77 = F_47 ( V_13 ) ;
int V_64 = 0 ;
unsigned char V_19 ;
unsigned V_78 ;
T_8 V_44 = 0 ;
if ( V_17 . V_13 )
return - V_79 ;
if ( ! V_74 )
return - V_80 ;
if ( V_81 )
V_74 = F_48 ( V_74 -> V_82 , F_49 ( V_74 ) ,
V_83 ) ;
else
V_74 = F_50 ( V_74 -> V_82 , F_49 ( V_74 ) ,
V_83 ) ;
if ( ! V_74 ) {
F_51 ( V_13 , L_12 ) ;
return - V_79 ;
}
V_17 . V_20 = V_75 ;
V_17 . V_84 = V_74 ;
#if F_52 ( V_85 )
V_78 = 64 ;
#elif F_52 ( V_86 ) || F_52 ( V_87 ) || F_52 ( V_88 ) \
|| F_52 ( V_89 ) || F_52 ( V_90 ) \
|| F_52 ( V_91 ) || F_52 ( V_92 )
V_78 = 128 ;
#else
#warning Assuming 128 bytes of RTC+NVRAM address space, not 64 bytes.
V_78 = 128 ;
#endif
if ( V_66 && V_74 -> V_93 > ( V_74 -> V_82 + 1 ) )
V_78 = 256 ;
if ( V_77 ) {
if ( V_77 -> V_44 )
V_44 = V_77 -> V_44 ;
if ( V_77 -> V_78 )
V_78 = V_77 -> V_78 ;
if ( V_77 -> V_94 && V_77 -> V_94 < 128 )
V_17 . V_29 = V_77 -> V_94 ;
if ( V_77 -> V_95 && V_77 -> V_95 < 128 )
V_17 . V_31 = V_77 -> V_95 ;
if ( V_77 -> V_96 && V_77 -> V_96 < 128 )
V_17 . V_67 = V_77 -> V_96 ;
if ( V_77 -> V_97 && V_77 -> V_98 ) {
V_17 . V_97 = V_77 -> V_97 ;
V_17 . V_98 = V_77 -> V_98 ;
}
}
V_17 . V_13 = V_13 ;
F_53 ( V_13 , & V_17 ) ;
V_17 . V_40 = F_54 ( V_83 , V_13 ,
& V_99 , V_100 ) ;
if ( F_55 ( V_17 . V_40 ) ) {
V_64 = F_56 ( V_17 . V_40 ) ;
goto V_101;
}
F_57 ( V_74 , F_58 ( & V_17 . V_40 -> V_13 ) ) ;
F_23 ( & V_22 ) ;
if ( ! ( V_44 & V_102 ) ) {
V_17 . V_40 -> V_53 = 1024 ;
F_6 ( V_17 . V_40 -> V_53 ) ;
F_30 ( V_103 | 0x06 , V_104 ) ;
}
if ( F_22 ( V_75 ) )
F_31 ( & V_17 , V_50 | V_37 | V_51 ) ;
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_22 ) ;
if ( F_22 ( V_75 ) && ! ( V_19 & V_105 ) ) {
F_59 ( V_13 , L_13 ) ;
V_64 = - V_106 ;
goto V_107;
}
F_8 () ;
if ( F_22 ( V_75 ) ) {
T_2 V_108 ;
if ( F_2 () ) {
V_108 = V_109 ;
V_64 = F_9 ( F_43 ) ;
if ( V_64 ) {
F_3 ( V_3 ) ;
F_59 ( V_13 , L_14
L_15 ) ;
goto V_107;
}
} else
V_108 = F_43 ;
V_64 = F_60 ( V_75 , V_108 ,
V_110 , F_58 ( & V_17 . V_40 -> V_13 ) ,
V_17 . V_40 ) ;
if ( V_64 < 0 ) {
F_51 ( V_13 , L_16 , V_75 ) ;
goto V_107;
}
}
V_111 . V_112 = V_78 - V_65 ;
V_64 = F_61 ( & V_13 -> V_58 , & V_111 ) ;
if ( V_64 < 0 ) {
F_51 ( V_13 , L_17 , V_64 ) ;
goto V_113;
}
F_62 ( V_13 , L_18 ,
! F_22 ( V_75 ) ? L_19 :
V_17 . V_31 ? L_20 :
V_17 . V_29 ? L_21 :
L_22 ,
V_17 . V_67 ? L_23 : L_24 ,
V_111 . V_112 ,
F_2 () ? L_25 : L_24 ) ;
return 0 ;
V_113:
if ( F_22 ( V_75 ) )
F_63 ( V_75 , V_17 . V_40 ) ;
V_107:
V_17 . V_13 = NULL ;
F_64 ( V_17 . V_40 ) ;
V_101:
if ( V_81 )
F_65 ( V_74 -> V_82 , F_49 ( V_74 ) ) ;
else
F_66 ( V_74 -> V_82 , F_49 ( V_74 ) ) ;
return V_64 ;
}
static void F_67 ( int V_75 )
{
F_23 ( & V_22 ) ;
if ( F_22 ( V_75 ) )
F_31 ( & V_17 , V_3 ) ;
F_25 ( & V_22 ) ;
}
static void F_68 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
struct V_73 * V_74 ;
F_67 ( V_18 -> V_20 ) ;
F_69 ( & V_13 -> V_58 , & V_111 ) ;
if ( F_22 ( V_18 -> V_20 ) ) {
F_63 ( V_18 -> V_20 , V_18 -> V_40 ) ;
F_10 ( F_43 ) ;
}
F_64 ( V_18 -> V_40 ) ;
V_18 -> V_40 = NULL ;
V_74 = V_18 -> V_84 ;
if ( V_81 )
F_65 ( V_74 -> V_82 , F_49 ( V_74 ) ) ;
else
F_66 ( V_74 -> V_82 , F_49 ( V_74 ) ) ;
V_18 -> V_84 = NULL ;
V_18 -> V_13 = NULL ;
}
static int F_70 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
struct V_14 V_114 ;
T_9 V_115 ;
int V_64 = 0 ;
unsigned char V_19 ;
if ( ! V_18 -> V_43 )
return - V_45 ;
F_23 ( & V_22 ) ;
V_19 = F_24 ( V_33 ) ;
F_25 ( & V_22 ) ;
if ( V_19 & V_37 )
return - V_79 ;
F_16 ( V_13 , & V_114 ) ;
V_115 = F_34 ( & V_114 ) ;
if ( V_18 -> V_43 == V_115 + 1 ) {
struct V_16 V_116 ;
F_71 ( V_115 - 1 , & V_116 . time ) ;
V_116 . V_36 = 0 ;
V_64 = F_32 ( V_13 , & V_116 ) ;
} else if ( V_18 -> V_43 > V_115 + 1 ) {
V_64 = - V_79 ;
}
return V_64 ;
}
static int F_72 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_117 ;
F_23 ( & V_22 ) ;
V_18 -> V_70 = V_117 = F_24 ( V_33 ) ;
if ( V_117 & ( V_50 | V_37 | V_51 ) ) {
unsigned char V_4 ;
if ( F_73 ( V_13 ) )
V_4 = V_3 & ~ V_37 ;
else
V_4 = V_3 ;
V_117 &= ~ V_4 ;
F_30 ( V_117 , V_33 ) ;
F_3 ( V_4 ) ;
F_27 ( V_18 , V_117 ) ;
}
F_25 ( & V_22 ) ;
if ( V_117 & V_37 ) {
V_18 -> V_118 = 1 ;
if ( V_18 -> V_97 )
V_18 -> V_97 ( V_13 ) ;
else
F_74 ( V_18 -> V_20 ) ;
}
F_20 ( V_13 , & V_18 -> V_119 ) ;
F_51 ( V_13 , L_26 ,
( V_117 & V_37 ) ? L_27 : L_24 ,
V_117 ) ;
return 0 ;
}
static inline int F_75 ( struct V_12 * V_13 )
{
if ( ! F_76 ( V_120 ) )
return - V_121 ;
return F_72 ( V_13 ) ;
}
static void F_77 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
struct V_16 V_122 ;
T_9 V_123 ;
T_9 V_124 ;
F_20 ( V_13 , & V_122 ) ;
V_123 = F_34 ( & V_122 . time ) ;
V_124 = F_34 ( & V_18 -> V_119 . time ) ;
if ( V_123 != V_124 ||
V_18 -> V_119 . V_36 != V_122 . V_36 ) {
F_32 ( V_13 , & V_18 -> V_119 ) ;
}
}
static int T_10 F_78 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_117 ;
if ( V_18 -> V_118 ) {
if ( V_18 -> V_98 )
V_18 -> V_98 ( V_13 ) ;
else
F_79 ( V_18 -> V_20 ) ;
V_18 -> V_118 = 0 ;
}
F_77 ( V_13 ) ;
F_23 ( & V_22 ) ;
V_117 = V_18 -> V_70 ;
V_18 -> V_70 = 0 ;
if ( V_117 & V_3 ) {
unsigned char V_4 ;
if ( F_73 ( V_13 ) )
F_8 () ;
do {
F_30 ( V_117 , V_33 ) ;
F_4 ( V_117 & V_3 ) ;
V_4 = F_24 ( V_39 ) ;
V_4 &= ( V_117 & V_3 ) | V_2 ;
if ( ! F_2 () || ! F_1 ( V_4 ) )
break;
F_28 ( V_18 -> V_40 , 1 , V_4 ) ;
V_117 &= ~ V_37 ;
F_3 ( V_37 ) ;
} while ( V_4 & V_37 );
if ( V_117 & V_37 )
F_80 ( V_13 , & V_117 ) ;
}
F_25 ( & V_22 ) ;
F_51 ( V_13 , L_28 , V_117 ) ;
return 0 ;
}
static T_8 F_81 ( void * V_125 )
{
struct V_12 * V_13 = V_125 ;
struct V_17 * V_18 = F_21 ( V_13 ) ;
unsigned char V_19 = 0 ;
unsigned char V_1 ;
unsigned long V_44 ;
F_36 ( & V_22 , V_44 ) ;
if ( V_17 . V_70 )
V_19 = F_24 ( V_33 ) ;
if ( V_19 & V_37 ) {
V_17 . V_70 &= ~ V_37 ;
F_30 ( V_19 , V_33 ) ;
V_1 = F_24 ( V_39 ) ;
F_28 ( V_18 -> V_40 , 1 , V_1 ) ;
}
F_37 ( & V_22 , V_44 ) ;
F_82 ( V_13 , 0 ) ;
F_83 ( V_126 ) ;
F_84 ( V_126 , 0 ) ;
return V_127 ;
}
static inline void F_85 ( struct V_12 * V_13 )
{
F_86 ( V_126 , F_81 , V_13 ) ;
F_83 ( V_126 ) ;
F_84 ( V_126 , 0 ) ;
}
static void F_87 ( struct V_12 * V_13 )
{
F_83 ( V_126 ) ;
F_88 ( V_126 , 0 ) ;
}
static void F_89 ( struct V_12 * V_13 )
{
F_84 ( V_126 , 0 ) ;
}
static void F_90 ( struct V_12 * V_13 )
{
if ( V_128 )
return;
F_85 ( V_13 ) ;
V_129 . V_97 = F_87 ;
V_129 . V_98 = F_89 ;
if ( V_130 . V_131 && ! V_130 . V_132 ) {
F_51 ( V_13 , L_29 ,
V_130 . V_131 ) ;
V_130 . V_131 = 0 ;
}
V_129 . V_94 = V_130 . V_132 ;
V_129 . V_95 = V_130 . V_131 ;
V_129 . V_96 = V_130 . V_67 ;
if ( V_130 . V_44 & V_133 )
F_62 ( V_13 , L_30 ) ;
V_13 -> V_134 = & V_129 ;
F_91 ( V_13 , 1 ) ;
}
static void F_80 ( struct V_12 * V_13 ,
unsigned char * V_19 )
{
struct V_17 * V_18 = F_21 ( V_13 ) ;
T_11 V_135 ;
T_12 V_136 ;
if ( V_130 . V_44 & V_137 )
return;
V_136 = F_92 ( V_126 , & V_135 ) ;
if ( F_93 ( V_136 ) ) {
F_94 ( V_13 , L_31 ) ;
} else if ( V_135 & V_138 ) {
unsigned char V_4 ;
* V_19 &= ~ V_37 ;
F_30 ( * V_19 , V_33 ) ;
V_4 = F_24 ( V_39 ) ;
F_28 ( V_18 -> V_40 , 1 , V_4 ) ;
}
}
static void F_90 ( struct V_12 * V_13 )
{
}
static void F_80 ( struct V_12 * V_13 ,
unsigned char * V_19 )
{
}
static int F_95 ( struct V_139 * V_140 , const struct V_141 * V_142 )
{
F_90 ( & V_140 -> V_13 ) ;
if ( F_96 ( V_140 , 0 ) == 0x70 && ! F_97 ( V_140 , 0 ) )
return F_46 ( & V_140 -> V_13 ,
F_98 ( V_140 , V_143 , 0 ) , 8 ) ;
else
return F_46 ( & V_140 -> V_13 ,
F_98 ( V_140 , V_143 , 0 ) ,
F_99 ( V_140 , 0 ) ) ;
}
static void F_100 ( struct V_139 * V_140 )
{
F_68 ( & V_140 -> V_13 ) ;
}
static void F_101 ( struct V_139 * V_140 )
{
struct V_12 * V_13 = & V_140 -> V_13 ;
struct V_17 * V_18 = F_21 ( V_13 ) ;
if ( V_144 == V_145 ) {
int V_64 = F_75 ( V_13 ) ;
if ( F_70 ( V_13 ) < 0 && ! V_64 )
return;
}
F_67 ( V_18 -> V_20 ) ;
}
static T_13 void F_102 ( struct V_146 * V_147 )
{
struct V_148 * V_149 = V_147 -> V_13 . V_150 ;
struct V_14 time ;
int V_151 ;
const T_14 * V_11 ;
if ( ! V_149 )
return;
V_11 = F_103 ( V_149 , L_32 , NULL ) ;
if ( V_11 )
F_30 ( F_104 ( V_11 ) , V_33 ) ;
V_11 = F_103 ( V_149 , L_33 , NULL ) ;
if ( V_11 )
F_30 ( F_104 ( V_11 ) , V_104 ) ;
F_16 ( & V_147 -> V_13 , & time ) ;
V_151 = F_105 ( & time ) ;
if ( V_151 ) {
struct V_14 V_152 = {
. V_153 = 1 ,
. V_30 = 1 ,
} ;
F_18 ( & V_147 -> V_13 , & V_152 ) ;
}
}
static inline void F_102 ( struct V_146 * V_147 ) {}
static int T_13 F_106 ( struct V_146 * V_147 )
{
struct V_73 * V_73 ;
int V_20 ;
F_102 ( V_147 ) ;
F_90 ( & V_147 -> V_13 ) ;
if ( V_81 )
V_73 = F_107 ( V_147 , V_143 , 0 ) ;
else
V_73 = F_107 ( V_147 , V_154 , 0 ) ;
V_20 = F_108 ( V_147 , 0 ) ;
if ( V_20 < 0 )
V_20 = - 1 ;
return F_46 ( & V_147 -> V_13 , V_73 , V_20 ) ;
}
static int F_109 ( struct V_146 * V_147 )
{
F_68 ( & V_147 -> V_13 ) ;
return 0 ;
}
static void F_110 ( struct V_146 * V_147 )
{
struct V_12 * V_13 = & V_147 -> V_13 ;
struct V_17 * V_18 = F_21 ( V_13 ) ;
if ( V_144 == V_145 ) {
int V_64 = F_75 ( V_13 ) ;
if ( F_70 ( V_13 ) < 0 && ! V_64 )
return;
}
F_67 ( V_18 -> V_20 ) ;
}
static int T_13 F_111 ( void )
{
int V_64 = 0 ;
#ifdef F_112
V_64 = F_113 ( & V_155 ) ;
if ( V_64 == 0 )
V_156 = true ;
#endif
if ( ! V_17 . V_13 ) {
V_64 = F_114 ( & V_157 ,
F_106 ) ;
if ( V_64 == 0 )
V_158 = true ;
}
if ( V_64 == 0 )
return 0 ;
#ifdef F_112
if ( V_156 )
F_115 ( & V_155 ) ;
#endif
return V_64 ;
}
static void T_15 F_116 ( void )
{
#ifdef F_112
if ( V_156 )
F_115 ( & V_155 ) ;
#endif
if ( V_158 )
F_117 ( & V_157 ) ;
}
