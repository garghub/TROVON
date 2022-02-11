struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_4 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 ;
unsigned int V_10 , V_11 , V_12 ;
struct V_4 * V_13 ;
int V_14 , V_15 ;
if ( V_6 -> V_16 > V_6 -> V_17 )
return F_2 ( - V_18 ) ;
V_9 = F_3 ( sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
return F_2 ( - V_20 ) ;
V_9 -> V_8 = V_8 ;
V_9 -> V_6 . V_16 = V_6 -> V_16 ;
V_9 -> V_6 . V_17 = V_6 -> V_17 ;
V_9 -> V_6 . V_21 = V_22 ;
V_10 = F_4 ( & V_9 -> V_6 ) ;
V_11 = F_4 ( V_5 ) >> V_8 -> V_23 ;
if ( V_10 > V_11 ) {
V_10 = V_11 ;
V_9 -> V_6 . V_17 = V_6 -> V_16 + V_10 - 1 ;
F_5 ( V_3 , L_1 ,
V_5 , & V_9 -> V_6 , V_6 ) ;
}
V_12 = 1 << V_8 -> V_23 ;
V_9 -> V_24 . V_16 = V_5 -> V_16 ;
V_9 -> V_24 . V_17 = V_5 -> V_17 ;
V_9 -> V_24 . V_21 = V_25 | V_26 ;
V_9 -> V_24 . V_27 = L_2 ;
V_13 = F_6 ( & V_28 , & V_9 -> V_24 ) ;
if ( V_13 ) {
V_15 = - V_29 ;
F_7 ( V_3 , L_3 ,
& V_9 -> V_24 , V_13 -> V_27 , V_13 ) ;
goto V_30;
}
if ( V_31 ) {
V_9 -> V_32 = F_8 ( V_10 , sizeof( * V_9 -> V_32 ) , V_19 ) ;
if ( ! V_9 -> V_32 )
goto V_33;
for ( V_14 = 0 ; V_14 < V_10 ; V_14 ++ ) {
V_9 -> V_32 [ V_14 ] = F_9 ( V_5 -> V_16 + V_14 * V_12 , V_12 ) ;
if ( ! V_9 -> V_32 [ V_14 ] )
goto V_34;
}
} else {
V_9 -> V_35 = F_9 ( V_5 -> V_16 , V_10 * V_12 ) ;
if ( ! V_9 -> V_35 )
goto V_34;
}
if ( V_8 -> V_36 ) {
V_15 = V_8 -> V_36 ( V_3 , V_9 ) ;
if ( V_15 )
goto V_30;
}
F_10 ( V_3 , L_4 , & V_9 -> V_24 , & V_9 -> V_6 ) ;
return V_9 ;
V_34:
F_7 ( V_3 , L_5 ) ;
V_33:
V_15 = - V_20 ;
V_30:
F_11 ( V_9 ) ;
return F_2 ( V_15 ) ;
}
void F_11 ( struct V_1 * V_9 )
{
int V_14 ;
if ( V_31 ) {
if ( V_9 -> V_32 ) {
for ( V_14 = 0 ; V_14 < F_4 ( & V_9 -> V_6 ) ; V_14 ++ )
if ( V_9 -> V_32 [ V_14 ] )
F_12 ( V_9 -> V_32 [ V_14 ] ) ;
F_13 ( V_9 -> V_32 ) ;
}
} else {
if ( V_9 -> V_35 )
F_12 ( V_9 -> V_35 ) ;
}
if ( V_9 -> V_24 . V_37 )
F_14 ( & V_9 -> V_24 ) ;
F_13 ( V_9 ) ;
}
void T_1 * F_15 ( struct V_38 * V_39 , unsigned int V_40 ,
int V_41 )
{
struct V_1 * V_9 = V_39 -> V_42 ;
unsigned int V_43 = V_9 -> V_8 -> V_23 - 8 ;
unsigned int V_44 = V_39 -> V_45 ;
void T_1 * V_46 ;
if ( V_44 < V_9 -> V_6 . V_16 || V_44 > V_9 -> V_6 . V_17 )
return NULL ;
V_44 -= V_9 -> V_6 . V_16 ;
if ( V_31 )
V_46 = V_9 -> V_32 [ V_44 ] ;
else
V_46 = V_9 -> V_35 + ( V_44 << V_9 -> V_8 -> V_23 ) ;
return V_46 + ( V_40 << V_43 ) + V_41 ;
}
