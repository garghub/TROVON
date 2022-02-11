static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 ;
unsigned int V_6 , V_7 ;
int V_8 ;
V_6 = F_2 ( V_2 -> V_9 ) / 1000 ;
V_7 = V_10 [ V_3 ] . V_11 ;
V_5 = & V_12 [ V_10 [ V_3 ] . V_13 ] ;
#ifdef F_3
if ( V_14 && V_7 > V_6 ) {
V_8 = F_4 ( V_14 ,
V_5 -> V_15 ,
V_5 -> V_16 ) ;
if ( V_8 != 0 ) {
F_5 ( L_1 ,
V_7 , V_8 ) ;
return V_8 ;
}
}
#endif
V_8 = F_6 ( V_2 -> V_9 , V_7 * 1000 ) ;
if ( V_8 < 0 ) {
F_5 ( L_2 ,
V_7 , V_8 ) ;
return V_8 ;
}
#ifdef F_3
if ( V_14 && V_7 < V_6 ) {
V_8 = F_4 ( V_14 ,
V_5 -> V_15 ,
V_5 -> V_16 ) ;
if ( V_8 != 0 ) {
F_5 ( L_1 ,
V_7 , V_8 ) ;
if ( F_6 ( V_2 -> V_9 , V_6 * 1000 ) < 0 )
F_5 ( L_3 ) ;
return V_8 ;
}
}
#endif
F_7 ( L_4 ,
F_2 ( V_2 -> V_9 ) / 1000 ) ;
return 0 ;
}
static void T_1 F_8 ( void )
{
int V_17 , V_18 , V_19 , V_20 ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
V_17 = F_9 ( V_14 ) ;
if ( V_17 < 0 ) {
F_5 ( L_5 ) ;
}
V_22 = V_10 ;
while ( V_17 > 0 && V_22 -> V_11 != V_23 ) {
if ( V_22 -> V_11 == V_24 )
continue;
V_5 = & V_12 [ V_22 -> V_13 ] ;
V_20 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
V_18 = F_10 ( V_14 , V_19 ) ;
if ( V_18 >= V_5 -> V_15 && V_18 <= V_5 -> V_16 )
V_20 = 1 ;
}
if ( ! V_20 ) {
F_7 ( L_6 ,
V_22 -> V_11 ) ;
V_22 -> V_11 = V_24 ;
}
V_22 ++ ;
}
V_25 = 1 * 1000 * 1000 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_21 * V_22 ;
if ( V_2 -> V_26 != 0 )
return - V_27 ;
if ( V_10 == NULL ) {
F_5 ( L_7 ) ;
return - V_28 ;
}
V_2 -> V_9 = F_12 ( NULL , L_8 ) ;
if ( F_13 ( V_2 -> V_9 ) ) {
F_5 ( L_9 ,
F_14 ( V_2 -> V_9 ) ) ;
return F_14 ( V_2 -> V_9 ) ;
}
#ifdef F_3
V_14 = F_15 ( NULL , L_10 ) ;
if ( F_13 ( V_14 ) ) {
V_8 = F_14 ( V_14 ) ;
F_5 ( L_11 , V_8 ) ;
F_5 ( L_12 ) ;
V_14 = NULL ;
} else {
F_8 () ;
}
#endif
V_22 = V_10 ;
while ( V_22 -> V_11 != V_23 ) {
unsigned long V_29 ;
V_29 = F_16 ( V_2 -> V_9 , V_22 -> V_11 * 1000 ) ;
V_29 /= 1000 ;
if ( V_29 != V_22 -> V_11 ) {
F_7 ( L_13 ,
V_22 -> V_11 ) ;
V_22 -> V_11 = V_24 ;
}
if ( ! V_14 && V_22 -> V_11 > F_2 ( V_2 -> V_9 ) / 1000 )
V_22 -> V_11 = V_24 ;
V_22 ++ ;
}
V_8 = F_17 ( V_2 , V_10 ,
( 500 * 1000 ) + V_25 ) ;
if ( V_8 != 0 ) {
F_5 ( L_14 ,
V_8 ) ;
F_18 ( V_14 ) ;
F_19 ( V_2 -> V_9 ) ;
}
return V_8 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_30 ) ;
}
