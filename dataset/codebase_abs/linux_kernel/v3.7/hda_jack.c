bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
return false ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_5 ) )
return false ;
if ( F_3 ( F_4 ( V_2 , V_3 ) ) &
V_6 )
return false ;
if ( ! ( F_5 ( V_2 , V_3 ) & V_7 ) )
return false ;
return true ;
}
static T_2 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_8 ;
if ( ! V_2 -> V_9 ) {
V_8 = F_2 ( V_2 , V_3 ) ;
if ( V_8 & V_10 )
F_7 ( V_2 , V_3 , 0 ,
V_11 , 0 ) ;
}
return F_7 ( V_2 , V_3 , 0 ,
V_12 , 0 ) ;
}
struct V_13 *
F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_16 ;
int V_17 ;
if ( ! V_3 || ! V_14 )
return NULL ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ )
if ( V_14 -> V_3 == V_3 )
return V_14 ;
return NULL ;
}
struct V_13 *
F_9 ( struct V_1 * V_2 , unsigned char V_19 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_16 ;
int V_17 ;
if ( ! V_19 || ! V_14 )
return NULL ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ )
if ( V_14 -> V_19 == V_19 )
return V_14 ;
return NULL ;
}
struct V_13 *
F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_13 * V_14 = F_8 ( V_2 , V_3 ) ;
if ( V_14 )
return V_14 ;
F_11 ( & V_2 -> V_15 , sizeof( * V_14 ) , 16 ) ;
V_14 = F_12 ( & V_2 -> V_15 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_3 = V_3 ;
V_14 -> V_20 = 1 ;
V_14 -> V_19 = V_2 -> V_15 . V_18 ;
return V_14 ;
}
void F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
if ( ! V_2 -> V_21 -> V_22 && V_2 -> V_15 . V_16 ) {
struct V_13 * V_14 = V_2 -> V_15 . V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ ) {
if ( V_14 -> V_14 )
F_15 ( V_2 -> V_21 -> V_23 , V_14 -> V_14 ) ;
}
}
#endif
F_16 ( & V_2 -> V_15 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
if ( ! V_14 -> V_20 )
return;
if ( V_14 -> V_24 )
V_14 -> V_25 = V_26 ;
else
V_14 -> V_25 = F_6 ( V_2 , V_14 -> V_3 ) ;
V_14 -> V_20 = 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ )
if ( V_14 -> V_3 )
V_14 -> V_20 = 1 ;
}
T_2 F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_13 * V_14 = F_8 ( V_2 , V_3 ) ;
if ( V_14 ) {
F_17 ( V_2 , V_14 ) ;
return V_14 -> V_25 ;
}
return F_6 ( V_2 , V_3 ) ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_27 = F_19 ( V_2 , V_3 ) ;
return F_21 ( V_27 ) ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_28 ,
T_3 V_29 )
{
struct V_13 * V_14 = F_10 ( V_2 , V_3 ) ;
if ( ! V_14 )
return - V_30 ;
if ( V_14 -> V_31 )
return 0 ;
V_14 -> V_31 = 1 ;
if ( V_28 )
V_14 -> V_28 = V_28 ;
if ( V_29 )
V_14 -> V_32 = V_29 ;
return F_23 ( V_2 , V_3 , 0 ,
V_33 ,
V_34 | V_14 -> V_19 ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_28 )
{
return F_22 ( V_2 , V_3 , V_28 , NULL ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_16 ;
int V_17 , V_35 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ )
if ( V_14 -> V_3 ) {
F_17 ( V_2 , V_14 ) ;
if ( ! V_14 -> V_36 )
continue;
V_35 = F_21 ( V_14 -> V_25 ) ;
F_26 ( V_2 -> V_21 -> V_23 , V_14 -> V_36 , V_35 ) ;
#ifdef F_14
if ( V_14 -> V_14 )
F_27 ( V_14 -> V_14 ,
V_35 ? V_14 -> type : 0 ) ;
#endif
}
}
static int F_28 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_37 = F_4 ( V_2 , V_3 ) ;
switch ( F_29 ( V_37 ) ) {
case V_38 :
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
case V_43 :
case V_44 :
return V_45 ;
case V_46 :
return V_47 ;
default:
return V_48 ;
}
}
static void F_30 ( struct V_49 * V_14 )
{
struct V_13 * V_50 = V_14 -> V_51 ;
V_50 -> V_3 = 0 ;
V_50 -> V_14 = NULL ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_52 , int V_53 , bool V_24 )
{
struct V_13 * V_14 ;
struct V_54 * V_36 ;
int V_55 , V_35 ;
V_14 = F_10 ( V_2 , V_3 ) ;
if ( ! V_14 )
return 0 ;
if ( V_14 -> V_36 )
return 0 ;
V_36 = F_32 ( V_52 , V_53 , V_2 ) ;
if ( ! V_36 )
return - V_30 ;
V_55 = F_33 ( V_2 , V_3 , V_36 ) ;
if ( V_55 < 0 )
return V_55 ;
V_14 -> V_36 = V_36 ;
V_14 -> V_24 = ! ! V_24 ;
V_35 = F_20 ( V_2 , V_3 ) ;
F_26 ( V_2 -> V_21 -> V_23 , V_36 , V_35 ) ;
#ifdef F_14
if ( ! V_24 ) {
V_14 -> type = F_28 ( V_2 , V_3 ) ;
V_55 = F_34 ( V_2 -> V_21 -> V_23 , V_52 , V_14 -> type ,
& V_14 -> V_14 ) ;
if ( V_55 < 0 )
return V_55 ;
V_14 -> V_14 -> V_51 = V_14 ;
V_14 -> V_14 -> V_56 = F_30 ;
F_27 ( V_14 -> V_14 , V_35 ? V_14 -> type : 0 ) ;
}
#endif
return 0 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_52 , int V_53 )
{
return F_31 ( V_2 , V_3 , V_52 , V_53 , false ) ;
}
static int F_36 ( struct V_1 * V_2 , const char * V_52 , int V_53 )
{
struct V_13 * V_14 ;
int V_17 , V_57 = strlen ( V_52 ) ;
V_58:
V_14 = V_2 -> V_15 . V_16 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ ) {
if ( V_14 -> V_36 &&
! strncmp ( V_52 , V_14 -> V_36 -> V_59 . V_52 , V_57 ) &&
! strcmp ( L_1 , V_14 -> V_36 -> V_59 . V_52 + V_57 ) &&
V_14 -> V_36 -> V_59 . V_60 == V_53 ) {
V_53 ++ ;
goto V_58;
}
}
return V_53 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_61 * V_62 )
{
unsigned int V_37 , V_63 ;
char V_52 [ 44 ] ;
int V_53 , V_55 ;
bool V_24 ;
if ( ! V_3 )
return 0 ;
V_37 = F_4 ( V_2 , V_3 ) ;
V_63 = F_38 ( V_37 ) ;
if ( V_63 == V_64 )
return 0 ;
V_24 = ( V_63 != V_65 ) ||
! F_1 ( V_2 , V_3 ) ;
F_39 ( V_2 , V_3 , V_62 , V_52 , sizeof( V_52 ) , & V_53 ) ;
if ( V_24 )
strncat ( V_52 , L_2 , sizeof( V_52 ) - strlen ( V_52 ) - 1 ) ;
V_53 = F_36 ( V_2 , V_52 , V_53 ) ;
V_55 = F_31 ( V_2 , V_3 , V_52 , V_53 , V_24 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! V_24 )
return F_24 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
const struct V_61 * V_62 )
{
const T_1 * V_66 ;
int V_17 , V_55 ;
for ( V_17 = 0 , V_66 = V_62 -> V_67 ; V_17 < V_62 -> V_68 ; V_17 ++ , V_66 ++ ) {
V_55 = F_37 ( V_2 , * V_66 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
}
for ( V_17 = 0 , V_66 = V_62 -> V_69 ; V_17 < V_62 -> V_70 ; V_17 ++ , V_66 ++ ) {
if ( * V_66 == * V_62 -> V_67 )
break;
V_55 = F_37 ( V_2 , * V_66 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
}
for ( V_17 = 0 , V_66 = V_62 -> V_71 ; V_17 < V_62 -> V_72 ; V_17 ++ , V_66 ++ ) {
if ( * V_66 == * V_62 -> V_67 )
break;
V_55 = F_37 ( V_2 , * V_66 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
}
for ( V_17 = 0 ; V_17 < V_62 -> V_73 ; V_17 ++ ) {
V_55 = F_37 ( V_2 , V_62 -> V_74 [ V_17 ] . V_75 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
}
for ( V_17 = 0 , V_66 = V_62 -> V_76 ; V_17 < V_62 -> V_77 ; V_17 ++ , V_66 ++ ) {
V_55 = F_37 ( V_2 , * V_66 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
}
V_55 = F_37 ( V_2 , V_62 -> V_78 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_37 ( V_2 , V_62 -> V_79 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
void F_41 ( struct V_1 * V_2 , unsigned int V_80 )
{
struct V_13 * V_81 ;
int V_19 = ( V_80 >> V_82 ) & 0x7f ;
V_81 = F_9 ( V_2 , V_19 ) ;
if ( ! V_81 )
return;
V_81 -> V_20 = 1 ;
if ( V_81 -> V_32 )
V_81 -> V_32 ( V_2 , V_81 ) ;
F_25 ( V_2 ) ;
}
