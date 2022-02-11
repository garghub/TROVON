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
T_3 F_3 ( T_1 * V_1 ,
T_4 * * V_6 ,
unsigned long * V_7 ,
unsigned long * V_8 ,
T_5 * V_9 ,
unsigned long * V_10 )
{
T_4 * V_11 = NULL ;
T_3 V_12 ;
unsigned long V_13 ;
T_5 V_14 ;
* V_7 = sizeof( * V_11 ) * 32 ;
V_15:
* V_7 += sizeof( * V_11 ) ;
V_12 = F_4 ( V_16 , V_17 ,
* V_7 , ( void * * ) & V_11 ) ;
if ( V_12 != V_18 )
goto V_19;
* V_8 = 0 ;
V_13 = 0 ;
V_12 = F_4 ( V_20 , V_7 , V_11 ,
& V_13 , V_8 , & V_14 ) ;
if ( V_12 == V_21 ) {
F_4 ( V_22 , V_11 ) ;
goto V_15;
}
if ( V_12 != V_18 )
F_4 ( V_22 , V_11 ) ;
if ( V_10 && V_12 == V_18 )
* V_10 = V_13 ;
if ( V_9 && V_12 == V_18 )
* V_9 = V_14 ;
V_19:
* V_6 = V_11 ;
return V_12 ;
}
unsigned long T_6 F_5 ( T_1 * V_1 )
{
T_3 V_12 ;
unsigned long V_7 ;
unsigned long V_23 = V_24 ;
struct V_25 V_6 ;
T_4 * V_26 ;
V_12 = F_3 ( V_1 , ( T_4 * * ) & V_6 . V_6 ,
& V_7 , & V_6 . V_8 , NULL , NULL ) ;
if ( V_12 != V_18 )
return V_23 ;
V_6 . V_27 = V_6 . V_6 + V_7 ;
F_6 (&map, md)
if ( V_26 -> V_28 & V_29 )
if ( V_23 > V_26 -> V_30 )
V_23 = V_26 -> V_30 ;
F_4 ( V_22 , V_6 . V_6 ) ;
return V_23 ;
}
T_3 F_7 ( T_1 * V_1 ,
unsigned long V_31 , unsigned long V_32 ,
unsigned long * V_33 , unsigned long V_34 )
{
unsigned long V_7 , V_8 ;
T_4 * V_6 ;
T_3 V_12 ;
unsigned long V_35 ;
T_7 V_36 = 0 ;
int V_37 ;
V_12 = F_3 ( V_1 , & V_6 , & V_7 , & V_8 ,
NULL , NULL ) ;
if ( V_12 != V_18 )
goto V_19;
if ( V_32 < V_38 )
V_32 = V_38 ;
V_35 = F_8 ( V_31 , V_38 ) / V_38 ;
V_15:
for ( V_37 = 0 ; V_37 < V_7 / V_8 ; V_37 ++ ) {
T_4 * V_39 ;
unsigned long V_11 = ( unsigned long ) V_6 ;
T_7 V_40 , V_41 ;
V_39 = ( T_4 * ) ( V_11 + ( V_37 * V_8 ) ) ;
if ( V_39 -> type != V_42 )
continue;
if ( V_39 -> V_43 < V_35 )
continue;
V_40 = V_39 -> V_30 ;
V_41 = V_40 + V_39 -> V_43 * ( 1UL << V_44 ) ;
if ( ( V_40 + V_31 ) > V_41 || ( V_40 + V_31 ) > V_34 )
continue;
if ( V_41 - V_31 > V_34 )
V_41 = V_34 ;
if ( F_9 ( V_41 - V_31 , V_32 ) < V_40 )
continue;
V_40 = F_9 ( V_41 - V_31 , V_32 ) ;
if ( V_40 == 0x0 )
continue;
if ( V_40 > V_36 )
V_36 = V_40 ;
}
if ( ! V_36 )
V_12 = V_45 ;
else {
V_12 = F_4 ( V_46 ,
V_47 , V_17 ,
V_35 , & V_36 ) ;
if ( V_12 != V_18 ) {
V_34 = V_36 ;
V_36 = 0 ;
goto V_15;
}
* V_33 = V_36 ;
}
F_4 ( V_22 , V_6 ) ;
V_19:
return V_12 ;
}
T_3 F_10 ( T_1 * V_1 ,
unsigned long V_31 , unsigned long V_32 ,
unsigned long * V_33 )
{
unsigned long V_7 , V_8 ;
T_4 * V_6 ;
T_3 V_12 ;
unsigned long V_35 ;
int V_37 ;
V_12 = F_3 ( V_1 , & V_6 , & V_7 , & V_8 ,
NULL , NULL ) ;
if ( V_12 != V_18 )
goto V_19;
if ( V_32 < V_38 )
V_32 = V_38 ;
V_35 = F_8 ( V_31 , V_38 ) / V_38 ;
for ( V_37 = 0 ; V_37 < V_7 / V_8 ; V_37 ++ ) {
T_4 * V_39 ;
unsigned long V_11 = ( unsigned long ) V_6 ;
T_7 V_40 , V_41 ;
V_39 = ( T_4 * ) ( V_11 + ( V_37 * V_8 ) ) ;
if ( V_39 -> type != V_42 )
continue;
if ( V_39 -> V_43 < V_35 )
continue;
V_40 = V_39 -> V_30 ;
V_41 = V_40 + V_39 -> V_43 * ( 1UL << V_44 ) ;
if ( V_40 == 0x0 )
V_40 += 8 ;
V_40 = F_8 ( V_40 , V_32 ) ;
if ( ( V_40 + V_31 ) > V_41 )
continue;
V_12 = F_4 ( V_46 ,
V_47 , V_17 ,
V_35 , & V_40 ) ;
if ( V_12 == V_18 ) {
* V_33 = V_40 ;
break;
}
}
if ( V_37 == V_7 / V_8 )
V_12 = V_45 ;
F_4 ( V_22 , V_6 ) ;
V_19:
return V_12 ;
}
void F_11 ( T_1 * V_1 , unsigned long V_31 ,
unsigned long V_33 )
{
unsigned long V_35 ;
if ( ! V_31 )
return;
V_35 = F_8 ( V_31 , V_38 ) / V_38 ;
F_4 ( V_48 , V_33 , V_35 ) ;
}
T_3 F_12 ( T_1 * V_1 ,
T_8 * V_49 ,
char * V_50 , char * V_51 ,
unsigned long V_36 ,
unsigned long * V_52 ,
unsigned long * V_53 )
{
struct V_54 * V_55 ;
unsigned long V_56 ;
T_7 V_57 ;
T_9 * V_58 = NULL ;
T_3 V_12 ;
int V_59 ;
char * V_2 ;
int V_37 , V_60 , V_61 ;
V_56 = 0 ;
V_57 = 0 ;
V_2 = V_50 ;
V_60 = 0 ;
if ( ! V_52 || ! V_53 )
return V_62 ;
* V_52 = 0 ;
* V_53 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_18 ;
for ( V_59 = 0 ; * V_2 ; V_59 ++ ) {
V_2 = strstr ( V_2 , V_51 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_51 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_59 )
return V_18 ;
V_12 = F_4 ( V_16 , V_17 ,
V_59 * sizeof( * V_55 ) , ( void * * ) & V_55 ) ;
if ( V_12 != V_18 ) {
F_13 ( V_1 , L_1 ) ;
goto V_19;
}
V_2 = V_50 ;
for ( V_37 = 0 ; V_37 < V_59 ; V_37 ++ ) {
struct V_54 * V_63 ;
T_2 V_64 [ 256 ] ;
T_2 * V_65 ;
V_2 = strstr ( V_2 , V_51 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_51 ) ;
V_63 = & V_55 [ V_37 ] ;
V_65 = V_64 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_66 * ) V_65 >= ( V_66 * ) V_64 + sizeof( V_64 ) )
break;
if ( * V_2 == '/' ) {
* V_65 ++ = '\\' ;
V_2 ++ ;
} else {
* V_65 ++ = * V_2 ++ ;
}
}
* V_65 = '\0' ;
if ( ! V_37 ) {
V_12 = F_14 ( V_1 , V_49 ,
( void * * ) & V_58 ) ;
if ( V_12 != V_18 )
goto V_67;
}
V_12 = F_15 ( V_1 , V_58 , V_64 ,
( void * * ) & V_63 -> V_68 , & V_63 -> V_31 ) ;
if ( V_12 != V_18 )
goto V_69;
V_57 += V_63 -> V_31 ;
}
if ( V_57 ) {
unsigned long V_33 ;
V_12 = F_7 ( V_1 , V_57 , 0x1000 ,
& V_56 , V_36 ) ;
if ( V_12 != V_18 ) {
F_13 ( V_1 , L_2 ) ;
goto V_69;
}
if ( V_56 > V_36 ) {
F_13 ( V_1 , L_3 ) ;
V_12 = V_62 ;
goto V_70;
}
V_33 = V_56 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
unsigned long V_31 ;
V_31 = V_55 [ V_60 ] . V_31 ;
while ( V_31 ) {
unsigned long V_71 ;
if ( V_31 > V_72 )
V_71 = V_72 ;
else
V_71 = V_31 ;
V_12 = F_16 ( V_55 [ V_60 ] . V_68 ,
& V_71 ,
( void * ) V_33 ) ;
if ( V_12 != V_18 ) {
F_13 ( V_1 , L_4 ) ;
goto V_70;
}
V_33 += V_71 ;
V_31 -= V_71 ;
}
F_17 ( V_55 [ V_60 ] . V_68 ) ;
}
}
F_4 ( V_22 , V_55 ) ;
* V_52 = V_56 ;
* V_53 = V_57 ;
return V_12 ;
V_70:
F_11 ( V_1 , V_57 , V_56 ) ;
V_69:
for ( V_61 = V_60 ; V_61 < V_37 ; V_61 ++ )
F_17 ( V_55 [ V_61 ] . V_68 ) ;
V_67:
F_4 ( V_22 , V_55 ) ;
V_19:
* V_52 = 0 ;
* V_53 = 0 ;
return V_12 ;
}
T_3 F_18 ( T_1 * V_1 ,
unsigned long * V_73 ,
unsigned long V_74 ,
unsigned long V_75 ,
unsigned long V_76 ,
unsigned long V_77 )
{
unsigned long V_78 ;
unsigned long V_79 = 0 ;
T_3 V_12 ;
unsigned long V_35 ;
T_10 V_80 = V_76 ;
if ( ! V_73 || ! V_74 || ! V_75 )
return V_62 ;
if ( V_75 < V_74 )
return V_62 ;
V_78 = * V_73 ;
V_35 = F_8 ( V_75 , V_38 ) / V_38 ;
V_12 = F_4 ( V_46 ,
V_47 , V_17 ,
V_35 , & V_80 ) ;
V_79 = V_80 ;
if ( V_12 != V_18 ) {
V_12 = F_10 ( V_1 , V_75 , V_77 ,
& V_79 ) ;
}
if ( V_12 != V_18 ) {
F_13 ( V_1 , L_5 ) ;
return V_12 ;
}
memcpy ( ( void * ) V_79 , ( void * ) V_78 , V_74 ) ;
* V_73 = V_79 ;
return V_12 ;
}
static int F_19 ( T_11 V_81 )
{
return 1 + ( V_81 >= 0x80 ) + ( V_81 >= 0x800 ) ;
}
static V_66 * F_20 ( V_66 * V_82 , const T_11 * V_83 , int V_84 )
{
unsigned int V_81 ;
while ( V_84 -- ) {
V_81 = * V_83 ++ ;
if ( V_84 && V_81 >= 0xd800 && V_81 <= 0xdbff &&
* V_83 >= 0xdc00 && * V_83 <= 0xdfff ) {
V_81 = 0x10000 + ( ( V_81 & 0x3ff ) << 10 ) + ( * V_83 & 0x3ff ) ;
V_83 ++ ;
V_84 -- ;
}
if ( V_81 >= 0xd800 && V_81 <= 0xdfff )
V_81 = 0xfffd ;
if ( V_81 < 0x80 ) {
* V_82 ++ = V_81 ;
continue;
}
if ( V_81 < 0x800 ) {
* V_82 ++ = 0xc0 + ( V_81 >> 6 ) ;
goto V_85;
}
if ( V_81 < 0x10000 ) {
* V_82 ++ = 0xe0 + ( V_81 >> 12 ) ;
goto V_86;
}
* V_82 ++ = 0xf0 + ( V_81 >> 18 ) ;
* V_82 ++ = 0x80 + ( ( V_81 >> 12 ) & 0x3f ) ;
V_86:
* V_82 ++ = 0x80 + ( ( V_81 >> 6 ) & 0x3f ) ;
V_85:
* V_82 ++ = 0x80 + ( V_81 & 0x3f ) ;
}
return V_82 ;
}
char * F_21 ( T_1 * V_1 ,
T_8 * V_49 ,
int * V_87 )
{
const T_11 * V_88 ;
V_66 * V_89 = NULL ;
unsigned long V_90 = 0 ;
int V_91 = V_49 -> V_92 / 2 ;
const T_11 * V_93 = V_49 -> V_94 ;
int V_95 = 0 ;
int V_96 = 0 ;
T_3 V_12 ;
T_11 V_97 = 0 ;
if ( V_93 ) {
V_88 = V_93 ;
while ( * V_88 && * V_88 != '\n'
&& V_96 < V_91 ) {
V_95 += F_19 ( * V_88 ++ ) ;
V_96 ++ ;
}
}
if ( ! V_96 ) {
V_93 = & V_97 ;
}
V_95 ++ ;
V_12 = F_10 ( V_1 , V_95 , 0 , & V_90 ) ;
if ( V_12 != V_18 )
return NULL ;
V_89 = ( V_66 * ) V_90 ;
V_88 = ( const T_11 * ) V_93 ;
V_89 = F_20 ( V_89 , V_88 , V_96 ) ;
* V_89 = '\0' ;
* V_87 = V_95 ;
return ( char * ) V_90 ;
}
