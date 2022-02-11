static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 -> V_7 ;
V_7 -> V_8 = V_2 -> V_8 ;
return V_6 -> V_9 ( V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 -> V_7 ;
V_7 -> V_8 = V_2 -> V_8 ;
return V_6 -> V_11 ( V_7 , V_10 ) ;
}
static unsigned long F_4 ( struct V_1 * V_2 ,
unsigned long V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_13 = V_4 -> V_13 ;
struct V_1 * V_14 = V_4 -> V_14 ;
V_14 -> V_8 = V_2 -> V_8 ;
return V_13 -> V_15 ( V_14 , V_12 ) ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_13 = V_4 -> V_13 ;
struct V_1 * V_14 = V_4 -> V_14 ;
V_14 -> V_8 = V_2 -> V_8 ;
return V_13 -> V_18 ( V_14 , V_16 , V_17 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_13 = V_4 -> V_13 ;
struct V_1 * V_14 = V_4 -> V_14 ;
V_14 -> V_8 = V_2 -> V_8 ;
return V_13 -> V_19 ( V_14 , V_16 , V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_20 = V_4 -> V_20 ;
struct V_1 * V_21 = V_4 -> V_21 ;
V_21 -> V_8 = V_2 -> V_8 ;
return V_20 -> V_22 ( V_21 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_20 = V_4 -> V_20 ;
struct V_1 * V_21 = V_4 -> V_21 ;
V_21 -> V_8 = V_2 -> V_8 ;
return V_20 -> V_23 ( V_21 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_20 = V_4 -> V_20 ;
struct V_1 * V_21 = V_4 -> V_21 ;
V_21 -> V_8 = V_2 -> V_8 ;
V_20 -> V_24 ( V_21 ) ;
}
struct V_8 * F_10 ( struct V_25 * V_26 , const char * V_27 ,
const char * * V_28 , int V_29 ,
struct V_1 * V_7 , const struct V_5 * V_6 ,
struct V_1 * V_14 , const struct V_5 * V_13 ,
struct V_1 * V_21 , const struct V_5 * V_20 ,
unsigned long V_30 )
{
struct V_8 * V_8 ;
struct V_31 V_32 ;
struct V_3 * V_4 ;
struct V_5 * V_33 ;
V_4 = F_11 ( sizeof( * V_4 ) , V_34 ) ;
if ( ! V_4 ) {
F_12 ( L_1 , V_35 ) ;
return F_13 ( - V_36 ) ;
}
V_32 . V_27 = V_27 ;
V_32 . V_30 = V_30 | V_37 ;
V_32 . V_28 = V_28 ;
V_32 . V_29 = V_29 ;
V_33 = & V_4 -> V_38 ;
if ( V_7 && V_6 ) {
if ( ! V_6 -> V_9 || ! V_6 -> V_11 ) {
V_8 = F_13 ( - V_39 ) ;
goto V_40;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_6 = V_6 ;
V_33 -> V_9 = F_1 ;
V_33 -> V_11 = F_3 ;
}
if ( V_14 && V_13 ) {
if ( ! V_13 -> V_15 ) {
V_8 = F_13 ( - V_39 ) ;
goto V_40;
}
if ( V_13 -> V_18 ) {
V_33 -> V_18 = F_5 ;
if ( V_13 -> V_19 ) {
V_33 -> V_19 = F_6 ;
}
} else {
F_14 ( V_13 -> V_19 ,
L_2 ,
V_35 ) ;
}
V_4 -> V_14 = V_14 ;
V_4 -> V_13 = V_13 ;
V_33 -> V_15 = F_4 ;
}
if ( V_21 && V_20 ) {
if ( ! V_20 -> V_22 || ! V_20 -> V_23 ||
! V_20 -> V_24 ) {
V_8 = F_13 ( - V_39 ) ;
goto V_40;
}
V_4 -> V_21 = V_21 ;
V_4 -> V_20 = V_20 ;
V_33 -> V_22 = F_7 ;
V_33 -> V_23 = F_8 ;
V_33 -> V_24 = F_9 ;
}
V_32 . V_38 = V_33 ;
V_4 -> V_2 . V_32 = & V_32 ;
V_8 = F_15 ( V_26 , & V_4 -> V_2 ) ;
if ( F_16 ( V_8 ) )
goto V_40;
if ( V_4 -> V_7 )
V_4 -> V_7 -> V_8 = V_8 ;
if ( V_4 -> V_14 )
V_4 -> V_14 -> V_8 = V_8 ;
if ( V_4 -> V_21 )
V_4 -> V_21 -> V_8 = V_8 ;
return V_8 ;
V_40:
F_17 ( V_4 ) ;
return V_8 ;
}
