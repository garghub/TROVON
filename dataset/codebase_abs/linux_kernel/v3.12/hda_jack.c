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
if ( ! V_18 -> V_48 )
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
unsigned int V_49 = F_4 ( V_2 , V_3 ) ;
switch ( F_30 ( V_49 ) ) {
case V_50 :
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
default:
return V_60 ;
}
}
static void F_31 ( struct V_61 * V_18 )
{
struct V_17 * V_62 = V_18 -> V_63 ;
V_62 -> V_3 = 0 ;
V_62 -> V_18 = NULL ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_64 , int V_65 , bool V_28 )
{
struct V_17 * V_18 ;
struct V_66 * V_48 ;
int V_67 , V_47 ;
V_18 = F_10 ( V_2 , V_3 ) ;
if ( ! V_18 )
return 0 ;
if ( V_18 -> V_48 )
return 0 ;
V_48 = F_33 ( V_64 , V_65 , V_2 ) ;
if ( ! V_48 )
return - V_38 ;
V_67 = F_34 ( V_2 , V_3 , V_48 ) ;
if ( V_67 < 0 )
return V_67 ;
V_18 -> V_48 = V_48 ;
V_18 -> V_28 = ! ! V_28 ;
V_47 = F_17 ( V_2 , V_3 ) ;
F_27 ( V_2 -> V_25 -> V_27 , V_48 , V_47 ) ;
#ifdef F_13
if ( ! V_28 ) {
V_18 -> type = F_29 ( V_2 , V_3 ) ;
V_67 = F_35 ( V_2 -> V_25 -> V_27 , V_64 , V_18 -> type ,
& V_18 -> V_18 ) ;
if ( V_67 < 0 )
return V_67 ;
V_18 -> V_18 -> V_63 = V_18 ;
V_18 -> V_18 -> V_68 = F_31 ;
F_28 ( V_18 -> V_18 , V_47 ? V_18 -> type : 0 ) ;
}
#endif
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_64 , int V_65 )
{
return F_32 ( V_2 , V_3 , V_64 , V_65 , false ) ;
}
static int F_37 ( struct V_1 * V_2 , const char * V_64 , int V_65 )
{
struct V_17 * V_18 ;
int V_21 , V_69 = strlen ( V_64 ) ;
V_70:
V_18 = V_2 -> V_19 . V_20 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
if ( V_18 -> V_48 &&
! strncmp ( V_64 , V_18 -> V_48 -> V_71 . V_64 , V_69 ) &&
! strcmp ( L_1 , V_18 -> V_48 -> V_71 . V_64 + V_69 ) &&
V_18 -> V_48 -> V_71 . V_72 == V_65 ) {
V_65 ++ ;
goto V_70;
}
}
return V_65 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_73 * V_74 ,
const char * V_75 )
{
unsigned int V_49 , V_76 ;
char V_64 [ V_77 ] ;
int V_65 , V_67 ;
bool V_28 ;
if ( ! V_3 )
return 0 ;
V_49 = F_4 ( V_2 , V_3 ) ;
V_76 = F_39 ( V_49 ) ;
if ( V_76 == V_78 )
return 0 ;
V_28 = ( V_76 != V_79 ) ||
! F_1 ( V_2 , V_3 ) ;
if ( V_75 ) {
F_40 ( V_64 , V_75 , sizeof( V_64 ) ) ;
V_65 = 0 ;
} else
F_41 ( V_2 , V_3 , V_74 , V_64 , sizeof( V_64 ) , & V_65 ) ;
if ( V_28 )
strncat ( V_64 , L_2 , sizeof( V_64 ) - strlen ( V_64 ) - 1 ) ;
V_65 = F_37 ( V_2 , V_64 , V_65 ) ;
V_67 = F_32 ( V_2 , V_3 , V_64 , V_65 , V_28 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_28 )
return F_23 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
const T_1 * V_80 ;
int V_21 , V_67 ;
for ( V_21 = 0 ; V_21 < V_74 -> V_81 ; V_21 ++ ) {
if ( V_74 -> V_82 [ V_21 ] . V_83 ) {
if ( F_43 ( V_74 ) == 1 )
V_67 = F_38 ( V_2 , F_44 ( V_74 ) [ 0 ] ,
V_74 , L_3 ) ;
else
V_67 = F_38 ( V_2 , V_74 -> V_82 [ V_21 ] . V_84 ,
V_74 , L_3 ) ;
} else
V_67 = F_38 ( V_2 , V_74 -> V_82 [ V_21 ] . V_84 , V_74 ,
NULL ) ;
if ( V_67 < 0 )
return V_67 ;
}
for ( V_21 = 0 , V_80 = V_74 -> V_85 ; V_21 < V_74 -> V_86 ; V_21 ++ , V_80 ++ ) {
V_67 = F_38 ( V_2 , * V_80 , V_74 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
}
for ( V_21 = 0 , V_80 = V_74 -> V_87 ; V_21 < V_74 -> V_88 ; V_21 ++ , V_80 ++ ) {
if ( * V_80 == * V_74 -> V_85 )
break;
V_67 = F_38 ( V_2 , * V_80 , V_74 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
}
for ( V_21 = 0 , V_80 = V_74 -> V_89 ; V_21 < V_74 -> V_90 ; V_21 ++ , V_80 ++ ) {
if ( * V_80 == * V_74 -> V_85 )
break;
V_67 = F_38 ( V_2 , * V_80 , V_74 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
}
for ( V_21 = 0 , V_80 = V_74 -> V_91 ; V_21 < V_74 -> V_92 ; V_21 ++ , V_80 ++ ) {
V_67 = F_38 ( V_2 , * V_80 , V_74 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
}
V_67 = F_38 ( V_2 , V_74 -> V_93 , V_74 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_38 ( V_2 , V_74 -> V_94 , V_74 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
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
void F_46 ( struct V_1 * V_2 , unsigned int V_95 )
{
struct V_17 * V_96 ;
int V_23 = ( V_95 >> V_97 ) & 0x7f ;
V_96 = F_9 ( V_2 , V_23 ) ;
if ( ! V_96 )
return;
V_96 -> V_24 = 1 ;
F_45 ( V_2 , V_96 ) ;
F_25 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 . V_20 ;
int V_21 , V_98 = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 . V_22 ; V_21 ++ , V_18 ++ ) {
unsigned int V_99 ;
if ( ! V_18 -> V_3 || ! V_18 -> V_24 || V_18 -> V_28 )
continue;
V_99 = F_26 ( V_18 -> V_29 ) ;
F_16 ( V_2 , V_18 ) ;
if ( V_99 == F_26 ( V_18 -> V_29 ) )
continue;
V_98 = 1 ;
F_45 ( V_2 , V_18 ) ;
}
if ( V_98 )
F_25 ( V_2 ) ;
}
