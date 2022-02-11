static void F_1 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( & V_1 -> V_3 -> V_4 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
if ( F_3 ( V_1 , V_5 ) || F_4 ( V_1 , V_5 ) ||
( V_1 -> V_7 [ V_5 ] . V_8 &&
! F_5 ( V_1 -> V_7 [ V_5 ] . V_8 ) ) )
continue;
if ( F_6 ( & V_1 -> V_7 [ V_5 ] . V_8 ,
V_9 ) )
F_7 ( F_8 ( V_5 , V_2 ) ,
V_1 -> V_7 [ V_5 ] . V_8 ) ;
}
}
static void F_9 ( struct V_1 * V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
if ( F_3 ( V_1 , V_5 ) || F_4 ( V_1 , V_5 ) )
continue;
F_10 ( V_1 -> V_7 [ V_5 ] . V_8 ) ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
int V_5 ;
int V_10 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
if ( F_3 ( V_1 , V_5 ) ||
F_4 ( V_1 , V_5 ) ||
! V_1 -> V_7 [ V_5 ] . V_8 ||
F_5 ( V_1 -> V_7 [ V_5 ] . V_8 ) )
continue;
V_10 = F_12 ( V_1 -> V_11 [ V_5 ] . V_12 ,
V_1 -> V_7 [ V_5 ] . V_8 ) ;
if ( V_10 )
F_13 ( V_1 -> V_13 , L_1 ,
V_10 ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
int V_15 = F_14 ( V_1 , V_5 ) ;
if ( V_1 -> V_7 [ V_15 ] . V_8 &&
! F_5 ( V_1 -> V_7 [ V_15 ] . V_8 ) )
F_15 ( V_1 -> V_13 ,
V_1 -> V_7 [ V_15 ] . V_8 ,
V_5 ) ;
}
}
static void F_16 ( struct V_1 * V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_12 ( V_1 -> V_11 [ V_5 ] . V_12 , NULL ) ;
}
static void F_17 ( struct V_16 * V_13 ,
struct V_17 * V_18 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
T_1 V_19 = V_18 -> V_19 ;
int V_10 ;
F_19 ( & V_1 -> V_20 ) ;
if ( V_18 -> type != V_21 ) {
F_20 ( V_13 , L_2 ) ;
goto error;
}
if ( V_18 -> V_22 != V_23 ) {
F_20 ( V_13 , L_3 ) ;
goto error;
}
if ( V_1 -> V_24 . V_25 ) {
if ( F_21 ( V_19 ) == V_1 -> V_24 . V_25 )
F_13 ( V_13 , L_4 ) ;
else
F_20 ( V_13 , L_5 ) ;
goto error;
}
V_10 = F_22 ( V_1 -> V_26 ,
V_27 ,
F_21 ( V_19 ) ) ;
if ( V_10 )
goto error;
V_10 = F_23 ( V_1 -> V_26 , V_28 ,
V_1 -> V_24 . V_29 ) ;
if ( V_10 )
goto error;
V_1 -> V_24 . V_25 = F_21 ( V_19 ) ;
F_20 ( V_13 , L_6 ,
( int ) V_1 -> V_24 . V_29 , F_21 ( V_19 ) , V_18 -> V_22 ) ;
goto V_30;
error:
F_20 ( V_13 , L_7 ,
F_21 ( V_19 ) , V_18 -> V_22 , V_18 -> type ) ;
V_30:
F_24 ( & V_1 -> V_20 ) ;
}
static void F_25 ( struct V_16 * V_13 ,
struct V_17 * V_18 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
int V_10 ;
F_19 ( & V_1 -> V_20 ) ;
if ( ( V_18 -> V_22 != V_23 ) ||
( ( F_21 ( V_18 -> V_19 ) != V_1 -> V_24 . V_25 ) ) ||
( V_18 -> type != V_21 ) ) {
F_20 ( V_13 , L_8 ,
F_21 ( V_18 -> V_19 ) , V_18 -> V_22 , V_18 -> type ) ;
goto V_30;
}
V_10 = F_23 ( V_1 -> V_26 , V_28 ,
V_31 ) ;
if ( V_10 ) {
F_26 ( V_13 , L_9 ,
F_21 ( V_18 -> V_19 ) ) ;
goto V_30;
}
V_1 -> V_24 . V_25 = 0 ;
F_20 ( V_13 , L_10 ,
F_21 ( V_18 -> V_19 ) , V_18 -> V_22 ) ;
V_30:
F_24 ( & V_1 -> V_20 ) ;
}
static T_2 F_27 ( struct V_32 * V_33 ,
struct V_16 * V_4 ,
T_2 V_34 )
{
const struct V_35 * V_36 = (struct V_35 * ) F_28 ( V_33 ) ;
struct V_1 * V_1 = F_18 ( V_4 ) ;
struct V_37 * V_38 ;
T_3 V_19 = 0 ;
T_3 V_39 ;
if ( ! V_33 -> V_40 )
return V_34 ;
V_34 = F_29 ( V_33 , V_34 ) ;
if ( F_30 ( V_33 ) != F_31 ( V_41 ) )
goto V_42;
if ( V_36 -> V_43 != F_21 ( V_41 ) )
goto V_42;
V_39 = F_32 ( V_33 ) -> V_44 ;
if ( V_39 == V_45 ) {
V_38 = F_33 ( V_33 ) ;
V_19 = F_34 ( V_38 -> V_46 ) ;
}
if ( V_19 != V_1 -> V_24 . V_25 )
goto V_42;
return V_34 ;
V_42:
return V_34 & ~ ( V_47 | V_48 ) ;
}
int F_35 ( struct V_1 * V_1 )
{
return V_1 -> V_3 -> V_49 == V_50 ;
}
int F_36 ( struct V_1 * V_1 )
{
return ( V_1 -> V_51 & V_52 ) ? 1 : 0 ;
}
static int F_37 ( struct V_1 * V_1 )
{
return V_1 -> V_3 -> V_49 == V_53 ;
}
int F_38 ( struct V_1 * V_1 , int V_54 )
{
#ifdef F_39
return V_54 >= 0 && V_54 < V_1 -> V_55 ;
#else
return 0 ;
#endif
}
static void F_40 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
struct V_1 * V_1 = F_41 ( V_57 -> V_26 ) ;
if ( V_59 -> V_60 )
F_42 ( V_1 -> V_3 , V_59 -> V_61 ,
V_59 -> V_62 , V_63 ) ;
else
F_43 ( V_1 -> V_3 , V_59 -> V_61 ,
V_59 -> V_62 , V_63 ) ;
if ( V_59 -> V_64 )
F_44 ( V_59 -> V_64 ) ;
}
static void F_45 ( struct V_56 * V_57 ,
struct V_65 * V_65 , struct V_58 * V_59 , void * V_66 )
{
F_40 ( V_57 , V_59 ) ;
}
static int F_46 ( struct V_67 * V_26 , struct V_65 * V_65 ,
T_4 type , T_3 V_68 , T_3 V_69 , void * V_66 )
{
struct V_1 * V_1 = F_41 ( V_26 ) ;
F_47 ( & V_1 -> V_70 [ V_68 ] ) ;
F_48 ( & V_1 -> V_57 [ V_68 ] , V_65 ,
V_69 , F_45 ,
V_66 ) ;
if ( F_49 ( F_50 ( V_1 -> V_13 , V_68 ) ) &&
F_51 ( & V_1 -> V_57 [ V_68 ] ) >=
( V_71 + V_72 ) )
F_52 ( V_1 -> V_13 , V_68 ) ;
F_53 ( & V_1 -> V_70 [ V_68 ] ) ;
return 0 ;
}
static bool F_54 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
T_5 V_73 ;
bool V_10 = false ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
V_73 = F_55 ( & V_1 -> V_57 [ V_5 ] ) ;
V_10 |= V_73 ;
if ( V_73 )
F_26 ( V_1 -> V_13 , L_11 ,
V_5 , V_73 ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
V_73 = F_56 ( & V_1 -> V_75 [ V_5 ] ) ;
V_10 |= V_73 ;
if ( V_73 )
F_26 ( V_1 -> V_13 , L_12 ,
V_5 , V_73 ) ;
}
return V_10 ;
}
static void F_57 ( struct V_1 * V_1 )
{
T_5 V_76 = F_58 ( V_1 -> V_26 ) ;
if ( V_76 != V_1 -> V_76 ) {
F_20 ( V_1 -> V_13 , L_13 ,
V_1 -> V_76 , V_76 ) ;
V_1 -> V_76 = V_76 ;
}
}
static void F_59 ( struct V_1 * V_1 )
{
T_5 V_77 = F_60 ( V_1 -> V_26 ) ;
struct V_16 * V_13 = V_1 -> V_13 ;
if ( V_77 && V_77 != V_1 -> V_78 ) {
V_1 -> V_78 = V_77 ;
if ( F_35 ( V_1 ) || F_37 ( V_1 ) ) {
V_77 = F_61 ( int , V_79 ,
F_62 ( int , V_80 , V_77 ) ) ;
if ( V_77 != V_13 -> V_77 )
F_63 ( & V_1 -> V_81 ) ;
} else {
if ( V_77 < V_13 -> V_77 )
F_13 ( V_13 ,
L_14
L_15 ,
V_13 -> V_77 , V_77 ) ;
}
}
}
static void F_64 ( struct V_1 * V_1 )
{
int V_82 = F_65 ( V_1 -> V_26 ) ;
int V_83 = F_66 ( V_1 -> V_13 ) ;
if ( V_82 && ! V_83 ) {
F_20 ( V_1 -> V_13 , L_16 ) ;
F_67 ( V_1 -> V_13 ) ;
} else if ( ! V_82 && V_83 ) {
F_20 ( V_1 -> V_13 , L_17 ) ;
F_68 ( V_1 -> V_13 ) ;
}
}
static void F_69 ( struct V_1 * V_1 )
{
F_57 ( V_1 ) ;
F_59 ( V_1 ) ;
F_64 ( V_1 ) ;
}
static T_6 F_70 ( int V_84 , void * V_85 )
{
struct V_16 * V_13 = V_85 ;
struct V_1 * V_1 = F_18 ( V_13 ) ;
unsigned int V_86 = F_71 () ;
unsigned int V_87 = F_72 () ;
unsigned int V_88 = F_73 () ;
T_5 V_89 ;
F_74 ( & V_1 -> V_90 [ V_86 ] ) ;
V_89 = F_75 ( V_1 -> V_91 ) ;
if ( ! V_89 ) {
F_76 ( & V_1 -> V_90 [ V_86 ] ) ;
return V_92 ;
}
if ( F_77 ( V_89 , V_88 ) ) {
F_69 ( V_1 ) ;
F_78 ( & V_1 -> V_90 [ V_88 ] ) ;
}
if ( F_77 ( V_89 , V_87 ) ) {
F_78 ( & V_1 -> V_90 [ V_87 ] ) ;
F_54 ( V_1 ) ;
F_63 ( & V_1 -> V_93 ) ;
return V_94 ;
}
if ( F_77 ( V_89 , V_86 ) )
F_79 ( & V_1 -> V_95 [ 0 ] ) ;
else
F_76 ( & V_1 -> V_90 [ V_86 ] ) ;
return V_94 ;
}
static T_6 F_80 ( int V_84 , void * V_85 )
{
struct V_1 * V_1 = V_85 ;
F_79 ( & V_1 -> V_95 [ 0 ] ) ;
return V_94 ;
}
static T_6 F_81 ( int V_84 , void * V_85 )
{
struct V_96 * V_95 = V_85 ;
F_79 ( V_95 ) ;
return V_94 ;
}
static T_6 F_82 ( int V_84 , void * V_85 )
{
struct V_1 * V_1 = V_85 ;
unsigned int V_90 = F_83 ( V_1 ) ;
F_78 ( & V_1 -> V_90 [ V_90 ] ) ;
if ( F_54 ( V_1 ) )
F_63 ( & V_1 -> V_93 ) ;
return V_94 ;
}
static T_6 F_84 ( int V_84 , void * V_85 )
{
struct V_1 * V_1 = V_85 ;
unsigned int V_90 = F_85 ( V_1 ) ;
F_69 ( V_1 ) ;
F_78 ( & V_1 -> V_90 [ V_90 ] ) ;
return V_94 ;
}
static int F_86 ( struct V_1 * V_1 , struct V_56 * V_57 ,
struct V_32 * V_33 , unsigned int V_97 ,
int V_98 )
{
const T_7 * V_99 ;
T_8 V_61 ;
for ( V_99 = F_87 ( V_33 ) -> V_100 ; V_97 ; V_99 ++ ) {
V_97 -= F_88 ( V_99 ) ;
V_61 = F_89 ( & V_1 -> V_3 -> V_4 , V_99 , 0 ,
F_88 ( V_99 ) ,
V_101 ) ;
if ( F_90 ( F_91 ( V_1 , V_61 ) ) )
return - V_102 ;
F_92 ( V_57 , V_33 , V_61 , F_88 ( V_99 ) ,
( V_97 == 0 ) ,
V_98 ) ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_1 , struct V_56 * V_57 ,
struct V_32 * V_33 , int V_103 ,
unsigned int V_104 , int V_98 )
{
unsigned int V_105 = F_94 ( V_33 ) ;
unsigned int V_97 = V_33 -> V_62 - V_105 ;
int V_106 = ( V_97 == 0 ) ;
T_8 V_61 ;
int V_10 = 0 ;
V_61 = F_95 ( V_1 -> V_3 , V_33 -> V_85 , V_105 ,
V_63 ) ;
if ( F_90 ( F_91 ( V_1 , V_61 ) ) )
return - V_102 ;
F_96 ( V_57 , V_33 , V_61 , V_105 , V_103 ,
V_104 , V_106 , V_98 ) ;
if ( ! V_106 )
V_10 = F_86 ( V_1 , V_57 , V_33 , V_97 , V_98 ) ;
return V_10 ;
}
static int F_97 ( struct V_1 * V_1 , struct V_56 * V_57 ,
struct V_32 * V_33 , int V_103 ,
unsigned int V_104 , int V_98 )
{
unsigned int V_105 = F_94 ( V_33 ) ;
unsigned int V_97 = V_33 -> V_62 - V_105 ;
unsigned int V_107 = F_98 ( V_33 ) ;
unsigned int V_108 = V_107 + V_33 -> V_108 ;
int V_106 = ( V_97 == 0 ) ;
T_8 V_61 ;
int V_10 = 0 ;
V_61 = F_95 ( V_1 -> V_3 , V_33 -> V_85 , V_105 ,
V_63 ) ;
if ( F_90 ( F_91 ( V_1 , V_61 ) ) )
return - V_102 ;
F_99 ( V_57 , V_33 , V_61 , V_105 , V_108 ,
V_107 , V_103 , V_104 , V_106 ,
V_98 ) ;
if ( ! V_106 )
V_10 = F_86 ( V_1 , V_57 , V_33 , V_97 , V_98 ) ;
return V_10 ;
}
static void F_100 ( struct V_32 * V_33 )
{
if ( V_33 -> V_44 == F_101 ( V_41 ) ) {
F_102 ( V_33 ) -> V_109 = 0 ;
F_103 ( V_33 ) -> V_109 =
~ F_104 ( F_102 ( V_33 ) -> V_110 ,
F_102 ( V_33 ) -> V_111 , 0 ,
V_112 , 0 ) ;
}
}
static void F_105 ( struct V_32 * V_33 )
{
if ( V_33 -> V_44 == F_101 ( V_41 ) ) {
F_32 ( V_33 ) -> V_109 = 0 ;
F_106 ( V_33 ) -> V_109 = ~ F_104 ( F_32 ( V_33 ) -> V_110 ,
F_32 ( V_33 ) -> V_111 , 0 , V_112 , 0 ) ;
} else if ( V_33 -> V_44 == F_101 ( V_113 ) ) {
F_106 ( V_33 ) -> V_109 = ~ F_107 ( & F_108 ( V_33 ) -> V_110 ,
& F_108 ( V_33 ) -> V_111 , 0 , V_112 , 0 ) ;
}
}
static int F_109 ( struct V_1 * V_1 , struct V_56 * V_57 ,
struct V_32 * V_33 , unsigned int V_114 ,
int V_103 , unsigned int V_104 ,
int V_98 )
{
unsigned int V_115 = F_94 ( V_33 ) ;
unsigned int V_97 = V_33 -> V_62 - V_115 ;
int V_106 = ( V_97 == 0 ) ;
unsigned int V_116 = 0 ;
unsigned int V_107 ;
T_8 V_61 ;
unsigned int V_62 ;
T_7 * V_99 ;
if ( V_33 -> V_40 ) {
V_107 = F_110 ( V_33 ) - V_33 -> V_85 ;
V_107 += F_111 ( V_33 ) ;
F_100 ( V_33 ) ;
} else {
V_107 = F_112 ( V_33 ) + F_113 ( V_33 ) ;
F_105 ( V_33 ) ;
}
while ( V_115 ) {
V_62 = F_114 ( V_115 , ( unsigned int ) V_117 ) ;
V_61 = F_95 ( V_1 -> V_3 , V_33 -> V_85 + V_116 , V_62 ,
V_63 ) ;
if ( F_90 ( F_91 ( V_1 , V_61 ) ) )
return - V_102 ;
F_115 ( V_57 , V_33 , V_61 , V_62 , V_114 , V_107 ,
V_103 , V_104 ,
V_106 && ( V_62 == V_115 ) , V_98 ) ;
V_115 -= V_62 ;
V_116 += V_62 ;
}
if ( V_106 )
return 0 ;
for ( V_99 = F_87 ( V_33 ) -> V_100 ; V_97 ; V_99 ++ ) {
V_97 -= F_88 ( V_99 ) ;
V_115 = F_88 ( V_99 ) ;
V_116 = 0 ;
while ( V_115 ) {
V_62 = F_114 ( V_115 ,
( unsigned int ) V_117 ) ;
V_61 = F_89 ( & V_1 -> V_3 -> V_4 , V_99 ,
V_116 , V_62 ,
V_101 ) ;
if ( F_90 ( F_91 ( V_1 , V_61 ) ) )
return - V_102 ;
F_92 ( V_57 , V_33 , V_61 , V_62 ,
( V_97 == 0 ) &&
( V_62 == V_115 ) ,
V_98 ) ;
V_115 -= V_62 ;
V_116 += V_62 ;
}
}
return 0 ;
}
static inline int F_116 ( struct V_1 * V_1 , struct V_56 * V_57 ,
struct V_32 * V_33 ,
int V_103 ,
unsigned int V_104 , int V_98 )
{
unsigned int V_105 = F_94 ( V_33 ) ;
unsigned int V_97 = V_33 -> V_62 - V_105 ;
unsigned int V_118 = 7 ;
int V_106 = ( V_97 == 0 ) ;
T_8 V_61 ;
int V_10 = 0 ;
V_61 = F_95 ( V_1 -> V_3 , V_33 -> V_85 , V_105 ,
V_63 ) ;
if ( F_90 ( F_91 ( V_1 , V_61 ) ) )
return - V_102 ;
F_117 ( V_57 , V_33 , V_61 , V_105 , V_118 , 0 ,
V_103 , V_104 ,
V_119 , V_106 , 1 , V_106 ,
V_98 ) ;
if ( ! V_106 )
V_10 = F_86 ( V_1 , V_57 , V_33 , V_97 , V_98 ) ;
return V_10 ;
}
static inline void F_118 ( struct V_1 * V_1 ,
struct V_56 * V_57 , struct V_32 * V_33 )
{
unsigned int V_114 = F_87 ( V_33 ) -> V_120 ;
unsigned int V_104 = 0 ;
int V_103 = 0 ;
int V_98 = 0 ;
int V_10 ;
if ( F_119 ( V_33 ) ) {
V_103 = 1 ;
V_104 = F_120 ( V_33 ) ;
} else if ( V_1 -> V_121 ) {
V_104 = V_1 -> V_122 ;
V_98 = 1 ;
}
if ( V_114 )
V_10 = F_109 ( V_1 , V_57 , V_33 , V_114 ,
V_103 , V_104 ,
V_98 ) ;
else if ( V_33 -> V_40 )
V_10 = F_116 ( V_1 , V_57 , V_33 , V_103 ,
V_104 , V_98 ) ;
else if ( V_33 -> V_123 == V_124 )
V_10 = F_97 ( V_1 , V_57 , V_33 , V_103 ,
V_104 , V_98 ) ;
else
V_10 = F_93 ( V_1 , V_57 , V_33 , V_103 ,
V_104 , V_98 ) ;
if ( F_90 ( V_10 ) ) {
struct V_58 * V_59 ;
V_59 = V_57 -> V_125 -> V_126 ;
while ( ! V_59 -> V_64 && ( V_59 -> V_127 != V_57 -> V_128 ) ) {
F_40 ( V_57 , V_59 ) ;
V_57 -> V_129 . V_130 ++ ;
V_59 = V_59 -> V_126 ;
}
V_57 -> V_125 = V_59 -> V_127 ;
F_121 ( V_33 ) ;
}
}
static T_9 F_122 ( struct V_32 * V_33 ,
struct V_16 * V_13 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
struct V_56 * V_57 ;
unsigned int V_131 ;
struct V_132 * V_133 ;
if ( V_33 -> V_62 <= 0 ) {
F_44 ( V_33 ) ;
return V_134 ;
}
V_131 = F_123 ( V_33 ) % V_1 -> V_14 ;
V_57 = & V_1 -> V_57 [ V_131 ] ;
V_133 = F_50 ( V_13 , V_131 ) ;
if ( F_87 ( V_33 ) -> V_120 == 0 &&
F_87 ( V_33 ) -> V_135 + 1 > V_136 &&
F_124 ( V_33 ) ) {
F_44 ( V_33 ) ;
return V_134 ;
}
F_47 ( & V_1 -> V_70 [ V_131 ] ) ;
if ( F_51 ( V_57 ) <
F_87 ( V_33 ) -> V_135 + V_72 ) {
F_125 ( V_133 ) ;
F_26 ( V_13 , L_18 ) ;
F_53 ( & V_1 -> V_70 [ V_131 ] ) ;
return V_137 ;
}
F_118 ( V_1 , V_57 , V_33 ) ;
if ( F_51 ( V_57 ) < V_71 + V_72 )
F_125 ( V_133 ) ;
if ( ! V_33 -> V_138 || F_126 ( V_133 ) )
F_127 ( V_57 ) ;
F_53 ( & V_1 -> V_70 [ V_131 ] ) ;
return V_134 ;
}
static void F_128 ( struct V_16 * V_13 ,
struct V_139 * V_140 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
struct V_141 * V_142 ;
int V_10 ;
V_10 = F_129 ( V_1 , & V_142 ) ;
if ( V_10 == - V_102 )
return;
V_140 -> V_143 = V_142 -> V_144 . V_145 ;
V_140 -> V_146 = V_142 -> V_144 . V_147 ;
V_140 -> V_148 = V_142 -> V_144 . V_148 ;
V_140 -> V_149 = V_142 -> V_144 . V_150 ;
V_140 -> V_151 = V_142 -> V_152 . V_153 ;
V_140 -> V_154 = V_142 -> V_152 . V_155 ;
V_140 -> V_156 = V_142 -> V_152 . V_156 ;
V_140 -> V_157 = V_142 -> V_152 . V_158 ;
V_140 -> V_159 = V_1 -> V_160 ;
V_140 -> V_161 = V_1 -> V_162 ;
V_140 -> V_163 = V_142 -> V_152 . V_164 + V_142 -> V_152 . V_165 ;
}
static int F_130 ( struct V_16 * V_13 , const T_4 * V_166 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
if ( V_1 -> V_167 == V_168 ) {
unsigned int V_167 = F_131 ( V_13 ) ;
F_13 ( V_13 , L_19 ,
V_168 , V_167 ) ;
return - V_169 ;
}
F_132 ( V_1 , V_166 ) ;
V_1 -> V_167 ++ ;
return 0 ;
}
static int F_133 ( struct V_16 * V_13 , const T_4 * V_166 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
F_134 ( V_1 , V_166 ) ;
V_1 -> V_167 -- ;
return 0 ;
}
static int F_135 ( struct V_16 * V_13 , const T_4 * V_170 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
if ( V_1 -> V_171 == V_172 ) {
unsigned int V_171 = F_136 ( V_13 ) ;
F_13 ( V_13 , L_20 ,
V_172 , V_171 ) ;
return - V_169 ;
}
F_132 ( V_1 , V_170 ) ;
V_1 -> V_171 ++ ;
return 0 ;
}
static int F_137 ( struct V_16 * V_13 , const T_4 * V_170 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
F_134 ( V_1 , V_170 ) ;
V_1 -> V_171 -- ;
return 0 ;
}
void F_138 ( struct V_1 * V_1 )
{
struct V_16 * V_13 = V_1 -> V_13 ;
F_139 ( V_13 , NULL ) ;
F_140 ( V_13 , NULL ) ;
V_1 -> V_167 = 0 ;
V_1 -> V_171 = 0 ;
V_1 -> V_173 = 0 ;
}
static int F_141 ( struct V_16 * V_13 , char * V_174 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
if ( F_35 ( V_1 ) || F_37 ( V_1 ) ) {
if ( ! F_142 ( V_174 ) && ! F_143 ( V_174 ) )
return - V_175 ;
} else {
if ( ! F_142 ( V_174 ) )
return - V_175 ;
}
memcpy ( V_13 -> V_176 , V_174 , V_13 -> V_177 ) ;
return 0 ;
}
static int F_144 ( struct V_16 * V_13 , void * V_178 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
struct V_179 * V_110 = V_178 ;
char * V_174 = V_110 -> V_180 ;
int V_10 ;
if ( F_145 ( V_1 -> V_13 ) ) {
V_10 = F_146 ( V_1 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_141 ( V_13 , V_174 ) ;
if ( V_10 )
return V_10 ;
if ( F_145 ( V_1 -> V_13 ) ) {
V_10 = F_147 ( V_1 ) ;
if ( V_10 )
return V_10 ;
}
return V_10 ;
}
static int F_148 ( struct V_16 * V_13 , void * V_178 )
{
struct V_179 * V_110 = V_178 ;
char * V_174 = V_110 -> V_180 ;
struct V_1 * V_1 = F_18 ( V_13 ) ;
int V_10 ;
V_10 = F_146 ( V_1 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_141 ( V_13 , V_174 ) ;
if ( V_10 )
return V_10 ;
return F_147 ( V_1 ) ;
}
static void F_149 ( struct V_16 * V_13 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
int V_181 = 1 ;
int V_157 = ( V_13 -> V_173 & V_182 ) ? 1 : 0 ;
int V_183 = ( V_13 -> V_173 & V_184 ) ? 1 : 0 ;
int V_185 = ( V_13 -> V_173 & V_186 ) ||
F_136 ( V_13 ) > V_172 ;
int V_187 = ( V_13 -> V_173 & V_188 ) ||
F_131 ( V_13 ) > V_168 ;
unsigned int V_173 = V_13 -> V_173 |
( V_187 ? V_188 : 0 ) |
( V_185 ? V_186 : 0 ) ;
if ( V_1 -> V_173 != V_173 ) {
V_1 -> V_173 = V_173 ;
F_150 ( V_1 , V_181 ,
V_157 , V_183 , V_185 , V_187 ) ;
}
if ( ! V_185 ) {
F_151 ( V_13 , F_135 , F_137 ) ;
if ( ! V_187 )
F_152 ( V_13 , F_130 , F_133 ) ;
}
}
static void F_153 ( struct V_16 * V_13 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
F_63 ( & V_1 -> V_189 ) ;
}
static int F_154 ( struct V_16 * V_13 , int V_54 , T_4 * V_190 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
struct V_191 * V_192 ;
int V_10 ;
F_155 ( V_1 , V_54 , V_192 , & V_10 ) ;
if ( V_10 )
return V_10 ;
if ( F_142 ( V_190 ) || F_143 ( V_190 ) ) {
if ( V_54 == V_193 ) {
memcpy ( V_192 -> V_194 , V_190 , V_195 ) ;
return 0 ;
} else {
F_156 ( V_54 , V_10 , V_1 ,
V_196 , V_190 ) ;
return F_157 ( V_10 ) ;
}
} else
return - V_197 ;
}
static int F_158 ( struct V_16 * V_13 , int V_54 ,
struct V_198 * V_19 [] )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
struct V_191 V_199 ;
struct V_191 * V_192 ;
int V_10 = 0 , V_200 = 1 ;
F_155 ( V_1 , V_54 , V_192 , & V_10 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_19 [ V_201 ] )
return - V_202 ;
memcpy ( & V_199 , V_192 , sizeof( * V_1 -> V_192 ) ) ;
memset ( V_192 , 0 , sizeof( * V_1 -> V_192 ) ) ;
V_192 -> V_203 |= V_204 ;
V_192 -> V_205 = F_159 ( V_19 [ V_201 ] ) ;
if ( V_19 [ V_206 ] ) {
V_192 -> V_203 |= V_207 ;
memcpy ( V_192 -> V_208 , F_160 ( V_19 [ V_206 ] ) ,
V_209 ) ;
}
if ( V_19 [ V_210 ] ) {
V_192 -> V_203 |= V_211 ;
memcpy ( V_192 -> V_212 ,
F_160 ( V_19 [ V_210 ] ) , V_213 ) ;
}
if ( V_19 [ V_214 ] ) {
V_192 -> V_203 |= V_215 ;
memcpy ( V_192 -> V_216 ,
F_160 ( V_19 [ V_214 ] ) , V_213 ) ;
}
if ( V_54 == V_193 ) {
if ( ! F_143 ( V_199 . V_194 ) )
memcpy ( V_192 -> V_217 , V_199 . V_194 , V_195 ) ;
if ( F_143 ( V_13 -> V_176 ) )
F_161 ( V_13 ) ;
} else {
F_156 ( V_54 , V_10 , V_1 ,
V_218 , V_192 -> V_217 ) ;
if ( V_10 ) {
F_26 ( V_13 , L_21 , V_54 ) ;
memcpy ( V_192 , & V_199 , sizeof( * V_192 ) ) ;
return F_157 ( V_10 ) ;
}
}
V_10 = F_162 ( V_1 , V_54 , & V_199 , & V_200 ) ;
if ( V_10 ) {
if ( V_200 ) {
memcpy ( V_192 , & V_199 , sizeof( * V_192 ) ) ;
} else {
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
if ( V_54 == V_193 )
F_163 ( V_13 -> V_176 ) ;
}
} else {
V_192 -> V_203 |= V_219 ;
if ( V_192 -> V_205 == V_220 ) {
F_163 ( V_192 -> V_217 ) ;
if ( V_54 == V_193 )
F_163 ( V_13 -> V_176 ) ;
}
}
if ( V_54 == V_193 )
F_163 ( V_192 -> V_194 ) ;
return V_10 ;
}
static int F_164 ( struct V_16 * V_13 , int V_54 ,
struct V_32 * V_33 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
T_3 V_221 = V_222 ;
struct V_191 * V_192 ;
int V_10 ;
F_155 ( V_1 , V_54 , V_192 , & V_10 ) ;
if ( V_10 )
return V_10 ;
if ( ! ( V_192 -> V_203 & V_219 ) )
return - V_223 ;
V_10 = F_165 ( V_1 , V_54 , V_192 -> V_205 , & V_221 ) ;
if ( V_10 )
return V_10 ;
if ( F_166 ( V_33 , V_201 , V_192 -> V_205 ) ||
F_166 ( V_33 , V_224 , V_221 ) ||
( ( V_192 -> V_203 & V_207 ) &&
F_167 ( V_33 , V_206 , V_209 , V_192 -> V_208 ) ) ||
( ( V_192 -> V_203 & V_211 ) &&
F_167 ( V_33 , V_210 , V_213 ,
V_192 -> V_212 ) ) ||
( ( V_192 -> V_203 & V_215 ) &&
F_167 ( V_33 , V_214 , V_213 , V_192 -> V_216 ) ) )
goto V_225;
return 0 ;
V_225:
return - V_226 ;
}
static void F_168 ( struct V_227 * V_75 , struct V_228 * V_59 )
{
struct V_1 * V_1 = F_41 ( V_75 -> V_26 ) ;
if ( ! V_59 -> V_64 )
return;
F_42 ( V_1 -> V_3 , V_59 -> V_61 ,
V_59 -> V_62 , V_229 ) ;
F_44 ( V_59 -> V_64 ) ;
V_59 -> V_64 = NULL ;
}
static int F_169 ( struct V_227 * V_75 )
{
struct V_1 * V_1 = F_41 ( V_75 -> V_26 ) ;
struct V_16 * V_13 = V_1 -> V_13 ;
struct V_32 * V_33 ;
unsigned int V_62 = V_13 -> V_77 + V_230 ;
unsigned int V_231 = 0 ;
T_8 V_61 ;
struct V_228 * V_59 = V_75 -> V_125 ;
if ( V_59 -> V_64 ) {
F_170 ( V_75 , V_59 -> V_64 , V_231 , V_59 -> V_61 ,
V_59 -> V_62 ) ;
return 0 ;
}
V_33 = F_171 ( V_13 , V_62 ) ;
if ( ! V_33 )
return - V_102 ;
V_61 = F_95 ( V_1 -> V_3 , V_33 -> V_85 , V_62 ,
V_229 ) ;
if ( F_90 ( F_91 ( V_1 , V_61 ) ) ) {
F_121 ( V_33 ) ;
return - V_102 ;
}
F_170 ( V_75 , V_33 , V_231 ,
V_61 , V_62 ) ;
return 0 ;
}
static void F_172 ( struct V_232 * V_233 ,
T_5 V_234 )
{
if ( V_235 <= V_234 )
V_233 -> V_236 += V_234 ;
else
V_233 -> V_237 += V_234 ;
}
static bool F_173 ( struct V_16 * V_13 , struct V_32 * * V_33 ,
struct V_228 * V_59 , T_3 V_62 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
struct V_32 * V_238 ;
if ( V_62 > V_1 -> V_239 )
return false ;
V_238 = F_171 ( V_13 , V_62 ) ;
if ( ! V_238 )
return false ;
F_174 ( V_1 -> V_3 , V_59 -> V_61 , V_62 ,
V_240 ) ;
memcpy ( V_238 -> V_85 , ( * V_33 ) -> V_85 , V_62 ) ;
* V_33 = V_238 ;
return true ;
}
static void F_175 ( struct V_227 * V_75 ,
struct V_65 * V_65 , struct V_228 * V_59 ,
int V_241 , void * V_66 )
{
struct V_1 * V_1 = F_41 ( V_75 -> V_26 ) ;
struct V_16 * V_13 = V_1 -> V_13 ;
struct V_32 * V_33 ;
struct V_242 * V_243 = & V_1 -> V_243 [ F_176 ( V_1 , V_75 -> V_244 ) ] ;
T_4 type , V_245 , V_106 , V_60 , V_246 , V_247 ;
T_4 V_248 , V_249 , V_250 , V_251 , V_252 ;
T_4 V_253 , V_254 , V_255 , V_256 ;
T_4 V_257 , V_258 , V_259 , V_260 , V_261 , V_262 ;
T_4 V_263 ;
T_3 V_68 , V_69 , V_264 , V_265 , V_266 ;
T_5 V_267 ;
bool V_268 = true , V_269 = false ;
if ( V_241 )
return;
V_33 = V_59 -> V_64 ;
F_177 ( (struct V_270 * ) V_65 ,
& type , & V_245 , & V_68 , & V_69 ,
& V_246 , & V_248 , & V_106 , & V_60 , & V_261 ,
& V_262 , & V_267 , & V_264 ,
& V_263 , & V_247 , & V_265 , & V_266 ,
& V_249 , & V_250 , & V_251 ,
& V_252 , & V_253 , & V_254 , & V_255 ,
& V_256 , & V_257 , & V_258 , & V_259 ,
& V_260 ) ;
if ( V_263 ) {
if ( ! V_260 ) {
if ( V_264 > 0 )
V_1 -> V_162 ++ ;
else if ( V_264 == 0 )
V_1 -> V_160 ++ ;
}
F_42 ( V_1 -> V_3 , V_59 -> V_61 , V_59 -> V_62 ,
V_229 ) ;
F_44 ( V_33 ) ;
V_59 -> V_64 = NULL ;
return;
}
if ( V_106 && V_264 > 0 ) {
if ( ! F_173 ( V_13 , & V_33 , V_59 , V_264 ) ) {
V_59 -> V_64 = NULL ;
F_42 ( V_1 -> V_3 , V_59 -> V_61 , V_59 -> V_62 ,
V_229 ) ;
}
F_178 ( V_33 -> V_85 - V_271 ) ;
F_179 ( V_33 , V_264 ) ;
V_33 -> V_44 = F_180 ( V_33 , V_13 ) ;
F_181 ( V_33 , V_68 ) ;
if ( ( V_13 -> V_34 & V_272 ) && V_267 &&
( type == 3 ) ) {
switch ( V_261 ) {
case V_273 :
case V_274 :
case V_275 :
F_182 ( V_33 , V_267 , V_276 ) ;
break;
case V_277 :
case V_278 :
case V_279 :
F_182 ( V_33 , V_267 , V_280 ) ;
break;
}
}
if ( V_1 -> V_24 . V_25 ) {
switch ( V_1 -> V_24 . V_29 ) {
case 0 :
if ( V_248 ) {
V_269 = true ;
V_268 = V_250 ;
}
break;
case 2 :
if ( ( type == 7 ) &&
( V_267 & F_183 ( 0 ) ) ) {
V_269 = true ;
V_268 = ( V_267 & F_183 ( 1 ) ) &&
( V_267 & F_183 ( 2 ) ) ;
}
break;
}
}
if ( ( V_13 -> V_34 & V_281 ) && ! V_262 &&
V_253 && V_256 && V_268 ) {
V_33 -> V_123 = V_282 ;
V_33 -> V_283 = V_269 ;
}
if ( V_247 )
F_184 ( V_33 , F_31 ( V_284 ) , V_265 ) ;
F_185 ( V_33 , & V_1 -> V_95 [ V_75 -> V_244 ] ) ;
if ( ! ( V_13 -> V_34 & V_285 ) )
F_186 ( V_33 ) ;
else
F_187 ( & V_1 -> V_95 [ V_68 ] , V_33 ) ;
if ( V_1 -> V_286 . V_287 )
F_172 ( & V_243 -> V_288 ,
V_264 ) ;
} else {
F_42 ( V_1 -> V_3 , V_59 -> V_61 , V_59 -> V_62 ,
V_229 ) ;
F_44 ( V_33 ) ;
V_59 -> V_64 = NULL ;
}
}
static int F_188 ( struct V_67 * V_26 , struct V_65 * V_65 ,
T_4 type , T_3 V_68 , T_3 V_69 , void * V_66 )
{
struct V_1 * V_1 = F_41 ( V_26 ) ;
F_189 ( & V_1 -> V_75 [ V_68 ] , V_65 ,
V_69 , V_289 ,
F_175 , V_66 ) ;
return 0 ;
}
static void F_190 ( struct V_1 * V_1 , struct V_227 * V_75 )
{
unsigned int V_90 = F_191 ( V_1 , V_75 -> V_244 ) ;
struct V_242 * V_243 = & V_1 -> V_243 [ F_176 ( V_1 , V_75 -> V_244 ) ] ;
T_5 V_290 = V_243 -> V_291 ;
if ( V_243 -> V_291 != V_243 -> V_292 ) {
F_192 ( & V_1 -> V_90 [ V_90 ] , V_290 ) ;
V_243 -> V_292 = V_243 -> V_291 ;
}
}
static void F_193 ( struct V_1 * V_1 , struct V_227 * V_75 )
{
struct V_293 * V_294 = & V_1 -> V_286 ;
struct V_242 * V_243 = & V_1 -> V_243 [ F_176 ( V_1 , V_75 -> V_244 ) ] ;
struct V_232 * V_288 = & V_243 -> V_288 ;
int V_244 ;
T_5 V_290 ;
T_5 V_295 ;
T_5 V_296 ;
T_10 V_297 ;
T_11 V_298 = F_194 () ;
V_297 = F_195 ( V_298 , V_243 -> V_299 ) ;
if ( V_297 < V_300 )
return;
V_243 -> V_299 = V_298 ;
V_296 = V_288 -> V_236 +
V_288 -> V_237 ;
V_296 <<= 3 ;
V_296 = V_297 > V_301 ? 0 : V_296 / ( T_5 ) V_297 ;
for ( V_244 = 0 ; V_244 < V_302 ; V_244 ++ )
if ( V_296 < V_303 [ V_244 ] . V_304 )
break;
V_295 = ( V_288 -> V_237 >
V_288 -> V_236 << 1 ) ?
V_294 -> V_305 :
V_294 -> V_306 ;
V_290 = V_295 + ( ( V_294 -> V_307 - V_295 ) *
V_303 [ V_244 ] . V_308 / 100 ) ;
V_243 -> V_291 = ( V_290 + V_243 -> V_291 ) >> 1 ;
V_288 -> V_236 = 0 ;
V_288 -> V_237 = 0 ;
}
static int F_196 ( struct V_96 * V_95 , int V_309 )
{
struct V_16 * V_13 = V_95 -> V_4 ;
struct V_1 * V_1 = F_18 ( V_13 ) ;
unsigned int V_310 = F_176 ( V_1 , 0 ) ;
unsigned int V_311 = F_197 ( V_1 , 0 ) ;
unsigned int V_90 = F_71 () ;
unsigned int V_312 = V_309 ;
unsigned int V_313 = - 1 ;
unsigned int V_314 , V_315 = 0 , V_316 ;
int V_10 ;
V_316 = F_198 ( & V_1 -> V_243 [ V_311 ] , V_313 ,
F_46 , NULL ) ;
if ( V_309 > 0 )
V_315 = F_198 ( & V_1 -> V_243 [ V_310 ] ,
V_312 , F_188 , NULL ) ;
V_314 = V_315 + V_316 ;
if ( V_314 > 0 )
F_199 ( & V_1 -> V_90 [ V_90 ] ,
V_314 ,
0 ,
0 ) ;
V_10 = F_200 ( & V_1 -> V_75 [ 0 ] , F_169 ) ;
if ( V_10 )
V_315 = V_312 ;
if ( V_1 -> V_286 . V_287 )
F_193 ( V_1 , & V_1 -> V_75 [ 0 ] ) ;
if ( ( V_315 < V_309 ) && F_201 ( V_95 , V_315 ) ) {
if ( V_1 -> V_286 . V_287 )
F_190 ( V_1 , & V_1 -> V_75 [ 0 ] ) ;
F_76 ( & V_1 -> V_90 [ V_90 ] ) ;
}
return V_315 ;
}
static void F_202 ( struct V_1 * V_1 )
{
F_203 ( V_1 -> V_13 -> V_317 ) ;
V_1 -> V_13 -> V_317 = NULL ;
}
static void F_204 ( struct V_1 * V_1 )
{
int V_5 , V_318 ;
if ( F_205 ( V_1 -> V_26 ) == V_319 ) {
V_1 -> V_13 -> V_317 = F_206 ( V_1 -> V_74 ) ;
if ( F_90 ( ! V_1 -> V_13 -> V_317 ) )
return;
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
V_318 = F_207 ( V_1 -> V_13 -> V_317 ,
V_1 -> V_11 [ V_5 ] . V_12 ) ;
if ( F_90 ( V_318 ) ) {
F_202 ( V_1 ) ;
return;
}
}
}
}
static void F_202 ( struct V_1 * V_1 )
{
}
static void F_204 ( struct V_1 * V_1 )
{
}
static int F_208 ( struct V_96 * V_95 , int V_309 )
{
struct V_16 * V_13 = V_95 -> V_4 ;
struct V_1 * V_1 = F_18 ( V_13 ) ;
unsigned int V_320 = ( V_95 - & V_1 -> V_95 [ 0 ] ) - V_1 -> V_74 ;
struct V_56 * V_57 = & V_1 -> V_57 [ V_320 ] ;
unsigned int V_243 ;
unsigned int V_90 ;
unsigned int V_313 = - 1 ;
unsigned int V_316 ;
unsigned int V_321 ;
V_321 = V_57 -> V_244 ;
V_243 = F_197 ( V_1 , V_321 ) ;
V_90 = F_14 ( V_1 , V_321 ) ;
V_316 = F_198 ( & V_1 -> V_243 [ V_243 ] , V_313 ,
F_46 , NULL ) ;
F_199 ( & V_1 -> V_90 [ V_90 ] , V_316 ,
0 ,
1 ) ;
if ( ! V_316 ) {
F_209 ( V_95 ) ;
F_76 ( & V_1 -> V_90 [ V_90 ] ) ;
return 0 ;
}
return V_309 ;
}
static int F_210 ( struct V_96 * V_95 , int V_309 )
{
struct V_16 * V_13 = V_95 -> V_4 ;
struct V_1 * V_1 = F_18 ( V_13 ) ;
unsigned int V_75 = ( V_95 - & V_1 -> V_95 [ 0 ] ) ;
unsigned int V_243 = F_176 ( V_1 , V_75 ) ;
unsigned int V_90 = F_191 ( V_1 , V_75 ) ;
unsigned int V_322 = V_309 ;
unsigned int V_314 = 0 ;
int V_10 ;
if ( V_309 > 0 )
V_314 = F_198 ( & V_1 -> V_243 [ V_243 ] ,
V_322 , F_188 , NULL ) ;
if ( V_314 > 0 )
F_199 ( & V_1 -> V_90 [ V_90 ] ,
V_314 ,
0 ,
0 ) ;
V_10 = F_200 ( & V_1 -> V_75 [ V_75 ] , F_169 ) ;
if ( V_10 )
V_314 = V_322 ;
if ( V_1 -> V_286 . V_287 )
F_193 ( V_1 , & V_1 -> V_75 [ V_75 ] ) ;
if ( ( V_314 < V_309 ) && F_201 ( V_95 , V_314 ) ) {
if ( V_1 -> V_286 . V_287 )
F_190 ( V_1 , & V_1 -> V_75 [ V_75 ] ) ;
F_76 ( & V_1 -> V_90 [ V_90 ] ) ;
}
return V_314 ;
}
static void F_211 ( unsigned long V_85 )
{
struct V_1 * V_1 = (struct V_1 * ) V_85 ;
F_69 ( V_1 ) ;
F_212 ( & V_1 -> V_323 ,
F_213 ( V_324 + V_325 ) ) ;
}
static void F_214 ( struct V_1 * V_1 )
{
struct V_16 * V_13 = V_1 -> V_13 ;
unsigned int V_5 ;
F_202 ( V_1 ) ;
switch ( F_205 ( V_1 -> V_26 ) ) {
case V_326 :
F_215 ( V_1 -> V_3 -> V_84 , V_13 ) ;
break;
case V_327 :
F_215 ( V_1 -> V_3 -> V_84 , V_1 ) ;
break;
case V_319 :
for ( V_5 = 0 ; V_5 < F_216 ( V_1 -> V_7 ) ; V_5 ++ )
if ( V_1 -> V_7 [ V_5 ] . V_328 )
F_215 ( V_1 -> V_11 [ V_5 ] . V_12 ,
V_1 -> V_7 [ V_5 ] . V_329 ) ;
break;
default:
break;
}
}
static int F_217 ( struct V_1 * V_1 )
{
struct V_16 * V_13 = V_1 -> V_13 ;
unsigned int V_5 , V_90 ;
int V_10 = 0 ;
F_204 ( V_1 ) ;
switch ( F_205 ( V_1 -> V_26 ) ) {
case V_326 :
V_10 = F_218 ( V_1 -> V_3 -> V_84 , F_70 ,
V_330 , V_13 -> V_208 , V_13 ) ;
break;
case V_327 :
V_10 = F_218 ( V_1 -> V_3 -> V_84 , F_80 ,
0 , V_13 -> V_208 , V_1 ) ;
break;
case V_319 :
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
V_90 = F_191 ( V_1 , V_5 ) ;
snprintf ( V_1 -> V_7 [ V_90 ] . V_331 ,
sizeof( V_1 -> V_7 [ V_90 ] . V_331 ) ,
L_22 , V_13 -> V_208 , V_5 ) ;
V_1 -> V_7 [ V_90 ] . V_332 = F_81 ;
V_1 -> V_7 [ V_90 ] . V_329 = & V_1 -> V_95 [ V_5 ] ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
int V_57 = F_197 ( V_1 , V_5 ) ;
V_90 = F_14 ( V_1 , V_5 ) ;
snprintf ( V_1 -> V_7 [ V_90 ] . V_331 ,
sizeof( V_1 -> V_7 [ V_90 ] . V_331 ) ,
L_23 , V_13 -> V_208 , V_5 ) ;
V_1 -> V_7 [ V_90 ] . V_332 = F_81 ;
V_1 -> V_7 [ V_90 ] . V_329 = & V_1 -> V_95 [ V_57 ] ;
}
V_90 = F_83 ( V_1 ) ;
snprintf ( V_1 -> V_7 [ V_90 ] . V_331 ,
sizeof( V_1 -> V_7 [ V_90 ] . V_331 ) ,
L_24 , V_13 -> V_208 ) ;
V_1 -> V_7 [ V_90 ] . V_332 = F_82 ;
V_1 -> V_7 [ V_90 ] . V_329 = V_1 ;
V_90 = F_85 ( V_1 ) ;
snprintf ( V_1 -> V_7 [ V_90 ] . V_331 ,
sizeof( V_1 -> V_7 [ V_90 ] . V_331 ) ,
L_25 , V_13 -> V_208 ) ;
V_1 -> V_7 [ V_90 ] . V_332 = F_84 ;
V_1 -> V_7 [ V_90 ] . V_329 = V_1 ;
for ( V_5 = 0 ; V_5 < F_216 ( V_1 -> V_7 ) ; V_5 ++ )
V_1 -> V_7 [ V_5 ] . V_328 = 0 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
V_10 = F_218 ( V_1 -> V_11 [ V_5 ] . V_12 ,
V_1 -> V_7 [ V_5 ] . V_332 , 0 ,
V_1 -> V_7 [ V_5 ] . V_331 ,
V_1 -> V_7 [ V_5 ] . V_329 ) ;
if ( V_10 ) {
F_214 ( V_1 ) ;
break;
}
V_1 -> V_7 [ V_5 ] . V_328 = 1 ;
}
break;
default:
break;
}
return V_10 ;
}
static void F_219 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
switch ( F_205 ( V_1 -> V_26 ) ) {
case V_326 :
case V_327 :
F_220 ( V_1 -> V_3 -> V_84 ) ;
break;
case V_319 :
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_220 ( V_1 -> V_11 [ V_5 ] . V_12 ) ;
break;
default:
break;
}
}
static void F_221 ( struct V_1 * V_1 )
{
unsigned int V_333 ;
int V_244 = - 1 ;
struct V_293 * V_294 = & V_1 -> V_286 ;
V_333 = F_222 ( V_1 -> V_26 ) ;
if ( V_334 < V_333 )
V_244 = V_335 ;
else if ( V_336 < V_333 )
V_244 = V_337 ;
else
V_244 = V_338 ;
V_294 -> V_305 = V_339 [ V_244 ] . V_305 ;
V_294 -> V_306 = V_339 [ V_244 ] . V_306 ;
V_294 -> V_307 = V_340 ;
for ( V_244 = 0 ; V_244 < V_1 -> V_74 ; V_244 ++ )
V_1 -> V_243 [ V_244 ] . V_292 =
V_1 -> V_341 . V_342 ;
V_294 -> V_287 = 1 ;
}
static int F_223 ( struct V_1 * V_1 )
{
int V_10 ;
F_19 ( & V_1 -> V_20 ) ;
switch ( F_205 ( V_1 -> V_26 ) ) {
case V_326 :
V_10 = F_224 ( V_1 -> V_26 ,
F_73 () ) ;
break;
case V_319 :
V_10 = F_224 ( V_1 -> V_26 ,
F_85 ( V_1 ) ) ;
break;
default:
V_10 = F_224 ( V_1 -> V_26 , - 1 ) ;
break;
}
F_24 ( & V_1 -> V_20 ) ;
return V_10 ;
}
static void F_225 ( struct V_1 * V_1 )
{
switch ( F_205 ( V_1 -> V_26 ) ) {
case V_327 :
F_212 ( & V_1 -> V_323 , V_324 ) ;
break;
default:
break;
}
}
static int F_226 ( struct V_16 * V_13 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
unsigned int V_5 ;
int V_10 ;
V_10 = F_217 ( V_1 ) ;
if ( V_10 ) {
F_26 ( V_13 , L_26 ) ;
return V_10 ;
}
F_1 ( V_1 ) ;
F_11 ( V_1 ) ;
V_10 = F_223 ( V_1 ) ;
if ( V_10 ) {
F_26 ( V_13 ,
L_27 ) ;
goto V_343;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
F_200 ( & V_1 -> V_75 [ V_5 ] , F_169 ) ;
if ( F_227 ( & V_1 -> V_75 [ V_5 ] ) == 0 ) {
F_26 ( V_13 , L_28 ) ;
V_10 = - V_102 ;
goto V_344;
}
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_228 ( & V_1 -> V_57 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ )
F_229 ( & V_1 -> V_75 [ V_5 ] ) ;
if ( ! F_35 ( V_1 ) && ! F_37 ( V_1 ) )
F_147 ( V_1 ) ;
F_149 ( V_13 ) ;
F_230 ( V_13 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ )
F_231 ( & V_1 -> V_95 [ V_5 ] ) ;
if ( F_205 ( V_1 -> V_26 ) == V_319 )
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_231 ( & V_1 -> V_95 [ F_197 ( V_1 , V_5 ) ] ) ;
F_232 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_76 ( & V_1 -> V_90 [ V_5 ] ) ;
F_225 ( V_1 ) ;
F_233 ( V_1 ) ;
return 0 ;
V_344:
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ )
F_234 ( & V_1 -> V_75 [ V_5 ] , F_168 ) ;
F_235 ( V_1 ) ;
V_343:
F_16 ( V_1 ) ;
F_214 ( V_1 ) ;
return V_10 ;
}
static int F_236 ( struct V_16 * V_13 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
unsigned int V_5 ;
int V_10 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
F_74 ( & V_1 -> V_90 [ V_5 ] ) ;
( void ) F_237 ( & V_1 -> V_90 [ V_5 ] ) ;
}
F_219 ( V_1 ) ;
F_238 ( & V_1 -> V_323 ) ;
F_239 ( V_1 ) ;
F_240 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ )
F_241 ( & V_1 -> V_95 [ V_5 ] ) ;
F_68 ( V_13 ) ;
F_242 ( V_13 ) ;
if ( F_205 ( V_1 -> V_26 ) == V_319 )
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_241 ( & V_1 -> V_95 [ F_197 ( V_1 , V_5 ) ] ) ;
if ( ! F_35 ( V_1 ) && ! F_37 ( V_1 ) )
F_146 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
V_10 = F_243 ( & V_1 -> V_57 [ V_5 ] ) ;
if ( V_10 )
return V_10 ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
V_10 = F_244 ( & V_1 -> V_75 [ V_5 ] ) ;
if ( V_10 )
return V_10 ;
}
F_235 ( V_1 ) ;
F_16 ( V_1 ) ;
F_214 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_245 ( & V_1 -> V_57 [ V_5 ] , F_40 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ )
F_234 ( & V_1 -> V_75 [ V_5 ] , F_168 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_345 ; V_5 ++ )
F_246 ( & V_1 -> V_243 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_247 ( & V_1 -> V_90 [ V_5 ] ) ;
return 0 ;
}
static int F_248 ( struct V_16 * V_13 , int V_346 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
int V_347 = F_145 ( V_13 ) ;
if ( F_35 ( V_1 ) || F_37 ( V_1 ) )
return - V_202 ;
if ( V_347 )
F_236 ( V_13 ) ;
V_13 -> V_77 = V_346 ;
if ( V_13 -> V_77 > V_1 -> V_78 )
F_13 ( V_13 ,
L_29 ,
V_13 -> V_77 , V_1 -> V_78 ) ;
if ( V_347 )
F_226 ( V_13 ) ;
return 0 ;
}
static void F_249 ( struct V_348 * V_349 )
{
struct V_1 * V_1 = F_250 ( V_349 , struct V_1 , V_81 ) ;
struct V_16 * V_13 = V_1 -> V_13 ;
int V_346 = F_60 ( V_1 -> V_26 ) ;
int V_10 ;
unsigned int V_5 ;
V_346 = F_61 ( int , V_79 , F_62 ( int , V_80 , V_346 ) ) ;
F_251 () ;
F_238 ( & V_1 -> V_323 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ )
F_241 ( & V_1 -> V_95 [ V_5 ] ) ;
F_74 ( & V_1 -> V_90 [ 0 ] ) ;
F_219 ( V_1 ) ;
V_10 = F_244 ( & V_1 -> V_75 [ 0 ] ) ;
if ( V_10 ) {
F_252 () ;
F_26 ( V_13 , L_30 ) ;
return;
}
F_234 ( & V_1 -> V_75 [ 0 ] , F_168 ) ;
F_246 ( & V_1 -> V_243 [ 0 ] ) ;
F_247 ( & V_1 -> V_90 [ 0 ] ) ;
V_13 -> V_77 = V_346 ;
F_200 ( & V_1 -> V_75 [ 0 ] , F_169 ) ;
if ( F_227 ( & V_1 -> V_75 [ 0 ] ) == 0 ) {
F_252 () ;
F_26 ( V_13 , L_31 ) ;
return;
}
F_229 ( & V_1 -> V_75 [ 0 ] ) ;
F_231 ( & V_1 -> V_95 [ 0 ] ) ;
F_76 ( & V_1 -> V_90 [ 0 ] ) ;
F_225 ( V_1 ) ;
F_252 () ;
F_20 ( V_13 , L_32 , V_13 -> V_77 ) ;
}
static void F_253 ( struct V_16 * V_13 )
{
struct V_1 * V_1 = F_18 ( V_13 ) ;
struct V_67 * V_26 = V_1 -> V_26 ;
unsigned int V_5 , V_90 ;
switch ( F_205 ( V_26 ) ) {
case V_319 :
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
V_90 = F_191 ( V_1 , V_5 ) ;
F_81 ( V_1 -> V_11 [ V_90 ] . V_12 ,
& V_1 -> V_95 [ V_5 ] ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
V_90 = F_14 ( V_1 , V_5 ) ;
F_81 ( V_1 -> V_11 [ V_90 ] . V_12 ,
& V_1 -> V_95 [ F_197 ( V_1 , V_5 ) ] ) ;
}
break;
case V_327 :
F_80 ( V_1 -> V_3 -> V_84 , V_1 ) ;
break;
case V_326 :
F_70 ( V_1 -> V_3 -> V_84 , V_13 ) ;
break;
default:
break;
}
}
static int F_254 ( struct V_67 * V_26 ,
int (* F_255)( struct V_67 * , int ) ,
int (* F_256)( struct V_67 * , int * ) ,
int V_350 )
{
unsigned long time ;
int V_351 ;
int V_10 ;
F_257 ( F_258 () ) ;
V_10 = F_255 ( V_26 , V_350 ) ;
if ( V_10 )
return V_10 ;
time = V_324 + ( V_352 * 2 ) ;
do {
V_10 = F_256 ( V_26 , & V_351 ) ;
if ( V_10 )
return V_10 ;
if ( V_351 )
return 0 ;
F_259 ( V_352 / 10 ) ;
} while ( F_260 ( time , V_324 ) );
return - V_353 ;
}
static int F_261 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_254 ( V_1 -> V_26 , V_354 ,
V_355 , 0 ) ;
if ( V_10 )
F_262 ( F_263 ( V_1 ) , L_33 ,
V_10 ) ;
return V_10 ;
}
static int F_264 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_254 ( V_1 -> V_26 , V_356 ,
V_357 , 0 ) ;
if ( V_10 )
F_26 ( V_1 -> V_13 , L_34 ,
V_10 ) ;
return V_10 ;
}
static int F_265 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_254 ( V_1 -> V_26 , V_358 ,
V_359 , 0 ) ;
if ( V_10 )
F_26 ( V_1 -> V_13 , L_35 ,
V_10 ) ;
return V_10 ;
}
int F_266 ( struct V_1 * V_1 )
{
union V_360 * V_361 ;
T_8 V_362 ;
int V_5 , V_363 , V_364 , V_10 ;
V_361 = F_267 ( V_1 -> V_3 ,
sizeof( union V_360 ) ,
& V_362 ) ;
if ( ! V_361 )
return - V_102 ;
for ( V_5 = 0 ; V_5 < V_365 ; V_5 ++ ) {
V_363 = V_5 / V_366 ;
V_364 = V_5 % V_366 ;
V_361 -> V_367 [ V_363 ] . V_368 [ V_364 ] = V_1 -> V_369 [ V_5 ] ;
}
F_19 ( & V_1 -> V_20 ) ;
V_10 = F_268 ( V_1 ,
V_362 ,
sizeof( union V_360 ) ) ;
F_24 ( & V_1 -> V_20 ) ;
F_269 ( V_1 -> V_3 , sizeof( union V_360 ) ,
V_361 , V_362 ) ;
return V_10 ;
}
static int F_270 ( struct V_1 * V_1 )
{
F_271 ( V_1 -> V_369 , V_365 ) ;
return F_266 ( V_1 ) ;
}
static int F_272 ( struct V_1 * V_1 , T_4 V_370 )
{
T_8 V_371 ;
union V_372 * V_373 = NULL ;
unsigned int V_5 ;
int V_10 ;
V_373 = F_273 ( V_1 -> V_3 ,
sizeof( union V_372 ) , & V_371 ) ;
if ( ! V_373 )
return - V_102 ;
for ( V_5 = 0 ; V_5 < ( 1 << V_370 ) ; V_5 ++ )
( * V_373 ) . V_374 [ V_5 / 4 ] . V_368 [ V_5 % 4 ] = V_5 % V_1 -> V_74 ;
F_19 ( & V_1 -> V_20 ) ;
V_10 = F_274 ( V_1 ,
V_371 ,
sizeof( union V_372 ) ) ;
F_24 ( & V_1 -> V_20 ) ;
F_269 ( V_1 -> V_3 , sizeof( union V_372 ) ,
V_373 , V_371 ) ;
return V_10 ;
}
static int F_275 ( struct V_1 * V_1 , T_4 V_375 ,
T_4 V_376 , T_4 V_370 , T_4 V_377 , T_4 V_378 )
{
const T_4 V_379 = 0 ;
const T_4 V_380 = 1 ;
int V_10 ;
F_19 ( & V_1 -> V_20 ) ;
V_10 = F_276 ( V_1 ,
V_375 , V_376 ,
V_370 , V_377 ,
V_378 , V_379 ,
V_380 ) ;
F_24 ( & V_1 -> V_20 ) ;
return V_10 ;
}
static int F_277 ( struct V_1 * V_1 )
{
struct V_49 * V_4 = F_263 ( V_1 ) ;
const T_4 V_375 = 0 ;
const T_4 V_376 = V_381 |
V_382 |
V_383 |
V_384 ;
const T_4 V_370 = 7 ;
const T_4 V_377 = 0 ;
T_4 V_378 = F_278 ( V_1 , V_385 ) && ( V_1 -> V_74 > 1 ) ;
if ( V_378 ) {
if ( ! F_270 ( V_1 ) ) {
if ( F_272 ( V_1 , V_370 ) ) {
V_378 = 0 ;
F_279 ( V_4 , L_36
L_37 ) ;
}
} else {
V_378 = 0 ;
F_279 ( V_4 , L_38 ) ;
}
}
return F_275 ( V_1 , V_375 , V_376 ,
V_370 , V_377 , V_378 ) ;
}
static void F_280 ( struct V_348 * V_349 )
{
struct V_1 * V_1 = F_250 ( V_349 , struct V_1 , V_93 ) ;
if ( ! F_145 ( V_1 -> V_13 ) )
return;
F_251 () ;
F_47 ( & V_1 -> V_386 ) ;
F_236 ( V_1 -> V_13 ) ;
F_264 ( V_1 ) ;
F_138 ( V_1 ) ;
F_281 ( V_1 ) ;
F_277 ( V_1 ) ;
F_282 ( V_1 ) ;
F_226 ( V_1 -> V_13 ) ;
F_53 ( & V_1 -> V_386 ) ;
F_283 ( V_387 , V_1 -> V_13 ) ;
F_252 () ;
}
static void F_284 ( struct V_348 * V_349 )
{
struct V_1 * V_1 = F_250 ( V_349 , struct V_1 , V_189 ) ;
F_251 () ;
F_47 ( & V_1 -> V_386 ) ;
F_285 ( V_1 ) ;
F_236 ( V_1 -> V_13 ) ;
F_265 ( V_1 ) ;
F_138 ( V_1 ) ;
F_281 ( V_1 ) ;
F_277 ( V_1 ) ;
F_282 ( V_1 ) ;
F_226 ( V_1 -> V_13 ) ;
F_53 ( & V_1 -> V_386 ) ;
F_283 ( V_387 , V_1 -> V_13 ) ;
F_252 () ;
}
static int F_286 ( struct V_1 * V_1 )
{
unsigned int V_388 = F_62 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_389 = F_62 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_5 ;
F_257 ( F_216 ( V_1 -> V_11 ) < V_388 + V_389 + 2 ) ;
for ( V_5 = 0 ; V_5 < V_388 + V_389 + 2 ; V_5 ++ )
V_1 -> V_11 [ V_5 ] . V_390 = V_5 ;
if ( F_278 ( V_1 , V_385 ) &&
V_1 -> V_341 . V_391 < 1 &&
V_1 -> V_74 >= V_388 &&
V_1 -> V_14 >= V_389 &&
V_1 -> V_345 >= V_388 + V_389 &&
V_1 -> V_6 >= V_388 + V_389 + 2 ) {
if ( F_287 ( V_1 -> V_3 , V_1 -> V_11 ,
V_388 + V_389 + 2 , V_388 + V_389 + 2 ) > 0 ) {
V_1 -> V_74 = V_388 ;
V_1 -> V_14 = V_389 ;
V_1 -> V_345 = V_388 + V_389 ;
V_1 -> V_6 = V_388 + V_389 + 2 ;
F_288 ( V_1 -> V_26 ,
V_319 ) ;
return 0 ;
}
}
if ( V_1 -> V_341 . V_391 < 1 &&
V_1 -> V_74 >= 1 &&
V_1 -> V_14 >= V_389 &&
V_1 -> V_345 >= 1 + V_389 &&
V_1 -> V_6 >= 1 + V_389 + 2 ) {
if ( F_287 ( V_1 -> V_3 , V_1 -> V_11 ,
1 + V_389 + 2 , 1 + V_389 + 2 ) > 0 ) {
V_1 -> V_74 = 1 ;
V_1 -> V_14 = V_389 ;
V_1 -> V_345 = 1 + V_389 ;
V_1 -> V_6 = 1 + V_389 + 2 ;
F_288 ( V_1 -> V_26 ,
V_319 ) ;
return 0 ;
}
}
if ( V_1 -> V_341 . V_391 < 2 &&
V_1 -> V_74 >= 1 &&
V_1 -> V_14 >= 1 &&
V_1 -> V_345 >= 2 &&
V_1 -> V_6 >= 1 &&
! F_289 ( V_1 -> V_3 ) ) {
V_1 -> V_74 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_345 = 2 ;
V_1 -> V_6 = 1 ;
F_288 ( V_1 -> V_26 , V_327 ) ;
return 0 ;
}
if ( V_1 -> V_341 . V_391 < 3 &&
V_1 -> V_74 >= 1 &&
V_1 -> V_14 >= 1 &&
V_1 -> V_345 >= 2 &&
V_1 -> V_6 >= 3 ) {
V_1 -> V_74 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_345 = 2 ;
V_1 -> V_6 = 3 ;
F_288 ( V_1 -> V_26 , V_326 ) ;
return 0 ;
}
F_288 ( V_1 -> V_26 , V_392 ) ;
return - V_197 ;
}
static void F_290 ( struct V_1 * V_1 )
{
switch ( F_205 ( V_1 -> V_26 ) ) {
case V_319 :
F_291 ( V_1 -> V_3 ) ;
break;
case V_327 :
F_292 ( V_1 -> V_3 ) ;
break;
default:
break;
}
F_288 ( V_1 -> V_26 , V_392 ) ;
}
static void F_293 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
F_294 ( & V_1 -> V_95 [ V_5 ] ) ;
F_295 ( & V_1 -> V_95 [ V_5 ] ) ;
}
if ( F_205 ( V_1 -> V_26 ) == V_319 )
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_295 ( & V_1 -> V_95 [ F_197 ( V_1 , V_5 ) ] ) ;
F_296 ( V_1 ) ;
F_290 ( V_1 ) ;
F_9 ( V_1 ) ;
}
static void F_297 ( struct V_1 * V_1 )
{
if ( F_298 () ) {
F_299 ( F_263 ( V_1 ) , L_39 ) ;
V_1 -> V_74 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_341 . V_393 = V_394 ;
V_1 -> V_341 . V_395 = V_396 ;
V_1 -> V_341 . V_77 = F_62 ( T_3 , 1500 , V_1 -> V_341 . V_77 ) ;
}
}
static int F_300 ( struct V_1 * V_1 )
{
struct V_49 * V_4 = F_263 ( V_1 ) ;
struct V_16 * V_13 = V_1 -> V_13 ;
unsigned int V_5 ;
int V_10 ;
V_10 = F_301 ( V_1 ) ;
if ( V_10 ) {
F_279 ( V_4 , L_40
L_41 ) ;
F_302 ( V_1 -> V_26 ) ;
}
V_10 = F_303 ( V_1 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_42 ) ;
return V_10 ;
}
F_304 ( V_1 ) ;
F_297 ( V_1 ) ;
V_10 = F_286 ( V_1 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_43
L_44 ) ;
return V_10 ;
}
V_10 = F_305 ( V_1 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_45 ) ;
goto V_397;
}
F_281 ( V_1 ) ;
V_10 = F_277 ( V_1 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_46 ) ;
goto V_397;
}
switch ( F_205 ( V_1 -> V_26 ) ) {
default:
F_306 ( V_13 , & V_1 -> V_95 [ 0 ] , F_196 , 64 ) ;
break;
case V_319 :
for ( V_5 = 0 ; V_5 < V_1 -> V_74 ; V_5 ++ ) {
F_306 ( V_13 , & V_1 -> V_95 [ V_5 ] ,
F_210 , V_398 ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_306 ( V_13 , & V_1 -> V_95 [ F_197 ( V_1 , V_5 ) ] ,
F_208 , V_398 ) ;
break;
}
return 0 ;
V_397:
F_9 ( V_1 ) ;
F_290 ( V_1 ) ;
F_296 ( V_1 ) ;
return V_10 ;
}
static void F_307 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_216 ( V_1 -> V_399 ) ; V_5 ++ )
if ( V_1 -> V_399 [ V_5 ] . V_400 )
F_308 ( V_1 -> V_399 [ V_5 ] . V_400 ) ;
}
static int F_309 ( struct V_401 * V_3 , const struct V_402 * V_403 )
{
struct V_49 * V_4 = & V_3 -> V_4 ;
struct V_16 * V_13 ;
struct V_1 * V_1 ;
int V_404 = 0 ;
unsigned int V_5 ;
int V_10 ;
#ifdef F_39
int V_405 = 0 ;
#endif
int V_406 = 1 ;
V_13 = F_310 ( sizeof( struct V_1 ) ,
V_407 , V_408 ) ;
if ( ! V_13 )
return - V_102 ;
F_311 ( V_3 , V_13 ) ;
F_312 ( V_13 , & V_3 -> V_4 ) ;
V_1 = F_18 ( V_13 ) ;
V_1 -> V_13 = V_13 ;
V_1 -> V_3 = V_3 ;
V_10 = F_313 ( V_3 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_47 ) ;
goto V_409;
}
V_10 = F_314 ( V_3 , V_410 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_48 ) ;
goto V_411;
}
F_315 ( V_3 ) ;
V_10 = F_316 ( V_3 , F_317 ( 64 ) ) ;
if ( V_10 ) {
V_10 = F_316 ( V_3 , F_317 ( 32 ) ) ;
if ( V_10 ) {
F_262 ( V_4 , L_49 ) ;
goto V_412;
}
V_10 = F_318 ( V_3 , F_317 ( 32 ) ) ;
if ( V_10 ) {
F_262 ( V_4 , L_50
L_51 , 32 ) ;
goto V_412;
}
} else {
V_10 = F_318 ( V_3 , F_317 ( 64 ) ) ;
if ( V_10 ) {
F_262 ( V_4 , L_50
L_51 , 64 ) ;
goto V_412;
}
V_404 = 1 ;
}
for ( V_5 = 0 ; V_5 < F_216 ( V_1 -> V_399 ) ; V_5 ++ ) {
if ( ! ( F_319 ( V_3 , V_5 ) & V_413 ) )
continue;
V_1 -> V_399 [ V_5 ] . V_62 = F_320 ( V_3 , V_5 ) ;
V_1 -> V_399 [ V_5 ] . V_400 = F_321 ( V_3 , V_5 , V_1 -> V_399 [ V_5 ] . V_62 ) ;
if ( ! V_1 -> V_399 [ V_5 ] . V_400 ) {
F_262 ( V_4 , L_52 , V_5 ) ;
V_10 = - V_414 ;
goto V_415;
}
V_1 -> V_399 [ V_5 ] . V_416 = F_322 ( V_3 , V_5 ) ;
}
V_1 -> V_26 = F_323 ( NULL , V_1 , V_3 , V_1 -> V_399 ,
F_216 ( V_1 -> V_399 ) ) ;
if ( ! V_1 -> V_26 ) {
F_262 ( V_4 , L_53 ) ;
V_10 = - V_414 ;
goto V_415;
}
V_10 = F_324 ( V_1 -> V_26 ) ;
if ( V_10 )
goto V_417;
#ifdef F_39
V_405 = F_325 ( V_3 , V_418 ) ;
if ( V_405 ) {
F_326 ( V_3 , V_405 + V_419 ,
& V_1 -> V_55 ) ;
if ( V_1 -> V_55 ) {
V_10 = F_327 ( V_3 , V_1 -> V_55 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_54
L_55 ,
V_10 ) ;
goto V_417;
}
V_1 -> V_51 |= V_52 ;
V_406 = V_1 -> V_55 ;
}
}
#endif
V_1 -> V_192 = F_328 ( V_406 , sizeof( * V_1 -> V_192 ) , V_9 ) ;
if ( ! V_1 -> V_192 ) {
V_10 = - V_102 ;
goto V_420;
}
V_10 = F_261 ( V_1 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_56 ) ;
goto V_421;
}
F_329 ( & V_1 -> V_20 ) ;
F_329 ( & V_1 -> V_386 ) ;
V_10 = F_282 ( V_1 ) ;
if ( V_10 ) {
F_262 ( V_4 ,
L_57 ) ;
goto V_422;
}
F_68 ( V_13 ) ;
if ( ! F_35 ( V_1 ) ) {
V_10 = F_330 ( V_1 -> V_26 , 0 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_58 ) ;
goto V_422;
}
}
V_10 = F_300 ( V_1 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_59 ) ;
goto V_422;
}
F_331 ( V_13 , V_1 -> V_14 ) ;
F_332 ( V_13 , V_1 -> V_74 ) ;
F_333 ( & V_1 -> V_323 ) ;
V_1 -> V_323 . V_423 = F_211 ;
V_1 -> V_323 . V_85 = ( unsigned long ) V_1 ;
F_221 ( V_1 ) ;
F_334 ( & V_1 -> V_93 , F_280 ) ;
F_334 ( & V_1 -> V_189 , F_284 ) ;
F_334 ( & V_1 -> V_81 , F_249 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_329 ( & V_1 -> V_70 [ V_5 ] ) ;
V_1 -> V_78 = V_1 -> V_341 . V_77 ;
( void ) F_248 ( V_13 , V_1 -> V_78 ) ;
V_10 = F_141 ( V_13 , V_1 -> V_217 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_60 ) ;
goto V_424;
}
V_1 -> V_425 = V_1 -> V_341 . V_342 ;
V_1 -> V_426 = V_1 -> V_425 ;
if ( F_35 ( V_1 ) || F_37 ( V_1 ) )
V_13 -> V_427 = & V_428 ;
else
V_13 -> V_427 = & V_429 ;
V_13 -> V_430 = 2 * V_352 ;
F_335 ( V_13 ) ;
V_13 -> V_34 |= V_431 | V_432 ;
if ( F_278 ( V_1 , V_433 ) ) {
V_13 -> V_34 &= ~ V_431 ;
V_1 -> V_121 = 1 ;
V_1 -> V_122 = V_1 -> V_341 . V_122 ;
F_299 ( V_4 , L_61 , V_1 -> V_122 ) ;
}
if ( F_278 ( V_1 , V_434 ) )
V_13 -> V_435 |= V_436 | V_437 ;
if ( F_278 ( V_1 , V_438 ) )
V_13 -> V_435 |= V_439 |
V_440 | V_441 ;
if ( F_278 ( V_1 , V_385 ) )
V_13 -> V_435 |= V_272 ;
if ( F_278 ( V_1 , V_442 ) )
V_13 -> V_435 |= V_281 ;
if ( F_278 ( V_1 , V_443 ) ) {
T_10 V_29 ;
V_13 -> V_444 |= V_281 |
V_439 |
V_441 |
V_445 |
V_437 |
V_446 ;
V_13 -> V_435 |= V_13 -> V_444 ;
V_10 = F_336 ( V_1 -> V_26 ,
V_447 ,
& V_29 ) ;
if ( V_10 )
V_29 = 0 ;
V_29 &= F_337 ( 0 ) | F_337 ( 2 ) ;
V_29 = F_338 ( V_29 ) ;
V_29 = V_29 ? V_29 - 1 : 0 ;
V_1 -> V_24 . V_29 = V_29 ;
}
V_13 -> V_34 |= V_13 -> V_435 ;
V_13 -> V_448 |= V_13 -> V_34 ;
#ifdef F_339
V_13 -> V_435 |= V_449 ;
#endif
if ( V_404 )
V_13 -> V_34 |= V_450 ;
V_13 -> V_51 |= V_451 ;
V_13 -> V_452 = V_79 ;
V_13 -> V_453 = V_80 ;
V_10 = F_340 ( V_13 ) ;
if ( V_10 ) {
F_262 ( V_4 , L_62 ) ;
goto V_424;
}
V_1 -> V_239 = V_454 ;
return 0 ;
V_424:
F_293 ( V_1 ) ;
V_422:
F_341 ( V_1 -> V_26 ) ;
V_421:
F_342 ( V_1 -> V_192 ) ;
V_420:
#ifdef F_39
if ( F_36 ( V_1 ) ) {
F_343 ( V_3 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
#endif
V_417:
F_344 ( V_1 -> V_26 ) ;
V_415:
F_307 ( V_1 ) ;
V_412:
F_345 ( V_3 ) ;
V_411:
F_346 ( V_3 ) ;
V_409:
F_347 ( V_13 ) ;
return V_10 ;
}
static void F_348 ( struct V_401 * V_3 )
{
struct V_16 * V_13 = F_349 ( V_3 ) ;
if ( V_13 ) {
struct V_1 * V_1 = F_18 ( V_13 ) ;
F_350 ( & V_1 -> V_93 ) ;
F_350 ( & V_1 -> V_81 ) ;
F_351 ( V_13 ) ;
F_293 ( V_1 ) ;
F_341 ( V_1 -> V_26 ) ;
#ifdef F_39
if ( F_36 ( V_1 ) ) {
F_343 ( V_3 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
#endif
F_342 ( V_1 -> V_192 ) ;
F_344 ( V_1 -> V_26 ) ;
F_307 ( V_1 ) ;
F_345 ( V_3 ) ;
F_346 ( V_3 ) ;
F_347 ( V_13 ) ;
}
}
static int T_12 F_352 ( void )
{
F_353 ( L_63 , V_455 , V_456 ) ;
return F_354 ( & V_457 ) ;
}
static void T_13 F_355 ( void )
{
F_356 ( & V_457 ) ;
}
