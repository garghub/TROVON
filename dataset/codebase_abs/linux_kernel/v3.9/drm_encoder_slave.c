int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
char V_9 [ sizeof( V_10 )
+ V_11 ] ;
struct V_12 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
snprintf ( V_9 , sizeof( V_9 ) ,
L_1 , V_10 , V_8 -> type ) ;
F_2 ( V_9 ) ;
V_14 = F_3 ( V_6 , V_8 ) ;
if ( ! V_14 ) {
V_17 = - V_18 ;
goto V_19;
}
if ( ! V_14 -> V_20 ) {
V_17 = - V_21 ;
goto V_22;
}
V_12 = V_14 -> V_20 -> V_20 . V_23 ;
if ( ! F_4 ( V_12 ) ) {
V_17 = - V_21 ;
goto V_22;
}
V_4 -> V_24 = V_14 ;
V_16 = F_5 ( V_14 -> V_20 ) ;
V_17 = V_16 -> V_25 ( V_14 , V_2 , V_4 ) ;
if ( V_17 )
goto V_22;
if ( V_8 -> V_26 )
V_4 -> V_27 -> V_28 ( & V_4 -> V_29 ,
V_8 -> V_26 ) ;
return 0 ;
V_22:
F_6 ( V_14 ) ;
F_7 ( V_12 ) ;
V_19:
return V_17 ;
}
void F_8 ( struct V_30 * V_30 )
{
struct V_3 * V_4 = F_9 ( V_30 ) ;
struct V_13 * V_14 = F_10 ( V_30 ) ;
struct V_12 * V_12 = V_14 -> V_20 -> V_20 . V_23 ;
F_6 ( V_14 ) ;
V_4 -> V_24 = NULL ;
F_7 ( V_12 ) ;
}
static inline struct V_31 *
F_11 ( struct V_30 * V_32 )
{
return F_9 ( V_32 ) -> V_27 ;
}
void F_12 ( struct V_30 * V_4 , int V_33 )
{
F_11 ( V_4 ) -> F_13 ( V_4 , V_33 ) ;
}
bool F_14 ( struct V_30 * V_4 ,
const struct V_34 * V_33 ,
struct V_34 * V_35 )
{
return F_11 ( V_4 ) -> F_15 ( V_4 , V_33 , V_35 ) ;
}
void F_16 ( struct V_30 * V_4 )
{
F_12 ( V_4 , V_36 ) ;
}
void F_17 ( struct V_30 * V_4 )
{
F_12 ( V_4 , V_37 ) ;
}
void F_18 ( struct V_30 * V_4 ,
struct V_34 * V_33 ,
struct V_34 * V_35 )
{
F_11 ( V_4 ) -> F_19 ( V_4 , V_33 , V_35 ) ;
}
enum V_38 F_20 ( struct V_30 * V_4 ,
struct V_39 * V_40 )
{
return F_11 ( V_4 ) -> F_21 ( V_4 , V_40 ) ;
}
void F_22 ( struct V_30 * V_4 )
{
F_11 ( V_4 ) -> F_23 ( V_4 ) ;
}
void F_24 ( struct V_30 * V_4 )
{
F_11 ( V_4 ) -> F_25 ( V_4 ) ;
}
