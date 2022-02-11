static T_1 F_1 ( const struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_2 -> V_5 == V_4 [ V_3 ] . clock )
break;
}
if ( V_3 == F_2 ( V_4 ) ) {
F_3 ( L_1 ,
V_2 -> V_5 ) ;
V_3 = 1 ;
}
F_3 ( L_2 ,
V_4 [ V_3 ] . clock ,
V_4 [ V_3 ] . V_6 ) ;
return V_4 [ V_3 ] . V_6 ;
}
static int F_4 ( const struct V_1 * V_7 , int V_8 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_9 ) ; V_3 ++ ) {
if ( ( V_8 == V_9 [ V_3 ] . V_10 ) &&
( V_7 -> clock == V_9 [ V_3 ] . clock ) ) {
return V_9 [ V_3 ] . V_11 ;
}
}
return 0 ;
}
static T_2 F_5 ( int V_11 , T_2 V_12 )
{
int V_13 , V_14 ;
T_2 V_15 = V_12 ;
V_13 = V_11 & 0xfff ;
V_14 = ( V_11 >> 12 ) & 0xff ;
V_15 &= ~ ( V_16 | V_17 ) ;
V_15 |= ( ( V_14 << V_18 ) |
( V_13 << V_19 ) |
V_20 ) ;
return V_15 ;
}
static bool F_6 ( struct V_21 * V_22 ,
const struct V_1 * V_7 )
{
if ( ( ( V_7 -> clock == V_23 ) ||
( V_7 -> clock == V_24 ) ) &&
F_7 ( V_22 , V_25 ) )
return true ;
else
return false ;
}
static bool F_8 ( struct V_26 * V_27 ,
int V_28 , T_2 V_29 ,
int V_30 , T_2 V_31 ,
int V_32 )
{
struct V_33 * V_34 = V_27 -> V_35 -> V_36 ;
T_3 * V_37 = V_27 -> V_37 ;
T_2 V_15 ;
int V_3 ;
V_15 = F_9 ( V_28 ) ;
V_15 &= V_29 ;
if ( ! V_15 )
return false ;
V_15 = F_9 ( V_30 ) ;
V_15 &= ~ V_31 ;
F_10 ( V_30 , V_15 ) ;
for ( V_3 = 0 ; V_3 < F_11 ( V_37 ) / 4 ; V_3 ++ )
if ( F_9 ( V_32 ) != * ( ( T_2 * ) V_37 + V_3 ) )
return false ;
return true ;
}
static void F_12 ( struct V_38 * V_39 )
{
struct V_33 * V_34 = V_39 -> V_40 . V_35 -> V_36 ;
T_2 V_41 , V_15 ;
F_3 ( L_3 ) ;
V_15 = F_9 ( V_42 ) ;
if ( V_15 == V_43 || V_15 == V_44 )
V_41 = V_45 ;
else
V_41 = V_46 ;
V_15 = F_9 ( V_47 ) ;
V_15 &= ~ V_41 ;
F_10 ( V_47 , V_15 ) ;
}
static void F_13 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 = V_27 -> V_35 -> V_36 ;
T_3 * V_37 = V_27 -> V_37 ;
T_2 V_41 ;
T_2 V_15 ;
int V_48 , V_3 ;
F_3 ( L_4 , V_37 [ 2 ] ) ;
V_15 = F_9 ( V_42 ) ;
if ( V_15 == V_43 || V_15 == V_44 )
V_41 = V_45 ;
else
V_41 = V_46 ;
if ( F_8 ( V_27 ,
V_47 , V_41 ,
V_47 , V_49 ,
V_50 ) )
return;
V_15 = F_9 ( V_47 ) ;
V_15 &= ~ ( V_41 | V_49 ) ;
V_48 = ( V_15 >> 9 ) & 0x1f ;
F_10 ( V_47 , V_15 ) ;
V_48 = F_14 ( F_11 ( V_37 ) / 4 , V_48 ) ;
F_15 ( L_5 , V_48 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
F_10 ( V_50 , * ( ( T_2 * ) V_37 + V_3 ) ) ;
V_15 = F_9 ( V_47 ) ;
V_15 |= V_41 ;
F_10 ( V_47 , V_15 ) ;
}
static void F_16 ( struct V_38 * V_39 )
{
struct V_33 * V_34 = V_39 -> V_40 . V_35 -> V_36 ;
struct V_21 * V_21 = F_17 ( V_39 -> V_40 . V_22 ) ;
enum V_51 V_51 = V_21 -> V_51 ;
T_2 V_15 ;
F_3 ( L_6 , F_18 ( V_51 ) ) ;
F_19 ( & V_34 -> V_52 ) ;
V_15 = F_9 ( F_20 ( V_51 ) ) ;
V_15 &= ~ V_53 ;
V_15 |= V_20 ;
V_15 &= ~ V_16 ;
V_15 &= ~ V_17 ;
if ( F_7 ( V_21 , V_54 ) )
V_15 |= V_53 ;
F_10 ( F_20 ( V_51 ) , V_15 ) ;
V_15 = F_9 ( V_55 ) ;
V_15 &= ~ F_21 ( V_51 ) ;
V_15 &= ~ F_22 ( V_51 ) ;
F_10 ( V_55 , V_15 ) ;
F_23 ( & V_34 -> V_52 ) ;
}
static void F_24 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 = V_27 -> V_35 -> V_36 ;
struct V_21 * V_21 = F_17 ( V_39 -> V_40 . V_22 ) ;
enum V_51 V_51 = V_21 -> V_51 ;
struct V_56 * V_57 = V_34 -> V_58 ;
const T_3 * V_37 = V_27 -> V_37 ;
struct V_59 * V_60 =
F_25 ( & V_39 -> V_40 ) ;
enum V_61 V_61 = V_60 -> V_61 ;
T_2 V_15 ;
int V_48 , V_3 ;
int V_11 , V_8 ;
F_3 ( L_7 ,
F_18 ( V_51 ) , F_11 ( V_37 ) ) ;
F_19 ( & V_34 -> V_52 ) ;
V_15 = F_9 ( V_55 ) ;
V_15 |= F_22 ( V_51 ) ;
V_15 &= ~ F_21 ( V_51 ) ;
F_10 ( V_55 , V_15 ) ;
V_15 = F_9 ( F_26 ( V_51 ) ) ;
V_15 &= ~ V_62 ;
F_10 ( F_26 ( V_51 ) , V_15 ) ;
V_48 = F_14 ( F_11 ( V_37 ) , 84 ) ;
for ( V_3 = 0 ; V_3 < V_48 / 4 ; V_3 ++ )
F_10 ( F_27 ( V_51 ) , * ( ( T_2 * ) V_37 + V_3 ) ) ;
V_15 = F_9 ( V_55 ) ;
V_15 |= F_21 ( V_51 ) ;
F_10 ( V_55 , V_15 ) ;
V_15 = F_9 ( F_20 ( V_51 ) ) ;
V_15 &= ~ V_53 ;
V_15 &= ~ V_63 ;
if ( F_7 ( V_21 , V_54 ) )
V_15 |= V_53 ;
else
V_15 |= F_1 ( V_2 ) ;
V_15 &= ~ V_20 ;
if ( F_6 ( V_21 , V_2 ) ) {
if ( ! V_57 )
V_8 = 0 ;
else if ( V_61 >= V_64 && V_61 <= V_65 )
V_8 = V_57 -> V_66 [ V_61 ] ;
else {
F_28 ( L_8 , V_61 ) ;
V_8 = 0 ;
}
V_11 = F_4 ( V_2 , V_8 ) ;
if ( V_11 != 0 )
V_15 = F_5 ( V_11 , V_15 ) ;
else
F_3 ( L_9 ) ;
}
F_10 ( F_20 ( V_51 ) , V_15 ) ;
F_23 ( & V_34 -> V_52 ) ;
}
static void F_29 ( struct V_38 * V_39 )
{
struct V_33 * V_34 = V_39 -> V_40 . V_35 -> V_36 ;
struct V_21 * V_21 = F_17 ( V_39 -> V_40 . V_22 ) ;
struct V_59 * V_60 =
F_25 ( & V_39 -> V_40 ) ;
enum V_61 V_61 = V_60 -> V_61 ;
enum V_51 V_51 = V_21 -> V_51 ;
T_2 V_15 , V_41 ;
int V_67 ;
int V_68 ;
F_3 ( L_10 ,
F_30 ( V_61 ) , F_18 ( V_51 ) ) ;
if ( F_31 ( V_61 == V_64 ) )
return;
if ( F_32 ( V_34 -> V_35 ) ) {
V_67 = F_33 ( V_51 ) ;
V_68 = V_69 ;
} else if ( F_34 ( V_34 ) ) {
V_67 = F_35 ( V_51 ) ;
V_68 = V_70 ;
} else {
V_67 = F_36 ( V_51 ) ;
V_68 = V_71 ;
}
V_15 = F_9 ( V_67 ) ;
V_15 &= ~ V_53 ;
V_15 |= V_20 ;
V_15 &= ~ V_16 ;
V_15 &= ~ V_17 ;
if ( F_7 ( V_21 , V_54 ) )
V_15 |= V_53 ;
F_10 ( V_67 , V_15 ) ;
V_41 = F_37 ( V_61 ) ;
V_15 = F_9 ( V_68 ) ;
V_15 &= ~ V_41 ;
F_10 ( V_68 , V_15 ) ;
}
static void F_38 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 = V_27 -> V_35 -> V_36 ;
struct V_21 * V_21 = F_17 ( V_39 -> V_40 . V_22 ) ;
struct V_59 * V_60 =
F_25 ( & V_39 -> V_40 ) ;
enum V_61 V_61 = V_60 -> V_61 ;
enum V_51 V_51 = V_21 -> V_51 ;
T_3 * V_37 = V_27 -> V_37 ;
T_2 V_41 ;
T_2 V_15 ;
int V_48 , V_3 ;
int V_72 ;
int V_67 ;
int V_73 ;
int V_68 ;
F_3 ( L_11 ,
F_30 ( V_61 ) , F_18 ( V_51 ) , F_11 ( V_37 ) ) ;
if ( F_31 ( V_61 == V_64 ) )
return;
if ( F_32 ( V_27 -> V_35 ) ) {
V_72 = F_39 ( V_51 ) ;
V_67 = F_33 ( V_51 ) ;
V_73 = F_40 ( V_51 ) ;
V_68 = V_69 ;
} else if ( F_34 ( V_27 -> V_35 ) ) {
V_72 = F_41 ( V_51 ) ;
V_67 = F_35 ( V_51 ) ;
V_73 = F_42 ( V_51 ) ;
V_68 = V_70 ;
} else {
V_72 = F_43 ( V_51 ) ;
V_67 = F_36 ( V_51 ) ;
V_73 = F_44 ( V_51 ) ;
V_68 = V_71 ;
}
V_41 = F_37 ( V_61 ) ;
V_15 = F_9 ( V_68 ) ;
V_15 &= ~ V_41 ;
F_10 ( V_68 , V_15 ) ;
V_15 = F_9 ( V_73 ) ;
V_15 &= ~ V_62 ;
F_10 ( V_73 , V_15 ) ;
V_48 = F_14 ( F_11 ( V_37 ) , 84 ) ;
for ( V_3 = 0 ; V_3 < V_48 / 4 ; V_3 ++ )
F_10 ( V_72 , * ( ( T_2 * ) V_37 + V_3 ) ) ;
V_15 = F_9 ( V_68 ) ;
V_15 |= V_41 ;
F_10 ( V_68 , V_15 ) ;
V_15 = F_9 ( V_67 ) ;
V_15 &= ~ V_53 ;
V_15 &= ~ V_20 ;
V_15 &= ~ V_63 ;
if ( F_7 ( V_21 , V_54 ) )
V_15 |= V_53 ;
else
V_15 |= F_1 ( V_2 ) ;
F_10 ( V_67 , V_15 ) ;
}
void F_45 ( struct V_38 * V_38 )
{
struct V_74 * V_39 = & V_38 -> V_40 ;
struct V_21 * V_22 = F_17 ( V_39 -> V_22 ) ;
const struct V_1 * V_2 = & V_22 -> V_6 -> V_40 . V_2 ;
struct V_26 * V_27 ;
struct V_75 * V_35 = V_39 -> V_35 ;
struct V_33 * V_34 = V_35 -> V_36 ;
struct V_56 * V_57 = V_34 -> V_58 ;
struct V_59 * V_60 = F_25 ( V_39 ) ;
enum V_61 V_61 = V_60 -> V_61 ;
V_27 = F_46 ( V_39 ) ;
if ( ! V_27 )
return;
F_15 ( L_12 ,
V_27 -> V_40 . V_76 ,
V_27 -> V_77 ,
V_27 -> V_39 -> V_40 . V_76 ,
V_27 -> V_39 -> V_77 ) ;
V_27 -> V_37 [ 5 ] &= ~ ( 3 << 2 ) ;
if ( F_7 ( V_22 , V_54 ) )
V_27 -> V_37 [ 5 ] |= ( 1 << 2 ) ;
V_27 -> V_37 [ 6 ] = F_47 ( V_27 , V_2 ) / 2 ;
if ( V_34 -> V_78 . V_79 )
V_34 -> V_78 . V_79 ( V_27 , V_38 ,
V_2 ) ;
if ( V_57 && V_57 -> V_80 && V_57 -> V_80 -> V_81 )
V_57 -> V_80 -> V_81 ( V_57 -> V_80 -> V_82 , ( int ) V_61 ) ;
}
void F_48 ( struct V_38 * V_38 )
{
struct V_74 * V_39 = & V_38 -> V_40 ;
struct V_75 * V_35 = V_39 -> V_35 ;
struct V_33 * V_34 = V_35 -> V_36 ;
struct V_56 * V_57 = V_34 -> V_58 ;
struct V_59 * V_60 = F_25 ( V_39 ) ;
enum V_61 V_61 = V_60 -> V_61 ;
if ( V_34 -> V_78 . V_83 )
V_34 -> V_78 . V_83 ( V_38 ) ;
if ( V_57 && V_57 -> V_80 && V_57 -> V_80 -> V_81 )
V_57 -> V_80 -> V_81 ( V_57 -> V_80 -> V_82 , ( int ) V_61 ) ;
}
void F_49 ( struct V_75 * V_35 )
{
struct V_33 * V_34 = V_35 -> V_36 ;
if ( F_50 ( V_35 ) ) {
V_34 -> V_78 . V_79 = F_13 ;
V_34 -> V_78 . V_83 = F_12 ;
} else if ( F_34 ( V_35 ) ) {
V_34 -> V_78 . V_79 = F_38 ;
V_34 -> V_78 . V_83 = F_29 ;
} else if ( F_51 ( V_35 ) || F_52 ( V_35 ) -> V_84 >= 8 ) {
V_34 -> V_78 . V_79 = F_24 ;
V_34 -> V_78 . V_83 = F_16 ;
} else if ( F_53 ( V_35 ) ) {
V_34 -> V_78 . V_79 = F_38 ;
V_34 -> V_78 . V_83 = F_29 ;
}
}
static void F_54 ( struct V_85 * V_35 )
{
F_55 ( F_56 ( V_35 ) , V_86 ) ;
}
static void F_57 ( struct V_85 * V_35 )
{
F_58 ( F_56 ( V_35 ) , V_86 ) ;
}
static void F_59 ( struct V_85 * V_35 ,
bool V_87 )
{
struct V_33 * V_34 = F_56 ( V_35 ) ;
T_1 V_15 ;
if ( ! F_60 ( V_34 ) )
return;
V_15 = F_9 ( V_88 ) ;
V_15 &= ~ V_89 ;
F_10 ( V_88 , V_15 ) ;
F_61 ( 1000 , 1500 ) ;
if ( V_87 ) {
V_15 = F_9 ( V_88 ) ;
V_15 |= V_89 ;
F_10 ( V_88 , V_15 ) ;
F_61 ( 1000 , 1500 ) ;
}
}
static int F_62 ( struct V_85 * V_35 )
{
struct V_33 * V_34 = F_56 ( V_35 ) ;
int V_90 ;
if ( F_63 ( ! F_64 ( V_34 ) ) )
return - V_91 ;
F_55 ( V_34 , V_86 ) ;
V_90 = V_34 -> V_78 . V_92 ( V_34 -> V_35 ) ;
F_58 ( V_34 , V_86 ) ;
return V_90 ;
}
static int F_65 ( struct V_85 * V_35 ,
int V_61 , int V_8 )
{
struct V_33 * V_34 = F_56 ( V_35 ) ;
struct V_75 * V_93 = V_34 -> V_35 ;
struct V_38 * V_38 ;
struct V_59 * V_60 ;
struct V_21 * V_22 ;
struct V_1 * V_7 ;
struct V_56 * V_57 = V_34 -> V_58 ;
enum V_51 V_51 = - 1 ;
T_1 V_15 ;
int V_11 ;
if ( ! F_60 ( V_34 ) &&
! F_66 ( V_34 ) &&
! F_51 ( V_34 ) )
return 0 ;
F_19 ( & V_34 -> V_52 ) ;
F_67 (drm_dev, intel_encoder) {
if ( V_38 -> type != V_25 )
continue;
V_60 = F_25 ( & V_38 -> V_40 ) ;
if ( V_61 == V_60 -> V_61 ) {
V_22 = F_17 ( V_38 -> V_40 . V_22 ) ;
if ( ! V_22 ) {
F_3 ( L_13 , V_94 ) ;
continue;
}
V_51 = V_22 -> V_51 ;
break;
}
}
if ( V_51 == V_95 ) {
F_3 ( L_14 , F_30 ( V_61 ) ) ;
F_23 ( & V_34 -> V_52 ) ;
return - V_91 ;
}
F_3 ( L_15 ,
F_18 ( V_51 ) , F_30 ( V_61 ) ) ;
V_7 = & V_22 -> V_6 -> V_40 . V_2 ;
V_57 -> V_66 [ V_61 ] = V_8 ;
if ( ! F_6 ( V_22 , V_7 ) ) {
V_15 = F_9 ( F_20 ( V_51 ) ) ;
V_15 &= ~ V_20 ;
F_10 ( F_20 ( V_51 ) , V_15 ) ;
F_23 ( & V_34 -> V_52 ) ;
return 0 ;
}
V_11 = F_4 ( V_7 , V_8 ) ;
if ( V_11 == 0 ) {
F_3 ( L_16 ,
F_30 ( V_61 ) ) ;
V_15 = F_9 ( F_20 ( V_51 ) ) ;
V_15 &= ~ V_20 ;
F_10 ( F_20 ( V_51 ) , V_15 ) ;
F_23 ( & V_34 -> V_52 ) ;
return 0 ;
}
V_15 = F_9 ( F_20 ( V_51 ) ) ;
V_15 = F_5 ( V_11 , V_15 ) ;
F_10 ( F_20 ( V_51 ) , V_15 ) ;
F_23 ( & V_34 -> V_52 ) ;
return 0 ;
}
static int F_68 ( struct V_85 * V_96 ,
struct V_85 * V_97 , void * V_98 )
{
struct V_56 * V_57 = V_98 ;
struct V_33 * V_34 = F_56 ( V_96 ) ;
int V_3 ;
if ( F_31 ( V_57 -> V_99 || V_57 -> V_35 ) )
return - V_100 ;
F_69 ( V_34 -> V_35 ) ;
V_57 -> V_99 = & V_101 ;
V_57 -> V_35 = V_96 ;
F_70 ( V_102 != V_103 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_57 -> V_66 ) ; V_3 ++ )
V_57 -> V_66 [ V_3 ] = 0 ;
V_34 -> V_58 = V_57 ;
F_71 ( V_34 -> V_35 ) ;
return 0 ;
}
static void F_72 ( struct V_85 * V_96 ,
struct V_85 * V_97 , void * V_98 )
{
struct V_56 * V_57 = V_98 ;
struct V_33 * V_34 = F_56 ( V_96 ) ;
F_69 ( V_34 -> V_35 ) ;
V_57 -> V_99 = NULL ;
V_57 -> V_35 = NULL ;
V_34 -> V_58 = NULL ;
F_71 ( V_34 -> V_35 ) ;
}
void F_73 ( struct V_33 * V_34 )
{
int V_90 ;
V_90 = F_74 ( V_34 -> V_35 -> V_35 , & V_104 ) ;
if ( V_90 < 0 ) {
F_28 ( L_17 , V_90 ) ;
return;
}
V_34 -> V_105 = true ;
}
void F_75 ( struct V_33 * V_34 )
{
if ( ! V_34 -> V_105 )
return;
F_76 ( V_34 -> V_35 -> V_35 , & V_104 ) ;
V_34 -> V_105 = false ;
}
