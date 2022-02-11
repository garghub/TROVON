void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
T_2 V_6 ;
F_3 ( sizeof( struct V_7 ) != V_8 ) ;
if ( ! F_4 ( V_2 ) )
return;
V_5 = F_5 ( V_4 -> V_9 + F_6 ( V_5 ) ) ;
if ( V_5 != V_10 )
return;
V_6 = F_7 (
F_8 ( V_4 -> V_9 + F_6 ( V_11 ) ) ,
F_8 ( V_4 -> V_9 + F_6 ( V_12 ) ) ) ;
if ( V_6 != V_13 ) {
F_9 ( L_1 ) ;
return;
}
V_4 -> V_14 . V_15 = true ;
F_9 ( L_2 ) ;
}
void F_10 ( void )
{
int V_16 ;
F_11 ( L_3 ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
if ( V_17 . V_18 [ V_16 ] . V_19 )
F_12 ( & V_17 . V_18 [ V_16 ] ) ;
}
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_26 = V_25 - V_24 ;
if ( V_24 == V_25 )
return - V_27 ;
F_9 ( L_4 ,
V_24 , V_25 , V_26 / 1024 ) ;
V_23 -> V_24 = V_24 ;
V_23 -> V_26 = V_26 ;
return F_14 ( V_21 , V_23 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_29 = & V_4 -> V_30 . V_31 ;
unsigned long V_32 = V_29 -> V_24 + V_29 -> V_33 ;
unsigned long V_34 , V_35 , V_36 ;
unsigned long V_37 , V_38 , V_39 ;
int V_40 ;
V_34 = F_16 ( F_6 ( V_41 . V_42 . V_31 ) ) ;
V_35 = F_16 ( F_6 ( V_41 . V_42 . V_26 ) ) ;
V_37 = F_16 ( F_6 ( V_41 . V_43 . V_31 ) ) ;
V_38 = F_16 ( F_6 ( V_41 . V_43 . V_26 ) ) ;
V_36 = V_34 + V_35 ;
V_39 = V_37 + V_38 ;
F_9 ( L_5 ) ;
F_9 ( L_6 ,
V_34 , V_35 / 1024 ) ;
F_9 ( L_7 ,
V_37 , V_38 / 1024 ) ;
if ( V_34 < V_29 -> V_24 ||
V_36 > V_4 -> V_30 . V_36 ||
V_37 < V_4 -> V_30 . V_36 ||
V_39 > V_32 ) {
F_17 ( L_8 ) ;
return - V_27 ;
}
if ( V_37 > V_4 -> V_30 . V_36 ) {
V_40 = F_13 ( & V_29 -> V_21 ,
& V_17 . V_18 [ 2 ] ,
V_4 -> V_30 . V_36 ,
V_37 ) ;
if ( V_40 )
goto V_44;
}
if ( V_39 < V_32 - V_45 ) {
V_40 = F_13 ( & V_29 -> V_21 ,
& V_17 . V_18 [ 3 ] ,
V_39 ,
V_32 - V_45 ) ;
if ( V_40 )
goto V_44;
}
if ( V_34 > V_29 -> V_24 ) {
V_40 = F_13 ( & V_29 -> V_21 ,
& V_17 . V_18 [ 0 ] ,
V_29 -> V_24 , V_34 ) ;
if ( V_40 )
goto V_44;
}
if ( V_36 < V_4 -> V_30 . V_36 ) {
V_40 = F_13 ( & V_29 -> V_21 ,
& V_17 . V_18 [ 1 ] ,
V_36 ,
V_4 -> V_30 . V_36 ) ;
if ( V_40 )
goto V_44;
}
F_9 ( L_9 ) ;
return 0 ;
V_44:
F_17 ( L_10 ) ;
F_10 () ;
return V_40 ;
}
