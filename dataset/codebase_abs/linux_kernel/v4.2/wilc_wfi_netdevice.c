void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
struct V_6 * V_7 ;
V_4 -> V_8 = NULL ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_7 = F_3 ( sizeof ( struct V_6 ) , V_10 ) ;
if ( V_7 == NULL ) {
F_4 ( V_11 , L_1 ) ;
return;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_12 = V_4 -> V_8 ;
V_4 -> V_8 = V_7 ;
}
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
while ( ( V_7 = V_4 -> V_8 ) ) {
V_4 -> V_8 = V_7 -> V_12 ;
F_6 ( V_7 ) ;
}
}
struct V_6 * F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_13 ;
struct V_6 * V_7 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
V_7 = V_4 -> V_8 ;
V_4 -> V_8 = V_7 -> V_12 ;
if ( V_4 -> V_8 == NULL ) {
F_9 ( V_11 , L_2 ) ;
F_10 ( V_2 ) ;
}
F_11 ( & V_4 -> V_14 , V_13 ) ;
return V_7 ;
}
void F_12 ( struct V_6 * V_7 )
{
unsigned long V_13 ;
struct V_3 * V_4 = F_2 ( V_7 -> V_2 ) ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
V_7 -> V_12 = V_4 -> V_8 ;
V_4 -> V_8 = V_7 ;
F_11 ( & V_4 -> V_14 , V_13 ) ;
if ( F_13 ( V_7 -> V_2 ) && V_7 -> V_12 == NULL )
F_14 ( V_7 -> V_2 ) ;
}
void F_15 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_13 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
V_7 -> V_12 = V_4 -> V_15 ;
V_4 -> V_15 = V_7 ;
F_11 ( & V_4 -> V_14 , V_13 ) ;
}
struct V_6 * F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_13 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
V_7 = V_4 -> V_15 ;
if ( V_7 != NULL )
V_4 -> V_15 = V_7 -> V_12 ;
F_11 ( & V_4 -> V_14 , V_13 ) ;
return V_7 ;
}
static void F_17 ( struct V_1 * V_2 , int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_17 = V_16 ;
}
int F_18 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_18 , L_3 , V_19 ) ;
if ( V_2 == V_20 [ 1 ] )
V_2 -> V_18 [ V_19 - 1 ] ++ ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( V_2 -> V_13 & V_23 )
return - V_24 ;
if ( V_22 -> V_25 != V_2 -> V_25 ) {
F_4 ( V_11 , V_26 L_4 ) ;
return - V_27 ;
}
if ( V_22 -> V_28 != V_2 -> V_28 ) {
V_2 -> V_28 = V_22 -> V_28 ;
}
return 0 ;
}
void F_23 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_5 ;
struct V_29 * V_30 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_31 ;
V_30 = F_24 ( V_7 -> V_32 + 2 ) ;
if ( ! V_30 ) {
if ( F_25 () )
F_4 ( V_11 , L_5 ) ;
V_4 -> V_33 . V_34 ++ ;
goto V_35;
}
F_26 ( V_30 , 2 ) ;
memcpy ( F_27 ( V_30 , V_7 -> V_32 ) , V_7 -> V_36 , V_7 -> V_32 ) ;
if ( V_4 -> V_37 ) {
F_9 ( V_11 , L_6 , V_2 -> V_38 ) ;
V_4 = F_28 ( V_4 -> V_2 -> V_39 -> V_40 ) ;
F_4 ( V_11 , L_7 , V_4 -> V_41 ) ;
if ( V_42 ) {
for ( V_5 = 14 ; V_5 < V_30 -> V_43 ; V_5 ++ )
F_9 ( V_11 , L_8 , V_5 , V_30 -> V_36 [ V_5 ] ) ;
}
F_29 ( V_2 , V_30 ) ;
return;
}
V_35:
return;
}
static int F_30 ( struct V_44 * V_45 , int V_46 )
{
int V_47 = 0 ;
struct V_29 * V_30 ;
struct V_3 * V_4 = F_31 ( V_45 , struct V_3 , V_45 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_6 * V_7 ;
while ( V_47 < V_46 && V_4 -> V_15 ) {
V_7 = F_16 ( V_2 ) ;
V_30 = F_24 ( V_7 -> V_32 + 2 ) ;
if ( ! V_30 ) {
if ( F_25 () )
F_4 ( V_11 , L_9 ) ;
V_4 -> V_33 . V_34 ++ ;
F_12 ( V_7 ) ;
continue;
}
F_26 ( V_30 , 2 ) ;
memcpy ( F_27 ( V_30 , V_7 -> V_32 ) , V_7 -> V_36 , V_7 -> V_32 ) ;
V_30 -> V_2 = V_2 ;
V_30 -> V_48 = F_32 ( V_30 , V_2 ) ;
V_30 -> V_49 = V_50 ;
F_33 ( V_30 ) ;
V_47 ++ ;
F_34 ( V_4 -> V_2 -> V_39 -> V_40 , V_7 -> V_32 , V_51 ) ;
F_12 ( V_7 ) ;
}
if ( V_47 < V_46 ) {
F_35 ( V_45 ) ;
F_17 ( V_2 , 1 ) ;
}
return V_47 ;
}
static void F_36 ( int V_28 , void * V_52 , struct V_53 * V_54 )
{
int V_55 ;
struct V_3 * V_4 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
if ( ! V_2 )
return;
V_4 = F_2 ( V_2 ) ;
F_37 ( & V_4 -> V_14 ) ;
V_55 = V_4 -> V_56 ;
V_4 -> V_56 = 0 ;
if ( V_55 & V_57 ) {
V_7 = V_4 -> V_15 ;
if ( V_7 ) {
V_4 -> V_15 = V_7 -> V_12 ;
F_23 ( V_2 , V_7 ) ;
}
}
if ( V_55 & V_58 ) {
F_34 ( V_4 -> V_2 -> V_39 -> V_40 , V_4 -> V_59 , V_60 ) ;
F_38 ( V_4 -> V_30 ) ;
}
F_39 ( & V_4 -> V_14 ) ;
if ( V_7 )
F_12 ( V_7 ) ;
return;
}
static void F_40 ( int V_28 , void * V_52 , struct V_53 * V_54 )
{
int V_55 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
if ( ! V_2 )
return;
V_4 = F_2 ( V_2 ) ;
F_37 ( & V_4 -> V_14 ) ;
V_55 = V_4 -> V_56 ;
V_4 -> V_56 = 0 ;
if ( V_55 & V_57 ) {
F_17 ( V_2 , 0 ) ;
F_41 ( & V_4 -> V_45 ) ;
}
if ( V_55 & V_58 ) {
F_34 ( V_4 -> V_2 -> V_39 -> V_40 , V_4 -> V_59 , V_60 ) ;
F_38 ( V_4 -> V_30 ) ;
}
F_39 ( & V_4 -> V_14 ) ;
return;
}
void F_42 ( char * V_61 , int V_43 , struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_1 * V_64 ;
struct V_3 * V_4 ;
T_2 * V_65 , * V_66 ;
struct V_6 * V_67 ;
if ( V_43 < sizeof( struct V_68 ) + sizeof( struct V_62 ) ) {
F_4 ( V_11 , L_10 ,
V_43 ) ;
return;
}
if ( 0 ) {
int V_5 ;
F_4 ( V_11 , L_11 , V_43 ) ;
for ( V_5 = 14 ; V_5 < V_43 ; V_5 ++ )
F_4 ( V_11 , L_12 , V_5 , V_61 [ V_5 ] & 0xff ) ;
}
V_63 = (struct V_62 * ) ( V_61 + sizeof( struct V_68 ) ) ;
V_65 = & V_63 -> V_65 ;
V_66 = & V_63 -> V_66 ;
( ( V_69 * ) V_65 ) [ 2 ] ^= 1 ;
( ( V_69 * ) V_66 ) [ 2 ] ^= 1 ;
V_63 -> V_70 = 0 ;
V_63 -> V_70 = F_43 ( ( unsigned char * ) V_63 , V_63 -> V_71 ) ;
if ( V_2 == V_20 [ 0 ] )
F_4 ( V_11 , L_13 ,
F_44 ( V_63 -> V_65 ) , F_45 ( ( (struct V_72 * ) ( V_63 + 1 ) ) -> V_73 ) ,
F_44 ( V_63 -> V_66 ) , F_45 ( ( (struct V_72 * ) ( V_63 + 1 ) ) -> V_64 ) ) ;
else
F_4 ( V_11 , L_14 ,
F_44 ( V_63 -> V_66 ) , F_45 ( ( (struct V_72 * ) ( V_63 + 1 ) ) -> V_64 ) ,
F_44 ( V_63 -> V_65 ) , F_45 ( ( (struct V_72 * ) ( V_63 + 1 ) ) -> V_73 ) ) ;
V_64 = V_20 [ V_2 == V_20 [ 0 ] ? 1 : 0 ] ;
V_4 = F_2 ( V_64 ) ;
V_67 = F_7 ( V_2 ) ;
V_67 -> V_32 = V_43 ;
memcpy ( V_67 -> V_36 , V_61 , V_43 ) ;
F_15 ( V_64 , V_67 ) ;
if ( V_4 -> V_17 ) {
V_4 -> V_56 |= V_57 ;
F_46 ( 0 , V_64 , NULL ) ;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_59 = V_43 ;
V_4 -> V_74 = V_61 ;
V_4 -> V_56 |= V_58 ;
if ( V_75 && ( ( V_4 -> V_33 . V_76 + 1 ) % V_75 ) == 0 ) {
F_10 ( V_2 ) ;
F_4 ( V_11 , L_15 , V_77 ,
( unsigned long ) V_4 -> V_33 . V_76 ) ;
} else
F_46 ( 0 , V_2 , NULL ) ;
}
int F_47 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
int V_43 ;
char * V_36 , V_78 [ V_79 ] ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_36 = V_30 -> V_36 ;
V_43 = V_30 -> V_43 ;
if ( V_43 < V_79 ) {
memset ( V_78 , 0 , V_79 ) ;
memcpy ( V_78 , V_30 -> V_36 , V_30 -> V_43 ) ;
V_43 = V_79 ;
V_36 = V_78 ;
}
V_2 -> V_80 = V_77 ;
V_4 -> V_30 = V_30 ;
F_42 ( V_36 , V_43 , V_2 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( V_11 , L_16 , V_77 ,
V_77 - V_2 -> V_80 ) ;
V_4 -> V_56 = V_58 ;
F_46 ( 0 , V_2 , NULL ) ;
V_4 -> V_33 . V_81 ++ ;
F_14 ( V_2 ) ;
return;
}
int F_49 ( struct V_1 * V_2 , struct V_82 * V_83 , int V_84 )
{
F_4 ( V_11 , L_17 ) ;
return 0 ;
}
struct V_85 * F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return & V_4 -> V_33 ;
}
int F_51 ( struct V_29 * V_30 )
{
struct V_68 * V_86 = (struct V_68 * ) V_30 -> V_36 ;
struct V_1 * V_2 = V_30 -> V_2 ;
memcpy ( V_86 -> V_87 , V_2 -> V_18 , V_2 -> V_88 ) ;
memcpy ( V_86 -> V_89 , V_2 -> V_18 , V_2 -> V_88 ) ;
V_86 -> V_89 [ V_19 - 1 ] ^= 0x01 ;
return 0 ;
}
int F_52 ( struct V_29 * V_30 , struct V_1 * V_2 ,
unsigned short type , const void * V_66 , const void * V_65 ,
unsigned int V_43 )
{
struct V_68 * V_86 = (struct V_68 * ) F_53 ( V_30 , V_90 ) ;
V_86 -> V_91 = F_54 ( type ) ;
memcpy ( V_86 -> V_87 , V_65 ? V_65 : V_2 -> V_18 , V_2 -> V_88 ) ;
memcpy ( V_86 -> V_89 , V_66 ? V_66 : V_2 -> V_18 , V_2 -> V_88 ) ;
V_86 -> V_89 [ V_19 - 1 ] ^= 0x01 ;
return V_2 -> V_92 ;
}
int F_55 ( struct V_1 * V_2 , int V_93 )
{
unsigned long V_13 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 * V_14 = & V_4 -> V_14 ;
if ( ( V_93 < 68 ) || ( V_93 > 1500 ) )
return - V_94 ;
F_8 ( V_14 , V_13 ) ;
V_2 -> V_95 = V_93 ;
F_11 ( V_14 , V_13 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_57 ( V_2 ) ;
V_2 -> V_96 = & V_97 ;
V_2 -> V_98 = & V_99 ;
V_2 -> V_100 = V_101 ;
V_2 -> V_13 |= V_102 ;
V_2 -> V_103 |= V_104 ;
V_4 = F_2 ( V_2 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_2 = V_2 ;
F_58 ( V_2 , & V_4 -> V_45 , F_30 , 2 ) ;
F_59 ( & V_4 -> V_14 ) ;
F_17 ( V_2 , 1 ) ;
F_1 ( V_2 ) ;
}
void F_60 ( void )
{
int V_5 ;
struct V_3 * V_4 [ 2 ] ;
for ( V_5 = 0 ; V_5 < 2 ; V_5 ++ ) {
V_4 [ V_5 ] = F_2 ( V_20 [ V_5 ] ) ;
if ( V_20 [ V_5 ] ) {
F_4 ( V_11 , L_18 ) ;
F_61 ( V_20 [ V_5 ] ) ;
F_5 ( V_20 [ V_5 ] ) ;
F_62 ( V_20 [ V_5 ] ) ;
F_4 ( V_11 , L_19 ) ;
F_63 ( V_20 [ V_5 ] ) ;
F_64 ( V_20 [ V_5 ] ) ;
}
}
F_65 () ;
return;
}
int F_66 ( void )
{
int V_105 , V_5 , V_106 = - V_107 ;
struct V_3 * V_4 [ 2 ] , * V_108 ;
struct V_109 * V_110 ;
F_46 = V_111 ? F_40 : F_36 ;
char V_61 [ V_112 ] ;
for ( V_5 = 0 ; V_5 < 2 ; V_5 ++ ) {
V_20 [ V_5 ] = F_67 ( sizeof( struct V_3 ) , L_20 ,
F_56 ) ;
if ( V_20 [ V_5 ] == NULL )
goto V_35;
V_110 = F_68 ( V_20 [ V_5 ] ) ;
V_20 [ V_5 ] -> V_39 = V_110 ;
V_108 = F_2 ( V_20 [ V_5 ] ) ;
V_108 -> V_2 -> V_39 = V_110 ;
V_108 -> V_2 -> V_113 = V_108 ;
V_110 -> V_114 = V_108 -> V_2 ;
V_105 = F_69 ( V_20 [ V_5 ] ) ;
if ( V_105 )
F_4 ( V_11 , L_21 ,
V_105 , V_20 [ V_5 ] -> V_38 ) ;
else
V_106 = 0 ;
}
V_4 [ 0 ] = F_2 ( V_20 [ 0 ] ) ;
V_4 [ 1 ] = F_2 ( V_20 [ 1 ] ) ;
if ( V_4 [ 1 ] -> V_2 -> V_39 -> V_40 -> V_115 && F_70 ( V_116 ) ) {
}
V_4 [ 0 ] -> V_117 = false ;
V_4 [ 0 ] -> V_118 = 0 ;
F_71 ( V_4 [ 0 ] -> V_119 , 0xFF , V_19 ) ;
if ( V_106 ) {
F_72 ( L_22 ) ;
}
V_35:
if ( V_106 )
F_60 () ;
return V_106 ;
}
