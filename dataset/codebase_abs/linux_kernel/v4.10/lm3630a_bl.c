static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
unsigned int V_5 ;
V_4 = F_2 ( V_2 -> V_6 , V_3 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_5 & 0xFF ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_7 )
{
return F_4 ( V_2 -> V_6 , V_3 , V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 ,
unsigned int V_7 )
{
return F_6 ( V_2 -> V_6 , V_3 , V_8 , V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_9 * V_10 = V_2 -> V_10 ;
F_8 ( 1000 , 2000 ) ;
V_4 = F_3 ( V_2 , 0x50 , 0x03 ) ;
V_4 |= F_5 ( V_2 , V_11 , 0x07 , V_10 -> V_12 ) ;
V_4 |= F_3 ( V_2 , V_13 , 0x38 ) ;
V_4 |= F_5 ( V_2 , V_14 , 0x1F , 0x1F ) ;
V_4 |= F_3 ( V_2 , V_15 , 0x1F ) ;
V_4 |= F_5 ( V_2 , V_16 , 0x14 , V_10 -> V_17 ) ;
V_4 |= F_5 ( V_2 , V_16 , 0x0B , V_10 -> V_18 ) ;
F_8 ( 1000 , 2000 ) ;
V_4 |= F_3 ( V_2 , V_19 , V_10 -> V_20 ) ;
V_4 |= F_3 ( V_2 , V_21 , V_10 -> V_22 ) ;
if ( V_4 < 0 )
F_9 ( V_2 -> V_23 , L_1 ) ;
return V_4 ;
}
static void F_10 ( struct V_24 * V_25 )
{
int V_4 ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_25 , struct V_1 , V_25 . V_25 ) ;
V_4 = F_1 ( V_2 , V_26 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 -> V_23 ,
L_2 ) ;
return;
}
F_12 ( V_2 -> V_23 , L_3 , V_4 ) ;
}
static T_1 F_13 ( int V_27 , void * V_28 )
{
int V_4 ;
struct V_1 * V_2 = V_28 ;
unsigned long V_29 = F_14 ( V_30 ) ;
F_15 ( V_2 -> V_31 , & V_2 -> V_25 , V_29 ) ;
V_4 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 -> V_23 , L_1 ) ;
return V_32 ;
}
return V_33 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_3 ( V_2 , V_34 , 0x87 ) ;
if ( V_4 < 0 )
return V_4 ;
F_17 ( & V_2 -> V_25 , F_10 ) ;
V_2 -> V_31 = F_18 ( L_4 ) ;
if ( ! V_2 -> V_31 ) {
F_9 ( V_2 -> V_23 , L_5 ) ;
return - V_35 ;
}
if ( F_19
( V_2 -> V_27 , NULL , F_13 ,
V_36 | V_37 , L_6 , V_2 ) ) {
F_9 ( V_2 -> V_23 , L_7 ) ;
F_20 ( V_2 -> V_31 ) ;
return - V_35 ;
}
return V_4 ;
}
static void F_21 ( struct V_1 * V_2 , int V_38 , int V_39 )
{
unsigned int V_40 = V_2 -> V_10 -> V_41 ;
unsigned int V_42 = V_38 * V_40 / V_39 ;
F_22 ( V_2 -> V_43 , V_42 , V_40 ) ;
if ( V_42 )
F_23 ( V_2 -> V_43 ) ;
else
F_24 ( V_2 -> V_43 ) ;
}
static int F_25 ( struct V_44 * V_45 )
{
int V_46 ;
struct V_1 * V_2 = F_26 ( V_45 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_47 ) != 0 ) {
F_21 ( V_2 , V_45 -> V_48 . V_49 ,
V_45 -> V_48 . V_50 ) ;
return V_45 -> V_48 . V_49 ;
}
V_46 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_46 < 0 )
goto V_51;
F_8 ( 1000 , 2000 ) ;
V_46 = F_3 ( V_2 , V_19 , V_45 -> V_48 . V_49 ) ;
if ( V_45 -> V_48 . V_49 < 0x4 )
V_46 |= F_5 ( V_2 , V_16 , V_52 , 0 ) ;
else
V_46 |= F_5 ( V_2 , V_16 ,
V_52 , V_52 ) ;
if ( V_46 < 0 )
goto V_51;
return V_45 -> V_48 . V_49 ;
V_51:
F_9 ( V_2 -> V_23 , L_8 ) ;
return V_45 -> V_48 . V_49 ;
}
static int F_27 ( struct V_44 * V_45 )
{
int V_49 , V_4 ;
struct V_1 * V_2 = F_26 ( V_45 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_47 ) != 0 ) {
V_4 = F_1 ( V_2 , V_53 ) ;
if ( V_4 < 0 )
goto V_51;
V_49 = ( V_4 & 0x01 ) << 8 ;
V_4 = F_1 ( V_2 , V_54 ) ;
if ( V_4 < 0 )
goto V_51;
V_49 |= V_4 ;
goto V_55;
}
V_4 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_4 < 0 )
goto V_51;
F_8 ( 1000 , 2000 ) ;
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
goto V_51;
V_49 = V_4 ;
V_55:
V_45 -> V_48 . V_49 = V_49 ;
return V_45 -> V_48 . V_49 ;
V_51:
F_9 ( V_2 -> V_23 , L_1 ) ;
return 0 ;
}
static int F_28 ( struct V_44 * V_45 )
{
int V_46 ;
struct V_1 * V_2 = F_26 ( V_45 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_56 ) != 0 ) {
F_21 ( V_2 , V_45 -> V_48 . V_49 ,
V_45 -> V_48 . V_50 ) ;
return V_45 -> V_48 . V_49 ;
}
V_46 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_46 < 0 )
goto V_51;
F_8 ( 1000 , 2000 ) ;
V_46 = F_3 ( V_2 , V_21 , V_45 -> V_48 . V_49 ) ;
if ( V_45 -> V_48 . V_49 < 0x4 )
V_46 |= F_5 ( V_2 , V_16 , V_57 , 0 ) ;
else
V_46 |= F_5 ( V_2 , V_16 ,
V_57 , V_57 ) ;
if ( V_46 < 0 )
goto V_51;
return V_45 -> V_48 . V_49 ;
V_51:
F_9 ( V_2 -> V_23 , L_9 ) ;
return V_45 -> V_48 . V_49 ;
}
static int F_29 ( struct V_44 * V_45 )
{
int V_49 , V_4 ;
struct V_1 * V_2 = F_26 ( V_45 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_56 ) != 0 ) {
V_4 = F_1 ( V_2 , V_53 ) ;
if ( V_4 < 0 )
goto V_51;
V_49 = ( V_4 & 0x01 ) << 8 ;
V_4 = F_1 ( V_2 , V_54 ) ;
if ( V_4 < 0 )
goto V_51;
V_49 |= V_4 ;
goto V_55;
}
V_4 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_4 < 0 )
goto V_51;
F_8 ( 1000 , 2000 ) ;
V_4 = F_1 ( V_2 , V_21 ) ;
if ( V_4 < 0 )
goto V_51;
V_49 = V_4 ;
V_55:
V_45 -> V_48 . V_49 = V_49 ;
return V_45 -> V_48 . V_49 ;
V_51:
F_9 ( V_2 -> V_23 , L_1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_58 V_48 ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_48 . type = V_59 ;
if ( V_10 -> V_17 != V_60 ) {
V_48 . V_49 = V_10 -> V_20 ;
V_48 . V_50 = V_10 -> V_61 ;
V_2 -> V_62 =
F_31 ( V_2 -> V_23 , L_10 ,
V_2 -> V_23 , V_2 ,
& V_63 , & V_48 ) ;
if ( F_32 ( V_2 -> V_62 ) )
return F_33 ( V_2 -> V_62 ) ;
}
if ( ( V_10 -> V_18 != V_64 ) &&
( V_10 -> V_18 != V_65 ) ) {
V_48 . V_49 = V_10 -> V_22 ;
V_48 . V_50 = V_10 -> V_66 ;
V_2 -> V_67 =
F_31 ( V_2 -> V_23 , L_11 ,
V_2 -> V_23 , V_2 ,
& V_68 , & V_48 ) ;
if ( F_32 ( V_2 -> V_67 ) )
return F_33 ( V_2 -> V_67 ) ;
}
return 0 ;
}
static int F_34 ( struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
struct V_9 * V_10 = F_35 ( & V_70 -> V_23 ) ;
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_36 ( V_70 -> V_73 , V_74 ) ) {
F_9 ( & V_70 -> V_23 , L_12 ) ;
return - V_75 ;
}
V_2 = F_37 ( & V_70 -> V_23 , sizeof( struct V_1 ) ,
V_76 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_23 = & V_70 -> V_23 ;
V_2 -> V_6 = F_38 ( V_70 , & V_77 ) ;
if ( F_32 ( V_2 -> V_6 ) ) {
V_4 = F_33 ( V_2 -> V_6 ) ;
F_9 ( & V_70 -> V_23 , L_13 , V_4 ) ;
return V_4 ;
}
F_39 ( V_70 , V_2 ) ;
if ( V_10 == NULL ) {
V_10 = F_37 ( V_2 -> V_23 ,
sizeof( struct V_9 ) ,
V_76 ) ;
if ( V_10 == NULL )
return - V_35 ;
V_10 -> V_17 = V_52 ;
V_10 -> V_18 = V_57 ;
V_10 -> V_61 = V_78 ;
V_10 -> V_66 = V_78 ;
V_10 -> V_20 = V_78 ;
V_10 -> V_22 = V_78 ;
}
V_2 -> V_10 = V_10 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_70 -> V_23 , L_14 ) ;
return V_4 ;
}
V_4 = F_30 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_70 -> V_23 , L_15 ) ;
return V_4 ;
}
if ( V_10 -> V_12 != V_79 ) {
V_2 -> V_43 = F_40 ( V_2 -> V_23 , L_16 ) ;
if ( F_32 ( V_2 -> V_43 ) ) {
F_9 ( & V_70 -> V_23 , L_17 ) ;
return F_33 ( V_2 -> V_43 ) ;
}
F_41 ( V_2 -> V_43 ) ;
}
V_2 -> V_27 = V_70 -> V_27 ;
if ( V_2 -> V_27 ) {
V_4 = F_16 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
}
F_12 ( & V_70 -> V_23 , L_18 ) ;
return 0 ;
}
static int F_42 ( struct V_69 * V_70 )
{
int V_4 ;
struct V_1 * V_2 = F_43 ( V_70 ) ;
V_4 = F_3 ( V_2 , V_19 , 0 ) ;
if ( V_4 < 0 )
F_9 ( V_2 -> V_23 , L_1 ) ;
V_4 = F_3 ( V_2 , V_21 , 0 ) ;
if ( V_4 < 0 )
F_9 ( V_2 -> V_23 , L_1 ) ;
if ( V_2 -> V_27 ) {
F_44 ( V_2 -> V_27 , V_2 ) ;
F_45 ( V_2 -> V_31 ) ;
F_20 ( V_2 -> V_31 ) ;
}
return 0 ;
}
