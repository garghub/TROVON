void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 () ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 -> V_4 , V_2 -> V_5 ) ;
F_5 ( V_2 -> V_4 , V_2 -> V_6 ) ;
F_6 ( V_2 -> V_4 , V_2 -> V_7 ) ;
F_7 ( V_2 -> V_4 ) ;
F_8 ( V_3 ) ;
}
unsigned int F_9 ( unsigned int V_8 )
{
unsigned long V_3 ;
unsigned int V_9 ;
V_3 = F_2 () ;
F_10 ( V_8 ) ;
V_9 = F_11 ( V_8 ) ;
F_8 ( V_3 ) ;
return V_9 ;
}
unsigned int F_12 ( unsigned int V_8 ,
unsigned int V_7 )
{
int V_10 = 0 ;
unsigned long V_3 ;
unsigned int V_9 ;
unsigned int V_11 ;
V_9 = F_9 ( V_8 ) ;
while ( V_9 % V_7 ) {
V_3 = F_2 () ;
F_7 ( V_8 ) ;
F_8 ( V_3 ) ;
F_13 ( 2 ) ;
V_11 = F_9 ( V_8 ) ;
if ( V_11 == V_9 ) {
V_10 ++ ;
if ( V_10 > 10 )
break;
} else {
V_9 = V_11 ;
V_10 = 0 ;
}
}
return V_9 ;
}
unsigned int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_2 [ V_13 -> V_14 ] ;
unsigned long V_3 ;
unsigned int V_15 ;
unsigned int V_16 ;
V_3 = F_2 () ;
F_3 ( V_2 -> V_4 ) ;
if ( ! V_17 )
F_10 ( V_2 -> V_4 ) ;
V_15 = F_11 ( V_2 -> V_4 ) ;
V_16 = F_11 ( V_2 -> V_4 ) ;
if ( ! V_17 )
F_7 ( V_2 -> V_4 ) ;
F_8 ( V_3 ) ;
if ( V_15 < V_16 )
V_15 = V_16 ;
if ( V_15 >= V_2 -> V_7 || V_15 == 0 )
return 0 ;
else
return V_2 -> V_7 - V_15 ;
}
void F_15 ( struct V_1 * V_2 , char V_18 )
{
V_2 -> V_5 = ( V_18 == V_19 ) ? V_20
: V_21 ;
}
struct V_12 * F_16 ( struct V_22 * V_23 ,
int V_24 , unsigned int V_25 ,
unsigned int V_26 ,
unsigned int V_27 , char V_18 )
{
struct V_12 * V_13 = NULL ;
struct V_1 * V_2 ;
unsigned int V_28 [ 2 ] ;
int V_29 ;
if ( V_24 < 1 || V_24 > 2 )
goto V_30;
V_13 = F_17 ( sizeof( * V_13 ) , V_31 ) ;
if ( ! V_13 )
goto V_30;
V_2 = F_18 ( V_24 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
goto V_30;
V_13 -> V_2 = V_2 ;
V_13 -> V_24 = V_24 ;
V_28 [ 0 ] = V_25 ;
if ( V_26 == 0 || V_26 == V_25 )
V_28 [ 1 ] = V_25 ;
else
V_28 [ 1 ] = V_26 ;
if ( F_19 ( V_28 [ 0 ] , V_23 -> V_32 ) )
goto V_30;
V_13 -> V_4 = V_28 [ 0 ] ;
if ( V_28 [ 1 ] != V_28 [ 0 ] ) {
if ( F_19 ( V_28 [ 1 ] , V_23 -> V_32 ) )
goto V_30;
}
V_13 -> V_33 = V_28 [ 1 ] ;
for ( V_29 = 0 ; V_29 < V_24 ; V_29 ++ ) {
V_2 = & V_13 -> V_2 [ V_29 ] ;
V_2 -> V_4 = V_28 [ V_29 ] ;
V_2 -> V_27 = V_27 ;
V_2 -> V_34 = F_20 ( NULL , V_2 -> V_27 ,
& V_2 -> V_6 ,
V_31 ) ;
if ( ! V_2 -> V_34 )
goto V_30;
F_15 ( V_2 , V_18 ) ;
}
return V_13 ;
V_30:
F_21 ( V_13 ) ;
return NULL ;
}
void F_21 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
int V_29 ;
if ( ! V_13 )
return;
if ( V_13 -> V_2 ) {
for ( V_29 = 0 ; V_29 < V_13 -> V_24 ; V_29 ++ ) {
V_2 = & V_13 -> V_2 [ V_29 ] ;
if ( V_2 -> V_34 )
F_22 ( NULL , V_2 -> V_27 ,
V_2 -> V_34 , V_2 -> V_6 ) ;
}
F_23 ( V_13 -> V_2 ) ;
}
if ( V_13 -> V_33 && V_13 -> V_33 != V_13 -> V_4 )
F_24 ( V_13 -> V_33 ) ;
if ( V_13 -> V_4 )
F_24 ( V_13 -> V_4 ) ;
F_23 ( V_13 ) ;
}
static int T_1 F_25 ( void )
{
return 0 ;
}
static void T_2 F_26 ( void )
{
}
