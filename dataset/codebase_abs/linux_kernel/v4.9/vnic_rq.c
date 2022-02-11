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
break;
} else if ( V_6 + 1 == F_5 ( V_7 ) ) {
V_4 -> V_19 = V_2 -> V_11 [ V_5 + 1 ] ;
} else {
V_4 -> V_19 = V_4 + 1 ;
V_4 ++ ;
}
}
}
V_2 -> V_20 = V_2 -> V_21 = V_2 -> V_11 [ 0 ] ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
unsigned int V_5 ;
V_23 = V_2 -> V_23 ;
F_7 ( V_23 , & V_2 -> V_8 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
if ( V_2 -> V_11 [ V_5 ] ) {
F_8 ( V_2 -> V_11 [ V_5 ] ) ;
V_2 -> V_11 [ V_5 ] = NULL ;
}
}
V_2 -> V_25 = NULL ;
}
int F_9 ( struct V_22 * V_23 , struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_9 , unsigned int V_18 )
{
int V_26 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_25 = F_10 ( V_23 , V_27 , V_14 ) ;
if ( ! V_2 -> V_25 ) {
F_11 ( V_23 , L_1 , V_14 ) ;
return - V_28 ;
}
F_12 ( V_2 ) ;
V_26 = F_13 ( V_23 , & V_2 -> V_8 , V_9 , V_18 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 ) {
F_6 ( V_2 ) ;
return V_26 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_29 ,
unsigned int V_30 , unsigned int V_31 ,
unsigned int V_32 ,
unsigned int V_33 )
{
T_1 V_34 ;
unsigned int V_7 = V_2 -> V_8 . V_9 ;
V_34 = ( T_1 ) V_2 -> V_8 . V_35 | V_36 ;
F_15 ( V_34 , & V_2 -> V_25 -> V_37 ) ;
F_16 ( V_7 , & V_2 -> V_25 -> V_38 ) ;
F_16 ( V_29 , & V_2 -> V_25 -> V_29 ) ;
F_16 ( V_32 , & V_2 -> V_25 -> V_32 ) ;
F_16 ( V_33 , & V_2 -> V_25 -> V_33 ) ;
F_16 ( 0 , & V_2 -> V_25 -> V_39 ) ;
F_16 ( 0 , & V_2 -> V_25 -> V_40 ) ;
F_16 ( V_30 , & V_2 -> V_25 -> V_30 ) ;
F_16 ( V_31 , & V_2 -> V_25 -> V_31 ) ;
V_2 -> V_20 = V_2 -> V_21 =
& V_2 -> V_11 [ V_30 / F_5 ( V_7 ) ]
[ V_30 % F_5 ( V_7 ) ] ;
}
void F_17 ( struct V_1 * V_2 , unsigned int V_29 ,
unsigned int V_32 ,
unsigned int V_33 )
{
T_2 V_30 = 0 ;
V_30 = F_18 ( & V_2 -> V_25 -> V_30 ) ;
if ( V_30 == 0xFFFFFFFF ) {
V_30 = 0 ;
}
F_14 ( V_2 , V_29 ,
V_30 , V_30 ,
V_32 ,
V_33 ) ;
}
unsigned int F_19 ( struct V_1 * V_2 )
{
return F_18 ( & V_2 -> V_25 -> V_40 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_16 ( 1 , & V_2 -> V_25 -> V_41 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
unsigned int V_42 ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 2 ; V_5 ++ ) {
F_16 ( 0 , & V_2 -> V_25 -> V_41 ) ;
for ( V_42 = 20000 ; V_42 > 0 ; V_42 -- )
if ( ! F_18 ( & V_2 -> V_25 -> V_43 ) )
break;
if ( ! V_42 ) {
F_21 ( V_23 , L_2 ,
V_2 -> V_14 ) ;
return - V_44 ;
}
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 ,
void (* F_23)( struct V_1 * V_2 , struct V_3 * V_4 ) )
{
struct V_3 * V_4 ;
T_2 V_30 ;
unsigned int V_7 = V_2 -> V_8 . V_9 ;
int V_5 ;
V_4 = V_2 -> V_21 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 . V_9 ; V_5 ++ ) {
(* F_23)( V_2 , V_4 ) ;
V_4 = V_4 -> V_19 ;
}
V_2 -> V_8 . V_45 = V_2 -> V_8 . V_9 - 1 ;
V_30 = F_18 ( & V_2 -> V_25 -> V_30 ) ;
if ( V_30 == 0xFFFFFFFF ) {
V_30 = 0 ;
}
V_2 -> V_20 = V_2 -> V_21 =
& V_2 -> V_11 [ V_30 / F_5 ( V_7 ) ]
[ V_30 % F_5 ( V_7 ) ] ;
F_16 ( V_30 , & V_2 -> V_25 -> V_31 ) ;
F_16 ( 0 , & V_2 -> V_25 -> V_41 ) ;
F_24 ( & V_2 -> V_8 ) ;
}
