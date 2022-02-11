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
struct V_19 * V_20 ;
int V_21 ;
F_6 () ;
V_20 = F_7 ( V_18 -> V_22 . V_23 -> V_24 ) ;
V_21 = V_20 ? V_20 -> V_25 : 0 ;
F_8 () ;
F_2 ( V_2 , L_2 ,
( unsigned long ) V_18 -> V_26 . V_27 ,
V_18 -> V_28 , V_21 ) ;
}
return 0 ;
}
int
F_9 ( struct V_29 * V_9 )
{
#if F_10 ( V_30 )
F_11 ( V_31 , V_32 ,
V_9 -> V_33 , V_9 ) ;
#endif
return 0 ;
}
void
F_12 ( struct V_29 * V_9 )
{
#if F_10 ( V_30 )
F_13 ( V_31 , V_32 ,
V_9 ) ;
#endif
}
int F_14 ( struct V_7 * V_8 ,
struct V_34 * V_35 ,
unsigned V_36 )
{
unsigned V_37 ;
for ( V_37 = 0 ; V_37 < V_8 -> V_38 ; V_37 ++ ) {
if ( V_8 -> V_39 [ V_37 ] . V_35 == V_35 ) {
return 0 ;
}
}
V_37 = V_8 -> V_38 + 1 ;
if ( V_37 > V_40 ) {
F_15 ( L_3 ) ;
F_15 ( L_4 ) ;
return - V_41 ;
}
V_8 -> V_39 [ V_8 -> V_38 ] . V_35 = V_35 ;
V_8 -> V_39 [ V_8 -> V_38 ] . V_42 = V_36 ;
V_8 -> V_38 = V_37 ;
#if F_10 ( V_30 )
F_11 ( V_35 , V_36 ,
V_8 -> V_43 -> V_44 -> V_33 ,
V_8 -> V_43 -> V_44 ) ;
F_11 ( V_35 , V_36 ,
V_8 -> V_43 -> V_45 -> V_33 ,
V_8 -> V_43 -> V_45 ) ;
#endif
return 0 ;
}
void F_16 ( struct V_7 * V_8 )
{
#if F_10 ( V_30 )
unsigned V_37 ;
for ( V_37 = 0 ; V_37 < V_8 -> V_38 ; V_37 ++ ) {
F_13 ( V_8 -> V_39 [ V_37 ] . V_35 ,
V_8 -> V_39 [ V_37 ] . V_42 ,
V_8 -> V_43 -> V_44 ) ;
F_13 ( V_8 -> V_39 [ V_37 ] . V_35 ,
V_8 -> V_39 [ V_37 ] . V_42 ,
V_8 -> V_43 -> V_45 ) ;
}
#endif
}
