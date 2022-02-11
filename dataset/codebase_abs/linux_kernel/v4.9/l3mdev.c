int F_1 ( const struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_2 ( V_2 ) ) {
V_3 = V_2 -> V_3 ;
} else if ( F_3 ( V_2 ) ) {
struct V_1 * V_4 ;
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
V_4 = F_4 ( V_5 ) ;
if ( V_4 )
V_3 = V_4 -> V_3 ;
}
return V_3 ;
}
T_1 F_5 ( const struct V_1 * V_2 )
{
T_1 V_6 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_7 -> V_8 )
V_6 = V_2 -> V_7 -> V_8 ( V_2 ) ;
} else if ( F_3 ( V_2 ) ) {
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
const struct V_1 * V_4 ;
V_4 = F_4 ( V_5 ) ;
if ( V_4 &&
V_4 -> V_7 -> V_8 )
V_6 = V_4 -> V_7 -> V_8 ( V_4 ) ;
}
return V_6 ;
}
T_1 F_6 ( struct V_9 * V_9 , int V_3 )
{
struct V_1 * V_2 ;
T_1 V_6 = 0 ;
if ( ! V_3 )
return 0 ;
F_7 () ;
V_2 = F_8 ( V_9 , V_3 ) ;
if ( V_2 )
V_6 = F_5 ( V_2 ) ;
F_9 () ;
return V_6 ;
}
struct V_10 * F_10 ( struct V_9 * V_9 ,
struct V_11 * V_12 )
{
struct V_10 * V_13 = NULL ;
struct V_1 * V_2 ;
if ( V_12 -> V_14 ) {
F_7 () ;
V_2 = F_8 ( V_9 , V_12 -> V_14 ) ;
if ( V_2 && F_3 ( V_2 ) )
V_2 = F_4 ( V_2 ) ;
if ( V_2 && F_2 ( V_2 ) &&
V_2 -> V_7 -> F_10 )
V_13 = V_2 -> V_7 -> F_10 ( V_2 , V_12 ) ;
F_9 () ;
}
return V_13 ;
}
int F_11 ( struct V_9 * V_9 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 ;
int V_19 = 0 ;
F_7 () ;
V_2 = F_8 ( V_9 , V_16 -> V_20 ) ;
if ( V_2 && F_2 ( V_2 ) &&
V_2 -> V_7 -> V_8 ) {
V_18 -> V_21 = V_2 -> V_7 -> V_8 ( V_2 ) ;
V_19 = 1 ;
goto V_22;
}
V_2 = F_8 ( V_9 , V_16 -> V_23 ) ;
if ( V_2 && F_2 ( V_2 ) &&
V_2 -> V_7 -> V_8 ) {
V_18 -> V_21 = V_2 -> V_7 -> V_8 ( V_2 ) ;
V_19 = 1 ;
goto V_22;
}
V_22:
F_9 () ;
return V_19 ;
}
void F_12 ( struct V_9 * V_9 , struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_3 ;
F_7 () ;
if ( V_16 -> V_20 ) {
V_2 = F_8 ( V_9 , V_16 -> V_20 ) ;
if ( V_2 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
V_16 -> V_20 = V_3 ;
V_16 -> V_24 |= V_25 ;
goto V_22;
}
}
}
if ( V_16 -> V_23 ) {
V_2 = F_8 ( V_9 , V_16 -> V_23 ) ;
if ( V_2 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
V_16 -> V_23 = V_3 ;
V_16 -> V_24 |= V_25 ;
}
}
}
V_22:
F_9 () ;
}
