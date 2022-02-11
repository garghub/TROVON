static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != 0 )
return - V_4 ;
return F_2 ( V_2 , V_5 ) ;
}
static unsigned int F_3 ( unsigned int V_3 )
{
if ( V_3 != 0 )
return 0 ;
return F_4 ( V_6 ) / 1000 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned int V_8 )
{
int V_9 ;
unsigned int V_10 ;
struct V_11 V_12 ;
struct V_13 * V_14 ;
V_9 = F_6 ( V_2 , V_5 ,
V_7 , V_8 , & V_10 ) ;
if ( V_9 != 0 )
return V_9 ;
V_12 . V_15 = F_4 ( V_6 ) / 1000 ;
V_12 . V_16 = V_5 [ V_10 ] . V_17 ;
V_12 . V_18 = 0 ;
V_14 = & V_19 [ V_5 [ V_10 ] . V_20 ] ;
if ( V_12 . V_15 == V_12 . V_16 )
return 0 ;
F_7 ( L_1 , V_12 . V_15 , V_12 . V_16 ) ;
F_8 ( V_2 , & V_12 , V_21 ) ;
#ifdef F_9
if ( V_22 && V_12 . V_16 > V_12 . V_15 ) {
V_9 = F_10 ( V_22 ,
V_14 -> V_23 ,
V_14 -> V_24 ) ;
if ( V_9 != 0 ) {
F_11 ( L_2 ,
V_12 . V_16 , V_9 ) ;
goto V_25;
}
}
#endif
V_9 = F_12 ( V_6 , V_12 . V_16 * 1000 ) ;
if ( V_9 < 0 ) {
F_11 ( L_3 ,
V_12 . V_16 , V_9 ) ;
goto V_25;
}
F_8 ( V_2 , & V_12 , V_26 ) ;
#ifdef F_9
if ( V_22 && V_12 . V_16 < V_12 . V_15 ) {
V_9 = F_10 ( V_22 ,
V_14 -> V_23 ,
V_14 -> V_24 ) ;
if ( V_9 != 0 ) {
F_11 ( L_2 ,
V_12 . V_16 , V_9 ) ;
goto V_27;
}
}
#endif
F_7 ( L_4 ,
F_4 ( V_6 ) / 1000 ) ;
return 0 ;
V_27:
if ( F_12 ( V_6 , V_12 . V_15 * 1000 ) < 0 )
F_11 ( L_5 ) ;
V_25:
F_8 ( V_2 , & V_12 , V_26 ) ;
return V_9 ;
}
static void T_1 F_13 ( void )
{
int V_28 , V_29 , V_10 , V_30 ;
struct V_31 * V_32 ;
struct V_13 * V_14 ;
V_28 = F_14 ( V_22 ) ;
if ( V_28 < 0 ) {
F_11 ( L_6 ) ;
}
V_32 = V_5 ;
while ( V_28 > 0 && V_32 -> V_17 != V_33 ) {
if ( V_32 -> V_17 == V_34 )
continue;
V_14 = & V_19 [ V_32 -> V_20 ] ;
V_30 = 0 ;
for ( V_10 = 0 ; V_10 < V_28 ; V_10 ++ ) {
V_29 = F_15 ( V_22 , V_10 ) ;
if ( V_29 >= V_14 -> V_23 && V_29 <= V_14 -> V_24 )
V_30 = 1 ;
}
if ( ! V_30 ) {
F_7 ( L_7 ,
V_32 -> V_17 ) ;
V_32 -> V_17 = V_34 ;
}
V_32 ++ ;
}
V_35 = 1 * 1000 * 1000 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_31 * V_32 ;
if ( V_2 -> V_3 != 0 )
return - V_4 ;
if ( V_5 == NULL ) {
F_11 ( L_8 ) ;
return - V_36 ;
}
V_6 = F_17 ( NULL , L_9 ) ;
if ( F_18 ( V_6 ) ) {
F_11 ( L_10 ,
F_19 ( V_6 ) ) ;
return F_19 ( V_6 ) ;
}
#ifdef F_9
V_22 = F_20 ( NULL , L_11 ) ;
if ( F_18 ( V_22 ) ) {
V_9 = F_19 ( V_22 ) ;
F_11 ( L_12 , V_9 ) ;
F_11 ( L_13 ) ;
V_22 = NULL ;
} else {
F_13 () ;
}
#endif
V_32 = V_5 ;
while ( V_32 -> V_17 != V_33 ) {
unsigned long V_37 ;
V_37 = F_21 ( V_6 , V_32 -> V_17 * 1000 ) ;
V_37 /= 1000 ;
if ( V_37 != V_32 -> V_17 ) {
F_7 ( L_14 ,
V_32 -> V_17 ) ;
V_32 -> V_17 = V_34 ;
}
if ( ! V_22 && V_32 -> V_17 > F_3 ( 0 ) )
V_32 -> V_17 = V_34 ;
V_32 ++ ;
}
V_2 -> V_38 = F_4 ( V_6 ) / 1000 ;
V_2 -> V_39 . V_40 = ( 500 * 1000 ) + V_35 ;
V_9 = F_22 ( V_2 , V_5 ) ;
if ( V_9 != 0 ) {
F_11 ( L_15 ,
V_9 ) ;
F_23 ( V_22 ) ;
F_24 ( V_6 ) ;
}
return V_9 ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_41 ) ;
}
