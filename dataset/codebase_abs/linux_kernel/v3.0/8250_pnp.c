static int T_1 F_1 ( char * V_1 )
{
char * * V_2 ;
for ( V_2 = V_3 ; * V_2 ; V_2 ++ )
if ( strstr ( V_1 , * V_2 ) )
return 1 ;
return 0 ;
}
static int T_1 F_2 ( struct V_4 * V_5 )
{
T_2 V_6 [] = { 0x2f8 , 0x3f8 , 0x2e8 , 0x3e8 } ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_3 ( V_6 ) ; V_7 ++ ) {
if ( F_4 ( V_5 , V_8 , V_6 [ V_7 ] , 8 ) )
return 1 ;
}
return 0 ;
}
static int T_1 F_5 ( struct V_4 * V_5 , int * V_9 )
{
if ( ! ( F_1 ( F_6 ( V_5 ) ) ||
( V_5 -> V_10 && F_1 ( V_5 -> V_10 -> V_1 ) ) ) )
return - V_11 ;
if ( F_2 ( V_5 ) )
return 0 ;
return - V_11 ;
}
static int T_1
F_7 ( struct V_4 * V_5 , const struct V_12 * V_13 )
{
struct V_14 V_15 ;
int V_16 , line , V_9 = V_13 -> V_17 ;
if ( V_9 & V_18 ) {
V_16 = F_5 ( V_5 , & V_9 ) ;
if ( V_16 < 0 )
return V_16 ;
}
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
if ( F_8 ( V_5 , 0 ) )
V_15 . V_19 = F_9 ( V_5 , 0 ) ;
if ( F_10 ( V_5 , 0 ) ) {
V_15 . V_20 = F_11 ( V_5 , 0 ) ;
V_15 . V_21 = V_22 ;
} else if ( F_12 ( V_5 , 0 ) ) {
V_15 . V_23 = F_13 ( V_5 , 0 ) ;
V_15 . V_21 = V_24 ;
V_15 . V_9 = V_25 ;
} else
return - V_11 ;
#ifdef F_14
F_15 ( V_26
L_1 ,
V_15 . V_20 , V_15 . V_23 , V_15 . V_19 , V_15 . V_21 ) ;
#endif
V_15 . V_9 |= V_27 | V_28 ;
if ( F_16 ( V_5 , 0 ) & V_29 )
V_15 . V_9 |= V_30 ;
V_15 . V_31 = 1843200 ;
V_15 . V_5 = & V_5 -> V_5 ;
line = F_17 ( & V_15 ) ;
if ( line < 0 )
return - V_11 ;
F_18 ( V_5 , ( void * ) ( ( long ) line + 1 ) ) ;
return 0 ;
}
static void T_3 F_19 ( struct V_4 * V_5 )
{
long line = ( long ) F_20 ( V_5 ) ;
if ( line )
F_21 ( line - 1 ) ;
}
static int F_22 ( struct V_4 * V_5 , T_4 V_32 )
{
long line = ( long ) F_20 ( V_5 ) ;
if ( ! line )
return - V_11 ;
F_23 ( line - 1 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
long line = ( long ) F_20 ( V_5 ) ;
if ( ! line )
return - V_11 ;
F_25 ( line - 1 ) ;
return 0 ;
}
static int T_5 F_26 ( void )
{
return F_27 ( & V_33 ) ;
}
static void T_6 F_28 ( void )
{
F_29 ( & V_33 ) ;
}
