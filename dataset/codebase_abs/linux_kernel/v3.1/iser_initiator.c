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
F_15 ( V_51 -> V_52 , V_47 -> V_71 ,
V_72 , V_18 ) ;
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
int F_18 ( struct V_73 * V_39 )
{
struct V_74 * V_21 = V_39 -> V_6 ;
F_7 ( L_13 , V_75 ) ;
F_19 ( V_21 -> V_47 -> V_76 != 0 ) ;
F_19 ( F_20 ( & V_21 -> V_47 -> V_77 ) != 0 ) ;
if ( F_11 ( V_21 -> V_47 ) )
return - V_69 ;
if ( F_21 ( V_21 -> V_47 , V_75 ) )
return - V_69 ;
return 0 ;
}
int F_22 ( struct V_73 * V_39 ,
struct V_1 * V_2 )
{
struct V_74 * V_21 = V_39 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_3 ;
int V_9 ;
struct V_14 * V_78 ;
struct V_79 * V_11 = (struct V_79 * ) V_2 -> V_11 ;
struct V_80 * V_81 = V_2 -> V_81 ;
struct V_48 * V_49 = & V_5 -> V_12 ;
V_3 = F_23 ( V_11 -> V_82 ) ;
V_49 -> type = V_83 ;
F_9 ( V_21 -> V_47 , V_49 ) ;
if ( V_11 -> V_24 & V_84 )
V_78 = & V_5 -> V_16 [ V_17 ] ;
else
V_78 = & V_5 -> V_16 [ V_34 ] ;
if ( F_24 ( V_81 ) ) {
V_78 -> V_85 = F_25 ( V_81 ) ;
V_78 -> V_86 = F_24 ( V_81 ) ;
}
V_78 -> V_19 = F_26 ( V_81 ) ;
if ( V_11 -> V_24 & V_84 ) {
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 )
goto V_87;
}
if ( V_11 -> V_24 & V_88 ) {
V_9 = F_8 ( V_2 ,
V_2 -> V_89 ,
V_2 -> V_89 +
V_2 -> V_90 . V_82 ,
V_3 ) ;
if ( V_9 )
goto V_87;
}
V_5 -> V_91 = V_92 ;
V_9 = F_27 ( V_21 -> V_47 , V_49 ) ;
if ( ! V_9 )
return 0 ;
V_87:
F_3 ( L_14 , V_39 , V_2 -> V_20 , V_9 ) ;
return V_9 ;
}
int F_28 ( struct V_73 * V_39 ,
struct V_1 * V_2 ,
struct V_93 * V_11 )
{
struct V_74 * V_21 = V_39 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_48 * V_49 = NULL ;
struct V_7 * V_8 ;
unsigned long V_94 ;
unsigned long V_95 ;
T_2 V_20 ;
int V_9 = 0 ;
struct V_35 * V_36 ;
V_20 = ( V_96 T_2 ) V_11 -> V_20 ;
V_95 = F_29 ( V_11 -> V_97 ) ;
V_94 = F_23 ( V_11 -> V_98 ) ;
F_7 ( L_15 ,
V_99 , ( int ) V_20 , ( int ) V_95 , ( int ) V_94 ) ;
V_49 = F_30 ( V_100 . V_101 , V_102 ) ;
if ( V_49 == NULL ) {
F_3 ( L_16 ) ;
return - V_69 ;
}
V_49 -> type = V_103 ;
V_49 -> V_13 . V_24 = V_55 ;
memcpy ( & V_49 -> V_104 , V_11 , sizeof( struct V_105 ) ) ;
F_31 ( V_2 , V_49 ) ;
V_8 = & V_5 -> V_23 [ V_34 ] ;
V_36 = & V_49 -> V_37 [ 1 ] ;
V_36 -> V_43 = V_8 -> V_27 . V_30 + V_94 ;
V_36 -> V_44 = V_95 ;
V_36 -> V_45 = V_8 -> V_27 . V_45 ;
V_49 -> V_46 = 2 ;
if ( V_94 + V_95 > V_5 -> V_16 [ V_34 ] . V_19 ) {
F_3 ( L_17
L_18 ,
V_94 , V_95 ,
V_5 -> V_16 [ V_34 ] . V_19 , V_20 ) ;
V_9 = - V_22 ;
goto V_106;
}
F_7 ( L_19 ,
V_20 , V_94 , V_95 ) ;
V_9 = F_27 ( V_21 -> V_47 , V_49 ) ;
if ( ! V_9 )
return 0 ;
V_106:
F_32 ( V_100 . V_101 , V_49 ) ;
F_3 ( L_20 , V_39 , V_9 ) ;
return V_9 ;
}
int F_33 ( struct V_73 * V_39 ,
struct V_1 * V_2 )
{
struct V_74 * V_21 = V_39 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_48 * V_107 = & V_5 -> V_12 ;
unsigned long V_95 ;
int V_9 = 0 ;
struct V_50 * V_51 ;
V_107 -> type = V_108 ;
F_9 ( V_21 -> V_47 , V_107 ) ;
V_51 = V_21 -> V_47 -> V_51 ;
V_95 = F_29 ( V_2 -> V_11 -> V_97 ) ;
if ( V_95 > 0 ) {
struct V_35 * V_36 = & V_107 -> V_37 [ 1 ] ;
if ( V_2 != V_39 -> V_109 ) {
F_3 ( L_21 ) ;
goto V_110;
}
memcpy ( V_21 -> V_47 -> V_70 , V_2 -> V_16 ,
V_2 -> V_111 ) ;
V_36 -> V_43 = V_21 -> V_47 -> V_71 ;
V_36 -> V_44 = V_2 -> V_111 ;
V_36 -> V_45 = V_51 -> V_56 -> V_45 ;
V_107 -> V_46 = 2 ;
}
if ( V_2 == V_39 -> V_109 ) {
V_9 = F_34 ( V_21 -> V_47 ) ;
if ( V_9 )
goto V_110;
}
V_9 = F_27 ( V_21 -> V_47 , V_107 ) ;
if ( ! V_9 )
return 0 ;
V_110:
F_3 ( L_20 , V_39 , V_9 ) ;
return V_9 ;
}
void F_35 ( struct V_59 * V_60 ,
unsigned long V_112 ,
struct V_21 * V_47 )
{
struct V_74 * V_39 = V_47 -> V_21 ;
struct V_105 * V_11 ;
T_1 V_113 ;
int V_114 , V_115 , V_116 , V_9 ;
if ( ( char * ) V_60 == V_47 -> V_70 ) {
V_113 = V_47 -> V_71 ;
V_114 = V_72 ;
} else {
V_113 = V_60 -> V_53 ;
V_114 = V_66 ;
}
F_10 ( V_47 -> V_51 -> V_52 , V_113 ,
V_114 , V_18 ) ;
V_11 = & V_60 -> V_104 ;
F_7 ( L_22 , V_11 -> V_117 ,
V_11 -> V_20 , ( int ) ( V_112 - V_54 ) ) ;
F_36 ( V_39 -> V_73 , V_11 ,
V_60 -> V_16 , V_112 - V_54 ) ;
F_37 ( V_47 -> V_51 -> V_52 , V_113 ,
V_114 , V_18 ) ;
V_39 -> V_47 -> V_76 -- ;
if ( V_113 == V_47 -> V_71 )
return;
V_115 = V_47 -> V_76 ;
if ( V_115 + V_75 <= V_63 ) {
V_116 = F_38 ( V_63 - V_115 ,
V_75 ) ;
V_9 = F_21 ( V_47 , V_116 ) ;
if ( V_9 )
F_3 ( L_23 , V_116 , V_9 ) ;
}
}
void F_39 ( struct V_48 * V_49 ,
struct V_21 * V_47 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_49 -> type == V_103 ) {
F_15 ( V_51 -> V_52 , V_49 -> V_53 ,
V_54 , V_38 ) ;
F_32 ( V_100 . V_101 , V_49 ) ;
}
F_40 ( & V_47 -> V_77 ) ;
if ( V_49 -> type == V_108 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_49 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_11 -> V_20 == V_118 )
F_41 ( V_2 ) ;
}
}
void F_42 ( struct V_4 * V_5 )
{
V_5 -> V_91 = V_119 ;
V_5 -> V_120 [ V_17 ] = 0 ;
V_5 -> V_120 [ V_34 ] = 0 ;
V_5 -> V_16 [ V_17 ] . V_19 = 0 ;
V_5 -> V_16 [ V_34 ] . V_19 = 0 ;
memset ( & V_5 -> V_23 [ V_17 ] , 0 ,
sizeof( struct V_7 ) ) ;
memset ( & V_5 -> V_23 [ V_34 ] , 0 ,
sizeof( struct V_7 ) ) ;
}
void F_43 ( struct V_4 * V_5 )
{
int V_121 = 1 ;
struct V_7 * V_122 ;
if ( V_5 -> V_123 [ V_17 ] . V_124 != NULL ) {
V_121 = 0 ;
F_44 ( V_5 , V_17 ) ;
}
if ( V_5 -> V_123 [ V_34 ] . V_124 != NULL ) {
V_121 = 0 ;
F_44 ( V_5 , V_34 ) ;
}
if ( V_5 -> V_120 [ V_17 ] ) {
V_122 = & V_5 -> V_23 [ V_17 ] ;
if ( V_122 -> V_27 . V_125 )
F_45 ( & V_122 -> V_27 ) ;
}
if ( V_5 -> V_120 [ V_34 ] ) {
V_122 = & V_5 -> V_23 [ V_34 ] ;
if ( V_122 -> V_27 . V_125 )
F_45 ( & V_122 -> V_27 ) ;
}
if ( V_121 )
F_46 ( V_5 ) ;
}
