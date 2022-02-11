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
}
F_20 ( & V_5 -> V_38 , V_36 ) ;
return V_51 ;
}
static void F_25 ( struct V_52 * V_9 , void * V_53 , T_1 V_54 , T_1 V_55 ,
T_1 V_56 )
{
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_57 * V_58 ;
if ( F_26 ( V_5 ) )
F_14 ( V_31 L_3 ,
V_32 , V_54 , V_55 , V_56 ) ;
if ( V_56 == V_59 ) {
if ( ! V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_54 ] ) {
F_27 (peer,
&nets[rnet->mport->id].peers, node) {
if ( V_58 -> V_23 -> V_35 == V_54 ) {
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_54 ] =
V_58 -> V_23 ;
V_41 [ V_5 -> V_9 -> V_42 ] . V_43 ++ ;
}
}
F_28 ( V_9 , V_54 ,
V_59 ) ;
}
} else if ( V_56 == V_60 ) {
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_54 ] = NULL ;
V_41 [ V_5 -> V_9 -> V_42 ] . V_43 -- ;
} else {
if ( F_26 ( V_5 ) )
F_14 ( V_61 L_4 ,
V_32 ) ;
}
}
static void F_29 ( struct V_52 * V_9 , void * V_53 , int V_62 , int V_63 )
{
int V_64 ;
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_26 ( V_5 ) )
F_14 ( V_31 L_5 ,
V_32 , V_62 , V_63 ) ;
F_30 ( & V_5 -> V_65 ) ;
if ( ( V_64 = F_1 ( V_2 ) ) != V_5 -> V_7 )
F_7 ( V_2 , V_64 ) ;
F_31 ( & V_5 -> V_65 ) ;
}
static void F_32 ( struct V_52 * V_9 , void * V_53 , int V_62 , int V_63 )
{
struct V_1 * V_2 = V_53 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_30 ( & V_5 -> V_65 ) ;
if ( F_26 ( V_5 ) )
F_14 ( V_31
L_6 ,
V_32 , V_62 , V_63 ) ;
while ( V_5 -> V_29 && ( V_5 -> V_66 != V_63 ) ) {
F_33 ( V_5 -> V_25 [ V_5 -> V_66 ] ) ;
V_5 -> V_25 [ V_5 -> V_66 ] = NULL ;
++ V_5 -> V_66 ;
V_5 -> V_66 &= ( V_30 - 1 ) ;
V_5 -> V_29 -- ;
}
if ( V_5 -> V_29 < V_30 )
F_34 ( V_2 ) ;
F_31 ( & V_5 -> V_65 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_3 , V_67 = 0 ;
struct V_57 * V_58 , * V_68 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_36 ( V_5 ) )
F_14 ( V_31 L_7 , V_32 ) ;
if ( ( V_67 = F_37 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_59 ,
V_60 ,
F_25 ) ) < 0 )
goto V_69;
if ( ( V_67 = F_38 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_18 ,
F_29 ) ) < 0 )
goto V_69;
if ( ( V_67 = F_39 ( V_5 -> V_9 ,
( void * ) V_2 ,
V_10 ,
V_30 ,
F_32 ) ) < 0 )
goto V_69;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
V_5 -> V_8 [ V_3 ] = NULL ;
V_5 -> V_7 = 0 ;
F_7 ( V_2 , 0 ) ;
V_5 -> V_26 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_66 = 0 ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 (peer, tmp,
&nets[rnet->mport->id].peers, node) {
if ( ! ( V_58 -> V_70 = F_43 ( V_58 -> V_23 ,
V_59 ,
V_60 ) ) )
{
F_14 ( V_44 L_8 ,
V_32 ) ;
continue;
}
F_44 ( V_58 -> V_23 , V_59 ) ;
}
V_69:
return V_67 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_57 * V_58 , * V_68 ;
int V_3 ;
if ( F_36 ( V_5 ) )
F_14 ( V_31 L_9 , V_32 , V_2 -> V_45 ) ;
F_12 ( V_2 ) ;
F_46 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_47 ( V_5 -> V_8 [ V_3 ] ) ;
F_42 (peer, tmp,
&nets[rnet->mport->id].peers, node) {
if ( V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_58 -> V_23 -> V_35 ] ) {
F_44 ( V_58 -> V_23 , V_60 ) ;
V_41 [ V_5 -> V_9 -> V_42 ] . V_49 [ V_58 -> V_23 -> V_35 ] = NULL ;
}
F_48 ( V_58 -> V_23 , V_58 -> V_70 ) ;
}
F_49 ( V_5 -> V_9 , V_59 ,
V_60 ) ;
F_50 ( V_5 -> V_9 , V_10 ) ;
F_51 ( V_5 -> V_9 , V_10 ) ;
return 0 ;
}
static void F_52 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_53 ( V_23 ) ;
unsigned char V_71 = V_23 -> V_72 -> V_73 -> V_42 ;
struct V_57 * V_58 , * V_68 ;
F_54 ( V_2 ) ;
F_55 ( ( unsigned long ) V_41 [ V_71 ] . V_49 , F_56 ( sizeof( void * ) *
F_21 ( V_23 -> V_72 -> V_73 -> V_48 ) ) ) ;
V_41 [ V_71 ] . V_49 = NULL ;
F_42 (peer, tmp, &nets[netid].peers, node) {
F_57 ( & V_58 -> V_74 ) ;
F_58 ( V_58 ) ;
}
F_59 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_75 * V_56 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
strcpy ( V_56 -> V_76 , V_32 ) ;
strcpy ( V_56 -> V_77 , V_78 ) ;
strcpy ( V_56 -> V_79 , L_10 ) ;
strcpy ( V_56 -> V_80 , V_5 -> V_9 -> V_45 ) ;
}
static T_2 F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_81 ;
}
static void F_62 ( struct V_1 * V_2 , T_2 V_82 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_81 = V_82 ;
}
static int F_63 ( struct V_52 * V_9 , struct V_1 * V_2 )
{
int V_67 = 0 ;
struct V_4 * V_5 ;
T_1 V_83 ;
const T_3 V_84 = sizeof( void * ) *
F_21 ( V_9 -> V_48 ) ;
V_41 [ V_9 -> V_42 ] . V_49 = (struct V_22 * * ) F_64 ( V_85 ,
F_56 ( V_84 ) ) ;
if ( ! V_41 [ V_9 -> V_42 ] . V_49 ) {
V_67 = - V_86 ;
goto V_69;
}
memset ( ( void * ) V_41 [ V_9 -> V_42 ] . V_49 , 0 , V_84 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_9 = V_9 ;
V_83 = F_65 ( V_9 ) ;
V_2 -> V_87 [ 0 ] = 0x00 ;
V_2 -> V_87 [ 1 ] = 0x01 ;
V_2 -> V_87 [ 2 ] = 0x00 ;
V_2 -> V_87 [ 3 ] = 0x01 ;
V_2 -> V_87 [ 4 ] = V_83 >> 8 ;
V_2 -> V_87 [ 5 ] = V_83 & 0xff ;
V_2 -> V_88 = & V_89 ;
V_2 -> V_90 = V_11 - 14 ;
V_2 -> V_91 = V_92 ;
F_66 ( V_2 , & V_93 ) ;
F_67 ( & V_5 -> V_65 ) ;
F_67 ( & V_5 -> V_38 ) ;
V_5 -> V_81 = V_94 ;
V_67 = F_68 ( V_2 ) ;
if ( V_67 != 0 )
goto V_69;
F_14 ( V_31 L_11 ,
V_2 -> V_45 ,
V_32 ,
V_95 ,
V_78 ,
V_2 -> V_87 ,
V_9 -> V_45 ) ;
V_69:
return V_67 ;
}
static int F_69 ( struct V_22 * V_23 , const struct V_96 * V_42 )
{
int V_67 = - V_97 ;
T_2 V_98 , V_99 ;
struct V_57 * V_58 ;
struct V_1 * V_2 = NULL ;
unsigned char V_71 = V_23 -> V_72 -> V_73 -> V_42 ;
int V_100 ;
if ( V_71 >= V_101 )
return V_67 ;
V_100 = F_70 ( V_71 , V_102 ) ;
if ( ! V_100 ) {
F_71 ( V_23 -> V_72 -> V_73 , V_103 ,
& V_98 ) ;
F_71 ( V_23 -> V_72 -> V_73 , V_104 ,
& V_99 ) ;
if ( ! F_72 ( V_98 , V_99 ) ) {
F_14 ( V_44
L_12 ,
V_32 , V_23 -> V_72 -> V_73 -> V_45 ) ;
goto V_69;
}
V_2 = F_73 ( sizeof( struct V_4 ) ) ;
if ( V_2 == NULL ) {
V_67 = - V_86 ;
goto V_69;
}
V_41 [ V_71 ] . V_2 = V_2 ;
V_67 = F_63 ( V_23 -> V_72 -> V_73 , V_2 ) ;
F_74 ( & V_41 [ V_71 ] . V_105 ) ;
V_41 [ V_71 ] . V_43 = 0 ;
} else if ( V_41 [ V_71 ] . V_2 == NULL )
goto V_69;
if ( F_75 ( V_23 ) ) {
if ( ! ( V_58 = F_76 ( sizeof( struct V_57 ) , V_85 ) ) ) {
V_67 = - V_86 ;
goto V_69;
}
V_58 -> V_23 = V_23 ;
F_77 ( & V_58 -> V_74 , & V_41 [ V_71 ] . V_105 ) ;
}
F_78 ( V_23 , V_41 [ V_71 ] . V_2 ) ;
V_69:
return V_67 ;
}
static int T_4 F_79 ( void )
{
return F_80 ( & V_106 ) ;
}
static void T_5 F_81 ( void )
{
F_82 ( & V_106 ) ;
}
