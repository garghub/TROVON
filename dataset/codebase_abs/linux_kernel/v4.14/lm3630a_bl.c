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
V_4 = F_3 ( V_2 , V_11 , 0x03 ) ;
V_4 |= F_5 ( V_2 , V_12 , 0x07 , V_10 -> V_13 ) ;
V_4 |= F_3 ( V_2 , V_14 , 0x38 ) ;
V_4 |= F_5 ( V_2 , V_15 , 0x1F , 0x1F ) ;
V_4 |= F_3 ( V_2 , V_16 , 0x1F ) ;
V_4 |= F_5 ( V_2 , V_17 , 0x14 , V_10 -> V_18 ) ;
V_4 |= F_5 ( V_2 , V_17 , 0x0B , V_10 -> V_19 ) ;
F_8 ( 1000 , 2000 ) ;
V_4 |= F_3 ( V_2 , V_20 , V_10 -> V_21 ) ;
V_4 |= F_3 ( V_2 , V_22 , V_10 -> V_23 ) ;
if ( V_4 < 0 )
F_9 ( V_2 -> V_24 , L_1 ) ;
return V_4 ;
}
static void F_10 ( struct V_25 * V_26 )
{
int V_4 ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_26 , struct V_1 , V_26 . V_26 ) ;
V_4 = F_1 ( V_2 , V_27 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 -> V_24 ,
L_2 ) ;
return;
}
F_12 ( V_2 -> V_24 , L_3 , V_4 ) ;
}
static T_1 F_13 ( int V_28 , void * V_29 )
{
int V_4 ;
struct V_1 * V_2 = V_29 ;
unsigned long V_30 = F_14 ( V_31 ) ;
F_15 ( V_2 -> V_32 , & V_2 -> V_26 , V_30 ) ;
V_4 = F_5 ( V_2 , V_17 , 0x80 , 0x00 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 -> V_24 , L_1 ) ;
return V_33 ;
}
return V_34 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_3 ( V_2 , V_35 , 0x87 ) ;
if ( V_4 < 0 )
return V_4 ;
F_17 ( & V_2 -> V_26 , F_10 ) ;
V_2 -> V_32 = F_18 ( L_4 ) ;
if ( ! V_2 -> V_32 ) {
F_9 ( V_2 -> V_24 , L_5 ) ;
return - V_36 ;
}
if ( F_19
( V_2 -> V_28 , NULL , F_13 ,
V_37 | V_38 , L_6 , V_2 ) ) {
F_9 ( V_2 -> V_24 , L_7 ) ;
F_20 ( V_2 -> V_32 ) ;
return - V_36 ;
}
return V_4 ;
}
static void F_21 ( struct V_1 * V_2 , int V_39 , int V_40 )
{
unsigned int V_41 = V_2 -> V_10 -> V_42 ;
unsigned int V_43 = V_39 * V_41 / V_40 ;
F_22 ( V_2 -> V_44 , V_43 , V_41 ) ;
if ( V_43 )
F_23 ( V_2 -> V_44 ) ;
else
F_24 ( V_2 -> V_44 ) ;
}
static int F_25 ( struct V_45 * V_46 )
{
int V_47 ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
enum F_21 V_13 = V_2 -> V_10 -> V_13 ;
if ( ( V_13 & V_48 ) != 0 ) {
F_21 ( V_2 , V_46 -> V_49 . V_50 ,
V_46 -> V_49 . V_51 ) ;
return V_46 -> V_49 . V_50 ;
}
V_47 = F_5 ( V_2 , V_17 , 0x80 , 0x00 ) ;
if ( V_47 < 0 )
goto V_52;
F_8 ( 1000 , 2000 ) ;
V_47 = F_3 ( V_2 , V_20 , V_46 -> V_49 . V_50 ) ;
if ( V_46 -> V_49 . V_50 < 0x4 )
V_47 |= F_5 ( V_2 , V_17 , V_53 , 0 ) ;
else
V_47 |= F_5 ( V_2 , V_17 ,
V_53 , V_53 ) ;
if ( V_47 < 0 )
goto V_52;
return V_46 -> V_49 . V_50 ;
V_52:
F_9 ( V_2 -> V_24 , L_8 ) ;
return V_46 -> V_49 . V_50 ;
}
static int F_27 ( struct V_45 * V_46 )
{
int V_50 , V_4 ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
enum F_21 V_13 = V_2 -> V_10 -> V_13 ;
if ( ( V_13 & V_48 ) != 0 ) {
V_4 = F_1 ( V_2 , V_54 ) ;
if ( V_4 < 0 )
goto V_52;
V_50 = ( V_4 & 0x01 ) << 8 ;
V_4 = F_1 ( V_2 , V_55 ) ;
if ( V_4 < 0 )
goto V_52;
V_50 |= V_4 ;
goto V_56;
}
V_4 = F_5 ( V_2 , V_17 , 0x80 , 0x00 ) ;
if ( V_4 < 0 )
goto V_52;
F_8 ( 1000 , 2000 ) ;
V_4 = F_1 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
goto V_52;
V_50 = V_4 ;
V_56:
V_46 -> V_49 . V_50 = V_50 ;
return V_46 -> V_49 . V_50 ;
V_52:
F_9 ( V_2 -> V_24 , L_1 ) ;
return 0 ;
}
static int F_28 ( struct V_45 * V_46 )
{
int V_47 ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
enum F_21 V_13 = V_2 -> V_10 -> V_13 ;
if ( ( V_13 & V_57 ) != 0 ) {
F_21 ( V_2 , V_46 -> V_49 . V_50 ,
V_46 -> V_49 . V_51 ) ;
return V_46 -> V_49 . V_50 ;
}
V_47 = F_5 ( V_2 , V_17 , 0x80 , 0x00 ) ;
if ( V_47 < 0 )
goto V_52;
F_8 ( 1000 , 2000 ) ;
V_47 = F_3 ( V_2 , V_22 , V_46 -> V_49 . V_50 ) ;
if ( V_46 -> V_49 . V_50 < 0x4 )
V_47 |= F_5 ( V_2 , V_17 , V_58 , 0 ) ;
else
V_47 |= F_5 ( V_2 , V_17 ,
V_58 , V_58 ) ;
if ( V_47 < 0 )
goto V_52;
return V_46 -> V_49 . V_50 ;
V_52:
F_9 ( V_2 -> V_24 , L_9 ) ;
return V_46 -> V_49 . V_50 ;
}
static int F_29 ( struct V_45 * V_46 )
{
int V_50 , V_4 ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
enum F_21 V_13 = V_2 -> V_10 -> V_13 ;
if ( ( V_13 & V_57 ) != 0 ) {
V_4 = F_1 ( V_2 , V_54 ) ;
if ( V_4 < 0 )
goto V_52;
V_50 = ( V_4 & 0x01 ) << 8 ;
V_4 = F_1 ( V_2 , V_55 ) ;
if ( V_4 < 0 )
goto V_52;
V_50 |= V_4 ;
goto V_56;
}
V_4 = F_5 ( V_2 , V_17 , 0x80 , 0x00 ) ;
if ( V_4 < 0 )
goto V_52;
F_8 ( 1000 , 2000 ) ;
V_4 = F_1 ( V_2 , V_22 ) ;
if ( V_4 < 0 )
goto V_52;
V_50 = V_4 ;
V_56:
V_46 -> V_49 . V_50 = V_50 ;
return V_46 -> V_49 . V_50 ;
V_52:
F_9 ( V_2 -> V_24 , L_1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_59 V_49 ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_49 . type = V_60 ;
if ( V_10 -> V_18 != V_61 ) {
V_49 . V_50 = V_10 -> V_21 ;
V_49 . V_51 = V_10 -> V_62 ;
V_2 -> V_63 =
F_31 ( V_2 -> V_24 , L_10 ,
V_2 -> V_24 , V_2 ,
& V_64 , & V_49 ) ;
if ( F_32 ( V_2 -> V_63 ) )
return F_33 ( V_2 -> V_63 ) ;
}
if ( ( V_10 -> V_19 != V_65 ) &&
( V_10 -> V_19 != V_66 ) ) {
V_49 . V_50 = V_10 -> V_23 ;
V_49 . V_51 = V_10 -> V_67 ;
V_2 -> V_68 =
F_31 ( V_2 -> V_24 , L_11 ,
V_2 -> V_24 , V_2 ,
& V_69 , & V_49 ) ;
if ( F_32 ( V_2 -> V_68 ) )
return F_33 ( V_2 -> V_68 ) ;
}
return 0 ;
}
static int F_34 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
struct V_9 * V_10 = F_35 ( & V_71 -> V_24 ) ;
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_36 ( V_71 -> V_74 , V_75 ) ) {
F_9 ( & V_71 -> V_24 , L_12 ) ;
return - V_76 ;
}
V_2 = F_37 ( & V_71 -> V_24 , sizeof( struct V_1 ) ,
V_77 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_24 = & V_71 -> V_24 ;
V_2 -> V_6 = F_38 ( V_71 , & V_78 ) ;
if ( F_32 ( V_2 -> V_6 ) ) {
V_4 = F_33 ( V_2 -> V_6 ) ;
F_9 ( & V_71 -> V_24 , L_13 , V_4 ) ;
return V_4 ;
}
F_39 ( V_71 , V_2 ) ;
if ( V_10 == NULL ) {
V_10 = F_37 ( V_2 -> V_24 ,
sizeof( struct V_9 ) ,
V_77 ) ;
if ( V_10 == NULL )
return - V_36 ;
V_10 -> V_18 = V_53 ;
V_10 -> V_19 = V_58 ;
V_10 -> V_62 = V_79 ;
V_10 -> V_67 = V_79 ;
V_10 -> V_21 = V_79 ;
V_10 -> V_23 = V_79 ;
}
V_2 -> V_10 = V_10 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_71 -> V_24 , L_14 ) ;
return V_4 ;
}
V_4 = F_30 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_71 -> V_24 , L_15 ) ;
return V_4 ;
}
if ( V_10 -> V_13 != V_80 ) {
V_2 -> V_44 = F_40 ( V_2 -> V_24 , L_16 ) ;
if ( F_32 ( V_2 -> V_44 ) ) {
F_9 ( & V_71 -> V_24 , L_17 ) ;
return F_33 ( V_2 -> V_44 ) ;
}
F_41 ( V_2 -> V_44 ) ;
}
V_2 -> V_28 = V_71 -> V_28 ;
if ( V_2 -> V_28 ) {
V_4 = F_16 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
}
F_12 ( & V_71 -> V_24 , L_18 ) ;
return 0 ;
}
static int F_42 ( struct V_70 * V_71 )
{
int V_4 ;
struct V_1 * V_2 = F_43 ( V_71 ) ;
V_4 = F_3 ( V_2 , V_20 , 0 ) ;
if ( V_4 < 0 )
F_9 ( V_2 -> V_24 , L_1 ) ;
V_4 = F_3 ( V_2 , V_22 , 0 ) ;
if ( V_4 < 0 )
F_9 ( V_2 -> V_24 , L_1 ) ;
if ( V_2 -> V_28 ) {
F_44 ( V_2 -> V_28 , V_2 ) ;
F_45 ( V_2 -> V_32 ) ;
F_20 ( V_2 -> V_32 ) ;
}
return 0 ;
}
