void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
double V_3 ;
V_1 -> V_4 ++ ;
V_3 = V_2 - V_1 -> V_5 ;
V_1 -> V_5 += V_3 / V_1 -> V_4 ;
V_1 -> V_6 += V_3 * ( V_2 - V_1 -> V_5 ) ;
if ( V_2 > V_1 -> V_7 )
V_1 -> V_7 = V_2 ;
if ( V_2 < V_1 -> V_8 )
V_1 -> V_8 = V_2 ;
}
double F_2 ( struct V_1 * V_1 )
{
return V_1 -> V_5 ;
}
double F_3 ( struct V_1 * V_1 )
{
double V_9 , V_10 ;
if ( V_1 -> V_4 < 2 )
return 0.0 ;
V_9 = V_1 -> V_6 / ( V_1 -> V_4 - 1 ) ;
V_10 = V_9 / V_1 -> V_4 ;
return sqrt ( V_10 ) ;
}
double F_4 ( double V_11 , double V_12 )
{
double V_13 = 0.0 ;
if ( V_12 )
V_13 = 100.0 * V_11 / V_12 ;
return V_13 ;
}
bool F_5 ( struct V_14 * V_15 ,
enum V_16 V_17 )
{
struct V_18 * V_19 = V_15 -> V_20 ;
return V_19 -> V_17 == V_17 ;
}
void F_6 ( struct V_14 * V_15 )
{
struct V_18 * V_19 = V_15 -> V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( ! strcmp ( F_7 ( V_15 ) , V_23 [ V_21 ] ) ) {
V_19 -> V_17 = V_21 ;
break;
}
}
}
static void F_8 ( struct V_14 * V_15 )
{
int V_21 ;
struct V_18 * V_19 = V_15 -> V_20 ;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
F_9 ( & V_19 -> V_24 [ V_21 ] ) ;
F_6 ( V_15 ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
V_15 -> V_20 = F_11 ( sizeof( struct V_18 ) ) ;
if ( V_15 -> V_20 == NULL )
return - V_25 ;
F_8 ( V_15 ) ;
return 0 ;
}
static void F_12 ( struct V_14 * V_15 )
{
F_13 ( & V_15 -> V_20 ) ;
}
static int F_14 ( struct V_14 * V_15 ,
int V_26 , int V_27 )
{
struct V_28 * V_29 ;
V_29 = F_15 ( V_26 , V_27 ) ;
if ( V_29 )
V_15 -> V_30 = V_29 ;
return V_29 ? 0 : - V_25 ;
}
static void F_16 ( struct V_14 * V_15 )
{
F_17 ( V_15 -> V_30 ) ;
V_15 -> V_30 = NULL ;
}
static int F_18 ( struct V_14 * V_15 , bool V_31 )
{
int V_26 = F_19 ( V_15 ) ;
int V_27 = F_20 ( V_15 -> V_32 ) ;
if ( F_10 ( V_15 ) < 0 ||
F_21 ( V_15 , V_26 , V_27 ) < 0 ||
( V_31 && F_14 ( V_15 , V_26 , V_27 ) < 0 ) )
return - V_25 ;
return 0 ;
}
int F_22 ( struct V_33 * V_34 , bool V_31 )
{
struct V_14 * V_15 ;
F_23 (evlist, evsel) {
if ( F_18 ( V_15 , V_31 ) )
goto V_35;
}
return 0 ;
V_35:
F_24 ( V_34 ) ;
return - 1 ;
}
void F_24 ( struct V_33 * V_34 )
{
struct V_14 * V_15 ;
F_23 (evlist, evsel) {
F_12 ( V_15 ) ;
F_25 ( V_15 ) ;
F_16 ( V_15 ) ;
}
}
void F_26 ( struct V_33 * V_34 )
{
struct V_14 * V_15 ;
F_23 (evlist, evsel) {
F_8 ( V_15 ) ;
F_27 ( V_15 ) ;
}
}
static void F_28 ( struct V_14 * V_36 )
{
if ( V_36 -> V_37 )
memset ( V_36 -> V_37 , 0 , V_38 ) ;
}
static int F_29 ( struct V_14 * V_36 ,
struct V_39 * V_40 , int V_41 , bool * V_42 )
{
unsigned long * V_43 = V_36 -> V_37 ;
struct V_44 * V_45 = F_30 ( V_36 ) ;
int V_46 ;
* V_42 = false ;
if ( ! V_36 -> V_47 )
return 0 ;
if ( F_31 ( V_45 ) )
return 0 ;
if ( ! V_43 ) {
V_43 = F_11 ( V_38 ) ;
if ( ! V_43 )
return - V_25 ;
V_36 -> V_37 = V_43 ;
}
if ( ! ( V_40 -> V_48 && V_40 -> V_49 ) )
return 0 ;
V_46 = F_32 ( V_45 , V_41 , NULL ) ;
if ( V_46 < 0 )
return - 1 ;
* V_42 = F_33 ( V_46 , V_43 ) == 1 ;
return 0 ;
}
static int
F_34 ( struct V_50 * V_51 , struct V_14 * V_15 ,
int V_41 , int V_52 ,
struct V_39 * V_53 )
{
struct V_39 * V_54 = & V_15 -> V_29 -> V_54 ;
static struct V_39 V_55 ;
bool V_42 = false ;
if ( F_29 ( V_15 , V_53 , V_41 , & V_42 ) ) {
F_35 ( L_1 ) ;
return - 1 ;
}
if ( V_42 )
V_53 = & V_55 ;
switch ( V_51 -> V_56 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
if ( ! V_15 -> V_61 )
F_36 ( V_15 , V_41 , V_52 , V_53 ) ;
F_37 ( V_53 , V_51 -> V_62 , NULL ) ;
if ( V_51 -> V_56 == V_60 )
F_38 ( V_15 , V_53 -> V_63 , V_41 ) ;
break;
case V_64 :
V_54 -> V_2 += V_53 -> V_2 ;
if ( V_51 -> V_62 ) {
V_54 -> V_49 += V_53 -> V_49 ;
V_54 -> V_48 += V_53 -> V_48 ;
}
case V_65 :
default:
break;
}
return 0 ;
}
static int F_39 ( struct V_50 * V_51 ,
struct V_14 * V_36 )
{
int V_27 = F_20 ( V_36 -> V_32 ) ;
int V_26 = F_19 ( V_36 ) ;
int V_41 , V_52 ;
if ( V_36 -> V_66 )
V_27 = 1 ;
for ( V_52 = 0 ; V_52 < V_27 ; V_52 ++ ) {
for ( V_41 = 0 ; V_41 < V_26 ; V_41 ++ ) {
if ( F_34 ( V_51 , V_36 , V_41 , V_52 ,
V_28 ( V_36 -> V_29 , V_41 , V_52 ) ) )
return - 1 ;
}
}
return 0 ;
}
int F_40 ( struct V_50 * V_51 ,
struct V_14 * V_36 )
{
struct V_39 * V_54 = & V_36 -> V_29 -> V_54 ;
struct V_18 * V_19 = V_36 -> V_20 ;
T_1 * V_53 = V_36 -> V_29 -> V_54 . V_63 ;
int V_21 , V_67 ;
V_54 -> V_2 = V_54 -> V_49 = V_54 -> V_48 = 0 ;
if ( V_51 -> V_68 )
F_9 ( V_19 -> V_24 ) ;
if ( V_36 -> V_47 )
F_28 ( V_36 ) ;
V_67 = F_39 ( V_51 , V_36 ) ;
if ( V_67 )
return V_67 ;
if ( V_51 -> V_56 != V_64 )
return 0 ;
if ( ! V_36 -> V_61 )
F_36 ( V_36 , - 1 , - 1 , V_54 ) ;
F_37 ( V_54 , V_51 -> V_62 , & V_36 -> V_29 -> V_69 ) ;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
F_1 ( & V_19 -> V_24 [ V_21 ] , V_53 [ V_21 ] ) ;
if ( V_70 ) {
fprintf ( V_51 -> V_71 , L_2 V_72 L_3 V_72 L_3 V_72 L_4 ,
F_7 ( V_36 ) , V_53 [ 0 ] , V_53 [ 1 ] , V_53 [ 2 ] ) ;
}
F_38 ( V_36 , V_53 , 0 ) ;
return 0 ;
}
int F_41 ( struct V_73 * T_2 V_74 ,
union V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_39 V_53 ;
struct V_79 * V_80 = & V_76 -> V_81 ;
struct V_14 * V_36 ;
V_53 . V_2 = V_80 -> V_2 ;
V_53 . V_49 = V_80 -> V_49 ;
V_53 . V_48 = V_80 -> V_48 ;
V_36 = F_42 ( V_78 -> V_34 , V_80 -> V_17 ) ;
if ( ! V_36 ) {
F_35 ( L_5 ) ;
return - V_82 ;
}
* V_28 ( V_36 -> V_29 , V_80 -> V_41 , V_80 -> V_52 ) = V_53 ;
V_36 -> V_83 = true ;
return 0 ;
}
T_3 F_43 ( union V_75 * V_76 , T_4 * V_84 )
{
struct V_79 * V_80 = (struct V_79 * ) V_76 ;
T_3 V_67 ;
V_67 = fprintf ( V_84 , L_6 V_72 L_7 ,
V_80 -> V_17 , V_80 -> V_41 , V_80 -> V_52 ) ;
V_67 += fprintf ( V_84 , L_8 V_72 L_9 V_72 L_10 V_72 L_4 ,
V_80 -> V_2 , V_80 -> V_49 , V_80 -> V_48 ) ;
return V_67 ;
}
T_3 F_44 ( union V_75 * V_76 , T_4 * V_84 )
{
struct V_85 * V_86 = (struct V_85 * ) V_76 ;
T_3 V_67 ;
V_67 = fprintf ( V_84 , L_11 V_72 L_12 , V_86 -> time ,
V_86 -> type == V_87 ? L_13 : L_14 ) ;
return V_67 ;
}
T_3 F_45 ( union V_75 * V_76 , T_4 * V_84 )
{
struct V_50 V_88 ;
T_3 V_67 ;
F_46 ( & V_88 , & V_76 -> V_89 ) ;
V_67 = fprintf ( V_84 , L_4 ) ;
V_67 += fprintf ( V_84 , L_15 , V_88 . V_56 ) ;
V_67 += fprintf ( V_84 , L_16 , V_88 . V_62 ) ;
V_67 += fprintf ( V_84 , L_17 , V_88 . V_68 ) ;
return V_67 ;
}
