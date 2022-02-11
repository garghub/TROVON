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
if ( F_6 ( V_2 -> V_11 ) )
F_7 ( & V_4 -> V_8 . V_12 ,
F_8 ( V_13 + V_14 ) ) ;
else {
F_1 ( V_2 ) ;
F_9 ( V_2 , V_15 , 0 ) ;
if ( V_16 ) {
F_10 ( & V_17 ) ;
F_11 ( & V_4 -> V_8 . V_18 , & V_19 ) ;
F_12 ( & V_17 ) ;
F_13 ( V_20 , & V_21 ) ;
}
}
} else
F_7 ( & V_4 -> V_8 . V_12 ,
F_8 ( V_13 + V_14 ) ) ;
}
static void F_14 ( struct V_22 * V_23 )
{
struct V_3 * V_4 , * V_24 ;
struct V_1 * V_2 ;
F_15 ( V_25 ) ;
int V_26 ;
F_16 ( & V_17 ) ;
F_17 ( & V_19 , & V_25 ) ;
F_18 ( & V_17 ) ;
F_19 (priv, tmppriv, &tlist, catas_err.list) {
struct V_27 * V_11 = V_4 -> V_2 . V_11 ;
if ( F_6 ( V_11 ) )
continue;
V_26 = F_20 ( V_4 -> V_2 . V_11 ) ;
if ( V_26 )
F_21 ( L_3 ,
F_22 ( V_11 ) , V_26 ) ;
else {
V_2 = F_23 ( V_11 ) ;
F_24 ( V_2 , L_4 ) ;
}
}
}
void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_28 ;
if ( F_26 ( V_2 ) )
V_16 = 0 ;
F_27 ( & V_4 -> V_8 . V_18 ) ;
F_28 ( & V_4 -> V_8 . V_12 ) ;
V_4 -> V_8 . V_9 = NULL ;
V_28 = F_29 ( V_2 -> V_11 , V_4 -> V_6 . V_29 ) +
V_4 -> V_6 . V_30 ;
V_4 -> V_8 . V_9 = F_30 ( V_28 , V_4 -> V_6 . V_7 * 4 ) ;
if ( ! V_4 -> V_8 . V_9 ) {
F_31 ( V_2 , L_5 ,
( unsigned long long ) V_28 ) ;
return;
}
V_4 -> V_8 . V_12 . V_31 = ( unsigned long ) V_2 ;
V_4 -> V_8 . V_12 . V_32 = F_5 ;
V_4 -> V_8 . V_12 . V_33 =
F_8 ( V_13 + V_14 ) ;
F_32 ( & V_4 -> V_8 . V_12 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
F_34 ( & V_4 -> V_8 . V_12 ) ;
if ( V_4 -> V_8 . V_9 )
F_35 ( V_4 -> V_8 . V_9 ) ;
F_16 ( & V_17 ) ;
F_36 ( & V_4 -> V_8 . V_18 ) ;
F_18 ( & V_17 ) ;
}
void T_2 F_37 ( void )
{
F_38 ( & V_21 , F_14 ) ;
}
