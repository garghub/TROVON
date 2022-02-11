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
#ifdef F_19
F_20 ( L_1 ,
V_3 -> V_61 [ 0 ] . V_80 , V_72 ) ;
#endif
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
V_75 = F_8 ( V_81 ,
V_14 ,
V_15
) ;
* V_68 = V_72 ;
* V_69 = V_73 ;
* V_70 = V_74 ;
* V_71 = V_75 ;
}
unsigned char
F_21 (
void * V_1 ,
bool V_82
)
{
T_2 V_3 = ( T_2 ) V_1 ;
if ( V_82 )
return V_3 -> V_83 ;
else
return V_3 -> V_84 ;
}
bool
F_22 (
void * V_85 ,
unsigned long V_86 ,
void * V_87
)
{
T_2 V_3 = ( T_2 ) V_85 ;
if ( V_86 > V_88 )
return false ;
V_3 -> V_89 . V_90 = V_86 ;
memcpy ( V_3 -> V_89 . V_91 , V_87 , ( V_86 * sizeof( V_92 ) ) ) ;
return true ;
}
unsigned short
F_23 (
void * V_85
)
{
unsigned short V_55 = V_81 ;
T_2 V_3 = ( T_2 ) V_85 ;
for ( V_55 = V_81 ; V_55 > V_17 ; V_55 -- ) {
if ( V_3 -> V_61 [ 0 ] . V_93 & ( 1 << V_55 ) )
return V_55 ;
}
if ( V_3 -> V_39 == V_78 )
return V_94 ;
else
return V_17 ;
}
void
F_24 (
void * V_85 ,
bool V_95
)
{
T_2 V_3 = ( T_2 ) V_85 ;
V_3 -> V_95 = V_95 ;
}
bool
F_25 (
void * V_85 ,
bool V_96 ,
void * V_97 ,
unsigned char V_98 ,
unsigned char V_99 ,
unsigned char V_100 ,
unsigned char * V_101
)
{
T_2 V_3 = ( T_2 ) V_85 ;
unsigned char * V_102 = ( unsigned char * ) ( V_3 -> V_103 ) ;
if ( ( V_97 != NULL ) &&
( V_3 -> V_104 < ( V_105 - sizeof( V_106 ) - sizeof( V_107 ) - 3 ) )
) {
V_3 -> V_103 -> V_108 = V_109 ;
V_3 -> V_103 -> V_20 = 3 ;
V_3 -> V_103 -> V_110 = ( ( V_111 ) V_97 ) -> V_110 ;
V_3 -> V_103 -> V_112 = V_98 ;
V_3 -> V_103 -> V_113 = ( ( V_111 ) V_97 ) -> V_113 ;
switch ( V_3 -> V_103 -> V_113 ) {
case V_114 :
V_3 -> V_103 -> V_20 += sizeof( V_115 ) ;
memcpy ( & ( V_3 -> V_103 -> V_116 . V_117 ) ,
& ( ( ( V_111 ) V_97 ) -> V_118 ) ,
sizeof( V_119 ) ) ;
V_3 -> V_103 -> V_116 . V_117 . V_120 = V_99 ;
break;
case V_121 :
V_3 -> V_103 -> V_20 += sizeof( V_122 ) ;
memcpy ( & ( V_3 -> V_103 -> V_116 . V_123 ) ,
& ( ( ( V_111 ) V_97 ) -> V_118 ) ,
sizeof( V_119 ) ) ;
V_3 -> V_103 -> V_116 . V_123 . V_124 = V_100 ;
break;
case V_125 :
V_3 -> V_103 -> V_20 += sizeof( V_126 ) ;
memcpy ( & ( V_3 -> V_103 -> V_116 . V_127 ) ,
& ( ( ( V_111 ) V_97 ) -> V_118 ) ,
sizeof( V_119 ) ) ;
memcpy ( V_3 -> V_103 -> V_116 . V_127 . V_128 , V_101 , 8 ) ;
break;
default:
break;
}
V_102 += ( 2 + V_3 -> V_103 -> V_20 ) ;
V_3 -> V_104 += ( 2 + V_3 -> V_103 -> V_20 ) ;
V_3 -> V_103 = ( V_129 ) V_102 ;
}
if ( V_96 )
F_26 ( V_3 ) ;
return true ;
}
bool
F_27 (
void * V_85 ,
unsigned char V_130
)
{
T_2 V_3 = ( T_2 ) V_85 ;
V_3 -> V_12 = V_130 ;
V_3 -> V_131 = false ;
return true ;
}
