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
F_16 ( & V_5 -> V_38 , V_36 ) ;
if ( F_17 ( V_34 -> V_39 ) )
V_37 = V_40 [ V_5 -> V_9 -> V_41 ] . V_42 ;
if ( ( V_5 -> V_29 + V_37 ) > V_30 ) {
F_12 ( V_2 ) ;
F_18 ( & V_5 -> V_38 , V_36 ) ;
F_14 ( V_43 L_2 ,
V_2 -> V_44 ) ;
return V_45 ;
}
if ( F_17 ( V_34 -> V_39 ) ) {
int V_46 = 0 ;
for ( V_3 = 0 ; V_3 < F_19 ( V_5 -> V_9 -> V_47 ) ;
V_3 ++ )
if ( V_40 [ V_5 -> V_9 -> V_41 ] . V_48 [ V_3 ] ) {
F_10 ( V_21 , V_2 ,
V_40 [ V_5 -> V_9 -> V_41 ] . V_48 [ V_3 ] ) ;
if ( V_46 )
F_20 ( & V_21 -> V_49 ) ;
V_46 ++ ;
}
} else if ( F_21 ( V_34 -> V_39 ) ) {
V_35 = F_22 ( V_34 -> V_39 ) ;
if ( V_40 [ V_5 -> V_9 -> V_41 ] . V_48 [ V_35 ] )
F_10 ( V_21 , V_2 ,
V_40 [ V_5 -> V_9 -> V_41 ] . V_48 [ V_35 ] ) ;
else {
F_23 ( V_21 ) ;
V_2 -> V_14 . V_27 ++ ;
V_2 -> V_14 . V_28 += V_21 -> V_24 ;
}
}
F_18 ( & V_5 -> V_38 , V_36 ) ;
return V_50 ;
}
static void F_24 ( struct V_51 * V_9 , void * V_52 , T_1 V_53 , T_1 V_54 ,
T_1 V_55 )
{
struct V_1 * V_2 = V_52 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_56 * V_57 ;
unsigned char V_58 = V_5 -> V_9 -> V_41 ;
if ( F_25 ( V_5 ) )
F_14 ( V_31 L_3 ,
V_32 , V_53 , V_54 , V_55 ) ;
if ( V_55 == V_59 ) {
if ( ! V_40 [ V_58 ] . V_48 [ V_53 ] ) {
F_26 ( & V_40 [ V_58 ] . V_60 ) ;
F_27 (peer, &nets[netid].peers, node) {
if ( V_57 -> V_23 -> V_35 == V_53 ) {
V_40 [ V_58 ] . V_48 [ V_53 ] = V_57 -> V_23 ;
V_40 [ V_58 ] . V_42 ++ ;
}
}
F_28 ( & V_40 [ V_58 ] . V_60 ) ;
F_29 ( V_9 , V_53 ,
V_59 ) ;
}
} else if ( V_55 == V_61 ) {
F_26 ( & V_40 [ V_58 ] . V_60 ) ;
if ( V_40 [ V_58 ] . V_48 [ V_53 ] ) {
V_40 [ V_58 ] . V_48 [ V_53 ] = NULL ;
V_40 [ V_58 ] . V_42 -- ;
}
F_28 ( & V_40 [ V_58 ] . V_60 ) ;
} else {
if ( F_25 ( V_5 ) )
F_14 ( V_62 L_4 ,
V_32 ) ;
}
}
static void F_30 ( struct V_51 * V_9 , void * V_52 , int V_63 , int V_64 )
{
int V_65 ;
struct V_1 * V_2 = V_52 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_25 ( V_5 ) )
F_14 ( V_31 L_5 ,
V_32 , V_63 , V_64 ) ;
F_26 ( & V_5 -> V_60 ) ;
if ( ( V_65 = F_1 ( V_2 ) ) != V_5 -> V_7 )
F_7 ( V_2 , V_65 ) ;
F_28 ( & V_5 -> V_60 ) ;
}
static void F_31 ( struct V_51 * V_9 , void * V_52 , int V_63 , int V_64 )
{
struct V_1 * V_2 = V_52 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_26 ( & V_5 -> V_38 ) ;
if ( F_25 ( V_5 ) )
F_14 ( V_31
L_6 ,
V_32 , V_63 , V_64 ) ;
while ( V_5 -> V_29 && ( V_5 -> V_66 != V_64 ) ) {
F_32 ( V_5 -> V_25 [ V_5 -> V_66 ] ) ;
V_5 -> V_25 [ V_5 -> V_66 ] = NULL ;
++ V_5 -> V_66 ;
V_5 -> V_66 &= ( V_30 - 1 ) ;
V_5 -> V_29 -- ;
}
if ( V_5 -> V_29 < V_30 )
F_33 ( V_2 ) ;
F_28 ( & V_5 -> V_38 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_3 , V_67 = 0 ;
struct V_56 * V_57 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_58 = V_5 -> V_9 -> V_41 ;
unsigned long V_36 ;
if ( F_35 ( V_5 ) )
F_14 ( V_31 L_7 , V_32 ) ;
if ( ( V_67 = F_36 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_59 ,
V_61 ,
F_24 ) ) < 0 )
goto V_68;
if ( ( V_67 = F_37 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_18 ,
F_30 ) ) < 0 )
goto V_68;
if ( ( V_67 = F_38 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_30 ,
F_31 ) ) < 0 )
goto V_68;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
V_5 -> V_8 [ V_3 ] = NULL ;
V_5 -> V_7 = 0 ;
F_7 ( V_2 , 0 ) ;
V_5 -> V_26 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_66 = 0 ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_16 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
F_27 (peer, &nets[netid].peers, node) {
F_41 ( V_57 -> V_23 , V_59 ) ;
}
F_18 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
V_5 -> V_69 = true ;
V_68:
return V_67 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_56 * V_57 ;
unsigned char V_58 = V_5 -> V_9 -> V_41 ;
unsigned long V_36 ;
int V_3 ;
if ( F_35 ( V_5 ) )
F_14 ( V_31 L_8 , V_32 , V_2 -> V_44 ) ;
F_12 ( V_2 ) ;
F_43 ( V_2 ) ;
V_5 -> V_69 = false ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_44 ( V_5 -> V_8 [ V_3 ] ) ;
F_16 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
F_27 (peer, &nets[netid].peers, node) {
if ( V_40 [ V_58 ] . V_48 [ V_57 -> V_23 -> V_35 ] ) {
F_41 ( V_57 -> V_23 , V_61 ) ;
V_40 [ V_58 ] . V_48 [ V_57 -> V_23 -> V_35 ] = NULL ;
}
if ( V_57 -> V_70 )
F_45 ( V_57 -> V_23 , V_57 -> V_70 ) ;
}
F_18 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
F_46 ( V_5 -> V_9 , V_59 ,
V_61 ) ;
F_47 ( V_5 -> V_9 , V_10 ) ;
F_48 ( V_5 -> V_9 , V_10 ) ;
return 0 ;
}
static void F_49 ( struct V_71 * V_72 , struct V_73 * V_74 )
{
struct V_22 * V_23 = F_50 ( V_72 ) ;
unsigned char V_58 = V_23 -> V_75 -> V_76 -> V_41 ;
struct V_56 * V_57 ;
int V_77 , V_78 = 0 ;
unsigned long V_36 ;
if ( ! F_51 ( V_23 ) )
return;
F_16 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
F_27 (peer, &nets[netid].peers, node) {
if ( V_57 -> V_23 == V_23 ) {
F_52 ( & V_57 -> V_79 ) ;
if ( V_40 [ V_58 ] . V_48 [ V_23 -> V_35 ] ) {
V_77 = F_53 ( & V_23 -> V_77 ) ;
if ( V_77 != V_80 &&
V_77 != V_81 ) {
F_41 ( V_23 ,
V_61 ) ;
}
V_40 [ V_58 ] . V_48 [ V_23 -> V_35 ] = NULL ;
V_40 [ V_58 ] . V_42 -- ;
}
V_78 = 1 ;
break;
}
}
F_18 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
if ( V_78 ) {
if ( V_57 -> V_70 )
F_45 ( V_23 , V_57 -> V_70 ) ;
F_54 ( V_57 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_82 * V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_56 ( V_55 -> V_83 , V_32 , sizeof( V_55 -> V_83 ) ) ;
F_56 ( V_55 -> V_84 , V_85 , sizeof( V_55 -> V_84 ) ) ;
F_56 ( V_55 -> V_86 , L_9 , sizeof( V_55 -> V_86 ) ) ;
F_56 ( V_55 -> V_87 , V_5 -> V_9 -> V_44 , sizeof( V_55 -> V_87 ) ) ;
}
static T_2 F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_88 ;
}
static void F_58 ( struct V_1 * V_2 , T_2 V_89 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_88 = V_89 ;
}
static int F_59 ( struct V_51 * V_9 , struct V_1 * V_2 )
{
int V_67 = 0 ;
struct V_4 * V_5 ;
T_1 V_90 ;
const T_3 V_91 = sizeof( void * ) *
F_19 ( V_9 -> V_47 ) ;
V_40 [ V_9 -> V_41 ] . V_48 = (struct V_22 * * ) F_60 ( V_92 ,
F_61 ( V_91 ) ) ;
if ( ! V_40 [ V_9 -> V_41 ] . V_48 ) {
V_67 = - V_93 ;
goto V_68;
}
memset ( ( void * ) V_40 [ V_9 -> V_41 ] . V_48 , 0 , V_91 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_9 = V_9 ;
V_5 -> V_69 = false ;
V_90 = F_62 ( V_9 ) ;
V_2 -> V_94 [ 0 ] = 0x00 ;
V_2 -> V_94 [ 1 ] = 0x01 ;
V_2 -> V_94 [ 2 ] = 0x00 ;
V_2 -> V_94 [ 3 ] = 0x01 ;
V_2 -> V_94 [ 4 ] = V_90 >> 8 ;
V_2 -> V_94 [ 5 ] = V_90 & 0xff ;
V_2 -> V_95 = & V_96 ;
V_2 -> V_97 = V_98 ;
V_2 -> V_99 = V_100 ;
V_2 -> V_101 = V_98 ;
V_2 -> V_102 = V_103 ;
F_63 ( V_2 , & V_9 -> V_72 ) ;
V_2 -> V_104 = & V_105 ;
F_64 ( & V_5 -> V_60 ) ;
F_64 ( & V_5 -> V_38 ) ;
V_5 -> V_88 = V_106 ;
V_67 = F_65 ( V_2 ) ;
if ( V_67 != 0 ) {
F_66 ( ( unsigned long ) V_40 [ V_9 -> V_41 ] . V_48 ,
F_61 ( V_91 ) ) ;
goto V_68;
}
F_14 ( V_31 L_10 ,
V_2 -> V_44 ,
V_32 ,
V_107 ,
V_85 ,
V_2 -> V_94 ,
V_9 -> V_44 ) ;
V_68:
return V_67 ;
}
static int F_67 ( struct V_71 * V_72 , struct V_73 * V_74 )
{
int V_67 = - V_108 ;
T_2 V_109 , V_110 ;
struct V_56 * V_57 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = F_50 ( V_72 ) ;
unsigned char V_58 = V_23 -> V_75 -> V_76 -> V_41 ;
if ( V_58 >= V_111 )
return V_67 ;
if ( ! V_40 [ V_58 ] . V_2 ) {
F_68 ( V_23 -> V_75 -> V_76 , V_112 ,
& V_109 ) ;
F_68 ( V_23 -> V_75 -> V_76 , V_113 ,
& V_110 ) ;
if ( ! F_69 ( V_109 , V_110 ) ) {
F_14 ( V_43
L_11 ,
V_32 , V_23 -> V_75 -> V_76 -> V_44 ) ;
goto V_68;
}
V_2 = F_70 ( sizeof( struct V_4 ) ) ;
if ( V_2 == NULL ) {
V_67 = - V_93 ;
goto V_68;
}
V_67 = F_59 ( V_23 -> V_75 -> V_76 , V_2 ) ;
if ( V_67 ) {
F_14 ( V_43 L_12 ,
V_32 , V_67 ) ;
F_71 ( V_2 ) ;
goto V_68;
}
F_72 ( & V_40 [ V_58 ] . V_114 ) ;
F_64 ( & V_40 [ V_58 ] . V_60 ) ;
V_40 [ V_58 ] . V_42 = 0 ;
V_40 [ V_58 ] . V_2 = V_2 ;
}
if ( F_51 ( V_23 ) ) {
struct V_4 * V_5 ;
unsigned long V_36 ;
V_5 = F_2 ( V_40 [ V_58 ] . V_2 ) ;
V_57 = F_73 ( sizeof( * V_57 ) , V_92 ) ;
if ( ! V_57 ) {
V_67 = - V_93 ;
goto V_68;
}
V_57 -> V_23 = V_23 ;
V_57 -> V_70 = F_74 ( V_57 -> V_23 ,
V_59 ,
V_61 ) ;
if ( ! V_57 -> V_70 ) {
F_75 ( L_13 , V_32 ) ;
F_54 ( V_57 ) ;
V_67 = - V_93 ;
goto V_68;
}
F_16 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
F_76 ( & V_57 -> V_79 , & V_40 [ V_58 ] . V_114 ) ;
F_18 ( & V_40 [ V_58 ] . V_60 , V_36 ) ;
F_77 ( L_14 ,
V_32 , V_115 , F_78 ( V_23 ) ) ;
if ( V_5 -> V_69 )
F_41 ( V_57 -> V_23 , V_59 ) ;
}
return 0 ;
V_68:
return V_67 ;
}
static int F_79 ( struct V_116 * V_117 , unsigned long V_118 ,
void * V_119 )
{
struct V_56 * V_57 ;
unsigned long V_36 ;
int V_3 ;
F_77 ( L_15 , V_32 , V_115 ) ;
for ( V_3 = 0 ; V_3 < V_111 ; V_3 ++ ) {
if ( ! V_40 [ V_3 ] . V_2 )
continue;
F_16 ( & V_40 [ V_3 ] . V_60 , V_36 ) ;
F_27 (peer, &nets[i].peers, node) {
if ( V_40 [ V_3 ] . V_48 [ V_57 -> V_23 -> V_35 ] ) {
F_41 ( V_57 -> V_23 ,
V_61 ) ;
V_40 [ V_3 ] . V_48 [ V_57 -> V_23 -> V_35 ] = NULL ;
}
}
F_18 ( & V_40 [ V_3 ] . V_60 , V_36 ) ;
}
return V_120 ;
}
static void F_80 ( struct V_71 * V_72 ,
struct V_121 * V_122 )
{
struct V_51 * V_9 = F_81 ( V_72 ) ;
struct V_1 * V_2 ;
int V_41 = V_9 -> V_41 ;
F_77 ( L_16 , V_115 , V_9 -> V_44 ) ;
F_82 ( V_40 [ V_41 ] . V_42 , L_17 ,
V_115 , V_40 [ V_41 ] . V_42 ) ;
F_82 ( ! V_40 [ V_41 ] . V_2 , L_18 ,
V_115 ) ;
if ( V_40 [ V_41 ] . V_2 ) {
V_2 = V_40 [ V_41 ] . V_2 ;
F_12 ( V_2 ) ;
F_83 ( V_2 ) ;
F_66 ( ( unsigned long ) V_40 [ V_41 ] . V_48 ,
F_61 ( sizeof( void * ) *
F_19 ( V_9 -> V_47 ) ) ) ;
V_40 [ V_41 ] . V_48 = NULL ;
F_71 ( V_2 ) ;
V_40 [ V_41 ] . V_2 = NULL ;
}
}
static int T_4 F_84 ( void )
{
int V_123 ;
V_123 = F_85 ( & V_124 ) ;
if ( V_123 ) {
F_75 ( L_19 ,
V_32 , V_123 ) ;
return V_123 ;
}
V_123 = F_86 ( & V_125 ) ;
if ( V_123 ) {
F_75 ( L_20 ,
V_32 , V_123 ) ;
return V_123 ;
}
return F_87 ( & V_126 ) ;
}
static void T_5 F_88 ( void )
{
F_89 ( & V_124 ) ;
F_90 ( & V_126 ) ;
F_91 ( & V_125 ) ;
}
