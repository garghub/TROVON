static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = F_3 ( V_4 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
if ( ! V_8 )
return 0 ;
while ( V_8 -> V_10 ) {
if ( V_8 -> V_10 == V_5 -> V_11 . V_10 )
return 1 ;
V_8 ++ ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return - V_14 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( F_2 ( V_2 ) ) ;
}
static const struct V_7 * F_7 ( const struct V_7
* V_8 ,
struct V_5 * V_15 )
{
while ( V_8 -> V_10 && V_8 -> V_16 ) {
if ( V_8 -> V_10 == V_15 -> V_11 . V_10 &&
V_8 -> V_16 == V_15 -> V_11 . V_16 )
return V_8 ;
V_8 ++ ;
}
return NULL ;
}
static int F_8 ( struct V_1 * V_2 )
{
const struct V_7 * V_17 ;
struct V_6 * V_6 = F_3 ( V_2 -> V_18 ) ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
int error = 0 ;
if ( ! V_5 -> V_18 && V_6 -> V_19 ) {
V_17 = F_7 ( V_6 -> V_9 , V_5 ) ;
if ( V_17 ) {
if ( ( error = V_6 -> V_19 ( V_5 , V_17 ) ) < 0 )
return error ;
else
V_5 -> V_18 = V_6 ;
}
}
return error ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_18 ;
if ( V_6 -> remove )
V_6 -> remove ( V_5 ) ;
V_5 -> V_18 = NULL ;
return 0 ;
}
int F_10 ( struct V_6 * V_20 )
{
V_20 -> V_18 . V_21 = V_20 -> V_21 ;
V_20 -> V_18 . V_22 = & V_23 ;
return F_11 ( & V_20 -> V_18 ) ;
}
int F_12 ( struct V_6 * V_20 )
{
F_13 ( & V_20 -> V_18 ) ;
return 0 ;
}
int
F_14 ( T_1 V_24 , int V_10 , int V_16 ,
struct V_25 * V_26 , int V_27 )
{
struct V_5 * V_5 ;
V_5 = F_15 ( sizeof( struct V_5 ) , V_28 ) ;
F_16 ( L_1 , V_5 ) ;
if ( V_5 == NULL )
return - V_29 ;
V_5 -> V_11 . V_10 = V_10 ;
V_5 -> V_11 . V_16 = V_16 ;
V_5 -> V_11 . V_24 = V_24 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_2 . V_30 = NULL ;
V_5 -> V_2 . V_22 = & V_23 ;
V_5 -> V_2 . V_31 = F_5 ;
F_17 ( & V_5 -> V_2 , L_2 , V_5 -> V_11 . V_24 ) ;
F_18 ( & V_5 -> V_2 ) ;
F_19 ( & V_5 -> V_2 ) ;
F_20 ( & V_5 -> V_2 , & V_32 ) ;
return 0 ;
}
int F_21 ( struct V_5 * V_5 )
{
F_22 ( & V_5 -> V_2 ) ;
F_23 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_5 )
{
F_21 ( V_5 ) ;
return F_14 ( V_5 -> V_11 . V_24 , V_5 -> V_11 . V_10 ,
V_5 -> V_11 . V_16 , V_5 -> V_26 ,
V_5 -> V_27 ) ;
}
static inline T_2 F_25 ( T_1 V_24 , int V_33 ,
T_2 V_34 ,
int V_35 , T_1 V_36 ,
int V_37 )
{
struct V_38 V_39 ;
V_39 . V_40 = 0 ;
V_39 . V_41 = 0 ;
F_26 ( & V_39 , V_42 ,
V_43 , V_24 ,
V_33 , V_34 , V_35 ,
V_36 , V_37 ) ;
return V_39 . V_40 ;
}
static inline void F_27 ( T_1 V_24 , int V_33 ,
struct V_34 * V_34 )
{
struct V_38 V_39 ;
V_39 . V_40 = 0 ;
V_39 . V_41 = 0 ;
F_26 ( & V_39 , V_42 ,
V_44 , V_24 ,
V_33 , V_34 -> V_45 ,
V_34 -> V_46 , 0 , 0 ) ;
}
struct V_34 * F_28 ( T_1 V_24 , int V_33 , int V_47 ,
T_1 V_36 , int V_48 )
{
struct V_34 * V_34 ;
int V_40 ;
int V_49 = sizeof( struct V_34 ) ;
if ( ( V_24 & 1 ) == 0 )
return NULL ;
V_34 = F_15 ( V_49 , V_28 ) ;
if ( V_34 == NULL )
return NULL ;
V_40 = F_25 ( V_24 , V_33 , F_29 ( V_34 ) , V_47 ,
V_36 , V_48 ) ;
if ( V_40 ) {
F_6 ( V_34 ) ;
return NULL ;
} else {
return V_34 ;
}
}
void F_30 ( struct V_34 * V_34 )
{
T_2 V_50 = ( T_2 ) V_34 -> V_51 ;
T_1 V_24 = F_31 ( V_50 ) ;
int V_33 ;
if ( V_24 & 1 ) {
V_33 = F_32 ( V_50 ) ;
F_27 ( V_24 , V_33 , V_34 ) ;
F_6 ( V_34 ) ;
}
}
T_2 F_33 ( T_2 V_52 )
{
return F_34 ( V_52 ) ;
}
T_2 F_35 ( int V_24 )
{
return F_36 ( V_24 , V_53 ) ;
}
static void F_37 ( T_1 V_24 , int V_54 )
{
T_2 V_55 ;
T_2 V_56 = ( 1ull << 61 ) ;
if ( ! ( V_24 & 1 ) )
return;
V_55 = F_38 ( V_24 , V_57 ) ;
if ( V_54 ) {
if ( ! ( V_55 & V_56 ) )
return;
V_55 &= ~ V_56 ;
} else {
if ( V_55 & V_56 )
return;
V_55 |= V_56 ;
}
F_16 ( V_58 L_3 , V_55 ) ;
F_39 ( V_24 , V_57 , V_55 ) ;
}
static void F_40 ( T_1 V_24 , int V_59 )
{
if ( ! ( V_24 & 1 ) )
return;
F_39 ( V_24 , V_60 , 1 << V_59 ) ;
F_41 ( 2000 ) ;
F_39 ( V_24 , V_60 , 0 ) ;
F_41 ( 2000 ) ;
}
static int F_42 ( int V_24 , int * V_27 )
{
T_3 V_61 ( V_62 ) ;
long V_63 ;
V_63 = F_43 ( V_24 , & V_62 ) ;
if ( V_63 ) {
F_44 ( V_64 L_4 ,
V_63 ) ;
return 0 ;
}
switch ( V_62 ) {
case V_65 :
case V_66 :
case V_67 :
* V_27 = V_62 ;
return 1 ;
}
return 0 ;
}
static int F_45 ( T_1 V_24 )
{
T_2 V_68 ;
V_68 = F_38 ( V_24 , V_69 ) ;
V_68 &= V_70 ;
F_16 ( L_5 , V_68 ) ;
return ( V_68 == 0xf ) ? 1 : 0 ;
}
static int F_46 ( struct V_5 * V_5 )
{
int V_10 = V_71 ;
int V_16 = V_71 ;
T_1 V_24 = V_5 -> V_11 . V_24 ;
if ( F_45 ( V_24 ) ) {
T_2 V_11 ;
int V_39 ;
V_39 = F_47 ( V_24 ) ;
if ( V_39 ) {
F_44 ( V_58 L_6 ) ;
} else {
V_11 = * ( volatile T_2 * )
( F_36 ( V_24 , V_53 ) +
V_72 ) ;
V_10 = F_48 ( V_11 ) ;
V_16 = F_49 ( V_11 ) ;
F_16 ( L_7 , V_10 , V_16 ) ;
if ( V_10 == V_73 )
return 0 ;
}
}
V_5 -> V_11 . V_10 = V_10 ;
V_5 -> V_11 . V_16 = V_16 ;
return F_24 ( V_5 ) ;
}
static T_4 F_50 ( struct V_1 * V_2 , struct V_74 * V_75 , char * V_76 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return sprintf ( V_76 , L_8 ,
V_5 -> V_11 . V_24 ,
V_5 -> V_11 . V_10 , V_5 -> V_11 . V_16 ,
V_5 -> V_27 ) ;
}
static T_4 F_51 ( struct V_1 * V_2 , struct V_74 * V_75 , const char * V_76 ,
T_5 V_77 )
{
int V_78 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( ! F_52 ( V_79 ) )
return - V_80 ;
if ( V_77 <= 0 )
return 0 ;
V_78 = F_53 ( V_76 , NULL , 0 ) ;
switch ( V_78 ) {
case 1 :
F_40 ( V_5 -> V_11 . V_24 , V_53 ) ;
F_46 ( V_5 ) ;
break;
case 2 :
F_46 ( V_5 ) ;
break;
case 3 :
F_40 ( V_5 -> V_11 . V_24 , V_53 ) ;
break;
default:
break;
}
return V_77 ;
}
static int T_6 F_54 ( void )
{
T_7 V_81 ;
int V_82 = 0 ;
if ( ! F_55 ( L_9 ) )
return 0 ;
F_56 ( & V_23 ) ;
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ ) {
T_1 V_24 ;
int V_27 ;
V_24 = F_57 ( V_81 ) ;
if ( ( V_24 & 0x1 ) && F_42 ( V_24 , & V_27 ) ) {
struct V_25 * V_26 ;
struct V_84 * V_85 ;
F_16 ( L_10 , V_24 ) ;
V_26 =
(struct V_25 * ) ( F_58 ( V_81 ) -> V_86 ) ;
V_85 = & V_26 -> V_87 [ V_53 ] ;
if ( V_85 -> V_88 . V_10 == V_73 )
continue;
F_40 ( V_24 , V_53 ) ;
F_59 ( V_24 ) ;
if ( F_14
( V_24 , V_85 -> V_88 . V_10 ,
V_85 -> V_88 . V_16 , V_26 , V_27 ) < 0 )
return - V_89 ;
else
V_82 ++ ;
}
}
F_16 ( L_11 , V_82 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , void * V_90 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_61 ( V_2 , & V_32 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
static void T_8 F_62 ( void )
{
F_16 ( L_12 ) ;
F_63 ( & V_23 , NULL , NULL , F_60 ) ;
F_64 ( & V_23 ) ;
}
