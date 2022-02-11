const struct V_1 * F_1 ( const char * V_2 )
{
const struct V_1 * V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_3 = F_2 ( V_4 ) ;
if ( V_3 && ! strcmp ( V_3 -> V_2 , V_2 ) )
return V_3 ;
}
return NULL ;
}
const struct V_6 * F_3 ( unsigned int V_4 , T_1 V_7 )
{
const struct V_1 * V_3 ;
int V_8 ;
V_3 = F_2 ( V_4 ) ;
if ( F_4 ( ! V_3 ) )
return NULL ;
for ( V_8 = 0 ; V_3 -> V_9 && V_3 -> V_9 [ V_8 ] . string ; V_8 ++ )
if ( V_3 -> V_9 [ V_8 ] . V_10 == V_7 )
return & V_3 -> V_9 [ V_8 ] ;
return NULL ;
}
static const struct V_6 * F_5 ( const struct V_1 * V_3 ,
T_2 V_11 )
{
int V_8 ;
for ( V_8 = 0 ; V_3 -> V_9 && V_3 -> V_9 [ V_8 ] . string ; V_8 ++ )
if ( V_3 -> V_9 [ V_8 ] . V_12 & V_11 )
return & V_3 -> V_9 [ V_8 ] ;
return NULL ;
}
static bool F_6 ( const struct V_1 * V_3 , T_1 V_7 )
{
const struct V_6 * V_13 , * V_14 ;
V_13 = F_5 ( V_3 , V_15 ) ;
V_14 = F_5 ( V_3 , V_16 ) ;
if ( ! V_14 || ( V_13 && V_7 < V_13 -> V_10 ) || V_7 > V_14 -> V_10 )
return false ;
return true ;
}
const struct V_6 * F_7 ( const struct V_1 * V_3 ,
struct V_6 * V_7 )
{
char * V_17 , V_18 [ V_19 + 1 ] = { 0 , } ;
const struct V_6 * V_20 ;
const struct V_6 * V_21 = NULL ;
bool V_22 ;
int V_8 , V_23 ;
if ( V_3 -> V_12 & V_24 )
return V_7 ;
V_20 = V_3 -> V_9 ;
if ( ! V_20 )
goto V_25;
V_22 = V_7 -> V_10 != V_26 ;
if ( ! V_22 ) {
if ( ! V_7 -> string )
goto V_25;
V_17 = strchr ( V_7 -> string , '\n' ) ;
if ( V_17 )
* V_17 = '\0' ;
for ( V_17 = V_7 -> string ; * V_17 ; V_17 ++ )
if ( ! ( isdigit ( * V_17 ) || isspace ( * V_17 ) ) )
break;
if ( * V_17 ) {
V_23 = sscanf ( V_7 -> string , L_1 , V_18 ) ;
} else {
V_23 = sscanf ( V_7 -> string , L_2 , & V_7 -> V_10 ) ;
V_22 = true ;
}
if ( ! V_23 )
goto V_25;
}
for ( V_8 = 0 ; V_20 [ V_8 ] . string ; V_8 ++ ) {
if ( V_22 ) {
if ( V_7 -> V_10 == V_20 [ V_8 ] . V_10 )
V_21 = & V_20 [ V_8 ] ;
} else {
if ( ! strcmp ( V_18 , L_3 ) &&
( V_20 [ V_8 ] . V_12 & V_27 ) )
V_21 = & V_20 [ V_8 ] ;
if ( ! strcmp ( V_18 , V_20 [ V_8 ] . string ) )
V_21 = & V_20 [ V_8 ] ;
}
if ( V_21 )
goto V_25;
}
if ( V_22 && F_6 ( V_3 , V_7 -> V_10 ) )
V_21 = V_7 ;
V_25:
return V_21 ;
}
static int F_8 ( struct V_28 * V_29 ,
const struct V_1 * V_3 )
{
struct V_30 * V_31 = & V_29 -> V_31 ;
if ( F_9 ( V_31 -> V_32 , & V_3 -> V_33 ) )
return - V_34 ;
if ( ( V_3 -> V_12 & V_35 ) && F_10 ( V_29 ) )
return - V_36 ;
if ( ( V_3 -> V_12 & V_37 ) && ( V_29 -> V_38 -> V_12 & V_39 ) )
return - V_40 ;
return 0 ;
}
static void F_11 ( struct V_28 * V_29 ,
const struct V_1 * V_3 )
{
const struct V_6 * V_41 ;
struct V_30 * V_31 ;
V_31 = & V_29 -> V_31 ;
V_41 = F_3 ( V_42 , V_31 -> V_32 ) ;
if ( F_9 ( V_31 -> V_32 , & V_3 -> V_33 ) )
F_12 ( V_29 -> V_38 , L_4 ,
V_3 -> V_2 , V_41 -> string , V_41 -> V_10 ) ;
}
static void F_13 ( struct V_28 * V_29 ,
const struct V_1 * V_3 ,
int error , const struct V_6 * V_7 )
{
const struct V_6 * V_13 , * V_14 ;
char * V_17 ;
switch ( error ) {
case - V_43 :
if ( V_7 ) {
if ( V_7 -> string ) {
V_17 = strchr ( V_7 -> string , '\n' ) ;
if ( V_17 )
* V_17 = '\0' ;
F_12 ( V_29 -> V_38 , L_5 ,
V_3 -> V_2 , V_7 -> string ) ;
} else {
F_12 ( V_29 -> V_38 , L_6 ,
V_3 -> V_2 , V_7 -> V_10 ) ;
}
}
V_13 = F_5 ( V_3 , V_15 ) ;
V_14 = F_5 ( V_3 , V_16 ) ;
if ( ! V_14 )
break;
F_12 ( V_29 -> V_38 , L_7 ,
V_3 -> V_2 , V_13 ? V_13 -> V_10 : 0 , V_14 -> V_10 ) ;
break;
case - V_34 :
F_11 ( V_29 , V_3 ) ;
break;
case - V_36 :
F_12 ( V_29 -> V_38 , L_8 ,
V_3 -> V_2 ) ;
break;
case - V_40 :
F_12 ( V_29 -> V_38 , L_9 ,
V_3 -> V_2 ) ;
break;
default:
break;
}
}
int F_14 ( struct V_28 * V_29 ,
unsigned int V_4 , struct V_6 * V_7 )
{
const struct V_6 * V_44 = NULL ;
const struct V_1 * V_3 ;
int V_21 = - V_45 ;
F_15 () ;
V_3 = F_2 ( V_4 ) ;
if ( F_4 ( ! V_7 ) || F_4 ( ! V_3 ) )
goto V_25;
V_21 = F_8 ( V_29 , V_3 ) ;
if ( V_21 )
goto V_25;
V_44 = F_7 ( V_3 , V_7 ) ;
if ( ! V_44 ) {
V_21 = - V_43 ;
goto V_25;
}
V_21 = V_3 -> V_46 ( V_29 , V_44 ) ;
V_25:
if ( V_21 )
F_13 ( V_29 , V_3 , V_21 , V_7 ) ;
return V_21 ;
}
int F_16 ( struct V_28 * V_29 ,
unsigned int V_4 , struct V_6 * V_7 )
{
int V_21 = - V_45 ;
F_15 () ;
V_21 = F_14 ( V_29 , V_4 , V_7 ) ;
if ( ! V_21 && ( V_29 -> V_38 -> V_47 == V_48 ) )
F_17 ( V_49 , V_29 -> V_38 ) ;
return V_21 ;
}
int F_18 ( struct V_28 * V_29 , unsigned int V_4 , char * V_50 )
{
struct V_6 V_51 ;
int V_21 ;
if ( ! F_19 () )
return F_20 () ;
F_21 ( & V_51 , V_50 ) ;
V_21 = F_16 ( V_29 , V_4 , & V_51 ) ;
F_22 () ;
return V_21 ;
}
const struct V_1 * F_2 ( unsigned int V_4 )
{
if ( ! F_23 ( V_4 ) )
return NULL ;
return & V_52 [ V_4 ] ;
}
static int F_24 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
if ( ! F_25 ( V_53 -> V_10 ) && V_29 -> V_31 . V_54 ) {
F_26 ( V_29 -> V_38 , L_10 ,
V_53 -> string ) ;
V_29 -> V_31 . V_54 = 0 ;
V_29 -> V_31 . V_55 = V_56 ;
F_26 ( V_29 -> V_38 , L_11 ,
V_29 -> V_31 . V_55 ) ;
}
if ( V_53 -> V_10 == V_57 )
V_29 -> V_31 . V_58 = 1 ;
V_29 -> V_31 . V_59 = V_60 ;
V_29 -> V_31 . V_32 = V_53 -> V_10 ;
return 0 ;
}
static int F_27 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
char V_61 [ V_62 ] = { 0 , } ;
struct V_63 * V_64 ;
int V_21 = 0 ;
sscanf ( V_53 -> string , L_12 , V_61 ) ;
if ( ! strlen ( V_61 ) || V_53 -> string [ 0 ] == '\n' ) {
V_64 = NULL ;
} else {
V_64 = F_28 ( F_29 ( V_29 -> V_38 ) , V_61 ) ;
if ( ! V_64 )
return - V_65 ;
}
if ( V_64 ) {
if ( ! F_30 ( V_64 ) ) {
F_12 ( V_29 -> V_38 , L_13 ,
V_64 -> V_2 ) ;
return - V_43 ;
}
if ( V_29 -> V_38 != F_31 ( V_64 ) ) {
F_12 ( V_29 -> V_38 , L_14 ,
V_64 -> V_2 ) ;
return - V_43 ;
}
}
F_32 () ;
if ( ! V_64 ) {
F_26 ( V_29 -> V_38 , L_15 ) ;
F_33 ( V_29 -> V_66 , NULL ) ;
F_34 ( V_29 ) ;
} else {
struct V_67 * V_68 = F_35 ( V_29 -> V_66 ) ;
struct V_67 * V_69 = F_36 ( V_64 ) ;
F_37 ( ! V_69 ) ;
if ( V_69 == V_68 ) {
F_26 ( V_29 -> V_38 , L_16 ,
V_69 -> V_38 -> V_2 ) ;
} else {
if ( V_68 && ( V_69 -> V_70 == V_71 ) &&
F_38 ( V_69 ) ) {
F_26 ( V_29 -> V_38 , L_17 ,
V_69 -> V_38 -> V_2 ) ;
F_39 ( V_29 , V_69 ) ;
} else {
F_12 ( V_29 -> V_38 , L_18 ,
V_69 -> V_38 -> V_2 ,
V_69 -> V_38 -> V_2 ) ;
V_21 = - V_43 ;
}
}
}
F_40 () ;
return V_21 ;
}
static int F_41 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_19 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_55 = V_53 -> V_10 ;
if ( V_29 -> V_31 . V_72 )
F_26 ( V_29 -> V_38 , L_20 ,
V_29 -> V_31 . V_72 * V_29 -> V_31 . V_55 ) ;
if ( V_29 -> V_31 . V_73 )
F_26 ( V_29 -> V_38 , L_21 ,
V_29 -> V_31 . V_73 * V_29 -> V_31 . V_55 ) ;
if ( V_53 -> V_10 && V_29 -> V_31 . V_54 ) {
F_26 ( V_29 -> V_38 , L_22 ) ;
V_29 -> V_31 . V_54 = 0 ;
if ( V_29 -> V_31 . V_59 )
V_29 -> V_31 . V_59 = V_60 ;
}
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_53 -> V_10 ) {
F_42 ( & V_29 -> V_74 ) ;
} else {
F_42 ( & V_29 -> V_75 ) ;
F_43 ( V_29 -> V_76 , & V_29 -> V_74 , 0 ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
int V_10 = V_53 -> V_10 ;
if ( ! V_29 -> V_31 . V_55 ) {
F_12 ( V_29 -> V_38 , L_23 ) ;
return - V_77 ;
}
if ( ( V_10 % V_29 -> V_31 . V_55 ) != 0 ) {
F_45 ( V_29 -> V_38 , L_24 ,
V_10 , V_29 -> V_31 . V_55 ,
( V_10 / V_29 -> V_31 . V_55 ) *
V_29 -> V_31 . V_55 ) ;
}
V_29 -> V_31 . V_72 = V_10 / V_29 -> V_31 . V_55 ;
F_26 ( V_29 -> V_38 , L_25 ,
V_29 -> V_31 . V_72 * V_29 -> V_31 . V_55 ) ;
return 0 ;
}
static int F_46 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
int V_10 = V_53 -> V_10 ;
if ( ! V_29 -> V_31 . V_55 ) {
F_12 ( V_29 -> V_38 , L_26 ) ;
return - V_77 ;
}
if ( ( V_10 % V_29 -> V_31 . V_55 ) != 0 ) {
F_45 ( V_29 -> V_38 , L_27 ,
V_10 , V_29 -> V_31 . V_55 ,
( V_10 / V_29 -> V_31 . V_55 ) *
V_29 -> V_31 . V_55 ) ;
}
V_29 -> V_31 . V_73 = V_10 / V_29 -> V_31 . V_55 ;
F_26 ( V_29 -> V_38 , L_28 ,
V_29 -> V_31 . V_73 * V_29 -> V_31 . V_55 ) ;
return 0 ;
}
static int F_47 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_29 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_78 = V_53 -> V_10 ;
return 0 ;
}
static int F_48 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_30 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_54 = V_53 -> V_10 ;
if ( V_53 -> V_10 ) {
if ( V_29 -> V_31 . V_55 ) {
F_26 ( V_29 -> V_38 , L_31 ) ;
V_29 -> V_31 . V_55 = 0 ;
}
if ( ! V_29 -> V_31 . V_79 [ 0 ] )
F_26 ( V_29 -> V_38 , L_32 ) ;
}
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_53 -> V_10 ) {
if ( V_29 -> V_31 . V_59 )
V_29 -> V_80 = NULL ;
F_42 ( & V_29 -> V_75 ) ;
} else {
V_29 -> V_80 = V_81 ;
F_42 ( & V_29 -> V_74 ) ;
F_43 ( V_29 -> V_76 , & V_29 -> V_75 , 0 ) ;
}
}
return 0 ;
}
static void F_49 ( struct V_28 * V_29 , int V_82 ,
T_3 V_83 ,
unsigned long V_84 )
{
T_3 * V_85 = V_29 -> V_31 . V_79 ;
struct V_86 * V_87 ;
struct V_67 * V_67 ;
if ( V_82 >= 0 && V_82 < V_88 ) {
F_50 (bond, slave, iter)
V_67 -> V_89 [ V_82 ] = V_84 ;
V_85 [ V_82 ] = V_83 ;
}
}
static int F_51 ( struct V_28 * V_29 , T_3 V_83 )
{
T_3 * V_85 = V_29 -> V_31 . V_79 ;
int V_90 ;
if ( ! F_52 ( V_83 ) ) {
F_12 ( V_29 -> V_38 , L_33 ,
& V_83 ) ;
return - V_43 ;
}
if ( F_53 ( V_85 , V_83 ) != - 1 ) {
F_12 ( V_29 -> V_38 , L_34 ,
& V_83 ) ;
return - V_43 ;
}
V_90 = F_53 ( V_85 , 0 ) ;
if ( V_90 == - 1 ) {
F_12 ( V_29 -> V_38 , L_35 ) ;
return - V_43 ;
}
F_26 ( V_29 -> V_38 , L_36 , & V_83 ) ;
F_49 ( V_29 , V_90 , V_83 , V_91 ) ;
return 0 ;
}
static int F_54 ( struct V_28 * V_29 , T_3 V_83 )
{
return F_51 ( V_29 , V_83 ) ;
}
static int F_55 ( struct V_28 * V_29 , T_3 V_83 )
{
T_3 * V_85 = V_29 -> V_31 . V_79 ;
struct V_86 * V_87 ;
struct V_67 * V_67 ;
unsigned long * V_92 ;
int V_90 , V_8 ;
if ( ! F_52 ( V_83 ) ) {
F_12 ( V_29 -> V_38 , L_37 ,
& V_83 ) ;
return - V_43 ;
}
V_90 = F_53 ( V_85 , V_83 ) ;
if ( V_90 == - 1 ) {
F_12 ( V_29 -> V_38 , L_38 ,
& V_83 ) ;
return - V_43 ;
}
if ( V_90 == 0 && ! V_85 [ 1 ] && V_29 -> V_31 . V_54 )
F_45 ( V_29 -> V_38 , L_39 ) ;
F_26 ( V_29 -> V_38 , L_40 , & V_83 ) ;
F_50 (bond, slave, iter) {
V_92 = V_67 -> V_89 ;
for ( V_8 = V_90 ; ( V_8 < V_88 - 1 ) && V_85 [ V_8 + 1 ] ; V_8 ++ )
V_92 [ V_8 ] = V_92 [ V_8 + 1 ] ;
V_92 [ V_8 ] = 0 ;
}
for ( V_8 = V_90 ; ( V_8 < V_88 - 1 ) && V_85 [ V_8 + 1 ] ; V_8 ++ )
V_85 [ V_8 ] = V_85 [ V_8 + 1 ] ;
V_85 [ V_8 ] = 0 ;
return 0 ;
}
void F_56 ( struct V_28 * V_29 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_88 ; V_8 ++ )
F_49 ( V_29 , V_8 , 0 , 0 ) ;
}
static int F_57 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
int V_21 = - V_77 ;
T_3 V_83 ;
if ( V_53 -> string ) {
if ( ! F_58 ( V_53 -> string + 1 , - 1 , ( V_93 * ) & V_83 , - 1 , NULL ) ) {
F_12 ( V_29 -> V_38 , L_41 ,
& V_83 ) ;
return V_21 ;
}
if ( V_53 -> string [ 0 ] == '+' )
V_21 = F_54 ( V_29 , V_83 ) ;
else if ( V_53 -> string [ 0 ] == '-' )
V_21 = F_55 ( V_29 , V_83 ) ;
else
F_12 ( V_29 -> V_38 , L_42 ) ;
} else {
V_83 = V_53 -> V_10 ;
V_21 = F_54 ( V_29 , V_83 ) ;
}
return V_21 ;
}
static int F_59 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_43 ,
V_53 -> string , V_53 -> V_10 ) ;
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_53 -> V_10 )
V_29 -> V_80 = NULL ;
else if ( V_29 -> V_31 . V_54 )
V_29 -> V_80 = V_81 ;
}
V_29 -> V_31 . V_59 = V_53 -> V_10 ;
return 0 ;
}
static int F_60 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_44 ,
V_53 -> string , V_53 -> V_10 ) ;
V_29 -> V_31 . V_94 = V_53 -> V_10 ;
return 0 ;
}
static int F_61 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
char * V_17 , * V_95 = V_53 -> string ;
struct V_86 * V_87 ;
struct V_67 * V_67 ;
F_32 () ;
V_17 = strchr ( V_95 , '\n' ) ;
if ( V_17 )
* V_17 = '\0' ;
if ( ! strlen ( V_95 ) ) {
F_26 ( V_29 -> V_38 , L_45 ) ;
F_33 ( V_29 -> V_96 , NULL ) ;
memset ( V_29 -> V_31 . V_95 , 0 , sizeof( V_29 -> V_31 . V_95 ) ) ;
F_34 ( V_29 ) ;
goto V_25;
}
F_50 (bond, slave, iter) {
if ( strncmp ( V_67 -> V_38 -> V_2 , V_95 , V_62 ) == 0 ) {
F_26 ( V_29 -> V_38 , L_46 ,
V_67 -> V_38 -> V_2 ) ;
F_62 ( V_29 -> V_96 , V_67 ) ;
strcpy ( V_29 -> V_31 . V_95 , V_67 -> V_38 -> V_2 ) ;
F_34 ( V_29 ) ;
goto V_25;
}
}
if ( F_35 ( V_29 -> V_96 ) ) {
F_26 ( V_29 -> V_38 , L_45 ) ;
F_33 ( V_29 -> V_96 , NULL ) ;
F_34 ( V_29 ) ;
}
strncpy ( V_29 -> V_31 . V_95 , V_95 , V_62 ) ;
V_29 -> V_31 . V_95 [ V_62 - 1 ] = 0 ;
F_26 ( V_29 -> V_38 , L_47 ,
V_95 , V_29 -> V_38 -> V_2 ) ;
V_25:
F_40 () ;
return 0 ;
}
static int F_63 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_48 ,
V_53 -> string , V_53 -> V_10 ) ;
V_29 -> V_31 . V_97 = V_53 -> V_10 ;
F_32 () ;
F_34 ( V_29 ) ;
F_40 () ;
return 0 ;
}
static int F_64 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_49 ,
V_53 -> string , V_53 -> V_10 ) ;
V_29 -> V_31 . V_98 = V_53 -> V_10 ;
return 0 ;
}
static int F_65 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_50 ,
V_53 -> string , V_53 -> V_10 ) ;
V_29 -> V_31 . V_99 = V_53 -> V_10 ;
return 0 ;
}
static int F_66 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_51 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_100 = V_53 -> V_10 ;
return 0 ;
}
static int F_67 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
V_29 -> V_31 . V_101 = V_53 -> V_10 ;
return 0 ;
}
static int F_68 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
struct V_86 * V_87 ;
struct V_67 * V_67 ;
if ( V_53 -> V_10 == V_29 -> V_31 . V_102 )
return 0 ;
V_29 -> V_31 . V_102 = V_53 -> V_10 ;
F_50 (bond, slave, iter) {
if ( ! F_69 ( V_67 ) ) {
if ( V_53 -> V_10 )
V_67 -> V_103 = 0 ;
else
V_67 -> V_103 = 1 ;
}
}
return 0 ;
}
static int F_70 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_52 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_104 = V_53 -> V_10 ;
F_71 ( V_29 ) ;
return 0 ;
}
static int F_72 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
V_29 -> V_31 . V_105 = V_53 -> V_10 ;
return 0 ;
}
static int F_73 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_53 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_106 = V_53 -> V_10 ;
if ( V_53 -> V_10 > 0 ) {
V_29 -> V_31 . V_107 =
F_74 ( V_53 -> V_10 ) ;
} else {
V_29 -> V_31 . V_107 =
(struct F_74 ) { 0 } ;
}
return 0 ;
}
static int F_75 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_54 ,
V_53 -> string , V_53 -> V_10 ) ;
V_29 -> V_31 . V_108 = V_53 -> V_10 ;
F_76 ( V_29 ) ;
return 0 ;
}
static int F_77 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_55 ,
V_53 -> string , V_53 -> V_10 ) ;
V_29 -> V_31 . V_109 = V_53 -> V_10 ;
return 0 ;
}
static int F_78 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
struct V_67 * V_67 , * V_110 ;
struct V_63 * V_111 ;
struct V_86 * V_87 ;
char * V_112 ;
int V_21 = 0 ;
T_4 V_113 ;
V_112 = strchr ( V_53 -> string , ':' ) ;
if ( ! V_112 )
goto V_114;
* V_112 = '\0' ;
if ( sscanf ( ++ V_112 , L_56 , & V_113 ) != 1 )
goto V_114;
if ( ! F_79 ( V_53 -> string ) ||
V_113 > V_29 -> V_38 -> V_115 )
goto V_114;
V_111 = F_28 ( F_29 ( V_29 -> V_38 ) , V_53 -> string ) ;
if ( ! V_111 )
goto V_114;
V_110 = NULL ;
F_50 (bond, slave, iter) {
if ( V_111 == V_67 -> V_38 )
V_110 = V_67 ;
else if ( V_113 && V_113 == V_67 -> V_116 ) {
goto V_114;
}
}
if ( ! V_110 )
goto V_114;
V_110 -> V_116 = V_113 ;
V_25:
return V_21 ;
V_114:
F_26 ( V_29 -> V_38 , L_57 ) ;
V_21 = - V_77 ;
goto V_25;
}
static int F_80 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
char V_117 [ V_62 + 1 ] = { 0 , } ;
struct V_63 * V_38 ;
char * V_61 ;
int V_21 ;
sscanf ( V_53 -> string , L_58 , V_117 ) ;
V_61 = V_117 + 1 ;
if ( ( strlen ( V_117 ) <= 1 ) ||
! F_79 ( V_61 ) )
goto V_114;
V_38 = F_28 ( F_29 ( V_29 -> V_38 ) , V_61 ) ;
if ( ! V_38 ) {
F_26 ( V_29 -> V_38 , L_59 ,
V_61 ) ;
V_21 = - V_65 ;
goto V_25;
}
switch ( V_117 [ 0 ] ) {
case '+' :
F_26 ( V_29 -> V_38 , L_60 , V_38 -> V_2 ) ;
V_21 = F_81 ( V_29 -> V_38 , V_38 ) ;
break;
case '-' :
F_26 ( V_29 -> V_38 , L_61 , V_38 -> V_2 ) ;
V_21 = F_82 ( V_29 -> V_38 , V_38 ) ;
break;
default:
goto V_114;
}
V_25:
return V_21 ;
V_114:
F_12 ( V_29 -> V_38 , L_62 ) ;
V_21 = - V_77 ;
goto V_25;
}
static int F_83 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_63 ,
V_53 -> string , V_53 -> V_10 ) ;
V_29 -> V_31 . V_58 = V_53 -> V_10 ;
return 0 ;
}
static int F_84 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_64 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_118 = V_53 -> V_10 ;
F_85 ( V_29 ) ;
return 0 ;
}
static int F_86 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
V_93 V_119 [ V_120 ] ;
V_93 * V_121 ;
int V_8 ;
if ( V_53 -> string ) {
V_8 = sscanf ( V_53 -> string , L_65 ,
& V_119 [ 0 ] , & V_119 [ 1 ] , & V_119 [ 2 ] ,
& V_119 [ 3 ] , & V_119 [ 4 ] , & V_119 [ 5 ] ) ;
if ( V_8 != V_120 )
goto V_122;
V_121 = V_119 ;
} else {
V_121 = ( V_93 * ) & V_53 -> V_10 ;
}
if ( ! F_87 ( V_121 ) )
goto V_122;
F_26 ( V_29 -> V_38 , L_66 , V_121 ) ;
F_88 ( V_29 -> V_31 . V_123 , V_121 ) ;
F_85 ( V_29 ) ;
return 0 ;
V_122:
F_12 ( V_29 -> V_38 , L_67 ) ;
return - V_43 ;
}
static int F_89 ( struct V_28 * V_29 ,
const struct V_6 * V_53 )
{
F_26 ( V_29 -> V_38 , L_68 ,
V_53 -> V_10 ) ;
V_29 -> V_31 . V_124 = V_53 -> V_10 ;
return 0 ;
}
