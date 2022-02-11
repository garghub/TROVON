static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_6 == 0 )
return false ;
V_2 -> V_7 . V_8 = V_4 -> V_9 . V_10 ;
V_2 -> V_11 = F_2 ( V_4 , F_3 ( V_12 ) ) ;
V_2 -> V_7 . V_13 = F_2 ( V_4 , F_3 ( V_14 ) ) ;
if ( F_4 ( & V_2 -> V_7 ) & V_15 ) {
V_2 -> V_7 . V_16 = F_2 ( V_4 ,
F_3 ( V_17 ) ) ;
V_2 -> V_7 . V_18 = V_2 -> V_7 . V_16 & V_19 ;
}
V_2 -> V_20 = F_5 ( & V_2 -> V_7 , V_21 , 0 ) ;
return true ;
}
static struct V_1 * F_6 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_2 -> V_7 ;
T_1 V_26 , V_27 ;
struct V_3 * V_4 ;
struct V_28 * V_29 = & V_23 -> V_29 ;
V_27 = 0 ;
V_2 -> V_30 = V_23 ;
V_2 -> V_31 = V_23 -> V_32 ;
V_4 = V_23 -> V_33 . V_34 ;
V_25 -> V_35 = V_23 -> V_36 . V_9 ;
V_25 -> V_37 = V_23 -> V_36 . V_10 ;
V_25 -> V_38 = V_23 -> V_36 . V_39 ;
V_25 -> V_40 = V_23 -> V_41 . V_42 ;
V_25 -> V_43 = V_23 -> V_41 . type ;
if ( ! F_1 ( V_2 , V_4 ) )
goto exit;
F_7 ( V_4 , F_3 ( V_44 ) , 0 ) ;
F_7 ( V_4 , F_3 ( V_45 ) , 0 ) ;
if ( F_4 ( V_25 ) & V_15 ) {
F_8 ( V_25 ) ;
( void ) F_9 ( V_25 ) ;
F_10 ( V_25 ) ;
}
V_26 = ( V_29 -> V_46 << V_47 ) |
( V_29 -> V_48 << V_49 ) ;
if ( V_26 == 0 )
V_26 = V_50 ;
F_11 ( V_25 , F_12 ( struct V_51 , V_52 ) ,
~ 0 , V_26 ) ;
if ( F_13 ( V_25 ) == V_53 ) {
if ( F_14 ( V_25 ) == 0 ) {
F_15 ( L_1 ) ;
F_11 ( V_25 , F_12 ( struct V_51 , V_54 ) ,
V_55 ,
V_55 ) ;
F_16 ( V_25 , 0 , V_56 ,
V_56 ) ;
}
if ( F_14 ( V_25 ) >= 1 ) {
F_15 ( L_2 ) ;
F_16 ( V_25 , 0 , V_57 ,
V_57 ) ;
}
}
if ( F_13 ( V_25 ) == V_58 ) {
F_15 ( L_3 ) ;
F_16 ( V_25 , 0 , V_59 ,
V_59 ) ;
}
return V_2 ;
exit:
return NULL ;
}
struct V_24 *
F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_60 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_6 ( V_2 , V_23 ) == NULL ) {
F_19 ( V_2 ) ;
return NULL ;
}
return (struct V_24 * ) V_2 ;
}
void F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_24 * V_61 = NULL ;
memcpy ( & V_61 , & V_25 , sizeof( struct V_24 * * ) ) ;
V_2 = (struct V_1 * ) V_25 ;
if ( V_2 == NULL )
return;
F_19 ( V_2 ) ;
}
struct V_3 * F_5 ( struct V_24 * V_25 , T_2 V_62 , T_2 V_63 )
{
struct V_3 * V_34 ;
struct V_1 * V_2 ;
T_3 V_64 ;
V_2 = (struct V_1 * ) V_25 ;
V_64 = 0 ;
F_21 (core, &sii->icbus->cores, list)
if ( V_34 -> V_9 . V_9 == V_62 ) {
if ( V_64 == V_63 )
return V_34 ;
V_64 ++ ;
}
return NULL ;
}
T_3 F_11 ( struct V_24 * V_25 , T_3 V_65 , T_1 V_66 , T_1 V_67 )
{
struct V_3 * V_4 ;
T_1 V_26 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_25 ;
V_4 = V_2 -> V_30 -> V_33 . V_34 ;
if ( V_66 || V_67 ) {
F_22 ( V_4 , V_65 , ~ V_66 , V_67 ) ;
}
V_26 = F_2 ( V_4 , V_65 ) ;
return V_26 ;
}
static T_3 F_23 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
return V_68 ;
}
static T_3 F_24 ( struct V_24 * V_25 , bool V_69 ,
struct V_3 * V_4 )
{
T_3 div ;
div = F_2 ( V_4 , F_3 ( V_70 ) ) ;
div = 4 * ( ( div >> V_71 ) + 1 ) ;
return V_69 ? V_72 : ( V_73 / div ) ;
}
static void
F_25 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
T_3 V_74 , V_75 , V_76 ;
T_3 V_77 , V_78 ;
V_75 = V_79 ;
V_76 = F_23 ( V_25 , V_4 ) ;
if ( V_76 != V_68 )
V_75 += V_80 ;
V_74 =
F_24 ( V_25 , false , V_4 ) ;
V_77 = ( ( V_74 * V_75 ) + 999999 ) / 1000000 ;
V_78 = ( ( V_74 * V_81 ) + 999999 ) / 1000000 ;
F_7 ( V_4 , F_3 ( V_77 ) , V_77 ) ;
F_7 ( V_4 , F_3 ( V_78 ) , V_78 ) ;
}
void F_26 ( struct V_24 * V_25 )
{
struct V_3 * V_4 ;
if ( ! ( F_4 ( V_25 ) & V_82 ) )
return;
V_4 = F_5 ( V_25 , V_83 , 0 ) ;
if ( V_4 == NULL )
return;
F_22 ( V_4 , F_3 ( V_70 ) , V_84 ,
( V_85 << V_71 ) ) ;
F_25 ( V_25 , V_4 ) ;
}
T_2 F_27 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_3 V_86 ;
T_2 V_87 ;
V_2 = (struct V_1 * ) V_25 ;
if ( F_4 ( V_25 ) & V_15 ) {
V_87 = F_28 ( V_25 ) ;
return V_87 ;
}
if ( ! ( F_4 ( V_25 ) & V_82 ) )
return 0 ;
V_87 = 0 ;
V_4 = F_5 ( V_25 , V_88 , 0 ) ;
if ( V_4 ) {
V_86 = F_24 ( V_25 , false , V_4 ) ;
V_87 = ( ( ( F_2 ( V_4 , F_3 ( V_77 ) ) + 2 )
* 1000000 ) + ( V_86 - 1 ) ) / V_86 ;
}
return V_87 ;
}
bool F_29 ( struct V_24 * V_25 , enum V_89 V_90 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = (struct V_1 * ) V_25 ;
if ( F_30 ( V_25 ) )
return V_90 == V_91 ;
V_4 = F_5 ( & V_2 -> V_7 , V_83 , 0 ) ;
F_31 ( V_4 , V_90 ) ;
return V_90 == V_91 ;
}
void F_32 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = (struct V_1 * ) V_25 ;
if ( F_30 ( V_25 ) ) {
V_4 = F_5 ( & V_2 -> V_7 , V_83 , 0 ) ;
F_31 ( V_4 , V_91 ) ;
}
if ( F_33 ( V_25 ) )
F_34 ( & V_2 -> V_30 -> V_92 , true ) ;
}
void F_35 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = (struct V_1 * ) V_25 ;
if ( F_30 ( V_25 ) ) {
V_4 = F_5 ( & V_2 -> V_7 , V_83 , 0 ) ;
F_31 ( V_4 , V_93 ) ;
}
if ( F_33 ( V_25 ) )
F_34 ( & V_2 -> V_30 -> V_92 , false ) ;
}
void F_36 ( struct V_24 * V_25 )
{
struct V_3 * V_4 ;
V_4 = F_5 ( V_25 , V_88 , 0 ) ;
F_37 ( V_4 , F_3 ( V_94 ) , V_95 ) ;
}
bool F_38 ( struct V_24 * V_25 )
{
T_1 V_26 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_25 ;
if ( V_2 -> V_30 -> V_96 != V_97 )
return false ;
F_39 ( V_2 -> V_31 , V_98 , & V_26 ) ;
if ( ( V_26 & 0xFFFF ) != V_99 )
return true ;
return false ;
}
T_3 F_40 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
return V_2 -> V_20 -> V_9 . V_9 ;
}
T_3 F_41 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
return V_2 -> V_20 -> V_9 . V_10 ;
}
