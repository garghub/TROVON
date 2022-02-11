void * F_1 ( void * (* F_2) ( void ) , T_1 * V_1 , T_2 * V_2 , void * * V_3 )
{
T_3 * V_4 ;
void * V_5 ;
if ( ( V_4 = F_3 ( F_4 () ) ) == NULL ) {
F_5 ( V_6 , V_7 ) ;
return ( NULL ) ;
}
F_6 ( V_4 , V_2 , V_8 ) ;
V_5 = F_7 ( F_2 , V_1 , V_4 , V_3 ) ;
F_8 ( V_4 ) ;
return ( V_5 ) ;
}
void * F_7 ( void * (* F_2) ( void ) , T_1 * V_1 , T_3 * V_2 , void * * V_3 )
{
T_4 * V_4 = NULL ;
const unsigned char * V_9 ;
void * V_5 = NULL ;
int V_10 ;
V_10 = F_9 ( V_2 , & V_4 ) ;
if ( V_10 < 0 )
goto V_11;
V_9 = ( unsigned char * ) V_4 -> V_12 ;
V_5 = V_1 ( V_3 , & V_9 , V_10 ) ;
V_11:
F_10 ( V_4 ) ;
return ( V_5 ) ;
}
void * F_11 ( const T_5 * V_13 , T_3 * V_2 , void * V_3 )
{
T_4 * V_4 = NULL ;
const unsigned char * V_9 ;
void * V_5 = NULL ;
int V_10 ;
V_10 = F_9 ( V_2 , & V_4 ) ;
if ( V_10 < 0 )
goto V_11;
V_9 = ( const unsigned char * ) V_4 -> V_12 ;
V_5 = F_12 ( V_3 , & V_9 , V_10 , V_13 ) ;
V_11:
F_10 ( V_4 ) ;
return ( V_5 ) ;
}
void * F_13 ( const T_5 * V_13 , T_2 * V_2 , void * V_3 )
{
T_3 * V_4 ;
char * V_5 ;
if ( ( V_4 = F_3 ( F_4 () ) ) == NULL ) {
F_5 ( V_14 , V_7 ) ;
return ( NULL ) ;
}
F_6 ( V_4 , V_2 , V_8 ) ;
V_5 = F_11 ( V_13 , V_4 , V_3 ) ;
F_8 ( V_4 ) ;
return ( V_5 ) ;
}
static int F_9 ( T_3 * V_2 , T_4 * * V_15 )
{
T_4 * V_4 ;
unsigned char * V_9 ;
int V_16 ;
T_6 V_17 = V_18 ;
T_7 V_19 = 0 ;
T_6 V_20 = 0 ;
T_6 V_10 = 0 ;
const unsigned char * V_21 ;
long V_22 ;
int V_23 , V_24 , V_25 ;
V_4 = F_14 () ;
if ( V_4 == NULL ) {
F_5 ( V_26 , V_27 ) ;
return - 1 ;
}
F_15 () ;
for (; ; ) {
if ( V_17 >= ( V_10 - V_20 ) ) {
V_17 -= ( V_10 - V_20 ) ;
if ( V_10 + V_17 < V_10 || ! F_16 ( V_4 , V_10 + V_17 ) ) {
F_5 ( V_26 , V_27 ) ;
goto V_11;
}
V_16 = F_17 ( V_2 , & ( V_4 -> V_12 [ V_10 ] ) , V_17 ) ;
if ( ( V_16 < 0 ) && ( ( V_10 - V_20 ) == 0 ) ) {
F_5 ( V_26 , V_28 ) ;
goto V_11;
}
if ( V_16 > 0 ) {
if ( V_10 + V_16 < V_10 ) {
F_5 ( V_26 , V_29 ) ;
goto V_11;
}
V_10 += V_16 ;
}
}
V_9 = ( unsigned char * ) & ( V_4 -> V_12 [ V_20 ] ) ;
V_21 = V_9 ;
V_23 = F_18 ( & V_21 , & V_22 , & V_24 , & V_25 , V_10 - V_20 ) ;
if ( V_23 & 0x80 ) {
unsigned long V_30 ;
V_30 = F_19 ( F_20 () ) ;
if ( V_30 != V_29 )
goto V_11;
else
F_15 () ;
}
V_16 = V_21 - V_9 ;
V_20 += V_16 ;
if ( V_23 & 1 ) {
if ( V_19 == V_31 ) {
F_5 ( V_26 , V_32 ) ;
goto V_11;
}
V_19 ++ ;
V_17 = V_18 ;
} else if ( V_19 && ( V_22 == 0 ) && ( V_24 == V_33 ) ) {
V_19 -- ;
if ( V_19 == 0 )
break;
else
V_17 = V_18 ;
} else {
V_17 = V_22 ;
if ( V_17 > ( V_10 - V_20 ) ) {
T_6 V_34 = V_35 ;
V_17 -= ( V_10 - V_20 ) ;
if ( V_17 > V_36 ||
V_10 + V_17 < V_10 ) {
F_5 ( V_26 , V_29 ) ;
goto V_11;
}
while ( V_17 > 0 ) {
T_6 V_37 = V_17 > V_34 ? V_34 : V_17 ;
if ( ! F_16 ( V_4 , V_10 + V_37 ) ) {
F_5 ( V_26 , V_27 ) ;
goto V_11;
}
V_17 -= V_37 ;
while ( V_37 > 0 ) {
V_16 = F_17 ( V_2 , & ( V_4 -> V_12 [ V_10 ] ) , V_37 ) ;
if ( V_16 <= 0 ) {
F_5 ( V_26 ,
V_28 ) ;
goto V_11;
}
V_10 += V_16 ;
V_37 -= V_16 ;
}
if ( V_34 < V_36 / 2 )
V_34 *= 2 ;
}
}
if ( V_20 + V_22 < V_20 ) {
F_5 ( V_26 , V_29 ) ;
goto V_11;
}
V_20 += V_22 ;
if ( V_19 == 0 ) {
break;
} else
V_17 = V_18 ;
}
}
if ( V_20 > V_36 ) {
F_5 ( V_26 , V_29 ) ;
goto V_11;
}
* V_15 = V_4 ;
return V_20 ;
V_11:
F_10 ( V_4 ) ;
return - 1 ;
}
