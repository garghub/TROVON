static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
int T_1 F_3 ( void )
{
void * V_3 = ( void * ) F_4 ( V_4 ) ;
V_5 [ 0 ] = F_5 ( V_3 ) ;
memcpy ( V_3 ,
& V_6 ,
& V_7 - & V_6 ) ;
return 0 ;
}
int F_6 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
unsigned long V_14 ;
int V_15 ;
F_7 ( & V_12 -> V_16 ) ;
V_14 = F_8 ( NULL , 0 , V_17 , 0 , 0 ) ;
if ( F_9 ( V_14 ) ) {
V_15 = V_14 ;
goto V_18;
}
V_15 = F_10 ( V_12 , V_14 , V_17 ,
V_19 | V_20 |
V_21 | V_22 | V_23 ,
V_5 ) ;
if ( F_11 ( V_15 ) )
goto V_18;
V_13 -> V_12 -> V_24 . V_25 = ( void * ) V_14 ;
V_18:
F_12 ( & V_12 -> V_16 ) ;
return V_15 ;
}
const char * F_13 ( struct V_26 * V_27 )
{
if ( V_27 -> V_28 && V_27 -> V_29 == ( long ) V_27 -> V_28 -> V_24 . V_25 )
return L_1 ;
return NULL ;
}
