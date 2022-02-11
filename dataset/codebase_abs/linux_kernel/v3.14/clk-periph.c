static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = & V_4 -> V_8 . V_2 ;
V_7 -> V_9 = V_2 -> V_9 ;
return V_6 -> V_10 ( V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = & V_4 -> V_8 . V_2 ;
V_7 -> V_9 = V_2 -> V_9 ;
return V_6 -> V_12 ( V_7 , V_11 ) ;
}
static unsigned long F_4 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_14 = V_4 -> V_14 ;
struct V_1 * V_15 = & V_4 -> V_16 . V_2 ;
V_15 -> V_9 = V_2 -> V_9 ;
return V_14 -> V_17 ( V_15 , V_13 ) ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_18 ,
unsigned long * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_14 = V_4 -> V_14 ;
struct V_1 * V_15 = & V_4 -> V_16 . V_2 ;
V_15 -> V_9 = V_2 -> V_9 ;
return V_14 -> V_20 ( V_15 , V_18 , V_19 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_18 ,
unsigned long V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_14 = V_4 -> V_14 ;
struct V_1 * V_15 = & V_4 -> V_16 . V_2 ;
V_15 -> V_9 = V_2 -> V_9 ;
return V_14 -> V_21 ( V_15 , V_18 , V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_22 = V_4 -> V_22 ;
struct V_1 * V_23 = & V_4 -> V_24 . V_2 ;
V_23 -> V_9 = V_2 -> V_9 ;
return V_22 -> V_25 ( V_23 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_22 = V_4 -> V_22 ;
struct V_1 * V_23 = & V_4 -> V_24 . V_2 ;
V_23 -> V_9 = V_2 -> V_9 ;
return V_22 -> V_26 ( V_23 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_22 = V_4 -> V_22 ;
struct V_1 * V_23 = & V_4 -> V_24 . V_2 ;
V_22 -> V_27 ( V_23 ) ;
}
static struct V_9 * F_10 ( const char * V_28 ,
const char * * V_29 , int V_30 ,
struct V_3 * V_4 ,
void T_2 * V_31 , T_3 V_32 ,
unsigned long V_33 )
{
struct V_9 * V_9 ;
struct V_34 V_35 ;
struct V_36 * V_37 ;
bool div = ! ( V_4 -> V_24 . V_33 & V_38 ) ;
if ( V_4 -> V_24 . V_33 & V_38 ) {
V_33 |= V_39 ;
V_35 . V_40 = & V_41 ;
} else if ( V_4 -> V_24 . V_33 & V_42 )
V_35 . V_40 = & V_43 ;
else
V_35 . V_40 = & V_44 ;
V_35 . V_28 = V_28 ;
V_35 . V_33 = V_33 ;
V_35 . V_29 = V_29 ;
V_35 . V_30 = V_30 ;
V_37 = F_11 ( V_4 -> V_24 . V_45 ) ;
if ( ! V_37 )
return F_12 ( - V_46 ) ;
V_4 -> V_2 . V_35 = & V_35 ;
V_4 -> V_47 = V_48 ;
V_4 -> V_8 . V_49 = V_31 + V_32 ;
V_4 -> V_16 . V_49 = div ? ( V_31 + V_32 ) : NULL ;
V_4 -> V_24 . V_31 = V_31 ;
V_4 -> V_24 . V_50 = V_37 ;
V_4 -> V_24 . V_51 = V_52 ;
V_9 = F_13 ( NULL , & V_4 -> V_2 ) ;
if ( F_14 ( V_9 ) )
return V_9 ;
V_4 -> V_8 . V_2 . V_9 = V_9 ;
V_4 -> V_16 . V_2 . V_9 = div ? V_9 : NULL ;
V_4 -> V_24 . V_2 . V_9 = V_9 ;
return V_9 ;
}
struct V_9 * F_15 ( const char * V_28 ,
const char * * V_29 , int V_30 ,
struct V_3 * V_4 , void T_2 * V_31 ,
T_3 V_32 , unsigned long V_33 )
{
return F_10 ( V_28 , V_29 , V_30 ,
V_4 , V_31 , V_32 , V_33 ) ;
}
struct V_9 * F_16 ( const char * V_28 ,
const char * * V_29 , int V_30 ,
struct V_3 * V_4 , void T_2 * V_31 ,
T_3 V_32 )
{
V_4 -> V_24 . V_33 |= V_38 ;
return F_10 ( V_28 , V_29 , V_30 ,
V_4 , V_31 , V_32 , V_39 ) ;
}
