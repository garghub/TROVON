static unsigned long F_1 ( void )
{
struct V_1 * V_2 ;
unsigned int V_3 = V_4 ;
struct V_5 V_6 ;
V_2 = F_2 ( L_1 ) ;
if ( V_2 ) {
const T_1 * V_7 ;
V_7 = F_3 ( V_2 , L_2 , NULL ) ;
if ( V_7 )
V_3 = F_4 ( V_7 ) ;
F_5 ( V_2 ) ;
} else if ( F_6 ( V_8 ) ) {
unsigned int V_9 = 0 ;
V_2 = F_2 ( L_3 ) ;
if ( V_2 ) {
if ( ! F_7 ( V_2 , 0 , & V_6 ) )
V_9 = F_8 ( & V_6 ) ;
F_5 ( V_2 ) ;
}
if ( V_9 ) {
char V_10 [ 64 ] ;
sprintf ( V_10 , L_4 , V_9 ) ;
V_2 = F_2 ( V_10 ) ;
if ( V_2 ) {
if ( ! F_7 ( V_2 , 0 , & V_6 ) )
V_3 = F_8 ( & V_6 ) ;
F_5 ( V_2 ) ;
}
}
}
return V_3 ;
}
unsigned long F_9 ( void )
{
return F_1 () ;
}
static int F_10 ( unsigned long V_11 , unsigned int V_3 )
{
unsigned long V_12 , V_13 ;
struct V_14 * V_14 ;
int V_15 ;
unsigned long V_16 ;
unsigned long V_17 ;
V_13 = V_11 >> V_18 ;
if ( ! F_11 ( V_13 ) ) {
F_12 ( V_11 , V_3 ) ;
return 0 ;
}
V_14 = F_13 ( F_14 ( V_13 ) ) ;
V_17 = ( V_3 >> V_18 ) / V_19 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
unsigned long V_20 = V_13 + V_16 * V_19 ;
V_15 = F_15 ( V_14 , V_20 , V_19 ) ;
if ( V_15 )
return V_15 ;
}
F_12 ( V_11 , V_3 ) ;
V_12 = ( unsigned long ) F_16 ( V_11 ) ;
V_15 = F_17 ( V_12 , V_12 + V_3 ) ;
F_18 () ;
return V_15 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const char * type ;
const unsigned int * V_21 ;
unsigned long V_11 ;
unsigned int V_22 ;
int V_15 = - V_23 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_21 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_21 )
return V_15 ;
V_11 = * ( unsigned long * ) V_21 ;
V_22 = V_21 [ 3 ] ;
V_15 = F_10 ( V_11 , V_22 ) ;
return V_15 ;
}
static int F_20 ( struct V_1 * V_2 )
{
const char * type ;
const unsigned int * V_21 ;
unsigned long V_11 ;
unsigned int V_22 ;
int V_15 = - V_23 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_21 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_21 )
return V_15 ;
V_11 = * ( unsigned long * ) V_21 ;
V_22 = V_21 [ 3 ] ;
V_15 = F_21 ( V_11 , V_22 ) ;
return ( V_15 < 0 ) ? - V_23 : 0 ;
}
static int F_22 ( unsigned long * V_11 , unsigned int V_24 )
{
unsigned long V_3 ;
int V_25 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_23 ;
if ( V_24 == V_26 ) {
V_25 = F_21 ( * V_11 , V_3 ) ;
V_25 = ( V_25 < 0 ) ? - V_23 : 0 ;
} else if ( V_24 == V_27 ) {
V_25 = F_10 ( * V_11 , V_3 ) ;
} else {
V_25 = - V_23 ;
}
return V_25 ;
}
static int F_23 ( struct V_28 * V_29 ,
unsigned long V_24 , void * V_30 )
{
int V_31 = 0 ;
switch ( V_24 ) {
case V_32 :
V_31 = F_20 ( V_30 ) ;
break;
case V_33 :
V_31 = F_19 ( V_30 ) ;
break;
case V_26 :
case V_27 :
V_31 = F_22 ( V_30 , V_24 ) ;
break;
}
return F_24 ( V_31 ) ;
}
static int T_2 F_25 ( void )
{
if ( F_26 ( V_34 ) )
F_27 ( & V_35 ) ;
return 0 ;
}
