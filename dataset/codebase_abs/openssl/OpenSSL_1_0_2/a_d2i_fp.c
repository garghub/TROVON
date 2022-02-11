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
if ( V_4 != NULL )
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
if ( V_4 != NULL )
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
T_6 V_17 ;
T_7 V_18 = V_19 ;
int V_20 = 0 ;
T_7 V_21 = 0 ;
T_7 V_10 = 0 ;
V_4 = F_14 () ;
if ( V_4 == NULL ) {
F_5 ( V_22 , V_23 ) ;
return - 1 ;
}
F_15 () ;
for (; ; ) {
if ( V_18 >= ( V_10 - V_21 ) ) {
V_18 -= ( V_10 - V_21 ) ;
if ( V_10 + V_18 < V_10 || ! F_16 ( V_4 , V_10 + V_18 ) ) {
F_5 ( V_22 , V_23 ) ;
goto V_11;
}
V_16 = F_17 ( V_2 , & ( V_4 -> V_12 [ V_10 ] ) , V_18 ) ;
if ( ( V_16 < 0 ) && ( ( V_10 - V_21 ) == 0 ) ) {
F_5 ( V_22 , V_24 ) ;
goto V_11;
}
if ( V_16 > 0 ) {
if ( V_10 + V_16 < V_10 ) {
F_5 ( V_22 , V_25 ) ;
goto V_11;
}
V_10 += V_16 ;
}
}
V_9 = ( unsigned char * ) & ( V_4 -> V_12 [ V_21 ] ) ;
V_17 . V_9 = V_9 ;
V_17 . V_26 = F_18 ( & ( V_17 . V_9 ) , & ( V_17 . V_27 ) , & ( V_17 . V_28 ) , & ( V_17 . V_29 ) ,
V_10 - V_21 ) ;
if ( V_17 . V_26 & 0x80 ) {
unsigned long V_30 ;
V_30 = F_19 ( F_20 () ) ;
if ( V_30 != V_25 )
goto V_11;
else
F_15 () ;
}
V_16 = V_17 . V_9 - V_9 ;
V_21 += V_16 ;
if ( V_17 . V_26 & 1 ) {
V_20 ++ ;
if ( V_20 < 0 ) {
F_5 ( V_22 , V_31 ) ;
goto V_11;
}
V_18 = V_19 ;
} else if ( V_20 && ( V_17 . V_27 == 0 ) && ( V_17 . V_28 == V_32 ) ) {
V_20 -- ;
if ( V_20 <= 0 )
break;
else
V_18 = V_19 ;
} else {
V_18 = V_17 . V_27 ;
if ( V_18 > ( V_10 - V_21 ) ) {
V_18 -= ( V_10 - V_21 ) ;
if ( V_18 > V_33 ||
V_10 + V_18 < V_10 ) {
F_5 ( V_22 , V_25 ) ;
goto V_11;
}
if ( ! F_16 ( V_4 , V_10 + V_18 ) ) {
F_5 ( V_22 , V_23 ) ;
goto V_11;
}
while ( V_18 > 0 ) {
V_16 = F_17 ( V_2 , & ( V_4 -> V_12 [ V_10 ] ) , V_18 ) ;
if ( V_16 <= 0 ) {
F_5 ( V_22 ,
V_24 ) ;
goto V_11;
}
V_10 += V_16 ;
V_18 -= V_16 ;
}
}
if ( V_21 + V_17 . V_27 < V_21 ) {
F_5 ( V_22 , V_25 ) ;
goto V_11;
}
V_21 += V_17 . V_27 ;
if ( V_20 <= 0 ) {
break;
} else
V_18 = V_19 ;
}
}
if ( V_21 > V_33 ) {
F_5 ( V_22 , V_25 ) ;
goto V_11;
}
* V_15 = V_4 ;
return V_21 ;
V_11:
if ( V_4 != NULL )
F_10 ( V_4 ) ;
return - 1 ;
}
