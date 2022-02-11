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
else
F_16 ( V_47 , V_29 -> V_38 ) ;
return V_21 ;
}
int F_17 ( struct V_28 * V_29 , unsigned int V_4 , char * V_48 )
{
struct V_6 V_49 ;
int V_21 ;
if ( ! F_18 () )
return F_19 () ;
F_20 ( & V_49 , V_48 ) ;
V_21 = F_14 ( V_29 , V_4 , & V_49 ) ;
F_21 () ;
return V_21 ;
}
const struct V_1 * F_2 ( unsigned int V_4 )
{
if ( ! F_22 ( V_4 ) )
return NULL ;
return & V_50 [ V_4 ] ;
}
static int F_23 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
if ( ! F_24 ( V_51 -> V_10 ) && V_29 -> V_31 . V_52 ) {
F_25 ( V_29 -> V_38 , L_10 ,
V_51 -> string ) ;
V_29 -> V_31 . V_52 = 0 ;
V_29 -> V_31 . V_53 = V_54 ;
F_25 ( V_29 -> V_38 , L_11 ,
V_29 -> V_31 . V_53 ) ;
}
V_29 -> V_31 . V_55 = V_56 ;
V_29 -> V_31 . V_32 = V_51 -> V_10 ;
return 0 ;
}
static struct V_57 * F_26 ( struct V_28 * V_29 ,
struct V_58 * V_58 )
{
return F_27 ( V_29 ) && V_58 ? V_58 -> V_38 : NULL ;
}
struct V_57 * F_28 ( struct V_28 * V_29 )
{
struct V_58 * V_58 = F_29 ( V_29 -> V_59 ) ;
return F_26 ( V_29 , V_58 ) ;
}
static int F_30 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
char V_60 [ V_61 ] = { 0 , } ;
struct V_57 * V_62 ;
int V_21 = 0 ;
sscanf ( V_51 -> string , L_12 , V_60 ) ;
if ( ! strlen ( V_60 ) || V_51 -> string [ 0 ] == '\n' ) {
V_62 = NULL ;
} else {
V_62 = F_31 ( F_32 ( V_29 -> V_38 ) , V_60 ) ;
if ( ! V_62 )
return - V_63 ;
}
if ( V_62 ) {
if ( ! F_33 ( V_62 ) ) {
F_12 ( V_29 -> V_38 , L_13 ,
V_62 -> V_2 ) ;
return - V_43 ;
}
if ( V_29 -> V_38 != F_34 ( V_62 ) ) {
F_12 ( V_29 -> V_38 , L_14 ,
V_62 -> V_2 ) ;
return - V_43 ;
}
}
F_35 () ;
if ( ! V_62 ) {
F_25 ( V_29 -> V_38 , L_15 ) ;
F_36 ( V_29 -> V_59 , NULL ) ;
F_37 ( V_29 ) ;
} else {
struct V_58 * V_64 = F_38 ( V_29 -> V_59 ) ;
struct V_58 * V_65 = F_39 ( V_62 ) ;
F_40 ( ! V_65 ) ;
if ( V_65 == V_64 ) {
F_25 ( V_29 -> V_38 , L_16 ,
V_65 -> V_38 -> V_2 ) ;
} else {
if ( V_64 && ( V_65 -> V_66 == V_67 ) &&
F_41 ( V_65 ) ) {
F_25 ( V_29 -> V_38 , L_17 ,
V_65 -> V_38 -> V_2 ) ;
F_42 ( V_29 , V_65 ) ;
} else {
F_12 ( V_29 -> V_38 , L_18 ,
V_65 -> V_38 -> V_2 ,
V_65 -> V_38 -> V_2 ) ;
V_21 = - V_43 ;
}
}
}
F_43 () ;
return V_21 ;
}
static int F_44 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_19 ,
V_51 -> V_10 ) ;
V_29 -> V_31 . V_53 = V_51 -> V_10 ;
if ( V_29 -> V_31 . V_68 )
F_25 ( V_29 -> V_38 , L_20 ,
V_29 -> V_31 . V_68 * V_29 -> V_31 . V_53 ) ;
if ( V_29 -> V_31 . V_69 )
F_25 ( V_29 -> V_38 , L_21 ,
V_29 -> V_31 . V_69 * V_29 -> V_31 . V_53 ) ;
if ( V_51 -> V_10 && V_29 -> V_31 . V_52 ) {
F_25 ( V_29 -> V_38 , L_22 ) ;
V_29 -> V_31 . V_52 = 0 ;
if ( V_29 -> V_31 . V_55 )
V_29 -> V_31 . V_55 = V_56 ;
}
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_51 -> V_10 ) {
F_45 ( & V_29 -> V_70 ) ;
} else {
F_45 ( & V_29 -> V_71 ) ;
F_46 ( V_29 -> V_72 , & V_29 -> V_70 , 0 ) ;
}
}
return 0 ;
}
static int F_47 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
int V_10 = V_51 -> V_10 ;
if ( ! V_29 -> V_31 . V_53 ) {
F_12 ( V_29 -> V_38 , L_23 ) ;
return - V_73 ;
}
if ( ( V_10 % V_29 -> V_31 . V_53 ) != 0 ) {
F_48 ( V_29 -> V_38 , L_24 ,
V_10 , V_29 -> V_31 . V_53 ,
( V_10 / V_29 -> V_31 . V_53 ) *
V_29 -> V_31 . V_53 ) ;
}
V_29 -> V_31 . V_68 = V_10 / V_29 -> V_31 . V_53 ;
F_25 ( V_29 -> V_38 , L_25 ,
V_29 -> V_31 . V_68 * V_29 -> V_31 . V_53 ) ;
return 0 ;
}
static int F_49 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
int V_10 = V_51 -> V_10 ;
if ( ! V_29 -> V_31 . V_53 ) {
F_12 ( V_29 -> V_38 , L_26 ) ;
return - V_73 ;
}
if ( ( V_10 % V_29 -> V_31 . V_53 ) != 0 ) {
F_48 ( V_29 -> V_38 , L_27 ,
V_10 , V_29 -> V_31 . V_53 ,
( V_10 / V_29 -> V_31 . V_53 ) *
V_29 -> V_31 . V_53 ) ;
}
V_29 -> V_31 . V_69 = V_10 / V_29 -> V_31 . V_53 ;
F_25 ( V_29 -> V_38 , L_28 ,
V_29 -> V_31 . V_69 * V_29 -> V_31 . V_53 ) ;
return 0 ;
}
static int F_50 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_29 ,
V_51 -> V_10 ) ;
V_29 -> V_31 . V_74 = V_51 -> V_10 ;
return 0 ;
}
static int F_51 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_30 ,
V_51 -> V_10 ) ;
V_29 -> V_31 . V_52 = V_51 -> V_10 ;
if ( V_51 -> V_10 ) {
if ( V_29 -> V_31 . V_53 ) {
F_25 ( V_29 -> V_38 , L_31 ) ;
V_29 -> V_31 . V_53 = 0 ;
}
if ( ! V_29 -> V_31 . V_75 [ 0 ] )
F_25 ( V_29 -> V_38 , L_32 ) ;
}
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_51 -> V_10 ) {
if ( V_29 -> V_31 . V_55 )
V_29 -> V_76 = NULL ;
F_45 ( & V_29 -> V_71 ) ;
} else {
V_29 -> V_76 = V_77 ;
F_45 ( & V_29 -> V_70 ) ;
F_46 ( V_29 -> V_72 , & V_29 -> V_71 , 0 ) ;
}
}
return 0 ;
}
static void F_52 ( struct V_28 * V_29 , int V_78 ,
T_3 V_79 ,
unsigned long V_80 )
{
T_3 * V_81 = V_29 -> V_31 . V_75 ;
struct V_82 * V_83 ;
struct V_58 * V_58 ;
if ( V_78 >= 0 && V_78 < V_84 ) {
F_53 (bond, slave, iter)
V_58 -> V_85 [ V_78 ] = V_80 ;
V_81 [ V_78 ] = V_79 ;
}
}
static int F_54 ( struct V_28 * V_29 , T_3 V_79 )
{
T_3 * V_81 = V_29 -> V_31 . V_75 ;
int V_86 ;
if ( ! F_55 ( V_79 ) ) {
F_12 ( V_29 -> V_38 , L_33 ,
& V_79 ) ;
return - V_43 ;
}
if ( F_56 ( V_81 , V_79 ) != - 1 ) {
F_12 ( V_29 -> V_38 , L_34 ,
& V_79 ) ;
return - V_43 ;
}
V_86 = F_56 ( V_81 , 0 ) ;
if ( V_86 == - 1 ) {
F_12 ( V_29 -> V_38 , L_35 ) ;
return - V_43 ;
}
F_25 ( V_29 -> V_38 , L_36 , & V_79 ) ;
F_52 ( V_29 , V_86 , V_79 , V_87 ) ;
return 0 ;
}
static int F_57 ( struct V_28 * V_29 , T_3 V_79 )
{
return F_54 ( V_29 , V_79 ) ;
}
static int F_58 ( struct V_28 * V_29 , T_3 V_79 )
{
T_3 * V_81 = V_29 -> V_31 . V_75 ;
struct V_82 * V_83 ;
struct V_58 * V_58 ;
unsigned long * V_88 ;
int V_86 , V_8 ;
if ( ! F_55 ( V_79 ) ) {
F_12 ( V_29 -> V_38 , L_37 ,
& V_79 ) ;
return - V_43 ;
}
V_86 = F_56 ( V_81 , V_79 ) ;
if ( V_86 == - 1 ) {
F_12 ( V_29 -> V_38 , L_38 ,
& V_79 ) ;
return - V_43 ;
}
if ( V_86 == 0 && ! V_81 [ 1 ] && V_29 -> V_31 . V_52 )
F_48 ( V_29 -> V_38 , L_39 ) ;
F_25 ( V_29 -> V_38 , L_40 , & V_79 ) ;
F_53 (bond, slave, iter) {
V_88 = V_58 -> V_85 ;
for ( V_8 = V_86 ; ( V_8 < V_84 - 1 ) && V_81 [ V_8 + 1 ] ; V_8 ++ )
V_88 [ V_8 ] = V_88 [ V_8 + 1 ] ;
V_88 [ V_8 ] = 0 ;
}
for ( V_8 = V_86 ; ( V_8 < V_84 - 1 ) && V_81 [ V_8 + 1 ] ; V_8 ++ )
V_81 [ V_8 ] = V_81 [ V_8 + 1 ] ;
V_81 [ V_8 ] = 0 ;
return 0 ;
}
void F_59 ( struct V_28 * V_29 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_84 ; V_8 ++ )
F_52 ( V_29 , V_8 , 0 , 0 ) ;
}
static int F_60 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
int V_21 = - V_73 ;
T_3 V_79 ;
if ( V_51 -> string ) {
if ( ! F_61 ( V_51 -> string + 1 , - 1 , ( V_89 * ) & V_79 , - 1 , NULL ) ) {
F_12 ( V_29 -> V_38 , L_41 ,
& V_79 ) ;
return V_21 ;
}
if ( V_51 -> string [ 0 ] == '+' )
V_21 = F_57 ( V_29 , V_79 ) ;
else if ( V_51 -> string [ 0 ] == '-' )
V_21 = F_58 ( V_29 , V_79 ) ;
else
F_12 ( V_29 -> V_38 , L_42 ) ;
} else {
V_79 = V_51 -> V_10 ;
V_21 = F_57 ( V_29 , V_79 ) ;
}
return V_21 ;
}
static int F_62 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_43 ,
V_51 -> string , V_51 -> V_10 ) ;
if ( V_29 -> V_38 -> V_12 & V_39 ) {
if ( ! V_51 -> V_10 )
V_29 -> V_76 = NULL ;
else if ( V_29 -> V_31 . V_52 )
V_29 -> V_76 = V_77 ;
}
V_29 -> V_31 . V_55 = V_51 -> V_10 ;
return 0 ;
}
static int F_63 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_44 ,
V_51 -> string , V_51 -> V_10 ) ;
V_29 -> V_31 . V_90 = V_51 -> V_10 ;
return 0 ;
}
static int F_64 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
char * V_17 , * V_91 = V_51 -> string ;
struct V_82 * V_83 ;
struct V_58 * V_58 ;
F_35 () ;
V_17 = strchr ( V_91 , '\n' ) ;
if ( V_17 )
* V_17 = '\0' ;
if ( ! strlen ( V_91 ) ) {
F_25 ( V_29 -> V_38 , L_45 ) ;
F_36 ( V_29 -> V_92 , NULL ) ;
memset ( V_29 -> V_31 . V_91 , 0 , sizeof( V_29 -> V_31 . V_91 ) ) ;
F_37 ( V_29 ) ;
goto V_25;
}
F_53 (bond, slave, iter) {
if ( strncmp ( V_58 -> V_38 -> V_2 , V_91 , V_61 ) == 0 ) {
F_25 ( V_29 -> V_38 , L_46 ,
V_58 -> V_38 -> V_2 ) ;
F_65 ( V_29 -> V_92 , V_58 ) ;
strcpy ( V_29 -> V_31 . V_91 , V_58 -> V_38 -> V_2 ) ;
F_37 ( V_29 ) ;
goto V_25;
}
}
if ( F_38 ( V_29 -> V_92 ) ) {
F_25 ( V_29 -> V_38 , L_45 ) ;
F_36 ( V_29 -> V_92 , NULL ) ;
F_37 ( V_29 ) ;
}
strncpy ( V_29 -> V_31 . V_91 , V_91 , V_61 ) ;
V_29 -> V_31 . V_91 [ V_61 - 1 ] = 0 ;
F_25 ( V_29 -> V_38 , L_47 ,
V_91 , V_29 -> V_38 -> V_2 ) ;
V_25:
F_43 () ;
return 0 ;
}
static int F_66 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_48 ,
V_51 -> string , V_51 -> V_10 ) ;
V_29 -> V_31 . V_93 = V_51 -> V_10 ;
F_35 () ;
F_37 ( V_29 ) ;
F_43 () ;
return 0 ;
}
static int F_67 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_49 ,
V_51 -> string , V_51 -> V_10 ) ;
V_29 -> V_31 . V_94 = V_51 -> V_10 ;
return 0 ;
}
static int F_68 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_50 ,
V_51 -> string , V_51 -> V_10 ) ;
V_29 -> V_31 . V_95 = V_51 -> V_10 ;
return 0 ;
}
static int F_69 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_51 ,
V_51 -> V_10 ) ;
V_29 -> V_31 . V_96 = V_51 -> V_10 ;
return 0 ;
}
static int F_70 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
V_29 -> V_31 . V_97 = V_51 -> V_10 ;
return 0 ;
}
static int F_71 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
struct V_82 * V_83 ;
struct V_58 * V_58 ;
if ( V_51 -> V_10 == V_29 -> V_31 . V_98 )
return 0 ;
V_29 -> V_31 . V_98 = V_51 -> V_10 ;
F_53 (bond, slave, iter) {
if ( ! F_72 ( V_58 ) ) {
if ( V_51 -> V_10 )
V_58 -> V_99 = 0 ;
else
V_58 -> V_99 = 1 ;
}
}
return 0 ;
}
static int F_73 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_52 ,
V_51 -> V_10 ) ;
V_29 -> V_31 . V_100 = V_51 -> V_10 ;
F_74 ( V_29 ) ;
return 0 ;
}
static int F_75 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
V_29 -> V_31 . V_101 = V_51 -> V_10 ;
return 0 ;
}
static int F_76 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
V_29 -> V_31 . V_102 = V_51 -> V_10 ;
if ( V_51 -> V_10 > 0 ) {
V_29 -> V_31 . V_103 =
F_77 ( V_51 -> V_10 ) ;
} else {
V_29 -> V_31 . V_103 =
(struct F_77 ) { 0 } ;
}
return 0 ;
}
static int F_78 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_53 ,
V_51 -> string , V_51 -> V_10 ) ;
V_29 -> V_31 . V_104 = V_51 -> V_10 ;
F_79 ( V_29 ) ;
return 0 ;
}
static int F_80 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_54 ,
V_51 -> string , V_51 -> V_10 ) ;
V_29 -> V_31 . V_105 = V_51 -> V_10 ;
return 0 ;
}
static int F_81 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
struct V_58 * V_58 , * V_106 ;
struct V_57 * V_107 ;
struct V_82 * V_83 ;
char * V_108 ;
int V_21 = 0 ;
T_4 V_109 ;
V_108 = strchr ( V_51 -> string , ':' ) ;
if ( ! V_108 )
goto V_110;
* V_108 = '\0' ;
if ( sscanf ( ++ V_108 , L_55 , & V_109 ) != 1 )
goto V_110;
if ( ! F_82 ( V_51 -> string ) ||
V_109 > V_29 -> V_38 -> V_111 )
goto V_110;
V_107 = F_31 ( F_32 ( V_29 -> V_38 ) , V_51 -> string ) ;
if ( ! V_107 )
goto V_110;
V_106 = NULL ;
F_53 (bond, slave, iter) {
if ( V_107 == V_58 -> V_38 )
V_106 = V_58 ;
else if ( V_109 && V_109 == V_58 -> V_112 ) {
goto V_110;
}
}
if ( ! V_106 )
goto V_110;
V_106 -> V_112 = V_109 ;
V_25:
return V_21 ;
V_110:
F_25 ( V_29 -> V_38 , L_56 ) ;
V_21 = - V_73 ;
goto V_25;
}
static int F_83 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
char V_113 [ V_61 + 1 ] = { 0 , } ;
struct V_57 * V_38 ;
char * V_60 ;
int V_21 ;
sscanf ( V_51 -> string , L_57 , V_113 ) ;
V_60 = V_113 + 1 ;
if ( ( strlen ( V_113 ) <= 1 ) ||
! F_82 ( V_60 ) )
goto V_110;
V_38 = F_31 ( F_32 ( V_29 -> V_38 ) , V_60 ) ;
if ( ! V_38 ) {
F_25 ( V_29 -> V_38 , L_58 ,
V_60 ) ;
V_21 = - V_63 ;
goto V_25;
}
switch ( V_113 [ 0 ] ) {
case '+' :
F_25 ( V_29 -> V_38 , L_59 , V_38 -> V_2 ) ;
V_21 = F_84 ( V_29 -> V_38 , V_38 ) ;
break;
case '-' :
F_25 ( V_29 -> V_38 , L_60 , V_38 -> V_2 ) ;
V_21 = F_85 ( V_29 -> V_38 , V_38 ) ;
break;
default:
goto V_110;
}
V_25:
return V_21 ;
V_110:
F_12 ( V_29 -> V_38 , L_61 ) ;
V_21 = - V_73 ;
goto V_25;
}
static int F_86 ( struct V_28 * V_29 ,
const struct V_6 * V_51 )
{
F_25 ( V_29 -> V_38 , L_62 ,
V_51 -> string , V_51 -> V_10 ) ;
V_29 -> V_31 . V_114 = V_51 -> V_10 ;
return 0 ;
}
