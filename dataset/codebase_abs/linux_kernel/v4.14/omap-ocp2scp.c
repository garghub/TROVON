static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 )
{
int V_6 ;
T_1 V_7 ;
void T_2 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = V_5 -> V_2 . V_13 ;
if ( V_12 ) {
V_6 = F_5 ( V_12 , NULL , NULL , & V_5 -> V_2 ) ;
if ( V_6 ) {
F_6 ( & V_5 -> V_2 ,
L_1 ) ;
goto V_14;
}
}
F_7 ( & V_5 -> V_2 ) ;
if ( ! F_8 ( V_12 , L_2 ) ) {
V_10 = F_9 ( V_5 , V_15 , 0 ) ;
V_8 = F_10 ( & V_5 -> V_2 , V_10 ) ;
if ( F_11 ( V_8 ) ) {
V_6 = F_12 ( V_8 ) ;
goto V_16;
}
F_13 ( & V_5 -> V_2 ) ;
V_7 = F_14 ( V_8 + V_17 ) ;
V_7 &= ~ ( V_18 ) ;
V_7 |= 0x6 ;
F_15 ( V_7 , V_8 + V_17 ) ;
F_16 ( & V_5 -> V_2 ) ;
}
return 0 ;
V_16:
F_17 ( & V_5 -> V_2 ) ;
V_14:
F_18 ( & V_5 -> V_2 , NULL , F_1 ) ;
return V_6 ;
}
static int F_19 ( struct V_4 * V_5 )
{
F_17 ( & V_5 -> V_2 ) ;
F_18 ( & V_5 -> V_2 , NULL , F_1 ) ;
return 0 ;
}
