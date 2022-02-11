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
int V_35 ;
switch ( V_24 -> V_28 ) {
case V_29 :
if ( * V_1 == '1' )
return V_27 ;
V_24 -> V_28 = V_30 ;
break;
case V_30 :
if ( * V_1 == '0' )
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
F_23 ( struct V_17 * V_18 ,
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
F_24 ( V_24 ) = V_2 ;
F_20 ( & V_24 -> V_42 ) ;
F_25 (fcf, &ctlr->fcfs, peers)
F_3 ( V_7 , V_2 ) ;
F_21 ( & V_24 -> V_42 ) ;
return V_27 ;
}
static T_1
F_26 ( struct V_17 * V_18 , struct V_19 * V_20 ,
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
static int F_27 ( struct V_17 * V_18 ,
struct V_43 * V_44 )
{
if ( V_18 -> V_45 == & V_46 )
return 1 ;
return 0 ;
}
static void F_28 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
F_29 ( V_24 ) ;
}
static void F_30 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
F_29 ( V_7 ) ;
}
static void F_31 ( struct V_23 * V_24 )
{
if ( ! F_32 ( V_24 ) ) {
F_33 ( V_47
L_8
L_9 , V_24 -> V_48 ) ;
F_34 () ;
return;
}
F_35 ( F_32 ( V_24 ) ) ;
}
static int F_36 ( struct V_23 * V_24 ,
struct V_49 * V_50 )
{
if ( F_37 ( ! F_32 ( V_24 ) ) ) {
F_33 ( V_47
L_10
L_9 , V_24 -> V_48 ) ;
F_34 () ;
return - V_4 ;
}
return F_38 ( F_32 ( V_24 ) , V_50 ) ;
}
static void F_39 ( struct V_23 * V_24 )
{
if ( ! F_40 ( V_24 ) ) {
F_33 ( V_47
L_8
L_9 , V_24 -> V_48 ) ;
F_34 () ;
return;
}
F_35 ( F_40 ( V_24 ) ) ;
}
static int F_41 ( struct V_23 * V_24 ,
struct V_51 * V_50 ,
unsigned long V_52 )
{
if ( F_37 ( ! F_40 ( V_24 ) ) ) {
F_33 ( V_47
L_10
L_9 , V_24 -> V_48 ) ;
F_34 () ;
return - V_4 ;
}
return F_42 ( F_40 ( V_24 ) , V_50 , V_52 ) ;
}
static int F_43 ( struct V_6 * V_53 ,
struct V_6 * V_54 )
{
if ( V_53 -> V_55 == V_54 -> V_55 &&
V_53 -> V_56 == V_54 -> V_56 &&
V_53 -> V_57 == V_54 -> V_57 &&
F_44 ( V_53 -> V_58 , V_54 -> V_58 ) )
return 1 ;
return 0 ;
}
struct V_23 * F_45 ( struct V_17 * V_59 ,
struct V_60 * V_31 ,
int V_61 )
{
struct V_23 * V_24 ;
int error = 0 ;
V_24 = F_46 ( sizeof( struct V_23 ) + V_61 ,
V_62 ) ;
if ( ! V_24 )
goto V_63;
V_24 -> V_48 = F_47 ( & V_64 ) - 1 ;
V_24 -> V_31 = V_31 ;
V_24 -> V_25 = V_65 ;
F_48 ( & V_24 -> V_66 ) ;
F_49 ( & V_24 -> V_42 ) ;
V_24 -> V_18 . V_59 = V_59 ;
V_24 -> V_18 . V_45 = & V_46 ;
V_24 -> V_18 . type = & V_67 ;
V_24 -> V_68 = F_4 ;
snprintf ( V_24 -> V_69 , sizeof( V_24 -> V_69 ) ,
L_11 , V_24 -> V_48 ) ;
V_24 -> V_70 = F_50 (
V_24 -> V_69 ) ;
if ( ! V_24 -> V_70 )
goto V_71;
snprintf ( V_24 -> V_72 ,
sizeof( V_24 -> V_72 ) ,
L_12 , V_24 -> V_48 ) ;
V_24 -> V_73 = F_50 (
V_24 -> V_72 ) ;
if ( ! V_24 -> V_73 )
goto V_74;
F_51 ( & V_24 -> V_18 , L_13 , V_24 -> V_48 ) ;
error = F_52 ( & V_24 -> V_18 ) ;
if ( error )
goto V_75;
return V_24 ;
V_75:
F_53 ( V_24 -> V_73 ) ;
V_24 -> V_73 = NULL ;
V_74:
F_53 ( V_24 -> V_70 ) ;
V_24 -> V_70 = NULL ;
V_71:
F_29 ( V_24 ) ;
V_63:
return NULL ;
}
void F_54 ( struct V_23 * V_24 )
{
struct V_6 * V_7 , * V_76 ;
F_20 ( & V_24 -> V_42 ) ;
F_55 (fcf, next,
&ctlr->fcfs, peers) {
F_56 ( & V_7 -> V_77 ) ;
V_7 -> V_8 = V_11 ;
F_36 ( V_24 , & V_7 -> V_78 ) ;
}
F_21 ( & V_24 -> V_42 ) ;
F_31 ( V_24 ) ;
F_53 ( V_24 -> V_73 ) ;
V_24 -> V_73 = NULL ;
F_53 ( V_24 -> V_70 ) ;
V_24 -> V_70 = NULL ;
F_57 ( & V_24 -> V_18 ) ;
}
static void F_58 ( struct V_49 * V_50 )
{
struct V_6 * V_7 =
F_59 ( V_50 , struct V_6 , V_78 ) ;
struct V_23 * V_24 = F_60 ( V_7 ) ;
if ( ! F_61 ( & V_7 -> V_79 ) )
F_39 ( V_24 ) ;
F_57 ( & V_7 -> V_18 ) ;
}
static void F_62 ( struct V_49 * V_50 )
{
struct V_6 * V_7 =
F_59 ( V_50 , struct V_6 , V_79 . V_50 ) ;
struct V_23 * V_24 = F_60 ( V_7 ) ;
F_20 ( & V_24 -> V_42 ) ;
if ( V_7 -> V_8 != V_10 )
goto V_63;
F_63 ( V_47 , & V_7 -> V_18 ,
L_14 ) ;
F_56 ( & V_7 -> V_77 ) ;
V_7 -> V_8 = V_11 ;
F_36 ( V_24 , & V_7 -> V_78 ) ;
V_63:
F_21 ( & V_24 -> V_42 ) ;
}
void F_64 ( struct V_6 * V_7 )
{
struct V_23 * V_24 = F_60 ( V_7 ) ;
int V_80 = V_7 -> V_81 ;
if ( V_7 -> V_8 != V_82 )
return;
V_7 -> V_8 = V_10 ;
V_7 -> V_83 = NULL ;
F_41 ( V_24 , & V_7 -> V_79 ,
V_80 * V_84 ) ;
}
struct V_6 * F_65 ( struct V_23 * V_24 ,
struct V_6 * V_85 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_25 (fcf, &ctlr->fcfs, peers) {
if ( F_43 ( V_85 , V_7 ) ) {
if ( V_7 -> V_8 == V_82 )
return V_7 ;
V_7 -> V_8 = V_82 ;
if ( ! F_61 ( & V_7 -> V_79 ) )
F_39 ( V_24 ) ;
return V_7 ;
}
}
V_7 = F_46 ( sizeof( struct V_6 ) , V_86 ) ;
if ( F_37 ( ! V_7 ) )
goto V_63;
F_66 ( & V_7 -> V_78 , F_58 ) ;
F_67 ( & V_7 -> V_79 , F_62 ) ;
V_7 -> V_18 . V_59 = & V_24 -> V_18 ;
V_7 -> V_18 . V_45 = & V_46 ;
V_7 -> V_18 . type = & V_87 ;
V_7 -> V_48 = F_47 ( & V_88 ) - 1 ;
V_7 -> V_8 = V_9 ;
V_7 -> V_81 = V_24 -> V_68 ;
F_51 ( & V_7 -> V_18 , L_15 , V_7 -> V_48 ) ;
V_7 -> V_56 = V_85 -> V_56 ;
V_7 -> V_55 = V_85 -> V_55 ;
V_7 -> V_57 = V_85 -> V_57 ;
V_7 -> V_89 = V_85 -> V_89 ;
memcpy ( V_7 -> V_58 , V_85 -> V_58 , V_90 ) ;
V_7 -> V_91 = V_85 -> V_91 ;
V_7 -> V_92 = V_85 -> V_92 ;
V_7 -> V_93 = V_85 -> V_93 ;
error = F_52 ( & V_7 -> V_18 ) ;
if ( error )
goto V_71;
V_7 -> V_8 = V_82 ;
F_68 ( & V_7 -> V_77 , & V_24 -> V_66 ) ;
return V_7 ;
V_71:
F_29 ( V_7 ) ;
V_63:
return NULL ;
}
int T_3 F_69 ( void )
{
int error ;
F_70 ( & V_64 , 0 ) ;
F_70 ( & V_88 , 0 ) ;
error = F_71 ( & V_46 ) ;
if ( error )
return error ;
return 0 ;
}
void T_4 F_72 ( void )
{
F_73 ( & V_46 ) ;
}
