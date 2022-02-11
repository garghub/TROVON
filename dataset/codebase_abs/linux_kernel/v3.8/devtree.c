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
F_15 ( L_2 , V_9 -> V_21 ) ;
if ( F_16 ( V_9 , L_3 , & V_20 ) ) {
F_15 ( L_4 ,
V_9 -> V_21 ) ;
return;
}
if ( V_20 & ~ V_15 )
return;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( F_17 ( V_16 [ V_12 ] == V_20 , L_5
L_6 ) )
return;
if ( V_20 == V_14 ) {
V_11 = 0 ;
V_19 = true ;
} else {
V_11 = V_13 ++ ;
}
if ( F_17 ( V_13 > V_22 , L_7
L_8 ,
V_13 , V_22 ) ) {
V_13 = V_22 ;
break;
}
V_16 [ V_11 ] = V_20 ;
}
if ( F_17 ( ! V_19 , L_9
L_10 ) )
return;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
F_18 ( V_11 , true ) ;
F_19 ( V_11 ) = V_16 [ V_11 ] ;
F_15 ( L_11 , F_19 ( V_11 ) ) ;
}
}
struct V_23 * T_1 F_20 ( unsigned int V_24 )
{
struct V_25 * V_26 ;
struct V_23 * V_27 , * V_28 = NULL ;
unsigned int V_29 , V_30 = ~ 1 ;
unsigned long V_31 ;
const char * V_32 ;
if ( ! V_24 )
return NULL ;
V_26 = F_21 ( V_24 ) ;
if ( F_8 ( V_26 -> V_33 ) != V_34 )
return NULL ;
V_5 = V_26 ;
V_31 = F_22 () ;
F_23 (mdesc) {
V_29 = F_24 ( V_31 , V_27 -> V_35 ) ;
if ( V_29 > 0 && V_29 < V_30 ) {
V_28 = V_27 ;
V_30 = V_29 ;
}
}
if ( ! V_28 ) {
const char * V_36 ;
long V_2 ;
F_25 ( L_12
L_13 ) ;
V_36 = F_26 ( V_31 , L_14 , & V_2 ) ;
while ( V_2 > 0 ) {
F_25 ( L_15 , V_36 ) ;
V_2 -= strlen ( V_36 ) + 1 ;
V_36 += strlen ( V_36 ) + 1 ;
}
F_25 ( L_16 ) ;
F_27 () ;
}
V_32 = F_26 ( V_31 , L_17 , NULL ) ;
if ( ! V_32 )
V_32 = F_26 ( V_31 , L_14 , NULL ) ;
if ( ! V_32 )
V_32 = L_18 ;
F_28 ( L_19 , V_28 -> V_37 , V_32 ) ;
F_29 ( V_38 , V_39 ) ;
F_29 ( V_40 , NULL ) ;
F_29 ( V_41 , NULL ) ;
V_42 = V_28 -> V_43 ;
return V_28 ;
}
