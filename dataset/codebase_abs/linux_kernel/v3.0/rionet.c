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
F_16 ( V_36 ) ;
if ( ! F_17 ( & V_5 -> V_37 ) ) {
F_18 ( V_36 ) ;
return V_38 ;
}
if ( ( V_5 -> V_29 + 1 ) > V_30 ) {
F_12 ( V_2 ) ;
F_19 ( & V_5 -> V_37 , V_36 ) ;
F_14 ( V_39 L_2 ,
V_2 -> V_40 ) ;
return V_41 ;
}
if ( V_34 -> V_42 [ 0 ] & 0x01 ) {
for ( V_3 = 0 ; V_3 < F_20 ( V_5 -> V_9 -> V_43 ) ;
V_3 ++ )
if ( V_44 [ V_3 ] )
F_10 ( V_21 , V_2 ,
V_44 [ V_3 ] ) ;
} else if ( F_21 ( V_34 -> V_42 ) ) {
V_35 = F_22 ( V_34 -> V_42 ) ;
if ( V_44 [ V_35 ] )
F_10 ( V_21 , V_2 , V_44 [ V_35 ] ) ;
}
F_19 ( & V_5 -> V_37 , V_36 ) ;
return V_45 ;
}
static void F_23 ( struct V_46 * V_9 , void * V_47 , T_1 V_48 , T_1 V_49 ,
T_1 V_50 )
{
struct V_1 * V_2 = V_47 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_51 * V_52 ;
if ( F_24 ( V_5 ) )
F_14 ( V_31 L_3 ,
V_32 , V_48 , V_49 , V_50 ) ;
if ( V_50 == V_53 ) {
if ( ! V_44 [ V_48 ] ) {
F_25 (peer, &rionet_peers, node) {
if ( V_52 -> V_23 -> V_35 == V_48 )
V_44 [ V_48 ] = V_52 -> V_23 ;
}
F_26 ( V_9 , V_48 ,
V_53 ) ;
}
} else if ( V_50 == V_54 ) {
V_44 [ V_48 ] = NULL ;
} else {
if ( F_24 ( V_5 ) )
F_14 ( V_55 L_4 ,
V_32 ) ;
}
}
static void F_27 ( struct V_46 * V_9 , void * V_47 , int V_56 , int V_57 )
{
int V_58 ;
struct V_1 * V_2 = V_47 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_24 ( V_5 ) )
F_14 ( V_31 L_5 ,
V_32 , V_56 , V_57 ) ;
F_28 ( & V_5 -> V_59 ) ;
if ( ( V_58 = F_1 ( V_2 ) ) != V_5 -> V_7 )
F_7 ( V_2 , V_58 ) ;
F_29 ( & V_5 -> V_59 ) ;
}
static void F_30 ( struct V_46 * V_9 , void * V_47 , int V_56 , int V_57 )
{
struct V_1 * V_2 = V_47 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_28 ( & V_5 -> V_59 ) ;
if ( F_24 ( V_5 ) )
F_14 ( V_31
L_6 ,
V_32 , V_56 , V_57 ) ;
while ( V_5 -> V_29 && ( V_5 -> V_60 != V_57 ) ) {
F_31 ( V_5 -> V_25 [ V_5 -> V_60 ] ) ;
V_5 -> V_25 [ V_5 -> V_60 ] = NULL ;
++ V_5 -> V_60 ;
V_5 -> V_60 &= ( V_30 - 1 ) ;
V_5 -> V_29 -- ;
}
if ( V_5 -> V_29 < V_30 )
F_32 ( V_2 ) ;
F_29 ( & V_5 -> V_59 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_3 , V_61 = 0 ;
struct V_51 * V_52 , * V_62 ;
T_2 V_63 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_34 ( V_5 ) )
F_14 ( V_31 L_7 , V_32 ) ;
if ( ( V_61 = F_35 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_53 ,
V_54 ,
F_23 ) ) < 0 )
goto V_64;
if ( ( V_61 = F_36 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_18 ,
F_27 ) ) < 0 )
goto V_64;
if ( ( V_61 = F_37 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_30 ,
F_30 ) ) < 0 )
goto V_64;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
V_5 -> V_8 [ V_3 ] = NULL ;
V_5 -> V_7 = 0 ;
F_7 ( V_2 , 0 ) ;
V_5 -> V_26 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_60 = 0 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 (peer, tmp, &rionet_peers, node) {
if ( ! ( V_52 -> V_65 = F_41 ( V_52 -> V_23 ,
V_53 ,
V_54 ) ) )
{
F_14 ( V_39 L_8 ,
V_32 ) ;
continue;
}
F_42 ( V_52 -> V_23 , V_66 , & V_63 ) ;
if ( V_63 & V_67 )
F_43 ( V_52 -> V_23 , V_53 ) ;
}
V_64:
return V_61 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_51 * V_52 , * V_62 ;
int V_3 ;
if ( F_34 ( V_5 ) )
F_14 ( V_31 L_9 , V_32 ) ;
F_12 ( V_2 ) ;
F_45 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_46 ( V_5 -> V_8 [ V_3 ] ) ;
F_40 (peer, tmp, &rionet_peers, node) {
if ( V_44 [ V_52 -> V_23 -> V_35 ] ) {
F_43 ( V_52 -> V_23 , V_54 ) ;
V_44 [ V_52 -> V_23 -> V_35 ] = NULL ;
}
F_47 ( V_52 -> V_23 , V_52 -> V_65 ) ;
}
F_48 ( V_5 -> V_9 , V_53 ,
V_54 ) ;
F_49 ( V_5 -> V_9 , V_10 ) ;
F_50 ( V_5 -> V_9 , V_10 ) ;
return 0 ;
}
static void F_51 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_52 ( V_23 ) ;
struct V_51 * V_52 , * V_62 ;
F_53 ( ( unsigned long ) V_44 , V_23 -> V_68 -> V_69 -> V_43 ?
F_54 ( sizeof( void * ) ) + 4 : 0 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_40 (peer, tmp, &rionet_peers, node) {
F_57 ( & V_52 -> V_70 ) ;
F_58 ( V_52 ) ;
}
}
static void F_59 ( struct V_1 * V_2 ,
struct V_71 * V_50 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
strcpy ( V_50 -> V_72 , V_32 ) ;
strcpy ( V_50 -> V_73 , V_74 ) ;
strcpy ( V_50 -> V_75 , L_10 ) ;
strcpy ( V_50 -> V_76 , V_5 -> V_9 -> V_40 ) ;
}
static T_2 F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_77 ;
}
static void F_61 ( struct V_1 * V_2 , T_2 V_78 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_77 = V_78 ;
}
static int F_62 ( struct V_46 * V_9 , struct V_1 * V_2 )
{
int V_61 = 0 ;
struct V_4 * V_5 ;
T_1 V_79 ;
V_44 = (struct V_22 * * ) F_63 ( V_80 ,
V_9 -> V_43 ? F_54 ( sizeof( void * ) ) + 4 : 0 ) ;
if ( ! V_44 ) {
V_61 = - V_81 ;
goto V_64;
}
memset ( ( void * ) V_44 , 0 , sizeof( void * ) *
F_20 ( V_9 -> V_43 ) ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_9 = V_9 ;
V_79 = F_64 ( V_9 ) ;
V_2 -> V_82 [ 0 ] = 0x00 ;
V_2 -> V_82 [ 1 ] = 0x01 ;
V_2 -> V_82 [ 2 ] = 0x00 ;
V_2 -> V_82 [ 3 ] = 0x01 ;
V_2 -> V_82 [ 4 ] = V_79 >> 8 ;
V_2 -> V_82 [ 5 ] = V_79 & 0xff ;
V_2 -> V_83 = & V_84 ;
V_2 -> V_85 = V_11 - 14 ;
V_2 -> V_86 = V_87 ;
F_65 ( V_2 , & V_88 ) ;
F_66 ( & V_5 -> V_59 ) ;
F_66 ( & V_5 -> V_37 ) ;
V_5 -> V_77 = V_89 ;
V_61 = F_67 ( V_2 ) ;
if ( V_61 != 0 )
goto V_64;
F_14 ( L_11 ,
V_2 -> V_40 ,
V_32 ,
V_90 ,
V_74 ,
V_2 -> V_82 ) ;
V_64:
return V_61 ;
}
static int F_68 ( struct V_22 * V_23 , const struct V_91 * V_92 )
{
int V_61 = - V_93 ;
T_2 V_94 , V_95 , V_96 ;
struct V_51 * V_52 ;
struct V_1 * V_2 = NULL ;
if ( ! V_97 )
goto V_64;
V_2 = F_69 ( sizeof( struct V_4 ) ) ;
if ( V_2 == NULL ) {
F_14 ( V_31 L_12 ,
V_32 ) ;
V_61 = - V_81 ;
goto V_64;
}
if ( ! V_98 ) {
F_70 ( V_23 -> V_68 -> V_69 , V_99 , & V_94 ) ;
F_70 ( V_23 -> V_68 -> V_69 , V_100 ,
& V_95 ) ;
F_70 ( V_23 -> V_68 -> V_69 , V_101 ,
& V_96 ) ;
if ( ! F_71 ( V_94 , V_95 , V_96 ) ) {
F_14 ( V_39
L_13 ,
V_32 ) ;
V_98 = 1 ;
V_97 = 0 ;
goto V_64;
}
V_61 = F_62 ( V_23 -> V_68 -> V_69 , V_2 ) ;
V_98 = 1 ;
}
if ( F_72 ( V_23 ) ) {
if ( ! ( V_52 = F_73 ( sizeof( struct V_51 ) , V_80 ) ) ) {
V_61 = - V_81 ;
goto V_64;
}
V_52 -> V_23 = V_23 ;
F_74 ( & V_52 -> V_70 , & V_102 ) ;
}
F_75 ( V_23 , V_2 ) ;
V_64:
return V_61 ;
}
static int T_3 F_76 ( void )
{
return F_77 ( & V_103 ) ;
}
static void T_4 F_78 ( void )
{
F_79 ( & V_103 ) ;
}
