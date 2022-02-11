static int F_1 ( struct V_1 * V_1 , int V_2 , int V_3 ,
T_1 * V_4 )
{
int V_5 ;
int V_6 ;
V_7:
if ( ! F_2 ( V_1 , V_8 ) )
return - V_9 ;
F_3 ( V_4 ) ;
V_6 = F_4 ( V_1 , V_2 , & V_5 ) ;
F_5 ( V_4 ) ;
if ( V_6 == - V_10 )
goto V_7;
else if ( V_6 )
return V_6 ;
if ( V_5 > V_3 ) {
F_3 ( V_4 ) ;
F_6 ( V_1 , V_5 ) ;
F_5 ( V_4 ) ;
return - V_9 ;
}
return V_5 ;
}
int F_7 ( struct V_11 * V_12 )
{
int V_13 ;
if ( V_12 -> V_14 . V_15 == V_16 ) {
V_13 = F_1 ( & V_17 , V_18 , V_19 ,
& V_20 ) ;
if ( V_13 >= 0 )
V_12 -> V_14 . V_15 = V_13 ;
}
return V_12 -> V_14 . V_15 ;
}
int F_8 ( struct V_11 * V_12 )
{
int V_21 = V_16 ;
if ( ( ! V_12 -> V_14 . V_22 ) && ( V_12 -> V_14 . V_15 != V_16 ) ) {
V_21 = V_12 -> V_14 . V_15 ;
V_12 -> V_14 . V_15 = V_16 ;
}
return V_21 ;
}
void F_9 ( int V_21 )
{
F_3 ( & V_20 ) ;
F_6 ( & V_17 , V_21 ) ;
F_5 ( & V_20 ) ;
}
