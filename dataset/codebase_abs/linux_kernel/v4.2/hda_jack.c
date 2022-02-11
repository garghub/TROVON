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
if ( ! V_2 -> V_28 -> V_29 && V_18 -> V_18 )
F_13 ( V_2 -> V_30 , V_18 -> V_18 ) ;
for ( V_26 = V_18 -> V_31 ; V_26 ; V_26 = V_27 ) {
V_27 = V_26 -> V_27 ;
F_14 ( V_26 ) ;
}
}
F_15 ( & V_2 -> V_19 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( ! V_18 -> V_24 )
return;
if ( V_18 -> V_32 )
V_18 -> V_33 = V_16 ;
else
V_18 -> V_33 = F_6 ( V_2 , V_18 -> V_3 ) ;
if ( V_18 -> V_34 && ! F_17 ( V_2 , V_18 -> V_34 ) )
V_18 -> V_33 &= ~ V_16 ;
V_18 -> V_24 = 0 ;
if ( V_18 -> V_35 ) {
struct V_17 * V_36 =
F_8 ( V_2 , V_18 -> V_35 ) ;
if ( V_36 ) {
V_36 -> V_24 = 1 ;
F_16 ( V_2 , V_36 ) ;
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
return V_18 -> V_33 ;
}
return F_6 ( V_2 , V_3 ) ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_17 * V_18 = F_8 ( V_2 , V_3 ) ;
if ( V_18 && V_18 -> V_32 )
return V_37 ;
else if ( F_19 ( V_2 , V_3 ) & V_16 )
return V_38 ;
else
return V_39 ;
}
struct V_25 *
F_21 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_40 )
{
struct V_17 * V_18 ;
struct V_25 * V_31 = NULL ;
int V_41 ;
V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return F_22 ( - V_42 ) ;
if ( V_40 ) {
V_31 = F_23 ( sizeof( * V_31 ) , V_43 ) ;
if ( ! V_31 )
return F_22 ( - V_42 ) ;
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
V_41 = F_24 ( V_2 , V_3 , 0 ,
V_46 ,
V_47 | V_18 -> V_23 ) ;
if ( V_41 < 0 )
return F_22 ( V_41 ) ;
return V_31 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_26 ( F_21 ( V_2 , V_3 , NULL ) ) ;
}
int F_27 ( struct V_1 * V_2 , T_1 V_48 ,
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
void F_28 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_21 , V_52 ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 )
F_16 ( V_2 , V_18 ) ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 ) {
if ( ! V_18 -> V_18 || V_18 -> V_53 )
continue;
V_52 = F_29 ( V_18 -> V_33 ) ;
F_30 ( V_18 -> V_18 ,
V_52 ? V_18 -> type : 0 ) ;
}
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_54 = F_4 ( V_2 , V_3 ) ;
switch ( F_32 ( V_54 ) ) {
case V_55 :
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
case V_60 :
case V_61 :
return V_62 ;
case V_63 :
return V_64 ;
default:
return V_65 ;
}
}
static void F_33 ( struct V_66 * V_18 )
{
struct V_17 * V_67 = V_18 -> V_68 ;
V_67 -> V_3 = 0 ;
V_67 -> V_18 = NULL ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_69 , bool V_32 )
{
struct V_17 * V_18 ;
int V_41 , V_52 , type ;
V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return 0 ;
if ( V_18 -> V_18 )
return 0 ;
type = F_31 ( V_2 , V_3 ) ;
V_41 = F_35 ( V_2 -> V_30 , V_69 , type ,
& V_18 -> V_18 , true , V_32 ) ;
if ( V_41 < 0 )
return V_41 ;
V_18 -> V_32 = ! ! V_32 ;
V_18 -> type = type ;
V_18 -> V_18 -> V_68 = V_18 ;
V_18 -> V_18 -> V_70 = F_33 ;
V_52 = F_17 ( V_2 , V_3 ) ;
F_30 ( V_18 -> V_18 , V_52 ? V_18 -> type : 0 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_69 )
{
return F_34 ( V_2 , V_3 , V_69 , false ) ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_71 * V_72 ,
const char * V_73 )
{
unsigned int V_54 , V_74 ;
char V_69 [ V_75 ] ;
int V_41 ;
bool V_32 ;
if ( ! V_3 )
return 0 ;
V_54 = F_4 ( V_2 , V_3 ) ;
V_74 = F_38 ( V_54 ) ;
if ( V_74 == V_76 )
return 0 ;
V_32 = ( V_74 != V_77 ) ||
! F_1 ( V_2 , V_3 ) ;
if ( V_73 )
F_39 ( V_69 , V_73 , sizeof( V_69 ) ) ;
else
F_40 ( V_2 , V_3 , V_72 , V_69 , sizeof( V_69 ) , NULL ) ;
if ( V_32 )
strncat ( V_69 , L_1 , sizeof( V_69 ) - strlen ( V_69 ) - 1 ) ;
V_41 = F_34 ( V_2 , V_3 , V_69 , V_32 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( ! V_32 )
return F_25 ( V_2 , V_3 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
const struct V_71 * V_72 )
{
const T_1 * V_78 ;
int V_21 , V_41 ;
for ( V_21 = 0 ; V_21 < V_72 -> V_79 ; V_21 ++ ) {
if ( V_72 -> V_80 [ V_21 ] . V_81 ) {
if ( F_42 ( V_72 ) == 1 )
V_41 = F_37 ( V_2 , F_43 ( V_72 ) [ 0 ] ,
V_72 , L_2 ) ;
else
V_41 = F_37 ( V_2 , V_72 -> V_80 [ V_21 ] . V_82 ,
V_72 , L_2 ) ;
} else
V_41 = F_37 ( V_2 , V_72 -> V_80 [ V_21 ] . V_82 , V_72 ,
NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_78 = V_72 -> V_83 ; V_21 < V_72 -> V_84 ; V_21 ++ , V_78 ++ ) {
V_41 = F_37 ( V_2 , * V_78 , V_72 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_78 = V_72 -> V_85 ; V_21 < V_72 -> V_86 ; V_21 ++ , V_78 ++ ) {
if ( * V_78 == * V_72 -> V_83 )
break;
V_41 = F_37 ( V_2 , * V_78 , V_72 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_78 = V_72 -> V_87 ; V_21 < V_72 -> V_88 ; V_21 ++ , V_78 ++ ) {
if ( * V_78 == * V_72 -> V_83 )
break;
V_41 = F_37 ( V_2 , * V_78 , V_72 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_21 = 0 , V_78 = V_72 -> V_89 ; V_21 < V_72 -> V_90 ; V_21 ++ , V_78 ++ ) {
V_41 = F_37 ( V_2 , * V_78 , V_72 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_41 = F_37 ( V_2 , V_72 -> V_91 , V_72 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_37 ( V_2 , V_72 -> V_92 , V_72 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
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
void F_45 ( struct V_1 * V_2 , unsigned int V_93 )
{
struct V_17 * V_94 ;
int V_23 = ( V_93 >> V_95 ) & 0x7f ;
V_94 = F_9 ( V_2 , V_23 ) ;
if ( ! V_94 )
return;
V_94 -> V_24 = 1 ;
F_44 ( V_2 , V_94 ) ;
F_28 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 , V_96 = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
unsigned int V_97 ;
if ( ! V_18 -> V_3 || ! V_18 -> V_24 || V_18 -> V_32 )
continue;
V_97 = F_29 ( V_18 -> V_33 ) ;
F_16 ( V_2 , V_18 ) ;
if ( V_97 == F_29 ( V_18 -> V_33 ) )
continue;
V_96 = 1 ;
F_44 ( V_2 , V_18 ) ;
}
if ( V_96 )
F_28 ( V_2 ) ;
}
