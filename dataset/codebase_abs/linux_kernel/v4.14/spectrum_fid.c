static const struct V_1 *
F_1 ( const struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_9 ; V_8 ++ ) {
if ( V_7 -> V_10 [ V_8 ] . V_5 != V_5 )
continue;
return & V_7 -> V_10 [ V_8 ] ;
}
return NULL ;
}
int F_2 ( struct V_2 * V_3 ,
enum V_4 V_5 , T_1 V_11 ,
bool V_12 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
const struct V_13 * V_14 = V_7 -> V_14 ;
const struct V_1 * V_15 ;
char * V_16 ;
int V_17 ;
if ( F_3 ( ! V_7 -> V_10 || ! V_14 -> V_18 ) )
return - V_19 ;
V_15 = F_1 ( V_3 , V_5 ) ;
if ( ! V_15 )
return - V_20 ;
V_16 = F_4 ( V_21 , V_22 ) ;
if ( ! V_16 )
return - V_23 ;
F_5 ( V_16 , V_15 -> V_24 ,
V_14 -> V_18 ( V_3 ) , V_15 -> V_25 , 1 ,
V_11 , V_12 ) ;
V_17 = F_6 ( V_7 -> V_26 -> V_27 , F_7 ( V_28 ) ,
V_16 ) ;
F_8 ( V_16 ) ;
return V_17 ;
}
int F_9 ( struct V_2 * V_3 ,
struct V_29 * V_29 , T_2 V_30 )
{
if ( F_3 ( ! V_3 -> V_7 -> V_14 -> V_31 ) )
return - V_19 ;
return V_3 -> V_7 -> V_14 -> V_31 ( V_3 , V_29 , V_30 ) ;
}
void F_10 ( struct V_2 * V_3 ,
struct V_29 * V_29 , T_2 V_30 )
{
V_3 -> V_7 -> V_14 -> V_32 ( V_3 , V_29 , V_30 ) ;
}
enum V_33 F_11 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 -> V_34 ;
}
T_2 F_12 ( const struct V_2 * V_3 )
{
return V_3 -> V_35 ;
}
enum V_36 V_36 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 -> type ;
}
void F_13 ( struct V_2 * V_3 , struct V_37 * V_38 )
{
V_3 -> V_38 = V_38 ;
}
enum V_33
F_14 ( const struct V_26 * V_26 ,
enum V_36 type )
{
struct V_39 * V_40 = V_26 -> V_40 ;
return V_40 -> V_41 [ type ] -> V_34 ;
}
static struct V_42 *
F_15 ( const struct V_2 * V_3 )
{
return F_16 ( V_3 , struct V_42 , V_43 ) ;
}
T_2 F_17 ( const struct V_2 * V_3 )
{
return F_15 ( V_3 ) -> V_30 ;
}
static void F_18 ( struct V_2 * V_3 , const void * V_44 )
{
T_2 V_30 = * ( T_2 * ) V_44 ;
F_15 ( V_3 ) -> V_30 = V_30 ;
}
static enum V_45 F_19 ( bool V_46 )
{
return V_46 ? V_47 :
V_48 ;
}
static int F_20 ( struct V_26 * V_26 , T_2 V_35 ,
T_2 V_49 , bool V_46 )
{
char V_50 [ V_51 ] ;
F_21 ( V_50 , F_19 ( V_46 ) , V_35 ,
V_49 ) ;
return F_6 ( V_26 -> V_27 , F_7 ( V_52 ) , V_50 ) ;
}
static int F_22 ( struct V_26 * V_26 , T_2 V_35 ,
T_2 V_30 , bool V_46 )
{
enum V_53 V_54 = V_55 ;
char V_56 [ V_57 ] ;
F_23 ( V_56 , 0 , V_54 , V_46 , V_35 , V_30 ) ;
return F_6 ( V_26 -> V_27 , F_7 ( V_58 ) , V_56 ) ;
}
static int F_24 ( struct V_26 * V_26 , T_2 V_35 ,
T_1 V_11 , T_2 V_30 , bool V_46 )
{
enum V_53 V_54 = V_59 ;
char V_56 [ V_57 ] ;
F_23 ( V_56 , V_11 , V_54 , V_46 , V_35 , V_30 ) ;
return F_6 ( V_26 -> V_27 , F_7 ( V_58 ) , V_56 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_26 * V_26 = V_3 -> V_7 -> V_26 ;
struct V_42 * V_60 ;
int V_17 ;
V_17 = F_20 ( V_26 , V_3 -> V_35 , V_3 -> V_35 , true ) ;
if ( V_17 )
return V_17 ;
V_60 = F_15 ( V_3 ) ;
V_17 = F_22 ( V_26 , V_3 -> V_35 , V_60 -> V_30 ,
true ) ;
if ( V_17 )
goto V_61;
return 0 ;
V_61:
F_20 ( V_26 , V_3 -> V_35 , 0 , false ) ;
return V_17 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_26 * V_26 = V_3 -> V_7 -> V_26 ;
struct V_42 * V_60 ;
V_60 = F_15 ( V_3 ) ;
F_22 ( V_26 , V_3 -> V_35 , V_60 -> V_30 , false ) ;
F_20 ( V_26 , V_3 -> V_35 , 0 , false ) ;
}
static int F_27 ( struct V_2 * V_3 ,
const void * V_44 , T_2 * V_62 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
T_2 V_30 = * ( T_2 * ) V_44 ;
if ( V_30 < V_7 -> V_63 || V_30 > V_7 -> V_64 )
return - V_19 ;
* V_62 = V_30 ;
return 0 ;
}
static bool
F_28 ( const struct V_2 * V_3 , const void * V_44 )
{
T_2 V_30 = * ( T_2 * ) V_44 ;
return F_15 ( V_3 ) -> V_30 == V_30 ;
}
static T_2 F_29 ( const struct V_2 * V_3 )
{
return V_3 -> V_35 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_29 * V_29 ,
T_2 V_30 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
T_1 V_11 = V_29 -> V_11 ;
if ( V_26 -> V_40 -> V_65 [ V_11 ] == 0 )
return 0 ;
return F_24 ( V_26 , V_3 -> V_35 , V_11 ,
V_30 , true ) ;
}
static void
F_31 ( struct V_2 * V_3 ,
struct V_29 * V_29 , T_2 V_30 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
T_1 V_11 = V_29 -> V_11 ;
if ( V_26 -> V_40 -> V_65 [ V_11 ] == 0 )
return;
F_24 ( V_26 , V_3 -> V_35 , V_11 , V_30 ,
false ) ;
}
static struct V_66 *
F_32 ( const struct V_2 * V_3 )
{
return F_16 ( V_3 , struct V_66 , V_43 ) ;
}
static void F_33 ( struct V_2 * V_3 , const void * V_44 )
{
int V_67 = * ( int * ) V_44 ;
F_32 ( V_3 ) -> V_67 = V_67 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
return F_20 ( V_7 -> V_26 , V_3 -> V_35 , 0 , true ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_7 -> V_26 , V_3 -> V_35 , 0 , false ) ;
}
static int F_36 ( struct V_2 * V_3 ,
const void * V_44 , T_2 * V_62 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
T_2 V_68 , V_35 ;
V_68 = V_7 -> V_64 - V_7 -> V_63 + 1 ;
V_35 = F_37 ( V_7 -> V_69 , V_68 ) ;
if ( V_35 == V_68 )
return - V_70 ;
* V_62 = V_7 -> V_63 + V_35 ;
return 0 ;
}
static bool
F_38 ( const struct V_2 * V_3 , const void * V_44 )
{
int V_67 = * ( int * ) V_44 ;
return F_32 ( V_3 ) -> V_67 == V_67 ;
}
static T_2 F_39 ( const struct V_2 * V_3 )
{
return V_3 -> V_35 - V_3 -> V_7 -> V_63 ;
}
static int F_40 ( struct V_29 * V_29 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
struct V_71 * V_71 ;
int V_17 ;
F_41 (mlxsw_sp_port_vlan, &mlxsw_sp_port->vlans_list,
list) {
struct V_2 * V_3 = V_71 -> V_3 ;
T_2 V_30 = V_71 -> V_30 ;
if ( ! V_3 )
continue;
V_17 = F_24 ( V_26 , V_3 -> V_35 ,
V_29 -> V_11 ,
V_30 , true ) ;
if ( V_17 )
goto V_72;
}
V_17 = F_42 ( V_29 , true ) ;
if ( V_17 )
goto V_73;
return 0 ;
V_73:
V_72:
F_43 (mlxsw_sp_port_vlan,
&mlxsw_sp_port->vlans_list, list) {
struct V_2 * V_3 = V_71 -> V_3 ;
T_2 V_30 = V_71 -> V_30 ;
if ( ! V_3 )
continue;
F_24 ( V_26 , V_3 -> V_35 ,
V_29 -> V_11 , V_30 ,
false ) ;
}
return V_17 ;
}
static void F_44 ( struct V_29 * V_29 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
struct V_71 * V_71 ;
F_42 ( V_29 , false ) ;
F_45 (mlxsw_sp_port_vlan,
&mlxsw_sp_port->vlans_list, list) {
struct V_2 * V_3 = V_71 -> V_3 ;
T_2 V_30 = V_71 -> V_30 ;
if ( ! V_3 )
continue;
F_24 ( V_26 , V_3 -> V_35 ,
V_29 -> V_11 , V_30 ,
false ) ;
}
}
static int F_46 ( struct V_2 * V_3 ,
struct V_29 * V_29 ,
T_2 V_30 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
T_1 V_11 = V_29 -> V_11 ;
int V_17 ;
V_17 = F_24 ( V_26 , V_3 -> V_35 ,
V_29 -> V_11 , V_30 , true ) ;
if ( V_17 )
return V_17 ;
if ( V_26 -> V_40 -> V_65 [ V_11 ] ++ == 0 ) {
V_17 = F_40 ( V_29 ) ;
if ( V_17 )
goto V_74;
}
return 0 ;
V_74:
V_26 -> V_40 -> V_65 [ V_11 ] -- ;
F_24 ( V_26 , V_3 -> V_35 ,
V_29 -> V_11 , V_30 , false ) ;
return V_17 ;
}
static void
F_47 ( struct V_2 * V_3 ,
struct V_29 * V_29 , T_2 V_30 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
T_1 V_11 = V_29 -> V_11 ;
if ( V_26 -> V_40 -> V_65 [ V_11 ] == 1 )
F_44 ( V_29 ) ;
V_26 -> V_40 -> V_65 [ V_11 ] -- ;
F_24 ( V_26 , V_3 -> V_35 ,
V_29 -> V_11 , V_30 , false ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
}
static int F_50 ( struct V_2 * V_3 ,
const void * V_44 , T_2 * V_62 )
{
T_2 V_75 = * ( T_2 * ) V_44 ;
* V_62 = V_3 -> V_7 -> V_63 + V_75 ;
return 0 ;
}
static bool F_51 ( const struct V_2 * V_3 ,
const void * V_44 )
{
T_2 V_75 = * ( T_2 * ) V_44 ;
return V_3 -> V_35 == V_75 + V_3 -> V_7 -> V_63 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_29 * V_29 ,
T_2 V_30 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
T_1 V_11 = V_29 -> V_11 ;
int V_17 ;
if ( V_26 -> V_40 -> V_65 [ V_11 ] ++ == 0 ) {
V_17 = F_40 ( V_29 ) ;
if ( V_17 )
goto V_74;
}
return 0 ;
V_74:
V_26 -> V_40 -> V_65 [ V_11 ] -- ;
return V_17 ;
}
static void
F_53 ( struct V_2 * V_3 ,
struct V_29 * V_29 , T_2 V_30 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
T_1 V_11 = V_29 -> V_11 ;
if ( V_26 -> V_40 -> V_65 [ V_11 ] == 1 )
F_44 ( V_29 ) ;
V_26 -> V_40 -> V_65 [ V_11 ] -- ;
}
static int F_54 ( struct V_2 * V_3 )
{
struct V_26 * V_26 = V_3 -> V_7 -> V_26 ;
return F_20 ( V_26 , V_3 -> V_35 , 0 , true ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_7 -> V_26 , V_3 -> V_35 , 0 , false ) ;
}
static int F_56 ( struct V_2 * V_3 ,
const void * V_44 , T_2 * V_62 )
{
* V_62 = V_3 -> V_7 -> V_63 ;
return 0 ;
}
static bool F_57 ( const struct V_2 * V_3 ,
const void * V_44 )
{
return true ;
}
static struct V_2 * F_58 ( struct V_26 * V_26 ,
enum V_36 type ,
const void * V_44 )
{
struct V_6 * V_7 ;
struct V_2 * V_3 ;
T_2 V_35 ;
int V_17 ;
V_7 = V_26 -> V_40 -> V_41 [ type ] ;
F_41 (fid, &fid_family->fids_list, list) {
if ( ! V_3 -> V_7 -> V_14 -> V_76 ( V_3 , V_44 ) )
continue;
V_3 -> V_77 ++ ;
return V_3 ;
}
V_3 = F_59 ( V_7 -> V_78 , V_22 ) ;
if ( ! V_3 )
return F_60 ( - V_23 ) ;
V_3 -> V_7 = V_7 ;
V_17 = V_3 -> V_7 -> V_14 -> V_79 ( V_3 , V_44 , & V_35 ) ;
if ( V_17 )
goto V_80;
V_3 -> V_35 = V_35 ;
F_61 ( V_35 - V_7 -> V_63 , V_7 -> V_69 ) ;
if ( V_3 -> V_7 -> V_14 -> V_81 )
V_3 -> V_7 -> V_14 -> V_81 ( V_3 , V_44 ) ;
V_17 = V_3 -> V_7 -> V_14 -> V_82 ( V_3 ) ;
if ( V_17 )
goto V_83;
F_62 ( & V_3 -> V_84 , & V_7 -> V_85 ) ;
V_3 -> V_77 ++ ;
return V_3 ;
V_83:
F_63 ( V_35 - V_7 -> V_63 ,
V_7 -> V_69 ) ;
V_80:
F_8 ( V_3 ) ;
return F_60 ( V_17 ) ;
}
void F_64 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
if ( -- V_3 -> V_77 == 1 && V_3 -> V_38 ) {
return F_65 ( V_3 -> V_38 ) ;
} else if ( V_3 -> V_77 == 0 ) {
F_66 ( & V_3 -> V_84 ) ;
V_3 -> V_7 -> V_14 -> V_86 ( V_3 ) ;
F_63 ( V_3 -> V_35 - V_7 -> V_63 ,
V_7 -> V_69 ) ;
F_8 ( V_3 ) ;
}
}
struct V_2 * F_67 ( struct V_26 * V_26 , T_2 V_30 )
{
return F_58 ( V_26 , V_87 , & V_30 ) ;
}
struct V_2 * F_68 ( struct V_26 * V_26 ,
int V_67 )
{
return F_58 ( V_26 , V_88 , & V_67 ) ;
}
struct V_2 * F_69 ( struct V_26 * V_26 ,
T_2 V_75 )
{
return F_58 ( V_26 , V_89 , & V_75 ) ;
}
struct V_2 * F_70 ( struct V_26 * V_26 )
{
return F_58 ( V_26 , V_90 , NULL ) ;
}
static int
F_71 ( struct V_6 * V_7 ,
const struct V_1 * V_15 )
{
enum V_4 V_5 = V_15 -> V_5 ;
const int * V_91 ;
int V_8 ;
V_91 = V_92 [ V_5 ] ;
for ( V_8 = 0 ; V_8 < V_93 ; V_8 ++ ) {
struct V_26 * V_26 = V_7 -> V_26 ;
char V_94 [ V_95 ] ;
int V_17 ;
if ( ! V_91 [ V_8 ] )
continue;
F_72 ( V_94 , V_8 , V_15 -> V_96 ,
V_15 -> V_25 ,
V_15 -> V_24 ) ;
V_17 = F_6 ( V_26 -> V_27 , F_7 ( V_97 ) , V_94 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int
F_73 ( struct V_6 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_9 ; V_8 ++ ) {
const struct V_1 * V_15 ;
int V_17 ;
V_15 = & V_7 -> V_10 [ V_8 ] ;
V_17 = F_71 ( V_7 , V_15 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_74 ( struct V_26 * V_26 ,
const struct V_6 * V_98 )
{
T_2 V_68 = V_98 -> V_64 - V_98 -> V_63 + 1 ;
struct V_6 * V_7 ;
int V_17 ;
V_7 = F_75 ( V_98 , sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 )
return - V_23 ;
V_7 -> V_26 = V_26 ;
F_76 ( & V_7 -> V_85 ) ;
V_7 -> V_69 = F_77 ( F_78 ( V_68 ) ,
sizeof( unsigned long ) , V_22 ) ;
if ( ! V_7 -> V_69 ) {
V_17 = - V_23 ;
goto V_99;
}
if ( V_7 -> V_10 ) {
V_17 = F_73 ( V_7 ) ;
if ( V_17 )
goto V_100;
}
V_26 -> V_40 -> V_41 [ V_98 -> type ] = V_7 ;
return 0 ;
V_100:
F_8 ( V_7 -> V_69 ) ;
V_99:
F_8 ( V_7 ) ;
return V_17 ;
}
static void
F_79 ( struct V_26 * V_26 ,
struct V_6 * V_7 )
{
V_26 -> V_40 -> V_41 [ V_7 -> type ] = NULL ;
F_8 ( V_7 -> V_69 ) ;
F_80 ( ! F_81 ( & V_7 -> V_85 ) ) ;
F_8 ( V_7 ) ;
}
int F_82 ( struct V_29 * V_29 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
V_26 -> V_40 -> V_65 [ V_29 -> V_11 ] = 0 ;
return F_42 ( V_29 , false ) ;
}
void F_83 ( struct V_29 * V_29 )
{
struct V_26 * V_26 = V_29 -> V_26 ;
V_26 -> V_40 -> V_65 [ V_29 -> V_11 ] = 0 ;
}
int F_84 ( struct V_26 * V_26 )
{
unsigned int V_101 = F_85 ( V_26 -> V_27 ) ;
struct V_39 * V_40 ;
int V_17 , V_8 ;
V_40 = F_59 ( sizeof( * V_26 -> V_40 ) , V_22 ) ;
if ( ! V_40 )
return - V_23 ;
V_26 -> V_40 = V_40 ;
V_40 -> V_65 = F_77 ( V_101 , sizeof( unsigned int ) ,
V_22 ) ;
if ( ! V_40 -> V_65 ) {
V_17 = - V_23 ;
goto V_102;
}
for ( V_8 = 0 ; V_8 < V_103 ; V_8 ++ ) {
V_17 = F_74 ( V_26 ,
V_104 [ V_8 ] ) ;
if ( V_17 )
goto V_105;
}
return 0 ;
V_105:
for ( V_8 -- ; V_8 >= 0 ; V_8 -- ) {
struct V_6 * V_7 ;
V_7 = V_40 -> V_41 [ V_8 ] ;
F_79 ( V_26 , V_7 ) ;
}
F_8 ( V_40 -> V_65 ) ;
V_102:
F_8 ( V_40 ) ;
return V_17 ;
}
void F_86 ( struct V_26 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_40 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_103 ; V_8 ++ )
F_79 ( V_26 ,
V_40 -> V_41 [ V_8 ] ) ;
F_8 ( V_40 -> V_65 ) ;
F_8 ( V_40 ) ;
}
