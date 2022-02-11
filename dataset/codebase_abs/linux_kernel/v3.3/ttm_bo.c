static inline int F_1 ( T_1 V_1 , T_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 <= V_4 ; V_3 ++ )
if ( V_1 & ( 1 << V_3 ) ) {
* V_2 = V_3 ;
return 0 ;
}
return - V_5 ;
}
static void F_2 ( struct V_6 * V_7 , int V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
F_3 (KERN_ERR TTM_PFX L_1 , man->has_type) ;
F_3 (KERN_ERR TTM_PFX L_2 , man->use_type) ;
F_3 (KERN_ERR TTM_PFX L_3 , man->flags) ;
F_3 (KERN_ERR TTM_PFX L_4 , man->gpu_offset) ;
F_3 (KERN_ERR TTM_PFX L_5 , man->size) ;
F_3 (KERN_ERR TTM_PFX L_6 ,
man->available_caching) ;
F_3 (KERN_ERR TTM_PFX L_7 ,
man->default_caching) ;
if ( V_2 != V_10 )
(* V_9 -> V_11 -> V_12 )( V_9 , V_13 ) ;
}
static void F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_3 , V_18 , V_2 ;
F_3 (KERN_ERR TTM_PFX L_8 ,
bo, bo->mem.num_pages, bo->mem.size >> 10 ,
bo->mem.size >> 20 ) ;
for ( V_3 = 0 ; V_3 < V_17 -> V_19 ; V_3 ++ ) {
V_18 = F_1 ( V_17 -> V_17 [ V_3 ] ,
& V_2 ) ;
if ( V_18 )
return;
F_3 (KERN_ERR TTM_PFX L_9 ,
i, placement->placement[i], mem_type) ;
F_2 ( V_15 -> V_7 , V_2 ) ;
}
}
static T_2 F_5 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 =
F_6 ( V_21 , struct V_25 , V_21 ) ;
return snprintf ( V_24 , V_27 , L_10 ,
( unsigned long ) F_7 ( & V_26 -> V_28 ) ) ;
}
static inline T_1 F_8 ( unsigned type )
{
return 1 << ( type ) ;
}
static void F_9 ( struct V_29 * V_30 )
{
struct V_14 * V_15 =
F_6 ( V_30 , struct V_14 , V_30 ) ;
struct V_6 * V_7 = V_15 -> V_7 ;
T_3 V_31 = V_15 -> V_31 ;
F_10 ( F_7 ( & V_15 -> V_30 . V_32 ) ) ;
F_10 ( F_7 ( & V_15 -> V_29 . V_32 ) ) ;
F_10 ( F_7 ( & V_15 -> V_33 ) ) ;
F_10 ( V_15 -> V_34 != NULL ) ;
F_10 ( V_15 -> V_35 . V_36 != NULL ) ;
F_10 ( ! F_11 ( & V_15 -> V_37 ) ) ;
F_10 ( ! F_11 ( & V_15 -> V_38 ) ) ;
if ( V_15 -> V_39 )
F_12 ( V_15 -> V_39 ) ;
F_13 ( & V_15 -> V_26 -> V_28 ) ;
if ( V_15 -> V_40 )
V_15 -> V_40 ( V_15 ) ;
else {
F_14 ( V_15 ) ;
}
F_15 ( V_7 -> V_26 -> V_41 , V_31 ) ;
}
int F_16 ( struct V_14 * V_15 , bool V_42 )
{
if ( V_42 ) {
return F_17 ( V_15 -> V_43 ,
F_7 ( & V_15 -> V_44 ) == 0 ) ;
} else {
F_18 ( V_15 -> V_43 , F_7 ( & V_15 -> V_44 ) == 0 ) ;
return 0 ;
}
}
void F_19 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 ;
F_10 ( ! F_7 ( & V_15 -> V_44 ) ) ;
if ( ! ( V_15 -> V_35 . V_17 & V_45 ) ) {
F_10 ( ! F_11 ( & V_15 -> V_37 ) ) ;
V_9 = & V_7 -> V_9 [ V_15 -> V_35 . V_2 ] ;
F_20 ( & V_15 -> V_37 , & V_9 -> V_37 ) ;
F_21 ( & V_15 -> V_30 ) ;
if ( V_15 -> V_39 != NULL ) {
F_20 ( & V_15 -> V_46 , & V_15 -> V_26 -> V_47 ) ;
F_21 ( & V_15 -> V_30 ) ;
}
}
}
int F_22 ( struct V_14 * V_15 )
{
int V_48 = 0 ;
if ( ! F_11 ( & V_15 -> V_46 ) ) {
F_23 ( & V_15 -> V_46 ) ;
++ V_48 ;
}
if ( ! F_11 ( & V_15 -> V_37 ) ) {
F_23 ( & V_15 -> V_37 ) ;
++ V_48 ;
}
return V_48 ;
}
int F_24 ( struct V_14 * V_15 ,
bool V_42 ,
bool V_49 , bool V_50 , T_1 V_51 )
{
struct V_25 * V_26 = V_15 -> V_26 ;
int V_18 ;
while ( F_25 ( F_26 ( & V_15 -> V_44 , 0 , 1 ) != 0 ) ) {
if ( V_50 && V_15 -> V_52 ) {
if ( F_25 ( V_51 == V_15 -> V_53 ) )
return - V_54 ;
if ( F_25 ( V_51 - V_15 -> V_53 < ( 1 << 31 ) ) )
return - V_55 ;
}
if ( V_49 )
return - V_56 ;
F_27 ( & V_26 -> V_57 ) ;
V_18 = F_16 ( V_15 , V_42 ) ;
F_28 ( & V_26 -> V_57 ) ;
if ( F_25 ( V_18 ) )
return V_18 ;
}
if ( V_50 ) {
if ( F_25 ( ( V_15 -> V_53 - V_51 < ( 1 << 31 ) )
|| ! V_15 -> V_52 ) )
F_29 ( & V_15 -> V_43 ) ;
V_15 -> V_53 = V_51 ;
V_15 -> V_52 = true ;
} else {
V_15 -> V_52 = false ;
}
return 0 ;
}
static void F_30 ( struct V_29 * V_30 )
{
F_31 () ;
}
void F_32 ( struct V_14 * V_15 , int V_58 ,
bool V_59 )
{
F_33 ( & V_15 -> V_30 , V_58 ,
( V_59 ) ? F_30 : F_9 ) ;
}
int F_34 ( struct V_14 * V_15 ,
bool V_42 ,
bool V_49 , bool V_50 , T_1 V_51 )
{
struct V_25 * V_26 = V_15 -> V_26 ;
int V_48 = 0 ;
int V_18 ;
F_28 ( & V_26 -> V_57 ) ;
V_18 = F_24 ( V_15 , V_42 , V_49 , V_50 ,
V_51 ) ;
if ( F_35 ( V_18 == 0 ) )
V_48 = F_22 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_32 ( V_15 , V_48 , true ) ;
return V_18 ;
}
void F_36 ( struct V_14 * V_15 )
{
F_19 ( V_15 ) ;
F_37 ( & V_15 -> V_44 , 0 ) ;
F_29 ( & V_15 -> V_43 ) ;
}
void F_38 ( struct V_14 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_26 ;
F_28 ( & V_26 -> V_57 ) ;
F_36 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
}
static int F_39 ( struct V_14 * V_15 , bool V_60 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_25 * V_26 = V_15 -> V_26 ;
int V_18 = 0 ;
T_1 V_61 = 0 ;
F_40 ( & V_15 -> V_62 ) ;
V_15 -> V_39 = NULL ;
if ( V_7 -> V_63 )
V_61 |= V_64 ;
switch ( V_15 -> type ) {
case V_65 :
if ( V_60 )
V_61 |= V_66 ;
case V_67 :
V_15 -> V_39 = V_7 -> V_68 -> V_69 ( V_7 , V_15 -> V_70 << V_71 ,
V_61 , V_26 -> V_72 ) ;
if ( F_25 ( V_15 -> V_39 == NULL ) )
V_18 = - V_73 ;
break;
default:
F_3 (KERN_ERR TTM_PFX L_11 ) ;
V_18 = - V_5 ;
break;
}
return V_18 ;
}
static int F_41 ( struct V_14 * V_15 ,
struct V_74 * V_35 ,
bool V_75 , bool V_42 ,
bool V_76 , bool V_77 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
bool V_78 = F_42 ( V_7 , & V_15 -> V_35 ) ;
bool V_79 = F_42 ( V_7 , V_35 ) ;
struct V_8 * V_80 = & V_7 -> V_9 [ V_15 -> V_35 . V_2 ] ;
struct V_8 * V_81 = & V_7 -> V_9 [ V_35 -> V_2 ] ;
int V_18 = 0 ;
if ( V_78 || V_79 ||
( ( V_35 -> V_17 & V_15 -> V_35 . V_17 & V_82 ) == 0 ) ) {
V_18 = F_43 ( V_80 , true ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_83;
F_44 ( V_15 ) ;
F_45 ( V_80 ) ;
}
if ( ! ( V_81 -> V_1 & V_84 ) ) {
if ( V_15 -> V_39 == NULL ) {
bool V_85 = ! ( V_80 -> V_1 & V_84 ) ;
V_18 = F_39 ( V_15 , V_85 ) ;
if ( V_18 )
goto V_83;
}
V_18 = F_46 ( V_15 -> V_39 , V_35 -> V_17 ) ;
if ( V_18 )
goto V_83;
if ( V_35 -> V_2 != V_10 ) {
V_18 = F_47 ( V_15 -> V_39 , V_35 ) ;
if ( V_18 )
goto V_83;
}
if ( V_15 -> V_35 . V_2 == V_10 ) {
if ( V_7 -> V_68 -> V_86 )
V_7 -> V_68 -> V_86 ( V_15 , V_35 ) ;
V_15 -> V_35 = * V_35 ;
V_35 -> V_36 = NULL ;
goto V_87;
}
}
if ( V_7 -> V_68 -> V_86 )
V_7 -> V_68 -> V_86 ( V_15 , V_35 ) ;
if ( ! ( V_80 -> V_1 & V_84 ) &&
! ( V_81 -> V_1 & V_84 ) )
V_18 = F_48 ( V_15 , V_75 , V_76 , V_77 , V_35 ) ;
else if ( V_7 -> V_68 -> V_88 )
V_18 = V_7 -> V_68 -> V_88 ( V_15 , V_75 , V_42 ,
V_76 , V_77 , V_35 ) ;
else
V_18 = F_49 ( V_15 , V_75 , V_76 , V_77 , V_35 ) ;
if ( V_18 ) {
if ( V_7 -> V_68 -> V_86 ) {
struct V_74 V_89 = * V_35 ;
* V_35 = V_15 -> V_35 ;
V_15 -> V_35 = V_89 ;
V_7 -> V_68 -> V_86 ( V_15 , V_35 ) ;
V_15 -> V_35 = * V_35 ;
}
goto V_83;
}
V_87:
if ( V_15 -> V_90 ) {
V_18 = V_7 -> V_68 -> V_91 ( V_7 , V_15 -> V_35 . V_17 ) ;
if ( V_18 )
F_3 (KERN_ERR TTM_PFX L_12 ) ;
V_15 -> V_90 = false ;
}
if ( V_15 -> V_35 . V_36 ) {
V_15 -> V_92 = ( V_15 -> V_35 . V_93 << V_71 ) +
V_7 -> V_9 [ V_15 -> V_35 . V_2 ] . V_94 ;
V_15 -> V_95 = V_15 -> V_35 . V_17 ;
} else
V_15 -> V_92 = 0 ;
return 0 ;
V_83:
V_81 = & V_7 -> V_9 [ V_15 -> V_35 . V_2 ] ;
if ( ( V_81 -> V_1 & V_84 ) && V_15 -> V_39 ) {
F_50 ( V_15 -> V_39 ) ;
F_12 ( V_15 -> V_39 ) ;
V_15 -> V_39 = NULL ;
}
return V_18 ;
}
static void F_51 ( struct V_14 * V_15 )
{
if ( V_15 -> V_7 -> V_68 -> V_86 )
V_15 -> V_7 -> V_68 -> V_86 ( V_15 , NULL ) ;
if ( V_15 -> V_39 ) {
F_50 ( V_15 -> V_39 ) ;
F_12 ( V_15 -> V_39 ) ;
V_15 -> V_39 = NULL ;
}
F_52 ( V_15 , & V_15 -> V_35 ) ;
F_37 ( & V_15 -> V_44 , 0 ) ;
F_53 () ;
F_29 ( & V_15 -> V_43 ) ;
}
static void F_54 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_25 * V_26 = V_15 -> V_26 ;
struct V_96 * V_68 ;
void * V_34 = NULL ;
void * V_97 ;
int V_48 ;
int V_18 ;
F_28 ( & V_7 -> V_98 ) ;
( void ) F_55 ( V_15 , false , false , true ) ;
if ( ! V_15 -> V_34 ) {
F_28 ( & V_26 -> V_57 ) ;
V_18 = F_24 ( V_15 , false , true , false , 0 ) ;
if ( F_25 ( V_18 == - V_56 ) )
goto V_99;
F_27 ( & V_7 -> V_98 ) ;
V_48 = F_22 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_51 ( V_15 ) ;
F_32 ( V_15 , V_48 , true ) ;
return;
} else {
F_28 ( & V_26 -> V_57 ) ;
}
V_99:
V_68 = V_7 -> V_68 ;
if ( V_15 -> V_34 )
V_34 = V_68 -> V_100 ( V_15 -> V_34 ) ;
V_97 = V_15 -> V_97 ;
F_21 ( & V_15 -> V_30 ) ;
F_20 ( & V_15 -> V_38 , & V_7 -> V_38 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_27 ( & V_7 -> V_98 ) ;
if ( V_34 ) {
V_68 -> V_101 ( V_34 , V_97 ) ;
V_68 -> V_102 ( & V_34 ) ;
}
F_56 ( & V_7 -> V_103 ,
( ( V_104 / 100 ) < 1 ) ? 1 : V_104 / 100 ) ;
}
static int F_57 ( struct V_14 * V_15 ,
bool V_42 ,
bool V_76 ,
bool V_77 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_25 * V_26 = V_15 -> V_26 ;
int V_48 ;
int V_18 = 0 ;
V_105:
F_28 ( & V_7 -> V_98 ) ;
V_18 = F_55 ( V_15 , false , V_42 , V_77 ) ;
F_27 ( & V_7 -> V_98 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
F_28 ( & V_26 -> V_57 ) ;
if ( F_25 ( F_11 ( & V_15 -> V_38 ) ) ) {
F_27 ( & V_26 -> V_57 ) ;
return 0 ;
}
V_18 = F_24 ( V_15 , V_42 ,
V_76 , false , 0 ) ;
if ( F_25 ( V_18 != 0 ) ) {
F_27 ( & V_26 -> V_57 ) ;
return V_18 ;
}
if ( F_25 ( V_15 -> V_34 ) ) {
F_37 ( & V_15 -> V_44 , 0 ) ;
F_29 ( & V_15 -> V_43 ) ;
F_27 ( & V_26 -> V_57 ) ;
goto V_105;
}
V_48 = F_22 ( V_15 ) ;
F_23 ( & V_15 -> V_38 ) ;
++ V_48 ;
F_27 ( & V_26 -> V_57 ) ;
F_51 ( V_15 ) ;
F_32 ( V_15 , V_48 , true ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 , bool V_106 )
{
struct V_25 * V_26 = V_7 -> V_26 ;
struct V_14 * V_107 = NULL ;
int V_18 = 0 ;
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_7 -> V_38 ) )
goto V_108;
V_107 = F_59 ( & V_7 -> V_38 ,
struct V_14 , V_38 ) ;
F_21 ( & V_107 -> V_30 ) ;
for (; ; ) {
struct V_14 * V_109 = NULL ;
if ( V_107 -> V_38 . V_110 != & V_7 -> V_38 ) {
V_109 = F_59 ( & V_107 -> V_38 ,
struct V_14 , V_38 ) ;
F_21 ( & V_109 -> V_30 ) ;
}
F_27 ( & V_26 -> V_57 ) ;
V_18 = F_57 ( V_107 , false , ! V_106 ,
! V_106 ) ;
F_60 ( & V_107 -> V_30 , F_9 ) ;
V_107 = V_109 ;
if ( V_18 || ! V_107 )
goto V_111;
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_107 -> V_38 ) )
break;
}
V_108:
F_27 ( & V_26 -> V_57 ) ;
V_111:
if ( V_107 )
F_60 ( & V_107 -> V_30 , F_9 ) ;
return V_18 ;
}
static void F_61 ( struct V_112 * V_113 )
{
struct V_6 * V_7 =
F_6 ( V_113 , struct V_6 , V_103 . V_113 ) ;
if ( F_58 ( V_7 , false ) ) {
F_56 ( & V_7 -> V_103 ,
( ( V_104 / 100 ) < 1 ) ? 1 : V_104 / 100 ) ;
}
}
static void F_62 ( struct V_29 * V_29 )
{
struct V_14 * V_15 =
F_6 ( V_29 , struct V_14 , V_29 ) ;
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_15 -> V_35 . V_2 ] ;
if ( F_35 ( V_15 -> V_114 != NULL ) ) {
F_63 ( & V_15 -> V_115 , & V_7 -> V_116 ) ;
F_64 ( V_15 -> V_114 ) ;
V_15 -> V_114 = NULL ;
}
F_65 ( & V_7 -> V_117 ) ;
F_43 ( V_9 , false ) ;
F_66 ( V_15 ) ;
F_45 ( V_9 ) ;
F_54 ( V_15 ) ;
F_60 ( & V_15 -> V_30 , F_9 ) ;
F_67 ( & V_7 -> V_117 ) ;
}
void F_68 ( struct V_14 * * V_118 )
{
struct V_14 * V_15 = * V_118 ;
struct V_6 * V_7 = V_15 -> V_7 ;
* V_118 = NULL ;
F_67 ( & V_7 -> V_117 ) ;
F_60 ( & V_15 -> V_29 , F_62 ) ;
F_65 ( & V_7 -> V_117 ) ;
}
int F_69 ( struct V_6 * V_7 )
{
return F_70 ( & V_7 -> V_103 ) ;
}
void F_71 ( struct V_6 * V_7 , int V_119 )
{
if ( V_119 )
F_56 ( & V_7 -> V_103 ,
( ( V_104 / 100 ) < 1 ) ? 1 : V_104 / 100 ) ;
}
static int F_72 ( struct V_14 * V_15 , bool V_42 ,
bool V_76 , bool V_77 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_74 V_120 ;
struct V_16 V_17 ;
int V_18 = 0 ;
F_28 ( & V_7 -> V_98 ) ;
V_18 = F_55 ( V_15 , false , V_42 , V_77 ) ;
F_27 ( & V_7 -> V_98 ) ;
if ( F_25 ( V_18 != 0 ) ) {
if ( V_18 != - V_121 ) {
F_3 (KERN_ERR TTM_PFX
L_13
L_14 ) ;
}
goto V_111;
}
F_10 ( ! F_7 ( & V_15 -> V_44 ) ) ;
V_120 = V_15 -> V_35 ;
V_120 . V_36 = NULL ;
V_120 . V_122 . V_123 = false ;
V_120 . V_122 . V_124 = 0 ;
V_17 . V_125 = 0 ;
V_17 . V_126 = 0 ;
V_17 . V_19 = 0 ;
V_17 . V_127 = 0 ;
V_7 -> V_68 -> V_128 ( V_15 , & V_17 ) ;
V_18 = F_73 ( V_15 , & V_17 , & V_120 , V_42 ,
V_76 , V_77 ) ;
if ( V_18 ) {
if ( V_18 != - V_121 ) {
F_3 (KERN_ERR TTM_PFX
L_15
L_16 , bo) ;
F_4 ( V_15 , & V_17 ) ;
}
goto V_111;
}
V_18 = F_41 ( V_15 , & V_120 , true , V_42 ,
V_76 , V_77 ) ;
if ( V_18 ) {
if ( V_18 != - V_121 )
F_3 (KERN_ERR TTM_PFX L_17 ) ;
F_52 ( V_15 , & V_120 ) ;
goto V_111;
}
V_15 -> V_90 = true ;
V_111:
return V_18 ;
}
static int F_74 ( struct V_6 * V_7 ,
T_1 V_2 ,
bool V_42 , bool V_76 ,
bool V_77 )
{
struct V_25 * V_26 = V_7 -> V_26 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_14 * V_15 ;
int V_18 , V_48 = 0 ;
V_105:
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_9 -> V_37 ) ) {
F_27 ( & V_26 -> V_57 ) ;
return - V_56 ;
}
V_15 = F_59 ( & V_9 -> V_37 , struct V_14 , V_37 ) ;
F_21 ( & V_15 -> V_30 ) ;
if ( ! F_11 ( & V_15 -> V_38 ) ) {
F_27 ( & V_26 -> V_57 ) ;
V_18 = F_57 ( V_15 , V_42 ,
V_76 , V_77 ) ;
F_60 ( & V_15 -> V_30 , F_9 ) ;
if ( F_35 ( V_18 == 0 || V_18 == - V_121 ) )
return V_18 ;
goto V_105;
}
V_18 = F_24 ( V_15 , false , V_76 , false , 0 ) ;
if ( F_25 ( V_18 == - V_56 ) ) {
F_27 ( & V_26 -> V_57 ) ;
if ( F_35 ( ! V_77 ) )
V_18 = F_16 ( V_15 , V_42 ) ;
F_60 ( & V_15 -> V_30 , F_9 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
goto V_105;
}
V_48 = F_22 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_10 ( V_18 != 0 ) ;
F_32 ( V_15 , V_48 , true ) ;
V_18 = F_72 ( V_15 , V_42 , V_76 , V_77 ) ;
F_38 ( V_15 ) ;
F_60 ( & V_15 -> V_30 , F_9 ) ;
return V_18 ;
}
void F_52 ( struct V_14 * V_15 , struct V_74 * V_35 )
{
struct V_8 * V_9 = & V_15 -> V_7 -> V_9 [ V_35 -> V_2 ] ;
if ( V_35 -> V_36 )
(* V_9 -> V_11 -> V_129 )( V_9 , V_35 ) ;
}
static int F_75 ( struct V_14 * V_15 ,
T_1 V_2 ,
struct V_16 * V_17 ,
struct V_74 * V_35 ,
bool V_42 ,
bool V_76 ,
bool V_77 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
int V_18 ;
do {
V_18 = (* V_9 -> V_11 -> V_130 )( V_9 , V_15 , V_17 , V_35 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
if ( V_35 -> V_36 )
break;
V_18 = F_74 ( V_7 , V_2 , V_42 ,
V_76 , V_77 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
} while ( 1 );
if ( V_35 -> V_36 == NULL )
return - V_73 ;
V_35 -> V_2 = V_2 ;
return 0 ;
}
static T_1 F_76 ( struct V_8 * V_9 ,
T_1 V_95 ,
T_1 V_131 )
{
T_1 V_132 = V_131 & V_82 ;
T_1 V_133 = V_131 & ~ V_82 ;
if ( ( V_95 & V_132 ) != 0 )
V_133 |= ( V_95 & V_132 ) ;
else if ( ( V_9 -> V_134 & V_132 ) != 0 )
V_133 |= V_9 -> V_134 ;
else if ( ( V_135 & V_132 ) != 0 )
V_133 |= V_135 ;
else if ( ( V_136 & V_132 ) != 0 )
V_133 |= V_136 ;
else if ( ( V_137 & V_132 ) != 0 )
V_133 |= V_137 ;
return V_133 ;
}
static bool F_77 ( struct V_8 * V_9 ,
T_1 V_2 ,
T_1 V_131 ,
T_1 * V_138 )
{
T_1 V_139 = F_8 ( V_2 ) ;
if ( ( V_139 & V_131 & V_140 ) == 0 )
return false ;
if ( ( V_131 & V_9 -> V_141 ) == 0 )
return false ;
V_139 |= ( V_131 & V_9 -> V_141 ) ;
* V_138 = V_139 ;
return true ;
}
int F_73 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_74 * V_35 ,
bool V_42 , bool V_76 ,
bool V_77 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_2 = V_10 ;
T_1 V_139 = 0 ;
bool V_142 = false ;
bool V_143 = false ;
bool V_144 = false ;
int V_3 , V_18 ;
V_35 -> V_36 = NULL ;
for ( V_3 = 0 ; V_3 < V_17 -> V_19 ; ++ V_3 ) {
V_18 = F_1 ( V_17 -> V_17 [ V_3 ] ,
& V_2 ) ;
if ( V_18 )
return V_18 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
V_143 = F_77 ( V_9 ,
V_2 ,
V_17 -> V_17 [ V_3 ] ,
& V_139 ) ;
if ( ! V_143 )
continue;
V_139 = F_76 ( V_9 , V_15 -> V_35 . V_17 ,
V_139 ) ;
F_78 ( & V_139 , V_17 -> V_17 [ V_3 ] ,
~ V_145 ) ;
if ( V_2 == V_10 )
break;
if ( V_9 -> V_146 && V_9 -> V_147 ) {
V_142 = true ;
V_18 = (* V_9 -> V_11 -> V_130 )( V_9 , V_15 , V_17 , V_35 ) ;
if ( F_25 ( V_18 ) )
return V_18 ;
}
if ( V_35 -> V_36 )
break;
}
if ( ( V_143 && ( V_2 == V_10 ) ) || V_35 -> V_36 ) {
V_35 -> V_2 = V_2 ;
V_35 -> V_17 = V_139 ;
return 0 ;
}
if ( ! V_142 )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_17 -> V_127 ; ++ V_3 ) {
V_18 = F_1 ( V_17 -> V_148 [ V_3 ] ,
& V_2 ) ;
if ( V_18 )
return V_18 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_146 )
continue;
if ( ! F_77 ( V_9 ,
V_2 ,
V_17 -> V_148 [ V_3 ] ,
& V_139 ) )
continue;
V_139 = F_76 ( V_9 , V_15 -> V_35 . V_17 ,
V_139 ) ;
F_78 ( & V_139 , V_17 -> V_148 [ V_3 ] ,
~ V_145 ) ;
if ( V_2 == V_10 ) {
V_35 -> V_2 = V_2 ;
V_35 -> V_17 = V_139 ;
V_35 -> V_36 = NULL ;
return 0 ;
}
V_18 = F_75 ( V_15 , V_2 , V_17 , V_35 ,
V_42 , V_76 , V_77 ) ;
if ( V_18 == 0 && V_35 -> V_36 ) {
V_35 -> V_17 = V_139 ;
return 0 ;
}
if ( V_18 == - V_121 )
V_144 = true ;
}
V_18 = ( V_144 ) ? - V_121 : - V_73 ;
return V_18 ;
}
int F_79 ( struct V_14 * V_15 , bool V_49 )
{
if ( ( F_7 ( & V_15 -> V_33 ) > 0 ) && V_49 )
return - V_56 ;
return F_17 ( V_15 -> V_43 ,
F_7 ( & V_15 -> V_33 ) == 0 ) ;
}
int F_80 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_42 , bool V_76 ,
bool V_77 )
{
int V_18 = 0 ;
struct V_74 V_35 ;
struct V_6 * V_7 = V_15 -> V_7 ;
F_10 ( ! F_7 ( & V_15 -> V_44 ) ) ;
F_28 ( & V_7 -> V_98 ) ;
V_18 = F_55 ( V_15 , false , V_42 , V_77 ) ;
F_27 ( & V_7 -> V_98 ) ;
if ( V_18 )
return V_18 ;
V_35 . V_70 = V_15 -> V_70 ;
V_35 . V_149 = V_35 . V_70 << V_71 ;
V_35 . V_150 = V_15 -> V_35 . V_150 ;
V_35 . V_122 . V_123 = false ;
V_35 . V_122 . V_124 = 0 ;
V_18 = F_73 ( V_15 , V_17 , & V_35 , V_42 , V_76 , V_77 ) ;
if ( V_18 )
goto V_108;
V_18 = F_41 ( V_15 , & V_35 , false , V_42 , V_76 , V_77 ) ;
V_108:
if ( V_18 && V_35 . V_36 )
F_52 ( V_15 , & V_35 ) ;
return V_18 ;
}
static int F_81 ( struct V_16 * V_17 ,
struct V_74 * V_35 )
{
int V_3 ;
if ( V_35 -> V_36 && V_17 -> V_126 != 0 &&
( V_35 -> V_93 < V_17 -> V_125 ||
V_35 -> V_93 + V_35 -> V_70 > V_17 -> V_126 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_17 -> V_19 ; V_3 ++ ) {
if ( ( V_17 -> V_17 [ V_3 ] & V_35 -> V_17 &
V_82 ) &&
( V_17 -> V_17 [ V_3 ] & V_35 -> V_17 &
V_140 ) )
return V_3 ;
}
return - 1 ;
}
int F_82 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_42 , bool V_76 ,
bool V_77 )
{
int V_18 ;
F_10 ( ! F_7 ( & V_15 -> V_44 ) ) ;
if ( V_17 -> V_126 || V_17 -> V_125 )
if ( V_17 -> V_125 > V_17 -> V_126 ||
( V_17 -> V_126 - V_17 -> V_125 ) < V_15 -> V_70 )
return - V_5 ;
V_18 = F_81 ( V_17 , & V_15 -> V_35 ) ;
if ( V_18 < 0 ) {
V_18 = F_80 ( V_15 , V_17 , V_42 , V_76 , V_77 ) ;
if ( V_18 )
return V_18 ;
} else {
F_78 ( & V_15 -> V_35 . V_17 , V_17 -> V_17 [ V_18 ] ,
~ V_145 ) ;
}
if ( V_15 -> V_35 . V_2 == V_10 && V_15 -> V_39 == NULL ) {
V_18 = F_39 ( V_15 , true ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
int F_83 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
F_10 ( ( V_17 -> V_125 || V_17 -> V_126 ) &&
( V_15 -> V_35 . V_70 > ( V_17 -> V_126 - V_17 -> V_125 ) ) ) ;
return 0 ;
}
int F_84 ( struct V_6 * V_7 ,
struct V_14 * V_15 ,
unsigned long V_149 ,
enum V_151 type ,
struct V_16 * V_17 ,
T_1 V_150 ,
unsigned long V_152 ,
bool V_42 ,
struct V_153 * V_154 ,
T_3 V_31 ,
void (* V_40) ( struct V_14 * ) )
{
int V_18 = 0 ;
unsigned long V_70 ;
struct V_155 * V_41 = V_7 -> V_26 -> V_41 ;
V_18 = F_85 ( V_41 , V_31 , false , false ) ;
if ( V_18 ) {
F_3 (KERN_ERR TTM_PFX L_18 ) ;
if ( V_40 )
(* V_40)( V_15 ) ;
else
F_14 ( V_15 ) ;
return - V_73 ;
}
V_149 += V_152 & ~ V_156 ;
V_70 = ( V_149 + V_27 - 1 ) >> V_71 ;
if ( V_70 == 0 ) {
F_3 (KERN_ERR TTM_PFX L_19 ) ;
if ( V_40 )
(* V_40)( V_15 ) ;
else
F_14 ( V_15 ) ;
return - V_5 ;
}
V_15 -> V_40 = V_40 ;
F_86 ( & V_15 -> V_29 ) ;
F_86 ( & V_15 -> V_30 ) ;
F_37 ( & V_15 -> V_33 , 0 ) ;
F_37 ( & V_15 -> V_44 , 1 ) ;
F_87 ( & V_15 -> V_43 ) ;
F_88 ( & V_15 -> V_37 ) ;
F_88 ( & V_15 -> V_38 ) ;
F_88 ( & V_15 -> V_46 ) ;
F_88 ( & V_15 -> V_157 ) ;
V_15 -> V_7 = V_7 ;
V_15 -> V_26 = V_7 -> V_26 ;
V_15 -> type = type ;
V_15 -> V_70 = V_70 ;
V_15 -> V_35 . V_149 = V_70 << V_71 ;
V_15 -> V_35 . V_2 = V_10 ;
V_15 -> V_35 . V_70 = V_15 -> V_70 ;
V_15 -> V_35 . V_36 = NULL ;
V_15 -> V_35 . V_150 = V_150 ;
V_15 -> V_35 . V_122 . V_123 = false ;
V_15 -> V_35 . V_122 . V_124 = 0 ;
V_15 -> V_152 = V_152 & V_156 ;
V_15 -> V_158 = 0 ;
V_15 -> V_35 . V_17 = ( V_159 | V_135 ) ;
V_15 -> V_52 = false ;
V_15 -> V_154 = V_154 ;
V_15 -> V_31 = V_31 ;
F_89 ( & V_15 -> V_26 -> V_28 ) ;
V_18 = F_83 ( V_15 , V_17 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_83;
if ( V_15 -> type == V_65 ) {
V_18 = F_90 ( V_15 ) ;
if ( V_18 )
goto V_83;
}
V_18 = F_82 ( V_15 , V_17 , V_42 , false , false ) ;
if ( V_18 )
goto V_83;
F_38 ( V_15 ) ;
return 0 ;
V_83:
F_38 ( V_15 ) ;
F_68 ( & V_15 ) ;
return V_18 ;
}
T_3 F_91 ( struct V_6 * V_7 ,
unsigned long V_160 ,
unsigned V_161 )
{
unsigned V_162 = ( F_92 ( V_160 ) ) >> V_71 ;
T_3 V_149 = 0 ;
V_149 += F_93 ( V_161 ) ;
V_149 += F_92 ( V_162 * sizeof( void * ) ) ;
V_149 += F_93 ( sizeof( struct V_163 ) ) ;
return V_149 ;
}
T_3 F_94 ( struct V_6 * V_7 ,
unsigned long V_160 ,
unsigned V_161 )
{
unsigned V_162 = ( F_92 ( V_160 ) ) >> V_71 ;
T_3 V_149 = 0 ;
V_149 += F_93 ( V_161 ) ;
V_149 += F_92 ( V_162 * sizeof( void * ) ) ;
V_149 += F_92 ( V_162 * sizeof( V_164 ) ) ;
V_149 += F_93 ( sizeof( struct V_165 ) ) ;
return V_149 ;
}
int F_95 ( struct V_6 * V_7 ,
unsigned long V_149 ,
enum V_151 type ,
struct V_16 * V_17 ,
T_1 V_150 ,
unsigned long V_152 ,
bool V_42 ,
struct V_153 * V_154 ,
struct V_14 * * V_118 )
{
struct V_14 * V_15 ;
struct V_155 * V_41 = V_7 -> V_26 -> V_41 ;
T_3 V_31 ;
int V_18 ;
V_31 = F_91 ( V_7 , V_149 , sizeof( struct V_14 ) ) ;
V_18 = F_85 ( V_41 , V_31 , false , false ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
V_15 = F_96 ( sizeof( * V_15 ) , V_166 ) ;
if ( F_25 ( V_15 == NULL ) ) {
F_15 ( V_41 , V_31 ) ;
return - V_73 ;
}
V_18 = F_84 ( V_7 , V_15 , V_149 , type , V_17 , V_150 ,
V_152 , V_42 ,
V_154 , V_31 , NULL ) ;
if ( F_35 ( V_18 == 0 ) )
* V_118 = V_15 ;
return V_18 ;
}
static int F_97 ( struct V_6 * V_7 ,
unsigned V_2 , bool V_167 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_25 * V_26 = V_7 -> V_26 ;
int V_18 ;
F_28 ( & V_26 -> V_57 ) ;
while ( ! F_11 ( & V_9 -> V_37 ) ) {
F_27 ( & V_26 -> V_57 ) ;
V_18 = F_74 ( V_7 , V_2 , false , false , false ) ;
if ( V_18 ) {
if ( V_167 ) {
return V_18 ;
} else {
F_3 (KERN_ERR TTM_PFX
L_20 ) ;
}
}
F_28 ( & V_26 -> V_57 ) ;
}
F_27 ( & V_26 -> V_57 ) ;
return 0 ;
}
int F_98 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 ;
int V_18 = - V_5 ;
if ( V_2 >= V_168 ) {
F_3 (KERN_ERR TTM_PFX L_21 , mem_type) ;
return V_18 ;
}
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_146 ) {
F_3 (KERN_ERR TTM_PFX L_22
L_23 , mem_type) ;
return V_18 ;
}
V_9 -> V_147 = false ;
V_9 -> V_146 = false ;
V_18 = 0 ;
if ( V_2 > 0 ) {
F_97 ( V_7 , V_2 , false ) ;
V_18 = (* V_9 -> V_11 -> V_169 )( V_9 ) ;
}
return V_18 ;
}
int F_99 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( V_2 == 0 || V_2 >= V_168 ) {
F_3 (KERN_ERR TTM_PFX
L_24 ,
mem_type) ;
return - V_5 ;
}
if ( ! V_9 -> V_146 ) {
F_3 (KERN_ERR TTM_PFX
L_25 ,
mem_type) ;
return 0 ;
}
return F_97 ( V_7 , V_2 , true ) ;
}
int F_100 ( struct V_6 * V_7 , unsigned type ,
unsigned long V_170 )
{
int V_18 = - V_5 ;
struct V_8 * V_9 ;
F_10 ( type >= V_168 ) ;
V_9 = & V_7 -> V_9 [ type ] ;
F_10 ( V_9 -> V_146 ) ;
V_9 -> V_171 = true ;
V_9 -> V_172 = false ;
F_101 ( & V_9 -> V_173 ) ;
F_88 ( & V_9 -> V_157 ) ;
V_18 = V_7 -> V_68 -> V_174 ( V_7 , type , V_9 ) ;
if ( V_18 )
return V_18 ;
V_9 -> V_7 = V_7 ;
V_18 = 0 ;
if ( type != V_10 ) {
V_18 = (* V_9 -> V_11 -> V_175 )( V_9 , V_170 ) ;
if ( V_18 )
return V_18 ;
}
V_9 -> V_146 = true ;
V_9 -> V_147 = true ;
V_9 -> V_149 = V_170 ;
F_88 ( & V_9 -> V_37 ) ;
return 0 ;
}
static void F_102 ( struct V_20 * V_21 )
{
struct V_25 * V_26 =
F_6 ( V_21 , struct V_25 , V_21 ) ;
F_103 ( V_26 -> V_41 , & V_26 -> V_176 ) ;
F_104 ( V_26 -> V_72 ) ;
F_14 ( V_26 ) ;
}
void F_105 ( struct V_177 * V_178 )
{
struct V_25 * V_26 = V_178 -> V_179 ;
F_106 ( & V_26 -> V_21 ) ;
F_107 ( & V_26 -> V_21 ) ;
}
int F_108 ( struct V_177 * V_178 )
{
struct V_180 * V_181 =
F_6 ( V_178 , struct V_180 , V_178 ) ;
struct V_25 * V_26 = V_178 -> V_179 ;
int V_18 ;
F_101 ( & V_26 -> V_182 ) ;
F_109 ( & V_26 -> V_57 ) ;
V_26 -> V_41 = V_181 -> V_41 ;
V_26 -> V_72 = F_110 ( V_183 | V_184 ) ;
if ( F_25 ( V_26 -> V_72 == NULL ) ) {
V_18 = - V_73 ;
goto V_185;
}
F_88 ( & V_26 -> V_47 ) ;
F_88 ( & V_26 -> V_186 ) ;
F_111 ( & V_26 -> V_176 , V_187 ) ;
V_18 = F_112 ( V_26 -> V_41 , & V_26 -> V_176 ) ;
if ( F_25 ( V_18 != 0 ) ) {
F_3 (KERN_ERR TTM_PFX
L_26 ) ;
goto V_188;
}
F_37 ( & V_26 -> V_28 , 0 ) ;
V_18 = F_113 (
& V_26 -> V_21 , & V_189 , F_114 () , L_27 ) ;
if ( F_25 ( V_18 != 0 ) )
F_107 ( & V_26 -> V_21 ) ;
return V_18 ;
V_188:
F_104 ( V_26 -> V_72 ) ;
V_185:
F_14 ( V_26 ) ;
return V_18 ;
}
int F_115 ( struct V_6 * V_7 )
{
int V_18 = 0 ;
unsigned V_3 = V_168 ;
struct V_8 * V_9 ;
struct V_25 * V_26 = V_7 -> V_26 ;
while ( V_3 -- ) {
V_9 = & V_7 -> V_9 [ V_3 ] ;
if ( V_9 -> V_146 ) {
V_9 -> V_147 = false ;
if ( ( V_3 != V_10 ) && F_98 ( V_7 , V_3 ) ) {
V_18 = - V_56 ;
F_3 (KERN_ERR TTM_PFX
L_28
L_29 , i) ;
}
V_9 -> V_146 = false ;
}
}
F_116 ( & V_26 -> V_182 ) ;
F_117 ( & V_7 -> V_186 ) ;
F_118 ( & V_26 -> V_182 ) ;
F_70 ( & V_7 -> V_103 ) ;
while ( F_58 ( V_7 , true ) )
;
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_7 -> V_38 ) )
F_119 ( L_30 ) ;
if ( F_11 ( & V_7 -> V_9 [ 0 ] . V_37 ) )
F_119 ( L_31 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_10 ( ! F_120 ( & V_7 -> V_190 ) ) ;
F_67 ( & V_7 -> V_117 ) ;
F_121 ( & V_7 -> V_190 ) ;
F_65 ( & V_7 -> V_117 ) ;
return V_18 ;
}
int F_122 ( struct V_6 * V_7 ,
struct V_25 * V_26 ,
struct V_96 * V_68 ,
T_4 V_191 ,
bool V_63 )
{
int V_18 = - V_5 ;
F_123 ( & V_7 -> V_117 ) ;
V_7 -> V_68 = V_68 ;
memset ( V_7 -> V_9 , 0 , sizeof( V_7 -> V_9 ) ) ;
V_18 = F_100 ( V_7 , V_10 , 0 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_192;
V_7 -> V_116 = V_193 ;
V_18 = F_124 ( & V_7 -> V_190 , V_191 , 0x10000000 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_194;
F_125 ( & V_7 -> V_103 , F_61 ) ;
V_7 -> V_195 = true ;
F_88 ( & V_7 -> V_38 ) ;
V_7 -> V_196 = NULL ;
V_7 -> V_26 = V_26 ;
V_7 -> V_63 = V_63 ;
V_7 -> V_53 = 0 ;
F_109 ( & V_7 -> V_98 ) ;
F_116 ( & V_26 -> V_182 ) ;
F_20 ( & V_7 -> V_186 , & V_26 -> V_186 ) ;
F_118 ( & V_26 -> V_182 ) ;
return 0 ;
V_194:
F_98 ( V_7 , 0 ) ;
V_192:
return V_18 ;
}
bool F_42 ( struct V_6 * V_7 , struct V_74 * V_35 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_35 -> V_2 ] ;
if ( ! ( V_9 -> V_1 & V_84 ) ) {
if ( V_35 -> V_2 == V_10 )
return false ;
if ( V_9 -> V_1 & V_197 )
return false ;
if ( V_35 -> V_17 & V_135 )
return false ;
}
return true ;
}
void F_44 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
T_5 V_92 = ( T_5 ) V_15 -> V_198 ;
T_5 V_199 = ( ( T_5 ) V_15 -> V_35 . V_70 ) << V_71 ;
if ( ! V_7 -> V_196 )
return;
F_126 ( V_7 -> V_196 , V_92 , V_199 , 1 ) ;
F_66 ( V_15 ) ;
}
void F_127 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_15 -> V_35 . V_2 ] ;
F_43 ( V_9 , false ) ;
F_44 ( V_15 ) ;
F_45 ( V_9 ) ;
}
static void F_128 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_200 * * V_201 = & V_7 -> V_116 . V_200 ;
struct V_200 * V_202 = NULL ;
struct V_14 * V_203 ;
unsigned long V_92 = V_15 -> V_114 -> V_93 ;
unsigned long V_204 ;
while ( * V_201 ) {
V_202 = * V_201 ;
V_203 = F_129 ( V_202 , struct V_14 , V_115 ) ;
V_204 = V_203 -> V_114 -> V_93 ;
if ( V_92 < V_204 )
V_201 = & V_202 -> V_205 ;
else if ( V_92 > V_204 )
V_201 = & V_202 -> V_206 ;
else
F_31 () ;
}
F_130 ( & V_15 -> V_115 , V_202 , V_201 ) ;
F_131 ( & V_15 -> V_115 , & V_7 -> V_116 ) ;
}
static int F_90 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
int V_18 ;
V_207:
V_18 = F_132 ( & V_7 -> V_190 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
F_67 ( & V_7 -> V_117 ) ;
V_15 -> V_114 = F_133 ( & V_7 -> V_190 ,
V_15 -> V_35 . V_70 , 0 , 0 ) ;
if ( F_25 ( V_15 -> V_114 == NULL ) ) {
V_18 = - V_73 ;
goto V_108;
}
V_15 -> V_114 = F_134 ( V_15 -> V_114 ,
V_15 -> V_35 . V_70 , 0 ) ;
if ( F_25 ( V_15 -> V_114 == NULL ) ) {
F_65 ( & V_7 -> V_117 ) ;
goto V_207;
}
F_128 ( V_15 ) ;
F_65 ( & V_7 -> V_117 ) ;
V_15 -> V_198 = ( ( T_4 ) V_15 -> V_114 -> V_93 ) << V_71 ;
return 0 ;
V_108:
F_65 ( & V_7 -> V_117 ) ;
return V_18 ;
}
int F_55 ( struct V_14 * V_15 ,
bool V_208 , bool V_42 , bool V_49 )
{
struct V_96 * V_68 = V_15 -> V_7 -> V_68 ;
struct V_6 * V_7 = V_15 -> V_7 ;
void * V_34 ;
void * V_97 ;
int V_18 = 0 ;
if ( F_35 ( V_15 -> V_34 == NULL ) )
return 0 ;
while ( V_15 -> V_34 ) {
if ( V_68 -> V_209 ( V_15 -> V_34 , V_15 -> V_97 ) ) {
void * V_210 = V_15 -> V_34 ;
V_15 -> V_34 = NULL ;
F_135 ( V_211 , & V_15 -> V_158 ) ;
F_27 ( & V_7 -> V_98 ) ;
V_68 -> V_102 ( & V_210 ) ;
F_28 ( & V_7 -> V_98 ) ;
continue;
}
if ( V_49 )
return - V_56 ;
V_34 = V_68 -> V_100 ( V_15 -> V_34 ) ;
V_97 = V_15 -> V_97 ;
F_27 ( & V_7 -> V_98 ) ;
V_18 = V_68 -> V_212 ( V_34 , V_97 ,
V_208 , V_42 ) ;
if ( F_25 ( V_18 != 0 ) ) {
V_68 -> V_102 ( & V_34 ) ;
F_28 ( & V_7 -> V_98 ) ;
return V_18 ;
}
F_28 ( & V_7 -> V_98 ) ;
if ( F_35 ( V_15 -> V_34 == V_34 &&
V_15 -> V_97 == V_97 ) ) {
void * V_210 = V_15 -> V_34 ;
V_15 -> V_34 = NULL ;
F_135 ( V_211 ,
& V_15 -> V_158 ) ;
F_27 ( & V_7 -> V_98 ) ;
V_68 -> V_102 ( & V_34 ) ;
V_68 -> V_102 ( & V_210 ) ;
F_28 ( & V_7 -> V_98 ) ;
} else {
F_27 ( & V_7 -> V_98 ) ;
V_68 -> V_102 ( & V_34 ) ;
F_28 ( & V_7 -> V_98 ) ;
}
}
return 0 ;
}
int F_136 ( struct V_14 * V_15 , bool V_49 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
int V_18 = 0 ;
V_18 = F_34 ( V_15 , true , V_49 , false , 0 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
F_28 ( & V_7 -> V_98 ) ;
V_18 = F_55 ( V_15 , false , true , V_49 ) ;
F_27 ( & V_7 -> V_98 ) ;
if ( F_35 ( V_18 == 0 ) )
F_89 ( & V_15 -> V_33 ) ;
F_38 ( V_15 ) ;
return V_18 ;
}
void F_137 ( struct V_14 * V_15 )
{
if ( F_138 ( & V_15 -> V_33 ) )
F_29 ( & V_15 -> V_43 ) ;
}
static int V_187 ( struct V_213 * V_176 )
{
struct V_25 * V_26 =
F_6 ( V_176 , struct V_25 , V_176 ) ;
struct V_14 * V_15 ;
int V_18 = - V_56 ;
int V_48 ;
T_1 V_214 = ( V_135 | V_159 ) ;
F_28 ( & V_26 -> V_57 ) ;
while ( V_18 == - V_56 ) {
if ( F_25 ( F_11 ( & V_26 -> V_47 ) ) ) {
F_27 ( & V_26 -> V_57 ) ;
return - V_56 ;
}
V_15 = F_59 ( & V_26 -> V_47 ,
struct V_14 , V_46 ) ;
F_21 ( & V_15 -> V_30 ) ;
if ( ! F_11 ( & V_15 -> V_38 ) ) {
F_27 ( & V_26 -> V_57 ) ;
( void ) F_57 ( V_15 , false , false , false ) ;
F_60 ( & V_15 -> V_30 , F_9 ) ;
continue;
}
V_18 = F_24 ( V_15 , false , true , false , 0 ) ;
if ( F_25 ( V_18 == - V_56 ) ) {
F_27 ( & V_26 -> V_57 ) ;
F_16 ( V_15 , false ) ;
F_60 ( & V_15 -> V_30 , F_9 ) ;
F_28 ( & V_26 -> V_57 ) ;
}
}
F_10 ( V_18 != 0 ) ;
V_48 = F_22 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_32 ( V_15 , V_48 , true ) ;
F_28 ( & V_15 -> V_7 -> V_98 ) ;
V_18 = F_55 ( V_15 , false , false , false ) ;
F_27 ( & V_15 -> V_7 -> V_98 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_111;
if ( ( V_15 -> V_35 . V_17 & V_214 ) != V_214 ) {
struct V_74 V_120 ;
V_120 = V_15 -> V_35 ;
V_120 . V_36 = NULL ;
V_120 . V_17 = V_159 | V_135 ;
V_120 . V_2 = V_10 ;
V_18 = F_41 ( V_15 , & V_120 , true ,
false , false , false ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_111;
}
F_127 ( V_15 ) ;
if ( V_15 -> V_7 -> V_68 -> V_215 )
V_15 -> V_7 -> V_68 -> V_215 ( V_15 ) ;
V_18 = F_139 ( V_15 -> V_39 , V_15 -> V_154 ) ;
V_111:
F_37 ( & V_15 -> V_44 , 0 ) ;
F_29 ( & V_15 -> V_43 ) ;
F_60 ( & V_15 -> V_30 , F_9 ) ;
return V_18 ;
}
void F_140 ( struct V_6 * V_7 )
{
while ( V_187 ( & V_7 -> V_26 -> V_176 ) == 0 )
;
}
