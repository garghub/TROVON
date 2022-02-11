struct V_1 * F_1 ( unsigned int V_2 )
{
int V_3 = 0 ;
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (ssc, &ssc_list, list) {
if ( V_4 -> V_6 -> V_7 . V_8 ) {
if ( F_4 ( V_4 -> V_6 -> V_7 . V_8 , L_1 )
== V_2 ) {
V_3 = 1 ;
break;
}
} else if ( V_4 -> V_6 -> V_9 == V_2 ) {
V_3 = 1 ;
break;
}
}
if ( ! V_3 ) {
F_5 ( & V_5 ) ;
F_6 ( L_2 , V_2 ) ;
return F_7 ( - V_10 ) ;
}
if ( V_4 -> V_11 ) {
F_5 ( & V_5 ) ;
F_8 ( & V_4 -> V_6 -> V_7 , L_3 ) ;
return F_7 ( - V_12 ) ;
}
V_4 -> V_11 ++ ;
F_5 ( & V_5 ) ;
F_9 ( V_4 -> V_13 ) ;
return V_4 ;
}
void F_10 ( struct V_1 * V_4 )
{
bool V_14 = true ;
F_2 ( & V_5 ) ;
if ( V_4 -> V_11 )
V_4 -> V_11 -- ;
else {
V_14 = false ;
F_8 ( & V_4 -> V_6 -> V_7 , L_4 ) ;
}
F_5 ( & V_5 ) ;
if ( V_14 )
F_11 ( V_4 -> V_13 ) ;
}
static inline const struct V_15 * T_1
F_12 ( struct V_16 * V_6 )
{
if ( V_6 -> V_7 . V_8 ) {
const struct V_17 * V_18 ;
V_18 = F_13 ( V_19 , V_6 -> V_7 . V_8 ) ;
if ( V_18 == NULL )
return NULL ;
return V_18 -> V_20 ;
}
return (struct V_15 * )
F_14 ( V_6 ) -> V_21 ;
}
static int F_15 ( struct V_16 * V_6 )
{
struct V_22 * V_23 ;
struct V_1 * V_4 ;
const struct V_15 * V_24 ;
V_4 = F_16 ( & V_6 -> V_7 , sizeof( struct V_1 ) , V_25 ) ;
if ( ! V_4 ) {
F_8 ( & V_6 -> V_7 , L_5 ) ;
return - V_26 ;
}
V_4 -> V_6 = V_6 ;
V_24 = F_12 ( V_6 ) ;
if ( ! V_24 )
return - V_10 ;
V_4 -> V_27 = (struct V_15 * ) V_24 ;
if ( V_6 -> V_7 . V_8 ) {
struct V_28 * V_29 = V_6 -> V_7 . V_8 ;
V_4 -> V_30 =
F_17 ( V_29 , L_6 ) ;
}
V_23 = F_18 ( V_6 , V_31 , 0 ) ;
V_4 -> V_23 = F_19 ( & V_6 -> V_7 , V_23 ) ;
if ( F_20 ( V_4 -> V_23 ) )
return F_21 ( V_4 -> V_23 ) ;
V_4 -> V_32 = V_23 -> V_33 ;
V_4 -> V_13 = F_22 ( & V_6 -> V_7 , L_7 ) ;
if ( F_20 ( V_4 -> V_13 ) ) {
F_8 ( & V_6 -> V_7 , L_8 ) ;
return - V_34 ;
}
F_9 ( V_4 -> V_13 ) ;
F_23 ( V_4 -> V_23 , V_35 , - 1 ) ;
F_24 ( V_4 -> V_23 , V_36 ) ;
F_11 ( V_4 -> V_13 ) ;
V_4 -> V_37 = F_25 ( V_6 , 0 ) ;
if ( ! V_4 -> V_37 ) {
F_8 ( & V_6 -> V_7 , L_9 ) ;
return - V_34 ;
}
F_2 ( & V_5 ) ;
F_26 ( & V_4 -> V_38 , & V_39 ) ;
F_5 ( & V_5 ) ;
F_27 ( V_6 , V_4 ) ;
F_28 ( & V_6 -> V_7 , L_10 ,
V_4 -> V_23 , V_4 -> V_37 ) ;
return 0 ;
}
static int F_29 ( struct V_16 * V_6 )
{
struct V_1 * V_4 = F_30 ( V_6 ) ;
F_2 ( & V_5 ) ;
F_31 ( & V_4 -> V_38 ) ;
F_5 ( & V_5 ) ;
return 0 ;
}
