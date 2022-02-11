static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_1 , V_10 , V_2 , V_4 ) ;
V_6 = F_3 ( sizeof( struct V_5 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_6 -> V_13 = 1 ;
F_4 ( & V_6 -> V_14 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_5 ( & V_6 -> V_16 ) ;
V_6 -> V_17 = 0 ;
F_6 ( & V_6 -> V_18 ) ;
V_4 -> V_19 = V_6 ;
return F_7 ( V_2 , V_4 ) ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
struct V_20 * V_21 = & V_6 -> V_14 ;
struct V_22 * V_23 , * V_24 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_1 , V_10 , V_2 , V_4 ) ;
F_9 ( & V_6 -> V_16 ) ;
while ( ! F_10 ( V_21 ) ) {
V_23 = F_11 ( V_21 , struct V_22 , V_21 ) ;
F_12 ( & V_6 -> V_16 ) ;
F_13 ( & V_23 -> V_25 ) ;
F_9 ( & V_6 -> V_16 ) ;
F_14 ( & V_23 -> V_21 ) ;
F_15 ( V_23 ) ;
}
F_12 ( & V_6 -> V_16 ) ;
F_16 (timer, next, &dev->expired, list) {
F_15 ( V_23 ) ;
}
F_15 ( V_6 ) ;
return 0 ;
}
static T_1
F_17 ( struct V_3 * V_4 , char T_2 * V_26 , T_3 V_27 , T_4 * V_28 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
struct V_20 * V_21 = & V_6 -> V_15 ;
struct V_22 * V_23 ;
int V_29 = 0 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_2 , V_10 ,
V_4 , V_26 , ( int ) V_27 , V_28 ) ;
if ( V_27 < sizeof( int ) )
return - V_30 ;
F_9 ( & V_6 -> V_16 ) ;
while ( F_10 ( V_21 ) && ( V_6 -> V_17 == 0 ) ) {
F_12 ( & V_6 -> V_16 ) ;
if ( V_4 -> V_31 & V_32 )
return - V_33 ;
F_18 ( V_6 -> V_18 , ( V_6 -> V_17 ||
! F_10 ( V_21 ) ) ) ;
if ( F_19 ( V_34 ) )
return - V_35 ;
F_9 ( & V_6 -> V_16 ) ;
}
if ( V_6 -> V_17 )
V_6 -> V_17 = 0 ;
if ( ! F_10 ( V_21 ) ) {
V_23 = F_11 ( V_21 , struct V_22 , V_21 ) ;
F_14 ( & V_23 -> V_21 ) ;
F_12 ( & V_6 -> V_16 ) ;
if ( F_20 ( V_23 -> V_36 , ( int T_2 * ) V_26 ) )
V_29 = - V_37 ;
else
V_29 = sizeof( int ) ;
F_15 ( V_23 ) ;
} else {
F_12 ( & V_6 -> V_16 ) ;
}
return V_29 ;
}
static unsigned int
F_21 ( struct V_3 * V_4 , T_5 * V_18 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
unsigned int V_38 = V_39 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_3 , V_10 , V_4 , V_18 ) ;
if ( V_6 ) {
F_22 ( V_4 , & V_6 -> V_18 , V_18 ) ;
V_38 = 0 ;
if ( V_6 -> V_17 || ! F_10 ( & V_6 -> V_15 ) )
V_38 |= ( V_40 | V_41 ) ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_4 , V_10 ,
V_6 -> V_17 , F_10 ( & V_6 -> V_15 ) ) ;
}
return V_38 ;
}
static void
F_23 ( unsigned long V_42 )
{
struct V_22 * V_23 = ( void * ) V_42 ;
T_6 V_43 ;
F_24 ( & V_23 -> V_6 -> V_16 , V_43 ) ;
if ( V_23 -> V_36 >= 0 )
F_25 ( & V_23 -> V_21 , & V_23 -> V_6 -> V_15 ) ;
F_26 ( & V_23 -> V_6 -> V_16 , V_43 ) ;
F_27 ( & V_23 -> V_6 -> V_18 ) ;
}
static int
F_28 ( struct V_5 * V_6 , int V_44 )
{
int V_36 ;
struct V_22 * V_23 ;
if ( ! V_44 ) {
V_6 -> V_17 = 1 ;
F_27 ( & V_6 -> V_18 ) ;
V_36 = 0 ;
} else {
V_23 = F_29 ( sizeof( struct V_22 ) , V_11 ) ;
if ( ! V_23 )
return - V_12 ;
V_23 -> V_6 = V_6 ;
F_30 ( & V_23 -> V_25 , F_23 , ( long ) V_23 ) ;
F_9 ( & V_6 -> V_16 ) ;
V_36 = V_23 -> V_36 = V_6 -> V_13 ++ ;
if ( V_6 -> V_13 < 0 )
V_6 -> V_13 = 1 ;
F_31 ( & V_23 -> V_21 , & V_6 -> V_14 ) ;
V_23 -> V_25 . V_45 = V_46 + ( ( V_47 * ( T_6 ) V_44 ) / 1000 ) ;
F_32 ( & V_23 -> V_25 ) ;
F_12 ( & V_6 -> V_16 ) ;
}
return V_36 ;
}
static int
F_33 ( struct V_5 * V_6 , int V_36 )
{
struct V_22 * V_23 ;
F_9 ( & V_6 -> V_16 ) ;
F_34 (timer, &dev->pending, list) {
if ( V_23 -> V_36 == V_36 ) {
F_35 ( & V_23 -> V_21 ) ;
V_23 -> V_36 = - 1 ;
F_12 ( & V_6 -> V_16 ) ;
F_13 ( & V_23 -> V_25 ) ;
F_15 ( V_23 ) ;
return V_36 ;
}
}
F_12 ( & V_6 -> V_16 ) ;
return 0 ;
}
static long
F_36 ( struct V_3 * V_4 , unsigned int V_48 , unsigned long V_49 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
int V_36 , V_50 , V_29 = 0 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_5 , V_10 ,
V_4 , V_48 , V_49 ) ;
F_37 ( & V_51 ) ;
switch ( V_48 ) {
case V_52 :
if ( F_38 ( V_50 , ( int T_2 * ) V_49 ) ) {
V_29 = - V_37 ;
break;
}
V_36 = F_28 ( V_6 , V_50 ) ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_6 , V_10 ,
V_50 , V_36 ) ;
if ( V_36 < 0 ) {
V_29 = V_36 ;
break;
}
if ( F_20 ( V_36 , ( int T_2 * ) V_49 ) )
V_29 = - V_37 ;
break;
case V_53 :
if ( F_38 ( V_36 , ( int T_2 * ) V_49 ) ) {
V_29 = - V_37 ;
break;
}
if ( * V_7 & V_8 )
F_2 ( V_9 L_7 , V_10 , V_36 ) ;
V_36 = F_33 ( V_6 , V_36 ) ;
if ( F_20 ( V_36 , ( int T_2 * ) V_49 ) )
V_29 = - V_37 ;
break;
default:
V_29 = - V_54 ;
}
F_39 ( & V_51 ) ;
return V_29 ;
}
int
F_40 ( T_7 * V_55 )
{
int V_56 ;
V_7 = V_55 ;
V_56 = F_41 ( & V_22 ) ;
if ( V_56 )
F_2 ( V_57 L_8 ) ;
return V_56 ;
}
void F_42 ( void )
{
F_43 ( & V_22 ) ;
}
