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
T_3 V_16 = 0 ;
struct V_7 * V_17 ;
#ifdef F_5
unsigned int V_18 ;
struct V_7 * V_19 ;
struct V_7 * V_20 = NULL ;
#endif
V_17 = F_10 ( NULL , L_8 ) ;
if ( V_17 ) {
unsigned int V_21 ;
const void * V_22 = F_11 ( V_17 , L_9 , & V_21 ) ;
V_16 = F_12 ( V_17 , V_22 ) ;
}
if ( V_16 == 0 ) {
F_8 ( L_10 , V_23 ) ;
return;
}
F_13 ( L_11 , V_23 ,
( V_24 ) V_16 ) ;
V_15 = F_14 ( V_17 , V_16 ,
V_25 | V_26 | V_27 |
V_28 | V_29 | V_30 ,
24 ,
V_31 - 4 ,
L_12 ) ;
F_15 ( V_15 == NULL ) ;
F_16 ( V_15 , 0 , V_16 + 0x100 ) ;
F_17 ( V_15 ) ;
#ifdef F_5
V_19 = F_10 ( NULL , L_2 ) ;
if ( V_19 == NULL ) {
F_8 ( L_13 , V_23 ) ;
return;
}
V_20 = F_10 ( NULL , L_14 ) ;
if ( V_20 == NULL ) {
F_8 ( L_15 , V_23 ) ;
return;
}
V_18 = F_18 ( V_19 , 0 ) ;
F_13 ( L_16 , V_23 ,
( V_24 ) V_18 ) ;
F_19 ( V_20 ) ;
F_20 ( V_18 , V_15 ) ;
F_21 ( V_18 , V_32 ) ;
#endif
F_22 ( V_33 + 0x30c , 0 ) ;
F_23 ( V_17 ) ;
}
void F_24 ( struct V_34 * V_35 )
{
F_25 ( V_35 , L_17 ) ;
}
void F_26 ( char * V_36 )
{
F_27 () ;
F_28 ( 0 , V_37 ) ;
for (; ; ) ;
}
void F_29 ( void )
{
F_27 () ;
for (; ; ) ;
}
void F_30 ( void )
{
F_29 () ;
}
static int T_2 F_31 ( void )
{
unsigned long V_38 = F_32 () ;
if ( ! F_33 ( V_38 , L_18 ) )
return 0 ;
return 1 ;
}
static int F_34 ( struct V_39 * V_40 )
{
const struct V_41 * V_42 ;
if ( ( V_42 = F_35 ( V_40 -> V_43 ) ) != NULL ) {
F_36 () ;
V_40 -> V_44 |= V_45 ;
V_40 -> V_43 = V_42 -> V_46 ;
return 1 ;
}
return 0 ;
}
