static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> type ) ;
}
static T_1
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 , V_9 ;
V_9 = F_4 ( V_7 , & V_8 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_5 , L_2 , V_8 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_10 V_11 ;
int V_12 ;
if ( ! V_7 -> V_13 -> V_14 )
return - V_15 ;
V_12 = V_7 -> V_13 -> V_14 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
return sprintf ( V_5 , L_1 , V_11 == V_16 ? L_3
: L_4 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 ;
if ( ! V_7 -> V_13 -> V_18 )
return - V_15 ;
if ( ! strncmp ( V_5 , L_3 , sizeof( L_3 ) - 1 ) )
V_12 = V_7 -> V_13 -> V_18 ( V_7 , V_16 ) ;
else if ( ! strncmp ( V_5 , L_4 , sizeof( L_4 ) - 1 ) )
V_12 = V_7 -> V_13 -> V_18 ( V_7 , V_19 ) ;
else
V_12 = - V_20 ;
if ( V_12 )
return V_12 ;
return V_17 ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_21 type ;
int V_22 , V_12 ;
if ( ! V_7 -> V_13 -> V_23 )
return - V_15 ;
if ( sscanf ( V_4 -> V_4 . V_24 , L_5 , & V_22 ) != 1 )
return - V_20 ;
V_12 = V_7 -> V_13 -> V_23 ( V_7 , V_22 , & type ) ;
if ( V_12 )
return V_12 ;
switch ( type ) {
case V_25 :
return sprintf ( V_5 , L_6 ) ;
case V_26 :
return sprintf ( V_5 , L_7 ) ;
case V_27 :
return sprintf ( V_5 , L_8 ) ;
case V_28 :
return sprintf ( V_5 , L_9 ) ;
default:
return sprintf ( V_5 , L_10 ) ;
}
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 , V_9 ;
int V_8 ;
if ( ! V_7 -> V_13 -> V_29 )
return - V_15 ;
if ( sscanf ( V_4 -> V_4 . V_24 , L_11 , & V_22 ) != 1 )
return - V_20 ;
if ( F_9 ( V_5 , 10 , & V_8 ) )
return - V_20 ;
V_9 = V_7 -> V_13 -> V_29 ( V_7 , V_22 , V_8 ) ;
if ( V_9 )
return V_9 ;
F_10 ( V_7 , V_30 ) ;
return V_17 ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 , V_9 ;
int V_8 ;
if ( ! V_7 -> V_13 -> V_31 )
return - V_15 ;
if ( sscanf ( V_4 -> V_4 . V_24 , L_11 , & V_22 ) != 1 )
return - V_20 ;
V_9 = V_7 -> V_13 -> V_31 ( V_7 , V_22 , & V_8 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_5 , L_2 , V_8 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 , V_9 ;
int V_8 ;
if ( ! V_7 -> V_13 -> V_32 )
return - V_15 ;
if ( sscanf ( V_4 -> V_4 . V_24 , L_12 , & V_22 ) != 1 )
return - V_20 ;
if ( F_9 ( V_5 , 10 , & V_8 ) )
return - V_20 ;
V_9 = V_7 -> V_13 -> V_32 ( V_7 , V_22 , V_8 ) ;
if ( ! V_9 )
F_13 ( V_7 ) ;
return V_9 ? V_9 : V_17 ;
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 , V_9 ;
int V_8 ;
if ( ! V_7 -> V_13 -> V_33 )
return - V_15 ;
if ( sscanf ( V_4 -> V_4 . V_24 , L_12 , & V_22 ) != 1 )
return - V_20 ;
V_9 = V_7 -> V_13 -> V_33 ( V_7 , V_22 , & V_8 ) ;
return V_9 ? V_9 : sprintf ( V_5 , L_2 , V_8 ) ;
}
static T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_34 ;
if ( sscanf ( V_5 , L_2 , & V_34 ) != 1 )
return - V_20 ;
if ( V_34 && V_34 < 1000 )
return - V_20 ;
if ( V_34 && ! V_7 -> V_35 ) {
if ( ! V_7 -> V_36 )
V_7 -> V_36 = 1000 ;
F_16 ( V_7 , L_13 ,
sizeof( L_13 ) ) ;
} else if ( ! V_34 && V_7 -> V_35 ) {
V_7 -> V_36 = 0 ;
F_17 ( V_7 , L_13 ,
sizeof( L_13 ) ) ;
}
V_7 -> V_35 = V_34 ;
F_10 ( V_7 , V_30 ) ;
return V_17 ;
}
static T_1
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_35 ) ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_24 [ V_37 ] ;
int V_9 ;
snprintf ( V_24 , sizeof( V_24 ) , L_14 , V_5 ) ;
V_9 = F_20 ( V_7 , V_24 ) ;
if ( ! V_9 )
V_9 = V_17 ;
return V_9 ;
}
static T_1
F_21 ( struct V_1 * V_2 , struct V_3 * V_38 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_39 -> V_24 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 , struct V_3 * V_38 ,
char * V_5 )
{
return F_23 ( V_5 ) ;
}
static T_1
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 = 0 ;
int V_8 ;
if ( F_9 ( V_5 , 10 , & V_8 ) )
return - V_20 ;
if ( ! V_7 -> V_13 -> V_40 ) {
F_25 ( & V_7 -> V_41 ) ;
V_7 -> V_42 = V_8 ;
F_26 ( & V_7 -> V_41 ) ;
} else {
V_9 = V_7 -> V_13 -> V_40 ( V_7 , V_8 ) ;
}
if ( ! V_9 )
F_10 ( V_7 , V_30 ) ;
return V_9 ? V_9 : V_17 ;
}
static T_1
F_27 ( struct V_1 * V_2 , struct V_3 * V_38 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_43 )
return sprintf ( V_5 , L_15 , V_7 -> V_43 -> V_44 ) ;
else
return - V_45 ;
}
static T_1
F_28 ( struct V_1 * V_2 , struct V_3 * V_38 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_44 ;
if ( ! V_7 -> V_43 )
return - V_45 ;
if ( F_29 ( V_5 , 10 , & V_44 ) )
return - V_20 ;
V_7 -> V_43 -> V_44 = V_44 ;
return V_17 ;
}
static T_4 F_30 ( struct V_46 * V_47 ,
struct V_48 * V_4 ,
int V_49 )
{
struct V_1 * V_2 = F_31 ( V_47 , struct V_1 , V_47 ) ;
struct V_6 * V_7 ;
V_7 = F_31 ( V_2 , struct V_6 , V_1 ) ;
if ( V_7 -> V_13 -> V_14 )
return V_4 -> V_11 ;
return 0 ;
}
static T_4 F_32 ( struct V_46 * V_47 ,
struct V_48 * V_4 ,
int V_49 )
{
struct V_1 * V_2 = F_31 ( V_47 , struct V_1 , V_47 ) ;
struct V_6 * V_7 ;
enum V_21 V_50 ;
int V_17 , V_51 = 0 ;
V_7 = F_31 ( V_2 , struct V_6 , V_1 ) ;
for ( V_17 = 0 ; V_17 < V_7 -> V_52 && ! V_51 ; V_17 ++ ) {
V_7 -> V_13 -> V_23 ( V_7 , V_17 , & V_50 ) ;
if ( V_50 == V_27 )
V_51 = 1 ;
}
if ( ! V_51 )
return V_4 -> V_11 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , int V_53 )
{
struct V_48 * * V_54 ;
int V_55 ;
if ( V_7 -> V_52 <= 0 )
return - V_20 ;
V_7 -> V_56 = F_34 ( V_7 -> V_52 , sizeof( * V_7 -> V_56 ) ,
V_57 ) ;
if ( ! V_7 -> V_56 )
return - V_58 ;
V_7 -> V_59 = F_34 ( V_7 -> V_52 , sizeof( * V_7 -> V_59 ) ,
V_57 ) ;
if ( ! V_7 -> V_59 ) {
F_35 ( V_7 -> V_56 ) ;
return - V_58 ;
}
if ( V_7 -> V_13 -> V_33 ) {
V_7 -> V_60 = F_34 ( V_7 -> V_52 ,
sizeof( * V_7 -> V_60 ) ,
V_57 ) ;
if ( ! V_7 -> V_60 ) {
F_35 ( V_7 -> V_56 ) ;
F_35 ( V_7 -> V_59 ) ;
return - V_58 ;
}
}
V_54 = F_34 ( V_7 -> V_52 * 3 + 1 , sizeof( * V_54 ) , V_57 ) ;
if ( ! V_54 ) {
F_35 ( V_7 -> V_56 ) ;
F_35 ( V_7 -> V_59 ) ;
if ( V_7 -> V_13 -> V_33 )
F_35 ( V_7 -> V_60 ) ;
return - V_58 ;
}
for ( V_55 = 0 ; V_55 < V_7 -> V_52 ; V_55 ++ ) {
snprintf ( V_7 -> V_56 [ V_55 ] . V_24 , V_37 ,
L_5 , V_55 ) ;
F_36 ( & V_7 -> V_56 [ V_55 ] . V_4 . V_4 ) ;
V_7 -> V_56 [ V_55 ] . V_4 . V_4 . V_24 =
V_7 -> V_56 [ V_55 ] . V_24 ;
V_7 -> V_56 [ V_55 ] . V_4 . V_4 . V_11 = V_61 ;
V_7 -> V_56 [ V_55 ] . V_4 . V_62 = F_7 ;
V_54 [ V_55 ] = & V_7 -> V_56 [ V_55 ] . V_4 . V_4 ;
snprintf ( V_7 -> V_59 [ V_55 ] . V_24 , V_37 ,
L_11 , V_55 ) ;
F_36 ( & V_7 -> V_59 [ V_55 ] . V_4 . V_4 ) ;
V_7 -> V_59 [ V_55 ] . V_4 . V_4 . V_24 =
V_7 -> V_59 [ V_55 ] . V_24 ;
V_7 -> V_59 [ V_55 ] . V_4 . V_4 . V_11 = V_61 ;
V_7 -> V_59 [ V_55 ] . V_4 . V_62 = F_11 ;
if ( F_37 ( V_63 ) &&
V_53 & ( 1 << V_55 ) ) {
V_7 -> V_59 [ V_55 ] . V_4 . V_4 . V_11 |= V_64 ;
V_7 -> V_59 [ V_55 ] . V_4 . V_65 =
F_8 ;
}
V_54 [ V_55 + V_7 -> V_52 ] = & V_7 -> V_59 [ V_55 ] . V_4 . V_4 ;
if ( ! V_7 -> V_13 -> V_33 )
continue;
snprintf ( V_7 -> V_60 [ V_55 ] . V_24 , V_37 ,
L_12 , V_55 ) ;
F_36 ( & V_7 -> V_60 [ V_55 ] . V_4 . V_4 ) ;
V_7 -> V_60 [ V_55 ] . V_4 . V_4 . V_24 =
V_7 -> V_60 [ V_55 ] . V_24 ;
V_7 -> V_60 [ V_55 ] . V_4 . V_4 . V_11 = V_61 ;
V_7 -> V_60 [ V_55 ] . V_4 . V_62 = F_14 ;
if ( V_7 -> V_13 -> V_32 ) {
V_7 -> V_60 [ V_55 ] . V_4 . V_4 . V_11 |= V_64 ;
V_7 -> V_60 [ V_55 ] . V_4 . V_65 =
F_12 ;
}
V_54 [ V_55 + V_7 -> V_52 * 2 ] =
& V_7 -> V_60 [ V_55 ] . V_4 . V_4 ;
}
V_54 [ V_7 -> V_52 * 3 ] = NULL ;
V_7 -> V_66 . V_54 = V_54 ;
return 0 ;
}
static void F_38 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_35 ( V_7 -> V_56 ) ;
F_35 ( V_7 -> V_59 ) ;
if ( V_7 -> V_13 -> V_33 )
F_35 ( V_7 -> V_60 ) ;
F_35 ( V_7 -> V_66 . V_54 ) ;
}
int F_39 ( struct V_6 * V_7 ,
int V_53 )
{
const struct V_67 * * V_68 ;
int V_69 , V_70 , V_12 ;
V_70 = F_40 ( V_71 ) + 2 ;
V_68 = F_34 ( V_70 , sizeof( * V_68 ) , V_57 ) ;
if ( ! V_68 )
return - V_58 ;
for ( V_69 = 0 ; V_69 < V_70 - 2 ; V_69 ++ )
V_68 [ V_69 ] = V_71 [ V_69 ] ;
if ( V_7 -> V_52 ) {
V_12 = F_33 ( V_7 , V_53 ) ;
if ( V_12 ) {
F_35 ( V_68 ) ;
return V_12 ;
}
V_68 [ V_70 - 2 ] = & V_7 -> V_66 ;
}
V_7 -> V_1 . V_68 = V_68 ;
return 0 ;
}
void F_41 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
if ( V_7 -> V_52 )
F_38 ( V_7 ) ;
F_35 ( V_7 -> V_1 . V_68 ) ;
}
static T_1
F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_72 * V_73 = F_43 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_73 -> type ) ;
}
static T_1
F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_72 * V_73 = F_43 ( V_2 ) ;
unsigned long V_34 ;
int V_9 ;
V_9 = V_73 -> V_13 -> V_74 ( V_73 , & V_34 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_5 , L_16 , V_34 ) ;
}
static T_1
F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_72 * V_73 = F_43 ( V_2 ) ;
unsigned long V_34 ;
int V_9 ;
V_9 = V_73 -> V_13 -> V_75 ( V_73 , & V_34 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_5 , L_16 , V_34 ) ;
}
static T_1
F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_72 * V_73 = F_43 ( V_2 ) ;
unsigned long V_34 ;
int V_12 ;
if ( sscanf ( V_5 , L_16 , & V_34 ) != 1 )
return - V_20 ;
if ( ( long ) V_34 < 0 )
return - V_20 ;
V_12 = V_73 -> V_13 -> V_76 ( V_73 , V_34 ) ;
if ( V_12 )
return V_12 ;
return V_17 ;
}
void F_47 ( struct V_72 * V_73 )
{
V_73 -> V_1 . V_68 = V_77 ;
}
T_1
F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_78 * V_79 ;
V_79 =
F_31 ( V_4 , struct V_78 , V_4 ) ;
if ( V_79 -> V_22 == V_80 )
return sprintf ( V_5 , L_17 ) ;
else
return sprintf ( V_5 , L_2 , V_79 -> V_22 ) ;
}
T_1
F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_78 * V_79 ;
V_79 = F_31 ( V_4 , struct V_78 , V_81 ) ;
return sprintf ( V_5 , L_2 , V_79 -> V_82 ) ;
}
T_1
F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_78 * V_79 ;
int V_9 , V_82 ;
V_9 = F_9 ( V_5 , 0 , & V_82 ) ;
if ( V_9 )
return V_9 ;
V_79 = F_31 ( V_4 , struct V_78 , V_81 ) ;
V_79 -> V_82 = V_82 ;
return V_17 ;
}
