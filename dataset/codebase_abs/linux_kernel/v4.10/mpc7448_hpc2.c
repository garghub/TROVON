int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_3 == 0 && F_2 ( V_4 ) == 0 )
return V_5 ;
else
return V_6 ;
}
static void T_2 F_3 ( void )
{
struct V_7 * V_8 ;
if ( V_9 . V_10 )
V_9 . V_10 ( L_1 , 0 ) ;
V_11 = F_4 () ;
#ifdef F_5
F_6 (np, L_2 , L_3 )
F_7 ( V_8 , V_12 , 0 ) ;
V_9 . V_13 = F_1 ;
if ( V_9 . V_10 )
V_9 . V_10 ( L_4 , 0x100 ) ;
#endif
F_8 ( V_14 L_5 ) ;
F_8 ( V_14
L_6 ) ;
F_8 ( V_14
L_7 ) ;
}
static void T_2 F_9 ( void )
{
struct V_15 * V_15 ;
#ifdef F_5
unsigned int V_16 ;
struct V_7 * V_17 ;
struct V_7 * V_18 = NULL ;
#endif
V_15 = F_10 ( NULL , 0 , V_19 |
V_20 | V_21 | V_22 ,
24 , 0 ,
L_8 ) ;
F_11 ( V_15 == NULL ) ;
F_12 ( V_15 , 0 , V_15 -> V_23 + 0x100 ) ;
F_13 ( V_15 ) ;
#ifdef F_5
V_17 = F_14 ( NULL , L_2 ) ;
if ( V_17 == NULL ) {
F_8 ( L_9 , V_24 ) ;
return;
}
V_18 = F_14 ( NULL , L_10 ) ;
if ( V_18 == NULL ) {
F_8 ( L_11 , V_24 ) ;
return;
}
V_16 = F_15 ( V_17 , 0 ) ;
F_16 ( L_12 , V_24 ,
( V_25 ) V_16 ) ;
F_17 ( V_18 ) ;
F_18 ( V_16 , V_15 ) ;
F_19 ( V_16 , V_26 ) ;
#endif
F_20 ( V_27 + 0x30c , 0 ) ;
}
void F_21 ( struct V_28 * V_29 )
{
F_22 ( V_29 , L_13 ) ;
}
static void T_3 F_23 ( char * V_30 )
{
F_24 () ;
F_25 ( 0 , V_31 ) ;
for (; ; ) ;
}
static int T_2 F_26 ( void )
{
if ( ! F_27 ( L_14 ) )
return 0 ;
return 1 ;
}
static int F_28 ( struct V_32 * V_33 )
{
const struct V_34 * V_35 ;
if ( ( V_35 = F_29 ( V_33 -> V_36 ) ) != NULL ) {
F_30 () ;
V_33 -> V_37 |= V_38 ;
V_33 -> V_36 = F_31 ( V_35 ) ;
return 1 ;
}
return 0 ;
}
