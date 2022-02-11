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
if ( V_2 -> type == & V_4 ) {
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 ;
if ( V_5 -> type == V_8 &&
! F_3 ( V_7 , V_9 ) &&
V_7 -> V_10 -> V_12 )
return V_7 -> V_10 -> V_12 ( V_7 ) ;
}
return 0 ;
}
static char * F_5 ( struct V_1 * V_2 , T_2 * V_13 )
{
return F_6 ( V_14 , L_1 , F_7 ( V_2 ) ) ;
}
struct V_15 * F_8 ( struct V_16 * V_17 , char * V_18 )
{
struct V_15 * V_15 ;
int V_19 ;
V_15 = F_9 ( V_17 , V_18 ) ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
goto V_20;
}
V_15 -> V_11 = F_1 ;
V_15 -> V_12 = F_4 ;
V_19 = F_12 ( V_15 , & V_21 . V_22 ) ;
if ( V_19 )
goto V_23;
V_15 -> V_24 = F_5 ;
return V_15 ;
V_23:
F_13 ( V_15 ) ;
V_20:
return F_14 ( V_19 ) ;
}
void F_15 ( void )
{
if ( ( V_25 == NULL ) || ( F_10 ( V_25 ) ) )
return;
F_16 ( V_25 , & V_21 . V_22 ) ;
F_13 ( V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
return;
}
static T_3 F_18 ( struct V_1 * V_1 ,
struct V_26 * V_22 ,
char * V_27 )
{
struct V_28 * V_29 = F_19 ( V_1 ) ;
enum V_30 V_31 ;
int V_32 ;
V_32 = F_20 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_29 -> V_35 -> V_36 ( V_29 , true ) ;
F_21 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
return snprintf ( V_27 , V_37 , L_2 ,
F_22 ( V_31 ) ) ;
}
static T_3 F_23 ( struct V_1 * V_1 ,
struct V_26 * V_22 ,
char * V_27 )
{
struct V_28 * V_29 = F_19 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
T_4 V_38 ;
int V_32 ;
V_32 = F_24 ( V_29 ,
V_2 -> V_33 . V_39 ,
& V_38 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_27 , V_37 , L_2 ,
F_25 ( ( int ) V_38 ) ) ;
}
static T_3 F_26 ( struct V_1 * V_1 ,
struct V_26 * V_22 ,
char * V_27 )
{
struct V_28 * V_29 = F_19 ( V_1 ) ;
return snprintf ( V_27 , V_37 , L_2 , V_29 -> V_40 ? L_3 :
L_4 ) ;
}
static T_3 F_27 ( struct V_41 * V_42 , struct V_43 * V_44 ,
struct V_45 * V_22 , char * V_27 , T_5 V_46 ,
T_6 V_47 )
{
struct V_1 * V_48 = F_28 ( V_44 , struct V_1 , V_44 ) ;
struct V_28 * V_29 = F_19 ( V_48 ) ;
unsigned char * V_49 ;
T_6 V_50 ;
if ( ! V_29 -> V_51 )
return 0 ;
V_49 = V_29 -> V_51 -> V_52 ;
V_50 = V_29 -> V_51 -> V_53 ;
if ( ! V_49 )
return 0 ;
if ( V_46 >= V_50 )
return 0 ;
if ( V_46 + V_47 > V_50 )
V_47 = V_50 - V_46 ;
memcpy ( V_27 , V_49 + V_46 , V_47 ) ;
return V_47 ;
}
static T_3 F_29 ( struct V_1 * V_1 ,
struct V_26 * V_22 ,
char * V_27 )
{
struct V_28 * V_29 = F_19 ( V_1 ) ;
struct V_54 * V_13 ;
int V_55 = 0 ;
F_30 (mode, &connector->modes, head) {
V_55 += snprintf ( V_27 + V_55 , V_37 - V_55 , L_2 ,
V_13 -> V_18 ) ;
}
return V_55 ;
}
static T_3 F_31 ( struct V_1 * V_1 ,
struct V_26 * V_22 ,
char * V_27 )
{
struct V_28 * V_29 = F_19 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_56 * V_57 = NULL ;
T_4 V_58 ;
int V_59 = 0 ;
int V_32 ;
switch ( V_29 -> V_60 ) {
case V_61 :
V_57 = V_2 -> V_33 . V_62 ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_57 = V_2 -> V_33 . V_67 ;
V_59 = 1 ;
break;
default:
F_32 ( L_5 ) ;
return 0 ;
}
if ( ! V_57 ) {
F_32 ( L_6 ) ;
return 0 ;
}
V_32 = F_24 ( V_29 , V_57 , & V_58 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_27 , V_37 , L_7 , V_59 ?
F_33 ( ( int ) V_58 ) :
F_34 ( ( int ) V_58 ) ) ;
}
static T_3 F_35 ( struct V_1 * V_1 ,
struct V_26 * V_22 ,
char * V_27 )
{
struct V_28 * V_29 = F_19 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_56 * V_57 = NULL ;
T_4 V_58 ;
int V_59 = 0 ;
int V_32 ;
switch ( V_29 -> V_60 ) {
case V_61 :
V_57 = V_2 -> V_33 . V_68 ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_57 = V_2 -> V_33 . V_69 ;
V_59 = 1 ;
break;
default:
F_32 ( L_5 ) ;
return 0 ;
}
if ( ! V_57 ) {
F_32 ( L_8 ) ;
return 0 ;
}
V_32 = F_24 ( V_29 , V_57 , & V_58 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_27 , V_37 , L_7 , V_59 ?
F_36 ( ( int ) V_58 ) :
F_37 ( ( int ) V_58 ) ) ;
}
int F_38 ( struct V_28 * V_29 )
{
struct V_6 * V_2 = V_29 -> V_2 ;
int V_70 = 0 ;
int V_71 = 0 ;
int V_72 ;
int V_32 ;
F_39 ( F_40 ( & V_29 -> V_73 ) ) ;
V_29 -> V_73 . V_74 = & V_2 -> V_75 -> V_73 ;
V_29 -> V_73 . V_15 = V_25 ;
V_29 -> V_73 . V_76 = F_17 ;
F_41 ( L_9 ,
F_42 ( V_29 ) ) ;
F_43 ( & V_29 -> V_73 , L_10 ,
V_2 -> V_75 -> V_77 , F_42 ( V_29 ) ) ;
V_32 = F_44 ( & V_29 -> V_73 ) ;
if ( V_32 ) {
F_32 ( L_11 , V_32 ) ;
goto V_78;
}
for ( V_70 = 0 ; V_70 < F_45 ( V_79 ) ; V_70 ++ ) {
V_32 = F_46 ( & V_29 -> V_73 , & V_79 [ V_70 ] ) ;
if ( V_32 )
goto V_80;
}
switch ( V_29 -> V_60 ) {
case V_61 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
for ( V_71 = 0 ; V_71 < F_45 ( V_81 ) ; V_71 ++ ) {
V_32 = F_46 ( & V_29 -> V_73 , & V_81 [ V_71 ] ) ;
if ( V_32 )
goto V_80;
}
break;
default:
break;
}
V_32 = F_47 ( & V_29 -> V_73 . V_44 , & V_82 ) ;
if ( V_32 )
goto V_80;
F_48 ( V_2 ) ;
return 0 ;
V_80:
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_49 ( & V_29 -> V_73 , & V_81 [ V_72 ] ) ;
for ( V_72 = 0 ; V_72 < V_70 ; V_72 ++ )
F_49 ( & V_29 -> V_73 , & V_79 [ V_72 ] ) ;
F_50 ( & V_29 -> V_73 ) ;
V_78:
return V_32 ;
}
void F_51 ( struct V_28 * V_29 )
{
int V_72 ;
if ( ! V_29 -> V_73 . V_74 )
return;
F_41 ( L_12 ,
F_42 ( V_29 ) ) ;
for ( V_72 = 0 ; V_72 < F_45 ( V_79 ) ; V_72 ++ )
F_49 ( & V_29 -> V_73 , & V_79 [ V_72 ] ) ;
F_52 ( & V_29 -> V_73 . V_44 , & V_82 ) ;
F_50 ( & V_29 -> V_73 ) ;
V_29 -> V_73 . V_74 = NULL ;
}
void F_48 ( struct V_6 * V_2 )
{
char * V_83 = L_13 ;
char * V_84 [] = { V_83 , NULL } ;
F_41 ( L_14 ) ;
F_53 ( & V_2 -> V_75 -> V_73 . V_44 , V_85 , V_84 ) ;
}
int F_54 ( struct V_5 * V_86 )
{
int V_19 ;
char * V_87 ;
V_86 -> V_73 . V_74 = V_86 -> V_2 -> V_2 ;
V_86 -> V_73 . V_15 = V_25 ;
V_86 -> V_73 . V_76 = F_17 ;
V_86 -> V_73 . V_88 = V_86 -> V_1 ;
V_86 -> V_73 . type = & V_4 ;
if ( V_86 -> type == V_89 )
V_87 = L_15 ;
else if ( V_86 -> type == V_90 )
V_87 = L_16 ;
else
V_87 = L_17 ;
F_43 ( & V_86 -> V_73 , V_87 , V_86 -> V_77 ) ;
V_19 = F_44 ( & V_86 -> V_73 ) ;
if ( V_19 ) {
F_32 ( L_18 , V_19 ) ;
goto V_20;
}
return 0 ;
V_20:
return V_19 ;
}
void F_55 ( struct V_5 * V_86 )
{
if ( V_86 -> V_73 . V_74 )
F_50 ( & V_86 -> V_73 ) ;
V_86 -> V_73 . V_74 = NULL ;
}
int F_56 ( struct V_1 * V_2 )
{
V_2 -> V_15 = V_25 ;
return F_44 ( V_2 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
return F_50 ( V_2 ) ;
}
