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
unsigned long F_5 ( T_1 * V_1 )
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
F_6 (&map, md) {
if ( V_26 -> V_28 & V_29 ) {
if ( V_23 > V_26 -> V_30 )
V_23 = V_26 -> V_30 ;
}
}
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
T_6 V_36 = 0 ;
int V_37 ;
V_12 = F_3 ( V_1 , & V_6 , & V_7 , & V_8 ,
NULL , NULL ) ;
if ( V_12 != V_18 )
goto V_19;
if ( V_32 < V_38 )
V_32 = V_38 ;
V_35 = F_8 ( V_31 , V_38 ) / V_39 ;
V_15:
for ( V_37 = 0 ; V_37 < V_7 / V_8 ; V_37 ++ ) {
T_4 * V_40 ;
unsigned long V_11 = ( unsigned long ) V_6 ;
T_6 V_41 , V_42 ;
V_40 = ( T_4 * ) ( V_11 + ( V_37 * V_8 ) ) ;
if ( V_40 -> type != V_43 )
continue;
if ( V_40 -> V_44 < V_35 )
continue;
V_41 = V_40 -> V_30 ;
V_42 = V_41 + V_40 -> V_44 * ( 1UL << V_45 ) ;
if ( V_42 > V_34 )
V_42 = V_34 ;
if ( ( V_41 + V_31 ) > V_42 )
continue;
if ( F_9 ( V_42 - V_31 , V_32 ) < V_41 )
continue;
V_41 = F_9 ( V_42 - V_31 , V_32 ) ;
if ( V_41 == 0x0 )
continue;
if ( V_41 > V_36 )
V_36 = V_41 ;
}
if ( ! V_36 )
V_12 = V_46 ;
else {
V_12 = F_4 ( V_47 ,
V_48 , V_17 ,
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
V_35 = F_8 ( V_31 , V_38 ) / V_39 ;
for ( V_37 = 0 ; V_37 < V_7 / V_8 ; V_37 ++ ) {
T_4 * V_40 ;
unsigned long V_11 = ( unsigned long ) V_6 ;
T_6 V_41 , V_42 ;
V_40 = ( T_4 * ) ( V_11 + ( V_37 * V_8 ) ) ;
if ( V_40 -> type != V_43 )
continue;
if ( V_40 -> V_44 < V_35 )
continue;
V_41 = V_40 -> V_30 ;
V_42 = V_41 + V_40 -> V_44 * ( 1UL << V_45 ) ;
if ( V_41 == 0x0 )
V_41 += 8 ;
V_41 = F_8 ( V_41 , V_32 ) ;
if ( ( V_41 + V_31 ) > V_42 )
continue;
V_12 = F_4 ( V_47 ,
V_48 , V_17 ,
V_35 , & V_41 ) ;
if ( V_12 == V_18 ) {
* V_33 = V_41 ;
break;
}
}
if ( V_37 == V_7 / V_8 )
V_12 = V_46 ;
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
V_35 = F_8 ( V_31 , V_38 ) / V_39 ;
F_4 ( V_49 , V_33 , V_35 ) ;
}
T_3 F_12 ( char * V_50 )
{
char * V_2 ;
V_2 = strstr ( V_50 , L_1 ) ;
if ( ! V_2 )
return V_18 ;
V_2 += strlen ( L_1 ) ;
while ( * V_2 ) {
if ( ! strncmp ( V_2 , L_2 , 7 ) ) {
V_2 += strlen ( L_2 ) ;
V_51 = - 1UL ;
}
while ( * V_2 && * V_2 != ',' )
V_2 ++ ;
if ( * V_2 == ',' )
V_2 ++ ;
}
return V_18 ;
}
T_3 F_13 ( T_1 * V_1 ,
T_7 * V_52 ,
char * V_53 , char * V_54 ,
unsigned long V_36 ,
unsigned long * V_55 ,
unsigned long * V_56 )
{
struct V_57 * V_58 ;
unsigned long V_59 ;
T_6 V_60 ;
T_8 * V_61 = NULL ;
T_3 V_12 ;
int V_62 ;
char * V_2 ;
int V_37 , V_63 , V_64 ;
V_59 = 0 ;
V_60 = 0 ;
V_2 = V_53 ;
V_63 = 0 ;
if ( ! V_55 || ! V_56 )
return V_65 ;
* V_55 = 0 ;
* V_56 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_18 ;
for ( V_62 = 0 ; * V_2 ; V_62 ++ ) {
V_2 = strstr ( V_2 , V_54 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_54 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_62 )
return V_18 ;
V_12 = F_4 ( V_16 , V_17 ,
V_62 * sizeof( * V_58 ) , ( void * * ) & V_58 ) ;
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_3 ) ;
goto V_19;
}
V_2 = V_53 ;
for ( V_37 = 0 ; V_37 < V_62 ; V_37 ++ ) {
struct V_57 * V_66 ;
T_2 V_67 [ 256 ] ;
T_2 * V_68 ;
V_2 = strstr ( V_2 , V_54 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_54 ) ;
V_66 = & V_58 [ V_37 ] ;
V_68 = V_67 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_69 * ) V_68 >= ( V_69 * ) V_67 + sizeof( V_67 ) )
break;
if ( * V_2 == '/' ) {
* V_68 ++ = '\\' ;
V_2 ++ ;
} else {
* V_68 ++ = * V_2 ++ ;
}
}
* V_68 = '\0' ;
if ( ! V_37 ) {
V_12 = F_15 ( V_1 , V_52 ,
( void * * ) & V_61 ) ;
if ( V_12 != V_18 )
goto V_70;
}
V_12 = F_16 ( V_1 , V_61 , V_67 ,
( void * * ) & V_66 -> V_71 , & V_66 -> V_31 ) ;
if ( V_12 != V_18 )
goto V_72;
V_60 += V_66 -> V_31 ;
}
if ( V_60 ) {
unsigned long V_33 ;
V_12 = F_7 ( V_1 , V_60 , 0x1000 ,
& V_59 , V_36 ) ;
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_4 ) ;
goto V_72;
}
if ( V_59 > V_36 ) {
F_14 ( V_1 , L_5 ) ;
V_12 = V_65 ;
goto V_73;
}
V_33 = V_59 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
unsigned long V_31 ;
V_31 = V_58 [ V_63 ] . V_31 ;
while ( V_31 ) {
unsigned long V_74 ;
if ( V_31 > V_51 )
V_74 = V_51 ;
else
V_74 = V_31 ;
V_12 = F_17 ( V_58 [ V_63 ] . V_71 ,
& V_74 ,
( void * ) V_33 ) ;
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_6 ) ;
goto V_73;
}
V_33 += V_74 ;
V_31 -= V_74 ;
}
F_18 ( V_58 [ V_63 ] . V_71 ) ;
}
}
F_4 ( V_22 , V_58 ) ;
* V_55 = V_59 ;
* V_56 = V_60 ;
return V_12 ;
V_73:
F_11 ( V_1 , V_60 , V_59 ) ;
V_72:
for ( V_64 = V_63 ; V_64 < V_37 ; V_64 ++ )
F_18 ( V_58 [ V_64 ] . V_71 ) ;
V_70:
F_4 ( V_22 , V_58 ) ;
V_19:
* V_55 = 0 ;
* V_56 = 0 ;
return V_12 ;
}
T_3 F_19 ( T_1 * V_1 ,
unsigned long * V_75 ,
unsigned long V_76 ,
unsigned long V_77 ,
unsigned long V_78 ,
unsigned long V_79 )
{
unsigned long V_80 ;
unsigned long V_81 = 0 ;
T_3 V_12 ;
unsigned long V_35 ;
T_9 V_82 = V_78 ;
if ( ! V_75 || ! V_76 || ! V_77 )
return V_65 ;
if ( V_77 < V_76 )
return V_65 ;
V_80 = * V_75 ;
V_35 = F_8 ( V_77 , V_38 ) / V_39 ;
V_12 = F_4 ( V_47 ,
V_48 , V_17 ,
V_35 , & V_82 ) ;
V_81 = V_82 ;
if ( V_12 != V_18 ) {
V_12 = F_10 ( V_1 , V_77 , V_79 ,
& V_81 ) ;
}
if ( V_12 != V_18 ) {
F_14 ( V_1 , L_7 ) ;
return V_12 ;
}
memcpy ( ( void * ) V_81 , ( void * ) V_80 , V_76 ) ;
* V_75 = V_81 ;
return V_12 ;
}
static int F_20 ( T_10 V_83 )
{
return 1 + ( V_83 >= 0x80 ) + ( V_83 >= 0x800 ) ;
}
static V_69 * F_21 ( V_69 * V_84 , const T_10 * V_85 , int V_86 )
{
unsigned int V_83 ;
while ( V_86 -- ) {
V_83 = * V_85 ++ ;
if ( V_86 && V_83 >= 0xd800 && V_83 <= 0xdbff &&
* V_85 >= 0xdc00 && * V_85 <= 0xdfff ) {
V_83 = 0x10000 + ( ( V_83 & 0x3ff ) << 10 ) + ( * V_85 & 0x3ff ) ;
V_85 ++ ;
V_86 -- ;
}
if ( V_83 >= 0xd800 && V_83 <= 0xdfff )
V_83 = 0xfffd ;
if ( V_83 < 0x80 ) {
* V_84 ++ = V_83 ;
continue;
}
if ( V_83 < 0x800 ) {
* V_84 ++ = 0xc0 + ( V_83 >> 6 ) ;
goto V_87;
}
if ( V_83 < 0x10000 ) {
* V_84 ++ = 0xe0 + ( V_83 >> 12 ) ;
goto V_88;
}
* V_84 ++ = 0xf0 + ( V_83 >> 18 ) ;
* V_84 ++ = 0x80 + ( ( V_83 >> 12 ) & 0x3f ) ;
V_88:
* V_84 ++ = 0x80 + ( ( V_83 >> 6 ) & 0x3f ) ;
V_87:
* V_84 ++ = 0x80 + ( V_83 & 0x3f ) ;
}
return V_84 ;
}
char * F_22 ( T_1 * V_1 ,
T_7 * V_52 ,
int * V_89 )
{
const T_10 * V_90 ;
V_69 * V_91 = NULL ;
unsigned long V_92 = 0 ;
int V_93 = V_52 -> V_94 / 2 ;
const T_10 * V_95 = V_52 -> V_96 ;
int V_97 = 0 ;
int V_98 = 0 ;
T_3 V_12 ;
T_10 V_99 = 0 ;
if ( V_95 ) {
V_90 = V_95 ;
while ( * V_90 && * V_90 != '\n'
&& V_98 < V_93 ) {
V_97 += F_20 ( * V_90 ++ ) ;
V_98 ++ ;
}
}
if ( ! V_98 ) {
V_95 = & V_99 ;
}
V_97 ++ ;
V_12 = F_7 ( V_1 , V_97 , 0 ,
& V_92 , V_100 ) ;
if ( V_12 != V_18 )
return NULL ;
V_91 = ( V_69 * ) V_92 ;
V_90 = ( const T_10 * ) V_95 ;
V_91 = F_21 ( V_91 , V_90 , V_98 ) ;
* V_91 = '\0' ;
* V_89 = V_97 ;
return ( char * ) V_92 ;
}
