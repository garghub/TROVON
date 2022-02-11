static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
if ( ! F_2 ( V_5 -> V_12 ) ) {
F_3 ( 1 , L_1 ) ;
return 0 ;
}
V_10 = V_3 & ~ ( V_5 -> V_13 - 1 ) ;
if ( V_10 != V_5 -> V_10 ) {
F_3 ( 2 , L_2 ,
V_5 -> V_10 , V_10 ) ;
V_11 = F_4 ( V_5 -> V_12 , V_8 , V_10 ) ;
if ( V_11 != 0 )
return NULL ;
V_5 -> V_10 = V_10 ;
}
return V_5 -> V_14 + ( V_3 & ( V_5 -> V_13 - 1 ) ) ;
}
static T_2 F_5 ( struct V_1 * V_2 , unsigned long V_15 )
{
T_1 V_16 ;
T_2 V_17 = { { 0 } } ;
V_16 = F_1 ( V_2 , V_15 ) ;
if( ! V_16 )
return V_17 ;
V_17 . V_18 [ 0 ] = F_6 ( V_16 ) ;
F_3 ( 3 , L_3 , V_15 , V_16 , V_17 . V_18 [ 0 ] ) ;
return V_17 ;
}
static T_2 F_7 ( struct V_1 * V_2 , unsigned long V_15 )
{
T_1 V_16 ;
T_2 V_17 = { { 0 } } ;
V_16 = F_1 ( V_2 , V_15 ) ;
if( ! V_16 )
return V_17 ;
V_17 . V_18 [ 0 ] = F_8 ( V_16 ) ;
F_3 ( 3 , L_4 , V_15 , V_16 , V_17 . V_18 [ 0 ] ) ;
return V_17 ;
}
static void F_9 ( struct V_1 * V_2 , void * V_3 , unsigned long V_19 , T_3 V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
unsigned long V_13 = V_5 -> V_13 ;
F_3 ( 3 , L_5 , V_3 , V_19 , V_20 ) ;
while( V_20 ) {
int V_21 = V_13 - ( V_19 & ( V_13 - 1 ) ) ;
T_1 V_16 ;
if( V_21 > V_20 )
V_21 = V_20 ;
V_16 = F_1 ( V_2 , V_19 ) ;
if( ! V_16 )
return;
F_3 ( 4 , L_6 , V_16 , V_3 , V_21 ) ;
F_10 ( V_3 , V_16 , V_21 ) ;
V_20 -= V_21 ;
V_3 += V_21 ;
V_19 += V_21 ;
}
}
static void F_11 ( struct V_1 * V_2 , T_2 V_17 , unsigned long V_22 )
{
T_1 V_16 = F_1 ( V_2 , V_22 ) ;
if( ! V_16 )
return;
F_3 ( 3 , L_7 , V_22 , V_16 , V_17 . V_18 [ 0 ] ) ;
F_12 ( V_17 . V_18 [ 0 ] , V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_17 , unsigned long V_22 )
{
T_1 V_16 = F_1 ( V_2 , V_22 ) ;
if( ! V_16 )
return;
F_3 ( 3 , L_8 , V_22 , V_16 , V_17 . V_18 [ 0 ] ) ;
F_14 ( V_17 . V_18 [ 0 ] , V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned long V_3 , const void * V_19 , T_3 V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
unsigned long V_13 = V_5 -> V_13 ;
F_3 ( 3 , L_9 , V_3 , V_19 , V_20 ) ;
while( V_20 ) {
int V_23 = V_13 - ( V_3 & ( V_13 - 1 ) ) ;
T_1 V_16 ;
if( V_23 > V_20 )
V_23 = V_20 ;
V_16 = F_1 ( V_2 , V_3 ) ;
if( ! V_16 )
return;
F_3 ( 4 , L_6 , V_19 , V_16 , V_23 ) ;
F_16 ( V_16 , V_19 , V_23 ) ;
V_20 -= V_23 ;
V_3 += V_23 ;
V_19 += V_23 ;
}
}
static T_2 F_17 ( struct V_1 * V_2 , unsigned long V_15 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
T_2 V_17 = { { 0 } } ;
if( F_18 ( V_2 ) )
return V_17 ;
V_17 . V_18 [ 0 ] = F_6 ( V_14 + V_15 ) ;
F_3 ( 3 , L_3 ,
V_15 , V_14 + V_15 , V_17 . V_18 [ 0 ] ) ;
return V_17 ;
}
static T_2 F_19 ( struct V_1 * V_2 , unsigned long V_15 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
T_2 V_17 = { { 0 } } ;
if( F_18 ( V_2 ) )
return V_17 ;
V_17 . V_18 [ 0 ] = F_8 ( V_14 + V_15 ) ;
F_3 ( 3 , L_4 ,
V_15 , V_14 + V_15 , V_17 . V_18 [ 0 ] ) ;
return V_17 ;
}
static void F_20 ( struct V_1 * V_2 , void * V_3 , unsigned long V_19 , T_3 V_20 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( 3 , L_5 , V_3 , V_19 , V_20 ) ;
F_10 ( V_3 , V_14 + V_19 , V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_17 , unsigned long V_22 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( 3 , L_7 ,
V_22 , V_14 + V_22 , V_17 . V_18 [ 0 ] ) ;
F_12 ( V_17 . V_18 [ 0 ] , V_14 + V_22 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_17 , unsigned long V_22 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( 3 , L_8 ,
V_22 , V_14 + V_22 , V_17 . V_18 [ 0 ] ) ;
F_14 ( V_17 . V_18 [ 0 ] , V_14 + V_22 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned long V_3 , const void * V_19 , T_3 V_20 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( 3 , L_9 , V_3 , V_19 , V_20 ) ;
F_16 ( V_14 + V_3 , V_19 , V_20 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_24 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_25 * V_26 = V_5 -> V_12 ;
F_3 ( 2 , L_10 , V_5 , V_24 , V_5 -> V_27 ) ;
F_25 ( V_26 , V_24 ? V_5 -> V_27 : 0 ) ;
}
static void F_26 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
F_3 ( 3 , L_11 , V_26 ) ;
if ( V_26 -> V_7 [ 2 ] -> V_29 ) {
if( V_5 -> V_14 ) {
F_27 ( V_5 -> V_14 ) ;
V_5 -> V_14 = NULL ;
}
}
F_28 ( V_26 ) ;
}
static int F_29 ( struct V_25 * V_12 ,
T_4 * V_30 ,
void * V_31 )
{
T_5 V_32 ;
if ( ! F_30 ( V_30 , & V_32 ) ) {
T_6 * V_33 = & V_32 . V_34 ;
( void ) V_33 ;
F_3 ( 2 , L_12 ,
V_33 -> type , V_33 -> V_35 , V_33 -> V_10 , V_33 -> V_36 ) ;
}
return - V_37 ;
}
static int F_31 ( struct V_25 * V_12 ,
T_4 * V_30 ,
void * V_31 )
{
T_5 V_32 ;
int V_38 ;
if ( ! F_30 ( V_30 , & V_32 ) ) {
T_7 * V_33 = & V_32 . V_39 ;
for ( V_38 = 0 ; V_38 < V_33 -> V_40 ; V_38 ++ )
F_3 ( 2 , L_13 ,
V_33 -> V_41 [ V_38 ] . V_42 , V_33 -> V_41 [ V_38 ] . V_43 ) ;
}
return - V_37 ;
}
static int F_32 ( struct V_25 * V_12 ,
T_4 * V_30 ,
void * V_31 )
{
struct V_4 * V_5 = V_31 ;
T_5 V_32 ;
T_8 * V_33 = & V_32 . V_44 ;
int V_38 ;
if ( F_30 ( V_30 , & V_32 ) )
return - V_45 ;
F_3 ( 2 , L_14 ) ;
V_5 -> V_46 . V_47 = V_33 -> V_5 [ 0 ] . V_47 ;
for ( V_38 = 0 ; V_38 < V_33 -> V_48 ; V_38 ++ ) {
F_3 ( 2 , L_15 , V_38 , V_33 -> V_5 [ V_38 ] . type ) ;
F_3 ( 2 , L_16 , V_38 , V_33 -> V_5 [ V_38 ] . V_49 ) ;
F_3 ( 2 , L_17 , V_38 , V_33 -> V_5 [ V_38 ] . V_50 ) ;
F_3 ( 2 , L_18 , V_38 , V_33 -> V_5 [ V_38 ] . V_47 ) ;
}
return 0 ;
}
static int F_33 ( struct V_25 * V_12 ,
T_4 * V_30 ,
void * V_31 )
{
struct V_4 * V_5 = V_31 ;
T_5 V_32 ;
T_9 * V_33 = & V_32 . V_51 ;
int V_38 ;
if ( F_30 ( V_30 , & V_32 ) )
return - V_45 ;
V_5 -> V_46 . V_52 = V_33 -> V_53 [ 0 ] . V_54 ;
for ( V_38 = 0 ; V_38 < V_33 -> V_55 ; V_38 ++ ) {
F_3 ( 2 , L_19 , V_38 , V_33 -> V_53 [ V_38 ] . V_54 ) ;
F_3 ( 2 , L_20 , V_38 , V_33 -> V_53 [ V_38 ] . V_56 ) ;
F_3 ( 2 , L_21 , V_38 , V_33 -> V_53 [ V_38 ] . V_57 ) ;
F_3 ( 2 , L_22 , V_38 , V_33 -> V_53 [ V_38 ] . V_58 ) ;
F_3 ( 2 , L_23 , V_38 , V_33 -> V_53 [ V_38 ] . V_59 ) ;
F_3 ( 2 , L_24 , V_38 , V_33 -> V_53 [ V_38 ] . V_60 ) ;
}
return 0 ;
}
static void F_34 ( struct V_4 * V_5 , struct V_25 * V_12 , int * V_61 )
{
int V_38 ;
if ( V_12 -> V_62 [ 0 ] ) {
V_5 -> V_63 [ 0 ] = '\0' ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
if ( V_38 )
strcat ( V_5 -> V_63 , L_25 ) ;
if ( V_12 -> V_62 [ V_38 ] )
strcat ( V_5 -> V_63 , V_12 -> V_62 [ V_38 ] ) ;
}
F_3 ( 2 , L_26 , V_5 -> V_63 ) ;
}
#ifdef F_35
F_36 ( V_12 , V_64 , F_29 , NULL ) ;
F_36 ( V_12 , V_65 , F_31 , NULL ) ;
#endif
F_36 ( V_12 , V_66 , F_32 , V_5 ) ;
F_36 ( V_12 , V_67 , F_33 , V_5 ) ;
if( ! V_5 -> V_46 . V_47 )
V_5 -> V_46 . V_47 = V_68 ;
if( ! V_5 -> V_46 . V_52 )
V_5 -> V_46 . V_52 = 2 ;
if( V_69 ) {
V_5 -> V_46 . V_47 = V_69 << 20 ;
F_3 ( 2 , L_27 , V_69 ) ;
}
if( V_52 ) {
V_5 -> V_46 . V_52 = V_52 ;
F_3 ( 2 , L_28 , V_52 ) ;
}
V_5 -> V_46 . V_70 = V_5 -> V_63 ;
if( ! V_5 -> V_63 [ 0 ] ) {
strcpy ( V_5 -> V_63 , L_29 ) ;
* V_61 = 1 ;
}
F_3 ( 1 , L_30 ,
V_5 -> V_46 . V_47 ,
V_5 -> V_46 . V_52 << 3 , V_5 -> V_63 ) ;
}
static int F_37 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
struct V_71 * V_72 = NULL ;
int V_11 ;
int V_38 , V_73 = 0 ;
static char * V_74 [] = { L_31 , L_32 } ;
int V_61 = 0 ;
F_3 ( 3 , L_33 , V_26 ) ;
F_34 ( V_5 , V_26 , & V_61 ) ;
V_5 -> V_46 . V_75 = V_76 ;
V_5 -> V_46 . V_77 = F_9 ;
V_5 -> V_46 . V_78 = F_15 ;
if ( V_5 -> V_46 . V_52 == 1 ) {
V_5 -> V_46 . V_79 = F_5 ;
V_5 -> V_46 . V_80 = F_11 ;
} else {
V_5 -> V_46 . V_79 = F_7 ;
V_5 -> V_46 . V_80 = F_13 ;
}
if( V_81 == 1 )
V_5 -> V_46 . V_82 = F_24 ;
V_26 -> V_7 [ 2 ] -> V_83 |= V_84 | V_85 ;
V_26 -> V_7 [ 2 ] -> V_83 |= ( V_5 -> V_46 . V_52 == 1 ) ?
V_86 : V_87 ;
V_26 -> V_7 [ 2 ] -> V_88 = 0 ;
V_26 -> V_7 [ 2 ] -> V_29 = ( V_69 ) ? V_69 << 20 :
V_68 ;
V_5 -> V_13 = 0 ;
do {
int V_11 ;
F_3 ( 2 , L_34 ,
( unsigned long ) F_38 ( V_26 -> V_7 [ 2 ] ) >> 10 ,
V_89 ) ;
V_11 = F_39 ( V_26 , V_26 -> V_7 [ 2 ] , V_89 ) ;
F_3 ( 2 , L_35 , V_11 , V_5 -> V_13 ) ;
if( V_11 ) {
V_73 ++ ;
V_26 -> V_7 [ 2 ] -> V_88 = 0 ;
V_26 -> V_7 [ 2 ] -> V_29 = ( V_69 ) ?
V_69 << 20 : V_68 ;
V_26 -> V_7 [ 2 ] -> V_29 >>= V_73 ;
} else {
F_3 ( 2 , L_36 , ( unsigned long )
F_38 ( V_26 -> V_7 [ 2 ] ) >> 10 ) ;
V_5 -> V_13 = F_38 ( V_26 -> V_7 [ 2 ] ) ;
break;
}
} while ( V_26 -> V_7 [ 2 ] -> V_29 >= 0x1000 );
F_3 ( 2 , L_37 , V_5 -> V_13 ) ;
if( ! V_5 -> V_13 ) {
F_40 ( & V_5 -> V_12 -> V_5 , L_38 ) ;
F_26 ( V_26 ) ;
return - V_90 ;
}
F_3 ( 1 , L_39 , V_5 -> V_13 >> 10 ) ;
V_5 -> V_14 = F_41 ( V_26 -> V_7 [ 2 ] -> V_88 ,
F_38 ( V_26 -> V_7 [ 2 ] ) ) ;
if( ! V_5 -> V_14 ) {
F_40 ( & V_5 -> V_12 -> V_5 , L_40 ,
V_26 -> V_7 [ 2 ] ) ;
F_26 ( V_26 ) ;
return - V_90 ;
}
F_3 ( 1 , L_41 ,
V_5 , V_26 -> V_7 [ 2 ] , V_5 -> V_14 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_46 . V_6 = ( unsigned long ) V_5 ;
V_5 -> V_46 . V_9 = ( unsigned long ) V_26 -> V_7 [ 2 ] ;
V_5 -> V_27 = ( V_27 ) ? V_27 : V_26 -> V_91 -> V_91 . V_92 ;
if( V_81 == 2 ) {
V_26 -> V_27 = V_5 -> V_27 ;
} else {
V_26 -> V_27 = 0 ;
}
V_26 -> V_93 = 0 ;
F_3 ( 2 , L_42 ) ;
V_11 = F_42 ( V_26 ) ;
if ( V_11 != 0 ) {
if ( V_5 -> V_14 ) {
F_27 ( V_5 -> V_14 ) ;
V_5 -> V_14 = NULL ;
}
return - V_90 ;
}
if( V_94 == 1 ) {
V_72 = F_43 ( L_43 , & V_5 -> V_46 ) ;
} else if( V_94 == 2 ) {
V_72 = F_43 ( L_44 , & V_5 -> V_46 ) ;
} else {
for( V_38 = 0 ; V_38 < F_44 ( V_74 ) ; V_38 ++ ) {
F_3 ( 1 , L_45 , V_74 [ V_38 ] ) ;
V_72 = F_43 ( V_74 [ V_38 ] , & V_5 -> V_46 ) ;
if( V_72 )
break;
F_3 ( 1 , L_46 , V_74 [ V_38 ] ) ;
}
}
if( ! V_72 ) {
F_3 ( 1 , L_47 ) ;
F_26 ( V_26 ) ;
return - V_90 ;
}
V_5 -> V_71 = V_72 ;
V_72 -> V_95 = V_96 ;
if( V_61 ) {
int V_47 = 0 ;
char V_97 = ' ' ;
if( V_72 -> V_47 < 1048576 ) {
V_47 = V_72 -> V_47 >> 10 ;
V_97 = 'K' ;
} else {
V_47 = V_72 -> V_47 >> 20 ;
V_97 = 'M' ;
}
snprintf ( V_5 -> V_63 , sizeof( V_5 -> V_63 ) , L_48 , V_47 , V_97 , L_29 ) ;
}
if( V_72 -> V_47 <= V_5 -> V_13 ) {
F_3 ( 1 , L_49 ) ;
V_5 -> V_46 . V_9 = ( unsigned long ) V_5 -> V_14 ;
if ( V_5 -> V_46 . V_52 == 1 ) {
V_5 -> V_46 . V_79 = F_17 ;
V_5 -> V_46 . V_80 = F_21 ;
} else {
V_5 -> V_46 . V_79 = F_19 ;
V_5 -> V_46 . V_80 = F_22 ;
}
V_5 -> V_46 . V_77 = F_20 ;
V_5 -> V_46 . V_78 = F_23 ;
}
if ( F_45 ( V_72 , NULL , 0 ) ) {
F_46 ( V_72 ) ;
V_5 -> V_71 = NULL ;
F_40 ( & V_5 -> V_12 -> V_5 ,
L_50 ) ;
F_26 ( V_26 ) ;
return - V_90 ;
}
F_47 ( & V_5 -> V_12 -> V_5 , L_51 , V_72 -> V_98 , V_72 -> V_70 ) ;
return 0 ;
}
static int F_48 ( struct V_25 * V_5 )
{
F_3 ( 2 , L_52 ) ;
return 0 ;
}
static int F_49 ( struct V_25 * V_5 )
{
F_3 ( 2 , L_53 ) ;
return 0 ;
}
static void F_50 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
F_3 ( 3 , L_33 , V_26 ) ;
if( V_5 -> V_71 ) {
F_51 ( V_5 -> V_71 ) ;
F_47 ( & V_5 -> V_12 -> V_5 , L_54 ,
V_5 -> V_71 -> V_98 ) ;
F_46 ( V_5 -> V_71 ) ;
}
F_26 ( V_26 ) ;
}
static int F_52 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
V_5 = F_53 ( sizeof( * V_5 ) , V_99 ) ;
if ( ! V_5 ) return - V_100 ;
F_3 ( 1 , L_55 , V_5 ) ;
V_5 -> V_12 = V_26 ;
V_26 -> V_28 = V_5 ;
return F_37 ( V_26 ) ;
}
static int T_10 F_54 ( void )
{
if( V_52 && V_52 != 1 && V_52 != 2 ) {
V_43 ( L_56 , V_52 ) ;
V_52 = 2 ;
}
if( V_69 && ( V_69 < 1 || V_69 > 64 ) ) {
V_43 ( L_57 , V_69 ) ;
V_69 = 0 ;
}
if( V_94 && V_94 != 1 && V_94 != 2 ) {
V_43 ( L_58 , V_94 ) ;
V_94 = 0 ;
}
return F_55 ( & V_101 ) ;
}
static void T_11 F_56 ( void )
{
F_3 ( 1 , V_102 L_59 ) ;
F_57 ( & V_101 ) ;
}
