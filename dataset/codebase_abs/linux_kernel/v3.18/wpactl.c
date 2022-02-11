static void F_1 ( struct V_1 * V_2 )
{
V_2 -> type = V_3 ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = 2048 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1000 ;
memset ( V_2 -> V_10 , 0xFF , V_8 ) ;
V_2 -> V_11 = V_12 | V_13 ;
}
static int F_2 ( struct V_14 * V_15 )
{
struct V_14 * V_16 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_17 = 0 ;
V_15 -> V_18 = F_3 ( sizeof( * V_16 ) , L_1 ,
V_19 , F_1 ) ;
if ( V_15 -> V_18 == NULL )
return - V_20 ;
V_16 = F_4 ( V_15 -> V_18 ) ;
* V_16 = * V_15 ;
F_5 ( V_15 -> V_18 , V_2 ) ;
V_15 -> V_18 -> V_21 = V_2 -> V_21 ;
V_15 -> V_18 -> V_22 = V_2 -> V_22 ;
V_15 -> V_18 -> V_23 = V_2 -> V_23 ;
V_15 -> V_18 -> V_24 = V_2 -> V_24 ;
V_17 = F_6 ( V_15 -> V_18 ) ;
if ( V_17 ) {
F_7 ( L_2 , V_2 -> V_25 ) ;
F_8 ( V_15 -> V_18 ) ;
return - 1 ;
}
if ( V_15 -> V_26 == NULL ) {
V_15 -> V_26 = F_9 ( ( int ) V_15 -> V_27 ) ;
if ( V_15 -> V_26 == NULL )
return - V_20 ;
}
F_7 ( L_3 ,
V_2 -> V_25 , V_15 -> V_18 -> V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
if ( V_15 -> V_26 ) {
F_11 ( V_15 -> V_26 ) ;
V_15 -> V_26 = NULL ;
}
if ( V_15 -> V_18 ) {
F_7 ( L_4 ,
V_15 -> V_2 -> V_25 , V_15 -> V_18 -> V_25 ) ;
F_12 ( V_15 -> V_18 ) ;
F_8 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
}
return 0 ;
}
int F_13 ( struct V_14 * V_15 , int V_28 )
{
if ( V_28 )
return F_2 ( V_15 ) ;
else
return F_10 ( V_15 ) ;
}
int F_14 ( struct V_14 * V_15 , void * V_29 ,
bool V_30 ) __must_hold( &pDevice->lock
static int F_15 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
T_1 V_33 = V_15 -> V_33 ;
V_33 -> V_34 = V_35 ;
V_33 -> V_36 = false ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
T_1 V_33 = V_15 -> V_33 ;
F_17 ( & V_15 -> V_37 ) ;
if ( V_15 -> V_38 ) {
if ( ! memcmp ( V_32 -> V_39 , V_33 -> V_40 , 6 ) )
F_18 ( ( void * ) V_15 , V_41 , NULL ) ;
}
F_19 ( & V_15 -> V_37 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
F_17 ( & V_15 -> V_37 ) ;
F_21 ( ( void * ) V_15 , V_15 -> V_38 ) ;
F_18 ( ( void * ) V_15 , V_42 , NULL ) ;
F_19 ( & V_15 -> V_37 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
T_1 V_33 = V_15 -> V_33 ;
memcpy ( V_32 -> V_43 . V_44 . V_45 , V_33 -> V_40 , 6 ) ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
T_1 V_33 = V_15 -> V_33 ;
T_2 V_46 ;
V_46 = ( T_2 ) V_33 -> V_47 ;
memcpy ( V_32 -> V_43 . V_44 . V_48 , V_46 -> V_49 , V_46 -> V_50 ) ;
V_32 -> V_43 . V_44 . V_51 = V_46 -> V_50 ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_52 * V_53 ;
T_1 V_33 = V_15 -> V_33 ;
T_2 V_46 ;
T_3 V_54 ;
unsigned char * V_55 ;
int V_17 = 0 ;
T_4 V_56 = 0 ;
T_4 V_57 , V_58 ;
#if 1
unsigned char * V_59 ;
V_59 = F_25 ( sizeof( V_60 ) , V_61 ) ;
if ( V_59 == NULL ) {
F_26 ( L_5 ) ;
V_17 = - V_20 ;
return V_17 ;
}
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ ) {
for ( V_58 = 0 ; V_58 < V_62 - V_57 - 1 ; V_58 ++ ) {
if ( ( V_33 -> V_63 [ V_58 ] . V_64 != true ) ||
( ( V_33 -> V_63 [ V_58 ] . V_65 > V_33 -> V_63 [ V_58 + 1 ] . V_65 ) && ( V_33 -> V_63 [ V_58 + 1 ] . V_64 != false ) ) ) {
memcpy ( V_59 , & V_33 -> V_63 [ V_58 ] , sizeof( V_60 ) ) ;
memcpy ( & V_33 -> V_63 [ V_58 ] , & V_33 -> V_63 [ V_58 + 1 ] , sizeof( V_60 ) ) ;
memcpy ( & V_33 -> V_63 [ V_58 + 1 ] , V_59 , sizeof( V_60 ) ) ;
}
}
}
F_27 ( V_59 ) ;
#endif
V_56 = 0 ;
V_54 = & ( V_33 -> V_63 [ 0 ] ) ;
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ ) {
V_54 = & ( V_33 -> V_63 [ V_57 ] ) ;
if ( ! V_54 -> V_64 )
continue;
V_56 ++ ;
}
V_55 = F_28 ( V_56 , sizeof( struct V_52 ) , V_61 ) ;
if ( V_55 == NULL ) {
V_17 = - V_20 ;
return V_17 ;
}
V_53 = (struct V_52 * ) V_55 ;
V_54 = & ( V_33 -> V_63 [ 0 ] ) ;
for ( V_57 = 0 , V_58 = 0 ; V_57 < V_62 ; V_57 ++ ) {
V_54 = & ( V_33 -> V_63 [ V_57 ] ) ;
if ( V_54 -> V_64 ) {
if ( V_58 >= V_56 )
break;
memcpy ( V_53 -> V_45 , V_54 -> V_66 , V_67 ) ;
V_46 = ( T_2 ) V_54 -> V_49 ;
memcpy ( V_53 -> V_48 , V_46 -> V_49 , V_46 -> V_50 ) ;
V_53 -> V_51 = V_46 -> V_50 ;
V_53 -> V_68 = V_69 [ V_54 -> V_70 - 1 ] ;
V_53 -> V_71 = V_54 -> V_72 ;
if ( V_54 -> V_73 != 0 ) {
V_53 -> V_74 = V_54 -> V_73 ;
memcpy ( V_53 -> V_75 , V_54 -> V_76 , V_54 -> V_73 ) ;
}
if ( V_54 -> V_77 != 0 ) {
V_53 -> V_78 = V_54 -> V_77 ;
memcpy ( V_53 -> V_79 , V_54 -> V_80 , V_54 -> V_77 ) ;
}
V_53 = (struct V_52 * ) ( ( unsigned char * ) V_53 + sizeof( struct V_52 ) ) ;
V_58 ++ ;
}
}
if ( V_58 < V_56 )
V_56 = V_58 ;
if ( F_29 ( V_32 -> V_43 . V_81 . V_82 , V_55 , sizeof( struct V_52 ) * V_56 ) )
V_17 = - V_83 ;
V_32 -> V_43 . V_81 . V_84 = V_56 ;
F_7 ( L_6 , V_56 ) ;
F_27 ( V_55 ) ;
return V_17 ;
}
static int F_30 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
T_1 V_33 = V_15 -> V_33 ;
T_2 V_46 ;
unsigned char V_85 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_86 [ 64 ] ;
bool V_87 = false ;
F_7 ( L_7 ,
V_32 -> V_43 . V_44 . V_88 ) ;
F_7 ( L_8 , V_32 -> V_43 . V_44 . V_89 ) ;
F_7 ( L_9 ,
V_32 -> V_43 . V_44 . V_90 ) ;
F_7 ( L_10 , V_32 -> V_43 . V_44 . V_91 ) ;
F_7 ( L_11 , V_32 -> V_43 . V_44 . V_92 ) ;
F_7 ( L_12 , V_32 -> V_43 . V_44 . V_74 ) ;
if ( V_32 -> V_43 . V_44 . V_74 ) {
if ( ! V_32 -> V_43 . V_44 . V_75 )
return - V_93 ;
if ( V_32 -> V_43 . V_44 . V_74 > sizeof( V_86 ) )
return - V_93 ;
if ( F_31 ( & V_86 [ 0 ] , V_32 -> V_43 . V_44 . V_75 , V_32 -> V_43 . V_44 . V_74 ) )
return - V_83 ;
}
if ( V_32 -> V_43 . V_44 . V_92 == 1 )
V_33 -> V_94 = V_95 ;
else
V_33 -> V_94 = V_96 ;
memset ( V_33 -> V_97 , 0 , V_98 + V_99 + 1 ) ;
V_46 = ( T_2 ) V_33 -> V_97 ;
V_46 -> V_100 = V_101 ;
V_46 -> V_50 = V_32 -> V_43 . V_44 . V_51 ;
memcpy ( V_46 -> V_49 , V_32 -> V_43 . V_44 . V_48 , V_46 -> V_50 ) ;
if ( memcmp ( V_32 -> V_43 . V_44 . V_45 , & V_85 [ 0 ] , 6 ) != 0 )
memcpy ( V_33 -> V_102 , V_32 -> V_43 . V_44 . V_45 , 6 ) ;
else
F_18 ( ( void * ) V_15 , V_42 , V_46 -> V_49 ) ;
if ( V_32 -> V_43 . V_44 . V_74 == 0 ) {
if ( V_32 -> V_43 . V_44 . V_91 & V_103 )
V_33 -> V_34 = V_104 ;
else
V_33 -> V_34 = V_35 ;
} else if ( V_86 [ 0 ] == V_105 ) {
if ( V_32 -> V_43 . V_44 . V_90 == V_106 )
V_33 -> V_34 = V_107 ;
else
V_33 -> V_34 = V_108 ;
} else {
if ( V_32 -> V_43 . V_44 . V_90 == V_109 )
V_33 -> V_34 = V_110 ;
else if ( V_32 -> V_43 . V_44 . V_90 == V_106 )
V_33 -> V_34 = V_111 ;
else
V_33 -> V_34 = V_112 ;
}
switch ( V_32 -> V_43 . V_44 . V_88 ) {
case V_113 :
V_15 -> V_114 = V_115 ;
break;
case V_116 :
V_15 -> V_114 = V_117 ;
break;
case V_118 :
case V_119 :
V_15 -> V_114 = V_120 ;
V_87 = true ;
break;
case V_121 :
if ( V_32 -> V_43 . V_44 . V_89 == V_113 )
V_15 -> V_114 = V_115 ;
else
V_15 -> V_114 = V_117 ;
break;
default:
V_15 -> V_114 = V_122 ;
}
if ( V_33 -> V_34 == V_104 ) {
V_15 -> V_114 = V_120 ;
V_33 -> V_36 = true ;
} else if ( V_33 -> V_34 == V_35 ) {
if ( ! V_87 ) V_15 -> V_114 = V_122 ;
else V_15 -> V_114 = V_120 ;
}
V_15 -> V_123 = V_15 -> V_114 ;
if ( V_15 -> V_114 != V_122 )
V_15 -> V_124 = true ;
else
V_15 -> V_124 = false ;
if ( ! ( ( V_33 -> V_34 == V_104 ) ||
( ( V_33 -> V_34 == V_35 ) && V_87 ) ) )
F_32 ( & V_15 -> V_125 , V_15 -> V_126 ) ;
F_17 ( & V_15 -> V_37 ) ;
V_15 -> V_38 = false ;
memset ( V_33 -> V_40 , 0 , 6 ) ;
V_33 -> V_127 = V_128 ;
F_33 ( V_15 -> V_2 ) ;
{
T_3 V_129 = NULL ;
V_129 = F_34 ( V_15 ,
V_33 -> V_102 ,
V_33 -> V_97 ,
V_33 -> V_130
) ;
if ( V_129 == NULL ) {
F_7 ( L_13 ) ;
F_18 ( ( void * ) V_15 , V_42 , V_33 -> V_97 ) ;
}
}
F_18 ( ( void * ) V_15 , V_131 , NULL ) ;
F_19 ( & V_15 -> V_37 ) ;
return 0 ;
}
int F_35 ( struct V_14 * V_15 , struct V_132 * V_133 )
{
struct V_31 * V_32 ;
int V_17 = 0 ;
int F_35 = 0 ;
if ( V_133 -> V_134 < sizeof( struct V_31 ) ||
V_133 -> V_134 > V_135 || ! V_133 -> V_136 )
return - V_93 ;
V_32 = F_25 ( ( int ) V_133 -> V_134 , V_137 ) ;
if ( V_32 == NULL )
return - V_20 ;
if ( F_31 ( V_32 , V_133 -> V_136 , V_133 -> V_134 ) ) {
V_17 = - V_83 ;
goto V_138;
}
switch ( V_32 -> V_139 ) {
case V_140 :
V_17 = F_15 ( V_15 , V_32 ) ;
F_7 ( L_14 ) ;
break;
case V_141 :
F_7 ( L_15 ) ;
F_17 ( & V_15 -> V_37 ) ;
V_17 = F_14 ( V_15 , V_32 , false ) ;
F_19 ( & V_15 -> V_37 ) ;
break;
case V_142 :
F_7 ( L_16 ) ;
V_17 = F_20 ( V_15 , V_32 ) ;
break;
case V_143 :
F_7 ( L_17 ) ;
V_17 = F_24 ( V_15 , V_32 ) ;
F_35 = 1 ;
break;
case V_144 :
F_7 ( L_18 ) ;
V_17 = F_23 ( V_15 , V_32 ) ;
F_35 = 1 ;
break;
case V_145 :
F_7 ( L_19 ) ;
V_17 = F_22 ( V_15 , V_32 ) ;
F_35 = 1 ;
break;
case V_146 :
F_7 ( L_20 ) ;
V_17 = F_30 ( V_15 , V_32 ) ;
break;
case V_147 :
F_7 ( L_21 ) ;
V_17 = F_16 ( V_15 , V_32 ) ;
break;
case V_148 :
F_7 ( L_22 ) ;
break;
case V_149 :
F_7 ( L_23 ) ;
break;
default:
F_7 ( L_24 ,
V_32 -> V_139 ) ;
V_17 = - V_150 ;
goto V_138;
}
if ( ( V_17 == 0 ) && F_35 ) {
if ( F_29 ( V_133 -> V_136 , V_32 , V_133 -> V_134 ) ) {
V_17 = - V_83 ;
goto V_138;
}
}
V_138:
F_27 ( V_32 ) ;
return V_17 ;
}
