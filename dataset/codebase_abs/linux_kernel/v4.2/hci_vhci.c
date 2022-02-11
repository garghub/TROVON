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
T_1 V_14 ;
V_14 = V_13 & 0x03 ;
if ( V_14 != V_15 && V_14 != V_16 )
return - V_17 ;
if ( V_13 & 0x3c )
return - V_17 ;
V_9 = F_15 ( 4 , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
V_2 = F_16 () ;
if ( ! V_2 ) {
F_17 ( V_9 ) ;
return - V_19 ;
}
V_6 -> V_2 = V_2 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_14 = V_14 ;
F_18 ( V_2 , V_6 ) ;
V_2 -> V_22 = F_1 ;
V_2 -> V_23 = F_3 ;
V_2 -> V_24 = F_7 ;
V_2 -> V_25 = F_8 ;
if ( V_13 & 0x40 )
F_2 ( V_26 , & V_2 -> V_27 ) ;
if ( V_13 & 0x80 )
F_2 ( V_28 , & V_2 -> V_27 ) ;
if ( F_19 ( V_2 ) < 0 ) {
F_20 ( L_1 ) ;
F_21 ( V_2 ) ;
V_6 -> V_2 = NULL ;
F_17 ( V_9 ) ;
return - V_10 ;
}
F_11 ( V_9 ) -> V_11 = V_29 ;
* F_22 ( V_9 , 1 ) = 0xff ;
* F_22 ( V_9 , 1 ) = V_13 ;
F_23 ( V_2 -> V_30 , F_22 ( V_9 , 2 ) ) ;
F_12 ( & V_6 -> V_7 , V_9 ) ;
F_13 ( & V_6 -> V_12 ) ;
return 0 ;
}
static inline T_2 F_24 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
T_3 V_33 = F_25 ( V_32 ) ;
struct V_8 * V_9 ;
T_1 V_11 , V_13 ;
int V_34 ;
if ( V_33 < 2 || V_33 > V_35 )
return - V_17 ;
V_9 = F_15 ( V_33 , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
if ( F_26 ( F_22 ( V_9 , V_33 ) , V_33 , V_32 ) != V_33 ) {
F_17 ( V_9 ) ;
return - V_36 ;
}
V_11 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_27 ( V_9 , 1 ) ;
switch ( V_11 ) {
case V_37 :
case V_38 :
case V_39 :
if ( ! V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_40 ;
}
F_11 ( V_9 ) -> V_11 = V_11 ;
V_34 = F_28 ( V_6 -> V_2 , V_9 ) ;
break;
case V_29 :
if ( V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_41 ;
}
F_29 ( & V_6 -> V_42 ) ;
V_13 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_27 ( V_9 , 1 ) ;
if ( V_9 -> V_33 > 0 ) {
F_17 ( V_9 ) ;
return - V_17 ;
}
F_17 ( V_9 ) ;
V_34 = F_14 ( V_6 , V_13 ) ;
break;
default:
F_17 ( V_9 ) ;
return - V_17 ;
}
return ( V_34 < 0 ) ? V_34 : V_33 ;
}
static inline T_2 F_30 ( struct V_5 * V_6 ,
struct V_8 * V_9 ,
char T_4 * V_43 , int V_44 )
{
char T_4 * V_45 = V_43 ;
int V_33 ;
V_33 = F_31 (unsigned int, skb->len, count) ;
if ( F_32 ( V_45 , V_9 -> V_6 , V_33 ) )
return - V_36 ;
if ( ! V_6 -> V_2 )
return V_33 ;
V_6 -> V_2 -> V_46 . V_47 += V_33 ;
switch ( F_11 ( V_9 ) -> V_11 ) {
case V_48 :
V_6 -> V_2 -> V_46 . V_49 ++ ;
break;
case V_38 :
V_6 -> V_2 -> V_46 . V_50 ++ ;
break;
case V_39 :
V_6 -> V_2 -> V_46 . V_51 ++ ;
break;
}
return V_33 ;
}
static T_2 F_33 ( struct V_52 * V_52 ,
char T_4 * V_43 , T_3 V_44 , T_5 * V_53 )
{
struct V_5 * V_6 = V_52 -> V_54 ;
struct V_8 * V_9 ;
T_2 V_34 = 0 ;
while ( V_44 ) {
V_9 = F_34 ( & V_6 -> V_7 ) ;
if ( V_9 ) {
V_34 = F_30 ( V_6 , V_9 , V_43 , V_44 ) ;
if ( V_34 < 0 )
F_35 ( & V_6 -> V_7 , V_9 ) ;
else
F_17 ( V_9 ) ;
break;
}
if ( V_52 -> V_55 & V_56 ) {
V_34 = - V_57 ;
break;
}
V_34 = F_36 ( V_6 -> V_12 ,
! F_37 ( & V_6 -> V_7 ) ) ;
if ( V_34 < 0 )
break;
}
return V_34 ;
}
static T_2 F_38 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_52 * V_52 = V_59 -> V_60 ;
struct V_5 * V_6 = V_52 -> V_54 ;
return F_24 ( V_6 , V_32 ) ;
}
static unsigned int F_39 ( struct V_52 * V_52 , T_6 * V_61 )
{
struct V_5 * V_6 = V_52 -> V_54 ;
F_40 ( V_52 , & V_6 -> V_12 , V_61 ) ;
if ( ! F_37 ( & V_6 -> V_7 ) )
return V_62 | V_63 ;
return V_64 | V_65 ;
}
static void F_41 ( struct V_66 * V_67 )
{
struct V_5 * V_6 = F_42 ( V_67 , struct V_5 ,
V_42 . V_67 ) ;
F_14 ( V_6 , V_68 ? V_16 : V_15 ) ;
}
static int F_43 ( struct V_69 * V_69 , struct V_52 * V_52 )
{
struct V_5 * V_6 ;
V_6 = F_44 ( sizeof( struct V_5 ) , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
F_45 ( & V_6 -> V_7 ) ;
F_46 ( & V_6 -> V_12 ) ;
F_47 ( & V_6 -> V_42 , F_41 ) ;
V_52 -> V_54 = V_6 ;
F_48 ( V_69 , V_52 ) ;
F_49 ( & V_6 -> V_42 , F_50 ( 1000 ) ) ;
return 0 ;
}
static int F_51 ( struct V_69 * V_69 , struct V_52 * V_52 )
{
struct V_5 * V_6 = V_52 -> V_54 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_29 ( & V_6 -> V_42 ) ;
if ( V_2 ) {
F_52 ( V_2 ) ;
F_21 ( V_2 ) ;
}
V_52 -> V_54 = NULL ;
F_53 ( V_6 ) ;
return 0 ;
}
static int T_7 F_54 ( void )
{
F_55 ( L_2 , V_70 ) ;
return F_56 ( & V_71 ) ;
}
static void T_8 F_57 ( void )
{
F_58 ( & V_71 ) ;
}
