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
F_11 ( & V_22 -> V_28 , & V_23 -> V_28 ) ) ;
}
static bool F_12 ( const struct V_2 * V_29 ,
const struct V_2 * V_30 )
{
F_2 ( ! V_29 || ! V_30 ) ;
return ( ( V_29 -> V_6 == V_30 -> V_6 ) &&
( V_29 -> V_7 == V_30 -> V_7 ) &&
( V_29 -> V_10 == V_30 -> V_10 ) &&
( V_29 -> V_11 == V_30 -> V_11 ) &&
! strncmp ( V_29 -> V_5 , V_30 -> V_5 ,
sizeof ( V_29 -> V_5 ) ) &&
! strncmp ( V_29 -> V_9 , V_30 -> V_9 ,
sizeof ( V_29 -> V_9 ) ) ) ;
}
static bool F_13 ( struct V_31 * V_32 ,
struct V_21 * V_22 )
{
static const int V_33 [ 3 ] = { V_34 , V_35 , V_36 } ;
struct V_21 * V_37 [ 3 ] = { V_22 } ;
T_2 V_38 ;
T_1 * V_1 ;
bool V_39 = false ;
long V_40 ;
int V_41 ;
F_2 ( ! V_32 || ! V_22 ) ;
V_37 [ 1 ] = F_14 ( sizeof ( * V_37 [ 1 ] ) , V_42 ) ;
V_37 [ 2 ] = F_14 ( sizeof ( * V_37 [ 2 ] ) , V_42 ) ;
if ( ! V_37 [ 1 ] || ! V_37 [ 2 ] ) {
F_4 ( L_10 ) ;
goto V_43;
}
V_37 [ 0 ] -> V_26 = 0 ;
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ ) {
V_1 = F_15 ( V_32 , V_37 [ 0 ] -> V_26 + V_33 [ V_41 ] ,
& V_38 ) ;
if ( ! V_1 ) {
F_4 ( L_11 ) ;
goto V_43;
}
V_39 = F_16 ( V_1 , V_37 [ V_41 ] ) ;
F_17 ( V_38 ) ;
if ( ! V_39 ) {
F_9 ( L_12 , V_41 + 1 ) ;
if ( V_41 < 2 )
goto V_43;
else
break;
}
}
V_40 = V_32 -> V_44 -> V_45 -> V_46 >> 9 ;
if ( ( V_37 [ 0 ] -> V_26 > V_40 ) ||
( ( V_37 [ 0 ] -> V_26 + V_37 [ 0 ] -> V_27 ) > V_40 ) ) {
F_4 ( L_13 ) ;
goto V_43;
}
if ( ( V_37 [ 0 ] -> V_24 > V_37 [ 0 ] -> V_26 ) ||
( ( V_37 [ 0 ] -> V_24 + V_37 [ 0 ] -> V_25 )
> V_37 [ 0 ] -> V_26 ) ) {
F_4 ( L_14 ) ;
goto V_43;
}
if ( ! F_10 ( V_37 [ 0 ] , V_37 [ 1 ] ) ) {
F_4 ( L_15 ) ;
goto V_43;
}
F_5 ( L_16 ) ;
V_39 = true ;
V_43:
F_18 ( V_37 [ 1 ] ) ;
F_18 ( V_37 [ 2 ] ) ;
return V_39 ;
}
static bool F_19 ( struct V_31 * V_32 ,
unsigned long V_47 , struct V_48 * V_49 )
{
static const int V_33 [ 4 ] = { V_50 , V_51 , V_52 , V_53 } ;
struct V_2 * V_54 [ 4 ] ;
struct V_21 * V_37 ;
T_2 V_38 ;
T_1 * V_1 ;
int V_41 , V_55 ;
bool V_39 = false ;
F_2 ( ! V_32 || ! V_49 ) ;
V_37 = & V_49 -> V_37 ;
V_54 [ 0 ] = & V_49 -> V_3 ;
V_54 [ 1 ] = F_14 ( sizeof( * V_54 [ 1 ] ) * 3 , V_42 ) ;
if ( ! V_54 [ 1 ] ) {
F_4 ( L_10 ) ;
goto V_56;
}
V_54 [ 2 ] = (struct V_2 * ) ( ( T_1 * ) V_54 [ 1 ] + sizeof( * V_54 [ 1 ] ) ) ;
V_54 [ 3 ] = (struct V_2 * ) ( ( T_1 * ) V_54 [ 2 ] + sizeof( * V_54 [ 2 ] ) ) ;
for ( V_55 = V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
V_1 = F_15 ( V_32 , V_47 + V_33 [ V_41 ] , & V_38 ) ;
if ( ! V_1 ) {
F_9 ( L_17 , V_41 ) ;
continue;
}
if ( F_1 ( V_1 , V_54 [ V_55 ] ) )
V_55 ++ ;
F_17 ( V_38 ) ;
}
if ( ! V_55 ) {
F_4 ( L_18 ) ;
goto V_56;
}
if ( ( ( V_54 [ 0 ] -> V_6 + V_54 [ 0 ] -> V_7 ) > V_37 -> V_27 ) ||
( ( V_54 [ 0 ] -> V_10 + V_54 [ 0 ] -> V_11 ) >
V_37 -> V_27 ) ) {
F_4 ( L_19 ) ;
goto V_56;
}
for ( V_41 = 1 ; V_41 < V_55 ; V_41 ++ ) {
if ( ! F_12 ( V_54 [ 0 ] , V_54 [ V_41 ] ) ) {
F_4 ( L_20 , V_41 ) ;
goto V_56;
}
}
F_5 ( L_21 , V_55 ) ;
V_39 = true ;
V_56:
F_18 ( V_54 [ 1 ] ) ;
return V_39 ;
}
static bool F_20 ( struct V_31 * V_32 ,
unsigned long V_47 , struct V_48 * V_49 )
{
T_2 V_38 ;
T_1 * V_1 ;
bool V_39 = false ;
struct V_13 * V_14 ;
struct V_2 * V_3 ;
F_2 ( ! V_32 || ! V_49 ) ;
V_14 = & V_49 -> V_14 ;
V_3 = & V_49 -> V_3 ;
V_1 = F_15 ( V_32 , V_47 + V_57 , & V_38 ) ;
if ( ! V_1 ) {
F_4 ( L_11 ) ;
return false ;
}
if ( ! F_6 ( V_1 , V_14 ) )
goto V_43;
if ( F_8 ( V_1 + 0x10 ) != 0x01 ) {
F_4 ( L_22 ) ;
goto V_43;
}
if ( V_14 -> V_19 != 512 )
F_21 ( L_23 , V_14 -> V_19 ) ;
if ( ( V_14 -> V_18 * V_14 -> V_20 ) > ( V_3 -> V_7 << 9 ) ) {
F_4 ( L_24
L_25 ) ;
goto V_43;
}
V_39 = true ;
V_43:
F_17 ( V_38 ) ;
return V_39 ;
}
static bool F_22 ( struct V_31 * V_32 )
{
T_2 V_38 ;
T_1 * V_1 ;
struct V_58 * V_59 ;
int V_41 ;
bool V_39 = false ;
F_2 ( ! V_32 ) ;
V_1 = F_15 ( V_32 , 0 , & V_38 ) ;
if ( ! V_1 ) {
F_21 ( L_11 ) ;
return false ;
}
if ( * ( V_60 * ) ( V_1 + 0x01FE ) != F_23 ( V_61 ) )
goto V_43;
V_59 = (struct V_58 * ) ( V_1 + 0x01BE ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ , V_59 ++ )
if ( F_24 ( V_59 ) == V_62 ) {
V_39 = true ;
break;
}
if ( V_39 )
F_5 ( L_26 ) ;
V_43:
F_17 ( V_38 ) ;
return V_39 ;
}
static struct V_63 * F_25 ( const struct V_48 * V_49 )
{
struct V_64 * V_65 ;
F_2 ( ! V_49 ) ;
F_26 (item, &ldb->v_disk) {
struct V_63 * V_66 = F_27 ( V_65 , struct V_63 , V_67 ) ;
if ( F_11 ( & V_66 -> V_63 . V_68 . V_28 , & V_49 -> V_37 . V_28 ) )
return V_66 ;
}
return NULL ;
}
static bool F_28 ( struct V_31 * V_69 ,
const struct V_48 * V_49 )
{
struct V_64 * V_65 ;
struct V_63 * V_70 ;
struct V_63 * V_68 ;
struct V_71 * V_72 ;
int V_73 = 1 ;
F_2 ( ! V_69 || ! V_49 ) ;
V_68 = F_25 ( V_49 ) ;
if ( ! V_68 ) {
F_4 ( L_27 ) ;
return false ;
}
F_29 ( V_69 -> V_74 , L_28 , V_75 ) ;
F_26 (item, &ldb->v_part) {
V_70 = F_27 ( V_65 , struct V_63 , V_67 ) ;
V_72 = & V_70 -> V_63 . V_72 ;
if ( V_72 -> V_28 != V_68 -> V_76 )
continue;
F_30 ( V_69 , V_73 , V_49 -> V_37 . V_24 +
V_72 -> V_77 , V_72 -> V_78 ) ;
V_73 ++ ;
}
F_29 ( V_69 -> V_74 , L_29 , V_75 ) ;
return true ;
}
static int F_31 ( const T_1 * V_79 , int V_80 , int V_47 , int V_81 )
{
V_47 += V_81 ;
if ( ! V_79 || V_81 < 0 || V_47 > V_80 ) {
if ( ! V_79 )
F_9 ( L_30 ) ;
if ( V_81 < 0 )
F_9 ( L_31 , V_81 ) ;
if ( V_47 > V_80 )
F_9 ( L_32 , V_47 , V_80 ) ;
return - 1 ;
}
if ( V_47 + V_79 [ V_47 ] >= V_80 ) {
F_9 ( L_33 , V_47 ,
V_79 [ V_47 ] , V_80 ) ;
return - 1 ;
}
return V_79 [ V_47 ] + V_81 + 1 ;
}
static T_3 F_32 ( const T_1 * V_82 )
{
T_3 V_83 = 0 ;
T_1 V_84 ;
F_2 ( ! V_82 ) ;
V_84 = * V_82 ++ ;
if ( V_84 && V_84 <= 8 )
while ( V_84 -- )
V_83 = ( V_83 << 8 ) | * V_82 ++ ;
else
F_9 ( L_34 , V_84 ) ;
return V_83 ;
}
static int F_33 ( const T_1 * V_82 , T_1 * V_79 , int V_80 )
{
int V_84 ;
F_2 ( ! V_82 || ! V_79 ) ;
V_84 = V_82 [ 0 ] ;
if ( V_84 >= V_80 ) {
F_9 ( L_35 , V_84 , V_80 ) ;
V_84 = V_80 - 1 ;
}
memcpy ( V_79 , V_82 + 1 , V_84 ) ;
V_79 [ V_84 ] = 0 ;
return V_84 ;
}
static bool F_34 ( const T_1 * V_79 , int V_80 , struct V_63 * V_70 )
{
int V_85 , V_86 , V_87 , V_88 , V_89 , V_90 , V_91 , V_92 ;
struct V_93 * V_94 ;
F_2 ( ! V_79 || ! V_70 ) ;
V_85 = F_31 ( V_79 , V_80 , 0x18 , 0 ) ;
V_86 = F_31 ( V_79 , V_80 , 0x18 , V_85 ) ;
V_87 = F_31 ( V_79 , V_80 , 0x18 , V_86 ) ;
V_88 = F_31 ( V_79 , V_80 , 0x1D , V_87 ) ;
V_89 = F_31 ( V_79 , V_80 , 0x2D , V_88 ) ;
if ( V_79 [ 0x12 ] & V_95 ) {
V_90 = F_31 ( V_79 , V_80 , 0x2E , V_89 ) ;
V_91 = F_31 ( V_79 , V_80 , 0x2E , V_90 ) ;
V_92 = V_91 ;
} else {
V_90 = 0 ;
V_91 = 0 ;
V_92 = V_89 ;
}
if ( V_92 < 0 )
return false ;
V_92 += V_96 ;
if ( V_92 != F_7 ( V_79 + 0x14 ) )
return false ;
V_94 = & V_70 -> V_63 . V_94 ;
F_33 ( V_79 + 0x18 + V_86 , V_94 -> V_32 ,
sizeof ( V_94 -> V_32 ) ) ;
V_94 -> type = V_79 [ 0x18 + V_87 ] ;
V_94 -> V_97 = F_32 ( V_79 + 0x1D + V_87 ) ;
V_94 -> V_98 = F_32 ( V_79 + 0x2D + V_88 ) ;
V_94 -> V_99 = V_90 ? F_32 ( V_79 + V_89 + 0x2E ) : 0 ;
return true ;
}
static int F_35 ( const T_1 * V_79 , int V_80 , struct V_63 * V_70 )
{
int V_85 , V_86 , V_100 , V_101 , V_102 , V_92 ;
struct V_103 * V_104 ;
F_2 ( ! V_79 || ! V_70 ) ;
V_85 = F_31 ( V_79 , V_80 , 0x18 , 0 ) ;
V_86 = F_31 ( V_79 , V_80 , 0x18 , V_85 ) ;
V_100 = F_31 ( V_79 , V_80 , 0x18 , V_86 ) ;
if ( V_79 [ 0x12 ] & V_105 ) {
V_101 = F_31 ( V_79 , V_80 , 0x24 , V_100 ) ;
V_102 = F_31 ( V_79 , V_80 , 0x24 , V_101 ) ;
V_92 = V_102 ;
} else {
V_101 = 0 ;
V_102 = 0 ;
V_92 = V_100 ;
}
if ( V_92 < 0 )
return false ;
V_92 += V_106 ;
if ( V_92 != F_7 ( V_79 + 0x14 ) )
return false ;
V_104 = & V_70 -> V_63 . V_104 ;
F_33 ( V_79 + 0x18 + V_86 , V_104 -> V_28 ,
sizeof ( V_104 -> V_28 ) ) ;
return true ;
}
static bool F_36 ( const T_1 * V_79 , int V_80 , struct V_63 * V_70 )
{
char V_107 [ 64 ] ;
int V_85 , V_86 , V_101 , V_102 , V_92 ;
struct V_103 * V_104 ;
F_2 ( ! V_79 || ! V_70 ) ;
V_85 = F_31 ( V_79 , V_80 , 0x18 , 0 ) ;
V_86 = F_31 ( V_79 , V_80 , 0x18 , V_85 ) ;
if ( V_79 [ 0x12 ] & V_108 ) {
V_101 = F_31 ( V_79 , V_80 , 0x44 , V_86 ) ;
V_102 = F_31 ( V_79 , V_80 , 0x44 , V_101 ) ;
V_92 = V_102 ;
} else {
V_101 = 0 ;
V_102 = 0 ;
V_92 = V_86 ;
}
if ( V_92 < 0 )
return false ;
V_92 += V_109 ;
if ( V_92 != F_7 ( V_79 + 0x14 ) )
return false ;
V_104 = & V_70 -> V_63 . V_104 ;
F_33 ( V_79 + 0x18 + V_85 , V_107 , sizeof ( V_107 ) ) ;
return true ;
}
static bool F_37 ( const T_1 * V_79 , int V_80 , struct V_63 * V_70 )
{
int V_85 , V_86 , V_100 , V_110 , V_92 ;
struct V_111 * V_68 ;
F_2 ( ! V_79 || ! V_70 ) ;
V_85 = F_31 ( V_79 , V_80 , 0x18 , 0 ) ;
V_86 = F_31 ( V_79 , V_80 , 0x18 , V_85 ) ;
V_100 = F_31 ( V_79 , V_80 , 0x18 , V_86 ) ;
V_110 = F_31 ( V_79 , V_80 , 0x18 , V_100 ) ;
V_92 = V_110 ;
if ( V_92 < 0 )
return false ;
V_92 += V_112 ;
if ( V_92 != F_7 ( V_79 + 0x14 ) )
return false ;
V_68 = & V_70 -> V_63 . V_68 ;
F_33 ( V_79 + 0x18 + V_100 , V_68 -> V_113 ,
sizeof ( V_68 -> V_113 ) ) ;
if ( F_38 ( V_79 + 0x19 + V_86 , & V_68 -> V_28 ) )
return false ;
return true ;
}
static bool F_39 ( const T_1 * V_79 , int V_80 , struct V_63 * V_70 )
{
int V_85 , V_86 , V_92 ;
struct V_111 * V_68 ;
F_2 ( ! V_79 || ! V_70 ) ;
V_85 = F_31 ( V_79 , V_80 , 0x18 , 0 ) ;
V_86 = F_31 ( V_79 , V_80 , 0x18 , V_85 ) ;
V_92 = V_86 ;
if ( V_92 < 0 )
return false ;
V_92 += V_114 ;
if ( V_92 != F_7 ( V_79 + 0x14 ) )
return false ;
V_68 = & V_70 -> V_63 . V_68 ;
F_40 ( & V_68 -> V_28 , ( V_115 * ) ( V_79 + 0x18 + V_86 ) ) ;
return true ;
}
static bool F_41 ( const T_1 * V_79 , int V_80 , struct V_63 * V_70 )
{
int V_85 , V_86 , V_116 , V_89 , V_100 , V_117 , V_92 ;
struct V_71 * V_72 ;
F_2 ( ! V_79 || ! V_70 ) ;
V_85 = F_31 ( V_79 , V_80 , 0x18 , 0 ) ;
if ( V_85 < 0 ) {
F_9 ( L_36 , V_85 ) ;
return false ;
}
V_86 = F_31 ( V_79 , V_80 , 0x18 , V_85 ) ;
if ( V_86 < 0 ) {
F_9 ( L_37 , V_86 ) ;
return false ;
}
V_116 = F_31 ( V_79 , V_80 , 0x34 , V_86 ) ;
if ( V_116 < 0 ) {
F_9 ( L_38 , V_116 ) ;
return false ;
}
V_89 = F_31 ( V_79 , V_80 , 0x34 , V_116 ) ;
if ( V_89 < 0 ) {
F_9 ( L_39 , V_89 ) ;
return false ;
}
V_100 = F_31 ( V_79 , V_80 , 0x34 , V_89 ) ;
if ( V_100 < 0 ) {
F_9 ( L_40 , V_100 ) ;
return false ;
}
if ( V_79 [ 0x12 ] & V_118 ) {
V_117 = F_31 ( V_79 , V_80 , 0x34 , V_100 ) ;
if ( V_117 < 0 ) {
F_9 ( L_41 , V_117 ) ;
return false ;
}
V_92 = V_117 ;
} else {
V_117 = 0 ;
V_92 = V_100 ;
}
if ( V_92 < 0 ) {
F_9 ( L_42 , V_92 ) ;
return false ;
}
V_92 += V_119 ;
if ( V_92 > F_7 ( V_79 + 0x14 ) ) {
F_9 ( L_43 , V_92 ,
F_7 ( V_79 + 0x14 ) ) ;
return false ;
}
V_72 = & V_70 -> V_63 . V_72 ;
V_72 -> V_77 = F_3 ( V_79 + 0x24 + V_86 ) ;
V_72 -> V_120 = F_3 ( V_79 + 0x2C + V_86 ) ;
V_72 -> V_78 = F_32 ( V_79 + 0x34 + V_86 ) ;
V_72 -> V_98 = F_32 ( V_79 + 0x34 + V_116 ) ;
V_72 -> V_28 = F_32 ( V_79 + 0x34 + V_89 ) ;
if ( V_70 -> V_121 & V_118 )
V_72 -> V_122 = V_79 [ 0x35 + V_100 ] ;
else
V_72 -> V_122 = 0 ;
return true ;
}
static bool F_42 ( const T_1 * V_79 , int V_80 , struct V_63 * V_70 )
{
int V_85 , V_86 , V_123 , V_124 , V_88 , V_116 ;
int V_101 , V_102 , V_125 , V_126 , V_92 ;
struct V_127 * V_128 ;
F_2 ( ! V_79 || ! V_70 ) ;
V_85 = F_31 ( V_79 , V_80 , 0x18 , 0 ) ;
if ( V_85 < 0 ) {
F_9 ( L_36 , V_85 ) ;
return false ;
}
V_86 = F_31 ( V_79 , V_80 , 0x18 , V_85 ) ;
if ( V_86 < 0 ) {
F_9 ( L_37 , V_86 ) ;
return false ;
}
V_123 = F_31 ( V_79 , V_80 , 0x18 , V_86 ) ;
if ( V_123 < 0 ) {
F_9 ( L_44 , V_123 ) ;
return false ;
}
V_124 = F_31 ( V_79 , V_80 , 0x18 , V_123 ) ;
if ( V_124 < 0 ) {
F_9 ( L_45 ,
V_124 ) ;
return false ;
}
V_88 = F_31 ( V_79 , V_80 , 0x2D , V_124 ) ;
if ( V_88 < 0 ) {
F_9 ( L_46 , V_88 ) ;
return false ;
}
V_116 = F_31 ( V_79 , V_80 , 0x3D , V_88 ) ;
if ( V_116 < 0 ) {
F_9 ( L_38 , V_116 ) ;
return false ;
}
if ( V_79 [ 0x12 ] & V_129 ) {
V_101 = F_31 ( V_79 , V_80 , 0x52 , V_116 ) ;
if ( V_101 < 0 ) {
F_9 ( L_47 , V_101 ) ;
return false ;
}
} else
V_101 = V_116 ;
if ( V_79 [ 0x12 ] & V_130 ) {
V_102 = F_31 ( V_79 , V_80 , 0x52 , V_101 ) ;
if ( V_102 < 0 ) {
F_9 ( L_48 , V_102 ) ;
return false ;
}
} else
V_102 = V_101 ;
if ( V_79 [ 0x12 ] & V_131 ) {
V_125 = F_31 ( V_79 , V_80 , 0x52 , V_102 ) ;
if ( V_125 < 0 ) {
F_9 ( L_49 , V_125 ) ;
return false ;
}
} else
V_125 = V_102 ;
if ( V_79 [ 0x12 ] & V_132 ) {
V_126 = F_31 ( V_79 , V_80 , 0x52 , V_125 ) ;
if ( V_126 < 0 ) {
F_9 ( L_50 , V_126 ) ;
return false ;
}
} else
V_126 = V_125 ;
V_92 = V_126 ;
if ( V_92 < 0 ) {
F_9 ( L_42 , V_92 ) ;
return false ;
}
V_92 += V_133 ;
if ( V_92 > F_7 ( V_79 + 0x14 ) ) {
F_9 ( L_43 , V_92 ,
F_7 ( V_79 + 0x14 ) ) ;
return false ;
}
V_128 = & V_70 -> V_63 . V_128 ;
F_33 ( V_79 + 0x18 + V_86 , V_128 -> V_134 ,
sizeof( V_128 -> V_134 ) ) ;
memcpy ( V_128 -> V_135 , V_79 + 0x18 + V_124 ,
sizeof( V_128 -> V_135 ) ) ;
V_128 -> V_78 = F_32 ( V_79 + 0x3D + V_88 ) ;
V_128 -> V_136 = V_79 [ 0x41 + V_116 ] ;
memcpy ( V_128 -> V_137 , V_79 + 0x42 + V_116 , sizeof( V_128 -> V_137 ) ) ;
if ( V_79 [ 0x12 ] & V_132 ) {
F_33 ( V_79 + 0x52 + V_116 , V_128 -> V_138 ,
sizeof( V_128 -> V_138 ) ) ;
}
return true ;
}
static bool F_43 ( const T_1 * V_107 , int V_92 , struct V_63 * V_70 )
{
bool V_39 = false ;
int V_85 ;
F_2 ( ! V_107 || ! V_70 ) ;
V_85 = F_31 ( V_107 , V_92 , 0x18 , 0 ) ;
if ( V_85 < 0 ) {
F_9 ( L_51 ) ;
return false ;
}
V_70 -> V_121 = V_107 [ 0x12 ] ;
V_70 -> type = V_107 [ 0x13 ] ;
V_70 -> V_76 = F_32 ( V_107 + 0x18 ) ;
F_33 ( V_107 + 0x18 + V_85 , V_70 -> V_139 , sizeof ( V_70 -> V_139 ) ) ;
switch ( V_70 -> type ) {
case V_140 : V_39 = F_34 ( V_107 , V_92 , V_70 ) ; break;
case V_141 : V_39 = F_37 ( V_107 , V_92 , V_70 ) ; break;
case V_142 : V_39 = F_39 ( V_107 , V_92 , V_70 ) ; break;
case V_143 : V_39 = F_35 ( V_107 , V_92 , V_70 ) ; break;
case V_144 : V_39 = F_36 ( V_107 , V_92 , V_70 ) ; break;
case V_145 : V_39 = F_41 ( V_107 , V_92 , V_70 ) ; break;
case V_146 : V_39 = F_42 ( V_107 , V_92 , V_70 ) ; break;
}
if ( V_39 )
F_5 ( L_52 ,
( unsigned long long ) V_70 -> V_76 , V_70 -> type ) ;
else
F_9 ( L_53 ,
( unsigned long long ) V_70 -> V_76 , V_70 -> type ) ;
return V_39 ;
}
static bool F_44 ( T_1 * V_1 , int V_92 , struct V_48 * V_49 )
{
struct V_63 * V_70 ;
struct V_64 * V_65 ;
F_2 ( ! V_1 || ! V_49 ) ;
V_70 = F_14 ( sizeof ( * V_70 ) , V_42 ) ;
if ( ! V_70 ) {
F_4 ( L_10 ) ;
return false ;
}
if ( ! F_43 ( V_1 , V_92 , V_70 ) ) {
F_18 ( V_70 ) ;
return false ;
}
switch ( V_70 -> type ) {
case V_143 :
case V_144 :
F_45 ( & V_70 -> V_67 , & V_49 -> V_147 ) ;
break;
case V_141 :
case V_142 :
F_45 ( & V_70 -> V_67 , & V_49 -> V_148 ) ;
break;
case V_146 :
F_45 ( & V_70 -> V_67 , & V_49 -> V_149 ) ;
break;
case V_140 :
F_45 ( & V_70 -> V_67 , & V_49 -> V_150 ) ;
break;
case V_145 :
F_26 (item, &ldb->v_part) {
struct V_63 * V_66 = F_27 ( V_65 , struct V_63 , V_67 ) ;
if ( ( V_66 -> V_63 . V_72 . V_28 == V_70 -> V_63 . V_72 . V_28 ) &&
( V_66 -> V_63 . V_72 . V_77 > V_70 -> V_63 . V_72 . V_77 ) ) {
F_46 ( & V_70 -> V_67 , & V_66 -> V_67 ) ;
return true ;
}
}
F_46 ( & V_70 -> V_67 , & V_49 -> V_151 ) ;
break;
}
return true ;
}
static bool F_47 ( const T_1 * V_1 , int V_78 , struct V_64 * V_152 )
{
struct V_153 * V_154 ;
struct V_64 * V_65 ;
int V_155 , V_156 , V_157 ;
F_2 ( ! V_1 || ! V_152 ) ;
if ( V_78 < 2 * V_158 ) {
F_9 ( L_54 ) ;
return false ;
}
V_157 = F_7 ( V_1 + 0x08 ) ;
V_155 = F_8 ( V_1 + 0x0C ) ;
V_156 = F_8 ( V_1 + 0x0E ) ;
if ( ( V_156 < 1 ) || ( V_156 > 4 ) ) {
F_9 ( L_55 , V_156 ) ;
return false ;
}
if ( V_155 >= V_156 ) {
F_9 ( L_56 , V_155 , V_156 ) ;
return false ;
}
F_26 (item, frags) {
V_154 = F_27 ( V_65 , struct V_153 , V_67 ) ;
if ( V_154 -> V_157 == V_157 )
goto V_159;
}
V_154 = F_14 ( sizeof ( * V_154 ) + V_78 * V_156 , V_42 ) ;
if ( ! V_154 ) {
F_4 ( L_10 ) ;
return false ;
}
V_154 -> V_157 = V_157 ;
V_154 -> V_156 = V_156 ;
V_154 -> V_155 = V_155 ;
V_154 -> V_160 = 0xFF << V_156 ;
F_46 ( & V_154 -> V_67 , V_152 ) ;
V_159:
if ( V_155 >= V_154 -> V_156 ) {
F_9 ( L_56 , V_155 , V_154 -> V_156 ) ;
return false ;
}
if ( V_154 -> V_160 & ( 1 << V_155 ) ) {
F_9 ( L_57 , V_155 ) ;
V_154 -> V_160 &= 0x7F ;
return false ;
}
V_154 -> V_160 |= ( 1 << V_155 ) ;
if ( ! V_155 )
memcpy ( V_154 -> V_1 , V_1 , V_158 ) ;
V_1 += V_158 ;
V_78 -= V_158 ;
memcpy ( V_154 -> V_1 + V_158 + V_155 * V_78 , V_1 , V_78 ) ;
return true ;
}
static void F_48 ( struct V_64 * V_67 )
{
struct V_64 * V_65 , * V_83 ;
F_2 ( ! V_67 ) ;
F_49 (item, tmp, list)
F_18 ( F_27 ( V_65 , struct V_153 , V_67 ) ) ;
}
static bool F_50 ( struct V_64 * V_152 , struct V_48 * V_49 )
{
struct V_153 * V_154 ;
struct V_64 * V_65 ;
F_2 ( ! V_152 || ! V_49 ) ;
F_26 (item, frags) {
V_154 = F_27 ( V_65 , struct V_153 , V_67 ) ;
if ( V_154 -> V_160 != 0xFF ) {
F_9 ( L_58 ,
V_154 -> V_157 , V_154 -> V_160 ) ;
return false ;
}
if ( ! F_44 ( V_154 -> V_1 , V_154 -> V_156 * V_49 -> V_14 . V_18 , V_49 ) )
return false ;
}
return true ;
}
static bool F_51 ( struct V_31 * V_32 , unsigned long V_47 ,
struct V_48 * V_49 )
{
int V_78 , V_161 , V_162 , V_163 , V_164 , V_66 , V_165 ;
T_1 * V_1 = NULL ;
T_2 V_38 ;
bool V_39 = false ;
F_52 ( V_152 ) ;
F_2 ( ! V_32 || ! V_49 ) ;
V_78 = V_49 -> V_14 . V_18 ;
V_161 = 512 / V_78 ;
V_162 = V_49 -> V_14 . V_19 >> 9 ;
V_163 = ( V_78 * V_49 -> V_14 . V_20 ) >> 9 ;
for ( V_164 = V_162 ; V_164 < V_163 ; V_164 ++ ) {
V_1 = F_15 ( V_32 , V_47 + V_57 + V_164 , & V_38 ) ;
if ( ! V_1 ) {
F_4 ( L_11 ) ;
goto V_43;
}
for ( V_66 = 0 ; V_66 < V_161 ; V_66 ++ , V_1 += V_78 ) {
if ( V_166 != F_7 ( V_1 ) ) {
F_9 ( L_59 ) ;
goto V_43;
}
V_165 = F_8 ( V_1 + 0x0E ) ;
if ( V_165 == 1 ) {
if ( ! F_44 ( V_1 , V_78 , V_49 ) )
goto V_43;
} else if ( V_165 > 1 ) {
if ( ! F_47 ( V_1 , V_78 , & V_152 ) )
goto V_43;
}
}
F_17 ( V_38 ) ;
V_1 = NULL ;
}
V_39 = F_50 ( & V_152 , V_49 ) ;
V_43:
if ( V_1 )
F_17 ( V_38 ) ;
F_48 ( & V_152 ) ;
return V_39 ;
}
static void F_53 ( struct V_64 * V_167 )
{
struct V_64 * V_65 , * V_83 ;
F_2 ( ! V_167 ) ;
F_49 (item, tmp, lh)
F_18 ( F_27 ( V_65 , struct V_63 , V_67 ) ) ;
}
int F_54 ( struct V_31 * V_32 )
{
struct V_48 * V_49 ;
unsigned long V_47 ;
int V_39 = - 1 ;
F_2 ( ! V_32 ) ;
if ( ! F_22 ( V_32 ) )
return 0 ;
V_49 = F_14 ( sizeof ( * V_49 ) , V_42 ) ;
if ( ! V_49 ) {
F_4 ( L_10 ) ;
goto V_43;
}
if ( ! F_13 ( V_32 , & V_49 -> V_37 ) )
goto V_43;
V_47 = V_49 -> V_37 . V_26 ;
if ( ! F_19 ( V_32 , V_47 , V_49 ) ||
! F_20 ( V_32 , V_47 , V_49 ) )
goto V_43;
F_55 ( & V_49 -> V_147 ) ;
F_55 ( & V_49 -> V_148 ) ;
F_55 ( & V_49 -> V_149 ) ;
F_55 ( & V_49 -> V_150 ) ;
F_55 ( & V_49 -> V_151 ) ;
if ( ! F_51 ( V_32 , V_47 , V_49 ) ) {
F_4 ( L_60 ) ;
goto V_168;
}
if ( F_28 ( V_32 , V_49 ) ) {
F_5 ( L_61 ) ;
V_39 = 1 ;
}
V_168:
F_53 ( & V_49 -> V_147 ) ;
F_53 ( & V_49 -> V_148 ) ;
F_53 ( & V_49 -> V_149 ) ;
F_53 ( & V_49 -> V_150 ) ;
F_53 ( & V_49 -> V_151 ) ;
V_43:
F_18 ( V_49 ) ;
return V_39 ;
}
