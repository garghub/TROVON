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
return snprintf ( V_3 , V_4 , L_6 ,
V_2 -> V_19 . V_20 , V_2 -> V_19 . V_21 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 , V_2 -> V_19 . V_22 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_6 ,
V_2 -> V_19 . V_23 , V_2 -> V_19 . V_24 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_25 ;
struct V_26 V_19 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
V_19 . V_23 = F_15 ( V_3 , & V_25 , 10 ) ;
++ V_25 ;
if ( V_25 - V_3 >= V_7 )
return - V_14 ;
V_19 . V_24 = F_15 ( V_25 , & V_25 , 10 ) ;
V_9 = V_2 -> V_28 ( V_2 , & V_19 ) ;
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
return snprintf ( V_3 , V_4 , L_6 ,
V_2 -> V_19 . V_29 , V_2 -> V_19 . V_30 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_25 ;
struct V_26 V_19 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
V_19 . V_29 = F_15 ( V_3 , & V_25 , 10 ) ;
++ V_25 ;
if ( V_25 - V_3 >= V_7 )
return - V_14 ;
V_19 . V_30 = F_15 ( V_25 , & V_25 , 10 ) ;
V_9 = V_2 -> V_28 ( V_2 , & V_19 ) ;
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
return snprintf ( V_3 , V_4 , L_7 , V_2 -> V_19 . V_31 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_7 )
{
int V_9 , V_32 ;
struct V_26 V_19 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
V_9 = F_20 ( V_3 , 0 , & V_32 ) ;
if ( V_9 )
return V_9 ;
V_19 . V_31 = ! ! V_32 ;
V_9 = V_2 -> V_28 ( V_2 , & V_19 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_21 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 ,
V_2 -> V_19 . V_33 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_34 ;
struct V_26 V_19 ;
if ( ! F_23 ( V_35 ) )
return - V_36 ;
V_9 = F_24 ( V_3 , 0 , & V_34 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
if ( ! F_23 ( V_37 ) &&
V_2 -> V_38 == V_39 )
V_19 . V_33 = 255 ;
else
V_19 . V_33 = V_34 ;
V_9 = V_2 -> V_28 ( V_2 , & V_19 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 ,
V_2 -> V_19 . V_40 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_34 ;
struct V_26 V_19 ;
V_9 = F_24 ( V_3 , 0 , & V_34 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
if ( ! F_23 ( V_37 ) &&
V_2 -> V_38 == V_39 )
V_19 . V_40 = 0 ;
else
V_19 . V_40 = V_34 ;
V_9 = V_2 -> V_28 ( V_2 , & V_19 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_27 ( struct V_41 * V_42 , struct V_43 * V_44 ,
char * V_3 )
{
struct V_1 * V_45 ;
struct V_46 * V_47 ;
V_45 = F_28 ( V_42 , struct V_1 , V_42 ) ;
V_47 = F_28 ( V_44 , struct V_46 , V_44 ) ;
if ( ! V_47 -> V_48 )
return - V_49 ;
return V_47 -> V_48 ( V_45 , V_3 ) ;
}
static T_1 F_29 ( struct V_41 * V_42 , struct V_43 * V_44 ,
const char * V_3 , T_2 V_7 )
{
struct V_1 * V_45 ;
struct V_46 * V_47 ;
V_45 = F_28 ( V_42 , struct V_1 , V_42 ) ;
V_47 = F_28 ( V_44 , struct V_46 , V_44 ) ;
if ( ! V_47 -> V_50 )
return - V_49 ;
return V_47 -> V_50 ( V_45 , V_3 , V_7 ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
struct V_26 * V_19 ;
T_4 V_53 , V_54 ;
T_4 V_55 , V_56 ;
if ( ! V_52 )
return 0 ;
if ( ! V_2 -> V_19 . V_31 )
return 0 ;
V_19 = & V_2 -> V_19 ;
if ( V_19 -> V_57 == 0 ) {
F_7 ( L_8 ) ;
return - V_14 ;
}
V_52 -> V_58 -> V_59 ( V_52 , & V_55 , & V_56 ) ;
F_7 ( L_9 ,
V_2 -> V_38 ,
V_19 -> V_23 , V_19 -> V_24 ,
V_19 -> V_20 , V_19 -> V_21 ,
V_19 -> V_29 , V_19 -> V_30 ,
V_55 , V_56 ) ;
if ( ( V_2 -> V_60 & V_61 ) == 0 ) {
V_53 = V_19 -> V_20 ;
V_54 = V_19 -> V_21 ;
} else {
if ( V_19 -> V_29 == 0 )
V_53 = V_19 -> V_20 ;
else
V_53 = V_19 -> V_29 ;
if ( V_19 -> V_30 == 0 )
V_54 = V_19 -> V_21 ;
else
V_54 = V_19 -> V_30 ;
}
if ( V_55 < V_19 -> V_23 + V_53 ) {
F_7 ( L_10 ,
V_55 , V_19 -> V_23 , V_53 ) ;
return - V_14 ;
}
if ( V_56 < V_19 -> V_24 + V_54 ) {
F_7 ( L_11 ,
V_56 , V_19 -> V_24 , V_54 ) ;
return - V_14 ;
}
if ( ( V_2 -> V_62 & V_19 -> V_63 ) == 0 ) {
F_9 ( L_12 , V_19 -> V_63 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_26 * V_19 )
{
int V_9 ;
struct V_26 V_64 ;
V_64 = V_2 -> V_19 ;
V_2 -> V_19 = * V_19 ;
if ( V_2 -> V_6 ) {
V_9 = F_30 ( V_2 , V_2 -> V_6 -> V_65 ) ;
if ( V_9 ) {
V_2 -> V_19 = V_64 ;
return V_9 ;
}
}
V_2 -> V_66 = true ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_26 * V_19 )
{
* V_19 = V_2 -> V_19 ;
}
static int F_33 ( struct V_1 * V_2 )
{
return F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_14 ;
if ( V_2 -> V_6 ) {
F_9 ( L_13 ,
V_2 -> V_5 , V_2 -> V_6 -> V_5 ) ;
return - V_14 ;
}
if ( V_2 -> V_19 . V_31 ) {
F_9 ( L_14 ) ;
return - V_14 ;
}
V_2 -> V_6 = V_11 ;
F_36 ( V_2 -> V_38 , V_11 -> V_38 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_9 ;
if ( ! V_2 -> V_6 ) {
F_9 ( L_15 ) ;
return - V_14 ;
}
if ( V_2 -> V_19 . V_31 ) {
F_9 ( L_16 ) ;
return - V_14 ;
}
V_9 = V_2 -> V_67 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_6 = NULL ;
return 0 ;
}
int F_38 ( void )
{
return V_68 ;
}
struct V_1 * F_39 ( int V_69 )
{
int V_8 = 0 ;
struct V_1 * V_2 ;
F_40 (ovl, &overlay_list, list) {
if ( V_8 ++ == V_69 )
return V_2 ;
}
return NULL ;
}
static void F_41 ( struct V_1 * V_45 )
{
++ V_68 ;
F_42 ( & V_45 -> V_70 , & V_71 ) ;
}
void F_43 ( struct V_10 * V_11 )
{
V_11 -> V_68 = F_44 () ;
V_11 -> V_72 = V_73 ;
}
void F_45 ( struct V_10 * V_11 )
{
V_11 -> V_68 = 1 ;
V_11 -> V_72 = V_74 ;
}
void F_46 ( struct V_75 * V_76 )
{
int V_8 , V_9 ;
F_47 ( & V_71 ) ;
V_68 = 0 ;
for ( V_8 = 0 ; V_8 < F_44 () ; ++ V_8 ) {
struct V_1 * V_2 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_77 ) ;
F_49 ( V_2 == NULL ) ;
switch ( V_8 ) {
case 0 :
V_2 -> V_5 = L_17 ;
V_2 -> V_38 = V_78 ;
V_2 -> V_60 = V_79 ;
V_2 -> V_19 . V_33 = 255 ;
break;
case 1 :
V_2 -> V_5 = L_18 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_60 = V_61 |
V_79 ;
V_2 -> V_19 . V_33 = 255 ;
break;
case 2 :
V_2 -> V_5 = L_19 ;
V_2 -> V_38 = V_80 ;
V_2 -> V_60 = V_61 |
V_79 ;
V_2 -> V_19 . V_33 = 255 ;
break;
}
V_2 -> V_18 = & F_35 ;
V_2 -> V_15 = & F_37 ;
V_2 -> V_28 = & F_31 ;
V_2 -> V_27 = & F_32 ;
V_2 -> V_67 = & F_33 ;
V_2 -> V_62 =
F_50 ( V_2 -> V_38 ) ;
F_41 ( V_2 ) ;
V_9 = F_51 ( & V_2 -> V_42 , & V_81 ,
& V_76 -> V_82 . V_42 , L_20 , V_8 ) ;
if ( V_9 ) {
F_9 ( L_21 ) ;
continue;
}
V_73 [ V_8 ] = V_2 ;
}
#ifdef F_52
{
struct V_1 * V_2 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_77 ) ;
F_49 ( V_2 == NULL ) ;
V_2 -> V_5 = L_22 ;
V_2 -> V_62 = V_83 ;
V_2 -> V_18 = & F_35 ;
V_2 -> V_15 = & F_37 ;
V_2 -> V_28 = & F_31 ;
V_2 -> V_27 = & F_32 ;
F_41 ( V_2 ) ;
V_9 = F_51 ( & V_2 -> V_42 , & V_81 ,
& V_76 -> V_82 . V_42 , L_23 ) ;
if ( V_9 )
F_9 ( L_21 ) ;
V_74 [ 0 ] = V_2 ;
}
#endif
}
void F_53 ( struct V_51 * V_52 , bool V_84 )
{
int V_8 ;
struct V_10 * V_85 ;
struct V_10 * V_86 ;
struct V_10 * V_87 = NULL ;
struct V_10 * V_11 = NULL ;
V_85 = F_5 ( V_88 ) ;
V_86 = F_5 ( V_89 ) ;
if ( F_23 ( V_90 ) )
V_87 = F_5 ( V_91 ) ;
if ( V_52 -> V_92 == V_93 ) {
if ( ! V_87 -> V_65 || V_84 ) {
if ( V_87 -> V_65 )
V_87 -> V_94 ( V_87 ) ;
V_87 -> V_95 ( V_87 , V_52 ) ;
V_11 = V_87 ;
}
} else if ( V_52 -> type != V_96
&& V_52 -> type != V_97 ) {
if ( ! V_85 -> V_65 || V_84 ) {
if ( V_85 -> V_65 )
V_85 -> V_94 ( V_85 ) ;
V_85 -> V_95 ( V_85 , V_52 ) ;
V_11 = V_85 ;
}
}
if ( V_52 -> type == V_96
|| V_52 -> type == V_97 ) {
if ( ! V_86 -> V_65 || V_84 ) {
if ( V_86 -> V_65 )
V_86 -> V_94 ( V_86 ) ;
V_86 -> V_95 ( V_86 , V_52 ) ;
V_11 = V_86 ;
}
}
if ( V_11 ) {
F_8 () ;
for ( V_8 = 0 ; V_8 < F_44 () ; V_8 ++ ) {
struct V_1 * V_2 ;
V_2 = F_39 ( V_8 ) ;
if ( ! V_2 -> V_6 || V_84 ) {
if ( V_2 -> V_6 )
F_37 ( V_2 ) ;
F_35 ( V_2 , V_11 ) ;
}
}
F_10 () ;
}
}
void F_54 ( struct V_75 * V_76 )
{
struct V_1 * V_2 ;
while ( ! F_55 ( & V_71 ) ) {
V_2 = F_56 ( & V_71 ,
struct V_1 , V_70 ) ;
F_57 ( & V_2 -> V_70 ) ;
F_58 ( & V_2 -> V_42 ) ;
F_59 ( & V_2 -> V_42 ) ;
F_60 ( V_2 ) ;
}
V_68 = 0 ;
}
