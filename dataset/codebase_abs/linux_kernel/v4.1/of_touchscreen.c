static T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
T_1 V_4 = 0 ;
F_2 ( V_2 , V_3 , & V_4 ) ;
return V_4 ;
}
static void F_3 ( struct V_5 * V_6 ,
unsigned long V_7 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 ;
if ( ! F_4 ( V_7 , V_6 -> V_12 ) ) {
if ( ! F_5 ( V_7 ) )
F_6 ( & V_6 -> V_6 ,
L_1 ) ;
return;
}
V_11 = & V_6 -> V_11 [ V_7 ] ;
V_11 -> V_13 = V_8 ;
V_11 -> V_9 = V_9 ;
}
void F_7 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_6 . V_14 -> V_15 ;
T_1 V_13 , V_9 ;
F_8 ( V_6 ) ;
if ( ! V_6 -> V_11 )
return;
V_13 = F_1 ( V_2 , L_2 ) ;
V_9 = F_1 ( V_2 , L_3 ) ;
if ( V_13 || V_9 ) {
F_3 ( V_6 , V_16 , V_13 , V_9 ) ;
F_3 ( V_6 , V_17 , V_13 , V_9 ) ;
}
V_13 = F_1 ( V_2 , L_4 ) ;
V_9 = F_1 ( V_2 , L_5 ) ;
if ( V_13 || V_9 ) {
F_3 ( V_6 , V_18 , V_13 , V_9 ) ;
F_3 ( V_6 , V_19 , V_13 , V_9 ) ;
}
V_13 = F_1 ( V_2 , L_6 ) ;
V_9 = F_1 ( V_2 , L_7 ) ;
if ( V_13 || V_9 ) {
F_3 ( V_6 , V_20 , V_13 , V_9 ) ;
F_3 ( V_6 , V_21 , V_13 , V_9 ) ;
}
}
