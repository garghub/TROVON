static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ,
V_3 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ,
V_3 + V_5 ) ;
}
static int F_5 ( struct V_6 * V_7 ,
unsigned int V_8 , T_1 V_9 )
{
F_1 ( F_6 ( V_8 ) ) ;
F_2 ( V_9 , V_10 + V_11 ) ;
F_7 ( V_8 , & V_12 ,
V_13 ) ;
F_8 ( V_8 , V_14 ) ;
F_9 ( V_8 , V_15 | V_16 ) ;
return 0 ;
}
static int T_2 F_10 ( struct V_17 * V_18 ,
struct V_17 * V_19 )
{
T_3 V_20 ;
V_10 = F_11 ( V_18 , 0 ) ;
V_3 = F_11 ( V_18 , 1 ) ;
F_12 ( ! V_10 ) ;
F_12 ( ! V_3 ) ;
V_20 = F_13 ( V_10 + V_21 ) ;
V_22 =
F_14 ( V_18 , ( V_20 >> 2 ) & 0x3ff ,
& V_23 , NULL ) ;
if ( ! V_22 )
F_15 ( L_1 ) ;
F_16 ( V_22 ) ;
return 0 ;
}
T_4 void T_5 F_17 ( struct V_24
* V_25 )
{
T_3 V_26 , V_27 ;
do {
V_26 = F_18 ( V_3 +
V_28 ) ;
V_27 = V_26 & 0x3FF ;
if ( V_27 < 1023 ) {
V_27 =
F_19 ( V_22 , V_27 ) ;
F_20 ( V_27 , V_25 ) ;
continue;
}
break;
} while ( 1 );
}
void T_2 F_21 ( void )
{
F_22 ( V_29 ) ;
}
