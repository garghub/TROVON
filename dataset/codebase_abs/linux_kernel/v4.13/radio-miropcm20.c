static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 2000 ;
do {
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 -- ;
} while ( ( V_3 & V_7 ) && V_4 );
F_3 ( 1 ) ;
return V_4 ? V_3 : - 1 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( F_1 ( V_2 ) >= 0 ) {
F_5 ( V_3 , V_2 -> V_5 + V_6 ) ;
return 0 ;
}
return - 1 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_8 [ 8 ] ;
int V_4 ;
for ( V_4 = 7 ; V_4 >= 0 ; V_4 -- )
V_8 [ 7 - V_4 ] = ( V_3 & ( 1 << V_4 ) ) ? V_9 : 0 ;
V_8 [ 0 ] |= V_10 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ )
F_4 ( V_2 , V_8 [ V_4 ] ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_5 ( 0 , V_2 -> V_5 + V_6 ) ;
return F_1 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 , 0 ) < 0 )
return - 1 ;
return F_1 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_4 = F_8 ( V_2 ) ;
if ( V_4 < 0 )
return - 1 ;
if ( V_4 & V_9 )
return 0 ;
return 1 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 [] , T_1 V_13 )
{
int V_4 , V_14 ;
F_6 ( V_2 , V_11 ) ;
if ( V_11 == V_15 )
return 0 ;
if ( F_9 ( V_2 ) )
return - V_16 ;
if ( V_13 == 0 )
return 0 ;
if ( F_1 ( V_2 ) < 0 )
return - 1 ;
memset ( V_12 , 0 , V_13 ) ;
for ( V_4 = 0 ; V_4 < 8 * V_13 ; V_4 ++ ) {
V_14 = F_7 ( V_2 ) ;
if ( V_14 < 0 )
return - V_16 ;
V_12 [ V_4 / 8 ] |= F_11 ( V_14 ) << ( 7 - ( V_4 % 8 ) ) ;
}
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , unsigned long V_19 )
{
unsigned char V_20 ;
unsigned char V_21 ;
struct V_1 * V_2 = V_18 -> V_2 ;
V_19 /= 160 ;
if ( ! ( V_2 -> V_22 == 0x07 || V_2 -> V_22 >= 0xb0 ) )
V_19 /= 10 ;
V_20 = V_19 & 0xff ;
V_21 = V_19 >> 8 ;
F_10 ( V_2 , V_15 , NULL , 0 ) ;
return F_13 ( V_2 , V_23 , V_20 , V_21 ) ;
}
static int F_14 ( struct V_24 * V_24 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_17 * V_18 = F_15 ( V_24 ) ;
F_16 ( V_27 -> V_28 , L_1 , sizeof( V_27 -> V_28 ) ) ;
F_16 ( V_27 -> V_29 , L_1 , sizeof( V_27 -> V_29 ) ) ;
snprintf ( V_27 -> V_30 , sizeof( V_27 -> V_30 ) , L_2 , V_18 -> V_31 . V_32 ) ;
V_27 -> V_33 = V_34 | V_35 | V_36 ;
V_27 -> V_37 = V_27 -> V_33 | V_38 ;
return 0 ;
}
static bool F_17 ( char * V_39 , int V_40 )
{
int V_4 ;
bool V_41 = true ;
for ( V_4 = 0 ; V_4 < V_40 ; V_4 ++ ) {
if ( V_39 [ V_4 ] < 32 ) {
V_39 [ V_4 ] = ' ' ;
V_41 = false ;
}
}
return V_41 ;
}
static int F_18 ( struct V_24 * V_24 , void * V_25 ,
struct V_42 * V_27 )
{
struct V_17 * V_18 = F_15 ( V_24 ) ;
int V_43 ;
T_1 V_44 ;
if ( V_27 -> V_45 )
return - V_46 ;
F_16 ( V_27 -> V_32 , L_3 , sizeof( V_27 -> V_32 ) ) ;
V_27 -> type = V_47 ;
V_27 -> V_48 = 87 * 16000 ;
V_27 -> V_49 = 108 * 16000 ;
V_43 = F_13 ( V_18 -> V_2 , V_50 , - 1 , - 1 ) ;
V_27 -> signal = ( V_43 & 0x80 ) ? 0 : 0xffff ;
V_43 = F_13 ( V_18 -> V_2 , V_51 , - 1 , - 1 ) ;
V_27 -> V_52 = ( V_43 & 0x40 ) ? V_53 :
V_54 ;
V_27 -> V_55 = V_56 | V_57 |
V_58 | V_59 ;
V_27 -> V_60 = V_18 -> V_60 ;
V_43 = F_10 ( V_18 -> V_2 , V_61 , & V_44 , 1 ) ;
if ( V_43 >= 0 && V_44 )
V_27 -> V_52 |= V_62 ;
return 0 ;
}
static int F_19 ( struct V_24 * V_24 , void * V_25 ,
const struct V_42 * V_27 )
{
struct V_17 * V_18 = F_15 ( V_24 ) ;
if ( V_27 -> V_45 )
return - V_46 ;
if ( V_27 -> V_60 > V_63 )
V_18 -> V_60 = V_63 ;
else
V_18 -> V_60 = V_27 -> V_60 ;
F_13 ( V_18 -> V_2 , V_64 ,
V_18 -> V_60 == V_65 , - 1 ) ;
return 0 ;
}
static int F_20 ( struct V_24 * V_24 , void * V_25 ,
struct V_66 * V_67 )
{
struct V_17 * V_18 = F_15 ( V_24 ) ;
if ( V_67 -> V_68 != 0 )
return - V_46 ;
V_67 -> type = V_47 ;
V_67 -> V_69 = V_18 -> V_19 ;
return 0 ;
}
static int F_21 ( struct V_24 * V_24 , void * V_25 ,
const struct V_66 * V_67 )
{
struct V_17 * V_18 = F_15 ( V_24 ) ;
if ( V_67 -> V_68 != 0 || V_67 -> type != V_47 )
return - V_46 ;
V_18 -> V_19 = F_22 ( V_70 , V_67 -> V_69 , 87 * 16000U , 108 * 16000U ) ;
F_12 ( V_18 , V_18 -> V_19 ) ;
return 0 ;
}
static int F_23 ( struct V_71 * V_72 )
{
struct V_17 * V_18 = F_24 ( V_72 -> V_73 , struct V_17 , V_74 ) ;
switch ( V_72 -> V_75 ) {
case V_76 :
F_13 ( V_18 -> V_2 , V_77 , V_72 -> V_78 , - 1 ) ;
return 0 ;
}
return - V_46 ;
}
static int F_25 ( void * V_79 )
{
struct V_17 * V_18 = V_79 ;
const unsigned V_80 = 5 ;
const unsigned V_81 = 2000 ;
unsigned V_82 = V_80 ;
for (; ; ) {
char V_83 [ 66 ] ;
T_1 V_44 ;
int V_43 ;
F_26 ( V_81 ) ;
if ( F_27 () )
break;
V_43 = F_10 ( V_18 -> V_2 , V_61 , & V_44 , 1 ) ;
if ( V_43 )
continue;
if ( V_44 == 0 ) {
if ( V_82 == 0 )
continue;
V_82 -- ;
if ( V_82 )
continue;
F_28 ( V_18 -> V_84 , L_4 ) ;
F_29 ( V_18 -> V_85 , 1 ) ;
F_29 ( V_18 -> V_86 , 0 ) ;
F_29 ( V_18 -> V_87 , 0 ) ;
F_29 ( V_18 -> V_88 , 0 ) ;
F_28 ( V_18 -> V_89 , L_4 ) ;
continue;
}
V_82 = V_80 ;
V_43 = F_10 ( V_18 -> V_2 , V_90 , & V_44 , 1 ) ;
if ( V_43 )
continue;
if ( ( V_44 >> 3 ) & 1 ) {
V_43 = F_10 ( V_18 -> V_2 , V_91 , V_83 , 8 ) ;
V_83 [ 8 ] = 0 ;
if ( ! V_43 && F_17 ( V_83 , 8 ) )
F_28 ( V_18 -> V_84 , V_83 ) ;
}
if ( ( V_44 >> 6 ) & 1 ) {
T_1 V_92 ;
V_43 = F_10 ( V_18 -> V_2 , V_93 , & V_92 , 1 ) ;
if ( ! V_43 ) {
F_29 ( V_18 -> V_85 , ! ! ( V_92 & 0x01 ) ) ;
F_29 ( V_18 -> V_86 , ! ! ( V_92 & 0x02 ) ) ;
F_29 ( V_18 -> V_87 , ! ! ( V_92 & 0x80 ) ) ;
F_29 ( V_18 -> V_88 , ( V_92 >> 2 ) & 0x1f ) ;
}
}
if ( ( V_44 >> 4 ) & 1 ) {
V_43 = F_10 ( V_18 -> V_2 , V_94 , V_83 , 65 ) ;
V_83 [ 65 ] = 0 ;
if ( ! V_43 && F_17 ( V_83 + 1 , 64 ) )
F_28 ( V_18 -> V_89 , V_83 + 1 ) ;
}
}
return 0 ;
}
static int F_30 ( struct V_24 * V_24 )
{
struct V_17 * V_18 = F_15 ( V_24 ) ;
int V_43 = F_31 ( V_24 ) ;
if ( ! V_43 && F_32 ( V_24 ) &&
F_33 ( V_18 -> V_95 ) ) {
V_18 -> V_95 = F_34 ( F_25 , V_18 , L_5 ,
V_18 -> V_31 . V_32 ) ;
if ( F_35 ( V_18 -> V_95 ) ) {
F_36 ( & V_18 -> V_31 , L_6 ) ;
F_37 ( V_24 ) ;
return F_38 ( V_18 -> V_95 ) ;
}
}
return V_43 ;
}
static int F_39 ( struct V_24 * V_24 )
{
struct V_17 * V_18 = F_15 ( V_24 ) ;
if ( F_32 ( V_24 ) && ! F_33 ( V_18 -> V_95 ) ) {
F_40 ( V_18 -> V_95 ) ;
V_18 -> V_95 = NULL ;
}
return F_37 ( V_24 ) ;
}
static int T_2 F_41 ( void )
{
struct V_17 * V_18 = & V_96 ;
struct V_97 * V_31 = & V_18 -> V_31 ;
struct V_98 * V_99 ;
int V_43 ;
V_18 -> V_2 = F_42 () ;
if ( V_18 -> V_2 == NULL ) {
F_36 ( V_31 ,
L_7 ) ;
return - V_100 ;
}
F_16 ( V_31 -> V_32 , L_8 , sizeof( V_31 -> V_32 ) ) ;
F_43 ( & V_18 -> V_101 ) ;
V_43 = F_44 ( NULL , V_31 ) ;
if ( V_43 < 0 ) {
F_36 ( V_31 , L_9 ) ;
return - V_46 ;
}
V_99 = & V_18 -> V_74 ;
F_45 ( V_99 , 7 ) ;
F_46 ( V_99 , & V_102 ,
V_76 , 0 , 1 , 1 , 1 ) ;
V_18 -> V_88 = F_46 ( V_99 , NULL ,
V_103 , 0 , 0x1f , 1 , 0 ) ;
V_18 -> V_84 = F_46 ( V_99 , NULL ,
V_104 , 0 , 8 , 8 , 0 ) ;
V_18 -> V_89 = F_46 ( V_99 , NULL ,
V_105 , 0 , 64 , 64 , 0 ) ;
V_18 -> V_86 = F_46 ( V_99 , NULL ,
V_106 , 0 , 1 , 1 , 0 ) ;
V_18 -> V_87 = F_46 ( V_99 , NULL ,
V_107 , 0 , 1 , 1 , 0 ) ;
V_18 -> V_85 = F_46 ( V_99 , NULL ,
V_108 , 0 , 1 , 1 , 1 ) ;
V_31 -> V_74 = V_99 ;
if ( V_99 -> error ) {
V_43 = V_99 -> error ;
F_36 ( V_31 , L_10 ) ;
goto V_109;
}
F_16 ( V_18 -> V_110 . V_32 , V_31 -> V_32 , sizeof( V_18 -> V_110 . V_32 ) ) ;
V_18 -> V_110 . V_31 = V_31 ;
V_18 -> V_110 . V_111 = & V_112 ;
V_18 -> V_110 . V_113 = & V_114 ;
V_18 -> V_110 . V_115 = V_116 ;
V_18 -> V_110 . V_101 = & V_18 -> V_101 ;
F_47 ( & V_18 -> V_110 , V_18 ) ;
F_13 ( V_18 -> V_2 , V_64 ,
V_18 -> V_60 == V_65 , - 1 ) ;
F_12 ( V_18 , V_18 -> V_19 ) ;
if ( F_48 ( & V_18 -> V_110 , V_117 , V_118 ) < 0 )
goto V_109;
F_49 ( V_31 , L_11 ) ;
return 0 ;
V_109:
F_50 ( V_99 ) ;
F_51 ( V_31 ) ;
return - V_46 ;
}
static void T_3 F_52 ( void )
{
struct V_17 * V_18 = & V_96 ;
F_53 ( & V_18 -> V_110 ) ;
F_13 ( V_18 -> V_2 , V_77 , 1 , - 1 ) ;
F_50 ( & V_18 -> V_74 ) ;
F_51 ( & V_18 -> V_31 ) ;
}
