static T_1
F_1 ( T_2 V_1 , T_3 V_2 ,
T_2 V_3 , T_4 * V_4 ,
void * V_5 , void * V_6 )
{
int V_7 ;
T_5 * V_8 = ( T_5 * ) & V_4 ;
if ( V_2 > 0xff || ! V_4 )
return V_9 ;
if ( V_1 != V_10 && V_1 != V_11 )
return V_9 ;
F_2 ( & V_12 ) ;
for ( V_7 = 0 ; V_7 < F_3 ( V_3 , 8 ) ; ++ V_7 , ++ V_2 , ++ V_8 )
if ( V_1 == V_11 )
* V_8 = F_4 ( V_2 ) ;
else
F_5 ( * V_8 , V_2 ) ;
F_6 ( & V_12 ) ;
return V_13 ;
}
static int F_7 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
T_1 V_18 ;
V_18 = F_8 ( V_15 -> V_19 ,
V_20 ,
& F_1 ,
NULL , NULL ) ;
if ( F_9 ( V_18 ) ) {
F_10 ( V_21 L_1 ) ;
return - V_22 ;
}
return 1 ;
}
static void F_11 ( struct V_14 * V_15 )
{
if ( F_9 ( F_12 ( V_15 -> V_19 ,
V_20 , & F_1 ) ) )
F_10 ( V_21 L_2 ) ;
}
void T_6 F_13 ( void )
{
F_14 ( & V_23 ) ;
}
