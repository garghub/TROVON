static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
T_1 V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 [ V_3 ] , V_4 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_7 [ 0 ] -> V_8 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
T_1 V_5 )
{
int V_6 ;
V_6 = F_5 ( V_2 -> V_7 [ V_3 ] , V_4 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_7 [ 0 ] -> V_8 , L_2 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 ,
T_1 * V_10 )
{
int V_6 ;
V_6 = F_7 ( & V_2 -> V_11 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_3 , & V_9 , 1 ) ;
if ( ! V_6 )
V_6 = F_4 ( V_2 , V_3 , V_10 , 1 ) ;
F_8 ( & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_12 , T_1 * V_13 , T_1 V_14 )
{
int V_6 ;
V_6 = F_7 ( & V_2 -> V_11 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_3 , & V_12 , 1 ) ;
if ( ! V_6 )
V_6 = F_4 ( V_2 , V_3 , V_13 , V_14 ) ;
F_8 ( & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_9 , T_1 V_15 , T_1 V_16 )
{
int V_6 = 0 ;
if ( F_11 ( V_15 ) ) {
T_1 V_17 [ 2 ] = { V_9 , 0 } ;
V_6 = F_7 ( & V_2 -> V_11 ) ;
if ( V_6 )
return V_6 ;
if ( V_15 == 0xFF )
V_17 [ 1 ] = V_16 ;
else {
T_1 V_18 ;
V_6 = F_1 ( V_2 , V_3 , & V_9 , 1 ) ;
if ( V_6 )
goto V_19;
V_6 = F_4 ( V_2 , V_3 , & V_18 , 1 ) ;
if ( V_6 )
goto V_19;
V_17 [ 1 ] = ( ( ~ V_15 & V_18 ) |
( V_15 & V_16 ) ) ;
}
V_6 = F_1 ( V_2 , V_3 , V_17 , 2 ) ;
V_19:
F_8 ( & V_2 -> V_11 ) ;
}
return V_6 ;
}
static bool F_12 ( const struct V_20 * V_21 ,
T_1 V_12 , T_1 V_22 )
{
T_1 V_23 ;
if ( V_22 < V_12 )
return false ;
for ( V_23 = 0 ; V_23 < V_21 -> V_5 ; V_23 ++ ) {
if ( V_12 < V_21 -> V_24 [ V_23 ] . V_25 )
break;
if ( ( V_22 <= V_21 -> V_24 [ V_23 ] . V_26 ) &&
( V_21 -> V_24 [ V_23 ] . V_27 & V_28 ) )
return true ;
}
return false ;
}
static bool F_13 ( const struct V_20 * V_21 , T_1 V_9 )
{
return F_12 ( V_21 , V_9 , V_9 ) ;
}
static bool F_14 ( const struct V_20 * V_21 ,
T_1 V_12 , T_1 V_22 )
{
T_1 V_23 ;
if ( V_22 < V_12 )
return false ;
for ( V_23 = 0 ; V_23 < V_21 -> V_5 ; V_23 ++ ) {
if ( V_12 < V_21 -> V_24 [ V_23 ] . V_25 )
return false ;
if ( V_12 <= V_21 -> V_24 [ V_23 ] . V_26 )
break;
}
while ( ( V_23 < V_21 -> V_5 ) &&
( V_21 -> V_24 [ V_23 ] . V_27 & V_29 ) ) {
if ( V_22 <= V_21 -> V_24 [ V_23 ] . V_26 )
return true ;
if ( ( ++ V_23 >= V_21 -> V_5 ) ||
( V_21 -> V_24 [ V_23 ] . V_25 !=
( V_21 -> V_24 [ V_23 - 1 ] . V_26 + 1 ) ) ) {
break;
}
}
return false ;
}
static bool F_15 ( const struct V_20 * V_21 , T_1 V_9 )
{
return F_14 ( V_21 , V_9 , V_9 ) ;
}
static int F_16 ( struct V_30 * V_8 )
{
struct V_1 * V_2 = F_17 ( V_8 -> V_31 ) ;
return ( int ) V_2 -> V_32 ;
}
static int F_18 ( struct V_30 * V_8 ,
T_1 V_3 , T_1 V_9 , T_1 V_15 , T_1 V_16 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = F_19 ( V_8 ) ;
if ( ( V_35 <= V_3 ) ||
! F_13 ( & V_20 [ V_34 -> V_36 ] [ V_3 ] , V_9 ) )
return - V_37 ;
V_2 = F_17 ( V_8 -> V_31 ) ;
return F_10 ( V_2 , V_3 , V_9 ,
V_15 , V_16 ) ;
}
static int F_20 ( struct V_30 * V_8 , T_1 V_3 ,
T_1 V_9 , T_1 V_10 )
{
return F_18 ( V_8 , V_3 , V_9 , 0xFF ,
V_10 ) ;
}
static int F_21 ( struct V_30 * V_8 , T_1 V_3 ,
T_1 V_9 , T_1 * V_10 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = F_19 ( V_8 ) ;
if ( ( V_35 <= V_3 ) ||
! F_15 ( & V_20 [ V_34 -> V_36 ] [ V_3 ] , V_9 ) )
return - V_37 ;
V_2 = F_17 ( V_8 -> V_31 ) ;
return F_6 ( V_2 , V_3 , V_9 , V_10 ) ;
}
static int F_22 ( struct V_30 * V_8 , T_1 V_3 ,
T_1 V_12 , T_1 * V_13 , T_1 V_14 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = F_19 ( V_8 ) ;
if ( ( V_35 <= V_3 ) ||
! F_14 ( & V_20 [ V_34 -> V_36 ] [ V_3 ] ,
V_12 , ( V_12 + V_14 - 1 ) ) )
return - V_37 ;
V_2 = F_17 ( V_8 -> V_31 ) ;
return F_9 ( V_2 , V_3 , V_12 , V_13 ,
V_14 ) ;
}
static int F_23 ( struct V_30 * V_8 ,
T_1 * V_38 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_8 -> V_31 ) ;
if ( ! V_2 -> V_39 )
return - V_40 ;
memcpy ( V_38 , V_2 -> V_41 , V_42 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_8 , unsigned int V_43 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
bool V_46 ;
V_2 = F_25 ( V_43 ) ;
V_45 = V_2 -> V_7 [ 0 ] -> V_8 . V_47 ;
V_43 -= V_45 -> V_43 . V_48 ;
V_46 = ( ( V_2 -> V_41 [ V_43 / 8 ] & F_26 ( V_43 % 8 ) ) != 0 ) ;
return V_46 ;
}
static T_2 F_27 ( int V_43 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
int V_6 ;
unsigned int V_23 ;
T_1 V_49 [ V_42 ] ;
T_1 * V_50 ;
unsigned long V_51 ;
V_50 = ( V_2 -> V_39 ? V_49 : V_2 -> V_41 ) ;
V_6 = F_9 ( V_2 , V_52 ,
V_53 , V_50 , V_42 ) ;
if ( V_6 )
goto V_54;
if ( ! V_2 -> V_39 ) {
F_28 ( & V_2 -> V_7 [ 0 ] -> V_8 ,
L_3 ,
V_2 -> V_41 [ 0 ] , V_2 -> V_41 [ 1 ] ,
V_2 -> V_41 [ 2 ] , V_2 -> V_41 [ 3 ] ,
V_2 -> V_41 [ 4 ] ) ;
V_2 -> V_39 = true ;
goto V_55;
}
V_50 [ 4 ] &= 0x3f ;
F_29 ( & V_2 -> V_56 , V_51 ) ;
for ( V_23 = 0 ; V_23 < V_42 ; V_23 ++ )
V_50 [ V_23 ] &= ~ V_2 -> V_57 [ V_23 ] ;
F_30 ( & V_2 -> V_56 , V_51 ) ;
for ( V_23 = 0 ; V_23 < V_42 ; V_23 ++ ) {
T_1 V_58 ;
T_1 V_59 ;
F_31 ( & V_2 -> V_7 [ 0 ] -> V_8 , L_4 ,
V_23 , V_50 [ V_23 ] ) ;
V_59 = V_50 [ V_23 ] ;
for ( V_58 = 0 ; V_59 ; V_58 ++ , V_59 /= 2 ) {
if ( V_59 % 2 ) {
unsigned int V_43 ;
struct V_44 * V_45 ;
V_45 = V_2 -> V_7 [ 0 ] -> V_8 . V_47 ;
V_43 = V_45 -> V_43 . V_48 + ( V_23 * 8 ) + V_58 ;
F_32 ( V_43 ) ;
}
}
}
V_55:
return V_60 ;
V_54:
F_31 ( & V_2 -> V_7 [ 0 ] -> V_8 , L_5 ) ;
return V_60 ;
}
static int F_33 ( struct V_61 * V_62 , void * V_63 )
{
struct V_1 * V_2 = V_62 -> V_64 ;
int V_3 ;
F_34 ( V_62 , V_65 L_6 ) ;
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ ) {
unsigned int V_23 ;
F_34 ( V_62 , L_7 , V_3 ) ;
for ( V_23 = 0 ; V_23 < V_66 [ V_3 ] . V_5 ; V_23 ++ ) {
T_1 V_9 ;
for ( V_9 = V_66 [ V_3 ] . V_24 [ V_23 ] . V_25 ;
V_9 <= V_66 [ V_3 ] . V_24 [ V_23 ] . V_26 ;
V_9 ++ ) {
T_1 V_10 ;
F_6 ( V_2 , V_3 , V_9 ,
& V_10 ) ;
F_34 ( V_62 , L_8 , V_3 ,
V_9 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_35 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_36 ( V_68 , F_33 , V_67 -> V_69 ) ;
}
static int F_37 ( struct V_61 * V_62 , void * V_63 )
{
struct V_1 * V_2 = V_62 -> V_64 ;
F_34 ( V_62 , L_9 , V_2 -> V_70 ) ;
return 0 ;
}
static int F_38 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_36 ( V_68 , F_37 , V_67 -> V_69 ) ;
}
static T_3 F_39 ( struct V_68 * V_68 ,
const char T_4 * V_71 ,
T_5 V_5 , T_6 * V_72 )
{
struct V_1 * V_2 = ( (struct V_61 * ) ( V_68 -> V_73 ) ) -> V_64 ;
unsigned long V_74 ;
int V_6 ;
V_6 = F_40 ( V_71 , V_5 , 0 , & V_74 ) ;
if ( V_6 )
return V_6 ;
if ( V_74 >= V_35 ) {
F_3 ( & V_2 -> V_7 [ 0 ] -> V_8 ,
L_10 ) ;
return - V_37 ;
}
V_2 -> V_70 = V_74 ;
return V_5 ;
}
static int F_41 ( struct V_61 * V_62 , void * V_63 )
{
struct V_1 * V_2 = V_62 -> V_64 ;
F_34 ( V_62 , L_11 , V_2 -> V_75 ) ;
return 0 ;
}
static int F_42 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_36 ( V_68 , F_41 , V_67 -> V_69 ) ;
}
static T_3 F_43 ( struct V_68 * V_68 ,
const char T_4 * V_71 ,
T_5 V_5 , T_6 * V_72 )
{
struct V_1 * V_2 = ( (struct V_61 * ) ( V_68 -> V_73 ) ) -> V_64 ;
unsigned long V_76 ;
int V_6 ;
V_6 = F_40 ( V_71 , V_5 , 0 , & V_76 ) ;
if ( V_6 )
return V_6 ;
if ( V_76 > 0xff ) {
F_3 ( & V_2 -> V_7 [ 0 ] -> V_8 ,
L_12 ) ;
return - V_37 ;
}
V_2 -> V_75 = V_76 ;
return V_5 ;
}
static int F_44 ( struct V_61 * V_62 , void * V_63 )
{
struct V_1 * V_2 = V_62 -> V_64 ;
int V_6 ;
T_1 V_77 ;
V_6 = F_6 ( V_2 , ( T_1 ) V_2 -> V_70 ,
( T_1 ) V_2 -> V_75 , & V_77 ) ;
if ( V_6 )
return - V_37 ;
F_34 ( V_62 , L_11 , V_77 ) ;
return 0 ;
}
static int F_45 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_36 ( V_68 , F_44 , V_67 -> V_69 ) ;
}
static T_3 F_46 ( struct V_68 * V_68 ,
const char T_4 * V_71 ,
T_5 V_5 , T_6 * V_72 )
{
struct V_1 * V_2 = ( (struct V_61 * ) ( V_68 -> V_73 ) ) -> V_64 ;
unsigned long V_78 ;
int V_6 ;
T_1 V_77 ;
V_6 = F_40 ( V_71 , V_5 , 0 , & V_78 ) ;
if ( V_6 )
return V_6 ;
if ( V_78 > 0xff ) {
F_3 ( & V_2 -> V_7 [ 0 ] -> V_8 ,
L_12 ) ;
return - V_37 ;
}
V_6 = F_10 (
V_2 , ( T_1 ) V_2 -> V_70 ,
( T_1 ) V_2 -> V_75 , 0xFF , ( T_1 ) V_78 ) ;
if ( V_6 )
return - V_37 ;
F_6 ( V_2 , ( T_1 ) V_2 -> V_70 ,
( T_1 ) V_2 -> V_75 , & V_77 ) ;
if ( V_6 )
return - V_37 ;
return V_5 ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_70 = 0 ;
V_2 -> V_75 = 0x00 ;
V_79 = F_48 ( V_65 , NULL ) ;
if ( ! V_79 )
goto V_80;
V_81 = F_49 ( L_13 ,
V_82 , V_79 , V_2 , & V_83 ) ;
if ( ! V_81 )
goto V_84;
V_85 = F_49 ( L_14 ,
( V_82 | V_86 ) , V_79 , V_2 , & V_87 ) ;
if ( ! V_85 )
goto V_88;
V_89 = F_49 ( L_15 ,
( V_82 | V_86 ) , V_79 , V_2 , & V_90 ) ;
if ( ! V_89 )
goto V_91;
V_92 = F_49 ( L_16 ,
( V_82 | V_86 ) , V_79 , V_2 , & V_93 ) ;
if ( ! V_92 )
goto V_94;
return;
V_94:
F_50 ( V_89 ) ;
V_91:
F_50 ( V_85 ) ;
V_88:
F_50 ( V_81 ) ;
V_84:
F_50 ( V_79 ) ;
V_80:
F_3 ( & V_2 -> V_7 [ 0 ] -> V_8 , L_17 ) ;
return;
}
static inline void F_51 ( void )
{
F_50 ( V_92 ) ;
F_50 ( V_89 ) ;
F_50 ( V_85 ) ;
F_50 ( V_81 ) ;
F_50 ( V_79 ) ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
}
static inline void F_51 ( void )
{
}
static int T_7 F_52 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
int V_23 ;
struct V_44 * V_45 ;
struct V_95 * V_96 ;
V_45 = V_2 -> V_7 [ 0 ] -> V_8 . V_47 ;
V_96 = V_45 -> V_97 ;
for ( V_23 = 0 ; V_23 < V_45 -> V_98 ; V_23 ++ ) {
V_6 = F_10 ( V_2 ,
V_96 [ V_23 ] . V_3 ,
V_96 [ V_23 ] . V_9 ,
0xFF , V_96 [ V_23 ] . V_99 ) ;
if ( V_6 )
goto V_100;
if ( ( V_96 [ V_23 ] . V_3 == 0 ) &&
( V_101 <= V_96 [ V_23 ] . V_9 ) &&
( V_96 [ V_23 ] . V_9 <= V_102 ) ) {
V_2 -> V_57 [ V_96 [ V_23 ] . V_9 - V_101 ] =
V_96 [ V_23 ] . V_99 ;
}
}
V_100:
return V_6 ;
}
static void F_53 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = F_54 ( V_104 , struct V_1 , V_105 ) ;
int V_23 ;
unsigned long V_51 ;
T_1 V_106 [ V_42 ] ;
F_29 ( & V_2 -> V_56 , V_51 ) ;
for ( V_23 = 0 ; V_23 < V_42 ; V_23 ++ )
V_106 [ V_23 ] = V_2 -> V_57 [ V_23 ] ;
F_30 ( & V_2 -> V_56 , V_51 ) ;
for ( V_23 = 0 ; V_23 < V_42 ; V_23 ++ ) {
int V_6 ;
V_6 = F_10 ( V_2 , 0 ,
( V_101 + V_23 ) , ~ 0 , V_106 [ V_23 ] ) ;
if ( V_6 )
F_3 ( & V_2 -> V_7 [ 0 ] -> V_8 ,
L_18 ,
( V_101 + V_23 ) , V_106 [ V_23 ] ) ;
}
}
static void F_55 ( struct V_107 * V_4 )
{
unsigned long V_51 ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_43 ;
V_2 = F_56 ( V_4 ) ;
V_45 = V_2 -> V_7 [ 0 ] -> V_8 . V_47 ;
V_43 = V_4 -> V_43 - V_45 -> V_43 . V_48 ;
F_29 ( & V_2 -> V_56 , V_51 ) ;
V_2 -> V_57 [ V_43 / 8 ] |= F_26 ( V_43 % 8 ) ;
F_30 ( & V_2 -> V_56 , V_51 ) ;
F_57 ( & V_2 -> V_105 ) ;
}
static void F_58 ( struct V_107 * V_4 )
{
unsigned long V_51 ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_43 ;
V_2 = F_56 ( V_4 ) ;
V_45 = V_2 -> V_7 [ 0 ] -> V_8 . V_47 ;
V_43 = V_4 -> V_43 - V_45 -> V_43 . V_48 ;
F_29 ( & V_2 -> V_56 , V_51 ) ;
V_2 -> V_57 [ V_43 / 8 ] &= ~ F_26 ( V_43 % 8 ) ;
F_30 ( & V_2 -> V_56 , V_51 ) ;
F_57 ( & V_2 -> V_105 ) ;
}
static void F_59 ( struct V_107 * V_4 )
{
}
static int T_7 F_60 ( struct V_7 * V_108 ,
const struct V_109 * V_36 )
{
struct V_1 * V_2 ;
struct V_44 * V_110 =
V_108 -> V_8 . V_47 ;
int V_6 ;
int V_23 ;
int V_111 = 0 ;
V_2 = F_61 ( sizeof( struct V_1 ) , V_112 ) ;
if ( ! V_2 ) {
F_3 ( & V_108 -> V_8 ,
L_19 V_65 L_20 ) ;
return - V_113 ;
}
F_62 ( & V_2 -> V_11 ) ;
F_63 ( & V_2 -> V_56 ) ;
V_2 -> V_7 [ 0 ] = V_108 ;
F_64 ( V_108 , V_2 ) ;
V_6 = F_6 ( V_2 , 0 , V_114 , & V_2 -> V_32 ) ;
if ( V_6 ) {
F_3 ( & V_108 -> V_8 , L_21
L_22 ) ;
goto V_115;
}
for ( V_23 = 0 ; V_116 [ V_23 ] . V_36 != 0x0 ; V_23 ++ ) {
if ( V_116 [ V_23 ] . V_36 == V_2 -> V_32 ) {
snprintf ( & V_2 -> V_117 [ 0 ] , sizeof( V_2 -> V_117 ) - 1 ,
V_118 , V_116 [ V_23 ] . V_119 ) ;
break;
}
}
if ( V_116 [ V_23 ] . V_36 == 0x0 ) {
F_3 ( & V_108 -> V_8 , L_23 ,
V_2 -> V_32 ) ;
F_3 ( & V_108 -> V_8 , L_24 ) ;
goto V_115;
}
F_28 ( & V_108 -> V_8 , L_25 , & V_2 -> V_117 [ 0 ] ) ;
while ( ++ V_111 < V_35 ) {
V_2 -> V_7 [ V_111 ] =
F_65 ( V_108 -> V_120 ,
( V_108 -> V_121 + V_111 ) ) ;
if ( ! V_2 -> V_7 [ V_111 ] ) {
V_6 = - V_113 ;
goto V_122;
}
F_66 ( V_2 -> V_7 [ V_111 ] -> V_119 , V_36 -> V_119 ,
sizeof( V_2 -> V_7 [ V_111 ] -> V_119 ) ) ;
}
V_6 = F_52 ( V_2 ) ;
if ( V_6 )
goto V_100;
F_67 ( & V_2 -> V_105 , F_53 ) ;
for ( V_23 = 0 ; V_23 < V_110 -> V_43 . V_5 ; V_23 ++ ) {
unsigned int V_43 ;
V_43 = V_110 -> V_43 . V_48 + V_23 ;
F_68 ( V_43 , V_2 ) ;
F_69 ( V_43 , & V_123 ,
V_124 ) ;
F_70 ( V_43 , 1 ) ;
#ifdef F_71
F_72 ( V_43 , V_125 ) ;
#else
F_73 ( V_43 ) ;
#endif
}
V_6 = F_74 ( V_108 -> V_43 , NULL , F_27 ,
V_126 , L_26 , V_2 ) ;
F_75 ( V_108 -> V_43 ) ;
if ( V_6 )
goto V_127;
V_6 = F_76 ( & V_108 -> V_8 , & V_128 ) ;
if ( V_6 )
goto V_129;
for ( V_23 = 0 ; V_23 < V_130 ; V_23 ++ ) {
V_131 [ V_23 ] . V_47 = V_110 -> V_132 [ V_23 ] ;
V_131 [ V_23 ] . V_133 = V_110 -> V_134 [ V_23 ] ;
}
V_6 = F_77 ( & V_108 -> V_8 , 0 , V_131 ,
F_78 ( V_131 ) , NULL ,
V_110 -> V_43 . V_48 ) ;
F_47 ( V_2 ) ;
return 0 ;
V_129:
V_127:
V_100:
V_122:
while ( -- V_111 )
F_79 ( V_2 -> V_7 [ V_111 ] ) ;
V_115:
F_80 ( V_2 ) ;
return V_6 ;
}
static int T_8 F_81 ( struct V_7 * V_108 )
{
struct V_1 * V_2 = F_82 ( V_108 ) ;
int V_111 = V_35 ;
F_83 ( & V_108 -> V_8 ) ;
F_51 () ;
while ( -- V_111 )
F_79 ( V_2 -> V_7 [ V_111 ] ) ;
F_84 ( V_108 -> V_43 , V_2 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static int T_7 F_85 ( void )
{
return F_86 ( & V_135 ) ;
}
static void T_8 F_87 ( void )
{
F_88 ( & V_135 ) ;
}
