static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = ( T_1 ) V_2 -> V_5 ;
int V_6 , V_7 ;
for ( V_7 = 0 ; V_7 < 20 ; V_7 ++ ) {
V_6 = ! ! ( F_2 ( V_4 + 0xF4 ) & 1 ) ;
if ( V_6 || ! V_3 )
break;
F_3 ( 10 ) ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_6 )
{
T_1 V_4 = ( T_1 ) V_2 -> V_5 ;
* V_6 = F_2 ( V_4 + 0xF0 ) ;
return 4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 V_8 ;
F_6 ( V_9 , 0x40 , & V_8 ) ;
V_8 |= ( 1 << 7 ) ;
F_7 ( V_9 , 0x40 , V_8 ) ;
F_6 ( V_9 , 0x41 , & V_8 ) ;
V_8 |= ( 1 << 7 ) ;
F_7 ( V_9 , 0x41 , V_8 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_8 ;
F_6 ( V_9 , 0x40 , & V_8 ) ;
V_8 &= ~ ( 1 << 7 ) ;
F_7 ( V_9 , 0x40 , V_8 ) ;
}
static int T_3 F_9 ( void )
{
int V_10 = - V_11 ;
struct V_12 * V_13 = NULL ;
const struct V_14 * V_15 ;
T_1 V_4 ;
F_10 (pdev) {
V_15 = F_11 ( V_16 , V_13 ) ;
if ( V_15 )
goto V_17;
}
goto V_18;
V_17:
V_10 = F_12 ( V_13 , 0x58 , & V_4 ) ;
if ( V_10 )
goto V_18;
V_10 = - V_19 ;
V_4 &= 0x0000FF00 ;
if ( V_4 == 0 )
goto V_18;
if ( ! F_13 ( V_4 + 0xF0 , 8 , L_1 ) ) {
F_14 ( & V_13 -> V_20 , L_2 ,
V_4 + 0xF0 ) ;
V_10 = - V_21 ;
goto V_18;
}
V_22 . V_5 = ( unsigned long ) V_4 ;
V_9 = V_13 ;
F_15 ( L_3 ) ;
V_10 = F_16 ( & V_22 ) ;
if ( V_10 ) {
F_17 ( V_23 L_4 ,
V_10 ) ;
F_18 ( V_4 + 0xF0 , 8 ) ;
goto V_18;
}
V_18:
return V_10 ;
}
static void T_4 F_19 ( void )
{
T_1 V_4 = ( unsigned long ) V_22 . V_5 ;
F_18 ( V_4 + 0xF0 , 8 ) ;
F_20 ( & V_22 ) ;
}
