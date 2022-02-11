int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_1 , L_1 ) ;
F_3 ( V_1 , V_2 -> V_3 ) ;
F_2 ( V_1 , L_2 ) ;
if ( V_2 -> V_4 != NULL )
F_4 ( V_1 , V_2 -> V_4 ) ;
else
F_2 ( V_1 , L_3 ) ;
return 1 ;
}
int F_3 ( T_1 * V_1 , T_3 * V_2 )
{
static const char * V_5 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9
} ;
static const struct V_6 V_7 [] = {
{ V_8 ,
L_10 } ,
{ V_9 ,
L_11 } ,
{ V_10 ,
L_12 } ,
{ V_11 ,
L_13 } ,
{ V_12 ,
L_14 } ,
{ V_13 ,
L_15 } ,
{ V_14 ,
L_16
L_17 } ,
{ V_15 ,
L_18 } ,
{ - 1 , NULL }
} ;
long V_16 ;
int V_17 , V_18 = 0 ;
F_2 ( V_1 , L_19 ) ;
V_16 = F_5 ( V_2 -> V_16 ) ;
if ( 0 <= V_16 && V_16 < ( long ) F_6 ( V_5 ) )
F_2 ( V_1 , L_20 , V_5 [ V_16 ] ) ;
else
F_2 ( V_1 , L_21 ) ;
F_2 ( V_1 , L_22 ) ;
for ( V_17 = 0 ; V_17 < F_7 ( V_2 -> V_19 ) ; ++ V_17 ) {
if ( V_17 > 0 )
F_8 ( V_1 , L_23 ) ;
F_9 ( V_1 , F_10 ( V_2 -> V_19 , V_17 ) , 0 ) ;
F_8 ( V_1 , L_24 ) ;
}
if ( V_17 == 0 )
F_2 ( V_1 , L_25 ) ;
F_2 ( V_1 , L_26 ) ;
if ( V_2 -> V_20 != NULL )
V_18 = F_11 ( V_1 , V_7 , V_2 -> V_20 ) ;
if ( V_18 == 0 )
F_2 ( V_1 , L_27 ) ;
F_2 ( V_1 , L_24 ) ;
return 1 ;
}
static int F_11 ( T_1 * V_1 , const struct V_6 * V_2 ,
const T_4 * V_21 )
{
int V_18 = 0 ;
for (; V_2 -> V_22 >= 0 ; ++ V_2 ) {
if ( F_12 ( V_21 , V_2 -> V_22 ) ) {
if ( ++ V_18 > 1 )
F_2 ( V_1 , L_28 ) ;
F_2 ( V_1 , L_29 , V_2 -> V_19 ) ;
}
}
return V_18 ;
}
int F_4 ( T_1 * V_1 , T_5 * V_2 )
{
int V_21 ;
if ( V_2 == NULL )
return 0 ;
V_21 = F_5 ( V_2 -> V_23 ) ;
F_2 ( V_1 , L_30 , V_21 ) ;
F_2 ( V_1 , L_31 ) ;
F_13 ( V_1 , V_2 -> V_24 ) ;
F_14 ( V_1 , V_2 -> V_25 ) ;
F_2 ( V_1 , L_32 ) ;
if ( V_2 -> V_26 == NULL )
F_2 ( V_1 , L_27 ) ;
else
F_15 ( V_1 , V_2 -> V_26 ) ;
F_16 ( V_1 , L_24 , 1 ) ;
F_2 ( V_1 , L_33 ) ;
F_17 ( V_1 , V_2 -> time ) ;
F_16 ( V_1 , L_24 , 1 ) ;
F_2 ( V_1 , L_34 ) ;
if ( V_2 -> V_27 == NULL )
F_2 ( V_1 , L_27 ) ;
else
F_18 ( V_1 , V_2 -> V_27 ) ;
F_16 ( V_1 , L_24 , 1 ) ;
F_2 ( V_1 , L_35 , V_2 -> V_28 ? L_36 : L_37 ) ;
F_2 ( V_1 , L_38 ) ;
if ( V_2 -> V_29 == NULL )
F_2 ( V_1 , L_27 ) ;
else
F_15 ( V_1 , V_2 -> V_29 ) ;
F_16 ( V_1 , L_24 , 1 ) ;
F_2 ( V_1 , L_39 ) ;
if ( V_2 -> V_30 == NULL )
F_2 ( V_1 , L_27 ) ;
else {
F_19 ( V_31 ) * V_32 ;
if ( ( V_32 = F_20 ( NULL , V_2 -> V_30 , NULL ) ) )
F_21 ( V_1 , V_32 , 0 , 0 ) ;
F_22 ( V_32 , V_33 ) ;
}
F_16 ( V_1 , L_24 , 1 ) ;
F_23 ( V_1 , V_2 -> V_34 ) ;
return 1 ;
}
static int F_18 ( T_1 * V_1 , const T_6 * V_2 )
{
if ( V_2 -> V_35 != NULL )
F_15 ( V_1 , V_2 -> V_35 ) ;
else
F_2 ( V_1 , L_27 ) ;
F_2 ( V_1 , L_40 ) ;
if ( V_2 -> V_36 != NULL )
F_15 ( V_1 , V_2 -> V_36 ) ;
else
F_2 ( V_1 , L_27 ) ;
F_2 ( V_1 , L_41 ) ;
if ( V_2 -> V_37 != NULL )
F_15 ( V_1 , V_2 -> V_37 ) ;
else
F_2 ( V_1 , L_27 ) ;
F_2 ( V_1 , L_42 ) ;
return 1 ;
}
