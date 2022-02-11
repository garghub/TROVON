static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 , & V_3 , false ) )
return - V_7 ;
for ( V_4 = 2 ; V_4 < V_6 -> V_8 -> V_9 ; V_4 ++ ) {
if ( V_6 -> V_8 -> V_10 [ V_4 ] == V_3 )
return V_4 - 2 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 = V_2 -> V_12 . V_8 + 2 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( & V_6 -> V_13 ) ;
return F_6 ( V_6 ,
V_6 -> V_8 -> V_10 [ V_11 ] ) ;
}
static int F_7 ( struct V_14 * V_15 , unsigned
long * V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_5 * V_20 = F_8 ( V_18 ) ;
* V_16 = V_20 -> V_8 -> V_9 - 3 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 , unsigned
long * V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_5 * V_20 = F_8 ( V_18 ) ;
unsigned long long V_21 ;
int V_22 ;
if ( F_3 ( V_20 , & V_21 , false ) )
return - V_7 ;
for ( V_22 = 2 ; V_22 < V_20 -> V_8 -> V_9 ; V_22 ++ )
if ( V_21 == V_20 -> V_8 -> V_10 [ V_22 ] ) {
* V_16 = V_20 -> V_8 -> V_9 - V_22 - 1 ;
return 0 ;
}
return - V_7 ;
}
static int
F_10 ( struct V_14 * V_15 , unsigned long V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_5 * V_20 = F_8 ( V_18 ) ;
int V_21 ;
if ( V_16 >= V_20 -> V_8 -> V_9 - 2 )
return - V_7 ;
V_16 = V_20 -> V_8 -> V_9 - V_16 ;
V_21 = V_20 -> V_8 -> V_10 [ V_16 - 1 ] ;
return F_6 ( V_20 , V_21 ) ;
}
static int
F_11 ( struct V_5 * V_18 ,
union V_23 * * V_10 )
{
int V_24 ;
struct V_25 V_26 = { V_27 , NULL } ;
union V_23 * V_28 ;
* V_10 = NULL ;
V_24 = F_12 ( V_18 -> V_29 -> V_30 , L_1 , NULL , & V_26 ) ;
if ( ! F_13 ( V_24 ) )
return V_24 ;
V_28 = (union V_23 * ) V_26 . V_31 ;
if ( ! V_28 || ( V_28 -> type != V_32 ) ) {
F_14 (KERN_ERR PREFIX L_2 ) ;
V_24 = - V_33 ;
goto V_34;
}
* V_10 = V_28 ;
return 0 ;
V_34:
F_15 ( V_26 . V_31 ) ;
return V_24 ;
}
static int
F_6 ( struct V_5 * V_18 , int V_21 )
{
int V_24 ;
int V_16 ;
V_24 = F_16 ( V_18 -> V_29 -> V_30 ,
L_3 , V_21 ) ;
if ( F_17 ( V_24 ) ) {
F_18 ( ( V_35 , L_4 ) ) ;
return - V_36 ;
}
V_18 -> V_8 -> V_37 = V_21 ;
for ( V_16 = 2 ; V_16 < V_18 -> V_8 -> V_9 ; V_16 ++ )
if ( V_21 == V_18 -> V_8 -> V_10 [ V_16 ] ) {
if ( V_18 -> V_38 )
V_18 -> V_38 -> V_12 . V_8 = V_16 - 2 ;
return 0 ;
}
F_18 ( ( V_35 , L_5 ) ) ;
return - V_7 ;
}
static int F_19 ( const struct V_39 * V_40 )
{
V_41 = 9 ;
return 0 ;
}
static int F_20 (
const struct V_39 * V_40 )
{
if ( V_42 == - 1 )
V_42 = 1 ;
return 0 ;
}
static int F_21 ( const struct V_39 * V_40 )
{
V_43 = true ;
return 0 ;
}
static int F_22 ( const struct V_39 * V_40 )
{
V_44 = true ;
return 0 ;
}
static int F_23 ( const struct V_39 * V_45 )
{
if ( V_46 == - 1 )
V_46 = ( V_47 ) V_45 -> V_48 ;
return 0 ;
}
static unsigned long long
F_24 ( struct V_5 * V_18 ,
unsigned long long V_49 )
{
unsigned long long V_21 ;
if ( V_18 -> V_8 -> V_50 . V_51 ) {
if ( V_18 -> V_8 -> V_50 . V_52 )
V_49 = V_18 -> V_8 -> V_9 - 3 - V_49 ;
V_21 = V_18 -> V_8 -> V_10 [ V_49 + 2 ] ;
} else {
V_21 = V_49 ;
}
V_21 += V_41 ;
return V_21 ;
}
static int
F_3 ( struct V_5 * V_18 ,
unsigned long long * V_21 , bool V_53 )
{
T_1 V_24 = V_54 ;
int V_4 ;
if ( V_18 -> V_55 . V_56 || V_18 -> V_55 . V_57 ) {
char * V_58 = V_18 -> V_55 . V_56 ? L_6 : L_7 ;
V_24 = F_25 ( V_18 -> V_29 -> V_30 , V_58 ,
NULL , V_21 ) ;
if ( F_13 ( V_24 ) ) {
if ( V_53 ) {
return 0 ;
}
* V_21 = F_24 ( V_18 , * V_21 ) ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ )
if ( V_18 -> V_8 -> V_10 [ V_4 ] == * V_21 ) {
V_18 -> V_8 -> V_37 = * V_21 ;
return 0 ;
}
F_26 ( ( V_35 ,
L_8 ,
V_58 ) ) ;
V_18 -> V_55 . V_56 = V_18 -> V_55 . V_57 = 0 ;
} else {
F_26 ( ( V_35 , L_9 , V_58 ) ) ;
V_18 -> V_55 . V_56 = V_18 -> V_55 . V_57 = 0 ;
}
}
* V_21 = V_18 -> V_8 -> V_37 ;
return 0 ;
}
static int
F_27 ( struct V_5 * V_18 ,
union V_23 * * V_59 , T_2 V_60 )
{
int V_24 ;
struct V_25 V_26 = { V_27 , NULL } ;
union V_23 * V_28 ;
union V_23 V_61 = { V_62 } ;
struct V_63 args = { 1 , & V_61 } ;
* V_59 = NULL ;
if ( ! V_18 )
return - V_64 ;
if ( V_60 == 128 )
V_61 . integer . V_65 = 1 ;
else if ( V_60 == 256 )
V_61 . integer . V_65 = 2 ;
else
return - V_7 ;
V_24 = F_12 ( V_18 -> V_29 -> V_30 , L_10 , & args , & V_26 ) ;
if ( F_17 ( V_24 ) )
return - V_64 ;
V_28 = V_26 . V_31 ;
if ( V_28 && V_28 -> type == V_66 )
* V_59 = V_28 ;
else {
F_14 (KERN_ERR PREFIX L_11 ) ;
V_24 = - V_33 ;
F_15 ( V_28 ) ;
}
return V_24 ;
}
static int
F_28 ( struct V_67 * V_20 , int V_68 , int V_69 )
{
T_1 V_24 ;
if ( ! V_20 -> V_55 . V_70 )
return 0 ;
if ( V_68 < 0 || V_68 > 3 || V_69 < 0 || V_69 > 1 )
return - V_7 ;
V_20 -> V_71 = ( V_69 << 2 ) | V_68 ;
V_24 = F_16 ( V_20 -> V_18 -> V_30 , L_12 ,
( V_69 << 2 ) | V_68 ) ;
if ( F_17 ( V_24 ) )
return - V_36 ;
return 0 ;
}
static int
F_29 ( const void * V_72 , const void * V_73 )
{
return * ( int * ) V_72 - * ( int * ) V_73 ;
}
static int F_30 ( struct V_5 * V_18 ,
int V_74 , int V_75 )
{
struct V_76 * V_77 = V_18 -> V_8 ;
int V_78 ;
unsigned long long V_21 ;
int V_79 ;
if ( V_41 )
return 0 ;
V_79 = V_75 == V_74 ? V_77 -> V_10 [ 3 ] : V_74 ;
V_78 = F_6 ( V_18 , V_79 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_3 ( V_18 , & V_21 , true ) ;
if ( V_78 )
return V_78 ;
if ( V_21 != V_79 ) {
if ( V_21 < V_77 -> V_9 ) {
if ( V_77 -> V_50 . V_52 )
V_21 = V_77 -> V_9 - 3 - V_21 ;
if ( V_77 -> V_10 [ V_21 + 2 ] == V_79 )
V_77 -> V_50 . V_51 = 1 ;
}
if ( ! V_77 -> V_50 . V_51 )
V_18 -> V_55 . V_56 = V_18 -> V_55 . V_57 = 0 ;
}
return 0 ;
}
static int
F_31 ( struct V_5 * V_18 )
{
union V_23 * V_28 = NULL ;
int V_4 , V_74 = 0 , V_9 = 0 , V_80 = 0 ;
unsigned long long V_21 , V_81 ;
union V_23 * V_82 ;
struct V_76 * V_77 = NULL ;
int V_78 = - V_7 ;
T_3 V_65 ;
if ( ! F_13 ( F_11 ( V_18 , & V_28 ) ) ) {
F_32 ( ( V_83 , L_13
L_14 ) ) ;
goto V_84;
}
if ( V_28 -> V_85 . V_9 < 2 )
goto V_84;
V_77 = F_33 ( sizeof( * V_77 ) , V_86 ) ;
if ( ! V_77 ) {
F_14 ( V_87 L_15 ) ;
V_78 = - V_88 ;
goto V_84;
}
V_77 -> V_10 = F_34 ( ( V_28 -> V_85 . V_9 + 2 ) * sizeof *( V_77 -> V_10 ) ,
V_86 ) ;
if ( ! V_77 -> V_10 ) {
V_78 = - V_88 ;
goto V_89;
}
for ( V_4 = 0 ; V_4 < V_28 -> V_85 . V_9 ; V_4 ++ ) {
V_82 = (union V_23 * ) & V_28 -> V_85 . V_90 [ V_4 ] ;
if ( V_82 -> type != V_62 ) {
F_14 (KERN_ERR PREFIX L_16 ) ;
continue;
}
V_65 = ( T_3 ) V_82 -> integer . V_65 ;
if ( V_9 > 2 && V_77 -> V_10 [ V_9 - 1 ] == V_65 )
continue;
V_77 -> V_10 [ V_9 ] = V_65 ;
if ( V_77 -> V_10 [ V_9 ] > V_74 )
V_74 = V_77 -> V_10 [ V_9 ] ;
V_9 ++ ;
}
for ( V_4 = 2 ; V_4 < V_9 ; V_4 ++ ) {
if ( V_77 -> V_10 [ V_4 ] == V_77 -> V_10 [ 0 ] )
V_80 ++ ;
if ( V_77 -> V_10 [ V_4 ] == V_77 -> V_10 [ 1 ] )
V_80 ++ ;
}
if ( V_80 < 2 ) {
V_80 = 2 - V_80 ;
V_77 -> V_50 . V_91 = 1 ;
for ( V_4 = ( V_9 - 1 + V_80 ) ; V_4 >= 2 ; V_4 -- )
V_77 -> V_10 [ V_4 ] = V_77 -> V_10 [ V_4 - V_80 ] ;
V_9 += V_80 ;
} else if ( V_80 > 2 )
F_18 ( ( V_35 , L_17 ) ) ;
if ( V_74 == V_77 -> V_10 [ 2 ] ) {
V_77 -> V_50 . V_52 = 1 ;
F_35 ( & V_77 -> V_10 [ 2 ] , V_9 - 2 , sizeof( V_77 -> V_10 [ 2 ] ) ,
F_29 , NULL ) ;
} else if ( V_74 != V_77 -> V_10 [ V_9 - 1 ] )
F_18 ( ( V_35 ,
L_18 ) ) ;
V_77 -> V_9 = V_9 ;
V_18 -> V_8 = V_77 ;
V_77 -> V_37 = V_21 = V_74 ;
if ( ! V_18 -> V_55 . V_56 )
goto V_92;
V_78 = F_3 ( V_18 ,
& V_81 , true ) ;
if ( V_78 )
goto V_93;
V_78 = F_30 ( V_18 , V_74 , V_81 ) ;
if ( V_78 )
goto V_93;
if ( ! V_18 -> V_55 . V_56 )
goto V_92;
V_21 = F_24 ( V_18 , V_81 ) ;
for ( V_4 = 2 ; V_4 < V_77 -> V_9 ; V_4 ++ )
if ( V_21 == V_77 -> V_10 [ V_4 ] )
break;
if ( V_4 == V_77 -> V_9 || ! V_21 )
V_21 = V_74 ;
V_92:
V_78 = F_6 ( V_18 , V_21 ) ;
if ( V_78 )
goto V_93;
F_32 ( ( V_83 ,
L_19 , V_9 - 2 ) ) ;
F_15 ( V_28 ) ;
return V_78 ;
V_93:
F_15 ( V_77 -> V_10 ) ;
V_89:
F_15 ( V_77 ) ;
V_84:
V_18 -> V_8 = NULL ;
F_15 ( V_28 ) ;
return V_78 ;
}
static void F_36 ( struct V_5 * V_18 )
{
if ( F_37 ( V_18 -> V_29 -> V_30 , L_20 ) )
V_18 -> V_55 . V_94 = 1 ;
if ( F_37 ( V_18 -> V_29 -> V_30 , L_1 ) )
V_18 -> V_55 . V_95 = 1 ;
if ( F_37 ( V_18 -> V_29 -> V_30 , L_3 ) )
V_18 -> V_55 . V_96 = 1 ;
if ( F_37 ( V_18 -> V_29 -> V_30 , L_6 ) ) {
V_18 -> V_55 . V_56 = 1 ;
} else if ( F_37 ( V_18 -> V_29 -> V_30 , L_7 ) ) {
F_14 (KERN_WARNING FW_BUG L_21 ) ;
V_18 -> V_55 . V_57 = 1 ;
}
if ( F_37 ( V_18 -> V_29 -> V_30 , L_10 ) )
V_18 -> V_55 . V_97 = 1 ;
}
static void F_38 ( struct V_67 * V_20 )
{
if ( F_37 ( V_20 -> V_18 -> V_30 , L_12 ) )
V_20 -> V_55 . V_70 = 1 ;
if ( F_37 ( V_20 -> V_18 -> V_30 , L_22 ) )
V_20 -> V_55 . V_98 = 1 ;
if ( F_37 ( V_20 -> V_18 -> V_30 , L_23 ) )
V_20 -> V_55 . V_99 = 1 ;
if ( F_37 ( V_20 -> V_18 -> V_30 , L_24 ) )
V_20 -> V_55 . V_100 = 1 ;
if ( F_37 ( V_20 -> V_18 -> V_30 , L_25 ) )
V_20 -> V_55 . V_101 = 1 ;
if ( F_37 ( V_20 -> V_18 -> V_30 , L_26 ) )
V_20 -> V_55 . V_102 = 1 ;
}
static int F_39 ( struct V_67 * V_20 )
{
T_1 V_24 = - V_103 ;
struct V_104 * V_29 ;
if ( ! V_20 )
return - V_7 ;
V_29 = F_40 ( V_20 -> V_18 -> V_30 ) ;
if ( ! V_29 )
return - V_64 ;
F_41 ( V_29 ) ;
if ( V_20 -> V_55 . V_70 || V_20 -> V_55 . V_98 ) {
if ( ! V_20 -> V_55 . V_70 ) {
F_14 (KERN_WARNING FW_BUG
L_27 ,
acpi_device_bid(video->device)) ;
}
V_20 -> V_50 . V_105 = 1 ;
V_24 = 0 ;
}
if ( V_20 -> V_55 . V_99 ) {
V_20 -> V_50 . V_106 = 1 ;
V_24 = 0 ;
}
if ( V_20 -> V_55 . V_100 && V_20 -> V_55 . V_101 && V_20 -> V_55 . V_102 ) {
V_20 -> V_50 . V_107 = 1 ;
V_24 = 0 ;
}
return V_24 ;
}
static struct V_108 *
F_42 ( struct V_67 * V_20 , unsigned long V_109 )
{
struct V_110 * V_111 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_112 ; V_4 ++ ) {
V_111 = & V_20 -> V_113 [ V_4 ] ;
if ( ( V_111 -> V_65 . V_114 & 0xffff ) == V_109 )
return & V_111 -> V_65 . V_115 ;
}
return NULL ;
}
static int
F_43 ( struct V_67 * V_20 ,
unsigned long V_109 )
{
struct V_110 * V_111 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_112 ; V_4 ++ ) {
V_111 = & V_20 -> V_113 [ V_4 ] ;
if ( ( V_111 -> V_65 . V_114 & 0xffff ) == V_109 )
return V_111 -> V_65 . V_114 ;
}
return 0 ;
}
static int
F_44 ( struct V_17 * V_18 ,
struct V_67 * V_20 )
{
unsigned long long V_109 ;
int V_24 , V_116 ;
struct V_5 * V_117 ;
struct V_108 * V_118 ;
V_24 =
F_25 ( V_18 -> V_30 , L_20 , NULL , & V_109 ) ;
if ( F_17 ( V_24 ) )
return 0 ;
V_117 = F_33 ( sizeof( struct V_5 ) , V_86 ) ;
if ( ! V_117 )
return - V_88 ;
strcpy ( F_45 ( V_18 ) , V_119 ) ;
strcpy ( F_46 ( V_18 ) , V_120 ) ;
V_18 -> V_48 = V_117 ;
V_117 -> V_109 = V_109 ;
V_117 -> V_20 = V_20 ;
V_117 -> V_29 = V_18 ;
F_47 ( & V_117 -> V_13 ,
V_121 ) ;
V_118 = F_42 ( V_20 , V_109 ) ;
if ( V_118 && ( V_118 -> V_43 || V_43 ) ) {
switch ( V_118 -> V_122 ) {
case V_123 :
V_117 -> V_50 . V_124 = 1 ;
break;
case V_125 :
V_117 -> V_50 . V_126 = 1 ;
break;
case V_127 :
V_117 -> V_50 . V_128 = 1 ;
break;
case V_129 :
V_117 -> V_50 . V_130 = 1 ;
break;
default:
V_117 -> V_50 . V_131 = 1 ;
break;
}
if ( V_118 -> V_132 )
V_117 -> V_50 . V_133 = 1 ;
} else {
V_116 = F_43 ( V_20 , V_109 ) ;
switch ( V_116 & 0xffe2ffff ) {
case V_134 :
V_117 -> V_50 . V_124 = 1 ;
break;
case V_135 :
V_117 -> V_50 . V_130 = 1 ;
break;
case V_136 :
V_117 -> V_50 . V_126 = 1 ;
break;
default:
V_117 -> V_50 . V_131 = 1 ;
}
}
F_48 ( V_20 , V_117 ) ;
F_36 ( V_117 ) ;
F_49 ( & V_20 -> V_137 ) ;
F_50 ( & V_117 -> V_138 , & V_20 -> V_139 ) ;
F_51 ( & V_20 -> V_137 ) ;
return V_24 ;
}
static void F_52 ( struct V_67 * V_20 )
{
struct V_5 * V_29 ;
F_49 ( & V_20 -> V_137 ) ;
F_53 (dev, &video->video_device_list, entry)
F_48 ( V_20 , V_29 ) ;
F_51 ( & V_20 -> V_137 ) ;
}
static void
F_48 ( struct V_67 * V_20 ,
struct V_5 * V_18 )
{
struct V_110 * V_111 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_112 ; V_4 ++ ) {
V_111 = & V_20 -> V_113 [ V_4 ] ;
if ( V_18 -> V_109 == ( V_111 -> V_65 . V_114 & 0xffff ) ) {
V_111 -> V_140 = V_18 ;
F_32 ( ( V_83 , L_28 , V_4 ) ) ;
}
}
}
static bool F_54 ( struct V_5 * V_18 )
{
struct V_67 * V_20 = V_18 -> V_20 ;
int V_4 ;
if ( ! V_20 -> V_112 || V_20 -> V_141 > 8 )
return true ;
for ( V_4 = 0 ; V_4 < V_20 -> V_112 ; V_4 ++ ) {
if ( ( V_20 -> V_113 [ V_4 ] . V_65 . V_114 & 0xfff ) ==
( V_18 -> V_109 & 0xfff ) )
return true ;
}
return false ;
}
static int F_55 ( struct V_67 * V_20 )
{
int V_24 ;
int V_9 ;
int V_4 ;
struct V_110 * V_142 ;
struct V_25 V_26 = { V_27 , NULL } ;
union V_23 * V_143 = NULL ;
union V_23 * V_28 ;
V_24 = F_12 ( V_20 -> V_18 -> V_30 , L_22 , NULL , & V_26 ) ;
if ( ! F_13 ( V_24 ) ) {
F_56 ( ( V_35 , V_24 , L_29 ) ) ;
return V_24 ;
}
V_143 = V_26 . V_31 ;
if ( ! V_143 || ( V_143 -> type != V_32 ) ) {
F_56 ( ( V_35 , V_24 , L_30 ) ) ;
V_24 = - V_33 ;
goto V_84;
}
F_32 ( ( V_83 , L_31 ,
V_143 -> V_85 . V_9 ) ) ;
V_142 = F_57 ( 1 + V_143 -> V_85 . V_9 ,
sizeof( struct V_110 ) ,
V_86 ) ;
if ( ! V_142 ) {
V_24 = - V_88 ;
goto V_84;
}
V_9 = 0 ;
for ( V_4 = 0 ; V_4 < V_143 -> V_85 . V_9 ; V_4 ++ ) {
V_28 = & V_143 -> V_85 . V_90 [ V_4 ] ;
if ( V_28 -> type != V_62 ) {
F_14 (KERN_ERR PREFIX
L_32 , i) ;
continue;
}
V_142 [ V_9 ] . V_65 . V_114 = V_28 -> integer . V_65 ;
V_142 [ V_9 ] . V_140 = NULL ;
F_32 ( ( V_83 , L_33 , V_4 ,
( int ) V_28 -> integer . V_65 ) ) ;
V_9 ++ ;
}
F_15 ( V_20 -> V_113 ) ;
V_20 -> V_113 = V_142 ;
V_20 -> V_112 = V_9 ;
V_84:
F_15 ( V_26 . V_31 ) ;
return V_24 ;
}
static int
F_58 ( struct V_5 * V_18 ,
T_3 V_144 , T_3 V_145 )
{
int V_146 , V_147 , V_148 , V_149 , V_4 , V_150 , V_151 = 255 ;
V_147 = V_149 = 0 ;
V_146 = V_148 = 255 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_150 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( abs ( V_150 - V_144 ) < abs ( V_151 ) ) {
V_151 = V_150 - V_144 ;
if ( ! V_151 )
break;
}
}
V_144 += V_151 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_150 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( V_150 < V_146 )
V_146 = V_150 ;
if ( V_150 > V_147 )
V_147 = V_150 ;
if ( V_150 < V_148 && V_150 > V_144 )
V_148 = V_150 ;
if ( V_150 > V_149 && V_150 < V_144 )
V_149 = V_150 ;
}
switch ( V_145 ) {
case V_152 :
return ( V_144 < V_147 ) ? V_148 : V_146 ;
case V_153 :
return ( V_144 < V_147 ) ? V_148 : V_147 ;
case V_154 :
return ( V_144 > V_146 ) ? V_149 : V_146 ;
case V_155 :
case V_156 :
return 0 ;
default:
return V_144 ;
}
}
static void
V_121 ( struct V_157 * V_158 )
{
struct V_5 * V_18 = F_59 ( F_60 ( V_158 ) ,
struct V_5 , V_13 ) ;
unsigned long long V_144 , V_159 ;
int V_145 = V_18 -> V_160 ;
int V_78 = - V_7 ;
if ( ! V_18 -> V_38 )
return;
if ( ! V_18 -> V_8 )
goto V_84;
V_78 = F_3 ( V_18 ,
& V_144 ,
false ) ;
if ( V_78 )
goto V_84;
V_159 = F_58 ( V_18 , V_144 , V_145 ) ;
V_78 = F_6 ( V_18 , V_159 ) ;
if ( ! V_78 )
F_61 ( V_18 -> V_38 ,
V_161 ) ;
V_84:
if ( V_78 )
F_14 (KERN_ERR PREFIX L_34 ) ;
}
int F_62 ( struct V_17 * V_18 , int type , int V_109 ,
void * * V_59 )
{
struct V_67 * V_20 ;
struct V_5 * V_162 ;
union V_23 * V_26 = NULL ;
T_1 V_24 ;
int V_4 , V_60 ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_112 ; V_4 ++ ) {
V_162 = V_20 -> V_113 [ V_4 ] . V_140 ;
V_60 = 256 ;
if ( ! V_162 )
continue;
if ( ! V_162 -> V_55 . V_97 )
continue;
if ( type ) {
switch ( type ) {
case V_123 :
if ( ! V_162 -> V_50 . V_124 )
continue;
break;
case V_125 :
if ( ! V_162 -> V_50 . V_126 )
continue;
break;
case V_127 :
if ( ! V_162 -> V_50 . V_128 )
continue;
break;
case V_129 :
if ( ! V_162 -> V_50 . V_130 )
continue;
break;
}
} else if ( V_162 -> V_109 != V_109 ) {
continue;
}
V_24 = F_27 ( V_162 , & V_26 , V_60 ) ;
if ( F_17 ( V_24 ) || ! V_26 ||
V_26 -> type != V_66 ) {
V_60 = 128 ;
V_24 = F_27 ( V_162 , & V_26 ,
V_60 ) ;
if ( F_17 ( V_24 ) || ! V_26 ||
V_26 -> type != V_66 ) {
continue;
}
}
* V_59 = V_26 -> V_26 . V_31 ;
return V_60 ;
}
return - V_64 ;
}
static int
F_63 ( struct V_67 * V_20 ,
struct V_17 * V_18 )
{
int V_24 = 0 ;
struct V_17 * V_29 ;
F_55 ( V_20 ) ;
F_53 (dev, &device->children, node) {
V_24 = F_44 ( V_29 , V_20 ) ;
if ( V_24 ) {
F_64 ( & V_29 -> V_29 , L_35 ) ;
break;
}
V_20 -> V_141 ++ ;
}
return V_24 ;
}
static int F_65 ( struct V_67 * V_20 )
{
return F_28 ( V_20 , 0 ,
F_66 () ? 1 : 0 ) ;
}
static int F_67 ( struct V_67 * V_20 )
{
return F_28 ( V_20 , 0 ,
F_66 () ? 0 : 1 ) ;
}
static void F_68 ( struct V_17 * V_18 , T_3 V_145 )
{
struct V_67 * V_20 = F_8 ( V_18 ) ;
struct V_163 * V_164 ;
int V_165 = 0 ;
if ( ! V_20 || ! V_20 -> V_164 )
return;
V_164 = V_20 -> V_164 ;
switch ( V_145 ) {
case V_166 :
V_165 = V_167 ;
break;
case V_168 :
F_55 ( V_20 ) ;
F_52 ( V_20 ) ;
V_165 = V_167 ;
break;
case V_169 :
V_165 = V_167 ;
break;
case V_170 :
V_165 = V_171 ;
break;
case V_172 :
V_165 = V_173 ;
break;
default:
F_32 ( ( V_83 ,
L_36 , V_145 ) ) ;
break;
}
if ( F_69 ( V_18 , V_145 , 0 ) )
V_165 = 0 ;
if ( V_165 && ( V_46 & V_174 ) ) {
F_70 ( V_164 , V_165 , 1 ) ;
F_71 ( V_164 ) ;
F_70 ( V_164 , V_165 , 0 ) ;
F_71 ( V_164 ) ;
}
return;
}
static void F_72 ( struct V_5 * V_162 ,
T_3 V_145 )
{
if ( ! V_175 )
return;
V_162 -> V_160 = V_145 ;
F_73 ( & V_162 -> V_13 , V_176 / 10 ) ;
}
static void F_74 ( T_4 V_30 , T_3 V_145 , void * V_117 )
{
struct V_5 * V_162 = V_117 ;
struct V_17 * V_18 = NULL ;
struct V_67 * V_177 ;
struct V_163 * V_164 ;
int V_165 = 0 ;
if ( ! V_162 )
return;
V_18 = V_162 -> V_29 ;
V_177 = V_162 -> V_20 ;
V_164 = V_177 -> V_164 ;
switch ( V_145 ) {
case V_152 :
F_72 ( V_162 , V_145 ) ;
V_165 = V_178 ;
break;
case V_153 :
F_72 ( V_162 , V_145 ) ;
V_165 = V_179 ;
break;
case V_154 :
F_72 ( V_162 , V_145 ) ;
V_165 = V_180 ;
break;
case V_155 :
F_72 ( V_162 , V_145 ) ;
V_165 = V_181 ;
break;
case V_156 :
F_72 ( V_162 , V_145 ) ;
V_165 = V_182 ;
break;
default:
F_32 ( ( V_83 ,
L_36 , V_145 ) ) ;
break;
}
F_69 ( V_18 , V_145 , 0 ) ;
if ( V_165 && ( V_46 & V_183 ) ) {
F_70 ( V_164 , V_165 , 1 ) ;
F_71 ( V_164 ) ;
F_70 ( V_164 , V_165 , 0 ) ;
F_71 ( V_164 ) ;
}
return;
}
static int F_75 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
struct V_67 * V_20 ;
struct V_5 * V_162 ;
int V_4 ;
switch ( V_186 ) {
case V_188 :
case V_189 :
case V_190 :
return V_191 ;
}
V_20 = F_59 ( V_185 , struct V_67 , V_192 ) ;
F_76 ( & V_20 -> V_18 -> V_29 , L_37 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_112 ; V_4 ++ ) {
V_162 = V_20 -> V_113 [ V_4 ] . V_140 ;
if ( V_162 && V_162 -> V_8 )
F_6 ( V_162 ,
V_162 -> V_8 -> V_37 ) ;
}
return V_193 ;
}
static T_1
F_77 ( T_4 V_30 , T_3 V_21 , void * V_194 ,
void * * V_195 )
{
struct V_17 * V_18 = V_194 ;
struct V_17 * V_196 ;
int V_78 ;
if ( V_30 == V_18 -> V_30 )
return V_197 ;
V_78 = F_78 ( V_30 , & V_196 ) ;
if ( V_78 )
return V_54 ;
if ( ! strcmp ( F_45 ( V_196 ) , V_198 ) )
return V_199 ;
return V_54 ;
}
static void F_79 ( struct V_5 * V_18 )
{
struct V_200 V_12 ;
struct V_104 * V_201 ;
T_4 V_202 ;
struct V_18 * V_203 = NULL ;
int V_78 ;
static int V_9 ;
char * V_204 ;
V_78 = F_31 ( V_18 ) ;
if ( V_78 )
return;
if ( V_42 > 0 )
return;
V_204 = F_80 ( V_86 , L_38 , V_9 ) ;
if ( ! V_204 )
return;
V_9 ++ ;
F_81 ( V_18 -> V_29 -> V_30 , & V_202 ) ;
V_201 = F_40 ( V_202 ) ;
if ( V_201 ) {
V_203 = & V_201 -> V_29 ;
F_41 ( V_201 ) ;
}
memset ( & V_12 , 0 , sizeof( struct V_200 ) ) ;
V_12 . type = V_205 ;
V_12 . V_206 = V_18 -> V_8 -> V_9 - 3 ;
V_18 -> V_38 = F_82 ( V_204 ,
V_203 ,
V_18 ,
& V_207 ,
& V_12 ) ;
F_15 ( V_204 ) ;
if ( F_83 ( V_18 -> V_38 ) ) {
V_18 -> V_38 = NULL ;
return;
}
V_18 -> V_38 -> V_12 . V_8 =
F_1 ( V_18 -> V_38 ) ;
V_18 -> V_15 = F_84 ( L_39 ,
V_18 -> V_29 , & V_208 ) ;
if ( F_83 ( V_18 -> V_15 ) ) {
V_18 -> V_15 = NULL ;
return;
}
F_76 ( & V_18 -> V_29 -> V_29 , L_40 ,
V_18 -> V_15 -> V_45 ) ;
V_78 = F_85 ( & V_18 -> V_29 -> V_29 . V_209 ,
& V_18 -> V_15 -> V_18 . V_209 ,
L_41 ) ;
if ( V_78 )
F_14 (KERN_ERR PREFIX L_42 ) ;
V_78 = F_85 ( & V_18 -> V_15 -> V_18 . V_209 ,
& V_18 -> V_29 -> V_29 . V_209 , L_43 ) ;
if ( V_78 )
F_14 (KERN_ERR PREFIX L_42 ) ;
}
static void F_86 ( struct V_67 * V_20 )
{
struct V_5 * V_29 ;
union V_23 * V_10 ;
F_49 ( & V_20 -> V_137 ) ;
F_53 (dev, &video->video_device_list, entry) {
if ( ! F_11 ( V_29 , & V_10 ) )
F_15 ( V_10 ) ;
}
F_51 ( & V_20 -> V_137 ) ;
}
static bool F_87 ( struct V_5 * V_29 )
{
if ( ! F_54 ( V_29 ) ) {
F_88 ( & V_29 -> V_29 -> V_29 , L_44 ) ;
return false ;
}
if ( V_44 )
return V_29 -> V_50 . V_130 ;
return true ;
}
static int F_89 ( struct V_67 * V_20 )
{
struct V_5 * V_29 ;
if ( V_20 -> V_210 )
return 0 ;
F_86 ( V_20 ) ;
if ( F_90 () != V_211 )
return 0 ;
F_49 ( & V_20 -> V_137 ) ;
F_53 (dev, &video->video_device_list, entry) {
if ( F_87 ( V_29 ) )
F_79 ( V_29 ) ;
}
F_51 ( & V_20 -> V_137 ) ;
V_20 -> V_210 = true ;
V_20 -> V_192 . V_212 = F_75 ;
V_20 -> V_192 . V_213 = 0 ;
return F_91 ( & V_20 -> V_192 ) ;
}
static void F_92 ( struct V_5 * V_18 )
{
if ( V_18 -> V_38 ) {
F_93 ( V_18 -> V_38 ) ;
V_18 -> V_38 = NULL ;
}
if ( V_18 -> V_8 ) {
F_15 ( V_18 -> V_8 -> V_10 ) ;
F_15 ( V_18 -> V_8 ) ;
V_18 -> V_8 = NULL ;
}
if ( V_18 -> V_15 ) {
F_94 ( & V_18 -> V_29 -> V_29 . V_209 , L_41 ) ;
F_94 ( & V_18 -> V_15 -> V_18 . V_209 , L_43 ) ;
F_95 ( V_18 -> V_15 ) ;
V_18 -> V_15 = NULL ;
}
}
static int F_96 ( struct V_67 * V_20 )
{
struct V_5 * V_29 ;
int error ;
if ( ! V_20 -> V_210 )
return 0 ;
error = F_97 ( & V_20 -> V_192 ) ;
F_49 ( & V_20 -> V_137 ) ;
F_53 (dev, &video->video_device_list, entry)
F_92 ( V_29 ) ;
F_51 ( & V_20 -> V_137 ) ;
V_20 -> V_210 = false ;
return error ;
}
static void F_98 ( struct V_5 * V_18 )
{
T_1 V_24 ;
struct V_17 * V_214 = V_18 -> V_29 ;
V_24 = F_99 ( V_214 -> V_30 , V_215 ,
F_74 , V_18 ) ;
if ( F_17 ( V_24 ) )
F_64 ( & V_214 -> V_29 , L_45 ) ;
else
V_18 -> V_50 . V_216 = 1 ;
}
static int F_100 ( struct V_67 * V_20 )
{
struct V_163 * V_164 ;
struct V_5 * V_29 ;
int error ;
V_20 -> V_164 = V_164 = F_101 () ;
if ( ! V_164 ) {
error = - V_88 ;
goto V_84;
}
error = F_65 ( V_20 ) ;
if ( error )
goto V_217;
snprintf ( V_20 -> V_218 , sizeof( V_20 -> V_218 ) ,
L_46 , F_102 ( V_20 -> V_18 ) ) ;
V_164 -> V_204 = F_45 ( V_20 -> V_18 ) ;
V_164 -> V_218 = V_20 -> V_218 ;
V_164 -> V_45 . V_219 = V_220 ;
V_164 -> V_45 . V_221 = 0x06 ;
V_164 -> V_29 . V_203 = & V_20 -> V_18 -> V_29 ;
V_164 -> V_222 [ 0 ] = F_103 ( V_223 ) ;
F_104 ( V_167 , V_164 -> V_224 ) ;
F_104 ( V_171 , V_164 -> V_224 ) ;
F_104 ( V_173 , V_164 -> V_224 ) ;
F_104 ( V_178 , V_164 -> V_224 ) ;
F_104 ( V_179 , V_164 -> V_224 ) ;
F_104 ( V_180 , V_164 -> V_224 ) ;
F_104 ( V_181 , V_164 -> V_224 ) ;
F_104 ( V_182 , V_164 -> V_224 ) ;
error = F_105 ( V_164 ) ;
if ( error )
goto V_225;
F_49 ( & V_20 -> V_137 ) ;
F_53 (dev, &video->video_device_list, entry)
F_98 ( V_29 ) ;
F_51 ( & V_20 -> V_137 ) ;
return 0 ;
V_225:
F_67 ( V_20 ) ;
V_217:
F_106 ( V_164 ) ;
V_20 -> V_164 = NULL ;
V_84:
return error ;
}
static void F_107 ( struct V_5 * V_29 )
{
if ( V_29 -> V_50 . V_216 ) {
F_108 ( V_29 -> V_29 -> V_30 , V_215 ,
F_74 ) ;
V_29 -> V_50 . V_216 = 0 ;
}
}
static void F_109 ( struct V_67 * V_20 )
{
struct V_5 * V_29 ;
F_49 ( & V_20 -> V_137 ) ;
F_53 (dev, &video->video_device_list, entry)
F_107 ( V_29 ) ;
F_51 ( & V_20 -> V_137 ) ;
F_67 ( V_20 ) ;
F_110 ( V_20 -> V_164 ) ;
V_20 -> V_164 = NULL ;
}
static int F_111 ( struct V_67 * V_20 )
{
struct V_5 * V_29 , * V_226 ;
F_49 ( & V_20 -> V_137 ) ;
F_112 (dev, next, &video->video_device_list, entry) {
F_113 ( & V_29 -> V_138 ) ;
F_15 ( V_29 ) ;
}
F_51 ( & V_20 -> V_137 ) ;
return 0 ;
}
static int F_114 ( struct V_17 * V_18 )
{
struct V_67 * V_20 ;
int error ;
T_1 V_24 ;
V_24 = F_115 ( V_227 ,
V_18 -> V_203 -> V_30 , 1 ,
F_77 , NULL ,
V_18 , NULL ) ;
if ( V_24 == V_199 ) {
F_14 (KERN_WARNING FW_BUG
L_47
L_48
L_49
L_50 ) ;
if ( ! V_228 )
return - V_64 ;
}
V_20 = F_33 ( sizeof( struct V_67 ) , V_86 ) ;
if ( ! V_20 )
return - V_88 ;
if ( ! strcmp ( V_18 -> V_229 . V_230 , L_51 ) ) {
if ( V_231 )
V_18 -> V_229 . V_230 [ 3 ] = '0' + V_231 ;
V_231 ++ ;
}
if ( ! strcmp ( V_18 -> V_229 . V_230 , L_52 ) ) {
if ( V_231 )
V_18 -> V_229 . V_230 [ 3 ] = '0' + V_231 ;
V_231 ++ ;
}
V_20 -> V_18 = V_18 ;
strcpy ( F_45 ( V_18 ) , V_198 ) ;
strcpy ( F_46 ( V_18 ) , V_120 ) ;
V_18 -> V_48 = V_20 ;
F_38 ( V_20 ) ;
error = F_39 ( V_20 ) ;
if ( error )
goto V_232;
F_116 ( & V_20 -> V_137 ) ;
F_117 ( & V_20 -> V_139 ) ;
error = F_63 ( V_20 , V_18 ) ;
if ( error )
goto V_233;
F_14 (KERN_INFO PREFIX L_53 ,
ACPI_VIDEO_DEVICE_NAME, acpi_device_bid(device),
video->flags.multihead ? L_54 : L_55 ,
video->flags.rom ? L_54 : L_55 ,
video->flags.post ? L_54 : L_55 ) ;
F_49 ( & V_234 ) ;
F_50 ( & V_20 -> V_138 , & V_235 ) ;
F_51 ( & V_234 ) ;
F_89 ( V_20 ) ;
F_100 ( V_20 ) ;
return 0 ;
V_233:
F_111 ( V_20 ) ;
F_15 ( V_20 -> V_113 ) ;
V_232:
F_15 ( V_20 ) ;
V_18 -> V_48 = NULL ;
return error ;
}
static int F_118 ( struct V_17 * V_18 )
{
struct V_67 * V_20 = NULL ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
F_109 ( V_20 ) ;
F_96 ( V_20 ) ;
F_111 ( V_20 ) ;
F_49 ( & V_234 ) ;
F_113 ( & V_20 -> V_138 ) ;
F_51 ( & V_234 ) ;
F_15 ( V_20 -> V_113 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static int T_5 F_119 ( struct V_104 * V_29 )
{
if ( V_29 -> V_18 == 0x00D1 )
return 1 ;
if ( V_29 -> V_18 == 0x7000 )
return 1 ;
return 0 ;
}
static int T_5 F_120 ( void )
{
int V_236 = 0 ;
struct V_104 * V_29 = NULL ;
T_3 V_237 ;
F_121 (dev) {
if ( ( V_29 -> V_238 >> 8 ) != V_239 )
continue;
if ( V_29 -> V_240 != V_241 )
continue;
if ( F_119 ( V_29 ) )
continue;
F_122 ( V_29 , 0xfc , & V_237 ) ;
if ( ! V_237 )
continue;
V_236 = 1 ;
}
return V_236 ;
}
int F_123 ( void )
{
int V_242 = 0 ;
F_49 ( & V_243 ) ;
if ( V_244 ) {
goto V_245;
}
F_124 ( V_246 ) ;
V_242 = F_125 ( & V_67 ) ;
if ( V_242 )
goto V_245;
V_244 = 1 ;
V_245:
F_51 ( & V_243 ) ;
return V_242 ;
}
void F_126 ( void )
{
F_49 ( & V_243 ) ;
if ( V_244 ) {
F_127 ( & V_67 ) ;
V_244 = 0 ;
}
F_51 ( & V_243 ) ;
}
void F_128 ( void )
{
struct V_67 * V_20 ;
F_49 ( & V_243 ) ;
if ( V_244 ) {
F_49 ( & V_234 ) ;
F_53 (video, &video_bus_head, entry)
F_96 ( V_20 ) ;
F_51 ( & V_234 ) ;
}
F_51 ( & V_243 ) ;
}
bool F_129 ( void )
{
bool V_247 ;
F_49 ( & V_234 ) ;
V_247 = ! F_130 ( & V_235 ) ;
F_51 ( & V_234 ) ;
return V_247 &&
( V_46 & V_183 ) ;
}
static int T_5 F_131 ( void )
{
if ( V_248 )
return 0 ;
if ( F_120 () )
return 0 ;
return F_123 () ;
}
static void T_6 F_132 ( void )
{
F_133 () ;
F_126 () ;
return;
}
