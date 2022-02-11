static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( F_2 ( V_3 ) ) {
struct V_4 * V_5 = F_3 ( V_3 ) ;
return V_5 -> V_6 ;
} else if ( F_4 ( V_3 ) ) {
struct V_7 * V_8 = F_5 ( V_3 ) ;
return V_8 -> V_6 ;
}
return NULL ;
}
static T_1 F_6 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return sprintf ( V_11 , L_1 , V_12 -> V_13 ) ;
}
static T_1 F_7 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return sprintf ( V_11 , L_1 , V_12 -> V_14 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return sprintf ( V_11 , L_1 , V_12 -> V_15 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( & V_3 -> V_16 , L_2 , L_3 ) ;
F_10 ( & V_3 -> V_16 , L_2 , L_4 ) ;
F_10 ( & V_3 -> V_16 , L_2 , L_5 ) ;
}
void F_11 ( struct V_17 * V_18 , int V_19 ,
bool V_20 )
{
struct V_21 * V_22 = & V_18 -> V_23 [ V_19 ] ;
char V_24 [ 6 ] ;
if ( V_22 -> V_20 == V_20 )
return;
V_22 -> V_20 = V_20 ;
snprintf ( V_24 , sizeof( V_24 ) , L_6 , V_19 ) ;
F_10 ( & V_18 -> V_3 . V_16 , V_24 , L_7 ) ;
F_12 ( & V_18 -> V_3 . V_16 , V_25 ) ;
}
struct V_26 * F_13 ( struct V_17 * V_18 )
{
if ( F_14 ( V_18 -> V_3 . V_27 ) )
return F_15 ( V_18 -> V_3 . V_27 -> V_27 -> V_27 ) ;
if ( F_2 ( V_18 -> V_3 . V_27 ) )
return F_15 ( V_18 -> V_3 . V_27 -> V_27 ) ;
if ( F_16 ( V_18 -> V_3 . V_27 ) )
return F_15 ( V_18 -> V_3 . V_27 ) ;
return NULL ;
}
static T_1
F_17 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_21 * V_19 = F_18 ( V_10 , struct V_21 ,
V_28 ) ;
return sprintf ( V_11 , L_1 , V_19 -> V_29 ) ;
}
static T_1
F_19 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_21 * V_19 = F_18 ( V_10 , struct V_21 ,
V_30 ) ;
return sprintf ( V_11 , L_8 , V_19 -> V_31 ? V_19 -> V_31 : L_9 ) ;
}
static T_1
F_20 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_21 * V_19 = F_18 ( V_10 , struct V_21 ,
V_32 ) ;
return sprintf ( V_11 , L_8 , V_19 -> V_20 ? L_10 : L_11 ) ;
}
static T_1
F_21 ( struct V_2 * V_3 , struct V_9 * V_10 ,
const char * V_11 , T_2 V_33 )
{
struct V_21 * V_19 = F_18 ( V_10 , struct V_21 ,
V_32 ) ;
struct V_26 * V_34 = F_13 ( V_19 -> V_35 ) ;
bool V_36 ;
int V_37 ;
if ( ! V_34 -> V_38 -> V_39 )
return - V_40 ;
V_37 = F_22 ( V_11 , & V_36 ) ;
if ( V_37 )
return V_37 ;
V_37 = V_34 -> V_38 -> V_39 ( V_34 -> V_38 , V_19 -> V_41 , V_36 ) ;
if ( V_37 )
return V_37 ;
return V_33 ;
}
static T_1
F_23 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_21 * V_19 = F_18 ( V_10 , struct V_21 ,
V_42 ) ;
T_1 V_37 ;
switch ( V_19 -> V_43 ) {
case V_44 :
V_37 = sprintf ( V_11 , L_12 ) ;
break;
case V_45 :
V_37 = sprintf ( V_11 , L_13 ) ;
break;
case V_46 :
default:
V_37 = sprintf ( V_11 , L_14 ) ;
break;
}
return V_37 ;
}
static void F_24 ( struct V_17 * V_18 ,
const struct V_47 * V_31 , bool V_48 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_18 -> V_50 ; V_49 ++ , V_31 ++ ) {
struct V_21 * V_19 = & V_18 -> V_23 [ V_49 ] ;
V_19 -> V_31 = F_25 ( V_31 -> V_31 , V_51 ) ;
if ( V_31 -> V_31 && ! V_19 -> V_31 )
F_26 ( & V_18 -> V_3 , L_15 , V_49 ) ;
V_19 -> V_35 = V_18 ;
V_19 -> V_29 = V_31 -> V_29 ;
V_19 -> V_43 = V_31 -> V_43 ;
V_19 -> V_41 = V_31 -> V_41 ;
sprintf ( V_19 -> V_52 , L_6 , V_31 -> V_41 ) ;
F_27 ( & V_19 -> V_28 . V_10 ) ;
V_19 -> V_28 . V_10 . V_53 = L_16 ;
V_19 -> V_28 . V_10 . V_19 = 0444 ;
V_19 -> V_28 . V_54 = F_17 ;
F_27 ( & V_19 -> V_30 . V_10 ) ;
V_19 -> V_30 . V_10 . V_53 = L_17 ;
V_19 -> V_30 . V_10 . V_19 = 0444 ;
V_19 -> V_30 . V_54 = F_19 ;
F_27 ( & V_19 -> V_32 . V_10 ) ;
V_19 -> V_32 . V_10 . V_53 = L_7 ;
V_19 -> V_32 . V_10 . V_19 = 0644 ;
V_19 -> V_32 . V_54 = F_20 ;
V_19 -> V_32 . V_55 = F_21 ;
V_19 -> V_56 [ 0 ] = & V_19 -> V_28 . V_10 ;
V_19 -> V_56 [ 1 ] = & V_19 -> V_30 . V_10 ;
V_19 -> V_56 [ 2 ] = & V_19 -> V_32 . V_10 ;
if ( V_48 ) {
F_27 ( & V_19 -> V_42 . V_10 ) ;
V_19 -> V_42 . V_10 . V_53 = L_18 ;
V_19 -> V_42 . V_10 . V_19 = 0444 ;
V_19 -> V_42 . V_54 = F_23 ;
V_19 -> V_56 [ 3 ] = & V_19 -> V_42 . V_10 ;
}
V_19 -> V_57 . V_56 = V_19 -> V_56 ;
V_19 -> V_57 . V_53 = V_19 -> V_52 ;
V_18 -> V_58 [ V_49 ] = & V_19 -> V_57 ;
}
}
static T_1 F_28 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_17 * V_18 = F_29 ( V_3 ) ;
return sprintf ( V_11 , L_19 , V_18 -> V_59 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_29 ( V_3 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_18 -> V_50 ; V_49 ++ )
F_31 ( V_18 -> V_23 [ V_49 ] . V_31 ) ;
F_31 ( V_18 ) ;
}
static struct V_17 *
F_32 ( struct V_2 * V_27 ,
const struct V_60 * V_31 )
{
struct V_17 * V_18 ;
int V_37 ;
V_18 = F_33 ( sizeof( * V_18 ) , V_51 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_59 = V_31 -> V_59 ;
V_18 -> V_50 = V_31 -> V_50 ;
F_24 ( V_18 , V_31 -> V_23 , F_16 ( V_27 ) ) ;
V_18 -> V_3 . V_27 = V_27 ;
V_18 -> V_3 . V_61 = V_18 -> V_58 ;
V_18 -> V_3 . type = & V_62 ;
F_34 ( & V_18 -> V_3 , L_20 , V_18 -> V_59 ) ;
V_37 = F_35 ( & V_18 -> V_3 ) ;
if ( V_37 ) {
F_26 ( V_27 , L_21 ,
V_37 ) ;
F_36 ( & V_18 -> V_3 ) ;
return NULL ;
}
return V_18 ;
}
void F_37 ( struct V_17 * V_18 )
{
if ( V_18 )
F_38 ( & V_18 -> V_3 ) ;
}
static T_1 F_39 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_4 * V_63 = F_3 ( V_3 ) ;
return sprintf ( V_11 , L_8 , V_64 [ V_63 -> V_65 ] ) ;
}
static T_1 F_40 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_4 * V_63 = F_3 ( V_3 ) ;
return sprintf ( V_11 , L_8 , V_63 -> V_66 ? L_10 : L_11 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_31 ( V_5 ) ;
}
int F_42 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 )
return - V_67 ;
F_9 ( & V_5 -> V_3 ) ;
return 0 ;
}
struct V_17 *
F_43 ( struct V_4 * V_5 ,
const struct V_60 * V_31 )
{
return F_32 ( & V_5 -> V_3 , V_31 ) ;
}
struct V_4 * F_44 ( struct V_26 * V_34 ,
struct V_68 * V_31 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_33 ( sizeof( * V_5 ) , V_51 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_66 = V_31 -> V_66 ;
V_5 -> V_65 = V_31 -> V_65 ;
if ( V_31 -> V_6 ) {
V_5 -> V_3 . V_61 = V_69 ;
V_5 -> V_6 = V_31 -> V_6 ;
}
V_5 -> V_3 . V_70 = V_71 ;
V_5 -> V_3 . V_27 = & V_34 -> V_3 ;
V_5 -> V_3 . type = & V_72 ;
F_34 ( & V_5 -> V_3 , L_22 , F_45 ( & V_34 -> V_3 ) ) ;
V_37 = F_35 ( & V_5 -> V_3 ) ;
if ( V_37 ) {
F_26 ( & V_34 -> V_3 , L_23 , V_37 ) ;
F_36 ( & V_5 -> V_3 ) ;
return NULL ;
}
return V_5 ;
}
void F_46 ( struct V_4 * V_5 )
{
if ( V_5 )
F_38 ( & V_5 -> V_3 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_73 * V_74 = F_48 ( V_3 ) ;
F_31 ( V_74 ) ;
}
struct V_17 *
F_49 ( struct V_73 * V_74 ,
const struct V_60 * V_31 )
{
return F_32 ( & V_74 -> V_3 , V_31 ) ;
}
struct V_73 * F_50 ( struct V_7 * V_8 ,
struct V_75 * V_31 )
{
struct V_73 * V_74 ;
char V_53 [ 8 ] ;
int V_37 ;
V_74 = F_33 ( sizeof( * V_74 ) , V_51 ) ;
if ( ! V_74 )
return NULL ;
sprintf ( V_53 , L_24 , V_31 -> V_41 ) ;
V_74 -> V_41 = V_31 -> V_41 ;
V_74 -> V_3 . V_70 = V_71 ;
V_74 -> V_3 . V_27 = & V_8 -> V_3 ;
V_74 -> V_3 . type = & V_76 ;
F_34 ( & V_74 -> V_3 , L_25 , F_45 ( V_8 -> V_3 . V_27 ) , V_53 ) ;
V_37 = F_35 ( & V_74 -> V_3 ) ;
if ( V_37 ) {
F_26 ( & V_8 -> V_3 , L_26 , V_37 ) ;
F_36 ( & V_74 -> V_3 ) ;
return NULL ;
}
return V_74 ;
}
void F_51 ( struct V_73 * V_74 )
{
if ( V_74 )
F_38 ( & V_74 -> V_3 ) ;
}
static T_1
F_52 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
return sprintf ( V_11 , L_8 , V_8 -> V_20 ? L_7 : L_27 ) ;
}
static T_1 F_53 ( struct V_2 * V_3 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
return sprintf ( V_11 , L_8 , V_77 [ V_8 -> type ] ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
F_31 ( V_8 ) ;
}
int F_55 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_6 )
return - V_67 ;
F_9 ( & V_8 -> V_3 ) ;
return 0 ;
}
struct V_7 * F_56 ( struct V_26 * V_34 ,
struct V_78 * V_31 )
{
struct V_7 * V_8 ;
int V_37 ;
V_8 = F_33 ( sizeof( * V_8 ) , V_51 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> type = V_31 -> type ;
V_8 -> V_20 = V_31 -> V_20 ;
if ( V_31 -> V_6 ) {
V_8 -> V_3 . V_61 = V_69 ;
V_8 -> V_6 = V_31 -> V_6 ;
}
V_8 -> V_3 . V_70 = V_71 ;
V_8 -> V_3 . V_27 = & V_34 -> V_3 ;
V_8 -> V_3 . type = & V_79 ;
F_34 ( & V_8 -> V_3 , L_28 , F_45 ( & V_34 -> V_3 ) ) ;
V_37 = F_35 ( & V_8 -> V_3 ) ;
if ( V_37 ) {
F_26 ( & V_34 -> V_3 , L_29 , V_37 ) ;
F_36 ( & V_8 -> V_3 ) ;
return NULL ;
}
return V_8 ;
}
void F_57 ( struct V_7 * V_8 )
{
if ( V_8 )
F_38 ( & V_8 -> V_3 ) ;
}
static T_1
F_58 ( struct V_2 * V_3 , struct V_9 * V_10 ,
const char * V_11 , T_2 V_33 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
int V_80 ;
int V_37 ;
if ( V_34 -> V_38 -> type != V_46 ) {
F_59 ( V_3 , L_30 ) ;
return - V_40 ;
}
if ( ! V_34 -> V_38 -> V_81 ) {
F_59 ( V_3 , L_31 ) ;
return - V_40 ;
}
V_80 = F_60 ( V_82 , V_11 ) ;
if ( V_80 < 0 ) {
if ( F_61 ( V_11 , L_32 ) )
V_80 = V_83 ;
else
return - V_67 ;
}
V_37 = V_34 -> V_38 -> V_81 ( V_34 -> V_38 , V_80 ) ;
if ( V_37 )
return V_37 ;
V_34 -> V_84 = V_80 ;
return V_33 ;
}
static T_1
F_62 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
if ( V_34 -> V_38 -> type != V_46 )
return 0 ;
if ( V_34 -> V_84 < 0 )
return 0 ;
return sprintf ( V_11 , L_8 , V_82 [ V_34 -> V_84 ] ) ;
}
static T_1 F_63 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
const char * V_11 , T_2 V_33 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
int V_37 ;
if ( ! V_34 -> V_38 -> V_85 ) {
F_59 ( V_3 , L_33 ) ;
return - V_40 ;
}
V_37 = F_60 ( V_86 , V_11 ) ;
if ( V_37 < 0 )
return V_37 ;
F_64 ( & V_34 -> V_87 ) ;
if ( V_34 -> V_88 != V_46 ) {
F_59 ( V_3 , L_34 ,
V_89 [ V_34 -> V_88 ] ) ;
V_37 = - V_40 ;
goto V_90;
}
V_37 = V_34 -> V_38 -> V_85 ( V_34 -> V_38 , V_37 ) ;
if ( V_37 )
goto V_90;
V_37 = V_33 ;
V_90:
F_65 ( & V_34 -> V_87 ) ;
return V_37 ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
if ( V_34 -> V_38 -> type == V_46 )
return sprintf ( V_11 , L_8 , V_34 -> V_91 == V_92 ?
L_35 : L_36 ) ;
return sprintf ( V_11 , L_37 , V_86 [ V_34 -> V_91 ] ) ;
}
static T_1 F_67 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
const char * V_11 , T_2 V_33 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
int V_37 ;
if ( ! V_34 -> V_38 -> V_93 ) {
F_59 ( V_3 , L_38 ) ;
return - V_40 ;
}
if ( ! V_34 -> V_38 -> V_94 ) {
F_59 ( V_3 , L_39 ) ;
return - V_40 ;
}
if ( V_34 -> V_95 != V_96 ) {
F_59 ( V_3 , L_40 ) ;
return - V_97 ;
}
V_37 = F_60 ( V_82 , V_11 ) ;
if ( V_37 < 0 )
return V_37 ;
F_64 ( & V_34 -> V_87 ) ;
if ( V_34 -> V_88 != V_46 ) {
F_59 ( V_3 , L_34 ,
V_89 [ V_34 -> V_88 ] ) ;
V_37 = - V_40 ;
goto V_90;
}
V_37 = V_34 -> V_38 -> V_94 ( V_34 -> V_38 , V_37 ) ;
if ( V_37 )
goto V_90;
V_37 = V_33 ;
V_90:
F_65 ( & V_34 -> V_87 ) ;
return V_37 ;
}
static T_1 F_68 ( struct V_2 * V_3 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
if ( V_34 -> V_38 -> type == V_46 )
return sprintf ( V_11 , L_8 , V_34 -> V_98 == V_99 ?
L_41 : L_42 ) ;
return sprintf ( V_11 , L_37 , V_82 [ V_34 -> V_98 ] ) ;
}
static T_1
F_69 ( struct V_2 * V_3 , struct V_9 * V_10 ,
const char * V_11 , T_2 V_33 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
int V_37 ;
enum V_100 type ;
if ( ! V_34 -> V_38 -> V_101 || V_34 -> V_38 -> type != V_46 ) {
F_59 ( V_3 , L_43 ) ;
return - V_40 ;
}
V_37 = F_60 ( V_89 , V_11 ) ;
if ( V_37 < 0 )
return V_37 ;
type = V_37 ;
F_64 ( & V_34 -> V_87 ) ;
if ( V_34 -> V_88 == type ) {
V_37 = V_33 ;
goto V_90;
}
V_37 = V_34 -> V_38 -> V_101 ( V_34 -> V_38 , type ) ;
if ( V_37 )
goto V_90;
V_34 -> V_88 = type ;
V_37 = V_33 ;
V_90:
F_65 ( & V_34 -> V_87 ) ;
return V_37 ;
}
static T_1
F_70 ( struct V_2 * V_3 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
if ( V_34 -> V_38 -> type == V_46 )
return sprintf ( V_11 , L_8 ,
V_102 [ V_34 -> V_88 ] ) ;
return sprintf ( V_11 , L_37 , V_89 [ V_34 -> V_38 -> type ] ) ;
}
static T_1 F_71 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
return sprintf ( V_11 , L_8 , V_103 [ V_34 -> V_95 ] ) ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
const char * V_11 , T_2 V_33 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
bool V_104 ;
int V_37 ;
if ( ! V_34 -> V_38 -> V_93 ) {
F_59 ( V_3 , L_44 ) ;
return - V_40 ;
}
if ( ! V_34 -> V_38 -> V_105 ) {
F_59 ( V_3 , L_45 ) ;
return - V_40 ;
}
V_37 = F_22 ( V_11 , & V_104 ) ;
if ( V_37 )
return V_37 ;
V_37 = V_34 -> V_38 -> V_105 ( V_34 -> V_38 , (enum V_106 ) V_104 ) ;
if ( V_37 )
return V_37 ;
return V_33 ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
return sprintf ( V_11 , L_8 ,
V_34 -> V_107 == V_99 ? L_10 : L_11 ) ;
}
static T_1 F_74 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
T_1 V_37 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_75 ( V_34 -> V_38 -> V_65 ) ; V_49 ++ ) {
if ( V_34 -> V_38 -> V_65 [ V_49 ] )
V_37 += sprintf ( V_11 + V_37 , L_46 ,
V_64 [ V_34 -> V_38 -> V_65 [ V_49 ] ] ) ;
}
if ( ! V_37 )
return sprintf ( V_11 , L_47 ) ;
V_11 [ V_37 - 1 ] = '\n' ;
return V_37 ;
}
static T_1 F_76 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
T_3 V_108 = V_34 -> V_38 -> V_109 ;
return sprintf ( V_11 , L_48 , ( V_108 >> 8 ) & 0xff , ( V_108 >> 4 ) & 0xf ) ;
}
static T_1 F_77 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_26 * V_63 = F_15 ( V_3 ) ;
return sprintf ( V_11 , L_49 , ( V_63 -> V_38 -> V_93 >> 8 ) & 0xff ) ;
}
static int F_78 ( struct V_2 * V_3 , struct V_110 * V_111 )
{
int V_37 ;
V_37 = F_79 ( V_111 , L_50 , F_45 ( V_3 ) ) ;
if ( V_37 )
F_26 ( V_3 , L_51 ) ;
return V_37 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_26 * V_34 = F_15 ( V_3 ) ;
F_81 ( & V_112 , V_34 -> V_12 ) ;
F_31 ( V_34 ) ;
}
void F_82 ( struct V_26 * V_34 , enum V_113 V_80 )
{
if ( V_34 -> V_91 == V_80 )
return;
V_34 -> V_91 = V_80 ;
F_10 ( & V_34 -> V_3 . V_16 , NULL , L_52 ) ;
F_12 ( & V_34 -> V_3 . V_16 , V_25 ) ;
}
void F_83 ( struct V_26 * V_34 , enum V_106 V_80 )
{
if ( V_34 -> V_98 == V_80 )
return;
V_34 -> V_98 = V_80 ;
F_10 ( & V_34 -> V_3 . V_16 , NULL , L_53 ) ;
F_12 ( & V_34 -> V_3 . V_16 , V_25 ) ;
}
void F_84 ( struct V_26 * V_34 , enum V_106 V_80 )
{
if ( V_34 -> V_107 == V_80 )
return;
V_34 -> V_107 = V_80 ;
F_10 ( & V_34 -> V_3 . V_16 , NULL , L_54 ) ;
F_12 ( & V_34 -> V_3 . V_16 , V_25 ) ;
}
static int F_85 ( struct V_2 * V_3 , void * V_114 )
{
return F_2 ( V_3 ) ;
}
void F_86 ( struct V_26 * V_34 ,
enum V_115 V_116 )
{
struct V_2 * V_117 ;
if ( V_34 -> V_95 == V_116 )
return;
V_34 -> V_95 = V_116 ;
F_10 ( & V_34 -> V_3 . V_16 , NULL , L_55 ) ;
F_12 ( & V_34 -> V_3 . V_16 , V_25 ) ;
V_117 = F_87 ( & V_34 -> V_3 , NULL , F_85 ) ;
if ( V_117 ) {
struct V_4 * V_5 = F_3 ( V_117 ) ;
if ( V_116 == V_96 && ! V_5 -> V_66 ) {
V_5 -> V_66 = 1 ;
F_10 ( & V_117 -> V_16 , NULL ,
L_56 ) ;
}
F_36 ( V_117 ) ;
}
}
struct V_17 *
F_88 ( struct V_26 * V_34 ,
const struct V_60 * V_31 )
{
return F_32 ( & V_34 -> V_3 , V_31 ) ;
}
struct V_26 * F_89 ( struct V_2 * V_27 ,
const struct V_118 * V_38 )
{
struct V_26 * V_34 ;
int V_80 ;
int V_37 ;
int V_12 ;
V_34 = F_33 ( sizeof( * V_34 ) , V_51 ) ;
if ( ! V_34 )
return NULL ;
V_12 = F_90 ( & V_112 , 0 , 0 , V_51 ) ;
if ( V_12 < 0 ) {
F_31 ( V_34 ) ;
return NULL ;
}
if ( V_38 -> type == V_44 )
V_80 = V_99 ;
else if ( V_38 -> type == V_45 )
V_80 = V_119 ;
else
V_80 = V_38 -> V_84 ;
if ( V_80 == V_99 ) {
V_34 -> V_91 = V_92 ;
V_34 -> V_98 = V_99 ;
V_34 -> V_107 = V_99 ;
} else {
V_34 -> V_91 = V_120 ;
V_34 -> V_98 = V_119 ;
V_34 -> V_107 = V_119 ;
}
V_34 -> V_12 = V_12 ;
V_34 -> V_38 = V_38 ;
V_34 -> V_88 = V_38 -> type ;
F_91 ( & V_34 -> V_87 ) ;
V_34 -> V_84 = V_38 -> V_84 ;
V_34 -> V_3 . V_70 = V_71 ;
V_34 -> V_3 . V_27 = V_27 ;
V_34 -> V_3 . V_121 = V_38 -> V_121 ;
V_34 -> V_3 . type = & V_122 ;
F_34 ( & V_34 -> V_3 , L_57 , V_12 ) ;
V_37 = F_35 ( & V_34 -> V_3 ) ;
if ( V_37 ) {
F_26 ( V_27 , L_58 , V_37 ) ;
F_36 ( & V_34 -> V_3 ) ;
return NULL ;
}
return V_34 ;
}
void F_92 ( struct V_26 * V_34 )
{
if ( V_34 )
F_38 ( & V_34 -> V_3 ) ;
}
static int T_4 F_93 ( void )
{
V_71 = F_94 ( V_123 , L_59 ) ;
return F_95 ( V_71 ) ;
}
static void T_5 F_96 ( void )
{
F_97 ( V_71 ) ;
F_98 ( & V_112 ) ;
}
