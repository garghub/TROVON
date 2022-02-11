static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
V_5 = & ( V_2 -> V_6 ) ;
if ( V_2 -> V_7 ) {
struct V_8 * V_9 ;
V_9 = F_2 ( sizeof( struct V_8 ) , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_9 -> V_12 = V_2 -> V_13 ;
V_9 -> V_14 = V_2 -> V_15 ;
V_9 -> V_16 = F_3 ( V_2 ) ;
V_3 = F_4 ( V_9 , V_5 ) ;
F_5 ( V_9 ) ;
} else {
V_5 -> V_17 = ( void * ) V_2 ;
switch ( V_2 -> V_15 ) {
#ifdef F_6
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_5 -> V_23 = & V_24 ;
break;
#endif
#ifdef F_7
case V_25 :
case V_26 :
V_5 -> V_23 = & V_27 ;
break;
case V_28 :
case V_29 :
case V_30 :
V_5 -> V_23 = & V_31 ;
break;
#endif
case V_32 :
case V_33 :
V_5 -> V_23 = & V_34 ;
break;
default:
V_3 = - V_35 ;
break;
}
}
return V_3 ;
}
static int F_8 ( void * V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
int V_3 = 0 ;
switch ( V_2 -> V_15 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
V_2 -> V_7 = true ;
break;
case V_32 :
case V_33 :
V_2 -> V_7 = ( V_43 == 0 ) ? false : true ;
break;
case V_25 :
case V_26 :
case V_28 :
case V_29 :
case V_30 :
default:
V_2 -> V_7 = false ;
break;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_6 . V_23 -> V_44 )
V_3 = V_2 -> V_6 . V_23 -> V_44 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_9 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_45 )
V_3 = V_2 -> V_6 . V_23 -> V_45 (
V_2 -> V_6 . V_17 ) ;
if ( V_2 -> V_7 && V_2 -> V_46 . V_47 ) {
F_10 ( V_2 ) ;
F_11 ( V_2 , V_48 , NULL , NULL ) ;
}
return V_3 ;
}
static int F_12 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_49 )
V_3 = V_2 -> V_6 . V_23 -> V_49 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_13 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_50 )
V_3 = V_2 -> V_6 . V_23 -> V_50 (
V_2 -> V_6 . V_17 ) ;
if ( V_3 )
return V_3 ;
return V_3 ;
}
static int F_14 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_7 && V_2 -> V_51 . V_52 )
F_15 ( V_2 ) ;
if ( V_2 -> V_6 . V_23 -> V_53 )
V_3 = V_2 -> V_6 . V_23 -> V_53 (
V_2 -> V_6 . V_17 ) ;
if ( ( V_54 != 0 ) && ! F_16 ( V_2 ) )
V_2 -> V_46 . V_47 = true ;
return V_3 ;
}
static int F_17 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_55 )
V_3 = V_2 -> V_6 . V_23 -> V_55 (
V_2 -> V_6 . V_17 ) ;
if ( V_2 -> V_7 && V_2 -> V_51 . V_52 )
F_18 ( V_2 ) ;
return V_3 ;
}
static void F_19 ( void * V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_7 ) {
F_20 ( V_2 ) ;
F_21 ( V_2 -> V_6 . V_17 ) ;
}
if ( V_2 -> V_6 . V_23 -> V_56 )
V_2 -> V_6 . V_23 -> V_56 (
V_2 -> V_6 . V_17 ) ;
}
static int F_22 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_57 )
V_3 = V_2 -> V_6 . V_23 -> V_57 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_23 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_58 )
V_3 = V_2 -> V_6 . V_23 -> V_58 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_24 ( void * V_36 ,
enum V_59 V_60 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_61 )
V_3 = V_2 -> V_6 . V_23 -> V_61 (
V_2 -> V_6 . V_17 , V_60 ) ;
return V_3 ;
}
static int F_25 ( void * V_36 ,
enum V_62 V_60 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_63 )
V_3 = V_2 -> V_6 . V_23 -> V_63 (
V_2 -> V_6 . V_17 , V_60 ) ;
return V_3 ;
}
static bool F_26 ( void * V_36 )
{
bool V_3 = true ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_64 )
V_3 = V_2 -> V_6 . V_23 -> V_64 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_27 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_65 )
V_3 = V_2 -> V_6 . V_23 -> V_65 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_28 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_23 -> V_66 )
V_3 = V_2 -> V_6 . V_23 -> V_66 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
