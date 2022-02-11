static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
V_2 -> V_6 -> V_7 ( V_2 , 1 ) ;
F_2 ( 16 ) ;
for ( V_4 = 25 ; V_4 > 0 ; V_4 -- ) {
V_5 = ( V_3 >> 24 ) & V_8 ;
V_3 <<= 1 ;
V_2 -> V_6 -> V_9 ( V_2 , V_5 | V_10 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_9 ( V_2 , V_5 | V_10 | V_11 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_9 ( V_2 , V_5 | V_10 ) ;
F_2 ( 2 ) ;
}
if ( ! V_2 -> V_12 )
V_2 -> V_6 -> V_9 ( V_2 , 0 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
T_1 V_4 , V_13 ;
T_3 V_5 = 0 ;
V_2 -> V_6 -> V_7 ( V_2 , 0 ) ;
V_2 -> V_6 -> V_9 ( V_2 , 0 ) ;
F_2 ( 16 ) ;
for ( V_4 = 24 ; V_4 -- ; ) {
V_2 -> V_6 -> V_9 ( V_2 , V_11 ) ;
F_2 ( 2 ) ;
if ( ! V_4 )
V_2 -> V_14 = V_2 -> V_6 -> V_15 ( V_2 ) & V_16 ? 0 : 1 ;
V_2 -> V_6 -> V_9 ( V_2 , 0 ) ;
F_2 ( 2 ) ;
V_5 <<= 1 ;
V_13 = V_2 -> V_6 -> V_15 ( V_2 ) ;
if ( ! V_4 )
V_2 -> V_17 = ( V_13 & V_16 ) ? 0 : 1 ;
if ( V_13 & V_8 )
V_5 ++ ;
F_2 ( 2 ) ;
}
if ( V_2 -> V_12 )
V_2 -> V_6 -> V_9 ( V_2 , V_10 ) ;
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
V_18 = F_3 ( V_2 ) & V_19 ;
V_18 *= 125 ;
V_18 /= 10 ;
if ( V_2 -> V_20 )
V_18 += V_21 ;
else
V_18 -= V_21 ;
V_2 -> V_18 = V_18 * 16 ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
V_18 = F_6 ( V_2 -> V_18 , V_22 , V_23 ) ;
V_18 /= 16 ;
if ( V_2 -> V_20 )
V_18 -= V_21 ;
else
V_18 += V_21 ;
V_18 *= 10 ;
V_18 /= 125 ;
V_2 -> V_3 &= ~ V_19 ;
V_2 -> V_3 |= V_18 & V_19 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
}
static int F_7 ( struct V_24 * V_24 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
F_9 ( V_27 -> V_28 , L_1 , sizeof( V_27 -> V_28 ) ) ;
F_9 ( V_27 -> V_29 , V_2 -> V_29 , sizeof( V_27 -> V_29 ) ) ;
F_10 ( V_27 -> V_29 , V_2 -> V_20 ? L_2 : L_3 , sizeof( V_27 -> V_29 ) ) ;
F_9 ( V_27 -> V_30 , V_2 -> V_30 , sizeof( V_27 -> V_30 ) ) ;
V_27 -> V_31 = V_32 ;
V_27 -> V_33 = V_34 | V_35 ;
return 0 ;
}
static int F_11 ( struct V_24 * V_24 , void * V_25 ,
struct V_36 * V_27 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
if ( V_27 -> V_37 > 0 )
return - V_38 ;
F_3 ( V_2 ) ;
strcpy ( V_27 -> V_39 , L_4 ) ;
V_27 -> type = V_40 ;
V_27 -> V_41 = V_42 | V_43 ;
V_27 -> V_44 = V_22 ;
V_27 -> V_45 = V_23 ;
V_27 -> V_46 = V_47 | V_48 ;
V_27 -> V_49 = V_2 -> V_17 ? V_50 : V_51 ;
V_27 -> signal = V_2 -> V_14 ? 0xffff : 0 ;
return 0 ;
}
static int F_12 ( struct V_24 * V_24 , void * V_25 ,
struct V_36 * V_27 )
{
if ( V_27 -> V_37 > 0 )
return - V_38 ;
return 0 ;
}
static int F_13 ( struct V_24 * V_24 , void * V_25 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
if ( V_53 -> V_54 != 0 )
return - V_38 ;
V_53 -> type = V_40 ;
F_4 ( V_2 ) ;
V_53 -> V_55 = V_2 -> V_18 ;
return 0 ;
}
static int F_14 ( struct V_24 * V_24 , void * V_25 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
if ( V_53 -> V_54 != 0 || V_53 -> type != V_40 )
return - V_38 ;
if ( V_53 -> V_55 < V_22 || V_53 -> V_55 > V_23 )
return - V_38 ;
V_2 -> V_18 = V_53 -> V_55 ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_24 * V_24 , void * V_25 ,
struct V_56 * V_57 )
{
if ( V_57 -> V_37 > 1 )
return - V_38 ;
strcpy ( V_57 -> V_39 , L_5 ) ;
V_57 -> V_41 = V_58 ;
return 0 ;
}
static int F_16 ( struct V_24 * V_24 , void * V_25 ,
struct V_56 * V_57 )
{
if ( V_57 -> V_37 != 0 )
return - V_38 ;
return 0 ;
}
static int F_17 ( struct V_24 * V_24 , void * V_25 ,
struct V_59 * V_60 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_18 ( V_62 ) ; V_61 ++ ) {
if ( V_60 -> V_63 && V_60 -> V_63 == V_62 [ V_61 ] . V_63 ) {
memcpy ( V_60 , & ( V_62 [ V_61 ] ) ,
sizeof( * V_60 ) ) ;
return 0 ;
}
}
return - V_38 ;
}
static int F_19 ( struct V_24 * V_24 , void * V_25 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
switch ( V_65 -> V_63 ) {
case V_66 :
V_65 -> V_67 = V_2 -> V_12 ;
return 0 ;
}
return - V_38 ;
}
static int F_20 ( struct V_24 * V_24 , void * V_25 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
switch ( V_65 -> V_63 ) {
case V_66 :
if ( V_2 -> V_12 != V_65 -> V_67 ) {
V_2 -> V_12 = V_65 -> V_67 ;
F_5 ( V_2 ) ;
}
return 0 ;
}
return - V_38 ;
}
static int F_21 ( struct V_24 * V_68 , void * V_25 , unsigned int * V_61 )
{
* V_61 = 0 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_68 , void * V_25 , unsigned int V_61 )
{
if ( V_61 != 0 )
return - V_38 ;
return 0 ;
}
static int F_23 ( struct V_24 * V_24 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
return F_24 ( 0 , & V_2 -> V_69 ) ? - V_70 : 0 ;
}
static int F_25 ( struct V_24 * V_24 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
F_26 ( 0 , & V_2 -> V_69 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_71 ;
struct V_72 * V_73 ;
V_2 -> V_12 = 1 ;
F_1 ( V_2 , 0x55AA ) ;
if ( F_3 ( V_2 ) != 0x55AA )
return - V_74 ;
V_2 -> V_69 = 0 ;
V_2 -> V_3 = V_75 | V_76 ;
V_2 -> V_18 = 90500 * 16 ;
V_73 = F_28 () ;
if ( V_73 == NULL ) {
F_29 ( V_77 L_6 ) ;
return - V_78 ;
}
memcpy ( V_73 , & V_79 , sizeof( V_79 ) ) ;
strcpy ( V_79 . V_39 , V_2 -> V_20 ?
L_7 : L_8 ) ;
F_30 ( V_73 , V_2 ) ;
V_71 = F_31 ( V_73 ,
V_80 , V_81 ) ;
if ( V_71 ) {
F_29 ( V_77 L_9 ) ;
F_32 ( V_73 ) ;
return V_71 ;
}
F_5 ( V_2 ) ;
V_2 -> V_82 = V_73 ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 ) {
F_34 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
}
}
static int T_4 F_35 ( void )
{
return 0 ;
}
static void T_5 F_36 ( void )
{
}
