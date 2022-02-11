static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 , * V_7 ;
int V_8 [ 4 ] , V_9 ;
int V_10 , V_11 , V_12 , V_13 ;
unsigned long V_14 ;
unsigned char V_15 ;
F_2 ( V_16 L_1 ) ;
F_2 ( V_16 L_2 , V_1 -> V_17 ) ;
F_2 ( V_16 L_3 , V_1 -> V_18 ) ;
if ( F_3 ( V_1 , V_3 , V_19 ) ) {
F_2 ( V_16 L_4 ) ;
if ( F_3 ( V_1 , V_3 , V_20 ) ) {
F_2 ( V_16 L_5 ) ;
F_2 ( V_16 L_6 ) ;
return - V_21 ;
}
F_4 ( V_1 , V_8 , & V_9 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
F_2 ( V_16 L_7 , V_10 , V_8 [ V_10 ] ) ;
F_2 ( V_16 L_8 , V_9 ) ;
F_2 ( V_16 L_6 ) ;
}
V_13 = F_5 ( V_1 , 10000 ) ;
V_5 = F_6 ( V_22 * sizeof( struct V_4 ) , V_23 ) ;
if ( ! V_5 ) {
F_2 ( V_16 L_9 ) ;
goto V_24;
}
V_6 = V_5 ;
V_12 = 0 ;
V_10 = 1 ;
F_7 ( V_14 ) ;
V_15 = F_8 ( V_1 ) ;
V_6 -> V_25 = V_15 ;
V_6 -> time = V_12 ;
V_6 ++ ;
F_9 ( V_1 ) ;
while ( V_10 < V_22 && V_12 < V_13 ) {
V_6 -> V_25 = F_8 ( V_1 ) ;
if ( V_6 -> V_25 ^ V_15 ) {
V_15 = V_6 -> V_25 ;
V_6 -> time = V_12 ;
V_10 ++ ;
V_6 ++ ;
}
V_12 ++ ;
}
F_10 ( V_14 ) ;
V_12 = V_10 ;
V_6 = V_5 ;
V_7 = V_6 ;
F_2 ( V_16 L_10 ) ;
F_2 ( V_16 L_11 , 0 , 0 ) ;
for ( V_11 = 7 ; V_11 >= 0 ; V_11 -- )
F_2 ( L_12 , ( V_6 -> V_25 >> V_11 ) & 1 ) ;
F_2 ( L_13 ) ;
V_6 ++ ;
for ( V_10 = 1 ; V_10 < V_12 ; V_10 ++ , V_6 ++ , V_7 ++ ) {
F_2 ( V_16 L_11 ,
V_10 , V_6 -> time - V_7 -> time ) ;
for ( V_11 = 7 ; V_11 >= 0 ; V_11 -- )
F_2 ( L_12 , ( V_6 -> V_25 >> V_11 ) & 1 ) ;
F_2 ( L_13 ) ;
}
F_11 ( V_5 ) ;
V_24:
F_2 ( V_16 L_6 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_13 ( V_1 ) ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_26 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_26 ) ;
}
