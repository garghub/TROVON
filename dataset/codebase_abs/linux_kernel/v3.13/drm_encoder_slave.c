int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_9 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 = 0 ;
F_2 ( L_1 , V_15 , V_8 -> type ) ;
V_11 = F_3 ( V_6 , V_8 ) ;
if ( ! V_11 ) {
V_14 = - V_16 ;
goto V_17;
}
if ( ! V_11 -> V_2 . V_18 ) {
V_14 = - V_19 ;
goto V_20;
}
V_9 = V_11 -> V_2 . V_18 -> V_21 ;
if ( ! F_4 ( V_9 ) ) {
V_14 = - V_19 ;
goto V_20;
}
V_4 -> V_22 = V_11 ;
V_13 = F_5 ( F_6 ( V_11 -> V_2 . V_18 ) ) ;
V_14 = V_13 -> V_23 ( V_11 , V_2 , V_4 ) ;
if ( V_14 )
goto V_20;
if ( V_8 -> V_24 )
V_4 -> V_25 -> V_26 ( & V_4 -> V_27 ,
V_8 -> V_24 ) ;
return 0 ;
V_20:
F_7 ( V_11 ) ;
F_8 ( V_9 ) ;
V_17:
return V_14 ;
}
void F_9 ( struct V_28 * V_28 )
{
struct V_3 * V_4 = F_10 ( V_28 ) ;
struct V_10 * V_11 = F_11 ( V_28 ) ;
struct V_9 * V_9 = V_11 -> V_2 . V_18 -> V_21 ;
F_7 ( V_11 ) ;
V_4 -> V_22 = NULL ;
F_8 ( V_9 ) ;
}
static inline struct V_29 *
F_12 ( struct V_28 * V_30 )
{
return F_10 ( V_30 ) -> V_25 ;
}
void F_13 ( struct V_28 * V_4 , int V_31 )
{
F_12 ( V_4 ) -> F_14 ( V_4 , V_31 ) ;
}
bool F_15 ( struct V_28 * V_4 ,
const struct V_32 * V_31 ,
struct V_32 * V_33 )
{
return F_12 ( V_4 ) -> F_16 ( V_4 , V_31 , V_33 ) ;
}
void F_17 ( struct V_28 * V_4 )
{
F_13 ( V_4 , V_34 ) ;
}
void F_18 ( struct V_28 * V_4 )
{
F_13 ( V_4 , V_35 ) ;
}
void F_19 ( struct V_28 * V_4 ,
struct V_32 * V_31 ,
struct V_32 * V_33 )
{
F_12 ( V_4 ) -> F_20 ( V_4 , V_31 , V_33 ) ;
}
enum V_36 F_21 ( struct V_28 * V_4 ,
struct V_37 * V_38 )
{
return F_12 ( V_4 ) -> F_22 ( V_4 , V_38 ) ;
}
void F_23 ( struct V_28 * V_4 )
{
F_12 ( V_4 ) -> F_24 ( V_4 ) ;
}
void F_25 ( struct V_28 * V_4 )
{
F_12 ( V_4 ) -> F_26 ( V_4 ) ;
}
