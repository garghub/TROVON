static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
T_2 T_1 __weak F_2 ( T_3 V_3 ,
unsigned long V_4 ,
T_2 V_5 )
{
return V_5 ;
}
void T_1 __weak F_3 ( void )
{
}
void T_1 F_4 ( void )
{
F_3 () ;
V_6 = 1 ;
}
static inline void T_1 F_5 ( enum V_7 V_8 ,
T_4 V_9 , T_2 V_5 )
{
F_6 () ;
}
static inline void T_1 F_7 ( enum V_7 V_8 )
{
F_6 () ;
}
void T_1 F_8 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( F_9 ( V_12 [ V_10 ] ) )
break;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_13 [ V_10 ] = F_10 ( V_14 - V_15 * V_10 ) ;
}
static int T_1 F_11 ( void )
{
int V_16 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
if ( V_12 [ V_10 ] )
V_16 ++ ;
if ( F_12 ( V_16 , V_17
L_1
L_2 ,
V_16 ) )
return 1 ;
return 0 ;
}
static void T_1 T_5 *
F_13 ( T_3 V_3 , unsigned long V_4 , T_2 V_5 )
{
unsigned long V_18 ;
T_3 V_19 ;
unsigned int V_20 ;
enum V_7 V_8 ;
int V_10 , V_21 ;
F_9 ( V_22 != V_23 ) ;
V_21 = - 1 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ! V_12 [ V_10 ] ) {
V_21 = V_10 ;
break;
}
}
if ( F_12 ( V_21 < 0 , L_3 ,
V_24 , ( V_25 ) V_3 , V_4 ) )
return NULL ;
V_19 = V_3 + V_4 - 1 ;
if ( F_9 ( ! V_4 || V_19 < V_3 ) )
return NULL ;
V_26 [ V_21 ] = V_4 ;
V_18 = F_14 ( V_3 ) ;
V_3 &= V_27 ;
V_4 = F_15 ( V_19 + 1 ) - V_3 ;
V_20 = V_4 >> V_28 ;
if ( F_9 ( V_20 > V_15 ) )
return NULL ;
V_8 = V_14 - V_15 * V_21 ;
while ( V_20 > 0 ) {
if ( V_6 )
F_5 ( V_8 , V_3 , V_5 ) ;
else
F_16 ( V_8 , V_3 , V_5 ) ;
V_3 += V_29 ;
-- V_8 ;
-- V_20 ;
}
F_12 ( V_2 , L_4 ,
V_24 , ( V_25 ) V_3 , V_4 , V_21 , V_18 , V_13 [ V_21 ] ) ;
V_12 [ V_21 ] = ( void T_5 * ) ( V_18 + V_13 [ V_21 ] ) ;
return V_12 [ V_21 ] ;
}
void T_1 F_17 ( void T_5 * V_30 , unsigned long V_4 )
{
unsigned long V_31 ;
unsigned long V_18 ;
unsigned int V_20 ;
enum V_7 V_8 ;
int V_10 , V_21 ;
V_21 = - 1 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_12 [ V_10 ] == V_30 ) {
V_21 = V_10 ;
break;
}
}
if ( F_12 ( V_21 < 0 , L_5 ,
V_30 , V_4 ) )
return;
if ( F_12 ( V_26 [ V_21 ] != V_4 ,
L_6 ,
V_30 , V_4 , V_21 , V_26 [ V_21 ] ) )
return;
F_12 ( V_2 , L_7 ,
V_30 , V_4 , V_21 ) ;
V_31 = ( unsigned long ) V_30 ;
if ( F_9 ( V_31 < F_18 ( V_14 ) ) )
return;
V_18 = F_14 ( V_31 ) ;
V_20 = F_15 ( V_18 + V_4 ) >> V_28 ;
V_8 = V_14 - V_15 * V_21 ;
while ( V_20 > 0 ) {
if ( V_6 )
F_7 ( V_8 ) ;
else
F_16 ( V_8 , 0 , V_32 ) ;
-- V_8 ;
-- V_20 ;
}
V_12 [ V_21 ] = NULL ;
}
void T_1 T_5 *
F_19 ( T_3 V_3 , unsigned long V_4 )
{
return F_13 ( V_3 , V_4 , V_33 ) ;
}
void T_1 *
F_20 ( T_3 V_3 , unsigned long V_4 )
{
T_2 V_5 = F_2 ( V_3 , V_4 ,
V_34 ) ;
return ( V_35 void * ) F_13 ( V_3 , V_4 , V_5 ) ;
}
void T_1 *
F_21 ( T_3 V_3 , unsigned long V_4 )
{
T_2 V_5 = F_2 ( V_3 , V_4 ,
V_36 ) ;
return ( V_35 void * ) F_13 ( V_3 , V_4 , V_5 ) ;
}
void T_1 *
F_22 ( T_3 V_3 , unsigned long V_4 ,
unsigned long V_37 )
{
return ( V_35 void * ) F_13 ( V_3 , V_4 ,
F_23 ( V_37 ) ) ;
}
void T_1 F_24 ( void * V_38 , T_4 V_39 , unsigned long V_4 )
{
unsigned long V_40 , V_41 ;
char * V_42 ;
while ( V_4 ) {
V_40 = F_14 ( V_39 ) ;
V_41 = V_4 ;
if ( V_41 > V_43 - V_40 )
V_41 = V_43 - V_40 ;
V_42 = F_20 ( V_39 & V_27 , V_41 + V_40 ) ;
memcpy ( V_38 , V_42 + V_40 , V_41 ) ;
F_25 ( V_42 , V_41 + V_40 ) ;
V_38 += V_41 ;
V_39 += V_41 ;
V_4 -= V_41 ;
}
}
void T_1 T_5 *
F_19 ( T_3 V_3 , unsigned long V_4 )
{
return ( V_35 void T_5 * ) V_3 ;
}
void T_1 *
F_20 ( T_3 V_3 , unsigned long V_4 )
{
return ( void * ) V_3 ;
}
void T_1 *
F_21 ( T_3 V_3 , unsigned long V_4 )
{
return ( void * ) V_3 ;
}
void T_1 F_17 ( void T_5 * V_30 , unsigned long V_4 )
{
}
void T_1 F_25 ( void * V_30 , unsigned long V_4 )
{
F_17 ( ( V_35 void T_5 * ) V_30 , V_4 ) ;
}
