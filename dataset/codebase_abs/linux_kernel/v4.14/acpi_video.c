static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 , & V_3 , false ) )
return - V_7 ;
for ( V_4 = V_8 ; V_4 < V_6 -> V_9 -> V_10 ; V_4 ++ ) {
if ( V_6 -> V_9 -> V_11 [ V_4 ] == V_3 )
return V_4 - V_8 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_12 = V_2 -> V_13 . V_9 + V_8 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( & V_6 -> V_14 ) ;
return F_6 ( V_6 ,
V_6 -> V_9 -> V_11 [ V_12 ] ) ;
}
static int F_7 ( struct V_15 * V_16 ,
unsigned long * V_17 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
struct V_5 * V_21 = F_8 ( V_19 ) ;
* V_17 = V_21 -> V_9 -> V_10 - V_8 - 1 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 ,
unsigned long * V_17 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
struct V_5 * V_21 = F_8 ( V_19 ) ;
unsigned long long V_22 ;
int V_23 ;
if ( F_3 ( V_21 , & V_22 , false ) )
return - V_7 ;
for ( V_23 = V_8 ; V_23 < V_21 -> V_9 -> V_10 ;
V_23 ++ )
if ( V_22 == V_21 -> V_9 -> V_11 [ V_23 ] ) {
* V_17 = V_21 -> V_9 -> V_10 - V_23 - 1 ;
return 0 ;
}
return - V_7 ;
}
static int
F_10 ( struct V_15 * V_16 , unsigned long V_17 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
struct V_5 * V_21 = F_8 ( V_19 ) ;
int V_22 ;
if ( V_17 >= V_21 -> V_9 -> V_10 - V_8 )
return - V_7 ;
V_17 = V_21 -> V_9 -> V_10 - V_17 ;
V_22 = V_21 -> V_9 -> V_11 [ V_17 - 1 ] ;
return F_6 ( V_21 , V_22 ) ;
}
static int
F_11 ( T_1 V_24 ,
union V_25 * * V_11 )
{
int V_26 ;
struct V_27 V_28 = { V_29 , NULL } ;
union V_25 * V_30 ;
* V_11 = NULL ;
V_26 = F_12 ( V_24 , L_1 , NULL , & V_28 ) ;
if ( ! F_13 ( V_26 ) )
return V_26 ;
V_30 = (union V_25 * ) V_28 . V_31 ;
if ( ! V_30 || ( V_30 -> type != V_32 ) ) {
F_14 (KERN_ERR PREFIX L_2 ) ;
V_26 = - V_33 ;
goto V_34;
}
* V_11 = V_30 ;
return 0 ;
V_34:
F_15 ( V_28 . V_31 ) ;
return V_26 ;
}
static int
F_6 ( struct V_5 * V_19 , int V_22 )
{
int V_26 ;
int V_17 ;
V_26 = F_16 ( V_19 -> V_35 -> V_24 ,
L_3 , V_22 ) ;
if ( F_17 ( V_26 ) ) {
F_18 ( ( V_36 , L_4 ) ) ;
return - V_37 ;
}
V_19 -> V_9 -> V_38 = V_22 ;
for ( V_17 = V_8 ; V_17 < V_19 -> V_9 -> V_10 ;
V_17 ++ )
if ( V_22 == V_19 -> V_9 -> V_11 [ V_17 ] ) {
if ( V_19 -> V_39 )
V_19 -> V_39 -> V_13 . V_9 =
V_17 - V_8 ;
return 0 ;
}
F_18 ( ( V_36 , L_5 ) ) ;
return - V_7 ;
}
static int F_19 ( const struct V_40 * V_41 )
{
V_42 = 9 ;
return 0 ;
}
static int F_20 (
const struct V_40 * V_41 )
{
if ( V_43 == - 1 )
V_43 = 1 ;
return 0 ;
}
static int F_21 ( const struct V_40 * V_41 )
{
V_44 = true ;
return 0 ;
}
static int F_22 ( const struct V_40 * V_41 )
{
V_45 = true ;
return 0 ;
}
static int F_23 ( const struct V_40 * V_46 )
{
if ( V_47 == - 1 )
V_47 = ( V_48 ) V_46 -> V_49 ;
return 0 ;
}
static unsigned long long
F_24 ( struct V_5 * V_19 ,
unsigned long long V_50 )
{
unsigned long long V_22 ;
if ( V_19 -> V_9 -> V_51 . V_52 ) {
if ( V_19 -> V_9 -> V_51 . V_53 )
V_50 = V_19 -> V_9 -> V_10 -
V_8 - 1 - V_50 ;
V_22 = V_19 -> V_9 -> V_11 [ V_50 +
V_8 ] ;
} else {
V_22 = V_50 ;
}
V_22 += V_42 ;
return V_22 ;
}
static int
F_3 ( struct V_5 * V_19 ,
unsigned long long * V_22 , bool V_54 )
{
T_2 V_26 = V_55 ;
int V_4 ;
if ( V_19 -> V_56 . V_57 || V_19 -> V_56 . V_58 ) {
char * V_59 = V_19 -> V_56 . V_57 ? L_6 : L_7 ;
V_26 = F_25 ( V_19 -> V_35 -> V_24 , V_59 ,
NULL , V_22 ) ;
if ( F_13 ( V_26 ) ) {
if ( V_54 ) {
return 0 ;
}
* V_22 = F_24 ( V_19 , * V_22 ) ;
for ( V_4 = V_8 ;
V_4 < V_19 -> V_9 -> V_10 ; V_4 ++ )
if ( V_19 -> V_9 -> V_11 [ V_4 ] == * V_22 ) {
V_19 -> V_9 -> V_38 = * V_22 ;
return 0 ;
}
F_26 ( ( V_36 ,
L_8 ,
V_59 ) ) ;
V_19 -> V_56 . V_57 = V_19 -> V_56 . V_58 = 0 ;
} else {
F_26 ( ( V_36 , L_9 , V_59 ) ) ;
V_19 -> V_56 . V_57 = V_19 -> V_56 . V_58 = 0 ;
}
}
* V_22 = V_19 -> V_9 -> V_38 ;
return 0 ;
}
static int
F_27 ( struct V_5 * V_19 ,
union V_25 * * V_60 , T_3 V_61 )
{
int V_26 ;
struct V_27 V_28 = { V_29 , NULL } ;
union V_25 * V_30 ;
union V_25 V_62 = { V_63 } ;
struct V_64 args = { 1 , & V_62 } ;
* V_60 = NULL ;
if ( ! V_19 )
return - V_65 ;
if ( V_61 == 128 )
V_62 . integer . V_66 = 1 ;
else if ( V_61 == 256 )
V_62 . integer . V_66 = 2 ;
else
return - V_7 ;
V_26 = F_12 ( V_19 -> V_35 -> V_24 , L_10 , & args , & V_28 ) ;
if ( F_17 ( V_26 ) )
return - V_65 ;
V_30 = V_28 . V_31 ;
if ( V_30 && V_30 -> type == V_67 )
* V_60 = V_30 ;
else {
F_14 (KERN_ERR PREFIX L_11 ) ;
V_26 = - V_33 ;
F_15 ( V_30 ) ;
}
return V_26 ;
}
static int
F_28 ( struct V_68 * V_21 , int V_69 , int V_70 )
{
T_2 V_26 ;
if ( ! V_21 -> V_56 . V_71 )
return 0 ;
if ( V_69 < 0 || V_69 > 3 || V_70 < 0 || V_70 > 1 )
return - V_7 ;
V_21 -> V_72 = ( V_70 << 2 ) | V_69 ;
V_26 = F_16 ( V_21 -> V_19 -> V_24 , L_12 ,
( V_70 << 2 ) | V_69 ) ;
if ( F_17 ( V_26 ) )
return - V_37 ;
return 0 ;
}
static int
F_29 ( const void * V_73 , const void * V_74 )
{
return * ( int * ) V_73 - * ( int * ) V_74 ;
}
static int F_30 ( struct V_5 * V_19 ,
int V_75 , int V_76 )
{
struct V_77 * V_78 = V_19 -> V_9 ;
int V_79 ;
unsigned long long V_22 ;
int V_80 ;
if ( V_42 )
return 0 ;
V_80 = V_76 == V_75
? V_78 -> V_11 [ V_8 + 1 ]
: V_75 ;
V_79 = F_6 ( V_19 , V_80 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_3 ( V_19 , & V_22 , true ) ;
if ( V_79 )
return V_79 ;
if ( V_22 != V_80 ) {
if ( V_22 < V_78 -> V_10 ) {
if ( V_78 -> V_51 . V_53 )
V_22 = V_78 -> V_10 - V_8 - 1 - V_22 ;
if ( V_78 -> V_11 [ V_22 + V_8 ] == V_80 )
V_78 -> V_51 . V_52 = 1 ;
}
if ( ! V_78 -> V_51 . V_52 )
V_19 -> V_56 . V_57 = V_19 -> V_56 . V_58 = 0 ;
}
return 0 ;
}
int F_31 ( struct V_18 * V_19 ,
struct V_77 * * V_81 ,
int * V_82 )
{
union V_25 * V_30 = NULL ;
int V_4 , V_75 = 0 , V_10 = 0 , V_83 = 0 ;
union V_25 * V_84 ;
struct V_77 * V_78 = NULL ;
int V_79 = 0 ;
T_4 V_66 ;
if ( ! F_13 ( F_11 ( V_19 -> V_24 ,
& V_30 ) ) ) {
F_32 ( ( V_85 , L_13
L_14 ) ) ;
V_79 = - V_65 ;
goto V_86;
}
if ( V_30 -> V_87 . V_10 < V_8 ) {
V_79 = - V_7 ;
goto V_86;
}
V_78 = F_33 ( sizeof( * V_78 ) , V_88 ) ;
if ( ! V_78 ) {
F_14 ( V_89 L_15 ) ;
V_79 = - V_90 ;
goto V_86;
}
V_78 -> V_11 = F_34 ( ( V_30 -> V_87 . V_10 + V_8 ) *
sizeof( * V_78 -> V_11 ) , V_88 ) ;
if ( ! V_78 -> V_11 ) {
V_79 = - V_90 ;
goto V_91;
}
for ( V_4 = 0 ; V_4 < V_30 -> V_87 . V_10 ; V_4 ++ ) {
V_84 = (union V_25 * ) & V_30 -> V_87 . V_92 [ V_4 ] ;
if ( V_84 -> type != V_63 ) {
F_14 (KERN_ERR PREFIX L_16 ) ;
continue;
}
V_66 = ( T_4 ) V_84 -> integer . V_66 ;
if ( V_10 > V_8
&& V_78 -> V_11 [ V_10 - 1 ] == V_66 )
continue;
V_78 -> V_11 [ V_10 ] = V_66 ;
if ( V_78 -> V_11 [ V_10 ] > V_75 )
V_75 = V_78 -> V_11 [ V_10 ] ;
V_10 ++ ;
}
for ( V_4 = V_8 ; V_4 < V_10 ; V_4 ++ ) {
if ( V_78 -> V_11 [ V_4 ] == V_78 -> V_11 [ V_93 ] )
V_83 ++ ;
if ( V_78 -> V_11 [ V_4 ] == V_78 -> V_11 [ V_94 ] )
V_83 ++ ;
}
if ( V_83 < V_8 ) {
V_83 = V_8 - V_83 ;
V_78 -> V_51 . V_95 = 1 ;
for ( V_4 = ( V_10 - 1 + V_83 ) ;
V_4 >= V_8 ; V_4 -- )
V_78 -> V_11 [ V_4 ] = V_78 -> V_11 [ V_4 - V_83 ] ;
V_10 += V_83 ;
} else if ( V_83 > V_8 )
F_18 ( ( V_36 , L_17 ) ) ;
if ( V_75 == V_78 -> V_11 [ V_8 ] ) {
V_78 -> V_51 . V_53 = 1 ;
F_35 ( & V_78 -> V_11 [ V_8 ] ,
V_10 - V_8 ,
sizeof( V_78 -> V_11 [ V_8 ] ) ,
F_29 , NULL ) ;
} else if ( V_75 != V_78 -> V_11 [ V_10 - 1 ] )
F_18 ( ( V_36 ,
L_18 ) ) ;
V_78 -> V_10 = V_10 ;
* V_81 = V_78 ;
if ( V_82 )
* V_82 = V_75 ;
V_86:
F_15 ( V_30 ) ;
return V_79 ;
V_91:
F_15 ( V_78 ) ;
goto V_86;
}
static int
F_36 ( struct V_5 * V_19 )
{
int V_4 , V_75 = 0 ;
unsigned long long V_22 , V_96 ;
struct V_77 * V_78 = NULL ;
int V_79 = - V_7 ;
V_79 = F_31 ( V_19 -> V_35 , & V_78 , & V_75 ) ;
if ( V_79 )
return V_79 ;
V_19 -> V_9 = V_78 ;
V_78 -> V_38 = V_22 = V_75 ;
if ( ! V_19 -> V_56 . V_57 )
goto V_97;
V_79 = F_3 ( V_19 ,
& V_96 , true ) ;
if ( V_79 )
goto V_98;
V_79 = F_30 ( V_19 , V_75 , V_96 ) ;
if ( V_79 )
goto V_98;
if ( ! V_19 -> V_56 . V_57 )
goto V_97;
V_22 = F_24 ( V_19 , V_96 ) ;
for ( V_4 = V_8 ; V_4 < V_78 -> V_10 ; V_4 ++ )
if ( V_22 == V_78 -> V_11 [ V_4 ] )
break;
if ( V_4 == V_78 -> V_10 || ! V_22 )
V_22 = V_75 ;
V_97:
V_79 = F_6 ( V_19 , V_22 ) ;
if ( V_79 )
goto V_98;
F_32 ( ( V_85 ,
L_19 ,
V_78 -> V_10 - V_8 ) ) ;
return 0 ;
V_98:
F_15 ( V_78 -> V_11 ) ;
F_15 ( V_78 ) ;
V_19 -> V_9 = NULL ;
return V_79 ;
}
static void F_37 ( struct V_5 * V_19 )
{
if ( F_38 ( V_19 -> V_35 -> V_24 , L_20 ) )
V_19 -> V_56 . V_99 = 1 ;
if ( F_38 ( V_19 -> V_35 -> V_24 , L_1 ) )
V_19 -> V_56 . V_100 = 1 ;
if ( F_38 ( V_19 -> V_35 -> V_24 , L_3 ) )
V_19 -> V_56 . V_101 = 1 ;
if ( F_38 ( V_19 -> V_35 -> V_24 , L_6 ) ) {
V_19 -> V_56 . V_57 = 1 ;
} else if ( F_38 ( V_19 -> V_35 -> V_24 , L_7 ) ) {
F_14 (KERN_WARNING FW_BUG L_21 ) ;
V_19 -> V_56 . V_58 = 1 ;
}
if ( F_38 ( V_19 -> V_35 -> V_24 , L_10 ) )
V_19 -> V_56 . V_102 = 1 ;
}
static void F_39 ( struct V_68 * V_21 )
{
if ( F_38 ( V_21 -> V_19 -> V_24 , L_12 ) )
V_21 -> V_56 . V_71 = 1 ;
if ( F_38 ( V_21 -> V_19 -> V_24 , L_22 ) )
V_21 -> V_56 . V_103 = 1 ;
if ( F_38 ( V_21 -> V_19 -> V_24 , L_23 ) )
V_21 -> V_56 . V_104 = 1 ;
if ( F_38 ( V_21 -> V_19 -> V_24 , L_24 ) )
V_21 -> V_56 . V_105 = 1 ;
if ( F_38 ( V_21 -> V_19 -> V_24 , L_25 ) )
V_21 -> V_56 . V_106 = 1 ;
if ( F_38 ( V_21 -> V_19 -> V_24 , L_26 ) )
V_21 -> V_56 . V_107 = 1 ;
}
static int F_40 ( struct V_68 * V_21 )
{
T_2 V_26 = - V_108 ;
struct V_109 * V_35 ;
if ( ! V_21 )
return - V_7 ;
V_35 = F_41 ( V_21 -> V_19 -> V_24 ) ;
if ( ! V_35 )
return - V_65 ;
F_42 ( V_35 ) ;
if ( V_21 -> V_56 . V_71 || V_21 -> V_56 . V_103 ) {
if ( ! V_21 -> V_56 . V_71 ) {
F_14 (KERN_WARNING FW_BUG
L_27 ,
acpi_device_bid(video->device)) ;
}
V_21 -> V_51 . V_110 = 1 ;
V_26 = 0 ;
}
if ( V_21 -> V_56 . V_104 ) {
V_21 -> V_51 . V_111 = 1 ;
V_26 = 0 ;
}
if ( V_21 -> V_56 . V_105 && V_21 -> V_56 . V_106 && V_21 -> V_56 . V_107 ) {
V_21 -> V_51 . V_112 = 1 ;
V_26 = 0 ;
}
return V_26 ;
}
static struct V_113 *
F_43 ( struct V_68 * V_21 , unsigned long V_114 )
{
struct V_115 * V_116 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_21 -> V_117 ; V_4 ++ ) {
V_116 = & V_21 -> V_118 [ V_4 ] ;
if ( ( V_116 -> V_66 . V_119 & 0xffff ) == V_114 )
return & V_116 -> V_66 . V_120 ;
}
return NULL ;
}
static int
F_44 ( struct V_68 * V_21 ,
unsigned long V_114 )
{
struct V_115 * V_116 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_21 -> V_117 ; V_4 ++ ) {
V_116 = & V_21 -> V_118 [ V_4 ] ;
if ( ( V_116 -> V_66 . V_119 & 0xffff ) == V_114 )
return V_116 -> V_66 . V_119 ;
}
return 0 ;
}
static int
F_45 ( struct V_18 * V_19 ,
struct V_68 * V_21 )
{
unsigned long long V_114 ;
int V_26 , V_121 ;
struct V_5 * V_122 ;
struct V_113 * V_123 ;
V_26 =
F_25 ( V_19 -> V_24 , L_20 , NULL , & V_114 ) ;
if ( F_17 ( V_26 ) )
return 0 ;
V_122 = F_33 ( sizeof( struct V_5 ) , V_88 ) ;
if ( ! V_122 )
return - V_90 ;
strcpy ( F_46 ( V_19 ) , V_124 ) ;
strcpy ( F_47 ( V_19 ) , V_125 ) ;
V_19 -> V_49 = V_122 ;
V_122 -> V_114 = V_114 ;
V_122 -> V_21 = V_21 ;
V_122 -> V_35 = V_19 ;
F_48 ( & V_122 -> V_14 ,
V_126 ) ;
V_123 = F_43 ( V_21 , V_114 ) ;
if ( V_123 && ( V_123 -> V_44 || V_44 ) ) {
switch ( V_123 -> V_127 ) {
case V_128 :
V_122 -> V_51 . V_129 = 1 ;
break;
case V_130 :
V_122 -> V_51 . V_131 = 1 ;
break;
case V_132 :
V_122 -> V_51 . V_133 = 1 ;
break;
case V_134 :
V_122 -> V_51 . V_135 = 1 ;
break;
default:
V_122 -> V_51 . V_136 = 1 ;
break;
}
if ( V_123 -> V_137 )
V_122 -> V_51 . V_138 = 1 ;
} else {
V_121 = F_44 ( V_21 , V_114 ) ;
switch ( V_121 & 0xffe2ffff ) {
case V_139 :
V_122 -> V_51 . V_129 = 1 ;
break;
case V_140 :
V_122 -> V_51 . V_135 = 1 ;
break;
case V_141 :
V_122 -> V_51 . V_131 = 1 ;
break;
default:
V_122 -> V_51 . V_136 = 1 ;
}
}
F_49 ( V_21 , V_122 ) ;
F_37 ( V_122 ) ;
F_50 ( & V_21 -> V_142 ) ;
F_51 ( & V_122 -> V_143 , & V_21 -> V_144 ) ;
F_52 ( & V_21 -> V_142 ) ;
return V_26 ;
}
static void F_53 ( struct V_68 * V_21 )
{
struct V_5 * V_35 ;
F_50 ( & V_21 -> V_142 ) ;
F_54 (dev, &video->video_device_list, entry)
F_49 ( V_21 , V_35 ) ;
F_52 ( & V_21 -> V_142 ) ;
}
static void
F_49 ( struct V_68 * V_21 ,
struct V_5 * V_19 )
{
struct V_115 * V_116 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_21 -> V_117 ; V_4 ++ ) {
V_116 = & V_21 -> V_118 [ V_4 ] ;
if ( V_19 -> V_114 == ( V_116 -> V_66 . V_119 & 0xffff ) ) {
V_116 -> V_145 = V_19 ;
F_32 ( ( V_85 , L_28 , V_4 ) ) ;
}
}
}
static bool F_55 ( struct V_5 * V_19 )
{
struct V_68 * V_21 = V_19 -> V_21 ;
int V_4 ;
if ( ! V_21 -> V_117 || V_21 -> V_146 > 8 )
return true ;
for ( V_4 = 0 ; V_4 < V_21 -> V_117 ; V_4 ++ ) {
if ( ( V_21 -> V_118 [ V_4 ] . V_66 . V_119 & 0xfff ) ==
( V_19 -> V_114 & 0xfff ) )
return true ;
}
return false ;
}
static int F_56 ( struct V_68 * V_21 )
{
int V_26 ;
int V_10 ;
int V_4 ;
struct V_115 * V_147 ;
struct V_27 V_28 = { V_29 , NULL } ;
union V_25 * V_148 = NULL ;
union V_25 * V_30 ;
if ( ! V_21 -> V_56 . V_103 )
return V_149 ;
V_26 = F_12 ( V_21 -> V_19 -> V_24 , L_22 , NULL , & V_28 ) ;
if ( ! F_13 ( V_26 ) ) {
F_57 ( ( V_36 , V_26 , L_29 ) ) ;
return V_26 ;
}
V_148 = V_28 . V_31 ;
if ( ! V_148 || ( V_148 -> type != V_32 ) ) {
F_57 ( ( V_36 , V_26 , L_30 ) ) ;
V_26 = - V_33 ;
goto V_86;
}
F_32 ( ( V_85 , L_31 ,
V_148 -> V_87 . V_10 ) ) ;
V_147 = F_58 ( 1 + V_148 -> V_87 . V_10 ,
sizeof( struct V_115 ) ,
V_88 ) ;
if ( ! V_147 ) {
V_26 = - V_90 ;
goto V_86;
}
V_10 = 0 ;
for ( V_4 = 0 ; V_4 < V_148 -> V_87 . V_10 ; V_4 ++ ) {
V_30 = & V_148 -> V_87 . V_92 [ V_4 ] ;
if ( V_30 -> type != V_63 ) {
F_14 (KERN_ERR PREFIX
L_32 , i) ;
continue;
}
V_147 [ V_10 ] . V_66 . V_119 = V_30 -> integer . V_66 ;
V_147 [ V_10 ] . V_145 = NULL ;
F_32 ( ( V_85 , L_33 , V_4 ,
( int ) V_30 -> integer . V_66 ) ) ;
V_10 ++ ;
}
F_15 ( V_21 -> V_118 ) ;
V_21 -> V_118 = V_147 ;
V_21 -> V_117 = V_10 ;
V_86:
F_15 ( V_28 . V_31 ) ;
return V_26 ;
}
static int
F_59 ( struct V_5 * V_19 ,
T_4 V_150 , T_4 V_151 )
{
int V_152 , V_153 , V_154 , V_155 , V_4 , V_156 , V_157 = 255 ;
V_153 = V_155 = 0 ;
V_152 = V_154 = 255 ;
for ( V_4 = V_8 ; V_4 < V_19 -> V_9 -> V_10 ; V_4 ++ ) {
V_156 = V_19 -> V_9 -> V_11 [ V_4 ] ;
if ( abs ( V_156 - V_150 ) < abs ( V_157 ) ) {
V_157 = V_156 - V_150 ;
if ( ! V_157 )
break;
}
}
V_150 += V_157 ;
for ( V_4 = V_8 ; V_4 < V_19 -> V_9 -> V_10 ; V_4 ++ ) {
V_156 = V_19 -> V_9 -> V_11 [ V_4 ] ;
if ( V_156 < V_152 )
V_152 = V_156 ;
if ( V_156 > V_153 )
V_153 = V_156 ;
if ( V_156 < V_154 && V_156 > V_150 )
V_154 = V_156 ;
if ( V_156 > V_155 && V_156 < V_150 )
V_155 = V_156 ;
}
switch ( V_151 ) {
case V_158 :
return ( V_150 < V_153 ) ? V_154 : V_152 ;
case V_159 :
return ( V_150 < V_153 ) ? V_154 : V_153 ;
case V_160 :
return ( V_150 > V_152 ) ? V_155 : V_152 ;
case V_161 :
case V_162 :
return 0 ;
default:
return V_150 ;
}
}
static void
V_126 ( struct V_163 * V_164 )
{
struct V_5 * V_19 = F_60 ( F_61 ( V_164 ) ,
struct V_5 , V_14 ) ;
unsigned long long V_150 , V_165 ;
int V_151 = V_19 -> V_166 ;
int V_79 = - V_7 ;
if ( ! V_19 -> V_39 )
return;
if ( ! V_19 -> V_9 )
goto V_86;
V_79 = F_3 ( V_19 ,
& V_150 ,
false ) ;
if ( V_79 )
goto V_86;
V_165 = F_59 ( V_19 , V_150 , V_151 ) ;
V_79 = F_6 ( V_19 , V_165 ) ;
if ( ! V_79 )
F_62 ( V_19 -> V_39 ,
V_167 ) ;
V_86:
if ( V_79 )
F_14 (KERN_ERR PREFIX L_34 ) ;
}
int F_63 ( struct V_18 * V_19 , int type , int V_114 ,
void * * V_60 )
{
struct V_68 * V_21 ;
struct V_5 * V_168 ;
union V_25 * V_28 = NULL ;
T_2 V_26 ;
int V_4 , V_61 ;
if ( ! V_19 || ! F_8 ( V_19 ) )
return - V_7 ;
V_21 = F_8 ( V_19 ) ;
for ( V_4 = 0 ; V_4 < V_21 -> V_117 ; V_4 ++ ) {
V_168 = V_21 -> V_118 [ V_4 ] . V_145 ;
V_61 = 256 ;
if ( ! V_168 )
continue;
if ( ! V_168 -> V_56 . V_102 )
continue;
if ( type ) {
switch ( type ) {
case V_128 :
if ( ! V_168 -> V_51 . V_129 )
continue;
break;
case V_130 :
if ( ! V_168 -> V_51 . V_131 )
continue;
break;
case V_132 :
if ( ! V_168 -> V_51 . V_133 )
continue;
break;
case V_134 :
if ( ! V_168 -> V_51 . V_135 )
continue;
break;
}
} else if ( V_168 -> V_114 != V_114 ) {
continue;
}
V_26 = F_27 ( V_168 , & V_28 , V_61 ) ;
if ( F_17 ( V_26 ) || ! V_28 ||
V_28 -> type != V_67 ) {
V_61 = 128 ;
V_26 = F_27 ( V_168 , & V_28 ,
V_61 ) ;
if ( F_17 ( V_26 ) || ! V_28 ||
V_28 -> type != V_67 ) {
continue;
}
}
* V_60 = V_28 -> V_28 . V_31 ;
return V_61 ;
}
return - V_65 ;
}
static int
F_64 ( struct V_68 * V_21 ,
struct V_18 * V_19 )
{
int V_26 = 0 ;
struct V_18 * V_35 ;
F_56 ( V_21 ) ;
F_54 (dev, &device->children, node) {
V_26 = F_45 ( V_35 , V_21 ) ;
if ( V_26 ) {
F_65 ( & V_35 -> V_35 , L_35 ) ;
break;
}
V_21 -> V_146 ++ ;
}
return V_26 ;
}
static int F_66 ( struct V_68 * V_21 )
{
return F_28 ( V_21 , 0 ,
F_67 () ? 1 : 0 ) ;
}
static int F_68 ( struct V_68 * V_21 )
{
return F_28 ( V_21 , 0 ,
F_67 () ? 0 : 1 ) ;
}
static void F_69 ( struct V_18 * V_19 , T_4 V_151 )
{
struct V_68 * V_21 = F_8 ( V_19 ) ;
struct V_169 * V_170 ;
int V_171 = 0 ;
if ( ! V_21 || ! V_21 -> V_170 )
return;
V_170 = V_21 -> V_170 ;
switch ( V_151 ) {
case V_172 :
V_171 = V_173 ;
break;
case V_174 :
F_56 ( V_21 ) ;
F_53 ( V_21 ) ;
V_171 = V_173 ;
break;
case V_175 :
V_171 = V_173 ;
break;
case V_176 :
V_171 = V_177 ;
break;
case V_178 :
V_171 = V_179 ;
break;
default:
F_32 ( ( V_85 ,
L_36 , V_151 ) ) ;
break;
}
if ( F_70 ( V_19 , V_151 , 0 ) )
V_171 = 0 ;
if ( V_171 && ( V_47 & V_180 ) ) {
F_71 ( V_170 , V_171 , 1 ) ;
F_72 ( V_170 ) ;
F_71 ( V_170 , V_171 , 0 ) ;
F_72 ( V_170 ) ;
}
return;
}
static void F_73 ( struct V_5 * V_168 ,
T_4 V_151 )
{
if ( ! V_181 )
return;
V_168 -> V_166 = V_151 ;
F_74 ( & V_168 -> V_14 , V_182 / 10 ) ;
}
static void F_75 ( T_1 V_24 , T_4 V_151 , void * V_122 )
{
struct V_5 * V_168 = V_122 ;
struct V_18 * V_19 = NULL ;
struct V_68 * V_183 ;
struct V_169 * V_170 ;
int V_171 = 0 ;
if ( ! V_168 )
return;
V_19 = V_168 -> V_35 ;
V_183 = V_168 -> V_21 ;
V_170 = V_183 -> V_170 ;
switch ( V_151 ) {
case V_158 :
F_73 ( V_168 , V_151 ) ;
V_171 = V_184 ;
break;
case V_159 :
F_73 ( V_168 , V_151 ) ;
V_171 = V_185 ;
break;
case V_160 :
F_73 ( V_168 , V_151 ) ;
V_171 = V_186 ;
break;
case V_161 :
F_73 ( V_168 , V_151 ) ;
V_171 = V_187 ;
break;
case V_162 :
F_73 ( V_168 , V_151 ) ;
V_171 = V_188 ;
break;
default:
F_32 ( ( V_85 ,
L_36 , V_151 ) ) ;
break;
}
F_70 ( V_19 , V_151 , 0 ) ;
if ( V_171 && ( V_47 & V_189 ) ) {
F_71 ( V_170 , V_171 , 1 ) ;
F_72 ( V_170 ) ;
F_71 ( V_170 , V_171 , 0 ) ;
F_72 ( V_170 ) ;
}
return;
}
static int F_76 ( struct V_190 * V_191 ,
unsigned long V_192 , void * V_193 )
{
struct V_68 * V_21 ;
struct V_5 * V_168 ;
int V_4 ;
switch ( V_192 ) {
case V_194 :
case V_195 :
case V_196 :
return V_197 ;
}
V_21 = F_60 ( V_191 , struct V_68 , V_198 ) ;
F_77 ( & V_21 -> V_19 -> V_35 , L_37 ) ;
for ( V_4 = 0 ; V_4 < V_21 -> V_117 ; V_4 ++ ) {
V_168 = V_21 -> V_118 [ V_4 ] . V_145 ;
if ( V_168 && V_168 -> V_9 )
F_6 ( V_168 ,
V_168 -> V_9 -> V_38 ) ;
}
return V_199 ;
}
static T_2
F_78 ( T_1 V_24 , T_4 V_22 , void * V_200 ,
void * * V_201 )
{
struct V_18 * V_19 = V_200 ;
struct V_18 * V_202 ;
int V_79 ;
if ( V_24 == V_19 -> V_24 )
return V_203 ;
V_79 = F_79 ( V_24 , & V_202 ) ;
if ( V_79 )
return V_55 ;
if ( ! strcmp ( F_46 ( V_202 ) , V_204 ) )
return V_205 ;
return V_55 ;
}
static void F_80 ( struct V_5 * V_19 )
{
struct V_206 V_13 ;
struct V_109 * V_207 ;
T_1 V_208 ;
struct V_19 * V_209 = NULL ;
int V_79 ;
static int V_10 ;
char * V_210 ;
V_79 = F_36 ( V_19 ) ;
if ( V_79 )
return;
if ( V_43 > 0 )
return;
V_210 = F_81 ( V_88 , L_38 , V_10 ) ;
if ( ! V_210 )
return;
V_10 ++ ;
F_82 ( V_19 -> V_35 -> V_24 , & V_208 ) ;
V_207 = F_41 ( V_208 ) ;
if ( V_207 ) {
V_209 = & V_207 -> V_35 ;
F_42 ( V_207 ) ;
}
memset ( & V_13 , 0 , sizeof( struct V_206 ) ) ;
V_13 . type = V_211 ;
V_13 . V_212 =
V_19 -> V_9 -> V_10 - V_8 - 1 ;
V_19 -> V_39 = F_83 ( V_210 ,
V_209 ,
V_19 ,
& V_213 ,
& V_13 ) ;
F_15 ( V_210 ) ;
if ( F_84 ( V_19 -> V_39 ) ) {
V_19 -> V_39 = NULL ;
return;
}
V_19 -> V_39 -> V_13 . V_9 =
F_1 ( V_19 -> V_39 ) ;
V_19 -> V_16 = F_85 ( L_39 ,
V_19 -> V_35 , & V_214 ) ;
if ( F_84 ( V_19 -> V_16 ) ) {
V_19 -> V_16 = NULL ;
return;
}
F_77 ( & V_19 -> V_35 -> V_35 , L_40 ,
V_19 -> V_16 -> V_46 ) ;
V_79 = F_86 ( & V_19 -> V_35 -> V_35 . V_215 ,
& V_19 -> V_16 -> V_19 . V_215 ,
L_41 ) ;
if ( V_79 )
F_14 (KERN_ERR PREFIX L_42 ) ;
V_79 = F_86 ( & V_19 -> V_16 -> V_19 . V_215 ,
& V_19 -> V_35 -> V_35 . V_215 , L_43 ) ;
if ( V_79 )
F_14 (KERN_ERR PREFIX L_42 ) ;
}
static void F_87 ( struct V_68 * V_21 )
{
struct V_5 * V_35 ;
union V_25 * V_11 ;
F_50 ( & V_21 -> V_142 ) ;
F_54 (dev, &video->video_device_list, entry) {
if ( ! F_11 ( V_35 -> V_35 -> V_24 , & V_11 ) )
F_15 ( V_11 ) ;
}
F_52 ( & V_21 -> V_142 ) ;
}
static bool F_88 ( struct V_5 * V_35 )
{
if ( ! F_55 ( V_35 ) ) {
F_89 ( & V_35 -> V_35 -> V_35 , L_44 ) ;
return false ;
}
if ( V_45 )
return V_35 -> V_51 . V_135 ;
return true ;
}
static int F_90 ( struct V_68 * V_21 )
{
struct V_5 * V_35 ;
if ( V_21 -> V_216 )
return 0 ;
F_87 ( V_21 ) ;
if ( F_91 () != V_217 )
return 0 ;
F_50 ( & V_21 -> V_142 ) ;
F_54 (dev, &video->video_device_list, entry) {
if ( F_88 ( V_35 ) )
F_80 ( V_35 ) ;
}
F_52 ( & V_21 -> V_142 ) ;
V_21 -> V_216 = true ;
V_21 -> V_198 . V_218 = F_76 ;
V_21 -> V_198 . V_219 = 0 ;
return F_92 ( & V_21 -> V_198 ) ;
}
static void F_93 ( struct V_5 * V_19 )
{
if ( V_19 -> V_39 ) {
F_94 ( V_19 -> V_39 ) ;
V_19 -> V_39 = NULL ;
}
if ( V_19 -> V_9 ) {
F_15 ( V_19 -> V_9 -> V_11 ) ;
F_15 ( V_19 -> V_9 ) ;
V_19 -> V_9 = NULL ;
}
if ( V_19 -> V_16 ) {
F_95 ( & V_19 -> V_35 -> V_35 . V_215 , L_41 ) ;
F_95 ( & V_19 -> V_16 -> V_19 . V_215 , L_43 ) ;
F_96 ( V_19 -> V_16 ) ;
V_19 -> V_16 = NULL ;
}
}
static int F_97 ( struct V_68 * V_21 )
{
struct V_5 * V_35 ;
int error ;
if ( ! V_21 -> V_216 )
return 0 ;
error = F_98 ( & V_21 -> V_198 ) ;
F_50 ( & V_21 -> V_142 ) ;
F_54 (dev, &video->video_device_list, entry)
F_93 ( V_35 ) ;
F_52 ( & V_21 -> V_142 ) ;
V_21 -> V_216 = false ;
return error ;
}
static void F_99 ( struct V_5 * V_19 )
{
T_2 V_26 ;
struct V_18 * V_220 = V_19 -> V_35 ;
V_26 = F_100 ( V_220 -> V_24 , V_221 ,
F_75 , V_19 ) ;
if ( F_17 ( V_26 ) )
F_65 ( & V_220 -> V_35 , L_45 ) ;
else
V_19 -> V_51 . V_222 = 1 ;
}
static int F_101 ( struct V_68 * V_21 )
{
struct V_169 * V_170 ;
struct V_5 * V_35 ;
int error ;
V_21 -> V_170 = V_170 = F_102 () ;
if ( ! V_170 ) {
error = - V_90 ;
goto V_86;
}
error = F_66 ( V_21 ) ;
if ( error )
goto V_223;
snprintf ( V_21 -> V_224 , sizeof( V_21 -> V_224 ) ,
L_46 , F_103 ( V_21 -> V_19 ) ) ;
V_170 -> V_210 = F_46 ( V_21 -> V_19 ) ;
V_170 -> V_224 = V_21 -> V_224 ;
V_170 -> V_46 . V_225 = V_226 ;
V_170 -> V_46 . V_227 = 0x06 ;
V_170 -> V_35 . V_209 = & V_21 -> V_19 -> V_35 ;
V_170 -> V_228 [ 0 ] = F_104 ( V_229 ) ;
F_105 ( V_173 , V_170 -> V_230 ) ;
F_105 ( V_177 , V_170 -> V_230 ) ;
F_105 ( V_179 , V_170 -> V_230 ) ;
F_105 ( V_184 , V_170 -> V_230 ) ;
F_105 ( V_185 , V_170 -> V_230 ) ;
F_105 ( V_186 , V_170 -> V_230 ) ;
F_105 ( V_187 , V_170 -> V_230 ) ;
F_105 ( V_188 , V_170 -> V_230 ) ;
error = F_106 ( V_170 ) ;
if ( error )
goto V_231;
F_50 ( & V_21 -> V_142 ) ;
F_54 (dev, &video->video_device_list, entry)
F_99 ( V_35 ) ;
F_52 ( & V_21 -> V_142 ) ;
return 0 ;
V_231:
F_68 ( V_21 ) ;
V_223:
F_107 ( V_170 ) ;
V_21 -> V_170 = NULL ;
V_86:
return error ;
}
static void F_108 ( struct V_5 * V_35 )
{
if ( V_35 -> V_51 . V_222 ) {
F_109 ( V_35 -> V_35 -> V_24 , V_221 ,
F_75 ) ;
V_35 -> V_51 . V_222 = 0 ;
}
}
static void F_110 ( struct V_68 * V_21 )
{
struct V_5 * V_35 ;
F_50 ( & V_21 -> V_142 ) ;
F_54 (dev, &video->video_device_list, entry)
F_108 ( V_35 ) ;
F_52 ( & V_21 -> V_142 ) ;
F_68 ( V_21 ) ;
F_111 ( V_21 -> V_170 ) ;
V_21 -> V_170 = NULL ;
}
static int F_112 ( struct V_68 * V_21 )
{
struct V_5 * V_35 , * V_232 ;
F_50 ( & V_21 -> V_142 ) ;
F_113 (dev, next, &video->video_device_list, entry) {
F_114 ( & V_35 -> V_143 ) ;
F_15 ( V_35 ) ;
}
F_52 ( & V_21 -> V_142 ) ;
return 0 ;
}
static int F_115 ( struct V_18 * V_19 )
{
struct V_68 * V_21 ;
int error ;
T_2 V_26 ;
V_26 = F_116 ( V_233 ,
V_19 -> V_209 -> V_24 , 1 ,
F_78 , NULL ,
V_19 , NULL ) ;
if ( V_26 == V_205 ) {
F_14 (KERN_WARNING FW_BUG
L_47
L_48
L_49
L_50 ) ;
if ( ! V_234 )
return - V_65 ;
}
V_21 = F_33 ( sizeof( struct V_68 ) , V_88 ) ;
if ( ! V_21 )
return - V_90 ;
if ( ! strcmp ( V_19 -> V_235 . V_236 , L_51 ) ) {
if ( V_237 )
V_19 -> V_235 . V_236 [ 3 ] = '0' + V_237 ;
V_237 ++ ;
}
if ( ! strcmp ( V_19 -> V_235 . V_236 , L_52 ) ) {
if ( V_237 )
V_19 -> V_235 . V_236 [ 3 ] = '0' + V_237 ;
V_237 ++ ;
}
V_21 -> V_19 = V_19 ;
strcpy ( F_46 ( V_19 ) , V_204 ) ;
strcpy ( F_47 ( V_19 ) , V_125 ) ;
V_19 -> V_49 = V_21 ;
F_39 ( V_21 ) ;
error = F_40 ( V_21 ) ;
if ( error )
goto V_238;
F_117 ( & V_21 -> V_142 ) ;
F_118 ( & V_21 -> V_144 ) ;
error = F_64 ( V_21 , V_19 ) ;
if ( error )
goto V_239;
F_14 (KERN_INFO PREFIX L_53 ,
ACPI_VIDEO_DEVICE_NAME, acpi_device_bid(device),
video->flags.multihead ? L_54 : L_55 ,
video->flags.rom ? L_54 : L_55 ,
video->flags.post ? L_54 : L_55 ) ;
F_50 ( & V_240 ) ;
F_51 ( & V_21 -> V_143 , & V_241 ) ;
F_52 ( & V_240 ) ;
F_90 ( V_21 ) ;
F_101 ( V_21 ) ;
return 0 ;
V_239:
F_112 ( V_21 ) ;
F_15 ( V_21 -> V_118 ) ;
V_238:
F_15 ( V_21 ) ;
V_19 -> V_49 = NULL ;
return error ;
}
static int F_119 ( struct V_18 * V_19 )
{
struct V_68 * V_21 = NULL ;
if ( ! V_19 || ! F_8 ( V_19 ) )
return - V_7 ;
V_21 = F_8 ( V_19 ) ;
F_110 ( V_21 ) ;
F_97 ( V_21 ) ;
F_112 ( V_21 ) ;
F_50 ( & V_240 ) ;
F_114 ( & V_21 -> V_143 ) ;
F_52 ( & V_240 ) ;
F_15 ( V_21 -> V_118 ) ;
F_15 ( V_21 ) ;
return 0 ;
}
static int T_5 F_120 ( struct V_109 * V_35 )
{
if ( V_35 -> V_19 == 0x00D1 )
return 1 ;
if ( V_35 -> V_19 == 0x7000 )
return 1 ;
return 0 ;
}
static int T_5 F_121 ( void )
{
int V_242 = 0 ;
struct V_109 * V_35 = NULL ;
T_4 V_243 ;
F_122 (dev) {
if ( ( V_35 -> V_244 >> 8 ) != V_245 )
continue;
if ( V_35 -> V_246 != V_247 )
continue;
if ( F_120 ( V_35 ) )
continue;
F_123 ( V_35 , 0xfc , & V_243 ) ;
if ( ! V_243 )
continue;
V_242 = 1 ;
}
return V_242 ;
}
int F_124 ( void )
{
int V_248 = 0 ;
F_50 ( & V_249 ) ;
if ( V_250 ) {
goto V_251;
}
F_125 ( V_252 ) ;
V_248 = F_126 ( & V_68 ) ;
if ( V_248 )
goto V_251;
V_250 = 1 ;
V_251:
F_52 ( & V_249 ) ;
return V_248 ;
}
void F_127 ( void )
{
F_50 ( & V_249 ) ;
if ( V_250 ) {
F_128 ( & V_68 ) ;
V_250 = 0 ;
}
F_52 ( & V_249 ) ;
}
void F_129 ( void )
{
struct V_68 * V_21 ;
F_50 ( & V_249 ) ;
if ( V_250 ) {
F_50 ( & V_240 ) ;
F_54 (video, &video_bus_head, entry)
F_97 ( V_21 ) ;
F_52 ( & V_240 ) ;
}
F_52 ( & V_249 ) ;
}
bool F_130 ( void )
{
bool V_253 ;
F_50 ( & V_240 ) ;
V_253 = ! F_131 ( & V_241 ) ;
F_52 ( & V_240 ) ;
return V_253 &&
( V_47 & V_189 ) ;
}
static int T_5 F_132 ( void )
{
if ( V_254 )
return 0 ;
if ( F_121 () )
return 0 ;
return F_124 () ;
}
static void T_6 F_133 ( void )
{
F_134 () ;
F_127 () ;
return;
}
