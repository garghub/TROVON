static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 )
goto V_6;
F_3 ( & V_4 -> V_4 , false ) ;
F_4 ( V_2 ) ;
F_5 ( & V_4 -> V_4 , V_2 -> V_5 ) ;
if ( ! V_4 -> V_7 )
goto V_6;
F_6 ( F_7 ( V_4 -> V_8 ) , V_4 -> V_7 -> V_9 ) ;
V_2 -> V_10 . V_11 = NULL ;
V_2 -> V_10 . V_12 = NULL ;
V_6:
F_8 ( V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_2 V_5 ;
unsigned char V_8 ;
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 )
return 0 ;
F_10 ( V_2 , V_4 ) ;
F_11 ( & V_4 -> V_4 , V_2 -> V_5 ) ;
if ( V_2 -> V_14 . V_15 . V_16 )
F_3 ( & V_4 -> V_4 , true ) ;
if ( V_4 -> V_7 ) {
F_12 ( ( V_17 ,
L_1 ,
F_7 ( V_4 -> V_8 ) , V_4 -> V_8 -> V_9 ,
F_13 ( V_4 -> V_18 ) , F_14 ( V_4 -> V_18 ) ) ) ;
V_2 -> V_10 . V_11 = F_9 ;
V_2 -> V_10 . V_12 = F_1 ;
}
V_13 = F_15 ( V_2 -> V_5 , V_19 , & V_5 ) ;
if ( F_16 ( V_13 ) )
goto V_6;
if ( V_4 -> V_7 )
V_8 = V_4 -> V_7 -> V_9 ;
else
V_8 = V_4 -> V_8 -> V_9 ;
F_17 ( V_2 -> V_5 , F_7 ( V_4 -> V_8 ) , V_8 ) ;
V_6:
F_8 ( V_4 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_11 = F_9 ;
V_2 -> V_10 . V_12 = F_1 ;
return 0 ;
}
