static bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 [ 0 ] & V_3 ;
}
bool F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_3 ( V_5 ) )
return false ;
return F_4 ( F_5 ( V_5 ) ) & V_9 ;
}
static void F_6 ( struct V_1 * V_1 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_13 -> V_14 . V_14 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_15 * V_16 = F_8 ( V_13 -> V_14 . V_14 . V_16 ) ;
T_1 V_17 = F_9 ( V_16 -> V_18 . V_19 ) ;
T_1 V_20 = F_10 ( V_16 -> V_18 . V_19 ) ;
T_2 * V_21 = ( T_2 * ) V_11 ;
unsigned int V_22 ;
F_11 ( V_17 , 0 ) ;
F_12 ( V_17 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 += 4 ) {
if ( V_22 < sizeof( struct V_10 ) )
F_11 ( V_20 + V_22 , * V_21 ++ ) ;
else
F_11 ( V_20 + V_22 , 0 ) ;
}
F_11 ( V_17 , V_24 ) ;
F_12 ( V_17 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_10 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 . V_27 = 0 ;
V_25 . V_26 . V_28 = 0x7 ;
V_25 . V_26 . V_29 = 0x2 ;
V_25 . V_26 . V_30 = 0x8 ;
F_6 ( V_1 , & V_25 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_13 -> V_14 . V_14 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 V_31 ;
int V_32 = 0x3 ;
bool V_33 = false ;
static const T_3 V_34 [] = {
[ 0 ] = V_35 << 4 ,
[ 1 ] = V_36 >> 8 ,
[ 2 ] = V_36 & 0xff ,
[ 3 ] = 1 - 1 ,
[ 4 ] = V_37 ,
} ;
int V_22 ;
F_15 ( sizeof( V_34 ) > 20 ) ;
V_31 = V_1 -> V_38 ( V_1 , 0 ) ;
if ( F_16 ( V_5 ) && V_13 -> V_39 != V_40 )
V_33 = true ;
if ( V_1 -> V_2 [ 1 ] & V_41 || V_33 )
F_17 ( & V_1 -> V_42 , V_43 ,
V_44 & ~ V_45 ) ;
else
F_17 ( & V_1 -> V_42 , V_43 ,
V_44 | V_45 ) ;
for ( V_22 = 0 ; V_22 < sizeof( V_34 ) ; V_22 += 4 )
F_11 ( F_18 ( V_5 ) + V_22 ,
F_19 ( & V_34 [ V_22 ] , sizeof( V_34 ) - V_22 ) ) ;
F_11 ( F_20 ( V_5 ) ,
V_46 |
( sizeof( V_34 ) << V_47 ) |
( V_32 << V_48 ) |
( V_31 << V_49 ) ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_13 -> V_14 . V_14 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 V_50 = 0x1f ;
T_2 V_51 = 1 ;
T_2 V_52 = 0x0 ;
const T_2 V_53 = V_54 ;
bool V_33 = false ;
if ( F_16 ( V_5 ) && V_13 -> V_39 != V_40 )
V_33 = true ;
if ( V_1 -> V_2 [ 1 ] & V_41 || V_33 ) {
V_52 |= V_55 ;
V_52 |= V_56 ;
V_52 |= V_57 ;
V_52 |= V_58 ;
V_52 |= F_16 ( V_5 ) ? V_59 : 0 ;
} else
V_52 |= V_60 ;
F_11 ( F_5 ( V_5 ) , V_52 |
( F_16 ( V_5 ) ? 0 : V_53 ) |
V_50 << V_61 |
V_51 << V_62 |
V_9 ) ;
}
static bool F_22 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_13 -> V_14 . V_14 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_63 * V_16 = V_13 -> V_14 . V_14 . V_16 ;
struct V_15 * V_15 = F_8 ( V_16 ) ;
F_23 ( & V_7 -> V_64 . V_65 ) ;
F_24 ( ! F_25 ( & V_5 -> V_66 . V_67 ) ) ;
F_24 ( ! F_25 ( & V_16 -> V_68 ) ) ;
V_7 -> V_64 . V_69 = false ;
if ( F_26 ( V_5 ) && V_13 -> V_39 != V_40 ) {
F_27 ( L_1 ) ;
return false ;
}
if ( ! V_70 . V_71 ) {
F_27 ( L_2 ) ;
return false ;
}
if ( F_16 ( V_5 ) )
goto V_72;
if ( F_4 ( F_28 ( V_15 -> V_18 . V_19 ) ) &
V_73 ) {
F_27 ( L_3 ) ;
return false ;
}
if ( V_15 -> V_18 . V_74 . V_75 & V_76 ) {
F_27 ( L_4 ) ;
return false ;
}
V_72:
V_7 -> V_64 . V_69 = true ;
return true ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_12 * V_77 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_77 -> V_14 . V_14 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_24 ( F_4 ( F_5 ( V_5 ) ) & V_9 ) ;
F_24 ( V_7 -> V_64 . V_78 ) ;
F_23 ( & V_7 -> V_64 . V_65 ) ;
F_21 ( V_1 ) ;
V_7 -> V_64 . V_78 = true ;
}
void F_30 ( struct V_1 * V_1 )
{
struct V_12 * V_77 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_77 -> V_14 . V_14 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_3 ( V_5 ) ) {
F_27 ( L_5 ) ;
return;
}
if ( ! F_1 ( V_1 ) ) {
F_27 ( L_6 ) ;
return;
}
F_31 ( & V_7 -> V_64 . V_65 ) ;
if ( V_7 -> V_64 . V_79 ) {
F_27 ( L_7 ) ;
goto V_80;
}
if ( ! F_22 ( V_1 ) )
goto V_80;
V_7 -> V_64 . V_81 = 0 ;
F_13 ( V_1 ) ;
F_11 ( F_32 ( V_5 ) , V_82 |
V_83 | V_84 ) ;
F_14 ( V_1 ) ;
V_7 -> V_64 . V_79 = V_1 ;
V_80:
F_33 ( & V_7 -> V_64 . V_65 ) ;
}
void F_34 ( struct V_1 * V_1 )
{
struct V_12 * V_77 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_77 -> V_14 . V_14 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_31 ( & V_7 -> V_64 . V_65 ) ;
if ( ! V_7 -> V_64 . V_79 ) {
F_33 ( & V_7 -> V_64 . V_65 ) ;
return;
}
if ( V_7 -> V_64 . V_78 ) {
F_11 ( F_5 ( V_5 ) ,
F_4 ( F_5 ( V_5 ) ) & ~ V_9 ) ;
if ( F_35 ( ( F_4 ( F_36 ( V_5 ) ) &
V_85 ) == 0 , 2000 , 10 ) )
F_37 ( L_8 ) ;
V_7 -> V_64 . V_78 = false ;
} else {
F_24 ( F_4 ( F_5 ( V_5 ) ) & V_9 ) ;
}
V_7 -> V_64 . V_79 = NULL ;
F_33 ( & V_7 -> V_64 . V_65 ) ;
F_38 ( & V_7 -> V_64 . V_86 ) ;
}
static void F_39 ( struct V_87 * V_86 )
{
struct V_6 * V_7 =
F_40 ( V_86 , F_41 ( * V_7 ) , V_64 . V_86 . V_86 ) ;
struct V_1 * V_1 = V_7 -> V_64 . V_79 ;
if ( F_42 ( ( F_4 ( F_36 ( V_7 -> V_5 ) ) &
V_85 ) == 0 , 50 ) ) {
F_37 ( L_9 ) ;
return;
}
F_31 ( & V_7 -> V_64 . V_65 ) ;
V_1 = V_7 -> V_64 . V_79 ;
if ( ! V_1 )
goto V_80;
if ( V_7 -> V_64 . V_81 )
goto V_80;
F_29 ( V_1 ) ;
V_80:
F_33 ( & V_7 -> V_64 . V_65 ) ;
}
static void F_43 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_64 . V_78 ) {
T_1 V_52 = F_4 ( F_5 ( V_5 ) ) ;
F_24 ( ! ( V_52 & V_9 ) ) ;
F_11 ( F_5 ( V_5 ) , V_52 & ~ V_9 ) ;
V_7 -> V_64 . V_78 = false ;
}
}
void F_44 ( struct V_4 * V_5 ,
unsigned V_88 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_63 * V_16 ;
enum V_89 V_89 ;
F_31 ( & V_7 -> V_64 . V_65 ) ;
if ( ! V_7 -> V_64 . V_79 ) {
F_33 ( & V_7 -> V_64 . V_65 ) ;
return;
}
V_16 = F_7 ( V_7 -> V_64 . V_79 ) -> V_14 . V_14 . V_16 ;
V_89 = F_8 ( V_16 ) -> V_89 ;
F_43 ( V_5 ) ;
V_88 &= F_45 ( V_89 ) ;
V_7 -> V_64 . V_81 |= V_88 ;
F_33 ( & V_7 -> V_64 . V_65 ) ;
}
void F_46 ( struct V_4 * V_5 ,
unsigned V_88 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_63 * V_16 ;
enum V_89 V_89 ;
F_31 ( & V_7 -> V_64 . V_65 ) ;
if ( ! V_7 -> V_64 . V_79 ) {
F_33 ( & V_7 -> V_64 . V_65 ) ;
return;
}
V_16 = F_7 ( V_7 -> V_64 . V_79 ) -> V_14 . V_14 . V_16 ;
V_89 = F_8 ( V_16 ) -> V_89 ;
V_7 -> V_64 . V_81 &= ~ V_88 ;
if ( F_26 ( V_5 ) &&
( V_88 & F_47 ( V_89 ) ) )
F_43 ( V_5 ) ;
if ( ! V_7 -> V_64 . V_78 && ! V_7 -> V_64 . V_81 )
F_48 ( & V_7 -> V_64 . V_86 ,
F_49 ( 100 ) ) ;
F_33 ( & V_7 -> V_64 . V_65 ) ;
}
void F_50 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_51 ( & V_7 -> V_64 . V_86 , F_39 ) ;
F_52 ( & V_7 -> V_64 . V_65 ) ;
}
