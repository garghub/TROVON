static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_4 )
{
unsigned short V_5 ;
int V_6 ;
do {
V_5 = F_4 ( V_4 , V_7 ) ;
if ( V_5 & F_5 ( V_4 ) ) {
F_6 ( V_4 , V_7 , F_7 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_5 & F_8 ( V_4 ) ) )
return V_8 ;
V_6 = F_4 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_7 ) ;
F_6 ( V_4 , V_7 , F_9 ( V_4 ) ) ;
return V_6 ;
}
static void F_10 ( struct V_2 * V_4 , unsigned char V_6 )
{
unsigned short V_5 ;
do {
V_5 = F_4 ( V_4 , V_7 ) ;
} while ( ! ( V_5 & F_11 ( V_4 ) ) );
F_6 ( V_4 , V_10 , V_6 ) ;
F_6 ( V_4 , V_7 , F_12 ( V_4 ) & ~ F_13 ( V_4 ) ) ;
}
static void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
int V_12 = ( V_4 -> V_13 - V_14 ) >> 3 ;
F_15 ( V_15 [ V_12 ] . V_4 ,
V_15 [ V_12 ] . V_16 ,
V_17 ) ;
F_15 ( V_15 [ V_12 ] . V_4 ,
V_15 [ V_12 ] . V_18 ,
V_19 ) ;
F_16 ( V_12 ) |= V_15 [ V_12 ] . V_18 ;
}
static inline void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
if ( V_4 -> V_13 == 0xA4400000 ) {
F_17 ( F_18 ( V_20 ) & 0xffc0 , V_20 ) ;
F_17 ( F_18 ( V_21 ) & 0x0fff , V_21 ) ;
} else if ( V_4 -> V_13 == 0xA4410000 )
F_17 ( F_18 ( V_21 ) & 0xf003 , V_21 ) ;
}
static inline void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
unsigned short V_22 ;
if ( V_11 & V_23 ) {
if ( V_4 -> V_13 == 0xa4430000 ) {
V_22 = F_18 ( V_24 ) ;
F_17 ( ( V_22 & 0xfc03 ) , V_24 ) ;
} else if ( V_4 -> V_13 == 0xa4438000 ) {
V_22 = F_18 ( V_25 ) ;
F_17 ( ( V_22 & 0xfc03 ) , V_25 ) ;
}
} else {
if ( V_4 -> V_13 == 0xa4430000 ) {
V_22 = F_18 ( V_24 ) ;
F_17 ( ( V_22 & 0xffc3 ) , V_24 ) ;
} else if ( V_4 -> V_13 == 0xa4438000 ) {
V_22 = F_18 ( V_25 ) ;
F_17 ( ( V_22 & 0xffc3 ) , V_25 ) ;
}
}
}
static inline void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
unsigned short V_22 ;
V_22 = F_18 ( V_26 ) ;
F_17 ( V_22 & 0x0fcf , V_26 ) ;
if ( ! ( V_11 & V_23 ) ) {
V_22 = F_18 ( V_26 ) ;
F_17 ( ( V_22 & 0x0fcf ) | 0x1000 , V_26 ) ;
V_22 = F_19 ( V_27 ) ;
F_20 ( V_22 & 0xbf , V_27 ) ;
}
}
static inline void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
unsigned short V_22 ;
if ( V_4 -> V_13 == 0xffe00000 ) {
V_22 = F_18 ( V_28 ) ;
V_22 &= ~ 0x03cf ;
if ( ! ( V_11 & V_23 ) )
V_22 |= 0x0340 ;
F_17 ( V_22 , V_28 ) ;
}
}
static inline void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
if ( ! ( V_11 & V_23 ) )
F_17 ( 0x0080 , V_29 ) ;
}
static inline void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
if ( ! ( V_11 & V_23 ) )
F_17 ( 0x0080 , V_30 ) ;
}
static inline void F_14 ( struct V_2 * V_4 , unsigned int V_11 )
{
}
static int F_21 ( struct V_2 * V_4 )
{
return F_4 ( V_4 , V_31 ) & 0xff ;
}
static int F_22 ( struct V_2 * V_4 )
{
return V_32 - F_21 ( V_4 ) ;
}
static int F_23 ( struct V_2 * V_4 )
{
return F_4 ( V_4 , V_33 ) & 0xff ;
}
static int F_21 ( struct V_2 * V_4 )
{
if ( V_4 -> V_13 == 0xffe00000 ||
V_4 -> V_13 == 0xffe08000 )
return F_4 ( V_4 , V_31 ) & 0xff ;
else
return F_4 ( V_4 , V_34 ) >> 8 ;
}
static int F_22 ( struct V_2 * V_4 )
{
if ( V_4 -> V_13 == 0xffe00000 ||
V_4 -> V_13 == 0xffe08000 )
return V_32 - F_21 ( V_4 ) ;
else
return V_35 - F_21 ( V_4 ) ;
}
static int F_23 ( struct V_2 * V_4 )
{
if ( ( V_4 -> V_13 == 0xffe00000 ) ||
( V_4 -> V_13 == 0xffe08000 ) ) {
return F_4 ( V_4 , V_33 ) & 0xff ;
} else {
return F_4 ( V_4 , V_34 ) & V_36 ;
}
}
static int F_21 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_37 )
return F_4 ( V_4 , V_34 ) >> 8 ;
else
return F_4 ( V_4 , V_31 ) ;
}
static int F_22 ( struct V_2 * V_4 )
{
return V_4 -> V_38 - F_21 ( V_4 ) ;
}
static int F_23 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_37 )
return F_4 ( V_4 , V_34 ) & V_39 ;
else
return F_4 ( V_4 , V_33 ) ;
}
static int F_21 ( struct V_2 * V_4 )
{
return F_4 ( V_4 , V_34 ) >> 8 ;
}
static int F_22 ( struct V_2 * V_4 )
{
return V_32 - F_21 ( V_4 ) ;
}
static int F_23 ( struct V_2 * V_4 )
{
return F_4 ( V_4 , V_34 ) & V_39 ;
}
static int F_24 ( struct V_2 * V_4 )
{
return ! ( F_4 ( V_4 , V_7 ) & V_40 ) ;
}
static int F_25 ( struct V_2 * V_4 )
{
return ! F_24 ( V_4 ) ;
}
static int F_26 ( struct V_2 * V_4 )
{
return ( F_4 ( V_4 , V_7 ) & F_8 ( V_4 ) ) != 0 ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_41 * V_42 = & V_4 -> V_43 -> V_42 ;
unsigned int V_44 = F_28 ( V_4 ) ;
unsigned short V_5 ;
unsigned short V_45 ;
int V_46 ;
V_5 = F_4 ( V_4 , V_7 ) ;
if ( ! ( V_5 & F_11 ( V_4 ) ) ) {
V_45 = F_4 ( V_4 , V_47 ) ;
if ( F_29 ( V_42 ) )
V_45 &= ~ V_48 ;
else
V_45 |= V_48 ;
F_6 ( V_4 , V_47 , V_45 ) ;
return;
}
if ( V_4 -> type == V_49 )
V_46 = F_25 ( V_4 ) ;
else
V_46 = F_22 ( V_4 ) ;
do {
unsigned char V_6 ;
if ( V_4 -> V_50 ) {
V_6 = V_4 -> V_50 ;
V_4 -> V_50 = 0 ;
} else if ( ! F_29 ( V_42 ) && ! V_44 ) {
V_6 = V_42 -> V_51 [ V_42 -> V_52 ] ;
V_42 -> V_52 = ( V_42 -> V_52 + 1 ) & ( V_53 - 1 ) ;
} else {
break;
}
F_6 ( V_4 , V_10 , V_6 ) ;
V_4 -> V_54 . V_18 ++ ;
} while ( -- V_46 > 0 );
F_6 ( V_4 , V_7 , F_12 ( V_4 ) ) ;
if ( F_30 ( V_42 ) < V_55 )
F_31 ( V_4 ) ;
if ( F_29 ( V_42 ) ) {
F_32 ( V_4 ) ;
} else {
V_45 = F_4 ( V_4 , V_47 ) ;
if ( V_4 -> type != V_49 ) {
F_4 ( V_4 , V_7 ) ;
F_6 ( V_4 , V_7 , F_12 ( V_4 ) ) ;
}
V_45 |= V_48 ;
F_6 ( V_4 , V_47 , V_45 ) ;
}
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_56 * V_57 = V_4 -> V_43 -> V_4 . V_57 ;
int V_58 , V_46 , V_59 = 0 ;
unsigned short V_5 ;
unsigned char V_60 ;
V_5 = F_4 ( V_4 , V_7 ) ;
if ( ! ( V_5 & F_8 ( V_4 ) ) )
return;
while ( 1 ) {
if ( V_4 -> type == V_49 )
V_46 = F_26 ( V_4 ) ;
else
V_46 = F_23 ( V_4 ) ;
V_46 = F_34 ( V_57 , V_46 ) ;
if ( V_46 == 0 )
break;
if ( V_4 -> type == V_49 ) {
char V_6 = F_4 ( V_4 , V_9 ) ;
if ( F_35 ( V_4 , V_6 ) ||
V_1 -> V_61 )
V_46 = 0 ;
else
F_36 ( V_57 , V_6 , V_62 ) ;
} else {
for ( V_58 = 0 ; V_58 < V_46 ; V_58 ++ ) {
char V_6 = F_4 ( V_4 , V_9 ) ;
V_5 = F_4 ( V_4 , V_7 ) ;
#if F_37 ( V_63 )
if ( V_1 -> V_61 ) {
if ( ( V_6 == 0 ) &&
( V_5 & F_38 ( V_4 ) ) ) {
V_46 -- ; V_58 -- ;
continue;
}
F_39 ( V_4 -> V_64 , L_1 , V_6 ) ;
V_1 -> V_61 = 0 ;
if ( F_40 ( V_6 ) ) {
V_46 -- ; V_58 -- ;
continue;
}
}
#endif
if ( F_35 ( V_4 , V_6 ) ) {
V_46 -- ; V_58 -- ;
continue;
}
if ( V_5 & F_38 ( V_4 ) ) {
V_60 = V_65 ;
F_41 ( V_4 -> V_64 , L_2 ) ;
} else if ( V_5 & F_42 ( V_4 ) ) {
V_60 = V_66 ;
F_41 ( V_4 -> V_64 , L_3 ) ;
} else
V_60 = V_62 ;
F_36 ( V_57 , V_6 , V_60 ) ;
}
}
F_4 ( V_4 , V_7 ) ;
F_6 ( V_4 , V_7 , F_9 ( V_4 ) ) ;
V_59 += V_46 ;
V_4 -> V_54 . V_16 += V_46 ;
}
if ( V_59 ) {
F_43 ( V_57 ) ;
} else {
F_4 ( V_4 , V_7 ) ;
F_6 ( V_4 , V_7 , F_9 ( V_4 ) ) ;
}
}
static inline void F_44 ( struct V_1 * V_4 )
{
F_45 ( & V_4 -> V_67 , V_68 + V_69 ) ;
}
static void F_46 ( unsigned long V_22 )
{
struct V_1 * V_4 = (struct V_1 * ) V_22 ;
if ( V_4 -> V_70 )
V_4 -> V_70 ( & V_4 -> V_4 ) ;
if ( F_47 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_61 = 1 ;
F_44 ( V_4 ) ;
} else if ( V_4 -> V_61 == 1 ) {
V_4 -> V_61 = 2 ;
F_44 ( V_4 ) ;
} else
V_4 -> V_61 = 0 ;
if ( V_4 -> V_71 )
V_4 -> V_71 ( & V_4 -> V_4 ) ;
}
static int F_48 ( struct V_2 * V_4 )
{
int V_59 = 0 ;
unsigned short V_5 = F_4 ( V_4 , V_7 ) ;
struct V_56 * V_57 = V_4 -> V_43 -> V_4 . V_57 ;
if ( V_5 & F_49 ( V_4 ) ) {
if ( F_36 ( V_57 , 0 , V_72 ) )
V_59 ++ ;
F_41 ( V_4 -> V_64 , L_4 ) ;
}
if ( V_5 & F_38 ( V_4 ) ) {
if ( F_47 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_61 ) {
V_1 -> V_61 = 1 ;
F_44 ( V_1 ) ;
if ( F_50 ( V_4 ) )
return 0 ;
F_39 ( V_4 -> V_64 , L_5 ) ;
if ( F_36 ( V_57 , 0 , V_73 ) )
V_59 ++ ;
}
} else {
if ( F_36 ( V_57 , 0 , V_65 ) )
V_59 ++ ;
F_41 ( V_4 -> V_64 , L_2 ) ;
}
}
if ( V_5 & F_42 ( V_4 ) ) {
if ( F_36 ( V_57 , 0 , V_66 ) )
V_59 ++ ;
F_41 ( V_4 -> V_64 , L_6 ) ;
}
if ( V_59 )
F_43 ( V_57 ) ;
return V_59 ;
}
static int F_51 ( struct V_2 * V_4 )
{
struct V_56 * V_57 = V_4 -> V_43 -> V_4 . V_57 ;
int V_59 = 0 ;
if ( V_4 -> type != V_74 )
return 0 ;
if ( ( F_4 ( V_4 , V_75 ) & V_76 ) != 0 ) {
F_6 ( V_4 , V_75 , 0 ) ;
F_36 ( V_57 , 0 , V_72 ) ;
F_43 ( V_57 ) ;
F_41 ( V_4 -> V_64 , L_7 ) ;
V_59 ++ ;
}
return V_59 ;
}
static int F_52 ( struct V_2 * V_4 )
{
int V_59 = 0 ;
unsigned short V_5 = F_4 ( V_4 , V_7 ) ;
struct V_56 * V_57 = V_4 -> V_43 -> V_4 . V_57 ;
struct V_1 * V_77 = F_1 ( V_4 ) ;
if ( F_50 ( V_4 ) )
return 0 ;
if ( ! V_77 -> V_61 && V_5 & F_53 ( V_4 ) ) {
#if F_37 ( V_63 )
V_77 -> V_61 = 1 ;
#endif
if ( F_36 ( V_57 , 0 , V_73 ) )
V_59 ++ ;
F_39 ( V_4 -> V_64 , L_5 ) ;
}
if ( V_59 )
F_43 ( V_57 ) ;
V_59 += F_51 ( V_4 ) ;
return V_59 ;
}
static T_1 F_54 ( int V_78 , void * V_79 )
{
#ifdef F_55
struct V_2 * V_4 = V_79 ;
struct V_1 * V_77 = F_1 ( V_4 ) ;
if ( V_77 -> V_80 ) {
T_2 V_81 = F_4 ( V_4 , V_47 ) ;
T_2 V_82 = F_4 ( V_4 , V_7 ) ;
if ( V_4 -> type == V_37 || V_4 -> type == V_83 ) {
F_56 ( V_78 ) ;
V_81 |= 0x4000 ;
} else {
V_81 &= ~ V_84 ;
}
F_6 ( V_4 , V_47 , V_81 ) ;
F_6 ( V_4 , V_7 , V_82 & ~ ( 1 | F_8 ( V_4 ) ) ) ;
F_39 ( V_4 -> V_64 , L_8 ,
V_68 , V_77 -> V_85 ) ;
F_45 ( & V_77 -> V_86 , V_68 + V_77 -> V_85 ) ;
return V_87 ;
}
#endif
F_33 ( V_79 ) ;
return V_87 ;
}
static T_1 F_57 ( int V_78 , void * V_79 )
{
struct V_2 * V_4 = V_79 ;
unsigned long V_88 ;
F_58 ( & V_4 -> V_89 , V_88 ) ;
F_27 ( V_4 ) ;
F_59 ( & V_4 -> V_89 , V_88 ) ;
return V_87 ;
}
static T_1 F_60 ( int V_78 , void * V_79 )
{
struct V_2 * V_4 = V_79 ;
if ( V_4 -> type == V_49 ) {
if ( F_48 ( V_4 ) ) {
F_4 ( V_4 , V_7 ) ;
F_6 ( V_4 , V_7 , F_9 ( V_4 ) ) ;
}
} else {
F_51 ( V_4 ) ;
F_54 ( V_78 , V_79 ) ;
}
F_6 ( V_4 , V_7 , F_7 ( V_4 ) ) ;
F_57 ( V_78 , V_79 ) ;
return V_87 ;
}
static T_1 F_61 ( int V_78 , void * V_79 )
{
struct V_2 * V_4 = V_79 ;
F_52 ( V_4 ) ;
F_6 ( V_4 , V_7 , F_62 ( V_4 ) ) ;
return V_87 ;
}
static inline unsigned long F_63 ( struct V_2 * V_4 )
{
return V_84 | ( F_1 ( V_4 ) -> V_90 -> V_91 & V_92 ) ;
}
static T_1 F_64 ( int V_78 , void * V_79 )
{
unsigned short V_93 , V_94 , V_95 ;
struct V_2 * V_4 = V_79 ;
struct V_1 * V_77 = F_1 ( V_4 ) ;
T_1 V_96 = V_97 ;
V_93 = F_4 ( V_4 , V_7 ) ;
V_94 = F_4 ( V_4 , V_47 ) ;
V_95 = V_94 & F_63 ( V_4 ) ;
if ( ( V_93 & F_11 ( V_4 ) ) && ( V_94 & V_48 ) &&
! V_77 -> V_98 )
V_96 = F_57 ( V_78 , V_79 ) ;
if ( ( ( V_93 & F_8 ( V_4 ) ) || V_77 -> V_80 ) &&
( V_94 & V_84 ) )
V_96 = F_54 ( V_78 , V_79 ) ;
if ( ( V_93 & F_5 ( V_4 ) ) && V_95 )
V_96 = F_60 ( V_78 , V_79 ) ;
if ( ( V_93 & F_53 ( V_4 ) ) && V_95 )
V_96 = F_61 ( V_78 , V_79 ) ;
return V_96 ;
}
static int F_65 ( struct V_99 * V_100 ,
unsigned long V_101 , void * V_102 )
{
struct V_1 * V_1 ;
unsigned long V_88 ;
V_1 = F_2 ( V_100 , struct V_1 , V_103 ) ;
if ( ( V_101 == V_104 ) ||
( V_101 == V_105 ) ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_58 ( & V_4 -> V_89 , V_88 ) ;
V_4 -> V_106 = F_66 ( V_1 -> V_107 ) ;
F_59 ( & V_4 -> V_89 , V_88 ) ;
}
return V_108 ;
}
static void F_67 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_68 ( V_4 -> V_64 ) ;
F_69 ( V_1 -> V_107 ) ;
V_1 -> V_4 . V_106 = F_66 ( V_1 -> V_107 ) ;
F_69 ( V_1 -> V_109 ) ;
}
static void F_70 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_71 ( V_1 -> V_109 ) ;
F_71 ( V_1 -> V_107 ) ;
F_72 ( V_4 -> V_64 ) ;
}
static int F_73 ( struct V_1 * V_4 )
{
int V_58 ;
T_1 (* F_74 [ 4 ])( int V_78 , void * V_79 ) = {
F_60 , sci_rx_interrupt, sci_tx_interrupt,
sci_br_interrupt,
}
void F_75 ( struct V_1 * V_4 )
{
int V_58 ;
if ( V_4 -> V_90 -> V_110 [ 0 ] == V_4 -> V_90 -> V_110 [ 1 ] )
F_76 ( V_4 -> V_90 -> V_110 [ 0 ] , V_4 ) ;
else {
for ( V_58 = 0 ; V_58 < F_77 ( V_4 -> V_90 -> V_110 ) ; V_58 ++ ) {
if ( ! V_4 -> V_90 -> V_110 [ V_58 ] )
continue;
F_76 ( V_4 -> V_90 -> V_110 [ V_58 ] , V_4 ) ;
}
}
}
static unsigned int F_78 ( struct V_2 * V_4 )
{
unsigned short V_5 = F_4 ( V_4 , V_7 ) ;
unsigned short V_111 = F_21 ( V_4 ) ;
return ( V_5 & F_13 ( V_4 ) ) && ! V_111 ? V_112 : 0 ;
}
static void F_79 ( struct V_2 * V_4 , unsigned int V_113 )
{
}
static unsigned int F_80 ( struct V_2 * V_4 )
{
return V_114 | V_115 | V_116 ;
}
static void F_81 ( void * V_117 )
{
struct V_1 * V_77 = V_117 ;
struct V_2 * V_4 = & V_77 -> V_4 ;
struct V_41 * V_42 = & V_4 -> V_43 -> V_42 ;
unsigned long V_88 ;
F_39 ( V_4 -> V_64 , L_9 , V_118 , V_4 -> line ) ;
F_58 ( & V_4 -> V_89 , V_88 ) ;
V_42 -> V_52 += F_82 ( & V_77 -> V_119 ) ;
V_42 -> V_52 &= V_53 - 1 ;
V_4 -> V_54 . V_18 += F_82 ( & V_77 -> V_119 ) ;
F_83 ( V_77 -> V_120 ) ;
V_77 -> V_121 = - V_122 ;
V_77 -> V_120 = NULL ;
if ( F_30 ( V_42 ) < V_55 )
F_31 ( V_4 ) ;
if ( ! F_29 ( V_42 ) ) {
F_84 ( & V_77 -> V_123 ) ;
} else if ( V_4 -> type == V_37 || V_4 -> type == V_83 ) {
T_2 V_45 = F_4 ( V_4 , V_47 ) ;
F_6 ( V_4 , V_47 , V_45 & ~ V_48 ) ;
}
F_59 ( & V_4 -> V_89 , V_88 ) ;
}
static int F_85 ( struct V_1 * V_77 , struct V_56 * V_57 ,
T_3 V_46 )
{
struct V_2 * V_4 = & V_77 -> V_4 ;
int V_58 , V_124 , V_125 ;
V_125 = F_34 ( V_57 , V_46 ) ;
if ( V_77 -> V_126 == V_77 -> V_127 [ 0 ] ) {
V_124 = 0 ;
} else if ( V_77 -> V_126 == V_77 -> V_127 [ 1 ] ) {
V_124 = 1 ;
} else {
F_86 ( V_4 -> V_64 , L_10 , V_77 -> V_126 ) ;
return 0 ;
}
if ( V_125 < V_46 )
F_87 ( V_4 -> V_64 , L_11 ,
V_46 - V_125 ) ;
if ( ! V_125 )
return V_125 ;
for ( V_58 = 0 ; V_58 < V_125 ; V_58 ++ )
F_36 ( V_57 , ( ( V_128 * ) F_88 ( & V_77 -> V_129 [ V_124 ] ) ) [ V_58 ] ,
V_62 ) ;
V_4 -> V_54 . V_16 += V_125 ;
return V_125 ;
}
static void F_89 ( void * V_117 )
{
struct V_1 * V_77 = V_117 ;
struct V_2 * V_4 = & V_77 -> V_4 ;
struct V_56 * V_57 = V_4 -> V_43 -> V_4 . V_57 ;
unsigned long V_88 ;
int V_46 ;
F_39 ( V_4 -> V_64 , L_12 , V_118 , V_4 -> line , V_77 -> V_126 ) ;
F_58 ( & V_4 -> V_89 , V_88 ) ;
V_46 = F_85 ( V_77 , V_57 , V_77 -> V_130 ) ;
F_45 ( & V_77 -> V_86 , V_68 + V_77 -> V_85 ) ;
F_59 ( & V_4 -> V_89 , V_88 ) ;
if ( V_46 )
F_43 ( V_57 ) ;
F_84 ( & V_77 -> V_131 ) ;
}
static void F_90 ( struct V_1 * V_77 , bool V_132 )
{
struct V_133 * V_134 = V_77 -> V_80 ;
struct V_2 * V_4 = & V_77 -> V_4 ;
V_77 -> V_80 = NULL ;
V_77 -> V_127 [ 0 ] = V_77 -> V_127 [ 1 ] = - V_122 ;
F_91 ( V_134 ) ;
if ( F_92 ( & V_77 -> V_129 [ 0 ] ) )
F_93 ( V_4 -> V_64 , V_77 -> V_130 * 2 ,
F_88 ( & V_77 -> V_129 [ 0 ] ) , F_92 ( & V_77 -> V_129 [ 0 ] ) ) ;
if ( V_132 )
F_94 ( V_4 ) ;
}
static void F_95 ( struct V_1 * V_77 , bool V_132 )
{
struct V_133 * V_134 = V_77 -> V_98 ;
struct V_2 * V_4 = & V_77 -> V_4 ;
V_77 -> V_98 = NULL ;
V_77 -> V_121 = - V_122 ;
F_91 ( V_134 ) ;
if ( V_132 )
F_96 ( V_4 ) ;
}
static void F_97 ( struct V_1 * V_77 )
{
struct V_133 * V_134 = V_77 -> V_80 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
struct V_135 * V_136 = & V_77 -> V_129 [ V_58 ] ;
struct V_137 * V_138 ;
V_138 = V_134 -> V_139 -> V_140 ( V_134 ,
V_136 , 1 , V_141 , V_142 ) ;
if ( V_138 ) {
V_77 -> V_143 [ V_58 ] = V_138 ;
V_138 -> V_144 = F_89 ;
V_138 -> V_145 = V_77 ;
V_77 -> V_127 [ V_58 ] = V_138 -> V_146 ( V_138 ) ;
}
if ( ! V_138 || V_77 -> V_127 [ V_58 ] < 0 ) {
if ( V_58 ) {
F_83 ( V_77 -> V_143 [ 0 ] ) ;
V_77 -> V_127 [ 0 ] = - V_122 ;
}
if ( V_138 ) {
F_83 ( V_138 ) ;
V_77 -> V_127 [ V_58 ] = - V_122 ;
}
F_87 ( V_77 -> V_4 . V_64 ,
L_13 ) ;
F_90 ( V_77 , true ) ;
return;
}
F_39 ( V_77 -> V_4 . V_64 , L_14 , V_118 ,
V_77 -> V_127 [ V_58 ] , V_58 ) ;
}
V_77 -> V_126 = V_77 -> V_127 [ 0 ] ;
F_98 ( V_134 ) ;
}
static void F_99 ( struct V_147 * V_148 )
{
struct V_1 * V_77 = F_2 ( V_148 , struct V_1 , V_131 ) ;
struct V_2 * V_4 = & V_77 -> V_4 ;
struct V_137 * V_138 ;
int V_149 ;
if ( V_77 -> V_126 == V_77 -> V_127 [ 0 ] ) {
V_149 = 0 ;
} else if ( V_77 -> V_126 == V_77 -> V_127 [ 1 ] ) {
V_149 = 1 ;
} else {
F_86 ( V_4 -> V_64 , L_10 , V_77 -> V_126 ) ;
return;
}
V_138 = V_77 -> V_143 [ V_149 ] ;
if ( F_100 ( V_77 -> V_80 , V_77 -> V_126 , NULL , NULL ) !=
V_150 ) {
struct V_56 * V_57 = V_4 -> V_43 -> V_4 . V_57 ;
struct V_133 * V_134 = V_77 -> V_80 ;
struct V_151 * V_151 = F_2 ( V_138 , struct V_151 ,
V_152 ) ;
unsigned long V_88 ;
int V_46 ;
V_134 -> V_139 -> V_153 ( V_134 , V_154 , 0 ) ;
F_39 ( V_4 -> V_64 , L_15 ,
V_151 -> V_155 , V_151 -> V_156 ) ;
F_58 ( & V_4 -> V_89 , V_88 ) ;
V_46 = F_85 ( V_77 , V_57 , V_151 -> V_155 ) ;
F_59 ( & V_4 -> V_89 , V_88 ) ;
if ( V_46 )
F_43 ( V_57 ) ;
F_97 ( V_77 ) ;
return;
}
V_77 -> V_127 [ V_149 ] = V_138 -> V_146 ( V_138 ) ;
if ( V_77 -> V_127 [ V_149 ] < 0 ) {
F_87 ( V_4 -> V_64 , L_16 ) ;
F_90 ( V_77 , true ) ;
return;
}
V_77 -> V_126 = V_77 -> V_127 [ ! V_149 ] ;
F_39 ( V_4 -> V_64 , L_17 , V_118 ,
V_77 -> V_127 [ V_149 ] , V_149 , V_77 -> V_126 ) ;
}
static void F_101 ( struct V_147 * V_148 )
{
struct V_1 * V_77 = F_2 ( V_148 , struct V_1 , V_123 ) ;
struct V_137 * V_138 ;
struct V_133 * V_134 = V_77 -> V_98 ;
struct V_2 * V_4 = & V_77 -> V_4 ;
struct V_41 * V_42 = & V_4 -> V_43 -> V_42 ;
struct V_135 * V_136 = & V_77 -> V_119 ;
F_102 ( & V_4 -> V_89 ) ;
V_136 -> V_157 = V_42 -> V_52 & ( V_53 - 1 ) ;
F_92 ( V_136 ) = ( F_92 ( V_136 ) & ~ ( V_53 - 1 ) ) +
V_136 -> V_157 ;
F_82 ( V_136 ) = F_103 ( ( int ) F_104 ( V_42 -> V_158 , V_42 -> V_52 , V_53 ) ,
F_105 ( V_42 -> V_158 , V_42 -> V_52 , V_53 ) ) ;
F_106 ( & V_4 -> V_89 ) ;
F_107 ( ! F_82 ( V_136 ) ) ;
V_138 = V_134 -> V_139 -> V_140 ( V_134 ,
V_136 , V_77 -> V_159 , V_160 ,
V_142 | V_161 ) ;
if ( ! V_138 ) {
F_95 ( V_77 , true ) ;
return;
}
F_108 ( V_4 -> V_64 , V_136 , 1 , V_160 ) ;
F_102 ( & V_4 -> V_89 ) ;
V_77 -> V_120 = V_138 ;
V_138 -> V_144 = F_81 ;
V_138 -> V_145 = V_77 ;
F_106 ( & V_4 -> V_89 ) ;
V_77 -> V_121 = V_138 -> V_146 ( V_138 ) ;
if ( V_77 -> V_121 < 0 ) {
F_87 ( V_4 -> V_64 , L_18 ) ;
F_95 ( V_77 , true ) ;
return;
}
F_39 ( V_4 -> V_64 , L_19 , V_118 ,
V_42 -> V_51 , V_42 -> V_52 , V_42 -> V_158 , V_77 -> V_121 ) ;
F_98 ( V_134 ) ;
}
static void F_96 ( struct V_2 * V_4 )
{
struct V_1 * V_77 = F_1 ( V_4 ) ;
unsigned short V_45 ;
#ifdef F_55
if ( V_4 -> type == V_37 || V_4 -> type == V_83 ) {
T_2 V_149 , V_81 = F_4 ( V_4 , V_47 ) ;
if ( V_77 -> V_98 )
V_149 = V_81 | 0x8000 ;
else
V_149 = V_81 & ~ 0x8000 ;
if ( V_149 != V_81 )
F_6 ( V_4 , V_47 , V_149 ) ;
}
if ( V_77 -> V_98 && ! F_29 ( & V_77 -> V_4 . V_43 -> V_42 ) &&
V_77 -> V_121 < 0 )
F_84 ( & V_77 -> V_123 ) ;
#endif
if ( ! V_77 -> V_98 || V_4 -> type == V_37 || V_4 -> type == V_83 ) {
V_45 = F_4 ( V_4 , V_47 ) ;
F_6 ( V_4 , V_47 , V_45 | V_48 ) ;
}
}
static void F_32 ( struct V_2 * V_4 )
{
unsigned short V_45 ;
V_45 = F_4 ( V_4 , V_47 ) ;
if ( V_4 -> type == V_37 || V_4 -> type == V_83 )
V_45 &= ~ 0x8000 ;
V_45 &= ~ V_48 ;
F_6 ( V_4 , V_47 , V_45 ) ;
}
static void F_94 ( struct V_2 * V_4 )
{
unsigned short V_45 ;
V_45 = F_4 ( V_4 , V_47 ) | F_63 ( V_4 ) ;
if ( V_4 -> type == V_37 || V_4 -> type == V_83 )
V_45 &= ~ 0x4000 ;
F_6 ( V_4 , V_47 , V_45 ) ;
}
static void F_109 ( struct V_2 * V_4 )
{
unsigned short V_45 ;
V_45 = F_4 ( V_4 , V_47 ) ;
if ( V_4 -> type == V_37 || V_4 -> type == V_83 )
V_45 &= ~ 0x4000 ;
V_45 &= ~ F_63 ( V_4 ) ;
F_6 ( V_4 , V_47 , V_45 ) ;
}
static void F_110 ( struct V_2 * V_4 )
{
}
static void F_111 ( struct V_2 * V_4 , int V_162 )
{
}
static bool F_112 ( struct V_133 * V_134 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_39 ( V_134 -> V_139 -> V_64 , L_20 , V_118 ,
V_165 -> V_166 ) ;
if ( V_165 -> V_167 == V_134 -> V_139 -> V_64 ) {
V_134 -> V_168 = V_165 ;
return true ;
} else {
return false ;
}
}
static void F_113 ( unsigned long V_117 )
{
struct V_1 * V_77 = (struct V_1 * ) V_117 ;
struct V_2 * V_4 = & V_77 -> V_4 ;
T_2 V_81 = F_4 ( V_4 , V_47 ) ;
if ( V_4 -> type == V_37 || V_4 -> type == V_83 ) {
V_81 &= ~ 0x4000 ;
F_114 ( V_77 -> V_90 -> V_110 [ 1 ] ) ;
}
F_6 ( V_4 , V_47 , V_81 | V_84 ) ;
F_39 ( V_4 -> V_64 , L_21 ) ;
F_84 ( & V_77 -> V_131 ) ;
}
static void F_115 ( struct V_2 * V_4 )
{
struct V_1 * V_77 = F_1 ( V_4 ) ;
struct V_164 * V_165 ;
struct V_133 * V_134 ;
T_4 V_169 ;
int V_170 ;
F_39 ( V_4 -> V_64 , L_22 , V_118 ,
V_4 -> line , V_77 -> V_90 -> V_167 ) ;
if ( ! V_77 -> V_90 -> V_167 )
return;
F_116 ( V_169 ) ;
F_117 ( V_171 , V_169 ) ;
V_165 = & V_77 -> V_172 ;
V_165 -> V_166 = V_77 -> V_90 -> V_173 ;
V_165 -> V_167 = V_77 -> V_90 -> V_167 ;
V_77 -> V_121 = - V_122 ;
V_134 = F_118 ( V_169 , F_112 , V_165 ) ;
F_39 ( V_4 -> V_64 , L_23 , V_118 , V_134 ) ;
if ( V_134 ) {
V_77 -> V_98 = V_134 ;
F_119 ( & V_77 -> V_119 , 1 ) ;
F_107 ( ( int ) V_4 -> V_43 -> V_42 . V_51 & ~ V_174 ) ;
F_120 ( & V_77 -> V_119 , F_121 ( V_4 -> V_43 -> V_42 . V_51 ) ,
V_53 , ( int ) V_4 -> V_43 -> V_42 . V_51 & ~ V_174 ) ;
V_170 = F_122 ( V_4 -> V_64 , & V_77 -> V_119 , 1 , V_160 ) ;
if ( ! V_170 )
F_95 ( V_77 , false ) ;
else
F_39 ( V_4 -> V_64 , L_24 , V_118 ,
F_82 ( & V_77 -> V_119 ) ,
V_4 -> V_43 -> V_42 . V_51 , F_92 ( & V_77 -> V_119 ) ) ;
V_77 -> V_159 = V_170 ;
F_123 ( & V_77 -> V_123 , F_101 ) ;
}
V_165 = & V_77 -> V_175 ;
V_165 -> V_166 = V_77 -> V_90 -> V_176 ;
V_165 -> V_167 = V_77 -> V_90 -> V_167 ;
V_134 = F_118 ( V_169 , F_112 , V_165 ) ;
F_39 ( V_4 -> V_64 , L_25 , V_118 , V_134 ) ;
if ( V_134 ) {
T_5 V_177 [ 2 ] ;
void * V_51 [ 2 ] ;
int V_58 ;
V_77 -> V_80 = V_134 ;
V_77 -> V_130 = 2 * F_124 ( 16 , ( int ) V_4 -> V_38 ) ;
V_51 [ 0 ] = F_125 ( V_4 -> V_64 , V_77 -> V_130 * 2 ,
& V_177 [ 0 ] , V_178 ) ;
if ( ! V_51 [ 0 ] ) {
F_87 ( V_4 -> V_64 ,
L_26 ) ;
F_90 ( V_77 , true ) ;
return;
}
V_51 [ 1 ] = V_51 [ 0 ] + V_77 -> V_130 ;
V_177 [ 1 ] = V_177 [ 0 ] + V_77 -> V_130 ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
struct V_135 * V_136 = & V_77 -> V_129 [ V_58 ] ;
F_119 ( V_136 , 1 ) ;
F_120 ( V_136 , F_121 ( V_51 [ V_58 ] ) , V_77 -> V_130 ,
( int ) V_51 [ V_58 ] & ~ V_174 ) ;
F_92 ( V_136 ) = V_177 [ V_58 ] ;
}
F_123 ( & V_77 -> V_131 , F_99 ) ;
F_126 ( & V_77 -> V_86 , F_113 , ( unsigned long ) V_77 ) ;
F_97 ( V_77 ) ;
}
}
static void F_127 ( struct V_2 * V_4 )
{
struct V_1 * V_77 = F_1 ( V_4 ) ;
if ( ! V_77 -> V_90 -> V_167 )
return;
if ( V_77 -> V_98 )
F_95 ( V_77 , false ) ;
if ( V_77 -> V_80 )
F_90 ( V_77 , false ) ;
}
static inline void F_115 ( struct V_2 * V_4 )
{
}
static inline void F_127 ( struct V_2 * V_4 )
{
}
static int F_128 ( struct V_2 * V_4 )
{
struct V_1 * V_77 = F_1 ( V_4 ) ;
int V_96 ;
F_39 ( V_4 -> V_64 , L_9 , V_118 , V_4 -> line ) ;
if ( V_77 -> V_70 )
V_77 -> V_70 ( V_4 ) ;
V_96 = F_73 ( V_77 ) ;
if ( F_129 ( V_96 < 0 ) )
return V_96 ;
F_115 ( V_4 ) ;
F_96 ( V_4 ) ;
F_94 ( V_4 ) ;
return 0 ;
}
static void F_130 ( struct V_2 * V_4 )
{
struct V_1 * V_77 = F_1 ( V_4 ) ;
F_39 ( V_4 -> V_64 , L_9 , V_118 , V_4 -> line ) ;
F_109 ( V_4 ) ;
F_32 ( V_4 ) ;
F_127 ( V_4 ) ;
F_75 ( V_77 ) ;
if ( V_77 -> V_71 )
V_77 -> V_71 ( V_4 ) ;
}
static unsigned int F_131 ( unsigned int V_179 , unsigned int V_180 ,
unsigned long V_181 )
{
switch ( V_179 ) {
case V_182 :
return ( ( V_181 + 16 * V_180 ) / ( 16 * V_180 ) - 1 ) ;
case V_183 :
return ( ( V_181 + 16 * V_180 ) / ( 32 * V_180 ) - 1 ) ;
case V_184 :
return ( ( ( V_181 * 2 ) + 16 * V_180 ) / ( 16 * V_180 ) - 1 ) ;
case V_185 :
return ( ( ( V_181 * 2 ) + 16 * V_180 ) / ( 32 * V_180 ) - 1 ) ;
case V_186 :
return ( ( ( V_181 * 1000 / 32 ) / V_180 ) - 1 ) ;
}
F_132 ( 1 ) ;
return ( ( V_181 + 16 * V_180 ) / ( 32 * V_180 ) - 1 ) ;
}
static void F_133 ( struct V_2 * V_4 , struct V_187 * V_188 ,
struct V_187 * V_189 )
{
struct V_1 * V_77 = F_1 ( V_4 ) ;
unsigned int V_5 , V_190 , V_191 , V_192 ;
int V_193 = - 1 ;
T_2 V_194 = 0 ;
V_192 = V_4 -> V_106 ? V_4 -> V_106 / 16 : 115200 ;
V_190 = F_134 ( V_4 , V_188 , V_189 , 0 , V_192 ) ;
if ( F_135 ( V_190 && V_4 -> V_106 ) )
V_193 = F_131 ( V_77 -> V_90 -> V_195 , V_190 , V_4 -> V_106 ) ;
if ( V_77 -> V_70 )
V_77 -> V_70 ( V_4 ) ;
do {
V_5 = F_4 ( V_4 , V_7 ) ;
} while ( ! ( V_5 & F_13 ( V_4 ) ) );
F_6 ( V_4 , V_47 , 0x00 ) ;
if ( V_4 -> type != V_49 )
F_6 ( V_4 , V_196 , V_194 | V_197 | V_198 ) ;
V_191 = F_4 ( V_4 , V_199 ) & 3 ;
if ( ( V_188 -> V_200 & V_201 ) == V_202 )
V_191 |= 0x40 ;
if ( V_188 -> V_200 & V_203 )
V_191 |= 0x20 ;
if ( V_188 -> V_200 & V_204 )
V_191 |= 0x30 ;
if ( V_188 -> V_200 & V_205 )
V_191 |= 0x08 ;
F_136 ( V_4 , V_188 -> V_200 , V_190 ) ;
F_6 ( V_4 , V_199 , V_191 ) ;
F_39 ( V_4 -> V_64 , L_27 , V_118 , V_191 , V_193 ,
V_77 -> V_90 -> V_91 ) ;
if ( V_193 > 0 ) {
if ( V_193 >= 256 ) {
F_6 ( V_4 , V_199 , ( F_4 ( V_4 , V_199 ) & ~ 3 ) | 1 ) ;
V_193 >>= 2 ;
} else
F_6 ( V_4 , V_199 , F_4 ( V_4 , V_199 ) & ~ 3 ) ;
F_6 ( V_4 , V_206 , V_193 ) ;
F_137 ( ( 1000000 + ( V_190 - 1 ) ) / V_190 ) ;
}
F_14 ( V_4 , V_188 -> V_200 ) ;
F_6 ( V_4 , V_196 , V_194 | ( ( V_188 -> V_200 & V_23 ) ? V_207 : 0 ) ) ;
F_6 ( V_4 , V_47 , V_77 -> V_90 -> V_91 ) ;
#ifdef F_55
if ( V_77 -> V_80 ) {
V_77 -> V_85 = ( V_4 -> V_208 - V_209 / 50 ) * V_77 -> V_130 * 3 /
V_4 -> V_38 / 2 ;
F_39 ( V_4 -> V_64 ,
L_28 ,
V_77 -> V_85 * 1000 / V_209 , V_4 -> V_208 ) ;
if ( V_77 -> V_85 < F_138 ( 20 ) )
V_77 -> V_85 = F_138 ( 20 ) ;
}
#endif
if ( ( V_188 -> V_200 & V_210 ) != 0 )
F_94 ( V_4 ) ;
if ( V_77 -> V_71 )
V_77 -> V_71 ( V_4 ) ;
}
static const char * F_139 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_211 :
return L_29 ;
case V_49 :
return L_30 ;
case V_74 :
return L_31 ;
case V_37 :
return L_32 ;
case V_83 :
return L_33 ;
}
return NULL ;
}
static inline unsigned long F_140 ( struct V_2 * V_4 )
{
return 64 ;
}
static int F_141 ( struct V_2 * V_4 )
{
unsigned long V_212 = F_140 ( V_4 ) ;
if ( V_4 -> V_213 )
return 0 ;
if ( V_4 -> V_88 & V_214 ) {
V_4 -> V_213 = F_142 ( V_4 -> V_13 , V_212 ) ;
if ( F_129 ( ! V_4 -> V_213 ) ) {
F_86 ( V_4 -> V_64 , L_34 , V_4 -> line ) ;
return - V_215 ;
}
} else {
V_4 -> V_213 = ( void V_216 * ) V_4 -> V_13 ;
}
return 0 ;
}
static void F_143 ( struct V_2 * V_4 )
{
if ( V_4 -> V_88 & V_214 ) {
F_144 ( V_4 -> V_213 ) ;
V_4 -> V_213 = NULL ;
}
F_145 ( V_4 -> V_13 , F_140 ( V_4 ) ) ;
}
static int F_146 ( struct V_2 * V_4 )
{
unsigned long V_212 = F_140 ( V_4 ) ;
struct V_217 * V_218 ;
int V_96 ;
V_218 = F_147 ( V_4 -> V_13 , V_212 , F_148 ( V_4 -> V_64 ) ) ;
if ( F_129 ( V_218 == NULL ) )
return - V_219 ;
V_96 = F_141 ( V_4 ) ;
if ( F_129 ( V_96 != 0 ) ) {
F_149 ( V_218 ) ;
return V_96 ;
}
return 0 ;
}
static void F_150 ( struct V_2 * V_4 , int V_88 )
{
if ( V_88 & V_220 ) {
struct V_1 * V_221 = F_1 ( V_4 ) ;
V_4 -> type = V_221 -> V_90 -> type ;
F_146 ( V_4 ) ;
}
}
static int F_151 ( struct V_2 * V_4 , struct V_222 * V_223 )
{
struct V_1 * V_77 = F_1 ( V_4 ) ;
if ( V_223 -> V_78 != V_77 -> V_90 -> V_110 [ V_224 ] || V_223 -> V_78 > V_225 )
return - V_122 ;
if ( V_223 -> V_226 < 2400 )
return - V_122 ;
return 0 ;
}
static int T_6 F_152 ( struct V_227 * V_64 ,
struct V_1 * V_1 ,
unsigned int V_228 ,
struct V_229 * V_102 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
V_4 -> V_230 = & V_231 ;
V_4 -> V_232 = V_233 ;
V_4 -> line = V_228 ;
switch ( V_102 -> type ) {
case V_83 :
V_4 -> V_38 = 256 ;
break;
case V_37 :
V_4 -> V_38 = 64 ;
break;
case V_74 :
V_4 -> V_38 = 16 ;
break;
default:
V_4 -> V_38 = 1 ;
break;
}
if ( V_64 ) {
V_1 -> V_107 = F_153 ( & V_64 -> V_64 , L_35 ) ;
if ( F_154 ( V_1 -> V_107 ) ) {
V_1 -> V_107 = F_153 ( & V_64 -> V_64 , L_36 ) ;
if ( F_154 ( V_1 -> V_107 ) ) {
F_86 ( & V_64 -> V_64 , L_37 ) ;
return F_155 ( V_1 -> V_107 ) ;
}
}
V_1 -> V_109 = F_153 ( & V_64 -> V_64 , L_38 ) ;
if ( F_154 ( V_1 -> V_109 ) )
V_1 -> V_109 = NULL ;
V_1 -> V_70 = F_67 ;
V_1 -> V_71 = F_70 ;
V_4 -> V_64 = & V_64 -> V_64 ;
F_156 ( & V_64 -> V_64 ) ;
}
V_1 -> V_67 . V_22 = ( unsigned long ) V_1 ;
V_1 -> V_67 . V_234 = F_46 ;
F_157 ( & V_1 -> V_67 ) ;
V_1 -> V_90 = V_102 ;
V_4 -> V_13 = V_102 -> V_13 ;
V_4 -> type = V_102 -> type ;
V_4 -> V_88 = V_102 -> V_88 ;
V_4 -> V_78 = V_102 -> V_110 [ V_235 ] ;
if ( V_102 -> V_167 )
F_39 ( V_4 -> V_64 , L_39 ,
V_102 -> V_167 , V_102 -> V_173 , V_102 -> V_176 ) ;
return 0 ;
}
static void F_158 ( struct V_2 * V_4 , int V_12 )
{
F_10 ( V_4 , V_12 ) ;
}
static void F_159 ( struct V_236 * V_237 , const char * V_77 ,
unsigned V_46 )
{
struct V_1 * V_1 = & V_238 [ V_237 -> V_228 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_239 ;
if ( V_1 -> V_70 )
V_1 -> V_70 ( V_4 ) ;
F_160 ( V_4 , V_77 , V_46 , F_158 ) ;
V_239 = F_11 ( V_4 ) | F_13 ( V_4 ) ;
while ( ( F_4 ( V_4 , V_7 ) & V_239 ) != V_239 )
F_161 () ;
if ( V_1 -> V_71 )
V_1 -> V_71 ( V_4 ) ;
}
static int T_6 F_162 ( struct V_236 * V_237 , char * V_240 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_190 = 115200 ;
int V_239 = 8 ;
int V_241 = 'n' ;
int V_242 = 'n' ;
int V_96 ;
if ( V_237 -> V_228 < 0 || V_237 -> V_228 >= V_243 )
return - V_244 ;
V_1 = & V_238 [ V_237 -> V_228 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_230 )
return - V_244 ;
V_96 = F_141 ( V_4 ) ;
if ( F_129 ( V_96 != 0 ) )
return V_96 ;
if ( V_1 -> V_70 )
V_1 -> V_70 ( V_4 ) ;
if ( V_240 )
F_163 ( V_240 , & V_190 , & V_241 , & V_239 , & V_242 ) ;
V_96 = F_164 ( V_4 , V_237 , V_190 , V_241 , V_239 , V_242 ) ;
#if F_37 ( V_245 ) || F_37 ( V_246 )
if ( V_96 == 0 )
F_109 ( V_4 ) ;
#endif
return V_96 ;
}
static int T_6 F_165 ( struct V_227 * V_247 )
{
struct V_229 * V_90 = V_247 -> V_64 . V_248 ;
if ( V_249 . V_22 )
return - V_250 ;
V_249 . V_228 = V_247 -> V_251 ;
F_152 ( NULL , & V_238 [ V_247 -> V_251 ] , V_247 -> V_251 , V_90 ) ;
F_162 ( & V_249 , V_252 ) ;
if ( ! strstr ( V_252 , L_40 ) )
V_249 . V_88 |= V_253 ;
F_166 ( & V_249 ) ;
return 0 ;
}
static inline int T_6 F_165 ( struct V_227 * V_247 )
{
return - V_122 ;
}
static int F_167 ( struct V_227 * V_64 )
{
struct V_1 * V_4 = F_168 ( V_64 ) ;
F_169 ( & V_4 -> V_103 ,
V_254 ) ;
F_170 ( & V_255 , & V_4 -> V_4 ) ;
F_171 ( V_4 -> V_107 ) ;
F_171 ( V_4 -> V_109 ) ;
F_172 ( & V_64 -> V_64 ) ;
return 0 ;
}
static int T_6 F_173 ( struct V_227 * V_64 ,
unsigned int V_228 ,
struct V_229 * V_102 ,
struct V_1 * V_256 )
{
int V_96 ;
if ( F_129 ( V_228 >= V_243 ) ) {
F_41 ( & V_64 -> V_64 , L_41
L_42 ,
V_228 + 1 , V_243 ) ;
F_41 ( & V_64 -> V_64 , L_43
L_44 ) ;
return 0 ;
}
V_96 = F_152 ( V_64 , V_256 , V_228 , V_102 ) ;
if ( V_96 )
return V_96 ;
return F_174 ( & V_255 , & V_256 -> V_4 ) ;
}
static int T_6 F_175 ( struct V_227 * V_64 )
{
struct V_229 * V_102 = V_64 -> V_64 . V_248 ;
struct V_1 * V_257 = & V_238 [ V_64 -> V_251 ] ;
int V_96 ;
if ( F_176 ( V_64 ) )
return F_165 ( V_64 ) ;
F_177 ( V_64 , V_257 ) ;
V_96 = F_173 ( V_64 , V_64 -> V_251 , V_102 , V_257 ) ;
if ( V_96 )
goto V_258;
V_257 -> V_103 . V_259 = F_65 ;
V_96 = F_178 ( & V_257 -> V_103 ,
V_254 ) ;
if ( F_129 ( V_96 < 0 ) )
goto V_258;
#ifdef F_179
F_180 () ;
#endif
return 0 ;
V_258:
F_167 ( V_64 ) ;
return V_96 ;
}
static int F_181 ( struct V_139 * V_64 )
{
struct V_1 * V_221 = F_182 ( V_64 ) ;
if ( V_221 )
F_183 ( & V_255 , & V_221 -> V_4 ) ;
return 0 ;
}
static int F_184 ( struct V_139 * V_64 )
{
struct V_1 * V_221 = F_182 ( V_64 ) ;
if ( V_221 )
F_185 ( & V_255 , & V_221 -> V_4 ) ;
return 0 ;
}
static int T_7 F_186 ( void )
{
int V_96 ;
F_187 ( V_260 ) ;
V_96 = F_188 ( & V_255 ) ;
if ( F_135 ( V_96 == 0 ) ) {
V_96 = F_189 ( & V_261 ) ;
if ( F_129 ( V_96 ) )
F_190 ( & V_255 ) ;
}
return V_96 ;
}
static void T_8 F_191 ( void )
{
F_192 ( & V_261 ) ;
F_190 ( & V_255 ) ;
}
