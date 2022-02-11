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
return true ;
}
static struct V_1 * F_5 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_2 -> V_7 ;
struct V_3 * V_4 ;
V_2 -> V_24 = V_21 ;
V_2 -> V_25 = V_21 -> V_26 ;
V_4 = V_21 -> V_27 . V_28 ;
V_23 -> V_29 = V_21 -> V_30 . V_9 ;
V_23 -> V_31 = V_21 -> V_30 . V_10 ;
V_23 -> V_32 = V_21 -> V_30 . V_33 ;
V_23 -> V_34 = V_21 -> V_35 . V_36 ;
V_23 -> V_37 = V_21 -> V_35 . type ;
if ( ! F_1 ( V_2 , V_4 ) )
goto exit;
F_6 ( V_4 , F_3 ( V_38 ) , 0 ) ;
F_6 ( V_4 , F_3 ( V_39 ) , 0 ) ;
if ( F_4 ( V_23 ) & V_15 ) {
( void ) F_7 ( V_23 ) ;
}
return V_2 ;
exit:
return NULL ;
}
struct V_22 *
F_8 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( sizeof( struct V_1 ) , V_40 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_5 ( V_2 , V_21 ) == NULL ) {
F_10 ( V_2 ) ;
return NULL ;
}
return (struct V_22 * ) V_2 ;
}
void F_11 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
if ( V_2 == NULL )
return;
F_10 ( V_2 ) ;
}
T_1 F_13 ( struct V_22 * V_23 , T_1 V_41 , T_2 V_42 , T_2 V_43 )
{
struct V_3 * V_4 ;
T_2 V_44 ;
struct V_1 * V_2 ;
V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
V_4 = V_2 -> V_24 -> V_27 . V_28 ;
if ( V_42 || V_43 )
F_14 ( V_4 , V_41 , ~ V_42 , V_43 ) ;
V_44 = F_2 ( V_4 , V_41 ) ;
return V_44 ;
}
static T_1 F_15 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
return V_45 ;
}
static T_1 F_16 ( struct V_22 * V_23 , bool V_46 ,
struct V_3 * V_4 )
{
T_1 div ;
div = F_2 ( V_4 , F_3 ( V_47 ) ) ;
div = 4 * ( ( div >> V_48 ) + 1 ) ;
return V_46 ? V_49 : ( V_50 / div ) ;
}
static void
F_17 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
T_1 V_51 , V_52 , V_53 ;
T_1 V_54 , V_55 ;
V_52 = V_56 ;
V_53 = F_15 ( V_23 , V_4 ) ;
if ( V_53 != V_45 )
V_52 += V_57 ;
V_51 =
F_16 ( V_23 , false , V_4 ) ;
V_54 = ( ( V_51 * V_52 ) + 999999 ) / 1000000 ;
V_55 = ( ( V_51 * V_58 ) + 999999 ) / 1000000 ;
F_6 ( V_4 , F_3 ( V_54 ) , V_54 ) ;
F_6 ( V_4 , F_3 ( V_55 ) , V_55 ) ;
}
void F_18 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
struct V_3 * V_4 ;
if ( ! ( F_4 ( V_23 ) & V_59 ) )
return;
V_4 = V_2 -> V_24 -> V_27 . V_28 ;
if ( V_4 == NULL )
return;
F_14 ( V_4 , F_3 ( V_47 ) , V_60 ,
( V_61 << V_48 ) ) ;
F_17 ( V_23 , V_4 ) ;
}
T_3 F_19 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_1 V_62 ;
T_3 V_63 ;
V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
if ( F_4 ( V_23 ) & V_15 ) {
V_63 = F_20 ( V_23 ) ;
return V_63 ;
}
if ( ! ( F_4 ( V_23 ) & V_59 ) )
return 0 ;
V_63 = 0 ;
V_4 = V_2 -> V_24 -> V_27 . V_28 ;
if ( V_4 ) {
V_62 = F_16 ( V_23 , false , V_4 ) ;
V_63 = ( ( ( F_2 ( V_4 , F_3 ( V_54 ) ) + 2 )
* 1000000 ) + ( V_62 - 1 ) ) / V_62 ;
}
return V_63 ;
}
bool F_21 ( struct V_22 * V_23 , enum V_64 V_65 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
V_4 = V_2 -> V_24 -> V_27 . V_28 ;
F_22 ( V_4 , V_65 ) ;
return V_65 == V_66 ;
}
void F_23 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
if ( V_2 -> V_24 -> V_67 == V_68 )
F_24 ( & V_2 -> V_24 -> V_69 , true ) ;
}
void F_25 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
if ( V_2 -> V_24 -> V_67 == V_68 )
F_24 ( & V_2 -> V_24 -> V_69 , false ) ;
}
void F_26 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
struct V_3 * V_4 ;
V_4 = V_2 -> V_24 -> V_27 . V_28 ;
F_27 ( V_4 , F_3 ( V_70 ) , V_71 ) ;
}
bool F_28 ( struct V_22 * V_23 )
{
T_2 V_44 ;
struct V_1 * V_2 ;
V_2 = F_12 ( V_23 , struct V_1 , V_7 ) ;
if ( V_2 -> V_24 -> V_67 != V_68 )
return false ;
F_29 ( V_2 -> V_25 , V_72 , & V_44 ) ;
if ( ( V_44 & 0xFFFF ) != V_73 )
return true ;
return false ;
}
