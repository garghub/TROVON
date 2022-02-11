static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return V_3 * V_2 -> V_4 + V_2 -> V_5 ;
}
static inline bool F_2 ( void )
{
if ( V_6 . V_7 == V_8 &&
V_6 . V_9 == 6 &&
V_6 . V_10 == V_11 ) {
struct V_1 * V_2 = & V_12 [ V_13 ] ;
T_1 V_14 , V_15 , V_16 = F_3 ( 20 ) - 1 ;
if ( F_4 ( V_17 , V_16 , 0 ) )
return false ;
F_5 ( V_17 , V_14 , V_15 ) ;
if ( V_14 != V_16 )
return false ;
V_2 -> V_18 = 4 ;
V_2 -> V_19 = 20 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_20 = 2 ;
V_2 -> V_21 = true ;
V_2 -> V_22 = true ;
return true ;
}
return false ;
}
static void F_6 ( int V_23 , struct V_1 * V_2 )
{
union V_24 V_25 ;
union V_26 V_27 ;
T_1 V_28 , V_29 ;
F_7 ( 0x00000010 , V_23 , & V_25 . V_30 , & V_28 , & V_29 , & V_27 . V_30 ) ;
V_2 -> V_18 = V_27 . V_31 . V_32 + 1 ;
V_2 -> V_19 = V_25 . V_31 . V_19 + 1 ;
V_2 -> V_16 = F_3 ( V_25 . V_31 . V_19 + 1 ) - 1 ;
V_2 -> V_21 = true ;
V_2 -> V_22 = true ;
}
static void F_8 ( int type )
{
struct V_1 * V_33 = & V_12 [ V_13 ] ;
struct V_1 * V_2 = & V_12 [ type ] ;
V_2 -> V_18 = V_33 -> V_18 / 2 ;
V_2 -> V_19 = V_33 -> V_19 ;
V_2 -> V_16 = V_33 -> V_16 ;
V_2 -> V_21 = true ;
V_2 -> V_22 = false ;
}
static inline bool F_9 ( void )
{
bool V_34 = false ;
if ( F_2 () )
return true ;
if ( ! F_10 ( V_35 ) )
return false ;
if ( F_10 ( V_36 ) ) {
F_6 ( 1 , & V_12 [ V_13 ] ) ;
if ( F_10 ( V_37 ) ) {
F_8 ( V_38 ) ;
F_8 ( V_39 ) ;
}
V_34 = true ;
}
if ( F_10 ( V_40 ) ) {
F_6 ( 2 , & V_12 [ V_41 ] ) ;
V_34 = true ;
}
return V_34 ;
}
static int F_11 ( int V_42 , int V_43 )
{
struct V_44 * V_45 = F_12 ( V_42 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_45 -> V_47 ; V_46 ++ ) {
if ( V_45 -> V_48 [ V_46 ] . V_43 == V_43 )
return V_45 -> V_48 [ V_46 ] . V_49 ;
}
return - 1 ;
}
void F_13 ( void * V_50 )
{
struct V_51 * V_52 = (struct V_51 * ) V_50 ;
struct V_1 * V_2 = V_52 -> V_53 ;
int V_46 , V_42 = F_14 () ;
struct V_54 * V_55 ;
F_15 (d, &r->domains, list) {
if ( F_16 ( V_42 , & V_55 -> V_56 ) )
goto V_57;
}
F_17 ( L_1 ,
V_42 , V_2 -> V_58 ) ;
return;
V_57:
for ( V_46 = V_52 -> V_59 ; V_46 < V_52 -> V_60 ; V_46 ++ ) {
int V_23 = F_1 ( V_2 , V_46 ) ;
F_18 ( V_2 -> V_61 + V_23 , V_55 -> V_62 [ V_46 ] ) ;
}
}
static struct V_54 * F_19 ( struct V_1 * V_2 , int V_49 ,
struct V_63 * * V_64 )
{
struct V_54 * V_55 ;
struct V_63 * V_14 ;
if ( V_49 < 0 )
return F_20 ( V_49 ) ;
F_21 (l, &r->domains) {
V_55 = F_22 ( V_14 , struct V_54 , V_65 ) ;
if ( V_49 == V_55 -> V_49 )
return V_55 ;
if ( V_49 < V_55 -> V_49 )
break;
}
if ( V_64 )
* V_64 = V_14 ;
return NULL ;
}
static void F_23 ( int V_42 , struct V_1 * V_2 )
{
int V_46 , V_49 = F_11 ( V_42 , V_2 -> V_66 ) ;
struct V_63 * V_67 = NULL ;
struct V_54 * V_55 ;
V_55 = F_19 ( V_2 , V_49 , & V_67 ) ;
if ( F_24 ( V_55 ) ) {
F_25 ( L_2 , V_42 ) ;
return;
}
if ( V_55 ) {
F_26 ( V_42 , & V_55 -> V_56 ) ;
return;
}
V_55 = F_27 ( sizeof( * V_55 ) , V_68 , F_28 ( V_42 ) ) ;
if ( ! V_55 )
return;
V_55 -> V_49 = V_49 ;
V_55 -> V_62 = F_29 ( V_2 -> V_18 , sizeof( * V_55 -> V_62 ) , V_68 ) ;
if ( ! V_55 -> V_62 ) {
F_30 ( V_55 ) ;
return;
}
for ( V_46 = 0 ; V_46 < V_2 -> V_18 ; V_46 ++ ) {
int V_23 = F_1 ( V_2 , V_46 ) ;
V_55 -> V_62 [ V_46 ] = V_2 -> V_16 ;
F_18 ( V_2 -> V_61 + V_23 , V_55 -> V_62 [ V_46 ] ) ;
}
F_26 ( V_42 , & V_55 -> V_56 ) ;
F_31 ( & V_55 -> V_65 , V_67 ) ;
V_2 -> V_69 ++ ;
}
static void F_32 ( int V_42 , struct V_1 * V_2 )
{
int V_49 = F_11 ( V_42 , V_2 -> V_66 ) ;
struct V_54 * V_55 ;
V_55 = F_19 ( V_2 , V_49 , NULL ) ;
if ( F_33 ( V_55 ) ) {
F_25 ( L_2 , V_42 ) ;
return;
}
F_34 ( V_42 , & V_55 -> V_56 ) ;
if ( F_35 ( & V_55 -> V_56 ) ) {
V_2 -> V_69 -- ;
F_30 ( V_55 -> V_62 ) ;
F_36 ( & V_55 -> V_65 ) ;
F_30 ( V_55 ) ;
}
}
static void F_37 ( int V_42 )
{
struct V_70 * V_71 = F_38 ( & V_72 ) ;
F_39 ( V_73 , V_42 ) = 0 ;
V_71 -> V_3 = 0 ;
F_40 ( V_74 , V_71 -> V_75 , 0 ) ;
}
static int F_41 ( unsigned int V_42 )
{
struct V_1 * V_2 ;
F_42 ( & V_76 ) ;
F_43 (r)
F_23 ( V_42 , V_2 ) ;
F_26 ( V_42 , & V_77 . V_56 ) ;
F_37 ( V_42 ) ;
F_44 ( & V_76 ) ;
return 0 ;
}
static int F_45 ( unsigned int V_42 )
{
struct V_78 * V_79 ;
struct V_1 * V_2 ;
F_42 ( & V_76 ) ;
F_43 (r)
F_32 ( V_42 , V_2 ) ;
F_15 (rdtgrp, &rdt_all_groups, rdtgroup_list) {
if ( F_46 ( V_42 , & V_79 -> V_56 ) )
break;
}
F_37 ( V_42 ) ;
F_44 ( & V_76 ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
struct V_1 * V_2 ;
int V_71 , V_34 ;
if ( ! F_9 () )
return - V_80 ;
V_71 = F_48 ( V_81 ,
L_3 ,
F_41 , F_45 ) ;
if ( V_71 < 0 )
return V_71 ;
V_34 = F_49 () ;
if ( V_34 ) {
F_50 ( V_71 ) ;
return V_34 ;
}
F_43 (r)
F_51 ( L_4 , V_2 -> V_58 ) ;
return 0 ;
}
