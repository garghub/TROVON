static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 | V_5 ;
return F_2 ( V_2 -> V_6 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_6 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_5 ( & V_8 -> V_9 ,
F_6 ( V_10 / V_8 -> V_11 ) ) ;
}
static void F_7 ( struct V_12 * V_9 )
{
struct V_7 * V_8 =
F_8 ( V_9 , struct V_7 , V_9 . V_9 ) ;
struct V_1 * V_2 =
F_8 ( V_8 , struct V_1 , V_8 ) ;
T_1 * V_13 , * V_14 ;
int V_15 , V_16 = 0 , V_17 = - 1 ;
V_13 = V_8 -> V_18 ;
V_14 = V_8 -> V_19 ;
while ( V_16 < V_20 && V_17 < 0 ) {
if ( * ( V_13 ++ ) - * ( V_14 ++ ) )
V_17 = V_16 ;
V_16 ++ ;
}
if ( V_17 < 0 )
goto V_21;
V_15 = V_20 - V_17 ;
V_13 = V_8 -> V_18 + V_20 - 1 ;
V_14 = V_8 -> V_19 + V_20 - 1 ;
while ( V_15 > 1 ) {
if ( * ( V_13 -- ) - * ( V_14 -- ) )
break;
V_15 -- ;
}
V_13 = V_8 -> V_18 + V_17 ;
V_14 = V_8 -> V_19 + V_17 ;
if ( ! F_9 ( V_2 -> V_6 , V_17 , V_15 , V_14 ) )
memcpy ( V_13 , V_14 , V_15 ) ;
V_21:
F_4 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_22 ;
int V_23 ;
T_1 V_3 [ V_24 * 2 ] ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_23 = F_11 ( V_2 -> V_6 , 0 , sizeof( V_3 ) , V_3 ) ;
if ( V_23 )
return V_23 ;
V_22 = V_25 | V_26 ;
V_23 = F_2 ( V_2 -> V_6 , V_22 ) ;
if ( V_23 )
return V_23 ;
V_22 = V_27 | V_28 ;
if ( V_2 -> V_6 -> V_29 > 0 )
V_22 |= V_30 ;
return F_2 ( V_2 -> V_6 , V_22 ) ;
}
static int F_12 ( struct V_31 * V_32 )
{
int V_33 = V_32 -> V_34 . V_33 ;
struct V_1 * V_2 = F_13 ( V_32 ) ;
if ( V_32 -> V_34 . V_35 != V_36 ||
V_32 -> V_34 . V_37 != V_36 ||
V_32 -> V_34 . V_38 & V_39 || V_33 == 0 ) {
return F_3 ( V_2 ) ;
}
F_1 ( V_2 ) ;
return F_2 ( V_2 -> V_6 ,
V_40 | ( V_33 - 1 ) ) ;
}
static int F_14 ( struct V_31 * V_32 , struct V_41 * V_42 )
{
struct V_1 * V_2 = F_13 ( V_32 ) ;
return ( V_42 == NULL ) || ( V_42 -> V_43 == V_2 ) ;
}
static int F_15 ( struct V_41 * V_44 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_44 -> V_43 ;
return F_16 ( V_46 , V_46 -> V_47 ,
F_17 ( V_2 -> V_8 . V_19 ) ) ;
}
static bool F_18 ( struct V_48 * V_49 )
{
const unsigned short * V_50 = V_49 -> V_51 -> V_52 ;
T_2 V_53 [ V_54 ] ;
T_3 V_3 [ V_54 ] ;
unsigned long V_55 ;
int V_56 , V_57 , V_58 ;
int V_59 ;
bool V_60 = false ;
V_59 = F_19 ( V_49 -> V_6 , 0x40 ,
sizeof( V_3 ) , ( V_61 * ) V_3 ) ;
if ( V_59 != sizeof( V_3 ) ) {
F_20 ( & V_49 -> V_6 -> V_51 ,
L_1 , V_59 ) ;
return false ;
}
for ( V_57 = 0 ; V_57 < V_49 -> V_62 ; V_57 ++ ) {
V_53 [ V_57 ] = F_21 ( V_3 [ V_57 ] ) ;
if ( V_53 [ V_57 ] )
V_60 = true ;
V_55 = V_49 -> V_63 [ V_57 ] ^ V_53 [ V_57 ] ;
F_22 (row, &bits_changed, BITS_PER_LONG) {
V_58 = F_23 ( V_56 , V_57 , V_49 -> V_64 ) ;
F_24 ( V_49 -> V_51 , V_65 , V_66 , V_58 ) ;
F_25 ( V_49 -> V_51 , V_50 [ V_58 ] ,
V_53 [ V_57 ] & F_26 ( V_56 ) ) ;
}
}
F_27 ( V_49 -> V_51 ) ;
memcpy ( V_49 -> V_63 , V_53 , sizeof( T_2 ) * V_49 -> V_62 ) ;
return V_60 ;
}
static T_4 F_28 ( int V_29 , void * V_51 )
{
struct V_48 * V_49 = V_51 ;
do {
F_29 ( V_49 -> V_67 , V_49 -> V_68 ,
F_6 ( V_49 -> V_69 ) ) ;
if ( V_49 -> V_68 )
break;
} while ( F_18 ( V_49 ) );
return V_70 ;
}
static int F_30 ( struct V_71 * V_51 )
{
struct V_48 * V_49 = F_31 ( V_51 ) ;
V_49 -> V_68 = false ;
F_32 () ;
F_33 ( V_49 -> V_6 -> V_29 ) ;
return 0 ;
}
static void F_34 ( struct V_71 * V_51 )
{
struct V_48 * V_49 = F_31 ( V_51 ) ;
V_49 -> V_68 = true ;
F_32 () ;
F_35 ( & V_49 -> V_67 ) ;
F_36 ( V_49 -> V_6 -> V_29 ) ;
}
static int F_37 ( struct V_72 * V_6 ,
struct V_48 * V_49 )
{
struct V_73 * V_74 = V_6 -> V_51 . V_75 ;
T_5 V_76 = V_77 ;
T_5 V_62 = V_54 ;
int V_23 ;
V_49 -> V_6 = V_6 ;
F_38 ( & V_49 -> V_67 ) ;
V_49 -> V_51 = F_39 ( & V_6 -> V_51 ) ;
if ( ! V_49 -> V_51 )
return - V_78 ;
F_40 ( V_49 -> V_51 , V_49 ) ;
V_49 -> V_51 -> V_79 = V_80 L_2 ;
V_49 -> V_51 -> V_81 . V_82 = V_83 ;
V_49 -> V_51 -> V_84 = F_30 ;
V_49 -> V_51 -> V_85 = F_34 ;
if ( ! F_41 ( V_74 , L_3 , NULL ) )
F_42 ( V_86 , V_49 -> V_51 -> V_87 ) ;
V_23 = F_43 ( V_74 , L_4 ,
& V_49 -> V_69 ) ;
if ( V_23 ) {
F_20 ( & V_6 -> V_51 , L_5 ) ;
return V_23 ;
}
V_23 = F_44 ( & V_6 -> V_51 , & V_76 , & V_62 ) ;
if ( V_23 )
return V_23 ;
if ( V_76 > V_77 ||
V_62 > V_54 ) {
F_20 ( & V_6 -> V_51 , L_6 ,
V_76 , V_62 ) ;
return - V_88 ;
}
V_49 -> V_76 = V_76 ;
V_49 -> V_62 = V_62 ;
V_49 -> V_64 = F_45 ( V_62 ) ;
V_23 = F_46 ( NULL , NULL , V_76 , V_62 , NULL ,
V_49 -> V_51 ) ;
if ( V_23 ) {
F_20 ( & V_6 -> V_51 , L_7 ) ;
return V_23 ;
}
V_23 = F_47 ( & V_6 -> V_51 , V_6 -> V_29 ,
NULL , F_28 ,
V_89 | V_90 ,
V_80 , V_49 ) ;
if ( V_23 ) {
F_20 ( & V_6 -> V_51 , L_8 ,
V_6 -> V_29 , V_23 ) ;
return V_23 ;
}
F_34 ( V_49 -> V_51 ) ;
V_23 = F_48 ( V_49 -> V_51 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_49 ( struct V_72 * V_6 ,
const struct V_91 * V_81 )
{
int V_23 ;
T_6 V_92 ;
struct V_31 * V_32 ;
struct V_93 V_94 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_73 * V_74 = V_6 -> V_51 . V_75 ;
if ( ! F_50 ( V_6 -> V_95 , V_96 ) ) {
F_20 ( & V_6 -> V_51 , L_9 ) ;
return - V_97 ;
}
if ( V_6 -> V_29 <= 0 ) {
F_20 ( & V_6 -> V_51 , L_10 ) ;
return - V_98 ;
}
V_2 = F_51 ( & V_6 -> V_51 , sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_6 = V_6 ;
F_52 ( V_6 , V_2 ) ;
V_8 = & V_2 -> V_8 ;
V_23 = F_10 ( V_2 ) ;
if ( V_23 )
return V_23 ;
F_53 ( V_100 < V_20 ) ;
V_8 -> V_19 = ( unsigned char * ) F_54 ( V_99 ) ;
if ( ! V_8 -> V_19 )
return - V_78 ;
V_8 -> V_18 = F_55 ( & V_6 -> V_51 , V_20 , V_99 ) ;
if ( ! V_8 -> V_18 ) {
V_23 = - V_78 ;
goto V_101;
}
V_8 -> V_44 = F_56 ( 0 , & V_6 -> V_51 ) ;
if ( ! V_8 -> V_44 ) {
V_23 = - V_78 ;
goto V_101;
}
V_23 = F_43 ( V_74 , L_11 ,
& V_8 -> V_11 ) ;
if ( V_23 ) {
F_20 ( & V_6 -> V_51 , L_12 ) ;
goto V_102;
}
F_57 ( V_8 -> V_44 , 0 , V_103 , V_104 ) ;
F_58 ( & V_8 -> V_9 , F_7 ) ;
V_8 -> V_44 -> V_105 = & V_106 ;
V_8 -> V_44 -> V_107 = ( char V_108 * ) V_8 -> V_19 ;
V_8 -> V_44 -> V_109 = V_20 ;
V_8 -> V_44 -> V_110 = V_111 ;
V_8 -> V_44 -> V_112 = V_113 ;
V_8 -> V_44 -> V_114 = NULL ;
V_8 -> V_44 -> V_115 = V_116 ;
V_8 -> V_44 -> V_43 = V_2 ;
V_23 = F_59 ( V_8 -> V_44 ) ;
if ( V_23 )
goto V_102;
V_23 = F_37 ( V_6 , & V_2 -> V_49 ) ;
if ( V_23 )
goto V_117;
memset ( & V_94 , 0 , sizeof( struct V_93 ) ) ;
V_94 . type = V_118 ;
V_94 . V_119 = V_104 ;
V_32 = F_60 ( & V_6 -> V_51 , V_80 L_13 ,
& V_6 -> V_51 , V_2 ,
& V_120 , & V_94 ) ;
if ( F_61 ( V_32 ) ) {
F_20 ( & V_6 -> V_51 , L_14 ) ;
V_23 = F_62 ( V_32 ) ;
goto V_117;
}
V_23 = F_43 ( V_74 , L_15 ,
& V_92 ) ;
if ( V_23 ) {
V_92 = V_104 ;
} else if ( V_92 > V_104 ) {
F_63 ( & V_6 -> V_51 ,
L_16 ,
V_92 , V_104 ) ;
V_92 = V_104 ;
}
V_32 -> V_34 . V_33 = V_92 ;
F_12 ( V_32 ) ;
F_4 ( V_2 ) ;
return 0 ;
V_117:
F_64 ( V_8 -> V_44 ) ;
V_102:
F_65 ( V_8 -> V_44 ) ;
V_101:
F_66 ( ( unsigned long ) V_8 -> V_19 ) ;
return V_23 ;
}
static int F_67 ( struct V_72 * V_6 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_69 ( & V_8 -> V_9 ) ;
F_64 ( V_8 -> V_44 ) ;
F_65 ( V_8 -> V_44 ) ;
F_66 ( ( unsigned long ) V_8 -> V_19 ) ;
return 0 ;
}
