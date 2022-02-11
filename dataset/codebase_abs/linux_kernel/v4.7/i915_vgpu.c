void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
T_2 V_6 ;
F_3 ( sizeof( struct V_7 ) != V_8 ) ;
if ( ! F_4 ( V_2 ) )
return;
V_5 = F_5 ( V_4 , F_6 ( V_5 ) ) ;
if ( V_5 != V_9 )
return;
V_6 = F_7 (
F_8 ( V_4 , F_6 ( V_10 ) ) ,
F_8 ( V_4 , F_6 ( V_11 ) ) ) ;
if ( V_6 != V_12 ) {
F_9 ( L_1 ) ;
return;
}
V_4 -> V_13 . V_14 = true ;
F_9 ( L_2 ) ;
}
void F_10 ( void )
{
int V_15 ;
F_11 ( L_3 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( V_16 . V_17 [ V_15 ] . V_18 )
F_12 ( & V_16 . V_17 [ V_15 ] ) ;
}
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned long V_23 , unsigned long V_24 )
{
unsigned long V_25 = V_24 - V_23 ;
if ( V_23 == V_24 )
return - V_26 ;
F_9 ( L_4 ,
V_23 , V_24 , V_25 / 1024 ) ;
V_22 -> V_23 = V_23 ;
V_22 -> V_25 = V_25 ;
return F_14 ( V_20 , V_22 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_28 ;
unsigned long V_29 = V_28 -> V_30 . V_23 + V_28 -> V_30 . V_31 ;
unsigned long V_32 , V_33 , V_34 ;
unsigned long V_35 , V_36 , V_37 ;
int V_38 ;
V_32 = F_16 ( F_6 ( V_39 . V_40 . V_30 ) ) ;
V_33 = F_16 ( F_6 ( V_39 . V_40 . V_25 ) ) ;
V_35 = F_16 ( F_6 ( V_39 . V_41 . V_30 ) ) ;
V_36 = F_16 ( F_6 ( V_39 . V_41 . V_25 ) ) ;
V_34 = V_32 + V_33 ;
V_37 = V_35 + V_36 ;
F_9 ( L_5 ) ;
F_9 ( L_6 ,
V_32 , V_33 / 1024 ) ;
F_9 ( L_7 ,
V_35 , V_36 / 1024 ) ;
if ( V_32 < V_28 -> V_30 . V_23 ||
V_34 > V_28 -> V_34 ||
V_35 < V_28 -> V_34 ||
V_37 > V_29 ) {
F_17 ( L_8 ) ;
return - V_26 ;
}
if ( V_35 > V_28 -> V_34 ) {
V_38 = F_13 ( & V_28 -> V_30 . V_20 ,
& V_16 . V_17 [ 2 ] ,
V_28 -> V_34 ,
V_35 ) ;
if ( V_38 )
goto V_42;
}
if ( V_37 < V_29 - V_43 ) {
V_38 = F_13 ( & V_28 -> V_30 . V_20 ,
& V_16 . V_17 [ 3 ] ,
V_37 ,
V_29 - V_43 ) ;
if ( V_38 )
goto V_42;
}
if ( V_32 > V_28 -> V_30 . V_23 ) {
V_38 = F_13 ( & V_28 -> V_30 . V_20 ,
& V_16 . V_17 [ 0 ] ,
V_28 -> V_30 . V_23 , V_32 ) ;
if ( V_38 )
goto V_42;
}
if ( V_34 < V_28 -> V_34 ) {
V_38 = F_13 ( & V_28 -> V_30 . V_20 ,
& V_16 . V_17 [ 1 ] ,
V_34 ,
V_28 -> V_34 ) ;
if ( V_38 )
goto V_42;
}
F_9 ( L_9 ) ;
return 0 ;
V_42:
F_17 ( L_10 ) ;
F_10 () ;
return V_38 ;
}
