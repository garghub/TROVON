void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL ) {
F_2 ( L_1 , V_3 ) ;
return;
}
F_2 ( L_2
L_3
L_4
L_5 ,
F_3 ( V_2 -> V_4 ) , F_4 ( V_2 -> V_5 ) ,
F_5 ( & V_2 -> V_6 ) , V_2 -> V_7 ,
V_2 -> V_7 ? V_2 -> V_7 -> V_8 : 0 ) ;
}
static struct V_1 *
F_6 ( T_1 V_9 , T_1 V_10 )
{
struct V_1 * V_2 ;
F_7 ( L_6 ,
F_3 ( V_9 ) , F_4 ( V_10 ) ) ;
F_8 (ds, &nfs4_data_server_cache, ds_node) {
if ( V_2 -> V_4 == V_9 &&
V_2 -> V_5 == V_10 ) {
return V_2 ;
}
}
return NULL ;
}
static int
F_9 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_15 sin ;
int V_16 = 0 ;
F_7 ( L_7 , V_3 ,
F_3 ( V_2 -> V_4 ) , F_4 ( V_2 -> V_5 ) ,
V_12 -> V_13 -> V_17 -> V_18 -> V_19 ) ;
sin . V_20 = V_21 ;
sin . V_22 . V_23 = V_2 -> V_4 ;
sin . V_24 = V_2 -> V_5 ;
V_14 = F_10 ( V_12 -> V_13 , (struct V_25 * ) & sin ,
sizeof( sin ) , V_26 ) ;
if ( F_11 ( V_14 ) ) {
V_16 = F_12 ( V_14 ) ;
goto V_27;
}
if ( ( V_14 -> V_8 & V_28 ) != 0 ) {
if ( ! F_13 ( V_14 ) ) {
V_16 = - V_29 ;
goto V_30;
}
V_2 -> V_7 = V_14 ;
F_7 ( L_8 , V_3 ,
F_3 ( V_2 -> V_4 ) , F_4 ( V_2 -> V_5 ) ) ;
goto V_27;
}
F_14 ( & V_12 -> V_13 -> V_31 ) ;
V_14 -> V_32 = V_12 -> V_13 -> V_32 ;
F_15 ( & V_12 -> V_13 -> V_31 ) ;
V_14 -> V_33 = V_34 ;
V_16 = F_16 ( V_14 ) ;
if ( V_16 )
goto V_30;
V_2 -> V_7 = V_14 ;
F_7 ( L_9 , V_3 , F_3 ( V_2 -> V_4 ) ,
F_4 ( V_2 -> V_5 ) ) ;
V_27:
return V_16 ;
V_30:
F_17 ( V_14 ) ;
goto V_27;
}
static void
F_18 ( struct V_1 * V_2 )
{
F_7 ( L_10 , V_3 ) ;
F_19 (FACILITY)
F_1 ( V_2 ) ;
if ( V_2 -> V_7 )
F_17 ( V_2 -> V_7 ) ;
F_20 ( V_2 ) ;
}
void
F_21 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
int V_37 ;
F_22 ( & V_36 -> V_38 . V_39 ) ;
for ( V_37 = 0 ; V_37 < V_36 -> V_40 ; V_37 ++ ) {
V_2 = V_36 -> V_41 [ V_37 ] ;
if ( V_2 != NULL ) {
if ( F_23 ( & V_2 -> V_6 ,
& V_42 ) ) {
F_24 ( & V_2 -> V_43 ) ;
F_15 ( & V_42 ) ;
F_18 ( V_2 ) ;
}
}
}
F_20 ( V_36 -> V_44 ) ;
F_20 ( V_36 ) ;
}
static struct V_1 *
F_25 ( struct V_45 * V_45 , T_1 V_9 , T_1 V_10 , T_2 V_46 )
{
struct V_1 * V_47 , * V_2 ;
V_2 = F_26 ( sizeof( * V_47 ) , V_46 ) ;
if ( ! V_2 )
goto V_27;
F_14 ( & V_42 ) ;
V_47 = F_6 ( V_9 , V_10 ) ;
if ( V_47 == NULL ) {
V_2 -> V_4 = V_9 ;
V_2 -> V_5 = V_10 ;
F_27 ( & V_2 -> V_6 , 1 ) ;
F_28 ( & V_2 -> V_43 ) ;
V_2 -> V_7 = NULL ;
F_29 ( & V_2 -> V_43 , & V_48 ) ;
F_7 ( L_11 , V_3 ,
V_2 -> V_4 ) ;
} else {
F_20 ( V_2 ) ;
F_30 ( & V_47 -> V_6 ) ;
F_7 ( L_12 ,
V_3 , V_47 -> V_4 ,
F_5 ( & V_47 -> V_6 ) ) ;
V_2 = V_47 ;
}
F_15 ( & V_42 ) ;
V_27:
return V_2 ;
}
static struct V_1 *
F_31 ( struct V_49 * V_50 , struct V_45 * V_45 , T_2 V_46 )
{
struct V_1 * V_2 = NULL ;
char * V_51 ;
const char * V_52 , * V_53 ;
T_1 V_9 , V_10 ;
int V_54 , V_55 , V_37 ;
int V_56 [ 2 ] ;
T_3 * V_57 ;
V_57 = F_32 ( V_50 , 4 ) ;
if ( F_33 ( ! V_57 ) )
goto V_58;
V_54 = F_34 ( V_57 ++ ) ;
V_57 = F_32 ( V_50 , V_54 ) ;
if ( F_33 ( ! V_57 ) )
goto V_58;
if ( V_54 != 3 || memcmp ( ( char * ) V_57 , L_13 , 3 ) ) {
F_7 ( L_14 , V_3 ) ;
goto V_58;
}
V_57 = F_32 ( V_50 , 4 ) ;
if ( F_33 ( ! V_57 ) )
goto V_58;
V_55 = F_34 ( V_57 ) ;
V_57 = F_32 ( V_50 , V_55 ) ;
if ( F_33 ( ! V_57 ) )
goto V_58;
if ( V_55 > V_59 + 8 ) {
F_7 ( L_15 , V_3 ,
V_55 ) ;
goto V_58;
}
V_51 = F_35 ( V_55 + 1 , V_46 ) ;
if ( ! V_51 ) {
F_7 ( L_16 , V_3 ) ;
goto V_58;
}
V_51 [ V_55 ] = '\0' ;
memcpy ( V_51 , V_57 , V_55 ) ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
char * V_60 = strrchr ( V_51 , '.' ) ;
if ( ! V_60 ) {
F_7 ( L_17 ,
V_3 ) ;
goto V_61;
}
* V_60 = '-' ;
}
if ( F_36 ( V_51 , V_55 , ( V_62 * ) & V_9 , '-' , & V_52 ) == 0 ) {
F_7 ( L_18 , V_3 ) ;
goto V_61;
}
V_53 = V_52 ;
sscanf ( V_53 , L_19 , & V_56 [ 0 ] , & V_56 [ 1 ] ) ;
V_10 = F_37 ( ( V_56 [ 0 ] << 8 ) | ( V_56 [ 1 ] ) ) ;
V_2 = F_25 ( V_45 , V_9 , V_10 , V_46 ) ;
F_7 ( L_20 , V_3 , V_51 ) ;
V_61:
F_20 ( V_51 ) ;
V_58:
return V_2 ;
}
static struct V_35 *
F_38 ( struct V_45 * V_63 , struct V_64 * V_65 , T_2 V_46 )
{
int V_37 ;
T_1 V_66 , V_67 ;
V_62 * V_68 ;
T_3 * V_57 ;
V_62 * V_44 ;
V_62 V_69 ;
struct V_35 * V_36 = NULL ;
struct V_49 V_70 ;
struct V_71 V_51 ;
struct V_72 * V_73 ;
V_73 = F_39 ( V_46 ) ;
if ( ! V_73 )
goto V_58;
F_40 ( & V_70 , & V_51 , V_65 -> V_74 , V_65 -> V_75 ) ;
F_41 ( & V_70 , F_42 ( V_73 ) , V_76 ) ;
V_57 = F_32 ( & V_70 , 4 ) ;
if ( F_33 ( ! V_57 ) )
goto V_77;
V_66 = F_34 ( V_57 ) ;
F_7 ( L_21 , V_3 , V_66 ) ;
if ( V_66 > V_78 ) {
F_2 ( V_79 L_22
L_23 , V_3 ,
V_66 , V_78 ) ;
goto V_77;
}
V_44 = F_43 ( V_66 , sizeof( V_62 ) , V_46 ) ;
if ( ! V_44 )
goto V_77;
V_57 = F_32 ( & V_70 , V_66 << 2 ) ;
if ( F_33 ( ! V_57 ) )
goto V_80;
V_68 = & V_44 [ 0 ] ;
V_69 = 0 ;
for ( V_37 = 0 ; V_37 < V_66 ; V_37 ++ ) {
* V_68 = F_34 ( V_57 ++ ) ;
V_69 = F_44 ( V_69 , * V_68 ) ;
V_68 ++ ;
}
V_57 = F_32 ( & V_70 , 4 ) ;
if ( F_33 ( ! V_57 ) )
goto V_80;
V_67 = F_34 ( V_57 ) ;
F_7 ( L_24 , V_3 , V_67 ) ;
if ( V_67 > V_81 ) {
F_2 ( V_79 L_25
L_23 , V_3 ,
V_67 , V_81 ) ;
goto V_80;
}
if ( V_69 >= V_67 ) {
F_2 ( V_79 L_26 ,
V_3 , V_69 , V_67 ) ;
goto V_80;
}
V_36 = F_26 ( sizeof( * V_36 ) +
( sizeof( struct V_1 * ) * ( V_67 - 1 ) ) ,
V_46 ) ;
if ( ! V_36 )
goto V_80;
V_36 -> V_82 = V_66 ;
V_36 -> V_44 = V_44 ;
V_44 = NULL ;
V_36 -> V_40 = V_67 ;
F_45 ( & V_36 -> V_38 ,
F_46 ( V_63 ) -> V_83 ,
F_46 ( V_63 ) -> V_13 ,
& V_65 -> V_84 ) ;
for ( V_37 = 0 ; V_37 < V_36 -> V_40 ; V_37 ++ ) {
int V_85 ;
T_1 V_86 ;
V_57 = F_32 ( & V_70 , 4 ) ;
if ( F_33 ( ! V_57 ) )
goto V_87;
V_86 = F_34 ( V_57 ) ;
if ( V_86 > 1 ) {
F_2 ( V_79
L_27
L_28 , V_3 ,
V_86 ) ;
}
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ ) {
if ( V_85 == 0 ) {
V_36 -> V_41 [ V_37 ] = F_31 ( & V_70 ,
V_63 , V_46 ) ;
if ( V_36 -> V_41 [ V_37 ] == NULL )
goto V_87;
} else {
T_1 V_88 ;
V_57 = F_32 ( & V_70 , 4 ) ;
if ( F_33 ( ! V_57 ) )
goto V_87;
V_88 = F_34 ( V_57 ) ;
V_57 = F_32 ( & V_70 , V_88 ) ;
if ( F_33 ( ! V_57 ) )
goto V_87;
V_57 = F_32 ( & V_70 , 4 ) ;
if ( F_33 ( ! V_57 ) )
goto V_87;
V_88 = F_34 ( V_57 ) ;
V_57 = F_32 ( & V_70 , V_88 ) ;
if ( F_33 ( ! V_57 ) )
goto V_87;
}
}
}
F_47 ( V_73 ) ;
return V_36 ;
V_87:
F_21 ( V_36 ) ;
goto V_77;
V_80:
F_20 ( V_44 ) ;
V_77:
F_47 ( V_73 ) ;
V_58:
F_7 ( L_29 , V_3 ) ;
return NULL ;
}
static struct V_35 *
F_48 ( struct V_45 * V_45 , struct V_64 * V_89 , T_2 V_46 )
{
struct V_90 * V_91 ;
struct V_35 * V_92 , * V_93 ;
V_93 = F_38 ( V_45 , V_89 , V_46 ) ;
if ( ! V_93 ) {
F_2 ( V_79 L_30 ,
V_3 ) ;
return NULL ;
}
V_91 = F_49 ( & V_93 -> V_38 ) ;
V_92 = F_50 ( V_91 , struct V_35 , V_38 ) ;
if ( V_92 != V_93 ) {
F_21 ( V_93 ) ;
return V_92 ;
}
return V_93 ;
}
struct V_35 *
F_51 ( struct V_45 * V_45 , struct V_94 * V_84 , T_2 V_46 )
{
struct V_64 * V_65 = NULL ;
T_1 V_95 ;
int V_96 ;
struct V_72 * * V_74 = NULL ;
struct V_35 * V_36 = NULL ;
int V_97 , V_37 ;
struct V_11 * V_98 = F_46 ( V_45 ) ;
V_95 = V_98 -> V_13 -> V_99 -> V_100 . V_95 ;
V_96 = V_95 >> V_101 ;
F_7 ( L_31 ,
V_3 , V_45 , V_95 , V_96 ) ;
V_65 = F_26 ( sizeof( struct V_64 ) , V_46 ) ;
if ( V_65 == NULL )
return NULL ;
V_74 = F_26 ( V_96 * sizeof( struct V_72 * ) , V_46 ) ;
if ( V_74 == NULL ) {
F_20 ( V_65 ) ;
return NULL ;
}
for ( V_37 = 0 ; V_37 < V_96 ; V_37 ++ ) {
V_74 [ V_37 ] = F_39 ( V_46 ) ;
if ( ! V_74 [ V_37 ] )
goto V_61;
}
memcpy ( & V_65 -> V_84 , V_84 , sizeof( * V_84 ) ) ;
V_65 -> V_102 = V_103 ;
V_65 -> V_74 = V_74 ;
V_65 -> V_104 = 0 ;
V_65 -> V_75 = V_76 * V_96 ;
V_65 -> V_105 = 0 ;
V_97 = F_52 ( V_98 , V_65 ) ;
F_7 ( L_32 , V_3 , V_97 ) ;
if ( V_97 )
goto V_61;
V_36 = F_48 ( V_45 , V_65 , V_46 ) ;
V_61:
for ( V_37 = 0 ; V_37 < V_96 ; V_37 ++ )
F_47 ( V_74 [ V_37 ] ) ;
F_20 ( V_74 ) ;
F_20 ( V_65 ) ;
F_7 ( L_33 , V_3 , V_36 ) ;
return V_36 ;
}
void
F_53 ( struct V_35 * V_36 )
{
F_54 ( & V_36 -> V_38 ) ;
}
T_1
F_55 ( struct V_106 * V_107 , T_4 V_108 )
{
struct V_109 * V_110 = F_56 ( V_107 ) ;
T_5 V_56 ;
V_56 = V_108 - V_110 -> V_111 ;
F_57 ( V_56 , V_110 -> V_112 ) ;
V_56 += V_110 -> V_113 ;
return F_57 ( V_56 , V_110 -> V_36 -> V_82 ) ;
}
T_1
F_58 ( struct V_106 * V_107 , T_1 V_85 )
{
return F_56 ( V_107 ) -> V_36 -> V_44 [ V_85 ] ;
}
struct V_114 *
F_59 ( struct V_106 * V_107 , T_1 V_85 )
{
struct V_109 * V_110 = F_56 ( V_107 ) ;
T_1 V_37 ;
if ( V_110 -> V_115 == V_116 ) {
if ( V_110 -> V_117 == 1 )
V_37 = 0 ;
else if ( V_110 -> V_117 == 0 )
return NULL ;
else
V_37 = F_58 ( V_107 , V_85 ) ;
} else
V_37 = V_85 ;
return V_110 -> V_118 [ V_37 ] ;
}
static void
F_60 ( struct V_35 * V_36 ,
int V_119 , T_1 V_120 )
{
T_1 * V_57 = ( T_1 * ) & V_36 -> V_38 . V_39 ;
F_2 ( V_121 L_34
L_35 ,
V_120 , V_119 , V_57 [ 0 ] , V_57 [ 1 ] , V_57 [ 2 ] , V_57 [ 3 ] ) ;
F_14 ( & V_42 ) ;
V_36 -> V_122 |= V_123 ;
F_15 ( & V_42 ) ;
}
struct V_1 *
F_61 ( struct V_106 * V_107 , T_1 V_124 )
{
struct V_35 * V_36 = F_56 ( V_107 ) -> V_36 ;
struct V_1 * V_2 = V_36 -> V_41 [ V_124 ] ;
if ( V_2 == NULL ) {
F_2 ( V_121 L_36 ,
V_3 , V_124 ) ;
return NULL ;
}
if ( ! V_2 -> V_7 ) {
struct V_11 * V_125 = F_46 ( V_107 -> V_126 -> V_127 ) ;
int V_119 ;
if ( V_36 -> V_122 & V_123 ) {
F_7 ( L_37 , V_3 ) ;
return NULL ;
}
V_119 = F_9 ( V_125 , V_2 ) ;
if ( V_119 ) {
F_60 ( V_36 , V_119 ,
F_3 ( V_2 -> V_4 ) ) ;
return NULL ;
}
}
return V_2 ;
}
