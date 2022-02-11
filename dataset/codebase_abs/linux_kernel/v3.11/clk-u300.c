static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
if ( ! V_2 -> V_5 )
return;
F_2 ( & V_6 , V_3 ) ;
V_4 = F_3 ( V_2 -> V_5 ) ;
V_4 |= F_4 ( V_2 -> V_7 ) ;
F_5 ( V_4 , V_2 -> V_5 ) ;
F_6 ( & V_6 , V_3 ) ;
V_2 -> V_8 = true ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
if ( ! V_2 -> V_5 )
return;
F_2 ( & V_6 , V_3 ) ;
V_4 = F_3 ( V_2 -> V_5 ) ;
V_4 &= ~ F_4 ( V_2 -> V_7 ) ;
F_5 ( V_4 , V_2 -> V_5 ) ;
F_6 ( & V_6 , V_3 ) ;
V_2 -> V_8 = false ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_11 == V_12 )
return;
if ( ! V_2 -> V_8 )
F_1 ( V_2 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_13 )
return 0 ;
if ( V_2 -> V_11 == 0xFFFFU )
return 0 ;
F_5 ( V_2 -> V_11 , V_14 + V_15 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_13 )
return;
if ( V_2 -> V_11 == 0xFFFFU )
return;
if ( V_2 -> V_11 == V_12 )
return;
F_5 ( V_2 -> V_11 , V_14 + V_16 ) ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
T_1 V_4 ;
if ( ! V_2 -> V_17 )
return 1 ;
V_4 = F_3 ( V_2 -> V_17 ) ;
V_4 &= F_4 ( V_2 -> V_18 ) ;
return V_4 ? 1 : 0 ;
}
static T_1 F_14 ( void )
{
T_1 V_4 ;
V_4 = F_3 ( V_14 + V_19 ) ;
V_4 &= V_20 ;
return V_4 ;
}
static unsigned long
F_15 ( struct V_9 * V_10 ,
unsigned long V_21 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
T_1 V_22 = F_14 () ;
switch( V_2 -> V_11 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 13000000 ;
default:
return V_21 ;
}
case V_30 :
case V_31 :
case V_32 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 6500000 ;
case V_33 :
return 26000000 ;
default:
return V_21 ;
}
case V_34 :
case V_35 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 13000000 ;
case V_33 :
return 52000000 ;
default:
return 104000000 ;
}
case V_36 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 13000000 ;
case V_33 :
return 52000000 ;
case V_37 :
return 104000000 ;
default:
return V_21 ;
}
default:
return V_21 ;
}
}
static long
F_16 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long * V_39 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_11 != V_36 )
return * V_39 ;
if ( V_38 <= 13000000 )
return 13000000 ;
if ( V_38 <= 52000000 )
return 52000000 ;
if ( V_38 <= 104000000 )
return 104000000 ;
return 208000000 ;
}
static int F_17 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long V_21 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
T_1 V_4 ;
if ( V_2 -> V_11 != V_36 )
return - V_40 ;
switch ( V_38 ) {
case 13000000 :
V_4 = V_28 ;
break;
case 52000000 :
V_4 = V_33 ;
break;
case 104000000 :
V_4 = V_37 ;
break;
case 208000000 :
V_4 = V_41 ;
break;
default:
return - V_40 ;
}
V_4 |= F_3 ( V_14 + V_19 ) &
~ V_20 ;
F_5 ( V_4 , V_14 + V_19 ) ;
return 0 ;
}
static struct V_42 * T_2
F_18 ( struct V_43 * V_44 , const char * V_45 ,
const char * V_46 , unsigned long V_47 ,
bool V_13 ,
void T_3 * V_5 , T_4 V_7 ,
void T_3 * V_17 , T_4 V_18 ,
T_1 V_11 )
{
struct V_42 * V_42 ;
struct V_1 * V_2 ;
struct V_48 V_49 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_50 ) ;
if ( ! V_2 ) {
F_20 ( L_1 ,
V_45 ) ;
return F_21 ( - V_51 ) ;
}
V_49 . V_45 = V_45 ;
V_49 . V_52 = & V_53 ;
V_49 . V_47 = V_47 ;
V_49 . V_54 = ( V_46 ? & V_46 : NULL ) ;
V_49 . V_55 = ( V_46 ? 1 : 0 ) ;
V_2 -> V_10 . V_49 = & V_49 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_8 = true ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_11 = V_11 ;
V_42 = F_22 ( V_44 , & V_2 -> V_10 ) ;
if ( F_23 ( V_42 ) )
F_24 ( V_2 ) ;
return V_42 ;
}
static void T_2 F_25 ( struct V_56 * V_57 )
{
struct V_42 * V_42 = F_21 ( - V_40 ) ;
const char * V_58 = V_57 -> V_45 ;
const char * V_46 ;
void T_3 * V_5 ;
void T_3 * V_17 ;
T_5 V_59 ;
T_5 V_60 ;
int V_61 ;
if ( F_26 ( V_57 , L_2 , & V_59 ) ) {
F_20 ( L_3 ,
V_62 , V_58 ) ;
return;
}
if ( F_26 ( V_57 , L_4 , & V_60 ) ) {
F_20 ( L_5 ,
V_62 , V_58 ) ;
return;
}
V_46 = F_27 ( V_57 , 0 ) ;
switch ( V_59 ) {
case V_63 :
V_5 = V_14 + V_64 ;
V_17 = V_14 + V_65 ;
break;
case V_66 :
V_5 = V_14 + V_67 ;
V_17 = V_14 + V_68 ;
break;
case V_69 :
V_5 = V_14 + V_70 ;
V_17 = V_14 + V_71 ;
break;
default:
F_20 ( L_6 , V_59 ) ;
return;
}
for ( V_61 = 0 ; V_61 < F_28 ( V_72 ) ; V_61 ++ ) {
const struct V_73 * V_74 = & V_72 [ V_61 ] ;
if ( V_74 -> type == V_59 && V_74 -> V_75 == V_60 )
V_42 = F_18 ( NULL ,
V_58 , V_46 ,
0 , V_74 -> V_13 ,
V_5 , V_74 -> V_75 ,
V_17 , V_74 -> V_75 ,
V_74 -> V_11 ) ;
}
if ( ! F_23 ( V_42 ) ) {
F_29 ( V_57 , V_76 , V_42 ) ;
if ( V_59 == V_69 && V_60 == 5 )
F_30 ( V_42 , NULL , L_7 ) ;
if ( V_59 == V_69 && V_60 == 9 )
F_30 ( V_42 , NULL , L_8 ) ;
if ( V_59 == V_69 && V_60 == 12 )
F_30 ( V_42 , NULL , L_9 ) ;
}
}
static int F_31 ( struct V_9 * V_10 )
{
struct V_77 * V_78 = F_32 ( V_10 ) ;
T_1 V_4 ;
if ( ! V_78 -> V_79 ) {
F_5 ( 0x0054U , V_14 + V_80 ) ;
V_4 = F_3 ( V_14 + V_81 ) ;
V_4 &= ~ V_82 ;
V_4 &= ~ V_83 ;
F_5 ( V_4 , V_14 + V_81 ) ;
} else {
V_4 = F_3 ( V_14 + V_81 ) ;
V_4 &= ~ V_82 ;
V_4 |= V_83 ;
F_5 ( V_4 , V_14 + V_81 ) ;
}
return 0 ;
}
static unsigned long
F_33 ( struct V_9 * V_10 ,
unsigned long V_21 )
{
T_1 V_22 = F_14 () ;
switch ( V_22 ) {
case V_28 :
return 13000000 ;
case V_29 :
case V_33 :
case V_37 :
case V_41 :
{
T_1 V_4 = F_3 ( V_14 + V_80 ) &
V_84 ;
switch ( V_4 ) {
case 0x0054 :
return 18900000 ;
case 0x0044 :
return 20800000 ;
case 0x0043 :
return 23100000 ;
case 0x0033 :
return 26000000 ;
case 0x0032 :
return 29700000 ;
case 0x0022 :
return 34700000 ;
case 0x0021 :
return 41600000 ;
case 0x0011 :
return 52000000 ;
case 0x0000 :
return 104000000 ;
default:
break;
}
}
default:
break;
}
return V_21 ;
}
static long
F_34 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long * V_39 )
{
if ( V_38 <= 18900000 )
return 18900000 ;
if ( V_38 <= 20800000 )
return 20800000 ;
if ( V_38 <= 23100000 )
return 23100000 ;
if ( V_38 <= 26000000 )
return 26000000 ;
if ( V_38 <= 29700000 )
return 29700000 ;
if ( V_38 <= 34700000 )
return 34700000 ;
if ( V_38 <= 41600000 )
return 41600000 ;
return 52000000 ;
}
static int F_35 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long V_21 )
{
T_1 V_4 ;
T_1 V_85 ;
switch ( V_38 ) {
case 18900000 :
V_4 = 0x0054 ;
break;
case 20800000 :
V_4 = 0x0044 ;
break;
case 23100000 :
V_4 = 0x0043 ;
break;
case 26000000 :
V_4 = 0x0033 ;
break;
case 29700000 :
V_4 = 0x0032 ;
break;
case 34700000 :
V_4 = 0x0022 ;
break;
case 41600000 :
V_4 = 0x0021 ;
break;
case 52000000 :
V_4 = 0x0011 ;
break;
case 104000000 :
V_4 = 0x0000 ;
break;
default:
return - V_40 ;
}
V_85 = F_3 ( V_14 + V_80 ) &
~ V_84 ;
F_5 ( V_85 | V_4 , V_14 + V_80 ) ;
return 0 ;
}
static struct V_42 * T_2
F_36 ( struct V_43 * V_44 , const char * V_45 ,
const char * V_46 , bool V_79 )
{
struct V_42 * V_42 ;
struct V_77 * V_78 ;
struct V_48 V_49 ;
V_78 = F_19 ( sizeof( struct V_77 ) , V_50 ) ;
if ( ! V_78 ) {
F_20 ( L_10 ,
V_45 ) ;
return F_21 ( - V_51 ) ;
}
V_49 . V_45 = L_11 ;
V_49 . V_52 = & V_86 ;
V_49 . V_47 = 0 ;
V_49 . V_54 = ( V_46 ? & V_46 : NULL ) ;
V_49 . V_55 = ( V_46 ? 1 : 0 ) ;
V_78 -> V_10 . V_49 = & V_49 ;
V_78 -> V_79 = V_79 ;
V_42 = F_22 ( V_44 , & V_78 -> V_10 ) ;
if ( F_23 ( V_42 ) )
F_24 ( V_78 ) ;
return V_42 ;
}
static void T_2 F_37 ( struct V_56 * V_57 )
{
struct V_42 * V_42 = F_21 ( - V_40 ) ;
const char * V_58 = V_57 -> V_45 ;
const char * V_46 ;
V_46 = F_27 ( V_57 , 0 ) ;
V_42 = F_36 ( NULL , V_58 , V_46 , false ) ;
if ( ! F_23 ( V_42 ) )
F_29 ( V_57 , V_76 , V_42 ) ;
}
void T_2 F_38 ( void T_3 * V_87 )
{
T_1 V_4 ;
V_14 = V_87 ;
V_4 = F_3 ( V_14 + V_19 ) ;
V_4 &= ~ V_20 ;
F_5 ( V_4 , V_14 + V_19 ) ;
while ( ! ( F_3 ( V_14 + V_88 ) &
V_89 ) ) ;
V_4 = F_3 ( V_14 + V_90 ) ;
V_4 |= V_91 ;
F_5 ( V_4 , V_14 + V_90 ) ;
F_39 ( V_92 ) ;
}
