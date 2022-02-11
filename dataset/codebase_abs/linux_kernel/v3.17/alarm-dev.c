static int F_1 ( enum V_1 type )
{
return type == V_2 ||
type == V_3 ;
}
static void F_2 ( struct V_4 * V_5 , T_1 exp )
{
if ( F_1 ( V_5 -> type ) )
F_3 ( & V_5 -> V_6 . V_5 , exp ) ;
else
F_4 ( & V_5 -> V_6 . V_7 , exp , V_8 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
if ( F_1 ( V_5 -> type ) )
return F_6 ( & V_5 -> V_6 . V_5 ) ;
return F_7 ( & V_5 -> V_6 . V_7 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
if ( F_1 ( V_5 -> type ) )
F_9 ( & V_5 -> V_6 . V_5 ) ;
else
F_10 ( & V_5 -> V_6 . V_7 ) ;
}
static void F_11 ( enum V_1 V_9 )
{
T_2 V_10 = 1U << V_9 ;
unsigned long V_11 ;
F_12 ( & V_12 , V_11 ) ;
F_13 ( V_13 , L_1 , V_9 ) ;
F_5 ( & V_14 [ V_9 ] ) ;
if ( V_15 ) {
V_15 &= ~ V_10 ;
if ( ! V_15 && ! V_16 )
F_14 ( & V_17 ) ;
}
V_18 &= ~ V_10 ;
F_15 ( & V_12 , V_11 ) ;
}
static void F_16 ( enum V_1 V_9 ,
struct V_19 * V_20 )
{
T_2 V_10 = 1U << V_9 ;
unsigned long V_11 ;
F_12 ( & V_12 , V_11 ) ;
F_13 ( V_13 , L_2 ,
V_9 , V_20 -> V_21 , V_20 -> V_22 ) ;
V_18 |= V_10 ;
F_2 ( & V_14 [ V_9 ] , F_17 ( * V_20 ) ) ;
F_15 ( & V_12 , V_11 ) ;
}
static int F_18 ( void )
{
unsigned long V_11 ;
int V_23 = 0 ;
F_12 ( & V_12 , V_11 ) ;
F_13 ( V_13 , L_3 ) ;
if ( ! V_15 && V_16 ) {
F_14 ( & V_17 ) ;
V_16 = 0 ;
}
F_15 ( & V_12 , V_11 ) ;
V_23 = F_19 ( V_24 , V_15 ) ;
if ( V_23 )
return V_23 ;
F_12 ( & V_12 , V_11 ) ;
V_23 = V_15 ;
V_16 = 1 ;
V_15 = 0 ;
F_15 ( & V_12 , V_11 ) ;
return V_23 ;
}
static int F_20 ( struct V_19 * V_20 )
{
struct V_25 V_26 ;
struct V_27 * V_28 ;
unsigned long V_11 ;
int V_23 = 0 ;
F_21 ( V_20 -> V_21 , & V_26 ) ;
V_28 = F_22 () ;
V_23 = F_23 ( V_20 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_28 )
V_23 = F_24 ( V_28 , & V_26 ) ;
F_12 ( & V_12 , V_11 ) ;
V_15 |= V_29 ;
F_25 ( & V_24 ) ;
F_15 ( & V_12 , V_11 ) ;
return V_23 ;
}
static int F_26 ( enum V_1 V_9 ,
struct V_19 * V_20 )
{
int V_23 = 0 ;
switch ( V_9 ) {
case V_2 :
case V_30 :
F_27 ( V_20 ) ;
break;
case V_3 :
case V_31 :
F_28 ( V_20 ) ;
break;
case V_32 :
F_29 ( V_20 ) ;
break;
default:
V_23 = - V_33 ;
}
return V_23 ;
}
static long F_30 ( struct V_34 * V_34 , unsigned int V_35 ,
struct V_19 * V_20 )
{
int V_23 = 0 ;
unsigned long V_11 ;
enum V_1 V_9 = F_31 ( V_35 ) ;
if ( V_9 >= V_36 )
return - V_33 ;
if ( F_32 ( V_35 ) != F_33 ( 0 ) ) {
if ( ( V_34 -> V_37 & V_38 ) == V_39 )
return - V_40 ;
if ( V_34 -> V_41 == NULL &&
V_35 != V_42 ) {
F_12 ( & V_12 , V_11 ) ;
if ( V_43 ) {
F_15 ( & V_12 , V_11 ) ;
return - V_44 ;
}
V_43 = 1 ;
V_34 -> V_41 = ( void * ) 1 ;
F_15 ( & V_12 , V_11 ) ;
}
}
switch ( F_32 ( V_35 ) ) {
case F_34 ( 0 ) :
F_11 ( V_9 ) ;
break;
case F_35 ( 0 ) :
F_16 ( V_9 , V_20 ) ;
break;
case F_36 ( 0 ) :
F_16 ( V_9 , V_20 ) ;
case V_45 :
V_23 = F_18 () ;
break;
case V_42 :
V_23 = F_20 ( V_20 ) ;
break;
case F_33 ( 0 ) :
V_23 = F_26 ( V_9 , V_20 ) ;
break;
default:
V_23 = - V_33 ;
}
return V_23 ;
}
static long F_37 ( struct V_34 * V_34 , unsigned int V_35 , unsigned long V_46 )
{
struct V_19 V_20 ;
int V_23 ;
switch ( F_32 ( V_35 ) ) {
case F_36 ( 0 ) :
case F_35 ( 0 ) :
case V_42 :
if ( F_38 ( & V_20 , ( void V_47 * ) V_46 , sizeof( V_20 ) ) )
return - V_48 ;
break;
}
V_23 = F_30 ( V_34 , V_35 , & V_20 ) ;
if ( V_23 )
return V_23 ;
switch ( F_32 ( V_35 ) ) {
case F_33 ( 0 ) :
if ( F_39 ( ( void V_47 * ) V_46 , & V_20 , sizeof( V_20 ) ) )
return - V_48 ;
break;
}
return 0 ;
}
static long F_40 ( struct V_34 * V_34 , unsigned int V_35 ,
unsigned long V_46 )
{
struct V_19 V_20 ;
int V_23 ;
switch ( F_32 ( V_35 ) ) {
case F_41 ( 0 ) :
case F_42 ( 0 ) :
case V_49 :
if ( F_43 ( & V_20 , ( void V_47 * ) V_46 ) )
return - V_48 ;
case F_44 ( 0 ) :
V_35 = F_45 ( V_35 ) ;
break;
}
V_23 = F_30 ( V_34 , V_35 , & V_20 ) ;
if ( V_23 )
return V_23 ;
switch ( F_32 ( V_35 ) ) {
case F_33 ( 0 ) :
if ( F_46 ( & V_20 , ( void V_47 * ) V_46 ) )
return - V_48 ;
break;
}
return 0 ;
}
static int F_47 ( struct V_50 * V_50 , struct V_34 * V_34 )
{
V_34 -> V_41 = NULL ;
return 0 ;
}
static int F_48 ( struct V_50 * V_50 , struct V_34 * V_34 )
{
int V_51 ;
unsigned long V_11 ;
F_12 ( & V_12 , V_11 ) ;
if ( V_34 -> V_41 ) {
for ( V_51 = 0 ; V_51 < V_36 ; V_51 ++ ) {
T_2 V_10 = 1U << V_51 ;
if ( V_18 & V_10 ) {
F_13 ( V_52 ,
L_4 ,
V_53 ,
! ! ( V_15 & V_10 ) ) ;
V_18 &= ~ V_10 ;
}
F_15 ( & V_12 , V_11 ) ;
F_8 ( & V_14 [ V_51 ] ) ;
F_12 ( & V_12 , V_11 ) ;
}
if ( V_15 | V_16 ) {
if ( V_15 )
F_13 ( V_52 , L_5 ,
V_53 , V_15 ) ;
F_14 ( & V_17 ) ;
V_16 = 0 ;
V_15 = 0 ;
}
V_43 = 0 ;
}
F_15 ( & V_12 , V_11 ) ;
return 0 ;
}
static void F_49 ( struct V_4 * V_54 )
{
unsigned long V_11 ;
T_2 V_10 = 1U << V_54 -> type ;
F_13 ( INT , L_6 , V_53 , V_54 -> type ) ;
F_12 ( & V_12 , V_11 ) ;
if ( V_18 & V_10 ) {
F_50 ( & V_17 , 5000 ) ;
V_18 &= ~ V_10 ;
V_15 |= V_10 ;
F_25 ( & V_24 ) ;
}
F_15 ( & V_12 , V_11 ) ;
}
static enum V_55 F_51 ( struct V_56 * V_7 )
{
struct V_4 * V_57 = F_52 ( V_7 , struct V_4 , V_6 . V_7 ) ;
F_49 ( V_57 ) ;
return V_58 ;
}
static enum V_59 F_53 ( struct V_54 * V_5 ,
T_1 V_60 )
{
struct V_4 * V_57 = F_52 ( V_5 , struct V_4 , V_6 . V_5 ) ;
F_49 ( V_57 ) ;
return V_61 ;
}
static int T_3 F_54 ( void )
{
int V_62 ;
int V_51 ;
V_62 = F_55 ( & V_63 ) ;
if ( V_62 )
return V_62 ;
F_56 ( & V_14 [ V_2 ] . V_6 . V_5 ,
V_64 , F_53 ) ;
F_57 ( & V_14 [ V_30 ] . V_6 . V_7 ,
V_65 , V_8 ) ;
F_56 ( & V_14 [ V_3 ] . V_6 . V_5 ,
V_66 , F_53 ) ;
F_57 ( & V_14 [ V_31 ] . V_6 . V_7 ,
V_67 , V_8 ) ;
F_57 ( & V_14 [ V_32 ] . V_6 . V_7 ,
V_68 , V_8 ) ;
for ( V_51 = 0 ; V_51 < V_36 ; V_51 ++ ) {
V_14 [ V_51 ] . type = V_51 ;
if ( ! F_1 ( V_51 ) )
V_14 [ V_51 ] . V_6 . V_7 . V_69 = F_51 ;
}
F_58 ( & V_17 , L_7 ) ;
return 0 ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_63 ) ;
F_61 ( & V_17 ) ;
}
