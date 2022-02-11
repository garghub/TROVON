void T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
void * T_1 F_3 ( T_2 V_2 , T_2 V_3 )
{
return F_4 ( V_2 , V_3 ) ;
}
void T_1 F_5 ( void )
{
T_2 * V_4 , V_1 , V_2 ;
if ( ! V_5 )
return;
F_6 ( F_7 ( V_5 ) ,
F_8 ( V_5 -> V_6 ) ) ;
V_4 = ( ( void * ) V_5 ) +
F_8 ( V_5 -> V_7 ) ;
while ( 1 ) {
V_1 = F_9 ( V_4 ++ ) ;
V_2 = F_9 ( V_4 ++ ) ;
if ( ! V_2 )
break;
F_6 ( V_1 , V_2 ) ;
}
}
void T_1 F_10 ( void )
{
struct V_8 * V_9 , * V_10 ;
T_3 V_11 , V_12 , V_13 = 1 ;
T_3 V_14 = F_11 () ? F_12 () & V_15 : 0 ;
T_3 V_16 [ V_17 ] = { [ 0 ... V_17 - 1 ] = V_18 } ;
bool V_19 = false ;
V_10 = F_13 ( L_1 ) ;
if ( ! V_10 )
return;
F_14 (cpus, cpu) {
T_3 V_20 ;
if ( F_15 ( V_9 -> type , L_2 ) )
continue;
F_16 ( L_3 , V_9 -> V_21 ) ;
if ( F_17 ( V_9 , L_4 , & V_20 ) ) {
F_16 ( L_5 ,
V_9 -> V_21 ) ;
return;
}
if ( V_20 & ~ V_15 )
return;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( F_18 ( V_16 [ V_12 ] == V_20 , L_6
L_7 ) )
return;
if ( V_20 == V_14 ) {
V_11 = 0 ;
V_19 = true ;
} else {
V_11 = V_13 ++ ;
}
if ( F_18 ( V_13 > V_22 , L_8
L_9 ,
V_13 , V_22 ) ) {
V_13 = V_22 ;
break;
}
V_16 [ V_11 ] = V_20 ;
}
if ( ! V_19 ) {
F_19 ( L_10 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
F_20 ( V_11 , true ) ;
F_21 ( V_11 ) = V_16 [ V_11 ] ;
F_16 ( L_11 , F_21 ( V_11 ) ) ;
}
}
bool F_22 ( int V_9 , T_2 V_23 )
{
return V_23 == F_21 ( V_9 ) ;
}
static const void * T_1 F_23 ( const char * const * * V_24 )
{
static const struct V_25 * V_26 = V_27 ;
const struct V_25 * V_28 = V_26 ;
if ( V_28 >= V_29 )
return NULL ;
V_26 ++ ;
* V_24 = V_28 -> V_30 ;
return V_28 ;
}
const struct V_25 * T_1 F_24 ( unsigned int V_31 )
{
const struct V_25 * V_26 , * V_32 = NULL ;
#ifdef F_25
F_26 (GENERIC_DT, L_12 )
T_4
V_32 = & V_33 ;
#endif
if ( ! V_31 || ! F_27 ( F_28 ( V_31 ) ) )
return NULL ;
V_26 = F_29 ( V_32 , F_23 ) ;
if ( ! V_26 ) {
const char * V_34 ;
long V_2 ;
unsigned long V_35 ;
F_30 ( L_13
L_14 ) ;
V_35 = F_31 () ;
V_34 = F_32 ( V_35 , L_15 , & V_2 ) ;
while ( V_2 > 0 ) {
F_30 ( L_16 , V_34 ) ;
V_2 -= strlen ( V_34 ) + 1 ;
V_34 += strlen ( V_34 ) + 1 ;
}
F_30 ( L_17 ) ;
F_33 () ;
}
V_36 = V_26 -> V_37 ;
return V_26 ;
}
