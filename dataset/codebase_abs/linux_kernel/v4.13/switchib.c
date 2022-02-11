static void
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
char * V_5 = F_2 ( V_2 , V_6 ) ;
memset ( V_5 , 0 , V_6 ) ;
F_3 ( V_5 , V_7 ) ;
F_4 ( V_5 , V_8 ) ;
F_5 ( V_5 , V_9 ) ;
F_6 ( V_5 , 0 ) ;
F_7 ( V_5 , 1 ) ;
F_8 ( V_5 , V_4 -> V_10 ) ;
F_9 ( V_5 , V_11 ) ;
}
static int
F_10 ( struct V_12 * V_12 ,
bool V_13 )
{
struct V_14 * V_14 = V_12 -> V_14 ;
char V_15 [ V_16 ] ;
F_11 ( V_15 , V_12 -> V_10 ,
V_13 ? V_17 :
V_18 ) ;
return F_12 ( V_14 -> V_19 , F_13 ( V_20 ) , V_15 ) ;
}
static int F_14 ( struct V_12 * V_12 ,
T_1 V_21 )
{
struct V_14 * V_14 = V_12 -> V_14 ;
char V_22 [ V_23 ] ;
int V_24 ;
int V_25 ;
F_15 ( V_22 , V_12 -> V_10 , 0 ) ;
V_25 = F_16 ( V_14 -> V_19 , F_13 ( V_26 ) , V_22 ) ;
if ( V_25 )
return V_25 ;
V_24 = F_17 ( V_22 ) ;
if ( V_21 > V_24 )
return - V_27 ;
F_15 ( V_22 , V_12 -> V_10 , V_21 ) ;
return F_12 ( V_14 -> V_19 , F_13 ( V_26 ) , V_22 ) ;
}
static int F_18 ( struct V_12 * V_12 , T_2 V_28 )
{
struct V_14 * V_14 = V_12 -> V_14 ;
char V_29 [ V_30 ] = { 0 } ;
int V_25 ;
F_19 ( V_29 , V_12 -> V_10 ) ;
F_20 ( V_29 , V_28 ) ;
V_25 = F_12 ( V_14 -> V_19 , F_13 ( V_31 ) , V_29 ) ;
return V_25 ;
}
static int F_21 ( struct V_12 * V_12 ,
T_2 V_32 )
{
struct V_14 * V_14 = V_12 -> V_14 ;
char V_33 [ V_34 ] ;
F_22 ( V_33 , V_32 , V_12 -> V_10 ) ;
return F_12 ( V_14 -> V_19 , F_13 ( V_35 ) , V_33 ) ;
}
static int F_23 ( struct V_14 * V_14 ,
T_2 V_10 , T_2 * V_36 ,
T_2 * V_37 )
{
char V_38 [ V_39 ] ;
int V_25 ;
F_24 ( V_38 , V_10 ) ;
V_25 = F_16 ( V_14 -> V_19 , F_13 ( V_40 ) , V_38 ) ;
if ( V_25 )
return V_25 ;
* V_36 = F_25 ( V_38 , 0 ) ;
* V_37 = F_26 ( V_38 ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_12 ,
T_1 V_41 , T_1 V_42 )
{
struct V_14 * V_14 = V_12 -> V_14 ;
char V_43 [ V_44 ] ;
F_28 ( V_43 , V_12 -> V_10 , V_41 ,
V_42 ) ;
return F_12 ( V_14 -> V_19 , F_13 ( V_45 ) , V_43 ) ;
}
static bool F_29 ( struct V_14 * V_14 , T_2 V_10 )
{
return V_14 -> V_46 [ V_10 ] != NULL ;
}
static int F_30 ( struct V_14 * V_14 , T_2 V_10 ,
T_2 V_47 , T_2 V_42 )
{
struct V_12 * V_12 ;
int V_25 ;
V_12 = F_31 ( sizeof( * V_12 ) , V_48 ) ;
if ( ! V_12 )
return - V_49 ;
V_12 -> V_14 = V_14 ;
V_12 -> V_10 = V_10 ;
V_12 -> V_50 . V_47 = V_47 ;
V_25 = F_21 ( V_12 , 0 ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_1 ,
V_12 -> V_10 ) ;
goto V_53;
}
V_25 = F_18 ( V_12 , V_47 + 1 ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_2 ,
V_12 -> V_10 ) ;
goto V_54;
}
V_25 = F_27 ( V_12 ,
V_55 - 1 ,
F_33 ( 3 ) - 1 ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_3 ,
V_12 -> V_10 ) ;
goto V_56;
}
V_25 = F_14 ( V_12 , V_57 ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_4 ,
V_12 -> V_10 ) ;
goto V_58;
}
V_25 = F_10 ( V_12 , true ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_5 ,
V_12 -> V_10 ) ;
goto V_59;
}
F_34 ( V_14 -> V_19 , V_12 -> V_10 ,
V_12 ) ;
V_14 -> V_46 [ V_10 ] = V_12 ;
return 0 ;
V_59:
V_58:
V_56:
V_54:
F_21 ( V_12 , V_60 ) ;
V_53:
F_35 ( V_12 ) ;
return V_25 ;
}
static int F_36 ( struct V_14 * V_14 , T_2 V_10 ,
T_2 V_47 , T_2 V_42 )
{
int V_25 ;
V_25 = F_37 ( V_14 -> V_19 , V_10 ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_6 ,
V_10 ) ;
return V_25 ;
}
V_25 = F_30 ( V_14 , V_10 , V_47 , V_42 ) ;
if ( V_25 )
goto V_61;
return 0 ;
V_61:
F_38 ( V_14 -> V_19 , V_10 ) ;
return V_25 ;
}
static void F_39 ( struct V_14 * V_14 , T_2 V_10 )
{
struct V_12 * V_12 = V_14 -> V_46 [ V_10 ] ;
F_40 ( V_14 -> V_19 , V_10 , V_14 ) ;
V_14 -> V_46 [ V_10 ] = NULL ;
F_10 ( V_12 , false ) ;
F_21 ( V_12 , V_60 ) ;
F_35 ( V_12 ) ;
}
static void F_41 ( struct V_14 * V_14 , T_2 V_10 )
{
F_39 ( V_14 , V_10 ) ;
F_38 ( V_14 -> V_19 , V_10 ) ;
}
static void F_42 ( struct V_14 * V_14 )
{
int V_62 ;
for ( V_62 = 1 ; V_62 < V_63 ; V_62 ++ )
if ( F_29 ( V_14 , V_62 ) )
F_41 ( V_14 , V_62 ) ;
F_35 ( V_14 -> V_46 ) ;
}
static int F_43 ( struct V_14 * V_14 )
{
T_3 V_64 ;
T_2 V_47 , V_42 ;
int V_62 ;
int V_25 ;
V_64 = sizeof( struct V_12 * ) * V_63 ;
V_14 -> V_46 = F_31 ( V_64 , V_48 ) ;
if ( ! V_14 -> V_46 )
return - V_49 ;
for ( V_62 = 1 ; V_62 < V_63 ; V_62 ++ ) {
V_25 = F_23 ( V_14 , V_62 , & V_47 ,
& V_42 ) ;
if ( V_25 )
goto V_65;
if ( ! V_42 )
continue;
V_25 = F_36 ( V_14 , V_62 , V_47 , V_42 ) ;
if ( V_25 )
goto V_61;
}
return 0 ;
V_61:
V_65:
for ( V_62 -- ; V_62 >= 1 ; V_62 -- )
if ( F_29 ( V_14 , V_62 ) )
F_41 ( V_14 , V_62 ) ;
F_35 ( V_14 -> V_46 ) ;
return V_25 ;
}
static void
F_44 ( struct V_12 * V_12 ,
enum V_66 V_67 )
{
if ( V_67 == V_68 )
F_45 ( L_7 ,
V_12 -> V_50 . V_47 + 1 ) ;
else
F_45 ( L_8 ,
V_12 -> V_50 . V_47 + 1 ) ;
}
static void F_46 ( const struct V_69 * V_70 ,
char * V_71 , void * V_72 )
{
struct V_14 * V_14 = V_72 ;
struct V_12 * V_12 ;
enum V_66 V_67 ;
T_2 V_10 ;
V_10 = F_47 ( V_71 ) ;
V_12 = V_14 -> V_46 [ V_10 ] ;
if ( ! V_12 ) {
F_48 ( V_14 -> V_51 -> V_52 , L_9 ,
V_10 ) ;
return;
}
V_67 = F_49 ( V_71 ) ;
F_44 ( V_12 , V_67 ) ;
}
static int F_50 ( struct V_14 * V_14 )
{
int V_62 ;
int V_25 ;
for ( V_62 = 0 ; V_62 < F_51 ( V_73 ) ; V_62 ++ ) {
V_25 = F_52 ( V_14 -> V_19 ,
& V_73 [ V_62 ] ,
V_14 ) ;
if ( V_25 )
goto V_74;
}
return 0 ;
V_74:
for ( V_62 -- ; V_62 >= 0 ; V_62 -- ) {
F_53 ( V_14 -> V_19 ,
& V_73 [ V_62 ] ,
V_14 ) ;
}
return V_25 ;
}
static void F_54 ( struct V_14 * V_14 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < F_51 ( V_73 ) ; V_62 ++ ) {
F_53 ( V_14 -> V_19 ,
& V_73 [ V_62 ] , V_14 ) ;
}
}
static int F_55 ( struct V_75 * V_75 )
{
char V_76 [ V_77 ] ;
F_56 ( V_76 , V_78 ,
V_79 ,
V_80 ,
V_81 ) ;
F_57 ( V_76 , V_82 ) ;
F_58 ( V_76 ,
V_83 ) ;
return F_12 ( V_75 , F_13 ( V_84 ) , V_76 ) ;
}
static int F_59 ( struct V_75 * V_75 ,
const struct V_85 * V_85 )
{
struct V_14 * V_14 = F_60 ( V_75 ) ;
int V_25 ;
V_14 -> V_19 = V_75 ;
V_14 -> V_51 = V_85 ;
V_25 = F_43 ( V_14 ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_10 ) ;
return V_25 ;
}
V_25 = F_50 ( V_14 ) ;
if ( V_25 ) {
F_32 ( V_14 -> V_51 -> V_52 , L_11 ) ;
goto V_86;
}
return 0 ;
V_86:
F_42 ( V_14 ) ;
return V_25 ;
}
static void F_61 ( struct V_75 * V_75 )
{
struct V_14 * V_14 = F_60 ( V_75 ) ;
F_54 ( V_14 ) ;
F_42 ( V_14 ) ;
}
static int T_4 F_62 ( void )
{
int V_25 ;
V_25 = F_63 ( & V_87 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_63 ( & V_88 ) ;
if ( V_25 )
goto V_89;
V_25 = F_64 ( & V_90 ) ;
if ( V_25 )
goto V_91;
V_25 = F_64 ( & V_92 ) ;
if ( V_25 )
goto V_93;
return 0 ;
V_93:
F_65 ( & V_90 ) ;
V_91:
F_66 ( & V_88 ) ;
V_89:
F_66 ( & V_87 ) ;
return V_25 ;
}
static void T_5 F_67 ( void )
{
F_65 ( & V_92 ) ;
F_65 ( & V_90 ) ;
F_66 ( & V_88 ) ;
F_66 ( & V_87 ) ;
}
