static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 div ;
if ( V_5 -> V_6 ) {
div = V_5 -> V_6 ;
} else if ( V_5 -> V_7 ) {
div = F_3 ( V_5 -> V_7 ) >> V_5 -> V_8 ;
div &= F_4 ( V_5 -> V_9 - 1 , 0 ) ;
div += 1 ;
} else {
div = ( ( F_3 ( V_5 -> V_10 . V_11 ) & 0x7ff ) + 1 ) ;
}
return V_3 / div ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_12 ;
V_12 = F_3 ( V_5 -> V_10 . V_11 ) ;
if ( F_6 ( V_2 -> V_13 -> V_14 , V_15 ) ||
F_6 ( V_2 -> V_13 -> V_14 , V_16 ) ||
F_6 ( V_2 -> V_13 -> V_14 , V_17 ) )
return ( V_12 >> V_18 ) &
V_19 ;
else
return 0 ;
}
static T_3 void F_7 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
T_1 V_11 ;
struct V_24 * V_24 ;
struct V_4 * V_25 ;
const char * V_26 = V_21 -> V_14 ;
const char * V_27 ;
struct V_28 V_13 ;
int V_29 ;
T_1 V_6 ;
T_1 V_7 [ 3 ] ;
F_8 ( V_21 , L_1 , & V_11 ) ;
V_25 = F_9 ( sizeof( * V_25 ) , V_30 ) ;
if ( F_10 ( ! V_25 ) )
return;
V_25 -> V_10 . V_11 = V_31 + V_11 ;
V_29 = F_11 ( V_21 , L_2 , V_7 , 3 ) ;
if ( ! V_29 ) {
V_25 -> V_7 = V_31 + V_7 [ 0 ] ;
V_25 -> V_8 = V_7 [ 1 ] ;
V_25 -> V_9 = V_7 [ 2 ] ;
} else {
V_25 -> V_7 = NULL ;
}
V_29 = F_8 ( V_21 , L_3 , & V_6 ) ;
if ( V_29 )
V_25 -> V_6 = 0 ;
else
V_25 -> V_6 = V_6 ;
F_12 ( V_21 , L_4 , & V_26 ) ;
V_13 . V_14 = V_26 ;
V_13 . V_23 = V_23 ;
V_13 . V_32 = 0 ;
V_27 = F_13 ( V_21 , 0 ) ;
V_13 . V_33 = 1 ;
V_13 . V_34 = & V_27 ;
V_25 -> V_10 . V_10 . V_13 = & V_13 ;
V_24 = F_14 ( NULL , & V_25 -> V_10 . V_10 ) ;
if ( F_10 ( F_15 ( V_24 ) ) ) {
F_16 ( V_25 ) ;
return;
}
V_29 = F_17 ( V_21 , V_35 , V_24 ) ;
if ( V_29 < 0 ) {
F_18 ( L_5 ,
V_26 ) ;
goto V_36;
}
return;
V_36:
F_19 ( V_24 ) ;
}
void T_3 F_20 ( struct V_20 * V_21 )
{
F_7 ( V_21 , & V_37 ) ;
}
