static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 -> V_5 ) | ( V_6 ) ;
F_3 ( V_3 , ( & V_2 -> V_4 -> V_5 ) ) ;
}
static T_2 F_4 ( struct V_7 T_3 * V_4 )
{
T_2 V_8 ;
T_1 V_9 , V_10 ;
V_9 = F_2 ( & V_4 -> V_11 ) ;
V_10 = F_2 ( & V_4 -> V_12 ) ;
V_8 = ( ( T_2 ) V_10 ) << 32 ;
V_8 |= V_9 ;
V_8 <<= V_13 ;
return V_8 ;
}
static void F_5 ( struct V_7 T_3 * V_4 , T_2 V_8 )
{
T_1 V_10 , V_9 ;
V_8 >>= V_13 ;
V_10 = V_8 >> 32 ;
V_9 = V_8 & 0xffffffff ;
F_3 ( V_9 , & V_4 -> V_11 ) ;
F_3 ( V_10 , & V_4 -> V_12 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 -> V_14 ) | V_15 ;
F_3 ( V_3 , ( & V_2 -> V_4 -> V_14 ) ) ;
V_3 = V_3 & ~ V_15 ;
F_3 ( V_3 , ( & V_2 -> V_4 -> V_14 ) ) ;
}
T_1 F_7 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
T_1 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 -> V_18 ) ;
return V_3 ;
}
void F_9 ( struct V_16 * V_17 , T_1 V_3 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_3 ( V_3 , ( & V_2 -> V_4 -> V_18 ) ) ;
}
T_1 F_10 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
T_1 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 -> V_19 ) ;
return V_3 ;
}
void F_11 ( struct V_16 * V_17 , T_1 V_3 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_3 ( V_3 , ( & V_2 -> V_4 -> V_19 ) ) ;
}
T_1 F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
T_1 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 -> V_20 ) ;
return V_3 ;
}
T_1 F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
T_1 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 -> V_21 ) ;
return V_3 ;
}
T_2 F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
T_2 V_8 ;
T_1 V_9 , V_10 ;
V_9 = F_2 ( & V_2 -> V_4 -> V_22 ) ;
V_10 = F_2 ( & V_2 -> V_4 -> V_23 ) ;
V_8 = ( ( T_2 ) V_10 ) << 32 ;
V_8 |= V_9 ;
V_8 <<= V_13 ;
return V_8 ;
}
T_2 F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
T_2 V_8 ;
T_1 V_9 , V_10 ;
V_9 = F_2 ( & V_2 -> V_4 -> V_24 ) ;
V_10 = F_2 ( & V_2 -> V_4 -> V_25 ) ;
V_8 = ( ( T_2 ) V_10 ) << 32 ;
V_8 |= V_9 ;
V_8 <<= V_13 ;
return V_8 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_3 ( 0x01 , & V_2 -> V_4 -> V_26 ) ;
F_3 ( 0xFFFFFFFF , & V_2 -> V_4 -> V_27 ) ;
F_3 ( 0x00 , & V_2 -> V_4 -> V_26 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_16 ( V_2 ) ;
}
int F_18 ( T_4 * V_28 , struct V_16 * V_17 )
{
T_5 V_29 ;
struct V_1 * V_2 = F_8 ( V_17 ) ;
if ( ( V_2 -> V_4 == NULL ) || V_28 == ( T_4 * ) NULL ) {
F_19 ( & V_17 -> V_30 ,
L_1 ) ;
return V_31 ;
}
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
T_1 V_3 ;
T_5 V_33 ;
V_33 = F_20 ( V_28 [ V_29 * 3 ] ) ;
if ( V_33 < 0 ) {
F_19 ( & V_17 -> V_30 ,
L_1 ) ;
return V_31 ;
}
V_3 = V_33 * 16 ;
V_33 = F_20 ( V_28 [ ( V_29 * 3 ) + 1 ] ) ;
if ( V_33 < 0 ) {
F_19 ( & V_17 -> V_30 ,
L_1 ) ;
return V_31 ;
}
V_3 += V_33 ;
if ( ( V_29 < 5 ) && ( V_28 [ ( V_29 * 3 ) + 2 ] != ':' ) ) {
F_19 ( & V_17 -> V_30 ,
L_1 ) ;
return V_31 ;
}
F_21 ( & V_17 -> V_30 , L_2 ) ;
F_3 ( V_3 , & V_2 -> V_4 -> V_34 [ V_29 ] ) ;
}
return 0 ;
}
static T_6 F_22 ( int V_35 , void * V_36 )
{
struct V_1 * V_1 = V_36 ;
struct V_7 T_3 * V_4 = V_1 -> V_4 ;
struct V_37 V_38 ;
T_1 V_39 = 0 , V_9 , V_10 , V_3 ;
V_3 = F_2 ( & V_4 -> V_38 ) ;
if ( V_3 & V_40 ) {
V_39 |= V_40 ;
if ( V_1 -> V_41 ) {
V_10 = F_2 ( & V_4 -> V_42 ) ;
V_9 = F_2 ( & V_4 -> V_43 ) ;
V_38 . type = V_44 ;
V_38 . V_45 = 0 ;
V_38 . V_46 = ( ( T_2 ) V_10 ) << 32 ;
V_38 . V_46 |= V_9 ;
V_38 . V_46 <<= V_13 ;
V_37 ( V_1 -> V_47 , & V_38 ) ;
}
}
if ( V_3 & V_48 ) {
V_39 |= V_48 ;
if ( V_1 -> V_49 ) {
V_10 = F_2 ( & V_4 -> V_50 ) ;
V_9 = F_2 ( & V_4 -> V_51 ) ;
V_38 . type = V_44 ;
V_38 . V_45 = 1 ;
V_38 . V_46 = ( ( T_2 ) V_10 ) << 32 ;
V_38 . V_46 |= V_9 ;
V_38 . V_46 <<= V_13 ;
V_37 ( V_1 -> V_47 , & V_38 ) ;
}
}
if ( V_3 & V_52 )
V_39 |= V_52 ;
if ( V_39 ) {
F_3 ( V_39 , & V_4 -> V_38 ) ;
return V_53 ;
} else
return V_54 ;
}
static int F_23 ( struct V_55 * V_56 , T_5 V_57 )
{
T_2 V_58 ;
T_1 V_59 , V_60 ;
int V_61 = 0 ;
struct V_1 * V_1 = F_24 ( V_56 , struct V_1 , V_62 ) ;
struct V_7 T_3 * V_4 = V_1 -> V_4 ;
if ( V_57 < 0 ) {
V_61 = 1 ;
V_57 = - V_57 ;
}
V_60 = V_63 ;
V_58 = V_60 ;
V_58 *= V_57 ;
V_59 = F_25 ( V_58 , 1000000000ULL ) ;
V_60 = V_61 ? V_60 - V_59 : V_60 + V_59 ;
F_3 ( V_60 , & V_4 -> V_60 ) ;
return 0 ;
}
static int F_26 ( struct V_55 * V_56 , T_7 V_64 )
{
T_7 V_65 ;
unsigned long V_66 ;
struct V_1 * V_1 = F_24 ( V_56 , struct V_1 , V_62 ) ;
struct V_7 T_3 * V_4 = V_1 -> V_4 ;
F_27 ( & V_1 -> V_67 , V_66 ) ;
V_65 = F_4 ( V_4 ) ;
V_65 += V_64 ;
F_5 ( V_4 , V_65 ) ;
F_28 ( & V_1 -> V_67 , V_66 ) ;
return 0 ;
}
static int F_29 ( struct V_55 * V_56 , struct V_68 * V_69 )
{
T_2 V_8 ;
T_1 V_70 ;
unsigned long V_66 ;
struct V_1 * V_1 = F_24 ( V_56 , struct V_1 , V_62 ) ;
struct V_7 T_3 * V_4 = V_1 -> V_4 ;
F_27 ( & V_1 -> V_67 , V_66 ) ;
V_8 = F_4 ( V_4 ) ;
F_28 ( & V_1 -> V_67 , V_66 ) ;
V_69 -> V_71 = F_30 ( V_8 , 1000000000 , & V_70 ) ;
V_69 -> V_72 = V_70 ;
return 0 ;
}
static int F_31 ( struct V_55 * V_56 ,
const struct V_68 * V_69 )
{
T_2 V_8 ;
unsigned long V_66 ;
struct V_1 * V_1 = F_24 ( V_56 , struct V_1 , V_62 ) ;
struct V_7 T_3 * V_4 = V_1 -> V_4 ;
V_8 = V_69 -> V_71 * 1000000000ULL ;
V_8 += V_69 -> V_72 ;
F_27 ( & V_1 -> V_67 , V_66 ) ;
F_5 ( V_4 , V_8 ) ;
F_28 ( & V_1 -> V_67 , V_66 ) ;
return 0 ;
}
static int F_32 ( struct V_55 * V_56 ,
struct V_73 * V_74 , int V_75 )
{
struct V_1 * V_1 = F_24 ( V_56 , struct V_1 , V_62 ) ;
switch ( V_74 -> type ) {
case V_76 :
switch ( V_74 -> V_77 . V_45 ) {
case 0 :
V_1 -> V_41 = V_75 ? 1 : 0 ;
break;
case 1 :
V_1 -> V_49 = V_75 ? 1 : 0 ;
break;
default:
return - V_78 ;
}
return 0 ;
default:
break;
}
return - V_79 ;
}
static T_5 F_33 ( struct V_16 * V_17 , T_8 V_80 )
{
F_34 ( V_17 ) ;
F_35 ( V_17 , V_81 , 0 ) ;
if ( F_36 ( V_17 ) != 0 ) {
F_19 ( & V_17 -> V_30 , L_3 ) ;
return - V_82 ;
}
F_37 ( V_17 , F_38 ( V_17 , V_80 ) ) ;
return 0 ;
}
static T_5 F_39 ( struct V_16 * V_17 )
{
T_5 V_83 ;
F_37 ( V_17 , V_84 ) ;
F_40 ( V_17 ) ;
V_83 = F_41 ( V_17 ) ;
if ( V_83 ) {
F_19 ( & V_17 -> V_30 , L_4 ) ;
return V_83 ;
}
F_35 ( V_17 , V_81 , 0 ) ;
return 0 ;
}
static void F_42 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_43 ( V_2 -> V_47 ) ;
if ( V_17 -> V_35 != 0 )
F_44 ( V_17 -> V_35 , V_2 ) ;
if ( V_2 -> V_4 != NULL ) {
F_45 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
if ( V_2 -> V_85 != 0 ) {
F_46 ( V_2 -> V_85 , V_2 -> V_86 ) ;
V_2 -> V_85 = 0 ;
}
F_34 ( V_17 ) ;
F_47 ( V_2 ) ;
F_48 ( & V_17 -> V_30 , L_5 ) ;
}
static T_5
F_49 ( struct V_16 * V_17 , const struct V_87 * V_88 )
{
T_5 V_83 ;
unsigned long V_66 ;
struct V_1 * V_2 ;
V_2 = F_50 ( sizeof( struct V_1 ) , V_89 ) ;
if ( V_2 == NULL )
return - V_82 ;
V_83 = F_41 ( V_17 ) ;
if ( V_83 != 0 ) {
F_19 ( & V_17 -> V_30 , L_6 ) ;
goto V_90;
}
V_2 -> V_85 = F_51 ( V_17 , V_91 ) ;
if ( ! V_2 -> V_85 ) {
F_19 ( & V_17 -> V_30 , L_7 ) ;
V_83 = - V_92 ;
goto V_93;
}
V_2 -> V_86 = F_52 ( V_17 , V_91 ) ;
if ( ! F_53 ( V_2 -> V_85 , V_2 -> V_86 , L_8 ) ) {
F_19 ( & V_17 -> V_30 ,
L_9 ) ;
V_83 = - V_94 ;
goto V_95;
}
V_2 -> V_4 = F_54 ( V_2 -> V_85 , V_2 -> V_86 ) ;
if ( ! V_2 -> V_4 ) {
F_19 ( & V_17 -> V_30 , L_10 ) ;
V_83 = - V_82 ;
goto V_96;
}
V_2 -> V_62 = V_97 ;
V_2 -> V_47 = F_55 ( & V_2 -> V_62 , & V_17 -> V_30 ) ;
if ( F_56 ( V_2 -> V_47 ) ) {
V_83 = F_57 ( V_2 -> V_47 ) ;
goto V_98;
}
F_58 ( & V_2 -> V_67 ) ;
V_83 = F_59 ( V_17 -> V_35 , & F_22 , V_99 , V_100 , V_2 ) ;
if ( V_83 != 0 ) {
F_19 ( & V_17 -> V_30 , L_11 , V_17 -> V_35 ) ;
goto V_101;
}
V_2 -> V_35 = V_17 -> V_35 ;
V_2 -> V_17 = V_17 ;
F_60 ( V_17 , V_2 ) ;
F_27 ( & V_2 -> V_67 , V_66 ) ;
F_17 ( V_2 ) ;
F_3 ( V_63 , & V_2 -> V_4 -> V_60 ) ;
F_3 ( 1 , & V_2 -> V_4 -> V_102 ) ;
F_3 ( 0 , & V_2 -> V_4 -> V_103 ) ;
F_3 ( V_52 , & V_2 -> V_4 -> V_38 ) ;
F_1 ( V_2 ) ;
if ( strcmp ( V_104 . V_105 , L_12 ) != 0 ) {
if ( F_18 ( V_104 . V_105 , V_17 ) != 0 ) {
F_19 ( & V_17 -> V_30 ,
L_13
L_14
) ;
}
}
F_28 ( & V_2 -> V_67 , V_66 ) ;
return 0 ;
V_101:
F_43 ( V_2 -> V_47 ) ;
V_98:
F_45 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
V_96:
F_46 ( V_2 -> V_85 , V_2 -> V_86 ) ;
V_95:
V_2 -> V_85 = 0 ;
V_93:
F_34 ( V_17 ) ;
V_90:
F_47 ( V_2 ) ;
F_19 ( & V_17 -> V_30 , L_15 , V_83 ) ;
return V_83 ;
}
static void T_9 F_61 ( void )
{
F_62 ( & V_106 ) ;
}
static T_5 T_10 F_63 ( void )
{
T_5 V_83 ;
V_83 = F_64 ( & V_106 ) ;
return V_83 ;
}
