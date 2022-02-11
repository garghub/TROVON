static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 , V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; V_7 ++ ) {
if ( V_3 >= V_2 -> V_9 [ 2 * V_7 + 1 ] )
break;
}
if ( V_7 == 0 ) {
V_4 = V_2 -> V_9 [ 0 ] ;
} else if ( V_7 >= ( V_2 -> V_8 - 1 ) ) {
V_4 = V_2 -> V_9 [ 2 * ( V_2 -> V_8 - 1 ) ] ;
} else {
V_5 = V_2 -> V_9 [ 2 * V_7 - 1 ] ;
V_6 = V_2 -> V_9 [ 2 * V_7 + 1 ] ;
V_4 = V_2 -> V_9 [ 2 * V_7 ] ;
V_4 -= ( ( V_3 - V_6 ) * 1000 ) / ( V_5 - V_6 ) ;
}
return V_4 ;
}
static int F_2 ( void * V_10 , int * V_4 )
{
struct V_1 * V_2 = V_10 ;
int V_3 ;
int V_11 ;
V_11 = F_3 ( V_2 -> V_12 , & V_3 ) ;
if ( V_11 < 0 ) {
F_4 ( V_2 -> V_13 , L_1 , V_11 ) ;
return V_11 ;
}
* V_4 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_14 * V_13 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_18 ;
int V_11 ;
V_18 = F_6 ( V_16 , L_2 ,
sizeof( V_19 ) ) ;
if ( V_18 < 0 ) {
F_4 ( V_13 , L_3 ) ;
return V_18 ;
}
if ( V_18 % 2 ) {
F_4 ( V_13 , L_4 ) ;
return - V_20 ;
}
V_2 -> V_9 = F_7 ( V_13 , sizeof( * V_2 -> V_9 ) *
V_18 , V_21 ) ;
if ( ! V_2 -> V_9 )
return - V_22 ;
V_11 = F_8 ( V_16 , L_2 ,
( V_19 * ) V_2 -> V_9 , V_18 ) ;
if ( V_11 < 0 ) {
F_4 ( V_13 , L_5 ,
V_11 ) ;
return V_11 ;
}
V_2 -> V_8 = V_18 / 2 ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ! V_24 -> V_13 . V_17 ) {
F_4 ( & V_24 -> V_13 , L_6 ) ;
return - V_25 ;
}
V_2 = F_7 ( & V_24 -> V_13 , sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_22 ;
V_11 = F_5 ( & V_24 -> V_13 , V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_13 = & V_24 -> V_13 ;
F_10 ( V_24 , V_2 ) ;
V_2 -> V_12 = F_11 ( & V_24 -> V_13 , L_7 ) ;
if ( F_12 ( V_2 -> V_12 ) ) {
V_11 = F_13 ( V_2 -> V_12 ) ;
F_4 ( & V_24 -> V_13 , L_8 , V_11 ) ;
return V_11 ;
}
V_2 -> V_26 = F_14 ( & V_24 -> V_13 , 0 ,
V_2 , & V_27 ) ;
if ( F_12 ( V_2 -> V_26 ) ) {
V_11 = F_13 ( V_2 -> V_26 ) ;
F_4 ( & V_24 -> V_13 , L_9 ,
V_11 ) ;
goto V_28;
}
return 0 ;
V_28:
F_15 ( V_2 -> V_12 ) ;
return V_11 ;
}
static int F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_17 ( V_24 ) ;
F_18 ( & V_24 -> V_13 , V_2 -> V_26 ) ;
F_15 ( V_2 -> V_12 ) ;
return 0 ;
}
