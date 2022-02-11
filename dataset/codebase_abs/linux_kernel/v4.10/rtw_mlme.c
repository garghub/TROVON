int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
int V_10 = V_11 ;
V_8 -> V_12 = ( T_1 * ) V_2 ;
V_8 -> V_13 = NULL ;
V_8 -> V_14 = 0 ;
V_8 -> V_15 . V_16 . V_17 = V_18 ;
V_8 -> V_19 = V_20 ;
F_2 ( & ( V_8 -> V_21 ) ) ;
F_3 ( & ( V_8 -> V_22 ) ) ;
F_3 ( & ( V_8 -> V_23 ) ) ;
memset ( & V_8 -> V_24 , 0 , sizeof( struct V_25 ) ) ;
V_4 = F_4 ( V_26 * ( sizeof( struct V_5 ) ) ) ;
if ( V_4 == NULL ) {
V_10 = V_27 ;
goto exit;
}
V_8 -> V_28 = V_4 ;
V_6 = (struct V_5 * ) V_4 ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
F_5 ( & ( V_6 -> V_29 ) ) ;
F_6 ( & ( V_6 -> V_29 ) , & ( V_8 -> V_22 . V_30 ) ) ;
V_6 ++ ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
exit:
return V_10 ;
}
static void F_9 ( T_1 * * V_31 , T_2 * V_32 )
{
F_10 ( * V_31 ) ;
* V_32 = 0 ;
* V_31 = NULL ;
}
void F_11 ( struct V_7 * V_8 )
{
F_12 ( & V_8 -> V_33 , & V_8 -> V_34 ) ;
F_12 ( & V_8 -> V_35 , & V_8 -> V_36 ) ;
F_9 ( & V_8 -> V_37 , & V_8 -> V_38 ) ;
F_9 ( & V_8 -> V_39 , & V_8 -> V_40 ) ;
F_9 ( & V_8 -> V_41 , & V_8 -> V_42 ) ;
F_9 ( & V_8 -> V_43 , & V_8 -> V_44 ) ;
}
void F_11 ( struct V_7 * V_8 )
{
}
void F_13 ( struct V_7 * V_8 )
{
F_11 ( V_8 ) ;
if ( V_8 )
F_14 ( V_8 -> V_28 ) ;
}
struct V_5 * F_15 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_45 * V_46 = & V_8 -> V_22 ;
F_16 ( & V_46 -> V_21 ) ;
V_6 = F_17 ( & V_46 -> V_30 ,
struct V_5 , V_29 ) ;
if ( ! V_6 )
goto exit;
F_18 ( & V_6 -> V_29 ) ;
F_19 ( V_47 , V_48 ,
( L_1 , & V_6 -> V_29 ) ) ;
V_6 -> V_49 = 0 ;
V_6 -> V_50 = false ;
V_6 -> V_51 = V_52 ;
V_6 -> V_53 = 0 ;
V_6 -> V_54 = 0 ;
exit:
F_20 ( & V_46 -> V_21 ) ;
return V_6 ;
}
static void F_21 ( struct V_7 * V_8 , struct V_5 * V_6 , T_1 V_55 )
{
unsigned long V_56 ;
T_2 V_57 ;
T_2 V_58 = V_59 ;
struct V_45 * V_46 = & ( V_8 -> V_22 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_50 )
return;
V_56 = V_52 ;
if ( ( F_22 ( V_8 , V_60 ) ) ||
( F_22 ( V_8 , V_61 ) ) )
V_58 = 1 ;
if ( ! V_55 ) {
V_57 = ( V_56 - V_6 -> V_51 ) / V_62 ;
if ( V_57 < V_58 )
return;
}
F_16 ( & V_46 -> V_21 ) ;
F_18 ( & ( V_6 -> V_29 ) ) ;
F_6 ( & ( V_6 -> V_29 ) , & ( V_46 -> V_30 ) ) ;
F_20 ( & V_46 -> V_21 ) ;
}
void F_23 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
struct V_45 * V_46 = & ( V_8 -> V_22 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_50 )
return;
F_18 ( & ( V_6 -> V_29 ) ) ;
F_6 ( & ( V_6 -> V_29 ) , F_24 ( V_46 ) ) ;
}
struct V_5 * F_25 ( struct V_45 * V_23 , T_1 * V_63 )
{
struct V_64 * V_65 , * V_66 ;
struct V_5 * V_6 = NULL ;
T_1 V_67 [ V_68 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( ! memcmp ( V_67 , V_63 , V_68 ) ) {
V_6 = NULL ;
goto exit;
}
V_65 = F_24 ( V_23 ) ;
V_66 = V_65 -> V_69 ;
while ( V_66 != V_65 ) {
V_6 = F_26 ( V_66 , struct V_5 , V_29 ) ;
if ( ! memcmp ( V_63 , V_6 -> V_16 . V_70 , V_68 ) )
break;
V_66 = V_66 -> V_69 ;
}
if ( V_66 == V_65 )
V_6 = NULL ;
exit:
return V_6 ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_55 )
{
struct V_64 * V_65 , * V_66 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_45 * V_23 = & V_8 -> V_23 ;
F_16 ( & V_23 -> V_21 ) ;
V_65 = F_24 ( V_23 ) ;
V_66 = V_65 -> V_69 ;
while ( V_65 != V_66 ) {
V_6 = F_26 ( V_66 , struct V_5 , V_29 ) ;
V_66 = V_66 -> V_69 ;
F_21 ( V_8 , V_6 , V_55 ) ;
}
F_20 ( & V_23 -> V_21 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_71 || V_2 -> V_72 ||
( F_22 ( & V_2 -> V_9 , V_73 ) == false ) ) {
F_19 ( V_47 , V_48 ,
( L_2 ,
V_2 -> V_71 , V_2 -> V_72 ) ) ;
V_10 = false ;
} else {
V_10 = true ;
}
return V_10 ;
}
void F_29 ( T_1 * V_74 )
{
unsigned long V_75 = V_52 ;
V_74 [ 0 ] = 0x02 ;
V_74 [ 1 ] = 0x11 ;
V_74 [ 2 ] = 0x87 ;
V_74 [ 3 ] = ( T_1 ) ( V_75 & 0xff ) ;
V_74 [ 4 ] = ( T_1 ) ( ( V_75 >> 8 ) & 0xff ) ;
V_74 [ 5 ] = ( T_1 ) ( ( V_75 >> 16 ) & 0xff ) ;
}
T_1 * F_30 ( T_1 * V_76 )
{
return V_76 + 8 + 2 ;
}
T_3 F_31 ( struct V_77 * V_78 )
{
T_4 V_79 ;
memcpy ( ( T_1 * ) & V_79 , F_30 ( V_78 -> V_80 ) , 2 ) ;
return F_32 ( V_79 ) ;
}
T_1 * F_33 ( T_1 * V_76 )
{
return V_76 + 8 ;
}
static struct V_5 * F_34 ( struct V_7 * V_8 )
{
return F_15 ( V_8 ) ;
}
static void F_35 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_23 ( V_8 , V_6 ) ;
}
int F_36 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
int V_81 = true ;
struct V_82 * V_83 = & V_1 -> V_84 ;
if ( ( V_83 -> V_85 != V_86 ) &&
( V_6 -> V_16 . V_87 == 0 ) )
V_81 = false ;
else if ( ( V_83 -> V_85 == V_86 ) &&
( V_6 -> V_16 . V_87 == 1 ) )
V_81 = false ;
else
V_81 = true ;
return V_81 ;
}
static int F_37 ( struct V_77 * V_88 , struct V_77 * V_89 )
{
return ( V_88 -> V_90 . V_91 == V_89 -> V_90 . V_91 ) &&
! memcmp ( V_88 -> V_90 . V_90 , V_89 -> V_90 . V_90 , V_88 -> V_90 . V_91 ) ;
}
int F_38 ( struct V_77 * V_92 , struct V_77 * V_93 )
{
T_3 V_94 , V_95 ;
T_4 V_96 , V_97 ;
memcpy ( ( T_1 * ) & V_96 , F_30 ( V_92 -> V_80 ) , 2 ) ;
memcpy ( ( T_1 * ) & V_97 , F_30 ( V_93 -> V_80 ) , 2 ) ;
V_94 = F_32 ( V_96 ) ;
V_95 = F_32 ( V_97 ) ;
return ( ( V_92 -> V_90 . V_91 == V_93 -> V_90 . V_91 ) &&
( ( ! memcmp ( V_92 -> V_70 , V_93 -> V_70 , V_68 ) ) == true ) &&
( ( ! memcmp ( V_92 -> V_90 . V_90 , V_93 -> V_90 . V_90 , V_92 -> V_90 . V_91 ) ) == true ) &&
( ( V_94 & V_98 ) ==
( V_95 & V_98 ) ) &&
( ( V_94 & V_99 ) ==
( V_95 & V_99 ) ) ) ;
}
struct V_5 * F_39 ( struct V_45 * V_23 )
{
struct V_64 * V_66 , * V_65 ;
struct V_5 * V_100 = NULL ;
struct V_5 * V_101 = NULL ;
V_65 = F_24 ( V_23 ) ;
for ( V_66 = V_65 -> V_69 ; V_66 != V_65 ; V_66 = V_66 -> V_69 ) {
V_100 = F_26 ( V_66 , struct V_5 , V_29 ) ;
if ( ! V_100 -> V_50 ) {
if ( V_101 == NULL || F_40 ( V_101 -> V_51 , V_100 -> V_51 ) )
V_101 = V_100 ;
}
}
return V_101 ;
}
void F_41 ( struct V_77 * V_93 , struct V_77 * V_92 ,
struct V_1 * V_2 , bool V_102 )
{
long V_103 = V_93 -> V_104 ;
T_1 V_105 = V_92 -> V_106 . V_107 ;
T_1 V_108 ;
T_1 V_109 ;
long V_110 ;
F_42 ( V_2 , V_93 , V_92 ) ;
if ( F_22 ( & V_2 -> V_9 , V_73 ) && F_38 ( & ( V_2 -> V_9 . V_15 . V_16 ) , V_92 ) ) {
V_108 = V_2 -> V_111 . V_112 ;
V_109 = V_2 -> V_111 . V_113 ;
if ( V_105 != 101 )
V_110 = ( V_92 -> V_104 + V_93 -> V_104 * 4 ) / 5 ;
else
V_110 = V_103 ;
} else {
if ( V_105 != 101 ) {
V_108 = ( ( T_2 ) ( V_92 -> V_106 . V_114 ) + ( T_2 ) ( V_93 -> V_106 . V_114 ) * 4 ) / 5 ;
V_109 = ( ( T_2 ) ( V_92 -> V_106 . V_107 ) + ( T_2 ) ( V_93 -> V_106 . V_107 ) * 4 ) / 5 ;
V_110 = ( V_92 -> V_104 + V_93 -> V_104 * 4 ) / 5 ;
} else {
V_108 = V_93 -> V_106 . V_114 ;
V_109 = V_93 -> V_106 . V_107 ;
V_110 = V_93 -> V_104 ;
}
}
if ( V_102 )
memcpy ( ( T_1 * ) V_93 , ( T_1 * ) V_92 , F_43 ( V_92 ) ) ;
V_93 -> V_106 . V_114 = V_108 ;
V_93 -> V_106 . V_107 = V_109 ;
V_93 -> V_104 = V_110 ;
}
static void F_44 ( struct V_1 * V_1 , struct V_77 * V_6 )
{
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
if ( ( F_22 ( V_8 , V_73 ) == true ) &&
( F_38 ( & ( V_8 -> V_15 . V_16 ) , V_6 ) ) ) {
F_41 ( & ( V_8 -> V_15 . V_16 ) , V_6 , V_1 , true ) ;
F_45 ( V_1 , ( V_8 -> V_15 . V_16 . V_80 ) + sizeof( struct V_115 ) ,
V_8 -> V_15 . V_16 . V_116 ) ;
}
}
void F_46 ( struct V_1 * V_1 , struct V_77 * V_117 )
{
struct V_64 * V_66 , * V_65 ;
T_2 V_118 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_45 * V_30 = & ( V_8 -> V_23 ) ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_101 = NULL ;
F_16 ( & V_30 -> V_21 ) ;
V_65 = F_24 ( V_30 ) ;
V_66 = V_65 -> V_69 ;
while ( V_65 != V_66 ) {
V_6 = F_26 ( V_66 , struct V_5 , V_29 ) ;
if ( F_38 ( & ( V_6 -> V_16 ) , V_117 ) )
break;
if ( ( V_101 == ( (struct V_5 * ) 0 ) ) ||
F_40 ( V_101 -> V_51 , V_6 -> V_51 ) )
V_101 = V_6 ;
V_66 = V_66 -> V_69 ;
}
if ( V_65 == V_66 ) {
if ( F_47 ( & ( V_8 -> V_22 . V_30 ) ) ) {
V_6 = V_101 ;
F_48 ( V_1 , V_119 , & ( V_117 -> V_106 . V_120 ) ) ;
memcpy ( & ( V_6 -> V_16 ) , V_117 , F_43 ( V_117 ) ) ;
V_6 -> V_50 = false ;
V_6 -> V_51 = V_52 ;
V_6 -> V_49 = 0 ;
V_6 -> V_53 = 0 ;
V_6 -> V_54 = 0 ;
if ( V_6 -> V_16 . V_106 . V_107 == 101 )
V_6 -> V_16 . V_106 . V_107 = 0 ;
} else {
V_6 = F_34 ( V_8 ) ;
if ( V_6 == NULL ) {
F_19 ( V_47 , V_121 , ( L_3 ) ) ;
goto exit;
}
V_118 = F_43 ( V_117 ) ;
V_117 -> V_122 = V_118 ;
F_48 ( V_1 , V_119 , & ( V_117 -> V_106 . V_120 ) ) ;
memcpy ( & ( V_6 -> V_16 ) , V_117 , V_118 ) ;
V_6 -> V_51 = V_52 ;
if ( V_6 -> V_16 . V_106 . V_107 == 101 )
V_6 -> V_16 . V_106 . V_107 = 0 ;
F_6 ( & ( V_6 -> V_29 ) , & ( V_30 -> V_30 ) ) ;
}
} else {
bool V_102 = true ;
V_6 -> V_51 = V_52 ;
if ( ( V_6 -> V_16 . V_116 > V_117 -> V_116 ) && ( V_117 -> V_123 [ 0 ] == 1 ) )
V_102 = false ;
F_41 ( & ( V_6 -> V_16 ) , V_117 , V_1 , V_102 ) ;
}
exit:
F_20 ( & V_30 -> V_21 ) ;
}
static void F_49 ( struct V_1 * V_1 ,
struct V_77 * V_6 )
{
F_44 ( V_1 , V_6 ) ;
F_46 ( V_1 , V_6 ) ;
}
static int F_50 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
struct V_82 * V_83 = & V_1 -> V_84 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
T_2 V_124 ;
T_2 V_125 ;
T_5 V_126 ;
int V_127 = true ;
V_124 = V_83 -> V_128 ;
V_125 = V_6 -> V_16 . V_87 ;
if ( F_22 ( V_8 , V_129 ) ) {
if ( F_51 ( V_6 -> V_16 . V_80 + V_130 , V_6 -> V_16 . V_116 - V_130 , NULL , & V_126 ) != NULL )
return true ;
else
return false ;
}
if ( V_1 -> V_131 . V_132 == 1 ) {
if ( ( V_124 == V_133 ) && ( V_125 != 0 ) )
V_127 = false ;
}
if ( ( V_124 != V_133 ) && ( V_125 == 0 ) ) {
F_52 ( L_4 , V_124 , V_125 ) ;
V_127 = false ;
}
if ( F_22 ( V_8 , V_61 ) == true ) {
if ( V_6 -> V_16 . V_17 != V_8 -> V_15 . V_16 . V_17 )
V_127 = false ;
}
return V_127 ;
}
void F_53 ( struct V_1 * V_1 , T_1 * V_4 )
{
F_19 ( V_47 , V_121 , ( L_5 ) ) ;
}
void F_54 ( struct V_1 * V_1 , T_1 * V_4 )
{
T_2 V_134 ;
struct V_77 * V_6 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
V_6 = (struct V_77 * ) V_4 ;
F_19 ( V_47 , V_48 , ( L_6 , V_6 -> V_90 . V_90 ) ) ;
V_134 = F_43 ( V_6 ) ;
if ( V_134 > ( sizeof( struct V_77 ) ) ) {
F_19 ( V_47 , V_121 , ( L_7 ) ) ;
return;
}
F_16 ( & V_8 -> V_21 ) ;
if ( ( F_22 ( V_8 , V_60 ) ) == true ) {
if ( ! memcmp ( & ( V_8 -> V_15 . V_16 . V_70 ) , V_6 -> V_70 , V_68 ) ) {
struct V_5 * V_135 = NULL ;
memcpy ( V_8 -> V_15 . V_16 . V_80 , V_6 -> V_80 , 8 ) ;
F_16 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_135 = F_25 ( & V_8 -> V_23 , V_6 -> V_70 ) ;
if ( V_135 ) {
memcpy ( V_135 -> V_16 . V_80 , V_6 -> V_80 , 8 ) ;
F_20 ( & V_8 -> V_23 . V_21 ) ;
goto exit;
}
F_20 ( & V_8 -> V_23 . V_21 ) ;
}
}
if ( ( F_22 ( V_8 , V_136 ) ) == false ) {
if ( V_6 -> V_90 . V_90 [ 0 ] == 0 )
V_6 -> V_90 . V_91 = 0 ;
F_49 ( V_1 , V_6 ) ;
}
exit:
F_20 ( & V_8 -> V_21 ) ;
return;
}
void F_55 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
F_16 ( & V_8 -> V_21 ) ;
if ( V_8 -> V_39 ) {
V_8 -> V_40 = 0 ;
F_10 ( V_8 -> V_39 ) ;
V_8 -> V_39 = NULL ;
}
F_19 ( V_47 , V_48 , ( L_8 , F_56 ( V_8 ) ) ) ;
if ( F_22 ( V_8 , V_137 ) ) {
F_57 ( & V_8 -> V_138 ) ;
F_58 ( V_8 , V_137 ) ;
} else {
F_19 ( V_47 , V_121 , ( L_9 , F_56 ( V_8 ) ) ) ;
}
F_59 ( & V_1 -> V_111 ) ;
if ( V_8 -> V_139 ) {
if ( ( F_22 ( V_8 , V_61 ) == true ) ) {
if ( F_22 ( V_8 , V_73 ) == false ) {
F_60 ( V_8 , V_136 ) ;
if ( F_61 ( V_8 ) == V_11 ) {
F_62 ( & V_8 -> V_140 ,
V_52 + F_63 ( V_141 ) ) ;
} else {
struct V_77 * V_142 = & ( V_1 -> V_131 . V_143 ) ;
T_1 * V_74 = V_1 -> V_131 . V_143 . V_70 ;
F_58 ( V_8 , V_137 ) ;
F_19 ( V_47 , V_121 , ( L_10 ) ) ;
memcpy ( & V_142 -> V_90 , & V_8 -> V_24 , sizeof( struct V_25 ) ) ;
F_64 ( V_1 ) ;
F_29 ( V_74 ) ;
V_8 -> V_14 = V_60 ;
if ( F_65 ( V_1 ) != V_11 )
F_19 ( V_47 , V_121 , ( L_11 ) ) ;
V_8 -> V_139 = false ;
}
}
} else {
int V_144 ;
F_60 ( V_8 , V_136 ) ;
V_8 -> V_139 = false ;
V_144 = F_61 ( V_8 ) ;
if ( V_11 == V_144 ) {
F_62 ( & V_8 -> V_140 ,
V_52 + F_63 ( V_141 ) ) ;
} else if ( V_144 == 2 ) {
F_58 ( V_8 , V_136 ) ;
F_66 ( V_1 ) ;
} else {
F_52 ( L_12 , V_8 -> V_145 ) ;
if ( V_8 -> V_145 != 0 ) {
if ( -- V_8 -> V_145 == 0 ||
V_11 != F_67 ( V_1 , & V_8 -> V_24 , 1 , NULL , 0 ) ) {
V_8 -> V_145 = 0 ;
F_68 ( V_1 ) ;
F_69 ( V_1 ) ;
} else {
V_8 -> V_139 = true ;
}
}
F_58 ( V_8 , V_136 ) ;
}
}
}
F_70 ( V_1 ) ;
F_20 ( & V_8 -> V_21 ) ;
F_71 ( V_1 ) ;
}
void F_72 ( struct V_1 * V_1 , T_1 * V_4 )
{
}
void F_73 ( struct V_1 * V_1 , T_1 * V_4 )
{
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_45 * V_46 = & V_8 -> V_22 ;
struct V_45 * V_146 = & V_8 -> V_23 ;
struct V_64 * V_66 , * V_65 , * V_147 ;
F_19 ( V_47 , V_148 , ( L_13 ) ) ;
F_16 ( & V_146 -> V_21 ) ;
F_16 ( & V_46 -> V_21 ) ;
V_65 = F_24 ( V_146 ) ;
V_66 = V_65 -> V_69 ;
while ( V_66 != V_65 ) {
V_147 = V_66 -> V_69 ;
F_18 ( V_66 ) ;
F_6 ( V_66 , & V_46 -> V_30 ) ;
V_66 = V_147 ;
}
F_20 ( & V_46 -> V_21 ) ;
F_20 ( & V_146 -> V_21 ) ;
}
void F_68 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = & V_1 -> V_9 ;
F_16 ( & V_8 -> V_23 . V_21 ) ;
F_75 ( V_1 ) ;
F_20 ( & V_8 -> V_23 . V_21 ) ;
}
void F_75 ( struct V_1 * V_1 )
{
struct V_5 * V_100 = NULL ;
struct V_7 * V_8 = & V_1 -> V_9 ;
struct V_149 * V_150 = & V_1 -> V_151 ;
struct V_5 * V_152 = & V_8 -> V_15 ;
F_19 ( V_47 , V_148 , ( L_14 ) ) ;
F_19 ( V_47 , V_48 ,
( L_15 ,
V_152 -> V_16 . V_70 , V_152 -> V_16 . V_90 . V_90 ) ) ;
if ( F_22 ( V_8 , V_153 | V_154 ) ) {
struct V_155 * V_156 ;
V_156 = F_76 ( & V_1 -> V_151 , V_152 -> V_16 . V_70 ) ;
F_16 ( & ( V_150 -> V_157 ) ) ;
F_77 ( V_1 , V_156 ) ;
F_20 ( & V_150 -> V_157 ) ;
}
if ( F_22 ( V_8 , V_61 | V_60 | V_154 ) ) {
struct V_155 * V_156 ;
F_78 ( V_1 ) ;
V_156 = F_79 ( V_1 ) ;
F_16 ( & ( V_150 -> V_157 ) ) ;
F_77 ( V_1 , V_156 ) ;
F_20 ( & V_150 -> V_157 ) ;
F_80 ( V_1 ) ;
}
V_100 = F_25 ( & V_8 -> V_23 , V_152 -> V_16 . V_70 ) ;
if ( V_100 )
V_100 -> V_50 = false ;
else
F_19 ( V_47 , V_121 , ( L_16 ) ) ;
if ( ( F_22 ( V_8 , V_60 ) && ( V_1 -> V_151 . V_158 == 1 ) ) )
F_35 ( V_8 , V_100 ) ;
V_8 -> V_159 = 0 ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
F_19 ( V_47 , V_121 , ( L_17 ) ) ;
V_8 -> V_139 = false ;
if ( ! F_22 ( & V_2 -> V_9 , V_73 ) ) {
F_60 ( V_8 , V_73 ) ;
F_81 ( V_2 , V_160 ) ;
F_82 ( V_2 ) ;
}
V_8 -> V_145 = 0 ;
F_83 ( V_2 , 3000 ) ;
F_19 ( V_47 , V_121 , ( L_18 , F_56 ( V_8 ) ) ) ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
F_19 ( V_47 , V_121 , ( L_19 ) ) ;
F_58 ( V_8 , V_136 | V_129 ) ;
if ( V_8 -> V_145 > 0 )
F_58 ( V_8 , V_73 ) ;
if ( F_22 ( & V_2 -> V_9 , V_73 ) ||
( V_8 -> V_145 <= 0 ) ) {
F_84 ( V_2 ) ;
F_58 ( V_8 , V_73 ) ;
F_81 ( V_2 , V_161 ) ;
F_7 ( V_2 ) ;
}
F_85 ( V_2 , V_162 , 1 ) ;
}
inline void F_86 ( struct V_1 * V_2 , bool V_163 )
{
F_87 ( V_2 , V_163 ) ;
}
void F_88 ( struct V_1 * V_1 )
{
unsigned long V_164 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_165 * V_166 = & ( V_1 -> V_167 ) ;
V_164 = V_52 ;
V_166 -> V_168 = true ;
while ( F_22 ( V_8 , V_137 ) &&
F_89 ( V_52 - V_164 ) <= 200 ) {
if ( V_1 -> V_71 || V_1 -> V_72 )
break;
F_52 ( V_169 L_20 , F_90 ( V_1 -> V_170 ) ) ;
F_91 ( 20 ) ;
}
if ( F_22 ( V_8 , V_137 ) ) {
if ( ! V_1 -> V_71 && ! V_1 -> V_72 )
F_52 ( V_169 L_21 , F_90 ( V_1 -> V_170 ) ) ;
F_86 ( V_1 , true ) ;
}
V_166 -> V_168 = false ;
}
static struct V_155 * F_92 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_3 ;
struct V_155 * V_171 , * V_156 = NULL ;
struct V_172 * V_173 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
V_156 = F_76 ( V_150 , V_6 -> V_16 . V_70 ) ;
if ( V_156 == NULL )
V_156 = F_93 ( V_150 , V_6 -> V_16 . V_70 ) ;
if ( V_156 ) {
F_52 ( L_22 , V_174 ) ;
V_156 -> V_53 = V_6 -> V_54 ;
V_156 -> V_175 = 0 ;
F_94 ( V_2 , V_176 , V_156 , true ) ;
if ( V_2 -> V_84 . V_177 == V_178 ) {
V_2 -> V_84 . V_179 = false ;
V_2 -> V_84 . V_180 = false ;
V_2 -> V_84 . V_181 = false ;
V_156 -> V_182 = true ;
V_156 -> V_183 = V_2 -> V_84 . V_85 ;
memset ( ( T_1 * ) & V_156 -> V_184 , 0 , sizeof( union V_185 ) ) ;
memset ( ( T_1 * ) & V_156 -> V_186 , 0 , sizeof( union V_185 ) ) ;
memset ( ( T_1 * ) & V_156 -> V_187 , 0 , sizeof( union V_185 ) ) ;
memset ( ( T_1 * ) & V_156 -> V_188 , 0 , sizeof( union V_189 ) ) ;
memset ( ( T_1 * ) & V_156 -> V_190 , 0 , sizeof( union V_189 ) ) ;
}
if ( V_2 -> V_84 . V_191 != 0 ) {
V_156 -> V_182 = true ;
V_2 -> V_84 . V_191 = 0 ;
}
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_173 = & V_156 -> V_192 [ V_3 ] ;
V_173 -> V_193 = false ;
V_173 -> V_194 = 0xffff ;
V_173 -> V_195 = 0xffff ;
V_173 -> V_196 = 64 ;
}
V_171 = F_79 ( V_2 ) ;
if ( V_171 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_173 = & V_171 -> V_192 [ V_3 ] ;
V_173 -> V_193 = false ;
V_173 -> V_194 = 0xffff ;
V_173 -> V_195 = 0xffff ;
V_173 -> V_196 = 64 ;
}
}
F_95 ( V_2 , V_156 ) ;
}
return V_156 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_5 * V_197 , struct V_5 * V_6 )
{
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_5 * V_15 = & ( V_8 -> V_15 ) ;
F_52 ( L_22 , V_174 ) ;
F_19 ( V_47 , V_48 ,
( L_23 ,
F_56 ( V_8 ) , V_6 -> V_16 . V_70 ) ) ;
memcpy ( & V_15 -> V_16 , & V_6 -> V_16 , V_6 -> V_16 . V_122 ) ;
V_15 -> V_16 . V_116 = V_197 -> V_16 . V_116 ;
memcpy ( & V_15 -> V_16 . V_80 [ 0 ] , & V_197 -> V_16 . V_80 [ 0 ] , V_198 ) ;
V_15 -> V_53 = V_6 -> V_54 ;
F_59 ( & V_2 -> V_111 ) ;
V_2 -> V_111 . V_112 = V_197 -> V_16 . V_106 . V_114 ;
V_2 -> V_111 . V_113 = V_197 -> V_16 . V_106 . V_107 ;
V_2 -> V_111 . V_199 = F_97 ( V_197 -> V_16 . V_106 . V_114 ) ;
F_59 ( & V_2 -> V_111 ) ;
switch ( V_6 -> V_16 . V_17 ) {
case V_200 :
if ( V_8 -> V_14 & V_129 )
V_8 -> V_14 = V_153 | V_129 ;
else
V_8 -> V_14 = V_153 ;
break;
case V_201 :
V_8 -> V_14 = V_61 ;
break;
default:
V_8 -> V_14 = V_202 ;
F_19 ( V_47 , V_121 , ( L_24 ) ) ;
break;
}
F_45 ( V_2 , ( V_15 -> V_16 . V_80 ) +
sizeof( struct V_115 ) ,
( V_15 -> V_16 . V_116 ) ) ;
F_98 ( V_2 , V_15 -> V_16 . V_80 , V_15 -> V_16 . V_116 ) ;
}
void F_99 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_155 * V_203 = NULL , * V_204 = NULL ;
struct V_149 * V_150 = & V_1 -> V_151 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
struct V_5 * V_15 = & ( V_8 -> V_15 ) ;
struct V_5 * V_205 = NULL , * V_197 = NULL ;
unsigned int V_206 = false ;
F_19 ( V_47 , V_48 , ( L_25 , V_6 -> V_54 ) ) ;
F_100 ( V_1 ) ;
if ( V_8 -> V_24 . V_91 == 0 )
F_19 ( V_47 , V_121 , ( L_26 ) ) ;
else
F_19 ( V_47 , V_121 , ( L_27 , V_8 -> V_24 . V_90 ) ) ;
V_206 = ! memcmp ( V_6 -> V_16 . V_70 , V_15 -> V_16 . V_70 , V_68 ) ;
V_6 -> V_16 . V_122 = F_43 ( & V_6 -> V_16 ) ;
if ( V_6 -> V_16 . V_122 > sizeof( struct V_77 ) ) {
F_19 ( V_47 , V_121 , ( L_28 ) ) ;
return;
}
F_16 ( & V_8 -> V_21 ) ;
F_19 ( V_47 , V_48 , ( L_29 ) ) ;
if ( V_6 -> V_54 > 0 ) {
F_16 ( & ( V_8 -> V_23 . V_21 ) ) ;
if ( F_22 ( V_8 , V_136 ) ) {
if ( F_22 ( V_8 , V_73 ) ) {
if ( V_206 ) {
V_197 = F_25 ( & V_8 -> V_23 , V_15 -> V_16 . V_70 ) ;
} else {
V_205 = F_25 ( & V_8 -> V_23 , V_15 -> V_16 . V_70 ) ;
if ( V_205 )
V_205 -> V_50 = false ;
V_204 = F_76 ( V_150 , V_15 -> V_16 . V_70 ) ;
if ( V_204 ) {
F_16 ( & ( V_150 -> V_157 ) ) ;
F_77 ( V_1 , V_204 ) ;
F_20 ( & V_150 -> V_157 ) ;
}
V_197 = F_25 ( & V_8 -> V_23 , V_6 -> V_16 . V_70 ) ;
if ( F_22 ( V_8 , V_153 ) == true ) {
if ( V_197 )
V_197 -> V_50 = true ;
}
}
} else {
V_197 = F_25 ( & V_8 -> V_23 , V_6 -> V_16 . V_70 ) ;
if ( F_22 ( V_8 , V_153 ) == true ) {
if ( V_197 )
V_197 -> V_50 = true ;
}
}
if ( V_197 ) {
F_96 ( V_1 , V_197 , V_6 ) ;
} else {
F_19 ( V_47 , V_121 , ( L_30 ) ) ;
F_20 ( & V_8 -> V_23 . V_21 ) ;
goto V_207;
}
if ( F_22 ( V_8 , V_153 ) == true ) {
V_203 = F_92 ( V_1 , V_6 ) ;
if ( V_203 == NULL ) {
F_19 ( V_47 , V_121 , ( L_31 ) ) ;
F_20 ( & V_8 -> V_23 . V_21 ) ;
goto V_207;
}
}
if ( F_22 ( V_8 , V_153 ) == true ) {
F_66 ( V_1 ) ;
} else {
F_19 ( V_47 , V_48 , ( L_32 , F_56 ( V_8 ) ) ) ;
}
F_57 ( & V_8 -> V_140 ) ;
F_19 ( V_47 , V_48 , ( L_33 ) ) ;
} else {
F_19 ( V_47 , V_121 , ( L_34 , F_56 ( V_8 ) ) ) ;
F_20 ( & V_8 -> V_23 . V_21 ) ;
goto V_207;
}
F_20 ( & V_8 -> V_23 . V_21 ) ;
} else if ( V_6 -> V_54 == - 4 ) {
F_101 ( V_1 ) ;
F_62 ( & V_8 -> V_140 ,
V_52 + F_63 ( 1 ) ) ;
if ( ( F_22 ( V_8 , V_136 ) ) == true ) {
F_19 ( V_47 , V_121 , ( L_35 , F_56 ( V_8 ) ) ) ;
F_58 ( V_8 , V_136 ) ;
}
} else {
F_62 ( & V_8 -> V_140 ,
V_52 + F_63 ( 1 ) ) ;
F_58 ( V_8 , V_136 ) ;
}
V_207:
F_20 ( & V_8 -> V_21 ) ;
}
void F_102 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
F_103 ( V_1 , V_6 -> V_54 ) ;
F_71 ( V_1 ) ;
}
static T_1 F_104 ( struct V_1 * V_2 )
{
T_1 V_175 ;
#if F_105 ( V_208 )
T_1 V_53 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_149 * V_150 = & V_2 -> V_151 ;
#endif
struct V_165 * V_166 = & ( V_2 -> V_167 ) ;
struct V_209 * V_210 = & ( V_166 -> V_211 ) ;
#if F_105 ( V_208 )
if ( F_22 ( V_8 , V_154 ) ) {
for ( V_53 = ( V_150 -> V_212 ) ; V_53 > 0 ; V_53 -- ) {
if ( V_150 -> V_213 [ V_53 - 1 ] != NULL )
break;
}
V_175 = V_53 + 1 ;
} else
#endif
{
for ( V_175 = ( V_214 - 1 ) ; V_175 >= V_215 ; V_175 -- ) {
if ( V_210 -> V_216 [ V_175 ] . V_217 == 1 )
break;
}
}
return V_175 ;
}
void F_106 ( struct V_1 * V_1 , struct V_155 * V_156 )
{
T_3 V_218 ;
T_1 V_219 ;
if ( V_156 == NULL )
return;
V_219 = F_104 ( V_1 ) ;
F_107 ( V_1 , V_220 , ( T_1 * ) & V_219 ) ;
V_218 = ( V_156 -> V_175 << 8 ) | 1 ;
F_107 ( V_1 , V_221 , ( T_1 * ) & V_218 ) ;
}
void F_108 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_155 * V_156 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_222 * V_223 = (struct V_222 * ) V_4 ;
struct V_5 * V_15 = & ( V_8 -> V_15 ) ;
struct V_5 * V_197 = NULL ;
if ( F_109 ( V_1 , V_223 -> V_224 ) == false )
return;
#if F_105 ( V_208 )
if ( F_22 ( V_8 , V_154 ) ) {
V_156 = F_76 ( & V_1 -> V_151 , V_223 -> V_224 ) ;
if ( V_156 ) {
F_110 ( V_1 , V_156 ) ;
F_106 ( V_1 , V_156 ) ;
}
return;
}
#endif
V_156 = F_76 ( & V_1 -> V_151 , V_223 -> V_224 ) ;
if ( V_156 != NULL ) {
F_19 ( V_47 , V_121 , ( L_36 ) ) ;
return;
}
V_156 = F_93 ( & V_1 -> V_151 , V_223 -> V_224 ) ;
if ( V_156 == NULL ) {
F_19 ( V_47 , V_121 , ( L_37 ) ) ;
return;
}
V_156 -> V_225 = 0 ;
V_156 -> V_175 = ( T_5 ) V_223 -> V_226 ;
F_52 ( L_22 , V_174 ) ;
F_94 ( V_1 , V_176 , V_156 , true ) ;
F_106 ( V_1 , V_156 ) ;
if ( V_1 -> V_84 . V_177 == V_178 )
V_156 -> V_183 = V_1 -> V_84 . V_85 ;
V_156 -> V_182 = false ;
F_16 ( & V_8 -> V_21 ) ;
if ( ( F_22 ( V_8 , V_60 ) ) ||
( F_22 ( V_8 , V_61 ) ) ) {
if ( V_1 -> V_151 . V_158 == 2 ) {
F_16 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_197 = F_25 ( & V_8 -> V_23 , V_15 -> V_16 . V_70 ) ;
if ( V_197 )
V_197 -> V_50 = true ;
F_20 ( & V_8 -> V_23 . V_21 ) ;
F_66 ( V_1 ) ;
}
}
F_20 ( & V_8 -> V_21 ) ;
F_111 ( V_1 , V_156 ) ;
}
void F_112 ( struct V_1 * V_1 , T_1 * V_4 )
{
int V_175 = - 1 ;
struct V_155 * V_156 ;
struct V_5 * V_100 = NULL ;
struct V_77 * V_142 = NULL ;
T_1 * V_74 = NULL ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_227 * V_228 = (struct V_227 * ) V_4 ;
struct V_149 * V_150 = & V_1 -> V_151 ;
struct V_5 * V_152 = & ( V_8 -> V_15 ) ;
V_156 = F_76 ( & V_1 -> V_151 , V_228 -> V_224 ) ;
if ( V_156 )
V_175 = V_156 -> V_175 ;
else
V_175 = V_228 -> V_175 ;
F_52 ( L_38 , V_174 , V_175 , V_228 -> V_224 ) ;
if ( V_175 >= 0 ) {
T_3 V_218 ;
V_218 = ( V_175 << 8 ) | 0 ;
F_107 ( V_1 , V_221 , ( T_1 * ) & V_218 ) ;
}
if ( F_22 ( V_8 , V_154 ) )
return;
F_113 ( V_1 ) ;
F_16 ( & V_8 -> V_21 ) ;
if ( F_22 ( V_8 , V_153 ) ) {
if ( V_8 -> V_145 > 0 )
V_8 -> V_145 -- ;
else if ( V_8 -> V_145 == 0 )
V_8 -> V_145 = V_1 -> V_131 . V_229 ;
if ( * ( ( unsigned short * ) ( V_228 -> V_230 ) ) != V_231 )
V_8 -> V_145 = 0 ;
F_114 ( V_1 ) ;
F_68 ( V_1 ) ;
F_69 ( V_1 ) ;
F_16 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_100 = F_25 ( & V_8 -> V_23 , V_152 -> V_16 . V_70 ) ;
if ( V_100 ) {
V_100 -> V_50 = false ;
F_35 ( V_8 , V_100 ) ;
}
F_20 ( & V_8 -> V_23 . V_21 ) ;
F_115 ( V_1 , V_152 ) ;
}
if ( F_22 ( V_8 , V_60 ) ||
F_22 ( V_8 , V_61 ) ) {
F_16 ( & ( V_150 -> V_157 ) ) ;
F_77 ( V_1 , V_156 ) ;
F_20 ( & V_150 -> V_157 ) ;
if ( V_1 -> V_151 . V_158 == 1 ) {
F_16 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_100 = F_25 ( & V_8 -> V_23 , V_152 -> V_16 . V_70 ) ;
if ( V_100 ) {
V_100 -> V_50 = false ;
F_35 ( V_8 , V_100 ) ;
}
F_20 ( & V_8 -> V_23 . V_21 ) ;
V_142 = & ( V_1 -> V_131 . V_143 ) ;
V_74 = V_1 -> V_131 . V_143 . V_70 ;
memcpy ( V_142 , & V_152 -> V_16 , F_43 ( & V_152 -> V_16 ) ) ;
memcpy ( & V_142 -> V_90 , & V_8 -> V_24 , sizeof( struct V_25 ) ) ;
F_64 ( V_1 ) ;
F_29 ( V_74 ) ;
if ( F_22 ( V_8 , V_61 ) ) {
F_60 ( V_8 , V_60 ) ;
F_58 ( V_8 , V_61 ) ;
}
if ( F_65 ( V_1 ) != V_11 )
F_19 ( V_232 , V_121 , ( L_39 ) ) ;
}
}
F_20 ( & V_8 -> V_21 ) ;
}
void F_116 ( struct V_1 * V_2 , T_1 * V_4 )
{
F_19 ( V_47 , V_121 , ( L_40 ) ) ;
}
void F_117 ( unsigned long V_233 )
{
struct V_1 * V_1 = (struct V_1 * ) V_233 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
int V_234 ;
F_52 ( L_41 , V_174 , F_56 ( V_8 ) ) ;
if ( V_1 -> V_71 || V_1 -> V_72 )
return;
F_16 ( & V_8 -> V_21 ) ;
if ( V_8 -> V_145 > 0 ) {
while ( 1 ) {
V_8 -> V_145 -- ;
if ( V_8 -> V_145 != 0 ) {
F_52 ( L_42 , V_174 ) ;
V_234 = F_118 ( V_1 ) ;
if ( V_11 != V_234 ) {
F_52 ( L_43 , V_174 , V_234 ) ;
continue;
}
break;
} else {
F_52 ( L_44 , V_174 ) ;
F_69 ( V_1 ) ;
break;
}
}
} else {
F_69 ( V_1 ) ;
F_74 ( V_8 ) ;
}
F_20 ( & V_8 -> V_21 ) ;
}
void F_119 ( unsigned long V_233 )
{
struct V_1 * V_1 = (struct V_1 * ) V_233 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
F_52 ( V_235 L_45 , F_120 ( V_1 ) , F_56 ( V_8 ) ) ;
F_16 ( & V_8 -> V_21 ) ;
F_58 ( V_8 , V_137 ) ;
F_20 ( & V_8 -> V_21 ) ;
F_86 ( V_1 , true ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( V_8 -> V_236 > 0 ) {
V_8 -> V_236 -- ;
if ( V_8 -> V_236 == 0 ) {
F_52 ( L_22 , V_174 ) ;
F_122 ( V_2 , NULL , 0 ) ;
V_8 -> V_236 = V_237 ;
}
}
}
void F_123 ( unsigned long V_233 )
{
struct V_1 * V_1 = (struct V_1 * ) V_233 ;
struct V_238 * V_239 = & V_1 -> V_131 ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_240 )
goto exit;
if ( ( V_1 -> V_71 ) || ( V_1 -> V_72 ) )
goto exit;
if ( V_1 -> V_241 )
goto exit;
F_124 ( V_1 ) ;
if ( V_239 -> V_132 == 1 ) {
F_121 ( V_1 ) ;
}
exit:
F_62 ( & V_1 -> V_9 . V_242 ,
V_52 + F_63 ( 2000 ) ) ;
}
static int F_125 ( struct V_7 * V_8
, struct V_5 * * V_243 , struct V_5 * V_244 )
{
int V_245 = false ;
unsigned long V_246 ;
struct V_1 * V_1 = F_26 ( V_8 , struct V_1 , V_9 ) ;
if ( V_8 -> V_247 ) {
if ( memcmp ( V_244 -> V_16 . V_70 , V_8 -> V_248 , V_68 ) )
goto exit;
}
if ( V_8 -> V_24 . V_91 ) {
if ( V_244 -> V_16 . V_90 . V_91 != V_8 -> V_24 . V_91 ||
! memcmp ( V_244 -> V_16 . V_90 . V_90 , V_8 -> V_24 . V_90 , V_8 -> V_24 . V_91 ) == false )
goto exit;
}
if ( F_50 ( V_1 , V_244 ) == false )
goto exit;
if ( V_8 -> V_145 ) {
V_246 = V_52 - V_244 -> V_51 ;
if ( F_89 ( V_246 ) >= V_249 ||
F_37 ( & V_244 -> V_16 , & V_8 -> V_15 . V_16 ) == false )
goto exit;
}
if ( * V_243 == NULL || ( * V_243 ) -> V_16 . V_104 < V_244 -> V_16 . V_104 ) {
* V_243 = V_244 ;
V_245 = true ;
}
if ( V_245 ) {
F_52 ( L_46 ,
V_8 -> V_247 ,
V_8 -> V_24 . V_90 ,
( * V_243 ) -> V_16 . V_90 . V_90 ,
( * V_243 ) -> V_16 . V_70 ,
( int ) ( * V_243 ) -> V_16 . V_104 ) ;
F_52 ( L_47 , V_8 -> V_145 ) ;
}
exit:
return V_245 ;
}
int F_61 ( struct V_7 * V_8 )
{
int V_81 ;
struct V_64 * V_65 ;
struct V_1 * V_1 ;
struct V_45 * V_30 = & ( V_8 -> V_23 ) ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_243 = NULL ;
T_1 V_250 = false ;
F_16 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_65 = F_24 ( V_30 ) ;
V_1 = (struct V_1 * ) V_8 -> V_12 ;
V_8 -> V_13 = V_65 -> V_69 ;
while ( V_65 != V_8 -> V_13 ) {
V_6 = F_26 ( V_8 -> V_13 , struct V_5 , V_29 ) ;
if ( V_6 == NULL ) {
F_19 ( V_47 , V_121 , ( L_48 , V_174 ) ) ;
V_81 = V_27 ;
goto exit;
}
V_8 -> V_13 = V_8 -> V_13 -> V_69 ;
F_125 ( V_8 , & V_243 , V_6 ) ;
}
if ( V_243 == NULL ) {
F_52 ( L_49 , V_174 ) ;
V_81 = V_27 ;
goto exit;
} else {
F_52 ( L_50 , V_174 ,
V_243 -> V_16 . V_90 . V_90 , V_243 -> V_16 . V_70 ,
V_243 -> V_16 . V_251 . V_252 ) ;
}
if ( F_22 ( V_8 , V_73 ) == true ) {
F_52 ( L_51 , V_174 ) ;
F_126 ( V_1 , 0 , true ) ;
F_69 ( V_1 ) ;
F_75 ( V_1 ) ;
}
F_48 ( V_1 , V_253 , & ( V_250 ) ) ;
if ( V_250 ) {
T_1 V_254 ;
F_48 ( V_1 , V_119 , & ( V_254 ) ) ;
F_52 ( L_52 ,
( 2 == V_243 -> V_16 . V_106 . V_120 ) ? L_53 : L_54 ,
( 2 == V_254 ) ? L_53 : L_54
) ;
}
V_81 = F_127 ( V_1 , V_243 ) ;
exit:
F_20 ( & V_8 -> V_23 . V_21 ) ;
return V_81 ;
}
int F_128 ( struct V_1 * V_1 , struct V_82 * V_83 )
{
struct V_255 * V_256 ;
struct V_257 * V_258 ;
struct V_259 * V_260 = & ( V_1 -> V_261 ) ;
int V_10 = V_11 ;
V_256 = F_129 ( sizeof( struct V_255 ) , V_262 ) ;
if ( ! V_256 ) {
V_10 = V_27 ;
goto exit;
}
V_258 = F_129 ( sizeof( struct V_257 ) , V_262 ) ;
if ( ! V_258 ) {
F_10 ( V_256 ) ;
V_10 = V_27 ;
goto exit;
}
memset ( V_258 , 0 , sizeof( struct V_257 ) ) ;
V_258 -> V_263 = ( unsigned char ) V_83 -> V_177 ;
V_256 -> V_264 = V_265 ;
V_256 -> V_266 = ( unsigned char * ) V_258 ;
V_256 -> V_267 = ( sizeof( struct V_257 ) ) ;
V_256 -> V_268 = NULL ;
V_256 -> V_269 = 0 ;
F_5 ( & V_256 -> V_29 ) ;
F_19 ( V_47 , V_121 ,
( L_55 ,
V_83 -> V_177 ) ) ;
V_10 = F_130 ( V_260 , V_256 ) ;
exit:
return V_10 ;
}
int F_131 ( struct V_1 * V_1 , struct V_82 * V_83 , int V_270 , T_1 V_271 )
{
T_1 V_272 ;
struct V_255 * V_256 ;
struct V_273 * V_274 ;
struct V_259 * V_260 = & ( V_1 -> V_261 ) ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
int V_10 = V_11 ;
V_256 = F_129 ( sizeof( struct V_255 ) , V_262 ) ;
if ( ! V_256 )
return V_27 ;
V_274 = F_129 ( sizeof( struct V_273 ) , V_262 ) ;
if ( ! V_274 ) {
V_10 = V_27 ;
goto V_275;
}
memset ( V_274 , 0 , sizeof( struct V_273 ) ) ;
if ( V_83 -> V_177 == V_178 ) {
V_274 -> V_276 = ( unsigned char ) V_83 -> V_277 ;
F_19 ( V_47 , V_121 ,
( L_56 ,
V_274 -> V_276 ) ) ;
} else {
V_274 -> V_276 = ( T_1 ) V_83 -> V_85 ;
F_19 ( V_47 , V_121 ,
( L_57 ,
V_274 -> V_276 ) ) ;
}
V_274 -> V_270 = ( T_1 ) V_270 ;
V_274 -> V_271 = V_271 ;
V_8 -> V_159 |= F_132 ( V_274 -> V_270 ) ;
F_52 ( L_58 ,
V_274 -> V_276 , V_274 -> V_270 , V_8 -> V_159 ) ;
F_19 ( V_47 , V_121 ,
( L_59 ,
V_274 -> V_276 , V_270 ) ) ;
switch ( V_274 -> V_276 ) {
case V_278 :
V_272 = 5 ;
memcpy ( & ( V_274 -> V_279 [ 0 ] ) , & ( V_83 -> V_280 [ V_270 ] . V_281 [ 0 ] ) , V_272 ) ;
break;
case V_282 :
V_272 = 13 ;
memcpy ( & ( V_274 -> V_279 [ 0 ] ) , & ( V_83 -> V_280 [ V_270 ] . V_281 [ 0 ] ) , V_272 ) ;
break;
case V_283 :
V_272 = 16 ;
memcpy ( & V_274 -> V_279 , & V_83 -> V_284 [ V_270 ] , V_272 ) ;
V_274 -> V_285 = 1 ;
break;
case V_286 :
V_272 = 16 ;
memcpy ( & V_274 -> V_279 , & V_83 -> V_284 [ V_270 ] , V_272 ) ;
V_274 -> V_285 = 1 ;
break;
default:
F_19 ( V_47 , V_121 ,
( L_60 ,
V_83 -> V_85 ) ) ;
V_10 = V_27 ;
goto V_287;
}
V_256 -> V_264 = V_288 ;
V_256 -> V_266 = ( T_1 * ) V_274 ;
V_256 -> V_267 = ( sizeof( struct V_273 ) ) ;
V_256 -> V_268 = NULL ;
V_256 -> V_269 = 0 ;
F_5 ( & V_256 -> V_29 ) ;
V_10 = F_130 ( V_260 , V_256 ) ;
return V_10 ;
V_287:
F_10 ( V_274 ) ;
V_275:
F_10 ( V_256 ) ;
return V_10 ;
}
int F_133 ( struct V_1 * V_1 , T_1 * V_289 , T_1 * V_290 , T_5 V_291 , T_5 V_292 )
{
unsigned int V_293 = 0 ;
unsigned int V_3 , V_294 ;
for ( V_3 = 12 ; V_3 < V_291 ; V_3 += ( V_289 [ V_3 + 1 ] + 2 ) ) {
V_293 = V_292 ;
if ( V_289 [ V_3 ] == 0xDD && V_289 [ V_3 + 2 ] == 0x00 && V_289 [ V_3 + 3 ] == 0x50 && V_289 [ V_3 + 4 ] == 0xF2 && V_289 [ V_3 + 5 ] == 0x02 && V_3 + 5 < V_291 ) {
for ( V_294 = V_3 ; V_294 < V_3 + 9 ; V_294 ++ ) {
V_290 [ V_293 ] = V_289 [ V_294 ] ;
V_293 ++ ;
}
V_290 [ V_292 + 1 ] = 0x07 ;
V_290 [ V_292 + 6 ] = 0x00 ;
V_290 [ V_292 + 8 ] = 0x00 ;
break;
}
}
return V_293 ;
}
static int F_134 ( struct V_1 * V_295 , T_1 * V_296 )
{
struct V_82 * V_83 = & V_295 -> V_84 ;
int V_3 = 0 ;
do {
if ( ( V_83 -> V_297 [ V_3 ] . V_298 ) &&
( ! memcmp ( V_83 -> V_297 [ V_3 ] . V_299 , V_296 , V_68 ) ) ) {
break;
} else {
V_3 ++ ;
}
} while ( V_3 < V_300 );
if ( V_3 == V_300 )
V_3 = - 1 ;
return V_3 ;
}
static int F_135 ( struct V_1 * V_295 , int V_301 , T_1 * V_76 , T_5 V_302 )
{
struct V_82 * V_83 = & V_295 -> V_84 ;
if ( V_76 [ 13 ] <= 20 ) {
V_76 [ V_302 ] = 1 ;
V_302 ++ ;
V_76 [ V_302 ] = 0 ;
V_302 ++ ;
memcpy ( & V_76 [ V_302 ] , & V_83 -> V_297 [ V_301 ] . V_303 , 16 ) ;
V_302 += 16 ;
V_76 [ 13 ] += 18 ;
}
return V_302 ;
}
int F_136 ( struct V_1 * V_1 , T_1 * V_289 , T_1 * V_290 , T_5 V_291 )
{
T_1 V_304 ;
T_5 V_293 ;
int V_301 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
struct V_82 * V_83 = & V_1 -> V_84 ;
T_5 V_305 = V_83 -> V_306 ;
T_5 V_307 = V_83 -> V_128 ;
F_19 ( V_47 , V_148 ,
( L_61 ,
V_305 , V_307 ) ) ;
memcpy ( V_290 , V_289 , 12 ) ;
V_293 = 12 ;
if ( ( V_305 == V_308 ) ||
( V_305 == V_309 ) )
V_304 = V_310 ;
if ( ( V_305 == V_311 ) ||
( V_305 == V_312 ) )
V_304 = V_313 ;
if ( F_22 ( V_8 , V_129 ) ) {
memcpy ( V_290 + V_293 , V_83 -> V_314 , V_83 -> V_191 ) ;
V_293 += V_83 -> V_191 ;
} else if ( ( V_304 == V_310 ) || ( V_304 == V_313 ) ) {
memcpy ( & V_290 [ V_293 ] , & V_83 -> V_315 [ 0 ] , V_83 -> V_315 [ 1 ] + 2 ) ;
V_293 += V_83 -> V_315 [ 1 ] + 2 ;
F_137 ( V_1 , V_304 , V_83 -> V_315 ) ;
}
V_301 = F_134 ( V_1 , V_8 -> V_248 ) ;
if ( V_301 < 0 ) {
return V_293 ;
} else {
if ( V_304 == V_313 )
V_293 = F_135 ( V_1 , V_301 , V_290 , V_293 ) ;
}
return V_293 ;
}
void F_138 ( struct V_1 * V_1 )
{
struct V_238 * V_239 = & V_1 -> V_131 ;
struct V_316 * V_317 = & V_1 -> V_318 ;
struct V_77 * V_142 = & V_239 -> V_143 ;
T_1 * V_319 = F_139 ( V_317 ) ;
memcpy ( V_142 -> V_70 , V_319 , V_68 ) ;
memcpy ( & V_142 -> V_90 , & V_239 -> V_320 , sizeof( struct V_25 ) ) ;
V_142 -> V_251 . V_122 = sizeof( struct V_321 ) ;
V_142 -> V_251 . V_322 = 100 ;
V_142 -> V_251 . V_323 . V_122 = 0 ;
V_142 -> V_251 . V_323 . V_324 = 0 ;
V_142 -> V_251 . V_323 . V_325 = 0 ;
V_142 -> V_251 . V_323 . V_326 = 0 ;
}
void F_64 ( struct V_1 * V_1 )
{
int V_327 = 0 ;
struct V_238 * V_239 = & V_1 -> V_131 ;
struct V_77 * V_142 = & V_239 -> V_143 ;
struct V_82 * V_83 = & V_1 -> V_84 ;
struct V_5 * V_15 = & V_1 -> V_9 . V_15 ;
V_142 -> V_87 = ( V_83 -> V_85 > 0 ? 1 : 0 ) ;
V_142 -> V_104 = 0 ;
switch ( V_239 -> V_328 ) {
case V_329 :
V_142 -> V_330 = ( V_331 ) ;
break;
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
V_142 -> V_330 = ( V_337 ) ;
break;
case V_338 :
case V_339 :
V_142 -> V_330 = ( V_340 ) ;
break;
case V_341 :
if ( V_239 -> V_342 > 14 )
V_142 -> V_330 = ( V_340 ) ;
else
V_142 -> V_330 = ( V_337 ) ;
break;
default:
break;
}
V_142 -> V_251 . V_252 = ( V_239 -> V_342 ) ;
F_19 ( V_47 , V_48 ,
( L_62 ,
V_239 -> V_342 , V_142 -> V_251 . V_252 ) ) ;
if ( V_15 -> V_16 . V_17 == V_201 )
V_142 -> V_251 . V_343 = ( 0 ) ;
V_142 -> V_17 = ( V_15 -> V_16 . V_17 ) ;
V_327 = F_140 ( V_239 ) ;
V_142 -> V_116 = V_327 ;
V_142 -> V_122 = F_43 ( (struct V_77 * ) V_142 ) ;
}
void F_100 ( struct V_1 * V_1 )
{
}
void F_141 ( struct V_1 * V_2 )
{
T_1 V_344 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_345 * V_346 = & V_8 -> V_347 ;
V_8 -> V_348 = 0 ;
V_8 -> V_349 = 0 ;
V_346 -> V_350 = false ;
if ( V_346 -> V_351 ) {
if ( V_2 -> V_131 . V_132 == 1 )
V_344 = 1 ;
else
V_344 = 0 ;
F_107 ( V_2 , V_352 , ( T_1 * ) ( & V_344 ) ) ;
} else {
V_344 = 1 ;
F_107 ( V_2 , V_352 , ( T_1 * ) ( & V_344 ) ) ;
}
}
unsigned int F_142 ( struct V_1 * V_2 , T_1 * V_289 , T_1 * V_290 , T_5 V_291 , T_5 * V_353 )
{
T_2 V_354 , V_355 ;
enum V_356 V_357 ;
unsigned char * V_358 ;
unsigned char V_359 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_360 * V_361 = & V_8 -> V_362 ;
struct V_345 * V_346 = & V_8 -> V_347 ;
T_2 V_363 , V_364 ;
V_346 -> V_351 = false ;
V_358 = F_143 ( V_289 + 12 , V_365 , & V_354 , V_291 - 12 ) ;
if ( V_358 && V_354 > 0 ) {
struct V_366 V_367 ;
if ( V_361 -> V_225 == 0 ) {
V_355 = * V_353 ;
F_144 ( V_290 + V_355 , V_368 ,
V_369 , V_359 , V_353 ) ;
V_361 -> V_225 = 1 ;
}
V_355 = * V_353 ;
memset ( & V_367 , 0 , sizeof( struct V_366 ) ) ;
V_367 . V_370 = F_145 ( V_371 |
V_372 |
V_373 |
V_374 |
V_375 ) ;
F_48 ( V_2 , V_376 , & V_363 ) ;
F_48 ( V_2 , V_377 , & V_364 ) ;
F_48 ( V_2 , V_378 , & V_357 ) ;
V_367 . V_379 = V_357 & 0x03 ;
if ( V_2 -> V_84 . V_85 == V_286 )
V_367 . V_379 |= V_380 & ( 0x07 << 2 ) ;
else
V_367 . V_379 |= V_380 & 0x00 ;
F_144 ( V_290 + V_355 , V_365 ,
sizeof( struct V_366 ) ,
( unsigned char * ) & V_367 , V_353 ) ;
V_346 -> V_351 = true ;
V_358 = F_143 ( V_289 + 12 , V_381 , & V_354 , V_291 - 12 ) ;
if ( V_358 && ( V_354 == sizeof( struct V_382 ) ) ) {
V_355 = * V_353 ;
F_144 ( V_290 + V_355 , V_381 , V_354 , V_358 + 2 , V_353 ) ;
}
}
return V_346 -> V_351 ;
}
void F_98 ( struct V_1 * V_2 , T_1 * V_383 , T_5 V_302 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_345 * V_346 = & V_8 -> V_347 ;
struct V_238 * V_239 = & V_2 -> V_131 ;
struct V_165 * V_166 = & V_2 -> V_167 ;
struct V_209 * V_210 = & ( V_166 -> V_211 ) ;
if ( ! V_346 -> V_351 )
return;
if ( ( ! V_210 -> V_384 ) || ( ! V_210 -> V_385 ) )
return;
F_52 ( L_63 ) ;
if ( ( ! V_346 -> V_350 ) && ( V_239 -> V_350 == 1 ) ) {
if ( V_239 -> V_132 == 1 )
V_346 -> V_350 = false ;
else
V_346 -> V_350 = true ;
} else if ( V_239 -> V_350 == 2 ) {
V_346 -> V_350 = true ;
}
if ( ( V_239 -> V_386 ) &&
( F_32 ( V_210 -> V_387 . V_370 ) & F_132 ( 1 ) ) &&
( V_210 -> V_388 . V_389 [ 0 ] & F_132 ( 2 ) ) ) {
int V_3 ;
T_1 V_390 ;
F_146 ( V_2 , V_391 , ( T_1 * ) ( & V_390 ) ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( V_390 == V_392 ) || ( V_390 == V_393 ) )
( ( T_1 * ) & V_210 -> V_387 . V_394 ) [ V_3 ] &= V_395 [ V_3 ] ;
else
( ( T_1 * ) & V_210 -> V_387 . V_394 ) [ V_3 ] &= V_396 [ V_3 ] ;
}
V_166 -> V_397 = V_398 ;
switch ( ( V_210 -> V_388 . V_389 [ 0 ] & 0x3 ) ) {
case V_399 :
V_166 -> V_400 = V_401 ;
break;
case V_402 :
V_166 -> V_400 = V_403 ;
break;
default:
V_166 -> V_400 = V_404 ;
break;
}
}
V_210 -> V_405 = ( F_32 ( V_210 -> V_387 . V_370 ) & 0x0C ) >> 2 ;
if ( V_210 -> V_405 == V_406 )
F_52 ( L_64 , V_174 ) ;
V_210 -> V_407 = V_210 -> V_388 . V_389 [ 1 ] & 0x3 ;
}
void F_147 ( struct V_1 * V_2 , struct V_408 * V_409 )
{
T_1 V_410 ;
int V_411 ;
struct V_155 * V_156 = NULL ;
struct V_345 * V_346 ;
struct V_412 * V_413 = & V_409 -> V_414 ;
T_6 V_415 = F_148 ( V_413 -> V_416 ) ;
if ( V_415 || ( V_2 -> V_9 . V_417 . V_418 < 100 ) )
return;
V_411 = V_413 -> V_411 ;
if ( V_413 -> V_156 )
V_156 = V_413 -> V_156 ;
else
V_156 = F_76 ( & V_2 -> V_151 , V_413 -> V_416 ) ;
if ( V_156 == NULL )
return;
V_346 = & V_156 -> V_347 ;
if ( ( V_346 -> V_351 ) && ( V_346 -> V_350 ) ) {
V_410 = ( V_346 -> V_419 >> V_411 ) & 0x1 ;
V_410 |= ( V_346 -> V_420 >> V_411 ) & 0x1 ;
if ( 0 == V_410 ) {
F_52 ( L_65 , V_411 ) ;
V_156 -> V_347 . V_420 |= F_132 ( ( T_1 ) V_411 ) ;
F_149 ( V_2 , ( T_1 ) V_411 , V_413 -> V_416 ) ;
}
}
}
void F_150 ( struct V_1 * V_2 , struct V_5 * V_152 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
F_16 ( & V_8 -> V_21 ) ;
F_115 ( V_2 , V_152 ) ;
F_20 ( & V_8 -> V_21 ) ;
}
void F_115 ( struct V_1 * V_2 , struct V_5 * V_152 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
int V_234 ;
struct V_5 * V_6 ;
if ( V_152 != NULL )
V_6 = V_152 ;
else
V_6 = & V_8 -> V_15 ;
if ( 0 < V_8 -> V_145 ) {
F_52 ( L_66 ,
V_6 -> V_16 . V_90 . V_90 , V_6 -> V_16 . V_70 ,
V_6 -> V_16 . V_90 . V_91 ) ;
memcpy ( & V_8 -> V_24 , & V_6 -> V_16 . V_90 , sizeof( struct V_25 ) ) ;
V_8 -> V_247 = false ;
while ( 1 ) {
V_234 = F_118 ( V_2 ) ;
if ( V_11 == V_234 ) {
break;
} else {
F_52 ( L_67 , V_234 ) ;
V_8 -> V_145 -- ;
if ( 0 < V_8 -> V_145 ) {
continue;
} else {
F_52 ( L_68 , V_174 , __LINE__ ) ;
F_69 ( V_2 ) ;
break;
}
}
}
}
}
