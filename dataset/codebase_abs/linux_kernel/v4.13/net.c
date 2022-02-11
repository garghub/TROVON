int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 , V_5 ) ;
char V_6 [ 16 ] ;
V_4 -> V_7 = V_2 ;
F_3 () ;
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_8 , V_4 -> V_7 , V_4 -> V_7 ,
V_9 , 0 , V_4 -> V_7 ) ;
F_7 ( L_1 ) ;
F_7 ( L_2 ,
F_8 ( V_6 , V_4 -> V_7 ) ,
V_4 -> V_10 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 , V_5 ) ;
if ( ! V_4 -> V_7 )
return;
F_10 ( V_1 , V_8 , V_4 -> V_7 , 0 ,
V_4 -> V_7 ) ;
F_11 () ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 () ;
F_7 ( L_3 ) ;
}
static int F_15 ( struct V_1 * V_1 , struct V_11 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_1 , V_5 ) ;
void * V_13 ;
struct V_14 * V_15 ;
V_13 = F_16 ( V_12 -> V_16 , V_12 -> V_17 , V_12 -> V_18 , & V_19 ,
V_20 , V_21 ) ;
if ( ! V_13 )
return - V_22 ;
V_15 = F_17 ( V_12 -> V_16 , V_23 ) ;
if ( ! V_15 )
goto V_24;
if ( F_18 ( V_12 -> V_16 , V_25 , V_4 -> V_10 ) )
goto V_26;
F_19 ( V_12 -> V_16 , V_15 ) ;
F_20 ( V_12 -> V_16 , V_13 ) ;
return 0 ;
V_26:
F_21 ( V_12 -> V_16 , V_15 ) ;
V_24:
F_22 ( V_12 -> V_16 , V_13 ) ;
return - V_22 ;
}
int F_23 ( struct V_27 * V_16 , struct V_28 * V_29 )
{
struct V_1 * V_1 = F_24 ( V_16 -> V_30 ) ;
int V_31 ;
int V_32 = V_29 -> args [ 0 ] ;
struct V_11 V_12 ;
if ( V_32 )
return 0 ;
V_12 . V_16 = V_16 ;
V_12 . V_17 = F_25 ( V_29 -> V_16 ) . V_17 ;
V_12 . V_18 = V_29 -> V_33 -> V_34 ;
V_31 = F_15 ( V_1 , & V_12 ) ;
if ( V_31 )
goto V_35;
V_32 = 1 ;
V_35:
V_29 -> args [ 0 ] = V_32 ;
return V_16 -> V_36 ;
}
int F_26 ( struct V_27 * V_16 , struct V_37 * V_38 )
{
struct V_1 * V_1 = F_24 ( V_16 -> V_30 ) ;
struct V_3 * V_4 = F_2 ( V_1 , V_5 ) ;
struct V_14 * V_15 [ V_39 + 1 ] ;
int V_31 ;
if ( ! V_38 -> V_15 [ V_23 ] )
return - V_40 ;
V_31 = F_27 ( V_15 , V_39 ,
V_38 -> V_15 [ V_23 ] , V_41 ,
V_38 -> V_42 ) ;
if ( V_31 )
return V_31 ;
if ( V_15 [ V_25 ] ) {
T_1 V_43 ;
if ( V_4 -> V_7 )
return - V_44 ;
V_43 = F_28 ( V_15 [ V_25 ] ) ;
if ( V_43 < 1 || V_43 > 9999 )
return - V_40 ;
V_4 -> V_10 = V_43 ;
}
if ( V_15 [ V_45 ] ) {
T_1 V_2 ;
if ( V_4 -> V_7 )
return - V_44 ;
V_2 = F_28 ( V_15 [ V_45 ] ) ;
if ( ! F_29 ( V_2 ) )
return - V_40 ;
F_11 () ;
F_1 ( V_1 , V_2 ) ;
F_14 () ;
}
return 0 ;
}
