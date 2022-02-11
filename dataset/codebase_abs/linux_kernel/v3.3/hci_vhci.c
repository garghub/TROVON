static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! F_4 ( V_3 , & V_2 -> V_4 ) )
return 0 ;
F_5 ( & V_6 -> V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( & V_6 -> V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_11 ;
struct V_5 * V_6 ;
if ( ! V_2 ) {
F_8 ( L_1 ) ;
return - V_12 ;
}
if ( ! F_9 ( V_3 , & V_2 -> V_4 ) )
return - V_13 ;
V_6 = V_2 -> V_7 ;
memcpy ( F_10 ( V_10 , 1 ) , & F_11 ( V_10 ) -> V_14 , 1 ) ;
F_12 ( & V_6 -> V_8 , V_10 ) ;
F_13 ( & V_6 -> V_15 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_7 ) ;
}
static inline T_1 F_16 ( struct V_5 * V_6 ,
const char T_2 * V_16 , T_3 V_17 )
{
struct V_9 * V_10 ;
if ( V_17 > V_18 )
return - V_19 ;
V_10 = F_17 ( V_17 , V_20 ) ;
if ( ! V_10 )
return - V_21 ;
if ( F_18 ( F_19 ( V_10 , V_17 ) , V_16 , V_17 ) ) {
F_20 ( V_10 ) ;
return - V_22 ;
}
V_10 -> V_11 = ( void * ) V_6 -> V_2 ;
F_11 ( V_10 ) -> V_14 = * ( ( V_23 * ) V_10 -> V_6 ) ;
F_21 ( V_10 , 1 ) ;
F_22 ( V_10 ) ;
return V_17 ;
}
static inline T_1 F_23 ( struct V_5 * V_6 ,
struct V_9 * V_10 , char T_2 * V_16 , int V_17 )
{
char T_2 * V_24 = V_16 ;
int V_25 , V_26 = 0 ;
V_25 = F_24 (unsigned int, skb->len, count) ;
if ( F_25 ( V_24 , V_10 -> V_6 , V_25 ) )
return - V_22 ;
V_26 += V_25 ;
V_6 -> V_2 -> V_27 . V_28 += V_25 ;
switch ( F_11 ( V_10 ) -> V_14 ) {
case V_29 :
V_6 -> V_2 -> V_27 . V_30 ++ ;
break;
case V_31 :
V_6 -> V_2 -> V_27 . V_32 ++ ;
break;
case V_33 :
V_6 -> V_2 -> V_27 . V_34 ++ ;
break;
} ;
return V_26 ;
}
static T_1 F_26 ( struct V_35 * V_35 ,
char T_2 * V_16 , T_3 V_17 , T_4 * V_36 )
{
struct V_5 * V_6 = V_35 -> V_37 ;
struct V_9 * V_10 ;
T_1 V_38 = 0 ;
while ( V_17 ) {
V_10 = F_27 ( & V_6 -> V_8 ) ;
if ( V_10 ) {
V_38 = F_23 ( V_6 , V_10 , V_16 , V_17 ) ;
if ( V_38 < 0 )
F_28 ( & V_6 -> V_8 , V_10 ) ;
else
F_20 ( V_10 ) ;
break;
}
if ( V_35 -> V_39 & V_40 ) {
V_38 = - V_41 ;
break;
}
V_38 = F_29 ( V_6 -> V_15 ,
! F_30 ( & V_6 -> V_8 ) ) ;
if ( V_38 < 0 )
break;
}
return V_38 ;
}
static T_1 F_31 ( struct V_35 * V_35 ,
const char T_2 * V_16 , T_3 V_17 , T_4 * V_36 )
{
struct V_5 * V_6 = V_35 -> V_37 ;
return F_16 ( V_6 , V_16 , V_17 ) ;
}
static unsigned int F_32 ( struct V_35 * V_35 , T_5 * V_42 )
{
struct V_5 * V_6 = V_35 -> V_37 ;
F_33 ( V_35 , & V_6 -> V_15 , V_42 ) ;
if ( ! F_30 ( & V_6 -> V_8 ) )
return V_43 | V_44 ;
return V_45 | V_46 ;
}
static int F_34 ( struct V_47 * V_47 , struct V_35 * V_35 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_35 ( sizeof( struct V_5 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
F_36 ( & V_6 -> V_8 ) ;
F_37 ( & V_6 -> V_15 ) ;
V_2 = F_38 () ;
if ( ! V_2 ) {
F_15 ( V_6 ) ;
return - V_21 ;
}
V_6 -> V_2 = V_2 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_7 = V_6 ;
if ( V_50 )
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = F_1 ;
V_2 -> V_54 = F_3 ;
V_2 -> V_55 = F_6 ;
V_2 -> V_56 = F_7 ;
V_2 -> V_57 = F_14 ;
V_2 -> V_58 = V_59 ;
if ( F_39 ( V_2 ) < 0 ) {
F_8 ( L_2 ) ;
F_15 ( V_6 ) ;
F_40 ( V_2 ) ;
return - V_13 ;
}
V_35 -> V_37 = V_6 ;
return F_41 ( V_47 , V_35 ) ;
}
static int F_42 ( struct V_47 * V_47 , struct V_35 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_37 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_43 ( V_2 ) ;
F_40 ( V_2 ) ;
V_35 -> V_37 = NULL ;
return 0 ;
}
static int T_6 F_44 ( void )
{
F_45 ( L_3 , V_60 ) ;
return F_46 ( & V_61 ) ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_61 ) ;
}
