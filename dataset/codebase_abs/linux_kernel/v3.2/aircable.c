static int F_1 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
int V_5 ;
unsigned char * V_6 = V_3 ;
V_5 = F_2 ( & V_2 -> V_7 , V_6 + V_8 ,
V_4 - V_8 , & V_2 -> V_9 ) ;
V_6 [ 0 ] = V_10 ;
V_6 [ 1 ] = V_11 ;
F_3 ( V_5 , & V_6 [ 2 ] ) ;
return V_5 + V_8 ;
}
static int F_4 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_18 ->
V_19 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_17 -> V_24 . V_25 ; V_23 ++ ) {
V_21 = & V_17 -> V_21 [ V_23 ] . V_24 ;
if ( F_5 ( V_21 ) ) {
F_6 ( L_1 , V_23 ) ;
++ V_22 ;
}
}
if ( V_22 == 0 ) {
F_6 ( L_2 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_7 ( struct V_27 * V_28 ,
struct V_1 * V_2 , int V_29 ,
char * V_30 , int V_31 )
{
if ( V_29 ) {
V_31 -= V_8 ;
V_30 += V_8 ;
}
if ( V_31 <= 0 ) {
F_6 ( L_3 , V_32 ) ;
return 0 ;
}
F_8 ( V_28 , V_30 , V_31 ) ;
return V_31 ;
}
static void F_9 ( struct V_33 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
char * V_35 = ( char * ) V_33 -> V_36 ;
struct V_27 * V_28 ;
int V_29 ;
int V_5 ;
int V_31 ;
int V_23 ;
V_28 = F_10 ( & V_2 -> V_2 ) ;
if ( ! V_28 )
return;
V_29 = ( V_33 -> V_37 > 2 && V_35 [ 0 ] == V_38 ) ;
V_5 = 0 ;
for ( V_23 = 0 ; V_23 < V_33 -> V_37 ; V_23 += V_39 ) {
V_31 = F_11 ( int , V_33 -> V_37 - V_23 , V_39 ) ;
V_5 += F_7 ( V_28 , V_2 , V_29 ,
& V_35 [ V_23 ] , V_31 ) ;
}
if ( V_5 )
F_12 ( V_28 ) ;
F_13 ( V_28 ) ;
}
static int T_2 F_14 ( void )
{
int V_40 ;
V_40 = F_15 ( & V_41 ) ;
if ( V_40 )
goto V_42;
V_40 = F_16 ( & V_43 ) ;
if ( V_40 )
goto V_44;
return 0 ;
V_44:
F_17 ( & V_41 ) ;
V_42:
return V_40 ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_43 ) ;
F_17 ( & V_41 ) ;
}
