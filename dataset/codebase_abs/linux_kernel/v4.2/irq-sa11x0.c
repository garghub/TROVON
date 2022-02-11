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
F_10 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_11 ( void )
{
struct V_13 * V_14 = & V_13 ;
V_14 -> V_15 = 1 ;
V_14 -> V_16 = F_2 ( V_4 + V_5 ) ;
V_14 -> V_17 = F_2 ( V_4 + V_18 ) ;
V_14 -> V_19 = F_2 ( V_4 + V_20 ) ;
F_4 ( V_14 -> V_16 & 0xfffff000 , V_4 + V_5 ) ;
return 0 ;
}
static void F_12 ( void )
{
struct V_13 * V_14 = & V_13 ;
if ( V_14 -> V_15 ) {
F_4 ( V_14 -> V_19 , V_4 + V_20 ) ;
F_4 ( V_14 -> V_17 , V_4 + V_18 ) ;
F_4 ( V_14 -> V_16 , V_4 + V_5 ) ;
}
}
static int T_3 F_13 ( void )
{
F_14 ( & V_21 ) ;
return 0 ;
}
static T_4 void T_5
F_15 ( struct V_22 * V_23 )
{
T_6 V_24 , V_16 , V_25 ;
do {
V_24 = F_2 ( V_4 + V_26 ) ;
V_16 = F_2 ( V_4 + V_5 ) ;
V_25 = V_24 & V_16 ;
if ( V_25 == 0 )
break;
F_16 ( V_27 ,
F_17 ( V_25 ) - 1 , V_23 ) ;
} while ( 1 );
}
void T_3 F_18 ( int V_28 , T_7 V_29 )
{
V_4 = F_19 ( V_29 , V_30 ) ;
if ( F_20 ( ! V_4 ) )
return;
F_4 ( 0 , V_4 + V_5 ) ;
F_4 ( 0 , V_4 + V_18 ) ;
F_4 ( 1 , V_4 + V_20 ) ;
V_27 = F_21 ( NULL ,
32 , V_28 ,
& V_31 , NULL ) ;
F_22 ( F_15 ) ;
}
