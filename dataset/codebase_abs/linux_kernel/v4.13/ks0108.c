void F_1 ( unsigned char V_1 )
{
F_2 ( V_2 , V_1 ) ;
}
void F_3 ( unsigned char V_1 )
{
F_4 ( V_3 ) ;
F_5 ( V_2 , V_1 ^ ( F_6 ( 0 ) | F_6 ( 1 ) | F_6 ( 3 ) ) ) ;
}
void F_7 ( unsigned char V_4 )
{
F_1 ( ( V_4 ? F_6 ( 0 ) : 0 ) | F_6 ( 1 ) | F_6 ( 2 ) | F_6 ( 3 ) | F_6 ( 4 ) | F_6 ( 5 ) ) ;
}
void F_8 ( unsigned char V_5 )
{
F_1 ( F_9 (unsigned char, startline, 63 ) | F_6 ( 6 ) |
F_6 ( 7 ) ) ;
}
void F_10 ( unsigned char V_6 )
{
F_1 ( F_9 (unsigned char, address, 63 ) | F_6 ( 6 ) ) ;
}
void F_11 ( unsigned char V_7 )
{
F_1 ( F_9 (unsigned char, page, 7 ) | F_6 ( 3 ) | F_6 ( 4 ) |
F_6 ( 5 ) | F_6 ( 7 ) ) ;
}
unsigned char F_12 ( void )
{
return V_8 ;
}
static void F_13 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
if ( V_10 -> V_13 != V_14 )
return;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_15 = V_16 ;
V_17 = F_14 ( V_10 , V_18 ,
& V_12 , 0 ) ;
if ( ! V_17 ) {
F_15 ( L_1 ) ;
return;
}
if ( F_16 ( V_17 ) ) {
F_15 ( L_2 ,
V_14 ) ;
goto V_19;
}
V_2 = V_10 ;
V_8 = 1 ;
return;
V_19:
F_17 ( V_17 ) ;
V_17 = NULL ;
}
static void F_18 ( struct V_9 * V_10 )
{
if ( V_10 -> V_13 != V_14 )
return;
if ( ! V_17 ) {
F_15 ( L_3 , V_18 ) ;
return;
}
F_19 ( V_17 ) ;
F_17 ( V_17 ) ;
V_17 = NULL ;
V_2 = NULL ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_20 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_20 ) ;
}
