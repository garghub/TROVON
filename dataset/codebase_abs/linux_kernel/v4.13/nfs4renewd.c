void
F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 . V_2 ) ;
struct V_8 * V_9 ;
long V_10 ;
unsigned long V_11 , V_12 ;
unsigned V_13 = 0 ;
V_4 = V_6 -> V_14 -> V_15 ;
F_3 ( L_1 , V_16 ) ;
if ( F_4 ( V_17 , & V_6 -> V_18 ) )
goto V_19;
F_5 ( & V_6 -> V_20 ) ;
V_10 = V_6 -> V_21 ;
V_11 = V_6 -> V_22 ;
V_12 = V_23 ;
if ( F_6 ( V_12 , V_11 + V_10 / 3 ) )
V_13 |= V_24 ;
if ( F_7 ( V_6 ) )
V_13 |= V_25 ;
if ( V_13 != 0 ) {
V_9 = V_4 -> V_26 ( V_6 ) ;
F_8 ( & V_6 -> V_20 ) ;
if ( V_9 == NULL ) {
if ( ! ( V_13 & V_25 ) ) {
F_9 ( V_27 , & V_6 -> V_28 ) ;
goto V_19;
}
F_10 ( V_6 ) ;
} else {
int V_29 ;
V_29 = V_4 -> V_30 ( V_6 , V_9 , V_13 ) ;
F_11 ( V_9 ) ;
switch ( V_29 ) {
default:
goto V_31;
case - V_32 :
case - V_33 :
break;
}
}
} else {
F_3 ( L_2 ,
V_16 ) ;
F_8 ( & V_6 -> V_20 ) ;
}
F_12 ( V_6 ) ;
V_31:
F_13 ( V_6 ) ;
V_19:
F_3 ( L_3 , V_16 ) ;
}
void
F_12 ( struct V_5 * V_6 )
{
long V_34 ;
F_5 ( & V_6 -> V_20 ) ;
V_34 = ( 2 * V_6 -> V_21 ) / 3 + ( long ) V_6 -> V_22
- ( long ) V_23 ;
if ( V_34 < 5 * V_35 )
V_34 = 5 * V_35 ;
F_3 ( L_4 ,
V_16 , ( V_34 + V_35 - 1 ) / V_35 ) ;
F_14 ( V_36 , & V_6 -> V_7 , V_34 ) ;
F_9 ( V_37 , & V_6 -> V_18 ) ;
F_8 ( & V_6 -> V_20 ) ;
}
void
F_15 ( struct V_5 * V_6 )
{
F_16 ( & V_6 -> V_7 ) ;
}
void F_17 ( struct V_5 * V_6 ,
unsigned long V_10 ,
unsigned long V_38 )
{
F_5 ( & V_6 -> V_20 ) ;
V_6 -> V_21 = V_10 ;
V_6 -> V_22 = V_38 ;
F_8 ( & V_6 -> V_20 ) ;
F_18 ( V_6 -> V_39 , V_10 , V_10 >> 1 ) ;
}
