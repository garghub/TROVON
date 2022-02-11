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
static unsigned long long
F_23 ( struct V_5 * V_18 ,
unsigned long long V_45 )
{
unsigned long long V_21 ;
if ( V_18 -> V_8 -> V_46 . V_47 ) {
if ( V_18 -> V_8 -> V_46 . V_48 )
V_45 = V_18 -> V_8 -> V_9 - 3 - V_45 ;
V_21 = V_18 -> V_8 -> V_10 [ V_45 + 2 ] ;
} else {
V_21 = V_45 ;
}
V_21 += V_41 ;
return V_21 ;
}
static int
F_3 ( struct V_5 * V_18 ,
unsigned long long * V_21 , bool V_49 )
{
T_1 V_24 = V_50 ;
int V_4 ;
if ( V_18 -> V_51 . V_52 || V_18 -> V_51 . V_53 ) {
char * V_54 = V_18 -> V_51 . V_52 ? L_6 : L_7 ;
V_24 = F_24 ( V_18 -> V_29 -> V_30 , V_54 ,
NULL , V_21 ) ;
if ( F_13 ( V_24 ) ) {
if ( V_49 ) {
return 0 ;
}
* V_21 = F_23 ( V_18 , * V_21 ) ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ )
if ( V_18 -> V_8 -> V_10 [ V_4 ] == * V_21 ) {
V_18 -> V_8 -> V_37 = * V_21 ;
return 0 ;
}
F_25 ( ( V_35 ,
L_8 ,
V_54 ) ) ;
V_18 -> V_51 . V_52 = V_18 -> V_51 . V_53 = 0 ;
} else {
F_25 ( ( V_35 , L_9 , V_54 ) ) ;
V_18 -> V_51 . V_52 = V_18 -> V_51 . V_53 = 0 ;
}
}
* V_21 = V_18 -> V_8 -> V_37 ;
return 0 ;
}
static int
F_26 ( struct V_5 * V_18 ,
union V_23 * * V_55 , T_2 V_56 )
{
int V_24 ;
struct V_25 V_26 = { V_27 , NULL } ;
union V_23 * V_28 ;
union V_23 V_57 = { V_58 } ;
struct V_59 args = { 1 , & V_57 } ;
* V_55 = NULL ;
if ( ! V_18 )
return - V_60 ;
if ( V_56 == 128 )
V_57 . integer . V_61 = 1 ;
else if ( V_56 == 256 )
V_57 . integer . V_61 = 2 ;
else
return - V_7 ;
V_24 = F_12 ( V_18 -> V_29 -> V_30 , L_10 , & args , & V_26 ) ;
if ( F_17 ( V_24 ) )
return - V_60 ;
V_28 = V_26 . V_31 ;
if ( V_28 && V_28 -> type == V_62 )
* V_55 = V_28 ;
else {
F_14 (KERN_ERR PREFIX L_11 ) ;
V_24 = - V_33 ;
F_15 ( V_28 ) ;
}
return V_24 ;
}
static int
F_27 ( struct V_63 * V_20 , int V_64 , int V_65 )
{
T_1 V_24 ;
if ( ! V_20 -> V_51 . V_66 )
return 0 ;
if ( V_64 < 0 || V_64 > 3 || V_65 < 0 || V_65 > 1 )
return - V_7 ;
V_20 -> V_67 = ( V_65 << 2 ) | V_64 ;
V_24 = F_16 ( V_20 -> V_18 -> V_30 , L_12 ,
( V_65 << 2 ) | V_64 ) ;
if ( F_17 ( V_24 ) )
return - V_36 ;
return 0 ;
}
static int
F_28 ( const void * V_68 , const void * V_69 )
{
return * ( int * ) V_68 - * ( int * ) V_69 ;
}
static int F_29 ( struct V_5 * V_18 ,
int V_70 , int V_71 )
{
struct V_72 * V_73 = V_18 -> V_8 ;
int V_74 ;
unsigned long long V_21 ;
int V_75 ;
if ( V_41 )
return 0 ;
V_75 = V_71 == V_70 ? V_73 -> V_10 [ 3 ] : V_70 ;
V_74 = F_6 ( V_18 , V_75 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_3 ( V_18 , & V_21 , true ) ;
if ( V_74 )
return V_74 ;
if ( V_21 != V_75 ) {
if ( V_21 < V_73 -> V_9 ) {
if ( V_73 -> V_46 . V_48 )
V_21 = V_73 -> V_9 - 3 - V_21 ;
if ( V_73 -> V_10 [ V_21 + 2 ] == V_75 )
V_73 -> V_46 . V_47 = 1 ;
}
if ( ! V_73 -> V_46 . V_47 )
V_18 -> V_51 . V_52 = V_18 -> V_51 . V_53 = 0 ;
}
return 0 ;
}
static int
F_30 ( struct V_5 * V_18 )
{
union V_23 * V_28 = NULL ;
int V_4 , V_70 = 0 , V_9 = 0 , V_76 = 0 ;
unsigned long long V_21 , V_77 ;
union V_23 * V_78 ;
struct V_72 * V_73 = NULL ;
int V_74 = - V_7 ;
T_3 V_61 ;
if ( ! F_13 ( F_11 ( V_18 , & V_28 ) ) ) {
F_31 ( ( V_79 , L_13
L_14 ) ) ;
goto V_80;
}
if ( V_28 -> V_81 . V_9 < 2 )
goto V_80;
V_73 = F_32 ( sizeof( * V_73 ) , V_82 ) ;
if ( ! V_73 ) {
F_14 ( V_83 L_15 ) ;
V_74 = - V_84 ;
goto V_80;
}
V_73 -> V_10 = F_33 ( ( V_28 -> V_81 . V_9 + 2 ) * sizeof *( V_73 -> V_10 ) ,
V_82 ) ;
if ( ! V_73 -> V_10 ) {
V_74 = - V_84 ;
goto V_85;
}
for ( V_4 = 0 ; V_4 < V_28 -> V_81 . V_9 ; V_4 ++ ) {
V_78 = (union V_23 * ) & V_28 -> V_81 . V_86 [ V_4 ] ;
if ( V_78 -> type != V_58 ) {
F_14 (KERN_ERR PREFIX L_16 ) ;
continue;
}
V_61 = ( T_3 ) V_78 -> integer . V_61 ;
if ( V_9 > 2 && V_73 -> V_10 [ V_9 - 1 ] == V_61 )
continue;
V_73 -> V_10 [ V_9 ] = V_61 ;
if ( V_73 -> V_10 [ V_9 ] > V_70 )
V_70 = V_73 -> V_10 [ V_9 ] ;
V_9 ++ ;
}
for ( V_4 = 2 ; V_4 < V_9 ; V_4 ++ ) {
if ( V_73 -> V_10 [ V_4 ] == V_73 -> V_10 [ 0 ] )
V_76 ++ ;
if ( V_73 -> V_10 [ V_4 ] == V_73 -> V_10 [ 1 ] )
V_76 ++ ;
}
if ( V_76 < 2 ) {
V_76 = 2 - V_76 ;
V_73 -> V_46 . V_87 = 1 ;
for ( V_4 = ( V_9 - 1 + V_76 ) ; V_4 >= 2 ; V_4 -- )
V_73 -> V_10 [ V_4 ] = V_73 -> V_10 [ V_4 - V_76 ] ;
V_9 += V_76 ;
} else if ( V_76 > 2 )
F_18 ( ( V_35 , L_17 ) ) ;
if ( V_70 == V_73 -> V_10 [ 2 ] ) {
V_73 -> V_46 . V_48 = 1 ;
F_34 ( & V_73 -> V_10 [ 2 ] , V_9 - 2 , sizeof( V_73 -> V_10 [ 2 ] ) ,
F_28 , NULL ) ;
} else if ( V_70 != V_73 -> V_10 [ V_9 - 1 ] )
F_18 ( ( V_35 ,
L_18 ) ) ;
V_73 -> V_9 = V_9 ;
V_18 -> V_8 = V_73 ;
V_73 -> V_37 = V_21 = V_70 ;
if ( ! V_18 -> V_51 . V_52 )
goto V_88;
V_74 = F_3 ( V_18 ,
& V_77 , true ) ;
if ( V_74 )
goto V_89;
V_74 = F_29 ( V_18 , V_70 , V_77 ) ;
if ( V_74 )
goto V_89;
if ( ! V_18 -> V_51 . V_52 )
goto V_88;
V_21 = F_23 ( V_18 , V_77 ) ;
for ( V_4 = 2 ; V_4 < V_73 -> V_9 ; V_4 ++ )
if ( V_21 == V_73 -> V_10 [ V_4 ] )
break;
if ( V_4 == V_73 -> V_9 || ! V_21 )
V_21 = V_70 ;
V_88:
V_74 = F_6 ( V_18 , V_21 ) ;
if ( V_74 )
goto V_89;
F_31 ( ( V_79 ,
L_19 , V_9 - 2 ) ) ;
F_15 ( V_28 ) ;
return V_74 ;
V_89:
F_15 ( V_73 -> V_10 ) ;
V_85:
F_15 ( V_73 ) ;
V_80:
V_18 -> V_8 = NULL ;
F_15 ( V_28 ) ;
return V_74 ;
}
static void F_35 ( struct V_5 * V_18 )
{
if ( F_36 ( V_18 -> V_29 -> V_30 , L_20 ) )
V_18 -> V_51 . V_90 = 1 ;
if ( F_36 ( V_18 -> V_29 -> V_30 , L_1 ) )
V_18 -> V_51 . V_91 = 1 ;
if ( F_36 ( V_18 -> V_29 -> V_30 , L_3 ) )
V_18 -> V_51 . V_92 = 1 ;
if ( F_36 ( V_18 -> V_29 -> V_30 , L_6 ) ) {
V_18 -> V_51 . V_52 = 1 ;
} else if ( F_36 ( V_18 -> V_29 -> V_30 , L_7 ) ) {
F_14 (KERN_WARNING FW_BUG L_21 ) ;
V_18 -> V_51 . V_53 = 1 ;
}
if ( F_36 ( V_18 -> V_29 -> V_30 , L_10 ) )
V_18 -> V_51 . V_93 = 1 ;
}
static void F_37 ( struct V_63 * V_20 )
{
if ( F_36 ( V_20 -> V_18 -> V_30 , L_12 ) )
V_20 -> V_51 . V_66 = 1 ;
if ( F_36 ( V_20 -> V_18 -> V_30 , L_22 ) )
V_20 -> V_51 . V_94 = 1 ;
if ( F_36 ( V_20 -> V_18 -> V_30 , L_23 ) )
V_20 -> V_51 . V_95 = 1 ;
if ( F_36 ( V_20 -> V_18 -> V_30 , L_24 ) )
V_20 -> V_51 . V_96 = 1 ;
if ( F_36 ( V_20 -> V_18 -> V_30 , L_25 ) )
V_20 -> V_51 . V_97 = 1 ;
if ( F_36 ( V_20 -> V_18 -> V_30 , L_26 ) )
V_20 -> V_51 . V_98 = 1 ;
}
static int F_38 ( struct V_63 * V_20 )
{
T_1 V_24 = - V_99 ;
struct V_100 * V_29 ;
if ( ! V_20 )
return - V_7 ;
V_29 = F_39 ( V_20 -> V_18 -> V_30 ) ;
if ( ! V_29 )
return - V_60 ;
F_40 ( V_29 ) ;
if ( V_20 -> V_51 . V_66 || V_20 -> V_51 . V_94 ) {
if ( ! V_20 -> V_51 . V_66 ) {
F_14 (KERN_WARNING FW_BUG
L_27 ,
acpi_device_bid(video->device)) ;
}
V_20 -> V_46 . V_101 = 1 ;
V_24 = 0 ;
}
if ( V_20 -> V_51 . V_95 ) {
V_20 -> V_46 . V_102 = 1 ;
V_24 = 0 ;
}
if ( V_20 -> V_51 . V_96 && V_20 -> V_51 . V_97 && V_20 -> V_51 . V_98 ) {
V_20 -> V_46 . V_103 = 1 ;
V_24 = 0 ;
}
return V_24 ;
}
static struct V_104 *
F_41 ( struct V_63 * V_20 , unsigned long V_105 )
{
struct V_106 * V_107 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_108 ; V_4 ++ ) {
V_107 = & V_20 -> V_109 [ V_4 ] ;
if ( ( V_107 -> V_61 . V_110 & 0xffff ) == V_105 )
return & V_107 -> V_61 . V_111 ;
}
return NULL ;
}
static int
F_42 ( struct V_63 * V_20 ,
unsigned long V_105 )
{
struct V_106 * V_107 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_108 ; V_4 ++ ) {
V_107 = & V_20 -> V_109 [ V_4 ] ;
if ( ( V_107 -> V_61 . V_110 & 0xffff ) == V_105 )
return V_107 -> V_61 . V_110 ;
}
return 0 ;
}
static int
F_43 ( struct V_17 * V_18 ,
struct V_63 * V_20 )
{
unsigned long long V_105 ;
int V_24 , V_112 ;
struct V_5 * V_113 ;
struct V_104 * V_114 ;
V_24 =
F_24 ( V_18 -> V_30 , L_20 , NULL , & V_105 ) ;
if ( F_17 ( V_24 ) )
return 0 ;
V_113 = F_32 ( sizeof( struct V_5 ) , V_82 ) ;
if ( ! V_113 )
return - V_84 ;
strcpy ( F_44 ( V_18 ) , V_115 ) ;
strcpy ( F_45 ( V_18 ) , V_116 ) ;
V_18 -> V_117 = V_113 ;
V_113 -> V_105 = V_105 ;
V_113 -> V_20 = V_20 ;
V_113 -> V_29 = V_18 ;
F_46 ( & V_113 -> V_13 ,
V_118 ) ;
V_114 = F_41 ( V_20 , V_105 ) ;
if ( V_114 && ( V_114 -> V_43 || V_43 ) ) {
switch ( V_114 -> V_119 ) {
case V_120 :
V_113 -> V_46 . V_121 = 1 ;
break;
case V_122 :
V_113 -> V_46 . V_123 = 1 ;
break;
case V_124 :
V_113 -> V_46 . V_125 = 1 ;
break;
case V_126 :
V_113 -> V_46 . V_127 = 1 ;
break;
default:
V_113 -> V_46 . V_128 = 1 ;
break;
}
if ( V_114 -> V_129 )
V_113 -> V_46 . V_130 = 1 ;
} else {
V_112 = F_42 ( V_20 , V_105 ) ;
switch ( V_112 & 0xffe2ffff ) {
case V_131 :
V_113 -> V_46 . V_121 = 1 ;
break;
case V_132 :
V_113 -> V_46 . V_127 = 1 ;
break;
case V_133 :
V_113 -> V_46 . V_123 = 1 ;
break;
default:
V_113 -> V_46 . V_128 = 1 ;
}
}
F_47 ( V_20 , V_113 ) ;
F_35 ( V_113 ) ;
F_48 ( & V_20 -> V_134 ) ;
F_49 ( & V_113 -> V_135 , & V_20 -> V_136 ) ;
F_50 ( & V_20 -> V_134 ) ;
return V_24 ;
}
static void F_51 ( struct V_63 * V_20 )
{
struct V_5 * V_29 ;
F_48 ( & V_20 -> V_134 ) ;
F_52 (dev, &video->video_device_list, entry)
F_47 ( V_20 , V_29 ) ;
F_50 ( & V_20 -> V_134 ) ;
}
static void
F_47 ( struct V_63 * V_20 ,
struct V_5 * V_18 )
{
struct V_106 * V_107 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_108 ; V_4 ++ ) {
V_107 = & V_20 -> V_109 [ V_4 ] ;
if ( V_18 -> V_105 == ( V_107 -> V_61 . V_110 & 0xffff ) ) {
V_107 -> V_137 = V_18 ;
F_31 ( ( V_79 , L_28 , V_4 ) ) ;
}
}
}
static bool F_53 ( struct V_5 * V_18 )
{
struct V_63 * V_20 = V_18 -> V_20 ;
int V_4 ;
if ( ! V_20 -> V_108 || V_20 -> V_138 > 8 )
return true ;
for ( V_4 = 0 ; V_4 < V_20 -> V_108 ; V_4 ++ ) {
if ( ( V_20 -> V_109 [ V_4 ] . V_61 . V_110 & 0xfff ) ==
( V_18 -> V_105 & 0xfff ) )
return true ;
}
return false ;
}
static int F_54 ( struct V_63 * V_20 )
{
int V_24 ;
int V_9 ;
int V_4 ;
struct V_106 * V_139 ;
struct V_25 V_26 = { V_27 , NULL } ;
union V_23 * V_140 = NULL ;
union V_23 * V_28 ;
V_24 = F_12 ( V_20 -> V_18 -> V_30 , L_22 , NULL , & V_26 ) ;
if ( ! F_13 ( V_24 ) ) {
F_55 ( ( V_35 , V_24 , L_29 ) ) ;
return V_24 ;
}
V_140 = V_26 . V_31 ;
if ( ! V_140 || ( V_140 -> type != V_32 ) ) {
F_55 ( ( V_35 , V_24 , L_30 ) ) ;
V_24 = - V_33 ;
goto V_80;
}
F_31 ( ( V_79 , L_31 ,
V_140 -> V_81 . V_9 ) ) ;
V_139 = F_56 ( 1 + V_140 -> V_81 . V_9 ,
sizeof( struct V_106 ) ,
V_82 ) ;
if ( ! V_139 ) {
V_24 = - V_84 ;
goto V_80;
}
V_9 = 0 ;
for ( V_4 = 0 ; V_4 < V_140 -> V_81 . V_9 ; V_4 ++ ) {
V_28 = & V_140 -> V_81 . V_86 [ V_4 ] ;
if ( V_28 -> type != V_58 ) {
F_14 (KERN_ERR PREFIX
L_32 , i) ;
continue;
}
V_139 [ V_9 ] . V_61 . V_110 = V_28 -> integer . V_61 ;
V_139 [ V_9 ] . V_137 = NULL ;
F_31 ( ( V_79 , L_33 , V_4 ,
( int ) V_28 -> integer . V_61 ) ) ;
V_9 ++ ;
}
F_15 ( V_20 -> V_109 ) ;
V_20 -> V_109 = V_139 ;
V_20 -> V_108 = V_9 ;
V_80:
F_15 ( V_26 . V_31 ) ;
return V_24 ;
}
static int
F_57 ( struct V_5 * V_18 ,
T_3 V_141 , T_3 V_142 )
{
int V_143 , V_144 , V_145 , V_146 , V_4 , V_147 , V_148 = 255 ;
V_144 = V_146 = 0 ;
V_143 = V_145 = 255 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_147 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( abs ( V_147 - V_141 ) < abs ( V_148 ) ) {
V_148 = V_147 - V_141 ;
if ( ! V_148 )
break;
}
}
V_141 += V_148 ;
for ( V_4 = 2 ; V_4 < V_18 -> V_8 -> V_9 ; V_4 ++ ) {
V_147 = V_18 -> V_8 -> V_10 [ V_4 ] ;
if ( V_147 < V_143 )
V_143 = V_147 ;
if ( V_147 > V_144 )
V_144 = V_147 ;
if ( V_147 < V_145 && V_147 > V_141 )
V_145 = V_147 ;
if ( V_147 > V_146 && V_147 < V_141 )
V_146 = V_147 ;
}
switch ( V_142 ) {
case V_149 :
return ( V_141 < V_144 ) ? V_145 : V_143 ;
case V_150 :
return ( V_141 < V_144 ) ? V_145 : V_144 ;
case V_151 :
return ( V_141 > V_143 ) ? V_146 : V_143 ;
case V_152 :
case V_153 :
return 0 ;
default:
return V_141 ;
}
}
static void
V_118 ( struct V_154 * V_155 )
{
struct V_5 * V_18 = F_58 ( F_59 ( V_155 ) ,
struct V_5 , V_13 ) ;
unsigned long long V_141 , V_156 ;
int V_142 = V_18 -> V_157 ;
int V_74 = - V_7 ;
if ( ! V_18 -> V_38 )
return;
if ( ! V_18 -> V_8 )
goto V_80;
V_74 = F_3 ( V_18 ,
& V_141 ,
false ) ;
if ( V_74 )
goto V_80;
V_156 = F_57 ( V_18 , V_141 , V_142 ) ;
V_74 = F_6 ( V_18 , V_156 ) ;
if ( ! V_74 )
F_60 ( V_18 -> V_38 ,
V_158 ) ;
V_80:
if ( V_74 )
F_14 (KERN_ERR PREFIX L_34 ) ;
}
int F_61 ( struct V_17 * V_18 , int type , int V_105 ,
void * * V_55 )
{
struct V_63 * V_20 ;
struct V_5 * V_159 ;
union V_23 * V_26 = NULL ;
T_1 V_24 ;
int V_4 , V_56 ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_108 ; V_4 ++ ) {
V_159 = V_20 -> V_109 [ V_4 ] . V_137 ;
V_56 = 256 ;
if ( ! V_159 )
continue;
if ( ! V_159 -> V_51 . V_93 )
continue;
if ( type ) {
switch ( type ) {
case V_120 :
if ( ! V_159 -> V_46 . V_121 )
continue;
break;
case V_122 :
if ( ! V_159 -> V_46 . V_123 )
continue;
break;
case V_124 :
if ( ! V_159 -> V_46 . V_125 )
continue;
break;
case V_126 :
if ( ! V_159 -> V_46 . V_127 )
continue;
break;
}
} else if ( V_159 -> V_105 != V_105 ) {
continue;
}
V_24 = F_26 ( V_159 , & V_26 , V_56 ) ;
if ( F_17 ( V_24 ) || ! V_26 ||
V_26 -> type != V_62 ) {
V_56 = 128 ;
V_24 = F_26 ( V_159 , & V_26 ,
V_56 ) ;
if ( F_17 ( V_24 ) || ! V_26 ||
V_26 -> type != V_62 ) {
continue;
}
}
* V_55 = V_26 -> V_26 . V_31 ;
return V_56 ;
}
return - V_60 ;
}
static int
F_62 ( struct V_63 * V_20 ,
struct V_17 * V_18 )
{
int V_24 = 0 ;
struct V_17 * V_29 ;
F_54 ( V_20 ) ;
F_52 (dev, &device->children, node) {
V_24 = F_43 ( V_29 , V_20 ) ;
if ( V_24 ) {
F_63 ( & V_29 -> V_29 , L_35 ) ;
break;
}
V_20 -> V_138 ++ ;
}
return V_24 ;
}
static int F_64 ( struct V_63 * V_20 )
{
return F_27 ( V_20 , 0 ,
F_65 () ? 1 : 0 ) ;
}
static int F_66 ( struct V_63 * V_20 )
{
return F_27 ( V_20 , 0 ,
F_65 () ? 0 : 1 ) ;
}
static void F_67 ( struct V_17 * V_18 , T_3 V_142 )
{
struct V_63 * V_20 = F_8 ( V_18 ) ;
struct V_160 * V_161 ;
int V_162 = 0 ;
if ( ! V_20 || ! V_20 -> V_161 )
return;
V_161 = V_20 -> V_161 ;
switch ( V_142 ) {
case V_163 :
V_162 = V_164 ;
break;
case V_165 :
F_54 ( V_20 ) ;
F_51 ( V_20 ) ;
V_162 = V_164 ;
break;
case V_166 :
V_162 = V_164 ;
break;
case V_167 :
V_162 = V_168 ;
break;
case V_169 :
V_162 = V_170 ;
break;
default:
F_31 ( ( V_79 ,
L_36 , V_142 ) ) ;
break;
}
if ( F_68 ( V_18 , V_142 , 0 ) )
V_162 = 0 ;
if ( V_162 ) {
F_69 ( V_161 , V_162 , 1 ) ;
F_70 ( V_161 ) ;
F_69 ( V_161 , V_162 , 0 ) ;
F_70 ( V_161 ) ;
}
return;
}
static void F_71 ( struct V_5 * V_159 ,
T_3 V_142 )
{
if ( ! V_171 )
return;
V_159 -> V_157 = V_142 ;
F_72 ( & V_159 -> V_13 , V_172 / 10 ) ;
}
static void F_73 ( T_4 V_30 , T_3 V_142 , void * V_113 )
{
struct V_5 * V_159 = V_113 ;
struct V_17 * V_18 = NULL ;
struct V_63 * V_173 ;
struct V_160 * V_161 ;
int V_162 = 0 ;
if ( ! V_159 )
return;
V_18 = V_159 -> V_29 ;
V_173 = V_159 -> V_20 ;
V_161 = V_173 -> V_161 ;
switch ( V_142 ) {
case V_149 :
F_71 ( V_159 , V_142 ) ;
V_162 = V_174 ;
break;
case V_150 :
F_71 ( V_159 , V_142 ) ;
V_162 = V_175 ;
break;
case V_151 :
F_71 ( V_159 , V_142 ) ;
V_162 = V_176 ;
break;
case V_152 :
F_71 ( V_159 , V_142 ) ;
V_162 = V_177 ;
break;
case V_153 :
F_71 ( V_159 , V_142 ) ;
V_162 = V_178 ;
break;
default:
F_31 ( ( V_79 ,
L_36 , V_142 ) ) ;
break;
}
F_68 ( V_18 , V_142 , 0 ) ;
if ( V_162 ) {
F_69 ( V_161 , V_162 , 1 ) ;
F_70 ( V_161 ) ;
F_69 ( V_161 , V_162 , 0 ) ;
F_70 ( V_161 ) ;
}
return;
}
static int F_74 ( struct V_179 * V_180 ,
unsigned long V_181 , void * V_182 )
{
struct V_63 * V_20 ;
struct V_5 * V_159 ;
int V_4 ;
switch ( V_181 ) {
case V_183 :
case V_184 :
case V_185 :
return V_186 ;
}
V_20 = F_58 ( V_180 , struct V_63 , V_187 ) ;
F_75 ( & V_20 -> V_18 -> V_29 , L_37 ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_108 ; V_4 ++ ) {
V_159 = V_20 -> V_109 [ V_4 ] . V_137 ;
if ( V_159 && V_159 -> V_8 )
F_6 ( V_159 ,
V_159 -> V_8 -> V_37 ) ;
}
return V_188 ;
}
static T_1
F_76 ( T_4 V_30 , T_3 V_21 , void * V_189 ,
void * * V_190 )
{
struct V_17 * V_18 = V_189 ;
struct V_17 * V_191 ;
int V_74 ;
if ( V_30 == V_18 -> V_30 )
return V_192 ;
V_74 = F_77 ( V_30 , & V_191 ) ;
if ( V_74 )
return V_50 ;
if ( ! strcmp ( F_44 ( V_191 ) , V_193 ) )
return V_194 ;
return V_50 ;
}
static void F_78 ( struct V_5 * V_18 )
{
struct V_195 V_12 ;
struct V_100 * V_196 ;
T_4 V_197 ;
struct V_18 * V_198 = NULL ;
int V_74 ;
static int V_9 ;
char * V_199 ;
V_74 = F_30 ( V_18 ) ;
if ( V_74 )
return;
if ( V_42 > 0 )
return;
V_199 = F_79 ( V_82 , L_38 , V_9 ) ;
if ( ! V_199 )
return;
V_9 ++ ;
F_80 ( V_18 -> V_29 -> V_30 , & V_197 ) ;
V_196 = F_39 ( V_197 ) ;
if ( V_196 ) {
V_198 = & V_196 -> V_29 ;
F_40 ( V_196 ) ;
}
memset ( & V_12 , 0 , sizeof( struct V_195 ) ) ;
V_12 . type = V_200 ;
V_12 . V_201 = V_18 -> V_8 -> V_9 - 3 ;
V_18 -> V_38 = F_81 ( V_199 ,
V_198 ,
V_18 ,
& V_202 ,
& V_12 ) ;
F_15 ( V_199 ) ;
if ( F_82 ( V_18 -> V_38 ) ) {
V_18 -> V_38 = NULL ;
return;
}
V_18 -> V_38 -> V_12 . V_8 =
F_1 ( V_18 -> V_38 ) ;
V_18 -> V_15 = F_83 ( L_39 ,
V_18 -> V_29 , & V_203 ) ;
if ( F_82 ( V_18 -> V_15 ) ) {
V_18 -> V_15 = NULL ;
return;
}
F_75 ( & V_18 -> V_29 -> V_29 , L_40 ,
V_18 -> V_15 -> V_204 ) ;
V_74 = F_84 ( & V_18 -> V_29 -> V_29 . V_205 ,
& V_18 -> V_15 -> V_18 . V_205 ,
L_41 ) ;
if ( V_74 )
F_14 (KERN_ERR PREFIX L_42 ) ;
V_74 = F_84 ( & V_18 -> V_15 -> V_18 . V_205 ,
& V_18 -> V_29 -> V_29 . V_205 , L_43 ) ;
if ( V_74 )
F_14 (KERN_ERR PREFIX L_42 ) ;
}
static void F_85 ( struct V_63 * V_20 )
{
struct V_5 * V_29 ;
union V_23 * V_10 ;
F_48 ( & V_20 -> V_134 ) ;
F_52 (dev, &video->video_device_list, entry) {
if ( ! F_11 ( V_29 , & V_10 ) )
F_15 ( V_10 ) ;
}
F_50 ( & V_20 -> V_134 ) ;
}
static bool F_86 ( struct V_5 * V_29 )
{
if ( ! F_53 ( V_29 ) ) {
F_87 ( & V_29 -> V_29 -> V_29 , L_44 ) ;
return false ;
}
if ( V_44 )
return V_29 -> V_46 . V_127 ;
return true ;
}
static int F_88 ( struct V_63 * V_20 )
{
struct V_5 * V_29 ;
if ( V_20 -> V_206 )
return 0 ;
F_85 ( V_20 ) ;
if ( F_89 () != V_207 )
return 0 ;
F_48 ( & V_20 -> V_134 ) ;
F_52 (dev, &video->video_device_list, entry) {
if ( F_86 ( V_29 ) )
F_78 ( V_29 ) ;
}
F_50 ( & V_20 -> V_134 ) ;
V_20 -> V_206 = true ;
V_20 -> V_187 . V_208 = F_74 ;
V_20 -> V_187 . V_209 = 0 ;
return F_90 ( & V_20 -> V_187 ) ;
}
static void F_91 ( struct V_5 * V_18 )
{
if ( V_18 -> V_38 ) {
F_92 ( V_18 -> V_38 ) ;
V_18 -> V_38 = NULL ;
}
if ( V_18 -> V_8 ) {
F_15 ( V_18 -> V_8 -> V_10 ) ;
F_15 ( V_18 -> V_8 ) ;
V_18 -> V_8 = NULL ;
}
if ( V_18 -> V_15 ) {
F_93 ( & V_18 -> V_29 -> V_29 . V_205 , L_41 ) ;
F_93 ( & V_18 -> V_15 -> V_18 . V_205 , L_43 ) ;
F_94 ( V_18 -> V_15 ) ;
V_18 -> V_15 = NULL ;
}
}
static int F_95 ( struct V_63 * V_20 )
{
struct V_5 * V_29 ;
int error ;
if ( ! V_20 -> V_206 )
return 0 ;
error = F_96 ( & V_20 -> V_187 ) ;
F_48 ( & V_20 -> V_134 ) ;
F_52 (dev, &video->video_device_list, entry)
F_91 ( V_29 ) ;
F_50 ( & V_20 -> V_134 ) ;
V_20 -> V_206 = false ;
return error ;
}
static void F_97 ( struct V_5 * V_18 )
{
T_1 V_24 ;
struct V_17 * V_210 = V_18 -> V_29 ;
V_24 = F_98 ( V_210 -> V_30 , V_211 ,
F_73 , V_18 ) ;
if ( F_17 ( V_24 ) )
F_63 ( & V_210 -> V_29 , L_45 ) ;
else
V_18 -> V_46 . V_212 = 1 ;
}
static int F_99 ( struct V_63 * V_20 )
{
struct V_160 * V_161 ;
struct V_5 * V_29 ;
int error ;
V_20 -> V_161 = V_161 = F_100 () ;
if ( ! V_161 ) {
error = - V_84 ;
goto V_80;
}
error = F_64 ( V_20 ) ;
if ( error )
goto V_213;
snprintf ( V_20 -> V_214 , sizeof( V_20 -> V_214 ) ,
L_46 , F_101 ( V_20 -> V_18 ) ) ;
V_161 -> V_199 = F_44 ( V_20 -> V_18 ) ;
V_161 -> V_214 = V_20 -> V_214 ;
V_161 -> V_204 . V_215 = V_216 ;
V_161 -> V_204 . V_217 = 0x06 ;
V_161 -> V_29 . V_198 = & V_20 -> V_18 -> V_29 ;
V_161 -> V_218 [ 0 ] = F_102 ( V_219 ) ;
F_103 ( V_164 , V_161 -> V_220 ) ;
F_103 ( V_168 , V_161 -> V_220 ) ;
F_103 ( V_170 , V_161 -> V_220 ) ;
F_103 ( V_174 , V_161 -> V_220 ) ;
F_103 ( V_175 , V_161 -> V_220 ) ;
F_103 ( V_176 , V_161 -> V_220 ) ;
F_103 ( V_177 , V_161 -> V_220 ) ;
F_103 ( V_178 , V_161 -> V_220 ) ;
error = F_104 ( V_161 ) ;
if ( error )
goto V_221;
F_48 ( & V_20 -> V_134 ) ;
F_52 (dev, &video->video_device_list, entry)
F_97 ( V_29 ) ;
F_50 ( & V_20 -> V_134 ) ;
return 0 ;
V_221:
F_66 ( V_20 ) ;
V_213:
F_105 ( V_161 ) ;
V_20 -> V_161 = NULL ;
V_80:
return error ;
}
static void F_106 ( struct V_5 * V_29 )
{
if ( V_29 -> V_46 . V_212 ) {
F_107 ( V_29 -> V_29 -> V_30 , V_211 ,
F_73 ) ;
V_29 -> V_46 . V_212 = 0 ;
}
}
static void F_108 ( struct V_63 * V_20 )
{
struct V_5 * V_29 ;
F_48 ( & V_20 -> V_134 ) ;
F_52 (dev, &video->video_device_list, entry)
F_106 ( V_29 ) ;
F_50 ( & V_20 -> V_134 ) ;
F_66 ( V_20 ) ;
F_109 ( V_20 -> V_161 ) ;
V_20 -> V_161 = NULL ;
}
static int F_110 ( struct V_63 * V_20 )
{
struct V_5 * V_29 , * V_222 ;
F_48 ( & V_20 -> V_134 ) ;
F_111 (dev, next, &video->video_device_list, entry) {
F_112 ( & V_29 -> V_135 ) ;
F_15 ( V_29 ) ;
}
F_50 ( & V_20 -> V_134 ) ;
return 0 ;
}
static int F_113 ( struct V_17 * V_18 )
{
struct V_63 * V_20 ;
int error ;
T_1 V_24 ;
V_24 = F_114 ( V_223 ,
V_18 -> V_198 -> V_30 , 1 ,
F_76 , NULL ,
V_18 , NULL ) ;
if ( V_24 == V_194 ) {
F_14 (KERN_WARNING FW_BUG
L_47
L_48
L_49
L_50 ) ;
if ( ! V_224 )
return - V_60 ;
}
V_20 = F_32 ( sizeof( struct V_63 ) , V_82 ) ;
if ( ! V_20 )
return - V_84 ;
if ( ! strcmp ( V_18 -> V_225 . V_226 , L_51 ) ) {
if ( V_227 )
V_18 -> V_225 . V_226 [ 3 ] = '0' + V_227 ;
V_227 ++ ;
}
if ( ! strcmp ( V_18 -> V_225 . V_226 , L_52 ) ) {
if ( V_227 )
V_18 -> V_225 . V_226 [ 3 ] = '0' + V_227 ;
V_227 ++ ;
}
V_20 -> V_18 = V_18 ;
strcpy ( F_44 ( V_18 ) , V_193 ) ;
strcpy ( F_45 ( V_18 ) , V_116 ) ;
V_18 -> V_117 = V_20 ;
F_37 ( V_20 ) ;
error = F_38 ( V_20 ) ;
if ( error )
goto V_228;
F_115 ( & V_20 -> V_134 ) ;
F_116 ( & V_20 -> V_136 ) ;
error = F_62 ( V_20 , V_18 ) ;
if ( error )
goto V_229;
F_14 (KERN_INFO PREFIX L_53 ,
ACPI_VIDEO_DEVICE_NAME, acpi_device_bid(device),
video->flags.multihead ? L_54 : L_55 ,
video->flags.rom ? L_54 : L_55 ,
video->flags.post ? L_54 : L_55 ) ;
F_48 ( & V_230 ) ;
F_49 ( & V_20 -> V_135 , & V_231 ) ;
F_50 ( & V_230 ) ;
F_88 ( V_20 ) ;
F_99 ( V_20 ) ;
return 0 ;
V_229:
F_110 ( V_20 ) ;
F_15 ( V_20 -> V_109 ) ;
V_228:
F_15 ( V_20 ) ;
V_18 -> V_117 = NULL ;
return error ;
}
static int F_117 ( struct V_17 * V_18 )
{
struct V_63 * V_20 = NULL ;
if ( ! V_18 || ! F_8 ( V_18 ) )
return - V_7 ;
V_20 = F_8 ( V_18 ) ;
F_108 ( V_20 ) ;
F_95 ( V_20 ) ;
F_110 ( V_20 ) ;
F_48 ( & V_230 ) ;
F_112 ( & V_20 -> V_135 ) ;
F_50 ( & V_230 ) ;
F_15 ( V_20 -> V_109 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static int T_5 F_118 ( struct V_100 * V_29 )
{
if ( V_29 -> V_18 == 0x00D1 )
return 1 ;
if ( V_29 -> V_18 == 0x7000 )
return 1 ;
return 0 ;
}
static int T_5 F_119 ( void )
{
int V_232 = 0 ;
struct V_100 * V_29 = NULL ;
T_3 V_233 ;
F_120 (dev) {
if ( ( V_29 -> V_234 >> 8 ) != V_235 )
continue;
if ( V_29 -> V_236 != V_237 )
continue;
if ( F_118 ( V_29 ) )
continue;
F_121 ( V_29 , 0xfc , & V_233 ) ;
if ( ! V_233 )
continue;
V_232 = 1 ;
}
return V_232 ;
}
int F_122 ( void )
{
int V_238 = 0 ;
F_48 ( & V_239 ) ;
if ( V_240 ) {
goto V_241;
}
F_115 ( & V_230 ) ;
F_116 ( & V_231 ) ;
F_123 ( V_242 ) ;
V_238 = F_124 ( & V_63 ) ;
if ( V_238 )
goto V_241;
V_240 = 1 ;
V_241:
F_50 ( & V_239 ) ;
return V_238 ;
}
void F_125 ( void )
{
F_48 ( & V_239 ) ;
if ( V_240 ) {
F_126 ( & V_63 ) ;
V_240 = 0 ;
}
F_50 ( & V_239 ) ;
}
void F_127 ( void )
{
struct V_63 * V_20 ;
F_48 ( & V_239 ) ;
if ( V_240 ) {
F_48 ( & V_230 ) ;
F_52 (video, &video_bus_head, entry)
F_95 ( V_20 ) ;
F_50 ( & V_230 ) ;
}
F_50 ( & V_239 ) ;
}
static int T_5 F_128 ( void )
{
if ( V_243 )
return 0 ;
if ( F_119 () )
return 0 ;
return F_122 () ;
}
static void T_6 F_129 ( void )
{
F_130 () ;
F_125 () ;
return;
}
