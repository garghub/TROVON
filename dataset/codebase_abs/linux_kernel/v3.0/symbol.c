static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 = F_2 ( V_6 , V_2 ) ;
V_5 -> V_7 = F_3 ( F_4 ( V_3 , V_8 ) ) ;
}
void F_5 ( void )
{
struct V_1 * V_2 ;
struct V_9 V_10 ;
static bool V_11 = false ;
if ( V_11 )
return;
V_11 = true ;
F_6 ( & V_10 ) ;
V_2 = F_4 ( L_1 , 0 ) ;
V_2 -> type = V_12 ;
V_2 -> V_13 |= V_14 ;
F_1 ( V_2 , V_10 . V_15 ) ;
}
enum V_16 F_7 ( struct V_1 * V_2 )
{
enum V_16 type = V_2 -> type ;
if ( type == V_17 ) {
if ( F_8 ( V_2 ) && V_2 -> V_18 == V_19 )
type = V_20 ;
else if ( V_21 == V_22 )
type = V_20 ;
}
return type ;
}
const char * F_9 ( enum V_16 type )
{
switch ( type ) {
case V_20 :
return L_2 ;
case V_17 :
return L_3 ;
case V_23 :
return L_4 ;
case V_24 :
return L_5 ;
case V_12 :
return L_6 ;
case V_25 :
return L_7 ;
case V_26 :
break;
}
return L_8 ;
}
struct V_4 * F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_11 (sym, prop)
return V_5 ;
return NULL ;
}
struct V_4 * F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_13 (sym, prop, P_ENV)
return V_5 ;
return NULL ;
}
struct V_4 * F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_15 (sym, prop) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
if ( V_5 -> V_18 . V_27 != V_22 )
return V_5 ;
}
return NULL ;
}
static struct V_4 * F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_13 (sym, prop, P_RANGE) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
if ( V_5 -> V_18 . V_27 != V_22 )
return V_5 ;
}
return NULL ;
}
static int F_18 ( struct V_1 * V_2 , int V_28 )
{
F_19 ( V_2 ) ;
switch ( V_2 -> type ) {
case V_23 :
V_28 = 10 ;
break;
case V_24 :
V_28 = 16 ;
break;
default:
break;
}
return strtol ( V_2 -> V_29 . V_30 , NULL , V_28 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_28 , V_30 , V_31 ;
char V_32 [ 64 ] ;
switch ( V_2 -> type ) {
case V_23 :
V_28 = 10 ;
break;
case V_24 :
V_28 = 16 ;
break;
default:
return;
}
V_5 = F_17 ( V_2 ) ;
if ( ! V_5 )
return;
V_30 = strtol ( V_2 -> V_29 . V_30 , NULL , V_28 ) ;
V_31 = F_18 ( V_5 -> V_7 -> V_33 . V_2 , V_28 ) ;
if ( V_30 >= V_31 ) {
V_31 = F_18 ( V_5 -> V_7 -> V_34 . V_2 , V_28 ) ;
if ( V_30 <= V_31 )
return;
}
if ( V_2 -> type == V_23 )
sprintf ( V_32 , L_9 , V_31 ) ;
else
sprintf ( V_32 , L_10 , V_31 ) ;
V_2 -> V_29 . V_30 = F_21 ( V_32 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_1 V_27 ;
V_27 = V_22 ;
F_23 (sym, prop) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
V_27 = F_24 ( V_27 , V_5 -> V_18 . V_27 ) ;
}
if ( V_27 == V_35 && ( V_2 -> type != V_17 || V_21 == V_22 ) )
V_27 = V_19 ;
if ( V_2 -> V_18 != V_27 ) {
V_2 -> V_18 = V_27 ;
F_25 ( V_2 ) ;
}
if ( F_8 ( V_2 ) )
return;
V_27 = V_19 ;
if ( V_2 -> V_36 . V_7 )
V_27 = F_16 ( V_2 -> V_36 . V_7 ) ;
if ( V_27 == V_35 )
V_27 = V_19 ;
if ( V_2 -> V_36 . V_27 != V_27 ) {
V_2 -> V_36 . V_27 = V_27 ;
F_25 ( V_2 ) ;
}
V_27 = V_22 ;
if ( V_2 -> V_37 . V_7 )
V_27 = F_16 ( V_2 -> V_37 . V_7 ) ;
if ( V_27 == V_35 && F_7 ( V_2 ) == V_20 )
V_27 = V_19 ;
if ( V_2 -> V_37 . V_27 != V_27 ) {
V_2 -> V_37 . V_27 = V_27 ;
F_25 ( V_2 ) ;
}
}
struct V_1 * F_26 ( struct V_1 * V_2 )
{
struct V_1 * V_38 ;
struct V_4 * V_5 ;
struct V_7 * V_39 ;
F_15 (sym, prop) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
if ( V_5 -> V_18 . V_27 == V_22 )
continue;
V_38 = F_27 ( V_5 ) ;
if ( V_38 -> V_18 != V_22 )
return V_38 ;
}
V_5 = F_10 ( V_2 ) ;
F_28 (prop->expr, e, def_sym)
if ( V_38 -> V_18 != V_22 )
return V_38 ;
return NULL ;
}
static struct V_1 * F_29 ( struct V_1 * V_2 )
{
struct V_1 * V_38 ;
struct V_4 * V_5 ;
struct V_7 * V_39 ;
V_5 = F_10 ( V_2 ) ;
F_28 (prop->expr, e, def_sym)
F_22 ( V_38 ) ;
V_38 = V_2 -> V_3 [ V_40 ] . V_30 ;
if ( V_38 && V_38 -> V_18 != V_22 )
return V_38 ;
V_38 = F_26 ( V_2 ) ;
if ( V_38 == NULL )
V_2 -> V_29 . V_27 = V_22 ;
return V_38 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_41 V_42 , V_43 ;
struct V_4 * V_5 ;
struct V_7 * V_39 ;
if ( ! V_2 )
return;
if ( V_2 -> V_13 & V_44 )
return;
V_2 -> V_13 |= V_44 ;
V_43 = V_2 -> V_29 ;
switch ( V_2 -> type ) {
case V_23 :
case V_24 :
case V_12 :
V_42 = V_45 . V_29 ;
break;
case V_20 :
case V_17 :
V_42 = V_46 . V_29 ;
break;
default:
V_2 -> V_29 . V_30 = V_2 -> V_47 ;
V_2 -> V_29 . V_27 = V_22 ;
return;
}
if ( ! F_8 ( V_2 ) )
V_2 -> V_13 &= ~ V_48 ;
F_22 ( V_2 ) ;
V_2 -> V_29 = V_42 ;
switch ( F_7 ( V_2 ) ) {
case V_20 :
case V_17 :
if ( F_8 ( V_2 ) && V_2 -> V_18 == V_19 ) {
V_5 = F_10 ( V_2 ) ;
V_42 . V_27 = ( F_27 ( V_5 ) -> V_29 . V_30 == V_2 ) ? V_19 : V_22 ;
} else {
if ( V_2 -> V_18 != V_22 ) {
V_2 -> V_13 |= V_48 ;
if ( F_30 ( V_2 ) ) {
V_42 . V_27 = F_31 ( V_2 -> V_3 [ V_40 ] . V_27 ,
V_2 -> V_18 ) ;
goto V_49;
}
}
if ( V_2 -> V_37 . V_27 != V_22 )
V_2 -> V_13 |= V_48 ;
if ( ! F_32 ( V_2 ) ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_13 |= V_48 ;
V_42 . V_27 = F_31 ( F_16 ( V_5 -> V_7 ) ,
V_5 -> V_18 . V_27 ) ;
}
}
V_49:
if ( V_2 -> V_36 . V_27 == V_22 && V_2 -> V_37 . V_27 != V_22 ) {
struct V_7 * V_39 ;
V_39 = F_33 ( V_2 -> V_37 . V_7 ,
V_2 -> V_36 . V_7 ) ;
fprintf ( V_50 , L_11 ) ;
F_34 ( V_39 , V_50 ) ;
fprintf ( V_50 , L_12 ,
V_2 -> V_47 ) ;
F_34 ( V_2 -> V_36 . V_7 , V_50 ) ;
fprintf ( V_50 , L_13 ) ;
F_35 ( V_39 ) ;
}
V_42 . V_27 = F_24 ( V_42 . V_27 , V_2 -> V_37 . V_27 ) ;
}
if ( V_42 . V_27 == V_35 && F_7 ( V_2 ) == V_20 )
V_42 . V_27 = V_19 ;
break;
case V_12 :
case V_24 :
case V_23 :
if ( V_2 -> V_18 != V_22 ) {
V_2 -> V_13 |= V_48 ;
if ( F_30 ( V_2 ) ) {
V_42 . V_30 = V_2 -> V_3 [ V_40 ] . V_30 ;
break;
}
}
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
struct V_1 * V_51 = F_27 ( V_5 ) ;
if ( V_51 ) {
V_2 -> V_13 |= V_48 ;
F_19 ( V_51 ) ;
V_42 . V_30 = V_51 -> V_29 . V_30 ;
}
}
break;
default:
;
}
V_2 -> V_29 = V_42 ;
if ( F_32 ( V_2 ) && V_42 . V_27 == V_19 )
V_2 -> V_29 . V_30 = F_29 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( memcmp ( & V_43 , & V_2 -> V_29 , sizeof( V_43 ) ) ) {
F_25 ( V_2 ) ;
if ( V_52 == V_2 ) {
F_36 () ;
V_21 = V_52 -> V_29 . V_27 ;
}
}
if ( F_32 ( V_2 ) ) {
struct V_1 * V_53 ;
V_5 = F_10 ( V_2 ) ;
F_28 (prop->expr, e, choice_sym) {
if ( ( V_2 -> V_13 & V_48 ) &&
V_53 -> V_18 != V_22 )
V_53 -> V_13 |= V_48 ;
if ( V_2 -> V_13 & V_54 )
F_25 ( V_53 ) ;
}
}
if ( V_2 -> V_13 & V_14 )
V_2 -> V_13 &= ~ V_48 ;
}
void F_37 ( void )
{
struct V_1 * V_2 ;
int V_55 ;
F_38 (i, sym)
V_2 -> V_13 &= ~ V_44 ;
F_39 ( 1 ) ;
if ( V_52 )
F_19 ( V_52 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_2 -> V_13 |= V_54 ;
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_56 ) {
if ( V_5 -> V_57 )
V_5 -> V_57 -> V_13 |= V_58 ;
}
}
void F_36 ( void )
{
struct V_1 * V_2 ;
int V_55 ;
F_38 (i, sym)
F_25 ( V_2 ) ;
}
bool F_40 ( struct V_1 * V_2 , T_1 V_30 )
{
int type = F_7 ( V_2 ) ;
if ( V_2 -> V_18 == V_22 )
return false ;
if ( type != V_20 && type != V_17 )
return false ;
if ( type == V_20 && V_30 == V_35 )
return false ;
if ( V_2 -> V_18 <= V_2 -> V_37 . V_27 )
return false ;
if ( F_8 ( V_2 ) && V_2 -> V_18 == V_19 )
return V_30 == V_19 ;
return V_30 >= V_2 -> V_37 . V_27 && V_30 <= V_2 -> V_18 ;
}
bool F_41 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_43 = F_42 ( V_2 ) ;
if ( V_43 != V_30 && ! F_40 ( V_2 , V_30 ) )
return false ;
if ( ! ( V_2 -> V_13 & V_59 ) ) {
V_2 -> V_13 |= V_59 ;
F_25 ( V_2 ) ;
}
if ( F_8 ( V_2 ) && V_30 == V_19 ) {
struct V_1 * V_60 = F_27 ( F_10 ( V_2 ) ) ;
struct V_4 * V_5 ;
struct V_7 * V_39 ;
V_60 -> V_3 [ V_40 ] . V_30 = V_2 ;
V_60 -> V_13 |= V_59 ;
V_5 = F_10 ( V_60 ) ;
for ( V_39 = V_5 -> V_7 ; V_39 ; V_39 = V_39 -> V_33 . V_7 ) {
if ( V_39 -> V_34 . V_2 -> V_18 != V_22 )
V_39 -> V_34 . V_2 -> V_13 |= V_59 ;
}
}
V_2 -> V_3 [ V_40 ] . V_27 = V_30 ;
if ( V_43 != V_30 )
F_37 () ;
return true ;
}
T_1 F_43 ( struct V_1 * V_2 )
{
T_1 V_43 , V_42 ;
V_43 = V_42 = F_42 ( V_2 ) ;
do {
switch ( V_42 ) {
case V_22 :
V_42 = V_35 ;
break;
case V_35 :
V_42 = V_19 ;
break;
case V_19 :
V_42 = V_22 ;
break;
}
if ( F_41 ( V_2 , V_42 ) )
break;
} while ( V_43 != V_42 );
return V_42 ;
}
bool F_44 ( struct V_1 * V_2 , const char * V_32 )
{
signed char V_61 ;
switch ( V_2 -> type ) {
case V_12 :
return true ;
case V_23 :
V_61 = * V_32 ++ ;
if ( V_61 == '-' )
V_61 = * V_32 ++ ;
if ( ! isdigit ( V_61 ) )
return false ;
if ( V_61 == '0' && * V_32 != 0 )
return false ;
while ( ( V_61 = * V_32 ++ ) ) {
if ( ! isdigit ( V_61 ) )
return false ;
}
return true ;
case V_24 :
if ( V_32 [ 0 ] == '0' && ( V_32 [ 1 ] == 'x' || V_32 [ 1 ] == 'X' ) )
V_32 += 2 ;
V_61 = * V_32 ++ ;
do {
if ( ! isxdigit ( V_61 ) )
return false ;
} while ( ( V_61 = * V_32 ++ ) );
return true ;
case V_20 :
case V_17 :
switch ( V_32 [ 0 ] ) {
case 'y' : case 'Y' :
case 'm' : case 'M' :
case 'n' : case 'N' :
return true ;
}
return false ;
default:
return false ;
}
}
bool F_45 ( struct V_1 * V_2 , const char * V_32 )
{
struct V_4 * V_5 ;
int V_30 ;
switch ( V_2 -> type ) {
case V_12 :
return F_44 ( V_2 , V_32 ) ;
case V_23 :
if ( ! F_44 ( V_2 , V_32 ) )
return false ;
V_5 = F_17 ( V_2 ) ;
if ( ! V_5 )
return true ;
V_30 = strtol ( V_32 , NULL , 10 ) ;
return V_30 >= F_18 ( V_5 -> V_7 -> V_33 . V_2 , 10 ) &&
V_30 <= F_18 ( V_5 -> V_7 -> V_34 . V_2 , 10 ) ;
case V_24 :
if ( ! F_44 ( V_2 , V_32 ) )
return false ;
V_5 = F_17 ( V_2 ) ;
if ( ! V_5 )
return true ;
V_30 = strtol ( V_32 , NULL , 16 ) ;
return V_30 >= F_18 ( V_5 -> V_7 -> V_33 . V_2 , 16 ) &&
V_30 <= F_18 ( V_5 -> V_7 -> V_34 . V_2 , 16 ) ;
case V_20 :
case V_17 :
switch ( V_32 [ 0 ] ) {
case 'y' : case 'Y' :
return F_40 ( V_2 , V_19 ) ;
case 'm' : case 'M' :
return F_40 ( V_2 , V_35 ) ;
case 'n' : case 'N' :
return F_40 ( V_2 , V_22 ) ;
}
return false ;
default:
return false ;
}
}
bool F_46 ( struct V_1 * V_2 , const char * V_42 )
{
const char * V_43 ;
char * V_30 ;
int V_62 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
switch ( V_42 [ 0 ] ) {
case 'y' : case 'Y' :
return F_41 ( V_2 , V_19 ) ;
case 'm' : case 'M' :
return F_41 ( V_2 , V_35 ) ;
case 'n' : case 'N' :
return F_41 ( V_2 , V_22 ) ;
}
return false ;
default:
;
}
if ( ! F_45 ( V_2 , V_42 ) )
return false ;
if ( ! ( V_2 -> V_13 & V_59 ) ) {
V_2 -> V_13 |= V_59 ;
F_25 ( V_2 ) ;
}
V_43 = V_2 -> V_3 [ V_40 ] . V_30 ;
V_62 = strlen ( V_42 ) + 1 ;
if ( V_2 -> type == V_24 && ( V_42 [ 0 ] != '0' || ( V_42 [ 1 ] != 'x' && V_42 [ 1 ] != 'X' ) ) ) {
V_62 += 2 ;
V_2 -> V_3 [ V_40 ] . V_30 = V_30 = malloc ( V_62 ) ;
* V_30 ++ = '0' ;
* V_30 ++ = 'x' ;
} else if ( ! V_43 || strcmp ( V_43 , V_42 ) )
V_2 -> V_3 [ V_40 ] . V_30 = V_30 = malloc ( V_62 ) ;
else
return true ;
strcpy ( V_30 , V_42 ) ;
free ( ( void * ) V_43 ) ;
F_37 () ;
return true ;
}
const char * F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_1 * V_51 ;
const char * V_32 ;
T_1 V_30 ;
F_22 ( V_2 ) ;
F_19 ( V_52 ) ;
V_30 = V_46 . V_29 . V_27 ;
V_32 = V_45 . V_29 . V_30 ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 != NULL ) {
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
V_30 = F_31 ( F_16 ( V_5 -> V_7 ) , V_5 -> V_18 . V_27 ) ;
break;
default:
V_51 = F_27 ( V_5 ) ;
if ( V_51 != NULL ) {
F_19 ( V_51 ) ;
V_32 = ( const char * ) V_51 -> V_29 . V_30 ;
}
}
}
V_30 = F_24 ( V_30 , V_2 -> V_37 . V_27 ) ;
if ( V_30 == V_35 )
if ( ! F_8 ( V_2 ) && V_52 -> V_29 . V_27 == V_22 )
V_30 = V_19 ;
if ( V_2 -> type == V_20 && V_30 == V_35 )
V_30 = V_19 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
switch ( V_30 ) {
case V_22 : return L_14 ;
case V_35 : return L_15 ;
case V_19 : return L_16 ;
}
case V_23 :
case V_24 :
return V_32 ;
case V_12 :
return V_32 ;
case V_26 :
case V_25 :
break;
}
return L_17 ;
}
const char * F_48 ( struct V_1 * V_2 )
{
T_1 V_30 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
V_30 = F_42 ( V_2 ) ;
switch ( V_30 ) {
case V_22 :
return L_14 ;
case V_35 :
return L_15 ;
case V_19 :
return L_16 ;
}
break;
default:
;
}
return ( const char * ) V_2 -> V_29 . V_30 ;
}
bool F_49 ( struct V_1 * V_2 )
{
return V_2 -> V_18 > V_2 -> V_37 . V_27 ;
}
static unsigned F_50 ( const char * V_63 )
{
unsigned V_64 = 2166136261U ;
for (; * V_63 ; V_63 ++ )
V_64 = ( V_64 ^ * V_63 ) * 0x01000193 ;
return V_64 ;
}
struct V_1 * F_4 ( const char * V_47 , int V_13 )
{
struct V_1 * V_1 ;
char * V_65 ;
int V_64 ;
if ( V_47 ) {
if ( V_47 [ 0 ] && ! V_47 [ 1 ] ) {
switch ( V_47 [ 0 ] ) {
case 'y' : return & V_66 ;
case 'm' : return & V_67 ;
case 'n' : return & V_46 ;
}
}
V_64 = F_50 ( V_47 ) % V_68 ;
for ( V_1 = V_69 [ V_64 ] ; V_1 ; V_1 = V_1 -> V_56 ) {
if ( V_1 -> V_47 &&
! strcmp ( V_1 -> V_47 , V_47 ) &&
( V_13 ? V_1 -> V_13 & V_13
: ! ( V_1 -> V_13 & ( V_8 | V_70 ) ) ) )
return V_1 ;
}
V_65 = F_21 ( V_47 ) ;
} else {
V_65 = NULL ;
V_64 = 0 ;
}
V_1 = malloc ( sizeof( * V_1 ) ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_47 = V_65 ;
V_1 -> type = V_25 ;
V_1 -> V_13 |= V_13 ;
V_1 -> V_56 = V_69 [ V_64 ] ;
V_69 [ V_64 ] = V_1 ;
return V_1 ;
}
struct V_1 * F_51 ( const char * V_47 )
{
struct V_1 * V_1 = NULL ;
int V_64 = 0 ;
if ( ! V_47 )
return NULL ;
if ( V_47 [ 0 ] && ! V_47 [ 1 ] ) {
switch ( V_47 [ 0 ] ) {
case 'y' : return & V_66 ;
case 'm' : return & V_67 ;
case 'n' : return & V_46 ;
}
}
V_64 = F_50 ( V_47 ) % V_68 ;
for ( V_1 = V_69 [ V_64 ] ; V_1 ; V_1 = V_1 -> V_56 ) {
if ( V_1 -> V_47 &&
! strcmp ( V_1 -> V_47 , V_47 ) &&
! ( V_1 -> V_13 & V_8 ) )
break;
}
return V_1 ;
}
const char * F_52 ( const char * V_71 )
{
const char * V_72 ;
char * V_73 ;
T_2 V_74 ;
V_74 = strlen ( V_71 ) + 1 ;
V_73 = malloc ( V_74 ) ;
V_73 [ 0 ] = '\0' ;
while ( ( V_72 = strchr ( V_71 , '$' ) ) ) {
char * V_75 , V_47 [ V_76 ] ;
const char * V_77 = L_17 ;
struct V_1 * V_2 ;
T_2 V_78 ;
strncat ( V_73 , V_71 , V_72 - V_71 ) ;
V_72 ++ ;
V_75 = V_47 ;
while ( isalnum ( * V_72 ) || * V_72 == '_' )
* V_75 ++ = * V_72 ++ ;
* V_75 = '\0' ;
V_2 = F_51 ( V_47 ) ;
if ( V_2 != NULL ) {
F_19 ( V_2 ) ;
V_77 = F_48 ( V_2 ) ;
}
V_78 = strlen ( V_73 ) + strlen ( V_77 ) + strlen ( V_72 ) + 1 ;
if ( V_78 > V_74 ) {
V_74 = V_78 ;
V_73 = realloc ( V_73 , V_74 ) ;
}
strcat ( V_73 , V_77 ) ;
V_71 = V_72 ;
}
strcat ( V_73 , V_71 ) ;
return V_73 ;
}
struct V_1 * * F_53 ( const char * V_79 )
{
struct V_1 * V_2 , * * V_80 = NULL ;
int V_55 , V_81 , V_62 ;
T_3 V_82 ;
V_81 = V_62 = 0 ;
if ( strlen ( V_79 ) == 0 )
return NULL ;
if ( regcomp ( & V_82 , V_79 , V_83 | V_84 | V_85 ) )
return NULL ;
F_38 (i, sym) {
if ( V_2 -> V_13 & V_8 || ! V_2 -> V_47 )
continue;
if ( regexec ( & V_82 , V_2 -> V_47 , 0 , NULL , 0 ) )
continue;
if ( V_81 + 1 >= V_62 ) {
void * V_86 = V_80 ;
V_62 += 16 ;
V_80 = realloc ( V_80 , V_62 * sizeof( struct V_1 * ) ) ;
if ( ! V_80 ) {
free ( V_86 ) ;
return NULL ;
}
}
F_19 ( V_2 ) ;
V_80 [ V_81 ++ ] = V_2 ;
}
if ( V_80 )
V_80 [ V_81 ] = NULL ;
regfree ( & V_82 ) ;
return V_80 ;
}
static void F_54 ( struct V_87 * V_88 , struct V_1 * V_2 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
if ( V_89 )
V_89 -> V_56 = V_88 ;
V_88 -> V_90 = V_89 ;
V_88 -> V_2 = V_2 ;
V_89 = V_88 ;
}
static void F_55 ( void )
{
V_89 = V_89 -> V_90 ;
if ( V_89 )
V_89 -> V_56 = NULL ;
}
static void F_56 ( struct V_1 * V_91 )
{
struct V_87 * V_88 ;
struct V_1 * V_2 , * V_92 ;
struct V_57 * V_57 = NULL ;
struct V_4 * V_5 ;
struct V_87 V_93 ;
if ( F_8 ( V_91 ) ) {
F_54 ( & V_93 , V_91 ) ;
V_91 = F_27 ( F_10 ( V_91 ) ) ;
}
for ( V_88 = V_89 ; V_88 != NULL ; V_88 = V_88 -> V_90 )
if ( V_88 -> V_2 == V_91 )
break;
if ( ! V_88 ) {
fprintf ( V_50 , L_18 ) ;
return;
}
for (; V_88 ; V_88 = V_88 -> V_56 ) {
V_2 = V_88 -> V_2 ;
V_92 = V_88 -> V_56 ? V_88 -> V_56 -> V_2 : V_91 ;
V_5 = V_88 -> V_5 ;
if ( V_5 == NULL )
V_5 = V_88 -> V_2 -> V_5 ;
if ( F_32 ( V_2 ) || F_8 ( V_2 ) ) {
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_56 ) {
V_57 = V_5 -> V_57 ;
if ( V_5 -> V_57 )
break;
}
}
if ( V_88 -> V_2 == V_91 )
fprintf ( V_50 , L_19 ,
V_5 -> V_94 -> V_47 , V_5 -> V_95 ) ;
if ( V_88 -> V_7 ) {
fprintf ( V_50 , L_20 ,
V_5 -> V_94 -> V_47 , V_5 -> V_95 ,
V_2 -> V_47 ? V_2 -> V_47 : L_21 ,
F_57 ( V_5 -> type ) ,
V_92 -> V_47 ? V_92 -> V_47 : L_21 ) ;
} else if ( V_88 -> V_5 ) {
fprintf ( V_50 , L_22 ,
V_5 -> V_94 -> V_47 , V_5 -> V_95 ,
V_2 -> V_47 ? V_2 -> V_47 : L_21 ,
V_92 -> V_47 ? V_92 -> V_47 : L_21 ) ;
} else if ( F_32 ( V_2 ) ) {
fprintf ( V_50 , L_23 ,
V_57 -> V_94 -> V_47 , V_57 -> V_95 ,
V_2 -> V_47 ? V_2 -> V_47 : L_21 ,
V_92 -> V_47 ? V_92 -> V_47 : L_21 ) ;
} else if ( F_8 ( V_2 ) ) {
fprintf ( V_50 , L_24 ,
V_57 -> V_94 -> V_47 , V_57 -> V_95 ,
V_2 -> V_47 ? V_2 -> V_47 : L_21 ,
V_92 -> V_47 ? V_92 -> V_47 : L_21 ) ;
} else {
fprintf ( V_50 , L_25 ,
V_5 -> V_94 -> V_47 , V_5 -> V_95 ,
V_2 -> V_47 ? V_2 -> V_47 : L_21 ,
V_92 -> V_47 ? V_92 -> V_47 : L_21 ) ;
}
}
if ( V_89 == & V_93 )
F_55 () ;
}
static struct V_1 * F_58 ( struct V_7 * V_39 )
{
struct V_1 * V_2 ;
if ( ! V_39 )
return NULL ;
switch ( V_39 -> type ) {
case V_96 :
case V_97 :
V_2 = F_58 ( V_39 -> V_33 . V_7 ) ;
if ( V_2 )
return V_2 ;
return F_58 ( V_39 -> V_34 . V_7 ) ;
case V_98 :
return F_58 ( V_39 -> V_33 . V_7 ) ;
case V_99 :
case V_100 :
V_2 = F_59 ( V_39 -> V_33 . V_2 ) ;
if ( V_2 )
return V_2 ;
return F_59 ( V_39 -> V_34 . V_2 ) ;
case V_101 :
return F_59 ( V_39 -> V_33 . V_2 ) ;
default:
break;
}
printf ( L_26 , V_39 -> type ) ;
return NULL ;
}
static struct V_1 * F_60 ( struct V_1 * V_2 )
{
struct V_1 * V_102 ;
struct V_4 * V_5 ;
struct V_87 V_88 ;
F_54 ( & V_88 , V_2 ) ;
V_102 = F_58 ( V_2 -> V_37 . V_7 ) ;
if ( V_102 )
goto V_103;
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_56 ) {
if ( V_5 -> type == V_104 || V_5 -> type == V_105 )
continue;
V_88 . V_5 = V_5 ;
V_102 = F_58 ( V_5 -> V_18 . V_7 ) ;
if ( V_102 )
break;
if ( V_5 -> type != V_6 || F_32 ( V_2 ) )
continue;
V_88 . V_7 = V_5 -> V_7 ;
V_102 = F_58 ( V_5 -> V_7 ) ;
if ( V_102 )
break;
V_88 . V_7 = NULL ;
}
V_103:
F_55 () ;
return V_102 ;
}
static struct V_1 * F_61 ( struct V_1 * V_106 )
{
struct V_1 * V_2 , * V_102 ;
struct V_4 * V_5 ;
struct V_7 * V_39 ;
struct V_87 V_88 ;
F_54 ( & V_88 , V_106 ) ;
V_5 = F_10 ( V_106 ) ;
F_28 (prop->expr, e, sym)
V_2 -> V_13 |= ( V_107 | V_108 ) ;
V_106 -> V_13 |= ( V_107 | V_108 ) ;
V_102 = F_60 ( V_106 ) ;
V_106 -> V_13 &= ~ V_107 ;
if ( V_102 )
goto V_103;
F_28 (prop->expr, e, sym) {
V_102 = F_60 ( V_2 ) ;
if ( V_102 )
break;
}
V_103:
F_28 (prop->expr, e, sym)
V_2 -> V_13 &= ~ V_107 ;
if ( V_102 && F_8 ( V_102 ) &&
F_27 ( F_10 ( V_102 ) ) == V_106 )
V_102 = V_106 ;
F_55 () ;
return V_102 ;
}
struct V_1 * F_59 ( struct V_1 * V_2 )
{
struct V_1 * V_102 ;
struct V_4 * V_5 ;
if ( V_2 -> V_13 & V_107 ) {
F_56 ( V_2 ) ;
return V_2 ;
}
if ( V_2 -> V_13 & V_108 )
return NULL ;
if ( F_8 ( V_2 ) ) {
struct V_87 V_88 ;
F_54 ( & V_88 , V_2 ) ;
V_5 = F_10 ( V_2 ) ;
V_102 = F_59 ( F_27 ( V_5 ) ) ;
F_55 () ;
} else if ( F_32 ( V_2 ) ) {
V_102 = F_61 ( V_2 ) ;
} else {
V_2 -> V_13 |= ( V_107 | V_108 ) ;
V_102 = F_60 ( V_2 ) ;
V_2 -> V_13 &= ~ V_107 ;
}
if ( V_102 && V_102 == V_2 )
V_102 = NULL ;
return V_102 ;
}
struct V_4 * F_2 ( enum V_109 type , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_4 * * V_110 ;
V_5 = malloc ( sizeof( * V_5 ) ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> type = type ;
V_5 -> V_2 = V_2 ;
V_5 -> V_94 = V_111 ;
V_5 -> V_95 = F_62 () ;
if ( V_2 ) {
for ( V_110 = & V_2 -> V_5 ; * V_110 ; V_110 = & ( * V_110 ) -> V_56 )
;
* V_110 = V_5 ;
}
return V_5 ;
}
struct V_1 * F_27 ( struct V_4 * V_5 )
{
if ( V_5 -> V_7 && ( V_5 -> V_7 -> type == V_101 ||
V_5 -> V_7 -> type == V_112 ) )
return V_5 -> V_7 -> V_33 . V_2 ;
return NULL ;
}
const char * F_57 ( enum V_109 type )
{
switch ( type ) {
case V_113 :
return L_27 ;
case V_114 :
return L_28 ;
case V_115 :
return L_29 ;
case V_116 :
return L_30 ;
case V_6 :
return L_31 ;
case V_104 :
return L_32 ;
case V_105 :
return L_33 ;
case V_117 :
return L_34 ;
case V_118 :
return L_35 ;
case V_119 :
break;
}
return L_7 ;
}
static void F_63 ( const char * V_120 )
{
struct V_1 * V_2 , * V_102 ;
struct V_4 * V_5 ;
char * V_75 ;
V_2 = V_121 -> V_2 ;
V_2 -> V_13 |= V_14 ;
F_13 (sym, prop, P_ENV) {
V_102 = F_27 ( V_5 ) ;
if ( strcmp ( V_102 -> V_47 , V_120 ) )
F_64 ( V_121 , L_36 ,
V_102 -> V_47 ) ;
return;
}
V_5 = F_2 ( V_114 , V_2 ) ;
V_5 -> V_7 = F_3 ( F_4 ( V_120 , V_8 ) ) ;
V_122 = F_65 ( V_112 , V_122 ) ;
V_122 -> V_34 . V_2 = V_2 ;
V_75 = getenv ( V_120 ) ;
if ( V_75 )
F_1 ( V_2 , V_75 ) ;
else
F_64 ( V_121 , L_37 , V_120 ) ;
}
