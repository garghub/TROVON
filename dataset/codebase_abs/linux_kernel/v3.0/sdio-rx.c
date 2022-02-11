static T_1 F_1 ( struct V_1 * V_1 )
{
int V_2 , V_3 , V_4 ;
T_1 V_5 ;
unsigned V_6 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_1 -> V_8 -> V_10 ;
F_2 ( 7 , V_10 , L_1 , V_1 ) ;
V_6 = V_11 ;
V_5 = 0 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_4 = F_3 ( V_8 , V_6 + V_3 , & V_2 ) ;
if ( V_2 < 0 ) {
F_4 ( V_10 , L_2
L_3 , V_3 , V_6 + V_3 , V_2 ) ;
V_5 = V_2 ;
goto V_12;
}
V_5 = V_5 << 8 | ( V_4 & 0xff ) ;
}
F_5 ( 6 , V_10 , L_4 , ( long ) V_5 ) ;
V_12:
F_6 ( 7 , V_10 , L_5 , V_1 , ( long ) V_5 ) ;
return V_5 ;
}
static
void F_7 ( struct V_1 * V_1 )
{
int V_2 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_13 * V_13 = & V_1 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_5 ;
F_2 ( 7 , V_10 , L_1 , V_1 ) ;
V_5 = F_1 ( V_1 ) ;
if ( V_5 < 0 ) {
V_2 = V_5 ;
goto V_16;
}
F_8 ( V_8 , 1 , V_17 , & V_2 ) ;
V_2 = - V_18 ;
V_15 = F_9 ( V_5 , V_19 ) ;
if ( NULL == V_15 ) {
F_4 ( V_10 , L_6 ) ;
goto V_20;
}
V_2 = F_10 ( V_8 , V_15 -> V_21 ,
V_22 , V_5 ) ;
if ( V_2 < 0 ) {
F_4 ( V_10 , L_7 , V_2 ) ;
goto V_23;
}
F_11 () ;
if ( F_12 ( V_13 -> V_24 == 1 ) ) {
F_13 ( & V_13 -> V_25 ) ;
V_1 -> V_26 = V_5 ;
F_14 ( & V_13 -> V_25 ) ;
memcpy ( V_13 -> V_27 , V_15 -> V_21 , V_5 ) ;
F_15 ( & V_1 -> V_28 ) ;
F_5 ( 5 , V_10 , L_8 ) ;
F_16 ( V_15 ) ;
goto V_29;
}
V_2 = - V_30 ;
if ( F_12 ( V_5 < sizeof( V_31 ) ) ) {
F_4 ( V_10 , L_9 , V_5 ) ;
goto V_32;
}
if ( F_17 ( F_18 ( V_15 -> V_21 ) ) ) {
F_19 ( V_15 , V_5 ) ;
F_20 ( V_13 , V_15 ) ;
} else if ( F_12 ( F_21 ( V_13 ,
V_15 -> V_21 , V_5 ) ) ) {
V_2 = F_22 ( V_13 , L_10 ) ;
F_4 ( V_10 , L_11 ) ;
F_16 ( V_15 ) ;
} else {
F_23 ( V_13 , V_15 -> V_21 , V_5 ) ;
F_16 ( V_15 ) ;
}
V_29:
F_6 ( 7 , V_10 , L_12 , V_1 ) ;
return;
V_23:
F_16 ( V_15 ) ;
V_20:
V_16:
V_32:
F_6 ( 7 , V_10 , L_13 , V_1 , V_2 ) ;
}
static
void F_24 ( struct V_7 * V_8 )
{
int V_2 ;
struct V_1 * V_1 = F_25 ( V_8 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
int V_4 ;
F_2 ( 6 , V_10 , L_1 , V_1 ) ;
V_4 = F_3 ( V_8 , V_33 , & V_2 ) ;
if ( V_2 < 0 ) {
F_4 ( V_10 , L_14 , V_2 ) ;
goto V_34;
}
if ( ! V_4 ) {
F_4 ( V_10 , L_15 ) ;
goto V_34;
}
F_7 ( V_1 ) ;
V_34:
F_6 ( 6 , V_10 , L_12 , V_1 ) ;
}
int F_26 ( struct V_1 * V_1 )
{
int V_35 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_13 * V_13 = & V_1 -> V_13 ;
F_2 ( 5 , V_10 , L_1 , V_1 ) ;
F_27 ( & V_1 -> V_28 ) ;
F_13 ( & V_13 -> V_25 ) ;
V_1 -> V_36 = - V_37 ;
V_1 -> V_26 = - V_37 ;
F_14 ( & V_13 -> V_25 ) ;
F_28 ( V_8 ) ;
V_35 = F_29 ( V_8 , F_24 ) ;
if ( V_35 < 0 ) {
F_4 ( V_10 , L_16 , V_35 ) ;
goto V_38;
}
V_35 = 0 ;
F_8 ( V_8 , 1 , V_39 , & V_35 ) ;
if ( V_35 < 0 ) {
F_30 ( V_8 ) ;
F_4 ( V_10 , L_17 , V_35 ) ;
}
V_38:
F_31 ( V_8 ) ;
F_6 ( 5 , V_10 , L_13 , V_1 , V_35 ) ;
return V_35 ;
}
void F_32 ( struct V_1 * V_1 )
{
int V_35 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_13 * V_13 = & V_1 -> V_13 ;
F_2 ( 5 , V_10 , L_1 , V_1 ) ;
F_13 ( & V_13 -> V_25 ) ;
V_1 -> V_26 = - V_40 ;
F_14 ( & V_13 -> V_25 ) ;
F_33 ( & V_1 -> V_28 ) ;
F_28 ( V_8 ) ;
F_8 ( V_8 , 0 , V_39 , & V_35 ) ;
F_30 ( V_8 ) ;
F_31 ( V_8 ) ;
F_6 ( 5 , V_10 , L_13 , V_1 , V_35 ) ;
}
