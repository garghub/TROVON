void F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = NULL ;
struct V_4 T_1 * V_5 ;
unsigned long V_6 ;
T_2 V_7 ;
T_3 V_8 ;
V_3 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_3 ) {
F_3 ( L_2 ) ;
return;
}
V_5 = F_4 ( V_3 , 0 ) ;
F_5 ( V_3 ) ;
if ( ! V_5 ) {
F_3 ( L_3 ) ;
return;
}
V_7 = 1000000000000ULL ;
F_6 ( V_7 , V_1 ) ;
V_6 = V_7 ;
V_8 = F_7 ( F_8 () , V_6 ) ;
V_8 = F_9 ( T_3 , V_8 , 2 , 255 ) ;
F_10 ( & V_5 -> V_9 ,
V_10 | V_11 | V_12 ) ;
F_11 ( & V_5 -> V_9 , V_10 | ( V_8 << 16 ) ) ;
F_12 ( V_5 ) ;
}
enum V_13
F_13 ( enum V_13 V_14 )
{
return V_15 ;
}
void T_4 F_14 ( void )
{
struct V_16 * V_16 = F_15 ( NULL , 0 , V_17 |
V_18 ,
0 , 256 , L_4 ) ;
F_16 ( V_16 == NULL ) ;
F_17 ( V_16 ) ;
}
static void T_4 F_18 ( void )
{
if ( V_19 . V_20 )
V_19 . V_20 ( L_5 , 0 ) ;
#if F_19 ( V_21 ) || F_19 ( V_22 )
V_23 . V_24 = F_1 ;
V_23 . V_25 = F_13 ;
#endif
F_20 () ;
F_21 () ;
F_22 () ;
F_23 ( L_6 ) ;
}
static int T_4 F_24 ( void )
{
return F_25 ( L_7 ) ;
}
