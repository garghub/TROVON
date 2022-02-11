static void F_1 ( enum V_1 V_2 )
{
if ( V_2 != V_3 ) {
F_2 ( L_1 , V_2 ) ;
return;
}
}
void F_3 ( unsigned int V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 T_1 * V_8 ;
unsigned long V_9 ;
T_2 V_10 ;
T_3 V_11 ;
V_6 = F_4 ( NULL , NULL , L_2 ) ;
if ( ! V_6 ) {
F_2 ( L_3 ) ;
return;
}
V_8 = F_5 ( V_6 , 0 ) ;
F_6 ( V_6 ) ;
if ( ! V_8 ) {
F_2 ( L_4 ) ;
return;
}
V_10 = 1000000000000ULL ;
F_7 ( V_10 , V_4 ) ;
V_9 = V_10 ;
V_11 = F_8 ( F_9 () , V_9 ) ;
V_11 = F_10 ( T_3 , V_11 , 2 , 255 ) ;
F_11 ( & V_8 -> V_12 ,
V_13 | V_14 | V_15 ) ;
F_12 ( & V_8 -> V_12 , V_13 | ( V_11 << 16 ) ) ;
F_13 ( V_8 ) ;
}
enum V_1
F_14 ( enum V_1 V_2 )
{
return V_3 ;
}
void T_4 F_15 ( void )
{
struct V_16 * V_16 = F_16 ( NULL , 0 , V_17 |
V_18 ,
0 , 256 , L_5 ) ;
F_17 ( V_16 == NULL ) ;
F_18 ( V_16 ) ;
}
static void T_4 F_19 ( void )
{
if ( V_19 . V_20 )
V_19 . V_20 ( L_6 , 0 ) ;
#if F_20 ( V_21 ) || F_20 ( V_22 )
V_23 . V_24 = F_1 ;
V_23 . V_25 = F_3 ;
V_23 . V_26 = F_14 ;
#endif
F_21 () ;
F_22 () ;
F_23 () ;
F_24 ( L_7 ) ;
}
static int T_4 F_25 ( void )
{
unsigned long V_27 = F_26 () ;
return F_27 ( V_27 , L_8 ) ;
}
