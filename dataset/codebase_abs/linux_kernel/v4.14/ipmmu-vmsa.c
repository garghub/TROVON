static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 )
{
return V_7 -> V_8 ? V_7 -> V_8 -> V_9 : NULL ;
}
static T_1 F_4 ( struct V_10 * V_11 , unsigned int V_12 )
{
return F_5 ( V_11 -> V_13 + V_12 ) ;
}
static void F_6 ( struct V_10 * V_11 , unsigned int V_12 ,
T_1 V_14 )
{
F_7 ( V_14 , V_11 -> V_13 + V_12 ) ;
}
static T_1 F_8 ( struct V_1 * V_15 , unsigned int V_16 )
{
return F_4 ( V_15 -> V_11 , V_15 -> V_17 * V_18 + V_16 ) ;
}
static void F_9 ( struct V_1 * V_15 , unsigned int V_16 ,
T_1 V_14 )
{
F_6 ( V_15 -> V_11 , V_15 -> V_17 * V_18 + V_16 , V_14 ) ;
}
static void F_10 ( struct V_1 * V_15 )
{
unsigned int V_19 = 0 ;
while ( F_8 ( V_15 , V_20 ) & V_21 ) {
F_11 () ;
if ( ++ V_19 == V_22 ) {
F_12 ( V_15 -> V_11 -> V_7 ,
L_1 ) ;
return;
}
F_13 ( 1 ) ;
}
}
static void F_14 ( struct V_1 * V_15 )
{
T_1 V_16 ;
V_16 = F_8 ( V_15 , V_20 ) ;
V_16 |= V_21 ;
F_9 ( V_15 , V_20 , V_16 ) ;
F_10 ( V_15 ) ;
}
static void F_15 ( struct V_1 * V_15 ,
unsigned int V_23 )
{
struct V_10 * V_11 = V_15 -> V_11 ;
F_6 ( V_11 , F_16 ( V_23 ) , 0 ) ;
F_6 ( V_11 , F_17 ( V_23 ) ,
F_18 ( V_15 -> V_17 ) | V_24 |
V_25 ) ;
}
static void F_19 ( struct V_1 * V_15 ,
unsigned int V_23 )
{
struct V_10 * V_11 = V_15 -> V_11 ;
F_6 ( V_11 , F_17 ( V_23 ) , 0 ) ;
}
static void F_20 ( void * V_26 )
{
struct V_1 * V_15 = V_26 ;
F_14 ( V_15 ) ;
}
static void F_21 ( unsigned long V_27 , T_2 V_28 ,
T_2 V_29 , bool V_30 , void * V_26 )
{
}
static int F_22 ( struct V_10 * V_11 ,
struct V_1 * V_15 )
{
unsigned long V_31 ;
int V_32 ;
F_23 ( & V_11 -> V_33 , V_31 ) ;
V_32 = F_24 ( V_11 -> V_34 , V_35 ) ;
if ( V_32 != V_35 ) {
V_11 -> V_36 [ V_32 ] = V_15 ;
F_25 ( V_32 , V_11 -> V_34 ) ;
}
F_26 ( & V_11 -> V_33 , V_31 ) ;
return V_32 ;
}
static void F_27 ( struct V_10 * V_11 ,
unsigned int V_17 )
{
unsigned long V_31 ;
F_23 ( & V_11 -> V_33 , V_31 ) ;
F_28 ( V_17 , V_11 -> V_34 ) ;
V_11 -> V_36 [ V_17 ] = NULL ;
F_26 ( & V_11 -> V_33 , V_31 ) ;
}
static int F_29 ( struct V_1 * V_15 )
{
T_3 V_37 ;
int V_32 ;
V_15 -> V_38 . V_39 = V_40 ;
V_15 -> V_38 . V_41 = V_42 | V_43 | V_44 ;
V_15 -> V_38 . V_45 = 32 ;
V_15 -> V_38 . V_46 = 40 ;
V_15 -> V_38 . V_47 = & V_48 ;
V_15 -> V_4 . V_49 . V_50 = F_30 ( 32 ) ;
V_15 -> V_4 . V_49 . V_51 = true ;
V_15 -> V_38 . V_52 = V_15 -> V_11 -> V_7 ;
V_32 = F_22 ( V_15 -> V_11 , V_15 ) ;
if ( V_32 == V_35 )
return - V_53 ;
V_15 -> V_17 = V_32 ;
V_15 -> V_54 = F_31 ( V_55 , & V_15 -> V_38 ,
V_15 ) ;
if ( ! V_15 -> V_54 ) {
F_27 ( V_15 -> V_11 , V_15 -> V_17 ) ;
return - V_56 ;
}
V_37 = V_15 -> V_38 . V_57 . V_37 [ 0 ] ;
F_9 ( V_15 , V_58 , V_37 ) ;
F_9 ( V_15 , V_59 , V_37 >> 32 ) ;
F_9 ( V_15 , V_60 , V_61 |
V_62 | V_63 |
V_64 | V_65 ) ;
F_9 ( V_15 , V_66 , V_15 -> V_38 . V_57 . V_67 [ 0 ] ) ;
F_9 ( V_15 , V_68 ,
F_8 ( V_15 , V_68 ) &
~ ( V_69 | V_70 ) ) ;
F_9 ( V_15 , V_71 , F_8 ( V_15 , V_71 ) ) ;
F_9 ( V_15 , V_20 , V_72 | V_21 | V_73 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_15 )
{
F_9 ( V_15 , V_20 , V_21 ) ;
F_10 ( V_15 ) ;
F_27 ( V_15 -> V_11 , V_15 -> V_17 ) ;
}
static T_4 F_33 ( struct V_1 * V_15 )
{
const T_1 V_74 = V_75 | V_76 | V_77 | V_78 ;
struct V_10 * V_11 = V_15 -> V_11 ;
T_1 V_79 ;
T_1 V_27 ;
V_79 = F_8 ( V_15 , V_71 ) ;
if ( ! ( V_79 & V_74 ) )
return V_80 ;
V_27 = F_8 ( V_15 , V_81 ) ;
F_9 ( V_15 , V_71 , 0 ) ;
if ( V_79 & V_75 )
F_12 ( V_11 -> V_7 , L_2 ,
V_27 ) ;
if ( V_79 & V_76 )
F_12 ( V_11 -> V_7 , L_3 ,
V_27 ) ;
if ( ! ( V_79 & ( V_77 | V_78 ) ) )
return V_80 ;
if ( ! F_34 ( & V_15 -> V_4 , V_11 -> V_7 , V_27 , 0 ) )
return V_82 ;
F_12 ( V_11 -> V_7 ,
L_4 ,
V_79 , V_27 ) ;
return V_82 ;
}
static T_4 F_35 ( int V_83 , void * V_7 )
{
struct V_10 * V_11 = V_7 ;
T_4 V_79 = V_80 ;
unsigned int V_84 ;
unsigned long V_31 ;
F_23 ( & V_11 -> V_33 , V_31 ) ;
for ( V_84 = 0 ; V_84 < V_35 ; V_84 ++ ) {
if ( ! V_11 -> V_36 [ V_84 ] )
continue;
if ( F_33 ( V_11 -> V_36 [ V_84 ] ) == V_82 )
V_79 = V_82 ;
}
F_26 ( & V_11 -> V_33 , V_31 ) ;
return V_79 ;
}
static struct V_2 * F_36 ( unsigned type )
{
struct V_1 * V_15 ;
V_15 = F_37 ( sizeof( * V_15 ) , V_85 ) ;
if ( ! V_15 )
return NULL ;
F_38 ( & V_15 -> V_33 ) ;
return & V_15 -> V_4 ;
}
static void F_39 ( struct V_2 * V_4 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
F_32 ( V_15 ) ;
F_40 ( V_15 -> V_54 ) ;
F_41 ( V_15 ) ;
}
static int F_42 ( struct V_2 * V_4 ,
struct V_6 * V_7 )
{
struct V_5 * V_86 = F_3 ( V_7 ) ;
struct V_8 * V_87 = V_7 -> V_8 ;
struct V_10 * V_11 = V_86 -> V_11 ;
struct V_1 * V_15 = F_1 ( V_4 ) ;
unsigned long V_31 ;
unsigned int V_84 ;
int V_32 = 0 ;
if ( ! V_86 || ! V_86 -> V_11 ) {
F_43 ( V_7 , L_5 ) ;
return - V_88 ;
}
F_23 ( & V_15 -> V_33 , V_31 ) ;
if ( ! V_15 -> V_11 ) {
V_15 -> V_11 = V_11 ;
V_32 = F_29 ( V_15 ) ;
} else if ( V_15 -> V_11 != V_11 ) {
F_43 ( V_7 , L_6 ,
F_44 ( V_11 -> V_7 ) , F_44 ( V_15 -> V_11 -> V_7 ) ) ;
V_32 = - V_56 ;
} else
F_45 ( V_7 , L_7 , V_15 -> V_17 ) ;
F_26 ( & V_15 -> V_33 , V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_84 = 0 ; V_84 < V_87 -> V_89 ; ++ V_84 )
F_15 ( V_15 , V_87 -> V_90 [ V_84 ] ) ;
return 0 ;
}
static void F_46 ( struct V_2 * V_4 ,
struct V_6 * V_7 )
{
struct V_8 * V_87 = V_7 -> V_8 ;
struct V_1 * V_15 = F_1 ( V_4 ) ;
unsigned int V_84 ;
for ( V_84 = 0 ; V_84 < V_87 -> V_89 ; ++ V_84 )
F_19 ( V_15 , V_87 -> V_90 [ V_84 ] ) ;
}
static int F_47 ( struct V_2 * V_4 , unsigned long V_27 ,
T_5 V_91 , T_2 V_28 , int V_92 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
if ( ! V_15 )
return - V_93 ;
return V_15 -> V_54 -> V_94 ( V_15 -> V_54 , V_27 , V_91 , V_28 , V_92 ) ;
}
static T_2 F_48 ( struct V_2 * V_4 , unsigned long V_27 ,
T_2 V_28 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
return V_15 -> V_54 -> V_95 ( V_15 -> V_54 , V_27 , V_28 ) ;
}
static T_5 F_49 ( struct V_2 * V_4 ,
T_6 V_27 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
return V_15 -> V_54 -> V_96 ( V_15 -> V_54 , V_27 ) ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_97 * args )
{
struct V_98 * V_99 ;
struct V_5 * V_86 ;
V_99 = F_51 ( args -> V_100 ) ;
if ( ! V_99 )
return - V_93 ;
V_86 = F_37 ( sizeof( * V_86 ) , V_85 ) ;
if ( ! V_86 )
return - V_101 ;
V_86 -> V_11 = F_52 ( V_99 ) ;
V_86 -> V_7 = V_7 ;
V_7 -> V_8 -> V_9 = V_86 ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 ,
struct V_97 * V_102 )
{
F_54 ( V_7 , V_102 -> args , 1 ) ;
if ( F_3 ( V_7 ) )
return 0 ;
return F_50 ( V_7 , V_102 ) ;
}
static struct V_2 * F_55 ( unsigned type )
{
if ( type != V_103 )
return NULL ;
return F_36 ( type ) ;
}
static int F_56 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = NULL ;
struct V_104 * V_105 ;
int V_32 ;
if ( ! F_3 ( V_7 ) )
return - V_93 ;
V_105 = F_57 () ;
if ( F_58 ( V_105 ) ) {
F_43 ( V_7 , L_8 ) ;
V_32 = F_59 ( V_105 ) ;
goto error;
}
V_32 = F_60 ( V_105 , V_7 ) ;
F_61 ( V_105 ) ;
if ( V_32 < 0 ) {
F_43 ( V_7 , L_9 ) ;
V_105 = NULL ;
goto error;
}
V_11 = F_3 ( V_7 ) -> V_11 ;
if ( ! V_11 -> V_106 ) {
struct V_107 * V_106 ;
V_106 = F_62 ( & V_108 ,
V_42 , V_109 ) ;
if ( F_58 ( V_106 ) ) {
F_43 ( V_11 -> V_7 , L_10 ) ;
V_32 = F_59 ( V_106 ) ;
goto error;
}
V_11 -> V_106 = V_106 ;
}
V_32 = F_63 ( V_7 , V_11 -> V_106 ) ;
if ( V_32 < 0 ) {
F_43 ( V_7 , L_11 ) ;
goto error;
}
return 0 ;
error:
if ( V_11 )
F_64 ( V_11 -> V_106 ) ;
if ( ! F_65 ( V_105 ) )
F_66 ( V_7 ) ;
return V_32 ;
}
static void F_67 ( struct V_6 * V_7 )
{
F_68 ( V_7 ) ;
F_66 ( V_7 ) ;
}
static struct V_2 * F_69 ( unsigned type )
{
struct V_2 * V_4 = NULL ;
switch ( type ) {
case V_103 :
V_4 = F_36 ( type ) ;
break;
case V_110 :
V_4 = F_36 ( type ) ;
if ( V_4 )
F_70 ( V_4 ) ;
break;
}
return V_4 ;
}
static void F_71 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_110 :
F_72 ( V_4 ) ;
default:
F_39 ( V_4 ) ;
break;
}
}
static int F_73 ( struct V_6 * V_7 )
{
struct V_104 * V_105 ;
if ( ! F_3 ( V_7 ) )
return - V_93 ;
V_105 = F_74 ( V_7 ) ;
if ( F_58 ( V_105 ) )
return F_59 ( V_105 ) ;
F_75 ( & V_111 ) ;
F_76 ( & F_3 ( V_7 ) -> V_112 , & V_113 ) ;
F_77 ( & V_111 ) ;
return 0 ;
}
static void F_78 ( struct V_6 * V_7 )
{
struct V_5 * V_86 = F_3 ( V_7 ) ;
F_75 ( & V_111 ) ;
F_79 ( & V_86 -> V_112 ) ;
F_77 ( & V_111 ) ;
F_66 ( V_7 ) ;
}
static struct V_6 * F_80 ( struct V_6 * V_7 )
{
struct V_5 * V_86 = F_3 ( V_7 ) ;
struct V_5 * V_114 = NULL ;
bool V_115 = false ;
F_75 ( & V_111 ) ;
F_81 (sibling_priv, &ipmmu_slave_devices, list) {
if ( V_86 == V_114 )
continue;
if ( V_114 -> V_11 == V_86 -> V_11 ) {
V_115 = true ;
break;
}
}
F_77 ( & V_111 ) ;
return V_115 ? V_114 -> V_7 : NULL ;
}
static struct V_104 * F_82 ( struct V_6 * V_7 )
{
struct V_104 * V_105 ;
struct V_6 * V_116 ;
V_116 = F_80 ( V_7 ) ;
if ( V_116 )
V_105 = F_83 ( V_116 ) ;
if ( ! V_116 || F_58 ( V_105 ) )
V_105 = F_84 ( V_7 ) ;
return V_105 ;
}
static void F_85 ( struct V_10 * V_11 )
{
unsigned int V_84 ;
for ( V_84 = 0 ; V_84 < 4 ; ++ V_84 )
F_6 ( V_11 , V_84 * V_18 + V_20 , 0 ) ;
}
static int F_86 ( struct V_98 * V_117 )
{
struct V_10 * V_11 ;
struct V_118 * V_119 ;
int V_83 ;
int V_32 ;
V_11 = F_87 ( & V_117 -> V_7 , sizeof( * V_11 ) , V_85 ) ;
if ( ! V_11 ) {
F_43 ( & V_117 -> V_7 , L_12 ) ;
return - V_101 ;
}
V_11 -> V_7 = & V_117 -> V_7 ;
V_11 -> V_120 = 32 ;
F_38 ( & V_11 -> V_33 ) ;
F_88 ( V_11 -> V_34 , V_35 ) ;
V_119 = F_89 ( V_117 , V_121 , 0 ) ;
V_11 -> V_13 = F_90 ( & V_117 -> V_7 , V_119 ) ;
if ( F_58 ( V_11 -> V_13 ) )
return F_59 ( V_11 -> V_13 ) ;
V_11 -> V_13 += V_122 ;
V_83 = F_91 ( V_117 , 0 ) ;
if ( V_83 < 0 ) {
F_43 ( & V_117 -> V_7 , L_13 ) ;
return V_83 ;
}
V_32 = F_92 ( & V_117 -> V_7 , V_83 , F_35 , 0 ,
F_44 ( & V_117 -> V_7 ) , V_11 ) ;
if ( V_32 < 0 ) {
F_43 ( & V_117 -> V_7 , L_14 , V_83 ) ;
return V_32 ;
}
F_85 ( V_11 ) ;
V_32 = F_93 ( & V_11 -> V_123 , & V_117 -> V_7 , NULL ,
F_44 ( & V_117 -> V_7 ) ) ;
if ( V_32 )
return V_32 ;
F_94 ( & V_11 -> V_123 , & V_124 ) ;
F_95 ( & V_11 -> V_123 , & V_117 -> V_7 . V_125 -> V_126 ) ;
V_32 = F_96 ( & V_11 -> V_123 ) ;
if ( V_32 )
return V_32 ;
F_97 ( V_117 , V_11 ) ;
return 0 ;
}
static int F_98 ( struct V_98 * V_117 )
{
struct V_10 * V_11 = F_52 ( V_117 ) ;
F_99 ( & V_11 -> V_123 ) ;
F_100 ( & V_11 -> V_123 ) ;
#if F_101 ( V_127 ) && ! F_101 ( V_128 )
F_64 ( V_11 -> V_106 ) ;
#endif
F_85 ( V_11 ) ;
return 0 ;
}
static int T_7 F_102 ( void )
{
int V_32 ;
V_32 = F_103 ( & V_129 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! F_104 ( & V_108 ) )
F_105 ( & V_108 , & V_124 ) ;
return 0 ;
}
static void T_8 F_106 ( void )
{
return F_107 ( & V_129 ) ;
}
