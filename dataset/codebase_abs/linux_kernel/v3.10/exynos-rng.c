static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_2 )
{
struct V_1 * V_1 = F_6 ( V_2 ,
struct V_1 , V_2 ) ;
int V_7 ;
int V_8 = 0 ;
F_7 ( V_1 -> V_9 ) ;
for ( V_7 = 0 ; V_7 < 5 ; V_7 ++ )
F_3 ( V_1 , V_10 ,
V_11 + 4 * V_7 ) ;
if ( ! ( F_1 ( V_1 , V_12 )
& V_13 ) )
V_8 = - V_14 ;
F_8 ( V_1 -> V_9 ) ;
return V_8 ;
}
static int F_9 ( struct V_6 * V_2 , void * V_15 ,
T_2 V_16 , bool V_17 )
{
struct V_1 * V_1 = F_6 ( V_2 ,
struct V_1 , V_2 ) ;
T_1 * V_18 = V_15 ;
F_7 ( V_1 -> V_9 ) ;
F_3 ( V_1 , V_19 , 0 ) ;
while ( ! ( F_1 ( V_1 ,
V_12 ) & V_20 ) )
F_10 () ;
F_3 ( V_1 , V_20 , V_12 ) ;
* V_18 = F_1 ( V_1 , V_21 ) ;
F_11 ( V_1 -> V_9 ) ;
F_12 ( V_1 -> V_9 ) ;
return 4 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_1 ;
struct V_24 * V_25 ;
V_1 = F_14 ( & V_23 -> V_9 , sizeof( struct V_1 ) ,
V_26 ) ;
if ( ! V_1 )
return - V_27 ;
V_1 -> V_9 = & V_23 -> V_9 ;
V_1 -> V_2 . V_28 = L_1 ;
V_1 -> V_2 . V_29 = F_5 ;
V_1 -> V_2 . V_30 = F_9 ;
V_1 -> V_31 = F_15 ( & V_23 -> V_9 , L_2 ) ;
if ( F_16 ( V_1 -> V_31 ) ) {
F_17 ( & V_23 -> V_9 , L_3 ) ;
return - V_32 ;
}
V_25 = F_18 ( V_23 , V_33 , 0 ) ;
V_1 -> V_4 = F_19 ( & V_23 -> V_9 , V_25 ) ;
if ( F_16 ( V_1 -> V_4 ) )
return F_20 ( V_1 -> V_4 ) ;
F_21 ( V_23 , V_1 ) ;
F_22 ( & V_23 -> V_9 , V_34 ) ;
F_23 ( & V_23 -> V_9 ) ;
F_24 ( & V_23 -> V_9 ) ;
return F_25 ( & V_1 -> V_2 ) ;
}
static int F_26 ( struct V_22 * V_23 )
{
struct V_1 * V_1 = F_27 ( V_23 ) ;
F_28 ( & V_1 -> V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_9 )
{
struct V_22 * V_23 = F_30 ( V_9 ) ;
struct V_1 * V_1 = F_27 ( V_23 ) ;
F_31 ( V_1 -> V_31 ) ;
return 0 ;
}
static int F_32 ( struct V_35 * V_9 )
{
struct V_22 * V_23 = F_30 ( V_9 ) ;
struct V_1 * V_1 = F_27 ( V_23 ) ;
return F_33 ( V_1 -> V_31 ) ;
}
