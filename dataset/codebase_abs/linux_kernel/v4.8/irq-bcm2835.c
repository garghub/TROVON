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
struct V_8 * V_20 ,
bool V_21 )
{
void T_3 * V_22 ;
int V_23 , V_24 , V_25 ;
V_22 = F_10 ( V_19 , 0 ) ;
if ( ! V_22 )
F_11 ( L_1 ,
V_19 -> V_26 ) ;
V_4 . V_27 = F_12 ( V_19 , F_8 ( V_15 , 0 ) ,
& V_28 , NULL ) ;
if ( ! V_4 . V_27 )
F_11 ( L_2 , V_19 -> V_26 ) ;
for ( V_24 = 0 ; V_24 < V_15 ; V_24 ++ ) {
V_4 . V_29 [ V_24 ] = V_22 + V_30 [ V_24 ] ;
V_4 . V_6 [ V_24 ] = V_22 + V_31 [ V_24 ] ;
V_4 . V_5 [ V_24 ] = V_22 + V_32 [ V_24 ] ;
for ( V_25 = 0 ; V_25 < V_33 [ V_24 ] ; V_25 ++ ) {
V_23 = F_13 ( V_4 . V_27 , F_8 ( V_24 , V_25 ) ) ;
F_14 ( V_23 <= 0 ) ;
F_15 ( V_23 , & V_34 ,
V_35 ) ;
F_16 ( V_23 ) ;
}
}
if ( V_21 ) {
int V_36 = F_17 ( V_19 , 0 ) ;
if ( ! V_36 ) {
F_11 ( L_3 ,
V_19 -> V_26 ) ;
}
F_18 ( V_36 , V_37 ) ;
} else {
F_19 ( V_38 ) ;
}
return 0 ;
}
static int T_2 F_20 ( struct V_8 * V_19 ,
struct V_8 * V_20 )
{
return F_9 ( V_19 , V_20 , false ) ;
}
static int T_2 F_21 ( struct V_8 * V_19 ,
struct V_8 * V_20 )
{
return F_9 ( V_19 , V_20 , true ) ;
}
static T_1 F_22 ( int V_39 )
{
T_1 V_40 = F_23 ( V_4 . V_29 [ V_39 ] ) ;
return F_8 ( V_39 , F_24 ( V_40 ) - 1 ) ;
}
static T_1 F_25 ( int V_39 , T_1 V_40 )
{
return F_8 ( V_39 , V_41 [ F_24 ( V_40 >> V_42 ) - 1 ] ) ;
}
static T_1 F_26 ( void )
{
T_1 V_40 = F_23 ( V_4 . V_29 [ 0 ] ) & V_43 ;
if ( V_40 == 0 )
return ~ 0 ;
else if ( V_40 & V_44 )
return F_8 ( 0 , F_24 ( V_40 & V_44 ) - 1 ) ;
else if ( V_40 & V_45 )
return F_25 ( 1 , V_40 & V_45 ) ;
else if ( V_40 & V_46 )
return F_25 ( 2 , V_40 & V_46 ) ;
else if ( V_40 & V_47 )
return F_22 ( 1 ) ;
else if ( V_40 & V_48 )
return F_22 ( 2 ) ;
else
F_27 () ;
}
static void T_4 V_38 (
struct V_49 * V_50 )
{
T_1 V_3 ;
while ( ( V_3 = F_26 () ) != ~ 0 )
F_28 ( V_4 . V_27 , V_3 , V_50 ) ;
}
static void V_37 ( struct V_51 * V_52 )
{
T_1 V_3 ;
while ( ( V_3 = F_26 () ) != ~ 0 )
F_29 ( F_30 ( V_4 . V_27 , V_3 ) ) ;
}
