static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_6 ? V_2 -> V_6 -> V_5 : L_2 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_7 )
{
int V_8 , V_9 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_12 ;
int V_13 = V_7 ;
if ( V_3 [ V_7 - 1 ] == '\n' )
-- V_13 ;
if ( V_13 > 0 ) {
for ( V_8 = 0 ; V_8 < F_4 () ; ++ V_8 ) {
V_11 = F_5 ( V_8 ) ;
if ( F_6 ( V_3 , V_11 -> V_5 ) )
break;
V_11 = NULL ;
}
}
if ( V_13 > 0 && V_11 == NULL )
return - V_14 ;
if ( V_11 )
F_7 ( L_3 , V_11 -> V_5 ) ;
if ( V_11 == V_2 -> V_6 )
return V_7 ;
V_12 = V_2 -> V_6 ;
V_9 = F_8 () ;
if ( V_9 )
return V_9 ;
if ( V_12 ) {
V_9 = V_2 -> V_15 ( V_2 ) ;
if ( V_9 ) {
F_9 ( L_4 ) ;
goto V_16;
}
V_9 = V_12 -> V_17 ( V_12 ) ;
if ( V_9 )
goto V_16;
}
if ( V_11 ) {
V_9 = V_2 -> V_18 ( V_2 , V_11 ) ;
if ( V_9 ) {
F_9 ( L_5 ) ;
goto V_16;
}
V_9 = V_11 -> V_17 ( V_11 ) ;
if ( V_9 )
goto V_16;
}
F_10 () ;
return V_7 ;
V_16:
F_10 () ;
return V_9 ;
}
static T_1 F_11 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_6 ,
V_20 . V_22 , V_20 . V_23 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 , V_20 . V_24 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_6 ,
V_20 . V_25 , V_20 . V_26 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_27 ;
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_25 = F_15 ( V_3 , & V_27 , 10 ) ;
++ V_27 ;
if ( V_27 - V_3 >= V_7 )
return - V_14 ;
V_20 . V_26 = F_15 ( V_27 , & V_27 , 10 ) ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_16 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_6 ,
V_20 . V_29 , V_20 . V_30 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_27 ;
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_29 = F_15 ( V_3 , & V_27 , 10 ) ;
++ V_27 ;
if ( V_27 - V_3 >= V_7 )
return - V_14 ;
V_20 . V_30 = F_15 ( V_27 , & V_27 , 10 ) ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_18 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 , V_2 -> V_31 ( V_2 ) ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_7 )
{
int V_9 ;
bool V_32 ;
V_9 = F_20 ( V_3 , & V_32 ) ;
if ( V_9 )
return V_9 ;
if ( V_32 )
V_9 = V_2 -> V_32 ( V_2 ) ;
else
V_9 = V_2 -> V_33 ( V_2 ) ;
if ( V_9 )
return V_9 ;
return V_7 ;
}
static T_1 F_21 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 ,
V_20 . V_34 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_35 ;
struct V_19 V_20 ;
if ( ( V_2 -> V_36 & V_37 ) == 0 )
return - V_38 ;
V_9 = F_23 ( V_3 , 0 , & V_35 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_34 = V_35 ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 ,
V_20 . V_39 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_35 ;
struct V_19 V_20 ;
if ( ( V_2 -> V_36 & V_40 ) == 0 )
return - V_38 ;
V_9 = F_23 ( V_3 , 0 , & V_35 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_39 = V_35 ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_26 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 , V_20 . V_41 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_41 ;
struct V_19 V_20 ;
if ( ( V_2 -> V_36 & V_42 ) == 0 )
return - V_38 ;
V_9 = F_23 ( V_3 , 0 , & V_41 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_41 = V_41 ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_28 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_3 )
{
struct V_1 * V_47 ;
struct V_48 * V_49 ;
V_47 = F_29 ( V_44 , struct V_1 , V_44 ) ;
V_49 = F_29 ( V_46 , struct V_48 , V_46 ) ;
if ( ! V_49 -> V_50 )
return - V_51 ;
return V_49 -> V_50 ( V_47 , V_3 ) ;
}
static T_1 F_30 ( struct V_43 * V_44 , struct V_45 * V_46 ,
const char * V_3 , T_2 V_7 )
{
struct V_1 * V_47 ;
struct V_48 * V_49 ;
V_47 = F_29 ( V_44 , struct V_1 , V_44 ) ;
V_49 = F_29 ( V_46 , struct V_48 , V_46 ) ;
if ( ! V_49 -> V_52 )
return - V_51 ;
return V_49 -> V_52 ( V_47 , V_3 , V_7 ) ;
}
int F_31 ( void )
{
return V_53 ;
}
struct V_1 * F_32 ( int V_54 )
{
if ( V_54 >= V_53 )
return NULL ;
return & V_55 [ V_54 ] ;
}
void F_33 ( struct V_56 * V_57 )
{
int V_8 , V_9 ;
V_53 = F_34 () ;
V_55 = F_35 ( sizeof( struct V_1 ) * V_53 ,
V_58 ) ;
F_36 ( V_55 == NULL ) ;
for ( V_8 = 0 ; V_8 < V_53 ; ++ V_8 ) {
struct V_1 * V_2 = & V_55 [ V_8 ] ;
switch ( V_8 ) {
case 0 :
V_2 -> V_5 = L_8 ;
V_2 -> V_59 = V_60 ;
break;
case 1 :
V_2 -> V_5 = L_9 ;
V_2 -> V_59 = V_61 ;
break;
case 2 :
V_2 -> V_5 = L_10 ;
V_2 -> V_59 = V_62 ;
break;
case 3 :
V_2 -> V_5 = L_11 ;
V_2 -> V_59 = V_63 ;
break;
}
V_2 -> V_31 = & V_64 ;
V_2 -> V_32 = & V_65 ;
V_2 -> V_33 = & V_66 ;
V_2 -> V_18 = & V_67 ;
V_2 -> V_15 = & V_68 ;
V_2 -> V_28 = & V_69 ;
V_2 -> V_21 = & V_70 ;
V_2 -> V_71 = & V_72 ;
V_2 -> V_36 = F_37 ( V_2 -> V_59 ) ;
V_2 -> V_73 =
F_38 ( V_2 -> V_59 ) ;
V_9 = F_39 ( & V_2 -> V_44 , & V_74 ,
& V_57 -> V_75 . V_44 , L_12 , V_8 ) ;
if ( V_9 )
F_9 ( L_13 ) ;
}
}
void F_40 ( struct V_76 * V_77 , bool V_78 )
{
int V_8 ;
struct V_10 * V_79 ;
struct V_10 * V_80 ;
struct V_10 * V_81 = NULL ;
struct V_10 * V_82 = NULL ;
struct V_10 * V_11 = NULL ;
V_79 = F_5 ( V_83 ) ;
V_80 = F_5 ( V_84 ) ;
if ( F_41 ( V_85 ) )
V_82 = F_5 ( V_86 ) ;
if ( F_41 ( V_87 ) )
V_81 = F_5 ( V_88 ) ;
if ( V_77 -> V_89 == V_86 ) {
if ( ! V_82 -> V_90 || V_78 ) {
if ( V_82 -> V_90 )
V_82 -> V_91 ( V_82 ) ;
V_82 -> V_92 ( V_82 , V_77 ) ;
V_11 = V_82 ;
}
} else if ( V_77 -> V_89 == V_88 ) {
if ( ! V_81 -> V_90 || V_78 ) {
if ( V_81 -> V_90 )
V_81 -> V_91 ( V_81 ) ;
V_81 -> V_92 ( V_81 , V_77 ) ;
V_11 = V_81 ;
}
} else if ( V_77 -> type != V_93
&& V_77 -> type != V_94 ) {
if ( ! V_79 -> V_90 || V_78 ) {
if ( V_79 -> V_90 )
V_79 -> V_91 ( V_79 ) ;
V_79 -> V_92 ( V_79 , V_77 ) ;
V_11 = V_79 ;
}
}
if ( V_77 -> type == V_93
|| V_77 -> type == V_94 ) {
if ( ! V_80 -> V_90 || V_78 ) {
if ( V_80 -> V_90 )
V_80 -> V_91 ( V_80 ) ;
V_80 -> V_92 ( V_80 , V_77 ) ;
V_11 = V_80 ;
}
}
if ( V_11 ) {
F_8 () ;
for ( V_8 = 0 ; V_8 < F_34 () ; V_8 ++ ) {
struct V_1 * V_2 ;
V_2 = F_32 ( V_8 ) ;
if ( ! V_2 -> V_6 || V_78 ) {
if ( V_2 -> V_6 )
V_2 -> V_15 ( V_2 ) ;
V_2 -> V_18 ( V_2 , V_11 ) ;
}
}
F_10 () ;
}
}
void F_42 ( struct V_56 * V_57 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_53 ; ++ V_8 ) {
struct V_1 * V_2 = & V_55 [ V_8 ] ;
F_43 ( & V_2 -> V_44 ) ;
F_44 ( & V_2 -> V_44 ) ;
}
F_45 ( V_55 ) ;
V_55 = NULL ;
V_53 = 0 ;
}
int F_46 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
if ( V_20 -> V_95 == 0 ) {
F_9 ( L_14 ) ;
return - V_14 ;
}
if ( ( V_2 -> V_36 & V_96 ) == 0 ) {
if ( V_20 -> V_29 != 0 && V_20 -> V_22 != V_20 -> V_29 ) {
F_9 ( L_15
L_16 , V_2 -> V_59 ) ;
return - V_14 ;
}
if ( V_20 -> V_30 != 0 && V_20 -> V_23 != V_20 -> V_30 ) {
F_9 ( L_15
L_16 , V_2 -> V_59 ) ;
return - V_14 ;
}
}
if ( ( V_2 -> V_73 & V_20 -> V_97 ) == 0 ) {
F_9 ( L_17 ,
V_2 -> V_59 , V_20 -> V_97 ) ;
return - V_14 ;
}
if ( V_20 -> V_41 >= F_31 () ) {
F_9 ( L_18 , V_20 -> V_41 ) ;
return - V_14 ;
}
if ( F_47 ( V_20 -> V_98 ) == 0 ) {
F_9 ( L_19 ,
V_20 -> V_98 ) ;
return - V_14 ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 , struct V_19 * V_20 ,
const struct V_99 * V_100 )
{
T_4 V_101 , V_102 ;
T_4 V_103 , V_104 ;
V_103 = V_100 -> V_105 ;
V_104 = V_100 -> V_106 ;
if ( ( V_2 -> V_36 & V_96 ) == 0 ) {
V_101 = V_20 -> V_22 ;
V_102 = V_20 -> V_23 ;
} else {
if ( V_20 -> V_29 == 0 )
V_101 = V_20 -> V_22 ;
else
V_101 = V_20 -> V_29 ;
if ( V_20 -> V_30 == 0 )
V_102 = V_20 -> V_23 ;
else
V_102 = V_20 -> V_30 ;
}
if ( V_103 < V_20 -> V_25 + V_101 ) {
F_9 ( L_20
L_21 ,
V_2 -> V_59 , V_20 -> V_25 , V_101 , V_103 ) ;
return - V_14 ;
}
if ( V_104 < V_20 -> V_26 + V_102 ) {
F_9 ( L_22
L_21 ,
V_2 -> V_59 , V_20 -> V_26 , V_102 , V_104 ) ;
return - V_14 ;
}
return 0 ;
}
bool F_49 ( struct V_107 V_108 ,
enum V_109 V_110 )
{
if ( V_110 != V_111 && V_110 != V_112 )
return false ;
return V_108 . V_113 > 16 ;
}
