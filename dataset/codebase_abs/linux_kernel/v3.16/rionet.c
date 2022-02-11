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
if ( F_27 ( V_5 ) )
F_14 ( V_31 L_3 ,
V_32 , V_54 , V_55 , V_56 ) ;
if ( V_56 == V_59 ) {
if ( ! V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_54 ] ) {
F_28 (peer,
&nets[rnet->mport->id].peers, node) {
if ( V_58 -> V_23 -> V_35 == V_54 ) {
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_54 ] =
V_58 -> V_23 ;
V_41 [ V_5 -> V_9 -> V_42 ] . V_43 ++ ;
}
}
F_29 ( V_9 , V_54 ,
V_59 ) ;
}
} else if ( V_56 == V_60 ) {
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_54 ] = NULL ;
V_41 [ V_5 -> V_9 -> V_42 ] . V_43 -- ;
} else {
if ( F_27 ( V_5 ) )
F_14 ( V_61 L_4 ,
V_32 ) ;
}
}
static void F_30 ( struct V_52 * V_9 , void * V_53 , int V_62 , int V_63 )
{
int V_64 ;
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_27 ( V_5 ) )
F_14 ( V_31 L_5 ,
V_32 , V_62 , V_63 ) ;
F_31 ( & V_5 -> V_65 ) ;
if ( ( V_64 = F_1 ( V_2 ) ) != V_5 -> V_7 )
F_7 ( V_2 , V_64 ) ;
F_32 ( & V_5 -> V_65 ) ;
}
static void F_33 ( struct V_52 * V_9 , void * V_53 , int V_62 , int V_63 )
{
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_31 ( & V_5 -> V_65 ) ;
if ( F_27 ( V_5 ) )
F_14 ( V_31
L_6 ,
V_32 , V_62 , V_63 ) ;
while ( V_5 -> V_29 && ( V_5 -> V_66 != V_63 ) ) {
F_34 ( V_5 -> V_25 [ V_5 -> V_66 ] ) ;
V_5 -> V_25 [ V_5 -> V_66 ] = NULL ;
++ V_5 -> V_66 ;
V_5 -> V_66 &= ( V_30 - 1 ) ;
V_5 -> V_29 -- ;
}
if ( V_5 -> V_29 < V_30 )
F_35 ( V_2 ) ;
F_32 ( & V_5 -> V_65 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_3 , V_67 = 0 ;
struct V_57 * V_58 , * V_68 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_37 ( V_5 ) )
F_14 ( V_31 L_7 , V_32 ) ;
if ( ( V_67 = F_38 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_59 ,
V_60 ,
F_26 ) ) < 0 )
goto V_69;
if ( ( V_67 = F_39 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_18 ,
F_30 ) ) < 0 )
goto V_69;
if ( ( V_67 = F_40 ( V_5 -> V_9 ,
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
V_5 -> V_66 = 0 ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 (peer, tmp,
&nets[rnet->mport->id].peers, node) {
if ( ! ( V_58 -> V_70 = F_44 ( V_58 -> V_23 ,
V_59 ,
V_60 ) ) )
{
F_14 ( V_44 L_8 ,
V_32 ) ;
continue;
}
F_45 ( V_58 -> V_23 , V_59 ) ;
}
V_69:
return V_67 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_57 * V_58 , * V_68 ;
int V_3 ;
if ( F_37 ( V_5 ) )
F_14 ( V_31 L_9 , V_32 , V_2 -> V_45 ) ;
F_12 ( V_2 ) ;
F_47 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_48 ( V_5 -> V_8 [ V_3 ] ) ;
F_43 (peer, tmp,
&nets[rnet->mport->id].peers, node) {
if ( V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_58 -> V_23 -> V_35 ] ) {
F_45 ( V_58 -> V_23 , V_60 ) ;
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_58 -> V_23 -> V_35 ] = NULL ;
}
F_49 ( V_58 -> V_23 , V_58 -> V_70 ) ;
}
F_50 ( V_5 -> V_9 , V_59 ,
V_60 ) ;
F_51 ( V_5 -> V_9 , V_10 ) ;
F_52 ( V_5 -> V_9 , V_10 ) ;
return 0 ;
}
static int F_53 ( struct V_71 * V_72 , struct V_73 * V_74 )
{
struct V_22 * V_23 = F_54 ( V_72 ) ;
unsigned char V_75 = V_23 -> V_76 -> V_77 -> V_42 ;
struct V_57 * V_58 , * V_68 ;
if ( F_55 ( V_23 ) ) {
F_43 (peer, tmp, &nets[netid].peers, node) {
if ( V_58 -> V_23 == V_23 ) {
if ( V_41 [ V_75 ] . V_49 [ V_23 -> V_35 ] ) {
V_41 [ V_75 ] . V_49 [ V_23 -> V_35 ] = NULL ;
V_41 [ V_75 ] . V_43 -- ;
}
F_56 ( & V_58 -> V_78 ) ;
F_57 ( V_58 ) ;
break;
}
}
}
return 0 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_79 * V_56 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_59 ( V_56 -> V_80 , V_32 , sizeof( V_56 -> V_80 ) ) ;
F_59 ( V_56 -> V_81 , V_82 , sizeof( V_56 -> V_81 ) ) ;
F_59 ( V_56 -> V_83 , L_10 , sizeof( V_56 -> V_83 ) ) ;
F_59 ( V_56 -> V_84 , V_5 -> V_9 -> V_45 , sizeof( V_56 -> V_84 ) ) ;
}
static T_2 F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_85 ;
}
static void F_61 ( struct V_1 * V_2 , T_2 V_86 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_85 = V_86 ;
}
static int F_62 ( struct V_52 * V_9 , struct V_1 * V_2 )
{
int V_67 = 0 ;
struct V_4 * V_5 ;
T_1 V_87 ;
const T_3 V_88 = sizeof( void * ) *
F_21 ( V_9 -> V_48 ) ;
V_41 [ V_9 -> V_42 ] . V_49 = (struct V_22 * * ) F_63 ( V_89 ,
F_64 ( V_88 ) ) ;
if ( ! V_41 [ V_9 -> V_42 ] . V_49 ) {
V_67 = - V_90 ;
goto V_69;
}
memset ( ( void * ) V_41 [ V_9 -> V_42 ] . V_49 , 0 , V_88 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_9 = V_9 ;
V_87 = F_65 ( V_9 ) ;
V_2 -> V_91 [ 0 ] = 0x00 ;
V_2 -> V_91 [ 1 ] = 0x01 ;
V_2 -> V_91 [ 2 ] = 0x00 ;
V_2 -> V_91 [ 3 ] = 0x01 ;
V_2 -> V_91 [ 4 ] = V_87 >> 8 ;
V_2 -> V_91 [ 5 ] = V_87 & 0xff ;
V_2 -> V_92 = & V_93 ;
V_2 -> V_94 = V_11 - 14 ;
V_2 -> V_95 = V_96 ;
F_66 ( V_2 , & V_9 -> V_72 ) ;
V_2 -> V_97 = & V_98 ;
F_67 ( & V_5 -> V_65 ) ;
F_67 ( & V_5 -> V_38 ) ;
V_5 -> V_85 = V_99 ;
V_67 = F_68 ( V_2 ) ;
if ( V_67 != 0 )
goto V_69;
F_14 ( V_31 L_11 ,
V_2 -> V_45 ,
V_32 ,
V_100 ,
V_82 ,
V_2 -> V_91 ,
V_9 -> V_45 ) ;
V_69:
return V_67 ;
}
static int F_69 ( struct V_71 * V_72 , struct V_73 * V_74 )
{
int V_67 = - V_101 ;
T_2 V_102 , V_103 ;
struct V_57 * V_58 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = F_54 ( V_72 ) ;
unsigned char V_75 = V_23 -> V_76 -> V_77 -> V_42 ;
int V_104 ;
if ( V_75 >= V_105 )
return V_67 ;
V_104 = F_70 ( V_75 , V_106 ) ;
if ( ! V_104 ) {
F_71 ( V_23 -> V_76 -> V_77 , V_107 ,
& V_102 ) ;
F_71 ( V_23 -> V_76 -> V_77 , V_108 ,
& V_103 ) ;
if ( ! F_72 ( V_102 , V_103 ) ) {
F_14 ( V_44
L_12 ,
V_32 , V_23 -> V_76 -> V_77 -> V_45 ) ;
goto V_69;
}
V_2 = F_73 ( sizeof( struct V_4 ) ) ;
if ( V_2 == NULL ) {
V_67 = - V_90 ;
goto V_69;
}
V_41 [ V_75 ] . V_2 = V_2 ;
V_67 = F_62 ( V_23 -> V_76 -> V_77 , V_2 ) ;
if ( V_67 ) {
F_14 ( V_44 L_13 ,
V_32 , V_67 ) ;
goto V_69;
}
F_74 ( & V_41 [ V_75 ] . V_109 ) ;
V_41 [ V_75 ] . V_43 = 0 ;
} else if ( V_41 [ V_75 ] . V_2 == NULL )
goto V_69;
if ( F_55 ( V_23 ) ) {
if ( ! ( V_58 = F_75 ( sizeof( struct V_57 ) , V_89 ) ) ) {
V_67 = - V_90 ;
goto V_69;
}
V_58 -> V_23 = V_23 ;
F_76 ( & V_58 -> V_78 , & V_41 [ V_75 ] . V_109 ) ;
}
return 0 ;
V_69:
return V_67 ;
}
static int T_4 F_77 ( void )
{
return F_78 ( & V_110 ) ;
}
static void T_5 F_79 ( void )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_57 * V_58 , * V_68 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_105 ; V_3 ++ ) {
if ( V_41 [ V_3 ] . V_2 != NULL ) {
V_2 = V_41 [ V_3 ] . V_2 ;
V_5 = F_2 ( V_2 ) ;
F_80 ( V_2 ) ;
F_43 (peer,
tmp, &nets[i].peers, node) {
F_56 ( & V_58 -> V_78 ) ;
F_57 ( V_58 ) ;
}
F_81 ( ( unsigned long ) V_41 [ V_3 ] . V_49 ,
F_64 ( sizeof( void * ) *
F_21 ( V_5 -> V_9 -> V_48 ) ) ) ;
V_41 [ V_3 ] . V_49 = NULL ;
F_82 ( V_2 ) ;
}
}
F_83 ( & V_110 ) ;
}
