void F_1 ( void )
{
struct V_1 * V_2 ;
void T_1 * V_3 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
return;
}
V_3 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_3 ) {
F_3 ( L_3 ) ;
return;
}
F_6 ( V_4 , V_3 ) ;
F_6 ( V_5 , V_3 ) ;
F_7 ( V_3 ) ;
}
static inline void F_8 ( T_2 V_6 , void T_1 * V_7 )
{
T_2 V_8 = F_9 ( V_7 ) ;
V_8 |= V_6 ;
F_6 ( V_8 , V_7 ) ;
}
static inline void F_10 ( T_2 V_6 , void T_1 * V_7 )
{
T_2 V_8 = F_9 ( V_7 ) ;
V_8 &= ~ V_6 ;
F_6 ( V_8 , V_7 ) ;
}
static inline int F_11 ( T_2 V_6 , void T_1 * V_7 )
{
T_2 V_8 = F_9 ( V_7 ) ;
return ( V_8 & V_6 ) ? 1 : 0 ;
}
static int F_12 ( void T_1 * V_7 )
{
int V_9 = V_10 ;
F_8 ( V_11 , ( V_7 + V_12 ) ) ;
while ( V_9 -- ) {
if ( F_11 ( V_13 ,
( V_7 + V_14 ) ) )
break;
F_13 ( 1 ) ;
}
if ( V_9 < 0 )
return - V_15 ;
F_6 ( V_16 ,
( V_7 + V_17 ) ) ;
return 0 ;
}
void F_14 ( void )
{
struct V_1 * V_2 ;
int V_18 = 0 ;
void T_1 * V_19 ;
if ( ! V_20 ) {
F_3 ( L_4 ) ;
return;
}
V_2 = F_2 ( NULL , NULL , L_5 ) ;
if ( ! V_2 ) {
F_3 ( L_6 ) ;
return;
}
V_19 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_19 ) {
F_3 ( L_7 ) ;
return;
}
F_6 ( V_21 ,
V_20 + V_22 ) ;
F_10 ( V_23 ,
( V_19 + V_24 ) ) ;
F_10 ( V_21 ,
( V_19 + V_12 ) ) ;
F_15 () ;
V_18 = F_12 ( V_19 ) ;
if ( V_18 ) {
F_3 ( L_8 ) ;
goto exit;
}
F_8 ( V_21 ,
( V_19 + V_12 ) ) ;
F_8 ( V_23 ,
( V_19 + V_24 ) ) ;
F_6 ( V_21 ,
V_20 + V_25 ) ;
F_15 () ;
exit:
F_7 ( V_19 ) ;
}
