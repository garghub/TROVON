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
static void F_20 ( struct V_3 * V_4 )
{
F_3 ( V_49 , V_50 ) ;
F_21 ( V_49 ) ;
}
static void F_22 ( struct V_13 * V_14 )
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
V_4 -> V_7 . V_51 ++ ;
switch ( V_4 -> V_7 . V_51 ) {
case 4 :
case 3 :
V_40 |= V_52 ;
break;
case 2 :
V_40 |= V_43 ;
break;
case 1 :
V_40 |= V_44 ;
break;
}
V_40 |= V_45 ;
if ( F_23 ( V_2 ) )
V_40 |= V_19 -> V_39 ;
F_3 ( V_53 , V_14 -> V_34 ) ;
F_3 ( V_54 , F_24 ( V_19 ) | V_55 ) ;
F_3 ( V_56 , V_40 | V_48 ) ;
if ( F_25 ( V_2 ) ) {
F_3 ( V_57 ,
V_58 | V_19 -> V_39 ) ;
F_3 ( V_59 , V_14 -> V_34 ) ;
}
F_20 ( V_4 ) ;
F_5 ( L_4 , F_13 ( V_20 -> V_31 ) ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_40 ;
V_4 -> V_7 . V_8 = false ;
V_40 = F_2 ( V_56 ) ;
if ( V_40 & V_48 ) {
V_40 &= ~ V_48 ;
F_3 ( V_56 , V_40 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_56 ) & V_48 ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
struct V_20 * V_20 = F_8 ( V_14 ) ;
T_1 V_40 ;
V_4 -> V_7 . V_8 = true ;
V_40 = F_29 ( V_20 -> V_31 ) ;
if ( F_17 ( V_16 -> V_42 , 0 ) == 2 )
V_4 -> V_7 . V_51 ++ ;
switch ( V_4 -> V_7 . V_51 ) {
case 4 :
case 3 :
V_40 |= V_52 ;
break;
case 2 :
V_40 |= V_43 ;
break;
case 1 :
V_40 |= V_44 ;
break;
}
V_40 |= V_60 ;
if ( V_4 -> V_7 . V_61 )
V_40 |= V_62 ;
F_3 ( V_56 , V_40 | V_48 ) ;
if ( F_30 ( V_2 ) ) {
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 ) ;
} else {
F_3 ( F_31 ( V_20 -> V_65 ) ,
F_2 ( F_31 ( V_20 -> V_65 ) ) |
V_66 ) ;
}
F_3 ( V_57 ,
V_58 | V_19 -> V_39 ) ;
F_3 ( V_59 , V_14 -> V_34 ) ;
F_20 ( V_4 ) ;
F_5 ( L_4 , F_13 ( V_20 -> V_31 ) ) ;
}
bool F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_7 . V_8 ;
}
static void F_33 ( struct V_67 * V_68 )
{
struct V_69 * V_70 =
F_34 ( F_35 ( V_68 ) ,
struct V_69 , V_70 ) ;
struct V_1 * V_2 = V_70 -> V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_36 ( & V_2 -> V_71 ) ;
if ( V_70 == V_4 -> V_7 . V_72 ) {
if ( V_70 -> V_14 -> V_17 -> V_16 == V_70 -> V_16 ) {
V_4 -> V_73 . V_74 ( V_70 -> V_14 ) ;
V_4 -> V_7 . V_14 = F_8 ( V_70 -> V_14 ) ;
V_4 -> V_7 . V_75 = V_70 -> V_14 -> V_17 -> V_16 -> V_76 . V_77 ;
V_4 -> V_7 . V_34 = V_70 -> V_14 -> V_34 ;
}
V_4 -> V_7 . V_72 = NULL ;
}
F_37 ( & V_2 -> V_71 ) ;
F_38 ( V_70 ) ;
}
static void F_39 ( struct V_3 * V_4 )
{
if ( V_4 -> V_7 . V_72 == NULL )
return;
F_5 ( L_5 ) ;
if ( F_40 ( & V_4 -> V_7 . V_72 -> V_70 ) )
F_38 ( V_4 -> V_7 . V_72 ) ;
V_4 -> V_7 . V_72 = NULL ;
}
static void F_41 ( struct V_13 * V_14 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_73 . V_74 )
return;
F_39 ( V_4 ) ;
V_70 = F_42 ( sizeof( * V_70 ) , V_78 ) ;
if ( V_70 == NULL ) {
F_43 ( L_6 ) ;
V_4 -> V_73 . V_74 ( V_14 ) ;
return;
}
V_70 -> V_14 = V_14 ;
V_70 -> V_16 = V_14 -> V_17 -> V_16 ;
F_44 ( & V_70 -> V_70 , F_33 ) ;
V_4 -> V_7 . V_72 = V_70 ;
F_45 ( & V_70 -> V_70 , F_46 ( 50 ) ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_39 ( V_4 ) ;
if ( ! V_4 -> V_73 . V_79 )
return;
V_4 -> V_73 . V_79 ( V_2 ) ;
V_4 -> V_7 . V_14 = NULL ;
}
static bool F_48 ( struct V_3 * V_4 ,
enum V_80 V_81 )
{
if ( V_4 -> V_7 . V_80 == V_81 )
return false ;
V_4 -> V_7 . V_80 = V_81 ;
return true ;
}
static struct V_13 * F_49 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = NULL , * V_82 ;
enum V_65 V_65 ;
bool V_83 = false , V_84 = false ;
if ( F_50 ( V_4 ) || F_51 ( V_4 ) -> V_85 >= 8 )
V_83 = true ;
else if ( F_51 ( V_4 ) -> V_85 <= 4 )
V_84 = true ;
F_52 (dev_priv, pipe) {
V_82 = V_4 -> V_86 [ V_65 ] ;
if ( F_53 ( V_82 ) &&
F_8 ( V_82 ) -> V_87 ) {
if ( V_84 && V_14 ) {
if ( F_48 ( V_4 , V_88 ) )
F_5 ( L_7 ) ;
return NULL ;
}
V_14 = V_82 ;
}
if ( V_83 )
break;
}
if ( ! V_14 || V_14 -> V_17 -> V_16 == NULL ) {
if ( F_48 ( V_4 , V_89 ) )
F_5 ( L_8 ) ;
return NULL ;
}
return V_14 ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = NULL ;
struct V_20 * V_20 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
const struct V_90 * V_91 ;
unsigned int V_92 , V_93 ;
if ( ! F_55 ( V_2 ) )
return;
if ( F_56 ( V_2 ) )
V_94 . V_74 = 0 ;
if ( V_94 . V_74 < 0 ) {
if ( F_48 ( V_4 , V_95 ) )
F_5 ( L_9 ) ;
goto V_96;
}
if ( ! V_94 . V_74 ) {
if ( F_48 ( V_4 , V_97 ) )
F_5 ( L_10 ) ;
goto V_96;
}
V_14 = F_49 ( V_4 ) ;
if ( ! V_14 )
goto V_96;
V_20 = F_8 ( V_14 ) ;
V_16 = V_14 -> V_17 -> V_16 ;
V_19 = F_7 ( V_16 ) ;
V_91 = & V_20 -> V_98 -> V_76 . V_91 ;
if ( ( V_91 -> V_99 & V_100 ) ||
( V_91 -> V_99 & V_101 ) ) {
if ( F_48 ( V_4 , V_102 ) )
F_5 ( L_11
L_12 ) ;
goto V_96;
}
if ( F_51 ( V_2 ) -> V_85 >= 8 || F_50 ( V_2 ) ) {
V_92 = 4096 ;
V_93 = 4096 ;
} else if ( F_57 ( V_2 ) || F_51 ( V_2 ) -> V_85 >= 5 ) {
V_92 = 4096 ;
V_93 = 2048 ;
} else {
V_92 = 2048 ;
V_93 = 1536 ;
}
if ( V_20 -> V_98 -> V_103 > V_92 ||
V_20 -> V_98 -> V_104 > V_93 ) {
if ( F_48 ( V_4 , V_105 ) )
F_5 ( L_13 ) ;
goto V_96;
}
if ( ( F_51 ( V_2 ) -> V_85 < 4 || F_58 ( V_2 ) ) &&
V_20 -> V_31 != V_106 ) {
if ( F_48 ( V_4 , V_107 ) )
F_5 ( L_14 ) ;
goto V_96;
}
if ( V_19 -> V_108 != V_109 ||
V_19 -> V_39 == V_110 ) {
if ( F_48 ( V_4 , V_111 ) )
F_5 ( L_15 ) ;
goto V_96;
}
if ( F_51 ( V_2 ) -> V_85 <= 4 && ! F_57 ( V_2 ) &&
V_14 -> V_17 -> V_112 -> V_113 != F_59 ( V_114 ) ) {
if ( F_48 ( V_4 , V_102 ) )
F_5 ( L_16 ) ;
goto V_96;
}
if ( F_60 () )
goto V_96;
if ( F_61 ( V_2 , V_19 -> V_76 . V_115 ,
F_17 ( V_16 -> V_42 , 0 ) ) ) {
if ( F_48 ( V_4 , V_116 ) )
F_5 ( L_17 ) ;
goto V_96;
}
if ( V_4 -> V_7 . V_14 == V_20 &&
V_4 -> V_7 . V_75 == V_16 -> V_76 . V_77 &&
V_4 -> V_7 . V_34 == V_14 -> V_34 )
return;
if ( F_32 ( V_2 ) ) {
F_5 ( L_18 ) ;
F_47 ( V_2 ) ;
}
F_41 ( V_14 ) ;
V_4 -> V_7 . V_80 = V_117 ;
return;
V_96:
if ( F_32 ( V_2 ) ) {
F_5 ( L_19 ) ;
F_47 ( V_2 ) ;
}
F_62 ( V_2 ) ;
}
void F_63 ( struct V_3 * V_4 ,
unsigned int V_118 ,
enum V_119 V_120 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_121 ;
if ( V_120 == V_122 )
return;
if ( V_4 -> V_7 . V_8 )
V_121 = F_64 ( V_4 -> V_7 . V_14 -> V_65 ) ;
else if ( V_4 -> V_7 . V_72 )
V_121 = F_64 (
F_8 ( V_4 -> V_7 . V_72 -> V_14 ) -> V_65 ) ;
else
V_121 = V_4 -> V_7 . V_123 ;
V_4 -> V_7 . V_124 |= ( V_121 & V_118 ) ;
if ( V_4 -> V_7 . V_124 )
F_47 ( V_2 ) ;
}
void F_65 ( struct V_3 * V_4 ,
unsigned int V_118 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_4 -> V_7 . V_124 )
return;
V_4 -> V_7 . V_124 &= ~ V_118 ;
if ( ! V_4 -> V_7 . V_124 )
F_54 ( V_2 ) ;
}
void F_66 ( struct V_3 * V_4 )
{
enum V_65 V_65 ;
if ( ! F_55 ( V_4 ) ) {
V_4 -> V_7 . V_8 = false ;
V_4 -> V_7 . V_80 = V_125 ;
return;
}
F_52 (dev_priv, pipe) {
V_4 -> V_7 . V_123 |=
F_64 ( V_65 ) ;
if ( F_50 ( V_4 ) || F_51 ( V_4 ) -> V_85 >= 8 )
break;
}
if ( F_51 ( V_4 ) -> V_85 >= 7 ) {
V_4 -> V_73 . V_126 = F_27 ;
V_4 -> V_73 . V_74 = F_28 ;
V_4 -> V_73 . V_79 = F_26 ;
} else if ( F_51 ( V_4 ) -> V_85 >= 5 ) {
V_4 -> V_73 . V_126 = F_27 ;
V_4 -> V_73 . V_74 = F_22 ;
V_4 -> V_73 . V_79 = F_26 ;
} else if ( F_67 ( V_4 ) ) {
V_4 -> V_73 . V_126 = F_19 ;
V_4 -> V_73 . V_74 = F_15 ;
V_4 -> V_73 . V_79 = F_18 ;
} else {
V_4 -> V_73 . V_126 = F_14 ;
V_4 -> V_73 . V_74 = F_6 ;
V_4 -> V_73 . V_79 = F_1 ;
F_3 ( V_9 , 500 << V_35 ) ;
}
V_4 -> V_7 . V_8 = V_4 -> V_73 . V_126 ( V_4 -> V_2 ) ;
}
