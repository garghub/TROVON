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
static void F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
F_8 ( L_3 ,
V_14 -> V_15 ,
V_14 -> V_15 + V_14 -> V_16 ,
V_14 -> V_16 / 1024 ) ;
V_12 -> V_17 . V_18 -= V_14 -> V_16 ;
F_9 ( V_14 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_19 ;
if ( ! F_11 ( V_2 ) )
return;
F_12 ( L_4 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
F_7 ( & V_2 -> V_12 , & V_20 . V_21 [ V_19 ] ) ;
}
static int F_13 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned long V_15 , unsigned long V_22 )
{
unsigned long V_16 = V_22 - V_15 ;
int V_23 ;
if ( V_15 >= V_22 )
return - V_24 ;
F_6 ( L_5 ,
V_15 , V_22 , V_16 / 1024 ) ;
V_23 = F_14 ( & V_12 -> V_17 , V_14 ,
V_16 , V_15 , V_25 ,
0 ) ;
if ( ! V_23 )
V_12 -> V_17 . V_18 += V_16 ;
return V_23 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
unsigned long V_26 = V_12 -> V_17 . V_27 ;
unsigned long V_28 , V_29 , V_30 ;
unsigned long V_31 , V_32 , V_33 ;
int V_23 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
V_28 = F_16 ( F_4 ( V_34 . V_35 . V_17 ) ) ;
V_29 = F_16 ( F_4 ( V_34 . V_35 . V_16 ) ) ;
V_31 = F_16 ( F_4 ( V_34 . V_36 . V_17 ) ) ;
V_32 = F_16 ( F_4 ( V_34 . V_36 . V_16 ) ) ;
V_30 = V_28 + V_29 ;
V_33 = V_31 + V_32 ;
F_6 ( L_6 ) ;
F_6 ( L_7 ,
V_28 , V_29 / 1024 ) ;
F_6 ( L_8 ,
V_31 , V_32 / 1024 ) ;
if ( V_30 > V_12 -> V_30 ||
V_31 < V_12 -> V_30 ||
V_33 > V_26 ) {
F_17 ( L_9 ) ;
return - V_24 ;
}
if ( V_31 > V_12 -> V_30 ) {
V_23 = F_13 ( V_12 , & V_20 . V_21 [ 2 ] ,
V_12 -> V_30 , V_31 ) ;
if ( V_23 )
goto V_37;
}
if ( V_33 < V_26 ) {
V_23 = F_13 ( V_12 , & V_20 . V_21 [ 3 ] ,
V_33 , V_26 ) ;
if ( V_23 )
goto V_38;
}
if ( V_28 ) {
V_23 = F_13 ( V_12 , & V_20 . V_21 [ 0 ] ,
0 , V_28 ) ;
if ( V_23 )
goto V_39;
}
if ( V_30 < V_12 -> V_30 ) {
V_23 = F_13 ( V_12 , & V_20 . V_21 [ 1 ] ,
V_30 , V_12 -> V_30 ) ;
if ( V_23 )
goto V_40;
}
F_6 ( L_10 ) ;
return 0 ;
V_40:
F_7 ( V_12 , & V_20 . V_21 [ 0 ] ) ;
V_39:
F_7 ( V_12 , & V_20 . V_21 [ 3 ] ) ;
V_38:
F_7 ( V_12 , & V_20 . V_21 [ 2 ] ) ;
V_37:
F_17 ( L_11 ) ;
return V_23 ;
}
