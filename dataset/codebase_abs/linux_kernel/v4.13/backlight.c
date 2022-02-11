static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = V_4 ;
int V_9 = V_8 -> V_10 -> V_9 ;
int V_11 = 0 ;
if ( V_3 != V_12 && V_3 != V_13 )
return 0 ;
V_6 = F_2 ( V_2 , struct V_5 , V_14 ) ;
F_3 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 )
if ( ! V_6 -> V_16 -> V_17 ||
V_6 -> V_16 -> V_17 ( V_6 , V_8 -> V_10 ) ) {
V_11 = * ( int * ) V_8 -> V_4 ;
if ( V_11 == V_18 &&
! V_6 -> V_19 [ V_9 ] ) {
V_6 -> V_19 [ V_9 ] = true ;
if ( ! V_6 -> V_20 ++ ) {
V_6 -> V_21 . V_22 &= ~ V_23 ;
V_6 -> V_21 . V_11 = V_18 ;
F_4 ( V_6 ) ;
}
} else if ( V_11 != V_18 &&
V_6 -> V_19 [ V_9 ] ) {
V_6 -> V_19 [ V_9 ] = false ;
if ( ! ( -- V_6 -> V_20 ) ) {
V_6 -> V_21 . V_22 |= V_23 ;
V_6 -> V_21 . V_11 = V_11 ;
F_4 ( V_6 ) ;
}
}
}
F_5 ( & V_6 -> V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
memset ( & V_6 -> V_14 , 0 , sizeof( V_6 -> V_14 ) ) ;
V_6 -> V_14 . V_24 = F_1 ;
return F_7 ( & V_6 -> V_14 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
F_9 ( & V_6 -> V_14 ) ;
}
static inline int F_6 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void F_8 ( struct V_5 * V_6 )
{
}
static void F_10 ( struct V_5 * V_6 ,
enum V_25 V_26 )
{
char * V_27 [ 2 ] ;
switch ( V_26 ) {
case V_28 :
V_27 [ 0 ] = L_1 ;
break;
case V_29 :
V_27 [ 0 ] = L_2 ;
break;
default:
V_27 [ 0 ] = L_3 ;
break;
}
V_27 [ 1 ] = NULL ;
F_11 ( & V_6 -> V_30 . V_31 , V_32 , V_27 ) ;
F_12 ( & V_6 -> V_30 . V_31 , NULL , L_4 ) ;
}
static T_1 F_13 ( struct V_33 * V_30 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
return sprintf ( V_36 , L_5 , V_6 -> V_21 . V_37 ) ;
}
static T_1 F_15 ( struct V_33 * V_30 , struct V_34 * V_35 ,
const char * V_36 , T_2 V_38 )
{
int V_39 ;
struct V_5 * V_6 = F_14 ( V_30 ) ;
unsigned long V_37 , V_40 ;
V_39 = F_16 ( V_36 , 0 , & V_37 ) ;
if ( V_39 )
return V_39 ;
V_39 = - V_41 ;
F_3 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 ) {
F_17 ( L_6 , V_37 ) ;
if ( V_6 -> V_21 . V_37 != V_37 ) {
V_40 = V_6 -> V_21 . V_37 ;
V_6 -> V_21 . V_37 = V_37 ;
V_39 = F_4 ( V_6 ) ;
if ( V_39 )
V_6 -> V_21 . V_37 = V_40 ;
else
V_39 = V_38 ;
} else {
V_39 = V_38 ;
}
}
F_5 ( & V_6 -> V_15 ) ;
return V_39 ;
}
static T_1 F_18 ( struct V_33 * V_30 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
return sprintf ( V_36 , L_5 , V_6 -> V_21 . V_42 ) ;
}
int F_19 ( struct V_5 * V_6 ,
unsigned long V_42 )
{
int V_39 = - V_41 ;
F_3 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 ) {
if ( V_42 > V_6 -> V_21 . V_43 )
V_39 = - V_44 ;
else {
F_17 ( L_7 , V_42 ) ;
V_6 -> V_21 . V_42 = V_42 ;
V_39 = F_4 ( V_6 ) ;
}
}
F_5 ( & V_6 -> V_15 ) ;
F_10 ( V_6 , V_28 ) ;
return V_39 ;
}
static T_1 F_20 ( struct V_33 * V_30 ,
struct V_34 * V_35 , const char * V_36 , T_2 V_38 )
{
int V_39 ;
struct V_5 * V_6 = F_14 ( V_30 ) ;
unsigned long V_42 ;
V_39 = F_16 ( V_36 , 0 , & V_42 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_19 ( V_6 , V_42 ) ;
return V_39 ? V_39 : V_38 ;
}
static T_1 F_21 ( struct V_33 * V_30 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
return sprintf ( V_36 , L_8 , V_45 [ V_6 -> V_21 . type ] ) ;
}
static T_1 F_22 ( struct V_33 * V_30 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
return sprintf ( V_36 , L_5 , V_6 -> V_21 . V_43 ) ;
}
static T_1 F_23 ( struct V_33 * V_30 ,
struct V_34 * V_35 , char * V_36 )
{
int V_39 = - V_41 ;
struct V_5 * V_6 = F_14 ( V_30 ) ;
F_3 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 && V_6 -> V_16 -> V_46 )
V_39 = sprintf ( V_36 , L_5 , V_6 -> V_16 -> V_46 ( V_6 ) ) ;
else
V_39 = sprintf ( V_36 , L_5 , V_6 -> V_21 . V_42 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_39 ;
}
static int F_24 ( struct V_33 * V_30 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
F_3 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 && V_6 -> V_16 -> V_47 & V_48 ) {
V_6 -> V_21 . V_22 |= V_49 ;
F_4 ( V_6 ) ;
}
F_5 ( & V_6 -> V_15 ) ;
return 0 ;
}
static int F_25 ( struct V_33 * V_30 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
F_3 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 && V_6 -> V_16 -> V_47 & V_48 ) {
V_6 -> V_21 . V_22 &= ~ V_49 ;
F_4 ( V_6 ) ;
}
F_5 ( & V_6 -> V_15 ) ;
return 0 ;
}
static void F_26 ( struct V_33 * V_30 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
F_27 ( V_6 ) ;
}
void F_28 ( struct V_5 * V_6 ,
enum V_25 V_26 )
{
F_3 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 && V_6 -> V_16 -> V_46 )
V_6 -> V_21 . V_42 = V_6 -> V_16 -> V_46 ( V_6 ) ;
F_5 ( & V_6 -> V_15 ) ;
F_10 ( V_6 , V_26 ) ;
}
struct V_5 * F_29 ( const char * V_50 ,
struct V_33 * V_51 , void * V_52 , const struct V_53 * V_16 ,
const struct V_54 * V_21 )
{
struct V_5 * V_55 ;
int V_39 ;
F_17 ( L_9 , V_50 ) ;
V_55 = F_30 ( sizeof( struct V_5 ) , V_56 ) ;
if ( ! V_55 )
return F_31 ( - V_57 ) ;
F_32 ( & V_55 -> V_58 ) ;
F_32 ( & V_55 -> V_15 ) ;
V_55 -> V_30 . V_59 = V_60 ;
V_55 -> V_30 . V_51 = V_51 ;
V_55 -> V_30 . V_61 = F_26 ;
F_33 ( & V_55 -> V_30 , L_10 , V_50 ) ;
F_34 ( & V_55 -> V_30 , V_52 ) ;
if ( V_21 ) {
memcpy ( & V_55 -> V_21 , V_21 ,
sizeof( struct V_54 ) ) ;
if ( V_21 -> type <= 0 || V_21 -> type >= V_62 ) {
F_35 ( 1 , L_11 , V_50 ) ;
V_55 -> V_21 . type = V_63 ;
}
} else {
V_55 -> V_21 . type = V_63 ;
}
V_39 = F_36 ( & V_55 -> V_30 ) ;
if ( V_39 ) {
F_37 ( & V_55 -> V_30 ) ;
return F_31 ( V_39 ) ;
}
V_39 = F_6 ( V_55 ) ;
if ( V_39 ) {
F_38 ( & V_55 -> V_30 ) ;
return F_31 ( V_39 ) ;
}
V_55 -> V_16 = V_16 ;
#ifdef F_39
F_3 ( & V_64 ) ;
if ( ! V_65 )
V_65 = V_55 ;
F_5 ( & V_64 ) ;
#endif
F_3 ( & V_66 ) ;
F_40 ( & V_55 -> V_67 , & V_68 ) ;
F_5 ( & V_66 ) ;
F_41 ( & V_69 ,
V_70 , V_55 ) ;
return V_55 ;
}
struct V_5 * F_42 ( enum V_71 type )
{
bool V_72 = false ;
struct V_5 * V_6 ;
F_3 ( & V_66 ) ;
F_43 (bd, &backlight_dev_list, entry) {
if ( V_6 -> V_21 . type == type ) {
V_72 = true ;
break;
}
}
F_5 ( & V_66 ) ;
return V_72 ? V_6 : NULL ;
}
void F_44 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_3 ( & V_66 ) ;
F_45 ( & V_6 -> V_67 ) ;
F_5 ( & V_66 ) ;
#ifdef F_39
F_3 ( & V_64 ) ;
if ( V_65 == V_6 )
V_65 = NULL ;
F_5 ( & V_64 ) ;
#endif
F_41 ( & V_69 ,
V_73 , V_6 ) ;
F_3 ( & V_6 -> V_15 ) ;
V_6 -> V_16 = NULL ;
F_5 ( & V_6 -> V_15 ) ;
F_8 ( V_6 ) ;
F_38 ( & V_6 -> V_30 ) ;
}
static void F_46 ( struct V_33 * V_30 , void * V_74 )
{
struct V_5 * V_75 = * (struct V_5 * * ) V_74 ;
F_44 ( V_75 ) ;
}
static int F_47 ( struct V_33 * V_30 , void * V_74 ,
void * V_4 )
{
struct V_5 * * V_76 = V_74 ;
return * V_76 == V_4 ;
}
int F_48 ( struct V_1 * V_77 )
{
return F_49 ( & V_69 , V_77 ) ;
}
int F_50 ( struct V_1 * V_77 )
{
return F_51 ( & V_69 , V_77 ) ;
}
struct V_5 * F_52 ( struct V_33 * V_30 ,
const char * V_50 , struct V_33 * V_51 , void * V_52 ,
const struct V_53 * V_16 ,
const struct V_54 * V_21 )
{
struct V_5 * * V_78 , * V_75 ;
V_78 = F_53 ( F_46 , sizeof( * V_78 ) ,
V_56 ) ;
if ( ! V_78 )
return F_31 ( - V_57 ) ;
V_75 = F_29 ( V_50 , V_51 , V_52 , V_16 ,
V_21 ) ;
if ( ! F_54 ( V_75 ) ) {
* V_78 = V_75 ;
F_55 ( V_30 , V_78 ) ;
} else {
F_56 ( V_78 ) ;
}
return V_75 ;
}
void F_57 ( struct V_33 * V_30 ,
struct V_5 * V_6 )
{
int V_39 ;
V_39 = F_58 ( V_30 , F_46 ,
F_47 , V_6 ) ;
F_59 ( V_39 ) ;
}
static int F_60 ( struct V_33 * V_30 , const void * V_4 )
{
return V_30 -> V_51 && V_30 -> V_51 -> V_79 == V_4 ;
}
struct V_5 * F_61 ( struct V_80 * V_9 )
{
struct V_33 * V_30 ;
V_30 = F_62 ( V_60 , NULL , V_9 , F_60 ) ;
return V_30 ? F_14 ( V_30 ) : NULL ;
}
static void T_3 F_63 ( void )
{
F_64 ( V_60 ) ;
}
static int T_4 F_65 ( void )
{
V_60 = F_66 ( V_81 , L_12 ) ;
if ( F_54 ( V_60 ) ) {
F_67 ( L_13 ,
F_68 ( V_60 ) ) ;
return F_68 ( V_60 ) ;
}
V_60 -> V_82 = V_83 ;
V_60 -> V_84 = & V_85 ;
F_69 ( & V_68 ) ;
F_32 ( & V_66 ) ;
F_70 ( & V_69 ) ;
return 0 ;
}
