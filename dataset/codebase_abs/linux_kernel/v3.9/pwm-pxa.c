static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long long V_9 ;
unsigned long V_10 , V_11 , V_12 , V_13 ;
unsigned long V_14 ;
int V_15 ;
V_14 = V_5 -> V_16 ? 0x10 : 0 ;
V_9 = F_4 ( V_8 -> V_17 ) ;
V_9 = V_9 * V_7 ;
F_5 ( V_9 , 1000000000 ) ;
V_10 = V_9 ;
if ( V_10 < 1 )
V_10 = 1 ;
V_11 = ( V_10 - 1 ) / 1024 ;
V_12 = V_10 / ( V_11 + 1 ) - 1 ;
if ( V_11 > 63 )
return - V_18 ;
if ( V_6 == V_7 )
V_13 = V_19 ;
else
V_13 = ( V_12 + 1 ) * V_6 / V_7 ;
V_15 = F_6 ( V_8 -> V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
F_7 ( V_11 , V_8 -> V_20 + V_14 + V_21 ) ;
F_7 ( V_13 , V_8 -> V_20 + V_14 + V_22 ) ;
F_7 ( V_12 , V_8 -> V_20 + V_14 + V_23 ) ;
F_8 ( V_8 -> V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_15 = 0 ;
if ( ! V_8 -> V_24 ) {
V_15 = F_6 ( V_8 -> V_17 ) ;
if ( ! V_15 )
V_8 -> V_24 ++ ;
}
return V_15 ;
}
static void F_10 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_8 -> V_24 ) {
F_8 ( V_8 -> V_17 ) ;
V_8 -> V_24 -- ;
}
}
static int F_11 ( struct V_25 * V_26 )
{
const struct V_27 * V_28 = F_12 ( V_26 ) ;
struct V_1 * V_5 ;
struct V_29 * V_30 ;
int V_31 = 0 ;
V_5 = F_13 ( & V_26 -> V_32 , sizeof( * V_5 ) , V_33 ) ;
if ( V_5 == NULL ) {
F_14 ( & V_26 -> V_32 , L_1 ) ;
return - V_34 ;
}
V_5 -> V_17 = F_15 ( & V_26 -> V_32 , NULL ) ;
if ( F_16 ( V_5 -> V_17 ) )
return F_17 ( V_5 -> V_17 ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_3 . V_32 = & V_26 -> V_32 ;
V_5 -> V_3 . V_35 = & V_36 ;
V_5 -> V_3 . V_37 = - 1 ;
V_5 -> V_3 . V_38 = ( V_28 -> V_39 & V_40 ) ? 2 : 1 ;
V_30 = F_18 ( V_26 , V_41 , 0 ) ;
if ( V_30 == NULL ) {
F_14 ( & V_26 -> V_32 , L_2 ) ;
return - V_42 ;
}
V_5 -> V_20 = F_19 ( & V_26 -> V_32 , V_30 ) ;
if ( F_16 ( V_5 -> V_20 ) )
return F_17 ( V_5 -> V_20 ) ;
V_31 = F_20 ( & V_5 -> V_3 ) ;
if ( V_31 < 0 ) {
F_14 ( & V_26 -> V_32 , L_3 , V_31 ) ;
return V_31 ;
}
F_21 ( V_26 , V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_25 * V_26 )
{
struct V_1 * V_3 ;
V_3 = F_23 ( V_26 ) ;
if ( V_3 == NULL )
return - V_42 ;
return F_24 ( & V_3 -> V_3 ) ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_43 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_43 ) ;
}
