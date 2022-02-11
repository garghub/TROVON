static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
V_5 = & ( V_2 -> V_6 ) ;
if ( V_2 -> V_7 ) {
#ifdef F_2
struct V_8 * V_9 ;
V_9 = F_3 ( sizeof( struct V_8 ) , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_9 -> V_12 = V_2 -> V_13 ;
V_9 -> V_14 = V_2 -> V_15 ;
V_9 -> V_16 = F_4 ( V_2 ) ;
V_3 = F_5 ( V_9 , V_5 ) ;
F_6 ( V_9 ) ;
#endif
} else {
V_5 -> V_17 = ( void * ) V_2 ;
switch ( V_2 -> V_15 ) {
#ifdef F_7
case V_18 :
case V_19 :
V_5 -> V_20 = & V_21 ;
break;
case V_22 :
case V_23 :
case V_24 :
V_5 -> V_20 = & V_25 ;
break;
#endif
case V_26 :
V_5 -> V_20 = & V_27 ;
break;
case V_28 :
V_5 -> V_20 = & V_29 ;
break;
case V_30 :
V_5 -> V_20 = & V_31 ;
break;
case V_32 :
case V_33 :
V_5 -> V_20 = & V_34 ;
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
#ifdef F_2
switch ( V_2 -> V_15 ) {
case V_37 :
case V_38 :
V_2 -> V_7 = true ;
break;
case V_28 :
case V_30 :
V_2 -> V_7 = ( V_39 == 0 ) ? false : true ;
break;
case V_32 :
case V_33 :
V_2 -> V_7 = ( V_39 > 0 ) ? true : false ;
break;
case V_18 :
case V_19 :
case V_22 :
case V_23 :
case V_24 :
case V_26 :
default:
V_2 -> V_7 = false ;
break;
}
#else
V_2 -> V_7 = false ;
#endif
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_6 . V_20 -> V_40 )
V_3 = V_2 -> V_6 . V_20 -> V_40 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_9 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_41 )
V_3 = V_2 -> V_6 . V_20 -> V_41 (
V_2 -> V_6 . V_17 ) ;
#ifdef F_2
if ( V_2 -> V_7 && V_2 -> V_42 . V_43 ) {
F_10 ( V_2 ) ;
F_11 ( V_2 , V_44 , NULL , NULL ) ;
}
#endif
return V_3 ;
}
static int F_12 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_45 )
V_3 = V_2 -> V_6 . V_20 -> V_45 (
V_2 -> V_6 . V_17 ) ;
#ifdef F_2
if ( V_2 -> V_7 )
V_2 -> V_42 . V_43 = true ;
#endif
return V_3 ;
}
static int F_13 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_46 )
V_3 = V_2 -> V_6 . V_20 -> V_46 (
V_2 -> V_6 . V_17 ) ;
if ( V_3 )
return V_3 ;
return V_3 ;
}
static int F_14 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_7 && V_2 -> V_47 . V_48 )
F_15 ( V_2 ) ;
if ( V_2 -> V_6 . V_20 -> V_49 )
V_3 = V_2 -> V_6 . V_20 -> V_49 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_16 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_50 )
V_3 = V_2 -> V_6 . V_20 -> V_50 (
V_2 -> V_6 . V_17 ) ;
if ( V_2 -> V_7 && V_2 -> V_47 . V_48 )
F_17 ( V_2 ) ;
return V_3 ;
}
static void F_18 ( void * V_36 )
{
#ifdef F_2
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_7 ) {
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_6 . V_17 ) ;
}
if ( V_2 -> V_6 . V_20 -> V_51 )
V_2 -> V_6 . V_20 -> V_51 (
V_2 -> V_6 . V_17 ) ;
#endif
}
static int F_21 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_52 )
V_3 = V_2 -> V_6 . V_20 -> V_52 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_22 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_53 )
V_3 = V_2 -> V_6 . V_20 -> V_53 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_23 ( void * V_36 ,
enum V_54 V_55 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_56 )
V_3 = V_2 -> V_6 . V_20 -> V_56 (
V_2 -> V_6 . V_17 , V_55 ) ;
return V_3 ;
}
static int F_24 ( void * V_36 ,
enum V_57 V_55 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_58 )
V_3 = V_2 -> V_6 . V_20 -> V_58 (
V_2 -> V_6 . V_17 , V_55 ) ;
return V_3 ;
}
static bool F_25 ( void * V_36 )
{
bool V_3 = true ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_59 )
V_3 = V_2 -> V_6 . V_20 -> V_59 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_26 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_60 )
V_3 = V_2 -> V_6 . V_20 -> V_60 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
static int F_27 ( void * V_36 )
{
int V_3 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( V_2 -> V_6 . V_20 -> V_61 )
V_3 = V_2 -> V_6 . V_20 -> V_61 (
V_2 -> V_6 . V_17 ) ;
return V_3 ;
}
