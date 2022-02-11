bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
return false ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_5 ) )
return false ;
if ( F_3 ( F_4 ( V_2 , V_3 ) ) &
V_6 )
return false ;
if ( ! ( F_5 ( V_2 , V_3 ) & V_7 ) &&
! V_2 -> V_8 )
return false ;
return true ;
}
static T_2 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_9 ;
T_2 V_10 ;
if ( ! V_2 -> V_11 ) {
V_9 = F_2 ( V_2 , V_3 ) ;
if ( V_9 & V_12 )
F_7 ( V_2 , V_3 , 0 ,
V_13 , 0 ) ;
}
V_10 = F_7 ( V_2 , V_3 , 0 ,
V_14 , 0 ) ;
if ( V_2 -> V_15 )
V_10 ^= V_16 ;
return V_10 ;
}
struct V_17 *
F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 ;
if ( ! V_3 || ! V_18 )
return NULL ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 == V_3 )
return V_18 ;
return NULL ;
}
struct V_17 *
F_9 ( struct V_1 * V_2 , unsigned char V_23 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 ;
if ( ! V_23 || ! V_18 )
return NULL ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_23 == V_23 )
return V_18 ;
return NULL ;
}
struct V_17 *
F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_17 * V_18 = F_8 ( V_2 , V_3 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_11 ( & V_2 -> V_19 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_3 = V_3 ;
V_18 -> V_24 = 1 ;
V_18 -> V_23 = V_2 -> V_19 . V_22 ;
return V_18 ;
}
void F_12 ( struct V_1 * V_2 )
{
#ifdef F_13
if ( ! V_2 -> V_25 -> V_26 && V_2 -> V_19 . V_20 ) {
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
if ( V_18 -> V_18 )
F_14 ( V_2 -> V_25 -> V_27 , V_18 -> V_18 ) ;
}
}
#endif
F_15 ( & V_2 -> V_19 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( ! V_18 -> V_24 )
return;
if ( V_18 -> V_28 )
V_18 -> V_29 = V_16 ;
else
V_18 -> V_29 = F_6 ( V_2 , V_18 -> V_3 ) ;
if ( V_18 -> V_30 && ! F_17 ( V_2 , V_18 -> V_30 ) )
V_18 -> V_29 &= ~ V_16 ;
V_18 -> V_24 = 0 ;
if ( V_18 -> V_31 ) {
struct V_17 * V_32 =
F_8 ( V_2 , V_18 -> V_31 ) ;
if ( V_32 ) {
V_32 -> V_24 = 1 ;
F_16 ( V_2 , V_32 ) ;
}
}
}
void F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 )
V_18 -> V_24 = 1 ;
}
T_2 F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_17 * V_18 = F_8 ( V_2 , V_3 ) ;
if ( V_18 ) {
F_16 ( V_2 , V_18 ) ;
return V_18 -> V_29 ;
}
return F_6 ( V_2 , V_3 ) ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_33 = F_19 ( V_2 , V_3 ) ;
return F_20 ( V_33 ) ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_34 ,
T_3 V_35 )
{
struct V_17 * V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return - V_36 ;
if ( V_18 -> V_37 )
return 0 ;
V_18 -> V_37 = 1 ;
if ( V_34 )
V_18 -> V_34 = V_34 ;
if ( V_35 )
V_18 -> V_38 = V_35 ;
if ( V_2 -> V_8 > 0 )
return 0 ;
return F_22 ( V_2 , V_3 , 0 ,
V_39 ,
V_40 | V_18 -> V_23 ) ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_34 )
{
return F_21 ( V_2 , V_3 , V_34 , NULL ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_42 )
{
struct V_17 * V_32 = F_8 ( V_2 , V_41 ) ;
struct V_17 * V_43 = F_8 ( V_2 , V_42 ) ;
if ( ! V_32 || ! V_43 )
return - V_44 ;
V_32 -> V_30 = V_42 ;
V_43 -> V_31 = V_41 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_21 , V_45 ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 )
F_16 ( V_2 , V_18 ) ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 ) {
if ( ! V_18 -> V_46 )
continue;
V_45 = F_20 ( V_18 -> V_29 ) ;
F_26 ( V_2 -> V_25 -> V_27 , V_18 -> V_46 , V_45 ) ;
#ifdef F_13
if ( V_18 -> V_18 )
F_27 ( V_18 -> V_18 ,
V_45 ? V_18 -> type : 0 ) ;
#endif
}
}
static int F_28 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_47 = F_4 ( V_2 , V_3 ) ;
switch ( F_29 ( V_47 ) ) {
case V_48 :
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
case V_54 :
return V_55 ;
case V_56 :
return V_57 ;
default:
return V_58 ;
}
}
static void F_30 ( struct V_59 * V_18 )
{
struct V_17 * V_60 = V_18 -> V_61 ;
V_60 -> V_3 = 0 ;
V_60 -> V_18 = NULL ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_62 , int V_63 , bool V_28 )
{
struct V_17 * V_18 ;
struct V_64 * V_46 ;
int V_65 , V_45 ;
V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return 0 ;
if ( V_18 -> V_46 )
return 0 ;
V_46 = F_32 ( V_62 , V_63 , V_2 ) ;
if ( ! V_46 )
return - V_36 ;
V_65 = F_33 ( V_2 , V_3 , V_46 ) ;
if ( V_65 < 0 )
return V_65 ;
V_18 -> V_46 = V_46 ;
V_18 -> V_28 = ! ! V_28 ;
V_45 = F_17 ( V_2 , V_3 ) ;
F_26 ( V_2 -> V_25 -> V_27 , V_46 , V_45 ) ;
#ifdef F_13
if ( ! V_28 ) {
V_18 -> type = F_28 ( V_2 , V_3 ) ;
V_65 = F_34 ( V_2 -> V_25 -> V_27 , V_62 , V_18 -> type ,
& V_18 -> V_18 ) ;
if ( V_65 < 0 )
return V_65 ;
V_18 -> V_18 -> V_61 = V_18 ;
V_18 -> V_18 -> V_66 = F_30 ;
F_27 ( V_18 -> V_18 , V_45 ? V_18 -> type : 0 ) ;
}
#endif
return 0 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_62 , int V_63 )
{
return F_31 ( V_2 , V_3 , V_62 , V_63 , false ) ;
}
static int F_36 ( struct V_1 * V_2 , const char * V_62 , int V_63 )
{
struct V_17 * V_18 ;
int V_21 , V_67 = strlen ( V_62 ) ;
V_68:
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
if ( V_18 -> V_46 &&
! strncmp ( V_62 , V_18 -> V_46 -> V_69 . V_62 , V_67 ) &&
! strcmp ( L_1 , V_18 -> V_46 -> V_69 . V_62 + V_67 ) &&
V_18 -> V_46 -> V_69 . V_70 == V_63 ) {
V_63 ++ ;
goto V_68;
}
}
return V_63 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_71 * V_72 )
{
unsigned int V_47 , V_73 ;
char V_62 [ 44 ] ;
int V_63 , V_65 ;
bool V_28 ;
if ( ! V_3 )
return 0 ;
V_47 = F_4 ( V_2 , V_3 ) ;
V_73 = F_38 ( V_47 ) ;
if ( V_73 == V_74 )
return 0 ;
V_28 = ( V_73 != V_75 ) ||
! F_1 ( V_2 , V_3 ) ;
F_39 ( V_2 , V_3 , V_72 , V_62 , sizeof( V_62 ) , & V_63 ) ;
if ( V_28 )
strncat ( V_62 , L_2 , sizeof( V_62 ) - strlen ( V_62 ) - 1 ) ;
V_63 = F_36 ( V_2 , V_62 , V_63 ) ;
V_65 = F_31 ( V_2 , V_3 , V_62 , V_63 , V_28 ) ;
if ( V_65 < 0 )
return V_65 ;
if ( ! V_28 )
return F_23 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
const struct V_71 * V_72 )
{
const T_1 * V_76 ;
int V_21 , V_65 ;
for ( V_21 = 0 , V_76 = V_72 -> V_77 ; V_21 < V_72 -> V_78 ; V_21 ++ , V_76 ++ ) {
V_65 = F_37 ( V_2 , * V_76 , V_72 ) ;
if ( V_65 < 0 )
return V_65 ;
}
for ( V_21 = 0 , V_76 = V_72 -> V_79 ; V_21 < V_72 -> V_80 ; V_21 ++ , V_76 ++ ) {
if ( * V_76 == * V_72 -> V_77 )
break;
V_65 = F_37 ( V_2 , * V_76 , V_72 ) ;
if ( V_65 < 0 )
return V_65 ;
}
for ( V_21 = 0 , V_76 = V_72 -> V_81 ; V_21 < V_72 -> V_82 ; V_21 ++ , V_76 ++ ) {
if ( * V_76 == * V_72 -> V_77 )
break;
V_65 = F_37 ( V_2 , * V_76 , V_72 ) ;
if ( V_65 < 0 )
return V_65 ;
}
for ( V_21 = 0 ; V_21 < V_72 -> V_83 ; V_21 ++ ) {
V_65 = F_37 ( V_2 , V_72 -> V_84 [ V_21 ] . V_85 , V_72 ) ;
if ( V_65 < 0 )
return V_65 ;
}
for ( V_21 = 0 , V_76 = V_72 -> V_86 ; V_21 < V_72 -> V_87 ; V_21 ++ , V_76 ++ ) {
V_65 = F_37 ( V_2 , * V_76 , V_72 ) ;
if ( V_65 < 0 )
return V_65 ;
}
V_65 = F_37 ( V_2 , V_72 -> V_88 , V_72 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_37 ( V_2 , V_72 -> V_89 , V_72 ) ;
if ( V_65 < 0 )
return V_65 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( V_18 -> V_38 )
V_18 -> V_38 ( V_2 , V_18 ) ;
if ( V_18 -> V_31 ) {
struct V_17 * V_32 =
F_8 ( V_2 , V_18 -> V_31 ) ;
if ( V_32 && V_32 -> V_38 )
V_32 -> V_38 ( V_2 , V_32 ) ;
}
}
void F_42 ( struct V_1 * V_2 , unsigned int V_90 )
{
struct V_17 * V_91 ;
int V_23 = ( V_90 >> V_92 ) & 0x7f ;
V_91 = F_9 ( V_2 , V_23 ) ;
if ( ! V_91 )
return;
V_91 -> V_24 = 1 ;
F_41 ( V_2 , V_91 ) ;
F_25 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 , V_93 = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
unsigned int V_94 ;
if ( ! V_18 -> V_3 || ! V_18 -> V_24 || V_18 -> V_28 )
continue;
V_94 = F_20 ( V_18 -> V_29 ) ;
F_16 ( V_2 , V_18 ) ;
if ( V_94 == F_20 ( V_18 -> V_29 ) )
continue;
V_93 = 1 ;
F_41 ( V_2 , V_18 ) ;
}
if ( V_93 )
F_25 ( V_2 ) ;
}
