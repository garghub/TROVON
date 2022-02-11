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
static int F_2 ( T_1 V_14 )
{
T_1 V_15 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int V_16 = 0 ;
V_14 -> V_17 = F_3 ( sizeof( T_1 ) , L_1 ,
V_18 , F_1 ) ;
if ( V_14 -> V_17 == NULL )
return - V_19 ;
V_15 = F_4 ( V_14 -> V_17 ) ;
* V_15 = * V_14 ;
F_5 ( V_14 -> V_17 , V_2 ) ;
V_14 -> V_17 -> V_20 = V_2 -> V_20 ;
V_14 -> V_17 -> V_21 = V_2 -> V_21 ;
V_14 -> V_17 -> V_22 = V_2 -> V_22 ;
V_14 -> V_17 -> V_23 = V_2 -> V_23 ;
V_16 = F_6 ( V_14 -> V_17 ) ;
if ( V_16 ) {
F_7 ( V_24 , V_25 L_2 ,
V_2 -> V_26 ) ;
F_8 ( V_14 -> V_17 ) ;
return - 1 ;
}
if ( V_14 -> V_27 == NULL ) {
V_14 -> V_27 = F_9 ( ( int ) V_14 -> V_28 ) ;
if ( V_14 -> V_27 == NULL )
return - V_19 ;
}
F_7 ( V_24 , V_25 L_3 ,
V_2 -> V_26 , V_14 -> V_17 -> V_26 ) ;
return 0 ;
}
static int F_10 ( T_1 V_14 )
{
if ( V_14 -> V_27 ) {
F_11 ( V_14 -> V_27 ) ;
V_14 -> V_27 = NULL ;
}
if ( V_14 -> V_17 ) {
F_7 ( V_24 , V_25 L_4 ,
V_14 -> V_2 -> V_26 , V_14 -> V_17 -> V_26 ) ;
F_12 ( V_14 -> V_17 ) ;
F_8 ( V_14 -> V_17 ) ;
V_14 -> V_17 = NULL ;
}
return 0 ;
}
int F_13 ( T_1 V_14 , int V_29 )
{
if ( V_29 )
return F_2 ( V_14 ) ;
else
return F_10 ( V_14 ) ;
}
int F_14 ( T_1 V_14 , void * V_30 ,
bool V_31 ) __must_hold( &pDevice->lock
static int F_15 ( T_1 V_14 ,
struct V_32 * V_33 )
{
T_2 V_34 = V_14 -> V_34 ;
V_34 -> V_35 = V_36 ;
V_34 -> V_37 = false ;
return 0 ;
}
static int F_16 ( T_1 V_14 ,
struct V_32 * V_33 )
{
T_2 V_34 = V_14 -> V_34 ;
F_17 ( & V_14 -> V_38 ) ;
if ( V_14 -> V_39 ) {
if ( ! memcmp ( V_33 -> V_40 , V_34 -> V_41 , 6 ) )
F_18 ( ( void * ) V_14 , V_42 , NULL ) ;
}
F_19 ( & V_14 -> V_38 ) ;
return 0 ;
}
static int F_20 ( T_1 V_14 ,
struct V_32 * V_33 )
{
F_17 ( & V_14 -> V_38 ) ;
F_21 ( ( void * ) V_14 , V_14 -> V_39 ) ;
F_18 ( ( void * ) V_14 , V_43 , NULL ) ;
F_19 ( & V_14 -> V_38 ) ;
return 0 ;
}
static int F_22 ( T_1 V_14 ,
struct V_32 * V_33 )
{
T_2 V_34 = V_14 -> V_34 ;
memcpy ( V_33 -> V_44 . V_45 . V_46 , V_34 -> V_41 , 6 ) ;
return 0 ;
}
static int F_23 ( T_1 V_14 ,
struct V_32 * V_33 )
{
T_2 V_34 = V_14 -> V_34 ;
T_3 V_47 ;
V_47 = ( T_3 ) V_34 -> V_48 ;
memcpy ( V_33 -> V_44 . V_45 . V_49 , V_47 -> V_50 , V_47 -> V_51 ) ;
V_33 -> V_44 . V_45 . V_52 = V_47 -> V_51 ;
return 0 ;
}
static int F_24 ( T_1 V_14 ,
struct V_32 * V_33 )
{
struct V_53 * V_54 ;
T_2 V_34 = V_14 -> V_34 ;
T_3 V_47 ;
T_4 V_55 ;
unsigned char * V_56 ;
int V_16 = 0 ;
T_5 V_57 = 0 ;
T_5 V_58 , V_59 ;
#if 1
unsigned char * V_60 ;
V_60 = F_25 ( sizeof( V_61 ) , V_62 ) ;
if ( V_60 == NULL ) {
F_26 ( L_5 ) ;
V_16 = - V_19 ;
return V_16 ;
}
for ( V_58 = 0 ; V_58 < V_63 ; V_58 ++ ) {
for ( V_59 = 0 ; V_59 < V_63 - V_58 - 1 ; V_59 ++ ) {
if ( ( V_34 -> V_64 [ V_59 ] . V_65 != true ) ||
( ( V_34 -> V_64 [ V_59 ] . V_66 > V_34 -> V_64 [ V_59 + 1 ] . V_66 ) && ( V_34 -> V_64 [ V_59 + 1 ] . V_65 != false ) ) ) {
memcpy ( V_60 , & V_34 -> V_64 [ V_59 ] , sizeof( V_61 ) ) ;
memcpy ( & V_34 -> V_64 [ V_59 ] , & V_34 -> V_64 [ V_59 + 1 ] , sizeof( V_61 ) ) ;
memcpy ( & V_34 -> V_64 [ V_59 + 1 ] , V_60 , sizeof( V_61 ) ) ;
}
}
}
F_27 ( V_60 ) ;
#endif
V_57 = 0 ;
V_55 = & ( V_34 -> V_64 [ 0 ] ) ;
for ( V_58 = 0 ; V_58 < V_63 ; V_58 ++ ) {
V_55 = & ( V_34 -> V_64 [ V_58 ] ) ;
if ( ! V_55 -> V_65 )
continue;
V_57 ++ ;
}
V_56 = F_28 ( V_57 , sizeof( struct V_53 ) , V_62 ) ;
if ( V_56 == NULL ) {
V_16 = - V_19 ;
return V_16 ;
}
V_54 = (struct V_53 * ) V_56 ;
V_55 = & ( V_34 -> V_64 [ 0 ] ) ;
for ( V_58 = 0 , V_59 = 0 ; V_58 < V_63 ; V_58 ++ ) {
V_55 = & ( V_34 -> V_64 [ V_58 ] ) ;
if ( V_55 -> V_65 ) {
if ( V_59 >= V_57 )
break;
memcpy ( V_54 -> V_46 , V_55 -> V_67 , V_68 ) ;
V_47 = ( T_3 ) V_55 -> V_50 ;
memcpy ( V_54 -> V_49 , V_47 -> V_50 , V_47 -> V_51 ) ;
V_54 -> V_52 = V_47 -> V_51 ;
V_54 -> V_69 = V_70 [ V_55 -> V_71 - 1 ] ;
V_54 -> V_72 = V_55 -> V_73 ;
if ( V_55 -> V_74 != 0 ) {
V_54 -> V_75 = V_55 -> V_74 ;
memcpy ( V_54 -> V_76 , V_55 -> V_77 , V_55 -> V_74 ) ;
}
if ( V_55 -> V_78 != 0 ) {
V_54 -> V_79 = V_55 -> V_78 ;
memcpy ( V_54 -> V_80 , V_55 -> V_81 , V_55 -> V_78 ) ;
}
V_54 = (struct V_53 * ) ( ( unsigned char * ) V_54 + sizeof( struct V_53 ) ) ;
V_59 ++ ;
}
}
if ( V_59 < V_57 )
V_57 = V_59 ;
if ( F_29 ( V_33 -> V_44 . V_82 . V_83 , V_56 , sizeof( struct V_53 ) * V_57 ) )
V_16 = - V_84 ;
V_33 -> V_44 . V_82 . V_85 = V_57 ;
F_7 ( V_24 , V_25 L_6 , V_57 ) ;
F_27 ( V_56 ) ;
return V_16 ;
}
static int F_30 ( T_1 V_14 ,
struct V_32 * V_33 )
{
T_2 V_34 = V_14 -> V_34 ;
T_3 V_47 ;
unsigned char V_86 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_87 [ 64 ] ;
bool V_88 = false ;
F_7 ( V_24 , V_25 L_7 , V_33 -> V_44 . V_45 . V_89 ) ;
F_7 ( V_24 , V_25 L_8 , V_33 -> V_44 . V_45 . V_90 ) ;
F_7 ( V_24 , V_25 L_9 , V_33 -> V_44 . V_45 . V_91 ) ;
F_7 ( V_24 , V_25 L_10 , V_33 -> V_44 . V_45 . V_92 ) ;
F_7 ( V_24 , V_25 L_11 , V_33 -> V_44 . V_45 . V_93 ) ;
F_7 ( V_24 , V_25 L_12 , V_33 -> V_44 . V_45 . V_75 ) ;
if ( V_33 -> V_44 . V_45 . V_75 ) {
if ( ! V_33 -> V_44 . V_45 . V_76 )
return - V_94 ;
if ( V_33 -> V_44 . V_45 . V_75 > sizeof( V_87 ) )
return - V_94 ;
if ( F_31 ( & V_87 [ 0 ] , V_33 -> V_44 . V_45 . V_76 , V_33 -> V_44 . V_45 . V_75 ) )
return - V_84 ;
}
if ( V_33 -> V_44 . V_45 . V_93 == 1 )
V_34 -> V_95 = V_96 ;
else
V_34 -> V_95 = V_97 ;
memset ( V_34 -> V_98 , 0 , V_99 + V_100 + 1 ) ;
V_47 = ( T_3 ) V_34 -> V_98 ;
V_47 -> V_101 = V_102 ;
V_47 -> V_51 = V_33 -> V_44 . V_45 . V_52 ;
memcpy ( V_47 -> V_50 , V_33 -> V_44 . V_45 . V_49 , V_47 -> V_51 ) ;
if ( memcmp ( V_33 -> V_44 . V_45 . V_46 , & V_86 [ 0 ] , 6 ) != 0 )
memcpy ( V_34 -> V_103 , V_33 -> V_44 . V_45 . V_46 , 6 ) ;
else
F_18 ( ( void * ) V_14 , V_43 , V_47 -> V_50 ) ;
if ( V_33 -> V_44 . V_45 . V_75 == 0 ) {
if ( V_33 -> V_44 . V_45 . V_92 & V_104 )
V_34 -> V_35 = V_105 ;
else
V_34 -> V_35 = V_36 ;
} else if ( V_87 [ 0 ] == V_106 ) {
if ( V_33 -> V_44 . V_45 . V_91 == V_107 )
V_34 -> V_35 = V_108 ;
else
V_34 -> V_35 = V_109 ;
} else {
if ( V_33 -> V_44 . V_45 . V_91 == V_110 )
V_34 -> V_35 = V_111 ;
else if ( V_33 -> V_44 . V_45 . V_91 == V_107 )
V_34 -> V_35 = V_112 ;
else
V_34 -> V_35 = V_113 ;
}
switch ( V_33 -> V_44 . V_45 . V_89 ) {
case V_114 :
V_14 -> V_115 = V_116 ;
break;
case V_117 :
V_14 -> V_115 = V_118 ;
break;
case V_119 :
case V_120 :
V_14 -> V_115 = V_121 ;
V_88 = true ;
break;
case V_122 :
if ( V_33 -> V_44 . V_45 . V_90 == V_114 )
V_14 -> V_115 = V_116 ;
else
V_14 -> V_115 = V_118 ;
break;
default:
V_14 -> V_115 = V_123 ;
}
if ( V_34 -> V_35 == V_105 ) {
V_14 -> V_115 = V_121 ;
V_34 -> V_37 = true ;
} else if ( V_34 -> V_35 == V_36 ) {
if ( ! V_88 ) V_14 -> V_115 = V_123 ;
else V_14 -> V_115 = V_121 ;
}
V_14 -> V_124 = V_14 -> V_115 ;
if ( V_14 -> V_115 != V_123 )
V_14 -> V_125 = true ;
else
V_14 -> V_125 = false ;
if ( ! ( ( V_34 -> V_35 == V_105 ) ||
( ( V_34 -> V_35 == V_36 ) && V_88 ) ) )
F_32 ( & V_14 -> V_126 , V_14 -> V_127 ) ;
F_17 ( & V_14 -> V_38 ) ;
V_14 -> V_39 = false ;
memset ( V_34 -> V_41 , 0 , 6 ) ;
V_34 -> V_128 = V_129 ;
F_33 ( V_14 -> V_2 ) ;
{
T_4 V_130 = NULL ;
V_130 = F_34 ( V_14 ,
V_34 -> V_103 ,
V_34 -> V_98 ,
V_34 -> V_131
) ;
if ( V_130 == NULL ) {
F_35 ( L_13 ) ;
F_18 ( ( void * ) V_14 , V_43 , V_34 -> V_98 ) ;
}
}
F_18 ( ( void * ) V_14 , V_132 , NULL ) ;
F_19 ( & V_14 -> V_38 ) ;
return 0 ;
}
int F_36 ( T_1 V_14 , struct V_133 * V_134 )
{
struct V_32 * V_33 ;
int V_16 = 0 ;
int F_36 = 0 ;
if ( V_134 -> V_135 < sizeof( struct V_32 ) ||
V_134 -> V_135 > V_136 || ! V_134 -> V_137 )
return - V_94 ;
V_33 = F_25 ( ( int ) V_134 -> V_135 , V_138 ) ;
if ( V_33 == NULL )
return - V_19 ;
if ( F_31 ( V_33 , V_134 -> V_137 , V_134 -> V_135 ) ) {
V_16 = - V_84 ;
goto V_139;
}
switch ( V_33 -> V_140 ) {
case V_141 :
V_16 = F_15 ( V_14 , V_33 ) ;
F_7 ( V_24 , V_25 L_14 ) ;
break;
case V_142 :
F_7 ( V_24 , V_25 L_15 ) ;
F_17 ( & V_14 -> V_38 ) ;
V_16 = F_14 ( V_14 , V_33 , false ) ;
F_19 ( & V_14 -> V_38 ) ;
break;
case V_143 :
F_7 ( V_24 , V_25 L_16 ) ;
V_16 = F_20 ( V_14 , V_33 ) ;
break;
case V_144 :
F_7 ( V_24 , V_25 L_17 ) ;
V_16 = F_24 ( V_14 , V_33 ) ;
F_36 = 1 ;
break;
case V_145 :
F_7 ( V_24 , V_25 L_18 ) ;
V_16 = F_23 ( V_14 , V_33 ) ;
F_36 = 1 ;
break;
case V_146 :
F_7 ( V_24 , V_25 L_19 ) ;
V_16 = F_22 ( V_14 , V_33 ) ;
F_36 = 1 ;
break;
case V_147 :
F_7 ( V_24 , V_25 L_20 ) ;
V_16 = F_30 ( V_14 , V_33 ) ;
break;
case V_148 :
F_7 ( V_24 , V_25 L_21 ) ;
V_16 = F_16 ( V_14 , V_33 ) ;
break;
case V_149 :
F_7 ( V_24 , V_25 L_22 ) ;
break;
case V_150 :
F_7 ( V_24 , V_25 L_23 ) ;
break;
default:
F_7 ( V_24 , V_25 L_24 ,
V_33 -> V_140 ) ;
V_16 = - V_151 ;
goto V_139;
}
if ( ( V_16 == 0 ) && F_36 ) {
if ( F_29 ( V_134 -> V_137 , V_33 , V_134 -> V_135 ) ) {
V_16 = - V_84 ;
goto V_139;
}
}
V_139:
F_27 ( V_33 ) ;
return V_16 ;
}
