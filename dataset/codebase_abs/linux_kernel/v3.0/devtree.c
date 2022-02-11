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
struct V_8 * T_1 F_10 ( unsigned int V_9 )
{
struct V_10 * V_11 ;
struct V_8 * V_12 , * V_13 = NULL ;
unsigned int V_14 , V_15 = ~ 1 ;
unsigned long V_16 ;
const char * V_17 ;
if ( ! V_9 )
return NULL ;
V_11 = F_11 ( V_9 ) ;
if ( F_8 ( V_11 -> V_18 ) != V_19 )
return NULL ;
V_5 = V_11 ;
V_16 = F_12 () ;
F_13 (mdesc) {
V_14 = F_14 ( V_16 , V_12 -> V_20 ) ;
if ( V_14 > 0 && V_14 < V_15 ) {
V_13 = V_12 ;
V_15 = V_14 ;
}
}
if ( ! V_13 ) {
const char * V_21 ;
long V_2 ;
F_15 ( L_1
L_2 ) ;
V_21 = F_16 ( V_16 , L_3 , & V_2 ) ;
while ( V_2 > 0 ) {
F_15 ( L_4 , V_21 ) ;
V_2 -= strlen ( V_21 ) + 1 ;
V_21 += strlen ( V_21 ) + 1 ;
}
F_15 ( L_5 ) ;
F_17 () ;
}
V_17 = F_16 ( V_16 , L_6 , NULL ) ;
if ( ! V_17 )
V_17 = F_16 ( V_16 , L_3 , NULL ) ;
if ( ! V_17 )
V_17 = L_7 ;
F_18 ( L_8 , V_13 -> V_22 , V_17 ) ;
F_19 ( V_23 , V_24 ) ;
F_19 ( V_25 , NULL ) ;
F_19 ( V_26 , NULL ) ;
V_27 = V_13 -> V_28 ;
return V_13 ;
}
unsigned int F_20 ( struct V_29 * V_30 ,
const T_3 * V_31 , unsigned int V_32 )
{
return V_31 [ 0 ] ;
}
