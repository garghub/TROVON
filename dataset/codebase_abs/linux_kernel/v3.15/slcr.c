static int F_1 ( T_1 V_1 , T_1 V_2 )
{
if ( ! V_3 ) {
F_2 ( V_1 , V_4 + V_2 ) ;
return 0 ;
}
return F_3 ( V_3 , V_2 , V_1 ) ;
}
static int F_4 ( T_1 * V_1 , T_1 V_2 )
{
if ( V_3 )
return F_5 ( V_3 , V_2 , V_1 ) ;
* V_1 = F_6 ( V_4 + V_2 ) ;
return 0 ;
}
static inline int F_7 ( void )
{
F_1 ( V_5 , V_6 ) ;
return 0 ;
}
void F_8 ( void )
{
T_1 V_7 ;
F_7 () ;
F_4 ( & V_7 , V_8 ) ;
F_1 ( V_7 & 0xF0FFFFFF , V_8 ) ;
F_1 ( 1 , V_9 ) ;
}
void F_9 ( int V_10 )
{
T_1 V_11 ;
F_4 ( & V_11 , V_12 ) ;
V_11 &= ~ ( V_13 << V_10 ) ;
F_1 ( V_11 , V_12 ) ;
V_11 &= ~ ( V_14 << V_10 ) ;
F_1 ( V_11 , V_12 ) ;
}
void F_10 ( int V_10 )
{
T_1 V_11 ;
F_4 ( & V_11 , V_12 ) ;
V_11 |= ( V_14 | V_13 ) << V_10 ;
F_1 ( V_11 , V_12 ) ;
}
int T_2 F_11 ( void )
{
V_3 = F_12 ( L_1 ) ;
if ( F_13 ( V_3 ) ) {
F_14 ( L_2 , V_15 ) ;
return - V_16 ;
}
return 0 ;
}
int T_2 F_15 ( void )
{
struct V_17 * V_18 ;
V_18 = F_16 ( NULL , NULL , L_1 ) ;
if ( ! V_18 ) {
F_14 ( L_3 , V_15 ) ;
F_17 () ;
}
V_4 = F_18 ( V_18 , 0 ) ;
if ( ! V_4 ) {
F_14 ( L_4 , V_15 ) ;
F_17 () ;
}
V_18 -> V_19 = ( V_20 void * ) V_4 ;
F_7 () ;
F_19 ( L_5 , V_18 -> V_21 , V_4 ) ;
F_20 ( V_18 ) ;
return 0 ;
}
