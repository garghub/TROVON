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
static unsigned long long
F_21 ( struct V_5 * V_18 ,
unsigned long long V_43 )
{
unsigned long long V_21 ;
if ( V_18 -> V_8 -> V_44 . V_45 ) {
if ( V_18 -> V_8 -> V_44 . V_46 )
V_43 = V_18 -> V_8 -> V_9 - 3 - V_43 ;
V_21 = V_18 -> V_8 -> V_10 [ V_43 + 2 ] ;
} else {
V_21 = V_43 ;
}
V_21 += V_41 ;
return V_21 ;
}
static int
F_3 ( struct V_5 * V_18 ,
unsigned long long * V_21 , bool V_47 )
{
T_1 V_24 = V_48 ;
int V_4 ;
if ( V_18 -> V_49 . V_50 || V_18 -> V_49 . V_51 ) {
char * V_52 = V_18 -> V_49 . V_50 ? L_6 : L_7 ;
V_24 = F_22 ( V_18 -> V_29 -> V_30 , V_52 ,
NULL , V_21 ) ;
if ( F_13 ( V_24 ) ) {
if ( V_47 ) {
return 0 ;
}
* V_21 = F_21 ( V_18 , * V_21 ) ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ )
if ( V_18 -> V_8 -> V_10 [ V_4 ] == * V_21 ) {
V_18 -> V_8 -> V_37 = * V_21 ;
return 0 ;
}
F_23 ( ( V_35 ,
L_8 ,
V_52 ) ) ;
V_18 -> V_49 . V_50 = V_18 -> V_49 . V_51 = 0 ;
} else {
F_23 ( ( V_35 , L_9 , V_52 ) ) ;
V_18 -> V_49 . V_50 = V_18 -> V_49 . V_51 = 0 ;
}
}
* V_21 = V_18 -> V_8 -> V_37 ;
return 0 ;
}
static int
F_24 ( struct V_5 * V_18 ,
union V_23 * * V_53 , T_2 V_54 )
{
int V_24 ;
struct V_25 V_26 = { V_27 , NULL } ;
union V_23 * V_28 ;
union V_23 V_55 = { V_56 } ;
struct V_57 args = { 1 , & V_55 } ;
* V_53 = NULL ;
if ( ! V_18 )
return - V_58 ;
if ( V_54 == 128 )
V_55 . integer . V_59 = 1 ;
else if ( V_54 == 256 )
V_55 . integer . V_59 = 2 ;
else
return - V_7 ;
V_24 = F_12 ( V_18 -> V_29 -> V_30 , L_10 , & args , & V_26 ) ;
if ( F_17 ( V_24 ) )
return - V_58 ;
V_28 = V_26 . V_31 ;
if ( V_28 && V_28 -> type == V_60 )
* V_53 = V_28 ;
else {
F_14 (KERN_ERR PREFIX L_11 ) ;
V_24 = - V_33 ;
F_15 ( V_28 ) ;
}
return V_24 ;
}
static int
F_25 ( struct V_61 * V_20 , int V_62 , int V_63 )
{
T_1 V_24 ;
if ( ! V_20 -> V_49 . V_64 )
return 0 ;
if ( V_62 < 0 || V_62 > 3 || V_63 < 0 || V_63 > 1 )
return - V_7 ;
V_20 -> V_65 = ( V_63 << 2 ) | V_62 ;
V_24 = F_16 ( V_20 -> V_18 -> V_30 , L_12 ,
( V_63 << 2 ) | V_62 ) ;
if ( F_17 ( V_24 ) )
return - V_36 ;
return 0 ;
}
static int
F_26 ( const void * V_66 , const void * V_67 )
{
return * ( int * ) V_66 - * ( int * ) V_67 ;
}
static int F_27 ( struct V_5 * V_18 ,
int V_68 , int V_69 )
{
struct V_70 * V_71 = V_18 -> V_8 ;
int V_72 ;
unsigned long long V_21 ;
int V_73 ;
if ( V_41 )
return 0 ;
V_73 = V_69 == V_68 ? V_71 -> V_10 [ 3 ] : V_68 ;
V_72 = F_6 ( V_18 , V_73 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_3 ( V_18 , & V_21 , true ) ;
if ( V_72 )
return V_72 ;
if ( V_21 != V_73 ) {
if ( V_21 < V_71 -> V_9 ) {
if ( V_71 -> V_44 . V_46 )
V_21 = V_71 -> V_9 - 3 - V_21 ;
if ( V_71 -> V_10 [ V_21 + 2 ] == V_73 )
V_71 -> V_44 . V_45 = 1 ;
}
if ( ! V_71 -> V_44 . V_45 )
V_18 -> V_49 . V_50 = V_18 -> V_49 . V_51 = 0 ;
}
return 0 ;
}
static int
F_28 ( struct V_5 * V_18 )
{
union V_23 * V_28 = NULL ;
int V_4 , V_68 = 0 , V_9 = 0 , V_74 = 0 ;
unsigned long long V_21 , V_75 ;
union V_23 * V_76 ;
struct V_70 * V_71 = NULL ;
int V_72 = - V_7 ;
T_3 V_59 ;
if ( ! F_13 ( F_11 ( V_18 , & V_28 ) ) ) {
F_29 ( ( V_77 , L_13
L_14 ) ) ;
goto V_78;
}
if ( V_28 -> V_79 . V_9 < 2 )
goto V_78;
V_71 = F_30 ( sizeof( * V_71 ) , V_80 ) ;
if ( ! V_71 ) {
F_14 ( V_81 L_15 ) ;
V_72 = - V_82 ;
goto V_78;
}
V_71 -> V_10 = F_31 ( ( V_28 -> V_79 . V_9 + 2 ) * sizeof *( V_71 -> V_10 ) ,
V_80 ) ;
if ( ! V_71 -> V_10 ) {
V_72 = - V_82 ;
goto V_83;
}
for ( V_4 = 0 ; V_4 < V_28 -> V_79 . V_9 ; V_4 ++ ) {
V_76 = (union V_23 * ) & V_28 -> V_79 . V_84 [ V_4 ] ;
if ( V_76 -> type != V_56 ) {
F_14 (KERN_ERR PREFIX L_16 ) ;
continue;
}
V_59 = ( T_3 ) V_76 -> integer . V_59 ;
if ( V_9 > 2 && V_71 -> V_10 [ V_9 - 1 ] == V_59 )
continue;
V_71 -> V_10 [ V_9 ] = V_59 ;
if ( V_71 -> V_10 [ V_9 ] > V_68 )
V_68 = V_71 -> V_10 [ V_9 ] ;
V_9 ++ ;
}
for ( V_4 = 2 ; V_4 < V_9 ; V_4 ++ ) {
if ( V_71 -> V_10 [ V_4 ] == V_71 -> V_10 [ 0 ] )
V_74 ++ ;
if ( V_71 -> V_10 [ V_4 ] == V_71 -> V_10 [ 1 ] )
V_74 ++ ;
}
if ( V_74 < 2 ) {
V_74 = 2 - V_74 ;
V_71 -> V_44 . V_85 = 1 ;
for ( V_4 = ( V_9 - 1 + V_74 ) ; V_4 >= 2 ; V_4 -- )
V_71 -> V_10 [ V_4 ] = V_71 -> V_10 [ V_4 - V_74 ] ;
V_9 += V_74 ;
} else if ( V_74 > 2 )
F_18 ( ( V_35 , L_17 ) ) ;
if ( V_68 == V_71 -> V_10 [ 2 ] ) {
V_71 -> V_44 . V_46 = 1 ;
F_32 ( & V_71 -> V_10 [ 2 ] , V_9 - 2 , sizeof( V_71 -> V_10 [ 2 ] ) ,
F_26 , NULL ) ;
} else if ( V_68 != V_71 -> V_10 [ V_9 - 1 ] )
F_18 ( ( V_35 ,
L_18 ) ) ;
V_71 -> V_9 = V_9 ;
V_18 -> V_8 = V_71 ;
V_71 -> V_37 = V_21 = V_68 ;
if ( ! V_18 -> V_49 . V_50 )
goto V_86;
V_72 = F_3 ( V_18 ,
& V_75 , true ) ;
if ( V_72 )
goto V_87;
V_72 = F_27 ( V_18 , V_68 , V_75 ) ;
if ( V_72 )
goto V_87;
if ( ! V_18 -> V_49 . V_50 )
goto V_86;
V_21 = F_21 ( V_18 , V_75 ) ;
for ( V_4 = 2 ; V_4 < V_71 -> V_9 ; V_4 ++ )
if ( V_21 == V_71 -> V_10 [ V_4 ] )
break;
if ( V_4 == V_71 -> V_9 || ! V_21 )
V_21 = V_68 ;
V_86:
V_72 = F_6 ( V_18 , V_21 ) ;
if ( V_72 )
goto V_87;
F_29 ( ( V_77 ,
L_19 , V_9 - 2 ) ) ;
F_15 ( V_28 ) ;
return V_72 ;
V_87:
F_15 ( V_71 -> V_10 ) ;
V_83:
F_15 ( V_71 ) ;
V_78:
V_18 -> V_8 = NULL ;
F_15 ( V_28 ) ;
return V_72 ;
}
static void F_33 ( struct V_5 * V_18 )
{
if ( F_34 ( V_18 -> V_29 -> V_30 , L_20 ) )
V_18 -> V_49 . V_88 = 1 ;
if ( F_34 ( V_18 -> V_29 -> V_30 , L_1 ) )
V_18 -> V_49 . V_89 = 1 ;
if ( F_34 ( V_18 -> V_29 -> V_30 , L_3 ) )
V_18 -> V_49 . V_90 = 1 ;
if ( F_34 ( V_18 -> V_29 -> V_30 , L_6 ) ) {
V_18 -> V_49 . V_50 = 1 ;
} else if ( F_34 ( V_18 -> V_29 -> V_30 , L_7 ) ) {
F_14 (KERN_WARNING FW_BUG L_21 ) ;
V_18 -> V_49 . V_51 = 1 ;
}
if ( F_34 ( V_18 -> V_29 -> V_30 , L_10 ) )
V_18 -> V_49 . V_91 = 1 ;
}
static void F_35 ( struct V_61 * V_20 )
{
if ( F_34 ( V_20 -> V_18 -> V_30 , L_12 ) )
V_20 -> V_49 . V_64 = 1 ;
if ( F_34 ( V_20 -> V_18 -> V_30 , L_22 ) )
V_20 -> V_49 . V_92 = 1 ;
if ( F_34 ( V_20 -> V_18 -> V_30 , L_23 ) )
V_20 -> V_49 . V_93 = 1 ;
if ( F_34 ( V_20 -> V_18 -> V_30 , L_24 ) )
V_20 -> V_49 . V_94 = 1 ;
if ( F_34 ( V_20 -> V_18 -> V_30 , L_25 ) )
V_20 -> V_49 . V_95 = 1 ;
if ( F_34 ( V_20 -> V_18 -> V_30 , L_26 ) )
V_20 -> V_49 . V_96 = 1 ;
}
static int F_36 ( struct V_61 * V_20 )
{
T_1 V_24 = - V_97 ;
struct V_98 * V_29 ;
if ( ! V_20 )
return - V_7 ;
V_29 = F_37 ( V_20 -> V_18 -> V_30 ) ;
if ( ! V_29 )
return - V_58 ;
F_38 ( V_29 ) ;
if ( V_20 -> V_49 . V_64 || V_20 -> V_49 . V_92 ) {
if ( ! V_20 -> V_49 . V_64 ) {
F_14 (KERN_WARNING FW_BUG
L_27 ,
acpi_device_bid(video->device)) ;
}
V_20 -> V_44 . V_99 = 1 ;
V_24 = 0 ;
}
if ( V_20 -> V_49 . V_93 ) {
V_20 -> V_44 . V_100 = 1 ;
V_24 = 0 ;
}
if ( V_20 -> V_49 . V_94 && V_20 -> V_49 . V_95 && V_20 -> V_49 . V_96 ) {
V_20 -> V_44 . V_101 = 1 ;
V_24 = 0 ;
}
return V_24 ;
}
static struct V_102 *
F_39 ( struct V_61 * V_20 , unsigned long V_103 )
{
struct V_104 * V_105 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_106 ; V_4 ++ ) {
V_105 = & V_20 -> V_107 [ V_4 ] ;
if ( ( V_105 -> V_59 . V_108 & 0xffff ) == V_103 )
return & V_105 -> V_59 . V_109 ;
}
return NULL ;
}
static int
F_40 ( struct V_61 * V_20 ,
unsigned long V_103 )
{
struct V_104 * V_105 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_106 ; V_4 ++ ) {
V_105 = & V_20 -> V_107 [ V_4 ] ;
if ( ( V_105 -> V_59 . V_108 & 0xffff ) == V_103 )
return V_105 -> V_59 . V_108 ;
}
return 0 ;
}
static int
F_41 ( struct V_17 * V_18 ,
struct V_61 * V_20 )
{
unsigned long long V_103 ;
int V_24 , V_110 ;
struct V_5 * V_111 ;
struct V_102 * V_112 ;
V_24 =
F_22 ( V_18 -> V_30 , L_20 , NULL , & V_103 ) ;
if ( F_17 ( V_24 ) )
return 0 ;
V_111 = F_30 ( sizeof( struct V_5 ) , V_80 ) ;
if ( ! V_111 )
return - V_82 ;
strcpy ( F_42 ( V_18 ) , V_113 ) ;
strcpy ( F_43 ( V_18 ) , V_114 ) ;
V_18 -> V_115 = V_111 ;
V_111 -> V_103 = V_103 ;
V_111 -> V_20 = V_20 ;
V_111 -> V_29 = V_18 ;
F_44 ( & V_111 -> V_13 ,
V_116 ) ;
V_112 = F_39 ( V_20 , V_103 ) ;
if ( V_112 && V_112 -> V_117 ) {
switch ( V_112 -> V_118 ) {
case V_119 :
V_111 -> V_44 . V_120 = 1 ;
break;
case V_121 :
V_111 -> V_44 . V_122 = 1 ;
break;
case V_123 :
V_111 -> V_44 . V_124 = 1 ;
break;
case V_125 :
V_111 -> V_44 . V_126 = 1 ;
break;
default:
V_111 -> V_44 . V_127 = 1 ;
break;
}
if ( V_112 -> V_128 )
V_111 -> V_44 . V_129 = 1 ;
} else {
V_110 = F_40 ( V_20 , V_103 ) ;
switch ( V_110 & 0xffe2ffff ) {
case V_130 :
V_111 -> V_44 . V_120 = 1 ;
break;
case V_131 :
V_111 -> V_44 . V_126 = 1 ;
break;
case V_132 :
V_111 -> V_44 . V_122 = 1 ;
break;
default:
V_111 -> V_44 . V_127 = 1 ;
}
}
F_45 ( V_20 , V_111 ) ;
F_33 ( V_111 ) ;
F_46 ( & V_20 -> V_133 ) ;
F_47 ( & V_111 -> V_134 , & V_20 -> V_135 ) ;
F_48 ( & V_20 -> V_133 ) ;
return V_24 ;
}
static void F_49 ( struct V_61 * V_20 )
{
struct V_5 * V_29 ;
F_46 ( & V_20 -> V_133 ) ;
F_50 (dev, &video->video_device_list, entry)
F_45 ( V_20 , V_29 ) ;
F_48 ( & V_20 -> V_133 ) ;
}
static void
F_45 ( struct V_61 * V_20 ,
struct V_5 * V_18 )
{
struct V_104 * V_105 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_106 ; V_4 ++ ) {
V_105 = & V_20 -> V_107 [ V_4 ] ;
if ( V_18 -> V_103 == ( V_105 -> V_59 . V_108 & 0xffff ) ) {
V_105 -> V_136 = V_18 ;
F_29 ( ( V_77 , L_28 , V_4 ) ) ;
}
}
}
static bool F_51 ( struct V_5 * V_18 )
{
struct V_61 * V_20 = V_18 -> V_20 ;
int V_4 ;
if ( ! V_20 -> V_106 || V_20 -> V_137 > 8 )
return true ;
for ( V_4 = 0 ; V_4 < V_20 -> V_106 ; V_4 ++ ) {
if ( ( V_20 -> V_107 [ V_4 ] . V_59 . V_108 & 0xfff ) ==
( V_18 -> V_103 & 0xfff ) )
return true ;
}
return false ;
}
static int F_52 ( struct V_61 * V_20 )
{
int V_24 ;
int V_9 ;
int V_4 ;
struct V_104 * V_138 ;
struct V_25 V_26 = { V_27 , NULL } ;
union V_23 * V_139 = NULL ;
union V_23 * V_28 ;
V_24 = F_12 ( V_20 -> V_18 -> V_30 , L_22 , NULL , & V_26 ) ;
if ( ! F_13 ( V_24 ) ) {
F_53 ( ( V_35 , V_24 , L_29 ) ) ;
return V_24 ;
}
V_139 = V_26 . V_31 ;
if ( ! V_139 || ( V_139 -> type != V_32 ) ) {
F_53 ( ( V_35 , V_24 , L_30 ) ) ;
V_24 = - V_33 ;
goto V_78;
}
F_29 ( ( V_77 , L_31 ,
V_139 -> V_79 . V_9 ) ) ;
V_138 = F_54 ( 1 + V_139 -> V_79 . V_9 ,
sizeof( struct V_104 ) ,
V_80 ) ;
if ( ! V_138 ) {
V_24 = - V_82 ;
goto V_78;
}
V_9 = 0 ;
for ( V_4 = 0 ; V_4 < V_139 -> V_79 . V_9 ; V_4 ++ ) {
V_28 = & V_139 -> V_79 . V_84 [ V_4 ] ;
if ( V_28 -> type != V_56 ) {
F_14 (KERN_ERR PREFIX
L_32 , i) ;
continue;
}
V_138 [ V_9 ] . V_59 . V_108 = V_28 -> integer . V_59 ;
V_138 [ V_9 ] . V_136 = NULL ;
F_29 ( ( V_77 , L_33 , V_4 ,
( int ) V_28 -> integer . V_59 ) ) ;
V_9 ++ ;
}
F_15 ( V_20 -> V_107 ) ;
V_20 -> V_107 = V_138 ;
V_20 -> V_106 = V_9 ;
V_78:
F_15 ( V_26 . V_31 ) ;
return V_24 ;
}
static int
F_55 ( struct V_5 * V_18 ,
T_3 V_140 , T_3 V_141 )
{
int V_142 , V_143 , V_144 , V_145 , V_4 , V_146 , V_147 = 255 ;
V_143 = V_145 = 0 ;
V_142 = V_144 = 255 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_146 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( abs ( V_146 - V_140 ) < abs ( V_147 ) ) {
V_147 = V_146 - V_140 ;
if ( ! V_147 )
break;
}
}
V_140 += V_147 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_146 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( V_146 < V_142 )
V_142 = V_146 ;
if ( V_146 > V_143 )
V_143 = V_146 ;
if ( V_146 < V_144 && V_146 > V_140 )
V_144 = V_146 ;
if ( V_146 > V_145 && V_146 < V_140 )
V_145 = V_146 ;
}
switch ( V_141 ) {
case V_148 :
return ( V_140 < V_143 ) ? V_144 : V_142 ;
case V_149 :
return ( V_140 < V_143 ) ? V_144 : V_143 ;
case V_150 :
return ( V_140 > V_142 ) ? V_145 : V_142 ;
case V_151 :
case V_152 :
return 0 ;
default:
return V_140 ;
}
}
static void
V_116 ( struct V_153 * V_154 )
{
struct V_5 * V_18 = F_56 ( F_57 ( V_154 ) ,
struct V_5 , V_13 ) ;
unsigned long long V_140 , V_155 ;
int V_141 = V_18 -> V_156 ;
int V_72 = - V_7 ;
if ( ! V_18 -> V_38 )
return;
if ( ! V_18 -> V_8 )
goto V_78;
V_72 = F_3 ( V_18 ,
& V_140 ,
false ) ;
if ( V_72 )
goto V_78;
V_155 = F_55 ( V_18 , V_140 , V_141 ) ;
V_72 = F_6 ( V_18 , V_155 ) ;
if ( ! V_72 )
F_58 ( V_18 -> V_38 ,
V_157 ) ;
V_78:
if ( V_72 )
F_14 (KERN_ERR PREFIX L_34 ) ;
}
int F_59 ( struct V_17 * V_18 , int type , int V_103 ,
void * * V_53 )
{
struct V_61 * V_20 ;
struct V_5 * V_158 ;
union V_23 * V_26 = NULL ;
T_1 V_24 ;
int V_4 , V_54 ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_106 ; V_4 ++ ) {
V_158 = V_20 -> V_107 [ V_4 ] . V_136 ;
V_54 = 256 ;
if ( ! V_158 )
continue;
if ( ! V_158 -> V_49 . V_91 )
continue;
if ( type ) {
switch ( type ) {
case V_119 :
if ( ! V_158 -> V_44 . V_120 )
continue;
break;
case V_121 :
if ( ! V_158 -> V_44 . V_122 )
continue;
break;
case V_123 :
if ( ! V_158 -> V_44 . V_124 )
continue;
break;
case V_125 :
if ( ! V_158 -> V_44 . V_126 )
continue;
break;
}
} else if ( V_158 -> V_103 != V_103 ) {
continue;
}
V_24 = F_24 ( V_158 , & V_26 , V_54 ) ;
if ( F_17 ( V_24 ) || ! V_26 ||
V_26 -> type != V_60 ) {
V_54 = 128 ;
V_24 = F_24 ( V_158 , & V_26 ,
V_54 ) ;
if ( F_17 ( V_24 ) || ! V_26 ||
V_26 -> type != V_60 ) {
continue;
}
}
* V_53 = V_26 -> V_26 . V_31 ;
return V_54 ;
}
return - V_58 ;
}
static int
F_60 ( struct V_61 * V_20 ,
struct V_17 * V_18 )
{
int V_24 = 0 ;
struct V_17 * V_29 ;
F_52 ( V_20 ) ;
F_50 (dev, &device->children, node) {
V_24 = F_41 ( V_29 , V_20 ) ;
if ( V_24 ) {
F_61 ( & V_29 -> V_29 , L_35 ) ;
break;
}
V_20 -> V_137 ++ ;
}
return V_24 ;
}
static int F_62 ( struct V_61 * V_20 )
{
return F_25 ( V_20 , 0 ,
F_63 () ? 1 : 0 ) ;
}
static int F_64 ( struct V_61 * V_20 )
{
return F_25 ( V_20 , 0 ,
F_63 () ? 0 : 1 ) ;
}
static void F_65 ( struct V_17 * V_18 , T_3 V_141 )
{
struct V_61 * V_20 = F_8 ( V_18 ) ;
struct V_159 * V_160 ;
int V_161 = 0 ;
if ( ! V_20 || ! V_20 -> V_160 )
return;
V_160 = V_20 -> V_160 ;
switch ( V_141 ) {
case V_162 :
V_161 = V_163 ;
break;
case V_164 :
F_52 ( V_20 ) ;
F_49 ( V_20 ) ;
V_161 = V_163 ;
break;
case V_165 :
V_161 = V_163 ;
break;
case V_166 :
V_161 = V_167 ;
break;
case V_168 :
V_161 = V_169 ;
break;
default:
F_29 ( ( V_77 ,
L_36 , V_141 ) ) ;
break;
}
if ( F_66 ( V_18 , V_141 , 0 ) )
V_161 = 0 ;
if ( V_161 ) {
F_67 ( V_160 , V_161 , 1 ) ;
F_68 ( V_160 ) ;
F_67 ( V_160 , V_161 , 0 ) ;
F_68 ( V_160 ) ;
}
return;
}
static void F_69 ( struct V_5 * V_158 ,
T_3 V_141 )
{
if ( ! V_170 )
return;
V_158 -> V_156 = V_141 ;
F_70 ( & V_158 -> V_13 , V_171 / 10 ) ;
}
static void F_71 ( T_4 V_30 , T_3 V_141 , void * V_111 )
{
struct V_5 * V_158 = V_111 ;
struct V_17 * V_18 = NULL ;
struct V_61 * V_172 ;
struct V_159 * V_160 ;
int V_161 = 0 ;
if ( ! V_158 )
return;
V_18 = V_158 -> V_29 ;
V_172 = V_158 -> V_20 ;
V_160 = V_172 -> V_160 ;
switch ( V_141 ) {
case V_148 :
F_69 ( V_158 , V_141 ) ;
V_161 = V_173 ;
break;
case V_149 :
F_69 ( V_158 , V_141 ) ;
V_161 = V_174 ;
break;
case V_150 :
F_69 ( V_158 , V_141 ) ;
V_161 = V_175 ;
break;
case V_151 :
F_69 ( V_158 , V_141 ) ;
V_161 = V_176 ;
break;
case V_152 :
F_69 ( V_158 , V_141 ) ;
V_161 = V_177 ;
break;
default:
F_29 ( ( V_77 ,
L_36 , V_141 ) ) ;
break;
}
F_66 ( V_18 , V_141 , 0 ) ;
if ( V_161 ) {
F_67 ( V_160 , V_161 , 1 ) ;
F_68 ( V_160 ) ;
F_67 ( V_160 , V_161 , 0 ) ;
F_68 ( V_160 ) ;
}
return;
}
static int F_72 ( struct V_178 * V_179 ,
unsigned long V_180 , void * V_181 )
{
struct V_61 * V_20 ;
struct V_5 * V_158 ;
int V_4 ;
switch ( V_180 ) {
case V_182 :
case V_183 :
case V_184 :
return V_185 ;
}
V_20 = F_56 ( V_179 , struct V_61 , V_186 ) ;
F_73 ( & V_20 -> V_18 -> V_29 , L_37 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_106 ; V_4 ++ ) {
V_158 = V_20 -> V_107 [ V_4 ] . V_136 ;
if ( V_158 && V_158 -> V_8 )
F_6 ( V_158 ,
V_158 -> V_8 -> V_37 ) ;
}
return V_187 ;
}
static T_1
F_74 ( T_4 V_30 , T_3 V_21 , void * V_188 ,
void * * V_189 )
{
struct V_17 * V_18 = V_188 ;
struct V_17 * V_190 ;
int V_72 ;
if ( V_30 == V_18 -> V_30 )
return V_191 ;
V_72 = F_75 ( V_30 , & V_190 ) ;
if ( V_72 )
return V_48 ;
if ( ! strcmp ( F_42 ( V_190 ) , V_192 ) )
return V_193 ;
return V_48 ;
}
static void F_76 ( struct V_5 * V_18 )
{
struct V_194 V_12 ;
struct V_98 * V_195 ;
T_4 V_196 ;
struct V_18 * V_197 = NULL ;
int V_72 ;
static int V_9 ;
char * V_198 ;
if ( ! F_51 ( V_18 ) ) {
F_77 ( & V_18 -> V_29 -> V_29 , L_38 ) ;
return;
}
V_72 = F_28 ( V_18 ) ;
if ( V_72 )
return;
if ( V_42 > 0 )
return;
V_198 = F_78 ( V_80 , L_39 , V_9 ) ;
if ( ! V_198 )
return;
V_9 ++ ;
F_79 ( V_18 -> V_29 -> V_30 , & V_196 ) ;
V_195 = F_37 ( V_196 ) ;
if ( V_195 ) {
V_197 = & V_195 -> V_29 ;
F_38 ( V_195 ) ;
}
memset ( & V_12 , 0 , sizeof( struct V_194 ) ) ;
V_12 . type = V_199 ;
V_12 . V_200 = V_18 -> V_8 -> V_9 - 3 ;
V_18 -> V_38 = F_80 ( V_198 ,
V_197 ,
V_18 ,
& V_201 ,
& V_12 ) ;
F_15 ( V_198 ) ;
if ( F_81 ( V_18 -> V_38 ) ) {
V_18 -> V_38 = NULL ;
return;
}
V_18 -> V_38 -> V_12 . V_8 =
F_1 ( V_18 -> V_38 ) ;
V_18 -> V_15 = F_82 ( L_40 ,
V_18 -> V_29 , & V_202 ) ;
if ( F_81 ( V_18 -> V_15 ) ) {
V_18 -> V_15 = NULL ;
return;
}
F_73 ( & V_18 -> V_29 -> V_29 , L_41 ,
V_18 -> V_15 -> V_203 ) ;
V_72 = F_83 ( & V_18 -> V_29 -> V_29 . V_204 ,
& V_18 -> V_15 -> V_18 . V_204 ,
L_42 ) ;
if ( V_72 )
F_14 (KERN_ERR PREFIX L_43 ) ;
V_72 = F_83 ( & V_18 -> V_15 -> V_18 . V_204 ,
& V_18 -> V_29 -> V_29 . V_204 , L_44 ) ;
if ( V_72 )
F_14 (KERN_ERR PREFIX L_43 ) ;
}
static void F_84 ( struct V_61 * V_20 )
{
struct V_5 * V_29 ;
union V_23 * V_10 ;
F_46 ( & V_20 -> V_133 ) ;
F_50 (dev, &video->video_device_list, entry) {
if ( ! F_11 ( V_29 , & V_10 ) )
F_15 ( V_10 ) ;
}
F_48 ( & V_20 -> V_133 ) ;
}
static int F_85 ( struct V_61 * V_20 )
{
struct V_5 * V_29 ;
if ( V_20 -> V_205 )
return 0 ;
F_84 ( V_20 ) ;
if ( F_86 () != V_206 )
return 0 ;
F_46 ( & V_20 -> V_133 ) ;
F_50 (dev, &video->video_device_list, entry)
F_76 ( V_29 ) ;
F_48 ( & V_20 -> V_133 ) ;
V_20 -> V_205 = true ;
V_20 -> V_186 . V_207 = F_72 ;
V_20 -> V_186 . V_208 = 0 ;
return F_87 ( & V_20 -> V_186 ) ;
}
static void F_88 ( struct V_5 * V_18 )
{
if ( V_18 -> V_38 ) {
F_89 ( V_18 -> V_38 ) ;
V_18 -> V_38 = NULL ;
}
if ( V_18 -> V_8 ) {
F_15 ( V_18 -> V_8 -> V_10 ) ;
F_15 ( V_18 -> V_8 ) ;
V_18 -> V_8 = NULL ;
}
if ( V_18 -> V_15 ) {
F_90 ( & V_18 -> V_29 -> V_29 . V_204 , L_42 ) ;
F_90 ( & V_18 -> V_15 -> V_18 . V_204 , L_44 ) ;
F_91 ( V_18 -> V_15 ) ;
V_18 -> V_15 = NULL ;
}
}
static int F_92 ( struct V_61 * V_20 )
{
struct V_5 * V_29 ;
int error ;
if ( ! V_20 -> V_205 )
return 0 ;
error = F_93 ( & V_20 -> V_186 ) ;
F_46 ( & V_20 -> V_133 ) ;
F_50 (dev, &video->video_device_list, entry)
F_88 ( V_29 ) ;
F_48 ( & V_20 -> V_133 ) ;
V_20 -> V_205 = false ;
return error ;
}
static void F_94 ( struct V_5 * V_18 )
{
T_1 V_24 ;
struct V_17 * V_209 = V_18 -> V_29 ;
V_24 = F_95 ( V_209 -> V_30 , V_210 ,
F_71 , V_18 ) ;
if ( F_17 ( V_24 ) )
F_61 ( & V_209 -> V_29 , L_45 ) ;
else
V_18 -> V_44 . V_211 = 1 ;
}
static int F_96 ( struct V_61 * V_20 )
{
struct V_159 * V_160 ;
struct V_5 * V_29 ;
int error ;
V_20 -> V_160 = V_160 = F_97 () ;
if ( ! V_160 ) {
error = - V_82 ;
goto V_78;
}
error = F_62 ( V_20 ) ;
if ( error )
goto V_212;
snprintf ( V_20 -> V_213 , sizeof( V_20 -> V_213 ) ,
L_46 , F_98 ( V_20 -> V_18 ) ) ;
V_160 -> V_198 = F_42 ( V_20 -> V_18 ) ;
V_160 -> V_213 = V_20 -> V_213 ;
V_160 -> V_203 . V_214 = V_215 ;
V_160 -> V_203 . V_216 = 0x06 ;
V_160 -> V_29 . V_197 = & V_20 -> V_18 -> V_29 ;
V_160 -> V_217 [ 0 ] = F_99 ( V_218 ) ;
F_100 ( V_163 , V_160 -> V_219 ) ;
F_100 ( V_167 , V_160 -> V_219 ) ;
F_100 ( V_169 , V_160 -> V_219 ) ;
F_100 ( V_173 , V_160 -> V_219 ) ;
F_100 ( V_174 , V_160 -> V_219 ) ;
F_100 ( V_175 , V_160 -> V_219 ) ;
F_100 ( V_176 , V_160 -> V_219 ) ;
F_100 ( V_177 , V_160 -> V_219 ) ;
error = F_101 ( V_160 ) ;
if ( error )
goto V_220;
F_46 ( & V_20 -> V_133 ) ;
F_50 (dev, &video->video_device_list, entry)
F_94 ( V_29 ) ;
F_48 ( & V_20 -> V_133 ) ;
return 0 ;
V_220:
F_64 ( V_20 ) ;
V_212:
F_102 ( V_160 ) ;
V_20 -> V_160 = NULL ;
V_78:
return error ;
}
static void F_103 ( struct V_5 * V_29 )
{
if ( V_29 -> V_44 . V_211 ) {
F_104 ( V_29 -> V_29 -> V_30 , V_210 ,
F_71 ) ;
V_29 -> V_44 . V_211 = 0 ;
}
}
static void F_105 ( struct V_61 * V_20 )
{
struct V_5 * V_29 ;
F_46 ( & V_20 -> V_133 ) ;
F_50 (dev, &video->video_device_list, entry)
F_103 ( V_29 ) ;
F_48 ( & V_20 -> V_133 ) ;
F_64 ( V_20 ) ;
F_106 ( V_20 -> V_160 ) ;
V_20 -> V_160 = NULL ;
}
static int F_107 ( struct V_61 * V_20 )
{
struct V_5 * V_29 , * V_221 ;
F_46 ( & V_20 -> V_133 ) ;
F_108 (dev, next, &video->video_device_list, entry) {
F_109 ( & V_29 -> V_134 ) ;
F_15 ( V_29 ) ;
}
F_48 ( & V_20 -> V_133 ) ;
return 0 ;
}
static int F_110 ( struct V_17 * V_18 )
{
struct V_61 * V_20 ;
int error ;
T_1 V_24 ;
V_24 = F_111 ( V_222 ,
V_18 -> V_197 -> V_30 , 1 ,
F_74 , NULL ,
V_18 , NULL ) ;
if ( V_24 == V_193 ) {
F_14 (KERN_WARNING FW_BUG
L_47
L_48
L_49
L_50 ) ;
if ( ! V_223 )
return - V_58 ;
}
V_20 = F_30 ( sizeof( struct V_61 ) , V_80 ) ;
if ( ! V_20 )
return - V_82 ;
if ( ! strcmp ( V_18 -> V_224 . V_225 , L_51 ) ) {
if ( V_226 )
V_18 -> V_224 . V_225 [ 3 ] = '0' + V_226 ;
V_226 ++ ;
}
if ( ! strcmp ( V_18 -> V_224 . V_225 , L_52 ) ) {
if ( V_226 )
V_18 -> V_224 . V_225 [ 3 ] = '0' + V_226 ;
V_226 ++ ;
}
V_20 -> V_18 = V_18 ;
strcpy ( F_42 ( V_18 ) , V_192 ) ;
strcpy ( F_43 ( V_18 ) , V_114 ) ;
V_18 -> V_115 = V_20 ;
F_35 ( V_20 ) ;
error = F_36 ( V_20 ) ;
if ( error )
goto V_227;
F_112 ( & V_20 -> V_133 ) ;
F_113 ( & V_20 -> V_135 ) ;
error = F_60 ( V_20 , V_18 ) ;
if ( error )
goto V_228;
F_14 (KERN_INFO PREFIX L_53 ,
ACPI_VIDEO_DEVICE_NAME, acpi_device_bid(device),
video->flags.multihead ? L_54 : L_55 ,
video->flags.rom ? L_54 : L_55 ,
video->flags.post ? L_54 : L_55 ) ;
F_46 ( & V_229 ) ;
F_47 ( & V_20 -> V_134 , & V_230 ) ;
F_48 ( & V_229 ) ;
F_85 ( V_20 ) ;
F_96 ( V_20 ) ;
return 0 ;
V_228:
F_107 ( V_20 ) ;
F_15 ( V_20 -> V_107 ) ;
V_227:
F_15 ( V_20 ) ;
V_18 -> V_115 = NULL ;
return error ;
}
static int F_114 ( struct V_17 * V_18 )
{
struct V_61 * V_20 = NULL ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
F_105 ( V_20 ) ;
F_92 ( V_20 ) ;
F_107 ( V_20 ) ;
F_46 ( & V_229 ) ;
F_109 ( & V_20 -> V_134 ) ;
F_48 ( & V_229 ) ;
F_15 ( V_20 -> V_107 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static int T_5 F_115 ( struct V_98 * V_29 )
{
if ( V_29 -> V_18 == 0x00D1 )
return 1 ;
if ( V_29 -> V_18 == 0x7000 )
return 1 ;
return 0 ;
}
static int T_5 F_116 ( void )
{
int V_231 = 0 ;
struct V_98 * V_29 = NULL ;
T_3 V_232 ;
F_117 (dev) {
if ( ( V_29 -> V_233 >> 8 ) != V_234 )
continue;
if ( V_29 -> V_235 != V_236 )
continue;
if ( F_115 ( V_29 ) )
continue;
F_118 ( V_29 , 0xfc , & V_232 ) ;
if ( ! V_232 )
continue;
V_231 = 1 ;
}
return V_231 ;
}
int F_119 ( void )
{
int V_237 = 0 ;
F_46 ( & V_238 ) ;
if ( V_239 ) {
goto V_240;
}
F_112 ( & V_229 ) ;
F_113 ( & V_230 ) ;
F_120 ( V_241 ) ;
V_237 = F_121 ( & V_61 ) ;
if ( V_237 )
goto V_240;
V_239 = 1 ;
V_240:
F_48 ( & V_238 ) ;
return V_237 ;
}
void F_122 ( void )
{
F_46 ( & V_238 ) ;
if ( V_239 ) {
F_123 ( & V_61 ) ;
V_239 = 0 ;
}
F_48 ( & V_238 ) ;
}
void F_124 ( void )
{
struct V_61 * V_20 ;
F_46 ( & V_238 ) ;
if ( V_239 ) {
F_46 ( & V_229 ) ;
F_50 (video, &video_bus_head, entry)
F_92 ( V_20 ) ;
F_48 ( & V_229 ) ;
}
F_48 ( & V_238 ) ;
}
static int T_5 F_125 ( void )
{
if ( V_242 )
return 0 ;
if ( F_116 () )
return 0 ;
return F_119 () ;
}
static void T_6 F_126 ( void )
{
F_127 () ;
F_122 () ;
return;
}
