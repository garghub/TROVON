static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = F_2 ( V_2 , 0 ) ;
if ( V_4 <= 0 )
return 1 ;
V_3 = F_3 ( V_2 , V_4 , V_4 ) ;
if ( V_3 < 0 )
return 1 ;
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_5 V_6 )
{
if ( V_6 == 0 )
return - V_7 ;
return F_2 ( V_2 , V_6 - 1 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
int V_3 ;
if ( V_9 -> V_10 )
return;
V_3 = F_7 ( V_9 -> V_11 ) ;
if ( V_3 != 0 ) {
F_8 ( V_9 -> V_12 . V_13 , L_1 , V_3 ) ;
return;
}
V_9 -> V_10 = 1 ;
}
static void F_9 ( struct V_8 * V_9 )
{
int V_3 ;
if ( ! V_9 -> V_10 )
return;
V_3 = F_10 ( V_9 -> V_11 ) ;
if ( V_3 != 0 ) {
F_8 ( V_9 -> V_12 . V_13 , L_2 , V_3 ) ;
return;
}
V_9 -> V_10 = 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
enum V_5 V_16 )
{
struct V_8 * V_9 = F_12 ( V_15 ) ;
int V_4 ;
int V_3 = 0 ;
F_13 ( & V_9 -> V_17 ) ;
if ( V_16 == V_18 ) {
F_9 ( V_9 ) ;
goto V_19;
}
if ( V_9 -> V_12 . V_20 > 1 ) {
V_4 = F_5 ( V_9 -> V_11 , V_16 ) ;
F_14 ( V_9 -> V_12 . V_13 , L_3 ,
V_16 , V_4 ) ;
V_3 = F_3 ( V_9 -> V_11 , V_4 , V_4 ) ;
if ( V_3 != 0 )
F_8 ( V_9 -> V_12 . V_13 , L_4 ,
V_4 , V_3 ) ;
}
F_6 ( V_9 ) ;
V_19:
F_15 ( & V_9 -> V_17 ) ;
return V_3 ;
}
static int F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_24 =
F_17 ( & V_22 -> V_13 ) ;
struct V_8 * V_9 ;
struct V_1 * V_11 ;
int V_3 = 0 ;
if ( V_24 == NULL ) {
F_8 ( & V_22 -> V_13 , L_5 ) ;
return - V_25 ;
}
V_11 = F_18 ( & V_22 -> V_13 , L_6 ) ;
if ( F_19 ( V_11 ) ) {
F_8 ( & V_22 -> V_13 , L_7 , V_24 -> V_26 ) ;
return F_20 ( V_11 ) ;
}
V_9 = F_21 ( & V_22 -> V_13 , sizeof( * V_9 ) , V_27 ) ;
if ( V_9 == NULL )
return - V_28 ;
V_9 -> V_12 . V_20 = F_1 ( V_11 ) ;
if ( V_24 -> V_6 > V_9 -> V_12 . V_20 ) {
F_8 ( & V_22 -> V_13 , L_8 ,
V_24 -> V_6 ) ;
return - V_7 ;
}
V_9 -> V_12 . V_29 = F_11 ;
V_9 -> V_12 . V_26 = V_24 -> V_26 ;
V_9 -> V_12 . V_30 |= V_31 ;
V_9 -> V_11 = V_11 ;
if ( F_22 ( V_9 -> V_11 ) )
V_9 -> V_10 = 1 ;
F_23 ( & V_9 -> V_17 ) ;
F_24 ( V_22 , V_9 ) ;
V_3 = F_25 ( & V_22 -> V_13 , & V_9 -> V_12 ) ;
if ( V_3 < 0 )
return V_3 ;
V_9 -> V_12 . V_6 = V_24 -> V_6 ;
F_11 ( & V_9 -> V_12 , V_9 -> V_12 . V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_8 * V_9 = F_27 ( V_22 ) ;
F_28 ( & V_9 -> V_12 ) ;
F_9 ( V_9 ) ;
return 0 ;
}
