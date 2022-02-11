static unsigned F_1 (
struct V_1 * V_2 ,
T_1 (* F_2)( struct V_1 * V_2 ,
unsigned V_3 ,
T_1 V_4 , T_2 V_5 ) ,
unsigned V_6 ,
struct V_7 * V_8
) {
unsigned V_5 = V_8 -> V_9 ;
unsigned V_10 = V_8 -> V_11 ;
const T_2 * V_12 = V_8 -> V_13 ;
T_2 * V_14 = V_8 -> V_15 ;
while ( F_3 ( V_10 > 0 ) ) {
T_2 V_4 = 0 ;
if ( V_12 )
V_4 = * V_12 ++ ;
V_4 = F_2 ( V_2 , V_6 , V_4 , V_5 ) ;
if ( V_14 )
* V_14 ++ = V_4 ;
V_10 -= 1 ;
}
return V_8 -> V_11 - V_10 ;
}
static unsigned F_4 (
struct V_1 * V_2 ,
T_1 (* F_2)( struct V_1 * V_2 ,
unsigned V_3 ,
T_1 V_4 , T_2 V_5 ) ,
unsigned V_6 ,
struct V_7 * V_8
) {
unsigned V_5 = V_8 -> V_9 ;
unsigned V_10 = V_8 -> V_11 ;
const T_3 * V_12 = V_8 -> V_13 ;
T_3 * V_14 = V_8 -> V_15 ;
while ( F_3 ( V_10 > 1 ) ) {
T_3 V_4 = 0 ;
if ( V_12 )
V_4 = * V_12 ++ ;
V_4 = F_2 ( V_2 , V_6 , V_4 , V_5 ) ;
if ( V_14 )
* V_14 ++ = V_4 ;
V_10 -= 2 ;
}
return V_8 -> V_11 - V_10 ;
}
static unsigned F_5 (
struct V_1 * V_2 ,
T_1 (* F_2)( struct V_1 * V_2 ,
unsigned V_3 ,
T_1 V_4 , T_2 V_5 ) ,
unsigned V_6 ,
struct V_7 * V_8
) {
unsigned V_5 = V_8 -> V_9 ;
unsigned V_10 = V_8 -> V_11 ;
const T_1 * V_12 = V_8 -> V_13 ;
T_1 * V_14 = V_8 -> V_15 ;
while ( F_3 ( V_10 > 3 ) ) {
T_1 V_4 = 0 ;
if ( V_12 )
V_4 = * V_12 ++ ;
V_4 = F_2 ( V_2 , V_6 , V_4 , V_5 ) ;
if ( V_14 )
* V_14 ++ = V_4 ;
V_10 -= 4 ;
}
return V_8 -> V_11 - V_10 ;
}
int F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
T_2 V_9 ;
T_1 V_19 ;
if ( V_8 ) {
V_9 = V_8 -> V_9 ;
V_19 = V_8 -> V_20 ;
} else {
V_9 = 0 ;
V_19 = 0 ;
}
if ( ! V_9 )
V_9 = V_2 -> V_9 ;
if ( V_9 <= 8 )
V_17 -> V_21 = F_1 ;
else if ( V_9 <= 16 )
V_17 -> V_21 = F_4 ;
else if ( V_9 <= 32 )
V_17 -> V_21 = F_5 ;
else
return - V_22 ;
if ( ! V_19 )
V_19 = V_2 -> V_23 ;
if ( V_19 ) {
V_17 -> V_3 = ( 1000000000 / 2 ) / V_19 ;
if ( V_17 -> V_3 > ( V_24 * 1000 * 1000 ) )
return - V_22 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_25 * V_26 ;
V_26 = F_8 ( V_2 -> V_27 ) ;
if ( ! V_17 ) {
V_17 = F_9 ( sizeof( * V_17 ) , V_28 ) ;
if ( ! V_17 )
return - V_29 ;
V_2 -> V_18 = V_17 ;
}
V_17 -> F_2 = V_26 -> F_2 [ V_2 -> V_30 & ( V_31 | V_32 ) ] ;
if ( ! V_17 -> F_2 )
return - V_22 ;
if ( V_26 -> V_33 ) {
int V_34 = V_26 -> V_33 ( V_2 , NULL ) ;
if ( V_34 < 0 )
return V_34 ;
}
F_10 ( & V_2 -> V_35 , L_1 , V_36 , 2 * V_17 -> V_3 ) ;
F_11 ( & V_26 -> V_37 ) ;
if ( ! V_26 -> V_38 ) {
V_26 -> V_39 ( V_2 , V_40 ) ;
F_12 ( V_17 -> V_3 ) ;
}
F_13 ( & V_26 -> V_37 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_18 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned V_3 = V_17 -> V_3 ;
return V_17 -> V_21 ( V_2 , V_17 -> F_2 , V_3 , V_8 ) ;
}
static int F_17 ( struct V_41 * V_2 )
{
struct V_25 * V_26 ;
V_26 = F_8 ( V_2 ) ;
F_11 ( & V_26 -> V_37 ) ;
V_26 -> V_38 = 1 ;
F_13 ( & V_26 -> V_37 ) ;
return 0 ;
}
static int F_18 ( struct V_41 * V_27 ,
struct V_1 * V_2 ,
struct V_7 * V_42 )
{
struct V_25 * V_26 = F_8 ( V_27 ) ;
int V_43 = 0 ;
if ( V_26 -> V_33 ) {
V_43 = V_26 -> V_33 ( V_2 , V_42 ) ;
if ( V_43 < 0 )
goto V_44;
}
if ( V_42 -> V_11 )
V_43 = V_26 -> V_21 ( V_2 , V_42 ) ;
if ( V_43 == V_42 -> V_11 )
V_43 = 0 ;
else if ( V_43 >= 0 )
V_43 = - V_45 ;
V_44:
F_19 ( V_27 ) ;
return V_43 ;
}
static int F_20 ( struct V_41 * V_2 )
{
struct V_25 * V_26 ;
V_26 = F_8 ( V_2 ) ;
F_11 ( & V_26 -> V_37 ) ;
V_26 -> V_38 = 0 ;
F_13 ( & V_26 -> V_37 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , bool V_46 )
{
struct V_25 * V_26 = F_8 ( V_2 -> V_27 ) ;
V_46 = ( ! ! ( V_2 -> V_30 & V_47 ) == V_46 ) ;
F_12 ( V_48 ) ;
V_26 -> V_39 ( V_2 , V_46 ? V_49 :
V_40 ) ;
F_12 ( V_48 ) ;
}
int F_22 ( struct V_25 * V_26 )
{
struct V_41 * V_27 = V_26 -> V_27 ;
int V_50 ;
if ( ! V_27 || ! V_26 -> V_39 )
return - V_22 ;
F_23 ( & V_26 -> V_37 ) ;
if ( ! V_27 -> V_51 )
V_27 -> V_51 = V_31 | V_32 | V_26 -> V_52 ;
if ( V_27 -> V_42 || V_27 -> V_53 )
return - V_22 ;
V_27 -> V_54 = F_17 ;
V_27 -> V_55 = F_20 ;
V_27 -> V_56 = F_18 ;
V_27 -> V_57 = F_21 ;
if ( ! V_26 -> V_21 ) {
V_26 -> V_58 = 0 ;
V_26 -> V_21 = F_16 ;
if ( ! V_27 -> V_59 ) {
if ( ! V_26 -> V_33 )
V_26 -> V_33 =
F_6 ;
V_27 -> V_59 = F_7 ;
V_27 -> V_60 = F_14 ;
}
}
V_50 = F_24 ( F_25 ( V_27 ) ) ;
if ( V_50 )
F_26 ( V_27 ) ;
return 0 ;
}
void F_27 ( struct V_25 * V_26 )
{
F_28 ( V_26 -> V_27 ) ;
}
