static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = V_5 ;
V_5 = 15 ;
V_6 ++ ;
F_2 ( V_2 ) ;
if ( V_3 ) {
F_3 ( (struct V_1 * ) V_2 , V_3 ) ;
} else if ( V_7 ) {
#ifdef F_4
F_3 ( V_2 , & V_7 -> V_8 ) ;
#else
F_3 ( V_2 , NULL ) ;
#endif
} else {
F_3 ( V_2 , NULL ) ;
}
V_5 = V_4 ;
V_6 -- ;
}
static int
F_5 ( struct V_1 * V_2 , unsigned long V_9 ,
int V_10 , int V_11 )
{
char V_12 [ 2 ] ;
if ( F_6 ( V_12 [ 0 ] , ( unsigned long ) V_2 ) ||
F_6 ( V_12 [ 0 ] , ( unsigned long ) ( V_2 + 1 ) - 1 ) )
return V_13 ;
if ( ! F_7 ( V_2 , V_9 ) )
return 0 ;
F_8 ( L_1 , V_2 -> V_14 ) ;
F_9 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
if ( V_11 ) {
F_10 ( V_12 , sizeof( V_12 ) ,
L_2 ) ;
if ( V_12 [ 0 ] == 'q' ) {
F_8 ( L_3 ) ;
return 1 ;
}
}
F_11 () ;
return 0 ;
}
int
F_12 ( int V_15 , const char * * V_16 )
{
int V_17 ;
int V_10 = 5 ;
int V_11 = 1 ;
int V_18 ;
unsigned long V_3 ;
long V_19 ;
F_13 ( L_4 , & V_11 ) ;
if ( strcmp ( V_16 [ 0 ] , L_5 ) == 0 ) {
struct V_1 * V_20 , * V_2 ;
unsigned long V_21 ;
unsigned long V_9 = F_14 ( V_15 ? V_16 [ 1 ] :
NULL ) ;
if ( V_15 == 0 )
F_15 () ;
F_16 (cpu) {
V_2 = F_17 ( V_21 ) ;
if ( F_5 ( V_2 , V_9 , V_10 , V_11 ) )
return 0 ;
}
F_18 (g, p) {
if ( F_19 ( V_22 ) )
return 0 ;
if ( F_20 ( V_2 ) )
continue;
if ( F_5 ( V_2 , V_9 , V_10 , V_11 ) )
return 0 ;
} F_21 ( V_20 , V_2 ) ;
} else if ( strcmp ( V_16 [ 0 ] , L_6 ) == 0 ) {
struct V_1 * V_2 ;
unsigned long V_14 ;
if ( V_15 != 1 )
return V_23 ;
V_17 = F_22 ( ( char * ) V_16 [ 1 ] , & V_14 ) ;
if ( V_17 )
return V_17 ;
V_2 = F_23 ( V_14 , & V_24 ) ;
if ( V_2 ) {
F_2 ( V_2 ) ;
return F_5 ( V_2 , ~ 0UL , V_10 , 0 ) ;
}
F_8 ( L_7 , V_14 ) ;
return 0 ;
} else if ( strcmp ( V_16 [ 0 ] , L_8 ) == 0 ) {
if ( V_15 != 1 )
return V_23 ;
V_17 = F_22 ( ( char * ) V_16 [ 1 ] , & V_3 ) ;
if ( V_17 )
return V_17 ;
F_2 ( (struct V_1 * ) V_3 ) ;
return F_5 ( (struct V_1 * ) V_3 , ~ 0UL , V_10 , 0 ) ;
} else if ( strcmp ( V_16 [ 0 ] , L_9 ) == 0 ) {
unsigned long V_21 = ~ 0 ;
struct V_1 * V_25 = V_26 ;
char V_27 [ 80 ] ;
if ( V_15 > 1 )
return V_23 ;
if ( V_15 == 1 ) {
V_17 = F_22 ( ( char * ) V_16 [ 1 ] , & V_21 ) ;
if ( V_17 )
return V_17 ;
}
V_16 = NULL ;
if ( V_21 != ~ 0 ) {
if ( V_21 >= F_24 () || ! F_25 ( V_21 ) ) {
F_8 ( L_10 , V_21 ) ;
return 0 ;
}
sprintf ( V_27 , L_11 , F_26 ( V_21 ) ) ;
F_27 ( V_27 ) ;
return 0 ;
}
F_8 ( L_12 ) ;
F_27 ( L_13 ) ;
F_16 (cpu) {
sprintf ( V_27 , L_11 , F_26 ( V_21 ) ) ;
F_27 ( V_27 ) ;
F_11 () ;
}
F_2 ( V_25 ) ;
return 0 ;
} else {
if ( V_15 ) {
V_18 = 1 ;
V_17 = F_28 ( V_15 , V_16 , & V_18 , & V_3 ,
& V_19 , NULL ) ;
if ( V_17 )
return V_17 ;
F_1 ( V_26 , ( void * ) V_3 ) ;
return 0 ;
} else {
return F_5 ( V_26 , ~ 0UL , V_10 , 0 ) ;
}
}
return 0 ;
}
