bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
return false ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_5 ) )
return false ;
if ( ! V_2 -> V_6 &&
( F_3 ( F_4 ( V_2 , V_3 ) ) &
V_7 ) )
return false ;
if ( ! ( F_5 ( V_2 , V_3 ) & V_8 ) )
return false ;
return true ;
}
static T_2 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_9 ;
if ( ! V_2 -> V_10 ) {
V_9 = F_2 ( V_2 , V_3 ) ;
if ( V_9 & V_11 )
F_7 ( V_2 , V_3 , 0 ,
V_12 , 0 ) ;
}
return F_7 ( V_2 , V_3 , 0 ,
V_13 , 0 ) ;
}
struct V_14 *
F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
if ( ! V_3 || ! V_15 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_3 == V_3 )
return V_15 ;
return NULL ;
}
struct V_14 *
F_9 ( struct V_1 * V_2 , unsigned char V_20 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
if ( ! V_20 || ! V_15 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_20 == V_20 )
return V_15 ;
return NULL ;
}
struct V_14 *
F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_14 * V_15 = F_8 ( V_2 , V_3 ) ;
if ( V_15 )
return V_15 ;
F_11 ( & V_2 -> V_16 , sizeof( * V_15 ) , 16 ) ;
V_15 = F_12 ( & V_2 -> V_16 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_3 = V_3 ;
V_15 -> V_21 = 1 ;
V_15 -> V_20 = V_2 -> V_16 . V_19 ;
return V_15 ;
}
void F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
if ( ! V_2 -> V_22 -> V_23 && V_2 -> V_16 . V_17 ) {
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ ) {
if ( V_15 -> V_15 )
F_15 ( V_2 -> V_22 -> V_24 , V_15 -> V_15 ) ;
}
}
#endif
F_16 ( & V_2 -> V_16 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( ! V_15 -> V_21 )
return;
if ( V_15 -> V_25 )
V_15 -> V_26 = V_27 ;
else
V_15 -> V_26 = F_6 ( V_2 , V_15 -> V_3 ) ;
V_15 -> V_21 = 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_3 )
V_15 -> V_21 = 1 ;
}
T_2 F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_14 * V_15 = F_8 ( V_2 , V_3 ) ;
if ( V_15 ) {
F_17 ( V_2 , V_15 ) ;
return V_15 -> V_26 ;
}
return F_6 ( V_2 , V_3 ) ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_28 = F_19 ( V_2 , V_3 ) ;
return F_21 ( V_28 ) ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_29 )
{
struct V_14 * V_15 = F_10 ( V_2 , V_3 ) ;
if ( ! V_15 )
return - V_30 ;
if ( V_15 -> V_31 )
return 0 ;
V_15 -> V_31 = 1 ;
if ( V_29 )
V_15 -> V_29 = V_29 ;
return F_23 ( V_2 , V_3 , 0 ,
V_32 ,
V_33 | V_15 -> V_20 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 , V_34 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_3 ) {
F_17 ( V_2 , V_15 ) ;
if ( ! V_15 -> V_35 )
continue;
V_34 = F_21 ( V_15 -> V_26 ) ;
F_25 ( V_2 -> V_22 -> V_24 , V_15 -> V_35 , V_34 ) ;
#ifdef F_14
if ( V_15 -> V_15 )
F_26 ( V_15 -> V_15 ,
V_34 ? V_15 -> type : 0 ) ;
#endif
}
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_36 = F_4 ( V_2 , V_3 ) ;
switch ( F_28 ( V_36 ) ) {
case V_37 :
case V_38 :
return V_39 ;
case V_40 :
return V_41 ;
case V_42 :
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
default:
return V_47 ;
}
}
static void F_29 ( struct V_48 * V_15 )
{
struct V_14 * V_49 = V_15 -> V_50 ;
V_49 -> V_3 = 0 ;
V_49 -> V_15 = NULL ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_51 , int V_52 , bool V_25 )
{
struct V_14 * V_15 ;
struct V_53 * V_35 ;
int V_54 , V_34 ;
V_15 = F_10 ( V_2 , V_3 ) ;
if ( ! V_15 )
return 0 ;
if ( V_15 -> V_35 )
return 0 ;
V_35 = F_31 ( V_51 , V_52 , V_2 ) ;
if ( ! V_35 )
return - V_30 ;
V_54 = F_32 ( V_2 , V_3 , V_35 ) ;
if ( V_54 < 0 )
return V_54 ;
V_15 -> V_35 = V_35 ;
V_15 -> V_25 = ! ! V_25 ;
V_34 = F_20 ( V_2 , V_3 ) ;
F_25 ( V_2 -> V_22 -> V_24 , V_35 , V_34 ) ;
#ifdef F_14
if ( ! V_25 ) {
V_15 -> type = F_27 ( V_2 , V_3 ) ;
V_54 = F_33 ( V_2 -> V_22 -> V_24 , V_51 , V_15 -> type ,
& V_15 -> V_15 ) ;
if ( V_54 < 0 )
return V_54 ;
V_15 -> V_15 -> V_50 = V_15 ;
V_15 -> V_15 -> V_55 = F_29 ;
F_26 ( V_15 -> V_15 , V_34 ? V_15 -> type : 0 ) ;
}
#endif
return 0 ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_51 , int V_52 )
{
return F_30 ( V_2 , V_3 , V_51 , V_52 , false ) ;
}
static int F_35 ( struct V_1 * V_2 , const char * V_51 , int V_52 )
{
struct V_14 * V_15 ;
int V_18 , V_56 = strlen ( V_51 ) ;
V_57:
V_15 = V_2 -> V_16 . V_17 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ ) {
if ( V_15 -> V_35 &&
! strncmp ( V_51 , V_15 -> V_35 -> V_58 . V_51 , V_56 ) &&
! strcmp ( L_1 , V_15 -> V_35 -> V_58 . V_51 + V_56 ) &&
V_15 -> V_35 -> V_58 . V_59 == V_52 ) {
V_52 ++ ;
goto V_57;
}
}
return V_52 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_60 * V_61 )
{
unsigned int V_36 , V_62 ;
char V_51 [ 44 ] ;
int V_52 , V_54 ;
bool V_25 ;
if ( ! V_3 )
return 0 ;
V_36 = F_4 ( V_2 , V_3 ) ;
V_62 = F_37 ( V_36 ) ;
if ( V_62 == V_63 )
return 0 ;
V_25 = ( V_62 != V_64 ) ||
! F_1 ( V_2 , V_3 ) ;
F_38 ( V_2 , V_3 , V_61 , V_51 , sizeof( V_51 ) , & V_52 ) ;
if ( V_25 )
strncat ( V_51 , L_2 , sizeof( V_51 ) - strlen ( V_51 ) - 1 ) ;
V_52 = F_35 ( V_2 , V_51 , V_52 ) ;
V_54 = F_30 ( V_2 , V_3 , V_51 , V_52 , V_25 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! V_25 )
return F_22 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
const T_1 * V_65 ;
int V_18 , V_54 ;
for ( V_18 = 0 , V_65 = V_61 -> V_66 ; V_18 < V_61 -> V_67 ; V_18 ++ , V_65 ++ ) {
V_54 = F_36 ( V_2 , * V_65 , V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
}
for ( V_18 = 0 , V_65 = V_61 -> V_68 ; V_18 < V_61 -> V_69 ; V_18 ++ , V_65 ++ ) {
if ( * V_65 == * V_61 -> V_66 )
break;
V_54 = F_36 ( V_2 , * V_65 , V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
}
for ( V_18 = 0 , V_65 = V_61 -> V_70 ; V_18 < V_61 -> V_71 ; V_18 ++ , V_65 ++ ) {
if ( * V_65 == * V_61 -> V_66 )
break;
V_54 = F_36 ( V_2 , * V_65 , V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
}
for ( V_18 = 0 ; V_18 < V_61 -> V_72 ; V_18 ++ ) {
V_54 = F_36 ( V_2 , V_61 -> V_73 [ V_18 ] . V_74 , V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
}
for ( V_18 = 0 , V_65 = V_61 -> V_75 ; V_18 < V_61 -> V_76 ; V_18 ++ , V_65 ++ ) {
V_54 = F_36 ( V_2 , * V_65 , V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
}
V_54 = F_36 ( V_2 , V_61 -> V_77 , V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_36 ( V_2 , V_61 -> V_78 , V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
return 0 ;
}
