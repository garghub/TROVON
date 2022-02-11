T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_3 ( V_3 -> V_4 ) ;
}
const struct V_5 * F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return & V_3 -> V_6 ;
}
enum V_7 F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
static int F_6 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
if ( V_9 -> V_12 )
return - V_13 ;
if ( ( V_9 -> V_14 & V_11 -> V_15 ) == 0 )
return - V_13 ;
V_11 -> V_16 = V_9 ;
V_9 -> V_12 = V_11 ;
return 0 ;
}
static void F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
V_9 -> V_12 -> V_16 = NULL ;
V_9 -> V_12 = NULL ;
}
static void F_8 ( struct V_8 * V_9 )
{
}
static void F_9 ( struct V_1 * V_2 , bool V_17 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_7 V_4 = V_3 -> V_4 ;
struct V_20 * V_21 ;
T_2 V_22 , V_23 ;
int V_24 ;
if ( F_10 ( V_4 ) == V_17 )
return;
if ( V_3 -> V_4 == V_25 ) {
V_3 -> V_26 = true ;
}
V_22 = F_11 ( V_4 ) ;
V_23 = F_3 ( V_4 ) ;
if ( V_17 ) {
V_21 = F_12 ( V_19 , V_23 , 1 ) ;
} else {
if ( V_22 )
V_21 = F_12 ( V_19 , V_22 , 1 ) ;
else
V_21 = F_12 ( V_19 , V_23 , 2 ) ;
}
F_13 ( V_4 , V_17 ) ;
V_24 = V_20 ( V_19 , V_21 , F_14 ( 100 ) ) ;
if ( V_24 ) {
F_15 ( V_19 -> V_19 , L_1 ,
V_3 -> V_27 , V_17 ? L_2 : L_3 ) ;
}
if ( V_3 -> V_4 == V_25 ) {
V_3 -> V_26 = false ;
F_16 () ;
}
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_3 * V_3 = V_28 [ V_9 -> V_15 ] ;
F_18 ( V_3 -> V_4 , & V_3 -> V_29 ) ;
F_19 ( V_3 -> V_4 ,
& V_3 -> V_6 ) ;
F_9 ( & V_3 -> V_30 , true ) ;
return 0 ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_3 * V_3 = V_28 [ V_9 -> V_15 ] ;
F_9 ( & V_3 -> V_30 , false ) ;
}
static void F_21 ( struct V_8 * V_9 ,
const struct V_5 * V_6 )
{
struct V_3 * V_3 = V_28 [ V_9 -> V_15 ] ;
F_22 ( L_4 , V_3 -> V_27 ) ;
V_3 -> V_6 = * V_6 ;
}
static void F_23 ( struct V_8 * V_9 ,
const struct V_31 * V_32 )
{
struct V_3 * V_3 = V_28 [ V_9 -> V_15 ] ;
F_22 ( L_4 , V_3 -> V_27 ) ;
F_24 ( V_3 -> V_4 , V_32 ) ;
}
static int F_25 (
struct V_8 * V_9 ,
void (* F_26)( void * ) , void * V_33 )
{
return 0 ;
}
static void F_27 (
struct V_8 * V_9 ,
void (* F_26)( void * ) , void * V_33 )
{
}
static void F_28 ( struct V_34 * V_35 , T_1 V_36 )
{
struct V_3 * V_3 =
F_29 ( V_35 , struct V_3 , V_37 ) ;
if ( V_3 -> V_26 ) {
V_36 &= ~ V_38 ;
if ( ! V_36 )
return;
}
F_30 ( L_5 , V_3 -> V_27 , V_36 ) ;
}
static void F_31 ( struct V_34 * V_35 , T_1 V_36 )
{
struct V_3 * V_3 =
F_29 ( V_35 , struct V_3 , V_39 ) ;
struct V_1 * V_2 = & V_3 -> V_30 ;
if ( ! F_32 ( V_3 -> V_4 ) ) {
struct V_40 * V_41 =
V_2 -> V_19 -> V_42 ;
F_22 ( L_6 , V_3 -> V_27 ) ;
F_33 ( V_2 -> V_19 , & V_3 -> V_39 ) ;
F_34 ( V_41 -> V_43 , & V_3 -> V_44 ) ;
}
}
static void F_35 ( struct V_45 * V_46 )
{
struct V_3 * V_3 =
F_29 ( V_46 , struct V_3 , V_44 ) ;
struct V_1 * V_2 = & V_3 -> V_30 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_47 * V_48 , * V_49 ;
bool V_50 ;
F_36 ( & V_2 -> V_51 , NULL ) ;
F_37 () ;
if ( V_3 -> V_39 . V_52 )
goto V_53;
F_38 (apply, n,
&omap_crtc->pending_applies, pending_node) {
V_48 -> V_54 ( V_48 ) ;
F_39 ( & V_48 -> V_55 ) ;
}
V_50 = ! F_40 ( & V_3 -> V_56 ) ;
F_38 (apply, n,
&omap_crtc->queued_applies, queued_node) {
V_48 -> V_57 ( V_48 ) ;
F_39 ( & V_48 -> V_58 ) ;
V_48 -> V_59 = false ;
F_41 ( & V_48 -> V_55 ,
& V_3 -> V_60 ) ;
}
if ( V_50 ) {
enum V_7 V_4 = V_3 -> V_4 ;
F_22 ( L_7 , V_3 -> V_27 ) ;
if ( F_10 ( V_4 ) ) {
F_42 ( V_4 ) ;
F_43 ( V_19 , & V_3 -> V_39 ) ;
} else {
struct V_40 * V_41 = V_19 -> V_42 ;
F_34 ( V_41 -> V_43 , & V_3 -> V_44 ) ;
}
}
V_53:
F_44 () ;
F_45 ( & V_2 -> V_51 ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_47 ( ! F_48 ( & V_2 -> V_51 ) ) ;
if ( V_48 -> V_59 )
return 0 ;
V_48 -> V_59 = true ;
F_41 ( & V_48 -> V_58 , & V_3 -> V_56 ) ;
if ( F_40 ( & V_3 -> V_60 ) ) {
struct V_40 * V_41 = V_2 -> V_19 -> V_42 ;
F_34 ( V_41 -> V_43 , & V_3 -> V_44 ) ;
}
return 0 ;
}
static void F_49 ( struct V_47 * V_48 )
{
struct V_3 * V_3 =
F_29 ( V_48 , struct V_3 , V_48 ) ;
struct V_1 * V_2 = & V_3 -> V_30 ;
struct V_40 * V_41 = V_2 -> V_19 -> V_42 ;
struct V_61 * V_62 = NULL ;
unsigned int V_63 ;
F_22 ( L_8 , V_3 -> V_27 , V_3 -> V_64 ) ;
for ( V_63 = 0 ; V_63 < V_41 -> V_65 ; V_63 ++ ) {
if ( V_41 -> V_66 [ V_63 ] -> V_2 == V_2 ) {
V_62 = V_41 -> V_66 [ V_63 ] ;
break;
}
}
if ( V_3 -> V_67 && V_62 != V_3 -> V_67 )
F_50 ( V_3 -> V_67 , false ) ;
V_3 -> V_67 = V_62 ;
if ( ! V_3 -> V_64 ) {
if ( V_62 )
F_50 ( V_62 , false ) ;
} else {
if ( V_62 ) {
F_50 ( V_62 , false ) ;
F_51 ( V_62 , V_3 -> V_9 ,
& V_3 -> V_6 ) ;
F_50 ( V_62 , true ) ;
}
}
}
static void F_52 ( struct V_47 * V_48 )
{
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_68 = 0 ;
while ( ! F_40 ( & V_3 -> V_60 ) ||
! F_40 ( & V_3 -> V_56 ) ||
V_3 -> V_69 || V_3 -> V_70 ) {
if ( ++ V_68 > 10 ) {
F_15 ( V_2 -> V_19 -> V_19 ,
L_9 ) ;
break;
}
F_54 ( F_14 ( 20 ) ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_22 ( L_4 , V_3 -> V_27 ) ;
F_47 ( V_3 -> V_39 . V_52 ) ;
F_56 ( V_2 -> V_19 , & V_3 -> V_37 ) ;
F_57 ( V_2 ) ;
F_58 ( V_3 ) ;
}
static void F_59 ( struct V_1 * V_2 , int V_71 )
{
struct V_40 * V_41 = V_2 -> V_19 -> V_42 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_64 = ( V_71 == V_72 ) ;
int V_63 ;
F_22 ( L_10 , V_3 -> V_27 , V_71 ) ;
if ( V_64 != V_3 -> V_64 ) {
V_3 -> V_64 = V_64 ;
F_46 ( V_2 , & V_3 -> V_48 ) ;
for ( V_63 = 0 ; V_63 < V_41 -> V_73 ; V_63 ++ ) {
struct V_74 * V_75 = V_41 -> V_76 [ V_63 ] ;
if ( V_75 -> V_2 == V_2 )
F_47 ( F_60 ( V_75 , V_64 ) ) ;
}
}
}
static bool F_61 ( struct V_1 * V_2 ,
const struct V_77 * V_71 ,
struct V_77 * V_78 )
{
return true ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_77 * V_71 ,
struct V_77 * V_78 ,
int V_79 , int V_80 ,
struct V_81 * V_70 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_71 = V_78 ;
F_22 ( L_11 ,
V_3 -> V_27 , V_71 -> V_30 . V_15 , V_71 -> V_27 ,
V_71 -> V_82 , V_71 -> clock ,
V_71 -> V_83 , V_71 -> V_84 ,
V_71 -> V_85 , V_71 -> V_86 ,
V_71 -> V_87 , V_71 -> V_88 ,
V_71 -> V_89 , V_71 -> V_90 ,
V_71 -> type , V_71 -> V_91 ) ;
F_63 ( & V_3 -> V_6 , V_71 ) ;
V_2 -> V_92 -> V_2 = V_2 ;
return F_64 ( V_2 -> V_92 , V_2 , V_2 -> V_92 -> V_93 ,
0 , 0 , V_71 -> V_83 , V_71 -> V_87 ,
V_79 , V_80 , V_71 -> V_83 , V_71 -> V_87 ,
NULL , NULL ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_22 ( L_4 , V_3 -> V_27 ) ;
F_59 ( V_2 , V_94 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_22 ( L_4 , V_3 -> V_27 ) ;
F_59 ( V_2 , V_72 ) ;
}
static int F_67 ( struct V_1 * V_2 , int V_79 , int V_80 ,
struct V_81 * V_70 )
{
struct V_74 * V_75 = V_2 -> V_92 ;
struct V_77 * V_71 = & V_2 -> V_71 ;
return F_64 ( V_75 , V_2 , V_2 -> V_92 -> V_93 ,
0 , 0 , V_71 -> V_83 , V_71 -> V_87 ,
V_79 , V_80 , V_71 -> V_83 , V_71 -> V_87 ,
NULL , NULL ) ;
}
static void F_68 ( void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_91 ;
struct V_81 * V_93 ;
F_69 ( & V_19 -> V_96 , V_91 ) ;
if ( V_3 -> V_69 )
F_70 ( V_19 , V_3 -> V_97 , V_3 -> V_69 ) ;
V_93 = V_3 -> V_70 ;
V_3 -> V_69 = NULL ;
V_3 -> V_70 = NULL ;
F_71 ( & V_19 -> V_96 , V_91 ) ;
if ( V_93 )
F_72 ( V_93 ) ;
}
static void F_73 ( struct V_45 * V_46 )
{
struct V_3 * V_3 =
F_29 ( V_46 , struct V_3 , V_98 ) ;
struct V_1 * V_2 = & V_3 -> V_30 ;
struct V_77 * V_71 = & V_2 -> V_71 ;
struct V_99 * V_100 ;
F_36 ( & V_2 -> V_51 , NULL ) ;
F_64 ( V_2 -> V_92 , V_2 , V_2 -> V_92 -> V_93 ,
0 , 0 , V_71 -> V_83 , V_71 -> V_87 ,
V_2 -> V_79 , V_2 -> V_80 , V_71 -> V_83 , V_71 -> V_87 ,
F_68 , V_2 ) ;
F_45 ( & V_2 -> V_51 ) ;
V_100 = F_74 ( V_2 -> V_92 -> V_93 , 0 ) ;
F_75 ( V_100 ) ;
}
static void F_76 ( void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_40 * V_41 = V_2 -> V_19 -> V_42 ;
F_34 ( V_41 -> V_43 , & V_3 -> V_98 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_81 * V_93 ,
struct V_101 * V_69 ,
T_1 V_102 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_74 * V_92 = V_2 -> V_92 ;
struct V_99 * V_100 ;
unsigned long V_91 ;
F_22 ( L_12 , V_92 -> V_93 ? V_92 -> V_93 -> V_30 . V_15 : - 1 ,
V_93 -> V_30 . V_15 , V_69 ) ;
F_69 ( & V_19 -> V_96 , V_91 ) ;
if ( V_3 -> V_70 ) {
F_71 ( & V_19 -> V_96 , V_91 ) ;
F_15 ( V_19 -> V_19 , L_13 ) ;
return - V_103 ;
}
V_3 -> V_69 = V_69 ;
V_3 -> V_70 = V_92 -> V_93 = V_93 ;
F_78 ( V_3 -> V_70 ) ;
F_71 ( & V_19 -> V_96 , V_91 ) ;
V_100 = F_74 ( V_93 , 0 ) ;
F_79 ( V_100 ) ;
F_80 ( V_100 , V_104 , F_76 , V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_105 * V_106 , T_3 V_107 )
{
struct V_40 * V_41 = V_2 -> V_19 -> V_42 ;
if ( V_106 == V_41 -> V_108 ) {
V_2 -> V_109 =
! ! ( V_107 & ( ( 1LL << V_110 ) | ( 1LL << V_111 ) ) ) ;
}
return F_82 ( V_2 -> V_92 , V_106 , V_107 ) ;
}
void F_83 ( void )
{
F_84 ( & V_112 ) ;
}
void F_85 ( void )
{
F_86 () ;
}
struct V_1 * F_87 ( struct V_18 * V_19 ,
struct V_74 * V_75 , enum V_7 V_4 , int V_15 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
struct V_113 * V_29 ;
int V_24 ;
F_22 ( L_4 , V_114 [ V_4 ] ) ;
V_3 = F_88 ( sizeof( * V_3 ) , V_115 ) ;
if ( ! V_3 )
return NULL ;
V_2 = & V_3 -> V_30 ;
F_89 ( & V_3 -> V_98 , F_73 ) ;
F_89 ( & V_3 -> V_44 , F_35 ) ;
F_90 ( & V_3 -> V_60 ) ;
F_90 ( & V_3 -> V_56 ) ;
V_3 -> V_48 . V_57 = F_49 ;
V_3 -> V_48 . V_54 = F_52 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_27 = V_114 [ V_4 ] ;
V_3 -> V_97 = V_15 ;
V_3 -> V_39 . V_116 = F_1 ( V_2 ) ;
V_3 -> V_39 . V_35 = F_31 ;
V_3 -> V_37 . V_116 =
F_91 ( V_4 ) ;
V_3 -> V_37 . V_35 = F_28 ;
F_43 ( V_19 , & V_3 -> V_37 ) ;
V_3 -> V_9 = F_92 ( V_4 ) ;
V_29 = & V_3 -> V_29 ;
V_29 -> V_117 = 0x00000000 ;
V_29 -> V_118 = 0x00000000 ;
V_29 -> V_119 = V_120 ;
V_29 -> V_121 = false ;
V_24 = F_93 ( V_19 , V_2 , V_75 , NULL ,
& V_122 ) ;
if ( V_24 < 0 ) {
F_58 ( V_3 ) ;
return NULL ;
}
F_94 ( V_2 , & V_123 ) ;
F_95 ( V_2 -> V_92 , & V_2 -> V_30 ) ;
V_28 [ V_4 ] = V_3 ;
return V_2 ;
}
