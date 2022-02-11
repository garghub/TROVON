static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
void T_1 __weak F_2 ( void )
{
}
void T_1 F_3 ( void )
{
F_2 () ;
V_3 = 1 ;
}
static inline void T_1 F_4 ( enum V_4 V_5 ,
T_2 V_6 , T_3 V_7 )
{
F_5 () ;
}
static inline void T_1 F_6 ( enum V_4 V_5 )
{
F_5 () ;
}
void T_1 F_7 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
if ( F_8 ( V_10 [ V_8 ] ) )
break;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
V_11 [ V_8 ] = F_9 ( V_12 - V_13 * V_8 ) ;
}
static int T_1 F_10 ( void )
{
int V_14 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
if ( V_10 [ V_8 ] )
V_14 ++ ;
if ( F_11 ( V_14 , V_15
L_1
L_2 ,
V_14 ) )
return 1 ;
return 0 ;
}
static void T_1 T_4 *
F_12 ( T_5 V_16 , unsigned long V_17 , T_3 V_7 )
{
unsigned long V_18 ;
T_5 V_19 ;
unsigned int V_20 ;
enum V_4 V_5 ;
int V_8 , V_21 ;
F_8 ( V_22 != V_23 ) ;
V_21 = - 1 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( ! V_10 [ V_8 ] ) {
V_21 = V_8 ;
break;
}
}
if ( F_11 ( V_21 < 0 , L_3 ,
V_24 , ( V_25 ) V_16 , V_17 ) )
return NULL ;
V_19 = V_16 + V_17 - 1 ;
if ( F_8 ( ! V_17 || V_19 < V_16 ) )
return NULL ;
V_26 [ V_21 ] = V_17 ;
V_18 = F_13 ( V_16 ) ;
V_16 &= V_27 ;
V_17 = F_14 ( V_19 + 1 ) - V_16 ;
V_20 = V_17 >> V_28 ;
if ( F_8 ( V_20 > V_13 ) )
return NULL ;
V_5 = V_12 - V_13 * V_21 ;
while ( V_20 > 0 ) {
if ( V_3 )
F_4 ( V_5 , V_16 , V_7 ) ;
else
F_15 ( V_5 , V_16 , V_7 ) ;
V_16 += V_29 ;
-- V_5 ;
-- V_20 ;
}
F_11 ( V_2 , L_4 ,
V_24 , ( V_25 ) V_16 , V_17 , V_21 , V_18 , V_11 [ V_21 ] ) ;
V_10 [ V_21 ] = ( void T_4 * ) ( V_18 + V_11 [ V_21 ] ) ;
return V_10 [ V_21 ] ;
}
void T_1 F_16 ( void T_4 * V_30 , unsigned long V_17 )
{
unsigned long V_31 ;
unsigned long V_18 ;
unsigned int V_20 ;
enum V_4 V_5 ;
int V_8 , V_21 ;
V_21 = - 1 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( V_10 [ V_8 ] == V_30 ) {
V_21 = V_8 ;
break;
}
}
if ( F_11 ( V_21 < 0 , L_5 ,
V_30 , V_17 ) )
return;
if ( F_11 ( V_26 [ V_21 ] != V_17 ,
L_6 ,
V_30 , V_17 , V_21 , V_26 [ V_21 ] ) )
return;
F_11 ( V_2 , L_7 ,
V_30 , V_17 , V_21 ) ;
V_31 = ( unsigned long ) V_30 ;
if ( F_8 ( V_31 < F_17 ( V_12 ) ) )
return;
V_18 = F_13 ( V_31 ) ;
V_20 = F_14 ( V_18 + V_17 ) >> V_28 ;
V_5 = V_12 - V_13 * V_21 ;
while ( V_20 > 0 ) {
if ( V_3 )
F_6 ( V_5 ) ;
else
F_15 ( V_5 , 0 , V_32 ) ;
-- V_5 ;
-- V_20 ;
}
V_10 [ V_21 ] = NULL ;
}
void T_1 T_4 *
F_18 ( T_5 V_16 , unsigned long V_17 )
{
return F_12 ( V_16 , V_17 , V_33 ) ;
}
void T_1 *
F_19 ( T_5 V_16 , unsigned long V_17 )
{
return ( V_34 void * ) F_12 ( V_16 , V_17 ,
V_35 ) ;
}
void T_1 *
F_20 ( T_5 V_16 , unsigned long V_17 )
{
return ( V_34 void * ) F_12 ( V_16 , V_17 , V_36 ) ;
}
void T_1 F_21 ( void * V_37 , T_2 V_38 , unsigned long V_17 )
{
unsigned long V_39 , V_40 ;
char * V_41 ;
while ( V_17 ) {
V_39 = F_13 ( V_38 ) ;
V_40 = V_17 ;
if ( V_40 > V_42 - V_39 )
V_40 = V_42 - V_39 ;
V_41 = F_19 ( V_38 & V_27 , V_40 + V_39 ) ;
memcpy ( V_37 , V_41 + V_39 , V_40 ) ;
F_22 ( V_41 , V_40 + V_39 ) ;
V_37 += V_40 ;
V_38 += V_40 ;
V_17 -= V_40 ;
}
}
void T_1 T_4 *
F_18 ( T_5 V_16 , unsigned long V_17 )
{
return ( V_34 void T_4 * ) V_16 ;
}
void T_1 *
F_19 ( T_5 V_16 , unsigned long V_17 )
{
return ( void * ) V_16 ;
}
void T_1 *
F_20 ( T_5 V_16 , unsigned long V_17 )
{
return ( void * ) V_16 ;
}
void T_1 F_16 ( void T_4 * V_30 , unsigned long V_17 )
{
}
void T_1 F_22 ( void * V_30 , unsigned long V_17 )
{
F_16 ( ( V_34 void T_4 * ) V_30 , V_17 ) ;
}
