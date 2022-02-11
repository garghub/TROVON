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
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_13 = V_10 -> V_13 ;
T_1 V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < F_9 ( V_10 -> V_16 ) ; V_14 ++ ) {
struct V_17 * V_18 = V_10 -> V_16 [ V_14 ] ;
if ( V_18 ) {
enum V_19 V_20 = F_10 ( V_18 ) ;
V_15 |= F_11 ( V_20 ) ;
}
}
V_15 |= F_12 ( V_10 -> V_13 ) ;
V_15 |= V_21 ;
F_13 ( L_1 , V_10 -> V_22 , V_15 ) ;
F_14 ( V_1 , F_15 ( V_13 ) , V_15 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_23 * V_25 = V_10 -> V_26 ;
F_17 ( V_24 ) ;
V_10 -> V_11 . V_26 = V_24 ;
V_10 -> V_26 = V_24 ;
if ( V_25 )
F_18 ( & V_10 -> V_27 , V_25 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_23 * V_26 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_8 ( V_3 ) ;
if ( V_10 -> V_28 )
F_18 ( & V_10 -> V_27 ,
V_10 -> V_28 ) ;
V_10 -> V_28 = V_26 ;
F_4 ( V_3 , V_29 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_32 * V_6 = V_3 -> V_6 ;
struct V_33 * V_34 ;
unsigned long V_35 , V_14 ;
F_21 ( & V_6 -> V_36 , V_35 ) ;
V_34 = V_10 -> V_34 ;
if ( V_34 ) {
if ( ! V_31 || ( V_34 -> V_11 . V_37 == V_31 ) ) {
V_10 -> V_34 = NULL ;
F_22 ( V_6 , V_10 -> V_13 , V_34 ) ;
}
}
F_23 ( & V_6 -> V_36 , V_35 ) ;
for ( V_14 = 0 ; V_14 < F_9 ( V_10 -> V_16 ) ; V_14 ++ ) {
struct V_17 * V_18 = V_10 -> V_16 [ V_14 ] ;
if ( V_18 )
F_24 ( V_18 ) ;
}
}
static void F_25 ( struct V_38 * V_39 )
{
struct V_10 * V_10 =
F_26 ( V_39 , struct V_10 , F_25 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_23 * V_26 = V_10 -> V_26 ;
if ( ! V_26 )
return;
F_17 ( V_26 ) ;
F_27 ( V_10 -> V_18 , V_26 ) ;
F_19 ( V_3 , V_26 ) ;
}
static void F_28 ( struct V_40 * V_41 , void * V_42 )
{
struct V_10 * V_10 =
F_26 ( V_41 , struct V_10 , V_27 ) ;
struct V_32 * V_6 = V_10 -> V_11 . V_6 ;
F_29 ( & V_6 -> V_43 . V_44 ) ;
F_30 ( V_42 ) ;
F_31 ( & V_6 -> V_43 . V_44 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
V_10 -> V_18 -> V_45 -> V_46 ( V_10 -> V_18 ) ;
F_33 ( V_3 ) ;
F_34 ( & V_10 -> V_27 ) ;
F_35 ( V_10 ) ;
}
static void F_36 ( struct V_2 * V_3 , int V_47 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_48 = ( V_47 == V_49 ) ;
F_13 ( L_2 , V_10 -> V_22 , V_47 ) ;
if ( V_48 != V_10 -> V_48 ) {
if ( V_48 ) {
F_37 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_50 ) ;
} else {
F_38 ( & V_1 -> V_11 , & V_10 -> V_50 ) ;
F_39 ( V_1 ) ;
}
V_10 -> V_48 = V_48 ;
}
}
static bool F_40 ( struct V_2 * V_3 ,
const struct V_51 * V_47 ,
struct V_51 * V_52 )
{
return true ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_13 = V_10 -> V_13 ;
F_14 ( V_1 , F_42 ( V_13 ) ,
V_53 ) ;
F_14 ( V_1 , F_43 ( V_13 , 0 ) ,
F_44 ( V_54 ) |
F_45 ( V_55 ) |
V_56 ) ;
F_14 ( V_1 , F_46 ( V_13 , 0 ) , 0xff ) ;
F_14 ( V_1 , F_47 ( V_13 , 0 ) , 0x00 ) ;
F_14 ( V_1 , F_48 ( V_13 , 0 ) ,
F_49 ( V_57 ) |
V_58 ) ;
F_14 ( V_1 , F_48 ( V_13 , 1 ) , 0 ) ;
F_14 ( V_1 , F_48 ( V_13 , 2 ) , 0 ) ;
F_14 ( V_1 , F_48 ( V_13 , 3 ) , 0 ) ;
F_14 ( V_1 , F_48 ( V_13 , 4 ) , 0 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_51 * V_47 ,
struct V_51 * V_52 ,
int V_59 , int V_60 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_61 ;
V_47 = V_52 ;
F_13 ( L_3 ,
V_10 -> V_22 , V_47 -> V_11 . V_13 , V_47 -> V_22 ,
V_47 -> V_62 , V_47 -> clock ,
V_47 -> V_63 , V_47 -> V_64 ,
V_47 -> V_65 , V_47 -> V_66 ,
V_47 -> V_67 , V_47 -> V_68 ,
V_47 -> V_69 , V_47 -> V_70 ,
V_47 -> type , V_47 -> V_35 ) ;
F_17 ( V_3 -> V_26 ) ;
V_61 = F_51 ( V_10 -> V_18 , V_3 , V_3 -> V_26 ,
0 , 0 , V_47 -> V_63 , V_47 -> V_67 ,
V_59 << 16 , V_60 << 16 ,
V_47 -> V_63 << 16 , V_47 -> V_67 << 16 ) ;
if ( V_61 ) {
F_30 ( V_3 -> V_26 ) ;
F_52 ( V_3 -> V_6 -> V_6 , L_4 ,
V_10 -> V_22 , V_61 ) ;
return V_61 ;
}
F_14 ( V_1 , F_53 ( V_10 -> V_13 ) ,
F_54 ( V_47 -> V_63 ) |
F_55 ( V_47 -> V_67 ) ) ;
F_16 ( V_3 , V_3 -> V_26 ) ;
F_19 ( V_3 , V_3 -> V_26 ) ;
return 0 ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_22 ) ;
F_37 ( F_1 ( V_3 ) ) ;
F_36 ( V_3 , V_71 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_36 ( V_3 , V_49 ) ;
F_8 ( V_3 ) ;
F_39 ( F_1 ( V_3 ) ) ;
}
static int F_58 ( struct V_2 * V_3 , int V_59 , int V_60 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_17 * V_18 = V_10 -> V_18 ;
struct V_51 * V_47 = & V_3 -> V_47 ;
int V_61 ;
F_17 ( V_3 -> V_26 ) ;
V_61 = F_51 ( V_18 , V_3 , V_3 -> V_26 ,
0 , 0 , V_47 -> V_63 , V_47 -> V_67 ,
V_59 << 16 , V_60 << 16 ,
V_47 -> V_63 << 16 , V_47 -> V_67 << 16 ) ;
if ( V_61 ) {
F_30 ( V_3 -> V_26 ) ;
return V_61 ;
}
F_16 ( V_3 , V_3 -> V_26 ) ;
F_19 ( V_3 , V_3 -> V_26 ) ;
return 0 ;
}
static void F_59 ( struct V_2 * V_3 )
{
}
static int F_60 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
struct V_33 * V_34 ,
T_1 V_72 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_32 * V_6 = V_3 -> V_6 ;
struct V_73 * V_74 ;
unsigned long V_35 ;
if ( V_10 -> V_34 ) {
F_52 ( V_6 -> V_6 , L_6 ) ;
return - V_75 ;
}
V_74 = F_61 ( V_24 , 0 ) ;
F_21 ( & V_6 -> V_36 , V_35 ) ;
V_10 -> V_34 = V_34 ;
F_23 ( & V_6 -> V_36 , V_35 ) ;
F_16 ( V_3 , V_24 ) ;
return F_62 ( V_74 , & V_10 -> F_25 ) ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_76 * V_77 , T_2 V_42 )
{
return - V_78 ;
}
static void F_64 ( struct V_79 * V_80 , T_1 V_81 )
{
struct V_10 * V_10 = F_26 ( V_80 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_38 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_65 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_29 ) {
F_20 ( V_3 , NULL ) ;
F_66 ( & V_10 -> V_27 , V_5 -> V_82 ) ;
}
}
static void F_67 ( struct V_79 * V_80 , T_1 V_81 )
{
struct V_10 * V_10 = F_26 ( V_80 , struct V_10 , V_50 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_7 , V_10 -> V_22 , V_81 ) ;
F_8 ( V_3 ) ;
}
T_1 F_68 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_83 ;
}
void F_69 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
F_13 ( L_8 , V_31 ) ;
F_20 ( V_3 , V_31 ) ;
}
void F_70 ( struct V_2 * V_3 , int V_84 ,
enum V_85 V_86 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
static const enum V_87 V_88 [] = {
V_89 , V_90 , V_91 , V_92 ,
} ;
T_1 V_93 ;
V_10 -> V_50 . V_83 = F_71 ( V_84 ) ;
V_10 -> V_12 . V_83 = F_72 ( V_84 ) ;
if ( ! V_1 )
return;
V_93 = F_73 ( V_1 , V_94 ) ;
switch ( V_84 ) {
case 0 :
V_93 &= ~ V_95 ;
V_93 |= F_74 ( V_86 ) ;
break;
case 1 :
V_93 &= ~ V_96 ;
V_93 |= F_75 ( V_86 ) ;
break;
case 2 :
V_93 &= ~ V_97 ;
V_93 |= F_76 ( V_86 ) ;
break;
case 3 :
V_93 &= ~ V_98 ;
V_93 |= F_77 ( V_86 ) ;
break;
default:
F_78 () ;
break;
}
F_41 ( V_3 ) ;
F_13 ( L_9 , V_10 -> V_22 , V_93 ) ;
F_14 ( V_1 , V_94 , V_93 ) ;
F_14 ( V_1 , F_79 ( V_10 -> V_13 ) ,
F_80 ( V_99 ) |
F_81 ( V_88 [ V_84 ] ) ) ;
F_8 ( V_3 ) ;
}
static void F_82 ( struct V_2 * V_3 , enum V_19 V_100 ,
struct V_17 * V_18 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_83 ( V_100 >= F_9 ( V_10 -> V_16 ) ) ;
if ( V_10 -> V_16 [ V_100 ] == V_18 )
return;
V_10 -> V_16 [ V_100 ] = V_18 ;
F_41 ( V_3 ) ;
if ( V_10 -> V_48 && ( V_18 != V_10 -> V_18 ) )
F_8 ( V_3 ) ;
}
void F_84 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
F_82 ( V_3 , F_10 ( V_18 ) , V_18 ) ;
}
void F_85 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
F_82 ( V_3 , F_10 ( V_18 ) , NULL ) ;
}
struct V_2 * F_86 ( struct V_32 * V_6 ,
struct V_17 * V_18 , int V_13 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
int V_61 ;
V_10 = F_87 ( sizeof( * V_10 ) , V_101 ) ;
if ( ! V_10 ) {
V_61 = - V_102 ;
goto V_103;
}
V_3 = & V_10 -> V_11 ;
V_10 -> V_18 = V_18 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_12 . V_80 = F_64 ;
V_10 -> V_50 . V_80 = F_67 ;
snprintf ( V_10 -> V_22 , sizeof( V_10 -> V_22 ) , L_10 ,
F_88 ( F_10 ( V_18 ) ) , V_13 ) ;
V_61 = F_89 ( & V_10 -> V_27 , 16 ,
L_11 , F_28 ) ;
if ( V_61 )
goto V_103;
F_90 ( & V_10 -> F_25 , F_25 ) ;
F_91 ( V_6 , V_3 , & V_104 ) ;
F_92 ( V_3 , & V_105 ) ;
F_93 ( V_10 -> V_18 , & V_3 -> V_11 ) ;
return V_3 ;
V_103:
if ( V_3 )
F_32 ( V_3 ) ;
return F_94 ( V_61 ) ;
}
