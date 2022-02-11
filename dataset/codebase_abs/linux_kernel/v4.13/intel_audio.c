static const struct V_1 *
F_1 ( struct V_2 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_1 ) ; V_4 ++ ) {
if ( V_3 == V_1 [ V_4 ] . V_5 &&
V_2 -> V_6 -> V_7 == V_1 [ V_4 ] . clock )
return & V_1 [ V_4 ] ;
}
return NULL ;
}
static T_1 F_3 ( const struct V_8 * V_9 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_10 ) ; V_4 ++ ) {
if ( V_9 -> V_11 == V_10 [ V_4 ] . clock )
break;
}
if ( V_4 == F_2 ( V_10 ) ) {
F_4 ( L_1 ,
V_9 -> V_11 ) ;
V_4 = 1 ;
}
F_4 ( L_2 ,
V_10 [ V_4 ] . clock ,
V_10 [ V_4 ] . V_6 ) ;
return V_10 [ V_4 ] . V_6 ;
}
static int F_5 ( const struct V_8 * V_9 ,
int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_12 ) ; V_4 ++ ) {
if ( V_3 == V_12 [ V_4 ] . V_5 &&
V_9 -> V_11 == V_12 [ V_4 ] . clock ) {
return V_12 [ V_4 ] . V_13 ;
}
}
return 0 ;
}
static bool F_6 ( struct V_14 * V_15 ,
T_2 V_16 , T_3 V_17 ,
T_2 V_18 , T_3 V_19 ,
T_2 V_20 )
{
struct V_21 * V_22 = F_7 ( V_15 -> V_23 ) ;
T_4 * V_24 = V_15 -> V_24 ;
T_3 V_25 ;
int V_4 ;
V_25 = F_8 ( V_16 ) ;
V_25 &= V_17 ;
if ( ! V_25 )
return false ;
V_25 = F_8 ( V_18 ) ;
V_25 &= ~ V_19 ;
F_9 ( V_18 , V_25 ) ;
for ( V_4 = 0 ; V_4 < F_10 ( V_24 ) / 4 ; V_4 ++ )
if ( F_8 ( V_20 ) != * ( ( T_3 * ) V_24 + V_4 ) )
return false ;
return true ;
}
static void F_11 ( struct V_26 * V_27 )
{
struct V_21 * V_22 = F_7 ( V_27 -> V_28 . V_23 ) ;
T_3 V_29 , V_25 ;
F_4 ( L_3 ) ;
V_25 = F_8 ( V_30 ) ;
if ( V_25 == V_31 || V_25 == V_32 )
V_29 = V_33 ;
else
V_29 = V_34 ;
V_25 = F_8 ( V_35 ) ;
V_25 &= ~ V_29 ;
F_9 ( V_35 , V_25 ) ;
}
static void F_12 ( struct V_14 * V_15 ,
struct V_26 * V_27 ,
const struct V_8 * V_9 )
{
struct V_21 * V_22 = F_7 ( V_15 -> V_23 ) ;
T_4 * V_24 = V_15 -> V_24 ;
T_3 V_29 ;
T_3 V_25 ;
int V_36 , V_4 ;
F_4 ( L_4 , V_24 [ 2 ] ) ;
V_25 = F_8 ( V_30 ) ;
if ( V_25 == V_31 || V_25 == V_32 )
V_29 = V_33 ;
else
V_29 = V_34 ;
if ( F_6 ( V_15 ,
V_35 , V_29 ,
V_35 , V_37 ,
V_38 ) )
return;
V_25 = F_8 ( V_35 ) ;
V_25 &= ~ ( V_29 | V_37 ) ;
V_36 = ( V_25 >> 9 ) & 0x1f ;
F_9 ( V_35 , V_25 ) ;
V_36 = F_13 ( F_10 ( V_24 ) / 4 , V_36 ) ;
F_14 ( L_5 , V_36 ) ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ )
F_9 ( V_38 , * ( ( T_3 * ) V_24 + V_4 ) ) ;
V_25 = F_8 ( V_35 ) ;
V_25 |= V_29 ;
F_9 ( V_35 , V_25 ) ;
}
static void
F_15 ( struct V_2 * V_2 , enum V_39 V_39 ,
const struct V_8 * V_9 )
{
struct V_21 * V_22 = F_7 ( V_2 -> V_28 . V_23 ) ;
struct V_40 * V_41 = V_22 -> V_42 ;
int V_3 = V_41 ? V_41 -> V_43 [ V_39 ] : 0 ;
const struct V_1 * V_44 = F_1 ( V_2 , V_3 ) ;
enum V_45 V_45 = V_2 -> V_45 ;
T_1 V_25 ;
if ( V_44 )
F_4 ( L_6 , V_44 -> V_46 , V_44 -> V_13 ) ;
else
F_4 ( L_7 ) ;
V_25 = F_8 ( F_16 ( V_45 ) ) ;
V_25 &= ~ V_47 ;
V_25 &= ~ V_48 ;
V_25 &= ~ V_49 ;
V_25 |= V_47 ;
if ( V_44 ) {
V_25 &= ~ V_50 ;
V_25 |= F_17 ( V_44 -> V_13 ) ;
V_25 |= V_49 ;
}
F_9 ( F_16 ( V_45 ) , V_25 ) ;
V_25 = F_8 ( F_18 ( V_45 ) ) ;
V_25 &= ~ V_51 ;
V_25 &= ~ V_52 ;
V_25 &= ~ V_53 ;
if ( V_44 ) {
V_25 |= V_44 -> V_46 ;
V_25 |= V_52 ;
V_25 |= V_53 ;
}
F_9 ( F_18 ( V_45 ) , V_25 ) ;
}
static void
F_19 ( struct V_2 * V_2 , enum V_39 V_39 ,
const struct V_8 * V_9 )
{
struct V_21 * V_22 = F_7 ( V_2 -> V_28 . V_23 ) ;
struct V_40 * V_41 = V_22 -> V_42 ;
int V_3 = V_41 ? V_41 -> V_43 [ V_39 ] : 0 ;
enum V_45 V_45 = V_2 -> V_45 ;
int V_13 ;
T_1 V_25 ;
V_25 = F_8 ( F_16 ( V_45 ) ) ;
V_25 &= ~ V_47 ;
V_25 &= ~ V_48 ;
V_25 &= ~ V_49 ;
V_25 |= F_3 ( V_9 ) ;
V_13 = F_5 ( V_9 , V_3 ) ;
if ( V_13 != 0 ) {
F_4 ( L_8 , V_13 ) ;
V_25 &= ~ V_50 ;
V_25 |= F_17 ( V_13 ) ;
V_25 |= V_49 ;
} else {
F_4 ( L_9 ) ;
}
F_9 ( F_16 ( V_45 ) , V_25 ) ;
V_25 = F_8 ( F_18 ( V_45 ) ) ;
V_25 &= ~ V_53 ;
V_25 &= ~ V_52 ;
F_9 ( F_18 ( V_45 ) , V_25 ) ;
}
static void
F_20 ( struct V_2 * V_2 , enum V_39 V_39 ,
const struct V_8 * V_9 )
{
if ( F_21 ( V_2 -> V_6 ) )
F_15 ( V_2 , V_39 , V_9 ) ;
else
F_19 ( V_2 , V_39 , V_9 ) ;
}
static void F_22 ( struct V_26 * V_27 )
{
struct V_21 * V_22 = F_7 ( V_27 -> V_28 . V_23 ) ;
struct V_2 * V_2 = F_23 ( V_27 -> V_28 . V_54 ) ;
enum V_45 V_45 = V_2 -> V_45 ;
T_3 V_25 ;
F_4 ( L_10 , F_24 ( V_45 ) ) ;
F_25 ( & V_22 -> V_55 ) ;
V_25 = F_8 ( F_16 ( V_45 ) ) ;
V_25 &= ~ V_47 ;
V_25 |= V_49 ;
V_25 &= ~ V_56 ;
V_25 &= ~ V_57 ;
if ( F_21 ( V_2 -> V_6 ) )
V_25 |= V_47 ;
F_9 ( F_16 ( V_45 ) , V_25 ) ;
V_25 = F_8 ( V_58 ) ;
V_25 &= ~ F_26 ( V_45 ) ;
V_25 &= ~ F_27 ( V_45 ) ;
F_9 ( V_58 , V_25 ) ;
F_28 ( & V_22 -> V_55 ) ;
}
static void F_29 ( struct V_14 * V_15 ,
struct V_26 * V_26 ,
const struct V_8 * V_9 )
{
struct V_21 * V_22 = F_7 ( V_15 -> V_23 ) ;
struct V_2 * V_2 = F_23 ( V_26 -> V_28 . V_54 ) ;
enum V_45 V_45 = V_2 -> V_45 ;
enum V_39 V_39 = V_26 -> V_39 ;
const T_4 * V_24 = V_15 -> V_24 ;
T_3 V_25 ;
int V_36 , V_4 ;
F_4 ( L_11 ,
F_24 ( V_45 ) , F_10 ( V_24 ) ) ;
F_25 ( & V_22 -> V_55 ) ;
V_25 = F_8 ( V_58 ) ;
V_25 |= F_27 ( V_45 ) ;
V_25 &= ~ F_26 ( V_45 ) ;
F_9 ( V_58 , V_25 ) ;
V_25 = F_8 ( F_30 ( V_45 ) ) ;
V_25 &= ~ V_59 ;
F_9 ( F_30 ( V_45 ) , V_25 ) ;
V_36 = F_13 ( F_10 ( V_24 ) , 84 ) ;
for ( V_4 = 0 ; V_4 < V_36 / 4 ; V_4 ++ )
F_9 ( F_31 ( V_45 ) , * ( ( T_3 * ) V_24 + V_4 ) ) ;
V_25 = F_8 ( V_58 ) ;
V_25 |= F_26 ( V_45 ) ;
F_9 ( V_58 , V_25 ) ;
F_20 ( V_2 , V_39 , V_9 ) ;
F_28 ( & V_22 -> V_55 ) ;
}
static void F_32 ( struct V_26 * V_26 )
{
struct V_21 * V_22 = F_7 ( V_26 -> V_28 . V_23 ) ;
struct V_2 * V_2 = F_23 ( V_26 -> V_28 . V_54 ) ;
enum V_45 V_45 = V_2 -> V_45 ;
enum V_39 V_39 = V_26 -> V_39 ;
T_3 V_25 , V_29 ;
T_2 V_60 , V_61 ;
F_4 ( L_12 ,
F_33 ( V_39 ) , F_24 ( V_45 ) ) ;
if ( F_34 ( V_39 == V_62 ) )
return;
if ( F_35 ( V_22 ) ) {
V_60 = F_36 ( V_45 ) ;
V_61 = V_63 ;
} else if ( F_37 ( V_22 ) || F_38 ( V_22 ) ) {
V_60 = F_39 ( V_45 ) ;
V_61 = V_64 ;
} else {
V_60 = F_40 ( V_45 ) ;
V_61 = V_65 ;
}
V_25 = F_8 ( V_60 ) ;
V_25 &= ~ V_47 ;
V_25 |= V_49 ;
V_25 &= ~ V_56 ;
V_25 &= ~ V_57 ;
if ( F_21 ( V_2 -> V_6 ) )
V_25 |= V_47 ;
F_9 ( V_60 , V_25 ) ;
V_29 = F_41 ( V_39 ) ;
V_25 = F_8 ( V_61 ) ;
V_25 &= ~ V_29 ;
F_9 ( V_61 , V_25 ) ;
}
static void F_42 ( struct V_14 * V_15 ,
struct V_26 * V_26 ,
const struct V_8 * V_9 )
{
struct V_21 * V_22 = F_7 ( V_15 -> V_23 ) ;
struct V_2 * V_2 = F_23 ( V_26 -> V_28 . V_54 ) ;
enum V_45 V_45 = V_2 -> V_45 ;
enum V_39 V_39 = V_26 -> V_39 ;
T_4 * V_24 = V_15 -> V_24 ;
T_3 V_25 , V_29 ;
int V_36 , V_4 ;
T_2 V_66 , V_60 , V_67 , V_61 ;
F_4 ( L_13 ,
F_33 ( V_39 ) , F_24 ( V_45 ) , F_10 ( V_24 ) ) ;
if ( F_34 ( V_39 == V_62 ) )
return;
if ( F_35 ( V_22 ) ) {
V_66 = F_43 ( V_45 ) ;
V_60 = F_36 ( V_45 ) ;
V_67 = F_44 ( V_45 ) ;
V_61 = V_63 ;
} else if ( F_37 ( V_22 ) ||
F_38 ( V_22 ) ) {
V_66 = F_45 ( V_45 ) ;
V_60 = F_39 ( V_45 ) ;
V_67 = F_46 ( V_45 ) ;
V_61 = V_64 ;
} else {
V_66 = F_47 ( V_45 ) ;
V_60 = F_40 ( V_45 ) ;
V_67 = F_48 ( V_45 ) ;
V_61 = V_65 ;
}
V_29 = F_41 ( V_39 ) ;
V_25 = F_8 ( V_61 ) ;
V_25 &= ~ V_29 ;
F_9 ( V_61 , V_25 ) ;
V_25 = F_8 ( V_67 ) ;
V_25 &= ~ V_59 ;
F_9 ( V_67 , V_25 ) ;
V_36 = F_13 ( F_10 ( V_24 ) , 84 ) ;
for ( V_4 = 0 ; V_4 < V_36 / 4 ; V_4 ++ )
F_9 ( V_66 , * ( ( T_3 * ) V_24 + V_4 ) ) ;
V_25 = F_8 ( V_61 ) ;
V_25 |= V_29 ;
F_9 ( V_61 , V_25 ) ;
V_25 = F_8 ( V_60 ) ;
V_25 &= ~ V_47 ;
V_25 &= ~ V_49 ;
V_25 &= ~ V_48 ;
if ( F_21 ( V_2 -> V_6 ) )
V_25 |= V_47 ;
else
V_25 |= F_3 ( V_9 ) ;
F_9 ( V_60 , V_25 ) ;
}
void F_49 ( struct V_26 * V_26 ,
const struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_72 * V_27 = & V_26 -> V_28 ;
const struct V_8 * V_9 = & V_69 -> V_28 . V_9 ;
struct V_14 * V_15 ;
struct V_21 * V_22 = F_7 ( V_27 -> V_23 ) ;
struct V_40 * V_41 = V_22 -> V_42 ;
enum V_39 V_39 = V_26 -> V_39 ;
enum V_45 V_45 = F_23 ( V_69 -> V_28 . V_54 ) -> V_45 ;
V_15 = V_71 -> V_15 ;
if ( ! V_15 || ! V_15 -> V_24 [ 0 ] )
return;
F_14 ( L_14 ,
V_15 -> V_28 . V_73 ,
V_15 -> V_74 ,
V_15 -> V_27 -> V_28 . V_73 ,
V_15 -> V_27 -> V_74 ) ;
V_15 -> V_24 [ 5 ] &= ~ ( 3 << 2 ) ;
if ( F_21 ( V_69 ) )
V_15 -> V_24 [ 5 ] |= ( 1 << 2 ) ;
V_15 -> V_24 [ 6 ] = F_50 ( V_15 , V_9 ) / 2 ;
if ( V_22 -> V_75 . V_76 )
V_22 -> V_75 . V_76 ( V_15 , V_26 ,
V_9 ) ;
F_25 ( & V_22 -> V_55 ) ;
V_26 -> V_77 = V_15 ;
V_22 -> V_78 [ V_45 ] = V_26 ;
F_28 ( & V_22 -> V_55 ) ;
if ( V_41 && V_41 -> V_79 && V_41 -> V_79 -> V_80 ) {
if ( V_26 -> type != V_81 )
V_45 = - 1 ;
V_41 -> V_79 -> V_80 ( V_41 -> V_79 -> V_82 ,
( int ) V_39 , ( int ) V_45 ) ;
}
F_51 ( V_22 , V_45 , V_39 , V_15 -> V_24 ,
V_69 -> V_7 ,
V_26 -> type == V_83 ) ;
}
void F_52 ( struct V_26 * V_26 )
{
struct V_72 * V_27 = & V_26 -> V_28 ;
struct V_21 * V_22 = F_7 ( V_27 -> V_23 ) ;
struct V_40 * V_41 = V_22 -> V_42 ;
enum V_39 V_39 = V_26 -> V_39 ;
struct V_2 * V_54 = F_23 ( V_27 -> V_54 ) ;
enum V_45 V_45 = V_54 -> V_45 ;
if ( V_22 -> V_75 . V_84 )
V_22 -> V_75 . V_84 ( V_26 ) ;
F_25 ( & V_22 -> V_55 ) ;
V_26 -> V_77 = NULL ;
V_22 -> V_78 [ V_45 ] = NULL ;
F_28 ( & V_22 -> V_55 ) ;
if ( V_41 && V_41 -> V_79 && V_41 -> V_79 -> V_80 ) {
if ( V_26 -> type != V_81 )
V_45 = - 1 ;
V_41 -> V_79 -> V_80 ( V_41 -> V_79 -> V_82 ,
( int ) V_39 , ( int ) V_45 ) ;
}
F_51 ( V_22 , V_45 , V_39 , NULL , 0 , false ) ;
}
void F_53 ( struct V_21 * V_22 )
{
if ( F_54 ( V_22 ) ) {
V_22 -> V_75 . V_76 = F_12 ;
V_22 -> V_75 . V_84 = F_11 ;
} else if ( F_37 ( V_22 ) || F_38 ( V_22 ) ) {
V_22 -> V_75 . V_76 = F_42 ;
V_22 -> V_75 . V_84 = F_32 ;
} else if ( F_55 ( V_22 ) || F_56 ( V_22 ) -> V_85 >= 8 ) {
V_22 -> V_75 . V_76 = F_29 ;
V_22 -> V_75 . V_84 = F_22 ;
} else if ( F_57 ( V_22 ) ) {
V_22 -> V_75 . V_76 = F_42 ;
V_22 -> V_75 . V_84 = F_32 ;
}
}
static void F_58 ( struct V_86 * V_87 )
{
F_59 ( F_60 ( V_87 ) , V_88 ) ;
}
static void F_61 ( struct V_86 * V_87 )
{
F_62 ( F_60 ( V_87 ) , V_88 ) ;
}
static void F_63 ( struct V_86 * V_87 ,
bool V_89 )
{
struct V_21 * V_22 = F_60 ( V_87 ) ;
T_1 V_25 ;
if ( ! F_64 ( V_22 ) )
return;
F_58 ( V_87 ) ;
V_25 = F_8 ( V_90 ) ;
V_25 &= ~ V_91 ;
F_9 ( V_90 , V_25 ) ;
F_65 ( 1000 , 1500 ) ;
if ( V_89 ) {
V_25 = F_8 ( V_90 ) ;
V_25 |= V_91 ;
F_9 ( V_90 , V_25 ) ;
F_65 ( 1000 , 1500 ) ;
}
F_61 ( V_87 ) ;
}
static int F_66 ( struct V_86 * V_87 )
{
struct V_21 * V_22 = F_60 ( V_87 ) ;
if ( F_67 ( ! F_68 ( V_22 ) ) )
return - V_92 ;
return V_22 -> V_93 . V_94 . V_93 ;
}
static struct V_26 * F_69 ( struct V_21 * V_22 ,
int V_39 , int V_45 )
{
struct V_26 * V_27 ;
if ( F_34 ( V_45 >= V_95 ) )
return NULL ;
if ( V_45 >= 0 ) {
V_27 = V_22 -> V_78 [ V_45 ] ;
if ( V_27 != NULL && V_27 -> V_39 == V_39 &&
V_27 -> type == V_81 )
return V_27 ;
}
if ( V_45 > 0 )
return NULL ;
F_70 (dev_priv, pipe) {
V_27 = V_22 -> V_78 [ V_45 ] ;
if ( V_27 == NULL )
continue;
if ( V_27 -> type == V_81 )
continue;
if ( V_39 == V_27 -> V_39 )
return V_27 ;
}
return NULL ;
}
static int F_71 ( struct V_86 * V_87 , int V_39 ,
int V_45 , int V_3 )
{
struct V_21 * V_22 = F_60 ( V_87 ) ;
struct V_26 * V_26 ;
struct V_2 * V_54 ;
struct V_8 * V_9 ;
struct V_40 * V_41 = V_22 -> V_42 ;
int V_96 = 0 ;
if ( ! F_68 ( V_22 ) )
return 0 ;
F_58 ( V_87 ) ;
F_25 ( & V_22 -> V_55 ) ;
V_26 = F_69 ( V_22 , V_39 , V_45 ) ;
if ( ! V_26 || ! V_26 -> V_28 . V_54 ) {
F_4 ( L_15 , F_33 ( V_39 ) ) ;
V_96 = - V_92 ;
goto V_97;
}
V_54 = F_23 ( V_26 -> V_28 . V_54 ) ;
V_45 = V_54 -> V_45 ;
V_9 = & V_54 -> V_6 -> V_28 . V_9 ;
V_41 -> V_43 [ V_39 ] = V_3 ;
F_20 ( V_54 , V_39 , V_9 ) ;
V_97:
F_28 ( & V_22 -> V_55 ) ;
F_61 ( V_87 ) ;
return V_96 ;
}
static int F_72 ( struct V_86 * V_87 , int V_39 ,
int V_45 , bool * V_98 ,
unsigned char * V_99 , int V_100 )
{
struct V_21 * V_22 = F_60 ( V_87 ) ;
struct V_26 * V_26 ;
const T_5 * V_24 ;
int V_101 = - V_102 ;
F_25 ( & V_22 -> V_55 ) ;
V_26 = F_69 ( V_22 , V_39 , V_45 ) ;
if ( ! V_26 ) {
F_4 ( L_15 , F_33 ( V_39 ) ) ;
F_28 ( & V_22 -> V_55 ) ;
return V_101 ;
}
V_101 = 0 ;
* V_98 = V_26 -> V_77 != NULL ;
if ( * V_98 ) {
V_24 = V_26 -> V_77 -> V_24 ;
V_101 = F_10 ( V_24 ) ;
memcpy ( V_99 , V_24 , F_13 ( V_100 , V_101 ) ) ;
}
F_28 ( & V_22 -> V_55 ) ;
return V_101 ;
}
static int F_73 ( struct V_86 * V_103 ,
struct V_86 * V_104 , void * V_105 )
{
struct V_40 * V_41 = V_105 ;
struct V_21 * V_22 = F_60 ( V_103 ) ;
int V_4 ;
if ( F_34 ( V_41 -> V_106 || V_41 -> V_23 ) )
return - V_107 ;
F_74 ( & V_22 -> V_108 ) ;
V_41 -> V_106 = & V_109 ;
V_41 -> V_23 = V_103 ;
F_75 ( V_110 != V_111 ) ;
for ( V_4 = 0 ; V_4 < F_2 ( V_41 -> V_43 ) ; V_4 ++ )
V_41 -> V_43 [ V_4 ] = 0 ;
V_22 -> V_42 = V_41 ;
F_76 ( & V_22 -> V_108 ) ;
return 0 ;
}
static void F_77 ( struct V_86 * V_103 ,
struct V_86 * V_104 , void * V_105 )
{
struct V_40 * V_41 = V_105 ;
struct V_21 * V_22 = F_60 ( V_103 ) ;
F_74 ( & V_22 -> V_108 ) ;
V_41 -> V_106 = NULL ;
V_41 -> V_23 = NULL ;
V_22 -> V_42 = NULL ;
F_76 ( & V_22 -> V_108 ) ;
}
void F_78 ( struct V_21 * V_22 )
{
int V_101 ;
if ( F_56 ( V_22 ) -> V_112 == 0 )
return;
V_101 = F_79 ( V_22 -> V_108 . V_23 , & V_113 ) ;
if ( V_101 < 0 ) {
F_80 ( L_16 , V_101 ) ;
return;
}
V_22 -> V_114 = true ;
}
void F_81 ( struct V_21 * V_22 )
{
if ( ! V_22 -> V_114 )
return;
F_82 ( V_22 -> V_108 . V_23 , & V_113 ) ;
V_22 -> V_114 = false ;
}
void F_83 ( struct V_21 * V_22 )
{
if ( F_84 ( V_22 ) < 0 )
F_78 ( V_22 ) ;
}
void F_85 ( struct V_21 * V_22 )
{
if ( ( V_22 ) -> V_115 . V_116 != NULL )
F_86 ( V_22 ) ;
else
F_81 ( V_22 ) ;
}
