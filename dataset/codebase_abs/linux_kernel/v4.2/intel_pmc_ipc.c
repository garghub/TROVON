static inline void F_1 ( T_1 V_1 )
{
V_2 . V_1 = V_1 ;
if ( V_2 . V_3 ) {
F_2 ( & V_2 . V_4 ) ;
V_1 |= V_5 ;
}
F_3 ( V_1 , V_2 . V_6 + V_7 ) ;
}
static inline T_1 F_4 ( void )
{
return F_5 ( V_2 . V_6 + V_8 ) ;
}
static inline void F_6 ( T_1 V_9 , T_1 V_10 )
{
F_3 ( V_9 , V_2 . V_6 + V_11 + V_10 ) ;
}
static inline T_2 F_7 ( T_1 V_10 )
{
return F_8 ( V_2 . V_6 + V_12 + V_10 ) ;
}
static inline T_1 F_9 ( T_1 V_10 )
{
return F_5 ( V_2 . V_6 + V_12 + V_10 ) ;
}
static int F_10 ( void )
{
int V_13 ;
int V_14 = 0 ;
if ( V_2 . V_3 ) {
if ( 0 == F_11 (
& V_2 . V_4 , V_15 * V_16 ) )
V_14 = - V_17 ;
} else {
int V_18 = V_19 ;
while ( ( F_4 () & V_20 ) && -- V_18 )
F_12 ( 1 ) ;
if ( V_18 == 0 )
V_14 = - V_17 ;
}
V_13 = F_4 () ;
if ( V_14 == - V_17 ) {
F_13 ( V_2 . V_21 ,
L_1 ,
V_13 , V_2 . V_1 ) ;
return V_14 ;
}
if ( V_13 & V_22 ) {
int V_23 ;
V_14 = - V_24 ;
V_23 = ( V_13 >> V_25 ) & 0xFF ;
if ( V_23 < F_14 ( V_26 ) )
F_13 ( V_2 . V_21 ,
L_2 ,
V_26 [ V_23 ] , V_13 , V_2 . V_1 ) ;
else
F_13 ( V_2 . V_21 ,
L_3 ,
V_13 , V_2 . V_1 ) ;
if ( ( V_23 == V_27 ) || ( V_23 == V_28 ) )
V_14 = - V_29 ;
}
return V_14 ;
}
int F_15 ( int V_1 , int V_30 )
{
int V_14 ;
F_16 ( & V_31 ) ;
if ( V_2 . V_21 == NULL ) {
F_17 ( & V_31 ) ;
return - V_32 ;
}
F_1 ( V_30 << V_33 | V_1 ) ;
V_14 = F_10 () ;
F_17 ( & V_31 ) ;
return V_14 ;
}
int F_18 ( T_1 V_1 , T_1 V_30 , T_2 * V_34 , T_1 V_35 , T_1 * V_36 ,
T_1 V_37 , T_1 V_38 , T_1 V_39 )
{
T_1 V_40 [ 4 ] = { 0 } ;
int V_14 ;
int V_23 ;
if ( V_35 > V_41 || V_37 > V_41 / 4 )
return - V_42 ;
F_16 ( & V_31 ) ;
if ( V_2 . V_21 == NULL ) {
F_17 ( & V_31 ) ;
return - V_32 ;
}
memcpy ( V_40 , V_34 , V_35 ) ;
F_3 ( V_38 , V_2 . V_6 + V_43 ) ;
F_3 ( V_39 , V_2 . V_6 + V_44 ) ;
for ( V_23 = 0 ; V_23 < ( ( V_35 + 3 ) / 4 ) ; V_23 ++ )
F_6 ( V_40 [ V_23 ] , 4 * V_23 ) ;
F_1 ( ( V_35 << V_25 ) |
( V_30 << V_33 ) | V_1 ) ;
V_14 = F_10 () ;
if ( ! V_14 ) {
for ( V_23 = 0 ; V_23 < V_37 ; V_23 ++ )
* V_36 ++ = F_9 ( 4 * V_23 ) ;
}
F_17 ( & V_31 ) ;
return V_14 ;
}
int F_19 ( T_1 V_1 , T_1 V_30 , T_2 * V_34 , T_1 V_35 ,
T_1 * V_36 , T_1 V_37 )
{
return F_18 ( V_1 , V_30 , V_34 , V_35 , V_36 , V_37 , 0 , 0 ) ;
}
static T_3 F_20 ( int V_45 , void * V_46 )
{
int V_13 ;
if ( V_2 . V_3 ) {
V_13 = F_4 () ;
F_3 ( V_13 | V_47 , V_2 . V_6 + V_8 ) ;
}
F_21 ( & V_2 . V_4 ) ;
return V_48 ;
}
static int F_22 ( struct V_49 * V_50 , const struct V_51 * V_52 )
{
T_4 V_53 ;
int V_14 ;
int V_54 ;
V_2 . V_21 = & F_23 ( V_50 ) -> V_21 ;
V_2 . V_3 = V_55 ;
V_14 = F_24 ( V_50 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_25 ( V_50 , L_4 ) ;
if ( V_14 )
return V_14 ;
V_53 = F_26 ( V_50 , 0 ) ;
V_54 = F_27 ( V_50 , 0 ) ;
if ( ! V_53 || ! V_54 ) {
F_13 ( & V_50 -> V_21 , L_5 ) ;
return - V_56 ;
}
F_28 ( & V_2 . V_4 ) ;
if ( F_29 ( V_50 -> V_45 , F_20 , 0 , L_4 , & V_2 ) ) {
F_13 ( & V_50 -> V_21 , L_6 ) ;
return - V_57 ;
}
V_2 . V_6 = F_30 ( V_53 , V_54 ) ;
if ( ! V_2 . V_6 ) {
F_13 ( & V_50 -> V_21 , L_7 ) ;
F_31 ( V_50 -> V_45 , & V_2 ) ;
V_14 = - V_56 ;
}
return V_14 ;
}
static void F_32 ( struct V_49 * V_50 )
{
F_31 ( V_50 -> V_45 , & V_2 ) ;
F_33 ( V_50 ) ;
F_34 ( V_50 ) ;
F_35 ( V_2 . V_6 ) ;
V_2 . V_21 = NULL ;
}
static T_5 F_36 ( struct V_58 * V_21 ,
struct V_59 * V_60 ,
const char * V_61 , T_6 V_62 )
{
int V_63 ;
int V_1 ;
int V_14 ;
V_14 = sscanf ( V_61 , L_8 , & V_1 , & V_63 ) ;
if ( V_14 != 2 ) {
F_13 ( V_21 , L_9 ) ;
return - V_42 ;
}
V_14 = F_15 ( V_1 , V_63 ) ;
if ( V_14 ) {
F_13 ( V_21 , L_10 , V_1 , V_14 ) ;
return V_14 ;
}
return ( T_5 ) V_62 ;
}
static T_5 F_37 ( struct V_58 * V_21 ,
struct V_59 * V_60 ,
const char * V_61 , T_6 V_62 )
{
unsigned long V_64 ;
int V_63 ;
int V_14 ;
if ( F_38 ( V_61 , 0 , & V_64 ) )
return - V_42 ;
if ( V_64 )
V_63 = 1 ;
else
V_63 = 0 ;
V_14 = F_15 ( V_65 , V_63 ) ;
if ( V_14 ) {
F_13 ( V_21 , L_11 , V_63 , V_14 ) ;
return V_14 ;
}
return ( T_5 ) V_62 ;
}
static int F_39 ( void )
{
struct V_66 * V_50 ;
struct V_67 * V_68 ;
int V_14 ;
V_50 = F_40 ( V_69 , - 1 ) ;
if ( ! V_50 ) {
F_13 ( V_2 . V_21 , L_12 ) ;
return - V_56 ;
}
V_50 -> V_21 . V_70 = V_2 . V_21 ;
V_68 = V_71 ;
V_68 -> V_72 = V_2 . V_73 ;
V_68 -> V_74 = V_68 -> V_72 + V_2 . V_75 - 1 ;
V_68 = V_71 + V_76 ;
V_68 -> V_72 = V_2 . V_77 ;
V_68 -> V_74 = V_68 -> V_72 + V_2 . V_78 - 1 ;
V_14 = F_41 ( V_50 , V_71 ,
F_14 ( V_71 ) ) ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_13 ) ;
goto V_79;
}
V_14 = F_42 ( V_50 ) ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_14 ) ;
goto V_79;
}
V_2 . V_80 = V_50 ;
return 0 ;
V_79:
F_43 ( V_50 ) ;
return V_14 ;
}
static int F_44 ( void )
{
struct V_66 * V_50 ;
struct V_67 * V_68 ;
int V_14 ;
V_50 = F_40 ( V_81 , - 1 ) ;
if ( ! V_50 ) {
F_13 ( V_2 . V_21 , L_15 ) ;
return - V_56 ;
}
V_50 -> V_21 . V_70 = V_2 . V_21 ;
V_68 = V_82 + V_83 ;
V_68 -> V_72 = V_2 . V_84 + V_85 ;
V_68 -> V_74 = V_68 -> V_72 + V_86 - 1 ;
V_68 = V_82 + V_87 ;
V_68 -> V_72 = V_2 . V_84 + V_88 ;
V_68 -> V_74 = V_68 -> V_72 + V_89 - 1 ;
V_68 = V_82 + V_90 ;
V_68 -> V_72 = V_2 . V_91 ;
V_68 -> V_74 = V_68 -> V_72 + V_2 . V_92 - 1 ;
V_14 = F_41 ( V_50 , V_82 , F_14 ( V_82 ) ) ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_16 ) ;
goto V_79;
}
V_14 = F_45 ( V_50 , & V_93 ,
sizeof( struct V_94 ) ) ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_17 ) ;
goto V_79;
}
V_14 = F_42 ( V_50 ) ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_18 ) ;
goto V_79;
}
V_2 . V_95 = V_50 ;
return 0 ;
V_79:
F_43 ( V_50 ) ;
return V_14 ;
}
static int F_46 ( void )
{
int V_14 ;
V_14 = F_44 () ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_18 ) ;
return V_14 ;
}
V_14 = F_39 () ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_14 ) ;
F_47 ( V_2 . V_95 ) ;
}
return V_14 ;
}
static int F_48 ( struct V_66 * V_50 )
{
struct V_67 * V_68 ;
void T_7 * V_96 ;
int V_97 ;
V_68 = F_49 ( V_50 , V_98 ,
V_99 ) ;
if ( ! V_68 ) {
F_13 ( & V_50 -> V_21 , L_19 ) ;
return - V_100 ;
}
V_97 = F_50 ( V_68 ) ;
V_2 . V_84 = V_68 -> V_72 ;
V_2 . V_101 = V_97 ;
F_51 ( & V_50 -> V_21 , L_20 ,
( long long ) V_68 -> V_72 , ( int ) F_50 ( V_68 ) ) ;
V_68 = F_49 ( V_50 , V_102 ,
V_103 ) ;
if ( ! V_68 ) {
F_13 ( & V_50 -> V_21 , L_21 ) ;
return - V_100 ;
}
V_97 = F_50 ( V_68 ) ;
V_2 . V_73 = V_68 -> V_72 ;
V_2 . V_75 = V_97 ;
F_51 ( & V_50 -> V_21 , L_22 ,
( long long ) V_68 -> V_72 , ( int ) F_50 ( V_68 ) ) ;
V_68 = F_49 ( V_50 , V_102 ,
V_104 ) ;
if ( ! V_68 ) {
F_13 ( & V_50 -> V_21 , L_23 ) ;
return - V_100 ;
}
V_97 = F_50 ( V_68 ) ;
V_2 . V_77 = V_68 -> V_72 ;
V_2 . V_78 = V_97 ;
F_51 ( & V_50 -> V_21 , L_24 ,
( long long ) V_68 -> V_72 , ( int ) F_50 ( V_68 ) ) ;
V_68 = F_49 ( V_50 , V_102 ,
V_105 ) ;
if ( ! V_68 ) {
F_13 ( & V_50 -> V_21 , L_25 ) ;
return - V_100 ;
}
V_97 = V_106 ;
if ( ! F_52 ( V_68 -> V_72 , V_97 , V_50 -> V_107 ) ) {
F_13 ( & V_50 -> V_21 , L_26 ) ;
return - V_57 ;
}
V_96 = F_30 ( V_68 -> V_72 , V_97 ) ;
if ( ! V_96 ) {
F_13 ( & V_50 -> V_21 , L_27 ) ;
F_53 ( V_68 -> V_72 , V_97 ) ;
return - V_56 ;
}
V_2 . V_6 = V_96 ;
V_2 . V_91 = V_68 -> V_72 + V_97 ;
V_2 . V_92 = V_108 ;
F_51 ( & V_50 -> V_21 , L_28 ,
( long long ) V_68 -> V_72 , ( int ) F_50 ( V_68 ) ) ;
return 0 ;
}
static int F_54 ( struct V_66 * V_50 )
{
struct V_67 * V_68 ;
int V_14 ;
V_2 . V_21 = & V_50 -> V_21 ;
V_2 . V_3 = V_55 ;
F_28 ( & V_2 . V_4 ) ;
V_2 . V_45 = F_55 ( V_50 , 0 ) ;
if ( V_2 . V_45 < 0 ) {
F_13 ( & V_50 -> V_21 , L_29 ) ;
return - V_42 ;
}
V_14 = F_48 ( V_50 ) ;
if ( V_14 ) {
F_13 ( & V_50 -> V_21 , L_30 ) ;
return V_14 ;
}
V_14 = F_46 () ;
if ( V_14 ) {
F_13 ( & V_50 -> V_21 , L_31 ) ;
goto V_109;
}
if ( F_29 ( V_2 . V_45 , F_20 , 0 , L_4 , & V_2 ) ) {
F_13 ( & V_50 -> V_21 , L_6 ) ;
V_14 = - V_57 ;
goto V_110;
}
V_14 = F_56 ( & V_50 -> V_21 . V_111 , & V_112 ) ;
if ( V_14 ) {
F_13 ( & V_50 -> V_21 , L_32 ,
V_14 ) ;
goto V_113;
}
return 0 ;
V_113:
F_31 ( V_2 . V_45 , & V_2 ) ;
V_110:
F_47 ( V_2 . V_95 ) ;
F_47 ( V_2 . V_80 ) ;
V_109:
F_35 ( V_2 . V_6 ) ;
V_68 = F_49 ( V_50 , V_102 ,
V_105 ) ;
if ( V_68 )
F_53 ( V_68 -> V_72 , V_106 ) ;
return V_14 ;
}
static int F_57 ( struct V_66 * V_50 )
{
struct V_67 * V_68 ;
F_58 ( & V_50 -> V_21 . V_111 , & V_112 ) ;
F_31 ( V_2 . V_45 , & V_2 ) ;
F_47 ( V_2 . V_95 ) ;
F_47 ( V_2 . V_80 ) ;
F_35 ( V_2 . V_6 ) ;
V_68 = F_49 ( V_50 , V_102 ,
V_105 ) ;
if ( V_68 )
F_53 ( V_68 -> V_72 , V_106 ) ;
V_2 . V_21 = NULL ;
return 0 ;
}
static int T_8 F_59 ( void )
{
int V_14 ;
V_14 = F_60 ( & V_114 ) ;
if ( V_14 ) {
F_61 ( L_33 ) ;
return V_14 ;
}
V_14 = F_62 ( & V_115 ) ;
if ( V_14 ) {
F_61 ( L_34 ) ;
F_63 ( & V_114 ) ;
return V_14 ;
}
return V_14 ;
}
static void T_9 F_64 ( void )
{
F_65 ( & V_115 ) ;
F_63 ( & V_114 ) ;
}
