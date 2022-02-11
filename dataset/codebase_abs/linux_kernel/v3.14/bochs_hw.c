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
unsigned long V_17 , V_18 , V_19 , V_20 , V_21 ;
T_1 V_22 ;
if (
( V_16 -> V_23 [ 2 ] . V_13 & V_24 ) ) {
if ( F_12 ( V_16 , 2 , L_1 ) != 0 ) {
F_13 ( L_2 ) ;
return - V_25 ;
}
V_20 = F_14 ( V_16 , 2 ) ;
V_21 = F_15 ( V_16 , 2 ) ;
V_2 -> V_5 = F_16 ( V_20 , V_21 ) ;
if ( V_2 -> V_5 == NULL ) {
F_13 ( L_3 ) ;
return - V_26 ;
}
} else {
V_20 = V_9 ;
V_21 = 2 ;
if ( ! F_17 ( V_20 , V_21 , L_1 ) ) {
F_13 ( L_4 ) ;
return - V_25 ;
}
V_2 -> V_27 = 1 ;
}
V_22 = F_5 ( V_2 , V_28 ) ;
V_19 = F_5 ( V_2 , V_29 )
* 64 * 1024 ;
if ( ( V_22 & 0xfff0 ) != V_30 ) {
F_13 ( L_5 ) ;
return - V_31 ;
}
if ( ( V_16 -> V_23 [ 0 ] . V_13 & V_24 ) == 0 )
return - V_31 ;
V_17 = F_14 ( V_16 , 0 ) ;
V_18 = F_15 ( V_16 , 0 ) ;
if ( V_17 == 0 )
return - V_31 ;
if ( V_18 != V_19 ) {
F_13 ( L_6 ,
V_18 , V_19 ) ;
V_18 = F_18 ( V_18 , V_19 ) ;
}
if ( F_12 ( V_16 , 0 , L_1 ) != 0 ) {
F_13 ( L_7 ) ;
return - V_25 ;
}
V_2 -> V_32 = F_16 ( V_17 , V_18 ) ;
if ( V_2 -> V_32 == NULL ) {
F_13 ( L_8 ) ;
return - V_26 ;
}
V_2 -> V_33 = V_17 ;
V_2 -> V_34 = V_18 ;
F_19 ( L_9 , V_22 ) ;
F_19 ( L_10 ,
V_18 / 1024 , V_17 ,
V_2 -> V_27 ? L_11 : L_12 ,
V_20 ) ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
if ( V_2 -> V_5 )
F_21 ( V_2 -> V_5 ) ;
if ( V_2 -> V_27 )
F_22 ( V_9 , 2 ) ;
if ( V_2 -> V_32 )
F_21 ( V_2 -> V_32 ) ;
F_23 ( V_12 -> V_16 ) ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
V_2 -> V_37 = V_36 -> V_38 ;
V_2 -> V_39 = V_36 -> V_40 ;
V_2 -> V_41 = 32 ;
V_2 -> V_42 = V_36 -> V_38 * ( V_2 -> V_41 / 8 ) ;
V_2 -> V_43 = V_2 -> V_34 / V_2 -> V_42 ;
F_25 ( L_13 ,
V_2 -> V_37 , V_2 -> V_39 , V_2 -> V_41 ,
V_2 -> V_43 ) ;
F_1 ( V_2 , 0x3c0 , 0x20 ) ;
F_9 ( V_2 , V_44 , V_2 -> V_41 ) ;
F_9 ( V_2 , V_45 , V_2 -> V_37 ) ;
F_9 ( V_2 , V_46 , V_2 -> V_39 ) ;
F_9 ( V_2 , V_47 , 0 ) ;
F_9 ( V_2 , V_48 , V_2 -> V_37 ) ;
F_9 ( V_2 , V_49 ,
V_2 -> V_43 ) ;
F_9 ( V_2 , V_50 , 0 ) ;
F_9 ( V_2 , V_51 , 0 ) ;
F_9 ( V_2 , V_52 ,
V_53 | V_54 ) ;
}
void F_26 ( struct V_1 * V_2 ,
int V_55 , int V_56 , T_4 V_17 )
{
unsigned long V_6 = ( unsigned long ) V_17 +
V_56 * V_2 -> V_42 +
V_55 * ( V_2 -> V_41 / 8 ) ;
int V_57 = V_6 / V_2 -> V_42 ;
int V_58 = ( V_6 % V_2 -> V_42 ) * 8 / V_2 -> V_41 ;
F_25 ( L_14 ,
V_55 , V_56 , V_17 , V_6 , V_58 , V_57 ) ;
F_9 ( V_2 , V_50 , V_58 ) ;
F_9 ( V_2 , V_51 , V_57 ) ;
}
