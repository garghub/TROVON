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
static int F_11 ( struct V_1 * V_2 , T_1 T_3 * V_29 )
{
return 0 ;
}
static bool F_12 ( T_1 V_30 )
{
return false ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_31 , T_1 V_32 )
{
return 0 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_1 V_31 )
{
return 0 ;
}
static bool F_12 ( T_1 V_30 )
{
switch ( V_30 ) {
case V_33 :
case V_34 :
case V_35 :
return true ;
}
return false ;
}
static int F_11 ( struct V_1 * V_2 , T_1 T_3 * V_29 )
{
if ( F_5 ( V_33 , V_29 ) )
return - V_17 ;
V_29 ++ ;
if ( F_5 ( V_34 , V_29 ) )
return - V_17 ;
V_29 ++ ;
if ( F_5 ( V_35 , V_29 ) )
return - V_17 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
void T_3 * V_9 = ( void T_3 * ) ( long ) V_8 -> V_10 ;
T_1 V_16 ;
int V_36 ;
V_36 = F_16 ( & V_16 , V_9 , F_4 ( V_8 -> V_3 ) ) ;
if ( V_36 != 0 )
return V_36 ;
return F_13 ( V_2 , V_8 -> V_3 , V_16 ) ;
}
static int F_17 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
void T_3 * V_9 = ( void T_3 * ) ( long ) V_8 -> V_10 ;
T_1 V_16 ;
V_16 = F_14 ( V_2 , V_8 -> V_3 ) ;
return F_18 ( V_9 , & V_16 , F_4 ( V_8 -> V_3 ) ) ;
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
int F_22 ( struct V_1 * V_2 , T_1 T_3 * V_29 )
{
unsigned int V_38 ;
const T_1 V_39 = V_40 | V_41 | V_6 ;
int V_36 ;
for ( V_38 = 0 ; V_38 < sizeof( struct V_11 ) / sizeof( T_2 ) ; V_38 ++ ) {
if ( F_5 ( V_39 | V_38 , V_29 ) )
return - V_17 ;
V_29 ++ ;
}
V_36 = F_11 ( V_2 , V_29 ) ;
if ( V_36 )
return V_36 ;
V_29 += V_37 ;
return F_23 ( V_2 , V_29 ) ;
}
int F_24 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_40 >> 32 )
return - V_28 ;
if ( ( V_8 -> V_3 & V_42 ) == V_6 )
return F_3 ( V_2 , V_8 ) ;
if ( F_12 ( V_8 -> V_3 ) )
return F_17 ( V_2 , V_8 ) ;
return F_25 ( V_2 , V_8 ) ;
}
int F_26 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_40 >> 32 )
return - V_28 ;
if ( ( V_8 -> V_3 & V_42 ) == V_6 )
return F_6 ( V_2 , V_8 ) ;
if ( F_12 ( V_8 -> V_3 ) )
return F_15 ( V_2 , V_8 ) ;
return F_27 ( V_2 , V_8 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
return - V_28 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
return - V_28 ;
}
int T_4 F_30 ( void )
{
unsigned long V_45 = F_31 () ;
unsigned long V_46 = F_32 () ;
if ( V_45 != V_47 )
return - V_28 ;
switch ( V_46 ) {
case V_48 :
return V_49 ;
case V_50 :
return V_51 ;
default:
return - V_28 ;
}
}
int F_33 ( struct V_1 * V_2 ,
const struct V_52 * V_53 )
{
unsigned int V_38 ;
if ( V_53 -> V_54 != F_30 () )
return - V_28 ;
V_2 -> V_13 . V_54 = V_53 -> V_54 ;
F_34 ( V_2 -> V_13 . V_55 , V_56 ) ;
for ( V_38 = 0 ; V_38 < sizeof( V_53 -> V_55 ) * 8 ; V_38 ++ ) {
if ( F_35 ( V_38 , ( void * ) V_53 -> V_55 ) ) {
if ( V_38 >= V_56 )
return - V_15 ;
F_36 ( V_38 , V_2 -> V_13 . V_55 ) ;
}
}
return F_37 ( V_2 ) ;
}
int F_38 ( struct V_52 * V_53 )
{
int V_54 = F_30 () ;
if ( V_54 < 0 )
return - V_57 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_54 = ( V_58 ) V_54 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return - V_28 ;
}
int F_40 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return - V_28 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
return - V_28 ;
}
