static int F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 ,
int V_4 )
{
struct V_5 * V_6 , * V_7 ;
int V_8 ;
V_6 = F_2 ( & V_2 -> V_9 , L_1 ) ;
if ( F_3 ( V_6 ) ) {
V_8 = F_4 ( V_6 ) ;
goto V_10;
}
V_7 = F_2 ( & V_2 -> V_9 , L_2 ) ;
if ( F_3 ( V_7 ) ) {
V_8 = F_4 ( V_7 ) ;
goto V_11;
}
if ( V_4 ) {
F_5 ( V_6 , F_6 ( V_6 , 24000000 ) ) ;
F_5 ( V_7 , F_6 ( V_6 , 510000000 ) ) ;
F_7 ( V_6 ) ;
F_7 ( V_7 ) ;
} else {
F_8 ( V_6 ) ;
F_8 ( V_7 ) ;
}
V_8 = 0 ;
F_9 ( V_7 ) ;
V_11:
F_9 ( V_6 ) ;
V_10:
return V_8 ;
}
static int F_10 ( int V_12 )
{
struct V_13 * V_14 ;
struct V_15 V_16 ;
unsigned int V_17 ;
int V_8 ;
if ( V_12 == 0 ) {
F_11 ( 235 , 0 ) ;
F_12 ( 24 ) ;
F_11 ( 235 , 1 ) ;
return 0 ;
}
V_14 = F_13 ( 1 ) ;
if ( V_14 == NULL )
return - V_18 ;
for ( V_17 = 0 ; V_17 < F_14 ( V_19 ) ; V_17 ++ ) {
V_16 . V_20 = 0x6d ;
V_16 . V_21 = & V_19 [ V_17 ] [ 0 ] ;
V_16 . V_22 = 2 ;
V_16 . V_23 = 0 ;
V_8 = F_15 ( V_14 , & V_16 , 1 ) ;
if ( V_8 < 0 )
break;
}
F_16 ( V_14 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static void F_17 ( struct V_1 * V_2 , int V_24 )
{
static int V_25 = - V_26 ;
if ( V_25 < 0 ) {
int V_8 = F_18 ( 114 , V_27 ,
L_3 ) ;
if ( ! V_8 )
V_25 = 114 ;
}
F_11 ( 114 , V_24 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( 0 , L_4 , V_28 ,
F_14 ( V_28 ) , 1800000 ) ;
F_20 ( 1 , L_5 , V_29 ,
F_14 ( V_29 ) , 3300000 ) ;
F_21 ( 3 , V_30 , F_14 ( V_30 ) ) ;
F_22 ( V_31 ,
F_14 ( V_31 ) ) ;
F_23 () ;
F_18 ( 208 , V_32 , NULL ) ;
F_18 ( 144 , V_33 , NULL ) ;
F_18 ( 145 , V_32 , NULL ) ;
F_18 ( 217 , V_27 , NULL ) ;
F_12 ( 1 ) ;
F_11 ( 217 , 1 ) ;
F_12 ( 100 ) ;
F_18 ( 235 , V_27 , NULL ) ;
F_10 ( 0 ) ;
#ifdef F_24
F_25 ( F_26 ( 0xf0100000 ) , 0x00460000 , 0xc2000fff ) ;
#endif
F_27 () ;
F_28 ( V_34 , F_14 ( V_34 ) ) ;
}
