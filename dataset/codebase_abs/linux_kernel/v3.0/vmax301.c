static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_2 ( V_3 , V_2 -> V_4 - V_5 ) ;
V_2 -> V_6 = V_3 ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
unsigned long V_3 = ( V_7 >> V_8 ) ;
if ( V_2 -> V_6 != V_3 )
F_1 ( V_2 , V_3 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , unsigned long V_7 )
{
T_1 V_9 ;
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_7 ) ;
V_9 . V_11 [ 0 ] = F_6 ( V_2 -> V_4 + ( V_7 & V_12 ) ) ;
F_7 ( & V_10 ) ;
return V_9 ;
}
static void F_8 ( struct V_1 * V_2 , void * V_13 , unsigned long V_14 , T_2 V_15 )
{
while( V_15 ) {
unsigned long V_16 = V_15 ;
if ( V_15 > ( V_5 - ( V_14 & V_12 ) ) )
V_16 = V_5 - ( V_14 & V_12 ) ;
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_14 ) ;
F_9 ( V_13 , V_2 -> V_4 + V_14 , V_16 ) ;
F_7 ( & V_10 ) ;
V_13 += V_16 ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
}
static void F_10 ( struct V_1 * V_2 , T_1 V_17 , unsigned long V_18 )
{
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_18 ) ;
F_11 ( V_17 . V_11 [ 0 ] , V_2 -> V_4 + ( V_18 & V_12 ) ) ;
F_7 ( & V_10 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned long V_13 , const void * V_14 , T_2 V_15 )
{
while( V_15 ) {
unsigned long V_16 = V_15 ;
if ( V_15 > ( V_5 - ( V_13 & V_12 ) ) )
V_16 = V_5 - ( V_13 & V_12 ) ;
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_13 ) ;
F_13 ( V_2 -> V_4 + V_13 , V_14 , V_16 ) ;
F_7 ( & V_10 ) ;
V_13 += V_16 ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
}
static void T_3 F_14 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
if ( V_20 [ V_19 ] ) {
F_15 ( V_20 [ V_19 ] ) ;
F_16 ( V_20 [ V_19 ] ) ;
}
}
F_17 ( ( void * ) V_21 [ 0 ] . V_6 - V_22 ) ;
}
static int T_4 F_18 ( void )
{
int V_19 ;
unsigned long V_23 ;
F_19 ( L_1 , V_22 ,
V_22 + 4 * V_5 ) ;
V_23 = ( unsigned long ) F_20 ( V_22 , V_5 * 4 ) ;
if ( ! V_23 ) {
F_19 ( L_2 ) ;
return - V_24 ;
}
V_21 [ 0 ] . V_4 = V_23 + V_22 ;
V_21 [ 1 ] . V_4 = V_23 + ( 3 * V_22 ) ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
V_20 [ V_19 ] = F_21 ( L_3 , & V_21 [ V_19 ] ) ;
if ( ! V_20 [ V_19 ] )
V_20 [ V_19 ] = F_21 ( L_4 , & V_21 [ V_19 ] ) ;
if ( ! V_20 [ V_19 ] )
V_20 [ V_19 ] = F_21 ( L_5 , & V_21 [ V_19 ] ) ;
if ( ! V_20 [ V_19 ] )
V_20 [ V_19 ] = F_21 ( L_6 , & V_21 [ V_19 ] ) ;
if ( V_20 [ V_19 ] ) {
V_20 [ V_19 ] -> V_25 = V_26 ;
F_22 ( V_20 [ V_19 ] , NULL , 0 ) ;
}
}
if ( ! V_20 [ 0 ] && ! V_20 [ 1 ] ) {
F_17 ( ( void * ) V_23 ) ;
return - V_27 ;
}
return 0 ;
}
