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
int V_16 , V_17 ;
V_18 [ V_19 ] . V_20 = V_6 -> V_21 ;
V_18 [ V_22 ] . V_20 = V_6 -> V_23 ;
V_18 [ V_24 ] . V_20 = V_6 -> V_25 ;
V_18 [ V_26 ] . V_20 = V_6 -> V_27 ;
for ( V_16 = 0 ; V_16 < F_10 ( V_18 ) ; V_16 ++ ) {
V_17 = F_11 ( V_18 [ V_16 ] . V_20 , V_18 [ V_16 ] . V_28 ) ;
if ( V_17 )
goto V_29;
F_12 ( V_18 [ V_16 ] . V_20 , 1 ) ;
}
V_2 -> V_20 = V_18 ;
return 0 ;
V_29:
while ( -- V_16 >= 0 )
F_13 ( V_18 [ V_16 ] . V_20 ) ;
return V_17 ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_10 ( V_18 ) ; V_16 ++ )
F_13 ( V_18 [ V_16 ] . V_20 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned char V_15 )
{
F_12 ( V_2 -> V_20 [ V_26 ] . V_20 , V_15 ) ;
F_16 ( V_2 -> V_20 [ V_19 ] . V_20 , 0 ) ;
F_16 ( V_2 -> V_20 [ V_22 ] . V_20 , 0 ) ;
F_17 ( 1 ) ;
F_16 ( V_2 -> V_20 [ V_22 ] . V_20 , 1 ) ;
F_16 ( V_2 -> V_20 [ V_19 ] . V_20 , 1 ) ;
}
static unsigned char F_18 ( struct V_1 * V_2 )
{
int V_15 ;
F_19 ( V_2 -> V_20 [ V_26 ] . V_20 ) ;
F_16 ( V_2 -> V_20 [ V_19 ] . V_20 , 0 ) ;
F_16 ( V_2 -> V_20 [ V_24 ] . V_20 , 0 ) ;
F_17 ( 1 ) ;
V_15 = ! ! F_20 ( V_2 -> V_20 [ V_26 ] . V_20 ) ;
F_17 ( 1 ) ;
F_16 ( V_2 -> V_20 [ V_24 ] . V_20 , 1 ) ;
F_16 ( V_2 -> V_20 [ V_19 ] . V_20 , 1 ) ;
return V_15 ;
}
static void F_21 ( struct V_1 * V_2 , unsigned char V_30 ,
unsigned char V_31 )
{
int V_16 ;
unsigned char V_32 ;
V_32 = V_30 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_2 -> V_33 -> V_34 ( V_2 , ( V_32 & 1 ) ) ;
V_32 >>= 1 ;
F_17 ( 1 ) ;
}
if ( ! F_22 ( V_30 ) ) {
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
V_2 -> V_33 -> V_34 ( V_2 , ( V_31 & 1 ) ) ;
V_31 >>= 1 ;
F_17 ( 1 ) ;
}
}
}
static unsigned char F_23 ( struct V_1 * V_2 , unsigned char V_30 )
{
unsigned int V_31 = 0 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_2 -> V_33 -> V_34 ( V_2 , ( V_30 & 1 ) ) ;
V_30 >>= 1 ;
F_17 ( 1 ) ;
}
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
V_31 >>= 1 ;
if ( V_2 -> V_33 -> V_35 ( V_2 ) )
V_31 |= 0x80 ;
F_17 ( 1 ) ;
}
return V_31 ;
}
static int F_24 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_25 ( V_37 ) ;
int V_32 ;
F_21 ( V_2 , V_40 , 0 ) ;
V_32 = F_23 ( V_2 , V_41 ) ;
V_39 -> V_42 = F_26 ( V_32 ) ;
V_32 = F_23 ( V_2 , V_43 ) ;
V_39 -> V_44 = F_26 ( V_32 ) ;
V_32 = F_23 ( V_2 , V_45 ) ;
V_39 -> V_46 = F_26 ( V_32 ) ;
V_32 = F_23 ( V_2 , V_47 ) ;
V_39 -> V_48 = F_26 ( V_32 ) ;
V_32 = F_23 ( V_2 , V_49 ) ;
V_39 -> V_50 = F_26 ( V_32 ) - 1 ;
V_32 = F_23 ( V_2 , V_51 ) ;
V_39 -> V_52 = F_26 ( V_32 ) ;
V_32 = F_23 ( V_2 , V_53 ) ;
V_39 -> V_54 = F_26 ( V_32 ) + 100 ;
F_27 ( V_37 , L_1 , V_55 ) ;
F_27 ( V_37 , L_2 , V_39 -> V_46 ) ;
F_27 ( V_37 , L_3 , V_39 -> V_44 ) ;
F_27 ( V_37 , L_4 , V_39 -> V_42 ) ;
F_27 ( V_37 , L_5 , V_39 -> V_54 ) ;
F_27 ( V_37 , L_6 , V_39 -> V_50 ) ;
F_27 ( V_37 , L_7 , V_39 -> V_48 ) ;
F_27 ( V_37 , L_8 , V_39 -> V_52 ) ;
return 0 ;
}
static int F_28 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_25 ( V_37 ) ;
F_27 ( V_37 , L_9 , V_55 ) ;
F_27 ( V_37 , L_4 , V_39 -> V_42 ) ;
F_27 ( V_37 , L_3 , V_39 -> V_44 ) ;
F_27 ( V_37 , L_2 , V_39 -> V_46 ) ;
F_27 ( V_37 , L_7 , V_39 -> V_48 ) ;
F_27 ( V_37 , L_8 , V_39 -> V_52 ) ;
F_27 ( V_37 , L_5 , V_39 -> V_54 ) ;
F_21 ( V_2 , V_41 , F_29 ( V_39 -> V_42 ) ) ;
F_21 ( V_2 , V_43 , F_29 ( V_39 -> V_44 ) ) ;
F_21 ( V_2 , V_45 , F_29 ( V_39 -> V_46 ) ) ;
F_21 ( V_2 , V_47 , F_29 ( V_39 -> V_48 ) ) ;
F_21 ( V_2 , V_49 , F_29 ( V_39 -> V_50 + 1 ) ) ;
F_21 ( V_2 , V_51 , F_29 ( V_39 -> V_52 ) ) ;
F_21 ( V_2 , V_53 , F_29 ( V_39 -> V_54 % 100 ) ) ;
F_21 ( V_2 , V_56 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_37 . V_57 ;
struct V_1 * V_2 ;
int V_58 = - V_8 ;
int V_16 ;
int V_59 ;
V_2 = F_31 ( & V_4 -> V_37 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
return - V_61 ;
if ( V_6 -> V_62 )
V_2 -> V_33 = & V_63 ;
else
V_2 -> V_33 = & V_64 ;
V_58 = V_2 -> V_33 -> V_65 ( V_2 , V_4 , V_6 ) ;
if ( V_58 )
return V_58 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ )
V_59 = V_2 -> V_33 -> V_35 ( V_2 ) ;
F_21 ( V_2 , V_41 , 0x33 ) ;
if ( F_23 ( V_2 , V_41 ) != 0x33 ) {
V_58 = - V_66 ;
goto V_67;
}
F_21 ( V_2 , V_68 , 0x0 ) ;
if ( V_6 -> V_62 )
F_32 ( & V_4 -> V_37 , L_10
L_11 ,
V_2 -> V_20 [ V_19 ] . V_20 , V_2 -> V_20 [ V_22 ] . V_20 ,
V_2 -> V_20 [ V_24 ] . V_20 , V_2 -> V_20 [ V_26 ] . V_20 ) ;
else
F_32 ( & V_4 -> V_37 , L_12
L_13
L_14 ,
( unsigned long long ) V_4 -> V_9 [ 0 ] . V_14 ,
V_2 -> V_12 ) ;
F_33 ( V_4 , V_2 ) ;
V_2 -> V_69 = F_34 ( & V_4 -> V_37 , L_15 ,
& V_70 , V_71 ) ;
if ( F_35 ( V_2 -> V_69 ) ) {
V_58 = F_36 ( V_2 -> V_69 ) ;
goto V_67;
}
return 0 ;
V_67:
V_2 -> V_33 -> V_72 ( V_2 ) ;
return V_58 ;
}
static int F_37 ( struct V_3 * V_37 )
{
struct V_1 * V_2 = F_38 ( V_37 ) ;
V_2 -> V_33 -> V_72 ( V_2 ) ;
return 0 ;
}
