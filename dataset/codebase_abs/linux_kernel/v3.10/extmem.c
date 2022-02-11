static int
F_1 ( void )
{
#ifdef F_2
char * V_1 = F_3 ( 8 * sizeof( char ) , V_2 | V_3 ) ;
unsigned long V_4 , V_5 ;
int V_6 ;
if ( V_1 == NULL )
return - V_7 ;
V_4 = ( unsigned long ) V_1 ;
V_5 = V_8 ;
strcpy ( V_1 , L_1 ) ;
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
V_9 = V_10 ;
V_11 = V_12 ;
V_13 = V_14 ;
V_15 = V_8 ;
V_16 = V_17 ;
return 0 ;
}
#endif
V_9 = V_18 ;
V_11 = V_19 ;
V_13 = V_14 ;
V_15 = V_20 ;
V_16 = V_21 ;
return 0 ;
}
static void
F_5 ( char * V_1 , char * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if ( V_1 [ V_23 ] == '\0' )
break;
V_22 [ V_23 ] = toupper ( V_1 [ V_23 ] ) ;
} ;
for (; V_23 < 8 ; V_23 ++ )
V_22 [ V_23 ] = ' ' ;
F_6 ( V_22 , 8 ) ;
}
static struct V_24 *
F_7 ( char * V_1 )
{
char V_22 [ 9 ] ;
struct V_25 * V_26 ;
struct V_24 * V_27 , * V_28 = NULL ;
F_8 ( ! F_9 ( & V_29 ) ) ;
F_5 ( V_1 , V_22 ) ;
F_10 (l, &dcss_list) {
V_27 = F_11 ( V_26 , struct V_24 , V_30 ) ;
if ( memcmp ( V_27 -> V_22 , V_22 , 8 ) == 0 ) {
V_28 = V_27 ;
break;
}
}
return V_28 ;
}
static inline int
F_12 ( int * V_31 , void * V_32 ,
unsigned long * V_33 , unsigned long * V_34 )
{
unsigned long V_4 , V_5 ;
int V_6 ;
if ( V_35 == 0 ) {
V_6 = F_1 () ;
if ( V_6 < 0 )
return V_6 ;
V_35 = 1 ;
}
V_4 = ( unsigned long ) V_32 ;
V_5 = ( unsigned long ) * V_31 ;
#ifdef F_2
if ( * V_31 > V_21 )
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
#else
asm volatile(
" diag %0,%1,0x64\n"
" ipm %2\n"
" srl %2,28\n"
: "+d" (rx), "+d" (ry), "=d" (rc) : : "cc");
#endif
* V_33 = V_4 ;
* V_34 = V_5 ;
return V_6 ;
}
static inline int
F_13 ( int V_36 ) {
if ( V_36 == 44 )
return - V_37 ;
return - V_38 ;
}
static int
F_14 ( struct V_24 * V_39 )
{
unsigned long V_40 , V_41 ;
int V_42 , V_6 , V_23 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
V_46 = F_3 ( sizeof( * V_46 ) , V_2 | V_3 ) ;
V_44 = F_3 ( sizeof( * V_44 ) , V_2 | V_3 ) ;
if ( ( V_46 == NULL ) || ( V_44 == NULL ) ) {
V_6 = - V_7 ;
goto V_47;
}
V_46 -> V_48 = V_49 ;
V_46 -> V_50 = ( unsigned long ) V_44 ;
V_46 -> V_51 = sizeof( struct V_43 ) ;
memcpy ( V_46 -> V_52 , V_39 -> V_22 , 8 ) ;
V_42 = F_12 ( & V_16 , V_46 , & V_40 , & V_41 ) ;
if ( V_42 < 0 ) {
V_6 = V_42 ;
goto V_47;
}
if ( V_42 > 1 ) {
F_15 ( L_2 , V_41 ) ;
V_6 = F_13 ( V_41 ) ;
goto V_47;
}
#ifdef F_2
if ( V_16 == V_21 ) {
struct V_53 * V_54 ;
V_54 = F_16 ( sizeof( * V_54 ) , V_2 | V_3 ) ;
if ( V_54 == NULL ) {
V_6 = - V_7 ;
goto V_47;
}
memcpy ( V_54 , V_44 , sizeof( struct V_53 ) ) ;
V_44 -> V_55 = ( unsigned long ) V_54 -> V_55 ;
V_44 -> V_56 = ( unsigned long ) V_54 -> V_56 ;
V_44 -> V_57 = V_54 -> V_57 ;
V_44 -> V_58 = V_54 -> V_58 ;
if ( V_44 -> V_57 > 6 )
V_44 -> V_58 = 6 ;
for ( V_23 = 0 ; V_23 < V_44 -> V_58 ; V_23 ++ ) {
V_44 -> V_59 [ V_23 ] . V_60 =
( unsigned long ) V_54 -> V_59 [ V_23 ] . V_60 ;
V_44 -> V_59 [ V_23 ] . V_61 =
( unsigned long ) V_54 -> V_59 [ V_23 ] . V_61 ;
}
F_4 ( V_54 ) ;
}
#endif
if ( V_44 -> V_57 > 6 ) {
V_6 = - V_62 ;
goto V_47;
}
if ( V_44 -> V_57 == 1 ) {
V_39 -> V_63 = V_44 -> V_59 [ 0 ] . V_60 & 0xff ;
} else {
unsigned long V_60 = V_44 -> V_55 >> V_64 ;
for ( V_23 = 0 ; V_23 < V_44 -> V_57 ; V_23 ++ ) {
if ( ( ( V_44 -> V_59 [ V_23 ] . V_60 & 0xff ) != V_65 ) &&
( ( V_44 -> V_59 [ V_23 ] . V_60 & 0xff ) != V_66 ) ) {
V_6 = - V_62 ;
goto V_47;
}
if ( V_60 != V_44 -> V_59 [ V_23 ] . V_60 >> V_64 ) {
V_6 = - V_62 ;
goto V_47;
}
V_60 = ( V_44 -> V_59 [ V_23 ] . V_61 >> V_64 ) + 1 ;
}
V_39 -> V_63 = V_67 ;
}
V_39 -> V_68 = V_44 -> V_55 ;
V_39 -> V_61 = V_44 -> V_56 ;
memcpy ( V_39 -> V_59 , V_44 -> V_59 , 6 * sizeof( struct V_69 ) ) ;
V_39 -> V_57 = V_44 -> V_57 ;
V_6 = 0 ;
V_47:
F_4 ( V_46 ) ;
F_4 ( V_44 ) ;
return V_6 ;
}
int
F_17 ( char * V_1 )
{
int V_6 ;
struct V_24 V_39 ;
if ( ! V_70 )
return - V_71 ;
F_5 ( V_1 , V_39 . V_22 ) ;
V_6 = F_14 ( & V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_39 . V_63 ;
}
static int
F_18 ( struct V_24 * V_39 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
F_8 ( ! F_9 ( & V_29 ) ) ;
F_10 (l, &dcss_list) {
V_27 = F_11 ( V_26 , struct V_24 , V_30 ) ;
if ( ( V_27 -> V_68 >> 20 ) > ( V_39 -> V_61 >> 20 ) )
continue;
if ( ( V_27 -> V_61 >> 20 ) < ( V_39 -> V_68 >> 20 ) )
continue;
if ( V_39 == V_27 )
continue;
return 1 ;
}
return 0 ;
}
static int
F_19 ( char * V_1 , int V_72 , unsigned long * V_73 , unsigned long * V_61 )
{
unsigned long V_68 , V_74 , V_40 ;
struct V_24 * V_39 ;
int V_6 , V_42 ;
V_68 = V_74 = 0 ;
V_39 = F_3 ( sizeof( * V_39 ) , V_2 | V_3 ) ;
if ( V_39 == NULL ) {
V_6 = - V_7 ;
goto V_75;
}
F_5 ( V_1 , V_39 -> V_22 ) ;
V_6 = F_14 ( V_39 ) ;
if ( V_6 < 0 )
goto V_47;
if ( V_9 == V_10 ) {
if ( F_18 ( V_39 ) ) {
V_6 = - V_76 ;
goto V_47;
}
}
V_6 = F_20 ( V_39 -> V_68 , V_39 -> V_61 - V_39 -> V_68 + 1 ) ;
if ( V_6 )
goto V_47;
V_39 -> V_77 = F_16 ( sizeof( struct V_78 ) , V_2 ) ;
if ( V_39 -> V_77 == NULL ) {
V_6 = - V_7 ;
goto V_79;
}
V_39 -> V_77 -> V_80 = V_81 | V_82 ;
V_39 -> V_77 -> V_60 = V_39 -> V_68 ;
V_39 -> V_77 -> V_61 = V_39 -> V_61 ;
memcpy ( & V_39 -> V_83 , V_39 -> V_22 , 8 ) ;
F_21 ( V_39 -> V_83 , 8 ) ;
V_39 -> V_83 [ 8 ] = '\0' ;
strncat ( V_39 -> V_83 , L_3 , 7 ) ;
V_39 -> V_77 -> V_1 = V_39 -> V_83 ;
V_6 = V_39 -> V_63 ;
if ( V_6 == V_84 ||
( ( V_6 == V_85 || V_6 == V_86 ) && ! V_72 ) )
V_39 -> V_77 -> V_80 |= V_87 ;
if ( F_22 ( & V_88 , V_39 -> V_77 ) ) {
V_6 = - V_76 ;
F_4 ( V_39 -> V_77 ) ;
goto V_79;
}
if ( V_72 )
V_42 = F_12 ( & V_11 , V_39 -> V_22 ,
& V_68 , & V_74 ) ;
else
V_42 = F_12 ( & V_9 , V_39 -> V_22 ,
& V_68 , & V_74 ) ;
if ( V_42 < 0 ) {
F_12 ( & V_13 , V_39 -> V_22 ,
& V_40 , & V_40 ) ;
V_6 = V_42 ;
goto V_89;
}
if ( V_42 > 1 ) {
F_15 ( L_4 , V_1 ,
V_74 ) ;
V_6 = F_13 ( V_74 ) ;
F_12 ( & V_13 , V_39 -> V_22 ,
& V_40 , & V_40 ) ;
goto V_89;
}
V_39 -> V_68 = V_68 ;
V_39 -> V_61 = V_74 ;
V_39 -> V_72 = V_72 ;
F_23 ( & V_39 -> V_90 , 1 ) ;
F_24 ( & V_39 -> V_30 , & V_91 ) ;
* V_73 = V_39 -> V_68 ;
* V_61 = V_39 -> V_61 ;
if ( V_72 )
F_25 ( L_5
L_6 , V_1 , ( void * ) V_39 -> V_68 ,
( void * ) V_39 -> V_61 , V_92 [ V_39 -> V_63 ] ) ;
else {
F_25 ( L_7
L_8 , V_1 , ( void * ) V_39 -> V_68 ,
( void * ) V_39 -> V_61 , V_92 [ V_39 -> V_63 ] ) ;
}
goto V_75;
V_89:
F_26 ( V_39 -> V_77 ) ;
F_4 ( V_39 -> V_77 ) ;
V_79:
F_27 ( V_39 -> V_68 , V_39 -> V_61 - V_39 -> V_68 + 1 ) ;
V_47:
F_4 ( V_39 ) ;
V_75:
return V_6 ;
}
int
F_28 ( char * V_1 , int V_72 , unsigned long * V_73 ,
unsigned long * V_61 )
{
struct V_24 * V_39 ;
int V_6 ;
if ( ! V_70 )
return - V_71 ;
F_29 ( & V_29 ) ;
V_39 = F_7 ( V_1 ) ;
if ( V_39 == NULL )
V_6 = F_19 ( V_1 , V_72 , V_73 , V_61 ) ;
else {
if ( V_72 == V_39 -> V_72 ) {
F_30 ( & V_39 -> V_90 ) ;
* V_73 = V_39 -> V_68 ;
* V_61 = V_39 -> V_61 ;
V_6 = V_39 -> V_63 ;
} else {
* V_73 = * V_61 = 0 ;
V_6 = - V_93 ;
}
}
F_31 ( & V_29 ) ;
return V_6 ;
}
int
F_32 ( char * V_1 , int V_72 )
{
struct V_24 * V_39 ;
unsigned long V_68 , V_74 , V_40 ;
int V_6 , V_42 ;
V_68 = V_74 = 0 ;
F_29 ( & V_29 ) ;
V_39 = F_7 ( V_1 ) ;
if ( V_39 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
if ( V_72 == V_39 -> V_72 ) {
F_25 ( L_9
L_10 , V_1 ) ;
V_6 = 0 ;
goto V_95;
}
if ( F_33 ( & V_39 -> V_90 ) != 1 ) {
F_15 ( L_11 ,
V_1 ) ;
V_6 = - V_96 ;
goto V_95;
}
F_26 ( V_39 -> V_77 ) ;
if ( V_72 )
V_39 -> V_77 -> V_80 &= ~ V_87 ;
else
if ( V_39 -> V_63 == V_85 ||
V_39 -> V_63 == V_86 )
V_39 -> V_77 -> V_80 |= V_87 ;
if ( F_22 ( & V_88 , V_39 -> V_77 ) ) {
F_15 ( L_12
L_13 , V_1 ) ;
V_6 = - V_76 ;
F_4 ( V_39 -> V_77 ) ;
goto V_97;
}
F_12 ( & V_13 , V_39 -> V_22 , & V_40 , & V_40 ) ;
if ( V_72 )
V_42 = F_12 ( & V_11 , V_39 -> V_22 ,
& V_68 , & V_74 ) ;
else
V_42 = F_12 ( & V_9 , V_39 -> V_22 ,
& V_68 , & V_74 ) ;
if ( V_42 < 0 ) {
V_6 = V_42 ;
goto V_98;
}
if ( V_42 > 1 ) {
F_15 ( L_14 , V_1 ,
V_74 ) ;
V_6 = F_13 ( V_74 ) ;
goto V_98;
}
V_39 -> V_68 = V_68 ;
V_39 -> V_61 = V_74 ;
V_39 -> V_72 = V_72 ;
V_6 = 0 ;
goto V_95;
V_98:
F_26 ( V_39 -> V_77 ) ;
F_4 ( V_39 -> V_77 ) ;
V_97:
F_27 ( V_39 -> V_68 , V_39 -> V_61 - V_39 -> V_68 + 1 ) ;
F_34 ( & V_39 -> V_30 ) ;
F_12 ( & V_13 , V_39 -> V_22 , & V_40 , & V_40 ) ;
F_4 ( V_39 ) ;
V_95:
F_31 ( & V_29 ) ;
return V_6 ;
}
void
F_35 ( char * V_1 )
{
unsigned long V_40 ;
struct V_24 * V_39 ;
if ( ! V_70 )
return;
F_29 ( & V_29 ) ;
V_39 = F_7 ( V_1 ) ;
if ( V_39 == NULL ) {
F_36 ( L_15 , V_1 ) ;
goto V_95;
}
if ( F_37 ( & V_39 -> V_90 ) != 0 )
goto V_95;
F_26 ( V_39 -> V_77 ) ;
F_4 ( V_39 -> V_77 ) ;
F_27 ( V_39 -> V_68 , V_39 -> V_61 - V_39 -> V_68 + 1 ) ;
F_34 ( & V_39 -> V_30 ) ;
F_12 ( & V_13 , V_39 -> V_22 , & V_40 , & V_40 ) ;
F_4 ( V_39 ) ;
V_95:
F_31 ( & V_29 ) ;
}
void
F_38 ( char * V_1 )
{
struct V_24 * V_39 ;
char V_99 [ 160 ] ;
char V_100 [ 80 ] ;
int V_23 , V_101 ;
if ( ! V_70 )
return;
F_29 ( & V_29 ) ;
V_39 = F_7 ( V_1 ) ;
if ( V_39 == NULL ) {
F_36 ( L_16 , V_1 ) ;
goto V_75;
}
sprintf ( V_99 , L_17 , V_1 ) ;
for ( V_23 = 0 ; V_23 < V_39 -> V_57 ; V_23 ++ ) {
sprintf ( V_99 + strlen ( V_99 ) , L_18 ,
V_39 -> V_59 [ V_23 ] . V_60 >> V_64 ,
V_39 -> V_59 [ V_23 ] . V_61 >> V_64 ,
V_92 [ V_39 -> V_59 [ V_23 ] . V_60 & 0xff ] ) ;
}
sprintf ( V_100 , L_19 , V_1 ) ;
V_101 = 0 ;
F_39 ( V_99 , NULL , 0 , & V_101 ) ;
if ( V_101 ) {
F_36 ( L_20
L_21 , V_101 ) ;
goto V_75;
}
F_39 ( V_100 , NULL , 0 , & V_101 ) ;
if ( V_101 ) {
F_36 ( L_22
L_21 , V_101 ) ;
goto V_75;
}
V_75:
F_31 ( & V_29 ) ;
}
void F_40 ( int V_6 , char * V_102 )
{
switch ( V_6 ) {
case - V_37 :
F_36 ( L_23 , V_102 ) ;
break;
case - V_71 :
F_36 ( L_24
L_25 , V_102 ) ;
break;
case - V_38 :
F_36 ( L_26
L_27 , V_102 ) ;
break;
case - V_62 :
F_36 ( L_28
L_29 , V_102 ) ;
break;
case - V_103 :
F_36 ( L_30
L_31 , V_102 ) ;
break;
case - V_76 :
F_36 ( L_32
L_29 , V_102 ) ;
break;
case - V_93 :
F_36 ( L_33
L_10 , V_102 ) ;
break;
case - V_7 :
F_36 ( L_34
L_35 , V_102 ) ;
break;
case - V_104 :
F_36 ( L_36
L_37 , V_102 , V_105 ) ;
break;
default:
break;
}
}
