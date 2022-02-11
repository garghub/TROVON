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
V_40 = F_9 ( V_36 , V_43 ) / V_44 ;
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
V_47 = V_46 + V_45 -> V_49 * ( 1UL << V_50 ) ;
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
V_14 = V_51 ;
else {
V_14 = F_5 ( V_52 ,
V_53 , V_19 ,
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
V_40 = F_9 ( V_36 , V_43 ) / V_44 ;
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
V_47 = V_46 + V_45 -> V_49 * ( 1UL << V_50 ) ;
if ( V_46 == 0x0 )
V_46 += 8 ;
V_46 = F_9 ( V_46 , V_37 ) ;
if ( ( V_46 + V_36 ) > V_47 )
continue;
V_14 = F_5 ( V_52 ,
V_53 , V_19 ,
V_40 , & V_46 ) ;
if ( V_14 == V_20 ) {
* V_38 = V_46 ;
break;
}
}
if ( V_42 == V_7 / V_8 )
V_14 = V_51 ;
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
F_5 ( V_54 , V_38 , V_40 ) ;
}
T_3 F_13 ( char * V_55 )
{
char * V_2 ;
V_2 = strstr ( V_55 , L_1 ) ;
if ( ! V_2 )
return V_20 ;
V_2 += strlen ( L_1 ) ;
while ( * V_2 ) {
if ( ! strncmp ( V_2 , L_2 , 7 ) ) {
V_2 += strlen ( L_2 ) ;
V_56 = - 1UL ;
}
while ( * V_2 && * V_2 != ',' )
V_2 ++ ;
if ( * V_2 == ',' )
V_2 ++ ;
}
return V_20 ;
}
T_3 F_14 ( T_1 * V_1 ,
T_7 * V_57 ,
char * V_58 , char * V_59 ,
unsigned long V_41 ,
unsigned long * V_60 ,
unsigned long * V_61 )
{
struct V_62 * V_63 ;
unsigned long V_64 ;
T_6 V_65 ;
T_8 * V_66 = NULL ;
T_3 V_14 ;
int V_67 ;
char * V_2 ;
int V_42 , V_68 , V_69 ;
V_64 = 0 ;
V_65 = 0 ;
V_2 = V_58 ;
V_68 = 0 ;
if ( ! V_60 || ! V_61 )
return V_70 ;
* V_60 = 0 ;
* V_61 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_20 ;
for ( V_67 = 0 ; * V_2 ; V_67 ++ ) {
V_2 = strstr ( V_2 , V_59 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_59 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_67 )
return V_20 ;
V_14 = F_5 ( V_18 , V_19 ,
V_67 * sizeof( * V_63 ) , ( void * * ) & V_63 ) ;
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_3 ) ;
goto V_21;
}
V_2 = V_58 ;
for ( V_42 = 0 ; V_42 < V_67 ; V_42 ++ ) {
struct V_62 * V_71 ;
T_2 V_72 [ 256 ] ;
T_2 * V_73 ;
V_2 = strstr ( V_2 , V_59 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_59 ) ;
V_71 = & V_63 [ V_42 ] ;
V_73 = V_72 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_74 * ) V_73 >= ( V_74 * ) V_72 + sizeof( V_72 ) )
break;
if ( * V_2 == '/' ) {
* V_73 ++ = '\\' ;
V_2 ++ ;
} else {
* V_73 ++ = * V_2 ++ ;
}
}
* V_73 = '\0' ;
if ( ! V_42 ) {
V_14 = F_16 ( V_1 , V_57 ,
( void * * ) & V_66 ) ;
if ( V_14 != V_20 )
goto V_75;
}
V_14 = F_17 ( V_1 , V_66 , V_72 ,
( void * * ) & V_71 -> V_76 , & V_71 -> V_36 ) ;
if ( V_14 != V_20 )
goto V_77;
V_65 += V_71 -> V_36 ;
}
if ( V_65 ) {
unsigned long V_38 ;
V_14 = F_8 ( V_1 , V_65 , 0x1000 ,
& V_64 , V_41 ) ;
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_4 ) ;
goto V_77;
}
if ( V_64 > V_41 ) {
F_15 ( V_1 , L_5 ) ;
V_14 = V_70 ;
goto V_78;
}
V_38 = V_64 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
unsigned long V_36 ;
V_36 = V_63 [ V_68 ] . V_36 ;
while ( V_36 ) {
unsigned long V_79 ;
if ( V_36 > V_56 )
V_79 = V_56 ;
else
V_79 = V_36 ;
V_14 = F_18 ( V_63 [ V_68 ] . V_76 ,
& V_79 ,
( void * ) V_38 ) ;
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_6 ) ;
goto V_78;
}
V_38 += V_79 ;
V_36 -= V_79 ;
}
F_19 ( V_63 [ V_68 ] . V_76 ) ;
}
}
F_5 ( V_24 , V_63 ) ;
* V_60 = V_64 ;
* V_61 = V_65 ;
return V_14 ;
V_78:
F_12 ( V_1 , V_65 , V_64 ) ;
V_77:
for ( V_69 = V_68 ; V_69 < V_42 ; V_69 ++ )
F_19 ( V_63 [ V_69 ] . V_76 ) ;
V_75:
F_5 ( V_24 , V_63 ) ;
V_21:
* V_60 = 0 ;
* V_61 = 0 ;
return V_14 ;
}
T_3 F_20 ( T_1 * V_1 ,
unsigned long * V_80 ,
unsigned long V_81 ,
unsigned long V_82 ,
unsigned long V_83 ,
unsigned long V_84 )
{
unsigned long V_85 ;
unsigned long V_86 = 0 ;
T_3 V_14 ;
unsigned long V_40 ;
T_9 V_87 = V_83 ;
if ( ! V_80 || ! V_81 || ! V_82 )
return V_70 ;
if ( V_82 < V_81 )
return V_70 ;
V_85 = * V_80 ;
V_40 = F_9 ( V_82 , V_43 ) / V_44 ;
V_14 = F_5 ( V_52 ,
V_53 , V_19 ,
V_40 , & V_87 ) ;
V_86 = V_87 ;
if ( V_14 != V_20 ) {
V_14 = F_11 ( V_1 , V_82 , V_84 ,
& V_86 ) ;
}
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_7 ) ;
return V_14 ;
}
memcpy ( ( void * ) V_86 , ( void * ) V_85 , V_81 ) ;
* V_80 = V_86 ;
return V_14 ;
}
static int F_21 ( T_10 V_88 )
{
return 1 + ( V_88 >= 0x80 ) + ( V_88 >= 0x800 ) ;
}
static V_74 * F_22 ( V_74 * V_89 , const T_10 * V_90 , int V_91 )
{
unsigned int V_88 ;
while ( V_91 -- ) {
V_88 = * V_90 ++ ;
if ( V_91 && V_88 >= 0xd800 && V_88 <= 0xdbff &&
* V_90 >= 0xdc00 && * V_90 <= 0xdfff ) {
V_88 = 0x10000 + ( ( V_88 & 0x3ff ) << 10 ) + ( * V_90 & 0x3ff ) ;
V_90 ++ ;
V_91 -- ;
}
if ( V_88 >= 0xd800 && V_88 <= 0xdfff )
V_88 = 0xfffd ;
if ( V_88 < 0x80 ) {
* V_89 ++ = V_88 ;
continue;
}
if ( V_88 < 0x800 ) {
* V_89 ++ = 0xc0 + ( V_88 >> 6 ) ;
goto V_92;
}
if ( V_88 < 0x10000 ) {
* V_89 ++ = 0xe0 + ( V_88 >> 12 ) ;
goto V_93;
}
* V_89 ++ = 0xf0 + ( V_88 >> 18 ) ;
* V_89 ++ = 0x80 + ( ( V_88 >> 12 ) & 0x3f ) ;
V_93:
* V_89 ++ = 0x80 + ( ( V_88 >> 6 ) & 0x3f ) ;
V_92:
* V_89 ++ = 0x80 + ( V_88 & 0x3f ) ;
}
return V_89 ;
}
char * F_23 ( T_1 * V_1 ,
T_7 * V_57 ,
int * V_94 )
{
const T_10 * V_95 ;
V_74 * V_96 = NULL ;
unsigned long V_97 = 0 ;
int V_98 = V_57 -> V_99 / 2 ;
const T_10 * V_100 = V_57 -> V_101 ;
int V_102 = 0 ;
int V_103 = 0 ;
T_3 V_14 ;
T_10 V_104 = 0 ;
if ( V_100 ) {
V_95 = V_100 ;
while ( * V_95 && * V_95 != '\n'
&& V_103 < V_98 ) {
V_102 += F_21 ( * V_95 ++ ) ;
V_103 ++ ;
}
}
if ( ! V_103 ) {
V_100 = & V_104 ;
}
V_102 ++ ;
V_14 = F_8 ( V_1 , V_102 , 0 ,
& V_97 , V_105 ) ;
if ( V_14 != V_20 )
return NULL ;
V_96 = ( V_74 * ) V_97 ;
V_95 = ( const T_10 * ) V_100 ;
V_96 = F_22 ( V_96 , V_95 , V_103 ) ;
* V_96 = '\0' ;
* V_94 = V_102 ;
return ( char * ) V_97 ;
}
T_3 F_24 ( T_1 * V_1 ,
void * V_76 ,
struct V_11 * V_12 ,
void * V_106 ,
T_11 V_107 )
{
T_3 V_14 ;
V_14 = F_4 ( V_1 , V_12 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = V_107 ( V_1 , V_12 , V_106 ) ;
if ( V_14 != V_20 )
goto V_108;
V_14 = F_5 ( V_109 , V_76 , * V_12 -> V_25 ) ;
if ( V_14 == V_70 ) {
* V_12 -> V_7 = * V_12 -> V_6 ;
V_14 = F_5 ( V_22 ,
V_12 -> V_7 ,
* V_12 -> V_12 ,
V_12 -> V_25 ,
V_12 -> V_8 ,
V_12 -> V_26 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = V_107 ( V_1 , V_12 , V_106 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = F_5 ( V_109 , V_76 , * V_12 -> V_25 ) ;
}
if ( V_14 != V_20 )
goto V_21;
return V_20 ;
V_108:
F_5 ( V_24 , * V_12 -> V_12 ) ;
V_21:
return V_14 ;
}
