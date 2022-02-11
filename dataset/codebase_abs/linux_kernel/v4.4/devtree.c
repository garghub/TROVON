static int T_1 F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
struct V_4 * V_5 = V_6 ;
if ( F_2 ( V_2 , L_1 , & V_3 ) )
return 0 ;
for (; V_5 -> V_3 ; V_5 ++ )
if ( ! strcmp ( V_5 -> V_3 , V_3 ) ) {
F_3 ( V_5 -> V_7 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 )
{
return 1 ;
}
void T_1 F_4 ( void )
{
struct V_1 * V_8 , * V_9 ;
int V_10 = 0 ;
T_2 V_11 , V_12 , V_13 = 1 ;
T_2 V_14 = F_5 () ? F_6 () & V_15 : 0 ;
T_2 V_16 [ V_17 ] = { [ 0 ... V_17 - 1 ] = V_18 } ;
bool V_19 = false ;
V_9 = F_7 ( L_2 ) ;
if ( ! V_9 )
return;
F_8 (cpus, cpu) {
T_2 V_20 ;
if ( F_9 ( V_8 -> type , L_3 ) )
continue;
F_10 ( L_4 , V_8 -> V_21 ) ;
if ( F_11 ( V_8 , L_5 , & V_20 ) ) {
F_10 ( L_6 ,
V_8 -> V_21 ) ;
F_12 ( V_8 ) ;
return;
}
if ( V_20 & ~ V_15 ) {
F_12 ( V_8 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( F_13 ( V_16 [ V_12 ] == V_20 ,
L_7 ) ) {
F_12 ( V_8 ) ;
return;
}
if ( V_20 == V_14 ) {
V_11 = 0 ;
V_19 = true ;
} else {
V_11 = V_13 ++ ;
}
if ( F_13 ( V_13 > V_22 , L_8
L_9 ,
V_13 , V_22 ) ) {
V_13 = V_22 ;
F_12 ( V_8 ) ;
break;
}
V_16 [ V_11 ] = V_20 ;
if ( ! V_10 )
V_10 = F_1 ( V_8 ) ;
}
if ( ! V_10 )
F_1 ( V_9 ) ;
if ( ! V_19 ) {
F_14 ( L_10 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
F_15 ( V_11 , true ) ;
F_16 ( V_11 ) = V_16 [ V_11 ] ;
F_10 ( L_11 , F_16 ( V_11 ) ) ;
}
}
bool F_17 ( int V_8 , T_3 V_23 )
{
return V_23 == F_16 ( V_8 ) ;
}
static const void * T_1 F_18 ( const char * const * * V_24 )
{
static const struct V_25 * V_26 = V_27 ;
const struct V_25 * V_5 = V_26 ;
if ( V_5 >= V_28 )
return NULL ;
V_26 ++ ;
* V_24 = V_5 -> V_29 ;
return V_5 ;
}
const struct V_25 * T_1 F_19 ( unsigned int V_30 )
{
const struct V_25 * V_26 , * V_31 = NULL ;
#ifdef F_20
F_21 (GENERIC_DT, L_12 )
T_4
V_31 = & V_32 ;
#endif
if ( ! V_30 || ! F_22 ( F_23 ( V_30 ) ) )
return NULL ;
V_26 = F_24 ( V_31 , F_18 ) ;
if ( ! V_26 ) {
const char * V_33 ;
int V_34 ;
unsigned long V_35 ;
F_25 ( L_13
L_14 ) ;
V_35 = F_26 () ;
V_33 = F_27 ( V_35 , L_15 , & V_34 ) ;
while ( V_34 > 0 ) {
F_25 ( L_16 , V_33 ) ;
V_34 -= strlen ( V_33 ) + 1 ;
V_33 += strlen ( V_33 ) + 1 ;
}
F_25 ( L_17 ) ;
F_28 () ;
}
if ( V_26 -> V_36 )
V_26 -> V_36 () ;
F_29 () ;
V_37 = V_26 -> V_38 ;
return V_26 ;
}
