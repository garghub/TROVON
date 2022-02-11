static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 , T_2 V_13 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_1 , V_10 -> V_14 , V_13 ) ;
F_10 ( V_10 -> V_15 , V_13 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_16 * V_17 ;
T_1 V_13 = 0 ;
if ( ! V_10 -> V_15 )
return;
F_12 (plane, crtc) {
V_13 |= F_13 ( V_17 ) ;
}
V_13 |= F_14 ( V_10 -> V_15 ) ;
V_13 |= F_15 ( V_10 -> V_18 ) ;
F_8 ( V_3 , V_13 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_22 * V_23 ;
struct V_16 * V_17 ;
unsigned long V_24 ;
F_17 ( & V_6 -> V_25 , V_24 ) ;
V_23 = V_10 -> V_23 ;
if ( V_23 ) {
if ( ! V_20 || ( V_23 -> V_11 . V_26 == V_20 ) ) {
V_10 -> V_23 = NULL ;
F_9 ( L_2 , V_10 -> V_14 , V_23 ) ;
F_18 ( V_6 , V_10 -> V_27 , V_23 ) ;
}
}
F_19 ( & V_6 -> V_25 , V_24 ) ;
F_12 (plane, crtc) {
F_20 ( V_17 ) ;
}
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_22 ( V_3 ) ;
F_23 ( V_10 ) ;
}
static void F_24 ( struct V_2 * V_3 , int V_28 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_29 = ( V_28 == V_30 ) ;
F_9 ( L_3 , V_10 -> V_14 , V_28 ) ;
if ( V_29 != V_10 -> V_29 ) {
if ( V_29 ) {
F_25 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_31 ) ;
} else {
F_26 ( V_10 -> V_15 , V_10 -> V_18 , 0x00000000 ) ;
F_27 ( & V_1 -> V_11 , & V_10 -> V_31 ) ;
F_28 ( V_1 ) ;
}
V_10 -> V_29 = V_29 ;
}
}
static bool F_29 ( struct V_2 * V_3 ,
const struct V_32 * V_28 ,
struct V_32 * V_33 )
{
return true ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
const struct V_34 * V_35 ;
T_1 V_18 = V_10 -> V_18 , V_36 = 0 ;
unsigned long V_24 ;
#define F_31 ( T_3 ) ((stage) - STAGE_BASE)
V_35 = F_32 ( V_1 -> V_37 ) ;
F_17 ( & V_10 -> V_38 , V_24 ) ;
if ( ! V_10 -> V_15 )
goto V_39;
F_12 (plane, crtc) {
enum V_40 T_3 =
F_33 ( V_17 -> V_41 ) -> T_3 ;
F_34 ( T_3 > V_35 -> V_18 . V_42 ) ;
F_35 ( V_1 ,
F_36 ( V_18 , F_31 ( T_3 ) ) ,
F_37 ( V_43 ) |
F_38 ( V_44 ) ) ;
F_35 ( V_1 , F_39 ( V_18 ,
F_31 ( T_3 ) ) , 0xff ) ;
F_35 ( V_1 , F_40 ( V_18 ,
F_31 ( T_3 ) ) , 0x00 ) ;
V_36 |= F_41 ( F_42 ( V_17 ) , T_3 ) ;
F_9 ( L_4 , V_10 -> V_14 ,
F_43 ( F_42 ( V_17 ) ) , T_3 ) ;
}
F_9 ( L_5 , V_10 -> V_14 , V_18 , V_36 ) ;
F_26 ( V_10 -> V_15 , V_18 , V_36 ) ;
V_39:
F_19 ( & V_10 -> V_38 , V_24 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_24 ;
struct V_32 * V_28 ;
if ( F_45 ( ! V_3 -> V_41 ) )
return;
V_28 = & V_3 -> V_41 -> V_33 ;
F_9 ( L_6 ,
V_10 -> V_14 , V_28 -> V_11 . V_27 , V_28 -> V_14 ,
V_28 -> V_45 , V_28 -> clock ,
V_28 -> V_46 , V_28 -> V_47 ,
V_28 -> V_48 , V_28 -> V_49 ,
V_28 -> V_50 , V_28 -> V_51 ,
V_28 -> V_52 , V_28 -> V_53 ,
V_28 -> type , V_28 -> V_24 ) ;
F_17 ( & V_10 -> V_38 , V_24 ) ;
F_35 ( V_1 , F_46 ( V_10 -> V_18 ) ,
F_47 ( V_28 -> V_46 ) |
F_48 ( V_28 -> V_50 ) ) ;
F_19 ( & V_10 -> V_38 , V_24 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_7 , V_10 -> V_14 ) ;
F_25 ( F_1 ( V_3 ) ) ;
F_24 ( V_3 , V_54 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_7 , V_10 -> V_14 ) ;
F_24 ( V_3 , V_30 ) ;
F_11 ( V_3 ) ;
F_28 ( F_1 ( V_3 ) ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
}
static int F_52 ( const void * V_55 , const void * V_56 )
{
struct V_57 * V_58 = (struct V_57 * ) V_55 ;
struct V_57 * V_59 = (struct V_57 * ) V_56 ;
return V_58 -> V_41 -> V_60 - V_59 -> V_41 -> V_60 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_61 * V_41 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_57 V_62 [ V_63 + 1 ] ;
int V_64 = 0 , V_65 ;
F_9 ( L_8 , V_10 -> V_14 ) ;
if ( V_41 -> V_66 && ! V_10 -> V_15 ) {
V_10 -> V_15 = F_54 ( V_1 -> V_67 , V_3 ) ;
if ( F_45 ( ! V_10 -> V_15 ) )
return - V_68 ;
}
F_55 (plane, state) {
struct V_69 * V_70 ;
if ( V_64 >= F_56 ( V_62 ) ) {
F_57 ( V_6 -> V_6 , L_9 ) ;
return - V_68 ;
}
V_70 = V_41 -> V_41 -> V_71 [ F_58 ( V_17 ) ] ;
if ( ! V_70 )
V_70 = V_17 -> V_41 ;
V_62 [ V_64 ] . V_17 = V_17 ;
V_62 [ V_64 ] . V_41 = F_33 ( V_70 ) ;
V_64 ++ ;
}
F_59 ( V_62 , V_64 , sizeof( V_62 [ 0 ] ) , F_52 , NULL ) ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
V_62 [ V_65 ] . V_41 -> T_3 = V_72 + V_65 ;
F_9 ( L_10 , V_10 -> V_14 ,
F_43 ( F_42 ( V_62 [ V_65 ] . V_17 ) ) ,
V_62 [ V_65 ] . V_41 -> T_3 ) ;
}
return 0 ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_11 , V_10 -> V_14 ) ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
unsigned long V_24 ;
F_9 ( L_12 , V_10 -> V_14 , V_3 -> V_41 -> V_23 ) ;
F_45 ( V_10 -> V_23 ) ;
F_17 ( & V_6 -> V_25 , V_24 ) ;
V_10 -> V_23 = V_3 -> V_41 -> V_23 ;
F_19 ( & V_6 -> V_25 , V_24 ) ;
F_30 ( V_3 ) ;
F_11 ( V_3 ) ;
F_4 ( V_3 , V_73 ) ;
if ( V_10 -> V_15 && ! V_3 -> V_41 -> V_66 ) {
F_62 ( V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
}
}
static int F_63 ( struct V_2 * V_3 ,
struct V_74 * V_75 , T_4 V_76 )
{
return - V_68 ;
}
static void F_64 ( struct V_77 * V_78 , T_1 V_79 )
{
struct V_10 * V_10 = F_65 ( V_78 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
unsigned V_9 ;
F_27 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_66 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_73 ) {
F_16 ( V_3 , NULL ) ;
}
}
static void F_67 ( struct V_77 * V_78 , T_1 V_79 )
{
struct V_10 * V_10 = F_65 ( V_78 , struct V_10 , V_31 ) ;
F_9 ( L_13 , V_10 -> V_14 , V_79 ) ;
}
T_1 F_68 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_80 ;
}
void F_69 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
F_9 ( L_14 , V_20 ) ;
F_16 ( V_3 , V_20 ) ;
}
void F_70 ( struct V_2 * V_3 , int V_81 ,
enum V_82 V_83 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_13 = 0 ;
T_1 V_84 ;
unsigned long V_24 ;
V_10 -> V_31 . V_80 = F_71 ( V_81 ) ;
V_10 -> V_12 . V_80 = F_72 ( V_81 ) ;
F_73 ( & V_1 -> V_11 ) ;
F_17 ( & V_1 -> V_85 , V_24 ) ;
V_84 = F_74 ( V_1 , V_86 ) ;
switch ( V_81 ) {
case 0 :
V_84 &= ~ V_87 ;
V_84 |= F_75 ( V_83 ) ;
break;
case 1 :
V_84 &= ~ V_88 ;
V_84 |= F_76 ( V_83 ) ;
break;
case 2 :
V_84 &= ~ V_89 ;
V_84 |= F_77 ( V_83 ) ;
break;
case 3 :
V_84 &= ~ V_90 ;
V_84 |= F_78 ( V_83 ) ;
break;
default:
F_79 () ;
break;
}
F_35 ( V_1 , V_86 , V_84 ) ;
F_19 ( & V_1 -> V_85 , V_24 ) ;
F_9 ( L_15 , V_10 -> V_14 , V_84 ) ;
F_80 ( V_10 -> V_15 , V_81 ) ;
V_13 |= F_14 ( V_10 -> V_15 ) ;
V_13 |= F_15 ( V_10 -> V_18 ) ;
F_8 ( V_3 , V_13 ) ;
}
int F_81 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
if ( F_45 ( ! V_3 ) )
return - V_68 ;
return V_10 -> V_18 ;
}
struct V_2 * F_82 ( struct V_21 * V_6 ,
struct V_16 * V_17 , int V_27 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_83 ( sizeof( * V_10 ) , V_91 ) ;
if ( ! V_10 )
return F_84 ( - V_92 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_27 = V_27 ;
V_10 -> V_18 = F_85 ( V_27 ) ;
F_86 ( & V_10 -> V_38 ) ;
V_10 -> V_12 . V_78 = F_64 ;
V_10 -> V_31 . V_78 = F_67 ;
snprintf ( V_10 -> V_14 , sizeof( V_10 -> V_14 ) , L_16 ,
F_43 ( F_42 ( V_17 ) ) , V_27 ) ;
F_87 ( V_6 , V_3 , V_17 , NULL , & V_93 ) ;
F_88 ( V_3 , & V_94 ) ;
V_17 -> V_3 = V_3 ;
F_89 ( V_17 , & V_3 -> V_11 ) ;
return V_3 ;
}
