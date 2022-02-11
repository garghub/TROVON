static T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - * V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
* V_5 = V_2 -> V_3 ;
* V_6 = 0 ;
* V_7 = V_8 | V_9 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
* V_7 = 0 ;
}
static int F_4 ( unsigned long V_10 ,
struct V_11 * V_12 )
{
* V_13 = 0 ;
* V_14 = V_10 ;
* V_15 = V_8 | V_9 ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 )
{
* V_15 = 0 ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 )
{
* V_13 = 0 ;
* V_14 = ( V_16 + 8 * V_17 ) / ( 16 * V_17 ) ;
* V_15 = V_8 | V_18 |
V_9 ;
return 0 ;
}
static T_2 F_7 ( int V_19 , void * V_20 )
{
struct V_11 * V_21 = V_20 ;
* V_13 = 0 ;
if ( F_8 ( V_21 ) )
* V_15 = 0 ;
V_21 -> V_22 ( V_21 ) ;
return V_23 ;
}
void T_3 F_9 ( void )
{
struct V_11 * V_21 = & V_24 ;
unsigned V_25 = F_10 ( V_16 , 16 ) ;
F_11 ( & V_26 , V_25 ) ;
F_12 ( V_21 -> V_19 , & V_27 ) ;
V_21 -> V_28 = F_13 ( F_14 () ) ;
F_15 ( V_21 , V_25 , 0x4 , 0xffffff ) ;
}
static T_4 T_5 F_16 ( void )
{
return ~ * V_29 ;
}
void T_3 F_17 ( void )
{
unsigned V_25 = F_10 ( V_16 , 16 ) ;
* V_30 = 0 ;
* V_31 = 0 ;
* V_32 = V_8 | V_9 ;
F_18 ( F_16 , 24 , V_25 ) ;
}
