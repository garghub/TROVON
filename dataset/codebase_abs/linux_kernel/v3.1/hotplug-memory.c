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
V_13 = V_11 >> V_16 ;
if ( ! F_11 ( V_13 ) ) {
F_12 ( V_11 , V_3 ) ;
return 0 ;
}
V_14 = F_13 ( F_14 ( V_13 ) ) ;
V_15 = F_15 ( V_14 , V_13 , V_3 >> V_16 ) ;
if ( V_15 )
return V_15 ;
F_12 ( V_11 , V_3 ) ;
V_12 = ( unsigned long ) F_16 ( V_11 ) ;
V_15 = F_17 ( V_12 , V_12 + V_3 ) ;
F_18 () ;
return V_15 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const char * type ;
const unsigned int * V_17 ;
unsigned long V_11 ;
unsigned int V_18 ;
int V_15 = - V_19 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_17 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_17 )
return V_15 ;
V_11 = * ( unsigned long * ) V_17 ;
V_18 = V_17 [ 3 ] ;
V_15 = F_10 ( V_11 , V_18 ) ;
return V_15 ;
}
static int F_20 ( struct V_1 * V_2 )
{
const char * type ;
const unsigned int * V_17 ;
unsigned long V_11 ;
unsigned int V_18 ;
int V_15 = - V_19 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_17 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_17 )
return V_15 ;
V_11 = * ( unsigned long * ) V_17 ;
V_18 = V_17 [ 3 ] ;
V_15 = F_21 ( V_11 , V_18 ) ;
return ( V_15 < 0 ) ? - V_19 : 0 ;
}
static int F_22 ( unsigned long * V_11 , unsigned int V_20 )
{
unsigned long V_3 ;
int V_21 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_19 ;
if ( V_20 == V_22 ) {
V_21 = F_21 ( * V_11 , V_3 ) ;
V_21 = ( V_21 < 0 ) ? - V_19 : 0 ;
} else if ( V_20 == V_23 ) {
V_21 = F_10 ( * V_11 , V_3 ) ;
} else {
V_21 = - V_19 ;
}
return V_21 ;
}
static int F_23 ( struct V_24 * V_25 ,
unsigned long V_20 , void * V_26 )
{
int V_27 = 0 ;
switch ( V_20 ) {
case V_28 :
V_27 = F_20 ( V_26 ) ;
break;
case V_29 :
V_27 = F_19 ( V_26 ) ;
break;
case V_22 :
case V_23 :
V_27 = F_22 ( V_26 , V_20 ) ;
break;
}
return F_24 ( V_27 ) ;
}
static int T_2 F_25 ( void )
{
if ( F_26 ( V_30 ) )
F_27 ( & V_31 ) ;
return 0 ;
}
