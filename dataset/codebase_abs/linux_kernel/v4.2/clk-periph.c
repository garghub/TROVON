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
V_6 &= F_4 ( V_5 -> V_10 ) ;
V_3 /= ( V_6 + 1 ) ;
}
div = ( ( F_3 ( V_5 -> V_11 . V_12 ) & 0x1ff ) + 1 ) ;
}
return V_3 / div ;
}
static T_2 void F_5 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
T_1 V_12 ;
struct V_17 * V_17 ;
struct V_4 * V_18 ;
const char * V_19 = V_14 -> V_20 ;
const char * V_21 ;
struct V_22 V_23 ;
int V_24 ;
T_1 V_7 ;
T_1 V_8 [ 3 ] ;
F_6 ( V_14 , L_1 , & V_12 ) ;
V_18 = F_7 ( sizeof( * V_18 ) , V_25 ) ;
if ( F_8 ( ! V_18 ) )
return;
V_18 -> V_11 . V_12 = V_26 + V_12 ;
V_24 = F_9 ( V_14 , L_2 , V_8 , 3 ) ;
if ( ! V_24 ) {
V_18 -> V_8 = V_26 + V_8 [ 0 ] ;
V_18 -> V_9 = V_8 [ 1 ] ;
V_18 -> V_10 = V_8 [ 2 ] ;
} else {
V_18 -> V_8 = NULL ;
}
V_24 = F_6 ( V_14 , L_3 , & V_7 ) ;
if ( V_24 )
V_18 -> V_7 = 0 ;
else
V_18 -> V_7 = V_7 ;
F_10 ( V_14 , L_4 , & V_19 ) ;
V_23 . V_20 = V_19 ;
V_23 . V_16 = V_16 ;
V_23 . V_27 = 0 ;
V_21 = F_11 ( V_14 , 0 ) ;
V_23 . V_28 = & V_21 ;
V_23 . V_29 = 1 ;
V_18 -> V_11 . V_11 . V_23 = & V_23 ;
V_17 = F_12 ( NULL , & V_18 -> V_11 . V_11 ) ;
if ( F_8 ( F_13 ( V_17 ) ) ) {
F_14 ( V_18 ) ;
return;
}
V_24 = F_15 ( V_14 , V_30 , V_17 ) ;
}
void T_2 F_16 ( struct V_13 * V_14 )
{
F_5 ( V_14 , & V_31 ) ;
}
