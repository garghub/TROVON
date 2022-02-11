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
static void F_19 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
return;
}
static T_3 F_20 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_21 ( V_1 ) ;
enum V_34 V_35 ;
int V_36 ;
V_36 = F_22 ( & V_33 -> V_2 -> V_37 . V_38 ) ;
if ( V_36 )
return V_36 ;
V_35 = V_33 -> V_39 -> V_40 ( V_33 , true ) ;
F_23 ( & V_33 -> V_2 -> V_37 . V_38 ) ;
return snprintf ( V_31 , V_41 , L_2 ,
F_24 ( V_35 ) ) ;
}
static T_3 F_25 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_21 ( V_1 ) ;
struct V_6 * V_2 = V_33 -> V_2 ;
T_4 V_42 ;
int V_36 ;
V_36 = F_26 ( & V_33 -> V_43 ,
V_2 -> V_37 . V_44 ,
& V_42 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_2 ,
F_27 ( ( int ) V_42 ) ) ;
}
static T_3 F_28 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_21 ( V_1 ) ;
return snprintf ( V_31 , V_41 , L_2 , V_33 -> V_45 ? L_3 :
L_4 ) ;
}
static T_3 F_29 ( struct V_46 * V_47 , struct V_48 * V_49 ,
struct V_50 * V_26 , char * V_31 , T_5 V_51 ,
T_6 V_52 )
{
struct V_1 * V_53 = F_30 ( V_49 , struct V_1 , V_49 ) ;
struct V_32 * V_33 = F_21 ( V_53 ) ;
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
static T_3 F_31 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_21 ( V_1 ) ;
struct V_59 * V_15 ;
int V_60 = 0 ;
F_32 (mode, &connector->modes, head) {
V_60 += snprintf ( V_31 + V_60 , V_41 - V_60 , L_2 ,
V_15 -> V_20 ) ;
}
return V_60 ;
}
static T_3 F_33 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_21 ( V_1 ) ;
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
F_34 ( L_5 ) ;
return 0 ;
}
if ( ! V_62 ) {
F_34 ( L_6 ) ;
return 0 ;
}
V_36 = F_26 ( & V_33 -> V_43 , V_62 , & V_63 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_7 , V_64 ?
F_35 ( ( int ) V_63 ) :
F_36 ( ( int ) V_63 ) ) ;
}
static T_3 F_37 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_21 ( V_1 ) ;
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
F_34 ( L_5 ) ;
return 0 ;
}
if ( ! V_62 ) {
F_34 ( L_8 ) ;
return 0 ;
}
V_36 = F_26 ( & V_33 -> V_43 , V_62 , & V_63 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_7 , V_64 ?
F_38 ( ( int ) V_63 ) :
F_39 ( ( int ) V_63 ) ) ;
}
int F_40 ( struct V_32 * V_33 )
{
struct V_6 * V_2 = V_33 -> V_2 ;
int V_75 = 0 ;
int V_76 = 0 ;
int V_77 ;
int V_36 ;
F_41 ( F_42 ( & V_33 -> V_78 ) ) ;
V_33 -> V_78 . V_79 = & V_2 -> V_80 -> V_78 ;
V_33 -> V_78 . V_17 = V_29 ;
V_33 -> V_78 . V_81 = F_19 ;
F_43 ( L_9 ,
F_44 ( V_33 ) ) ;
F_45 ( & V_33 -> V_78 , L_10 ,
V_2 -> V_80 -> V_82 , F_44 ( V_33 ) ) ;
V_36 = F_46 ( & V_33 -> V_78 ) ;
if ( V_36 ) {
F_34 ( L_11 , V_36 ) ;
goto V_83;
}
for ( V_75 = 0 ; V_75 < F_47 ( V_84 ) ; V_75 ++ ) {
V_36 = F_48 ( & V_33 -> V_78 , & V_84 [ V_75 ] ) ;
if ( V_36 )
goto V_85;
}
switch ( V_33 -> V_65 ) {
case V_66 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
for ( V_76 = 0 ; V_76 < F_47 ( V_86 ) ; V_76 ++ ) {
V_36 = F_48 ( & V_33 -> V_78 , & V_86 [ V_76 ] ) ;
if ( V_36 )
goto V_85;
}
break;
default:
break;
}
V_36 = F_49 ( & V_33 -> V_78 . V_49 , & V_87 ) ;
if ( V_36 )
goto V_85;
F_50 ( V_2 ) ;
return 0 ;
V_85:
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_51 ( & V_33 -> V_78 , & V_86 [ V_77 ] ) ;
for ( V_77 = 0 ; V_77 < V_75 ; V_77 ++ )
F_51 ( & V_33 -> V_78 , & V_84 [ V_77 ] ) ;
F_52 ( & V_33 -> V_78 ) ;
V_83:
return V_36 ;
}
void F_53 ( struct V_32 * V_33 )
{
int V_77 ;
if ( ! V_33 -> V_78 . V_79 )
return;
F_43 ( L_12 ,
F_44 ( V_33 ) ) ;
for ( V_77 = 0 ; V_77 < F_47 ( V_84 ) ; V_77 ++ )
F_51 ( & V_33 -> V_78 , & V_84 [ V_77 ] ) ;
F_54 ( & V_33 -> V_78 . V_49 , & V_87 ) ;
F_52 ( & V_33 -> V_78 ) ;
V_33 -> V_78 . V_79 = NULL ;
}
void F_50 ( struct V_6 * V_2 )
{
char * V_88 = L_13 ;
char * V_89 [] = { V_88 , NULL } ;
F_43 ( L_14 ) ;
F_55 ( & V_2 -> V_80 -> V_78 . V_49 , V_90 , V_89 ) ;
}
int F_56 ( struct V_5 * V_91 )
{
int V_21 ;
char * V_92 ;
V_91 -> V_78 . V_79 = V_91 -> V_2 -> V_2 ;
V_91 -> V_78 . V_17 = V_29 ;
V_91 -> V_78 . V_81 = F_19 ;
V_91 -> V_78 . V_93 = V_91 -> V_1 ;
V_91 -> V_78 . type = & V_4 ;
if ( V_91 -> type == V_94 )
V_92 = L_15 ;
else if ( V_91 -> type == V_95 )
V_92 = L_16 ;
else
V_92 = L_17 ;
F_45 ( & V_91 -> V_78 , V_92 , V_91 -> V_82 ) ;
V_21 = F_46 ( & V_91 -> V_78 ) ;
if ( V_21 ) {
F_34 ( L_18 , V_21 ) ;
goto V_22;
}
return 0 ;
V_22:
return V_21 ;
}
void F_57 ( struct V_5 * V_91 )
{
if ( V_91 -> V_78 . V_79 )
F_52 ( & V_91 -> V_78 ) ;
V_91 -> V_78 . V_79 = NULL ;
}
int F_58 ( struct V_1 * V_2 )
{
if ( ! V_29 || F_12 ( V_29 ) )
return - V_96 ;
V_2 -> V_17 = V_29 ;
return F_46 ( V_2 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
return F_52 ( V_2 ) ;
}
