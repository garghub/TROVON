static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( F_2 ( V_4 ) ) {
T_2 V_5 = F_3 ( V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
F_4 ( V_5 , V_6 + V_7 ) ;
}
V_4 -> V_9 ( V_4 ) ;
return V_10 ;
}
static int F_5 ( unsigned long V_11 ,
struct V_3 * V_4 )
{
T_2 V_5 = F_3 ( V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
F_4 ( V_5 , V_6 + V_7 ) ;
F_4 ( V_5 , V_6 + V_12 ) ;
F_4 ( V_11 , V_6 + V_13 ) ;
if ( V_14 )
while ( F_3 ( V_14 ) & V_15 )
F_6 () ;
F_4 ( V_5 | V_8 , V_6 + V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
T_2 V_5 ;
V_5 = F_3 ( V_6 + V_7 ) ;
V_5 &= ~ ( V_8 | V_16 ) ;
F_4 ( V_5 , V_6 + V_7 ) ;
return 0 ;
}
static T_3 T_4 F_8 ( struct V_17 * V_18 )
{
return F_3 ( V_19 + V_20 ) ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_21 = F_10 () ;
int V_22 ;
V_4 -> V_1 = V_23 ;
V_4 -> V_24 = L_1 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 200 ;
V_4 -> V_28 = F_7 ;
V_4 -> V_29 = F_7 ;
V_4 -> V_30 = F_7 ;
V_4 -> V_31 = F_5 ;
V_4 -> V_32 = F_11 ( V_21 ) ;
F_12 ( V_4 , V_33 , 4 , 0xffffffff ) ;
if ( V_34 ) {
F_13 ( V_4 -> V_1 , V_35 ) ;
} else {
V_22 = F_14 ( V_4 -> V_1 , F_1 ,
V_36 | V_37 |
V_38 , L_2 , V_4 ) ;
if ( V_22 )
F_15 ( L_3 ) ;
}
return 0 ;
}
static void F_16 ( struct V_3 * V_4 )
{
V_4 -> V_28 ( V_4 ) ;
F_17 ( V_4 -> V_1 ) ;
}
static int F_18 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_42 )
{
switch ( V_41 & ~ V_43 ) {
case V_44 :
F_9 ( F_19 ( V_45 ) ) ;
break;
case V_46 :
F_16 ( F_19 ( V_45 ) ) ;
break;
}
return V_47 ;
}
static T_5 T_3 F_20 ( void )
{
return V_48 . V_49 ( & V_48 ) ;
}
static unsigned long F_21 ( void )
{
return V_48 . V_49 ( & V_48 ) ;
}
static void T_6 F_22 ( T_2 V_50 , int V_51 , int V_1 ,
bool V_52 )
{
struct V_17 * V_18 = & V_48 ;
int V_53 = 0 ;
V_23 = V_1 ;
V_34 = V_52 ;
V_45 = F_23 ( struct V_3 ) ;
if ( ! V_45 ) {
F_15 ( L_4 ) ;
goto V_22;
}
if ( V_52 )
V_53 = F_24 ( V_1 , F_1 ,
L_2 , V_45 ) ;
if ( V_53 ) {
F_15 ( L_5 ) ;
} else {
V_53 = F_25 ( & V_54 ) ;
if ( V_53 ) {
F_26 ( V_1 , V_45 ) ;
goto V_22;
}
F_9 ( F_27 ( V_45 ) ) ;
}
V_22:
F_4 ( V_8 , V_19 + V_7 ) ;
V_53 = F_28 ( V_18 , V_50 ) ;
if ( V_53 )
F_15 ( L_6 ) ;
F_29 ( F_20 , V_51 , V_50 ) ;
V_55 . V_56 = V_50 ;
F_30 ( & V_55 ) ;
}
static void T_6 F_31 ( struct V_57 * V_58 )
{
T_2 V_56 ;
int V_1 ;
struct V_59 V_53 ;
T_2 V_60 ;
void T_7 * V_61 ;
void T_7 * V_62 ;
V_61 = F_32 ( V_58 , 0 ) ;
if ( ! V_61 ) {
F_15 ( L_7 ) ;
return;
}
V_1 = F_33 ( V_58 , 1 ) ;
if ( V_1 <= 0 ) {
F_15 ( L_8 ) ;
return;
}
if ( F_34 ( V_58 , L_9 , & V_60 ) )
V_60 = 0 ;
if ( F_35 ( V_58 , 0 , & V_53 ) ) {
F_15 ( L_10 ) ;
return;
}
V_62 = F_36 ( V_53 . V_63 + V_60 , F_37 ( & V_53 ) ) ;
if ( ! V_62 ) {
F_15 ( L_11 ) ;
return;
}
if ( F_34 ( V_58 , L_12 , & V_56 ) ) {
F_15 ( L_13 ) ;
return;
}
V_6 = V_61 + 0x4 ;
V_14 = V_61 + 0x88 ;
V_19 = V_62 + 0x24 ;
V_56 /= 4 ;
F_4 ( V_64 , V_19 + V_65 ) ;
F_22 ( V_56 , 32 , V_1 , ! ! V_60 ) ;
}
