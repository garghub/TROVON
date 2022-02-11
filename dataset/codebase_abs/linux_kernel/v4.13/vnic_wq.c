static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 , V_6 , V_7 = V_2 -> V_8 . V_9 ;
unsigned int V_10 = F_2 ( V_7 ) ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
V_2 -> V_11 [ V_5 ] = F_3 ( F_4 ( V_7 ) , V_12 ) ;
if ( ! V_2 -> V_11 [ V_5 ] )
return - V_13 ;
}
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
V_4 = V_2 -> V_11 [ V_5 ] ;
for ( V_6 = 0 ; V_6 < F_5 ( V_7 ) ; V_6 ++ ) {
V_4 -> V_14 = V_5 * F_5 ( V_7 ) + V_6 ;
V_4 -> V_15 = ( V_16 * ) V_2 -> V_8 . V_17 +
V_2 -> V_8 . V_18 * V_4 -> V_14 ;
if ( V_4 -> V_14 + 1 == V_7 ) {
V_4 -> V_19 = V_2 -> V_11 [ 0 ] ;
V_4 -> V_19 -> V_20 = V_4 ;
break;
} else if ( V_6 + 1 == F_5 ( V_7 ) ) {
V_4 -> V_19 = V_2 -> V_11 [ V_5 + 1 ] ;
V_4 -> V_19 -> V_20 = V_4 ;
} else {
V_4 -> V_19 = V_4 + 1 ;
V_4 -> V_19 -> V_20 = V_4 ;
V_4 ++ ;
}
}
}
V_2 -> V_21 = V_2 -> V_22 = V_2 -> V_11 [ 0 ] ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
unsigned int V_5 ;
V_24 = V_2 -> V_24 ;
F_7 ( V_24 , & V_2 -> V_8 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
if ( V_2 -> V_11 [ V_5 ] ) {
F_8 ( V_2 -> V_11 [ V_5 ] ) ;
V_2 -> V_11 [ V_5 ] = NULL ;
}
}
V_2 -> V_26 = NULL ;
}
int F_9 ( struct V_23 * V_24 , struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_9 , unsigned int V_18 )
{
int V_27 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_26 = F_10 ( V_24 , V_28 , V_14 ) ;
if ( ! V_2 -> V_26 ) {
F_11 ( V_24 , L_1 , V_14 ) ;
return - V_29 ;
}
F_12 ( V_2 ) ;
V_27 = F_13 ( V_24 , & V_2 -> V_8 , V_9 , V_18 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_1 ( V_2 ) ;
if ( V_27 ) {
F_6 ( V_2 ) ;
return V_27 ;
}
return 0 ;
}
int F_14 ( struct V_23 * V_24 , struct V_1 * V_2 ,
unsigned int V_9 , unsigned int V_18 )
{
int V_27 ;
V_2 -> V_14 = 0 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_26 = F_10 ( V_24 , V_30 , 0 ) ;
if ( ! V_2 -> V_26 )
return - V_29 ;
F_12 ( V_2 ) ;
V_27 = F_13 ( V_24 , & V_2 -> V_8 , V_9 , V_18 ) ;
return V_27 ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int V_32 , unsigned int V_33 ,
unsigned int V_34 ,
unsigned int V_35 )
{
T_1 V_36 ;
unsigned int V_7 = V_2 -> V_8 . V_9 ;
V_36 = ( T_1 ) V_2 -> V_8 . V_37 | V_38 ;
F_16 ( V_36 , & V_2 -> V_26 -> V_39 ) ;
F_17 ( V_7 , & V_2 -> V_26 -> V_40 ) ;
F_17 ( V_32 , & V_2 -> V_26 -> V_32 ) ;
F_17 ( V_33 , & V_2 -> V_26 -> V_33 ) ;
F_17 ( V_31 , & V_2 -> V_26 -> V_31 ) ;
F_17 ( V_34 , & V_2 -> V_26 -> V_34 ) ;
F_17 ( V_35 , & V_2 -> V_26 -> V_35 ) ;
F_17 ( 0 , & V_2 -> V_26 -> V_41 ) ;
V_2 -> V_21 = V_2 -> V_22 =
& V_2 -> V_11 [ V_32 / F_5 ( V_7 ) ]
[ V_32 % F_5 ( V_7 ) ] ;
}
void F_18 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int V_34 ,
unsigned int V_35 )
{
F_15 ( V_2 , V_31 , 0 , 0 ,
V_34 ,
V_35 ) ;
}
unsigned int F_19 ( struct V_1 * V_2 )
{
return F_20 ( & V_2 -> V_26 -> V_41 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_17 ( 1 , & V_2 -> V_26 -> V_42 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
unsigned int V_43 ;
struct V_23 * V_24 = V_2 -> V_24 ;
F_17 ( 0 , & V_2 -> V_26 -> V_42 ) ;
for ( V_43 = 0 ; V_43 < 1000 ; V_43 ++ ) {
if ( ! ( F_20 ( & V_2 -> V_26 -> V_44 ) ) )
return 0 ;
F_22 ( 10 ) ;
}
F_23 ( V_24 , L_2 , V_2 -> V_14 ) ;
return - V_45 ;
}
void F_24 ( struct V_1 * V_2 ,
void (* F_25)( struct V_1 * V_2 , struct V_3 * V_4 ) )
{
struct V_3 * V_4 ;
V_4 = V_2 -> V_22 ;
while ( F_26 ( V_2 ) > 0 ) {
(* F_25)( V_2 , V_4 ) ;
V_4 = V_2 -> V_22 = V_4 -> V_19 ;
V_2 -> V_8 . V_46 ++ ;
}
V_2 -> V_21 = V_2 -> V_22 = V_2 -> V_11 [ 0 ] ;
F_17 ( 0 , & V_2 -> V_26 -> V_32 ) ;
F_17 ( 0 , & V_2 -> V_26 -> V_33 ) ;
F_17 ( 0 , & V_2 -> V_26 -> V_41 ) ;
F_27 ( & V_2 -> V_8 ) ;
}
