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
T_3 F_12 ( char * V_49 )
{
char * V_2 ;
V_2 = strstr ( V_49 , L_1 ) ;
if ( ! V_2 )
return V_18 ;
V_2 += strlen ( L_1 ) ;
while ( * V_2 ) {
if ( ! strncmp ( V_2 , L_2 , 7 ) ) {
V_2 += strlen ( L_2 ) ;
V_50 = - 1UL ;
}
while ( * V_2 && * V_2 != ',' )
V_2 ++ ;
if ( * V_2 == ',' )
V_2 ++ ;
}
return V_18 ;
}
T_3 F_13 ( T_1 * V_1 ,
T_8 * V_51 ,
char * V_52 , char * V_53 ,
unsigned long V_36 ,
unsigned long * V_54 ,
unsigned long * V_55 )
{
struct V_56 * V_57 ;
unsigned long V_58 ;
T_7 V_59 ;
T_9 * V_60 = NULL ;
T_3 V_12 ;
int V_61 ;
char * V_2 ;
int V_37 , V_62 , V_63 ;
V_58 = 0 ;
V_59 = 0 ;
V_2 = V_52 ;
V_62 = 0 ;
if ( ! V_54 || ! V_55 )
return V_64 ;
* V_54 = 0 ;
* V_55 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_18 ;
for ( V_61 = 0 ; * V_2 ; V_61 ++ ) {
V_2 = strstr ( V_2 , V_53 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_53 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_61 )
return V_18 ;
V_12 = F_4 ( V_16 , V_17 ,
V_61 * sizeof( * V_57 ) , ( void * * ) & V_57 ) ;
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_3 ) ;
goto V_19;
}
V_2 = V_52 ;
for ( V_37 = 0 ; V_37 < V_61 ; V_37 ++ ) {
struct V_56 * V_65 ;
T_2 V_66 [ 256 ] ;
T_2 * V_67 ;
V_2 = strstr ( V_2 , V_53 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_53 ) ;
V_65 = & V_57 [ V_37 ] ;
V_67 = V_66 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_68 * ) V_67 >= ( V_68 * ) V_66 + sizeof( V_66 ) )
break;
if ( * V_2 == '/' ) {
* V_67 ++ = '\\' ;
V_2 ++ ;
} else {
* V_67 ++ = * V_2 ++ ;
}
}
* V_67 = '\0' ;
if ( ! V_37 ) {
V_12 = F_15 ( V_1 , V_51 ,
( void * * ) & V_60 ) ;
if ( V_12 != V_18 )
goto V_69;
}
V_12 = F_16 ( V_1 , V_60 , V_66 ,
( void * * ) & V_65 -> V_70 , & V_65 -> V_31 ) ;
if ( V_12 != V_18 )
goto V_71;
V_59 += V_65 -> V_31 ;
}
if ( V_59 ) {
unsigned long V_33 ;
V_12 = F_7 ( V_1 , V_59 , 0x1000 ,
& V_58 , V_36 ) ;
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_4 ) ;
goto V_71;
}
if ( V_58 > V_36 ) {
F_14 ( V_1 , L_5 ) ;
V_12 = V_64 ;
goto V_72;
}
V_33 = V_58 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
unsigned long V_31 ;
V_31 = V_57 [ V_62 ] . V_31 ;
while ( V_31 ) {
unsigned long V_73 ;
if ( V_31 > V_50 )
V_73 = V_50 ;
else
V_73 = V_31 ;
V_12 = F_17 ( V_57 [ V_62 ] . V_70 ,
& V_73 ,
( void * ) V_33 ) ;
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_6 ) ;
goto V_72;
}
V_33 += V_73 ;
V_31 -= V_73 ;
}
F_18 ( V_57 [ V_62 ] . V_70 ) ;
}
}
F_4 ( V_22 , V_57 ) ;
* V_54 = V_58 ;
* V_55 = V_59 ;
return V_12 ;
V_72:
F_11 ( V_1 , V_59 , V_58 ) ;
V_71:
for ( V_63 = V_62 ; V_63 < V_37 ; V_63 ++ )
F_18 ( V_57 [ V_63 ] . V_70 ) ;
V_69:
F_4 ( V_22 , V_57 ) ;
V_19:
* V_54 = 0 ;
* V_55 = 0 ;
return V_12 ;
}
T_3 F_19 ( T_1 * V_1 ,
unsigned long * V_74 ,
unsigned long V_75 ,
unsigned long V_76 ,
unsigned long V_77 ,
unsigned long V_78 )
{
unsigned long V_79 ;
unsigned long V_80 = 0 ;
T_3 V_12 ;
unsigned long V_35 ;
T_10 V_81 = V_77 ;
if ( ! V_74 || ! V_75 || ! V_76 )
return V_64 ;
if ( V_76 < V_75 )
return V_64 ;
V_79 = * V_74 ;
V_35 = F_8 ( V_76 , V_38 ) / V_38 ;
V_12 = F_4 ( V_46 ,
V_47 , V_17 ,
V_35 , & V_81 ) ;
V_80 = V_81 ;
if ( V_12 != V_18 ) {
V_12 = F_10 ( V_1 , V_76 , V_78 ,
& V_80 ) ;
}
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_7 ) ;
return V_12 ;
}
memcpy ( ( void * ) V_80 , ( void * ) V_79 , V_75 ) ;
* V_74 = V_80 ;
return V_12 ;
}
static int F_20 ( T_11 V_82 )
{
return 1 + ( V_82 >= 0x80 ) + ( V_82 >= 0x800 ) ;
}
static V_68 * F_21 ( V_68 * V_83 , const T_11 * V_84 , int V_85 )
{
unsigned int V_82 ;
while ( V_85 -- ) {
V_82 = * V_84 ++ ;
if ( V_85 && V_82 >= 0xd800 && V_82 <= 0xdbff &&
* V_84 >= 0xdc00 && * V_84 <= 0xdfff ) {
V_82 = 0x10000 + ( ( V_82 & 0x3ff ) << 10 ) + ( * V_84 & 0x3ff ) ;
V_84 ++ ;
V_85 -- ;
}
if ( V_82 >= 0xd800 && V_82 <= 0xdfff )
V_82 = 0xfffd ;
if ( V_82 < 0x80 ) {
* V_83 ++ = V_82 ;
continue;
}
if ( V_82 < 0x800 ) {
* V_83 ++ = 0xc0 + ( V_82 >> 6 ) ;
goto V_86;
}
if ( V_82 < 0x10000 ) {
* V_83 ++ = 0xe0 + ( V_82 >> 12 ) ;
goto V_87;
}
* V_83 ++ = 0xf0 + ( V_82 >> 18 ) ;
* V_83 ++ = 0x80 + ( ( V_82 >> 12 ) & 0x3f ) ;
V_87:
* V_83 ++ = 0x80 + ( ( V_82 >> 6 ) & 0x3f ) ;
V_86:
* V_83 ++ = 0x80 + ( V_82 & 0x3f ) ;
}
return V_83 ;
}
char * F_22 ( T_1 * V_1 ,
T_8 * V_51 ,
int * V_88 )
{
const T_11 * V_89 ;
V_68 * V_90 = NULL ;
unsigned long V_91 = 0 ;
int V_92 = V_51 -> V_93 / 2 ;
const T_11 * V_94 = V_51 -> V_95 ;
int V_96 = 0 ;
int V_97 = 0 ;
T_3 V_12 ;
T_11 V_98 = 0 ;
if ( V_94 ) {
V_89 = V_94 ;
while ( * V_89 && * V_89 != '\n'
&& V_97 < V_92 ) {
V_96 += F_20 ( * V_89 ++ ) ;
V_97 ++ ;
}
}
if ( ! V_97 ) {
V_94 = & V_98 ;
}
V_96 ++ ;
V_12 = F_10 ( V_1 , V_96 , 0 , & V_91 ) ;
if ( V_12 != V_18 )
return NULL ;
V_90 = ( V_68 * ) V_91 ;
V_89 = ( const T_11 * ) V_94 ;
V_90 = F_21 ( V_90 , V_89 , V_97 ) ;
* V_90 = '\0' ;
* V_88 = V_96 ;
return ( char * ) V_91 ;
}
