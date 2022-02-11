static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_10 -> V_11 ;
F_2 ( V_2 , L_1 , F_3 ( & V_8 -> V_12 ) ) ;
F_2 ( V_2 , L_1 , F_3 ( & V_8 -> V_13 ) ) ;
F_2 ( V_2 , L_1 , F_3 ( & V_8 -> V_14 ) ) ;
F_2 ( V_2 , L_1 , F_3 ( & V_8 -> V_15 ) ) ;
F_2 ( V_2 , L_1 , V_8 -> V_16 ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_10 -> V_11 ;
struct V_17 * V_18 ;
F_5 (bo, &qdev->gem.objects, list) {
F_2 ( V_2 , L_2 ,
( unsigned long ) V_18 -> V_19 . V_20 , V_18 -> V_21 ,
V_18 -> V_22 . V_23 , V_18 -> V_24 . V_25 ) ;
}
return 0 ;
}
int
F_6 ( struct V_26 * V_9 )
{
#if F_7 ( V_27 )
F_8 ( V_28 , V_29 ,
V_9 -> V_30 , V_9 ) ;
#endif
return 0 ;
}
void
F_9 ( struct V_26 * V_9 )
{
#if F_7 ( V_27 )
F_10 ( V_28 , V_29 ,
V_9 ) ;
#endif
}
int F_11 ( struct V_7 * V_8 ,
struct V_31 * V_32 ,
unsigned V_33 )
{
unsigned V_34 ;
for ( V_34 = 0 ; V_34 < V_8 -> V_35 ; V_34 ++ ) {
if ( V_8 -> V_36 [ V_34 ] . V_32 == V_32 ) {
return 0 ;
}
}
V_34 = V_8 -> V_35 + 1 ;
if ( V_34 > V_37 ) {
F_12 ( L_3 ) ;
F_12 ( L_4 ) ;
return - V_38 ;
}
V_8 -> V_36 [ V_8 -> V_35 ] . V_32 = V_32 ;
V_8 -> V_36 [ V_8 -> V_35 ] . V_39 = V_33 ;
V_8 -> V_35 = V_34 ;
#if F_7 ( V_27 )
F_8 ( V_32 , V_33 ,
V_8 -> V_40 -> V_41 -> V_30 ,
V_8 -> V_40 -> V_41 ) ;
F_8 ( V_32 , V_33 ,
V_8 -> V_40 -> V_42 -> V_30 ,
V_8 -> V_40 -> V_42 ) ;
#endif
return 0 ;
}
void F_13 ( struct V_7 * V_8 )
{
#if F_7 ( V_27 )
unsigned V_34 ;
for ( V_34 = 0 ; V_34 < V_8 -> V_35 ; V_34 ++ ) {
F_10 ( V_8 -> V_36 [ V_34 ] . V_32 ,
V_8 -> V_36 [ V_34 ] . V_39 ,
V_8 -> V_40 -> V_41 ) ;
F_10 ( V_8 -> V_36 [ V_34 ] . V_32 ,
V_8 -> V_36 [ V_34 ] . V_39 ,
V_8 -> V_40 -> V_42 ) ;
}
#endif
}
