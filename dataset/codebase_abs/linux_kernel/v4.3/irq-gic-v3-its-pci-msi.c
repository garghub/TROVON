static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_5 , V_6 ;
V_5 = F_8 ( F_9 ( V_4 ) , 0 ) ;
V_6 = F_8 ( F_10 ( V_4 ) , 0 ) ;
return F_8 ( V_5 , V_6 ) ;
}
static int F_11 ( struct V_3 * V_4 , T_1 V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
V_10 -> V_11 = V_7 ;
if ( V_4 != V_10 -> V_4 )
V_10 -> V_12 += F_7 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , struct V_15 * V_16 ,
int V_17 , T_2 * V_18 )
{
struct V_3 * V_4 ;
struct V_9 V_10 ;
struct V_19 * V_20 ;
if ( ! F_13 ( V_16 ) )
return - V_21 ;
V_20 = F_14 ( V_14 -> V_22 ) ;
V_4 = F_15 ( V_16 ) ;
V_10 . V_4 = V_4 ;
V_10 . V_12 = V_17 ;
F_16 ( V_4 , F_11 , & V_10 ) ;
V_18 -> V_23 [ 0 ] . V_24 = V_10 . V_11 ;
return V_20 -> V_25 -> V_26 ( V_14 -> V_22 ,
V_16 , V_10 . V_12 , V_18 ) ;
}
static int T_3 F_17 ( void )
{
struct V_27 * V_28 ;
struct V_13 * V_22 ;
for ( V_28 = F_18 ( NULL , V_29 ) ; V_28 ;
V_28 = F_18 ( V_28 , V_29 ) ) {
if ( ! F_19 ( V_28 , L_1 ) )
continue;
V_22 = F_20 ( V_28 , V_30 ) ;
if ( ! V_22 || ! F_14 ( V_22 ) ) {
F_21 ( L_2 ,
V_28 -> V_31 ) ;
continue;
}
if ( ! F_22 ( V_28 , & V_32 ,
V_22 ) ) {
F_21 ( L_3 ,
V_28 -> V_31 ) ;
continue;
}
F_23 ( L_4 , V_28 -> V_31 ) ;
}
return 0 ;
}
