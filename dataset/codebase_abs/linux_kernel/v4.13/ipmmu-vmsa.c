static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 )
{
#if F_4 ( V_8 )
return V_7 -> V_9 . V_10 ;
#else
return V_7 -> V_11 -> V_12 ;
#endif
}
static void F_5 ( struct V_6 * V_7 , struct V_5 * V_13 )
{
#if F_4 ( V_8 )
V_7 -> V_9 . V_10 = V_13 ;
#else
V_7 -> V_11 -> V_12 = V_13 ;
#endif
}
static T_1 F_6 ( struct V_14 * V_15 , unsigned int V_16 )
{
return F_7 ( V_15 -> V_17 + V_16 ) ;
}
static void F_8 ( struct V_14 * V_15 , unsigned int V_16 ,
T_1 V_18 )
{
F_9 ( V_18 , V_15 -> V_17 + V_16 ) ;
}
static T_1 F_10 ( struct V_1 * V_19 , unsigned int V_20 )
{
return F_6 ( V_19 -> V_15 , V_19 -> V_21 * V_22 + V_20 ) ;
}
static void F_11 ( struct V_1 * V_19 , unsigned int V_20 ,
T_1 V_18 )
{
F_8 ( V_19 -> V_15 , V_19 -> V_21 * V_22 + V_20 , V_18 ) ;
}
static void F_12 ( struct V_1 * V_19 )
{
unsigned int V_23 = 0 ;
while ( F_10 ( V_19 , V_24 ) & V_25 ) {
F_13 () ;
if ( ++ V_23 == V_26 ) {
F_14 ( V_19 -> V_15 -> V_7 ,
L_1 ) ;
return;
}
F_15 ( 1 ) ;
}
}
static void F_16 ( struct V_1 * V_19 )
{
T_1 V_20 ;
V_20 = F_10 ( V_19 , V_24 ) ;
V_20 |= V_25 ;
F_11 ( V_19 , V_24 , V_20 ) ;
F_12 ( V_19 ) ;
}
static void F_17 ( struct V_1 * V_19 ,
unsigned int V_27 )
{
struct V_14 * V_15 = V_19 -> V_15 ;
F_8 ( V_15 , F_18 ( V_27 ) , 0 ) ;
F_8 ( V_15 , F_19 ( V_27 ) ,
F_20 ( V_19 -> V_21 ) | V_28 |
V_29 ) ;
}
static void F_21 ( struct V_1 * V_19 ,
unsigned int V_27 )
{
struct V_14 * V_15 = V_19 -> V_15 ;
F_8 ( V_15 , F_19 ( V_27 ) , 0 ) ;
}
static void F_22 ( void * V_30 )
{
struct V_1 * V_19 = V_30 ;
F_16 ( V_19 ) ;
}
static void F_23 ( unsigned long V_31 , T_2 V_32 ,
T_2 V_33 , bool V_34 , void * V_30 )
{
}
static int F_24 ( struct V_14 * V_15 ,
struct V_1 * V_19 )
{
unsigned long V_35 ;
int V_36 ;
F_25 ( & V_15 -> V_37 , V_35 ) ;
V_36 = F_26 ( V_15 -> V_38 , V_39 ) ;
if ( V_36 != V_39 ) {
V_15 -> V_40 [ V_36 ] = V_19 ;
F_27 ( V_36 , V_15 -> V_38 ) ;
}
F_28 ( & V_15 -> V_37 , V_35 ) ;
return V_36 ;
}
static int F_29 ( struct V_1 * V_19 )
{
T_3 V_41 ;
int V_36 ;
V_19 -> V_42 . V_43 = V_44 ;
V_19 -> V_42 . V_45 = V_46 | V_47 | V_48 ;
V_19 -> V_42 . V_49 = 32 ;
V_19 -> V_42 . V_50 = 40 ;
V_19 -> V_42 . V_51 = & V_52 ;
V_19 -> V_4 . V_53 . V_54 = F_30 ( 32 ) ;
V_19 -> V_4 . V_53 . V_55 = true ;
V_19 -> V_42 . V_56 = V_19 -> V_15 -> V_7 ;
V_19 -> V_57 = F_31 ( V_58 , & V_19 -> V_42 ,
V_19 ) ;
if ( ! V_19 -> V_57 )
return - V_59 ;
V_36 = F_24 ( V_19 -> V_15 , V_19 ) ;
if ( V_36 == V_39 ) {
F_32 ( V_19 -> V_57 ) ;
return - V_60 ;
}
V_19 -> V_21 = V_36 ;
V_41 = V_19 -> V_42 . V_61 . V_41 [ 0 ] ;
F_11 ( V_19 , V_62 , V_41 ) ;
F_11 ( V_19 , V_63 , V_41 >> 32 ) ;
F_11 ( V_19 , V_64 , V_65 |
V_66 | V_67 |
V_68 | V_69 ) ;
F_11 ( V_19 , V_70 , V_19 -> V_42 . V_61 . V_71 [ 0 ] ) ;
F_11 ( V_19 , V_72 ,
F_10 ( V_19 , V_72 ) &
~ ( V_73 | V_74 ) ) ;
F_11 ( V_19 , V_75 , F_10 ( V_19 , V_75 ) ) ;
F_11 ( V_19 , V_24 , V_76 | V_25 | V_77 ) ;
return 0 ;
}
static void F_33 ( struct V_14 * V_15 ,
unsigned int V_21 )
{
unsigned long V_35 ;
F_25 ( & V_15 -> V_37 , V_35 ) ;
F_34 ( V_21 , V_15 -> V_38 ) ;
V_15 -> V_40 [ V_21 ] = NULL ;
F_28 ( & V_15 -> V_37 , V_35 ) ;
}
static void F_35 ( struct V_1 * V_19 )
{
F_11 ( V_19 , V_24 , V_25 ) ;
F_12 ( V_19 ) ;
F_33 ( V_19 -> V_15 , V_19 -> V_21 ) ;
}
static T_4 F_36 ( struct V_1 * V_19 )
{
const T_1 V_78 = V_79 | V_80 | V_81 | V_82 ;
struct V_14 * V_15 = V_19 -> V_15 ;
T_1 V_83 ;
T_1 V_31 ;
V_83 = F_10 ( V_19 , V_75 ) ;
if ( ! ( V_83 & V_78 ) )
return V_84 ;
V_31 = F_10 ( V_19 , V_85 ) ;
F_11 ( V_19 , V_75 , 0 ) ;
if ( V_83 & V_79 )
F_14 ( V_15 -> V_7 , L_2 ,
V_31 ) ;
if ( V_83 & V_80 )
F_14 ( V_15 -> V_7 , L_3 ,
V_31 ) ;
if ( ! ( V_83 & ( V_81 | V_82 ) ) )
return V_84 ;
if ( ! F_37 ( & V_19 -> V_4 , V_15 -> V_7 , V_31 , 0 ) )
return V_86 ;
F_14 ( V_15 -> V_7 ,
L_4 ,
V_83 , V_31 ) ;
return V_86 ;
}
static T_4 F_38 ( int V_87 , void * V_7 )
{
struct V_14 * V_15 = V_7 ;
T_4 V_83 = V_84 ;
unsigned int V_88 ;
unsigned long V_35 ;
F_25 ( & V_15 -> V_37 , V_35 ) ;
for ( V_88 = 0 ; V_88 < V_39 ; V_88 ++ ) {
if ( ! V_15 -> V_40 [ V_88 ] )
continue;
if ( F_36 ( V_15 -> V_40 [ V_88 ] ) == V_86 )
V_83 = V_86 ;
}
F_28 ( & V_15 -> V_37 , V_35 ) ;
return V_83 ;
}
static struct V_2 * F_39 ( unsigned type )
{
struct V_1 * V_19 ;
V_19 = F_40 ( sizeof( * V_19 ) , V_89 ) ;
if ( ! V_19 )
return NULL ;
F_41 ( & V_19 -> V_37 ) ;
return & V_19 -> V_4 ;
}
static void F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_19 = F_1 ( V_4 ) ;
F_35 ( V_19 ) ;
F_32 ( V_19 -> V_57 ) ;
F_43 ( V_19 ) ;
}
static int F_44 ( struct V_2 * V_4 ,
struct V_6 * V_7 )
{
struct V_5 * V_90 = F_3 ( V_7 ) ;
struct V_14 * V_15 = V_90 -> V_15 ;
struct V_1 * V_19 = F_1 ( V_4 ) ;
unsigned long V_35 ;
unsigned int V_88 ;
int V_36 = 0 ;
if ( ! V_15 ) {
F_45 ( V_7 , L_5 ) ;
return - V_91 ;
}
F_25 ( & V_19 -> V_37 , V_35 ) ;
if ( ! V_19 -> V_15 ) {
V_19 -> V_15 = V_15 ;
V_36 = F_29 ( V_19 ) ;
} else if ( V_19 -> V_15 != V_15 ) {
F_45 ( V_7 , L_6 ,
F_46 ( V_15 -> V_7 ) , F_46 ( V_19 -> V_15 -> V_7 ) ) ;
V_36 = - V_59 ;
} else
F_47 ( V_7 , L_7 , V_19 -> V_21 ) ;
F_28 ( & V_19 -> V_37 , V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
for ( V_88 = 0 ; V_88 < V_90 -> V_92 ; ++ V_88 )
F_17 ( V_19 , V_90 -> V_93 [ V_88 ] ) ;
return 0 ;
}
static void F_48 ( struct V_2 * V_4 ,
struct V_6 * V_7 )
{
struct V_5 * V_90 = F_3 ( V_7 ) ;
struct V_1 * V_19 = F_1 ( V_4 ) ;
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_90 -> V_92 ; ++ V_88 )
F_21 ( V_19 , V_90 -> V_93 [ V_88 ] ) ;
}
static int F_49 ( struct V_2 * V_4 , unsigned long V_31 ,
T_5 V_94 , T_2 V_32 , int V_95 )
{
struct V_1 * V_19 = F_1 ( V_4 ) ;
if ( ! V_19 )
return - V_96 ;
return V_19 -> V_57 -> V_97 ( V_19 -> V_57 , V_31 , V_94 , V_32 , V_95 ) ;
}
static T_2 F_50 ( struct V_2 * V_4 , unsigned long V_31 ,
T_2 V_32 )
{
struct V_1 * V_19 = F_1 ( V_4 ) ;
return V_19 -> V_57 -> V_98 ( V_19 -> V_57 , V_31 , V_32 ) ;
}
static T_5 F_51 ( struct V_2 * V_4 ,
T_6 V_31 )
{
struct V_1 * V_19 = F_1 ( V_4 ) ;
return V_19 -> V_57 -> V_99 ( V_19 -> V_57 , V_31 ) ;
}
static int F_52 ( struct V_14 * V_15 , struct V_6 * V_7 ,
unsigned int * V_93 , unsigned int V_92 )
{
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_92 ; ++ V_88 ) {
struct V_100 args ;
int V_36 ;
V_36 = F_53 ( V_7 -> V_101 , L_8 ,
L_9 , V_88 , & args ) ;
if ( V_36 < 0 )
return V_36 ;
F_54 ( args . V_102 ) ;
if ( args . V_102 != V_15 -> V_7 -> V_101 || args . V_103 != 1 )
return - V_59 ;
V_93 [ V_88 ] = args . args [ 0 ] ;
}
return 0 ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_5 * V_90 ;
struct V_14 * V_15 ;
unsigned int * V_93 ;
unsigned int V_88 ;
int V_92 ;
int V_36 = - V_96 ;
V_92 = F_56 ( V_7 -> V_101 , L_8 ,
L_9 ) ;
if ( V_92 < 0 )
return - V_96 ;
V_93 = F_57 ( V_92 , sizeof( * V_93 ) , V_89 ) ;
if ( ! V_93 )
return - V_104 ;
F_58 ( & V_105 ) ;
F_59 (mmu, &ipmmu_devices, list) {
V_36 = F_52 ( V_15 , V_7 , V_93 , V_92 ) ;
if ( ! V_36 ) {
break;
}
}
F_60 ( & V_105 ) ;
if ( V_36 < 0 )
goto error;
for ( V_88 = 0 ; V_88 < V_92 ; ++ V_88 ) {
if ( V_93 [ V_88 ] >= V_15 -> V_92 ) {
V_36 = - V_59 ;
goto error;
}
}
V_90 = F_40 ( sizeof( * V_90 ) , V_89 ) ;
if ( ! V_90 ) {
V_36 = - V_104 ;
goto error;
}
V_90 -> V_15 = V_15 ;
V_90 -> V_93 = V_93 ;
V_90 -> V_92 = V_92 ;
V_90 -> V_7 = V_7 ;
F_5 ( V_7 , V_90 ) ;
return 0 ;
error:
F_43 ( V_93 ) ;
return V_36 ;
}
static struct V_2 * F_61 ( unsigned type )
{
if ( type != V_106 )
return NULL ;
return F_39 ( type ) ;
}
static int F_62 ( struct V_6 * V_7 )
{
struct V_14 * V_15 = NULL ;
struct V_107 * V_108 ;
int V_36 ;
if ( F_3 ( V_7 ) ) {
F_63 ( V_7 , L_10 ,
F_46 ( V_7 ) ) ;
return - V_59 ;
}
V_108 = F_64 () ;
if ( F_65 ( V_108 ) ) {
F_45 ( V_7 , L_11 ) ;
V_36 = F_66 ( V_108 ) ;
goto error;
}
V_36 = F_67 ( V_108 , V_7 ) ;
F_68 ( V_108 ) ;
if ( V_36 < 0 ) {
F_45 ( V_7 , L_12 ) ;
V_108 = NULL ;
goto error;
}
V_36 = F_55 ( V_7 ) ;
if ( V_36 < 0 )
goto error;
V_15 = F_3 ( V_7 ) -> V_15 ;
if ( ! V_15 -> V_109 ) {
struct V_110 * V_109 ;
V_109 = F_69 ( & V_111 ,
V_46 , V_112 ) ;
if ( F_65 ( V_109 ) ) {
F_45 ( V_15 -> V_7 , L_13 ) ;
V_36 = F_66 ( V_109 ) ;
goto error;
}
V_15 -> V_109 = V_109 ;
}
V_36 = F_70 ( V_7 , V_15 -> V_109 ) ;
if ( V_36 < 0 ) {
F_45 ( V_7 , L_14 ) ;
goto error;
}
return 0 ;
error:
if ( V_15 )
F_71 ( V_15 -> V_109 ) ;
if ( ! F_72 ( V_108 ) )
F_73 ( V_7 ) ;
F_43 ( F_3 ( V_7 ) -> V_93 ) ;
F_43 ( F_3 ( V_7 ) ) ;
F_5 ( V_7 , NULL ) ;
return V_36 ;
}
static void F_74 ( struct V_6 * V_7 )
{
struct V_5 * V_90 = F_3 ( V_7 ) ;
F_75 ( V_7 ) ;
F_73 ( V_7 ) ;
F_43 ( V_90 -> V_93 ) ;
F_43 ( V_90 ) ;
F_5 ( V_7 , NULL ) ;
}
static struct V_2 * F_76 ( unsigned type )
{
struct V_2 * V_4 = NULL ;
switch ( type ) {
case V_106 :
V_4 = F_39 ( type ) ;
break;
case V_113 :
V_4 = F_39 ( type ) ;
if ( V_4 )
F_77 ( V_4 ) ;
break;
}
return V_4 ;
}
static void F_78 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_113 :
F_79 ( V_4 ) ;
default:
F_42 ( V_4 ) ;
break;
}
}
static int F_80 ( struct V_6 * V_7 )
{
struct V_11 * V_114 = V_7 -> V_11 ;
struct V_107 * V_108 ;
if ( ! V_114 || ! V_114 -> V_12 )
return - V_96 ;
V_108 = F_81 ( V_7 ) ;
if ( F_65 ( V_108 ) )
return F_66 ( V_108 ) ;
F_58 ( & V_115 ) ;
F_82 ( & F_3 ( V_7 ) -> V_116 , & V_117 ) ;
F_60 ( & V_115 ) ;
return 0 ;
}
static void F_83 ( struct V_6 * V_7 )
{
struct V_5 * V_90 = F_3 ( V_7 ) ;
F_58 ( & V_115 ) ;
F_84 ( & V_90 -> V_116 ) ;
F_60 ( & V_115 ) ;
F_73 ( V_7 ) ;
}
static struct V_6 * F_85 ( struct V_6 * V_7 )
{
struct V_5 * V_90 = F_3 ( V_7 ) ;
struct V_5 * V_118 = NULL ;
bool V_119 = false ;
F_58 ( & V_115 ) ;
F_59 (sibling_priv, &ipmmu_slave_devices, list) {
if ( V_90 == V_118 )
continue;
if ( V_118 -> V_15 == V_90 -> V_15 ) {
V_119 = true ;
break;
}
}
F_60 ( & V_115 ) ;
return V_119 ? V_118 -> V_7 : NULL ;
}
static struct V_107 * F_86 ( struct V_6 * V_7 )
{
struct V_107 * V_108 ;
struct V_6 * V_120 ;
V_120 = F_85 ( V_7 ) ;
if ( V_120 )
V_108 = F_87 ( V_120 ) ;
if ( ! V_120 || F_65 ( V_108 ) )
V_108 = F_88 ( V_7 ) ;
return V_108 ;
}
static int F_89 ( struct V_6 * V_7 ,
struct V_100 * V_121 )
{
if ( ! F_90 ( V_121 -> V_102 ) )
return - V_96 ;
return F_55 ( V_7 ) ;
}
static void F_91 ( struct V_14 * V_15 )
{
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < 4 ; ++ V_88 )
F_8 ( V_15 , V_88 * V_22 + V_24 , 0 ) ;
}
static int F_92 ( struct V_122 * V_123 )
{
struct V_14 * V_15 ;
struct V_124 * V_125 ;
int V_87 ;
int V_36 ;
V_15 = F_93 ( & V_123 -> V_7 , sizeof( * V_15 ) , V_89 ) ;
if ( ! V_15 ) {
F_45 ( & V_123 -> V_7 , L_15 ) ;
return - V_104 ;
}
V_15 -> V_7 = & V_123 -> V_7 ;
V_15 -> V_92 = 32 ;
F_41 ( & V_15 -> V_37 ) ;
F_94 ( V_15 -> V_38 , V_39 ) ;
V_125 = F_95 ( V_123 , V_126 , 0 ) ;
V_15 -> V_17 = F_96 ( & V_123 -> V_7 , V_125 ) ;
if ( F_65 ( V_15 -> V_17 ) )
return F_66 ( V_15 -> V_17 ) ;
V_15 -> V_17 += V_127 ;
V_87 = F_97 ( V_123 , 0 ) ;
if ( V_87 < 0 ) {
F_45 ( & V_123 -> V_7 , L_16 ) ;
return V_87 ;
}
V_36 = F_98 ( & V_123 -> V_7 , V_87 , F_38 , 0 ,
F_46 ( & V_123 -> V_7 ) , V_15 ) ;
if ( V_36 < 0 ) {
F_45 ( & V_123 -> V_7 , L_17 , V_87 ) ;
return V_36 ;
}
F_91 ( V_15 ) ;
F_58 ( & V_105 ) ;
F_82 ( & V_15 -> V_116 , & V_128 ) ;
F_60 ( & V_105 ) ;
F_99 ( V_123 , V_15 ) ;
return 0 ;
}
static int F_100 ( struct V_122 * V_123 )
{
struct V_14 * V_15 = F_101 ( V_123 ) ;
F_58 ( & V_105 ) ;
F_84 ( & V_15 -> V_116 ) ;
F_60 ( & V_105 ) ;
#if F_4 ( V_8 ) && ! F_4 ( V_129 )
F_71 ( V_15 -> V_109 ) ;
#endif
F_91 ( V_15 ) ;
return 0 ;
}
static int T_7 F_102 ( void )
{
int V_36 ;
V_36 = F_103 ( & V_130 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( ! F_104 ( & V_111 ) )
F_105 ( & V_111 , & V_131 ) ;
return 0 ;
}
static void T_8 F_106 ( void )
{
return F_107 ( & V_130 ) ;
}
