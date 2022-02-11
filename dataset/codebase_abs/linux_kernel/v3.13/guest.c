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
static unsigned long F_11 ( void )
{
return sizeof( struct V_11 ) / sizeof( T_2 ) ;
}
unsigned long F_12 ( struct V_1 * V_2 )
{
return F_11 () + F_13 ( V_2 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 T_3 * V_29 )
{
unsigned int V_30 ;
const T_1 V_31 = V_32 | V_33 | V_6 ;
for ( V_30 = 0 ; V_30 < sizeof( struct V_11 ) / sizeof( T_2 ) ; V_30 ++ ) {
if ( F_5 ( V_31 | V_30 , V_29 ) )
return - V_17 ;
V_29 ++ ;
}
return F_15 ( V_2 , V_29 ) ;
}
int F_16 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_32 >> 32 )
return - V_28 ;
if ( ( V_8 -> V_3 & V_34 ) == V_6 )
return F_3 ( V_2 , V_8 ) ;
return F_17 ( V_2 , V_8 ) ;
}
int F_18 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
if ( ( V_8 -> V_3 & ~ V_5 ) >> 32 != V_32 >> 32 )
return - V_28 ;
if ( ( V_8 -> V_3 & V_34 ) == V_6 )
return F_6 ( V_2 , V_8 ) ;
return F_19 ( V_2 , V_8 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
return - V_28 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
return - V_28 ;
}
int T_4 F_22 ( void )
{
unsigned long V_37 = F_23 () ;
unsigned long V_38 = F_24 () ;
if ( V_37 != V_39 )
return - V_28 ;
switch ( V_38 ) {
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
default:
return - V_28 ;
}
}
int F_25 ( struct V_1 * V_2 ,
const struct V_44 * V_45 )
{
unsigned int V_30 ;
if ( V_45 -> V_46 != F_22 () )
return - V_28 ;
V_2 -> V_13 . V_46 = V_45 -> V_46 ;
F_26 ( V_2 -> V_13 . V_47 , V_48 ) ;
for ( V_30 = 0 ; V_30 < sizeof( V_45 -> V_47 ) * 8 ; V_30 ++ ) {
if ( F_27 ( V_30 , ( void * ) V_45 -> V_47 ) ) {
if ( V_30 >= V_48 )
return - V_15 ;
F_28 ( V_30 , V_2 -> V_13 . V_47 ) ;
}
}
return F_29 ( V_2 ) ;
}
int F_30 ( struct V_44 * V_45 )
{
int V_46 = F_22 () ;
if ( V_46 < 0 )
return - V_49 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_46 = ( V_50 ) V_46 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
return - V_28 ;
}
int F_32 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
return - V_28 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
return - V_28 ;
}
