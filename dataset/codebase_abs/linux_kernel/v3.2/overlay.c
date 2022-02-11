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
int V_9 ;
bool V_32 ;
struct V_26 V_19 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
V_9 = F_20 ( V_3 , & V_32 ) ;
if ( V_9 )
return V_9 ;
V_19 . V_31 = V_32 ;
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
if ( ( V_2 -> V_35 & V_36 ) == 0 )
return - V_37 ;
V_9 = F_23 ( V_3 , 0 , & V_34 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
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
static T_1 F_24 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 ,
V_2 -> V_19 . V_38 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_34 ;
struct V_26 V_19 ;
if ( ( V_2 -> V_35 & V_39 ) == 0 )
return - V_37 ;
V_9 = F_23 ( V_3 , 0 , & V_34 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
V_19 . V_38 = V_34 ;
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
static T_1 F_26 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 , V_2 -> V_19 . V_40 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_40 ;
struct V_26 V_19 ;
if ( ( V_2 -> V_35 & V_41 ) == 0 )
return - V_37 ;
V_9 = F_23 ( V_3 , 0 , & V_40 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_27 ( V_2 , & V_19 ) ;
V_19 . V_40 = V_40 ;
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
static T_1 F_28 ( struct V_42 * V_43 , struct V_44 * V_45 ,
char * V_3 )
{
struct V_1 * V_46 ;
struct V_47 * V_48 ;
V_46 = F_29 ( V_43 , struct V_1 , V_43 ) ;
V_48 = F_29 ( V_45 , struct V_47 , V_45 ) ;
if ( ! V_48 -> V_49 )
return - V_50 ;
return V_48 -> V_49 ( V_46 , V_3 ) ;
}
static T_1 F_30 ( struct V_42 * V_43 , struct V_44 * V_45 ,
const char * V_3 , T_2 V_7 )
{
struct V_1 * V_46 ;
struct V_47 * V_48 ;
V_46 = F_29 ( V_43 , struct V_1 , V_43 ) ;
V_48 = F_29 ( V_45 , struct V_47 , V_45 ) ;
if ( ! V_48 -> V_51 )
return - V_50 ;
return V_48 -> V_51 ( V_46 , V_3 , V_7 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_26 * V_19 ;
T_4 V_54 , V_55 ;
T_4 V_56 , V_57 ;
int V_8 ;
if ( ! V_53 )
return 0 ;
if ( ! V_2 -> V_19 . V_31 )
return 0 ;
V_19 = & V_2 -> V_19 ;
if ( V_19 -> V_58 == 0 ) {
F_7 ( L_8 ) ;
return - V_14 ;
}
V_53 -> V_59 -> V_60 ( V_53 , & V_56 , & V_57 ) ;
F_7 ( L_9 ,
V_2 -> V_61 ,
V_19 -> V_23 , V_19 -> V_24 ,
V_19 -> V_20 , V_19 -> V_21 ,
V_19 -> V_29 , V_19 -> V_30 ,
V_56 , V_57 ) ;
if ( ( V_2 -> V_35 & V_62 ) == 0 ) {
V_54 = V_19 -> V_20 ;
V_55 = V_19 -> V_21 ;
} else {
if ( V_19 -> V_29 == 0 )
V_54 = V_19 -> V_20 ;
else
V_54 = V_19 -> V_29 ;
if ( V_19 -> V_30 == 0 )
V_55 = V_19 -> V_21 ;
else
V_55 = V_19 -> V_30 ;
}
if ( V_56 < V_19 -> V_23 + V_54 ) {
F_7 ( L_10 ,
V_56 , V_19 -> V_23 , V_54 ) ;
return - V_14 ;
}
if ( V_57 < V_19 -> V_24 + V_55 ) {
F_7 ( L_11 ,
V_57 , V_19 -> V_24 , V_55 ) ;
return - V_14 ;
}
if ( ( V_2 -> V_63 & V_19 -> V_64 ) == 0 ) {
F_9 ( L_12 , V_19 -> V_64 ) ;
return - V_14 ;
}
if ( V_2 -> V_35 & V_41 ) {
if ( V_19 -> V_40 < 0 || V_19 -> V_40 > 3 ) {
F_9 ( L_13 ,
V_19 -> V_40 ) ;
return - V_14 ;
}
for ( V_8 = 0 ; V_8 < F_32 () ; V_8 ++ ) {
struct V_1 * V_65 = F_33 ( V_8 ) ;
if ( V_65 -> V_61 != V_2 -> V_61 &&
V_65 -> V_6 == V_2 -> V_6 &&
V_65 -> V_19 . V_31 == true &&
V_65 -> V_19 . V_40 == V_19 -> V_40 ) {
F_9 ( L_14 ,
V_2 -> V_5 , V_65 -> V_5 , V_19 -> V_40 ) ;
return - V_14 ;
}
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_26 * V_19 )
{
int V_9 ;
struct V_26 V_66 ;
V_66 = V_2 -> V_19 ;
V_2 -> V_19 = * V_19 ;
if ( V_2 -> V_6 ) {
V_9 = F_31 ( V_2 , V_2 -> V_6 -> V_67 ) ;
if ( V_9 ) {
V_2 -> V_19 = V_66 ;
return V_9 ;
}
}
V_2 -> V_68 = true ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_26 * V_19 )
{
* V_19 = V_2 -> V_19 ;
}
static int F_36 ( struct V_1 * V_2 )
{
return F_37 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_14 ;
if ( V_2 -> V_6 ) {
F_9 ( L_15 ,
V_2 -> V_5 , V_2 -> V_6 -> V_5 ) ;
return - V_14 ;
}
if ( V_2 -> V_19 . V_31 ) {
F_9 ( L_16 ) ;
return - V_14 ;
}
V_2 -> V_6 = V_11 ;
V_2 -> V_69 = true ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 ) {
F_9 ( L_17 ) ;
return - V_14 ;
}
if ( V_2 -> V_19 . V_31 ) {
F_9 ( L_18 ) ;
return - V_14 ;
}
V_2 -> V_6 = NULL ;
V_2 -> V_69 = true ;
return 0 ;
}
int F_32 ( void )
{
return V_70 ;
}
struct V_1 * F_33 ( int V_71 )
{
int V_8 = 0 ;
struct V_1 * V_2 ;
F_40 (ovl, &overlay_list, list) {
if ( V_8 ++ == V_71 )
return V_2 ;
}
return NULL ;
}
static void F_41 ( struct V_1 * V_46 )
{
++ V_70 ;
F_42 ( & V_46 -> V_72 , & V_73 ) ;
}
void F_43 ( struct V_10 * V_11 )
{
V_11 -> V_70 = F_44 () ;
V_11 -> V_74 = V_75 ;
}
void F_45 ( struct V_10 * V_11 )
{
V_11 -> V_70 = 1 ;
V_11 -> V_74 = V_76 ;
}
void F_46 ( struct V_77 * V_78 )
{
int V_8 , V_9 ;
F_47 ( & V_73 ) ;
V_70 = 0 ;
for ( V_8 = 0 ; V_8 < F_44 () ; ++ V_8 ) {
struct V_1 * V_2 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_79 ) ;
F_49 ( V_2 == NULL ) ;
switch ( V_8 ) {
case 0 :
V_2 -> V_5 = L_19 ;
V_2 -> V_61 = V_80 ;
V_2 -> V_19 . V_33 = 255 ;
V_2 -> V_19 . V_40 = 0 ;
break;
case 1 :
V_2 -> V_5 = L_20 ;
V_2 -> V_61 = V_81 ;
V_2 -> V_19 . V_33 = 255 ;
V_2 -> V_19 . V_40 =
F_50 ( V_82 ) ? 3 : 0 ;
break;
case 2 :
V_2 -> V_5 = L_21 ;
V_2 -> V_61 = V_83 ;
V_2 -> V_19 . V_33 = 255 ;
V_2 -> V_19 . V_40 =
F_50 ( V_82 ) ? 2 : 0 ;
break;
case 3 :
V_2 -> V_5 = L_22 ;
V_2 -> V_61 = V_84 ;
V_2 -> V_19 . V_33 = 255 ;
V_2 -> V_19 . V_40 =
F_50 ( V_82 ) ? 1 : 0 ;
break;
}
V_2 -> V_18 = & F_38 ;
V_2 -> V_15 = & F_39 ;
V_2 -> V_28 = & F_34 ;
V_2 -> V_27 = & F_35 ;
V_2 -> V_85 = & F_36 ;
V_2 -> V_35 = F_51 ( V_2 -> V_61 ) ;
V_2 -> V_63 =
F_52 ( V_2 -> V_61 ) ;
F_41 ( V_2 ) ;
V_9 = F_53 ( & V_2 -> V_43 , & V_86 ,
& V_78 -> V_87 . V_43 , L_23 , V_8 ) ;
if ( V_9 ) {
F_9 ( L_24 ) ;
continue;
}
V_75 [ V_8 ] = V_2 ;
}
#ifdef F_54
{
struct V_1 * V_2 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_79 ) ;
F_49 ( V_2 == NULL ) ;
V_2 -> V_5 = L_25 ;
V_2 -> V_63 = V_88 ;
V_2 -> V_18 = & F_38 ;
V_2 -> V_15 = & F_39 ;
V_2 -> V_28 = & F_34 ;
V_2 -> V_27 = & F_35 ;
F_41 ( V_2 ) ;
V_9 = F_53 ( & V_2 -> V_43 , & V_86 ,
& V_78 -> V_87 . V_43 , L_26 ) ;
if ( V_9 )
F_9 ( L_24 ) ;
V_76 [ 0 ] = V_2 ;
}
#endif
}
void F_55 ( struct V_52 * V_53 , bool V_89 )
{
int V_8 ;
struct V_10 * V_90 ;
struct V_10 * V_91 ;
struct V_10 * V_92 = NULL ;
struct V_10 * V_11 = NULL ;
V_90 = F_5 ( V_93 ) ;
V_91 = F_5 ( V_94 ) ;
if ( F_50 ( V_95 ) )
V_92 = F_5 ( V_96 ) ;
if ( V_53 -> V_97 == V_98 ) {
if ( ! V_92 -> V_67 || V_89 ) {
if ( V_92 -> V_67 )
V_92 -> V_99 ( V_92 ) ;
V_92 -> V_100 ( V_92 , V_53 ) ;
V_11 = V_92 ;
}
} else if ( V_53 -> type != V_101
&& V_53 -> type != V_102 ) {
if ( ! V_90 -> V_67 || V_89 ) {
if ( V_90 -> V_67 )
V_90 -> V_99 ( V_90 ) ;
V_90 -> V_100 ( V_90 , V_53 ) ;
V_11 = V_90 ;
}
}
if ( V_53 -> type == V_101
|| V_53 -> type == V_102 ) {
if ( ! V_91 -> V_67 || V_89 ) {
if ( V_91 -> V_67 )
V_91 -> V_99 ( V_91 ) ;
V_91 -> V_100 ( V_91 , V_53 ) ;
V_11 = V_91 ;
}
}
if ( V_11 ) {
F_8 () ;
for ( V_8 = 0 ; V_8 < F_44 () ; V_8 ++ ) {
struct V_1 * V_2 ;
V_2 = F_33 ( V_8 ) ;
if ( ! V_2 -> V_6 || V_89 ) {
if ( V_2 -> V_6 )
F_39 ( V_2 ) ;
F_38 ( V_2 , V_11 ) ;
}
}
F_10 () ;
}
}
void F_56 ( struct V_77 * V_78 )
{
struct V_1 * V_2 ;
while ( ! F_57 ( & V_73 ) ) {
V_2 = F_58 ( & V_73 ,
struct V_1 , V_72 ) ;
F_59 ( & V_2 -> V_72 ) ;
F_60 ( & V_2 -> V_43 ) ;
F_61 ( & V_2 -> V_43 ) ;
F_62 ( V_2 ) ;
}
V_70 = 0 ;
}
