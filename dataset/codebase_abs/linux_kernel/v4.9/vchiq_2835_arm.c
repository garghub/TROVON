int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 * V_8 ;
struct V_9 * V_10 ;
void * V_11 ;
T_3 V_12 ;
T_4 V_13 ;
int V_14 , V_15 ;
int V_16 , V_17 , V_18 ;
V_19 = F_3 ( V_5 , ( void * ) 0 ) ;
( void ) F_4 ( V_5 -> V_20 , L_1 ,
& V_21 ) ;
V_22 = 2 * V_21 ;
V_14 = F_5 ( V_23 * V_24 ) ;
V_15 = F_5 ( V_22 * V_25 ) ;
V_11 = F_6 ( V_5 , V_14 + V_15 ,
& V_12 , V_26 ) ;
if ( ! V_11 ) {
F_7 ( V_5 , L_2 ) ;
return - V_27 ;
}
F_8 ( ( ( int ) V_11 & ( V_28 - 1 ) ) != 0 ) ;
V_8 = F_9 ( V_11 , V_14 ) ;
if ( ! V_8 )
return - V_29 ;
V_8 -> V_30 [ V_31 ] =
( int ) V_12 + V_14 ;
V_8 -> V_30 [ V_32 ] =
V_25 ;
V_33 = ( char * ) V_11 + V_14 ;
V_14 += V_15 ;
V_34 = V_33 ;
for ( V_18 = 0 ; V_18 < ( V_25 - 1 ) ; V_18 ++ ) {
* ( char * * ) & V_33 [ V_18 * V_22 ] =
& V_33 [ ( V_18 + 1 ) * V_22 ] ;
}
* ( char * * ) & V_33 [ V_18 * V_22 ] = NULL ;
F_10 ( & V_35 , V_25 ) ;
if ( F_11 ( V_3 , V_8 , 0 ) != V_36 )
return - V_29 ;
V_10 = F_12 ( V_2 , V_37 , 0 ) ;
V_38 = F_13 ( & V_2 -> V_5 , V_10 ) ;
if ( F_14 ( V_38 ) )
return F_15 ( V_38 ) ;
V_17 = F_16 ( V_2 , 0 ) ;
if ( V_17 <= 0 ) {
F_7 ( V_5 , L_3 ) ;
return V_17 ;
}
V_16 = F_17 ( V_5 , V_17 , V_39 , V_40 ,
L_4 , V_3 ) ;
if ( V_16 ) {
F_7 ( V_5 , L_5 , V_17 ) ;
return V_16 ;
}
V_13 = V_12 ;
V_16 = F_18 ( V_7 , V_41 ,
& V_13 , sizeof( V_13 ) ) ;
if ( V_16 || V_13 ) {
F_7 ( V_5 , L_6 ) ;
return V_16 ? : - V_42 ;
}
F_19 ( V_43 ,
L_7 ,
( unsigned int ) V_8 , & V_12 ) ;
F_20 () ;
return 0 ;
}
T_5
F_21 ( T_1 * V_3 )
{
T_5 V_44 = V_36 ;
V_3 -> V_45 = F_22 ( sizeof( V_46 ) , V_26 ) ;
( ( V_46 * ) V_3 -> V_45 ) -> V_47 = 1 ;
V_44 = F_23 ( V_3 , & ( ( V_46 * ) V_3 -> V_45 ) -> V_48 ) ;
if( V_44 != V_36 )
{
( ( V_46 * ) V_3 -> V_45 ) -> V_47 = 0 ;
}
return V_44 ;
}
T_6 *
F_24 ( T_1 * V_3 )
{
if( ! ( ( V_46 * ) V_3 -> V_45 ) -> V_47 )
{
F_25 () ;
}
return & ( ( V_46 * ) V_3 -> V_45 ) -> V_48 ;
}
void
F_26 ( T_7 * V_49 )
{
F_27 () ;
V_49 -> V_50 = 1 ;
F_28 () ;
if ( V_49 -> V_51 )
F_29 ( 0 , V_38 + V_52 ) ;
}
int
F_30 ( void * V_53 , const void * V_54 , int V_55 )
{
if ( ( V_56 ) V_54 < V_57 ) {
return F_31 ( V_53 , V_54 , V_55 ) ;
} else {
memcpy ( V_53 , V_54 , V_55 ) ;
return 0 ;
}
}
T_5
F_32 ( T_8 * V_58 , T_9 V_59 ,
void * V_60 , int V_55 , int V_61 )
{
T_10 * V_62 ;
int V_63 ;
F_8 ( V_59 != V_64 ) ;
V_63 = F_33 ( ( char V_65 * ) V_60 , V_55 ,
( V_61 == V_66 )
? V_67
: V_68 ,
V_69 ,
& V_62 ) ;
if ( V_63 != 0 )
return V_70 ;
V_58 -> V_71 = V_59 ;
V_58 -> V_72 = F_34 ( V_62 ) ;
V_58 -> V_73 = V_62 ;
return V_36 ;
}
void
F_35 ( T_8 * V_58 )
{
if ( V_58 && V_58 -> V_73 && V_58 -> V_74 )
F_36 ( ( T_10 * ) V_58 -> V_73 , V_58 -> V_74 ) ;
}
void
F_37 ( T_8 * V_58 )
{
F_25 () ;
}
void
F_38 ( void * V_75 )
{
char V_76 [ 80 ] ;
int V_77 ;
V_77 = snprintf ( V_76 , sizeof( V_76 ) ,
L_8 ) ;
F_39 ( V_75 , V_76 , V_77 + 1 ) ;
}
T_5
F_40 ( T_1 * V_3 )
{
return V_70 ;
}
T_5
F_41 ( T_1 * V_3 )
{
return V_36 ;
}
void
F_42 ( T_1 * V_3 )
{
}
void
F_43 ( T_1 * V_3 )
{
}
int
F_44 ( T_1 * V_3 )
{
return 1 ;
}
int
F_45 ( void )
{
return 0 ;
}
void
F_46 ( T_1 * V_3 )
{
F_19 ( V_43 , L_9 ) ;
}
void
F_47 ( T_1 * V_3 )
{
( void ) V_3 ;
}
static T_11
V_39 ( int V_17 , void * V_78 )
{
T_1 * V_3 = V_78 ;
T_11 V_63 = V_79 ;
unsigned int V_44 ;
V_44 = F_48 ( V_38 + V_80 ) ;
if ( V_44 & 0x4 ) {
F_49 ( V_3 ) ;
V_63 = V_81 ;
}
return V_63 ;
}
static int
F_33 ( char V_65 * V_76 , T_12 V_82 , unsigned short type ,
struct V_83 * V_84 , T_10 * * V_85 )
{
T_10 * V_62 ;
struct V_86 * * V_87 ;
unsigned long * V_88 ;
unsigned int V_89 , V_60 , V_18 ;
char * V_90 , * V_91 , * V_92 ;
int V_93 , V_94 , V_95 ;
unsigned long * V_96 ;
V_60 = ( unsigned int ) V_76 & ( V_28 - 1 ) ;
V_89 = ( V_82 + V_60 + V_28 - 1 ) / V_28 ;
* V_85 = NULL ;
V_62 = F_50 ( sizeof( T_10 ) +
( V_89 * sizeof( unsigned long ) ) +
sizeof( unsigned long ) +
( V_89 * sizeof( V_87 [ 0 ] ) ) ,
V_26 ) ;
F_51 ( V_43 ,
L_10 , ( unsigned int ) V_62 ) ;
if ( ! V_62 )
return - V_27 ;
V_88 = V_62 -> V_88 ;
V_96 = ( unsigned long * ) ( V_88 + V_89 ) ;
V_87 = (struct V_86 * * ) ( V_88 + V_89 + 1 ) ;
if ( F_52 ( V_76 ) ) {
int V_61 = ( type == V_68 ) ?
V_97 : V_98 ;
unsigned long V_99 = V_82 ;
unsigned int V_100 = V_60 ;
for ( V_95 = 0 ; V_95 < V_89 ;
V_95 ++ ) {
struct V_86 * V_101 = F_53 ( V_76 + ( V_95 *
V_28 ) ) ;
T_12 V_102 = V_28 - V_100 ;
if ( V_102 > V_99 )
V_102 = V_99 ;
V_87 [ V_95 ] = V_101 ;
F_54 ( F_55 ( V_101 ) + V_100 , V_102 , V_61 ) ;
V_99 -= V_102 ;
V_100 = 0 ;
}
* V_96 = 0 ;
} else {
F_56 ( & V_84 -> V_103 -> V_104 ) ;
V_95 = F_57 ( V_84 , V_84 -> V_103 ,
( unsigned long ) V_76 & ~ ( V_28 - 1 ) ,
V_89 ,
( type == V_67 ) ? V_105 : 0 ,
V_87 ,
NULL ) ;
F_58 ( & V_84 -> V_103 -> V_104 ) ;
if ( V_95 != V_89 ) {
F_19 ( V_43 ,
L_11 ,
V_95 ,
V_89 ) ;
while ( V_95 > 0 )
{
V_95 -- ;
F_59 ( V_87 [ V_95 ] ) ;
}
F_60 ( V_62 ) ;
if ( V_95 == 0 )
V_95 = - V_27 ;
return V_95 ;
}
* V_96 = 1 ;
}
V_62 -> V_99 = V_82 ;
V_62 -> type = type ;
V_62 -> V_60 = V_60 ;
V_91 = F_34 ( F_55 ( V_87 [ 0 ] ) ) ;
V_92 = V_91 + V_28 ;
V_94 = 0 ;
V_93 = 0 ;
for ( V_18 = 1 ; V_18 < V_89 ; V_18 ++ ) {
V_90 = F_34 ( F_55 ( V_87 [ V_18 ] ) ) ;
if ( ( V_90 == V_92 ) && ( V_93 < ( V_28 - 1 ) ) ) {
V_92 += V_28 ;
V_93 ++ ;
} else {
V_88 [ V_94 ] = ( unsigned long ) V_91 + V_93 ;
V_94 ++ ;
V_91 = V_90 ;
V_92 = V_90 + V_28 ;
V_93 = 0 ;
}
}
V_88 [ V_94 ] = ( unsigned long ) V_91 + V_93 ;
V_94 ++ ;
if ( ( type == V_67 ) &&
( ( V_62 -> V_60 & ( V_21 - 1 ) ) ||
( ( V_62 -> V_60 + V_62 -> V_99 ) &
( V_21 - 1 ) ) ) ) {
char * V_106 ;
if ( F_61 ( & V_35 ) != 0 ) {
F_60 ( V_62 ) ;
return - V_107 ;
}
F_8 ( V_34 == NULL ) ;
F_62 ( & V_108 ) ;
V_106 = V_34 ;
F_8 ( V_106 == NULL ) ;
V_34 = * ( char * * ) V_34 ;
F_63 ( & V_108 ) ;
V_62 -> type = V_109 +
( V_106 - V_33 ) / V_22 ;
}
F_64 ( V_62 , V_88 + V_89 ) ;
* V_85 = V_62 ;
return 0 ;
}
static void
F_36 ( T_10 * V_62 , int V_74 )
{
unsigned long * V_96 ;
struct V_86 * * V_87 ;
unsigned int V_89 , V_18 ;
F_51 ( V_43 ,
L_12 , ( unsigned int ) V_62 , V_74 ) ;
V_89 =
( V_62 -> V_99 + V_62 -> V_60 + V_28 - 1 ) /
V_28 ;
V_96 = ( unsigned long * ) ( V_62 -> V_88 + V_89 ) ;
V_87 = (struct V_86 * * ) ( V_62 -> V_88 + V_89 + 1 ) ;
if ( V_62 -> type >= V_109 ) {
char * V_106 = V_33 +
( V_62 -> type - V_109 ) *
V_22 ;
int V_110 , V_111 ;
V_110 = ( V_21 - V_62 -> V_60 ) &
( V_21 - 1 ) ;
V_111 = ( V_62 -> V_60 + V_74 ) &
( V_21 - 1 ) ;
if ( ( V_74 >= 0 ) && ( V_110 != 0 ) ) {
if ( V_110 > V_74 )
V_110 = V_74 ;
memcpy ( ( char * ) F_55 ( V_87 [ 0 ] ) +
V_62 -> V_60 ,
V_106 ,
V_110 ) ;
}
if ( ( V_74 >= 0 ) && ( V_110 < V_74 ) &&
( V_111 != 0 ) ) {
memcpy ( ( char * ) F_55 ( V_87 [ V_89 - 1 ] ) +
( ( V_62 -> V_60 + V_74 ) &
( V_28 - 1 ) & ~ ( V_21 - 1 ) ) ,
V_106 + V_21 ,
V_111 ) ;
}
F_62 ( & V_108 ) ;
* ( char * * ) V_106 = V_34 ;
V_34 = V_106 ;
F_63 ( & V_108 ) ;
F_63 ( & V_35 ) ;
}
if ( * V_96 ) {
unsigned int V_99 = V_62 -> V_99 ;
unsigned int V_60 = V_62 -> V_60 ;
for ( V_18 = 0 ; V_18 < V_89 ; V_18 ++ ) {
struct V_86 * V_101 = V_87 [ V_18 ] ;
if ( V_62 -> type != V_68 ) {
unsigned int V_102 = V_28 - V_60 ;
if ( V_102 > V_99 )
V_102 = V_99 ;
F_65 ( F_55 ( V_101 ) + V_60 ,
V_102 , V_98 ) ;
V_99 -= V_102 ;
V_60 = 0 ;
F_66 ( V_101 ) ;
}
F_59 ( V_101 ) ;
}
}
F_60 ( V_62 ) ;
}
