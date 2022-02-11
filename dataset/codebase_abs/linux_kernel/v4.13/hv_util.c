static void F_1 ( struct V_1 * V_2 )
{
F_2 ( true ) ;
}
static void F_3 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
bool V_8 = false ;
T_3 * V_9 = V_10 . V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_4 ( V_5 , V_9 ,
V_16 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_9 [
sizeof( struct V_17 ) ] ;
if ( V_15 -> V_18 == V_19 ) {
if ( F_5 ( V_15 , V_9 ,
V_20 , V_21 ,
V_22 , V_23 ,
NULL , & V_24 ) ) {
F_6 ( L_1 ,
V_24 >> 16 ,
V_24 & 0xFFFF ) ;
}
} else {
V_13 =
(struct V_12 * ) & V_9 [
sizeof( struct V_17 ) +
sizeof( struct V_14 ) ] ;
switch ( V_13 -> V_25 ) {
case 0 :
case 1 :
V_15 -> V_26 = V_27 ;
V_8 = true ;
F_6 ( L_2
L_3 ) ;
break;
default:
V_15 -> V_26 = V_28 ;
V_8 = false ;
F_6 ( L_2
L_4 ) ;
break;
}
}
V_15 -> V_29 = V_30
| V_31 ;
F_7 ( V_5 , V_9 ,
V_6 , V_7 ,
V_32 , 0 ) ;
}
if ( V_8 == true )
F_8 ( & V_33 ) ;
}
static struct V_34 F_9 ( void )
{
struct V_34 V_35 ;
T_2 V_36 , V_37 ;
unsigned long V_25 ;
F_10 ( & V_38 . V_39 , V_25 ) ;
V_37 = V_40 -> V_41 ( V_40 ) ;
V_36 = V_38 . V_42 + ( V_37 - V_38 . V_43 ) ;
V_35 = F_11 ( ( V_36 - V_44 ) * 100 ) ;
F_12 ( & V_38 . V_39 , V_25 ) ;
return V_35 ;
}
static void F_13 ( struct V_1 * V_45 )
{
struct V_34 V_35 = F_9 () ;
F_14 ( & V_35 ) ;
}
static inline void F_15 ( T_2 V_46 , T_2 V_37 , T_3 V_47 )
{
unsigned long V_25 ;
T_2 V_48 ;
F_10 ( & V_38 . V_39 , V_25 ) ;
V_48 = V_40 -> V_41 ( V_40 ) ;
V_38 . V_42 = V_46 ;
V_38 . V_43 = V_48 ;
V_38 . V_42 += ( V_48 - V_37 ) ;
F_12 ( & V_38 . V_39 , V_25 ) ;
if ( V_47 & V_49 )
F_8 ( & V_50 ) ;
}
static void F_16 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_3 * V_55 = V_56 . V_11 ;
F_4 ( V_5 , V_55 ,
V_16 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_55 [
sizeof( struct V_17 ) ] ;
if ( V_15 -> V_18 == V_19 ) {
if ( F_5 ( V_15 , V_55 ,
V_20 , V_21 ,
V_57 , V_58 ,
NULL , & V_59 ) ) {
F_6 ( L_5 ,
V_59 >> 16 ,
V_59 & 0xFFFF ) ;
}
} else {
if ( V_59 > V_60 ) {
V_54 = (struct V_53 * )
& V_55 [
sizeof( struct V_17 ) +
sizeof( struct V_14 ) ] ;
F_15 ( V_54 -> V_61 ,
V_54 -> V_62 ,
V_54 -> V_25 ) ;
} else {
V_52 = (struct V_51 * )
& V_55 [
sizeof( struct V_17 ) +
sizeof( struct V_14 ) ] ;
F_15 ( V_52 -> V_61 ,
V_40 -> V_41 ( V_40 ) ,
V_52 -> V_25 ) ;
}
}
V_15 -> V_29 = V_30
| V_31 ;
F_7 ( V_5 , V_55 ,
V_6 , V_7 ,
V_32 , 0 ) ;
}
}
static void F_17 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_63 * V_64 ;
T_3 * V_65 = V_66 . V_11 ;
while ( 1 ) {
F_4 ( V_5 , V_65 ,
V_16 , & V_6 , & V_7 ) ;
if ( ! V_6 )
break;
V_15 = (struct V_14 * ) & V_65 [
sizeof( struct V_17 ) ] ;
if ( V_15 -> V_18 == V_19 ) {
if ( F_5 ( V_15 ,
V_65 ,
V_20 , V_21 ,
V_67 , V_68 ,
NULL , & V_69 ) ) {
F_6 ( L_6 ,
V_69 >> 16 ,
V_69 & 0xFFFF ) ;
}
} else {
V_64 =
(struct V_63 * ) & V_65 [
sizeof( struct V_17 ) +
sizeof( struct V_14 ) ] ;
V_64 -> V_70 += 1 ;
}
V_15 -> V_29 = V_30
| V_31 ;
F_7 ( V_5 , V_65 ,
V_6 , V_7 ,
V_32 , 0 ) ;
}
}
static int F_18 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_75 * V_76 =
(struct V_75 * ) V_74 -> V_77 ;
int V_78 ;
V_76 -> V_11 = F_19 ( V_16 * 4 , V_79 ) ;
if ( ! V_76 -> V_11 )
return - V_80 ;
V_76 -> V_5 = V_72 -> V_5 ;
if ( V_76 -> V_81 ) {
V_78 = V_76 -> V_81 ( V_76 ) ;
if ( V_78 ) {
V_78 = - V_82 ;
goto V_83;
}
}
F_20 ( V_72 -> V_5 , V_84 ) ;
F_21 ( V_72 , V_76 ) ;
V_78 = F_22 ( V_72 -> V_5 , 4 * V_16 , 4 * V_16 , NULL , 0 ,
V_76 -> V_85 , V_72 -> V_5 ) ;
if ( V_78 )
goto error;
return 0 ;
error:
if ( V_76 -> V_86 )
V_76 -> V_86 () ;
V_83:
F_23 ( V_76 -> V_11 ) ;
return V_78 ;
}
static int F_24 ( struct V_71 * V_72 )
{
struct V_75 * V_76 = F_25 ( V_72 ) ;
if ( V_76 -> V_86 )
V_76 -> V_86 () ;
F_26 ( V_72 -> V_5 ) ;
F_23 ( V_76 -> V_11 ) ;
return 0 ;
}
static int F_27 ( struct V_87 * V_88 ,
struct V_89 * V_90 , int V_91 )
{
return - V_92 ;
}
static int F_28 ( struct V_87 * V_93 , const struct V_34 * V_35 )
{
return - V_92 ;
}
static int F_29 ( struct V_87 * V_94 , T_4 V_95 )
{
return - V_92 ;
}
static int F_30 ( struct V_87 * V_94 , T_5 V_95 )
{
return - V_92 ;
}
static int F_31 ( struct V_87 * V_88 , struct V_34 * V_35 )
{
* V_35 = F_9 () ;
return 0 ;
}
static int F_32 ( struct V_75 * V_76 )
{
if ( ! V_40 )
return - V_82 ;
F_33 ( & V_38 . V_39 ) ;
F_34 ( & V_50 , F_13 ) ;
V_96 = F_35 ( & V_97 , NULL ) ;
if ( F_36 ( V_96 ) ) {
F_37 ( L_7 ,
F_38 ( V_96 ) ) ;
V_96 = NULL ;
}
return 0 ;
}
static void F_39 ( void )
{
if ( V_96 )
F_40 ( V_96 ) ;
F_41 ( & V_50 ) ;
}
static int T_6 F_42 ( void )
{
F_6 ( L_8 ) ;
return F_43 ( & V_98 ) ;
}
static void F_44 ( void )
{
F_6 ( L_9 ) ;
F_45 ( & V_98 ) ;
}
