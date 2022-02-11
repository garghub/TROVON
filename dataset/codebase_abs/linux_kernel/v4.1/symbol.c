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
static struct V_4 * F_14 ( struct V_1 * V_2 )
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
static long long F_18 ( struct V_1 * V_2 , int V_28 )
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
return strtoll ( V_2 -> V_29 . V_30 , NULL , V_28 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_28 ;
long long V_30 , V_31 ;
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
V_30 = strtoll ( V_2 -> V_29 . V_30 , NULL , V_28 ) ;
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
V_2 -> V_13 |= V_35 ;
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_36 ) {
if ( V_5 -> V_37 )
V_5 -> V_37 -> V_13 |= V_38 ;
}
}
static void F_23 ( void )
{
struct V_1 * V_2 ;
int V_39 ;
F_24 (i, sym)
F_22 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_1 V_27 ;
V_27 = V_22 ;
F_26 (sym, prop) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
V_27 = F_27 ( V_27 , V_5 -> V_18 . V_27 ) ;
}
if ( V_27 == V_40 && ( V_2 -> type != V_17 || V_21 == V_22 ) )
V_27 = V_19 ;
if ( V_2 -> V_18 != V_27 ) {
V_2 -> V_18 = V_27 ;
F_22 ( V_2 ) ;
}
if ( F_8 ( V_2 ) )
return;
V_27 = V_19 ;
if ( V_2 -> V_41 . V_7 )
V_27 = F_16 ( V_2 -> V_41 . V_7 ) ;
if ( V_27 == V_40 )
V_27 = V_19 ;
if ( V_2 -> V_41 . V_27 != V_27 ) {
V_2 -> V_41 . V_27 = V_27 ;
F_22 ( V_2 ) ;
}
V_27 = V_22 ;
if ( V_2 -> V_42 . V_7 )
V_27 = F_16 ( V_2 -> V_42 . V_7 ) ;
if ( V_27 == V_40 && F_7 ( V_2 ) == V_20 )
V_27 = V_19 ;
if ( V_2 -> V_42 . V_27 != V_27 ) {
V_2 -> V_42 . V_27 = V_27 ;
F_22 ( V_2 ) ;
}
}
struct V_1 * F_28 ( struct V_1 * V_2 )
{
struct V_1 * V_43 ;
struct V_4 * V_5 ;
struct V_7 * V_44 ;
F_15 (sym, prop) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
if ( V_5 -> V_18 . V_27 == V_22 )
continue;
V_43 = F_29 ( V_5 ) ;
if ( V_43 -> V_18 != V_22 )
return V_43 ;
}
V_5 = F_10 ( V_2 ) ;
F_30 (prop->expr, e, def_sym)
if ( V_43 -> V_18 != V_22 )
return V_43 ;
return NULL ;
}
static struct V_1 * F_31 ( struct V_1 * V_2 )
{
struct V_1 * V_43 ;
struct V_4 * V_5 ;
struct V_7 * V_44 ;
int V_13 ;
V_13 = V_2 -> V_13 ;
V_5 = F_10 ( V_2 ) ;
F_30 (prop->expr, e, def_sym) {
F_25 ( V_43 ) ;
if ( V_43 -> V_18 != V_22 )
V_13 &= V_43 -> V_13 ;
}
V_2 -> V_13 &= V_13 | ~ V_45 ;
V_43 = V_2 -> V_3 [ V_46 ] . V_30 ;
if ( V_43 && V_43 -> V_18 != V_22 )
return V_43 ;
V_43 = F_28 ( V_2 ) ;
if ( V_43 == NULL )
V_2 -> V_29 . V_27 = V_22 ;
return V_43 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_47 V_48 , V_49 ;
struct V_4 * V_5 ;
struct V_7 * V_44 ;
if ( ! V_2 )
return;
if ( V_2 -> V_13 & V_50 )
return;
if ( F_8 ( V_2 ) &&
V_2 -> V_13 & V_51 ) {
V_2 -> V_13 &= ~ V_51 ;
V_5 = F_10 ( V_2 ) ;
F_19 ( F_29 ( V_5 ) ) ;
}
V_2 -> V_13 |= V_50 ;
V_49 = V_2 -> V_29 ;
switch ( V_2 -> type ) {
case V_23 :
case V_24 :
case V_12 :
V_48 = V_52 . V_29 ;
break;
case V_20 :
case V_17 :
V_48 = V_53 . V_29 ;
break;
default:
V_2 -> V_29 . V_30 = V_2 -> V_54 ;
V_2 -> V_29 . V_27 = V_22 ;
return;
}
if ( ! F_8 ( V_2 ) )
V_2 -> V_13 &= ~ V_55 ;
F_25 ( V_2 ) ;
V_2 -> V_29 = V_48 ;
switch ( F_7 ( V_2 ) ) {
case V_20 :
case V_17 :
if ( F_8 ( V_2 ) && V_2 -> V_18 == V_19 ) {
V_5 = F_10 ( V_2 ) ;
V_48 . V_27 = ( F_29 ( V_5 ) -> V_29 . V_30 == V_2 ) ? V_19 : V_22 ;
} else {
if ( V_2 -> V_18 != V_22 ) {
V_2 -> V_13 |= V_55 ;
if ( F_32 ( V_2 ) ) {
V_48 . V_27 = F_33 ( V_2 -> V_3 [ V_46 ] . V_27 ,
V_2 -> V_18 ) ;
goto V_56;
}
}
if ( V_2 -> V_42 . V_27 != V_22 )
V_2 -> V_13 |= V_55 ;
if ( ! F_34 ( V_2 ) ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_13 |= V_55 ;
V_48 . V_27 = F_33 ( F_16 ( V_5 -> V_7 ) ,
V_5 -> V_18 . V_27 ) ;
}
}
V_56:
if ( V_2 -> V_41 . V_27 == V_22 && V_2 -> V_42 . V_27 != V_22 ) {
struct V_7 * V_44 ;
V_44 = F_35 ( V_2 -> V_42 . V_7 ,
V_2 -> V_41 . V_7 ) ;
fprintf ( V_57 , L_11 ) ;
F_36 ( V_44 , V_57 ) ;
fprintf ( V_57 , L_12 ,
V_2 -> V_54 ) ;
F_36 ( V_2 -> V_41 . V_7 , V_57 ) ;
fprintf ( V_57 , L_13 ) ;
F_37 ( V_44 ) ;
}
V_48 . V_27 = F_27 ( V_48 . V_27 , V_2 -> V_42 . V_27 ) ;
}
if ( V_48 . V_27 == V_40 && F_7 ( V_2 ) == V_20 )
V_48 . V_27 = V_19 ;
break;
case V_12 :
case V_24 :
case V_23 :
if ( V_2 -> V_18 != V_22 ) {
V_2 -> V_13 |= V_55 ;
if ( F_32 ( V_2 ) ) {
V_48 . V_30 = V_2 -> V_3 [ V_46 ] . V_30 ;
break;
}
}
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
struct V_1 * V_58 = F_29 ( V_5 ) ;
if ( V_58 ) {
V_2 -> V_13 |= V_55 ;
F_19 ( V_58 ) ;
V_48 . V_30 = V_58 -> V_29 . V_30 ;
}
}
break;
default:
;
}
V_2 -> V_29 = V_48 ;
if ( F_34 ( V_2 ) && V_48 . V_27 == V_19 )
V_2 -> V_29 . V_30 = F_31 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( memcmp ( & V_49 , & V_2 -> V_29 , sizeof( V_49 ) ) ) {
F_22 ( V_2 ) ;
if ( V_59 == V_2 ) {
F_23 () ;
V_21 = V_59 -> V_29 . V_27 ;
}
}
if ( F_34 ( V_2 ) ) {
struct V_1 * V_60 ;
V_5 = F_10 ( V_2 ) ;
F_30 (prop->expr, e, choice_sym) {
if ( ( V_2 -> V_13 & V_55 ) &&
V_60 -> V_18 != V_22 )
V_60 -> V_13 |= V_55 ;
if ( V_2 -> V_13 & V_35 )
F_22 ( V_60 ) ;
}
}
if ( V_2 -> V_13 & V_14 )
V_2 -> V_13 &= ~ V_55 ;
if ( V_2 -> V_13 & V_51 )
F_38 ( V_2 ) ;
}
void F_39 ( void )
{
struct V_1 * V_2 ;
int V_39 ;
F_24 (i, sym)
V_2 -> V_13 &= ~ V_50 ;
F_40 ( 1 ) ;
if ( V_59 )
F_19 ( V_59 ) ;
}
bool F_41 ( struct V_1 * V_2 , T_1 V_30 )
{
int type = F_7 ( V_2 ) ;
if ( V_2 -> V_18 == V_22 )
return false ;
if ( type != V_20 && type != V_17 )
return false ;
if ( type == V_20 && V_30 == V_40 )
return false ;
if ( V_2 -> V_18 <= V_2 -> V_42 . V_27 )
return false ;
if ( F_8 ( V_2 ) && V_2 -> V_18 == V_19 )
return V_30 == V_19 ;
return V_30 >= V_2 -> V_42 . V_27 && V_30 <= V_2 -> V_18 ;
}
bool F_42 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_49 = F_43 ( V_2 ) ;
if ( V_49 != V_30 && ! F_41 ( V_2 , V_30 ) )
return false ;
if ( ! ( V_2 -> V_13 & V_45 ) ) {
V_2 -> V_13 |= V_45 ;
F_22 ( V_2 ) ;
}
if ( F_8 ( V_2 ) && V_30 == V_19 ) {
struct V_1 * V_61 = F_29 ( F_10 ( V_2 ) ) ;
struct V_4 * V_5 ;
struct V_7 * V_44 ;
V_61 -> V_3 [ V_46 ] . V_30 = V_2 ;
V_61 -> V_13 |= V_45 ;
V_5 = F_10 ( V_61 ) ;
for ( V_44 = V_5 -> V_7 ; V_44 ; V_44 = V_44 -> V_33 . V_7 ) {
if ( V_44 -> V_34 . V_2 -> V_18 != V_22 )
V_44 -> V_34 . V_2 -> V_13 |= V_45 ;
}
}
V_2 -> V_3 [ V_46 ] . V_27 = V_30 ;
if ( V_49 != V_30 )
F_39 () ;
return true ;
}
T_1 F_44 ( struct V_1 * V_2 )
{
T_1 V_49 , V_48 ;
V_49 = V_48 = F_43 ( V_2 ) ;
do {
switch ( V_48 ) {
case V_22 :
V_48 = V_40 ;
break;
case V_40 :
V_48 = V_19 ;
break;
case V_19 :
V_48 = V_22 ;
break;
}
if ( F_42 ( V_2 , V_48 ) )
break;
} while ( V_49 != V_48 );
return V_48 ;
}
bool F_45 ( struct V_1 * V_2 , const char * V_32 )
{
signed char V_62 ;
switch ( V_2 -> type ) {
case V_12 :
return true ;
case V_23 :
V_62 = * V_32 ++ ;
if ( V_62 == '-' )
V_62 = * V_32 ++ ;
if ( ! isdigit ( V_62 ) )
return false ;
if ( V_62 == '0' && * V_32 != 0 )
return false ;
while ( ( V_62 = * V_32 ++ ) ) {
if ( ! isdigit ( V_62 ) )
return false ;
}
return true ;
case V_24 :
if ( V_32 [ 0 ] == '0' && ( V_32 [ 1 ] == 'x' || V_32 [ 1 ] == 'X' ) )
V_32 += 2 ;
V_62 = * V_32 ++ ;
do {
if ( ! isxdigit ( V_62 ) )
return false ;
} while ( ( V_62 = * V_32 ++ ) );
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
bool F_46 ( struct V_1 * V_2 , const char * V_32 )
{
struct V_4 * V_5 ;
long long V_30 ;
switch ( V_2 -> type ) {
case V_12 :
return F_45 ( V_2 , V_32 ) ;
case V_23 :
if ( ! F_45 ( V_2 , V_32 ) )
return false ;
V_5 = F_17 ( V_2 ) ;
if ( ! V_5 )
return true ;
V_30 = strtoll ( V_32 , NULL , 10 ) ;
return V_30 >= F_18 ( V_5 -> V_7 -> V_33 . V_2 , 10 ) &&
V_30 <= F_18 ( V_5 -> V_7 -> V_34 . V_2 , 10 ) ;
case V_24 :
if ( ! F_45 ( V_2 , V_32 ) )
return false ;
V_5 = F_17 ( V_2 ) ;
if ( ! V_5 )
return true ;
V_30 = strtoll ( V_32 , NULL , 16 ) ;
return V_30 >= F_18 ( V_5 -> V_7 -> V_33 . V_2 , 16 ) &&
V_30 <= F_18 ( V_5 -> V_7 -> V_34 . V_2 , 16 ) ;
case V_20 :
case V_17 :
switch ( V_32 [ 0 ] ) {
case 'y' : case 'Y' :
return F_41 ( V_2 , V_19 ) ;
case 'm' : case 'M' :
return F_41 ( V_2 , V_40 ) ;
case 'n' : case 'N' :
return F_41 ( V_2 , V_22 ) ;
}
return false ;
default:
return false ;
}
}
bool F_47 ( struct V_1 * V_2 , const char * V_48 )
{
const char * V_49 ;
char * V_30 ;
int V_63 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
switch ( V_48 [ 0 ] ) {
case 'y' : case 'Y' :
return F_42 ( V_2 , V_19 ) ;
case 'm' : case 'M' :
return F_42 ( V_2 , V_40 ) ;
case 'n' : case 'N' :
return F_42 ( V_2 , V_22 ) ;
}
return false ;
default:
;
}
if ( ! F_46 ( V_2 , V_48 ) )
return false ;
if ( ! ( V_2 -> V_13 & V_45 ) ) {
V_2 -> V_13 |= V_45 ;
F_22 ( V_2 ) ;
}
V_49 = V_2 -> V_3 [ V_46 ] . V_30 ;
V_63 = strlen ( V_48 ) + 1 ;
if ( V_2 -> type == V_24 && ( V_48 [ 0 ] != '0' || ( V_48 [ 1 ] != 'x' && V_48 [ 1 ] != 'X' ) ) ) {
V_63 += 2 ;
V_2 -> V_3 [ V_46 ] . V_30 = V_30 = xmalloc ( V_63 ) ;
* V_30 ++ = '0' ;
* V_30 ++ = 'x' ;
} else if ( ! V_49 || strcmp ( V_49 , V_48 ) )
V_2 -> V_3 [ V_46 ] . V_30 = V_30 = xmalloc ( V_63 ) ;
else
return true ;
strcpy ( V_30 , V_48 ) ;
free ( ( void * ) V_49 ) ;
F_39 () ;
return true ;
}
const char * F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_1 * V_58 ;
const char * V_32 ;
T_1 V_30 ;
F_25 ( V_2 ) ;
F_19 ( V_59 ) ;
V_30 = V_53 . V_29 . V_27 ;
V_32 = V_52 . V_29 . V_30 ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 != NULL ) {
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
V_30 = F_33 ( F_16 ( V_5 -> V_7 ) , V_5 -> V_18 . V_27 ) ;
break;
default:
V_58 = F_29 ( V_5 ) ;
if ( V_58 != NULL ) {
F_19 ( V_58 ) ;
V_32 = ( const char * ) V_58 -> V_29 . V_30 ;
}
}
}
V_30 = F_27 ( V_30 , V_2 -> V_42 . V_27 ) ;
if ( V_30 == V_40 )
if ( ! F_8 ( V_2 ) && V_59 -> V_29 . V_27 == V_22 )
V_30 = V_19 ;
if ( V_2 -> type == V_20 && V_30 == V_40 )
V_30 = V_19 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
switch ( V_30 ) {
case V_22 : return L_14 ;
case V_40 : return L_15 ;
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
const char * F_49 ( struct V_1 * V_2 )
{
T_1 V_30 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
V_30 = F_43 ( V_2 ) ;
switch ( V_30 ) {
case V_22 :
return L_14 ;
case V_40 :
F_19 ( V_59 ) ;
return ( V_59 -> V_29 . V_27 == V_22 ) ? L_14 : L_15 ;
case V_19 :
return L_16 ;
}
break;
default:
;
}
return ( const char * ) V_2 -> V_29 . V_30 ;
}
bool F_50 ( struct V_1 * V_2 )
{
return V_2 -> V_18 > V_2 -> V_42 . V_27 ;
}
static unsigned F_51 ( const char * V_64 )
{
unsigned V_65 = 2166136261U ;
for (; * V_64 ; V_64 ++ )
V_65 = ( V_65 ^ * V_64 ) * 0x01000193 ;
return V_65 ;
}
struct V_1 * F_4 ( const char * V_54 , int V_13 )
{
struct V_1 * V_1 ;
char * V_66 ;
int V_65 ;
if ( V_54 ) {
if ( V_54 [ 0 ] && ! V_54 [ 1 ] ) {
switch ( V_54 [ 0 ] ) {
case 'y' : return & V_67 ;
case 'm' : return & V_68 ;
case 'n' : return & V_53 ;
}
}
V_65 = F_51 ( V_54 ) % V_69 ;
for ( V_1 = V_70 [ V_65 ] ; V_1 ; V_1 = V_1 -> V_36 ) {
if ( V_1 -> V_54 &&
! strcmp ( V_1 -> V_54 , V_54 ) &&
( V_13 ? V_1 -> V_13 & V_13
: ! ( V_1 -> V_13 & ( V_8 | V_71 ) ) ) )
return V_1 ;
}
V_66 = F_21 ( V_54 ) ;
} else {
V_66 = NULL ;
V_65 = 0 ;
}
V_1 = xmalloc ( sizeof( * V_1 ) ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_54 = V_66 ;
V_1 -> type = V_25 ;
V_1 -> V_13 |= V_13 ;
V_1 -> V_36 = V_70 [ V_65 ] ;
V_70 [ V_65 ] = V_1 ;
return V_1 ;
}
struct V_1 * F_52 ( const char * V_54 )
{
struct V_1 * V_1 = NULL ;
int V_65 = 0 ;
if ( ! V_54 )
return NULL ;
if ( V_54 [ 0 ] && ! V_54 [ 1 ] ) {
switch ( V_54 [ 0 ] ) {
case 'y' : return & V_67 ;
case 'm' : return & V_68 ;
case 'n' : return & V_53 ;
}
}
V_65 = F_51 ( V_54 ) % V_69 ;
for ( V_1 = V_70 [ V_65 ] ; V_1 ; V_1 = V_1 -> V_36 ) {
if ( V_1 -> V_54 &&
! strcmp ( V_1 -> V_54 , V_54 ) &&
! ( V_1 -> V_13 & V_8 ) )
break;
}
return V_1 ;
}
const char * F_53 ( const char * V_72 )
{
const char * V_73 ;
char * V_74 ;
T_2 V_75 ;
V_75 = strlen ( V_72 ) + 1 ;
V_74 = xmalloc ( V_75 ) ;
V_74 [ 0 ] = '\0' ;
while ( ( V_73 = strchr ( V_72 , '$' ) ) ) {
char * V_76 , V_54 [ V_77 ] ;
const char * V_78 = L_17 ;
struct V_1 * V_2 ;
T_2 V_79 ;
strncat ( V_74 , V_72 , V_73 - V_72 ) ;
V_73 ++ ;
V_76 = V_54 ;
while ( isalnum ( * V_73 ) || * V_73 == '_' )
* V_76 ++ = * V_73 ++ ;
* V_76 = '\0' ;
V_2 = F_52 ( V_54 ) ;
if ( V_2 != NULL ) {
F_19 ( V_2 ) ;
V_78 = F_49 ( V_2 ) ;
}
V_79 = strlen ( V_74 ) + strlen ( V_78 ) + strlen ( V_73 ) + 1 ;
if ( V_79 > V_75 ) {
V_75 = V_79 ;
V_74 = realloc ( V_74 , V_75 ) ;
}
strcat ( V_74 , V_78 ) ;
V_72 = V_73 ;
}
strcat ( V_74 , V_72 ) ;
return V_74 ;
}
const char * F_54 ( const char * V_72 )
{
const char * V_76 ;
T_2 V_75 ;
char * V_74 ;
T_2 V_80 ;
V_75 = strlen ( V_72 ) + strlen ( L_18 ) + 1 ;
V_76 = V_72 ;
for (; ; ) {
V_80 = strcspn ( V_76 , L_19 ) ;
V_76 += V_80 ;
if ( V_76 [ 0 ] == '\0' )
break;
V_75 ++ ;
V_76 ++ ;
}
V_74 = xmalloc ( V_75 ) ;
V_74 [ 0 ] = '\0' ;
strcat ( V_74 , L_20 ) ;
V_76 = V_72 ;
for (; ; ) {
V_80 = strcspn ( V_76 , L_19 ) ;
strncat ( V_74 , V_76 , V_80 ) ;
V_76 += V_80 ;
if ( V_76 [ 0 ] == '\0' )
break;
strcat ( V_74 , L_21 ) ;
strncat ( V_74 , V_76 ++ , 1 ) ;
}
strcat ( V_74 , L_20 ) ;
return V_74 ;
}
static int F_55 ( const void * V_81 , const void * V_82 )
{
const struct V_83 * V_84 = V_81 ;
const struct V_83 * V_85 = V_82 ;
int V_86 , V_87 ;
V_86 = ( V_84 -> V_88 - V_84 -> V_89 ) == strlen ( V_84 -> V_2 -> V_54 ) ;
V_87 = ( V_85 -> V_88 - V_85 -> V_89 ) == strlen ( V_85 -> V_2 -> V_54 ) ;
if ( V_86 && ! V_87 )
return - 1 ;
if ( ! V_86 && V_87 )
return 1 ;
return strcmp ( V_84 -> V_2 -> V_54 , V_85 -> V_2 -> V_54 ) ;
}
struct V_1 * * F_56 ( const char * V_90 )
{
struct V_1 * V_2 , * * V_91 = NULL ;
struct V_83 * V_92 = NULL ;
int V_39 , V_93 , V_63 ;
T_3 V_94 ;
T_4 V_95 [ 1 ] ;
V_93 = V_63 = 0 ;
if ( strlen ( V_90 ) == 0 )
return NULL ;
if ( regcomp ( & V_94 , V_90 , V_96 | V_97 ) )
return NULL ;
F_24 (i, sym) {
if ( V_2 -> V_13 & V_8 || ! V_2 -> V_54 )
continue;
if ( regexec ( & V_94 , V_2 -> V_54 , 1 , V_95 , 0 ) )
continue;
if ( V_93 >= V_63 ) {
void * V_98 ;
V_63 += 16 ;
V_98 = realloc ( V_92 , V_63 * sizeof( struct V_83 ) ) ;
if ( ! V_98 )
goto V_99;
V_92 = V_98 ;
}
F_19 ( V_2 ) ;
V_92 [ V_93 ] . V_89 = V_95 [ 0 ] . V_100 ;
V_92 [ V_93 ] . V_88 = V_95 [ 0 ] . V_101 ;
V_92 [ V_93 ++ ] . V_2 = V_2 ;
}
if ( V_92 ) {
qsort ( V_92 , V_93 , sizeof( struct V_83 ) , F_55 ) ;
V_91 = malloc ( ( V_93 + 1 ) * sizeof( struct V_1 ) ) ;
if ( ! V_91 )
goto V_99;
for ( V_39 = 0 ; V_39 < V_93 ; V_39 ++ )
V_91 [ V_39 ] = V_92 [ V_39 ] . V_2 ;
V_91 [ V_93 ] = NULL ;
}
V_99:
free ( V_92 ) ;
regfree ( & V_94 ) ;
return V_91 ;
}
static void F_57 ( struct V_102 * V_103 , struct V_1 * V_2 )
{
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
if ( V_104 )
V_104 -> V_36 = V_103 ;
V_103 -> V_105 = V_104 ;
V_103 -> V_2 = V_2 ;
V_104 = V_103 ;
}
static void F_58 ( void )
{
V_104 = V_104 -> V_105 ;
if ( V_104 )
V_104 -> V_36 = NULL ;
}
static void F_59 ( struct V_1 * V_106 )
{
struct V_102 * V_103 ;
struct V_1 * V_2 , * V_107 ;
struct V_37 * V_37 = NULL ;
struct V_4 * V_5 ;
struct V_102 V_108 ;
if ( F_8 ( V_106 ) ) {
F_57 ( & V_108 , V_106 ) ;
V_106 = F_29 ( F_10 ( V_106 ) ) ;
}
for ( V_103 = V_104 ; V_103 != NULL ; V_103 = V_103 -> V_105 )
if ( V_103 -> V_2 == V_106 )
break;
if ( ! V_103 ) {
fprintf ( V_57 , L_22 ) ;
return;
}
for (; V_103 ; V_103 = V_103 -> V_36 ) {
V_2 = V_103 -> V_2 ;
V_107 = V_103 -> V_36 ? V_103 -> V_36 -> V_2 : V_106 ;
V_5 = V_103 -> V_5 ;
if ( V_5 == NULL )
V_5 = V_103 -> V_2 -> V_5 ;
if ( F_34 ( V_2 ) || F_8 ( V_2 ) ) {
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_36 ) {
V_37 = V_5 -> V_37 ;
if ( V_5 -> V_37 )
break;
}
}
if ( V_103 -> V_2 == V_106 )
fprintf ( V_57 , L_23 ,
V_5 -> V_109 -> V_54 , V_5 -> V_110 ) ;
if ( V_103 -> V_7 ) {
fprintf ( V_57 , L_24 ,
V_5 -> V_109 -> V_54 , V_5 -> V_110 ,
V_2 -> V_54 ? V_2 -> V_54 : L_25 ,
F_60 ( V_5 -> type ) ,
V_107 -> V_54 ? V_107 -> V_54 : L_25 ) ;
} else if ( V_103 -> V_5 ) {
fprintf ( V_57 , L_26 ,
V_5 -> V_109 -> V_54 , V_5 -> V_110 ,
V_2 -> V_54 ? V_2 -> V_54 : L_25 ,
V_107 -> V_54 ? V_107 -> V_54 : L_25 ) ;
} else if ( F_34 ( V_2 ) ) {
fprintf ( V_57 , L_27 ,
V_37 -> V_109 -> V_54 , V_37 -> V_110 ,
V_2 -> V_54 ? V_2 -> V_54 : L_25 ,
V_107 -> V_54 ? V_107 -> V_54 : L_25 ) ;
} else if ( F_8 ( V_2 ) ) {
fprintf ( V_57 , L_28 ,
V_37 -> V_109 -> V_54 , V_37 -> V_110 ,
V_2 -> V_54 ? V_2 -> V_54 : L_25 ,
V_107 -> V_54 ? V_107 -> V_54 : L_25 ) ;
} else {
fprintf ( V_57 , L_29 ,
V_5 -> V_109 -> V_54 , V_5 -> V_110 ,
V_2 -> V_54 ? V_2 -> V_54 : L_25 ,
V_107 -> V_54 ? V_107 -> V_54 : L_25 ) ;
}
}
if ( V_104 == & V_108 )
F_58 () ;
}
static struct V_1 * F_61 ( struct V_7 * V_44 )
{
struct V_1 * V_2 ;
if ( ! V_44 )
return NULL ;
switch ( V_44 -> type ) {
case V_111 :
case V_112 :
V_2 = F_61 ( V_44 -> V_33 . V_7 ) ;
if ( V_2 )
return V_2 ;
return F_61 ( V_44 -> V_34 . V_7 ) ;
case V_113 :
return F_61 ( V_44 -> V_33 . V_7 ) ;
case V_114 :
case V_115 :
V_2 = F_62 ( V_44 -> V_33 . V_2 ) ;
if ( V_2 )
return V_2 ;
return F_62 ( V_44 -> V_34 . V_2 ) ;
case V_116 :
return F_62 ( V_44 -> V_33 . V_2 ) ;
default:
break;
}
printf ( L_30 , V_44 -> type ) ;
return NULL ;
}
static struct V_1 * F_63 ( struct V_1 * V_2 )
{
struct V_1 * V_82 ;
struct V_4 * V_5 ;
struct V_102 V_103 ;
F_57 ( & V_103 , V_2 ) ;
V_82 = F_61 ( V_2 -> V_42 . V_7 ) ;
if ( V_82 )
goto V_117;
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_36 ) {
if ( V_5 -> type == V_118 || V_5 -> type == V_119 )
continue;
V_103 . V_5 = V_5 ;
V_82 = F_61 ( V_5 -> V_18 . V_7 ) ;
if ( V_82 )
break;
if ( V_5 -> type != V_6 || F_34 ( V_2 ) )
continue;
V_103 . V_7 = V_5 -> V_7 ;
V_82 = F_61 ( V_5 -> V_7 ) ;
if ( V_82 )
break;
V_103 . V_7 = NULL ;
}
V_117:
F_58 () ;
return V_82 ;
}
static struct V_1 * F_64 ( struct V_1 * V_120 )
{
struct V_1 * V_2 , * V_82 ;
struct V_4 * V_5 ;
struct V_7 * V_44 ;
struct V_102 V_103 ;
F_57 ( & V_103 , V_120 ) ;
V_5 = F_10 ( V_120 ) ;
F_30 (prop->expr, e, sym)
V_2 -> V_13 |= ( V_121 | V_122 ) ;
V_120 -> V_13 |= ( V_121 | V_122 ) ;
V_82 = F_63 ( V_120 ) ;
V_120 -> V_13 &= ~ V_121 ;
if ( V_82 )
goto V_117;
F_30 (prop->expr, e, sym) {
V_82 = F_63 ( V_2 ) ;
if ( V_82 )
break;
}
V_117:
F_30 (prop->expr, e, sym)
V_2 -> V_13 &= ~ V_121 ;
if ( V_82 && F_8 ( V_82 ) &&
F_29 ( F_10 ( V_82 ) ) == V_120 )
V_82 = V_120 ;
F_58 () ;
return V_82 ;
}
struct V_1 * F_62 ( struct V_1 * V_2 )
{
struct V_1 * V_82 ;
struct V_4 * V_5 ;
if ( V_2 -> V_13 & V_121 ) {
F_59 ( V_2 ) ;
return V_2 ;
}
if ( V_2 -> V_13 & V_122 )
return NULL ;
if ( F_8 ( V_2 ) ) {
struct V_102 V_103 ;
F_57 ( & V_103 , V_2 ) ;
V_5 = F_10 ( V_2 ) ;
V_82 = F_62 ( F_29 ( V_5 ) ) ;
F_58 () ;
} else if ( F_34 ( V_2 ) ) {
V_82 = F_64 ( V_2 ) ;
} else {
V_2 -> V_13 |= ( V_121 | V_122 ) ;
V_82 = F_63 ( V_2 ) ;
V_2 -> V_13 &= ~ V_121 ;
}
if ( V_82 && V_82 == V_2 )
V_82 = NULL ;
return V_82 ;
}
struct V_4 * F_2 ( enum V_123 type , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_4 * * V_124 ;
V_5 = xmalloc ( sizeof( * V_5 ) ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> type = type ;
V_5 -> V_2 = V_2 ;
V_5 -> V_109 = V_125 ;
V_5 -> V_110 = F_65 () ;
if ( V_2 ) {
for ( V_124 = & V_2 -> V_5 ; * V_124 ; V_124 = & ( * V_124 ) -> V_36 )
;
* V_124 = V_5 ;
}
return V_5 ;
}
struct V_1 * F_29 ( struct V_4 * V_5 )
{
if ( V_5 -> V_7 && ( V_5 -> V_7 -> type == V_116 ||
V_5 -> V_7 -> type == V_126 ) )
return V_5 -> V_7 -> V_33 . V_2 ;
return NULL ;
}
const char * F_60 ( enum V_123 type )
{
switch ( type ) {
case V_127 :
return L_31 ;
case V_128 :
return L_32 ;
case V_129 :
return L_33 ;
case V_130 :
return L_34 ;
case V_6 :
return L_35 ;
case V_118 :
return L_36 ;
case V_119 :
return L_37 ;
case V_131 :
return L_38 ;
case V_132 :
return L_39 ;
case V_133 :
break;
}
return L_7 ;
}
static void F_66 ( const char * V_134 )
{
struct V_1 * V_2 , * V_82 ;
struct V_4 * V_5 ;
char * V_76 ;
V_2 = V_135 -> V_2 ;
V_2 -> V_13 |= V_14 ;
F_13 (sym, prop, P_ENV) {
V_82 = F_29 ( V_5 ) ;
if ( strcmp ( V_82 -> V_54 , V_134 ) )
F_67 ( V_135 , L_40 ,
V_82 -> V_54 ) ;
return;
}
V_5 = F_2 ( V_128 , V_2 ) ;
V_5 -> V_7 = F_3 ( F_4 ( V_134 , V_8 ) ) ;
V_136 = F_68 ( V_126 , V_136 ) ;
V_136 -> V_34 . V_2 = V_2 ;
V_76 = getenv ( V_134 ) ;
if ( V_76 )
F_1 ( V_2 , V_76 ) ;
else
F_67 ( V_135 , L_41 , V_134 ) ;
}
