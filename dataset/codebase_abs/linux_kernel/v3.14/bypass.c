static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int * V_6 )
{
int V_7 = - 1 ;
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_4 ;
V_9 -> V_5 = V_5 ;
V_9 -> V_6 = * V_6 ;
if ( V_2 -> V_10 && V_2 -> V_10 -> V_11 ) {
V_7 = V_2 -> V_10 -> V_11 ( V_2 , V_4 , V_12 ) ;
* V_6 = V_9 -> V_6 ;
}
return V_7 ;
}
static int F_2 ( int V_5 , int V_13 , int * V_6 )
{
struct V_3 V_4 ;
int V_7 = - 1 ;
struct V_1 * V_2 ;
struct V_1 * V_14 ;
F_3 (&init_net, dev, n) {
if ( V_2 -> V_15 == V_13 ) {
V_7 = F_1 ( V_2 , & V_4 , V_5 , V_6 ) ;
if ( V_7 < 0 )
V_7 = - 1 ;
}
}
return V_7 ;
}
static int F_4 ( int V_13 )
{
int V_7 = 0 ;
F_5 ( V_16 , int , V_13 , V_7 ) ;
return V_7 >= 0 ? 1 : 0 ;
}
static int F_6 ( int V_13 )
{
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 V_4 ;
int V_7 = 0 ;
int V_6 = 0 ;
while ( ( V_18 = F_7 ( V_19 << 8 , V_18 ) ) ) {
V_2 = F_8 ( V_18 ) ;
if ( V_2 != NULL ) {
V_2 = F_8 ( V_18 ) ;
if ( ( V_2 != NULL ) && ( V_2 -> V_15 == V_13 ) ) {
if ( ( V_18 -> V_20 == V_21 ) &&
( V_18 -> V_22 >= V_23 ) &&
( V_18 -> V_22 <= V_24 ) ) {
goto V_25;
}
#if F_9 ( V_26 ) && F_9 ( V_27 )
else {
struct V_28 V_29 ;
const struct V_30 * V_31 =
V_2 -> V_30 ;
int V_32 = 0 ;
if ( V_31 -> V_33 ) {
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_5 = V_27 ;
V_31 -> V_33 ( V_2 , & V_29 ) ;
for (; V_34 [ V_32 ] ; V_32 ++ )
if ( !
( strcmp
( V_34 [ V_32 ] ,
V_29 . V_35 ) ) )
goto V_25;
}
}
#endif
return - 1 ;
}
}
}
V_25:
V_7 = F_1 ( V_2 , & V_4 , V_36 , & V_6 ) ;
return V_7 < 0 ? - 1 : V_7 ;
}
static int V_16 ( int V_13 )
{
int V_7 = 0 ;
F_5 ( V_16 , int , V_13 , V_7 ) ;
if ( V_7 < 0 )
return F_6 ( V_13 ) ;
return V_7 ;
}
static int F_10 ( int V_13 )
{
F_11 ( F_10 , V_37 , V_13 ) ;
}
static int F_12 ( int V_13 )
{
F_11 ( F_12 , V_38 , V_13 ) ;
}
static int F_13 ( int V_13 )
{
F_11 ( F_13 , V_39 , V_13 ) ;
}
static int F_14 ( int V_13 , int V_40 )
{
F_15 ( F_14 , V_41 , V_13 , V_40 ) ;
}
static int F_16 ( int V_13 )
{
F_11 ( F_16 , V_42 , V_13 ) ;
}
static int F_17 ( int V_13 )
{
F_11 ( F_17 , V_43 , V_13 ) ;
}
static int F_18 ( int V_13 , int V_44 )
{
F_15 ( F_18 , V_45 , V_13 ,
V_44 ) ;
}
static int F_19 ( int V_13 )
{
F_11 ( F_19 , V_46 , V_13 ) ;
}
static int F_20 ( int V_13 , int V_40 )
{
F_15 ( F_20 , V_47 , V_13 ,
V_40 ) ;
}
static int F_21 ( int V_13 )
{
F_11 ( F_21 , V_48 , V_13 ) ;
}
static int F_22 ( int V_13 , int V_40 )
{
F_15 ( F_22 , V_49 , V_13 ,
V_40 ) ;
}
static int F_23 ( int V_13 )
{
F_11 ( F_23 , V_50 , V_13 ) ;
}
static int F_24 ( int V_13 , int V_51 , int * V_52 )
{
int V_6 = V_51 ;
int V_7 = 0 ;
if ( F_4 ( V_13 ) ) {
F_25 ( F_24 , int , V_13 , int , V_51 ,
int * , V_52 , V_7 ) ;
} else {
V_7 = F_2 ( V_53 , V_13 , & V_6 ) ;
if ( V_7 > 0 ) {
* V_52 = V_7 ;
V_7 = 0 ;
}
}
return V_7 ;
}
static int F_26 ( int V_13 , int * V_52 )
{
int * V_6 = V_52 ;
int V_7 = 0 ;
if ( F_4 ( V_13 ) )
F_27 ( F_26 , int , V_13 , int * ,
V_52 , V_7 ) ;
else
V_7 = F_2 ( V_54 , V_13 , V_6 ) ;
return V_7 ;
}
static int F_28 ( int V_13 , int * V_55 )
{
int * V_6 = V_55 , V_7 = 0 ;
if ( F_4 ( V_13 ) ) {
F_27 ( F_28 , int , V_13 , int * ,
V_55 , V_7 ) ;
} else {
V_7 = F_2 ( V_56 , V_13 , V_6 ) ;
if ( ( V_7 == 0 ) && ( * V_6 != 0 ) )
V_7 = 1 ;
}
return V_7 ;
}
static int F_29 ( int V_13 )
{
F_11 ( F_29 , V_57 ,
V_13 ) ;
}
static int F_30 ( int V_13 , int V_40 )
{
F_15 ( F_30 , V_58 , V_13 , V_40 ) ;
}
static int F_31 ( int V_13 )
{
F_11 ( F_31 , V_59 , V_13 ) ;
}
static int F_32 ( int V_13 , int V_60 )
{
F_15 ( F_32 , V_61 , V_13 , V_60 ) ;
}
static int F_33 ( int V_13 )
{
F_11 ( F_33 , V_62 , V_13 ) ;
}
static int F_34 ( int V_13 , int V_63 )
{
F_15 ( F_34 , V_64 , V_13 , V_63 ) ;
}
static int F_35 ( int V_13 )
{
F_11 ( F_35 , V_65 , V_13 ) ;
}
static int F_36 ( int V_13 )
{
F_11 ( F_36 , V_66 , V_13 ) ;
}
static int F_37 ( int V_13 , int V_67 )
{
F_15 ( F_37 , V_68 , V_13 , V_67 ) ;
}
static int F_38 ( int V_13 )
{
F_11 ( F_38 , V_69 , V_13 ) ;
}
static int F_39 ( int V_13 , int V_63 )
{
F_15 ( F_39 , V_70 , V_13 , V_63 ) ;
}
static int F_40 ( int V_13 )
{
F_11 ( F_40 , V_71 , V_13 ) ;
}
static int F_41 ( int V_13 , int V_72 )
{
F_15 ( F_41 , V_73 , V_13 , V_72 ) ;
}
static int F_42 ( int V_13 )
{
F_11 ( F_42 , V_74 , V_13 ) ;
}
static int F_43 ( int V_13 )
{
F_11 ( F_43 , V_75 , V_13 ) ;
}
static int F_44 ( int V_13 , int V_76 )
{
F_15 ( F_44 , V_77 , V_13 , V_76 ) ;
}
static int F_45 ( int V_13 )
{
F_11 ( F_45 , V_78 , V_13 ) ;
}
static int F_46 ( int V_13 , int V_72 )
{
F_15 ( F_46 , V_79 , V_13 ,
V_72 ) ;
}
static int F_47 ( int V_13 )
{
F_11 ( F_47 , V_80 , V_13 ) ;
}
static int F_48 ( int V_13 , int V_81 )
{
F_15 ( F_48 , V_82 , V_13 , V_81 ) ;
}
static int F_49 ( int V_13 )
{
F_11 ( F_49 , V_83 , V_13 ) ;
}
static int F_50 ( int V_13 , int time )
{
F_15 ( F_50 , V_84 , V_13 , time ) ;
}
static int F_51 ( int V_13 )
{
F_11 ( F_51 , V_85 , V_13 ) ;
}
static int F_52 ( int V_13 , int V_86 )
{
F_15 ( F_52 , V_87 , V_13 , V_86 ) ;
}
static int F_53 ( int V_13 )
{
F_11 ( F_53 , V_88 , V_13 ) ;
}
static int F_54 ( int V_13 , int V_81 )
{
F_15 ( F_52 , V_89 , V_13 , V_81 ) ;
}
static int F_55 ( int V_13 )
{
F_11 ( F_53 , V_90 , V_13 ) ;
}
static int F_56 ( int V_13 , struct V_91 * V_91 )
{
int V_7 = 0 ;
if ( F_4 ( V_13 ) ) {
F_27 ( F_56 , int , V_13 ,
struct V_91 * , V_91 , V_7 ) ;
} else {
struct V_1 * V_2 ;
struct V_1 * V_14 ;
F_3 (&init_net, dev, n) {
if ( V_2 -> V_15 == V_13 ) {
struct V_92 * V_9 ;
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_9 = (struct V_92 * ) & V_4 ;
V_9 -> V_5 = V_93 ;
if ( V_2 -> V_10 &&
V_2 -> V_10 -> V_11 )
V_7 = V_2 -> V_10 -> V_11 ( V_2 ,
& V_4 , V_12 ) ;
else
V_7 = - 1 ;
if ( V_7 == 0 )
memcpy ( V_91 , & V_9 -> V_91 ,
sizeof( struct V_91 ) ) ;
V_7 = V_7 < 0 ? - 1 : 0 ;
break;
}
}
}
return V_7 ;
}
static int T_1 F_57 ( void )
{
F_58 ( V_94 ) ;
return 0 ;
}
static void T_2 F_59 ( void )
{
}
