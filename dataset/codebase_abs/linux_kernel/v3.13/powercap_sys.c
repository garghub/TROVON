static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
const char * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
T_1 V_10 = - V_11 ;
struct V_12 * V_13 ;
if ( ! sscanf ( V_4 -> V_14 . V_6 , L_1 , & V_9 ) )
return - V_15 ;
if ( V_9 >= V_8 -> V_16 )
return - V_15 ;
V_13 = & V_8 -> V_17 [ V_9 ] ;
if ( V_13 && V_13 -> V_18 && V_13 -> V_18 -> V_19 ) {
V_6 = V_13 -> V_18 -> V_19 ( V_8 , V_9 ) ;
if ( V_6 ) {
snprintf ( V_5 , V_20 ,
L_2 , V_6 ) ;
V_5 [ V_20 ] = '\0' ;
V_10 = strlen ( V_5 ) ;
}
}
return V_10 ;
}
static int F_3 ( int V_9 , const char * V_6 ,
int V_21 ,
struct V_3 * V_4 ,
T_1 (* F_4)( struct V_1 * ,
struct V_3 * , char * ) ,
T_1 (* F_5)( struct V_1 * ,
struct V_3 * ,
const char * , T_2 )
)
{
V_4 -> V_14 . V_6 = F_6 ( V_22 , L_3 ,
V_9 , V_6 ) ;
if ( ! V_4 -> V_14 . V_6 )
return - V_23 ;
V_4 -> V_14 . V_21 = V_21 ;
V_4 -> F_4 = F_4 ;
V_4 -> F_5 = F_5 ;
return 0 ;
}
static void F_7 ( void )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; ++ V_24 ) {
F_8 ( V_26 [ V_24 ] . V_27 . V_14 . V_6 ) ;
F_8 ( V_26 [ V_24 ] . V_28 . V_14 . V_6 ) ;
F_8 ( V_26 [ V_24 ] . V_29 . V_14 . V_6 ) ;
F_8 ( V_26 [ V_24 ] . V_30 . V_14 . V_6 ) ;
F_8 ( V_26 [ V_24 ] . V_31 . V_14 . V_6 ) ;
F_8 ( V_26 [ V_24 ] . V_32 . V_14 . V_6 ) ;
F_8 ( V_26 [ V_24 ] . V_33 . V_14 . V_6 ) ;
}
}
static int F_9 ( void )
{
int V_24 ;
int V_34 ;
for ( V_24 = 0 ; V_24 < V_25 ; ++ V_24 ) {
V_34 = F_3 ( V_24 , L_4 ,
V_35 | V_36 ,
& V_26 [ V_24 ] . V_27 ,
V_37 ,
V_38 ) ;
if ( V_34 )
goto V_39;
V_34 = F_3 ( V_24 , L_5 ,
V_35 | V_36 ,
& V_26 [ V_24 ] . V_28 ,
V_40 ,
V_41 ) ;
if ( V_34 )
goto V_39;
V_34 = F_3 ( V_24 , L_6 , V_36 ,
& V_26 [ V_24 ] . V_29 ,
F_1 ,
NULL ) ;
if ( V_34 )
goto V_39;
V_34 = F_3 ( V_24 , L_7 , V_36 ,
& V_26 [ V_24 ] . V_30 ,
V_42 ,
NULL ) ;
if ( V_34 )
goto V_39;
V_34 = F_3 ( V_24 , L_8 , V_36 ,
& V_26 [ V_24 ] . V_31 ,
V_43 ,
NULL ) ;
if ( V_34 )
goto V_39;
V_34 = F_3 ( V_24 , L_9 ,
V_36 ,
& V_26 [ V_24 ] . V_32 ,
V_44 ,
NULL ) ;
if ( V_34 )
goto V_39;
V_34 = F_3 ( V_24 , L_10 ,
V_36 ,
& V_26 [ V_24 ] . V_33 ,
V_45 ,
NULL ) ;
if ( V_34 )
goto V_39;
}
return 0 ;
V_39:
F_7 () ;
return V_34 ;
}
static int F_10 ( struct V_7 * V_8 ,
int V_46 ,
struct V_47 * V_48 )
{
int V_24 ;
int V_34 = 0 ;
int V_49 ;
struct V_12 * V_13 ;
if ( ! V_8 || ! V_48 || ! V_48 -> V_50 ||
! V_48 -> V_51 ||
! V_48 -> V_52 ||
! V_48 -> V_53 )
return - V_15 ;
V_49 = V_8 -> V_54 ;
for ( V_24 = 0 ; V_24 < V_46 ; ++ V_24 ) {
V_13 = & V_8 -> V_17 [ V_24 ] ;
V_13 -> V_18 = V_48 ;
V_13 -> V_9 = V_8 -> V_16 ;
V_8 -> V_16 ++ ;
V_8 -> V_55 [ V_49 ++ ] =
& V_26 [ V_24 ] . V_27 . V_14 ;
V_8 -> V_55 [ V_49 ++ ] =
& V_26 [ V_24 ] . V_28 . V_14 ;
if ( V_13 -> V_18 -> V_19 )
V_8 -> V_55 [ V_49 ++ ] =
& V_26 [ V_24 ] . V_29 . V_14 ;
if ( V_13 -> V_18 -> V_56 )
V_8 -> V_55 [ V_49 ++ ] =
& V_26 [ V_24 ] . V_30 . V_14 ;
if ( V_13 -> V_18 -> V_57 )
V_8 -> V_55 [ V_49 ++ ] =
& V_26 [ V_24 ] . V_31 . V_14 ;
if ( V_13 -> V_18 -> V_58 )
V_8 -> V_55 [ V_49 ++ ] =
& V_26 [ V_24 ] . V_32 . V_14 ;
if ( V_13 -> V_18 -> V_59 )
V_8 -> V_55 [ V_49 ++ ] =
& V_26 [ V_24 ] . V_33 . V_14 ;
}
V_8 -> V_54 = V_49 ;
return V_34 ;
}
static bool F_11 ( void * V_60 )
{
struct V_61 * V_62 = NULL ;
bool V_63 = false ;
F_12 ( & V_64 ) ;
F_13 (pos, &powercap_cntrl_list, node) {
if ( V_62 == V_60 ) {
V_63 = true ;
break;
}
}
F_14 ( & V_64 ) ;
return V_63 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_14 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_8 -> V_6 ) ;
}
static void F_16 (
struct V_7 * V_8 )
{
int V_49 = 0 ;
V_8 -> V_55 [ V_49 ++ ] = & V_65 . V_14 ;
if ( V_8 -> V_18 -> V_66 )
V_8 -> V_55 [ V_49 ++ ] =
& V_67 . V_14 ;
if ( V_8 -> V_18 -> V_68 ) {
if ( V_8 -> V_18 -> V_69 )
V_70 . V_14 . V_21 = V_35 | V_36 ;
else
V_70 . V_14 . V_21 = V_36 ;
V_8 -> V_55 [ V_49 ++ ] =
& V_70 . V_14 ;
}
if ( V_8 -> V_18 -> V_71 )
V_8 -> V_55 [ V_49 ++ ] =
& V_72 . V_14 ;
if ( V_8 -> V_18 -> V_73 )
V_8 -> V_55 [ V_49 ++ ] =
& V_74 . V_14 ;
V_8 -> V_55 [ V_49 ] = NULL ;
V_8 -> V_54 = V_49 ;
}
static void F_17 ( struct V_1 * V_2 )
{
bool V_75 ;
if ( V_2 -> V_76 ) {
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_75 = V_8 -> V_75 ;
F_18 ( V_8 -> V_77 , V_8 -> V_9 ) ;
F_19 ( & V_8 -> V_78 ) ;
F_8 ( V_8 -> V_6 ) ;
F_8 ( V_8 -> V_55 ) ;
F_8 ( V_8 -> V_17 ) ;
if ( V_8 -> V_18 -> V_79 )
V_8 -> V_18 -> V_79 ( V_8 ) ;
if ( V_75 )
F_8 ( V_8 ) ;
} else {
struct V_61 * V_60 =
F_20 ( V_2 ) ;
V_75 = V_60 -> V_75 ;
F_19 ( & V_60 -> V_78 ) ;
F_21 ( & V_60 -> V_80 ) ;
if ( V_60 -> V_18 && V_60 -> V_18 -> V_79 )
V_60 -> V_18 -> V_79 ( V_60 ) ;
if ( V_75 )
F_8 ( V_60 ) ;
}
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_14 ,
char * V_5 )
{
bool V_21 = true ;
if ( V_2 -> V_76 ) {
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_18 -> V_81 )
if ( V_8 -> V_18 -> V_81 ( V_8 , & V_21 ) )
V_21 = false ;
} else {
struct V_61 * V_60 =
F_20 ( V_2 ) ;
if ( V_60 -> V_18 && V_60 -> V_18 -> V_81 )
if ( V_60 -> V_18 -> V_81 ( V_60 , & V_21 ) )
V_21 = false ;
}
return sprintf ( V_5 , L_11 , V_21 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_3 * V_14 ,
const char * V_5 , T_2 V_10 )
{
bool V_21 ;
if ( F_24 ( V_5 , & V_21 ) )
return - V_15 ;
if ( V_2 -> V_76 ) {
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_18 -> V_82 )
if ( ! V_8 -> V_18 -> V_82 ( V_8 , V_21 ) )
return V_10 ;
} else {
struct V_61 * V_60 =
F_20 ( V_2 ) ;
if ( V_60 -> V_18 && V_60 -> V_18 -> V_82 )
if ( ! V_60 -> V_18 -> V_82 ( V_60 , V_21 ) )
return V_10 ;
}
return - V_83 ;
}
struct V_7 * F_25 (
struct V_7 * V_8 ,
struct V_61 * V_60 ,
const char * V_6 ,
struct V_7 * V_76 ,
const struct V_84 * V_18 ,
int V_46 ,
struct V_47 * V_48 )
{
int V_85 ;
int V_86 ;
if ( ! V_6 || ! V_60 || ! V_18 ||
V_46 > V_25 ||
( ! V_18 -> V_68 && ! V_18 -> V_71 ) ||
! F_11 ( V_60 ) )
return F_26 ( - V_15 ) ;
if ( V_8 ) {
if ( ! V_18 -> V_79 )
return F_26 ( - V_15 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
} else {
V_8 = F_27 ( sizeof( * V_8 ) , V_22 ) ;
if ( ! V_8 )
return F_26 ( - V_23 ) ;
V_8 -> V_75 = true ;
}
V_8 -> V_18 = V_18 ;
V_8 -> V_87 = V_60 ;
if ( ! V_76 ) {
V_8 -> V_2 . V_76 = & V_60 -> V_2 ;
V_8 -> V_77 = & V_60 -> V_78 ;
} else {
V_8 -> V_2 . V_76 = & V_76 -> V_2 ;
V_8 -> V_77 = & V_76 -> V_78 ;
}
V_8 -> V_2 . V_88 = & V_89 ;
F_12 ( & V_60 -> V_80 ) ;
V_85 = F_28 ( V_8 -> V_77 , NULL , 0 , 0 , V_22 ) ;
if ( V_85 < 0 )
goto V_90;
V_8 -> V_9 = V_85 ;
F_29 ( & V_8 -> V_78 ) ;
V_8 -> V_6 = F_30 ( V_6 , V_22 ) ;
if ( ! V_8 -> V_6 )
goto V_91;
F_31 ( & V_8 -> V_2 , L_12 ,
F_32 ( V_8 -> V_2 . V_76 ) ,
V_8 -> V_9 ) ;
V_8 -> V_17 = F_27 ( sizeof( * V_8 -> V_17 ) *
V_46 , V_22 ) ;
if ( ! V_8 -> V_17 )
goto V_92;
V_86 = V_46 * V_93 +
V_94 + 1 ;
V_8 -> V_55 = F_27 ( sizeof( void * ) *
V_86 , V_22 ) ;
if ( ! V_8 -> V_55 )
goto V_95;
F_16 ( V_8 ) ;
V_85 = F_10 ( V_8 , V_46 , V_48 ) ;
if ( V_85 )
goto V_96;
V_8 -> V_55 [ V_8 -> V_54 ] = NULL ;
V_8 -> V_97 . V_98 = V_8 -> V_55 ;
V_8 -> V_99 [ 0 ] = & V_8 -> V_97 ;
V_8 -> V_99 [ 1 ] = NULL ;
V_8 -> V_2 . V_100 = V_8 -> V_99 ;
V_85 = F_33 ( & V_8 -> V_2 ) ;
if ( V_85 )
goto V_96;
V_60 -> V_101 ++ ;
F_14 ( & V_60 -> V_80 ) ;
return V_8 ;
V_96:
F_8 ( V_8 -> V_55 ) ;
V_95:
F_8 ( V_8 -> V_17 ) ;
V_92:
F_8 ( V_8 -> V_6 ) ;
V_91:
F_18 ( V_8 -> V_77 , V_8 -> V_9 ) ;
V_90:
if ( V_8 -> V_75 )
F_8 ( V_8 ) ;
F_14 ( & V_60 -> V_80 ) ;
return F_26 ( V_85 ) ;
}
int F_34 ( struct V_61 * V_60 ,
struct V_7 * V_8 )
{
if ( ! V_8 || ! V_60 )
return - V_15 ;
F_12 ( & V_60 -> V_80 ) ;
V_60 -> V_101 -- ;
F_14 ( & V_60 -> V_80 ) ;
F_35 ( & V_8 -> V_2 ) ;
return 0 ;
}
struct V_61 * F_36 (
struct V_61 * V_60 ,
const char * V_6 ,
const struct V_102 * V_18 )
{
int V_85 ;
if ( ! V_6 )
return F_26 ( - V_15 ) ;
if ( V_60 ) {
if ( ! V_18 || ! V_18 -> V_79 )
return F_26 ( - V_15 ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
} else {
V_60 = F_27 ( sizeof( * V_60 ) , V_22 ) ;
if ( ! V_60 )
return F_26 ( - V_23 ) ;
V_60 -> V_75 = true ;
}
F_37 ( & V_60 -> V_80 ) ;
V_60 -> V_18 = V_18 ;
F_38 ( & V_60 -> V_103 ) ;
V_60 -> V_2 . V_88 = & V_89 ;
F_31 ( & V_60 -> V_2 , L_13 , V_6 ) ;
V_85 = F_33 ( & V_60 -> V_2 ) ;
if ( V_85 ) {
if ( V_60 -> V_75 )
F_8 ( V_60 ) ;
return F_26 ( V_85 ) ;
}
F_29 ( & V_60 -> V_78 ) ;
F_12 ( & V_64 ) ;
F_39 ( & V_60 -> V_103 , & V_104 ) ;
F_14 ( & V_64 ) ;
return V_60 ;
}
int F_40 ( struct V_61 * V_60 )
{
struct V_61 * V_62 = NULL ;
if ( V_60 -> V_101 ) {
F_41 ( & V_60 -> V_2 , L_14 ) ;
return - V_15 ;
}
F_12 ( & V_64 ) ;
F_13 (pos, &powercap_cntrl_list, node) {
if ( V_62 == V_60 ) {
F_42 ( & V_60 -> V_103 ) ;
F_14 ( & V_64 ) ;
F_35 ( & V_60 -> V_2 ) ;
return 0 ;
}
}
F_14 ( & V_64 ) ;
return - V_105 ;
}
static int T_3 F_43 ( void )
{
int V_85 = 0 ;
V_85 = F_9 () ;
if ( V_85 )
return V_85 ;
V_85 = F_44 ( & V_89 ) ;
return V_85 ;
}
