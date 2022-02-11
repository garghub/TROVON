static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 * V_2 -> V_4 . V_5 + V_2 -> V_4 . V_6 ;
}
static inline bool F_2 ( void )
{
if ( V_7 . V_8 == V_9 &&
V_7 . V_10 == 6 &&
V_7 . V_11 == V_12 ) {
struct V_1 * V_2 = & V_13 [ V_14 ] ;
T_1 V_15 , V_16 , V_17 = F_3 ( 20 ) - 1 ;
if ( F_4 ( V_18 , V_17 , 0 ) )
return false ;
F_5 ( V_18 , V_15 , V_16 ) ;
if ( V_15 != V_17 )
return false ;
V_2 -> V_19 = 4 ;
V_2 -> V_20 = V_17 ;
V_2 -> V_4 . V_21 = 20 ;
V_2 -> V_4 . V_22 = 2 ;
V_2 -> V_23 = true ;
V_2 -> V_24 = true ;
return true ;
}
return false ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
F_7 ( L_1 ,
V_7 . V_10 , V_7 . V_11 ) ;
return false ;
}
static bool F_8 ( struct V_1 * V_2 )
{
union V_25 V_26 ;
union V_27 V_28 ;
T_1 V_29 , V_30 ;
F_9 ( 0x00000010 , 3 , & V_26 . V_31 , & V_29 , & V_30 , & V_28 . V_31 ) ;
V_2 -> V_19 = V_28 . V_32 . V_33 + 1 ;
V_2 -> V_34 . V_35 = V_26 . V_32 . V_35 + 1 ;
V_2 -> V_20 = V_36 ;
if ( V_30 & V_37 ) {
V_2 -> V_34 . V_38 = true ;
V_2 -> V_34 . V_39 = V_36 - V_2 -> V_34 . V_35 ;
V_2 -> V_34 . V_40 = V_36 - V_2 -> V_34 . V_35 ;
} else {
if ( ! F_6 ( V_2 ) )
return false ;
}
V_2 -> V_41 = 3 ;
F_10 ( V_2 ) ;
V_2 -> V_23 = true ;
V_2 -> V_24 = true ;
return true ;
}
static void F_11 ( int V_42 , struct V_1 * V_2 )
{
union V_43 V_26 ;
union V_27 V_28 ;
T_1 V_29 , V_30 ;
F_9 ( 0x00000010 , V_42 , & V_26 . V_31 , & V_29 , & V_30 , & V_28 . V_31 ) ;
V_2 -> V_19 = V_28 . V_32 . V_33 + 1 ;
V_2 -> V_4 . V_21 = V_26 . V_32 . V_21 + 1 ;
V_2 -> V_20 = F_3 ( V_26 . V_32 . V_21 + 1 ) - 1 ;
V_2 -> V_41 = ( V_2 -> V_4 . V_21 + 3 ) / 4 ;
F_12 ( V_2 ) ;
V_2 -> V_23 = true ;
V_2 -> V_24 = true ;
}
static void F_13 ( int type )
{
struct V_1 * V_44 = & V_13 [ V_14 ] ;
struct V_1 * V_2 = & V_13 [ type ] ;
V_2 -> V_19 = V_44 -> V_19 / 2 ;
V_2 -> V_4 . V_21 = V_44 -> V_4 . V_21 ;
V_2 -> V_20 = V_44 -> V_20 ;
V_2 -> V_41 = ( V_2 -> V_4 . V_21 + 3 ) / 4 ;
V_2 -> V_23 = true ;
V_2 -> V_24 = false ;
}
static int F_14 ( int V_45 , int V_46 )
{
struct V_47 * V_48 = F_15 ( V_45 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_50 ; V_49 ++ ) {
if ( V_48 -> V_51 [ V_49 ] . V_46 == V_46 )
return V_48 -> V_51 [ V_49 ] . V_52 ;
}
return - 1 ;
}
static T_1 F_16 ( unsigned long V_53 , struct V_1 * V_2 )
{
if ( V_2 -> V_34 . V_38 )
return V_36 - V_53 ;
F_17 ( L_2 ) ;
return V_2 -> V_20 ;
}
static void
F_18 ( struct V_54 * V_55 , struct V_56 * V_57 , struct V_1 * V_2 )
{
unsigned int V_49 ;
for ( V_49 = V_57 -> V_58 ; V_49 < V_57 -> V_59 ; V_49 ++ )
F_19 ( V_2 -> V_60 + V_49 , F_16 ( V_55 -> V_61 [ V_49 ] , V_2 ) ) ;
}
static void
F_20 ( struct V_54 * V_55 , struct V_56 * V_57 , struct V_1 * V_2 )
{
unsigned int V_49 ;
for ( V_49 = V_57 -> V_58 ; V_49 < V_57 -> V_59 ; V_49 ++ )
F_19 ( V_2 -> V_60 + F_1 ( V_2 , V_49 ) , V_55 -> V_61 [ V_49 ] ) ;
}
void F_21 ( void * V_62 )
{
struct V_56 * V_57 = V_62 ;
struct V_1 * V_2 = V_57 -> V_63 ;
int V_45 = F_22 () ;
struct V_54 * V_55 ;
F_23 (d, &r->domains, list) {
if ( F_24 ( V_45 , & V_55 -> V_64 ) ) {
V_2 -> V_65 ( V_55 , V_57 , V_2 ) ;
return;
}
}
F_17 ( L_3 ,
V_45 , V_2 -> V_66 ) ;
}
static struct V_54 * F_25 ( struct V_1 * V_2 , int V_52 ,
struct V_67 * * V_68 )
{
struct V_54 * V_55 ;
struct V_67 * V_15 ;
if ( V_52 < 0 )
return F_26 ( V_52 ) ;
F_27 (l, &r->domains) {
V_55 = F_28 ( V_15 , struct V_54 , V_69 ) ;
if ( V_52 == V_55 -> V_52 )
return V_55 ;
if ( V_52 < V_55 -> V_52 )
break;
}
if ( V_68 )
* V_68 = V_15 ;
return NULL ;
}
static int F_29 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_56 V_57 ;
T_1 * V_70 ;
int V_49 ;
V_70 = F_30 ( V_2 -> V_19 , sizeof( * V_55 -> V_61 ) , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
V_55 -> V_61 = V_70 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_19 ; V_49 ++ , V_70 ++ )
* V_70 = V_2 -> V_20 ;
V_57 . V_58 = 0 ;
V_57 . V_59 = V_2 -> V_19 ;
V_2 -> V_65 ( V_55 , & V_57 , V_2 ) ;
return 0 ;
}
static void F_31 ( int V_45 , struct V_1 * V_2 )
{
int V_52 = F_14 ( V_45 , V_2 -> V_73 ) ;
struct V_67 * V_74 = NULL ;
struct V_54 * V_55 ;
V_55 = F_25 ( V_2 , V_52 , & V_74 ) ;
if ( F_32 ( V_55 ) ) {
F_33 ( L_4 , V_45 ) ;
return;
}
if ( V_55 ) {
F_34 ( V_45 , & V_55 -> V_64 ) ;
return;
}
V_55 = F_35 ( sizeof( * V_55 ) , V_71 , F_36 ( V_45 ) ) ;
if ( ! V_55 )
return;
V_55 -> V_52 = V_52 ;
if ( F_29 ( V_2 , V_55 ) ) {
F_37 ( V_55 ) ;
return;
}
F_34 ( V_45 , & V_55 -> V_64 ) ;
F_38 ( & V_55 -> V_69 , V_74 ) ;
}
static void F_39 ( int V_45 , struct V_1 * V_2 )
{
int V_52 = F_14 ( V_45 , V_2 -> V_73 ) ;
struct V_54 * V_55 ;
V_55 = F_25 ( V_2 , V_52 , NULL ) ;
if ( F_40 ( V_55 ) ) {
F_33 ( L_4 , V_45 ) ;
return;
}
F_41 ( V_45 , & V_55 -> V_64 ) ;
if ( F_42 ( & V_55 -> V_64 ) ) {
F_37 ( V_55 -> V_61 ) ;
F_43 ( & V_55 -> V_69 ) ;
F_37 ( V_55 ) ;
}
}
static void F_44 ( int V_45 )
{
struct V_75 * V_76 = F_45 ( & V_77 ) ;
F_46 ( V_78 , V_45 ) = 0 ;
V_76 -> V_3 = 0 ;
F_47 ( V_79 , V_76 -> V_80 , 0 ) ;
}
static int F_48 ( unsigned int V_45 )
{
struct V_1 * V_2 ;
F_49 ( & V_81 ) ;
F_50 (r)
F_31 ( V_45 , V_2 ) ;
F_34 ( V_45 , & V_82 . V_64 ) ;
F_44 ( V_45 ) ;
F_51 ( & V_81 ) ;
return 0 ;
}
static int F_52 ( unsigned int V_45 )
{
struct V_83 * V_84 ;
struct V_1 * V_2 ;
F_49 ( & V_81 ) ;
F_50 (r)
F_39 ( V_45 , V_2 ) ;
F_23 (rdtgrp, &rdt_all_groups, rdtgroup_list) {
if ( F_53 ( V_45 , & V_84 -> V_64 ) )
break;
}
F_44 ( V_45 ) ;
F_51 ( & V_81 ) ;
return 0 ;
}
static T_2 void F_54 ( void )
{
struct V_1 * V_2 ;
int V_85 ;
F_50 (r) {
V_85 = strlen ( V_2 -> V_66 ) ;
if ( V_85 > V_86 )
V_86 = V_85 ;
if ( V_2 -> V_41 > V_87 )
V_87 = V_2 -> V_41 ;
}
}
static T_2 bool F_55 ( void )
{
bool V_88 = false ;
if ( F_2 () )
return true ;
if ( ! F_56 ( V_89 ) )
return false ;
if ( F_56 ( V_90 ) ) {
F_11 ( 1 , & V_13 [ V_14 ] ) ;
if ( F_56 ( V_91 ) ) {
F_13 ( V_92 ) ;
F_13 ( V_93 ) ;
}
V_88 = true ;
}
if ( F_56 ( V_94 ) ) {
F_11 ( 2 , & V_13 [ V_95 ] ) ;
V_88 = true ;
}
if ( F_56 ( V_96 ) ) {
if ( F_8 ( & V_13 [ V_97 ] ) )
V_88 = true ;
}
return V_88 ;
}
static int T_2 F_57 ( void )
{
struct V_1 * V_2 ;
int V_76 , V_88 ;
if ( ! F_55 () )
return - V_98 ;
F_54 () ;
V_76 = F_58 ( V_99 ,
L_5 ,
F_48 , F_52 ) ;
if ( V_76 < 0 )
return V_76 ;
V_88 = F_59 () ;
if ( V_88 ) {
F_60 ( V_76 ) ;
return V_88 ;
}
F_50 (r)
F_7 ( L_6 , V_2 -> V_66 ) ;
return 0 ;
}
