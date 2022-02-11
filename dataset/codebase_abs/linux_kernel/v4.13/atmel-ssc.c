struct V_1 * F_1 ( unsigned int V_2 )
{
int V_3 = 0 ;
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (ssc, &ssc_list, list) {
if ( V_4 -> V_6 -> V_7 . V_8 ) {
if ( F_4 ( V_4 -> V_6 -> V_7 . V_8 , L_1 )
== V_2 ) {
V_4 -> V_6 -> V_9 = V_2 ;
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
static int F_15 ( struct V_1 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_6 -> V_7 . V_8 ;
int V_24 ;
int V_9 ;
V_4 -> V_25 = false ;
if ( ! F_16 ( V_23 , L_5 ) )
return 0 ;
V_9 = F_4 ( V_23 , L_1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_24 = F_17 ( V_9 ) ;
V_4 -> V_25 = ! V_24 ;
return V_24 ;
}
static void F_18 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_25 )
return;
F_19 ( F_4 ( V_4 -> V_6 -> V_7 . V_8 , L_1 ) ) ;
}
static inline int F_15 ( struct V_1 * V_4 )
{
if ( F_16 ( V_4 -> V_6 -> V_7 . V_8 , L_5 ) )
return - V_26 ;
return 0 ;
}
static inline void F_18 ( struct V_1 * V_4 )
{
}
static int F_20 ( struct V_16 * V_6 )
{
struct V_27 * V_28 ;
struct V_1 * V_4 ;
const struct V_15 * V_29 ;
V_4 = F_21 ( & V_6 -> V_7 , sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_4 ) {
F_8 ( & V_6 -> V_7 , L_6 ) ;
return - V_31 ;
}
V_4 -> V_6 = V_6 ;
V_29 = F_12 ( V_6 ) ;
if ( ! V_29 )
return - V_10 ;
V_4 -> V_32 = (struct V_15 * ) V_29 ;
if ( V_6 -> V_7 . V_8 ) {
struct V_22 * V_23 = V_6 -> V_7 . V_8 ;
V_4 -> V_33 =
F_16 ( V_23 , L_7 ) ;
}
V_28 = F_22 ( V_6 , V_34 , 0 ) ;
V_4 -> V_28 = F_23 ( & V_6 -> V_7 , V_28 ) ;
if ( F_24 ( V_4 -> V_28 ) )
return F_25 ( V_4 -> V_28 ) ;
V_4 -> V_35 = V_28 -> V_36 ;
V_4 -> V_13 = F_26 ( & V_6 -> V_7 , L_8 ) ;
if ( F_24 ( V_4 -> V_13 ) ) {
F_8 ( & V_6 -> V_7 , L_9 ) ;
return - V_37 ;
}
F_27 ( V_4 -> V_13 ) ;
F_28 ( V_4 -> V_28 , V_38 , - 1 ) ;
F_29 ( V_4 -> V_28 , V_39 ) ;
F_30 ( V_4 -> V_13 ) ;
V_4 -> V_40 = F_31 ( V_6 , 0 ) ;
if ( ! V_4 -> V_40 ) {
F_8 ( & V_6 -> V_7 , L_10 ) ;
return - V_37 ;
}
F_2 ( & V_5 ) ;
F_32 ( & V_4 -> V_41 , & V_42 ) ;
F_5 ( & V_5 ) ;
F_33 ( V_6 , V_4 ) ;
F_34 ( & V_6 -> V_7 , L_11 ,
V_4 -> V_28 , V_4 -> V_40 ) ;
if ( F_15 ( V_4 ) )
F_35 ( & V_6 -> V_7 , L_12 ) ;
return 0 ;
}
static int F_36 ( struct V_16 * V_6 )
{
struct V_1 * V_4 = F_37 ( V_6 ) ;
F_18 ( V_4 ) ;
F_2 ( & V_5 ) ;
F_38 ( & V_4 -> V_41 ) ;
F_5 ( & V_5 ) ;
return 0 ;
}
