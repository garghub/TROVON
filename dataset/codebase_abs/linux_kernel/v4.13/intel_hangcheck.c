static bool
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( F_2 ( V_2 -> V_4 ) >= 8 ) {
return ( V_3 >> 23 ) == 0x1c ;
} else {
V_3 &= ~ V_5 ;
return V_3 == ( V_6 | V_7 |
V_8 ) ;
}
}
static struct V_1 *
F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_9 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_1 * V_12 ;
enum V_13 V_14 ;
if ( F_2 ( V_11 ) >= 8 ) {
F_4 (signaller, dev_priv, id) {
if ( V_2 == V_12 )
continue;
if ( V_9 == V_12 -> V_15 . V_16 [ V_2 -> V_17 ] )
return V_12 ;
}
} else {
T_1 V_18 = V_3 & V_5 ;
F_4 (signaller, dev_priv, id) {
if( V_2 == V_12 )
continue;
if ( V_18 == V_12 -> V_15 . V_19 . V_20 [ V_2 -> V_17 ] )
return V_12 ;
}
}
F_5 ( L_1 ,
V_2 -> V_21 , V_3 , V_9 ) ;
return F_6 ( - V_22 ) ;
}
static struct V_1 *
F_7 ( struct V_1 * V_2 , T_1 * V_23 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
void T_3 * V_24 ;
T_1 V_25 , V_3 , V_26 ;
T_2 V_9 = 0 ;
int V_27 , V_28 ;
if ( V_2 -> V_29 == NULL )
return NULL ;
V_3 = F_8 ( F_9 ( V_2 -> V_30 ) ) ;
if ( ! F_1 ( V_2 , V_3 ) )
return NULL ;
V_26 = F_10 ( V_2 ) & V_31 ;
V_28 = ( F_2 ( V_11 ) >= 8 ) ? 5 : 4 ;
V_24 = ( void T_3 * ) V_2 -> V_29 -> V_24 ;
for ( V_27 = V_28 ; V_27 ; -- V_27 ) {
V_26 &= V_2 -> V_29 -> V_32 - 1 ;
V_25 = F_11 ( V_24 + V_26 ) ;
if ( V_25 == V_3 )
break;
V_26 -= 4 ;
}
if ( ! V_27 )
return NULL ;
* V_23 = F_11 ( V_24 + V_26 + 4 ) + 1 ;
if ( F_2 ( V_11 ) >= 8 ) {
V_9 = F_11 ( V_24 + V_26 + 12 ) ;
V_9 <<= 32 ;
V_9 |= F_11 ( V_24 + V_26 + 8 ) ;
}
return F_3 ( V_2 , V_3 , V_9 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_1 * V_12 ;
T_1 V_23 ;
V_2 -> V_33 . V_34 ++ ;
V_12 = F_7 ( V_2 , & V_23 ) ;
if ( V_12 == NULL )
return - 1 ;
if ( F_13 ( V_12 ) )
return 0 ;
if ( V_12 -> V_33 . V_34 >= V_35 )
return - 1 ;
if ( F_14 ( F_15 ( V_12 ) , V_23 ) )
return 1 ;
if ( F_16 ( V_12 ) & V_36 &&
F_12 ( V_12 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
enum V_13 V_14 ;
F_4 (engine, dev_priv, id)
V_2 -> V_33 . V_34 = 0 ;
}
static bool F_18 ( T_1 V_37 , T_1 * V_38 )
{
T_1 V_39 = V_37 | * V_38 ;
bool V_40 ;
V_40 = V_39 == * V_38 ;
* V_38 |= V_39 ;
return V_40 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_41 V_42 ;
struct V_41 * V_43 = & V_2 -> V_33 . V_42 ;
bool V_44 ;
int V_45 ;
int V_46 ;
if ( V_2 -> V_14 != V_47 )
return true ;
F_20 ( V_2 , & V_42 ) ;
V_44 = F_18 ( V_42 . V_42 ,
& V_43 -> V_42 ) ;
V_44 &= F_18 ( V_42 . V_48 ,
& V_43 -> V_48 ) ;
F_21 (dev_priv, slice, subslice) {
V_44 &= F_18 ( V_42 . V_49 [ V_45 ] [ V_46 ] ,
& V_43 -> V_49 [ V_45 ] [ V_46 ] ) ;
V_44 &= F_18 ( V_42 . V_50 [ V_45 ] [ V_46 ] ,
& V_43 -> V_50 [ V_45 ] [ V_46 ] ) ;
}
return V_44 ;
}
static enum V_51
F_22 ( struct V_1 * V_2 , T_2 V_52 )
{
if ( V_52 != V_2 -> V_33 . V_52 ) {
memset ( & V_2 -> V_33 . V_42 , 0 ,
sizeof( V_2 -> V_33 . V_42 ) ) ;
return V_53 ;
}
if ( ! F_19 ( V_2 ) )
return V_54 ;
return V_55 ;
}
static enum V_51
F_23 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
enum V_51 V_56 ;
T_1 V_39 ;
V_56 = F_22 ( V_2 , V_52 ) ;
if ( V_56 != V_55 )
return V_56 ;
if ( F_24 ( V_11 ) )
return V_55 ;
V_39 = F_16 ( V_2 ) ;
if ( V_39 & V_57 ) {
F_25 ( V_11 , 0 ,
L_2 ,
V_2 -> V_21 ) ;
F_26 ( V_2 , V_39 ) ;
return V_58 ;
}
if ( F_2 ( V_11 ) >= 6 && V_39 & V_36 ) {
switch ( F_12 ( V_2 ) ) {
default:
return V_55 ;
case 1 :
F_25 ( V_11 , 0 ,
L_3 ,
V_2 -> V_21 ) ;
F_26 ( V_2 , V_39 ) ;
return V_58 ;
case 0 :
return V_59 ;
}
}
return V_55 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
if ( V_2 -> V_62 )
V_2 -> V_62 ( V_2 ) ;
V_61 -> V_52 = F_28 ( V_2 ) ;
V_61 -> V_23 = F_15 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
V_2 -> V_33 . V_52 = V_61 -> V_52 ;
V_2 -> V_33 . V_23 = V_61 -> V_23 ;
V_2 -> V_33 . V_63 = V_61 -> V_63 ;
V_2 -> V_33 . V_64 = V_61 -> V_64 ;
}
static enum V_51
F_30 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
if ( V_2 -> V_33 . V_23 != V_61 -> V_23 )
return V_65 ;
if ( F_14 ( V_61 -> V_23 , F_31 ( V_2 ) ) )
return V_66 ;
return F_23 ( V_2 , V_61 -> V_52 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
unsigned long V_67 = V_68 ;
V_61 -> V_63 = F_30 ( V_2 , V_61 ) ;
switch ( V_61 -> V_63 ) {
case V_66 :
case V_65 :
V_61 -> V_52 = 0 ;
memset ( & V_2 -> V_33 . V_42 , 0 ,
sizeof( V_2 -> V_33 . V_42 ) ) ;
case V_58 :
case V_59 :
V_2 -> V_33 . V_69 = V_70 ;
break;
case V_53 :
case V_54 :
V_67 = V_71 ;
break;
case V_55 :
break;
default:
F_33 ( V_61 -> V_63 ) ;
}
V_61 -> V_64 = F_34 ( V_70 ,
V_2 -> V_33 . V_69 + V_67 ) ;
}
static void F_35 ( struct V_10 * V_4 ,
unsigned int V_72 ,
unsigned int V_44 )
{
struct V_1 * V_2 ;
char V_73 [ 80 ] ;
unsigned int V_39 ;
int V_74 ;
if ( V_44 != V_72 )
V_72 &= ~ V_44 ;
V_74 = F_36 ( V_73 , sizeof( V_73 ) ,
L_4 , V_44 == V_72 ? L_5 : L_6 ) ;
F_37 (engine, i915, hung, tmp)
V_74 += F_36 ( V_73 + V_74 , sizeof( V_73 ) - V_74 ,
L_7 , V_2 -> V_21 ) ;
V_73 [ V_74 - 2 ] = '\0' ;
return F_25 ( V_4 , V_72 , L_8 , V_73 ) ;
}
static void F_38 ( struct V_75 * V_76 )
{
struct V_10 * V_11 =
F_39 ( V_76 , F_40 ( * V_11 ) ,
V_77 . V_78 . V_76 ) ;
struct V_1 * V_2 ;
enum V_13 V_14 ;
unsigned int V_72 = 0 , V_44 = 0 ;
int V_79 = 0 ;
if ( ! V_4 . V_80 )
return;
if ( ! F_41 ( V_11 -> V_81 . V_82 ) )
return;
if ( F_42 ( & V_11 -> V_77 ) )
return;
F_43 ( V_11 ) ;
F_4 (engine, dev_priv, id) {
struct V_60 V_83 , * V_61 = & V_83 ;
const bool V_84 = F_44 ( V_2 ) ;
F_17 ( V_11 ) ;
F_27 ( V_2 , V_61 ) ;
F_32 ( V_2 , V_61 ) ;
F_29 ( V_2 , V_61 ) ;
if ( V_2 -> V_33 . V_64 ) {
V_72 |= F_45 ( V_2 ) ;
if ( V_61 -> V_63 != V_55 )
V_44 |= F_45 ( V_2 ) ;
}
V_79 += V_84 ;
}
if ( V_72 )
F_35 ( V_11 , V_72 , V_44 ) ;
if ( V_79 )
F_46 ( V_11 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_33 , 0 , sizeof( V_2 -> V_33 ) ) ;
}
void F_48 ( struct V_10 * V_4 )
{
F_49 ( & V_4 -> V_77 . V_78 ,
F_38 ) ;
}
