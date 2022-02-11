static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( ! V_9 )
V_9 = F_2 ( F_3 ( V_4 ) , V_2 , F_4 ( V_4 ) ) ;
if ( V_9 ) {
bool V_10 ;
bool V_11 = true ;
V_10 = ( ! ( V_6 -> V_12 & V_13 ) &&
F_5 ( V_9 ) &&
F_6 ( V_9 ) -> V_14 == 0 ) ;
if ( V_6 -> V_12 & V_15 )
V_11 = F_7 ( V_9 ) ;
if ( V_6 -> V_12 & V_16 && ! V_10 &&
V_11 && F_5 ( V_9 ) )
V_7 -> V_17 = V_9 -> V_18 ;
if ( V_9 != V_2 -> V_9 )
F_8 ( V_9 ) ;
if ( V_10 || ! V_11 )
V_9 = NULL ;
}
return V_9 != NULL ;
}
static bool
F_9 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
static struct V_5 V_19 = {
. V_12 = 0 ,
} ;
return F_1 ( V_2 , V_4 , & V_19 ) ;
}
static bool
F_10 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_1 ( V_2 , V_4 , V_4 -> V_20 ) ;
}
static bool
F_11 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_20 ;
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( ! V_9 )
V_9 = F_12 ( F_3 ( V_4 ) , V_2 , F_4 ( V_4 ) ) ;
if ( V_9 ) {
bool V_10 ;
bool V_11 = true ;
V_10 = ( ! ( V_6 -> V_12 & V_13 ) &&
F_5 ( V_9 ) &&
F_13 ( & V_9 -> V_21 ) ) ;
if ( V_6 -> V_12 & V_15 )
V_11 = F_7 ( V_9 ) ;
if ( V_6 -> V_12 & V_16 && ! V_10 &&
V_11 && F_5 ( V_9 ) )
V_7 -> V_17 = V_9 -> V_18 ;
if ( V_9 != V_2 -> V_9 )
F_8 ( V_9 ) ;
if ( V_10 || ! V_11 )
V_9 = NULL ;
}
return V_9 != NULL ;
}
static int F_14 ( struct V_22 * V_22 , int V_23 )
{
switch ( V_23 ) {
case V_24 :
return F_15 ( V_22 ) ;
#if F_16 ( V_25 )
case V_26 :
return F_17 ( V_22 ) ;
#endif
}
F_18 ( 1 , L_1 , V_23 ) ;
return 0 ;
}
static int F_19 ( const struct V_27 * V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_20 ;
int V_28 ;
V_28 = F_14 ( V_4 -> V_22 , V_4 -> V_23 ) ;
if ( V_28 )
return V_28 ;
if ( V_6 -> V_12 & ~ V_29 ) {
F_20 ( L_2 , V_6 -> V_12 & ~ V_29 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_21 ( const struct V_27 * V_4 )
{
const struct V_31 * V_6 = (struct V_31 * ) V_4 -> V_20 ;
int V_28 ;
V_28 = F_14 ( V_4 -> V_22 , V_4 -> V_23 ) ;
if ( V_28 )
return V_28 ;
if ( V_6 -> V_12 & ~ V_32 ) {
F_20 ( L_2 , V_6 -> V_12 & ~ V_32 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_22 ( const struct V_27 * V_4 )
{
const struct V_33 * V_6 =
(struct V_33 * ) V_4 -> V_20 ;
int V_28 ;
V_28 = F_14 ( V_4 -> V_22 , V_4 -> V_23 ) ;
if ( V_28 )
return V_28 ;
if ( V_6 -> V_12 & ~ V_34 ) {
F_20 ( L_2 ,
V_6 -> V_12 & ~ V_34 ) ;
return - V_30 ;
}
return 0 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( V_35 , F_25 ( V_35 ) ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( V_35 , F_25 ( V_35 ) ) ;
}
