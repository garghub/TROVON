int
F_1 ( void * V_1 , int V_2 ,
T_1 * V_3 , void * V_4 , T_2 * V_5 ,
int (* F_2)( void * V_1 , int V_2 ,
T_1 V_6 , void * V_4 , int V_7 ) )
{
int V_8 = F_2 ( V_1 , V_2 , * V_3 , V_4 , * V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 ) {
* V_3 += * V_5 ;
} else {
* V_5 = V_8 ;
* V_3 += V_8 ;
}
return 0 ;
}
static int F_3 ( void * V_1 , int V_2 ,
T_1 V_6 , void * V_4 , int V_9 )
{
const int V_10 = 512 ;
char * V_11 ;
int V_8 ;
unsigned int * V_12 = V_1 ;
int V_13 = ( V_12 == & V_14 ) ? 1 : 0 ;
int V_15 = ( V_12 == & V_16 ) ? 1 : 0 ;
V_8 = F_4 ( & V_11 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! V_2 ) {
F_5 ( V_11 , V_10 , * V_12 , V_13 ) ;
V_8 = strlen ( V_11 ) ;
if ( V_6 >= V_8 ) {
V_8 = 0 ;
} else {
V_8 = F_6 ( V_4 , V_9 ,
V_11 + V_6 , L_1 ) ;
}
} else {
V_8 = F_7 ( V_11 , V_10 , V_4 , V_9 ) ;
if ( V_8 < 0 ) {
F_8 ( V_11 , V_10 ) ;
return V_8 ;
}
V_8 = F_9 ( V_12 , V_11 , V_13 ) ;
if ( V_15 )
* V_12 |= V_17 ;
}
F_8 ( V_11 , V_10 ) ;
return V_8 ;
}
static int F_10 ( void * V_1 , int V_2 ,
T_1 V_6 , void * V_4 , int V_9 )
{
if ( ! V_2 )
return 0 ;
return F_11 ( V_4 , V_9 ) ;
}
static int F_12 ( void * V_1 , int V_2 ,
T_1 V_6 , void * V_4 , int V_9 )
{
if ( ! V_2 ) {
int V_7 = strlen ( V_18 ) ;
if ( V_6 >= V_7 )
return 0 ;
return F_6 ( V_4 , V_9 ,
V_18 + V_6 , L_1 ) ;
}
return F_13 ( V_4 , V_9 ) ;
}
static int F_14 ( void * V_1 , int V_2 ,
T_1 V_6 , void * V_4 , int V_9 )
{
if ( ! V_2 ) {
char V_11 [ 32 ] ;
int V_7 = snprintf ( V_11 , sizeof( V_11 ) , L_2 ,
F_15 () ) ;
if ( V_6 >= V_7 )
return 0 ;
return F_6 ( V_4 , V_9 , V_11 + V_6 ,
L_1 ) ;
}
return F_16 ( V_4 , V_9 ) ;
}
int F_17 ( T_3 )
{
int V_8 , V_19 ;
T_4 V_20 = * V_21 ;
T_5 V_22 ;
V_20 . V_1 = & V_19 ;
V_20 . V_23 = & V_24 ;
if ( ! V_2 ) {
V_19 = F_18 ( V_25 * 100 ) ;
V_8 = F_19 ( & V_20 , V_2 , V_26 , V_4 , V_5 , V_3 ) ;
return V_8 ;
}
V_19 = 0 ;
V_8 = F_19 ( & V_20 , V_2 , V_26 , V_4 , V_5 , V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_19 <= 0 )
return - V_27 ;
V_22 = F_20 ( V_19 ) / 100 ;
if ( V_22 == 0 || V_22 < V_28 )
return - V_27 ;
V_25 = V_22 ;
return V_8 ;
}
int F_17 ( T_6 )
{
int V_8 , V_29 ;
T_4 V_20 = * V_21 ;
T_5 V_22 ;
V_20 . V_1 = & V_29 ;
V_20 . V_23 = & V_24 ;
if ( ! V_2 ) {
V_29 = F_18 ( V_28 * 100 ) ;
V_8 = F_19 ( & V_20 , V_2 , V_26 , V_4 , V_5 , V_3 ) ;
return V_8 ;
}
V_29 = 0 ;
V_8 = F_19 ( & V_20 , V_2 , V_26 , V_4 , V_5 , V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_29 <= 0 )
return - V_27 ;
V_22 = F_20 ( V_29 ) / 100 ;
if ( V_22 == 0 || V_22 > V_25 )
return - V_27 ;
V_28 = V_22 ;
return V_8 ;
}
int F_17 ( T_7 )
{
int V_8 , V_30 ;
T_4 V_20 = * V_21 ;
V_20 . V_1 = & V_30 ;
V_20 . V_23 = & V_24 ;
if ( ! V_2 ) {
V_30 = V_31 ;
V_8 = F_19 ( & V_20 , V_2 , V_26 , V_4 , V_5 , V_3 ) ;
return V_8 ;
}
V_30 = 0 ;
V_8 = F_19 ( & V_20 , V_2 , V_26 , V_4 , V_5 , V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_30 <= 0 )
return - V_27 ;
V_31 = V_30 ;
return V_8 ;
}
int F_17 ( T_8 )
{
if ( V_2 )
F_21 () ;
return 0 ;
}
int F_17 ( T_9 )
{
int V_8 ;
long V_32 = V_33 ;
V_8 = F_22 ( V_21 , V_2 , V_26 , V_4 , V_5 , V_3 ) ;
if ( V_32 != V_33 )
F_23 ( & V_34 ) ;
return V_8 ;
}
static int F_24 ( void * V_1 , int V_2 ,
T_1 V_6 , void * V_4 , int V_9 )
{
char * V_35 = NULL ;
int V_7 = 4096 ;
int V_8 = 0 ;
if ( V_2 )
return - V_36 ;
F_25 ( V_37 != NULL ) ;
while ( 1 ) {
F_26 ( V_35 , V_7 ) ;
if ( V_35 == NULL )
return - V_38 ;
V_8 = F_27 ( V_37 , V_35 , V_7 ) ;
if ( V_8 >= 0 )
break;
F_28 ( V_35 , V_7 ) ;
if ( V_8 == - V_39 ) {
V_7 <<= 1 ;
continue;
}
goto V_40;
}
if ( V_6 >= V_8 ) {
V_8 = 0 ;
goto V_40;
}
V_8 = F_6 ( V_4 , V_9 , V_35 + V_6 , NULL ) ;
V_40:
if ( V_35 != NULL )
F_28 ( V_35 , V_7 ) ;
return V_8 ;
}
int F_29 ( void )
{
#ifdef F_30
if ( V_41 == NULL )
V_41 = F_31 ( V_42 ) ;
#endif
return 0 ;
}
void F_32 ( void )
{
#ifdef F_30
if ( V_41 != NULL )
F_33 ( V_41 ) ;
V_41 = NULL ;
#endif
}
