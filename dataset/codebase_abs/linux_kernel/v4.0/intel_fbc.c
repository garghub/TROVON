static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
V_4 -> V_7 . V_8 = false ;
V_6 = F_2 ( V_9 ) ;
if ( ( V_6 & V_10 ) == 0 )
return;
V_6 &= ~ V_10 ;
F_3 ( V_9 , V_6 ) ;
if ( F_4 ( ( F_2 ( V_11 ) & V_12 ) == 0 , 10 ) ) {
F_5 ( L_1 ) ;
return;
}
F_5 ( L_2 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
struct V_20 * V_20 = F_8 ( V_14 ) ;
int V_21 ;
int V_22 ;
T_1 V_6 ;
V_4 -> V_7 . V_8 = true ;
V_21 = V_4 -> V_7 . V_23 / V_24 ;
if ( V_16 -> V_25 [ 0 ] < V_21 )
V_21 = V_16 -> V_25 [ 0 ] ;
if ( F_9 ( V_2 ) )
V_21 = ( V_21 / 32 ) - 1 ;
else
V_21 = ( V_21 / 64 ) - 1 ;
for ( V_22 = 0 ; V_22 < ( V_24 / 32 ) + 1 ; V_22 ++ )
F_3 ( V_26 + ( V_22 * 4 ) , 0 ) ;
if ( F_10 ( V_2 ) ) {
T_1 V_27 ;
V_27 = V_28 | V_29 | V_30 ;
V_27 |= F_11 ( V_20 -> V_31 ) ;
F_3 ( V_32 , V_27 ) ;
F_3 ( V_33 , V_14 -> V_34 ) ;
}
V_6 = F_2 ( V_9 ) ;
V_6 &= 0x3fff << V_35 ;
V_6 |= V_10 | V_36 ;
if ( F_12 ( V_2 ) )
V_6 |= V_37 ;
V_6 |= ( V_21 & 0xff ) << V_38 ;
V_6 |= V_19 -> V_39 ;
F_3 ( V_9 , V_6 ) ;
F_5 ( L_3 ,
V_21 , V_14 -> V_34 , F_13 ( V_20 -> V_31 ) ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_9 ) & V_10 ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
struct V_20 * V_20 = F_8 ( V_14 ) ;
T_1 V_40 ;
V_4 -> V_7 . V_8 = true ;
V_40 = F_16 ( V_20 -> V_31 ) | V_41 ;
if ( F_17 ( V_16 -> V_42 , 0 ) == 2 )
V_40 |= V_43 ;
else
V_40 |= V_44 ;
V_40 |= V_45 | V_19 -> V_39 ;
F_3 ( V_46 , V_14 -> V_34 ) ;
F_3 ( V_47 , V_40 | V_48 ) ;
F_5 ( L_4 , F_13 ( V_20 -> V_31 ) ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_40 ;
V_4 -> V_7 . V_8 = false ;
V_40 = F_2 ( V_47 ) ;
if ( V_40 & V_48 ) {
V_40 &= ~ V_48 ;
F_3 ( V_47 , V_40 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_47 ) & V_48 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_49 ;
F_21 ( V_4 , V_50 ) ;
V_49 = F_2 ( V_51 ) ;
V_49 |= V_52 <<
V_53 ;
F_3 ( V_51 , V_49 ) ;
V_49 |= V_52 ;
F_3 ( V_51 , V_49 ) ;
V_49 &= ~ ( V_52 <<
V_53 ) ;
F_3 ( V_51 , V_49 ) ;
F_22 ( V_51 ) ;
F_23 ( V_4 , V_50 ) ;
}
static void F_24 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
struct V_20 * V_20 = F_8 ( V_14 ) ;
T_1 V_40 ;
V_4 -> V_7 . V_8 = true ;
V_40 = F_16 ( V_20 -> V_31 ) ;
if ( F_17 ( V_16 -> V_42 , 0 ) == 2 )
V_4 -> V_7 . V_54 ++ ;
switch ( V_4 -> V_7 . V_54 ) {
case 4 :
case 3 :
V_40 |= V_55 ;
break;
case 2 :
V_40 |= V_43 ;
break;
case 1 :
V_40 |= V_44 ;
break;
}
V_40 |= V_45 ;
if ( F_25 ( V_2 ) )
V_40 |= V_19 -> V_39 ;
F_3 ( V_56 , V_14 -> V_34 ) ;
F_3 ( V_57 , F_26 ( V_19 ) | V_58 ) ;
F_3 ( V_59 , V_40 | V_48 ) ;
if ( F_27 ( V_2 ) ) {
F_3 ( V_60 ,
V_61 | V_19 -> V_39 ) ;
F_3 ( V_62 , V_14 -> V_34 ) ;
F_20 ( V_2 ) ;
}
F_5 ( L_4 , F_13 ( V_20 -> V_31 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_40 ;
V_4 -> V_7 . V_8 = false ;
V_40 = F_2 ( V_59 ) ;
if ( V_40 & V_48 ) {
V_40 &= ~ V_48 ;
F_3 ( V_59 , V_40 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_59 ) & V_48 ;
}
static void F_30 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
struct V_20 * V_20 = F_8 ( V_14 ) ;
T_1 V_40 ;
V_4 -> V_7 . V_8 = true ;
V_40 = F_31 ( V_20 -> V_31 ) ;
if ( F_17 ( V_16 -> V_42 , 0 ) == 2 )
V_4 -> V_7 . V_54 ++ ;
switch ( V_4 -> V_7 . V_54 ) {
case 4 :
case 3 :
V_40 |= V_55 ;
break;
case 2 :
V_40 |= V_43 ;
break;
case 1 :
V_40 |= V_44 ;
break;
}
V_40 |= V_63 ;
if ( V_4 -> V_7 . V_64 )
V_40 |= V_65 ;
F_3 ( V_59 , V_40 | V_48 ) ;
if ( F_32 ( V_2 ) ) {
F_3 ( V_66 ,
F_2 ( V_66 ) |
V_67 ) ;
} else {
F_3 ( F_33 ( V_20 -> V_68 ) ,
F_2 ( F_33 ( V_20 -> V_68 ) ) |
V_69 ) ;
}
F_3 ( V_60 ,
V_61 | V_19 -> V_39 ) ;
F_3 ( V_62 , V_14 -> V_34 ) ;
F_20 ( V_2 ) ;
F_5 ( L_4 , F_13 ( V_20 -> V_31 ) ) ;
}
bool F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_7 . V_8 ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_70 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_36 ( V_2 ) )
return;
if ( ! F_34 ( V_2 ) )
return;
F_3 ( V_71 , V_70 ) ;
}
static void F_37 ( struct V_72 * V_73 )
{
struct V_74 * V_75 =
F_38 ( F_39 ( V_73 ) ,
struct V_74 , V_75 ) ;
struct V_1 * V_2 = V_75 -> V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_40 ( & V_2 -> V_76 ) ;
if ( V_75 == V_4 -> V_7 . V_77 ) {
if ( V_75 -> V_14 -> V_17 -> V_16 == V_75 -> V_16 ) {
V_4 -> V_78 . V_79 ( V_75 -> V_14 ) ;
V_4 -> V_7 . V_31 = F_8 ( V_75 -> V_14 ) -> V_31 ;
V_4 -> V_7 . V_80 = V_75 -> V_14 -> V_17 -> V_16 -> V_81 . V_82 ;
V_4 -> V_7 . V_34 = V_75 -> V_14 -> V_34 ;
}
V_4 -> V_7 . V_77 = NULL ;
}
F_41 ( & V_2 -> V_76 ) ;
F_42 ( V_75 ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
if ( V_4 -> V_7 . V_77 == NULL )
return;
F_5 ( L_5 ) ;
if ( F_44 ( & V_4 -> V_7 . V_77 -> V_75 ) )
F_42 ( V_4 -> V_7 . V_77 ) ;
V_4 -> V_7 . V_77 = NULL ;
}
static void F_45 ( struct V_13 * V_14 )
{
struct V_74 * V_75 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_78 . V_79 )
return;
F_43 ( V_4 ) ;
V_75 = F_46 ( sizeof( * V_75 ) , V_83 ) ;
if ( V_75 == NULL ) {
F_47 ( L_6 ) ;
V_4 -> V_78 . V_79 ( V_14 ) ;
return;
}
V_75 -> V_14 = V_14 ;
V_75 -> V_16 = V_14 -> V_17 -> V_16 ;
F_48 ( & V_75 -> V_75 , F_37 ) ;
V_4 -> V_7 . V_77 = V_75 ;
F_49 ( & V_75 -> V_75 , F_50 ( 50 ) ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_43 ( V_4 ) ;
if ( ! V_4 -> V_78 . V_84 )
return;
V_4 -> V_78 . V_84 ( V_2 ) ;
V_4 -> V_7 . V_31 = - 1 ;
}
static bool F_52 ( struct V_3 * V_4 ,
enum V_85 V_86 )
{
if ( V_4 -> V_7 . V_85 == V_86 )
return false ;
V_4 -> V_7 . V_85 = V_86 ;
return true ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = NULL , * V_87 ;
struct V_20 * V_20 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
const struct V_88 * V_89 ;
unsigned int V_90 , V_91 ;
if ( ! F_54 ( V_2 ) ) {
F_52 ( V_4 , V_92 ) ;
return;
}
if ( ! V_93 . V_94 ) {
if ( F_52 ( V_4 , V_95 ) )
F_5 ( L_7 ) ;
return;
}
F_55 (dev, tmp_crtc) {
if ( F_56 ( V_87 ) &&
F_8 ( V_87 ) -> V_96 ) {
if ( V_14 ) {
if ( F_52 ( V_4 , V_97 ) )
F_5 ( L_8 ) ;
goto V_98;
}
V_14 = V_87 ;
}
}
if ( ! V_14 || V_14 -> V_17 -> V_16 == NULL ) {
if ( F_52 ( V_4 , V_99 ) )
F_5 ( L_9 ) ;
goto V_98;
}
V_20 = F_8 ( V_14 ) ;
V_16 = V_14 -> V_17 -> V_16 ;
V_19 = F_7 ( V_16 ) ;
V_89 = & V_20 -> V_100 -> V_81 . V_89 ;
if ( V_93 . V_79 < 0 ) {
if ( F_52 ( V_4 , V_101 ) )
F_5 ( L_10 ) ;
goto V_98;
}
if ( ! V_93 . V_79 ) {
if ( F_52 ( V_4 , V_95 ) )
F_5 ( L_7 ) ;
goto V_98;
}
if ( ( V_89 -> V_102 & V_103 ) ||
( V_89 -> V_102 & V_104 ) ) {
if ( F_52 ( V_4 , V_105 ) )
F_5 ( L_11
L_12 ) ;
goto V_98;
}
if ( F_57 ( V_2 ) -> V_106 >= 8 || F_58 ( V_2 ) ) {
V_90 = 4096 ;
V_91 = 4096 ;
} else if ( F_59 ( V_2 ) || F_57 ( V_2 ) -> V_106 >= 5 ) {
V_90 = 4096 ;
V_91 = 2048 ;
} else {
V_90 = 2048 ;
V_91 = 1536 ;
}
if ( V_20 -> V_100 -> V_107 > V_90 ||
V_20 -> V_100 -> V_108 > V_91 ) {
if ( F_52 ( V_4 , V_109 ) )
F_5 ( L_13 ) ;
goto V_98;
}
if ( ( F_57 ( V_2 ) -> V_106 < 4 || F_60 ( V_2 ) ) &&
V_20 -> V_31 != V_110 ) {
if ( F_52 ( V_4 , V_111 ) )
F_5 ( L_14 ) ;
goto V_98;
}
if ( V_19 -> V_112 != V_113 ||
V_19 -> V_39 == V_114 ) {
if ( F_52 ( V_4 , V_115 ) )
F_5 ( L_15 ) ;
goto V_98;
}
if ( F_57 ( V_2 ) -> V_106 <= 4 && ! F_59 ( V_2 ) &&
V_14 -> V_17 -> V_116 -> V_117 != F_61 ( V_118 ) ) {
if ( F_52 ( V_4 , V_105 ) )
F_5 ( L_16 ) ;
goto V_98;
}
if ( F_62 () )
goto V_98;
if ( F_63 ( V_2 , V_19 -> V_81 . V_23 ,
F_17 ( V_16 -> V_42 , 0 ) ) ) {
if ( F_52 ( V_4 , V_119 ) )
F_5 ( L_17 ) ;
goto V_98;
}
if ( V_4 -> V_7 . V_31 == V_20 -> V_31 &&
V_4 -> V_7 . V_80 == V_16 -> V_81 . V_82 &&
V_4 -> V_7 . V_34 == V_14 -> V_34 )
return;
if ( F_34 ( V_2 ) ) {
F_5 ( L_18 ) ;
F_51 ( V_2 ) ;
}
F_45 ( V_14 ) ;
V_4 -> V_7 . V_85 = V_120 ;
return;
V_98:
if ( F_34 ( V_2 ) ) {
F_5 ( L_19 ) ;
F_51 ( V_2 ) ;
}
F_64 ( V_2 ) ;
}
void F_65 ( struct V_3 * V_4 )
{
if ( ! F_54 ( V_4 ) ) {
V_4 -> V_7 . V_8 = false ;
return;
}
if ( F_57 ( V_4 ) -> V_106 >= 7 ) {
V_4 -> V_78 . V_121 = F_29 ;
V_4 -> V_78 . V_79 = F_30 ;
V_4 -> V_78 . V_84 = F_28 ;
} else if ( F_57 ( V_4 ) -> V_106 >= 5 ) {
V_4 -> V_78 . V_121 = F_29 ;
V_4 -> V_78 . V_79 = F_24 ;
V_4 -> V_78 . V_84 = F_28 ;
} else if ( F_66 ( V_4 ) ) {
V_4 -> V_78 . V_121 = F_19 ;
V_4 -> V_78 . V_79 = F_15 ;
V_4 -> V_78 . V_84 = F_18 ;
} else {
V_4 -> V_78 . V_121 = F_14 ;
V_4 -> V_78 . V_79 = F_6 ;
V_4 -> V_78 . V_84 = F_1 ;
F_3 ( V_9 , 500 << V_35 ) ;
}
V_4 -> V_7 . V_8 = V_4 -> V_78 . V_121 ( V_4 -> V_2 ) ;
}
