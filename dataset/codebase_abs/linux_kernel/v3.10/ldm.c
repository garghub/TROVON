bool F_1 ( const T_1 * V_1 , T_1 * V_2 )
{
static const int V_3 [] = { 4 , 2 , 2 , 2 , 6 } ;
int V_4 , V_5 , V_6 ;
if ( V_1 [ 8 ] != '-' || V_1 [ 13 ] != '-' ||
V_1 [ 18 ] != '-' || V_1 [ 23 ] != '-' )
return false ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ , V_1 ++ )
for ( V_4 = 0 ; V_4 < V_3 [ V_5 ] ; V_4 ++ , V_1 += 2 , * V_2 ++ = V_6 )
if ( ( V_6 = F_2 ( V_1 ) ) < 0 )
return false ;
return true ;
}
static bool F_3 ( const T_1 * V_7 , struct V_8 * V_9 )
{
bool V_10 = false ;
F_4 ( ! V_7 || ! V_9 ) ;
if ( V_11 != F_5 ( V_7 ) ) {
F_6 ( L_1
L_2 ) ;
return false ;
}
V_9 -> V_12 = F_7 ( V_7 + 0x000C ) ;
V_9 -> V_13 = F_7 ( V_7 + 0x000E ) ;
V_9 -> V_14 = F_5 ( V_7 + 0x011B ) ;
V_9 -> V_15 = F_5 ( V_7 + 0x0123 ) ;
V_9 -> V_16 = F_5 ( V_7 + 0x012B ) ;
V_9 -> V_17 = F_5 ( V_7 + 0x0133 ) ;
if ( V_9 -> V_12 == 2 && V_9 -> V_13 == 12 )
V_10 = true ;
if ( ! V_10 && ( V_9 -> V_12 != 2 || V_9 -> V_13 != 11 ) ) {
F_6 ( L_3
L_4 , V_9 -> V_12 , V_9 -> V_13 ) ;
return false ;
}
F_8 ( L_5 , V_9 -> V_12 ,
V_9 -> V_13 , V_10 ? L_6 : L_7 ) ;
if ( V_9 -> V_17 != V_18 ) {
F_9 ( L_8
L_9 , V_18 ,
( unsigned long long ) V_9 -> V_17 ) ;
}
if ( ( V_9 -> V_15 == 0 ) || ( V_9 -> V_14 +
V_9 -> V_15 > V_9 -> V_16 ) ) {
F_6 ( L_10 ) ;
return false ;
}
if ( ! F_1 ( V_7 + 0x0030 , V_9 -> V_19 ) ) {
F_6 ( L_11 ) ;
return false ;
}
F_8 ( L_12 ) ;
return true ;
}
static bool F_10 ( const T_1 * V_7 , struct V_20 * V_21 )
{
F_4 ( ! V_7 || ! V_21 ) ;
if ( V_22 != F_5 ( V_7 ) ) {
F_11 ( L_13 ) ;
return false ;
}
strncpy ( V_21 -> V_23 , V_7 + 0x24 , sizeof ( V_21 -> V_23 ) ) ;
V_21 -> V_23 [ sizeof ( V_21 -> V_23 ) - 1 ] = 0 ;
V_21 -> V_24 = F_5 ( V_7 + 0x2E ) ;
V_21 -> V_25 = F_5 ( V_7 + 0x36 ) ;
if ( strncmp ( V_21 -> V_23 , V_26 ,
sizeof ( V_21 -> V_23 ) ) != 0 ) {
F_11 ( L_14 ,
V_26 , V_21 -> V_23 ) ;
return false ;
}
strncpy ( V_21 -> V_27 , V_7 + 0x46 , sizeof ( V_21 -> V_27 ) ) ;
V_21 -> V_27 [ sizeof ( V_21 -> V_27 ) - 1 ] = 0 ;
V_21 -> V_28 = F_5 ( V_7 + 0x50 ) ;
V_21 -> V_29 = F_5 ( V_7 + 0x58 ) ;
if ( strncmp ( V_21 -> V_27 , V_30 ,
sizeof ( V_21 -> V_27 ) ) != 0 ) {
F_11 ( L_15 ,
V_30 , V_21 -> V_27 ) ;
return false ;
}
F_8 ( L_16 ) ;
return true ;
}
static bool F_12 ( const T_1 * V_7 , struct V_31 * V_32 )
{
F_4 ( ! V_7 || ! V_32 ) ;
if ( V_33 != F_13 ( V_7 ) ) {
F_11 ( L_17 ) ;
return false ;
}
V_32 -> V_12 = F_7 ( V_7 + 0x12 ) ;
V_32 -> V_13 = F_7 ( V_7 + 0x14 ) ;
if ( ( V_32 -> V_12 != 4 ) || ( V_32 -> V_13 != 10 ) ) {
F_6 ( L_18
L_19 , 4 , 10 , V_32 -> V_12 , V_32 -> V_13 ) ;
return false ;
}
V_32 -> V_34 = F_13 ( V_7 + 0x08 ) ;
if ( V_32 -> V_34 == 0 ) {
F_6 ( L_20 ) ;
return false ;
}
V_32 -> V_35 = F_13 ( V_7 + 0x0C ) ;
V_32 -> V_36 = F_13 ( V_7 + 0x04 ) ;
F_8 ( L_21 ) ;
return true ;
}
static bool F_14 ( const struct V_8 * V_37 ,
const struct V_8 * V_38 )
{
F_4 ( ! V_37 || ! V_38 ) ;
return ( ( V_37 -> V_12 == V_38 -> V_12 ) &&
( V_37 -> V_13 == V_38 -> V_13 ) &&
( V_37 -> V_14 == V_38 -> V_14 ) &&
( V_37 -> V_15 == V_38 -> V_15 ) &&
( V_37 -> V_16 == V_38 -> V_16 ) &&
( V_37 -> V_17 == V_38 -> V_17 ) &&
! memcmp ( V_37 -> V_19 , V_38 -> V_19 , V_39 ) ) ;
}
static bool F_15 ( const struct V_20 * V_40 ,
const struct V_20 * V_41 )
{
F_4 ( ! V_40 || ! V_41 ) ;
return ( ( V_40 -> V_24 == V_41 -> V_24 ) &&
( V_40 -> V_25 == V_41 -> V_25 ) &&
( V_40 -> V_28 == V_41 -> V_28 ) &&
( V_40 -> V_29 == V_41 -> V_29 ) &&
! strncmp ( V_40 -> V_23 , V_41 -> V_23 ,
sizeof ( V_40 -> V_23 ) ) &&
! strncmp ( V_40 -> V_27 , V_41 -> V_27 ,
sizeof ( V_40 -> V_27 ) ) ) ;
}
static bool F_16 ( struct V_42 * V_43 ,
struct V_8 * V_37 )
{
static const int V_44 [ 3 ] = { V_45 , V_46 , V_47 } ;
struct V_8 * V_9 [ 3 ] = { V_37 } ;
T_2 V_48 ;
T_1 * V_7 ;
bool V_49 = false ;
long V_50 ;
int V_4 ;
F_4 ( ! V_43 || ! V_37 ) ;
V_9 [ 1 ] = F_17 ( sizeof ( * V_9 [ 1 ] ) , V_51 ) ;
V_9 [ 2 ] = F_17 ( sizeof ( * V_9 [ 2 ] ) , V_51 ) ;
if ( ! V_9 [ 1 ] || ! V_9 [ 2 ] ) {
F_11 ( L_22 ) ;
goto V_52;
}
V_9 [ 0 ] -> V_16 = 0 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_7 = F_18 ( V_43 , V_9 [ 0 ] -> V_16 + V_44 [ V_4 ] ,
& V_48 ) ;
if ( ! V_7 ) {
F_11 ( L_23 ) ;
goto V_52;
}
V_49 = F_3 ( V_7 , V_9 [ V_4 ] ) ;
F_19 ( V_48 ) ;
if ( ! V_49 ) {
F_6 ( L_24 , V_4 + 1 ) ;
if ( V_4 < 2 )
goto V_52;
else
break;
}
}
V_50 = V_43 -> V_53 -> V_54 -> V_55 >> 9 ;
if ( ( V_9 [ 0 ] -> V_16 > V_50 ) ||
( ( V_9 [ 0 ] -> V_16 + V_9 [ 0 ] -> V_17 ) > V_50 ) ) {
F_11 ( L_25 ) ;
goto V_52;
}
if ( ( V_9 [ 0 ] -> V_14 > V_9 [ 0 ] -> V_16 ) ||
( ( V_9 [ 0 ] -> V_14 + V_9 [ 0 ] -> V_15 )
> V_9 [ 0 ] -> V_16 ) ) {
F_11 ( L_26 ) ;
goto V_52;
}
if ( ! F_14 ( V_9 [ 0 ] , V_9 [ 1 ] ) ) {
F_11 ( L_27 ) ;
goto V_52;
}
F_8 ( L_28 ) ;
V_49 = true ;
V_52:
F_20 ( V_9 [ 1 ] ) ;
F_20 ( V_9 [ 2 ] ) ;
return V_49 ;
}
static bool F_21 ( struct V_42 * V_43 ,
unsigned long V_56 , struct V_57 * V_58 )
{
static const int V_44 [ 4 ] = { V_59 , V_60 , V_61 , V_62 } ;
struct V_20 * V_63 [ 4 ] ;
struct V_8 * V_9 ;
T_2 V_48 ;
T_1 * V_7 ;
int V_4 , V_64 ;
bool V_49 = false ;
F_4 ( ! V_43 || ! V_58 ) ;
V_9 = & V_58 -> V_9 ;
V_63 [ 0 ] = & V_58 -> V_21 ;
V_63 [ 1 ] = F_17 ( sizeof( * V_63 [ 1 ] ) * 3 , V_51 ) ;
if ( ! V_63 [ 1 ] ) {
F_11 ( L_22 ) ;
goto V_65;
}
V_63 [ 2 ] = (struct V_20 * ) ( ( T_1 * ) V_63 [ 1 ] + sizeof( * V_63 [ 1 ] ) ) ;
V_63 [ 3 ] = (struct V_20 * ) ( ( T_1 * ) V_63 [ 2 ] + sizeof( * V_63 [ 2 ] ) ) ;
for ( V_64 = V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_7 = F_18 ( V_43 , V_56 + V_44 [ V_4 ] , & V_48 ) ;
if ( ! V_7 ) {
F_6 ( L_29 , V_4 ) ;
continue;
}
if ( F_10 ( V_7 , V_63 [ V_64 ] ) )
V_64 ++ ;
F_19 ( V_48 ) ;
}
if ( ! V_64 ) {
F_11 ( L_30 ) ;
goto V_65;
}
if ( ( ( V_63 [ 0 ] -> V_24 + V_63 [ 0 ] -> V_25 ) > V_9 -> V_17 ) ||
( ( V_63 [ 0 ] -> V_28 + V_63 [ 0 ] -> V_29 ) >
V_9 -> V_17 ) ) {
F_11 ( L_31 ) ;
goto V_65;
}
for ( V_4 = 1 ; V_4 < V_64 ; V_4 ++ ) {
if ( ! F_15 ( V_63 [ 0 ] , V_63 [ V_4 ] ) ) {
F_11 ( L_32 , V_4 ) ;
goto V_65;
}
}
F_8 ( L_33 , V_64 ) ;
V_49 = true ;
V_65:
F_20 ( V_63 [ 1 ] ) ;
return V_49 ;
}
static bool F_22 ( struct V_42 * V_43 ,
unsigned long V_56 , struct V_57 * V_58 )
{
T_2 V_48 ;
T_1 * V_7 ;
bool V_49 = false ;
struct V_31 * V_32 ;
struct V_20 * V_21 ;
F_4 ( ! V_43 || ! V_58 ) ;
V_32 = & V_58 -> V_32 ;
V_21 = & V_58 -> V_21 ;
V_7 = F_18 ( V_43 , V_56 + V_66 , & V_48 ) ;
if ( ! V_7 ) {
F_11 ( L_23 ) ;
return false ;
}
if ( ! F_12 ( V_7 , V_32 ) )
goto V_52;
if ( F_7 ( V_7 + 0x10 ) != 0x01 ) {
F_11 ( L_34 ) ;
goto V_52;
}
if ( V_32 -> V_35 != 512 )
F_9 ( L_35 , V_32 -> V_35 ) ;
if ( ( V_32 -> V_34 * V_32 -> V_36 ) > ( V_21 -> V_25 << 9 ) ) {
F_11 ( L_36
L_37 ) ;
goto V_52;
}
V_49 = true ;
V_52:
F_19 ( V_48 ) ;
return V_49 ;
}
static bool F_23 ( struct V_42 * V_43 )
{
T_2 V_48 ;
T_1 * V_7 ;
struct V_67 * V_68 ;
int V_4 ;
bool V_49 = false ;
F_4 ( ! V_43 ) ;
V_7 = F_18 ( V_43 , 0 , & V_48 ) ;
if ( ! V_7 ) {
F_9 ( L_23 ) ;
return false ;
}
if ( * ( V_69 * ) ( V_7 + 0x01FE ) != F_24 ( V_70 ) )
goto V_52;
V_68 = (struct V_67 * ) ( V_7 + 0x01BE ) ;
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ , V_68 ++ )
if ( F_25 ( V_68 ) == V_71 ) {
V_49 = true ;
break;
}
if ( V_49 )
F_8 ( L_38 ) ;
V_52:
F_19 ( V_48 ) ;
return V_49 ;
}
static struct V_72 * F_26 ( const struct V_57 * V_58 )
{
struct V_73 * V_74 ;
F_4 ( ! V_58 ) ;
F_27 (item, &ldb->v_disk) {
struct V_72 * V_6 = F_28 ( V_74 , struct V_72 , V_75 ) ;
if ( ! memcmp ( V_6 -> V_72 . V_76 . V_19 , V_58 -> V_9 . V_19 , V_39 ) )
return V_6 ;
}
return NULL ;
}
static bool F_29 ( struct V_42 * V_77 ,
const struct V_57 * V_58 )
{
struct V_73 * V_74 ;
struct V_72 * V_78 ;
struct V_72 * V_76 ;
struct V_79 * V_80 ;
int V_81 = 1 ;
F_4 ( ! V_77 || ! V_58 ) ;
V_76 = F_26 ( V_58 ) ;
if ( ! V_76 ) {
F_11 ( L_39 ) ;
return false ;
}
F_30 ( V_77 -> V_82 , L_40 , V_83 ) ;
F_27 (item, &ldb->v_part) {
V_78 = F_28 ( V_74 , struct V_72 , V_75 ) ;
V_80 = & V_78 -> V_72 . V_80 ;
if ( V_80 -> V_19 != V_76 -> V_84 )
continue;
F_31 ( V_77 , V_81 , V_58 -> V_9 . V_14 +
V_80 -> V_85 , V_80 -> V_3 ) ;
V_81 ++ ;
}
F_30 ( V_77 -> V_82 , L_41 , V_83 ) ;
return true ;
}
static int F_32 ( const T_1 * V_86 , int V_87 , int V_56 , int V_88 )
{
V_56 += V_88 ;
if ( ! V_86 || V_88 < 0 || V_56 > V_87 ) {
if ( ! V_86 )
F_6 ( L_42 ) ;
if ( V_88 < 0 )
F_6 ( L_43 , V_88 ) ;
if ( V_56 > V_87 )
F_6 ( L_44 , V_56 , V_87 ) ;
return - 1 ;
}
if ( V_56 + V_86 [ V_56 ] >= V_87 ) {
F_6 ( L_45 , V_56 ,
V_86 [ V_56 ] , V_87 ) ;
return - 1 ;
}
return V_86 [ V_56 ] + V_88 + 1 ;
}
static T_3 F_33 ( const T_1 * V_89 )
{
T_3 V_90 = 0 ;
T_1 V_91 ;
F_4 ( ! V_89 ) ;
V_91 = * V_89 ++ ;
if ( V_91 && V_91 <= 8 )
while ( V_91 -- )
V_90 = ( V_90 << 8 ) | * V_89 ++ ;
else
F_6 ( L_46 , V_91 ) ;
return V_90 ;
}
static int F_34 ( const T_1 * V_89 , T_1 * V_86 , int V_87 )
{
int V_91 ;
F_4 ( ! V_89 || ! V_86 ) ;
V_91 = V_89 [ 0 ] ;
if ( V_91 >= V_87 ) {
F_6 ( L_47 , V_91 , V_87 ) ;
V_91 = V_87 - 1 ;
}
memcpy ( V_86 , V_89 + 1 , V_91 ) ;
V_86 [ V_91 ] = 0 ;
return V_91 ;
}
static bool F_35 ( const T_1 * V_86 , int V_87 , struct V_72 * V_78 )
{
int V_92 , V_93 , V_94 , V_95 , V_96 , V_97 , V_98 , V_99 ;
struct V_100 * V_101 ;
F_4 ( ! V_86 || ! V_78 ) ;
V_92 = F_32 ( V_86 , V_87 , 0x18 , 0 ) ;
V_93 = F_32 ( V_86 , V_87 , 0x18 , V_92 ) ;
V_94 = F_32 ( V_86 , V_87 , 0x18 , V_93 ) ;
V_95 = F_32 ( V_86 , V_87 , 0x1D , V_94 ) ;
V_96 = F_32 ( V_86 , V_87 , 0x2D , V_95 ) ;
if ( V_86 [ 0x12 ] & V_102 ) {
V_97 = F_32 ( V_86 , V_87 , 0x2E , V_96 ) ;
V_98 = F_32 ( V_86 , V_87 , 0x2E , V_97 ) ;
V_99 = V_98 ;
} else {
V_97 = 0 ;
V_98 = 0 ;
V_99 = V_96 ;
}
if ( V_99 < 0 )
return false ;
V_99 += V_103 ;
if ( V_99 != F_13 ( V_86 + 0x14 ) )
return false ;
V_101 = & V_78 -> V_72 . V_101 ;
F_34 ( V_86 + 0x18 + V_93 , V_101 -> V_43 ,
sizeof ( V_101 -> V_43 ) ) ;
V_101 -> type = V_86 [ 0x18 + V_94 ] ;
V_101 -> V_104 = F_33 ( V_86 + 0x1D + V_94 ) ;
V_101 -> V_105 = F_33 ( V_86 + 0x2D + V_95 ) ;
V_101 -> V_106 = V_97 ? F_33 ( V_86 + V_96 + 0x2E ) : 0 ;
return true ;
}
static int F_36 ( const T_1 * V_86 , int V_87 , struct V_72 * V_78 )
{
int V_92 , V_93 , V_107 , V_108 , V_109 , V_99 ;
struct V_110 * V_111 ;
F_4 ( ! V_86 || ! V_78 ) ;
V_92 = F_32 ( V_86 , V_87 , 0x18 , 0 ) ;
V_93 = F_32 ( V_86 , V_87 , 0x18 , V_92 ) ;
V_107 = F_32 ( V_86 , V_87 , 0x18 , V_93 ) ;
if ( V_86 [ 0x12 ] & V_112 ) {
V_108 = F_32 ( V_86 , V_87 , 0x24 , V_107 ) ;
V_109 = F_32 ( V_86 , V_87 , 0x24 , V_108 ) ;
V_99 = V_109 ;
} else {
V_108 = 0 ;
V_109 = 0 ;
V_99 = V_107 ;
}
if ( V_99 < 0 )
return false ;
V_99 += V_113 ;
if ( V_99 != F_13 ( V_86 + 0x14 ) )
return false ;
V_111 = & V_78 -> V_72 . V_111 ;
F_34 ( V_86 + 0x18 + V_93 , V_111 -> V_19 ,
sizeof ( V_111 -> V_19 ) ) ;
return true ;
}
static bool F_37 ( const T_1 * V_86 , int V_87 , struct V_72 * V_78 )
{
char V_114 [ 64 ] ;
int V_92 , V_93 , V_108 , V_109 , V_99 ;
struct V_110 * V_111 ;
F_4 ( ! V_86 || ! V_78 ) ;
V_92 = F_32 ( V_86 , V_87 , 0x18 , 0 ) ;
V_93 = F_32 ( V_86 , V_87 , 0x18 , V_92 ) ;
if ( V_86 [ 0x12 ] & V_115 ) {
V_108 = F_32 ( V_86 , V_87 , 0x44 , V_93 ) ;
V_109 = F_32 ( V_86 , V_87 , 0x44 , V_108 ) ;
V_99 = V_109 ;
} else {
V_108 = 0 ;
V_109 = 0 ;
V_99 = V_93 ;
}
if ( V_99 < 0 )
return false ;
V_99 += V_116 ;
if ( V_99 != F_13 ( V_86 + 0x14 ) )
return false ;
V_111 = & V_78 -> V_72 . V_111 ;
F_34 ( V_86 + 0x18 + V_92 , V_114 , sizeof ( V_114 ) ) ;
return true ;
}
static bool F_38 ( const T_1 * V_86 , int V_87 , struct V_72 * V_78 )
{
int V_92 , V_93 , V_107 , V_117 , V_99 ;
struct V_118 * V_76 ;
F_4 ( ! V_86 || ! V_78 ) ;
V_92 = F_32 ( V_86 , V_87 , 0x18 , 0 ) ;
V_93 = F_32 ( V_86 , V_87 , 0x18 , V_92 ) ;
V_107 = F_32 ( V_86 , V_87 , 0x18 , V_93 ) ;
V_117 = F_32 ( V_86 , V_87 , 0x18 , V_107 ) ;
V_99 = V_117 ;
if ( V_99 < 0 )
return false ;
V_99 += V_119 ;
if ( V_99 != F_13 ( V_86 + 0x14 ) )
return false ;
V_76 = & V_78 -> V_72 . V_76 ;
F_34 ( V_86 + 0x18 + V_107 , V_76 -> V_120 ,
sizeof ( V_76 -> V_120 ) ) ;
if ( ! F_1 ( V_86 + 0x19 + V_93 , V_76 -> V_19 ) )
return false ;
return true ;
}
static bool F_39 ( const T_1 * V_86 , int V_87 , struct V_72 * V_78 )
{
int V_92 , V_93 , V_99 ;
struct V_118 * V_76 ;
F_4 ( ! V_86 || ! V_78 ) ;
V_92 = F_32 ( V_86 , V_87 , 0x18 , 0 ) ;
V_93 = F_32 ( V_86 , V_87 , 0x18 , V_92 ) ;
V_99 = V_93 ;
if ( V_99 < 0 )
return false ;
V_99 += V_121 ;
if ( V_99 != F_13 ( V_86 + 0x14 ) )
return false ;
V_76 = & V_78 -> V_72 . V_76 ;
memcpy ( V_76 -> V_19 , V_86 + 0x18 + V_93 , V_39 ) ;
return true ;
}
static bool F_40 ( const T_1 * V_86 , int V_87 , struct V_72 * V_78 )
{
int V_92 , V_93 , V_122 , V_96 , V_107 , V_123 , V_99 ;
struct V_79 * V_80 ;
F_4 ( ! V_86 || ! V_78 ) ;
V_92 = F_32 ( V_86 , V_87 , 0x18 , 0 ) ;
if ( V_92 < 0 ) {
F_6 ( L_48 , V_92 ) ;
return false ;
}
V_93 = F_32 ( V_86 , V_87 , 0x18 , V_92 ) ;
if ( V_93 < 0 ) {
F_6 ( L_49 , V_93 ) ;
return false ;
}
V_122 = F_32 ( V_86 , V_87 , 0x34 , V_93 ) ;
if ( V_122 < 0 ) {
F_6 ( L_50 , V_122 ) ;
return false ;
}
V_96 = F_32 ( V_86 , V_87 , 0x34 , V_122 ) ;
if ( V_96 < 0 ) {
F_6 ( L_51 , V_96 ) ;
return false ;
}
V_107 = F_32 ( V_86 , V_87 , 0x34 , V_96 ) ;
if ( V_107 < 0 ) {
F_6 ( L_52 , V_107 ) ;
return false ;
}
if ( V_86 [ 0x12 ] & V_124 ) {
V_123 = F_32 ( V_86 , V_87 , 0x34 , V_107 ) ;
if ( V_123 < 0 ) {
F_6 ( L_53 , V_123 ) ;
return false ;
}
V_99 = V_123 ;
} else {
V_123 = 0 ;
V_99 = V_107 ;
}
if ( V_99 < 0 ) {
F_6 ( L_54 , V_99 ) ;
return false ;
}
V_99 += V_125 ;
if ( V_99 > F_13 ( V_86 + 0x14 ) ) {
F_6 ( L_55 , V_99 ,
F_13 ( V_86 + 0x14 ) ) ;
return false ;
}
V_80 = & V_78 -> V_72 . V_80 ;
V_80 -> V_85 = F_5 ( V_86 + 0x24 + V_93 ) ;
V_80 -> V_126 = F_5 ( V_86 + 0x2C + V_93 ) ;
V_80 -> V_3 = F_33 ( V_86 + 0x34 + V_93 ) ;
V_80 -> V_105 = F_33 ( V_86 + 0x34 + V_122 ) ;
V_80 -> V_19 = F_33 ( V_86 + 0x34 + V_96 ) ;
if ( V_78 -> V_127 & V_124 )
V_80 -> V_128 = V_86 [ 0x35 + V_107 ] ;
else
V_80 -> V_128 = 0 ;
return true ;
}
static bool F_41 ( const T_1 * V_86 , int V_87 , struct V_72 * V_78 )
{
int V_92 , V_93 , V_129 , V_130 , V_95 , V_122 ;
int V_108 , V_109 , V_131 , V_132 , V_99 ;
struct V_133 * V_134 ;
F_4 ( ! V_86 || ! V_78 ) ;
V_92 = F_32 ( V_86 , V_87 , 0x18 , 0 ) ;
if ( V_92 < 0 ) {
F_6 ( L_48 , V_92 ) ;
return false ;
}
V_93 = F_32 ( V_86 , V_87 , 0x18 , V_92 ) ;
if ( V_93 < 0 ) {
F_6 ( L_49 , V_93 ) ;
return false ;
}
V_129 = F_32 ( V_86 , V_87 , 0x18 , V_93 ) ;
if ( V_129 < 0 ) {
F_6 ( L_56 , V_129 ) ;
return false ;
}
V_130 = F_32 ( V_86 , V_87 , 0x18 , V_129 ) ;
if ( V_130 < 0 ) {
F_6 ( L_57 ,
V_130 ) ;
return false ;
}
V_95 = F_32 ( V_86 , V_87 , 0x2D , V_130 ) ;
if ( V_95 < 0 ) {
F_6 ( L_58 , V_95 ) ;
return false ;
}
V_122 = F_32 ( V_86 , V_87 , 0x3D , V_95 ) ;
if ( V_122 < 0 ) {
F_6 ( L_50 , V_122 ) ;
return false ;
}
if ( V_86 [ 0x12 ] & V_135 ) {
V_108 = F_32 ( V_86 , V_87 , 0x52 , V_122 ) ;
if ( V_108 < 0 ) {
F_6 ( L_59 , V_108 ) ;
return false ;
}
} else
V_108 = V_122 ;
if ( V_86 [ 0x12 ] & V_136 ) {
V_109 = F_32 ( V_86 , V_87 , 0x52 , V_108 ) ;
if ( V_109 < 0 ) {
F_6 ( L_60 , V_109 ) ;
return false ;
}
} else
V_109 = V_108 ;
if ( V_86 [ 0x12 ] & V_137 ) {
V_131 = F_32 ( V_86 , V_87 , 0x52 , V_109 ) ;
if ( V_131 < 0 ) {
F_6 ( L_61 , V_131 ) ;
return false ;
}
} else
V_131 = V_109 ;
if ( V_86 [ 0x12 ] & V_138 ) {
V_132 = F_32 ( V_86 , V_87 , 0x52 , V_131 ) ;
if ( V_132 < 0 ) {
F_6 ( L_62 , V_132 ) ;
return false ;
}
} else
V_132 = V_131 ;
V_99 = V_132 ;
if ( V_99 < 0 ) {
F_6 ( L_54 , V_99 ) ;
return false ;
}
V_99 += V_139 ;
if ( V_99 > F_13 ( V_86 + 0x14 ) ) {
F_6 ( L_55 , V_99 ,
F_13 ( V_86 + 0x14 ) ) ;
return false ;
}
V_134 = & V_78 -> V_72 . V_134 ;
F_34 ( V_86 + 0x18 + V_93 , V_134 -> V_140 ,
sizeof( V_134 -> V_140 ) ) ;
memcpy ( V_134 -> V_141 , V_86 + 0x18 + V_130 ,
sizeof( V_134 -> V_141 ) ) ;
V_134 -> V_3 = F_33 ( V_86 + 0x3D + V_95 ) ;
V_134 -> V_142 = V_86 [ 0x41 + V_122 ] ;
memcpy ( V_134 -> V_143 , V_86 + 0x42 + V_122 , sizeof( V_134 -> V_143 ) ) ;
if ( V_86 [ 0x12 ] & V_138 ) {
F_34 ( V_86 + 0x52 + V_122 , V_134 -> V_144 ,
sizeof( V_134 -> V_144 ) ) ;
}
return true ;
}
static bool F_42 ( const T_1 * V_114 , int V_99 , struct V_72 * V_78 )
{
bool V_49 = false ;
int V_92 ;
F_4 ( ! V_114 || ! V_78 ) ;
V_92 = F_32 ( V_114 , V_99 , 0x18 , 0 ) ;
if ( V_92 < 0 ) {
F_6 ( L_63 ) ;
return false ;
}
V_78 -> V_127 = V_114 [ 0x12 ] ;
V_78 -> type = V_114 [ 0x13 ] ;
V_78 -> V_84 = F_33 ( V_114 + 0x18 ) ;
F_34 ( V_114 + 0x18 + V_92 , V_78 -> V_145 , sizeof ( V_78 -> V_145 ) ) ;
switch ( V_78 -> type ) {
case V_146 : V_49 = F_35 ( V_114 , V_99 , V_78 ) ; break;
case V_147 : V_49 = F_38 ( V_114 , V_99 , V_78 ) ; break;
case V_148 : V_49 = F_39 ( V_114 , V_99 , V_78 ) ; break;
case V_149 : V_49 = F_36 ( V_114 , V_99 , V_78 ) ; break;
case V_150 : V_49 = F_37 ( V_114 , V_99 , V_78 ) ; break;
case V_151 : V_49 = F_40 ( V_114 , V_99 , V_78 ) ; break;
case V_152 : V_49 = F_41 ( V_114 , V_99 , V_78 ) ; break;
}
if ( V_49 )
F_8 ( L_64 ,
( unsigned long long ) V_78 -> V_84 , V_78 -> type ) ;
else
F_6 ( L_65 ,
( unsigned long long ) V_78 -> V_84 , V_78 -> type ) ;
return V_49 ;
}
static bool F_43 ( T_1 * V_7 , int V_99 , struct V_57 * V_58 )
{
struct V_72 * V_78 ;
struct V_73 * V_74 ;
F_4 ( ! V_7 || ! V_58 ) ;
V_78 = F_17 ( sizeof ( * V_78 ) , V_51 ) ;
if ( ! V_78 ) {
F_11 ( L_22 ) ;
return false ;
}
if ( ! F_42 ( V_7 , V_99 , V_78 ) ) {
F_20 ( V_78 ) ;
return false ;
}
switch ( V_78 -> type ) {
case V_149 :
case V_150 :
F_44 ( & V_78 -> V_75 , & V_58 -> V_153 ) ;
break;
case V_147 :
case V_148 :
F_44 ( & V_78 -> V_75 , & V_58 -> V_154 ) ;
break;
case V_152 :
F_44 ( & V_78 -> V_75 , & V_58 -> V_155 ) ;
break;
case V_146 :
F_44 ( & V_78 -> V_75 , & V_58 -> V_156 ) ;
break;
case V_151 :
F_27 (item, &ldb->v_part) {
struct V_72 * V_6 = F_28 ( V_74 , struct V_72 , V_75 ) ;
if ( ( V_6 -> V_72 . V_80 . V_19 == V_78 -> V_72 . V_80 . V_19 ) &&
( V_6 -> V_72 . V_80 . V_85 > V_78 -> V_72 . V_80 . V_85 ) ) {
F_45 ( & V_78 -> V_75 , & V_6 -> V_75 ) ;
return true ;
}
}
F_45 ( & V_78 -> V_75 , & V_58 -> V_157 ) ;
break;
}
return true ;
}
static bool F_46 ( const T_1 * V_7 , int V_3 , struct V_73 * V_158 )
{
struct V_159 * V_160 ;
struct V_73 * V_74 ;
int V_161 , V_162 , V_163 ;
F_4 ( ! V_7 || ! V_158 ) ;
if ( V_3 < 2 * V_164 ) {
F_6 ( L_66 ) ;
return false ;
}
V_163 = F_13 ( V_7 + 0x08 ) ;
V_161 = F_7 ( V_7 + 0x0C ) ;
V_162 = F_7 ( V_7 + 0x0E ) ;
if ( ( V_162 < 1 ) || ( V_162 > 4 ) ) {
F_6 ( L_67 , V_162 ) ;
return false ;
}
if ( V_161 >= V_162 ) {
F_6 ( L_68 , V_161 , V_162 ) ;
return false ;
}
F_27 (item, frags) {
V_160 = F_28 ( V_74 , struct V_159 , V_75 ) ;
if ( V_160 -> V_163 == V_163 )
goto V_165;
}
V_160 = F_17 ( sizeof ( * V_160 ) + V_3 * V_162 , V_51 ) ;
if ( ! V_160 ) {
F_11 ( L_22 ) ;
return false ;
}
V_160 -> V_163 = V_163 ;
V_160 -> V_162 = V_162 ;
V_160 -> V_161 = V_161 ;
V_160 -> V_166 = 0xFF << V_162 ;
F_45 ( & V_160 -> V_75 , V_158 ) ;
V_165:
if ( V_161 >= V_160 -> V_162 ) {
F_6 ( L_68 , V_161 , V_160 -> V_162 ) ;
return false ;
}
if ( V_160 -> V_166 & ( 1 << V_161 ) ) {
F_6 ( L_69 , V_161 ) ;
V_160 -> V_166 &= 0x7F ;
return false ;
}
V_160 -> V_166 |= ( 1 << V_161 ) ;
if ( ! V_161 )
memcpy ( V_160 -> V_7 , V_7 , V_164 ) ;
V_7 += V_164 ;
V_3 -= V_164 ;
memcpy ( V_160 -> V_7 + V_164 + V_161 * V_3 , V_7 , V_3 ) ;
return true ;
}
static void F_47 ( struct V_73 * V_75 )
{
struct V_73 * V_74 , * V_90 ;
F_4 ( ! V_75 ) ;
F_48 (item, tmp, list)
F_20 ( F_28 ( V_74 , struct V_159 , V_75 ) ) ;
}
static bool F_49 ( struct V_73 * V_158 , struct V_57 * V_58 )
{
struct V_159 * V_160 ;
struct V_73 * V_74 ;
F_4 ( ! V_158 || ! V_58 ) ;
F_27 (item, frags) {
V_160 = F_28 ( V_74 , struct V_159 , V_75 ) ;
if ( V_160 -> V_166 != 0xFF ) {
F_6 ( L_70 ,
V_160 -> V_163 , V_160 -> V_166 ) ;
return false ;
}
if ( ! F_43 ( V_160 -> V_7 , V_160 -> V_162 * V_58 -> V_32 . V_34 , V_58 ) )
return false ;
}
return true ;
}
static bool F_50 ( struct V_42 * V_43 , unsigned long V_56 ,
struct V_57 * V_58 )
{
int V_3 , V_167 , V_168 , V_169 , V_170 , V_6 , V_171 ;
T_1 * V_7 = NULL ;
T_2 V_48 ;
bool V_49 = false ;
F_51 ( V_158 ) ;
F_4 ( ! V_43 || ! V_58 ) ;
V_3 = V_58 -> V_32 . V_34 ;
V_167 = 512 / V_3 ;
V_168 = V_58 -> V_32 . V_35 >> 9 ;
V_169 = ( V_3 * V_58 -> V_32 . V_36 ) >> 9 ;
for ( V_170 = V_168 ; V_170 < V_169 ; V_170 ++ ) {
V_7 = F_18 ( V_43 , V_56 + V_66 + V_170 , & V_48 ) ;
if ( ! V_7 ) {
F_11 ( L_23 ) ;
goto V_52;
}
for ( V_6 = 0 ; V_6 < V_167 ; V_6 ++ , V_7 += V_3 ) {
if ( V_172 != F_13 ( V_7 ) ) {
F_6 ( L_71 ) ;
goto V_52;
}
V_171 = F_7 ( V_7 + 0x0E ) ;
if ( V_171 == 1 ) {
if ( ! F_43 ( V_7 , V_3 , V_58 ) )
goto V_52;
} else if ( V_171 > 1 ) {
if ( ! F_46 ( V_7 , V_3 , & V_158 ) )
goto V_52;
}
}
F_19 ( V_48 ) ;
V_7 = NULL ;
}
V_49 = F_49 ( & V_158 , V_58 ) ;
V_52:
if ( V_7 )
F_19 ( V_48 ) ;
F_47 ( & V_158 ) ;
return V_49 ;
}
static void F_52 ( struct V_73 * V_173 )
{
struct V_73 * V_74 , * V_90 ;
F_4 ( ! V_173 ) ;
F_48 (item, tmp, lh)
F_20 ( F_28 ( V_74 , struct V_72 , V_75 ) ) ;
}
int F_53 ( struct V_42 * V_43 )
{
struct V_57 * V_58 ;
unsigned long V_56 ;
int V_49 = - 1 ;
F_4 ( ! V_43 ) ;
if ( ! F_23 ( V_43 ) )
return 0 ;
V_58 = F_17 ( sizeof ( * V_58 ) , V_51 ) ;
if ( ! V_58 ) {
F_11 ( L_22 ) ;
goto V_52;
}
if ( ! F_16 ( V_43 , & V_58 -> V_9 ) )
goto V_52;
V_56 = V_58 -> V_9 . V_16 ;
if ( ! F_21 ( V_43 , V_56 , V_58 ) ||
! F_22 ( V_43 , V_56 , V_58 ) )
goto V_52;
F_54 ( & V_58 -> V_153 ) ;
F_54 ( & V_58 -> V_154 ) ;
F_54 ( & V_58 -> V_155 ) ;
F_54 ( & V_58 -> V_156 ) ;
F_54 ( & V_58 -> V_157 ) ;
if ( ! F_50 ( V_43 , V_56 , V_58 ) ) {
F_11 ( L_72 ) ;
goto V_174;
}
if ( F_29 ( V_43 , V_58 ) ) {
F_8 ( L_73 ) ;
V_49 = 1 ;
}
V_174:
F_52 ( & V_58 -> V_153 ) ;
F_52 ( & V_58 -> V_154 ) ;
F_52 ( & V_58 -> V_155 ) ;
F_52 ( & V_58 -> V_156 ) ;
F_52 ( & V_58 -> V_157 ) ;
V_52:
F_20 ( V_58 ) ;
return V_49 ;
}
