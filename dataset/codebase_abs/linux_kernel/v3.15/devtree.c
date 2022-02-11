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
static int T_1 F_10 ( struct V_8 * V_9 )
{
const char * V_10 ;
struct V_11 * V_12 = V_13 ;
if ( F_11 ( V_9 , L_1 , & V_10 ) )
return 0 ;
for (; V_12 < V_14 ; V_12 ++ )
if ( ! strcmp ( V_12 -> V_10 , V_10 ) ) {
F_12 ( V_12 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_10 ( struct V_8 * V_9 )
{
return 1 ;
}
void T_1 F_13 ( void )
{
struct V_8 * V_16 , * V_17 ;
int V_18 = 0 ;
T_3 V_19 , V_20 , V_21 = 1 ;
T_3 V_22 = F_14 () ? F_15 () & V_23 : 0 ;
T_3 V_24 [ V_25 ] = { [ 0 ... V_25 - 1 ] = V_26 } ;
bool V_27 = false ;
V_17 = F_16 ( L_2 ) ;
if ( ! V_17 )
return;
F_17 (cpus, cpu) {
T_3 V_28 ;
if ( F_18 ( V_16 -> type , L_3 ) )
continue;
F_19 ( L_4 , V_16 -> V_29 ) ;
if ( F_20 ( V_16 , L_5 , & V_28 ) ) {
F_19 ( L_6 ,
V_16 -> V_29 ) ;
return;
}
if ( V_28 & ~ V_23 )
return;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
if ( F_21 ( V_24 [ V_20 ] == V_28 , L_7
L_8 ) )
return;
if ( V_28 == V_22 ) {
V_19 = 0 ;
V_27 = true ;
} else {
V_19 = V_21 ++ ;
}
if ( F_21 ( V_21 > V_30 , L_9
L_10 ,
V_21 , V_30 ) ) {
V_21 = V_30 ;
break;
}
V_24 [ V_19 ] = V_28 ;
if ( ! V_18 )
V_18 = F_10 ( V_16 ) ;
}
if ( ! V_18 )
F_10 ( V_17 ) ;
if ( ! V_27 ) {
F_22 ( L_11 ) ;
return;
}
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
F_23 ( V_19 , true ) ;
F_24 ( V_19 ) = V_24 [ V_19 ] ;
F_19 ( L_12 , F_24 ( V_19 ) ) ;
}
}
bool F_25 ( int V_16 , T_2 V_31 )
{
return V_31 == F_24 ( V_16 ) ;
}
static const void * T_1 F_26 ( const char * const * * V_32 )
{
static const struct V_33 * V_34 = V_35 ;
const struct V_33 * V_12 = V_34 ;
if ( V_12 >= V_36 )
return NULL ;
V_34 ++ ;
* V_32 = V_12 -> V_37 ;
return V_12 ;
}
const struct V_33 * T_1 F_27 ( unsigned int V_38 )
{
const struct V_33 * V_34 , * V_39 = NULL ;
#ifdef F_28
F_29 (GENERIC_DT, L_13 )
T_4
V_39 = & V_40 ;
#endif
if ( ! V_38 || ! F_30 ( F_31 ( V_38 ) ) )
return NULL ;
V_34 = F_32 ( V_39 , F_26 ) ;
if ( ! V_34 ) {
const char * V_41 ;
long V_2 ;
unsigned long V_42 ;
F_33 ( L_14
L_15 ) ;
V_42 = F_34 () ;
V_41 = F_35 ( V_42 , L_16 , & V_2 ) ;
while ( V_2 > 0 ) {
F_33 ( L_17 , V_41 ) ;
V_2 -= strlen ( V_41 ) + 1 ;
V_41 += strlen ( V_41 ) + 1 ;
}
F_33 ( L_18 ) ;
F_36 () ;
}
V_43 = V_34 -> V_44 ;
return V_34 ;
}
