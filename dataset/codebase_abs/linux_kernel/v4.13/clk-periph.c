static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 div , V_6 ;
if ( V_5 -> V_7 ) {
div = V_5 -> V_7 ;
} else {
if ( V_5 -> V_8 ) {
V_6 = F_3 ( V_5 -> V_8 ) >> V_5 -> V_9 ;
V_6 &= F_4 ( V_5 -> V_10 - 1 , 0 ) ;
V_3 /= ( V_6 + 1 ) ;
}
div = ( ( F_3 ( V_5 -> V_11 . V_12 ) & 0x1ff ) + 1 ) ;
}
return V_3 / div ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
T_1 V_13 ;
V_13 = F_3 ( V_14 + V_15 ) ;
return V_13 & 0x1 ;
}
static T_3 void F_6 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
T_1 V_12 ;
struct V_20 * V_20 ;
struct V_4 * V_21 ;
const char * V_22 = V_17 -> V_23 ;
const char * V_24 [ V_25 ] ;
struct V_26 V_27 ;
int V_28 ;
T_1 V_7 ;
T_1 V_8 [ 3 ] ;
F_7 ( V_17 , L_1 , & V_12 ) ;
V_21 = F_8 ( sizeof( * V_21 ) , V_29 ) ;
if ( F_9 ( ! V_21 ) )
return;
V_21 -> V_11 . V_12 = V_14 + V_12 ;
V_28 = F_10 ( V_17 , L_2 , V_8 , 3 ) ;
if ( ! V_28 ) {
V_21 -> V_8 = V_14 + V_8 [ 0 ] ;
V_21 -> V_9 = V_8 [ 1 ] ;
V_21 -> V_10 = V_8 [ 2 ] ;
} else {
V_21 -> V_8 = NULL ;
}
V_28 = F_7 ( V_17 , L_3 , & V_7 ) ;
if ( V_28 )
V_21 -> V_7 = 0 ;
else
V_21 -> V_7 = V_7 ;
F_11 ( V_17 , L_4 , & V_22 ) ;
V_27 . V_23 = V_22 ;
V_27 . V_19 = V_19 ;
V_27 . V_30 = 0 ;
V_27 . V_31 = F_12 ( V_17 , V_24 ,
V_25 ) ;
V_27 . V_32 = V_24 ;
V_21 -> V_11 . V_11 . V_27 = & V_27 ;
V_20 = F_13 ( NULL , & V_21 -> V_11 . V_11 ) ;
if ( F_9 ( F_14 ( V_20 ) ) ) {
F_15 ( V_21 ) ;
return;
}
V_28 = F_16 ( V_17 , V_33 , V_20 ) ;
}
void T_3 F_17 ( struct V_16 * V_17 )
{
F_6 ( V_17 , & V_34 ) ;
}
