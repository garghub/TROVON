static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
F_3 ( V_7 , V_5 -> V_8 + V_9 ) ;
V_6 = F_4 ( V_5 -> V_8 + V_10 ) ;
if ( V_3 == 1 )
F_3 ( V_6 | V_7 , V_5 -> V_8 + V_10 ) ;
else
F_3 ( V_6 & ~ V_7 , V_5 -> V_8 + V_10 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned long * V_13 ,
unsigned long * V_14 )
{
int V_15 = V_12 -> V_16 + 1900 ;
int V_17 = V_12 -> V_18 ;
if ( V_17 < - 1 || V_17 > 6 ) {
F_6 ( V_2 , L_1 , V_12 -> V_18 ) ;
return - V_19 ;
} else if ( V_17 == - 1 ) {
unsigned long time ;
struct V_11 V_20 ;
F_7 ( V_12 , & time ) ;
F_8 ( time , & V_20 ) ;
V_17 = V_20 . V_18 ;
}
* V_14 = ( F_9 ( V_15 % 100 ) | F_9 ( V_15 / 100 ) << 8 ) ;
* V_13 = ( ( V_12 -> V_21 + 1 ) << V_22 )
| ( V_12 -> V_23 << V_24 )
| ( ( V_17 + 1 ) << V_25 )
| ( V_12 -> V_26 << V_27 )
| ( V_12 -> V_28 << V_29 )
| ( V_12 -> V_30 << V_31 ) ;
return 0 ;
}
static int F_10 ( unsigned long V_13 , unsigned long V_14 ,
struct V_11 * V_12 )
{
V_12 -> V_16 = F_11 ( V_14 ) + ( F_11 ( V_14 >> 8 ) * 100 ) ;
V_12 -> V_21 = ( ( V_13 & V_32 ) >> V_22 ) - 1 ;
V_12 -> V_23 = ( ( V_13 & V_33 ) >> V_24 ) ;
V_12 -> V_18 = ( ( V_13 & V_34 ) >> V_25 ) - 1 ;
V_12 -> V_26 = ( ( V_13 & V_35 ) >> V_27 ) ;
V_12 -> V_28 = ( ( V_13 & V_36 ) >> V_29 ) ;
V_12 -> V_30 = ( ( V_13 & V_37 ) >> V_31 ) ;
V_12 -> V_38 = F_12 ( V_12 -> V_23 , V_12 -> V_21 , V_12 -> V_16 ) ;
V_12 -> V_16 -= 1900 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( F_4 ( V_5 -> V_8 + V_39 ) ,
F_4 ( V_5 -> V_8 + V_40 ) , V_12 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned long time ;
unsigned long V_14 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_41 ;
V_41 = F_5 ( V_2 , V_12 , & time , & V_14 ) ;
if ( V_41 == 0 ) {
F_3 ( V_14 , V_5 -> V_8 + V_42 ) ;
F_3 ( time , V_5 -> V_8 + V_43 ) ;
}
return V_41 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_41 ;
V_41 = F_10 ( F_4 ( V_5 -> V_8 + V_46 ) ,
F_4 ( V_5 -> V_8 + V_47 ) , & V_45 -> time ) ;
V_45 -> V_48 = F_4 ( V_5 -> V_8 + V_49 ) & V_7 ;
V_45 -> V_3 = F_4 ( V_5 -> V_8 + V_10 ) & V_7 ;
return V_41 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long time ;
unsigned long V_14 ;
int V_41 ;
V_41 = F_17 ( & V_45 -> time ) ;
if ( V_41 == 0 ) {
V_41 = F_5 ( V_2 , & V_45 -> time ,
& time , & V_14 ) ;
if ( V_41 == 0 ) {
F_3 ( V_14 , V_5 -> V_8 + V_47 ) ;
F_3 ( time , V_5 -> V_8 + V_46 ) ;
F_1 ( V_2 , V_45 -> V_3 ) ;
}
}
return V_41 ;
}
static T_1 F_18 ( int V_50 , void * V_51 )
{
struct V_4 * V_5 = V_51 ;
unsigned long V_52 ;
unsigned long V_53 = 0 ;
V_52 = F_4 ( V_5 -> V_8 + V_54 ) ;
if ( V_52 ) {
F_3 ( V_52 , V_5 -> V_8 + V_9 ) ;
if ( V_52 & V_7 )
V_53 |= ( V_55 | V_56 ) ;
if ( ( V_52 & V_57 ) &&
( V_5 -> V_58 == V_59 ) )
V_53 |= ( V_60 | V_56 ) ;
F_19 ( V_5 -> V_61 , 1 , V_53 ) ;
return V_62 ;
}
return V_63 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_8 ( F_4 ( V_5 -> V_8 + V_39 ) , V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned long time ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_41 ;
V_41 = F_7 ( V_12 , & time ) ;
if ( V_41 == 0 )
F_3 ( time , V_5 -> V_8 + V_43 ) ;
return V_41 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_8 ( F_4 ( V_5 -> V_8 + V_46 ) , & V_45 -> time ) ;
V_45 -> V_48 = F_4 ( V_5 -> V_8 + V_49 ) & V_7 ;
V_45 -> V_3 = F_4 ( V_5 -> V_8 + V_10 ) & V_7 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long time ;
int V_41 ;
V_41 = F_17 ( & V_45 -> time ) ;
if ( V_41 == 0 ) {
V_41 = F_7 ( & V_45 -> time , & time ) ;
if ( V_41 == 0 ) {
F_3 ( time , V_5 -> V_8 + V_46 ) ;
F_1 ( V_2 , V_45 -> V_3 ) ;
}
}
return V_41 ;
}
static int F_24 ( struct V_64 * V_65 )
{
struct V_4 * V_5 = F_2 ( & V_65 -> V_2 ) ;
F_25 ( V_65 , NULL ) ;
F_26 ( V_65 -> V_50 [ 0 ] , V_5 -> V_61 ) ;
F_27 ( V_5 -> V_61 ) ;
F_28 ( V_5 -> V_8 ) ;
F_29 ( V_5 ) ;
F_30 ( V_65 ) ;
return 0 ;
}
static int F_31 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
int V_41 ;
struct V_4 * V_5 ;
struct V_68 * V_69 = V_67 -> V_70 ;
unsigned long time ;
V_41 = F_32 ( V_65 , NULL ) ;
if ( V_41 )
goto V_71;
V_5 = F_33 ( sizeof( struct V_4 ) , V_72 ) ;
if ( ! V_5 ) {
V_41 = - V_73 ;
goto V_74;
}
V_5 -> V_8 = F_34 ( V_65 -> V_75 . V_76 , F_35 ( & V_65 -> V_75 ) ) ;
if ( ! V_5 -> V_8 ) {
V_41 = - V_73 ;
goto V_77;
}
F_25 ( V_65 , V_5 ) ;
V_5 -> V_58 = F_36 ( V_65 ) ;
V_5 -> V_78 = F_37 ( V_65 ) ;
F_38 ( & V_65 -> V_2 , L_2 , V_5 -> V_58 ) ;
F_38 ( & V_65 -> V_2 , L_3 , V_5 -> V_78 ) ;
if ( V_5 -> V_58 == V_59 )
F_3 ( F_4 ( V_5 -> V_8 + V_79 ) | V_80 ,
V_5 -> V_8 + V_79 ) ;
if ( V_5 -> V_58 == V_59 ) {
if ( F_4 ( V_5 -> V_8 + V_40 ) == 0x2000 ) {
time = F_4 ( V_5 -> V_8 + V_39 ) ;
if ( ( time &
( V_32 | V_33 | V_34 ) )
== 0x02120000 ) {
time = time | ( 0x7 << V_25 ) ;
F_3 ( 0x2000 , V_5 -> V_8 + V_42 ) ;
F_3 ( time , V_5 -> V_8 + V_43 ) ;
}
}
}
V_5 -> V_61 = F_39 ( L_4 , & V_65 -> V_2 , V_69 ,
V_81 ) ;
if ( F_40 ( V_5 -> V_61 ) ) {
V_41 = F_41 ( V_5 -> V_61 ) ;
goto V_82;
}
if ( F_42 ( V_65 -> V_50 [ 0 ] , F_18 ,
0 , L_5 , V_5 ) ) {
V_41 = - V_83 ;
goto V_84;
}
return 0 ;
V_84:
F_27 ( V_5 -> V_61 ) ;
V_82:
F_28 ( V_5 -> V_8 ) ;
F_25 ( V_65 , NULL ) ;
V_77:
F_29 ( V_5 ) ;
V_74:
F_30 ( V_65 ) ;
V_71:
return V_41 ;
}
