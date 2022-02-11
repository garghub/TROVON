int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 ;
V_4 = V_2 -> V_7 . V_8 ;
if ( ! F_2 () && ! F_3 () ) {
V_9 = F_4 ( & V_2 -> V_7 , L_1 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
V_6 = F_7 ( V_9 ) ;
if ( V_6 < 0 ) {
F_8 ( & V_2 -> V_7 , L_2 ) ;
goto V_10;
}
}
V_11 = F_4 ( & V_2 -> V_7 , L_3 ) ;
if ( F_5 ( V_11 ) ) {
F_8 ( & V_2 -> V_7 , L_4 ) ;
V_6 = F_6 ( V_11 ) ;
goto V_12;
}
if ( ! F_9 () ) {
V_5 = F_10 ( V_11 ) ;
if ( V_4 -> V_13 != V_14 &&
( V_5 < 59999000 || V_5 > 60001000 ) ) {
F_8 ( & V_2 -> V_7 , L_5 , V_5 ) ;
V_6 = - V_15 ;
goto V_16;
}
}
V_6 = F_7 ( V_11 ) ;
if ( V_6 < 0 ) {
F_8 ( & V_2 -> V_7 , L_6 ) ;
goto V_17;
}
return 0 ;
V_17:
V_16:
F_11 ( V_11 ) ;
V_11 = NULL ;
V_12:
if ( ! F_2 () )
F_12 ( V_9 ) ;
V_10:
if ( ! F_2 () )
F_11 ( V_9 ) ;
return V_6 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_7 . V_8 ;
#if F_14 ( V_18 )
if ( F_2 () ) {
unsigned int V_19 ;
if ( V_4 -> V_20 & V_21 ) {
V_19 = F_15 ( F_16 ( V_22 +
V_23 ) ) ;
F_17 ( V_19 | V_24 ,
F_16 ( V_22 +
V_23 ) ) ;
}
}
#endif
if ( V_4 -> V_13 == V_14 ) {
F_12 ( V_11 ) ;
F_11 ( V_11 ) ;
V_11 = NULL ;
}
}
void F_18 ( void )
{
if ( V_11 ) {
F_12 ( V_11 ) ;
F_11 ( V_11 ) ;
}
if ( ! F_2 () ) {
F_12 ( V_9 ) ;
F_11 ( V_9 ) ;
}
}
