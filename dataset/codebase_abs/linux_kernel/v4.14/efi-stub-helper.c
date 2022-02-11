int T_1 F_1 ( void )
{
return V_1 ;
}
int T_1 F_2 ( void )
{
return V_2 ;
}
void F_3 ( T_2 * V_3 , char * V_4 )
{
char * V_5 ;
for ( V_5 = V_4 ; * V_5 ; V_5 ++ ) {
T_3 V_6 [ 2 ] = { 0 } ;
V_6 [ 0 ] = * V_5 ;
if ( * V_5 == '\n' ) {
T_3 V_7 [ 2 ] = { '\r' , 0 } ;
F_4 ( V_3 , V_7 ) ;
}
F_4 ( V_3 , V_6 ) ;
}
}
static inline bool F_5 ( unsigned long V_8 ,
unsigned long V_9 ,
unsigned long V_10 )
{
unsigned long V_11 = V_8 - V_9 ;
return V_11 / V_10 >= V_12 ;
}
T_4 F_6 ( T_2 * V_3 ,
struct V_13 * V_14 )
{
T_5 * V_15 = NULL ;
T_4 V_16 ;
unsigned long V_17 ;
T_6 V_18 ;
* V_14 -> V_10 = sizeof( * V_15 ) ;
* V_14 -> V_9 = * V_14 -> V_10 * 32 ;
* V_14 -> V_8 = * V_14 -> V_9 ;
V_19:
V_16 = F_7 ( V_20 , V_21 ,
* V_14 -> V_9 , ( void * * ) & V_15 ) ;
if ( V_16 != V_22 )
goto V_23;
* V_14 -> V_10 = 0 ;
V_17 = 0 ;
V_16 = F_7 ( V_24 , V_14 -> V_9 , V_15 ,
& V_17 , V_14 -> V_10 , & V_18 ) ;
if ( V_16 == V_25 ||
! F_5 ( * V_14 -> V_8 , * V_14 -> V_9 ,
* V_14 -> V_10 ) ) {
F_7 ( V_26 , V_15 ) ;
* V_14 -> V_9 += * V_14 -> V_10 * V_12 ;
* V_14 -> V_8 = * V_14 -> V_9 ;
goto V_19;
}
if ( V_16 != V_22 )
F_7 ( V_26 , V_15 ) ;
if ( V_14 -> V_27 && V_16 == V_22 )
* V_14 -> V_27 = V_17 ;
if ( V_14 -> V_28 && V_16 == V_22 )
* V_14 -> V_28 = V_18 ;
V_23:
* V_14 -> V_14 = V_15 ;
return V_16 ;
}
unsigned long F_8 ( T_2 * V_3 )
{
T_4 V_16 ;
unsigned long V_9 , V_8 ;
unsigned long V_29 = V_30 ;
struct V_31 V_14 ;
T_5 * V_32 ;
struct V_13 V_33 ;
V_33 . V_14 = ( T_5 * * ) & V_14 . V_14 ;
V_33 . V_9 = & V_9 ;
V_33 . V_10 = & V_14 . V_10 ;
V_33 . V_28 = NULL ;
V_33 . V_27 = NULL ;
V_33 . V_8 = & V_8 ;
V_16 = F_6 ( V_3 , & V_33 ) ;
if ( V_16 != V_22 )
return V_29 ;
V_14 . V_34 = V_14 . V_14 + V_9 ;
F_9 (&map, md) {
if ( V_32 -> V_35 & V_36 ) {
if ( V_29 > V_32 -> V_37 )
V_29 = V_32 -> V_37 ;
}
}
F_7 ( V_26 , V_14 . V_14 ) ;
return V_29 ;
}
T_4 F_10 ( T_2 * V_3 ,
unsigned long V_38 , unsigned long V_39 ,
unsigned long * V_40 , unsigned long V_41 )
{
unsigned long V_9 , V_10 , V_8 ;
T_5 * V_14 ;
T_4 V_16 ;
unsigned long V_42 ;
T_7 V_43 = 0 ;
int V_44 ;
struct V_13 V_33 ;
V_33 . V_14 = & V_14 ;
V_33 . V_9 = & V_9 ;
V_33 . V_10 = & V_10 ;
V_33 . V_28 = NULL ;
V_33 . V_27 = NULL ;
V_33 . V_8 = & V_8 ;
V_16 = F_6 ( V_3 , & V_33 ) ;
if ( V_16 != V_22 )
goto V_23;
if ( V_39 < V_45 )
V_39 = V_45 ;
V_38 = F_11 ( V_38 , V_45 ) ;
V_42 = V_38 / V_46 ;
V_19:
for ( V_44 = 0 ; V_44 < V_9 / V_10 ; V_44 ++ ) {
T_5 * V_47 ;
unsigned long V_15 = ( unsigned long ) V_14 ;
T_7 V_48 , V_49 ;
V_47 = F_12 ( V_15 , V_10 , V_44 ) ;
if ( V_47 -> type != V_50 )
continue;
if ( V_47 -> V_51 < V_42 )
continue;
V_48 = V_47 -> V_37 ;
V_49 = V_48 + V_47 -> V_51 * V_46 ;
if ( V_49 > V_41 )
V_49 = V_41 ;
if ( ( V_48 + V_38 ) > V_49 )
continue;
if ( F_13 ( V_49 - V_38 , V_39 ) < V_48 )
continue;
V_48 = F_13 ( V_49 - V_38 , V_39 ) ;
if ( V_48 == 0x0 )
continue;
if ( V_48 > V_43 )
V_43 = V_48 ;
}
if ( ! V_43 )
V_16 = V_52 ;
else {
V_16 = F_7 ( V_53 ,
V_54 , V_21 ,
V_42 , & V_43 ) ;
if ( V_16 != V_22 ) {
V_41 = V_43 ;
V_43 = 0 ;
goto V_19;
}
* V_40 = V_43 ;
}
F_7 ( V_26 , V_14 ) ;
V_23:
return V_16 ;
}
T_4 F_14 ( T_2 * V_3 ,
unsigned long V_38 , unsigned long V_39 ,
unsigned long * V_40 )
{
unsigned long V_9 , V_10 , V_8 ;
T_5 * V_14 ;
T_4 V_16 ;
unsigned long V_42 ;
int V_44 ;
struct V_13 V_33 ;
V_33 . V_14 = & V_14 ;
V_33 . V_9 = & V_9 ;
V_33 . V_10 = & V_10 ;
V_33 . V_28 = NULL ;
V_33 . V_27 = NULL ;
V_33 . V_8 = & V_8 ;
V_16 = F_6 ( V_3 , & V_33 ) ;
if ( V_16 != V_22 )
goto V_23;
if ( V_39 < V_45 )
V_39 = V_45 ;
V_38 = F_11 ( V_38 , V_45 ) ;
V_42 = V_38 / V_46 ;
for ( V_44 = 0 ; V_44 < V_9 / V_10 ; V_44 ++ ) {
T_5 * V_47 ;
unsigned long V_15 = ( unsigned long ) V_14 ;
T_7 V_48 , V_49 ;
V_47 = F_12 ( V_15 , V_10 , V_44 ) ;
if ( V_47 -> type != V_50 )
continue;
if ( V_47 -> V_51 < V_42 )
continue;
V_48 = V_47 -> V_37 ;
V_49 = V_48 + V_47 -> V_51 * V_46 ;
if ( V_48 == 0x0 )
V_48 += 8 ;
V_48 = F_11 ( V_48 , V_39 ) ;
if ( ( V_48 + V_38 ) > V_49 )
continue;
V_16 = F_7 ( V_53 ,
V_54 , V_21 ,
V_42 , & V_48 ) ;
if ( V_16 == V_22 ) {
* V_40 = V_48 ;
break;
}
}
if ( V_44 == V_9 / V_10 )
V_16 = V_52 ;
F_7 ( V_26 , V_14 ) ;
V_23:
return V_16 ;
}
void F_15 ( T_2 * V_3 , unsigned long V_38 ,
unsigned long V_40 )
{
unsigned long V_42 ;
if ( ! V_38 )
return;
V_42 = F_11 ( V_38 , V_45 ) / V_46 ;
F_7 ( V_55 , V_40 , V_42 ) ;
}
static T_4 F_16 ( T_2 * V_3 , void * V_56 ,
T_3 * V_57 , void * * V_58 ,
T_7 * V_59 )
{
T_8 * V_60 , * V_61 = V_56 ;
T_9 * V_62 ;
T_4 V_16 ;
T_10 V_63 = V_64 ;
unsigned long V_65 ;
V_16 = F_17 ( V_66 , V_67 , V_61 , & V_60 , V_57 ,
V_68 , ( T_7 ) 0 ) ;
if ( V_16 != V_22 ) {
F_3 ( V_3 , L_1 ) ;
F_4 ( V_3 , V_57 ) ;
F_3 ( V_3 , L_2 ) ;
return V_16 ;
}
* V_58 = V_60 ;
V_65 = 0 ;
V_16 = F_17 ( V_66 , V_69 , V_60 , & V_63 ,
& V_65 , NULL ) ;
if ( V_16 != V_25 ) {
F_3 ( V_3 , L_3 ) ;
return V_16 ;
}
V_70:
V_16 = F_7 ( V_20 , V_21 ,
V_65 , ( void * * ) & V_62 ) ;
if ( V_16 != V_22 ) {
F_3 ( V_3 , L_4 ) ;
return V_16 ;
}
V_16 = F_17 ( V_66 , V_69 , V_60 , & V_63 ,
& V_65 , V_62 ) ;
if ( V_16 == V_25 ) {
F_7 ( V_26 , V_62 ) ;
goto V_70;
}
* V_59 = V_62 -> V_71 ;
F_7 ( V_26 , V_62 ) ;
if ( V_16 != V_22 )
F_3 ( V_3 , L_5 ) ;
return V_16 ;
}
static T_4 F_18 ( void * V_58 , unsigned long * V_38 , void * V_40 )
{
return F_17 ( V_66 , V_72 , V_58 , V_38 , V_40 ) ;
}
static T_4 F_19 ( void * V_58 )
{
return F_17 ( V_66 , V_73 , V_58 ) ;
}
T_4 F_20 ( char const * V_74 )
{
char * V_4 ;
V_4 = strstr ( V_74 , L_6 ) ;
if ( V_4 == V_74 || ( V_4 && V_4 > V_74 && * ( V_4 - 1 ) == ' ' ) )
V_1 = 1 ;
V_4 = strstr ( V_74 , L_7 ) ;
if ( V_4 == V_74 || ( V_4 && V_4 > V_74 && * ( V_4 - 1 ) == ' ' ) )
V_2 = 1 ;
V_4 = strstr ( V_74 , L_8 ) ;
if ( ! V_4 )
return V_22 ;
V_4 += strlen ( L_8 ) ;
while ( * V_4 && * V_4 != ' ' ) {
if ( ! strncmp ( V_4 , L_9 , 7 ) ) {
V_4 += strlen ( L_9 ) ;
V_75 = - 1UL ;
}
while ( * V_4 && * V_4 != ' ' && * V_4 != ',' )
V_4 ++ ;
if ( * V_4 == ',' )
V_4 ++ ;
}
return V_22 ;
}
T_4 F_21 ( T_2 * V_3 ,
T_11 * V_76 ,
char * V_77 , char * V_78 ,
unsigned long V_43 ,
unsigned long * V_79 ,
unsigned long * V_80 )
{
struct V_81 * V_82 ;
unsigned long V_83 ;
T_7 V_84 ;
T_8 * V_61 = NULL ;
T_4 V_16 ;
int V_85 ;
char * V_4 ;
int V_44 , V_86 , V_87 ;
V_83 = 0 ;
V_84 = 0 ;
V_4 = V_77 ;
V_86 = 0 ;
if ( ! V_79 || ! V_80 )
return V_88 ;
* V_79 = 0 ;
* V_80 = 0 ;
if ( ! V_4 || ! * V_4 )
return V_22 ;
for ( V_85 = 0 ; * V_4 ; V_85 ++ ) {
V_4 = strstr ( V_4 , V_78 ) ;
if ( ! V_4 )
break;
V_4 += strlen ( V_78 ) ;
while ( * V_4 == '/' || * V_4 == '\\' )
V_4 ++ ;
while ( * V_4 && * V_4 != ' ' && * V_4 != '\n' )
V_4 ++ ;
}
if ( ! V_85 )
return V_22 ;
V_16 = F_7 ( V_20 , V_21 ,
V_85 * sizeof( * V_82 ) , ( void * * ) & V_82 ) ;
if ( V_16 != V_22 ) {
F_22 ( V_3 , L_10 ) ;
goto V_23;
}
V_4 = V_77 ;
for ( V_44 = 0 ; V_44 < V_85 ; V_44 ++ ) {
struct V_81 * V_89 ;
T_3 V_57 [ 256 ] ;
T_3 * V_90 ;
V_4 = strstr ( V_4 , V_78 ) ;
if ( ! V_4 )
break;
V_4 += strlen ( V_78 ) ;
V_89 = & V_82 [ V_44 ] ;
V_90 = V_57 ;
while ( * V_4 == '/' || * V_4 == '\\' )
V_4 ++ ;
while ( * V_4 && * V_4 != ' ' && * V_4 != '\n' ) {
if ( ( V_91 * ) V_90 >= ( V_91 * ) V_57 + sizeof( V_57 ) )
break;
if ( * V_4 == '/' ) {
* V_90 ++ = '\\' ;
V_4 ++ ;
} else {
* V_90 ++ = * V_4 ++ ;
}
}
* V_90 = '\0' ;
if ( ! V_44 ) {
V_16 = F_23 ( V_3 , V_76 ,
( void * * ) & V_61 ) ;
if ( V_16 != V_22 )
goto V_92;
}
V_16 = F_16 ( V_3 , V_61 , V_57 ,
( void * * ) & V_89 -> V_58 , & V_89 -> V_38 ) ;
if ( V_16 != V_22 )
goto V_93;
V_84 += V_89 -> V_38 ;
}
if ( V_84 ) {
unsigned long V_40 ;
V_16 = F_10 ( V_3 , V_84 , 0x1000 ,
& V_83 , V_43 ) ;
if ( V_16 != V_22 ) {
F_22 ( V_3 , L_11 ) ;
goto V_93;
}
if ( V_83 > V_43 ) {
F_22 ( V_3 , L_12 ) ;
V_16 = V_88 ;
goto V_94;
}
V_40 = V_83 ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
unsigned long V_38 ;
V_38 = V_82 [ V_86 ] . V_38 ;
while ( V_38 ) {
unsigned long V_95 ;
if ( F_24 ( V_96 ) && V_38 > V_75 )
V_95 = V_75 ;
else
V_95 = V_38 ;
V_16 = F_18 ( V_82 [ V_86 ] . V_58 ,
& V_95 ,
( void * ) V_40 ) ;
if ( V_16 != V_22 ) {
F_22 ( V_3 , L_13 ) ;
goto V_94;
}
V_40 += V_95 ;
V_38 -= V_95 ;
}
F_19 ( V_82 [ V_86 ] . V_58 ) ;
}
}
F_7 ( V_26 , V_82 ) ;
* V_79 = V_83 ;
* V_80 = V_84 ;
return V_16 ;
V_94:
F_15 ( V_3 , V_84 , V_83 ) ;
V_93:
for ( V_87 = V_86 ; V_87 < V_44 ; V_87 ++ )
F_19 ( V_82 [ V_87 ] . V_58 ) ;
V_92:
F_7 ( V_26 , V_82 ) ;
V_23:
* V_79 = 0 ;
* V_80 = 0 ;
return V_16 ;
}
T_4 F_25 ( T_2 * V_3 ,
unsigned long * V_97 ,
unsigned long V_98 ,
unsigned long V_99 ,
unsigned long V_100 ,
unsigned long V_101 )
{
unsigned long V_102 ;
unsigned long V_103 = 0 ;
T_4 V_16 ;
unsigned long V_42 ;
T_12 V_104 = V_100 ;
if ( ! V_97 || ! V_98 || ! V_99 )
return V_88 ;
if ( V_99 < V_98 )
return V_88 ;
V_102 = * V_97 ;
V_42 = F_11 ( V_99 , V_45 ) / V_46 ;
V_16 = F_7 ( V_53 ,
V_54 , V_21 ,
V_42 , & V_104 ) ;
V_103 = V_104 ;
if ( V_16 != V_22 ) {
V_16 = F_14 ( V_3 , V_99 , V_101 ,
& V_103 ) ;
}
if ( V_16 != V_22 ) {
F_22 ( V_3 , L_14 ) ;
return V_16 ;
}
memcpy ( ( void * ) V_103 , ( void * ) V_102 , V_98 ) ;
* V_97 = V_103 ;
return V_16 ;
}
static int F_26 ( T_13 V_105 )
{
return 1 + ( V_105 >= 0x80 ) + ( V_105 >= 0x800 ) ;
}
static V_91 * F_27 ( V_91 * V_106 , const T_13 * V_107 , int V_108 )
{
unsigned int V_105 ;
while ( V_108 -- ) {
V_105 = * V_107 ++ ;
if ( V_108 && V_105 >= 0xd800 && V_105 <= 0xdbff &&
* V_107 >= 0xdc00 && * V_107 <= 0xdfff ) {
V_105 = 0x10000 + ( ( V_105 & 0x3ff ) << 10 ) + ( * V_107 & 0x3ff ) ;
V_107 ++ ;
V_108 -- ;
}
if ( V_105 >= 0xd800 && V_105 <= 0xdfff )
V_105 = 0xfffd ;
if ( V_105 < 0x80 ) {
* V_106 ++ = V_105 ;
continue;
}
if ( V_105 < 0x800 ) {
* V_106 ++ = 0xc0 + ( V_105 >> 6 ) ;
goto V_109;
}
if ( V_105 < 0x10000 ) {
* V_106 ++ = 0xe0 + ( V_105 >> 12 ) ;
goto V_110;
}
* V_106 ++ = 0xf0 + ( V_105 >> 18 ) ;
* V_106 ++ = 0x80 + ( ( V_105 >> 12 ) & 0x3f ) ;
V_110:
* V_106 ++ = 0x80 + ( ( V_105 >> 6 ) & 0x3f ) ;
V_109:
* V_106 ++ = 0x80 + ( V_105 & 0x3f ) ;
}
return V_106 ;
}
char * F_28 ( T_2 * V_3 ,
T_11 * V_76 ,
int * V_111 )
{
const T_13 * V_112 ;
V_91 * V_113 = NULL ;
unsigned long V_114 = 0 ;
int V_115 = V_76 -> V_116 / 2 ;
const T_13 * V_117 = V_76 -> V_118 ;
int V_119 = 0 ;
int V_120 = 0 ;
T_4 V_16 ;
T_13 V_121 = 0 ;
if ( V_117 ) {
V_112 = V_117 ;
while ( * V_112 && * V_112 != '\n'
&& V_120 < V_115 ) {
V_119 += F_26 ( * V_112 ++ ) ;
V_120 ++ ;
}
}
if ( ! V_120 ) {
V_117 = & V_121 ;
}
V_119 ++ ;
V_16 = F_10 ( V_3 , V_119 , 0 ,
& V_114 , V_122 ) ;
if ( V_16 != V_22 )
return NULL ;
V_113 = ( V_91 * ) V_114 ;
V_112 = ( const T_13 * ) V_117 ;
V_113 = F_27 ( V_113 , V_112 , V_120 ) ;
* V_113 = '\0' ;
* V_111 = V_119 ;
return ( char * ) V_114 ;
}
T_4 F_29 ( T_2 * V_3 ,
void * V_58 ,
struct V_13 * V_14 ,
void * V_123 ,
T_14 V_124 )
{
T_4 V_16 ;
V_16 = F_6 ( V_3 , V_14 ) ;
if ( V_16 != V_22 )
goto V_23;
V_16 = V_124 ( V_3 , V_14 , V_123 ) ;
if ( V_16 != V_22 )
goto V_125;
V_16 = F_7 ( V_126 , V_58 , * V_14 -> V_27 ) ;
if ( V_16 == V_88 ) {
* V_14 -> V_9 = * V_14 -> V_8 ;
V_16 = F_7 ( V_24 ,
V_14 -> V_9 ,
* V_14 -> V_14 ,
V_14 -> V_27 ,
V_14 -> V_10 ,
V_14 -> V_28 ) ;
if ( V_16 != V_22 )
goto V_23;
V_16 = V_124 ( V_3 , V_14 , V_123 ) ;
if ( V_16 != V_22 )
goto V_23;
V_16 = F_7 ( V_126 , V_58 , * V_14 -> V_27 ) ;
}
if ( V_16 != V_22 )
goto V_23;
return V_22 ;
V_125:
F_7 ( V_26 , * V_14 -> V_14 ) ;
V_23:
return V_16 ;
}
