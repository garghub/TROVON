static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( F_3 ( V_4 > 0x800 ) ) {
F_4 ( V_3 , V_6 -> V_7 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_4 ( V_3 , V_6 -> V_7 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , const T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( F_3 ( V_4 > 0x800 ) ) {
F_6 ( V_6 -> V_7 , V_3 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_6 ( V_6 -> V_7 , V_3 , V_4 ) ;
}
static unsigned char F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_8 ( V_6 -> V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 = 100000 ;
while ( V_9 && F_8 ( V_6 -> V_7 + V_10 ) & V_11 ) {
F_10 ( 1 ) ;
V_9 -- ;
}
F_11 ( V_8 , V_6 -> V_12 + 0x801 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_13 ,
unsigned int V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_2 * V_15 = V_6 -> V_7 ;
if ( V_14 & V_16 ) {
unsigned char V_17 = ( V_14 & ~ V_16 ) ^ 0x01 ;
F_11 ( V_17 , V_15 + V_18 ) ;
}
if ( V_13 != V_19 )
F_9 ( V_2 , V_13 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_2 * V_15 = V_6 -> V_7 ;
unsigned char V_20 = F_8 ( V_15 + V_10 ) ;
return ( V_20 & V_21 ) && ! ( V_20 & V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_2 * V_15 = V_6 -> V_7 ;
F_11 ( 0x07 , V_15 + V_23 ) ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 * V_24 , T_1 * V_25 )
{
T_3 V_26 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_2 * V_15 = V_6 -> V_7 ;
V_26 = F_16 ( V_15 + V_10 ) ;
V_25 [ 1 ] = V_26 >> 8 ;
V_25 [ 0 ] = V_26 >> 16 ;
V_25 [ 2 ] = V_26 >> 24 ;
return 0 ;
}
static int T_4 F_17 ( int V_27 , int V_28 , unsigned long V_29 )
{
int V_30 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_31 ;
F_18 ( V_32 L_1 , V_27 , V_28 ? L_2 : L_3 , V_29 ) ;
if ( ! V_28 ) {
F_18 ( V_32 L_4 ) ;
return - V_33 ;
}
V_6 = F_19 ( sizeof( struct V_5 ) , V_34 ) ;
if ( ! V_6 ) {
V_30 = - V_35 ;
goto V_36;
}
V_31 = F_20 ( V_6 ) ;
V_31 -> V_37 = V_38 ;
V_6 -> V_7 = V_6 -> V_12 = F_21 ( V_29 , 4096 ) ;
if ( ! V_6 -> V_7 ) {
F_18 ( V_39 L_5 , V_29 ) ;
V_30 = - V_40 ;
goto V_41;
}
V_6 -> V_42 = F_12 ;
V_6 -> V_43 = F_13 ;
V_6 -> V_44 = F_7 ;
V_6 -> V_45 = F_1 ;
V_6 -> V_46 = F_5 ;
V_6 -> V_47 = 0 ;
V_6 -> V_26 . V_22 = V_48 ;
V_6 -> V_26 . V_49 = 256 ;
V_6 -> V_26 . V_50 = 3 ;
V_6 -> V_26 . V_51 = F_14 ;
V_6 -> V_26 . V_52 = F_15 ;
V_6 -> V_26 . V_53 = V_54 ;
V_6 -> V_26 . V_55 = 1 ;
V_6 -> V_56 = V_57 ;
V_31 -> V_58 = F_22 ( V_34 , L_6 , V_27 ) ;
if ( ! V_31 -> V_58 ) {
V_30 = - V_35 ;
goto V_59;
}
V_30 = F_23 ( V_31 , 1 ) ;
if ( V_30 )
goto V_60;
V_61 [ V_27 ] = V_31 ;
goto V_36;
V_60:
F_24 ( V_31 -> V_58 ) ;
V_59:
F_25 ( V_6 -> V_7 ) ;
V_41:
F_24 ( V_6 ) ;
V_36:
return V_30 ;
}
static int F_26 ( void )
{
if ( V_62 . V_63 == V_64 &&
V_62 . V_65 == 5 &&
V_62 . V_66 == 10 )
return 1 ;
if ( ( V_62 . V_63 == V_67 ||
V_62 . V_63 == V_68 ) &&
V_62 . V_65 == 5 &&
V_62 . V_66 == 5 )
return 1 ;
return 0 ;
}
static int T_4 F_27 ( void )
{
int V_30 = - V_33 ;
int V_9 ;
T_5 V_69 ;
if ( ! F_26 () )
return - V_33 ;
F_28 ( V_70 , V_69 ) ;
V_69 &= ~ 0xFFULL ;
if ( V_69 != V_71 && V_69 != V_72 )
return - V_33 ;
F_28 ( V_73 , V_69 ) ;
if ( V_69 & V_74 ) {
F_18 ( V_75 L_7 ) ;
return - V_33 ;
}
for ( V_9 = 0 ; V_9 < V_76 ; V_9 ++ ) {
F_28 ( V_77 + V_9 , V_69 ) ;
if ( ( V_69 & ( V_78 | V_79 ) ) == ( V_78 | V_79 ) )
V_30 = F_17 ( V_9 , ! ! ( V_69 & V_80 ) , V_69 & 0xFFFFFFFF ) ;
}
for ( V_9 = 0 ; V_9 < V_76 ; V_9 ++ ) {
if ( V_61 [ V_9 ] ) {
F_29 ( V_61 [ V_9 ] , NULL , NULL ,
NULL , 0 ) ;
V_30 = 0 ;
}
}
return V_30 ;
}
static void T_6 F_30 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_76 ; V_9 ++ ) {
struct V_1 * V_2 = V_61 [ V_9 ] ;
struct V_5 * V_6 ;
void T_2 * V_15 ;
if ( ! V_2 )
continue;
V_6 = F_2 ( V_2 ) ;
V_15 = V_6 -> V_7 ;
F_31 ( V_2 ) ;
F_24 ( V_2 -> V_58 ) ;
V_61 [ V_9 ] = NULL ;
F_25 ( V_15 ) ;
F_24 ( V_6 ) ;
}
}
