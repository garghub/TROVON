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
memcpy ( F_7 ( V_7 , 1 ) , & F_8 ( V_7 ) , 1 ) ;
F_9 ( & V_4 -> V_5 , V_7 ) ;
F_10 ( & V_4 -> V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 , T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_1 V_10 ;
if ( V_4 -> V_2 )
return - V_11 ;
V_10 = V_9 & 0x03 ;
if ( V_10 != V_12 && V_10 != V_13 )
return - V_14 ;
if ( V_9 & 0x3c )
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
V_2 -> V_10 = V_10 ;
F_15 ( V_2 , V_4 ) ;
V_2 -> V_19 = F_1 ;
V_2 -> V_20 = F_2 ;
V_2 -> V_21 = F_5 ;
V_2 -> V_22 = F_6 ;
if ( V_9 & 0x40 )
F_16 ( V_23 , & V_2 -> V_24 ) ;
if ( V_9 & 0x80 )
F_16 ( V_25 , & V_2 -> V_24 ) ;
if ( F_17 ( V_2 ) < 0 ) {
F_18 ( L_1 ) ;
F_19 ( V_2 ) ;
V_4 -> V_2 = NULL ;
F_14 ( V_7 ) ;
return - V_26 ;
}
F_8 ( V_7 ) = V_27 ;
F_20 ( V_7 , 0xff ) ;
F_20 ( V_7 , V_9 ) ;
F_21 ( V_2 -> V_28 , F_22 ( V_7 , 2 ) ) ;
F_9 ( & V_4 -> V_5 , V_7 ) ;
F_10 ( & V_4 -> V_8 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , T_1 V_9 )
{
int V_29 ;
F_24 ( & V_4 -> V_30 ) ;
V_29 = F_11 ( V_4 , V_9 ) ;
F_25 ( & V_4 -> V_30 ) ;
return V_29 ;
}
static inline T_2 F_26 ( struct V_3 * V_4 ,
struct V_31 * V_32 )
{
T_3 V_33 = F_27 ( V_32 ) ;
struct V_6 * V_7 ;
T_1 V_34 , V_9 ;
int V_35 ;
if ( V_33 < 2 || V_33 > V_36 )
return - V_14 ;
V_7 = F_12 ( V_33 , V_15 ) ;
if ( ! V_7 )
return - V_16 ;
if ( ! F_28 ( F_22 ( V_7 , V_33 ) , V_33 , V_32 ) ) {
F_14 ( V_7 ) ;
return - V_37 ;
}
V_34 = * ( ( T_1 * ) V_7 -> V_4 ) ;
F_29 ( V_7 , 1 ) ;
switch ( V_34 ) {
case V_38 :
case V_39 :
case V_40 :
if ( ! V_4 -> V_2 ) {
F_14 ( V_7 ) ;
return - V_41 ;
}
F_8 ( V_7 ) = V_34 ;
V_35 = F_30 ( V_4 -> V_2 , V_7 ) ;
break;
case V_27 :
F_31 ( & V_4 -> V_42 ) ;
V_9 = * ( ( T_1 * ) V_7 -> V_4 ) ;
F_29 ( V_7 , 1 ) ;
if ( V_7 -> V_33 > 0 ) {
F_14 ( V_7 ) ;
return - V_14 ;
}
F_14 ( V_7 ) ;
V_35 = F_23 ( V_4 , V_9 ) ;
break;
default:
F_14 ( V_7 ) ;
return - V_14 ;
}
return ( V_35 < 0 ) ? V_35 : V_33 ;
}
static inline T_2 F_32 ( struct V_3 * V_4 ,
struct V_6 * V_7 ,
char T_4 * V_43 , int V_44 )
{
char T_4 * V_45 = V_43 ;
int V_33 ;
V_33 = F_33 (unsigned int, skb->len, count) ;
if ( F_34 ( V_45 , V_7 -> V_4 , V_33 ) )
return - V_37 ;
if ( ! V_4 -> V_2 )
return V_33 ;
V_4 -> V_2 -> V_46 . V_47 += V_33 ;
switch ( F_8 ( V_7 ) ) {
case V_48 :
V_4 -> V_2 -> V_46 . V_49 ++ ;
break;
case V_39 :
V_4 -> V_2 -> V_46 . V_50 ++ ;
break;
case V_40 :
V_4 -> V_2 -> V_46 . V_51 ++ ;
break;
}
return V_33 ;
}
static T_2 F_35 ( struct V_52 * V_52 ,
char T_4 * V_43 , T_3 V_44 , T_5 * V_53 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
struct V_6 * V_7 ;
T_2 V_35 = 0 ;
while ( V_44 ) {
V_7 = F_36 ( & V_4 -> V_5 ) ;
if ( V_7 ) {
V_35 = F_32 ( V_4 , V_7 , V_43 , V_44 ) ;
if ( V_35 < 0 )
F_37 ( & V_4 -> V_5 , V_7 ) ;
else
F_14 ( V_7 ) ;
break;
}
if ( V_52 -> V_55 & V_56 ) {
V_35 = - V_57 ;
break;
}
V_35 = F_38 ( V_4 -> V_8 ,
! F_39 ( & V_4 -> V_5 ) ) ;
if ( V_35 < 0 )
break;
}
return V_35 ;
}
static T_2 F_40 ( struct V_58 * V_59 , struct V_31 * V_32 )
{
struct V_52 * V_52 = V_59 -> V_60 ;
struct V_3 * V_4 = V_52 -> V_54 ;
return F_26 ( V_4 , V_32 ) ;
}
static unsigned int F_41 ( struct V_52 * V_52 , T_6 * V_61 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
F_42 ( V_52 , & V_4 -> V_8 , V_61 ) ;
if ( ! F_39 ( & V_4 -> V_5 ) )
return V_62 | V_63 ;
return V_64 | V_65 ;
}
static void F_43 ( struct V_66 * V_67 )
{
struct V_3 * V_4 = F_44 ( V_67 , struct V_3 ,
V_42 . V_67 ) ;
F_23 ( V_4 , V_68 ? V_13 : V_12 ) ;
}
static int F_45 ( struct V_69 * V_69 , struct V_52 * V_52 )
{
struct V_3 * V_4 ;
V_4 = F_46 ( sizeof( struct V_3 ) , V_15 ) ;
if ( ! V_4 )
return - V_16 ;
F_47 ( & V_4 -> V_5 ) ;
F_48 ( & V_4 -> V_8 ) ;
F_49 ( & V_4 -> V_30 ) ;
F_50 ( & V_4 -> V_42 , F_43 ) ;
V_52 -> V_54 = V_4 ;
F_51 ( V_69 , V_52 ) ;
F_52 ( & V_4 -> V_42 , F_53 ( 1000 ) ) ;
return 0 ;
}
static int F_54 ( struct V_69 * V_69 , struct V_52 * V_52 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
struct V_1 * V_2 ;
F_31 ( & V_4 -> V_42 ) ;
V_2 = V_4 -> V_2 ;
if ( V_2 ) {
F_55 ( V_2 ) ;
F_19 ( V_2 ) ;
}
F_4 ( & V_4 -> V_5 ) ;
V_52 -> V_54 = NULL ;
F_56 ( V_4 ) ;
return 0 ;
}
