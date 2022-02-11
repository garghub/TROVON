void T_1 F_1 ( T_2 V_1 , unsigned int V_2 ,
T_2 V_3 , unsigned int V_4 )
{
int V_5 ;
V_6 [ 0 ] . V_7 = & V_8 . V_7 ;
V_6 [ 0 ] . V_9 = V_1 ;
V_6 [ 0 ] . V_10 = V_2 ;
V_6 [ 1 ] . V_7 = & V_11 . V_7 ;
V_6 [ 1 ] . V_9 = V_3 ;
V_6 [ 1 ] . V_10 = V_4 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
struct V_12 * V_13 = & V_6 [ V_5 ] ;
if ( F_3 ( V_13 -> V_9 , V_13 -> V_10 ) ) {
F_4 ( V_14 L_1 ,
V_13 -> V_10 , ( unsigned long ) V_13 -> V_9 ) ;
V_13 -> V_9 = 0 ;
}
}
}
static int T_1 F_5 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
struct V_12 * V_13 = & V_6 [ V_5 ] ;
if ( ! V_13 -> V_9 )
continue;
if ( F_6 ( V_13 -> V_7 , V_13 -> V_9 ,
V_13 -> V_9 , V_13 -> V_10 ,
V_15 | V_16 ) == 0 )
F_4 ( V_14 L_2 ,
V_13 -> V_10 , ( unsigned long ) V_13 -> V_9 ) ;
}
return 0 ;
}
int T_1 F_7 ( unsigned long V_17 , const char * V_18 ,
int V_19 , void * V_20 )
{
T_3 * V_21 ;
unsigned long V_22 ;
struct V_23 * V_24 = V_20 ;
if ( ! V_20 )
return 0 ;
if ( ! F_8 ( V_17 , V_24 -> V_25 ) )
return 0 ;
V_21 = F_9 ( V_17 , L_3 , & V_22 ) ;
if ( ! V_21 || ( V_22 != 2 * sizeof( unsigned long ) ) )
return 0 ;
V_24 -> V_26 = F_10 ( V_21 [ 0 ] ) ;
V_24 -> V_4 = F_10 ( V_21 [ 1 ] ) ;
V_21 = F_9 ( V_17 , L_4 , & V_22 ) ;
if ( ! V_21 || ( V_22 != 2 * sizeof( unsigned long ) ) )
return 0 ;
V_24 -> V_27 = F_10 ( V_21 [ 0 ] ) ;
V_24 -> V_2 = F_10 ( V_21 [ 1 ] ) ;
return 1 ;
}
