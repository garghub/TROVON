static inline T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 |= V_2 ;
F_3 ( V_1 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_4 ( T_2 V_1 , T_1 V_4 )
{
T_1 V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 &= ~ V_4 ;
F_3 ( V_1 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_5 ( T_2 V_1 , T_1 V_2 )
{
T_1 V_3 ;
V_3 = F_6 ( V_1 ) ;
V_3 |= V_2 ;
F_7 ( V_1 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_8 ( T_2 V_1 , T_1 V_4 )
{
T_1 V_3 ;
V_3 = F_6 ( V_1 ) ;
V_3 &= ~ V_4 ;
F_7 ( V_1 , V_3 ) ;
return V_3 ;
}
void F_9 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_8 ) ;
unsigned long V_9 ;
if ( F_11 () == V_10 ||
F_11 () == V_11 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_1 ( V_13 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_14 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_8 ) ;
unsigned long V_9 ;
if ( F_11 () == V_10 ||
F_11 () == V_11 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_4 ( V_13 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_15 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_14 ) ;
unsigned long V_9 ;
if ( F_11 () == V_10 ||
F_11 () == V_11 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_1 ( V_15 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_16 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_14 ) ;
unsigned long V_9 ;
if ( F_11 () == V_10 ||
F_11 () == V_11 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_4 ( V_15 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_17 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_16 ) ;
unsigned long V_9 ;
if ( F_11 () == V_10 ||
F_11 () == V_11 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_1 ( V_17 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_18 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_16 ) ;
unsigned long V_9 ;
if ( F_11 () == V_10 ||
F_11 () == V_11 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_4 ( V_17 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_19 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_18 ) ;
unsigned long V_9 ;
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_1 ( V_19 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
void F_20 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_18 ) ;
unsigned long V_9 ;
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_4 ( V_19 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
void F_21 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_20 ) ;
unsigned long V_9 ;
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_1 ( V_21 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
void F_22 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_20 ) ;
unsigned long V_9 ;
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_4 ( V_21 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
void F_23 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_22 ) ;
unsigned long V_9 ;
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_5 ( V_23 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
void F_24 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_22 ) ;
unsigned long V_9 ;
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_8 ( V_23 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
void F_25 ( void )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_7 ( V_28 , V_29 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_26 ( void )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_7 ( V_28 , 0 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_27 ( void )
{
struct V_6 * V_7 = F_10 ( V_30 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_7 ( V_31 , V_32 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_28 ( void )
{
struct V_6 * V_7 = F_10 ( V_30 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_7 ( V_31 , 0 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_29 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_33 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_5 ( V_34 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_30 ( T_1 V_5 )
{
struct V_6 * V_7 = F_10 ( V_33 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_8 ( V_34 , V_5 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_31 ( void )
{
struct V_6 * V_7 = F_10 ( V_35 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_7 ( V_36 , V_37 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
void F_32 ( void )
{
struct V_6 * V_7 = F_10 ( V_35 ) ;
unsigned long V_9 ;
if ( F_11 () == V_25 ||
F_11 () == V_26 ||
F_11 () == V_27 ) {
F_12 ( & V_7 -> V_12 , V_9 ) ;
F_7 ( V_36 , 0 ) ;
F_13 ( & V_7 -> V_12 , V_9 ) ;
}
}
static void F_33 ( struct V_38 * V_39 )
{
F_4 ( V_40 , 1 << F_34 ( V_39 -> V_41 ) ) ;
}
static void F_35 ( struct V_38 * V_39 )
{
F_1 ( V_40 , 1 << F_34 ( V_39 -> V_41 ) ) ;
}
static void F_36 ( struct V_38 * V_39 )
{
F_8 ( V_42 , 1 << F_37 ( V_39 -> V_41 ) ) ;
}
static void F_38 ( struct V_38 * V_39 )
{
F_5 ( V_42 , 1 << F_37 ( V_39 -> V_41 ) ) ;
}
static inline int F_39 ( unsigned int V_41 , unsigned char V_43 )
{
struct V_6 * V_7 = F_10 ( V_41 ) ;
T_1 V_44 , V_45 ;
unsigned int V_46 ;
V_46 = F_34 ( V_41 ) ;
F_40 ( & V_7 -> V_12 ) ;
V_44 = F_2 ( V_47 ) ;
V_45 = F_2 ( V_48 ) ;
switch ( V_46 ) {
case 0 :
V_44 &= ~ V_49 ;
V_44 |= ( T_1 ) V_43 ;
break;
case 1 :
V_44 &= ~ ( V_49 << 3 ) ;
V_44 |= ( T_1 ) V_43 << 3 ;
break;
case 2 :
V_44 &= ~ ( V_49 << 6 ) ;
V_44 |= ( T_1 ) V_43 << 6 ;
break;
case 3 :
V_44 &= ~ ( V_49 << 9 ) ;
V_44 |= ( T_1 ) V_43 << 9 ;
break;
case 8 :
V_44 &= ~ ( V_49 << 12 ) ;
V_44 |= ( T_1 ) V_43 << 12 ;
break;
case 9 :
V_45 &= ~ V_49 ;
V_45 |= ( T_1 ) V_43 ;
break;
case 11 :
V_45 &= ~ ( V_49 << 6 ) ;
V_45 |= ( T_1 ) V_43 << 6 ;
break;
case 12 :
V_45 &= ~ ( V_49 << 9 ) ;
V_45 |= ( T_1 ) V_43 << 9 ;
break;
default:
F_41 ( & V_7 -> V_12 ) ;
return - V_50 ;
}
V_51 [ V_46 ] = V_43 ;
F_3 ( V_47 , V_44 ) ;
F_3 ( V_48 , V_45 ) ;
F_41 ( & V_7 -> V_12 ) ;
return 0 ;
}
static inline int F_42 ( unsigned int V_41 , unsigned char V_43 )
{
struct V_6 * V_7 = F_10 ( V_41 ) ;
T_1 V_52 , V_53 ;
unsigned int V_46 ;
V_46 = F_37 ( V_41 ) ;
F_40 ( & V_7 -> V_12 ) ;
V_52 = F_2 ( V_54 ) ;
V_53 = F_2 ( V_55 ) ;
switch ( V_46 ) {
case 0 :
V_52 &= ~ V_49 ;
V_52 |= ( T_1 ) V_43 ;
break;
case 1 :
V_52 &= ~ ( V_49 << 3 ) ;
V_52 |= ( T_1 ) V_43 << 3 ;
break;
case 3 :
V_52 &= ~ ( V_49 << 6 ) ;
V_52 |= ( T_1 ) V_43 << 6 ;
break;
case 4 :
V_52 &= ~ ( V_49 << 9 ) ;
V_52 |= ( T_1 ) V_43 << 9 ;
break;
case 5 :
V_52 &= ~ ( V_49 << 12 ) ;
V_52 |= ( T_1 ) V_43 << 12 ;
break;
case 6 :
V_53 &= ~ V_49 ;
V_53 |= ( T_1 ) V_43 ;
break;
case 7 :
V_53 &= ~ ( V_49 << 3 ) ;
V_53 |= ( T_1 ) V_43 << 3 ;
break;
case 8 :
V_53 &= ~ ( V_49 << 6 ) ;
V_53 |= ( T_1 ) V_43 << 6 ;
break;
case 9 :
V_53 &= ~ ( V_49 << 9 ) ;
V_53 |= ( T_1 ) V_43 << 9 ;
break;
case 10 :
V_53 &= ~ ( V_49 << 12 ) ;
V_53 |= ( T_1 ) V_43 << 12 ;
break;
default:
F_41 ( & V_7 -> V_12 ) ;
return - V_50 ;
}
V_56 [ V_46 ] = V_43 ;
F_3 ( V_54 , V_52 ) ;
F_3 ( V_55 , V_53 ) ;
F_41 ( & V_7 -> V_12 ) ;
return 0 ;
}
int F_43 ( unsigned int V_41 , unsigned char V_57 )
{
int V_58 = - V_50 ;
if ( F_11 () != V_27 )
return - V_50 ;
if ( V_57 > V_59 )
return - V_50 ;
if ( V_41 >= V_60 && V_41 <= V_61 )
V_58 = F_39 ( V_41 , V_57 ) ;
else if ( V_41 >= V_62 && V_41 <= V_63 )
V_58 = F_42 ( V_41 , V_57 ) ;
return V_58 ;
}
static int F_44 ( unsigned int V_41 )
{
T_1 V_64 , V_65 ;
T_1 V_66 , V_67 ;
int V_68 ;
V_64 = F_2 ( V_69 ) ;
V_66 = F_2 ( V_40 ) ;
V_65 = F_6 ( V_70 ) ;
V_67 = F_6 ( V_42 ) ;
V_66 &= V_64 ;
V_67 &= V_65 ;
if ( V_66 ) {
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ ) {
if ( V_41 == F_45 ( V_51 [ V_68 ] ) && ( V_66 & ( 1 << V_68 ) ) )
return F_46 ( V_68 ) ;
}
}
if ( V_67 ) {
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ ) {
if ( V_41 == F_45 ( V_56 [ V_68 ] ) && ( V_67 & ( 1 << V_68 ) ) )
return F_47 ( V_68 ) ;
}
}
F_48 ( V_71 L_1 , V_64 , V_65 ) ;
F_49 ( & V_72 ) ;
return - 1 ;
}
static int T_3 F_50 ( void )
{
unsigned long V_73 , V_74 ;
int V_68 ;
switch ( F_11 () ) {
case V_10 :
case V_11 :
V_73 = V_75 ;
V_74 = V_76 ;
break;
case V_25 :
case V_26 :
case V_27 :
V_73 = V_77 ;
V_74 = V_78 ;
break;
default:
F_48 ( V_71 L_2 ) ;
return - V_79 ;
}
if ( F_51 ( V_73 , V_80 , L_3 ) == NULL )
return - V_81 ;
if ( F_51 ( V_74 , V_82 , L_3 ) == NULL ) {
F_52 ( V_73 , V_80 ) ;
return - V_81 ;
}
V_83 = F_53 ( V_73 , V_80 ) ;
if ( V_83 == NULL ) {
F_52 ( V_73 , V_80 ) ;
F_52 ( V_74 , V_82 ) ;
return - V_84 ;
}
V_85 = F_53 ( V_74 , V_82 ) ;
if ( V_85 == NULL ) {
F_54 ( V_83 ) ;
F_52 ( V_73 , V_80 ) ;
F_52 ( V_74 , V_82 ) ;
return - V_84 ;
}
F_3 ( V_40 , 0 ) ;
F_3 ( V_86 , 0xffff ) ;
F_7 ( V_42 , 0 ) ;
F_7 ( V_87 , 0xffff ) ;
for ( V_68 = V_60 ; V_68 <= V_61 ; V_68 ++ )
F_55 ( V_68 , & V_88 ,
V_89 ) ;
for ( V_68 = V_62 ; V_68 <= V_63 ; V_68 ++ )
F_55 ( V_68 , & V_90 ,
V_89 ) ;
F_56 ( V_91 , F_44 ) ;
F_56 ( V_92 , F_44 ) ;
F_56 ( V_93 , F_44 ) ;
F_56 ( V_94 , F_44 ) ;
F_56 ( V_95 , F_44 ) ;
return 0 ;
}
