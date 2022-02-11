unsigned long F_1 ( struct V_1 * V_1 )
{
return V_2 -> V_3 ;
}
long F_2 ( struct V_1 * V_1 , unsigned long V_4 )
{
const struct V_5 * V_6 ;
long V_7 , V_8 ;
V_7 = - V_9 ;
V_8 = F_3 ( V_10 ) ;
for ( V_6 = V_11 ; V_6 -> V_3 ; V_6 ++ ) {
if ( ! ( V_6 -> V_12 & V_13 ) )
continue;
if ( V_6 -> V_14 != V_8 )
continue;
V_7 = V_6 -> V_3 ;
if ( V_6 -> V_3 <= V_4 )
break;
}
return V_7 ;
}
int F_4 ( struct V_1 * V_1 , unsigned long V_4 )
{
T_1 V_15 , V_16 , V_17 = 0 , V_18 ;
const struct V_5 * V_19 ;
unsigned long V_20 = 0 ;
unsigned long V_12 ;
long V_8 ;
V_8 = F_3 ( V_10 ) ;
for ( V_19 = V_11 ; V_19 -> V_3 ; V_19 ++ ) {
if ( ! ( V_19 -> V_12 & V_13 ) )
continue;
if ( V_19 -> V_14 != V_8 )
continue;
if ( V_19 -> V_3 <= V_4 ) {
V_20 = V_19 -> V_3 ;
break;
}
}
if ( ! V_20 ) {
F_5 ( V_21 L_1 ,
V_4 / 1000000 ) ;
return - V_9 ;
}
V_2 = V_19 ;
V_15 = F_6 ( V_22 ) ;
if ( V_19 -> V_23 == V_15 / 2 ) {
F_7 ( V_24 , 1 ) ;
} else if ( V_19 -> V_23 == V_15 * 2 ) {
F_7 ( V_25 , 1 ) ;
} else if ( V_19 -> V_23 != V_15 ) {
F_8 ( V_12 ) ;
if ( V_19 -> V_23 == V_19 -> V_14 )
V_17 = 1 ;
if ( ( V_19 -> V_26 & V_27 ) ==
V_25 )
V_16 = V_25 ;
else
V_16 = V_24 ;
F_9 ( V_19 -> V_28 , V_29 , V_30 ) ;
F_9 ( V_19 -> V_31 ,
V_32 , V_30 ) ;
F_9 ( V_19 -> V_33 , V_34 , V_30 ) ;
V_18 = F_10 ( V_35 , V_36 ) & V_37 ;
F_9 ( V_19 -> V_38 | V_18 , V_35 ,
V_36 ) ;
if ( F_11 () )
F_9 ( V_19 -> V_39 ,
V_40 , V_30 ) ;
F_7 ( V_25 , 1 ) ;
F_12 ( V_19 -> V_41 , V_19 -> V_42 ,
V_17 ) ;
F_13 ( F_14 () ) ;
F_7 ( V_16 , 0 ) ;
F_15 ( V_12 ) ;
}
return 0 ;
}
