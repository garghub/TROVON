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
F_14 ( V_24 ,
L_4 , V_1 ) ;
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
static T_1
F_18 ( struct V_17 * V_18 ,
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
F_19 ( V_24 ) = V_2 ;
F_20 ( & V_24 -> V_38 ) ;
F_21 (fcf, &ctlr->fcfs, peers)
F_3 ( V_7 , V_2 ) ;
F_22 ( & V_24 -> V_38 ) ;
return V_27 ;
}
static T_1
F_23 ( struct V_17 * V_18 , struct V_19 * V_20 ,
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
static int F_24 ( struct V_17 * V_18 ,
struct V_39 * V_40 )
{
if ( V_18 -> V_41 == & V_42 )
return 1 ;
return 0 ;
}
static void F_25 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = F_11 ( V_18 ) ;
F_26 ( V_24 ) ;
}
static void F_27 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
F_26 ( V_7 ) ;
}
void F_28 ( struct V_23 * V_24 )
{
if ( ! F_29 ( V_24 ) ) {
F_30 ( V_43
L_7
L_8 , V_24 -> V_44 ) ;
F_31 () ;
return;
}
F_32 ( F_29 ( V_24 ) ) ;
}
int F_33 ( struct V_23 * V_24 ,
struct V_45 * V_46 )
{
if ( F_34 ( ! F_29 ( V_24 ) ) ) {
F_30 ( V_43
L_9
L_8 , V_24 -> V_44 ) ;
F_31 () ;
return - V_4 ;
}
return F_35 ( F_29 ( V_24 ) , V_46 ) ;
}
void F_36 ( struct V_23 * V_24 )
{
if ( ! F_37 ( V_24 ) ) {
F_30 ( V_43
L_7
L_8 , V_24 -> V_44 ) ;
F_31 () ;
return;
}
F_32 ( F_37 ( V_24 ) ) ;
}
int F_38 ( struct V_23 * V_24 ,
struct V_47 * V_46 ,
unsigned long V_48 )
{
if ( F_34 ( ! F_37 ( V_24 ) ) ) {
F_30 ( V_43
L_9
L_8 , V_24 -> V_44 ) ;
F_31 () ;
return - V_4 ;
}
return F_39 ( F_37 ( V_24 ) , V_46 , V_48 ) ;
}
static int F_40 ( struct V_6 * V_49 ,
struct V_6 * V_50 )
{
if ( V_49 -> V_51 == V_50 -> V_51 &&
V_49 -> V_52 == V_50 -> V_52 &&
V_49 -> V_53 == V_50 -> V_53 &&
F_41 ( V_49 -> V_54 , V_50 -> V_54 ) == 0 )
return 1 ;
return 0 ;
}
struct V_23 * F_42 ( struct V_17 * V_55 ,
struct V_56 * V_31 ,
int V_57 )
{
struct V_23 * V_24 ;
int error = 0 ;
V_24 = F_43 ( sizeof( struct V_23 ) + V_57 ,
V_58 ) ;
if ( ! V_24 )
goto V_59;
V_24 -> V_44 = F_44 ( & V_60 ) - 1 ;
V_24 -> V_31 = V_31 ;
V_24 -> V_25 = V_61 ;
F_45 ( & V_24 -> V_62 ) ;
F_46 ( & V_24 -> V_38 ) ;
V_24 -> V_18 . V_55 = V_55 ;
V_24 -> V_18 . V_41 = & V_42 ;
V_24 -> V_18 . type = & V_63 ;
V_24 -> V_64 = F_4 ;
snprintf ( V_24 -> V_65 , sizeof( V_24 -> V_65 ) ,
L_10 , V_24 -> V_44 ) ;
V_24 -> V_66 = F_47 (
V_24 -> V_65 ) ;
if ( ! V_24 -> V_66 )
goto V_67;
snprintf ( V_24 -> V_68 ,
sizeof( V_24 -> V_68 ) ,
L_11 , V_24 -> V_44 ) ;
V_24 -> V_69 = F_47 (
V_24 -> V_68 ) ;
if ( ! V_24 -> V_69 )
goto V_70;
F_48 ( & V_24 -> V_18 , L_12 , V_24 -> V_44 ) ;
error = F_49 ( & V_24 -> V_18 ) ;
if ( error )
goto V_71;
return V_24 ;
V_71:
F_50 ( V_24 -> V_69 ) ;
V_24 -> V_69 = NULL ;
V_70:
F_50 ( V_24 -> V_66 ) ;
V_24 -> V_66 = NULL ;
V_67:
F_26 ( V_24 ) ;
V_59:
return NULL ;
}
void F_51 ( struct V_23 * V_24 )
{
struct V_6 * V_7 , * V_72 ;
F_20 ( & V_24 -> V_38 ) ;
F_52 (fcf, next,
&ctlr->fcfs, peers) {
F_53 ( & V_7 -> V_73 ) ;
V_7 -> V_8 = V_11 ;
F_33 ( V_24 , & V_7 -> V_74 ) ;
}
F_22 ( & V_24 -> V_38 ) ;
F_28 ( V_24 ) ;
F_50 ( V_24 -> V_69 ) ;
V_24 -> V_69 = NULL ;
F_50 ( V_24 -> V_66 ) ;
V_24 -> V_66 = NULL ;
F_54 ( & V_24 -> V_18 ) ;
}
static void F_55 ( struct V_45 * V_46 )
{
struct V_6 * V_7 =
F_56 ( V_46 , struct V_6 , V_74 ) ;
struct V_23 * V_24 = F_57 ( V_7 ) ;
if ( ! F_58 ( & V_7 -> V_75 ) )
F_36 ( V_24 ) ;
F_54 ( & V_7 -> V_18 ) ;
}
static void F_59 ( struct V_45 * V_46 )
{
struct V_6 * V_7 =
F_56 ( V_46 , struct V_6 , V_75 . V_46 ) ;
struct V_23 * V_24 = F_57 ( V_7 ) ;
F_20 ( & V_24 -> V_38 ) ;
if ( V_7 -> V_8 != V_10 )
goto V_59;
F_60 ( V_43 , & V_7 -> V_18 ,
L_13 ) ;
F_53 ( & V_7 -> V_73 ) ;
V_7 -> V_8 = V_11 ;
F_33 ( V_24 , & V_7 -> V_74 ) ;
V_59:
F_22 ( & V_24 -> V_38 ) ;
}
void F_61 ( struct V_6 * V_7 )
{
struct V_23 * V_24 = F_57 ( V_7 ) ;
int V_76 = V_7 -> V_77 ;
if ( V_7 -> V_8 != V_78 )
return;
V_7 -> V_8 = V_10 ;
V_7 -> V_79 = NULL ;
F_38 ( V_24 , & V_7 -> V_75 ,
V_76 * V_80 ) ;
}
struct V_6 * F_62 ( struct V_23 * V_24 ,
struct V_6 * V_81 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_21 (fcf, &ctlr->fcfs, peers) {
if ( F_40 ( V_81 , V_7 ) ) {
if ( V_7 -> V_8 == V_78 )
return V_7 ;
V_7 -> V_8 = V_78 ;
if ( ! F_58 ( & V_7 -> V_75 ) )
F_36 ( V_24 ) ;
return V_7 ;
}
}
V_7 = F_43 ( sizeof( struct V_6 ) , V_82 ) ;
if ( F_34 ( ! V_7 ) )
goto V_59;
F_63 ( & V_7 -> V_74 , F_55 ) ;
F_64 ( & V_7 -> V_75 , F_59 ) ;
V_7 -> V_18 . V_55 = & V_24 -> V_18 ;
V_7 -> V_18 . V_41 = & V_42 ;
V_7 -> V_18 . type = & V_83 ;
V_7 -> V_44 = F_44 ( & V_84 ) - 1 ;
V_7 -> V_8 = V_9 ;
V_7 -> V_77 = V_24 -> V_64 ;
F_48 ( & V_7 -> V_18 , L_14 , V_7 -> V_44 ) ;
V_7 -> V_52 = V_81 -> V_52 ;
V_7 -> V_51 = V_81 -> V_51 ;
V_7 -> V_53 = V_81 -> V_53 ;
V_7 -> V_85 = V_81 -> V_85 ;
memcpy ( V_7 -> V_54 , V_81 -> V_54 , V_86 ) ;
V_7 -> V_87 = V_81 -> V_87 ;
V_7 -> V_88 = V_81 -> V_88 ;
V_7 -> V_89 = V_81 -> V_89 ;
error = F_49 ( & V_7 -> V_18 ) ;
if ( error )
goto V_67;
V_7 -> V_8 = V_78 ;
F_65 ( & V_7 -> V_73 , & V_24 -> V_62 ) ;
return V_7 ;
V_67:
F_26 ( V_7 ) ;
V_59:
return NULL ;
}
int T_3 F_66 ( void )
{
int error ;
F_67 ( & V_60 , 0 ) ;
F_67 ( & V_84 , 0 ) ;
error = F_68 ( & V_42 ) ;
if ( error )
return error ;
return 0 ;
}
void T_4 F_69 ( void )
{
F_70 ( & V_42 ) ;
}
