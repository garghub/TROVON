static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 -> V_7 ;
F_3 ( V_7 , V_2 ) ;
return V_6 -> V_8 ( V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 -> V_7 ;
F_3 ( V_7 , V_2 ) ;
return V_6 -> V_10 ( V_7 , V_9 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_12 = V_4 -> V_12 ;
struct V_1 * V_13 = V_4 -> V_13 ;
F_3 ( V_13 , V_2 ) ;
return V_12 -> V_14 ( V_13 , V_11 ) ;
}
static long F_6 ( struct V_1 * V_2 , unsigned long V_15 ,
unsigned long V_16 ,
unsigned long V_17 ,
unsigned long * V_18 ,
struct V_1 * * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_12 = V_4 -> V_12 ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_13 = V_4 -> V_13 ;
struct V_1 * V_7 = V_4 -> V_7 ;
struct V_20 * V_21 ;
unsigned long V_11 ;
long V_22 , V_23 = 0 ;
unsigned long V_24 ;
unsigned long V_25 = V_26 ;
int V_27 ;
if ( V_13 && V_12 && V_12 -> V_28 ) {
F_3 ( V_13 , V_2 ) ;
return V_12 -> V_28 ( V_13 , V_15 , V_16 ,
V_17 ,
V_18 ,
V_19 ) ;
} else if ( V_13 && V_12 && V_12 -> V_29 &&
V_7 && V_6 && V_6 -> V_10 ) {
* V_19 = NULL ;
if ( F_7 ( V_2 -> V_20 ) & V_30 ) {
V_21 = F_8 ( V_7 -> V_20 ) ;
* V_19 = F_9 ( V_21 ) ;
* V_18 = F_10 ( V_21 ) ;
return V_12 -> V_29 ( V_13 , V_15 ,
V_18 ) ;
}
for ( V_27 = 0 ; V_27 < F_11 ( V_7 -> V_20 ) ; V_27 ++ ) {
V_21 = F_12 ( V_7 -> V_20 , V_27 ) ;
if ( ! V_21 )
continue;
V_11 = F_10 ( V_21 ) ;
V_22 = V_12 -> V_29 ( V_13 , V_15 ,
& V_11 ) ;
if ( V_22 < 0 )
continue;
V_24 = abs ( V_15 - V_22 ) ;
if ( ! V_24 || ! * V_19
|| V_25 > V_24 ) {
* V_19 = F_9 ( V_21 ) ;
* V_18 = V_11 ;
V_25 = V_24 ;
V_23 = V_22 ;
}
if ( ! V_24 )
return V_15 ;
}
return V_23 ;
} else if ( V_7 && V_6 && V_6 -> V_28 ) {
F_3 ( V_7 , V_2 ) ;
return V_6 -> V_28 ( V_7 , V_15 , V_16 ,
V_17 , V_18 ,
V_19 ) ;
} else {
F_13 ( L_1 ) ;
return 0 ;
}
}
static long F_14 ( struct V_1 * V_2 , unsigned long V_15 ,
unsigned long * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_12 = V_4 -> V_12 ;
struct V_1 * V_13 = V_4 -> V_13 ;
F_3 ( V_13 , V_2 ) ;
return V_12 -> V_29 ( V_13 , V_15 , V_31 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_15 ,
unsigned long V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_12 = V_4 -> V_12 ;
struct V_1 * V_13 = V_4 -> V_13 ;
F_3 ( V_13 , V_2 ) ;
return V_12 -> V_32 ( V_13 , V_15 , V_11 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_33 = V_4 -> V_33 ;
struct V_1 * V_34 = V_4 -> V_34 ;
F_3 ( V_34 , V_2 ) ;
return V_33 -> V_35 ( V_34 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_33 = V_4 -> V_33 ;
struct V_1 * V_34 = V_4 -> V_34 ;
F_3 ( V_34 , V_2 ) ;
return V_33 -> V_36 ( V_34 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_33 = V_4 -> V_33 ;
struct V_1 * V_34 = V_4 -> V_34 ;
F_3 ( V_34 , V_2 ) ;
V_33 -> V_37 ( V_34 ) ;
}
struct V_20 * F_19 ( struct V_38 * V_39 , const char * V_40 ,
const char * * V_41 , int V_42 ,
struct V_1 * V_7 , const struct V_5 * V_6 ,
struct V_1 * V_13 , const struct V_5 * V_12 ,
struct V_1 * V_34 , const struct V_5 * V_33 ,
unsigned long V_43 )
{
struct V_20 * V_20 ;
struct V_44 V_45 ;
struct V_3 * V_4 ;
struct V_5 * V_46 ;
V_4 = F_20 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 ) {
F_13 ( L_2 , V_48 ) ;
return F_21 ( - V_49 ) ;
}
V_45 . V_40 = V_40 ;
V_45 . V_43 = V_43 | V_50 ;
V_45 . V_41 = V_41 ;
V_45 . V_42 = V_42 ;
V_46 = & V_4 -> V_51 ;
if ( V_7 && V_6 ) {
if ( ! V_6 -> V_8 ) {
V_20 = F_21 ( - V_52 ) ;
goto V_53;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_6 = V_6 ;
V_46 -> V_8 = F_1 ;
if ( V_6 -> V_10 )
V_46 -> V_10 = F_4 ;
if ( V_6 -> V_28 )
V_46 -> V_28 = F_6 ;
}
if ( V_13 && V_12 ) {
if ( ! V_12 -> V_14 ) {
V_20 = F_21 ( - V_52 ) ;
goto V_53;
}
V_46 -> V_14 = F_5 ;
if ( V_12 -> V_28 )
V_46 -> V_28 =
F_6 ;
else if ( V_12 -> V_29 )
V_46 -> V_29 =
F_14 ;
if ( V_12 -> V_32 ) {
if ( V_12 -> V_28 || V_12 -> V_29 )
V_46 -> V_32 =
F_15 ;
else
F_22 ( 1 , L_3 ,
V_48 ) ;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_12 = V_12 ;
}
if ( V_34 && V_33 ) {
if ( ! V_33 -> V_35 || ! V_33 -> V_36 ||
! V_33 -> V_37 ) {
V_20 = F_21 ( - V_52 ) ;
goto V_53;
}
V_4 -> V_34 = V_34 ;
V_4 -> V_33 = V_33 ;
V_46 -> V_35 = F_16 ;
V_46 -> V_36 = F_17 ;
V_46 -> V_37 = F_18 ;
}
V_45 . V_51 = V_46 ;
V_4 -> V_2 . V_45 = & V_45 ;
V_20 = F_23 ( V_39 , & V_4 -> V_2 ) ;
if ( F_24 ( V_20 ) )
goto V_53;
if ( V_4 -> V_7 )
V_4 -> V_7 -> V_20 = V_20 ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_20 = V_20 ;
if ( V_4 -> V_34 )
V_4 -> V_34 -> V_20 = V_20 ;
return V_20 ;
V_53:
F_25 ( V_4 ) ;
return V_20 ;
}
