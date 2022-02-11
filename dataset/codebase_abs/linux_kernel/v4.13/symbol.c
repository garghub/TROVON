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
struct V_1 * V_40 = NULL ;
T_1 V_27 ;
V_27 = V_22 ;
if ( F_8 ( V_2 ) )
V_40 = F_26 ( F_10 ( V_2 ) ) ;
F_27 (sym, prop) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
if ( V_40 && V_2 -> type == V_17 &&
V_5 -> V_18 . V_27 == V_41 && V_40 -> V_29 . V_27 == V_19 )
V_5 -> V_18 . V_27 = V_22 ;
V_27 = F_28 ( V_27 , V_5 -> V_18 . V_27 ) ;
}
if ( V_27 == V_41 && ( V_2 -> type != V_17 || V_21 == V_22 ) )
V_27 = V_19 ;
if ( V_2 -> V_18 != V_27 ) {
V_2 -> V_18 = V_27 ;
F_22 ( V_2 ) ;
}
if ( F_8 ( V_2 ) )
return;
V_27 = V_19 ;
if ( V_2 -> V_42 . V_7 )
V_27 = F_16 ( V_2 -> V_42 . V_7 ) ;
if ( V_27 == V_41 )
V_27 = V_19 ;
if ( V_2 -> V_42 . V_27 != V_27 ) {
V_2 -> V_42 . V_27 = V_27 ;
F_22 ( V_2 ) ;
}
V_27 = V_22 ;
if ( V_2 -> V_43 . V_7 )
V_27 = F_16 ( V_2 -> V_43 . V_7 ) ;
if ( V_27 == V_41 && F_7 ( V_2 ) == V_20 )
V_27 = V_19 ;
if ( V_2 -> V_43 . V_27 != V_27 ) {
V_2 -> V_43 . V_27 = V_27 ;
F_22 ( V_2 ) ;
}
V_27 = V_22 ;
if ( V_2 -> V_44 . V_7 && V_2 -> V_42 . V_27 != V_22 )
V_27 = F_16 ( V_2 -> V_44 . V_7 ) ;
if ( V_27 == V_41 && F_7 ( V_2 ) == V_20 )
V_27 = V_19 ;
if ( V_2 -> V_44 . V_27 != V_27 ) {
V_2 -> V_44 . V_27 = V_27 ;
F_22 ( V_2 ) ;
}
}
struct V_1 * F_29 ( struct V_1 * V_2 )
{
struct V_1 * V_45 ;
struct V_4 * V_5 ;
struct V_7 * V_46 ;
F_15 (sym, prop) {
V_5 -> V_18 . V_27 = F_16 ( V_5 -> V_18 . V_7 ) ;
if ( V_5 -> V_18 . V_27 == V_22 )
continue;
V_45 = F_26 ( V_5 ) ;
if ( V_45 -> V_18 != V_22 )
return V_45 ;
}
V_5 = F_10 ( V_2 ) ;
F_30 (prop->expr, e, def_sym)
if ( V_45 -> V_18 != V_22 )
return V_45 ;
return NULL ;
}
static struct V_1 * F_31 ( struct V_1 * V_2 )
{
struct V_1 * V_45 ;
struct V_4 * V_5 ;
struct V_7 * V_46 ;
int V_13 ;
V_13 = V_2 -> V_13 ;
V_5 = F_10 ( V_2 ) ;
F_30 (prop->expr, e, def_sym) {
F_25 ( V_45 ) ;
if ( V_45 -> V_18 != V_22 )
V_13 &= V_45 -> V_13 ;
}
V_2 -> V_13 &= V_13 | ~ V_47 ;
V_45 = V_2 -> V_3 [ V_48 ] . V_30 ;
if ( V_45 && V_45 -> V_18 != V_22 )
return V_45 ;
V_45 = F_29 ( V_2 ) ;
if ( V_45 == NULL )
V_2 -> V_29 . V_27 = V_22 ;
return V_45 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_49 V_50 , V_51 ;
struct V_4 * V_5 ;
struct V_7 * V_46 ;
if ( ! V_2 )
return;
if ( V_2 -> V_13 & V_52 )
return;
if ( F_8 ( V_2 ) &&
V_2 -> V_13 & V_53 ) {
V_2 -> V_13 &= ~ V_53 ;
V_5 = F_10 ( V_2 ) ;
F_19 ( F_26 ( V_5 ) ) ;
}
V_2 -> V_13 |= V_52 ;
V_51 = V_2 -> V_29 ;
switch ( V_2 -> type ) {
case V_23 :
case V_24 :
case V_12 :
V_50 = V_54 . V_29 ;
break;
case V_20 :
case V_17 :
V_50 = V_55 . V_29 ;
break;
default:
V_2 -> V_29 . V_30 = V_2 -> V_56 ;
V_2 -> V_29 . V_27 = V_22 ;
return;
}
if ( ! F_8 ( V_2 ) )
V_2 -> V_13 &= ~ V_57 ;
F_25 ( V_2 ) ;
V_2 -> V_29 = V_50 ;
switch ( F_7 ( V_2 ) ) {
case V_20 :
case V_17 :
if ( F_8 ( V_2 ) && V_2 -> V_18 == V_19 ) {
V_5 = F_10 ( V_2 ) ;
V_50 . V_27 = ( F_26 ( V_5 ) -> V_29 . V_30 == V_2 ) ? V_19 : V_22 ;
} else {
if ( V_2 -> V_18 != V_22 ) {
V_2 -> V_13 |= V_57 ;
if ( F_32 ( V_2 ) ) {
V_50 . V_27 = F_33 ( V_2 -> V_3 [ V_48 ] . V_27 ,
V_2 -> V_18 ) ;
goto V_58;
}
}
if ( V_2 -> V_43 . V_27 != V_22 )
V_2 -> V_13 |= V_57 ;
if ( ! F_34 ( V_2 ) ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_13 |= V_57 ;
V_50 . V_27 = F_33 ( F_16 ( V_5 -> V_7 ) ,
V_5 -> V_18 . V_27 ) ;
}
if ( V_2 -> V_44 . V_27 != V_22 ) {
V_2 -> V_13 |= V_57 ;
V_50 . V_27 = F_28 ( V_50 . V_27 , V_2 -> V_44 . V_27 ) ;
}
}
V_58:
if ( V_2 -> V_42 . V_27 == V_22 && V_2 -> V_43 . V_27 != V_22 ) {
struct V_7 * V_46 ;
V_46 = F_35 ( V_2 -> V_43 . V_7 ,
V_2 -> V_42 . V_7 ) ;
fprintf ( V_59 , L_11 ) ;
F_36 ( V_46 , V_59 ) ;
fprintf ( V_59 , L_12 ,
V_2 -> V_56 ) ;
F_36 ( V_2 -> V_42 . V_7 , V_59 ) ;
fprintf ( V_59 , L_13 ) ;
F_37 ( V_46 ) ;
}
V_50 . V_27 = F_28 ( V_50 . V_27 , V_2 -> V_43 . V_27 ) ;
}
if ( V_50 . V_27 == V_41 &&
( F_7 ( V_2 ) == V_20 || V_2 -> V_44 . V_27 == V_19 ) )
V_50 . V_27 = V_19 ;
break;
case V_12 :
case V_24 :
case V_23 :
if ( V_2 -> V_18 != V_22 ) {
V_2 -> V_13 |= V_57 ;
if ( F_32 ( V_2 ) ) {
V_50 . V_30 = V_2 -> V_3 [ V_48 ] . V_30 ;
break;
}
}
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
struct V_1 * V_60 = F_26 ( V_5 ) ;
if ( V_60 ) {
V_2 -> V_13 |= V_57 ;
F_19 ( V_60 ) ;
V_50 . V_30 = V_60 -> V_29 . V_30 ;
}
}
break;
default:
;
}
V_2 -> V_29 = V_50 ;
if ( F_34 ( V_2 ) && V_50 . V_27 == V_19 )
V_2 -> V_29 . V_30 = F_31 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( memcmp ( & V_51 , & V_2 -> V_29 , sizeof( V_51 ) ) ) {
F_22 ( V_2 ) ;
if ( V_61 == V_2 ) {
F_23 () ;
V_21 = V_61 -> V_29 . V_27 ;
}
}
if ( F_34 ( V_2 ) ) {
struct V_1 * V_40 ;
V_5 = F_10 ( V_2 ) ;
F_30 (prop->expr, e, choice_sym) {
if ( ( V_2 -> V_13 & V_57 ) &&
V_40 -> V_18 != V_22 )
V_40 -> V_13 |= V_57 ;
if ( V_2 -> V_13 & V_35 )
F_22 ( V_40 ) ;
}
}
if ( V_2 -> V_13 & V_14 )
V_2 -> V_13 &= ~ V_57 ;
if ( V_2 -> V_13 & V_53 )
F_38 ( V_2 ) ;
}
void F_39 ( void )
{
struct V_1 * V_2 ;
int V_39 ;
F_24 (i, sym)
V_2 -> V_13 &= ~ V_52 ;
F_40 ( 1 ) ;
F_19 ( V_61 ) ;
}
bool F_41 ( struct V_1 * V_2 , T_1 V_30 )
{
int type = F_7 ( V_2 ) ;
if ( V_2 -> V_18 == V_22 )
return false ;
if ( type != V_20 && type != V_17 )
return false ;
if ( type == V_20 && V_30 == V_41 )
return false ;
if ( V_2 -> V_18 <= V_2 -> V_43 . V_27 )
return false ;
if ( V_2 -> V_44 . V_27 == V_19 && V_30 == V_41 )
return false ;
if ( F_8 ( V_2 ) && V_2 -> V_18 == V_19 )
return V_30 == V_19 ;
return V_30 >= V_2 -> V_43 . V_27 && V_30 <= V_2 -> V_18 ;
}
bool F_42 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_51 = F_43 ( V_2 ) ;
if ( V_51 != V_30 && ! F_41 ( V_2 , V_30 ) )
return false ;
if ( ! ( V_2 -> V_13 & V_47 ) ) {
V_2 -> V_13 |= V_47 ;
F_22 ( V_2 ) ;
}
if ( F_8 ( V_2 ) && V_30 == V_19 ) {
struct V_1 * V_62 = F_26 ( F_10 ( V_2 ) ) ;
struct V_4 * V_5 ;
struct V_7 * V_46 ;
V_62 -> V_3 [ V_48 ] . V_30 = V_2 ;
V_62 -> V_13 |= V_47 ;
V_5 = F_10 ( V_62 ) ;
for ( V_46 = V_5 -> V_7 ; V_46 ; V_46 = V_46 -> V_33 . V_7 ) {
if ( V_46 -> V_34 . V_2 -> V_18 != V_22 )
V_46 -> V_34 . V_2 -> V_13 |= V_47 ;
}
}
V_2 -> V_3 [ V_48 ] . V_27 = V_30 ;
if ( V_51 != V_30 )
F_39 () ;
return true ;
}
T_1 F_44 ( struct V_1 * V_2 )
{
T_1 V_51 , V_50 ;
V_51 = V_50 = F_43 ( V_2 ) ;
do {
switch ( V_50 ) {
case V_22 :
V_50 = V_41 ;
break;
case V_41 :
V_50 = V_19 ;
break;
case V_19 :
V_50 = V_22 ;
break;
}
if ( F_42 ( V_2 , V_50 ) )
break;
} while ( V_51 != V_50 );
return V_50 ;
}
bool F_45 ( struct V_1 * V_2 , const char * V_32 )
{
signed char V_63 ;
switch ( V_2 -> type ) {
case V_12 :
return true ;
case V_23 :
V_63 = * V_32 ++ ;
if ( V_63 == '-' )
V_63 = * V_32 ++ ;
if ( ! isdigit ( V_63 ) )
return false ;
if ( V_63 == '0' && * V_32 != 0 )
return false ;
while ( ( V_63 = * V_32 ++ ) ) {
if ( ! isdigit ( V_63 ) )
return false ;
}
return true ;
case V_24 :
if ( V_32 [ 0 ] == '0' && ( V_32 [ 1 ] == 'x' || V_32 [ 1 ] == 'X' ) )
V_32 += 2 ;
V_63 = * V_32 ++ ;
do {
if ( ! isxdigit ( V_63 ) )
return false ;
} while ( ( V_63 = * V_32 ++ ) );
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
return F_41 ( V_2 , V_41 ) ;
case 'n' : case 'N' :
return F_41 ( V_2 , V_22 ) ;
}
return false ;
default:
return false ;
}
}
bool F_47 ( struct V_1 * V_2 , const char * V_50 )
{
const char * V_51 ;
char * V_30 ;
int V_64 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
switch ( V_50 [ 0 ] ) {
case 'y' : case 'Y' :
return F_42 ( V_2 , V_19 ) ;
case 'm' : case 'M' :
return F_42 ( V_2 , V_41 ) ;
case 'n' : case 'N' :
return F_42 ( V_2 , V_22 ) ;
}
return false ;
default:
;
}
if ( ! F_46 ( V_2 , V_50 ) )
return false ;
if ( ! ( V_2 -> V_13 & V_47 ) ) {
V_2 -> V_13 |= V_47 ;
F_22 ( V_2 ) ;
}
V_51 = V_2 -> V_3 [ V_48 ] . V_30 ;
V_64 = strlen ( V_50 ) + 1 ;
if ( V_2 -> type == V_24 && ( V_50 [ 0 ] != '0' || ( V_50 [ 1 ] != 'x' && V_50 [ 1 ] != 'X' ) ) ) {
V_64 += 2 ;
V_2 -> V_3 [ V_48 ] . V_30 = V_30 = xmalloc ( V_64 ) ;
* V_30 ++ = '0' ;
* V_30 ++ = 'x' ;
} else if ( ! V_51 || strcmp ( V_51 , V_50 ) )
V_2 -> V_3 [ V_48 ] . V_30 = V_30 = xmalloc ( V_64 ) ;
else
return true ;
strcpy ( V_30 , V_50 ) ;
free ( ( void * ) V_51 ) ;
F_39 () ;
return true ;
}
const char * F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_1 * V_60 ;
const char * V_32 ;
T_1 V_30 ;
F_25 ( V_2 ) ;
F_19 ( V_61 ) ;
V_30 = V_55 . V_29 . V_27 ;
V_32 = V_54 . V_29 . V_30 ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 != NULL ) {
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
V_30 = F_33 ( F_16 ( V_5 -> V_7 ) , V_5 -> V_18 . V_27 ) ;
break;
default:
V_60 = F_26 ( V_5 ) ;
if ( V_60 != NULL ) {
F_19 ( V_60 ) ;
V_32 = ( const char * ) V_60 -> V_29 . V_30 ;
}
}
}
V_30 = F_28 ( V_30 , V_2 -> V_43 . V_27 ) ;
if ( V_30 == V_41 )
if ( ! F_8 ( V_2 ) && V_61 -> V_29 . V_27 == V_22 )
V_30 = V_19 ;
if ( V_2 -> type == V_20 && V_30 == V_41 )
V_30 = V_19 ;
if ( V_30 < V_2 -> V_44 . V_27 )
V_30 = V_2 -> V_44 . V_27 ;
switch ( V_2 -> type ) {
case V_20 :
case V_17 :
switch ( V_30 ) {
case V_22 : return L_14 ;
case V_41 : return L_15 ;
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
case V_41 :
F_19 ( V_61 ) ;
return ( V_61 -> V_29 . V_27 == V_22 ) ? L_14 : L_15 ;
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
return V_2 -> V_18 > V_2 -> V_43 . V_27 ;
}
static unsigned F_51 ( const char * V_65 )
{
unsigned V_66 = 2166136261U ;
for (; * V_65 ; V_65 ++ )
V_66 = ( V_66 ^ * V_65 ) * 0x01000193 ;
return V_66 ;
}
struct V_1 * F_4 ( const char * V_56 , int V_13 )
{
struct V_1 * V_1 ;
char * V_67 ;
int V_66 ;
if ( V_56 ) {
if ( V_56 [ 0 ] && ! V_56 [ 1 ] ) {
switch ( V_56 [ 0 ] ) {
case 'y' : return & V_68 ;
case 'm' : return & V_69 ;
case 'n' : return & V_55 ;
}
}
V_66 = F_51 ( V_56 ) % V_70 ;
for ( V_1 = V_71 [ V_66 ] ; V_1 ; V_1 = V_1 -> V_36 ) {
if ( V_1 -> V_56 &&
! strcmp ( V_1 -> V_56 , V_56 ) &&
( V_13 ? V_1 -> V_13 & V_13
: ! ( V_1 -> V_13 & ( V_8 | V_72 ) ) ) )
return V_1 ;
}
V_67 = F_21 ( V_56 ) ;
} else {
V_67 = NULL ;
V_66 = 0 ;
}
V_1 = xmalloc ( sizeof( * V_1 ) ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_56 = V_67 ;
V_1 -> type = V_25 ;
V_1 -> V_13 |= V_13 ;
V_1 -> V_36 = V_71 [ V_66 ] ;
V_71 [ V_66 ] = V_1 ;
return V_1 ;
}
struct V_1 * F_52 ( const char * V_56 )
{
struct V_1 * V_1 = NULL ;
int V_66 = 0 ;
if ( ! V_56 )
return NULL ;
if ( V_56 [ 0 ] && ! V_56 [ 1 ] ) {
switch ( V_56 [ 0 ] ) {
case 'y' : return & V_68 ;
case 'm' : return & V_69 ;
case 'n' : return & V_55 ;
}
}
V_66 = F_51 ( V_56 ) % V_70 ;
for ( V_1 = V_71 [ V_66 ] ; V_1 ; V_1 = V_1 -> V_36 ) {
if ( V_1 -> V_56 &&
! strcmp ( V_1 -> V_56 , V_56 ) &&
! ( V_1 -> V_13 & V_8 ) )
break;
}
return V_1 ;
}
const char * F_53 ( const char * V_73 )
{
const char * V_74 ;
char * V_75 ;
T_2 V_76 ;
V_76 = strlen ( V_73 ) + 1 ;
V_75 = xmalloc ( V_76 ) ;
V_75 [ 0 ] = '\0' ;
while ( ( V_74 = strchr ( V_73 , '$' ) ) ) {
char * V_77 , V_56 [ V_78 ] ;
const char * V_79 = L_17 ;
struct V_1 * V_2 ;
T_2 V_80 ;
strncat ( V_75 , V_73 , V_74 - V_73 ) ;
V_74 ++ ;
V_77 = V_56 ;
while ( isalnum ( * V_74 ) || * V_74 == '_' )
* V_77 ++ = * V_74 ++ ;
* V_77 = '\0' ;
V_2 = F_52 ( V_56 ) ;
if ( V_2 != NULL ) {
F_19 ( V_2 ) ;
V_79 = F_49 ( V_2 ) ;
}
V_80 = strlen ( V_75 ) + strlen ( V_79 ) + strlen ( V_74 ) + 1 ;
if ( V_80 > V_76 ) {
V_76 = V_80 ;
V_75 = realloc ( V_75 , V_76 ) ;
}
strcat ( V_75 , V_79 ) ;
V_73 = V_74 ;
}
strcat ( V_75 , V_73 ) ;
return V_75 ;
}
const char * F_54 ( const char * V_73 )
{
const char * V_77 ;
T_2 V_76 ;
char * V_75 ;
T_2 V_81 ;
V_76 = strlen ( V_73 ) + strlen ( L_18 ) + 1 ;
V_77 = V_73 ;
for (; ; ) {
V_81 = strcspn ( V_77 , L_19 ) ;
V_77 += V_81 ;
if ( V_77 [ 0 ] == '\0' )
break;
V_76 ++ ;
V_77 ++ ;
}
V_75 = xmalloc ( V_76 ) ;
V_75 [ 0 ] = '\0' ;
strcat ( V_75 , L_20 ) ;
V_77 = V_73 ;
for (; ; ) {
V_81 = strcspn ( V_77 , L_19 ) ;
strncat ( V_75 , V_77 , V_81 ) ;
V_77 += V_81 ;
if ( V_77 [ 0 ] == '\0' )
break;
strcat ( V_75 , L_21 ) ;
strncat ( V_75 , V_77 ++ , 1 ) ;
}
strcat ( V_75 , L_20 ) ;
return V_75 ;
}
static int F_55 ( const void * V_82 , const void * V_83 )
{
const struct V_84 * V_85 = V_82 ;
const struct V_84 * V_86 = V_83 ;
int V_87 , V_88 ;
V_87 = ( V_85 -> V_89 - V_85 -> V_90 ) == strlen ( V_85 -> V_2 -> V_56 ) ;
V_88 = ( V_86 -> V_89 - V_86 -> V_90 ) == strlen ( V_86 -> V_2 -> V_56 ) ;
if ( V_87 && ! V_88 )
return - 1 ;
if ( ! V_87 && V_88 )
return 1 ;
return strcmp ( V_85 -> V_2 -> V_56 , V_86 -> V_2 -> V_56 ) ;
}
struct V_1 * * F_56 ( const char * V_91 )
{
struct V_1 * V_2 , * * V_92 = NULL ;
struct V_84 * V_93 = NULL ;
int V_39 , V_94 , V_64 ;
T_3 V_95 ;
T_4 V_96 [ 1 ] ;
V_94 = V_64 = 0 ;
if ( strlen ( V_91 ) == 0 )
return NULL ;
if ( regcomp ( & V_95 , V_91 , V_97 | V_98 ) )
return NULL ;
F_24 (i, sym) {
if ( V_2 -> V_13 & V_8 || ! V_2 -> V_56 )
continue;
if ( regexec ( & V_95 , V_2 -> V_56 , 1 , V_96 , 0 ) )
continue;
if ( V_94 >= V_64 ) {
void * V_99 ;
V_64 += 16 ;
V_99 = realloc ( V_93 , V_64 * sizeof( struct V_84 ) ) ;
if ( ! V_99 )
goto V_100;
V_93 = V_99 ;
}
F_19 ( V_2 ) ;
V_93 [ V_94 ] . V_90 = V_96 [ 0 ] . V_101 ;
V_93 [ V_94 ] . V_89 = V_96 [ 0 ] . V_102 ;
V_93 [ V_94 ++ ] . V_2 = V_2 ;
}
if ( V_93 ) {
qsort ( V_93 , V_94 , sizeof( struct V_84 ) , F_55 ) ;
V_92 = malloc ( ( V_94 + 1 ) * sizeof( struct V_1 ) ) ;
if ( ! V_92 )
goto V_100;
for ( V_39 = 0 ; V_39 < V_94 ; V_39 ++ )
V_92 [ V_39 ] = V_93 [ V_39 ] . V_2 ;
V_92 [ V_94 ] = NULL ;
}
V_100:
free ( V_93 ) ;
regfree ( & V_95 ) ;
return V_92 ;
}
static void F_57 ( struct V_103 * V_104 , struct V_1 * V_2 )
{
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
if ( V_105 )
V_105 -> V_36 = V_104 ;
V_104 -> V_106 = V_105 ;
V_104 -> V_2 = V_2 ;
V_105 = V_104 ;
}
static void F_58 ( void )
{
V_105 = V_105 -> V_106 ;
if ( V_105 )
V_105 -> V_36 = NULL ;
}
static void F_59 ( struct V_1 * V_107 )
{
struct V_103 * V_104 ;
struct V_1 * V_2 , * V_108 ;
struct V_37 * V_37 = NULL ;
struct V_4 * V_5 ;
struct V_103 V_109 ;
if ( F_8 ( V_107 ) ) {
F_57 ( & V_109 , V_107 ) ;
V_107 = F_26 ( F_10 ( V_107 ) ) ;
}
for ( V_104 = V_105 ; V_104 != NULL ; V_104 = V_104 -> V_106 )
if ( V_104 -> V_2 == V_107 )
break;
if ( ! V_104 ) {
fprintf ( V_59 , L_22 ) ;
return;
}
for (; V_104 ; V_104 = V_104 -> V_36 ) {
V_2 = V_104 -> V_2 ;
V_108 = V_104 -> V_36 ? V_104 -> V_36 -> V_2 : V_107 ;
V_5 = V_104 -> V_5 ;
if ( V_5 == NULL )
V_5 = V_104 -> V_2 -> V_5 ;
if ( F_34 ( V_2 ) || F_8 ( V_2 ) ) {
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_36 ) {
V_37 = V_5 -> V_37 ;
if ( V_5 -> V_37 )
break;
}
}
if ( V_104 -> V_2 == V_107 )
fprintf ( V_59 , L_23 ,
V_5 -> V_110 -> V_56 , V_5 -> V_111 ) ;
fprintf ( V_59 , L_24 ) ;
fprintf ( V_59 , L_25 ) ;
if ( V_104 -> V_7 ) {
fprintf ( V_59 , L_26 ,
V_5 -> V_110 -> V_56 , V_5 -> V_111 ,
V_2 -> V_56 ? V_2 -> V_56 : L_27 ,
F_60 ( V_5 -> type ) ,
V_108 -> V_56 ? V_108 -> V_56 : L_27 ) ;
} else if ( V_104 -> V_5 ) {
fprintf ( V_59 , L_28 ,
V_5 -> V_110 -> V_56 , V_5 -> V_111 ,
V_2 -> V_56 ? V_2 -> V_56 : L_27 ,
V_108 -> V_56 ? V_108 -> V_56 : L_27 ) ;
} else if ( F_34 ( V_2 ) ) {
fprintf ( V_59 , L_29 ,
V_37 -> V_110 -> V_56 , V_37 -> V_111 ,
V_2 -> V_56 ? V_2 -> V_56 : L_27 ,
V_108 -> V_56 ? V_108 -> V_56 : L_27 ) ;
} else if ( F_8 ( V_2 ) ) {
fprintf ( V_59 , L_30 ,
V_37 -> V_110 -> V_56 , V_37 -> V_111 ,
V_2 -> V_56 ? V_2 -> V_56 : L_27 ,
V_108 -> V_56 ? V_108 -> V_56 : L_27 ) ;
} else {
fprintf ( V_59 , L_31 ,
V_5 -> V_110 -> V_56 , V_5 -> V_111 ,
V_2 -> V_56 ? V_2 -> V_56 : L_27 ,
V_108 -> V_56 ? V_108 -> V_56 : L_27 ) ;
}
}
if ( V_105 == & V_109 )
F_58 () ;
}
static struct V_1 * F_61 ( struct V_7 * V_46 )
{
struct V_1 * V_2 ;
if ( ! V_46 )
return NULL ;
switch ( V_46 -> type ) {
case V_112 :
case V_113 :
V_2 = F_61 ( V_46 -> V_33 . V_7 ) ;
if ( V_2 )
return V_2 ;
return F_61 ( V_46 -> V_34 . V_7 ) ;
case V_114 :
return F_61 ( V_46 -> V_33 . V_7 ) ;
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_2 = F_62 ( V_46 -> V_33 . V_2 ) ;
if ( V_2 )
return V_2 ;
return F_62 ( V_46 -> V_34 . V_2 ) ;
case V_121 :
return F_62 ( V_46 -> V_33 . V_2 ) ;
default:
break;
}
printf ( L_32 , V_46 -> type ) ;
return NULL ;
}
static struct V_1 * F_63 ( struct V_1 * V_2 )
{
struct V_1 * V_83 ;
struct V_4 * V_5 ;
struct V_103 V_104 ;
F_57 ( & V_104 , V_2 ) ;
V_83 = F_61 ( V_2 -> V_43 . V_7 ) ;
if ( V_83 )
goto V_122;
for ( V_5 = V_2 -> V_5 ; V_5 ; V_5 = V_5 -> V_36 ) {
if ( V_5 -> type == V_123 || V_5 -> type == V_124 )
continue;
V_104 . V_5 = V_5 ;
V_83 = F_61 ( V_5 -> V_18 . V_7 ) ;
if ( V_83 )
break;
if ( V_5 -> type != V_6 || F_34 ( V_2 ) )
continue;
V_104 . V_7 = V_5 -> V_7 ;
V_83 = F_61 ( V_5 -> V_7 ) ;
if ( V_83 )
break;
V_104 . V_7 = NULL ;
}
V_122:
F_58 () ;
return V_83 ;
}
static struct V_1 * F_64 ( struct V_1 * V_125 )
{
struct V_1 * V_2 , * V_83 ;
struct V_4 * V_5 ;
struct V_7 * V_46 ;
struct V_103 V_104 ;
F_57 ( & V_104 , V_125 ) ;
V_5 = F_10 ( V_125 ) ;
F_30 (prop->expr, e, sym)
V_2 -> V_13 |= ( V_126 | V_127 ) ;
V_125 -> V_13 |= ( V_126 | V_127 ) ;
V_83 = F_63 ( V_125 ) ;
V_125 -> V_13 &= ~ V_126 ;
if ( V_83 )
goto V_122;
F_30 (prop->expr, e, sym) {
V_83 = F_63 ( V_2 ) ;
if ( V_83 )
break;
}
V_122:
F_30 (prop->expr, e, sym)
V_2 -> V_13 &= ~ V_126 ;
if ( V_83 && F_8 ( V_83 ) &&
F_26 ( F_10 ( V_83 ) ) == V_125 )
V_83 = V_125 ;
F_58 () ;
return V_83 ;
}
struct V_1 * F_62 ( struct V_1 * V_2 )
{
struct V_1 * V_83 ;
struct V_4 * V_5 ;
if ( V_2 -> V_13 & V_126 ) {
F_59 ( V_2 ) ;
return V_2 ;
}
if ( V_2 -> V_13 & V_127 )
return NULL ;
if ( F_8 ( V_2 ) ) {
struct V_103 V_104 ;
F_57 ( & V_104 , V_2 ) ;
V_5 = F_10 ( V_2 ) ;
V_83 = F_62 ( F_26 ( V_5 ) ) ;
F_58 () ;
} else if ( F_34 ( V_2 ) ) {
V_83 = F_64 ( V_2 ) ;
} else {
V_2 -> V_13 |= ( V_126 | V_127 ) ;
V_83 = F_63 ( V_2 ) ;
V_2 -> V_13 &= ~ V_126 ;
}
if ( V_83 && V_83 == V_2 )
V_83 = NULL ;
return V_83 ;
}
struct V_4 * F_2 ( enum V_128 type , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_4 * * V_129 ;
V_5 = xmalloc ( sizeof( * V_5 ) ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> type = type ;
V_5 -> V_2 = V_2 ;
V_5 -> V_110 = V_130 ;
V_5 -> V_111 = F_65 () ;
if ( V_2 ) {
for ( V_129 = & V_2 -> V_5 ; * V_129 ; V_129 = & ( * V_129 ) -> V_36 )
;
* V_129 = V_5 ;
}
return V_5 ;
}
struct V_1 * F_26 ( struct V_4 * V_5 )
{
if ( V_5 -> V_7 && ( V_5 -> V_7 -> type == V_121 ||
V_5 -> V_7 -> type == V_131 ) )
return V_5 -> V_7 -> V_33 . V_2 ;
return NULL ;
}
const char * F_60 ( enum V_128 type )
{
switch ( type ) {
case V_132 :
return L_33 ;
case V_133 :
return L_34 ;
case V_134 :
return L_35 ;
case V_135 :
return L_36 ;
case V_6 :
return L_37 ;
case V_123 :
return L_38 ;
case V_124 :
return L_39 ;
case V_136 :
return L_40 ;
case V_137 :
return L_41 ;
case V_138 :
return L_42 ;
case V_139 :
break;
}
return L_7 ;
}
static void F_66 ( const char * V_140 )
{
struct V_1 * V_2 , * V_83 ;
struct V_4 * V_5 ;
char * V_77 ;
V_2 = V_141 -> V_2 ;
V_2 -> V_13 |= V_14 ;
F_13 (sym, prop, P_ENV) {
V_83 = F_26 ( V_5 ) ;
if ( strcmp ( V_83 -> V_56 , V_140 ) )
F_67 ( V_141 , L_43 ,
V_83 -> V_56 ) ;
return;
}
V_5 = F_2 ( V_133 , V_2 ) ;
V_5 -> V_7 = F_3 ( F_4 ( V_140 , V_8 ) ) ;
V_142 = F_68 ( V_131 , V_142 ) ;
V_142 -> V_34 . V_2 = V_2 ;
V_77 = getenv ( V_140 ) ;
if ( V_77 )
F_1 ( V_2 , V_77 ) ;
else
F_67 ( V_141 , L_44 , V_140 ) ;
}
