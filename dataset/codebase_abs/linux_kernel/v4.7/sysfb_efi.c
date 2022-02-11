void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ V_4 ] . V_7 != 0 &&
! strcmp ( V_3 , V_6 [ V_4 ] . V_8 ) ) {
V_2 -> V_9 = V_6 [ V_4 ] . V_7 ;
V_2 -> V_10 = V_6 [ V_4 ] . V_11 ;
V_2 -> V_12 = V_6 [ V_4 ] . V_13 ;
V_2 -> V_14 = V_6 [ V_4 ] . V_15 ;
}
}
}
static int T_1 F_2 ( const struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
if ( V_19 -> V_7 == 0 && V_19 -> V_15 == 0 && V_19 -> V_13 == 0 &&
V_19 -> V_11 == 0 )
return 0 ;
if ( V_1 . V_9 == 0 ) {
#if F_3 ( V_21 )
struct V_22 * V_23 = NULL ;
int V_24 = 0 ;
#endif
if ( V_19 -> V_7 ) {
V_1 . V_9 = F_4 ( V_19 -> V_7 ,
V_1 . V_9 , V_25 ,
V_19 -> V_26 ) ;
#if F_3 ( V_21 )
F_5 (dev) {
int V_4 ;
if ( ( V_23 -> V_27 >> 8 ) != V_28 )
continue;
for ( V_4 = 0 ; V_4 < V_29 ; V_4 ++ ) {
T_2 V_30 , V_31 ;
unsigned long V_26 ;
V_26 = F_6 ( V_23 , V_4 ) ;
if ( ! ( V_26 & V_32 ) )
continue;
if ( V_26 & V_33 )
continue;
if ( F_7 ( V_23 , V_4 ) == 0 )
continue;
V_30 = F_8 ( V_23 , V_4 ) ;
V_31 = F_9 ( V_23 , V_4 ) ;
if ( V_1 . V_9 >= V_30 &&
V_1 . V_9 < V_31 ) {
V_24 = 1 ;
break;
}
}
}
if ( ! V_24 )
V_1 . V_9 = 0 ;
#endif
}
}
if ( V_1 . V_9 ) {
V_1 . V_10 = F_4 ( V_19 -> V_11 ,
V_1 . V_10 , V_34 ,
V_19 -> V_26 ) ;
V_1 . V_12 = F_4 ( V_19 -> V_13 ,
V_1 . V_12 , V_35 ,
V_19 -> V_26 ) ;
V_1 . V_14 = F_4 ( V_19 -> V_15 ,
V_1 . V_14 , V_36 ,
V_19 -> V_26 ) ;
if ( V_1 . V_37 == 0 )
V_1 . V_37 = V_38 ;
} else {
V_1 . V_10 = 0 ;
V_1 . V_12 = 0 ;
V_1 . V_14 = 0 ;
V_1 . V_37 = 0 ;
return 0 ;
}
F_10 ( V_39 L_1
L_2 , V_17 -> V_40 ,
V_1 . V_9 , V_1 . V_12 ,
V_1 . V_14 , V_1 . V_10 ) ;
return 1 ;
}
T_1 void F_11 ( void )
{
if ( V_1 . V_37 != V_38 ||
! ( V_1 . V_41 & V_42 ) )
F_12 ( V_43 ) ;
}
