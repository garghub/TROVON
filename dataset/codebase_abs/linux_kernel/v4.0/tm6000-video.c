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
F_4 ( V_6 , 2 , L_31
L_32 , V_157 -> V_117 . V_164 . V_162 ) ;
return - V_129 ;
}
V_32 = V_157 -> V_117 . V_164 . V_32 ;
V_32 = V_171 ;
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
int V_172 = F_69 ( V_135 , V_115 , V_157 ) ;
if ( V_172 < 0 )
return V_172 ;
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
struct V_173 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_74 ( & V_115 -> V_165 , V_65 ) ;
}
static int F_75 ( struct V_135 * V_135 , void * V_136 ,
struct V_174 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_76 ( & V_115 -> V_165 , V_65 ) ;
}
static int F_77 ( struct V_135 * V_135 , void * V_136 , struct V_174 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_78 ( & V_115 -> V_165 , V_65 ) ;
}
static int F_79 ( struct V_135 * V_135 , void * V_136 , struct V_174 * V_65 )
{
struct V_114 * V_115 = V_136 ;
return F_80 ( & V_115 -> V_165 , V_65 ,
V_135 -> V_175 & V_176 ) ;
}
static int F_81 ( struct V_135 * V_135 , void * V_136 , enum V_177 V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_115 -> type != V_178 )
return - V_129 ;
if ( V_14 != V_115 -> type )
return - V_129 ;
if ( ! F_59 ( V_6 , V_115 , false ) )
return - V_179 ;
return F_82 ( & V_115 -> V_165 ) ;
}
static int F_83 ( struct V_135 * V_135 , void * V_136 , enum V_177 V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_115 -> type != V_178 )
return - V_129 ;
if ( V_14 != V_115 -> type )
return - V_129 ;
F_84 ( & V_115 -> V_165 ) ;
F_60 ( V_6 , V_115 ) ;
return 0 ;
}
static int F_85 ( struct V_135 * V_135 , void * V_136 , T_3 V_180 )
{
int V_27 = 0 ;
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
V_6 -> V_180 = V_180 ;
V_27 = F_86 ( V_6 ) ;
V_115 -> V_45 = V_6 -> V_45 ;
V_115 -> V_119 = V_6 -> V_119 ;
if ( V_27 < 0 )
return V_27 ;
F_87 ( & V_6 -> V_181 , 0 , V_182 , V_183 , V_6 -> V_180 ) ;
return 0 ;
}
static int F_88 ( struct V_135 * V_135 , void * V_136 , T_3 * V_180 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
* V_180 = V_6 -> V_180 ;
return 0 ;
}
static int F_89 ( struct V_135 * V_135 , void * V_136 ,
struct V_184 * V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
unsigned int V_185 ;
V_185 = V_14 -> V_158 ;
if ( V_185 >= 3 )
return - V_129 ;
if ( ! V_6 -> V_186 [ V_185 ] . type )
return - V_129 ;
V_14 -> V_158 = V_185 ;
if ( V_6 -> V_186 [ V_185 ] . type == V_187 )
V_14 -> type = V_188 ;
else
V_14 -> type = V_189 ;
strcpy ( V_14 -> V_161 , V_190 [ V_6 -> V_186 [ V_185 ] . type ] ) ;
V_14 -> V_191 = V_192 ;
return 0 ;
}
static int F_90 ( struct V_135 * V_135 , void * V_136 , unsigned int * V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
* V_14 = V_6 -> V_193 ;
return 0 ;
}
static int F_91 ( struct V_135 * V_135 , void * V_136 , unsigned int V_14 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
int V_27 = 0 ;
if ( V_14 >= 3 )
return - V_129 ;
if ( ! V_6 -> V_186 [ V_14 ] . type )
return - V_129 ;
V_6 -> V_193 = V_14 ;
V_27 = F_85 ( V_135 , V_136 , V_6 -> V_180 ) ;
return V_27 ;
}
static int F_92 ( struct V_194 * V_195 )
{
struct V_5 * V_6 = F_2 ( V_195 -> V_196 , struct V_5 , V_197 ) ;
T_1 V_198 = V_195 -> V_198 ;
switch ( V_195 -> V_199 ) {
case V_200 :
F_93 ( V_6 , V_201 , V_198 ) ;
return 0 ;
case V_202 :
F_93 ( V_6 , V_203 , V_198 ) ;
return 0 ;
case V_204 :
F_93 ( V_6 , V_205 , V_198 ) ;
return 0 ;
case V_206 :
F_93 ( V_6 , V_207 , V_198 ) ;
return 0 ;
}
return - V_129 ;
}
static int F_94 ( struct V_194 * V_195 )
{
struct V_5 * V_6 = F_2 ( V_195 -> V_196 ,
struct V_5 , V_208 ) ;
T_1 V_198 = V_195 -> V_198 ;
switch ( V_195 -> V_199 ) {
case V_209 :
V_6 -> V_210 = V_198 ;
F_95 ( V_6 , V_198 ) ;
return 0 ;
case V_211 :
V_6 -> V_212 = V_198 ;
F_96 ( V_6 , V_198 ) ;
return 0 ;
}
return - V_129 ;
}
static int F_97 ( struct V_135 * V_135 , void * V_136 ,
struct V_213 * V_214 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_215 == V_6 -> V_144 )
return - V_216 ;
if ( 0 != V_214 -> V_158 )
return - V_129 ;
strcpy ( V_214 -> V_161 , L_33 ) ;
V_214 -> type = V_217 ;
V_214 -> V_218 = V_219 | V_220 ;
V_214 -> V_221 = 0xffffffffUL ;
V_214 -> V_222 = V_223 ;
F_87 ( & V_6 -> V_181 , 0 , V_224 , V_225 , V_214 ) ;
V_214 -> V_226 = V_6 -> V_227 ;
return 0 ;
}
static int F_98 ( struct V_135 * V_135 , void * V_136 ,
const struct V_213 * V_214 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_215 == V_6 -> V_144 )
return - V_216 ;
if ( 0 != V_214 -> V_158 )
return - V_129 ;
if ( V_214 -> V_226 > V_228 )
V_6 -> V_227 = V_228 ;
else
V_6 -> V_227 = V_214 -> V_226 ;
F_4 ( V_6 , 3 , L_34 , V_214 -> V_226 ) ;
F_87 ( & V_6 -> V_181 , 0 , V_224 , V_229 , V_214 ) ;
return 0 ;
}
static int F_99 ( struct V_135 * V_135 , void * V_136 ,
struct V_230 * V_157 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_215 == V_6 -> V_144 )
return - V_216 ;
if ( V_157 -> V_224 )
return - V_129 ;
V_157 -> V_231 = V_6 -> V_232 ;
F_87 ( & V_6 -> V_181 , 0 , V_224 , V_233 , V_157 ) ;
return 0 ;
}
static int F_100 ( struct V_135 * V_135 , void * V_136 ,
const struct V_230 * V_157 )
{
struct V_114 * V_115 = V_136 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_215 == V_6 -> V_144 )
return - V_216 ;
if ( V_157 -> V_224 != 0 )
return - V_129 ;
V_6 -> V_232 = V_157 -> V_231 ;
F_87 ( & V_6 -> V_181 , 0 , V_224 , V_234 , V_157 ) ;
return 0 ;
}
static int F_101 ( struct V_135 * V_135 , void * V_136 ,
struct V_213 * V_214 )
{
struct V_114 * V_115 = V_135 -> V_235 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( 0 != V_214 -> V_158 )
return - V_129 ;
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
strcpy ( V_214 -> V_161 , L_35 ) ;
V_214 -> type = V_236 ;
V_214 -> V_218 = V_237 | V_220 ;
V_214 -> V_222 = V_223 ;
V_214 -> V_226 = V_228 ;
F_87 ( & V_6 -> V_181 , 0 , V_224 , V_225 , V_214 ) ;
return 0 ;
}
static int F_102 ( struct V_135 * V_135 , void * V_136 ,
const struct V_213 * V_214 )
{
struct V_114 * V_115 = V_135 -> V_235 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( 0 != V_214 -> V_158 )
return - V_129 ;
F_87 ( & V_6 -> V_181 , 0 , V_224 , V_229 , V_214 ) ;
return 0 ;
}
static int F_103 ( struct V_135 * V_135 )
{
struct V_139 * V_140 = F_62 ( V_135 ) ;
struct V_5 * V_6 = F_104 ( V_135 ) ;
struct V_114 * V_115 ;
enum V_177 type = V_178 ;
int V_27 ;
int V_38 = 0 ;
F_4 ( V_6 , V_238 , L_36 ,
F_105 ( V_140 ) ) ;
switch ( V_140 -> V_148 ) {
case V_149 :
type = V_178 ;
break;
case V_239 :
type = V_240 ;
break;
case V_241 :
V_38 = 1 ;
break;
}
V_6 -> V_242 ++ ;
F_4 ( V_6 , V_238 , L_37 ,
F_105 ( V_140 ) , V_243 [ type ] ,
V_6 -> V_242 ) ;
V_115 = F_106 ( sizeof( * V_115 ) , V_80 ) ;
if ( NULL == V_115 ) {
V_6 -> V_242 -- ;
return - V_81 ;
}
F_107 ( & V_115 -> V_115 , V_140 ) ;
V_135 -> V_235 = V_115 ;
V_115 -> V_6 = V_6 ;
V_115 -> V_38 = V_38 ;
V_6 -> V_38 = V_38 ;
V_115 -> type = type ;
V_6 -> V_71 = V_159 [ 0 ] . V_71 ;
V_115 -> V_117 = F_68 ( V_6 -> V_71 ) ;
F_70 ( V_6 ) ;
V_115 -> V_45 = V_6 -> V_45 ;
V_115 -> V_119 = V_6 -> V_119 ;
F_4 ( V_6 , V_238 , L_38
L_39 ,
( unsigned long ) V_115 , ( unsigned long ) V_6 ,
( unsigned long ) & V_6 -> V_7 ) ;
F_4 ( V_6 , V_238 , L_40
L_41 , F_3 ( & V_6 -> V_7 . V_244 ) ) ;
F_4 ( V_6 , V_238 , L_40
L_42 , F_3 ( & V_6 -> V_7 . V_8 ) ) ;
V_27 = F_86 ( V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
V_6 -> V_245 = V_246 ;
if ( ! V_115 -> V_38 ) {
F_108 ( & V_115 -> V_165 , & V_247 ,
NULL , & V_6 -> V_75 ,
V_115 -> type ,
V_171 ,
sizeof( struct V_3 ) , V_115 , & V_6 -> V_248 ) ;
} else {
F_4 ( V_6 , V_238 , L_43 ) ;
F_109 ( V_6 ) ;
F_87 ( & V_6 -> V_181 , 0 , V_224 , V_249 ) ;
F_33 ( V_6 ) ;
F_42 ( V_6 ) ;
}
F_110 ( & V_115 -> V_115 ) ;
return 0 ;
}
static int F_111 ( struct V_135 * V_135 )
{
struct V_139 * V_140 = F_62 ( V_135 ) ;
int V_250 ;
F_112 ( V_140 -> V_248 ) ;
V_250 = F_103 ( V_135 ) ;
F_113 ( V_140 -> V_248 ) ;
return V_250 ;
}
static T_4
F_114 ( struct V_135 * V_135 , char T_5 * V_20 , T_6 V_113 , T_7 * V_34 )
{
struct V_114 * V_115 = V_135 -> V_235 ;
struct V_5 * V_6 = V_115 -> V_6 ;
if ( V_115 -> type == V_178 ) {
int V_250 ;
if ( ! F_59 ( V_115 -> V_6 , V_115 , true ) )
return - V_179 ;
if ( F_115 ( & V_6 -> V_248 ) )
return - V_251 ;
V_250 = F_116 ( & V_115 -> V_165 , V_20 , V_113 , V_34 , 0 ,
V_135 -> V_175 & V_176 ) ;
F_113 ( & V_6 -> V_248 ) ;
return V_250 ;
}
return 0 ;
}
static unsigned int
F_117 ( struct V_135 * V_135 , struct V_252 * V_253 )
{
unsigned long V_254 = F_118 ( V_253 ) ;
struct V_114 * V_115 = V_135 -> V_235 ;
struct V_3 * V_4 ;
int V_250 = 0 ;
if ( F_119 ( & V_115 -> V_115 ) )
V_250 = V_255 ;
else if ( V_254 & V_255 )
F_120 ( V_135 , & V_115 -> V_115 . V_253 , V_253 ) ;
if ( V_178 != V_115 -> type )
return V_250 | V_256 ;
if ( ! ! F_58 ( V_115 -> V_6 , V_115 ) )
return V_250 | V_256 ;
if ( ! F_57 ( V_115 -> V_6 , V_115 ) ) {
if ( F_3 ( & V_115 -> V_165 . V_257 ) )
return V_250 | V_256 ;
V_4 = F_5 ( V_115 -> V_165 . V_257 . V_10 , struct V_3 , V_11 . V_257 ) ;
F_120 ( V_135 , & V_4 -> V_11 . V_19 , V_253 ) ;
if ( V_4 -> V_11 . V_15 == V_16 ||
V_4 -> V_11 . V_15 == V_258 )
return V_250 | V_259 | V_260 ;
} else if ( V_254 & ( V_259 | V_260 ) ) {
return V_250 | F_121 ( V_135 , & V_115 -> V_165 , V_253 ) ;
}
return V_250 ;
}
static unsigned int F_122 ( struct V_135 * V_135 , struct V_252 * V_253 )
{
struct V_114 * V_115 = V_135 -> V_235 ;
struct V_5 * V_6 = V_115 -> V_6 ;
unsigned int V_250 ;
F_112 ( & V_6 -> V_248 ) ;
V_250 = F_117 ( V_135 , V_253 ) ;
F_113 ( & V_6 -> V_248 ) ;
return V_250 ;
}
static int F_123 ( struct V_135 * V_135 )
{
struct V_114 * V_115 = V_135 -> V_235 ;
struct V_5 * V_6 = V_115 -> V_6 ;
struct V_139 * V_140 = F_62 ( V_135 ) ;
F_4 ( V_6 , V_238 , L_44 ,
F_105 ( V_140 ) , V_6 -> V_242 ) ;
F_112 ( & V_6 -> V_248 ) ;
V_6 -> V_242 -- ;
F_60 ( V_6 , V_115 ) ;
if ( ! V_6 -> V_242 ) {
F_29 ( V_6 ) ;
F_34 ( V_6 ) ;
F_124 ( V_6 -> V_84 ) ;
if ( V_6 -> V_261 . V_25 )
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
F_113 ( & V_6 -> V_248 ) ;
return 0 ;
}
static int F_128 ( struct V_135 * V_135 , struct V_262 * V_263 )
{
struct V_114 * V_115 = V_135 -> V_235 ;
struct V_5 * V_6 = V_115 -> V_6 ;
int V_250 ;
if ( F_115 ( & V_6 -> V_248 ) )
return - V_251 ;
V_250 = F_129 ( & V_115 -> V_165 , V_263 ) ;
F_113 ( & V_6 -> V_248 ) ;
return V_250 ;
}
static struct V_139 * F_130 ( struct V_5 * V_6 ,
const struct V_139
* V_264 , const char * V_265 )
{
struct V_139 * V_266 ;
V_266 = F_131 () ;
if ( NULL == V_266 )
return NULL ;
* V_266 = * V_264 ;
V_266 -> V_181 = & V_6 -> V_181 ;
V_266 -> V_267 = V_268 ;
V_266 -> V_248 = & V_6 -> V_248 ;
snprintf ( V_266 -> V_161 , sizeof( V_266 -> V_161 ) , L_45 , V_6 -> V_161 , V_265 ) ;
F_132 ( V_266 , V_6 ) ;
return V_266 ;
}
int F_133 ( struct V_5 * V_6 )
{
int V_172 = 0 ;
F_134 ( & V_6 -> V_197 , 6 ) ;
F_134 ( & V_6 -> V_208 , 2 ) ;
F_135 ( & V_6 -> V_208 , & V_269 ,
V_209 , 0 , 1 , 1 , 0 ) ;
F_135 ( & V_6 -> V_208 , & V_269 ,
V_211 , - 15 , 15 , 1 , 0 ) ;
F_135 ( & V_6 -> V_197 , & V_270 ,
V_202 , 0 , 255 , 1 , 54 ) ;
F_135 ( & V_6 -> V_197 , & V_270 ,
V_200 , 0 , 255 , 1 , 119 ) ;
F_135 ( & V_6 -> V_197 , & V_270 ,
V_204 , 0 , 255 , 1 , 112 ) ;
F_135 ( & V_6 -> V_197 , & V_270 ,
V_206 , - 128 , 127 , 1 , 0 ) ;
F_136 ( & V_6 -> V_197 ,
& V_6 -> V_208 , NULL ) ;
if ( V_6 -> V_208 . error )
V_172 = V_6 -> V_208 . error ;
if ( ! V_172 && V_6 -> V_197 . error )
V_172 = V_6 -> V_197 . error ;
if ( V_172 )
goto V_271;
V_6 -> V_266 = F_130 ( V_6 , & V_272 , L_46 ) ;
if ( ! V_6 -> V_266 ) {
F_137 ( V_273 L_47 ,
V_6 -> V_161 ) ;
V_172 = - V_81 ;
goto V_271;
}
V_6 -> V_266 -> V_197 = & V_6 -> V_197 ;
F_138 ( & V_6 -> V_7 . V_8 ) ;
F_138 ( & V_6 -> V_7 . V_244 ) ;
V_172 = F_139 ( V_6 -> V_266 , V_149 , V_274 ) ;
if ( V_172 < 0 ) {
F_137 ( V_273 L_47 ,
V_6 -> V_161 ) ;
V_268 ( V_6 -> V_266 ) ;
V_6 -> V_266 = NULL ;
goto V_271;
}
F_137 ( V_273 L_48 ,
V_6 -> V_161 , F_105 ( V_6 -> V_266 ) ) ;
if ( V_6 -> V_275 . V_276 ) {
V_6 -> V_277 = F_130 ( V_6 , & V_278 ,
L_49 ) ;
if ( ! V_6 -> V_277 ) {
F_137 ( V_273 L_50 ,
V_6 -> V_161 ) ;
V_172 = - V_279 ;
goto V_280;
}
V_6 -> V_277 -> V_197 = & V_6 -> V_208 ;
V_172 = F_139 ( V_6 -> V_277 , V_241 ,
V_281 ) ;
if ( V_172 < 0 ) {
F_137 ( V_273 L_50 ,
V_6 -> V_161 ) ;
V_268 ( V_6 -> V_277 ) ;
goto V_280;
}
F_137 ( V_273 L_48 ,
V_6 -> V_161 , F_105 ( V_6 -> V_277 ) ) ;
}
F_137 ( V_273 L_51 , V_172 ) ;
return V_172 ;
V_280:
F_140 ( V_6 -> V_266 ) ;
V_271:
F_141 ( & V_6 -> V_197 ) ;
F_141 ( & V_6 -> V_208 ) ;
return V_172 ;
}
int F_142 ( struct V_5 * V_6 )
{
F_140 ( V_6 -> V_266 ) ;
F_26 ( V_6 ) ;
if ( V_6 -> V_277 ) {
if ( F_143 ( V_6 -> V_277 ) )
F_140 ( V_6 -> V_277 ) ;
else
V_268 ( V_6 -> V_277 ) ;
V_6 -> V_277 = NULL ;
}
return 0 ;
}
int F_144 ( void )
{
return 0 ;
}
