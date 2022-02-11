static void F_1 ( T_1 * V_1 , char * V_2 )
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
static T_3 F_3 ( T_1 * V_1 ,
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
static T_3 F_5 ( T_1 * V_1 ,
unsigned long V_23 , unsigned long V_24 ,
unsigned long * V_25 , unsigned long V_26 )
{
unsigned long V_7 , V_8 ;
T_4 * V_6 ;
T_3 V_12 ;
unsigned long V_27 ;
T_6 V_28 = 0 ;
int V_29 ;
V_12 = F_3 ( V_1 , & V_6 , & V_7 , & V_8 ,
NULL , NULL ) ;
if ( V_12 != V_18 )
goto V_19;
if ( V_24 < V_30 )
V_24 = V_30 ;
V_27 = F_6 ( V_23 , V_30 ) / V_30 ;
V_15:
for ( V_29 = 0 ; V_29 < V_7 / V_8 ; V_29 ++ ) {
T_4 * V_31 ;
unsigned long V_11 = ( unsigned long ) V_6 ;
T_6 V_32 , V_33 ;
V_31 = ( T_4 * ) ( V_11 + ( V_29 * V_8 ) ) ;
if ( V_31 -> type != V_34 )
continue;
if ( V_31 -> V_35 < V_27 )
continue;
V_32 = V_31 -> V_36 ;
V_33 = V_32 + V_31 -> V_35 * ( 1UL << V_37 ) ;
if ( ( V_32 + V_23 ) > V_33 || ( V_32 + V_23 ) > V_26 )
continue;
if ( V_33 - V_23 > V_26 )
V_33 = V_26 ;
if ( F_7 ( V_33 - V_23 , V_24 ) < V_32 )
continue;
V_32 = F_7 ( V_33 - V_23 , V_24 ) ;
if ( V_32 == 0x0 )
continue;
if ( V_32 > V_28 )
V_28 = V_32 ;
}
if ( ! V_28 )
V_12 = V_38 ;
else {
V_12 = F_4 ( V_39 ,
V_40 , V_17 ,
V_27 , & V_28 ) ;
if ( V_12 != V_18 ) {
V_26 = V_28 ;
V_28 = 0 ;
goto V_15;
}
* V_25 = V_28 ;
}
F_4 ( V_22 , V_6 ) ;
V_19:
return V_12 ;
}
static T_3 F_8 ( T_1 * V_1 ,
unsigned long V_23 , unsigned long V_24 ,
unsigned long * V_25 )
{
unsigned long V_7 , V_8 ;
T_4 * V_6 ;
T_3 V_12 ;
unsigned long V_27 ;
int V_29 ;
V_12 = F_3 ( V_1 , & V_6 , & V_7 , & V_8 ,
NULL , NULL ) ;
if ( V_12 != V_18 )
goto V_19;
if ( V_24 < V_30 )
V_24 = V_30 ;
V_27 = F_6 ( V_23 , V_30 ) / V_30 ;
for ( V_29 = 0 ; V_29 < V_7 / V_8 ; V_29 ++ ) {
T_4 * V_31 ;
unsigned long V_11 = ( unsigned long ) V_6 ;
T_6 V_32 , V_33 ;
V_31 = ( T_4 * ) ( V_11 + ( V_29 * V_8 ) ) ;
if ( V_31 -> type != V_34 )
continue;
if ( V_31 -> V_35 < V_27 )
continue;
V_32 = V_31 -> V_36 ;
V_33 = V_32 + V_31 -> V_35 * ( 1UL << V_37 ) ;
if ( V_32 == 0x0 )
V_32 += 8 ;
V_32 = F_6 ( V_32 , V_24 ) ;
if ( ( V_32 + V_23 ) > V_33 )
continue;
V_12 = F_4 ( V_39 ,
V_40 , V_17 ,
V_27 , & V_32 ) ;
if ( V_12 == V_18 ) {
* V_25 = V_32 ;
break;
}
}
if ( V_29 == V_7 / V_8 )
V_12 = V_38 ;
F_4 ( V_22 , V_6 ) ;
V_19:
return V_12 ;
}
static void F_9 ( T_1 * V_1 , unsigned long V_23 ,
unsigned long V_25 )
{
unsigned long V_27 ;
if ( ! V_23 )
return;
V_27 = F_6 ( V_23 , V_30 ) / V_30 ;
F_4 ( V_41 , V_25 , V_27 ) ;
}
static T_3 F_10 ( T_1 * V_1 ,
T_7 * V_42 ,
char * V_43 , char * V_44 ,
unsigned long V_28 ,
unsigned long * V_45 ,
unsigned long * V_46 )
{
struct V_47 * V_48 ;
unsigned long V_49 ;
T_6 V_50 ;
T_8 * V_51 ;
T_3 V_12 ;
int V_52 ;
char * V_2 ;
int V_29 , V_53 , V_54 ;
V_49 = 0 ;
V_50 = 0 ;
V_2 = V_43 ;
V_53 = 0 ;
if ( ! V_45 || ! V_46 )
return V_55 ;
* V_45 = 0 ;
* V_46 = 0 ;
if ( ! V_2 || ! * V_2 )
return V_18 ;
for ( V_52 = 0 ; * V_2 ; V_52 ++ ) {
V_2 = strstr ( V_2 , V_44 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_44 ) ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' )
V_2 ++ ;
}
if ( ! V_52 )
return V_18 ;
V_12 = F_4 ( V_16 , V_17 ,
V_52 * sizeof( * V_48 ) , ( void * * ) & V_48 ) ;
if ( V_12 != V_18 ) {
F_1 ( V_1 , L_1 ) ;
goto V_19;
}
V_2 = V_43 ;
for ( V_29 = 0 ; V_29 < V_52 ; V_29 ++ ) {
struct V_47 * V_56 ;
T_2 V_57 [ 256 ] ;
T_2 * V_58 ;
V_2 = strstr ( V_2 , V_44 ) ;
if ( ! V_2 )
break;
V_2 += strlen ( V_44 ) ;
V_56 = & V_48 [ V_29 ] ;
V_58 = V_57 ;
while ( * V_2 == '/' || * V_2 == '\\' )
V_2 ++ ;
while ( * V_2 && * V_2 != ' ' && * V_2 != '\n' ) {
if ( ( V_59 * ) V_58 >= ( V_59 * ) V_57 + sizeof( V_57 ) )
break;
if ( * V_2 == '/' ) {
* V_58 ++ = '\\' ;
V_2 ++ ;
} else {
* V_58 ++ = * V_2 ++ ;
}
}
* V_58 = '\0' ;
if ( ! V_29 ) {
V_12 = F_11 ( V_1 , V_42 ,
( void * * ) & V_51 ) ;
if ( V_12 != V_18 )
goto V_60;
}
V_12 = F_12 ( V_1 , V_51 , V_57 ,
( void * * ) & V_56 -> V_61 , & V_56 -> V_23 ) ;
if ( V_12 != V_18 )
goto V_62;
V_50 += V_56 -> V_23 ;
}
if ( V_50 ) {
unsigned long V_25 ;
V_12 = F_5 ( V_1 , V_50 , 0x1000 ,
& V_49 , V_28 ) ;
if ( V_12 != V_18 ) {
F_1 ( V_1 , L_2 ) ;
goto V_62;
}
if ( V_49 > V_28 ) {
F_1 ( V_1 , L_3 ) ;
V_12 = V_55 ;
goto V_63;
}
V_25 = V_49 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
unsigned long V_23 ;
V_23 = V_48 [ V_53 ] . V_23 ;
while ( V_23 ) {
unsigned long V_64 ;
if ( V_23 > V_65 )
V_64 = V_65 ;
else
V_64 = V_23 ;
V_12 = F_13 ( V_48 [ V_53 ] . V_61 ,
& V_64 ,
( void * ) V_25 ) ;
if ( V_12 != V_18 ) {
F_1 ( V_1 , L_4 ) ;
goto V_63;
}
V_25 += V_64 ;
V_23 -= V_64 ;
}
F_14 ( V_48 [ V_53 ] . V_61 ) ;
}
}
F_4 ( V_22 , V_48 ) ;
* V_45 = V_49 ;
* V_46 = V_50 ;
return V_12 ;
V_63:
F_9 ( V_1 , V_50 , V_49 ) ;
V_62:
for ( V_54 = V_53 ; V_54 < V_29 ; V_54 ++ )
F_14 ( V_48 [ V_54 ] . V_61 ) ;
V_60:
F_4 ( V_22 , V_48 ) ;
V_19:
* V_45 = 0 ;
* V_46 = 0 ;
return V_12 ;
}
static T_3 F_15 ( T_1 * V_1 ,
unsigned long * V_66 ,
unsigned long V_67 ,
unsigned long V_68 ,
unsigned long V_69 ,
unsigned long V_70 )
{
unsigned long V_71 ;
unsigned long V_72 = 0 ;
T_3 V_12 ;
unsigned long V_27 ;
T_9 V_73 = V_69 ;
if ( ! V_66 || ! V_67 || ! V_68 )
return V_55 ;
if ( V_68 < V_67 )
return V_55 ;
V_71 = * V_66 ;
V_27 = F_6 ( V_68 , V_30 ) / V_30 ;
V_12 = F_4 ( V_39 ,
V_40 , V_17 ,
V_27 , & V_73 ) ;
V_72 = V_73 ;
if ( V_12 != V_18 ) {
V_12 = F_8 ( V_1 , V_68 , V_70 ,
& V_72 ) ;
}
if ( V_12 != V_18 ) {
F_1 ( V_1 , L_5 ) ;
return V_12 ;
}
memcpy ( ( void * ) V_72 , ( void * ) V_71 , V_67 ) ;
* V_66 = V_72 ;
return V_12 ;
}
static char * F_16 ( T_1 * V_1 ,
T_7 * V_42 ,
int * V_74 )
{
T_10 * V_75 ;
V_59 * V_76 = NULL ;
unsigned long V_77 = 0 ;
int V_78 = V_42 -> V_78 / 2 ;
void * V_79 = V_42 -> V_80 ;
int V_81 = 0 ;
T_3 V_12 ;
int V_29 ;
T_10 V_82 = 0 ;
if ( V_79 ) {
V_75 = V_79 ;
while ( * V_75 && * V_75 != '\n' && V_81 < V_78 ) {
V_75 ++ ;
V_81 ++ ;
}
}
if ( V_81 == 0 ) {
V_81 = 1 ;
V_79 = & V_82 ;
}
V_81 ++ ;
#ifdef F_17
V_12 = F_5 ( V_1 , V_81 , 0 ,
& V_77 , 0xfffff000 ) ;
#else
V_12 = F_8 ( V_1 , V_81 , 0 ,
& V_77 ) ;
#endif
if ( V_12 != V_18 )
return NULL ;
V_76 = ( V_59 * ) V_77 ;
V_75 = ( T_10 * ) V_79 ;
for ( V_29 = 0 ; V_29 < V_81 - 1 ; V_29 ++ )
* V_76 ++ = * V_75 ++ ;
* V_76 = '\0' ;
* V_74 = V_81 ;
return ( char * ) V_77 ;
}
