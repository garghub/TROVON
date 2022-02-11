static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_8 ;
struct V_9 * V_9 = ( void * ) & V_8 . V_10 . V_11 ;
if ( V_6 -> V_12 ) {
V_6 -> V_12 = 0 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_13 ;
V_9 -> V_11 . V_14 = V_4 -> V_15 ;
memcpy ( & V_9 -> V_11 . V_11 , V_4 -> V_16 , V_4 -> V_15 ) ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
}
}
static int
F_3 ( struct V_18 * V_19 , const struct V_20 * V_21 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
struct V_9 * V_9 = ( void * ) & V_8 . V_10 . V_11 ;
if ( ( V_21 -> V_22 & V_23 ) != V_24 ) {
F_5 ( V_19 -> V_25 -> V_26 , L_1 ) ;
return - V_27 ;
}
if ( F_6 ( V_21 -> V_28 ) > V_29 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_30 ;
memcpy ( & V_9 -> V_4 , V_21 , sizeof( V_9 -> V_4 ) ) ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
return 0 ;
}
static int
F_7 ( struct V_18 * V_19 , unsigned V_31 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_19 -> V_25 -> V_26 , L_2 , V_31 ) ;
if ( V_31 == V_6 -> V_32 )
return 0 ;
else if ( V_31 != V_6 -> V_33 )
return - V_27 ;
else
return V_6 -> V_34 == V_35 ? 1 : 0 ;
}
static int
F_8 ( struct V_18 * V_19 , unsigned V_31 , unsigned V_36 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
struct V_9 * V_9 = ( void * ) & V_8 . V_10 . V_11 ;
F_5 ( V_19 -> V_25 -> V_26 , L_3 , V_31 , V_36 ) ;
if ( V_31 == V_6 -> V_32 ) {
if ( V_36 )
return - V_27 ;
if ( V_6 -> V_34 == V_37 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_38 ;
V_9 -> V_39 = V_19 -> V_25 -> V_26 -> V_40 -> V_39 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_41 ;
}
return 0 ;
}
if ( V_31 != V_6 -> V_33 )
return - V_27 ;
switch ( V_36 ) {
case 0 :
if ( V_6 -> V_34 != V_35 )
return 0 ;
if ( V_6 -> V_42 . V_2 )
F_9 ( V_6 -> V_42 . V_2 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_43 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_41 ;
break;
case 1 :
if ( V_6 -> V_34 != V_41 )
return 0 ;
if ( V_6 -> V_42 . V_2 )
F_10 ( V_6 -> V_42 . V_2 , & V_44 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_45 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_35 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static void
F_11 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
F_5 ( V_19 -> V_25 -> V_26 , L_4 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_46 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_37 ;
}
void
F_12 ( struct V_5 * V_6 )
{
struct V_47 * V_26 = V_6 -> V_48 . V_25 -> V_26 ;
int V_49 ;
if ( ( V_49 = F_13 ( & V_6 -> V_48 ) ) < 0 )
F_5 ( V_26 , L_5 , V_49 ) ;
}
void
F_14 ( struct V_5 * V_6 )
{
struct V_47 * V_26 = V_6 -> V_48 . V_25 -> V_26 ;
int V_49 ;
if ( ( V_49 = F_15 ( & V_6 -> V_48 ) ) < 0 )
F_5 ( V_26 , L_6 , V_49 ) ;
}
static int
F_16 ( struct V_5 * V_6 )
{
struct V_47 * V_26 = V_6 -> V_48 . V_25 -> V_26 ;
struct V_50 * V_42 ;
V_42 = F_17 () ;
if ( V_42 == NULL )
return - V_51 ;
V_42 -> V_52 = & V_26 -> V_40 -> V_53 ;
V_42 -> V_54 = - 1 ;
V_42 -> V_55 = & V_56 ;
V_42 -> V_57 = V_58 ;
strncpy ( V_42 -> V_59 , V_26 -> V_40 -> V_59 , sizeof( V_42 -> V_59 ) ) ;
V_6 -> V_17 = V_42 ;
F_18 ( V_42 , V_6 ) ;
return F_19 ( V_42 , V_60 , - 1 ) ;
}
static struct V_61 * * T_1
F_20 ( struct V_5 * V_6 , enum V_62 V_39 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
const struct V_67 * const * V_68 ;
const struct V_61 * const * V_69 ;
const struct V_61 * const * V_70 ;
struct V_61 * * V_71 ;
struct V_61 * * V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
void * V_77 ;
V_68 = ( V_39 == V_78 )
? V_6 -> V_79 . V_80 : V_6 -> V_79 . V_81 ;
V_69 = ( V_39 == V_78 )
? V_82 : V_83 ;
V_73 = 0 ;
V_74 = 0 ;
V_76 = V_84 . V_85 + V_86 . V_85
+ V_87 . V_85 + V_88 . V_85
+ V_89 . V_85 ;
V_75 = 5 ;
for ( V_70 = ( const struct V_61 * * ) V_6 -> V_79 . V_90 ; * V_70 ; ++ V_70 ) {
V_73 += ( * V_70 ) -> V_85 ;
V_76 += ( * V_70 ) -> V_85 ;
V_75 ++ ;
}
for ( V_70 = ( const struct V_61 * * ) V_68 ; * V_70 ; ++ V_70 ) {
V_74 += ( * V_70 ) -> V_85 ;
V_76 += ( * V_70 ) -> V_85 ;
V_75 ++ ;
}
for ( V_70 = V_69 ; * V_70 ; ++ V_70 ) {
V_76 += ( * V_70 ) -> V_85 ;
V_75 ++ ;
}
V_77 = F_21 ( ( V_75 + 1 ) * sizeof( * V_70 ) + V_76 , V_91 ) ;
if ( V_77 == NULL )
return NULL ;
V_72 = V_77 ;
V_71 = V_77 ;
V_77 += ( V_75 + 1 ) * sizeof( * V_70 ) ;
F_22 ( V_77 , V_71 , & V_84 ) ;
F_22 ( V_77 , V_71 , & V_86 ) ;
V_66 = V_77 ;
F_23 ( V_77 , V_71 ,
( const struct V_61 * * ) V_6 -> V_79 . V_90 ) ;
V_66 -> V_92 = F_24 ( V_73 ) ;
V_66 -> V_93 = 1 ;
V_66 -> V_94 [ 0 ] = V_6 -> V_33 ;
F_22 ( V_77 , V_71 , & V_87 ) ;
F_22 ( V_77 , V_71 , & V_88 ) ;
F_22 ( V_77 , V_71 , & V_89 ) ;
V_64 = V_77 ;
F_23 ( V_77 , V_71 ,
( const struct V_61 * * ) V_68 ) ;
V_64 -> V_92 = F_24 ( V_74 ) ;
V_64 -> V_95 = V_44 . V_95 ;
F_23 ( V_77 , V_71 , V_69 ) ;
* V_71 = NULL ;
return V_72 ;
}
static void
F_25 ( struct V_96 * V_97 , struct V_18 * V_19 )
{
struct V_47 * V_26 = V_97 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_26 , L_7 ) ;
if ( V_6 -> V_17 ) {
if ( V_6 -> V_17 -> V_54 == - 1 )
V_58 ( V_6 -> V_17 ) ;
else
F_26 ( V_6 -> V_17 ) ;
V_6 -> V_17 = NULL ;
}
if ( V_6 -> V_98 )
V_6 -> V_98 -> V_99 = NULL ;
if ( V_6 -> V_42 . V_2 )
V_6 -> V_42 . V_2 -> V_99 = NULL ;
if ( V_6 -> V_100 ) {
F_27 ( V_26 -> V_40 -> V_101 , V_6 -> V_100 ) ;
F_28 ( V_6 -> V_102 ) ;
}
F_28 ( V_19 -> V_103 ) ;
F_28 ( V_19 -> V_104 ) ;
F_28 ( V_6 ) ;
}
static int T_1
F_29 ( struct V_96 * V_97 , struct V_18 * V_19 )
{
struct V_47 * V_26 = V_97 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_1 * V_2 ;
int V_49 = - V_27 ;
F_5 ( V_26 , L_8 ) ;
V_2 = F_30 ( V_26 -> V_40 , & V_87 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_9 ) ;
goto error;
}
V_6 -> V_98 = V_2 ;
V_2 -> V_99 = V_6 ;
V_2 = F_30 ( V_26 -> V_40 , & V_44 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_10 ) ;
goto error;
}
V_6 -> V_42 . V_2 = V_2 ;
V_2 -> V_99 = V_6 ;
if ( ( V_49 = F_31 ( V_97 , V_19 ) ) < 0 )
goto error;
V_84 . V_105 = V_49 ;
V_86 . V_106 = V_49 ;
V_6 -> V_32 = V_49 ;
if ( ( V_49 = F_31 ( V_97 , V_19 ) ) < 0 )
goto error;
V_89 . V_106 = V_49 ;
V_107 . V_106 = V_49 ;
V_6 -> V_33 = V_49 ;
V_19 -> V_103 = F_20 ( V_6 , V_78 ) ;
V_19 -> V_104 = F_20 ( V_6 , V_108 ) ;
V_6 -> V_100 = F_32 ( V_26 -> V_40 -> V_101 , V_91 ) ;
V_6 -> V_102 = F_21 ( V_29 , V_91 ) ;
if ( V_6 -> V_100 == NULL || V_6 -> V_102 == NULL ) {
V_49 = - V_51 ;
goto error;
}
V_6 -> V_100 -> V_16 = V_6 -> V_102 ;
V_6 -> V_100 -> V_109 = F_1 ;
V_6 -> V_100 -> V_7 = V_6 ;
if ( ( V_49 = F_15 ( V_19 ) ) < 0 )
goto error;
V_49 = F_33 ( & V_6 -> V_42 ) ;
if ( V_49 < 0 )
goto error;
V_49 = F_16 ( V_6 ) ;
if ( V_49 < 0 ) {
F_34 ( V_110 L_11 ) ;
goto error;
}
return 0 ;
error:
F_25 ( V_97 , V_19 ) ;
return V_49 ;
}
int T_1
F_35 ( struct V_96 * V_97 ,
const struct V_67 * const * V_90 ,
const struct V_67 * const * V_80 ,
const struct V_67 * const * V_81 )
{
struct V_5 * V_6 ;
int V_49 = 0 ;
if ( ! F_36 ( V_97 -> V_26 -> V_40 ) )
return - V_27 ;
V_6 = F_37 ( sizeof( * V_6 ) , V_91 ) ;
if ( V_6 == NULL )
return - V_51 ;
V_6 -> V_34 = V_37 ;
if ( V_90 == NULL || V_90 [ 0 ] == NULL ||
V_90 [ 0 ] -> V_111 != V_112 )
goto error;
if ( V_80 == NULL || V_80 [ 0 ] == NULL ||
V_80 [ 0 ] -> V_111 != V_113 )
goto error;
if ( V_81 == NULL || V_81 [ 0 ] == NULL ||
V_81 [ 0 ] -> V_111 != V_113 )
goto error;
V_6 -> V_79 . V_90 = V_90 ;
V_6 -> V_79 . V_80 = V_80 ;
V_6 -> V_79 . V_81 = V_81 ;
if ( ( V_49 = F_38 ( V_97 -> V_26 ) ) < 0 )
goto error;
V_114 [ V_115 ] . V_116 = V_49 ;
V_84 . V_117 = V_49 ;
if ( ( V_49 = F_38 ( V_97 -> V_26 ) ) < 0 )
goto error;
V_114 [ V_118 ] . V_116 = V_49 ;
V_86 . V_119 = V_49 ;
if ( ( V_49 = F_38 ( V_97 -> V_26 ) ) < 0 )
goto error;
V_114 [ V_120 ] . V_116 = V_49 ;
V_89 . V_119 = V_49 ;
V_107 . V_119 = V_49 ;
V_6 -> V_48 . V_59 = L_12 ;
V_6 -> V_48 . V_121 = V_122 ;
V_6 -> V_48 . V_123 = F_29 ;
V_6 -> V_48 . V_124 = F_25 ;
V_6 -> V_48 . V_125 = F_7 ;
V_6 -> V_48 . V_126 = F_8 ;
V_6 -> V_48 . V_127 = F_11 ;
V_6 -> V_48 . V_128 = F_3 ;
V_49 = F_39 ( V_97 , & V_6 -> V_48 ) ;
if ( V_49 )
F_28 ( V_6 ) ;
return 0 ;
error:
F_28 ( V_6 ) ;
return V_49 ;
}
