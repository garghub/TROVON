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
F_12 ( L_4 ,
V_29 -> V_38 -> V_2 , V_3 -> V_2 ,
V_41 -> string , V_41 -> V_10 ) ;
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
F_12 ( L_5 ,
V_29 -> V_38 -> V_2 , V_3 -> V_2 , V_7 -> string ) ;
} else {
F_12 ( L_6 ,
V_29 -> V_38 -> V_2 , V_3 -> V_2 , V_7 -> V_10 ) ;
}
}
V_13 = F_5 ( V_3 , V_15 ) ;
V_14 = F_5 ( V_3 , V_16 ) ;
if ( ! V_14 )
break;
F_12 ( L_7 ,
V_29 -> V_38 -> V_2 , V_3 -> V_2 , V_13 ? V_13 -> V_10 : 0 ,
V_14 -> V_10 ) ;
break;
case - V_34 :
F_11 ( V_29 , V_3 ) ;
break;
case - V_36 :
F_12 ( L_8 ,
V_29 -> V_38 -> V_2 , V_3 -> V_2 ) ;
break;
case - V_40 :
F_12 ( L_9 ,
V_29 -> V_38 -> V_2 , V_3 -> V_2 ) ;
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
int F_16 ( struct V_28 * V_29 , unsigned int V_4 , char * V_47 )
{
struct V_6 V_48 ;
int V_21 ;
if ( ! F_17 () )
return F_18 () ;
F_19 ( & V_48 , V_47 ) ;
V_21 = F_14 ( V_29 , V_4 , & V_48 ) ;
F_20 () ;
return V_21 ;
}
const struct V_1 * F_2 ( unsigned int V_4 )
{
if ( ! F_21 ( V_4 ) )
return NULL ;
return & V_49 [ V_4 ] ;
}
int F_22 ( struct V_28 * V_29 , const struct V_6 * V_50 )
{
if ( ! F_23 ( V_50 -> V_10 ) && V_29 -> V_31 . V_51 ) {
F_24 ( L_10 ,
V_29 -> V_38 -> V_2 , V_50 -> string ) ;
V_29 -> V_31 . V_51 = 0 ;
V_29 -> V_31 . V_52 = V_53 ;
F_24 ( L_11 ,
V_29 -> V_38 -> V_2 , V_29 -> V_31 . V_52 ) ;
}
V_29 -> V_31 . V_54 = V_55 ;
V_29 -> V_31 . V_32 = V_50 -> V_10 ;
return 0 ;
}
static struct V_56 * F_25 ( struct V_28 * V_29 ,
struct V_57 * V_57 )
{
return F_26 ( V_29 ) && V_57 ? V_57 -> V_38 : NULL ;
}
struct V_56 * F_27 ( struct V_28 * V_29 )
{
struct V_57 * V_57 = F_28 ( V_29 -> V_58 ) ;
return F_25 ( V_29 , V_57 ) ;
}
struct V_56 * F_29 ( struct V_28 * V_29 )
{
return F_25 ( V_29 , V_29 -> V_58 ) ;
}
static int F_30 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
char V_59 [ V_60 ] = { 0 , } ;
struct V_56 * V_61 ;
int V_21 = 0 ;
sscanf ( V_50 -> string , L_12 , V_59 ) ;
if ( ! strlen ( V_59 ) || V_50 -> string [ 0 ] == '\n' ) {
V_61 = NULL ;
} else {
V_61 = F_31 ( F_32 ( V_29 -> V_38 ) , V_59 ) ;
if ( ! V_61 )
return - V_62 ;
}
if ( V_61 ) {
if ( ! F_33 ( V_61 ) ) {
F_12 ( L_13 ,
V_61 -> V_2 ) ;
return - V_43 ;
}
if ( V_29 -> V_38 != F_34 ( V_61 ) ) {
F_12 ( L_14 ,
V_29 -> V_38 -> V_2 , V_61 -> V_2 ) ;
return - V_43 ;
}
}
F_35 () ;
F_36 ( & V_29 -> V_63 ) ;
if ( ! V_61 ) {
F_24 ( L_15 , V_29 -> V_38 -> V_2 ) ;
F_37 ( V_29 -> V_58 , NULL ) ;
F_38 ( V_29 ) ;
} else {
struct V_57 * V_64 = V_29 -> V_58 ;
struct V_57 * V_65 = F_39 ( V_61 ) ;
F_40 ( ! V_65 ) ;
if ( V_65 == V_64 ) {
F_24 ( L_16 ,
V_29 -> V_38 -> V_2 , V_65 -> V_38 -> V_2 ) ;
} else {
if ( V_64 && ( V_65 -> V_66 == V_67 ) &&
F_41 ( V_65 ) ) {
F_24 ( L_17 ,
V_29 -> V_38 -> V_2 , V_65 -> V_38 -> V_2 ) ;
F_42 ( V_29 , V_65 ) ;
} else {
F_12 ( L_18 ,
V_29 -> V_38 -> V_2 , V_65 -> V_38 -> V_2 ,
V_65 -> V_38 -> V_2 ) ;
V_21 = - V_43 ;
}
}
}
F_43 ( & V_29 -> V_63 ) ;
F_44 () ;
return V_21 ;
}
static int F_45 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_19 ,
V_29 -> V_38 -> V_2 , V_50 -> V_10 ) ;
V_29 -> V_31 . V_52 = V_50 -> V_10 ;
if ( V_29 -> V_31 . V_68 )
F_24 ( L_20 ,
V_29 -> V_38 -> V_2 ,
V_29 -> V_31 . V_68 * V_29 -> V_31 . V_52 ) ;
if ( V_29 -> V_31 . V_69 )
F_24 ( L_21 ,
V_29 -> V_38 -> V_2 ,
V_29 -> V_31 . V_69 * V_29 -> V_31 . V_52 ) ;
if ( V_50 -> V_10 && V_29 -> V_31 . V_51 ) {
F_24 ( L_22 ,
V_29 -> V_38 -> V_2 ) ;
V_29 -> V_31 . V_51 = 0 ;
if ( V_29 -> V_31 . V_54 )
V_29 -> V_31 . V_54 = V_55 ;
}
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_50 -> V_10 ) {
F_46 ( & V_29 -> V_70 ) ;
} else {
F_46 ( & V_29 -> V_71 ) ;
F_47 ( V_29 -> V_72 , & V_29 -> V_70 , 0 ) ;
}
}
return 0 ;
}
static int F_48 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
int V_10 = V_50 -> V_10 ;
if ( ! V_29 -> V_31 . V_52 ) {
F_12 ( L_23 ,
V_29 -> V_38 -> V_2 ) ;
return - V_73 ;
}
if ( ( V_10 % V_29 -> V_31 . V_52 ) != 0 ) {
F_49 ( L_24 ,
V_29 -> V_38 -> V_2 , V_10 ,
V_29 -> V_31 . V_52 ,
( V_10 / V_29 -> V_31 . V_52 ) *
V_29 -> V_31 . V_52 ) ;
}
V_29 -> V_31 . V_68 = V_10 / V_29 -> V_31 . V_52 ;
F_24 ( L_25 ,
V_29 -> V_38 -> V_2 , V_29 -> V_31 . V_68 * V_29 -> V_31 . V_52 ) ;
return 0 ;
}
static int F_50 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
int V_10 = V_50 -> V_10 ;
if ( ! V_29 -> V_31 . V_52 ) {
F_12 ( L_26 ,
V_29 -> V_38 -> V_2 ) ;
return - V_73 ;
}
if ( ( V_10 % V_29 -> V_31 . V_52 ) != 0 ) {
F_49 ( L_27 ,
V_29 -> V_38 -> V_2 , V_10 ,
V_29 -> V_31 . V_52 ,
( V_10 / V_29 -> V_31 . V_52 ) *
V_29 -> V_31 . V_52 ) ;
}
V_29 -> V_31 . V_69 = V_10 / V_29 -> V_31 . V_52 ;
F_24 ( L_28 ,
V_29 -> V_38 -> V_2 , V_29 -> V_31 . V_69 * V_29 -> V_31 . V_52 ) ;
return 0 ;
}
static int F_51 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_29 ,
V_29 -> V_38 -> V_2 , V_50 -> V_10 ) ;
V_29 -> V_31 . V_74 = V_50 -> V_10 ;
return 0 ;
}
static int F_52 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_30 ,
V_29 -> V_38 -> V_2 , V_50 -> V_10 ) ;
V_29 -> V_31 . V_51 = V_50 -> V_10 ;
if ( V_50 -> V_10 ) {
if ( V_29 -> V_31 . V_52 ) {
F_24 ( L_31 ,
V_29 -> V_38 -> V_2 , V_29 -> V_38 -> V_2 ) ;
V_29 -> V_31 . V_52 = 0 ;
}
if ( ! V_29 -> V_31 . V_75 [ 0 ] )
F_24 ( L_32 ,
V_29 -> V_38 -> V_2 ) ;
}
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_50 -> V_10 ) {
if ( V_29 -> V_31 . V_54 )
V_29 -> V_76 = NULL ;
F_46 ( & V_29 -> V_71 ) ;
} else {
V_29 -> V_76 = V_77 ;
F_46 ( & V_29 -> V_70 ) ;
F_47 ( V_29 -> V_72 , & V_29 -> V_71 , 0 ) ;
}
}
return 0 ;
}
static void F_53 ( struct V_28 * V_29 , int V_78 ,
T_3 V_79 ,
unsigned long V_80 )
{
T_3 * V_81 = V_29 -> V_31 . V_75 ;
struct V_82 * V_83 ;
struct V_57 * V_57 ;
if ( V_78 >= 0 && V_78 < V_84 ) {
F_54 (bond, slave, iter)
V_57 -> V_85 [ V_78 ] = V_80 ;
V_81 [ V_78 ] = V_79 ;
}
}
static int F_55 ( struct V_28 * V_29 , T_3 V_79 )
{
T_3 * V_81 = V_29 -> V_31 . V_75 ;
int V_86 ;
if ( ! F_56 ( V_79 ) ) {
F_12 ( L_33 ,
V_29 -> V_38 -> V_2 , & V_79 ) ;
return - V_43 ;
}
if ( F_57 ( V_81 , V_79 ) != - 1 ) {
F_12 ( L_34 ,
V_29 -> V_38 -> V_2 , & V_79 ) ;
return - V_43 ;
}
V_86 = F_57 ( V_81 , 0 ) ;
if ( V_86 == - 1 ) {
F_12 ( L_35 , V_29 -> V_38 -> V_2 ) ;
return - V_43 ;
}
F_24 ( L_36 , V_29 -> V_38 -> V_2 , & V_79 ) ;
F_53 ( V_29 , V_86 , V_79 , V_87 ) ;
return 0 ;
}
static int F_58 ( struct V_28 * V_29 , T_3 V_79 )
{
int V_21 ;
F_36 ( & V_29 -> V_88 ) ;
V_21 = F_55 ( V_29 , V_79 ) ;
F_43 ( & V_29 -> V_88 ) ;
return V_21 ;
}
static int F_59 ( struct V_28 * V_29 , T_3 V_79 )
{
T_3 * V_81 = V_29 -> V_31 . V_75 ;
struct V_82 * V_83 ;
struct V_57 * V_57 ;
unsigned long * V_89 ;
int V_86 , V_8 ;
if ( ! F_56 ( V_79 ) ) {
F_12 ( L_37 ,
V_29 -> V_38 -> V_2 , & V_79 ) ;
return - V_43 ;
}
V_86 = F_57 ( V_81 , V_79 ) ;
if ( V_86 == - 1 ) {
F_12 ( L_38 ,
V_29 -> V_38 -> V_2 , & V_79 ) ;
return - V_43 ;
}
if ( V_86 == 0 && ! V_81 [ 1 ] && V_29 -> V_31 . V_51 )
F_49 ( L_39 ,
V_29 -> V_38 -> V_2 ) ;
F_24 ( L_40 , V_29 -> V_38 -> V_2 , & V_79 ) ;
F_36 ( & V_29 -> V_88 ) ;
F_54 (bond, slave, iter) {
V_89 = V_57 -> V_85 ;
for ( V_8 = V_86 ; ( V_8 < V_84 - 1 ) && V_81 [ V_8 + 1 ] ; V_8 ++ )
V_89 [ V_8 ] = V_89 [ V_8 + 1 ] ;
V_89 [ V_8 ] = 0 ;
}
for ( V_8 = V_86 ; ( V_8 < V_84 - 1 ) && V_81 [ V_8 + 1 ] ; V_8 ++ )
V_81 [ V_8 ] = V_81 [ V_8 + 1 ] ;
V_81 [ V_8 ] = 0 ;
F_43 ( & V_29 -> V_88 ) ;
return 0 ;
}
void F_60 ( struct V_28 * V_29 )
{
int V_8 ;
F_36 ( & V_29 -> V_88 ) ;
for ( V_8 = 0 ; V_8 < V_84 ; V_8 ++ )
F_53 ( V_29 , V_8 , 0 , 0 ) ;
F_43 ( & V_29 -> V_88 ) ;
}
static int F_61 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
int V_21 = - V_73 ;
T_3 V_79 ;
if ( V_50 -> string ) {
if ( ! F_62 ( V_50 -> string + 1 , - 1 , ( V_90 * ) & V_79 , - 1 , NULL ) ) {
F_12 ( L_41 ,
V_29 -> V_38 -> V_2 , & V_79 ) ;
return V_21 ;
}
if ( V_50 -> string [ 0 ] == '+' )
V_21 = F_58 ( V_29 , V_79 ) ;
else if ( V_50 -> string [ 0 ] == '-' )
V_21 = F_59 ( V_29 , V_79 ) ;
else
F_12 ( L_42 ,
V_29 -> V_38 -> V_2 ) ;
} else {
V_79 = V_50 -> V_10 ;
V_21 = F_58 ( V_29 , V_79 ) ;
}
return V_21 ;
}
static int F_63 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_43 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_50 -> V_10 )
V_29 -> V_76 = NULL ;
else if ( V_29 -> V_31 . V_51 )
V_29 -> V_76 = V_77 ;
}
V_29 -> V_31 . V_54 = V_50 -> V_10 ;
return 0 ;
}
static int F_64 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_44 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
V_29 -> V_31 . V_91 = V_50 -> V_10 ;
return 0 ;
}
static int F_65 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
char * V_17 , * V_92 = V_50 -> string ;
struct V_82 * V_83 ;
struct V_57 * V_57 ;
F_35 () ;
F_66 ( & V_29 -> V_88 ) ;
F_36 ( & V_29 -> V_63 ) ;
V_17 = strchr ( V_92 , '\n' ) ;
if ( V_17 )
* V_17 = '\0' ;
if ( ! strlen ( V_92 ) ) {
F_24 ( L_45 , V_29 -> V_38 -> V_2 ) ;
V_29 -> V_93 = NULL ;
memset ( V_29 -> V_31 . V_92 , 0 , sizeof( V_29 -> V_31 . V_92 ) ) ;
F_38 ( V_29 ) ;
goto V_25;
}
F_54 (bond, slave, iter) {
if ( strncmp ( V_57 -> V_38 -> V_2 , V_92 , V_60 ) == 0 ) {
F_24 ( L_46 ,
V_29 -> V_38 -> V_2 , V_57 -> V_38 -> V_2 ) ;
V_29 -> V_93 = V_57 ;
strcpy ( V_29 -> V_31 . V_92 , V_57 -> V_38 -> V_2 ) ;
F_38 ( V_29 ) ;
goto V_25;
}
}
if ( V_29 -> V_93 ) {
F_24 ( L_45 , V_29 -> V_38 -> V_2 ) ;
V_29 -> V_93 = NULL ;
F_38 ( V_29 ) ;
}
strncpy ( V_29 -> V_31 . V_92 , V_92 , V_60 ) ;
V_29 -> V_31 . V_92 [ V_60 - 1 ] = 0 ;
F_24 ( L_47 ,
V_29 -> V_38 -> V_2 , V_92 , V_29 -> V_38 -> V_2 ) ;
V_25:
F_43 ( & V_29 -> V_63 ) ;
F_67 ( & V_29 -> V_88 ) ;
F_44 () ;
return 0 ;
}
static int F_68 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_48 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
V_29 -> V_31 . V_94 = V_50 -> V_10 ;
F_35 () ;
F_36 ( & V_29 -> V_63 ) ;
F_38 ( V_29 ) ;
F_43 ( & V_29 -> V_63 ) ;
F_44 () ;
return 0 ;
}
static int F_69 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_49 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
V_29 -> V_31 . V_95 = V_50 -> V_10 ;
return 0 ;
}
static int F_70 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_50 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
V_29 -> V_31 . V_96 = V_50 -> V_10 ;
return 0 ;
}
static int F_71 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_51 ,
V_29 -> V_38 -> V_2 , V_50 -> V_10 ) ;
V_29 -> V_31 . V_97 = V_50 -> V_10 ;
return 0 ;
}
static int F_72 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
V_29 -> V_31 . V_98 = V_50 -> V_10 ;
return 0 ;
}
static int F_73 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
struct V_82 * V_83 ;
struct V_57 * V_57 ;
if ( V_50 -> V_10 == V_29 -> V_31 . V_99 )
return 0 ;
V_29 -> V_31 . V_99 = V_50 -> V_10 ;
F_54 (bond, slave, iter) {
if ( ! F_74 ( V_57 ) ) {
if ( V_50 -> V_10 )
V_57 -> V_100 = 0 ;
else
V_57 -> V_100 = 1 ;
}
}
return 0 ;
}
static int F_75 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_52 ,
V_29 -> V_38 -> V_2 , V_50 -> V_10 ) ;
V_29 -> V_31 . V_101 = V_50 -> V_10 ;
return 0 ;
}
static int F_76 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
V_29 -> V_31 . V_102 = V_50 -> V_10 ;
return 0 ;
}
static int F_77 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
V_29 -> V_31 . V_103 = V_50 -> V_10 ;
if ( V_50 -> V_10 > 0 ) {
V_29 -> V_31 . V_104 =
F_78 ( V_50 -> V_10 ) ;
} else {
V_29 -> V_31 . V_104 =
(struct F_78 ) { 0 } ;
}
return 0 ;
}
static int F_79 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_53 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
V_29 -> V_31 . V_105 = V_50 -> V_10 ;
F_80 ( V_29 ) ;
return 0 ;
}
static int F_81 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_54 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
V_29 -> V_31 . V_106 = V_50 -> V_10 ;
return 0 ;
}
static int F_82 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
struct V_57 * V_57 , * V_107 ;
struct V_56 * V_108 ;
struct V_82 * V_83 ;
char * V_109 ;
int V_21 = 0 ;
T_4 V_110 ;
V_109 = strchr ( V_50 -> string , ':' ) ;
if ( ! V_109 )
goto V_111;
* V_109 = '\0' ;
if ( sscanf ( ++ V_109 , L_55 , & V_110 ) != 1 )
goto V_111;
if ( ! F_83 ( V_50 -> string ) ||
V_110 > V_29 -> V_38 -> V_112 )
goto V_111;
V_108 = F_31 ( F_32 ( V_29 -> V_38 ) , V_50 -> string ) ;
if ( ! V_108 )
goto V_111;
V_107 = NULL ;
F_54 (bond, slave, iter) {
if ( V_108 == V_57 -> V_38 )
V_107 = V_57 ;
else if ( V_110 && V_110 == V_57 -> V_113 ) {
goto V_111;
}
}
if ( ! V_107 )
goto V_111;
V_107 -> V_113 = V_110 ;
V_25:
return V_21 ;
V_111:
F_24 ( L_56 , V_29 -> V_38 -> V_2 ) ;
V_21 = - V_73 ;
goto V_25;
}
static int F_84 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
char V_114 [ V_60 + 1 ] = { 0 , } ;
struct V_56 * V_38 ;
char * V_59 ;
int V_21 ;
sscanf ( V_50 -> string , L_57 , V_114 ) ;
V_59 = V_114 + 1 ;
if ( ( strlen ( V_114 ) <= 1 ) ||
! F_83 ( V_59 ) )
goto V_111;
V_38 = F_31 ( F_32 ( V_29 -> V_38 ) , V_59 ) ;
if ( ! V_38 ) {
F_24 ( L_58 ,
V_29 -> V_38 -> V_2 , V_59 ) ;
V_21 = - V_62 ;
goto V_25;
}
switch ( V_114 [ 0 ] ) {
case '+' :
F_24 ( L_59 , V_29 -> V_38 -> V_2 , V_38 -> V_2 ) ;
V_21 = F_85 ( V_29 -> V_38 , V_38 ) ;
break;
case '-' :
F_24 ( L_60 , V_29 -> V_38 -> V_2 , V_38 -> V_2 ) ;
V_21 = F_86 ( V_29 -> V_38 , V_38 ) ;
break;
default:
goto V_111;
}
V_25:
return V_21 ;
V_111:
F_12 ( L_61 ,
V_29 -> V_38 -> V_2 ) ;
V_21 = - V_73 ;
goto V_25;
}
static int F_87 ( struct V_28 * V_29 ,
const struct V_6 * V_50 )
{
F_24 ( L_62 ,
V_29 -> V_38 -> V_2 , V_50 -> string , V_50 -> V_10 ) ;
V_29 -> V_31 . V_115 = V_50 -> V_10 ;
return 0 ;
}
