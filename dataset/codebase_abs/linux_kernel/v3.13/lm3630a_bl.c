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
unsigned int V_40 = F_22 ( V_2 -> V_41 ) ;
unsigned int V_42 = V_38 * V_40 / V_39 ;
F_23 ( V_2 -> V_41 , V_42 , V_40 ) ;
if ( V_42 )
F_24 ( V_2 -> V_41 ) ;
else
F_25 ( V_2 -> V_41 ) ;
}
static int F_26 ( struct V_43 * V_44 )
{
int V_45 ;
struct V_1 * V_2 = F_27 ( V_44 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_46 ) != 0 ) {
F_21 ( V_2 , V_44 -> V_47 . V_48 ,
V_44 -> V_47 . V_49 ) ;
return V_44 -> V_47 . V_48 ;
}
V_45 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_45 < 0 )
goto V_50;
F_8 ( 1000 , 2000 ) ;
V_45 = F_3 ( V_2 , V_19 , V_44 -> V_47 . V_48 ) ;
if ( V_44 -> V_47 . V_48 < 0x4 )
V_45 |= F_5 ( V_2 , V_16 , V_51 , 0 ) ;
else
V_45 |= F_5 ( V_2 , V_16 ,
V_51 , V_51 ) ;
if ( V_45 < 0 )
goto V_50;
return V_44 -> V_47 . V_48 ;
V_50:
F_9 ( V_2 -> V_23 , L_8 ) ;
return V_44 -> V_47 . V_48 ;
}
static int F_28 ( struct V_43 * V_44 )
{
int V_48 , V_4 ;
struct V_1 * V_2 = F_27 ( V_44 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_46 ) != 0 ) {
V_4 = F_1 ( V_2 , V_52 ) ;
if ( V_4 < 0 )
goto V_50;
V_48 = ( V_4 & 0x01 ) << 8 ;
V_4 = F_1 ( V_2 , V_53 ) ;
if ( V_4 < 0 )
goto V_50;
V_48 |= V_4 ;
goto V_54;
}
V_4 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_4 < 0 )
goto V_50;
F_8 ( 1000 , 2000 ) ;
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
goto V_50;
V_48 = V_4 ;
V_54:
V_44 -> V_47 . V_48 = V_48 ;
return V_44 -> V_47 . V_48 ;
V_50:
F_9 ( V_2 -> V_23 , L_1 ) ;
return 0 ;
}
static int F_29 ( struct V_43 * V_44 )
{
int V_45 ;
struct V_1 * V_2 = F_27 ( V_44 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_55 ) != 0 ) {
F_21 ( V_2 , V_44 -> V_47 . V_48 ,
V_44 -> V_47 . V_49 ) ;
return V_44 -> V_47 . V_48 ;
}
V_45 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_45 < 0 )
goto V_50;
F_8 ( 1000 , 2000 ) ;
V_45 = F_3 ( V_2 , V_21 , V_44 -> V_47 . V_48 ) ;
if ( V_44 -> V_47 . V_48 < 0x4 )
V_45 |= F_5 ( V_2 , V_16 , V_56 , 0 ) ;
else
V_45 |= F_5 ( V_2 , V_16 ,
V_56 , V_56 ) ;
if ( V_45 < 0 )
goto V_50;
return V_44 -> V_47 . V_48 ;
V_50:
F_9 ( V_2 -> V_23 , L_9 ) ;
return V_44 -> V_47 . V_48 ;
}
static int F_30 ( struct V_43 * V_44 )
{
int V_48 , V_4 ;
struct V_1 * V_2 = F_27 ( V_44 ) ;
enum F_21 V_12 = V_2 -> V_10 -> V_12 ;
if ( ( V_12 & V_55 ) != 0 ) {
V_4 = F_1 ( V_2 , V_52 ) ;
if ( V_4 < 0 )
goto V_50;
V_48 = ( V_4 & 0x01 ) << 8 ;
V_4 = F_1 ( V_2 , V_53 ) ;
if ( V_4 < 0 )
goto V_50;
V_48 |= V_4 ;
goto V_54;
}
V_4 = F_5 ( V_2 , V_16 , 0x80 , 0x00 ) ;
if ( V_4 < 0 )
goto V_50;
F_8 ( 1000 , 2000 ) ;
V_4 = F_1 ( V_2 , V_21 ) ;
if ( V_4 < 0 )
goto V_50;
V_48 = V_4 ;
V_54:
V_44 -> V_47 . V_48 = V_48 ;
return V_44 -> V_47 . V_48 ;
V_50:
F_9 ( V_2 -> V_23 , L_1 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_57 V_47 ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_47 . type = V_58 ;
if ( V_10 -> V_17 != V_59 ) {
V_47 . V_48 = V_10 -> V_20 ;
V_47 . V_49 = V_10 -> V_60 ;
V_2 -> V_61 =
F_32 ( V_2 -> V_23 , L_10 ,
V_2 -> V_23 , V_2 ,
& V_62 , & V_47 ) ;
if ( F_33 ( V_2 -> V_61 ) )
return F_34 ( V_2 -> V_61 ) ;
}
if ( ( V_10 -> V_18 != V_63 ) &&
( V_10 -> V_18 != V_64 ) ) {
V_47 . V_48 = V_10 -> V_22 ;
V_47 . V_49 = V_10 -> V_65 ;
V_2 -> V_66 =
F_32 ( V_2 -> V_23 , L_11 ,
V_2 -> V_23 , V_2 ,
& V_67 , & V_47 ) ;
if ( F_33 ( V_2 -> V_66 ) )
return F_34 ( V_2 -> V_66 ) ;
}
return 0 ;
}
static int F_35 ( struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_9 * V_10 = F_36 ( & V_69 -> V_23 ) ;
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_37 ( V_69 -> V_72 , V_73 ) ) {
F_9 ( & V_69 -> V_23 , L_12 ) ;
return - V_74 ;
}
V_2 = F_38 ( & V_69 -> V_23 , sizeof( struct V_1 ) ,
V_75 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_23 = & V_69 -> V_23 ;
V_2 -> V_6 = F_39 ( V_69 , & V_76 ) ;
if ( F_33 ( V_2 -> V_6 ) ) {
V_4 = F_34 ( V_2 -> V_6 ) ;
F_9 ( & V_69 -> V_23 , L_13 , V_4 ) ;
return V_4 ;
}
F_40 ( V_69 , V_2 ) ;
if ( V_10 == NULL ) {
V_10 = F_38 ( V_2 -> V_23 ,
sizeof( struct V_9 ) ,
V_75 ) ;
if ( V_10 == NULL )
return - V_35 ;
V_10 -> V_17 = V_51 ;
V_10 -> V_18 = V_56 ;
V_10 -> V_60 = V_77 ;
V_10 -> V_65 = V_77 ;
V_10 -> V_20 = V_77 ;
V_10 -> V_22 = V_77 ;
}
V_2 -> V_10 = V_10 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_69 -> V_23 , L_14 ) ;
return V_4 ;
}
V_4 = F_31 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_69 -> V_23 , L_15 ) ;
return V_4 ;
}
if ( V_10 -> V_12 != V_78 ) {
V_2 -> V_41 = F_41 ( V_2 -> V_23 , L_16 ) ;
if ( F_33 ( V_2 -> V_41 ) ) {
F_9 ( & V_69 -> V_23 , L_17 ) ;
return F_34 ( V_2 -> V_41 ) ;
}
}
V_2 -> V_41 -> V_40 = V_10 -> V_79 ;
V_2 -> V_27 = V_69 -> V_27 ;
if ( V_2 -> V_27 ) {
V_4 = F_16 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
}
F_12 ( & V_69 -> V_23 , L_18 ) ;
return 0 ;
}
static int F_42 ( struct V_68 * V_69 )
{
int V_4 ;
struct V_1 * V_2 = F_43 ( V_69 ) ;
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
