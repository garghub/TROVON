static unsigned int F_1 ( unsigned int V_1 )
{
if ( V_1 != 0 )
return 0 ;
return F_2 ( V_2 ) / 1000 ;
}
static int F_3 ( struct V_3 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 ;
unsigned int V_8 , V_9 ;
int V_10 ;
V_8 = F_2 ( V_2 ) / 1000 ;
V_9 = V_11 [ V_5 ] . V_12 ;
V_7 = & V_13 [ V_11 [ V_5 ] . V_14 ] ;
#ifdef F_4
if ( V_15 && V_9 > V_8 ) {
V_10 = F_5 ( V_15 ,
V_7 -> V_16 ,
V_7 -> V_17 ) ;
if ( V_10 != 0 ) {
F_6 ( L_1 ,
V_9 , V_10 ) ;
return V_10 ;
}
}
#endif
V_10 = F_7 ( V_2 , V_9 * 1000 ) ;
if ( V_10 < 0 ) {
F_6 ( L_2 ,
V_9 , V_10 ) ;
return V_10 ;
}
#ifdef F_4
if ( V_15 && V_9 < V_8 ) {
V_10 = F_5 ( V_15 ,
V_7 -> V_16 ,
V_7 -> V_17 ) ;
if ( V_10 != 0 ) {
F_6 ( L_1 ,
V_9 , V_10 ) ;
if ( F_7 ( V_2 , V_8 * 1000 ) < 0 )
F_6 ( L_3 ) ;
return V_10 ;
}
}
#endif
F_8 ( L_4 ,
F_2 ( V_2 ) / 1000 ) ;
return 0 ;
}
static void T_1 F_9 ( void )
{
int V_18 , V_19 , V_20 , V_21 ;
struct V_22 * V_23 ;
struct V_6 * V_7 ;
V_18 = F_10 ( V_15 ) ;
if ( V_18 < 0 ) {
F_6 ( L_5 ) ;
}
V_23 = V_11 ;
while ( V_18 > 0 && V_23 -> V_12 != V_24 ) {
if ( V_23 -> V_12 == V_25 )
continue;
V_7 = & V_13 [ V_23 -> V_14 ] ;
V_21 = 0 ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
V_19 = F_11 ( V_15 , V_20 ) ;
if ( V_19 >= V_7 -> V_16 && V_19 <= V_7 -> V_17 )
V_21 = 1 ;
}
if ( ! V_21 ) {
F_8 ( L_6 ,
V_23 -> V_12 ) ;
V_23 -> V_12 = V_25 ;
}
V_23 ++ ;
}
V_26 = 1 * 1000 * 1000 ;
}
static int F_12 ( struct V_3 * V_4 )
{
int V_10 ;
struct V_22 * V_23 ;
if ( V_4 -> V_1 != 0 )
return - V_27 ;
if ( V_11 == NULL ) {
F_6 ( L_7 ) ;
return - V_28 ;
}
V_2 = F_13 ( NULL , L_8 ) ;
if ( F_14 ( V_2 ) ) {
F_6 ( L_9 ,
F_15 ( V_2 ) ) ;
return F_15 ( V_2 ) ;
}
#ifdef F_4
V_15 = F_16 ( NULL , L_10 ) ;
if ( F_14 ( V_15 ) ) {
V_10 = F_15 ( V_15 ) ;
F_6 ( L_11 , V_10 ) ;
F_6 ( L_12 ) ;
V_15 = NULL ;
} else {
F_9 () ;
}
#endif
V_23 = V_11 ;
while ( V_23 -> V_12 != V_24 ) {
unsigned long V_29 ;
V_29 = F_17 ( V_2 , V_23 -> V_12 * 1000 ) ;
V_29 /= 1000 ;
if ( V_29 != V_23 -> V_12 ) {
F_8 ( L_13 ,
V_23 -> V_12 ) ;
V_23 -> V_12 = V_25 ;
}
if ( ! V_15 && V_23 -> V_12 > F_1 ( 0 ) )
V_23 -> V_12 = V_25 ;
V_23 ++ ;
}
V_10 = F_18 ( V_4 , V_11 ,
( 500 * 1000 ) + V_26 ) ;
if ( V_10 != 0 ) {
F_6 ( L_14 ,
V_10 ) ;
F_19 ( V_15 ) ;
F_20 ( V_2 ) ;
}
return V_10 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_30 ) ;
}
