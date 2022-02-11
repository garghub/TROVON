static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = V_5 ;
V_5 = V_6 ;
V_7 ++ ;
F_2 ( V_2 ) ;
if ( V_3 ) {
F_3 ( (struct V_1 * ) V_2 , V_3 ) ;
} else if ( V_8 ) {
#ifdef F_4
F_3 ( V_2 , & V_8 -> V_9 ) ;
#else
F_3 ( V_2 , NULL ) ;
#endif
} else {
F_3 ( V_2 , NULL ) ;
}
V_5 = V_4 ;
V_7 -- ;
}
static int
F_5 ( struct V_1 * V_2 , unsigned long V_10 ,
int V_11 , int V_12 )
{
char V_13 [ 2 ] ;
if ( F_6 ( V_13 [ 0 ] , ( unsigned long ) V_2 ) ||
F_6 ( V_13 [ 0 ] , ( unsigned long ) ( V_2 + 1 ) - 1 ) )
return V_14 ;
if ( ! F_7 ( V_2 , V_10 ) )
return 0 ;
F_8 ( L_1 , V_2 -> V_15 ) ;
F_9 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
if ( V_12 ) {
F_10 ( V_13 , sizeof( V_13 ) ,
L_2 ) ;
if ( V_13 [ 0 ] == 'q' ) {
F_8 ( L_3 ) ;
return 1 ;
}
}
F_11 () ;
return 0 ;
}
int
F_12 ( int V_16 , const char * * V_17 )
{
int V_18 ;
int V_11 = 5 ;
int V_12 = 1 ;
int V_19 ;
unsigned long V_3 ;
long V_20 ;
F_13 ( L_4 , & V_12 ) ;
if ( strcmp ( V_17 [ 0 ] , L_5 ) == 0 ) {
struct V_1 * V_21 , * V_2 ;
unsigned long V_22 ;
unsigned long V_10 = F_14 ( V_16 ? V_17 [ 1 ] :
NULL ) ;
if ( V_16 == 0 )
F_15 () ;
F_16 (cpu) {
V_2 = F_17 ( V_22 ) ;
if ( F_5 ( V_2 , V_10 , V_11 , V_12 ) )
return 0 ;
}
F_18 (g, p) {
if ( F_19 ( V_23 ) )
return 0 ;
if ( F_20 ( V_2 ) )
continue;
if ( F_5 ( V_2 , V_10 , V_11 , V_12 ) )
return 0 ;
} F_21 ( V_21 , V_2 ) ;
} else if ( strcmp ( V_17 [ 0 ] , L_6 ) == 0 ) {
struct V_1 * V_2 ;
unsigned long V_15 ;
if ( V_16 != 1 )
return V_24 ;
V_18 = F_22 ( ( char * ) V_17 [ 1 ] , & V_15 ) ;
if ( V_18 )
return V_18 ;
V_2 = F_23 ( V_15 , & V_25 ) ;
if ( V_2 ) {
F_2 ( V_2 ) ;
return F_5 ( V_2 , ~ 0UL , V_11 , 0 ) ;
}
F_8 ( L_7 , V_15 ) ;
return 0 ;
} else if ( strcmp ( V_17 [ 0 ] , L_8 ) == 0 ) {
if ( V_16 != 1 )
return V_24 ;
V_18 = F_22 ( ( char * ) V_17 [ 1 ] , & V_3 ) ;
if ( V_18 )
return V_18 ;
F_2 ( (struct V_1 * ) V_3 ) ;
return F_5 ( (struct V_1 * ) V_3 , ~ 0UL , V_11 , 0 ) ;
} else if ( strcmp ( V_17 [ 0 ] , L_9 ) == 0 ) {
unsigned long V_22 = ~ 0 ;
struct V_1 * V_26 = V_27 ;
char V_28 [ 80 ] ;
if ( V_16 > 1 )
return V_24 ;
if ( V_16 == 1 ) {
V_18 = F_22 ( ( char * ) V_17 [ 1 ] , & V_22 ) ;
if ( V_18 )
return V_18 ;
}
V_17 = NULL ;
if ( V_22 != ~ 0 ) {
if ( V_22 >= F_24 () || ! F_25 ( V_22 ) ) {
F_8 ( L_10 , V_22 ) ;
return 0 ;
}
sprintf ( V_28 , L_11 , F_26 ( V_22 ) ) ;
F_27 ( V_28 ) ;
return 0 ;
}
F_8 ( L_12 ) ;
F_27 ( L_13 ) ;
F_16 (cpu) {
sprintf ( V_28 , L_11 , F_26 ( V_22 ) ) ;
F_27 ( V_28 ) ;
F_11 () ;
}
F_2 ( V_26 ) ;
return 0 ;
} else {
if ( V_16 ) {
V_19 = 1 ;
V_18 = F_28 ( V_16 , V_17 , & V_19 , & V_3 ,
& V_20 , NULL ) ;
if ( V_18 )
return V_18 ;
F_1 ( V_27 , ( void * ) V_3 ) ;
return 0 ;
} else {
return F_5 ( V_27 , ~ 0UL , V_11 , 0 ) ;
}
}
return 0 ;
}
