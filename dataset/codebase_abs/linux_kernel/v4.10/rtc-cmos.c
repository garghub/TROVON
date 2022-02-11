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
if ( ! F_17 () )
return - V_16 ;
F_18 ( V_15 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
return F_20 ( V_15 ) ;
}
static int F_21 ( struct V_12 * V_13 , struct V_17 * V_15 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
unsigned char V_20 ;
if ( ! F_23 ( V_19 -> V_21 ) )
return - V_16 ;
F_24 ( & V_22 ) ;
V_15 -> time . V_23 = F_25 ( V_24 ) ;
V_15 -> time . V_25 = F_25 ( V_26 ) ;
V_15 -> time . V_27 = F_25 ( V_28 ) ;
if ( V_19 -> V_29 ) {
V_15 -> time . V_30 = F_25 ( V_19 -> V_29 ) & 0x3f ;
if ( ! V_15 -> time . V_30 )
V_15 -> time . V_30 = - 1 ;
if ( V_19 -> V_31 ) {
V_15 -> time . V_32 = F_25 ( V_19 -> V_31 ) ;
if ( ! V_15 -> time . V_32 )
V_15 -> time . V_32 = - 1 ;
}
}
V_20 = F_25 ( V_33 ) ;
F_26 ( & V_22 ) ;
if ( ! ( V_20 & V_34 ) || V_35 ) {
if ( ( ( unsigned ) V_15 -> time . V_23 ) < 0x60 )
V_15 -> time . V_23 = F_27 ( V_15 -> time . V_23 ) ;
else
V_15 -> time . V_23 = - 1 ;
if ( ( ( unsigned ) V_15 -> time . V_25 ) < 0x60 )
V_15 -> time . V_25 = F_27 ( V_15 -> time . V_25 ) ;
else
V_15 -> time . V_25 = - 1 ;
if ( ( ( unsigned ) V_15 -> time . V_27 ) < 0x24 )
V_15 -> time . V_27 = F_27 ( V_15 -> time . V_27 ) ;
else
V_15 -> time . V_27 = - 1 ;
if ( V_19 -> V_29 ) {
if ( ( ( unsigned ) V_15 -> time . V_30 ) <= 0x31 )
V_15 -> time . V_30 = F_27 ( V_15 -> time . V_30 ) ;
else
V_15 -> time . V_30 = - 1 ;
if ( V_19 -> V_31 ) {
if ( ( ( unsigned ) V_15 -> time . V_32 ) <= 0x12 )
V_15 -> time . V_32 = F_27 ( V_15 -> time . V_32 ) - 1 ;
else
V_15 -> time . V_32 = - 1 ;
}
}
}
V_15 -> V_36 = ! ! ( V_20 & V_37 ) ;
V_15 -> V_38 = 0 ;
return 0 ;
}
static void F_28 ( struct V_18 * V_19 , unsigned char V_20 )
{
unsigned char V_1 ;
V_1 = F_25 ( V_39 ) ;
if ( F_2 () )
return;
V_1 &= ( V_20 & V_3 ) | V_2 ;
if ( F_1 ( V_1 ) )
F_29 ( V_19 -> V_40 , 1 , V_1 ) ;
}
static void F_30 ( struct V_18 * V_19 , unsigned char V_4 )
{
unsigned char V_20 ;
V_20 = F_25 ( V_33 ) ;
F_28 ( V_19 , V_20 ) ;
V_20 |= V_4 ;
F_31 ( V_20 , V_33 ) ;
F_4 ( V_4 ) ;
F_28 ( V_19 , V_20 ) ;
}
static void F_32 ( struct V_18 * V_19 , unsigned char V_4 )
{
unsigned char V_20 ;
V_20 = F_25 ( V_33 ) ;
V_20 &= ~ V_4 ;
F_31 ( V_20 , V_33 ) ;
F_3 ( V_4 ) ;
F_28 ( V_19 , V_20 ) ;
}
static int F_33 ( struct V_12 * V_13 , struct V_17 * V_15 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
struct V_14 V_41 ;
F_16 ( V_13 , & V_41 ) ;
if ( ! V_19 -> V_29 ) {
T_3 V_42 ;
T_3 V_43 ;
V_42 = F_34 ( & V_41 ) ;
V_42 += 24 * 60 * 60 - 1 ;
V_43 = F_34 ( & V_15 -> time ) ;
if ( V_43 > V_42 ) {
F_35 ( V_13 ,
L_1 ) ;
return - V_44 ;
}
} else if ( ! V_19 -> V_31 ) {
struct V_14 V_45 = V_41 ;
T_3 V_42 ;
T_3 V_43 ;
int V_46 ;
if ( V_45 . V_32 == 11 ) {
V_45 . V_32 = 0 ;
V_45 . V_47 += 1 ;
} else {
V_45 . V_32 += 1 ;
}
V_46 = F_36 ( V_45 . V_32 , V_45 . V_47 ) ;
if ( V_45 . V_30 > V_46 )
V_45 . V_30 = V_46 ;
V_42 = F_34 ( & V_45 ) ;
V_42 -= 1 ;
V_43 = F_34 ( & V_15 -> time ) ;
if ( V_43 > V_42 ) {
F_35 ( V_13 ,
L_2 ) ;
return - V_44 ;
}
} else {
struct V_14 V_45 = V_41 ;
T_3 V_42 ;
T_3 V_43 ;
int V_46 ;
V_45 . V_47 += 1 ;
V_46 = F_36 ( V_45 . V_32 , V_45 . V_47 ) ;
if ( V_45 . V_30 > V_46 )
V_45 . V_30 = V_46 ;
V_42 = F_34 ( & V_45 ) ;
V_42 -= 1 ;
V_43 = F_34 ( & V_15 -> time ) ;
if ( V_43 > V_42 ) {
F_35 ( V_13 ,
L_3 ) ;
return - V_44 ;
}
}
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , struct V_17 * V_15 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
unsigned char V_48 , V_49 , V_5 , V_6 , V_7 , V_20 ;
int V_50 ;
if ( ! F_23 ( V_19 -> V_21 ) )
return - V_16 ;
V_50 = F_33 ( V_13 , V_15 ) ;
if ( V_50 < 0 )
return V_50 ;
V_48 = V_15 -> time . V_32 + 1 ;
V_49 = V_15 -> time . V_30 ;
V_5 = V_15 -> time . V_27 ;
V_6 = V_15 -> time . V_25 ;
V_7 = V_15 -> time . V_23 ;
V_20 = F_25 ( V_33 ) ;
if ( ! ( V_20 & V_34 ) || V_35 ) {
V_48 = ( V_48 <= 12 ) ? F_38 ( V_48 ) : 0xff ;
V_49 = ( V_49 >= 1 && V_49 <= 31 ) ? F_38 ( V_49 ) : 0xff ;
V_5 = ( V_5 < 24 ) ? F_38 ( V_5 ) : 0xff ;
V_6 = ( V_6 < 60 ) ? F_38 ( V_6 ) : 0xff ;
V_7 = ( V_7 < 60 ) ? F_38 ( V_7 ) : 0xff ;
}
F_24 ( & V_22 ) ;
F_32 ( V_19 , V_37 ) ;
F_31 ( V_5 , V_28 ) ;
F_31 ( V_6 , V_26 ) ;
F_31 ( V_7 , V_24 ) ;
if ( V_19 -> V_29 ) {
F_31 ( V_49 , V_19 -> V_29 ) ;
if ( V_19 -> V_31 )
F_31 ( V_48 , V_19 -> V_31 ) ;
}
F_5 ( V_15 -> time . V_27 , V_15 -> time . V_25 , V_15 -> time . V_23 ) ;
if ( V_15 -> V_36 )
F_30 ( V_19 , V_37 ) ;
F_26 ( & V_22 ) ;
V_19 -> V_51 = F_34 ( & V_15 -> time ) ;
return 0 ;
}
static int F_39 ( struct V_12 * V_13 , unsigned int V_36 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
unsigned long V_52 ;
if ( ! F_23 ( V_19 -> V_21 ) )
return - V_44 ;
F_40 ( & V_22 , V_52 ) ;
if ( V_36 )
F_30 ( V_19 , V_37 ) ;
else
F_32 ( V_19 , V_37 ) ;
F_41 ( & V_22 , V_52 ) ;
return 0 ;
}
static int F_42 ( struct V_12 * V_13 , struct V_53 * V_54 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
unsigned char V_20 , V_55 ;
F_24 ( & V_22 ) ;
V_20 = F_25 ( V_33 ) ;
V_55 = F_25 ( V_56 ) ;
F_26 ( & V_22 ) ;
F_43 ( V_54 ,
L_4
L_5
L_6
L_7
L_8
L_9
L_10 ,
( V_20 & V_57 ) ? L_11 : L_12 ,
( V_20 & V_58 ) ? L_11 : L_12 ,
F_2 () ? L_11 : L_12 ,
( V_20 & V_34 ) ? L_12 : L_11 ,
( V_20 & V_59 ) ? L_11 : L_12 ,
V_19 -> V_40 -> V_60 ,
( V_55 & V_61 ) ? L_13 : L_14 ) ;
return 0 ;
}
static T_4
F_44 ( struct V_62 * V_63 , struct V_64 * V_65 ,
struct V_66 * V_67 ,
char * V_68 , T_5 V_69 , T_6 V_70 )
{
int V_71 ;
V_69 += V_72 ;
F_24 ( & V_22 ) ;
for ( V_71 = 0 ; V_70 ; V_70 -- , V_69 ++ , V_71 ++ ) {
if ( V_69 < 128 )
* V_68 ++ = F_25 ( V_69 ) ;
else if ( V_73 )
* V_68 ++ = F_11 ( V_69 ) ;
else
break;
}
F_26 ( & V_22 ) ;
return V_71 ;
}
static T_4
F_45 ( struct V_62 * V_63 , struct V_64 * V_65 ,
struct V_66 * V_67 ,
char * V_68 , T_5 V_69 , T_6 V_70 )
{
struct V_18 * V_19 ;
int V_71 ;
V_19 = F_22 ( F_46 ( V_65 , struct V_12 , V_65 ) ) ;
V_69 += V_72 ;
F_24 ( & V_22 ) ;
for ( V_71 = 0 ; V_70 ; V_70 -- , V_69 ++ , V_71 ++ ) {
if ( V_69 == V_19 -> V_29
|| V_69 == V_19 -> V_31
|| V_69 == V_19 -> V_74 )
V_68 ++ ;
else if ( V_69 < 128 )
F_31 ( * V_68 ++ , V_69 ) ;
else if ( V_73 )
F_15 ( * V_68 ++ , V_69 ) ;
else
break;
}
F_26 ( & V_22 ) ;
return V_71 ;
}
static T_7 F_47 ( int V_21 , void * V_75 )
{
T_1 V_76 ;
T_1 V_20 ;
F_48 ( & V_22 ) ;
V_76 = F_25 ( V_39 ) ;
V_20 = F_25 ( V_33 ) ;
if ( F_2 () )
V_76 = ( unsigned long ) V_21 & 0xF0 ;
if ( ! V_18 . V_77 )
V_76 &= ( V_20 & V_3 ) | V_2 ;
else
V_76 &= ( V_18 . V_77 & V_3 ) | V_2 ;
if ( V_76 & V_37 ) {
V_18 . V_77 &= ~ V_37 ;
V_20 &= ~ V_37 ;
F_31 ( V_20 , V_33 ) ;
F_3 ( V_37 ) ;
F_25 ( V_39 ) ;
}
F_49 ( & V_22 ) ;
if ( F_1 ( V_76 ) ) {
F_29 ( V_75 , 1 , V_76 ) ;
return V_78 ;
} else
return V_79 ;
}
static int T_8
F_50 ( struct V_12 * V_13 , struct V_80 * V_81 , int V_82 )
{
struct V_83 * V_84 = F_51 ( V_13 ) ;
int V_71 = 0 ;
unsigned char V_20 ;
unsigned V_85 ;
T_9 V_52 = 0 ;
if ( V_18 . V_13 )
return - V_86 ;
if ( ! V_81 )
return - V_87 ;
if ( V_88 )
V_81 = F_52 ( V_81 -> V_89 , F_53 ( V_81 ) ,
V_90 ) ;
else
V_81 = F_54 ( V_81 -> V_89 , F_53 ( V_81 ) ,
V_90 ) ;
if ( ! V_81 ) {
F_55 ( V_13 , L_15 ) ;
return - V_86 ;
}
V_18 . V_21 = V_82 ;
V_18 . V_91 = V_81 ;
#if F_56 ( V_92 )
V_85 = 64 ;
#elif F_56 ( V_93 ) || F_56 ( V_94 ) || F_56 ( V_95 ) \
|| F_56 ( V_96 ) || F_56 ( V_97 ) \
|| F_56 ( V_98 ) || F_56 ( V_99 )
V_85 = 128 ;
#else
#warning Assuming 128 bytes of RTC+NVRAM address space, not 64 bytes.
V_85 = 128 ;
#endif
if ( V_73 && V_81 -> V_100 > ( V_81 -> V_89 + 1 ) )
V_85 = 256 ;
if ( V_84 ) {
if ( V_84 -> V_52 )
V_52 = V_84 -> V_52 ;
if ( V_84 -> V_85 )
V_85 = V_84 -> V_85 ;
if ( V_84 -> V_101 && V_84 -> V_101 < 128 )
V_18 . V_29 = V_84 -> V_101 ;
if ( V_84 -> V_102 && V_84 -> V_102 < 128 )
V_18 . V_31 = V_84 -> V_102 ;
if ( V_84 -> V_103 && V_84 -> V_103 < 128 )
V_18 . V_74 = V_84 -> V_103 ;
if ( V_84 -> V_104 && V_84 -> V_105 ) {
V_18 . V_104 = V_84 -> V_104 ;
V_18 . V_105 = V_84 -> V_105 ;
}
}
V_18 . V_13 = V_13 ;
F_57 ( V_13 , & V_18 ) ;
V_18 . V_40 = F_58 ( V_90 , V_13 ,
& V_106 , V_107 ) ;
if ( F_59 ( V_18 . V_40 ) ) {
V_71 = F_60 ( V_18 . V_40 ) ;
goto V_108;
}
F_61 ( V_81 , F_62 ( & V_18 . V_40 -> V_13 ) ) ;
F_24 ( & V_22 ) ;
if ( ! ( V_52 & V_109 ) ) {
V_18 . V_40 -> V_60 = 1024 ;
F_6 ( V_18 . V_40 -> V_60 ) ;
F_31 ( V_110 | 0x06 , V_111 ) ;
}
if ( F_23 ( V_82 ) )
F_32 ( & V_18 , V_57 | V_37 | V_58 ) ;
V_20 = F_25 ( V_33 ) ;
F_26 ( & V_22 ) ;
if ( F_23 ( V_82 ) && ! ( V_20 & V_112 ) ) {
F_63 ( V_13 , L_16 ) ;
V_71 = - V_113 ;
goto V_114;
}
F_8 () ;
if ( F_23 ( V_82 ) ) {
T_2 V_115 ;
if ( F_2 () ) {
V_115 = V_116 ;
V_71 = F_9 ( F_47 ) ;
if ( V_71 ) {
F_3 ( V_3 ) ;
F_63 ( V_13 , L_17
L_18 ) ;
goto V_114;
}
} else
V_115 = F_47 ;
V_71 = F_64 ( V_82 , V_115 ,
V_117 , F_62 ( & V_18 . V_40 -> V_13 ) ,
V_18 . V_40 ) ;
if ( V_71 < 0 ) {
F_55 ( V_13 , L_19 , V_82 ) ;
goto V_114;
}
}
V_118 . V_119 = V_85 - V_72 ;
V_71 = F_65 ( & V_13 -> V_65 , & V_118 ) ;
if ( V_71 < 0 ) {
F_55 ( V_13 , L_20 , V_71 ) ;
goto V_120;
}
F_66 ( V_13 , L_21 ,
! F_23 ( V_82 ) ? L_22 :
V_18 . V_31 ? L_23 :
V_18 . V_29 ? L_24 :
L_25 ,
V_18 . V_74 ? L_26 : L_27 ,
V_118 . V_119 ,
F_2 () ? L_28 : L_27 ) ;
return 0 ;
V_120:
if ( F_23 ( V_82 ) )
F_67 ( V_82 , V_18 . V_40 ) ;
V_114:
V_18 . V_13 = NULL ;
F_68 ( V_18 . V_40 ) ;
V_108:
if ( V_88 )
F_69 ( V_81 -> V_89 , F_53 ( V_81 ) ) ;
else
F_70 ( V_81 -> V_89 , F_53 ( V_81 ) ) ;
return V_71 ;
}
static void F_71 ( int V_82 )
{
F_24 ( & V_22 ) ;
if ( F_23 ( V_82 ) )
F_32 ( & V_18 , V_3 ) ;
F_26 ( & V_22 ) ;
}
static void F_72 ( struct V_12 * V_13 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
struct V_80 * V_81 ;
F_71 ( V_19 -> V_21 ) ;
F_73 ( & V_13 -> V_65 , & V_118 ) ;
if ( F_23 ( V_19 -> V_21 ) ) {
F_67 ( V_19 -> V_21 , V_19 -> V_40 ) ;
F_10 ( F_47 ) ;
}
F_68 ( V_19 -> V_40 ) ;
V_19 -> V_40 = NULL ;
V_81 = V_19 -> V_91 ;
if ( V_88 )
F_69 ( V_81 -> V_89 , F_53 ( V_81 ) ) ;
else
F_70 ( V_81 -> V_89 , F_53 ( V_81 ) ) ;
V_19 -> V_91 = NULL ;
V_19 -> V_13 = NULL ;
}
static int F_74 ( struct V_12 * V_13 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
struct V_14 V_41 ;
T_3 V_121 ;
int V_71 = 0 ;
unsigned char V_20 ;
if ( ! V_19 -> V_51 )
return - V_44 ;
F_24 ( & V_22 ) ;
V_20 = F_25 ( V_33 ) ;
F_26 ( & V_22 ) ;
if ( V_20 & V_37 )
return - V_86 ;
F_16 ( V_13 , & V_41 ) ;
V_121 = F_34 ( & V_41 ) ;
if ( V_19 -> V_51 == V_121 + 1 ) {
struct V_17 V_122 ;
F_75 ( V_121 - 1 , & V_122 . time ) ;
V_122 . V_36 = 0 ;
V_71 = F_37 ( V_13 , & V_122 ) ;
} else if ( V_19 -> V_51 > V_121 + 1 ) {
V_71 = - V_86 ;
}
return V_71 ;
}
static int F_76 ( struct V_12 * V_13 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
unsigned char V_123 ;
F_24 ( & V_22 ) ;
V_19 -> V_77 = V_123 = F_25 ( V_33 ) ;
if ( V_123 & ( V_57 | V_37 | V_58 ) ) {
unsigned char V_4 ;
if ( F_77 ( V_13 ) )
V_4 = V_3 & ~ V_37 ;
else
V_4 = V_3 ;
V_123 &= ~ V_4 ;
F_31 ( V_123 , V_33 ) ;
F_3 ( V_4 ) ;
F_28 ( V_19 , V_123 ) ;
}
F_26 ( & V_22 ) ;
if ( V_123 & V_37 ) {
V_19 -> V_124 = 1 ;
if ( V_19 -> V_104 )
V_19 -> V_104 ( V_13 ) ;
else
F_78 ( V_19 -> V_21 ) ;
}
F_21 ( V_13 , & V_19 -> V_125 ) ;
F_55 ( V_13 , L_29 ,
( V_123 & V_37 ) ? L_30 : L_27 ,
V_123 ) ;
return 0 ;
}
static inline int F_79 ( struct V_12 * V_13 )
{
if ( ! F_80 ( V_126 ) )
return - V_127 ;
return F_76 ( V_13 ) ;
}
static void F_81 ( struct V_12 * V_13 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
struct V_17 V_128 ;
T_3 V_129 ;
T_3 V_130 ;
F_21 ( V_13 , & V_128 ) ;
V_129 = F_34 ( & V_128 . time ) ;
V_130 = F_34 ( & V_19 -> V_125 . time ) ;
if ( V_129 != V_130 ||
V_19 -> V_125 . V_36 != V_128 . V_36 ) {
F_37 ( V_13 , & V_19 -> V_125 ) ;
}
}
static int T_10 F_82 ( struct V_12 * V_13 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
unsigned char V_123 ;
if ( V_19 -> V_124 ) {
if ( V_19 -> V_105 )
V_19 -> V_105 ( V_13 ) ;
else
F_83 ( V_19 -> V_21 ) ;
V_19 -> V_124 = 0 ;
}
F_81 ( V_13 ) ;
F_24 ( & V_22 ) ;
V_123 = V_19 -> V_77 ;
V_19 -> V_77 = 0 ;
if ( V_123 & V_3 ) {
unsigned char V_4 ;
if ( F_77 ( V_13 ) )
F_8 () ;
do {
F_31 ( V_123 , V_33 ) ;
F_4 ( V_123 & V_3 ) ;
V_4 = F_25 ( V_39 ) ;
V_4 &= ( V_123 & V_3 ) | V_2 ;
if ( ! F_2 () || ! F_1 ( V_4 ) )
break;
F_29 ( V_19 -> V_40 , 1 , V_4 ) ;
V_123 &= ~ V_37 ;
F_3 ( V_37 ) ;
} while ( V_4 & V_37 );
if ( V_123 & V_37 )
F_84 ( V_13 , & V_123 ) ;
}
F_26 ( & V_22 ) ;
F_55 ( V_13 , L_31 , V_123 ) ;
return 0 ;
}
static T_9 F_85 ( void * V_131 )
{
struct V_12 * V_13 = V_131 ;
struct V_18 * V_19 = F_22 ( V_13 ) ;
unsigned char V_20 = 0 ;
unsigned char V_1 ;
unsigned long V_52 ;
F_40 ( & V_22 , V_52 ) ;
if ( V_18 . V_77 )
V_20 = F_25 ( V_33 ) ;
if ( V_20 & V_37 ) {
V_18 . V_77 &= ~ V_37 ;
F_31 ( V_20 , V_33 ) ;
V_1 = F_25 ( V_39 ) ;
F_29 ( V_19 -> V_40 , 1 , V_1 ) ;
}
F_41 ( & V_22 , V_52 ) ;
F_86 ( V_13 , 0 ) ;
F_87 ( V_132 ) ;
F_88 ( V_132 , 0 ) ;
return V_133 ;
}
static inline void F_89 ( struct V_12 * V_13 )
{
F_90 ( V_132 , F_85 , V_13 ) ;
F_87 ( V_132 ) ;
F_88 ( V_132 , 0 ) ;
}
static void F_91 ( struct V_12 * V_13 )
{
F_87 ( V_132 ) ;
F_92 ( V_132 , 0 ) ;
}
static void F_93 ( struct V_12 * V_13 )
{
F_88 ( V_132 , 0 ) ;
}
static void F_94 ( struct V_12 * V_13 )
{
if ( V_134 )
return;
F_89 ( V_13 ) ;
V_135 . V_104 = F_91 ;
V_135 . V_105 = F_93 ;
if ( V_136 . V_137 && ! V_136 . V_138 ) {
F_55 ( V_13 , L_32 ,
V_136 . V_137 ) ;
V_136 . V_137 = 0 ;
}
V_135 . V_101 = V_136 . V_138 ;
V_135 . V_102 = V_136 . V_137 ;
V_135 . V_103 = V_136 . V_74 ;
if ( V_136 . V_52 & V_139 )
F_66 ( V_13 , L_33 ) ;
V_13 -> V_140 = & V_135 ;
F_95 ( V_13 , 1 ) ;
}
static void F_84 ( struct V_12 * V_13 ,
unsigned char * V_20 )
{
struct V_18 * V_19 = F_22 ( V_13 ) ;
T_11 V_141 ;
T_12 V_142 ;
if ( V_136 . V_52 & V_143 )
return;
V_142 = F_96 ( V_132 , & V_141 ) ;
if ( F_97 ( V_142 ) ) {
F_35 ( V_13 , L_34 ) ;
} else if ( V_141 & V_144 ) {
unsigned char V_4 ;
* V_20 &= ~ V_37 ;
F_31 ( * V_20 , V_33 ) ;
V_4 = F_25 ( V_39 ) ;
F_29 ( V_19 -> V_40 , 1 , V_4 ) ;
}
}
static void F_94 ( struct V_12 * V_13 )
{
}
static void F_84 ( struct V_12 * V_13 ,
unsigned char * V_20 )
{
}
static int F_98 ( struct V_145 * V_146 , const struct V_147 * V_148 )
{
F_94 ( & V_146 -> V_13 ) ;
if ( F_99 ( V_146 , 0 ) == 0x70 && ! F_100 ( V_146 , 0 ) )
return F_50 ( & V_146 -> V_13 ,
F_101 ( V_146 , V_149 , 0 ) , 8 ) ;
else
return F_50 ( & V_146 -> V_13 ,
F_101 ( V_146 , V_149 , 0 ) ,
F_102 ( V_146 , 0 ) ) ;
}
static void F_103 ( struct V_145 * V_146 )
{
F_72 ( & V_146 -> V_13 ) ;
}
static void F_104 ( struct V_145 * V_146 )
{
struct V_12 * V_13 = & V_146 -> V_13 ;
struct V_18 * V_19 = F_22 ( V_13 ) ;
if ( V_150 == V_151 ) {
int V_71 = F_79 ( V_13 ) ;
if ( F_74 ( V_13 ) < 0 && ! V_71 )
return;
}
F_71 ( V_19 -> V_21 ) ;
}
static T_13 void F_105 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = V_153 -> V_13 . V_156 ;
struct V_14 time ;
int V_50 ;
const T_14 * V_11 ;
if ( ! V_155 )
return;
V_11 = F_106 ( V_155 , L_35 , NULL ) ;
if ( V_11 )
F_31 ( F_107 ( V_11 ) , V_33 ) ;
V_11 = F_106 ( V_155 , L_36 , NULL ) ;
if ( V_11 )
F_31 ( F_107 ( V_11 ) , V_111 ) ;
F_16 ( & V_153 -> V_13 , & time ) ;
V_50 = F_108 ( & time ) ;
if ( V_50 ) {
struct V_14 V_157 = {
. V_47 = 1 ,
. V_30 = 1 ,
} ;
F_19 ( & V_153 -> V_13 , & V_157 ) ;
}
}
static inline void F_105 ( struct V_152 * V_153 ) {}
static int T_13 F_109 ( struct V_152 * V_153 )
{
struct V_80 * V_80 ;
int V_21 ;
F_105 ( V_153 ) ;
F_94 ( & V_153 -> V_13 ) ;
if ( V_88 )
V_80 = F_110 ( V_153 , V_149 , 0 ) ;
else
V_80 = F_110 ( V_153 , V_158 , 0 ) ;
V_21 = F_111 ( V_153 , 0 ) ;
if ( V_21 < 0 )
V_21 = - 1 ;
return F_50 ( & V_153 -> V_13 , V_80 , V_21 ) ;
}
static int F_112 ( struct V_152 * V_153 )
{
F_72 ( & V_153 -> V_13 ) ;
return 0 ;
}
static void F_113 ( struct V_152 * V_153 )
{
struct V_12 * V_13 = & V_153 -> V_13 ;
struct V_18 * V_19 = F_22 ( V_13 ) ;
if ( V_150 == V_151 ) {
int V_71 = F_79 ( V_13 ) ;
if ( F_74 ( V_13 ) < 0 && ! V_71 )
return;
}
F_71 ( V_19 -> V_21 ) ;
}
static int T_13 F_114 ( void )
{
int V_71 = 0 ;
#ifdef F_115
V_71 = F_116 ( & V_159 ) ;
if ( V_71 == 0 )
V_160 = true ;
#endif
if ( ! V_18 . V_13 ) {
V_71 = F_117 ( & V_161 ,
F_109 ) ;
if ( V_71 == 0 )
V_162 = true ;
}
if ( V_71 == 0 )
return 0 ;
#ifdef F_115
if ( V_160 )
F_118 ( & V_159 ) ;
#endif
return V_71 ;
}
static void T_15 F_119 ( void )
{
#ifdef F_115
if ( V_160 )
F_118 ( & V_159 ) ;
#endif
if ( V_162 )
F_120 ( & V_161 ) ;
}
