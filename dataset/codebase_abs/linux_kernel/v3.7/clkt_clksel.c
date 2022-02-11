static const struct V_1 * F_1 ( struct V_2 * V_2 ,
struct V_2 * V_3 )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 -> V_1 ; V_4 -> V_5 ; V_4 ++ )
if ( V_4 -> V_5 == V_3 )
break;
if ( ! V_4 -> V_5 ) {
F_2 ( 1 , L_1 ,
F_3 ( V_2 ) , F_3 ( V_3 ) ) ;
return NULL ;
}
return V_4 ;
}
static T_1 F_4 ( struct V_2 * V_3 , struct V_2 * V_2 ,
T_2 * V_6 )
{
const struct V_1 * V_4 ;
const struct V_7 * V_8 , * V_9 = NULL ;
T_1 V_10 = 0 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ! V_4 )
return 0 ;
for ( V_8 = V_4 -> V_11 ; V_8 -> div ; V_8 ++ ) {
if ( ! ( V_8 -> V_12 & V_13 ) )
continue;
if ( V_8 -> div > V_10 ) {
V_10 = V_8 -> div ;
V_9 = V_8 ;
}
}
if ( V_10 == 0 ) {
F_2 ( 1 , L_2 ,
F_3 ( V_2 ) ,
F_3 ( F_5 ( V_3 ) ) ) ;
return 0 ;
}
* V_6 = V_9 -> V_14 ;
return V_10 ;
}
static void F_6 ( struct V_2 * V_2 , T_2 V_6 )
{
T_2 V_15 ;
V_15 = F_7 ( V_2 -> V_16 ) ;
V_15 &= ~ V_2 -> V_17 ;
V_15 |= V_6 << F_8 ( V_2 -> V_17 ) ;
F_9 ( V_15 , V_2 -> V_16 ) ;
V_15 = F_7 ( V_2 -> V_16 ) ;
}
static T_2 F_10 ( struct V_2 * V_2 , T_2 V_6 )
{
const struct V_1 * V_4 ;
const struct V_7 * V_8 ;
struct V_2 * V_5 ;
V_5 = F_5 ( V_2 ) ;
V_4 = F_1 ( V_2 , V_5 ) ;
if ( ! V_4 )
return 0 ;
for ( V_8 = V_4 -> V_11 ; V_8 -> div ; V_8 ++ ) {
if ( ! ( V_8 -> V_12 & V_13 ) )
continue;
if ( V_8 -> V_14 == V_6 )
break;
}
if ( ! V_8 -> div ) {
F_2 ( 1 , L_3 ,
F_3 ( V_2 ) , V_6 , F_3 ( V_5 ) ) ;
return 0 ;
}
return V_8 -> div ;
}
static T_2 F_11 ( struct V_2 * V_2 , T_2 div )
{
const struct V_1 * V_4 ;
const struct V_7 * V_8 ;
struct V_2 * V_5 ;
F_12 ( div == 0 ) ;
V_5 = F_5 ( V_2 ) ;
V_4 = F_1 ( V_2 , V_5 ) ;
if ( ! V_4 )
return ~ 0 ;
for ( V_8 = V_4 -> V_11 ; V_8 -> div ; V_8 ++ ) {
if ( ! ( V_8 -> V_12 & V_13 ) )
continue;
if ( V_8 -> div == div )
break;
}
if ( ! V_8 -> div ) {
F_13 ( L_4 ,
F_3 ( V_2 ) , div , F_3 ( V_5 ) ) ;
return ~ 0 ;
}
return V_8 -> V_14 ;
}
static T_2 F_14 ( struct V_2 * V_2 )
{
T_2 V_15 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_17 )
return 0 ;
V_15 = F_7 ( V_2 -> V_16 ) ;
V_15 &= V_2 -> V_17 ;
V_15 >>= F_8 ( V_2 -> V_17 ) ;
return F_10 ( V_2 , V_15 ) ;
}
T_2 F_15 ( struct V_2 * V_2 , unsigned long V_18 ,
T_2 * V_19 )
{
unsigned long V_20 ;
const struct V_1 * V_4 ;
const struct V_7 * V_8 ;
T_2 V_21 = 0 ;
struct V_2 * V_5 ;
unsigned long V_22 ;
const char * V_23 ;
V_5 = F_5 ( V_2 ) ;
V_22 = F_16 ( V_5 ) ;
V_23 = F_3 ( V_2 ) ;
if ( ! V_2 -> V_1 || ! V_2 -> V_17 )
return ~ 0 ;
F_17 ( L_5 ,
V_23 , V_18 ) ;
* V_19 = 1 ;
V_4 = F_1 ( V_2 , V_5 ) ;
if ( ! V_4 )
return ~ 0 ;
for ( V_8 = V_4 -> V_11 ; V_8 -> div ; V_8 ++ ) {
if ( ! ( V_8 -> V_12 & V_13 ) )
continue;
if ( V_8 -> div <= V_21 )
F_13 ( L_6 ,
V_23 ) ;
V_21 = V_8 -> div ;
V_20 = V_22 / V_8 -> div ;
if ( V_20 <= V_18 )
break;
}
if ( ! V_8 -> div ) {
F_13 ( L_7 ,
V_23 , V_18 , F_3 ( V_5 ) ) ;
return ~ 0 ;
}
* V_19 = V_8 -> div ;
F_17 ( L_8 , * V_19 ,
( V_22 / V_8 -> div ) ) ;
return V_22 / V_8 -> div ;
}
void F_18 ( struct V_2 * V_2 )
{
const struct V_1 * V_4 ;
const struct V_7 * V_8 ;
T_2 V_24 , V_25 = 0 ;
struct V_2 * V_5 ;
const char * V_23 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_17 )
return;
V_5 = F_5 ( V_2 ) ;
V_23 = F_3 ( V_2 ) ;
V_24 = F_7 ( V_2 -> V_16 ) & V_2 -> V_17 ;
V_24 >>= F_8 ( V_2 -> V_17 ) ;
for ( V_4 = V_2 -> V_1 ; V_4 -> V_5 && ! V_25 ; V_4 ++ ) {
for ( V_8 = V_4 -> V_11 ; V_8 -> div && ! V_25 ; V_8 ++ ) {
if ( ! ( V_8 -> V_12 & V_13 ) )
continue;
if ( V_8 -> V_14 == V_24 ) {
if ( V_5 != V_4 -> V_5 ) {
F_17 ( L_9 ,
V_23 ,
F_3 ( V_4 -> V_5 ) ,
( ( V_5 ) ?
F_3 ( V_5 ) :
L_10 ) ) ;
F_19 ( V_2 , V_4 -> V_5 ) ;
}
V_25 = 1 ;
}
}
}
F_2 ( ! V_25 , L_11 ,
V_23 , V_24 ) ;
return;
}
unsigned long F_20 ( struct V_2 * V_2 )
{
unsigned long V_26 ;
T_2 div = 0 ;
struct V_2 * V_5 ;
div = F_14 ( V_2 ) ;
if ( div == 0 )
return F_16 ( V_2 ) ;
V_5 = F_5 ( V_2 ) ;
V_26 = F_16 ( V_5 ) / div ;
F_17 ( L_12 ,
F_3 ( V_2 ) , V_26 , div ) ;
return V_26 ;
}
long F_21 ( struct V_2 * V_2 , unsigned long V_18 )
{
T_2 V_19 ;
return F_15 ( V_2 , V_18 , & V_19 ) ;
}
int F_22 ( struct V_2 * V_2 , unsigned long V_26 )
{
T_2 V_6 , V_27 , V_19 = 0 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_17 )
return - V_28 ;
V_27 = F_15 ( V_2 , V_26 , & V_19 ) ;
if ( V_27 != V_26 )
return - V_28 ;
V_6 = F_11 ( V_2 , V_19 ) ;
if ( V_6 == ~ 0 )
return - V_28 ;
F_6 ( V_2 , V_6 ) ;
V_2 -> V_26 = F_16 ( F_5 ( V_2 ) ) / V_19 ;
F_17 ( L_13 , F_3 ( V_2 ) ,
F_16 ( V_2 ) ) ;
return 0 ;
}
int F_23 ( struct V_2 * V_2 , struct V_2 * V_29 )
{
T_2 V_6 = 0 ;
T_2 V_30 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_17 )
return - V_28 ;
V_30 = F_4 ( V_29 , V_2 , & V_6 ) ;
if ( ! V_30 )
return - V_28 ;
F_6 ( V_2 , V_6 ) ;
F_19 ( V_2 , V_29 ) ;
V_2 -> V_26 = F_16 ( V_29 ) ;
if ( V_30 > 0 )
F_16 ( V_2 ) /= V_30 ;
F_17 ( L_14 ,
F_3 ( V_2 ) ,
F_3 ( F_5 ( V_2 ) ) ,
F_16 ( V_2 ) ) ;
return 0 ;
}
