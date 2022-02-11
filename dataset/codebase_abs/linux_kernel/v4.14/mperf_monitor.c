static int F_1 ( unsigned long long * V_1 )
{
int V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_1 ) ;
if ( V_2 )
F_3 ( L_1 , * V_1 ) ;
return V_2 ;
}
static int F_4 ( unsigned int V_5 )
{
unsigned long long V_6 ;
int V_2 ;
V_2 = F_2 ( V_5 , V_7 , & V_6 ) ;
V_8 [ V_5 ] = V_6 ;
V_2 |= F_2 ( V_5 , V_9 , & V_6 ) ;
V_10 [ V_5 ] = V_6 ;
V_11 [ V_5 ] = ! V_2 ;
return 0 ;
}
static int F_5 ( unsigned int V_5 )
{
unsigned long long V_6 ;
int V_2 ;
V_2 = F_2 ( V_5 , V_7 , & V_6 ) ;
V_12 [ V_5 ] = V_6 ;
V_2 |= F_2 ( V_5 , V_9 , & V_6 ) ;
V_13 [ V_5 ] = V_6 ;
V_11 [ V_5 ] = ! V_2 ;
return 0 ;
}
static int F_6 ( unsigned int V_14 , double * V_15 ,
unsigned int V_5 )
{
unsigned long long V_16 , V_17 , V_18 ;
unsigned long long V_19 ;
if ( ! V_11 [ V_5 ] )
return - 1 ;
if ( V_14 != V_20 && V_14 != V_21 )
return - 1 ;
V_17 = V_13 [ V_5 ] - V_10 [ V_5 ] ;
V_16 = V_12 [ V_5 ] - V_8 [ V_5 ] ;
if ( V_22 == V_23 ) {
V_18 = V_24 - V_25 ;
* V_15 = 100.0 * V_17 / V_18 ;
F_3 ( L_2 ,
V_26 [ V_14 ] . V_27 , V_17 , V_18 ) ;
} else if ( V_22 == V_28 ) {
V_19 = V_29 * F_7 ( V_30 , V_31 ) ;
* V_15 = 100.0 * V_17 / V_19 ;
F_3 ( L_3 ,
V_26 [ V_14 ] . V_27 , V_17 , V_19 ) ;
} else
return - 1 ;
if ( V_14 == V_21 )
* V_15 = 100.0 - * V_15 ;
F_3 ( L_4 ,
V_26 [ V_14 ] . V_27 , V_17 , V_16 , V_5 ) ;
F_3 ( L_5 , V_26 [ V_14 ] . V_27 , * V_15 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_14 , unsigned long long * V_32 ,
unsigned int V_5 )
{
unsigned long long V_16 , V_17 , V_33 , V_18 ;
if ( V_14 != V_34 )
return 1 ;
if ( ! V_11 [ V_5 ] )
return - 1 ;
V_17 = V_13 [ V_5 ] - V_10 [ V_5 ] ;
V_16 = V_12 [ V_5 ] - V_8 [ V_5 ] ;
if ( V_22 == V_23 ) {
V_18 = V_24 - V_25 ;
V_33 = F_7 ( V_30 , V_31 ) ;
V_29 = V_18 / V_33 ;
}
* V_32 = V_29 * ( ( double ) V_16 / V_17 ) ;
F_3 ( L_6 ,
V_26 [ V_14 ] . V_27 ,
( V_22 == V_23 ) ? L_7 : L_8 ) ;
F_3 ( L_9 , V_29 ) ;
F_3 ( L_10 , V_16 ) ;
F_3 ( L_11 , V_17 ) ;
F_3 ( L_12 , * V_32 ) ;
return 0 ;
}
static int F_9 ( void )
{
int V_5 ;
unsigned long long V_35 ;
F_10 ( V_36 , & V_30 ) ;
F_1 ( & V_25 ) ;
for ( V_5 = 0 ; V_5 < V_37 ; V_5 ++ )
F_4 ( V_5 ) ;
F_1 ( & V_35 ) ;
F_3 ( L_13 , V_35 - V_25 ) ;
return 0 ;
}
static int F_11 ( void )
{
unsigned long long V_35 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_37 ; V_5 ++ )
F_5 ( V_5 ) ;
F_1 ( & V_24 ) ;
F_10 ( V_36 , & V_31 ) ;
F_1 ( & V_35 ) ;
F_3 ( L_13 , V_35 - V_24 ) ;
return 0 ;
}
static int F_12 ( void )
{
int V_2 ;
unsigned long long V_38 ;
unsigned long V_39 ;
if ( ! ( V_40 . V_41 & V_42 ) )
goto V_43;
if ( V_40 . V_44 == V_45 ) {
V_2 = F_2 ( 0 , V_46 , & V_38 ) ;
if ( V_2 != 0 ) {
F_3 ( L_14 ,
V_46 ) ;
return 0 ;
} else if ( 1 & ( V_38 >> 24 ) ) {
V_22 = V_23 ;
return 0 ;
} else { }
} else if ( V_40 . V_44 == V_47 ) {
V_22 = V_23 ;
return 0 ;
}
V_43:
if ( F_13 ( 0 , & V_39 , & V_29 ) ) {
F_3 ( L_15
L_16 ) ;
return - 1 ;
}
V_22 = V_28 ;
V_29 /= 1000 ;
return 0 ;
}
struct V_48 * F_14 ( void )
{
if ( ! ( V_40 . V_41 & V_49 ) )
return NULL ;
if ( F_12 () )
return NULL ;
V_11 = calloc ( V_37 , sizeof( int ) ) ;
V_10 = calloc ( V_37 , sizeof( unsigned long long ) ) ;
V_8 = calloc ( V_37 , sizeof( unsigned long long ) ) ;
V_13 = calloc ( V_37 , sizeof( unsigned long long ) ) ;
V_12 = calloc ( V_37 , sizeof( unsigned long long ) ) ;
V_50 . V_51 = strlen ( V_50 . V_27 ) ;
return & V_50 ;
}
void F_15 ( void )
{
free ( V_10 ) ;
free ( V_8 ) ;
free ( V_13 ) ;
free ( V_12 ) ;
free ( V_11 ) ;
}
