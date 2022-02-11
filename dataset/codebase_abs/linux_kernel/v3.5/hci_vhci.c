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
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 -> V_10 ;
struct V_5 * V_6 ;
if ( ! V_2 ) {
F_9 ( L_1 ) ;
return - V_11 ;
}
if ( ! F_10 ( V_3 , & V_2 -> V_4 ) )
return - V_12 ;
V_6 = F_4 ( V_2 ) ;
memcpy ( F_11 ( V_9 , 1 ) , & F_12 ( V_9 ) -> V_13 , 1 ) ;
F_13 ( & V_6 -> V_7 , V_9 ) ;
F_14 ( & V_6 -> V_14 ) ;
return 0 ;
}
static inline T_1 F_15 ( struct V_5 * V_6 ,
const char T_2 * V_15 , T_3 V_16 )
{
struct V_8 * V_9 ;
if ( V_16 > V_17 )
return - V_18 ;
V_9 = F_16 ( V_16 , V_19 ) ;
if ( ! V_9 )
return - V_20 ;
if ( F_17 ( F_18 ( V_9 , V_16 ) , V_15 , V_16 ) ) {
F_19 ( V_9 ) ;
return - V_21 ;
}
V_9 -> V_10 = ( void * ) V_6 -> V_2 ;
F_12 ( V_9 ) -> V_13 = * ( ( V_22 * ) V_9 -> V_6 ) ;
F_20 ( V_9 , 1 ) ;
F_21 ( V_9 ) ;
return V_16 ;
}
static inline T_1 F_22 ( struct V_5 * V_6 ,
struct V_8 * V_9 , char T_2 * V_15 , int V_16 )
{
char T_2 * V_23 = V_15 ;
int V_24 , V_25 = 0 ;
V_24 = F_23 (unsigned int, skb->len, count) ;
if ( F_24 ( V_23 , V_9 -> V_6 , V_24 ) )
return - V_21 ;
V_25 += V_24 ;
V_6 -> V_2 -> V_26 . V_27 += V_24 ;
switch ( F_12 ( V_9 ) -> V_13 ) {
case V_28 :
V_6 -> V_2 -> V_26 . V_29 ++ ;
break;
case V_30 :
V_6 -> V_2 -> V_26 . V_31 ++ ;
break;
case V_32 :
V_6 -> V_2 -> V_26 . V_33 ++ ;
break;
} ;
return V_25 ;
}
static T_1 F_25 ( struct V_34 * V_34 ,
char T_2 * V_15 , T_3 V_16 , T_4 * V_35 )
{
struct V_5 * V_6 = V_34 -> V_36 ;
struct V_8 * V_9 ;
T_1 V_37 = 0 ;
while ( V_16 ) {
V_9 = F_26 ( & V_6 -> V_7 ) ;
if ( V_9 ) {
V_37 = F_22 ( V_6 , V_9 , V_15 , V_16 ) ;
if ( V_37 < 0 )
F_27 ( & V_6 -> V_7 , V_9 ) ;
else
F_19 ( V_9 ) ;
break;
}
if ( V_34 -> V_38 & V_39 ) {
V_37 = - V_40 ;
break;
}
V_37 = F_28 ( V_6 -> V_14 ,
! F_29 ( & V_6 -> V_7 ) ) ;
if ( V_37 < 0 )
break;
}
return V_37 ;
}
static T_1 F_30 ( struct V_34 * V_34 ,
const char T_2 * V_15 , T_3 V_16 , T_4 * V_35 )
{
struct V_5 * V_6 = V_34 -> V_36 ;
return F_15 ( V_6 , V_15 , V_16 ) ;
}
static unsigned int F_31 ( struct V_34 * V_34 , T_5 * V_41 )
{
struct V_5 * V_6 = V_34 -> V_36 ;
F_32 ( V_34 , & V_6 -> V_14 , V_41 ) ;
if ( ! F_29 ( & V_6 -> V_7 ) )
return V_42 | V_43 ;
return V_44 | V_45 ;
}
static int F_33 ( struct V_46 * V_46 , struct V_34 * V_34 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_34 ( sizeof( struct V_5 ) , V_19 ) ;
if ( ! V_6 )
return - V_20 ;
F_35 ( & V_6 -> V_7 ) ;
F_36 ( & V_6 -> V_14 ) ;
V_2 = F_37 () ;
if ( ! V_2 ) {
F_38 ( V_6 ) ;
return - V_20 ;
}
V_6 -> V_2 = V_2 ;
V_2 -> V_47 = V_48 ;
F_39 ( V_2 , V_6 ) ;
if ( V_49 )
V_2 -> V_50 = V_51 ;
V_2 -> V_52 = F_1 ;
V_2 -> V_53 = F_3 ;
V_2 -> V_54 = F_7 ;
V_2 -> V_55 = F_8 ;
if ( F_40 ( V_2 ) < 0 ) {
F_9 ( L_2 ) ;
F_38 ( V_6 ) ;
F_41 ( V_2 ) ;
return - V_12 ;
}
V_34 -> V_36 = V_6 ;
F_42 ( V_46 , V_34 ) ;
return 0 ;
}
static int F_43 ( struct V_46 * V_46 , struct V_34 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_36 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_44 ( V_2 ) ;
F_41 ( V_2 ) ;
V_34 -> V_36 = NULL ;
F_38 ( V_6 ) ;
return 0 ;
}
static int T_6 F_45 ( void )
{
F_46 ( L_3 , V_56 ) ;
return F_47 ( & V_57 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_57 ) ;
}
