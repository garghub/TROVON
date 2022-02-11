static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
if ( ! F_2 ( V_5 -> V_12 ) ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_10 = V_3 & ~ ( V_5 -> V_13 - 1 ) ;
if ( V_10 != V_5 -> V_10 ) {
F_3 ( L_2 ,
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
F_3 ( L_3 , V_15 , V_16 , V_17 . V_18 [ 0 ] ) ;
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
F_3 ( L_4 , V_15 , V_16 , V_17 . V_18 [ 0 ] ) ;
return V_17 ;
}
static void F_9 ( struct V_1 * V_2 , void * V_3 , unsigned long V_19 , T_3 V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
unsigned long V_13 = V_5 -> V_13 ;
F_3 ( L_5 , V_3 , V_19 , V_20 ) ;
while( V_20 ) {
int V_21 = V_13 - ( V_19 & ( V_13 - 1 ) ) ;
T_1 V_16 ;
if( V_21 > V_20 )
V_21 = V_20 ;
V_16 = F_1 ( V_2 , V_19 ) ;
if( ! V_16 )
return;
F_3 ( L_6 , V_16 , V_3 , V_21 ) ;
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
F_3 ( L_7 , V_22 , V_16 , V_17 . V_18 [ 0 ] ) ;
F_12 ( V_17 . V_18 [ 0 ] , V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_17 , unsigned long V_22 )
{
T_1 V_16 = F_1 ( V_2 , V_22 ) ;
if( ! V_16 )
return;
F_3 ( L_8 , V_22 , V_16 , V_17 . V_18 [ 0 ] ) ;
F_14 ( V_17 . V_18 [ 0 ] , V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned long V_3 , const void * V_19 , T_3 V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
unsigned long V_13 = V_5 -> V_13 ;
F_3 ( L_9 , V_3 , V_19 , V_20 ) ;
while( V_20 ) {
int V_23 = V_13 - ( V_3 & ( V_13 - 1 ) ) ;
T_1 V_16 ;
if( V_23 > V_20 )
V_23 = V_20 ;
V_16 = F_1 ( V_2 , V_3 ) ;
if( ! V_16 )
return;
F_3 ( L_6 , V_19 , V_16 , V_23 ) ;
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
F_3 ( L_3 ,
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
F_3 ( L_4 ,
V_15 , V_14 + V_15 , V_17 . V_18 [ 0 ] ) ;
return V_17 ;
}
static void F_20 ( struct V_1 * V_2 , void * V_3 , unsigned long V_19 , T_3 V_20 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( L_5 , V_3 , V_19 , V_20 ) ;
F_10 ( V_3 , V_14 + V_19 , V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_17 , unsigned long V_22 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( L_7 ,
V_22 , V_14 + V_22 , V_17 . V_18 [ 0 ] ) ;
F_12 ( V_17 . V_18 [ 0 ] , V_14 + V_22 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_17 , unsigned long V_22 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( L_8 ,
V_22 , V_14 + V_22 , V_17 . V_18 [ 0 ] ) ;
F_14 ( V_17 . V_18 [ 0 ] , V_14 + V_22 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned long V_3 , const void * V_19 , T_3 V_20 )
{
T_1 V_14 = ( T_1 ) V_2 -> V_9 ;
if( F_18 ( V_2 ) )
return;
F_3 ( L_9 , V_3 , V_19 , V_20 ) ;
F_16 ( V_14 + V_3 , V_19 , V_20 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_24 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_25 * V_26 = V_5 -> V_12 ;
unsigned long V_27 ;
F_3 ( L_10 , V_5 , V_24 , V_5 -> V_28 ) ;
F_25 ( & V_29 , V_27 ) ;
if ( V_24 ) {
if ( ++ V_30 == 1 )
F_26 ( V_26 , V_5 -> V_28 ) ;
} else {
if ( -- V_30 == 0 )
F_26 ( V_26 , 0 ) ;
}
F_27 ( & V_29 , V_27 ) ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_31 ;
F_3 ( L_11 , V_26 ) ;
if ( V_26 -> V_7 [ 2 ] -> V_32 ) {
if( V_5 -> V_14 ) {
F_29 ( V_5 -> V_14 ) ;
V_5 -> V_14 = NULL ;
}
}
F_30 ( V_26 ) ;
}
static int F_31 ( struct V_25 * V_12 ,
T_4 * V_33 ,
void * V_34 )
{
T_5 V_35 ;
if ( ! F_32 ( V_33 , & V_35 ) ) {
T_6 * V_36 = & V_35 . V_37 ;
( void ) V_36 ;
F_3 ( L_12 ,
V_36 -> type , V_36 -> V_38 , V_36 -> V_10 , V_36 -> V_39 ) ;
}
return - V_40 ;
}
static int F_33 ( struct V_25 * V_12 ,
T_4 * V_33 ,
void * V_34 )
{
T_5 V_35 ;
int V_41 ;
if ( ! F_32 ( V_33 , & V_35 ) ) {
T_7 * V_36 = & V_35 . V_42 ;
for ( V_41 = 0 ; V_41 < V_36 -> V_43 ; V_41 ++ )
F_3 ( L_13 ,
V_36 -> V_44 [ V_41 ] . V_45 , V_36 -> V_44 [ V_41 ] . V_46 ) ;
}
return - V_40 ;
}
static int F_34 ( struct V_25 * V_12 ,
T_4 * V_33 ,
void * V_34 )
{
struct V_4 * V_5 = V_34 ;
T_5 V_35 ;
T_8 * V_36 = & V_35 . V_47 ;
int V_41 ;
if ( F_32 ( V_33 , & V_35 ) )
return - V_48 ;
F_3 ( L_14 ) ;
V_5 -> V_49 . V_50 = V_36 -> V_5 [ 0 ] . V_50 ;
for ( V_41 = 0 ; V_41 < V_36 -> V_51 ; V_41 ++ ) {
F_3 ( L_15 , V_41 , V_36 -> V_5 [ V_41 ] . type ) ;
F_3 ( L_16 , V_41 , V_36 -> V_5 [ V_41 ] . V_52 ) ;
F_3 ( L_17 , V_41 , V_36 -> V_5 [ V_41 ] . V_53 ) ;
F_3 ( L_18 , V_41 , V_36 -> V_5 [ V_41 ] . V_50 ) ;
}
return 0 ;
}
static int F_35 ( struct V_25 * V_12 ,
T_4 * V_33 ,
void * V_34 )
{
struct V_4 * V_5 = V_34 ;
T_5 V_35 ;
T_9 * V_36 = & V_35 . V_54 ;
int V_41 ;
if ( F_32 ( V_33 , & V_35 ) )
return - V_48 ;
V_5 -> V_49 . V_55 = V_36 -> V_56 [ 0 ] . V_57 ;
for ( V_41 = 0 ; V_41 < V_36 -> V_58 ; V_41 ++ ) {
F_3 ( L_19 , V_41 , V_36 -> V_56 [ V_41 ] . V_57 ) ;
F_3 ( L_20 , V_41 , V_36 -> V_56 [ V_41 ] . V_59 ) ;
F_3 ( L_21 , V_41 , V_36 -> V_56 [ V_41 ] . V_60 ) ;
F_3 ( L_22 , V_41 , V_36 -> V_56 [ V_41 ] . V_61 ) ;
F_3 ( L_23 , V_41 , V_36 -> V_56 [ V_41 ] . V_62 ) ;
F_3 ( L_24 , V_41 , V_36 -> V_56 [ V_41 ] . V_63 ) ;
}
return 0 ;
}
static void F_36 ( struct V_4 * V_5 , struct V_25 * V_12 , int * V_64 )
{
int V_41 ;
if ( V_12 -> V_65 [ 0 ] ) {
V_5 -> V_66 [ 0 ] = '\0' ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
if ( V_41 )
strcat ( V_5 -> V_66 , L_25 ) ;
if ( V_12 -> V_65 [ V_41 ] )
strcat ( V_5 -> V_66 , V_12 -> V_65 [ V_41 ] ) ;
}
F_3 ( L_26 , V_5 -> V_66 ) ;
}
F_37 ( V_12 , V_67 , F_31 , NULL ) ;
F_37 ( V_12 , V_68 , F_33 , NULL ) ;
F_37 ( V_12 , V_69 , F_34 , V_5 ) ;
F_37 ( V_12 , V_70 , F_35 , V_5 ) ;
if( ! V_5 -> V_49 . V_50 )
V_5 -> V_49 . V_50 = V_71 ;
if( ! V_5 -> V_49 . V_55 )
V_5 -> V_49 . V_55 = 2 ;
if( V_72 ) {
V_5 -> V_49 . V_50 = V_72 << 20 ;
F_3 ( L_27 , V_72 ) ;
}
if( V_55 ) {
V_5 -> V_49 . V_55 = V_55 ;
F_3 ( L_28 , V_55 ) ;
}
V_5 -> V_49 . V_73 = V_5 -> V_66 ;
if( ! V_5 -> V_66 [ 0 ] ) {
strcpy ( V_5 -> V_66 , L_29 ) ;
* V_64 = 1 ;
}
F_3 ( L_30 ,
V_5 -> V_49 . V_50 ,
V_5 -> V_49 . V_55 << 3 , V_5 -> V_66 ) ;
}
static int F_38 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_31 ;
struct V_74 * V_75 = NULL ;
int V_11 ;
int V_41 , V_76 = 0 ;
static char * V_77 [] = { L_31 , L_32 } ;
int V_64 = 0 ;
F_3 ( L_33 , V_26 ) ;
F_36 ( V_5 , V_26 , & V_64 ) ;
V_5 -> V_49 . V_78 = V_79 ;
V_5 -> V_49 . V_80 = F_9 ;
V_5 -> V_49 . V_81 = F_15 ;
if ( V_5 -> V_49 . V_55 == 1 ) {
V_5 -> V_49 . V_82 = F_5 ;
V_5 -> V_49 . V_83 = F_11 ;
} else {
V_5 -> V_49 . V_82 = F_7 ;
V_5 -> V_49 . V_83 = F_13 ;
}
if( V_84 == 1 )
V_5 -> V_49 . V_85 = F_24 ;
V_26 -> V_7 [ 2 ] -> V_27 |= V_86 | V_87 ;
V_26 -> V_7 [ 2 ] -> V_27 |= ( V_5 -> V_49 . V_55 == 1 ) ?
V_88 : V_89 ;
V_26 -> V_7 [ 2 ] -> V_90 = 0 ;
V_26 -> V_7 [ 2 ] -> V_32 = ( V_72 ) ? V_72 << 20 :
V_71 ;
V_5 -> V_13 = 0 ;
do {
int V_11 ;
F_3 ( L_34 ,
( unsigned long ) F_39 ( V_26 -> V_7 [ 2 ] ) >> 10 ,
V_91 ) ;
V_11 = F_40 ( V_26 , V_26 -> V_7 [ 2 ] , V_91 ) ;
F_3 ( L_35 , V_11 , V_5 -> V_13 ) ;
if( V_11 ) {
V_76 ++ ;
V_26 -> V_7 [ 2 ] -> V_90 = 0 ;
V_26 -> V_7 [ 2 ] -> V_32 = ( V_72 ) ?
V_72 << 20 : V_71 ;
V_26 -> V_7 [ 2 ] -> V_32 >>= V_76 ;
} else {
F_3 ( L_36 , ( unsigned long )
F_39 ( V_26 -> V_7 [ 2 ] ) >> 10 ) ;
V_5 -> V_13 = F_39 ( V_26 -> V_7 [ 2 ] ) ;
break;
}
} while ( V_26 -> V_7 [ 2 ] -> V_32 >= 0x1000 );
F_3 ( L_37 , V_5 -> V_13 ) ;
if( ! V_5 -> V_13 ) {
F_41 ( & V_5 -> V_12 -> V_5 , L_38 ) ;
F_28 ( V_26 ) ;
return - V_92 ;
}
F_3 ( L_39 , V_5 -> V_13 >> 10 ) ;
V_5 -> V_14 = F_42 ( V_26 -> V_7 [ 2 ] -> V_90 ,
F_39 ( V_26 -> V_7 [ 2 ] ) ) ;
if( ! V_5 -> V_14 ) {
F_41 ( & V_5 -> V_12 -> V_5 , L_40 ,
V_26 -> V_7 [ 2 ] ) ;
F_28 ( V_26 ) ;
return - V_92 ;
}
F_3 ( L_41 ,
V_5 , V_26 -> V_7 [ 2 ] , V_5 -> V_14 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_49 . V_6 = ( unsigned long ) V_5 ;
V_5 -> V_49 . V_9 = ( unsigned long ) V_26 -> V_7 [ 2 ] ;
V_5 -> V_28 = ( V_28 ) ? V_28 : V_26 -> V_93 -> V_93 . V_94 ;
if( V_84 == 2 ) {
V_26 -> V_28 = V_5 -> V_28 ;
} else {
V_26 -> V_28 = 0 ;
}
V_26 -> V_95 = 0 ;
F_3 ( L_42 ) ;
V_11 = F_43 ( V_26 ) ;
if ( V_11 != 0 ) {
if ( V_5 -> V_14 ) {
F_29 ( V_5 -> V_14 ) ;
V_5 -> V_14 = NULL ;
}
return - V_92 ;
}
if( V_96 == 1 ) {
V_75 = F_44 ( L_43 , & V_5 -> V_49 ) ;
} else if( V_96 == 2 ) {
V_75 = F_44 ( L_44 , & V_5 -> V_49 ) ;
} else {
for( V_41 = 0 ; V_41 < F_45 ( V_77 ) ; V_41 ++ ) {
F_3 ( L_45 , V_77 [ V_41 ] ) ;
V_75 = F_44 ( V_77 [ V_41 ] , & V_5 -> V_49 ) ;
if( V_75 )
break;
F_3 ( L_46 , V_77 [ V_41 ] ) ;
}
}
if( ! V_75 ) {
F_3 ( L_47 ) ;
F_28 ( V_26 ) ;
return - V_92 ;
}
V_5 -> V_74 = V_75 ;
V_75 -> V_97 = V_98 ;
if( V_64 ) {
int V_50 = 0 ;
char V_99 = ' ' ;
if( V_75 -> V_50 < 1048576 ) {
V_50 = V_75 -> V_50 >> 10 ;
V_99 = 'K' ;
} else {
V_50 = V_75 -> V_50 >> 20 ;
V_99 = 'M' ;
}
snprintf ( V_5 -> V_66 , sizeof( V_5 -> V_66 ) , L_48 , V_50 , V_99 , L_29 ) ;
}
if( V_75 -> V_50 <= V_5 -> V_13 ) {
F_3 ( L_49 ) ;
V_5 -> V_49 . V_9 = ( unsigned long ) V_5 -> V_14 ;
if ( V_5 -> V_49 . V_55 == 1 ) {
V_5 -> V_49 . V_82 = F_17 ;
V_5 -> V_49 . V_83 = F_21 ;
} else {
V_5 -> V_49 . V_82 = F_19 ;
V_5 -> V_49 . V_83 = F_22 ;
}
V_5 -> V_49 . V_80 = F_20 ;
V_5 -> V_49 . V_81 = F_23 ;
}
if ( F_46 ( V_75 , NULL , 0 ) ) {
F_47 ( V_75 ) ;
V_5 -> V_74 = NULL ;
F_41 ( & V_5 -> V_12 -> V_5 ,
L_50 ) ;
F_28 ( V_26 ) ;
return - V_92 ;
}
F_48 ( & V_5 -> V_12 -> V_5 , L_51 , V_75 -> V_100 , V_75 -> V_73 ) ;
return 0 ;
}
static int F_49 ( struct V_25 * V_5 )
{
F_3 ( L_52 ) ;
return 0 ;
}
static int F_50 ( struct V_25 * V_5 )
{
F_3 ( L_53 ) ;
return 0 ;
}
static void F_51 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_31 ;
F_3 ( L_33 , V_26 ) ;
if( V_5 -> V_74 ) {
F_52 ( V_5 -> V_74 ) ;
F_48 ( & V_5 -> V_12 -> V_5 , L_54 ,
V_5 -> V_74 -> V_100 ) ;
F_47 ( V_5 -> V_74 ) ;
}
F_28 ( V_26 ) ;
}
static int F_53 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
V_5 = F_54 ( sizeof( * V_5 ) , V_101 ) ;
if ( ! V_5 ) return - V_102 ;
F_3 ( L_55 , V_5 ) ;
V_5 -> V_12 = V_26 ;
V_26 -> V_31 = V_5 ;
return F_38 ( V_26 ) ;
}
static int T_10 F_55 ( void )
{
if( V_55 && V_55 != 1 && V_55 != 2 ) {
V_46 ( L_56 , V_55 ) ;
V_55 = 2 ;
}
if( V_72 && ( V_72 < 1 || V_72 > 64 ) ) {
V_46 ( L_57 , V_72 ) ;
V_72 = 0 ;
}
if( V_96 && V_96 != 1 && V_96 != 2 ) {
V_46 ( L_58 , V_96 ) ;
V_96 = 0 ;
}
return F_56 ( & V_103 ) ;
}
static void T_11 F_57 ( void )
{
F_3 ( V_104 L_59 ) ;
F_58 ( & V_103 ) ;
}
