static int
F_1 ( void )
{
char * V_1 = F_2 ( 8 * sizeof( char ) , V_2 | V_3 ) ;
unsigned long V_4 , V_5 ;
int V_6 ;
if ( V_1 == NULL )
return - V_7 ;
V_4 = ( unsigned long ) V_1 ;
V_5 = V_8 ;
strcpy ( V_1 , L_1 ) ;
F_3 ( V_9 ) ;
asm volatile(
" diag %0,%1,0x64\n"
"0: ipm %2\n"
" srl %2,28\n"
" j 2f\n"
"1: la %2,3\n"
"2:\n"
EX_TABLE(0b, 1b)
: "+d" (rx), "+d" (ry), "=d" (rc) : : "cc");
F_4 ( V_1 ) ;
if ( V_6 != 3 ) {
V_10 = V_11 ;
V_12 = V_13 ;
V_14 = V_15 ;
V_16 = V_8 ;
V_17 = V_18 ;
return 0 ;
}
V_10 = V_19 ;
V_12 = V_20 ;
V_14 = V_15 ;
V_16 = V_21 ;
V_17 = V_22 ;
return 0 ;
}
static void
F_5 ( char * V_1 , char * V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_1 [ V_24 ] == '\0' )
break;
V_23 [ V_24 ] = toupper ( V_1 [ V_24 ] ) ;
} ;
for (; V_24 < 8 ; V_24 ++ )
V_23 [ V_24 ] = ' ' ;
F_6 ( V_23 , 8 ) ;
}
static struct V_25 *
F_7 ( char * V_1 )
{
char V_23 [ 9 ] ;
struct V_26 * V_27 ;
struct V_25 * V_28 , * V_29 = NULL ;
F_8 ( ! F_9 ( & V_30 ) ) ;
F_5 ( V_1 , V_23 ) ;
F_10 (l, &dcss_list) {
V_28 = F_11 ( V_27 , struct V_25 , V_31 ) ;
if ( memcmp ( V_28 -> V_23 , V_23 , 8 ) == 0 ) {
V_29 = V_28 ;
break;
}
}
return V_29 ;
}
static inline int
F_12 ( int * V_32 , void * V_33 ,
unsigned long * V_34 , unsigned long * V_35 )
{
unsigned long V_4 , V_5 ;
int V_6 ;
if ( V_36 == 0 ) {
V_6 = F_1 () ;
if ( V_6 < 0 )
return V_6 ;
V_36 = 1 ;
}
V_4 = ( unsigned long ) V_33 ;
V_5 = ( unsigned long ) * V_32 ;
F_3 ( V_9 ) ;
if ( * V_32 > V_22 )
asm volatile(
" diag %0,%1,0x64\n"
" ipm %2\n"
" srl %2,28\n"
: "+d" (rx), "+d" (ry), "=d" (rc) : : "cc");
else
asm volatile(
" sam31\n"
" diag %0,%1,0x64\n"
" sam64\n"
" ipm %2\n"
" srl %2,28\n"
: "+d" (rx), "+d" (ry), "=d" (rc) : : "cc");
* V_34 = V_4 ;
* V_35 = V_5 ;
return V_6 ;
}
static inline int
F_13 ( int V_37 ) {
if ( V_37 == 44 )
return - V_38 ;
return - V_39 ;
}
static int
F_14 ( struct V_25 * V_40 )
{
unsigned long V_41 , V_42 ;
int V_43 , V_6 , V_24 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_47 = F_2 ( sizeof( * V_47 ) , V_2 | V_3 ) ;
V_45 = F_2 ( sizeof( * V_45 ) , V_2 | V_3 ) ;
if ( ( V_47 == NULL ) || ( V_45 == NULL ) ) {
V_6 = - V_7 ;
goto V_48;
}
V_47 -> V_49 = V_50 ;
V_47 -> V_51 = ( unsigned long ) V_45 ;
V_47 -> V_52 = sizeof( struct V_44 ) ;
memcpy ( V_47 -> V_53 , V_40 -> V_23 , 8 ) ;
V_43 = F_12 ( & V_17 , V_47 , & V_41 , & V_42 ) ;
if ( V_43 < 0 ) {
V_6 = V_43 ;
goto V_48;
}
if ( V_43 > 1 ) {
F_15 ( L_2 , V_42 ) ;
V_6 = F_13 ( V_42 ) ;
goto V_48;
}
if ( V_17 == V_22 ) {
struct V_54 * V_55 ;
V_55 = F_16 ( sizeof( * V_55 ) , V_2 | V_3 ) ;
if ( V_55 == NULL ) {
V_6 = - V_7 ;
goto V_48;
}
memcpy ( V_55 , V_45 , sizeof( struct V_54 ) ) ;
V_45 -> V_56 = ( unsigned long ) V_55 -> V_56 ;
V_45 -> V_57 = ( unsigned long ) V_55 -> V_57 ;
V_45 -> V_58 = V_55 -> V_58 ;
V_45 -> V_59 = V_55 -> V_59 ;
if ( V_45 -> V_58 > 6 )
V_45 -> V_59 = 6 ;
for ( V_24 = 0 ; V_24 < V_45 -> V_59 ; V_24 ++ ) {
V_45 -> V_60 [ V_24 ] . V_61 =
( unsigned long ) V_55 -> V_60 [ V_24 ] . V_61 ;
V_45 -> V_60 [ V_24 ] . V_62 =
( unsigned long ) V_55 -> V_60 [ V_24 ] . V_62 ;
}
F_4 ( V_55 ) ;
}
if ( V_45 -> V_58 > 6 ) {
V_6 = - V_63 ;
goto V_48;
}
if ( V_45 -> V_58 == 1 ) {
V_40 -> V_64 = V_45 -> V_60 [ 0 ] . V_61 & 0xff ;
} else {
unsigned long V_61 = V_45 -> V_56 >> V_65 ;
for ( V_24 = 0 ; V_24 < V_45 -> V_58 ; V_24 ++ ) {
if ( ( ( V_45 -> V_60 [ V_24 ] . V_61 & 0xff ) != V_66 ) &&
( ( V_45 -> V_60 [ V_24 ] . V_61 & 0xff ) != V_67 ) ) {
V_6 = - V_63 ;
goto V_48;
}
if ( V_61 != V_45 -> V_60 [ V_24 ] . V_61 >> V_65 ) {
V_6 = - V_63 ;
goto V_48;
}
V_61 = ( V_45 -> V_60 [ V_24 ] . V_62 >> V_65 ) + 1 ;
}
V_40 -> V_64 = V_68 ;
}
V_40 -> V_69 = V_45 -> V_56 ;
V_40 -> V_62 = V_45 -> V_57 ;
memcpy ( V_40 -> V_60 , V_45 -> V_60 , 6 * sizeof( struct V_70 ) ) ;
V_40 -> V_58 = V_45 -> V_58 ;
V_6 = 0 ;
V_48:
F_4 ( V_47 ) ;
F_4 ( V_45 ) ;
return V_6 ;
}
int
F_17 ( char * V_1 )
{
int V_6 ;
struct V_25 V_40 ;
if ( ! V_71 )
return - V_72 ;
F_5 ( V_1 , V_40 . V_23 ) ;
V_6 = F_14 ( & V_40 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_40 . V_64 ;
}
static int
F_18 ( struct V_25 * V_40 )
{
struct V_26 * V_27 ;
struct V_25 * V_28 ;
F_8 ( ! F_9 ( & V_30 ) ) ;
F_10 (l, &dcss_list) {
V_28 = F_11 ( V_27 , struct V_25 , V_31 ) ;
if ( ( V_28 -> V_69 >> 20 ) > ( V_40 -> V_62 >> 20 ) )
continue;
if ( ( V_28 -> V_62 >> 20 ) < ( V_40 -> V_69 >> 20 ) )
continue;
if ( V_40 == V_28 )
continue;
return 1 ;
}
return 0 ;
}
static int
F_19 ( char * V_1 , int V_73 , unsigned long * V_74 , unsigned long * V_62 )
{
unsigned long V_69 , V_75 , V_41 ;
struct V_25 * V_40 ;
int V_6 , V_43 ;
V_69 = V_75 = 0 ;
V_40 = F_2 ( sizeof( * V_40 ) , V_2 | V_3 ) ;
if ( V_40 == NULL ) {
V_6 = - V_7 ;
goto V_76;
}
F_5 ( V_1 , V_40 -> V_23 ) ;
V_6 = F_14 ( V_40 ) ;
if ( V_6 < 0 )
goto V_48;
if ( V_10 == V_11 ) {
if ( F_18 ( V_40 ) ) {
V_6 = - V_77 ;
goto V_48;
}
}
V_6 = F_20 ( V_40 -> V_69 , V_40 -> V_62 - V_40 -> V_69 + 1 ) ;
if ( V_6 )
goto V_48;
V_40 -> V_78 = F_16 ( sizeof( struct V_79 ) , V_2 ) ;
if ( V_40 -> V_78 == NULL ) {
V_6 = - V_7 ;
goto V_80;
}
V_40 -> V_78 -> V_81 = V_82 | V_83 ;
V_40 -> V_78 -> V_61 = V_40 -> V_69 ;
V_40 -> V_78 -> V_62 = V_40 -> V_62 ;
memcpy ( & V_40 -> V_84 , V_40 -> V_23 , 8 ) ;
F_21 ( V_40 -> V_84 , 8 ) ;
V_40 -> V_84 [ 8 ] = '\0' ;
strncat ( V_40 -> V_84 , L_3 , 7 ) ;
V_40 -> V_78 -> V_1 = V_40 -> V_84 ;
V_6 = V_40 -> V_64 ;
if ( V_6 == V_85 ||
( ( V_6 == V_86 || V_6 == V_87 ) && ! V_73 ) )
V_40 -> V_78 -> V_81 |= V_88 ;
if ( F_22 ( & V_89 , V_40 -> V_78 ) ) {
V_6 = - V_77 ;
F_4 ( V_40 -> V_78 ) ;
goto V_80;
}
if ( V_73 )
V_43 = F_12 ( & V_12 , V_40 -> V_23 ,
& V_69 , & V_75 ) ;
else
V_43 = F_12 ( & V_10 , V_40 -> V_23 ,
& V_69 , & V_75 ) ;
if ( V_43 < 0 ) {
F_12 ( & V_14 , V_40 -> V_23 ,
& V_41 , & V_41 ) ;
V_6 = V_43 ;
goto V_90;
}
if ( V_43 > 1 ) {
F_15 ( L_4 , V_1 ,
V_75 ) ;
V_6 = F_13 ( V_75 ) ;
F_12 ( & V_14 , V_40 -> V_23 ,
& V_41 , & V_41 ) ;
goto V_90;
}
V_40 -> V_69 = V_69 ;
V_40 -> V_62 = V_75 ;
V_40 -> V_73 = V_73 ;
F_23 ( & V_40 -> V_91 , 1 ) ;
F_24 ( & V_40 -> V_31 , & V_92 ) ;
* V_74 = V_40 -> V_69 ;
* V_62 = V_40 -> V_62 ;
if ( V_73 )
F_25 ( L_5
L_6 , V_1 , ( void * ) V_40 -> V_69 ,
( void * ) V_40 -> V_62 , V_93 [ V_40 -> V_64 ] ) ;
else {
F_25 ( L_7
L_8 , V_1 , ( void * ) V_40 -> V_69 ,
( void * ) V_40 -> V_62 , V_93 [ V_40 -> V_64 ] ) ;
}
goto V_76;
V_90:
F_26 ( V_40 -> V_78 ) ;
F_4 ( V_40 -> V_78 ) ;
V_80:
F_27 ( V_40 -> V_69 , V_40 -> V_62 - V_40 -> V_69 + 1 ) ;
V_48:
F_4 ( V_40 ) ;
V_76:
return V_6 ;
}
int
F_28 ( char * V_1 , int V_73 , unsigned long * V_74 ,
unsigned long * V_62 )
{
struct V_25 * V_40 ;
int V_6 ;
if ( ! V_71 )
return - V_72 ;
F_29 ( & V_30 ) ;
V_40 = F_7 ( V_1 ) ;
if ( V_40 == NULL )
V_6 = F_19 ( V_1 , V_73 , V_74 , V_62 ) ;
else {
if ( V_73 == V_40 -> V_73 ) {
F_30 ( & V_40 -> V_91 ) ;
* V_74 = V_40 -> V_69 ;
* V_62 = V_40 -> V_62 ;
V_6 = V_40 -> V_64 ;
} else {
* V_74 = * V_62 = 0 ;
V_6 = - V_94 ;
}
}
F_31 ( & V_30 ) ;
return V_6 ;
}
int
F_32 ( char * V_1 , int V_73 )
{
struct V_25 * V_40 ;
unsigned long V_69 , V_75 , V_41 ;
int V_6 , V_43 ;
V_69 = V_75 = 0 ;
F_29 ( & V_30 ) ;
V_40 = F_7 ( V_1 ) ;
if ( V_40 == NULL ) {
V_6 = - V_95 ;
goto V_96;
}
if ( V_73 == V_40 -> V_73 ) {
F_25 ( L_9
L_10 , V_1 ) ;
V_6 = 0 ;
goto V_96;
}
if ( F_33 ( & V_40 -> V_91 ) != 1 ) {
F_15 ( L_11 ,
V_1 ) ;
V_6 = - V_97 ;
goto V_96;
}
F_26 ( V_40 -> V_78 ) ;
if ( V_73 )
V_40 -> V_78 -> V_81 &= ~ V_88 ;
else
if ( V_40 -> V_64 == V_86 ||
V_40 -> V_64 == V_87 )
V_40 -> V_78 -> V_81 |= V_88 ;
if ( F_22 ( & V_89 , V_40 -> V_78 ) ) {
F_15 ( L_12
L_13 , V_1 ) ;
V_6 = - V_77 ;
F_4 ( V_40 -> V_78 ) ;
goto V_98;
}
F_12 ( & V_14 , V_40 -> V_23 , & V_41 , & V_41 ) ;
if ( V_73 )
V_43 = F_12 ( & V_12 , V_40 -> V_23 ,
& V_69 , & V_75 ) ;
else
V_43 = F_12 ( & V_10 , V_40 -> V_23 ,
& V_69 , & V_75 ) ;
if ( V_43 < 0 ) {
V_6 = V_43 ;
goto V_99;
}
if ( V_43 > 1 ) {
F_15 ( L_14 , V_1 ,
V_75 ) ;
V_6 = F_13 ( V_75 ) ;
goto V_99;
}
V_40 -> V_69 = V_69 ;
V_40 -> V_62 = V_75 ;
V_40 -> V_73 = V_73 ;
V_6 = 0 ;
goto V_96;
V_99:
F_26 ( V_40 -> V_78 ) ;
F_4 ( V_40 -> V_78 ) ;
V_98:
F_27 ( V_40 -> V_69 , V_40 -> V_62 - V_40 -> V_69 + 1 ) ;
F_34 ( & V_40 -> V_31 ) ;
F_12 ( & V_14 , V_40 -> V_23 , & V_41 , & V_41 ) ;
F_4 ( V_40 ) ;
V_96:
F_31 ( & V_30 ) ;
return V_6 ;
}
void
F_35 ( char * V_1 )
{
unsigned long V_41 ;
struct V_25 * V_40 ;
if ( ! V_71 )
return;
F_29 ( & V_30 ) ;
V_40 = F_7 ( V_1 ) ;
if ( V_40 == NULL ) {
F_36 ( L_15 , V_1 ) ;
goto V_96;
}
if ( F_37 ( & V_40 -> V_91 ) != 0 )
goto V_96;
F_26 ( V_40 -> V_78 ) ;
F_4 ( V_40 -> V_78 ) ;
F_27 ( V_40 -> V_69 , V_40 -> V_62 - V_40 -> V_69 + 1 ) ;
F_34 ( & V_40 -> V_31 ) ;
F_12 ( & V_14 , V_40 -> V_23 , & V_41 , & V_41 ) ;
F_4 ( V_40 ) ;
V_96:
F_31 ( & V_30 ) ;
}
void
F_38 ( char * V_1 )
{
struct V_25 * V_40 ;
char V_100 [ 160 ] ;
char V_101 [ 80 ] ;
int V_24 , V_102 ;
if ( ! V_71 )
return;
F_29 ( & V_30 ) ;
V_40 = F_7 ( V_1 ) ;
if ( V_40 == NULL ) {
F_36 ( L_16 , V_1 ) ;
goto V_76;
}
sprintf ( V_100 , L_17 , V_1 ) ;
for ( V_24 = 0 ; V_24 < V_40 -> V_58 ; V_24 ++ ) {
sprintf ( V_100 + strlen ( V_100 ) , L_18 ,
V_40 -> V_60 [ V_24 ] . V_61 >> V_65 ,
V_40 -> V_60 [ V_24 ] . V_62 >> V_65 ,
V_93 [ V_40 -> V_60 [ V_24 ] . V_61 & 0xff ] ) ;
}
sprintf ( V_101 , L_19 , V_1 ) ;
V_102 = 0 ;
F_39 ( V_100 , NULL , 0 , & V_102 ) ;
if ( V_102 ) {
F_36 ( L_20
L_21 , V_102 ) ;
goto V_76;
}
F_39 ( V_101 , NULL , 0 , & V_102 ) ;
if ( V_102 ) {
F_36 ( L_22
L_21 , V_102 ) ;
goto V_76;
}
V_76:
F_31 ( & V_30 ) ;
}
void F_40 ( int V_6 , char * V_103 )
{
switch ( V_6 ) {
case - V_38 :
F_36 ( L_23 , V_103 ) ;
break;
case - V_72 :
F_36 ( L_24
L_25 , V_103 ) ;
break;
case - V_39 :
F_36 ( L_26
L_27 , V_103 ) ;
break;
case - V_63 :
F_36 ( L_28
L_29 , V_103 ) ;
break;
case - V_104 :
F_36 ( L_30
L_31 , V_103 ) ;
break;
case - V_77 :
F_36 ( L_32
L_29 , V_103 ) ;
break;
case - V_94 :
F_36 ( L_33
L_10 , V_103 ) ;
break;
case - V_7 :
F_36 ( L_34
L_35 , V_103 ) ;
break;
case - V_105 :
F_36 ( L_36
L_37 , V_103 , V_106 ) ;
break;
default:
break;
}
}
