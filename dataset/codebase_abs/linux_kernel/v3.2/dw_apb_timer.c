static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static unsigned long F_4 ( struct V_8 * V_9 , unsigned long V_10 )
{
return F_5 ( V_9 -> V_11 + V_10 ) ;
}
static void F_6 ( struct V_8 * V_9 , unsigned long V_12 ,
unsigned long V_10 )
{
F_7 ( V_12 , V_9 -> V_11 + V_10 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
unsigned long V_13 = F_4 ( V_9 , V_14 ) ;
V_13 |= V_15 ;
F_6 ( V_9 , V_13 , V_14 ) ;
}
void F_9 ( struct V_1 * V_16 )
{
F_10 ( V_16 -> V_9 . V_17 ) ;
F_8 ( & V_16 -> V_9 ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
F_4 ( V_9 , V_18 ) ;
}
static T_1 F_12 ( int V_17 , void * V_19 )
{
struct V_2 * V_3 = V_19 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_20 ) {
F_13 ( L_1 , V_17 ) ;
return V_21 ;
}
if ( V_16 -> V_22 )
V_16 -> V_22 ( & V_16 -> V_9 ) ;
V_3 -> V_20 ( V_3 ) ;
return V_23 ;
}
static void F_14 ( struct V_8 * V_9 )
{
unsigned long V_13 = F_4 ( V_9 , V_14 ) ;
F_4 ( V_9 , V_18 ) ;
V_13 &= ~ V_15 ;
F_6 ( V_9 , V_13 , V_14 ) ;
}
static void F_15 ( enum V_24 V_25 ,
struct V_2 * V_3 )
{
unsigned long V_13 ;
unsigned long V_26 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_16 ( L_2 , V_27 , F_17 ( * V_3 -> V_28 ) ,
V_25 ) ;
switch ( V_25 ) {
case V_29 :
V_26 = F_18 ( V_16 -> V_9 . V_30 , V_31 ) ;
V_13 = F_4 ( & V_16 -> V_9 , V_14 ) ;
V_13 |= V_32 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
V_13 &= ~ V_33 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_19 ( 1 ) ;
F_16 ( L_3 , V_26 , V_31 ) ;
F_6 ( & V_16 -> V_9 , V_26 , V_34 ) ;
V_13 |= V_33 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
break;
case V_35 :
V_13 = F_4 ( & V_16 -> V_9 , V_14 ) ;
V_13 &= ~ V_33 ;
V_13 &= ~ V_32 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_6 ( & V_16 -> V_9 , ~ 0 , V_34 ) ;
V_13 &= ~ V_15 ;
V_13 |= V_33 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
break;
case V_36 :
case V_37 :
V_13 = F_4 ( & V_16 -> V_9 , V_14 ) ;
V_13 &= ~ V_33 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
break;
case V_38 :
F_14 ( & V_16 -> V_9 ) ;
break;
}
}
static int F_20 ( unsigned long V_39 ,
struct V_2 * V_3 )
{
unsigned long V_13 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_13 = F_4 ( & V_16 -> V_9 , V_14 ) ;
V_13 &= ~ V_33 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_6 ( & V_16 -> V_9 , V_39 , V_34 ) ;
V_13 |= V_33 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
return 0 ;
}
struct V_1 *
F_21 ( int V_40 , const char * V_41 , unsigned V_42 ,
void T_2 * V_11 , int V_17 , unsigned long V_30 )
{
struct V_1 * V_16 =
F_22 ( sizeof( * V_16 ) , V_43 ) ;
int V_44 ;
if ( ! V_16 )
return NULL ;
V_16 -> V_9 . V_11 = V_11 ;
V_16 -> V_9 . V_17 = V_17 ;
V_16 -> V_9 . V_30 = V_30 ;
F_23 ( & V_16 -> V_4 , V_30 , V_45 ) ;
V_16 -> V_4 . V_46 = F_24 ( 0x7fffffff ,
& V_16 -> V_4 ) ;
V_16 -> V_4 . V_47 = F_24 ( 5000 , & V_16 -> V_4 ) ;
V_16 -> V_4 . V_28 = F_25 ( V_40 ) ;
V_16 -> V_4 . V_48 = V_49 | V_50 ;
V_16 -> V_4 . V_51 = F_15 ;
V_16 -> V_4 . V_52 = F_20 ;
V_16 -> V_4 . V_17 = V_16 -> V_9 . V_17 ;
V_16 -> V_4 . V_42 = V_42 ;
V_16 -> V_4 . V_41 = V_41 ;
V_16 -> V_53 . V_41 = V_16 -> V_4 . V_41 ;
V_16 -> V_53 . V_54 = F_12 ;
V_16 -> V_53 . V_55 = & V_16 -> V_4 ;
V_16 -> V_53 . V_17 = V_17 ;
V_16 -> V_53 . V_56 = V_57 | V_58 |
V_59 |
V_60 ;
V_16 -> V_22 = F_11 ;
V_44 = F_26 ( V_17 , & V_16 -> V_53 ) ;
if ( V_44 ) {
F_27 ( L_4 ) ;
F_28 ( V_16 ) ;
V_16 = NULL ;
}
return V_16 ;
}
void F_29 ( struct V_1 * V_16 )
{
F_30 ( V_16 -> V_9 . V_17 ) ;
}
void F_31 ( struct V_1 * V_16 )
{
F_32 ( V_16 -> V_9 . V_17 , & V_16 -> V_4 ) ;
}
void F_33 ( struct V_1 * V_16 )
{
F_6 ( & V_16 -> V_9 , 0 , V_14 ) ;
F_34 ( & V_16 -> V_4 ) ;
F_14 ( & V_16 -> V_9 ) ;
}
void F_35 ( struct V_5 * V_61 )
{
unsigned long V_13 = F_4 ( & V_61 -> V_9 , V_14 ) ;
V_13 &= ~ V_33 ;
F_6 ( & V_61 -> V_9 , V_13 , V_14 ) ;
F_6 ( & V_61 -> V_9 , ~ 0 , V_34 ) ;
V_13 &= ~ V_32 ;
V_13 |= ( V_33 | V_15 ) ;
F_6 ( & V_61 -> V_9 , V_13 , V_14 ) ;
F_36 ( V_61 ) ;
}
static T_3 F_37 ( struct V_6 * V_7 )
{
unsigned long V_62 ;
struct V_5 * V_61 =
F_3 ( V_7 ) ;
V_62 = F_4 ( & V_61 -> V_9 , V_63 ) ;
return ( T_3 ) ~ V_62 ;
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_5 * V_61 =
F_3 ( V_7 ) ;
F_35 ( V_61 ) ;
}
struct V_5 *
F_39 ( unsigned V_42 , const char * V_41 , void T_2 * V_11 ,
unsigned long V_30 )
{
struct V_5 * V_61 = F_22 ( sizeof( * V_61 ) , V_43 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_9 . V_11 = V_11 ;
V_61 -> V_9 . V_30 = V_30 ;
V_61 -> V_7 . V_41 = V_41 ;
V_61 -> V_7 . V_42 = V_42 ;
V_61 -> V_7 . V_64 = F_37 ;
V_61 -> V_7 . V_65 = F_40 ( 32 ) ;
V_61 -> V_7 . V_56 = V_66 ;
V_61 -> V_7 . V_67 = F_38 ;
return V_61 ;
}
void F_41 ( struct V_5 * V_61 )
{
F_42 ( & V_61 -> V_7 , V_61 -> V_9 . V_30 ) ;
}
T_3 F_36 ( struct V_5 * V_61 )
{
return ( T_3 ) ~ F_4 ( & V_61 -> V_9 , V_63 ) ;
}
void F_43 ( struct V_5 * V_61 )
{
F_44 ( & V_61 -> V_7 ) ;
F_28 ( V_61 ) ;
}
