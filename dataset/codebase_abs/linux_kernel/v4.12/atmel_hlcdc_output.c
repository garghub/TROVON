static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_6 =
F_3 ( V_5 ) ;
if ( V_6 -> V_7 ) {
F_5 ( V_6 -> V_7 ) ;
F_6 ( V_6 -> V_7 ) ;
}
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_1 * V_6 =
F_3 ( V_5 ) ;
if ( V_6 -> V_7 ) {
F_8 ( V_6 -> V_7 ) ;
F_9 ( V_6 -> V_7 ) ;
}
}
static void F_10 ( struct V_4 * V_5 )
{
F_11 ( V_5 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
if ( V_6 -> V_7 )
return V_6 -> V_7 -> V_8 -> V_9 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
return F_14 ( V_6 -> V_12 , V_11 ) ;
}
static enum V_13
F_15 ( struct V_2 * V_3 , bool V_14 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
if ( V_6 -> V_7 )
return V_15 ;
return V_16 ;
}
static void
F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
if ( V_6 -> V_7 )
F_17 ( V_6 -> V_7 ) ;
F_18 ( V_3 ) ;
}
static int F_19 ( struct V_17 * V_18 , int V_19 )
{
struct V_20 * V_12 = V_18 -> V_21 ;
struct V_1 * V_22 ;
struct V_23 * V_7 ;
struct V_24 * V_25 ;
int V_26 ;
V_26 = F_20 ( V_18 -> V_18 -> V_27 , 0 , V_19 ,
& V_7 , & V_25 ) ;
if ( V_26 )
return V_26 ;
V_22 = F_21 ( V_18 -> V_18 , sizeof( * V_22 ) , V_28 ) ;
if ( ! V_22 )
return - V_29 ;
V_22 -> V_12 = V_12 ;
F_22 ( & V_22 -> V_5 ,
& V_30 ) ;
V_26 = F_23 ( V_18 , & V_22 -> V_5 ,
& V_31 ,
V_32 , NULL ) ;
if ( V_26 )
return V_26 ;
V_22 -> V_5 . V_33 = 0x1 ;
if ( V_7 ) {
V_22 -> V_3 . V_34 = V_35 ;
V_22 -> V_3 . V_36 = V_37 ;
F_24 ( & V_22 -> V_3 ,
& V_38 ) ;
V_26 = F_25 ( V_18 , & V_22 -> V_3 ,
& V_39 ,
V_40 ) ;
if ( V_26 )
goto V_41;
F_26 ( & V_22 -> V_3 ,
& V_22 -> V_5 ) ;
V_26 = F_27 ( V_7 , & V_22 -> V_3 ) ;
if ( V_26 ) {
F_18 ( & V_22 -> V_3 ) ;
goto V_41;
}
V_22 -> V_7 = V_7 ;
return 0 ;
}
if ( V_25 ) {
V_26 = F_28 ( & V_22 -> V_5 , V_25 , NULL ) ;
if ( ! V_26 )
return 0 ;
}
V_41:
F_11 ( & V_22 -> V_5 ) ;
return V_26 ;
}
int F_29 ( struct V_17 * V_18 )
{
int V_19 , V_26 = 0 ;
for ( V_19 = 0 ; ! V_26 ; V_19 ++ )
V_26 = F_19 ( V_18 , V_19 ) ;
if ( V_26 == - V_42 && V_19 )
return 0 ;
return V_26 ;
}
