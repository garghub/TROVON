bool F_1 ( T_1 V_1 , T_2 V_2 , unsigned long V_3 )
{
if ( V_2 & V_4 )
return false ;
if ( V_5 . V_6 && ( V_2 & V_7 ) )
return false ;
if ( V_5 . V_8 && ! ( V_3 & V_9 ) )
return false ;
return F_2 ( & V_5 . V_10 , V_1 ) ;
}
static int T_3 F_3 ( char * V_11 )
{
return F_4 ( & V_5 . V_10 , V_11 ) ;
}
static int T_3 F_5 ( void )
{
T_4 V_12 = V_13 | V_14 | V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_18 = F_6 ( & V_5 . V_10 , L_1 ) ;
if ( V_18 )
return V_18 ;
V_17 = V_5 . V_10 . V_19 . V_17 ;
V_5 . V_20 =
F_7 ( L_2 , V_12 , V_17 ,
& V_5 . V_6 ) ;
V_5 . V_21 =
F_7 ( L_3 , V_12 , V_17 ,
& V_5 . V_8 ) ;
if ( ! V_5 . V_20 ||
! V_5 . V_21 ) {
V_18 = - V_22 ;
F_8 ( V_5 . V_21 ) ;
F_8 ( V_5 . V_20 ) ;
F_9 ( & V_5 . V_10 ) ;
}
return V_18 ;
}
