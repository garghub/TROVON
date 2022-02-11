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
if ( V_4 -> V_20 == V_21 )
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
struct V_22 * V_23 ,
bool V_24 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int T_1 V_25 ( ( V_26 ) ) ;
T_2 V_27 = 0 ;
T_3 V_28 ;
if ( V_23 -> V_29 >= F_8 ( V_30 ) )
V_4 -> V_31 . V_32 = V_30 ;
else
V_4 -> V_31 . V_32 = V_33 ;
F_9 ( V_34 ) ;
if ( V_24 )
F_10 ( V_4 ) ;
F_1 ( V_2 ) ;
F_11 ( V_4 , V_23 -> V_35 , V_23 -> V_29 ) ;
V_2 -> V_8 . V_36 = 0 ;
V_27 = F_12 ( V_4 -> V_37 ) ;
F_13 ( V_38 , & V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_22 * V_39 )
{
struct V_40 V_41 ;
enum V_42 V_37 = 0 ;
T_2 V_27 = 0 ;
int T_1 V_25 ( ( V_26 ) ) ;
T_3 V_28 ;
if ( F_15 ( V_2 -> V_4 , V_39 , & V_41 ) == - V_43 )
return;
F_9 ( V_34 ) ;
F_16 ( V_2 -> V_4 , & V_41 ) ;
V_37 |= V_44 ;
V_27 = F_12 ( V_37 ) ;
F_13 ( V_38 , & V_27 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_37 = 0 ;
F_18 ( V_4 , V_23 , V_45 ) ;
F_7 ( V_2 , V_23 , false ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_37 = 0 ;
F_20 ( V_4 , V_23 ) ;
F_7 ( V_2 , V_23 , V_23 -> V_46 ) ;
}
void F_21 ( void * V_47 , struct V_48 * V_49 ,
enum V_50 V_51 , bool V_52 )
{
F_22 ( V_49 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
int V_53 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_56 * V_57 ;
struct V_48 * V_49 ;
struct V_58 * V_59 ;
int V_60 , V_61 , T_1 , V_62 ;
F_24 ( & V_2 -> V_63 ) ;
V_57 = V_2 -> V_8 . V_64 [ V_53 ] ;
V_49 = F_25 ( V_2 -> V_65 , V_57 ) ;
while( V_49 ) {
V_59 = (struct V_58 * ) V_49 -> V_66 ;
V_60 = F_26 ( V_59 -> V_67 ) ;
V_61 = V_60 & 3 ;
if ( V_61 && V_49 -> V_68 > V_60 ) {
if ( F_27 ( V_49 ) < V_61 ) {
F_22 ( V_49 ) ;
goto V_69;
}
F_28 ( V_49 , V_61 ) ;
memmove ( V_49 -> V_66 , V_49 -> V_66 + V_61 , V_60 ) ;
}
V_62 = F_29 ( V_2 ) ;
if ( V_62 < 0 ) {
F_30 ( V_55 , V_70 , L_2 ) ;
F_22 ( V_49 ) ;
goto V_69;
}
T_1 = F_31 ( V_2 , NULL , V_49 , V_62 , true ) ;
if ( T_1 != 0 ) {
F_32 ( V_2 , V_62 ) ;
F_22 ( V_49 ) ;
F_30 ( V_55 , V_70 , L_3 ) ;
} else {
F_24 ( & V_2 -> V_71 . V_72 ) ;
V_2 -> V_71 . V_73 ++ ;
F_33 ( & V_2 -> V_71 . V_72 ) ;
}
V_69:
V_49 = F_25 ( V_2 -> V_65 , V_57 ) ;
}
F_33 ( & V_2 -> V_63 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
int V_53 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_56 * V_57 ;
struct V_74 * V_75 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_48 * V_8 ;
T_3 * V_84 ;
int T_1 ;
memset ( & V_77 , 0 , sizeof( struct V_76 ) ) ;
F_24 ( & V_2 -> V_63 ) ;
V_57 = V_2 -> V_8 . V_64 [ V_53 ] ;
V_75 = (struct V_74 * ) V_57 -> V_47 ;
if ( F_35 ( F_36 ( V_85 , & V_55 -> V_86 ) ) ) {
F_33 ( & V_2 -> V_63 ) ;
return;
}
V_8 = F_37 ( V_2 -> V_65 , V_57 ) ;
if ( ! V_8 ) {
F_33 ( & V_2 -> V_63 ) ;
return;
}
V_83 = (struct V_82 * ) V_8 -> V_66 ;
V_83 -> V_87 . V_8 . V_88 = V_75 -> V_89 ;
V_81 = F_38 ( V_8 ) ;
if ( V_81 -> V_90 & V_91 ) {
struct V_58 * V_59 =
(struct V_58 * ) V_8 -> V_66 ;
V_75 -> V_92 += 0x10 ;
V_59 -> V_93 &= F_39 ( V_94 ) ;
V_59 -> V_93 |= F_39 ( V_75 -> V_92 ) ;
}
V_79 = F_40 ( V_8 ) ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> type = V_95 ;
V_79 -> V_96 = V_2 -> V_97 ;
V_77 . V_98 = V_75 -> V_99 ;
V_84 = F_28 ( V_8 , sizeof( V_77 ) ) ;
memcpy ( V_84 , ( T_3 * ) & V_77 , sizeof( V_77 ) ) ;
T_1 = F_41 ( V_2 -> V_100 , V_8 ) ;
if ( T_1 != 0 ) {
if ( T_1 == - V_101 ) {
F_30 ( V_55 , V_102 ,
L_4 ) ;
}
F_22 ( V_8 ) ;
}
F_33 ( & V_2 -> V_63 ) ;
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
T_4 V_105 ;
T_5 V_106 ;
T_6 V_29 ;
int V_53 ;
V_29 = V_2 -> V_107 . V_108 ;
V_105 = F_44 ( V_104 -> V_105 ) ;
V_106 = F_45 ( V_105 >> 32 , V_105 ) ;
V_53 = ( ( V_106 % V_29 ) * V_45 ) / V_29 ;
V_53 = V_45 - V_53 - 1 ;
F_30 ( V_55 , V_109 ,
L_5 ,
V_53 , V_105 , V_106 , V_29 ) ;
return V_53 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
int V_53 ;
if ( V_104 -> V_110 != 0 ) {
V_2 -> V_8 . V_36 ++ ;
if ( V_2 -> V_8 . V_36 > V_111 ) {
F_30 ( V_55 , V_102 , L_6 ) ;
F_47 ( V_2 -> V_65 ,
& V_2 -> V_112 ) ;
}
return;
}
if ( V_2 -> V_8 . V_36 ) {
F_30 ( V_55 , V_102 ,
L_7 ,
V_2 -> V_8 . V_36 ) ;
V_2 -> V_8 . V_36 = 0 ;
}
V_53 = F_43 ( V_2 , V_104 ) ;
F_24 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_8 . V_64 [ V_53 ] == NULL ) {
F_33 ( & V_2 -> V_63 ) ;
return;
}
F_33 ( & V_2 -> V_63 ) ;
F_23 ( V_2 , V_53 ) ;
F_34 ( V_2 , V_53 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_57 -> V_47 ;
int V_113 = 0 ;
F_24 ( & V_2 -> V_63 ) ;
for ( V_113 = 0 ; V_113 < V_45 ; V_113 ++ ) {
if ( V_2 -> V_8 . V_64 [ V_113 ] == NULL ) {
V_75 -> V_64 = V_113 ;
break;
}
}
V_2 -> V_8 . V_64 [ V_75 -> V_64 ] = V_57 ;
F_33 ( & V_2 -> V_63 ) ;
F_30 ( V_55 , V_114 , L_8 ,
V_75 -> V_64 ) ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_57 -> V_47 ;
F_24 ( & V_2 -> V_63 ) ;
V_2 -> V_8 . V_64 [ V_75 -> V_64 ] = NULL ;
F_33 ( & V_2 -> V_63 ) ;
F_30 ( V_55 , V_114 , L_9 ,
V_75 -> V_64 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_57 -> V_47 ;
struct V_22 * V_115 = & V_2 -> V_107 ;
T_4 V_89 ;
if ( V_75 -> V_64 == 0 )
return;
V_89 = V_115 -> V_108 * V_75 -> V_64 / V_45 ;
V_75 -> V_89 = F_51 ( F_8 ( V_89 ) ) ;
F_30 ( V_55 , V_114 , L_10 ,
( unsigned long long ) V_89 , V_75 -> V_64 ) ;
}
static void F_52 ( void * V_66 , T_3 * V_116 , struct V_56 * V_57 )
{
bool * V_117 = ( bool * ) V_66 ;
struct V_74 * V_75 = (struct V_74 * ) V_57 -> V_47 ;
if ( V_57 -> type == V_118 &&
V_75 -> V_117 )
* V_117 = true ;
}
static bool F_53 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_22 * V_115 = & V_2 -> V_107 ;
struct V_119 * V_39 = & V_57 -> V_39 ;
bool V_117 ;
if ( ( V_2 -> V_4 -> V_10 == V_11 ) &&
( V_2 -> V_120 > 1 ) &&
( V_57 -> type == V_11 ) &&
( V_115 -> V_108 != V_39 -> V_121 ) ) {
F_30 ( V_55 , V_114 ,
L_11 ) ;
return false ;
}
if ( V_2 -> V_120 &&
( V_57 -> type != V_11 ) ) {
F_30 ( V_55 , V_114 ,
L_12 ) ;
return false ;
}
if ( ( V_2 -> V_4 -> V_10 == V_118 ) &&
( V_2 -> V_122 > 1 ) &&
( V_57 -> type == V_118 ) ) {
V_117 = false ;
F_54 (
V_2 -> V_65 , V_123 ,
F_52 , & V_117 ) ;
if ( V_117 ) {
F_30 ( V_55 , V_114 ,
L_13 ) ;
return false ;
}
}
return true ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_22 * V_115 = & V_2 -> V_107 ;
struct V_119 * V_39 = & V_57 -> V_39 ;
struct V_74 * V_75 = (struct V_74 * ) V_57 -> V_47 ;
if ( ! F_53 ( V_2 , V_57 ) )
return;
V_115 -> V_108 = V_39 -> V_121 ;
if ( V_115 -> V_108 == 0 )
V_115 -> V_108 = 100 ;
V_115 -> V_124 = V_39 -> V_124 ;
V_115 -> V_125 =
V_126 * V_115 -> V_108 ;
switch ( V_57 -> type ) {
case V_118 :
F_14 ( V_2 , V_115 ) ;
V_75 -> V_117 = true ;
break;
case V_16 :
F_19 ( V_2 , V_115 ) ;
break;
case V_12 :
case V_11 :
F_17 ( V_2 , V_115 ) ;
break;
default:
F_30 ( V_55 , V_114 , L_14 ) ;
return;
}
}
void F_56 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_5 ( V_2 -> V_4 ) ;
struct V_22 * V_115 = & V_2 -> V_107 ;
switch ( V_2 -> V_4 -> V_10 ) {
case V_118 :
F_14 ( V_2 , V_115 ) ;
break;
case V_16 :
F_19 ( V_2 , V_115 ) ;
break;
case V_12 :
case V_11 :
F_17 ( V_2 , V_115 ) ;
break;
default:
F_30 ( V_55 , V_114 , L_14 ) ;
return;
}
}
bool F_42 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
V_57 = V_2 -> V_127 ;
if ( ! V_57 || ! V_57 -> V_128 )
return false ;
if ( ! F_57 ( V_57 ) )
return false ;
F_58 ( V_57 ) ;
V_2 -> V_127 = NULL ;
return true ;
}
