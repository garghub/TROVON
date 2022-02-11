void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_4 ;
T_1 V_5 ;
if ( ! V_3 )
return;
if ( V_2 -> V_6 & V_7 )
V_4 = V_2 -> V_8 + V_2 -> V_9 ;
else
V_4 = V_2 -> V_8 + V_2 -> V_5 ;
F_2 ( F_3 ( V_4 , V_5 , V_5 & V_3 , 100 , 70000 ) ) ;
}
static int F_4 ( struct V_10 * V_11 ,
unsigned long V_12 , void * V_13 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
int V_16 = 0 ;
if ( V_12 != V_17 )
goto V_18;
F_6 ( V_15 -> V_2 , V_15 -> V_19 ) ;
V_16 = F_7 ( V_15 -> V_2 , V_15 -> V_19 ) ;
if ( V_16 )
goto V_18;
F_1 ( V_15 -> V_2 , V_15 -> V_3 ) ;
V_18:
return F_8 ( V_16 ) ;
}
int F_9 ( struct V_14 * V_20 )
{
V_20 -> V_21 . V_22 = F_4 ;
return F_10 ( V_20 -> V_2 -> V_23 . V_24 ,
& V_20 -> V_21 ) ;
}
int F_11 ( struct V_25 * V_26 , void T_2 * V_5 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 ;
int V_31 , V_16 ;
for ( V_31 = 0 ; V_31 < V_28 -> V_32 ; V_31 ++ ) {
struct V_1 * V_33 = V_28 -> V_34 [ V_31 ] ;
if ( ! V_33 )
continue;
V_33 -> V_8 = V_5 ;
V_33 -> V_3 = & V_35 ;
}
for ( V_31 = 0 ; V_31 < V_28 -> V_36 -> V_37 ; V_31 ++ ) {
struct V_38 * V_23 = V_28 -> V_36 -> V_39 [ V_31 ] ;
if ( ! V_23 )
continue;
V_16 = F_12 ( NULL , V_23 ) ;
if ( V_16 ) {
F_13 ( L_1 ,
V_31 , F_14 ( V_23 ) ) ;
goto V_40;
}
}
V_16 = F_15 ( V_26 , V_41 ,
V_28 -> V_36 ) ;
if ( V_16 )
goto V_40;
V_30 = F_16 ( sizeof( * V_30 ) , V_42 ) ;
if ( ! V_30 ) {
V_16 = - V_43 ;
goto V_44;
}
V_30 -> V_45 . V_46 = V_26 ;
V_30 -> V_45 . V_47 = & V_48 ;
V_30 -> V_45 . V_49 = V_50 ;
V_30 -> V_45 . V_51 = V_28 -> V_52 ;
V_30 -> V_8 = V_5 ;
V_30 -> V_3 = & V_35 ;
V_30 -> V_53 = V_28 -> V_54 ;
V_16 = F_17 ( & V_30 -> V_45 ) ;
if ( V_16 )
goto V_55;
return 0 ;
V_55:
F_18 ( V_30 ) ;
V_44:
F_19 ( V_26 ) ;
V_40:
while ( -- V_31 >= 0 ) {
struct V_38 * V_23 = V_28 -> V_36 -> V_39 [ V_31 ] ;
if ( ! V_23 )
continue;
F_20 ( V_23 ) ;
}
return V_16 ;
}
