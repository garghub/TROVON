static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_7 ) ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 )
{
return F_2 ( V_11 , struct V_9 , V_11 ) ;
}
static struct V_12 * F_5 ( struct V_6 * V_7 )
{
return & V_7 -> V_3 -> V_12 ;
}
static int F_6 ( T_1 V_13 )
{
if ( V_13 > 8 )
return - V_14 ;
return ( V_13 >> 2 ) ;
}
static int F_7 ( enum V_15 V_16 )
{
if ( V_16 > V_17 )
return - V_14 ;
return ( V_16 >> 1 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_5 * V_18 = F_3 ( V_7 ) ;
F_9 ( & V_18 -> V_8 ) ;
}
static struct V_19 * F_10 ( struct V_1 * V_20 ,
struct V_5 * V_18 )
{
struct V_19 * V_21 = NULL , * V_22 = V_20 -> V_22 ;
unsigned long V_23 ;
int V_24 , V_25 ;
if ( V_18 -> V_26 ) {
V_24 = V_27 ;
V_25 = V_28 ;
} else {
V_24 = 0 ;
V_25 = V_27 ;
}
F_11 ( & V_20 -> V_29 , V_23 ) ;
F_12 (i, &priv->pchans_used, max) {
V_21 = & V_22 [ V_24 ] ;
V_21 -> V_18 = V_18 ;
F_13 ( V_24 , V_20 -> V_30 ) ;
break;
}
F_14 ( & V_20 -> V_29 , V_23 ) ;
return V_21 ;
}
static void F_15 ( struct V_1 * V_20 ,
struct V_19 * V_21 )
{
unsigned long V_23 ;
int V_31 = V_21 - V_20 -> V_22 ;
F_11 ( & V_20 -> V_29 , V_23 ) ;
V_21 -> V_18 = NULL ;
F_16 ( V_31 , V_20 -> V_30 ) ;
F_14 ( & V_20 -> V_29 , V_23 ) ;
}
static void F_17 ( struct V_19 * V_21 ,
struct V_32 * V_33 )
{
if ( V_21 -> V_26 ) {
F_18 ( V_33 -> V_34 , V_21 -> V_35 + V_36 ) ;
F_18 ( V_33 -> V_37 , V_21 -> V_35 + V_38 ) ;
F_18 ( V_33 -> V_39 , V_21 -> V_35 + V_40 ) ;
F_18 ( V_33 -> V_41 , V_21 -> V_35 + V_42 ) ;
F_18 ( V_33 -> V_43 , V_21 -> V_35 + V_44 ) ;
} else {
F_18 ( V_33 -> V_34 , V_21 -> V_35 + V_45 ) ;
F_18 ( V_33 -> V_37 , V_21 -> V_35 + V_46 ) ;
F_18 ( V_33 -> V_39 , V_21 -> V_35 + V_47 ) ;
F_18 ( V_33 -> V_43 , V_21 -> V_35 + V_48 ) ;
}
}
static void F_19 ( struct V_1 * V_20 ,
struct V_19 * V_21 ,
int V_49 , int V_50 )
{
T_1 V_51 ;
int V_52 = V_21 - V_20 -> V_22 ;
unsigned long V_23 ;
F_11 ( & V_20 -> V_29 , V_23 ) ;
V_51 = F_20 ( V_20 -> V_35 + V_53 ) ;
if ( V_49 )
V_51 |= F_21 ( V_52 * 2 ) ;
else
V_51 &= ~ F_21 ( V_52 * 2 ) ;
if ( V_50 )
V_51 |= F_21 ( V_52 * 2 + 1 ) ;
else
V_51 &= ~ F_21 ( V_52 * 2 + 1 ) ;
F_18 ( V_51 , V_20 -> V_35 + V_53 ) ;
F_14 ( & V_20 -> V_29 , V_23 ) ;
}
static int F_22 ( struct V_1 * V_20 ,
struct V_5 * V_18 )
{
struct V_32 * V_54 = NULL ;
struct V_9 * V_55 = NULL ;
struct V_19 * V_21 ;
struct V_10 * V_11 ;
int V_56 ;
F_23 ( & V_18 -> V_8 . V_29 ) ;
V_21 = F_10 ( V_20 , V_18 ) ;
if ( ! V_21 )
return - V_57 ;
if ( V_18 -> V_58 ) {
F_24 ( F_5 ( & V_18 -> V_8 . V_7 ) ,
L_1 ) ;
V_56 = - V_57 ;
goto F_15;
}
do {
V_11 = F_25 ( & V_18 -> V_8 ) ;
if ( ! V_11 ) {
F_24 ( F_5 ( & V_18 -> V_8 . V_7 ) ,
L_2 ) ;
V_56 = 0 ;
goto F_15;
}
V_55 = F_4 ( V_11 ) ;
if ( F_26 ( & V_55 -> V_59 ) ) {
F_27 ( & V_55 -> V_11 . V_60 ) ;
F_28 ( & V_55 -> V_11 ) ;
F_24 ( F_5 ( & V_18 -> V_8 . V_7 ) ,
L_3 ) ;
}
} while ( F_26 ( & V_55 -> V_59 ) );
V_54 = F_29 ( & V_55 -> V_59 ,
struct V_32 , V_61 ) ;
V_18 -> V_58 = V_54 ;
if ( V_54 ) {
V_18 -> V_55 = V_55 ;
V_18 -> V_21 = V_21 ;
F_19 ( V_20 , V_21 , V_55 -> V_62 , 1 ) ;
F_17 ( V_21 , V_54 ) ;
}
return 0 ;
F_15:
F_15 ( V_20 , V_21 ) ;
return V_56 ;
}
static int F_30 ( struct V_63 * V_64 ,
enum V_65 V_66 )
{
switch ( V_66 ) {
case V_67 :
if ( ( V_64 -> V_68 == V_69 ) ||
! V_64 -> V_70 )
return - V_14 ;
if ( V_64 -> V_71 == V_69 )
V_64 -> V_71 = V_64 -> V_68 ;
if ( ! V_64 -> V_72 )
V_64 -> V_72 = V_64 -> V_70 ;
break;
case V_73 :
if ( ( V_64 -> V_71 == V_69 ) ||
! V_64 -> V_72 )
return - V_14 ;
if ( V_64 -> V_68 == V_69 )
V_64 -> V_68 = V_64 -> V_71 ;
if ( ! V_64 -> V_70 )
V_64 -> V_70 = V_64 -> V_72 ;
break;
default:
return 0 ;
}
return 0 ;
}
static struct V_32 *
F_31 ( struct V_6 * V_7 , T_2 V_34 , T_2 V_74 ,
T_3 V_39 , struct V_63 * V_64 ,
enum V_65 V_66 )
{
struct V_32 * V_54 ;
int V_56 ;
V_56 = F_30 ( V_64 , V_66 ) ;
if ( V_56 )
return NULL ;
V_54 = F_32 ( sizeof( * V_54 ) , V_75 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_34 = V_34 ;
V_54 -> V_37 = V_74 ;
V_54 -> V_39 = V_39 ;
V_54 -> V_43 = V_76 |
V_77 ;
F_24 ( F_5 ( V_7 ) ,
L_4 ,
V_64 -> V_72 , V_64 -> V_70 ,
V_64 -> V_71 , V_64 -> V_68 ) ;
V_56 = F_6 ( V_64 -> V_72 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_34 ( V_56 ) ;
V_56 = F_6 ( V_64 -> V_70 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_35 ( V_56 ) ;
V_56 = F_7 ( V_64 -> V_71 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_36 ( V_56 ) ;
V_56 = F_7 ( V_64 -> V_68 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_37 ( V_56 ) ;
return V_54 ;
V_78:
F_38 ( V_54 ) ;
return NULL ;
}
static struct V_32 *
F_39 ( struct V_6 * V_7 , T_2 V_34 , T_2 V_74 ,
T_3 V_39 , struct V_63 * V_64 )
{
struct V_32 * V_54 ;
int V_56 ;
V_54 = F_32 ( sizeof( * V_54 ) , V_75 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_34 = V_34 ;
V_54 -> V_37 = V_74 ;
V_54 -> V_39 = V_39 ;
V_54 -> V_43 = V_76 |
V_79 ;
V_56 = F_6 ( V_64 -> V_72 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_34 ( V_56 ) ;
V_56 = F_6 ( V_64 -> V_70 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_35 ( V_56 ) ;
V_56 = F_7 ( V_64 -> V_71 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_36 ( V_56 ) ;
V_56 = F_7 ( V_64 -> V_68 ) ;
if ( F_33 ( V_56 ) )
goto V_78;
V_54 -> V_43 |= F_37 ( V_56 ) ;
return V_54 ;
V_78:
F_38 ( V_54 ) ;
return NULL ;
}
static struct V_9 * F_40 ( void )
{
struct V_9 * V_55 ;
V_55 = F_32 ( sizeof( * V_55 ) , V_75 ) ;
if ( ! V_55 )
return NULL ;
F_41 ( & V_55 -> V_59 ) ;
F_41 ( & V_55 -> V_80 ) ;
return V_55 ;
}
static struct V_32 *
F_42 ( struct V_9 * V_55 )
{
struct V_32 * V_54 ;
V_54 = F_43 ( & V_55 -> V_59 ,
struct V_32 , V_61 ) ;
if ( ! V_54 ) {
F_44 ( & V_55 -> V_80 ,
& V_55 -> V_59 ) ;
V_54 = F_29 ( & V_55 -> V_59 ,
struct V_32 , V_61 ) ;
}
return V_54 ;
}
static void F_45 ( struct V_10 * V_11 )
{
struct V_9 * V_55 = F_4 ( V_11 ) ;
struct V_32 * V_54 , * V_81 ;
F_46 (promise, tmp, &contract->demands, list)
F_38 ( V_54 ) ;
F_46 (promise, tmp, &contract->completed_demands, list)
F_38 ( V_54 ) ;
F_38 ( V_55 ) ;
}
static struct V_82 *
F_47 ( struct V_6 * V_7 , T_2 V_74 ,
T_2 V_34 , T_3 V_39 , unsigned long V_23 )
{
struct V_5 * V_18 = F_3 ( V_7 ) ;
struct V_63 * V_64 = & V_18 -> V_43 ;
struct V_32 * V_54 ;
struct V_9 * V_55 ;
V_55 = F_40 () ;
if ( ! V_55 )
return NULL ;
V_64 -> V_71 = V_17 ;
V_64 -> V_68 = V_17 ;
V_64 -> V_72 = 8 ;
V_64 -> V_70 = 8 ;
if ( V_18 -> V_26 )
V_54 = F_39 ( V_7 , V_34 , V_74 , V_39 , V_64 ) ;
else
V_54 = F_31 ( V_7 , V_34 , V_74 , V_39 , V_64 ,
V_83 ) ;
if ( ! V_54 ) {
F_38 ( V_55 ) ;
return NULL ;
}
if ( V_18 -> V_26 ) {
V_54 -> V_43 |= F_48 ( V_84 ) |
F_49 ( V_84 ) ;
} else {
V_54 -> V_43 |= F_48 ( V_85 ) |
F_49 ( V_85 ) ;
}
F_50 ( & V_54 -> V_61 , & V_55 -> V_59 ) ;
return F_51 ( & V_18 -> V_8 , & V_55 -> V_11 , V_23 ) ;
}
static struct V_82 *
F_52 ( struct V_6 * V_7 , T_2 V_86 , T_3 V_39 ,
T_3 V_87 , enum V_65 V_88 ,
unsigned long V_23 )
{
struct V_5 * V_18 = F_3 ( V_7 ) ;
struct V_63 * V_64 = & V_18 -> V_43 ;
struct V_32 * V_54 ;
struct V_9 * V_55 ;
T_2 V_34 , V_74 ;
T_1 V_89 ;
int V_90 , V_91 , V_92 , V_24 ;
if ( ! F_53 ( V_88 ) ) {
F_54 ( F_5 ( V_7 ) , L_5 ) ;
return NULL ;
}
if ( V_18 -> V_26 ) {
F_54 ( F_5 ( V_7 ) ,
L_6 ) ;
return NULL ;
}
V_55 = F_40 () ;
if ( ! V_55 )
return NULL ;
V_55 -> V_62 = 1 ;
if ( V_88 == V_67 ) {
V_34 = V_86 ;
V_74 = V_64 -> V_93 ;
V_89 = F_48 ( V_85 ) |
F_49 ( V_18 -> V_94 ) |
F_55 ( V_95 ) ;
} else {
V_34 = V_64 -> V_96 ;
V_74 = V_86 ;
V_89 = F_48 ( V_18 -> V_94 ) |
F_56 ( V_95 ) |
F_49 ( V_85 ) ;
}
V_90 = F_57 ( V_39 / V_87 , 2 ) ;
for ( V_24 = 0 ; V_24 < V_90 ; V_24 ++ ) {
V_91 = V_24 * V_87 * 2 ;
V_92 = F_58 ( ( V_39 - V_91 ) , ( V_87 * 2 ) ) ;
if ( V_88 == V_67 )
V_34 = V_86 + V_91 ;
else
V_74 = V_86 + V_91 ;
V_54 = F_31 ( V_7 , V_34 , V_74 ,
V_92 , V_64 , V_88 ) ;
if ( ! V_54 ) {
return NULL ;
}
V_54 -> V_43 |= V_89 ;
F_50 ( & V_54 -> V_61 , & V_55 -> V_59 ) ;
}
return F_51 ( & V_18 -> V_8 , & V_55 -> V_11 , V_23 ) ;
}
static struct V_82 *
F_59 ( struct V_6 * V_7 , struct V_97 * V_98 ,
unsigned int V_99 , enum V_65 V_88 ,
unsigned long V_23 , void * V_100 )
{
struct V_5 * V_18 = F_3 ( V_7 ) ;
struct V_63 * V_64 = & V_18 -> V_43 ;
struct V_32 * V_54 ;
struct V_9 * V_55 ;
T_4 V_101 , V_102 , V_103 ;
struct V_97 * V_104 ;
T_2 V_105 , V_106 ;
T_1 V_89 , V_41 ;
int V_24 ;
if ( ! V_98 )
return NULL ;
if ( ! F_53 ( V_88 ) ) {
F_54 ( F_5 ( V_7 ) , L_5 ) ;
return NULL ;
}
V_55 = F_40 () ;
if ( ! V_55 )
return NULL ;
if ( V_18 -> V_26 ) {
V_102 = V_107 ;
V_103 = V_108 ;
V_101 = V_84 ;
} else {
V_102 = V_95 ;
V_103 = V_109 ;
V_101 = V_85 ;
}
if ( V_88 == V_67 )
V_89 = F_49 ( V_18 -> V_94 ) |
F_55 ( V_102 ) |
F_48 ( V_101 ) |
F_56 ( V_103 ) ;
else
V_89 = F_49 ( V_101 ) |
F_55 ( V_103 ) |
F_48 ( V_18 -> V_94 ) |
F_56 ( V_102 ) ;
F_60 (sgl, sg, sg_len, i) {
if ( V_88 == V_67 ) {
V_105 = F_61 ( V_104 ) ;
V_106 = V_64 -> V_93 ;
} else {
V_105 = V_64 -> V_96 ;
V_106 = F_61 ( V_104 ) ;
}
V_41 = V_110 ;
if ( V_18 -> V_26 )
V_54 = F_39 ( V_7 , V_105 , V_106 ,
F_62 ( V_104 ) ,
V_64 ) ;
else
V_54 = F_31 ( V_7 , V_105 , V_106 ,
F_62 ( V_104 ) ,
V_64 , V_88 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_43 |= V_89 ;
V_54 -> V_41 = V_41 ;
F_50 ( & V_54 -> V_61 , & V_55 -> V_59 ) ;
}
return F_51 ( & V_18 -> V_8 , & V_55 -> V_11 , V_23 ) ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_20 = F_1 ( V_7 -> V_12 ) ;
struct V_5 * V_18 = F_3 ( V_7 ) ;
struct V_19 * V_21 = V_18 -> V_21 ;
F_64 ( V_111 ) ;
unsigned long V_23 ;
F_11 ( & V_18 -> V_8 . V_29 , V_23 ) ;
F_65 ( & V_18 -> V_8 , & V_111 ) ;
F_14 ( & V_18 -> V_8 . V_29 , V_23 ) ;
if ( V_21 ) {
if ( V_21 -> V_26 )
F_66 ( 0 , V_21 -> V_35 + V_44 ) ;
else
F_66 ( 0 , V_21 -> V_35 + V_48 ) ;
F_19 ( V_20 , V_21 , 0 , 0 ) ;
F_15 ( V_20 , V_21 ) ;
}
F_11 ( & V_18 -> V_8 . V_29 , V_23 ) ;
F_67 ( & V_18 -> V_8 , & V_111 ) ;
V_18 -> V_58 = NULL ;
V_18 -> V_21 = NULL ;
F_14 ( & V_18 -> V_8 . V_29 , V_23 ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 ,
struct V_63 * V_112 )
{
struct V_5 * V_18 = F_3 ( V_7 ) ;
memcpy ( & V_18 -> V_43 , V_112 , sizeof( * V_112 ) ) ;
return 0 ;
}
static struct V_6 * F_69 ( struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_20 = V_116 -> V_117 ;
struct V_5 * V_18 ;
struct V_6 * V_7 ;
T_4 V_26 = V_114 -> args [ 0 ] ;
T_4 V_94 = V_114 -> args [ 1 ] ;
if ( V_26 != 0 && V_26 != 1 )
return NULL ;
if ( ( V_26 && V_94 >= V_118 ) ||
( ! V_26 && V_94 >= V_119 ) )
return NULL ;
V_7 = F_70 ( & V_20 -> V_4 ) ;
if ( ! V_7 )
return NULL ;
V_18 = F_3 ( V_7 ) ;
V_18 -> V_26 = V_26 ;
V_18 -> V_94 = V_94 ;
return V_7 ;
}
static enum V_120 F_71 ( struct V_6 * V_7 ,
T_5 V_121 ,
struct V_122 * V_123 )
{
struct V_5 * V_18 = F_3 ( V_7 ) ;
struct V_19 * V_21 = V_18 -> V_21 ;
struct V_9 * V_55 ;
struct V_32 * V_54 ;
struct V_10 * V_11 ;
unsigned long V_23 ;
enum V_120 V_56 ;
T_3 V_124 = 0 ;
V_56 = F_72 ( V_7 , V_121 , V_123 ) ;
if ( ! V_123 || ( V_56 == V_125 ) )
return V_56 ;
F_11 ( & V_18 -> V_8 . V_29 , V_23 ) ;
V_11 = F_73 ( & V_18 -> V_8 , V_121 ) ;
if ( ! V_11 )
goto exit;
V_55 = F_4 ( V_11 ) ;
F_74 (promise, &contract->demands, list)
V_124 += V_54 -> V_39 ;
V_54 = F_43 ( & V_55 -> V_59 ,
struct V_32 , V_61 ) ;
if ( V_54 && V_21 ) {
V_124 -= V_54 -> V_39 ;
if ( V_21 -> V_26 )
V_124 += F_75 ( V_21 -> V_35 + V_40 ) ;
else
V_124 += F_75 ( V_21 -> V_35 + V_47 ) ;
}
exit:
F_76 ( V_123 , V_124 ) ;
F_14 ( & V_18 -> V_8 . V_29 , V_23 ) ;
return V_56 ;
}
static void F_77 ( struct V_6 * V_7 )
{
struct V_1 * V_20 = F_1 ( V_7 -> V_12 ) ;
struct V_5 * V_18 = F_3 ( V_7 ) ;
unsigned long V_23 ;
F_11 ( & V_18 -> V_8 . V_29 , V_23 ) ;
if ( F_78 ( & V_18 -> V_8 ) )
F_22 ( V_20 , V_18 ) ;
F_14 ( & V_18 -> V_8 . V_29 , V_23 ) ;
}
static T_6 F_79 ( int V_126 , void * V_127 )
{
struct V_1 * V_20 = V_127 ;
struct V_19 * V_22 = V_20 -> V_22 , * V_21 ;
struct V_5 * V_18 ;
struct V_9 * V_55 ;
struct V_32 * V_54 ;
unsigned long V_128 , V_129 , V_130 ;
int V_131 , V_24 , V_132 , V_133 = 1 ;
V_128 = F_20 ( V_20 -> V_35 + V_134 ) ;
V_135:
V_130 = 0 ;
V_132 = 0 ;
F_80 (bit, &pendirq, 32 ) {
V_21 = & V_22 [ V_131 >> 1 ] ;
V_18 = V_21 -> V_18 ;
if ( ! V_18 )
continue;
V_55 = V_18 -> V_55 ;
if ( V_131 & 1 ) {
F_81 ( & V_18 -> V_8 . V_29 ) ;
F_27 ( & V_18 -> V_58 -> V_61 ) ;
F_50 ( & V_18 -> V_58 -> V_61 ,
& V_55 -> V_80 ) ;
if ( V_55 -> V_62 ) {
V_54 = F_42 ( V_55 ) ;
V_18 -> V_58 = V_54 ;
F_17 ( V_21 , V_54 ) ;
F_82 ( & V_55 -> V_11 ) ;
} else {
V_18 -> V_58 = NULL ;
V_18 -> V_21 = NULL ;
V_132 = 1 ;
V_130 |= F_21 ( V_131 ) ;
F_15 ( V_20 , V_21 ) ;
}
F_83 ( & V_18 -> V_8 . V_29 ) ;
} else {
if ( V_55 -> V_62 )
F_82 ( & V_55 -> V_11 ) ;
else
V_130 |= F_21 ( V_131 ) ;
}
}
F_81 ( & V_20 -> V_29 ) ;
V_129 = F_20 ( V_20 -> V_35 + V_53 ) ;
F_18 ( V_129 & ~ V_130 ,
V_20 -> V_35 + V_53 ) ;
F_83 ( & V_20 -> V_29 ) ;
F_18 ( V_128 , V_20 -> V_35 + V_134 ) ;
if ( V_132 ) {
for ( V_24 = 0 ; V_24 < V_136 ; V_24 ++ ) {
V_18 = & V_20 -> V_137 [ V_24 ] ;
F_81 ( & V_18 -> V_8 . V_29 ) ;
F_22 ( V_20 , V_18 ) ;
F_83 ( & V_18 -> V_8 . V_29 ) ;
}
}
if ( V_133 ) {
V_128 = F_20 ( V_20 -> V_35 +
V_134 ) ;
if ( V_128 ) {
V_133 = 0 ;
goto V_135;
}
}
return V_138 ;
}
static int F_84 ( struct V_139 * V_140 )
{
struct V_1 * V_20 ;
struct V_141 * V_142 ;
int V_24 , V_143 , V_56 ;
V_20 = F_85 ( & V_140 -> V_3 , sizeof( * V_20 ) , V_144 ) ;
if ( ! V_20 )
return - V_145 ;
V_142 = F_86 ( V_140 , V_146 , 0 ) ;
V_20 -> V_35 = F_87 ( & V_140 -> V_3 , V_142 ) ;
if ( F_88 ( V_20 -> V_35 ) )
return F_89 ( V_20 -> V_35 ) ;
V_20 -> V_126 = F_90 ( V_140 , 0 ) ;
if ( V_20 -> V_126 < 0 ) {
F_54 ( & V_140 -> V_3 , L_7 ) ;
return V_20 -> V_126 ;
}
V_20 -> V_147 = F_91 ( & V_140 -> V_3 , NULL ) ;
if ( F_88 ( V_20 -> V_147 ) ) {
F_54 ( & V_140 -> V_3 , L_8 ) ;
return F_89 ( V_20 -> V_147 ) ;
}
F_92 ( V_140 , V_20 ) ;
F_93 ( & V_20 -> V_29 ) ;
F_94 ( V_20 -> V_4 . V_148 ) ;
F_95 ( V_149 , V_20 -> V_4 . V_148 ) ;
F_95 ( V_150 , V_20 -> V_4 . V_148 ) ;
F_95 ( V_151 , V_20 -> V_4 . V_148 ) ;
F_95 ( V_152 , V_20 -> V_4 . V_148 ) ;
F_41 ( & V_20 -> V_4 . V_153 ) ;
V_20 -> V_4 . V_154 = F_8 ;
V_20 -> V_4 . V_155 = F_71 ;
V_20 -> V_4 . V_156 = F_77 ;
V_20 -> V_4 . V_157 = F_59 ;
V_20 -> V_4 . V_158 = F_47 ;
V_20 -> V_4 . V_159 = F_52 ;
V_20 -> V_4 . V_160 = F_68 ;
V_20 -> V_4 . V_161 = F_63 ;
V_20 -> V_4 . V_162 = 2 ;
V_20 -> V_4 . V_163 = F_21 ( V_164 ) |
F_21 ( V_165 ) |
F_21 ( V_17 ) ;
V_20 -> V_4 . V_166 = F_21 ( V_164 ) |
F_21 ( V_165 ) |
F_21 ( V_17 ) ;
V_20 -> V_4 . V_167 = F_21 ( V_73 ) |
F_21 ( V_67 ) ;
V_20 -> V_4 . V_168 = V_169 ;
V_20 -> V_4 . V_3 = & V_140 -> V_3 ;
V_20 -> V_22 = F_96 ( & V_140 -> V_3 , V_28 ,
sizeof( struct V_19 ) , V_144 ) ;
V_20 -> V_137 = F_96 ( & V_140 -> V_3 , V_136 ,
sizeof( struct V_5 ) , V_144 ) ;
if ( ! V_20 -> V_137 || ! V_20 -> V_22 )
return - V_145 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ )
V_20 -> V_22 [ V_24 ] . V_35 = V_20 -> V_35 +
F_97 ( V_24 ) ;
for ( V_143 = 0 ; V_24 < V_28 ; V_24 ++ , V_143 ++ ) {
V_20 -> V_22 [ V_24 ] . V_35 = V_20 -> V_35 +
F_98 ( V_143 ) ;
V_20 -> V_22 [ V_24 ] . V_26 = 1 ;
}
for ( V_24 = 0 ; V_24 < V_136 ; V_24 ++ ) {
struct V_5 * V_18 = & V_20 -> V_137 [ V_24 ] ;
F_93 ( & V_18 -> V_8 . V_29 ) ;
V_18 -> V_8 . V_170 = F_45 ;
F_99 ( & V_18 -> V_8 , & V_20 -> V_4 ) ;
}
V_56 = F_100 ( V_20 -> V_147 ) ;
if ( V_56 ) {
F_54 ( & V_140 -> V_3 , L_9 ) ;
return V_56 ;
}
F_66 ( 0 , V_20 -> V_35 + V_53 ) ;
F_66 ( 0xFFFFFFFF , V_20 -> V_35 + V_134 ) ;
V_56 = F_101 ( & V_140 -> V_3 , V_20 -> V_126 , F_79 ,
0 , F_102 ( & V_140 -> V_3 ) , V_20 ) ;
if ( V_56 ) {
F_54 ( & V_140 -> V_3 , L_10 ) ;
goto V_171;
}
V_56 = F_103 ( & V_20 -> V_4 ) ;
if ( V_56 ) {
F_104 ( & V_140 -> V_3 , L_11 ) ;
goto V_171;
}
V_56 = F_105 ( V_140 -> V_3 . V_172 , F_69 ,
V_20 ) ;
if ( V_56 ) {
F_54 ( & V_140 -> V_3 , L_12 ) ;
goto V_173;
}
F_24 ( & V_140 -> V_3 , L_13 ) ;
return 0 ;
V_173:
F_106 ( & V_20 -> V_4 ) ;
V_171:
F_107 ( V_20 -> V_147 ) ;
return V_56 ;
}
static int F_108 ( struct V_139 * V_140 )
{
struct V_1 * V_20 = F_109 ( V_140 ) ;
F_110 ( V_20 -> V_126 ) ;
F_111 ( V_140 -> V_3 . V_172 ) ;
F_106 ( & V_20 -> V_4 ) ;
F_107 ( V_20 -> V_147 ) ;
return 0 ;
}
