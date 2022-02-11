static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_3 = F_2 ( V_4 ) ;
if ( ! V_3 )
F_3 ( L_1 ) ;
V_2 = F_4 ( & V_3 , 1 , 0 , V_5 ) ;
if ( ! V_2 )
F_3 ( L_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_6 [ 0 ] = V_7 [ 0 ] ;
V_2 -> V_6 [ 1 ] = V_7 [ 1 ] ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_7 ( struct V_8 * V_9 , int V_10 )
{
int V_11 ;
unsigned long V_12 ;
struct V_13 * V_14 = V_15 -> V_14 ;
F_8 ( & V_14 -> V_16 ) ;
V_12 = V_17 ;
V_12 = F_9 ( NULL , V_12 , V_18 , 0 , 0 ) ;
if ( F_10 ( V_12 ) ) {
V_11 = V_12 ;
goto V_19;
}
V_11 = F_11 ( V_14 , V_12 , V_18 ,
V_20 | V_21 |
V_22 | V_23 | V_24 ,
& V_3 ) ;
if ( V_11 )
goto V_19;
V_14 -> V_25 . V_2 = ( void * ) V_12 ;
V_19:
F_12 ( & V_14 -> V_16 ) ;
return V_11 ;
}
const char * F_13 ( struct V_26 * V_27 )
{
if ( V_27 -> V_28 && V_27 -> V_29 == ( long ) V_27 -> V_28 -> V_25 . V_2 )
return L_3 ;
return NULL ;
}
