static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 div ;
if ( V_5 -> V_6 )
div = V_5 -> V_6 ;
else
div = ( ( F_3 ( V_5 -> V_7 . V_8 ) & 0x1ff ) + 1 ) ;
return V_3 / div ;
}
static T_2 void F_4 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
T_1 V_8 ;
struct V_13 * V_13 ;
struct V_4 * V_14 ;
const char * V_15 = V_10 -> V_16 ;
const char * V_17 ;
struct V_18 V_19 ;
int V_20 ;
T_1 V_6 ;
F_5 ( V_10 , L_1 , & V_8 ) ;
V_14 = F_6 ( sizeof( * V_14 ) , V_21 ) ;
if ( F_7 ( ! V_14 ) )
return;
V_14 -> V_7 . V_8 = V_22 + V_8 ;
V_20 = F_5 ( V_10 , L_2 , & V_6 ) ;
if ( V_20 )
V_14 -> V_6 = 0 ;
else
V_14 -> V_6 = V_6 ;
F_8 ( V_10 , L_3 , & V_15 ) ;
V_19 . V_16 = V_15 ;
V_19 . V_12 = V_12 ;
V_19 . V_23 = 0 ;
V_17 = F_9 ( V_10 , 0 ) ;
V_19 . V_24 = & V_17 ;
V_19 . V_25 = 1 ;
V_14 -> V_7 . V_7 . V_19 = & V_19 ;
V_13 = F_10 ( NULL , & V_14 -> V_7 . V_7 ) ;
if ( F_7 ( F_11 ( V_13 ) ) ) {
F_12 ( V_14 ) ;
return;
}
V_20 = F_13 ( V_10 , V_26 , V_13 ) ;
}
void T_2 F_14 ( struct V_9 * V_10 )
{
F_4 ( V_10 , & V_27 ) ;
}
