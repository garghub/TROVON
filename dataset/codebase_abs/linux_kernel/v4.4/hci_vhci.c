static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_4 ( & V_4 -> V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_4 ( & V_4 -> V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
memcpy ( F_7 ( V_7 , 1 ) , & F_8 ( V_7 ) -> V_8 , 1 ) ;
F_9 ( & V_4 -> V_5 , V_7 ) ;
F_10 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 , T_1 V_10 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_1 V_11 ;
V_11 = V_10 & 0x03 ;
if ( V_11 != V_12 && V_11 != V_13 )
return - V_14 ;
if ( V_10 & 0x3c )
return - V_14 ;
V_7 = F_12 ( 4 , V_15 ) ;
if ( ! V_7 )
return - V_16 ;
V_2 = F_13 () ;
if ( ! V_2 ) {
F_14 ( V_7 ) ;
return - V_16 ;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_11 = V_11 ;
F_15 ( V_2 , V_4 ) ;
V_2 -> V_19 = F_1 ;
V_2 -> V_20 = F_2 ;
V_2 -> V_21 = F_5 ;
V_2 -> V_22 = F_6 ;
if ( V_10 & 0x40 )
F_16 ( V_23 , & V_2 -> V_24 ) ;
if ( V_10 & 0x80 )
F_16 ( V_25 , & V_2 -> V_24 ) ;
if ( F_17 ( V_2 ) < 0 ) {
F_18 ( L_1 ) ;
F_19 ( V_2 ) ;
V_4 -> V_2 = NULL ;
F_14 ( V_7 ) ;
return - V_26 ;
}
F_8 ( V_7 ) -> V_8 = V_27 ;
* F_20 ( V_7 , 1 ) = 0xff ;
* F_20 ( V_7 , 1 ) = V_10 ;
F_21 ( V_2 -> V_28 , F_20 ( V_7 , 2 ) ) ;
F_9 ( & V_4 -> V_5 , V_7 ) ;
F_10 ( & V_4 -> V_9 ) ;
return 0 ;
}
static inline T_2 F_22 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
T_3 V_31 = F_23 ( V_30 ) ;
struct V_6 * V_7 ;
T_1 V_8 , V_10 ;
int V_32 ;
if ( V_31 < 2 || V_31 > V_33 )
return - V_14 ;
V_7 = F_12 ( V_31 , V_15 ) ;
if ( ! V_7 )
return - V_16 ;
if ( F_24 ( F_20 ( V_7 , V_31 ) , V_31 , V_30 ) != V_31 ) {
F_14 ( V_7 ) ;
return - V_34 ;
}
V_8 = * ( ( T_1 * ) V_7 -> V_4 ) ;
F_25 ( V_7 , 1 ) ;
switch ( V_8 ) {
case V_35 :
case V_36 :
case V_37 :
if ( ! V_4 -> V_2 ) {
F_14 ( V_7 ) ;
return - V_38 ;
}
F_8 ( V_7 ) -> V_8 = V_8 ;
V_32 = F_26 ( V_4 -> V_2 , V_7 ) ;
break;
case V_27 :
if ( V_4 -> V_2 ) {
F_14 ( V_7 ) ;
return - V_39 ;
}
F_27 ( & V_4 -> V_40 ) ;
V_10 = * ( ( T_1 * ) V_7 -> V_4 ) ;
F_25 ( V_7 , 1 ) ;
if ( V_7 -> V_31 > 0 ) {
F_14 ( V_7 ) ;
return - V_14 ;
}
F_14 ( V_7 ) ;
V_32 = F_11 ( V_4 , V_10 ) ;
break;
default:
F_14 ( V_7 ) ;
return - V_14 ;
}
return ( V_32 < 0 ) ? V_32 : V_31 ;
}
static inline T_2 F_28 ( struct V_3 * V_4 ,
struct V_6 * V_7 ,
char T_4 * V_41 , int V_42 )
{
char T_4 * V_43 = V_41 ;
int V_31 ;
V_31 = F_29 (unsigned int, skb->len, count) ;
if ( F_30 ( V_43 , V_7 -> V_4 , V_31 ) )
return - V_34 ;
if ( ! V_4 -> V_2 )
return V_31 ;
V_4 -> V_2 -> V_44 . V_45 += V_31 ;
switch ( F_8 ( V_7 ) -> V_8 ) {
case V_46 :
V_4 -> V_2 -> V_44 . V_47 ++ ;
break;
case V_36 :
V_4 -> V_2 -> V_44 . V_48 ++ ;
break;
case V_37 :
V_4 -> V_2 -> V_44 . V_49 ++ ;
break;
}
return V_31 ;
}
static T_2 F_31 ( struct V_50 * V_50 ,
char T_4 * V_41 , T_3 V_42 , T_5 * V_51 )
{
struct V_3 * V_4 = V_50 -> V_52 ;
struct V_6 * V_7 ;
T_2 V_32 = 0 ;
while ( V_42 ) {
V_7 = F_32 ( & V_4 -> V_5 ) ;
if ( V_7 ) {
V_32 = F_28 ( V_4 , V_7 , V_41 , V_42 ) ;
if ( V_32 < 0 )
F_33 ( & V_4 -> V_5 , V_7 ) ;
else
F_14 ( V_7 ) ;
break;
}
if ( V_50 -> V_53 & V_54 ) {
V_32 = - V_55 ;
break;
}
V_32 = F_34 ( V_4 -> V_9 ,
! F_35 ( & V_4 -> V_5 ) ) ;
if ( V_32 < 0 )
break;
}
return V_32 ;
}
static T_2 F_36 ( struct V_56 * V_57 , struct V_29 * V_30 )
{
struct V_50 * V_50 = V_57 -> V_58 ;
struct V_3 * V_4 = V_50 -> V_52 ;
return F_22 ( V_4 , V_30 ) ;
}
static unsigned int F_37 ( struct V_50 * V_50 , T_6 * V_59 )
{
struct V_3 * V_4 = V_50 -> V_52 ;
F_38 ( V_50 , & V_4 -> V_9 , V_59 ) ;
if ( ! F_35 ( & V_4 -> V_5 ) )
return V_60 | V_61 ;
return V_62 | V_63 ;
}
static void F_39 ( struct V_64 * V_65 )
{
struct V_3 * V_4 = F_40 ( V_65 , struct V_3 ,
V_40 . V_65 ) ;
F_11 ( V_4 , V_66 ? V_13 : V_12 ) ;
}
static int F_41 ( struct V_67 * V_67 , struct V_50 * V_50 )
{
struct V_3 * V_4 ;
V_4 = F_42 ( sizeof( struct V_3 ) , V_15 ) ;
if ( ! V_4 )
return - V_16 ;
F_43 ( & V_4 -> V_5 ) ;
F_44 ( & V_4 -> V_9 ) ;
F_45 ( & V_4 -> V_40 , F_39 ) ;
V_50 -> V_52 = V_4 ;
F_46 ( V_67 , V_50 ) ;
F_47 ( & V_4 -> V_40 , F_48 ( 1000 ) ) ;
return 0 ;
}
static int F_49 ( struct V_67 * V_67 , struct V_50 * V_50 )
{
struct V_3 * V_4 = V_50 -> V_52 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_27 ( & V_4 -> V_40 ) ;
if ( V_2 ) {
F_50 ( V_2 ) ;
F_19 ( V_2 ) ;
}
V_50 -> V_52 = NULL ;
F_51 ( V_4 ) ;
return 0 ;
}
static int T_7 F_52 ( void )
{
F_53 ( L_2 , V_68 ) ;
return F_54 ( & V_69 ) ;
}
static void T_8 F_55 ( void )
{
F_56 ( & V_69 ) ;
}
