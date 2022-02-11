static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + F_3 ( 1 ) ) ;
while ( ( V_2 - F_2 ( V_1 + F_3 ( 1 ) ) ) < V_3 )
F_4 () ;
}
static void F_5 ( void T_1 * V_1 , T_3 V_4 )
{
T_2 V_5 = F_2 ( V_1 + F_6 ( V_4 ) ) ;
F_7 ( V_5 & ~ V_6 , V_1 + F_6 ( V_4 ) ) ;
F_1 ( V_1 ) ;
}
static void F_8 ( void T_1 * V_1 , T_3 V_4 ,
unsigned long V_7 )
{
F_7 ( V_7 , V_1 + F_9 ( V_4 ) ) ;
}
static void F_10 ( void T_1 * V_1 , T_3 V_4 ,
bool V_8 )
{
T_2 V_5 = F_2 ( V_1 + F_6 ( V_4 ) ) ;
if ( V_8 )
V_5 &= ~ V_9 ;
else
V_5 |= V_9 ;
F_7 ( V_5 | V_6 | V_10 ,
V_1 + F_6 ( V_4 ) ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_12 ( V_12 ) ;
F_5 ( F_13 ( V_14 ) , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_12 ( V_12 ) ;
F_5 ( F_13 ( V_14 ) , 0 ) ;
F_10 ( F_13 ( V_14 ) , 0 , false ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_12 ( V_12 ) ;
F_5 ( F_13 ( V_14 ) , 0 ) ;
F_8 ( F_13 ( V_14 ) , 0 , F_16 ( V_14 ) ) ;
F_10 ( F_13 ( V_14 ) , 0 , true ) ;
return 0 ;
}
static int F_17 ( unsigned long V_12 ,
struct V_11 * V_15 )
{
struct V_13 * V_14 = F_12 ( V_15 ) ;
F_5 ( F_13 ( V_14 ) , 0 ) ;
F_8 ( F_13 ( V_14 ) , 0 , V_12 - V_3 ) ;
F_10 ( F_13 ( V_14 ) , 0 , false ) ;
return 0 ;
}
static void F_18 ( void T_1 * V_1 )
{
F_7 ( F_19 ( 0 ) , V_1 + V_16 ) ;
}
static T_4 F_20 ( int V_17 , void * V_18 )
{
struct V_11 * V_12 = (struct V_11 * ) V_18 ;
struct V_13 * V_14 = F_12 ( V_12 ) ;
F_18 ( F_13 ( V_14 ) ) ;
V_12 -> V_19 ( V_12 ) ;
return V_20 ;
}
static T_5 T_6 F_21 ( void )
{
return ~ F_2 ( F_13 ( & V_14 ) + F_3 ( 1 ) ) ;
}
static int T_7 F_22 ( struct V_21 * V_22 )
{
int V_23 ;
T_2 V_5 ;
V_23 = F_23 ( V_22 , & V_14 ) ;
if ( V_23 )
return V_23 ;
F_7 ( ~ 0 , F_13 ( & V_14 ) + F_9 ( 1 ) ) ;
F_7 ( V_6 | V_10 |
F_24 ( V_24 ) ,
F_13 ( & V_14 ) + F_6 ( 1 ) ) ;
if ( F_25 ( L_1 ) ||
F_25 ( L_2 ) ||
F_25 ( L_3 ) )
F_26 ( F_21 , 32 ,
F_27 ( & V_14 ) ) ;
V_23 = F_28 ( F_13 ( & V_14 ) + F_3 ( 1 ) ,
V_22 -> V_25 , F_27 ( & V_14 ) , 350 , 32 ,
V_26 ) ;
if ( V_23 ) {
F_29 ( L_4 ) ;
return V_23 ;
}
F_7 ( F_24 ( V_24 ) ,
F_13 ( & V_14 ) + F_6 ( 0 ) ) ;
F_5 ( F_13 ( & V_14 ) , 0 ) ;
F_18 ( F_13 ( & V_14 ) ) ;
F_30 ( & V_14 . V_15 , F_27 ( & V_14 ) ,
V_3 , 0xffffffff ) ;
V_5 = F_2 ( F_13 ( & V_14 ) + V_27 ) ;
F_7 ( V_5 | F_19 ( 0 ) , F_13 ( & V_14 ) + V_27 ) ;
return V_23 ;
}
