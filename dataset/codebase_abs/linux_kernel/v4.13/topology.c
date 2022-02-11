static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static inline bool F_2 ( void )
{
return V_2 ;
}
static int F_3 ( struct V_3 * V_4 , int V_5 , int V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_4 -> V_11 ;
F_4 ( V_8 ) ;
F_5 ( V_12 L_1 , V_6 , L_2 , V_6 ) ;
if ( ! ( V_4 -> V_13 & V_14 ) ) {
F_5 ( L_3 ) ;
if ( V_4 -> V_15 )
F_5 ( V_16 L_4
L_5 ) ;
return - 1 ;
}
F_5 ( V_17 L_6 ,
F_6 ( F_7 ( V_4 ) ) , V_4 -> V_18 ) ;
if ( ! F_8 ( V_5 , F_7 ( V_4 ) ) ) {
F_5 ( V_16 L_7
L_8 , V_5 ) ;
}
if ( ! F_8 ( V_5 , F_9 ( V_10 ) ) ) {
F_5 ( V_16 L_9
L_10 , V_5 ) ;
}
F_5 ( V_12 L_11 , V_6 + 1 , L_2 ) ;
do {
if ( ! V_10 ) {
F_5 ( L_12 ) ;
F_5 ( V_16 L_13 ) ;
break;
}
if ( ! F_10 ( F_9 ( V_10 ) ) ) {
F_5 ( V_17 L_12 ) ;
F_5 ( V_16 L_14 ) ;
break;
}
if ( ! ( V_4 -> V_13 & V_19 ) &&
F_11 ( V_8 , F_9 ( V_10 ) ) ) {
F_5 ( V_17 L_12 ) ;
F_5 ( V_16 L_15 ) ;
break;
}
F_12 ( V_8 , V_8 , F_9 ( V_10 ) ) ;
F_5 ( V_17 L_16 ,
V_10 -> V_20 -> V_21 ,
F_6 ( F_9 ( V_10 ) ) ) ;
if ( ( V_4 -> V_13 & V_19 ) &&
! F_13 ( F_14 ( V_10 ) , F_9 ( V_10 ) ) ) {
F_5 ( V_17 L_17 ,
F_6 ( F_14 ( V_10 ) ) ) ;
}
if ( V_10 -> V_20 -> V_22 != V_23 )
F_5 ( V_17 L_18 , V_10 -> V_20 -> V_22 ) ;
if ( V_10 == V_4 -> V_11 && V_4 -> V_24 &&
! F_13 ( F_7 ( V_4 -> V_24 ) ,
F_9 ( V_10 ) ) ) {
F_5 ( V_16 L_19 ) ;
}
F_5 ( V_17 L_20 ) ;
V_10 = V_10 -> V_25 ;
if ( V_10 != V_4 -> V_11 )
F_5 ( V_17 L_21 ) ;
} while ( V_10 != V_4 -> V_11 );
F_5 ( V_17 L_12 ) ;
if ( ! F_13 ( F_7 ( V_4 ) , V_8 ) )
F_5 ( V_16 L_22 ) ;
if ( V_4 -> V_15 &&
! F_15 ( V_8 , F_7 ( V_4 -> V_15 ) ) )
F_5 ( V_16 L_23
L_24 ) ;
return 0 ;
}
static void F_16 ( struct V_3 * V_4 , int V_5 )
{
int V_6 = 0 ;
if ( ! V_2 )
return;
if ( ! V_4 ) {
F_5 ( V_12 L_25 , V_5 ) ;
return;
}
F_5 ( V_12 L_26 , V_5 ) ;
for (; ; ) {
if ( F_3 ( V_4 , V_5 , V_6 , V_26 ) )
break;
V_6 ++ ;
V_4 = V_4 -> V_15 ;
if ( ! V_4 )
break;
}
}
static inline bool F_2 ( void )
{
return false ;
}
static int F_17 ( struct V_3 * V_4 )
{
if ( F_10 ( F_7 ( V_4 ) ) == 1 )
return 1 ;
if ( V_4 -> V_13 & ( V_14 |
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 ) ) {
if ( V_4 -> V_11 != V_4 -> V_11 -> V_25 )
return 0 ;
}
if ( V_4 -> V_13 & ( V_34 ) )
return 0 ;
return 1 ;
}
static int
F_18 ( struct V_3 * V_4 , struct V_3 * V_15 )
{
unsigned long V_35 = V_4 -> V_13 , V_36 = V_15 -> V_13 ;
if ( F_17 ( V_15 ) )
return 1 ;
if ( ! F_13 ( F_7 ( V_4 ) , F_7 ( V_15 ) ) )
return 0 ;
if ( V_15 -> V_11 == V_15 -> V_11 -> V_25 ) {
V_36 &= ~ ( V_14 |
V_27 |
V_28 |
V_29 |
V_31 |
V_30 |
V_32 |
V_37 |
V_33 ) ;
if ( V_38 == 1 )
V_36 &= ~ V_39 ;
}
if ( ~ V_35 & V_36 )
return 0 ;
return 1 ;
}
static void F_19 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_20 ( V_41 , struct V_42 , V_41 ) ;
F_21 ( & V_43 -> V_44 ) ;
F_22 ( & V_43 -> V_45 ) ;
F_23 ( V_43 -> V_46 ) ;
F_23 ( V_43 -> V_47 ) ;
F_23 ( V_43 -> V_48 ) ;
F_23 ( V_43 -> V_49 ) ;
F_24 ( V_43 ) ;
}
void F_25 ( struct V_50 * V_50 , struct V_42 * V_43 )
{
struct V_42 * V_51 = NULL ;
unsigned long V_13 ;
F_26 ( & V_50 -> V_52 , V_13 ) ;
if ( V_50 -> V_43 ) {
V_51 = V_50 -> V_43 ;
if ( F_8 ( V_50 -> V_5 , V_51 -> V_48 ) )
F_27 ( V_50 ) ;
F_28 ( V_50 -> V_5 , V_51 -> V_49 ) ;
if ( ! F_29 ( & V_51 -> V_53 ) )
V_51 = NULL ;
}
F_30 ( & V_43 -> V_53 ) ;
V_50 -> V_43 = V_43 ;
F_31 ( V_50 -> V_5 , V_43 -> V_49 ) ;
if ( F_8 ( V_50 -> V_5 , V_54 ) )
F_32 ( V_50 ) ;
F_33 ( & V_50 -> V_52 , V_13 ) ;
if ( V_51 )
F_34 ( & V_51 -> V_41 , F_19 ) ;
}
static int F_35 ( struct V_42 * V_43 )
{
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
if ( ! F_36 ( & V_43 -> V_49 , V_55 ) )
goto V_56;
if ( ! F_36 ( & V_43 -> V_48 , V_55 ) )
goto V_57;
if ( ! F_36 ( & V_43 -> V_46 , V_55 ) )
goto V_58;
if ( ! F_36 ( & V_43 -> V_47 , V_55 ) )
goto V_59;
F_37 ( & V_43 -> V_60 ) ;
if ( F_38 ( & V_43 -> V_45 ) != 0 )
goto V_61;
if ( F_39 ( & V_43 -> V_44 ) != 0 )
goto V_62;
return 0 ;
V_62:
F_22 ( & V_43 -> V_45 ) ;
V_61:
F_23 ( V_43 -> V_47 ) ;
V_59:
F_23 ( V_43 -> V_46 ) ;
V_58:
F_23 ( V_43 -> V_48 ) ;
V_57:
F_23 ( V_43 -> V_49 ) ;
V_56:
return - V_63 ;
}
void F_40 ( void )
{
F_35 ( & V_64 ) ;
F_41 ( & V_64 . V_53 , 1 ) ;
}
static struct V_42 * F_42 ( void )
{
struct V_42 * V_43 ;
V_43 = F_43 ( sizeof( * V_43 ) , V_55 ) ;
if ( ! V_43 )
return NULL ;
if ( F_35 ( V_43 ) != 0 ) {
F_24 ( V_43 ) ;
return NULL ;
}
return V_43 ;
}
static void F_44 ( struct V_9 * V_65 , int V_66 )
{
struct V_9 * V_67 , * V_68 ;
if ( ! V_65 )
return;
V_68 = V_65 ;
do {
V_67 = V_65 -> V_25 ;
if ( V_66 && F_29 ( & V_65 -> V_20 -> V_69 ) )
F_24 ( V_65 -> V_20 ) ;
F_24 ( V_65 ) ;
V_65 = V_67 ;
} while ( V_65 != V_68 );
}
static void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 & V_19 ) {
F_44 ( V_4 -> V_11 , 1 ) ;
} else if ( F_29 ( & V_4 -> V_11 -> V_69 ) ) {
F_24 ( V_4 -> V_11 -> V_20 ) ;
F_24 ( V_4 -> V_11 ) ;
}
if ( V_4 -> V_70 && F_29 ( & V_4 -> V_70 -> V_69 ) )
F_24 ( V_4 -> V_70 ) ;
F_24 ( V_4 ) ;
}
static void F_46 ( struct V_40 * V_41 )
{
struct V_3 * V_4 = F_20 ( V_41 , struct V_3 , V_41 ) ;
while ( V_4 ) {
struct V_3 * V_15 = V_4 -> V_15 ;
F_45 ( V_4 ) ;
V_4 = V_15 ;
}
}
static void F_47 ( struct V_3 * V_4 )
{
if ( V_4 )
F_48 ( & V_4 -> V_41 , F_46 ) ;
}
static void F_49 ( int V_5 )
{
struct V_71 * V_72 = NULL ;
struct V_3 * V_4 ;
int V_21 = V_5 ;
int V_73 = 1 ;
V_4 = F_50 ( V_5 , V_32 ) ;
if ( V_4 ) {
V_21 = F_51 ( F_7 ( V_4 ) ) ;
V_73 = F_10 ( F_7 ( V_4 ) ) ;
V_72 = V_4 -> V_70 ;
}
F_52 ( F_53 ( V_74 , V_5 ) , V_4 ) ;
F_53 ( V_75 , V_5 ) = V_73 ;
F_53 ( V_76 , V_5 ) = V_21 ;
F_52 ( F_53 ( V_77 , V_5 ) , V_72 ) ;
V_4 = F_54 ( V_5 , V_78 ) ;
F_52 ( F_53 ( V_79 , V_5 ) , V_4 ) ;
V_4 = F_50 ( V_5 , V_80 ) ;
F_52 ( F_53 ( V_81 , V_5 ) , V_4 ) ;
}
static void
F_55 ( struct V_3 * V_4 , struct V_42 * V_43 , int V_5 )
{
struct V_50 * V_50 = F_56 ( V_5 ) ;
struct V_3 * V_67 ;
for ( V_67 = V_4 ; V_67 ; ) {
struct V_3 * V_15 = V_67 -> V_15 ;
if ( ! V_15 )
break;
if ( F_18 ( V_67 , V_15 ) ) {
V_67 -> V_15 = V_15 -> V_15 ;
if ( V_15 -> V_15 )
V_15 -> V_15 -> V_24 = V_67 ;
if ( V_15 -> V_13 & V_37 )
V_67 -> V_13 |= V_37 ;
F_45 ( V_15 ) ;
} else
V_67 = V_67 -> V_15 ;
}
if ( V_4 && F_17 ( V_4 ) ) {
V_67 = V_4 ;
V_4 = V_4 -> V_15 ;
F_45 ( V_67 ) ;
if ( V_4 )
V_4 -> V_24 = NULL ;
}
F_16 ( V_4 , V_5 ) ;
F_25 ( V_50 , V_43 ) ;
V_67 = V_50 -> V_4 ;
F_52 ( V_50 -> V_4 , V_4 ) ;
F_47 ( V_67 ) ;
F_49 ( V_5 ) ;
}
static int T_1 F_57 ( char * V_1 )
{
int V_82 ;
F_58 ( & V_83 ) ;
V_82 = F_59 ( V_1 , V_83 ) ;
if ( V_82 ) {
F_60 ( L_27 , V_84 ) ;
return 0 ;
}
return 1 ;
}
int F_61 ( struct V_9 * V_65 )
{
return F_51 ( F_14 ( V_65 ) ) ;
}
static void
F_62 ( struct V_3 * V_4 , struct V_9 * V_65 , struct V_7 * V_85 )
{
const struct V_7 * V_86 = F_9 ( V_65 ) ;
struct V_87 * V_88 = V_4 -> V_89 ;
struct V_3 * V_90 ;
int V_91 ;
F_4 ( V_85 ) ;
F_63 (i, sg_span) {
V_90 = * F_64 ( V_88 -> V_4 , V_91 ) ;
if ( ! V_90 -> V_24 )
continue;
if ( ! F_13 ( V_86 , F_7 ( V_90 -> V_24 ) ) )
continue;
F_31 ( V_91 , V_85 ) ;
}
F_65 ( F_66 ( V_85 ) ) ;
}
static struct V_9 *
F_67 ( struct V_3 * V_4 , int V_5 )
{
struct V_9 * V_65 ;
struct V_7 * V_86 ;
V_65 = F_68 ( sizeof( struct V_9 ) + F_69 () ,
V_55 , F_70 ( V_5 ) ) ;
if ( ! V_65 )
return NULL ;
V_86 = F_9 ( V_65 ) ;
if ( V_4 -> V_24 )
F_71 ( V_86 , F_7 ( V_4 -> V_24 ) ) ;
else
F_71 ( V_86 , F_7 ( V_4 ) ) ;
return V_65 ;
}
static void F_72 ( struct V_3 * V_4 ,
struct V_9 * V_65 )
{
struct V_7 * V_85 = V_92 ;
struct V_87 * V_88 = V_4 -> V_89 ;
struct V_7 * V_86 ;
int V_5 ;
F_62 ( V_4 , V_65 , V_85 ) ;
V_5 = F_73 ( F_9 ( V_65 ) , V_85 ) ;
V_65 -> V_20 = * F_64 ( V_88 -> V_20 , V_5 ) ;
if ( F_74 ( & V_65 -> V_20 -> V_69 ) == 1 )
F_71 ( F_14 ( V_65 ) , V_85 ) ;
else
F_65 ( ! F_13 ( F_14 ( V_65 ) , V_85 ) ) ;
V_86 = F_9 ( V_65 ) ;
V_65 -> V_20 -> V_22 = V_23 * F_10 ( V_86 ) ;
V_65 -> V_20 -> V_93 = V_23 ;
}
static int
F_75 ( struct V_3 * V_4 , int V_5 )
{
struct V_9 * V_68 = NULL , * V_94 = NULL , * V_65 ;
const struct V_7 * V_49 = F_7 ( V_4 ) ;
struct V_7 * V_95 = V_26 ;
struct V_87 * V_88 = V_4 -> V_89 ;
struct V_3 * V_90 ;
int V_91 ;
F_4 ( V_95 ) ;
F_76 (i, span, cpu) {
struct V_7 * V_86 ;
if ( F_8 ( V_91 , V_95 ) )
continue;
V_90 = * F_64 ( V_88 -> V_4 , V_91 ) ;
if ( ! F_8 ( V_91 , F_7 ( V_90 ) ) )
continue;
V_65 = F_67 ( V_90 , V_5 ) ;
if ( ! V_65 )
goto V_96;
V_86 = F_9 ( V_65 ) ;
F_12 ( V_95 , V_95 , V_86 ) ;
F_72 ( V_4 , V_65 ) ;
if ( ! V_68 )
V_68 = V_65 ;
if ( V_94 )
V_94 -> V_25 = V_65 ;
V_94 = V_65 ;
V_94 -> V_25 = V_68 ;
}
V_4 -> V_11 = V_68 ;
return 0 ;
V_96:
F_44 ( V_68 , 0 ) ;
return - V_63 ;
}
static struct V_9 * F_77 ( int V_5 , struct V_87 * V_88 )
{
struct V_3 * V_4 = * F_64 ( V_88 -> V_4 , V_5 ) ;
struct V_3 * V_24 = V_4 -> V_24 ;
struct V_9 * V_65 ;
if ( V_24 )
V_5 = F_51 ( F_7 ( V_24 ) ) ;
V_65 = * F_64 ( V_88 -> V_65 , V_5 ) ;
V_65 -> V_20 = * F_64 ( V_88 -> V_20 , V_5 ) ;
F_30 ( & V_65 -> V_69 ) ;
F_30 ( & V_65 -> V_20 -> V_69 ) ;
if ( V_24 ) {
F_71 ( F_9 ( V_65 ) , F_7 ( V_24 ) ) ;
F_71 ( F_14 ( V_65 ) , F_9 ( V_65 ) ) ;
} else {
F_31 ( V_5 , F_9 ( V_65 ) ) ;
F_31 ( V_5 , F_14 ( V_65 ) ) ;
}
V_65 -> V_20 -> V_22 = V_23 * F_10 ( F_9 ( V_65 ) ) ;
V_65 -> V_20 -> V_93 = V_23 ;
return V_65 ;
}
static int
F_78 ( struct V_3 * V_4 , int V_5 )
{
struct V_9 * V_68 = NULL , * V_94 = NULL ;
struct V_87 * V_88 = V_4 -> V_89 ;
const struct V_7 * V_49 = F_7 ( V_4 ) ;
struct V_7 * V_95 ;
int V_91 ;
F_79 ( & V_97 ) ;
V_95 = V_26 ;
F_4 ( V_95 ) ;
F_76 (i, span, cpu) {
struct V_9 * V_65 ;
if ( F_8 ( V_91 , V_95 ) )
continue;
V_65 = F_77 ( V_91 , V_88 ) ;
F_12 ( V_95 , V_95 , F_9 ( V_65 ) ) ;
if ( ! V_68 )
V_68 = V_65 ;
if ( V_94 )
V_94 -> V_25 = V_65 ;
V_94 = V_65 ;
}
V_94 -> V_25 = V_68 ;
V_4 -> V_11 = V_68 ;
return 0 ;
}
static void F_80 ( int V_5 , struct V_3 * V_4 )
{
struct V_9 * V_65 = V_4 -> V_11 ;
F_81 ( ! V_65 ) ;
do {
int V_5 , V_98 = - 1 ;
V_65 -> V_99 = F_10 ( F_9 ( V_65 ) ) ;
if ( ! ( V_4 -> V_13 & V_80 ) )
goto V_25;
F_63 (cpu, sched_group_span(sg)) {
if ( V_98 < 0 )
V_98 = V_5 ;
else if ( F_82 ( V_5 , V_98 ) )
V_98 = V_5 ;
}
V_65 -> V_100 = V_98 ;
V_25:
V_65 = V_65 -> V_25 ;
} while ( V_65 != V_4 -> V_11 );
if ( V_5 != F_61 ( V_65 ) )
return;
F_83 ( V_4 , V_5 ) ;
}
static int T_1 F_84 ( char * V_1 )
{
if ( F_85 ( V_1 , 0 , & V_101 ) )
F_86 ( L_28 ) ;
return 1 ;
}
static void F_87 ( struct V_3 * V_4 ,
struct V_102 * V_103 )
{
int V_104 ;
if ( ! V_103 || V_103 -> V_105 < 0 ) {
if ( V_101 < 0 )
return;
else
V_104 = V_101 ;
} else
V_104 = V_103 -> V_105 ;
if ( V_104 < V_4 -> V_6 ) {
V_4 -> V_13 &= ~ ( V_106 | V_27 ) ;
} else {
V_4 -> V_13 |= ( V_106 | V_27 ) ;
}
}
static void F_88 ( struct V_107 * V_108 , enum V_109 V_110 ,
const struct V_7 * V_111 )
{
switch ( V_110 ) {
case V_112 :
if ( ! F_89 ( & V_108 -> V_43 -> V_53 ) )
F_19 ( & V_108 -> V_43 -> V_41 ) ;
case V_113 :
F_90 ( V_108 -> V_4 ) ;
case V_114 :
F_91 ( V_111 ) ;
case V_115 :
break;
}
}
static enum V_109
F_92 ( struct V_107 * V_108 , const struct V_7 * V_111 )
{
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
if ( F_93 ( V_111 ) )
return V_114 ;
V_108 -> V_4 = F_94 ( struct V_3 * ) ;
if ( ! V_108 -> V_4 )
return V_114 ;
V_108 -> V_43 = F_42 () ;
if ( ! V_108 -> V_43 )
return V_113 ;
return V_112 ;
}
static void F_95 ( int V_5 , struct V_3 * V_4 )
{
struct V_87 * V_88 = V_4 -> V_89 ;
F_65 ( * F_64 ( V_88 -> V_4 , V_5 ) != V_4 ) ;
* F_64 ( V_88 -> V_4 , V_5 ) = NULL ;
if ( F_89 ( & ( * F_64 ( V_88 -> V_72 , V_5 ) ) -> V_69 ) )
* F_64 ( V_88 -> V_72 , V_5 ) = NULL ;
if ( F_89 ( & ( * F_64 ( V_88 -> V_65 , V_5 ) ) -> V_69 ) )
* F_64 ( V_88 -> V_65 , V_5 ) = NULL ;
if ( F_89 ( & ( * F_64 ( V_88 -> V_20 , V_5 ) ) -> V_69 ) )
* F_64 ( V_88 -> V_20 , V_5 ) = NULL ;
}
static struct V_3 *
F_96 ( struct V_116 * V_117 ,
const struct V_7 * V_111 ,
struct V_3 * V_24 , int V_5 )
{
struct V_87 * V_88 = & V_117 -> V_118 ;
struct V_3 * V_4 = * F_64 ( V_88 -> V_4 , V_5 ) ;
int V_119 , V_120 , V_121 = 0 ;
#ifdef F_97
V_122 = V_117 -> V_123 ;
#endif
V_120 = F_10 ( V_117 -> V_85 ( V_5 ) ) ;
if ( V_117 -> V_121 )
V_121 = (* V_117 -> V_121 )() ;
if ( F_98 ( V_121 & ~ V_124 ,
L_29 ) )
V_121 &= ~ V_124 ;
* V_4 = (struct V_3 ) {
. V_125 = V_120 ,
. V_126 = 2 * V_120 ,
. V_127 = 32 ,
. V_128 = 125 ,
. V_129 = 0 ,
. V_130 = 0 ,
. V_131 = 0 ,
. V_132 = 0 ,
. V_133 = 0 ,
. V_134 = 0 ,
. V_13 = 1 * V_14
| 1 * V_27
| 1 * V_29
| 1 * V_28
| 0 * V_106
| 1 * V_34
| 0 * V_30
| 0 * V_32
| 0 * V_39
| 0 * V_37
| 0 * V_78
| V_121
,
. V_135 = V_136 ,
. V_137 = V_120 ,
. V_138 = 0 ,
. V_139 = 0 ,
. V_140 = V_136 ,
. V_24 = V_24 ,
#ifdef F_99
. V_18 = V_117 -> V_18 ,
#endif
} ;
F_100 ( F_7 ( V_4 ) , V_111 , V_117 -> V_85 ( V_5 ) ) ;
V_119 = F_51 ( F_7 ( V_4 ) ) ;
if ( V_4 -> V_13 & V_31 ) {
struct V_3 * V_141 = V_4 ;
F_101 (t)
V_141 -> V_13 |= V_106 ;
}
if ( V_4 -> V_13 & V_30 ) {
V_4 -> V_13 |= V_37 ;
V_4 -> V_128 = 110 ;
V_4 -> V_138 = 1178 ;
} else if ( V_4 -> V_13 & V_32 ) {
V_4 -> V_128 = 117 ;
V_4 -> V_129 = 1 ;
V_4 -> V_130 = 2 ;
#ifdef F_97
} else if ( V_4 -> V_13 & V_78 ) {
V_4 -> V_129 = 2 ;
V_4 -> V_130 = 3 ;
V_4 -> V_131 = 2 ;
V_4 -> V_13 |= V_39 ;
if ( V_142 [ V_117 -> V_123 ] > V_143 ) {
V_4 -> V_13 &= ~ ( V_29 |
V_28 |
V_34 ) ;
}
#endif
} else {
V_4 -> V_13 |= V_37 ;
V_4 -> V_129 = 1 ;
V_4 -> V_130 = 2 ;
V_4 -> V_131 = 1 ;
}
if ( V_4 -> V_13 & V_32 ) {
V_4 -> V_70 = * F_64 ( V_88 -> V_72 , V_119 ) ;
F_30 ( & V_4 -> V_70 -> V_69 ) ;
F_41 ( & V_4 -> V_70 -> V_144 , V_120 ) ;
}
V_4 -> V_89 = V_88 ;
return V_4 ;
}
void F_102 ( struct V_116 * V_117 )
{
if ( F_65 ( V_145 ) )
return;
V_146 = V_117 ;
}
static const struct V_7 * F_103 ( int V_5 )
{
return V_147 [ V_122 ] [ F_70 ( V_5 ) ] ;
}
static void F_104 ( const char * V_1 )
{
static int V_148 = false ;
int V_91 , V_149 ;
if ( V_148 )
return;
V_148 = true ;
F_5 ( V_150 L_30 , V_1 ) ;
for ( V_91 = 0 ; V_91 < V_38 ; V_91 ++ ) {
F_5 ( V_150 L_31 ) ;
for ( V_149 = 0 ; V_149 < V_38 ; V_149 ++ )
F_5 ( V_17 L_32 , F_105 ( V_91 , V_149 ) ) ;
F_5 ( V_17 L_12 ) ;
}
F_5 ( V_150 L_12 ) ;
}
bool F_106 ( int V_151 )
{
int V_91 ;
if ( V_151 == F_105 ( 0 , 0 ) )
return true ;
for ( V_91 = 0 ; V_91 < V_152 ; V_91 ++ ) {
if ( V_142 [ V_91 ] == V_151 )
return true ;
}
return false ;
}
static void F_107 ( void )
{
int V_153 , V_154 , V_155 , V_156 ;
V_156 = V_157 ;
if ( V_152 <= 1 ) {
V_158 = V_159 ;
return;
}
F_108 (a) {
F_108 (b) {
if ( F_105 ( V_153 , V_154 ) < V_156 )
continue;
F_108 (c) {
if ( F_105 ( V_153 , V_155 ) < V_156 &&
F_105 ( V_154 , V_155 ) < V_156 ) {
V_158 =
V_160 ;
return;
}
}
V_158 = V_161 ;
return;
}
}
}
void F_109 ( void )
{
int V_162 , V_163 = F_105 ( 0 , 0 ) ;
struct V_116 * V_117 ;
int V_6 = 0 ;
int V_91 , V_149 , V_164 ;
V_142 = F_110 ( sizeof( int ) * V_38 , V_55 ) ;
if ( ! V_142 )
return;
V_162 = V_163 ;
for ( V_91 = 0 ; V_91 < V_38 ; V_91 ++ ) {
for ( V_149 = 0 ; V_149 < V_38 ; V_149 ++ ) {
for ( V_164 = 0 ; V_164 < V_38 ; V_164 ++ ) {
int V_151 = F_105 ( V_91 , V_164 ) ;
if ( V_151 > V_163 &&
( V_151 < V_162 ||
V_162 == V_163 ) )
V_162 = V_151 ;
if ( F_2 () && F_105 ( V_164 , V_91 ) != V_151 )
F_104 ( L_33 ) ;
if ( F_2 () && V_91 && ! F_106 ( V_151 ) )
F_104 ( L_34 ) ;
}
if ( V_162 != V_163 ) {
V_142 [ V_6 ++ ] = V_162 ;
V_152 = V_6 ;
V_163 = V_162 ;
} else break;
}
if ( ! F_2 () )
break;
}
if ( ! V_6 )
return;
V_152 = 0 ;
V_147 = F_110 ( sizeof( void * ) * V_6 , V_55 ) ;
if ( ! V_147 )
return;
for ( V_91 = 0 ; V_91 < V_6 ; V_91 ++ ) {
V_147 [ V_91 ] =
F_110 ( V_38 * sizeof( void * ) , V_55 ) ;
if ( ! V_147 [ V_91 ] )
return;
for ( V_149 = 0 ; V_149 < V_38 ; V_149 ++ ) {
struct V_7 * V_85 = F_110 ( F_69 () , V_55 ) ;
if ( ! V_85 )
return;
V_147 [ V_91 ] [ V_149 ] = V_85 ;
F_111 (k) {
if ( F_105 ( V_149 , V_164 ) > V_142 [ V_91 ] )
continue;
F_12 ( V_85 , V_85 , F_112 ( V_164 ) ) ;
}
}
}
for ( V_91 = 0 ; V_146 [ V_91 ] . V_85 ; V_91 ++ ) ;
V_117 = F_110 ( ( V_91 + V_6 + 1 ) *
sizeof( struct V_116 ) , V_55 ) ;
if ( ! V_117 )
return;
for ( V_91 = 0 ; V_146 [ V_91 ] . V_85 ; V_91 ++ )
V_117 [ V_91 ] = V_146 [ V_91 ] ;
for ( V_149 = 0 ; V_149 < V_6 ; V_91 ++ , V_149 ++ ) {
V_117 [ V_91 ] = (struct V_116 ) {
. V_85 = F_103 ,
. V_121 = V_165 ,
. V_13 = V_166 ,
. V_123 = V_149 ,
F_113 (NUMA)
} ;
}
V_146 = V_117 ;
V_152 = V_6 ;
V_157 = V_142 [ V_6 - 1 ] ;
F_107 () ;
}
void F_114 ( unsigned int V_5 )
{
int V_167 = F_70 ( V_5 ) ;
int V_91 , V_149 ;
for ( V_91 = 0 ; V_91 < V_152 ; V_91 ++ ) {
for ( V_149 = 0 ; V_149 < V_38 ; V_149 ++ ) {
if ( F_105 ( V_149 , V_167 ) <= V_142 [ V_91 ] )
F_31 ( V_5 , V_147 [ V_91 ] [ V_149 ] ) ;
}
}
}
void F_115 ( unsigned int V_5 )
{
int V_91 , V_149 ;
for ( V_91 = 0 ; V_91 < V_152 ; V_91 ++ ) {
for ( V_149 = 0 ; V_149 < V_38 ; V_149 ++ )
F_28 ( V_5 , V_147 [ V_91 ] [ V_149 ] ) ;
}
}
static int F_93 ( const struct V_7 * V_111 )
{
struct V_116 * V_117 ;
int V_149 ;
F_116 (tl) {
struct V_87 * V_88 = & V_117 -> V_118 ;
V_88 -> V_4 = F_94 ( struct V_3 * ) ;
if ( ! V_88 -> V_4 )
return - V_63 ;
V_88 -> V_72 = F_94 ( struct V_71 * ) ;
if ( ! V_88 -> V_72 )
return - V_63 ;
V_88 -> V_65 = F_94 ( struct V_9 * ) ;
if ( ! V_88 -> V_65 )
return - V_63 ;
V_88 -> V_20 = F_94 ( struct V_168 * ) ;
if ( ! V_88 -> V_20 )
return - V_63 ;
F_63 (j, cpu_map) {
struct V_3 * V_4 ;
struct V_71 * V_72 ;
struct V_9 * V_65 ;
struct V_168 * V_20 ;
V_4 = F_68 ( sizeof( struct V_3 ) + F_69 () ,
V_55 , F_70 ( V_149 ) ) ;
if ( ! V_4 )
return - V_63 ;
* F_64 ( V_88 -> V_4 , V_149 ) = V_4 ;
V_72 = F_68 ( sizeof( struct V_71 ) ,
V_55 , F_70 ( V_149 ) ) ;
if ( ! V_72 )
return - V_63 ;
* F_64 ( V_88 -> V_72 , V_149 ) = V_72 ;
V_65 = F_68 ( sizeof( struct V_9 ) + F_69 () ,
V_55 , F_70 ( V_149 ) ) ;
if ( ! V_65 )
return - V_63 ;
V_65 -> V_25 = V_65 ;
* F_64 ( V_88 -> V_65 , V_149 ) = V_65 ;
V_20 = F_68 ( sizeof( struct V_168 ) + F_69 () ,
V_55 , F_70 ( V_149 ) ) ;
if ( ! V_20 )
return - V_63 ;
#ifdef F_99
V_20 -> V_21 = V_149 ;
#endif
* F_64 ( V_88 -> V_20 , V_149 ) = V_20 ;
}
}
return 0 ;
}
static void F_91 ( const struct V_7 * V_111 )
{
struct V_116 * V_117 ;
int V_149 ;
F_116 (tl) {
struct V_87 * V_88 = & V_117 -> V_118 ;
F_63 (j, cpu_map) {
struct V_3 * V_4 ;
if ( V_88 -> V_4 ) {
V_4 = * F_64 ( V_88 -> V_4 , V_149 ) ;
if ( V_4 && ( V_4 -> V_13 & V_19 ) )
F_44 ( V_4 -> V_11 , 0 ) ;
F_24 ( * F_64 ( V_88 -> V_4 , V_149 ) ) ;
}
if ( V_88 -> V_72 )
F_24 ( * F_64 ( V_88 -> V_72 , V_149 ) ) ;
if ( V_88 -> V_65 )
F_24 ( * F_64 ( V_88 -> V_65 , V_149 ) ) ;
if ( V_88 -> V_20 )
F_24 ( * F_64 ( V_88 -> V_20 , V_149 ) ) ;
}
F_90 ( V_88 -> V_4 ) ;
V_88 -> V_4 = NULL ;
F_90 ( V_88 -> V_72 ) ;
V_88 -> V_72 = NULL ;
F_90 ( V_88 -> V_65 ) ;
V_88 -> V_65 = NULL ;
F_90 ( V_88 -> V_20 ) ;
V_88 -> V_20 = NULL ;
}
}
struct V_3 * F_117 ( struct V_116 * V_117 ,
const struct V_7 * V_111 , struct V_102 * V_103 ,
struct V_3 * V_24 , int V_5 )
{
struct V_3 * V_4 = F_96 ( V_117 , V_111 , V_24 , V_5 ) ;
if ( V_24 ) {
V_4 -> V_6 = V_24 -> V_6 + 1 ;
V_169 = F_118 ( V_169 , V_4 -> V_6 ) ;
V_24 -> V_15 = V_4 ;
if ( ! F_15 ( F_7 ( V_24 ) ,
F_7 ( V_4 ) ) ) {
F_60 ( L_35 ) ;
#ifdef F_99
F_60 ( L_36 ,
V_24 -> V_18 , V_4 -> V_18 ) ;
#endif
F_12 ( F_7 ( V_4 ) ,
F_7 ( V_4 ) ,
F_7 ( V_24 ) ) ;
}
}
F_87 ( V_4 , V_103 ) ;
return V_4 ;
}
static int
F_119 ( const struct V_7 * V_111 , struct V_102 * V_103 )
{
enum V_109 V_170 ;
struct V_3 * V_4 ;
struct V_107 V_108 ;
struct V_50 * V_50 = NULL ;
int V_91 , V_82 = - V_63 ;
V_170 = F_92 ( & V_108 , V_111 ) ;
if ( V_170 != V_112 )
goto error;
F_63 (i, cpu_map) {
struct V_116 * V_117 ;
V_4 = NULL ;
F_116 (tl) {
V_4 = F_117 ( V_117 , V_111 , V_103 , V_4 , V_91 ) ;
if ( V_117 == V_146 )
* F_64 ( V_108 . V_4 , V_91 ) = V_4 ;
if ( V_117 -> V_13 & V_166 )
V_4 -> V_13 |= V_19 ;
if ( F_13 ( V_111 , F_7 ( V_4 ) ) )
break;
}
}
F_63 (i, cpu_map) {
for ( V_4 = * F_64 ( V_108 . V_4 , V_91 ) ; V_4 ; V_4 = V_4 -> V_15 ) {
V_4 -> V_171 = F_10 ( F_7 ( V_4 ) ) ;
if ( V_4 -> V_13 & V_19 ) {
if ( F_75 ( V_4 , V_91 ) )
goto error;
} else {
if ( F_78 ( V_4 , V_91 ) )
goto error;
}
}
}
for ( V_91 = V_172 - 1 ; V_91 >= 0 ; V_91 -- ) {
if ( ! F_8 ( V_91 , V_111 ) )
continue;
for ( V_4 = * F_64 ( V_108 . V_4 , V_91 ) ; V_4 ; V_4 = V_4 -> V_15 ) {
F_95 ( V_91 , V_4 ) ;
F_80 ( V_91 , V_4 ) ;
}
}
F_120 () ;
F_63 (i, cpu_map) {
V_50 = F_56 ( V_91 ) ;
V_4 = * F_64 ( V_108 . V_4 , V_91 ) ;
if ( V_50 -> V_173 > F_121 ( V_108 . V_43 -> V_174 ) )
F_122 ( V_108 . V_43 -> V_174 , V_50 -> V_173 ) ;
F_55 ( V_4 , V_108 . V_43 , V_91 ) ;
}
F_123 () ;
if ( V_50 && V_2 ) {
F_124 ( L_37 ,
F_6 ( V_111 ) , V_50 -> V_43 -> V_174 ) ;
}
V_82 = 0 ;
error:
F_88 ( & V_108 , V_170 , V_111 ) ;
return V_82 ;
}
int __weak F_125 ( void )
{
return 0 ;
}
T_2 * F_126 ( unsigned int V_175 )
{
int V_91 ;
T_2 * V_176 ;
V_176 = F_43 ( sizeof( * V_176 ) * V_175 , V_55 ) ;
if ( ! V_176 )
return NULL ;
for ( V_91 = 0 ; V_91 < V_175 ; V_91 ++ ) {
if ( ! F_127 ( & V_176 [ V_91 ] , V_55 ) ) {
F_128 ( V_176 , V_91 ) ;
return NULL ;
}
}
return V_176 ;
}
void F_128 ( T_2 V_176 [] , unsigned int V_175 )
{
unsigned int V_91 ;
for ( V_91 = 0 ; V_91 < V_175 ; V_91 ++ )
F_23 ( V_176 [ V_91 ] ) ;
F_24 ( V_176 ) ;
}
int F_129 ( const struct V_7 * V_111 )
{
int V_177 ;
F_36 ( & V_26 , V_55 ) ;
F_36 ( & V_92 , V_55 ) ;
F_36 ( & V_178 , V_55 ) ;
F_125 () ;
V_179 = 1 ;
V_180 = F_126 ( V_179 ) ;
if ( ! V_180 )
V_180 = & V_178 ;
F_130 ( V_180 [ 0 ] , V_111 , V_83 ) ;
V_177 = F_119 ( V_180 [ 0 ] , NULL ) ;
F_131 () ;
return V_177 ;
}
static void F_132 ( const struct V_7 * V_111 )
{
int V_91 ;
F_120 () ;
F_63 (i, cpu_map)
F_55 ( NULL , & V_64 , V_91 ) ;
F_123 () ;
}
static int F_133 ( struct V_102 * V_181 , int V_182 ,
struct V_102 * V_183 , int V_184 )
{
struct V_102 V_67 ;
if ( ! V_183 && ! V_181 )
return 1 ;
V_67 = V_185 ;
return ! memcmp ( V_181 ? ( V_181 + V_182 ) : & V_67 ,
V_183 ? ( V_183 + V_184 ) : & V_67 ,
sizeof( struct V_102 ) ) ;
}
void F_134 ( int V_186 , T_2 V_187 [] ,
struct V_102 * V_188 )
{
int V_91 , V_149 , V_156 ;
int V_189 ;
F_135 ( & V_97 ) ;
F_136 () ;
V_189 = F_125 () ;
V_156 = V_187 ? V_186 : 0 ;
for ( V_91 = 0 ; V_91 < V_179 ; V_91 ++ ) {
for ( V_149 = 0 ; V_149 < V_156 && ! V_189 ; V_149 ++ ) {
if ( F_13 ( V_180 [ V_91 ] , V_187 [ V_149 ] )
&& F_133 ( V_190 , V_91 , V_188 , V_149 ) )
goto V_191;
}
F_132 ( V_180 [ V_91 ] ) ;
V_191:
;
}
V_156 = V_179 ;
if ( V_187 == NULL ) {
V_156 = 0 ;
V_187 = & V_178 ;
F_130 ( V_187 [ 0 ] , V_54 , V_83 ) ;
F_65 ( V_188 ) ;
}
for ( V_91 = 0 ; V_91 < V_186 ; V_91 ++ ) {
for ( V_149 = 0 ; V_149 < V_156 && ! V_189 ; V_149 ++ ) {
if ( F_13 ( V_187 [ V_91 ] , V_180 [ V_149 ] )
&& F_133 ( V_188 , V_91 , V_190 , V_149 ) )
goto V_192;
}
F_119 ( V_187 [ V_91 ] , V_188 ? V_188 + V_91 : NULL ) ;
V_192:
;
}
if ( V_180 != & V_178 )
F_128 ( V_180 , V_179 ) ;
F_24 ( V_190 ) ;
V_180 = V_187 ;
V_190 = V_188 ;
V_179 = V_186 ;
F_131 () ;
F_137 ( & V_97 ) ;
}
