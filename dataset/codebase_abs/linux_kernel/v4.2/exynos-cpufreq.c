static int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_2 * V_5 ;
F_2 (pos, freq_table)
if ( V_5 -> V_6 == V_1 )
break;
if ( V_5 -> V_6 == V_7 )
return - V_8 ;
return V_5 - V_3 ;
}
static int F_3 ( unsigned int V_9 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
unsigned int * V_10 = V_4 -> V_10 ;
struct V_11 * V_12 = F_4 ( 0 ) ;
unsigned int V_13 , V_14 = 0 ;
unsigned int V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_4 -> V_17 ;
unsigned int V_18 ;
int V_19 , V_20 ;
int V_21 = 0 ;
V_18 = V_12 -> V_22 ;
V_20 = F_1 ( V_18 ) ;
if ( V_20 < 0 ) {
V_21 = V_20 ;
goto V_23;
}
V_19 = F_1 ( V_9 ) ;
if ( V_19 < 0 ) {
V_21 = V_19 ;
goto V_23;
}
if ( V_4 -> V_24 != NULL ) {
if ( V_4 -> V_24 ( V_20 , V_19 ) &&
( V_3 [ V_19 ] . V_6 < V_15 ) &&
( V_3 [ V_20 ] . V_6 < V_15 ) )
V_14 = V_10 [ V_4 -> V_25 ] ;
}
V_13 = V_10 [ V_19 ] ;
if ( ( V_9 > V_18 ) && ! V_14 ) {
V_21 = F_5 ( V_26 , V_13 , V_13 ) ;
if ( V_21 ) {
F_6 ( V_17 , L_1 ,
V_13 ) ;
return V_21 ;
}
}
if ( V_14 ) {
V_21 = F_5 ( V_26 , V_14 ,
V_14 ) ;
if ( V_21 ) {
F_6 ( V_17 , L_1 ,
V_14 ) ;
return V_21 ;
}
}
V_4 -> V_27 ( V_20 , V_19 ) ;
if ( ( V_9 < V_18 ) ||
( ( V_9 > V_18 ) && V_14 ) ) {
V_21 = F_5 ( V_26 , V_13 ,
V_13 ) ;
if ( V_21 ) {
F_6 ( V_17 , L_1 ,
V_13 ) ;
goto V_23;
}
}
V_23:
F_7 ( V_12 ) ;
return V_21 ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_19 )
{
return F_3 ( V_4 -> V_3 [ V_19 ] . V_6 ) ;
}
static int F_9 ( struct V_11 * V_12 )
{
V_12 -> V_28 = V_4 -> V_29 ;
V_12 -> V_30 = V_31 ;
return F_10 ( V_12 , V_4 -> V_3 , 100000 ) ;
}
static int F_11 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
int V_21 = - V_8 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return - V_37 ;
V_4 -> V_17 = & V_33 -> V_17 ;
if ( F_13 ( L_2 ) ) {
V_4 -> type = V_38 ;
V_21 = F_14 ( V_4 ) ;
} else if ( F_13 ( L_3 ) ) {
V_4 -> type = V_39 ;
V_21 = F_14 ( V_4 ) ;
} else if ( F_13 ( L_4 ) ) {
V_4 -> type = V_40 ;
V_21 = F_15 ( V_4 ) ;
} else {
F_16 ( L_5 , V_41 ) ;
V_21 = - V_42 ;
}
if ( V_21 )
goto V_43;
if ( V_4 -> V_27 == NULL ) {
F_6 ( & V_33 -> V_17 , L_6 ) ;
V_21 = - V_8 ;
goto V_43;
}
V_26 = F_17 ( NULL , L_7 ) ;
if ( F_18 ( V_26 ) ) {
F_6 ( & V_33 -> V_17 , L_8 ) ;
V_21 = - V_8 ;
goto V_43;
}
V_31 = F_19 ( V_4 -> V_29 ) / 1000 ;
V_21 = F_20 ( & V_44 ) ;
if ( V_21 )
goto V_45;
V_35 = F_21 ( 0 , NULL ) ;
if ( ! V_35 ) {
F_16 ( L_9 ) ;
return 0 ;
}
if ( F_22 ( V_35 , L_10 , NULL ) ) {
V_46 = F_23 ( V_35 ,
V_47 ) ;
if ( F_18 ( V_46 ) )
F_16 ( L_11 ,
F_24 ( V_46 ) ) ;
}
return 0 ;
V_45:
F_6 ( & V_33 -> V_17 , L_12 ) ;
F_25 ( V_26 ) ;
V_43:
F_26 ( V_4 ) ;
return V_21 ;
}
