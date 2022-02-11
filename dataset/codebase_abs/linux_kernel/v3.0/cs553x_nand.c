static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
while ( F_2 ( V_4 > 0x800 ) ) {
F_3 ( V_3 , V_6 -> V_8 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_3 ( V_3 , V_6 -> V_8 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , const T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
while ( F_2 ( V_4 > 0x800 ) ) {
F_5 ( V_6 -> V_8 , V_3 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_5 ( V_6 -> V_8 , V_3 , V_4 ) ;
}
static unsigned char F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_7 ( V_6 -> V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_10 = 100000 ;
while ( V_10 && F_7 ( V_6 -> V_8 + V_11 ) & V_12 ) {
F_9 ( 1 ) ;
V_10 -- ;
}
F_10 ( V_9 , V_6 -> V_13 + 0x801 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_14 ,
unsigned int V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void T_2 * V_16 = V_6 -> V_8 ;
if ( V_15 & V_17 ) {
unsigned char V_18 = ( V_15 & ~ V_17 ) ^ 0x01 ;
F_10 ( V_18 , V_16 + V_19 ) ;
}
if ( V_14 != V_20 )
F_8 ( V_2 , V_14 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void T_2 * V_16 = V_6 -> V_8 ;
unsigned char V_21 = F_7 ( V_16 + V_11 ) ;
return ( V_21 & V_22 ) && ! ( V_21 & V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void T_2 * V_16 = V_6 -> V_8 ;
F_10 ( 0x07 , V_16 + V_24 ) ;
}
static int F_14 ( struct V_1 * V_2 , const T_1 * V_25 , T_1 * V_26 )
{
T_3 V_27 ;
struct V_5 * V_6 = V_2 -> V_7 ;
void T_2 * V_16 = V_6 -> V_8 ;
V_27 = F_15 ( V_16 + V_11 ) ;
V_26 [ 1 ] = V_27 >> 8 ;
V_26 [ 0 ] = V_27 >> 16 ;
V_26 [ 2 ] = V_27 >> 24 ;
return 0 ;
}
static int T_4 F_16 ( int V_28 , int V_29 , unsigned long V_30 )
{
int V_31 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_32 ;
F_17 ( V_33 L_1 , V_28 , V_29 ? L_2 : L_3 , V_30 ) ;
if ( ! V_29 ) {
F_17 ( V_33 L_4 ) ;
return - V_34 ;
}
V_32 = F_18 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_35 ) ;
if ( ! V_32 ) {
F_17 ( V_36 L_5 ) ;
V_31 = - V_37 ;
goto V_38;
}
V_6 = (struct V_5 * ) ( & V_32 [ 1 ] ) ;
memset ( V_32 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_32 -> V_7 = V_6 ;
V_32 -> V_39 = V_40 ;
V_6 -> V_8 = V_6 -> V_13 = F_19 ( V_30 , 4096 ) ;
if ( ! V_6 -> V_8 ) {
F_17 ( V_36 L_6 , V_30 ) ;
V_31 = - V_41 ;
goto V_42;
}
V_6 -> V_43 = F_11 ;
V_6 -> V_44 = F_12 ;
V_6 -> V_45 = F_6 ;
V_6 -> V_46 = F_1 ;
V_6 -> V_47 = F_4 ;
V_6 -> V_48 = 0 ;
V_6 -> V_27 . V_23 = V_49 ;
V_6 -> V_27 . V_50 = 256 ;
V_6 -> V_27 . V_51 = 3 ;
V_6 -> V_27 . V_52 = F_13 ;
V_6 -> V_27 . V_53 = F_14 ;
V_6 -> V_27 . V_54 = V_55 ;
V_6 -> V_56 = V_57 | V_58 ;
if ( F_20 ( V_32 , 1 ) ) {
V_31 = - V_34 ;
goto V_59;
}
V_32 -> V_60 = F_21 ( V_35 , L_7 , V_28 ) ;
V_61 [ V_28 ] = V_32 ;
goto V_38;
V_59:
F_22 ( V_6 -> V_8 ) ;
V_42:
F_23 ( V_32 ) ;
V_38:
return V_31 ;
}
static int F_24 ( void )
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
static int T_4 F_25 ( void )
{
int V_31 = - V_34 ;
int V_10 ;
T_5 V_69 ;
int V_70 = 0 ;
struct V_71 * V_72 = NULL ;
if ( ! F_24 () )
return - V_34 ;
F_26 ( V_73 , V_69 ) ;
V_69 &= ~ 0xFFULL ;
if ( V_69 != V_74 && V_69 != V_75 )
return - V_34 ;
F_26 ( V_76 , V_69 ) ;
if ( V_69 & V_77 ) {
F_17 ( V_78 L_8 ) ;
return - V_34 ;
}
for ( V_10 = 0 ; V_10 < V_79 ; V_10 ++ ) {
F_26 ( V_80 + V_10 , V_69 ) ;
if ( ( V_69 & ( V_81 | V_82 ) ) == ( V_81 | V_82 ) )
V_31 = F_16 ( V_10 , ! ! ( V_69 & V_83 ) , V_69 & 0xFFFFFFFF ) ;
}
for ( V_10 = 0 ; V_10 < V_79 ; V_10 ++ ) {
if ( V_61 [ V_10 ] ) {
V_70 = F_27 ( V_61 [ V_10 ] , V_84 , & V_72 , 0 ) ;
if ( V_70 > 0 )
F_17 ( V_33 L_9 ) ;
F_28 ( V_61 [ V_10 ] , V_72 ,
V_70 ) ;
V_31 = 0 ;
}
}
return V_31 ;
}
static void T_6 F_29 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_79 ; V_10 ++ ) {
struct V_1 * V_2 = V_61 [ V_10 ] ;
struct V_5 * V_6 ;
void T_2 * V_16 ;
if ( ! V_2 )
continue;
V_6 = V_61 [ V_10 ] -> V_7 ;
V_16 = V_6 -> V_8 ;
F_30 ( V_61 [ V_10 ] ) ;
F_23 ( V_61 [ V_10 ] -> V_60 ) ;
V_61 [ V_10 ] = NULL ;
F_22 ( V_16 ) ;
F_23 ( V_2 ) ;
}
}
