static const struct V_1 * F_1 ( struct V_2 * V_2 ,
struct V_2 * V_3 )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 -> V_1 ; V_4 -> V_5 ; V_4 ++ )
if ( V_4 -> V_5 == V_3 )
break;
if ( ! V_4 -> V_5 ) {
F_2 ( 1 , L_1
L_2 , V_3 -> V_6 , V_2 -> V_6 ) ;
return NULL ;
}
return V_4 ;
}
static T_1 F_3 ( struct V_2 * V_3 , struct V_2 * V_2 ,
T_2 * V_7 )
{
const struct V_1 * V_4 ;
const struct V_8 * V_9 , * V_10 = NULL ;
T_1 V_11 = 0 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ! V_4 )
return 0 ;
for ( V_9 = V_4 -> V_12 ; V_9 -> div ; V_9 ++ ) {
if ( ! ( V_9 -> V_13 & V_14 ) )
continue;
if ( V_9 -> div > V_11 ) {
V_11 = V_9 -> div ;
V_10 = V_9 ;
}
}
if ( V_11 == 0 ) {
F_2 ( 1 , L_3
L_4 , V_2 -> V_6 , V_3 -> V_5 -> V_6 ) ;
return 0 ;
}
* V_7 = V_10 -> V_15 ;
return V_11 ;
}
static void F_4 ( struct V_2 * V_2 , T_2 V_7 )
{
T_2 V_16 ;
V_16 = F_5 ( V_2 -> V_17 ) ;
V_16 &= ~ V_2 -> V_18 ;
V_16 |= V_7 << F_6 ( V_2 -> V_18 ) ;
F_7 ( V_16 , V_2 -> V_17 ) ;
V_16 = F_5 ( V_2 -> V_17 ) ;
}
static T_2 F_8 ( struct V_2 * V_2 , T_2 V_7 )
{
const struct V_1 * V_4 ;
const struct V_8 * V_9 ;
V_4 = F_1 ( V_2 , V_2 -> V_5 ) ;
if ( ! V_4 )
return 0 ;
for ( V_9 = V_4 -> V_12 ; V_9 -> div ; V_9 ++ ) {
if ( ! ( V_9 -> V_13 & V_14 ) )
continue;
if ( V_9 -> V_15 == V_7 )
break;
}
if ( ! V_9 -> div ) {
F_2 ( 1 , L_5
L_6 , V_7 , V_2 -> V_6 , V_2 -> V_5 -> V_6 ) ;
return 0 ;
}
return V_9 -> div ;
}
static T_2 F_9 ( struct V_2 * V_2 , T_2 div )
{
const struct V_1 * V_4 ;
const struct V_8 * V_9 ;
F_10 ( div == 0 ) ;
V_4 = F_1 ( V_2 , V_2 -> V_5 ) ;
if ( ! V_4 )
return ~ 0 ;
for ( V_9 = V_4 -> V_12 ; V_9 -> div ; V_9 ++ ) {
if ( ! ( V_9 -> V_13 & V_14 ) )
continue;
if ( V_9 -> div == div )
break;
}
if ( ! V_9 -> div ) {
F_11 ( L_7
L_6 , div , V_2 -> V_6 , V_2 -> V_5 -> V_6 ) ;
return ~ 0 ;
}
return V_9 -> V_15 ;
}
static T_2 F_12 ( struct V_2 * V_2 )
{
T_2 V_16 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_18 )
return 0 ;
V_16 = F_5 ( V_2 -> V_17 ) ;
V_16 &= V_2 -> V_18 ;
V_16 >>= F_6 ( V_2 -> V_18 ) ;
return F_8 ( V_2 , V_16 ) ;
}
T_2 F_13 ( struct V_2 * V_2 , unsigned long V_19 ,
T_2 * V_20 )
{
unsigned long V_21 ;
const struct V_1 * V_4 ;
const struct V_8 * V_9 ;
T_2 V_22 = 0 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_18 )
return ~ 0 ;
F_14 ( L_8 ,
V_2 -> V_6 , V_19 ) ;
* V_20 = 1 ;
V_4 = F_1 ( V_2 , V_2 -> V_5 ) ;
if ( ! V_4 )
return ~ 0 ;
for ( V_9 = V_4 -> V_12 ; V_9 -> div ; V_9 ++ ) {
if ( ! ( V_9 -> V_13 & V_14 ) )
continue;
if ( V_9 -> div <= V_22 )
F_11 ( L_9
L_10 , V_2 -> V_6 ) ;
V_22 = V_9 -> div ;
V_21 = V_2 -> V_5 -> V_23 / V_9 -> div ;
if ( V_21 <= V_19 )
break;
}
if ( ! V_9 -> div ) {
F_11 ( L_11
L_12 , V_19 ,
V_2 -> V_6 , V_2 -> V_5 -> V_6 ) ;
return ~ 0 ;
}
* V_20 = V_9 -> div ;
F_14 ( L_13 , * V_20 ,
( V_2 -> V_5 -> V_23 / V_9 -> div ) ) ;
return V_2 -> V_5 -> V_23 / V_9 -> div ;
}
void F_15 ( struct V_2 * V_2 )
{
const struct V_1 * V_4 ;
const struct V_8 * V_9 ;
T_2 V_24 , V_25 = 0 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_18 )
return;
V_24 = F_5 ( V_2 -> V_17 ) & V_2 -> V_18 ;
V_24 >>= F_6 ( V_2 -> V_18 ) ;
for ( V_4 = V_2 -> V_1 ; V_4 -> V_5 && ! V_25 ; V_4 ++ ) {
for ( V_9 = V_4 -> V_12 ; V_9 -> div && ! V_25 ; V_9 ++ ) {
if ( ! ( V_9 -> V_13 & V_14 ) )
continue;
if ( V_9 -> V_15 == V_24 ) {
if ( V_2 -> V_5 != V_4 -> V_5 ) {
F_14 ( L_14
L_15 ,
V_2 -> V_6 , V_4 -> V_5 -> V_6 ,
( ( V_2 -> V_5 ) ?
V_2 -> V_5 -> V_6 : L_16 ) ) ;
F_16 ( V_2 , V_4 -> V_5 ) ;
} ;
V_25 = 1 ;
}
}
}
F_2 ( ! V_25 , L_17 ,
V_2 -> V_6 , V_24 ) ;
return;
}
unsigned long F_17 ( struct V_2 * V_2 )
{
unsigned long V_23 ;
T_2 div = 0 ;
div = F_12 ( V_2 ) ;
if ( div == 0 )
return V_2 -> V_23 ;
V_23 = V_2 -> V_5 -> V_23 / div ;
F_14 ( L_18 , V_2 -> V_6 ,
V_23 , div ) ;
return V_23 ;
}
long F_18 ( struct V_2 * V_2 , unsigned long V_19 )
{
T_2 V_20 ;
return F_13 ( V_2 , V_19 , & V_20 ) ;
}
int F_19 ( struct V_2 * V_2 , unsigned long V_23 )
{
T_2 V_7 , V_26 , V_20 = 0 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_18 )
return - V_27 ;
V_26 = F_13 ( V_2 , V_23 , & V_20 ) ;
if ( V_26 != V_23 )
return - V_27 ;
V_7 = F_9 ( V_2 , V_20 ) ;
if ( V_7 == ~ 0 )
return - V_27 ;
F_4 ( V_2 , V_7 ) ;
V_2 -> V_23 = V_2 -> V_5 -> V_23 / V_20 ;
F_14 ( L_19 , V_2 -> V_6 , V_2 -> V_23 ) ;
return 0 ;
}
int F_20 ( struct V_2 * V_2 , struct V_2 * V_28 )
{
T_2 V_7 = 0 ;
T_2 V_29 ;
if ( ! V_2 -> V_1 || ! V_2 -> V_18 )
return - V_27 ;
V_29 = F_3 ( V_28 , V_2 , & V_7 ) ;
if ( ! V_29 )
return - V_27 ;
F_4 ( V_2 , V_7 ) ;
F_16 ( V_2 , V_28 ) ;
V_2 -> V_23 = V_28 -> V_23 ;
if ( V_29 > 0 )
V_2 -> V_23 /= V_29 ;
F_14 ( L_20 ,
V_2 -> V_6 , V_2 -> V_5 -> V_6 , V_2 -> V_23 ) ;
return 0 ;
}
