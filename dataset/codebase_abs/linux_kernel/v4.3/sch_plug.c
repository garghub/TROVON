static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( F_3 ( V_4 -> V_7 . V_8 + V_2 -> V_9 <= V_6 -> V_10 ) ) {
if ( ! V_6 -> V_11 )
V_6 -> V_12 ++ ;
return F_4 ( V_2 , V_4 ) ;
}
return F_5 ( V_2 , V_4 ) ;
}
static struct V_1 * F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( F_7 ( V_4 ) )
return NULL ;
if ( ! V_6 -> V_11 ) {
if ( ! V_6 -> V_13 ) {
F_8 ( V_4 ) ;
return NULL ;
}
V_6 -> V_13 -- ;
}
return F_9 ( V_4 ) ;
}
static int F_10 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_12 = 0 ;
V_6 -> V_16 = 0 ;
V_6 -> V_13 = 0 ;
V_6 -> V_11 = false ;
if ( V_15 == NULL ) {
V_6 -> V_10 = F_11 ( V_4 ) -> V_17
* F_12 ( F_11 ( V_4 ) ) ;
} else {
struct V_18 * V_19 = F_13 ( V_15 ) ;
if ( F_14 ( V_15 ) < sizeof( * V_19 ) )
return - V_20 ;
V_6 -> V_10 = V_19 -> V_10 ;
}
F_8 ( V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_18 * V_21 ;
if ( V_15 == NULL )
return - V_20 ;
V_21 = F_13 ( V_15 ) ;
if ( F_14 ( V_15 ) < sizeof( * V_21 ) )
return - V_20 ;
switch ( V_21 -> V_22 ) {
case V_23 :
V_6 -> V_16 = V_6 -> V_12 ;
V_6 -> V_12 = 0 ;
if ( V_6 -> V_11 )
F_8 ( V_4 ) ;
V_6 -> V_11 = false ;
break;
case V_24 :
V_6 -> V_13 += V_6 -> V_16 ;
V_6 -> V_16 = 0 ;
F_16 ( V_4 ) ;
F_17 ( V_4 -> V_25 ) ;
break;
case V_26 :
V_6 -> V_11 = true ;
V_6 -> V_13 = 0 ;
V_6 -> V_16 = 0 ;
V_6 -> V_12 = 0 ;
F_16 ( V_4 ) ;
F_17 ( V_4 -> V_25 ) ;
break;
case V_27 :
V_6 -> V_10 = V_21 -> V_10 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_28 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_28 ) ;
}
