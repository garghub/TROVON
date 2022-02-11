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
const T_3 * V_20 ;
int V_21 ;
T_2 V_22 ;
if ( F_9 ( V_8 -> type , L_3 ) )
continue;
F_10 ( L_4 , V_8 -> V_23 ) ;
V_20 = F_11 ( V_8 , L_5 , & V_21 ) ;
if ( ! V_20 || V_21 < sizeof( * V_20 ) ) {
F_10 ( L_6 ,
V_8 -> V_23 ) ;
F_12 ( V_8 ) ;
return;
}
do {
V_22 = F_13 ( * V_20 ++ ) ;
V_21 -= sizeof( * V_20 ) ;
} while ( ! V_22 && V_21 > 0 );
if ( V_21 || ( V_22 & ~ V_15 ) ) {
F_12 ( V_8 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( F_14 ( V_16 [ V_12 ] == V_22 ,
L_7 ) ) {
F_12 ( V_8 ) ;
return;
}
if ( V_22 == V_14 ) {
V_11 = 0 ;
V_19 = true ;
} else {
V_11 = V_13 ++ ;
}
if ( F_14 ( V_13 > V_24 , L_8
L_9 ,
V_13 , V_24 ) ) {
V_13 = V_24 ;
F_12 ( V_8 ) ;
break;
}
V_16 [ V_11 ] = V_22 ;
if ( ! V_10 )
V_10 = F_1 ( V_8 ) ;
}
if ( ! V_10 )
F_1 ( V_9 ) ;
if ( ! V_19 ) {
F_15 ( L_10 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
F_16 ( V_11 , true ) ;
F_17 ( V_11 ) = V_16 [ V_11 ] ;
F_10 ( L_11 , F_17 ( V_11 ) ) ;
}
}
bool F_18 ( int V_8 , T_4 V_25 )
{
return V_25 == F_17 ( V_8 ) ;
}
static const void * T_1 F_19 ( const char * const * * V_26 )
{
static const struct V_27 * V_28 = V_29 ;
const struct V_27 * V_5 = V_28 ;
if ( V_5 >= V_30 )
return NULL ;
V_28 ++ ;
* V_26 = V_5 -> V_31 ;
return V_5 ;
}
const struct V_27 * T_1 F_20 ( unsigned int V_32 )
{
const struct V_27 * V_28 , * V_33 = NULL ;
#if F_21 ( V_34 ) || F_21 ( V_35 )
F_22 ( V_36 , L_12 )
. V_37 = 0x0 ,
. V_38 = ~ 0x0 ,
V_39
V_33 = & V_40 ;
#endif
if ( ! V_32 || ! F_23 ( F_24 ( V_32 ) ) )
return NULL ;
V_28 = F_25 ( V_33 , F_19 ) ;
if ( ! V_28 ) {
const char * V_41 ;
int V_42 ;
unsigned long V_43 ;
F_26 ( L_13
L_14 ) ;
V_43 = F_27 () ;
V_41 = F_28 ( V_43 , L_15 , & V_42 ) ;
while ( V_42 > 0 ) {
F_26 ( L_16 , V_41 ) ;
V_42 -= strlen ( V_41 ) + 1 ;
V_41 += strlen ( V_41 ) + 1 ;
}
F_26 ( L_17 ) ;
F_29 () ;
}
if ( V_28 -> V_44 )
V_28 -> V_44 () ;
F_30 () ;
V_45 = V_28 -> V_46 ;
return V_28 ;
}
