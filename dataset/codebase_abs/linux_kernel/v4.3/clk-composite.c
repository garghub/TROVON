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
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_12 = V_4 -> V_12 ;
const struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_13 = V_4 -> V_13 ;
struct V_1 * V_7 = V_4 -> V_7 ;
struct V_1 * V_17 ;
unsigned long V_11 ;
long V_18 , V_19 = 0 ;
unsigned long V_20 ;
unsigned long V_21 = V_22 ;
long V_23 ;
int V_24 ;
if ( V_13 && V_12 && V_12 -> V_25 ) {
F_3 ( V_13 , V_2 ) ;
return V_12 -> V_25 ( V_13 , V_16 ) ;
} else if ( V_13 && V_12 && V_12 -> V_26 &&
V_7 && V_6 && V_6 -> V_10 ) {
V_16 -> V_27 = NULL ;
if ( F_7 ( V_2 ) & V_28 ) {
V_17 = F_8 ( V_7 ) ;
V_16 -> V_27 = V_17 ;
V_16 -> V_29 = F_9 ( V_17 ) ;
V_23 = V_12 -> V_26 ( V_13 , V_16 -> V_23 ,
& V_16 -> V_29 ) ;
if ( V_23 < 0 )
return V_23 ;
V_16 -> V_23 = V_23 ;
return 0 ;
}
for ( V_24 = 0 ; V_24 < F_10 ( V_7 ) ; V_24 ++ ) {
V_17 = F_11 ( V_7 , V_24 ) ;
if ( ! V_17 )
continue;
V_11 = F_9 ( V_17 ) ;
V_18 = V_12 -> V_26 ( V_13 , V_16 -> V_23 ,
& V_11 ) ;
if ( V_18 < 0 )
continue;
V_20 = abs ( V_16 -> V_23 - V_18 ) ;
if ( ! V_20 || ! V_16 -> V_27
|| V_21 > V_20 ) {
V_16 -> V_27 = V_17 ;
V_16 -> V_29 = V_11 ;
V_21 = V_20 ;
V_19 = V_18 ;
}
if ( ! V_20 )
return 0 ;
}
V_16 -> V_23 = V_19 ;
return 0 ;
} else if ( V_7 && V_6 && V_6 -> V_25 ) {
F_3 ( V_7 , V_2 ) ;
return V_6 -> V_25 ( V_7 , V_16 ) ;
} else {
F_12 ( L_1 ) ;
return - V_30 ;
}
}
static long F_13 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_12 = V_4 -> V_12 ;
struct V_1 * V_13 = V_4 -> V_13 ;
F_3 ( V_13 , V_2 ) ;
return V_12 -> V_26 ( V_13 , V_23 , V_31 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_12 = V_4 -> V_12 ;
struct V_1 * V_13 = V_4 -> V_13 ;
F_3 ( V_13 , V_2 ) ;
return V_12 -> V_32 ( V_13 , V_23 , V_11 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_33 = V_4 -> V_33 ;
struct V_1 * V_34 = V_4 -> V_34 ;
F_3 ( V_34 , V_2 ) ;
return V_33 -> V_35 ( V_34 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_33 = V_4 -> V_33 ;
struct V_1 * V_34 = V_4 -> V_34 ;
F_3 ( V_34 , V_2 ) ;
return V_33 -> V_36 ( V_34 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_33 = V_4 -> V_33 ;
struct V_1 * V_34 = V_4 -> V_34 ;
F_3 ( V_34 , V_2 ) ;
V_33 -> V_37 ( V_34 ) ;
}
struct V_38 * F_18 ( struct V_39 * V_40 , const char * V_41 ,
const char * const * V_42 , int V_43 ,
struct V_1 * V_7 , const struct V_5 * V_6 ,
struct V_1 * V_13 , const struct V_5 * V_12 ,
struct V_1 * V_34 , const struct V_5 * V_33 ,
unsigned long V_44 )
{
struct V_38 * V_38 ;
struct V_45 V_46 ;
struct V_3 * V_4 ;
struct V_5 * V_47 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return F_20 ( - V_49 ) ;
V_46 . V_41 = V_41 ;
V_46 . V_44 = V_44 | V_50 ;
V_46 . V_42 = V_42 ;
V_46 . V_43 = V_43 ;
V_47 = & V_4 -> V_51 ;
if ( V_7 && V_6 ) {
if ( ! V_6 -> V_8 ) {
V_38 = F_20 ( - V_30 ) ;
goto V_52;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_6 = V_6 ;
V_47 -> V_8 = F_1 ;
if ( V_6 -> V_10 )
V_47 -> V_10 = F_4 ;
if ( V_6 -> V_25 )
V_47 -> V_25 = F_6 ;
}
if ( V_13 && V_12 ) {
if ( ! V_12 -> V_14 ) {
V_38 = F_20 ( - V_30 ) ;
goto V_52;
}
V_47 -> V_14 = F_5 ;
if ( V_12 -> V_25 )
V_47 -> V_25 =
F_6 ;
else if ( V_12 -> V_26 )
V_47 -> V_26 =
F_13 ;
if ( V_12 -> V_32 ) {
if ( V_12 -> V_25 || V_12 -> V_26 )
V_47 -> V_32 =
F_14 ;
else
F_21 ( 1 , L_2 ,
V_53 ) ;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_12 = V_12 ;
}
if ( V_34 && V_33 ) {
if ( ! V_33 -> V_35 || ! V_33 -> V_36 ||
! V_33 -> V_37 ) {
V_38 = F_20 ( - V_30 ) ;
goto V_52;
}
V_4 -> V_34 = V_34 ;
V_4 -> V_33 = V_33 ;
V_47 -> V_35 = F_15 ;
V_47 -> V_36 = F_16 ;
V_47 -> V_37 = F_17 ;
}
V_46 . V_51 = V_47 ;
V_4 -> V_2 . V_46 = & V_46 ;
V_38 = F_22 ( V_40 , & V_4 -> V_2 ) ;
if ( F_23 ( V_38 ) )
goto V_52;
if ( V_4 -> V_7 )
V_4 -> V_7 -> V_38 = V_38 ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_38 = V_38 ;
if ( V_4 -> V_34 )
V_4 -> V_34 -> V_38 = V_38 ;
return V_38 ;
V_52:
F_24 ( V_4 ) ;
return V_38 ;
}
