void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 , V_7 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( struct V_5 ) ) ;
F_2 ( V_4 , V_2 -> V_8 . V_9 , & V_6 ) ;
if ( V_2 -> V_4 -> V_10 == V_11 ||
V_2 -> V_4 -> V_10 == V_12 ) {
V_6 . V_13 = 1 ;
V_6 . V_14 = 0 ;
V_6 . V_15 = 0 ;
} else if ( V_2 -> V_4 -> V_10 == V_16 ) {
int V_17 = V_2 -> V_18 [ V_19 ] ;
F_2 ( V_4 , V_17 , & V_7 ) ;
V_6 . V_13 = V_7 . V_13 ;
if ( V_4 -> V_20 == 20 )
V_6 . V_14 = 2 * V_7 . V_14 ;
else
V_6 . V_14 = 4 * V_7 . V_14 ;
V_6 . V_15 = V_7 . V_15 ;
}
if ( ! F_3 ( V_4 , V_2 -> V_8 . V_9 , & V_6 ) ) {
F_4 ( F_5 ( V_4 ) ,
L_1 , V_2 -> V_8 . V_9 ) ;
} else {
F_6 ( V_4 , V_2 -> V_8 . V_9 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
bool V_23 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int T_1 V_24 ( ( V_25 ) ) ;
T_2 V_26 = 0 ;
T_3 V_27 ;
if ( V_22 -> V_28 >= F_8 ( V_29 ) )
V_4 -> V_30 . V_31 = V_29 ;
else
V_4 -> V_30 . V_31 = V_32 ;
F_9 ( V_33 ) ;
if ( V_23 )
F_10 ( V_4 ) ;
F_1 ( V_2 ) ;
F_11 ( V_4 , V_22 -> V_34 , V_22 -> V_28 ) ;
V_2 -> V_8 . V_35 = 0 ;
V_26 = F_12 ( V_4 -> V_36 ) ;
F_13 ( V_37 , & V_26 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_21 * V_38 )
{
struct V_39 V_40 ;
enum V_41 V_36 = 0 ;
T_2 V_26 = 0 ;
int T_1 V_24 ( ( V_25 ) ) ;
T_3 V_27 ;
if ( F_15 ( V_2 -> V_4 , V_38 , & V_40 ) == - V_42 )
return;
F_9 ( V_33 ) ;
F_16 ( V_2 -> V_4 , & V_40 ) ;
V_36 |= V_43 ;
V_26 = F_12 ( V_36 ) ;
F_13 ( V_37 , & V_26 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_36 = 0 ;
F_18 ( V_4 , V_22 , V_44 ) ;
F_7 ( V_2 , V_22 , false ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_36 = 0 ;
F_20 ( V_4 , V_22 ) ;
F_7 ( V_2 , V_22 , V_22 -> V_45 ) ;
}
void F_21 ( void * V_46 , struct V_47 * V_48 ,
enum V_49 V_50 , bool V_51 )
{
F_22 ( V_48 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
int V_52 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_55 * V_56 ;
struct V_47 * V_48 ;
struct V_57 * V_58 ;
int V_59 , V_60 , T_1 , V_61 ;
F_24 ( & V_2 -> V_62 ) ;
V_56 = V_2 -> V_8 . V_63 [ V_52 ] ;
V_48 = F_25 ( V_2 -> V_64 , V_56 ) ;
while( V_48 ) {
V_58 = (struct V_57 * ) V_48 -> V_65 ;
V_59 = F_26 ( V_58 -> V_66 ) ;
V_60 = V_59 & 3 ;
if ( V_60 && V_48 -> V_67 > V_59 ) {
if ( F_27 ( V_48 ) < V_60 ) {
F_22 ( V_48 ) ;
goto V_68;
}
F_28 ( V_48 , V_60 ) ;
memmove ( V_48 -> V_65 , V_48 -> V_65 + V_60 , V_59 ) ;
}
V_61 = F_29 ( V_2 ) ;
if ( V_61 < 0 ) {
F_30 ( V_54 , V_69 , L_2 ) ;
F_22 ( V_48 ) ;
goto V_68;
}
T_1 = F_31 ( V_2 , NULL , V_48 , V_61 , true ) ;
if ( T_1 != 0 ) {
F_32 ( V_2 , V_61 ) ;
F_22 ( V_48 ) ;
F_30 ( V_54 , V_69 , L_3 ) ;
} else {
F_24 ( & V_2 -> V_70 . V_71 ) ;
V_2 -> V_70 . V_72 ++ ;
F_33 ( & V_2 -> V_70 . V_71 ) ;
}
V_68:
V_48 = F_25 ( V_2 -> V_64 , V_56 ) ;
}
F_33 ( & V_2 -> V_62 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
int V_52 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_55 * V_56 ;
struct V_73 * V_74 ;
struct V_75 V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_47 * V_8 ;
T_3 * V_83 ;
int T_1 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
F_24 ( & V_2 -> V_62 ) ;
V_56 = V_2 -> V_8 . V_63 [ V_52 ] ;
V_74 = (struct V_73 * ) V_56 -> V_46 ;
if ( F_35 ( F_36 ( V_84 , & V_54 -> V_85 ) ) ) {
F_33 ( & V_2 -> V_62 ) ;
return;
}
V_8 = F_37 ( V_2 -> V_64 , V_56 ) ;
if ( ! V_8 ) {
F_33 ( & V_2 -> V_62 ) ;
return;
}
V_82 = (struct V_81 * ) V_8 -> V_65 ;
V_82 -> V_86 . V_8 . V_87 = V_74 -> V_88 ;
V_80 = F_38 ( V_8 ) ;
if ( V_80 -> V_89 & V_90 ) {
struct V_57 * V_58 =
(struct V_57 * ) V_8 -> V_65 ;
V_74 -> V_91 += 0x10 ;
V_58 -> V_92 &= F_39 ( V_93 ) ;
V_58 -> V_92 |= F_39 ( V_74 -> V_91 ) ;
}
V_78 = F_40 ( V_8 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> type = V_94 ;
V_78 -> V_95 = V_2 -> V_96 ;
V_76 . V_97 = V_74 -> V_98 ;
V_83 = F_28 ( V_8 , sizeof( V_76 ) ) ;
memcpy ( V_83 , ( T_3 * ) & V_76 , sizeof( V_76 ) ) ;
T_1 = F_41 ( V_2 -> V_99 , V_8 ) ;
if ( T_1 != 0 ) {
if ( T_1 == - V_100 ) {
F_30 ( V_54 , V_101 ,
L_4 ) ;
}
F_22 ( V_8 ) ;
}
F_33 ( & V_2 -> V_62 ) ;
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
T_4 V_104 ;
T_5 V_105 ;
T_6 V_28 ;
int V_52 ;
V_28 = V_2 -> V_106 . V_107 ;
V_104 = F_44 ( V_103 -> V_104 ) ;
V_105 = F_45 ( V_104 >> 32 , V_104 ) ;
V_52 = ( ( V_105 % V_28 ) * V_44 ) / V_28 ;
V_52 = V_44 - V_52 - 1 ;
F_30 ( V_54 , V_108 ,
L_5 ,
V_52 , V_104 , V_105 , V_28 ) ;
return V_52 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
int V_52 ;
if ( V_103 -> V_109 != 0 ) {
V_2 -> V_8 . V_35 ++ ;
if ( V_2 -> V_8 . V_35 > V_110 ) {
F_30 ( V_54 , V_101 , L_6 ) ;
F_47 ( V_2 -> V_64 ,
& V_2 -> V_111 ) ;
}
return;
}
if ( V_2 -> V_8 . V_35 ) {
F_30 ( V_54 , V_101 ,
L_7 ,
V_2 -> V_8 . V_35 ) ;
V_2 -> V_8 . V_35 = 0 ;
}
V_52 = F_43 ( V_2 , V_103 ) ;
F_24 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_8 . V_63 [ V_52 ] == NULL ) {
F_33 ( & V_2 -> V_62 ) ;
return;
}
F_33 ( & V_2 -> V_62 ) ;
F_23 ( V_2 , V_52 ) ;
F_34 ( V_2 , V_52 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_73 * V_74 = (struct V_73 * ) V_56 -> V_46 ;
int V_112 = 0 ;
F_24 ( & V_2 -> V_62 ) ;
for ( V_112 = 0 ; V_112 < V_44 ; V_112 ++ ) {
if ( V_2 -> V_8 . V_63 [ V_112 ] == NULL ) {
V_74 -> V_63 = V_112 ;
break;
}
}
V_2 -> V_8 . V_63 [ V_74 -> V_63 ] = V_56 ;
F_33 ( & V_2 -> V_62 ) ;
F_30 ( V_54 , V_113 , L_8 ,
V_74 -> V_63 ) ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_73 * V_74 = (struct V_73 * ) V_56 -> V_46 ;
F_24 ( & V_2 -> V_62 ) ;
V_2 -> V_8 . V_63 [ V_74 -> V_63 ] = NULL ;
F_33 ( & V_2 -> V_62 ) ;
F_30 ( V_54 , V_113 , L_9 ,
V_74 -> V_63 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_73 * V_74 = (struct V_73 * ) V_56 -> V_46 ;
struct V_21 * V_114 = & V_2 -> V_106 ;
T_4 V_88 ;
if ( V_74 -> V_63 == 0 )
return;
V_88 = V_114 -> V_107 * V_74 -> V_63 / V_44 ;
V_74 -> V_88 = F_51 ( F_8 ( V_88 ) ) ;
F_30 ( V_54 , V_113 , L_10 ,
( unsigned long long ) V_88 , V_74 -> V_63 ) ;
}
static void F_52 ( void * V_65 , T_3 * V_115 , struct V_55 * V_56 )
{
bool * V_116 = ( bool * ) V_65 ;
struct V_73 * V_74 = (struct V_73 * ) V_56 -> V_46 ;
if ( V_56 -> type == V_117 &&
V_74 -> V_116 )
* V_116 = true ;
}
static bool F_53 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_114 = & V_2 -> V_106 ;
struct V_118 * V_38 = & V_56 -> V_38 ;
bool V_116 ;
if ( ( V_2 -> V_4 -> V_10 == V_11 ) &&
( V_2 -> V_119 > 1 ) &&
( V_56 -> type == V_11 ) &&
( V_114 -> V_107 != V_38 -> V_120 ) ) {
F_30 ( V_54 , V_113 ,
L_11 ) ;
return false ;
}
if ( V_2 -> V_119 &&
( V_56 -> type != V_11 ) ) {
F_30 ( V_54 , V_113 ,
L_12 ) ;
return false ;
}
if ( ( V_2 -> V_4 -> V_10 == V_117 ) &&
( V_2 -> V_121 > 1 ) &&
( V_56 -> type == V_117 ) ) {
V_116 = false ;
F_54 (
V_2 -> V_64 , V_122 ,
F_52 , & V_116 ) ;
if ( V_116 ) {
F_30 ( V_54 , V_113 ,
L_13 ) ;
return false ;
}
}
return true ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_114 = & V_2 -> V_106 ;
struct V_118 * V_38 = & V_56 -> V_38 ;
struct V_73 * V_74 = (struct V_73 * ) V_56 -> V_46 ;
if ( ! F_53 ( V_2 , V_56 ) )
return;
V_114 -> V_107 = V_38 -> V_120 ;
if ( V_114 -> V_107 == 0 )
V_114 -> V_107 = 100 ;
V_114 -> V_123 = V_38 -> V_123 ;
V_114 -> V_124 =
V_125 * V_114 -> V_107 ;
switch ( V_56 -> type ) {
case V_117 :
F_14 ( V_2 , V_114 ) ;
V_74 -> V_116 = true ;
break;
case V_16 :
F_19 ( V_2 , V_114 ) ;
break;
case V_12 :
case V_11 :
F_17 ( V_2 , V_114 ) ;
break;
default:
F_30 ( V_54 , V_113 , L_14 ) ;
return;
}
}
void F_56 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_114 = & V_2 -> V_106 ;
switch ( V_2 -> V_4 -> V_10 ) {
case V_117 :
F_14 ( V_2 , V_114 ) ;
break;
case V_16 :
F_19 ( V_2 , V_114 ) ;
break;
case V_12 :
case V_11 :
F_17 ( V_2 , V_114 ) ;
break;
default:
F_30 ( V_54 , V_113 , L_14 ) ;
return;
}
}
bool F_42 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
V_56 = V_2 -> V_126 ;
if ( ! V_56 || ! V_56 -> V_127 )
return false ;
if ( ! F_57 ( V_56 ) )
return false ;
F_58 ( V_56 ) ;
V_2 -> V_126 = NULL ;
return true ;
}
