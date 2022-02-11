static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 , V_6 = 0 ;
struct V_7 * V_8 ;
const char * V_9 ;
T_1 V_10 = 1 ;
T_2 V_11 ;
V_8 = V_4 -> V_7 ;
if ( ! V_8 )
return - V_12 ;
V_9 = F_3 ( & V_4 -> V_2 ) ;
V_10 <<= F_4 ( V_8 -> V_13 ) ;
V_11 = V_14 -> V_15 ( V_8 -> V_16 ) ;
if ( ( V_11 & V_8 -> V_13 ) == V_10 )
return V_5 ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= ~ V_8 -> V_18 ;
V_11 |= V_19 << F_4 ( V_8 -> V_18 ) ;
V_14 -> V_20 ( V_11 , V_8 -> V_17 ) ;
V_10 <<= F_4 ( V_8 -> V_13 ) ;
while ( 1 ) {
V_11 = V_14 -> V_15 ( V_8 -> V_16 ) ;
if ( ( V_11 & V_8 -> V_13 ) == V_10 )
break;
if ( V_6 > V_21 )
break;
V_6 ++ ;
F_5 ( 1 ) ;
}
if ( V_6 == V_21 ) {
F_6 ( L_1 ,
V_9 , ( V_10 ) ? L_2 : L_3 ) ;
V_5 = - V_22 ;
} else
F_7 ( L_4 ,
V_9 , ( V_10 ) ? L_2 : L_3 , V_6 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_10 = 1 ;
T_2 V_11 ;
V_8 = V_4 -> V_7 ;
V_10 <<= F_4 ( V_8 -> V_13 ) ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= ~ V_8 -> V_18 ;
V_11 |= V_23 << F_4 ( V_8 -> V_18 ) ;
V_14 -> V_20 ( V_11 , V_8 -> V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_2 V_11 ;
V_8 = V_4 -> V_7 ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= V_8 -> V_18 ;
V_11 >>= F_4 ( V_8 -> V_18 ) ;
return V_11 == V_23 ? 0 : 1 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static void T_3 F_11 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_1 -> V_7 ;
struct V_4 * V_4 ;
V_8 -> V_26 = F_12 ( V_25 , 0 ) ;
V_8 -> V_27 = F_12 ( V_25 , 1 ) ;
if ( F_13 ( V_8 -> V_26 ) || F_13 ( V_8 -> V_27 ) ) {
F_7 ( L_5 ,
V_25 -> V_28 ) ;
if ( ! F_14 ( V_25 , V_2 , F_11 ) )
return;
goto V_29;
}
V_4 = F_15 ( NULL , & V_1 -> V_2 ) ;
if ( ! F_13 ( V_4 ) ) {
F_16 ( V_25 , V_30 , V_4 ) ;
F_17 ( V_1 -> V_2 . V_31 -> V_32 ) ;
F_17 ( V_1 -> V_2 . V_31 ) ;
return;
}
V_29:
F_17 ( V_1 -> V_7 ) ;
F_17 ( V_1 -> V_2 . V_31 -> V_32 ) ;
F_17 ( V_1 -> V_2 . V_31 ) ;
F_17 ( V_1 ) ;
}
static void T_3 F_18 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = NULL ;
struct V_3 * V_1 = NULL ;
struct V_33 * V_31 = NULL ;
const char * * V_32 = NULL ;
V_8 = F_19 ( sizeof( * V_8 ) , V_34 ) ;
V_1 = F_19 ( sizeof( * V_1 ) , V_34 ) ;
V_31 = F_19 ( sizeof( * V_31 ) , V_34 ) ;
if ( ! V_8 || ! V_1 || ! V_31 )
goto V_29;
V_1 -> V_7 = V_8 ;
V_1 -> V_2 . V_31 = V_31 ;
V_1 -> V_35 = V_36 ;
V_31 -> V_28 = V_25 -> V_28 ;
V_31 -> V_37 = & V_38 ;
V_31 -> V_39 = F_20 ( V_25 ) ;
if ( V_31 -> V_39 < 1 ) {
F_21 ( L_6 , V_25 -> V_28 ) ;
goto V_29;
}
V_32 = F_19 ( sizeof( char * ) * V_31 -> V_39 , V_34 ) ;
if ( ! V_32 )
goto V_29;
F_22 ( V_25 , V_32 , V_31 -> V_39 ) ;
V_31 -> V_32 = V_32 ;
V_8 -> V_17 = F_23 ( V_25 , 0 ) ;
V_8 -> V_16 = F_23 ( V_25 , 1 ) ;
if ( F_13 ( V_8 -> V_17 ) || F_13 ( V_8 -> V_16 ) )
goto V_29;
V_8 -> V_13 = 0x1 ;
V_8 -> V_18 = 0x3 ;
F_11 ( & V_1 -> V_2 , V_25 ) ;
return;
V_29:
F_17 ( V_32 ) ;
F_17 ( V_8 ) ;
F_17 ( V_1 ) ;
F_17 ( V_31 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_7 ;
T_2 V_11 ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= V_8 -> V_18 ;
V_11 >>= F_4 ( V_8 -> V_18 ) ;
return V_11 == V_40 ? 1 : 0 ;
}
static unsigned long F_25 ( struct V_1 * V_2 ,
unsigned long V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_24 ( V_2 ) )
return V_4 -> V_42 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_7 ;
T_2 V_11 ;
int V_6 = 0 ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= ~ V_8 -> V_18 ;
V_11 |= V_40 << F_4 ( V_8 -> V_18 ) ;
V_14 -> V_20 ( V_11 , V_8 -> V_17 ) ;
while ( 1 ) {
V_11 = V_14 -> V_15 ( V_8 -> V_16 ) ;
if ( V_11 & V_8 -> V_13 )
break;
if ( V_6 > V_21 )
break;
V_6 ++ ;
F_5 ( 1 ) ;
}
if ( V_6 == V_21 ) {
F_6 ( L_7 ,
F_3 ( & V_4 -> V_2 ) ) ;
return - V_22 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_7 ;
T_2 V_11 ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= ~ V_8 -> V_18 ;
V_11 |= V_43 << F_4 ( V_8 -> V_18 ) ;
V_14 -> V_20 ( V_11 , V_8 -> V_17 ) ;
}
static void F_28 ( struct V_3 * V_4 , T_2 V_44 )
{
struct V_7 * V_8 = V_4 -> V_7 ;
T_2 V_11 ;
V_11 = V_14 -> V_15 ( V_8 -> V_45 ) ;
V_11 &= ~ V_8 -> V_46 ;
V_11 |= V_44 << F_4 ( V_8 -> V_46 ) ;
V_14 -> V_20 ( V_11 , V_8 -> V_17 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_28 ( V_4 , V_47 ) ;
}
static void F_30 ( struct V_3 * V_4 )
{
F_28 ( V_4 , V_48 ) ;
}
static void T_3 F_31 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = NULL ;
struct V_3 * V_1 = NULL ;
struct V_33 * V_31 = NULL ;
struct V_4 * V_4 ;
const char * V_49 ;
T_2 V_44 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_34 ) ;
V_1 = F_19 ( sizeof( * V_1 ) , V_34 ) ;
V_31 = F_19 ( sizeof( * V_31 ) , V_34 ) ;
if ( ! V_8 || ! V_1 || ! V_31 )
goto V_29;
V_1 -> V_7 = V_8 ;
V_1 -> V_2 . V_31 = V_31 ;
V_31 -> V_37 = & V_50 ;
V_31 -> V_28 = V_25 -> V_28 ;
V_1 -> V_37 = & V_51 ;
V_31 -> V_39 = F_20 ( V_25 ) ;
if ( V_31 -> V_39 != 1 ) {
F_21 ( L_8 , V_25 -> V_28 ) ;
goto V_29;
}
V_49 = F_32 ( V_25 , 0 ) ;
V_31 -> V_32 = & V_49 ;
if ( F_33 ( V_25 , L_9 , & V_44 ) ) {
F_21 ( L_10 , V_25 -> V_28 ) ;
goto V_29;
}
V_1 -> V_42 = V_44 ;
if ( F_33 ( V_25 , L_11 , & V_44 ) ) {
F_21 ( L_12 , V_25 -> V_28 ) ;
goto V_29;
}
V_1 -> V_52 = V_44 ;
V_8 -> V_18 = 0x3 << V_44 ;
V_8 -> V_46 = 0x3 << V_44 ;
if ( F_33 ( V_25 , L_13 , & V_44 ) ) {
F_21 ( L_14 , V_25 -> V_28 ) ;
goto V_29;
}
V_8 -> V_13 = 1 << V_44 ;
V_8 -> V_17 = F_23 ( V_25 , 0 ) ;
V_8 -> V_45 = F_23 ( V_25 , 1 ) ;
V_8 -> V_16 = F_23 ( V_25 , 2 ) ;
if ( F_13 ( V_8 -> V_17 ) || F_13 ( V_8 -> V_45 ) ||
F_13 ( V_8 -> V_16 ) )
goto V_29;
V_4 = F_15 ( NULL , & V_1 -> V_2 ) ;
if ( ! F_13 ( V_4 ) ) {
F_16 ( V_25 , V_30 , V_4 ) ;
F_17 ( V_31 ) ;
return;
}
V_29:
F_17 ( V_8 ) ;
F_17 ( V_1 ) ;
F_17 ( V_31 ) ;
}
