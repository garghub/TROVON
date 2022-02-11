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
F_7 ( V_20 ) ;
return F_8 ( V_2 , V_4 ) ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
struct V_21 * V_22 , * V_23 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_1 , V_10 , V_2 , V_4 ) ;
F_10 (timer, next, &dev->pending, list) {
F_11 ( & V_22 -> V_24 ) ;
F_12 ( V_22 ) ;
}
F_10 (timer, next, &dev->expired, list) {
F_12 ( V_22 ) ;
}
F_12 ( V_6 ) ;
F_13 ( V_20 ) ;
return 0 ;
}
static T_1
F_14 ( struct V_3 * V_4 , char T_2 * V_25 , T_3 V_26 , T_4 * V_27 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
struct V_21 * V_22 ;
T_5 V_28 ;
int V_29 = 0 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_2 , V_10 ,
V_4 , V_25 , ( int ) V_26 , V_27 ) ;
if ( F_15 ( & V_6 -> V_15 ) && ( V_6 -> V_17 == 0 ) ) {
if ( V_4 -> V_30 & V_31 )
return - V_32 ;
F_16 ( V_6 -> V_18 , ( V_6 -> V_17 ||
! F_15 ( & V_6 -> V_15 ) ) ) ;
if ( F_17 ( V_33 ) )
return - V_34 ;
}
if ( V_26 < sizeof( int ) )
return - V_35 ;
if ( V_6 -> V_17 )
V_6 -> V_17 = 0 ;
if ( ! F_15 ( & V_6 -> V_15 ) ) {
F_18 ( & V_6 -> V_16 , V_28 ) ;
V_22 = (struct V_21 * ) V_6 -> V_15 . V_23 ;
F_19 ( & V_22 -> V_36 ) ;
F_20 ( & V_6 -> V_16 , V_28 ) ;
if ( F_21 ( V_22 -> V_37 , ( int T_2 * ) V_25 ) )
V_29 = - V_38 ;
else
V_29 = sizeof( int ) ;
F_12 ( V_22 ) ;
}
return V_29 ;
}
static unsigned int
F_22 ( struct V_3 * V_4 , T_6 * V_18 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
unsigned int V_39 = V_40 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_3 , V_10 , V_4 , V_18 ) ;
if ( V_6 ) {
F_23 ( V_4 , & V_6 -> V_18 , V_18 ) ;
V_39 = 0 ;
if ( V_6 -> V_17 || ! F_15 ( & V_6 -> V_15 ) )
V_39 |= ( V_41 | V_42 ) ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_4 , V_10 ,
V_6 -> V_17 , F_15 ( & V_6 -> V_15 ) ) ;
}
return V_39 ;
}
static void
F_24 ( unsigned long V_43 )
{
struct V_21 * V_22 = ( void * ) V_43 ;
T_5 V_28 ;
F_18 ( & V_22 -> V_6 -> V_16 , V_28 ) ;
F_25 ( & V_22 -> V_36 , & V_22 -> V_6 -> V_15 ) ;
F_20 ( & V_22 -> V_6 -> V_16 , V_28 ) ;
F_26 ( & V_22 -> V_6 -> V_18 ) ;
}
static int
F_27 ( struct V_5 * V_6 , int V_44 )
{
int V_37 ;
T_5 V_28 ;
struct V_21 * V_22 ;
if ( ! V_44 ) {
V_6 -> V_17 = 1 ;
F_26 ( & V_6 -> V_18 ) ;
V_37 = 0 ;
} else {
V_22 = F_28 ( sizeof( struct V_21 ) , V_11 ) ;
if ( ! V_22 )
return - V_12 ;
F_18 ( & V_6 -> V_16 , V_28 ) ;
V_22 -> V_37 = V_6 -> V_13 ++ ;
if ( V_6 -> V_13 < 0 )
V_6 -> V_13 = 1 ;
F_29 ( & V_22 -> V_36 , & V_6 -> V_14 ) ;
F_20 ( & V_6 -> V_16 , V_28 ) ;
V_22 -> V_6 = V_6 ;
V_22 -> V_24 . V_43 = ( long ) V_22 ;
V_22 -> V_24 . V_45 = F_24 ;
F_30 ( & V_22 -> V_24 ) ;
V_22 -> V_24 . V_46 = V_47 + ( ( V_48 * ( T_5 ) V_44 ) / 1000 ) ;
F_31 ( & V_22 -> V_24 ) ;
V_37 = V_22 -> V_37 ;
}
return V_37 ;
}
static int
F_32 ( struct V_5 * V_6 , int V_37 )
{
T_5 V_28 ;
struct V_21 * V_22 ;
int V_29 = 0 ;
F_18 ( & V_6 -> V_16 , V_28 ) ;
F_33 (timer, &dev->pending, list) {
if ( V_22 -> V_37 == V_37 ) {
F_34 ( & V_22 -> V_36 ) ;
F_11 ( & V_22 -> V_24 ) ;
V_29 = V_22 -> V_37 ;
F_12 ( V_22 ) ;
goto V_49;
}
}
V_49:
F_20 ( & V_6 -> V_16 , V_28 ) ;
return V_29 ;
}
static long
F_35 ( struct V_3 * V_4 , unsigned int V_50 , unsigned long V_51 )
{
struct V_5 * V_6 = V_4 -> V_19 ;
int V_37 , V_52 , V_29 = 0 ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_5 , V_10 ,
V_4 , V_50 , V_51 ) ;
F_36 ( & V_53 ) ;
switch ( V_50 ) {
case V_54 :
if ( F_37 ( V_52 , ( int T_2 * ) V_51 ) ) {
V_29 = - V_38 ;
break;
}
V_37 = F_27 ( V_6 , V_52 ) ;
if ( * V_7 & V_8 )
F_2 ( V_9 L_6 , V_10 ,
V_52 , V_37 ) ;
if ( V_37 < 0 ) {
V_29 = V_37 ;
break;
}
if ( F_21 ( V_37 , ( int T_2 * ) V_51 ) )
V_29 = - V_38 ;
break;
case V_55 :
if ( F_37 ( V_37 , ( int T_2 * ) V_51 ) ) {
V_29 = - V_38 ;
break;
}
if ( * V_7 & V_8 )
F_2 ( V_9 L_7 , V_10 , V_37 ) ;
V_37 = F_32 ( V_6 , V_37 ) ;
if ( F_21 ( V_37 , ( int T_2 * ) V_51 ) )
V_29 = - V_38 ;
break;
default:
V_29 = - V_56 ;
}
F_38 ( & V_53 ) ;
return V_29 ;
}
int
F_39 ( T_7 * V_57 )
{
int V_58 ;
V_7 = V_57 ;
V_58 = F_40 ( & V_21 ) ;
if ( V_58 )
F_2 ( V_59 L_8 ) ;
return V_58 ;
}
void F_41 ( void )
{
F_42 ( & V_21 ) ;
}
