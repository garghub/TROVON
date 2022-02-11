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
T_1 V_25 = F_21 ( V_4 , V_55 ) ;
V_25 &= ~ ( V_56 | V_57 ) ;
if ( F_1 ( V_4 ) -> V_58 ) {
V_25 |= V_59 ;
F_22 ( V_4 , V_60 ,
F_21 ( V_4 , V_60 ) | V_61 ) ;
V_25 &= ~ V_62 ;
}
F_22 ( V_4 , V_55 , V_25 ) ;
} else if ( F_4 ( V_4 , V_63 ) -> V_9 ) {
T_1 V_47 = F_21 ( V_4 , V_63 ) ;
V_47 |= V_64 | V_65 ;
V_47 &= ~ ( V_66 | V_67 ) ;
F_22 ( V_4 , V_63 , V_47 ) ;
}
}
static int F_40 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
unsigned int V_68 = ( V_24 -> V_42 -> V_69 << 1 ) - 1 ;
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_70 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_70 ) & V_68 ;
V_8 = F_4 ( V_4 , V_71 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_71 ) >> 8 ;
return ! ( F_21 ( V_4 , V_41 ) & V_72 ) ;
}
static int F_41 ( struct V_2 * V_4 )
{
return V_4 -> V_69 - F_40 ( V_4 ) ;
}
static int F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
unsigned int V_68 = ( V_24 -> V_42 -> V_69 << 1 ) - 1 ;
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_73 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_73 ) & V_68 ;
V_8 = F_4 ( V_4 , V_71 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_71 ) & V_68 ;
return ( F_21 ( V_4 , V_41 ) & F_33 ( V_4 ) ) != 0 ;
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_74 * V_34 = & V_4 -> V_33 -> V_34 ;
unsigned int V_75 = F_44 ( V_4 ) ;
unsigned short V_47 ;
unsigned short V_25 ;
int V_76 ;
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
V_76 = F_41 ( V_4 ) ;
do {
unsigned char V_48 ;
if ( V_4 -> V_77 ) {
V_48 = V_4 -> V_77 ;
V_4 -> V_77 = 0 ;
} else if ( ! F_23 ( V_34 ) && ! V_75 ) {
V_48 = V_34 -> V_78 [ V_34 -> V_79 ] ;
V_34 -> V_79 = ( V_34 -> V_79 + 1 ) & ( V_80 - 1 ) ;
} else {
break;
}
F_22 ( V_4 , V_51 , V_48 ) ;
V_4 -> V_81 . V_82 ++ ;
} while ( -- V_76 > 0 );
F_29 ( V_4 , F_37 ( V_4 ) ) ;
if ( F_45 ( V_34 ) < V_83 )
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
struct V_84 * V_85 = & V_4 -> V_33 -> V_4 ;
int V_13 , V_76 , V_86 = 0 ;
unsigned short V_47 ;
unsigned char V_87 ;
V_47 = F_21 ( V_4 , V_41 ) ;
if ( ! ( V_47 & F_33 ( V_4 ) ) )
return;
while ( 1 ) {
V_76 = F_48 ( V_85 , F_42 ( V_4 ) ) ;
if ( V_76 == 0 )
break;
if ( V_4 -> type == V_40 ) {
char V_48 = F_21 ( V_4 , V_50 ) ;
if ( F_49 ( V_4 , V_48 ) )
V_76 = 0 ;
else
F_50 ( V_85 , V_48 , V_88 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_76 ; V_13 ++ ) {
char V_48 = F_21 ( V_4 , V_50 ) ;
V_47 = F_21 ( V_4 , V_41 ) ;
if ( F_49 ( V_4 , V_48 ) ) {
V_76 -- ; V_13 -- ;
continue;
}
if ( V_47 & F_51 ( V_4 ) ) {
V_87 = V_89 ;
V_4 -> V_81 . V_90 ++ ;
F_52 ( V_4 -> V_14 , L_2 ) ;
} else if ( V_47 & F_53 ( V_4 ) ) {
V_87 = V_91 ;
V_4 -> V_81 . V_92 ++ ;
F_52 ( V_4 -> V_14 , L_3 ) ;
} else
V_87 = V_88 ;
F_50 ( V_85 , V_48 , V_87 ) ;
}
}
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_34 ( V_4 ) ) ;
V_86 += V_76 ;
V_4 -> V_81 . V_93 += V_76 ;
}
if ( V_86 ) {
F_54 ( V_85 ) ;
} else {
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_34 ( V_4 ) ) ;
}
}
static int F_55 ( struct V_2 * V_4 )
{
int V_86 = 0 ;
unsigned short V_47 = F_21 ( V_4 , V_41 ) ;
struct V_84 * V_85 = & V_4 -> V_33 -> V_4 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_47 & V_24 -> V_42 -> V_43 ) {
V_4 -> V_81 . V_94 ++ ;
if ( F_50 ( V_85 , 0 , V_95 ) )
V_86 ++ ;
F_52 ( V_4 -> V_14 , L_4 ) ;
}
if ( V_47 & F_51 ( V_4 ) ) {
V_4 -> V_81 . V_90 ++ ;
if ( F_50 ( V_85 , 0 , V_89 ) )
V_86 ++ ;
F_52 ( V_4 -> V_14 , L_2 ) ;
}
if ( V_47 & F_53 ( V_4 ) ) {
V_4 -> V_81 . V_92 ++ ;
if ( F_50 ( V_85 , 0 , V_91 ) )
V_86 ++ ;
F_52 ( V_4 -> V_14 , L_3 ) ;
}
if ( V_86 )
F_54 ( V_85 ) ;
return V_86 ;
}
static int F_56 ( struct V_2 * V_4 )
{
struct V_84 * V_85 = & V_4 -> V_33 -> V_4 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_86 = 0 ;
T_1 V_47 ;
V_8 = F_4 ( V_4 , V_24 -> V_42 -> V_96 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
V_47 = F_21 ( V_4 , V_24 -> V_42 -> V_96 ) ;
if ( V_47 & V_24 -> V_42 -> V_43 ) {
V_47 &= ~ V_24 -> V_42 -> V_43 ;
F_22 ( V_4 , V_24 -> V_42 -> V_96 , V_47 ) ;
V_4 -> V_81 . V_94 ++ ;
F_50 ( V_85 , 0 , V_95 ) ;
F_54 ( V_85 ) ;
F_57 ( V_4 -> V_14 , L_4 ) ;
V_86 ++ ;
}
return V_86 ;
}
static int F_58 ( struct V_2 * V_4 )
{
int V_86 = 0 ;
unsigned short V_47 = F_21 ( V_4 , V_41 ) ;
struct V_84 * V_85 = & V_4 -> V_33 -> V_4 ;
if ( F_59 ( V_4 ) )
return 0 ;
if ( V_47 & F_60 ( V_4 ) ) {
V_4 -> V_81 . V_97 ++ ;
if ( F_50 ( V_85 , 0 , V_98 ) )
V_86 ++ ;
F_57 ( V_4 -> V_14 , L_5 ) ;
}
if ( V_86 )
F_54 ( V_85 ) ;
V_86 += F_56 ( V_4 ) ;
return V_86 ;
}
static int F_61 ( struct V_2 * V_4 , int V_99 )
{
unsigned int V_100 ;
if ( V_99 < 1 )
V_99 = 1 ;
if ( V_99 >= V_4 -> V_69 )
V_99 = V_4 -> V_69 ;
if ( F_4 ( V_4 , V_101 ) -> V_9 ) {
F_22 ( V_4 , V_101 , V_99 ) ;
return V_99 ;
}
switch ( V_4 -> type ) {
case V_102 :
if ( V_99 < 4 ) {
V_100 = 0 ;
V_99 = 1 ;
} else if ( V_99 < 8 ) {
V_100 = V_103 ;
V_99 = 4 ;
} else if ( V_99 < 14 ) {
V_100 = V_104 ;
V_99 = 8 ;
} else {
V_100 = V_103 | V_104 ;
V_99 = 14 ;
}
break;
case V_26 :
case V_27 :
if ( V_99 < 16 ) {
V_100 = 0 ;
V_99 = 1 ;
} else if ( V_99 < 32 ) {
V_100 = V_103 ;
V_99 = 16 ;
} else if ( V_99 < 48 ) {
V_100 = V_104 ;
V_99 = 32 ;
} else {
V_100 = V_103 | V_104 ;
V_99 = 48 ;
}
break;
default:
F_7 ( 1 , L_6 ) ;
return 1 ;
}
F_22 ( V_4 , V_105 ,
( F_21 ( V_4 , V_105 ) &
~ ( V_104 | V_103 ) ) | V_100 ) ;
return V_99 ;
}
static int F_62 ( struct V_2 * V_4 )
{
if ( F_4 ( V_4 , V_101 ) -> V_9 )
return F_21 ( V_4 , V_101 ) != 0 ;
else
return ( F_21 ( V_4 , V_105 ) &
( V_103 | V_104 ) ) != 0 ;
}
static void F_63 ( unsigned long V_106 )
{
struct V_1 * V_24 = (struct V_1 * ) V_106 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
F_57 ( V_4 -> V_14 , L_7 ) ;
F_61 ( V_4 , 1 ) ;
}
static T_2 F_64 ( struct V_107 * V_14 ,
struct V_108 * V_109 ,
char * V_78 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_110 = F_1 ( V_4 ) ;
return sprintf ( V_78 , L_8 , V_110 -> V_111 ) ;
}
static T_2 F_66 ( struct V_107 * V_14 ,
struct V_108 * V_109 ,
const char * V_78 ,
T_3 V_76 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_110 = F_1 ( V_4 ) ;
long V_112 ;
if ( F_67 ( V_78 , 0 , & V_112 ) == - V_113 )
return - V_113 ;
V_110 -> V_111 = F_61 ( V_4 , V_112 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
F_61 ( V_4 , 1 ) ;
return V_76 ;
}
static T_2 F_68 ( struct V_107 * V_14 ,
struct V_108 * V_109 ,
char * V_78 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_110 = F_1 ( V_4 ) ;
return sprintf ( V_78 , L_8 , V_110 -> V_114 ) ;
}
static T_2 F_69 ( struct V_107 * V_14 ,
struct V_108 * V_109 ,
const char * V_78 ,
T_3 V_76 )
{
struct V_2 * V_4 = F_65 ( V_14 ) ;
struct V_1 * V_110 = F_1 ( V_4 ) ;
long V_112 ;
if ( F_67 ( V_78 , 0 , & V_112 ) == - V_113 )
return - V_113 ;
V_110 -> V_114 = V_112 ;
F_61 ( V_4 , 1 ) ;
if ( V_112 > 0 )
F_70 ( & V_110 -> V_115 , F_63 ,
( unsigned long ) V_110 ) ;
return V_76 ;
}
static void F_71 ( void * V_106 )
{
struct V_1 * V_24 = V_106 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_74 * V_34 = & V_4 -> V_33 -> V_34 ;
unsigned long V_116 ;
F_57 ( V_4 -> V_14 , L_9 , V_117 , V_4 -> line ) ;
F_72 ( & V_4 -> V_118 , V_116 ) ;
V_34 -> V_79 += V_24 -> V_119 ;
V_34 -> V_79 &= V_80 - 1 ;
V_4 -> V_81 . V_82 += V_24 -> V_119 ;
if ( F_45 ( V_34 ) < V_83 )
F_46 ( V_4 ) ;
if ( ! F_23 ( V_34 ) ) {
V_24 -> V_35 = 0 ;
F_25 ( & V_24 -> V_36 ) ;
} else {
V_24 -> V_35 = - V_113 ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
T_1 V_25 = F_21 ( V_4 , V_30 ) ;
F_22 ( V_4 , V_30 , V_25 & ~ V_37 ) ;
}
}
F_73 ( & V_4 -> V_118 , V_116 ) ;
}
static int F_74 ( struct V_1 * V_24 , void * V_78 , T_3 V_76 )
{
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_84 * V_85 = & V_4 -> V_33 -> V_4 ;
int V_86 ;
V_86 = F_75 ( V_85 , V_78 , V_76 ) ;
if ( V_86 < V_76 )
V_4 -> V_81 . V_120 ++ ;
V_4 -> V_81 . V_93 += V_86 ;
return V_86 ;
}
static int F_76 ( struct V_1 * V_24 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_77 ( V_24 -> V_121 ) ; V_13 ++ )
if ( V_24 -> V_122 == V_24 -> V_121 [ V_13 ] )
return V_13 ;
return - 1 ;
}
static void F_78 ( struct V_1 * V_24 , bool V_123 )
{
struct V_124 * V_125 = V_24 -> V_126 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
unsigned long V_116 ;
F_72 ( & V_4 -> V_118 , V_116 ) ;
V_24 -> V_126 = NULL ;
V_24 -> V_121 [ 0 ] = V_24 -> V_121 [ 1 ] = - V_113 ;
F_73 ( & V_4 -> V_118 , V_116 ) ;
F_79 ( V_125 ) ;
F_80 ( V_125 -> V_107 -> V_14 , V_24 -> V_127 * 2 , V_24 -> V_128 [ 0 ] ,
F_81 ( & V_24 -> V_129 [ 0 ] ) ) ;
F_82 ( V_125 ) ;
if ( V_123 )
F_27 ( V_4 ) ;
}
static void F_83 ( void * V_106 )
{
struct V_1 * V_24 = V_106 ;
struct V_124 * V_125 = V_24 -> V_126 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_130 * V_131 ;
unsigned long V_116 ;
int V_132 , V_76 = 0 ;
F_57 ( V_4 -> V_14 , L_10 , V_117 , V_4 -> line ,
V_24 -> V_122 ) ;
F_72 ( & V_4 -> V_118 , V_116 ) ;
V_132 = F_76 ( V_24 ) ;
if ( V_132 >= 0 )
V_76 = F_74 ( V_24 , V_24 -> V_128 [ V_132 ] , V_24 -> V_127 ) ;
F_84 ( & V_24 -> V_133 , V_134 + V_24 -> V_135 ) ;
if ( V_76 )
F_54 ( & V_4 -> V_33 -> V_4 ) ;
V_131 = F_85 ( V_24 -> V_126 , & V_24 -> V_129 [ V_132 ] , 1 ,
V_136 ,
V_137 | V_138 ) ;
if ( ! V_131 )
goto V_139;
V_131 -> V_140 = F_83 ;
V_131 -> V_141 = V_24 ;
V_24 -> V_121 [ V_132 ] = F_86 ( V_131 ) ;
if ( F_24 ( V_24 -> V_121 [ V_132 ] ) )
goto V_139;
V_24 -> V_122 = V_24 -> V_121 [ ! V_132 ] ;
F_87 ( V_125 ) ;
F_73 ( & V_4 -> V_118 , V_116 ) ;
F_57 ( V_4 -> V_14 , L_11 ,
V_117 , V_24 -> V_121 [ V_132 ] , V_132 , V_24 -> V_122 ) ;
return;
V_139:
F_73 ( & V_4 -> V_118 , V_116 ) ;
F_88 ( V_4 -> V_14 , L_12 ) ;
F_78 ( V_24 , true ) ;
}
static void F_89 ( struct V_1 * V_24 , bool V_123 )
{
struct V_124 * V_125 = V_24 -> V_31 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
unsigned long V_116 ;
F_72 ( & V_4 -> V_118 , V_116 ) ;
V_24 -> V_31 = NULL ;
V_24 -> V_35 = - V_113 ;
F_73 ( & V_4 -> V_118 , V_116 ) ;
F_79 ( V_125 ) ;
F_90 ( V_125 -> V_107 -> V_14 , V_24 -> V_142 , V_80 ,
V_143 ) ;
F_82 ( V_125 ) ;
if ( V_123 )
F_19 ( V_4 ) ;
}
static void F_91 ( struct V_1 * V_24 )
{
struct V_124 * V_125 = V_24 -> V_126 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
struct V_144 * V_145 = & V_24 -> V_129 [ V_13 ] ;
struct V_130 * V_131 ;
V_131 = F_85 ( V_125 ,
V_145 , 1 , V_136 ,
V_137 | V_138 ) ;
if ( ! V_131 )
goto V_139;
V_131 -> V_140 = F_83 ;
V_131 -> V_141 = V_24 ;
V_24 -> V_121 [ V_13 ] = F_86 ( V_131 ) ;
if ( F_24 ( V_24 -> V_121 [ V_13 ] ) )
goto V_139;
}
V_24 -> V_122 = V_24 -> V_121 [ 0 ] ;
F_87 ( V_125 ) ;
return;
V_139:
if ( V_13 )
F_79 ( V_125 ) ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
V_24 -> V_121 [ V_13 ] = - V_113 ;
V_24 -> V_122 = - V_113 ;
F_78 ( V_24 , true ) ;
}
static void F_92 ( struct V_146 * V_147 )
{
struct V_1 * V_24 = F_2 ( V_147 , struct V_1 , V_36 ) ;
struct V_130 * V_131 ;
struct V_124 * V_125 = V_24 -> V_31 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_74 * V_34 = & V_4 -> V_33 -> V_34 ;
T_4 V_78 ;
F_93 ( & V_4 -> V_118 ) ;
V_78 = V_24 -> V_142 + ( V_34 -> V_79 & ( V_80 - 1 ) ) ;
V_24 -> V_119 = F_94 (unsigned int,
CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE),
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE)) ;
F_95 ( & V_4 -> V_118 ) ;
V_131 = F_96 ( V_125 , V_78 , V_24 -> V_119 ,
V_148 ,
V_137 | V_138 ) ;
if ( ! V_131 ) {
F_88 ( V_4 -> V_14 , L_13 ) ;
F_89 ( V_24 , true ) ;
return;
}
F_97 ( V_125 -> V_107 -> V_14 , V_78 , V_24 -> V_119 ,
V_143 ) ;
F_93 ( & V_4 -> V_118 ) ;
V_131 -> V_140 = F_71 ;
V_131 -> V_141 = V_24 ;
F_95 ( & V_4 -> V_118 ) ;
V_24 -> V_35 = F_86 ( V_131 ) ;
if ( F_24 ( V_24 -> V_35 ) ) {
F_88 ( V_4 -> V_14 , L_14 ) ;
F_89 ( V_24 , true ) ;
return;
}
F_57 ( V_4 -> V_14 , L_15 ,
V_117 , V_34 -> V_78 , V_34 -> V_79 , V_34 -> V_149 , V_24 -> V_35 ) ;
F_87 ( V_125 ) ;
}
static void F_98 ( unsigned long V_106 )
{
struct V_1 * V_24 = (struct V_1 * ) V_106 ;
struct V_124 * V_125 = V_24 -> V_126 ;
struct V_2 * V_4 = & V_24 -> V_4 ;
struct V_150 V_33 ;
enum V_151 V_47 ;
unsigned long V_116 ;
unsigned int V_152 ;
int V_132 , V_76 ;
T_1 V_29 ;
F_57 ( V_4 -> V_14 , L_16 ) ;
F_72 ( & V_4 -> V_118 , V_116 ) ;
V_132 = F_76 ( V_24 ) ;
if ( V_132 < 0 ) {
F_73 ( & V_4 -> V_118 , V_116 ) ;
return;
}
V_47 = F_99 ( V_24 -> V_126 , V_24 -> V_122 , & V_33 ) ;
if ( V_47 == V_153 ) {
F_73 ( & V_4 -> V_118 , V_116 ) ;
F_57 ( V_4 -> V_14 , L_17 ,
V_24 -> V_122 , V_132 ) ;
return;
}
F_100 ( V_125 ) ;
V_47 = F_99 ( V_24 -> V_126 , V_24 -> V_122 , & V_33 ) ;
if ( V_47 == V_153 ) {
F_73 ( & V_4 -> V_118 , V_116 ) ;
F_57 ( V_4 -> V_14 , L_18 ) ;
return;
}
F_79 ( V_24 -> V_126 ) ;
V_152 = F_101 ( & V_24 -> V_129 [ V_132 ] ) - V_33 . V_154 ;
if ( V_152 ) {
V_76 = F_74 ( V_24 , V_24 -> V_128 [ V_132 ] , V_152 ) ;
if ( V_76 )
F_54 ( & V_4 -> V_33 -> V_4 ) ;
}
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
F_91 ( V_24 ) ;
V_29 = F_21 ( V_4 , V_30 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
V_29 &= ~ V_38 ;
F_102 ( V_24 -> V_155 [ V_156 ] ) ;
}
F_22 ( V_4 , V_30 , V_29 | V_20 ) ;
F_73 ( & V_4 -> V_118 , V_116 ) ;
}
static struct V_124 * F_103 ( struct V_2 * V_4 ,
enum V_157 V_158 )
{
struct V_124 * V_125 ;
struct V_159 V_21 ;
int V_160 ;
V_125 = F_104 ( V_4 -> V_14 ,
V_158 == V_148 ? L_19 : L_20 ) ;
if ( ! V_125 ) {
F_88 ( V_4 -> V_14 ,
L_21 ) ;
return NULL ;
}
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_161 = V_158 ;
if ( V_158 == V_148 ) {
V_21 . V_162 = V_4 -> V_163 +
( F_4 ( V_4 , V_51 ) -> V_6 << V_4 -> V_11 ) ;
V_21 . V_164 = V_165 ;
} else {
V_21 . V_166 = V_4 -> V_163 +
( F_4 ( V_4 , V_50 ) -> V_6 << V_4 -> V_11 ) ;
V_21 . V_167 = V_165 ;
}
V_160 = F_105 ( V_125 , & V_21 ) ;
if ( V_160 ) {
F_88 ( V_4 -> V_14 , L_22 , V_160 ) ;
F_82 ( V_125 ) ;
return NULL ;
}
return V_125 ;
}
static void F_106 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
struct V_124 * V_125 ;
F_57 ( V_4 -> V_14 , L_23 , V_117 , V_4 -> line ) ;
if ( ! V_4 -> V_14 -> V_168 )
return;
V_24 -> V_35 = - V_113 ;
V_125 = F_103 ( V_4 , V_148 ) ;
F_57 ( V_4 -> V_14 , L_24 , V_117 , V_125 ) ;
if ( V_125 ) {
V_24 -> V_31 = V_125 ;
V_24 -> V_142 = F_107 ( V_125 -> V_107 -> V_14 ,
V_4 -> V_33 -> V_34 . V_78 ,
V_80 ,
V_143 ) ;
if ( F_108 ( V_125 -> V_107 -> V_14 , V_24 -> V_142 ) ) {
F_88 ( V_4 -> V_14 , L_25 ) ;
F_82 ( V_125 ) ;
V_24 -> V_31 = NULL ;
} else {
F_57 ( V_4 -> V_14 , L_26 ,
V_117 , V_80 ,
V_4 -> V_33 -> V_34 . V_78 , & V_24 -> V_142 ) ;
}
F_109 ( & V_24 -> V_36 , F_92 ) ;
}
V_125 = F_103 ( V_4 , V_136 ) ;
F_57 ( V_4 -> V_14 , L_27 , V_117 , V_125 ) ;
if ( V_125 ) {
unsigned int V_13 ;
T_4 V_169 ;
void * V_78 ;
V_24 -> V_126 = V_125 ;
V_24 -> V_127 = 2 * F_110 ( T_3 , 16 , V_4 -> V_69 ) ;
V_78 = F_111 ( V_125 -> V_107 -> V_14 , V_24 -> V_127 * 2 ,
& V_169 , V_170 ) ;
if ( ! V_78 ) {
F_88 ( V_4 -> V_14 ,
L_28 ) ;
F_82 ( V_125 ) ;
V_24 -> V_126 = NULL ;
return;
}
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
struct V_144 * V_145 = & V_24 -> V_129 [ V_13 ] ;
F_112 ( V_145 , 1 ) ;
V_24 -> V_128 [ V_13 ] = V_78 ;
F_81 ( V_145 ) = V_169 ;
F_101 ( V_145 ) = V_24 -> V_127 ;
V_78 += V_24 -> V_127 ;
V_169 += V_24 -> V_127 ;
}
F_70 ( & V_24 -> V_133 , F_98 , ( unsigned long ) V_24 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 )
F_91 ( V_24 ) ;
}
}
static void F_113 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_24 -> V_31 )
F_89 ( V_24 , false ) ;
if ( V_24 -> V_126 )
F_78 ( V_24 , false ) ;
}
static inline void F_106 ( struct V_2 * V_4 )
{
}
static inline void F_113 ( struct V_2 * V_4 )
{
}
static T_5 F_114 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
#ifdef F_20
if ( V_24 -> V_126 ) {
T_1 V_29 = F_21 ( V_4 , V_30 ) ;
T_1 V_173 = F_21 ( V_4 , V_41 ) ;
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
F_115 ( V_171 ) ;
V_29 |= V_38 ;
} else {
V_29 &= ~ V_20 ;
F_91 ( V_24 ) ;
}
F_22 ( V_4 , V_30 , V_29 ) ;
F_22 ( V_4 , V_41 ,
V_173 & ~ ( V_174 | F_33 ( V_4 ) ) ) ;
F_57 ( V_4 -> V_14 , L_29 ,
V_134 , V_24 -> V_135 ) ;
F_84 ( & V_24 -> V_133 , V_134 + V_24 -> V_135 ) ;
return V_175 ;
}
#endif
if ( V_24 -> V_111 > 1 && V_24 -> V_114 > 0 ) {
if ( ! F_62 ( V_4 ) )
F_61 ( V_4 , V_24 -> V_111 ) ;
F_84 ( & V_24 -> V_115 , V_134 + F_116 (
V_24 -> V_176 * V_24 -> V_114 , 1000 ) ) ;
}
F_47 ( V_172 ) ;
return V_175 ;
}
static T_5 F_117 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
unsigned long V_116 ;
F_72 ( & V_4 -> V_118 , V_116 ) ;
F_43 ( V_4 ) ;
F_73 ( & V_4 -> V_118 , V_116 ) ;
return V_175 ;
}
static T_5 F_118 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_4 -> type == V_40 ) {
if ( F_55 ( V_4 ) ) {
F_21 ( V_4 , V_41 ) ;
F_29 ( V_4 , F_34 ( V_4 ) ) ;
}
} else {
F_56 ( V_4 ) ;
if ( ! V_24 -> V_126 )
F_47 ( V_172 ) ;
}
F_29 ( V_4 , F_32 ( V_4 ) ) ;
if ( ! V_24 -> V_31 )
F_117 ( V_171 , V_172 ) ;
return V_175 ;
}
static T_5 F_119 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
F_58 ( V_4 ) ;
F_29 ( V_4 , F_120 ( V_4 ) ) ;
return V_175 ;
}
static T_5 F_121 ( int V_171 , void * V_172 )
{
unsigned short V_177 , V_178 , V_179 , V_180 = 0 ;
struct V_2 * V_4 = V_172 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
T_5 V_160 = V_181 ;
V_177 = F_21 ( V_4 , V_41 ) ;
V_178 = F_21 ( V_4 , V_30 ) ;
if ( V_24 -> V_42 -> V_96 == V_41 )
V_180 = V_177 ;
else if ( F_4 ( V_4 , V_24 -> V_42 -> V_96 ) -> V_9 )
V_180 = F_21 ( V_4 , V_24 -> V_42 -> V_96 ) ;
V_179 = V_178 & F_18 ( V_4 ) ;
if ( ( V_177 & F_36 ( V_4 ) ) && ( V_178 & V_37 ) &&
! V_24 -> V_31 )
V_160 = F_117 ( V_171 , V_172 ) ;
if ( ( ( V_177 & F_33 ( V_4 ) ) || V_24 -> V_126 ) &&
( V_178 & V_20 ) )
V_160 = F_114 ( V_171 , V_172 ) ;
if ( ( V_177 & F_31 ( V_4 ) ) && V_179 )
V_160 = F_118 ( V_171 , V_172 ) ;
if ( ( V_177 & F_60 ( V_4 ) ) && V_179 )
V_160 = F_119 ( V_171 , V_172 ) ;
if ( V_180 & V_24 -> V_42 -> V_43 ) {
F_56 ( V_4 ) ;
V_160 = V_175 ;
}
return V_160 ;
}
static int F_122 ( struct V_1 * V_4 )
{
struct V_2 * V_182 = & V_4 -> V_4 ;
int V_13 , V_183 , V_160 = 0 ;
for ( V_13 = V_183 = 0 ; V_13 < V_184 ; V_13 ++ , V_183 ++ ) {
const struct V_185 * V_131 ;
int V_171 ;
if ( F_123 ( V_4 ) ) {
V_13 = V_186 ;
V_171 = V_182 -> V_171 ;
} else {
V_171 = V_4 -> V_155 [ V_13 ] ;
if ( F_124 ( V_171 < 0 ) )
continue;
}
V_131 = V_185 + V_13 ;
V_4 -> V_187 [ V_183 ] = F_125 ( V_170 , L_30 ,
F_126 ( V_182 -> V_14 ) , V_131 -> V_131 ) ;
if ( ! V_4 -> V_187 [ V_183 ] ) {
V_160 = - V_188 ;
goto V_189;
}
V_160 = F_127 ( V_171 , V_131 -> V_190 , V_182 -> V_191 ,
V_4 -> V_187 [ V_183 ] , V_4 ) ;
if ( F_124 ( V_160 ) ) {
F_128 ( V_182 -> V_14 , L_31 , V_131 -> V_131 ) ;
goto V_192;
}
}
return 0 ;
V_192:
while ( -- V_13 >= 0 )
F_129 ( V_4 -> V_155 [ V_13 ] , V_4 ) ;
V_189:
while ( -- V_183 >= 0 )
F_130 ( V_4 -> V_187 [ V_183 ] ) ;
return V_160 ;
}
static void F_131 ( struct V_1 * V_4 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_184 ; V_13 ++ ) {
int V_171 = V_4 -> V_155 [ V_13 ] ;
if ( F_124 ( V_171 < 0 ) )
continue;
F_129 ( V_4 -> V_155 [ V_13 ] , V_4 ) ;
F_130 ( V_4 -> V_187 [ V_13 ] ) ;
if ( F_123 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_132 ( struct V_2 * V_4 )
{
unsigned short V_47 = F_21 ( V_4 , V_41 ) ;
unsigned short V_193 = F_40 ( V_4 ) ;
return ( V_47 & F_38 ( V_4 ) ) && ! V_193 ? V_194 : 0 ;
}
static void F_133 ( struct V_2 * V_4 , bool V_33 )
{
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
T_1 V_195 = F_21 ( V_4 , V_60 ) ;
if ( V_33 )
V_195 &= ~ V_61 ;
else
V_195 |= V_61 ;
F_22 ( V_4 , V_60 , V_195 ) ;
F_22 ( V_4 , V_55 ,
F_21 ( V_4 , V_55 ) | V_59 ) ;
} else if ( F_4 ( V_4 , V_63 ) -> V_9 ) {
T_1 V_25 = F_21 ( V_4 , V_63 ) ;
if ( V_33 )
V_25 &= ~ V_65 ;
else
V_25 |= V_65 ;
F_22 ( V_4 , V_63 , V_25 ) ;
}
}
static bool F_134 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
return ! ( F_21 ( V_4 , V_60 ) & V_196 ) ;
} else if ( F_4 ( V_4 , V_63 ) -> V_9 ) {
return ! ( F_21 ( V_4 , V_63 ) & V_197 ) ;
}
return true ;
}
static void F_135 ( struct V_2 * V_4 , unsigned int V_198 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
if ( V_198 & V_199 ) {
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_105 ) ;
if ( V_8 -> V_9 )
F_22 ( V_4 , V_105 ,
F_21 ( V_4 , V_105 ) |
V_200 ) ;
}
F_136 ( V_24 -> V_201 , V_198 ) ;
if ( ! V_24 -> V_58 )
return;
if ( ! ( V_198 & V_202 ) ) {
F_22 ( V_4 , V_105 ,
F_21 ( V_4 , V_105 ) & ~ V_203 ) ;
F_133 ( V_4 , 0 ) ;
} else if ( V_24 -> V_204 ) {
if ( V_4 -> type == V_26 || V_4 -> type == V_27 ) {
F_22 ( V_4 , V_55 ,
F_21 ( V_4 , V_55 ) & ~ V_59 ) ;
}
F_22 ( V_4 , V_105 ,
F_21 ( V_4 , V_105 ) | V_203 ) ;
} else {
F_133 ( V_4 , 1 ) ;
}
}
static unsigned int F_137 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
struct V_205 * V_201 = V_24 -> V_201 ;
unsigned int V_198 = 0 ;
F_138 ( V_201 , & V_198 ) ;
if ( V_24 -> V_204 ) {
if ( F_134 ( V_4 ) )
V_198 |= V_206 ;
} else if ( F_139 ( F_140 ( V_201 , V_207 ) ) ) {
V_198 |= V_206 ;
}
if ( F_139 ( F_140 ( V_201 , V_208 ) ) )
V_198 |= V_209 ;
if ( F_139 ( F_140 ( V_201 , V_210 ) ) )
V_198 |= V_211 ;
return V_198 ;
}
static void F_141 ( struct V_2 * V_4 )
{
F_142 ( F_1 ( V_4 ) -> V_201 ) ;
}
static void F_143 ( struct V_2 * V_4 , int V_212 )
{
unsigned short V_22 , V_213 ;
if ( ! F_4 ( V_4 , V_63 ) -> V_9 ) {
return;
}
V_213 = F_21 ( V_4 , V_63 ) ;
V_22 = F_21 ( V_4 , V_30 ) ;
if ( V_212 == - 1 ) {
V_213 = ( V_213 | V_214 ) & ~ V_215 ;
V_22 &= ~ V_216 ;
} else {
V_213 = ( V_213 | V_215 ) & ~ V_214 ;
V_22 |= V_216 ;
}
F_22 ( V_4 , V_63 , V_213 ) ;
F_22 ( V_4 , V_30 , V_22 ) ;
}
static int F_144 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
int V_160 ;
F_57 ( V_4 -> V_14 , L_9 , V_117 , V_4 -> line ) ;
V_160 = F_122 ( V_24 ) ;
if ( F_124 ( V_160 < 0 ) )
return V_160 ;
F_106 ( V_4 ) ;
return 0 ;
}
static void F_145 ( struct V_2 * V_4 )
{
struct V_1 * V_24 = F_1 ( V_4 ) ;
unsigned long V_116 ;
T_1 V_29 ;
F_57 ( V_4 -> V_14 , L_9 , V_117 , V_4 -> line ) ;
V_24 -> V_204 = false ;
F_146 ( F_1 ( V_4 ) -> V_201 ) ;
F_72 ( & V_4 -> V_118 , V_116 ) ;
F_28 ( V_4 ) ;
F_26 ( V_4 ) ;
V_29 = F_21 ( V_4 , V_30 ) ;
F_22 ( V_4 , V_30 , V_29 & ( V_217 | V_218 ) ) ;
F_73 ( & V_4 -> V_118 , V_116 ) ;
#ifdef F_20
if ( V_24 -> V_126 ) {
F_57 ( V_4 -> V_14 , L_32 , V_117 ,
V_4 -> line ) ;
F_147 ( & V_24 -> V_133 ) ;
}
#endif
F_113 ( V_4 ) ;
F_131 ( V_24 ) ;
}
static int F_148 ( struct V_1 * V_24 , unsigned int V_219 ,
unsigned int * V_220 )
{
unsigned long V_221 = V_24 -> V_17 [ V_222 ] ;
int V_223 , V_224 = V_225 ;
unsigned int V_226 ;
if ( V_24 -> V_4 . type != V_227 )
V_221 *= 2 ;
F_149 (sr, s) {
V_223 = F_150 ( V_221 , V_226 ) - V_219 ;
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
static int F_151 ( struct V_1 * V_24 , unsigned int V_219 ,
unsigned long V_221 , unsigned int * V_228 ,
unsigned int * V_220 )
{
int V_223 , V_224 = V_225 ;
unsigned int V_226 , V_229 ;
if ( V_24 -> V_4 . type != V_227 )
V_221 *= 2 ;
F_149 (sr, s) {
V_229 = F_150 ( V_221 , V_226 * V_219 ) ;
V_229 = F_152 ( V_229 , 1U , 65535U ) ;
V_223 = F_150 ( V_221 , V_226 * V_229 ) - V_219 ;
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
static int F_153 ( struct V_1 * V_24 , unsigned int V_219 ,
unsigned int * V_230 , unsigned int * V_220 ,
unsigned int * V_231 )
{
unsigned long V_221 = V_24 -> V_17 [ V_19 ] ;
unsigned int V_226 , V_232 , V_233 , V_234 , V_48 ;
int V_223 , V_224 = V_225 ;
if ( V_24 -> V_4 . type != V_227 )
V_221 *= 2 ;
F_149 (sr, s) {
for ( V_48 = 0 ; V_48 <= 3 ; V_48 ++ ) {
V_233 = V_226 * ( 1 << ( 2 * V_48 + 1 ) ) ;
if ( V_219 > V_235 / V_233 )
break;
V_234 = V_233 * V_219 ;
V_232 = F_150 ( V_221 , V_234 ) ;
V_232 = F_152 ( V_232 , 1U , 256U ) ;
V_223 = F_150 ( V_221 , V_232 * V_233 ) - V_219 ;
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
static void F_154 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
unsigned int V_47 ;
struct V_1 * V_24 = F_1 ( V_4 ) ;
do {
V_47 = F_21 ( V_4 , V_41 ) ;
} while ( ! ( V_47 & F_38 ( V_4 ) ) );
F_22 ( V_4 , V_30 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_105 ) ;
if ( V_8 -> V_9 )
F_22 ( V_4 , V_105 , V_237 | V_238 ) ;
F_29 ( V_4 ,
F_34 ( V_4 ) & F_32 ( V_4 ) &
F_120 ( V_4 ) ) ;
if ( F_4 ( V_4 , V_239 ) -> V_9 ) {
V_47 = F_21 ( V_4 , V_239 ) ;
V_47 &= ~ ( V_240 | V_241 ) ;
F_22 ( V_4 , V_239 , V_47 ) ;
}
if ( V_24 -> V_111 > 1 ) {
if ( V_24 -> V_114 ) {
F_61 ( V_4 , 1 ) ;
F_70 ( & V_24 -> V_115 , F_63 ,
( unsigned long ) V_24 ) ;
} else {
if ( V_4 -> type == V_26 ||
V_4 -> type == V_27 )
F_61 ( V_4 , 1 ) ;
else
F_61 ( V_4 , V_24 -> V_111 ) ;
}
}
}
static void F_155 ( struct V_2 * V_4 , struct V_242 * V_243 ,
struct V_242 * V_244 )
{
unsigned int V_245 , V_246 = V_247 , V_248 = 0 , V_13 , V_100 ;
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
V_245 = F_156 ( V_4 , V_243 , V_244 , 0 , 115200 ) ;
goto V_266;
}
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ )
V_254 = F_157 ( V_254 , V_24 -> V_17 [ V_13 ] ) ;
V_245 = F_156 ( V_4 , V_243 , V_244 , 0 , V_254 / F_158 ( V_24 ) ) ;
if ( ! V_245 )
goto V_266;
if ( V_24 -> V_17 [ V_222 ] && V_4 -> type != V_26 &&
V_4 -> type != V_27 ) {
V_223 = F_148 ( V_24 , V_245 , & V_252 ) ;
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
V_223 = F_151 ( V_24 , V_245 , V_24 -> V_17 [ V_268 ] , & V_253 ,
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
V_223 = F_151 ( V_24 , V_245 , V_24 -> V_17 [ V_270 ] , & V_253 ,
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
V_223 = F_153 ( V_24 , V_245 , & V_250 , & V_252 , & V_251 ) ;
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
F_154 ( V_4 ) ;
F_159 ( V_4 , V_243 -> V_256 , V_245 ) ;
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
F_160 ( ( 1000000 + ( V_245 - 1 ) ) / V_245 ) ;
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
V_24 -> V_204 = false ;
V_8 = F_4 ( V_4 , V_105 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_25 = F_21 ( V_4 , V_105 ) ;
if ( ( V_4 -> V_116 & V_289 ) &&
( V_243 -> V_256 & V_290 ) ) {
V_4 -> V_47 |= V_288 ;
V_24 -> V_204 = true ;
}
V_25 &= ~ ( V_237 | V_238 ) ;
F_22 ( V_4 , V_105 , V_25 ) ;
}
V_248 |= V_291 | V_216 |
( V_24 -> V_21 -> V_22 & ~ ( V_217 | V_218 ) ) ;
F_57 ( V_4 -> V_14 , L_39 , V_248 ) ;
F_22 ( V_4 , V_30 , V_248 ) ;
if ( ( V_220 + 1 == 5 ) &&
( V_4 -> type == V_26 || V_4 -> type == V_27 ) ) {
F_160 ( F_116 ( 10 * 1000000 , V_245 ) ) ;
}
switch ( V_243 -> V_256 & V_257 ) {
case V_292 :
V_100 = 7 ;
break;
case V_293 :
V_100 = 8 ;
break;
case V_258 :
V_100 = 9 ;
break;
default:
V_100 = 10 ;
break;
}
if ( V_243 -> V_256 & V_264 )
V_100 ++ ;
if ( V_243 -> V_256 & V_260 )
V_100 ++ ;
V_24 -> V_176 = ( 100 * V_100 * V_294 ) / ( V_245 / 10 ) ;
#ifdef F_20
V_24 -> V_135 = F_116 ( V_24 -> V_127 * 2 * V_24 -> V_176 , 1000 ) ;
F_57 ( V_4 -> V_14 , L_40 ,
V_24 -> V_135 * 1000 / V_294 , V_4 -> V_295 ) ;
if ( V_24 -> V_135 < F_161 ( 20 ) )
V_24 -> V_135 = F_161 ( 20 ) ;
#endif
if ( ( V_243 -> V_256 & V_296 ) != 0 )
F_27 ( V_4 ) ;
F_15 ( V_24 ) ;
if ( F_162 ( V_4 , V_243 -> V_256 ) )
F_141 ( V_4 ) ;
}
static void F_163 ( struct V_2 * V_4 , unsigned int V_33 ,
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
static const char * F_164 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_299 :
return L_41 ;
case V_40 :
return L_42 ;
case V_102 :
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
static int F_165 ( struct V_2 * V_4 )
{
struct V_1 * V_300 = F_1 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_14 -> V_168 || ( V_4 -> V_116 & V_301 ) ) {
V_4 -> V_10 = F_166 ( V_4 -> V_163 , V_300 -> V_302 ) ;
if ( F_124 ( ! V_4 -> V_10 ) ) {
F_128 ( V_4 -> V_14 , L_47 , V_4 -> line ) ;
return - V_303 ;
}
} else {
V_4 -> V_10 = ( void V_304 * ) ( V_305 ) V_4 -> V_163 ;
}
return 0 ;
}
static void F_167 ( struct V_2 * V_4 )
{
struct V_1 * V_300 = F_1 ( V_4 ) ;
if ( V_4 -> V_14 -> V_168 || ( V_4 -> V_116 & V_301 ) ) {
F_168 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_169 ( V_4 -> V_163 , V_300 -> V_302 ) ;
}
static int F_170 ( struct V_2 * V_4 )
{
struct V_306 * V_307 ;
struct V_1 * V_300 = F_1 ( V_4 ) ;
int V_160 ;
V_307 = F_171 ( V_4 -> V_163 , V_300 -> V_302 ,
F_126 ( V_4 -> V_14 ) ) ;
if ( F_124 ( V_307 == NULL ) ) {
F_128 ( V_4 -> V_14 , L_48 ) ;
return - V_308 ;
}
V_160 = F_165 ( V_4 ) ;
if ( F_124 ( V_160 != 0 ) ) {
F_172 ( V_307 ) ;
return V_160 ;
}
return 0 ;
}
static void F_173 ( struct V_2 * V_4 , int V_116 )
{
if ( V_116 & V_309 ) {
struct V_1 * V_300 = F_1 ( V_4 ) ;
V_4 -> type = V_300 -> V_21 -> type ;
F_170 ( V_4 ) ;
}
}
static int F_174 ( struct V_2 * V_4 , struct V_310 * V_311 )
{
if ( V_311 -> V_312 < 2400 )
return - V_113 ;
return 0 ;
}
static int F_175 ( struct V_1 * V_1 , struct V_107 * V_14 )
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
V_314 = F_176 ( V_14 , V_313 [ V_13 ] ) ;
if ( F_177 ( V_314 ) == - V_315 )
return - V_315 ;
if ( F_178 ( V_314 ) && V_13 == V_19 ) {
V_314 = F_176 ( V_14 , L_54 ) ;
if ( F_177 ( V_314 ) == - V_315 )
return - V_315 ;
if ( ! F_178 ( V_314 ) )
goto V_236;
V_314 = F_176 ( V_14 , L_55 ) ;
if ( ! F_178 ( V_314 ) )
goto V_236;
F_128 ( V_14 , L_56 , V_313 [ V_13 ] ,
F_177 ( V_314 ) ) ;
return F_177 ( V_314 ) ;
}
V_236:
if ( F_178 ( V_314 ) )
F_57 ( V_14 , L_56 , V_313 [ V_13 ] ,
F_177 ( V_314 ) ) ;
else
F_57 ( V_14 , L_57 , V_313 [ V_13 ] ,
V_314 , V_314 ) ;
V_1 -> V_16 [ V_13 ] = F_178 ( V_314 ) ? NULL : V_314 ;
}
return 0 ;
}
static const struct V_316 *
F_179 ( const struct V_317 * V_21 )
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
case V_102 :
V_318 = V_324 ;
break;
case V_227 :
V_318 = V_325 ;
break;
default:
F_180 ( L_58 ) ;
return NULL ;
}
return & V_316 [ V_318 ] ;
}
static int F_181 ( struct V_326 * V_14 ,
struct V_1 * V_1 , unsigned int V_327 ,
const struct V_317 * V_5 , bool V_328 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_306 * V_307 ;
unsigned int V_13 ;
int V_160 ;
V_1 -> V_21 = V_5 ;
V_4 -> V_53 = & V_329 ;
V_4 -> V_330 = V_331 ;
V_4 -> line = V_327 ;
V_307 = F_182 ( V_14 , V_332 , 0 ) ;
if ( V_307 == NULL )
return - V_188 ;
V_4 -> V_163 = V_307 -> V_333 ;
V_1 -> V_302 = F_183 ( V_307 ) ;
for ( V_13 = 0 ; V_13 < F_77 ( V_1 -> V_155 ) ; ++ V_13 )
V_1 -> V_155 [ V_13 ] = F_184 ( V_14 , V_13 ) ;
if ( V_1 -> V_155 [ 0 ] < 0 )
return - V_303 ;
if ( V_1 -> V_155 [ 1 ] < 0 ) {
V_1 -> V_155 [ 1 ] = V_1 -> V_155 [ 0 ] ;
V_1 -> V_155 [ 2 ] = V_1 -> V_155 [ 0 ] ;
V_1 -> V_155 [ 3 ] = V_1 -> V_155 [ 0 ] ;
}
V_1 -> V_42 = F_179 ( V_5 ) ;
if ( F_124 ( V_1 -> V_42 == NULL ) )
return - V_113 ;
switch ( V_5 -> type ) {
case V_27 :
V_1 -> V_111 = 48 ;
break;
case V_227 :
V_1 -> V_111 = 64 ;
break;
case V_26 :
V_1 -> V_111 = 32 ;
break;
case V_102 :
if ( V_5 -> V_318 == V_334 )
V_1 -> V_111 = 1 ;
else
V_1 -> V_111 = 8 ;
break;
default:
V_1 -> V_111 = 1 ;
break;
}
V_1 -> V_114 = 0 ;
V_1 -> V_335 = V_5 -> V_336
? F_185 ( V_5 -> V_336 )
: V_1 -> V_42 -> V_335 ;
if ( ! V_328 ) {
V_160 = F_175 ( V_1 , & V_14 -> V_14 ) ;
if ( V_160 < 0 )
return V_160 ;
V_4 -> V_14 = & V_14 -> V_14 ;
F_186 ( & V_14 -> V_14 ) ;
}
V_4 -> type = V_5 -> type ;
V_4 -> V_116 = V_337 | V_338 | V_5 -> V_116 ;
V_4 -> V_69 = V_1 -> V_42 -> V_69 ;
if ( V_4 -> type == V_40 ) {
if ( V_1 -> V_302 >= 0x20 )
V_4 -> V_11 = 2 ;
else
V_4 -> V_11 = 1 ;
}
V_4 -> V_171 = V_1 -> V_155 [ V_156 ] ;
V_4 -> V_191 = 0 ;
V_4 -> V_339 = F_3 ;
V_4 -> V_340 = F_8 ;
return 0 ;
}
static void F_187 ( struct V_1 * V_4 )
{
F_188 ( V_4 -> V_4 . V_14 ) ;
}
static void F_189 ( struct V_2 * V_4 , int V_341 )
{
F_35 ( V_4 , V_341 ) ;
}
static void F_190 ( struct V_342 * V_343 , const char * V_24 ,
unsigned V_76 )
{
struct V_1 * V_1 = & V_344 [ V_343 -> V_327 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_100 , V_25 , V_345 ;
unsigned long V_116 ;
int V_346 = 1 ;
F_191 ( V_116 ) ;
#if F_192 ( V_347 )
if ( V_4 -> V_348 )
V_346 = 0 ;
else
#endif
if ( V_349 )
V_346 = F_193 ( & V_4 -> V_118 ) ;
else
F_194 ( & V_4 -> V_118 ) ;
V_25 = F_21 ( V_4 , V_30 ) ;
V_345 = V_291 | V_216 |
( V_1 -> V_21 -> V_22 & ~ ( V_217 | V_218 ) ) |
( V_25 & ( V_217 | V_218 ) ) ;
F_22 ( V_4 , V_30 , V_345 ) ;
F_195 ( V_4 , V_24 , V_76 , F_189 ) ;
V_100 = F_36 ( V_4 ) | F_38 ( V_4 ) ;
while ( ( F_21 ( V_4 , V_41 ) & V_100 ) != V_100 )
F_196 () ;
F_22 ( V_4 , V_30 , V_25 ) ;
if ( V_346 )
F_197 ( & V_4 -> V_118 ) ;
F_198 ( V_116 ) ;
}
static int F_199 ( struct V_342 * V_343 , char * V_350 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_245 = 115200 ;
int V_100 = 8 ;
int V_92 = 'n' ;
int V_351 = 'n' ;
int V_160 ;
if ( V_343 -> V_327 < 0 || V_343 -> V_327 >= V_352 )
return - V_353 ;
V_1 = & V_344 [ V_343 -> V_327 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_53 )
return - V_353 ;
V_160 = F_165 ( V_4 ) ;
if ( F_124 ( V_160 != 0 ) )
return V_160 ;
if ( V_350 )
F_200 ( V_350 , & V_245 , & V_92 , & V_100 , & V_351 ) ;
return F_201 ( V_4 , V_343 , V_245 , V_92 , V_100 , V_351 ) ;
}
static int F_202 ( struct V_326 * V_354 )
{
const struct V_317 * V_21 = F_203 ( & V_354 -> V_14 ) ;
if ( V_355 . V_195 )
return - V_356 ;
V_355 . V_327 = V_354 -> V_357 ;
F_181 ( V_354 , & V_344 [ V_354 -> V_357 ] , V_354 -> V_357 , V_21 , true ) ;
F_199 ( & V_355 , V_358 ) ;
if ( ! strstr ( V_358 , L_59 ) )
V_355 . V_116 |= V_359 ;
F_204 ( & V_355 ) ;
return 0 ;
}
static inline int F_202 ( struct V_326 * V_354 )
{
return - V_113 ;
}
static int F_205 ( struct V_326 * V_14 )
{
struct V_1 * V_4 = F_206 ( V_14 ) ;
F_207 ( & V_360 , & V_4 -> V_4 ) ;
F_187 ( V_4 ) ;
if ( V_4 -> V_4 . V_69 > 1 ) {
F_208 ( & V_14 -> V_14 . V_361 ,
& V_362 . V_109 ) ;
}
if ( V_4 -> V_4 . type == V_26 || V_4 -> V_4 . type == V_27 ) {
F_208 ( & V_14 -> V_14 . V_361 ,
& V_363 . V_109 ) ;
}
return 0 ;
}
static struct V_317 * F_209 ( struct V_326 * V_354 ,
unsigned int * V_364 )
{
struct V_365 * V_366 = V_354 -> V_14 . V_168 ;
const struct V_367 * V_368 ;
struct V_317 * V_5 ;
struct V_1 * V_369 ;
int V_357 ;
if ( ! F_210 ( V_370 ) || ! V_366 )
return NULL ;
V_368 = F_211 ( V_371 , V_366 ) ;
if ( ! V_368 )
return NULL ;
V_5 = F_212 ( & V_354 -> V_14 , sizeof( struct V_317 ) , V_170 ) ;
if ( ! V_5 )
return NULL ;
V_357 = F_213 ( V_366 , L_60 ) ;
if ( V_357 < 0 ) {
F_128 ( & V_354 -> V_14 , L_61 , V_357 ) ;
return NULL ;
}
V_369 = & V_344 [ V_357 ] ;
* V_364 = V_357 ;
V_5 -> type = F_214 ( V_368 -> V_195 ) ;
V_5 -> V_318 = F_215 ( V_368 -> V_195 ) ;
if ( F_216 ( V_366 , L_62 , NULL ) )
V_369 -> V_58 = true ;
return V_5 ;
}
static int F_217 ( struct V_326 * V_14 ,
unsigned int V_327 ,
struct V_317 * V_5 ,
struct V_1 * V_372 )
{
int V_160 ;
if ( F_124 ( V_327 >= V_352 ) ) {
F_52 ( & V_14 -> V_14 , L_63 ,
V_327 + 1 , V_352 ) ;
F_52 ( & V_14 -> V_14 , L_64 ) ;
return - V_113 ;
}
V_160 = F_181 ( V_14 , V_372 , V_327 , V_5 , false ) ;
if ( V_160 )
return V_160 ;
V_372 -> V_201 = F_218 ( & V_372 -> V_4 , 0 ) ;
if ( F_178 ( V_372 -> V_201 ) && F_177 ( V_372 -> V_201 ) != - V_373 )
return F_177 ( V_372 -> V_201 ) ;
if ( V_372 -> V_58 ) {
if ( ! F_139 ( F_140 ( V_372 -> V_201 ,
V_207 ) ) ||
! F_139 ( F_140 ( V_372 -> V_201 ,
V_374 ) ) ) {
F_128 ( & V_14 -> V_14 , L_65 ) ;
return - V_113 ;
}
V_372 -> V_4 . V_116 |= V_289 ;
}
V_160 = F_219 ( & V_360 , & V_372 -> V_4 ) ;
if ( V_160 ) {
F_187 ( V_372 ) ;
return V_160 ;
}
return 0 ;
}
static int F_220 ( struct V_326 * V_14 )
{
struct V_317 * V_5 ;
struct V_1 * V_369 ;
unsigned int V_364 ;
int V_160 ;
if ( F_221 ( V_14 ) )
return F_202 ( V_14 ) ;
if ( V_14 -> V_14 . V_168 ) {
V_5 = F_209 ( V_14 , & V_364 ) ;
if ( V_5 == NULL )
return - V_113 ;
} else {
V_5 = V_14 -> V_14 . V_375 ;
if ( V_5 == NULL ) {
F_128 ( & V_14 -> V_14 , L_66 ) ;
return - V_113 ;
}
V_364 = V_14 -> V_357 ;
}
V_369 = & V_344 [ V_364 ] ;
F_222 ( V_14 , V_369 ) ;
V_160 = F_217 ( V_14 , V_364 , V_5 , V_369 ) ;
if ( V_160 )
return V_160 ;
if ( V_369 -> V_4 . V_69 > 1 ) {
V_160 = F_223 ( & V_14 -> V_14 . V_361 ,
& V_362 . V_109 ) ;
if ( V_160 )
return V_160 ;
}
if ( V_369 -> V_4 . type == V_26 || V_369 -> V_4 . type == V_27 ) {
V_160 = F_223 ( & V_14 -> V_14 . V_361 ,
& V_363 . V_109 ) ;
if ( V_160 ) {
if ( V_369 -> V_4 . V_69 > 1 ) {
F_208 ( & V_14 -> V_14 . V_361 ,
& V_362 . V_109 ) ;
}
return V_160 ;
}
}
#ifdef F_224
F_225 () ;
#endif
return 0 ;
}
static T_6 int F_226 ( struct V_107 * V_14 )
{
struct V_1 * V_300 = F_65 ( V_14 ) ;
if ( V_300 )
F_227 ( & V_360 , & V_300 -> V_4 ) ;
return 0 ;
}
static T_6 int F_228 ( struct V_107 * V_14 )
{
struct V_1 * V_300 = F_65 ( V_14 ) ;
if ( V_300 )
F_229 ( & V_360 , & V_300 -> V_4 ) ;
return 0 ;
}
static int T_7 F_230 ( void )
{
int V_160 ;
F_231 ( L_67 , V_376 ) ;
V_160 = F_232 ( & V_360 ) ;
if ( F_233 ( V_160 == 0 ) ) {
V_160 = F_234 ( & V_377 ) ;
if ( F_124 ( V_160 ) )
F_235 ( & V_360 ) ;
}
return V_160 ;
}
static void T_8 F_236 ( void )
{
F_237 ( & V_377 ) ;
F_235 ( & V_360 ) ;
}
static int T_7 F_238 ( struct V_378 * V_107 ,
int type )
{
if ( ! V_107 -> V_4 . V_10 )
return - V_353 ;
V_107 -> V_4 . V_339 = F_3 ;
V_107 -> V_4 . V_340 = F_8 ;
V_107 -> V_4 . type = type ;
memcpy ( & V_344 [ 0 ] . V_4 , & V_107 -> V_4 , sizeof( struct V_2 ) ) ;
V_379 . type = type ;
V_344 [ 0 ] . V_21 = & V_379 ;
V_344 [ 0 ] . V_42 = F_179 ( & V_379 ) ;
V_379 . V_22 = F_3 ( & V_344 [ 0 ] . V_4 , V_30 ) ;
F_8 ( & V_344 [ 0 ] . V_4 , V_30 ,
V_291 | V_216 | V_379 . V_22 ) ;
V_107 -> V_380 -> V_381 = F_190 ;
return 0 ;
}
static int T_7 F_239 ( struct V_378 * V_107 ,
const char * V_382 )
{
return F_238 ( V_107 , V_40 ) ;
}
static int T_7 F_240 ( struct V_378 * V_107 ,
const char * V_382 )
{
return F_238 ( V_107 , V_102 ) ;
}
static int T_7 F_241 ( struct V_378 * V_107 ,
const char * V_382 )
{
return F_238 ( V_107 , V_26 ) ;
}
static int T_7 F_242 ( struct V_378 * V_107 ,
const char * V_382 )
{
return F_238 ( V_107 , V_27 ) ;
}
static int T_7 F_243 ( struct V_378 * V_107 ,
const char * V_382 )
{
return F_238 ( V_107 , V_227 ) ;
}
