static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
int V_5 ;
F_2 ( V_2 , L_1 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 . V_7 ; ++ V_5 )
F_2 ( V_2 , L_2 ,
V_5 , F_3 ( F_4 ( V_4 -> V_8 . V_9 + V_5 ) ) ) ;
}
static void F_5 ( unsigned long V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( F_4 ( V_4 -> V_8 . V_9 ) ) {
F_1 ( V_2 ) ;
F_6 ( V_2 , V_11 , 0 ) ;
if ( V_12 ) {
F_7 ( & V_13 ) ;
F_8 ( & V_4 -> V_8 . V_14 , & V_15 ) ;
F_9 ( & V_13 ) ;
F_10 ( V_16 , & V_17 ) ;
}
} else
F_11 ( & V_4 -> V_8 . V_18 ,
F_12 ( V_19 + V_20 ) ) ;
}
static void F_13 ( struct V_21 * V_22 )
{
struct V_3 * V_4 , * V_23 ;
struct V_1 * V_2 ;
F_14 ( V_24 ) ;
int V_25 ;
F_15 ( & V_13 ) ;
F_16 ( & V_15 , & V_24 ) ;
F_17 ( & V_13 ) ;
F_18 (priv, tmppriv, &tlist, catas_err.list) {
struct V_26 * V_27 = V_4 -> V_2 . V_27 ;
V_25 = F_19 ( V_4 -> V_2 . V_27 ) ;
if ( V_25 )
F_20 ( L_3 ,
F_21 ( V_27 ) , V_25 ) ;
else {
V_2 = F_22 ( V_27 ) ;
F_23 ( V_2 , L_4 ) ;
}
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_28 ;
if ( F_25 ( V_2 ) )
V_12 = 0 ;
F_26 ( & V_4 -> V_8 . V_14 ) ;
F_27 ( & V_4 -> V_8 . V_18 ) ;
V_4 -> V_8 . V_9 = NULL ;
V_28 = F_28 ( V_2 -> V_27 , V_4 -> V_6 . V_29 ) +
V_4 -> V_6 . V_30 ;
V_4 -> V_8 . V_9 = F_29 ( V_28 , V_4 -> V_6 . V_7 * 4 ) ;
if ( ! V_4 -> V_8 . V_9 ) {
F_30 ( V_2 , L_5 ,
( unsigned long long ) V_28 ) ;
return;
}
V_4 -> V_8 . V_18 . V_31 = ( unsigned long ) V_2 ;
V_4 -> V_8 . V_18 . V_32 = F_5 ;
V_4 -> V_8 . V_18 . V_33 =
F_12 ( V_19 + V_20 ) ;
F_31 ( & V_4 -> V_8 . V_18 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
F_33 ( & V_4 -> V_8 . V_18 ) ;
if ( V_4 -> V_8 . V_9 )
F_34 ( V_4 -> V_8 . V_9 ) ;
F_15 ( & V_13 ) ;
F_35 ( & V_4 -> V_8 . V_14 ) ;
F_17 ( & V_13 ) ;
}
void T_2 F_36 ( void )
{
F_37 ( & V_17 , F_13 ) ;
}
