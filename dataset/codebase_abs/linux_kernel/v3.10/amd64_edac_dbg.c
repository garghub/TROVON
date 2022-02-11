static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_8 = 0 ;
T_2 V_9 = 0 ;
T_2 V_10 = 0 ;
F_3 ( V_7 , & V_8 , & V_9 , & V_10 ) ;
return sprintf ( V_5 , L_1 , V_8 , V_9 ,
V_10 ) ;
}
int F_4 ( struct V_6 * V_7 )
{
int V_11 ;
V_11 = F_5 ( & V_7 -> V_2 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( & V_7 -> V_2 , & V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( & V_7 -> V_2 , & V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( & V_7 -> V_2 , & V_15 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( & V_7 -> V_2 , & V_16 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
void F_6 ( struct V_6 * V_7 )
{
F_7 ( & V_7 -> V_2 , & V_12 ) ;
F_7 ( & V_7 -> V_2 , & V_13 ) ;
F_7 ( & V_7 -> V_2 , & V_14 ) ;
F_7 ( & V_7 -> V_2 , & V_15 ) ;
F_7 ( & V_7 -> V_2 , & V_16 ) ;
}
