static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 + V_5 ) ;
V_3 &= ~ F_3 ( V_2 -> V_6 ) ;
F_4 ( V_3 , V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 + V_5 ) ;
V_3 |= F_3 ( V_2 -> V_6 ) ;
F_4 ( V_3 , V_4 + V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_7 )
{
return F_7 ( V_2 -> V_6 , V_7 ) ;
}
static int F_8 ( struct V_8 * V_2 ,
unsigned int V_9 , T_2 V_6 )
{
F_9 ( V_9 , & V_10 ,
V_11 ) ;
return 0 ;
}
static int F_10 ( void )
{
struct V_12 * V_13 = & V_12 ;
V_13 -> V_14 = 1 ;
V_13 -> V_15 = F_2 ( V_4 + V_5 ) ;
V_13 -> V_16 = F_2 ( V_4 + V_17 ) ;
V_13 -> V_18 = F_2 ( V_4 + V_19 ) ;
F_4 ( V_13 -> V_15 & 0xfffff000 , V_4 + V_5 ) ;
return 0 ;
}
static void F_11 ( void )
{
struct V_12 * V_13 = & V_12 ;
if ( V_13 -> V_14 ) {
F_4 ( V_13 -> V_18 , V_4 + V_19 ) ;
F_4 ( V_13 -> V_16 , V_4 + V_17 ) ;
F_4 ( V_13 -> V_15 , V_4 + V_5 ) ;
}
}
static int T_3 F_12 ( void )
{
F_13 ( & V_20 ) ;
return 0 ;
}
static T_4 void T_5
F_14 ( struct V_21 * V_22 )
{
T_6 V_23 , V_15 , V_24 ;
do {
V_23 = F_2 ( V_4 + V_25 ) ;
V_15 = F_2 ( V_4 + V_5 ) ;
V_24 = V_23 & V_15 ;
if ( V_24 == 0 )
break;
F_15 ( V_26 ,
F_16 ( V_24 ) - 1 , V_22 ) ;
} while ( 1 );
}
void T_3 F_17 ( int V_27 , T_7 V_28 )
{
V_4 = F_18 ( V_28 , V_29 ) ;
if ( F_19 ( ! V_4 ) )
return;
F_4 ( 0 , V_4 + V_5 ) ;
F_4 ( 0 , V_4 + V_17 ) ;
F_4 ( 1 , V_4 + V_19 ) ;
V_26 = F_20 ( NULL ,
32 , V_27 ,
& V_30 , NULL ) ;
F_21 ( F_14 ) ;
}
