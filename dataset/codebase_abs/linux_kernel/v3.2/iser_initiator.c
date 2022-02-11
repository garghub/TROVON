static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_9 ;
struct V_10 * V_11 = & V_5 -> V_12 . V_13 ;
struct V_14 * V_15 = & V_5 -> V_16 [ V_17 ] ;
V_9 = F_2 ( V_5 ,
V_15 ,
V_17 ,
V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_3 > V_5 -> V_16 [ V_17 ] . V_19 ) {
F_3 ( L_1
L_2 ,
V_5 -> V_16 [ V_17 ] . V_19 , V_3 ,
V_2 -> V_20 , V_5 -> V_21 ) ;
return - V_22 ;
}
V_9 = F_4 ( V_5 , V_17 ) ;
if ( V_9 ) {
F_3 ( L_3 ) ;
return V_9 ;
}
V_8 = & V_5 -> V_23 [ V_17 ] ;
V_11 -> V_24 |= V_25 ;
V_11 -> V_26 = F_5 ( V_8 -> V_27 . V_28 ) ;
V_11 -> V_29 = F_6 ( V_8 -> V_27 . V_30 ) ;
F_7 ( L_4 ,
V_2 -> V_20 , V_8 -> V_27 . V_28 ,
( unsigned long long ) V_8 -> V_27 . V_30 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 ,
unsigned int V_31 ,
unsigned int V_32 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_9 ;
struct V_10 * V_11 = & V_5 -> V_12 . V_13 ;
struct V_14 * V_33 = & V_5 -> V_16 [ V_34 ] ;
struct V_35 * V_36 = & V_5 -> V_12 . V_37 [ 1 ] ;
V_9 = F_2 ( V_5 ,
V_33 ,
V_34 ,
V_38 ) ;
if ( V_9 )
return V_9 ;
if ( V_3 > V_5 -> V_16 [ V_34 ] . V_19 ) {
F_3 ( L_5
L_6 ,
V_5 -> V_16 [ V_34 ] . V_19 ,
V_3 , V_2 -> V_20 , V_2 -> V_39 ) ;
return - V_22 ;
}
V_9 = F_4 ( V_5 , V_34 ) ;
if ( V_9 != 0 ) {
F_3 ( L_7 ) ;
return V_9 ;
}
V_8 = & V_5 -> V_23 [ V_34 ] ;
if ( V_32 < V_3 ) {
V_11 -> V_24 |= V_40 ;
V_11 -> V_41 = F_5 ( V_8 -> V_27 . V_28 ) ;
V_11 -> V_42 = F_6 ( V_8 -> V_27 . V_30 + V_32 ) ;
F_7 ( L_8
L_9 ,
V_2 -> V_20 , V_8 -> V_27 . V_28 ,
( unsigned long long ) V_8 -> V_27 . V_30 , V_32 ) ;
}
if ( V_31 > 0 ) {
F_7 ( L_10 ,
V_2 -> V_20 , V_31 ) ;
V_36 -> V_43 = V_8 -> V_27 . V_30 ;
V_36 -> V_44 = V_31 ;
V_36 -> V_45 = V_8 -> V_27 . V_45 ;
V_5 -> V_12 . V_46 = 2 ;
}
return 0 ;
}
static void F_9 ( struct V_21 * V_47 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
F_10 ( V_51 -> V_52 ,
V_49 -> V_53 , V_54 , V_38 ) ;
memset ( & V_49 -> V_13 , 0 , sizeof( struct V_10 ) ) ;
V_49 -> V_13 . V_24 = V_55 ;
V_49 -> V_46 = 1 ;
if ( V_49 -> V_37 [ 0 ] . V_45 != V_51 -> V_56 -> V_45 ) {
V_49 -> V_37 [ 0 ] . V_45 = V_51 -> V_56 -> V_45 ;
F_7 ( L_11 , V_49 ) ;
}
}
static int F_11 ( struct V_21 * V_47 )
{
int V_57 , V_58 ;
T_1 V_53 ;
struct V_59 * V_60 ;
struct V_35 * V_61 ;
struct V_50 * V_51 = V_47 -> V_51 ;
V_47 -> V_62 = F_12 ( V_63 *
sizeof( struct V_59 ) , V_64 ) ;
if ( ! V_47 -> V_62 )
goto V_65;
V_60 = V_47 -> V_62 ;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ , V_60 ++ ) {
V_53 = F_13 ( V_51 -> V_52 , ( void * ) V_60 ,
V_66 , V_18 ) ;
if ( F_14 ( V_51 -> V_52 , V_53 ) )
goto V_67;
V_60 -> V_53 = V_53 ;
V_61 = & V_60 -> V_61 ;
V_61 -> V_43 = V_60 -> V_53 ;
V_61 -> V_44 = V_66 ;
V_61 -> V_45 = V_51 -> V_56 -> V_45 ;
}
V_47 -> V_68 = 0 ;
return 0 ;
V_67:
V_60 = V_47 -> V_62 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ , V_60 ++ )
F_15 ( V_51 -> V_52 , V_60 -> V_53 ,
V_66 , V_18 ) ;
F_16 ( V_47 -> V_62 ) ;
V_47 -> V_62 = NULL ;
V_65:
F_3 ( L_12 ) ;
return - V_69 ;
}
void F_17 ( struct V_21 * V_47 )
{
int V_57 ;
struct V_59 * V_60 ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_47 -> V_70 ) {
if ( V_47 -> V_71 )
F_15 ( V_51 -> V_52 ,
V_47 -> V_71 ,
V_72 , V_38 ) ;
if ( V_47 -> V_73 )
F_15 ( V_51 -> V_52 ,
V_47 -> V_73 ,
V_74 , V_18 ) ;
F_16 ( V_47 -> V_70 ) ;
}
if ( ! V_47 -> V_62 )
return;
V_60 = V_47 -> V_62 ;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ , V_60 ++ )
F_15 ( V_51 -> V_52 , V_60 -> V_53 ,
V_66 , V_18 ) ;
F_16 ( V_47 -> V_62 ) ;
}
int F_18 ( struct V_75 * V_39 )
{
struct V_76 * V_21 = V_39 -> V_6 ;
F_7 ( L_13 , V_77 ) ;
F_19 ( V_21 -> V_47 -> V_78 != 0 ) ;
F_19 ( F_20 ( & V_21 -> V_47 -> V_79 ) != 0 ) ;
if ( F_11 ( V_21 -> V_47 ) )
return - V_69 ;
if ( F_21 ( V_21 -> V_47 , V_77 ) )
return - V_69 ;
return 0 ;
}
int F_22 ( struct V_75 * V_39 ,
struct V_1 * V_2 )
{
struct V_76 * V_21 = V_39 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_3 ;
int V_9 ;
struct V_14 * V_80 ;
struct V_81 * V_11 = (struct V_81 * ) V_2 -> V_11 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_48 * V_49 = & V_5 -> V_12 ;
V_3 = F_23 ( V_11 -> V_84 ) ;
V_49 -> type = V_85 ;
F_9 ( V_21 -> V_47 , V_49 ) ;
if ( V_11 -> V_24 & V_86 )
V_80 = & V_5 -> V_16 [ V_17 ] ;
else
V_80 = & V_5 -> V_16 [ V_34 ] ;
if ( F_24 ( V_83 ) ) {
V_80 -> V_87 = F_25 ( V_83 ) ;
V_80 -> V_88 = F_24 ( V_83 ) ;
}
V_80 -> V_19 = F_26 ( V_83 ) ;
if ( V_11 -> V_24 & V_86 ) {
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 )
goto V_89;
}
if ( V_11 -> V_24 & V_90 ) {
V_9 = F_8 ( V_2 ,
V_2 -> V_91 ,
V_2 -> V_91 +
V_2 -> V_92 . V_84 ,
V_3 ) ;
if ( V_9 )
goto V_89;
}
V_5 -> V_93 = V_94 ;
V_9 = F_27 ( V_21 -> V_47 , V_49 ) ;
if ( ! V_9 )
return 0 ;
V_89:
F_3 ( L_14 , V_39 , V_2 -> V_20 , V_9 ) ;
return V_9 ;
}
int F_28 ( struct V_75 * V_39 ,
struct V_1 * V_2 ,
struct V_95 * V_11 )
{
struct V_76 * V_21 = V_39 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_48 * V_49 = NULL ;
struct V_7 * V_8 ;
unsigned long V_96 ;
unsigned long V_97 ;
T_2 V_20 ;
int V_9 = 0 ;
struct V_35 * V_36 ;
V_20 = ( V_98 T_2 ) V_11 -> V_20 ;
V_97 = F_29 ( V_11 -> V_99 ) ;
V_96 = F_23 ( V_11 -> V_100 ) ;
F_7 ( L_15 ,
V_101 , ( int ) V_20 , ( int ) V_97 , ( int ) V_96 ) ;
V_49 = F_30 ( V_102 . V_103 , V_104 ) ;
if ( V_49 == NULL ) {
F_3 ( L_16 ) ;
return - V_69 ;
}
V_49 -> type = V_105 ;
V_49 -> V_13 . V_24 = V_55 ;
memcpy ( & V_49 -> V_106 , V_11 , sizeof( struct V_107 ) ) ;
F_31 ( V_2 , V_49 ) ;
V_8 = & V_5 -> V_23 [ V_34 ] ;
V_36 = & V_49 -> V_37 [ 1 ] ;
V_36 -> V_43 = V_8 -> V_27 . V_30 + V_96 ;
V_36 -> V_44 = V_97 ;
V_36 -> V_45 = V_8 -> V_27 . V_45 ;
V_49 -> V_46 = 2 ;
if ( V_96 + V_97 > V_5 -> V_16 [ V_34 ] . V_19 ) {
F_3 ( L_17
L_18 ,
V_96 , V_97 ,
V_5 -> V_16 [ V_34 ] . V_19 , V_20 ) ;
V_9 = - V_22 ;
goto V_108;
}
F_7 ( L_19 ,
V_20 , V_96 , V_97 ) ;
V_9 = F_27 ( V_21 -> V_47 , V_49 ) ;
if ( ! V_9 )
return 0 ;
V_108:
F_32 ( V_102 . V_103 , V_49 ) ;
F_3 ( L_20 , V_39 , V_9 ) ;
return V_9 ;
}
int F_33 ( struct V_75 * V_39 ,
struct V_1 * V_2 )
{
struct V_76 * V_21 = V_39 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_48 * V_109 = & V_5 -> V_12 ;
unsigned long V_97 ;
int V_9 = 0 ;
struct V_50 * V_51 ;
struct V_21 * V_47 = V_21 -> V_47 ;
V_109 -> type = V_110 ;
F_9 ( V_21 -> V_47 , V_109 ) ;
V_51 = V_21 -> V_47 -> V_51 ;
V_97 = F_29 ( V_2 -> V_11 -> V_99 ) ;
if ( V_97 > 0 ) {
struct V_35 * V_36 = & V_109 -> V_37 [ 1 ] ;
if ( V_2 != V_39 -> V_111 ) {
F_3 ( L_21 ) ;
goto V_112;
}
F_10 ( V_51 -> V_52 ,
V_47 -> V_71 , V_2 -> V_113 ,
V_38 ) ;
memcpy ( V_21 -> V_47 -> V_114 , V_2 -> V_16 ,
V_2 -> V_113 ) ;
F_34 ( V_51 -> V_52 ,
V_47 -> V_71 , V_2 -> V_113 ,
V_38 ) ;
V_36 -> V_43 = V_21 -> V_47 -> V_71 ;
V_36 -> V_44 = V_2 -> V_113 ;
V_36 -> V_45 = V_51 -> V_56 -> V_45 ;
V_109 -> V_46 = 2 ;
}
if ( V_2 == V_39 -> V_111 ) {
V_9 = F_35 ( V_21 -> V_47 ) ;
if ( V_9 )
goto V_112;
}
V_9 = F_27 ( V_21 -> V_47 , V_109 ) ;
if ( ! V_9 )
return 0 ;
V_112:
F_3 ( L_20 , V_39 , V_9 ) ;
return V_9 ;
}
void F_36 ( struct V_59 * V_60 ,
unsigned long V_115 ,
struct V_21 * V_47 )
{
struct V_76 * V_39 = V_47 -> V_21 ;
struct V_107 * V_11 ;
T_1 V_116 ;
int V_117 , V_118 , V_119 , V_9 ;
if ( ( char * ) V_60 == V_47 -> V_120 ) {
V_116 = V_47 -> V_73 ;
V_117 = V_74 ;
} else {
V_116 = V_60 -> V_53 ;
V_117 = V_66 ;
}
F_10 ( V_47 -> V_51 -> V_52 , V_116 ,
V_117 , V_18 ) ;
V_11 = & V_60 -> V_106 ;
F_7 ( L_22 , V_11 -> V_121 ,
V_11 -> V_20 , ( int ) ( V_115 - V_54 ) ) ;
F_37 ( V_39 -> V_75 , V_11 ,
V_60 -> V_16 , V_115 - V_54 ) ;
F_34 ( V_47 -> V_51 -> V_52 , V_116 ,
V_117 , V_18 ) ;
V_39 -> V_47 -> V_78 -- ;
if ( V_116 == V_47 -> V_73 )
return;
V_118 = V_47 -> V_78 ;
if ( V_118 + V_77 <= V_63 ) {
V_119 = F_38 ( V_63 - V_118 ,
V_77 ) ;
V_9 = F_21 ( V_47 , V_119 ) ;
if ( V_9 )
F_3 ( L_23 , V_119 , V_9 ) ;
}
}
void F_39 ( struct V_48 * V_49 ,
struct V_21 * V_47 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_49 -> type == V_105 ) {
F_15 ( V_51 -> V_52 , V_49 -> V_53 ,
V_54 , V_38 ) ;
F_32 ( V_102 . V_103 , V_49 ) ;
}
F_40 ( & V_47 -> V_79 ) ;
if ( V_49 -> type == V_110 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_49 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_11 -> V_20 == V_122 )
F_41 ( V_2 ) ;
}
}
void F_42 ( struct V_4 * V_5 )
{
V_5 -> V_93 = V_123 ;
V_5 -> V_124 [ V_17 ] = 0 ;
V_5 -> V_124 [ V_34 ] = 0 ;
V_5 -> V_16 [ V_17 ] . V_19 = 0 ;
V_5 -> V_16 [ V_34 ] . V_19 = 0 ;
memset ( & V_5 -> V_23 [ V_17 ] , 0 ,
sizeof( struct V_7 ) ) ;
memset ( & V_5 -> V_23 [ V_34 ] , 0 ,
sizeof( struct V_7 ) ) ;
}
void F_43 ( struct V_4 * V_5 )
{
int V_125 = 1 ;
struct V_7 * V_126 ;
if ( V_5 -> V_127 [ V_17 ] . V_128 != NULL ) {
V_125 = 0 ;
F_44 ( V_5 , V_17 ) ;
}
if ( V_5 -> V_127 [ V_34 ] . V_128 != NULL ) {
V_125 = 0 ;
F_44 ( V_5 , V_34 ) ;
}
if ( V_5 -> V_124 [ V_17 ] ) {
V_126 = & V_5 -> V_23 [ V_17 ] ;
if ( V_126 -> V_27 . V_129 )
F_45 ( & V_126 -> V_27 ) ;
}
if ( V_5 -> V_124 [ V_34 ] ) {
V_126 = & V_5 -> V_23 [ V_34 ] ;
if ( V_126 -> V_27 . V_129 )
F_45 ( & V_126 -> V_27 ) ;
}
if ( V_125 )
F_46 ( V_5 ) ;
}
