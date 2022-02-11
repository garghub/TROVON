static int F_1 ( unsigned char V_1 )
{
return F_2 ( V_2 , V_1 ,
V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_6 + 1 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
return F_1 ( 0 ) ;
}
static int F_5 ( struct V_4 * V_5 , int V_7 )
{
if ( V_7 < 0 || V_7 > 30 ) {
F_6 ( V_5 -> V_8 . V_9 ,
L_1 ) ;
return - V_10 ;
}
V_5 -> V_6 = V_7 ;
return F_3 ( V_5 ) ;
}
static T_1 F_7 ( struct V_11 * V_11 ,
const char T_2 * V_12 , T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_5 = V_11 -> V_15 ;
if ( V_13 )
F_3 ( V_5 ) ;
return V_13 ;
}
static long F_8 ( struct V_11 * V_11 ,
unsigned int V_16 , unsigned long V_17 )
{
void T_2 * V_18 = ( void T_2 * ) V_17 ;
int T_2 * V_19 = V_18 ;
int V_20 ;
struct V_4 * V_5 = V_11 -> V_15 ;
static const struct V_21 V_22 = {
. V_23 = L_2 ,
. V_24 = V_25 ,
. V_26 = 0 ,
} ;
switch ( V_16 ) {
case V_27 :
return F_9 ( V_18 , & V_22 ,
sizeof( V_22 ) ) ? - V_28 : 0 ;
case V_29 :
case V_30 :
return F_10 ( 0 , V_19 ) ;
case V_31 :
F_3 ( V_5 ) ;
break;
case V_32 :
if ( F_11 ( V_20 , V_19 ) )
return - V_28 ;
if ( F_5 ( V_5 , V_20 ) )
return - V_10 ;
return F_10 ( V_5 -> V_6 , V_19 ) ;
case V_33 :
return F_10 ( V_5 -> V_6 , V_19 ) ;
default:
return - V_34 ;
}
return 0 ;
}
static int F_12 ( struct V_35 * V_35 , struct V_11 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_36 ) ;
if ( F_14 ( 0 , & V_5 -> V_37 ) )
return - V_38 ;
V_5 -> V_37 |= V_39 ;
V_11 -> V_15 = ( void * ) V_5 ;
F_3 ( V_5 ) ;
return F_15 ( V_35 , V_11 ) ;
}
static int F_16 ( struct V_35 * V_35 , struct V_11 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_15 ;
if ( V_40 ) {
F_17 ( V_5 -> V_8 . V_9 ,
L_3 ) ;
F_3 ( V_5 ) ;
} else {
if ( F_4 ( V_5 ) )
return - V_28 ;
V_5 -> V_37 &= ~ V_39 ;
}
F_18 ( 0 , & V_5 -> V_37 ) ;
return 0 ;
}
static int T_5 F_19 ( struct V_41 * V_42 )
{
int V_43 = 0 ;
struct V_4 * V_5 ;
V_5 = F_20 ( sizeof( struct V_4 ) , V_44 ) ;
if ( ! V_5 )
return - V_45 ;
V_5 -> V_37 = 0 ;
V_5 -> V_6 = 30 ;
V_5 -> V_8 . V_9 = & V_42 -> V_46 ;
V_5 -> V_8 . V_47 = & V_48 ;
V_5 -> V_8 . V_49 = V_50 ;
V_5 -> V_8 . V_51 = L_4 ;
F_21 ( V_42 , V_5 ) ;
V_36 = V_42 ;
F_4 ( V_5 ) ;
V_43 = F_22 ( & V_5 -> V_8 ) ;
if ( V_43 ) {
F_23 ( V_5 -> V_8 . V_9 ,
L_5 ) ;
F_21 ( V_42 , NULL ) ;
F_24 ( V_5 ) ;
V_36 = NULL ;
return V_43 ;
}
return 0 ;
}
static int T_6 F_25 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = F_13 ( V_42 ) ;
if ( V_5 -> V_37 & V_39 )
if ( F_4 ( V_5 ) )
return - V_28 ;
V_5 -> V_37 &= ~ V_39 ;
F_26 ( & V_5 -> V_8 ) ;
F_21 ( V_42 , NULL ) ;
F_24 ( V_5 ) ;
V_36 = NULL ;
return 0 ;
}
static int F_27 ( struct V_41 * V_42 , T_7 V_37 )
{
struct V_4 * V_5 = F_13 ( V_42 ) ;
if ( V_5 -> V_37 & V_39 )
return F_4 ( V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = F_13 ( V_42 ) ;
if ( V_5 -> V_37 & V_39 )
return F_3 ( V_5 ) ;
return 0 ;
}
