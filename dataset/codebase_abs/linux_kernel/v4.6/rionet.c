static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int error = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
void * V_6 ;
V_3 = V_5 -> V_7 ;
do {
if ( ! V_5 -> V_8 [ V_3 ] )
continue;
if ( ! ( V_6 = F_3 ( V_5 -> V_9 , V_10 ) ) )
break;
V_5 -> V_8 [ V_3 ] -> V_6 = V_6 ;
F_4 ( V_5 -> V_8 [ V_3 ] , V_11 ) ;
V_5 -> V_8 [ V_3 ] -> V_12 =
F_5 ( V_5 -> V_8 [ V_3 ] , V_2 ) ;
error = F_6 ( V_5 -> V_8 [ V_3 ] ) ;
if ( error == V_13 ) {
V_2 -> V_14 . V_15 ++ ;
} else {
V_2 -> V_14 . V_16 ++ ;
V_2 -> V_14 . V_17 += V_11 ;
}
} while ( ( V_3 = ( V_3 + 1 ) % V_18 ) != V_5 -> V_7 );
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 , int V_19 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 = V_5 -> V_7 ;
do {
V_5 -> V_8 [ V_3 ] = F_8 ( V_11 ) ;
if ( ! V_5 -> V_8 [ V_3 ] )
break;
F_9 ( V_5 -> V_9 , V_10 ,
V_5 -> V_8 [ V_3 ] -> V_6 ) ;
} while ( ( V_3 = ( V_3 + 1 ) % V_18 ) != V_19 );
V_5 -> V_7 = V_3 ;
}
static int F_10 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 -> V_9 , V_23 , 0 , V_21 -> V_6 , V_21 -> V_24 ) ;
V_5 -> V_25 [ V_5 -> V_26 ] = V_21 ;
V_2 -> V_14 . V_27 ++ ;
V_2 -> V_14 . V_28 += V_21 -> V_24 ;
if ( ++ V_5 -> V_29 == V_30 )
F_12 ( V_2 ) ;
++ V_5 -> V_26 ;
V_5 -> V_26 &= ( V_30 - 1 ) ;
if ( F_13 ( V_5 ) )
F_14 ( V_31 L_1 , V_32 ,
V_21 -> V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_33 * V_34 = (struct V_33 * ) V_21 -> V_6 ;
T_1 V_35 ;
unsigned long V_36 ;
int V_37 = 1 ;
F_16 ( V_36 ) ;
if ( ! F_17 ( & V_5 -> V_38 ) ) {
F_18 ( V_36 ) ;
return V_39 ;
}
if ( F_19 ( V_34 -> V_40 ) )
V_37 = V_41 [ V_5 -> V_9 -> V_42 ] . V_43 ;
if ( ( V_5 -> V_29 + V_37 ) > V_30 ) {
F_12 ( V_2 ) ;
F_20 ( & V_5 -> V_38 , V_36 ) ;
F_14 ( V_44 L_2 ,
V_2 -> V_45 ) ;
return V_46 ;
}
if ( F_19 ( V_34 -> V_40 ) ) {
int V_47 = 0 ;
for ( V_3 = 0 ; V_3 < F_21 ( V_5 -> V_9 -> V_48 ) ;
V_3 ++ )
if ( V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_3 ] ) {
F_10 ( V_21 , V_2 ,
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_3 ] ) ;
if ( V_47 )
F_22 ( & V_21 -> V_50 ) ;
V_47 ++ ;
}
} else if ( F_23 ( V_34 -> V_40 ) ) {
V_35 = F_24 ( V_34 -> V_40 ) ;
if ( V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_35 ] )
F_10 ( V_21 , V_2 ,
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_35 ] ) ;
else {
F_25 ( V_21 ) ;
V_2 -> V_14 . V_27 ++ ;
V_2 -> V_14 . V_28 += V_21 -> V_24 ;
}
}
F_20 ( & V_5 -> V_38 , V_36 ) ;
return V_51 ;
}
static void F_26 ( struct V_52 * V_9 , void * V_53 , T_1 V_54 , T_1 V_55 ,
T_1 V_56 )
{
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_57 * V_58 ;
unsigned char V_59 = V_5 -> V_9 -> V_42 ;
if ( F_27 ( V_5 ) )
F_14 ( V_31 L_3 ,
V_32 , V_54 , V_55 , V_56 ) ;
if ( V_56 == V_60 ) {
if ( ! V_41 [ V_59 ] . V_49 [ V_54 ] ) {
F_28 ( & V_41 [ V_59 ] . V_61 ) ;
F_29 (peer, &nets[netid].peers, node) {
if ( V_58 -> V_23 -> V_35 == V_54 ) {
V_41 [ V_59 ] . V_49 [ V_54 ] = V_58 -> V_23 ;
V_41 [ V_59 ] . V_43 ++ ;
}
}
F_30 ( & V_41 [ V_59 ] . V_61 ) ;
F_31 ( V_9 , V_54 ,
V_60 ) ;
}
} else if ( V_56 == V_62 ) {
F_28 ( & V_41 [ V_59 ] . V_61 ) ;
if ( V_41 [ V_59 ] . V_49 [ V_54 ] ) {
V_41 [ V_59 ] . V_49 [ V_54 ] = NULL ;
V_41 [ V_59 ] . V_43 -- ;
}
F_30 ( & V_41 [ V_59 ] . V_61 ) ;
} else {
if ( F_27 ( V_5 ) )
F_14 ( V_63 L_4 ,
V_32 ) ;
}
}
static void F_32 ( struct V_52 * V_9 , void * V_53 , int V_64 , int V_65 )
{
int V_66 ;
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_27 ( V_5 ) )
F_14 ( V_31 L_5 ,
V_32 , V_64 , V_65 ) ;
F_28 ( & V_5 -> V_61 ) ;
if ( ( V_66 = F_1 ( V_2 ) ) != V_5 -> V_7 )
F_7 ( V_2 , V_66 ) ;
F_30 ( & V_5 -> V_61 ) ;
}
static void F_33 ( struct V_52 * V_9 , void * V_53 , int V_64 , int V_65 )
{
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_28 ( & V_5 -> V_38 ) ;
if ( F_27 ( V_5 ) )
F_14 ( V_31
L_6 ,
V_32 , V_64 , V_65 ) ;
while ( V_5 -> V_29 && ( V_5 -> V_67 != V_65 ) ) {
F_34 ( V_5 -> V_25 [ V_5 -> V_67 ] ) ;
V_5 -> V_25 [ V_5 -> V_67 ] = NULL ;
++ V_5 -> V_67 ;
V_5 -> V_67 &= ( V_30 - 1 ) ;
V_5 -> V_29 -- ;
}
if ( V_5 -> V_29 < V_30 )
F_35 ( V_2 ) ;
F_30 ( & V_5 -> V_38 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_3 , V_68 = 0 ;
struct V_57 * V_58 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_59 = V_5 -> V_9 -> V_42 ;
unsigned long V_36 ;
if ( F_37 ( V_5 ) )
F_14 ( V_31 L_7 , V_32 ) ;
if ( ( V_68 = F_38 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_60 ,
V_62 ,
F_26 ) ) < 0 )
goto V_69;
if ( ( V_68 = F_39 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_18 ,
F_32 ) ) < 0 )
goto V_69;
if ( ( V_68 = F_40 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_30 ,
F_33 ) ) < 0 )
goto V_69;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
V_5 -> V_8 [ V_3 ] = NULL ;
V_5 -> V_7 = 0 ;
F_7 ( V_2 , 0 ) ;
V_5 -> V_26 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_67 = 0 ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
F_29 (peer, &nets[netid].peers, node) {
F_44 ( V_58 -> V_23 , V_60 ) ;
}
F_20 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
V_5 -> V_70 = true ;
V_69:
return V_68 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_57 * V_58 ;
unsigned char V_59 = V_5 -> V_9 -> V_42 ;
unsigned long V_36 ;
int V_3 ;
if ( F_37 ( V_5 ) )
F_14 ( V_31 L_8 , V_32 , V_2 -> V_45 ) ;
F_12 ( V_2 ) ;
F_46 ( V_2 ) ;
V_5 -> V_70 = false ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_47 ( V_5 -> V_8 [ V_3 ] ) ;
F_43 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
F_29 (peer, &nets[netid].peers, node) {
if ( V_41 [ V_59 ] . V_49 [ V_58 -> V_23 -> V_35 ] ) {
F_44 ( V_58 -> V_23 , V_62 ) ;
V_41 [ V_59 ] . V_49 [ V_58 -> V_23 -> V_35 ] = NULL ;
}
if ( V_58 -> V_71 )
F_48 ( V_58 -> V_23 , V_58 -> V_71 ) ;
}
F_20 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
F_49 ( V_5 -> V_9 , V_60 ,
V_62 ) ;
F_50 ( V_5 -> V_9 , V_10 ) ;
F_51 ( V_5 -> V_9 , V_10 ) ;
return 0 ;
}
static void F_52 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
struct V_22 * V_23 = F_53 ( V_73 ) ;
unsigned char V_59 = V_23 -> V_76 -> V_77 -> V_42 ;
struct V_57 * V_58 ;
int V_78 , V_79 = 0 ;
unsigned long V_36 ;
if ( ! F_54 ( V_23 ) )
return;
F_43 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
F_29 (peer, &nets[netid].peers, node) {
if ( V_58 -> V_23 == V_23 ) {
F_55 ( & V_58 -> V_80 ) ;
if ( V_41 [ V_59 ] . V_49 [ V_23 -> V_35 ] ) {
V_78 = F_56 ( & V_23 -> V_78 ) ;
if ( V_78 != V_81 &&
V_78 != V_82 ) {
F_44 ( V_23 ,
V_62 ) ;
}
V_41 [ V_59 ] . V_49 [ V_23 -> V_35 ] = NULL ;
V_41 [ V_59 ] . V_43 -- ;
}
V_79 = 1 ;
break;
}
}
F_20 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
if ( V_79 ) {
if ( V_58 -> V_71 )
F_48 ( V_23 , V_58 -> V_71 ) ;
F_57 ( V_58 ) ;
}
}
static void F_58 ( struct V_1 * V_2 ,
struct V_83 * V_56 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_59 ( V_56 -> V_84 , V_32 , sizeof( V_56 -> V_84 ) ) ;
F_59 ( V_56 -> V_85 , V_86 , sizeof( V_56 -> V_85 ) ) ;
F_59 ( V_56 -> V_87 , L_9 , sizeof( V_56 -> V_87 ) ) ;
F_59 ( V_56 -> V_88 , V_5 -> V_9 -> V_45 , sizeof( V_56 -> V_88 ) ) ;
}
static T_2 F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_89 ;
}
static void F_61 ( struct V_1 * V_2 , T_2 V_90 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_89 = V_90 ;
}
static int F_62 ( struct V_1 * V_2 , int V_91 )
{
if ( ( V_91 < 68 ) || ( V_91 > V_92 ) ) {
F_14 ( V_44 L_10 ,
V_2 -> V_45 , V_91 ) ;
return - V_93 ;
}
V_2 -> V_94 = V_91 ;
return 0 ;
}
static int F_63 ( struct V_52 * V_9 , struct V_1 * V_2 )
{
int V_68 = 0 ;
struct V_4 * V_5 ;
T_1 V_95 ;
const T_3 V_96 = sizeof( void * ) *
F_21 ( V_9 -> V_48 ) ;
V_41 [ V_9 -> V_42 ] . V_49 = (struct V_22 * * ) F_64 ( V_97 ,
F_65 ( V_96 ) ) ;
if ( ! V_41 [ V_9 -> V_42 ] . V_49 ) {
V_68 = - V_98 ;
goto V_69;
}
memset ( ( void * ) V_41 [ V_9 -> V_42 ] . V_49 , 0 , V_96 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_9 = V_9 ;
V_5 -> V_70 = false ;
V_95 = F_66 ( V_9 ) ;
V_2 -> V_99 [ 0 ] = 0x00 ;
V_2 -> V_99 [ 1 ] = 0x01 ;
V_2 -> V_99 [ 2 ] = 0x00 ;
V_2 -> V_99 [ 3 ] = 0x01 ;
V_2 -> V_99 [ 4 ] = V_95 >> 8 ;
V_2 -> V_99 [ 5 ] = V_95 & 0xff ;
V_2 -> V_100 = & V_101 ;
V_2 -> V_94 = V_92 ;
V_2 -> V_102 = V_103 ;
F_67 ( V_2 , & V_9 -> V_73 ) ;
V_2 -> V_104 = & V_105 ;
F_68 ( & V_5 -> V_61 ) ;
F_68 ( & V_5 -> V_38 ) ;
V_5 -> V_89 = V_106 ;
V_68 = F_69 ( V_2 ) ;
if ( V_68 != 0 ) {
F_70 ( ( unsigned long ) V_41 [ V_9 -> V_42 ] . V_49 ,
F_65 ( V_96 ) ) ;
goto V_69;
}
F_14 ( V_31 L_11 ,
V_2 -> V_45 ,
V_32 ,
V_107 ,
V_86 ,
V_2 -> V_99 ,
V_9 -> V_45 ) ;
V_69:
return V_68 ;
}
static int F_71 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
int V_68 = - V_108 ;
T_2 V_109 , V_110 ;
struct V_57 * V_58 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = F_53 ( V_73 ) ;
unsigned char V_59 = V_23 -> V_76 -> V_77 -> V_42 ;
if ( V_59 >= V_111 )
return V_68 ;
if ( ! V_41 [ V_59 ] . V_2 ) {
F_72 ( V_23 -> V_76 -> V_77 , V_112 ,
& V_109 ) ;
F_72 ( V_23 -> V_76 -> V_77 , V_113 ,
& V_110 ) ;
if ( ! F_73 ( V_109 , V_110 ) ) {
F_14 ( V_44
L_12 ,
V_32 , V_23 -> V_76 -> V_77 -> V_45 ) ;
goto V_69;
}
V_2 = F_74 ( sizeof( struct V_4 ) ) ;
if ( V_2 == NULL ) {
V_68 = - V_98 ;
goto V_69;
}
V_68 = F_63 ( V_23 -> V_76 -> V_77 , V_2 ) ;
if ( V_68 ) {
F_14 ( V_44 L_13 ,
V_32 , V_68 ) ;
F_75 ( V_2 ) ;
goto V_69;
}
F_76 ( & V_41 [ V_59 ] . V_114 ) ;
F_68 ( & V_41 [ V_59 ] . V_61 ) ;
V_41 [ V_59 ] . V_43 = 0 ;
V_41 [ V_59 ] . V_2 = V_2 ;
}
if ( F_54 ( V_23 ) ) {
struct V_4 * V_5 ;
unsigned long V_36 ;
V_5 = F_2 ( V_41 [ V_59 ] . V_2 ) ;
V_58 = F_77 ( sizeof( * V_58 ) , V_97 ) ;
if ( ! V_58 ) {
V_68 = - V_98 ;
goto V_69;
}
V_58 -> V_23 = V_23 ;
V_58 -> V_71 = F_78 ( V_58 -> V_23 ,
V_60 ,
V_62 ) ;
if ( ! V_58 -> V_71 ) {
F_79 ( L_14 , V_32 ) ;
F_57 ( V_58 ) ;
V_68 = - V_98 ;
goto V_69;
}
F_43 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
F_80 ( & V_58 -> V_80 , & V_41 [ V_59 ] . V_114 ) ;
F_20 ( & V_41 [ V_59 ] . V_61 , V_36 ) ;
F_81 ( L_15 ,
V_32 , V_115 , F_82 ( V_23 ) ) ;
if ( V_5 -> V_70 )
F_44 ( V_58 -> V_23 , V_60 ) ;
}
return 0 ;
V_69:
return V_68 ;
}
static int F_83 ( struct V_116 * V_117 , unsigned long V_118 ,
void * V_119 )
{
struct V_57 * V_58 ;
unsigned long V_36 ;
int V_3 ;
F_81 ( L_16 , V_32 , V_115 ) ;
for ( V_3 = 0 ; V_3 < V_111 ; V_3 ++ ) {
if ( ! V_41 [ V_3 ] . V_2 )
continue;
F_43 ( & V_41 [ V_3 ] . V_61 , V_36 ) ;
F_29 (peer, &nets[i].peers, node) {
if ( V_41 [ V_3 ] . V_49 [ V_58 -> V_23 -> V_35 ] ) {
F_44 ( V_58 -> V_23 ,
V_62 ) ;
V_41 [ V_3 ] . V_49 [ V_58 -> V_23 -> V_35 ] = NULL ;
}
}
F_20 ( & V_41 [ V_3 ] . V_61 , V_36 ) ;
}
return V_120 ;
}
static void F_84 ( struct V_72 * V_73 ,
struct V_121 * V_122 )
{
struct V_52 * V_9 = F_85 ( V_73 ) ;
struct V_1 * V_2 ;
int V_42 = V_9 -> V_42 ;
F_81 ( L_17 , V_115 , V_9 -> V_45 ) ;
F_86 ( V_41 [ V_42 ] . V_43 , L_18 ,
V_115 , V_41 [ V_42 ] . V_43 ) ;
F_86 ( ! V_41 [ V_42 ] . V_2 , L_19 ,
V_115 ) ;
if ( V_41 [ V_42 ] . V_2 ) {
V_2 = V_41 [ V_42 ] . V_2 ;
F_12 ( V_2 ) ;
F_87 ( V_2 ) ;
F_70 ( ( unsigned long ) V_41 [ V_42 ] . V_49 ,
F_65 ( sizeof( void * ) *
F_21 ( V_9 -> V_48 ) ) ) ;
V_41 [ V_42 ] . V_49 = NULL ;
F_75 ( V_2 ) ;
V_41 [ V_42 ] . V_2 = NULL ;
}
}
static int T_4 F_88 ( void )
{
int V_123 ;
V_123 = F_89 ( & V_124 ) ;
if ( V_123 ) {
F_79 ( L_20 ,
V_32 , V_123 ) ;
return V_123 ;
}
V_123 = F_90 ( & V_125 ) ;
if ( V_123 ) {
F_79 ( L_21 ,
V_32 , V_123 ) ;
return V_123 ;
}
return F_91 ( & V_126 ) ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_124 ) ;
F_94 ( & V_126 ) ;
F_95 ( & V_125 ) ;
}
