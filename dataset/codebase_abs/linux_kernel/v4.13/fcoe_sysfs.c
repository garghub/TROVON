static int F_1 ( const char * V_1 , unsigned long * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 , 0 , V_2 ) ;
if ( V_3 )
return - V_4 ;
if ( * V_2 > V_5 )
return - V_4 ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned long V_2 )
{
if ( ( V_7 -> V_8 == V_9 ) ||
( V_7 -> V_8 == V_10 ) ||
( V_7 -> V_8 == V_11 ) )
return - V_12 ;
if ( V_2 > V_5 )
return - V_4 ;
F_4 ( V_7 ) = V_2 ;
return 0 ;
}
static enum V_13 F_5 ( const char * V_1 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_6 ( V_15 ) ; V_14 ++ ) {
if ( strcasecmp ( V_1 , V_15 [ V_14 ] ) == 0 )
return V_14 ;
}
return V_16 ;
}
static T_1 F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_1 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
const char * V_21 ;
V_21 = F_9 ( V_7 -> V_8 ) ;
if ( ! V_21 )
return - V_4 ;
return snprintf ( V_1 , V_22 , L_1 , V_21 ) ;
}
static T_1 F_10 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_1 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
const char * V_21 ;
V_21 = F_12 ( V_24 -> V_25 ) ;
if ( ! V_21 )
return - V_4 ;
return snprintf ( V_1 , V_26 ,
L_1 , V_21 ) ;
}
static T_1 F_13 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_1 , T_2 V_27 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
char V_25 [ V_26 + 1 ] ;
if ( V_27 > V_26 )
return - V_4 ;
strncpy ( V_25 , V_1 , V_27 ) ;
if ( V_25 [ V_27 - 1 ] == '\n' )
V_25 [ V_27 - 1 ] = '\0' ;
else
V_25 [ V_27 ] = '\0' ;
switch ( V_24 -> V_28 ) {
case V_29 :
F_14 ( V_24 , L_2 ) ;
return - V_12 ;
case V_30 :
if ( ! V_24 -> V_31 -> V_32 ) {
F_14 ( V_24 ,
L_3 ) ;
return - V_33 ;
}
V_24 -> V_25 = F_5 ( V_25 ) ;
if ( V_24 -> V_25 == V_16 ) {
F_14 ( V_24 , L_4 ,
V_1 ) ;
return - V_4 ;
}
V_24 -> V_31 -> V_32 ( V_24 ) ;
F_14 ( V_24 , L_5 , V_1 ) ;
return V_27 ;
case V_34 :
default:
F_14 ( V_24 , L_6 ) ;
return - V_33 ;
} ;
}
static T_1 F_15 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_1 , T_2 V_27 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
bool V_28 ;
int V_35 ;
if ( * V_1 == '1' )
V_28 = true ;
else if ( * V_1 == '0' )
V_28 = false ;
else
return - V_4 ;
switch ( V_24 -> V_28 ) {
case V_29 :
if ( V_28 )
return V_27 ;
V_24 -> V_28 = V_30 ;
break;
case V_30 :
if ( ! V_28 )
return V_27 ;
V_24 -> V_28 = V_29 ;
break;
case V_34 :
return - V_33 ;
} ;
V_35 = V_24 -> V_31 -> V_36 ( V_24 ) ;
if ( V_35 )
return V_35 ;
return V_27 ;
}
static T_1 F_16 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_1 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
const char * V_21 ;
V_21 = F_17 ( V_24 -> V_28 ) ;
if ( ! V_21 )
return - V_4 ;
return snprintf ( V_1 , V_37 ,
L_1 , V_21 ) ;
}
static T_1 F_18 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_1 , T_2 V_27 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
struct V_38 * V_39 = F_19 ( V_24 ) ;
F_20 ( & V_39 -> V_40 ) ;
if ( ( V_1 [ 1 ] == '\0' ) || ( ( V_1 [ 1 ] == '\n' ) && ( V_1 [ 2 ] == '\0' ) ) ) {
if ( V_1 [ 0 ] == '1' ) {
V_39 -> V_41 = 1 ;
F_21 ( & V_39 -> V_40 ) ;
return V_27 ;
}
if ( V_1 [ 0 ] == '0' ) {
V_39 -> V_41 = 0 ;
F_21 ( & V_39 -> V_40 ) ;
return V_27 ;
}
}
F_21 ( & V_39 -> V_40 ) ;
return - V_4 ;
}
static T_1 F_22 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_1 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
struct V_38 * V_39 = F_19 ( V_24 ) ;
return sprintf ( V_1 , L_7 , V_39 -> V_41 ? 1 : 0 ) ;
}
static T_1
F_23 ( T_3 * V_42 , const char * V_1 , T_2 V_27 )
{
int V_43 ;
unsigned long V_44 ;
V_43 = F_2 ( V_1 , 10 , & V_44 ) ;
if ( V_43 || V_44 > V_5 )
return - V_4 ;
* V_42 = V_44 ;
return V_27 ;
}
static T_1 F_24 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_1 , T_2 V_27 )
{
struct V_23 * V_45 = F_11 ( V_18 ) ;
struct V_38 * V_24 = F_19 ( V_45 ) ;
if ( V_45 -> V_28 == V_29 )
return - V_12 ;
if ( V_45 -> V_28 == V_30 )
return F_23 ( & V_24 -> V_46 -> V_47 , V_1 , V_27 ) ;
return - V_33 ;
}
static T_1 F_25 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_1 )
{
struct V_23 * V_45 = F_11 ( V_18 ) ;
struct V_38 * V_24 = F_19 ( V_45 ) ;
return sprintf ( V_1 , L_7 , V_24 -> V_46 -> V_47 ) ;
}
static T_1 F_26 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_1 , T_2 V_27 )
{
struct V_23 * V_45 = F_11 ( V_18 ) ;
struct V_38 * V_24 = F_19 ( V_45 ) ;
if ( V_45 -> V_28 == V_29 )
return - V_12 ;
if ( V_45 -> V_28 == V_30 )
return F_23 ( & V_24 -> V_46 -> V_48 , V_1 , V_27 ) ;
return - V_33 ;
}
static T_1 F_27 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_1 )
{
struct V_23 * V_45 = F_11 ( V_18 ) ;
struct V_38 * V_24 = F_19 ( V_45 ) ;
return sprintf ( V_1 , L_7 , V_24 -> V_46 -> V_48 ) ;
}
static T_1
F_28 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_1 , T_2 V_27 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
struct V_6 * V_7 ;
unsigned long V_2 ;
int V_35 ;
V_35 = F_1 ( V_1 , & V_2 ) ;
if ( V_35 )
return V_35 ;
F_29 ( V_24 ) = V_2 ;
F_20 ( & V_24 -> V_49 ) ;
F_30 (fcf, &ctlr->fcfs, peers)
F_3 ( V_7 , V_2 ) ;
F_21 ( & V_24 -> V_49 ) ;
return V_27 ;
}
static T_1
F_31 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_1 , T_2 V_27 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
unsigned long V_2 ;
int V_35 ;
V_35 = F_1 ( V_1 , & V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_3 ( V_7 , V_2 ) ;
if ( V_35 )
return V_35 ;
return V_27 ;
}
static int F_32 ( struct V_17 * V_18 ,
struct V_50 * V_51 )
{
if ( V_18 -> V_52 == & V_53 )
return 1 ;
return 0 ;
}
static void F_33 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
F_34 ( V_24 ) ;
}
static void F_35 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
F_34 ( V_7 ) ;
}
static void F_36 ( struct V_23 * V_24 )
{
if ( ! F_37 ( V_24 ) ) {
F_38 ( V_54
L_8
L_9 , V_24 -> V_55 ) ;
F_39 () ;
return;
}
F_40 ( F_37 ( V_24 ) ) ;
}
static int F_41 ( struct V_23 * V_24 ,
struct V_56 * V_57 )
{
if ( F_42 ( ! F_37 ( V_24 ) ) ) {
F_38 ( V_54
L_10
L_9 , V_24 -> V_55 ) ;
F_39 () ;
return - V_4 ;
}
return F_43 ( F_37 ( V_24 ) , V_57 ) ;
}
static void F_44 ( struct V_23 * V_24 )
{
if ( ! F_45 ( V_24 ) ) {
F_38 ( V_54
L_8
L_9 , V_24 -> V_55 ) ;
F_39 () ;
return;
}
F_40 ( F_45 ( V_24 ) ) ;
}
static int F_46 ( struct V_23 * V_24 ,
struct V_58 * V_57 ,
unsigned long V_59 )
{
if ( F_42 ( ! F_45 ( V_24 ) ) ) {
F_38 ( V_54
L_10
L_9 , V_24 -> V_55 ) ;
F_39 () ;
return - V_4 ;
}
return F_47 ( F_45 ( V_24 ) , V_57 , V_59 ) ;
}
static int F_48 ( struct V_6 * V_60 ,
struct V_6 * V_61 )
{
if ( V_60 -> V_62 == V_61 -> V_62 &&
V_60 -> V_63 == V_61 -> V_63 &&
V_60 -> V_64 == V_61 -> V_64 &&
F_49 ( V_60 -> V_65 , V_61 -> V_65 ) )
return 1 ;
return 0 ;
}
struct V_23 * F_50 ( struct V_17 * V_66 ,
struct V_67 * V_31 ,
int V_68 )
{
struct V_23 * V_24 ;
int error = 0 ;
V_24 = F_51 ( sizeof( struct V_23 ) + V_68 ,
V_69 ) ;
if ( ! V_24 )
goto V_70;
V_24 -> V_55 = F_52 ( & V_71 ) - 1 ;
V_24 -> V_31 = V_31 ;
V_24 -> V_25 = V_72 ;
F_53 ( & V_24 -> V_73 ) ;
F_54 ( & V_24 -> V_49 ) ;
V_24 -> V_18 . V_66 = V_66 ;
V_24 -> V_18 . V_52 = & V_53 ;
V_24 -> V_18 . type = & V_74 ;
V_24 -> V_75 = F_4 ;
snprintf ( V_24 -> V_76 , sizeof( V_24 -> V_76 ) ,
L_11 , V_24 -> V_55 ) ;
V_24 -> V_77 = F_55 (
V_24 -> V_76 ) ;
if ( ! V_24 -> V_77 )
goto V_78;
snprintf ( V_24 -> V_79 ,
sizeof( V_24 -> V_79 ) ,
L_12 , V_24 -> V_55 ) ;
V_24 -> V_80 = F_55 (
V_24 -> V_79 ) ;
if ( ! V_24 -> V_80 )
goto V_81;
F_56 ( & V_24 -> V_18 , L_13 , V_24 -> V_55 ) ;
error = F_57 ( & V_24 -> V_18 ) ;
if ( error )
goto V_82;
return V_24 ;
V_82:
F_58 ( V_24 -> V_80 ) ;
V_24 -> V_80 = NULL ;
V_81:
F_58 ( V_24 -> V_77 ) ;
V_24 -> V_77 = NULL ;
V_78:
F_34 ( V_24 ) ;
V_70:
return NULL ;
}
void F_59 ( struct V_23 * V_24 )
{
struct V_6 * V_7 , * V_83 ;
F_20 ( & V_24 -> V_49 ) ;
F_60 (fcf, next,
&ctlr->fcfs, peers) {
F_61 ( & V_7 -> V_84 ) ;
V_7 -> V_8 = V_11 ;
F_41 ( V_24 , & V_7 -> V_85 ) ;
}
F_21 ( & V_24 -> V_49 ) ;
F_36 ( V_24 ) ;
F_58 ( V_24 -> V_80 ) ;
V_24 -> V_80 = NULL ;
F_58 ( V_24 -> V_77 ) ;
V_24 -> V_77 = NULL ;
F_62 ( & V_24 -> V_18 ) ;
}
static void F_63 ( struct V_56 * V_57 )
{
struct V_6 * V_7 =
F_64 ( V_57 , struct V_6 , V_85 ) ;
struct V_23 * V_24 = F_65 ( V_7 ) ;
if ( ! F_66 ( & V_7 -> V_86 ) )
F_44 ( V_24 ) ;
F_62 ( & V_7 -> V_18 ) ;
}
static void F_67 ( struct V_56 * V_57 )
{
struct V_6 * V_7 =
F_64 ( V_57 , struct V_6 , V_86 . V_57 ) ;
struct V_23 * V_24 = F_65 ( V_7 ) ;
F_20 ( & V_24 -> V_49 ) ;
if ( V_7 -> V_8 != V_10 )
goto V_70;
F_68 ( V_54 , & V_7 -> V_18 ,
L_14 ) ;
F_61 ( & V_7 -> V_84 ) ;
V_7 -> V_8 = V_11 ;
F_41 ( V_24 , & V_7 -> V_85 ) ;
V_70:
F_21 ( & V_24 -> V_49 ) ;
}
void F_69 ( struct V_6 * V_7 )
{
struct V_23 * V_24 = F_65 ( V_7 ) ;
int V_87 = V_7 -> V_88 ;
if ( V_7 -> V_8 != V_89 )
return;
V_7 -> V_8 = V_10 ;
V_7 -> V_90 = NULL ;
F_46 ( V_24 , & V_7 -> V_86 ,
V_87 * V_91 ) ;
}
struct V_6 * F_70 ( struct V_23 * V_24 ,
struct V_6 * V_92 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_30 (fcf, &ctlr->fcfs, peers) {
if ( F_48 ( V_92 , V_7 ) ) {
if ( V_7 -> V_8 == V_89 )
return V_7 ;
V_7 -> V_8 = V_89 ;
if ( ! F_66 ( & V_7 -> V_86 ) )
F_44 ( V_24 ) ;
return V_7 ;
}
}
V_7 = F_51 ( sizeof( struct V_6 ) , V_93 ) ;
if ( F_42 ( ! V_7 ) )
goto V_70;
F_71 ( & V_7 -> V_85 , F_63 ) ;
F_72 ( & V_7 -> V_86 , F_67 ) ;
V_7 -> V_18 . V_66 = & V_24 -> V_18 ;
V_7 -> V_18 . V_52 = & V_53 ;
V_7 -> V_18 . type = & V_94 ;
V_7 -> V_55 = F_52 ( & V_95 ) - 1 ;
V_7 -> V_8 = V_9 ;
V_7 -> V_88 = V_24 -> V_75 ;
F_56 ( & V_7 -> V_18 , L_15 , V_7 -> V_55 ) ;
V_7 -> V_63 = V_92 -> V_63 ;
V_7 -> V_62 = V_92 -> V_62 ;
V_7 -> V_64 = V_92 -> V_64 ;
V_7 -> V_96 = V_92 -> V_96 ;
memcpy ( V_7 -> V_65 , V_92 -> V_65 , V_97 ) ;
V_7 -> V_98 = V_92 -> V_98 ;
V_7 -> V_99 = V_92 -> V_99 ;
V_7 -> V_100 = V_92 -> V_100 ;
error = F_57 ( & V_7 -> V_18 ) ;
if ( error )
goto V_78;
V_7 -> V_8 = V_89 ;
F_73 ( & V_7 -> V_84 , & V_24 -> V_73 ) ;
return V_7 ;
V_78:
F_34 ( V_7 ) ;
V_70:
return NULL ;
}
int T_4 F_74 ( void )
{
int error ;
F_75 ( & V_71 , 0 ) ;
F_75 ( & V_95 , 0 ) ;
error = F_76 ( & V_53 ) ;
if ( error )
return error ;
return 0 ;
}
void T_5 F_77 ( void )
{
F_78 ( & V_53 ) ;
}
