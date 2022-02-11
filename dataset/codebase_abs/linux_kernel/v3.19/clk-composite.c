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
unsigned long * V_17 ,
struct V_1 * * V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_13 = V_4 -> V_13 ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_14 = V_4 -> V_14 ;
struct V_1 * V_7 = V_4 -> V_7 ;
struct V_8 * V_19 ;
unsigned long V_12 ;
long V_20 , V_21 = 0 ;
unsigned long V_22 ;
unsigned long V_23 = V_24 ;
int V_25 ;
if ( V_14 && V_13 && V_13 -> V_26 ) {
V_14 -> V_8 = V_2 -> V_8 ;
return V_13 -> V_26 ( V_14 , V_16 , V_17 ,
V_18 ) ;
} else if ( V_14 && V_13 && V_13 -> V_27 &&
V_7 && V_6 && V_6 -> V_11 ) {
* V_18 = NULL ;
if ( F_6 ( V_2 -> V_8 ) & V_28 ) {
V_19 = F_7 ( V_7 -> V_8 ) ;
* V_18 = F_8 ( V_19 ) ;
* V_17 = F_9 ( V_19 ) ;
return V_13 -> V_27 ( V_14 , V_16 ,
V_17 ) ;
}
for ( V_25 = 0 ; V_25 < F_10 ( V_7 -> V_8 ) ; V_25 ++ ) {
V_19 = F_11 ( V_7 -> V_8 , V_25 ) ;
if ( ! V_19 )
continue;
V_12 = F_9 ( V_19 ) ;
V_20 = V_13 -> V_27 ( V_14 , V_16 ,
& V_12 ) ;
if ( V_20 < 0 )
continue;
V_22 = abs ( V_16 - V_20 ) ;
if ( ! V_22 || ! * V_18
|| V_23 > V_22 ) {
* V_18 = F_8 ( V_19 ) ;
* V_17 = V_12 ;
V_23 = V_22 ;
V_21 = V_20 ;
}
if ( ! V_22 )
return V_16 ;
}
return V_21 ;
} else if ( V_7 && V_6 && V_6 -> V_26 ) {
V_7 -> V_8 = V_2 -> V_8 ;
return V_6 -> V_26 ( V_7 , V_16 , V_17 ,
V_18 ) ;
} else {
F_12 ( L_1 ) ;
return 0 ;
}
}
static long F_13 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long * V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_13 = V_4 -> V_13 ;
struct V_1 * V_14 = V_4 -> V_14 ;
V_14 -> V_8 = V_2 -> V_8 ;
return V_13 -> V_27 ( V_14 , V_16 , V_29 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_13 = V_4 -> V_13 ;
struct V_1 * V_14 = V_4 -> V_14 ;
V_14 -> V_8 = V_2 -> V_8 ;
return V_13 -> V_30 ( V_14 , V_16 , V_12 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_31 = V_4 -> V_31 ;
struct V_1 * V_32 = V_4 -> V_32 ;
V_32 -> V_8 = V_2 -> V_8 ;
return V_31 -> V_33 ( V_32 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_31 = V_4 -> V_31 ;
struct V_1 * V_32 = V_4 -> V_32 ;
V_32 -> V_8 = V_2 -> V_8 ;
return V_31 -> V_34 ( V_32 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_31 = V_4 -> V_31 ;
struct V_1 * V_32 = V_4 -> V_32 ;
V_32 -> V_8 = V_2 -> V_8 ;
V_31 -> V_35 ( V_32 ) ;
}
struct V_8 * F_18 ( struct V_36 * V_37 , const char * V_38 ,
const char * * V_39 , int V_40 ,
struct V_1 * V_7 , const struct V_5 * V_6 ,
struct V_1 * V_14 , const struct V_5 * V_13 ,
struct V_1 * V_32 , const struct V_5 * V_31 ,
unsigned long V_41 )
{
struct V_8 * V_8 ;
struct V_42 V_43 ;
struct V_3 * V_4 ;
struct V_5 * V_44 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 ) {
F_12 ( L_2 , V_46 ) ;
return F_20 ( - V_47 ) ;
}
V_43 . V_38 = V_38 ;
V_43 . V_41 = V_41 | V_48 ;
V_43 . V_39 = V_39 ;
V_43 . V_40 = V_40 ;
V_44 = & V_4 -> V_49 ;
if ( V_7 && V_6 ) {
if ( ! V_6 -> V_9 ) {
V_8 = F_20 ( - V_50 ) ;
goto V_51;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_6 = V_6 ;
V_44 -> V_9 = F_1 ;
if ( V_6 -> V_11 )
V_44 -> V_11 = F_3 ;
if ( V_6 -> V_26 )
V_44 -> V_26 = F_5 ;
}
if ( V_14 && V_13 ) {
if ( ! V_13 -> V_15 ) {
V_8 = F_20 ( - V_50 ) ;
goto V_51;
}
V_44 -> V_15 = F_4 ;
if ( V_13 -> V_26 )
V_44 -> V_26 =
F_5 ;
else if ( V_13 -> V_27 )
V_44 -> V_27 =
F_13 ;
if ( V_13 -> V_30 ) {
if ( V_13 -> V_26 || V_13 -> V_27 )
V_44 -> V_30 =
F_14 ;
else
F_21 ( 1 , L_3 ,
V_46 ) ;
}
V_4 -> V_14 = V_14 ;
V_4 -> V_13 = V_13 ;
}
if ( V_32 && V_31 ) {
if ( ! V_31 -> V_33 || ! V_31 -> V_34 ||
! V_31 -> V_35 ) {
V_8 = F_20 ( - V_50 ) ;
goto V_51;
}
V_4 -> V_32 = V_32 ;
V_4 -> V_31 = V_31 ;
V_44 -> V_33 = F_15 ;
V_44 -> V_34 = F_16 ;
V_44 -> V_35 = F_17 ;
}
V_43 . V_49 = V_44 ;
V_4 -> V_2 . V_43 = & V_43 ;
V_8 = F_22 ( V_37 , & V_4 -> V_2 ) ;
if ( F_23 ( V_8 ) )
goto V_51;
if ( V_4 -> V_7 )
V_4 -> V_7 -> V_8 = V_8 ;
if ( V_4 -> V_14 )
V_4 -> V_14 -> V_8 = V_8 ;
if ( V_4 -> V_32 )
V_4 -> V_32 -> V_8 = V_8 ;
return V_8 ;
V_51:
F_24 ( V_4 ) ;
return V_8 ;
}
