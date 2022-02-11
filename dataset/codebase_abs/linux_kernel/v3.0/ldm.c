static void F_1 ( const char * V_1 , const char * V_2 ,
const char * V_3 , ... )
{
static char V_4 [ 128 ] ;
T_1 args ;
va_start ( args , V_3 ) ;
vsnprintf ( V_4 , sizeof ( V_4 ) , V_3 , args ) ;
va_end ( args ) ;
F_2 ( L_1 , V_1 , V_2 , V_4 ) ;
}
static int F_3 ( const T_2 * V_5 )
{
unsigned int V_6 ;
int V_7 ;
V_6 = V_7 = F_4 ( V_5 [ 0 ] ) ;
if ( V_7 < 0 )
return - 1 ;
V_7 = F_4 ( V_5 [ 1 ] ) ;
if ( V_7 < 0 )
return - 1 ;
return ( V_6 << 4 ) + V_7 ;
}
static bool F_5 ( const T_2 * V_5 , T_2 * V_8 )
{
static const int V_9 [] = { 4 , 2 , 2 , 2 , 6 } ;
int V_10 , V_11 , V_12 ;
if ( V_5 [ 8 ] != '-' || V_5 [ 13 ] != '-' ||
V_5 [ 18 ] != '-' || V_5 [ 23 ] != '-' )
return false ;
for ( V_11 = 0 ; V_11 < 5 ; V_11 ++ , V_5 ++ )
for ( V_10 = 0 ; V_10 < V_9 [ V_11 ] ; V_10 ++ , V_5 += 2 , * V_8 ++ = V_12 )
if ( ( V_12 = F_3 ( V_5 ) ) < 0 )
return false ;
return true ;
}
static bool F_6 ( const T_2 * V_13 , struct V_14 * V_15 )
{
bool V_16 = false ;
F_7 ( ! V_13 || ! V_15 ) ;
if ( V_17 != F_8 ( V_13 ) ) {
F_9 ( L_2
L_3 ) ;
return false ;
}
V_15 -> V_18 = F_10 ( V_13 + 0x000C ) ;
V_15 -> V_19 = F_10 ( V_13 + 0x000E ) ;
V_15 -> V_20 = F_8 ( V_13 + 0x011B ) ;
V_15 -> V_21 = F_8 ( V_13 + 0x0123 ) ;
V_15 -> V_22 = F_8 ( V_13 + 0x012B ) ;
V_15 -> V_23 = F_8 ( V_13 + 0x0133 ) ;
if ( V_15 -> V_18 == 2 && V_15 -> V_19 == 12 )
V_16 = true ;
if ( ! V_16 && ( V_15 -> V_18 != 2 || V_15 -> V_19 != 11 ) ) {
F_9 ( L_4
L_5 , V_15 -> V_18 , V_15 -> V_19 ) ;
return false ;
}
F_11 ( L_6 , V_15 -> V_18 ,
V_15 -> V_19 , V_16 ? L_7 : L_8 ) ;
if ( V_15 -> V_23 != V_24 ) {
F_12 ( L_9
L_10 , V_24 ,
( unsigned long long ) V_15 -> V_23 ) ;
}
if ( ( V_15 -> V_21 == 0 ) || ( V_15 -> V_20 +
V_15 -> V_21 > V_15 -> V_22 ) ) {
F_9 ( L_11 ) ;
return false ;
}
if ( ! F_5 ( V_13 + 0x0030 , V_15 -> V_25 ) ) {
F_9 ( L_12 ) ;
return false ;
}
F_11 ( L_13 ) ;
return true ;
}
static bool F_13 ( const T_2 * V_13 , struct V_26 * V_27 )
{
F_7 ( ! V_13 || ! V_27 ) ;
if ( V_28 != F_8 ( V_13 ) ) {
F_14 ( L_14 ) ;
return false ;
}
strncpy ( V_27 -> V_29 , V_13 + 0x24 , sizeof ( V_27 -> V_29 ) ) ;
V_27 -> V_29 [ sizeof ( V_27 -> V_29 ) - 1 ] = 0 ;
V_27 -> V_30 = F_8 ( V_13 + 0x2E ) ;
V_27 -> V_31 = F_8 ( V_13 + 0x36 ) ;
if ( strncmp ( V_27 -> V_29 , V_32 ,
sizeof ( V_27 -> V_29 ) ) != 0 ) {
F_14 ( L_15 ,
V_32 , V_27 -> V_29 ) ;
return false ;
}
strncpy ( V_27 -> V_33 , V_13 + 0x46 , sizeof ( V_27 -> V_33 ) ) ;
V_27 -> V_33 [ sizeof ( V_27 -> V_33 ) - 1 ] = 0 ;
V_27 -> V_34 = F_8 ( V_13 + 0x50 ) ;
V_27 -> V_35 = F_8 ( V_13 + 0x58 ) ;
if ( strncmp ( V_27 -> V_33 , V_36 ,
sizeof ( V_27 -> V_33 ) ) != 0 ) {
F_14 ( L_16 ,
V_36 , V_27 -> V_33 ) ;
return false ;
}
F_11 ( L_17 ) ;
return true ;
}
static bool F_15 ( const T_2 * V_13 , struct V_37 * V_38 )
{
F_7 ( ! V_13 || ! V_38 ) ;
if ( V_39 != F_16 ( V_13 ) ) {
F_14 ( L_18 ) ;
return false ;
}
V_38 -> V_18 = F_10 ( V_13 + 0x12 ) ;
V_38 -> V_19 = F_10 ( V_13 + 0x14 ) ;
if ( ( V_38 -> V_18 != 4 ) || ( V_38 -> V_19 != 10 ) ) {
F_9 ( L_19
L_20 , 4 , 10 , V_38 -> V_18 , V_38 -> V_19 ) ;
return false ;
}
V_38 -> V_40 = F_16 ( V_13 + 0x08 ) ;
if ( V_38 -> V_40 == 0 ) {
F_9 ( L_21 ) ;
return false ;
}
V_38 -> V_41 = F_16 ( V_13 + 0x0C ) ;
V_38 -> V_42 = F_16 ( V_13 + 0x04 ) ;
F_11 ( L_22 ) ;
return true ;
}
static bool F_17 ( const struct V_14 * V_43 ,
const struct V_14 * V_44 )
{
F_7 ( ! V_43 || ! V_44 ) ;
return ( ( V_43 -> V_18 == V_44 -> V_18 ) &&
( V_43 -> V_19 == V_44 -> V_19 ) &&
( V_43 -> V_20 == V_44 -> V_20 ) &&
( V_43 -> V_21 == V_44 -> V_21 ) &&
( V_43 -> V_22 == V_44 -> V_22 ) &&
( V_43 -> V_23 == V_44 -> V_23 ) &&
! memcmp ( V_43 -> V_25 , V_44 -> V_25 , V_45 ) ) ;
}
static bool F_18 ( const struct V_26 * V_46 ,
const struct V_26 * V_47 )
{
F_7 ( ! V_46 || ! V_47 ) ;
return ( ( V_46 -> V_30 == V_47 -> V_30 ) &&
( V_46 -> V_31 == V_47 -> V_31 ) &&
( V_46 -> V_34 == V_47 -> V_34 ) &&
( V_46 -> V_35 == V_47 -> V_35 ) &&
! strncmp ( V_46 -> V_29 , V_47 -> V_29 ,
sizeof ( V_46 -> V_29 ) ) &&
! strncmp ( V_46 -> V_33 , V_47 -> V_33 ,
sizeof ( V_46 -> V_33 ) ) ) ;
}
static bool F_19 ( struct V_48 * V_49 ,
struct V_14 * V_43 )
{
static const int V_50 [ 3 ] = { V_51 , V_52 , V_53 } ;
struct V_14 * V_15 [ 3 ] = { V_43 } ;
T_3 V_54 ;
T_2 * V_13 ;
bool V_55 = false ;
long V_56 ;
int V_10 ;
F_7 ( ! V_49 || ! V_43 ) ;
V_15 [ 1 ] = F_20 ( sizeof ( * V_15 [ 1 ] ) , V_57 ) ;
V_15 [ 2 ] = F_20 ( sizeof ( * V_15 [ 2 ] ) , V_57 ) ;
if ( ! V_15 [ 1 ] || ! V_15 [ 2 ] ) {
F_14 ( L_23 ) ;
goto V_58;
}
V_15 [ 0 ] -> V_22 = 0 ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
V_13 = F_21 ( V_49 , V_15 [ 0 ] -> V_22 + V_50 [ V_10 ] ,
& V_54 ) ;
if ( ! V_13 ) {
F_14 ( L_24 ) ;
goto V_58;
}
V_55 = F_6 ( V_13 , V_15 [ V_10 ] ) ;
F_22 ( V_54 ) ;
if ( ! V_55 ) {
F_9 ( L_25 , V_10 + 1 ) ;
if ( V_10 < 2 )
goto V_58;
else
break;
}
}
V_56 = V_49 -> V_59 -> V_60 -> V_61 >> 9 ;
if ( ( V_15 [ 0 ] -> V_22 > V_56 ) ||
( ( V_15 [ 0 ] -> V_22 + V_15 [ 0 ] -> V_23 ) > V_56 ) ) {
F_14 ( L_26 ) ;
goto V_58;
}
if ( ( V_15 [ 0 ] -> V_20 > V_15 [ 0 ] -> V_22 ) ||
( ( V_15 [ 0 ] -> V_20 + V_15 [ 0 ] -> V_21 )
> V_15 [ 0 ] -> V_22 ) ) {
F_14 ( L_27 ) ;
goto V_58;
}
if ( ! F_17 ( V_15 [ 0 ] , V_15 [ 1 ] ) ) {
F_14 ( L_28 ) ;
goto V_58;
}
F_11 ( L_29 ) ;
V_55 = true ;
V_58:
F_23 ( V_15 [ 1 ] ) ;
F_23 ( V_15 [ 2 ] ) ;
return V_55 ;
}
static bool F_24 ( struct V_48 * V_49 ,
unsigned long V_62 , struct V_63 * V_64 )
{
static const int V_50 [ 4 ] = { V_65 , V_66 , V_67 , V_68 } ;
struct V_26 * V_69 [ 4 ] ;
struct V_14 * V_15 ;
T_3 V_54 ;
T_2 * V_13 ;
int V_10 , V_70 ;
bool V_55 = false ;
F_7 ( ! V_49 || ! V_64 ) ;
V_15 = & V_64 -> V_15 ;
V_69 [ 0 ] = & V_64 -> V_27 ;
V_69 [ 1 ] = F_20 ( sizeof( * V_69 [ 1 ] ) * 3 , V_57 ) ;
if ( ! V_69 [ 1 ] ) {
F_14 ( L_23 ) ;
goto V_71;
}
V_69 [ 2 ] = (struct V_26 * ) ( ( T_2 * ) V_69 [ 1 ] + sizeof( * V_69 [ 1 ] ) ) ;
V_69 [ 3 ] = (struct V_26 * ) ( ( T_2 * ) V_69 [ 2 ] + sizeof( * V_69 [ 2 ] ) ) ;
for ( V_70 = V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
V_13 = F_21 ( V_49 , V_62 + V_50 [ V_10 ] , & V_54 ) ;
if ( ! V_13 ) {
F_9 ( L_30 , V_10 ) ;
continue;
}
if ( F_13 ( V_13 , V_69 [ V_70 ] ) )
V_70 ++ ;
F_22 ( V_54 ) ;
}
if ( ! V_70 ) {
F_14 ( L_31 ) ;
goto V_71;
}
if ( ( ( V_69 [ 0 ] -> V_30 + V_69 [ 0 ] -> V_31 ) > V_15 -> V_23 ) ||
( ( V_69 [ 0 ] -> V_34 + V_69 [ 0 ] -> V_35 ) >
V_15 -> V_23 ) ) {
F_14 ( L_32 ) ;
goto V_71;
}
for ( V_10 = 1 ; V_10 < V_70 ; V_10 ++ ) {
if ( ! F_18 ( V_69 [ 0 ] , V_69 [ V_10 ] ) ) {
F_14 ( L_33 , V_10 ) ;
goto V_71;
}
}
F_11 ( L_34 , V_70 ) ;
V_55 = true ;
V_71:
F_23 ( V_69 [ 1 ] ) ;
return V_55 ;
}
static bool F_25 ( struct V_48 * V_49 ,
unsigned long V_62 , struct V_63 * V_64 )
{
T_3 V_54 ;
T_2 * V_13 ;
bool V_55 = false ;
struct V_37 * V_38 ;
struct V_26 * V_27 ;
F_7 ( ! V_49 || ! V_64 ) ;
V_38 = & V_64 -> V_38 ;
V_27 = & V_64 -> V_27 ;
V_13 = F_21 ( V_49 , V_62 + V_72 , & V_54 ) ;
if ( ! V_13 ) {
F_14 ( L_24 ) ;
return false ;
}
if ( ! F_15 ( V_13 , V_38 ) )
goto V_58;
if ( F_10 ( V_13 + 0x10 ) != 0x01 ) {
F_14 ( L_35 ) ;
goto V_58;
}
if ( V_38 -> V_41 != 512 )
F_12 ( L_36 , V_38 -> V_41 ) ;
if ( ( V_38 -> V_40 * V_38 -> V_42 ) > ( V_27 -> V_31 << 9 ) ) {
F_14 ( L_37
L_38 ) ;
goto V_58;
}
V_55 = true ;
V_58:
F_22 ( V_54 ) ;
return V_55 ;
}
static bool F_26 ( struct V_48 * V_49 )
{
T_3 V_54 ;
T_2 * V_13 ;
struct V_73 * V_74 ;
int V_10 ;
bool V_55 = false ;
F_7 ( ! V_49 ) ;
V_13 = F_21 ( V_49 , 0 , & V_54 ) ;
if ( ! V_13 ) {
F_12 ( L_24 ) ;
return false ;
}
if ( * ( V_75 * ) ( V_13 + 0x01FE ) != F_27 ( V_76 ) )
goto V_58;
V_74 = (struct V_73 * ) ( V_13 + 0x01BE ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ , V_74 ++ )
if ( F_28 ( V_74 ) == V_77 ) {
V_55 = true ;
break;
}
if ( V_55 )
F_11 ( L_39 ) ;
V_58:
F_22 ( V_54 ) ;
return V_55 ;
}
static struct V_78 * F_29 ( const struct V_63 * V_64 )
{
struct V_79 * V_80 ;
F_7 ( ! V_64 ) ;
F_30 (item, &ldb->v_disk) {
struct V_78 * V_12 = F_31 ( V_80 , struct V_78 , V_81 ) ;
if ( ! memcmp ( V_12 -> V_78 . V_82 . V_25 , V_64 -> V_15 . V_25 , V_45 ) )
return V_12 ;
}
return NULL ;
}
static bool F_32 ( struct V_48 * V_83 ,
const struct V_63 * V_64 )
{
struct V_79 * V_80 ;
struct V_78 * V_84 ;
struct V_78 * V_82 ;
struct V_85 * V_86 ;
int V_87 = 1 ;
F_7 ( ! V_83 || ! V_64 ) ;
V_82 = F_29 ( V_64 ) ;
if ( ! V_82 ) {
F_14 ( L_40 ) ;
return false ;
}
F_33 ( V_83 -> V_88 , L_41 , V_89 ) ;
F_30 (item, &ldb->v_part) {
V_84 = F_31 ( V_80 , struct V_78 , V_81 ) ;
V_86 = & V_84 -> V_78 . V_86 ;
if ( V_86 -> V_25 != V_82 -> V_90 )
continue;
F_34 ( V_83 , V_87 , V_64 -> V_15 . V_20 +
V_86 -> V_91 , V_86 -> V_9 ) ;
V_87 ++ ;
}
F_33 ( V_83 -> V_88 , L_42 , V_89 ) ;
return true ;
}
static int F_35 ( const T_2 * V_92 , int V_93 , int V_62 , int V_94 )
{
V_62 += V_94 ;
if ( ! V_92 || V_94 < 0 || V_62 > V_93 ) {
if ( ! V_92 )
F_9 ( L_43 ) ;
if ( V_94 < 0 )
F_9 ( L_44 , V_94 ) ;
if ( V_62 > V_93 )
F_9 ( L_45 , V_62 , V_93 ) ;
return - 1 ;
}
if ( V_62 + V_92 [ V_62 ] >= V_93 ) {
F_9 ( L_46 , V_62 ,
V_92 [ V_62 ] , V_93 ) ;
return - 1 ;
}
return V_92 [ V_62 ] + V_94 + 1 ;
}
static T_4 F_36 ( const T_2 * V_95 )
{
T_4 V_96 = 0 ;
T_2 V_97 ;
F_7 ( ! V_95 ) ;
V_97 = * V_95 ++ ;
if ( V_97 && V_97 <= 8 )
while ( V_97 -- )
V_96 = ( V_96 << 8 ) | * V_95 ++ ;
else
F_9 ( L_47 , V_97 ) ;
return V_96 ;
}
static int F_37 ( const T_2 * V_95 , T_2 * V_92 , int V_93 )
{
int V_97 ;
F_7 ( ! V_95 || ! V_92 ) ;
V_97 = V_95 [ 0 ] ;
if ( V_97 >= V_93 ) {
F_9 ( L_48 , V_97 , V_93 ) ;
V_97 = V_93 - 1 ;
}
memcpy ( V_92 , V_95 + 1 , V_97 ) ;
V_92 [ V_97 ] = 0 ;
return V_97 ;
}
static bool F_38 ( const T_2 * V_92 , int V_93 , struct V_78 * V_84 )
{
int V_98 , V_99 , V_100 , V_101 , V_102 , V_103 , V_104 , V_105 ;
struct V_106 * V_107 ;
F_7 ( ! V_92 || ! V_84 ) ;
V_98 = F_35 ( V_92 , V_93 , 0x18 , 0 ) ;
V_99 = F_35 ( V_92 , V_93 , 0x18 , V_98 ) ;
V_100 = F_35 ( V_92 , V_93 , 0x18 , V_99 ) ;
V_101 = F_35 ( V_92 , V_93 , 0x1D , V_100 ) ;
V_102 = F_35 ( V_92 , V_93 , 0x2D , V_101 ) ;
if ( V_92 [ 0x12 ] & V_108 ) {
V_103 = F_35 ( V_92 , V_93 , 0x2E , V_102 ) ;
V_104 = F_35 ( V_92 , V_93 , 0x2E , V_103 ) ;
V_105 = V_104 ;
} else {
V_103 = 0 ;
V_104 = 0 ;
V_105 = V_102 ;
}
if ( V_105 < 0 )
return false ;
V_105 += V_109 ;
if ( V_105 != F_16 ( V_92 + 0x14 ) )
return false ;
V_107 = & V_84 -> V_78 . V_107 ;
F_37 ( V_92 + 0x18 + V_99 , V_107 -> V_49 ,
sizeof ( V_107 -> V_49 ) ) ;
V_107 -> type = V_92 [ 0x18 + V_100 ] ;
V_107 -> V_110 = F_36 ( V_92 + 0x1D + V_100 ) ;
V_107 -> V_111 = F_36 ( V_92 + 0x2D + V_101 ) ;
V_107 -> V_112 = V_103 ? F_36 ( V_92 + V_102 + 0x2E ) : 0 ;
return true ;
}
static int F_39 ( const T_2 * V_92 , int V_93 , struct V_78 * V_84 )
{
int V_98 , V_99 , V_113 , V_114 , V_115 , V_105 ;
struct V_116 * V_117 ;
F_7 ( ! V_92 || ! V_84 ) ;
V_98 = F_35 ( V_92 , V_93 , 0x18 , 0 ) ;
V_99 = F_35 ( V_92 , V_93 , 0x18 , V_98 ) ;
V_113 = F_35 ( V_92 , V_93 , 0x18 , V_99 ) ;
if ( V_92 [ 0x12 ] & V_118 ) {
V_114 = F_35 ( V_92 , V_93 , 0x24 , V_113 ) ;
V_115 = F_35 ( V_92 , V_93 , 0x24 , V_114 ) ;
V_105 = V_115 ;
} else {
V_114 = 0 ;
V_115 = 0 ;
V_105 = V_113 ;
}
if ( V_105 < 0 )
return false ;
V_105 += V_119 ;
if ( V_105 != F_16 ( V_92 + 0x14 ) )
return false ;
V_117 = & V_84 -> V_78 . V_117 ;
F_37 ( V_92 + 0x18 + V_99 , V_117 -> V_25 ,
sizeof ( V_117 -> V_25 ) ) ;
return true ;
}
static bool F_40 ( const T_2 * V_92 , int V_93 , struct V_78 * V_84 )
{
char V_4 [ 64 ] ;
int V_98 , V_99 , V_114 , V_115 , V_105 ;
struct V_116 * V_117 ;
F_7 ( ! V_92 || ! V_84 ) ;
V_98 = F_35 ( V_92 , V_93 , 0x18 , 0 ) ;
V_99 = F_35 ( V_92 , V_93 , 0x18 , V_98 ) ;
if ( V_92 [ 0x12 ] & V_120 ) {
V_114 = F_35 ( V_92 , V_93 , 0x44 , V_99 ) ;
V_115 = F_35 ( V_92 , V_93 , 0x44 , V_114 ) ;
V_105 = V_115 ;
} else {
V_114 = 0 ;
V_115 = 0 ;
V_105 = V_99 ;
}
if ( V_105 < 0 )
return false ;
V_105 += V_121 ;
if ( V_105 != F_16 ( V_92 + 0x14 ) )
return false ;
V_117 = & V_84 -> V_78 . V_117 ;
F_37 ( V_92 + 0x18 + V_98 , V_4 , sizeof ( V_4 ) ) ;
return true ;
}
static bool F_41 ( const T_2 * V_92 , int V_93 , struct V_78 * V_84 )
{
int V_98 , V_99 , V_113 , V_122 , V_105 ;
struct V_123 * V_82 ;
F_7 ( ! V_92 || ! V_84 ) ;
V_98 = F_35 ( V_92 , V_93 , 0x18 , 0 ) ;
V_99 = F_35 ( V_92 , V_93 , 0x18 , V_98 ) ;
V_113 = F_35 ( V_92 , V_93 , 0x18 , V_99 ) ;
V_122 = F_35 ( V_92 , V_93 , 0x18 , V_113 ) ;
V_105 = V_122 ;
if ( V_105 < 0 )
return false ;
V_105 += V_124 ;
if ( V_105 != F_16 ( V_92 + 0x14 ) )
return false ;
V_82 = & V_84 -> V_78 . V_82 ;
F_37 ( V_92 + 0x18 + V_113 , V_82 -> V_125 ,
sizeof ( V_82 -> V_125 ) ) ;
if ( ! F_5 ( V_92 + 0x19 + V_99 , V_82 -> V_25 ) )
return false ;
return true ;
}
static bool F_42 ( const T_2 * V_92 , int V_93 , struct V_78 * V_84 )
{
int V_98 , V_99 , V_105 ;
struct V_123 * V_82 ;
F_7 ( ! V_92 || ! V_84 ) ;
V_98 = F_35 ( V_92 , V_93 , 0x18 , 0 ) ;
V_99 = F_35 ( V_92 , V_93 , 0x18 , V_98 ) ;
V_105 = V_99 ;
if ( V_105 < 0 )
return false ;
V_105 += V_126 ;
if ( V_105 != F_16 ( V_92 + 0x14 ) )
return false ;
V_82 = & V_84 -> V_78 . V_82 ;
memcpy ( V_82 -> V_25 , V_92 + 0x18 + V_99 , V_45 ) ;
return true ;
}
static bool F_43 ( const T_2 * V_92 , int V_93 , struct V_78 * V_84 )
{
int V_98 , V_99 , V_127 , V_102 , V_113 , V_128 , V_105 ;
struct V_85 * V_86 ;
F_7 ( ! V_92 || ! V_84 ) ;
V_98 = F_35 ( V_92 , V_93 , 0x18 , 0 ) ;
if ( V_98 < 0 ) {
F_9 ( L_49 , V_98 ) ;
return false ;
}
V_99 = F_35 ( V_92 , V_93 , 0x18 , V_98 ) ;
if ( V_99 < 0 ) {
F_9 ( L_50 , V_99 ) ;
return false ;
}
V_127 = F_35 ( V_92 , V_93 , 0x34 , V_99 ) ;
if ( V_127 < 0 ) {
F_9 ( L_51 , V_127 ) ;
return false ;
}
V_102 = F_35 ( V_92 , V_93 , 0x34 , V_127 ) ;
if ( V_102 < 0 ) {
F_9 ( L_52 , V_102 ) ;
return false ;
}
V_113 = F_35 ( V_92 , V_93 , 0x34 , V_102 ) ;
if ( V_113 < 0 ) {
F_9 ( L_53 , V_113 ) ;
return false ;
}
if ( V_92 [ 0x12 ] & V_129 ) {
V_128 = F_35 ( V_92 , V_93 , 0x34 , V_113 ) ;
if ( V_128 < 0 ) {
F_9 ( L_54 , V_128 ) ;
return false ;
}
V_105 = V_128 ;
} else {
V_128 = 0 ;
V_105 = V_113 ;
}
if ( V_105 < 0 ) {
F_9 ( L_55 , V_105 ) ;
return false ;
}
V_105 += V_130 ;
if ( V_105 > F_16 ( V_92 + 0x14 ) ) {
F_9 ( L_56 , V_105 ,
F_16 ( V_92 + 0x14 ) ) ;
return false ;
}
V_86 = & V_84 -> V_78 . V_86 ;
V_86 -> V_91 = F_8 ( V_92 + 0x24 + V_99 ) ;
V_86 -> V_131 = F_8 ( V_92 + 0x2C + V_99 ) ;
V_86 -> V_9 = F_36 ( V_92 + 0x34 + V_99 ) ;
V_86 -> V_111 = F_36 ( V_92 + 0x34 + V_127 ) ;
V_86 -> V_25 = F_36 ( V_92 + 0x34 + V_102 ) ;
if ( V_84 -> V_132 & V_129 )
V_86 -> V_133 = V_92 [ 0x35 + V_113 ] ;
else
V_86 -> V_133 = 0 ;
return true ;
}
static bool F_44 ( const T_2 * V_92 , int V_93 , struct V_78 * V_84 )
{
int V_98 , V_99 , V_134 , V_135 , V_101 , V_127 ;
int V_114 , V_115 , V_136 , V_137 , V_105 ;
struct V_138 * V_139 ;
F_7 ( ! V_92 || ! V_84 ) ;
V_98 = F_35 ( V_92 , V_93 , 0x18 , 0 ) ;
if ( V_98 < 0 ) {
F_9 ( L_49 , V_98 ) ;
return false ;
}
V_99 = F_35 ( V_92 , V_93 , 0x18 , V_98 ) ;
if ( V_99 < 0 ) {
F_9 ( L_50 , V_99 ) ;
return false ;
}
V_134 = F_35 ( V_92 , V_93 , 0x18 , V_99 ) ;
if ( V_134 < 0 ) {
F_9 ( L_57 , V_134 ) ;
return false ;
}
V_135 = F_35 ( V_92 , V_93 , 0x18 , V_134 ) ;
if ( V_135 < 0 ) {
F_9 ( L_58 ,
V_135 ) ;
return false ;
}
V_101 = F_35 ( V_92 , V_93 , 0x2D , V_135 ) ;
if ( V_101 < 0 ) {
F_9 ( L_59 , V_101 ) ;
return false ;
}
V_127 = F_35 ( V_92 , V_93 , 0x3D , V_101 ) ;
if ( V_127 < 0 ) {
F_9 ( L_51 , V_127 ) ;
return false ;
}
if ( V_92 [ 0x12 ] & V_140 ) {
V_114 = F_35 ( V_92 , V_93 , 0x52 , V_127 ) ;
if ( V_114 < 0 ) {
F_9 ( L_60 , V_114 ) ;
return false ;
}
} else
V_114 = V_127 ;
if ( V_92 [ 0x12 ] & V_141 ) {
V_115 = F_35 ( V_92 , V_93 , 0x52 , V_114 ) ;
if ( V_115 < 0 ) {
F_9 ( L_61 , V_115 ) ;
return false ;
}
} else
V_115 = V_114 ;
if ( V_92 [ 0x12 ] & V_142 ) {
V_136 = F_35 ( V_92 , V_93 , 0x52 , V_115 ) ;
if ( V_136 < 0 ) {
F_9 ( L_62 , V_136 ) ;
return false ;
}
} else
V_136 = V_115 ;
if ( V_92 [ 0x12 ] & V_143 ) {
V_137 = F_35 ( V_92 , V_93 , 0x52 , V_136 ) ;
if ( V_137 < 0 ) {
F_9 ( L_63 , V_137 ) ;
return false ;
}
} else
V_137 = V_136 ;
V_105 = V_137 ;
if ( V_105 < 0 ) {
F_9 ( L_55 , V_105 ) ;
return false ;
}
V_105 += V_144 ;
if ( V_105 > F_16 ( V_92 + 0x14 ) ) {
F_9 ( L_56 , V_105 ,
F_16 ( V_92 + 0x14 ) ) ;
return false ;
}
V_139 = & V_84 -> V_78 . V_139 ;
F_37 ( V_92 + 0x18 + V_99 , V_139 -> V_145 ,
sizeof( V_139 -> V_145 ) ) ;
memcpy ( V_139 -> V_146 , V_92 + 0x18 + V_135 ,
sizeof( V_139 -> V_146 ) ) ;
V_139 -> V_9 = F_36 ( V_92 + 0x3D + V_101 ) ;
V_139 -> V_147 = V_92 [ 0x41 + V_127 ] ;
memcpy ( V_139 -> V_148 , V_92 + 0x42 + V_127 , sizeof( V_139 -> V_148 ) ) ;
if ( V_92 [ 0x12 ] & V_143 ) {
F_37 ( V_92 + 0x52 + V_127 , V_139 -> V_149 ,
sizeof( V_139 -> V_149 ) ) ;
}
return true ;
}
static bool F_45 ( const T_2 * V_4 , int V_105 , struct V_78 * V_84 )
{
bool V_55 = false ;
int V_98 ;
F_7 ( ! V_4 || ! V_84 ) ;
V_98 = F_35 ( V_4 , V_105 , 0x18 , 0 ) ;
if ( V_98 < 0 ) {
F_9 ( L_64 ) ;
return false ;
}
V_84 -> V_132 = V_4 [ 0x12 ] ;
V_84 -> type = V_4 [ 0x13 ] ;
V_84 -> V_90 = F_36 ( V_4 + 0x18 ) ;
F_37 ( V_4 + 0x18 + V_98 , V_84 -> V_150 , sizeof ( V_84 -> V_150 ) ) ;
switch ( V_84 -> type ) {
case V_151 : V_55 = F_38 ( V_4 , V_105 , V_84 ) ; break;
case V_152 : V_55 = F_41 ( V_4 , V_105 , V_84 ) ; break;
case V_153 : V_55 = F_42 ( V_4 , V_105 , V_84 ) ; break;
case V_154 : V_55 = F_39 ( V_4 , V_105 , V_84 ) ; break;
case V_155 : V_55 = F_40 ( V_4 , V_105 , V_84 ) ; break;
case V_156 : V_55 = F_43 ( V_4 , V_105 , V_84 ) ; break;
case V_157 : V_55 = F_44 ( V_4 , V_105 , V_84 ) ; break;
}
if ( V_55 )
F_11 ( L_65 ,
( unsigned long long ) V_84 -> V_90 , V_84 -> type ) ;
else
F_9 ( L_66 ,
( unsigned long long ) V_84 -> V_90 , V_84 -> type ) ;
return V_55 ;
}
static bool F_46 ( T_2 * V_13 , int V_105 , struct V_63 * V_64 )
{
struct V_78 * V_84 ;
struct V_79 * V_80 ;
F_7 ( ! V_13 || ! V_64 ) ;
V_84 = F_20 ( sizeof ( * V_84 ) , V_57 ) ;
if ( ! V_84 ) {
F_14 ( L_23 ) ;
return false ;
}
if ( ! F_45 ( V_13 , V_105 , V_84 ) ) {
F_23 ( V_84 ) ;
return false ;
}
switch ( V_84 -> type ) {
case V_154 :
case V_155 :
F_47 ( & V_84 -> V_81 , & V_64 -> V_158 ) ;
break;
case V_152 :
case V_153 :
F_47 ( & V_84 -> V_81 , & V_64 -> V_159 ) ;
break;
case V_157 :
F_47 ( & V_84 -> V_81 , & V_64 -> V_160 ) ;
break;
case V_151 :
F_47 ( & V_84 -> V_81 , & V_64 -> V_161 ) ;
break;
case V_156 :
F_30 (item, &ldb->v_part) {
struct V_78 * V_12 = F_31 ( V_80 , struct V_78 , V_81 ) ;
if ( ( V_12 -> V_78 . V_86 . V_25 == V_84 -> V_78 . V_86 . V_25 ) &&
( V_12 -> V_78 . V_86 . V_91 > V_84 -> V_78 . V_86 . V_91 ) ) {
F_48 ( & V_84 -> V_81 , & V_12 -> V_81 ) ;
return true ;
}
}
F_48 ( & V_84 -> V_81 , & V_64 -> V_162 ) ;
break;
}
return true ;
}
static bool F_49 ( const T_2 * V_13 , int V_9 , struct V_79 * V_163 )
{
struct V_164 * V_165 ;
struct V_79 * V_80 ;
int V_166 , V_167 , V_168 ;
F_7 ( ! V_13 || ! V_163 ) ;
if ( V_9 < 2 * V_169 ) {
F_9 ( L_67 ) ;
return false ;
}
V_168 = F_16 ( V_13 + 0x08 ) ;
V_166 = F_10 ( V_13 + 0x0C ) ;
V_167 = F_10 ( V_13 + 0x0E ) ;
if ( ( V_167 < 1 ) || ( V_167 > 4 ) ) {
F_9 ( L_68 , V_167 ) ;
return false ;
}
if ( V_166 >= V_167 ) {
F_9 ( L_69 , V_166 , V_167 ) ;
return false ;
}
F_30 (item, frags) {
V_165 = F_31 ( V_80 , struct V_164 , V_81 ) ;
if ( V_165 -> V_168 == V_168 )
goto V_170;
}
V_165 = F_20 ( sizeof ( * V_165 ) + V_9 * V_167 , V_57 ) ;
if ( ! V_165 ) {
F_14 ( L_23 ) ;
return false ;
}
V_165 -> V_168 = V_168 ;
V_165 -> V_167 = V_167 ;
V_165 -> V_166 = V_166 ;
V_165 -> V_171 = 0xFF << V_167 ;
F_48 ( & V_165 -> V_81 , V_163 ) ;
V_170:
if ( V_166 >= V_165 -> V_167 ) {
F_9 ( L_69 , V_166 , V_165 -> V_167 ) ;
return false ;
}
if ( V_165 -> V_171 & ( 1 << V_166 ) ) {
F_9 ( L_70 , V_166 ) ;
V_165 -> V_171 &= 0x7F ;
return false ;
}
V_165 -> V_171 |= ( 1 << V_166 ) ;
V_13 += V_169 ;
V_9 -= V_169 ;
memcpy ( V_165 -> V_13 + V_166 * ( V_9 - V_169 ) + V_169 , V_13 , V_9 ) ;
return true ;
}
static void F_50 ( struct V_79 * V_81 )
{
struct V_79 * V_80 , * V_96 ;
F_7 ( ! V_81 ) ;
F_51 (item, tmp, list)
F_23 ( F_31 ( V_80 , struct V_164 , V_81 ) ) ;
}
static bool F_52 ( struct V_79 * V_163 , struct V_63 * V_64 )
{
struct V_164 * V_165 ;
struct V_79 * V_80 ;
F_7 ( ! V_163 || ! V_64 ) ;
F_30 (item, frags) {
V_165 = F_31 ( V_80 , struct V_164 , V_81 ) ;
if ( V_165 -> V_171 != 0xFF ) {
F_9 ( L_71 ,
V_165 -> V_168 , V_165 -> V_171 ) ;
return false ;
}
if ( ! F_46 ( V_165 -> V_13 , V_165 -> V_167 * V_64 -> V_38 . V_40 , V_64 ) )
return false ;
}
return true ;
}
static bool F_53 ( struct V_48 * V_49 , unsigned long V_62 ,
struct V_63 * V_64 )
{
int V_9 , V_172 , V_173 , V_174 , V_175 , V_12 , V_176 ;
T_2 * V_13 = NULL ;
T_3 V_54 ;
bool V_55 = false ;
F_54 ( V_163 ) ;
F_7 ( ! V_49 || ! V_64 ) ;
V_9 = V_64 -> V_38 . V_40 ;
V_172 = 512 / V_9 ;
V_173 = V_64 -> V_38 . V_41 >> 9 ;
V_174 = ( V_9 * V_64 -> V_38 . V_42 ) >> 9 ;
for ( V_175 = V_173 ; V_175 < V_174 ; V_175 ++ ) {
V_13 = F_21 ( V_49 , V_62 + V_72 + V_175 , & V_54 ) ;
if ( ! V_13 ) {
F_14 ( L_24 ) ;
goto V_58;
}
for ( V_12 = 0 ; V_12 < V_172 ; V_12 ++ , V_13 += V_9 ) {
if ( V_177 != F_16 ( V_13 ) ) {
F_9 ( L_72 ) ;
goto V_58;
}
V_176 = F_10 ( V_13 + 0x0E ) ;
if ( V_176 == 1 ) {
if ( ! F_46 ( V_13 , V_9 , V_64 ) )
goto V_58;
} else if ( V_176 > 1 ) {
if ( ! F_49 ( V_13 , V_9 , & V_163 ) )
goto V_58;
}
}
F_22 ( V_54 ) ;
V_13 = NULL ;
}
V_55 = F_52 ( & V_163 , V_64 ) ;
V_58:
if ( V_13 )
F_22 ( V_54 ) ;
F_50 ( & V_163 ) ;
return V_55 ;
}
static void F_55 ( struct V_79 * V_178 )
{
struct V_79 * V_80 , * V_96 ;
F_7 ( ! V_178 ) ;
F_51 (item, tmp, lh)
F_23 ( F_31 ( V_80 , struct V_78 , V_81 ) ) ;
}
int F_56 ( struct V_48 * V_49 )
{
struct V_63 * V_64 ;
unsigned long V_62 ;
int V_55 = - 1 ;
F_7 ( ! V_49 ) ;
if ( ! F_26 ( V_49 ) )
return 0 ;
V_64 = F_20 ( sizeof ( * V_64 ) , V_57 ) ;
if ( ! V_64 ) {
F_14 ( L_23 ) ;
goto V_58;
}
if ( ! F_19 ( V_49 , & V_64 -> V_15 ) )
goto V_58;
V_62 = V_64 -> V_15 . V_22 ;
if ( ! F_24 ( V_49 , V_62 , V_64 ) ||
! F_25 ( V_49 , V_62 , V_64 ) )
goto V_58;
F_57 ( & V_64 -> V_158 ) ;
F_57 ( & V_64 -> V_159 ) ;
F_57 ( & V_64 -> V_160 ) ;
F_57 ( & V_64 -> V_161 ) ;
F_57 ( & V_64 -> V_162 ) ;
if ( ! F_53 ( V_49 , V_62 , V_64 ) ) {
F_14 ( L_73 ) ;
goto V_179;
}
if ( F_32 ( V_49 , V_64 ) ) {
F_11 ( L_74 ) ;
V_55 = 1 ;
}
V_179:
F_55 ( & V_64 -> V_158 ) ;
F_55 ( & V_64 -> V_159 ) ;
F_55 ( & V_64 -> V_160 ) ;
F_55 ( & V_64 -> V_161 ) ;
F_55 ( & V_64 -> V_162 ) ;
V_58:
F_23 ( V_64 ) ;
return V_55 ;
}
