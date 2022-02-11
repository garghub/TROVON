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
F_7 ( V_22 -> V_6 , V_25 ) )
return true ;
else
return false ;
}
static bool F_8 ( struct V_26 * V_27 ,
T_3 V_28 , T_2 V_29 ,
T_3 V_30 , T_2 V_31 ,
T_3 V_32 )
{
struct V_33 * V_34 = F_9 ( V_27 -> V_35 ) ;
T_4 * V_36 = V_27 -> V_36 ;
T_2 V_15 ;
int V_3 ;
V_15 = F_10 ( V_28 ) ;
V_15 &= V_29 ;
if ( ! V_15 )
return false ;
V_15 = F_10 ( V_30 ) ;
V_15 &= ~ V_31 ;
F_11 ( V_30 , V_15 ) ;
for ( V_3 = 0 ; V_3 < F_12 ( V_36 ) / 4 ; V_3 ++ )
if ( F_10 ( V_32 ) != * ( ( T_2 * ) V_36 + V_3 ) )
return false ;
return true ;
}
static void F_13 ( struct V_37 * V_38 )
{
struct V_33 * V_34 = F_9 ( V_38 -> V_39 . V_35 ) ;
T_2 V_40 , V_15 ;
F_3 ( L_3 ) ;
V_15 = F_10 ( V_41 ) ;
if ( V_15 == V_42 || V_15 == V_43 )
V_40 = V_44 ;
else
V_40 = V_45 ;
V_15 = F_10 ( V_46 ) ;
V_15 &= ~ V_40 ;
F_11 ( V_46 , V_15 ) ;
}
static void F_14 ( struct V_26 * V_27 ,
struct V_37 * V_38 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 = F_9 ( V_27 -> V_35 ) ;
T_4 * V_36 = V_27 -> V_36 ;
T_2 V_40 ;
T_2 V_15 ;
int V_47 , V_3 ;
F_3 ( L_4 , V_36 [ 2 ] ) ;
V_15 = F_10 ( V_41 ) ;
if ( V_15 == V_42 || V_15 == V_43 )
V_40 = V_44 ;
else
V_40 = V_45 ;
if ( F_8 ( V_27 ,
V_46 , V_40 ,
V_46 , V_48 ,
V_49 ) )
return;
V_15 = F_10 ( V_46 ) ;
V_15 &= ~ ( V_40 | V_48 ) ;
V_47 = ( V_15 >> 9 ) & 0x1f ;
F_11 ( V_46 , V_15 ) ;
V_47 = F_15 ( F_12 ( V_36 ) / 4 , V_47 ) ;
F_16 ( L_5 , V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ )
F_11 ( V_49 , * ( ( T_2 * ) V_36 + V_3 ) ) ;
V_15 = F_10 ( V_46 ) ;
V_15 |= V_40 ;
F_11 ( V_46 , V_15 ) ;
}
static void F_17 ( struct V_37 * V_38 )
{
struct V_33 * V_34 = F_9 ( V_38 -> V_39 . V_35 ) ;
struct V_21 * V_21 = F_18 ( V_38 -> V_39 . V_22 ) ;
enum V_50 V_50 = V_21 -> V_50 ;
T_2 V_15 ;
F_3 ( L_6 , F_19 ( V_50 ) ) ;
F_20 ( & V_34 -> V_51 ) ;
V_15 = F_10 ( F_21 ( V_50 ) ) ;
V_15 &= ~ V_52 ;
V_15 |= V_20 ;
V_15 &= ~ V_16 ;
V_15 &= ~ V_17 ;
if ( F_22 ( V_21 -> V_6 ) )
V_15 |= V_52 ;
F_11 ( F_21 ( V_50 ) , V_15 ) ;
V_15 = F_10 ( V_53 ) ;
V_15 &= ~ F_23 ( V_50 ) ;
V_15 &= ~ F_24 ( V_50 ) ;
F_11 ( V_53 , V_15 ) ;
F_25 ( & V_34 -> V_51 ) ;
}
static void F_26 ( struct V_26 * V_27 ,
struct V_37 * V_38 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 = F_9 ( V_27 -> V_35 ) ;
struct V_21 * V_21 = F_18 ( V_38 -> V_39 . V_22 ) ;
enum V_50 V_50 = V_21 -> V_50 ;
struct V_54 * V_55 = V_34 -> V_56 ;
const T_4 * V_36 = V_27 -> V_36 ;
struct V_57 * V_58 =
F_27 ( & V_38 -> V_39 ) ;
enum V_59 V_59 = V_58 -> V_59 ;
T_2 V_15 ;
int V_47 , V_3 ;
int V_11 , V_8 ;
F_3 ( L_7 ,
F_19 ( V_50 ) , F_12 ( V_36 ) ) ;
F_20 ( & V_34 -> V_51 ) ;
V_15 = F_10 ( V_53 ) ;
V_15 |= F_24 ( V_50 ) ;
V_15 &= ~ F_23 ( V_50 ) ;
F_11 ( V_53 , V_15 ) ;
V_15 = F_10 ( F_28 ( V_50 ) ) ;
V_15 &= ~ V_60 ;
F_11 ( F_28 ( V_50 ) , V_15 ) ;
V_47 = F_15 ( F_12 ( V_36 ) , 84 ) ;
for ( V_3 = 0 ; V_3 < V_47 / 4 ; V_3 ++ )
F_11 ( F_29 ( V_50 ) , * ( ( T_2 * ) V_36 + V_3 ) ) ;
V_15 = F_10 ( V_53 ) ;
V_15 |= F_23 ( V_50 ) ;
F_11 ( V_53 , V_15 ) ;
V_15 = F_10 ( F_21 ( V_50 ) ) ;
V_15 &= ~ V_52 ;
V_15 &= ~ V_61 ;
if ( F_22 ( V_21 -> V_6 ) )
V_15 |= V_52 ;
else
V_15 |= F_1 ( V_2 ) ;
V_15 &= ~ V_20 ;
if ( F_6 ( V_21 , V_2 ) ) {
if ( ! V_55 )
V_8 = 0 ;
else if ( V_59 >= V_62 && V_59 <= V_63 )
V_8 = V_55 -> V_64 [ V_59 ] ;
else {
F_30 ( L_8 , V_59 ) ;
V_8 = 0 ;
}
V_11 = F_4 ( V_2 , V_8 ) ;
if ( V_11 != 0 )
V_15 = F_5 ( V_11 , V_15 ) ;
else
F_3 ( L_9 ) ;
}
F_11 ( F_21 ( V_50 ) , V_15 ) ;
F_25 ( & V_34 -> V_51 ) ;
}
static void F_31 ( struct V_37 * V_38 )
{
struct V_33 * V_34 = F_9 ( V_38 -> V_39 . V_35 ) ;
struct V_21 * V_21 = F_18 ( V_38 -> V_39 . V_22 ) ;
enum V_59 V_59 = F_27 ( & V_38 -> V_39 ) -> V_59 ;
enum V_50 V_50 = V_21 -> V_50 ;
T_2 V_15 , V_40 ;
T_3 V_65 , V_66 ;
F_3 ( L_10 ,
F_32 ( V_59 ) , F_19 ( V_50 ) ) ;
if ( F_33 ( V_59 == V_62 ) )
return;
if ( F_34 ( V_34 ) ) {
V_65 = F_35 ( V_50 ) ;
V_66 = V_67 ;
} else if ( F_36 ( V_34 ) || F_37 ( V_34 ) ) {
V_65 = F_38 ( V_50 ) ;
V_66 = V_68 ;
} else {
V_65 = F_39 ( V_50 ) ;
V_66 = V_69 ;
}
V_15 = F_10 ( V_65 ) ;
V_15 &= ~ V_52 ;
V_15 |= V_20 ;
V_15 &= ~ V_16 ;
V_15 &= ~ V_17 ;
if ( F_22 ( V_21 -> V_6 ) )
V_15 |= V_52 ;
F_11 ( V_65 , V_15 ) ;
V_40 = F_40 ( V_59 ) ;
V_15 = F_10 ( V_66 ) ;
V_15 &= ~ V_40 ;
F_11 ( V_66 , V_15 ) ;
}
static void F_41 ( struct V_26 * V_27 ,
struct V_37 * V_38 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 = F_9 ( V_27 -> V_35 ) ;
struct V_21 * V_21 = F_18 ( V_38 -> V_39 . V_22 ) ;
enum V_59 V_59 = F_27 ( & V_38 -> V_39 ) -> V_59 ;
enum V_50 V_50 = V_21 -> V_50 ;
T_4 * V_36 = V_27 -> V_36 ;
T_2 V_15 , V_40 ;
int V_47 , V_3 ;
T_3 V_70 , V_65 , V_71 , V_66 ;
F_3 ( L_11 ,
F_32 ( V_59 ) , F_19 ( V_50 ) , F_12 ( V_36 ) ) ;
if ( F_33 ( V_59 == V_62 ) )
return;
if ( F_34 ( V_27 -> V_35 ) ) {
V_70 = F_42 ( V_50 ) ;
V_65 = F_35 ( V_50 ) ;
V_71 = F_43 ( V_50 ) ;
V_66 = V_67 ;
} else if ( F_36 ( V_27 -> V_35 ) ||
F_37 ( V_27 -> V_35 ) ) {
V_70 = F_44 ( V_50 ) ;
V_65 = F_38 ( V_50 ) ;
V_71 = F_45 ( V_50 ) ;
V_66 = V_68 ;
} else {
V_70 = F_46 ( V_50 ) ;
V_65 = F_39 ( V_50 ) ;
V_71 = F_47 ( V_50 ) ;
V_66 = V_69 ;
}
V_40 = F_40 ( V_59 ) ;
V_15 = F_10 ( V_66 ) ;
V_15 &= ~ V_40 ;
F_11 ( V_66 , V_15 ) ;
V_15 = F_10 ( V_71 ) ;
V_15 &= ~ V_60 ;
F_11 ( V_71 , V_15 ) ;
V_47 = F_15 ( F_12 ( V_36 ) , 84 ) ;
for ( V_3 = 0 ; V_3 < V_47 / 4 ; V_3 ++ )
F_11 ( V_70 , * ( ( T_2 * ) V_36 + V_3 ) ) ;
V_15 = F_10 ( V_66 ) ;
V_15 |= V_40 ;
F_11 ( V_66 , V_15 ) ;
V_15 = F_10 ( V_65 ) ;
V_15 &= ~ V_52 ;
V_15 &= ~ V_20 ;
V_15 &= ~ V_61 ;
if ( F_22 ( V_21 -> V_6 ) )
V_15 |= V_52 ;
else
V_15 |= F_1 ( V_2 ) ;
F_11 ( V_65 , V_15 ) ;
}
void F_48 ( struct V_37 * V_37 )
{
struct V_72 * V_38 = & V_37 -> V_39 ;
struct V_21 * V_22 = F_18 ( V_38 -> V_22 ) ;
const struct V_1 * V_2 = & V_22 -> V_6 -> V_39 . V_2 ;
struct V_26 * V_27 ;
struct V_73 * V_35 = V_38 -> V_35 ;
struct V_33 * V_34 = F_9 ( V_35 ) ;
struct V_54 * V_55 = V_34 -> V_56 ;
struct V_57 * V_58 = F_27 ( V_38 ) ;
enum V_59 V_59 = V_58 -> V_59 ;
V_27 = F_49 ( V_38 ) ;
if ( ! V_27 )
return;
F_16 ( L_12 ,
V_27 -> V_39 . V_74 ,
V_27 -> V_75 ,
V_27 -> V_38 -> V_39 . V_74 ,
V_27 -> V_38 -> V_75 ) ;
V_27 -> V_36 [ 5 ] &= ~ ( 3 << 2 ) ;
if ( F_22 ( V_22 -> V_6 ) )
V_27 -> V_36 [ 5 ] |= ( 1 << 2 ) ;
V_27 -> V_36 [ 6 ] = F_50 ( V_27 , V_2 ) / 2 ;
if ( V_34 -> V_76 . V_77 )
V_34 -> V_76 . V_77 ( V_27 , V_37 ,
V_2 ) ;
F_20 ( & V_34 -> V_51 ) ;
V_58 -> V_78 = V_27 ;
V_34 -> V_79 [ V_59 ] = V_37 ;
F_25 ( & V_34 -> V_51 ) ;
if ( V_55 && V_55 -> V_80 && V_55 -> V_80 -> V_81 )
V_55 -> V_80 -> V_81 ( V_55 -> V_80 -> V_82 , ( int ) V_59 ) ;
}
void F_51 ( struct V_37 * V_37 )
{
struct V_72 * V_38 = & V_37 -> V_39 ;
struct V_73 * V_35 = V_38 -> V_35 ;
struct V_33 * V_34 = F_9 ( V_35 ) ;
struct V_54 * V_55 = V_34 -> V_56 ;
struct V_57 * V_58 = F_27 ( V_38 ) ;
enum V_59 V_59 = V_58 -> V_59 ;
if ( V_34 -> V_76 . V_83 )
V_34 -> V_76 . V_83 ( V_37 ) ;
F_20 ( & V_34 -> V_51 ) ;
V_58 -> V_78 = NULL ;
V_34 -> V_79 [ V_59 ] = NULL ;
F_25 ( & V_34 -> V_51 ) ;
if ( V_55 && V_55 -> V_80 && V_55 -> V_80 -> V_81 )
V_55 -> V_80 -> V_81 ( V_55 -> V_80 -> V_82 , ( int ) V_59 ) ;
}
void F_52 ( struct V_33 * V_34 )
{
if ( F_53 ( V_34 ) ) {
V_34 -> V_76 . V_77 = F_14 ;
V_34 -> V_76 . V_83 = F_13 ;
} else if ( F_36 ( V_34 ) || F_37 ( V_34 ) ) {
V_34 -> V_76 . V_77 = F_41 ;
V_34 -> V_76 . V_83 = F_31 ;
} else if ( F_54 ( V_34 ) || F_55 ( V_34 ) -> V_84 >= 8 ) {
V_34 -> V_76 . V_77 = F_26 ;
V_34 -> V_76 . V_83 = F_17 ;
} else if ( F_56 ( V_34 ) ) {
V_34 -> V_76 . V_77 = F_41 ;
V_34 -> V_76 . V_83 = F_31 ;
}
}
static void F_57 ( struct V_85 * V_86 )
{
F_58 ( F_59 ( V_86 ) , V_87 ) ;
}
static void F_60 ( struct V_85 * V_86 )
{
F_61 ( F_59 ( V_86 ) , V_87 ) ;
}
static void F_62 ( struct V_85 * V_86 ,
bool V_88 )
{
struct V_33 * V_34 = F_59 ( V_86 ) ;
T_1 V_15 ;
if ( ! F_63 ( V_34 ) && ! F_64 ( V_34 ) )
return;
F_57 ( V_86 ) ;
V_15 = F_10 ( V_89 ) ;
V_15 &= ~ V_90 ;
F_11 ( V_89 , V_15 ) ;
F_65 ( 1000 , 1500 ) ;
if ( V_88 ) {
V_15 = F_10 ( V_89 ) ;
V_15 |= V_90 ;
F_11 ( V_89 , V_15 ) ;
F_65 ( 1000 , 1500 ) ;
}
F_60 ( V_86 ) ;
}
static int F_66 ( struct V_85 * V_86 )
{
struct V_33 * V_34 = F_59 ( V_86 ) ;
if ( F_67 ( ! F_68 ( V_34 ) ) )
return - V_91 ;
return V_34 -> V_92 ;
}
static int F_69 ( struct V_85 * V_86 ,
int V_59 , int V_8 )
{
struct V_33 * V_34 = F_59 ( V_86 ) ;
struct V_37 * V_37 ;
struct V_21 * V_22 ;
struct V_1 * V_7 ;
struct V_54 * V_55 = V_34 -> V_56 ;
enum V_50 V_50 = V_93 ;
T_1 V_15 ;
int V_11 ;
int V_94 = 0 ;
if ( ! F_63 ( V_34 ) &&
! F_64 ( V_34 ) &&
! F_70 ( V_34 ) &&
! F_54 ( V_34 ) )
return 0 ;
F_57 ( V_86 ) ;
F_20 ( & V_34 -> V_51 ) ;
V_37 = V_34 -> V_79 [ V_59 ] ;
if ( ! V_37 || ! V_37 -> V_39 . V_22 ||
V_37 -> type != V_25 ) {
F_3 ( L_13 , F_32 ( V_59 ) ) ;
V_94 = - V_91 ;
goto V_95;
}
V_22 = F_18 ( V_37 -> V_39 . V_22 ) ;
V_50 = V_22 -> V_50 ;
if ( V_50 == V_93 ) {
F_3 ( L_14 , F_32 ( V_59 ) ) ;
V_94 = - V_91 ;
goto V_95;
}
F_3 ( L_15 ,
F_19 ( V_50 ) , F_32 ( V_59 ) ) ;
V_7 = & V_22 -> V_6 -> V_39 . V_2 ;
V_55 -> V_64 [ V_59 ] = V_8 ;
if ( ! F_6 ( V_22 , V_7 ) ) {
V_15 = F_10 ( F_21 ( V_50 ) ) ;
V_15 &= ~ V_20 ;
F_11 ( F_21 ( V_50 ) , V_15 ) ;
goto V_95;
}
V_11 = F_4 ( V_7 , V_8 ) ;
if ( V_11 == 0 ) {
F_3 ( L_16 ,
F_32 ( V_59 ) ) ;
V_15 = F_10 ( F_21 ( V_50 ) ) ;
V_15 &= ~ V_20 ;
F_11 ( F_21 ( V_50 ) , V_15 ) ;
goto V_95;
}
V_15 = F_10 ( F_21 ( V_50 ) ) ;
V_15 = F_5 ( V_11 , V_15 ) ;
F_11 ( F_21 ( V_50 ) , V_15 ) ;
V_95:
F_25 ( & V_34 -> V_51 ) ;
F_60 ( V_86 ) ;
return V_94 ;
}
static int F_71 ( struct V_85 * V_86 , int V_59 ,
bool * V_96 ,
unsigned char * V_97 , int V_98 )
{
struct V_33 * V_34 = F_59 ( V_86 ) ;
struct V_37 * V_37 ;
struct V_57 * V_58 ;
const T_5 * V_36 ;
int V_99 = - V_100 ;
F_20 ( & V_34 -> V_51 ) ;
V_37 = V_34 -> V_79 [ V_59 ] ;
if ( V_37 ) {
V_99 = 0 ;
V_58 = F_27 ( & V_37 -> V_39 ) ;
* V_96 = V_58 -> V_78 != NULL ;
if ( * V_96 ) {
V_36 = V_58 -> V_78 -> V_36 ;
V_99 = F_12 ( V_36 ) ;
memcpy ( V_97 , V_36 , F_15 ( V_98 , V_99 ) ) ;
}
}
F_25 ( & V_34 -> V_51 ) ;
return V_99 ;
}
static int F_72 ( struct V_85 * V_101 ,
struct V_85 * V_102 , void * V_103 )
{
struct V_54 * V_55 = V_103 ;
struct V_33 * V_34 = F_59 ( V_101 ) ;
int V_3 ;
if ( F_33 ( V_55 -> V_104 || V_55 -> V_35 ) )
return - V_105 ;
F_73 ( & V_34 -> V_106 ) ;
V_55 -> V_104 = & V_107 ;
V_55 -> V_35 = V_101 ;
F_74 ( V_108 != V_109 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_55 -> V_64 ) ; V_3 ++ )
V_55 -> V_64 [ V_3 ] = 0 ;
V_34 -> V_56 = V_55 ;
F_75 ( & V_34 -> V_106 ) ;
return 0 ;
}
static void F_76 ( struct V_85 * V_101 ,
struct V_85 * V_102 , void * V_103 )
{
struct V_54 * V_55 = V_103 ;
struct V_33 * V_34 = F_59 ( V_101 ) ;
F_73 ( & V_34 -> V_106 ) ;
V_55 -> V_104 = NULL ;
V_55 -> V_35 = NULL ;
V_34 -> V_56 = NULL ;
F_75 ( & V_34 -> V_106 ) ;
}
void F_77 ( struct V_33 * V_34 )
{
int V_99 ;
V_99 = F_78 ( V_34 -> V_106 . V_35 , & V_110 ) ;
if ( V_99 < 0 ) {
F_30 ( L_17 , V_99 ) ;
return;
}
V_34 -> V_111 = true ;
}
void F_79 ( struct V_33 * V_34 )
{
if ( ! V_34 -> V_111 )
return;
F_80 ( V_34 -> V_106 . V_35 , & V_110 ) ;
V_34 -> V_111 = false ;
}
