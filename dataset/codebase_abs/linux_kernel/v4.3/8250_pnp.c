static int F_1 ( char * V_1 )
{
char * * V_2 ;
for ( V_2 = V_3 ; * V_2 ; V_2 ++ )
if ( strstr ( V_1 , * V_2 ) )
return 1 ;
return 0 ;
}
static int F_2 ( struct V_4 * V_5 )
{
T_1 V_6 [] = { 0x2f8 , 0x3f8 , 0x2e8 , 0x3e8 } ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_3 ( V_6 ) ; V_7 ++ ) {
if ( F_4 ( V_5 , V_8 , V_6 [ V_7 ] , 8 ) )
return 1 ;
}
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
if ( ! ( F_1 ( F_6 ( V_5 ) ) ||
( V_5 -> V_9 && F_1 ( V_5 -> V_9 -> V_1 ) ) ) )
return - V_10 ;
if ( F_2 ( V_5 ) )
return 0 ;
return - V_10 ;
}
static int
F_7 ( struct V_4 * V_5 , const struct V_11 * V_12 )
{
struct V_13 V_14 , * V_15 ;
int V_16 , line , V_17 = V_12 -> V_18 ;
if ( V_17 & V_19 ) {
V_16 = F_5 ( V_5 ) ;
if ( V_16 < 0 )
return V_16 ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( F_8 ( V_5 , 0 ) )
V_14 . V_15 . V_20 = F_9 ( V_5 , 0 ) ;
if ( ( V_17 & V_21 ) && F_10 ( V_5 , 2 ) ) {
V_14 . V_15 . V_22 = F_11 ( V_5 , 2 ) ;
V_14 . V_15 . V_23 = V_24 ;
} else if ( F_10 ( V_5 , 0 ) ) {
V_14 . V_15 . V_22 = F_11 ( V_5 , 0 ) ;
V_14 . V_15 . V_23 = V_24 ;
} else if ( F_12 ( V_5 , 0 ) ) {
V_14 . V_15 . V_25 = F_13 ( V_5 , 0 ) ;
V_14 . V_15 . V_23 = V_26 ;
V_14 . V_15 . V_17 = V_27 ;
} else
return - V_10 ;
#ifdef F_14
F_15 ( V_28
L_1 ,
V_14 . V_15 . V_22 , V_14 . V_15 . V_25 , V_14 . V_15 . V_20 , V_14 . V_15 . V_23 ) ;
#endif
if ( V_17 & V_21 ) {
V_14 . V_15 . V_17 |= V_29 | V_30 ;
V_14 . V_15 . type = V_31 ;
}
V_14 . V_15 . V_17 |= V_32 | V_33 ;
if ( F_16 ( V_5 , 0 ) & V_34 )
V_14 . V_15 . V_17 |= V_35 ;
V_14 . V_15 . V_36 = 1843200 ;
V_14 . V_15 . V_5 = & V_5 -> V_5 ;
line = F_17 ( & V_14 ) ;
if ( line < 0 || ( V_17 & V_21 ) )
return - V_10 ;
V_15 = F_18 ( line ) ;
if ( F_19 ( & V_15 -> V_15 ) )
V_5 -> V_37 |= V_38 ;
F_20 ( V_5 , ( void * ) ( ( long ) line + 1 ) ) ;
return 0 ;
}
static void F_21 ( struct V_4 * V_5 )
{
long line = ( long ) F_22 ( V_5 ) ;
V_5 -> V_37 &= ~ V_38 ;
if ( line )
F_23 ( line - 1 ) ;
}
static int F_24 ( struct V_4 * V_5 , T_2 V_39 )
{
long line = ( long ) F_22 ( V_5 ) ;
if ( ! line )
return - V_10 ;
F_25 ( line - 1 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 )
{
long line = ( long ) F_22 ( V_5 ) ;
if ( ! line )
return - V_10 ;
F_27 ( line - 1 ) ;
return 0 ;
}
int F_28 ( void )
{
return F_29 ( & V_40 ) ;
}
void F_30 ( void )
{
F_31 ( & V_40 ) ;
}
