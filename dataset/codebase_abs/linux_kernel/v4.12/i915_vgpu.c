void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
F_2 ( sizeof( struct V_5 ) != V_6 ) ;
V_3 = F_3 ( V_2 , F_4 ( V_3 ) ) ;
if ( V_3 != V_7 )
return;
V_4 = F_5 ( V_2 , F_4 ( V_4 ) ) ;
if ( V_4 < V_8 ) {
F_6 ( L_1 ) ;
return;
}
V_2 -> V_9 . V_10 = true ;
F_6 ( L_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! F_8 ( V_2 ) )
return;
F_9 ( L_3 ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
if ( V_12 . V_13 [ V_11 ] . V_14 )
F_10 ( & V_12 . V_13 [ V_11 ] ) ;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
}
static int F_11 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned long V_19 , unsigned long V_20 )
{
unsigned long V_21 = V_20 - V_19 ;
if ( V_19 >= V_20 )
return - V_22 ;
F_6 ( L_4 ,
V_19 , V_20 , V_21 / 1024 ) ;
return F_12 ( & V_16 -> V_23 , V_18 ,
V_21 , V_19 , V_24 ,
0 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
unsigned long V_25 = V_16 -> V_23 . V_26 ;
unsigned long V_27 , V_28 , V_29 ;
unsigned long V_30 , V_31 , V_32 ;
int V_33 ;
if ( ! F_8 ( V_2 ) )
return 0 ;
V_27 = F_14 ( F_4 ( V_34 . V_35 . V_23 ) ) ;
V_28 = F_14 ( F_4 ( V_34 . V_35 . V_21 ) ) ;
V_30 = F_14 ( F_4 ( V_34 . V_36 . V_23 ) ) ;
V_31 = F_14 ( F_4 ( V_34 . V_36 . V_21 ) ) ;
V_29 = V_27 + V_28 ;
V_32 = V_30 + V_31 ;
F_6 ( L_5 ) ;
F_6 ( L_6 ,
V_27 , V_28 / 1024 ) ;
F_6 ( L_7 ,
V_30 , V_31 / 1024 ) ;
if ( V_29 > V_16 -> V_29 ||
V_30 < V_16 -> V_29 ||
V_32 > V_25 ) {
F_15 ( L_8 ) ;
return - V_22 ;
}
if ( V_30 > V_16 -> V_29 ) {
V_33 = F_11 ( V_16 , & V_12 . V_13 [ 2 ] ,
V_16 -> V_29 , V_30 ) ;
if ( V_33 )
goto V_37;
}
if ( V_32 < V_25 ) {
V_33 = F_11 ( V_16 , & V_12 . V_13 [ 3 ] ,
V_32 , V_25 ) ;
if ( V_33 )
goto V_37;
}
if ( V_27 ) {
V_33 = F_11 ( V_16 , & V_12 . V_13 [ 0 ] ,
0 , V_27 ) ;
if ( V_33 )
goto V_37;
}
if ( V_29 < V_16 -> V_29 ) {
V_33 = F_11 ( V_16 , & V_12 . V_13 [ 1 ] ,
V_29 , V_16 -> V_29 ) ;
if ( V_33 )
goto V_37;
}
F_6 ( L_9 ) ;
return 0 ;
V_37:
F_15 ( L_10 ) ;
F_7 ( V_2 ) ;
return V_33 ;
}
