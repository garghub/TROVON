static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 . V_2 ) ;
struct V_6 * V_6 = V_4 -> V_5 . V_6 ;
struct V_7 * V_8 ;
int V_9 ;
F_3 (bv, bio, i) {
struct V_10 * V_10 = V_8 -> V_11 ;
int V_12 = F_4 ( V_10 -> V_13 -> V_14 , V_10 ,
V_15 , 0 , V_10 -> V_16 ) ;
if ( V_12 ) {
F_5 ( 1 ) ;
F_6 ( V_10 ) ;
} else {
F_7 ( V_10 ) ;
}
F_8 ( V_10 ) ;
}
F_9 ( V_4 ) ;
F_10 ( V_6 ) ;
}
void F_11 ( struct V_3 * V_4 , struct V_6 * V_6 )
{
F_12 ( & V_4 -> V_5 . V_2 , F_1 ) ;
V_4 -> V_5 . V_6 = V_6 ;
F_13 ( V_17 , & V_4 -> V_5 . V_2 ) ;
}
void F_14 ( struct V_10 * * V_10 , bool V_18 )
{
struct V_3 * V_4 ;
struct V_10 * V_19 ;
if ( ( * V_10 ) -> V_13 )
return;
V_19 = * V_10 ;
V_4 = (struct V_3 * ) F_15 ( V_19 ) ;
* V_10 = V_4 -> V_20 . V_21 ;
if ( V_18 )
F_16 ( V_19 ) ;
}
int F_17 ( const struct V_22 * V_22 , T_1 V_23 ,
T_2 V_24 , unsigned int V_25 )
{
struct V_3 * V_4 ;
struct V_10 * V_26 = NULL ;
struct V_6 * V_6 ;
int V_12 , V_27 = 0 ;
F_18 ( V_22 -> V_28 -> V_29 != V_15 ) ;
V_4 = F_19 ( V_22 , V_30 ) ;
if ( F_20 ( V_4 ) )
return F_21 ( V_4 ) ;
V_26 = F_22 ( V_4 , V_31 ) ;
if ( F_20 ( V_26 ) ) {
V_27 = F_21 ( V_26 ) ;
goto V_32;
}
while ( V_25 -- ) {
V_27 = F_23 ( V_22 , V_33 , V_23 ,
F_24 ( 0 ) , V_26 ,
V_15 , 0 , V_30 ) ;
if ( V_27 )
goto V_32;
V_6 = F_25 ( V_31 , 1 ) ;
if ( ! V_6 ) {
V_27 = - V_34 ;
goto V_32;
}
V_6 -> V_35 = V_22 -> V_28 -> V_36 ;
V_6 -> V_37 . V_38 =
V_24 << ( V_22 -> V_28 -> V_39 - 9 ) ;
F_26 ( V_6 , V_40 , 0 ) ;
V_12 = F_27 ( V_6 , V_26 ,
V_22 -> V_28 -> V_29 , 0 ) ;
if ( V_12 != V_22 -> V_28 -> V_29 ) {
F_28 ( 1 ) ;
F_10 ( V_6 ) ;
V_27 = - V_41 ;
goto V_32;
}
V_27 = F_29 ( V_6 ) ;
if ( ( V_27 == 0 ) && V_6 -> V_42 )
V_27 = - V_41 ;
F_10 ( V_6 ) ;
if ( V_27 )
goto V_32;
V_23 ++ ;
V_24 ++ ;
}
V_27 = 0 ;
V_32:
F_9 ( V_4 ) ;
return V_27 ;
}
