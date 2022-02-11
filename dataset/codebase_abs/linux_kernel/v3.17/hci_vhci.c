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
const struct V_31 * V_32 ,
unsigned long V_33 )
{
T_3 V_34 = F_25 ( V_32 , V_33 ) ;
struct V_8 * V_9 ;
T_1 V_11 , V_13 ;
unsigned long V_35 ;
int V_36 ;
if ( V_34 < 2 || V_34 > V_37 )
return - V_17 ;
V_9 = F_15 ( V_34 , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
if ( F_26 ( F_22 ( V_9 , V_32 [ V_35 ] . V_38 ) ,
V_32 [ V_35 ] . V_39 , V_32 [ V_35 ] . V_38 ) ) {
F_17 ( V_9 ) ;
return - V_40 ;
}
}
V_11 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_27 ( V_9 , 1 ) ;
switch ( V_11 ) {
case V_41 :
case V_42 :
case V_43 :
if ( ! V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_44 ;
}
F_11 ( V_9 ) -> V_11 = V_11 ;
V_36 = F_28 ( V_6 -> V_2 , V_9 ) ;
break;
case V_29 :
if ( V_6 -> V_2 ) {
F_17 ( V_9 ) ;
return - V_45 ;
}
F_29 ( & V_6 -> V_46 ) ;
V_13 = * ( ( T_1 * ) V_9 -> V_6 ) ;
F_27 ( V_9 , 1 ) ;
if ( V_9 -> V_34 > 0 ) {
F_17 ( V_9 ) ;
return - V_17 ;
}
F_17 ( V_9 ) ;
V_36 = F_14 ( V_6 , V_13 ) ;
break;
default:
F_17 ( V_9 ) ;
return - V_17 ;
}
return ( V_36 < 0 ) ? V_36 : V_34 ;
}
static inline T_2 F_30 ( struct V_5 * V_6 ,
struct V_8 * V_9 ,
char T_4 * V_47 , int V_33 )
{
char T_4 * V_48 = V_47 ;
int V_34 ;
V_34 = F_31 (unsigned int, skb->len, count) ;
if ( F_32 ( V_48 , V_9 -> V_6 , V_34 ) )
return - V_40 ;
if ( ! V_6 -> V_2 )
return V_34 ;
V_6 -> V_2 -> V_49 . V_50 += V_34 ;
switch ( F_11 ( V_9 ) -> V_11 ) {
case V_51 :
V_6 -> V_2 -> V_49 . V_52 ++ ;
break;
case V_42 :
V_6 -> V_2 -> V_49 . V_53 ++ ;
break;
case V_43 :
V_6 -> V_2 -> V_49 . V_54 ++ ;
break;
}
return V_34 ;
}
static T_2 F_33 ( struct V_55 * V_55 ,
char T_4 * V_47 , T_3 V_33 , T_5 * V_56 )
{
struct V_5 * V_6 = V_55 -> V_57 ;
struct V_8 * V_9 ;
T_2 V_36 = 0 ;
while ( V_33 ) {
V_9 = F_34 ( & V_6 -> V_7 ) ;
if ( V_9 ) {
V_36 = F_30 ( V_6 , V_9 , V_47 , V_33 ) ;
if ( V_36 < 0 )
F_35 ( & V_6 -> V_7 , V_9 ) ;
else
F_17 ( V_9 ) ;
break;
}
if ( V_55 -> V_58 & V_59 ) {
V_36 = - V_60 ;
break;
}
V_36 = F_36 ( V_6 -> V_12 ,
! F_37 ( & V_6 -> V_7 ) ) ;
if ( V_36 < 0 )
break;
}
return V_36 ;
}
static T_2 F_38 ( struct V_61 * V_62 , const struct V_31 * V_32 ,
unsigned long V_33 , T_5 V_56 )
{
struct V_55 * V_55 = V_62 -> V_63 ;
struct V_5 * V_6 = V_55 -> V_57 ;
return F_24 ( V_6 , V_32 , V_33 ) ;
}
static unsigned int F_39 ( struct V_55 * V_55 , T_6 * V_64 )
{
struct V_5 * V_6 = V_55 -> V_57 ;
F_40 ( V_55 , & V_6 -> V_12 , V_64 ) ;
if ( ! F_37 ( & V_6 -> V_7 ) )
return V_65 | V_66 ;
return V_67 | V_68 ;
}
static void F_41 ( struct V_69 * V_70 )
{
struct V_5 * V_6 = F_42 ( V_70 , struct V_5 ,
V_46 . V_70 ) ;
F_14 ( V_6 , V_71 ? V_16 : V_15 ) ;
}
static int F_43 ( struct V_72 * V_72 , struct V_55 * V_55 )
{
struct V_5 * V_6 ;
V_6 = F_44 ( sizeof( struct V_5 ) , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
F_45 ( & V_6 -> V_7 ) ;
F_46 ( & V_6 -> V_12 ) ;
F_47 ( & V_6 -> V_46 , F_41 ) ;
V_55 -> V_57 = V_6 ;
F_48 ( V_72 , V_55 ) ;
F_49 ( & V_6 -> V_46 , F_50 ( 1000 ) ) ;
return 0 ;
}
static int F_51 ( struct V_72 * V_72 , struct V_55 * V_55 )
{
struct V_5 * V_6 = V_55 -> V_57 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_29 ( & V_6 -> V_46 ) ;
if ( V_2 ) {
F_52 ( V_2 ) ;
F_21 ( V_2 ) ;
}
V_55 -> V_57 = NULL ;
F_53 ( V_6 ) ;
return 0 ;
}
static int T_7 F_54 ( void )
{
F_55 ( L_2 , V_73 ) ;
return F_56 ( & V_74 ) ;
}
static void T_8 F_57 ( void )
{
F_58 ( & V_74 ) ;
}
