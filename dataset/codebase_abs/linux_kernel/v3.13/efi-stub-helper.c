static void F_1 ( T_1 * V_1 ,
T_2 * V_2 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) V_1 -> V_5 ;
F_2 ( V_4 -> V_6 , V_4 , V_2 ) ;
}
static void F_3 ( T_1 * V_1 , char * V_2 )
{
char * V_7 ;
for ( V_7 = V_2 ; * V_7 ; V_7 ++ ) {
T_2 V_8 [ 2 ] = { 0 } ;
V_8 [ 0 ] = * V_7 ;
if ( * V_7 == '\n' ) {
T_2 V_9 [ 2 ] = { '\r' , 0 } ;
F_1 ( V_1 , V_9 ) ;
}
F_1 ( V_1 , V_8 ) ;
}
}
static T_3 F_4 ( T_1 * V_1 ,
T_4 * * V_10 ,
unsigned long * V_11 ,
unsigned long * V_12 ,
T_5 * V_13 ,
unsigned long * V_14 )
{
T_4 * V_15 = NULL ;
T_3 V_16 ;
unsigned long V_17 ;
T_5 V_18 ;
* V_11 = sizeof( * V_15 ) * 32 ;
V_19:
* V_11 += sizeof( * V_15 ) ;
V_16 = F_5 ( V_1 -> V_20 -> V_21 ,
V_22 , * V_11 , ( void * * ) & V_15 ) ;
if ( V_16 != V_23 )
goto V_24;
V_16 = F_6 ( V_1 -> V_20 -> V_25 ,
V_11 , V_15 , & V_17 , V_12 , & V_18 ) ;
if ( V_16 == V_26 ) {
F_7 ( V_1 -> V_20 -> V_27 , V_15 ) ;
goto V_19;
}
if ( V_16 != V_23 )
F_7 ( V_1 -> V_20 -> V_27 , V_15 ) ;
if ( V_14 && V_16 == V_23 )
* V_14 = V_17 ;
if ( V_13 && V_16 == V_23 )
* V_13 = V_18 ;
V_24:
* V_10 = V_15 ;
return V_16 ;
}
static T_3 F_8 ( T_1 * V_1 ,
unsigned long V_28 , unsigned long V_29 ,
unsigned long * V_30 , unsigned long V_31 )
{
unsigned long V_11 , V_12 ;
T_4 * V_10 ;
T_3 V_16 ;
unsigned long V_32 ;
T_6 V_33 = 0 ;
int V_34 ;
V_16 = F_4 ( V_1 , & V_10 , & V_11 , & V_12 ,
NULL , NULL ) ;
if ( V_16 != V_23 )
goto V_24;
if ( V_29 < V_35 )
V_29 = V_35 ;
V_32 = F_9 ( V_28 , V_35 ) / V_35 ;
V_19:
for ( V_34 = 0 ; V_34 < V_11 / V_12 ; V_34 ++ ) {
T_4 * V_36 ;
unsigned long V_15 = ( unsigned long ) V_10 ;
T_6 V_37 , V_38 ;
V_36 = ( T_4 * ) ( V_15 + ( V_34 * V_12 ) ) ;
if ( V_36 -> type != V_39 )
continue;
if ( V_36 -> V_40 < V_32 )
continue;
V_37 = V_36 -> V_41 ;
V_38 = V_37 + V_36 -> V_40 * ( 1UL << V_42 ) ;
if ( ( V_37 + V_28 ) > V_38 || ( V_37 + V_28 ) > V_31 )
continue;
if ( V_38 - V_28 > V_31 )
V_38 = V_31 ;
if ( F_10 ( V_38 - V_28 , V_29 ) < V_37 )
continue;
V_37 = F_10 ( V_38 - V_28 , V_29 ) ;
if ( V_37 == 0x0 )
continue;
if ( V_37 > V_33 )
V_33 = V_37 ;
}
if ( ! V_33 )
V_16 = V_43 ;
else {
V_16 = F_11 ( V_1 -> V_20 -> V_44 ,
V_45 , V_22 ,
V_32 , & V_33 ) ;
if ( V_16 != V_23 ) {
V_31 = V_33 ;
V_33 = 0 ;
goto V_19;
}
* V_30 = V_33 ;
}
F_7 ( V_1 -> V_20 -> V_27 , V_10 ) ;
V_24:
return V_16 ;
}
static T_3 F_12 ( T_1 * V_1 ,
unsigned long V_28 , unsigned long V_29 ,
unsigned long * V_30 )
{
unsigned long V_11 , V_12 ;
T_4 * V_10 ;
T_3 V_16 ;
unsigned long V_32 ;
int V_34 ;
V_16 = F_4 ( V_1 , & V_10 , & V_11 , & V_12 ,
NULL , NULL ) ;
if ( V_16 != V_23 )
goto V_24;
if ( V_29 < V_35 )
V_29 = V_35 ;
V_32 = F_9 ( V_28 , V_35 ) / V_35 ;
for ( V_34 = 0 ; V_34 < V_11 / V_12 ; V_34 ++ ) {
T_4 * V_36 ;
unsigned long V_15 = ( unsigned long ) V_10 ;
T_6 V_37 , V_38 ;
V_36 = ( T_4 * ) ( V_15 + ( V_34 * V_12 ) ) ;
if ( V_36 -> type != V_39 )
continue;
if ( V_36 -> V_40 < V_32 )
continue;
V_37 = V_36 -> V_41 ;
V_38 = V_37 + V_36 -> V_40 * ( 1UL << V_42 ) ;
if ( V_37 == 0x0 )
V_37 += 8 ;
V_37 = F_9 ( V_37 , V_29 ) ;
if ( ( V_37 + V_28 ) > V_38 )
continue;
V_16 = F_11 ( V_1 -> V_20 -> V_44 ,
V_45 , V_22 ,
V_32 , & V_37 ) ;
if ( V_16 == V_23 ) {
* V_30 = V_37 ;
break;
}
}
if ( V_34 == V_11 / V_12 )
V_16 = V_43 ;
F_7 ( V_1 -> V_20 -> V_27 , V_10 ) ;
V_24:
return V_16 ;
}
static void F_13 ( T_1 * V_1 , unsigned long V_28 ,
unsigned long V_30 )
{
unsigned long V_32 ;
if ( ! V_28 )
return;
V_32 = F_9 ( V_28 , V_35 ) / V_35 ;
F_2 ( V_1 -> V_20 -> V_46 , V_30 , V_32 ) ;
}
static T_3 F_14 ( T_1 * V_1 ,
T_7 * V_47 ,
char * V_48 , char * V_49 ,
unsigned long V_33 ,
unsigned long * V_50 ,
unsigned long * V_51 )
{
struct V_52 * V_53 ;
unsigned long V_54 ;
T_8 V_55 = V_56 ;
T_6 V_57 ;
T_9 * V_58 ;
T_10 * V_59 ;
T_3 V_16 ;
int V_60 ;
char * V_2 ;
int V_34 , V_61 , V_62 ;
V_54 = 0 ;
V_57 = 0 ;
V_2 = V_48 ;
V_61 = 0 ;
if ( ! V_50 || ! V_51 )
return V_63 ;
* V_50 = 0 ;
* V_51 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_23 ;
for ( V_60 = 0 ; * V_2 ; V_60 ++ ) {
V_2 = strstr ( V_2 , V_49 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_49 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_60 )
return V_23 ;
V_16 = F_5 ( V_1 -> V_20 -> V_21 ,
V_22 ,
V_60 * sizeof( * V_53 ) ,
( void * * ) & V_53 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_1 ) ;
goto V_24;
}
V_2 = V_48 ;
for ( V_34 = 0 ; V_34 < V_60 ; V_34 ++ ) {
struct V_52 * V_64 ;
T_10 * V_65 ;
T_11 * V_66 ;
T_2 V_67 [ 256 ] ;
unsigned long V_68 ;
T_8 V_69 = V_70 ;
T_2 * V_71 ;
T_6 V_72 ;
V_2 = strstr ( V_2 , V_49 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_49 ) ;
V_64 = & V_53 [ V_34 ] ;
V_71 = V_67 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_73 * ) V_71 >= ( V_73 * ) V_67 + sizeof( V_67 ) )
break;
if ( * V_2 == '/' ) {
* V_71 ++ = '\\' ;
V_2 ++ ;
} else {
* V_71 ++ = * V_2 ++ ;
}
}
* V_71 = '\0' ;
if ( ! V_34 ) {
T_12 * V_20 ;
V_20 = V_1 -> V_20 ;
V_16 = F_5 ( V_20 -> V_74 ,
V_47 -> V_75 , & V_55 ,
( void * * ) & V_58 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_2 ) ;
goto V_76;
}
V_16 = F_2 ( V_58 -> V_77 , V_58 , & V_59 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_3 ) ;
goto V_76;
}
}
V_16 = F_6 ( V_59 -> V_78 , V_59 , & V_65 , V_67 ,
V_79 , ( T_6 ) 0 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_4 ) ;
F_1 ( V_1 , V_67 ) ;
F_3 ( V_1 , L_5 ) ;
goto V_80;
}
V_64 -> V_81 = V_65 ;
V_68 = 0 ;
V_16 = F_11 ( V_65 -> V_82 , V_65 , & V_69 ,
& V_68 , NULL ) ;
if ( V_16 != V_26 ) {
F_3 ( V_1 , L_6 ) ;
goto V_80;
}
V_83:
V_16 = F_5 ( V_1 -> V_20 -> V_21 ,
V_22 , V_68 ,
( void * * ) & V_66 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_7 ) ;
goto V_80;
}
V_16 = F_11 ( V_65 -> V_82 , V_65 , & V_69 ,
& V_68 , V_66 ) ;
if ( V_16 == V_26 ) {
F_7 ( V_1 -> V_20 -> V_27 ,
V_66 ) ;
goto V_83;
}
V_72 = V_66 -> V_84 ;
F_7 ( V_1 -> V_20 -> V_27 , V_66 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_8 ) ;
goto V_80;
}
V_64 -> V_28 = V_72 ;
V_57 += V_72 ;
}
if ( V_57 ) {
unsigned long V_30 ;
V_16 = F_8 ( V_1 , V_57 , 0x1000 ,
& V_54 , V_33 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_9 ) ;
goto V_80;
}
if ( V_54 > V_33 ) {
F_3 ( V_1 , L_10 ) ;
V_16 = V_63 ;
goto V_85;
}
V_30 = V_54 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
unsigned long V_28 ;
V_28 = V_53 [ V_61 ] . V_28 ;
while ( V_28 ) {
unsigned long V_86 ;
if ( V_28 > V_87 )
V_86 = V_87 ;
else
V_86 = V_28 ;
V_16 = F_5 ( V_59 -> V_88 ,
V_53 [ V_61 ] . V_81 ,
& V_86 ,
( void * ) V_30 ) ;
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_11 ) ;
goto V_85;
}
V_30 += V_86 ;
V_28 -= V_86 ;
}
F_7 ( V_59 -> V_89 , V_53 [ V_61 ] . V_81 ) ;
}
}
F_7 ( V_1 -> V_20 -> V_27 , V_53 ) ;
* V_50 = V_54 ;
* V_51 = V_57 ;
return V_16 ;
V_85:
F_13 ( V_1 , V_57 , V_54 ) ;
V_80:
for ( V_62 = V_61 ; V_62 < V_34 ; V_62 ++ )
F_7 ( V_59 -> V_89 , V_53 [ V_62 ] . V_81 ) ;
V_76:
F_7 ( V_1 -> V_20 -> V_27 , V_53 ) ;
V_24:
* V_50 = 0 ;
* V_51 = 0 ;
return V_16 ;
}
static T_3 F_15 ( T_1 * V_1 ,
unsigned long * V_90 ,
unsigned long V_91 ,
unsigned long V_92 ,
unsigned long V_93 ,
unsigned long V_94 )
{
unsigned long V_95 ;
unsigned long V_96 = 0 ;
T_3 V_16 ;
unsigned long V_32 ;
T_13 V_97 = V_93 ;
if ( ! V_90 || ! V_91 || ! V_92 )
return V_63 ;
if ( V_92 < V_91 )
return V_63 ;
V_95 = * V_90 ;
V_32 = F_9 ( V_92 , V_35 ) / V_35 ;
V_16 = F_11 ( V_1 -> V_20 -> V_44 ,
V_45 , V_22 ,
V_32 , & V_97 ) ;
V_96 = V_97 ;
if ( V_16 != V_23 ) {
V_16 = F_12 ( V_1 , V_92 , V_94 ,
& V_96 ) ;
}
if ( V_16 != V_23 ) {
F_3 ( V_1 , L_12 ) ;
return V_16 ;
}
memcpy ( ( void * ) V_96 , ( void * ) V_95 , V_91 ) ;
* V_90 = V_96 ;
return V_16 ;
}
static char * F_16 ( T_1 * V_1 ,
T_7 * V_47 ,
int * V_98 )
{
T_14 * V_99 ;
V_73 * V_100 = NULL ;
unsigned long V_101 = 0 ;
int V_102 = V_47 -> V_102 / 2 ;
void * V_103 = V_47 -> V_104 ;
int V_105 = 0 ;
T_3 V_16 ;
int V_34 ;
T_14 V_106 = 0 ;
if ( V_103 ) {
V_99 = V_103 ;
while ( * V_99 && * V_99 != '\n' && V_105 < V_102 ) {
V_99 ++ ;
V_105 ++ ;
}
}
if ( V_105 == 0 ) {
V_105 = 1 ;
V_103 = & V_106 ;
}
V_105 ++ ;
#ifdef F_17
V_16 = F_8 ( V_1 , V_105 , 0 ,
& V_101 , 0xfffff000 ) ;
#else
V_16 = F_12 ( V_1 , V_105 , 0 ,
& V_101 ) ;
#endif
if ( V_16 != V_23 )
return NULL ;
V_100 = ( V_73 * ) V_101 ;
V_99 = ( T_14 * ) V_103 ;
for ( V_34 = 0 ; V_34 < V_105 - 1 ; V_34 ++ )
* V_100 ++ = * V_99 ++ ;
* V_100 = '\0' ;
* V_98 = V_105 ;
return ( char * ) V_101 ;
}
