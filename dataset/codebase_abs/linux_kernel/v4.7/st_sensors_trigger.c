T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_9 = F_4 () ;
return V_10 ;
}
T_1 F_5 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_11 ;
if ( V_8 -> V_12 -> V_13 . V_14 ) {
T_2 V_15 ;
V_11 = V_8 -> V_16 -> V_17 ( & V_8 -> V_18 , V_8 -> V_19 ,
V_8 -> V_12 -> V_13 . V_14 ,
& V_15 ) ;
if ( V_11 < 0 ) {
F_6 ( V_8 -> V_19 , L_1 ) ;
goto V_20;
}
V_15 &= 0x07 ;
if ( ! V_6 -> V_21 )
return V_22 ;
if ( ! ( V_15 & ( T_2 ) V_6 -> V_21 [ 0 ] ) )
return V_22 ;
}
V_20:
F_7 ( V_2 ) ;
return V_23 ;
}
int F_8 ( struct V_5 * V_6 ,
const struct V_24 * V_25 )
{
int V_26 , V_1 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_27 ;
V_8 -> V_4 = F_9 ( L_2 , V_6 -> V_28 ) ;
if ( V_8 -> V_4 == NULL ) {
F_6 ( & V_6 -> V_19 , L_3 ) ;
return - V_29 ;
}
F_10 ( V_8 -> V_4 , V_6 ) ;
V_8 -> V_4 -> V_30 = V_25 ;
V_8 -> V_4 -> V_19 . V_31 = V_8 -> V_19 ;
V_1 = V_8 -> V_32 ( V_6 ) ;
V_27 = F_11 ( F_12 ( V_1 ) ) ;
if ( V_27 == V_33 ) {
if ( ! V_8 -> V_12 -> V_13 . V_34 ) {
F_6 ( & V_6 -> V_19 ,
L_4
L_5
L_6 ) ;
V_27 = V_35 ;
} else {
V_26 = F_13 ( V_6 ,
V_8 -> V_12 -> V_13 . V_34 ,
V_8 -> V_12 -> V_13 . V_36 , 1 ) ;
if ( V_26 < 0 )
goto V_37;
F_14 ( & V_6 -> V_19 ,
L_7 ) ;
}
} else if ( V_27 == V_35 ) {
F_14 ( & V_6 -> V_19 ,
L_8 ) ;
} else {
F_6 ( & V_6 -> V_19 ,
L_9
L_10
L_6 , V_27 ) ;
V_27 = V_35 ;
}
if ( V_8 -> V_38 &&
V_8 -> V_12 -> V_13 . V_14 )
V_27 |= V_39 ;
V_27 |= V_40 ;
V_26 = F_15 ( V_8 -> V_32 ( V_6 ) ,
F_1 ,
F_5 ,
V_27 ,
V_8 -> V_4 -> V_28 ,
V_8 -> V_4 ) ;
if ( V_26 ) {
F_6 ( & V_6 -> V_19 , L_11 ) ;
goto V_37;
}
V_26 = F_16 ( V_8 -> V_4 ) ;
if ( V_26 < 0 ) {
F_6 ( & V_6 -> V_19 , L_12 ) ;
goto V_41;
}
V_6 -> V_4 = F_17 ( V_8 -> V_4 ) ;
return 0 ;
V_41:
F_18 ( V_8 -> V_32 ( V_6 ) , V_8 -> V_4 ) ;
V_37:
V_37 ( V_8 -> V_4 ) ;
return V_26 ;
}
void F_19 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_20 ( V_8 -> V_4 ) ;
F_18 ( V_8 -> V_32 ( V_6 ) , V_8 -> V_4 ) ;
V_37 ( V_8 -> V_4 ) ;
}
int F_21 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_5 * V_42 = F_2 ( V_4 ) ;
if ( V_42 != V_6 )
return - V_43 ;
return 0 ;
}
