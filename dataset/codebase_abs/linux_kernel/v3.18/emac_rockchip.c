static void F_1 ( void * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = V_1 ;
T_1 V_5 ;
int V_6 = 0 ;
V_5 = V_7 ;
switch( V_2 ) {
case 10 :
V_5 |= V_8 ;
break;
case 100 :
V_5 |= V_9 ;
break;
default:
F_2 ( L_1 , V_2 ) ;
return;
}
V_6 = F_3 ( V_4 -> V_10 , V_4 -> V_11 -> V_12 , V_5 ) ;
if ( V_6 )
F_2 ( L_2 , V_2 , V_6 ) ;
}
static int F_4 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
struct V_17 * V_18 ;
struct V_3 * V_1 ;
const struct V_19 * V_20 ;
T_1 V_5 ;
int V_6 , V_21 ;
if ( ! V_14 -> V_16 . V_22 )
return - V_23 ;
V_18 = F_5 ( sizeof( struct V_3 ) ) ;
if ( ! V_18 )
return - V_24 ;
F_6 ( V_14 , V_18 ) ;
F_7 ( V_18 , V_16 ) ;
V_1 = F_8 ( V_18 ) ;
V_1 -> V_4 . V_25 = V_26 ;
V_1 -> V_4 . V_27 = V_28 ;
V_1 -> V_4 . V_29 = F_1 ;
V_21 = F_9 ( V_16 -> V_22 ) ;
if ( V_21 != V_30 ) {
F_10 ( V_16 , L_3 , V_21 ) ;
V_6 = - V_31 ;
goto V_32;
}
V_1 -> V_10 = F_11 ( V_16 -> V_22 , L_4 ) ;
if ( F_12 ( V_1 -> V_10 ) ) {
F_10 ( V_16 , L_5 , F_13 ( V_1 -> V_10 ) ) ;
V_6 = F_13 ( V_1 -> V_10 ) ;
goto V_32;
}
V_20 = F_14 ( V_33 , V_16 -> V_22 ) ;
V_1 -> V_11 = V_20 -> V_5 ;
V_1 -> V_4 . V_34 = F_15 ( V_16 , L_6 ) ;
if ( F_12 ( V_1 -> V_4 . V_34 ) ) {
F_10 ( V_16 , L_7 , F_13 ( V_1 -> V_4 . V_34 ) ) ;
V_6 = F_13 ( V_1 -> V_4 . V_34 ) ;
goto V_32;
}
V_1 -> V_35 = F_15 ( V_16 , L_8 ) ;
if ( F_12 ( V_1 -> V_35 ) ) {
F_10 ( V_16 , L_9 , F_13 ( V_1 -> V_35 ) ) ;
V_6 = F_13 ( V_1 -> V_35 ) ;
goto V_32;
}
V_6 = F_16 ( V_1 -> V_35 ) ;
if ( V_6 ) {
F_10 ( V_16 , L_10 , V_6 ) ;
goto V_32;
}
V_1 -> V_36 = F_17 ( V_16 , L_11 ) ;
if ( F_12 ( V_1 -> V_36 ) ) {
if ( F_13 ( V_1 -> V_36 ) == - V_37 )
return - V_37 ;
F_10 ( V_16 , L_12 ) ;
V_1 -> V_36 = NULL ;
}
if ( V_1 -> V_36 ) {
V_6 = F_18 ( V_1 -> V_36 ) ;
if ( V_6 ) {
F_10 ( V_16 , L_13 , V_6 ) ;
goto V_38;
}
}
V_6 = F_19 ( V_18 , V_21 ) ;
if ( V_6 )
goto V_39;
V_5 = V_40 | V_7 ;
V_5 |= V_9 ;
V_5 |= V_41 ;
V_6 = F_3 ( V_1 -> V_10 , V_1 -> V_11 -> V_12 , V_5 ) ;
if ( V_6 ) {
F_10 ( V_16 , L_14 , V_6 ) ;
goto V_39;
}
V_6 = F_20 ( V_1 -> V_35 , 50000000 ) ;
if ( V_6 )
F_10 ( V_16 , L_15 , V_6 ) ;
return 0 ;
V_39:
if ( V_1 -> V_36 )
F_21 ( V_1 -> V_36 ) ;
V_38:
F_22 ( V_1 -> V_35 ) ;
V_32:
F_23 ( V_18 ) ;
return V_6 ;
}
static int F_24 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = F_25 ( V_14 ) ;
struct V_3 * V_1 = F_8 ( V_18 ) ;
int V_6 ;
V_6 = F_26 ( V_18 ) ;
F_22 ( V_1 -> V_35 ) ;
if ( V_1 -> V_36 )
F_21 ( V_1 -> V_36 ) ;
F_23 ( V_18 ) ;
return V_6 ;
}
