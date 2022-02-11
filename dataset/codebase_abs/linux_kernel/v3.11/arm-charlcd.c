static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
V_5 = F_2 ( V_4 -> V_6 + V_7 ) & 0x01 ;
F_3 ( V_8 , V_4 -> V_6 + V_9 ) ;
if ( V_5 )
F_4 ( & V_4 -> F_4 ) ;
else
F_5 ( V_4 -> V_10 , L_1 , V_5 ) ;
return V_11 ;
}
static void F_6 ( struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_7 ( & V_4 -> F_4 ,
V_13 ) ;
F_3 ( 0x00 , V_4 -> V_6 + V_14 ) ;
if ( V_12 < 0 ) {
F_8 ( V_4 -> V_10 ,
L_2
L_3 , V_12 ) ;
return;
}
if ( V_12 == 0 ) {
F_8 ( V_4 -> V_10 , L_4
L_5 ) ;
return;
}
}
static T_2 F_9 ( struct V_3 * V_4 )
{
T_2 V_2 ;
T_3 V_15 ;
int V_16 ;
if ( V_4 -> V_1 >= 0 )
F_6 ( V_4 ) ;
else {
V_16 = 0 ;
V_15 = 0 ;
while ( ! ( V_15 & V_17 ) && V_16 < 10 ) {
F_10 ( 100 ) ;
V_15 = F_2 ( V_4 -> V_6 + V_9 ) ;
V_16 ++ ;
}
F_3 ( V_8 , V_4 -> V_6 + V_9 ) ;
}
F_11 ( 1 ) ;
V_2 = F_2 ( V_4 -> V_6 + V_18 ) & 0xf0 ;
V_16 = 0 ;
V_15 = 0 ;
while ( ! ( V_15 & V_17 ) && V_16 < 10 ) {
F_10 ( 100 ) ;
V_15 = F_2 ( V_4 -> V_6 + V_9 ) ;
V_16 ++ ;
}
F_3 ( V_8 , V_4 -> V_6 + V_9 ) ;
F_11 ( 1 ) ;
V_2 |= ( F_2 ( V_4 -> V_6 + V_18 ) >> 4 ) & 0x0f ;
return V_2 ;
}
static bool F_12 ( struct V_3 * V_4 )
{
if ( V_4 -> V_1 >= 0 ) {
F_3 ( V_8 , V_4 -> V_6 + V_9 ) ;
F_13 ( & V_4 -> F_4 ) ;
F_3 ( 0x01 , V_4 -> V_6 + V_14 ) ;
}
F_2 ( V_4 -> V_6 + V_19 ) ;
return F_9 ( V_4 ) & V_20 ? true : false ;
}
static void F_14 ( struct V_3 * V_4 )
{
int V_21 = 50 ;
F_10 ( 100 ) ;
while ( F_12 ( V_4 ) && V_21 )
V_21 -- ;
if ( ! V_21 )
F_8 ( V_4 -> V_10 , L_6 ) ;
}
static void F_15 ( struct V_3 * V_4 , T_2 V_22 )
{
T_3 V_23 = ( V_22 << 4 ) & 0xf0 ;
T_3 V_24 = ( V_22 & 0xf0 ) ;
F_3 ( V_24 , V_4 -> V_6 + V_19 ) ;
F_10 ( 10 ) ;
F_3 ( V_23 , V_4 -> V_6 + V_19 ) ;
F_14 ( V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 , T_2 V_25 )
{
T_3 V_26 = ( V_25 << 4 ) & 0xf0 ;
T_3 V_27 = ( V_25 & 0xf0 ) ;
F_3 ( V_27 , V_4 -> V_6 + V_28 ) ;
F_10 ( 10 ) ;
F_3 ( V_26 , V_4 -> V_6 + V_28 ) ;
F_14 ( V_4 ) ;
}
static void F_17 ( struct V_3 * V_4 , int line , const char * V_29 )
{
T_2 V_30 ;
int V_16 ;
if ( line == 0 )
V_30 = 0 ;
else if ( line == 1 )
V_30 = 0x28 ;
else
return;
F_15 ( V_4 , V_31 | V_30 ) ;
for ( V_16 = 0 ; V_16 < strlen ( V_29 ) && V_16 < 0x28 ; V_16 ++ )
F_16 ( V_4 , V_29 [ V_16 ] ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
F_3 ( V_32 | V_33 , V_4 -> V_6 + V_19 ) ;
F_11 ( 5 ) ;
F_3 ( V_32 | V_33 , V_4 -> V_6 + V_19 ) ;
F_10 ( 100 ) ;
F_3 ( V_32 | V_33 , V_4 -> V_6 + V_19 ) ;
F_10 ( 100 ) ;
F_3 ( V_32 , V_4 -> V_6 + V_19 ) ;
F_10 ( 100 ) ;
F_15 ( V_4 , V_32 | V_34 ) ;
F_15 ( V_4 , V_35 | V_36 ) ;
F_15 ( V_4 , V_37 | V_38 ) ;
F_15 ( V_4 , V_39 ) ;
F_15 ( V_4 , V_40 ) ;
F_17 ( V_4 , 0 , L_7 ) ;
F_17 ( V_4 , 1 , V_41 ) ;
}
static void F_19 ( struct V_42 * V_43 )
{
struct V_3 * V_4 =
F_20 ( V_43 , struct V_3 , V_44 . V_43 ) ;
F_18 ( V_4 ) ;
}
static int T_4 F_21 ( struct V_45 * V_46 )
{
int V_12 ;
struct V_3 * V_4 ;
struct V_47 * V_48 ;
V_4 = F_22 ( sizeof( struct V_3 ) , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_10 = & V_46 -> V_10 ;
V_48 = F_23 ( V_46 , V_51 , 0 ) ;
if ( ! V_48 ) {
V_12 = - V_52 ;
goto V_53;
}
V_4 -> V_54 = V_48 -> V_55 ;
V_4 -> V_56 = F_24 ( V_48 ) ;
if ( F_25 ( V_4 -> V_54 , V_4 -> V_56 ,
V_57 ) == NULL ) {
V_12 = - V_58 ;
goto V_59;
}
V_4 -> V_6 = F_26 ( V_4 -> V_54 , V_4 -> V_56 ) ;
if ( ! V_4 -> V_6 ) {
V_12 = - V_50 ;
goto V_59;
}
V_4 -> V_1 = F_27 ( V_46 , 0 ) ;
if ( V_4 -> V_1 >= 0 ) {
if ( F_28 ( V_4 -> V_1 , F_1 , V_60 ,
V_57 , V_4 ) ) {
V_12 = - V_61 ;
goto V_62;
}
}
F_29 ( V_46 , V_4 ) ;
F_30 ( & V_4 -> V_44 , F_19 ) ;
F_31 ( & V_4 -> V_44 , 0 ) ;
F_5 ( & V_46 -> V_10 , L_8 ,
V_4 -> V_54 ) ;
return 0 ;
V_62:
F_32 ( V_4 -> V_6 ) ;
V_59:
F_33 ( V_4 -> V_54 , V_63 ) ;
V_53:
F_34 ( V_4 ) ;
return V_12 ;
}
static int T_5 F_35 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = F_36 ( V_46 ) ;
if ( V_4 ) {
F_37 ( V_4 -> V_1 , V_4 ) ;
F_32 ( V_4 -> V_6 ) ;
F_33 ( V_4 -> V_54 , V_4 -> V_56 ) ;
F_34 ( V_4 ) ;
}
return 0 ;
}
static int F_38 ( struct V_64 * V_10 )
{
struct V_45 * V_46 = F_39 ( V_10 ) ;
struct V_3 * V_4 = F_36 ( V_46 ) ;
F_15 ( V_4 , V_35 ) ;
return 0 ;
}
static int F_40 ( struct V_64 * V_10 )
{
struct V_45 * V_46 = F_39 ( V_10 ) ;
struct V_3 * V_4 = F_36 ( V_46 ) ;
F_15 ( V_4 , V_35 | V_36 ) ;
return 0 ;
}
