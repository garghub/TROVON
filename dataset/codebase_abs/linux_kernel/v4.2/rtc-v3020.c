static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 -> V_7 != 1 )
return - V_8 ;
if ( V_4 -> V_9 [ 0 ] . V_10 != V_11 )
return - V_8 ;
V_2 -> V_12 = V_6 -> V_12 ;
V_2 -> V_13 = F_2 ( V_4 -> V_9 [ 0 ] . V_14 , 1 ) ;
if ( V_2 -> V_13 == NULL )
return - V_8 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned char V_15 )
{
F_6 ( V_15 << V_2 -> V_12 , V_2 -> V_13 ) ;
}
static unsigned char F_7 ( struct V_1 * V_2 )
{
return ! ! ( F_8 ( V_2 -> V_13 ) & ( 1 << V_2 -> V_12 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_16 ;
V_17 [ V_18 ] . V_19 = V_6 -> V_20 ;
V_17 [ V_21 ] . V_19 = V_6 -> V_22 ;
V_17 [ V_23 ] . V_19 = V_6 -> V_24 ;
V_17 [ V_25 ] . V_19 = V_6 -> V_26 ;
V_16 = F_10 ( V_17 , F_11 ( V_17 ) ) ;
if ( ! V_16 )
V_2 -> V_19 = V_17 ;
return V_16 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_17 , F_11 ( V_17 ) ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned char V_15 )
{
F_15 ( V_2 -> V_19 [ V_25 ] . V_19 , V_15 ) ;
F_16 ( V_2 -> V_19 [ V_18 ] . V_19 , 0 ) ;
F_16 ( V_2 -> V_19 [ V_21 ] . V_19 , 0 ) ;
F_17 ( 1 ) ;
F_16 ( V_2 -> V_19 [ V_21 ] . V_19 , 1 ) ;
F_16 ( V_2 -> V_19 [ V_18 ] . V_19 , 1 ) ;
}
static unsigned char F_18 ( struct V_1 * V_2 )
{
int V_15 ;
F_19 ( V_2 -> V_19 [ V_25 ] . V_19 ) ;
F_16 ( V_2 -> V_19 [ V_18 ] . V_19 , 0 ) ;
F_16 ( V_2 -> V_19 [ V_23 ] . V_19 , 0 ) ;
F_17 ( 1 ) ;
V_15 = ! ! F_20 ( V_2 -> V_19 [ V_25 ] . V_19 ) ;
F_17 ( 1 ) ;
F_16 ( V_2 -> V_19 [ V_23 ] . V_19 , 1 ) ;
F_16 ( V_2 -> V_19 [ V_18 ] . V_19 , 1 ) ;
return V_15 ;
}
static void F_21 ( struct V_1 * V_2 , unsigned char V_27 ,
unsigned char V_28 )
{
int V_29 ;
unsigned char V_30 ;
V_30 = V_27 ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
V_2 -> V_31 -> V_32 ( V_2 , ( V_30 & 1 ) ) ;
V_30 >>= 1 ;
F_17 ( 1 ) ;
}
if ( ! F_22 ( V_27 ) ) {
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
V_2 -> V_31 -> V_32 ( V_2 , ( V_28 & 1 ) ) ;
V_28 >>= 1 ;
F_17 ( 1 ) ;
}
}
}
static unsigned char F_23 ( struct V_1 * V_2 , unsigned char V_27 )
{
unsigned int V_28 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
V_2 -> V_31 -> V_32 ( V_2 , ( V_27 & 1 ) ) ;
V_27 >>= 1 ;
F_17 ( 1 ) ;
}
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
V_28 >>= 1 ;
if ( V_2 -> V_31 -> V_33 ( V_2 ) )
V_28 |= 0x80 ;
F_17 ( 1 ) ;
}
return V_28 ;
}
static int F_24 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
int V_30 ;
F_21 ( V_2 , V_38 , 0 ) ;
V_30 = F_23 ( V_2 , V_39 ) ;
V_37 -> V_40 = F_26 ( V_30 ) ;
V_30 = F_23 ( V_2 , V_41 ) ;
V_37 -> V_42 = F_26 ( V_30 ) ;
V_30 = F_23 ( V_2 , V_43 ) ;
V_37 -> V_44 = F_26 ( V_30 ) ;
V_30 = F_23 ( V_2 , V_45 ) ;
V_37 -> V_46 = F_26 ( V_30 ) ;
V_30 = F_23 ( V_2 , V_47 ) ;
V_37 -> V_48 = F_26 ( V_30 ) - 1 ;
V_30 = F_23 ( V_2 , V_49 ) ;
V_37 -> V_50 = F_26 ( V_30 ) ;
V_30 = F_23 ( V_2 , V_51 ) ;
V_37 -> V_52 = F_26 ( V_30 ) + 100 ;
F_27 ( V_35 , L_1 , V_53 ) ;
F_27 ( V_35 , L_2 , V_37 -> V_44 ) ;
F_27 ( V_35 , L_3 , V_37 -> V_42 ) ;
F_27 ( V_35 , L_4 , V_37 -> V_40 ) ;
F_27 ( V_35 , L_5 , V_37 -> V_52 ) ;
F_27 ( V_35 , L_6 , V_37 -> V_48 ) ;
F_27 ( V_35 , L_7 , V_37 -> V_46 ) ;
F_27 ( V_35 , L_8 , V_37 -> V_50 ) ;
return 0 ;
}
static int F_28 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
F_27 ( V_35 , L_9 , V_53 ) ;
F_27 ( V_35 , L_4 , V_37 -> V_40 ) ;
F_27 ( V_35 , L_3 , V_37 -> V_42 ) ;
F_27 ( V_35 , L_2 , V_37 -> V_44 ) ;
F_27 ( V_35 , L_7 , V_37 -> V_46 ) ;
F_27 ( V_35 , L_8 , V_37 -> V_50 ) ;
F_27 ( V_35 , L_5 , V_37 -> V_52 ) ;
F_21 ( V_2 , V_39 , F_29 ( V_37 -> V_40 ) ) ;
F_21 ( V_2 , V_41 , F_29 ( V_37 -> V_42 ) ) ;
F_21 ( V_2 , V_43 , F_29 ( V_37 -> V_44 ) ) ;
F_21 ( V_2 , V_45 , F_29 ( V_37 -> V_46 ) ) ;
F_21 ( V_2 , V_47 , F_29 ( V_37 -> V_48 + 1 ) ) ;
F_21 ( V_2 , V_49 , F_29 ( V_37 -> V_50 ) ) ;
F_21 ( V_2 , V_51 , F_29 ( V_37 -> V_52 % 100 ) ) ;
F_21 ( V_2 , V_54 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_31 ( & V_4 -> V_35 ) ;
struct V_1 * V_2 ;
int V_55 = - V_8 ;
int V_29 ;
int V_56 ;
V_2 = F_32 ( & V_4 -> V_35 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return - V_58 ;
if ( V_6 -> V_59 )
V_2 -> V_31 = & V_60 ;
else
V_2 -> V_31 = & V_61 ;
V_55 = V_2 -> V_31 -> V_62 ( V_2 , V_4 , V_6 ) ;
if ( V_55 )
return V_55 ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
V_56 = V_2 -> V_31 -> V_33 ( V_2 ) ;
F_21 ( V_2 , V_39 , 0x33 ) ;
if ( F_23 ( V_2 , V_39 ) != 0x33 ) {
V_55 = - V_63 ;
goto V_64;
}
F_21 ( V_2 , V_65 , 0x0 ) ;
if ( V_6 -> V_59 )
F_33 ( & V_4 -> V_35 , L_10
L_11 ,
V_2 -> V_19 [ V_18 ] . V_19 , V_2 -> V_19 [ V_21 ] . V_19 ,
V_2 -> V_19 [ V_23 ] . V_19 , V_2 -> V_19 [ V_25 ] . V_19 ) ;
else
F_33 ( & V_4 -> V_35 , L_12
L_13
L_14 ,
( unsigned long long ) V_4 -> V_9 [ 0 ] . V_14 ,
V_2 -> V_12 ) ;
F_34 ( V_4 , V_2 ) ;
V_2 -> V_66 = F_35 ( & V_4 -> V_35 , L_15 ,
& V_67 , V_68 ) ;
if ( F_36 ( V_2 -> V_66 ) ) {
V_55 = F_37 ( V_2 -> V_66 ) ;
goto V_64;
}
return 0 ;
V_64:
V_2 -> V_31 -> V_69 ( V_2 ) ;
return V_55 ;
}
static int F_38 ( struct V_3 * V_35 )
{
struct V_1 * V_2 = F_39 ( V_35 ) ;
V_2 -> V_31 -> V_69 ( V_2 ) ;
return 0 ;
}
