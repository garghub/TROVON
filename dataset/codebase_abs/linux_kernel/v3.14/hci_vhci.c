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
const struct V_24 * V_25 ,
unsigned long V_26 )
{
T_3 V_27 = F_25 ( V_25 , V_26 ) ;
struct V_8 * V_9 ;
T_1 V_11 , V_13 ;
unsigned long V_28 ;
int V_29 ;
if ( V_27 < 2 || V_27 > V_30 )
return - V_31 ;
V_9 = F_15 ( V_27 , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
if ( F_26 ( F_22 ( V_9 , V_25 [ V_28 ] . V_32 ) ,
V_25 [ V_28 ] . V_33 , V_25 [ V_28 ] . V_32 ) ) {
F_17 ( V_9 ) ;
return - V_34 ;
}
}
V_11 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_27 ( V_9 , 1 ) ;
switch ( V_11 ) {
case V_35 :
case V_36 :
case V_37 :
if ( ! V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_38 ;
}
F_11 ( V_9 ) -> V_11 = V_11 ;
V_29 = F_28 ( V_6 -> V_2 , V_9 ) ;
break;
case V_22 :
if ( V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_39 ;
}
F_29 ( & V_6 -> V_40 ) ;
V_13 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_27 ( V_9 , 1 ) ;
if ( V_9 -> V_27 > 0 ) {
F_17 ( V_9 ) ;
return - V_31 ;
}
F_17 ( V_9 ) ;
if ( V_13 != V_41 && V_13 != V_42 )
return - V_31 ;
V_29 = F_14 ( V_6 , V_13 ) ;
break;
default:
F_17 ( V_9 ) ;
return - V_31 ;
}
return ( V_29 < 0 ) ? V_29 : V_27 ;
}
static inline T_2 F_30 ( struct V_5 * V_6 ,
struct V_8 * V_9 ,
char T_4 * V_43 , int V_26 )
{
char T_4 * V_44 = V_43 ;
int V_27 ;
V_27 = F_31 (unsigned int, skb->len, count) ;
if ( F_32 ( V_44 , V_9 -> V_6 , V_27 ) )
return - V_34 ;
if ( ! V_6 -> V_2 )
return V_27 ;
V_6 -> V_2 -> V_45 . V_46 += V_27 ;
switch ( F_11 ( V_9 ) -> V_11 ) {
case V_47 :
V_6 -> V_2 -> V_45 . V_48 ++ ;
break;
case V_36 :
V_6 -> V_2 -> V_45 . V_49 ++ ;
break;
case V_37 :
V_6 -> V_2 -> V_45 . V_50 ++ ;
break;
}
return V_27 ;
}
static T_2 F_33 ( struct V_51 * V_51 ,
char T_4 * V_43 , T_3 V_26 , T_5 * V_52 )
{
struct V_5 * V_6 = V_51 -> V_53 ;
struct V_8 * V_9 ;
T_2 V_29 = 0 ;
while ( V_26 ) {
V_9 = F_34 ( & V_6 -> V_7 ) ;
if ( V_9 ) {
V_29 = F_30 ( V_6 , V_9 , V_43 , V_26 ) ;
if ( V_29 < 0 )
F_35 ( & V_6 -> V_7 , V_9 ) ;
else
F_17 ( V_9 ) ;
break;
}
if ( V_51 -> V_54 & V_55 ) {
V_29 = - V_56 ;
break;
}
V_29 = F_36 ( V_6 -> V_12 ,
! F_37 ( & V_6 -> V_7 ) ) ;
if ( V_29 < 0 )
break;
}
return V_29 ;
}
static T_2 F_38 ( struct V_57 * V_58 , const struct V_24 * V_25 ,
unsigned long V_26 , T_5 V_52 )
{
struct V_51 * V_51 = V_58 -> V_59 ;
struct V_5 * V_6 = V_51 -> V_53 ;
return F_24 ( V_6 , V_25 , V_26 ) ;
}
static unsigned int F_39 ( struct V_51 * V_51 , T_6 * V_60 )
{
struct V_5 * V_6 = V_51 -> V_53 ;
F_40 ( V_51 , & V_6 -> V_12 , V_60 ) ;
if ( ! F_37 ( & V_6 -> V_7 ) )
return V_61 | V_62 ;
return V_63 | V_64 ;
}
static void F_41 ( struct V_65 * V_66 )
{
struct V_5 * V_6 = F_42 ( V_66 , struct V_5 ,
V_40 . V_66 ) ;
F_14 ( V_6 , V_67 ? V_42 : V_41 ) ;
}
static int F_43 ( struct V_68 * V_68 , struct V_51 * V_51 )
{
struct V_5 * V_6 ;
V_6 = F_44 ( sizeof( struct V_5 ) , V_14 ) ;
if ( ! V_6 )
return - V_15 ;
F_45 ( & V_6 -> V_7 ) ;
F_46 ( & V_6 -> V_12 ) ;
F_47 ( & V_6 -> V_40 , F_41 ) ;
V_51 -> V_53 = V_6 ;
F_48 ( V_68 , V_51 ) ;
F_49 ( & V_6 -> V_40 , F_50 ( 1000 ) ) ;
return 0 ;
}
static int F_51 ( struct V_68 * V_68 , struct V_51 * V_51 )
{
struct V_5 * V_6 = V_51 -> V_53 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_29 ( & V_6 -> V_40 ) ;
if ( V_2 ) {
F_52 ( V_2 ) ;
F_21 ( V_2 ) ;
}
V_51 -> V_53 = NULL ;
F_53 ( V_6 ) ;
return 0 ;
}
static int T_7 F_54 ( void )
{
F_55 ( L_2 , V_69 ) ;
return F_56 ( & V_70 ) ;
}
static void T_8 F_57 ( void )
{
F_58 ( & V_70 ) ;
}
