const struct V_1 * F_1 ( unsigned int V_2 , T_1 V_3 )
{
const struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 ) ;
if ( F_3 ( ! V_5 ) )
return NULL ;
for ( V_6 = 0 ; V_5 -> V_7 && V_5 -> V_7 [ V_6 ] . string ; V_6 ++ )
if ( V_5 -> V_7 [ V_6 ] . V_8 == V_3 )
return & V_5 -> V_7 [ V_6 ] ;
return NULL ;
}
static const struct V_1 * F_4 ( const struct V_4 * V_5 ,
T_2 V_9 )
{
int V_6 ;
for ( V_6 = 0 ; V_5 -> V_7 && V_5 -> V_7 [ V_6 ] . string ; V_6 ++ )
if ( V_5 -> V_7 [ V_6 ] . V_10 & V_9 )
return & V_5 -> V_7 [ V_6 ] ;
return NULL ;
}
static bool F_5 ( const struct V_4 * V_5 , T_1 V_3 )
{
const struct V_1 * V_11 , * V_12 ;
V_11 = F_4 ( V_5 , V_13 ) ;
V_12 = F_4 ( V_5 , V_14 ) ;
if ( ! V_12 || ( V_11 && V_3 < V_11 -> V_8 ) || V_3 > V_12 -> V_8 )
return false ;
return true ;
}
const struct V_1 * F_6 ( const struct V_4 * V_5 ,
struct V_1 * V_3 )
{
char * V_15 , V_16 [ V_17 + 1 ] = { 0 , } ;
const struct V_1 * V_18 ;
const struct V_1 * V_19 = NULL ;
bool V_20 ;
int V_6 , V_21 ;
if ( V_5 -> V_10 & V_22 )
return V_3 ;
V_18 = V_5 -> V_7 ;
if ( ! V_18 )
goto V_23;
V_20 = V_3 -> V_8 != V_24 ;
if ( ! V_20 ) {
if ( ! V_3 -> string )
goto V_23;
V_15 = strchr ( V_3 -> string , '\n' ) ;
if ( V_15 )
* V_15 = '\0' ;
for ( V_15 = V_3 -> string ; * V_15 ; V_15 ++ )
if ( ! ( isdigit ( * V_15 ) || isspace ( * V_15 ) ) )
break;
if ( * V_15 ) {
V_21 = sscanf ( V_3 -> string , L_1 , V_16 ) ;
} else {
V_21 = sscanf ( V_3 -> string , L_2 , & V_3 -> V_8 ) ;
V_20 = true ;
}
if ( ! V_21 )
goto V_23;
}
for ( V_6 = 0 ; V_18 [ V_6 ] . string ; V_6 ++ ) {
if ( V_20 ) {
if ( V_3 -> V_8 == V_18 [ V_6 ] . V_8 )
V_19 = & V_18 [ V_6 ] ;
} else {
if ( ! strcmp ( V_16 , L_3 ) &&
( V_18 [ V_6 ] . V_10 & V_25 ) )
V_19 = & V_18 [ V_6 ] ;
if ( ! strcmp ( V_16 , V_18 [ V_6 ] . string ) )
V_19 = & V_18 [ V_6 ] ;
}
if ( V_19 )
goto V_23;
}
if ( V_20 && F_5 ( V_5 , V_3 -> V_8 ) )
V_19 = V_3 ;
V_23:
return V_19 ;
}
static int F_7 ( struct V_26 * V_27 ,
const struct V_4 * V_5 )
{
struct V_28 * V_29 = & V_27 -> V_29 ;
if ( F_8 ( V_29 -> V_30 , & V_5 -> V_31 ) )
return - V_32 ;
if ( ( V_5 -> V_10 & V_33 ) && F_9 ( V_27 ) )
return - V_34 ;
if ( ( V_5 -> V_10 & V_35 ) && ( V_27 -> V_36 -> V_10 & V_37 ) )
return - V_38 ;
return 0 ;
}
static void F_10 ( struct V_26 * V_27 ,
const struct V_4 * V_5 )
{
const struct V_1 * V_39 ;
struct V_28 * V_29 ;
V_29 = & V_27 -> V_29 ;
V_39 = F_1 ( V_40 , V_29 -> V_30 ) ;
if ( F_8 ( V_29 -> V_30 , & V_5 -> V_31 ) )
F_11 ( L_4 ,
V_27 -> V_36 -> V_41 , V_5 -> V_41 ,
V_39 -> string , V_39 -> V_8 ) ;
}
static void F_12 ( struct V_26 * V_27 ,
const struct V_4 * V_5 ,
int error , const struct V_1 * V_3 )
{
const struct V_1 * V_11 , * V_12 ;
char * V_15 ;
switch ( error ) {
case - V_42 :
if ( V_3 ) {
if ( V_3 -> string ) {
V_15 = strchr ( V_3 -> string , '\n' ) ;
if ( V_15 )
* V_15 = '\0' ;
F_11 ( L_5 ,
V_27 -> V_36 -> V_41 , V_5 -> V_41 , V_3 -> string ) ;
} else {
F_11 ( L_6 ,
V_27 -> V_36 -> V_41 , V_5 -> V_41 , V_3 -> V_8 ) ;
}
}
V_11 = F_4 ( V_5 , V_13 ) ;
V_12 = F_4 ( V_5 , V_14 ) ;
if ( ! V_12 )
break;
F_11 ( L_7 ,
V_27 -> V_36 -> V_41 , V_5 -> V_41 , V_11 ? V_11 -> V_8 : 0 ,
V_12 -> V_8 ) ;
break;
case - V_32 :
F_10 ( V_27 , V_5 ) ;
break;
case - V_34 :
F_11 ( L_8 ,
V_27 -> V_36 -> V_41 , V_5 -> V_41 ) ;
break;
case - V_38 :
F_11 ( L_9 ,
V_27 -> V_36 -> V_41 , V_5 -> V_41 ) ;
break;
default:
break;
}
}
int F_13 ( struct V_26 * V_27 ,
unsigned int V_2 , struct V_1 * V_3 )
{
const struct V_1 * V_43 = NULL ;
const struct V_4 * V_5 ;
int V_19 = - V_44 ;
F_14 () ;
V_5 = F_2 ( V_2 ) ;
if ( F_3 ( ! V_3 ) || F_3 ( ! V_5 ) )
goto V_23;
V_19 = F_7 ( V_27 , V_5 ) ;
if ( V_19 )
goto V_23;
V_43 = F_6 ( V_5 , V_3 ) ;
if ( ! V_43 ) {
V_19 = - V_42 ;
goto V_23;
}
V_19 = V_5 -> V_45 ( V_27 , V_43 ) ;
V_23:
if ( V_19 )
F_12 ( V_27 , V_5 , V_19 , V_3 ) ;
return V_19 ;
}
int F_15 ( struct V_26 * V_27 , unsigned int V_2 , char * V_46 )
{
struct V_1 V_47 ;
int V_19 ;
if ( ! F_16 () )
return F_17 () ;
F_18 ( & V_47 , V_46 ) ;
V_19 = F_13 ( V_27 , V_2 , & V_47 ) ;
F_19 () ;
return V_19 ;
}
const struct V_4 * F_2 ( unsigned int V_2 )
{
if ( ! F_20 ( V_2 ) )
return NULL ;
return & V_48 [ V_2 ] ;
}
int F_21 ( struct V_26 * V_27 , const struct V_1 * V_49 )
{
if ( F_22 ( V_49 -> V_8 ) && V_27 -> V_29 . V_50 ) {
F_23 ( L_10 ,
V_27 -> V_36 -> V_41 , V_49 -> string ) ;
V_27 -> V_29 . V_50 = 0 ;
V_27 -> V_29 . V_51 = V_52 ;
F_23 ( L_11 ,
V_27 -> V_36 -> V_41 , V_27 -> V_29 . V_51 ) ;
}
V_27 -> V_29 . V_53 = V_54 ;
V_27 -> V_29 . V_30 = V_49 -> V_8 ;
return 0 ;
}
static struct V_55 * F_24 ( struct V_26 * V_27 ,
struct V_56 * V_56 )
{
return F_25 ( V_27 -> V_29 . V_30 ) && V_56 ? V_56 -> V_36 : NULL ;
}
struct V_55 * F_26 ( struct V_26 * V_27 )
{
struct V_56 * V_56 = F_27 ( V_27 -> V_57 ) ;
return F_24 ( V_27 , V_56 ) ;
}
struct V_55 * F_28 ( struct V_26 * V_27 )
{
return F_24 ( V_27 , V_27 -> V_57 ) ;
}
static int F_29 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
char V_58 [ V_59 ] = { 0 , } ;
struct V_55 * V_60 ;
int V_19 = 0 ;
sscanf ( V_49 -> string , L_12 , V_58 ) ;
if ( ! strlen ( V_58 ) || V_49 -> string [ 0 ] == '\n' ) {
V_60 = NULL ;
} else {
V_60 = F_30 ( F_31 ( V_27 -> V_36 ) , V_58 ) ;
if ( ! V_60 )
return - V_61 ;
}
if ( V_60 ) {
if ( ! F_32 ( V_60 ) ) {
F_11 ( L_13 ,
V_60 -> V_41 ) ;
return - V_42 ;
}
if ( V_27 -> V_36 != F_33 ( V_60 ) ) {
F_11 ( L_14 ,
V_27 -> V_36 -> V_41 , V_60 -> V_41 ) ;
return - V_42 ;
}
}
F_34 () ;
F_35 ( & V_27 -> V_62 ) ;
if ( ! V_60 ) {
F_23 ( L_15 , V_27 -> V_36 -> V_41 ) ;
F_36 ( V_27 -> V_57 , NULL ) ;
F_37 ( V_27 ) ;
} else {
struct V_56 * V_63 = V_27 -> V_57 ;
struct V_56 * V_64 = F_38 ( V_60 ) ;
F_39 ( ! V_64 ) ;
if ( V_64 == V_63 ) {
F_23 ( L_16 ,
V_27 -> V_36 -> V_41 , V_64 -> V_36 -> V_41 ) ;
} else {
if ( V_63 && ( V_64 -> V_65 == V_66 ) &&
F_40 ( V_64 -> V_36 ) ) {
F_23 ( L_17 ,
V_27 -> V_36 -> V_41 , V_64 -> V_36 -> V_41 ) ;
F_41 ( V_27 , V_64 ) ;
} else {
F_11 ( L_18 ,
V_27 -> V_36 -> V_41 , V_64 -> V_36 -> V_41 ,
V_64 -> V_36 -> V_41 ) ;
V_19 = - V_42 ;
}
}
}
F_42 ( & V_27 -> V_62 ) ;
F_43 () ;
return V_19 ;
}
static int F_44 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_19 ,
V_27 -> V_36 -> V_41 , V_49 -> V_8 ) ;
V_27 -> V_29 . V_51 = V_49 -> V_8 ;
if ( V_27 -> V_29 . V_67 )
F_23 ( L_20 ,
V_27 -> V_36 -> V_41 ,
V_27 -> V_29 . V_67 * V_27 -> V_29 . V_51 ) ;
if ( V_27 -> V_29 . V_68 )
F_23 ( L_21 ,
V_27 -> V_36 -> V_41 ,
V_27 -> V_29 . V_68 * V_27 -> V_29 . V_51 ) ;
if ( V_49 -> V_8 && V_27 -> V_29 . V_50 ) {
F_23 ( L_22 ,
V_27 -> V_36 -> V_41 ) ;
V_27 -> V_29 . V_50 = 0 ;
if ( V_27 -> V_29 . V_53 )
V_27 -> V_29 . V_53 = V_54 ;
}
if ( V_27 -> V_36 -> V_10 & V_37 ) {
if ( ! V_49 -> V_8 ) {
F_45 ( & V_27 -> V_69 ) ;
} else {
F_45 ( & V_27 -> V_70 ) ;
F_46 ( V_27 -> V_71 , & V_27 -> V_69 , 0 ) ;
}
}
return 0 ;
}
static int F_47 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
int V_8 = V_49 -> V_8 ;
if ( ! V_27 -> V_29 . V_51 ) {
F_11 ( L_23 ,
V_27 -> V_36 -> V_41 ) ;
return - V_72 ;
}
if ( ( V_8 % V_27 -> V_29 . V_51 ) != 0 ) {
F_48 ( L_24 ,
V_27 -> V_36 -> V_41 , V_8 ,
V_27 -> V_29 . V_51 ,
( V_8 / V_27 -> V_29 . V_51 ) *
V_27 -> V_29 . V_51 ) ;
}
V_27 -> V_29 . V_67 = V_8 / V_27 -> V_29 . V_51 ;
F_23 ( L_25 ,
V_27 -> V_36 -> V_41 , V_27 -> V_29 . V_67 * V_27 -> V_29 . V_51 ) ;
return 0 ;
}
static int F_49 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
int V_8 = V_49 -> V_8 ;
if ( ! V_27 -> V_29 . V_51 ) {
F_11 ( L_26 ,
V_27 -> V_36 -> V_41 ) ;
return - V_72 ;
}
if ( ( V_8 % V_27 -> V_29 . V_51 ) != 0 ) {
F_48 ( L_27 ,
V_27 -> V_36 -> V_41 , V_8 ,
V_27 -> V_29 . V_51 ,
( V_8 / V_27 -> V_29 . V_51 ) *
V_27 -> V_29 . V_51 ) ;
}
V_27 -> V_29 . V_68 = V_8 / V_27 -> V_29 . V_51 ;
F_23 ( L_28 ,
V_27 -> V_36 -> V_41 , V_27 -> V_29 . V_68 * V_27 -> V_29 . V_51 ) ;
return 0 ;
}
static int F_50 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_29 ,
V_27 -> V_36 -> V_41 , V_49 -> V_8 ) ;
V_27 -> V_29 . V_73 = V_49 -> V_8 ;
return 0 ;
}
static int F_51 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_30 ,
V_27 -> V_36 -> V_41 , V_49 -> V_8 ) ;
V_27 -> V_29 . V_50 = V_49 -> V_8 ;
if ( V_49 -> V_8 ) {
if ( V_27 -> V_29 . V_51 ) {
F_23 ( L_31 ,
V_27 -> V_36 -> V_41 , V_27 -> V_36 -> V_41 ) ;
V_27 -> V_29 . V_51 = 0 ;
}
if ( ! V_27 -> V_29 . V_74 [ 0 ] )
F_23 ( L_32 ,
V_27 -> V_36 -> V_41 ) ;
}
if ( V_27 -> V_36 -> V_10 & V_37 ) {
if ( ! V_49 -> V_8 ) {
if ( V_27 -> V_29 . V_53 )
V_27 -> V_75 = NULL ;
F_45 ( & V_27 -> V_70 ) ;
} else {
V_27 -> V_75 = V_76 ;
F_45 ( & V_27 -> V_69 ) ;
F_46 ( V_27 -> V_71 , & V_27 -> V_70 , 0 ) ;
}
}
return 0 ;
}
static void F_52 ( struct V_26 * V_27 , int V_77 ,
T_3 V_78 ,
unsigned long V_79 )
{
T_3 * V_80 = V_27 -> V_29 . V_74 ;
struct V_81 * V_82 ;
struct V_56 * V_56 ;
if ( V_77 >= 0 && V_77 < V_83 ) {
F_53 (bond, slave, iter)
V_56 -> V_84 [ V_77 ] = V_79 ;
V_80 [ V_77 ] = V_78 ;
}
}
static int F_54 ( struct V_26 * V_27 , T_3 V_78 )
{
T_3 * V_80 = V_27 -> V_29 . V_74 ;
int V_85 ;
if ( F_55 ( V_78 ) ) {
F_11 ( L_33 ,
V_27 -> V_36 -> V_41 , & V_78 ) ;
return - V_42 ;
}
if ( F_56 ( V_80 , V_78 ) != - 1 ) {
F_11 ( L_34 ,
V_27 -> V_36 -> V_41 , & V_78 ) ;
return - V_42 ;
}
V_85 = F_56 ( V_80 , 0 ) ;
if ( V_85 == - 1 ) {
F_11 ( L_35 , V_27 -> V_36 -> V_41 ) ;
return - V_42 ;
}
F_23 ( L_36 , V_27 -> V_36 -> V_41 , & V_78 ) ;
F_52 ( V_27 , V_85 , V_78 , V_86 ) ;
return 0 ;
}
static int F_57 ( struct V_26 * V_27 , T_3 V_78 )
{
int V_19 ;
F_35 ( & V_27 -> V_87 ) ;
V_19 = F_54 ( V_27 , V_78 ) ;
F_42 ( & V_27 -> V_87 ) ;
return V_19 ;
}
static int F_58 ( struct V_26 * V_27 , T_3 V_78 )
{
T_3 * V_80 = V_27 -> V_29 . V_74 ;
struct V_81 * V_82 ;
struct V_56 * V_56 ;
unsigned long * V_88 ;
int V_85 , V_6 ;
if ( F_55 ( V_78 ) ) {
F_11 ( L_37 ,
V_27 -> V_36 -> V_41 , & V_78 ) ;
return - V_42 ;
}
V_85 = F_56 ( V_80 , V_78 ) ;
if ( V_85 == - 1 ) {
F_11 ( L_38 ,
V_27 -> V_36 -> V_41 , & V_78 ) ;
return - V_42 ;
}
if ( V_85 == 0 && ! V_80 [ 1 ] && V_27 -> V_29 . V_50 )
F_48 ( L_39 ,
V_27 -> V_36 -> V_41 ) ;
F_23 ( L_40 , V_27 -> V_36 -> V_41 , & V_78 ) ;
F_35 ( & V_27 -> V_87 ) ;
F_53 (bond, slave, iter) {
V_88 = V_56 -> V_84 ;
for ( V_6 = V_85 ; ( V_6 < V_83 - 1 ) && V_80 [ V_6 + 1 ] ; V_6 ++ )
V_88 [ V_6 ] = V_88 [ V_6 + 1 ] ;
V_88 [ V_6 ] = 0 ;
}
for ( V_6 = V_85 ; ( V_6 < V_83 - 1 ) && V_80 [ V_6 + 1 ] ; V_6 ++ )
V_80 [ V_6 ] = V_80 [ V_6 + 1 ] ;
V_80 [ V_6 ] = 0 ;
F_42 ( & V_27 -> V_87 ) ;
return 0 ;
}
void F_59 ( struct V_26 * V_27 )
{
int V_6 ;
F_35 ( & V_27 -> V_87 ) ;
for ( V_6 = 0 ; V_6 < V_83 ; V_6 ++ )
F_52 ( V_27 , V_6 , 0 , 0 ) ;
F_42 ( & V_27 -> V_87 ) ;
}
static int F_60 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
int V_19 = - V_72 ;
T_3 V_78 ;
if ( V_49 -> string ) {
if ( ! F_61 ( V_49 -> string + 1 , - 1 , ( V_89 * ) & V_78 , - 1 , NULL ) ) {
F_11 ( L_41 ,
V_27 -> V_36 -> V_41 , & V_78 ) ;
return V_19 ;
}
if ( V_49 -> string [ 0 ] == '+' )
V_19 = F_57 ( V_27 , V_78 ) ;
else if ( V_49 -> string [ 0 ] == '-' )
V_19 = F_58 ( V_27 , V_78 ) ;
else
F_11 ( L_42 ,
V_27 -> V_36 -> V_41 ) ;
} else {
V_78 = V_49 -> V_8 ;
V_19 = F_57 ( V_27 , V_78 ) ;
}
return V_19 ;
}
static int F_62 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_43 ,
V_27 -> V_36 -> V_41 , V_49 -> string , V_49 -> V_8 ) ;
if ( V_27 -> V_36 -> V_10 & V_37 ) {
if ( ! V_49 -> V_8 )
V_27 -> V_75 = NULL ;
else if ( V_27 -> V_29 . V_50 )
V_27 -> V_75 = V_76 ;
}
V_27 -> V_29 . V_53 = V_49 -> V_8 ;
return 0 ;
}
static int F_63 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_44 ,
V_27 -> V_36 -> V_41 , V_49 -> string , V_49 -> V_8 ) ;
V_27 -> V_29 . V_90 = V_49 -> V_8 ;
return 0 ;
}
static int F_64 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
char * V_15 , * V_91 = V_49 -> string ;
struct V_81 * V_82 ;
struct V_56 * V_56 ;
F_34 () ;
F_65 ( & V_27 -> V_87 ) ;
F_35 ( & V_27 -> V_62 ) ;
V_15 = strchr ( V_91 , '\n' ) ;
if ( V_15 )
* V_15 = '\0' ;
if ( ! strlen ( V_91 ) ) {
F_23 ( L_45 , V_27 -> V_36 -> V_41 ) ;
V_27 -> V_92 = NULL ;
memset ( V_27 -> V_29 . V_91 , 0 , sizeof( V_27 -> V_29 . V_91 ) ) ;
F_37 ( V_27 ) ;
goto V_23;
}
F_53 (bond, slave, iter) {
if ( strncmp ( V_56 -> V_36 -> V_41 , V_91 , V_59 ) == 0 ) {
F_23 ( L_46 ,
V_27 -> V_36 -> V_41 , V_56 -> V_36 -> V_41 ) ;
V_27 -> V_92 = V_56 ;
strcpy ( V_27 -> V_29 . V_91 , V_56 -> V_36 -> V_41 ) ;
F_37 ( V_27 ) ;
goto V_23;
}
}
if ( V_27 -> V_92 ) {
F_23 ( L_45 , V_27 -> V_36 -> V_41 ) ;
V_27 -> V_92 = NULL ;
F_37 ( V_27 ) ;
}
strncpy ( V_27 -> V_29 . V_91 , V_91 , V_59 ) ;
V_27 -> V_29 . V_91 [ V_59 - 1 ] = 0 ;
F_23 ( L_47 ,
V_27 -> V_36 -> V_41 , V_91 , V_27 -> V_36 -> V_41 ) ;
V_23:
F_42 ( & V_27 -> V_62 ) ;
F_66 ( & V_27 -> V_87 ) ;
F_43 () ;
return 0 ;
}
static int F_67 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_48 ,
V_27 -> V_36 -> V_41 , V_49 -> string , V_49 -> V_8 ) ;
V_27 -> V_29 . V_93 = V_49 -> V_8 ;
F_34 () ;
F_35 ( & V_27 -> V_62 ) ;
F_37 ( V_27 ) ;
F_42 ( & V_27 -> V_62 ) ;
F_43 () ;
return 0 ;
}
static int F_68 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_49 ,
V_27 -> V_36 -> V_41 , V_49 -> string , V_49 -> V_8 ) ;
V_27 -> V_29 . V_94 = V_49 -> V_8 ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_50 ,
V_27 -> V_36 -> V_41 , V_49 -> string , V_49 -> V_8 ) ;
V_27 -> V_29 . V_95 = V_49 -> V_8 ;
return 0 ;
}
static int F_70 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_51 ,
V_27 -> V_36 -> V_41 , V_49 -> V_8 ) ;
V_27 -> V_29 . V_96 = V_49 -> V_8 ;
return 0 ;
}
static int F_71 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
V_27 -> V_29 . V_97 = V_49 -> V_8 ;
return 0 ;
}
static int F_72 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
struct V_81 * V_82 ;
struct V_56 * V_56 ;
if ( V_49 -> V_8 == V_27 -> V_29 . V_98 )
return 0 ;
V_27 -> V_29 . V_98 = V_49 -> V_8 ;
F_53 (bond, slave, iter) {
if ( ! F_73 ( V_56 ) ) {
if ( V_49 -> V_8 )
V_56 -> V_99 = 0 ;
else
V_56 -> V_99 = 1 ;
}
}
return 0 ;
}
static int F_74 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_52 ,
V_27 -> V_36 -> V_41 , V_49 -> V_8 ) ;
V_27 -> V_29 . V_100 = V_49 -> V_8 ;
return 0 ;
}
static int F_75 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
V_27 -> V_29 . V_101 = V_49 -> V_8 ;
return 0 ;
}
static int F_76 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
V_27 -> V_29 . V_102 = V_49 -> V_8 ;
if ( V_49 -> V_8 > 0 ) {
V_27 -> V_29 . V_103 =
F_77 ( V_49 -> V_8 ) ;
} else {
V_27 -> V_29 . V_103 =
(struct F_77 ) { 0 } ;
}
return 0 ;
}
static int F_78 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_53 ,
V_27 -> V_36 -> V_41 , V_49 -> string , V_49 -> V_8 ) ;
V_27 -> V_29 . V_104 = V_49 -> V_8 ;
F_79 ( V_27 ) ;
return 0 ;
}
static int F_80 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
F_23 ( L_54 ,
V_27 -> V_36 -> V_41 , V_49 -> string , V_49 -> V_8 ) ;
V_27 -> V_29 . V_105 = V_49 -> V_8 ;
return 0 ;
}
static int F_81 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
struct V_56 * V_56 , * V_106 ;
struct V_55 * V_107 ;
struct V_81 * V_82 ;
char * V_108 ;
int V_19 = 0 ;
T_4 V_109 ;
V_108 = strchr ( V_49 -> string , ':' ) ;
if ( ! V_108 )
goto V_110;
* V_108 = '\0' ;
if ( sscanf ( ++ V_108 , L_55 , & V_109 ) != 1 )
goto V_110;
if ( ! F_82 ( V_49 -> string ) ||
V_109 > V_27 -> V_36 -> V_111 )
goto V_110;
V_107 = F_30 ( F_31 ( V_27 -> V_36 ) , V_49 -> string ) ;
if ( ! V_107 )
goto V_110;
V_106 = NULL ;
F_53 (bond, slave, iter) {
if ( V_107 == V_56 -> V_36 )
V_106 = V_56 ;
else if ( V_109 && V_109 == V_56 -> V_112 ) {
goto V_110;
}
}
if ( ! V_106 )
goto V_110;
V_106 -> V_112 = V_109 ;
V_23:
return V_19 ;
V_110:
F_23 ( L_56 , V_27 -> V_36 -> V_41 ) ;
V_19 = - V_72 ;
goto V_23;
}
static int F_83 ( struct V_26 * V_27 ,
const struct V_1 * V_49 )
{
char V_113 [ V_59 + 1 ] = { 0 , } ;
struct V_55 * V_36 ;
char * V_58 ;
int V_19 ;
sscanf ( V_49 -> string , L_57 , V_113 ) ;
V_58 = V_113 + 1 ;
if ( ( strlen ( V_113 ) <= 1 ) ||
! F_82 ( V_58 ) )
goto V_110;
V_36 = F_30 ( F_31 ( V_27 -> V_36 ) , V_58 ) ;
if ( ! V_36 ) {
F_23 ( L_58 ,
V_27 -> V_36 -> V_41 , V_58 ) ;
V_19 = - V_61 ;
goto V_23;
}
switch ( V_113 [ 0 ] ) {
case '+' :
F_23 ( L_59 , V_27 -> V_36 -> V_41 , V_36 -> V_41 ) ;
V_19 = F_84 ( V_27 -> V_36 , V_36 ) ;
break;
case '-' :
F_23 ( L_60 , V_27 -> V_36 -> V_41 , V_36 -> V_41 ) ;
V_19 = F_85 ( V_27 -> V_36 , V_36 ) ;
break;
default:
goto V_110;
}
V_23:
return V_19 ;
V_110:
F_11 ( L_61 ,
V_27 -> V_36 -> V_41 ) ;
V_19 = - V_72 ;
goto V_23;
}
