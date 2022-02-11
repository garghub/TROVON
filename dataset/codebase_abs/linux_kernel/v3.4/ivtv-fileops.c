static int F_1 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ type ] ;
struct V_5 * V_8 ;
int V_9 ;
if ( F_2 ( V_10 , & V_6 -> V_11 ) ) {
if ( V_6 -> V_12 == & V_2 -> V_12 ) {
return 0 ;
}
if ( V_6 -> V_12 == NULL && ( type == V_13 ||
type == V_14 ) ) {
V_6 -> V_12 = & V_2 -> V_12 ;
F_3 ( L_1 ) ;
return 0 ;
}
F_3 ( L_2 , type ) ;
return - V_15 ;
}
V_6 -> V_12 = & V_2 -> V_12 ;
if ( type == V_13 ) {
F_4 ( V_4 , V_16 ) ;
}
if ( type == V_17 ) {
V_9 = V_13 ;
} else if ( type == V_18 &&
V_4 -> V_19 . V_20 && ! F_5 ( V_4 ) ) {
V_9 = V_14 ;
} else {
return 0 ;
}
V_8 = & V_4 -> V_7 [ V_9 ] ;
if ( ! F_2 ( V_10 , & V_8 -> V_11 ) ) {
if ( V_9 == V_13 )
F_4 ( V_4 , V_16 ) ;
}
F_6 ( V_21 , & V_8 -> V_11 ) ;
return 0 ;
}
void F_7 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_5 * V_8 ;
V_6 -> V_12 = NULL ;
if ( ( V_6 -> type == V_13 || V_6 -> type == V_14 ) &&
F_8 ( V_21 , & V_6 -> V_11 ) ) {
return;
}
if ( ! F_9 ( V_10 , & V_6 -> V_11 ) ) {
F_10 ( L_3 , V_6 -> V_22 ) ;
return;
}
F_11 ( V_6 ) ;
if ( V_6 -> type == V_13 )
F_12 ( V_4 , V_16 ) ;
if ( V_6 -> type == V_17 )
V_8 = & V_4 -> V_7 [ V_13 ] ;
else if ( V_6 -> type == V_18 )
V_8 = & V_4 -> V_7 [ V_14 ] ;
else
return;
if ( ! F_9 ( V_21 , & V_8 -> V_11 ) ) {
return;
}
if ( V_8 -> V_12 ) {
return;
}
if ( V_8 -> type == V_13 )
F_12 ( V_4 , V_16 ) ;
F_13 ( V_10 , & V_8 -> V_11 ) ;
F_11 ( V_8 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_23 V_24 ;
T_1 V_25 ;
const T_1 V_26 = 0x02 ;
V_25 = F_15 ( V_4 -> V_27 . V_28 ) ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
F_16 ( V_4 , V_29 , V_30 , & V_24 ) ;
if ( V_24 . V_31 == V_32 && ( V_24 . V_33 & V_34 ) )
V_25 = V_26 ;
if ( V_25 == V_4 -> V_35 )
return;
F_3 ( L_4 ,
V_4 -> V_35 , V_25 ) ;
if ( F_17 ( V_4 -> V_27 . V_28 , V_25 ) )
F_3 ( L_5 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
T_1 V_36 = ( F_19 ( V_4 -> V_37 ) - V_4 -> V_37 - 4 ) / 24 ;
int V_38 ;
int V_39 = 0 ;
if ( V_36 >= V_4 -> V_40 ) {
F_10 ( L_6 , V_36 , V_4 -> V_40 ) ;
return;
}
V_38 = ( V_36 + V_4 -> V_40 - V_4 -> V_41 ) % V_4 -> V_40 ;
while ( V_39 < V_38 ) {
int V_42 = ( V_4 -> V_41 + V_39 ) % V_4 -> V_40 ;
struct V_43 * V_44 = V_4 -> V_45 + V_42 ;
T_1 V_46 = V_4 -> V_37 + 4 + V_42 * 24 ;
const int V_47 [ 8 ] = { - 1 , V_48 , V_49 , - 1 ,
V_50 , - 1 , - 1 , - 1 } ;
V_44 -> V_51 = F_19 ( V_46 + 4 ) + ( ( V_52 ) F_19 ( V_46 + 8 ) << 32 ) ;
if ( V_44 -> V_51 > V_4 -> V_53 ) {
break;
}
V_44 -> V_51 += V_4 -> V_54 ;
V_44 -> V_55 = F_19 ( V_46 ) ;
V_44 -> V_56 = F_19 ( V_46 + 16 ) + ( ( V_52 ) ( F_19 ( V_46 + 20 ) & 1 ) << 32 ) ;
V_44 -> V_57 = V_47 [ F_19 ( V_46 + 12 ) & 7 ] ;
V_39 ++ ;
}
V_4 -> V_41 = ( V_4 -> V_41 + V_39 ) % V_4 -> V_40 ;
}
static struct V_58 * F_20 ( struct V_5 * V_6 , int V_59 , int * V_60 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_5 * V_8 = & V_4 -> V_7 [ V_14 ] ;
struct V_58 * V_61 ;
F_21 ( V_62 ) ;
* V_60 = 0 ;
while ( 1 ) {
if ( V_6 -> type == V_18 ) {
F_18 ( V_4 ) ;
if ( F_22 ( V_63 ,
V_4 -> V_64 +
F_23 ( 1000 ) ) ) {
V_4 -> V_64 = V_63 ;
F_14 ( V_4 ) ;
}
if ( F_8 ( V_21 , & V_8 -> V_11 ) &&
! F_8 ( V_65 , & V_8 -> V_11 ) ) {
while ( ( V_61 = F_24 ( V_8 , & V_8 -> V_66 ) ) ) {
F_25 ( V_4 , V_61 , V_8 -> V_67 , V_8 -> type ) ;
F_26 ( V_8 , V_61 , & V_8 -> V_68 ) ;
}
}
V_61 = & V_4 -> V_19 . V_69 ;
if ( V_61 -> V_70 != V_61 -> V_71 ) {
return V_61 ;
}
}
V_61 = F_24 ( V_6 , & V_6 -> V_72 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_24 ( V_6 , & V_6 -> V_66 ) ;
if ( V_61 ) {
if ( ( V_61 -> V_73 & V_74 ) == 0 )
return V_61 ;
V_61 -> V_73 &= ~ V_74 ;
if ( V_6 -> type == V_18 )
F_27 ( V_61 ) ;
else if ( V_6 -> type != V_13 ) {
F_25 ( V_4 , V_61 , V_6 -> V_67 , V_6 -> type ) ;
}
return V_61 ;
}
if ( V_6 -> type != V_13 && ! F_8 ( V_75 , & V_6 -> V_11 ) ) {
F_3 ( L_7 , V_6 -> V_22 ) ;
return NULL ;
}
if ( V_59 ) {
* V_60 = - V_76 ;
return NULL ;
}
F_28 ( & V_4 -> V_77 ) ;
F_29 ( & V_6 -> V_78 , & V_62 , V_79 ) ;
if ( ! V_6 -> V_66 . V_80 )
F_30 () ;
F_31 ( & V_6 -> V_78 , & V_62 ) ;
F_32 ( & V_4 -> V_77 ) ;
if ( F_33 ( V_81 ) ) {
F_3 ( L_8 , V_6 -> V_22 ) ;
* V_60 = - V_82 ;
return NULL ;
}
}
}
static void F_34 ( struct V_3 * V_4 )
{
int V_42 = V_4 -> V_19 . V_83 % V_84 ;
V_4 -> V_19 . V_69 . V_61 = V_4 -> V_19 . V_85 [ V_42 ] ;
V_4 -> V_19 . V_69 . V_71 = V_4 -> V_19 . V_86 [ V_42 ] ;
V_4 -> V_19 . V_69 . V_70 = 0 ;
}
static T_2 F_35 ( struct V_5 * V_6 , struct V_58 * V_61 ,
char T_3 * V_87 , T_2 V_88 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_89 = V_61 -> V_71 - V_61 -> V_70 ;
if ( V_89 > V_88 ) V_89 = V_88 ;
if ( V_4 -> V_19 . V_20 && V_6 -> type == V_18 &&
! F_5 ( V_4 ) && V_61 != & V_4 -> V_19 . V_69 ) {
const char * V_90 = V_61 -> V_61 + V_61 -> V_70 ;
const char * V_91 = V_90 + 1 ;
const T_4 * V_92 ;
T_4 V_93 = V_4 -> V_94 ? 0xba : 0xe0 ;
int V_95 , V_39 ;
while ( V_90 + V_89 > V_91 && ( V_92 = memchr ( V_91 , 0 , V_90 + V_89 - V_91 ) ) ) {
V_91 = V_92 + 1 ;
if ( ( char * ) V_92 + 15 >= V_61 -> V_61 + V_61 -> V_71 ||
V_92 [ 1 ] != 0 || V_92 [ 2 ] != 1 || V_92 [ 3 ] != V_93 ) {
continue;
}
if ( ! V_4 -> V_94 ) {
if ( ( V_92 [ 6 ] & 0xc0 ) != 0x80 )
continue;
if ( ( ( V_92 [ 7 ] & 0xc0 ) == 0x80 && ( V_92 [ 9 ] & 0xf0 ) == 0x20 ) ||
( ( V_92 [ 7 ] & 0xc0 ) == 0xc0 && ( V_92 [ 9 ] & 0xf0 ) == 0x30 ) ) {
V_93 = 0xba ;
V_4 -> V_94 = 1 ;
V_91 = V_92 + 9 ;
}
continue;
}
V_95 = V_92 [ 13 ] & 7 ;
for ( V_39 = 0 ; V_39 < V_95 ; V_39 ++ )
if ( V_92 [ 14 + V_39 ] != 0xff )
break;
if ( V_39 == V_95 && ( V_92 [ 4 ] & 0xc4 ) == 0x44 && ( V_92 [ 12 ] & 3 ) == 3 &&
V_92 [ 14 + V_95 ] == 0 && V_92 [ 15 + V_95 ] == 0 &&
V_92 [ 16 + V_95 ] == 1 ) {
V_4 -> V_94 = 0 ;
V_89 = ( char * ) V_92 - V_90 ;
F_34 ( V_4 ) ;
break;
}
}
}
if ( F_36 ( V_87 , ( T_4 * ) V_61 -> V_61 + V_61 -> V_70 , V_89 ) ) {
F_10 ( L_9 , V_89 , V_6 -> V_22 ) ;
return - V_96 ;
}
V_61 -> V_70 += V_89 ;
if ( V_6 -> type == V_18 && V_61 != & V_4 -> V_19 . V_69 )
V_4 -> V_53 += V_89 ;
return V_89 ;
}
static T_5 F_37 ( struct V_5 * V_6 , char T_3 * V_87 , T_2 V_97 , int V_59 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_98 = 0 ;
int V_99 = 0 ;
if ( F_38 ( & V_4 -> V_100 ) == 0 && V_6 -> V_12 == NULL ) {
F_10 ( L_10 , V_6 -> V_22 ) ;
return - V_101 ;
}
if ( V_6 -> type == V_13 ||
( V_6 -> type == V_14 && ! F_5 ( V_4 ) ) )
V_99 = 1 ;
for (; ; ) {
struct V_58 * V_61 ;
int V_102 ;
V_61 = F_20 ( V_6 , V_59 , & V_102 ) ;
if ( V_61 == NULL ) {
if ( V_98 )
break;
if ( V_102 == 0 ) {
F_13 ( V_103 , & V_6 -> V_11 ) ;
F_13 ( V_65 , & V_6 -> V_11 ) ;
F_7 ( V_6 ) ;
}
return V_102 ;
}
V_102 = F_35 ( V_6 , V_61 , V_87 + V_98 , V_97 - V_98 ) ;
if ( V_61 != & V_4 -> V_19 . V_69 ) {
F_26 ( V_6 , V_61 , ( V_61 -> V_70 == V_61 -> V_71 ) ? & V_6 -> V_68 : & V_6 -> V_72 ) ;
}
else if ( V_61 -> V_70 == V_61 -> V_71 ) {
int V_42 = V_4 -> V_19 . V_83 % V_84 ;
V_4 -> V_19 . V_86 [ V_42 ] = 0 ;
V_4 -> V_19 . V_83 ++ ;
V_4 -> V_54 += V_61 -> V_71 ;
}
if ( V_102 < 0 )
return V_102 ;
V_98 += V_102 ;
if ( V_98 == V_97 || V_99 )
break;
}
return V_98 ;
}
static T_5 F_39 ( struct V_5 * V_6 , char T_3 * V_87 , T_2 V_104 ,
T_6 * V_105 , int V_59 )
{
T_5 V_102 = V_104 ? F_37 ( V_6 , V_87 , V_104 , V_59 ) : 0 ;
struct V_3 * V_4 = V_6 -> V_4 ;
F_40 ( L_11 , V_104 , V_6 -> V_22 , V_102 ) ;
if ( V_102 > 0 )
V_105 += V_102 ;
return V_102 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
struct V_5 * V_8 ;
if ( V_6 -> type == V_106 ||
V_6 -> type == V_17 ||
V_6 -> type == V_107 ||
V_6 -> type == V_108 ) {
return - V_109 ;
}
if ( F_1 ( V_2 , V_6 -> type ) )
return - V_15 ;
if ( V_6 -> type == V_13 ) {
F_6 ( V_65 , & V_6 -> V_11 ) ;
return 0 ;
}
if ( F_8 ( V_103 , & V_6 -> V_11 ) || F_2 ( V_75 , & V_6 -> V_11 ) ) {
F_6 ( V_65 , & V_6 -> V_11 ) ;
return 0 ;
}
V_8 = & V_4 -> V_7 [ V_14 ] ;
if ( V_6 -> type == V_18 &&
F_8 ( V_21 , & V_8 -> V_11 ) &&
! F_2 ( V_75 , & V_8 -> V_11 ) ) {
if ( F_42 ( V_8 ) ) {
F_10 ( L_12 ) ;
F_13 ( V_75 , & V_8 -> V_11 ) ;
F_13 ( V_75 , & V_6 -> V_11 ) ;
F_7 ( V_6 ) ;
return - V_101 ;
}
F_3 ( L_13 ) ;
}
if ( ! F_42 ( V_6 ) ) {
F_6 ( V_65 , & V_6 -> V_11 ) ;
if ( F_9 ( V_110 , & V_4 -> V_111 ) )
F_43 ( V_4 , V_112 , 1 , 1 ) ;
return 0 ;
}
F_10 ( L_14 , V_6 -> V_22 ) ;
if ( V_6 -> type == V_18 &&
F_8 ( V_75 , & V_8 -> V_11 ) ) {
F_44 ( V_8 , 0 ) ;
F_13 ( V_75 , & V_8 -> V_11 ) ;
}
F_13 ( V_75 , & V_6 -> V_11 ) ;
F_7 ( V_6 ) ;
return - V_101 ;
}
T_5 F_45 ( struct V_113 * V_114 , char T_3 * V_61 , T_2 V_104 , T_6 * V_105 )
{
struct V_1 * V_2 = F_46 ( V_114 -> V_115 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
int V_102 ;
F_40 ( L_15 , V_104 , V_6 -> V_22 ) ;
V_102 = F_41 ( V_2 ) ;
if ( V_102 )
return V_102 ;
return F_39 ( V_6 , V_61 , V_104 , V_105 , V_114 -> V_116 & V_117 ) ;
}
int F_47 ( struct V_1 * V_2 , int V_118 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
int V_102 ;
if ( F_38 ( & V_4 -> V_119 ) == 0 ) {
if ( F_1 ( V_2 , V_6 -> type ) ) {
F_10 ( L_16 ) ;
return - V_15 ;
}
V_102 = F_48 ( V_6 , 0 ) ;
if ( V_102 < 0 ) {
if ( V_102 == - V_76 )
V_102 = F_48 ( V_6 , 0 ) ;
if ( V_102 < 0 )
return V_102 ;
}
}
if ( V_6 -> type == V_17 )
return F_49 ( V_4 , V_118 ) ;
return 0 ;
}
T_5 F_50 ( struct V_113 * V_114 , const char T_3 * V_120 , T_2 V_104 , T_6 * V_105 )
{
struct V_1 * V_2 = F_46 ( V_114 -> V_115 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
struct V_121 * V_122 = & V_4 -> V_123 ;
struct V_58 * V_61 ;
struct V_124 V_92 ;
int V_125 = 0 ;
int V_126 ;
int V_102 ;
F_21 ( V_62 ) ;
F_40 ( L_17 , V_104 , V_6 -> V_22 ) ;
if ( V_6 -> type != V_17 &&
V_6 -> type != V_107 &&
V_6 -> type != V_108 )
return - V_109 ;
if ( F_1 ( V_2 , V_6 -> type ) )
return - V_15 ;
if ( V_6 -> type == V_108 ) {
int V_127 = V_104 / sizeof( struct V_128 ) ;
F_6 ( V_65 , & V_6 -> V_11 ) ;
return F_51 ( V_4 ,
( const struct V_128 T_3 * ) V_120 , V_127 ) ;
}
V_126 = V_6 -> type == V_17 ? V_129 : V_130 ;
if ( F_52 ( V_4 , V_126 ) != V_126 ) {
F_7 ( V_6 ) ;
return - V_15 ;
}
F_53 ( & V_92 ) ;
F_6 ( V_65 , & V_6 -> V_11 ) ;
V_102 = F_47 ( V_2 , V_4 -> V_118 ) ;
if ( V_102 ) {
F_10 ( L_18 , V_6 -> V_22 ) ;
F_13 ( V_75 , & V_6 -> V_11 ) ;
F_13 ( V_65 , & V_6 -> V_11 ) ;
return V_102 ;
}
V_131:
if ( V_126 == V_130 && V_6 -> V_66 . V_55 == 0 && V_4 -> V_132 ) {
while ( V_104 >= V_4 -> V_132 ) {
V_102 = F_54 ( V_4 , ( void T_3 * ) V_120 ) ;
if ( V_102 < 0 )
return V_102 ;
V_125 += V_4 -> V_132 ;
V_120 += V_4 -> V_132 ;
V_104 -= V_4 -> V_132 ;
}
if ( V_104 == 0 ) {
F_40 ( L_19 , V_125 , V_6 -> V_22 , V_6 -> V_66 . V_71 ) ;
return V_125 ;
}
}
for (; ; ) {
while ( V_92 . V_55 - V_92 . V_71 < V_104 && ( V_61 = F_24 ( V_6 , & V_6 -> V_72 ) ) )
F_26 ( V_6 , V_61 , & V_92 ) ;
while ( V_92 . V_55 - V_92 . V_71 < V_104 && ( V_61 = F_24 ( V_6 , & V_6 -> V_68 ) ) ) {
F_26 ( V_6 , V_61 , & V_92 ) ;
}
if ( V_92 . V_80 )
break;
if ( V_114 -> V_116 & V_117 )
return - V_76 ;
F_28 ( & V_4 -> V_77 ) ;
F_29 ( & V_6 -> V_78 , & V_62 , V_79 ) ;
if ( ! V_6 -> V_68 . V_80 )
F_30 () ;
F_31 ( & V_6 -> V_78 , & V_62 ) ;
F_32 ( & V_4 -> V_77 ) ;
if ( F_33 ( V_81 ) ) {
F_3 ( L_8 , V_6 -> V_22 ) ;
return - V_82 ;
}
}
while ( ( V_61 = F_24 ( V_6 , & V_92 ) ) ) {
if ( V_6 -> type == V_107 &&
V_122 -> V_133 + V_104 > V_4 -> V_132 )
V_102 = F_55 ( V_6 , V_61 , V_120 ,
V_4 -> V_132 - V_122 -> V_133 ) ;
else
V_102 = F_55 ( V_6 , V_61 , V_120 , V_104 ) ;
if ( V_102 < 0 ) {
F_56 ( V_6 , & V_92 , NULL , & V_6 -> V_68 , 0 ) ;
return V_102 ;
}
V_120 += V_102 ;
V_104 -= V_102 ;
V_125 += V_102 ;
if ( V_6 -> type == V_107 ) {
V_122 -> V_133 += V_102 ;
if ( V_122 -> V_133 == V_4 -> V_132 ) {
F_26 ( V_6 , V_61 , & V_6 -> V_66 ) ;
V_122 -> V_133 = 0 ;
break;
}
}
if ( V_61 -> V_71 != V_6 -> V_134 ) {
F_26 ( V_6 , V_61 , & V_6 -> V_72 ) ;
break;
}
if ( V_6 -> type == V_17 )
F_27 ( V_61 ) ;
F_26 ( V_6 , V_61 , & V_6 -> V_66 ) ;
}
if ( F_8 ( V_135 , & V_6 -> V_11 ) ) {
if ( V_6 -> V_66 . V_55 >= V_4 -> V_132 ) {
int V_136 ;
if ( V_126 == V_130 )
F_57 ( V_4 ) ;
F_28 ( & V_4 -> V_77 ) ;
F_29 ( & V_4 -> V_137 , & V_62 , V_79 ) ;
while ( ! ( V_136 = F_33 ( V_81 ) ) &&
F_8 ( V_138 , & V_6 -> V_11 ) ) {
F_30 () ;
}
F_31 ( & V_4 -> V_137 , & V_62 ) ;
F_32 ( & V_4 -> V_77 ) ;
if ( V_136 ) {
F_3 ( L_20 , V_6 -> V_22 ) ;
return - V_82 ;
}
F_13 ( V_135 , & V_6 -> V_11 ) ;
F_56 ( V_6 , & V_6 -> V_66 , NULL , & V_6 -> V_139 , V_4 -> V_132 ) ;
F_58 ( V_6 , V_4 -> V_140 + V_141 , 1 ) ;
}
}
if ( V_104 && ! ( V_114 -> V_116 & V_117 ) )
goto V_131;
F_40 ( L_19 , V_125 , V_6 -> V_22 , V_6 -> V_66 . V_71 ) ;
return V_125 ;
}
unsigned int F_59 ( struct V_113 * V_114 , T_7 * V_62 )
{
struct V_1 * V_2 = F_46 ( V_114 -> V_115 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
int V_142 = 0 ;
F_40 ( L_21 ) ;
if ( ! F_60 ( & V_2 -> V_12 . V_143 ) ) {
F_61 ( V_114 , & V_2 -> V_12 . V_62 , V_62 ) ;
F_13 ( V_144 , & V_4 -> V_111 ) ;
if ( F_62 ( & V_2 -> V_12 ) )
V_142 = V_145 ;
} else {
F_61 ( V_114 , & V_6 -> V_78 , V_62 ) ;
F_6 ( V_144 , & V_4 -> V_111 ) ;
if ( F_8 ( V_146 , & V_4 -> V_111 ) ||
F_8 ( V_147 , & V_4 -> V_111 ) )
V_142 = V_145 ;
}
if ( V_6 -> V_68 . V_80 )
V_142 |= V_148 | V_149 ;
return V_142 ;
}
unsigned int F_63 ( struct V_113 * V_114 , T_7 * V_62 )
{
struct V_1 * V_2 = F_46 ( V_114 -> V_115 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
int V_150 = F_8 ( V_103 , & V_6 -> V_11 ) ;
unsigned V_142 = 0 ;
if ( ! V_150 && ! F_8 ( V_75 , & V_6 -> V_11 ) ) {
int V_102 ;
V_102 = F_41 ( V_2 ) ;
if ( V_102 ) {
F_3 ( L_22 ,
V_6 -> V_22 , V_102 ) ;
return V_151 ;
}
F_64 ( L_23 ) ;
}
F_40 ( L_24 ) ;
F_61 ( V_114 , & V_6 -> V_78 , V_62 ) ;
if ( F_62 ( & V_2 -> V_12 ) )
V_142 |= V_145 ;
else
F_61 ( V_114 , & V_2 -> V_12 . V_62 , V_62 ) ;
if ( V_6 -> V_66 . V_55 || V_6 -> V_72 . V_55 )
return V_142 | V_152 | V_153 ;
if ( V_150 )
return V_142 | V_154 ;
return V_142 ;
}
void F_65 ( struct V_1 * V_2 , int V_155 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
F_64 ( L_25 , V_6 -> V_22 ) ;
if ( F_8 ( V_75 , & V_6 -> V_11 ) ) {
struct V_5 * V_8 = & V_4 -> V_7 [ V_14 ] ;
F_3 ( L_26 ) ;
if ( V_2 -> type == V_18 &&
F_8 ( V_75 , & V_8 -> V_11 ) &&
! F_8 ( V_65 , & V_8 -> V_11 ) ) {
F_3 ( L_27 ) ;
F_44 ( V_8 , 0 ) ;
}
if ( ( V_2 -> type == V_13 ||
V_2 -> type == V_14 ) &&
F_8 ( V_21 , & V_6 -> V_11 ) ) {
V_6 -> V_12 = NULL ;
}
else {
F_44 ( V_6 , V_155 ) ;
}
}
if ( ! V_155 ) {
F_13 ( V_65 , & V_6 -> V_11 ) ;
F_13 ( V_103 , & V_6 -> V_11 ) ;
F_7 ( V_6 ) ;
}
}
static void F_66 ( struct V_1 * V_2 , int V_57 , V_52 V_56 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
F_64 ( L_25 , V_6 -> V_22 ) ;
if ( V_2 -> type == V_107 &&
F_8 ( V_156 , & V_4 -> V_111 ) ) {
F_67 ( V_4 ) ;
}
if ( F_8 ( V_75 , & V_6 -> V_11 ) ) {
F_3 ( L_28 ) ;
F_68 ( V_6 , V_57 , V_56 ) ;
V_4 -> V_157 = V_158 ;
}
F_13 ( V_65 , & V_6 -> V_11 ) ;
F_13 ( V_103 , & V_6 -> V_11 ) ;
if ( V_4 -> V_157 == V_159 && V_2 -> V_160 )
V_4 -> V_157 = V_158 ;
V_4 -> V_118 = 0 ;
F_13 ( V_161 , & V_4 -> V_111 ) ;
F_7 ( V_6 ) ;
}
int F_69 ( struct V_113 * V_114 )
{
struct V_162 * V_12 = V_114 -> V_115 ;
struct V_1 * V_2 = F_46 ( V_12 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
F_64 ( L_29 , V_6 -> V_22 ) ;
if ( V_2 -> type == V_106 &&
F_70 ( V_114 ) ) {
F_71 ( V_4 ) ;
F_13 ( V_163 , & V_4 -> V_111 ) ;
F_16 ( V_4 , V_164 , V_165 , V_4 -> V_166 ) ;
F_72 ( V_4 ) ;
if ( V_4 -> V_167 & V_168 ) {
F_73 ( V_4 , V_168 , V_169 , V_170 ,
V_171 , 0 ) ;
}
if ( F_38 ( & V_4 -> V_100 ) > 0 ) {
F_43 ( V_4 , V_172 , 1 ,
F_15 ( V_4 -> V_27 . V_173 ) |
( F_15 ( V_4 -> V_27 . V_174 ) << 8 ) ) ;
}
F_74 ( V_4 ) ;
}
F_75 ( V_12 ) ;
F_76 ( V_12 ) ;
if ( V_6 -> V_12 != & V_2 -> V_12 ) {
F_77 ( V_2 ) ;
return 0 ;
}
if ( V_6 -> type >= V_17 ) {
struct V_5 * V_175 = & V_4 -> V_7 [ V_108 ] ;
F_66 ( V_2 , V_176 | V_177 , 0 ) ;
if ( V_4 -> V_157 == V_158 && ! F_8 ( V_65 , & V_175 -> V_11 ) ) {
F_78 ( V_4 ) ;
}
} else {
F_65 ( V_2 , 0 ) ;
}
F_77 ( V_2 ) ;
return 0 ;
}
void F_71 ( struct V_3 * V_4 )
{
if ( F_38 ( & V_4 -> V_100 ) )
F_43 ( V_4 , V_178 , 1 , 1 ) ;
F_3 ( L_30 ) ;
}
void F_74 ( struct V_3 * V_4 )
{
if ( F_38 ( & V_4 -> V_100 ) ) {
F_79 ( 100 , 0 ) ;
F_43 ( V_4 , V_179 , 1 , 12 ) ;
F_43 ( V_4 , V_178 , 1 , 0 ) ;
}
F_3 ( L_31 ) ;
}
