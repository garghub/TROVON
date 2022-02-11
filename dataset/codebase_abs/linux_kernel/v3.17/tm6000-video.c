static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( F_3 ( & V_2 -> V_8 ) ) {
F_4 ( V_6 , V_9 , L_1 ) ;
* V_4 = NULL ;
return;
}
* V_4 = F_5 ( V_2 -> V_8 . V_10 ,
struct V_3 , V_11 . V_12 ) ;
}
static inline void F_6 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_6 , V_13 , L_2 , V_4 , V_4 -> V_11 . V_14 ) ;
V_4 -> V_11 . V_15 = V_16 ;
V_4 -> V_11 . V_17 ++ ;
F_7 ( & V_4 -> V_11 . V_18 ) ;
F_8 ( & V_4 -> V_11 . V_12 ) ;
F_9 ( & V_4 -> V_11 . V_19 ) ;
}
static int F_10 ( T_1 * V_20 , unsigned long V_21 ,
struct V_22 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
T_1 * V_24 = V_20 , * V_25 = V_20 + V_21 ;
unsigned long V_26 = 0 ;
int V_27 = 0 ;
unsigned int V_28 , V_29 , V_30 , V_31 , V_32 , V_33 , line , V_34 = 0 ;
struct V_3 * V_35 = NULL ;
char * V_36 = NULL ;
unsigned int V_37 ;
if ( ! V_6 -> V_38 ) {
F_1 ( V_2 , & V_35 ) ;
if ( ! V_35 )
return V_27 ;
V_36 = F_11 ( & V_35 -> V_11 ) ;
if ( ! V_36 )
return 0 ;
}
for ( V_24 = V_20 ; V_24 < V_25 ; ) {
if ( ! V_6 -> V_39 . V_28 ) {
if ( V_6 -> V_39 . V_40 > 0 ) {
V_26 = V_6 -> V_39 . V_41 ;
if ( 4 - V_6 -> V_39 . V_40 > 0 ) {
memcpy ( ( T_1 * ) & V_26 +
V_6 -> V_39 . V_40 ,
V_24 ,
4 - V_6 -> V_39 . V_40 ) ;
V_24 += 4 - V_6 -> V_39 . V_40 ;
}
V_6 -> V_39 . V_40 = 0 ;
} else {
if ( V_24 + 3 >= V_25 ) {
V_6 -> V_39 . V_40 = V_25 - V_24 ;
memcpy ( & V_6 -> V_39 . V_41 , V_24 ,
V_6 -> V_39 . V_40 ) ;
return V_27 ;
}
for (; V_24 < V_25 - 3 ; V_24 ++ ) {
if ( * ( V_24 + 3 ) == 0x47 )
break;
}
V_26 = * ( unsigned long * ) V_24 ;
V_24 += 4 ;
}
V_31 = ( ( V_26 & 0x7e ) << 1 ) ;
if ( V_31 > 0 )
V_31 -= 4 ;
V_33 = ( V_26 >> 7 ) & 0xf ;
V_32 = ( V_26 >> 11 ) & 0x1 ;
line = ( V_26 >> 12 ) & 0x1ff ;
V_28 = ( V_26 >> 21 ) & 0x7 ;
if ( V_31 > V_42 )
V_31 = V_42 ;
V_30 = V_42 ;
switch ( V_28 ) {
case V_43 :
if ( ! V_6 -> V_38 ) {
if ( ( V_6 -> V_39 . V_44 != V_32 ) &&
( V_32 == 1 ) ) {
F_6 ( V_6 , V_2 , V_35 ) ;
F_4 ( V_6 , V_13 ,
L_3 ) ;
F_1 ( V_2 , & V_35 ) ;
if ( ! V_35 )
return V_27 ;
V_36 = F_11 ( & V_35 -> V_11 ) ;
if ( ! V_36 )
return V_27 ;
memset ( V_36 , 0 , V_35 -> V_11 . V_31 ) ;
}
V_37 = V_35 -> V_11 . V_45 << 1 ;
V_34 = ( ( line << 1 ) - V_32 - 1 ) *
V_37 + V_33 * V_42 ;
if ( V_34 + V_31 > V_35 -> V_11 . V_31 )
V_28 = V_46 ;
V_6 -> V_39 . V_44 = V_32 ;
}
break;
case V_47 :
break;
case V_48 :
case V_49 :
V_31 = V_30 ;
break;
}
} else {
V_28 = V_6 -> V_39 . V_28 ;
V_31 = V_6 -> V_39 . V_31 ;
V_34 = V_6 -> V_39 . V_34 ;
V_30 = V_6 -> V_39 . V_30 ;
V_32 = V_6 -> V_39 . V_32 ;
}
V_29 = ( V_25 - V_24 > V_31 ) ? V_31 : V_25 - V_24 ;
if ( V_29 ) {
switch ( V_28 ) {
case V_43 :
if ( V_35 )
memcpy ( & V_36 [ V_34 ] , V_24 , V_29 ) ;
break;
case V_48 : {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_29 ; V_14 += 2 )
F_12 ( ( V_50 * ) ( V_24 + V_14 ) ) ;
F_13 ( V_6 , V_51 , V_24 , V_29 ) ;
break;
}
case V_47 :
break;
case V_49 : {
T_2 V_52 ;
V_52 = * ( T_2 * ) V_24 ;
F_4 ( V_6 , V_13 , L_4 ,
V_32 , V_52 ) ;
break;
}
}
}
if ( V_24 + V_30 > V_25 ) {
V_6 -> V_39 . V_34 = V_34 + V_29 ;
V_6 -> V_39 . V_31 = V_31 - V_29 ;
V_6 -> V_39 . V_28 = V_28 ;
V_6 -> V_39 . V_32 = V_32 ;
V_6 -> V_39 . V_30 = V_30 - ( V_25 - V_24 ) ;
V_24 += V_25 - V_24 ;
} else {
V_6 -> V_39 . V_28 = 0 ;
V_24 += V_30 ;
}
}
return 0 ;
}
static int F_14 ( T_1 * V_24 , unsigned long V_21 ,
struct V_22 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
unsigned int V_34 = V_6 -> V_39 . V_34 , V_29 ;
int V_27 = 1 ;
struct V_3 * V_4 ;
char * V_53 = NULL ;
F_1 ( V_2 , & V_4 ) ;
if ( V_4 )
V_53 = F_11 ( & V_4 -> V_11 ) ;
if ( ! V_53 )
return 0 ;
while ( V_21 > 0 ) {
V_29 = F_15 ( V_21 , V_4 -> V_11 . V_31 - V_34 ) ;
memcpy ( & V_53 [ V_34 ] , V_24 , V_29 ) ;
V_34 += V_29 ;
V_24 += V_29 ;
V_21 -= V_29 ;
if ( V_34 >= V_4 -> V_11 . V_31 ) {
V_34 = 0 ;
F_6 ( V_6 , V_2 , V_4 ) ;
F_4 ( V_6 , V_13 , L_3 ) ;
F_1 ( V_2 , & V_4 ) ;
if ( ! V_4 )
break;
V_53 = F_11 ( & ( V_4 -> V_11 ) ) ;
if ( ! V_53 )
return V_27 ;
V_34 = 0 ;
}
}
V_6 -> V_39 . V_34 = V_34 ;
return V_27 ;
}
static inline void F_16 ( struct V_5 * V_6 ,
int V_54 , int V_55 )
{
char * V_56 = L_5 ;
switch ( V_55 ) {
case - V_57 :
V_56 = L_6 ;
break;
case - V_58 :
V_56 = L_7 ;
break;
case - V_59 :
V_56 = L_8 ;
break;
case - V_60 :
V_56 = L_9 ;
break;
case - V_61 :
V_56 = L_10 ;
break;
case - V_62 :
V_56 = L_11 ;
break;
case - V_63 :
V_56 = L_12 ;
break;
case - V_64 :
V_56 = L_13 ;
break;
}
if ( V_54 < 0 ) {
F_4 ( V_6 , V_9 , L_14 ,
V_55 , V_56 ) ;
} else {
F_4 ( V_6 , V_9 , L_15 ,
V_54 , V_55 , V_56 ) ;
}
}
static inline int F_17 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
int V_14 , V_21 = 0 , V_27 = 1 , V_55 ;
char * V_65 ;
if ( V_22 -> V_55 < 0 ) {
F_16 ( V_6 , - 1 , V_22 -> V_55 ) ;
return 0 ;
}
for ( V_14 = 0 ; V_14 < V_22 -> V_66 ; V_14 ++ ) {
V_55 = V_22 -> V_67 [ V_14 ] . V_55 ;
if ( V_55 < 0 ) {
F_16 ( V_6 , V_14 , V_55 ) ;
continue;
}
V_21 = V_22 -> V_67 [ V_14 ] . V_68 ;
if ( V_21 > 0 ) {
V_65 = V_22 -> V_69 + V_22 -> V_67 [ V_14 ] . V_70 ;
if ( ! V_22 -> V_67 [ V_14 ] . V_55 ) {
if ( ( V_6 -> V_71 ) == V_72 ) {
V_27 = F_14 ( V_65 , V_21 , V_22 ) ;
if ( V_27 <= 0 )
return V_27 ;
} else {
F_10 ( V_65 , V_21 , V_22 ) ;
}
}
}
}
return V_27 ;
}
static void F_18 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
int V_14 ;
switch ( V_22 -> V_55 ) {
case 0 :
case - V_73 :
break;
case - V_58 :
case - V_57 :
case - V_74 :
return;
default:
F_19 ( L_16 , V_22 -> V_55 ) ;
break;
}
F_20 ( & V_6 -> V_75 ) ;
F_17 ( V_22 ) ;
F_21 ( & V_6 -> V_75 ) ;
for ( V_14 = 0 ; V_14 < V_22 -> V_66 ; V_14 ++ ) {
V_22 -> V_67 [ V_14 ] . V_55 = 0 ;
V_22 -> V_67 [ V_14 ] . V_68 = 0 ;
}
V_22 -> V_55 = F_22 ( V_22 , V_76 ) ;
if ( V_22 -> V_55 )
F_19 ( L_17 ,
V_22 -> V_55 ) ;
}
static int F_23 ( struct V_5 * V_6 )
{
int V_77 = V_78 ;
int V_14 ;
if ( V_6 -> V_79 != NULL )
return 0 ;
V_6 -> V_79 = F_24 ( sizeof( void * ) * V_77 , V_80 ) ;
if ( ! V_6 -> V_79 ) {
F_19 ( L_18 ) ;
return - V_81 ;
}
V_6 -> V_82 = F_24 ( sizeof( V_83 * ) * V_77 , V_80 ) ;
if ( ! V_6 -> V_82 ) {
F_19 ( L_19 ) ;
return - V_81 ;
}
for ( V_14 = 0 ; V_14 < V_77 ; V_14 ++ ) {
V_6 -> V_79 [ V_14 ] = F_25 (
V_6 -> V_84 , V_6 -> V_85 ,
V_80 , & V_6 -> V_82 [ V_14 ] ) ;
if ( ! V_6 -> V_79 [ V_14 ] ) {
F_19 ( L_20 ,
V_6 -> V_85 , V_14 ) ;
return - V_81 ;
}
memset ( V_6 -> V_79 [ V_14 ] , 0 , V_6 -> V_85 ) ;
}
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
int V_14 ;
if ( V_6 -> V_79 == NULL )
return 0 ;
for ( V_14 = 0 ; V_14 < V_78 ; V_14 ++ ) {
if ( V_6 -> V_79 [ V_14 ] ) {
F_27 ( V_6 -> V_84 ,
V_6 -> V_85 ,
V_6 -> V_79 [ V_14 ] ,
V_6 -> V_82 [ V_14 ] ) ;
V_6 -> V_79 [ V_14 ] = NULL ;
}
}
F_28 ( V_6 -> V_79 ) ;
F_28 ( V_6 -> V_82 ) ;
V_6 -> V_79 = NULL ;
V_6 -> V_82 = NULL ;
return 0 ;
}
static void F_29 ( struct V_5 * V_6 )
{
struct V_22 * V_22 ;
int V_14 ;
V_6 -> V_39 . V_4 = NULL ;
for ( V_14 = 0 ; V_14 < V_6 -> V_39 . V_77 ; V_14 ++ ) {
V_22 = V_6 -> V_39 . V_22 [ V_14 ] ;
if ( V_22 ) {
F_30 ( V_22 ) ;
F_31 ( V_22 ) ;
F_32 ( V_22 ) ;
V_6 -> V_39 . V_22 [ V_14 ] = NULL ;
}
V_6 -> V_39 . V_69 [ V_14 ] = NULL ;
}
if ( ! V_86 )
F_26 ( V_6 ) ;
F_28 ( V_6 -> V_39 . V_22 ) ;
F_28 ( V_6 -> V_39 . V_69 ) ;
V_6 -> V_39 . V_22 = NULL ;
V_6 -> V_39 . V_69 = NULL ;
V_6 -> V_39 . V_77 = 0 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_7 ;
int V_14 , V_87 , V_88 , V_89 , V_31 , V_90 ;
int V_77 = V_78 ;
struct V_22 * V_22 ;
F_29 ( V_6 ) ;
F_34 ( V_6 ) ;
F_35 ( V_6 -> V_84 ,
V_6 -> V_91 . V_92 ,
V_6 -> V_91 . V_93 ) ;
F_36 ( V_6 ) ;
V_89 = F_37 ( V_6 -> V_84 ,
V_6 -> V_91 . V_25 -> V_94 . V_95 &
V_96 ) ;
V_31 = F_38 ( V_6 -> V_84 , V_89 , F_39 ( V_89 ) ) ;
if ( V_31 > V_6 -> V_91 . V_97 )
V_31 = V_6 -> V_91 . V_97 ;
V_6 -> V_39 . V_98 = V_31 ;
V_90 = V_99 ;
V_88 = V_90 * V_31 ;
V_6 -> V_85 = V_88 ;
V_6 -> V_39 . V_77 = V_77 ;
V_6 -> V_39 . V_22 = F_24 ( sizeof( void * ) * V_77 , V_80 ) ;
if ( ! V_6 -> V_39 . V_22 ) {
F_19 ( L_21 ) ;
return - V_81 ;
}
V_6 -> V_39 . V_69 = F_24 ( sizeof( void * ) * V_77 ,
V_80 ) ;
if ( ! V_6 -> V_39 . V_69 ) {
F_19 ( L_22 ) ;
F_28 ( V_6 -> V_39 . V_22 ) ;
return - V_81 ;
}
F_4 ( V_6 , V_9 , L_23
L_24 ,
V_90 , V_77 , V_88 ,
V_6 -> V_91 . V_97 , V_31 ) ;
if ( ! V_6 -> V_79 && F_23 ( V_6 ) < 0 ) {
F_19 ( L_18 ) ;
F_26 ( V_6 ) ;
F_28 ( V_6 -> V_39 . V_22 ) ;
F_28 ( V_6 -> V_39 . V_69 ) ;
return - V_81 ;
}
for ( V_14 = 0 ; V_14 < V_6 -> V_39 . V_77 ; V_14 ++ ) {
V_22 = F_40 ( V_90 , V_80 ) ;
if ( ! V_22 ) {
F_19 ( L_25 , V_14 ) ;
F_29 ( V_6 ) ;
F_32 ( V_22 ) ;
return - V_81 ;
}
V_6 -> V_39 . V_22 [ V_14 ] = V_22 ;
V_22 -> V_100 = V_6 -> V_82 [ V_14 ] ;
V_6 -> V_39 . V_69 [ V_14 ] = V_6 -> V_79 [ V_14 ] ;
F_41 ( V_22 , V_6 -> V_84 , V_89 ,
V_6 -> V_39 . V_69 [ V_14 ] , V_88 ,
F_18 , V_2 ) ;
V_22 -> V_101 = V_6 -> V_91 . V_25 -> V_94 . V_102 ;
V_22 -> V_66 = V_90 ;
V_22 -> V_103 = V_104 | V_105 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
V_22 -> V_67 [ V_87 ] . V_70 = V_31 * V_87 ;
V_22 -> V_67 [ V_87 ] . V_106 = V_31 ;
}
}
return 0 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_7 ;
int V_14 ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = V_109 ;
F_43 ( & V_2 -> V_110 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_39 . V_77 ; V_14 ++ ) {
int V_27 = F_22 ( V_6 -> V_39 . V_22 [ V_14 ] , V_76 ) ;
if ( V_27 ) {
F_19 ( L_26 , V_14 ,
V_27 ) ;
F_29 ( V_6 ) ;
return V_27 ;
}
}
return 0 ;
}
static int
F_44 ( struct V_111 * V_112 , unsigned int * V_113 , unsigned int * V_31 )
{
struct V_114 * V_115 = V_112 -> V_116 ;
* V_31 = V_115 -> V_117 -> V_118 * V_115 -> V_45 * V_115 -> V_119 >> 3 ;
if ( 0 == * V_113 )
* V_113 = V_120 ;
if ( * V_113 < V_121 )
* V_113 = V_121 ;
while ( * V_31 * * V_113 > V_122 * 1024 * 1024 )
( * V_113 ) -- ;
return 0 ;
}
static void F_45 ( struct V_111 * V_112 , struct V_3 * V_4 )
{
struct V_114 * V_115 = V_112 -> V_116 ;
struct V_5 * V_6 = V_115 -> V_6 ;
unsigned long V_123 ;
if ( F_46 () )
F_47 () ;
F_48 ( & V_6 -> V_75 , V_123 ) ;
if ( V_6 -> V_39 . V_4 == V_4 )
V_6 -> V_39 . V_4 = NULL ;
F_49 ( & V_6 -> V_75 , V_123 ) ;
F_50 ( & V_4 -> V_11 ) ;
V_4 -> V_11 . V_15 = V_124 ;
}
static int
F_51 ( struct V_111 * V_112 , struct V_125 * V_11 ,
enum V_126 V_32 )
{
struct V_114 * V_115 = V_112 -> V_116 ;
struct V_3 * V_4 = F_2 ( V_11 , struct V_3 , V_11 ) ;
struct V_5 * V_6 = V_115 -> V_6 ;
int V_27 = 0 ;
F_52 ( NULL == V_115 -> V_117 ) ;
V_4 -> V_11 . V_31 = V_115 -> V_117 -> V_118 * V_115 -> V_45 * V_115 -> V_119 >> 3 ;
if ( 0 != V_4 -> V_11 . V_127 && V_4 -> V_11 . V_128 < V_4 -> V_11 . V_31 )
return - V_129 ;
if ( V_4 -> V_117 != V_115 -> V_117 ||
V_4 -> V_11 . V_45 != V_115 -> V_45 ||
V_4 -> V_11 . V_119 != V_115 -> V_119 ||
V_4 -> V_11 . V_32 != V_32 ) {
V_4 -> V_117 = V_115 -> V_117 ;
V_4 -> V_11 . V_45 = V_115 -> V_45 ;
V_4 -> V_11 . V_119 = V_115 -> V_119 ;
V_4 -> V_11 . V_32 = V_32 ;
V_4 -> V_11 . V_15 = V_124 ;
}
if ( V_124 == V_4 -> V_11 . V_15 ) {
V_27 = F_53 ( V_112 , & V_4 -> V_11 , NULL ) ;
if ( V_27 != 0 )
goto V_130;
}
if ( ! V_6 -> V_39 . V_77 ) {
V_27 = F_33 ( V_6 ) ;
if ( V_27 < 0 )
goto V_130;
V_27 = F_42 ( V_6 ) ;
if ( V_27 < 0 )
goto V_130;
}
V_4 -> V_11 . V_15 = V_131 ;
return 0 ;
V_130:
F_45 ( V_112 , V_4 ) ;
return V_27 ;
}
static void
F_54 ( struct V_111 * V_112 , struct V_125 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 , struct V_3 , V_11 ) ;
struct V_114 * V_115 = V_112 -> V_116 ;
struct V_5 * V_6 = V_115 -> V_6 ;
struct V_1 * V_7 = & V_6 -> V_7 ;
V_4 -> V_11 . V_15 = V_132 ;
F_55 ( & V_4 -> V_11 . V_12 , & V_7 -> V_8 ) ;
}
static void F_56 ( struct V_111 * V_112 , struct V_125 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 , struct V_3 , V_11 ) ;
F_45 ( V_112 , V_4 ) ;
}
static bool F_57 ( struct V_5 * V_6 , struct V_114 * V_115 )
{
if ( V_6 -> V_133 == V_115 && V_6 -> F_57 )
return true ;
return false ;
}
static bool F_58 ( struct V_5 * V_6 , struct V_114 * V_115 )
{
if ( V_6 -> V_133 == V_115 )
return true ;
return false ;
}
static bool F_59 ( struct V_5 * V_6 , struct V_114 * V_115 ,
bool F_57 )
{
if ( V_6 -> V_133 == V_115 && V_6 -> F_57 == F_57 )
return true ;
if ( V_6 -> V_133 )
return false ;
V_6 -> V_133 = V_115 ;
V_6 -> F_57 = F_57 ;
F_4 ( V_6 , V_134 , L_27 ) ;
return true ;
}
static void F_60 ( struct V_5 * V_6 , struct V_114 * V_115 )
{
if ( V_6 -> V_133 != V_115 )
return;
V_6 -> V_133 = NULL ;
F_4 ( V_6 , V_134 , L_28 ) ;
}
static int F_61 ( struct V_135 * V_135 , void * V_136 ,
struct V_137 * V_138 )
{
struct V_5 * V_6 = ( (struct V_114 * ) V_136 ) -> V_6 ;
struct V_139 * V_140 = F_62 ( V_135 ) ;
F_63 ( V_138 -> V_141 , L_29 , sizeof( V_138 -> V_141 ) ) ;
F_63 ( V_138 -> V_142 , L_30 , sizeof( V_138 -> V_142 ) ) ;
F_64 ( V_6 -> V_84 , V_138 -> V_143 , sizeof( V_138 -> V_143 ) ) ;
if ( V_6 -> V_144 != V_145 )
V_138 -> V_146 |= V_147 ;
if ( V_140 -> V_148 == V_149 )
V_138 -> V_146 |= V_150 |
V_151 |
V_152 ;
else
V_138 -> V_146 |= V_153 ;
V_138 -> V_154 = V_138 -> V_146 | V_155 |
V_153 | V_150 | V_152 ;
return 0 ;
}
static int F_65 ( struct V_135 * V_135 , void * V_136 ,
struct V_156 * V_157 )
{
if ( V_157 -> V_158 >= F_66 ( V_159 ) )
return - V_129 ;
F_63 ( V_157 -> V_160 , V_159 [ V_157 -> V_158 ] . V_161 , sizeof( V_157 -> V_160 ) ) ;
V_157 -> V_162 = V_159 [ V_157 -> V_158 ] . V_71 ;
return 0 ;
}
static int F_67 ( struct V_135 * V_135 , void * V_136 ,
struct V_163 * V_157 )
{
struct V_114 * V_115 = V_136 ;
V_157 -> V_117 . V_164 . V_45 = V_115 -> V_45 ;
V_157 -> V_117 . V_164 . V_119 = V_115 -> V_119 ;
V_157 -> V_117 . V_164 . V_32 = V_115 -> V_165 . V_32 ;
V_157 -> V_117 . V_164 . V_162 = V_115 -> V_117 -> V_71 ;
V_157 -> V_117 . V_164 . V_166 = V_167 ;
V_157 -> V_117 . V_164 . V_168 =
( V_157 -> V_117 . V_164 . V_45 * V_115 -> V_117 -> V_118 ) >> 3 ;
V_157 -> V_117 . V_164 . V_169 =
V_157 -> V_117 . V_164 . V_119 * V_157 -> V_117 . V_164 . V_168 ;
return 0 ;
}
static struct V_170 * F_68 ( unsigned int V_71 )
{
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_66 ( V_159 ) ; V_14 ++ )
if ( V_159 [ V_14 ] . V_71 == V_71 )
return V_159 + V_14 ;
return NULL ;
}
static int F_69 ( struct V_135 * V_135 , void * V_136 ,
struct V_163 * V_157 )
{
struct V_5 * V_6 = ( (struct V_114 * ) V_136 ) -> V_6 ;
struct V_170 * V_117 ;
enum V_126 V_32 ;
V_117 = F_68 ( V_157 -> V_117 . V_164 . V_162 ) ;
if ( NULL == V_117 ) {
F_4 ( V_6 , V_171 , L_31
L_32 , V_157 -> V_117 . V_164 . V_162 ) ;
return - V_129 ;
}
V_32 = V_157 -> V_117 . V_164 . V_32 ;
V_32 = V_172 ;
F_70 ( V_6 ) ;
V_157 -> V_117 . V_164 . V_45 = V_6 -> V_45 ;
V_157 -> V_117 . V_164 . V_119 = V_6 -> V_119 ;
V_157 -> V_117 . V_164 . V_45 &= ~ 0x01 ;
V_157 -> V_117 . V_164 . V_32 = V_32 ;
V_157 -> V_117 . V_164 . V_168 =
( V_157 -> V_117 . V_164 . V_45 * V_117 -> V_118 ) >> 3 ;
V_157 -> V_117 . V_164 . V_169 =
V_157 -> V_117 . V_164 . V_119 * V_157 -> V_117 . V_164 . V_168 ;
V_157 -> V_117 . V_164 . V_166 = V_167 ;
return 0 ;
}
static int F_71 ( struct V_135 * V_135 , void * V_136 ,
struct V_163 * V_157 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
int V_173 = F_69 ( V_135 , V_115 , V_157 ) ;
if ( V_173 < 0 )
return V_173 ;
V_115 -> V_117 = F_68 ( V_157 -> V_117 . V_164 . V_162 ) ;
V_115 -> V_45 = V_157 -> V_117 . V_164 . V_45 ;
V_115 -> V_119 = V_157 -> V_117 . V_164 . V_119 ;
V_115 -> V_165 . V_32 = V_157 -> V_117 . V_164 . V_32 ;
V_115 -> type = V_157 -> type ;
V_6 -> V_71 = V_157 -> V_117 . V_164 . V_162 ;
F_72 ( V_6 ) ;
return 0 ;
}
static int F_73 ( struct V_135 * V_135 , void * V_136 ,
struct V_174 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_74 ( & V_115 -> V_165 , V_65 ) ;
}
static int F_75 ( struct V_135 * V_135 , void * V_136 ,
struct V_175 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_76 ( & V_115 -> V_165 , V_65 ) ;
}
static int F_77 ( struct V_135 * V_135 , void * V_136 , struct V_175 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_78 ( & V_115 -> V_165 , V_65 ) ;
}
static int F_79 ( struct V_135 * V_135 , void * V_136 , struct V_175 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_80 ( & V_115 -> V_165 , V_65 ,
V_135 -> V_176 & V_177 ) ;
}
static int F_81 ( struct V_135 * V_135 , void * V_136 , enum V_178 V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_115 -> type != V_179 )
return - V_129 ;
if ( V_14 != V_115 -> type )
return - V_129 ;
if ( ! F_59 ( V_6 , V_115 , false ) )
return - V_180 ;
return F_82 ( & V_115 -> V_165 ) ;
}
static int F_83 ( struct V_135 * V_135 , void * V_136 , enum V_178 V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_115 -> type != V_179 )
return - V_129 ;
if ( V_14 != V_115 -> type )
return - V_129 ;
F_84 ( & V_115 -> V_165 ) ;
F_60 ( V_6 , V_115 ) ;
return 0 ;
}
static int F_85 ( struct V_135 * V_135 , void * V_136 , T_3 V_181 )
{
int V_27 = 0 ;
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
V_6 -> V_181 = V_181 ;
V_27 = F_86 ( V_6 ) ;
V_115 -> V_45 = V_6 -> V_45 ;
V_115 -> V_119 = V_6 -> V_119 ;
if ( V_27 < 0 )
return V_27 ;
F_87 ( & V_6 -> V_182 , 0 , V_183 , V_184 , V_6 -> V_181 ) ;
return 0 ;
}
static int F_88 ( struct V_135 * V_135 , void * V_136 , T_3 * V_181 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
* V_181 = V_6 -> V_181 ;
return 0 ;
}
static int F_89 ( struct V_135 * V_135 , void * V_136 ,
struct V_185 * V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
unsigned int V_186 ;
V_186 = V_14 -> V_158 ;
if ( V_186 >= 3 )
return - V_129 ;
if ( ! V_6 -> V_187 [ V_186 ] . type )
return - V_129 ;
V_14 -> V_158 = V_186 ;
if ( V_6 -> V_187 [ V_186 ] . type == V_188 )
V_14 -> type = V_189 ;
else
V_14 -> type = V_190 ;
strcpy ( V_14 -> V_161 , V_191 [ V_6 -> V_187 [ V_186 ] . type ] ) ;
V_14 -> V_192 = V_193 ;
return 0 ;
}
static int F_90 ( struct V_135 * V_135 , void * V_136 , unsigned int * V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
* V_14 = V_6 -> V_194 ;
return 0 ;
}
static int F_91 ( struct V_135 * V_135 , void * V_136 , unsigned int V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
int V_27 = 0 ;
if ( V_14 >= 3 )
return - V_129 ;
if ( ! V_6 -> V_187 [ V_14 ] . type )
return - V_129 ;
V_6 -> V_194 = V_14 ;
V_27 = F_85 ( V_135 , V_136 , V_6 -> V_181 ) ;
return V_27 ;
}
static int F_92 ( struct V_195 * V_196 )
{
struct V_5 * V_6 = F_2 ( V_196 -> V_197 , struct V_5 , V_198 ) ;
T_1 V_199 = V_196 -> V_199 ;
switch ( V_196 -> V_200 ) {
case V_201 :
F_93 ( V_6 , V_202 , V_199 ) ;
return 0 ;
case V_203 :
F_93 ( V_6 , V_204 , V_199 ) ;
return 0 ;
case V_205 :
F_93 ( V_6 , V_206 , V_199 ) ;
return 0 ;
case V_207 :
F_93 ( V_6 , V_208 , V_199 ) ;
return 0 ;
}
return - V_129 ;
}
static int F_94 ( struct V_195 * V_196 )
{
struct V_5 * V_6 = F_2 ( V_196 -> V_197 ,
struct V_5 , V_209 ) ;
T_1 V_199 = V_196 -> V_199 ;
switch ( V_196 -> V_200 ) {
case V_210 :
V_6 -> V_211 = V_199 ;
F_95 ( V_6 , V_199 ) ;
return 0 ;
case V_212 :
V_6 -> V_213 = V_199 ;
F_96 ( V_6 , V_199 ) ;
return 0 ;
}
return - V_129 ;
}
static int F_97 ( struct V_135 * V_135 , void * V_136 ,
struct V_214 * V_215 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_216 == V_6 -> V_144 )
return - V_217 ;
if ( 0 != V_215 -> V_158 )
return - V_129 ;
strcpy ( V_215 -> V_161 , L_33 ) ;
V_215 -> type = V_218 ;
V_215 -> V_219 = V_220 | V_221 ;
V_215 -> V_222 = 0xffffffffUL ;
V_215 -> V_223 = V_224 ;
F_87 ( & V_6 -> V_182 , 0 , V_225 , V_226 , V_215 ) ;
V_215 -> V_227 = V_6 -> V_228 ;
return 0 ;
}
static int F_98 ( struct V_135 * V_135 , void * V_136 ,
const struct V_214 * V_215 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_216 == V_6 -> V_144 )
return - V_217 ;
if ( 0 != V_215 -> V_158 )
return - V_129 ;
if ( V_215 -> V_227 > V_229 )
V_6 -> V_228 = V_229 ;
else
V_6 -> V_228 = V_215 -> V_227 ;
F_4 ( V_6 , 3 , L_34 , V_215 -> V_227 ) ;
F_87 ( & V_6 -> V_182 , 0 , V_225 , V_230 , V_215 ) ;
return 0 ;
}
static int F_99 ( struct V_135 * V_135 , void * V_136 ,
struct V_231 * V_157 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_216 == V_6 -> V_144 )
return - V_217 ;
if ( V_157 -> V_225 )
return - V_129 ;
V_157 -> V_232 = V_6 -> V_233 ;
F_87 ( & V_6 -> V_182 , 0 , V_225 , V_234 , V_157 ) ;
return 0 ;
}
static int F_100 ( struct V_135 * V_135 , void * V_136 ,
const struct V_231 * V_157 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_216 == V_6 -> V_144 )
return - V_217 ;
if ( V_157 -> V_225 != 0 )
return - V_129 ;
V_6 -> V_233 = V_157 -> V_232 ;
F_87 ( & V_6 -> V_182 , 0 , V_225 , V_235 , V_157 ) ;
return 0 ;
}
static int F_101 ( struct V_135 * V_135 , void * V_136 ,
struct V_214 * V_215 )
{
struct V_114 * V_115 = V_135 -> V_236 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( 0 != V_215 -> V_158 )
return - V_129 ;
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
strcpy ( V_215 -> V_161 , L_35 ) ;
V_215 -> type = V_237 ;
V_215 -> V_219 = V_238 | V_221 ;
V_215 -> V_223 = V_224 ;
V_215 -> V_227 = V_229 ;
F_87 ( & V_6 -> V_182 , 0 , V_225 , V_226 , V_215 ) ;
return 0 ;
}
static int F_102 ( struct V_135 * V_135 , void * V_136 ,
const struct V_214 * V_215 )
{
struct V_114 * V_115 = V_135 -> V_236 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( 0 != V_215 -> V_158 )
return - V_129 ;
F_87 ( & V_6 -> V_182 , 0 , V_225 , V_230 , V_215 ) ;
return 0 ;
}
static int F_103 ( struct V_135 * V_135 )
{
struct V_139 * V_140 = F_62 ( V_135 ) ;
struct V_5 * V_6 = F_104 ( V_135 ) ;
struct V_114 * V_115 ;
enum V_178 type = V_179 ;
int V_27 ;
int V_38 = 0 ;
F_4 ( V_6 , V_239 , L_36 ,
F_105 ( V_140 ) ) ;
switch ( V_140 -> V_148 ) {
case V_149 :
type = V_179 ;
break;
case V_240 :
type = V_241 ;
break;
case V_242 :
V_38 = 1 ;
break;
}
V_6 -> V_243 ++ ;
F_4 ( V_6 , V_239 , L_37 ,
F_105 ( V_140 ) , V_244 [ type ] ,
V_6 -> V_243 ) ;
V_115 = F_106 ( sizeof( * V_115 ) , V_80 ) ;
if ( NULL == V_115 ) {
V_6 -> V_243 -- ;
return - V_81 ;
}
F_107 ( & V_115 -> V_115 , V_140 ) ;
V_135 -> V_236 = V_115 ;
V_115 -> V_6 = V_6 ;
V_115 -> V_38 = V_38 ;
V_6 -> V_38 = V_38 ;
V_115 -> type = type ;
V_6 -> V_71 = V_159 [ 0 ] . V_71 ;
V_115 -> V_117 = F_68 ( V_6 -> V_71 ) ;
F_70 ( V_6 ) ;
V_115 -> V_45 = V_6 -> V_45 ;
V_115 -> V_119 = V_6 -> V_119 ;
F_4 ( V_6 , V_239 , L_38
L_39 ,
( unsigned long ) V_115 , ( unsigned long ) V_6 ,
( unsigned long ) & V_6 -> V_7 ) ;
F_4 ( V_6 , V_239 , L_40
L_41 , F_3 ( & V_6 -> V_7 . V_245 ) ) ;
F_4 ( V_6 , V_239 , L_40
L_42 , F_3 ( & V_6 -> V_7 . V_8 ) ) ;
V_27 = F_86 ( V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
V_6 -> V_246 = V_247 ;
if ( ! V_115 -> V_38 ) {
F_108 ( & V_115 -> V_165 , & V_248 ,
NULL , & V_6 -> V_75 ,
V_115 -> type ,
V_172 ,
sizeof( struct V_3 ) , V_115 , & V_6 -> V_249 ) ;
} else {
F_4 ( V_6 , V_239 , L_43 ) ;
F_109 ( V_6 ) ;
F_87 ( & V_6 -> V_182 , 0 , V_225 , V_250 ) ;
F_33 ( V_6 ) ;
F_42 ( V_6 ) ;
}
F_110 ( & V_115 -> V_115 ) ;
return 0 ;
}
static int F_111 ( struct V_135 * V_135 )
{
struct V_139 * V_140 = F_62 ( V_135 ) ;
int V_251 ;
F_112 ( V_140 -> V_249 ) ;
V_251 = F_103 ( V_135 ) ;
F_113 ( V_140 -> V_249 ) ;
return V_251 ;
}
static T_4
F_114 ( struct V_135 * V_135 , char T_5 * V_20 , T_6 V_113 , T_7 * V_34 )
{
struct V_114 * V_115 = V_135 -> V_236 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_115 -> type == V_179 ) {
int V_251 ;
if ( ! F_59 ( V_115 -> V_6 , V_115 , true ) )
return - V_180 ;
if ( F_115 ( & V_6 -> V_249 ) )
return - V_252 ;
V_251 = F_116 ( & V_115 -> V_165 , V_20 , V_113 , V_34 , 0 ,
V_135 -> V_176 & V_177 ) ;
F_113 ( & V_6 -> V_249 ) ;
return V_251 ;
}
return 0 ;
}
static unsigned int
F_117 ( struct V_135 * V_135 , struct V_253 * V_254 )
{
unsigned long V_255 = F_118 ( V_254 ) ;
struct V_114 * V_115 = V_135 -> V_236 ;
struct V_3 * V_4 ;
int V_251 = 0 ;
if ( F_119 ( & V_115 -> V_115 ) )
V_251 = V_256 ;
else if ( V_255 & V_256 )
F_120 ( V_135 , & V_115 -> V_115 . V_254 , V_254 ) ;
if ( V_179 != V_115 -> type )
return V_251 | V_257 ;
if ( ! ! F_58 ( V_115 -> V_6 , V_115 ) )
return V_251 | V_257 ;
if ( ! F_57 ( V_115 -> V_6 , V_115 ) ) {
if ( F_3 ( & V_115 -> V_165 . V_258 ) )
return V_251 | V_257 ;
V_4 = F_5 ( V_115 -> V_165 . V_258 . V_10 , struct V_3 , V_11 . V_258 ) ;
F_120 ( V_135 , & V_4 -> V_11 . V_19 , V_254 ) ;
if ( V_4 -> V_11 . V_15 == V_16 ||
V_4 -> V_11 . V_15 == V_259 )
return V_251 | V_260 | V_261 ;
} else if ( V_255 & ( V_260 | V_261 ) ) {
return V_251 | F_121 ( V_135 , & V_115 -> V_165 , V_254 ) ;
}
return V_251 ;
}
static unsigned int F_122 ( struct V_135 * V_135 , struct V_253 * V_254 )
{
struct V_114 * V_115 = V_135 -> V_236 ;
struct V_5 * V_6 = V_115 -> V_6 ;
unsigned int V_251 ;
F_112 ( & V_6 -> V_249 ) ;
V_251 = F_117 ( V_135 , V_254 ) ;
F_113 ( & V_6 -> V_249 ) ;
return V_251 ;
}
static int F_123 ( struct V_135 * V_135 )
{
struct V_114 * V_115 = V_135 -> V_236 ;
struct V_5 * V_6 = V_115 -> V_6 ;
struct V_139 * V_140 = F_62 ( V_135 ) ;
F_4 ( V_6 , V_239 , L_44 ,
F_105 ( V_140 ) , V_6 -> V_243 ) ;
F_112 ( & V_6 -> V_249 ) ;
V_6 -> V_243 -- ;
F_60 ( V_6 , V_115 ) ;
if ( ! V_6 -> V_243 ) {
F_29 ( V_6 ) ;
F_34 ( V_6 ) ;
F_124 ( V_6 -> V_84 ) ;
if ( V_6 -> V_262 . V_25 )
F_35 ( V_6 -> V_84 ,
V_6 -> V_91 . V_92 , 2 ) ;
else
F_35 ( V_6 -> V_84 ,
V_6 -> V_91 . V_92 , 0 ) ;
F_36 ( V_6 ) ;
if ( ! V_115 -> V_38 )
F_125 ( & V_115 -> V_165 ) ;
}
F_126 ( & V_115 -> V_115 ) ;
F_127 ( & V_115 -> V_115 ) ;
F_28 ( V_115 ) ;
F_113 ( & V_6 -> V_249 ) ;
return 0 ;
}
static int F_128 ( struct V_135 * V_135 , struct V_263 * V_264 )
{
struct V_114 * V_115 = V_135 -> V_236 ;
struct V_5 * V_6 = V_115 -> V_6 ;
int V_251 ;
if ( F_115 ( & V_6 -> V_249 ) )
return - V_252 ;
V_251 = F_129 ( & V_115 -> V_165 , V_264 ) ;
F_113 ( & V_6 -> V_249 ) ;
return V_251 ;
}
static struct V_139 * F_130 ( struct V_5 * V_6 ,
const struct V_139
* V_265 , const char * V_266 )
{
struct V_139 * V_267 ;
V_267 = F_131 () ;
if ( NULL == V_267 )
return NULL ;
* V_267 = * V_265 ;
V_267 -> V_182 = & V_6 -> V_182 ;
V_267 -> V_268 = V_269 ;
V_267 -> V_270 = V_271 ;
V_267 -> V_249 = & V_6 -> V_249 ;
snprintf ( V_267 -> V_161 , sizeof( V_267 -> V_161 ) , L_45 , V_6 -> V_161 , V_266 ) ;
F_132 ( V_267 , V_6 ) ;
return V_267 ;
}
int F_133 ( struct V_5 * V_6 )
{
int V_173 = 0 ;
F_134 ( & V_6 -> V_198 , 6 ) ;
F_134 ( & V_6 -> V_209 , 2 ) ;
F_135 ( & V_6 -> V_209 , & V_272 ,
V_210 , 0 , 1 , 1 , 0 ) ;
F_135 ( & V_6 -> V_209 , & V_272 ,
V_212 , - 15 , 15 , 1 , 0 ) ;
F_135 ( & V_6 -> V_198 , & V_273 ,
V_203 , 0 , 255 , 1 , 54 ) ;
F_135 ( & V_6 -> V_198 , & V_273 ,
V_201 , 0 , 255 , 1 , 119 ) ;
F_135 ( & V_6 -> V_198 , & V_273 ,
V_205 , 0 , 255 , 1 , 112 ) ;
F_135 ( & V_6 -> V_198 , & V_273 ,
V_207 , - 128 , 127 , 1 , 0 ) ;
F_136 ( & V_6 -> V_198 ,
& V_6 -> V_209 , NULL ) ;
if ( V_6 -> V_209 . error )
V_173 = V_6 -> V_209 . error ;
if ( ! V_173 && V_6 -> V_198 . error )
V_173 = V_6 -> V_198 . error ;
if ( V_173 )
goto V_274;
V_6 -> V_267 = F_130 ( V_6 , & V_275 , L_46 ) ;
if ( ! V_6 -> V_267 ) {
F_137 ( V_276 L_47 ,
V_6 -> V_161 ) ;
V_173 = - V_81 ;
goto V_274;
}
V_6 -> V_267 -> V_198 = & V_6 -> V_198 ;
F_138 ( & V_6 -> V_7 . V_8 ) ;
F_138 ( & V_6 -> V_7 . V_245 ) ;
V_173 = F_139 ( V_6 -> V_267 , V_149 , V_277 ) ;
if ( V_173 < 0 ) {
F_137 ( V_276 L_47 ,
V_6 -> V_161 ) ;
V_269 ( V_6 -> V_267 ) ;
V_6 -> V_267 = NULL ;
goto V_274;
}
F_137 ( V_276 L_48 ,
V_6 -> V_161 , F_105 ( V_6 -> V_267 ) ) ;
if ( V_6 -> V_278 . V_279 ) {
V_6 -> V_280 = F_130 ( V_6 , & V_281 ,
L_49 ) ;
if ( ! V_6 -> V_280 ) {
F_137 ( V_276 L_50 ,
V_6 -> V_161 ) ;
V_173 = - V_282 ;
goto V_283;
}
V_6 -> V_280 -> V_198 = & V_6 -> V_209 ;
V_173 = F_139 ( V_6 -> V_280 , V_242 ,
V_284 ) ;
if ( V_173 < 0 ) {
F_137 ( V_276 L_50 ,
V_6 -> V_161 ) ;
V_269 ( V_6 -> V_280 ) ;
goto V_283;
}
F_137 ( V_276 L_48 ,
V_6 -> V_161 , F_105 ( V_6 -> V_280 ) ) ;
}
F_137 ( V_276 L_51 , V_173 ) ;
return V_173 ;
V_283:
F_140 ( V_6 -> V_267 ) ;
V_274:
F_141 ( & V_6 -> V_198 ) ;
F_141 ( & V_6 -> V_209 ) ;
return V_173 ;
}
int F_142 ( struct V_5 * V_6 )
{
F_140 ( V_6 -> V_267 ) ;
F_26 ( V_6 ) ;
if ( V_6 -> V_280 ) {
if ( F_143 ( V_6 -> V_280 ) )
F_140 ( V_6 -> V_280 ) ;
else
V_269 ( V_6 -> V_280 ) ;
V_6 -> V_280 = NULL ;
}
return 0 ;
}
int F_144 ( void )
{
return 0 ;
}
