static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = V_2 -> V_4 ;
return 1 ;
}
static int F_2 ( const char * V_5 , struct V_6 * V_7 )
{
long unsigned int V_8 ;
int V_9 ;
union T_2 {
struct V_10 V_11 ;
int V_12 ;
} V_13 ;
V_9 = F_3 ( V_5 , 16 , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 > 0xFFFFFF )
return - V_14 ;
V_13 . V_12 = V_8 & 0x0f0f0f0f ;
F_4 ( L_1 ,
V_13 . V_11 . V_15 , V_13 . V_11 . V_16 , V_13 . V_11 . V_17 ) ;
V_7 -> V_18 = V_13 . V_11 ;
return 0 ;
}
static struct V_6 * F_5 ( struct V_19 * V_20 )
{
T_3 V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_21 ; V_7 ++ ) {
if ( (struct V_19 * ) V_22 [ V_7 ] . V_20 == V_20 ) {
F_4 ( L_2 ,
V_22 [ V_7 ] . V_23 ) ;
return & V_22 [ V_7 ] ;
}
}
return NULL ;
}
static int F_6 ( struct V_6 * V_7 )
{
int V_24 ;
T_4 V_25 ;
char * V_26 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
struct V_31 V_32 ;
if ( V_33 == V_34 ) {
V_32 . V_35 = 1 << V_7 -> V_23 ;
V_32 . V_18 = V_7 -> V_18 ;
V_32 . V_36 = V_37 ;
V_26 = V_38 ;
V_24 = V_39 ;
V_28 . V_40 = ( V_41 ) sizeof( V_32 ) ;
V_28 . V_42 = & V_32 ;
} else {
V_30 . V_18 = V_7 -> V_18 ;
V_30 . V_43 = V_44 ;
V_30 . V_36 = 0 ;
if ( V_37 == V_45 ||
V_37 == V_46 ) {
V_26 = V_47 ;
V_30 . V_36 = V_37 ;
} else
V_26 = V_48 ;
V_24 = V_7 -> V_23 + 1 ;
V_28 . V_40 = ( V_41 ) sizeof( V_30 ) ;
V_28 . V_42 = & V_30 ;
}
F_4 ( L_3 , V_26 , V_24 ) ;
V_25 = F_7 ( V_26 , 0 , V_24 , & V_28 , NULL ) ;
if ( F_8 ( V_25 ) )
F_9 ( L_4 , V_25 ) ;
return F_8 ( V_25 ) ;
}
static T_5 F_10 ( struct V_49 * V_50 , struct V_19 * V_20 ,
char * V_5 )
{
struct V_6 * V_51 ;
V_51 = F_5 ( V_20 ) ;
if ( V_51 == NULL )
return sprintf ( V_5 , L_5 ) ;
return sprintf ( V_5 , L_6 ,
V_51 -> V_18 . V_15 ,
V_51 -> V_18 . V_16 , V_51 -> V_18 . V_17 ) ;
}
static T_5 F_11 ( struct V_49 * V_50 , struct V_19 * V_20 ,
const char * V_5 , T_6 V_52 )
{
struct V_6 * V_51 ;
int V_9 ;
V_51 = F_5 ( V_20 ) ;
if ( V_51 == NULL ) {
F_9 ( L_7 ) ;
return 1 ;
}
V_9 = F_2 ( V_5 , V_51 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_6 ( V_51 ) ;
return V_9 ? V_9 : V_52 ;
}
static int F_12 ( int V_43 )
{
T_4 V_25 ;
struct V_27 V_28 ;
struct V_53 args = {
. V_35 = 0xFF ,
. V_54 = V_43 ,
} ;
V_28 . V_40 = ( V_41 ) sizeof( args ) ;
V_28 . V_42 = & args ;
V_25 = F_7 ( V_38 , 0 ,
V_55 , & V_28 , NULL ) ;
if ( F_8 ( V_25 ) )
F_9 ( L_8 , V_25 ) ;
return F_8 ( V_25 ) ;
}
static void F_13 ( struct V_56 * V_57 ,
enum V_58 V_43 )
{
int V_9 ;
V_44 = V_43 ;
if ( V_33 == V_34 )
V_9 = F_12 ( V_43 ) ;
else
V_9 = F_6 ( & V_22 [ 0 ] ) ;
if ( V_9 )
F_9 ( L_9 ) ;
}
static enum V_58 F_14 ( struct V_56 * V_57 )
{
return V_44 ;
}
static T_5 F_15 ( struct V_49 * V_50 ,
struct V_19 * V_20 , char * V_5 )
{
if ( V_37 == V_45 )
return F_16 ( V_5 , V_59 , L_10 ) ;
else if ( V_37 == V_46 )
return F_16 ( V_5 , V_59 , L_11 ) ;
return F_16 ( V_5 , V_59 , L_12 ) ;
}
static T_5 F_17 ( struct V_49 * V_50 ,
struct V_19 * V_20 ,
const char * V_5 , T_6 V_52 )
{
long unsigned int V_60 ;
if ( strcmp ( V_5 , L_13 ) == 0 )
V_60 = V_45 ;
else if ( strcmp ( V_5 , L_14 ) == 0 )
V_60 = V_46 ;
else if ( V_33 == V_61 )
V_60 = V_62 ;
else
V_60 = V_63 ;
V_37 = V_60 ;
F_4 ( L_15 ,
V_37 ) ;
return V_52 ;
}
static int F_18 ( struct V_64 * V_50 )
{
T_3 V_7 ;
char V_65 [ 10 ] ;
char * V_66 ;
if ( V_33 == V_34 ) {
V_37 = V_63 ;
} else if ( V_33 == V_61 ) {
V_37 = V_62 ;
}
V_67 . V_68 = 0x0F ;
V_44 = V_67 . V_68 ;
V_69 =
F_19 ( sizeof( struct V_19 ) * ( V_3 -> V_21 + 1 ) ,
V_70 ) ;
if ( ! V_69 )
return - V_71 ;
V_72 =
F_19 ( sizeof( struct V_73 * ) * ( V_3 -> V_21 + 2 ) ,
V_70 ) ;
if ( ! V_72 )
return - V_71 ;
V_22 =
F_19 ( sizeof( struct V_6 ) * ( V_3 -> V_21 ) ,
V_70 ) ;
if ( ! V_22 )
return - V_71 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_21 ; V_7 ++ ) {
sprintf ( V_65 , L_16 , V_7 ) ;
V_66 = F_20 ( V_65 , V_70 ) ;
if ( V_66 == NULL )
return 1 ;
F_21 ( & V_69 [ V_7 ] . V_20 ) ;
V_69 [ V_7 ] . V_20 . V_66 = V_66 ;
V_69 [ V_7 ] . V_20 . V_74 = 0644 ;
V_69 [ V_7 ] . V_75 = F_10 ;
V_69 [ V_7 ] . V_76 = F_11 ;
V_22 [ V_7 ] . V_23 = V_7 ;
V_72 [ V_7 ] = & V_69 [ V_7 ] . V_20 ;
V_22 [ V_7 ] . V_20 = & V_69 [ V_7 ] ;
}
V_72 [ V_3 -> V_21 ] = & V_77 . V_20 ;
V_78 . V_79 = V_72 ;
F_22 ( & V_50 -> V_50 , & V_67 ) ;
return F_23 ( & V_50 -> V_50 . V_80 , & V_78 ) ;
}
static void F_24 ( struct V_64 * V_50 )
{
T_3 V_7 ;
F_25 ( & V_50 -> V_50 . V_80 , & V_78 ) ;
F_26 ( & V_67 ) ;
if ( V_69 ) {
for ( V_7 = 0 ; V_7 < V_3 -> V_21 ; V_7 ++ )
F_27 ( V_69 [ V_7 ] . V_20 . V_66 ) ;
}
F_27 ( V_69 ) ;
F_27 ( V_22 ) ;
F_27 ( V_72 ) ;
}
static T_4 F_28 ( struct V_32 * V_81 ,
T_7 V_82 , int * V_83 )
{
T_4 V_25 ;
union V_84 * V_85 ;
struct V_27 V_28 ;
struct V_27 V_86 ;
V_28 . V_40 = ( V_41 ) sizeof( * V_81 ) ;
V_28 . V_42 = V_81 ;
if ( V_83 != NULL ) {
V_86 . V_40 = V_87 ;
V_86 . V_42 = NULL ;
V_25 = F_7 ( V_38 , 0 ,
V_82 , & V_28 , & V_86 ) ;
} else
V_25 = F_7 ( V_38 , 0 ,
V_82 , & V_28 , NULL ) ;
if ( F_29 ( V_25 ) && V_83 != NULL ) {
V_85 = (union V_84 * ) V_86 . V_42 ;
if ( V_85 && V_85 -> type == V_88 )
* V_83 = ( T_7 ) V_85 -> integer . V_89 ;
}
return V_25 ;
}
static T_5 F_30 ( struct V_49 * V_50 ,
struct V_19 * V_20 , char * V_5 )
{
T_4 V_25 ;
T_7 V_83 ;
struct V_32 V_81 = {
. V_90 = 0 ,
} ;
V_25 =
F_28 ( & V_81 , V_91 ,
( T_7 * ) & V_83 ) ;
if ( F_29 ( V_25 ) ) {
if ( V_83 == 0 )
return F_16 ( V_5 , V_59 ,
L_17 ) ;
else if ( V_83 == 1 )
return F_16 ( V_5 , V_59 ,
L_18 ) ;
}
F_9 ( L_19 , V_25 ) ;
return F_16 ( V_5 , V_59 , L_20 ) ;
}
static T_5 F_31 ( struct V_49 * V_50 ,
struct V_19 * V_20 , char * V_5 )
{
T_4 V_25 ;
T_7 V_83 ;
struct V_32 V_81 = {
. V_90 = 0 ,
} ;
V_25 =
F_28 ( & V_81 , V_92 ,
( T_7 * ) & V_83 ) ;
if ( F_29 ( V_25 ) ) {
if ( V_83 == 1 )
return F_16 ( V_5 , V_59 ,
L_21 ) ;
else if ( V_83 == 2 )
return F_16 ( V_5 , V_59 ,
L_22 ) ;
}
F_9 ( L_23 , V_83 ) ;
return F_16 ( V_5 , V_59 , L_24 ) ;
}
static T_5 F_32 ( struct V_49 * V_50 ,
struct V_19 * V_20 ,
const char * V_5 , T_6 V_52 )
{
T_4 V_25 ;
struct V_32 args ;
if ( strcmp ( V_5 , L_25 ) == 0 )
args . V_90 = 1 ;
else if ( strcmp ( V_5 , L_26 ) == 0 )
args . V_90 = 2 ;
else
args . V_90 = 3 ;
F_4 ( L_27 , args . V_90 , V_5 ) ;
V_25 = F_28 ( & args , V_93 , NULL ) ;
if ( F_8 ( V_25 ) )
F_9 ( L_28 ,
V_25 ) ;
return V_52 ;
}
static void F_33 ( struct V_64 * V_50 )
{
if ( V_3 -> V_94 > 0 )
F_25 ( & V_50 -> V_50 . V_80 , & V_95 ) ;
}
static int F_34 ( struct V_64 * V_50 )
{
int V_9 ;
V_9 = F_23 ( & V_50 -> V_50 . V_80 , & V_95 ) ;
if ( V_9 )
F_33 ( V_50 ) ;
return V_9 ;
}
static T_5 F_35 ( struct V_49 * V_50 ,
struct V_19 * V_20 , char * V_5 )
{
T_4 V_25 ;
T_7 V_83 ;
struct V_32 V_81 = {
. V_90 = 0 ,
} ;
V_25 =
F_28 ( & V_81 , V_96 ,
( T_7 * ) & V_83 ) ;
if ( F_29 ( V_25 ) ) {
if ( V_83 == 0 )
return F_16 ( V_5 , V_59 ,
L_17 ) ;
else if ( V_83 == 1 )
return F_16 ( V_5 , V_59 ,
L_18 ) ;
}
F_9 ( L_29 , V_25 ) ;
return F_16 ( V_5 , V_59 , L_20 ) ;
}
static void F_36 ( struct V_64 * V_50 )
{
if ( V_3 -> V_97 > 0 )
F_25 ( & V_50 -> V_50 . V_80 , & V_98 ) ;
}
static int F_37 ( struct V_64 * V_50 )
{
int V_9 ;
V_9 = F_23 ( & V_50 -> V_50 . V_80 , & V_98 ) ;
if ( V_9 )
F_36 ( V_50 ) ;
return V_9 ;
}
static T_5 F_38 ( struct V_49 * V_50 ,
struct V_19 * V_20 , char * V_5 )
{
T_4 V_25 ;
T_7 V_83 ;
struct V_32 V_81 = {
. V_90 = 0 ,
} ;
V_25 = F_28 ( & V_81 , V_99 ,
( T_7 * ) & V_83 ) ;
if ( F_29 ( V_25 ) ) {
if ( V_83 == 0 )
return F_16 ( V_5 , V_59 ,
L_30 ) ;
else if ( V_83 == 1 )
return F_16 ( V_5 , V_59 ,
L_31 ) ;
else if ( V_83 == 2 )
return F_16 ( V_5 , V_59 ,
L_32 ) ;
}
F_9 ( L_33 , V_25 ) ;
return F_16 ( V_5 , V_59 , L_34 ) ;
}
static T_5 F_39 ( struct V_49 * V_50 ,
struct V_19 * V_20 ,
const char * V_5 , T_6 V_52 )
{
T_4 V_25 ;
struct V_32 args ;
if ( strcmp ( V_5 , L_35 ) == 0 )
args . V_90 = 0 ;
else if ( strcmp ( V_5 , L_36 ) == 0 )
args . V_90 = 1 ;
else
args . V_90 = 2 ;
F_4 ( L_37 , args . V_90 , V_5 ) ;
V_25 = F_28 ( & args , V_100 ,
NULL ) ;
if ( F_8 ( V_25 ) )
F_9 ( L_38 ,
V_25 ) ;
return V_52 ;
}
static void F_40 ( struct V_64 * V_50 )
{
if ( V_3 -> V_101 > 0 )
F_25 ( & V_50 -> V_50 . V_80 , & V_102 ) ;
}
static int F_41 ( struct V_64 * V_50 )
{
int V_9 ;
V_9 = F_23 ( & V_50 -> V_50 . V_80 , & V_102 ) ;
if ( V_9 )
F_40 ( V_50 ) ;
return V_9 ;
}
static int T_1 F_42 ( void )
{
int V_9 ;
if ( F_43 ( V_48 ) )
V_33 = V_61 ;
else if ( F_43 ( V_38 ) )
V_33 = V_34 ;
else {
F_44 ( L_39 ) ;
return - V_103 ;
}
F_45 ( V_104 ) ;
if ( V_3 == NULL )
V_3 = & V_105 ;
V_9 = F_46 ( & V_106 ) ;
if ( V_9 )
goto V_107;
V_64 = F_47 ( L_40 , - 1 ) ;
if ( ! V_64 ) {
V_9 = - V_71 ;
goto V_108;
}
V_9 = F_48 ( V_64 ) ;
if ( V_9 )
goto V_109;
if ( V_3 -> V_94 > 0 ) {
V_9 = F_34 ( V_64 ) ;
if ( V_9 )
goto V_110;
}
if ( V_3 -> V_97 > 0 ) {
V_9 = F_37 ( V_64 ) ;
if ( V_9 )
goto V_111;
}
if ( V_3 -> V_101 > 0 ) {
V_9 = F_41 ( V_64 ) ;
if ( V_9 )
goto V_112;
}
V_9 = F_18 ( V_64 ) ;
if ( V_9 )
goto V_113;
return 0 ;
V_113:
F_24 ( V_64 ) ;
V_112:
V_111:
V_110:
F_49 ( V_64 ) ;
V_109:
F_50 ( V_64 ) ;
V_108:
F_51 ( & V_106 ) ;
V_107:
return V_9 ;
}
static void T_8 F_52 ( void )
{
if ( V_64 ) {
F_24 ( V_64 ) ;
F_33 ( V_64 ) ;
F_53 ( V_64 ) ;
F_51 ( & V_106 ) ;
}
}
