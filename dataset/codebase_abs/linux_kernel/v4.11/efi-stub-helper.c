void F_1 ( T_1 * V_1 , char * V_2 )
{
char * V_3 ;
for ( V_3 = V_2 ; * V_3 ; V_3 ++ ) {
T_2 V_4 [ 2 ] = { 0 } ;
V_4 [ 0 ] = * V_3 ;
if ( * V_3 == '\n' ) {
T_2 V_5 [ 2 ] = { '\r' , 0 } ;
F_2 ( V_1 , V_5 ) ;
}
F_2 ( V_1 , V_4 ) ;
}
}
static inline bool F_3 ( unsigned long V_6 ,
unsigned long V_7 ,
unsigned long V_8 )
{
unsigned long V_9 = V_6 - V_7 ;
return V_9 / V_8 >= V_10 ;
}
T_3 F_4 ( T_1 * V_1 ,
struct V_11 * V_12 )
{
T_4 * V_13 = NULL ;
T_3 V_14 ;
unsigned long V_15 ;
T_5 V_16 ;
* V_12 -> V_8 = sizeof( * V_13 ) ;
* V_12 -> V_7 = * V_12 -> V_8 * 32 ;
* V_12 -> V_6 = * V_12 -> V_7 ;
V_17:
V_14 = F_5 ( V_18 , V_19 ,
* V_12 -> V_7 , ( void * * ) & V_13 ) ;
if ( V_14 != V_20 )
goto V_21;
* V_12 -> V_8 = 0 ;
V_15 = 0 ;
V_14 = F_5 ( V_22 , V_12 -> V_7 , V_13 ,
& V_15 , V_12 -> V_8 , & V_16 ) ;
if ( V_14 == V_23 ||
! F_3 ( * V_12 -> V_6 , * V_12 -> V_7 ,
* V_12 -> V_8 ) ) {
F_5 ( V_24 , V_13 ) ;
* V_12 -> V_7 += * V_12 -> V_8 * V_10 ;
* V_12 -> V_6 = * V_12 -> V_7 ;
goto V_17;
}
if ( V_14 != V_20 )
F_5 ( V_24 , V_13 ) ;
if ( V_12 -> V_25 && V_14 == V_20 )
* V_12 -> V_25 = V_15 ;
if ( V_12 -> V_26 && V_14 == V_20 )
* V_12 -> V_26 = V_16 ;
V_21:
* V_12 -> V_12 = V_13 ;
return V_14 ;
}
unsigned long F_6 ( T_1 * V_1 )
{
T_3 V_14 ;
unsigned long V_7 , V_6 ;
unsigned long V_27 = V_28 ;
struct V_29 V_12 ;
T_4 * V_30 ;
struct V_11 V_31 ;
V_31 . V_12 = ( T_4 * * ) & V_12 . V_12 ;
V_31 . V_7 = & V_7 ;
V_31 . V_8 = & V_12 . V_8 ;
V_31 . V_26 = NULL ;
V_31 . V_25 = NULL ;
V_31 . V_6 = & V_6 ;
V_14 = F_4 ( V_1 , & V_31 ) ;
if ( V_14 != V_20 )
return V_27 ;
V_12 . V_32 = V_12 . V_12 + V_7 ;
F_7 (&map, md) {
if ( V_30 -> V_33 & V_34 ) {
if ( V_27 > V_30 -> V_35 )
V_27 = V_30 -> V_35 ;
}
}
F_5 ( V_24 , V_12 . V_12 ) ;
return V_27 ;
}
T_3 F_8 ( T_1 * V_1 ,
unsigned long V_36 , unsigned long V_37 ,
unsigned long * V_38 , unsigned long V_39 )
{
unsigned long V_7 , V_8 , V_6 ;
T_4 * V_12 ;
T_3 V_14 ;
unsigned long V_40 ;
T_6 V_41 = 0 ;
int V_42 ;
struct V_11 V_31 ;
V_31 . V_12 = & V_12 ;
V_31 . V_7 = & V_7 ;
V_31 . V_8 = & V_8 ;
V_31 . V_26 = NULL ;
V_31 . V_25 = NULL ;
V_31 . V_6 = & V_6 ;
V_14 = F_4 ( V_1 , & V_31 ) ;
if ( V_14 != V_20 )
goto V_21;
if ( V_37 < V_43 )
V_37 = V_43 ;
V_36 = F_9 ( V_36 , V_43 ) ;
V_40 = V_36 / V_44 ;
V_17:
for ( V_42 = 0 ; V_42 < V_7 / V_8 ; V_42 ++ ) {
T_4 * V_45 ;
unsigned long V_13 = ( unsigned long ) V_12 ;
T_6 V_46 , V_47 ;
V_45 = ( T_4 * ) ( V_13 + ( V_42 * V_8 ) ) ;
if ( V_45 -> type != V_48 )
continue;
if ( V_45 -> V_49 < V_40 )
continue;
V_46 = V_45 -> V_35 ;
V_47 = V_46 + V_45 -> V_49 * V_44 ;
if ( V_47 > V_39 )
V_47 = V_39 ;
if ( ( V_46 + V_36 ) > V_47 )
continue;
if ( F_10 ( V_47 - V_36 , V_37 ) < V_46 )
continue;
V_46 = F_10 ( V_47 - V_36 , V_37 ) ;
if ( V_46 == 0x0 )
continue;
if ( V_46 > V_41 )
V_41 = V_46 ;
}
if ( ! V_41 )
V_14 = V_50 ;
else {
V_14 = F_5 ( V_51 ,
V_52 , V_19 ,
V_40 , & V_41 ) ;
if ( V_14 != V_20 ) {
V_39 = V_41 ;
V_41 = 0 ;
goto V_17;
}
* V_38 = V_41 ;
}
F_5 ( V_24 , V_12 ) ;
V_21:
return V_14 ;
}
T_3 F_11 ( T_1 * V_1 ,
unsigned long V_36 , unsigned long V_37 ,
unsigned long * V_38 )
{
unsigned long V_7 , V_8 , V_6 ;
T_4 * V_12 ;
T_3 V_14 ;
unsigned long V_40 ;
int V_42 ;
struct V_11 V_31 ;
V_31 . V_12 = & V_12 ;
V_31 . V_7 = & V_7 ;
V_31 . V_8 = & V_8 ;
V_31 . V_26 = NULL ;
V_31 . V_25 = NULL ;
V_31 . V_6 = & V_6 ;
V_14 = F_4 ( V_1 , & V_31 ) ;
if ( V_14 != V_20 )
goto V_21;
if ( V_37 < V_43 )
V_37 = V_43 ;
V_36 = F_9 ( V_36 , V_43 ) ;
V_40 = V_36 / V_44 ;
for ( V_42 = 0 ; V_42 < V_7 / V_8 ; V_42 ++ ) {
T_4 * V_45 ;
unsigned long V_13 = ( unsigned long ) V_12 ;
T_6 V_46 , V_47 ;
V_45 = ( T_4 * ) ( V_13 + ( V_42 * V_8 ) ) ;
if ( V_45 -> type != V_48 )
continue;
if ( V_45 -> V_49 < V_40 )
continue;
V_46 = V_45 -> V_35 ;
V_47 = V_46 + V_45 -> V_49 * V_44 ;
if ( V_46 == 0x0 )
V_46 += 8 ;
V_46 = F_9 ( V_46 , V_37 ) ;
if ( ( V_46 + V_36 ) > V_47 )
continue;
V_14 = F_5 ( V_51 ,
V_52 , V_19 ,
V_40 , & V_46 ) ;
if ( V_14 == V_20 ) {
* V_38 = V_46 ;
break;
}
}
if ( V_42 == V_7 / V_8 )
V_14 = V_50 ;
F_5 ( V_24 , V_12 ) ;
V_21:
return V_14 ;
}
void F_12 ( T_1 * V_1 , unsigned long V_36 ,
unsigned long V_38 )
{
unsigned long V_40 ;
if ( ! V_36 )
return;
V_40 = F_9 ( V_36 , V_43 ) / V_44 ;
F_5 ( V_53 , V_38 , V_40 ) ;
}
static T_3 F_13 ( T_1 * V_1 , void * V_54 ,
T_2 * V_55 , void * * V_56 ,
T_6 * V_57 )
{
T_7 * V_58 , * V_59 = V_54 ;
T_8 * V_60 ;
T_3 V_14 ;
T_9 V_61 = V_62 ;
unsigned long V_63 ;
V_14 = F_14 ( V_64 , V_65 , V_59 , & V_58 , V_55 ,
V_66 , ( T_6 ) 0 ) ;
if ( V_14 != V_20 ) {
F_1 ( V_1 , L_1 ) ;
F_2 ( V_1 , V_55 ) ;
F_1 ( V_1 , L_2 ) ;
return V_14 ;
}
* V_56 = V_58 ;
V_63 = 0 ;
V_14 = F_14 ( V_64 , V_67 , V_58 , & V_61 ,
& V_63 , NULL ) ;
if ( V_14 != V_23 ) {
F_1 ( V_1 , L_3 ) ;
return V_14 ;
}
V_68:
V_14 = F_5 ( V_18 , V_19 ,
V_63 , ( void * * ) & V_60 ) ;
if ( V_14 != V_20 ) {
F_1 ( V_1 , L_4 ) ;
return V_14 ;
}
V_14 = F_14 ( V_64 , V_67 , V_58 , & V_61 ,
& V_63 , V_60 ) ;
if ( V_14 == V_23 ) {
F_5 ( V_24 , V_60 ) ;
goto V_68;
}
* V_57 = V_60 -> V_69 ;
F_5 ( V_24 , V_60 ) ;
if ( V_14 != V_20 )
F_1 ( V_1 , L_5 ) ;
return V_14 ;
}
static T_3 F_15 ( void * V_56 , unsigned long * V_36 , void * V_38 )
{
return F_14 ( V_64 , V_70 , V_56 , V_36 , V_38 ) ;
}
static T_3 F_16 ( void * V_56 )
{
return F_14 ( V_64 , V_71 , V_56 ) ;
}
T_3 F_17 ( char * V_72 )
{
char * V_2 ;
if ( ! F_18 ( V_73 ) )
return V_20 ;
V_2 = strstr ( V_72 , L_6 ) ;
if ( ! V_2 )
return V_20 ;
V_2 += strlen ( L_6 ) ;
while ( * V_2 ) {
if ( ! strncmp ( V_2 , L_7 , 7 ) ) {
V_2 += strlen ( L_7 ) ;
V_74 = - 1UL ;
}
while ( * V_2 && * V_2 != ',' )
V_2 ++ ;
if ( * V_2 == ',' )
V_2 ++ ;
}
return V_20 ;
}
T_3 F_19 ( T_1 * V_1 ,
T_10 * V_75 ,
char * V_76 , char * V_77 ,
unsigned long V_41 ,
unsigned long * V_78 ,
unsigned long * V_79 )
{
struct V_80 * V_81 ;
unsigned long V_82 ;
T_6 V_83 ;
T_7 * V_59 = NULL ;
T_3 V_14 ;
int V_84 ;
char * V_2 ;
int V_42 , V_85 , V_86 ;
V_82 = 0 ;
V_83 = 0 ;
V_2 = V_76 ;
V_85 = 0 ;
if ( ! V_78 || ! V_79 )
return V_87 ;
* V_78 = 0 ;
* V_79 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_20 ;
for ( V_84 = 0 ; * V_2 ; V_84 ++ ) {
V_2 = strstr ( V_2 , V_77 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_77 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_84 )
return V_20 ;
V_14 = F_5 ( V_18 , V_19 ,
V_84 * sizeof( * V_81 ) , ( void * * ) & V_81 ) ;
if ( V_14 != V_20 ) {
F_20 ( V_1 , L_8 ) ;
goto V_21;
}
V_2 = V_76 ;
for ( V_42 = 0 ; V_42 < V_84 ; V_42 ++ ) {
struct V_80 * V_88 ;
T_2 V_55 [ 256 ] ;
T_2 * V_89 ;
V_2 = strstr ( V_2 , V_77 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_77 ) ;
V_88 = & V_81 [ V_42 ] ;
V_89 = V_55 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_90 * ) V_89 >= ( V_90 * ) V_55 + sizeof( V_55 ) )
break;
if ( * V_2 == '/' ) {
* V_89 ++ = '\\' ;
V_2 ++ ;
} else {
* V_89 ++ = * V_2 ++ ;
}
}
* V_89 = '\0' ;
if ( ! V_42 ) {
V_14 = F_21 ( V_1 , V_75 ,
( void * * ) & V_59 ) ;
if ( V_14 != V_20 )
goto V_91;
}
V_14 = F_13 ( V_1 , V_59 , V_55 ,
( void * * ) & V_88 -> V_56 , & V_88 -> V_36 ) ;
if ( V_14 != V_20 )
goto V_92;
V_83 += V_88 -> V_36 ;
}
if ( V_83 ) {
unsigned long V_38 ;
V_14 = F_8 ( V_1 , V_83 , 0x1000 ,
& V_82 , V_41 ) ;
if ( V_14 != V_20 ) {
F_20 ( V_1 , L_9 ) ;
goto V_92;
}
if ( V_82 > V_41 ) {
F_20 ( V_1 , L_10 ) ;
V_14 = V_87 ;
goto V_93;
}
V_38 = V_82 ;
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ ) {
unsigned long V_36 ;
V_36 = V_81 [ V_85 ] . V_36 ;
while ( V_36 ) {
unsigned long V_94 ;
if ( F_18 ( V_73 ) && V_36 > V_74 )
V_94 = V_74 ;
else
V_94 = V_36 ;
V_14 = F_15 ( V_81 [ V_85 ] . V_56 ,
& V_94 ,
( void * ) V_38 ) ;
if ( V_14 != V_20 ) {
F_20 ( V_1 , L_11 ) ;
goto V_93;
}
V_38 += V_94 ;
V_36 -= V_94 ;
}
F_16 ( V_81 [ V_85 ] . V_56 ) ;
}
}
F_5 ( V_24 , V_81 ) ;
* V_78 = V_82 ;
* V_79 = V_83 ;
return V_14 ;
V_93:
F_12 ( V_1 , V_83 , V_82 ) ;
V_92:
for ( V_86 = V_85 ; V_86 < V_42 ; V_86 ++ )
F_16 ( V_81 [ V_86 ] . V_56 ) ;
V_91:
F_5 ( V_24 , V_81 ) ;
V_21:
* V_78 = 0 ;
* V_79 = 0 ;
return V_14 ;
}
T_3 F_22 ( T_1 * V_1 ,
unsigned long * V_95 ,
unsigned long V_96 ,
unsigned long V_97 ,
unsigned long V_98 ,
unsigned long V_99 )
{
unsigned long V_100 ;
unsigned long V_101 = 0 ;
T_3 V_14 ;
unsigned long V_40 ;
T_11 V_102 = V_98 ;
if ( ! V_95 || ! V_96 || ! V_97 )
return V_87 ;
if ( V_97 < V_96 )
return V_87 ;
V_100 = * V_95 ;
V_40 = F_9 ( V_97 , V_43 ) / V_44 ;
V_14 = F_5 ( V_51 ,
V_52 , V_19 ,
V_40 , & V_102 ) ;
V_101 = V_102 ;
if ( V_14 != V_20 ) {
V_14 = F_11 ( V_1 , V_97 , V_99 ,
& V_101 ) ;
}
if ( V_14 != V_20 ) {
F_20 ( V_1 , L_12 ) ;
return V_14 ;
}
memcpy ( ( void * ) V_101 , ( void * ) V_100 , V_96 ) ;
* V_95 = V_101 ;
return V_14 ;
}
static int F_23 ( T_12 V_103 )
{
return 1 + ( V_103 >= 0x80 ) + ( V_103 >= 0x800 ) ;
}
static V_90 * F_24 ( V_90 * V_104 , const T_12 * V_105 , int V_106 )
{
unsigned int V_103 ;
while ( V_106 -- ) {
V_103 = * V_105 ++ ;
if ( V_106 && V_103 >= 0xd800 && V_103 <= 0xdbff &&
* V_105 >= 0xdc00 && * V_105 <= 0xdfff ) {
V_103 = 0x10000 + ( ( V_103 & 0x3ff ) << 10 ) + ( * V_105 & 0x3ff ) ;
V_105 ++ ;
V_106 -- ;
}
if ( V_103 >= 0xd800 && V_103 <= 0xdfff )
V_103 = 0xfffd ;
if ( V_103 < 0x80 ) {
* V_104 ++ = V_103 ;
continue;
}
if ( V_103 < 0x800 ) {
* V_104 ++ = 0xc0 + ( V_103 >> 6 ) ;
goto V_107;
}
if ( V_103 < 0x10000 ) {
* V_104 ++ = 0xe0 + ( V_103 >> 12 ) ;
goto V_108;
}
* V_104 ++ = 0xf0 + ( V_103 >> 18 ) ;
* V_104 ++ = 0x80 + ( ( V_103 >> 12 ) & 0x3f ) ;
V_108:
* V_104 ++ = 0x80 + ( ( V_103 >> 6 ) & 0x3f ) ;
V_107:
* V_104 ++ = 0x80 + ( V_103 & 0x3f ) ;
}
return V_104 ;
}
char * F_25 ( T_1 * V_1 ,
T_10 * V_75 ,
int * V_109 )
{
const T_12 * V_110 ;
V_90 * V_111 = NULL ;
unsigned long V_112 = 0 ;
int V_113 = V_75 -> V_114 / 2 ;
const T_12 * V_115 = V_75 -> V_116 ;
int V_117 = 0 ;
int V_118 = 0 ;
T_3 V_14 ;
T_12 V_119 = 0 ;
if ( V_115 ) {
V_110 = V_115 ;
while ( * V_110 && * V_110 != '\n'
&& V_118 < V_113 ) {
V_117 += F_23 ( * V_110 ++ ) ;
V_118 ++ ;
}
}
if ( ! V_118 ) {
V_115 = & V_119 ;
}
V_117 ++ ;
V_14 = F_8 ( V_1 , V_117 , 0 ,
& V_112 , V_120 ) ;
if ( V_14 != V_20 )
return NULL ;
V_111 = ( V_90 * ) V_112 ;
V_110 = ( const T_12 * ) V_115 ;
V_111 = F_24 ( V_111 , V_110 , V_118 ) ;
* V_111 = '\0' ;
* V_109 = V_117 ;
return ( char * ) V_112 ;
}
T_3 F_26 ( T_1 * V_1 ,
void * V_56 ,
struct V_11 * V_12 ,
void * V_121 ,
T_13 V_122 )
{
T_3 V_14 ;
V_14 = F_4 ( V_1 , V_12 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = V_122 ( V_1 , V_12 , V_121 ) ;
if ( V_14 != V_20 )
goto V_123;
V_14 = F_5 ( V_124 , V_56 , * V_12 -> V_25 ) ;
if ( V_14 == V_87 ) {
* V_12 -> V_7 = * V_12 -> V_6 ;
V_14 = F_5 ( V_22 ,
V_12 -> V_7 ,
* V_12 -> V_12 ,
V_12 -> V_25 ,
V_12 -> V_8 ,
V_12 -> V_26 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = V_122 ( V_1 , V_12 , V_121 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = F_5 ( V_124 , V_56 , * V_12 -> V_25 ) ;
}
if ( V_14 != V_20 )
goto V_21;
return V_20 ;
V_123:
F_5 ( V_24 , * V_12 -> V_12 ) ;
V_21:
return V_14 ;
}
