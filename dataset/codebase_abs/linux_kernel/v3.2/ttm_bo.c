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
F_10 ( F_7 ( & V_15 -> V_30 . V_31 ) ) ;
F_10 ( F_7 ( & V_15 -> V_29 . V_31 ) ) ;
F_10 ( F_7 ( & V_15 -> V_32 ) ) ;
F_10 ( V_15 -> V_33 != NULL ) ;
F_10 ( V_15 -> V_34 . V_35 != NULL ) ;
F_10 ( ! F_11 ( & V_15 -> V_36 ) ) ;
F_10 ( ! F_11 ( & V_15 -> V_37 ) ) ;
if ( V_15 -> V_38 )
F_12 ( V_15 -> V_38 ) ;
F_13 ( & V_15 -> V_26 -> V_28 ) ;
if ( V_15 -> V_39 )
V_15 -> V_39 ( V_15 ) ;
else {
F_14 ( V_7 -> V_26 -> V_40 , V_15 -> V_41 ) ;
F_15 ( V_15 ) ;
}
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
if ( ! ( V_15 -> V_34 . V_17 & V_45 ) ) {
F_10 ( ! F_11 ( & V_15 -> V_36 ) ) ;
V_9 = & V_7 -> V_9 [ V_15 -> V_34 . V_2 ] ;
F_20 ( & V_15 -> V_36 , & V_9 -> V_36 ) ;
F_21 ( & V_15 -> V_30 ) ;
if ( V_15 -> V_38 != NULL ) {
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
if ( ! F_11 ( & V_15 -> V_36 ) ) {
F_23 ( & V_15 -> V_36 ) ;
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
V_15 -> V_38 = NULL ;
if ( V_7 -> V_63 )
V_61 |= V_64 ;
switch ( V_15 -> type ) {
case V_65 :
if ( V_60 )
V_61 |= V_66 ;
case V_67 :
V_15 -> V_38 = F_41 ( V_7 , V_15 -> V_68 << V_69 ,
V_61 , V_26 -> V_70 ) ;
if ( F_25 ( V_15 -> V_38 == NULL ) )
V_18 = - V_71 ;
break;
case V_72 :
V_15 -> V_38 = F_41 ( V_7 , V_15 -> V_68 << V_69 ,
V_61 | V_73 ,
V_26 -> V_70 ) ;
if ( F_25 ( V_15 -> V_38 == NULL ) ) {
V_18 = - V_71 ;
break;
}
V_18 = F_42 ( V_15 -> V_38 , V_74 ,
V_15 -> V_75 , V_15 -> V_68 ) ;
if ( F_25 ( V_18 != 0 ) ) {
F_12 ( V_15 -> V_38 ) ;
V_15 -> V_38 = NULL ;
}
break;
default:
F_3 (KERN_ERR TTM_PFX L_11 ) ;
V_18 = - V_5 ;
break;
}
return V_18 ;
}
static int F_43 ( struct V_14 * V_15 ,
struct V_76 * V_34 ,
bool V_77 , bool V_42 ,
bool V_78 , bool V_79 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
bool V_80 = F_44 ( V_7 , & V_15 -> V_34 ) ;
bool V_81 = F_44 ( V_7 , V_34 ) ;
struct V_8 * V_82 = & V_7 -> V_9 [ V_15 -> V_34 . V_2 ] ;
struct V_8 * V_83 = & V_7 -> V_9 [ V_34 -> V_2 ] ;
int V_18 = 0 ;
if ( V_80 || V_81 ||
( ( V_34 -> V_17 & V_15 -> V_34 . V_17 & V_84 ) == 0 ) ) {
V_18 = F_45 ( V_82 , true ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_85;
F_46 ( V_15 ) ;
F_47 ( V_82 ) ;
}
if ( ! ( V_83 -> V_1 & V_86 ) ) {
if ( V_15 -> V_38 == NULL ) {
bool V_87 = ! ( V_82 -> V_1 & V_86 ) ;
V_18 = F_39 ( V_15 , V_87 ) ;
if ( V_18 )
goto V_85;
}
V_18 = F_48 ( V_15 -> V_38 , V_34 -> V_17 ) ;
if ( V_18 )
goto V_85;
if ( V_34 -> V_2 != V_10 ) {
V_18 = F_49 ( V_15 -> V_38 , V_34 ) ;
if ( V_18 )
goto V_85;
}
if ( V_15 -> V_34 . V_2 == V_10 ) {
if ( V_7 -> V_88 -> V_89 )
V_7 -> V_88 -> V_89 ( V_15 , V_34 ) ;
V_15 -> V_34 = * V_34 ;
V_34 -> V_35 = NULL ;
goto V_90;
}
}
if ( V_7 -> V_88 -> V_89 )
V_7 -> V_88 -> V_89 ( V_15 , V_34 ) ;
if ( ! ( V_82 -> V_1 & V_86 ) &&
! ( V_83 -> V_1 & V_86 ) )
V_18 = F_50 ( V_15 , V_77 , V_78 , V_79 , V_34 ) ;
else if ( V_7 -> V_88 -> V_91 )
V_18 = V_7 -> V_88 -> V_91 ( V_15 , V_77 , V_42 ,
V_78 , V_79 , V_34 ) ;
else
V_18 = F_51 ( V_15 , V_77 , V_78 , V_79 , V_34 ) ;
if ( V_18 )
goto V_85;
V_90:
if ( V_15 -> V_92 ) {
V_18 = V_7 -> V_88 -> V_93 ( V_7 , V_15 -> V_34 . V_17 ) ;
if ( V_18 )
F_3 (KERN_ERR TTM_PFX L_12 ) ;
V_15 -> V_92 = false ;
}
if ( V_15 -> V_34 . V_35 ) {
V_15 -> V_94 = ( V_15 -> V_34 . V_95 << V_69 ) +
V_7 -> V_9 [ V_15 -> V_34 . V_2 ] . V_96 ;
V_15 -> V_97 = V_15 -> V_34 . V_17 ;
} else
V_15 -> V_94 = 0 ;
return 0 ;
V_85:
V_83 = & V_7 -> V_9 [ V_15 -> V_34 . V_2 ] ;
if ( ( V_83 -> V_1 & V_86 ) && V_15 -> V_38 ) {
F_52 ( V_15 -> V_38 ) ;
F_12 ( V_15 -> V_38 ) ;
V_15 -> V_38 = NULL ;
}
return V_18 ;
}
static void F_53 ( struct V_14 * V_15 )
{
if ( V_15 -> V_38 ) {
F_52 ( V_15 -> V_38 ) ;
F_12 ( V_15 -> V_38 ) ;
V_15 -> V_38 = NULL ;
}
F_54 ( V_15 , & V_15 -> V_34 ) ;
F_37 ( & V_15 -> V_44 , 0 ) ;
F_55 () ;
F_29 ( & V_15 -> V_43 ) ;
}
static void F_56 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_25 * V_26 = V_15 -> V_26 ;
struct V_98 * V_88 ;
void * V_33 = NULL ;
void * V_99 ;
int V_48 ;
int V_18 ;
F_28 ( & V_7 -> V_100 ) ;
( void ) F_57 ( V_15 , false , false , true ) ;
if ( ! V_15 -> V_33 ) {
F_28 ( & V_26 -> V_57 ) ;
V_18 = F_24 ( V_15 , false , true , false , 0 ) ;
if ( F_25 ( V_18 == - V_56 ) )
goto V_101;
F_27 ( & V_7 -> V_100 ) ;
V_48 = F_22 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_53 ( V_15 ) ;
F_32 ( V_15 , V_48 , true ) ;
return;
} else {
F_28 ( & V_26 -> V_57 ) ;
}
V_101:
V_88 = V_7 -> V_88 ;
if ( V_15 -> V_33 )
V_33 = V_88 -> V_102 ( V_15 -> V_33 ) ;
V_99 = V_15 -> V_99 ;
F_21 ( & V_15 -> V_30 ) ;
F_20 ( & V_15 -> V_37 , & V_7 -> V_37 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_27 ( & V_7 -> V_100 ) ;
if ( V_33 ) {
V_88 -> V_103 ( V_33 , V_99 ) ;
V_88 -> V_104 ( & V_33 ) ;
}
F_58 ( & V_7 -> V_105 ,
( ( V_106 / 100 ) < 1 ) ? 1 : V_106 / 100 ) ;
}
static int F_59 ( struct V_14 * V_15 ,
bool V_42 ,
bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_25 * V_26 = V_15 -> V_26 ;
int V_48 ;
int V_18 = 0 ;
V_107:
F_28 ( & V_7 -> V_100 ) ;
V_18 = F_57 ( V_15 , false , V_42 , V_79 ) ;
F_27 ( & V_7 -> V_100 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
F_28 ( & V_26 -> V_57 ) ;
if ( F_25 ( F_11 ( & V_15 -> V_37 ) ) ) {
F_27 ( & V_26 -> V_57 ) ;
return 0 ;
}
V_18 = F_24 ( V_15 , V_42 ,
V_78 , false , 0 ) ;
if ( F_25 ( V_18 != 0 ) ) {
F_27 ( & V_26 -> V_57 ) ;
return V_18 ;
}
if ( F_25 ( V_15 -> V_33 ) ) {
F_37 ( & V_15 -> V_44 , 0 ) ;
F_29 ( & V_15 -> V_43 ) ;
F_27 ( & V_26 -> V_57 ) ;
goto V_107;
}
V_48 = F_22 ( V_15 ) ;
F_23 ( & V_15 -> V_37 ) ;
++ V_48 ;
F_27 ( & V_26 -> V_57 ) ;
F_53 ( V_15 ) ;
F_32 ( V_15 , V_48 , true ) ;
return 0 ;
}
static int F_60 ( struct V_6 * V_7 , bool V_108 )
{
struct V_25 * V_26 = V_7 -> V_26 ;
struct V_14 * V_109 = NULL ;
int V_18 = 0 ;
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_7 -> V_37 ) )
goto V_110;
V_109 = F_61 ( & V_7 -> V_37 ,
struct V_14 , V_37 ) ;
F_21 ( & V_109 -> V_30 ) ;
for (; ; ) {
struct V_14 * V_111 = NULL ;
if ( V_109 -> V_37 . V_112 != & V_7 -> V_37 ) {
V_111 = F_61 ( & V_109 -> V_37 ,
struct V_14 , V_37 ) ;
F_21 ( & V_111 -> V_30 ) ;
}
F_27 ( & V_26 -> V_57 ) ;
V_18 = F_59 ( V_109 , false , ! V_108 ,
! V_108 ) ;
F_62 ( & V_109 -> V_30 , F_9 ) ;
V_109 = V_111 ;
if ( V_18 || ! V_109 )
goto V_113;
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_109 -> V_37 ) )
break;
}
V_110:
F_27 ( & V_26 -> V_57 ) ;
V_113:
if ( V_109 )
F_62 ( & V_109 -> V_30 , F_9 ) ;
return V_18 ;
}
static void F_63 ( struct V_114 * V_115 )
{
struct V_6 * V_7 =
F_6 ( V_115 , struct V_6 , V_105 . V_115 ) ;
if ( F_60 ( V_7 , false ) ) {
F_58 ( & V_7 -> V_105 ,
( ( V_106 / 100 ) < 1 ) ? 1 : V_106 / 100 ) ;
}
}
static void F_64 ( struct V_29 * V_29 )
{
struct V_14 * V_15 =
F_6 ( V_29 , struct V_14 , V_29 ) ;
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_15 -> V_34 . V_2 ] ;
if ( F_35 ( V_15 -> V_116 != NULL ) ) {
F_65 ( & V_15 -> V_117 , & V_7 -> V_118 ) ;
F_66 ( V_15 -> V_116 ) ;
V_15 -> V_116 = NULL ;
}
F_67 ( & V_7 -> V_119 ) ;
F_45 ( V_9 , false ) ;
F_68 ( V_15 ) ;
F_47 ( V_9 ) ;
F_56 ( V_15 ) ;
F_62 ( & V_15 -> V_30 , F_9 ) ;
F_69 ( & V_7 -> V_119 ) ;
}
void F_70 ( struct V_14 * * V_120 )
{
struct V_14 * V_15 = * V_120 ;
struct V_6 * V_7 = V_15 -> V_7 ;
* V_120 = NULL ;
F_69 ( & V_7 -> V_119 ) ;
F_62 ( & V_15 -> V_29 , F_64 ) ;
F_67 ( & V_7 -> V_119 ) ;
}
int F_71 ( struct V_6 * V_7 )
{
return F_72 ( & V_7 -> V_105 ) ;
}
void F_73 ( struct V_6 * V_7 , int V_121 )
{
if ( V_121 )
F_58 ( & V_7 -> V_105 ,
( ( V_106 / 100 ) < 1 ) ? 1 : V_106 / 100 ) ;
}
static int F_74 ( struct V_14 * V_15 , bool V_42 ,
bool V_78 , bool V_79 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_76 V_122 ;
struct V_16 V_17 ;
int V_18 = 0 ;
F_28 ( & V_7 -> V_100 ) ;
V_18 = F_57 ( V_15 , false , V_42 , V_79 ) ;
F_27 ( & V_7 -> V_100 ) ;
if ( F_25 ( V_18 != 0 ) ) {
if ( V_18 != - V_123 ) {
F_3 (KERN_ERR TTM_PFX
L_13
L_14 ) ;
}
goto V_113;
}
F_10 ( ! F_7 ( & V_15 -> V_44 ) ) ;
V_122 = V_15 -> V_34 ;
V_122 . V_35 = NULL ;
V_122 . V_124 . V_125 = false ;
V_122 . V_124 . V_126 = 0 ;
V_17 . V_127 = 0 ;
V_17 . V_128 = 0 ;
V_17 . V_19 = 0 ;
V_17 . V_129 = 0 ;
V_7 -> V_88 -> V_130 ( V_15 , & V_17 ) ;
V_18 = F_75 ( V_15 , & V_17 , & V_122 , V_42 ,
V_78 , V_79 ) ;
if ( V_18 ) {
if ( V_18 != - V_123 ) {
F_3 (KERN_ERR TTM_PFX
L_15
L_16 , bo) ;
F_4 ( V_15 , & V_17 ) ;
}
goto V_113;
}
V_18 = F_43 ( V_15 , & V_122 , true , V_42 ,
V_78 , V_79 ) ;
if ( V_18 ) {
if ( V_18 != - V_123 )
F_3 (KERN_ERR TTM_PFX L_17 ) ;
F_54 ( V_15 , & V_122 ) ;
goto V_113;
}
V_15 -> V_92 = true ;
V_113:
return V_18 ;
}
static int F_76 ( struct V_6 * V_7 ,
T_1 V_2 ,
bool V_42 , bool V_78 ,
bool V_79 )
{
struct V_25 * V_26 = V_7 -> V_26 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_14 * V_15 ;
int V_18 , V_48 = 0 ;
V_107:
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_9 -> V_36 ) ) {
F_27 ( & V_26 -> V_57 ) ;
return - V_56 ;
}
V_15 = F_61 ( & V_9 -> V_36 , struct V_14 , V_36 ) ;
F_21 ( & V_15 -> V_30 ) ;
if ( ! F_11 ( & V_15 -> V_37 ) ) {
F_27 ( & V_26 -> V_57 ) ;
V_18 = F_59 ( V_15 , V_42 ,
V_78 , V_79 ) ;
F_62 ( & V_15 -> V_30 , F_9 ) ;
if ( F_35 ( V_18 == 0 || V_18 == - V_123 ) )
return V_18 ;
goto V_107;
}
V_18 = F_24 ( V_15 , false , V_78 , false , 0 ) ;
if ( F_25 ( V_18 == - V_56 ) ) {
F_27 ( & V_26 -> V_57 ) ;
if ( F_35 ( ! V_79 ) )
V_18 = F_16 ( V_15 , V_42 ) ;
F_62 ( & V_15 -> V_30 , F_9 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
goto V_107;
}
V_48 = F_22 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_10 ( V_18 != 0 ) ;
F_32 ( V_15 , V_48 , true ) ;
V_18 = F_74 ( V_15 , V_42 , V_78 , V_79 ) ;
F_38 ( V_15 ) ;
F_62 ( & V_15 -> V_30 , F_9 ) ;
return V_18 ;
}
void F_54 ( struct V_14 * V_15 , struct V_76 * V_34 )
{
struct V_8 * V_9 = & V_15 -> V_7 -> V_9 [ V_34 -> V_2 ] ;
if ( V_34 -> V_35 )
(* V_9 -> V_11 -> V_131 )( V_9 , V_34 ) ;
}
static int F_77 ( struct V_14 * V_15 ,
T_1 V_2 ,
struct V_16 * V_17 ,
struct V_76 * V_34 ,
bool V_42 ,
bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
int V_18 ;
do {
V_18 = (* V_9 -> V_11 -> V_132 )( V_9 , V_15 , V_17 , V_34 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
if ( V_34 -> V_35 )
break;
V_18 = F_76 ( V_7 , V_2 , V_42 ,
V_78 , V_79 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
} while ( 1 );
if ( V_34 -> V_35 == NULL )
return - V_71 ;
V_34 -> V_2 = V_2 ;
return 0 ;
}
static T_1 F_78 ( struct V_8 * V_9 ,
T_1 V_97 ,
T_1 V_133 )
{
T_1 V_134 = V_133 & V_84 ;
T_1 V_135 = V_133 & ~ V_84 ;
if ( ( V_97 & V_134 ) != 0 )
V_135 |= ( V_97 & V_134 ) ;
else if ( ( V_9 -> V_136 & V_134 ) != 0 )
V_135 |= V_9 -> V_136 ;
else if ( ( V_137 & V_134 ) != 0 )
V_135 |= V_137 ;
else if ( ( V_138 & V_134 ) != 0 )
V_135 |= V_138 ;
else if ( ( V_139 & V_134 ) != 0 )
V_135 |= V_139 ;
return V_135 ;
}
static bool F_79 ( struct V_8 * V_9 ,
bool V_140 ,
T_1 V_2 ,
T_1 V_133 ,
T_1 * V_141 )
{
T_1 V_142 = F_8 ( V_2 ) ;
if ( ( V_9 -> V_1 & V_86 ) && V_140 )
return false ;
if ( ( V_142 & V_133 & V_143 ) == 0 )
return false ;
if ( ( V_133 & V_9 -> V_144 ) == 0 )
return false ;
V_142 |= ( V_133 & V_9 -> V_144 ) ;
* V_141 = V_142 ;
return true ;
}
int F_75 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_76 * V_34 ,
bool V_42 , bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_2 = V_10 ;
T_1 V_142 = 0 ;
bool V_145 = false ;
bool V_146 = false ;
bool V_147 = false ;
int V_3 , V_18 ;
V_34 -> V_35 = NULL ;
for ( V_3 = 0 ; V_3 < V_17 -> V_19 ; ++ V_3 ) {
V_18 = F_1 ( V_17 -> V_17 [ V_3 ] ,
& V_2 ) ;
if ( V_18 )
return V_18 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
V_146 = F_79 ( V_9 ,
V_15 -> type == V_72 ,
V_2 ,
V_17 -> V_17 [ V_3 ] ,
& V_142 ) ;
if ( ! V_146 )
continue;
V_142 = F_78 ( V_9 , V_15 -> V_34 . V_17 ,
V_142 ) ;
F_80 ( & V_142 , V_17 -> V_17 [ V_3 ] ,
~ V_148 ) ;
if ( V_2 == V_10 )
break;
if ( V_9 -> V_149 && V_9 -> V_150 ) {
V_145 = true ;
V_18 = (* V_9 -> V_11 -> V_132 )( V_9 , V_15 , V_17 , V_34 ) ;
if ( F_25 ( V_18 ) )
return V_18 ;
}
if ( V_34 -> V_35 )
break;
}
if ( ( V_146 && ( V_2 == V_10 ) ) || V_34 -> V_35 ) {
V_34 -> V_2 = V_2 ;
V_34 -> V_17 = V_142 ;
return 0 ;
}
if ( ! V_145 )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_17 -> V_129 ; ++ V_3 ) {
V_18 = F_1 ( V_17 -> V_151 [ V_3 ] ,
& V_2 ) ;
if ( V_18 )
return V_18 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_149 )
continue;
if ( ! F_79 ( V_9 ,
V_15 -> type == V_72 ,
V_2 ,
V_17 -> V_151 [ V_3 ] ,
& V_142 ) )
continue;
V_142 = F_78 ( V_9 , V_15 -> V_34 . V_17 ,
V_142 ) ;
F_80 ( & V_142 , V_17 -> V_151 [ V_3 ] ,
~ V_148 ) ;
if ( V_2 == V_10 ) {
V_34 -> V_2 = V_2 ;
V_34 -> V_17 = V_142 ;
V_34 -> V_35 = NULL ;
return 0 ;
}
V_18 = F_77 ( V_15 , V_2 , V_17 , V_34 ,
V_42 , V_78 , V_79 ) ;
if ( V_18 == 0 && V_34 -> V_35 ) {
V_34 -> V_17 = V_142 ;
return 0 ;
}
if ( V_18 == - V_123 )
V_147 = true ;
}
V_18 = ( V_147 ) ? - V_123 : - V_71 ;
return V_18 ;
}
int F_81 ( struct V_14 * V_15 , bool V_49 )
{
if ( ( F_7 ( & V_15 -> V_32 ) > 0 ) && V_49 )
return - V_56 ;
return F_17 ( V_15 -> V_43 ,
F_7 ( & V_15 -> V_32 ) == 0 ) ;
}
int F_82 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_42 , bool V_78 ,
bool V_79 )
{
int V_18 = 0 ;
struct V_76 V_34 ;
struct V_6 * V_7 = V_15 -> V_7 ;
F_10 ( ! F_7 ( & V_15 -> V_44 ) ) ;
F_28 ( & V_7 -> V_100 ) ;
V_18 = F_57 ( V_15 , false , V_42 , V_79 ) ;
F_27 ( & V_7 -> V_100 ) ;
if ( V_18 )
return V_18 ;
V_34 . V_68 = V_15 -> V_68 ;
V_34 . V_152 = V_34 . V_68 << V_69 ;
V_34 . V_153 = V_15 -> V_34 . V_153 ;
V_34 . V_124 . V_125 = false ;
V_34 . V_124 . V_126 = 0 ;
V_18 = F_75 ( V_15 , V_17 , & V_34 , V_42 , V_78 , V_79 ) ;
if ( V_18 )
goto V_110;
V_18 = F_43 ( V_15 , & V_34 , false , V_42 , V_78 , V_79 ) ;
V_110:
if ( V_18 && V_34 . V_35 )
F_54 ( V_15 , & V_34 ) ;
return V_18 ;
}
static int F_83 ( struct V_16 * V_17 ,
struct V_76 * V_34 )
{
int V_3 ;
if ( V_34 -> V_35 && V_17 -> V_128 != 0 &&
( V_34 -> V_95 < V_17 -> V_127 ||
V_34 -> V_95 + V_34 -> V_68 > V_17 -> V_128 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_17 -> V_19 ; V_3 ++ ) {
if ( ( V_17 -> V_17 [ V_3 ] & V_34 -> V_17 &
V_84 ) &&
( V_17 -> V_17 [ V_3 ] & V_34 -> V_17 &
V_143 ) )
return V_3 ;
}
return - 1 ;
}
int F_84 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_42 , bool V_78 ,
bool V_79 )
{
int V_18 ;
F_10 ( ! F_7 ( & V_15 -> V_44 ) ) ;
if ( V_17 -> V_128 || V_17 -> V_127 )
if ( V_17 -> V_127 > V_17 -> V_128 ||
( V_17 -> V_128 - V_17 -> V_127 ) < V_15 -> V_68 )
return - V_5 ;
V_18 = F_83 ( V_17 , & V_15 -> V_34 ) ;
if ( V_18 < 0 ) {
V_18 = F_82 ( V_15 , V_17 , V_42 , V_78 , V_79 ) ;
if ( V_18 )
return V_18 ;
} else {
F_80 ( & V_15 -> V_34 . V_17 , V_17 -> V_17 [ V_18 ] ,
~ V_148 ) ;
}
if ( V_15 -> V_34 . V_2 == V_10 && V_15 -> V_38 == NULL ) {
V_18 = F_39 ( V_15 , true ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
int F_85 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
F_10 ( ( V_17 -> V_127 || V_17 -> V_128 ) &&
( V_15 -> V_34 . V_68 > ( V_17 -> V_128 - V_17 -> V_127 ) ) ) ;
return 0 ;
}
int F_86 ( struct V_6 * V_7 ,
struct V_14 * V_15 ,
unsigned long V_152 ,
enum V_154 type ,
struct V_16 * V_17 ,
T_1 V_153 ,
unsigned long V_75 ,
bool V_42 ,
struct V_155 * V_156 ,
T_3 V_41 ,
void (* V_39) ( struct V_14 * ) )
{
int V_18 = 0 ;
unsigned long V_68 ;
V_152 += V_75 & ~ V_157 ;
V_68 = ( V_152 + V_27 - 1 ) >> V_69 ;
if ( V_68 == 0 ) {
F_3 (KERN_ERR TTM_PFX L_18 ) ;
if ( V_39 )
(* V_39)( V_15 ) ;
else
F_15 ( V_15 ) ;
return - V_5 ;
}
V_15 -> V_39 = V_39 ;
F_87 ( & V_15 -> V_29 ) ;
F_87 ( & V_15 -> V_30 ) ;
F_37 ( & V_15 -> V_32 , 0 ) ;
F_37 ( & V_15 -> V_44 , 1 ) ;
F_88 ( & V_15 -> V_43 ) ;
F_89 ( & V_15 -> V_36 ) ;
F_89 ( & V_15 -> V_37 ) ;
F_89 ( & V_15 -> V_46 ) ;
F_89 ( & V_15 -> V_158 ) ;
V_15 -> V_7 = V_7 ;
V_15 -> V_26 = V_7 -> V_26 ;
V_15 -> type = type ;
V_15 -> V_68 = V_68 ;
V_15 -> V_34 . V_152 = V_68 << V_69 ;
V_15 -> V_34 . V_2 = V_10 ;
V_15 -> V_34 . V_68 = V_15 -> V_68 ;
V_15 -> V_34 . V_35 = NULL ;
V_15 -> V_34 . V_153 = V_153 ;
V_15 -> V_34 . V_124 . V_125 = false ;
V_15 -> V_34 . V_124 . V_126 = 0 ;
V_15 -> V_75 = V_75 & V_157 ;
V_15 -> V_159 = 0 ;
V_15 -> V_34 . V_17 = ( V_160 | V_137 ) ;
V_15 -> V_52 = false ;
V_15 -> V_156 = V_156 ;
V_15 -> V_41 = V_41 ;
F_90 ( & V_15 -> V_26 -> V_28 ) ;
V_18 = F_85 ( V_15 , V_17 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_85;
if ( V_15 -> type == V_65 ) {
V_18 = F_91 ( V_15 ) ;
if ( V_18 )
goto V_85;
}
V_18 = F_84 ( V_15 , V_17 , V_42 , false , false ) ;
if ( V_18 )
goto V_85;
F_38 ( V_15 ) ;
return 0 ;
V_85:
F_38 ( V_15 ) ;
F_70 ( & V_15 ) ;
return V_18 ;
}
static inline T_3 F_92 ( struct V_25 * V_26 ,
unsigned long V_68 )
{
T_3 V_161 = ( V_68 * sizeof( void * ) + V_27 - 1 ) &
V_157 ;
return V_26 -> F_92 + 2 * V_161 ;
}
int F_93 ( struct V_6 * V_7 ,
unsigned long V_152 ,
enum V_154 type ,
struct V_16 * V_17 ,
T_1 V_153 ,
unsigned long V_75 ,
bool V_42 ,
struct V_155 * V_156 ,
struct V_14 * * V_120 )
{
struct V_14 * V_15 ;
struct V_162 * V_40 = V_7 -> V_26 -> V_40 ;
int V_18 ;
T_3 V_41 =
F_92 ( V_7 -> V_26 , ( V_152 + V_27 - 1 ) >> V_69 ) ;
V_18 = F_94 ( V_40 , V_41 , false , false ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
V_15 = F_95 ( sizeof( * V_15 ) , V_163 ) ;
if ( F_25 ( V_15 == NULL ) ) {
F_14 ( V_40 , V_41 ) ;
return - V_71 ;
}
V_18 = F_86 ( V_7 , V_15 , V_152 , type , V_17 , V_153 ,
V_75 , V_42 ,
V_156 , V_41 , NULL ) ;
if ( F_35 ( V_18 == 0 ) )
* V_120 = V_15 ;
return V_18 ;
}
static int F_96 ( struct V_6 * V_7 ,
unsigned V_2 , bool V_164 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_25 * V_26 = V_7 -> V_26 ;
int V_18 ;
F_28 ( & V_26 -> V_57 ) ;
while ( ! F_11 ( & V_9 -> V_36 ) ) {
F_27 ( & V_26 -> V_57 ) ;
V_18 = F_76 ( V_7 , V_2 , false , false , false ) ;
if ( V_18 ) {
if ( V_164 ) {
return V_18 ;
} else {
F_3 (KERN_ERR TTM_PFX
L_19 ) ;
}
}
F_28 ( & V_26 -> V_57 ) ;
}
F_27 ( & V_26 -> V_57 ) ;
return 0 ;
}
int F_97 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 ;
int V_18 = - V_5 ;
if ( V_2 >= V_165 ) {
F_3 (KERN_ERR TTM_PFX L_20 , mem_type) ;
return V_18 ;
}
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_149 ) {
F_3 (KERN_ERR TTM_PFX L_21
L_22 , mem_type) ;
return V_18 ;
}
V_9 -> V_150 = false ;
V_9 -> V_149 = false ;
V_18 = 0 ;
if ( V_2 > 0 ) {
F_96 ( V_7 , V_2 , false ) ;
V_18 = (* V_9 -> V_11 -> V_166 )( V_9 ) ;
}
return V_18 ;
}
int F_98 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( V_2 == 0 || V_2 >= V_165 ) {
F_3 (KERN_ERR TTM_PFX
L_23 ,
mem_type) ;
return - V_5 ;
}
if ( ! V_9 -> V_149 ) {
F_3 (KERN_ERR TTM_PFX
L_24 ,
mem_type) ;
return 0 ;
}
return F_96 ( V_7 , V_2 , true ) ;
}
int F_99 ( struct V_6 * V_7 , unsigned type ,
unsigned long V_167 )
{
int V_18 = - V_5 ;
struct V_8 * V_9 ;
F_10 ( type >= V_165 ) ;
V_9 = & V_7 -> V_9 [ type ] ;
F_10 ( V_9 -> V_149 ) ;
V_9 -> V_168 = true ;
V_9 -> V_169 = false ;
F_100 ( & V_9 -> V_170 ) ;
F_89 ( & V_9 -> V_158 ) ;
V_18 = V_7 -> V_88 -> V_171 ( V_7 , type , V_9 ) ;
if ( V_18 )
return V_18 ;
V_9 -> V_7 = V_7 ;
V_18 = 0 ;
if ( type != V_10 ) {
V_18 = (* V_9 -> V_11 -> V_172 )( V_9 , V_167 ) ;
if ( V_18 )
return V_18 ;
}
V_9 -> V_149 = true ;
V_9 -> V_150 = true ;
V_9 -> V_152 = V_167 ;
F_89 ( & V_9 -> V_36 ) ;
return 0 ;
}
static void F_101 ( struct V_20 * V_21 )
{
struct V_25 * V_26 =
F_6 ( V_21 , struct V_25 , V_21 ) ;
F_102 ( V_26 -> V_40 , & V_26 -> V_173 ) ;
F_103 ( V_26 -> V_70 ) ;
F_15 ( V_26 ) ;
}
void F_104 ( struct V_174 * V_175 )
{
struct V_25 * V_26 = V_175 -> V_176 ;
F_105 ( & V_26 -> V_21 ) ;
F_106 ( & V_26 -> V_21 ) ;
}
int F_107 ( struct V_174 * V_175 )
{
struct V_177 * V_178 =
F_6 ( V_175 , struct V_177 , V_175 ) ;
struct V_25 * V_26 = V_175 -> V_176 ;
int V_18 ;
F_100 ( & V_26 -> V_179 ) ;
F_108 ( & V_26 -> V_57 ) ;
V_26 -> V_40 = V_178 -> V_40 ;
V_26 -> V_70 = F_109 ( V_180 | V_181 ) ;
if ( F_25 ( V_26 -> V_70 == NULL ) ) {
V_18 = - V_71 ;
goto V_182;
}
F_89 ( & V_26 -> V_47 ) ;
F_89 ( & V_26 -> V_183 ) ;
F_110 ( & V_26 -> V_173 , V_184 ) ;
V_18 = F_111 ( V_26 -> V_40 , & V_26 -> V_173 ) ;
if ( F_25 ( V_18 != 0 ) ) {
F_3 (KERN_ERR TTM_PFX
L_25 ) ;
goto V_185;
}
V_26 -> V_186 =
F_112 ( sizeof( struct V_187 ) ) +
F_112 ( sizeof( struct V_188 ) ) ;
V_26 -> F_92 = V_26 -> V_186 +
F_112 ( sizeof( struct V_14 ) ) ;
F_37 ( & V_26 -> V_28 , 0 ) ;
V_18 = F_113 (
& V_26 -> V_21 , & V_189 , F_114 () , L_26 ) ;
if ( F_25 ( V_18 != 0 ) )
F_106 ( & V_26 -> V_21 ) ;
return V_18 ;
V_185:
F_103 ( V_26 -> V_70 ) ;
V_182:
F_15 ( V_26 ) ;
return V_18 ;
}
int F_115 ( struct V_6 * V_7 )
{
int V_18 = 0 ;
unsigned V_3 = V_165 ;
struct V_8 * V_9 ;
struct V_25 * V_26 = V_7 -> V_26 ;
while ( V_3 -- ) {
V_9 = & V_7 -> V_9 [ V_3 ] ;
if ( V_9 -> V_149 ) {
V_9 -> V_150 = false ;
if ( ( V_3 != V_10 ) && F_97 ( V_7 , V_3 ) ) {
V_18 = - V_56 ;
F_3 (KERN_ERR TTM_PFX
L_27
L_28 , i) ;
}
V_9 -> V_149 = false ;
}
}
F_116 ( & V_26 -> V_179 ) ;
F_117 ( & V_7 -> V_183 ) ;
F_118 ( & V_26 -> V_179 ) ;
F_72 ( & V_7 -> V_105 ) ;
while ( F_60 ( V_7 , true ) )
;
F_28 ( & V_26 -> V_57 ) ;
if ( F_11 ( & V_7 -> V_37 ) )
F_119 ( L_29 ) ;
if ( F_11 ( & V_7 -> V_9 [ 0 ] . V_36 ) )
F_119 ( L_30 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_10 ( ! F_120 ( & V_7 -> V_190 ) ) ;
F_69 ( & V_7 -> V_119 ) ;
F_121 ( & V_7 -> V_190 ) ;
F_67 ( & V_7 -> V_119 ) ;
return V_18 ;
}
int F_122 ( struct V_6 * V_7 ,
struct V_25 * V_26 ,
struct V_98 * V_88 ,
T_4 V_191 ,
bool V_63 )
{
int V_18 = - V_5 ;
F_123 ( & V_7 -> V_119 ) ;
V_7 -> V_88 = V_88 ;
memset ( V_7 -> V_9 , 0 , sizeof( V_7 -> V_9 ) ) ;
V_18 = F_99 ( V_7 , V_10 , 0 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_192;
V_7 -> V_118 = V_193 ;
V_18 = F_124 ( & V_7 -> V_190 , V_191 , 0x10000000 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_194;
F_125 ( & V_7 -> V_105 , F_63 ) ;
V_7 -> V_195 = true ;
F_89 ( & V_7 -> V_37 ) ;
V_7 -> V_196 = NULL ;
V_7 -> V_26 = V_26 ;
V_7 -> V_63 = V_63 ;
V_7 -> V_53 = 0 ;
F_108 ( & V_7 -> V_100 ) ;
F_116 ( & V_26 -> V_179 ) ;
F_20 ( & V_7 -> V_183 , & V_26 -> V_183 ) ;
F_118 ( & V_26 -> V_179 ) ;
return 0 ;
V_194:
F_97 ( V_7 , 0 ) ;
V_192:
return V_18 ;
}
bool F_44 ( struct V_6 * V_7 , struct V_76 * V_34 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_34 -> V_2 ] ;
if ( ! ( V_9 -> V_1 & V_86 ) ) {
if ( V_34 -> V_2 == V_10 )
return false ;
if ( V_9 -> V_1 & V_197 )
return false ;
if ( V_34 -> V_17 & V_137 )
return false ;
}
return true ;
}
void F_46 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
T_5 V_94 = ( T_5 ) V_15 -> V_198 ;
T_5 V_199 = ( ( T_5 ) V_15 -> V_34 . V_68 ) << V_69 ;
if ( ! V_7 -> V_196 )
return;
F_126 ( V_7 -> V_196 , V_94 , V_199 , 1 ) ;
F_68 ( V_15 ) ;
}
void F_127 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_15 -> V_34 . V_2 ] ;
F_45 ( V_9 , false ) ;
F_46 ( V_15 ) ;
F_47 ( V_9 ) ;
}
static void F_128 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_200 * * V_201 = & V_7 -> V_118 . V_200 ;
struct V_200 * V_202 = NULL ;
struct V_14 * V_203 ;
unsigned long V_94 = V_15 -> V_116 -> V_95 ;
unsigned long V_204 ;
while ( * V_201 ) {
V_202 = * V_201 ;
V_203 = F_129 ( V_202 , struct V_14 , V_117 ) ;
V_204 = V_203 -> V_116 -> V_95 ;
if ( V_94 < V_204 )
V_201 = & V_202 -> V_205 ;
else if ( V_94 > V_204 )
V_201 = & V_202 -> V_206 ;
else
F_31 () ;
}
F_130 ( & V_15 -> V_117 , V_202 , V_201 ) ;
F_131 ( & V_15 -> V_117 , & V_7 -> V_118 ) ;
}
static int F_91 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
int V_18 ;
V_207:
V_18 = F_132 ( & V_7 -> V_190 ) ;
if ( F_25 ( V_18 != 0 ) )
return V_18 ;
F_69 ( & V_7 -> V_119 ) ;
V_15 -> V_116 = F_133 ( & V_7 -> V_190 ,
V_15 -> V_34 . V_68 , 0 , 0 ) ;
if ( F_25 ( V_15 -> V_116 == NULL ) ) {
V_18 = - V_71 ;
goto V_110;
}
V_15 -> V_116 = F_134 ( V_15 -> V_116 ,
V_15 -> V_34 . V_68 , 0 ) ;
if ( F_25 ( V_15 -> V_116 == NULL ) ) {
F_67 ( & V_7 -> V_119 ) ;
goto V_207;
}
F_128 ( V_15 ) ;
F_67 ( & V_7 -> V_119 ) ;
V_15 -> V_198 = ( ( T_4 ) V_15 -> V_116 -> V_95 ) << V_69 ;
return 0 ;
V_110:
F_67 ( & V_7 -> V_119 ) ;
return V_18 ;
}
int F_57 ( struct V_14 * V_15 ,
bool V_208 , bool V_42 , bool V_49 )
{
struct V_98 * V_88 = V_15 -> V_7 -> V_88 ;
struct V_6 * V_7 = V_15 -> V_7 ;
void * V_33 ;
void * V_99 ;
int V_18 = 0 ;
if ( F_35 ( V_15 -> V_33 == NULL ) )
return 0 ;
while ( V_15 -> V_33 ) {
if ( V_88 -> V_209 ( V_15 -> V_33 , V_15 -> V_99 ) ) {
void * V_210 = V_15 -> V_33 ;
V_15 -> V_33 = NULL ;
F_135 ( V_211 , & V_15 -> V_159 ) ;
F_27 ( & V_7 -> V_100 ) ;
V_88 -> V_104 ( & V_210 ) ;
F_28 ( & V_7 -> V_100 ) ;
continue;
}
if ( V_49 )
return - V_56 ;
V_33 = V_88 -> V_102 ( V_15 -> V_33 ) ;
V_99 = V_15 -> V_99 ;
F_27 ( & V_7 -> V_100 ) ;
V_18 = V_88 -> V_212 ( V_33 , V_99 ,
V_208 , V_42 ) ;
if ( F_25 ( V_18 != 0 ) ) {
V_88 -> V_104 ( & V_33 ) ;
F_28 ( & V_7 -> V_100 ) ;
return V_18 ;
}
F_28 ( & V_7 -> V_100 ) ;
if ( F_35 ( V_15 -> V_33 == V_33 &&
V_15 -> V_99 == V_99 ) ) {
void * V_210 = V_15 -> V_33 ;
V_15 -> V_33 = NULL ;
F_135 ( V_211 ,
& V_15 -> V_159 ) ;
F_27 ( & V_7 -> V_100 ) ;
V_88 -> V_104 ( & V_33 ) ;
V_88 -> V_104 ( & V_210 ) ;
F_28 ( & V_7 -> V_100 ) ;
} else {
F_27 ( & V_7 -> V_100 ) ;
V_88 -> V_104 ( & V_33 ) ;
F_28 ( & V_7 -> V_100 ) ;
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
F_28 ( & V_7 -> V_100 ) ;
V_18 = F_57 ( V_15 , false , true , V_49 ) ;
F_27 ( & V_7 -> V_100 ) ;
if ( F_35 ( V_18 == 0 ) )
F_90 ( & V_15 -> V_32 ) ;
F_38 ( V_15 ) ;
return V_18 ;
}
void F_137 ( struct V_14 * V_15 )
{
if ( F_138 ( & V_15 -> V_32 ) )
F_29 ( & V_15 -> V_43 ) ;
}
static int V_184 ( struct V_213 * V_173 )
{
struct V_25 * V_26 =
F_6 ( V_173 , struct V_25 , V_173 ) ;
struct V_14 * V_15 ;
int V_18 = - V_56 ;
int V_48 ;
T_1 V_214 = ( V_137 | V_160 ) ;
F_28 ( & V_26 -> V_57 ) ;
while ( V_18 == - V_56 ) {
if ( F_25 ( F_11 ( & V_26 -> V_47 ) ) ) {
F_27 ( & V_26 -> V_57 ) ;
return - V_56 ;
}
V_15 = F_61 ( & V_26 -> V_47 ,
struct V_14 , V_46 ) ;
F_21 ( & V_15 -> V_30 ) ;
if ( ! F_11 ( & V_15 -> V_37 ) ) {
F_27 ( & V_26 -> V_57 ) ;
( void ) F_59 ( V_15 , false , false , false ) ;
F_62 ( & V_15 -> V_30 , F_9 ) ;
continue;
}
V_18 = F_24 ( V_15 , false , true , false , 0 ) ;
if ( F_25 ( V_18 == - V_56 ) ) {
F_27 ( & V_26 -> V_57 ) ;
F_16 ( V_15 , false ) ;
F_62 ( & V_15 -> V_30 , F_9 ) ;
F_28 ( & V_26 -> V_57 ) ;
}
}
F_10 ( V_18 != 0 ) ;
V_48 = F_22 ( V_15 ) ;
F_27 ( & V_26 -> V_57 ) ;
F_32 ( V_15 , V_48 , true ) ;
F_28 ( & V_15 -> V_7 -> V_100 ) ;
V_18 = F_57 ( V_15 , false , false , false ) ;
F_27 ( & V_15 -> V_7 -> V_100 ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_113;
if ( ( V_15 -> V_34 . V_17 & V_214 ) != V_214 ) {
struct V_76 V_122 ;
V_122 = V_15 -> V_34 ;
V_122 . V_35 = NULL ;
V_122 . V_17 = V_160 | V_137 ;
V_122 . V_2 = V_10 ;
V_18 = F_43 ( V_15 , & V_122 , true ,
false , false , false ) ;
if ( F_25 ( V_18 != 0 ) )
goto V_113;
}
F_127 ( V_15 ) ;
if ( V_15 -> V_7 -> V_88 -> V_215 )
V_15 -> V_7 -> V_88 -> V_215 ( V_15 ) ;
V_18 = F_139 ( V_15 -> V_38 , V_15 -> V_156 ) ;
V_113:
F_37 ( & V_15 -> V_44 , 0 ) ;
F_29 ( & V_15 -> V_43 ) ;
F_62 ( & V_15 -> V_30 , F_9 ) ;
return V_18 ;
}
void F_140 ( struct V_6 * V_7 )
{
while ( V_184 ( & V_7 -> V_26 -> V_173 ) == 0 )
;
}
