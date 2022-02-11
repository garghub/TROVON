static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
struct V_2 *
F_2 ( struct V_5 * V_6 , unsigned int V_7 ,
enum V_8 type )
{
struct V_1 * V_9 ;
struct V_2 * V_3 ;
V_7 += V_10 ;
V_3 = F_3 ( V_6 , V_7 , V_11 ) ;
if ( ! V_3 )
return NULL ;
V_9 = F_1 ( V_3 ) ;
V_9 -> V_12 = 0 ;
V_9 -> V_13 = V_14 ;
V_9 -> type = type ;
F_4 ( V_3 , V_7 ) ;
return V_3 ;
}
int F_5 ( struct V_15 * V_16 , bool V_17 )
{
struct F_5 * V_18 ;
struct V_2 * V_3 ;
V_3 = F_2 ( V_16 -> V_6 , sizeof( * V_18 ) ,
V_19 ) ;
if ( ! V_3 )
return - V_20 ;
V_18 = F_6 ( V_3 ) ;
V_18 -> V_21 = F_7 ( V_16 -> V_22 -> V_23 . V_24 . V_25 ) ;
V_18 -> V_26 = 0 ;
V_18 -> V_27 = V_17 ;
V_18 -> V_28 = F_8 ( V_16 -> V_29 -> V_28 ) ;
F_9 ( V_16 -> V_6 -> V_30 , V_3 ) ;
return 0 ;
}
static void
F_10 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct F_5 * V_18 ;
struct V_31 * V_29 ;
bool V_32 ;
V_18 = F_6 ( V_3 ) ;
V_32 = V_18 -> V_27 & V_33 ;
F_11 () ;
V_29 = F_12 ( V_6 , F_13 ( V_18 -> V_21 ) ) ;
if ( ! V_29 ) {
F_14 ( V_6 , L_1 ,
F_13 ( V_18 -> V_21 ) ) ;
F_15 () ;
return;
}
if ( V_32 )
F_16 ( V_29 ) ;
else
F_17 ( V_29 ) ;
F_15 () ;
}
void F_18 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_34 ;
enum V_8 type ;
V_34 = F_1 ( V_3 ) ;
if ( F_19 ( V_34 -> V_13 != V_14 ) ) {
F_14 ( V_6 , L_2 ,
V_34 -> V_13 ) ;
goto V_35;
}
type = V_34 -> type ;
switch ( type ) {
case V_19 :
F_10 ( V_6 , V_3 ) ;
break;
case V_36 :
F_20 ( V_6 , V_3 ) ;
break;
default:
F_14 ( V_6 , L_3 ,
type ) ;
}
V_35:
F_21 ( V_3 ) ;
}
