static int F_1 ( void ) {
if ( ! F_2 ( V_1 , 2 , V_2 ) )
return - V_3 ;
F_3 ( V_4 , V_1 ) ;
F_3 ( V_4 , V_1 ) ;
return 0 ;
}
static void F_4 ( void ) {
F_3 ( V_5 , V_1 ) ;
F_5 ( V_1 , 2 ) ;
}
static int F_6 ( T_1 V_6 )
{
T_1 V_7 [] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 } ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_7 ( V_7 ) ; V_8 ++ )
if ( V_6 == V_7 [ V_8 ] )
return V_8 ;
return - V_9 ;
}
static int F_8 ( void )
{
F_3 ( V_10 , V_1 ) ;
if ( F_9 ( V_11 ) != V_12 )
return - V_9 ;
F_3 ( V_13 , V_1 ) ;
if ( F_9 ( V_11 ) != V_14 )
return - V_9 ;
F_3 ( V_15 , V_1 ) ;
if ( F_9 ( V_11 ) != V_16 )
return - V_9 ;
F_3 ( V_17 , V_1 ) ;
if ( F_9 ( V_11 ) != V_18 )
return - V_9 ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
T_2 V_23 = 0 ;
int V_24 = F_6 ( V_20 -> V_25 ) ;
if ( V_24 < 0 )
return - V_26 ;
if ( V_22 -> V_27 & V_28 )
memset ( V_22 -> V_29 , 0 , sizeof( V_22 -> V_29 ) ) ;
else
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_27 &= V_28 | V_30 |
V_31 ;
if ( V_22 -> V_32 ) {
V_22 -> V_32 = 1 ;
V_23 |= V_33 ;
}
if ( V_22 -> V_34 ) {
V_22 -> V_34 = 1 ;
V_23 |= V_35 ;
}
if ( ( ! ! ( V_22 -> V_27 & V_30 ) ) ==
( ! ! ( V_22 -> V_27 & V_31 ) ) )
V_22 -> V_27 &= V_28 ;
else
V_23 |= V_36 ;
if ( V_22 -> V_27 & V_30 )
V_23 |= V_37 ;
if ( F_1 () )
return - V_3 ;
F_3 ( V_38 , V_1 ) ;
F_3 ( V_24 , V_11 ) ;
F_3 ( V_39 , V_1 ) ;
F_3 ( V_23 , V_11 ) ;
F_4 () ;
V_20 -> V_22 = * V_22 ;
return 0 ;
}
static int
F_11 ( struct V_40 * V_41 , const struct V_42 * V_43 )
{
int line ;
struct V_44 V_45 ;
int V_46 ;
if ( ! F_12 ( V_41 , 0 ) )
return - V_9 ;
if ( F_6 ( F_13 ( V_41 , 0 ) ) < 0 )
return - V_9 ;
if ( F_1 () )
return - V_3 ;
V_46 = F_8 () ;
F_4 () ;
if ( V_46 )
return V_46 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
if ( ! F_14 ( V_41 , 0 ) )
return - V_9 ;
V_45 . V_20 . V_47 = F_15 ( V_41 , 0 ) ;
V_45 . V_20 . V_25 = F_13 ( V_41 , 0 ) ;
V_45 . V_20 . V_48 = V_49 ;
V_45 . V_20 . V_50 = F_10 ;
V_45 . V_20 . V_27 |= V_51 | V_52 ;
if ( F_16 ( V_41 , 0 ) & V_53 )
V_45 . V_20 . V_27 |= V_54 ;
V_45 . V_20 . V_55 = 1843200 ;
V_45 . V_20 . V_41 = & V_41 -> V_41 ;
line = F_17 ( & V_45 ) ;
if ( line < 0 )
return - V_9 ;
F_18 ( V_41 , ( void * ) ( ( long ) line + 1 ) ) ;
return 0 ;
}
static void F_19 ( struct V_40 * V_41 )
{
long line = ( long ) F_20 ( V_41 ) ;
if ( line )
F_21 ( line - 1 ) ;
}
static int F_22 ( struct V_40 * V_41 , T_3 V_56 )
{
long line = ( long ) F_20 ( V_41 ) ;
if ( ! line )
return - V_9 ;
F_23 ( line - 1 ) ;
return 0 ;
}
static int F_24 ( struct V_40 * V_41 )
{
long line = ( long ) F_20 ( V_41 ) ;
if ( ! line )
return - V_9 ;
F_25 ( line - 1 ) ;
return 0 ;
}
