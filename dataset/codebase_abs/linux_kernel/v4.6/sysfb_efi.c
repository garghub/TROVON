static int T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 == 0 && V_4 -> V_7 == 0 && V_4 -> V_8 == 0 &&
V_4 -> V_9 == 0 )
return 0 ;
if ( V_10 . V_11 == 0 ) {
#if F_2 ( V_12 )
struct V_13 * V_14 = NULL ;
int V_15 = 0 ;
#endif
if ( V_4 -> V_6 ) {
V_10 . V_11 = F_3 ( V_4 -> V_6 ,
V_10 . V_11 , V_16 ,
V_4 -> V_17 ) ;
#if F_2 ( V_12 )
F_4 (dev) {
int V_18 ;
if ( ( V_14 -> V_19 >> 8 ) != V_20 )
continue;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
T_2 V_22 , V_23 ;
unsigned long V_17 ;
V_17 = F_5 ( V_14 , V_18 ) ;
if ( ! ( V_17 & V_24 ) )
continue;
if ( V_17 & V_25 )
continue;
if ( F_6 ( V_14 , V_18 ) == 0 )
continue;
V_22 = F_7 ( V_14 , V_18 ) ;
V_23 = F_8 ( V_14 , V_18 ) ;
if ( V_10 . V_11 >= V_22 &&
V_10 . V_11 < V_23 ) {
V_15 = 1 ;
break;
}
}
}
if ( ! V_15 )
V_10 . V_11 = 0 ;
#endif
}
}
if ( V_10 . V_11 ) {
V_10 . V_26 = F_3 ( V_4 -> V_9 ,
V_10 . V_26 , V_27 ,
V_4 -> V_17 ) ;
V_10 . V_28 = F_3 ( V_4 -> V_8 ,
V_10 . V_28 , V_29 ,
V_4 -> V_17 ) ;
V_10 . V_30 = F_3 ( V_4 -> V_7 ,
V_10 . V_30 , V_31 ,
V_4 -> V_17 ) ;
if ( V_10 . V_32 == 0 )
V_10 . V_32 = V_33 ;
} else {
V_10 . V_26 = 0 ;
V_10 . V_28 = 0 ;
V_10 . V_30 = 0 ;
V_10 . V_32 = 0 ;
return 0 ;
}
F_9 ( V_34 L_1
L_2 , V_2 -> V_35 ,
V_10 . V_11 , V_10 . V_28 ,
V_10 . V_30 , V_10 . V_26 ) ;
return 1 ;
}
T_1 void F_10 ( void )
{
if ( V_10 . V_32 != V_33 ||
! ( V_10 . V_36 & V_37 ) )
F_11 ( V_38 ) ;
}
