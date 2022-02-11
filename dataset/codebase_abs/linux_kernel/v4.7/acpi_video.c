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
F_11 ( T_1 V_23 ,
union V_24 * * V_10 )
{
int V_25 ;
struct V_26 V_27 = { V_28 , NULL } ;
union V_24 * V_29 ;
* V_10 = NULL ;
V_25 = F_12 ( V_23 , L_1 , NULL , & V_27 ) ;
if ( ! F_13 ( V_25 ) )
return V_25 ;
V_29 = (union V_24 * ) V_27 . V_30 ;
if ( ! V_29 || ( V_29 -> type != V_31 ) ) {
F_14 (KERN_ERR PREFIX L_2 ) ;
V_25 = - V_32 ;
goto V_33;
}
* V_10 = V_29 ;
return 0 ;
V_33:
F_15 ( V_27 . V_30 ) ;
return V_25 ;
}
static int
F_6 ( struct V_5 * V_18 , int V_21 )
{
int V_25 ;
int V_16 ;
V_25 = F_16 ( V_18 -> V_34 -> V_23 ,
L_3 , V_21 ) ;
if ( F_17 ( V_25 ) ) {
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
T_2 V_25 = V_54 ;
int V_4 ;
if ( V_18 -> V_55 . V_56 || V_18 -> V_55 . V_57 ) {
char * V_58 = V_18 -> V_55 . V_56 ? L_6 : L_7 ;
V_25 = F_25 ( V_18 -> V_34 -> V_23 , V_58 ,
NULL , V_21 ) ;
if ( F_13 ( V_25 ) ) {
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
union V_24 * * V_59 , T_3 V_60 )
{
int V_25 ;
struct V_26 V_27 = { V_28 , NULL } ;
union V_24 * V_29 ;
union V_24 V_61 = { V_62 } ;
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
V_25 = F_12 ( V_18 -> V_34 -> V_23 , L_10 , & args , & V_27 ) ;
if ( F_17 ( V_25 ) )
return - V_64 ;
V_29 = V_27 . V_30 ;
if ( V_29 && V_29 -> type == V_66 )
* V_59 = V_29 ;
else {
F_14 (KERN_ERR PREFIX L_11 ) ;
V_25 = - V_32 ;
F_15 ( V_29 ) ;
}
return V_25 ;
}
static int
F_28 ( struct V_67 * V_20 , int V_68 , int V_69 )
{
T_2 V_25 ;
if ( ! V_20 -> V_55 . V_70 )
return 0 ;
if ( V_68 < 0 || V_68 > 3 || V_69 < 0 || V_69 > 1 )
return - V_7 ;
V_20 -> V_71 = ( V_69 << 2 ) | V_68 ;
V_25 = F_16 ( V_20 -> V_18 -> V_23 , L_12 ,
( V_69 << 2 ) | V_68 ) ;
if ( F_17 ( V_25 ) )
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
int F_31 ( struct V_17 * V_18 ,
struct V_76 * * V_80 ,
int * V_81 )
{
union V_24 * V_29 = NULL ;
int V_4 , V_74 = 0 , V_9 = 0 , V_82 = 0 ;
union V_24 * V_83 ;
struct V_76 * V_77 = NULL ;
int V_78 = 0 ;
T_4 V_65 ;
if ( ! F_13 ( F_11 ( V_18 -> V_23 ,
& V_29 ) ) ) {
F_32 ( ( V_84 , L_13
L_14 ) ) ;
V_78 = - V_64 ;
goto V_85;
}
if ( V_29 -> V_86 . V_9 < 2 ) {
V_78 = - V_7 ;
goto V_85;
}
V_77 = F_33 ( sizeof( * V_77 ) , V_87 ) ;
if ( ! V_77 ) {
F_14 ( V_88 L_15 ) ;
V_78 = - V_89 ;
goto V_85;
}
V_77 -> V_10 = F_34 ( ( V_29 -> V_86 . V_9 + 2 ) * sizeof *( V_77 -> V_10 ) ,
V_87 ) ;
if ( ! V_77 -> V_10 ) {
V_78 = - V_89 ;
goto V_90;
}
for ( V_4 = 0 ; V_4 < V_29 -> V_86 . V_9 ; V_4 ++ ) {
V_83 = (union V_24 * ) & V_29 -> V_86 . V_91 [ V_4 ] ;
if ( V_83 -> type != V_62 ) {
F_14 (KERN_ERR PREFIX L_16 ) ;
continue;
}
V_65 = ( T_4 ) V_83 -> integer . V_65 ;
if ( V_9 > 2 && V_77 -> V_10 [ V_9 - 1 ] == V_65 )
continue;
V_77 -> V_10 [ V_9 ] = V_65 ;
if ( V_77 -> V_10 [ V_9 ] > V_74 )
V_74 = V_77 -> V_10 [ V_9 ] ;
V_9 ++ ;
}
for ( V_4 = 2 ; V_4 < V_9 ; V_4 ++ ) {
if ( V_77 -> V_10 [ V_4 ] == V_77 -> V_10 [ 0 ] )
V_82 ++ ;
if ( V_77 -> V_10 [ V_4 ] == V_77 -> V_10 [ 1 ] )
V_82 ++ ;
}
if ( V_82 < 2 ) {
V_82 = 2 - V_82 ;
V_77 -> V_50 . V_92 = 1 ;
for ( V_4 = ( V_9 - 1 + V_82 ) ; V_4 >= 2 ; V_4 -- )
V_77 -> V_10 [ V_4 ] = V_77 -> V_10 [ V_4 - V_82 ] ;
V_9 += V_82 ;
} else if ( V_82 > 2 )
F_18 ( ( V_35 , L_17 ) ) ;
if ( V_74 == V_77 -> V_10 [ 2 ] ) {
V_77 -> V_50 . V_52 = 1 ;
F_35 ( & V_77 -> V_10 [ 2 ] , V_9 - 2 , sizeof( V_77 -> V_10 [ 2 ] ) ,
F_29 , NULL ) ;
} else if ( V_74 != V_77 -> V_10 [ V_9 - 1 ] )
F_18 ( ( V_35 ,
L_18 ) ) ;
V_77 -> V_9 = V_9 ;
* V_80 = V_77 ;
if ( V_81 )
* V_81 = V_74 ;
V_85:
F_15 ( V_29 ) ;
return V_78 ;
V_90:
F_15 ( V_77 ) ;
goto V_85;
}
static int
F_36 ( struct V_5 * V_18 )
{
int V_4 , V_74 = 0 ;
unsigned long long V_21 , V_93 ;
struct V_76 * V_77 = NULL ;
int V_78 = - V_7 ;
V_78 = F_31 ( V_18 -> V_34 , & V_77 , & V_74 ) ;
if ( V_78 )
return V_78 ;
V_18 -> V_8 = V_77 ;
V_77 -> V_37 = V_21 = V_74 ;
if ( ! V_18 -> V_55 . V_56 )
goto V_94;
V_78 = F_3 ( V_18 ,
& V_93 , true ) ;
if ( V_78 )
goto V_95;
V_78 = F_30 ( V_18 , V_74 , V_93 ) ;
if ( V_78 )
goto V_95;
if ( ! V_18 -> V_55 . V_56 )
goto V_94;
V_21 = F_24 ( V_18 , V_93 ) ;
for ( V_4 = 2 ; V_4 < V_77 -> V_9 ; V_4 ++ )
if ( V_21 == V_77 -> V_10 [ V_4 ] )
break;
if ( V_4 == V_77 -> V_9 || ! V_21 )
V_21 = V_74 ;
V_94:
V_78 = F_6 ( V_18 , V_21 ) ;
if ( V_78 )
goto V_95;
F_32 ( ( V_84 ,
L_19 , V_77 -> V_9 - 2 ) ) ;
return 0 ;
V_95:
F_15 ( V_77 -> V_10 ) ;
F_15 ( V_77 ) ;
V_18 -> V_8 = NULL ;
return V_78 ;
}
static void F_37 ( struct V_5 * V_18 )
{
if ( F_38 ( V_18 -> V_34 -> V_23 , L_20 ) )
V_18 -> V_55 . V_96 = 1 ;
if ( F_38 ( V_18 -> V_34 -> V_23 , L_1 ) )
V_18 -> V_55 . V_97 = 1 ;
if ( F_38 ( V_18 -> V_34 -> V_23 , L_3 ) )
V_18 -> V_55 . V_98 = 1 ;
if ( F_38 ( V_18 -> V_34 -> V_23 , L_6 ) ) {
V_18 -> V_55 . V_56 = 1 ;
} else if ( F_38 ( V_18 -> V_34 -> V_23 , L_7 ) ) {
F_14 (KERN_WARNING FW_BUG L_21 ) ;
V_18 -> V_55 . V_57 = 1 ;
}
if ( F_38 ( V_18 -> V_34 -> V_23 , L_10 ) )
V_18 -> V_55 . V_99 = 1 ;
}
static void F_39 ( struct V_67 * V_20 )
{
if ( F_38 ( V_20 -> V_18 -> V_23 , L_12 ) )
V_20 -> V_55 . V_70 = 1 ;
if ( F_38 ( V_20 -> V_18 -> V_23 , L_22 ) )
V_20 -> V_55 . V_100 = 1 ;
if ( F_38 ( V_20 -> V_18 -> V_23 , L_23 ) )
V_20 -> V_55 . V_101 = 1 ;
if ( F_38 ( V_20 -> V_18 -> V_23 , L_24 ) )
V_20 -> V_55 . V_102 = 1 ;
if ( F_38 ( V_20 -> V_18 -> V_23 , L_25 ) )
V_20 -> V_55 . V_103 = 1 ;
if ( F_38 ( V_20 -> V_18 -> V_23 , L_26 ) )
V_20 -> V_55 . V_104 = 1 ;
}
static int F_40 ( struct V_67 * V_20 )
{
T_2 V_25 = - V_105 ;
struct V_106 * V_34 ;
if ( ! V_20 )
return - V_7 ;
V_34 = F_41 ( V_20 -> V_18 -> V_23 ) ;
if ( ! V_34 )
return - V_64 ;
F_42 ( V_34 ) ;
if ( V_20 -> V_55 . V_70 || V_20 -> V_55 . V_100 ) {
if ( ! V_20 -> V_55 . V_70 ) {
F_14 (KERN_WARNING FW_BUG
L_27 ,
acpi_device_bid(video->device)) ;
}
V_20 -> V_50 . V_107 = 1 ;
V_25 = 0 ;
}
if ( V_20 -> V_55 . V_101 ) {
V_20 -> V_50 . V_108 = 1 ;
V_25 = 0 ;
}
if ( V_20 -> V_55 . V_102 && V_20 -> V_55 . V_103 && V_20 -> V_55 . V_104 ) {
V_20 -> V_50 . V_109 = 1 ;
V_25 = 0 ;
}
return V_25 ;
}
static struct V_110 *
F_43 ( struct V_67 * V_20 , unsigned long V_111 )
{
struct V_112 * V_113 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_114 ; V_4 ++ ) {
V_113 = & V_20 -> V_115 [ V_4 ] ;
if ( ( V_113 -> V_65 . V_116 & 0xffff ) == V_111 )
return & V_113 -> V_65 . V_117 ;
}
return NULL ;
}
static int
F_44 ( struct V_67 * V_20 ,
unsigned long V_111 )
{
struct V_112 * V_113 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_114 ; V_4 ++ ) {
V_113 = & V_20 -> V_115 [ V_4 ] ;
if ( ( V_113 -> V_65 . V_116 & 0xffff ) == V_111 )
return V_113 -> V_65 . V_116 ;
}
return 0 ;
}
static int
F_45 ( struct V_17 * V_18 ,
struct V_67 * V_20 )
{
unsigned long long V_111 ;
int V_25 , V_118 ;
struct V_5 * V_119 ;
struct V_110 * V_120 ;
V_25 =
F_25 ( V_18 -> V_23 , L_20 , NULL , & V_111 ) ;
if ( F_17 ( V_25 ) )
return 0 ;
V_119 = F_33 ( sizeof( struct V_5 ) , V_87 ) ;
if ( ! V_119 )
return - V_89 ;
strcpy ( F_46 ( V_18 ) , V_121 ) ;
strcpy ( F_47 ( V_18 ) , V_122 ) ;
V_18 -> V_48 = V_119 ;
V_119 -> V_111 = V_111 ;
V_119 -> V_20 = V_20 ;
V_119 -> V_34 = V_18 ;
F_48 ( & V_119 -> V_13 ,
V_123 ) ;
V_120 = F_43 ( V_20 , V_111 ) ;
if ( V_120 && ( V_120 -> V_43 || V_43 ) ) {
switch ( V_120 -> V_124 ) {
case V_125 :
V_119 -> V_50 . V_126 = 1 ;
break;
case V_127 :
V_119 -> V_50 . V_128 = 1 ;
break;
case V_129 :
V_119 -> V_50 . V_130 = 1 ;
break;
case V_131 :
V_119 -> V_50 . V_132 = 1 ;
break;
default:
V_119 -> V_50 . V_133 = 1 ;
break;
}
if ( V_120 -> V_134 )
V_119 -> V_50 . V_135 = 1 ;
} else {
V_118 = F_44 ( V_20 , V_111 ) ;
switch ( V_118 & 0xffe2ffff ) {
case V_136 :
V_119 -> V_50 . V_126 = 1 ;
break;
case V_137 :
V_119 -> V_50 . V_132 = 1 ;
break;
case V_138 :
V_119 -> V_50 . V_128 = 1 ;
break;
default:
V_119 -> V_50 . V_133 = 1 ;
}
}
F_49 ( V_20 , V_119 ) ;
F_37 ( V_119 ) ;
F_50 ( & V_20 -> V_139 ) ;
F_51 ( & V_119 -> V_140 , & V_20 -> V_141 ) ;
F_52 ( & V_20 -> V_139 ) ;
return V_25 ;
}
static void F_53 ( struct V_67 * V_20 )
{
struct V_5 * V_34 ;
F_50 ( & V_20 -> V_139 ) ;
F_54 (dev, &video->video_device_list, entry)
F_49 ( V_20 , V_34 ) ;
F_52 ( & V_20 -> V_139 ) ;
}
static void
F_49 ( struct V_67 * V_20 ,
struct V_5 * V_18 )
{
struct V_112 * V_113 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_114 ; V_4 ++ ) {
V_113 = & V_20 -> V_115 [ V_4 ] ;
if ( V_18 -> V_111 == ( V_113 -> V_65 . V_116 & 0xffff ) ) {
V_113 -> V_142 = V_18 ;
F_32 ( ( V_84 , L_28 , V_4 ) ) ;
}
}
}
static bool F_55 ( struct V_5 * V_18 )
{
struct V_67 * V_20 = V_18 -> V_20 ;
int V_4 ;
if ( ! V_20 -> V_114 || V_20 -> V_143 > 8 )
return true ;
for ( V_4 = 0 ; V_4 < V_20 -> V_114 ; V_4 ++ ) {
if ( ( V_20 -> V_115 [ V_4 ] . V_65 . V_116 & 0xfff ) ==
( V_18 -> V_111 & 0xfff ) )
return true ;
}
return false ;
}
static int F_56 ( struct V_67 * V_20 )
{
int V_25 ;
int V_9 ;
int V_4 ;
struct V_112 * V_144 ;
struct V_26 V_27 = { V_28 , NULL } ;
union V_24 * V_145 = NULL ;
union V_24 * V_29 ;
V_25 = F_12 ( V_20 -> V_18 -> V_23 , L_22 , NULL , & V_27 ) ;
if ( ! F_13 ( V_25 ) ) {
F_57 ( ( V_35 , V_25 , L_29 ) ) ;
return V_25 ;
}
V_145 = V_27 . V_30 ;
if ( ! V_145 || ( V_145 -> type != V_31 ) ) {
F_57 ( ( V_35 , V_25 , L_30 ) ) ;
V_25 = - V_32 ;
goto V_85;
}
F_32 ( ( V_84 , L_31 ,
V_145 -> V_86 . V_9 ) ) ;
V_144 = F_58 ( 1 + V_145 -> V_86 . V_9 ,
sizeof( struct V_112 ) ,
V_87 ) ;
if ( ! V_144 ) {
V_25 = - V_89 ;
goto V_85;
}
V_9 = 0 ;
for ( V_4 = 0 ; V_4 < V_145 -> V_86 . V_9 ; V_4 ++ ) {
V_29 = & V_145 -> V_86 . V_91 [ V_4 ] ;
if ( V_29 -> type != V_62 ) {
F_14 (KERN_ERR PREFIX
L_32 , i) ;
continue;
}
V_144 [ V_9 ] . V_65 . V_116 = V_29 -> integer . V_65 ;
V_144 [ V_9 ] . V_142 = NULL ;
F_32 ( ( V_84 , L_33 , V_4 ,
( int ) V_29 -> integer . V_65 ) ) ;
V_9 ++ ;
}
F_15 ( V_20 -> V_115 ) ;
V_20 -> V_115 = V_144 ;
V_20 -> V_114 = V_9 ;
V_85:
F_15 ( V_27 . V_30 ) ;
return V_25 ;
}
static int
F_59 ( struct V_5 * V_18 ,
T_4 V_146 , T_4 V_147 )
{
int V_148 , V_149 , V_150 , V_151 , V_4 , V_152 , V_153 = 255 ;
V_149 = V_151 = 0 ;
V_148 = V_150 = 255 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_152 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( abs ( V_152 - V_146 ) < abs ( V_153 ) ) {
V_153 = V_152 - V_146 ;
if ( ! V_153 )
break;
}
}
V_146 += V_153 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_152 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( V_152 < V_148 )
V_148 = V_152 ;
if ( V_152 > V_149 )
V_149 = V_152 ;
if ( V_152 < V_150 && V_152 > V_146 )
V_150 = V_152 ;
if ( V_152 > V_151 && V_152 < V_146 )
V_151 = V_152 ;
}
switch ( V_147 ) {
case V_154 :
return ( V_146 < V_149 ) ? V_150 : V_148 ;
case V_155 :
return ( V_146 < V_149 ) ? V_150 : V_149 ;
case V_156 :
return ( V_146 > V_148 ) ? V_151 : V_148 ;
case V_157 :
case V_158 :
return 0 ;
default:
return V_146 ;
}
}
static void
V_123 ( struct V_159 * V_160 )
{
struct V_5 * V_18 = F_60 ( F_61 ( V_160 ) ,
struct V_5 , V_13 ) ;
unsigned long long V_146 , V_161 ;
int V_147 = V_18 -> V_162 ;
int V_78 = - V_7 ;
if ( ! V_18 -> V_38 )
return;
if ( ! V_18 -> V_8 )
goto V_85;
V_78 = F_3 ( V_18 ,
& V_146 ,
false ) ;
if ( V_78 )
goto V_85;
V_161 = F_59 ( V_18 , V_146 , V_147 ) ;
V_78 = F_6 ( V_18 , V_161 ) ;
if ( ! V_78 )
F_62 ( V_18 -> V_38 ,
V_163 ) ;
V_85:
if ( V_78 )
F_14 (KERN_ERR PREFIX L_34 ) ;
}
int F_63 ( struct V_17 * V_18 , int type , int V_111 ,
void * * V_59 )
{
struct V_67 * V_20 ;
struct V_5 * V_164 ;
union V_24 * V_27 = NULL ;
T_2 V_25 ;
int V_4 , V_60 ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_114 ; V_4 ++ ) {
V_164 = V_20 -> V_115 [ V_4 ] . V_142 ;
V_60 = 256 ;
if ( ! V_164 )
continue;
if ( ! V_164 -> V_55 . V_99 )
continue;
if ( type ) {
switch ( type ) {
case V_125 :
if ( ! V_164 -> V_50 . V_126 )
continue;
break;
case V_127 :
if ( ! V_164 -> V_50 . V_128 )
continue;
break;
case V_129 :
if ( ! V_164 -> V_50 . V_130 )
continue;
break;
case V_131 :
if ( ! V_164 -> V_50 . V_132 )
continue;
break;
}
} else if ( V_164 -> V_111 != V_111 ) {
continue;
}
V_25 = F_27 ( V_164 , & V_27 , V_60 ) ;
if ( F_17 ( V_25 ) || ! V_27 ||
V_27 -> type != V_66 ) {
V_60 = 128 ;
V_25 = F_27 ( V_164 , & V_27 ,
V_60 ) ;
if ( F_17 ( V_25 ) || ! V_27 ||
V_27 -> type != V_66 ) {
continue;
}
}
* V_59 = V_27 -> V_27 . V_30 ;
return V_60 ;
}
return - V_64 ;
}
static int
F_64 ( struct V_67 * V_20 ,
struct V_17 * V_18 )
{
int V_25 = 0 ;
struct V_17 * V_34 ;
F_56 ( V_20 ) ;
F_54 (dev, &device->children, node) {
V_25 = F_45 ( V_34 , V_20 ) ;
if ( V_25 ) {
F_65 ( & V_34 -> V_34 , L_35 ) ;
break;
}
V_20 -> V_143 ++ ;
}
return V_25 ;
}
static int F_66 ( struct V_67 * V_20 )
{
return F_28 ( V_20 , 0 ,
F_67 () ? 1 : 0 ) ;
}
static int F_68 ( struct V_67 * V_20 )
{
return F_28 ( V_20 , 0 ,
F_67 () ? 0 : 1 ) ;
}
static void F_69 ( struct V_17 * V_18 , T_4 V_147 )
{
struct V_67 * V_20 = F_8 ( V_18 ) ;
struct V_165 * V_166 ;
int V_167 = 0 ;
if ( ! V_20 || ! V_20 -> V_166 )
return;
V_166 = V_20 -> V_166 ;
switch ( V_147 ) {
case V_168 :
V_167 = V_169 ;
break;
case V_170 :
F_56 ( V_20 ) ;
F_53 ( V_20 ) ;
V_167 = V_169 ;
break;
case V_171 :
V_167 = V_169 ;
break;
case V_172 :
V_167 = V_173 ;
break;
case V_174 :
V_167 = V_175 ;
break;
default:
F_32 ( ( V_84 ,
L_36 , V_147 ) ) ;
break;
}
if ( F_70 ( V_18 , V_147 , 0 ) )
V_167 = 0 ;
if ( V_167 && ( V_46 & V_176 ) ) {
F_71 ( V_166 , V_167 , 1 ) ;
F_72 ( V_166 ) ;
F_71 ( V_166 , V_167 , 0 ) ;
F_72 ( V_166 ) ;
}
return;
}
static void F_73 ( struct V_5 * V_164 ,
T_4 V_147 )
{
if ( ! V_177 )
return;
V_164 -> V_162 = V_147 ;
F_74 ( & V_164 -> V_13 , V_178 / 10 ) ;
}
static void F_75 ( T_1 V_23 , T_4 V_147 , void * V_119 )
{
struct V_5 * V_164 = V_119 ;
struct V_17 * V_18 = NULL ;
struct V_67 * V_179 ;
struct V_165 * V_166 ;
int V_167 = 0 ;
if ( ! V_164 )
return;
V_18 = V_164 -> V_34 ;
V_179 = V_164 -> V_20 ;
V_166 = V_179 -> V_166 ;
switch ( V_147 ) {
case V_154 :
F_73 ( V_164 , V_147 ) ;
V_167 = V_180 ;
break;
case V_155 :
F_73 ( V_164 , V_147 ) ;
V_167 = V_181 ;
break;
case V_156 :
F_73 ( V_164 , V_147 ) ;
V_167 = V_182 ;
break;
case V_157 :
F_73 ( V_164 , V_147 ) ;
V_167 = V_183 ;
break;
case V_158 :
F_73 ( V_164 , V_147 ) ;
V_167 = V_184 ;
break;
default:
F_32 ( ( V_84 ,
L_36 , V_147 ) ) ;
break;
}
F_70 ( V_18 , V_147 , 0 ) ;
if ( V_167 && ( V_46 & V_185 ) ) {
F_71 ( V_166 , V_167 , 1 ) ;
F_72 ( V_166 ) ;
F_71 ( V_166 , V_167 , 0 ) ;
F_72 ( V_166 ) ;
}
return;
}
static int F_76 ( struct V_186 * V_187 ,
unsigned long V_188 , void * V_189 )
{
struct V_67 * V_20 ;
struct V_5 * V_164 ;
int V_4 ;
switch ( V_188 ) {
case V_190 :
case V_191 :
case V_192 :
return V_193 ;
}
V_20 = F_60 ( V_187 , struct V_67 , V_194 ) ;
F_77 ( & V_20 -> V_18 -> V_34 , L_37 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_114 ; V_4 ++ ) {
V_164 = V_20 -> V_115 [ V_4 ] . V_142 ;
if ( V_164 && V_164 -> V_8 )
F_6 ( V_164 ,
V_164 -> V_8 -> V_37 ) ;
}
return V_195 ;
}
static T_2
F_78 ( T_1 V_23 , T_4 V_21 , void * V_196 ,
void * * V_197 )
{
struct V_17 * V_18 = V_196 ;
struct V_17 * V_198 ;
int V_78 ;
if ( V_23 == V_18 -> V_23 )
return V_199 ;
V_78 = F_79 ( V_23 , & V_198 ) ;
if ( V_78 )
return V_54 ;
if ( ! strcmp ( F_46 ( V_198 ) , V_200 ) )
return V_201 ;
return V_54 ;
}
static void F_80 ( struct V_5 * V_18 )
{
struct V_202 V_12 ;
struct V_106 * V_203 ;
T_1 V_204 ;
struct V_18 * V_205 = NULL ;
int V_78 ;
static int V_9 ;
char * V_206 ;
V_78 = F_36 ( V_18 ) ;
if ( V_78 )
return;
if ( V_42 > 0 )
return;
V_206 = F_81 ( V_87 , L_38 , V_9 ) ;
if ( ! V_206 )
return;
V_9 ++ ;
F_82 ( V_18 -> V_34 -> V_23 , & V_204 ) ;
V_203 = F_41 ( V_204 ) ;
if ( V_203 ) {
V_205 = & V_203 -> V_34 ;
F_42 ( V_203 ) ;
}
memset ( & V_12 , 0 , sizeof( struct V_202 ) ) ;
V_12 . type = V_207 ;
V_12 . V_208 = V_18 -> V_8 -> V_9 - 3 ;
V_18 -> V_38 = F_83 ( V_206 ,
V_205 ,
V_18 ,
& V_209 ,
& V_12 ) ;
F_15 ( V_206 ) ;
if ( F_84 ( V_18 -> V_38 ) ) {
V_18 -> V_38 = NULL ;
return;
}
V_18 -> V_38 -> V_12 . V_8 =
F_1 ( V_18 -> V_38 ) ;
V_18 -> V_15 = F_85 ( L_39 ,
V_18 -> V_34 , & V_210 ) ;
if ( F_84 ( V_18 -> V_15 ) ) {
V_18 -> V_15 = NULL ;
return;
}
F_77 ( & V_18 -> V_34 -> V_34 , L_40 ,
V_18 -> V_15 -> V_45 ) ;
V_78 = F_86 ( & V_18 -> V_34 -> V_34 . V_211 ,
& V_18 -> V_15 -> V_18 . V_211 ,
L_41 ) ;
if ( V_78 )
F_14 (KERN_ERR PREFIX L_42 ) ;
V_78 = F_86 ( & V_18 -> V_15 -> V_18 . V_211 ,
& V_18 -> V_34 -> V_34 . V_211 , L_43 ) ;
if ( V_78 )
F_14 (KERN_ERR PREFIX L_42 ) ;
}
static void F_87 ( struct V_67 * V_20 )
{
struct V_5 * V_34 ;
union V_24 * V_10 ;
F_50 ( & V_20 -> V_139 ) ;
F_54 (dev, &video->video_device_list, entry) {
if ( ! F_11 ( V_34 -> V_34 -> V_23 , & V_10 ) )
F_15 ( V_10 ) ;
}
F_52 ( & V_20 -> V_139 ) ;
}
static bool F_88 ( struct V_5 * V_34 )
{
if ( ! F_55 ( V_34 ) ) {
F_89 ( & V_34 -> V_34 -> V_34 , L_44 ) ;
return false ;
}
if ( V_44 )
return V_34 -> V_50 . V_132 ;
return true ;
}
static int F_90 ( struct V_67 * V_20 )
{
struct V_5 * V_34 ;
if ( V_20 -> V_212 )
return 0 ;
F_87 ( V_20 ) ;
if ( F_91 () != V_213 )
return 0 ;
F_50 ( & V_20 -> V_139 ) ;
F_54 (dev, &video->video_device_list, entry) {
if ( F_88 ( V_34 ) )
F_80 ( V_34 ) ;
}
F_52 ( & V_20 -> V_139 ) ;
V_20 -> V_212 = true ;
V_20 -> V_194 . V_214 = F_76 ;
V_20 -> V_194 . V_215 = 0 ;
return F_92 ( & V_20 -> V_194 ) ;
}
static void F_93 ( struct V_5 * V_18 )
{
if ( V_18 -> V_38 ) {
F_94 ( V_18 -> V_38 ) ;
V_18 -> V_38 = NULL ;
}
if ( V_18 -> V_8 ) {
F_15 ( V_18 -> V_8 -> V_10 ) ;
F_15 ( V_18 -> V_8 ) ;
V_18 -> V_8 = NULL ;
}
if ( V_18 -> V_15 ) {
F_95 ( & V_18 -> V_34 -> V_34 . V_211 , L_41 ) ;
F_95 ( & V_18 -> V_15 -> V_18 . V_211 , L_43 ) ;
F_96 ( V_18 -> V_15 ) ;
V_18 -> V_15 = NULL ;
}
}
static int F_97 ( struct V_67 * V_20 )
{
struct V_5 * V_34 ;
int error ;
if ( ! V_20 -> V_212 )
return 0 ;
error = F_98 ( & V_20 -> V_194 ) ;
F_50 ( & V_20 -> V_139 ) ;
F_54 (dev, &video->video_device_list, entry)
F_93 ( V_34 ) ;
F_52 ( & V_20 -> V_139 ) ;
V_20 -> V_212 = false ;
return error ;
}
static void F_99 ( struct V_5 * V_18 )
{
T_2 V_25 ;
struct V_17 * V_216 = V_18 -> V_34 ;
V_25 = F_100 ( V_216 -> V_23 , V_217 ,
F_75 , V_18 ) ;
if ( F_17 ( V_25 ) )
F_65 ( & V_216 -> V_34 , L_45 ) ;
else
V_18 -> V_50 . V_218 = 1 ;
}
static int F_101 ( struct V_67 * V_20 )
{
struct V_165 * V_166 ;
struct V_5 * V_34 ;
int error ;
V_20 -> V_166 = V_166 = F_102 () ;
if ( ! V_166 ) {
error = - V_89 ;
goto V_85;
}
error = F_66 ( V_20 ) ;
if ( error )
goto V_219;
snprintf ( V_20 -> V_220 , sizeof( V_20 -> V_220 ) ,
L_46 , F_103 ( V_20 -> V_18 ) ) ;
V_166 -> V_206 = F_46 ( V_20 -> V_18 ) ;
V_166 -> V_220 = V_20 -> V_220 ;
V_166 -> V_45 . V_221 = V_222 ;
V_166 -> V_45 . V_223 = 0x06 ;
V_166 -> V_34 . V_205 = & V_20 -> V_18 -> V_34 ;
V_166 -> V_224 [ 0 ] = F_104 ( V_225 ) ;
F_105 ( V_169 , V_166 -> V_226 ) ;
F_105 ( V_173 , V_166 -> V_226 ) ;
F_105 ( V_175 , V_166 -> V_226 ) ;
F_105 ( V_180 , V_166 -> V_226 ) ;
F_105 ( V_181 , V_166 -> V_226 ) ;
F_105 ( V_182 , V_166 -> V_226 ) ;
F_105 ( V_183 , V_166 -> V_226 ) ;
F_105 ( V_184 , V_166 -> V_226 ) ;
error = F_106 ( V_166 ) ;
if ( error )
goto V_227;
F_50 ( & V_20 -> V_139 ) ;
F_54 (dev, &video->video_device_list, entry)
F_99 ( V_34 ) ;
F_52 ( & V_20 -> V_139 ) ;
return 0 ;
V_227:
F_68 ( V_20 ) ;
V_219:
F_107 ( V_166 ) ;
V_20 -> V_166 = NULL ;
V_85:
return error ;
}
static void F_108 ( struct V_5 * V_34 )
{
if ( V_34 -> V_50 . V_218 ) {
F_109 ( V_34 -> V_34 -> V_23 , V_217 ,
F_75 ) ;
V_34 -> V_50 . V_218 = 0 ;
}
}
static void F_110 ( struct V_67 * V_20 )
{
struct V_5 * V_34 ;
F_50 ( & V_20 -> V_139 ) ;
F_54 (dev, &video->video_device_list, entry)
F_108 ( V_34 ) ;
F_52 ( & V_20 -> V_139 ) ;
F_68 ( V_20 ) ;
F_111 ( V_20 -> V_166 ) ;
V_20 -> V_166 = NULL ;
}
static int F_112 ( struct V_67 * V_20 )
{
struct V_5 * V_34 , * V_228 ;
F_50 ( & V_20 -> V_139 ) ;
F_113 (dev, next, &video->video_device_list, entry) {
F_114 ( & V_34 -> V_140 ) ;
F_15 ( V_34 ) ;
}
F_52 ( & V_20 -> V_139 ) ;
return 0 ;
}
static int F_115 ( struct V_17 * V_18 )
{
struct V_67 * V_20 ;
int error ;
T_2 V_25 ;
V_25 = F_116 ( V_229 ,
V_18 -> V_205 -> V_23 , 1 ,
F_78 , NULL ,
V_18 , NULL ) ;
if ( V_25 == V_201 ) {
F_14 (KERN_WARNING FW_BUG
L_47
L_48
L_49
L_50 ) ;
if ( ! V_230 )
return - V_64 ;
}
V_20 = F_33 ( sizeof( struct V_67 ) , V_87 ) ;
if ( ! V_20 )
return - V_89 ;
if ( ! strcmp ( V_18 -> V_231 . V_232 , L_51 ) ) {
if ( V_233 )
V_18 -> V_231 . V_232 [ 3 ] = '0' + V_233 ;
V_233 ++ ;
}
if ( ! strcmp ( V_18 -> V_231 . V_232 , L_52 ) ) {
if ( V_233 )
V_18 -> V_231 . V_232 [ 3 ] = '0' + V_233 ;
V_233 ++ ;
}
V_20 -> V_18 = V_18 ;
strcpy ( F_46 ( V_18 ) , V_200 ) ;
strcpy ( F_47 ( V_18 ) , V_122 ) ;
V_18 -> V_48 = V_20 ;
F_39 ( V_20 ) ;
error = F_40 ( V_20 ) ;
if ( error )
goto V_234;
F_117 ( & V_20 -> V_139 ) ;
F_118 ( & V_20 -> V_141 ) ;
error = F_64 ( V_20 , V_18 ) ;
if ( error )
goto V_235;
F_14 (KERN_INFO PREFIX L_53 ,
ACPI_VIDEO_DEVICE_NAME, acpi_device_bid(device),
video->flags.multihead ? L_54 : L_55 ,
video->flags.rom ? L_54 : L_55 ,
video->flags.post ? L_54 : L_55 ) ;
F_50 ( & V_236 ) ;
F_51 ( & V_20 -> V_140 , & V_237 ) ;
F_52 ( & V_236 ) ;
F_90 ( V_20 ) ;
F_101 ( V_20 ) ;
return 0 ;
V_235:
F_112 ( V_20 ) ;
F_15 ( V_20 -> V_115 ) ;
V_234:
F_15 ( V_20 ) ;
V_18 -> V_48 = NULL ;
return error ;
}
static int F_119 ( struct V_17 * V_18 )
{
struct V_67 * V_20 = NULL ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
F_110 ( V_20 ) ;
F_97 ( V_20 ) ;
F_112 ( V_20 ) ;
F_50 ( & V_236 ) ;
F_114 ( & V_20 -> V_140 ) ;
F_52 ( & V_236 ) ;
F_15 ( V_20 -> V_115 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static int T_5 F_120 ( struct V_106 * V_34 )
{
if ( V_34 -> V_18 == 0x00D1 )
return 1 ;
if ( V_34 -> V_18 == 0x7000 )
return 1 ;
return 0 ;
}
static int T_5 F_121 ( void )
{
int V_238 = 0 ;
struct V_106 * V_34 = NULL ;
T_4 V_239 ;
F_122 (dev) {
if ( ( V_34 -> V_240 >> 8 ) != V_241 )
continue;
if ( V_34 -> V_242 != V_243 )
continue;
if ( F_120 ( V_34 ) )
continue;
F_123 ( V_34 , 0xfc , & V_239 ) ;
if ( ! V_239 )
continue;
V_238 = 1 ;
}
return V_238 ;
}
int F_124 ( void )
{
int V_244 = 0 ;
F_50 ( & V_245 ) ;
if ( V_246 ) {
goto V_247;
}
F_125 ( V_248 ) ;
V_244 = F_126 ( & V_67 ) ;
if ( V_244 )
goto V_247;
V_246 = 1 ;
V_247:
F_52 ( & V_245 ) ;
return V_244 ;
}
void F_127 ( void )
{
F_50 ( & V_245 ) ;
if ( V_246 ) {
F_128 ( & V_67 ) ;
V_246 = 0 ;
}
F_52 ( & V_245 ) ;
}
void F_129 ( void )
{
struct V_67 * V_20 ;
F_50 ( & V_245 ) ;
if ( V_246 ) {
F_50 ( & V_236 ) ;
F_54 (video, &video_bus_head, entry)
F_97 ( V_20 ) ;
F_52 ( & V_236 ) ;
}
F_52 ( & V_245 ) ;
}
bool F_130 ( void )
{
bool V_249 ;
F_50 ( & V_236 ) ;
V_249 = ! F_131 ( & V_237 ) ;
F_52 ( & V_236 ) ;
return V_249 &&
( V_46 & V_185 ) ;
}
static int T_5 F_132 ( void )
{
if ( V_250 )
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
