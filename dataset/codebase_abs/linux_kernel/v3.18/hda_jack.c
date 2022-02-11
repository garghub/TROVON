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
static struct V_17 *
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
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
struct V_25 * V_26 , * V_27 ;
#ifdef F_13
if ( ! V_2 -> V_28 -> V_29 && V_18 -> V_18 )
F_14 ( V_2 -> V_28 -> V_30 , V_18 -> V_18 ) ;
#endif
for ( V_26 = V_18 -> V_31 ; V_26 ; V_26 = V_27 ) {
V_27 = V_26 -> V_27 ;
F_15 ( V_26 ) ;
}
}
F_16 ( & V_2 -> V_19 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( ! V_18 -> V_24 )
return;
if ( V_18 -> V_32 )
V_18 -> V_33 = V_16 ;
else
V_18 -> V_33 = F_6 ( V_2 , V_18 -> V_3 ) ;
if ( V_18 -> V_34 && ! F_18 ( V_2 , V_18 -> V_34 ) )
V_18 -> V_33 &= ~ V_16 ;
V_18 -> V_24 = 0 ;
if ( V_18 -> V_35 ) {
struct V_17 * V_36 =
F_8 ( V_2 , V_18 -> V_35 ) ;
if ( V_36 ) {
V_36 -> V_24 = 1 ;
F_17 ( V_2 , V_36 ) ;
}
}
}
void F_19 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 )
V_18 -> V_24 = 1 ;
}
T_2 F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_17 * V_18 = F_8 ( V_2 , V_3 ) ;
if ( V_18 ) {
F_17 ( V_2 , V_18 ) ;
return V_18 -> V_33 ;
}
return F_6 ( V_2 , V_3 ) ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_17 * V_18 = F_8 ( V_2 , V_3 ) ;
if ( V_18 && V_18 -> V_32 )
return V_37 ;
else if ( F_20 ( V_2 , V_3 ) & V_16 )
return V_38 ;
else
return V_39 ;
}
struct V_25 *
F_22 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_40 )
{
struct V_17 * V_18 ;
struct V_25 * V_31 = NULL ;
int V_41 ;
V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return F_23 ( - V_42 ) ;
if ( V_40 ) {
V_31 = F_24 ( sizeof( * V_31 ) , V_43 ) ;
if ( ! V_31 )
return F_23 ( - V_42 ) ;
V_31 -> V_40 = V_40 ;
V_31 -> V_44 = V_18 ;
V_31 -> V_27 = V_18 -> V_31 ;
V_18 -> V_31 = V_31 ;
}
if ( V_18 -> V_45 )
return V_31 ;
V_18 -> V_45 = 1 ;
if ( V_2 -> V_8 > 0 )
return V_31 ;
V_41 = F_25 ( V_2 , V_3 , 0 ,
V_46 ,
V_47 | V_18 -> V_23 ) ;
if ( V_41 < 0 )
return F_23 ( V_41 ) ;
return V_31 ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_27 ( F_22 ( V_2 , V_3 , NULL ) ) ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_48 ,
T_1 V_49 )
{
struct V_17 * V_36 = F_10 ( V_2 , V_48 ) ;
struct V_17 * V_50 = F_10 ( V_2 , V_49 ) ;
if ( ! V_36 || ! V_50 )
return - V_51 ;
V_36 -> V_34 = V_49 ;
V_50 -> V_35 = V_48 ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_21 , V_52 ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 )
F_17 ( V_2 , V_18 ) ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 ) {
if ( ! V_18 -> V_53 || V_18 -> V_54 )
continue;
V_52 = F_30 ( V_18 -> V_33 ) ;
F_31 ( V_2 -> V_28 -> V_30 , V_18 -> V_53 , V_52 ) ;
#ifdef F_13
if ( V_18 -> V_18 )
F_32 ( V_18 -> V_18 ,
V_52 ? V_18 -> type : 0 ) ;
#endif
}
}
static int F_33 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_55 = F_4 ( V_2 , V_3 ) ;
switch ( F_34 ( V_55 ) ) {
case V_56 :
case V_57 :
return V_58 ;
case V_59 :
return V_60 ;
case V_61 :
case V_62 :
return V_63 ;
case V_64 :
return V_65 ;
default:
return V_66 ;
}
}
static void F_35 ( struct V_67 * V_18 )
{
struct V_17 * V_68 = V_18 -> V_69 ;
V_68 -> V_3 = 0 ;
V_68 -> V_18 = NULL ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_70 , int V_71 , bool V_32 )
{
struct V_17 * V_18 ;
struct V_72 * V_53 ;
int V_41 , V_52 ;
V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return 0 ;
if ( V_18 -> V_53 )
return 0 ;
V_53 = F_37 ( V_70 , V_71 , V_2 ) ;
if ( ! V_53 )
return - V_42 ;
V_41 = F_38 ( V_2 , V_3 , V_53 ) ;
if ( V_41 < 0 )
return V_41 ;
V_18 -> V_53 = V_53 ;
V_18 -> V_32 = ! ! V_32 ;
V_52 = F_18 ( V_2 , V_3 ) ;
F_31 ( V_2 -> V_28 -> V_30 , V_53 , V_52 ) ;
#ifdef F_13
if ( ! V_32 ) {
V_18 -> type = F_33 ( V_2 , V_3 ) ;
V_41 = F_39 ( V_2 -> V_28 -> V_30 , V_70 , V_18 -> type ,
& V_18 -> V_18 ) ;
if ( V_41 < 0 )
return V_41 ;
V_18 -> V_18 -> V_69 = V_18 ;
V_18 -> V_18 -> V_73 = F_35 ;
F_32 ( V_18 -> V_18 , V_52 ? V_18 -> type : 0 ) ;
}
#endif
return 0 ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_70 , int V_71 )
{
return F_36 ( V_2 , V_3 , V_70 , V_71 , false ) ;
}
static int F_41 ( struct V_1 * V_2 , const char * V_70 , int V_71 )
{
struct V_17 * V_18 ;
int V_21 , V_74 = strlen ( V_70 ) ;
V_75:
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
if ( V_18 -> V_53 &&
! strncmp ( V_70 , V_18 -> V_53 -> V_76 . V_70 , V_74 ) &&
! strcmp ( L_1 , V_18 -> V_53 -> V_76 . V_70 + V_74 ) &&
V_18 -> V_53 -> V_76 . V_77 == V_71 ) {
V_71 ++ ;
goto V_75;
}
}
return V_71 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_78 * V_79 ,
const char * V_80 )
{
unsigned int V_55 , V_81 ;
char V_70 [ V_82 ] ;
int V_71 , V_41 ;
bool V_32 ;
if ( ! V_3 )
return 0 ;
V_55 = F_4 ( V_2 , V_3 ) ;
V_81 = F_43 ( V_55 ) ;
if ( V_81 == V_83 )
return 0 ;
V_32 = ( V_81 != V_84 ) ||
! F_1 ( V_2 , V_3 ) ;
if ( V_80 ) {
F_44 ( V_70 , V_80 , sizeof( V_70 ) ) ;
V_71 = 0 ;
} else
F_45 ( V_2 , V_3 , V_79 , V_70 , sizeof( V_70 ) , & V_71 ) ;
if ( V_32 )
strncat ( V_70 , L_2 , sizeof( V_70 ) - strlen ( V_70 ) - 1 ) ;
V_71 = F_41 ( V_2 , V_70 , V_71 ) ;
V_41 = F_36 ( V_2 , V_3 , V_70 , V_71 , V_32 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( ! V_32 )
return F_26 ( V_2 , V_3 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
const T_1 * V_85 ;
int V_21 , V_41 ;
for ( V_21 = 0 ; V_21 < V_79 -> V_86 ; V_21 ++ ) {
if ( V_79 -> V_87 [ V_21 ] . V_88 ) {
if ( F_47 ( V_79 ) == 1 )
V_41 = F_42 ( V_2 , F_48 ( V_79 ) [ 0 ] ,
V_79 , L_3 ) ;
else
V_41 = F_42 ( V_2 , V_79 -> V_87 [ V_21 ] . V_89 ,
V_79 , L_3 ) ;
} else
V_41 = F_42 ( V_2 , V_79 -> V_87 [ V_21 ] . V_89 , V_79 ,
NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_85 = V_79 -> V_90 ; V_21 < V_79 -> V_91 ; V_21 ++ , V_85 ++ ) {
V_41 = F_42 ( V_2 , * V_85 , V_79 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_85 = V_79 -> V_92 ; V_21 < V_79 -> V_93 ; V_21 ++ , V_85 ++ ) {
if ( * V_85 == * V_79 -> V_90 )
break;
V_41 = F_42 ( V_2 , * V_85 , V_79 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_85 = V_79 -> V_94 ; V_21 < V_79 -> V_95 ; V_21 ++ , V_85 ++ ) {
if ( * V_85 == * V_79 -> V_90 )
break;
V_41 = F_42 ( V_2 , * V_85 , V_79 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_85 = V_79 -> V_96 ; V_21 < V_79 -> V_97 ; V_21 ++ , V_85 ++ ) {
V_41 = F_42 ( V_2 , * V_85 , V_79 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_41 = F_42 ( V_2 , V_79 -> V_98 , V_79 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_42 ( V_2 , V_79 -> V_99 , V_79 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_25 * V_26 ;
for ( V_26 = V_18 -> V_31 ; V_26 ; V_26 = V_26 -> V_27 )
V_26 -> V_40 ( V_2 , V_26 ) ;
if ( V_18 -> V_35 ) {
struct V_17 * V_36 =
F_8 ( V_2 , V_18 -> V_35 ) ;
if ( V_36 ) {
for ( V_26 = V_36 -> V_31 ; V_26 ; V_26 = V_26 -> V_27 )
V_26 -> V_40 ( V_2 , V_26 ) ;
}
}
}
void F_50 ( struct V_1 * V_2 , unsigned int V_100 )
{
struct V_17 * V_101 ;
int V_23 = ( V_100 >> V_102 ) & 0x7f ;
V_101 = F_9 ( V_2 , V_23 ) ;
if ( ! V_101 )
return;
V_101 -> V_24 = 1 ;
F_49 ( V_2 , V_101 ) ;
F_29 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 , V_103 = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
unsigned int V_104 ;
if ( ! V_18 -> V_3 || ! V_18 -> V_24 || V_18 -> V_32 )
continue;
V_104 = F_30 ( V_18 -> V_33 ) ;
F_17 ( V_2 , V_18 ) ;
if ( V_104 == F_30 ( V_18 -> V_33 ) )
continue;
V_103 = 1 ;
F_49 ( V_2 , V_18 ) ;
}
if ( V_103 )
F_29 ( V_2 ) ;
}
