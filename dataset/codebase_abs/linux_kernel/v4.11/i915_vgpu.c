void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
F_2 ( sizeof( struct V_5 ) != V_6 ) ;
V_3 = F_3 ( V_2 , F_4 ( V_3 ) ) ;
if ( V_3 != V_7 )
return;
V_4 = F_5 (
F_6 ( V_2 , F_4 ( V_8 ) ) ,
F_6 ( V_2 , F_4 ( V_9 ) ) ) ;
if ( V_4 != V_10 ) {
F_7 ( L_1 ) ;
return;
}
V_2 -> V_11 . V_12 = true ;
F_7 ( L_2 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! F_9 ( V_2 ) )
return;
F_10 ( L_3 ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
if ( V_14 . V_15 [ V_13 ] . V_16 )
F_11 ( & V_14 . V_15 [ V_13 ] ) ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
}
static int F_12 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
unsigned long V_23 = V_22 - V_21 ;
if ( V_21 >= V_22 )
return - V_24 ;
F_7 ( L_4 ,
V_21 , V_22 , V_23 / 1024 ) ;
return F_13 ( & V_18 -> V_25 , V_20 ,
V_23 , V_21 , V_26 ,
0 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
unsigned long V_27 = V_18 -> V_25 . V_21 + V_18 -> V_25 . V_28 ;
unsigned long V_29 , V_30 , V_31 ;
unsigned long V_32 , V_33 , V_34 ;
int V_35 ;
if ( ! F_9 ( V_2 ) )
return 0 ;
V_29 = F_15 ( F_4 ( V_36 . V_37 . V_25 ) ) ;
V_30 = F_15 ( F_4 ( V_36 . V_37 . V_23 ) ) ;
V_32 = F_15 ( F_4 ( V_36 . V_38 . V_25 ) ) ;
V_33 = F_15 ( F_4 ( V_36 . V_38 . V_23 ) ) ;
V_31 = V_29 + V_30 ;
V_34 = V_32 + V_33 ;
F_7 ( L_5 ) ;
F_7 ( L_6 ,
V_29 , V_30 / 1024 ) ;
F_7 ( L_7 ,
V_32 , V_33 / 1024 ) ;
if ( V_29 < V_18 -> V_25 . V_21 ||
V_31 > V_18 -> V_31 ||
V_32 < V_18 -> V_31 ||
V_34 > V_27 ) {
F_16 ( L_8 ) ;
return - V_24 ;
}
if ( V_32 > V_18 -> V_31 ) {
V_35 = F_12 ( V_18 , & V_14 . V_15 [ 2 ] ,
V_18 -> V_31 , V_32 ) ;
if ( V_35 )
goto V_39;
}
if ( V_34 < V_27 - V_40 ) {
V_35 = F_12 ( V_18 , & V_14 . V_15 [ 3 ] ,
V_34 , V_27 - V_40 ) ;
if ( V_35 )
goto V_39;
}
if ( V_29 > V_18 -> V_25 . V_21 ) {
V_35 = F_12 ( V_18 , & V_14 . V_15 [ 0 ] ,
V_18 -> V_25 . V_21 , V_29 ) ;
if ( V_35 )
goto V_39;
}
if ( V_31 < V_18 -> V_31 ) {
V_35 = F_12 ( V_18 , & V_14 . V_15 [ 1 ] ,
V_31 , V_18 -> V_31 ) ;
if ( V_35 )
goto V_39;
}
F_7 ( L_9 ) ;
return 0 ;
V_39:
F_16 ( L_10 ) ;
F_8 ( V_2 ) ;
return V_35 ;
}
