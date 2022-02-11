static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 , V_6 ;
V_5 = F_2 ( V_7 ) ;
V_6 = F_2 ( V_8 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_6 = mktime ( ( V_6 & V_9 ) , F_3 ( V_5 ) ,
F_4 ( V_5 ) , F_5 ( V_5 ) ,
F_6 ( V_5 ) , F_7 ( V_5 ) ) ;
F_8 ( V_6 , V_4 ) ;
return F_9 ( V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 , V_6 , V_10 ;
int V_11 = - V_12 ;
V_5 = ( ( V_4 -> V_13 + 1 ) << V_14 )
| ( V_4 -> V_15 << V_16 )
| ( V_4 -> V_17 << V_18 )
| ( V_4 -> V_19 << V_20 )
| ( V_4 -> V_21 << V_22 ) ;
F_11 ( V_5 , V_23 ) ;
V_10 = 0x10000 ;
while ( ( F_2 ( V_24 ) & V_25 ) && -- V_10 )
F_12 ( 1000 , 3000 ) ;
if ( ! V_10 ) {
F_13 ( V_2 , L_1 ) ;
goto V_26;
}
V_6 = V_4 -> V_27 + 1900 ;
F_11 ( V_6 , V_28 ) ;
V_10 = 0x10000 ;
while ( ( F_2 ( V_24 ) & V_25 ) && -- V_10 )
F_12 ( 1000 , 3000 ) ;
if ( ! V_10 ) {
F_13 ( V_2 , L_1 ) ;
goto V_26;
}
return 0 ;
V_26:
return V_11 ;
}
static int F_14 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
unsigned long V_5 ;
int V_11 ;
V_5 = F_2 ( V_24 ) ;
if ( ! ( V_5 & V_33 ) ) {
F_13 ( & V_30 -> V_2 , L_2 ) ;
V_11 = - V_34 ;
goto V_26;
}
V_11 = - V_12 ;
if ( F_2 ( V_35 ) != 32767 ) {
V_5 = 0x100000 ;
while ( ( F_2 ( V_24 ) & V_36 ) && -- V_5 )
F_12 ( 1000 , 3000 ) ;
if ( ! V_5 ) {
F_13 ( & V_30 -> V_2 , L_3 ) ;
goto V_26;
}
F_11 ( 32767 , V_35 ) ;
}
while ( F_2 ( V_24 ) & V_36 )
F_12 ( 1000 , 3000 ) ;
V_32 = F_15 ( & V_30 -> V_2 , L_4 ,
& V_37 , V_38 ) ;
if ( F_16 ( V_32 ) ) {
V_11 = F_17 ( V_32 ) ;
goto V_26;
}
F_18 ( V_30 , V_32 ) ;
return 0 ;
V_26:
return V_11 ;
}
