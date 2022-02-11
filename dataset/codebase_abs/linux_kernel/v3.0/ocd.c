void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 )
F_2 ( L_1 ,
V_2 -> V_4 , V_2 -> V_5 ) ;
else
F_2 ( L_2 ) ;
if ( ! V_2 || ! F_3 ( V_2 , V_6 ) ) {
F_4 ( & V_7 ) ;
V_8 ++ ;
V_3 = F_5 ( V_9 ) ;
V_3 |= ( 1 << V_10 ) | ( 1 << V_11 ) ;
F_6 ( V_9 , V_3 ) ;
F_7 ( & V_7 ) ;
}
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! V_2 )
F_2 ( L_3 ) ;
else if ( F_9 ( V_2 , V_6 ) )
F_2 ( L_4 ,
V_2 -> V_4 , V_2 -> V_5 ) ;
if ( ! V_2 || F_10 ( V_2 , V_6 ) ) {
F_4 ( & V_7 ) ;
V_8 -- ;
F_11 ( V_8 < 0 ) ;
if ( V_8 <= 0 ) {
V_3 = F_5 ( V_9 ) ;
V_3 &= ~ ( ( 1 << V_10 ) | ( 1 << V_11 ) ) ;
F_6 ( V_9 , V_3 ) ;
}
F_7 ( & V_7 ) ;
}
}
static int F_12 ( void * V_12 , T_2 * V_13 )
{
* V_13 = F_5 ( V_9 ) ;
return 0 ;
}
static int F_13 ( void * V_12 , T_2 V_13 )
{
F_6 ( V_9 , V_13 ) ;
return 0 ;
}
static int F_14 ( void * V_12 , T_2 * V_13 )
{
* V_13 = F_5 ( V_14 ) ;
return 0 ;
}
static int F_15 ( void * V_12 , T_2 * V_13 )
{
* V_13 = V_8 ;
return 0 ;
}
static void F_16 ( void )
{
struct V_15 * V_16 ;
V_16 = F_17 ( L_5 , NULL ) ;
if ( F_18 ( V_16 ) || ! V_16 )
goto V_17;
V_18 = V_16 ;
V_19 = F_19 ( L_6 , V_20 | V_21 ,
V_16 , NULL , & V_22 ) ;
if ( ! V_19 )
goto V_23;
V_24 = F_19 ( L_7 , V_20 , V_16 ,
NULL , & V_25 ) ;
if ( ! V_24 )
goto V_26;
V_27 = F_19 ( L_8 , V_20 , V_16 ,
NULL , & V_28 ) ;
if ( ! V_27 )
goto V_29;
return;
V_29:
F_20 ( V_24 ) ;
V_26:
F_20 ( V_19 ) ;
V_23:
F_20 ( V_18 ) ;
V_17:
F_21 ( V_30 L_9 ) ;
}
static inline void F_16 ( void )
{
}
static int T_3 F_22 ( void )
{
F_23 ( & V_7 ) ;
F_16 () ;
return 0 ;
}
