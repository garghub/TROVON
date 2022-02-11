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
V_10 -> V_11 . V_27 -> V_26 = V_24 ;
V_10 -> V_26 = V_24 ;
if ( V_25 )
F_18 ( & V_10 -> V_28 , V_25 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_23 * V_26 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_8 ( V_3 ) ;
if ( V_10 -> V_29 )
F_18 ( & V_10 -> V_28 ,
V_10 -> V_29 ) ;
V_10 -> V_29 = V_26 ;
F_4 ( V_3 , V_30 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_33 * V_6 = V_3 -> V_6 ;
struct V_34 * V_35 ;
unsigned long V_36 , V_14 ;
F_21 ( & V_6 -> V_37 , V_36 ) ;
V_35 = V_10 -> V_35 ;
if ( V_35 ) {
if ( ! V_32 || ( V_35 -> V_11 . V_38 == V_32 ) ) {
V_10 -> V_35 = NULL ;
F_22 ( V_6 , V_10 -> V_13 , V_35 ) ;
}
}
F_23 ( & V_6 -> V_37 , V_36 ) ;
for ( V_14 = 0 ; V_14 < F_9 ( V_10 -> V_16 ) ; V_14 ++ ) {
struct V_17 * V_18 = V_10 -> V_16 [ V_14 ] ;
if ( V_18 )
F_24 ( V_18 ) ;
}
}
static void F_25 ( struct V_39 * V_40 )
{
struct V_10 * V_10 =
F_26 ( V_40 , struct V_10 , F_25 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_23 * V_26 = V_10 -> V_26 ;
if ( ! V_26 )
return;
F_17 ( V_26 ) ;
F_27 ( V_10 -> V_18 , V_26 ) ;
F_19 ( V_3 , V_26 ) ;
}
static void F_28 ( struct V_41 * V_42 , void * V_43 )
{
struct V_10 * V_10 =
F_26 ( V_42 , struct V_10 , V_28 ) ;
struct V_33 * V_6 = V_10 -> V_11 . V_6 ;
F_29 ( & V_6 -> V_44 . V_45 ) ;
F_30 ( V_43 ) ;
F_31 ( & V_6 -> V_44 . V_45 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_33 ( V_3 ) ;
F_34 ( & V_10 -> V_28 ) ;
F_35 ( V_10 ) ;
}
static void F_36 ( struct V_2 * V_3 , int V_46 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_47 = ( V_46 == V_48 ) ;
F_13 ( L_2 , V_10 -> V_22 , V_46 ) ;
if ( V_47 != V_10 -> V_47 ) {
if ( V_47 ) {
F_37 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_49 ) ;
} else {
F_38 ( & V_1 -> V_11 , & V_10 -> V_49 ) ;
F_39 ( V_1 ) ;
}
V_10 -> V_47 = V_47 ;
}
}
static bool F_40 ( struct V_2 * V_3 ,
const struct V_50 * V_46 ,
struct V_50 * V_51 )
{
return true ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_13 = V_10 -> V_13 ;
F_14 ( V_1 , F_42 ( V_13 ) ,
V_52 ) ;
F_14 ( V_1 , F_43 ( V_13 , 0 ) ,
F_44 ( V_53 ) |
F_45 ( V_54 ) |
V_55 ) ;
F_14 ( V_1 , F_46 ( V_13 , 0 ) , 0xff ) ;
F_14 ( V_1 , F_47 ( V_13 , 0 ) , 0x00 ) ;
F_14 ( V_1 , F_48 ( V_13 , 0 ) ,
F_49 ( V_56 ) |
V_57 ) ;
F_14 ( V_1 , F_48 ( V_13 , 1 ) , 0 ) ;
F_14 ( V_1 , F_48 ( V_13 , 2 ) , 0 ) ;
F_14 ( V_1 , F_48 ( V_13 , 3 ) , 0 ) ;
F_14 ( V_1 , F_48 ( V_13 , 4 ) , 0 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_50 * V_46 ,
struct V_50 * V_51 ,
int V_58 , int V_59 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_60 ;
V_46 = V_51 ;
F_13 ( L_3 ,
V_10 -> V_22 , V_46 -> V_11 . V_13 , V_46 -> V_22 ,
V_46 -> V_61 , V_46 -> clock ,
V_46 -> V_62 , V_46 -> V_63 ,
V_46 -> V_64 , V_46 -> V_65 ,
V_46 -> V_66 , V_46 -> V_67 ,
V_46 -> V_68 , V_46 -> V_69 ,
V_46 -> type , V_46 -> V_36 ) ;
F_17 ( V_3 -> V_27 -> V_26 ) ;
V_60 = F_51 ( V_10 -> V_18 , V_3 , V_3 -> V_27 -> V_26 ,
0 , 0 , V_46 -> V_62 , V_46 -> V_66 ,
V_58 << 16 , V_59 << 16 ,
V_46 -> V_62 << 16 , V_46 -> V_66 << 16 ) ;
if ( V_60 ) {
F_30 ( V_3 -> V_27 -> V_26 ) ;
F_52 ( V_3 -> V_6 -> V_6 , L_4 ,
V_10 -> V_22 , V_60 ) ;
return V_60 ;
}
F_14 ( V_1 , F_53 ( V_10 -> V_13 ) ,
F_54 ( V_46 -> V_62 ) |
F_55 ( V_46 -> V_66 ) ) ;
F_16 ( V_3 , V_3 -> V_27 -> V_26 ) ;
F_19 ( V_3 , V_3 -> V_27 -> V_26 ) ;
return 0 ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_22 ) ;
F_37 ( F_1 ( V_3 ) ) ;
F_36 ( V_3 , V_70 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_36 ( V_3 , V_48 ) ;
F_8 ( V_3 ) ;
F_39 ( F_1 ( V_3 ) ) ;
}
static int F_58 ( struct V_2 * V_3 , int V_58 , int V_59 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_17 * V_18 = V_10 -> V_18 ;
struct V_50 * V_46 = & V_3 -> V_46 ;
int V_60 ;
F_17 ( V_3 -> V_27 -> V_26 ) ;
V_60 = F_51 ( V_18 , V_3 , V_3 -> V_27 -> V_26 ,
0 , 0 , V_46 -> V_62 , V_46 -> V_66 ,
V_58 << 16 , V_59 << 16 ,
V_46 -> V_62 << 16 , V_46 -> V_66 << 16 ) ;
if ( V_60 ) {
F_30 ( V_3 -> V_27 -> V_26 ) ;
return V_60 ;
}
F_16 ( V_3 , V_3 -> V_27 -> V_26 ) ;
F_19 ( V_3 , V_3 -> V_27 -> V_26 ) ;
return 0 ;
}
static void F_59 ( struct V_2 * V_3 )
{
}
static int F_60 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
struct V_34 * V_35 ,
T_1 V_71 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_33 * V_6 = V_3 -> V_6 ;
struct V_72 * V_73 ;
unsigned long V_36 ;
if ( V_10 -> V_35 ) {
F_52 ( V_6 -> V_6 , L_6 ) ;
return - V_74 ;
}
V_73 = F_61 ( V_24 , 0 ) ;
F_21 ( & V_6 -> V_37 , V_36 ) ;
V_10 -> V_35 = V_35 ;
F_23 ( & V_6 -> V_37 , V_36 ) ;
F_16 ( V_3 , V_24 ) ;
return F_62 ( V_73 , & V_10 -> F_25 ) ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_75 * V_76 , T_2 V_43 )
{
return - V_77 ;
}
static void F_64 ( struct V_78 * V_79 , T_1 V_80 )
{
struct V_10 * V_10 = F_26 ( V_79 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_38 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_65 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_30 ) {
F_20 ( V_3 , NULL ) ;
F_66 ( & V_10 -> V_28 , V_5 -> V_81 ) ;
}
}
static void F_67 ( struct V_78 * V_79 , T_1 V_80 )
{
struct V_10 * V_10 = F_26 ( V_79 , struct V_10 , V_49 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_7 , V_10 -> V_22 , V_80 ) ;
F_8 ( V_3 ) ;
}
T_1 F_68 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_82 ;
}
void F_69 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
F_13 ( L_8 , V_32 ) ;
F_20 ( V_3 , V_32 ) ;
}
void F_70 ( struct V_2 * V_3 , int V_83 ,
enum V_84 V_85 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
static const enum V_86 V_87 [] = {
V_88 , V_89 , V_90 , V_91 ,
} ;
T_1 V_92 ;
V_10 -> V_49 . V_82 = F_71 ( V_83 ) ;
V_10 -> V_12 . V_82 = F_72 ( V_83 ) ;
if ( ! V_1 )
return;
V_92 = F_73 ( V_1 , V_93 ) ;
switch ( V_83 ) {
case 0 :
V_92 &= ~ V_94 ;
V_92 |= F_74 ( V_85 ) ;
break;
case 1 :
V_92 &= ~ V_95 ;
V_92 |= F_75 ( V_85 ) ;
break;
case 2 :
V_92 &= ~ V_96 ;
V_92 |= F_76 ( V_85 ) ;
break;
case 3 :
V_92 &= ~ V_97 ;
V_92 |= F_77 ( V_85 ) ;
break;
default:
F_78 () ;
break;
}
F_41 ( V_3 ) ;
F_13 ( L_9 , V_10 -> V_22 , V_92 ) ;
F_14 ( V_1 , V_93 , V_92 ) ;
F_14 ( V_1 , F_79 ( V_10 -> V_13 ) ,
F_80 ( V_98 ) |
F_81 ( V_87 [ V_83 ] ) ) ;
F_8 ( V_3 ) ;
}
static void F_82 ( struct V_2 * V_3 , enum V_19 V_99 ,
struct V_17 * V_18 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_83 ( V_99 >= F_9 ( V_10 -> V_16 ) ) ;
if ( V_10 -> V_16 [ V_99 ] == V_18 )
return;
V_10 -> V_16 [ V_99 ] = V_18 ;
F_41 ( V_3 ) ;
if ( V_10 -> V_47 && ( V_18 != V_10 -> V_18 ) )
F_8 ( V_3 ) ;
}
void F_84 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
F_82 ( V_3 , F_10 ( V_18 ) , V_18 ) ;
}
void F_85 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
if ( F_5 ( V_3 ) -> V_18 == V_18 )
return;
F_82 ( V_3 , F_10 ( V_18 ) , NULL ) ;
}
struct V_2 * F_86 ( struct V_33 * V_6 ,
struct V_17 * V_18 , int V_13 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
int V_60 ;
V_10 = F_87 ( sizeof( * V_10 ) , V_100 ) ;
if ( ! V_10 ) {
V_60 = - V_101 ;
goto V_102;
}
V_3 = & V_10 -> V_11 ;
V_10 -> V_18 = V_18 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_12 . V_79 = F_64 ;
V_10 -> V_49 . V_79 = F_67 ;
snprintf ( V_10 -> V_22 , sizeof( V_10 -> V_22 ) , L_10 ,
F_88 ( F_10 ( V_18 ) ) , V_13 ) ;
V_60 = F_89 ( & V_10 -> V_28 , 16 ,
L_11 , F_28 ) ;
if ( V_60 )
goto V_102;
F_90 ( & V_10 -> F_25 , F_25 ) ;
F_91 ( V_6 , V_3 , V_18 , NULL , & V_103 ) ;
F_92 ( V_3 , & V_104 ) ;
F_93 ( V_10 -> V_18 , & V_3 -> V_11 ) ;
return V_3 ;
V_102:
if ( V_3 )
F_32 ( V_3 ) ;
return F_94 ( V_60 ) ;
}
