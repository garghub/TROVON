static inline int
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , unsigned int V_5 )
{
unsigned int V_6 ;
int V_7 ;
T_3 * V_8 = ( T_3 * ) V_4 ;
V_7 = F_2 ( V_2 -> V_9 , V_10 ,
V_11 + V_3 ,
V_8 , V_5 , 0 ) ;
if ( V_7 < 0 )
goto V_12;
for ( V_6 = 0 ; V_6 < V_5 / sizeof( T_2 ) ; V_6 ++ )
V_4 [ V_6 ] = F_3 ( V_8 [ V_6 ] ) ;
V_12:
return V_7 ;
}
static inline int
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_13 )
{
int V_7 ;
T_3 V_8 ;
V_7 = F_2 ( V_2 -> V_9 , V_14 ,
V_11 + V_3 ,
& V_8 , sizeof( T_3 ) , 0 ) ;
if ( V_7 < 0 )
goto V_12;
* V_13 = F_3 ( V_8 ) ;
V_12:
return V_7 ;
}
static inline int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_13 )
{
T_3 V_15 = F_6 ( V_13 ) ;
return F_2 ( V_2 -> V_9 , V_16 ,
V_11 + V_3 ,
& V_15 , sizeof( T_3 ) , 0 ) ;
}
static int
F_7 ( struct V_1 * V_2 , unsigned int * V_17 )
{
T_2 V_18 ;
int V_7 ;
V_7 = F_4 ( V_2 , V_19 , & V_18 ) ;
if ( V_7 < 0 )
goto V_12;
if ( V_18 >= F_8 ( V_20 ) )
V_7 = - V_21 ;
else
* V_17 = V_20 [ V_18 ] ;
V_12:
return V_7 ;
}
static int
F_9 ( struct V_1 * V_2 , unsigned int V_17 )
{
T_2 V_18 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_20 ) ; V_18 ++ ) {
if ( V_20 [ V_18 ] == V_17 )
break;
}
if ( V_18 == F_8 ( V_20 ) )
return - V_22 ;
return F_5 ( V_2 , V_19 , V_18 ) ;
}
static int
F_10 ( struct V_1 * V_2 , unsigned int * V_18 )
{
int V_7 ;
T_2 V_13 ;
V_7 = F_4 ( V_2 , V_23 , & V_13 ) ;
if ( V_7 < 0 )
goto V_12;
if ( V_2 -> V_24 -> clock -> V_25 == V_26 ) {
if ( V_13 == V_27 )
* V_18 = 2 ;
else if ( V_13 == V_28 )
* V_18 = 1 ;
} else if ( V_13 > 1 ) {
* V_18 = V_13 - 1 ;
}
V_12:
return V_7 ;
}
static int
F_11 ( struct V_1 * V_2 , unsigned int * V_18 )
{
int V_7 ;
T_2 V_13 ;
V_7 = F_4 ( V_2 , V_29 , & V_13 ) ;
if ( V_7 >= 0 )
* V_18 = 0xff & V_13 ;
return V_7 ;
}
static int
F_12 ( struct V_1 * V_2 , T_2 * V_4 , unsigned int V_5 )
{
struct V_30 * V_24 = V_2 -> V_24 -> V_31 ;
unsigned int V_32 ;
T_1 V_3 ;
int V_7 ;
if ( V_24 -> V_25 == V_33 )
V_3 = V_34 ;
else
V_3 = V_35 ;
V_32 = V_24 -> V_36 * 2 ;
if ( V_5 < V_32 * sizeof( T_2 ) )
return - V_21 ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_7 >= 0 && V_24 -> V_25 == V_33 ) {
F_13 ( V_4 [ 1 ] , V_4 [ 3 ] ) ;
F_13 ( V_4 [ 2 ] , V_4 [ 3 ] ) ;
F_13 ( V_4 [ 3 ] , V_4 [ 4 ] ) ;
F_13 ( V_4 [ 7 ] , V_4 [ 10 ] ) ;
F_13 ( V_4 [ 8 ] , V_4 [ 10 ] ) ;
F_13 ( V_4 [ 9 ] , V_4 [ 11 ] ) ;
F_13 ( V_4 [ 11 ] , V_4 [ 12 ] ) ;
F_13 ( V_4 [ 15 ] , V_4 [ 16 ] ) ;
}
return V_7 ;
}
