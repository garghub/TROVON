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
F_5 ( V_2 -> V_9 , & V_8 -> V_10 ,
F_6 ( V_11 / V_8 -> V_12 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
F_5 ( V_2 -> V_9 , & V_14 -> V_10 ,
F_6 ( V_14 -> V_15 ) ) ;
}
static void F_8 ( struct V_16 * V_10 )
{
struct V_7 * V_8 =
F_9 ( V_10 , struct V_7 , V_10 . V_10 ) ;
struct V_1 * V_2 =
F_9 ( V_8 , struct V_1 , V_8 ) ;
T_1 * V_17 , * V_18 ;
int V_19 , V_20 = 0 , V_21 = - 1 ;
V_17 = V_8 -> V_22 ;
V_18 = V_8 -> V_23 ;
while ( V_20 < V_24 && V_21 < 0 ) {
if ( * ( V_17 ++ ) - * ( V_18 ++ ) )
V_21 = V_20 ;
V_20 ++ ;
}
if ( V_21 < 0 )
goto V_25;
V_19 = V_24 - V_21 ;
V_17 = V_8 -> V_22 + V_24 - 1 ;
V_18 = V_8 -> V_23 + V_24 - 1 ;
while ( V_19 > 1 ) {
if ( * ( V_17 -- ) - * ( V_18 -- ) )
break;
V_19 -- ;
}
V_17 = V_8 -> V_22 + V_21 ;
V_18 = V_8 -> V_23 + V_21 ;
if ( ! F_10 ( V_2 -> V_6 , V_21 , V_19 , V_18 ) )
memcpy ( V_17 , V_18 , V_19 ) ;
V_25:
F_4 ( V_2 ) ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_27 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
F_5 ( V_2 -> V_9 , & V_14 -> V_10 , 0 ) ;
return 0 ;
}
static void F_13 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_27 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
F_14 ( & V_14 -> V_10 ) ;
F_15 ( V_2 -> V_6 -> V_28 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_29 ;
int V_30 ;
T_1 V_3 [ V_31 * 2 ] ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_30 = F_17 ( V_2 -> V_6 , 0 , sizeof( V_3 ) , V_3 ) ;
if ( V_30 )
return V_30 ;
V_29 = V_32 | V_33 ;
V_30 = F_2 ( V_2 -> V_6 , V_29 ) ;
if ( V_30 )
return V_30 ;
V_29 = V_34 | V_35 ;
if ( V_2 -> V_6 -> V_28 > 0 )
V_29 |= V_36 ;
return F_2 ( V_2 -> V_6 , V_29 ) ;
}
static void F_18 ( struct V_16 * V_10 )
{
struct V_13 * V_14 =
F_9 ( V_10 , struct V_13 , V_10 . V_10 ) ;
struct V_1 * V_2 =
F_9 ( V_14 , struct V_1 , V_14 ) ;
const unsigned short * V_37 = V_14 -> V_27 -> V_38 ;
T_2 V_39 , V_40 [ V_41 ] ;
T_1 V_3 [ V_41 * 2 ] ;
int V_42 , V_43 , V_44 ;
bool V_45 = false ;
if ( F_19 ( V_2 -> V_6 , 0x40 , 6 , V_3 ) != 6 ) {
F_20 ( & V_2 -> V_6 -> V_27 , L_1 ) ;
goto V_46;
}
for ( V_43 = 0 ; V_43 < V_14 -> V_47 ; V_43 ++ ) {
V_40 [ V_43 ] = ( V_3 [ V_43 * 2 + 1 ] << 8 ) | V_3 [ V_43 * 2 ] ;
if ( V_40 [ V_43 ] )
V_45 = true ;
V_39 = V_14 -> V_48 [ V_43 ] ^ V_40 [ V_43 ] ;
while ( V_39 ) {
V_42 = F_21 ( V_39 ) - 1 ;
V_44 = F_22 ( V_42 , V_43 , V_14 -> V_49 ) ;
F_23 ( V_14 -> V_27 , V_50 , V_51 , V_44 ) ;
F_24 ( V_14 -> V_27 , V_37 [ V_44 ] ,
V_40 [ V_43 ] & F_25 ( V_42 ) ) ;
V_39 &= ~ F_25 ( V_42 ) ;
}
}
F_26 ( V_14 -> V_27 ) ;
memcpy ( V_14 -> V_48 , V_40 , sizeof( V_40 ) ) ;
V_46:
if ( V_45 )
F_7 ( V_2 ) ;
else
F_27 ( V_2 -> V_6 -> V_28 ) ;
}
static T_3 F_28 ( int V_28 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
F_15 ( V_2 -> V_6 -> V_28 ) ;
F_7 ( V_2 ) ;
return V_52 ;
}
static int F_29 ( struct V_53 * V_54 )
{
int V_55 = V_54 -> V_56 . V_55 ;
struct V_1 * V_2 = F_30 ( V_54 ) ;
if ( V_54 -> V_56 . V_57 != V_58 ||
V_54 -> V_56 . V_59 != V_58 ||
V_54 -> V_56 . V_60 & V_61 || V_55 == 0 ) {
return F_3 ( V_2 ) ;
}
F_1 ( V_2 ) ;
return F_2 ( V_2 -> V_6 ,
V_62 | ( V_55 - 1 ) ) ;
}
static int F_31 ( struct V_53 * V_54 , struct V_63 * V_64 )
{
struct V_1 * V_2 = F_30 ( V_54 ) ;
return ( V_64 == NULL ) || ( V_64 -> V_65 == V_2 ) ;
}
static int F_32 ( struct V_63 * V_66 , struct V_67 * V_68 )
{
struct V_1 * V_2 = V_66 -> V_65 ;
return F_33 ( V_68 , V_68 -> V_69 ,
F_34 ( V_2 -> V_8 . V_23 ) ) ;
}
static int F_35 ( struct V_70 * V_6 ,
const struct V_71 * V_72 )
{
int V_30 ;
T_4 V_73 , V_47 , V_74 ;
struct V_53 * V_54 ;
struct V_75 V_76 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_7 * V_8 ;
struct V_77 * V_78 = V_6 -> V_27 . V_79 ;
if ( ! F_36 ( V_6 -> V_80 , V_81 ) ) {
F_20 ( & V_6 -> V_27 , L_2 ) ;
return - V_82 ;
}
if ( V_6 -> V_28 <= 0 ) {
F_20 ( & V_6 -> V_27 , L_3 ) ;
return - V_83 ;
}
V_2 = F_37 ( & V_6 -> V_27 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_6 = V_6 ;
F_38 ( V_6 , V_2 ) ;
V_8 = & V_2 -> V_8 ;
V_14 = & V_2 -> V_14 ;
V_2 -> V_9 = F_39 ( V_86 L_4 ) ;
if ( V_2 -> V_9 == NULL )
return - V_85 ;
V_30 = F_16 ( V_2 ) ;
if ( V_30 )
goto V_87;
F_40 ( V_88 < V_24 ) ;
V_8 -> V_23 = ( unsigned char * ) F_41 ( V_84 ) ;
if ( ! V_8 -> V_23 ) {
V_30 = - V_85 ;
goto V_89;
}
V_8 -> V_22 = F_42 ( & V_6 -> V_27 , V_24 , V_84 ) ;
if ( ! V_8 -> V_22 ) {
V_30 = - V_85 ;
goto V_90;
}
V_8 -> V_66 = F_43 ( 0 , & V_6 -> V_27 ) ;
if ( ! V_8 -> V_66 ) {
V_30 = - V_85 ;
goto V_90;
}
V_30 = F_44 ( V_78 , L_5 ,
& V_8 -> V_12 ) ;
if ( V_30 ) {
F_20 ( & V_6 -> V_27 , L_6 ) ;
goto V_91;
}
F_45 ( V_8 -> V_66 , 0 , V_92 , V_93 ) ;
F_46 ( & V_8 -> V_10 , F_8 ) ;
V_8 -> V_66 -> V_94 = & V_95 ;
V_8 -> V_66 -> V_96 = ( char V_97 * ) V_8 -> V_23 ;
V_8 -> V_66 -> V_98 = V_24 ;
V_8 -> V_66 -> V_99 = V_100 ;
V_8 -> V_66 -> V_101 = V_102 ;
V_8 -> V_66 -> V_103 = NULL ;
V_8 -> V_66 -> V_104 = V_105 ;
V_8 -> V_66 -> V_65 = V_2 ;
V_30 = F_47 ( V_8 -> V_66 ) ;
if ( V_30 )
goto V_91;
V_14 -> V_27 = F_48 ( & V_6 -> V_27 ) ;
if ( ! V_14 -> V_27 ) {
V_30 = - V_85 ;
goto V_106;
}
V_14 -> V_27 -> V_107 = V_86 L_7 ;
V_14 -> V_27 -> V_72 . V_108 = V_109 ;
V_14 -> V_27 -> V_110 = F_11 ;
V_14 -> V_27 -> V_111 = F_13 ;
if ( ! F_49 ( V_78 , L_8 , NULL ) )
F_50 ( V_112 , V_14 -> V_27 -> V_113 ) ;
V_30 = F_44 ( V_78 , L_9 ,
& V_14 -> V_15 ) ;
if ( V_30 ) {
F_20 ( & V_6 -> V_27 , L_10 ) ;
goto V_106;
}
V_30 = F_51 ( & V_6 -> V_27 , V_6 -> V_28 , NULL ,
F_28 ,
V_114 | V_115 ,
V_86 , V_2 ) ;
if ( V_30 ) {
F_20 ( & V_6 -> V_27 , L_11 ,
V_6 -> V_28 , V_30 ) ;
goto V_106;
}
F_15 ( V_6 -> V_28 ) ;
V_73 = V_116 ;
V_47 = V_41 ;
V_30 = F_52 ( & V_6 -> V_27 , & V_73 , & V_47 ) ;
if ( V_30 )
goto V_106;
V_30 = F_53 ( NULL , NULL , V_73 , V_47 , NULL ,
V_14 -> V_27 ) ;
if ( V_30 ) {
F_20 ( & V_6 -> V_27 , L_12 ) ;
goto V_106;
}
F_54 ( V_14 -> V_27 , V_2 ) ;
V_14 -> V_73 = V_73 ;
V_14 -> V_47 = V_47 ;
V_14 -> V_49 = F_55 ( V_47 ) ;
F_46 ( & V_14 -> V_10 , F_18 ) ;
V_30 = F_56 ( V_14 -> V_27 ) ;
if ( V_30 )
goto V_106;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . type = V_117 ;
V_76 . V_118 = V_93 ;
V_54 = F_57 ( & V_6 -> V_27 , V_86 L_13 ,
& V_6 -> V_27 , V_2 ,
& V_119 , & V_76 ) ;
if ( F_58 ( V_54 ) ) {
F_20 ( & V_6 -> V_27 , L_14 ) ;
V_30 = F_59 ( V_54 ) ;
goto V_120;
}
V_30 = F_44 ( V_78 , L_15 ,
& V_74 ) ;
if ( V_30 ) {
V_74 = V_93 ;
} else if ( V_74 > V_93 ) {
F_60 ( & V_6 -> V_27 ,
L_16 ,
V_74 , V_93 ) ;
V_74 = V_93 ;
}
V_54 -> V_56 . V_55 = V_74 ;
F_29 ( V_54 ) ;
F_4 ( V_2 ) ;
return 0 ;
V_120:
F_61 ( V_14 -> V_27 ) ;
V_106:
F_62 ( V_8 -> V_66 ) ;
V_91:
F_63 ( V_8 -> V_66 ) ;
V_90:
F_64 ( ( unsigned long ) V_8 -> V_23 ) ;
V_89:
F_65 ( V_8 ) ;
V_87:
F_66 ( V_2 -> V_9 ) ;
return V_30 ;
}
static int F_67 ( struct V_70 * V_6 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_13 ( V_14 -> V_27 ) ;
F_14 ( & V_8 -> V_10 ) ;
F_62 ( V_8 -> V_66 ) ;
F_63 ( V_8 -> V_66 ) ;
F_64 ( ( unsigned long ) V_8 -> V_23 ) ;
F_66 ( V_2 -> V_9 ) ;
return 0 ;
}
