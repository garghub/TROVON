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
V_2 -> V_9 . V_10 = F_7 ( V_2 , F_4 ( V_11 ) ) ;
V_2 -> V_9 . V_12 = true ;
F_6 ( L_2 ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_9 . V_10 & V_13 ;
}
static void F_9 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
F_10 ( L_3 ,
V_17 -> V_18 ,
V_17 -> V_18 + V_17 -> V_19 ,
V_17 -> V_19 / 1024 ) ;
V_15 -> V_20 . V_21 -= V_17 -> V_19 ;
F_11 ( V_17 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
int V_22 ;
if ( ! F_13 ( V_2 ) )
return;
F_14 ( L_4 ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
F_9 ( & V_2 -> V_15 , & V_23 . V_24 [ V_22 ] ) ;
}
static int F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned long V_18 , unsigned long V_25 )
{
unsigned long V_19 = V_25 - V_18 ;
int V_26 ;
if ( V_18 >= V_25 )
return - V_27 ;
F_6 ( L_5 ,
V_18 , V_25 , V_19 / 1024 ) ;
V_26 = F_16 ( & V_15 -> V_20 , V_17 ,
V_19 , V_18 , V_28 ,
0 ) ;
if ( ! V_26 )
V_15 -> V_20 . V_21 += V_19 ;
return V_26 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
unsigned long V_29 = V_15 -> V_20 . V_30 ;
unsigned long V_31 , V_32 , V_33 ;
unsigned long V_34 , V_35 , V_36 ;
int V_26 ;
if ( ! F_13 ( V_2 ) )
return 0 ;
V_31 = F_18 ( F_4 ( V_37 . V_38 . V_20 ) ) ;
V_32 = F_18 ( F_4 ( V_37 . V_38 . V_19 ) ) ;
V_34 = F_18 ( F_4 ( V_37 . V_39 . V_20 ) ) ;
V_35 = F_18 ( F_4 ( V_37 . V_39 . V_19 ) ) ;
V_33 = V_31 + V_32 ;
V_36 = V_34 + V_35 ;
F_6 ( L_6 ) ;
F_6 ( L_7 ,
V_31 , V_32 / 1024 ) ;
F_6 ( L_8 ,
V_34 , V_35 / 1024 ) ;
if ( V_33 > V_15 -> V_33 ||
V_34 < V_15 -> V_33 ||
V_36 > V_29 ) {
F_19 ( L_9 ) ;
return - V_27 ;
}
if ( V_34 > V_15 -> V_33 ) {
V_26 = F_15 ( V_15 , & V_23 . V_24 [ 2 ] ,
V_15 -> V_33 , V_34 ) ;
if ( V_26 )
goto V_40;
}
if ( V_36 < V_29 ) {
V_26 = F_15 ( V_15 , & V_23 . V_24 [ 3 ] ,
V_36 , V_29 ) ;
if ( V_26 )
goto V_41;
}
if ( V_31 ) {
V_26 = F_15 ( V_15 , & V_23 . V_24 [ 0 ] ,
0 , V_31 ) ;
if ( V_26 )
goto V_42;
}
if ( V_33 < V_15 -> V_33 ) {
V_26 = F_15 ( V_15 , & V_23 . V_24 [ 1 ] ,
V_33 , V_15 -> V_33 ) ;
if ( V_26 )
goto V_43;
}
F_6 ( L_10 ) ;
return 0 ;
V_43:
F_9 ( V_15 , & V_23 . V_24 [ 0 ] ) ;
V_42:
F_9 ( V_15 , & V_23 . V_24 [ 3 ] ) ;
V_41:
F_9 ( V_15 , & V_23 . V_24 [ 2 ] ) ;
V_40:
F_19 ( L_11 ) ;
return V_26 ;
}
