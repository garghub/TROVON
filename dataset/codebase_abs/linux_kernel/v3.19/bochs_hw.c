static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( F_2 ( V_3 < 0x3c0 || V_3 > 0x3df ) )
return;
if ( V_2 -> V_5 ) {
int V_6 = V_3 - 0x3c0 + 0x400 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
} else {
F_4 ( V_4 , V_3 ) ;
}
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
T_1 V_8 = 0 ;
if ( V_2 -> V_5 ) {
int V_6 = 0x500 + ( V_7 << 1 ) ;
V_8 = F_6 ( V_2 -> V_5 + V_6 ) ;
} else {
F_7 ( V_7 , V_9 ) ;
V_8 = F_8 ( V_10 ) ;
}
return V_8 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_4 )
{
if ( V_2 -> V_5 ) {
int V_6 = 0x500 + ( V_7 << 1 ) ;
F_10 ( V_4 , V_2 -> V_5 + V_6 ) ;
} else {
F_7 ( V_7 , V_9 ) ;
F_7 ( V_4 , V_10 ) ;
}
}
int F_11 ( struct V_11 * V_12 , T_3 V_13 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
struct V_15 * V_16 = V_12 -> V_16 ;
unsigned long V_17 , V_18 , V_19 , V_20 , V_21 , V_22 ;
T_1 V_23 ;
if ( V_16 -> V_24 [ 2 ] . V_13 & V_25 ) {
if ( F_12 ( V_16 , 2 , L_1 ) != 0 ) {
F_13 ( L_2 ) ;
return - V_26 ;
}
V_20 = F_14 ( V_16 , 2 ) ;
V_21 = F_15 ( V_16 , 2 ) ;
V_2 -> V_5 = F_16 ( V_20 , V_21 ) ;
if ( V_2 -> V_5 == NULL ) {
F_13 ( L_3 ) ;
return - V_27 ;
}
} else {
V_20 = V_9 ;
V_21 = 2 ;
if ( ! F_17 ( V_20 , V_21 , L_1 ) ) {
F_13 ( L_4 ) ;
return - V_26 ;
}
V_2 -> V_28 = 1 ;
}
V_23 = F_5 ( V_2 , V_29 ) ;
V_19 = F_5 ( V_2 , V_30 )
* 64 * 1024 ;
if ( ( V_23 & 0xfff0 ) != V_31 ) {
F_13 ( L_5 ) ;
return - V_32 ;
}
if ( ( V_16 -> V_24 [ 0 ] . V_13 & V_25 ) == 0 )
return - V_32 ;
V_17 = F_14 ( V_16 , 0 ) ;
V_18 = F_15 ( V_16 , 0 ) ;
if ( V_17 == 0 )
return - V_32 ;
if ( V_18 != V_19 ) {
F_13 ( L_6 ,
V_18 , V_19 ) ;
V_18 = F_18 ( V_18 , V_19 ) ;
}
if ( F_12 ( V_16 , 0 , L_1 ) != 0 ) {
F_13 ( L_7 ) ;
return - V_26 ;
}
V_2 -> V_33 = F_16 ( V_17 , V_18 ) ;
if ( V_2 -> V_33 == NULL ) {
F_13 ( L_8 ) ;
return - V_27 ;
}
V_2 -> V_34 = V_17 ;
V_2 -> V_35 = V_18 ;
F_19 ( L_9 , V_23 ) ;
F_19 ( L_10 ,
V_18 / 1024 , V_17 ,
V_2 -> V_28 ? L_11 : L_12 ,
V_20 ) ;
if ( V_2 -> V_5 && V_16 -> V_36 >= 2 ) {
V_22 = F_20 ( V_2 -> V_5 + 0x600 ) ;
if ( V_22 < 4 || V_22 > V_21 )
goto V_37;
F_21 ( L_13 , V_22 ) ;
if ( V_22 >= 8 ) {
#ifdef F_22
F_23 ( 0xbebebebe , V_2 -> V_5 + 0x604 ) ;
#else
F_23 ( 0x1e1e1e1e , V_2 -> V_5 + 0x604 ) ;
#endif
F_21 ( L_14 ,
F_20 ( V_2 -> V_5 + 0x604 ) ) ;
}
}
V_37:
return 0 ;
}
void F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
if ( V_2 -> V_5 )
F_25 ( V_2 -> V_5 ) ;
if ( V_2 -> V_28 )
F_26 ( V_9 , 2 ) ;
if ( V_2 -> V_33 )
F_25 ( V_2 -> V_33 ) ;
F_27 ( V_12 -> V_16 ) ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
V_2 -> V_40 = V_39 -> V_41 ;
V_2 -> V_42 = V_39 -> V_43 ;
V_2 -> V_44 = 32 ;
V_2 -> V_45 = V_39 -> V_41 * ( V_2 -> V_44 / 8 ) ;
V_2 -> V_46 = V_2 -> V_35 / V_2 -> V_45 ;
F_29 ( L_15 ,
V_2 -> V_40 , V_2 -> V_42 , V_2 -> V_44 ,
V_2 -> V_46 ) ;
F_1 ( V_2 , 0x3c0 , 0x20 ) ;
F_9 ( V_2 , V_47 , V_2 -> V_44 ) ;
F_9 ( V_2 , V_48 , V_2 -> V_40 ) ;
F_9 ( V_2 , V_49 , V_2 -> V_42 ) ;
F_9 ( V_2 , V_50 , 0 ) ;
F_9 ( V_2 , V_51 , V_2 -> V_40 ) ;
F_9 ( V_2 , V_52 ,
V_2 -> V_46 ) ;
F_9 ( V_2 , V_53 , 0 ) ;
F_9 ( V_2 , V_54 , 0 ) ;
F_9 ( V_2 , V_55 ,
V_56 | V_57 ) ;
}
void F_30 ( struct V_1 * V_2 ,
int V_58 , int V_59 , T_4 V_17 )
{
unsigned long V_6 = ( unsigned long ) V_17 +
V_59 * V_2 -> V_45 +
V_58 * ( V_2 -> V_44 / 8 ) ;
int V_60 = V_6 / V_2 -> V_45 ;
int V_61 = ( V_6 % V_2 -> V_45 ) * 8 / V_2 -> V_44 ;
F_29 ( L_16 ,
V_58 , V_59 , V_17 , V_6 , V_61 , V_60 ) ;
F_9 ( V_2 , V_53 , V_61 ) ;
F_9 ( V_2 , V_54 , V_60 ) ;
}
