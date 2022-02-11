void
F_1 (
void * V_1 ,
T_1 V_2
)
{
T_2 V_3 = ( T_2 ) V_1 ;
V_3 -> V_4 = V_2 ;
}
void
F_2 (
void * V_1 ,
unsigned short V_5 ,
unsigned short V_6 ,
unsigned int V_7
)
{
T_2 V_3 = ( T_2 ) V_1 ;
V_3 -> V_8 = V_5 ;
V_3 -> V_9 = V_6 ;
V_3 -> V_10 = V_7 ;
}
T_3
F_3 (
void * V_1
)
{
T_2 V_3 = ( T_2 ) V_1 ;
return ( T_3 ) V_3 -> V_11 ;
}
unsigned int
F_4 (
void * V_1
)
{
T_2 V_3 = ( T_2 ) V_1 ;
if ( V_1 != NULL )
return V_3 -> V_12 ;
return 0 ;
}
unsigned short
F_5 (
void * V_1
)
{
T_2 V_3 = ( T_2 ) V_1 ;
return V_3 -> V_13 ;
}
unsigned char
F_6 (
T_4 V_14 ,
T_4 V_15
)
{
unsigned char V_16 = V_17 ;
unsigned char V_18 = V_17 ;
unsigned int V_19 = 0 ;
if ( V_14 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ ) {
V_18 = F_7 ( V_14 -> V_21 [ V_19 ] ) ;
if ( V_18 > V_16 )
V_16 = V_18 ;
}
}
if ( V_15 ) {
for ( V_19 = 0 ; V_19 < V_15 -> V_20 ; V_19 ++ ) {
V_18 = F_7 ( V_15 -> V_21 [ V_19 ] ) ;
if ( V_18 > V_16 )
V_16 = V_18 ;
}
}
return V_16 ;
}
unsigned char
F_8 (
unsigned char V_22 ,
T_4 V_14 ,
T_4 V_15
)
{
unsigned char V_23 ;
unsigned char V_24 ;
unsigned int V_19 ;
if ( V_22 <= V_25 ) {
V_23 = V_17 ;
} else {
V_23 = V_26 ;
}
if ( V_14 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ ) {
if ( V_14 -> V_21 [ V_19 ] & 0x80 ) {
V_24 = F_7 ( V_14 -> V_21 [ V_19 ] ) ;
if ( ( V_24 <= V_22 ) &&
( V_24 > V_23 ) ) {
V_23 = V_24 ;
}
}
}
}
if ( V_15 ) {
for ( V_19 = 0 ; V_19 < V_15 -> V_20 ; V_19 ++ ) {
if ( V_15 -> V_21 [ V_19 ] & 0x80 ) {
V_24 = F_7 ( V_15 -> V_21 [ V_19 ] ) ;
if ( ( V_24 <= V_22 ) &&
( V_24 > V_23 ) ) {
V_23 = V_24 ;
}
}
}
}
return V_23 ;
}
void
F_9 (
void * V_1 ,
T_5 V_27
)
{
T_2 V_3 = ( T_2 ) V_1 ;
V_3 -> V_28 = V_27 ;
if ( ( V_27 == V_29 ) ||
( V_27 == V_30 ) ) {
V_3 -> V_31 = true ;
} else {
V_3 -> V_31 = false ;
}
}
void
F_10 (
void * V_1 ,
T_6 V_32
)
{
T_2 V_3 = ( T_2 ) V_1 ;
V_3 -> V_32 = V_32 ;
if ( ( V_32 == V_33 ) ||
( V_32 == V_34 ) ||
( V_32 == V_35 ) ) {
V_3 -> V_36 = true ;
} else {
V_3 -> V_36 = false ;
}
}
bool
F_11 (
void * V_1 ,
T_7 V_37
)
{
T_2 V_3 = ( T_2 ) V_1 ;
if ( ( V_37 != V_38 ) &&
( V_37 != V_3 -> V_39 ) ) {
if ( F_12 ( V_3 -> V_40 , V_37 , 0 , 0 , NULL , NULL ) == true )
V_3 -> V_39 = V_37 ;
else
return false ;
}
V_3 -> V_41 = V_37 ;
return true ;
}
void
F_13 (
void * V_1 ,
void * V_42
)
{
T_2 V_3 = ( T_2 ) V_1 ;
if ( ( V_3 != NULL ) && ( V_42 != NULL ) )
* ( V_43 ) V_42 = V_3 -> V_41 ;
}
void
F_14 ( void * V_1 , unsigned int * V_44 , void * * V_45 )
{
unsigned int V_19 = 0 ;
T_2 V_3 = ( T_2 ) V_1 ;
T_8 V_46 = NULL ;
unsigned int V_47 = 0 ;
* V_45 = NULL ;
for ( V_19 = 0 ; V_19 < V_48 ; V_19 ++ ) {
V_46 = & ( V_3 -> V_49 [ V_19 ] ) ;
if ( ! V_46 -> V_50 )
continue;
if ( * V_45 == NULL )
* V_45 = & ( V_3 -> V_49 [ V_19 ] ) ;
V_47 ++ ;
}
* V_44 = V_47 ;
}
void
F_15 (
void * V_1 ,
void * V_51 ,
void * * V_52
)
{
T_8 V_46 = ( T_8 ) V_51 ;
T_2 V_3 = ( T_2 ) V_1 ;
* V_52 = NULL ;
while ( * V_52 == NULL ) {
V_46 ++ ;
if ( V_46 > & ( V_3 -> V_49 [ V_48 ] ) )
return;
if ( V_46 -> V_50 == true ) {
* V_52 = V_46 ;
return;
}
}
}
void
F_16 (
void * V_1 ,
unsigned char * V_53 ,
bool V_54 ,
unsigned short V_55 ,
unsigned char * V_56
)
{
T_2 V_3 = ( T_2 ) V_1 ;
unsigned int V_57 = 0 ;
unsigned int V_19 ;
if ( ( V_3 -> V_58 == V_59 ) ||
( V_3 -> V_58 == V_60 ) ) {
if ( F_17 ( V_3 , V_53 , & V_57 ) == false )
return;
}
V_3 -> V_61 [ V_57 ] . V_62 ++ ;
if ( V_54 ) {
V_3 -> V_61 [ V_57 ] . V_63 [ V_64 ] ++ ;
V_3 -> V_61 [ V_57 ] . V_63 [ V_55 ] ++ ;
} else {
V_3 -> V_61 [ V_57 ] . V_65 ++ ;
}
V_3 -> V_61 [ V_57 ] . V_66 += V_56 [ V_64 ] ;
for ( V_19 = 0 ; V_19 < V_64 ; V_19 ++ )
V_3 -> V_61 [ V_57 ] . V_67 [ V_19 ] += V_56 [ V_19 ] ;
}
void
F_18 (
void * V_1 ,
unsigned char * V_53 ,
unsigned short * V_68 ,
unsigned char * V_69 ,
unsigned char * V_70 ,
unsigned char * V_71
)
{
T_2 V_3 = ( T_2 ) V_1 ;
unsigned int V_57 = 0 ;
unsigned short V_72 = V_17 ;
unsigned char V_73 = V_17 ;
unsigned char V_74 = V_17 ;
unsigned char V_75 = V_26 ;
T_4 V_14 = NULL ;
T_4 V_15 = NULL ;
if ( ( V_3 -> V_58 == V_59 ) ||
( V_3 -> V_58 == V_60 ) ) {
if ( F_17 ( V_3 , V_53 , & V_57 ) ) {
V_72 = ( V_3 -> V_61 [ V_57 ] . V_72 ) ;
V_14 = ( T_4 ) ( V_3 -> V_61 [ V_57 ] . V_76 ) ;
V_15 = ( T_4 ) ( V_3 -> V_61 [ V_57 ] . V_77 ) ;
} else {
if ( V_3 -> V_39 != V_78 )
V_72 = V_79 ;
else
V_72 = V_26 ;
V_14 = ( T_4 ) V_3 -> V_76 ;
V_15 = ( T_4 ) V_3 -> V_77 ;
}
} else {
V_72 = ( V_3 -> V_61 [ 0 ] . V_72 ) ;
V_14 = ( T_4 ) V_3 -> V_76 ;
V_15 = ( T_4 ) V_3 -> V_77 ;
}
V_73 = F_8 ( ( unsigned char ) V_72 ,
V_14 ,
V_15
) ;
if ( V_73 > ( unsigned char ) V_72 )
V_73 = ( unsigned char ) V_72 ;
V_74 = F_8 ( V_25 ,
V_14 ,
V_15
) ;
V_75 = F_8 ( V_80 ,
V_14 ,
V_15
) ;
* V_68 = V_72 ;
* V_69 = V_73 ;
* V_70 = V_74 ;
* V_71 = V_75 ;
}
unsigned char
F_19 (
void * V_1 ,
bool V_81
)
{
T_2 V_3 = ( T_2 ) V_1 ;
if ( V_81 )
return V_3 -> V_82 ;
else
return V_3 -> V_83 ;
}
bool
F_20 (
void * V_84 ,
unsigned long V_85 ,
void * V_86
)
{
T_2 V_3 = ( T_2 ) V_84 ;
if ( V_85 > V_87 )
return false ;
V_3 -> V_88 . V_89 = V_85 ;
memcpy ( V_3 -> V_88 . V_90 , V_86 , ( V_85 * sizeof( V_91 ) ) ) ;
return true ;
}
unsigned short
F_21 (
void * V_84
)
{
unsigned short V_55 = V_80 ;
T_2 V_3 = ( T_2 ) V_84 ;
for ( V_55 = V_80 ; V_55 > V_17 ; V_55 -- ) {
if ( V_3 -> V_61 [ 0 ] . V_92 & ( 1 << V_55 ) )
return V_55 ;
}
if ( V_3 -> V_39 == V_78 )
return V_93 ;
else
return V_17 ;
}
void
F_22 (
void * V_84 ,
bool V_94
)
{
T_2 V_3 = ( T_2 ) V_84 ;
V_3 -> V_94 = V_94 ;
}
bool
F_23 (
void * V_84 ,
bool V_95 ,
void * V_96 ,
unsigned char V_97 ,
unsigned char V_98 ,
unsigned char V_99 ,
unsigned char * V_100
)
{
T_2 V_3 = ( T_2 ) V_84 ;
unsigned char * V_101 = ( unsigned char * ) ( V_3 -> V_102 ) ;
if ( ( V_96 != NULL ) &&
( V_3 -> V_103 < ( V_104 - sizeof( V_105 ) - sizeof( V_106 ) - 3 ) )
) {
V_3 -> V_102 -> V_107 = V_108 ;
V_3 -> V_102 -> V_20 = 3 ;
V_3 -> V_102 -> V_109 = ( ( V_110 ) V_96 ) -> V_109 ;
V_3 -> V_102 -> V_111 = V_97 ;
V_3 -> V_102 -> V_112 = ( ( V_110 ) V_96 ) -> V_112 ;
switch ( V_3 -> V_102 -> V_112 ) {
case V_113 :
V_3 -> V_102 -> V_20 += sizeof( V_114 ) ;
memcpy ( & ( V_3 -> V_102 -> V_115 . V_116 ) ,
& ( ( ( V_110 ) V_96 ) -> V_117 ) ,
sizeof( V_118 ) ) ;
V_3 -> V_102 -> V_115 . V_116 . V_119 = V_98 ;
break;
case V_120 :
V_3 -> V_102 -> V_20 += sizeof( V_121 ) ;
memcpy ( & ( V_3 -> V_102 -> V_115 . V_122 ) ,
& ( ( ( V_110 ) V_96 ) -> V_117 ) ,
sizeof( V_118 ) ) ;
V_3 -> V_102 -> V_115 . V_122 . V_123 = V_99 ;
break;
case V_124 :
V_3 -> V_102 -> V_20 += sizeof( V_125 ) ;
memcpy ( & ( V_3 -> V_102 -> V_115 . V_126 ) ,
& ( ( ( V_110 ) V_96 ) -> V_117 ) ,
sizeof( V_118 ) ) ;
memcpy ( V_3 -> V_102 -> V_115 . V_126 . V_127 , V_100 , 8 ) ;
break;
default:
break;
}
V_101 += ( 2 + V_3 -> V_102 -> V_20 ) ;
V_3 -> V_103 += ( 2 + V_3 -> V_102 -> V_20 ) ;
V_3 -> V_102 = ( V_128 ) V_101 ;
}
if ( V_95 )
F_24 ( V_3 ) ;
return true ;
}
bool
F_25 (
void * V_84 ,
unsigned char V_129
)
{
T_2 V_3 = ( T_2 ) V_84 ;
V_3 -> V_12 = V_129 ;
V_3 -> V_130 = false ;
return true ;
}
