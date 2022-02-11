static int F_1 ( void * V_1 , void * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
F_2 ( 3 , L_1 , V_10 ) ;
V_6 = V_1 ;
V_8 = V_1 ;
V_9 = F_3 ( V_8 , V_4 ) ;
if ( V_9 ) {
F_2 ( 1 , L_2 , V_10 ) ;
V_6 -> V_11 = V_12 ;
return V_9 ;
}
return 0 ;
}
static void F_4 ( void * V_1 , void * V_2 ,
T_1 V_13 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = V_1 ;
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
if( V_4 )
F_5 ( V_4 ) ;
V_8 = V_1 ;
if ( V_8 == NULL ) {
F_2 ( 0 , L_4 ,
V_10 , V_6 ) ;
return;
}
F_6 ( V_8 ) ;
if ( ! F_7 ( V_8 , V_14 ) && V_8 -> V_15 != V_16 ) {
V_8 -> V_15 = V_16 ;
V_8 -> V_17 |= V_18 ;
V_8 -> V_19 ( V_8 ) ;
if ( V_6 -> V_20 ) {
F_8 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
}
F_9 ( V_8 ) ;
}
static void F_10 ( void * V_1 , void * V_2 ,
struct V_21 * V_22 ,
T_2 V_23 , T_3 V_24 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = V_1 ;
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
V_8 = V_1 ;
if ( V_8 == NULL ) {
F_5 ( V_4 ) ;
return;
}
F_5 ( V_4 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_25 = V_23 ;
switch ( V_8 -> V_26 ) {
case V_27 :
if ( V_23 != 0 ) {
F_11 ( L_5 ,
V_10 ) ;
return;
}
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
break;
case V_29 :
if ( V_23 == 0 ) {
F_11 ( L_6 ,
V_10 ) ;
return;
}
V_6 -> V_28 = V_23 ;
break;
default:
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
}
F_2 ( 2 , L_7 , V_10 ,
V_6 -> V_28 ) ;
memcpy ( & V_6 -> V_30 , V_22 , sizeof( struct V_21 ) ) ;
V_8 -> V_15 = V_31 ;
V_8 -> V_19 ( V_8 ) ;
}
static void F_13 ( void * V_1 , void * V_2 ,
struct V_21 * V_22 , T_2 V_23 ,
T_3 V_24 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = V_1 ;
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
V_8 = V_1 ;
if ( V_8 == NULL ) {
F_5 ( V_4 ) ;
return;
}
V_6 -> V_24 = V_24 ;
V_6 -> V_25 = V_23 ;
switch ( V_8 -> V_26 ) {
case V_27 :
if ( V_23 != 0 ) {
F_11 ( L_5 ,
V_10 ) ;
F_14 ( V_4 ) ;
return;
}
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
break;
case V_29 :
if ( V_23 == 0 ) {
F_11 ( L_6 ,
V_10 ) ;
F_14 ( V_4 ) ;
return;
}
V_6 -> V_28 = V_23 ;
break;
default:
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
}
F_2 ( 2 , L_7 , V_10 ,
V_6 -> V_28 ) ;
memcpy ( & V_6 -> V_30 , V_22 , sizeof( struct V_21 ) ) ;
F_15 ( & V_8 -> V_32 , V_4 ) ;
V_8 -> V_19 ( V_8 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
F_2 ( 2 , L_1 , V_10 ) ;
V_4 = F_17 ( V_33 + V_34 , V_35 ) ;
if ( V_4 == NULL ) {
F_2 ( 0 , L_8 ,
V_10 ) ;
return;
}
F_18 ( V_4 , V_36 ) ;
F_19 ( V_6 -> V_20 , V_6 -> V_37 , V_4 ) ;
}
static void F_20 ( void * V_1 , void * V_2 , T_4 V_38 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 ( 2 , L_1 , V_10 ) ;
V_6 = V_1 ;
V_8 = V_1 ;
F_21 ( V_8 == NULL ) ;
switch ( V_38 ) {
case V_12 :
F_2 ( 1 , L_9 ,
V_10 ) ;
V_6 -> V_39 = V_38 ;
break;
case V_40 :
V_6 -> V_39 = V_38 ;
F_2 ( 1 , L_10 ,
V_10 ) ;
F_22 ( F_23 ( V_8 ) ) ;
break;
default:
F_2 ( 0 , L_11 , V_10 ) ;
V_6 -> V_39 = V_38 ;
break;
}
}
static void F_24 ( int V_41 , T_5 V_42 ,
struct V_43 * V_44 , void * V_45 )
{
struct V_5 * V_6 ;
V_6 = V_45 ;
if ( ! V_6 ) {
F_25 ( L_12 , V_10 ) ;
return;
}
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
F_26 ( V_6 -> V_46 ) ;
V_6 -> V_46 = NULL ;
if ( V_41 != V_47 ) {
F_2 ( 1 , L_13 , V_10 ,
V_41 ) ;
V_6 -> V_48 = V_41 ;
F_22 ( & V_6 -> V_49 ) ;
return;
}
V_6 -> V_50 = V_44 ;
V_6 -> V_48 = 0 ;
F_22 ( & V_6 -> V_49 ) ;
}
static void F_27 ( T_6 * V_51 ,
T_7 V_52 ,
void * V_45 )
{
struct V_5 * V_6 ;
F_2 ( 2 , L_1 , V_10 ) ;
V_6 = V_45 ;
if ( ! V_6 ) {
F_25 ( L_12 , V_10 ) ;
return;
}
V_6 -> V_53 = V_51 -> V_54 ;
F_22 ( & V_6 -> V_49 ) ;
}
static void F_28 ( T_8 V_45 )
{
struct V_5 * V_6 ;
F_2 ( 2 , L_1 , V_10 ) ;
V_6 = (struct V_5 * ) V_45 ;
F_21 ( V_6 == NULL ) ;
V_6 -> V_55 = NULL ;
V_6 -> V_53 = 0 ;
V_6 -> V_48 = - V_56 ;
F_22 ( & V_6 -> V_49 ) ;
}
static int F_29 ( struct V_5 * V_6 , T_3 V_57 , char * V_58 )
{
T_9 V_59 ;
if ( V_6 -> V_20 ) {
F_2 ( 0 , L_14 , V_10 ) ;
return - V_60 ;
}
F_30 ( & V_59 ) ;
V_59 . V_61 = F_10 ;
V_59 . V_62 = F_13 ;
V_59 . V_63 = F_4 ;
V_59 . V_64 = F_1 ;
V_59 . V_65 = F_1 ;
V_59 . V_66 = F_20 ;
V_59 . V_1 = V_6 ;
strncpy ( V_59 . V_58 , V_58 , V_67 ) ;
V_6 -> V_20 = F_31 ( V_57 , V_68 ,
& V_59 ) ;
if ( V_6 -> V_20 == NULL ) {
F_2 ( 0 , L_15 ,
V_10 ) ;
return - V_69 ;
}
V_6 -> V_70 = V_6 -> V_20 -> V_70 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 , int V_71 )
{
T_9 V_59 ;
if ( V_6 -> V_72 ) {
F_25 ( L_16 , V_10 ) ;
return - V_60 ;
}
F_30 ( & V_59 ) ;
V_59 . V_65 = F_1 ;
V_59 . V_1 = V_6 ;
strncpy ( V_59 . V_58 , L_17 , V_67 ) ;
V_6 -> V_72 = F_33 ( V_73 , & V_59 , V_71 ) ;
if ( V_6 -> V_72 == NULL ) {
F_2 ( 0 , L_18 , V_10 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_34 ( struct V_5 * V_6 , char * V_58 )
{
F_2 ( 2 , L_19 , V_10 , V_6 , V_58 ) ;
if ( V_6 -> V_46 ) {
F_25 ( L_20 ,
V_10 ) ;
return - V_60 ;
}
V_6 -> V_46 = F_35 ( V_74 , V_75 , V_6 ,
F_24 ) ;
if( V_6 -> V_46 == NULL )
return - V_69 ;
V_6 -> V_48 = - V_76 ;
F_36 ( V_6 -> V_46 , V_6 -> V_77 , V_6 -> V_54 ,
V_58 , L_21 ) ;
if ( F_37 ( V_6 -> V_49 , ( V_6 -> V_46 == NULL ) ) )
return - V_76 ;
if ( V_6 -> V_48 )
{
if( ( V_6 -> V_48 == V_78 ) ||
( V_6 -> V_48 == V_79 ) )
return - V_80 ;
else
return - V_76 ;
}
switch ( V_6 -> V_50 -> type ) {
case V_81 :
F_2 ( 4 , L_22 ,
V_10 , V_6 -> V_50 -> V_82 . integer ) ;
if ( V_6 -> V_50 -> V_82 . integer != - 1 )
V_6 -> V_83 = V_6 -> V_50 -> V_82 . integer ;
else
V_6 -> V_83 = 0 ;
break;
default:
V_6 -> V_83 = 0 ;
F_2 ( 0 , L_23 , V_10 ) ;
break;
}
if ( V_6 -> V_50 )
F_38 ( V_6 -> V_50 ) ;
if ( V_6 -> V_83 )
return 0 ;
return - V_80 ;
}
static int F_39 ( struct V_5 * V_6 , char * V_58 )
{
T_6 * V_84 ;
int V_85 ;
int V_86 ;
int V_9 = - V_87 ;
T_2 V_54 = V_88 ;
T_3 V_83 = 0x0 ;
F_2 ( 2 , L_24 , V_10 , V_58 ) ;
V_84 = F_40 ( & V_85 , V_6 -> V_89 . V_90 ,
V_6 -> V_91 ) ;
if ( V_84 == NULL )
return - V_87 ;
for( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
V_6 -> V_54 = V_84 [ V_86 ] . V_54 ;
V_6 -> V_77 = 0x0 ;
F_2 ( 1 , L_25 ,
V_10 , V_6 -> V_54 ) ;
V_9 = F_34 ( V_6 , V_58 ) ;
switch ( V_9 ) {
case 0 :
if( V_54 != V_88 ) {
F_2 ( 1 , L_26 ,
V_10 , V_58 ) ;
V_6 -> V_54 = V_88 ;
F_41 ( V_84 ) ;
return - V_92 ;
}
V_54 = V_6 -> V_54 ;
V_83 = V_6 -> V_83 ;
break;
case - V_80 :
break;
default:
F_2 ( 0 , L_27 , V_10 ) ;
V_6 -> V_54 = V_88 ;
F_41 ( V_84 ) ;
return - V_76 ;
}
}
F_41 ( V_84 ) ;
if( V_54 == V_88 ) {
F_2 ( 1 , L_28 ,
V_10 , V_58 ) ;
V_6 -> V_54 = V_88 ;
return - V_80 ;
}
V_6 -> V_54 = V_54 ;
V_6 -> V_77 = 0x0 ;
V_6 -> V_83 = V_83 ;
F_2 ( 1 , L_29 ,
V_10 , V_58 , V_6 -> V_54 ) ;
return 0 ;
}
static int F_42 ( struct V_93 * V_7 , struct V_94 * V_95 ,
int * V_96 , int V_97 )
{
struct V_98 V_77 ;
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_97 ) {
if ( V_8 -> V_15 != V_31 )
return - V_99 ;
V_77 . V_100 = V_101 ;
V_77 . V_102 = V_6 -> V_83 ;
V_77 . V_103 = V_6 -> V_54 ;
} else {
V_77 . V_100 = V_101 ;
V_77 . V_102 = V_6 -> V_70 ;
V_77 . V_103 = V_6 -> V_77 ;
}
F_2 ( 1 , L_30 , V_10 , V_77 . V_102 ) ;
F_2 ( 1 , L_31 , V_10 , V_77 . V_103 ) ;
* V_96 = sizeof ( struct V_98 ) ;
memcpy ( V_95 , & V_77 , * V_96 ) ;
return 0 ;
}
static int F_44 ( struct V_93 * V_7 , int V_104 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
int V_9 = - V_105 ;
F_2 ( 2 , L_1 , V_10 ) ;
F_45 ( V_8 ) ;
if ( ( V_8 -> V_26 != V_27 ) && ( V_8 -> V_26 != V_29 ) &&
( V_8 -> V_26 != V_106 ) )
goto V_107;
if ( V_8 -> V_15 != V_108 ) {
V_8 -> V_109 = V_104 ;
V_8 -> V_15 = V_108 ;
V_9 = 0 ;
}
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_47 ( struct V_93 * V_7 , struct V_94 * V_95 , int V_110 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_98 * V_111 = (struct V_98 * ) V_95 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
int V_9 ;
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
if ( V_110 != sizeof( struct V_98 ) )
return - V_112 ;
F_45 ( V_8 ) ;
#ifdef F_48
if ( ( V_8 -> V_26 == V_106 ) &&
( V_8 -> V_113 == V_114 ) ) {
V_6 -> V_71 = V_111 -> V_102 ;
V_9 = - V_105 ;
if ( V_6 -> V_71 & 0x80 ) {
F_2 ( 0 , L_32 , V_10 ) ;
goto V_107;
}
V_9 = F_32 ( V_6 , V_6 -> V_71 ) ;
if ( V_9 < 0 )
goto V_107;
V_7 -> V_115 = V_116 ;
V_8 -> V_15 = V_31 ;
V_9 = 0 ;
goto V_107;
}
#endif
V_6 -> V_117 = F_49 ( V_111 -> V_118 , V_119 ) ;
V_9 = - V_69 ;
if ( V_6 -> V_117 == NULL )
goto V_107;
V_9 = F_29 ( V_6 , V_111 -> V_102 , V_111 -> V_118 ) ;
if ( V_9 < 0 ) {
F_50 ( V_6 -> V_117 ) ;
V_6 -> V_117 = NULL ;
goto V_107;
}
F_51 ( V_6 -> V_117 , L_21 ,
V_6 -> V_70 , V_120 ) ;
F_52 ( V_6 -> V_117 ) ;
V_9 = 0 ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_53 ( struct V_93 * V_7 , struct V_93 * V_121 , int V_122 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_123 , * V_6 = F_43 ( V_8 ) ;
struct V_7 * V_124 ;
struct V_3 * V_4 ;
int V_9 ;
F_2 ( 2 , L_1 , V_10 ) ;
V_9 = F_54 ( F_55 ( V_8 ) , V_121 , V_8 -> V_113 , 0 ) ;
if ( V_9 )
return V_9 ;
V_9 = - V_112 ;
F_45 ( V_8 ) ;
if ( V_7 -> V_115 != V_125 )
goto V_107;
if ( ( V_8 = V_7 -> V_8 ) == NULL )
goto V_107;
V_9 = - V_105 ;
if ( ( V_8 -> V_26 != V_27 ) && ( V_8 -> V_26 != V_29 ) &&
( V_8 -> V_26 != V_106 ) )
goto V_107;
V_9 = - V_112 ;
if ( V_8 -> V_15 != V_108 )
goto V_107;
while ( 1 ) {
V_4 = F_56 ( & V_8 -> V_32 ) ;
if ( V_4 )
break;
V_9 = - V_126 ;
if ( V_122 & V_127 )
goto V_107;
V_9 = F_37 ( * ( F_23 ( V_8 ) ) ,
F_57 ( & V_8 -> V_32 ) ) ;
if ( V_9 )
goto V_107;
}
V_124 = V_121 -> V_8 ;
V_9 = - V_128 ;
if ( V_124 == NULL )
goto V_107;
V_124 -> V_15 = V_31 ;
V_123 = F_43 ( V_124 ) ;
V_123 -> V_20 = F_58 ( V_6 -> V_20 , V_123 ) ;
V_9 = - V_129 ;
if ( ! V_123 -> V_20 ) {
F_2 ( 0 , L_33 , V_10 ) ;
F_14 ( V_4 ) ;
goto V_107;
}
V_123 -> V_70 = V_123 -> V_20 -> V_70 ;
V_123 -> V_83 = V_123 -> V_20 -> V_83 ;
V_123 -> V_77 = F_59 ( V_123 -> V_20 ) ;
V_123 -> V_54 = F_60 ( V_123 -> V_20 ) ;
V_123 -> V_25 = V_6 -> V_25 ;
V_123 -> V_37 = V_6 -> V_37 ;
V_123 -> V_28 = V_6 -> V_28 ;
V_123 -> V_24 = V_6 -> V_24 ;
memcpy ( & V_123 -> V_30 , & V_6 -> V_30 , sizeof( struct V_21 ) ) ;
F_61 ( V_6 -> V_20 ) ;
F_14 ( V_4 ) ;
V_8 -> V_130 -- ;
V_121 -> V_115 = V_116 ;
F_16 ( V_123 ) ;
V_9 = 0 ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_62 ( struct V_93 * V_7 , struct V_94 * V_95 ,
int V_110 , int V_122 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_98 * V_111 = (struct V_98 * ) V_95 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
int V_9 ;
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
F_45 ( V_8 ) ;
V_9 = - V_131 ;
if ( ( V_8 -> V_26 == V_106 ) && ( V_8 -> V_113 == V_114 ) )
goto V_107;
if ( V_8 -> V_15 == V_31 && V_7 -> V_115 == V_132 ) {
V_7 -> V_115 = V_116 ;
V_9 = 0 ;
goto V_107;
}
if ( V_8 -> V_15 == V_16 && V_7 -> V_115 == V_132 ) {
V_7 -> V_115 = V_125 ;
V_9 = - V_133 ;
goto V_107;
}
V_9 = - V_134 ;
if ( V_8 -> V_15 == V_31 )
goto V_107;
V_8 -> V_15 = V_16 ;
V_7 -> V_115 = V_125 ;
V_9 = - V_112 ;
if ( V_110 != sizeof( struct V_98 ) )
goto V_107;
if ( ( ! V_111 -> V_103 ) || ( V_111 -> V_103 == V_88 ) ) {
V_9 = F_39 ( V_6 , V_111 -> V_118 ) ;
if ( V_9 ) {
F_2 ( 0 , L_34 , V_10 ) ;
goto V_107;
}
} else {
V_6 -> V_54 = V_111 -> V_103 ;
F_2 ( 1 , L_35 , V_10 , V_6 -> V_54 ) ;
if( ( V_111 -> V_118 [ 0 ] != '\0' ) ||
( V_111 -> V_102 >= 0x70 ) ) {
V_9 = F_34 ( V_6 , V_111 -> V_118 ) ;
if ( V_9 ) {
F_2 ( 0 , L_36 , V_10 ) ;
goto V_107;
}
} else {
V_6 -> V_83 = V_111 -> V_102 ;
}
}
if ( ! V_6 -> V_20 )
F_29 ( V_6 , V_74 , V_111 -> V_118 ) ;
V_7 -> V_115 = V_132 ;
V_8 -> V_15 = V_135 ;
V_9 = F_63 ( V_6 -> V_20 , V_6 -> V_83 ,
V_6 -> V_77 , V_6 -> V_54 , NULL ,
V_6 -> V_37 , NULL ) ;
if ( V_9 ) {
F_2 ( 0 , L_36 , V_10 ) ;
goto V_107;
}
V_9 = - V_136 ;
if ( V_8 -> V_15 != V_31 && ( V_122 & V_127 ) )
goto V_107;
V_9 = - V_137 ;
if ( F_37 ( * ( F_23 ( V_8 ) ) ,
( V_8 -> V_15 != V_135 ) ) )
goto V_107;
if ( V_8 -> V_15 != V_31 ) {
V_7 -> V_115 = V_125 ;
if ( V_8 -> V_138 -> V_139 ( V_8 , V_122 ) )
V_7 -> V_115 = V_140 ;
V_9 = F_64 ( V_8 ) ;
if ( ! V_9 )
V_9 = - V_141 ;
goto V_107;
}
V_7 -> V_115 = V_116 ;
V_6 -> V_77 = F_59 ( V_6 -> V_20 ) ;
V_9 = 0 ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_54 ( struct V_142 * V_142 , struct V_93 * V_7 , int V_143 ,
int V_144 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
F_2 ( 2 , L_1 , V_10 ) ;
if ( V_142 != & V_145 )
return - V_146 ;
switch ( V_7 -> type ) {
case V_27 :
case V_29 :
case V_106 :
break;
default:
return - V_131 ;
}
V_8 = F_65 ( V_142 , V_147 , V_35 , & V_148 ) ;
if ( V_8 == NULL )
return - V_69 ;
V_6 = F_43 ( V_8 ) ;
F_2 ( 2 , L_37 , V_10 , V_6 ) ;
F_66 ( & V_6 -> V_49 ) ;
switch ( V_7 -> type ) {
case V_27 :
V_7 -> V_149 = & V_150 ;
V_6 -> V_37 = V_151 ;
break;
case V_29 :
V_7 -> V_149 = & V_152 ;
V_6 -> V_37 = V_153 ;
break;
case V_106 :
switch ( V_143 ) {
#ifdef F_48
case V_114 :
V_7 -> V_149 = & V_154 ;
V_6 -> V_28 = V_155 - V_156 ;
V_6 -> V_24 = V_36 + V_156 ;
break;
#endif
case V_157 :
V_7 -> V_149 = & V_158 ;
V_6 -> V_37 = V_153 ;
break;
default:
F_67 ( V_8 ) ;
return - V_131 ;
}
break;
default:
F_67 ( V_8 ) ;
return - V_131 ;
}
F_68 ( V_7 , V_8 ) ;
V_8 -> V_159 = V_147 ;
V_8 -> V_113 = V_143 ;
V_6 -> V_160 = F_69 ( 0 , NULL , NULL , NULL ) ;
V_6 -> V_89 . V_90 = 0xffff ;
V_6 -> V_11 = V_6 -> V_39 = V_40 ;
V_6 -> V_91 = V_161 ;
V_6 -> V_54 = V_88 ;
V_6 -> V_77 = 0x0 ;
return 0 ;
}
static void F_70 ( struct V_5 * V_6 )
{
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
F_71 ( V_6 -> V_160 ) ;
F_72 ( V_6 -> V_162 ) ;
if ( V_6 -> V_117 ) {
F_50 ( V_6 -> V_117 ) ;
V_6 -> V_117 = NULL ;
}
if ( V_6 -> V_46 ) {
F_26 ( V_6 -> V_46 ) ;
V_6 -> V_46 = NULL ;
}
if ( V_6 -> V_20 ) {
F_73 ( V_6 -> V_20 , NULL , V_163 ) ;
F_8 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
#ifdef F_48
if ( V_6 -> V_72 ) {
F_74 ( V_6 -> V_72 ) ;
V_6 -> V_72 = NULL ;
}
#endif
}
static int F_75 ( struct V_93 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_2 ( 2 , L_1 , V_10 ) ;
if ( V_8 == NULL )
return 0 ;
F_45 ( V_8 ) ;
V_8 -> V_15 = V_16 ;
V_8 -> V_17 |= V_18 ;
V_8 -> V_19 ( V_8 ) ;
F_70 ( F_43 ( V_8 ) ) ;
F_76 ( V_8 ) ;
V_7 -> V_8 = NULL ;
F_46 ( V_8 ) ;
F_77 ( & V_8 -> V_32 ) ;
F_78 ( V_8 ) ;
return 0 ;
}
static int F_79 ( struct V_164 * V_165 , struct V_93 * V_7 ,
struct V_166 * V_167 , T_10 V_168 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_9 = - V_169 ;
F_2 ( 4 , L_38 , V_10 , V_168 ) ;
if ( V_167 -> V_170 & ~ ( V_171 | V_172 | V_173 |
V_174 ) ) {
return - V_112 ;
}
F_45 ( V_8 ) ;
if ( V_8 -> V_17 & V_18 )
goto V_175;
if ( V_8 -> V_15 != V_31 ) {
V_9 = - V_99 ;
goto V_107;
}
V_6 = F_43 ( V_8 ) ;
if ( F_37 ( * ( F_23 ( V_8 ) ) ,
( V_6 -> V_39 != V_12 || V_8 -> V_15 != V_31 ) ) ) {
V_9 = - V_137 ;
goto V_107;
}
if ( V_8 -> V_15 != V_31 ) {
V_9 = - V_99 ;
goto V_107;
}
if ( V_168 > V_6 -> V_28 ) {
F_2 ( 2 , L_39 ,
V_10 , V_168 , V_6 -> V_28 ) ;
V_168 = V_6 -> V_28 ;
}
V_4 = F_80 ( V_8 , V_168 + V_6 -> V_24 + 16 ,
V_167 -> V_170 & V_171 , & V_9 ) ;
if ( ! V_4 )
goto V_175;
F_18 ( V_4 , V_6 -> V_24 + 16 ) ;
F_81 ( V_4 ) ;
F_82 ( V_4 , V_168 ) ;
V_9 = F_83 ( F_84 ( V_4 ) , V_167 -> V_176 , V_168 ) ;
if ( V_9 ) {
F_14 ( V_4 ) ;
goto V_175;
}
V_9 = F_85 ( V_6 -> V_20 , V_4 ) ;
if ( V_9 ) {
F_2 ( 0 , L_40 , V_10 , V_9 ) ;
goto V_175;
}
F_46 ( V_8 ) ;
return V_168 ;
V_175:
V_9 = F_86 ( V_8 , V_167 -> V_170 , V_9 ) ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_87 ( struct V_164 * V_165 , struct V_93 * V_7 ,
struct V_166 * V_167 , T_10 V_177 , int V_122 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
struct V_3 * V_4 ;
T_10 V_178 ;
int V_9 ;
F_2 ( 4 , L_1 , V_10 ) ;
V_4 = F_88 ( V_8 , V_122 & ~ V_171 ,
V_122 & V_171 , & V_9 ) ;
if ( ! V_4 )
return V_9 ;
F_81 ( V_4 ) ;
V_178 = V_4 -> V_168 ;
if ( V_178 > V_177 ) {
F_2 ( 2 , L_41 ,
V_10 , V_178 , V_177 ) ;
V_178 = V_177 ;
V_167 -> V_170 |= V_179 ;
}
F_89 ( V_4 , 0 , V_167 -> V_176 , V_178 ) ;
F_90 ( V_8 , V_4 ) ;
if ( V_6 -> V_11 == V_12 ) {
if ( ( F_91 ( & V_8 -> V_180 ) << 2 ) <= V_8 -> V_181 ) {
F_2 ( 2 , L_42 , V_10 ) ;
V_6 -> V_11 = V_40 ;
F_92 ( V_6 -> V_20 , V_40 ) ;
}
}
return V_178 ;
}
static int F_93 ( struct V_164 * V_165 , struct V_93 * V_7 ,
struct V_166 * V_167 , T_10 V_177 , int V_122 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
int V_182 = V_122 & V_171 ;
T_10 V_178 = 0 ;
int V_183 , V_9 ;
long V_184 ;
F_2 ( 3 , L_1 , V_10 ) ;
if ( ( V_9 = F_64 ( V_8 ) ) < 0 )
return V_9 ;
if ( V_7 -> V_122 & V_185 )
return - V_112 ;
V_9 = - V_105 ;
if ( V_122 & V_186 )
return - V_105 ;
V_9 = 0 ;
V_183 = F_94 ( V_8 , V_122 & V_187 , V_177 ) ;
V_184 = F_95 ( V_8 , V_182 ) ;
do {
int V_188 ;
struct V_3 * V_4 = F_56 ( & V_8 -> V_32 ) ;
if ( V_4 == NULL ) {
F_96 ( V_189 ) ;
V_9 = 0 ;
if ( V_178 >= V_183 )
break;
F_97 ( F_23 ( V_8 ) , & V_189 , V_190 ) ;
V_9 = F_64 ( V_8 ) ;
if ( V_9 )
;
else if ( V_8 -> V_17 & V_191 )
;
else if ( V_182 )
V_9 = - V_192 ;
else if ( F_98 ( V_193 ) )
V_9 = F_99 ( V_184 ) ;
else if ( V_8 -> V_15 != V_31 )
V_9 = - V_99 ;
else if ( F_57 ( & V_8 -> V_32 ) == NULL )
F_100 () ;
F_101 ( F_23 ( V_8 ) , & V_189 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 -> V_17 & V_191 )
break;
continue;
}
V_188 = F_102 (unsigned int, skb->len, size) ;
if ( F_103 ( V_167 -> V_176 , V_4 -> V_194 , V_188 ) ) {
F_104 ( & V_8 -> V_32 , V_4 ) ;
if ( V_178 == 0 )
V_178 = - V_195 ;
break;
}
V_178 += V_188 ;
V_177 -= V_188 ;
if ( ! ( V_122 & V_196 ) ) {
F_105 ( V_4 , V_188 ) ;
if ( V_4 -> V_168 ) {
F_2 ( 1 , L_43 ,
V_10 ) ;
F_104 ( & V_8 -> V_32 , V_4 ) ;
break;
}
F_14 ( V_4 ) ;
} else {
F_2 ( 0 , L_44 , V_10 ) ;
F_104 ( & V_8 -> V_32 , V_4 ) ;
break;
}
} while ( V_177 );
if ( V_6 -> V_11 == V_12 ) {
if ( ( F_91 ( & V_8 -> V_180 ) << 2 ) <= V_8 -> V_181 ) {
F_2 ( 2 , L_42 , V_10 ) ;
V_6 -> V_11 = V_40 ;
F_92 ( V_6 -> V_20 , V_40 ) ;
}
}
return V_178 ;
}
static int F_106 ( struct V_164 * V_165 , struct V_93 * V_7 ,
struct V_166 * V_167 , T_10 V_168 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_9 ;
F_2 ( 4 , L_38 , V_10 , V_168 ) ;
if ( V_167 -> V_170 & ~ ( V_171 | V_173 ) )
return - V_112 ;
F_45 ( V_8 ) ;
if ( V_8 -> V_17 & V_18 ) {
F_107 ( V_197 , V_193 , 0 ) ;
V_9 = - V_169 ;
goto V_107;
}
V_9 = - V_99 ;
if ( V_8 -> V_15 != V_31 )
goto V_107;
V_6 = F_43 ( V_8 ) ;
if ( V_168 > V_6 -> V_28 ) {
F_2 ( 0 , L_45
L_46 ,
V_10 , V_168 , V_6 -> V_28 ) ;
V_168 = V_6 -> V_28 ;
}
V_4 = F_80 ( V_8 , V_168 + V_6 -> V_24 ,
V_167 -> V_170 & V_171 , & V_9 ) ;
V_9 = - V_198 ;
if ( ! V_4 )
goto V_107;
F_18 ( V_4 , V_6 -> V_24 ) ;
F_81 ( V_4 ) ;
F_2 ( 4 , L_47 , V_10 ) ;
F_82 ( V_4 , V_168 ) ;
V_9 = F_83 ( F_84 ( V_4 ) , V_167 -> V_176 , V_168 ) ;
if ( V_9 ) {
F_14 ( V_4 ) ;
goto V_107;
}
V_9 = F_108 ( V_6 -> V_20 , V_4 ) ;
if ( V_9 ) {
F_2 ( 0 , L_40 , V_10 , V_9 ) ;
goto V_107;
}
F_46 ( V_8 ) ;
return V_168 ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_109 ( struct V_164 * V_165 , struct V_93 * V_7 ,
struct V_166 * V_167 , T_10 V_168 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 ;
T_3 V_71 = 0 ;
int V_199 = 0 ;
struct V_3 * V_4 ;
int V_9 ;
F_2 ( 4 , L_38 , V_10 , V_168 ) ;
V_9 = - V_112 ;
if ( V_167 -> V_170 & ~ ( V_171 | V_173 ) )
return - V_112 ;
F_45 ( V_8 ) ;
V_9 = - V_169 ;
if ( V_8 -> V_17 & V_18 ) {
F_107 ( V_197 , V_193 , 0 ) ;
goto V_107;
}
V_6 = F_43 ( V_8 ) ;
if ( V_167 -> V_200 ) {
F_110 ( struct V_98 * , V_111 , V_167 -> V_200 ) ;
V_9 = - V_112 ;
if ( V_167 -> V_201 < sizeof( * V_111 ) )
goto V_107;
if ( V_111 -> V_100 != V_101 )
goto V_107;
V_71 = V_111 -> V_102 ;
if ( V_71 & 0x80 ) {
F_2 ( 0 , L_32 , V_10 ) ;
V_9 = - V_105 ;
goto V_107;
}
} else {
if ( ( V_6 -> V_72 == NULL ) ||
( V_8 -> V_15 != V_31 ) ) {
F_2 ( 0 , L_48 ,
V_10 ) ;
V_9 = - V_99 ;
goto V_107;
}
V_199 = 1 ;
}
if ( V_168 > V_6 -> V_28 ) {
F_2 ( 0 , L_45
L_46 ,
V_10 , V_168 , V_6 -> V_28 ) ;
V_168 = V_6 -> V_28 ;
}
V_4 = F_80 ( V_8 , V_168 + V_6 -> V_24 ,
V_167 -> V_170 & V_171 , & V_9 ) ;
V_9 = - V_198 ;
if ( ! V_4 )
goto V_107;
F_18 ( V_4 , V_6 -> V_24 ) ;
F_81 ( V_4 ) ;
F_2 ( 4 , L_47 , V_10 ) ;
F_82 ( V_4 , V_168 ) ;
V_9 = F_83 ( F_84 ( V_4 ) , V_167 -> V_176 , V_168 ) ;
if ( V_9 ) {
F_14 ( V_4 ) ;
goto V_107;
}
V_9 = F_111 ( ( V_199 ? V_6 -> V_72 : NULL ) ,
V_4 , V_71 ) ;
if ( V_9 )
F_2 ( 0 , L_40 , V_10 , V_9 ) ;
V_107:
F_46 ( V_8 ) ;
return V_9 ? : V_168 ;
}
static int F_112 ( struct V_93 * V_7 , int V_202 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
F_2 ( 1 , L_3 , V_10 , V_6 ) ;
F_45 ( V_8 ) ;
V_8 -> V_15 = V_16 ;
V_8 -> V_17 |= V_18 ;
V_8 -> V_19 ( V_8 ) ;
if ( V_6 -> V_46 ) {
F_26 ( V_6 -> V_46 ) ;
V_6 -> V_46 = NULL ;
}
if ( V_6 -> V_20 ) {
F_73 ( V_6 -> V_20 , NULL , V_163 ) ;
F_8 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
V_6 -> V_11 = V_6 -> V_39 = V_40 ;
V_6 -> V_54 = V_88 ;
V_6 -> V_77 = 0x0 ;
F_46 ( V_8 ) ;
return 0 ;
}
static unsigned int F_113 ( struct V_203 * V_203 , struct V_93 * V_7 ,
T_11 * V_189 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
unsigned int V_89 ;
F_2 ( 4 , L_1 , V_10 ) ;
F_114 ( V_203 , F_23 ( V_8 ) , V_189 ) ;
V_89 = 0 ;
if ( V_8 -> V_204 )
V_89 |= V_205 ;
if ( V_8 -> V_17 & V_191 ) {
F_2 ( 0 , L_49 , V_10 ) ;
V_89 |= V_206 ;
}
if ( ! F_115 ( & V_8 -> V_32 ) ) {
F_2 ( 4 , L_50 ) ;
V_89 |= V_207 | V_208 ;
}
switch ( V_8 -> V_26 ) {
case V_27 :
if ( V_8 -> V_15 == V_16 ) {
F_2 ( 0 , L_49 , V_10 ) ;
V_89 |= V_206 ;
}
if ( V_8 -> V_15 == V_31 ) {
if ( ( V_6 -> V_39 == V_40 ) &&
F_116 ( V_8 ) )
{
V_89 |= V_209 | V_210 | V_211 ;
}
}
break;
case V_29 :
if ( ( V_6 -> V_39 == V_40 ) &&
F_116 ( V_8 ) )
{
V_89 |= V_209 | V_210 | V_211 ;
}
break;
case V_106 :
if ( F_116 ( V_8 ) )
V_89 |= V_209 | V_210 | V_211 ;
break;
default:
break;
}
return V_89 ;
}
static int F_117 ( struct V_93 * V_7 , unsigned int V_212 , unsigned long V_213 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
int V_9 ;
F_2 ( 4 , L_51 , V_10 , V_212 ) ;
V_9 = - V_112 ;
switch ( V_212 ) {
case V_214 : {
long V_215 ;
V_215 = V_8 -> V_216 - F_118 ( V_8 ) ;
if ( V_215 < 0 )
V_215 = 0 ;
V_9 = F_119 ( V_215 , ( unsigned int V_217 * ) V_213 ) ;
break;
}
case V_218 : {
struct V_3 * V_4 ;
long V_215 = 0L ;
if ( ( V_4 = F_57 ( & V_8 -> V_32 ) ) != NULL )
V_215 = V_4 -> V_168 ;
V_9 = F_119 ( V_215 , ( unsigned int V_217 * ) V_213 ) ;
break;
}
case V_219 :
if ( V_8 != NULL )
V_9 = F_120 ( V_8 , (struct V_220 V_217 * ) V_213 ) ;
break;
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
break;
default:
F_2 ( 1 , L_52 , V_10 ) ;
V_9 = - V_231 ;
}
return V_9 ;
}
static int F_121 ( struct V_93 * V_7 , unsigned int V_212 , unsigned long V_213 )
{
return - V_231 ;
}
static int F_122 ( struct V_93 * V_7 , int V_232 , int V_233 ,
char V_217 * V_234 , unsigned int V_235 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
struct V_236 * V_237 ;
struct V_238 * V_117 ;
struct V_239 * V_240 ;
int V_241 , V_242 = 0 , V_9 = 0 ;
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
if ( V_232 != V_243 )
return - V_244 ;
F_45 ( V_8 ) ;
switch ( V_233 ) {
case V_245 :
if ( V_235 != sizeof( struct V_236 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_237 = F_123 ( sizeof( struct V_236 ) , V_246 ) ;
if ( V_237 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_237 , V_234 , V_235 ) ) {
F_41 ( V_237 ) ;
V_9 = - V_195 ;
goto V_107;
}
if( V_237 -> V_247 [ 0 ] == '\0' ) {
if( V_6 -> V_117 == NULL ) {
F_41 ( V_237 ) ;
V_9 = - V_112 ;
goto V_107;
}
V_117 = V_6 -> V_117 ;
} else
V_117 = F_125 ( V_237 -> V_247 ) ;
if( ( ! F_126 ( V_248 ) ) &&
( ( V_117 == NULL ) || ( V_117 != V_6 -> V_117 ) ) ) {
F_41 ( V_237 ) ;
V_9 = - V_129 ;
goto V_107;
}
if( V_117 == (struct V_238 * ) NULL ) {
V_117 = F_49 ( V_237 -> V_247 ,
V_119 ) ;
if ( V_117 == NULL ) {
F_41 ( V_237 ) ;
V_9 = - V_69 ;
goto V_107;
}
V_242 = 1 ;
}
if( F_127 ( V_117 , V_237 -> V_249 ) ) {
F_41 ( V_237 ) ;
if ( V_242 ) {
F_41 ( V_117 -> V_58 ) ;
F_41 ( V_117 ) ;
}
V_9 = - V_112 ;
goto V_107;
}
switch( V_237 -> V_250 ) {
case V_81 :
F_51 (
V_117 ,
V_237 -> V_249 ,
V_237 -> V_251 . V_252 ,
V_253 ) ;
break;
case V_254 :
if( V_237 -> V_251 . V_255 . V_168 >
V_256 ) {
F_41 ( V_237 ) ;
if ( V_242 ) {
F_41 ( V_117 -> V_58 ) ;
F_41 ( V_117 ) ;
}
V_9 = - V_112 ;
goto V_107;
}
F_128 (
V_117 ,
V_237 -> V_249 ,
V_237 -> V_251 . V_255 . V_257 ,
V_237 -> V_251 . V_255 . V_168 ,
V_253 ) ;
break;
case V_258 :
V_237 -> V_251 . V_259 . string [ V_237 -> V_251 . V_259 . V_168 ] = '\0' ;
F_129 (
V_117 ,
V_237 -> V_249 ,
V_237 -> V_251 . V_259 . string ,
V_253 ) ;
break;
default :
F_41 ( V_237 ) ;
if ( V_242 ) {
F_41 ( V_117 -> V_58 ) ;
F_41 ( V_117 ) ;
}
V_9 = - V_112 ;
goto V_107;
}
F_52 ( V_117 ) ;
F_41 ( V_237 ) ;
break;
case V_260 :
if ( V_235 != sizeof( struct V_236 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_237 = F_123 ( sizeof( struct V_236 ) , V_246 ) ;
if ( V_237 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_237 , V_234 , V_235 ) ) {
F_41 ( V_237 ) ;
V_9 = - V_195 ;
goto V_107;
}
if( V_237 -> V_247 [ 0 ] == '\0' )
V_117 = V_6 -> V_117 ;
else
V_117 = F_125 ( V_237 -> V_247 ) ;
if( V_117 == (struct V_238 * ) NULL ) {
F_41 ( V_237 ) ;
V_9 = - V_112 ;
goto V_107;
}
if( ( ! F_126 ( V_248 ) ) &&
( ( V_117 == NULL ) || ( V_117 != V_6 -> V_117 ) ) ) {
F_41 ( V_237 ) ;
V_9 = - V_129 ;
goto V_107;
}
V_240 = F_127 ( V_117 ,
V_237 -> V_249 ) ;
if( V_240 == (struct V_239 * ) NULL ) {
F_41 ( V_237 ) ;
V_9 = - V_112 ;
goto V_107;
}
if( V_240 -> V_44 -> V_261 != V_253 ) {
F_2 ( 1 , L_53 , V_10 ) ;
F_41 ( V_237 ) ;
V_9 = - V_129 ;
goto V_107;
}
F_130 ( V_117 , V_240 , 1 ) ;
F_41 ( V_237 ) ;
break;
case V_262 :
if ( V_235 < sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_241 , ( int V_217 * ) V_234 ) ) {
V_9 = - V_195 ;
goto V_107;
}
if ( V_8 -> V_26 != V_29 ) {
F_2 ( 2 , L_54 ,
V_10 , V_241 ) ;
V_6 -> V_37 = V_241 ;
} else {
F_25 ( L_55 ,
V_10 ) ;
V_9 = - V_244 ;
goto V_107;
}
break;
case V_263 :
if ( V_235 < sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_241 , ( int V_217 * ) V_234 ) ) {
V_9 = - V_195 ;
goto V_107;
}
if ( V_6 -> V_162 )
F_72 ( V_6 -> V_162 ) ;
V_6 -> V_162 = F_132 ( ( T_5 ) V_241 ) ;
break;
case V_264 :
if ( V_235 < sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_241 , ( int V_217 * ) V_234 ) ) {
V_9 = - V_195 ;
goto V_107;
}
V_6 -> V_89 . V_90 = ( T_5 ) V_241 ;
V_6 -> V_89 . V_90 &= 0x7f7f ;
if( ! V_6 -> V_89 . V_90 )
V_6 -> V_89 . V_90 = 0xFFFF ;
break;
default:
V_9 = - V_244 ;
break;
}
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_133 ( struct V_236 * V_237 ,
struct V_43 * V_43 )
{
switch ( V_43 -> type ) {
case V_81 :
V_237 -> V_251 . V_252 = V_43 -> V_82 . integer ;
break;
case V_254 :
V_237 -> V_251 . V_255 . V_168 = V_43 -> V_168 ;
memcpy ( V_237 -> V_251 . V_255 . V_257 ,
V_43 -> V_82 . V_265 , V_43 -> V_168 ) ;
break;
case V_258 :
V_237 -> V_251 . V_259 . V_168 = V_43 -> V_168 ;
V_237 -> V_251 . V_259 . V_266 = V_43 -> V_266 ;
memcpy ( V_237 -> V_251 . V_259 . string ,
V_43 -> V_82 . string , V_43 -> V_168 ) ;
V_237 -> V_251 . V_259 . string [ V_43 -> V_168 ] = '\0' ;
break;
case V_267 :
default :
return - V_112 ;
}
V_237 -> V_250 = V_43 -> type ;
return 0 ;
}
static int F_134 ( struct V_93 * V_7 , int V_232 , int V_233 ,
char V_217 * V_234 , int V_217 * V_235 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
struct V_268 V_269 ;
struct V_270 * V_84 ;
struct V_236 * V_237 ;
struct V_238 * V_117 ;
struct V_239 * V_240 ;
int V_54 = V_88 ;
int V_271 = 0 ;
int V_168 = 0 ;
int V_9 = 0 ;
int V_272 , V_273 ;
F_2 ( 2 , L_3 , V_10 , V_6 ) ;
if ( V_232 != V_243 )
return - V_244 ;
if ( F_131 ( V_168 , V_235 ) )
return - V_195 ;
if( V_168 < 0 )
return - V_112 ;
F_45 ( V_8 ) ;
switch ( V_233 ) {
case V_274 :
V_272 = sizeof( struct V_268 ) -
sizeof( struct V_270 ) ;
if ( V_168 < V_272 ) {
V_9 = - V_112 ;
goto V_107;
}
V_84 = F_40 ( & V_269 . V_168 , V_6 -> V_89 . V_90 ,
V_6 -> V_91 ) ;
if ( V_84 == NULL ) {
V_9 = - V_192 ;
goto V_107;
}
if ( F_135 ( V_234 , & V_269 , V_272 ) )
V_9 = - V_195 ;
if ( V_269 . V_168 > 2048 ) {
V_9 = - V_112 ;
goto V_275;
}
V_273 = V_272 + ( V_269 . V_168 * sizeof( struct V_270 ) ) ;
if ( V_273 > V_168 )
V_273 = V_168 ;
if ( F_135 ( V_234 + V_272 , V_84 , V_273 - V_272 ) )
V_9 = - V_195 ;
if ( F_119 ( V_273 , V_235 ) )
V_9 = - V_195 ;
V_275:
F_41 ( V_84 ) ;
break;
case V_262 :
V_271 = V_6 -> V_28 ;
V_168 = sizeof( int ) ;
if ( F_119 ( V_168 , V_235 ) ) {
V_9 = - V_195 ;
goto V_107;
}
if ( F_135 ( V_234 , & V_271 , V_168 ) ) {
V_9 = - V_195 ;
goto V_107;
}
break;
case V_276 :
if ( V_168 != sizeof( struct V_236 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_237 = F_123 ( sizeof( struct V_236 ) , V_246 ) ;
if ( V_237 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_237 , V_234 , V_168 ) ) {
F_41 ( V_237 ) ;
V_9 = - V_195 ;
goto V_107;
}
if( V_237 -> V_247 [ 0 ] == '\0' )
V_117 = V_6 -> V_117 ;
else
V_117 = F_125 ( V_237 -> V_247 ) ;
if( V_117 == (struct V_238 * ) NULL ) {
F_41 ( V_237 ) ;
V_9 = - V_112 ;
goto V_107;
}
V_240 = F_127 ( V_117 ,
V_237 -> V_249 ) ;
if( V_240 == (struct V_239 * ) NULL ) {
F_41 ( V_237 ) ;
V_9 = - V_112 ;
goto V_107;
}
V_9 = F_133 ( V_237 , V_240 -> V_44 ) ;
if( V_9 ) {
F_41 ( V_237 ) ;
goto V_107;
}
if ( F_135 ( V_234 , V_237 ,
sizeof( struct V_236 ) ) ) {
F_41 ( V_237 ) ;
V_9 = - V_195 ;
goto V_107;
}
F_41 ( V_237 ) ;
break;
case V_277 :
if ( V_168 != sizeof( struct V_236 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_237 = F_123 ( sizeof( struct V_236 ) , V_246 ) ;
if ( V_237 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_237 , V_234 , V_168 ) ) {
F_41 ( V_237 ) ;
V_9 = - V_195 ;
goto V_107;
}
if( V_6 -> V_54 != V_88 ) {
V_54 = V_6 -> V_54 ;
} else {
V_54 = V_237 -> V_54 ;
if( ( ! V_54 ) || ( V_54 == V_88 ) ) {
F_41 ( V_237 ) ;
V_9 = - V_112 ;
goto V_107;
}
}
if ( V_6 -> V_46 ) {
F_25 ( L_56 ,
V_10 ) ;
F_41 ( V_237 ) ;
V_9 = - V_60 ;
goto V_107;
}
V_6 -> V_46 = F_35 ( V_74 , V_75 , V_6 ,
F_24 ) ;
if ( V_6 -> V_46 == NULL ) {
F_41 ( V_237 ) ;
V_9 = - V_69 ;
goto V_107;
}
V_6 -> V_48 = - V_76 ;
F_36 ( V_6 -> V_46 ,
V_6 -> V_77 , V_54 ,
V_237 -> V_247 ,
V_237 -> V_249 ) ;
if ( F_37 ( V_6 -> V_49 ,
( V_6 -> V_46 == NULL ) ) ) {
F_41 ( V_237 ) ;
V_9 = - V_76 ;
goto V_107;
}
if ( V_6 -> V_48 )
{
F_41 ( V_237 ) ;
if( ( V_6 -> V_48 == V_78 ) ||
( V_6 -> V_48 == V_79 ) )
V_9 = - V_80 ;
else
V_9 = - V_76 ;
goto V_107;
}
V_9 = F_133 ( V_237 , V_6 -> V_50 ) ;
if ( V_6 -> V_50 )
F_38 ( V_6 -> V_50 ) ;
if ( V_9 ) {
F_41 ( V_237 ) ;
goto V_107;
}
if ( F_135 ( V_234 , V_237 ,
sizeof( struct V_236 ) ) ) {
F_41 ( V_237 ) ;
V_9 = - V_195 ;
goto V_107;
}
F_41 ( V_237 ) ;
break;
case V_278 :
if ( V_168 != sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_271 , ( int V_217 * ) V_234 ) ) {
V_9 = - V_195 ;
goto V_107;
}
F_136 ( V_6 -> V_160 , V_6 -> V_89 . V_90 ,
F_27 ,
NULL , ( void * ) V_6 ) ;
F_137 ( V_6 -> V_91 ) ;
if ( ! V_6 -> V_53 ) {
F_2 ( 1 , L_57 , V_10 ) ;
V_6 -> V_48 = 0 ;
F_138 ( & V_6 -> V_279 , F_28 ,
( unsigned long ) V_6 ) ;
F_139 ( & V_6 -> V_279 ,
V_119 + F_140 ( V_271 ) ) ;
V_9 = F_141 ( V_6 -> V_49 ,
( V_6 -> V_53 != 0 || V_6 -> V_48 == - V_56 ) ) ;
F_142 ( & ( V_6 -> V_279 ) ) ;
F_2 ( 1 , L_58 , V_10 ) ;
if ( V_9 != 0 )
goto V_107;
}
else
F_2 ( 1 , L_59 ,
V_10 ) ;
F_136 ( V_6 -> V_160 , V_6 -> V_89 . V_90 ,
NULL , NULL , NULL ) ;
if ( ! V_6 -> V_53 ) {
V_9 = - V_192 ;
goto V_107;
}
V_54 = V_6 -> V_53 ;
V_6 -> V_53 = 0 ;
if ( F_119 ( V_54 , ( int V_217 * ) V_234 ) ) {
V_9 = - V_195 ;
goto V_107;
}
break;
default:
V_9 = - V_244 ;
}
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
int T_12 F_143 ( void )
{
int V_280 = F_144 ( & V_148 , 0 ) ;
if ( V_280 == 0 )
V_280 = F_145 ( & V_281 ) ;
return V_280 ;
}
void F_146 ( void )
{
F_147 ( V_147 ) ;
F_148 ( & V_148 ) ;
}
