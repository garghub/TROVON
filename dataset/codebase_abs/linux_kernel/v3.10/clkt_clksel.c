static const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_3 * V_4 )
{
const struct V_1 * V_5 ;
if ( ! V_4 )
return NULL ;
for ( V_5 = V_3 -> V_1 ; V_5 -> V_6 ; V_5 ++ )
if ( V_5 -> V_6 == V_4 )
break;
if ( ! V_5 -> V_6 ) {
F_2 ( 1 , L_1 ,
F_3 ( V_3 -> V_7 . V_3 ) , F_3 ( V_4 ) ) ;
return NULL ;
}
return V_5 ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_8 )
{
T_1 V_9 ;
V_9 = F_5 ( V_3 -> V_10 ) ;
V_9 &= ~ V_3 -> V_11 ;
V_9 |= V_8 << F_6 ( V_3 -> V_11 ) ;
F_7 ( V_9 , V_3 -> V_10 ) ;
V_9 = F_5 ( V_3 -> V_10 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 , T_1 V_8 )
{
const struct V_1 * V_5 ;
const struct V_12 * V_13 ;
struct V_3 * V_6 ;
V_6 = F_9 ( V_3 -> V_7 . V_3 ) ;
V_5 = F_1 ( V_3 , V_6 ) ;
if ( ! V_5 )
return 0 ;
for ( V_13 = V_5 -> V_14 ; V_13 -> div ; V_13 ++ ) {
if ( ! ( V_13 -> V_15 & V_16 ) )
continue;
if ( V_13 -> V_17 == V_8 )
break;
}
if ( ! V_13 -> div ) {
F_2 ( 1 , L_2 ,
F_3 ( V_3 -> V_7 . V_3 ) , V_8 ,
F_3 ( V_6 ) ) ;
return 0 ;
}
return V_13 -> div ;
}
static T_1 F_10 ( struct V_2 * V_3 , T_1 div )
{
const struct V_1 * V_5 ;
const struct V_12 * V_13 ;
struct V_3 * V_6 ;
F_11 ( div == 0 ) ;
V_6 = F_9 ( V_3 -> V_7 . V_3 ) ;
V_5 = F_1 ( V_3 , V_6 ) ;
if ( ! V_5 )
return ~ 0 ;
for ( V_13 = V_5 -> V_14 ; V_13 -> div ; V_13 ++ ) {
if ( ! ( V_13 -> V_15 & V_16 ) )
continue;
if ( V_13 -> div == div )
break;
}
if ( ! V_13 -> div ) {
F_12 ( L_3 ,
F_3 ( V_3 -> V_7 . V_3 ) , div ,
F_3 ( V_6 ) ) ;
return ~ 0 ;
}
return V_13 -> V_17 ;
}
static T_1 F_13 ( struct V_2 * V_3 )
{
T_1 V_9 ;
if ( ! V_3 -> V_1 || ! V_3 -> V_11 )
return 0 ;
V_9 = F_5 ( V_3 -> V_10 ) ;
V_9 &= V_3 -> V_11 ;
V_9 >>= F_6 ( V_3 -> V_11 ) ;
return F_8 ( V_3 , V_9 ) ;
}
T_1 F_14 ( struct V_2 * V_3 ,
unsigned long V_18 ,
T_1 * V_19 )
{
unsigned long V_20 ;
const struct V_1 * V_5 ;
const struct V_12 * V_13 ;
T_1 V_21 = 0 ;
struct V_3 * V_6 ;
unsigned long V_22 ;
const char * V_23 ;
V_6 = F_9 ( V_3 -> V_7 . V_3 ) ;
V_23 = F_3 ( V_3 -> V_7 . V_3 ) ;
V_22 = F_15 ( V_6 ) ;
if ( ! V_3 -> V_1 || ! V_3 -> V_11 )
return ~ 0 ;
F_16 ( L_4 ,
V_23 , V_18 ) ;
* V_19 = 1 ;
V_5 = F_1 ( V_3 , V_6 ) ;
if ( ! V_5 )
return ~ 0 ;
for ( V_13 = V_5 -> V_14 ; V_13 -> div ; V_13 ++ ) {
if ( ! ( V_13 -> V_15 & V_16 ) )
continue;
if ( V_13 -> div <= V_21 )
F_12 ( L_5 ,
V_23 ) ;
V_21 = V_13 -> div ;
V_20 = V_22 / V_13 -> div ;
if ( V_20 <= V_18 )
break;
}
if ( ! V_13 -> div ) {
F_12 ( L_6 ,
V_23 , V_18 , F_3 ( V_6 ) ) ;
return ~ 0 ;
}
* V_19 = V_13 -> div ;
F_16 ( L_7 , * V_19 ,
( V_22 / V_13 -> div ) ) ;
return V_22 / V_13 -> div ;
}
T_2 F_17 ( struct V_24 * V_7 )
{
struct V_2 * V_3 = F_18 ( V_7 ) ;
const struct V_1 * V_5 ;
const struct V_12 * V_13 ;
T_1 V_25 , V_26 = 0 ;
struct V_3 * V_6 ;
const char * V_23 ;
int V_27 = 0 , V_28 = 0 ;
V_6 = F_9 ( V_7 -> V_3 ) ;
V_23 = F_3 ( V_7 -> V_3 ) ;
F_2 ( ( ! V_3 -> V_1 || ! V_3 -> V_11 ) ,
L_8 , V_23 ) ;
V_25 = F_5 ( V_3 -> V_10 ) & V_3 -> V_11 ;
V_25 >>= F_6 ( V_3 -> V_11 ) ;
for ( V_5 = V_3 -> V_1 ; V_5 -> V_6 && ! V_26 ; V_5 ++ ) {
for ( V_13 = V_5 -> V_14 ; V_13 -> div && ! V_26 ; V_13 ++ ) {
if ( ! ( V_13 -> V_15 & V_16 ) )
continue;
if ( V_13 -> V_17 == V_25 ) {
V_26 = 1 ;
V_27 = V_28 ;
}
}
V_28 ++ ;
}
F_2 ( ! V_26 , L_9 ,
V_23 , V_25 ) ;
return V_27 ;
}
unsigned long F_19 ( struct V_24 * V_7 , unsigned long V_22 )
{
unsigned long V_29 ;
T_1 div = 0 ;
struct V_2 * V_3 = F_18 ( V_7 ) ;
if ( ! V_22 )
return 0 ;
div = F_13 ( V_3 ) ;
if ( ! div )
V_29 = V_22 ;
else
V_29 = V_22 / div ;
F_16 ( L_10 , V_30 ,
F_3 ( V_7 -> V_3 ) , V_29 , div ) ;
return V_29 ;
}
long F_20 ( struct V_24 * V_7 , unsigned long V_18 ,
unsigned long * V_22 )
{
struct V_2 * V_3 = F_18 ( V_7 ) ;
T_1 V_19 ;
return F_14 ( V_3 , V_18 , & V_19 ) ;
}
int F_21 ( struct V_24 * V_7 , unsigned long V_29 ,
unsigned long V_22 )
{
struct V_2 * V_3 = F_18 ( V_7 ) ;
T_1 V_8 , V_31 , V_19 = 0 ;
if ( ! V_3 -> V_1 || ! V_3 -> V_11 )
return - V_32 ;
V_31 = F_14 ( V_3 , V_29 , & V_19 ) ;
if ( V_31 != V_29 )
return - V_32 ;
V_8 = F_10 ( V_3 , V_19 ) ;
if ( V_8 == ~ 0 )
return - V_32 ;
F_4 ( V_3 , V_8 ) ;
F_16 ( L_11 , F_3 ( V_7 -> V_3 ) ,
F_15 ( V_7 -> V_3 ) ) ;
return 0 ;
}
int F_22 ( struct V_24 * V_7 , T_2 V_8 )
{
struct V_2 * V_3 = F_18 ( V_7 ) ;
if ( ! V_3 -> V_1 || ! V_3 -> V_11 )
return - V_32 ;
F_4 ( V_3 , V_8 ) ;
return 0 ;
}
