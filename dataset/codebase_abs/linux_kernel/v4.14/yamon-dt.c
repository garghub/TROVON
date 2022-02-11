T_1 int F_1 ( void * V_1 )
{
int V_2 , V_3 ;
V_3 = F_2 ( V_1 , L_1 ) ;
if ( V_3 == - V_4 )
V_3 = F_2 ( V_1 , L_2 ) ;
if ( V_3 == - V_4 )
V_3 = F_3 ( V_1 , 0 , L_3 ) ;
if ( V_3 < 0 ) {
F_4 ( L_4 ,
V_3 ) ;
return V_3 ;
}
V_2 = F_5 ( V_1 , V_3 , L_5 , F_6 () ) ;
if ( V_2 ) {
F_4 ( L_6 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
static unsigned int T_1 F_7 (
const struct V_5 * V_6 ,
T_2 * V_7 ,
unsigned int V_8 ,
unsigned long V_9 )
{
const struct V_5 * V_10 ;
unsigned long V_11 ;
unsigned int V_12 = 0 ;
for ( V_10 = V_6 ; V_10 -> V_11 && V_9 ; ++ V_10 ) {
if ( V_12 >= V_8 ) {
F_8 ( L_7 ,
V_8 ) ;
break;
}
V_11 = F_9 (unsigned long, memsize, mr->size) ;
V_9 -= V_11 ;
* ( V_7 ++ ) = F_10 ( V_10 -> V_13 ) ;
* ( V_7 ++ ) = F_10 ( V_11 ) ;
++ V_12 ;
V_9 -= F_9 (unsigned long, memsize, mr->discard) ;
}
return V_12 ;
}
T_1 int F_11 ( void * V_1 ,
const struct V_5 * V_6 )
{
unsigned long V_14 , V_9 ;
T_2 V_7 [ 2 * V_15 ] ;
unsigned int V_16 ;
int V_17 , V_2 , V_18 ;
char * V_19 , V_20 [ 10 ] , * V_21 [] = {
L_8 , L_9 ,
} ;
for ( V_17 = 0 ; V_17 < F_12 ( V_21 ) ; V_17 ++ ) {
V_19 = F_13 ( V_21 [ V_17 ] ) ;
if ( ! V_19 )
continue;
V_2 = F_14 ( V_19 , 0 , & V_14 ) ;
if ( ! V_2 )
break;
F_8 ( L_10 ,
V_21 [ V_17 ] , V_19 ) ;
}
if ( ! V_14 ) {
F_8 ( L_11 ) ;
V_14 = 32 << 20 ;
}
V_9 = V_14 ;
for ( V_17 = 0 ; V_17 < F_12 ( V_21 ) ; V_17 ++ ) {
snprintf ( V_20 , sizeof( V_20 ) , L_12 , V_21 [ V_17 ] ) ;
V_19 = strstr ( V_22 , V_20 ) ;
if ( ! V_19 )
continue;
V_9 = F_15 ( V_19 + strlen ( V_20 ) , NULL ) ;
}
V_14 = F_16 (unsigned long, phys_memsize, memsize) ;
V_18 = F_2 ( V_1 , L_13 ) ;
if ( V_18 == - V_4 )
V_18 = F_3 ( V_1 , 0 , L_14 ) ;
if ( V_18 < 0 ) {
F_4 ( L_15 , V_18 ) ;
return V_18 ;
}
V_2 = F_5 ( V_1 , V_18 , L_16 , L_14 ) ;
if ( V_2 ) {
F_4 ( L_17 , V_2 ) ;
return V_2 ;
}
V_16 = F_7 ( V_6 , V_7 ,
V_15 , V_14 ) ;
V_2 = F_17 ( V_1 , V_18 , L_18 ,
V_7 , V_16 * 2 * sizeof( V_7 [ 0 ] ) ) ;
if ( V_2 ) {
F_4 ( L_19 , V_2 ) ;
return V_2 ;
}
V_16 = F_7 ( V_6 , V_7 ,
V_15 , V_9 ) ;
V_2 = F_17 ( V_1 , V_18 , L_20 ,
V_7 , V_16 * 2 * sizeof( V_7 [ 0 ] ) ) ;
if ( V_2 ) {
F_4 ( L_21 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
T_1 int F_18 ( void * V_1 )
{
const char * V_23 , * V_24 ;
char V_25 [ 9 ] , V_26 [ 20 ] , V_27 ;
unsigned int V_28 , V_29 , V_30 ;
bool V_31 ;
int V_3 , V_2 ;
V_23 = F_13 ( L_22 ) ;
if ( ! V_23 || ! strcmp ( V_23 , L_23 ) ) {
V_28 = 0 ;
} else if ( ! strcmp ( V_23 , L_24 ) ) {
V_28 = 1 ;
} else {
F_8 ( L_25 ,
V_23 ) ;
V_28 = 0 ;
}
V_29 = V_30 = 0 ;
V_27 = 0 ;
V_31 = false ;
snprintf ( V_25 , sizeof( V_25 ) , L_26 , V_28 ) ;
V_24 = F_13 ( V_25 ) ;
if ( V_24 ) {
while ( V_24 [ 0 ] >= '0' && V_24 [ 0 ] <= '9' ) {
V_29 *= 10 ;
V_29 += V_24 [ 0 ] - '0' ;
V_24 ++ ;
}
if ( V_24 [ 0 ] == ',' )
V_24 ++ ;
if ( V_24 [ 0 ] )
V_27 = V_24 [ 0 ] ;
if ( V_24 [ 0 ] == ',' )
V_24 ++ ;
if ( V_24 [ 0 ] )
V_30 = V_24 [ 0 ] - '0' ;
if ( V_24 [ 0 ] == ',' )
V_24 ++ ;
if ( ! strcmp ( V_24 , L_27 ) )
V_31 = true ;
}
if ( ! V_29 )
V_29 = 38400 ;
if ( V_27 != 'e' && V_27 != 'n' && V_27 != 'o' )
V_27 = 'n' ;
if ( V_30 != 7 && V_30 != 8 )
V_30 = 8 ;
F_19 ( snprintf ( V_26 , sizeof( V_26 ) , L_28 ,
V_28 , V_29 , V_27 , V_30 ,
V_31 ? L_29 : L_30 ) >= sizeof( V_26 ) ) ;
V_3 = F_2 ( V_1 , L_1 ) ;
if ( V_3 == - V_4 )
V_3 = F_2 ( V_1 , L_2 ) ;
if ( V_3 == - V_4 )
V_3 = F_3 ( V_1 , 0 , L_3 ) ;
if ( V_3 < 0 ) {
F_4 ( L_4 ,
V_3 ) ;
return V_3 ;
}
V_2 = F_5 ( V_1 , V_3 , L_31 , V_26 ) ;
if ( V_2 ) {
F_4 ( L_32 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
