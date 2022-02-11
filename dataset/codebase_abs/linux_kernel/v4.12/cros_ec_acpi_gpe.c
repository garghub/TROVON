static T_1 F_1 ( T_2 V_1 , T_1 V_2 ,
void * V_3 )
{
return V_4 | V_5 ;
}
static int F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_8 * V_10 ;
T_2 V_11 ;
T_3 V_12 ;
int V_13 ;
V_9 = F_3 ( V_7 ) ;
if ( ! V_9 || ! V_9 -> V_14 ||
! V_9 -> V_14 -> V_11 )
return - V_15 ;
V_12 = F_4 ( V_9 -> V_14 -> V_11 , V_16 ,
& V_11 ) ;
if ( F_5 ( V_12 ) )
return - V_15 ;
V_13 = F_6 ( V_11 , & V_10 ) ;
if ( V_13 )
return V_13 ;
return V_10 -> V_17 . V_2 ;
}
int F_7 ( struct V_6 * V_7 )
{
T_3 V_12 ;
V_18 = F_2 ( V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
V_12 = F_8 ( NULL , V_18 ,
V_19 ,
& F_1 , NULL ) ;
if ( F_5 ( V_12 ) )
return - V_20 ;
F_9 ( V_7 , L_1 , V_18 ) ;
return 0 ;
}
void F_10 ( void )
{
T_3 V_12 ;
if ( V_18 < 0 )
return;
V_12 = F_11 ( NULL , V_18 ,
& F_1 ) ;
if ( F_5 ( V_12 ) )
F_12 ( L_2 ) ;
}
void F_13 ( void )
{
if ( V_18 < 0 )
return;
F_14 ( NULL , V_18 ) ;
}
