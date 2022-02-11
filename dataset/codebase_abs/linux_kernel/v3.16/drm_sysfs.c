static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> type == & V_4 ) {
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 ;
if ( V_5 -> type == V_8 &&
! F_3 ( V_7 , V_9 ) &&
V_7 -> V_10 -> V_11 )
return V_7 -> V_10 -> V_11 ( V_7 , V_3 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> type == & V_4 ) {
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 ;
if ( V_5 -> type == V_8 &&
! F_3 ( V_7 , V_9 ) &&
V_7 -> V_10 -> V_14 )
return V_7 -> V_10 -> V_14 ( V_7 ) ;
}
return 0 ;
}
static char * F_7 ( struct V_1 * V_2 , T_2 * V_15 )
{
return F_8 ( V_16 , L_1 , F_9 ( V_2 ) ) ;
}
struct V_17 * F_10 ( struct V_18 * V_19 , char * V_20 )
{
struct V_17 * V_17 ;
int V_21 ;
V_17 = F_11 ( V_19 , V_20 ) ;
if ( F_12 ( V_17 ) ) {
V_21 = F_13 ( V_17 ) ;
goto V_22;
}
V_17 -> V_23 = & V_24 ;
V_21 = F_14 ( V_17 , & V_25 . V_26 ) ;
if ( V_21 )
goto V_27;
V_17 -> V_28 = F_7 ;
return V_17 ;
V_27:
F_15 ( V_17 ) ;
V_22:
return F_16 ( V_21 ) ;
}
void F_17 ( void )
{
if ( ( V_29 == NULL ) || ( F_12 ( V_29 ) ) )
return;
F_18 ( V_29 , & V_25 . V_26 ) ;
F_15 ( V_29 ) ;
V_29 = NULL ;
}
static T_3 F_19 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
enum V_34 V_35 ;
int V_36 ;
V_36 = F_21 ( & V_33 -> V_2 -> V_37 . V_38 ) ;
if ( V_36 )
return V_36 ;
V_35 = V_33 -> V_39 -> V_40 ( V_33 , true ) ;
F_22 ( & V_33 -> V_2 -> V_37 . V_38 ) ;
return snprintf ( V_31 , V_41 , L_2 ,
F_23 ( V_35 ) ) ;
}
static T_3 F_24 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_33 -> V_2 ;
T_4 V_42 ;
int V_36 ;
V_36 = F_25 ( & V_33 -> V_43 ,
V_2 -> V_37 . V_44 ,
& V_42 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_2 ,
F_26 ( ( int ) V_42 ) ) ;
}
static T_3 F_27 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
return snprintf ( V_31 , V_41 , L_2 , V_33 -> V_45 ? L_3 :
L_4 ) ;
}
static T_3 F_28 ( struct V_46 * V_47 , struct V_48 * V_49 ,
struct V_50 * V_26 , char * V_31 , T_5 V_51 ,
T_6 V_52 )
{
struct V_1 * V_53 = F_29 ( V_49 , struct V_1 , V_49 ) ;
struct V_32 * V_33 = F_20 ( V_53 ) ;
unsigned char * V_54 ;
T_6 V_55 ;
if ( ! V_33 -> V_56 )
return 0 ;
V_54 = V_33 -> V_56 -> V_57 ;
V_55 = V_33 -> V_56 -> V_58 ;
if ( ! V_54 )
return 0 ;
if ( V_51 >= V_55 )
return 0 ;
if ( V_51 + V_52 > V_55 )
V_52 = V_55 - V_51 ;
memcpy ( V_31 , V_54 + V_51 , V_52 ) ;
return V_52 ;
}
static T_3 F_30 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_59 * V_15 ;
int V_60 = 0 ;
F_31 (mode, &connector->modes, head) {
V_60 += snprintf ( V_31 + V_60 , V_41 - V_60 , L_2 ,
V_15 -> V_20 ) ;
}
return V_60 ;
}
static T_3 F_32 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_33 -> V_2 ;
struct V_61 * V_62 = NULL ;
T_4 V_63 ;
int V_64 = 0 ;
int V_36 ;
switch ( V_33 -> V_65 ) {
case V_66 :
V_62 = V_2 -> V_37 . V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_62 = V_2 -> V_37 . V_72 ;
V_64 = 1 ;
break;
default:
F_33 ( L_5 ) ;
return 0 ;
}
if ( ! V_62 ) {
F_33 ( L_6 ) ;
return 0 ;
}
V_36 = F_25 ( & V_33 -> V_43 , V_62 , & V_63 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_7 , V_64 ?
F_34 ( ( int ) V_63 ) :
F_35 ( ( int ) V_63 ) ) ;
}
static T_3 F_36 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_33 -> V_2 ;
struct V_61 * V_62 = NULL ;
T_4 V_63 ;
int V_64 = 0 ;
int V_36 ;
switch ( V_33 -> V_65 ) {
case V_66 :
V_62 = V_2 -> V_37 . V_73 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_62 = V_2 -> V_37 . V_74 ;
V_64 = 1 ;
break;
default:
F_33 ( L_5 ) ;
return 0 ;
}
if ( ! V_62 ) {
F_33 ( L_8 ) ;
return 0 ;
}
V_36 = F_25 ( & V_33 -> V_43 , V_62 , & V_63 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_7 , V_64 ?
F_37 ( ( int ) V_63 ) :
F_38 ( ( int ) V_63 ) ) ;
}
int F_39 ( struct V_32 * V_33 )
{
struct V_6 * V_2 = V_33 -> V_2 ;
int V_75 = 0 ;
int V_76 = 0 ;
int V_77 ;
int V_36 ;
if ( V_33 -> V_78 )
return 0 ;
V_33 -> V_78 = F_40 ( V_29 , V_2 -> V_79 -> V_78 ,
0 , V_33 , L_9 ,
V_2 -> V_79 -> V_80 , V_33 -> V_20 ) ;
F_41 ( L_10 ,
V_33 -> V_20 ) ;
if ( F_12 ( V_33 -> V_78 ) ) {
F_33 ( L_11 , F_13 ( V_33 -> V_78 ) ) ;
V_36 = F_13 ( V_33 -> V_78 ) ;
goto V_81;
}
for ( V_75 = 0 ; V_75 < F_42 ( V_82 ) ; V_75 ++ ) {
V_36 = F_43 ( V_33 -> V_78 , & V_82 [ V_75 ] ) ;
if ( V_36 )
goto V_83;
}
switch ( V_33 -> V_65 ) {
case V_66 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
for ( V_76 = 0 ; V_76 < F_42 ( V_84 ) ; V_76 ++ ) {
V_36 = F_43 ( V_33 -> V_78 , & V_84 [ V_76 ] ) ;
if ( V_36 )
goto V_83;
}
break;
default:
break;
}
V_36 = F_44 ( & V_33 -> V_78 -> V_49 , & V_85 ) ;
if ( V_36 )
goto V_83;
F_45 ( V_2 ) ;
return 0 ;
V_83:
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_46 ( V_33 -> V_78 , & V_84 [ V_77 ] ) ;
for ( V_77 = 0 ; V_77 < V_75 ; V_77 ++ )
F_46 ( V_33 -> V_78 , & V_82 [ V_77 ] ) ;
F_47 ( V_33 -> V_78 ) ;
V_81:
return V_36 ;
}
void F_48 ( struct V_32 * V_33 )
{
int V_77 ;
if ( ! V_33 -> V_78 )
return;
F_41 ( L_12 ,
V_33 -> V_20 ) ;
for ( V_77 = 0 ; V_77 < F_42 ( V_82 ) ; V_77 ++ )
F_46 ( V_33 -> V_78 , & V_82 [ V_77 ] ) ;
F_49 ( & V_33 -> V_78 -> V_49 , & V_85 ) ;
F_47 ( V_33 -> V_78 ) ;
V_33 -> V_78 = NULL ;
}
void F_45 ( struct V_6 * V_2 )
{
char * V_86 = L_13 ;
char * V_87 [] = { V_86 , NULL } ;
F_41 ( L_14 ) ;
F_50 ( & V_2 -> V_79 -> V_78 -> V_49 , V_88 , V_87 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 ) ;
}
int F_53 ( struct V_5 * V_89 )
{
char * V_90 ;
int V_91 ;
if ( V_89 -> type == V_92 )
V_90 = L_15 ;
else if ( V_89 -> type == V_93 )
V_90 = L_16 ;
else
V_90 = L_17 ;
V_89 -> V_78 = F_54 ( sizeof( * V_89 -> V_78 ) , V_16 ) ;
if ( ! V_89 -> V_78 ) {
V_91 = - V_94 ;
goto error;
}
F_55 ( V_89 -> V_78 ) ;
V_89 -> V_78 -> V_95 = F_56 ( V_96 , V_89 -> V_80 ) ;
V_89 -> V_78 -> V_17 = V_29 ;
V_89 -> V_78 -> type = & V_4 ;
V_89 -> V_78 -> V_97 = V_89 -> V_2 -> V_2 ;
V_89 -> V_78 -> V_98 = F_51 ;
F_57 ( V_89 -> V_78 , V_89 ) ;
V_91 = F_58 ( V_89 -> V_78 , V_90 , V_89 -> V_80 ) ;
if ( V_91 < 0 )
goto error;
V_91 = F_59 ( V_89 -> V_78 ) ;
if ( V_91 < 0 )
goto error;
return 0 ;
error:
F_33 ( L_18 , V_91 ) ;
F_60 ( V_89 -> V_78 ) ;
return V_91 ;
}
void F_61 ( struct V_5 * V_89 )
{
if ( V_89 -> V_78 )
F_47 ( V_89 -> V_78 ) ;
V_89 -> V_78 = NULL ;
}
int F_62 ( struct V_1 * V_2 )
{
if ( ! V_29 || F_12 ( V_29 ) )
return - V_99 ;
V_2 -> V_17 = V_29 ;
return F_63 ( V_2 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
