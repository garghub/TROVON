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
V_16 = V_17 ;
return 0 ;
}
V_10 = V_18 ;
V_12 = V_19 ;
V_14 = V_15 ;
V_16 = V_20 ;
return 0 ;
}
static void
F_5 ( char * V_1 , char * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if ( V_1 [ V_22 ] == '\0' )
break;
V_21 [ V_22 ] = toupper ( V_1 [ V_22 ] ) ;
} ;
for (; V_22 < 8 ; V_22 ++ )
V_21 [ V_22 ] = ' ' ;
F_6 ( V_21 , 8 ) ;
}
static struct V_23 *
F_7 ( char * V_1 )
{
char V_21 [ 9 ] ;
struct V_24 * V_25 ;
struct V_23 * V_26 , * V_27 = NULL ;
F_8 ( ! F_9 ( & V_28 ) ) ;
F_5 ( V_1 , V_21 ) ;
F_10 (l, &dcss_list) {
V_26 = F_11 ( V_25 , struct V_23 , V_29 ) ;
if ( memcmp ( V_26 -> V_21 , V_21 , 8 ) == 0 ) {
V_27 = V_26 ;
break;
}
}
return V_27 ;
}
static inline int
F_12 ( int * V_30 , void * V_31 ,
unsigned long * V_32 , unsigned long * V_33 )
{
unsigned long V_4 , V_5 ;
int V_6 ;
if ( V_34 == 0 ) {
V_6 = F_1 () ;
if ( V_6 < 0 )
return V_6 ;
V_34 = 1 ;
}
V_4 = ( unsigned long ) V_31 ;
V_5 = ( unsigned long ) * V_30 ;
F_3 ( V_9 ) ;
if ( * V_30 > V_20 )
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
* V_32 = V_4 ;
* V_33 = V_5 ;
return V_6 ;
}
static inline int
F_13 ( int V_35 ) {
if ( V_35 == 44 )
return - V_36 ;
return - V_37 ;
}
static int
F_14 ( struct V_23 * V_38 )
{
unsigned long V_39 , V_40 ;
int V_41 , V_6 , V_22 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
V_45 = F_2 ( sizeof( * V_45 ) , V_2 | V_3 ) ;
V_43 = F_2 ( sizeof( * V_43 ) , V_2 | V_3 ) ;
if ( ( V_45 == NULL ) || ( V_43 == NULL ) ) {
V_6 = - V_7 ;
goto V_46;
}
V_45 -> V_47 = V_48 ;
V_45 -> V_49 = ( unsigned long ) V_43 ;
V_45 -> V_50 = sizeof( struct V_42 ) ;
memcpy ( V_45 -> V_51 , V_38 -> V_21 , 8 ) ;
V_41 = F_12 ( & V_16 , V_45 , & V_39 , & V_40 ) ;
if ( V_41 < 0 ) {
V_6 = V_41 ;
goto V_46;
}
if ( V_41 > 1 ) {
F_15 ( L_2 , V_40 ) ;
V_6 = F_13 ( V_40 ) ;
goto V_46;
}
if ( V_16 == V_20 ) {
struct V_52 * V_53 ;
V_53 = F_16 ( sizeof( * V_53 ) , V_2 | V_3 ) ;
if ( V_53 == NULL ) {
V_6 = - V_7 ;
goto V_46;
}
memcpy ( V_53 , V_43 , sizeof( struct V_52 ) ) ;
V_43 -> V_54 = ( unsigned long ) V_53 -> V_54 ;
V_43 -> V_55 = ( unsigned long ) V_53 -> V_55 ;
V_43 -> V_56 = V_53 -> V_56 ;
V_43 -> V_57 = V_53 -> V_57 ;
if ( V_43 -> V_56 > 6 )
V_43 -> V_57 = 6 ;
for ( V_22 = 0 ; V_22 < V_43 -> V_57 ; V_22 ++ ) {
V_43 -> V_58 [ V_22 ] . V_59 =
( unsigned long ) V_53 -> V_58 [ V_22 ] . V_59 ;
V_43 -> V_58 [ V_22 ] . V_60 =
( unsigned long ) V_53 -> V_58 [ V_22 ] . V_60 ;
}
F_4 ( V_53 ) ;
}
if ( V_43 -> V_56 > 6 ) {
V_6 = - V_61 ;
goto V_46;
}
if ( V_43 -> V_56 == 1 ) {
V_38 -> V_62 = V_43 -> V_58 [ 0 ] . V_59 & 0xff ;
} else {
unsigned long V_59 = V_43 -> V_54 >> V_63 ;
for ( V_22 = 0 ; V_22 < V_43 -> V_56 ; V_22 ++ ) {
if ( ( ( V_43 -> V_58 [ V_22 ] . V_59 & 0xff ) != V_64 ) &&
( ( V_43 -> V_58 [ V_22 ] . V_59 & 0xff ) != V_65 ) ) {
V_6 = - V_61 ;
goto V_46;
}
if ( V_59 != V_43 -> V_58 [ V_22 ] . V_59 >> V_63 ) {
V_6 = - V_61 ;
goto V_46;
}
V_59 = ( V_43 -> V_58 [ V_22 ] . V_60 >> V_63 ) + 1 ;
}
V_38 -> V_62 = V_66 ;
}
V_38 -> V_67 = V_43 -> V_54 ;
V_38 -> V_60 = V_43 -> V_55 ;
memcpy ( V_38 -> V_58 , V_43 -> V_58 , 6 * sizeof( struct V_68 ) ) ;
V_38 -> V_56 = V_43 -> V_56 ;
V_6 = 0 ;
V_46:
F_4 ( V_45 ) ;
F_4 ( V_43 ) ;
return V_6 ;
}
int
F_17 ( char * V_1 )
{
int V_6 ;
struct V_23 V_38 ;
if ( ! V_69 )
return - V_70 ;
F_5 ( V_1 , V_38 . V_21 ) ;
V_6 = F_14 ( & V_38 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_38 . V_62 ;
}
static int
F_18 ( struct V_23 * V_38 )
{
struct V_24 * V_25 ;
struct V_23 * V_26 ;
F_8 ( ! F_9 ( & V_28 ) ) ;
F_10 (l, &dcss_list) {
V_26 = F_11 ( V_25 , struct V_23 , V_29 ) ;
if ( ( V_26 -> V_67 >> 20 ) > ( V_38 -> V_60 >> 20 ) )
continue;
if ( ( V_26 -> V_60 >> 20 ) < ( V_38 -> V_67 >> 20 ) )
continue;
if ( V_38 == V_26 )
continue;
return 1 ;
}
return 0 ;
}
static int
F_19 ( char * V_1 , int V_71 , unsigned long * V_72 , unsigned long * V_60 )
{
unsigned long V_67 , V_73 , V_39 ;
struct V_23 * V_38 ;
int V_6 , V_41 ;
V_67 = V_73 = 0 ;
V_38 = F_2 ( sizeof( * V_38 ) , V_2 | V_3 ) ;
if ( V_38 == NULL ) {
V_6 = - V_7 ;
goto V_74;
}
F_5 ( V_1 , V_38 -> V_21 ) ;
V_6 = F_14 ( V_38 ) ;
if ( V_6 < 0 )
goto V_46;
if ( V_10 == V_11 ) {
if ( F_18 ( V_38 ) ) {
V_6 = - V_75 ;
goto V_46;
}
}
V_6 = F_20 ( V_38 -> V_67 , V_38 -> V_60 - V_38 -> V_67 + 1 ) ;
if ( V_6 )
goto V_46;
V_38 -> V_76 = F_16 ( sizeof( struct V_77 ) , V_2 ) ;
if ( V_38 -> V_76 == NULL ) {
V_6 = - V_7 ;
goto V_78;
}
V_38 -> V_76 -> V_79 = V_80 | V_81 ;
V_38 -> V_76 -> V_59 = V_38 -> V_67 ;
V_38 -> V_76 -> V_60 = V_38 -> V_60 ;
memcpy ( & V_38 -> V_82 , V_38 -> V_21 , 8 ) ;
F_21 ( V_38 -> V_82 , 8 ) ;
V_38 -> V_82 [ 8 ] = '\0' ;
strncat ( V_38 -> V_82 , L_3 , 7 ) ;
V_38 -> V_76 -> V_1 = V_38 -> V_82 ;
V_6 = V_38 -> V_62 ;
if ( V_6 == V_83 ||
( ( V_6 == V_84 || V_6 == V_85 ) && ! V_71 ) )
V_38 -> V_76 -> V_79 |= V_86 ;
if ( F_22 ( & V_87 , V_38 -> V_76 ) ) {
V_6 = - V_75 ;
F_4 ( V_38 -> V_76 ) ;
goto V_78;
}
if ( V_71 )
V_41 = F_12 ( & V_12 , V_38 -> V_21 ,
& V_67 , & V_73 ) ;
else
V_41 = F_12 ( & V_10 , V_38 -> V_21 ,
& V_67 , & V_73 ) ;
if ( V_41 < 0 ) {
F_12 ( & V_14 , V_38 -> V_21 ,
& V_39 , & V_39 ) ;
V_6 = V_41 ;
goto V_88;
}
if ( V_41 > 1 ) {
F_15 ( L_4 , V_1 , V_73 ) ;
V_6 = F_13 ( V_73 ) ;
F_12 ( & V_14 , V_38 -> V_21 ,
& V_39 , & V_39 ) ;
goto V_88;
}
V_38 -> V_67 = V_67 ;
V_38 -> V_60 = V_73 ;
V_38 -> V_71 = V_71 ;
F_23 ( & V_38 -> V_89 , 1 ) ;
F_24 ( & V_38 -> V_29 , & V_90 ) ;
* V_72 = V_38 -> V_67 ;
* V_60 = V_38 -> V_60 ;
if ( V_71 )
F_25 ( L_5
L_6 , V_1 , ( void * ) V_38 -> V_67 ,
( void * ) V_38 -> V_60 , V_91 [ V_38 -> V_62 ] ) ;
else {
F_25 ( L_7
L_8 , V_1 , ( void * ) V_38 -> V_67 ,
( void * ) V_38 -> V_60 , V_91 [ V_38 -> V_62 ] ) ;
}
goto V_74;
V_88:
F_26 ( V_38 -> V_76 ) ;
F_4 ( V_38 -> V_76 ) ;
V_78:
F_27 ( V_38 -> V_67 , V_38 -> V_60 - V_38 -> V_67 + 1 ) ;
V_46:
F_4 ( V_38 ) ;
V_74:
return V_6 ;
}
int
F_28 ( char * V_1 , int V_71 , unsigned long * V_72 ,
unsigned long * V_60 )
{
struct V_23 * V_38 ;
int V_6 ;
if ( ! V_69 )
return - V_70 ;
F_29 ( & V_28 ) ;
V_38 = F_7 ( V_1 ) ;
if ( V_38 == NULL )
V_6 = F_19 ( V_1 , V_71 , V_72 , V_60 ) ;
else {
if ( V_71 == V_38 -> V_71 ) {
F_30 ( & V_38 -> V_89 ) ;
* V_72 = V_38 -> V_67 ;
* V_60 = V_38 -> V_60 ;
V_6 = V_38 -> V_62 ;
} else {
* V_72 = * V_60 = 0 ;
V_6 = - V_92 ;
}
}
F_31 ( & V_28 ) ;
return V_6 ;
}
int
F_32 ( char * V_1 , int V_71 )
{
struct V_23 * V_38 ;
unsigned long V_67 , V_73 , V_39 ;
int V_6 , V_41 ;
V_67 = V_73 = 0 ;
F_29 ( & V_28 ) ;
V_38 = F_7 ( V_1 ) ;
if ( V_38 == NULL ) {
V_6 = - V_93 ;
goto V_94;
}
if ( V_71 == V_38 -> V_71 ) {
F_25 ( L_9
L_10 , V_1 ) ;
V_6 = 0 ;
goto V_94;
}
if ( F_33 ( & V_38 -> V_89 ) != 1 ) {
F_15 ( L_11 , V_1 ) ;
V_6 = - V_95 ;
goto V_94;
}
F_26 ( V_38 -> V_76 ) ;
if ( V_71 )
V_38 -> V_76 -> V_79 &= ~ V_86 ;
else
if ( V_38 -> V_62 == V_84 ||
V_38 -> V_62 == V_85 )
V_38 -> V_76 -> V_79 |= V_86 ;
if ( F_22 ( & V_87 , V_38 -> V_76 ) ) {
F_15 ( L_12 ,
V_1 ) ;
V_6 = - V_75 ;
F_4 ( V_38 -> V_76 ) ;
goto V_96;
}
F_12 ( & V_14 , V_38 -> V_21 , & V_39 , & V_39 ) ;
if ( V_71 )
V_41 = F_12 ( & V_12 , V_38 -> V_21 ,
& V_67 , & V_73 ) ;
else
V_41 = F_12 ( & V_10 , V_38 -> V_21 ,
& V_67 , & V_73 ) ;
if ( V_41 < 0 ) {
V_6 = V_41 ;
goto V_97;
}
if ( V_41 > 1 ) {
F_15 ( L_13 ,
V_1 , V_73 ) ;
V_6 = F_13 ( V_73 ) ;
goto V_97;
}
V_38 -> V_67 = V_67 ;
V_38 -> V_60 = V_73 ;
V_38 -> V_71 = V_71 ;
V_6 = 0 ;
goto V_94;
V_97:
F_26 ( V_38 -> V_76 ) ;
F_4 ( V_38 -> V_76 ) ;
V_96:
F_27 ( V_38 -> V_67 , V_38 -> V_60 - V_38 -> V_67 + 1 ) ;
F_34 ( & V_38 -> V_29 ) ;
F_12 ( & V_14 , V_38 -> V_21 , & V_39 , & V_39 ) ;
F_4 ( V_38 ) ;
V_94:
F_31 ( & V_28 ) ;
return V_6 ;
}
void
F_35 ( char * V_1 )
{
unsigned long V_39 ;
struct V_23 * V_38 ;
if ( ! V_69 )
return;
F_29 ( & V_28 ) ;
V_38 = F_7 ( V_1 ) ;
if ( V_38 == NULL ) {
F_36 ( L_14 , V_1 ) ;
goto V_94;
}
if ( F_37 ( & V_38 -> V_89 ) != 0 )
goto V_94;
F_26 ( V_38 -> V_76 ) ;
F_4 ( V_38 -> V_76 ) ;
F_27 ( V_38 -> V_67 , V_38 -> V_60 - V_38 -> V_67 + 1 ) ;
F_34 ( & V_38 -> V_29 ) ;
F_12 ( & V_14 , V_38 -> V_21 , & V_39 , & V_39 ) ;
F_4 ( V_38 ) ;
V_94:
F_31 ( & V_28 ) ;
}
void
F_38 ( char * V_1 )
{
struct V_23 * V_38 ;
char V_98 [ 160 ] ;
char V_99 [ 80 ] ;
int V_22 , V_100 ;
if ( ! V_69 )
return;
F_29 ( & V_28 ) ;
V_38 = F_7 ( V_1 ) ;
if ( V_38 == NULL ) {
F_36 ( L_15 , V_1 ) ;
goto V_74;
}
sprintf ( V_98 , L_16 , V_1 ) ;
for ( V_22 = 0 ; V_22 < V_38 -> V_56 ; V_22 ++ ) {
sprintf ( V_98 + strlen ( V_98 ) , L_17 ,
V_38 -> V_58 [ V_22 ] . V_59 >> V_63 ,
V_38 -> V_58 [ V_22 ] . V_60 >> V_63 ,
V_91 [ V_38 -> V_58 [ V_22 ] . V_59 & 0xff ] ) ;
}
sprintf ( V_99 , L_18 , V_1 ) ;
V_100 = 0 ;
F_39 ( V_98 , NULL , 0 , & V_100 ) ;
if ( V_100 ) {
F_36 ( L_19
L_20 , V_100 ) ;
goto V_74;
}
F_39 ( V_99 , NULL , 0 , & V_100 ) ;
if ( V_100 ) {
F_36 ( L_21
L_20 , V_100 ) ;
goto V_74;
}
V_74:
F_31 ( & V_28 ) ;
}
void F_40 ( int V_6 , char * V_101 )
{
switch ( V_6 ) {
case - V_36 :
F_36 ( L_22 , V_101 ) ;
break;
case - V_70 :
F_36 ( L_23
L_24 , V_101 ) ;
break;
case - V_37 :
F_36 ( L_25
L_26 , V_101 ) ;
break;
case - V_61 :
F_36 ( L_27
L_28 , V_101 ) ;
break;
case - V_102 :
F_36 ( L_29
L_30 , V_101 ) ;
break;
case - V_75 :
F_36 ( L_31
L_28 , V_101 ) ;
break;
case - V_92 :
F_36 ( L_32
L_10 , V_101 ) ;
break;
case - V_7 :
F_36 ( L_33
L_34 , V_101 ) ;
break;
case - V_103 :
F_36 ( L_35
L_36 , V_101 , V_104 ) ;
break;
default:
break;
}
}
