int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
return 0 ;
}
static T_1 F_2 ( T_1 V_6 )
{
return V_6 & ~ ( V_7 | V_8 | V_9 ) ;
}
static int F_3 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
T_2 T_3 * V_12 = ( T_2 T_3 * ) ( long ) V_11 -> V_13 ;
struct V_14 * V_15 = & V_2 -> V_3 . V_15 ;
T_1 V_16 ;
if ( F_4 ( V_11 -> V_6 ) != 4 )
return - V_17 ;
V_16 = F_2 ( V_11 -> V_6 ) ;
if ( V_16 >= sizeof( * V_15 ) / F_4 ( V_11 -> V_6 ) )
return - V_17 ;
return F_5 ( ( ( T_2 * ) V_15 ) [ V_16 ] , V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
T_2 T_3 * V_12 = ( T_2 T_3 * ) ( long ) V_11 -> V_13 ;
struct V_14 * V_15 = & V_2 -> V_3 . V_15 ;
T_1 V_16 , V_18 ;
if ( F_4 ( V_11 -> V_6 ) != 4 )
return - V_17 ;
V_16 = F_2 ( V_11 -> V_6 ) ;
if ( V_16 >= sizeof( * V_15 ) / F_4 ( V_11 -> V_6 ) )
return - V_17 ;
if ( F_7 ( V_18 , V_12 ) != 0 )
return - V_19 ;
if ( V_16 == F_8 ( V_20 . V_21 ) ) {
unsigned long V_22 = V_18 & V_23 ;
switch ( V_22 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
break;
default:
return - V_30 ;
}
}
( ( T_2 * ) V_15 ) [ V_16 ] = V_18 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return - V_30 ;
}
int F_10 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return - V_30 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 T_3 * V_31 )
{
return 0 ;
}
static bool F_12 ( T_1 V_32 )
{
return false ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_33 , T_1 V_34 )
{
return 0 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_1 V_33 )
{
return 0 ;
}
static bool F_12 ( T_1 V_32 )
{
switch ( V_32 ) {
case V_35 :
case V_36 :
case V_37 :
return true ;
}
return false ;
}
static int F_11 ( struct V_1 * V_2 , T_1 T_3 * V_31 )
{
if ( F_5 ( V_35 , V_31 ) )
return - V_19 ;
V_31 ++ ;
if ( F_5 ( V_36 , V_31 ) )
return - V_19 ;
V_31 ++ ;
if ( F_5 ( V_37 , V_31 ) )
return - V_19 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
void T_3 * V_12 = ( void T_3 * ) ( long ) V_11 -> V_13 ;
T_1 V_18 ;
int V_38 ;
V_38 = F_16 ( & V_18 , V_12 , F_4 ( V_11 -> V_6 ) ) ;
if ( V_38 != 0 )
return V_38 ;
return F_13 ( V_2 , V_11 -> V_6 , V_18 ) ;
}
static int F_17 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
void T_3 * V_12 = ( void T_3 * ) ( long ) V_11 -> V_13 ;
T_1 V_18 ;
V_18 = F_14 ( V_2 , V_11 -> V_6 ) ;
return F_18 ( V_12 , & V_18 , F_4 ( V_11 -> V_6 ) ) ;
}
static unsigned long F_19 ( void )
{
return sizeof( struct V_14 ) / sizeof( T_2 ) ;
}
unsigned long F_20 ( struct V_1 * V_2 )
{
return F_19 () + F_21 ( V_2 )
+ V_39 ;
}
int F_22 ( struct V_1 * V_2 , T_1 T_3 * V_31 )
{
unsigned int V_40 ;
const T_1 V_41 = V_42 | V_43 | V_9 ;
int V_38 ;
for ( V_40 = 0 ; V_40 < sizeof( struct V_14 ) / sizeof( T_2 ) ; V_40 ++ ) {
if ( F_5 ( V_41 | V_40 , V_31 ) )
return - V_19 ;
V_31 ++ ;
}
V_38 = F_11 ( V_2 , V_31 ) ;
if ( V_38 )
return V_38 ;
V_31 += V_39 ;
return F_23 ( V_2 , V_31 ) ;
}
int F_24 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
if ( ( V_11 -> V_6 & ~ V_8 ) >> 32 != V_42 >> 32 )
return - V_30 ;
if ( ( V_11 -> V_6 & V_44 ) == V_9 )
return F_3 ( V_2 , V_11 ) ;
if ( F_12 ( V_11 -> V_6 ) )
return F_17 ( V_2 , V_11 ) ;
return F_25 ( V_2 , V_11 ) ;
}
int F_26 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
if ( ( V_11 -> V_6 & ~ V_8 ) >> 32 != V_42 >> 32 )
return - V_30 ;
if ( ( V_11 -> V_6 & V_44 ) == V_9 )
return F_6 ( V_2 , V_11 ) ;
if ( F_12 ( V_11 -> V_6 ) )
return F_15 ( V_2 , V_11 ) ;
return F_27 ( V_2 , V_11 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
return - V_30 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
return - V_30 ;
}
int T_4 F_30 ( void )
{
unsigned long V_47 = F_31 () ;
unsigned long V_48 = F_32 () ;
if ( V_47 != V_49 )
return - V_30 ;
switch ( V_48 ) {
case V_50 :
return V_51 ;
case V_52 :
return V_53 ;
default:
return - V_30 ;
}
}
int F_33 ( struct V_1 * V_2 ,
const struct V_54 * V_55 )
{
unsigned int V_40 ;
if ( V_55 -> V_56 != F_30 () )
return - V_30 ;
V_2 -> V_3 . V_56 = V_55 -> V_56 ;
F_34 ( V_2 -> V_3 . V_57 , V_58 ) ;
for ( V_40 = 0 ; V_40 < sizeof( V_55 -> V_57 ) * 8 ; V_40 ++ ) {
if ( F_35 ( V_40 , ( void * ) V_55 -> V_57 ) ) {
if ( V_40 >= V_58 )
return - V_17 ;
F_36 ( V_40 , V_2 -> V_3 . V_57 ) ;
}
}
return F_37 ( V_2 ) ;
}
int F_38 ( struct V_54 * V_55 )
{
int V_56 = F_30 () ;
if ( V_56 < 0 )
return - V_59 ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
V_55 -> V_56 = ( V_60 ) V_56 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
return - V_30 ;
}
int F_40 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
return - V_30 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
return - V_30 ;
}
