static unsigned int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
unsigned int V_4 , V_5 , V_6 ;
V_5 = V_7 - V_8 ;
while ( V_5 -- ) {
V_3 = V_9 [ V_1 ] ;
if ( V_3 -> V_10 . V_11 ) {
V_1 ++ ;
if ( V_1 > V_7 )
V_1 = V_8 ;
continue;
}
F_2 ( L_1 , V_1 , V_3 ) ;
V_3 -> V_10 . V_1 = V_12 ;
F_3 (cpu, mm_cpumask(mm)) {
for ( V_6 = F_4 ( V_4 ) ;
V_6 <= F_5 ( V_4 ) ; V_6 ++ ) {
if ( V_13 [ V_6 ] )
F_6 ( V_1 , V_13 [ V_6 ] ) ;
}
V_4 = V_6 - 1 ;
}
return V_1 ;
}
F_7 ( & V_14 ) ;
F_8 () ;
F_9 ( & V_14 ) ;
return V_12 ;
}
static unsigned int F_10 ( void )
{
struct V_2 * V_3 ;
int V_4 = F_11 () ;
unsigned int V_1 ;
for ( V_1 = V_8 ; V_1 <= V_7 ; V_1 ++ ) {
V_3 = V_9 [ V_1 ] ;
F_2 ( L_1 , V_1 , V_3 ) ;
V_3 -> V_10 . V_1 = V_12 ;
if ( V_1 != V_8 ) {
V_9 [ V_1 ] = NULL ;
F_12 ( V_1 , V_15 ) ;
#ifdef F_13
V_3 -> V_10 . V_11 = 0 ;
#endif
}
F_12 ( V_1 , V_13 [ V_4 ] ) ;
}
F_14 () ;
V_16 = V_7 - V_8 ;
return V_8 ;
}
static unsigned int F_15 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
int V_4 = F_11 () ;
V_3 = V_9 [ V_1 ] ;
F_2 ( L_1 , V_1 , V_3 ) ;
F_16 ( V_3 ) ;
V_3 -> V_10 . V_1 = V_12 ;
F_12 ( V_1 , V_13 [ V_4 ] ) ;
return V_1 ;
}
static void F_17 ( void )
{
unsigned int V_1 , V_17 , V_18 ;
V_17 = V_18 = 0 ;
for ( V_1 = V_8 ; V_1 <= V_7 ; V_1 ++ ) {
int V_19 = F_18 ( V_1 , V_15 ) ;
if ( ! V_19 )
V_17 ++ ;
if ( V_19 != ( V_9 [ V_1 ] != NULL ) )
F_19 ( L_2 ,
V_1 , V_19 ? L_3 : L_4 , V_9 [ V_1 ] ) ;
if ( V_9 [ V_1 ] != NULL )
V_18 += V_9 [ V_1 ] -> V_10 . V_11 ;
}
if ( V_17 != V_16 ) {
F_19 ( L_5 ,
V_16 , V_17 ) ;
V_16 = V_17 ;
}
if ( V_18 > F_20 () )
F_19 ( L_6 ,
V_18 , F_20 () ) ;
if ( V_8 > 0 && ! F_18 ( 0 , V_15 ) )
F_19 ( L_7 ) ;
}
static void F_17 ( void ) { }
void F_21 ( struct V_2 * V_20 , struct V_2 * V_21 ,
struct V_22 * V_23 )
{
unsigned int V_6 , V_1 , V_4 = F_11 () ;
unsigned long * V_24 ;
F_9 ( & V_14 ) ;
F_22 ( L_8 ,
V_4 , V_21 , V_21 -> V_10 . V_11 , V_21 -> V_10 . V_1 ) ;
#ifdef F_23
V_21 -> V_10 . V_11 ++ ;
if ( V_20 ) {
F_2 ( L_9 , V_20 , V_20 -> V_10 . V_11 ) ;
F_24 ( V_20 -> V_10 . V_11 < 1 ) ;
V_20 -> V_10 . V_11 -- ;
}
V_25:
#endif
V_1 = V_21 -> V_10 . V_1 ;
if ( F_25 ( V_1 != V_12 ) ) {
#ifdef F_13
if ( V_9 [ V_1 ] != V_21 )
F_19 ( L_10 ,
V_21 , V_1 , V_1 , V_9 [ V_1 ] ) ;
#endif
goto V_26;
}
V_1 = V_27 ;
if ( V_1 > V_7 )
V_1 = V_8 ;
V_24 = V_15 ;
if ( V_16 == 0 ) {
#ifdef F_23
if ( F_20 () > 1 ) {
V_1 = F_1 ( V_1 ) ;
if ( V_1 == V_12 )
goto V_25;
goto V_28;
}
#endif
if ( V_29 )
V_1 = F_10 () ;
else
V_1 = F_15 ( V_1 ) ;
goto V_28;
}
V_16 -- ;
while ( F_26 ( V_1 , V_24 ) ) {
V_1 = F_27 ( V_24 , V_7 + 1 , V_1 ) ;
if ( V_1 > V_7 )
V_1 = V_8 ;
}
V_28:
V_27 = V_1 + 1 ;
V_9 [ V_1 ] = V_21 ;
V_21 -> V_10 . V_1 = V_1 ;
F_2 ( L_11 , V_1 , V_16 ) ;
F_17 () ;
V_26:
if ( F_18 ( V_1 , V_13 [ V_4 ] ) ) {
F_2 ( L_12 ,
V_1 , F_4 ( V_4 ) ,
F_5 ( V_4 ) ) ;
F_16 ( V_21 ) ;
for ( V_6 = F_4 ( V_4 ) ;
V_6 <= F_5 ( V_4 ) ; V_6 ++ ) {
if ( V_13 [ V_6 ] )
F_12 ( V_1 , V_13 [ V_6 ] ) ;
}
}
F_2 ( L_13 , V_1 ) ;
F_28 ( V_1 , V_21 -> V_30 ) ;
F_7 ( & V_14 ) ;
}
int F_29 ( struct V_22 * V_31 , struct V_2 * V_3 )
{
F_22 ( L_14 , V_3 ) ;
V_3 -> V_10 . V_1 = V_12 ;
V_3 -> V_10 . V_11 = 0 ;
#ifdef F_30
F_31 ( V_3 , V_32 ) ;
#endif
return 0 ;
}
void F_32 ( struct V_2 * V_3 )
{
unsigned long V_33 ;
unsigned int V_1 ;
if ( V_3 -> V_10 . V_1 == V_12 )
return;
F_24 ( V_3 -> V_10 . V_11 != 0 ) ;
F_33 ( & V_14 , V_33 ) ;
V_1 = V_3 -> V_10 . V_1 ;
if ( V_1 != V_12 ) {
F_12 ( V_1 , V_15 ) ;
V_3 -> V_10 . V_1 = V_12 ;
#ifdef F_13
V_3 -> V_10 . V_11 = 0 ;
#endif
V_9 [ V_1 ] = NULL ;
V_16 ++ ;
}
F_34 ( & V_14 , V_33 ) ;
}
static int F_35 ( unsigned int V_4 )
{
if ( V_4 == V_34 )
return 0 ;
F_36 ( L_15 , V_4 ) ;
V_13 [ V_4 ] = F_37 ( V_35 , V_36 ) ;
return 0 ;
}
static int F_38 ( unsigned int V_4 )
{
#ifdef F_39
if ( V_4 == V_34 )
return 0 ;
F_36 ( L_16 , V_4 ) ;
F_40 ( V_13 [ V_4 ] ) ;
V_13 [ V_4 ] = NULL ;
F_41 ( V_4 ) ;
#endif
return 0 ;
}
void T_1 F_42 ( void )
{
V_37 . V_10 . V_11 = V_38 ;
if ( F_43 ( V_39 ) ) {
V_8 = 0 ;
V_7 = 15 ;
V_29 = true ;
} else if ( F_43 ( V_40 ) ) {
V_8 = 1 ;
V_7 = 65535 ;
V_29 = false ;
} else {
V_8 = 1 ;
V_7 = 255 ;
V_29 = false ;
}
#ifdef F_44
V_7 = F_44 ;
#endif
V_15 = F_45 ( V_35 , 0 ) ;
V_9 = F_45 ( sizeof( void * ) * ( V_7 + 1 ) , 0 ) ;
#ifndef F_23
V_13 [ 0 ] = F_45 ( V_35 , 0 ) ;
#else
V_13 [ V_34 ] = F_45 ( V_35 , 0 ) ;
F_46 ( V_41 ,
L_17 ,
F_35 , F_38 ) ;
#endif
F_47 ( V_42
L_18 ,
2 * V_35 + ( sizeof( void * ) * ( V_7 + 1 ) ) ,
V_7 - V_8 + 1 ) ;
V_15 [ 0 ] = ( 1 << V_8 ) - 1 ;
V_27 = V_8 ;
V_16 = V_7 - V_8 + 1 ;
}
