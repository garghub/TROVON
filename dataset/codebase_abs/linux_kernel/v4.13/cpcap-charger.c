static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int error , V_5 ;
V_4 = V_2 -> V_6 [ V_7 ] ;
error = F_2 ( V_4 , & V_5 ) ;
if ( error < 0 ) {
F_3 ( V_2 -> V_8 , L_1 , V_9 , error ) ;
return false ;
}
return V_5 == 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int error , V_5 = 0 ;
V_4 = V_2 -> V_6 [ V_10 ] ;
error = F_5 ( V_4 , & V_5 ) ;
if ( error < 0 ) {
F_3 ( V_2 -> V_8 , L_1 , V_9 , error ) ;
return 0 ;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int error , V_5 = 0 ;
V_4 = V_2 -> V_6 [ V_11 ] ;
error = F_5 ( V_4 , & V_5 ) ;
if ( error < 0 ) {
F_3 ( V_2 -> V_8 , L_1 , V_9 , error ) ;
return 0 ;
}
return V_5 ;
}
static int F_7 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
union V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_13 -> V_8 . V_18 ) ;
switch ( V_15 ) {
case V_19 :
V_17 -> V_20 = V_2 -> V_21 ;
break;
case V_22 :
if ( V_2 -> V_21 == V_23 )
V_17 -> V_20 = F_4 ( V_2 ) *
1000 ;
else
V_17 -> V_20 = 0 ;
break;
case V_24 :
if ( V_2 -> V_21 == V_23 )
V_17 -> V_20 = F_6 ( V_2 ) *
1000 ;
else
V_17 -> V_20 = 0 ;
break;
case V_25 :
V_17 -> V_20 = V_2 -> V_21 == V_23 ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
bool V_27 )
{
if ( ! V_2 -> V_28 [ 0 ] )
return;
F_10 ( V_2 -> V_28 [ 0 ] , V_27 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
bool V_27 )
{
if ( ! V_2 -> V_28 [ 1 ] )
return;
F_10 ( V_2 -> V_28 [ 1 ] , V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_29 , int V_30 ,
int V_31 )
{
bool V_32 ;
int error ;
V_32 = ( V_30 || V_31 ) ;
F_13 ( V_2 -> V_8 , L_2 , V_9 , V_32 ) ;
if ( ! V_32 ) {
error = F_14 ( V_2 -> V_33 , V_34 ,
0x3fff ,
V_35 |
V_36 ) ;
if ( error ) {
V_2 -> V_21 = V_37 ;
goto V_38;
}
V_2 -> V_21 = V_39 ;
return 0 ;
}
error = F_14 ( V_2 -> V_33 , V_34 , 0x3fff ,
V_40 |
V_31 |
V_35 |
V_36 |
V_29 |
V_30 ) ;
if ( error ) {
V_2 -> V_21 = V_37 ;
goto V_38;
}
V_2 -> V_21 = V_23 ;
return 0 ;
V_38:
F_15 ( V_2 -> V_8 , L_3 , V_9 , error ) ;
return error ;
}
static bool F_16 ( struct V_1 * V_2 )
{
int error , V_5 = 0 ;
struct V_3 * V_4 =
V_2 -> V_6 [ V_41 ] ;
error = F_5 ( V_4 , & V_5 ) ;
if ( error >= 0 )
return V_5 > 3900 ? true : false ;
F_15 ( V_2 -> V_8 , L_4 , error ) ;
return false ;
}
static void F_17 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
bool V_44 = false ;
int error ;
V_2 = F_18 ( V_43 , struct V_1 ,
V_45 . V_43 ) ;
if ( V_2 -> V_46 ) {
V_44 = F_16 ( V_2 ) ;
if ( V_44 ) {
F_19 ( V_2 -> V_8 , L_5 ) ;
return;
}
F_9 ( V_2 , false ) ;
F_11 ( V_2 , false ) ;
error = F_12 ( V_2 , 0 , 0 , 0 ) ;
if ( error )
goto V_38;
error = F_14 ( V_2 -> V_33 , V_34 ,
V_47 ,
V_47 ) ;
if ( error )
goto V_38;
} else {
error = F_14 ( V_2 -> V_33 , V_34 ,
V_47 , 0 ) ;
if ( error )
goto V_38;
F_9 ( V_2 , true ) ;
F_11 ( V_2 , true ) ;
}
return;
V_38:
F_15 ( V_2 -> V_8 , L_6 , V_9 ,
V_2 -> V_46 ? L_7 : L_8 , error ) ;
}
static int F_20 ( struct V_48 * V_49 ,
bool V_27 )
{
struct V_1 * V_2 =
F_18 ( V_49 , struct V_1 ,
V_49 ) ;
V_2 -> V_46 = V_27 ;
F_21 ( & V_2 -> V_45 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_17 , error ;
error = F_23 ( V_2 -> V_33 , V_52 , & V_17 ) ;
if ( error )
return error ;
V_51 -> V_53 = V_17 & F_24 ( 13 ) ;
V_51 -> V_54 = V_17 & F_24 ( 12 ) ;
V_51 -> V_55 = V_17 & F_24 ( 11 ) ;
error = F_23 ( V_2 -> V_33 , V_56 , & V_17 ) ;
if ( error )
return error ;
V_51 -> V_57 = V_17 & F_24 ( 13 ) ;
V_51 -> V_58 = V_17 & F_24 ( 6 ) ;
V_51 -> V_59 = V_17 & F_24 ( 4 ) ;
V_51 -> V_60 = V_17 & F_24 ( 3 ) ;
error = F_23 ( V_2 -> V_33 , V_61 , & V_17 ) ;
if ( error )
return error ;
V_51 -> V_62 = V_17 & F_24 ( 6 ) ;
return 0 ;
}
static void F_25 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_50 V_51 ;
int error ;
V_2 = F_18 ( V_43 , struct V_1 ,
V_63 . V_43 ) ;
error = F_22 ( V_2 , & V_51 ) ;
if ( error )
return;
if ( F_16 ( V_2 ) && V_51 . V_59 ) {
int V_64 ;
if ( F_1 ( V_2 ) )
V_64 = V_65 ;
else
V_64 = V_66 ;
error = F_12 ( V_2 ,
V_67 ,
V_64 , 0 ) ;
if ( error )
goto V_38;
} else {
error = F_12 ( V_2 , 0 , 0 , 0 ) ;
if ( error )
goto V_38;
}
return;
V_38:
F_15 ( V_2 -> V_8 , L_3 , V_9 , error ) ;
}
static T_1 F_26 ( int V_68 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
if ( ! F_27 ( & V_2 -> V_70 ) )
return V_71 ;
F_21 ( & V_2 -> V_63 , 0 ) ;
return V_72 ;
}
static int F_28 ( struct V_73 * V_74 ,
struct V_1 * V_2 ,
const char * V_75 )
{
struct V_76 * V_77 ;
int V_68 , error ;
V_68 = F_29 ( V_74 , V_75 ) ;
if ( ! V_68 )
return - V_78 ;
error = F_30 ( V_2 -> V_8 , V_68 , NULL ,
F_26 ,
V_79 ,
V_75 , V_2 ) ;
if ( error ) {
F_15 ( V_2 -> V_8 , L_9 ,
V_75 , error ) ;
return error ;
}
V_77 = F_31 ( V_2 -> V_8 , sizeof( * V_77 ) , V_80 ) ;
if ( ! V_77 )
return - V_81 ;
V_77 -> V_75 = V_75 ;
V_77 -> V_68 = V_68 ;
F_32 ( & V_77 -> V_82 , & V_2 -> V_83 ) ;
return 0 ;
}
static int F_33 ( struct V_73 * V_74 ,
struct V_1 * V_2 )
{
int V_84 , error ;
for ( V_84 = 0 ; V_84 < F_34 ( V_85 ) ; V_84 ++ ) {
error = F_28 ( V_74 , V_2 , V_85 [ V_84 ] ) ;
if ( error )
return error ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
V_2 -> V_28 [ V_84 ] = F_36 ( V_2 -> V_8 , L_10 ,
V_84 , V_86 ) ;
if ( F_37 ( V_2 -> V_28 [ V_84 ] ) ) {
F_19 ( V_2 -> V_8 , L_11 ,
V_84 , F_38 ( V_2 -> V_28 [ V_84 ] ) ) ;
V_2 -> V_28 [ V_84 ] = NULL ;
}
}
}
static int F_39 ( struct V_1 * V_2 )
{
const char * const V_87 [ V_88 ] = {
L_12 , L_13 , L_14 , L_15 , L_16 ,
} ;
int error , V_84 ;
for ( V_84 = 0 ; V_84 < V_88 ; V_84 ++ ) {
V_2 -> V_6 [ V_84 ] = F_40 ( V_2 -> V_8 ,
V_87 [ V_84 ] ) ;
if ( F_37 ( V_2 -> V_6 [ V_84 ] ) ) {
error = F_38 ( V_2 -> V_6 [ V_84 ] ) ;
goto V_38;
}
if ( ! V_2 -> V_6 [ V_84 ] -> V_89 ) {
error = - V_90 ;
goto V_38;
}
}
return 0 ;
V_38:
F_15 ( V_2 -> V_8 , L_17 ,
error ) ;
return error ;
}
static int F_41 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
const struct V_91 * V_92 ;
struct V_93 V_94 = {} ;
int error ;
V_92 = F_42 ( F_43 ( V_95 ) ,
& V_74 -> V_8 ) ;
if ( ! V_92 )
return - V_26 ;
V_2 = F_31 ( & V_74 -> V_8 , sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_8 = & V_74 -> V_8 ;
V_2 -> V_33 = F_44 ( V_2 -> V_8 -> V_18 , NULL ) ;
if ( ! V_2 -> V_33 )
return - V_78 ;
F_45 ( & V_2 -> V_83 ) ;
F_46 ( & V_2 -> V_63 , F_25 ) ;
F_46 ( & V_2 -> V_45 , F_17 ) ;
F_47 ( V_74 , V_2 ) ;
error = F_39 ( V_2 ) ;
if ( error )
return error ;
F_48 ( & V_2 -> V_70 , 1 ) ;
V_94 . V_96 = V_74 -> V_8 . V_96 ;
V_94 . V_97 = V_2 ;
V_2 -> V_98 = F_49 ( V_2 -> V_8 ,
& V_99 ,
& V_94 ) ;
if ( F_37 ( V_2 -> V_98 ) ) {
error = F_38 ( V_2 -> V_98 ) ;
F_15 ( V_2 -> V_8 , L_18 ,
error ) ;
return error ;
}
error = F_33 ( V_74 , V_2 ) ;
if ( error )
return error ;
V_2 -> V_49 . V_100 = F_20 ;
error = F_50 ( & V_2 -> V_49 ) ;
if ( error == - V_78 ) {
F_19 ( V_2 -> V_8 , L_19 ) ;
return - V_101 ;
}
F_35 ( V_2 ) ;
F_21 ( & V_2 -> V_63 , 0 ) ;
return 0 ;
}
static int F_51 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_52 ( V_74 ) ;
int error ;
F_48 ( & V_2 -> V_70 , 0 ) ;
error = F_50 ( NULL ) ;
if ( error )
F_3 ( V_2 -> V_8 , L_20 ,
error ) ;
error = F_12 ( V_2 , 0 , 0 , 0 ) ;
if ( error )
F_3 ( V_2 -> V_8 , L_21 ,
error ) ;
F_53 ( & V_2 -> V_45 ) ;
F_53 ( & V_2 -> V_63 ) ;
return 0 ;
}
