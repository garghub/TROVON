static unsigned int F_1 ( const struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> div > V_3 )
V_3 = V_4 -> div ;
return V_3 ;
}
static unsigned int F_2 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 & V_8 )
return F_3 ( V_6 ) ;
if ( V_6 -> V_7 & V_9 )
return 1 << F_3 ( V_6 ) ;
if ( V_6 -> V_2 )
return F_1 ( V_6 -> V_2 ) ;
return F_3 ( V_6 ) + 1 ;
}
static unsigned int F_4 ( const struct V_1 * V_2 ,
unsigned int V_10 )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> V_10 == V_10 )
return V_4 -> div ;
return 0 ;
}
static unsigned int F_5 ( struct V_5 * V_6 , unsigned int V_10 )
{
if ( V_6 -> V_7 & V_8 )
return V_10 ;
if ( V_6 -> V_7 & V_9 )
return 1 << V_10 ;
if ( V_6 -> V_2 )
return F_4 ( V_6 -> V_2 , V_10 ) ;
return V_10 + 1 ;
}
static unsigned int F_6 ( const struct V_1 * V_2 ,
unsigned int div )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> div == div )
return V_4 -> V_10 ;
return 0 ;
}
static unsigned int F_7 ( struct V_5 * V_6 , T_1 div )
{
if ( V_6 -> V_7 & V_8 )
return div ;
if ( V_6 -> V_7 & V_9 )
return F_8 ( div ) ;
if ( V_6 -> V_2 )
return F_6 ( V_6 -> V_2 , div ) ;
return div - 1 ;
}
static unsigned long F_9 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned int div , V_10 ;
V_10 = F_11 ( V_6 -> V_14 ) >> V_6 -> V_15 ;
V_10 &= F_3 ( V_6 ) ;
div = F_5 ( V_6 , V_10 ) ;
if ( ! div ) {
F_12 ( 1 , L_1 , V_16 ,
F_13 ( V_12 -> V_17 ) ) ;
return V_13 ;
}
return V_13 / div ;
}
static bool F_14 ( const struct V_1 * V_2 ,
unsigned int div )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> div == div )
return true ;
return false ;
}
static bool F_15 ( struct V_5 * V_6 , unsigned int div )
{
if ( V_6 -> V_7 & V_9 )
return F_16 ( div ) ;
if ( V_6 -> V_2 )
return F_14 ( V_6 -> V_2 , div ) ;
return true ;
}
static int F_17 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long * V_19 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_20 , V_21 = 0 ;
unsigned long V_13 , V_22 = 0 , V_23 , V_3 ;
if ( ! V_18 )
V_18 = 1 ;
V_3 = F_2 ( V_6 ) ;
if ( ! ( F_18 ( V_12 -> V_17 ) & V_24 ) ) {
V_13 = * V_19 ;
V_21 = F_19 ( V_13 , V_18 ) ;
V_21 = V_21 == 0 ? 1 : V_21 ;
V_21 = V_21 > V_3 ? V_3 : V_21 ;
return V_21 ;
}
V_3 = F_20 ( V_25 / V_18 , V_3 ) ;
for ( V_20 = 1 ; V_20 <= V_3 ; V_20 ++ ) {
if ( ! F_15 ( V_6 , V_20 ) )
continue;
V_13 = F_21 ( F_22 ( V_12 -> V_17 ) ,
F_23 ( V_18 , V_20 ) ) ;
V_23 = V_13 / V_20 ;
if ( V_23 <= V_18 && V_23 > V_22 ) {
V_21 = V_20 ;
V_22 = V_23 ;
* V_19 = V_13 ;
}
}
if ( ! V_21 ) {
V_21 = F_2 ( V_6 ) ;
* V_19 = F_21 ( F_22 ( V_12 -> V_17 ) , 1 ) ;
}
return V_21 ;
}
static long F_24 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long * V_26 )
{
int div ;
div = F_17 ( V_12 , V_18 , V_26 ) ;
return * V_26 / div ;
}
static int F_25 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long V_13 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned int div , V_27 ;
unsigned long V_7 = 0 ;
T_2 V_10 ;
div = V_13 / V_18 ;
V_27 = F_7 ( V_6 , div ) ;
if ( V_27 > F_3 ( V_6 ) )
V_27 = F_3 ( V_6 ) ;
if ( V_6 -> V_28 )
F_26 ( V_6 -> V_28 , V_7 ) ;
V_10 = F_11 ( V_6 -> V_14 ) ;
V_10 &= ~ ( F_3 ( V_6 ) << V_6 -> V_15 ) ;
V_10 |= V_27 << V_6 -> V_15 ;
F_27 ( V_10 , V_6 -> V_14 ) ;
if ( V_6 -> V_28 )
F_28 ( V_6 -> V_28 , V_7 ) ;
return 0 ;
}
static struct V_17 * F_29 ( struct V_29 * V_30 , const char * V_31 ,
const char * V_32 , unsigned long V_7 ,
void T_3 * V_14 , T_1 V_15 , T_1 V_33 ,
T_1 V_34 , const struct V_1 * V_2 ,
T_4 * V_28 )
{
struct V_5 * div ;
struct V_17 * V_17 ;
struct V_35 V_36 ;
div = F_30 ( sizeof( struct V_5 ) , V_37 ) ;
if ( ! div ) {
F_31 ( L_2 , V_16 ) ;
return F_32 ( - V_38 ) ;
}
V_36 . V_31 = V_31 ;
V_36 . V_39 = & V_40 ;
V_36 . V_7 = V_7 | V_41 ;
V_36 . V_42 = ( V_32 ? & V_32 : NULL ) ;
V_36 . V_43 = ( V_32 ? 1 : 0 ) ;
div -> V_14 = V_14 ;
div -> V_15 = V_15 ;
div -> V_33 = V_33 ;
div -> V_7 = V_34 ;
div -> V_28 = V_28 ;
div -> V_12 . V_36 = & V_36 ;
div -> V_2 = V_2 ;
V_17 = F_33 ( V_30 , & div -> V_12 ) ;
if ( F_34 ( V_17 ) )
F_35 ( div ) ;
return V_17 ;
}
struct V_17 * F_36 ( struct V_29 * V_30 , const char * V_31 ,
const char * V_32 , unsigned long V_7 ,
void T_3 * V_14 , T_1 V_15 , T_1 V_33 ,
T_1 V_34 , T_4 * V_28 )
{
return F_29 ( V_30 , V_31 , V_32 , V_7 , V_14 , V_15 ,
V_33 , V_34 , NULL , V_28 ) ;
}
struct V_17 * F_37 ( struct V_29 * V_30 , const char * V_31 ,
const char * V_32 , unsigned long V_7 ,
void T_3 * V_14 , T_1 V_15 , T_1 V_33 ,
T_1 V_34 , const struct V_1 * V_2 ,
T_4 * V_28 )
{
return F_29 ( V_30 , V_31 , V_32 , V_7 , V_14 , V_15 ,
V_33 , V_34 , V_2 , V_28 ) ;
}
