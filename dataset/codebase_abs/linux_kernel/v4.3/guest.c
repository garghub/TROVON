int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_1 F_2 ( T_1 V_3 )
{
return V_3 & ~ ( V_4 | V_5 | V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
T_2 T_3 * V_9 = ( T_2 T_3 * ) ( long ) V_8 -> V_10 ;
struct V_11 * V_12 = & V_2 -> V_13 . V_12 ;
T_1 V_14 ;
if ( F_4 ( V_8 -> V_3 ) != 4 )
return - V_15 ;
V_14 = F_2 ( V_8 -> V_3 ) ;
if ( V_14 >= sizeof( * V_12 ) / F_4 ( V_8 -> V_3 ) )
return - V_15 ;
return F_5 ( ( ( T_2 * ) V_12 ) [ V_14 ] , V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
T_2 T_3 * V_9 = ( T_2 T_3 * ) ( long ) V_8 -> V_10 ;
struct V_11 * V_12 = & V_2 -> V_13 . V_12 ;
T_1 V_14 , V_16 ;
if ( F_4 ( V_8 -> V_3 ) != 4 )
return - V_15 ;
V_14 = F_2 ( V_8 -> V_3 ) ;
if ( V_14 >= sizeof( * V_12 ) / F_4 ( V_8 -> V_3 ) )
return - V_15 ;
if ( F_7 ( V_16 , V_9 ) != 0 )
return - V_17 ;
if ( V_14 == F_8 ( V_18 . V_19 ) ) {
unsigned long V_20 = V_16 & V_21 ;
switch ( V_20 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
break;
default:
return - V_28 ;
}
}
( ( T_2 * ) V_12 ) [ V_14 ] = V_16 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return - V_28 ;
}
int F_10 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return - V_28 ;
}
static bool F_11 ( T_1 V_29 )
{
switch ( V_29 ) {
case V_30 :
case V_31 :
case V_32 :
return true ;
}
return false ;
}
static int F_12 ( struct V_1 * V_2 , T_1 T_3 * V_33 )
{
if ( F_5 ( V_30 , V_33 ) )
return - V_17 ;
V_33 ++ ;
if ( F_5 ( V_31 , V_33 ) )
return - V_17 ;
V_33 ++ ;
if ( F_5 ( V_32 , V_33 ) )
return - V_17 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
void T_3 * V_9 = ( void T_3 * ) ( long ) V_8 -> V_10 ;
T_1 V_16 ;
int V_34 ;
V_34 = F_14 ( & V_16 , V_9 , F_4 ( V_8 -> V_3 ) ) ;
if ( V_34 != 0 )
return - V_17 ;
return F_15 ( V_2 , V_8 -> V_3 , V_16 ) ;
}
static int F_16 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
void T_3 * V_9 = ( void T_3 * ) ( long ) V_8 -> V_10 ;
T_1 V_16 ;
V_16 = F_17 ( V_2 , V_8 -> V_3 ) ;
return F_18 ( V_9 , & V_16 , F_4 ( V_8 -> V_3 ) ) ;
}
static unsigned long F_19 ( void )
{
return sizeof( struct V_11 ) / sizeof( T_2 ) ;
}
unsigned long F_20 ( struct V_1 * V_2 )
{
return F_19 () + F_21 ( V_2 )
+ V_35 ;
}
int F_22 ( struct V_1 * V_2 , T_1 T_3 * V_33 )
{
unsigned int V_36 ;
const T_1 V_37 = V_38 | V_39 | V_6 ;
int V_34 ;
for ( V_36 = 0 ; V_36 < sizeof( struct V_11 ) / sizeof( T_2 ) ; V_36 ++ ) {
if ( F_5 ( V_37 | V_36 , V_33 ) )
return - V_17 ;
V_33 ++ ;
}
V_34 = F_12 ( V_2 , V_33 ) ;
if ( V_34 )
return V_34 ;
V_33 += V_35 ;
return F_23 ( V_2 , V_33 ) ;
}
int F_24 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_38 >> 32 )
return - V_28 ;
if ( ( V_8 -> V_3 & V_40 ) == V_6 )
return F_3 ( V_2 , V_8 ) ;
if ( F_11 ( V_8 -> V_3 ) )
return F_16 ( V_2 , V_8 ) ;
return F_25 ( V_2 , V_8 ) ;
}
int F_26 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_38 >> 32 )
return - V_28 ;
if ( ( V_8 -> V_3 & V_40 ) == V_6 )
return F_6 ( V_2 , V_8 ) ;
if ( F_11 ( V_8 -> V_3 ) )
return F_13 ( V_2 , V_8 ) ;
return F_27 ( V_2 , V_8 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
return - V_28 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
return - V_28 ;
}
int T_4 F_30 ( void )
{
switch ( F_31 () ) {
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
default:
return - V_28 ;
}
}
int F_32 ( struct V_47 * V_48 )
{
int V_49 = F_30 () ;
if ( V_49 < 0 )
return - V_50 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_49 = ( V_51 ) V_49 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
return - V_28 ;
}
int F_34 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
return - V_28 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
return - V_28 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
return - V_28 ;
}
