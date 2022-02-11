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
int F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_17 * V_18 = F_8 ( V_2 , V_3 ) ;
if ( V_18 && V_18 -> V_28 )
return V_33 ;
else if ( F_19 ( V_2 , V_3 ) & V_16 )
return V_34 ;
else
return V_35 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_36 ,
T_3 V_37 )
{
struct V_17 * V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return - V_38 ;
if ( V_18 -> V_39 )
return 0 ;
V_18 -> V_39 = 1 ;
if ( V_36 )
V_18 -> V_36 = V_36 ;
if ( V_37 )
V_18 -> V_40 = V_37 ;
if ( V_2 -> V_8 > 0 )
return 0 ;
return F_22 ( V_2 , V_3 , 0 ,
V_41 ,
V_42 | V_18 -> V_23 ) ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_36 )
{
return F_21 ( V_2 , V_3 , V_36 , NULL ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_43 ,
T_1 V_44 )
{
struct V_17 * V_32 = F_10 ( V_2 , V_43 ) ;
struct V_17 * V_45 = F_10 ( V_2 , V_44 ) ;
if ( ! V_32 || ! V_45 )
return - V_46 ;
V_32 -> V_30 = V_44 ;
V_45 -> V_31 = V_43 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_21 , V_47 ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 )
F_16 ( V_2 , V_18 ) ;
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ )
if ( V_18 -> V_3 ) {
if ( ! V_18 -> V_48 || V_18 -> V_49 )
continue;
V_47 = F_26 ( V_18 -> V_29 ) ;
F_27 ( V_2 -> V_25 -> V_27 , V_18 -> V_48 , V_47 ) ;
#ifdef F_13
if ( V_18 -> V_18 )
F_28 ( V_18 -> V_18 ,
V_47 ? V_18 -> type : 0 ) ;
#endif
}
}
static int F_29 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_50 = F_4 ( V_2 , V_3 ) ;
switch ( F_30 ( V_50 ) ) {
case V_51 :
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
case V_56 :
case V_57 :
return V_58 ;
case V_59 :
return V_60 ;
default:
return V_61 ;
}
}
static void F_31 ( struct V_62 * V_18 )
{
struct V_17 * V_63 = V_18 -> V_64 ;
V_63 -> V_3 = 0 ;
V_63 -> V_18 = NULL ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_65 , int V_66 , bool V_28 )
{
struct V_17 * V_18 ;
struct V_67 * V_48 ;
int V_68 , V_47 ;
V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return 0 ;
if ( V_18 -> V_48 )
return 0 ;
V_48 = F_33 ( V_65 , V_66 , V_2 ) ;
if ( ! V_48 )
return - V_38 ;
V_68 = F_34 ( V_2 , V_3 , V_48 ) ;
if ( V_68 < 0 )
return V_68 ;
V_18 -> V_48 = V_48 ;
V_18 -> V_28 = ! ! V_28 ;
V_47 = F_17 ( V_2 , V_3 ) ;
F_27 ( V_2 -> V_25 -> V_27 , V_48 , V_47 ) ;
#ifdef F_13
if ( ! V_28 ) {
V_18 -> type = F_29 ( V_2 , V_3 ) ;
V_68 = F_35 ( V_2 -> V_25 -> V_27 , V_65 , V_18 -> type ,
& V_18 -> V_18 ) ;
if ( V_68 < 0 )
return V_68 ;
V_18 -> V_18 -> V_64 = V_18 ;
V_18 -> V_18 -> V_69 = F_31 ;
F_28 ( V_18 -> V_18 , V_47 ? V_18 -> type : 0 ) ;
}
#endif
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_65 , int V_66 )
{
return F_32 ( V_2 , V_3 , V_65 , V_66 , false ) ;
}
static int F_37 ( struct V_1 * V_2 , const char * V_65 , int V_66 )
{
struct V_17 * V_18 ;
int V_21 , V_70 = strlen ( V_65 ) ;
V_71:
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
if ( V_18 -> V_48 &&
! strncmp ( V_65 , V_18 -> V_48 -> V_72 . V_65 , V_70 ) &&
! strcmp ( L_1 , V_18 -> V_48 -> V_72 . V_65 + V_70 ) &&
V_18 -> V_48 -> V_72 . V_73 == V_66 ) {
V_66 ++ ;
goto V_71;
}
}
return V_66 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_74 * V_75 ,
const char * V_76 )
{
unsigned int V_50 , V_77 ;
char V_65 [ V_78 ] ;
int V_66 , V_68 ;
bool V_28 ;
if ( ! V_3 )
return 0 ;
V_50 = F_4 ( V_2 , V_3 ) ;
V_77 = F_39 ( V_50 ) ;
if ( V_77 == V_79 )
return 0 ;
V_28 = ( V_77 != V_80 ) ||
! F_1 ( V_2 , V_3 ) ;
if ( V_76 ) {
F_40 ( V_65 , V_76 , sizeof( V_65 ) ) ;
V_66 = 0 ;
} else
F_41 ( V_2 , V_3 , V_75 , V_65 , sizeof( V_65 ) , & V_66 ) ;
if ( V_28 )
strncat ( V_65 , L_2 , sizeof( V_65 ) - strlen ( V_65 ) - 1 ) ;
V_66 = F_37 ( V_2 , V_65 , V_66 ) ;
V_68 = F_32 ( V_2 , V_3 , V_65 , V_66 , V_28 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( ! V_28 )
return F_23 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
const struct V_74 * V_75 )
{
const T_1 * V_81 ;
int V_21 , V_68 ;
for ( V_21 = 0 ; V_21 < V_75 -> V_82 ; V_21 ++ ) {
if ( V_75 -> V_83 [ V_21 ] . V_84 ) {
if ( F_43 ( V_75 ) == 1 )
V_68 = F_38 ( V_2 , F_44 ( V_75 ) [ 0 ] ,
V_75 , L_3 ) ;
else
V_68 = F_38 ( V_2 , V_75 -> V_83 [ V_21 ] . V_85 ,
V_75 , L_3 ) ;
} else
V_68 = F_38 ( V_2 , V_75 -> V_83 [ V_21 ] . V_85 , V_75 ,
NULL ) ;
if ( V_68 < 0 )
return V_68 ;
}
for ( V_21 = 0 , V_81 = V_75 -> V_86 ; V_21 < V_75 -> V_87 ; V_21 ++ , V_81 ++ ) {
V_68 = F_38 ( V_2 , * V_81 , V_75 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
}
for ( V_21 = 0 , V_81 = V_75 -> V_88 ; V_21 < V_75 -> V_89 ; V_21 ++ , V_81 ++ ) {
if ( * V_81 == * V_75 -> V_86 )
break;
V_68 = F_38 ( V_2 , * V_81 , V_75 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
}
for ( V_21 = 0 , V_81 = V_75 -> V_90 ; V_21 < V_75 -> V_91 ; V_21 ++ , V_81 ++ ) {
if ( * V_81 == * V_75 -> V_86 )
break;
V_68 = F_38 ( V_2 , * V_81 , V_75 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
}
for ( V_21 = 0 , V_81 = V_75 -> V_92 ; V_21 < V_75 -> V_93 ; V_21 ++ , V_81 ++ ) {
V_68 = F_38 ( V_2 , * V_81 , V_75 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
}
V_68 = F_38 ( V_2 , V_75 -> V_94 , V_75 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_38 ( V_2 , V_75 -> V_95 , V_75 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( V_18 -> V_40 )
V_18 -> V_40 ( V_2 , V_18 ) ;
if ( V_18 -> V_31 ) {
struct V_17 * V_32 =
F_8 ( V_2 , V_18 -> V_31 ) ;
if ( V_32 && V_32 -> V_40 )
V_32 -> V_40 ( V_2 , V_32 ) ;
}
}
void F_46 ( struct V_1 * V_2 , unsigned int V_96 )
{
struct V_17 * V_97 ;
int V_23 = ( V_96 >> V_98 ) & 0x7f ;
V_97 = F_9 ( V_2 , V_23 ) ;
if ( ! V_97 )
return;
V_97 -> V_24 = 1 ;
F_45 ( V_2 , V_97 ) ;
F_25 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 , V_99 = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
unsigned int V_100 ;
if ( ! V_18 -> V_3 || ! V_18 -> V_24 || V_18 -> V_28 )
continue;
V_100 = F_26 ( V_18 -> V_29 ) ;
F_16 ( V_2 , V_18 ) ;
if ( V_100 == F_26 ( V_18 -> V_29 ) )
continue;
V_99 = 1 ;
F_45 ( V_2 , V_18 ) ;
}
if ( V_99 )
F_25 ( V_2 ) ;
}
