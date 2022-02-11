static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 ) , V_4 . V_5 [ F_4 ( V_2 -> V_3 ) ] ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 ) , V_4 . V_6 [ F_4 ( V_2 -> V_3 ) ] ) ;
}
static int F_6 ( struct V_7 * V_2 , struct V_8 * V_9 ,
const T_1 * V_10 , unsigned int V_11 ,
unsigned long * V_12 , unsigned int * V_13 )
{
if ( F_7 ( V_11 != 2 ) )
return - V_14 ;
if ( F_7 ( V_10 [ 0 ] >= V_15 ) )
return - V_14 ;
if ( F_7 ( V_10 [ 1 ] >= V_16 ) )
return - V_14 ;
if ( F_7 ( V_10 [ 0 ] == 0 && V_10 [ 1 ] >= V_17 ) )
return - V_14 ;
* V_12 = F_8 ( V_10 [ 0 ] , V_10 [ 1 ] ) ;
* V_13 = V_18 ;
return 0 ;
}
static int T_2 F_9 ( struct V_8 * V_19 ,
struct V_8 * V_20 )
{
void T_3 * V_21 ;
int V_22 , V_23 , V_24 ;
V_21 = F_10 ( V_19 , 0 ) ;
if ( ! V_21 )
F_11 ( L_1 ,
V_19 -> V_25 ) ;
V_4 . V_26 = F_12 ( V_19 , F_8 ( V_15 , 0 ) ,
& V_27 , NULL ) ;
if ( ! V_4 . V_26 )
F_11 ( L_2 , V_19 -> V_25 ) ;
for ( V_23 = 0 ; V_23 < V_15 ; V_23 ++ ) {
V_4 . V_28 [ V_23 ] = V_21 + V_29 [ V_23 ] ;
V_4 . V_6 [ V_23 ] = V_21 + V_30 [ V_23 ] ;
V_4 . V_5 [ V_23 ] = V_21 + V_31 [ V_23 ] ;
for ( V_24 = 0 ; V_24 < V_32 [ V_23 ] ; V_24 ++ ) {
V_22 = F_13 ( V_4 . V_26 , F_8 ( V_23 , V_24 ) ) ;
F_14 ( V_22 <= 0 ) ;
F_15 ( V_22 , & V_33 ,
V_34 ) ;
F_16 ( V_22 , V_35 | V_36 ) ;
}
}
F_17 ( V_37 ) ;
return 0 ;
}
static void F_18 ( int V_38 , struct V_39 * V_40 )
{
T_1 V_41 , V_22 ;
while ( ( V_41 = F_19 ( V_4 . V_28 [ V_38 ] ) ) ) {
V_22 = F_8 ( V_38 , F_20 ( V_41 ) - 1 ) ;
F_21 ( F_22 ( V_4 . V_26 , V_22 ) , V_40 ) ;
}
}
static void F_23 ( int V_38 , struct V_39 * V_40 ,
T_1 V_41 )
{
T_1 V_22 = F_8 ( V_38 , V_42 [ F_20 ( V_41 >> V_43 ) - 1 ] ) ;
F_21 ( F_22 ( V_4 . V_26 , V_22 ) , V_40 ) ;
}
static void T_4 V_37 (
struct V_39 * V_40 )
{
T_1 V_41 , V_22 ;
while ( ( V_41 = F_19 ( V_4 . V_28 [ 0 ] ) & V_44 ) ) {
if ( V_41 & V_45 ) {
V_22 = F_8 ( 0 , F_20 ( V_41 & V_45 ) - 1 ) ;
F_21 ( F_22 ( V_4 . V_26 , V_22 ) , V_40 ) ;
} else if ( V_41 & V_46 ) {
F_23 ( 1 , V_40 , V_41 & V_46 ) ;
} else if ( V_41 & V_47 ) {
F_23 ( 2 , V_40 , V_41 & V_47 ) ;
} else if ( V_41 & V_48 ) {
F_18 ( 1 , V_40 ) ;
} else if ( V_41 & V_49 ) {
F_18 ( 2 , V_40 ) ;
} else {
F_24 () ;
}
}
}
