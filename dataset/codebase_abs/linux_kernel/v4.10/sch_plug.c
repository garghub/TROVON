static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_1 * * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( F_3 ( V_4 -> V_8 . V_9 + V_2 -> V_10 <= V_7 -> V_11 ) ) {
if ( ! V_7 -> V_12 )
V_7 -> V_13 ++ ;
return F_4 ( V_2 , V_4 ) ;
}
return F_5 ( V_2 , V_4 , V_5 ) ;
}
static struct V_1 * F_6 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_7 -> V_14 )
return NULL ;
if ( ! V_7 -> V_12 ) {
if ( ! V_7 -> V_15 ) {
V_7 -> V_14 = true ;
return NULL ;
}
V_7 -> V_15 -- ;
}
return F_7 ( V_4 ) ;
}
static int F_8 ( struct V_3 * V_4 , struct V_16 * V_17 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_13 = 0 ;
V_7 -> V_18 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_12 = false ;
if ( V_17 == NULL ) {
V_7 -> V_11 = F_9 ( V_4 ) -> V_19
* F_10 ( F_9 ( V_4 ) ) ;
} else {
struct V_20 * V_21 = F_11 ( V_17 ) ;
if ( F_12 ( V_17 ) < sizeof( * V_21 ) )
return - V_22 ;
V_7 -> V_11 = V_21 -> V_11 ;
}
V_7 -> V_14 = true ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , struct V_16 * V_17 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_20 * V_23 ;
if ( V_17 == NULL )
return - V_22 ;
V_23 = F_11 ( V_17 ) ;
if ( F_12 ( V_17 ) < sizeof( * V_23 ) )
return - V_22 ;
switch ( V_23 -> V_24 ) {
case V_25 :
V_7 -> V_18 = V_7 -> V_13 ;
V_7 -> V_13 = 0 ;
if ( V_7 -> V_12 )
V_7 -> V_14 = true ;
V_7 -> V_12 = false ;
break;
case V_26 :
V_7 -> V_15 += V_7 -> V_18 ;
V_7 -> V_18 = 0 ;
V_7 -> V_14 = false ;
F_14 ( V_4 -> V_27 ) ;
break;
case V_28 :
V_7 -> V_12 = true ;
V_7 -> V_15 = 0 ;
V_7 -> V_18 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = false ;
F_14 ( V_4 -> V_27 ) ;
break;
case V_29 :
V_7 -> V_11 = V_23 -> V_11 ;
break;
default:
return - V_22 ;
}
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_30 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_30 ) ;
}
