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
V_14 = F_11 ( & V_2 -> V_15 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_3 = V_3 ;
V_14 -> V_20 = 1 ;
V_14 -> V_19 = V_2 -> V_15 . V_18 ;
return V_14 ;
}
void F_12 ( struct V_1 * V_2 )
{
#ifdef F_13
if ( ! V_2 -> V_21 -> V_22 && V_2 -> V_15 . V_16 ) {
struct V_13 * V_14 = V_2 -> V_15 . V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ ) {
if ( V_14 -> V_14 )
F_14 ( V_2 -> V_21 -> V_23 , V_14 -> V_14 ) ;
}
}
#endif
F_15 ( & V_2 -> V_15 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
if ( ! V_14 -> V_20 )
return;
if ( V_14 -> V_24 )
V_14 -> V_25 = V_26 ;
else
V_14 -> V_25 = F_6 ( V_2 , V_14 -> V_3 ) ;
if ( V_14 -> V_27 && ! F_17 ( V_2 , V_14 -> V_27 ) )
V_14 -> V_25 &= ~ V_26 ;
V_14 -> V_20 = 0 ;
if ( V_14 -> V_28 ) {
struct V_13 * V_29 =
F_8 ( V_2 , V_14 -> V_28 ) ;
if ( V_29 ) {
V_29 -> V_20 = 1 ;
F_16 ( V_2 , V_29 ) ;
}
}
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
F_16 ( V_2 , V_14 ) ;
return V_14 -> V_25 ;
}
return F_6 ( V_2 , V_3 ) ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_30 = F_19 ( V_2 , V_3 ) ;
return F_20 ( V_30 ) ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_31 ,
T_3 V_32 )
{
struct V_13 * V_14 = F_10 ( V_2 , V_3 ) ;
if ( ! V_14 )
return - V_33 ;
if ( V_14 -> V_34 )
return 0 ;
V_14 -> V_34 = 1 ;
if ( V_31 )
V_14 -> V_31 = V_31 ;
if ( V_32 )
V_14 -> V_35 = V_32 ;
if ( V_2 -> V_36 > 0 )
return 0 ;
return F_22 ( V_2 , V_3 , 0 ,
V_37 ,
V_38 | V_14 -> V_19 ) ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_31 )
{
return F_21 ( V_2 , V_3 , V_31 , NULL ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_39 ,
T_1 V_40 )
{
struct V_13 * V_29 = F_8 ( V_2 , V_39 ) ;
struct V_13 * V_41 = F_8 ( V_2 , V_40 ) ;
if ( ! V_29 || ! V_41 )
return - V_42 ;
V_29 -> V_27 = V_40 ;
V_41 -> V_28 = V_39 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_17 , V_43 ;
V_14 = V_2 -> V_15 . V_16 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ )
if ( V_14 -> V_3 )
F_16 ( V_2 , V_14 ) ;
V_14 = V_2 -> V_15 . V_16 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ )
if ( V_14 -> V_3 ) {
if ( ! V_14 -> V_44 )
continue;
V_43 = F_20 ( V_14 -> V_25 ) ;
F_26 ( V_2 -> V_21 -> V_23 , V_14 -> V_44 , V_43 ) ;
#ifdef F_13
if ( V_14 -> V_14 )
F_27 ( V_14 -> V_14 ,
V_43 ? V_14 -> type : 0 ) ;
#endif
}
}
static int F_28 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_45 = F_4 ( V_2 , V_3 ) ;
switch ( F_29 ( V_45 ) ) {
case V_46 :
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
case V_51 :
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
default:
return V_56 ;
}
}
static void F_30 ( struct V_57 * V_14 )
{
struct V_13 * V_58 = V_14 -> V_59 ;
V_58 -> V_3 = 0 ;
V_58 -> V_14 = NULL ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_60 , int V_61 , bool V_24 )
{
struct V_13 * V_14 ;
struct V_62 * V_44 ;
int V_63 , V_43 ;
V_14 = F_10 ( V_2 , V_3 ) ;
if ( ! V_14 )
return 0 ;
if ( V_14 -> V_44 )
return 0 ;
V_44 = F_32 ( V_60 , V_61 , V_2 ) ;
if ( ! V_44 )
return - V_33 ;
V_63 = F_33 ( V_2 , V_3 , V_44 ) ;
if ( V_63 < 0 )
return V_63 ;
V_14 -> V_44 = V_44 ;
V_14 -> V_24 = ! ! V_24 ;
V_43 = F_17 ( V_2 , V_3 ) ;
F_26 ( V_2 -> V_21 -> V_23 , V_44 , V_43 ) ;
#ifdef F_13
if ( ! V_24 ) {
V_14 -> type = F_28 ( V_2 , V_3 ) ;
V_63 = F_34 ( V_2 -> V_21 -> V_23 , V_60 , V_14 -> type ,
& V_14 -> V_14 ) ;
if ( V_63 < 0 )
return V_63 ;
V_14 -> V_14 -> V_59 = V_14 ;
V_14 -> V_14 -> V_64 = F_30 ;
F_27 ( V_14 -> V_14 , V_43 ? V_14 -> type : 0 ) ;
}
#endif
return 0 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_60 , int V_61 )
{
return F_31 ( V_2 , V_3 , V_60 , V_61 , false ) ;
}
static int F_36 ( struct V_1 * V_2 , const char * V_60 , int V_61 )
{
struct V_13 * V_14 ;
int V_17 , V_65 = strlen ( V_60 ) ;
V_66:
V_14 = V_2 -> V_15 . V_16 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ ) {
if ( V_14 -> V_44 &&
! strncmp ( V_60 , V_14 -> V_44 -> V_67 . V_60 , V_65 ) &&
! strcmp ( L_1 , V_14 -> V_44 -> V_67 . V_60 + V_65 ) &&
V_14 -> V_44 -> V_67 . V_68 == V_61 ) {
V_61 ++ ;
goto V_66;
}
}
return V_61 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_69 * V_70 )
{
unsigned int V_45 , V_71 ;
char V_60 [ 44 ] ;
int V_61 , V_63 ;
bool V_24 ;
if ( ! V_3 )
return 0 ;
V_45 = F_4 ( V_2 , V_3 ) ;
V_71 = F_38 ( V_45 ) ;
if ( V_71 == V_72 )
return 0 ;
V_24 = ( V_71 != V_73 ) ||
! F_1 ( V_2 , V_3 ) ;
F_39 ( V_2 , V_3 , V_70 , V_60 , sizeof( V_60 ) , & V_61 ) ;
if ( V_24 )
strncat ( V_60 , L_2 , sizeof( V_60 ) - strlen ( V_60 ) - 1 ) ;
V_61 = F_36 ( V_2 , V_60 , V_61 ) ;
V_63 = F_31 ( V_2 , V_3 , V_60 , V_61 , V_24 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( ! V_24 )
return F_23 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
const struct V_69 * V_70 )
{
const T_1 * V_74 ;
int V_17 , V_63 ;
for ( V_17 = 0 , V_74 = V_70 -> V_75 ; V_17 < V_70 -> V_76 ; V_17 ++ , V_74 ++ ) {
V_63 = F_37 ( V_2 , * V_74 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
}
for ( V_17 = 0 , V_74 = V_70 -> V_77 ; V_17 < V_70 -> V_78 ; V_17 ++ , V_74 ++ ) {
if ( * V_74 == * V_70 -> V_75 )
break;
V_63 = F_37 ( V_2 , * V_74 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
}
for ( V_17 = 0 , V_74 = V_70 -> V_79 ; V_17 < V_70 -> V_80 ; V_17 ++ , V_74 ++ ) {
if ( * V_74 == * V_70 -> V_75 )
break;
V_63 = F_37 ( V_2 , * V_74 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
}
for ( V_17 = 0 ; V_17 < V_70 -> V_81 ; V_17 ++ ) {
V_63 = F_37 ( V_2 , V_70 -> V_82 [ V_17 ] . V_83 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
}
for ( V_17 = 0 , V_74 = V_70 -> V_84 ; V_17 < V_70 -> V_85 ; V_17 ++ , V_74 ++ ) {
V_63 = F_37 ( V_2 , * V_74 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
}
V_63 = F_37 ( V_2 , V_70 -> V_86 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_37 ( V_2 , V_70 -> V_87 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
if ( V_14 -> V_35 )
V_14 -> V_35 ( V_2 , V_14 ) ;
if ( V_14 -> V_28 ) {
struct V_13 * V_29 =
F_8 ( V_2 , V_14 -> V_28 ) ;
if ( V_29 && V_29 -> V_35 )
V_29 -> V_35 ( V_2 , V_29 ) ;
}
}
void F_42 ( struct V_1 * V_2 , unsigned int V_88 )
{
struct V_13 * V_89 ;
int V_19 = ( V_88 >> V_90 ) & 0x7f ;
V_89 = F_9 ( V_2 , V_19 ) ;
if ( ! V_89 )
return;
V_89 -> V_20 = 1 ;
F_41 ( V_2 , V_89 ) ;
F_25 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_16 ;
int V_17 , V_91 = 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 . V_18 ; V_17 ++ , V_14 ++ ) {
unsigned int V_92 ;
if ( ! V_14 -> V_3 || ! V_14 -> V_20 || V_14 -> V_24 )
continue;
V_92 = F_20 ( V_14 -> V_25 ) ;
F_16 ( V_2 , V_14 ) ;
if ( V_92 == F_20 ( V_14 -> V_25 ) )
continue;
V_91 = 1 ;
F_41 ( V_2 , V_14 ) ;
}
if ( V_91 )
F_25 ( V_2 ) ;
}
