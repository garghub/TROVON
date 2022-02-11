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
int V_21 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_22 ; V_21 ++ ) {
if ( (struct V_19 * ) V_23 [ V_21 ] . V_20 == V_20 ) {
F_4 ( L_2 ,
V_23 [ V_21 ] . V_24 ) ;
return & V_23 [ V_21 ] ;
}
}
return NULL ;
}
static int F_6 ( struct V_6 * V_7 )
{
int V_25 ;
T_3 V_26 ;
char * V_27 ;
struct V_28 V_29 ;
struct V_30 V_31 ;
struct V_32 V_33 ;
if ( V_34 == V_35 ) {
V_33 . V_36 = 1 << V_7 -> V_24 ;
V_33 . V_18 = V_7 -> V_18 ;
V_33 . V_37 = V_38 ;
V_27 = V_39 ;
V_25 = V_40 ;
V_29 . V_41 = ( V_42 ) sizeof( V_33 ) ;
V_29 . V_43 = & V_33 ;
} else {
V_31 . V_18 = V_7 -> V_18 ;
V_31 . V_44 = V_45 ;
V_31 . V_37 = 0 ;
if ( V_38 == V_46 ||
V_38 == V_47 ) {
V_27 = V_48 ;
V_31 . V_37 = V_38 ;
} else
V_27 = V_49 ;
V_25 = V_7 -> V_24 + 1 ;
V_29 . V_41 = ( V_42 ) sizeof( V_31 ) ;
V_29 . V_43 = & V_31 ;
}
F_4 ( L_3 , V_27 , V_25 ) ;
V_26 = F_7 ( V_27 , 1 , V_25 , & V_29 , NULL ) ;
if ( F_8 ( V_26 ) )
F_9 ( L_4 , V_26 ) ;
return F_8 ( V_26 ) ;
}
static T_4 F_10 ( struct V_50 * V_51 , struct V_19 * V_20 ,
char * V_5 )
{
struct V_6 * V_52 ;
V_52 = F_5 ( V_20 ) ;
if ( V_52 == NULL )
return sprintf ( V_5 , L_5 ) ;
return sprintf ( V_5 , L_6 ,
V_52 -> V_18 . V_15 ,
V_52 -> V_18 . V_16 , V_52 -> V_18 . V_17 ) ;
}
static T_4 F_11 ( struct V_50 * V_51 , struct V_19 * V_20 ,
const char * V_5 , T_5 V_53 )
{
struct V_6 * V_52 ;
int V_9 ;
V_52 = F_5 ( V_20 ) ;
if ( V_52 == NULL ) {
F_9 ( L_7 ) ;
return 1 ;
}
V_9 = F_2 ( V_5 , V_52 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_6 ( V_52 ) ;
return V_9 ? V_9 : V_53 ;
}
static int F_12 ( int V_44 )
{
T_3 V_26 ;
struct V_28 V_29 ;
struct V_54 args = {
. V_36 = 0xFF ,
. V_55 = V_44 ,
} ;
V_29 . V_41 = ( V_42 ) sizeof( args ) ;
V_29 . V_43 = & args ;
V_26 = F_7 ( V_39 , 1 ,
V_56 , & V_29 , NULL ) ;
if ( F_8 ( V_26 ) )
F_9 ( L_8 , V_26 ) ;
return F_8 ( V_26 ) ;
}
static void F_13 ( struct V_57 * V_58 ,
enum V_59 V_44 )
{
int V_9 ;
V_45 = V_44 ;
if ( V_34 == V_35 )
V_9 = F_12 ( V_44 ) ;
else
V_9 = F_6 ( & V_23 [ 0 ] ) ;
if ( V_9 )
F_9 ( L_9 ) ;
}
static enum V_59 F_14 ( struct V_57 * V_58 )
{
return V_45 ;
}
static T_4 F_15 ( struct V_50 * V_51 ,
struct V_19 * V_20 , char * V_5 )
{
if ( V_38 == V_46 )
return F_16 ( V_5 , V_60 , L_10 ) ;
else if ( V_38 == V_47 )
return F_16 ( V_5 , V_60 , L_11 ) ;
return F_16 ( V_5 , V_60 , L_12 ) ;
}
static T_4 F_17 ( struct V_50 * V_51 ,
struct V_19 * V_20 ,
const char * V_5 , T_5 V_53 )
{
long unsigned int V_61 ;
if ( strcmp ( V_5 , L_13 ) == 0 )
V_61 = V_46 ;
else if ( strcmp ( V_5 , L_14 ) == 0 )
V_61 = V_47 ;
else if ( V_34 == V_62 )
V_61 = V_63 ;
else
V_61 = V_64 ;
V_38 = V_61 ;
F_4 ( L_15 ,
V_38 ) ;
return V_53 ;
}
static int F_18 ( struct V_65 * V_51 )
{
int V_21 ;
char V_66 [ 10 ] ;
char * V_67 ;
if ( V_34 == V_35 ) {
V_38 = V_64 ;
} else if ( V_34 == V_62 ) {
V_38 = V_63 ;
}
V_68 . V_69 = 0x0F ;
V_45 = V_68 . V_69 ;
V_70 =
F_19 ( sizeof( struct V_19 ) * ( V_3 -> V_22 + 1 ) ,
V_71 ) ;
if ( ! V_70 )
return - V_72 ;
V_73 =
F_19 ( sizeof( struct V_74 * ) * ( V_3 -> V_22 + 2 ) ,
V_71 ) ;
if ( ! V_73 )
return - V_72 ;
V_23 =
F_19 ( sizeof( struct V_6 ) * ( V_3 -> V_22 ) ,
V_71 ) ;
if ( ! V_23 )
return - V_72 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_22 ; V_21 ++ ) {
sprintf ( V_66 , L_16 , V_21 ) ;
V_67 = F_20 ( V_66 , V_71 ) ;
if ( V_67 == NULL )
return 1 ;
F_21 ( & V_70 [ V_21 ] . V_20 ) ;
V_70 [ V_21 ] . V_20 . V_67 = V_67 ;
V_70 [ V_21 ] . V_20 . V_75 = 0644 ;
V_70 [ V_21 ] . V_76 = F_10 ;
V_70 [ V_21 ] . V_77 = F_11 ;
V_23 [ V_21 ] . V_24 = V_21 ;
V_73 [ V_21 ] = & V_70 [ V_21 ] . V_20 ;
V_23 [ V_21 ] . V_20 = & V_70 [ V_21 ] ;
}
V_73 [ V_3 -> V_22 ] = & V_78 . V_20 ;
V_79 . V_80 = V_73 ;
F_22 ( & V_51 -> V_51 , & V_68 ) ;
return F_23 ( & V_51 -> V_51 . V_81 , & V_79 ) ;
}
static void F_24 ( struct V_65 * V_51 )
{
F_25 ( & V_51 -> V_51 . V_81 , & V_79 ) ;
F_26 ( & V_68 ) ;
if ( V_70 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_22 ; V_21 ++ )
F_27 ( V_70 [ V_21 ] . V_20 . V_67 ) ;
}
F_27 ( V_70 ) ;
F_27 ( V_23 ) ;
F_27 ( V_73 ) ;
}
static T_3 F_28 ( struct V_82 * V_83 ,
T_6 V_84 , int * V_85 )
{
T_3 V_26 ;
union V_86 * V_87 ;
struct V_28 V_29 ;
struct V_28 V_88 ;
V_29 . V_41 = ( V_42 ) sizeof( * V_83 ) ;
V_29 . V_43 = V_83 ;
if ( V_85 != NULL ) {
V_88 . V_41 = V_89 ;
V_88 . V_43 = NULL ;
V_26 = F_7 ( V_39 , 1 ,
V_84 , & V_29 , & V_88 ) ;
} else
V_26 = F_7 ( V_39 , 1 ,
V_84 , & V_29 , NULL ) ;
if ( F_29 ( V_26 ) && V_85 != NULL ) {
V_87 = (union V_86 * ) V_88 . V_43 ;
if ( V_87 && V_87 -> type == V_90 )
* V_85 = ( T_6 ) V_87 -> integer . V_91 ;
}
return V_26 ;
}
static T_4 F_30 ( struct V_50 * V_51 ,
struct V_19 * V_20 , char * V_5 )
{
T_3 V_26 ;
T_6 V_85 ;
struct V_82 V_83 = {
. V_92 = 0 ,
} ;
V_26 =
F_28 ( & V_83 , V_93 ,
( T_6 * ) & V_85 ) ;
if ( F_29 ( V_26 ) ) {
if ( V_85 == 0 )
return F_16 ( V_5 , V_60 ,
L_17 ) ;
else if ( V_85 == 1 )
return F_16 ( V_5 , V_60 ,
L_18 ) ;
}
F_9 ( L_19 , V_26 ) ;
return F_16 ( V_5 , V_60 , L_20 ) ;
}
static T_4 F_31 ( struct V_50 * V_51 ,
struct V_19 * V_20 , char * V_5 )
{
T_3 V_26 ;
T_6 V_85 ;
struct V_82 V_83 = {
. V_92 = 0 ,
} ;
V_26 =
F_28 ( & V_83 , V_94 ,
( T_6 * ) & V_85 ) ;
if ( F_29 ( V_26 ) ) {
if ( V_85 == 1 )
return F_16 ( V_5 , V_60 ,
L_21 ) ;
else if ( V_85 == 2 )
return F_16 ( V_5 , V_60 ,
L_22 ) ;
}
F_9 ( L_23 , V_85 ) ;
return F_16 ( V_5 , V_60 , L_24 ) ;
}
static T_4 F_32 ( struct V_50 * V_51 ,
struct V_19 * V_20 ,
const char * V_5 , T_5 V_53 )
{
T_3 V_26 ;
struct V_82 args ;
if ( strcmp ( V_5 , L_25 ) == 0 )
args . V_92 = 1 ;
else if ( strcmp ( V_5 , L_26 ) == 0 )
args . V_92 = 2 ;
else
args . V_92 = 3 ;
F_4 ( L_27 , args . V_92 , V_5 ) ;
V_26 = F_28 ( & args , V_95 , NULL ) ;
if ( F_8 ( V_26 ) )
F_9 ( L_28 ,
V_26 ) ;
return V_53 ;
}
static void F_33 ( struct V_65 * V_51 )
{
if ( V_3 -> V_96 > 0 )
F_25 ( & V_51 -> V_51 . V_81 , & V_97 ) ;
}
static int F_34 ( struct V_65 * V_51 )
{
int V_9 ;
V_9 = F_23 ( & V_51 -> V_51 . V_81 , & V_97 ) ;
if ( V_9 )
goto V_98;
return 0 ;
V_98:
F_33 ( V_51 ) ;
return V_9 ;
}
static int T_1 F_35 ( void )
{
int V_9 ;
if ( F_36 ( V_49 ) )
V_34 = V_62 ;
else if ( F_36 ( V_39 ) )
V_34 = V_35 ;
else {
F_37 ( L_29 ) ;
return - V_99 ;
}
F_38 ( V_100 ) ;
if ( V_3 == NULL )
V_3 = & V_101 ;
V_9 = F_39 ( & V_102 ) ;
if ( V_9 )
goto V_103;
V_65 = F_40 ( L_30 , - 1 ) ;
if ( ! V_65 ) {
V_9 = - V_72 ;
goto V_104;
}
V_9 = F_41 ( V_65 ) ;
if ( V_9 )
goto V_105;
if ( V_3 -> V_96 > 0 ) {
V_9 = F_34 ( V_65 ) ;
if ( V_9 )
goto V_106;
}
V_9 = F_18 ( V_65 ) ;
if ( V_9 )
goto V_107;
return 0 ;
V_107:
F_24 ( V_65 ) ;
V_106:
F_42 ( V_65 ) ;
V_105:
F_43 ( V_65 ) ;
V_104:
F_44 ( & V_102 ) ;
V_103:
return V_9 ;
}
static void T_7 F_45 ( void )
{
if ( V_65 ) {
F_24 ( V_65 ) ;
F_33 ( V_65 ) ;
F_46 ( V_65 ) ;
F_44 ( & V_102 ) ;
}
}
