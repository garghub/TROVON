static void T_1 F_1 ( T_2 V_1 , unsigned int V_2 ,
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
int T_1 F_5 ( unsigned long V_15 , const char * V_16 ,
int V_17 , void * V_18 )
{
const T_3 * V_19 ;
int V_20 ;
struct V_21 V_22 ;
if ( ! V_18 )
return 0 ;
if ( ! F_6 ( V_15 , V_18 ) )
return 0 ;
V_19 = F_7 ( V_15 , L_2 , & V_20 ) ;
if ( ! V_19 || ( V_20 != 2 * sizeof( unsigned long ) ) )
return 0 ;
V_22 . V_23 = F_8 ( V_19 [ 0 ] ) ;
V_22 . V_4 = F_8 ( V_19 [ 1 ] ) ;
V_19 = F_7 ( V_15 , L_3 , & V_20 ) ;
if ( ! V_19 || ( V_20 != 2 * sizeof( unsigned long ) ) )
return 0 ;
V_22 . V_24 = F_8 ( V_19 [ 0 ] ) ;
V_22 . V_2 = F_8 ( V_19 [ 1 ] ) ;
F_1 ( V_22 . V_24 , V_22 . V_2 ,
V_22 . V_23 , V_22 . V_4 ) ;
return 1 ;
}
