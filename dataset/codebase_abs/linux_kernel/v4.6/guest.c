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
struct V_11 * V_12 = & V_2 -> V_13 . V_14 . V_15 ;
T_1 V_16 ;
if ( F_4 ( V_8 -> V_3 ) != 4 )
return - V_17 ;
V_16 = F_2 ( V_8 -> V_3 ) ;
if ( V_16 >= sizeof( * V_12 ) / F_4 ( V_8 -> V_3 ) )
return - V_17 ;
return F_5 ( ( ( T_2 * ) V_12 ) [ V_16 ] , V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
T_2 T_3 * V_9 = ( T_2 T_3 * ) ( long ) V_8 -> V_10 ;
struct V_11 * V_12 = & V_2 -> V_13 . V_14 . V_15 ;
T_1 V_16 , V_18 ;
if ( F_4 ( V_8 -> V_3 ) != 4 )
return - V_17 ;
V_16 = F_2 ( V_8 -> V_3 ) ;
if ( V_16 >= sizeof( * V_12 ) / F_4 ( V_8 -> V_3 ) )
return - V_17 ;
if ( F_7 ( V_18 , V_9 ) != 0 )
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
( ( T_2 * ) V_12 ) [ V_16 ] = V_18 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return - V_30 ;
}
int F_10 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return - V_30 ;
}
static bool F_11 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_32 :
case V_33 :
case V_34 :
return true ;
}
return false ;
}
static int F_12 ( struct V_1 * V_2 , T_1 T_3 * V_35 )
{
if ( F_5 ( V_32 , V_35 ) )
return - V_19 ;
V_35 ++ ;
if ( F_5 ( V_33 , V_35 ) )
return - V_19 ;
V_35 ++ ;
if ( F_5 ( V_34 , V_35 ) )
return - V_19 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
void T_3 * V_9 = ( void T_3 * ) ( long ) V_8 -> V_10 ;
T_1 V_18 ;
int V_36 ;
V_36 = F_14 ( & V_18 , V_9 , F_4 ( V_8 -> V_3 ) ) ;
if ( V_36 != 0 )
return - V_19 ;
return F_15 ( V_2 , V_8 -> V_3 , V_18 ) ;
}
static int F_16 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
void T_3 * V_9 = ( void T_3 * ) ( long ) V_8 -> V_10 ;
T_1 V_18 ;
V_18 = F_17 ( V_2 , V_8 -> V_3 ) ;
return F_18 ( V_9 , & V_18 , F_4 ( V_8 -> V_3 ) ) ? - V_19 : 0 ;
}
static unsigned long F_19 ( void )
{
return sizeof( struct V_11 ) / sizeof( T_2 ) ;
}
unsigned long F_20 ( struct V_1 * V_2 )
{
return F_19 () + F_21 ( V_2 )
+ V_37 ;
}
int F_22 ( struct V_1 * V_2 , T_1 T_3 * V_35 )
{
unsigned int V_38 ;
const T_1 V_39 = V_40 | V_41 | V_6 ;
int V_36 ;
for ( V_38 = 0 ; V_38 < sizeof( struct V_11 ) / sizeof( T_2 ) ; V_38 ++ ) {
if ( F_5 ( V_39 | V_38 , V_35 ) )
return - V_19 ;
V_35 ++ ;
}
V_36 = F_12 ( V_2 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_35 += V_37 ;
return F_23 ( V_2 , V_35 ) ;
}
int F_24 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_40 >> 32 )
return - V_30 ;
if ( ( V_8 -> V_3 & V_42 ) == V_6 )
return F_3 ( V_2 , V_8 ) ;
if ( F_11 ( V_8 -> V_3 ) )
return F_16 ( V_2 , V_8 ) ;
return F_25 ( V_2 , V_8 ) ;
}
int F_26 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_40 >> 32 )
return - V_30 ;
if ( ( V_8 -> V_3 & V_42 ) == V_6 )
return F_6 ( V_2 , V_8 ) ;
if ( F_11 ( V_8 -> V_3 ) )
return F_13 ( V_2 , V_8 ) ;
return F_27 ( V_2 , V_8 ) ;
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
int F_32 ( struct V_49 * V_50 )
{
int V_51 = F_30 () ;
if ( V_51 < 0 )
return - V_52 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_51 = ( V_53 ) V_51 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
return - V_30 ;
}
int F_34 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
return - V_30 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
return - V_30 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
return - V_30 ;
}
