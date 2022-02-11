int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 ;
V_4 = F_2 ( & V_2 -> V_7 ) ;
V_8 = F_3 ( & V_2 -> V_7 , L_1 ) ;
if ( F_4 ( V_8 ) ) {
F_5 ( & V_2 -> V_7 , L_2 ) ;
return F_6 ( V_8 ) ;
}
V_9 = F_3 ( & V_2 -> V_7 , L_3 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( & V_2 -> V_7 , L_4 ) ;
return F_6 ( V_9 ) ;
}
V_10 = F_3 ( & V_2 -> V_7 , L_5 ) ;
if ( F_4 ( V_10 ) ) {
F_5 ( & V_2 -> V_7 , L_6 ) ;
return F_6 ( V_10 ) ;
}
F_7 ( V_8 ) ;
F_7 ( V_9 ) ;
F_7 ( V_10 ) ;
if ( ! strcmp ( V_2 -> V_11 -> V_12 , L_7 ) ) {
V_5 = F_8 ( V_10 ) ;
if ( V_4 -> V_13 != V_14 &&
( V_5 < 59999000 || V_5 > 60001000 ) ) {
F_5 ( & V_2 -> V_7 , L_8 , V_5 ) ;
V_6 = - V_15 ;
goto V_16;
}
}
return 0 ;
V_16:
F_9 ( V_8 ) ;
F_9 ( V_9 ) ;
F_9 ( V_10 ) ;
V_10 = NULL ;
return V_6 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_7 ) ;
int V_6 = 0 ;
if ( V_4 -> V_17 & V_18 ) {
unsigned int V_19 ;
struct V_20 * V_21 = F_11
( V_2 , V_22 , 0 ) ;
void T_1 * V_23 = F_12 ( V_21 -> V_24 +
V_25 , 512 ) ;
if ( ! V_23 ) {
F_5 ( & V_2 -> V_7 , L_9 ) ;
V_6 = - V_15 ;
goto V_26;
}
V_19 = F_13 ( V_23 + V_27 ) ;
F_14 ( V_19 | V_28 ,
V_23 + V_27 ) ;
F_15 ( V_23 ) ;
}
V_26:
if ( V_4 -> V_13 == V_14 ) {
F_9 ( V_10 ) ;
V_10 = NULL ;
}
return V_6 ;
}
void F_16 ( void )
{
if ( V_10 )
F_9 ( V_10 ) ;
F_9 ( V_9 ) ;
F_9 ( V_8 ) ;
}
