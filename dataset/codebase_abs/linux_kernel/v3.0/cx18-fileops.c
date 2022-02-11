int F_1 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ type ] ;
struct V_5 * V_8 ;
if ( type == V_9 ) {
F_2 ( L_1
L_2 ) ;
return - V_10 ;
}
if ( F_3 ( V_11 , & V_6 -> V_12 ) ) {
if ( V_6 -> V_2 == V_2 -> V_13 ) {
return 0 ;
}
if ( V_6 -> V_2 == - 1 && type == V_14 ) {
V_6 -> V_2 = V_2 -> V_13 ;
F_4 ( L_3 ) ;
return 0 ;
}
F_4 ( L_4 , type ) ;
return - V_15 ;
}
V_6 -> V_2 = V_2 -> V_13 ;
if ( type != V_16 )
return 0 ;
V_8 = & V_4 -> V_7 [ V_9 ] ;
if ( V_4 -> V_17 . V_18 && ! F_5 ( V_4 ) )
V_8 = & V_4 -> V_7 [ V_14 ] ;
else if ( ! F_6 ( V_8 ) )
return 0 ;
F_7 ( V_11 , & V_8 -> V_12 ) ;
F_7 ( V_19 , & V_8 -> V_12 ) ;
return 0 ;
}
void F_8 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_5 * V_8 ;
V_6 -> V_2 = - 1 ;
if ( V_6 -> type == V_9 ) {
return;
}
if ( V_6 -> type == V_14 &&
F_9 ( V_19 , & V_6 -> V_12 ) ) {
return;
}
if ( ! F_10 ( V_11 , & V_6 -> V_12 ) ) {
F_11 ( L_5 , V_6 -> V_20 ) ;
return;
}
F_12 ( V_6 ) ;
if ( V_6 -> type != V_16 )
return;
V_8 = & V_4 -> V_7 [ V_9 ] ;
if ( F_10 ( V_19 , & V_8 -> V_12 ) ) {
F_13 ( V_11 , & V_8 -> V_12 ) ;
F_12 ( V_8 ) ;
}
V_8 = & V_4 -> V_7 [ V_14 ] ;
if ( F_10 ( V_19 , & V_8 -> V_12 ) ) {
if ( V_8 -> V_2 == - 1 ) {
F_13 ( V_11 , & V_8 -> V_12 ) ;
F_12 ( V_8 ) ;
}
}
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_21 V_22 ;
T_1 V_23 ;
const T_1 V_24 = 0x0200 ;
V_23 = F_15 ( V_4 -> V_25 . V_26 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_16 ( V_4 , V_27 , V_28 , & V_22 ) ;
if ( V_22 . V_29 == V_30 &&
( V_22 . V_31 & V_32 ) )
V_23 = V_24 ;
if ( V_23 == V_4 -> V_33 )
return;
F_4 ( L_6 ,
V_4 -> V_33 , V_23 ) ;
if ( F_17 ( V_4 -> V_25 . V_26 , V_23 ) )
F_4 ( L_7 ) ;
}
static struct V_34 * F_18 ( struct V_5 * V_6 , int V_35 ,
int * V_36 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_5 * V_37 = & V_4 -> V_7 [ V_14 ] ;
struct V_34 * V_38 ;
F_19 ( V_39 ) ;
* V_36 = 0 ;
while ( 1 ) {
if ( V_6 -> type == V_16 ) {
if ( F_20 ( V_40 , V_4 -> V_41 + F_21 ( 1000 ) ) ) {
V_4 -> V_41 = V_40 ;
F_14 ( V_4 ) ;
}
if ( F_9 ( V_19 , & V_37 -> V_12 ) &&
! F_9 ( V_42 , & V_37 -> V_12 ) ) {
while ( ( V_38 = F_22 ( V_37 ,
& V_37 -> V_43 ) ) ) {
F_23 ( V_4 , V_38 ,
V_37 -> type ) ;
F_24 ( V_37 , V_38 ) ;
}
}
V_38 = & V_4 -> V_17 . V_44 ;
if ( V_38 -> V_45 != V_38 -> V_46 )
return V_38 ;
}
V_38 = F_22 ( V_6 , & V_6 -> V_43 ) ;
if ( V_38 ) {
if ( ! F_10 ( V_47 ,
& V_38 -> V_48 ) )
return V_38 ;
if ( V_6 -> type == V_16 )
F_25 ( V_38 ) ;
else {
F_23 ( V_4 , V_38 , V_6 -> type ) ;
}
return V_38 ;
}
if ( ! F_9 ( V_49 , & V_6 -> V_12 ) ) {
F_4 ( L_8 , V_6 -> V_20 ) ;
return NULL ;
}
if ( V_35 ) {
* V_36 = - V_50 ;
return NULL ;
}
F_26 ( & V_6 -> V_51 , & V_39 , V_52 ) ;
if ( ! F_27 ( & V_6 -> V_43 . V_53 ) )
F_28 () ;
F_29 ( & V_6 -> V_51 , & V_39 ) ;
if ( F_30 ( V_54 ) ) {
F_4 ( L_9 , V_6 -> V_20 ) ;
* V_36 = - V_55 ;
return NULL ;
}
}
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_34 * V_38 = & V_4 -> V_17 . V_44 ;
struct V_56 * V_57 = & V_4 -> V_17 . V_58 ;
int V_59 = V_4 -> V_17 . V_60 % V_61 ;
V_57 -> V_57 = V_4 -> V_17 . V_62 [ V_59 ] ;
V_57 -> V_46 = V_4 -> V_17 . V_63 [ V_59 ] ;
V_57 -> V_45 = 0 ;
V_38 -> V_64 = NULL ;
V_38 -> V_46 = V_4 -> V_17 . V_63 [ V_59 ] ;
V_38 -> V_45 = 0 ;
}
static T_2 F_32 ( struct V_5 * V_6 ,
struct V_56 * V_57 , char T_3 * V_65 , T_2 V_66 , bool * V_67 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_68 = V_57 -> V_46 - V_57 -> V_45 ;
* V_67 = false ;
if ( V_68 > V_66 )
V_68 = V_66 ;
if ( V_4 -> V_17 . V_18 && V_6 -> type == V_16 &&
! F_5 ( V_4 ) && V_57 != & V_4 -> V_17 . V_58 ) {
const char * V_69 = V_57 -> V_57 + V_57 -> V_45 ;
const char * V_70 = V_69 + 1 ;
const T_4 * V_71 ;
T_4 V_72 = V_4 -> V_73 ? 0xba : 0xe0 ;
int V_74 , V_75 ;
while ( V_69 + V_68 > V_70 ) {
V_71 = memchr ( V_70 , 0 , V_69 + V_68 - V_70 ) ;
if ( V_71 == NULL )
break;
V_70 = V_71 + 1 ;
if ( ( char * ) V_71 + 15 >= V_57 -> V_57 + V_57 -> V_46 ||
V_71 [ 1 ] != 0 || V_71 [ 2 ] != 1 || V_71 [ 3 ] != V_72 )
continue;
if ( ! V_4 -> V_73 ) {
if ( ( V_71 [ 6 ] & 0xc0 ) != 0x80 )
continue;
if ( ( ( V_71 [ 7 ] & 0xc0 ) == 0x80 &&
( V_71 [ 9 ] & 0xf0 ) == 0x20 ) ||
( ( V_71 [ 7 ] & 0xc0 ) == 0xc0 &&
( V_71 [ 9 ] & 0xf0 ) == 0x30 ) ) {
V_72 = 0xba ;
V_4 -> V_73 = 1 ;
V_70 = V_71 + 9 ;
}
continue;
}
V_74 = V_71 [ 13 ] & 7 ;
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ )
if ( V_71 [ 14 + V_75 ] != 0xff )
break;
if ( V_75 == V_74 &&
( V_71 [ 4 ] & 0xc4 ) == 0x44 &&
( V_71 [ 12 ] & 3 ) == 3 &&
V_71 [ 14 + V_74 ] == 0 &&
V_71 [ 15 + V_74 ] == 0 &&
V_71 [ 16 + V_74 ] == 1 ) {
V_4 -> V_73 = 0 ;
V_68 = ( char * ) V_71 - V_69 ;
F_31 ( V_4 ) ;
* V_67 = true ;
break;
}
}
}
if ( F_33 ( V_65 , ( T_4 * ) V_57 -> V_57 + V_57 -> V_45 , V_68 ) ) {
F_11 ( L_10 ,
V_68 , V_6 -> V_20 ) ;
return - V_76 ;
}
V_57 -> V_45 += V_68 ;
if ( V_6 -> type == V_16 &&
V_57 != & V_4 -> V_17 . V_58 )
V_4 -> V_77 += V_68 ;
return V_68 ;
}
static T_2 F_34 ( struct V_5 * V_6 ,
struct V_34 * V_38 , char T_3 * V_65 , T_2 V_66 )
{
T_2 V_78 = 0 ;
int V_79 ;
bool V_67 = false ;
if ( V_38 -> V_64 == NULL )
V_38 -> V_64 = F_35 ( & V_38 -> V_80 ,
struct V_56 , V_81 ) ;
if ( F_36 ( V_38 -> V_64 , & V_38 -> V_80 , V_81 ) ) {
V_38 -> V_45 = V_38 -> V_46 ;
return 0 ;
}
F_37 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_38 -> V_64 -> V_45 >= V_38 -> V_64 -> V_46 )
continue;
V_79 = F_32 ( V_6 , V_38 -> V_64 , V_65 + V_78 ,
V_66 - V_78 , & V_67 ) ;
if ( V_79 < 0 )
return V_79 ;
V_38 -> V_45 += V_79 ;
V_78 += V_79 ;
if ( V_67 ||
V_78 >= V_66 ||
V_38 -> V_64 -> V_45 < V_38 -> V_64 -> V_46 ||
V_38 -> V_45 >= V_38 -> V_46 )
break;
}
return V_78 ;
}
static T_5 F_38 ( struct V_5 * V_6 , char T_3 * V_65 ,
T_2 V_82 , int V_35 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_78 = 0 ;
int V_83 = 0 ;
if ( F_27 ( & V_4 -> V_84 ) == 0 && V_6 -> V_2 == - 1 ) {
F_11 ( L_11 ,
V_6 -> V_20 ) ;
return - V_85 ;
}
if ( V_6 -> type == V_14 && ! F_5 ( V_4 ) )
V_83 = 1 ;
for (; ; ) {
struct V_34 * V_38 ;
int V_79 ;
V_38 = F_18 ( V_6 , V_35 , & V_79 ) ;
if ( V_38 == NULL ) {
if ( V_78 )
break;
if ( V_79 == 0 ) {
F_13 ( V_86 , & V_6 -> V_12 ) ;
F_13 ( V_42 , & V_6 -> V_12 ) ;
F_8 ( V_6 ) ;
}
return V_79 ;
}
V_79 = F_34 ( V_6 , V_38 , V_65 + V_78 ,
V_82 - V_78 ) ;
if ( V_38 != & V_4 -> V_17 . V_44 ) {
if ( V_38 -> V_45 == V_38 -> V_46 )
F_24 ( V_6 , V_38 ) ;
else
F_39 ( V_6 , V_38 , & V_6 -> V_43 ) ;
} else if ( V_38 -> V_45 == V_38 -> V_46 ) {
int V_59 = V_4 -> V_17 . V_60 % V_61 ;
V_4 -> V_17 . V_63 [ V_59 ] = 0 ;
V_4 -> V_17 . V_60 ++ ;
V_4 -> V_87 += V_38 -> V_46 ;
}
if ( V_79 < 0 )
return V_79 ;
V_78 += V_79 ;
if ( V_78 == V_82 || V_83 )
break;
}
return V_78 ;
}
static T_5 F_40 ( struct V_5 * V_6 , char T_3 * V_65 ,
T_2 V_88 , T_6 * V_89 , int V_35 )
{
T_5 V_79 = V_88 ? F_38 ( V_6 , V_65 , V_88 , V_35 ) : 0 ;
struct V_3 * V_4 = V_6 -> V_4 ;
F_41 ( L_12 , V_88 , V_6 -> V_20 , V_79 ) ;
if ( V_79 > 0 )
V_89 += V_79 ;
return V_79 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
struct V_5 * V_37 ;
struct V_5 * V_90 ;
if ( V_6 -> type == V_91 ) {
return - V_92 ;
}
if ( F_1 ( V_2 , V_6 -> type ) )
return - V_15 ;
if ( F_9 ( V_86 , & V_6 -> V_12 ) ||
F_3 ( V_49 , & V_6 -> V_12 ) ) {
F_7 ( V_42 , & V_6 -> V_12 ) ;
return 0 ;
}
V_37 = & V_4 -> V_7 [ V_14 ] ;
V_90 = & V_4 -> V_7 [ V_9 ] ;
if ( V_6 -> type == V_16 ) {
if ( F_9 ( V_19 , & V_90 -> V_12 ) &&
! F_3 ( V_49 , & V_90 -> V_12 ) ) {
if ( F_43 ( V_90 ) ) {
F_11 ( L_13 ) ;
F_13 ( V_49 , & V_90 -> V_12 ) ;
goto V_93;
}
F_4 ( L_14 ) ;
}
if ( F_9 ( V_19 , & V_37 -> V_12 ) &&
! F_3 ( V_49 , & V_37 -> V_12 ) ) {
if ( F_43 ( V_37 ) ) {
F_11 ( L_15 ) ;
F_13 ( V_49 , & V_37 -> V_12 ) ;
goto V_93;
}
F_4 ( L_16 ) ;
}
}
if ( ! F_43 ( V_6 ) ) {
F_7 ( V_42 , & V_6 -> V_12 ) ;
if ( F_10 ( V_94 , & V_4 -> V_95 ) )
F_44 ( V_4 , V_96 , 1 , V_6 -> V_97 ) ;
return 0 ;
}
V_93:
F_11 ( L_17 , V_6 -> V_20 ) ;
if ( V_6 -> type == V_16 ) {
if ( F_9 ( V_49 , & V_90 -> V_12 ) ) {
F_45 ( V_90 , 0 ) ;
F_13 ( V_49 , & V_90 -> V_12 ) ;
}
if ( F_9 ( V_49 , & V_37 -> V_12 ) &&
! F_9 ( V_42 , & V_37 -> V_12 ) ) {
F_45 ( V_37 , 0 ) ;
F_13 ( V_49 , & V_37 -> V_12 ) ;
}
}
F_13 ( V_49 , & V_6 -> V_12 ) ;
F_8 ( V_6 ) ;
return - V_85 ;
}
T_5 F_46 ( struct V_98 * V_99 , char T_3 * V_57 , T_2 V_88 ,
T_6 * V_89 )
{
struct V_1 * V_2 = F_47 ( V_99 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
int V_79 ;
F_41 ( L_18 , V_88 , V_6 -> V_20 ) ;
F_48 ( & V_4 -> V_100 ) ;
V_79 = F_42 ( V_2 ) ;
F_49 ( & V_4 -> V_100 ) ;
if ( V_79 )
return V_79 ;
if ( ( V_6 -> V_101 == V_102 ) &&
( V_2 -> type == V_103 ) ) {
return F_50 ( & V_6 -> V_104 , V_57 , V_88 , V_89 , 0 ,
V_99 -> V_105 & V_106 ) ;
}
return F_40 ( V_6 , V_57 , V_88 , V_89 , V_99 -> V_105 & V_106 ) ;
}
unsigned int F_51 ( struct V_98 * V_99 , T_7 * V_39 )
{
struct V_1 * V_2 = F_47 ( V_99 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
int V_107 = F_9 ( V_86 , & V_6 -> V_12 ) ;
if ( ! V_107 && ! F_9 ( V_49 , & V_6 -> V_12 ) ) {
int V_79 ;
F_48 ( & V_4 -> V_100 ) ;
V_79 = F_42 ( V_2 ) ;
F_49 ( & V_4 -> V_100 ) ;
if ( V_79 ) {
F_4 ( L_19 ,
V_6 -> V_20 , V_79 ) ;
return V_108 ;
}
F_52 ( L_20 ) ;
}
if ( ( V_6 -> V_101 == V_102 ) &&
( V_2 -> type == V_103 ) ) {
int V_109 = F_53 ( V_99 , & V_6 -> V_104 , V_39 ) ;
if ( V_107 && V_109 == V_108 )
return V_110 ;
else
return V_109 ;
}
F_41 ( L_21 ) ;
F_54 ( V_99 , & V_6 -> V_51 , V_39 ) ;
if ( F_27 ( & V_6 -> V_43 . V_53 ) )
return V_111 | V_112 ;
if ( V_107 )
return V_110 ;
return 0 ;
}
int F_55 ( struct V_98 * V_98 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_98 -> V_115 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
int V_107 = F_9 ( V_86 , & V_6 -> V_12 ) ;
if ( ( V_6 -> V_101 == V_102 ) &&
( V_2 -> type == V_103 ) ) {
if ( ! V_107 && ! F_9 ( V_49 , & V_6 -> V_12 ) ) {
int V_79 ;
F_48 ( & V_4 -> V_100 ) ;
V_79 = F_42 ( V_2 ) ;
F_49 ( & V_4 -> V_100 ) ;
if ( V_79 ) {
F_4 (
L_19 ,
V_6 -> V_20 , V_79 ) ;
return - V_10 ;
}
F_52 ( L_22 ) ;
}
return F_56 ( & V_6 -> V_104 , V_114 ) ;
}
return - V_10 ;
}
void F_57 ( unsigned long V_116 )
{
struct V_5 * V_6 = (struct V_5 * ) V_116 ;
struct V_117 * V_57 ;
unsigned long V_118 ;
F_58 ( & V_6 -> V_119 , V_118 ) ;
while ( ! F_59 ( & V_6 -> V_120 ) ) {
V_57 = F_60 ( V_6 -> V_120 . V_121 ,
struct V_117 , V_122 . V_123 ) ;
F_61 ( & V_57 -> V_122 . V_123 ) ;
V_57 -> V_122 . V_124 = V_125 ;
F_62 ( & V_57 -> V_122 . V_126 ) ;
}
F_63 ( & V_6 -> V_119 , V_118 ) ;
}
void F_64 ( struct V_1 * V_2 , int V_127 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
struct V_5 * V_37 = & V_4 -> V_7 [ V_14 ] ;
struct V_5 * V_90 = & V_4 -> V_7 [ V_9 ] ;
F_65 ( L_23 , V_6 -> V_20 ) ;
if ( F_9 ( V_49 , & V_6 -> V_12 ) ) {
F_4 ( L_24 ) ;
if ( V_2 -> type == V_16 ) {
if ( F_9 ( V_49 , & V_37 -> V_12 ) &&
! F_9 ( V_42 , & V_37 -> V_12 ) ) {
F_4 ( L_25
L_26 ) ;
F_45 ( V_37 , 0 ) ;
}
if ( F_9 ( V_49 , & V_90 -> V_12 ) ) {
F_4 ( L_27 ) ;
F_45 ( V_90 , 0 ) ;
}
}
if ( V_2 -> type == V_14 &&
F_9 ( V_19 , & V_6 -> V_12 ) )
V_6 -> V_2 = - 1 ;
else
F_45 ( V_6 , V_127 ) ;
}
if ( ! V_127 ) {
F_13 ( V_42 , & V_6 -> V_12 ) ;
F_13 ( V_86 , & V_6 -> V_12 ) ;
F_8 ( V_6 ) ;
}
}
int F_66 ( struct V_98 * V_99 )
{
struct V_128 * V_129 = V_99 -> V_115 ;
struct V_1 * V_2 = F_67 ( V_129 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 [ V_2 -> type ] ;
F_65 ( L_23 , V_6 -> V_20 ) ;
F_68 ( V_129 ) ;
F_69 ( V_129 ) ;
if ( V_6 -> V_2 != V_2 -> V_13 ) {
F_70 ( V_2 ) ;
return 0 ;
}
F_48 ( & V_4 -> V_100 ) ;
if ( V_2 -> type == V_91 ) {
F_71 ( V_4 ) ;
F_13 ( V_130 , & V_4 -> V_95 ) ;
F_16 ( V_4 , V_131 , V_132 , V_4 -> V_133 ) ;
F_72 ( V_4 ) ;
if ( F_27 ( & V_4 -> V_84 ) > 0 ) {
F_44 ( V_4 , V_134 , 2 , V_6 -> V_97 ,
( F_15 ( V_4 -> V_25 . V_135 ) |
( F_15 ( V_4 -> V_25 . V_136 ) << 8 ) ) ) ;
}
F_73 ( V_4 ) ;
F_8 ( V_6 ) ;
} else {
F_64 ( V_2 , 0 ) ;
if ( V_2 -> type == V_103 )
F_74 ( & V_2 -> V_104 ) ;
}
F_70 ( V_2 ) ;
F_49 ( & V_4 -> V_100 ) ;
return 0 ;
}
static int F_75 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_1 * V_137 ;
F_52 ( L_28 , V_6 -> V_20 ) ;
V_137 = F_76 ( sizeof( struct V_1 ) , V_138 ) ;
if ( NULL == V_137 ) {
F_11 ( L_29 ) ;
return - V_139 ;
}
F_77 ( & V_137 -> V_129 , V_6 -> V_140 ) ;
V_137 -> V_4 = V_4 ;
V_137 -> type = V_6 -> type ;
V_137 -> V_13 = V_4 -> V_13 ++ ;
V_99 -> V_115 = & V_137 -> V_129 ;
if ( V_137 -> type == V_91 ) {
if ( F_1 ( V_137 , V_137 -> type ) ) {
F_69 ( & V_137 -> V_129 ) ;
F_70 ( V_137 ) ;
return - V_15 ;
}
if ( ! F_9 ( V_130 , & V_4 -> V_95 ) ) {
if ( F_27 ( & V_4 -> V_84 ) > 0 ) {
F_8 ( V_6 ) ;
F_69 ( & V_137 -> V_129 ) ;
F_70 ( V_137 ) ;
return - V_15 ;
}
}
F_7 ( V_130 , & V_4 -> V_95 ) ;
F_71 ( V_4 ) ;
F_16 ( V_4 , V_27 , V_141 ) ;
F_72 ( V_4 ) ;
F_73 ( V_4 ) ;
}
F_78 ( & V_137 -> V_129 ) ;
return 0 ;
}
int F_79 ( struct V_98 * V_99 )
{
int V_142 ;
struct V_143 * V_140 = F_80 ( V_99 ) ;
struct V_5 * V_6 = F_81 ( V_140 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
F_48 ( & V_4 -> V_100 ) ;
if ( F_82 ( V_4 ) ) {
F_83 ( L_30 ,
F_84 ( V_140 ) ) ;
F_49 ( & V_4 -> V_100 ) ;
return - V_144 ;
}
V_142 = F_75 ( V_6 , V_99 ) ;
F_49 ( & V_4 -> V_100 ) ;
return V_142 ;
}
void F_71 ( struct V_3 * V_4 )
{
T_1 V_145 ;
if ( F_27 ( & V_4 -> V_84 ) ) {
V_145 = F_85 ( V_4 ) ;
if ( V_145 != V_146 )
F_44 ( V_4 , V_147 , 2 , V_145 , 1 ) ;
else
F_83 ( L_31 ) ;
}
F_4 ( L_32 ) ;
}
void F_73 ( struct V_3 * V_4 )
{
T_1 V_145 ;
if ( F_27 ( & V_4 -> V_84 ) ) {
V_145 = F_85 ( V_4 ) ;
if ( V_145 != V_146 ) {
F_86 ( 100 , 0 ) ;
F_44 ( V_4 , V_148 , 2 , V_145 , 12 ) ;
F_44 ( V_4 , V_147 , 2 , V_145 , 0 ) ;
} else
F_83 ( L_33 ) ;
}
F_4 ( L_34 ) ;
}
