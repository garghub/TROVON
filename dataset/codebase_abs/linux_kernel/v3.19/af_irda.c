static int F_1 ( void * V_1 , void * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_6 = V_1 ;
V_8 = V_1 ;
V_9 = F_2 ( V_8 , V_4 ) ;
if ( V_9 ) {
F_3 ( L_1 , V_10 ) ;
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
F_3 ( L_2 , V_10 , V_6 ) ;
if( V_4 )
F_5 ( V_4 ) ;
V_8 = V_1 ;
if ( V_8 == NULL ) {
F_3 ( L_3 ,
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
F_3 ( L_2 , V_10 , V_6 ) ;
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
F_11 ( L_4 ,
V_10 ) ;
return;
}
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
break;
case V_29 :
if ( V_23 == 0 ) {
F_11 ( L_5 ,
V_10 ) ;
return;
}
V_6 -> V_28 = V_23 ;
break;
default:
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
}
F_3 ( L_6 , V_10 ,
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
F_3 ( L_2 , V_10 , V_6 ) ;
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
F_11 ( L_4 ,
V_10 ) ;
F_14 ( V_4 ) ;
return;
}
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
break;
case V_29 :
if ( V_23 == 0 ) {
F_11 ( L_5 ,
V_10 ) ;
F_14 ( V_4 ) ;
return;
}
V_6 -> V_28 = V_23 ;
break;
default:
V_6 -> V_28 = F_12 ( V_6 -> V_20 ) ;
}
F_3 ( L_6 , V_10 ,
V_6 -> V_28 ) ;
memcpy ( & V_6 -> V_30 , V_22 , sizeof( struct V_21 ) ) ;
F_15 ( & V_8 -> V_32 , V_4 ) ;
V_8 -> V_19 ( V_8 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = F_17 ( V_33 + V_34 , V_35 ) ;
if ( V_4 == NULL ) {
F_3 ( L_7 ,
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
V_6 = V_1 ;
V_8 = V_1 ;
F_21 ( V_8 == NULL ) ;
switch ( V_38 ) {
case V_12 :
F_3 ( L_8 ,
V_10 ) ;
V_6 -> V_39 = V_38 ;
break;
case V_40 :
V_6 -> V_39 = V_38 ;
F_3 ( L_9 ,
V_10 ) ;
F_22 ( F_23 ( V_8 ) ) ;
break;
default:
F_3 ( L_10 , V_10 ) ;
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
F_25 ( L_11 , V_10 ) ;
return;
}
F_3 ( L_2 , V_10 , V_6 ) ;
F_26 ( V_6 -> V_46 ) ;
V_6 -> V_46 = NULL ;
if ( V_41 != V_47 ) {
F_3 ( L_12 , V_10 ,
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
V_6 = V_45 ;
if ( ! V_6 ) {
F_25 ( L_11 , V_10 ) ;
return;
}
V_6 -> V_53 = V_51 -> V_54 ;
F_22 ( & V_6 -> V_49 ) ;
}
static void F_28 ( T_8 V_45 )
{
struct V_5 * V_6 ;
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
F_3 ( L_13 , V_10 ) ;
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
F_3 ( L_14 ,
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
F_25 ( L_15 , V_10 ) ;
return - V_60 ;
}
F_30 ( & V_59 ) ;
V_59 . V_65 = F_1 ;
V_59 . V_1 = V_6 ;
strncpy ( V_59 . V_58 , L_16 , V_67 ) ;
V_6 -> V_72 = F_33 ( V_73 , & V_59 , V_71 ) ;
if ( V_6 -> V_72 == NULL ) {
F_3 ( L_17 , V_10 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_34 ( struct V_5 * V_6 , char * V_58 )
{
F_3 ( L_18 , V_10 , V_6 , V_58 ) ;
if ( V_6 -> V_46 ) {
F_25 ( L_19 ,
V_10 ) ;
return - V_60 ;
}
V_6 -> V_46 = F_35 ( V_74 , V_75 , V_6 ,
F_24 ) ;
if( V_6 -> V_46 == NULL )
return - V_69 ;
V_6 -> V_48 = - V_76 ;
F_36 ( V_6 -> V_46 , V_6 -> V_77 , V_6 -> V_54 ,
V_58 , L_20 ) ;
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
F_3 ( L_21 ,
V_10 , V_6 -> V_50 -> V_82 . integer ) ;
if ( V_6 -> V_50 -> V_82 . integer != - 1 )
V_6 -> V_83 = V_6 -> V_50 -> V_82 . integer ;
else
V_6 -> V_83 = 0 ;
break;
default:
V_6 -> V_83 = 0 ;
F_3 ( L_22 , V_10 ) ;
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
F_3 ( L_23 , V_10 , V_58 ) ;
V_84 = F_40 ( & V_85 , V_6 -> V_89 . V_90 ,
V_6 -> V_91 ) ;
if ( V_84 == NULL )
return - V_87 ;
for( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
V_6 -> V_54 = V_84 [ V_86 ] . V_54 ;
V_6 -> V_77 = 0x0 ;
F_3 ( L_24 ,
V_10 , V_6 -> V_54 ) ;
V_9 = F_34 ( V_6 , V_58 ) ;
switch ( V_9 ) {
case 0 :
if( V_54 != V_88 ) {
F_3 ( L_25 ,
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
F_3 ( L_26 ,
V_10 ) ;
V_6 -> V_54 = V_88 ;
F_41 ( V_84 ) ;
return - V_76 ;
}
}
F_41 ( V_84 ) ;
if( V_54 == V_88 ) {
F_3 ( L_27 ,
V_10 , V_58 ) ;
V_6 -> V_54 = V_88 ;
return - V_80 ;
}
V_6 -> V_54 = V_54 ;
V_6 -> V_77 = 0x0 ;
V_6 -> V_83 = V_83 ;
F_3 ( L_28 ,
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
F_3 ( L_29 , V_10 , V_77 . V_102 ) ;
F_3 ( L_30 , V_10 , V_77 . V_103 ) ;
* V_96 = sizeof ( struct V_98 ) ;
memcpy ( V_95 , & V_77 , * V_96 ) ;
return 0 ;
}
static int F_44 ( struct V_93 * V_7 , int V_104 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
int V_9 = - V_105 ;
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
F_3 ( L_2 , V_10 , V_6 ) ;
if ( V_110 != sizeof( struct V_98 ) )
return - V_112 ;
F_45 ( V_8 ) ;
#ifdef F_48
if ( ( V_8 -> V_26 == V_106 ) &&
( V_8 -> V_113 == V_114 ) ) {
V_6 -> V_71 = V_111 -> V_102 ;
V_9 = - V_105 ;
if ( V_6 -> V_71 & 0x80 ) {
F_3 ( L_31 ,
V_10 ) ;
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
F_51 ( V_6 -> V_117 , L_20 ,
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
F_3 ( L_32 , V_10 ) ;
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
F_3 ( L_2 , V_10 , V_6 ) ;
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
F_3 ( L_33 , V_10 ) ;
goto V_107;
}
} else {
V_6 -> V_54 = V_111 -> V_103 ;
F_3 ( L_34 , V_10 , V_6 -> V_54 ) ;
if( ( V_111 -> V_118 [ 0 ] != '\0' ) ||
( V_111 -> V_102 >= 0x70 ) ) {
V_9 = F_34 ( V_6 , V_111 -> V_118 ) ;
if ( V_9 ) {
F_3 ( L_35 , V_10 ) ;
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
F_3 ( L_35 , V_10 ) ;
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
V_9 = F_64 ( V_8 ) ;
if ( ! V_9 )
V_9 = - V_138 ;
goto V_107;
}
V_7 -> V_115 = V_116 ;
V_6 -> V_77 = F_59 ( V_6 -> V_20 ) ;
V_9 = 0 ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_54 ( struct V_139 * V_139 , struct V_93 * V_7 , int V_140 ,
int V_141 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
if ( V_139 != & V_142 )
return - V_143 ;
switch ( V_7 -> type ) {
case V_27 :
case V_29 :
case V_106 :
break;
default:
return - V_131 ;
}
V_8 = F_65 ( V_139 , V_144 , V_35 , & V_145 ) ;
if ( V_8 == NULL )
return - V_69 ;
V_6 = F_43 ( V_8 ) ;
F_3 ( L_36 , V_10 , V_6 ) ;
F_66 ( & V_6 -> V_49 ) ;
switch ( V_7 -> type ) {
case V_27 :
V_7 -> V_146 = & V_147 ;
V_6 -> V_37 = V_148 ;
break;
case V_29 :
V_7 -> V_146 = & V_149 ;
V_6 -> V_37 = V_150 ;
break;
case V_106 :
switch ( V_140 ) {
#ifdef F_48
case V_114 :
V_7 -> V_146 = & V_151 ;
V_6 -> V_28 = V_152 - V_153 ;
V_6 -> V_24 = V_36 + V_153 ;
break;
#endif
case V_154 :
V_7 -> V_146 = & V_155 ;
V_6 -> V_37 = V_150 ;
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
V_8 -> V_156 = V_144 ;
V_8 -> V_113 = V_140 ;
V_6 -> V_157 = F_69 ( 0 , NULL , NULL , NULL ) ;
V_6 -> V_89 . V_90 = 0xffff ;
V_6 -> V_11 = V_6 -> V_39 = V_40 ;
V_6 -> V_91 = V_158 ;
V_6 -> V_54 = V_88 ;
V_6 -> V_77 = 0x0 ;
return 0 ;
}
static void F_70 ( struct V_5 * V_6 )
{
F_3 ( L_2 , V_10 , V_6 ) ;
F_71 ( V_6 -> V_157 ) ;
F_72 ( V_6 -> V_159 ) ;
if ( V_6 -> V_117 ) {
F_50 ( V_6 -> V_117 ) ;
V_6 -> V_117 = NULL ;
}
if ( V_6 -> V_46 ) {
F_26 ( V_6 -> V_46 ) ;
V_6 -> V_46 = NULL ;
}
if ( V_6 -> V_20 ) {
F_73 ( V_6 -> V_20 , NULL , V_160 ) ;
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
static int F_79 ( struct V_161 * V_162 , struct V_93 * V_7 ,
struct V_163 * V_164 , T_10 V_165 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_9 = - V_166 ;
F_3 ( L_37 , V_10 , V_165 ) ;
if ( V_164 -> V_167 & ~ ( V_168 | V_169 | V_170 |
V_171 ) ) {
return - V_112 ;
}
F_45 ( V_8 ) ;
if ( V_8 -> V_17 & V_18 )
goto V_172;
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
if ( V_165 > V_6 -> V_28 ) {
F_3 ( L_38 ,
V_10 , V_165 , V_6 -> V_28 ) ;
V_165 = V_6 -> V_28 ;
}
V_4 = F_80 ( V_8 , V_165 + V_6 -> V_24 + 16 ,
V_164 -> V_167 & V_168 , & V_9 ) ;
if ( ! V_4 )
goto V_172;
F_18 ( V_4 , V_6 -> V_24 + 16 ) ;
F_81 ( V_4 ) ;
F_82 ( V_4 , V_165 ) ;
V_9 = F_83 ( F_84 ( V_4 ) , V_164 , V_165 ) ;
if ( V_9 ) {
F_14 ( V_4 ) ;
goto V_172;
}
V_9 = F_85 ( V_6 -> V_20 , V_4 ) ;
if ( V_9 ) {
F_3 ( L_39 , V_10 , V_9 ) ;
goto V_172;
}
F_46 ( V_8 ) ;
return V_165 ;
V_172:
V_9 = F_86 ( V_8 , V_164 -> V_167 , V_9 ) ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_87 ( struct V_161 * V_162 , struct V_93 * V_7 ,
struct V_163 * V_164 , T_10 V_173 , int V_122 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
struct V_3 * V_4 ;
T_10 V_174 ;
int V_9 ;
V_4 = F_88 ( V_8 , V_122 & ~ V_168 ,
V_122 & V_168 , & V_9 ) ;
if ( ! V_4 )
return V_9 ;
F_81 ( V_4 ) ;
V_174 = V_4 -> V_165 ;
if ( V_174 > V_173 ) {
F_3 ( L_40 ,
V_10 , V_174 , V_173 ) ;
V_174 = V_173 ;
V_164 -> V_167 |= V_175 ;
}
F_89 ( V_4 , 0 , V_164 , V_174 ) ;
F_90 ( V_8 , V_4 ) ;
if ( V_6 -> V_11 == V_12 ) {
if ( ( F_91 ( & V_8 -> V_176 ) << 2 ) <= V_8 -> V_177 ) {
F_3 ( L_41 , V_10 ) ;
V_6 -> V_11 = V_40 ;
F_92 ( V_6 -> V_20 , V_40 ) ;
}
}
return V_174 ;
}
static int F_93 ( struct V_161 * V_162 , struct V_93 * V_7 ,
struct V_163 * V_164 , T_10 V_173 , int V_122 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
int V_178 = V_122 & V_168 ;
T_10 V_174 = 0 ;
int V_179 , V_9 ;
long V_180 ;
if ( ( V_9 = F_64 ( V_8 ) ) < 0 )
return V_9 ;
if ( V_7 -> V_122 & V_181 )
return - V_112 ;
V_9 = - V_105 ;
if ( V_122 & V_182 )
return - V_105 ;
V_9 = 0 ;
V_179 = F_94 ( V_8 , V_122 & V_183 , V_173 ) ;
V_180 = F_95 ( V_8 , V_178 ) ;
do {
int V_184 ;
struct V_3 * V_4 = F_56 ( & V_8 -> V_32 ) ;
if ( V_4 == NULL ) {
F_96 ( V_185 ) ;
V_9 = 0 ;
if ( V_174 >= V_179 )
break;
F_97 ( F_23 ( V_8 ) , & V_185 , V_186 ) ;
V_9 = F_64 ( V_8 ) ;
if ( V_9 )
;
else if ( V_8 -> V_17 & V_187 )
;
else if ( V_178 )
V_9 = - V_188 ;
else if ( F_98 ( V_189 ) )
V_9 = F_99 ( V_180 ) ;
else if ( V_8 -> V_15 != V_31 )
V_9 = - V_99 ;
else if ( F_57 ( & V_8 -> V_32 ) == NULL )
F_100 () ;
F_101 ( F_23 ( V_8 ) , & V_185 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 -> V_17 & V_187 )
break;
continue;
}
V_184 = F_102 (unsigned int, skb->len, size) ;
if ( F_103 ( V_164 , V_4 -> V_190 , V_184 ) ) {
F_104 ( & V_8 -> V_32 , V_4 ) ;
if ( V_174 == 0 )
V_174 = - V_191 ;
break;
}
V_174 += V_184 ;
V_173 -= V_184 ;
if ( ! ( V_122 & V_192 ) ) {
F_105 ( V_4 , V_184 ) ;
if ( V_4 -> V_165 ) {
F_3 ( L_42 ,
V_10 ) ;
F_104 ( & V_8 -> V_32 , V_4 ) ;
break;
}
F_14 ( V_4 ) ;
} else {
F_3 ( L_43 , V_10 ) ;
F_104 ( & V_8 -> V_32 , V_4 ) ;
break;
}
} while ( V_173 );
if ( V_6 -> V_11 == V_12 ) {
if ( ( F_91 ( & V_8 -> V_176 ) << 2 ) <= V_8 -> V_177 ) {
F_3 ( L_41 , V_10 ) ;
V_6 -> V_11 = V_40 ;
F_92 ( V_6 -> V_20 , V_40 ) ;
}
}
return V_174 ;
}
static int F_106 ( struct V_161 * V_162 , struct V_93 * V_7 ,
struct V_163 * V_164 , T_10 V_165 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_9 ;
F_3 ( L_37 , V_10 , V_165 ) ;
if ( V_164 -> V_167 & ~ ( V_168 | V_170 ) )
return - V_112 ;
F_45 ( V_8 ) ;
if ( V_8 -> V_17 & V_18 ) {
F_107 ( V_193 , V_189 , 0 ) ;
V_9 = - V_166 ;
goto V_107;
}
V_9 = - V_99 ;
if ( V_8 -> V_15 != V_31 )
goto V_107;
V_6 = F_43 ( V_8 ) ;
if ( V_165 > V_6 -> V_28 ) {
F_3 ( L_44 ,
V_10 , V_165 , V_6 -> V_28 ) ;
V_165 = V_6 -> V_28 ;
}
V_4 = F_80 ( V_8 , V_165 + V_6 -> V_24 ,
V_164 -> V_167 & V_168 , & V_9 ) ;
V_9 = - V_194 ;
if ( ! V_4 )
goto V_107;
F_18 ( V_4 , V_6 -> V_24 ) ;
F_81 ( V_4 ) ;
F_3 ( L_45 , V_10 ) ;
F_82 ( V_4 , V_165 ) ;
V_9 = F_83 ( F_84 ( V_4 ) , V_164 , V_165 ) ;
if ( V_9 ) {
F_14 ( V_4 ) ;
goto V_107;
}
V_9 = F_108 ( V_6 -> V_20 , V_4 ) ;
if ( V_9 ) {
F_3 ( L_39 , V_10 , V_9 ) ;
goto V_107;
}
F_46 ( V_8 ) ;
return V_165 ;
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_109 ( struct V_161 * V_162 , struct V_93 * V_7 ,
struct V_163 * V_164 , T_10 V_165 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 ;
T_3 V_71 = 0 ;
int V_195 = 0 ;
struct V_3 * V_4 ;
int V_9 ;
F_3 ( L_37 , V_10 , V_165 ) ;
V_9 = - V_112 ;
if ( V_164 -> V_167 & ~ ( V_168 | V_170 ) )
return - V_112 ;
F_45 ( V_8 ) ;
V_9 = - V_166 ;
if ( V_8 -> V_17 & V_18 ) {
F_107 ( V_193 , V_189 , 0 ) ;
goto V_107;
}
V_6 = F_43 ( V_8 ) ;
if ( V_164 -> V_196 ) {
F_110 ( struct V_98 * , V_111 , V_164 -> V_196 ) ;
V_9 = - V_112 ;
if ( V_164 -> V_197 < sizeof( * V_111 ) )
goto V_107;
if ( V_111 -> V_100 != V_101 )
goto V_107;
V_71 = V_111 -> V_102 ;
if ( V_71 & 0x80 ) {
F_3 ( L_31 ,
V_10 ) ;
V_9 = - V_105 ;
goto V_107;
}
} else {
if ( ( V_6 -> V_72 == NULL ) ||
( V_8 -> V_15 != V_31 ) ) {
F_3 ( L_46 ,
V_10 ) ;
V_9 = - V_99 ;
goto V_107;
}
V_195 = 1 ;
}
if ( V_165 > V_6 -> V_28 ) {
F_3 ( L_44 ,
V_10 , V_165 , V_6 -> V_28 ) ;
V_165 = V_6 -> V_28 ;
}
V_4 = F_80 ( V_8 , V_165 + V_6 -> V_24 ,
V_164 -> V_167 & V_168 , & V_9 ) ;
V_9 = - V_194 ;
if ( ! V_4 )
goto V_107;
F_18 ( V_4 , V_6 -> V_24 ) ;
F_81 ( V_4 ) ;
F_3 ( L_45 , V_10 ) ;
F_82 ( V_4 , V_165 ) ;
V_9 = F_83 ( F_84 ( V_4 ) , V_164 , V_165 ) ;
if ( V_9 ) {
F_14 ( V_4 ) ;
goto V_107;
}
V_9 = F_111 ( ( V_195 ? V_6 -> V_72 : NULL ) ,
V_4 , V_71 ) ;
if ( V_9 )
F_3 ( L_39 , V_10 , V_9 ) ;
V_107:
F_46 ( V_8 ) ;
return V_9 ? : V_165 ;
}
static int F_112 ( struct V_93 * V_7 , int V_198 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
F_3 ( L_2 , V_10 , V_6 ) ;
F_45 ( V_8 ) ;
V_8 -> V_15 = V_16 ;
V_8 -> V_17 |= V_18 ;
V_8 -> V_19 ( V_8 ) ;
if ( V_6 -> V_46 ) {
F_26 ( V_6 -> V_46 ) ;
V_6 -> V_46 = NULL ;
}
if ( V_6 -> V_20 ) {
F_73 ( V_6 -> V_20 , NULL , V_160 ) ;
F_8 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
V_6 -> V_11 = V_6 -> V_39 = V_40 ;
V_6 -> V_54 = V_88 ;
V_6 -> V_77 = 0x0 ;
F_46 ( V_8 ) ;
return 0 ;
}
static unsigned int F_113 ( struct V_199 * V_199 , struct V_93 * V_7 ,
T_11 * V_185 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
unsigned int V_89 ;
F_114 ( V_199 , F_23 ( V_8 ) , V_185 ) ;
V_89 = 0 ;
if ( V_8 -> V_200 )
V_89 |= V_201 ;
if ( V_8 -> V_17 & V_187 ) {
F_3 ( L_47 , V_10 ) ;
V_89 |= V_202 ;
}
if ( ! F_115 ( & V_8 -> V_32 ) ) {
F_3 ( L_48 ) ;
V_89 |= V_203 | V_204 ;
}
switch ( V_8 -> V_26 ) {
case V_27 :
if ( V_8 -> V_15 == V_16 ) {
F_3 ( L_47 , V_10 ) ;
V_89 |= V_202 ;
}
if ( V_8 -> V_15 == V_31 ) {
if ( ( V_6 -> V_39 == V_40 ) &&
F_116 ( V_8 ) )
{
V_89 |= V_205 | V_206 | V_207 ;
}
}
break;
case V_29 :
if ( ( V_6 -> V_39 == V_40 ) &&
F_116 ( V_8 ) )
{
V_89 |= V_205 | V_206 | V_207 ;
}
break;
case V_106 :
if ( F_116 ( V_8 ) )
V_89 |= V_205 | V_206 | V_207 ;
break;
default:
break;
}
return V_89 ;
}
static int F_117 ( struct V_93 * V_7 , unsigned int V_208 , unsigned long V_209 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
int V_9 ;
F_3 ( L_49 , V_10 , V_208 ) ;
V_9 = - V_112 ;
switch ( V_208 ) {
case V_210 : {
long V_211 ;
V_211 = V_8 -> V_212 - F_118 ( V_8 ) ;
if ( V_211 < 0 )
V_211 = 0 ;
V_9 = F_119 ( V_211 , ( unsigned int V_213 * ) V_209 ) ;
break;
}
case V_214 : {
struct V_3 * V_4 ;
long V_211 = 0L ;
if ( ( V_4 = F_57 ( & V_8 -> V_32 ) ) != NULL )
V_211 = V_4 -> V_165 ;
V_9 = F_119 ( V_211 , ( unsigned int V_213 * ) V_209 ) ;
break;
}
case V_215 :
if ( V_8 != NULL )
V_9 = F_120 ( V_8 , (struct V_216 V_213 * ) V_209 ) ;
break;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
break;
default:
F_3 ( L_50 , V_10 ) ;
V_9 = - V_227 ;
}
return V_9 ;
}
static int F_121 ( struct V_93 * V_7 , unsigned int V_208 , unsigned long V_209 )
{
return - V_227 ;
}
static int F_122 ( struct V_93 * V_7 , int V_228 , int V_229 ,
char V_213 * V_230 , unsigned int V_231 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
struct V_232 * V_233 ;
struct V_234 * V_117 ;
struct V_235 * V_236 ;
int V_237 , V_238 = 0 , V_9 = 0 ;
F_3 ( L_2 , V_10 , V_6 ) ;
if ( V_228 != V_239 )
return - V_240 ;
F_45 ( V_8 ) ;
switch ( V_229 ) {
case V_241 :
if ( V_231 != sizeof( struct V_232 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_233 = F_123 ( sizeof( struct V_232 ) , V_242 ) ;
if ( V_233 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_233 , V_230 , V_231 ) ) {
F_41 ( V_233 ) ;
V_9 = - V_191 ;
goto V_107;
}
if( V_233 -> V_243 [ 0 ] == '\0' ) {
if( V_6 -> V_117 == NULL ) {
F_41 ( V_233 ) ;
V_9 = - V_112 ;
goto V_107;
}
V_117 = V_6 -> V_117 ;
} else
V_117 = F_125 ( V_233 -> V_243 ) ;
if( ( ! F_126 ( V_244 ) ) &&
( ( V_117 == NULL ) || ( V_117 != V_6 -> V_117 ) ) ) {
F_41 ( V_233 ) ;
V_9 = - V_129 ;
goto V_107;
}
if( V_117 == (struct V_234 * ) NULL ) {
V_117 = F_49 ( V_233 -> V_243 ,
V_119 ) ;
if ( V_117 == NULL ) {
F_41 ( V_233 ) ;
V_9 = - V_69 ;
goto V_107;
}
V_238 = 1 ;
}
if( F_127 ( V_117 , V_233 -> V_245 ) ) {
F_41 ( V_233 ) ;
if ( V_238 ) {
F_41 ( V_117 -> V_58 ) ;
F_41 ( V_117 ) ;
}
V_9 = - V_112 ;
goto V_107;
}
switch( V_233 -> V_246 ) {
case V_81 :
F_51 (
V_117 ,
V_233 -> V_245 ,
V_233 -> V_247 . V_248 ,
V_249 ) ;
break;
case V_250 :
if( V_233 -> V_247 . V_251 . V_165 >
V_252 ) {
F_41 ( V_233 ) ;
if ( V_238 ) {
F_41 ( V_117 -> V_58 ) ;
F_41 ( V_117 ) ;
}
V_9 = - V_112 ;
goto V_107;
}
F_128 (
V_117 ,
V_233 -> V_245 ,
V_233 -> V_247 . V_251 . V_253 ,
V_233 -> V_247 . V_251 . V_165 ,
V_249 ) ;
break;
case V_254 :
V_233 -> V_247 . V_255 . string [ V_233 -> V_247 . V_255 . V_165 ] = '\0' ;
F_129 (
V_117 ,
V_233 -> V_245 ,
V_233 -> V_247 . V_255 . string ,
V_249 ) ;
break;
default :
F_41 ( V_233 ) ;
if ( V_238 ) {
F_41 ( V_117 -> V_58 ) ;
F_41 ( V_117 ) ;
}
V_9 = - V_112 ;
goto V_107;
}
F_52 ( V_117 ) ;
F_41 ( V_233 ) ;
break;
case V_256 :
if ( V_231 != sizeof( struct V_232 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_233 = F_123 ( sizeof( struct V_232 ) , V_242 ) ;
if ( V_233 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_233 , V_230 , V_231 ) ) {
F_41 ( V_233 ) ;
V_9 = - V_191 ;
goto V_107;
}
if( V_233 -> V_243 [ 0 ] == '\0' )
V_117 = V_6 -> V_117 ;
else
V_117 = F_125 ( V_233 -> V_243 ) ;
if( V_117 == (struct V_234 * ) NULL ) {
F_41 ( V_233 ) ;
V_9 = - V_112 ;
goto V_107;
}
if( ( ! F_126 ( V_244 ) ) &&
( ( V_117 == NULL ) || ( V_117 != V_6 -> V_117 ) ) ) {
F_41 ( V_233 ) ;
V_9 = - V_129 ;
goto V_107;
}
V_236 = F_127 ( V_117 ,
V_233 -> V_245 ) ;
if( V_236 == (struct V_235 * ) NULL ) {
F_41 ( V_233 ) ;
V_9 = - V_112 ;
goto V_107;
}
if( V_236 -> V_44 -> V_257 != V_249 ) {
F_3 ( L_51 ,
V_10 ) ;
F_41 ( V_233 ) ;
V_9 = - V_129 ;
goto V_107;
}
F_130 ( V_117 , V_236 , 1 ) ;
F_41 ( V_233 ) ;
break;
case V_258 :
if ( V_231 < sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_237 , ( int V_213 * ) V_230 ) ) {
V_9 = - V_191 ;
goto V_107;
}
if ( V_8 -> V_26 != V_29 ) {
F_3 ( L_52 ,
V_10 , V_237 ) ;
V_6 -> V_37 = V_237 ;
} else {
F_25 ( L_53 ,
V_10 ) ;
V_9 = - V_240 ;
goto V_107;
}
break;
case V_259 :
if ( V_231 < sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_237 , ( int V_213 * ) V_230 ) ) {
V_9 = - V_191 ;
goto V_107;
}
if ( V_6 -> V_159 )
F_72 ( V_6 -> V_159 ) ;
V_6 -> V_159 = F_132 ( ( T_5 ) V_237 ) ;
break;
case V_260 :
if ( V_231 < sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_237 , ( int V_213 * ) V_230 ) ) {
V_9 = - V_191 ;
goto V_107;
}
V_6 -> V_89 . V_90 = ( T_5 ) V_237 ;
V_6 -> V_89 . V_90 &= 0x7f7f ;
if( ! V_6 -> V_89 . V_90 )
V_6 -> V_89 . V_90 = 0xFFFF ;
break;
default:
V_9 = - V_240 ;
break;
}
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
static int F_133 ( struct V_232 * V_233 ,
struct V_43 * V_43 )
{
switch ( V_43 -> type ) {
case V_81 :
V_233 -> V_247 . V_248 = V_43 -> V_82 . integer ;
break;
case V_250 :
V_233 -> V_247 . V_251 . V_165 = V_43 -> V_165 ;
memcpy ( V_233 -> V_247 . V_251 . V_253 ,
V_43 -> V_82 . V_261 , V_43 -> V_165 ) ;
break;
case V_254 :
V_233 -> V_247 . V_255 . V_165 = V_43 -> V_165 ;
V_233 -> V_247 . V_255 . V_262 = V_43 -> V_262 ;
memcpy ( V_233 -> V_247 . V_255 . string ,
V_43 -> V_82 . string , V_43 -> V_165 ) ;
V_233 -> V_247 . V_255 . string [ V_43 -> V_165 ] = '\0' ;
break;
case V_263 :
default :
return - V_112 ;
}
V_233 -> V_246 = V_43 -> type ;
return 0 ;
}
static int F_134 ( struct V_93 * V_7 , int V_228 , int V_229 ,
char V_213 * V_230 , int V_213 * V_231 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
struct V_5 * V_6 = F_43 ( V_8 ) ;
struct V_264 V_265 ;
struct V_266 * V_84 ;
struct V_232 * V_233 ;
struct V_234 * V_117 ;
struct V_235 * V_236 ;
int V_54 = V_88 ;
int V_267 = 0 ;
int V_165 = 0 ;
int V_9 = 0 ;
int V_268 , V_269 ;
F_3 ( L_2 , V_10 , V_6 ) ;
if ( V_228 != V_239 )
return - V_240 ;
if ( F_131 ( V_165 , V_231 ) )
return - V_191 ;
if( V_165 < 0 )
return - V_112 ;
F_45 ( V_8 ) ;
switch ( V_229 ) {
case V_270 :
V_268 = sizeof( struct V_264 ) -
sizeof( struct V_266 ) ;
if ( V_165 < V_268 ) {
V_9 = - V_112 ;
goto V_107;
}
V_84 = F_40 ( & V_265 . V_165 , V_6 -> V_89 . V_90 ,
V_6 -> V_91 ) ;
if ( V_84 == NULL ) {
V_9 = - V_188 ;
goto V_107;
}
if ( F_135 ( V_230 , & V_265 , V_268 ) )
V_9 = - V_191 ;
if ( V_265 . V_165 > 2048 ) {
V_9 = - V_112 ;
goto V_271;
}
V_269 = V_268 + ( V_265 . V_165 * sizeof( struct V_266 ) ) ;
if ( V_269 > V_165 )
V_269 = V_165 ;
if ( F_135 ( V_230 + V_268 , V_84 , V_269 - V_268 ) )
V_9 = - V_191 ;
if ( F_119 ( V_269 , V_231 ) )
V_9 = - V_191 ;
V_271:
F_41 ( V_84 ) ;
break;
case V_258 :
V_267 = V_6 -> V_28 ;
V_165 = sizeof( int ) ;
if ( F_119 ( V_165 , V_231 ) ) {
V_9 = - V_191 ;
goto V_107;
}
if ( F_135 ( V_230 , & V_267 , V_165 ) ) {
V_9 = - V_191 ;
goto V_107;
}
break;
case V_272 :
if ( V_165 != sizeof( struct V_232 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_233 = F_123 ( sizeof( struct V_232 ) , V_242 ) ;
if ( V_233 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_233 , V_230 , V_165 ) ) {
F_41 ( V_233 ) ;
V_9 = - V_191 ;
goto V_107;
}
if( V_233 -> V_243 [ 0 ] == '\0' )
V_117 = V_6 -> V_117 ;
else
V_117 = F_125 ( V_233 -> V_243 ) ;
if( V_117 == (struct V_234 * ) NULL ) {
F_41 ( V_233 ) ;
V_9 = - V_112 ;
goto V_107;
}
V_236 = F_127 ( V_117 ,
V_233 -> V_245 ) ;
if( V_236 == (struct V_235 * ) NULL ) {
F_41 ( V_233 ) ;
V_9 = - V_112 ;
goto V_107;
}
V_9 = F_133 ( V_233 , V_236 -> V_44 ) ;
if( V_9 ) {
F_41 ( V_233 ) ;
goto V_107;
}
if ( F_135 ( V_230 , V_233 ,
sizeof( struct V_232 ) ) ) {
F_41 ( V_233 ) ;
V_9 = - V_191 ;
goto V_107;
}
F_41 ( V_233 ) ;
break;
case V_273 :
if ( V_165 != sizeof( struct V_232 ) ) {
V_9 = - V_112 ;
goto V_107;
}
V_233 = F_123 ( sizeof( struct V_232 ) , V_242 ) ;
if ( V_233 == NULL ) {
V_9 = - V_69 ;
goto V_107;
}
if ( F_124 ( V_233 , V_230 , V_165 ) ) {
F_41 ( V_233 ) ;
V_9 = - V_191 ;
goto V_107;
}
if( V_6 -> V_54 != V_88 ) {
V_54 = V_6 -> V_54 ;
} else {
V_54 = V_233 -> V_54 ;
if( ( ! V_54 ) || ( V_54 == V_88 ) ) {
F_41 ( V_233 ) ;
V_9 = - V_112 ;
goto V_107;
}
}
if ( V_6 -> V_46 ) {
F_25 ( L_54 ,
V_10 ) ;
F_41 ( V_233 ) ;
V_9 = - V_60 ;
goto V_107;
}
V_6 -> V_46 = F_35 ( V_74 , V_75 , V_6 ,
F_24 ) ;
if ( V_6 -> V_46 == NULL ) {
F_41 ( V_233 ) ;
V_9 = - V_69 ;
goto V_107;
}
V_6 -> V_48 = - V_76 ;
F_36 ( V_6 -> V_46 ,
V_6 -> V_77 , V_54 ,
V_233 -> V_243 ,
V_233 -> V_245 ) ;
if ( F_37 ( V_6 -> V_49 ,
( V_6 -> V_46 == NULL ) ) ) {
F_41 ( V_233 ) ;
V_9 = - V_76 ;
goto V_107;
}
if ( V_6 -> V_48 )
{
F_41 ( V_233 ) ;
if( ( V_6 -> V_48 == V_78 ) ||
( V_6 -> V_48 == V_79 ) )
V_9 = - V_80 ;
else
V_9 = - V_76 ;
goto V_107;
}
V_9 = F_133 ( V_233 , V_6 -> V_50 ) ;
if ( V_6 -> V_50 )
F_38 ( V_6 -> V_50 ) ;
if ( V_9 ) {
F_41 ( V_233 ) ;
goto V_107;
}
if ( F_135 ( V_230 , V_233 ,
sizeof( struct V_232 ) ) ) {
F_41 ( V_233 ) ;
V_9 = - V_191 ;
goto V_107;
}
F_41 ( V_233 ) ;
break;
case V_274 :
if ( V_165 != sizeof( int ) ) {
V_9 = - V_112 ;
goto V_107;
}
if ( F_131 ( V_267 , ( int V_213 * ) V_230 ) ) {
V_9 = - V_191 ;
goto V_107;
}
F_136 ( V_6 -> V_157 , V_6 -> V_89 . V_90 ,
F_27 ,
NULL , ( void * ) V_6 ) ;
F_137 ( V_6 -> V_91 ) ;
if ( ! V_6 -> V_53 ) {
F_3 ( L_55 ,
V_10 ) ;
V_6 -> V_48 = 0 ;
F_138 ( & V_6 -> V_275 , F_28 ,
( unsigned long ) V_6 ) ;
F_139 ( & V_6 -> V_275 ,
V_119 + F_140 ( V_267 ) ) ;
V_9 = F_141 ( V_6 -> V_49 ,
( V_6 -> V_53 != 0 || V_6 -> V_48 == - V_56 ) ) ;
F_142 ( & ( V_6 -> V_275 ) ) ;
F_3 ( L_56 , V_10 ) ;
if ( V_9 != 0 )
goto V_107;
}
else
F_3 ( L_57 ,
V_10 ) ;
F_136 ( V_6 -> V_157 , V_6 -> V_89 . V_90 ,
NULL , NULL , NULL ) ;
if ( ! V_6 -> V_53 ) {
V_9 = - V_188 ;
goto V_107;
}
V_54 = V_6 -> V_53 ;
V_6 -> V_53 = 0 ;
if ( F_119 ( V_54 , ( int V_213 * ) V_230 ) ) {
V_9 = - V_191 ;
goto V_107;
}
break;
default:
V_9 = - V_240 ;
}
V_107:
F_46 ( V_8 ) ;
return V_9 ;
}
int T_12 F_143 ( void )
{
int V_276 = F_144 ( & V_145 , 0 ) ;
if ( V_276 == 0 )
V_276 = F_145 ( & V_277 ) ;
return V_276 ;
}
void F_146 ( void )
{
F_147 ( V_144 ) ;
F_148 ( & V_145 ) ;
}
