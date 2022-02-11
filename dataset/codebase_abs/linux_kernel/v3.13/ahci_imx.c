static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
void T_2 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_2 -> V_5 -> V_14 ) ;
F_3 ( V_2 ) ;
if ( ! ( V_13 -> V_15 ) || V_16 )
return;
V_13 -> V_15 = false ;
F_4 (dev, &ap->link, ENABLED)
return;
V_3 = F_5 ( V_11 + V_17 ) ;
F_6 ( V_3 | V_18 , V_11 + V_17 ) ;
F_7 ( V_13 -> V_19 , V_20 ,
V_21 ,
! V_21 ) ;
F_8 ( V_13 -> V_22 ) ;
V_13 -> V_23 = true ;
}
static int F_9 ( struct V_24 * V_5 , void T_2 * V_11 )
{
int V_25 = 0 ;
unsigned int V_3 ;
struct V_12 * V_13 = F_2 ( V_5 -> V_14 ) ;
V_13 -> V_19 =
F_10 ( L_1 ) ;
if ( F_11 ( V_13 -> V_19 ) ) {
F_12 ( V_5 , L_2 ) ;
return F_13 ( V_13 -> V_19 ) ;
}
V_25 = F_14 ( V_13 -> V_22 ) ;
if ( V_25 < 0 ) {
F_12 ( V_5 , L_3 , V_25 ) ;
return V_25 ;
}
F_7 ( V_13 -> V_19 , 0x34 , V_26
| V_27
| V_28
| V_29
| V_30
| V_31
| V_32
| V_33
| V_21
| V_34
, V_35
| V_36
| V_37
| V_38
| V_30
| V_39
| V_40
| V_41 ) ;
F_7 ( V_13 -> V_19 , 0x34 , V_21 ,
V_21 ) ;
F_15 ( 100 , 200 ) ;
V_3 = F_5 ( V_11 + V_42 ) ;
if ( ! ( V_3 & V_43 ) ) {
V_3 |= V_43 ;
F_6 ( V_3 , V_11 + V_42 ) ;
}
V_3 = F_5 ( V_11 + V_44 ) ;
if ( ! ( V_3 & 0x1 ) ) {
V_3 |= 0x1 ;
F_6 ( V_3 , V_11 + V_44 ) ;
}
V_3 = F_16 ( V_13 -> V_45 ) / 1000 ;
F_6 ( V_3 , V_11 + V_46 ) ;
return 0 ;
}
static void F_17 ( struct V_24 * V_5 )
{
struct V_12 * V_13 = F_2 ( V_5 -> V_14 ) ;
F_7 ( V_13 -> V_19 , 0x34 , V_21 ,
! V_21 ) ;
F_8 ( V_13 -> V_22 ) ;
}
static int F_18 ( struct V_24 * V_5 )
{
struct V_12 * V_13 = F_2 ( V_5 -> V_14 ) ;
if ( ! V_13 -> V_23 ) {
F_7 ( V_13 -> V_19 , V_20 ,
V_21 ,
! V_21 ) ;
F_8 ( V_13 -> V_22 ) ;
}
return 0 ;
}
static int F_19 ( struct V_24 * V_5 )
{
struct V_12 * V_13 = F_2 ( V_5 -> V_14 ) ;
int V_25 ;
if ( ! V_13 -> V_23 ) {
V_25 = F_14 ( V_13 -> V_22 ) ;
if ( V_25 < 0 ) {
F_12 ( V_5 , L_4 , V_25 ) ;
return V_25 ;
}
F_7 ( V_13 -> V_19 , V_20 ,
V_21 ,
V_21 ) ;
F_15 ( 1000 , 2000 ) ;
}
return 0 ;
}
static int F_20 ( struct V_47 * V_48 )
{
struct V_24 * V_5 = & V_48 -> V_5 ;
struct V_49 * V_50 , * V_51 , V_52 [ 2 ] ;
const struct V_53 * V_54 ;
const struct V_55 * V_56 = NULL ;
struct V_12 * V_13 ;
struct V_24 * V_57 ;
struct V_47 * V_58 ;
int V_25 ;
V_13 = F_21 ( V_5 , sizeof( * V_13 ) , V_59 ) ;
if ( ! V_13 ) {
F_12 ( V_5 , L_5 ) ;
return - V_60 ;
}
V_58 = F_22 ( L_6 , - 1 ) ;
if ( ! V_58 )
return - V_61 ;
V_57 = & V_58 -> V_5 ;
V_57 -> V_14 = V_5 ;
V_13 -> V_23 = false ;
V_13 -> V_15 = true ;
V_13 -> V_45 = F_23 ( V_5 , L_7 ) ;
if ( F_11 ( V_13 -> V_45 ) ) {
F_12 ( V_5 , L_8 ) ;
V_25 = F_13 ( V_13 -> V_45 ) ;
goto V_62;
}
V_13 -> V_22 = F_23 ( V_5 , L_9 ) ;
if ( F_11 ( V_13 -> V_22 ) ) {
F_12 ( V_5 , L_10 ) ;
V_25 = F_13 ( V_13 -> V_22 ) ;
goto V_62;
}
V_13 -> V_58 = V_58 ;
F_24 ( V_48 , V_13 ) ;
V_54 = F_25 ( V_63 , V_5 ) ;
if ( V_54 ) {
V_56 = V_54 -> V_64 ;
} else {
V_25 = - V_65 ;
goto V_62;
}
V_50 = F_26 ( V_48 , V_66 , 0 ) ;
V_51 = F_26 ( V_48 , V_67 , 0 ) ;
if ( ! V_50 || ! V_51 ) {
F_12 ( V_5 , L_11 ) ;
V_25 = - V_60 ;
goto V_62;
}
V_52 [ 0 ] = * V_50 ;
V_52 [ 1 ] = * V_51 ;
V_57 -> V_68 = F_27 ( 32 ) ;
V_57 -> V_69 = & V_57 -> V_68 ;
V_57 -> V_70 = V_5 -> V_70 ;
V_25 = F_28 ( V_58 , V_52 , 2 ) ;
if ( V_25 )
goto V_62;
V_25 = F_29 ( V_58 , V_56 , sizeof( * V_56 ) ) ;
if ( V_25 )
goto V_62;
V_25 = F_30 ( V_58 ) ;
if ( V_25 ) {
V_62:
F_31 ( V_58 ) ;
return V_25 ;
}
return 0 ;
}
static int F_32 ( struct V_47 * V_48 )
{
struct V_12 * V_13 = F_33 ( V_48 ) ;
struct V_47 * V_58 = V_13 -> V_58 ;
F_34 ( V_58 ) ;
return 0 ;
}
