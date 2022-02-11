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
static void F_9 ( struct V_1 * V_34 )
{
struct V_35 * V_36 ;
struct V_37 V_38 ;
T_2 V_39 , V_40 ;
V_36 = F_10 ( V_34 , struct V_35 , V_34 ) ;
V_39 = V_41 -> V_42 ( V_41 ) ;
V_40 = V_36 -> V_43 + ( V_39 - V_36 -> V_44 ) ;
V_38 = F_11 ( ( V_40 - V_45 ) * 100 ) ;
F_12 ( & V_38 ) ;
}
static inline void F_13 ( T_2 V_46 , T_2 V_39 , T_3 V_47 )
{
unsigned long V_25 ;
T_2 V_48 ;
if ( V_47 & V_49 ) {
if ( F_14 ( & V_36 . V_34 ) )
return;
V_36 . V_43 = V_46 ;
V_36 . V_44 = V_39 ;
V_36 . V_25 = V_47 ;
F_8 ( & V_36 . V_34 ) ;
} else {
F_15 ( & V_38 . V_50 , V_25 ) ;
V_48 = V_41 -> V_42 ( V_41 ) ;
V_38 . V_43 = V_46 ;
V_38 . V_44 = V_48 ;
F_16 ( & V_38 . V_51 ) ;
if ( V_52 > V_53 )
V_38 . V_43 += ( V_48 - V_39 ) ;
F_17 ( & V_38 . V_50 , V_25 ) ;
}
}
static void F_18 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_3 * V_58 = V_59 . V_11 ;
F_4 ( V_5 , V_58 ,
V_16 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_58 [
sizeof( struct V_17 ) ] ;
if ( V_15 -> V_18 == V_19 ) {
if ( F_5 ( V_15 , V_58 ,
V_20 , V_21 ,
V_60 , V_61 ,
NULL , & V_52 ) ) {
F_6 ( L_5 ,
V_52 >> 16 ,
V_52 & 0xFFFF ) ;
}
} else {
if ( V_52 > V_53 ) {
V_57 = (struct V_56 * )
& V_58 [
sizeof( struct V_17 ) +
sizeof( struct V_14 ) ] ;
F_13 ( V_57 -> V_62 ,
V_57 -> V_63 ,
V_57 -> V_25 ) ;
} else {
V_55 = (struct V_54 * )
& V_58 [
sizeof( struct V_17 ) +
sizeof( struct V_14 ) ] ;
F_13 ( V_55 -> V_62 ,
0 ,
V_55 -> V_25 ) ;
}
}
V_15 -> V_29 = V_30
| V_31 ;
F_7 ( V_5 , V_58 ,
V_6 , V_7 ,
V_32 , 0 ) ;
}
}
static void F_19 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_64 * V_65 ;
T_3 * V_66 = V_67 . V_11 ;
while ( 1 ) {
F_4 ( V_5 , V_66 ,
V_16 , & V_6 , & V_7 ) ;
if ( ! V_6 )
break;
V_15 = (struct V_14 * ) & V_66 [
sizeof( struct V_17 ) ] ;
if ( V_15 -> V_18 == V_19 ) {
if ( F_5 ( V_15 ,
V_66 ,
V_20 , V_21 ,
V_68 , V_69 ,
NULL , & V_70 ) ) {
F_6 ( L_6 ,
V_70 >> 16 ,
V_70 & 0xFFFF ) ;
}
} else {
V_65 =
(struct V_64 * ) & V_66 [
sizeof( struct V_17 ) +
sizeof( struct V_14 ) ] ;
V_65 -> V_71 += 1 ;
}
V_15 -> V_29 = V_30
| V_31 ;
F_7 ( V_5 , V_66 ,
V_6 , V_7 ,
V_32 , 0 ) ;
}
}
static int F_20 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_76 * V_77 =
(struct V_76 * ) V_75 -> V_78 ;
int V_79 ;
V_77 -> V_11 = F_21 ( V_16 * 4 , V_80 ) ;
if ( ! V_77 -> V_11 )
return - V_81 ;
V_77 -> V_5 = V_73 -> V_5 ;
if ( V_77 -> V_82 ) {
V_79 = V_77 -> V_82 ( V_77 ) ;
if ( V_79 ) {
V_79 = - V_83 ;
goto V_84;
}
}
F_22 ( V_73 -> V_5 , V_85 ) ;
F_23 ( V_73 , V_77 ) ;
V_79 = F_24 ( V_73 -> V_5 , 4 * V_16 , 4 * V_16 , NULL , 0 ,
V_77 -> V_86 , V_73 -> V_5 ) ;
if ( V_79 )
goto error;
return 0 ;
error:
if ( V_77 -> V_87 )
V_77 -> V_87 () ;
V_84:
F_25 ( V_77 -> V_11 ) ;
return V_79 ;
}
static int F_26 ( struct V_72 * V_73 )
{
struct V_76 * V_77 = F_27 ( V_73 ) ;
if ( V_77 -> V_87 )
V_77 -> V_87 () ;
F_28 ( V_73 -> V_5 ) ;
F_25 ( V_77 -> V_11 ) ;
return 0 ;
}
static int F_29 ( struct V_88 * V_89 ,
struct V_90 * V_91 , int V_92 )
{
return - V_93 ;
}
static int F_30 ( struct V_88 * V_94 , const struct V_37 * V_95 )
{
return - V_93 ;
}
static int F_31 ( struct V_88 * V_96 , T_4 V_97 )
{
return - V_93 ;
}
static int F_32 ( struct V_88 * V_96 , T_5 V_97 )
{
return - V_93 ;
}
static int F_33 ( struct V_88 * V_89 , struct V_37 * V_95 )
{
unsigned long V_25 ;
T_2 V_40 , V_39 ;
F_15 ( & V_38 . V_50 , V_25 ) ;
V_39 = V_41 -> V_42 ( V_41 ) ;
V_40 = V_38 . V_43 + ( V_39 - V_38 . V_44 ) ;
* V_95 = F_11 ( ( V_40 - V_45 ) * 100 ) ;
F_17 ( & V_38 . V_50 , V_25 ) ;
return 0 ;
}
static int F_34 ( T_6 * V_98 ,
struct V_99 * system ,
void * V_100 )
{
system -> V_101 = V_41 ;
system -> V_102 = V_38 . V_44 ;
* V_98 = F_35 ( ( V_38 . V_43 - V_45 ) * 100 ) ;
return 0 ;
}
static int F_36 ( struct V_88 * V_96 ,
struct V_103 * V_104 )
{
unsigned long V_25 ;
int V_79 ;
F_15 ( & V_38 . V_50 , V_25 ) ;
V_79 = F_37 ( F_34 ,
NULL , & V_38 . V_51 , V_104 ) ;
F_17 ( & V_38 . V_50 , V_25 ) ;
return V_79 ;
}
static int F_38 ( struct V_76 * V_77 )
{
if ( ! V_41 )
return - V_83 ;
F_39 ( & V_38 . V_50 ) ;
F_40 ( & V_36 . V_34 , F_9 ) ;
V_105 = F_41 ( & V_106 , NULL ) ;
if ( F_42 ( V_105 ) ) {
F_43 ( L_7 ,
F_44 ( V_105 ) ) ;
V_105 = NULL ;
}
return 0 ;
}
static void F_45 ( void )
{
if ( V_105 )
F_46 ( V_105 ) ;
F_47 ( & V_36 . V_34 ) ;
}
static int T_7 F_48 ( void )
{
F_6 ( L_8 ) ;
return F_49 ( & V_107 ) ;
}
static void F_50 ( void )
{
F_6 ( L_9 ) ;
F_51 ( & V_107 ) ;
}
