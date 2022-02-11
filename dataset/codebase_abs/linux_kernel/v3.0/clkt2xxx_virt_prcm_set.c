unsigned long F_1 ( struct V_1 * V_1 )
{
return V_2 -> V_3 ;
}
long F_2 ( struct V_1 * V_1 , unsigned long V_4 )
{
const struct V_5 * V_6 ;
long V_7 ;
V_7 = - V_8 ;
for ( V_6 = V_9 ; V_6 -> V_3 ; V_6 ++ ) {
if ( ! ( V_6 -> V_10 & V_11 ) )
continue;
if ( V_6 -> V_12 != V_13 -> V_4 )
continue;
V_7 = V_6 -> V_3 ;
if ( V_6 -> V_3 <= V_4 )
break;
}
return V_7 ;
}
int F_3 ( struct V_1 * V_1 , unsigned long V_4 )
{
T_1 V_14 , V_15 , V_16 = 0 , V_17 ;
const struct V_5 * V_18 ;
unsigned long V_19 = 0 ;
unsigned long V_10 ;
for ( V_18 = V_9 ; V_18 -> V_3 ; V_18 ++ ) {
if ( ! ( V_18 -> V_10 & V_11 ) )
continue;
if ( V_18 -> V_12 != V_13 -> V_4 )
continue;
if ( V_18 -> V_3 <= V_4 ) {
V_19 = V_18 -> V_3 ;
break;
}
}
if ( ! V_19 ) {
F_4 ( V_20 L_1 ,
V_4 / 1000000 ) ;
return - V_8 ;
}
V_2 = V_18 ;
V_14 = F_5 ( V_21 ) ;
if ( V_18 -> V_22 == V_14 / 2 ) {
F_6 ( V_23 , 1 ) ;
} else if ( V_18 -> V_22 == V_14 * 2 ) {
F_6 ( V_24 , 1 ) ;
} else if ( V_18 -> V_22 != V_14 ) {
F_7 ( V_10 ) ;
if ( V_18 -> V_22 == V_18 -> V_12 )
V_16 = 1 ;
if ( ( V_18 -> V_25 & V_26 ) ==
V_24 )
V_15 = V_24 ;
else
V_15 = V_23 ;
F_8 ( V_18 -> V_27 , V_28 , V_29 ) ;
F_8 ( V_18 -> V_30 ,
V_31 , V_29 ) ;
F_8 ( V_18 -> V_32 , V_33 , V_29 ) ;
V_17 = F_9 ( V_34 , V_35 ) & V_36 ;
F_8 ( V_18 -> V_37 | V_17 , V_34 ,
V_35 ) ;
if ( F_10 () )
F_8 ( V_18 -> V_38 ,
V_39 , V_29 ) ;
F_6 ( V_24 , 1 ) ;
F_11 ( V_18 -> V_40 , V_18 -> V_41 ,
V_16 ) ;
F_12 ( F_13 () ) ;
F_6 ( V_15 , 0 ) ;
F_14 ( V_10 ) ;
}
return 0 ;
}
void F_15 ( struct V_42 * * V_43 )
{
const struct V_5 * V_18 ;
int V_44 = 0 ;
int V_45 = 0 ;
if ( ! F_16 () )
return;
for ( V_18 = V_9 ; V_18 -> V_3 ; V_18 ++ ) {
if ( ! ( V_18 -> V_10 & V_11 ) )
continue;
if ( V_18 -> V_12 != V_13 -> V_4 )
continue;
if ( V_18 -> V_22 == V_18 -> V_12 )
continue;
V_45 ++ ;
}
if ( V_45 == 0 ) {
F_17 ( L_2 ,
V_46 ) ;
return;
}
V_45 ++ ;
V_47 = F_18 ( sizeof( struct V_42 ) * V_45 ,
V_48 ) ;
if ( ! V_47 ) {
F_19 ( L_3 , V_46 ) ;
return;
}
for ( V_18 = V_9 ; V_18 -> V_3 ; V_18 ++ ) {
if ( ! ( V_18 -> V_10 & V_11 ) )
continue;
if ( V_18 -> V_12 != V_13 -> V_4 )
continue;
if ( V_18 -> V_22 == V_18 -> V_12 )
continue;
V_47 [ V_44 ] . V_49 = V_44 ;
V_47 [ V_44 ] . V_50 = V_18 -> V_3 / 1000 ;
V_44 ++ ;
}
V_47 [ V_44 ] . V_49 = V_44 ;
V_47 [ V_44 ] . V_50 = V_51 ;
* V_43 = & V_47 [ 0 ] ;
}
void F_20 ( struct V_42 * * V_43 )
{
if ( ! F_16 () )
return;
F_21 ( V_47 ) ;
}
