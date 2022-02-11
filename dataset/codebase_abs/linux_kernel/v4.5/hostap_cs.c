static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_10 , V_3 , V_4 ) ;
F_5 ( V_4 , V_2 -> V_11 + V_3 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
T_1 V_4 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_4 = F_8 ( V_2 -> V_11 + V_3 ) ;
F_4 ( V_2 , V_12 , V_3 , V_4 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return V_4 ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_3 , T_3 V_4 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_13 , V_3 , V_4 ) ;
F_10 ( V_4 , V_2 -> V_11 + V_3 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static inline T_3 F_11 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
T_3 V_4 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_4 = F_12 ( V_2 -> V_11 + V_3 ) ;
F_4 ( V_2 , V_14 , V_3 , V_4 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return V_4 ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_15 , int V_16 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_17 , V_3 , V_16 ) ;
F_14 ( V_2 -> V_11 + V_3 , V_15 , V_16 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_15 , int V_16 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_18 , V_3 , V_16 ) ;
F_16 ( V_2 -> V_11 + V_3 , V_15 , V_16 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_19 , void * V_15 ,
int V_20 )
{
T_3 V_21 ;
T_3 * V_22 ;
V_21 = ( V_19 == 1 ) ? V_23 : V_24 ;
V_22 = ( T_3 * ) V_15 ;
if ( V_20 / 2 )
F_18 ( V_21 , V_15 , V_20 / 2 ) ;
V_22 += V_20 / 2 ;
if ( V_20 & 1 )
* ( ( char * ) V_22 ) = F_19 ( V_21 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_19 , void * V_15 , int V_20 )
{
T_3 V_21 ;
T_3 * V_22 ;
V_21 = ( V_19 == 1 ) ? V_23 : V_24 ;
V_22 = ( T_3 * ) V_15 ;
if ( V_20 / 2 )
F_21 ( V_21 , V_15 , V_20 / 2 ) ;
V_22 += V_20 / 2 ;
if ( V_20 & 1 )
F_22 ( * ( ( char * ) V_22 ) , V_21 ) ;
return 0 ;
}
static int F_23 ( T_2 * V_7 )
{
struct V_25 * V_26 = V_7 -> V_26 ;
if ( V_26 != NULL && V_26 -> V_27 != NULL && F_24 ( V_26 -> V_27 ) )
return 1 ;
return 0 ;
}
static void F_25 ( T_2 * V_7 )
{
int V_28 ;
struct V_25 * V_26 = V_7 -> V_26 ;
V_28 = F_26 ( V_26 -> V_27 , 0x10 ,
V_26 -> V_27 -> V_29 [ 0 ] -> V_30 & 0x00ff ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_1
L_2 , V_28 ) ;
}
F_28 ( 10 ) ;
V_28 = F_26 ( V_26 -> V_27 , 0x12 ,
( V_26 -> V_27 -> V_29 [ 0 ] -> V_30 >> 8 ) & 0x00ff ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_3
L_2 , V_28 ) ;
}
}
static void F_29 ( T_2 * V_7 , int V_32 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_33 ;
F_22 ( 0x80 , V_34 ) ;
F_28 ( 50 ) ;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ ) {
F_22 ( V_32 , V_35 ) ;
}
F_28 ( 55 ) ;
F_22 ( 0x45 , V_34 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_28 , V_36 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_7 = V_6 -> V_7 ;
struct V_25 * V_26 = V_7 -> V_26 ;
if ( F_31 ( V_26 -> V_27 -> V_29 [ 0 ] ) < 0x42 ) {
V_36 = - V_37 ;
goto V_38;
}
if ( V_26 -> V_27 -> V_39 != 0xd601 || V_26 -> V_27 -> V_40 != 0x0101 ) {
V_36 = - V_37 ;
goto V_38;
}
if ( V_26 -> V_27 -> V_41 -> V_42 < 2 ) {
V_36 = - V_37 ;
goto V_38;
}
F_27 ( V_31 L_4
L_5 , V_2 -> V_43 ) ;
V_26 -> V_44 = 1 ;
V_28 = F_26 ( V_26 -> V_27 , V_45 ,
V_46 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_6 ,
V_2 -> V_43 , V_28 ) ;
goto V_38;
}
F_32 ( 5 ) ;
V_28 = F_26 ( V_26 -> V_27 , V_45 ,
( V_47 | 0x8 | V_48 |
V_49 ) ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_6 ,
V_2 -> V_43 , V_28 ) ;
goto V_38;
}
F_32 ( 5 ) ;
F_25 ( V_7 ) ;
F_22 ( 0xc5 , V_34 ) ;
F_28 ( 10 ) ;
F_22 ( 0x4b , V_34 ) ;
F_28 ( 10 ) ;
V_38:
return V_36 ;
}
static void F_33 ( T_2 * V_7 )
{
int V_28 ;
T_1 V_50 ;
struct V_25 * V_26 = V_7 -> V_26 ;
if ( ! F_23 ( V_7 ) )
return;
V_28 = F_34 ( V_26 -> V_27 , V_45 , & V_50 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_7 ,
V_28 ) ;
return;
}
F_27 ( V_31 L_8 ,
V_50 ) ;
V_50 |= V_46 ;
V_28 = F_26 ( V_26 -> V_27 , V_45 , V_50 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_9 ,
V_28 ) ;
return;
}
F_32 ( V_26 -> V_44 ? 5 : 2 ) ;
V_50 &= ~ V_46 ;
if ( V_26 -> V_44 )
V_50 |= V_51 ;
V_28 = F_26 ( V_26 -> V_27 , V_45 , V_50 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_10 ,
V_28 ) ;
return;
}
F_32 ( V_26 -> V_44 ? 5 : 2 ) ;
if ( V_26 -> V_44 )
F_25 ( V_7 ) ;
}
static void F_35 ( T_2 * V_7 , int V_32 )
{
int V_28 ;
T_1 V_52 ;
struct V_25 * V_26 = V_7 -> V_26 ;
if ( ! F_23 ( V_7 ) )
return;
if ( V_26 -> V_44 ) {
F_29 ( V_7 , V_32 ) ;
return;
}
V_28 = F_34 ( V_26 -> V_27 , V_45 , & V_52 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_11 , V_53 , V_28 ) ;
return;
}
F_27 ( V_31 L_12 , V_53 , V_52 ) ;
V_28 = F_26 ( V_26 -> V_27 , V_45 ,
V_52 | V_46 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_13 , V_53 , V_28 ) ;
return;
}
F_32 ( 10 ) ;
V_28 = F_26 ( V_26 -> V_27 , V_54 , V_32 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_14 , V_53 , V_28 ) ;
return;
}
F_32 ( 10 ) ;
V_28 = F_26 ( V_26 -> V_27 , V_45 ,
V_52 & ~ V_46 ) ;
if ( V_28 != 0 ) {
F_27 ( V_31 L_15 , V_53 , V_28 ) ;
return;
}
F_32 ( 10 ) ;
}
static int F_36 ( struct V_55 * V_56 )
{
int V_36 ;
F_37 ( V_57 , L_16 , V_58 ) ;
V_36 = F_38 ( V_56 ) ;
if ( V_36 ) {
F_37 ( V_59 , L_17 ) ;
}
return V_36 ;
}
static void F_39 ( struct V_55 * V_27 )
{
F_37 ( V_60 , L_18 ) ;
F_40 ( ( V_61 ) V_27 ) ;
if ( V_27 -> V_62 ) {
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = V_27 -> V_62 ;
V_6 = F_2 ( V_2 ) ;
V_26 = V_6 -> V_7 -> V_26 ;
F_41 ( V_2 ) ;
F_42 ( V_26 ) ;
}
}
static int F_43 ( struct V_55 * V_56 , void * V_63 )
{
if ( V_56 -> V_64 == 0 )
return - V_65 ;
return F_44 ( V_56 ) ;
}
static int F_38 ( struct V_55 * V_27 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
T_2 * V_7 ;
int V_36 ;
struct V_25 * V_26 ;
unsigned long V_8 ;
F_37 ( V_60 , L_19 ) ;
V_26 = F_45 ( sizeof( * V_26 ) , V_66 ) ;
if ( V_26 == NULL ) {
V_36 = - V_67 ;
goto V_68;
}
V_27 -> V_69 |= V_70 | V_71 |
V_72 | V_73 | V_74 ;
if ( V_75 )
V_27 -> V_69 &= ~ V_72 ;
V_36 = F_46 ( V_27 , F_43 , NULL ) ;
if ( V_36 ) {
if ( ! V_75 )
F_27 ( V_76 L_20
L_21
L_22 ) ;
goto V_68;
}
V_2 = F_47 ( & V_77 , 0 ,
& V_27 -> V_2 ) ;
if ( ! V_2 ) {
V_36 = - V_67 ;
goto V_68;
}
V_27 -> V_62 = V_2 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
V_7 -> V_26 = V_26 ;
V_26 -> V_27 = V_27 ;
V_36 = F_48 ( V_27 , V_78 ) ;
if ( V_36 )
goto V_68;
V_36 = F_49 ( V_27 ) ;
if ( V_36 )
goto V_68;
F_3 ( & V_7 -> V_79 , V_8 ) ;
V_2 -> V_80 = V_27 -> V_80 ;
V_2 -> V_11 = V_27 -> V_29 [ 0 ] -> V_30 ;
F_6 ( & V_7 -> V_79 , V_8 ) ;
V_7 -> V_81 = 0 ;
F_30 ( V_2 ) ;
V_36 = F_50 ( V_2 , 1 ) ;
if ( ! V_36 )
V_36 = F_51 ( V_2 ) ;
return V_36 ;
V_68:
F_42 ( V_26 ) ;
F_40 ( ( V_61 ) V_27 ) ;
return V_36 ;
}
static void F_40 ( V_61 V_82 )
{
struct V_55 * V_27 = (struct V_55 * ) V_82 ;
F_37 ( V_60 , L_23 ) ;
if ( V_27 -> V_62 ) {
struct V_1 * V_2 = V_27 -> V_62 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
F_52 ( V_2 , 0 ) ;
V_6 -> V_7 -> V_81 = 1 ;
}
F_53 ( V_27 ) ;
F_37 ( V_60 , L_24 ) ;
}
static int F_54 ( struct V_55 * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 -> V_62 ;
int V_83 = 0 ;
struct V_5 * V_6 = NULL ;
if ( ! V_2 )
return - V_37 ;
V_6 = F_2 ( V_2 ) ;
F_37 ( V_59 , L_25 , V_58 ) ;
if ( V_6 && V_6 -> V_7 )
V_83 = V_6 -> V_7 -> V_84 > 0 ;
if ( V_83 ) {
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
}
F_57 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_55 * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 -> V_62 ;
int V_83 = 0 ;
struct V_5 * V_6 = NULL ;
if ( ! V_2 )
return - V_37 ;
V_6 = F_2 ( V_2 ) ;
F_37 ( V_59 , L_26 , V_58 ) ;
if ( V_6 && V_6 -> V_7 )
V_83 = V_6 -> V_7 -> V_84 > 0 ;
F_52 ( V_2 , 1 ) ;
F_50 ( V_2 , V_83 ? 0 : 1 ) ;
if ( V_83 ) {
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
