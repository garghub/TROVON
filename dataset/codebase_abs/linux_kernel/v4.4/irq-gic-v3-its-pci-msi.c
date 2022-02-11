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
if ( V_4 != V_10 -> V_4 )
V_10 -> V_11 += F_7 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , struct V_14 * V_15 ,
int V_16 , T_2 * V_17 )
{
struct V_3 * V_4 ;
struct V_9 V_10 ;
struct V_18 * V_19 ;
if ( ! F_13 ( V_15 ) )
return - V_20 ;
V_19 = F_14 ( V_13 -> V_21 ) ;
V_4 = F_15 ( V_15 ) ;
V_10 . V_4 = V_4 ;
V_10 . V_11 = V_16 ;
F_16 ( V_4 , F_11 , & V_10 ) ;
V_17 -> V_22 [ 0 ] . V_23 = F_17 ( V_13 , V_4 ) ;
return V_19 -> V_24 -> V_25 ( V_13 -> V_21 ,
V_15 , V_10 . V_11 , V_17 ) ;
}
static int T_3 F_18 ( void )
{
struct V_26 * V_27 ;
struct V_12 * V_21 ;
for ( V_27 = F_19 ( NULL , V_28 ) ; V_27 ;
V_27 = F_19 ( V_27 , V_28 ) ) {
if ( ! F_20 ( V_27 , L_1 ) )
continue;
V_21 = F_21 ( V_27 , V_29 ) ;
if ( ! V_21 || ! F_14 ( V_21 ) ) {
F_22 ( L_2 ,
V_27 -> V_30 ) ;
continue;
}
if ( ! F_23 ( F_24 ( V_27 ) ,
& V_31 ,
V_21 ) ) {
F_22 ( L_3 ,
V_27 -> V_30 ) ;
continue;
}
F_25 ( L_4 , V_27 -> V_30 ) ;
}
return 0 ;
}
