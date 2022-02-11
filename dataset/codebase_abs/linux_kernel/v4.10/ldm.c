bool F_1 ( const T_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( ! V_1 || ! V_3 ) ;
if ( V_4 != F_3 ( V_1 ) ) {
F_4 ( L_1 ) ;
return false ;
}
strncpy ( V_3 -> V_5 , V_1 + 0x24 , sizeof ( V_3 -> V_5 ) ) ;
V_3 -> V_5 [ sizeof ( V_3 -> V_5 ) - 1 ] = 0 ;
V_3 -> V_6 = F_3 ( V_1 + 0x2E ) ;
V_3 -> V_7 = F_3 ( V_1 + 0x36 ) ;
if ( strncmp ( V_3 -> V_5 , V_8 ,
sizeof ( V_3 -> V_5 ) ) != 0 ) {
F_4 ( L_2 ,
V_8 , V_3 -> V_5 ) ;
return false ;
}
strncpy ( V_3 -> V_9 , V_1 + 0x46 , sizeof ( V_3 -> V_9 ) ) ;
V_3 -> V_9 [ sizeof ( V_3 -> V_9 ) - 1 ] = 0 ;
V_3 -> V_10 = F_3 ( V_1 + 0x50 ) ;
V_3 -> V_11 = F_3 ( V_1 + 0x58 ) ;
if ( strncmp ( V_3 -> V_9 , V_12 ,
sizeof ( V_3 -> V_9 ) ) != 0 ) {
F_4 ( L_3 ,
V_12 , V_3 -> V_9 ) ;
return false ;
}
F_5 ( L_4 ) ;
return true ;
}
static bool F_6 ( const T_1 * V_1 , struct V_13 * V_14 )
{
F_2 ( ! V_1 || ! V_14 ) ;
if ( V_15 != F_7 ( V_1 ) ) {
F_4 ( L_5 ) ;
return false ;
}
V_14 -> V_16 = F_8 ( V_1 + 0x12 ) ;
V_14 -> V_17 = F_8 ( V_1 + 0x14 ) ;
if ( ( V_14 -> V_16 != 4 ) || ( V_14 -> V_17 != 10 ) ) {
F_9 ( L_6
L_7 , 4 , 10 , V_14 -> V_16 , V_14 -> V_17 ) ;
return false ;
}
V_14 -> V_18 = F_7 ( V_1 + 0x08 ) ;
if ( V_14 -> V_18 == 0 ) {
F_9 ( L_8 ) ;
return false ;
}
V_14 -> V_19 = F_7 ( V_1 + 0x0C ) ;
V_14 -> V_20 = F_7 ( V_1 + 0x04 ) ;
F_5 ( L_9 ) ;
return true ;
}
static bool F_10 ( const struct V_21 * V_22 ,
const struct V_21 * V_23 )
{
F_2 ( ! V_22 || ! V_23 ) ;
return ( ( V_22 -> V_16 == V_23 -> V_16 ) &&
( V_22 -> V_17 == V_23 -> V_17 ) &&
( V_22 -> V_24 == V_23 -> V_24 ) &&
( V_22 -> V_25 == V_23 -> V_25 ) &&
( V_22 -> V_26 == V_23 -> V_26 ) &&
( V_22 -> V_27 == V_23 -> V_27 ) &&
! memcmp ( V_22 -> V_28 , V_23 -> V_28 , V_29 ) ) ;
}
static bool F_11 ( const struct V_2 * V_30 ,
const struct V_2 * V_31 )
{
F_2 ( ! V_30 || ! V_31 ) ;
return ( ( V_30 -> V_6 == V_31 -> V_6 ) &&
( V_30 -> V_7 == V_31 -> V_7 ) &&
( V_30 -> V_10 == V_31 -> V_10 ) &&
( V_30 -> V_11 == V_31 -> V_11 ) &&
! strncmp ( V_30 -> V_5 , V_31 -> V_5 ,
sizeof ( V_30 -> V_5 ) ) &&
! strncmp ( V_30 -> V_9 , V_31 -> V_9 ,
sizeof ( V_30 -> V_9 ) ) ) ;
}
static bool F_12 ( struct V_32 * V_33 ,
struct V_21 * V_22 )
{
static const int V_34 [ 3 ] = { V_35 , V_36 , V_37 } ;
struct V_21 * V_38 [ 3 ] = { V_22 } ;
T_2 V_39 ;
T_1 * V_1 ;
bool V_40 = false ;
long V_41 ;
int V_42 ;
F_2 ( ! V_33 || ! V_22 ) ;
V_38 [ 1 ] = F_13 ( sizeof ( * V_38 [ 1 ] ) , V_43 ) ;
V_38 [ 2 ] = F_13 ( sizeof ( * V_38 [ 2 ] ) , V_43 ) ;
if ( ! V_38 [ 1 ] || ! V_38 [ 2 ] ) {
F_4 ( L_10 ) ;
goto V_44;
}
V_38 [ 0 ] -> V_26 = 0 ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_1 = F_14 ( V_33 , V_38 [ 0 ] -> V_26 + V_34 [ V_42 ] ,
& V_39 ) ;
if ( ! V_1 ) {
F_4 ( L_11 ) ;
goto V_44;
}
V_40 = F_15 ( V_1 , V_38 [ V_42 ] ) ;
F_16 ( V_39 ) ;
if ( ! V_40 ) {
F_9 ( L_12 , V_42 + 1 ) ;
if ( V_42 < 2 )
goto V_44;
else
break;
}
}
V_41 = V_33 -> V_45 -> V_46 -> V_47 >> 9 ;
if ( ( V_38 [ 0 ] -> V_26 > V_41 ) ||
( ( V_38 [ 0 ] -> V_26 + V_38 [ 0 ] -> V_27 ) > V_41 ) ) {
F_4 ( L_13 ) ;
goto V_44;
}
if ( ( V_38 [ 0 ] -> V_24 > V_38 [ 0 ] -> V_26 ) ||
( ( V_38 [ 0 ] -> V_24 + V_38 [ 0 ] -> V_25 )
> V_38 [ 0 ] -> V_26 ) ) {
F_4 ( L_14 ) ;
goto V_44;
}
if ( ! F_10 ( V_38 [ 0 ] , V_38 [ 1 ] ) ) {
F_4 ( L_15 ) ;
goto V_44;
}
F_5 ( L_16 ) ;
V_40 = true ;
V_44:
F_17 ( V_38 [ 1 ] ) ;
F_17 ( V_38 [ 2 ] ) ;
return V_40 ;
}
static bool F_18 ( struct V_32 * V_33 ,
unsigned long V_48 , struct V_49 * V_50 )
{
static const int V_34 [ 4 ] = { V_51 , V_52 , V_53 , V_54 } ;
struct V_2 * V_55 [ 4 ] ;
struct V_21 * V_38 ;
T_2 V_39 ;
T_1 * V_1 ;
int V_42 , V_56 ;
bool V_40 = false ;
F_2 ( ! V_33 || ! V_50 ) ;
V_38 = & V_50 -> V_38 ;
V_55 [ 0 ] = & V_50 -> V_3 ;
V_55 [ 1 ] = F_13 ( sizeof( * V_55 [ 1 ] ) * 3 , V_43 ) ;
if ( ! V_55 [ 1 ] ) {
F_4 ( L_10 ) ;
goto V_57;
}
V_55 [ 2 ] = (struct V_2 * ) ( ( T_1 * ) V_55 [ 1 ] + sizeof( * V_55 [ 1 ] ) ) ;
V_55 [ 3 ] = (struct V_2 * ) ( ( T_1 * ) V_55 [ 2 ] + sizeof( * V_55 [ 2 ] ) ) ;
for ( V_56 = V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
V_1 = F_14 ( V_33 , V_48 + V_34 [ V_42 ] , & V_39 ) ;
if ( ! V_1 ) {
F_9 ( L_17 , V_42 ) ;
continue;
}
if ( F_1 ( V_1 , V_55 [ V_56 ] ) )
V_56 ++ ;
F_16 ( V_39 ) ;
}
if ( ! V_56 ) {
F_4 ( L_18 ) ;
goto V_57;
}
if ( ( ( V_55 [ 0 ] -> V_6 + V_55 [ 0 ] -> V_7 ) > V_38 -> V_27 ) ||
( ( V_55 [ 0 ] -> V_10 + V_55 [ 0 ] -> V_11 ) >
V_38 -> V_27 ) ) {
F_4 ( L_19 ) ;
goto V_57;
}
for ( V_42 = 1 ; V_42 < V_56 ; V_42 ++ ) {
if ( ! F_11 ( V_55 [ 0 ] , V_55 [ V_42 ] ) ) {
F_4 ( L_20 , V_42 ) ;
goto V_57;
}
}
F_5 ( L_21 , V_56 ) ;
V_40 = true ;
V_57:
F_17 ( V_55 [ 1 ] ) ;
return V_40 ;
}
static bool F_19 ( struct V_32 * V_33 ,
unsigned long V_48 , struct V_49 * V_50 )
{
T_2 V_39 ;
T_1 * V_1 ;
bool V_40 = false ;
struct V_13 * V_14 ;
struct V_2 * V_3 ;
F_2 ( ! V_33 || ! V_50 ) ;
V_14 = & V_50 -> V_14 ;
V_3 = & V_50 -> V_3 ;
V_1 = F_14 ( V_33 , V_48 + V_58 , & V_39 ) ;
if ( ! V_1 ) {
F_4 ( L_11 ) ;
return false ;
}
if ( ! F_6 ( V_1 , V_14 ) )
goto V_44;
if ( F_8 ( V_1 + 0x10 ) != 0x01 ) {
F_4 ( L_22 ) ;
goto V_44;
}
if ( V_14 -> V_19 != 512 )
F_20 ( L_23 , V_14 -> V_19 ) ;
if ( ( V_14 -> V_18 * V_14 -> V_20 ) > ( V_3 -> V_7 << 9 ) ) {
F_4 ( L_24
L_25 ) ;
goto V_44;
}
V_40 = true ;
V_44:
F_16 ( V_39 ) ;
return V_40 ;
}
static bool F_21 ( struct V_32 * V_33 )
{
T_2 V_39 ;
T_1 * V_1 ;
struct V_59 * V_60 ;
int V_42 ;
bool V_40 = false ;
F_2 ( ! V_33 ) ;
V_1 = F_14 ( V_33 , 0 , & V_39 ) ;
if ( ! V_1 ) {
F_20 ( L_11 ) ;
return false ;
}
if ( * ( V_61 * ) ( V_1 + 0x01FE ) != F_22 ( V_62 ) )
goto V_44;
V_60 = (struct V_59 * ) ( V_1 + 0x01BE ) ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ , V_60 ++ )
if ( F_23 ( V_60 ) == V_63 ) {
V_40 = true ;
break;
}
if ( V_40 )
F_5 ( L_26 ) ;
V_44:
F_16 ( V_39 ) ;
return V_40 ;
}
static struct V_64 * F_24 ( const struct V_49 * V_50 )
{
struct V_65 * V_66 ;
F_2 ( ! V_50 ) ;
F_25 (item, &ldb->v_disk) {
struct V_64 * V_67 = F_26 ( V_66 , struct V_64 , V_68 ) ;
if ( ! memcmp ( V_67 -> V_64 . V_69 . V_28 , V_50 -> V_38 . V_28 , V_29 ) )
return V_67 ;
}
return NULL ;
}
static bool F_27 ( struct V_32 * V_70 ,
const struct V_49 * V_50 )
{
struct V_65 * V_66 ;
struct V_64 * V_71 ;
struct V_64 * V_69 ;
struct V_72 * V_73 ;
int V_74 = 1 ;
F_2 ( ! V_70 || ! V_50 ) ;
V_69 = F_24 ( V_50 ) ;
if ( ! V_69 ) {
F_4 ( L_27 ) ;
return false ;
}
F_28 ( V_70 -> V_75 , L_28 , V_76 ) ;
F_25 (item, &ldb->v_part) {
V_71 = F_26 ( V_66 , struct V_64 , V_68 ) ;
V_73 = & V_71 -> V_64 . V_73 ;
if ( V_73 -> V_28 != V_69 -> V_77 )
continue;
F_29 ( V_70 , V_74 , V_50 -> V_38 . V_24 +
V_73 -> V_78 , V_73 -> V_79 ) ;
V_74 ++ ;
}
F_28 ( V_70 -> V_75 , L_29 , V_76 ) ;
return true ;
}
static int F_30 ( const T_1 * V_80 , int V_81 , int V_48 , int V_82 )
{
V_48 += V_82 ;
if ( ! V_80 || V_82 < 0 || V_48 > V_81 ) {
if ( ! V_80 )
F_9 ( L_30 ) ;
if ( V_82 < 0 )
F_9 ( L_31 , V_82 ) ;
if ( V_48 > V_81 )
F_9 ( L_32 , V_48 , V_81 ) ;
return - 1 ;
}
if ( V_48 + V_80 [ V_48 ] >= V_81 ) {
F_9 ( L_33 , V_48 ,
V_80 [ V_48 ] , V_81 ) ;
return - 1 ;
}
return V_80 [ V_48 ] + V_82 + 1 ;
}
static T_3 F_31 ( const T_1 * V_83 )
{
T_3 V_84 = 0 ;
T_1 V_85 ;
F_2 ( ! V_83 ) ;
V_85 = * V_83 ++ ;
if ( V_85 && V_85 <= 8 )
while ( V_85 -- )
V_84 = ( V_84 << 8 ) | * V_83 ++ ;
else
F_9 ( L_34 , V_85 ) ;
return V_84 ;
}
static int F_32 ( const T_1 * V_83 , T_1 * V_80 , int V_81 )
{
int V_85 ;
F_2 ( ! V_83 || ! V_80 ) ;
V_85 = V_83 [ 0 ] ;
if ( V_85 >= V_81 ) {
F_9 ( L_35 , V_85 , V_81 ) ;
V_85 = V_81 - 1 ;
}
memcpy ( V_80 , V_83 + 1 , V_85 ) ;
V_80 [ V_85 ] = 0 ;
return V_85 ;
}
static bool F_33 ( const T_1 * V_80 , int V_81 , struct V_64 * V_71 )
{
int V_86 , V_87 , V_88 , V_89 , V_90 , V_91 , V_92 , V_93 ;
struct V_94 * V_95 ;
F_2 ( ! V_80 || ! V_71 ) ;
V_86 = F_30 ( V_80 , V_81 , 0x18 , 0 ) ;
V_87 = F_30 ( V_80 , V_81 , 0x18 , V_86 ) ;
V_88 = F_30 ( V_80 , V_81 , 0x18 , V_87 ) ;
V_89 = F_30 ( V_80 , V_81 , 0x1D , V_88 ) ;
V_90 = F_30 ( V_80 , V_81 , 0x2D , V_89 ) ;
if ( V_80 [ 0x12 ] & V_96 ) {
V_91 = F_30 ( V_80 , V_81 , 0x2E , V_90 ) ;
V_92 = F_30 ( V_80 , V_81 , 0x2E , V_91 ) ;
V_93 = V_92 ;
} else {
V_91 = 0 ;
V_92 = 0 ;
V_93 = V_90 ;
}
if ( V_93 < 0 )
return false ;
V_93 += V_97 ;
if ( V_93 != F_7 ( V_80 + 0x14 ) )
return false ;
V_95 = & V_71 -> V_64 . V_95 ;
F_32 ( V_80 + 0x18 + V_87 , V_95 -> V_33 ,
sizeof ( V_95 -> V_33 ) ) ;
V_95 -> type = V_80 [ 0x18 + V_88 ] ;
V_95 -> V_98 = F_31 ( V_80 + 0x1D + V_88 ) ;
V_95 -> V_99 = F_31 ( V_80 + 0x2D + V_89 ) ;
V_95 -> V_100 = V_91 ? F_31 ( V_80 + V_90 + 0x2E ) : 0 ;
return true ;
}
static int F_34 ( const T_1 * V_80 , int V_81 , struct V_64 * V_71 )
{
int V_86 , V_87 , V_101 , V_102 , V_103 , V_93 ;
struct V_104 * V_105 ;
F_2 ( ! V_80 || ! V_71 ) ;
V_86 = F_30 ( V_80 , V_81 , 0x18 , 0 ) ;
V_87 = F_30 ( V_80 , V_81 , 0x18 , V_86 ) ;
V_101 = F_30 ( V_80 , V_81 , 0x18 , V_87 ) ;
if ( V_80 [ 0x12 ] & V_106 ) {
V_102 = F_30 ( V_80 , V_81 , 0x24 , V_101 ) ;
V_103 = F_30 ( V_80 , V_81 , 0x24 , V_102 ) ;
V_93 = V_103 ;
} else {
V_102 = 0 ;
V_103 = 0 ;
V_93 = V_101 ;
}
if ( V_93 < 0 )
return false ;
V_93 += V_107 ;
if ( V_93 != F_7 ( V_80 + 0x14 ) )
return false ;
V_105 = & V_71 -> V_64 . V_105 ;
F_32 ( V_80 + 0x18 + V_87 , V_105 -> V_28 ,
sizeof ( V_105 -> V_28 ) ) ;
return true ;
}
static bool F_35 ( const T_1 * V_80 , int V_81 , struct V_64 * V_71 )
{
char V_108 [ 64 ] ;
int V_86 , V_87 , V_102 , V_103 , V_93 ;
struct V_104 * V_105 ;
F_2 ( ! V_80 || ! V_71 ) ;
V_86 = F_30 ( V_80 , V_81 , 0x18 , 0 ) ;
V_87 = F_30 ( V_80 , V_81 , 0x18 , V_86 ) ;
if ( V_80 [ 0x12 ] & V_109 ) {
V_102 = F_30 ( V_80 , V_81 , 0x44 , V_87 ) ;
V_103 = F_30 ( V_80 , V_81 , 0x44 , V_102 ) ;
V_93 = V_103 ;
} else {
V_102 = 0 ;
V_103 = 0 ;
V_93 = V_87 ;
}
if ( V_93 < 0 )
return false ;
V_93 += V_110 ;
if ( V_93 != F_7 ( V_80 + 0x14 ) )
return false ;
V_105 = & V_71 -> V_64 . V_105 ;
F_32 ( V_80 + 0x18 + V_86 , V_108 , sizeof ( V_108 ) ) ;
return true ;
}
static bool F_36 ( const T_1 * V_80 , int V_81 , struct V_64 * V_71 )
{
int V_86 , V_87 , V_101 , V_111 , V_93 ;
struct V_112 * V_69 ;
F_2 ( ! V_80 || ! V_71 ) ;
V_86 = F_30 ( V_80 , V_81 , 0x18 , 0 ) ;
V_87 = F_30 ( V_80 , V_81 , 0x18 , V_86 ) ;
V_101 = F_30 ( V_80 , V_81 , 0x18 , V_87 ) ;
V_111 = F_30 ( V_80 , V_81 , 0x18 , V_101 ) ;
V_93 = V_111 ;
if ( V_93 < 0 )
return false ;
V_93 += V_113 ;
if ( V_93 != F_7 ( V_80 + 0x14 ) )
return false ;
V_69 = & V_71 -> V_64 . V_69 ;
F_32 ( V_80 + 0x18 + V_101 , V_69 -> V_114 ,
sizeof ( V_69 -> V_114 ) ) ;
if ( F_37 ( V_80 + 0x19 + V_87 , ( V_115 * ) V_69 -> V_28 ) )
return false ;
return true ;
}
static bool F_38 ( const T_1 * V_80 , int V_81 , struct V_64 * V_71 )
{
int V_86 , V_87 , V_93 ;
struct V_112 * V_69 ;
F_2 ( ! V_80 || ! V_71 ) ;
V_86 = F_30 ( V_80 , V_81 , 0x18 , 0 ) ;
V_87 = F_30 ( V_80 , V_81 , 0x18 , V_86 ) ;
V_93 = V_87 ;
if ( V_93 < 0 )
return false ;
V_93 += V_116 ;
if ( V_93 != F_7 ( V_80 + 0x14 ) )
return false ;
V_69 = & V_71 -> V_64 . V_69 ;
memcpy ( V_69 -> V_28 , V_80 + 0x18 + V_87 , V_29 ) ;
return true ;
}
static bool F_39 ( const T_1 * V_80 , int V_81 , struct V_64 * V_71 )
{
int V_86 , V_87 , V_117 , V_90 , V_101 , V_118 , V_93 ;
struct V_72 * V_73 ;
F_2 ( ! V_80 || ! V_71 ) ;
V_86 = F_30 ( V_80 , V_81 , 0x18 , 0 ) ;
if ( V_86 < 0 ) {
F_9 ( L_36 , V_86 ) ;
return false ;
}
V_87 = F_30 ( V_80 , V_81 , 0x18 , V_86 ) ;
if ( V_87 < 0 ) {
F_9 ( L_37 , V_87 ) ;
return false ;
}
V_117 = F_30 ( V_80 , V_81 , 0x34 , V_87 ) ;
if ( V_117 < 0 ) {
F_9 ( L_38 , V_117 ) ;
return false ;
}
V_90 = F_30 ( V_80 , V_81 , 0x34 , V_117 ) ;
if ( V_90 < 0 ) {
F_9 ( L_39 , V_90 ) ;
return false ;
}
V_101 = F_30 ( V_80 , V_81 , 0x34 , V_90 ) ;
if ( V_101 < 0 ) {
F_9 ( L_40 , V_101 ) ;
return false ;
}
if ( V_80 [ 0x12 ] & V_119 ) {
V_118 = F_30 ( V_80 , V_81 , 0x34 , V_101 ) ;
if ( V_118 < 0 ) {
F_9 ( L_41 , V_118 ) ;
return false ;
}
V_93 = V_118 ;
} else {
V_118 = 0 ;
V_93 = V_101 ;
}
if ( V_93 < 0 ) {
F_9 ( L_42 , V_93 ) ;
return false ;
}
V_93 += V_120 ;
if ( V_93 > F_7 ( V_80 + 0x14 ) ) {
F_9 ( L_43 , V_93 ,
F_7 ( V_80 + 0x14 ) ) ;
return false ;
}
V_73 = & V_71 -> V_64 . V_73 ;
V_73 -> V_78 = F_3 ( V_80 + 0x24 + V_87 ) ;
V_73 -> V_121 = F_3 ( V_80 + 0x2C + V_87 ) ;
V_73 -> V_79 = F_31 ( V_80 + 0x34 + V_87 ) ;
V_73 -> V_99 = F_31 ( V_80 + 0x34 + V_117 ) ;
V_73 -> V_28 = F_31 ( V_80 + 0x34 + V_90 ) ;
if ( V_71 -> V_122 & V_119 )
V_73 -> V_123 = V_80 [ 0x35 + V_101 ] ;
else
V_73 -> V_123 = 0 ;
return true ;
}
static bool F_40 ( const T_1 * V_80 , int V_81 , struct V_64 * V_71 )
{
int V_86 , V_87 , V_124 , V_125 , V_89 , V_117 ;
int V_102 , V_103 , V_126 , V_127 , V_93 ;
struct V_128 * V_129 ;
F_2 ( ! V_80 || ! V_71 ) ;
V_86 = F_30 ( V_80 , V_81 , 0x18 , 0 ) ;
if ( V_86 < 0 ) {
F_9 ( L_36 , V_86 ) ;
return false ;
}
V_87 = F_30 ( V_80 , V_81 , 0x18 , V_86 ) ;
if ( V_87 < 0 ) {
F_9 ( L_37 , V_87 ) ;
return false ;
}
V_124 = F_30 ( V_80 , V_81 , 0x18 , V_87 ) ;
if ( V_124 < 0 ) {
F_9 ( L_44 , V_124 ) ;
return false ;
}
V_125 = F_30 ( V_80 , V_81 , 0x18 , V_124 ) ;
if ( V_125 < 0 ) {
F_9 ( L_45 ,
V_125 ) ;
return false ;
}
V_89 = F_30 ( V_80 , V_81 , 0x2D , V_125 ) ;
if ( V_89 < 0 ) {
F_9 ( L_46 , V_89 ) ;
return false ;
}
V_117 = F_30 ( V_80 , V_81 , 0x3D , V_89 ) ;
if ( V_117 < 0 ) {
F_9 ( L_38 , V_117 ) ;
return false ;
}
if ( V_80 [ 0x12 ] & V_130 ) {
V_102 = F_30 ( V_80 , V_81 , 0x52 , V_117 ) ;
if ( V_102 < 0 ) {
F_9 ( L_47 , V_102 ) ;
return false ;
}
} else
V_102 = V_117 ;
if ( V_80 [ 0x12 ] & V_131 ) {
V_103 = F_30 ( V_80 , V_81 , 0x52 , V_102 ) ;
if ( V_103 < 0 ) {
F_9 ( L_48 , V_103 ) ;
return false ;
}
} else
V_103 = V_102 ;
if ( V_80 [ 0x12 ] & V_132 ) {
V_126 = F_30 ( V_80 , V_81 , 0x52 , V_103 ) ;
if ( V_126 < 0 ) {
F_9 ( L_49 , V_126 ) ;
return false ;
}
} else
V_126 = V_103 ;
if ( V_80 [ 0x12 ] & V_133 ) {
V_127 = F_30 ( V_80 , V_81 , 0x52 , V_126 ) ;
if ( V_127 < 0 ) {
F_9 ( L_50 , V_127 ) ;
return false ;
}
} else
V_127 = V_126 ;
V_93 = V_127 ;
if ( V_93 < 0 ) {
F_9 ( L_42 , V_93 ) ;
return false ;
}
V_93 += V_134 ;
if ( V_93 > F_7 ( V_80 + 0x14 ) ) {
F_9 ( L_43 , V_93 ,
F_7 ( V_80 + 0x14 ) ) ;
return false ;
}
V_129 = & V_71 -> V_64 . V_129 ;
F_32 ( V_80 + 0x18 + V_87 , V_129 -> V_135 ,
sizeof( V_129 -> V_135 ) ) ;
memcpy ( V_129 -> V_136 , V_80 + 0x18 + V_125 ,
sizeof( V_129 -> V_136 ) ) ;
V_129 -> V_79 = F_31 ( V_80 + 0x3D + V_89 ) ;
V_129 -> V_137 = V_80 [ 0x41 + V_117 ] ;
memcpy ( V_129 -> V_138 , V_80 + 0x42 + V_117 , sizeof( V_129 -> V_138 ) ) ;
if ( V_80 [ 0x12 ] & V_133 ) {
F_32 ( V_80 + 0x52 + V_117 , V_129 -> V_139 ,
sizeof( V_129 -> V_139 ) ) ;
}
return true ;
}
static bool F_41 ( const T_1 * V_108 , int V_93 , struct V_64 * V_71 )
{
bool V_40 = false ;
int V_86 ;
F_2 ( ! V_108 || ! V_71 ) ;
V_86 = F_30 ( V_108 , V_93 , 0x18 , 0 ) ;
if ( V_86 < 0 ) {
F_9 ( L_51 ) ;
return false ;
}
V_71 -> V_122 = V_108 [ 0x12 ] ;
V_71 -> type = V_108 [ 0x13 ] ;
V_71 -> V_77 = F_31 ( V_108 + 0x18 ) ;
F_32 ( V_108 + 0x18 + V_86 , V_71 -> V_140 , sizeof ( V_71 -> V_140 ) ) ;
switch ( V_71 -> type ) {
case V_141 : V_40 = F_33 ( V_108 , V_93 , V_71 ) ; break;
case V_142 : V_40 = F_36 ( V_108 , V_93 , V_71 ) ; break;
case V_143 : V_40 = F_38 ( V_108 , V_93 , V_71 ) ; break;
case V_144 : V_40 = F_34 ( V_108 , V_93 , V_71 ) ; break;
case V_145 : V_40 = F_35 ( V_108 , V_93 , V_71 ) ; break;
case V_146 : V_40 = F_39 ( V_108 , V_93 , V_71 ) ; break;
case V_147 : V_40 = F_40 ( V_108 , V_93 , V_71 ) ; break;
}
if ( V_40 )
F_5 ( L_52 ,
( unsigned long long ) V_71 -> V_77 , V_71 -> type ) ;
else
F_9 ( L_53 ,
( unsigned long long ) V_71 -> V_77 , V_71 -> type ) ;
return V_40 ;
}
static bool F_42 ( T_1 * V_1 , int V_93 , struct V_49 * V_50 )
{
struct V_64 * V_71 ;
struct V_65 * V_66 ;
F_2 ( ! V_1 || ! V_50 ) ;
V_71 = F_13 ( sizeof ( * V_71 ) , V_43 ) ;
if ( ! V_71 ) {
F_4 ( L_10 ) ;
return false ;
}
if ( ! F_41 ( V_1 , V_93 , V_71 ) ) {
F_17 ( V_71 ) ;
return false ;
}
switch ( V_71 -> type ) {
case V_144 :
case V_145 :
F_43 ( & V_71 -> V_68 , & V_50 -> V_148 ) ;
break;
case V_142 :
case V_143 :
F_43 ( & V_71 -> V_68 , & V_50 -> V_149 ) ;
break;
case V_147 :
F_43 ( & V_71 -> V_68 , & V_50 -> V_150 ) ;
break;
case V_141 :
F_43 ( & V_71 -> V_68 , & V_50 -> V_151 ) ;
break;
case V_146 :
F_25 (item, &ldb->v_part) {
struct V_64 * V_67 = F_26 ( V_66 , struct V_64 , V_68 ) ;
if ( ( V_67 -> V_64 . V_73 . V_28 == V_71 -> V_64 . V_73 . V_28 ) &&
( V_67 -> V_64 . V_73 . V_78 > V_71 -> V_64 . V_73 . V_78 ) ) {
F_44 ( & V_71 -> V_68 , & V_67 -> V_68 ) ;
return true ;
}
}
F_44 ( & V_71 -> V_68 , & V_50 -> V_152 ) ;
break;
}
return true ;
}
static bool F_45 ( const T_1 * V_1 , int V_79 , struct V_65 * V_153 )
{
struct V_154 * V_155 ;
struct V_65 * V_66 ;
int V_156 , V_157 , V_158 ;
F_2 ( ! V_1 || ! V_153 ) ;
if ( V_79 < 2 * V_159 ) {
F_9 ( L_54 ) ;
return false ;
}
V_158 = F_7 ( V_1 + 0x08 ) ;
V_156 = F_8 ( V_1 + 0x0C ) ;
V_157 = F_8 ( V_1 + 0x0E ) ;
if ( ( V_157 < 1 ) || ( V_157 > 4 ) ) {
F_9 ( L_55 , V_157 ) ;
return false ;
}
if ( V_156 >= V_157 ) {
F_9 ( L_56 , V_156 , V_157 ) ;
return false ;
}
F_25 (item, frags) {
V_155 = F_26 ( V_66 , struct V_154 , V_68 ) ;
if ( V_155 -> V_158 == V_158 )
goto V_160;
}
V_155 = F_13 ( sizeof ( * V_155 ) + V_79 * V_157 , V_43 ) ;
if ( ! V_155 ) {
F_4 ( L_10 ) ;
return false ;
}
V_155 -> V_158 = V_158 ;
V_155 -> V_157 = V_157 ;
V_155 -> V_156 = V_156 ;
V_155 -> V_161 = 0xFF << V_157 ;
F_44 ( & V_155 -> V_68 , V_153 ) ;
V_160:
if ( V_156 >= V_155 -> V_157 ) {
F_9 ( L_56 , V_156 , V_155 -> V_157 ) ;
return false ;
}
if ( V_155 -> V_161 & ( 1 << V_156 ) ) {
F_9 ( L_57 , V_156 ) ;
V_155 -> V_161 &= 0x7F ;
return false ;
}
V_155 -> V_161 |= ( 1 << V_156 ) ;
if ( ! V_156 )
memcpy ( V_155 -> V_1 , V_1 , V_159 ) ;
V_1 += V_159 ;
V_79 -= V_159 ;
memcpy ( V_155 -> V_1 + V_159 + V_156 * V_79 , V_1 , V_79 ) ;
return true ;
}
static void F_46 ( struct V_65 * V_68 )
{
struct V_65 * V_66 , * V_84 ;
F_2 ( ! V_68 ) ;
F_47 (item, tmp, list)
F_17 ( F_26 ( V_66 , struct V_154 , V_68 ) ) ;
}
static bool F_48 ( struct V_65 * V_153 , struct V_49 * V_50 )
{
struct V_154 * V_155 ;
struct V_65 * V_66 ;
F_2 ( ! V_153 || ! V_50 ) ;
F_25 (item, frags) {
V_155 = F_26 ( V_66 , struct V_154 , V_68 ) ;
if ( V_155 -> V_161 != 0xFF ) {
F_9 ( L_58 ,
V_155 -> V_158 , V_155 -> V_161 ) ;
return false ;
}
if ( ! F_42 ( V_155 -> V_1 , V_155 -> V_157 * V_50 -> V_14 . V_18 , V_50 ) )
return false ;
}
return true ;
}
static bool F_49 ( struct V_32 * V_33 , unsigned long V_48 ,
struct V_49 * V_50 )
{
int V_79 , V_162 , V_163 , V_164 , V_165 , V_67 , V_166 ;
T_1 * V_1 = NULL ;
T_2 V_39 ;
bool V_40 = false ;
F_50 ( V_153 ) ;
F_2 ( ! V_33 || ! V_50 ) ;
V_79 = V_50 -> V_14 . V_18 ;
V_162 = 512 / V_79 ;
V_163 = V_50 -> V_14 . V_19 >> 9 ;
V_164 = ( V_79 * V_50 -> V_14 . V_20 ) >> 9 ;
for ( V_165 = V_163 ; V_165 < V_164 ; V_165 ++ ) {
V_1 = F_14 ( V_33 , V_48 + V_58 + V_165 , & V_39 ) ;
if ( ! V_1 ) {
F_4 ( L_11 ) ;
goto V_44;
}
for ( V_67 = 0 ; V_67 < V_162 ; V_67 ++ , V_1 += V_79 ) {
if ( V_167 != F_7 ( V_1 ) ) {
F_9 ( L_59 ) ;
goto V_44;
}
V_166 = F_8 ( V_1 + 0x0E ) ;
if ( V_166 == 1 ) {
if ( ! F_42 ( V_1 , V_79 , V_50 ) )
goto V_44;
} else if ( V_166 > 1 ) {
if ( ! F_45 ( V_1 , V_79 , & V_153 ) )
goto V_44;
}
}
F_16 ( V_39 ) ;
V_1 = NULL ;
}
V_40 = F_48 ( & V_153 , V_50 ) ;
V_44:
if ( V_1 )
F_16 ( V_39 ) ;
F_46 ( & V_153 ) ;
return V_40 ;
}
static void F_51 ( struct V_65 * V_168 )
{
struct V_65 * V_66 , * V_84 ;
F_2 ( ! V_168 ) ;
F_47 (item, tmp, lh)
F_17 ( F_26 ( V_66 , struct V_64 , V_68 ) ) ;
}
int F_52 ( struct V_32 * V_33 )
{
struct V_49 * V_50 ;
unsigned long V_48 ;
int V_40 = - 1 ;
F_2 ( ! V_33 ) ;
if ( ! F_21 ( V_33 ) )
return 0 ;
V_50 = F_13 ( sizeof ( * V_50 ) , V_43 ) ;
if ( ! V_50 ) {
F_4 ( L_10 ) ;
goto V_44;
}
if ( ! F_12 ( V_33 , & V_50 -> V_38 ) )
goto V_44;
V_48 = V_50 -> V_38 . V_26 ;
if ( ! F_18 ( V_33 , V_48 , V_50 ) ||
! F_19 ( V_33 , V_48 , V_50 ) )
goto V_44;
F_53 ( & V_50 -> V_148 ) ;
F_53 ( & V_50 -> V_149 ) ;
F_53 ( & V_50 -> V_150 ) ;
F_53 ( & V_50 -> V_151 ) ;
F_53 ( & V_50 -> V_152 ) ;
if ( ! F_49 ( V_33 , V_48 , V_50 ) ) {
F_4 ( L_60 ) ;
goto V_169;
}
if ( F_27 ( V_33 , V_50 ) ) {
F_5 ( L_61 ) ;
V_40 = 1 ;
}
V_169:
F_51 ( & V_50 -> V_148 ) ;
F_51 ( & V_50 -> V_149 ) ;
F_51 ( & V_50 -> V_150 ) ;
F_51 ( & V_50 -> V_151 ) ;
F_51 ( & V_50 -> V_152 ) ;
V_44:
F_17 ( V_50 ) ;
return V_40 ;
}
