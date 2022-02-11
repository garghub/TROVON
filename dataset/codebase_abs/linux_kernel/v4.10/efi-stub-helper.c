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
T_3 F_13 ( char * V_54 )
{
char * V_2 ;
V_2 = strstr ( V_54 , L_1 ) ;
if ( ! V_2 )
return V_20 ;
V_2 += strlen ( L_1 ) ;
while ( * V_2 ) {
if ( ! strncmp ( V_2 , L_2 , 7 ) ) {
V_2 += strlen ( L_2 ) ;
V_55 = - 1UL ;
}
while ( * V_2 && * V_2 != ',' )
V_2 ++ ;
if ( * V_2 == ',' )
V_2 ++ ;
}
return V_20 ;
}
T_3 F_14 ( T_1 * V_1 ,
T_7 * V_56 ,
char * V_57 , char * V_58 ,
unsigned long V_41 ,
unsigned long * V_59 ,
unsigned long * V_60 )
{
struct V_61 * V_62 ;
unsigned long V_63 ;
T_6 V_64 ;
T_8 * V_65 = NULL ;
T_3 V_14 ;
int V_66 ;
char * V_2 ;
int V_42 , V_67 , V_68 ;
V_63 = 0 ;
V_64 = 0 ;
V_2 = V_57 ;
V_67 = 0 ;
if ( ! V_59 || ! V_60 )
return V_69 ;
* V_59 = 0 ;
* V_60 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_20 ;
for ( V_66 = 0 ; * V_2 ; V_66 ++ ) {
V_2 = strstr ( V_2 , V_58 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_58 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_66 )
return V_20 ;
V_14 = F_5 ( V_18 , V_19 ,
V_66 * sizeof( * V_62 ) , ( void * * ) & V_62 ) ;
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_3 ) ;
goto V_21;
}
V_2 = V_57 ;
for ( V_42 = 0 ; V_42 < V_66 ; V_42 ++ ) {
struct V_61 * V_70 ;
T_2 V_71 [ 256 ] ;
T_2 * V_72 ;
V_2 = strstr ( V_2 , V_58 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_58 ) ;
V_70 = & V_62 [ V_42 ] ;
V_72 = V_71 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_73 * ) V_72 >= ( V_73 * ) V_71 + sizeof( V_71 ) )
break;
if ( * V_2 == '/' ) {
* V_72 ++ = '\\' ;
V_2 ++ ;
} else {
* V_72 ++ = * V_2 ++ ;
}
}
* V_72 = '\0' ;
if ( ! V_42 ) {
V_14 = F_16 ( V_1 , V_56 ,
( void * * ) & V_65 ) ;
if ( V_14 != V_20 )
goto V_74;
}
V_14 = F_17 ( V_1 , V_65 , V_71 ,
( void * * ) & V_70 -> V_75 , & V_70 -> V_36 ) ;
if ( V_14 != V_20 )
goto V_76;
V_64 += V_70 -> V_36 ;
}
if ( V_64 ) {
unsigned long V_38 ;
V_14 = F_8 ( V_1 , V_64 , 0x1000 ,
& V_63 , V_41 ) ;
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_4 ) ;
goto V_76;
}
if ( V_63 > V_41 ) {
F_15 ( V_1 , L_5 ) ;
V_14 = V_69 ;
goto V_77;
}
V_38 = V_63 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
unsigned long V_36 ;
V_36 = V_62 [ V_67 ] . V_36 ;
while ( V_36 ) {
unsigned long V_78 ;
if ( V_36 > V_55 )
V_78 = V_55 ;
else
V_78 = V_36 ;
V_14 = F_18 ( V_62 [ V_67 ] . V_75 ,
& V_78 ,
( void * ) V_38 ) ;
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_6 ) ;
goto V_77;
}
V_38 += V_78 ;
V_36 -= V_78 ;
}
F_19 ( V_62 [ V_67 ] . V_75 ) ;
}
}
F_5 ( V_24 , V_62 ) ;
* V_59 = V_63 ;
* V_60 = V_64 ;
return V_14 ;
V_77:
F_12 ( V_1 , V_64 , V_63 ) ;
V_76:
for ( V_68 = V_67 ; V_68 < V_42 ; V_68 ++ )
F_19 ( V_62 [ V_68 ] . V_75 ) ;
V_74:
F_5 ( V_24 , V_62 ) ;
V_21:
* V_59 = 0 ;
* V_60 = 0 ;
return V_14 ;
}
T_3 F_20 ( T_1 * V_1 ,
unsigned long * V_79 ,
unsigned long V_80 ,
unsigned long V_81 ,
unsigned long V_82 ,
unsigned long V_83 )
{
unsigned long V_84 ;
unsigned long V_85 = 0 ;
T_3 V_14 ;
unsigned long V_40 ;
T_9 V_86 = V_82 ;
if ( ! V_79 || ! V_80 || ! V_81 )
return V_69 ;
if ( V_81 < V_80 )
return V_69 ;
V_84 = * V_79 ;
V_40 = F_9 ( V_81 , V_43 ) / V_44 ;
V_14 = F_5 ( V_51 ,
V_52 , V_19 ,
V_40 , & V_86 ) ;
V_85 = V_86 ;
if ( V_14 != V_20 ) {
V_14 = F_11 ( V_1 , V_81 , V_83 ,
& V_85 ) ;
}
if ( V_14 != V_20 ) {
F_15 ( V_1 , L_7 ) ;
return V_14 ;
}
memcpy ( ( void * ) V_85 , ( void * ) V_84 , V_80 ) ;
* V_79 = V_85 ;
return V_14 ;
}
static int F_21 ( T_10 V_87 )
{
return 1 + ( V_87 >= 0x80 ) + ( V_87 >= 0x800 ) ;
}
static V_73 * F_22 ( V_73 * V_88 , const T_10 * V_89 , int V_90 )
{
unsigned int V_87 ;
while ( V_90 -- ) {
V_87 = * V_89 ++ ;
if ( V_90 && V_87 >= 0xd800 && V_87 <= 0xdbff &&
* V_89 >= 0xdc00 && * V_89 <= 0xdfff ) {
V_87 = 0x10000 + ( ( V_87 & 0x3ff ) << 10 ) + ( * V_89 & 0x3ff ) ;
V_89 ++ ;
V_90 -- ;
}
if ( V_87 >= 0xd800 && V_87 <= 0xdfff )
V_87 = 0xfffd ;
if ( V_87 < 0x80 ) {
* V_88 ++ = V_87 ;
continue;
}
if ( V_87 < 0x800 ) {
* V_88 ++ = 0xc0 + ( V_87 >> 6 ) ;
goto V_91;
}
if ( V_87 < 0x10000 ) {
* V_88 ++ = 0xe0 + ( V_87 >> 12 ) ;
goto V_92;
}
* V_88 ++ = 0xf0 + ( V_87 >> 18 ) ;
* V_88 ++ = 0x80 + ( ( V_87 >> 12 ) & 0x3f ) ;
V_92:
* V_88 ++ = 0x80 + ( ( V_87 >> 6 ) & 0x3f ) ;
V_91:
* V_88 ++ = 0x80 + ( V_87 & 0x3f ) ;
}
return V_88 ;
}
char * F_23 ( T_1 * V_1 ,
T_7 * V_56 ,
int * V_93 )
{
const T_10 * V_94 ;
V_73 * V_95 = NULL ;
unsigned long V_96 = 0 ;
int V_97 = V_56 -> V_98 / 2 ;
const T_10 * V_99 = V_56 -> V_100 ;
int V_101 = 0 ;
int V_102 = 0 ;
T_3 V_14 ;
T_10 V_103 = 0 ;
if ( V_99 ) {
V_94 = V_99 ;
while ( * V_94 && * V_94 != '\n'
&& V_102 < V_97 ) {
V_101 += F_21 ( * V_94 ++ ) ;
V_102 ++ ;
}
}
if ( ! V_102 ) {
V_99 = & V_103 ;
}
V_101 ++ ;
V_14 = F_8 ( V_1 , V_101 , 0 ,
& V_96 , V_104 ) ;
if ( V_14 != V_20 )
return NULL ;
V_95 = ( V_73 * ) V_96 ;
V_94 = ( const T_10 * ) V_99 ;
V_95 = F_22 ( V_95 , V_94 , V_102 ) ;
* V_95 = '\0' ;
* V_93 = V_101 ;
return ( char * ) V_96 ;
}
T_3 F_24 ( T_1 * V_1 ,
void * V_75 ,
struct V_11 * V_12 ,
void * V_105 ,
T_11 V_106 )
{
T_3 V_14 ;
V_14 = F_4 ( V_1 , V_12 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = V_106 ( V_1 , V_12 , V_105 ) ;
if ( V_14 != V_20 )
goto V_107;
V_14 = F_5 ( V_108 , V_75 , * V_12 -> V_25 ) ;
if ( V_14 == V_69 ) {
* V_12 -> V_7 = * V_12 -> V_6 ;
V_14 = F_5 ( V_22 ,
V_12 -> V_7 ,
* V_12 -> V_12 ,
V_12 -> V_25 ,
V_12 -> V_8 ,
V_12 -> V_26 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = V_106 ( V_1 , V_12 , V_105 ) ;
if ( V_14 != V_20 )
goto V_21;
V_14 = F_5 ( V_108 , V_75 , * V_12 -> V_25 ) ;
}
if ( V_14 != V_20 )
goto V_21;
return V_20 ;
V_107:
F_5 ( V_24 , * V_12 -> V_12 ) ;
V_21:
return V_14 ;
}
