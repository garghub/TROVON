static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( V_4 -> V_5 == V_6 ) {
T_2 V_7 = F_2 ( V_8 + V_9 ) ;
V_7 &= ~ V_10 ;
F_3 ( V_7 , V_8 + V_9 ) ;
}
V_4 -> V_11 ( V_4 ) ;
return V_12 ;
}
static int F_4 ( unsigned long V_13 ,
struct V_3 * V_4 )
{
T_2 V_7 = F_2 ( V_8 + V_9 ) ;
V_7 &= ~ V_10 ;
F_3 ( V_7 , V_8 + V_9 ) ;
F_3 ( V_7 , V_8 + V_14 ) ;
F_3 ( V_13 , V_8 + V_15 ) ;
if ( V_16 )
while ( F_2 ( V_16 ) & V_17 )
F_5 () ;
F_3 ( V_7 | V_10 , V_8 + V_9 ) ;
return 0 ;
}
static void F_6 ( enum V_18 V_5 ,
struct V_3 * V_4 )
{
T_2 V_7 ;
V_7 = F_2 ( V_8 + V_9 ) ;
V_7 &= ~ ( V_10 | V_19 ) ;
switch ( V_5 ) {
case V_20 :
case V_21 :
break;
case V_6 :
break;
case V_22 :
case V_23 :
break;
}
F_3 ( V_7 , V_8 + V_9 ) ;
}
static T_3 T_4 F_7 ( struct V_24 * V_25 )
{
return F_2 ( V_26 + V_27 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_28 = F_9 () ;
int V_29 ;
V_4 -> V_1 = V_30 ;
V_4 -> V_31 = L_1 ;
V_4 -> V_32 = V_33 ;
V_4 -> V_34 = 200 ;
V_4 -> V_35 = F_6 ;
V_4 -> V_36 = F_4 ;
V_4 -> V_37 = F_10 ( V_28 ) ;
F_11 ( V_4 , V_38 , 4 , 0xffffffff ) ;
if ( V_39 ) {
F_12 ( V_4 -> V_1 , V_40 ) ;
} else {
V_29 = F_13 ( V_4 -> V_1 , F_1 ,
V_41 | V_42 |
V_43 , L_2 , V_4 ) ;
if ( V_29 )
F_14 ( L_3 ) ;
}
return 0 ;
}
static void F_15 ( struct V_3 * V_4 )
{
V_4 -> V_35 ( V_22 , V_4 ) ;
F_16 ( V_4 -> V_1 ) ;
}
static int F_17 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
switch ( V_46 & ~ V_48 ) {
case V_49 :
F_8 ( F_18 ( V_50 ) ) ;
break;
case V_51 :
F_15 ( F_18 ( V_50 ) ) ;
break;
}
return V_52 ;
}
static T_5 T_3 F_19 ( void )
{
return V_53 . V_54 ( & V_53 ) ;
}
static unsigned long F_20 ( void )
{
return V_53 . V_54 ( & V_53 ) ;
}
static void T_6 F_21 ( T_2 V_55 , int V_56 , int V_1 ,
bool V_57 )
{
struct V_24 * V_25 = & V_53 ;
int V_58 = 0 ;
V_30 = V_1 ;
V_39 = V_57 ;
V_50 = F_22 ( struct V_3 ) ;
if ( ! V_50 ) {
F_14 ( L_4 ) ;
goto V_29;
}
if ( V_57 )
V_58 = F_23 ( V_1 , F_1 ,
L_2 , V_50 ) ;
if ( V_58 ) {
F_14 ( L_5 ) ;
} else {
V_58 = F_24 ( & V_59 ) ;
if ( V_58 ) {
F_25 ( V_1 , V_50 ) ;
goto V_29;
}
F_8 ( F_26 ( V_50 ) ) ;
}
V_29:
F_3 ( V_10 , V_26 + V_9 ) ;
V_58 = F_27 ( V_25 , V_55 ) ;
if ( V_58 )
F_14 ( L_6 ) ;
F_28 ( F_19 , V_56 , V_55 ) ;
V_60 . V_61 = V_55 ;
F_29 ( & V_60 ) ;
}
static void T_6 F_30 ( struct V_62 * V_63 )
{
T_2 V_61 ;
int V_1 ;
struct V_64 V_58 ;
T_2 V_65 ;
void T_7 * V_66 ;
void T_7 * V_67 ;
V_66 = F_31 ( V_63 , 0 ) ;
if ( ! V_66 ) {
F_14 ( L_7 ) ;
return;
}
V_1 = F_32 ( V_63 , 1 ) ;
if ( V_1 <= 0 ) {
F_14 ( L_8 ) ;
return;
}
if ( F_33 ( V_63 , L_9 , & V_65 ) )
V_65 = 0 ;
if ( F_34 ( V_63 , 0 , & V_58 ) ) {
F_14 ( L_10 ) ;
return;
}
V_67 = F_35 ( V_58 . V_68 + V_65 , F_36 ( & V_58 ) ) ;
if ( ! V_67 ) {
F_14 ( L_11 ) ;
return;
}
if ( F_33 ( V_63 , L_12 , & V_61 ) ) {
F_14 ( L_13 ) ;
return;
}
V_8 = V_66 + 0x4 ;
V_16 = V_66 + 0x88 ;
V_26 = V_67 + 0x24 ;
V_61 /= 4 ;
F_3 ( V_69 , V_26 + V_70 ) ;
F_21 ( V_61 , 32 , V_1 , ! ! V_65 ) ;
}
static int T_6 F_37 ( T_8 V_71 , T_2 V_72 , T_2 V_73 ,
T_2 V_74 )
{
void T_7 * V_66 ;
V_66 = F_35 ( V_71 , V_75 ) ;
if ( ! V_66 ) {
F_14 ( L_14 ) ;
return - V_76 ;
}
V_8 = V_66 + V_72 ;
V_26 = V_66 + V_73 ;
if ( V_74 )
V_16 = V_66 + V_74 ;
return 0 ;
}
static T_3 T_4 F_38 ( struct V_24 * V_25 )
{
return F_7 ( V_25 ) >> V_77 ;
}
void T_6 F_39 ( void )
{
struct V_24 * V_25 = & V_53 ;
if ( F_37 ( 0xc0100000 , 0x0 , 0x10 , 0x0 ) )
return;
V_25 -> V_54 = F_38 ;
V_25 -> V_78 = F_40 ( ( 32 - V_77 ) ) ;
F_21 ( 19200000 >> V_77 , 32 - V_77 , 7 ,
false ) ;
}
void T_6 F_41 ( void )
{
if ( F_37 ( 0xc0100000 , 0x4 , 0x24 , 0x80 ) )
return;
F_21 ( 24576000 / 4 , 32 , 1 , false ) ;
}
void T_6 F_42 ( void )
{
if ( F_37 ( 0xAC100000 , 0x0 , 0x10 , 0x34 ) )
return;
F_21 ( 19200000 / 4 , 32 , 7 , false ) ;
}
