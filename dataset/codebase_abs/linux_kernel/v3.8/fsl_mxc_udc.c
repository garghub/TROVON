int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 ;
V_4 = V_2 -> V_7 . V_8 ;
V_9 = F_2 ( & V_2 -> V_7 , L_1 ) ;
if ( F_3 ( V_9 ) ) {
F_4 ( & V_2 -> V_7 , L_2 ) ;
return F_5 ( V_9 ) ;
}
V_10 = F_2 ( & V_2 -> V_7 , L_3 ) ;
if ( F_3 ( V_10 ) ) {
F_4 ( & V_2 -> V_7 , L_4 ) ;
return F_5 ( V_10 ) ;
}
V_11 = F_2 ( & V_2 -> V_7 , L_5 ) ;
if ( F_3 ( V_11 ) ) {
F_4 ( & V_2 -> V_7 , L_6 ) ;
return F_5 ( V_11 ) ;
}
F_6 ( V_9 ) ;
F_6 ( V_10 ) ;
F_6 ( V_11 ) ;
if ( ! strcmp ( V_2 -> V_12 -> V_13 , L_7 ) ) {
V_5 = F_7 ( V_11 ) ;
if ( V_4 -> V_14 != V_15 &&
( V_5 < 59999000 || V_5 > 60001000 ) ) {
F_4 ( & V_2 -> V_7 , L_8 , V_5 ) ;
V_6 = - V_16 ;
goto V_17;
}
}
return 0 ;
V_17:
F_8 ( V_9 ) ;
F_8 ( V_10 ) ;
F_8 ( V_11 ) ;
V_11 = NULL ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_7 . V_8 ;
int V_6 = 0 ;
if ( V_4 -> V_18 & V_19 ) {
unsigned int V_20 ;
struct V_21 * V_22 = F_10
( V_2 , V_23 , 0 ) ;
void T_1 * V_24 = F_11 ( V_22 -> V_25 +
V_26 , 512 ) ;
if ( ! V_24 ) {
F_4 ( & V_2 -> V_7 , L_9 ) ;
V_6 = - V_16 ;
goto V_27;
}
V_20 = F_12 ( V_24 + V_28 ) ;
F_13 ( V_20 | V_29 ,
V_24 + V_28 ) ;
F_14 ( V_24 ) ;
}
V_27:
if ( V_4 -> V_14 == V_15 ) {
F_8 ( V_11 ) ;
V_11 = NULL ;
}
return V_6 ;
}
void F_15 ( void )
{
if ( V_11 )
F_8 ( V_11 ) ;
F_8 ( V_10 ) ;
F_8 ( V_9 ) ;
}
