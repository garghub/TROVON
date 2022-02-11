int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 , int V_8 )
{
int V_9 = 0 ;
T_1 * V_10 = V_2 -> V_11 ;
V_10 [ 0 ] = V_3 ;
if ( V_5 > 19 )
V_5 = 19 ;
if ( V_7 > 11 )
V_7 = 11 ;
V_9 = F_2 ( & V_2 -> V_12 ) ;
if ( V_9 )
return V_9 ;
if ( V_4 != NULL && V_5 > 0 )
memcpy ( & V_10 [ 1 ] , V_4 , V_5 ) ;
F_3 ( L_1 ) ;
F_4 ( V_10 , V_5 + 1 , F_3 ) ;
if ( F_5 ( V_2 -> V_13 ,
F_6 ( V_2 -> V_13 , 0 ) ,
V_14 , V_15 | V_16 , 0 , 0 ,
V_10 , 20 , 2000 ) != 20 ) {
F_7 ( L_2 ) ;
V_9 = - V_17 ;
goto V_18;
}
F_8 ( V_8 ) ;
if ( F_5 ( V_2 -> V_13 ,
F_9 ( V_2 -> V_13 , 0 ) ,
V_19 , V_15 | V_20 , 0 , 0 ,
V_10 , 12 , 2000 ) != 12 ) {
F_7 ( L_3 ) ;
V_9 = - V_17 ;
goto V_18;
}
F_3 ( L_4 ) ;
F_4 ( V_10 , 12 , F_3 ) ;
if ( V_6 != NULL && V_7 > 0 )
memcpy ( V_6 , & V_10 [ 1 ] , V_7 ) ;
V_18:
F_10 ( & V_2 -> V_12 ) ;
return V_9 ;
}
T_1 F_11 ( struct V_1 * V_2 , T_1 V_21 )
{
T_1 V_22 [ 2 ] = { 0 } , V_23 ;
V_22 [ 1 ] = V_21 ;
F_1 ( V_2 , V_24 , V_22 , 2 , & V_23 , 1 , 30 ) ;
return V_23 ;
}
static int F_12 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_23 = V_25 ;
return F_1 ( V_2 , V_26 , & V_23 , 1 , NULL , 0 , 150 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 * V_27 , int * V_28 )
{
T_1 V_29 ;
int V_30 ;
F_1 ( V_2 , V_31 , NULL , 0 , & V_29 , 1 , 20 ) ;
F_14 ( L_5 , V_29 , V_29 ) ;
if ( V_29 == 0x44 ) {
* V_28 = V_32 ;
return 0 ;
}
for ( V_30 = 0 ; V_30 < F_15 ( V_33 ) ; V_30 ++ )
if ( F_16 ( & V_33 [ V_30 ] ) == V_29 ) {
* V_28 = V_34 ;
* V_27 = V_33 [ V_30 ] . V_35 ;
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 * V_10 , int V_36 , int V_37 )
{
int V_30 = 0 ;
T_1 V_23 , V_38 [ 2 ] ;
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
V_23 = V_37 + V_30 ;
F_1 ( V_2 , V_39 , & V_23 , 1 , V_38 , 2 , 5 ) ;
V_10 [ V_30 ] = V_38 [ 1 ] ;
}
F_18 ( L_6 , V_37 , V_30 ) ;
F_4 ( V_10 , V_30 , F_18 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_40 [ 6 ] )
{
return F_17 ( V_2 , V_40 , 6 , V_41 ) ;
}
static int F_20 ( struct V_42 * V_43 )
{
T_1 V_10 [ 255 ] = { 0 } ;
F_1 ( V_43 -> V_44 , V_45 , NULL , 0 , V_10 , 20 , 0 ) ;
V_10 [ 10 ] = '\0' ;
F_18 ( L_7 , V_10 ) ;
F_1 ( V_43 -> V_44 , V_46 , NULL , 0 , V_10 , 20 , 0 ) ;
V_10 [ 10 ] = '\0' ;
F_18 ( L_8 , V_10 ) ;
F_1 ( V_43 -> V_44 , V_47 , NULL , 0 , V_10 , 20 , 0 ) ;
V_10 [ 10 ] = '\0' ;
F_18 ( L_9 , V_10 ) ;
V_43 -> V_48 [ 0 ] . V_49 = F_21 ( V_43 -> V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
return F_23 ( V_51 , & V_54 ,
V_55 , NULL , V_56 ) ;
}
