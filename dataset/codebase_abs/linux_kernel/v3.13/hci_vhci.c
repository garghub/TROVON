static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
if ( ! F_5 ( V_3 , & V_2 -> V_4 ) )
return 0 ;
F_6 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
F_6 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
if ( ! F_9 ( V_3 , & V_2 -> V_4 ) )
return - V_10 ;
memcpy ( F_10 ( V_9 , 1 ) , & F_11 ( V_9 ) -> V_11 , 1 ) ;
F_12 ( & V_6 -> V_7 , V_9 ) ;
F_13 ( & V_6 -> V_12 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , T_1 V_13 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_9 = F_15 ( 4 , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
V_2 = F_16 () ;
if ( ! V_2 ) {
F_17 ( V_9 ) ;
return - V_15 ;
}
V_6 -> V_2 = V_2 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_13 = V_13 ;
F_18 ( V_2 , V_6 ) ;
V_2 -> V_18 = F_1 ;
V_2 -> V_19 = F_3 ;
V_2 -> V_20 = F_7 ;
V_2 -> V_21 = F_8 ;
if ( F_19 ( V_2 ) < 0 ) {
F_20 ( L_1 ) ;
F_21 ( V_2 ) ;
V_6 -> V_2 = NULL ;
F_17 ( V_9 ) ;
return - V_10 ;
}
F_11 ( V_9 ) -> V_11 = V_22 ;
* F_22 ( V_9 , 1 ) = 0xff ;
* F_22 ( V_9 , 1 ) = V_13 ;
F_23 ( V_2 -> V_23 , F_22 ( V_9 , 2 ) ) ;
F_12 ( & V_6 -> V_7 , V_9 ) ;
F_13 ( & V_6 -> V_12 ) ;
return 0 ;
}
static inline T_2 F_24 ( struct V_5 * V_6 ,
const char T_3 * V_24 , T_4 V_25 )
{
struct V_8 * V_9 ;
T_1 V_11 , V_13 ;
int V_26 ;
if ( V_25 < 2 || V_25 > V_27 )
return - V_28 ;
V_9 = F_15 ( V_25 , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
if ( F_25 ( F_22 ( V_9 , V_25 ) , V_24 , V_25 ) ) {
F_17 ( V_9 ) ;
return - V_29 ;
}
V_11 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_26 ( V_9 , 1 ) ;
switch ( V_11 ) {
case V_30 :
case V_31 :
case V_32 :
if ( ! V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_33 ;
}
F_11 ( V_9 ) -> V_11 = V_11 ;
V_26 = F_27 ( V_6 -> V_2 , V_9 ) ;
break;
case V_22 :
if ( V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_34 ;
}
F_28 ( & V_6 -> V_35 ) ;
V_13 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_26 ( V_9 , 1 ) ;
if ( V_9 -> V_36 > 0 ) {
F_17 ( V_9 ) ;
return - V_28 ;
}
F_17 ( V_9 ) ;
if ( V_13 != V_37 && V_13 != V_38 )
return - V_28 ;
V_26 = F_14 ( V_6 , V_13 ) ;
break;
default:
F_17 ( V_9 ) ;
return - V_28 ;
}
return ( V_26 < 0 ) ? V_26 : V_25 ;
}
static inline T_2 F_29 ( struct V_5 * V_6 ,
struct V_8 * V_9 ,
char T_3 * V_24 , int V_25 )
{
char T_3 * V_39 = V_24 ;
int V_36 ;
V_36 = F_30 (unsigned int, skb->len, count) ;
if ( F_31 ( V_39 , V_9 -> V_6 , V_36 ) )
return - V_29 ;
if ( ! V_6 -> V_2 )
return V_36 ;
V_6 -> V_2 -> V_40 . V_41 += V_36 ;
switch ( F_11 ( V_9 ) -> V_11 ) {
case V_42 :
V_6 -> V_2 -> V_40 . V_43 ++ ;
break;
case V_31 :
V_6 -> V_2 -> V_40 . V_44 ++ ;
break;
case V_32 :
V_6 -> V_2 -> V_40 . V_45 ++ ;
break;
}
return V_36 ;
}
static T_2 F_32 ( struct V_46 * V_46 ,
char T_3 * V_24 , T_4 V_25 , T_5 * V_47 )
{
struct V_5 * V_6 = V_46 -> V_48 ;
struct V_8 * V_9 ;
T_2 V_26 = 0 ;
while ( V_25 ) {
V_9 = F_33 ( & V_6 -> V_7 ) ;
if ( V_9 ) {
V_26 = F_29 ( V_6 , V_9 , V_24 , V_25 ) ;
if ( V_26 < 0 )
F_34 ( & V_6 -> V_7 , V_9 ) ;
else
F_17 ( V_9 ) ;
break;
}
if ( V_46 -> V_49 & V_50 ) {
V_26 = - V_51 ;
break;
}
V_26 = F_35 ( V_6 -> V_12 ,
! F_36 ( & V_6 -> V_7 ) ) ;
if ( V_26 < 0 )
break;
}
return V_26 ;
}
static T_2 F_37 ( struct V_46 * V_46 ,
const char T_3 * V_24 , T_4 V_25 , T_5 * V_47 )
{
struct V_5 * V_6 = V_46 -> V_48 ;
return F_24 ( V_6 , V_24 , V_25 ) ;
}
static unsigned int F_38 ( struct V_46 * V_46 , T_6 * V_52 )
{
struct V_5 * V_6 = V_46 -> V_48 ;
F_39 ( V_46 , & V_6 -> V_12 , V_52 ) ;
if ( ! F_36 ( & V_6 -> V_7 ) )
return V_53 | V_54 ;
return V_55 | V_56 ;
}
static void F_40 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_41 ( V_58 , struct V_5 ,
V_35 . V_58 ) ;
F_14 ( V_6 , V_59 ? V_38 : V_37 ) ;
}
static int F_42 ( struct V_60 * V_60 , struct V_46 * V_46 )
{
struct V_5 * V_6 ;
V_6 = F_43 ( sizeof( struct V_5 ) , V_14 ) ;
if ( ! V_6 )
return - V_15 ;
F_44 ( & V_6 -> V_7 ) ;
F_45 ( & V_6 -> V_12 ) ;
F_46 ( & V_6 -> V_35 , F_40 ) ;
V_46 -> V_48 = V_6 ;
F_47 ( V_60 , V_46 ) ;
F_48 ( & V_6 -> V_35 , F_49 ( 1000 ) ) ;
return 0 ;
}
static int F_50 ( struct V_60 * V_60 , struct V_46 * V_46 )
{
struct V_5 * V_6 = V_46 -> V_48 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_28 ( & V_6 -> V_35 ) ;
if ( V_2 ) {
F_51 ( V_2 ) ;
F_21 ( V_2 ) ;
}
V_46 -> V_48 = NULL ;
F_52 ( V_6 ) ;
return 0 ;
}
static int T_7 F_53 ( void )
{
F_54 ( L_2 , V_61 ) ;
return F_55 ( & V_62 ) ;
}
static void T_8 F_56 ( void )
{
F_57 ( & V_62 ) ;
}
