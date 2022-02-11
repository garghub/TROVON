bool F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( ( ! F_2 ( V_2 , V_3 ) ) || ( V_4
&& ! F_2 ( V_2 , V_3 + V_4 - 1 ) ) ) {
F_3 ( L_1 ,
V_3 , V_4 ) ;
return false ;
}
return true ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_5 , T_1 * V_6 )
{
if ( F_5 ( ! F_2 ( V_2 , V_5 ) ,
L_2 , V_5 ) )
return - V_7 ;
if ( F_6 ( V_2 , V_5 ) )
* V_6 = F_7 ( V_2 )
+ ( V_5 - F_8 ( V_2 ) ) ;
else
* V_6 = F_9 ( V_2 )
+ ( V_5 - F_10 ( V_2 ) ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_6 , T_1 * V_5 )
{
if ( F_5 ( ! F_12 ( V_2 -> V_8 , V_6 ) ,
L_3 , V_6 ) )
return - V_7 ;
if ( F_13 ( V_2 -> V_8 , V_6 ) )
* V_5 = F_7 ( V_2 )
+ ( V_6 - F_14 ( V_2 -> V_8 ) ) ;
else
* V_5 = F_9 ( V_2 )
+ ( V_6 - F_15 ( V_2 -> V_8 ) ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
T_1 V_6 ;
int V_11 ;
V_11 = F_4 ( V_2 , V_9 << V_12 ,
& V_6 ) ;
if ( V_11 )
return V_11 ;
* V_10 = V_6 >> V_12 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_9 )
{
T_1 V_5 ;
int V_11 ;
V_11 = F_11 ( V_2 , V_10 << V_12 ,
& V_5 ) ;
if ( V_11 )
return V_11 ;
* V_9 = V_5 >> V_12 ;
return 0 ;
}
static inline int F_18 ( int type )
{
return V_13 [ type ] . V_14 ;
}
static inline int F_19 ( int type )
{
return V_13 [ type ] . V_15 ;
}
static inline int F_20 ( int type )
{
return V_13 [ type ] . V_16 ;
}
static T_1 F_21 ( struct V_17 * V_18 , unsigned long V_19 )
{
void T_3 * V_3 = ( V_20 T_3 * ) V_18 -> V_21 . V_22 + V_19 ;
return F_22 ( V_3 ) ;
}
static void F_23 ( struct V_17 * V_18 )
{
F_24 ( V_18 ) ;
F_25 ( V_23 , V_24 ) ;
F_26 ( V_18 ) ;
}
static void F_27 ( struct V_17 * V_18 ,
unsigned long V_19 , T_1 V_25 )
{
void T_3 * V_3 = ( V_20 T_3 * ) V_18 -> V_21 . V_22 + V_19 ;
F_28 ( V_25 , V_3 ) ;
}
static inline int F_29 ( void * V_26 ,
struct V_27 * V_28 ,
unsigned long V_19 , bool V_29 , unsigned long V_30 ,
struct V_1 * V_2 )
{
const struct V_31 * V_32 = & V_2 -> V_8 -> V_33 ;
int V_11 ;
if ( F_30 ( V_32 -> V_34 != 8 ) )
return - V_35 ;
if ( V_29 ) {
V_11 = F_31 ( V_2 , V_30 +
( V_19 << V_32 -> V_36 ) ,
& V_28 -> V_37 , 8 ) ;
if ( F_30 ( V_11 ) )
return V_11 ;
} else if ( ! V_26 ) {
V_28 -> V_37 = F_21 ( V_2 -> V_8 -> V_18 , V_19 ) ;
} else {
V_28 -> V_37 = * ( ( T_1 * ) V_26 + V_19 ) ;
}
return 0 ;
}
static inline int F_32 ( void * V_26 ,
struct V_27 * V_28 ,
unsigned long V_19 , bool V_29 , unsigned long V_30 ,
struct V_1 * V_2 )
{
const struct V_31 * V_32 = & V_2 -> V_8 -> V_33 ;
int V_11 ;
if ( F_30 ( V_32 -> V_34 != 8 ) )
return - V_35 ;
if ( V_29 ) {
V_11 = F_33 ( V_2 , V_30 +
( V_19 << V_32 -> V_36 ) ,
& V_28 -> V_37 , 8 ) ;
if ( F_30 ( V_11 ) )
return V_11 ;
} else if ( ! V_26 ) {
F_27 ( V_2 -> V_8 -> V_18 , V_19 , V_28 -> V_37 ) ;
} else {
* ( ( T_1 * ) V_26 + V_19 ) = V_28 -> V_37 ;
}
return 0 ;
}
static unsigned long F_34 ( struct V_27 * V_28 )
{
unsigned long V_38 ;
if ( V_28 -> type == V_39 )
V_38 = ( V_28 -> V_37 & V_40 ) >> 12 ;
else if ( V_28 -> type == V_41 )
V_38 = ( V_28 -> V_37 & V_42 ) >> 12 ;
else
V_38 = ( V_28 -> V_37 & V_43 ) >> 12 ;
return V_38 ;
}
static void F_35 ( struct V_27 * V_28 , unsigned long V_38 )
{
if ( V_28 -> type == V_39 ) {
V_28 -> V_37 &= ~ V_40 ;
V_38 &= ( V_40 >> 12 ) ;
} else if ( V_28 -> type == V_41 ) {
V_28 -> V_37 &= ~ V_42 ;
V_38 &= ( V_42 >> 12 ) ;
} else {
V_28 -> V_37 &= ~ V_43 ;
V_38 &= ( V_43 >> 12 ) ;
}
V_28 -> V_37 |= ( V_38 << 12 ) ;
}
static bool F_36 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 -> type ) == V_44 )
return false ;
V_28 -> type = F_19 ( V_28 -> type ) ;
if ( ! ( V_28 -> V_37 & ( 1 << 7 ) ) )
return false ;
V_28 -> type = F_20 ( V_28 -> type ) ;
return true ;
}
static bool F_37 ( struct V_27 * V_28 )
{
if ( V_28 -> type == V_45
|| V_28 -> type == V_46 )
return ( V_28 -> V_37 != 0 ) ;
else
return ( V_28 -> V_37 & ( 1 << 0 ) ) ;
}
static void F_38 ( struct V_27 * V_28 )
{
V_28 -> V_37 &= ~ ( 1 << 0 ) ;
}
static unsigned long F_39 ( unsigned long V_47 )
{
unsigned long V_48 = ( V_47 >> V_12 ) ;
F_40 ( V_49 , V_47 , V_48 ) ;
return V_48 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_27 * V_50 ,
struct V_27 * V_51 )
{
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
unsigned long V_56 , V_57 ;
* V_51 = * V_50 ;
if ( ! V_53 -> V_58 ( V_50 ) )
return 0 ;
V_56 = V_53 -> V_59 ( V_50 ) ;
V_57 = F_42 ( V_2 , V_56 ) ;
if ( V_57 == V_60 ) {
F_3 ( L_4 , V_56 ) ;
return - V_61 ;
}
V_53 -> V_62 ( V_51 , V_57 ) ;
return 0 ;
}
int F_43 ( struct V_63 * V_64 ,
void * V_65 , struct V_27 * V_28 ,
unsigned long V_19 )
{
struct V_66 * V_8 = V_64 -> V_2 -> V_8 ;
struct V_52 * V_53 = V_8 -> V_54 . V_55 ;
int V_11 ;
V_28 -> type = V_64 -> V_67 ;
V_11 = V_53 -> V_68 ( V_65 , V_28 , V_19 , false , 0 , V_64 -> V_2 ) ;
if ( V_11 )
return V_11 ;
V_53 -> V_69 ( V_28 ) ;
return 0 ;
}
int F_44 ( struct V_63 * V_64 ,
void * V_65 , struct V_27 * V_28 ,
unsigned long V_19 )
{
struct V_66 * V_8 = V_64 -> V_2 -> V_8 ;
struct V_52 * V_53 = V_8 -> V_54 . V_55 ;
return V_53 -> V_70 ( V_65 , V_28 , V_19 , false , 0 , V_64 -> V_2 ) ;
}
static inline int F_45 (
struct V_71 * V_72 ,
void * V_65 , int type ,
struct V_27 * V_28 , unsigned long V_19 ,
bool V_73 )
{
struct V_66 * V_8 = V_72 -> V_2 -> V_8 ;
struct V_52 * V_53 = V_8 -> V_54 . V_55 ;
int V_11 ;
V_28 -> type = F_19 ( type ) ;
if ( F_5 ( ! F_46 ( V_28 -> type ) , L_5 ) )
return - V_35 ;
V_11 = V_53 -> V_68 ( V_65 , V_28 , V_19 , V_73 ,
V_72 -> V_74 . V_56 << V_12 ,
V_72 -> V_2 ) ;
if ( V_11 )
return V_11 ;
V_53 -> V_69 ( V_28 ) ;
return 0 ;
}
static inline int F_47 (
struct V_71 * V_72 ,
void * V_65 , int type ,
struct V_27 * V_28 , unsigned long V_19 ,
bool V_73 )
{
struct V_66 * V_8 = V_72 -> V_2 -> V_8 ;
struct V_52 * V_53 = V_8 -> V_54 . V_55 ;
if ( F_5 ( ! F_46 ( V_28 -> type ) , L_5 ) )
return - V_35 ;
return V_53 -> V_70 ( V_65 , V_28 , V_19 , V_73 ,
V_72 -> V_74 . V_56 << V_12 ,
V_72 -> V_2 ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_75 * V_50 ,
unsigned long V_56 ,
int (* F_49)( void * , T_1 , void * , int ) ,
void * V_76 )
{
F_50 ( & V_50 -> V_77 ) ;
V_50 -> V_78 = false ;
V_50 -> V_56 = V_56 ;
V_50 -> F_49 = F_49 ;
V_50 -> V_76 = V_76 ;
V_50 -> V_79 = NULL ;
V_50 -> V_80 = 0 ;
F_51 ( V_2 -> V_54 . V_81 , & V_50 -> V_77 , V_50 -> V_56 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_75 * V_50 )
{
if ( ! F_53 ( & V_50 -> V_77 ) )
F_54 ( & V_50 -> V_77 ) ;
if ( V_50 -> V_79 )
F_55 ( V_2 , V_50 -> V_79 ) ;
if ( V_50 -> V_78 )
F_56 ( V_2 , V_50 ) ;
}
struct V_75 * F_57 (
struct V_1 * V_2 , unsigned long V_56 )
{
struct V_75 * V_50 ;
F_58 (vgpu->gtt.guest_page_hash_table,
p, node, gfn) {
if ( V_50 -> V_56 == V_56 )
return V_50 ;
}
return NULL ;
}
static inline int F_59 ( struct V_1 * V_2 ,
struct V_82 * V_50 , int type )
{
struct V_83 * V_84 = & V_2 -> V_8 -> V_18 -> V_85 . V_86 -> V_87 ;
T_4 V_88 ;
V_88 = F_60 ( V_84 , V_50 -> V_89 , 0 , 4096 , V_90 ) ;
if ( F_61 ( V_84 , V_88 ) ) {
F_3 ( L_6 ) ;
return - V_35 ;
}
V_50 -> V_91 = F_62 ( V_50 -> V_89 ) ;
V_50 -> type = type ;
F_50 ( & V_50 -> V_77 ) ;
V_50 -> V_57 = V_88 >> V_12 ;
F_51 ( V_2 -> V_54 . V_92 , & V_50 -> V_77 , V_50 -> V_57 ) ;
return 0 ;
}
static inline void F_63 ( struct V_1 * V_2 ,
struct V_82 * V_50 )
{
struct V_83 * V_84 = & V_2 -> V_8 -> V_18 -> V_85 . V_86 -> V_87 ;
F_64 ( V_84 , V_50 -> V_57 << V_12 , 4096 ,
V_90 ) ;
if ( ! F_53 ( & V_50 -> V_77 ) )
F_54 ( & V_50 -> V_77 ) ;
}
static inline struct V_82 * F_65 (
struct V_1 * V_2 , unsigned long V_57 )
{
struct V_82 * V_50 ;
F_58 (vgpu->gtt.shadow_page_hash_table,
p, node, mfn) {
if ( V_50 -> V_57 == V_57 )
return V_50 ;
}
return NULL ;
}
static void * F_66 ( T_5 V_93 )
{
struct V_71 * V_72 ;
V_72 = F_67 ( sizeof( * V_72 ) , V_93 ) ;
if ( ! V_72 )
return NULL ;
V_72 -> V_94 . V_89 = F_68 ( V_93 ) ;
if ( ! V_72 -> V_94 . V_89 ) {
F_69 ( V_72 ) ;
return NULL ;
}
return V_72 ;
}
static void F_70 ( struct V_71 * V_72 )
{
F_71 ( V_72 -> V_94 . V_89 ) ;
F_69 ( V_72 ) ;
}
static void F_72 ( struct V_71 * V_72 )
{
F_73 ( V_72 -> V_2 -> V_95 , V_72 , V_72 -> V_94 . type ) ;
F_63 ( V_72 -> V_2 , & V_72 -> V_94 ) ;
F_52 ( V_72 -> V_2 , & V_72 -> V_74 ) ;
F_74 ( & V_72 -> V_96 ) ;
F_70 ( V_72 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
struct V_82 * V_99 ;
int V_100 ;
F_76 (vgpu->gtt.shadow_page_hash_table, i, n, sp, node)
F_72 ( F_77 ( V_99 ) ) ;
}
static int F_78 ( void * V_101 , T_1 V_102 ,
void * V_103 , int V_104 )
{
struct V_75 * V_105 = (struct V_75 * ) V_101 ;
int V_11 ;
if ( V_104 != 4 && V_104 != 8 )
return - V_35 ;
if ( ! V_105 -> V_78 )
return - V_35 ;
V_11 = F_79 ( V_101 ,
V_102 , V_103 , V_104 ) ;
if ( V_11 )
return V_11 ;
return V_11 ;
}
static struct V_71 * F_80 (
struct V_1 * V_2 , int type , unsigned long V_56 )
{
struct V_71 * V_72 = NULL ;
int V_11 ;
V_106:
V_72 = F_66 ( V_107 | V_108 ) ;
if ( ! V_72 ) {
if ( F_81 ( V_2 -> V_8 ) )
goto V_106;
F_3 ( L_7 ) ;
return F_82 ( - V_109 ) ;
}
V_72 -> V_2 = V_2 ;
V_72 -> V_110 = type ;
F_83 ( & V_72 -> V_111 , 1 ) ;
F_84 ( & V_72 -> V_96 ) ;
V_11 = F_59 ( V_2 , & V_72 -> V_94 , type ) ;
if ( V_11 ) {
F_3 ( L_8 ) ;
goto V_112;
}
V_11 = F_48 ( V_2 , & V_72 -> V_74 ,
V_56 , F_78 , NULL ) ;
if ( V_11 ) {
F_3 ( L_9 ) ;
goto V_112;
}
F_85 ( V_2 -> V_95 , V_72 , type , V_72 -> V_94 . V_57 , V_56 ) ;
return V_72 ;
V_112:
F_72 ( V_72 ) ;
return F_82 ( V_11 ) ;
}
static struct V_71 * F_86 (
struct V_1 * V_2 , unsigned long V_57 )
{
struct V_82 * V_50 = F_65 ( V_2 , V_57 ) ;
if ( V_50 )
return F_77 ( V_50 ) ;
F_3 ( L_10 , V_57 ) ;
return NULL ;
}
static void F_87 ( struct V_71 * V_72 )
{
int V_113 = F_88 ( & V_72 -> V_111 ) ;
F_89 ( V_72 -> V_2 -> V_95 , L_11 , V_72 , V_113 , ( V_113 + 1 ) ) ;
F_90 ( & V_72 -> V_111 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
struct V_71 * V_114 ;
T_6 V_115 ;
if ( F_30 ( ! F_92 ( F_18 ( V_28 -> type ) ) ) )
return - V_35 ;
if ( V_28 -> type != V_45
&& V_28 -> type != V_46 ) {
V_115 = F_18 ( V_28 -> type ) + 1 ;
if ( V_53 -> V_59 ( V_28 ) ==
V_2 -> V_54 . V_116 [ V_115 ] . V_117 )
return 0 ;
}
V_114 = F_86 ( V_2 , V_53 -> V_59 ( V_28 ) ) ;
if ( ! V_114 ) {
F_3 ( L_12 ,
V_53 -> V_59 ( V_28 ) ) ;
return - V_61 ;
}
return F_93 ( V_114 ) ;
}
static int F_93 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_27 V_28 ;
unsigned long V_19 ;
int V_11 ;
int V_113 = F_88 ( & V_72 -> V_111 ) ;
F_94 ( V_72 -> V_2 -> V_95 , L_13 , V_72 ,
V_72 -> V_74 . V_56 , V_72 -> V_94 . type ) ;
F_89 ( V_72 -> V_2 -> V_95 , L_14 , V_72 , V_113 , ( V_113 - 1 ) ) ;
if ( F_95 ( & V_72 -> V_111 ) > 0 )
return 0 ;
if ( F_96 ( V_72 -> V_94 . type ) )
goto V_118;
F_97 (spt, &e, index) {
if ( ! F_92 ( F_18 ( V_28 . type ) ) ) {
F_3 ( L_15 ) ;
return - V_35 ;
}
V_11 = F_91 (
V_72 -> V_2 , & V_28 ) ;
if ( V_11 )
goto V_119;
}
V_118:
F_94 ( V_72 -> V_2 -> V_95 , L_16 , V_72 ,
V_72 -> V_74 . V_56 , V_72 -> V_94 . type ) ;
F_72 ( V_72 ) ;
return 0 ;
V_119:
F_3 ( L_17 ,
V_72 , V_28 . V_37 , V_28 . type ) ;
return V_11 ;
}
static struct V_71 * F_98 (
struct V_1 * V_2 , struct V_27 * V_120 )
{
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
struct V_71 * V_114 = NULL ;
struct V_75 * V_121 ;
int V_11 ;
if ( F_30 ( ! F_92 ( F_18 ( V_120 -> type ) ) ) ) {
V_11 = - V_35 ;
goto V_119;
}
V_121 = F_57 ( V_2 , V_53 -> V_59 ( V_120 ) ) ;
if ( V_121 ) {
V_114 = F_99 ( V_121 ) ;
F_87 ( V_114 ) ;
} else {
int type = F_18 ( V_120 -> type ) ;
V_114 = F_80 ( V_2 , type , V_53 -> V_59 ( V_120 ) ) ;
if ( F_100 ( V_114 ) ) {
V_11 = F_101 ( V_114 ) ;
goto V_119;
}
V_11 = F_102 ( V_2 , & V_114 -> V_74 ) ;
if ( V_11 )
goto V_119;
V_11 = F_103 ( V_114 ) ;
if ( V_11 )
goto V_119;
F_94 ( V_2 -> V_95 , L_18 , V_114 , V_114 -> V_74 . V_56 ,
V_114 -> V_94 . type ) ;
}
return V_114 ;
V_119:
F_3 ( L_19 ,
V_114 , V_120 -> V_37 , V_120 -> type ) ;
return F_82 ( V_11 ) ;
}
static inline void F_104 ( struct V_27 * V_122 ,
struct V_71 * V_114 , struct V_27 * V_123 )
{
struct V_52 * V_53 = V_114 -> V_2 -> V_8 -> V_54 . V_55 ;
V_122 -> type = V_123 -> type ;
V_122 -> V_37 = V_123 -> V_37 ;
V_53 -> V_62 ( V_122 , V_114 -> V_94 . V_57 ) ;
}
static int F_103 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_71 * V_114 ;
struct V_27 V_122 , V_123 ;
unsigned long V_100 ;
int V_11 ;
F_94 ( V_72 -> V_2 -> V_95 , L_20 , V_72 ,
V_72 -> V_74 . V_56 , V_72 -> V_94 . type ) ;
if ( F_96 ( V_72 -> V_94 . type ) ) {
F_105 (spt, &ge, i) {
V_11 = F_41 ( V_2 , & V_123 , & V_122 ) ;
if ( V_11 )
goto V_119;
F_106 ( V_72 , & V_122 , V_100 ) ;
}
return 0 ;
}
F_105 (spt, &ge, i) {
if ( ! F_92 ( F_18 ( V_123 . type ) ) ) {
F_3 ( L_21 ) ;
V_11 = - V_35 ;
goto V_119;
}
V_114 = F_98 ( V_2 , & V_123 ) ;
if ( F_100 ( V_114 ) ) {
V_11 = F_101 ( V_114 ) ;
goto V_119;
}
F_107 ( V_72 , & V_122 , V_100 ) ;
F_104 ( & V_122 , V_114 , & V_123 ) ;
F_106 ( V_72 , & V_122 , V_100 ) ;
}
return 0 ;
V_119:
F_3 ( L_19 ,
V_72 , V_123 . V_37 , V_123 . type ) ;
return V_11 ;
}
static int F_108 ( struct V_75 * V_105 ,
struct V_27 * V_122 , unsigned long V_19 )
{
struct V_71 * V_72 = F_99 ( V_105 ) ;
struct V_82 * V_99 = & V_72 -> V_94 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
int V_11 ;
F_109 ( V_72 -> V_2 -> V_95 , L_22 , V_72 , V_99 -> type , V_122 -> V_37 ,
V_19 ) ;
if ( ! V_53 -> V_58 ( V_122 ) )
return 0 ;
if ( V_53 -> V_59 ( V_122 ) == V_2 -> V_54 . V_116 [ V_99 -> type ] . V_117 )
return 0 ;
if ( F_92 ( F_18 ( V_122 -> type ) ) ) {
struct V_71 * V_114 =
F_86 ( V_2 , V_53 -> V_59 ( V_122 ) ) ;
if ( ! V_114 ) {
F_3 ( L_23 ) ;
V_11 = - V_61 ;
goto V_119;
}
V_11 = F_93 ( V_114 ) ;
if ( V_11 )
goto V_119;
}
return 0 ;
V_119:
F_3 ( L_19 ,
V_72 , V_122 -> V_37 , V_122 -> type ) ;
return V_11 ;
}
static int F_110 ( struct V_75 * V_105 ,
struct V_27 * V_120 , unsigned long V_19 )
{
struct V_71 * V_72 = F_99 ( V_105 ) ;
struct V_82 * V_99 = & V_72 -> V_94 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_27 V_51 ;
struct V_71 * V_114 ;
int V_11 ;
F_109 ( V_72 -> V_2 -> V_95 , L_24 , V_72 , V_99 -> type ,
V_120 -> V_37 , V_19 ) ;
if ( F_92 ( F_18 ( V_120 -> type ) ) ) {
V_114 = F_98 ( V_2 , V_120 ) ;
if ( F_100 ( V_114 ) ) {
V_11 = F_101 ( V_114 ) ;
goto V_119;
}
F_107 ( V_72 , & V_51 , V_19 ) ;
F_104 ( & V_51 , V_114 , V_120 ) ;
F_106 ( V_72 , & V_51 , V_19 ) ;
} else {
V_11 = F_41 ( V_2 , V_120 , & V_51 ) ;
if ( V_11 )
goto V_119;
F_106 ( V_72 , & V_51 , V_19 ) ;
}
return 0 ;
V_119:
F_3 ( L_25 ,
V_72 , V_120 -> V_37 , V_120 -> type ) ;
return V_11 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_124 * V_79 )
{
const struct V_31 * V_32 = & V_2 -> V_8 -> V_33 ;
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_52 * V_53 = V_8 -> V_54 . V_55 ;
struct V_71 * V_72 =
F_99 ( V_79 -> V_74 ) ;
struct V_27 V_125 , V_126 , V_51 ;
int V_19 ;
int V_11 ;
F_112 ( V_2 -> V_95 , L_26 , V_79 -> V_95 ,
V_79 -> V_74 , V_72 -> V_110 ) ;
V_125 . type = V_126 . type = F_19 ( V_72 -> V_110 ) ;
V_125 . V_37 = V_126 . V_37 = 0 ;
for ( V_19 = 0 ; V_19 < ( V_127 >> V_32 -> V_36 ) ;
V_19 ++ ) {
V_53 -> V_68 ( V_79 -> V_128 , & V_125 , V_19 , false , 0 , V_2 ) ;
V_53 -> V_68 ( NULL , & V_126 , V_19 , true ,
V_79 -> V_74 -> V_56 << V_129 , V_2 ) ;
if ( V_125 . V_37 == V_126 . V_37
&& ! F_113 ( V_19 , V_72 -> V_130 ) )
continue;
F_114 ( V_2 -> V_95 , V_79 -> V_95 ,
V_79 -> V_74 , V_72 -> V_110 ,
V_126 . V_37 , V_19 ) ;
V_11 = F_41 ( V_2 , & V_126 , & V_51 ) ;
if ( V_11 )
return V_11 ;
V_53 -> V_70 ( V_79 -> V_128 , & V_126 , V_19 , false , 0 , V_2 ) ;
F_106 ( V_72 , & V_51 , V_19 ) ;
}
V_79 -> V_74 -> V_80 = 0 ;
F_74 ( & V_72 -> V_96 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_124 * V_79 )
{
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_71 * V_72 =
F_99 ( V_79 -> V_74 ) ;
F_112 ( V_2 -> V_95 , L_27 , V_79 -> V_95 ,
V_79 -> V_74 , V_72 -> V_110 ) ;
V_79 -> V_74 -> V_80 = 0 ;
V_79 -> V_74 -> V_79 = NULL ;
V_79 -> V_74 = NULL ;
F_74 ( & V_79 -> V_131 ) ;
F_115 ( & V_79 -> V_132 , & V_8 -> V_54 . V_133 ) ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_124 * V_79 ,
struct V_75 * V_105 )
{
struct V_66 * V_8 = V_2 -> V_8 ;
int V_11 ;
V_11 = F_31 ( V_2 , V_105 -> V_56 << V_12 ,
V_79 -> V_128 , V_127 ) ;
if ( V_11 )
return V_11 ;
V_79 -> V_74 = V_105 ;
V_105 -> V_79 = V_79 ;
F_115 ( & V_79 -> V_132 , & V_8 -> V_54 . V_134 ) ;
F_112 ( V_2 -> V_95 , L_28 , V_105 -> V_79 -> V_95 ,
V_105 , F_99 ( V_105 ) -> V_110 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_75 * V_105 )
{
int V_11 ;
V_11 = F_102 ( V_2 , V_105 ) ;
if ( V_11 )
return V_11 ;
F_112 ( V_2 -> V_95 , L_29 , V_105 -> V_79 -> V_95 ,
V_105 , F_99 ( V_105 ) -> V_110 ) ;
F_74 ( & V_105 -> V_79 -> V_131 ) ;
return F_111 ( V_2 , V_105 -> V_79 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_75 * V_105 )
{
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_135 * V_54 = & V_8 -> V_54 ;
struct V_124 * V_79 = V_105 -> V_79 ;
int V_11 ;
F_5 ( V_79 , L_30 ) ;
if ( F_119 ( & V_54 -> V_133 ) ) {
V_79 = F_120 ( V_54 -> V_134 . V_136 ,
struct V_124 , V_132 ) ;
V_11 = F_117 ( V_2 , V_79 -> V_74 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_55 ( V_2 , V_79 ) ;
if ( V_11 )
return V_11 ;
} else
V_79 = F_120 ( V_54 -> V_133 . V_136 ,
struct V_124 , V_132 ) ;
return F_116 ( V_2 , V_79 , V_105 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_75 * V_105 )
{
struct V_124 * V_79 = V_105 -> V_79 ;
if ( F_5 ( ! V_79 , L_31 ) )
return - V_35 ;
F_112 ( V_2 -> V_95 , L_32 , V_105 -> V_79 -> V_95 ,
V_105 , F_99 ( V_105 ) -> V_110 ) ;
F_122 ( & V_79 -> V_131 , & V_2 -> V_54 . V_137 ) ;
return F_56 ( V_2 , V_105 ) ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_138 * V_139 , * V_98 ;
struct V_124 * V_79 ;
int V_11 ;
if ( ! V_140 )
return 0 ;
F_124 (pos, n, &vgpu->gtt.oos_page_list_head) {
V_79 = F_120 ( V_139 ,
struct V_124 , V_131 ) ;
V_11 = F_117 ( V_2 , V_79 -> V_74 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_125 (
struct V_75 * V_105 ,
struct V_27 * V_120 , unsigned long V_19 )
{
struct V_71 * V_72 = F_99 ( V_105 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
int type = V_72 -> V_94 . type ;
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
struct V_27 V_122 ;
int V_11 ;
int V_141 ;
V_141 = V_53 -> V_58 ( V_120 ) ;
F_107 ( V_72 , & V_122 , V_19 ) ;
if ( V_141 ) {
V_11 = F_110 ( V_105 , V_120 , V_19 ) ;
if ( V_11 )
goto V_119;
}
V_11 = F_108 ( V_105 , & V_122 , V_19 ) ;
if ( V_11 )
goto V_119;
if ( ! V_141 ) {
V_53 -> V_62 ( & V_122 , V_2 -> V_54 . V_116 [ type ] . V_117 ) ;
F_106 ( V_72 , & V_122 , V_19 ) ;
}
return 0 ;
V_119:
F_3 ( L_33 ,
V_72 , V_120 -> V_37 , V_120 -> type ) ;
return V_11 ;
}
static inline bool F_126 ( struct V_75 * V_105 )
{
return V_140
&& F_96 (
F_99 ( V_105 ) -> V_110 )
&& V_105 -> V_80 >= 2 ;
}
static void F_127 ( struct V_71 * V_72 ,
unsigned long V_19 )
{
F_128 ( V_19 , V_72 -> V_130 ) ;
if ( ! F_119 ( & V_72 -> V_96 ) )
return;
F_122 ( & V_72 -> V_96 ,
& V_72 -> V_2 -> V_54 . V_142 ) ;
}
int F_129 ( struct V_1 * V_2 )
{
struct V_138 * V_139 , * V_98 ;
struct V_71 * V_72 ;
struct V_27 V_123 ;
unsigned long V_19 ;
int V_11 ;
F_124 (pos, n, &vgpu->gtt.post_shadow_list_head) {
V_72 = F_120 ( V_139 , struct V_71 ,
V_96 ) ;
F_130 (index, spt->post_shadow_bitmap,
GTT_ENTRY_NUM_IN_ONE_PAGE) {
F_131 ( V_72 , & V_123 , V_19 ) ;
V_11 = F_125 (
& V_72 -> V_74 , & V_123 , V_19 ) ;
if ( V_11 )
return V_11 ;
F_132 ( V_19 , V_72 -> V_130 ) ;
}
F_74 ( & V_72 -> V_96 ) ;
}
return 0 ;
}
static int F_79 ( void * V_101 ,
T_1 V_102 , void * V_103 , int V_104 )
{
struct V_75 * V_105 = (struct V_75 * ) V_101 ;
struct V_71 * V_72 = F_99 ( V_105 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
const struct V_31 * V_32 = & V_2 -> V_8 -> V_33 ;
struct V_27 V_120 , V_122 ;
unsigned long V_19 ;
int V_11 ;
V_19 = ( V_102 & ( V_143 - 1 ) ) >> V_32 -> V_36 ;
F_131 ( V_72 , & V_120 , V_19 ) ;
V_53 -> V_69 ( & V_120 ) ;
if ( V_104 == V_32 -> V_34 ) {
V_11 = F_125 ( V_105 , & V_120 , V_19 ) ;
if ( V_11 )
return V_11 ;
} else {
if ( ! F_133 ( V_19 , V_72 -> V_130 ) ) {
F_107 ( V_72 , & V_122 , V_19 ) ;
V_11 = F_108 ( V_105 , & V_122 , V_19 ) ;
if ( V_11 )
return V_11 ;
}
F_127 ( V_72 , V_19 ) ;
}
if ( ! V_140 )
return 0 ;
V_105 -> V_80 ++ ;
if ( V_105 -> V_79 )
V_53 -> V_70 ( V_105 -> V_79 -> V_128 , & V_120 , V_19 ,
false , 0 , V_2 ) ;
if ( F_126 ( V_105 ) ) {
if ( ! V_105 -> V_79 )
F_118 ( V_2 , V_105 ) ;
V_11 = F_121 ( V_2 , V_105 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_134 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_66 * V_8 = V_2 -> V_8 ;
const struct V_31 * V_32 = & V_8 -> V_33 ;
void * V_128 ;
if ( V_64 -> type == V_144 ) {
V_64 -> V_145 = 4 ;
V_64 -> V_146 = V_64 -> V_145 *
V_32 -> V_34 ;
V_128 = F_67 ( V_64 -> V_147 ?
V_64 -> V_146 * 2
: V_64 -> V_146 , V_107 ) ;
if ( ! V_128 )
return - V_109 ;
V_64 -> V_148 = V_128 ;
if ( ! V_64 -> V_147 )
return 0 ;
V_64 -> V_149 = V_128 + V_64 -> V_146 ;
} else if ( V_64 -> type == V_150 ) {
V_64 -> V_145 =
( F_135 ( V_8 ) >> V_12 ) ;
V_64 -> V_146 = V_64 -> V_145 *
V_32 -> V_34 ;
V_128 = F_136 ( V_64 -> V_146 ) ;
if ( ! V_128 )
return - V_109 ;
V_64 -> V_148 = V_128 ;
}
return 0 ;
}
static void F_137 ( struct V_63 * V_64 )
{
if ( V_64 -> type == V_144 ) {
F_69 ( V_64 -> V_148 ) ;
} else if ( V_64 -> type == V_150 ) {
if ( V_64 -> V_148 )
F_138 ( V_64 -> V_148 ) ;
}
V_64 -> V_148 = V_64 -> V_149 = NULL ;
}
static void F_139 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_135 * V_54 = & V_8 -> V_54 ;
struct V_52 * V_53 = V_54 -> V_55 ;
struct V_27 V_122 ;
int V_100 ;
if ( F_30 ( ! V_64 -> V_147 || ! V_64 -> V_151 ) )
return;
for ( V_100 = 0 ; V_100 < V_64 -> V_145 ; V_100 ++ ) {
F_140 ( V_64 , & V_122 , V_100 ) ;
if ( ! V_53 -> V_58 ( & V_122 ) )
continue;
F_91 (
V_2 , & V_122 ) ;
V_122 . V_37 = 0 ;
F_141 ( V_64 , & V_122 , V_100 ) ;
F_109 ( V_2 -> V_95 , L_34 ,
NULL , V_122 . type , V_122 . V_37 , V_100 ) ;
}
V_64 -> V_151 = false ;
}
void F_142 ( struct V_152 * V_153 )
{
struct V_63 * V_64 = F_120 ( V_153 , F_143 ( * V_64 ) , V_154 ) ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_135 * V_54 = & V_8 -> V_54 ;
if ( ! V_64 -> V_155 )
goto V_156;
F_144 ( & V_64 -> V_132 ) ;
F_144 ( & V_64 -> V_157 ) ;
if ( V_64 -> V_147 )
F_139 ( V_64 ) ;
V_54 -> V_158 ( V_64 ) ;
V_156:
F_69 ( V_64 ) ;
}
static int F_145 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_135 * V_54 = & V_8 -> V_54 ;
struct V_52 * V_53 = V_54 -> V_55 ;
struct V_71 * V_72 ;
struct V_27 V_123 , V_122 ;
int V_100 ;
int V_11 ;
if ( F_30 ( ! V_64 -> V_147 || V_64 -> V_151 ) )
return 0 ;
V_64 -> V_151 = true ;
for ( V_100 = 0 ; V_100 < V_64 -> V_145 ; V_100 ++ ) {
F_146 ( V_64 , & V_123 , V_100 ) ;
if ( ! V_53 -> V_58 ( & V_123 ) )
continue;
F_109 ( V_2 -> V_95 , V_49 , NULL ,
V_123 . type , V_123 . V_37 , V_100 ) ;
V_72 = F_98 ( V_2 , & V_123 ) ;
if ( F_100 ( V_72 ) ) {
F_3 ( L_35 ) ;
V_11 = F_101 ( V_72 ) ;
goto V_119;
}
F_104 ( & V_122 , V_72 , & V_123 ) ;
F_141 ( V_64 , & V_122 , V_100 ) ;
F_109 ( V_2 -> V_95 , L_36 ,
NULL , V_122 . type , V_122 . V_37 , V_100 ) ;
}
return 0 ;
V_119:
F_139 ( V_64 ) ;
return V_11 ;
}
struct V_63 * F_147 ( struct V_1 * V_2 ,
int V_159 , void * V_148 , int V_160 ,
T_2 V_161 )
{
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_135 * V_54 = & V_8 -> V_54 ;
struct V_63 * V_64 ;
int V_11 ;
V_64 = F_67 ( sizeof( * V_64 ) , V_107 ) ;
if ( ! V_64 ) {
V_11 = - V_109 ;
goto V_119;
}
V_64 -> type = V_159 ;
if ( V_160 == 1 )
V_64 -> V_67 = V_162 ;
else if ( V_160 == 3 )
V_64 -> V_67 = V_45 ;
else if ( V_160 == 4 )
V_64 -> V_67 = V_46 ;
else {
F_30 ( 1 ) ;
V_11 = - V_35 ;
goto V_119;
}
V_64 -> V_160 = V_160 ;
V_64 -> V_161 = V_161 ;
V_64 -> V_2 = V_2 ;
V_64 -> V_147 = ! ! ( V_159 == V_144 ) ;
F_148 ( & V_64 -> V_154 ) ;
F_83 ( & V_64 -> V_163 , 0 ) ;
F_84 ( & V_64 -> V_132 ) ;
F_84 ( & V_64 -> V_157 ) ;
F_122 ( & V_64 -> V_132 , & V_2 -> V_54 . V_164 ) ;
V_11 = V_54 -> V_165 ( V_64 ) ;
if ( V_11 ) {
F_3 ( L_37 ) ;
goto V_119;
}
V_64 -> V_155 = true ;
if ( V_148 )
memcpy ( V_64 -> V_148 , V_148 ,
V_64 -> V_146 ) ;
if ( V_64 -> V_147 ) {
V_11 = F_145 ( V_64 ) ;
if ( V_11 )
goto V_119;
F_122 ( & V_64 -> V_157 , & V_8 -> V_54 . V_166 ) ;
}
return V_64 ;
V_119:
F_3 ( L_38 ) ;
if ( V_64 )
F_149 ( V_64 ) ;
return F_82 ( V_11 ) ;
}
void F_150 ( struct V_63 * V_64 )
{
if ( F_30 ( V_64 -> type != V_144 ) )
return;
F_151 ( & V_64 -> V_163 ) ;
}
int F_152 ( struct V_63 * V_64 )
{
int V_11 ;
if ( F_30 ( V_64 -> type != V_144 ) )
return 0 ;
F_90 ( & V_64 -> V_163 ) ;
if ( ! V_64 -> V_151 ) {
V_11 = F_145 ( V_64 ) ;
if ( V_11 )
return V_11 ;
}
F_74 ( & V_64 -> V_157 ) ;
F_122 ( & V_64 -> V_157 , & V_64 -> V_2 -> V_8 -> V_54 . V_166 ) ;
return 0 ;
}
static int F_81 ( struct V_66 * V_8 )
{
struct V_63 * V_64 ;
struct V_138 * V_139 , * V_98 ;
F_124 (pos, n, &gvt->gtt.mm_lru_list_head) {
V_64 = F_120 ( V_139 , struct V_63 , V_157 ) ;
if ( V_64 -> type != V_144 )
continue;
if ( F_88 ( & V_64 -> V_163 ) )
continue;
F_74 ( & V_64 -> V_157 ) ;
F_139 ( V_64 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_153 ( struct V_63 * V_64 ,
struct V_27 * V_28 , unsigned long V_19 , bool V_73 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
struct V_71 * V_114 ;
if ( F_30 ( ! V_64 -> V_147 ) )
return - V_35 ;
V_114 = F_86 ( V_2 , V_53 -> V_59 ( V_28 ) ) ;
if ( ! V_114 )
return - V_61 ;
if ( ! V_73 )
F_107 ( V_114 , V_28 , V_19 ) ;
else
F_131 ( V_114 , V_28 , V_19 ) ;
return 0 ;
}
unsigned long F_154 ( struct V_63 * V_64 , unsigned long V_47 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_52 * V_55 = V_8 -> V_54 . V_55 ;
struct V_167 * V_168 = V_8 -> V_54 . V_168 ;
unsigned long V_30 = V_60 ;
unsigned long V_169 [ 4 ] ;
struct V_27 V_28 ;
int V_100 , V_19 ;
int V_11 ;
if ( V_64 -> type != V_150 && V_64 -> type != V_144 )
return V_60 ;
if ( V_64 -> type == V_150 ) {
if ( ! F_2 ( V_2 , V_47 ) )
goto V_112;
V_11 = F_155 ( V_64 , & V_28 ,
V_168 -> F_39 ( V_47 ) ) ;
if ( V_11 )
goto V_112;
V_30 = ( V_55 -> V_59 ( & V_28 ) << V_12 )
+ ( V_47 & ~ V_170 ) ;
F_156 ( V_2 -> V_95 , L_39 , 0 , 0 , V_47 , V_30 ) ;
return V_30 ;
}
switch ( V_64 -> V_160 ) {
case 4 :
V_11 = F_140 ( V_64 , & V_28 , 0 ) ;
if ( V_11 )
goto V_112;
V_169 [ 0 ] = V_168 -> V_171 ( V_47 ) ;
V_169 [ 1 ] = V_168 -> V_172 ( V_47 ) ;
V_169 [ 2 ] = V_168 -> V_173 ( V_47 ) ;
V_169 [ 3 ] = V_168 -> V_174 ( V_47 ) ;
V_19 = 4 ;
break;
case 3 :
V_11 = F_140 ( V_64 , & V_28 ,
V_168 -> V_175 ( V_47 ) ) ;
if ( V_11 )
goto V_112;
V_169 [ 0 ] = V_168 -> V_173 ( V_47 ) ;
V_169 [ 1 ] = V_168 -> V_174 ( V_47 ) ;
V_19 = 2 ;
break;
case 2 :
V_11 = F_140 ( V_64 , & V_28 ,
V_168 -> V_173 ( V_47 ) ) ;
if ( V_11 )
goto V_112;
V_169 [ 0 ] = V_168 -> V_174 ( V_47 ) ;
V_19 = 1 ;
break;
default:
F_30 ( 1 ) ;
goto V_112;
}
for ( V_100 = 0 ; V_100 < V_19 ; V_100 ++ ) {
V_11 = F_153 ( V_64 , & V_28 , V_169 [ V_100 ] ,
( V_100 == V_19 - 1 ) ) ;
if ( V_11 )
goto V_112;
if ( ! V_55 -> V_58 ( & V_28 ) ) {
F_157 ( L_40 , V_47 ) ;
goto V_112;
}
}
V_30 = ( V_55 -> V_59 ( & V_28 ) << V_12 )
+ ( V_47 & ~ V_170 ) ;
F_156 ( V_2 -> V_95 , L_41 , 0 ,
V_64 -> V_160 , V_47 , V_30 ) ;
return V_30 ;
V_112:
F_3 ( L_42 , V_64 -> type , V_47 ) ;
return V_60 ;
}
static int F_158 ( struct V_1 * V_2 ,
unsigned int V_176 , void * V_103 , unsigned int V_104 )
{
struct V_63 * V_177 = V_2 -> V_54 . V_177 ;
const struct V_31 * V_32 = & V_2 -> V_8 -> V_33 ;
unsigned long V_19 = V_176 >> V_32 -> V_36 ;
struct V_27 V_28 ;
if ( V_104 != 4 && V_104 != 8 )
return - V_35 ;
F_155 ( V_177 , & V_28 , V_19 ) ;
memcpy ( V_103 , ( void * ) & V_28 . V_37 + ( V_176 & ( V_32 -> V_34 - 1 ) ) ,
V_104 ) ;
return 0 ;
}
int F_159 ( struct V_1 * V_2 , unsigned int V_176 ,
void * V_103 , unsigned int V_104 )
{
const struct V_31 * V_32 = & V_2 -> V_8 -> V_33 ;
int V_11 ;
if ( V_104 != 4 && V_104 != 8 )
return - V_35 ;
V_176 -= V_32 -> V_178 ;
V_11 = F_158 ( V_2 , V_176 , V_103 , V_104 ) ;
return V_11 ;
}
static int F_160 ( struct V_1 * V_2 , unsigned int V_176 ,
void * V_103 , unsigned int V_104 )
{
struct V_66 * V_8 = V_2 -> V_8 ;
const struct V_31 * V_32 = & V_8 -> V_33 ;
struct V_63 * V_177 = V_2 -> V_54 . V_177 ;
struct V_52 * V_53 = V_8 -> V_54 . V_55 ;
unsigned long V_179 = V_176 >> V_32 -> V_36 ;
unsigned long V_47 ;
struct V_27 V_28 , V_51 ;
int V_11 ;
if ( V_104 != 4 && V_104 != 8 )
return - V_35 ;
V_47 = V_179 << V_12 ;
if ( ! F_2 ( V_2 , V_47 ) )
return 0 ;
F_155 ( V_177 , & V_28 , V_179 ) ;
memcpy ( ( void * ) & V_28 . V_37 + ( V_176 & ( V_32 -> V_34 - 1 ) ) , V_103 ,
V_104 ) ;
if ( V_53 -> V_58 ( & V_28 ) ) {
V_11 = F_41 ( V_2 , & V_28 , & V_51 ) ;
if ( V_11 ) {
F_3 ( L_43 ) ;
V_53 -> V_62 ( & V_51 , V_8 -> V_54 . V_180 ) ;
}
} else {
V_51 = V_28 ;
V_53 -> V_62 ( & V_51 , V_8 -> V_54 . V_180 ) ;
}
F_161 ( V_177 , & V_51 , V_179 ) ;
F_23 ( V_8 -> V_18 ) ;
F_162 ( V_177 , & V_28 , V_179 ) ;
return 0 ;
}
int F_163 ( struct V_1 * V_2 , unsigned int V_176 ,
void * V_103 , unsigned int V_104 )
{
const struct V_31 * V_32 = & V_2 -> V_8 -> V_33 ;
int V_11 ;
if ( V_104 != 4 && V_104 != 8 )
return - V_35 ;
V_176 -= V_32 -> V_178 ;
V_11 = F_160 ( V_2 , V_176 , V_103 , V_104 ) ;
return V_11 ;
}
static int F_164 ( struct V_1 * V_2 ,
T_6 type )
{
struct V_181 * V_54 = & V_2 -> V_54 ;
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
int V_182 = V_127 >>
V_2 -> V_8 -> V_33 . V_36 ;
void * V_116 ;
int V_100 ;
struct V_83 * V_87 = & V_2 -> V_8 -> V_18 -> V_85 . V_86 -> V_87 ;
T_4 V_88 ;
if ( F_30 ( type < V_183 || type >= V_184 ) )
return - V_35 ;
V_116 = ( void * ) F_165 ( V_107 ) ;
if ( ! V_116 ) {
F_3 ( L_44 ) ;
return - V_109 ;
}
V_88 = F_60 ( V_87 , F_166 ( V_116 ) , 0 ,
4096 , V_90 ) ;
if ( F_61 ( V_87 , V_88 ) ) {
F_3 ( L_45 ) ;
F_71 ( F_166 ( V_116 ) ) ;
return - V_109 ;
}
V_54 -> V_116 [ type ] . V_117 =
( unsigned long ) ( V_88 >> V_12 ) ;
V_54 -> V_116 [ type ] . V_89 = F_166 ( V_116 ) ;
F_167 ( L_46 ,
V_2 -> V_95 , type , V_54 -> V_116 [ type ] . V_117 ) ;
if ( type > V_183 && type < V_184 ) {
struct V_27 V_122 ;
memset ( & V_122 , 0 , sizeof( struct V_27 ) ) ;
V_122 . type = F_19 ( type - 1 ) ;
V_53 -> V_62 ( & V_122 , V_54 -> V_116 [ type - 1 ] . V_117 ) ;
V_122 . V_37 |= V_185 | V_186 ;
if ( type == V_187 )
V_122 . V_37 |= V_188 ;
for ( V_100 = 0 ; V_100 < V_182 ; V_100 ++ )
V_53 -> V_70 ( V_116 , & V_122 , V_100 , false , 0 , V_2 ) ;
}
return 0 ;
}
static int F_168 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_83 * V_87 = & V_2 -> V_8 -> V_18 -> V_85 . V_86 -> V_87 ;
T_4 V_88 ;
for ( V_100 = V_183 ; V_100 < V_184 ; V_100 ++ ) {
if ( V_2 -> V_54 . V_116 [ V_100 ] . V_89 != NULL ) {
V_88 = ( T_4 ) ( V_2 -> V_54 . V_116 [ V_100 ] . V_117 <<
V_12 ) ;
F_64 ( V_87 , V_88 , 4096 , V_90 ) ;
F_71 ( V_2 -> V_54 . V_116 [ V_100 ] . V_89 ) ;
V_2 -> V_54 . V_116 [ V_100 ] . V_89 = NULL ;
V_2 -> V_54 . V_116 [ V_100 ] . V_117 = 0 ;
}
}
return 0 ;
}
static int F_169 ( struct V_1 * V_2 )
{
int V_100 , V_11 ;
for ( V_100 = V_183 ; V_100 < V_184 ; V_100 ++ ) {
V_11 = F_164 ( V_2 , V_100 ) ;
if ( V_11 )
goto V_112;
}
return 0 ;
V_112:
F_168 ( V_2 ) ;
return V_11 ;
}
int F_170 ( struct V_1 * V_2 )
{
struct V_181 * V_54 = & V_2 -> V_54 ;
struct V_63 * V_177 ;
F_171 ( V_54 -> V_81 ) ;
F_171 ( V_54 -> V_92 ) ;
F_84 ( & V_54 -> V_164 ) ;
F_84 ( & V_54 -> V_137 ) ;
F_84 ( & V_54 -> V_142 ) ;
F_172 ( V_2 ) ;
V_177 = F_147 ( V_2 , V_150 ,
NULL , 1 , 0 ) ;
if ( F_100 ( V_177 ) ) {
F_3 ( L_47 ) ;
return F_101 ( V_177 ) ;
}
V_54 -> V_177 = V_177 ;
return F_169 ( V_2 ) ;
}
static void F_173 ( struct V_1 * V_2 , int type )
{
struct V_138 * V_139 , * V_98 ;
struct V_63 * V_64 ;
F_124 (pos, n, &vgpu->gtt.mm_list_head) {
V_64 = F_120 ( V_139 , struct V_63 , V_132 ) ;
if ( V_64 -> type == type ) {
V_2 -> V_8 -> V_54 . V_158 ( V_64 ) ;
F_144 ( & V_64 -> V_132 ) ;
F_144 ( & V_64 -> V_157 ) ;
F_69 ( V_64 ) ;
}
}
}
void F_174 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
F_168 ( V_2 ) ;
F_173 ( V_2 , V_144 ) ;
F_173 ( V_2 , V_150 ) ;
}
static void F_175 ( struct V_66 * V_8 )
{
struct V_135 * V_54 = & V_8 -> V_54 ;
struct V_138 * V_139 , * V_98 ;
struct V_124 * V_79 ;
F_5 ( ! F_119 ( & V_54 -> V_134 ) ,
L_48 ) ;
F_124 (pos, n, &gtt->oos_page_free_list_head) {
V_79 = F_120 ( V_139 , struct V_124 , V_132 ) ;
F_144 ( & V_79 -> V_132 ) ;
F_69 ( V_79 ) ;
}
}
static int F_176 ( struct V_66 * V_8 )
{
struct V_135 * V_54 = & V_8 -> V_54 ;
struct V_124 * V_79 ;
int V_100 ;
int V_11 ;
F_84 ( & V_54 -> V_133 ) ;
F_84 ( & V_54 -> V_134 ) ;
for ( V_100 = 0 ; V_100 < V_189 ; V_100 ++ ) {
V_79 = F_67 ( sizeof( * V_79 ) , V_107 ) ;
if ( ! V_79 ) {
V_11 = - V_109 ;
goto V_119;
}
F_84 ( & V_79 -> V_132 ) ;
F_84 ( & V_79 -> V_131 ) ;
V_79 -> V_95 = V_100 ;
F_122 ( & V_79 -> V_132 , & V_54 -> V_133 ) ;
}
F_167 ( L_49 , V_100 ) ;
return 0 ;
V_119:
F_175 ( V_8 ) ;
return V_11 ;
}
struct V_63 * F_177 ( struct V_1 * V_2 ,
int V_160 , void * V_190 )
{
struct V_138 * V_139 ;
struct V_63 * V_64 ;
T_1 * V_191 , * V_192 ;
F_178 (pos, &vgpu->gtt.mm_list_head) {
V_64 = F_120 ( V_139 , struct V_63 , V_132 ) ;
if ( V_64 -> type != V_144 )
continue;
if ( V_64 -> V_160 != V_160 )
continue;
V_191 = V_190 ;
V_192 = V_64 -> V_148 ;
if ( V_160 == 3 ) {
if ( V_191 [ 0 ] == V_192 [ 0 ]
&& V_191 [ 1 ] == V_192 [ 1 ]
&& V_191 [ 2 ] == V_192 [ 2 ]
&& V_191 [ 3 ] == V_192 [ 3 ] )
return V_64 ;
} else {
if ( V_191 [ 0 ] == V_192 [ 0 ] )
return V_64 ;
}
}
return NULL ;
}
int F_179 ( struct V_1 * V_2 ,
int V_160 )
{
T_1 * V_193 = ( T_1 * ) & F_180 ( V_2 , F_181 ( V_193 [ 0 ] ) ) ;
struct V_63 * V_64 ;
if ( F_30 ( ( V_160 != 4 ) && ( V_160 != 3 ) ) )
return - V_35 ;
V_64 = F_177 ( V_2 , V_160 , V_193 ) ;
if ( V_64 ) {
F_182 ( V_64 ) ;
} else {
V_64 = F_147 ( V_2 , V_144 ,
V_193 , V_160 , 0 ) ;
if ( F_100 ( V_64 ) ) {
F_3 ( L_38 ) ;
return F_101 ( V_64 ) ;
}
}
return 0 ;
}
int F_183 ( struct V_1 * V_2 ,
int V_160 )
{
T_1 * V_193 = ( T_1 * ) & F_180 ( V_2 , F_181 ( V_193 [ 0 ] ) ) ;
struct V_63 * V_64 ;
if ( F_30 ( ( V_160 != 4 ) && ( V_160 != 3 ) ) )
return - V_35 ;
V_64 = F_177 ( V_2 , V_160 , V_193 ) ;
if ( ! V_64 ) {
F_3 ( L_50 ) ;
return - V_35 ;
}
F_149 ( V_64 ) ;
return 0 ;
}
int F_184 ( struct V_66 * V_8 )
{
int V_11 ;
void * V_89 ;
struct V_83 * V_87 = & V_8 -> V_18 -> V_85 . V_86 -> V_87 ;
T_4 V_88 ;
F_157 ( L_51 ) ;
if ( F_185 ( V_8 -> V_18 ) || F_186 ( V_8 -> V_18 )
|| F_187 ( V_8 -> V_18 ) ) {
V_8 -> V_54 . V_55 = & V_194 ;
V_8 -> V_54 . V_168 = & V_195 ;
V_8 -> V_54 . V_165 = F_134 ;
V_8 -> V_54 . V_158 = F_137 ;
} else {
return - V_196 ;
}
V_89 = ( void * ) F_165 ( V_107 ) ;
if ( ! V_89 ) {
F_188 ( L_52 ) ;
return - V_109 ;
}
V_88 = F_60 ( V_87 , F_166 ( V_89 ) , 0 ,
4096 , V_90 ) ;
if ( F_61 ( V_87 , V_88 ) ) {
F_188 ( L_53 ) ;
F_71 ( F_166 ( V_89 ) ) ;
return - V_109 ;
}
V_8 -> V_54 . V_197 = F_166 ( V_89 ) ;
V_8 -> V_54 . V_180 = ( unsigned long ) ( V_88 >> V_12 ) ;
if ( V_140 ) {
V_11 = F_176 ( V_8 ) ;
if ( V_11 ) {
F_188 ( L_54 ) ;
F_64 ( V_87 , V_88 , 4096 , V_90 ) ;
F_71 ( V_8 -> V_54 . V_197 ) ;
return V_11 ;
}
}
F_84 ( & V_8 -> V_54 . V_166 ) ;
return 0 ;
}
void F_189 ( struct V_66 * V_8 )
{
struct V_83 * V_87 = & V_8 -> V_18 -> V_85 . V_86 -> V_87 ;
T_4 V_88 = ( T_4 ) ( V_8 -> V_54 . V_180 <<
V_12 ) ;
F_64 ( V_87 , V_88 , 4096 , V_90 ) ;
F_71 ( V_8 -> V_54 . V_197 ) ;
if ( V_140 )
F_175 ( V_8 ) ;
}
void F_172 ( struct V_1 * V_2 )
{
struct V_66 * V_8 = V_2 -> V_8 ;
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_52 * V_53 = V_2 -> V_8 -> V_54 . V_55 ;
T_2 V_19 ;
T_2 V_198 ;
T_2 V_199 ;
struct V_27 V_28 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . type = V_162 ;
V_53 -> V_62 ( & V_28 , V_8 -> V_54 . V_180 ) ;
V_28 . V_37 |= V_185 ;
V_19 = F_7 ( V_2 ) >> V_129 ;
V_199 = F_190 ( V_2 ) >> V_129 ;
for ( V_198 = 0 ; V_198 < V_199 ; V_198 ++ )
V_53 -> V_70 ( NULL , & V_28 , V_19 + V_198 , false , 0 , V_2 ) ;
V_19 = F_9 ( V_2 ) >> V_129 ;
V_199 = F_191 ( V_2 ) >> V_129 ;
for ( V_198 = 0 ; V_198 < V_199 ; V_198 ++ )
V_53 -> V_70 ( NULL , & V_28 , V_19 + V_198 , false , 0 , V_2 ) ;
F_23 ( V_18 ) ;
}
void F_192 ( struct V_1 * V_2 )
{
int V_100 ;
F_75 ( V_2 ) ;
F_173 ( V_2 , V_144 ) ;
F_172 ( V_2 ) ;
for ( V_100 = V_183 ; V_100 < V_184 ; V_100 ++ ) {
if ( V_2 -> V_54 . V_116 [ V_100 ] . V_89 != NULL )
memset ( F_62 ( V_2 -> V_54 . V_116 [ V_100 ] . V_89 ) ,
0 , V_143 ) ;
}
}
