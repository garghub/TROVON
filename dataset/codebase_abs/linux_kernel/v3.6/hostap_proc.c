static int F_1 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
char * V_7 = V_1 ;
T_2 * V_8 = ( T_2 * ) V_6 ;
int V_9 ;
if ( V_3 != 0 ) {
* V_5 = 1 ;
return 0 ;
}
V_7 += sprintf ( V_7 , L_1 ,
V_8 -> V_10 , V_8 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
V_7 += sprintf ( V_7 , L_2 ,
V_8 -> V_13 [ V_9 ] , V_8 -> V_14 [ V_9 ] ) ;
V_7 += sprintf ( V_7 , L_3 , V_8 -> V_15 ) ;
V_7 += sprintf ( V_7 , L_4 , V_8 -> V_16 ) ;
V_7 += sprintf ( V_7 , L_5 , V_8 -> V_17 ) ;
V_7 += sprintf ( V_7 , L_6 ,
V_8 -> V_18 ) ;
V_7 += sprintf ( V_7 , L_7 , V_8 -> V_19 ) ;
V_7 += sprintf ( V_7 , L_8 , V_8 -> V_20 ) ;
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
if ( V_8 -> V_22 . V_23 [ V_9 ] &&
V_8 -> V_22 . V_23 [ V_9 ] -> V_24 ) {
V_7 += sprintf ( V_7 , L_9 , V_9 ,
V_8 -> V_22 . V_23 [ V_9 ] -> V_24 -> V_25 ) ;
}
}
V_7 += sprintf ( V_7 , L_10 , V_8 -> V_26 ) ;
V_7 += sprintf ( V_7 , L_11 , V_8 -> V_27 -> V_28 == V_29 ) ;
V_7 += sprintf ( V_7 , L_12 , V_8 -> V_30 ) ;
V_7 += sprintf ( V_7 , L_13 , V_8 -> V_31 ) ;
return ( V_7 - V_1 ) ;
}
static int F_2 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
char * V_7 = V_1 ;
T_2 * V_8 = ( T_2 * ) V_6 ;
struct V_32 * V_33 = & V_8 -> V_34 ;
if ( V_3 != 0 ) {
* V_5 = 1 ;
return 0 ;
}
V_7 += sprintf ( V_7 , L_14 , V_33 -> V_35 ) ;
V_7 += sprintf ( V_7 , L_15 , V_33 -> V_36 ) ;
V_7 += sprintf ( V_7 , L_16 , V_33 -> V_37 ) ;
V_7 += sprintf ( V_7 , L_17 , V_33 -> V_38 ) ;
V_7 += sprintf ( V_7 , L_18 , V_33 -> V_39 ) ;
V_7 += sprintf ( V_7 , L_19 ,
V_33 -> V_40 ) ;
V_7 += sprintf ( V_7 , L_20 ,
V_33 -> V_41 ) ;
V_7 += sprintf ( V_7 , L_21 ,
V_33 -> V_42 ) ;
V_7 += sprintf ( V_7 , L_22 ,
V_33 -> V_43 ) ;
V_7 += sprintf ( V_7 , L_23 , V_33 -> V_44 ) ;
V_7 += sprintf ( V_7 , L_24 , V_33 -> V_45 ) ;
V_7 += sprintf ( V_7 , L_25 , V_33 -> V_46 ) ;
V_7 += sprintf ( V_7 , L_26 , V_33 -> V_47 ) ;
V_7 += sprintf ( V_7 , L_27 , V_33 -> V_48 ) ;
V_7 += sprintf ( V_7 , L_28 , V_33 -> V_49 ) ;
V_7 += sprintf ( V_7 , L_29 , V_33 -> V_50 ) ;
V_7 += sprintf ( V_7 , L_30 ,
V_33 -> V_51 ) ;
V_7 += sprintf ( V_7 , L_31 , V_33 -> V_52 ) ;
V_7 += sprintf ( V_7 , L_32 ,
V_33 -> V_53 ) ;
V_7 += sprintf ( V_7 , L_33 ,
V_33 -> V_54 ) ;
V_7 += sprintf ( V_7 , L_34 ,
V_33 -> V_55 ) ;
return ( V_7 - V_1 ) ;
}
static int F_3 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
char * V_7 = V_1 ;
T_2 * V_8 = ( T_2 * ) V_6 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
if ( V_3 > V_60 ) {
* V_5 = 1 ;
return 0 ;
}
F_4 ( & V_8 -> V_61 ) ;
F_5 (ptr, &local->hostap_interfaces) {
V_59 = F_6 ( V_57 , struct V_58 , V_62 ) ;
if ( V_59 -> type != V_63 )
continue;
V_7 += sprintf ( V_7 , L_35 ,
V_59 -> V_64 -> V_25 ,
V_59 -> V_65 . V_66 . V_67 ) ;
if ( ( V_7 - V_1 ) > V_60 ) {
F_7 ( V_68 L_36 ,
V_8 -> V_64 -> V_25 ) ;
break;
}
}
F_8 ( & V_8 -> V_61 ) ;
if ( ( V_7 - V_1 ) <= V_3 ) {
* V_5 = 1 ;
return 0 ;
}
* V_2 = V_1 + V_3 ;
return ( V_7 - V_1 - V_3 ) ;
}
static int F_9 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
char * V_7 = V_1 ;
T_2 * V_8 = ( T_2 * ) V_6 ;
struct V_56 * V_57 ;
struct V_69 * V_70 ;
int V_9 ;
if ( V_3 > V_60 ) {
* V_5 = 1 ;
return 0 ;
}
V_7 += sprintf ( V_7 , L_37
L_38 ) ;
F_10 ( & V_8 -> V_71 ) ;
F_5 (ptr, &local->bss_list) {
V_70 = F_6 ( V_57 , struct V_69 , V_62 ) ;
V_7 += sprintf ( V_7 , L_39 ,
V_70 -> V_72 , V_70 -> V_73 ,
V_70 -> V_4 , V_70 -> V_74 ) ;
for ( V_9 = 0 ; V_9 < V_70 -> V_75 ; V_9 ++ ) {
V_7 += sprintf ( V_7 , L_40 ,
V_70 -> V_76 [ V_9 ] >= 32 && V_70 -> V_76 [ V_9 ] < 127 ?
V_70 -> V_76 [ V_9 ] : '_' ) ;
}
V_7 += sprintf ( V_7 , L_41 ) ;
for ( V_9 = 0 ; V_9 < V_70 -> V_75 ; V_9 ++ ) {
V_7 += sprintf ( V_7 , L_42 , V_70 -> V_76 [ V_9 ] ) ;
}
V_7 += sprintf ( V_7 , L_41 ) ;
for ( V_9 = 0 ; V_9 < V_70 -> V_77 ; V_9 ++ ) {
V_7 += sprintf ( V_7 , L_42 , V_70 -> V_78 [ V_9 ] ) ;
}
V_7 += sprintf ( V_7 , L_43 ) ;
if ( ( V_7 - V_1 ) > V_60 ) {
F_7 ( V_68 L_44 ,
V_8 -> V_64 -> V_25 ) ;
break;
}
}
F_11 ( & V_8 -> V_71 ) ;
if ( ( V_7 - V_1 ) <= V_3 ) {
* V_5 = 1 ;
return 0 ;
}
* V_2 = V_1 + V_3 ;
return ( V_7 - V_1 - V_3 ) ;
}
static int F_12 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
char * V_7 = V_1 ;
T_2 * V_8 = ( T_2 * ) V_6 ;
int V_9 ;
if ( V_3 > V_60 ) {
* V_5 = 1 ;
return 0 ;
}
V_7 += sprintf ( V_7 , L_45 , V_8 -> V_22 . V_79 ) ;
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
if ( V_8 -> V_22 . V_23 [ V_9 ] &&
V_8 -> V_22 . V_23 [ V_9 ] -> V_24 &&
V_8 -> V_22 . V_23 [ V_9 ] -> V_24 -> V_80 ) {
V_7 = V_8 -> V_22 . V_23 [ V_9 ] -> V_24 -> V_80 (
V_7 , V_8 -> V_22 . V_23 [ V_9 ] -> V_81 ) ;
}
}
if ( ( V_7 - V_1 ) <= V_3 ) {
* V_5 = 1 ;
return 0 ;
}
* V_2 = V_1 + V_3 ;
return ( V_7 - V_1 - V_3 ) ;
}
static int F_13 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
T_2 * V_8 = ( T_2 * ) V_6 ;
if ( V_8 -> V_82 == NULL || V_3 >= V_83 ) {
* V_5 = 1 ;
return 0 ;
}
if ( V_3 + V_4 > V_83 )
V_4 = V_83 - V_3 ;
memcpy ( V_1 , V_8 -> V_82 + V_3 , V_4 ) ;
return V_4 ;
}
static int F_14 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
T_2 * V_8 = ( T_2 * ) V_6 ;
if ( V_8 -> V_27 -> V_84 == NULL ) {
* V_5 = 1 ;
return 0 ;
}
if ( V_8 -> V_27 -> V_84 ( V_8 -> V_64 , V_3 , V_4 , V_1 ) ) {
* V_5 = 1 ;
return 0 ;
}
* V_2 = V_1 ;
return V_4 ;
}
static int F_15 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
T_2 * V_8 = ( T_2 * ) V_6 ;
int V_85 = V_8 -> V_86 ;
int V_87 , V_88 , V_89 , V_90 ;
if ( V_3 + V_4 > V_91 * 4 ) {
* V_5 = 1 ;
if ( V_3 >= V_91 * 4 )
return 0 ;
V_4 = V_91 * 4 - V_3 ;
}
V_90 = 0 ;
V_87 = ( V_91 - V_85 ) * 4 ;
V_88 = V_4 ;
if ( V_3 < V_87 ) {
V_89 = V_87 - V_3 ;
if ( V_89 > V_4 )
V_89 = V_4 ;
memcpy ( V_1 , ( ( V_92 * ) & V_8 -> V_93 [ V_85 ] ) + V_3 , V_89 ) ;
V_88 -= V_89 ;
if ( V_88 > 0 )
memcpy ( & V_1 [ V_89 ] , V_8 -> V_93 , V_88 ) ;
} else {
memcpy ( V_1 , ( ( V_92 * ) V_8 -> V_93 ) + ( V_3 - V_87 ) ,
V_88 ) ;
}
* V_2 = V_1 ;
return V_4 ;
}
static int F_16 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
char * V_7 = V_1 ;
T_2 * V_8 = ( T_2 * ) V_6 ;
int V_94 , V_9 , V_95 , V_96 = 0 ;
struct V_97 * V_98 ;
V_92 * V_99 ;
V_7 += sprintf ( V_7 , L_46
L_47 ) ;
F_10 ( & V_8 -> V_71 ) ;
for ( V_94 = 0 ; V_94 < V_8 -> V_100 ; V_94 ++ ) {
V_98 = & V_8 -> V_101 [ V_94 ] ;
if ( V_96 + ( V_7 - V_1 ) <= V_3 ) {
V_96 += V_7 - V_1 ;
V_7 = V_1 ;
}
if ( V_96 + ( V_7 - V_1 ) > V_3 + V_4 )
break;
if ( ( V_7 - V_1 ) > ( V_102 - 200 ) )
break;
V_7 += sprintf ( V_7 , L_48 ,
F_17 ( V_98 -> V_103 ) ,
( V_104 ) F_17 ( V_98 -> V_105 ) ,
( V_104 ) F_17 ( V_98 -> V_106 ) ,
F_17 ( V_98 -> V_107 ) ,
F_17 ( V_98 -> V_108 ) ,
F_17 ( V_98 -> V_109 ) ,
V_98 -> V_72 ,
F_17 ( V_98 -> V_110 ) ) ;
V_99 = V_98 -> V_111 ;
for ( V_9 = 0 ; V_9 < sizeof( V_98 -> V_111 ) ; V_9 ++ ) {
if ( V_99 [ V_9 ] == 0 )
break;
V_7 += sprintf ( V_7 , L_49 , V_99 [ V_9 ] ) ;
}
V_7 += sprintf ( V_7 , L_50 ) ;
V_99 = V_98 -> V_76 ;
V_95 = F_17 ( V_98 -> V_75 ) ;
if ( V_95 > 32 )
V_95 = 32 ;
for ( V_9 = 0 ; V_9 < V_95 ; V_9 ++ ) {
unsigned char V_112 = V_99 [ V_9 ] ;
if ( V_112 >= 32 && V_112 < 127 )
V_7 += sprintf ( V_7 , L_40 , V_112 ) ;
else
V_7 += sprintf ( V_7 , L_49 , V_112 ) ;
}
V_7 += sprintf ( V_7 , L_43 ) ;
}
F_11 ( & V_8 -> V_71 ) ;
V_96 += ( V_7 - V_1 ) ;
if ( V_96 >= V_3 + V_4 )
* V_5 = 1 ;
if ( V_96 < V_3 ) {
* V_5 = 1 ;
return 0 ;
}
V_95 = V_96 - V_3 ;
if ( V_95 > ( V_7 - V_1 ) )
V_95 = V_7 - V_1 ;
* V_2 = V_7 - V_95 ;
if ( V_95 > V_4 )
V_95 = V_4 ;
return V_95 ;
}
void F_18 ( T_2 * V_8 )
{
V_8 -> V_113 = NULL ;
if ( V_114 == NULL ) {
F_7 ( V_115 L_51 ,
V_8 -> V_64 -> V_25 ) ;
return;
}
V_8 -> V_113 = F_19 ( V_8 -> V_116 -> V_25 , V_114 ) ;
if ( V_8 -> V_113 == NULL ) {
F_7 ( V_117 L_52 ,
V_8 -> V_116 -> V_25 ) ;
return;
}
#ifndef F_20
F_21 ( L_53 , 0 , V_8 -> V_113 ,
F_1 , V_8 ) ;
#endif
F_21 ( L_54 , 0 , V_8 -> V_113 ,
F_2 , V_8 ) ;
F_21 ( L_55 , 0 , V_8 -> V_113 ,
F_3 , V_8 ) ;
F_21 ( L_56 , 0 , V_8 -> V_113 ,
F_13 , V_8 ) ;
F_21 ( L_57 , 0 , V_8 -> V_113 ,
F_14 , V_8 ) ;
F_21 ( L_58 , 0 , V_8 -> V_113 ,
F_9 , V_8 ) ;
F_21 ( L_59 , 0 , V_8 -> V_113 ,
F_12 , V_8 ) ;
#ifdef F_22
F_21 ( L_60 , 0 , V_8 -> V_113 ,
F_15 , V_8 ) ;
#endif
#ifndef F_23
F_21 ( L_61 , 0 , V_8 -> V_113 ,
F_16 , V_8 ) ;
#endif
}
void F_24 ( T_2 * V_8 )
{
if ( V_8 -> V_113 != NULL ) {
#ifndef F_23
F_25 ( L_61 , V_8 -> V_113 ) ;
#endif
#ifdef F_22
F_25 ( L_60 , V_8 -> V_113 ) ;
#endif
F_25 ( L_56 , V_8 -> V_113 ) ;
F_25 ( L_57 , V_8 -> V_113 ) ;
F_25 ( L_55 , V_8 -> V_113 ) ;
F_25 ( L_54 , V_8 -> V_113 ) ;
F_25 ( L_58 , V_8 -> V_113 ) ;
F_25 ( L_59 , V_8 -> V_113 ) ;
#ifndef F_20
F_25 ( L_53 , V_8 -> V_113 ) ;
#endif
if ( V_114 != NULL )
F_25 ( V_8 -> V_113 -> V_25 , V_114 ) ;
}
}
