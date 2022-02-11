static int F_1 ( unsigned long long * V_1 )
{
int V_2 ;
V_2 = F_2 ( 0 , V_3 , V_1 ) ;
if ( V_2 )
F_3 ( L_1 , * V_1 ) ;
return V_2 ;
}
static int F_4 ( unsigned int V_4 )
{
unsigned long long V_5 ;
int V_2 ;
V_2 = F_2 ( V_4 , V_6 , & V_5 ) ;
V_7 [ V_4 ] = V_5 ;
V_2 |= F_2 ( V_4 , V_8 , & V_5 ) ;
V_9 [ V_4 ] = V_5 ;
V_10 [ V_4 ] = ! V_2 ;
return 0 ;
}
static int F_5 ( unsigned int V_4 )
{
unsigned long long V_5 ;
int V_2 ;
V_2 = F_2 ( V_4 , V_6 , & V_5 ) ;
V_11 [ V_4 ] = V_5 ;
V_2 |= F_2 ( V_4 , V_8 , & V_5 ) ;
V_12 [ V_4 ] = V_5 ;
V_10 [ V_4 ] = ! V_2 ;
return 0 ;
}
static int F_6 ( unsigned int V_13 , double * V_14 ,
unsigned int V_4 )
{
unsigned long long V_15 , V_16 , V_17 ;
unsigned long long V_18 ;
if ( ! V_10 [ V_4 ] )
return - 1 ;
if ( V_13 != V_19 && V_13 != V_20 )
return - 1 ;
V_16 = V_12 [ V_4 ] - V_9 [ V_4 ] ;
V_15 = V_11 [ V_4 ] - V_7 [ V_4 ] ;
if ( V_21 == V_22 ) {
V_17 = V_23 - V_24 ;
* V_14 = 100.0 * V_16 / V_17 ;
F_3 ( L_2 ,
V_25 [ V_13 ] . V_26 , V_16 , V_17 ) ;
} else if ( V_21 == V_27 ) {
V_18 = V_28 * F_7 ( V_29 , V_30 ) ;
* V_14 = 100.0 * V_16 / V_18 ;
F_3 ( L_3 ,
V_25 [ V_13 ] . V_26 , V_16 , V_18 ) ;
} else
return - 1 ;
if ( V_13 == V_20 )
* V_14 = 100.0 - * V_14 ;
F_3 ( L_4 ,
V_25 [ V_13 ] . V_26 , V_16 , V_15 , V_4 ) ;
F_3 ( L_5 , V_25 [ V_13 ] . V_26 , * V_14 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_13 , unsigned long long * V_31 ,
unsigned int V_4 )
{
unsigned long long V_15 , V_16 , V_32 , V_17 ;
if ( V_13 != V_33 )
return 1 ;
if ( ! V_10 [ V_4 ] )
return - 1 ;
V_16 = V_12 [ V_4 ] - V_9 [ V_4 ] ;
V_15 = V_11 [ V_4 ] - V_7 [ V_4 ] ;
if ( V_21 == V_22 ) {
V_17 = V_23 - V_24 ;
V_32 = F_7 ( V_29 , V_30 ) ;
V_28 = V_17 / V_32 ;
}
* V_31 = V_28 * ( ( double ) V_15 / V_16 ) ;
F_3 ( L_6 ,
V_25 [ V_13 ] . V_26 ,
( V_21 == V_22 ) ? L_7 : L_8 ) ;
F_3 ( L_9 , V_28 ) ;
F_3 ( L_10 , V_15 ) ;
F_3 ( L_11 , V_16 ) ;
F_3 ( L_12 , * V_31 ) ;
return 0 ;
}
static int F_9 ( void )
{
int V_4 ;
unsigned long long V_34 ;
F_10 ( V_35 , & V_29 ) ;
F_1 ( & V_24 ) ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ )
F_4 ( V_4 ) ;
F_1 ( & V_34 ) ;
F_3 ( L_13 , V_34 - V_24 ) ;
return 0 ;
}
static int F_11 ( void )
{
unsigned long long V_34 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ )
F_5 ( V_4 ) ;
F_1 ( & V_23 ) ;
F_10 ( V_35 , & V_30 ) ;
F_1 ( & V_34 ) ;
F_3 ( L_13 , V_34 - V_23 ) ;
return 0 ;
}
static int F_12 ( void )
{
int V_2 ;
unsigned long long V_37 ;
unsigned long V_38 ;
if ( ! ( V_39 . V_40 & V_41 ) )
goto V_42;
if ( V_39 . V_43 == V_44 ) {
V_2 = F_2 ( 0 , V_45 , & V_37 ) ;
if ( V_2 != 0 ) {
F_3 ( L_14 ,
V_45 ) ;
return 0 ;
} else if ( 1 & ( V_37 >> 24 ) ) {
V_21 = V_22 ;
return 0 ;
} else { }
} else if ( V_39 . V_43 == V_46 ) {
V_21 = V_22 ;
return 0 ;
}
V_42:
if ( F_13 ( 0 , & V_38 , & V_28 ) ) {
F_3 ( L_15
L_16 ) ;
return - 1 ;
}
V_21 = V_27 ;
V_28 /= 1000 ;
return 0 ;
}
struct V_47 * F_14 ( void )
{
if ( ! ( V_39 . V_40 & V_48 ) )
return NULL ;
if ( F_12 () )
return NULL ;
V_10 = calloc ( V_36 , sizeof( int ) ) ;
V_9 = calloc ( V_36 , sizeof( unsigned long long ) ) ;
V_7 = calloc ( V_36 , sizeof( unsigned long long ) ) ;
V_12 = calloc ( V_36 , sizeof( unsigned long long ) ) ;
V_11 = calloc ( V_36 , sizeof( unsigned long long ) ) ;
V_49 . V_50 = strlen ( V_49 . V_26 ) ;
return & V_49 ;
}
void F_15 ( void )
{
free ( V_9 ) ;
free ( V_7 ) ;
free ( V_12 ) ;
free ( V_11 ) ;
free ( V_10 ) ;
}
