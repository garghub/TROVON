int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_5 ) ;
if ( V_4 -> V_6 == 0 )
if ( V_7 == V_2 ) {
V_8 = 0 ;
V_7 = NULL ;
F_3 ( & V_5 ) ;
F_4 ( V_2 -> V_9 , L_1
L_2 ) ;
} else {
F_3 ( & V_5 ) ;
F_5 ( V_2 -> V_9 , L_3
L_4 ) ;
return - V_10 ;
}
else
if ( V_7 == NULL ||
V_7 == V_2 ) {
V_8 = V_4 -> V_6 ;
V_7 = V_2 ;
F_3 ( & V_5 ) ;
F_4 ( V_2 -> V_9 , L_5
L_6 , V_4 -> V_6 ) ;
} else {
F_3 ( & V_5 ) ;
F_5 ( V_2 -> V_9 , L_7
L_8 ) ;
return - V_10 ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_2 ( & V_5 ) ;
if ( V_2 == V_7 ) {
V_8 = 0 ;
V_7 = NULL ;
F_3 ( & V_5 ) ;
F_4 ( V_2 -> V_9 , L_9
L_10 ) ;
} else
F_3 ( & V_5 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_13 )
{
unsigned long V_14 ;
F_8 ( & V_5 , V_14 ) ;
if ( V_2 == V_7 && V_13 & V_8 )
F_9 ( & V_12 -> V_15 , & V_12 -> V_16 ) ;
F_10 ( & V_5 , V_14 ) ;
}
