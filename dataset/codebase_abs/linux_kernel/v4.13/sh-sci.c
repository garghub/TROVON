static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static unsigned int F_3 ( struct V_2 * V_5 , int V_6 )
{
const struct V_7 * V_8 = F_4 ( V_5 , V_6 ) ;
if ( V_8 -> V_9 == 8 )
return F_5 ( V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else if ( V_8 -> V_9 == 16 )
return F_6 ( V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else
F_7 ( 1 , L_1 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_5 , int V_6 , int V_12 )
{
const struct V_7 * V_8 = F_4 ( V_5 , V_6 ) ;
if ( V_8 -> V_9 == 8 )
F_9 ( V_12 , V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else if ( V_8 -> V_9 == 16 )
F_10 ( V_12 , V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else
F_7 ( 1 , L_1 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
unsigned int V_13 ;
if ( ! V_1 -> V_4 . V_14 )
return;
F_12 ( V_1 -> V_4 . V_14 ) ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
F_13 ( V_1 -> V_16 [ V_13 ] ) ;
V_1 -> V_17 [ V_13 ] = F_14 ( V_1 -> V_16 [ V_13 ] ) ;
}
V_1 -> V_4 . V_18 = V_1 -> V_17 [ V_19 ] ;
}
static void F_15 ( struct V_1 * V_1 )
{
unsigned int V_13 ;
if ( ! V_1 -> V_4 . V_14 )
return;
for ( V_13 = V_15 ; V_13 -- > 0 ; )
F_16 ( V_1 -> V_16 [ V_13 ] ) ;
F_17 ( V_1 -> V_4 . V_14 ) ;
}
static inline unsigned long F_18 ( struct V_2 * V_4 )
{
return V_20 | ( F_1 ( V_4 ) -> V_21 -> V_22 & V_23 ) ;
}
static void F_19 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
unsigned short V_25 ;
#ifdef F_20
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
T_1 V_28 , V_29 = F_21 ( V_4 , V_30 ) ;
if ( V_24 -> V_31 )
V_28 = V_29 | V_32 ;
else
V_28 = V_29 & ~ V_32 ;
if ( V_28 != V_29 )
F_22 ( V_4 , V_30 , V_28 ) ;
}
if ( V_24 -> V_31 && ! F_23 ( & V_24 -> V_4 . V_33 -> V_34 ) &&
F_24 ( V_24 -> V_35 ) ) {
V_24 -> V_35 = 0 ;
F_25 ( & V_24 -> V_36 ) ;
}
#endif
if ( ! V_24 -> V_31 || V_4 -> type == V_26 || V_4 -> type == V_27 ) {
V_25 = F_21 ( V_4 , V_30 ) ;
F_22 ( V_4 , V_30 , V_25 | V_37 ) ;
}
}
static void F_26 ( struct V_2 * V_4 )
{
unsigned short V_25 ;
V_25 = F_21 ( V_4 , V_30 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
V_25 &= ~ V_32 ;
V_25 &= ~ V_37 ;
F_22 ( V_4 , V_30 , V_25 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
unsigned short V_25 ;
V_25 = F_21 ( V_4 , V_30 ) | F_18 ( V_4 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
V_25 &= ~ V_38 ;
F_22 ( V_4 , V_30 , V_25 ) ;
}
static void F_28 ( struct V_2 * V_4 )
{
unsigned short V_25 ;
V_25 = F_21 ( V_4 , V_30 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
V_25 &= ~ V_38 ;
V_25 &= ~ F_18 ( V_4 ) ;
F_22 ( V_4 , V_30 , V_25 ) ;
}
static void F_29 ( struct V_2 * V_4 , unsigned int V_39 )
{
if ( V_4 -> type == V_40 ) {
F_22 ( V_4 , V_41 , V_39 ) ;
} else if ( F_1 ( V_4 ) -> V_42 -> V_43 == V_44 ) {
F_22 ( V_4 , V_41 ,
F_21 ( V_4 , V_41 ) & V_39 ) ;
} else {
F_22 ( V_4 , V_41 , V_39 & ~ ( V_45 | V_46 ) ) ;
}
}
static int F_30 ( struct V_2 * V_4 )
{
unsigned short V_47 ;
int V_48 ;
do {
V_47 = F_21 ( V_4 , V_41 ) ;
if ( V_47 & F_31 ( V_4 ) ) {
F_29 ( V_4 , F_32 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_47 & F_33 ( V_4 ) ) )
return V_49 ;
V_48 = F_21 ( V_4 , V_50 ) ;
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_34 ( V_4 ) ) ;
return V_48 ;
}
static void F_35 ( struct V_2 * V_4 , unsigned char V_48 )
{
unsigned short V_47 ;
do {
V_47 = F_21 ( V_4 , V_41 ) ;
} while ( ! ( V_47 & F_36 ( V_4 ) ) );
F_22 ( V_4 , V_51 , V_48 ) ;
F_29 ( V_4 , F_37 ( V_4 ) & ~ F_38 ( V_4 ) ) ;
}
static void F_39 ( struct V_2 * V_4 , unsigned int V_52 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_24 -> V_21 -> V_53 && V_24 -> V_21 -> V_53 -> V_54 ) {
V_24 -> V_21 -> V_53 -> V_54 ( V_4 , V_52 ) ;
return;
}
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
T_1 V_55 = F_21 ( V_4 , V_56 ) ;
T_1 V_25 = F_21 ( V_4 , V_57 ) ;
V_25 &= ~ ( V_58 | V_59 ) ;
if ( F_1 ( V_4 ) -> V_60 ) {
if ( ! ( V_4 -> V_61 & V_62 ) ) {
V_25 |= V_63 ;
V_55 |= V_64 ;
} else if ( ! V_24 -> V_65 ) {
V_25 |= V_63 ;
V_55 &= ~ V_64 ;
} else {
V_25 &= ~ V_63 ;
}
V_25 &= ~ V_66 ;
}
F_22 ( V_4 , V_56 , V_55 ) ;
F_22 ( V_4 , V_57 , V_25 ) ;
} else if ( F_4 ( V_4 , V_67 ) -> V_9 ) {
T_1 V_47 = F_21 ( V_4 , V_67 ) ;
V_47 |= V_68 ;
if ( ! ( V_4 -> V_61 & V_62 ) )
V_47 |= V_69 ;
else if ( ! V_24 -> V_65 )
V_47 &= ~ V_69 ;
V_47 &= ~ ( V_70 | V_71 ) ;
F_22 ( V_4 , V_67 , V_47 ) ;
}
}
static int F_40 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
unsigned int V_72 = ( V_24 -> V_42 -> V_73 << 1 ) - 1 ;
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_74 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_74 ) & V_72 ;
V_8 = F_4 ( V_4 , V_75 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_75 ) >> 8 ;
return ! ( F_21 ( V_4 , V_41 ) & V_76 ) ;
}
static int F_41 ( struct V_2 * V_4 )
{
return V_4 -> V_73 - F_40 ( V_4 ) ;
}
static int F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
unsigned int V_72 = ( V_24 -> V_42 -> V_73 << 1 ) - 1 ;
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_77 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_77 ) & V_72 ;
V_8 = F_4 ( V_4 , V_75 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_75 ) & V_72 ;
return ( F_21 ( V_4 , V_41 ) & F_33 ( V_4 ) ) != 0 ;
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_78 * V_34 = & V_4 -> V_33 -> V_34 ;
unsigned int V_79 = F_44 ( V_4 ) ;
unsigned short V_47 ;
unsigned short V_25 ;
int V_80 ;
V_47 = F_21 ( V_4 , V_41 ) ;
if ( ! ( V_47 & F_36 ( V_4 ) ) ) {
V_25 = F_21 ( V_4 , V_30 ) ;
if ( F_23 ( V_34 ) )
V_25 &= ~ V_37 ;
else
V_25 |= V_37 ;
F_22 ( V_4 , V_30 , V_25 ) ;
return;
}
V_80 = F_41 ( V_4 ) ;
do {
unsigned char V_48 ;
if ( V_4 -> V_81 ) {
V_48 = V_4 -> V_81 ;
V_4 -> V_81 = 0 ;
} else if ( ! F_23 ( V_34 ) && ! V_79 ) {
V_48 = V_34 -> V_82 [ V_34 -> V_83 ] ;
V_34 -> V_83 = ( V_34 -> V_83 + 1 ) & ( V_84 - 1 ) ;
} else {
break;
}
F_22 ( V_4 , V_51 , V_48 ) ;
V_4 -> V_85 . V_86 ++ ;
} while ( -- V_80 > 0 );
F_29 ( V_4 , F_37 ( V_4 ) ) ;
if ( F_45 ( V_34 ) < V_87 )
F_46 ( V_4 ) ;
if ( F_23 ( V_34 ) ) {
F_26 ( V_4 ) ;
} else {
V_25 = F_21 ( V_4 , V_30 ) ;
if ( V_4 -> type != V_40 ) {
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_37 ( V_4 ) ) ;
}
V_25 |= V_37 ;
F_22 ( V_4 , V_30 , V_25 ) ;
}
}
static void F_47 ( struct V_2 * V_4 )
{
struct V_88 * V_89 = & V_4 -> V_33 -> V_4 ;
int V_13 , V_80 , V_90 = 0 ;
unsigned short V_47 ;
unsigned char V_91 ;
V_47 = F_21 ( V_4 , V_41 ) ;
if ( ! ( V_47 & F_33 ( V_4 ) ) )
return;
while ( 1 ) {
V_80 = F_48 ( V_89 , F_42 ( V_4 ) ) ;
if ( V_80 == 0 )
break;
if ( V_4 -> type == V_40 ) {
char V_48 = F_21 ( V_4 , V_50 ) ;
if ( F_49 ( V_4 , V_48 ) )
V_80 = 0 ;
else
F_50 ( V_89 , V_48 , V_92 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_80 ; V_13 ++ ) {
char V_48 = F_21 ( V_4 , V_50 ) ;
V_47 = F_21 ( V_4 , V_41 ) ;
if ( F_49 ( V_4 , V_48 ) ) {
V_80 -- ; V_13 -- ;
continue;
}
if ( V_47 & F_51 ( V_4 ) ) {
V_91 = V_93 ;
V_4 -> V_85 . V_94 ++ ;
F_52 ( V_4 -> V_14 , L_2 ) ;
} else if ( V_47 & F_53 ( V_4 ) ) {
V_91 = V_95 ;
V_4 -> V_85 . V_96 ++ ;
F_52 ( V_4 -> V_14 , L_3 ) ;
} else
V_91 = V_92 ;
F_50 ( V_89 , V_48 , V_91 ) ;
}
}
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_34 ( V_4 ) ) ;
V_90 += V_80 ;
V_4 -> V_85 . V_97 += V_80 ;
}
if ( V_90 ) {
F_54 ( V_89 ) ;
} else {
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_34 ( V_4 ) ) ;
}
}
static int F_55 ( struct V_2 * V_4 )
{
int V_90 = 0 ;
unsigned short V_47 = F_21 ( V_4 , V_41 ) ;
struct V_88 * V_89 = & V_4 -> V_33 -> V_4 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_47 & V_24 -> V_42 -> V_43 ) {
V_4 -> V_85 . V_98 ++ ;
if ( F_50 ( V_89 , 0 , V_99 ) )
V_90 ++ ;
F_52 ( V_4 -> V_14 , L_4 ) ;
}
if ( V_47 & F_51 ( V_4 ) ) {
V_4 -> V_85 . V_94 ++ ;
if ( F_50 ( V_89 , 0 , V_93 ) )
V_90 ++ ;
F_52 ( V_4 -> V_14 , L_2 ) ;
}
if ( V_47 & F_53 ( V_4 ) ) {
V_4 -> V_85 . V_96 ++ ;
if ( F_50 ( V_89 , 0 , V_95 ) )
V_90 ++ ;
F_52 ( V_4 -> V_14 , L_3 ) ;
}
if ( V_90 )
F_54 ( V_89 ) ;
return V_90 ;
}
static int F_56 ( struct V_2 * V_4 )
{
struct V_88 * V_89 = & V_4 -> V_33 -> V_4 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_90 = 0 ;
T_1 V_47 ;
V_8 = F_4 ( V_4 , V_24 -> V_42 -> V_100 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
V_47 = F_21 ( V_4 , V_24 -> V_42 -> V_100 ) ;
if ( V_47 & V_24 -> V_42 -> V_43 ) {
V_47 &= ~ V_24 -> V_42 -> V_43 ;
F_22 ( V_4 , V_24 -> V_42 -> V_100 , V_47 ) ;
V_4 -> V_85 . V_98 ++ ;
F_50 ( V_89 , 0 , V_99 ) ;
F_54 ( V_89 ) ;
F_57 ( V_4 -> V_14 , L_4 ) ;
V_90 ++ ;
}
return V_90 ;
}
static int F_58 ( struct V_2 * V_4 )
{
int V_90 = 0 ;
unsigned short V_47 = F_21 ( V_4 , V_41 ) ;
struct V_88 * V_89 = & V_4 -> V_33 -> V_4 ;
if ( F_59 ( V_4 ) )
return 0 ;
if ( V_47 & F_60 ( V_4 ) ) {
V_4 -> V_85 . V_101 ++ ;
if ( F_50 ( V_89 , 0 , V_102 ) )
V_90 ++ ;
F_57 ( V_4 -> V_14 , L_5 ) ;
}
if ( V_90 )
F_54 ( V_89 ) ;
V_90 += F_56 ( V_4 ) ;
return V_90 ;
}
static int F_61 ( struct V_2 * V_4 , int V_103 )
{
unsigned int V_104 ;
if ( V_103 < 1 )
V_103 = 1 ;
if ( V_103 >= V_4 -> V_73 )
V_103 = V_4 -> V_73 ;
if ( F_4 ( V_4 , V_105 ) -> V_9 ) {
F_22 ( V_4 , V_105 , V_103 ) ;
return V_103 ;
}
switch ( V_4 -> type ) {
case V_106 :
if ( V_103 < 4 ) {
V_104 = 0 ;
V_103 = 1 ;
} else if ( V_103 < 8 ) {
V_104 = V_107 ;
V_103 = 4 ;
} else if ( V_103 < 14 ) {
V_104 = V_108 ;
V_103 = 8 ;
} else {
V_104 = V_107 | V_108 ;
V_103 = 14 ;
}
break;
case V_26 :
case V_27 :
if ( V_103 < 16 ) {
V_104 = 0 ;
V_103 = 1 ;
} else if ( V_103 < 32 ) {
V_104 = V_107 ;
V_103 = 16 ;
} else if ( V_103 < 48 ) {
V_104 = V_108 ;
V_103 = 32 ;
} else {
V_104 = V_107 | V_108 ;
V_103 = 48 ;
}
break;
default:
F_7 ( 1 , L_6 ) ;
return 1 ;
}
F_22 ( V_4 , V_109 ,
( F_21 ( V_4 , V_109 ) &
~ ( V_108 | V_107 ) ) | V_104 ) ;
return V_103 ;
}
static int F_62 ( struct V_2 * V_4 )
{
if ( F_4 ( V_4 , V_105 ) -> V_9 )
return F_21 ( V_4 , V_105 ) != 0 ;
else
return ( F_21 ( V_4 , V_109 ) &
( V_107 | V_108 ) ) != 0 ;
}
static void F_63 ( unsigned long V_110 )
{
struct V_1 * V_24 = (struct V_1 * ) V_110 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
F_57 ( V_4 -> V_14 , L_7 ) ;
F_61 ( V_4 , 1 ) ;
}
static T_2 F_64 ( struct V_111 * V_14 ,
struct V_112 * V_113 ,
char * V_82 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_114 = F_1 ( V_4 ) ;
return sprintf ( V_82 , L_8 , V_114 -> V_115 ) ;
}
static T_2 F_66 ( struct V_111 * V_14 ,
struct V_112 * V_113 ,
const char * V_82 ,
T_3 V_80 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_114 = F_1 ( V_4 ) ;
int V_116 ;
long V_117 ;
V_116 = F_67 ( V_82 , 0 , & V_117 ) ;
if ( V_116 )
return V_116 ;
V_114 -> V_115 = F_61 ( V_4 , V_117 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
F_61 ( V_4 , 1 ) ;
return V_80 ;
}
static T_2 F_68 ( struct V_111 * V_14 ,
struct V_112 * V_113 ,
char * V_82 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_114 = F_1 ( V_4 ) ;
return sprintf ( V_82 , L_8 , V_114 -> V_118 ) ;
}
static T_2 F_69 ( struct V_111 * V_14 ,
struct V_112 * V_113 ,
const char * V_82 ,
T_3 V_80 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_114 = F_1 ( V_4 ) ;
int V_116 ;
long V_117 ;
V_116 = F_67 ( V_82 , 0 , & V_117 ) ;
if ( V_116 )
return V_116 ;
V_114 -> V_118 = V_117 ;
F_61 ( V_4 , 1 ) ;
if ( V_117 > 0 )
F_70 ( & V_114 -> V_119 , F_63 ,
( unsigned long ) V_114 ) ;
return V_80 ;
}
static void F_71 ( void * V_110 )
{
struct V_1 * V_24 = V_110 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_78 * V_34 = & V_4 -> V_33 -> V_34 ;
unsigned long V_120 ;
F_57 ( V_4 -> V_14 , L_9 , V_121 , V_4 -> line ) ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_34 -> V_83 += V_24 -> V_123 ;
V_34 -> V_83 &= V_84 - 1 ;
V_4 -> V_85 . V_86 += V_24 -> V_123 ;
if ( F_45 ( V_34 ) < V_87 )
F_46 ( V_4 ) ;
if ( ! F_23 ( V_34 ) ) {
V_24 -> V_35 = 0 ;
F_25 ( & V_24 -> V_36 ) ;
} else {
V_24 -> V_35 = - V_124 ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
T_1 V_25 = F_21 ( V_4 , V_30 ) ;
F_22 ( V_4 , V_30 , V_25 & ~ V_37 ) ;
}
}
F_73 ( & V_4 -> V_122 , V_120 ) ;
}
static int F_74 ( struct V_1 * V_24 , void * V_82 , T_3 V_80 )
{
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_88 * V_89 = & V_4 -> V_33 -> V_4 ;
int V_90 ;
V_90 = F_75 ( V_89 , V_82 , V_80 ) ;
if ( V_90 < V_80 )
V_4 -> V_85 . V_125 ++ ;
V_4 -> V_85 . V_97 += V_90 ;
return V_90 ;
}
static int F_76 ( struct V_1 * V_24 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_77 ( V_24 -> V_126 ) ; V_13 ++ )
if ( V_24 -> V_127 == V_24 -> V_126 [ V_13 ] )
return V_13 ;
return - 1 ;
}
static void F_78 ( struct V_1 * V_24 , bool V_128 )
{
struct V_129 * V_130 = V_24 -> V_131 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
unsigned long V_120 ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_24 -> V_131 = NULL ;
V_24 -> V_126 [ 0 ] = V_24 -> V_126 [ 1 ] = - V_124 ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_79 ( V_130 ) ;
F_80 ( V_130 -> V_111 -> V_14 , V_24 -> V_132 * 2 , V_24 -> V_133 [ 0 ] ,
F_81 ( & V_24 -> V_134 [ 0 ] ) ) ;
F_82 ( V_130 ) ;
if ( V_128 )
F_27 ( V_4 ) ;
}
static void F_83 ( void * V_110 )
{
struct V_1 * V_24 = V_110 ;
struct V_129 * V_130 = V_24 -> V_131 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_135 * V_136 ;
unsigned long V_120 ;
int V_137 , V_80 = 0 ;
F_57 ( V_4 -> V_14 , L_10 , V_121 , V_4 -> line ,
V_24 -> V_127 ) ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_137 = F_76 ( V_24 ) ;
if ( V_137 >= 0 )
V_80 = F_74 ( V_24 , V_24 -> V_133 [ V_137 ] , V_24 -> V_132 ) ;
F_84 ( & V_24 -> V_138 , V_139 + V_24 -> V_140 ) ;
if ( V_80 )
F_54 ( & V_4 -> V_33 -> V_4 ) ;
V_136 = F_85 ( V_24 -> V_131 , & V_24 -> V_134 [ V_137 ] , 1 ,
V_141 ,
V_142 | V_143 ) ;
if ( ! V_136 )
goto V_144;
V_136 -> V_145 = F_83 ;
V_136 -> V_146 = V_24 ;
V_24 -> V_126 [ V_137 ] = F_86 ( V_136 ) ;
if ( F_24 ( V_24 -> V_126 [ V_137 ] ) )
goto V_144;
V_24 -> V_127 = V_24 -> V_126 [ ! V_137 ] ;
F_87 ( V_130 ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_57 ( V_4 -> V_14 , L_11 ,
V_121 , V_24 -> V_126 [ V_137 ] , V_137 , V_24 -> V_127 ) ;
return;
V_144:
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_88 ( V_4 -> V_14 , L_12 ) ;
F_78 ( V_24 , true ) ;
}
static void F_89 ( struct V_1 * V_24 , bool V_128 )
{
struct V_129 * V_130 = V_24 -> V_31 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
unsigned long V_120 ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_24 -> V_31 = NULL ;
V_24 -> V_35 = - V_124 ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_79 ( V_130 ) ;
F_90 ( V_130 -> V_111 -> V_14 , V_24 -> V_147 , V_84 ,
V_148 ) ;
F_82 ( V_130 ) ;
if ( V_128 )
F_19 ( V_4 ) ;
}
static void F_91 ( struct V_1 * V_24 )
{
struct V_129 * V_130 = V_24 -> V_131 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
struct V_149 * V_150 = & V_24 -> V_134 [ V_13 ] ;
struct V_135 * V_136 ;
V_136 = F_85 ( V_130 ,
V_150 , 1 , V_141 ,
V_142 | V_143 ) ;
if ( ! V_136 )
goto V_144;
V_136 -> V_145 = F_83 ;
V_136 -> V_146 = V_24 ;
V_24 -> V_126 [ V_13 ] = F_86 ( V_136 ) ;
if ( F_24 ( V_24 -> V_126 [ V_13 ] ) )
goto V_144;
}
V_24 -> V_127 = V_24 -> V_126 [ 0 ] ;
F_87 ( V_130 ) ;
return;
V_144:
if ( V_13 )
F_79 ( V_130 ) ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
V_24 -> V_126 [ V_13 ] = - V_124 ;
V_24 -> V_127 = - V_124 ;
F_78 ( V_24 , true ) ;
}
static void F_92 ( struct V_151 * V_152 )
{
struct V_1 * V_24 = F_2 ( V_152 , struct V_1 , V_36 ) ;
struct V_135 * V_136 ;
struct V_129 * V_130 = V_24 -> V_31 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_78 * V_34 = & V_4 -> V_33 -> V_34 ;
T_4 V_82 ;
F_93 ( & V_4 -> V_122 ) ;
V_82 = V_24 -> V_147 + ( V_34 -> V_83 & ( V_84 - 1 ) ) ;
V_24 -> V_123 = F_94 (unsigned int,
CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE),
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE)) ;
F_95 ( & V_4 -> V_122 ) ;
V_136 = F_96 ( V_130 , V_82 , V_24 -> V_123 ,
V_153 ,
V_142 | V_143 ) ;
if ( ! V_136 ) {
F_88 ( V_4 -> V_14 , L_13 ) ;
F_89 ( V_24 , true ) ;
return;
}
F_97 ( V_130 -> V_111 -> V_14 , V_82 , V_24 -> V_123 ,
V_148 ) ;
F_93 ( & V_4 -> V_122 ) ;
V_136 -> V_145 = F_71 ;
V_136 -> V_146 = V_24 ;
F_95 ( & V_4 -> V_122 ) ;
V_24 -> V_35 = F_86 ( V_136 ) ;
if ( F_24 ( V_24 -> V_35 ) ) {
F_88 ( V_4 -> V_14 , L_14 ) ;
F_89 ( V_24 , true ) ;
return;
}
F_57 ( V_4 -> V_14 , L_15 ,
V_121 , V_34 -> V_82 , V_34 -> V_83 , V_34 -> V_154 , V_24 -> V_35 ) ;
F_87 ( V_130 ) ;
}
static void F_98 ( unsigned long V_110 )
{
struct V_1 * V_24 = (struct V_1 * ) V_110 ;
struct V_129 * V_130 = V_24 -> V_131 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_155 V_33 ;
enum V_156 V_47 ;
unsigned long V_120 ;
unsigned int V_157 ;
int V_137 , V_80 ;
T_1 V_29 ;
F_57 ( V_4 -> V_14 , L_16 ) ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_137 = F_76 ( V_24 ) ;
if ( V_137 < 0 ) {
F_73 ( & V_4 -> V_122 , V_120 ) ;
return;
}
V_47 = F_99 ( V_24 -> V_131 , V_24 -> V_127 , & V_33 ) ;
if ( V_47 == V_158 ) {
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_57 ( V_4 -> V_14 , L_17 ,
V_24 -> V_127 , V_137 ) ;
return;
}
F_100 ( V_130 ) ;
V_47 = F_99 ( V_24 -> V_131 , V_24 -> V_127 , & V_33 ) ;
if ( V_47 == V_158 ) {
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_57 ( V_4 -> V_14 , L_18 ) ;
return;
}
F_79 ( V_24 -> V_131 ) ;
V_157 = F_101 ( & V_24 -> V_134 [ V_137 ] ) - V_33 . V_159 ;
if ( V_157 ) {
V_80 = F_74 ( V_24 , V_24 -> V_133 [ V_137 ] , V_157 ) ;
if ( V_80 )
F_54 ( & V_4 -> V_33 -> V_4 ) ;
}
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
F_91 ( V_24 ) ;
V_29 = F_21 ( V_4 , V_30 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
V_29 &= ~ V_38 ;
F_102 ( V_24 -> V_160 [ V_161 ] ) ;
}
F_22 ( V_4 , V_30 , V_29 | V_20 ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
}
static struct V_129 * F_103 ( struct V_2 * V_4 ,
enum V_162 V_163 )
{
struct V_129 * V_130 ;
struct V_164 V_21 ;
int V_116 ;
V_130 = F_104 ( V_4 -> V_14 ,
V_163 == V_153 ? L_19 : L_20 ) ;
if ( ! V_130 ) {
F_88 ( V_4 -> V_14 , L_21 ) ;
return NULL ;
}
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_165 = V_163 ;
if ( V_163 == V_153 ) {
V_21 . V_166 = V_4 -> V_167 +
( F_4 ( V_4 , V_51 ) -> V_6 << V_4 -> V_11 ) ;
V_21 . V_168 = V_169 ;
} else {
V_21 . V_170 = V_4 -> V_167 +
( F_4 ( V_4 , V_50 ) -> V_6 << V_4 -> V_11 ) ;
V_21 . V_171 = V_169 ;
}
V_116 = F_105 ( V_130 , & V_21 ) ;
if ( V_116 ) {
F_88 ( V_4 -> V_14 , L_22 , V_116 ) ;
F_82 ( V_130 ) ;
return NULL ;
}
return V_130 ;
}
static void F_106 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
struct V_129 * V_130 ;
F_57 ( V_4 -> V_14 , L_23 , V_121 , V_4 -> line ) ;
if ( ! V_4 -> V_14 -> V_172 )
return;
V_24 -> V_35 = - V_124 ;
V_130 = F_103 ( V_4 , V_153 ) ;
F_57 ( V_4 -> V_14 , L_24 , V_121 , V_130 ) ;
if ( V_130 ) {
V_24 -> V_31 = V_130 ;
V_24 -> V_147 = F_107 ( V_130 -> V_111 -> V_14 ,
V_4 -> V_33 -> V_34 . V_82 ,
V_84 ,
V_148 ) ;
if ( F_108 ( V_130 -> V_111 -> V_14 , V_24 -> V_147 ) ) {
F_88 ( V_4 -> V_14 , L_25 ) ;
F_82 ( V_130 ) ;
V_24 -> V_31 = NULL ;
} else {
F_57 ( V_4 -> V_14 , L_26 ,
V_121 , V_84 ,
V_4 -> V_33 -> V_34 . V_82 , & V_24 -> V_147 ) ;
}
F_109 ( & V_24 -> V_36 , F_92 ) ;
}
V_130 = F_103 ( V_4 , V_141 ) ;
F_57 ( V_4 -> V_14 , L_27 , V_121 , V_130 ) ;
if ( V_130 ) {
unsigned int V_13 ;
T_4 V_173 ;
void * V_82 ;
V_24 -> V_131 = V_130 ;
V_24 -> V_132 = 2 * F_110 ( T_3 , 16 , V_4 -> V_73 ) ;
V_82 = F_111 ( V_130 -> V_111 -> V_14 , V_24 -> V_132 * 2 ,
& V_173 , V_174 ) ;
if ( ! V_82 ) {
F_88 ( V_4 -> V_14 ,
L_28 ) ;
F_82 ( V_130 ) ;
V_24 -> V_131 = NULL ;
return;
}
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
struct V_149 * V_150 = & V_24 -> V_134 [ V_13 ] ;
F_112 ( V_150 , 1 ) ;
V_24 -> V_133 [ V_13 ] = V_82 ;
F_81 ( V_150 ) = V_173 ;
F_101 ( V_150 ) = V_24 -> V_132 ;
V_82 += V_24 -> V_132 ;
V_173 += V_24 -> V_132 ;
}
F_70 ( & V_24 -> V_138 , F_98 , ( unsigned long ) V_24 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
F_91 ( V_24 ) ;
}
}
static void F_113 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_24 -> V_31 )
F_89 ( V_24 , false ) ;
if ( V_24 -> V_131 )
F_78 ( V_24 , false ) ;
}
static void F_114 ( struct V_2 * V_4 )
{
F_1 ( V_4 ) -> V_123 = 0 ;
}
static inline void F_106 ( struct V_2 * V_4 )
{
}
static inline void F_113 ( struct V_2 * V_4 )
{
}
static T_5 F_115 ( int V_175 , void * V_176 )
{
struct V_2 * V_4 = V_176 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
#ifdef F_20
if ( V_24 -> V_131 ) {
T_1 V_29 = F_21 ( V_4 , V_30 ) ;
T_1 V_177 = F_21 ( V_4 , V_41 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
F_116 ( V_175 ) ;
V_29 |= V_38 ;
} else {
V_29 &= ~ V_20 ;
F_91 ( V_24 ) ;
}
F_22 ( V_4 , V_30 , V_29 ) ;
F_22 ( V_4 , V_41 ,
V_177 & ~ ( V_178 | F_33 ( V_4 ) ) ) ;
F_57 ( V_4 -> V_14 , L_29 ,
V_139 , V_24 -> V_140 ) ;
F_84 ( & V_24 -> V_138 , V_139 + V_24 -> V_140 ) ;
return V_179 ;
}
#endif
if ( V_24 -> V_115 > 1 && V_24 -> V_118 > 0 ) {
if ( ! F_62 ( V_4 ) )
F_61 ( V_4 , V_24 -> V_115 ) ;
F_84 ( & V_24 -> V_119 , V_139 + F_117 (
V_24 -> V_180 * V_24 -> V_118 , 1000 ) ) ;
}
F_47 ( V_176 ) ;
return V_179 ;
}
static T_5 F_118 ( int V_175 , void * V_176 )
{
struct V_2 * V_4 = V_176 ;
unsigned long V_120 ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
F_43 ( V_4 ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
return V_179 ;
}
static T_5 F_119 ( int V_175 , void * V_176 )
{
struct V_2 * V_4 = V_176 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_4 -> type == V_40 ) {
if ( F_55 ( V_4 ) ) {
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_34 ( V_4 ) ) ;
}
} else {
F_56 ( V_4 ) ;
if ( ! V_24 -> V_131 )
F_47 ( V_176 ) ;
}
F_29 ( V_4 , F_32 ( V_4 ) ) ;
if ( ! V_24 -> V_31 )
F_118 ( V_175 , V_176 ) ;
return V_179 ;
}
static T_5 F_120 ( int V_175 , void * V_176 )
{
struct V_2 * V_4 = V_176 ;
F_58 ( V_4 ) ;
F_29 ( V_4 , F_121 ( V_4 ) ) ;
return V_179 ;
}
static T_5 F_122 ( int V_175 , void * V_176 )
{
unsigned short V_181 , V_182 , V_183 , V_184 = 0 ;
struct V_2 * V_4 = V_176 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
T_5 V_116 = V_185 ;
V_181 = F_21 ( V_4 , V_41 ) ;
V_182 = F_21 ( V_4 , V_30 ) ;
if ( V_24 -> V_42 -> V_100 == V_41 )
V_184 = V_181 ;
else if ( F_4 ( V_4 , V_24 -> V_42 -> V_100 ) -> V_9 )
V_184 = F_21 ( V_4 , V_24 -> V_42 -> V_100 ) ;
V_183 = V_182 & F_18 ( V_4 ) ;
if ( ( V_181 & F_36 ( V_4 ) ) && ( V_182 & V_37 ) &&
! V_24 -> V_31 )
V_116 = F_118 ( V_175 , V_176 ) ;
if ( ( ( V_181 & F_33 ( V_4 ) ) || V_24 -> V_131 ) &&
( V_182 & V_20 ) )
V_116 = F_115 ( V_175 , V_176 ) ;
if ( ( V_181 & F_31 ( V_4 ) ) && V_183 )
V_116 = F_119 ( V_175 , V_176 ) ;
if ( ( V_181 & F_60 ( V_4 ) ) && V_183 )
V_116 = F_120 ( V_175 , V_176 ) ;
if ( V_184 & V_24 -> V_42 -> V_43 ) {
F_56 ( V_4 ) ;
V_116 = V_179 ;
}
return V_116 ;
}
static int F_123 ( struct V_1 * V_4 )
{
struct V_2 * V_186 = & V_4 -> V_4 ;
int V_13 , V_187 , V_116 = 0 ;
for ( V_13 = V_187 = 0 ; V_13 < V_188 ; V_13 ++ , V_187 ++ ) {
const struct V_189 * V_136 ;
int V_175 ;
if ( F_124 ( V_4 ) ) {
V_13 = V_190 ;
V_175 = V_186 -> V_175 ;
} else {
V_175 = V_4 -> V_160 [ V_13 ] ;
if ( F_125 ( V_175 < 0 ) )
continue;
}
V_136 = V_189 + V_13 ;
V_4 -> V_191 [ V_187 ] = F_126 ( V_174 , L_30 ,
F_127 ( V_186 -> V_14 ) , V_136 -> V_136 ) ;
if ( ! V_4 -> V_191 [ V_187 ] ) {
V_116 = - V_192 ;
goto V_193;
}
V_116 = F_128 ( V_175 , V_136 -> V_194 , V_186 -> V_195 ,
V_4 -> V_191 [ V_187 ] , V_4 ) ;
if ( F_125 ( V_116 ) ) {
F_129 ( V_186 -> V_14 , L_31 , V_136 -> V_136 ) ;
goto V_196;
}
}
return 0 ;
V_196:
while ( -- V_13 >= 0 )
F_130 ( V_4 -> V_160 [ V_13 ] , V_4 ) ;
V_193:
while ( -- V_187 >= 0 )
F_131 ( V_4 -> V_191 [ V_187 ] ) ;
return V_116 ;
}
static void F_132 ( struct V_1 * V_4 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_188 ; V_13 ++ ) {
int V_175 = V_4 -> V_160 [ V_13 ] ;
if ( F_125 ( V_175 < 0 ) )
continue;
F_130 ( V_4 -> V_160 [ V_13 ] , V_4 ) ;
F_131 ( V_4 -> V_191 [ V_13 ] ) ;
if ( F_124 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_133 ( struct V_2 * V_4 )
{
unsigned short V_47 = F_21 ( V_4 , V_41 ) ;
unsigned short V_197 = F_40 ( V_4 ) ;
return ( V_47 & F_38 ( V_4 ) ) && ! V_197 ? V_198 : 0 ;
}
static void F_134 ( struct V_2 * V_4 , bool V_33 )
{
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
T_1 V_55 = F_21 ( V_4 , V_56 ) ;
if ( V_33 )
V_55 &= ~ V_64 ;
else
V_55 |= V_64 ;
F_22 ( V_4 , V_56 , V_55 ) ;
F_22 ( V_4 , V_57 ,
F_21 ( V_4 , V_57 ) | V_63 ) ;
} else if ( F_4 ( V_4 , V_67 ) -> V_9 ) {
T_1 V_25 = F_21 ( V_4 , V_67 ) ;
if ( V_33 )
V_25 &= ~ V_69 ;
else
V_25 |= V_69 ;
F_22 ( V_4 , V_67 , V_25 ) ;
}
}
static bool F_135 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
return ! ( F_21 ( V_4 , V_56 ) & V_199 ) ;
} else if ( F_4 ( V_4 , V_67 ) -> V_9 ) {
return ! ( F_21 ( V_4 , V_67 ) & V_200 ) ;
}
return true ;
}
static void F_136 ( struct V_2 * V_4 , unsigned int V_61 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_61 & V_201 ) {
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_109 ) ;
if ( V_8 -> V_9 )
F_22 ( V_4 , V_109 ,
F_21 ( V_4 , V_109 ) |
V_202 ) ;
}
F_137 ( V_24 -> V_203 , V_61 ) ;
if ( ! V_24 -> V_60 )
return;
if ( ! ( V_61 & V_62 ) ) {
F_22 ( V_4 , V_109 ,
F_21 ( V_4 , V_109 ) & ~ V_204 ) ;
F_134 ( V_4 , 0 ) ;
} else if ( V_24 -> V_65 ) {
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
F_22 ( V_4 , V_57 ,
F_21 ( V_4 , V_57 ) & ~ V_63 ) ;
}
F_22 ( V_4 , V_109 ,
F_21 ( V_4 , V_109 ) | V_204 ) ;
} else {
F_134 ( V_4 , 1 ) ;
}
}
static unsigned int F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
struct V_205 * V_203 = V_24 -> V_203 ;
unsigned int V_61 = 0 ;
F_139 ( V_203 , & V_61 ) ;
if ( V_24 -> V_65 ) {
if ( F_135 ( V_4 ) )
V_61 |= V_206 ;
} else if ( F_140 ( F_141 ( V_203 , V_207 ) ) ) {
V_61 |= V_206 ;
}
if ( F_140 ( F_141 ( V_203 , V_208 ) ) )
V_61 |= V_209 ;
if ( F_140 ( F_141 ( V_203 , V_210 ) ) )
V_61 |= V_211 ;
return V_61 ;
}
static void F_142 ( struct V_2 * V_4 )
{
F_143 ( F_1 ( V_4 ) -> V_203 ) ;
}
static void F_144 ( struct V_2 * V_4 , int V_212 )
{
unsigned short V_22 , V_213 ;
if ( ! F_4 ( V_4 , V_67 ) -> V_9 ) {
return;
}
V_213 = F_21 ( V_4 , V_67 ) ;
V_22 = F_21 ( V_4 , V_30 ) ;
if ( V_212 == - 1 ) {
V_213 = ( V_213 | V_214 ) & ~ V_215 ;
V_22 &= ~ V_216 ;
} else {
V_213 = ( V_213 | V_215 ) & ~ V_214 ;
V_22 |= V_216 ;
}
F_22 ( V_4 , V_67 , V_213 ) ;
F_22 ( V_4 , V_30 , V_22 ) ;
}
static int F_145 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
int V_116 ;
F_57 ( V_4 -> V_14 , L_9 , V_121 , V_4 -> line ) ;
F_106 ( V_4 ) ;
V_116 = F_123 ( V_24 ) ;
if ( F_125 ( V_116 < 0 ) ) {
F_113 ( V_4 ) ;
return V_116 ;
}
return 0 ;
}
static void F_146 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
unsigned long V_120 ;
T_1 V_29 ;
F_57 ( V_4 -> V_14 , L_9 , V_121 , V_4 -> line ) ;
V_24 -> V_65 = false ;
F_147 ( F_1 ( V_4 ) -> V_203 ) ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
F_28 ( V_4 ) ;
F_26 ( V_4 ) ;
V_29 = F_21 ( V_4 , V_30 ) ;
F_22 ( V_4 , V_30 , V_29 & ( V_217 | V_218 ) ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
#ifdef F_20
if ( V_24 -> V_131 ) {
F_57 ( V_4 -> V_14 , L_32 , V_121 ,
V_4 -> line ) ;
F_148 ( & V_24 -> V_138 ) ;
}
#endif
F_132 ( V_24 ) ;
F_113 ( V_4 ) ;
}
static int F_149 ( struct V_1 * V_24 , unsigned int V_219 ,
unsigned int * V_220 )
{
unsigned long V_221 = V_24 -> V_17 [ V_222 ] ;
int V_223 , V_224 = V_225 ;
unsigned int V_226 ;
if ( V_24 -> V_4 . type != V_227 )
V_221 *= 2 ;
F_150 (sr, s) {
V_223 = F_151 ( V_221 , V_226 ) - V_219 ;
if ( abs ( V_223 ) >= abs ( V_224 ) )
continue;
V_224 = V_223 ;
* V_220 = V_226 - 1 ;
if ( ! V_223 )
break;
}
F_57 ( V_24 -> V_4 . V_14 , L_33 , V_219 , V_224 ,
* V_220 + 1 ) ;
return V_224 ;
}
static int F_152 ( struct V_1 * V_24 , unsigned int V_219 ,
unsigned long V_221 , unsigned int * V_228 ,
unsigned int * V_220 )
{
int V_223 , V_224 = V_225 ;
unsigned int V_226 , V_229 ;
if ( V_24 -> V_4 . type != V_227 )
V_221 *= 2 ;
F_150 (sr, s) {
V_229 = F_151 ( V_221 , V_226 * V_219 ) ;
V_229 = F_153 ( V_229 , 1U , 65535U ) ;
V_223 = F_151 ( V_221 , V_226 * V_229 ) - V_219 ;
if ( abs ( V_223 ) >= abs ( V_224 ) )
continue;
V_224 = V_223 ;
* V_228 = V_229 ;
* V_220 = V_226 - 1 ;
if ( ! V_223 )
break;
}
F_57 ( V_24 -> V_4 . V_14 , L_34 , V_219 ,
V_224 , * V_228 , * V_220 + 1 ) ;
return V_224 ;
}
static int F_154 ( struct V_1 * V_24 , unsigned int V_219 ,
unsigned int * V_230 , unsigned int * V_220 ,
unsigned int * V_231 )
{
unsigned long V_221 = V_24 -> V_17 [ V_19 ] ;
unsigned int V_226 , V_232 , V_233 , V_234 , V_48 ;
int V_223 , V_224 = V_225 ;
if ( V_24 -> V_4 . type != V_227 )
V_221 *= 2 ;
F_150 (sr, s) {
for ( V_48 = 0 ; V_48 <= 3 ; V_48 ++ ) {
V_233 = V_226 * ( 1 << ( 2 * V_48 + 1 ) ) ;
if ( V_219 > V_235 / V_233 )
break;
V_234 = V_233 * V_219 ;
V_232 = F_151 ( V_221 , V_234 ) ;
V_232 = F_153 ( V_232 , 1U , 256U ) ;
V_223 = F_151 ( V_221 , V_232 * V_233 ) - V_219 ;
if ( abs ( V_223 ) >= abs ( V_224 ) )
continue;
V_224 = V_223 ;
* V_230 = V_232 - 1 ;
* V_220 = V_226 - 1 ;
* V_231 = V_48 ;
if ( ! V_223 )
goto V_236;
}
}
V_236:
F_57 ( V_24 -> V_4 . V_14 , L_35 , V_219 ,
V_224 , * V_230 , * V_220 + 1 , * V_231 ) ;
return V_224 ;
}
static void F_155 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
unsigned int V_47 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
F_22 ( V_4 , V_30 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_109 ) ;
if ( V_8 -> V_9 )
F_22 ( V_4 , V_109 , V_237 | V_238 ) ;
F_29 ( V_4 ,
F_34 ( V_4 ) & F_32 ( V_4 ) &
F_121 ( V_4 ) ) ;
if ( F_4 ( V_4 , V_239 ) -> V_9 ) {
V_47 = F_21 ( V_4 , V_239 ) ;
V_47 &= ~ ( V_240 | V_241 ) ;
F_22 ( V_4 , V_239 , V_47 ) ;
}
if ( V_24 -> V_115 > 1 ) {
if ( V_24 -> V_118 ) {
F_61 ( V_4 , 1 ) ;
F_70 ( & V_24 -> V_119 , F_63 ,
( unsigned long ) V_24 ) ;
} else {
if ( V_4 -> type == V_26 ||
V_4 -> type == V_27 )
F_61 ( V_4 , 1 ) ;
else
F_61 ( V_4 , V_24 -> V_115 ) ;
}
}
}
static void F_156 ( struct V_2 * V_4 , struct V_242 * V_243 ,
struct V_242 * V_244 )
{
unsigned int V_245 , V_246 = V_247 , V_248 = 0 , V_13 , V_104 ;
unsigned int V_230 = 255 , V_231 = 0 , V_220 = 15 , V_229 = 0 , V_249 = 0 ;
unsigned int V_250 = 255 , V_251 = 0 , V_252 = 15 , V_253 = 0 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_224 = V_225 , V_223 ;
unsigned long V_254 = 0 ;
int V_255 = - 1 ;
if ( ( V_243 -> V_256 & V_257 ) == V_258 )
V_246 |= V_259 ;
if ( V_243 -> V_256 & V_260 )
V_246 |= V_261 ;
if ( V_243 -> V_256 & V_262 )
V_246 |= V_261 | V_263 ;
if ( V_243 -> V_256 & V_264 )
V_246 |= V_265 ;
if ( ! V_4 -> V_18 ) {
V_245 = F_157 ( V_4 , V_243 , V_244 , 0 , 115200 ) ;
goto V_266;
}
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ )
V_254 = F_158 ( V_254 , V_24 -> V_17 [ V_13 ] ) ;
V_245 = F_157 ( V_4 , V_243 , V_244 , 0 , V_254 / F_159 ( V_24 ) ) ;
if ( ! V_245 )
goto V_266;
if ( V_24 -> V_17 [ V_222 ] && V_4 -> type != V_26 &&
V_4 -> type != V_27 ) {
V_223 = F_149 ( V_24 , V_245 , & V_252 ) ;
if ( abs ( V_223 ) < abs ( V_224 ) ) {
V_255 = V_222 ;
V_248 = V_217 ;
V_249 = V_267 ;
V_224 = V_223 ;
V_220 = V_252 ;
if ( ! V_223 )
goto V_266;
}
}
if ( V_24 -> V_17 [ V_268 ] && F_4 ( V_4 , V_269 ) -> V_9 ) {
V_223 = F_152 ( V_24 , V_245 , V_24 -> V_17 [ V_268 ] , & V_253 ,
& V_252 ) ;
if ( abs ( V_223 ) < abs ( V_224 ) ) {
V_255 = V_268 ;
V_248 = V_217 ;
V_249 = 0 ;
V_224 = V_223 ;
V_229 = V_253 ;
V_220 = V_252 ;
if ( ! V_223 )
goto V_266;
}
}
if ( V_24 -> V_17 [ V_270 ] && F_4 ( V_4 , V_269 ) -> V_9 ) {
V_223 = F_152 ( V_24 , V_245 , V_24 -> V_17 [ V_270 ] , & V_253 ,
& V_252 ) ;
if ( abs ( V_223 ) < abs ( V_224 ) ) {
V_255 = V_270 ;
V_248 = V_217 ;
V_249 = V_271 ;
V_224 = V_223 ;
V_229 = V_253 ;
V_220 = V_252 ;
if ( ! V_224 )
goto V_266;
}
}
V_223 = F_154 ( V_24 , V_245 , & V_250 , & V_252 , & V_251 ) ;
if ( abs ( V_223 ) < abs ( V_224 ) ) {
V_255 = V_19 ;
V_248 = 0 ;
V_224 = V_223 ;
V_230 = V_250 ;
V_220 = V_252 ;
V_231 = V_251 ;
}
V_266:
if ( V_255 >= 0 )
F_57 ( V_4 -> V_14 , L_36 ,
V_24 -> V_16 [ V_255 ] , V_245 , V_224 ) ;
F_11 ( V_24 ) ;
if ( V_255 >= 0 && F_4 ( V_4 , V_272 ) -> V_9 ) {
F_22 ( V_4 , V_269 , V_229 ) ;
F_22 ( V_4 , V_272 , V_249 ) ;
}
F_155 ( V_4 ) ;
F_160 ( V_4 , V_243 -> V_256 , V_245 ) ;
if ( V_255 >= 0 ) {
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
switch ( V_220 + 1 ) {
case 5 : V_246 |= V_273 ; break;
case 7 : V_246 |= V_274 ; break;
case 11 : V_246 |= V_275 ; break;
case 13 : V_246 |= V_276 ; break;
case 16 : V_246 |= V_277 ; break;
case 17 : V_246 |= V_278 ; break;
case 19 : V_246 |= V_279 ; break;
case 27 : V_246 |= V_280 ; break;
}
V_246 |= V_231 ;
F_57 ( V_4 -> V_14 ,
L_37 ,
V_248 , V_246 , V_230 , V_249 , V_229 , V_220 ) ;
F_22 ( V_4 , V_30 , V_248 ) ;
F_22 ( V_4 , V_281 , V_246 ) ;
F_22 ( V_4 , V_282 , V_230 ) ;
if ( F_4 ( V_4 , V_283 ) -> V_9 )
F_22 ( V_4 , V_283 , V_220 | V_284 ) ;
F_161 ( ( 1000000 + ( V_245 - 1 ) ) / V_245 ) ;
} else {
V_248 = V_24 -> V_21 -> V_22 & ( V_217 | V_218 ) ;
V_246 |= F_21 ( V_4 , V_281 ) &
( V_285 | V_286 | V_287 ) ;
F_57 ( V_4 -> V_14 , L_38 , V_248 , V_246 ) ;
F_22 ( V_4 , V_30 , V_248 ) ;
F_22 ( V_4 , V_281 , V_246 ) ;
}
F_39 ( V_4 , V_243 -> V_256 ) ;
V_4 -> V_47 &= ~ V_288 ;
V_24 -> V_65 = false ;
V_8 = F_4 ( V_4 , V_109 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_25 = F_21 ( V_4 , V_109 ) ;
if ( ( V_4 -> V_120 & V_289 ) &&
( V_243 -> V_256 & V_290 ) ) {
V_4 -> V_47 |= V_288 ;
V_24 -> V_65 = true ;
}
V_25 &= ~ ( V_237 | V_238 ) ;
F_22 ( V_4 , V_109 , V_25 ) ;
}
if ( V_4 -> V_120 & V_289 ) {
F_136 ( V_4 , V_4 -> V_61 ) ;
}
V_248 |= V_291 | V_216 |
( V_24 -> V_21 -> V_22 & ~ ( V_217 | V_218 ) ) ;
F_57 ( V_4 -> V_14 , L_39 , V_248 ) ;
F_22 ( V_4 , V_30 , V_248 ) ;
if ( ( V_220 + 1 == 5 ) &&
( V_4 -> type == V_26 || V_4 -> type == V_27 ) ) {
F_161 ( F_117 ( 10 * 1000000 , V_245 ) ) ;
}
switch ( V_243 -> V_256 & V_257 ) {
case V_292 :
V_104 = 7 ;
break;
case V_293 :
V_104 = 8 ;
break;
case V_258 :
V_104 = 9 ;
break;
default:
V_104 = 10 ;
break;
}
if ( V_243 -> V_256 & V_264 )
V_104 ++ ;
if ( V_243 -> V_256 & V_260 )
V_104 ++ ;
V_24 -> V_180 = ( 100 * V_104 * V_294 ) / ( V_245 / 10 ) ;
#ifdef F_20
V_24 -> V_140 = F_117 ( V_24 -> V_132 * 2 * V_24 -> V_180 , 1000 ) ;
F_57 ( V_4 -> V_14 , L_40 ,
V_24 -> V_140 * 1000 / V_294 , V_4 -> V_295 ) ;
if ( V_24 -> V_140 < F_162 ( 20 ) )
V_24 -> V_140 = F_162 ( 20 ) ;
#endif
if ( ( V_243 -> V_256 & V_296 ) != 0 )
F_27 ( V_4 ) ;
F_15 ( V_24 ) ;
if ( F_163 ( V_4 , V_243 -> V_256 ) )
F_142 ( V_4 ) ;
}
static void F_164 ( struct V_2 * V_4 , unsigned int V_33 ,
unsigned int V_297 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_33 ) {
case V_298 :
F_15 ( V_1 ) ;
break;
default:
F_11 ( V_1 ) ;
break;
}
}
static const char * F_165 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_299 :
return L_41 ;
case V_40 :
return L_42 ;
case V_106 :
return L_43 ;
case V_26 :
return L_44 ;
case V_27 :
return L_45 ;
case V_227 :
return L_46 ;
}
return NULL ;
}
static int F_166 ( struct V_2 * V_4 )
{
struct V_1 * V_300 = F_1 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_14 -> V_172 || ( V_4 -> V_120 & V_301 ) ) {
V_4 -> V_10 = F_167 ( V_4 -> V_167 , V_300 -> V_302 ) ;
if ( F_125 ( ! V_4 -> V_10 ) ) {
F_129 ( V_4 -> V_14 , L_47 , V_4 -> line ) ;
return - V_303 ;
}
} else {
V_4 -> V_10 = ( void V_304 * ) ( V_305 ) V_4 -> V_167 ;
}
return 0 ;
}
static void F_168 ( struct V_2 * V_4 )
{
struct V_1 * V_300 = F_1 ( V_4 ) ;
if ( V_4 -> V_14 -> V_172 || ( V_4 -> V_120 & V_301 ) ) {
F_169 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_170 ( V_4 -> V_167 , V_300 -> V_302 ) ;
}
static int F_171 ( struct V_2 * V_4 )
{
struct V_306 * V_307 ;
struct V_1 * V_300 = F_1 ( V_4 ) ;
int V_116 ;
V_307 = F_172 ( V_4 -> V_167 , V_300 -> V_302 ,
F_127 ( V_4 -> V_14 ) ) ;
if ( F_125 ( V_307 == NULL ) ) {
F_129 ( V_4 -> V_14 , L_48 ) ;
return - V_308 ;
}
V_116 = F_166 ( V_4 ) ;
if ( F_125 ( V_116 != 0 ) ) {
F_173 ( V_307 ) ;
return V_116 ;
}
return 0 ;
}
static void F_174 ( struct V_2 * V_4 , int V_120 )
{
if ( V_120 & V_309 ) {
struct V_1 * V_300 = F_1 ( V_4 ) ;
V_4 -> type = V_300 -> V_21 -> type ;
F_171 ( V_4 ) ;
}
}
static int F_175 ( struct V_2 * V_4 , struct V_310 * V_311 )
{
if ( V_311 -> V_312 < 2400 )
return - V_124 ;
return 0 ;
}
static int F_176 ( struct V_1 * V_1 , struct V_111 * V_14 )
{
const char * V_313 [] = {
[ V_19 ] = L_49 ,
[ V_222 ] = L_50 ,
[ V_270 ] = L_51 ,
[ V_268 ] = L_52 ,
} ;
struct V_314 * V_314 ;
unsigned int V_13 ;
if ( V_1 -> V_21 -> type == V_227 )
V_313 [ V_222 ] = L_53 ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
V_314 = F_177 ( V_14 , V_313 [ V_13 ] ) ;
if ( F_178 ( V_314 ) == - V_315 )
return - V_315 ;
if ( F_179 ( V_314 ) && V_13 == V_19 ) {
V_314 = F_177 ( V_14 , L_54 ) ;
if ( F_178 ( V_314 ) == - V_315 )
return - V_315 ;
if ( ! F_179 ( V_314 ) )
goto V_236;
V_314 = F_177 ( V_14 , L_55 ) ;
if ( ! F_179 ( V_314 ) )
goto V_236;
F_129 ( V_14 , L_56 , V_313 [ V_13 ] ,
F_178 ( V_314 ) ) ;
return F_178 ( V_314 ) ;
}
V_236:
if ( F_179 ( V_314 ) )
F_57 ( V_14 , L_56 , V_313 [ V_13 ] ,
F_178 ( V_314 ) ) ;
else
F_57 ( V_14 , L_57 , V_313 [ V_13 ] ,
V_314 , V_314 ) ;
V_1 -> V_16 [ V_13 ] = F_179 ( V_314 ) ? NULL : V_314 ;
}
return 0 ;
}
static const struct V_316 *
F_180 ( const struct V_317 * V_21 )
{
unsigned int V_318 ;
if ( V_21 -> V_318 != V_319 )
return & V_316 [ V_21 -> V_318 ] ;
switch ( V_21 -> type ) {
case V_40 :
V_318 = V_320 ;
break;
case V_299 :
V_318 = V_321 ;
break;
case V_26 :
V_318 = V_322 ;
break;
case V_27 :
V_318 = V_323 ;
break;
case V_106 :
V_318 = V_324 ;
break;
case V_227 :
V_318 = V_325 ;
break;
default:
F_181 ( L_58 ) ;
return NULL ;
}
return & V_316 [ V_318 ] ;
}
static int F_182 ( struct V_326 * V_14 ,
struct V_1 * V_1 , unsigned int V_327 ,
const struct V_317 * V_5 , bool V_328 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_306 * V_307 ;
unsigned int V_13 ;
int V_116 ;
V_1 -> V_21 = V_5 ;
V_4 -> V_53 = & V_329 ;
V_4 -> V_330 = V_331 ;
V_4 -> line = V_327 ;
V_307 = F_183 ( V_14 , V_332 , 0 ) ;
if ( V_307 == NULL )
return - V_192 ;
V_4 -> V_167 = V_307 -> V_333 ;
V_1 -> V_302 = F_184 ( V_307 ) ;
for ( V_13 = 0 ; V_13 < F_77 ( V_1 -> V_160 ) ; ++ V_13 )
V_1 -> V_160 [ V_13 ] = F_185 ( V_14 , V_13 ) ;
if ( V_1 -> V_160 [ 0 ] < 0 )
return - V_303 ;
if ( V_1 -> V_160 [ 1 ] < 0 ) {
V_1 -> V_160 [ 1 ] = V_1 -> V_160 [ 0 ] ;
V_1 -> V_160 [ 2 ] = V_1 -> V_160 [ 0 ] ;
V_1 -> V_160 [ 3 ] = V_1 -> V_160 [ 0 ] ;
}
V_1 -> V_42 = F_180 ( V_5 ) ;
if ( F_125 ( V_1 -> V_42 == NULL ) )
return - V_124 ;
switch ( V_5 -> type ) {
case V_27 :
V_1 -> V_115 = 48 ;
break;
case V_227 :
V_1 -> V_115 = 64 ;
break;
case V_26 :
V_1 -> V_115 = 32 ;
break;
case V_106 :
if ( V_5 -> V_318 == V_334 )
V_1 -> V_115 = 1 ;
else
V_1 -> V_115 = 8 ;
break;
default:
V_1 -> V_115 = 1 ;
break;
}
V_1 -> V_118 = 0 ;
V_1 -> V_335 = V_5 -> V_336
? F_186 ( V_5 -> V_336 )
: V_1 -> V_42 -> V_335 ;
if ( ! V_328 ) {
V_116 = F_176 ( V_1 , & V_14 -> V_14 ) ;
if ( V_116 < 0 )
return V_116 ;
V_4 -> V_14 = & V_14 -> V_14 ;
F_187 ( & V_14 -> V_14 ) ;
}
V_4 -> type = V_5 -> type ;
V_4 -> V_120 = V_337 | V_338 | V_5 -> V_120 ;
V_4 -> V_73 = V_1 -> V_42 -> V_73 ;
if ( V_4 -> type == V_40 ) {
if ( V_1 -> V_302 >= 0x20 )
V_4 -> V_11 = 2 ;
else
V_4 -> V_11 = 1 ;
}
V_4 -> V_175 = V_1 -> V_160 [ V_161 ] ;
V_4 -> V_195 = 0 ;
V_4 -> V_339 = F_3 ;
V_4 -> V_340 = F_8 ;
return 0 ;
}
static void F_188 ( struct V_1 * V_4 )
{
F_189 ( V_4 -> V_4 . V_14 ) ;
}
static void F_190 ( struct V_2 * V_4 , int V_341 )
{
F_35 ( V_4 , V_341 ) ;
}
static void F_191 ( struct V_342 * V_343 , const char * V_24 ,
unsigned V_80 )
{
struct V_1 * V_1 = & V_344 [ V_343 -> V_327 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_104 , V_25 , V_345 ;
unsigned long V_120 ;
int V_346 = 1 ;
F_192 ( V_120 ) ;
#if F_193 ( V_347 )
if ( V_4 -> V_348 )
V_346 = 0 ;
else
#endif
if ( V_349 )
V_346 = F_194 ( & V_4 -> V_122 ) ;
else
F_195 ( & V_4 -> V_122 ) ;
V_25 = F_21 ( V_4 , V_30 ) ;
V_345 = V_291 | V_216 |
( V_1 -> V_21 -> V_22 & ~ ( V_217 | V_218 ) ) |
( V_25 & ( V_217 | V_218 ) ) ;
F_22 ( V_4 , V_30 , V_345 ) ;
F_196 ( V_4 , V_24 , V_80 , F_190 ) ;
V_104 = F_36 ( V_4 ) | F_38 ( V_4 ) ;
while ( ( F_21 ( V_4 , V_41 ) & V_104 ) != V_104 )
F_197 () ;
F_22 ( V_4 , V_30 , V_25 ) ;
if ( V_346 )
F_198 ( & V_4 -> V_122 ) ;
F_199 ( V_120 ) ;
}
static int F_200 ( struct V_342 * V_343 , char * V_350 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_245 = 115200 ;
int V_104 = 8 ;
int V_96 = 'n' ;
int V_351 = 'n' ;
int V_116 ;
if ( V_343 -> V_327 < 0 || V_343 -> V_327 >= V_352 )
return - V_353 ;
V_1 = & V_344 [ V_343 -> V_327 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_53 )
return - V_353 ;
V_116 = F_166 ( V_4 ) ;
if ( F_125 ( V_116 != 0 ) )
return V_116 ;
if ( V_350 )
F_201 ( V_350 , & V_245 , & V_96 , & V_104 , & V_351 ) ;
return F_202 ( V_4 , V_343 , V_245 , V_96 , V_104 , V_351 ) ;
}
static int F_203 ( struct V_326 * V_354 )
{
const struct V_317 * V_21 = F_204 ( & V_354 -> V_14 ) ;
if ( V_355 . V_55 )
return - V_356 ;
V_355 . V_327 = V_354 -> V_357 ;
F_182 ( V_354 , & V_344 [ V_354 -> V_357 ] , V_354 -> V_357 , V_21 , true ) ;
F_200 ( & V_355 , V_358 ) ;
if ( ! strstr ( V_358 , L_59 ) )
V_355 . V_120 |= V_359 ;
F_205 ( & V_355 ) ;
return 0 ;
}
static inline int F_203 ( struct V_326 * V_354 )
{
return - V_124 ;
}
static int F_206 ( struct V_326 * V_14 )
{
struct V_1 * V_4 = F_207 ( V_14 ) ;
F_208 ( & V_360 , & V_4 -> V_4 ) ;
F_188 ( V_4 ) ;
if ( V_4 -> V_4 . V_73 > 1 ) {
F_209 ( & V_14 -> V_14 . V_361 ,
& V_362 . V_113 ) ;
}
if ( V_4 -> V_4 . type == V_26 || V_4 -> V_4 . type == V_27 ) {
F_209 ( & V_14 -> V_14 . V_361 ,
& V_363 . V_113 ) ;
}
return 0 ;
}
static struct V_317 * F_210 ( struct V_326 * V_354 ,
unsigned int * V_364 )
{
struct V_365 * V_366 = V_354 -> V_14 . V_172 ;
const struct V_367 * V_368 ;
struct V_317 * V_5 ;
struct V_1 * V_369 ;
int V_357 ;
if ( ! F_211 ( V_370 ) || ! V_366 )
return NULL ;
V_368 = F_212 ( V_371 , V_366 ) ;
if ( ! V_368 )
return NULL ;
V_5 = F_213 ( & V_354 -> V_14 , sizeof( struct V_317 ) , V_174 ) ;
if ( ! V_5 )
return NULL ;
V_357 = F_214 ( V_366 , L_60 ) ;
if ( V_357 < 0 ) {
F_129 ( & V_354 -> V_14 , L_61 , V_357 ) ;
return NULL ;
}
V_369 = & V_344 [ V_357 ] ;
* V_364 = V_357 ;
V_5 -> type = F_215 ( V_368 -> V_55 ) ;
V_5 -> V_318 = F_216 ( V_368 -> V_55 ) ;
if ( F_217 ( V_366 , L_62 , NULL ) )
V_369 -> V_60 = true ;
return V_5 ;
}
static int F_218 ( struct V_326 * V_14 ,
unsigned int V_327 ,
struct V_317 * V_5 ,
struct V_1 * V_372 )
{
int V_116 ;
if ( F_125 ( V_327 >= V_352 ) ) {
F_52 ( & V_14 -> V_14 , L_63 ,
V_327 + 1 , V_352 ) ;
F_52 ( & V_14 -> V_14 , L_64 ) ;
return - V_124 ;
}
F_219 ( & V_373 ) ;
if ( ! V_360 . V_33 ) {
V_116 = F_220 ( & V_360 ) ;
if ( V_116 ) {
F_221 ( & V_373 ) ;
return V_116 ;
}
}
F_221 ( & V_373 ) ;
V_116 = F_182 ( V_14 , V_372 , V_327 , V_5 , false ) ;
if ( V_116 )
return V_116 ;
V_372 -> V_203 = F_222 ( & V_372 -> V_4 , 0 ) ;
if ( F_179 ( V_372 -> V_203 ) && F_178 ( V_372 -> V_203 ) != - V_374 )
return F_178 ( V_372 -> V_203 ) ;
if ( V_372 -> V_60 ) {
if ( ! F_140 ( F_141 ( V_372 -> V_203 ,
V_207 ) ) ||
! F_140 ( F_141 ( V_372 -> V_203 ,
V_375 ) ) ) {
F_129 ( & V_14 -> V_14 , L_65 ) ;
return - V_124 ;
}
V_372 -> V_4 . V_120 |= V_289 ;
}
V_116 = F_223 ( & V_360 , & V_372 -> V_4 ) ;
if ( V_116 ) {
F_188 ( V_372 ) ;
return V_116 ;
}
return 0 ;
}
static int F_224 ( struct V_326 * V_14 )
{
struct V_317 * V_5 ;
struct V_1 * V_369 ;
unsigned int V_364 ;
int V_116 ;
if ( F_225 ( V_14 ) )
return F_203 ( V_14 ) ;
if ( V_14 -> V_14 . V_172 ) {
V_5 = F_210 ( V_14 , & V_364 ) ;
if ( V_5 == NULL )
return - V_124 ;
} else {
V_5 = V_14 -> V_14 . V_376 ;
if ( V_5 == NULL ) {
F_129 ( & V_14 -> V_14 , L_66 ) ;
return - V_124 ;
}
V_364 = V_14 -> V_357 ;
}
V_369 = & V_344 [ V_364 ] ;
F_226 ( V_14 , V_369 ) ;
V_116 = F_218 ( V_14 , V_364 , V_5 , V_369 ) ;
if ( V_116 )
return V_116 ;
if ( V_369 -> V_4 . V_73 > 1 ) {
V_116 = F_227 ( & V_14 -> V_14 . V_361 ,
& V_362 . V_113 ) ;
if ( V_116 )
return V_116 ;
}
if ( V_369 -> V_4 . type == V_26 || V_369 -> V_4 . type == V_27 ) {
V_116 = F_227 ( & V_14 -> V_14 . V_361 ,
& V_363 . V_113 ) ;
if ( V_116 ) {
if ( V_369 -> V_4 . V_73 > 1 ) {
F_209 ( & V_14 -> V_14 . V_361 ,
& V_362 . V_113 ) ;
}
return V_116 ;
}
}
#ifdef F_228
F_229 () ;
#endif
return 0 ;
}
static T_6 int F_230 ( struct V_111 * V_14 )
{
struct V_1 * V_300 = F_65 ( V_14 ) ;
if ( V_300 )
F_231 ( & V_360 , & V_300 -> V_4 ) ;
return 0 ;
}
static T_6 int F_232 ( struct V_111 * V_14 )
{
struct V_1 * V_300 = F_65 ( V_14 ) ;
if ( V_300 )
F_233 ( & V_360 , & V_300 -> V_4 ) ;
return 0 ;
}
static int T_7 F_234 ( void )
{
F_235 ( L_67 , V_377 ) ;
return F_236 ( & V_378 ) ;
}
static void T_8 F_237 ( void )
{
F_238 ( & V_378 ) ;
if ( V_360 . V_33 )
F_239 ( & V_360 ) ;
}
static int T_7 F_240 ( struct V_379 * V_111 ,
int type )
{
if ( ! V_111 -> V_4 . V_10 )
return - V_353 ;
V_111 -> V_4 . V_339 = F_3 ;
V_111 -> V_4 . V_340 = F_8 ;
V_111 -> V_4 . type = type ;
memcpy ( & V_344 [ 0 ] . V_4 , & V_111 -> V_4 , sizeof( struct V_2 ) ) ;
V_380 . type = type ;
V_344 [ 0 ] . V_21 = & V_380 ;
V_344 [ 0 ] . V_42 = F_180 ( & V_380 ) ;
V_380 . V_22 = F_3 ( & V_344 [ 0 ] . V_4 , V_30 ) ;
F_8 ( & V_344 [ 0 ] . V_4 , V_30 ,
V_291 | V_216 | V_380 . V_22 ) ;
V_111 -> V_381 -> V_382 = F_191 ;
return 0 ;
}
static int T_7 F_241 ( struct V_379 * V_111 ,
const char * V_383 )
{
return F_240 ( V_111 , V_40 ) ;
}
static int T_7 F_242 ( struct V_379 * V_111 ,
const char * V_383 )
{
return F_240 ( V_111 , V_106 ) ;
}
static int T_7 F_243 ( struct V_379 * V_111 ,
const char * V_383 )
{
return F_240 ( V_111 , V_26 ) ;
}
static int T_7 F_244 ( struct V_379 * V_111 ,
const char * V_383 )
{
return F_240 ( V_111 , V_27 ) ;
}
static int T_7 F_245 ( struct V_379 * V_111 ,
const char * V_383 )
{
return F_240 ( V_111 , V_227 ) ;
}
