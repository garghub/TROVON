static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_4 ) ;
V_2 -> V_5 -> V_6 . V_7 ++ ;
V_2 -> V_5 -> V_6 . V_8 += V_2 -> V_9 ;
return F_3 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_10 )
{
switch ( V_10 ) {
case V_11 :
F_5 ( L_1 ,
V_12 ) ;
case V_13 :
F_6 ( V_2 ) ;
case V_14 :
return V_15 ;
case V_16 :
return F_1 ( V_2 ) ;
default:
break;
}
return V_15 ;
}
static inline bool F_7 ( T_2 V_17 )
{
return ( V_17 & V_18 ) == V_19 ;
}
static inline bool F_8 ( T_2 V_17 )
{
return ( V_17 & V_18 ) == V_20 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
int V_21 ;
if ( ! ( F_7 ( * F_10 ( V_2 ) ) ||
F_8 ( * F_10 ( V_2 ) ) ) )
return V_11 ;
V_21 = F_11 ( V_2 , * F_10 ( V_2 ) &
V_18 ) ;
if ( V_21 == 1 )
return V_16 ;
return V_14 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_22 V_23 ;
if ( F_13 ( V_2 , & V_23 ) < 0 )
return - V_24 ;
return F_14 ( V_2 , V_2 -> V_5 , & V_23 . V_25 , & V_23 . V_26 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 )
{
int V_21 ;
if ( ! F_16 ( * F_10 ( V_2 ) ) )
return V_11 ;
F_17 ( V_2 ) -> V_27 = 0 ;
V_21 = F_12 ( V_2 ) ;
if ( V_21 < 0 )
return V_13 ;
return V_16 ;
}
T_1 F_18 ( struct V_1 * V_2 )
{
if ( ! F_19 ( * F_10 ( V_2 ) ) )
return V_11 ;
F_20 ( V_2 , 1 ) ;
return V_16 ;
}
static inline bool F_21 ( T_2 V_17 )
{
return V_17 == V_28 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
if ( ! F_21 ( * F_10 ( V_2 ) ) )
return V_11 ;
F_5 ( L_2 , V_2 -> V_5 -> V_29 ,
L_3 ) ;
return V_13 ;
}
static inline bool F_23 ( T_2 V_17 )
{
return V_17 == V_30 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
if ( ! F_23 ( * F_10 ( V_2 ) ) )
return V_11 ;
F_5 ( L_2 , V_2 -> V_5 -> V_29 ,
L_4 ) ;
return V_13 ;
}
static inline bool F_25 ( T_2 V_17 )
{
return V_17 == V_31 ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
if ( ! F_25 ( * F_10 ( V_2 ) ) )
return V_11 ;
F_5 ( L_2 , V_2 -> V_5 -> V_29 ,
L_5 ) ;
return V_13 ;
}
static inline bool F_27 ( T_2 V_17 )
{
return V_17 == V_32 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
if ( ! F_27 ( * F_10 ( V_2 ) ) )
return V_11 ;
F_5 ( L_2 , V_2 -> V_5 -> V_29 ,
L_6 ) ;
return V_13 ;
}
static inline bool F_29 ( T_2 V_17 )
{
return ( V_17 & V_33 ) == V_34 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
if ( ! F_29 ( * F_10 ( V_2 ) ) )
return V_11 ;
F_5 ( L_2 , V_2 -> V_5 -> V_29 ,
L_7 ) ;
return V_13 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_10 ;
#define F_32 ( T_3 ) \
do { \
res = rxh(skb); \
if (res != RX_CONTINUE) \
goto rxh_next; \
} while (0)
F_32 ( F_15 ) ;
F_32 ( F_9 ) ;
F_32 ( F_18 ) ;
F_32 ( F_22 ) ;
F_32 ( F_24 ) ;
F_32 ( F_26 ) ;
F_32 ( F_28 ) ;
F_32 ( F_30 ) ;
V_35:
return F_4 ( V_2 , V_10 ) ;
#undef F_32
}
static inline bool F_33 ( T_2 V_17 )
{
return ( V_17 & V_33 ) == V_36 ;
}
static inline bool F_34 ( T_2 V_17 )
{
return ( ( V_17 >= 0x44 && V_17 <= 0x4F ) ||
( V_17 >= 0x51 && V_17 <= 0x5F ) ||
( V_17 >= 0xc8 && V_17 <= 0xdf ) ||
( V_17 >= 0xe8 && V_17 <= 0xff ) ) ;
}
static inline bool F_35 ( struct V_1 * V_2 )
{
T_4 V_37 = F_36 ( V_2 ) ;
if ( ! F_37 ( V_37 ) ||
! F_38 ( V_37 , V_2 ) )
return false ;
if ( F_39 ( ! V_2 -> V_9 ) )
return false ;
if ( F_33 ( * F_10 ( V_2 ) ) ||
F_34 ( * F_10 ( V_2 ) ) )
return false ;
return true ;
}
static int F_40 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_38 * V_42 )
{
struct V_38 * V_43 ;
if ( V_39 -> type != V_44 ||
V_2 -> V_45 == V_46 ||
! F_35 ( V_2 ) )
goto V_47;
V_43 = V_39 -> V_48 -> V_49 ;
if ( ! V_43 || ! F_41 ( V_43 ) )
goto V_47;
V_2 = F_42 ( V_2 , V_50 ) ;
if ( ! V_2 )
goto V_51;
V_2 -> V_5 = V_43 ;
if ( F_7 ( * F_10 ( V_2 ) ) ||
F_16 ( * F_10 ( V_2 ) ) ) {
V_2 = F_43 ( V_2 , V_50 ) ;
if ( ! V_2 )
goto V_51;
}
return F_31 ( V_2 ) ;
V_47:
F_6 ( V_2 ) ;
V_51:
return V_15 ;
}
void F_44 ( void )
{
F_45 ( & V_52 ) ;
}
void F_46 ( void )
{
F_47 ( & V_52 ) ;
}
