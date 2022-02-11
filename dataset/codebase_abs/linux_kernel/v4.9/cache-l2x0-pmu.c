static int F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( ! V_3 [ V_1 ] )
return V_1 ;
}
return - 1 ;
}
static int F_2 ( void )
{
int V_1 , V_4 = 0 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] )
V_4 ++ ;
}
return V_4 ;
}
static void F_3 ( int V_5 , T_1 V_6 )
{
F_4 ( V_6 , V_7 + V_8 - 4 * V_5 ) ;
}
static T_1 F_5 ( int V_5 )
{
return F_6 ( V_7 + V_9 - 4 * V_5 ) ;
}
static void F_7 ( int V_5 , T_1 V_6 )
{
F_4 ( V_6 , V_7 + V_9 - 4 * V_5 ) ;
}
static void F_8 ( void )
{
T_1 V_6 = F_6 ( V_7 + V_10 ) ;
V_6 |= V_11 ;
F_4 ( V_6 , V_7 + V_10 ) ;
}
static void F_9 ( void )
{
T_1 V_6 = F_6 ( V_7 + V_10 ) ;
V_6 &= ~ V_11 ;
F_4 ( V_6 , V_7 + V_10 ) ;
}
static void F_10 ( struct V_12 * V_12 )
{
if ( F_2 () == 0 )
return;
F_8 () ;
}
static void F_11 ( struct V_12 * V_12 )
{
if ( F_2 () == 0 )
return;
F_9 () ;
}
static void F_12 ( T_1 V_13 )
{
if ( V_13 != 0xffffffff )
return;
F_13 ( L_1 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
T_2 V_18 , V_19 , V_20 ;
do {
V_18 = F_15 ( & V_17 -> V_18 ) ;
V_19 = F_5 ( V_17 -> V_5 ) ;
} while ( F_16 ( & V_17 -> V_18 , V_19 ) != V_18 );
V_20 = F_17 ( 31 , 0 ) ;
F_18 ( ( V_19 - V_18 ) & V_20 , & V_15 -> V_13 ) ;
F_12 ( V_19 ) ;
}
static void F_19 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
F_20 ( & V_17 -> V_18 , 0 ) ;
F_7 ( V_17 -> V_5 , 0 ) ;
}
static enum V_21 F_21 ( struct V_22 * V_22 )
{
unsigned long V_23 ;
int V_1 ;
F_22 ( V_23 ) ;
F_9 () ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
struct V_14 * V_15 = V_3 [ V_1 ] ;
if ( ! V_15 )
continue;
F_14 ( V_15 ) ;
F_19 ( V_15 ) ;
}
F_8 () ;
F_23 ( V_23 ) ;
F_24 ( V_22 , V_24 ) ;
return V_25 ;
}
static void F_25 ( int V_5 , T_1 V_15 )
{
T_1 V_6 ;
V_6 = V_15 << V_26 ;
V_6 |= V_27 ;
F_3 ( V_5 , V_6 ) ;
}
static void F_26 ( struct V_14 * V_15 , int V_23 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
if ( F_27 ( ! ( V_15 -> V_17 . V_28 & V_29 ) ) )
return;
if ( V_23 & V_30 ) {
F_27 ( ! ( V_17 -> V_28 & V_31 ) ) ;
F_19 ( V_15 ) ;
}
V_17 -> V_28 = 0 ;
F_25 ( V_17 -> V_5 , V_17 -> V_32 ) ;
}
static void F_28 ( int V_5 )
{
T_1 V_6 ;
V_6 = V_33 << V_26 ;
V_6 |= V_27 ;
F_3 ( V_5 , V_6 ) ;
}
static void F_29 ( struct V_14 * V_15 , int V_23 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
if ( F_27 ( V_15 -> V_17 . V_28 & V_29 ) )
return;
F_28 ( V_17 -> V_5 ) ;
V_17 -> V_28 |= V_29 ;
if ( V_23 & V_34 ) {
F_14 ( V_15 ) ;
V_17 -> V_28 |= V_31 ;
}
}
static int F_30 ( struct V_14 * V_15 , int V_23 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
int V_5 = F_1 () ;
if ( V_5 == - 1 )
return - V_35 ;
if ( F_2 () == 0 )
F_31 ( & V_36 , V_24 ,
V_37 ) ;
V_3 [ V_5 ] = V_15 ;
V_17 -> V_5 = V_5 ;
F_19 ( V_15 ) ;
V_17 -> V_28 = V_29 | V_31 ;
if ( V_23 & V_38 )
F_26 ( V_15 , 0 ) ;
return 0 ;
}
static void F_32 ( struct V_14 * V_15 , int V_23 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
F_29 ( V_15 , V_34 ) ;
V_3 [ V_17 -> V_5 ] = NULL ;
V_17 -> V_5 = - 1 ;
if ( F_2 () == 0 )
F_33 ( & V_36 ) ;
}
static bool F_34 ( struct V_14 * V_15 )
{
struct V_12 * V_12 = V_15 -> V_12 ;
struct V_14 * V_39 = V_15 -> V_40 ;
struct V_14 * V_41 ;
int V_42 = 0 ;
if ( V_39 -> V_12 == V_12 )
V_42 ++ ;
else if ( ! F_35 ( V_39 ) )
return false ;
F_36 (sibling, &leader->sibling_list, group_entry) {
if ( V_41 -> V_12 == V_12 )
V_42 ++ ;
else if ( ! F_35 ( V_41 ) )
return false ;
}
return V_42 <= V_2 ;
}
static int F_37 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
if ( V_15 -> V_43 . type != V_44 -> type )
return - V_45 ;
if ( F_38 ( V_15 ) ||
V_15 -> V_46 & V_47 )
return - V_48 ;
if ( V_15 -> V_43 . V_49 ||
V_15 -> V_43 . V_50 ||
V_15 -> V_43 . V_51 ||
V_15 -> V_43 . V_52 ||
V_15 -> V_43 . V_53 ||
V_15 -> V_43 . V_54 )
return - V_48 ;
if ( V_15 -> V_55 < 0 )
return - V_48 ;
if ( V_15 -> V_43 . V_56 & ~ V_57 )
return - V_48 ;
V_17 -> V_32 = V_15 -> V_43 . V_56 ;
if ( ! F_34 ( V_15 ) )
return - V_48 ;
V_15 -> V_55 = F_39 ( & V_58 ) ;
return 0 ;
}
static T_3 F_40 ( struct V_59 * V_60 ,
struct V_61 * V_43 , char * V_62 )
{
struct V_63 * V_64 ;
V_64 = F_41 ( V_43 , F_42 ( * V_64 ) , V_43 ) ;
return snprintf ( V_62 , V_65 , L_2 , V_64 -> V_56 ) ;
}
static T_4 F_43 ( struct V_66 * V_67 ,
struct V_68 * V_43 ,
int V_69 )
{
struct V_59 * V_60 = F_44 ( V_67 ) ;
struct V_12 * V_12 = F_45 ( V_60 ) ;
struct V_63 * V_64 ;
V_64 = F_41 ( V_43 , F_42 ( * V_64 ) , V_43 . V_43 ) ;
if ( ! V_64 -> V_70 || strcmp ( L_3 , V_12 -> V_71 ) == 0 )
return V_43 -> V_72 ;
return 0 ;
}
static T_3 F_46 ( struct V_59 * V_60 ,
struct V_61 * V_43 , char * V_62 )
{
return F_47 ( true , V_62 , & V_58 ) ;
}
static void F_48 ( void )
{
int V_1 ;
F_9 () ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_28 ( V_1 ) ;
}
static int F_49 ( unsigned int V_55 )
{
unsigned int V_73 ;
if ( ! F_50 ( V_55 , & V_58 ) )
return 0 ;
V_73 = F_51 ( V_74 , V_55 ) ;
if ( V_73 >= V_75 )
return 0 ;
F_52 ( V_44 , V_55 , V_73 ) ;
F_53 ( V_73 , & V_58 ) ;
return 0 ;
}
void F_54 ( void )
{
int V_1 ;
if ( ! V_44 )
return;
F_11 ( V_44 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] )
F_29 ( V_3 [ V_1 ] , V_34 ) ;
}
}
void F_55 ( void )
{
int V_1 ;
if ( ! V_44 )
return;
F_48 () ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] )
F_26 ( V_3 [ V_1 ] , V_30 ) ;
}
F_10 ( V_44 ) ;
}
void T_5 F_56 ( void T_6 * V_76 , T_1 V_77 )
{
switch ( V_77 & V_78 ) {
case V_79 :
V_80 = L_4 ;
break;
case V_81 :
V_80 = L_3 ;
break;
default:
return;
}
V_7 = V_76 ;
}
static T_5 int F_57 ( void )
{
int V_82 ;
if ( ! V_7 )
return 0 ;
V_44 = F_58 ( sizeof( * V_44 ) , V_83 ) ;
if ( ! V_44 ) {
F_59 ( L_5 ) ;
return - V_84 ;
}
* V_44 = (struct V_12 ) {
. V_85 = V_86 ,
. V_87 = F_10 ,
. V_88 = F_11 ,
. V_89 = F_14 ,
. V_90 = F_26 ,
. V_91 = F_29 ,
. V_92 = F_30 ,
. V_93 = F_32 ,
. V_94 = F_37 ,
. V_95 = V_96 ,
} ;
F_48 () ;
V_24 = F_60 ( 1000 ) ;
F_61 ( & V_36 , V_97 , V_98 ) ;
V_36 . V_99 = F_21 ;
F_53 ( 0 , & V_58 ) ;
V_82 = F_62 ( V_100 ,
L_6 , NULL ,
F_49 ) ;
if ( V_82 )
goto V_101;
V_82 = F_63 ( V_44 , V_80 , - 1 ) ;
if ( V_82 )
goto V_102;
return 0 ;
V_102:
F_64 ( V_100 ) ;
V_101:
F_65 ( V_44 ) ;
V_44 = NULL ;
return V_82 ;
}
