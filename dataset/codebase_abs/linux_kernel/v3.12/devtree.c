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
return ( V_23 & V_15 ) == F_21 ( V_9 ) ;
}
const struct V_24 * T_1 F_23 ( unsigned int V_25 )
{
struct V_26 * V_27 ;
const struct V_24 * V_28 , * V_29 = NULL ;
unsigned int V_30 , V_31 = ~ 1 ;
unsigned long V_32 ;
const char * V_33 ;
#ifdef F_24
F_25 (GENERIC_DT, L_12 )
T_4
V_29 = & V_34 ;
#endif
if ( ! V_25 )
return NULL ;
V_27 = F_26 ( V_25 ) ;
if ( F_8 ( V_27 -> V_35 ) != V_36 )
return NULL ;
V_5 = V_27 ;
V_32 = F_27 () ;
F_28 (mdesc) {
V_30 = F_29 ( V_32 , V_28 -> V_37 ) ;
if ( V_30 > 0 && V_30 < V_31 ) {
V_29 = V_28 ;
V_31 = V_30 ;
}
}
if ( ! V_29 ) {
const char * V_38 ;
long V_2 ;
F_30 ( L_13
L_14 ) ;
V_38 = F_31 ( V_32 , L_15 , & V_2 ) ;
while ( V_2 > 0 ) {
F_30 ( L_16 , V_38 ) ;
V_2 -= strlen ( V_38 ) + 1 ;
V_38 += strlen ( V_38 ) + 1 ;
}
F_30 ( L_17 ) ;
F_32 () ;
}
V_33 = F_31 ( V_32 , L_18 , NULL ) ;
if ( ! V_33 )
V_33 = F_31 ( V_32 , L_15 , NULL ) ;
if ( ! V_33 )
V_33 = L_19 ;
F_33 ( L_20 , V_29 -> V_39 , V_33 ) ;
F_34 ( V_40 , V_41 ) ;
F_34 ( V_42 , NULL ) ;
F_34 ( V_43 , NULL ) ;
V_44 = V_29 -> V_45 ;
return V_29 ;
}
