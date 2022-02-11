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
static bool F_12 ( T_1 V_32 )
{
switch ( V_32 ) {
case V_33 :
case V_34 :
case V_35 :
return true ;
}
return false ;
}
static int F_11 ( struct V_1 * V_2 , T_1 T_3 * V_31 )
{
if ( F_5 ( V_33 , V_31 ) )
return - V_19 ;
V_31 ++ ;
if ( F_5 ( V_34 , V_31 ) )
return - V_19 ;
V_31 ++ ;
if ( F_5 ( V_35 , V_31 ) )
return - V_19 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
void T_3 * V_12 = ( void T_3 * ) ( long ) V_11 -> V_13 ;
T_1 V_18 ;
int V_36 ;
V_36 = F_14 ( & V_18 , V_12 , F_4 ( V_11 -> V_6 ) ) ;
if ( V_36 != 0 )
return - V_19 ;
return F_15 ( V_2 , V_11 -> V_6 , V_18 ) ;
}
static int F_16 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
void T_3 * V_12 = ( void T_3 * ) ( long ) V_11 -> V_13 ;
T_1 V_18 ;
V_18 = F_17 ( V_2 , V_11 -> V_6 ) ;
return F_18 ( V_12 , & V_18 , F_4 ( V_11 -> V_6 ) ) ;
}
static unsigned long F_19 ( void )
{
return sizeof( struct V_14 ) / sizeof( T_2 ) ;
}
unsigned long F_20 ( struct V_1 * V_2 )
{
return F_19 () + F_21 ( V_2 )
+ V_37 ;
}
int F_22 ( struct V_1 * V_2 , T_1 T_3 * V_31 )
{
unsigned int V_38 ;
const T_1 V_39 = V_40 | V_41 | V_9 ;
int V_36 ;
for ( V_38 = 0 ; V_38 < sizeof( struct V_14 ) / sizeof( T_2 ) ; V_38 ++ ) {
if ( F_5 ( V_39 | V_38 , V_31 ) )
return - V_19 ;
V_31 ++ ;
}
V_36 = F_11 ( V_2 , V_31 ) ;
if ( V_36 )
return V_36 ;
V_31 += V_37 ;
return F_23 ( V_2 , V_31 ) ;
}
int F_24 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
if ( ( V_11 -> V_6 & ~ V_8 ) >> 32 != V_40 >> 32 )
return - V_30 ;
if ( ( V_11 -> V_6 & V_42 ) == V_9 )
return F_3 ( V_2 , V_11 ) ;
if ( F_12 ( V_11 -> V_6 ) )
return F_16 ( V_2 , V_11 ) ;
return F_25 ( V_2 , V_11 ) ;
}
int F_26 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
if ( ( V_11 -> V_6 & ~ V_8 ) >> 32 != V_40 >> 32 )
return - V_30 ;
if ( ( V_11 -> V_6 & V_42 ) == V_9 )
return F_6 ( V_2 , V_11 ) ;
if ( F_12 ( V_11 -> V_6 ) )
return F_13 ( V_2 , V_11 ) ;
return F_27 ( V_2 , V_11 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
return - V_30 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
return - V_30 ;
}
int T_4 F_30 ( void )
{
switch ( F_31 () ) {
case V_45 :
return V_46 ;
case V_47 :
return V_48 ;
default:
return - V_30 ;
}
}
int F_32 ( struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
unsigned int V_38 ;
if ( V_50 -> V_51 != F_30 () )
return - V_30 ;
V_2 -> V_3 . V_51 = V_50 -> V_51 ;
F_33 ( V_2 -> V_3 . V_52 , V_53 ) ;
for ( V_38 = 0 ; V_38 < sizeof( V_50 -> V_52 ) * 8 ; V_38 ++ ) {
if ( F_34 ( V_38 , ( void * ) V_50 -> V_52 ) ) {
if ( V_38 >= V_53 )
return - V_17 ;
F_35 ( V_38 , V_2 -> V_3 . V_52 ) ;
}
}
return F_36 ( V_2 ) ;
}
int F_37 ( struct V_49 * V_50 )
{
int V_51 = F_30 () ;
if ( V_51 < 0 )
return - V_54 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_51 = ( V_55 ) V_51 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
return - V_30 ;
}
int F_39 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
return - V_30 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
return - V_30 ;
}
