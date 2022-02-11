static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
unsigned long * V_4 = F_2 ( V_3 -> V_5 ) ;
return (struct V_1 * ) * V_4 ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
unsigned long * V_4 = F_2 ( V_7 ) ;
return (struct V_1 * ) * V_4 ;
}
static int F_4 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_12 [ 2 ] != V_13 )
return 0 ;
switch ( V_10 -> V_11 -> V_12 [ 12 ] ) {
case V_14 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_1
L_2 , V_8 -> V_18 ) ;
break;
case V_19 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_3
L_4 , V_8 -> V_18 ) ;
break;
case V_20 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_5
L_6 , V_8 -> V_18 ) ;
break;
case V_21 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_7
L_8 , V_8 -> V_18 ) ;
break;
case V_22 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_9
L_10 , V_8 -> V_18 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_11
L_12 , V_8 -> V_18 ) ;
break;
}
return 1 ;
}
static int F_6 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_23 != V_24 ||
( V_10 -> V_11 -> V_25 != V_26 &&
V_10 -> V_11 -> V_25 != V_27 ) )
return 0 ;
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_13 ) ;
return 1 ;
}
static T_1 F_7 ( struct V_28 * V_16 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_1 * V_8 ;
struct V_6 * V_33 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_33 ) ;
F_9 ( V_8 -> V_34 ) ;
return V_32 ;
}
static T_1 F_10 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_33 = F_8 ( V_16 ) ;
unsigned char * V_35 ;
V_8 = F_3 ( V_33 ) ;
if ( ! V_8 -> V_36 )
return 0 ;
V_35 = & V_8 -> V_36 [ 32 ] ;
return snprintf ( V_31 , 20 , L_14 ,
V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] , V_35 [ 3 ] ) ;
}
static T_1 F_11 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_6 * V_33 = F_8 ( V_16 ) ;
struct V_1 * V_8 = F_3 ( V_33 ) ;
return snprintf ( V_31 , 20 , L_15 , V_8 -> V_37 ) ;
}
static T_1 F_12 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_33 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_33 ) ;
return snprintf ( V_31 , 20 , L_16 ,
V_8 -> V_38 & V_39 ?
L_17 : L_18 ) ;
}
static int F_13 ( T_3 V_40 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_14 ( V_42 ) ; V_41 ++ )
if ( V_42 [ V_41 ] == V_40 )
return 0 ;
return 1 ;
}
static int F_15 ( T_3 V_40 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_14 ( V_43 ) ; V_41 ++ )
if ( V_43 [ V_41 ] == V_40 )
return 0 ;
return 1 ;
}
static int F_16 ( T_3 V_40 )
{
return F_13 ( V_40 ) ||
F_15 ( V_40 ) ;
}
static T_1 F_17 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_33 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_33 ) ;
return snprintf ( V_31 , 20 , L_15 , F_16 ( V_8 -> V_40 ) ) ;
}
static inline int F_18 ( unsigned char V_44 [] )
{
return ( V_44 [ 3 ] & 0xC0 ) == 0x40 ;
}
static T_1 F_19 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
T_1 V_45 = 0 ;
unsigned char V_46 ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_47 * V_48 ;
unsigned long V_49 ;
V_3 = F_20 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_48 = V_3 -> V_51 ;
if ( ! V_48 ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
return - V_52 ;
}
if ( ! F_18 ( V_48 -> V_44 ) ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
V_45 = snprintf ( V_31 , V_53 , L_19 ) ;
return V_45 ;
}
V_46 = V_48 -> V_54 ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
if ( V_46 > V_55 )
V_46 = V_55 ;
V_45 = snprintf ( V_31 , V_53 , L_20 , V_56 [ V_46 ] ) ;
return V_45 ;
}
static T_1 F_23 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_47 * V_48 ;
unsigned long V_49 ;
unsigned char V_57 [ 8 ] ;
V_3 = F_20 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_48 = V_3 -> V_51 ;
if ( ! V_48 ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
return - V_52 ;
}
memcpy ( V_57 , V_48 -> V_44 , sizeof( V_57 ) ) ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
return snprintf ( V_31 , 20 , L_21 ,
V_57 [ 0 ] , V_57 [ 1 ] , V_57 [ 2 ] , V_57 [ 3 ] ,
V_57 [ 4 ] , V_57 [ 5 ] , V_57 [ 6 ] , V_57 [ 7 ] ) ;
}
static T_1 F_24 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_47 * V_48 ;
unsigned long V_49 ;
unsigned char V_58 [ 16 ] ;
V_3 = F_20 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_48 = V_3 -> V_51 ;
if ( ! V_48 ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
return - V_52 ;
}
memcpy ( V_58 , V_48 -> V_59 , sizeof( V_58 ) ) ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
return snprintf ( V_31 , 16 * 2 + 2 ,
L_22
L_23 ,
V_58 [ 0 ] , V_58 [ 1 ] , V_58 [ 2 ] , V_58 [ 3 ] ,
V_58 [ 4 ] , V_58 [ 5 ] , V_58 [ 6 ] , V_58 [ 7 ] ,
V_58 [ 8 ] , V_58 [ 9 ] , V_58 [ 10 ] , V_58 [ 11 ] ,
V_58 [ 12 ] , V_58 [ 13 ] , V_58 [ 14 ] , V_58 [ 15 ] ) ;
}
static inline void F_25 ( struct V_60 * V_61 , struct V_9 * V_10 )
{
F_26 ( & V_10 -> V_61 , V_61 ) ;
}
static inline T_3 F_27 ( struct V_1 * V_8 , T_4 V_62 )
{
T_3 V_63 ;
struct V_64 * V_65 = & V_8 -> V_66 [ V_62 ] ;
unsigned long V_49 ;
if ( F_28 ( ! ( V_8 -> V_38 & V_39 ) ) )
return V_8 -> V_67 . V_68 ( V_8 , V_62 ) ;
if ( ( V_65 -> V_69 [ V_65 -> V_70 ] & 1 ) == V_65 -> V_71 ) {
V_63 = V_65 -> V_69 [ V_65 -> V_70 ] ;
V_65 -> V_70 ++ ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_8 -> V_37 -- ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
} else {
V_63 = V_72 ;
}
if ( V_65 -> V_70 == V_8 -> V_73 ) {
V_65 -> V_70 = 0 ;
V_65 -> V_71 ^= 1 ;
}
return V_63 ;
}
static void F_29 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( F_30 ( V_8 -> V_38 & V_39 ) ) {
V_10 -> V_74 |= 1 | ( V_8 -> V_75 [ V_10 -> V_76 . V_77 ] << 1 ) ;
if ( F_30 ( V_8 -> V_78 ) )
V_10 -> V_76 . V_79 =
F_31 () % V_8 -> V_80 ;
}
}
static int F_32 ( T_4 * V_81 )
{
return V_81 [ 0 ] == V_82 && V_81 [ 6 ] == V_83 ;
}
static void F_33 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( ! F_32 ( V_10 -> V_84 . V_85 ) )
return;
F_34 ( & V_8 -> V_86 ) ;
V_8 -> V_87 = V_88 ;
}
static void F_35 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( F_32 ( V_10 -> V_84 . V_85 ) &&
F_36 ( & V_8 -> V_86 ) )
V_8 -> V_87 = V_89 ;
}
static void F_37 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_49 ;
F_29 ( V_8 , V_10 ) ;
F_33 ( V_8 , V_10 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
F_25 ( & V_8 -> V_90 , V_10 ) ;
V_8 -> V_91 ++ ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
F_38 ( V_8 ) ;
}
static inline void F_39 ( struct V_9 * V_10 )
{
if ( F_40 ( F_41 ( & V_10 -> V_61 ) ) )
return;
F_42 ( & V_10 -> V_61 ) ;
}
static inline int F_43 ( unsigned char V_44 [] )
{
return memcmp ( V_44 , V_92 , 8 ) == 0 ;
}
static inline int F_44 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_36 )
return 0 ;
if ( ( V_8 -> V_36 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_8 ,
unsigned char V_44 [] , int V_93 , int * V_94 , int * V_95 )
{
int V_41 , V_96 = 0 ;
F_46 ( V_97 , V_98 ) ;
F_47 ( V_97 , V_98 ) ;
for ( V_41 = 0 ; V_41 < V_8 -> V_99 ; V_41 ++ ) {
if ( V_8 -> V_16 [ V_41 ] -> V_93 == V_93 && V_8 -> V_16 [ V_41 ] -> V_94 != - 1 )
F_48 ( V_8 -> V_16 [ V_41 ] -> V_94 , V_97 ) ;
}
V_41 = F_49 ( V_97 , V_98 ) ;
if ( V_41 < V_98 ) {
* V_94 = V_41 ;
* V_95 = 0 ;
V_96 = 1 ;
}
return ! V_96 ;
}
static int F_50 ( struct V_1 * V_8 , int V_100 ,
struct V_47 * V_28 ,
struct V_47 * V_101 [] , int * V_102 )
{
int V_103 = V_8 -> V_99 ;
int V_41 ;
unsigned char V_104 [ 8 ] , V_105 [ 8 ] ;
struct V_47 * V_106 ;
if ( V_103 >= V_98 ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_24
L_25 ) ;
return - 1 ;
}
if ( V_28 -> V_95 != - 1 )
goto V_107;
if ( V_28 -> V_44 [ 4 ] == 0 ) {
if ( F_45 ( V_8 , V_28 -> V_44 ,
V_28 -> V_93 , & V_28 -> V_94 , & V_28 -> V_95 ) != 0 )
return - 1 ;
goto V_107;
}
memcpy ( V_104 , V_28 -> V_44 , 8 ) ;
V_104 [ 4 ] = 0 ;
for ( V_41 = 0 ; V_41 < V_103 ; V_41 ++ ) {
V_106 = V_8 -> V_16 [ V_41 ] ;
memcpy ( V_105 , V_106 -> V_44 , 8 ) ;
V_105 [ 4 ] = 0 ;
if ( memcmp ( V_104 , V_105 , 8 ) == 0 ) {
V_28 -> V_93 = V_106 -> V_93 ;
V_28 -> V_94 = V_106 -> V_94 ;
V_28 -> V_95 = V_28 -> V_44 [ 4 ] ;
break;
}
}
if ( V_28 -> V_95 == - 1 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_26
L_27
L_28 ) ;
return - 1 ;
}
V_107:
V_8 -> V_16 [ V_103 ] = V_28 ;
V_8 -> V_99 ++ ;
V_101 [ * V_102 ] = V_28 ;
( * V_102 ) ++ ;
F_52 ( & V_8 -> V_15 -> V_16 , L_29 ,
F_53 ( V_28 -> V_108 ) , V_100 ,
V_28 -> V_93 , V_28 -> V_94 , V_28 -> V_95 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_8 , int V_100 ,
int V_109 , struct V_47 * V_110 )
{
F_55 ( V_109 < 0 || V_109 >= V_98 ) ;
V_8 -> V_16 [ V_109 ] -> V_54 = V_110 -> V_54 ;
F_52 ( & V_8 -> V_15 -> V_16 , L_30 ,
F_53 ( V_110 -> V_108 ) , V_100 , V_110 -> V_93 ,
V_110 -> V_94 , V_110 -> V_95 ) ;
}
static void F_56 ( struct V_1 * V_8 , int V_100 ,
int V_109 , struct V_47 * V_110 ,
struct V_47 * V_101 [] , int * V_102 ,
struct V_47 * V_111 [] , int * V_112 )
{
F_55 ( V_109 < 0 || V_109 >= V_98 ) ;
V_111 [ * V_112 ] = V_8 -> V_16 [ V_109 ] ;
( * V_112 ) ++ ;
if ( V_110 -> V_94 == - 1 ) {
V_110 -> V_94 = V_8 -> V_16 [ V_109 ] -> V_94 ;
V_110 -> V_95 = V_8 -> V_16 [ V_109 ] -> V_95 ;
}
V_8 -> V_16 [ V_109 ] = V_110 ;
V_101 [ * V_102 ] = V_110 ;
( * V_102 ) ++ ;
F_52 ( & V_8 -> V_15 -> V_16 , L_31 ,
F_53 ( V_110 -> V_108 ) , V_100 , V_110 -> V_93 ,
V_110 -> V_94 , V_110 -> V_95 ) ;
}
static void F_57 ( struct V_1 * V_8 , int V_100 , int V_109 ,
struct V_47 * V_111 [] , int * V_112 )
{
int V_41 ;
struct V_47 * V_106 ;
F_55 ( V_109 < 0 || V_109 >= V_98 ) ;
V_106 = V_8 -> V_16 [ V_109 ] ;
V_111 [ * V_112 ] = V_8 -> V_16 [ V_109 ] ;
( * V_112 ) ++ ;
for ( V_41 = V_109 ; V_41 < V_8 -> V_99 - 1 ; V_41 ++ )
V_8 -> V_16 [ V_41 ] = V_8 -> V_16 [ V_41 + 1 ] ;
V_8 -> V_99 -- ;
F_52 ( & V_8 -> V_15 -> V_16 , L_32 ,
F_53 ( V_106 -> V_108 ) , V_100 , V_106 -> V_93 , V_106 -> V_94 ,
V_106 -> V_95 ) ;
}
static void F_58 ( struct V_1 * V_8 ,
struct V_47 * V_101 )
{
unsigned long V_49 ;
int V_41 , V_113 ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
for ( V_41 = 0 ; V_41 < V_8 -> V_99 ; V_41 ++ ) {
if ( V_8 -> V_16 [ V_41 ] == V_101 ) {
for ( V_113 = V_41 ; V_113 < V_8 -> V_99 - 1 ; V_113 ++ )
V_8 -> V_16 [ V_113 ] = V_8 -> V_16 [ V_113 + 1 ] ;
V_8 -> V_99 -- ;
break;
}
}
F_22 ( & V_8 -> V_50 , V_49 ) ;
F_59 ( V_101 ) ;
}
static inline int F_60 ( struct V_47 * V_114 ,
struct V_47 * V_115 )
{
if ( memcmp ( V_114 -> V_44 , V_115 -> V_44 ,
sizeof( V_114 -> V_44 ) ) != 0 )
return 0 ;
if ( memcmp ( V_114 -> V_59 , V_115 -> V_59 ,
sizeof( V_114 -> V_59 ) ) != 0 )
return 0 ;
if ( memcmp ( V_114 -> V_116 , V_115 -> V_116 , sizeof( V_114 -> V_116 ) ) != 0 )
return 0 ;
if ( memcmp ( V_114 -> V_117 , V_115 -> V_117 , sizeof( V_114 -> V_117 ) ) != 0 )
return 0 ;
if ( V_114 -> V_108 != V_115 -> V_108 )
return 0 ;
if ( V_114 -> V_93 != V_115 -> V_93 )
return 0 ;
return 1 ;
}
static inline int F_61 ( struct V_47 * V_114 ,
struct V_47 * V_115 )
{
if ( V_114 -> V_54 != V_115 -> V_54 )
return 1 ;
return 0 ;
}
static int F_62 ( struct V_47 * V_118 ,
struct V_47 * V_119 [] , int V_120 ,
int * V_121 )
{
int V_41 ;
#define F_63 0
#define F_64 1
#define F_65 2
#define F_66 3
for ( V_41 = 0 ; V_41 < V_120 ; V_41 ++ ) {
if ( V_119 [ V_41 ] == NULL )
continue;
if ( F_67 ( V_118 -> V_44 , V_119 [ V_41 ] -> V_44 ) ) {
* V_121 = V_41 ;
if ( F_60 ( V_118 , V_119 [ V_41 ] ) ) {
if ( F_61 ( V_118 , V_119 [ V_41 ] ) )
return F_66 ;
return F_65 ;
} else {
return F_64 ;
}
}
}
* V_121 = - 1 ;
return F_63 ;
}
static void F_68 ( struct V_1 * V_8 , int V_100 ,
struct V_47 * V_106 [] , int V_122 )
{
int V_41 , V_109 , V_123 , V_124 = 0 ;
struct V_47 * V_125 ;
unsigned long V_49 ;
struct V_47 * * V_101 , * * V_111 ;
int V_102 , V_112 ;
struct V_6 * V_7 = NULL ;
V_101 = F_69 ( sizeof( * V_101 ) * V_98 , V_126 ) ;
V_111 = F_69 ( sizeof( * V_111 ) * V_98 , V_126 ) ;
if ( ! V_101 || ! V_111 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_33
L_34 ) ;
goto V_127;
}
F_21 ( & V_8 -> V_128 , V_49 ) ;
V_41 = 0 ;
V_112 = 0 ;
V_102 = 0 ;
while ( V_41 < V_8 -> V_99 ) {
V_125 = V_8 -> V_16 [ V_41 ] ;
V_123 = F_62 ( V_125 , V_106 , V_122 , & V_109 ) ;
if ( V_123 == F_63 ) {
V_124 ++ ;
F_57 ( V_8 , V_100 , V_41 ,
V_111 , & V_112 ) ;
continue;
} else if ( V_123 == F_64 ) {
V_124 ++ ;
F_56 ( V_8 , V_100 , V_41 , V_106 [ V_109 ] ,
V_101 , & V_102 , V_111 , & V_112 ) ;
V_106 [ V_109 ] = NULL ;
} else if ( V_123 == F_66 ) {
F_54 ( V_8 , V_100 , V_41 , V_106 [ V_109 ] ) ;
}
V_41 ++ ;
}
for ( V_41 = 0 ; V_41 < V_122 ; V_41 ++ ) {
if ( ! V_106 [ V_41 ] )
continue;
V_123 = F_62 ( V_106 [ V_41 ] , V_8 -> V_16 ,
V_8 -> V_99 , & V_109 ) ;
if ( V_123 == F_63 ) {
V_124 ++ ;
if ( F_50 ( V_8 , V_100 , V_106 [ V_41 ] ,
V_101 , & V_102 ) != 0 )
break;
V_106 [ V_41 ] = NULL ;
} else if ( V_123 == F_64 ) {
V_124 ++ ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_35 ) ;
}
}
F_22 ( & V_8 -> V_128 , V_49 ) ;
if ( V_100 == - 1 || ! V_124 )
goto V_127;
V_7 = V_8 -> V_34 ;
for ( V_41 = 0 ; V_41 < V_112 ; V_41 ++ ) {
struct V_2 * V_3 =
F_70 ( V_7 , V_111 [ V_41 ] -> V_93 ,
V_111 [ V_41 ] -> V_94 , V_111 [ V_41 ] -> V_95 ) ;
if ( V_3 != NULL ) {
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_36
L_37 , V_100 , V_111 [ V_41 ] -> V_93 ,
V_111 [ V_41 ] -> V_94 , V_111 [ V_41 ] -> V_95 ) ;
}
F_59 ( V_111 [ V_41 ] ) ;
V_111 [ V_41 ] = NULL ;
}
for ( V_41 = 0 ; V_41 < V_102 ; V_41 ++ ) {
if ( F_73 ( V_7 , V_101 [ V_41 ] -> V_93 ,
V_101 [ V_41 ] -> V_94 , V_101 [ V_41 ] -> V_95 ) == 0 )
continue;
F_5 ( & V_8 -> V_15 -> V_16 , L_38
L_39 , V_100 , V_101 [ V_41 ] -> V_93 ,
V_101 [ V_41 ] -> V_94 , V_101 [ V_41 ] -> V_95 ) ;
F_58 ( V_8 , V_101 [ V_41 ] ) ;
}
V_127:
F_59 ( V_101 ) ;
F_59 ( V_111 ) ;
}
static struct V_47 * F_74 ( struct V_1 * V_8 ,
int V_93 , int V_94 , int V_95 )
{
int V_41 ;
struct V_47 * V_106 ;
for ( V_41 = 0 ; V_41 < V_8 -> V_99 ; V_41 ++ ) {
V_106 = V_8 -> V_16 [ V_41 ] ;
if ( V_106 -> V_93 == V_93 && V_106 -> V_94 == V_94 && V_106 -> V_95 == V_95 )
return V_106 ;
}
return NULL ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_47 * V_106 ;
unsigned long V_49 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 ) ;
F_21 ( & V_8 -> V_128 , V_49 ) ;
V_106 = F_74 ( V_8 , F_76 ( V_3 ) ,
F_77 ( V_3 ) , V_3 -> V_95 ) ;
if ( V_106 != NULL )
V_3 -> V_51 = V_106 ;
F_22 ( & V_8 -> V_128 , V_49 ) ;
return 0 ;
}
static void F_78 ( struct V_2 * V_3 )
{
}
static void F_79 ( struct V_1 * V_8 )
{
int V_41 ;
if ( ! V_8 -> V_129 )
return;
for ( V_41 = 0 ; V_41 < V_8 -> V_130 ; V_41 ++ ) {
F_59 ( V_8 -> V_129 [ V_41 ] ) ;
V_8 -> V_129 [ V_41 ] = NULL ;
}
F_59 ( V_8 -> V_129 ) ;
V_8 -> V_129 = NULL ;
}
static int F_80 ( struct V_1 * V_8 )
{
int V_41 ;
if ( V_8 -> V_131 <= 0 )
return 0 ;
V_8 -> V_129 = F_69 ( sizeof( * V_8 -> V_129 ) * V_8 -> V_130 ,
V_126 ) ;
if ( ! V_8 -> V_129 )
return - V_132 ;
for ( V_41 = 0 ; V_41 < V_8 -> V_130 ; V_41 ++ ) {
V_8 -> V_129 [ V_41 ] = F_81 ( sizeof( * V_8 -> V_129 [ V_41 ] ) *
V_8 -> V_131 , V_126 ) ;
if ( ! V_8 -> V_129 [ V_41 ] )
goto V_133;
}
return 0 ;
V_133:
F_79 ( V_8 ) ;
return - V_132 ;
}
static void F_82 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_134 * V_135 , * V_136 ;
T_5 V_137 ;
V_135 = & V_10 -> V_138 [ V_8 -> V_139 - 1 ] ;
V_136 = V_8 -> V_129 [ V_10 -> V_140 ] ;
V_135 -> V_141 = V_142 ;
V_135 -> V_143 = sizeof( * V_135 ) *
( V_10 -> V_76 . V_144 - V_8 -> V_139 ) ;
V_137 = F_83 ( V_8 -> V_15 , V_136 , V_135 -> V_143 ,
V_145 ) ;
V_135 -> V_146 . V_147 = ( T_3 ) ( V_137 & 0x0FFFFFFFFULL ) ;
V_135 -> V_146 . V_148 = ( T_3 ) ( ( V_137 >> 32 ) & 0x0FFFFFFFFULL ) ;
}
static void F_84 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_134 * V_135 ;
union V_149 V_137 ;
if ( V_10 -> V_76 . V_144 <= V_8 -> V_139 )
return;
V_135 = & V_10 -> V_138 [ V_8 -> V_139 - 1 ] ;
V_137 . V_150 . V_147 = V_135 -> V_146 . V_147 ;
V_137 . V_150 . V_148 = V_135 -> V_146 . V_148 ;
F_85 ( V_8 -> V_15 , V_137 . V_151 , V_135 -> V_143 , V_145 ) ;
}
static void F_86 ( struct V_9 * V_152 )
{
struct V_153 * V_154 ;
struct V_1 * V_8 ;
struct V_155 * V_156 ;
unsigned char V_157 ;
unsigned char V_158 ;
unsigned char V_159 ;
unsigned long V_160 ;
V_156 = V_152 -> V_11 ;
V_154 = (struct V_153 * ) V_152 -> V_161 ;
V_8 = V_152 -> V_8 ;
F_87 ( V_154 ) ;
if ( V_152 -> V_76 . V_144 > V_8 -> V_139 )
F_84 ( V_8 , V_152 ) ;
V_154 -> V_162 = ( V_163 << 16 ) ;
V_154 -> V_162 |= ( V_164 << 8 ) ;
V_154 -> V_162 |= V_156 -> V_25 ;
if ( V_165 < sizeof( V_156 -> V_12 ) )
V_160 = V_165 ;
else
V_160 = sizeof( V_156 -> V_12 ) ;
if ( V_156 -> V_166 < V_160 )
V_160 = V_156 -> V_166 ;
memcpy ( V_154 -> V_167 , V_156 -> V_12 , V_160 ) ;
F_88 ( V_154 , V_156 -> V_168 ) ;
if ( V_156 -> V_23 == 0 ) {
V_154 -> V_169 ( V_154 ) ;
F_89 ( V_8 , V_152 ) ;
return;
}
switch ( V_156 -> V_23 ) {
case V_24 :
if ( V_156 -> V_25 ) {
V_157 = 0xf & V_156 -> V_12 [ 2 ] ;
V_158 = V_156 -> V_12 [ 12 ] ;
V_159 = V_156 -> V_12 [ 13 ] ;
}
if ( V_156 -> V_25 == V_170 ) {
if ( F_4 ( V_8 , V_152 ) ) {
V_154 -> V_162 = V_171 << 16 ;
break;
}
if ( V_157 == V_172 ) {
if ( V_152 -> V_84 . V_85 [ 0 ] == V_173 )
break;
if ( ( V_158 == 0x25 ) && ( V_159 == 0x0 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_40
L_41 , V_152 ) ;
break;
}
}
if ( V_157 == V_174 ) {
if ( ( V_158 == 0x04 ) && ( V_159 == 0x03 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_40
L_42
L_43
L_44 , V_152 ) ;
break;
}
}
if ( V_157 == V_175 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_40
L_45
L_46 ,
V_152 , V_158 , V_159 ) ;
V_154 -> V_162 = V_171 << 16 ;
break;
}
F_90 ( & V_8 -> V_15 -> V_16 , L_47
L_48
L_49
L_50
L_51
L_52
L_53 ,
V_152 , V_157 , V_158 , V_159 ,
V_154 -> V_162 ,
V_154 -> V_176 [ 0 ] , V_154 -> V_176 [ 1 ] ,
V_154 -> V_176 [ 2 ] , V_154 -> V_176 [ 3 ] ,
V_154 -> V_176 [ 4 ] , V_154 -> V_176 [ 5 ] ,
V_154 -> V_176 [ 6 ] , V_154 -> V_176 [ 7 ] ,
V_154 -> V_176 [ 8 ] , V_154 -> V_176 [ 9 ] ,
V_154 -> V_176 [ 10 ] , V_154 -> V_176 [ 11 ] ,
V_154 -> V_176 [ 12 ] , V_154 -> V_176 [ 13 ] ,
V_154 -> V_176 [ 14 ] , V_154 -> V_176 [ 15 ] ) ;
break;
}
if ( V_156 -> V_25 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_54
L_49
L_55 ,
V_152 , V_156 -> V_25 ,
V_157 , V_158 , V_159 ,
V_154 -> V_162 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_56
L_57 , V_152 ) ,
V_154 -> V_162 = V_177 << 16 ;
}
break;
case V_178 :
break;
case V_179 :
F_5 ( & V_8 -> V_15 -> V_16 , L_58
L_59
L_60 , V_152 ) ;
break;
case V_180 : {
V_154 -> V_162 = V_177 << 16 ;
}
break;
case V_181 :
V_154 -> V_162 = V_182 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_61
L_62 , V_152 ) ;
break;
case V_183 :
V_154 -> V_162 = V_182 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_63 , V_152 ) ;
break;
case V_184 :
V_154 -> V_162 = V_182 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_64 , V_152 ) ;
break;
case V_185 :
V_154 -> V_162 = V_186 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_65 ,
V_152 , V_156 -> V_25 ) ;
break;
case V_187 :
V_154 -> V_162 = V_182 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_66 , V_152 ) ;
break;
case V_188 :
V_154 -> V_162 = V_171 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_67
L_68 , V_152 ) ;
break;
case V_189 :
V_154 -> V_162 = V_190 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_69 , V_152 ) ;
break;
case V_191 :
V_154 -> V_162 = V_182 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_70 ) ;
break;
default:
V_154 -> V_162 = V_182 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_71 ,
V_152 , V_156 -> V_23 ) ;
}
V_154 -> V_169 ( V_154 ) ;
F_89 ( V_8 , V_152 ) ;
}
static void F_91 ( struct V_192 * V_15 ,
struct V_9 * V_10 , int V_193 , int V_194 )
{
int V_41 ;
union V_149 V_195 ;
for ( V_41 = 0 ; V_41 < V_193 ; V_41 ++ ) {
V_195 . V_150 . V_147 = V_10 -> V_138 [ V_41 ] . V_146 . V_147 ;
V_195 . V_150 . V_148 = V_10 -> V_138 [ V_41 ] . V_146 . V_148 ;
F_85 ( V_15 , ( V_196 ) V_195 . V_151 , V_10 -> V_138 [ V_41 ] . V_143 ,
V_194 ) ;
}
}
static void F_92 ( struct V_192 * V_15 ,
struct V_9 * V_152 ,
unsigned char * V_31 ,
T_2 V_197 ,
int V_194 )
{
T_5 V_195 ;
if ( V_197 == 0 || V_194 == V_198 ) {
V_152 -> V_76 . V_77 = 0 ;
V_152 -> V_76 . V_144 = 0 ;
return;
}
V_195 = ( T_5 ) F_83 ( V_15 , V_31 , V_197 , V_194 ) ;
V_152 -> V_138 [ 0 ] . V_146 . V_147 =
( T_3 ) ( V_195 & ( T_5 ) 0x00000000FFFFFFFF ) ;
V_152 -> V_138 [ 0 ] . V_146 . V_148 =
( T_3 ) ( ( V_195 >> 32 ) & ( T_5 ) 0x00000000FFFFFFFF ) ;
V_152 -> V_138 [ 0 ] . V_143 = V_197 ;
V_152 -> V_76 . V_77 = ( T_4 ) 1 ;
V_152 -> V_76 . V_144 = ( V_199 ) 1 ;
}
static inline void F_93 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_94 ( V_200 ) ;
V_10 -> V_201 = & V_200 ;
F_37 ( V_8 , V_10 ) ;
F_95 ( & V_200 ) ;
}
static void F_96 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_49 ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
if ( F_28 ( V_8 -> V_202 ) ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
V_10 -> V_11 -> V_23 = V_183 ;
} else {
F_22 ( & V_8 -> V_50 , V_49 ) ;
F_93 ( V_8 , V_10 ) ;
}
}
static void F_97 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_194 )
{
int V_203 = 10 , V_204 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_93 ( V_8 , V_10 ) ;
V_204 ++ ;
if ( V_204 > 3 ) {
F_98 ( V_203 ) ;
if ( V_203 < 1000 )
V_203 *= 2 ;
}
} while ( ( F_4 ( V_8 , V_10 ) ||
F_6 ( V_8 , V_10 ) ) &&
V_204 <= V_205 );
F_91 ( V_8 -> V_15 , V_10 , 1 , V_194 ) ;
}
static void F_99 ( struct V_9 * V_152 )
{
struct V_155 * V_156 ;
struct V_28 * V_206 = & V_152 -> V_8 -> V_15 -> V_16 ;
V_156 = V_152 -> V_11 ;
switch ( V_156 -> V_23 ) {
case V_24 :
F_5 ( V_206 , L_72 , V_152 ) ;
F_5 ( V_206 , L_73 , V_152 ,
V_156 -> V_25 ) ;
if ( V_156 -> V_25 == 0 )
F_5 ( V_206 , L_74
L_75
L_76
L_77 ) ;
break;
case V_178 :
F_52 ( V_206 , L_78 ) ;
break;
case V_179 :
F_5 ( V_206 , L_79 , V_152 ) ;
break;
case V_180 : {
F_5 ( V_206 , L_80
L_81 , V_152 ) ;
}
break;
case V_181 :
F_5 ( V_206 , L_82 , V_152 ) ;
break;
case V_183 :
F_5 ( V_206 , L_83 , V_152 ) ;
break;
case V_184 :
F_5 ( V_206 , L_64 , V_152 ) ;
break;
case V_185 :
F_5 ( V_206 , L_84 , V_152 ) ;
break;
case V_187 :
F_5 ( V_206 , L_66 , V_152 ) ;
break;
case V_188 :
F_5 ( V_206 , L_85 , V_152 ) ;
break;
case V_189 :
F_5 ( V_206 , L_86 , V_152 ) ;
break;
case V_191 :
F_5 ( V_206 , L_70 ) ;
break;
default:
F_5 ( V_206 , L_71 , V_152 ,
V_156 -> V_23 ) ;
}
}
static int F_100 ( struct V_1 * V_8 , unsigned char * V_44 ,
unsigned char V_207 , unsigned char * V_31 ,
unsigned char V_208 )
{
int V_209 = V_210 ;
struct V_9 * V_10 ;
struct V_155 * V_156 ;
V_10 = F_101 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_87 ) ;
return - V_132 ;
}
F_102 ( V_10 , V_211 , V_8 , V_31 , V_208 , V_207 , V_44 , V_212 ) ;
F_97 ( V_8 , V_10 , V_213 ) ;
V_156 = V_10 -> V_11 ;
if ( V_156 -> V_23 != 0 && V_156 -> V_23 != V_178 ) {
F_99 ( V_10 ) ;
V_209 = - 1 ;
}
F_103 ( V_8 , V_10 ) ;
return V_209 ;
}
static int F_104 ( struct V_1 * V_8 , unsigned char * V_44 )
{
int V_209 = V_210 ;
struct V_9 * V_10 ;
struct V_155 * V_156 ;
V_10 = F_101 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_87 ) ;
return - V_132 ;
}
F_102 ( V_10 , V_214 , V_8 , NULL , 0 , 0 , V_44 , V_215 ) ;
F_93 ( V_8 , V_10 ) ;
V_156 = V_10 -> V_11 ;
if ( V_156 -> V_23 != 0 ) {
F_99 ( V_10 ) ;
V_209 = - 1 ;
}
F_103 ( V_8 , V_10 ) ;
return V_209 ;
}
static void F_105 ( struct V_1 * V_8 ,
unsigned char * V_44 , unsigned char * V_54 )
{
int V_209 ;
unsigned char * V_31 ;
* V_54 = V_55 ;
V_31 = F_69 ( 64 , V_126 ) ;
if ( ! V_31 )
return;
V_209 = F_100 ( V_8 , V_44 , 0xC1 , V_31 , 64 ) ;
if ( V_209 == 0 )
* V_54 = V_31 [ 8 ] ;
if ( * V_54 > V_55 )
* V_54 = V_55 ;
F_59 ( V_31 ) ;
return;
}
static int F_106 ( struct V_1 * V_8 , unsigned char * V_44 ,
unsigned char * V_59 , int V_197 )
{
int V_209 ;
unsigned char * V_31 ;
if ( V_197 > 16 )
V_197 = 16 ;
V_31 = F_69 ( 64 , V_126 ) ;
if ( ! V_31 )
return - 1 ;
V_209 = F_100 ( V_8 , V_44 , 0x83 , V_31 , 64 ) ;
if ( V_209 == 0 )
memcpy ( V_59 , & V_31 [ 8 ] , V_197 ) ;
F_59 ( V_31 ) ;
return V_209 != 0 ;
}
static int F_107 ( struct V_1 * V_8 , int V_216 ,
struct V_217 * V_31 , int V_208 ,
int V_218 )
{
int V_209 = V_210 ;
struct V_9 * V_10 ;
unsigned char V_44 [ 8 ] ;
struct V_155 * V_156 ;
V_10 = F_101 ( V_8 ) ;
if ( V_10 == NULL ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_87 ) ;
return - 1 ;
}
memset ( V_44 , 0 , sizeof( V_44 ) ) ;
F_102 ( V_10 , V_216 ? V_219 : V_220 , V_8 ,
V_31 , V_208 , 0 , V_44 , V_212 ) ;
if ( V_218 )
V_10 -> V_84 . V_85 [ 1 ] = V_218 ;
F_97 ( V_8 , V_10 , V_213 ) ;
V_156 = V_10 -> V_11 ;
if ( V_156 -> V_23 != 0 &&
V_156 -> V_23 != V_178 ) {
F_99 ( V_10 ) ;
V_209 = - 1 ;
}
F_103 ( V_8 , V_10 ) ;
return V_209 ;
}
static inline int F_108 ( struct V_1 * V_8 ,
struct V_217 * V_31 ,
int V_208 , int V_218 )
{
return F_107 ( V_8 , 0 , V_31 , V_208 , V_218 ) ;
}
static inline int F_109 ( struct V_1 * V_8 ,
struct V_217 * V_31 , int V_208 )
{
return F_107 ( V_8 , 1 , V_31 , V_208 , 0 ) ;
}
static inline void F_110 ( struct V_47 * V_28 ,
int V_93 , int V_94 , int V_95 )
{
V_28 -> V_93 = V_93 ;
V_28 -> V_94 = V_94 ;
V_28 -> V_95 = V_95 ;
}
static int F_111 ( struct V_1 * V_8 ,
unsigned char V_44 [] , struct V_47 * V_221 ,
unsigned char * V_222 )
{
#define F_112 43
#define F_113 "$DR-10"
#define F_114 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_115 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_223 ;
unsigned char * V_224 ;
V_223 = F_69 ( F_115 , V_126 ) ;
if ( ! V_223 )
goto V_225;
if ( F_100 ( V_8 , V_44 , 0 , V_223 ,
( unsigned char ) F_115 ) != 0 ) {
F_51 ( & V_8 -> V_15 -> V_16 ,
L_88 ) ;
goto V_225;
}
V_221 -> V_108 = ( V_223 [ 0 ] & 0x1f ) ;
memcpy ( V_221 -> V_44 , V_44 , 8 ) ;
memcpy ( V_221 -> V_117 , & V_223 [ 8 ] ,
sizeof( V_221 -> V_117 ) ) ;
memcpy ( V_221 -> V_116 , & V_223 [ 16 ] ,
sizeof( V_221 -> V_116 ) ) ;
memset ( V_221 -> V_59 , 0 ,
sizeof( V_221 -> V_59 ) ) ;
F_106 ( V_8 , V_44 , V_221 -> V_59 ,
sizeof( V_221 -> V_59 ) ) ;
if ( V_221 -> V_108 == V_226 &&
F_18 ( V_44 ) )
F_105 ( V_8 , V_44 , & V_221 -> V_54 ) ;
else
V_221 -> V_54 = V_55 ;
if ( V_222 ) {
V_224 = & V_223 [ F_112 ] ;
* V_222 = ( V_221 -> V_108 == V_227 &&
strncmp ( V_224 , F_113 ,
F_114 ) == 0 ) ;
}
F_59 ( V_223 ) ;
return 0 ;
V_225:
F_59 ( V_223 ) ;
return 1 ;
}
static int F_116 ( struct V_1 * V_8 , struct V_47 * V_28 )
{
int V_41 ;
for ( V_41 = 0 ; V_228 [ V_41 ] ; V_41 ++ )
if ( strncmp ( V_28 -> V_116 , V_228 [ V_41 ] ,
strlen ( V_228 [ V_41 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_117 ( struct V_1 * V_8 ,
T_4 * V_229 , struct V_47 * V_28 )
{
T_3 V_57 = F_118 ( * ( ( V_230 * ) V_229 ) ) ;
if ( ! F_18 ( V_229 ) ) {
if ( F_43 ( V_229 ) )
F_110 ( V_28 , 3 , 0 , V_57 & 0x3fff ) ;
else
F_110 ( V_28 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_116 ( V_8 , V_28 ) ) {
F_110 ( V_28 ,
1 , ( V_57 >> 16 ) & 0x3fff , V_57 & 0x00ff ) ;
return;
}
F_110 ( V_28 , 0 , 0 , V_57 & 0x3fff ) ;
}
static int F_119 ( struct V_1 * V_8 ,
struct V_47 * V_231 ,
struct V_47 * V_221 , T_4 * V_229 ,
unsigned long V_232 [] , int * V_233 )
{
unsigned char V_44 [ 8 ] ;
if ( F_120 ( V_231 -> V_94 , V_232 ) )
return 0 ;
if ( ! F_18 ( V_229 ) )
return 0 ;
if ( ! F_116 ( V_8 , V_231 ) )
return 0 ;
if ( V_231 -> V_95 == 0 )
return 0 ;
memset ( V_44 , 0 , 8 ) ;
V_44 [ 3 ] = V_231 -> V_94 ;
if ( F_43 ( V_44 ) )
return 0 ;
if ( F_44 ( V_8 ) )
return 0 ;
if ( * V_233 >= V_234 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_89
L_90
L_91 ) ;
return 0 ;
}
if ( F_111 ( V_8 , V_44 , V_221 , NULL ) )
return 0 ;
( * V_233 ) ++ ;
F_110 ( V_221 ,
V_231 -> V_93 , V_231 -> V_94 , 0 ) ;
F_121 ( V_231 -> V_94 , V_232 ) ;
return 1 ;
}
static int F_122 ( struct V_1 * V_8 ,
int V_235 ,
struct V_217 * V_236 , T_3 * V_237 ,
struct V_217 * V_238 , T_3 * V_239 )
{
if ( F_108 ( V_8 , V_236 , V_235 , 0 ) ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_92 ) ;
return - 1 ;
}
* V_237 = F_123 ( * ( ( V_240 * ) V_236 -> V_241 ) ) / 8 ;
if ( * V_237 > V_242 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_93
L_94 , V_242 ,
* V_237 - V_242 ) ;
* V_237 = V_242 ;
}
if ( F_109 ( V_8 , V_238 , V_235 ) ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_95 ) ;
return - 1 ;
}
* V_239 = F_123 ( * ( ( V_240 * ) V_238 -> V_241 ) ) / 8 ;
if ( * V_239 > V_243 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_96
L_97 , V_243 ,
* V_239 - V_243 ) ;
* V_239 = V_243 ;
}
if ( * V_239 + * V_237 > V_242 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_98
L_97 , V_242 ,
* V_237 + * V_239 - V_242 ) ;
* V_239 = V_242 - * V_237 ;
}
return 0 ;
}
T_4 * F_124 ( struct V_1 * V_8 , int V_244 , int V_41 ,
int V_237 , int V_239 , struct V_217 * V_245 ,
struct V_217 * V_246 )
{
int V_247 = V_237 + ( V_244 == 0 ) ;
int V_248 = V_237 + V_239 + ( V_244 == 0 ) ;
if ( V_41 == V_244 )
return V_92 ;
if ( V_41 < V_247 )
return & V_245 -> V_249 [ V_41 - ( V_244 == 0 ) ] [ 0 ] ;
if ( V_41 < V_248 )
return & V_246 -> V_249 [ V_41 - V_237 -
( V_244 == 0 ) ] [ 0 ] ;
F_125 () ;
return NULL ;
}
static void F_126 ( struct V_1 * V_8 , int V_100 )
{
struct V_217 * V_245 = NULL ;
struct V_217 * V_246 = NULL ;
T_3 V_237 = 0 ;
T_3 V_239 = 0 ;
T_3 V_250 = 0 ;
struct V_47 * * V_251 , * V_221 , * V_231 ;
int V_252 = 0 ;
int V_235 = sizeof( * V_245 ) + V_242 * 8 ;
int V_41 , V_233 , V_253 ;
int V_244 ;
F_46 ( V_232 , V_234 ) ;
V_251 = F_69 ( sizeof( * V_251 ) * V_98 , V_126 ) ;
V_245 = F_69 ( V_235 , V_126 ) ;
V_246 = F_69 ( V_235 , V_126 ) ;
V_231 = F_69 ( sizeof( * V_231 ) , V_126 ) ;
if ( ! V_251 || ! V_245 || ! V_246 || ! V_231 ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_99 ) ;
goto V_254;
}
memset ( V_232 , 0 , sizeof( V_232 ) ) ;
if ( F_122 ( V_8 , V_235 , V_245 , & V_237 ,
V_246 , & V_239 ) )
goto V_254;
V_253 = V_237 + V_239 + V_234 + 1 ;
for ( V_41 = 0 ; V_41 < V_253 ; V_41 ++ ) {
if ( V_41 >= V_98 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_100
L_101 , V_98 ,
V_253 - V_98 ) ;
break;
}
V_251 [ V_41 ] = F_69 ( sizeof( * V_251 [ V_41 ] ) , V_126 ) ;
if ( ! V_251 [ V_41 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_102 ,
__FILE__ , __LINE__ ) ;
goto V_254;
}
V_250 ++ ;
}
if ( F_28 ( F_44 ( V_8 ) ) )
V_244 = 0 ;
else
V_244 = V_237 + V_239 ;
V_233 = 0 ;
for ( V_41 = 0 ; V_41 < V_237 + V_239 + 1 ; V_41 ++ ) {
T_4 * V_229 , V_255 = 0 ;
V_229 = F_124 ( V_8 , V_244 ,
V_41 , V_237 , V_239 , V_245 , V_246 ) ;
if ( V_229 [ 3 ] & 0xC0 &&
V_41 < V_237 + ( V_244 == 0 ) )
continue;
if ( F_111 ( V_8 , V_229 , V_231 ,
& V_255 ) )
continue;
F_117 ( V_8 , V_229 , V_231 ) ;
V_221 = V_251 [ V_252 ] ;
if ( F_119 ( V_8 , V_231 , V_221 ,
V_229 , V_232 ,
& V_233 ) ) {
V_252 ++ ;
V_221 = V_251 [ V_252 ] ;
}
* V_221 = * V_231 ;
switch ( V_221 -> V_108 ) {
case V_227 :
if ( V_255 )
V_252 ++ ;
break;
case V_226 :
if ( V_41 < V_237 )
break;
V_252 ++ ;
break;
case V_256 :
case V_257 :
V_252 ++ ;
break;
case V_258 :
if ( ! F_43 ( V_229 ) )
break;
V_252 ++ ;
break;
default:
break;
}
if ( V_252 >= V_98 )
break;
}
F_68 ( V_8 , V_100 , V_251 , V_252 ) ;
V_254:
F_59 ( V_231 ) ;
for ( V_41 = 0 ; V_41 < V_250 ; V_41 ++ )
F_59 ( V_251 [ V_41 ] ) ;
F_59 ( V_251 ) ;
F_59 ( V_245 ) ;
F_59 ( V_246 ) ;
}
static int F_127 ( struct V_1 * V_8 ,
struct V_9 * V_152 ,
struct V_153 * V_154 )
{
unsigned int V_259 ;
struct V_260 * V_261 ;
T_5 V_195 ;
int V_262 , V_41 , V_263 , V_264 ;
struct V_134 * V_265 ;
F_55 ( F_128 ( V_154 ) > V_8 -> V_266 ) ;
V_262 = F_129 ( V_154 ) ;
if ( V_262 < 0 )
return V_262 ;
if ( ! V_262 )
goto V_267;
V_265 = V_152 -> V_138 ;
V_264 = 0 ;
V_263 = 0 ;
F_130 (cmd, sg, use_sg, i) {
if ( V_41 == V_8 -> V_139 - 1 &&
V_262 > V_8 -> V_139 ) {
V_264 = 1 ;
V_265 = V_8 -> V_129 [ V_152 -> V_140 ] ;
V_263 = 0 ;
}
V_195 = ( T_5 ) F_131 ( V_261 ) ;
V_259 = F_132 ( V_261 ) ;
V_265 -> V_146 . V_147 = ( T_3 ) ( V_195 & 0x0FFFFFFFFULL ) ;
V_265 -> V_146 . V_148 = ( T_3 ) ( ( V_195 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_265 -> V_143 = V_259 ;
V_265 -> V_141 = 0 ;
V_265 ++ ;
}
if ( V_262 + V_264 > V_8 -> V_268 )
V_8 -> V_268 = V_262 + V_264 ;
if ( V_264 ) {
V_152 -> V_76 . V_77 = V_8 -> V_139 ;
V_152 -> V_76 . V_144 = ( V_199 ) ( V_262 + 1 ) ;
F_82 ( V_8 , V_152 ) ;
return 0 ;
}
V_267:
V_152 -> V_76 . V_77 = ( T_4 ) V_262 ;
V_152 -> V_76 . V_144 = ( V_199 ) V_262 ;
return 0 ;
}
static int F_133 ( struct V_153 * V_154 ,
void (* F_134)( struct V_153 * ) )
{
struct V_1 * V_8 ;
struct V_47 * V_16 ;
unsigned char V_44 [ 8 ] ;
struct V_9 * V_10 ;
unsigned long V_49 ;
V_8 = F_1 ( V_154 -> V_28 ) ;
V_16 = V_154 -> V_28 -> V_51 ;
if ( ! V_16 ) {
V_154 -> V_162 = V_177 << 16 ;
F_134 ( V_154 ) ;
return 0 ;
}
memcpy ( V_44 , V_16 -> V_44 , sizeof( V_44 ) ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
if ( F_28 ( V_8 -> V_202 ) ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
V_154 -> V_162 = V_182 << 16 ;
F_134 ( V_154 ) ;
return 0 ;
}
F_22 ( & V_8 -> V_50 , V_49 ) ;
V_10 = F_135 ( V_8 ) ;
if ( V_10 == NULL ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_103 ) ;
return V_269 ;
}
V_154 -> V_169 = F_134 ;
V_154 -> V_270 = ( unsigned char * ) V_10 ;
V_10 -> V_271 = V_272 ;
V_10 -> V_161 = V_154 ;
V_10 -> V_76 . V_79 = 0 ;
memcpy ( & V_10 -> V_76 . V_249 . V_273 [ 0 ] , & V_44 [ 0 ] , 8 ) ;
V_10 -> V_76 . V_274 . V_147 = ( V_10 -> V_140 << V_275 ) ;
V_10 -> V_76 . V_274 . V_147 |= V_276 ;
V_10 -> V_84 . V_277 = 0 ;
memset ( V_10 -> V_84 . V_85 , 0 , sizeof( V_10 -> V_84 . V_85 ) ) ;
F_55 ( V_154 -> V_278 > sizeof( V_10 -> V_84 . V_85 ) ) ;
V_10 -> V_84 . V_279 = V_154 -> V_278 ;
memcpy ( V_10 -> V_84 . V_85 , V_154 -> V_176 , V_154 -> V_278 ) ;
V_10 -> V_84 . Type . Type = V_212 ;
V_10 -> V_84 . Type . V_280 = V_281 ;
switch ( V_154 -> V_282 ) {
case V_283 :
V_10 -> V_84 . Type . V_284 = V_285 ;
break;
case V_286 :
V_10 -> V_84 . Type . V_284 = V_287 ;
break;
case V_288 :
V_10 -> V_84 . Type . V_284 = V_289 ;
break;
case V_290 :
V_10 -> V_84 . Type . V_284 = V_291 ;
break;
default:
F_51 ( & V_8 -> V_15 -> V_16 , L_104 ,
V_154 -> V_282 ) ;
F_125 () ;
break;
}
if ( F_127 ( V_8 , V_10 , V_154 ) < 0 ) {
F_89 ( V_8 , V_10 ) ;
return V_269 ;
}
F_37 ( V_8 , V_10 ) ;
return 0 ;
}
int F_136 ( struct V_6 * V_7 ,
unsigned long V_292 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_49 ;
int V_293 ;
F_21 ( & V_8 -> V_294 , V_49 ) ;
V_293 = V_8 -> V_295 ;
F_22 ( & V_8 -> V_294 , V_49 ) ;
return V_293 ;
}
static int F_137 ( struct V_2 * V_3 ,
int V_296 , int V_297 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_297 != V_298 )
return - V_299 ;
if ( V_296 < 1 )
V_296 = 1 ;
else
if ( V_296 > V_8 -> V_130 )
V_296 = V_8 -> V_130 ;
F_138 ( V_3 , F_139 ( V_3 ) , V_296 ) ;
return V_3 -> V_300 ;
}
static void F_140 ( struct V_1 * V_8 )
{
F_141 ( V_8 -> V_34 ) ;
F_142 ( V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
}
static int F_143 ( struct V_1 * V_8 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_144 ( & V_301 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_302;
V_7 -> V_303 = 0 ;
V_7 -> V_304 = 0 ;
V_7 -> V_305 = - 1 ;
V_7 -> V_306 = 3 ;
V_7 -> V_307 = V_308 ;
V_7 -> V_309 = V_243 ;
V_7 -> V_310 = V_243 ;
V_7 -> V_311 = V_8 -> V_130 ;
V_7 -> V_312 = V_8 -> V_130 ;
V_7 -> V_313 = V_8 -> V_266 ;
V_8 -> V_34 = V_7 ;
V_7 -> V_51 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_314 = V_8 -> V_315 [ V_8 -> V_316 ] ;
V_7 -> V_317 = V_7 -> V_314 ;
error = F_145 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_318;
F_146 ( V_7 ) ;
return 0 ;
V_318:
F_51 ( & V_8 -> V_15 -> V_16 , L_105
L_106 , V_319 , V_8 -> V_18 ) ;
F_142 ( V_7 ) ;
return error ;
V_302:
F_51 ( & V_8 -> V_15 -> V_16 , L_107
L_106 , V_319 , V_8 -> V_18 ) ;
return - V_132 ;
}
static int F_147 ( struct V_1 * V_8 ,
unsigned char V_320 [] )
{
int V_209 = 0 ;
int V_32 = 0 ;
int V_321 = 1 ;
struct V_9 * V_10 ;
V_10 = F_101 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_33
L_108 ) ;
return V_322 ;
}
while ( V_32 < V_323 ) {
F_98 ( 1000 * V_321 ) ;
V_32 ++ ;
if ( V_321 < V_324 )
V_321 = V_321 * 2 ;
F_102 ( V_10 , V_325 , V_8 , NULL , 0 , 0 , V_320 , V_212 ) ;
F_93 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_23 == V_326 )
break;
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 == V_170 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_327 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_109
L_110 , V_321 ) ;
V_209 = 1 ;
}
if ( V_209 )
F_5 ( & V_8 -> V_15 -> V_16 , L_111 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_112 ) ;
F_103 ( V_8 , V_10 ) ;
return V_209 ;
}
static int F_148 ( struct V_153 * V_328 )
{
int V_209 ;
struct V_1 * V_8 ;
struct V_47 * V_16 ;
V_8 = F_1 ( V_328 -> V_28 ) ;
if ( V_8 == NULL )
return V_329 ;
V_16 = V_328 -> V_28 -> V_51 ;
if ( ! V_16 ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_113
L_114 ) ;
return V_329 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_115 ,
V_8 -> V_34 -> V_330 , V_16 -> V_93 , V_16 -> V_94 , V_16 -> V_95 ) ;
V_209 = F_104 ( V_8 , V_16 -> V_44 ) ;
if ( V_209 == 0 && F_147 ( V_8 , V_16 -> V_44 ) == 0 )
return V_331 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_116 ) ;
return V_329 ;
}
static void F_149 ( T_4 * V_332 )
{
T_4 V_333 [ 8 ] ;
memcpy ( V_333 , V_332 , 8 ) ;
V_332 [ 0 ] = V_333 [ 3 ] ;
V_332 [ 1 ] = V_333 [ 2 ] ;
V_332 [ 2 ] = V_333 [ 1 ] ;
V_332 [ 3 ] = V_333 [ 0 ] ;
V_332 [ 4 ] = V_333 [ 7 ] ;
V_332 [ 5 ] = V_333 [ 6 ] ;
V_332 [ 6 ] = V_333 [ 5 ] ;
V_332 [ 7 ] = V_333 [ 4 ] ;
}
static int F_150 ( struct V_1 * V_8 , unsigned char * V_44 ,
struct V_9 * abort , int V_334 )
{
int V_209 = V_210 ;
struct V_9 * V_10 ;
struct V_155 * V_156 ;
V_10 = F_101 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_87 ) ;
return - V_132 ;
}
F_102 ( V_10 , V_335 , V_8 , abort , 0 , 0 , V_44 , V_215 ) ;
if ( V_334 )
F_149 ( & V_10 -> V_84 . V_85 [ 4 ] ) ;
F_93 ( V_8 , V_10 ) ;
F_90 ( & V_8 -> V_15 -> V_16 , L_117 ,
V_319 , abort -> V_76 . V_274 . V_148 , abort -> V_76 . V_274 . V_147 ) ;
V_156 = V_10 -> V_11 ;
switch ( V_156 -> V_23 ) {
case V_326 :
break;
case V_191 :
V_209 = - 1 ;
break;
default:
F_90 ( & V_8 -> V_15 -> V_16 , L_118 ,
V_319 , abort -> V_76 . V_274 . V_148 ,
abort -> V_76 . V_274 . V_147 ) ;
F_99 ( V_10 ) ;
V_209 = - 1 ;
break;
}
F_103 ( V_8 , V_10 ) ;
F_90 ( & V_8 -> V_15 -> V_16 , L_119 , V_319 ,
abort -> V_76 . V_274 . V_148 , abort -> V_76 . V_274 . V_147 ) ;
return V_209 ;
}
static struct V_9 * F_151 ( struct V_1 * V_8 ,
struct V_153 * V_336 , struct V_60 * V_337 )
{
unsigned long V_49 ;
struct V_9 * V_10 = NULL ;
if ( ! V_336 )
return 0 ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
F_152 (c, queue_head, list) {
if ( V_10 -> V_161 == NULL )
continue;
if ( V_10 -> V_161 == V_336 ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
return V_10 ;
}
}
F_22 ( & V_8 -> V_50 , V_49 ) ;
return NULL ;
}
static struct V_9 * F_153 ( struct V_1 * V_8 ,
T_4 * V_332 , struct V_60 * V_337 )
{
unsigned long V_49 ;
struct V_9 * V_10 ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
F_152 (c, queue_head, list) {
if ( memcmp ( & V_10 -> V_76 . V_274 , V_332 , 8 ) != 0 )
continue;
F_22 ( & V_8 -> V_50 , V_49 ) ;
return V_10 ;
}
F_22 ( & V_8 -> V_50 , V_49 ) ;
return NULL ;
}
static int F_154 ( struct V_1 * V_8 ,
unsigned char * V_44 , struct V_9 * abort )
{
T_4 V_338 [ 8 ] ;
struct V_9 * V_10 ;
int V_209 = 0 , V_339 = 0 ;
memcpy ( V_338 , & abort -> V_84 . V_85 [ 4 ] , 8 ) ;
F_149 ( V_338 ) ;
V_10 = F_153 ( V_8 , V_338 , & V_8 -> V_340 ) ;
if ( V_10 != NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_120 ) ;
return F_150 ( V_8 , V_44 , abort , 0 ) ;
}
V_209 = F_150 ( V_8 , V_44 , abort , 0 ) ;
V_10 = F_151 ( V_8 , abort -> V_161 , & V_8 -> V_340 ) ;
if ( V_10 )
V_339 = F_150 ( V_8 , V_44 , abort , 1 ) ;
return V_209 && V_339 ;
}
static int F_155 ( struct V_153 * V_341 )
{
int V_41 , V_209 ;
struct V_1 * V_8 ;
struct V_47 * V_16 ;
struct V_9 * abort ;
struct V_9 * V_96 ;
struct V_153 * V_342 ;
char V_343 [ 256 ] ;
int V_344 = 0 ;
V_8 = F_1 ( V_341 -> V_28 ) ;
if ( F_156 ( V_8 == NULL ,
L_121 ) )
return V_329 ;
if ( ! ( V_345 & V_8 -> V_346 ) &&
! ( V_347 & V_8 -> V_346 ) )
return V_329 ;
memset ( V_343 , 0 , sizeof( V_343 ) ) ;
V_344 += sprintf ( V_343 + V_344 , L_122 ,
V_8 -> V_34 -> V_330 , V_341 -> V_28 -> V_348 ,
V_341 -> V_28 -> V_349 , V_341 -> V_28 -> V_95 ) ;
V_16 = V_341 -> V_28 -> V_51 ;
if ( ! V_16 ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_123 ,
V_343 ) ;
return V_329 ;
}
abort = (struct V_9 * ) V_341 -> V_270 ;
if ( abort == NULL ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_124 ,
V_343 ) ;
return V_329 ;
}
V_344 += sprintf ( V_343 + V_344 , L_125 ,
abort -> V_76 . V_274 . V_148 , abort -> V_76 . V_274 . V_147 ) ;
V_342 = (struct V_153 * ) abort -> V_161 ;
if ( V_342 != NULL )
V_344 += sprintf ( V_343 + V_344 , L_126 ,
V_342 -> V_176 [ 0 ] , V_342 -> V_350 ) ;
F_90 ( & V_8 -> V_15 -> V_16 , L_16 , V_343 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_127 ,
V_8 -> V_34 -> V_330 , V_16 -> V_93 , V_16 -> V_94 , V_16 -> V_95 ) ;
V_96 = F_151 ( V_8 , V_341 , & V_8 -> V_90 ) ;
if ( V_96 ) {
V_96 -> V_11 -> V_23 = V_185 ;
F_157 ( V_96 ) ;
F_52 ( & V_8 -> V_15 -> V_16 , L_128 ,
V_343 ) ;
return V_331 ;
}
V_96 = F_151 ( V_8 , V_341 , & V_8 -> V_340 ) ;
if ( ! V_96 ) {
F_90 ( & V_8 -> V_15 -> V_16 , L_129 ,
V_343 ) ;
return V_331 ;
}
V_209 = F_154 ( V_8 , V_16 -> V_44 , abort ) ;
if ( V_209 != 0 ) {
F_90 ( & V_8 -> V_15 -> V_16 , L_130 , V_343 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_131 ,
V_8 -> V_34 -> V_330 ,
V_16 -> V_93 , V_16 -> V_94 , V_16 -> V_95 ) ;
return V_329 ;
}
F_52 ( & V_8 -> V_15 -> V_16 , L_132 , V_343 ) ;
#define F_158 30
for ( V_41 = 0 ; V_41 < F_158 * 10 ; V_41 ++ ) {
V_96 = F_151 ( V_8 , V_341 , & V_8 -> V_340 ) ;
if ( ! V_96 )
return V_331 ;
F_98 ( 100 ) ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_133 ,
V_343 , F_158 ) ;
return V_329 ;
}
static struct V_9 * F_135 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_41 ;
union V_149 V_137 ;
V_196 V_351 , V_352 ;
unsigned long V_49 ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
do {
V_41 = F_49 ( V_8 -> V_353 , V_8 -> V_130 ) ;
if ( V_41 == V_8 -> V_130 ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
return NULL ;
}
} while ( F_159
( V_41 & ( V_354 - 1 ) ,
V_8 -> V_353 + ( V_41 / V_354 ) ) != 0 );
V_8 -> V_355 ++ ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
V_10 = V_8 -> V_356 + V_41 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_351 = V_8 -> V_357
+ V_41 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_358 + V_41 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_352 = V_8 -> V_359
+ V_41 * sizeof( * V_10 -> V_11 ) ;
V_10 -> V_140 = V_41 ;
F_160 ( & V_10 -> V_61 ) ;
V_10 -> V_74 = ( T_3 ) V_351 ;
V_137 . V_151 = ( T_5 ) V_352 ;
V_10 -> V_360 . V_146 . V_147 = V_137 . V_150 . V_147 ;
V_10 -> V_360 . V_146 . V_148 = V_137 . V_150 . V_148 ;
V_10 -> V_360 . V_143 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_101 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
union V_149 V_137 ;
V_196 V_351 , V_352 ;
V_10 = F_161 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_351 ) ;
if ( V_10 == NULL )
return NULL ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_140 = - 1 ;
V_10 -> V_11 = F_161 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_352 ) ;
if ( V_10 -> V_11 == NULL ) {
F_162 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_351 ) ;
return NULL ;
}
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_160 ( & V_10 -> V_61 ) ;
V_10 -> V_74 = ( T_3 ) V_351 ;
V_137 . V_151 = ( T_5 ) V_352 ;
V_10 -> V_360 . V_146 . V_147 = V_137 . V_150 . V_147 ;
V_10 -> V_360 . V_146 . V_148 = V_137 . V_150 . V_148 ;
V_10 -> V_360 . V_143 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_89 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_41 ;
unsigned long V_49 ;
V_41 = V_10 - V_8 -> V_356 ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
F_163 ( V_41 & ( V_354 - 1 ) ,
V_8 -> V_353 + ( V_41 / V_354 ) ) ;
V_8 -> V_361 ++ ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
}
static void F_103 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
union V_149 V_137 ;
V_137 . V_150 . V_147 = V_10 -> V_360 . V_146 . V_147 ;
V_137 . V_150 . V_148 = V_10 -> V_360 . V_146 . V_148 ;
F_162 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 , ( V_196 ) V_137 . V_151 ) ;
F_162 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_196 ) ( V_10 -> V_74 & V_362 ) ) ;
}
static int F_164 ( struct V_2 * V_16 , int V_154 , void * V_363 )
{
T_6 T_7 * V_364 =
( T_6 T_7 * ) V_363 ;
T_8 V_365 ;
T_8 T_7 * V_366 = F_165 ( sizeof( V_365 ) ) ;
int V_367 ;
T_3 V_152 ;
memset ( & V_365 , 0 , sizeof( V_365 ) ) ;
V_367 = 0 ;
V_367 |= F_166 ( & V_365 . V_368 , & V_364 -> V_368 ,
sizeof( V_365 . V_368 ) ) ;
V_367 |= F_166 ( & V_365 . V_84 , & V_364 -> V_84 ,
sizeof( V_365 . V_84 ) ) ;
V_367 |= F_166 ( & V_365 . V_369 , & V_364 -> V_369 ,
sizeof( V_365 . V_369 ) ) ;
V_367 |= F_167 ( V_365 . V_370 , & V_364 -> V_370 ) ;
V_367 |= F_167 ( V_152 , & V_364 -> V_31 ) ;
V_365 . V_31 = F_168 ( V_152 ) ;
V_367 |= F_169 ( V_366 , & V_365 , sizeof( V_365 ) ) ;
if ( V_367 )
return - V_371 ;
V_367 = F_170 ( V_16 , V_372 , ( void * ) V_366 ) ;
if ( V_367 )
return V_367 ;
V_367 |= F_171 ( & V_364 -> V_369 , & V_366 -> V_369 ,
sizeof( V_364 -> V_369 ) ) ;
if ( V_367 )
return - V_371 ;
return V_367 ;
}
static int F_172 ( struct V_2 * V_16 ,
int V_154 , void * V_363 )
{
T_9 T_7 * V_364 =
( T_9 T_7 * ) V_363 ;
T_10 V_365 ;
T_10 T_7 * V_366 =
F_165 ( sizeof( V_365 ) ) ;
int V_367 ;
T_3 V_152 ;
memset ( & V_365 , 0 , sizeof( V_365 ) ) ;
V_367 = 0 ;
V_367 |= F_166 ( & V_365 . V_368 , & V_364 -> V_368 ,
sizeof( V_365 . V_368 ) ) ;
V_367 |= F_166 ( & V_365 . V_84 , & V_364 -> V_84 ,
sizeof( V_365 . V_84 ) ) ;
V_367 |= F_166 ( & V_365 . V_369 , & V_364 -> V_369 ,
sizeof( V_365 . V_369 ) ) ;
V_367 |= F_167 ( V_365 . V_370 , & V_364 -> V_370 ) ;
V_367 |= F_167 ( V_365 . V_373 , & V_364 -> V_373 ) ;
V_367 |= F_167 ( V_152 , & V_364 -> V_31 ) ;
V_365 . V_31 = F_168 ( V_152 ) ;
V_367 |= F_169 ( V_366 , & V_365 , sizeof( V_365 ) ) ;
if ( V_367 )
return - V_371 ;
V_367 = F_170 ( V_16 , V_374 , ( void * ) V_366 ) ;
if ( V_367 )
return V_367 ;
V_367 |= F_171 ( & V_364 -> V_369 , & V_366 -> V_369 ,
sizeof( V_364 -> V_369 ) ) ;
if ( V_367 )
return - V_371 ;
return V_367 ;
}
static int F_173 ( struct V_2 * V_16 , int V_154 , void * V_363 )
{
switch ( V_154 ) {
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
return F_170 ( V_16 , V_154 , V_363 ) ;
case V_390 :
return F_164 ( V_16 , V_154 , V_363 ) ;
case V_391 :
return F_172 ( V_16 , V_154 , V_363 ) ;
default:
return - V_392 ;
}
}
static int F_174 ( struct V_1 * V_8 , void T_7 * V_393 )
{
struct V_394 V_395 ;
if ( ! V_393 )
return - V_396 ;
V_395 . V_397 = F_175 ( V_8 -> V_15 -> V_93 ) ;
V_395 . V_93 = V_8 -> V_15 -> V_93 -> V_398 ;
V_395 . V_399 = V_8 -> V_15 -> V_400 ;
V_395 . V_40 = V_8 -> V_40 ;
if ( F_169 ( V_393 , & V_395 , sizeof( V_395 ) ) )
return - V_371 ;
return 0 ;
}
static int F_176 ( struct V_1 * V_8 , void T_7 * V_393 )
{
T_11 V_401 ;
unsigned char V_402 , V_403 , V_404 ;
int V_209 ;
V_209 = sscanf ( V_405 , L_134 ,
& V_402 , & V_403 , & V_404 ) ;
if ( V_209 != 3 ) {
F_52 ( & V_8 -> V_15 -> V_16 , L_135
L_136 , V_405 ) ;
V_402 = 0 ;
V_403 = 0 ;
V_404 = 0 ;
}
V_401 = ( V_402 << 16 ) | ( V_403 << 8 ) | V_404 ;
if ( ! V_393 )
return - V_396 ;
if ( F_169 ( V_393 , & V_401 , sizeof( T_11 ) ) )
return - V_371 ;
return 0 ;
}
static int F_177 ( struct V_1 * V_8 , void T_7 * V_393 )
{
T_8 V_406 ;
struct V_9 * V_10 ;
char * V_407 = NULL ;
union V_149 V_137 ;
if ( ! V_393 )
return - V_396 ;
if ( ! F_178 ( V_408 ) )
return - V_409 ;
if ( F_166 ( & V_406 , V_393 , sizeof( V_406 ) ) )
return - V_371 ;
if ( ( V_406 . V_370 < 1 ) &&
( V_406 . V_84 . Type . V_284 != V_289 ) ) {
return - V_396 ;
}
if ( V_406 . V_370 > 0 ) {
V_407 = F_81 ( V_406 . V_370 , V_126 ) ;
if ( V_407 == NULL )
return - V_371 ;
if ( V_406 . V_84 . Type . V_284 == V_285 ) {
if ( F_166 ( V_407 , V_406 . V_31 ,
V_406 . V_370 ) ) {
F_59 ( V_407 ) ;
return - V_371 ;
}
} else {
memset ( V_407 , 0 , V_406 . V_370 ) ;
}
}
V_10 = F_101 ( V_8 ) ;
if ( V_10 == NULL ) {
F_59 ( V_407 ) ;
return - V_132 ;
}
V_10 -> V_271 = V_410 ;
V_10 -> V_76 . V_79 = 0 ;
if ( V_406 . V_370 > 0 ) {
V_10 -> V_76 . V_77 = 1 ;
V_10 -> V_76 . V_144 = 1 ;
} else {
V_10 -> V_76 . V_77 = 0 ;
V_10 -> V_76 . V_144 = 0 ;
}
memcpy ( & V_10 -> V_76 . V_249 , & V_406 . V_368 , sizeof( V_10 -> V_76 . V_249 ) ) ;
V_10 -> V_76 . V_274 . V_147 = V_10 -> V_74 ;
memcpy ( & V_10 -> V_84 , & V_406 . V_84 ,
sizeof( V_10 -> V_84 ) ) ;
if ( V_406 . V_370 > 0 ) {
V_137 . V_151 = F_83 ( V_8 -> V_15 , V_407 ,
V_406 . V_370 , V_411 ) ;
V_10 -> V_138 [ 0 ] . V_146 . V_147 = V_137 . V_150 . V_147 ;
V_10 -> V_138 [ 0 ] . V_146 . V_148 = V_137 . V_150 . V_148 ;
V_10 -> V_138 [ 0 ] . V_143 = V_406 . V_370 ;
V_10 -> V_138 [ 0 ] . V_141 = 0 ;
}
F_96 ( V_8 , V_10 ) ;
if ( V_406 . V_370 > 0 )
F_91 ( V_8 -> V_15 , V_10 , 1 , V_411 ) ;
F_179 ( V_8 , V_10 ) ;
memcpy ( & V_406 . V_369 , V_10 -> V_11 ,
sizeof( V_406 . V_369 ) ) ;
if ( F_169 ( V_393 , & V_406 , sizeof( V_406 ) ) ) {
F_59 ( V_407 ) ;
F_103 ( V_8 , V_10 ) ;
return - V_371 ;
}
if ( V_406 . V_84 . Type . V_284 == V_287 &&
V_406 . V_370 > 0 ) {
if ( F_169 ( V_406 . V_31 , V_407 , V_406 . V_370 ) ) {
F_59 ( V_407 ) ;
F_103 ( V_8 , V_10 ) ;
return - V_371 ;
}
}
F_59 ( V_407 ) ;
F_103 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_8 , void T_7 * V_393 )
{
T_10 * V_412 ;
struct V_9 * V_10 ;
unsigned char * * V_407 = NULL ;
int * V_413 = NULL ;
union V_149 V_137 ;
T_12 V_193 = 0 ;
int V_414 = 0 ;
int V_41 ;
T_3 V_415 ;
T_3 V_416 ;
T_12 T_7 * V_417 ;
if ( ! V_393 )
return - V_396 ;
if ( ! F_178 ( V_408 ) )
return - V_409 ;
V_412 = ( T_10 * )
F_81 ( sizeof( * V_412 ) , V_126 ) ;
if ( ! V_412 ) {
V_414 = - V_132 ;
goto V_418;
}
if ( F_166 ( V_412 , V_393 , sizeof( * V_412 ) ) ) {
V_414 = - V_371 ;
goto V_418;
}
if ( ( V_412 -> V_370 < 1 ) &&
( V_412 -> V_84 . Type . V_284 != V_289 ) ) {
V_414 = - V_396 ;
goto V_418;
}
if ( V_412 -> V_373 > V_419 ) {
V_414 = - V_396 ;
goto V_418;
}
if ( V_412 -> V_370 > V_412 -> V_373 * V_420 ) {
V_414 = - V_396 ;
goto V_418;
}
V_407 = F_69 ( V_420 * sizeof( char * ) , V_126 ) ;
if ( ! V_407 ) {
V_414 = - V_132 ;
goto V_418;
}
V_413 = F_81 ( V_420 * sizeof( int ) , V_126 ) ;
if ( ! V_413 ) {
V_414 = - V_132 ;
goto V_418;
}
V_415 = V_412 -> V_370 ;
V_417 = V_412 -> V_31 ;
while ( V_415 ) {
V_416 = ( V_415 > V_412 -> V_373 ) ? V_412 -> V_373 : V_415 ;
V_413 [ V_193 ] = V_416 ;
V_407 [ V_193 ] = F_81 ( V_416 , V_126 ) ;
if ( V_407 [ V_193 ] == NULL ) {
V_414 = - V_132 ;
goto V_418;
}
if ( V_412 -> V_84 . Type . V_284 == V_285 ) {
if ( F_166 ( V_407 [ V_193 ] , V_417 , V_416 ) ) {
V_414 = - V_132 ;
goto V_418;
}
} else
memset ( V_407 [ V_193 ] , 0 , V_416 ) ;
V_415 -= V_416 ;
V_417 += V_416 ;
V_193 ++ ;
}
V_10 = F_101 ( V_8 ) ;
if ( V_10 == NULL ) {
V_414 = - V_132 ;
goto V_418;
}
V_10 -> V_271 = V_410 ;
V_10 -> V_76 . V_79 = 0 ;
V_10 -> V_76 . V_77 = V_10 -> V_76 . V_144 = V_193 ;
memcpy ( & V_10 -> V_76 . V_249 , & V_412 -> V_368 , sizeof( V_10 -> V_76 . V_249 ) ) ;
V_10 -> V_76 . V_274 . V_147 = V_10 -> V_74 ;
memcpy ( & V_10 -> V_84 , & V_412 -> V_84 , sizeof( V_10 -> V_84 ) ) ;
if ( V_412 -> V_370 > 0 ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_193 ; V_41 ++ ) {
V_137 . V_151 = F_83 ( V_8 -> V_15 , V_407 [ V_41 ] ,
V_413 [ V_41 ] , V_411 ) ;
V_10 -> V_138 [ V_41 ] . V_146 . V_147 = V_137 . V_150 . V_147 ;
V_10 -> V_138 [ V_41 ] . V_146 . V_148 = V_137 . V_150 . V_148 ;
V_10 -> V_138 [ V_41 ] . V_143 = V_413 [ V_41 ] ;
V_10 -> V_138 [ V_41 ] . V_141 = 0 ;
}
}
F_96 ( V_8 , V_10 ) ;
if ( V_193 )
F_91 ( V_8 -> V_15 , V_10 , V_193 , V_411 ) ;
F_179 ( V_8 , V_10 ) ;
memcpy ( & V_412 -> V_369 , V_10 -> V_11 , sizeof( V_412 -> V_369 ) ) ;
if ( F_169 ( V_393 , V_412 , sizeof( * V_412 ) ) ) {
F_103 ( V_8 , V_10 ) ;
V_414 = - V_371 ;
goto V_418;
}
if ( V_412 -> V_84 . Type . V_284 == V_287 && V_412 -> V_370 > 0 ) {
T_12 T_7 * V_421 = V_412 -> V_31 ;
for ( V_41 = 0 ; V_41 < V_193 ; V_41 ++ ) {
if ( F_169 ( V_421 , V_407 [ V_41 ] , V_413 [ V_41 ] ) ) {
F_103 ( V_8 , V_10 ) ;
V_414 = - V_371 ;
goto V_418;
}
V_421 += V_413 [ V_41 ] ;
}
}
F_103 ( V_8 , V_10 ) ;
V_414 = 0 ;
V_418:
if ( V_407 ) {
for ( V_41 = 0 ; V_41 < V_193 ; V_41 ++ )
F_59 ( V_407 [ V_41 ] ) ;
F_59 ( V_407 ) ;
}
F_59 ( V_413 ) ;
F_59 ( V_412 ) ;
return V_414 ;
}
static void F_179 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 != V_170 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_170 ( struct V_2 * V_16 , int V_154 , void * V_363 )
{
struct V_1 * V_8 ;
void T_7 * V_393 = ( void T_7 * ) V_363 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_154 ) {
case V_385 :
case V_386 :
case V_387 :
F_9 ( V_8 -> V_34 ) ;
return 0 ;
case V_375 :
return F_174 ( V_8 , V_393 ) ;
case V_383 :
return F_176 ( V_8 , V_393 ) ;
case V_372 :
return F_177 ( V_8 , V_393 ) ;
case V_374 :
return F_180 ( V_8 , V_393 ) ;
default:
return - V_422 ;
}
}
static int T_13 F_181 ( struct V_1 * V_8 ,
unsigned char * V_44 , T_4 V_423 )
{
struct V_9 * V_10 ;
V_10 = F_135 ( V_8 ) ;
if ( ! V_10 )
return - V_132 ;
F_102 ( V_10 , V_214 , V_8 , NULL , 0 , 0 ,
V_92 , V_215 ) ;
V_10 -> V_84 . V_85 [ 1 ] = V_423 ;
V_10 -> V_201 = NULL ;
F_37 ( V_8 , V_10 ) ;
return 0 ;
}
static void F_102 ( struct V_9 * V_10 , T_4 V_154 , struct V_1 * V_8 ,
void * V_407 , T_2 V_424 , T_4 V_425 , unsigned char * V_44 ,
int V_271 )
{
int V_426 = V_289 ;
struct V_9 * V_63 ;
V_10 -> V_271 = V_410 ;
V_10 -> V_76 . V_79 = 0 ;
if ( V_407 != NULL && V_424 > 0 ) {
V_10 -> V_76 . V_77 = 1 ;
V_10 -> V_76 . V_144 = 1 ;
} else {
V_10 -> V_76 . V_77 = 0 ;
V_10 -> V_76 . V_144 = 0 ;
}
V_10 -> V_76 . V_274 . V_147 = V_10 -> V_74 ;
memcpy ( V_10 -> V_76 . V_249 . V_273 , V_44 , 8 ) ;
V_10 -> V_84 . Type . Type = V_271 ;
if ( V_271 == V_212 ) {
switch ( V_154 ) {
case V_211 :
if ( V_425 != 0 ) {
V_10 -> V_84 . V_85 [ 1 ] = 0x01 ;
V_10 -> V_84 . V_85 [ 2 ] = V_425 ;
}
V_10 -> V_84 . V_279 = 6 ;
V_10 -> V_84 . Type . V_280 = V_281 ;
V_10 -> V_84 . Type . V_284 = V_287 ;
V_10 -> V_84 . V_277 = 0 ;
V_10 -> V_84 . V_85 [ 0 ] = V_211 ;
V_10 -> V_84 . V_85 [ 4 ] = V_424 & 0xFF ;
break;
case V_219 :
case V_220 :
V_10 -> V_84 . V_279 = 12 ;
V_10 -> V_84 . Type . V_280 = V_281 ;
V_10 -> V_84 . Type . V_284 = V_287 ;
V_10 -> V_84 . V_277 = 0 ;
V_10 -> V_84 . V_85 [ 0 ] = V_154 ;
V_10 -> V_84 . V_85 [ 6 ] = ( V_424 >> 24 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 7 ] = ( V_424 >> 16 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 8 ] = ( V_424 >> 8 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 9 ] = V_424 & 0xFF ;
break;
case V_427 :
V_10 -> V_84 . V_279 = 12 ;
V_10 -> V_84 . Type . V_280 = V_281 ;
V_10 -> V_84 . Type . V_284 = V_285 ;
V_10 -> V_84 . V_277 = 0 ;
V_10 -> V_84 . V_85 [ 0 ] = V_82 ;
V_10 -> V_84 . V_85 [ 6 ] = V_428 ;
V_10 -> V_84 . V_85 [ 7 ] = ( V_424 >> 8 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 8 ] = V_424 & 0xFF ;
break;
case V_325 :
V_10 -> V_84 . V_279 = 6 ;
V_10 -> V_84 . Type . V_280 = V_281 ;
V_10 -> V_84 . Type . V_284 = V_289 ;
V_10 -> V_84 . V_277 = 0 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_137 , V_154 ) ;
F_125 () ;
return;
}
} else if ( V_271 == V_215 ) {
switch ( V_154 ) {
case V_214 :
V_10 -> V_84 . V_279 = 16 ;
V_10 -> V_84 . Type . Type = 1 ;
V_10 -> V_84 . Type . V_280 = V_281 ;
V_10 -> V_84 . Type . V_284 = V_289 ;
V_10 -> V_84 . V_277 = 0 ;
memset ( & V_10 -> V_84 . V_85 [ 0 ] , 0 , sizeof( V_10 -> V_84 . V_85 ) ) ;
V_10 -> V_84 . V_85 [ 0 ] = V_154 ;
V_10 -> V_84 . V_85 [ 1 ] = V_429 ;
V_10 -> V_84 . V_85 [ 4 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 5 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 6 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 7 ] = 0x00 ;
break;
case V_335 :
V_63 = V_407 ;
F_90 ( & V_8 -> V_15 -> V_16 , L_138 ,
V_63 -> V_76 . V_274 . V_148 , V_63 -> V_76 . V_274 . V_147 ,
V_10 -> V_76 . V_274 . V_148 , V_10 -> V_76 . V_274 . V_147 ) ;
V_10 -> V_84 . V_279 = 16 ;
V_10 -> V_84 . Type . Type = V_215 ;
V_10 -> V_84 . Type . V_280 = V_281 ;
V_10 -> V_84 . Type . V_284 = V_285 ;
V_10 -> V_84 . V_277 = 0 ;
V_10 -> V_84 . V_85 [ 0 ] = V_430 ;
V_10 -> V_84 . V_85 [ 1 ] = V_431 ;
V_10 -> V_84 . V_85 [ 2 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 3 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 4 ] = V_63 -> V_76 . V_274 . V_147 & 0xFF ;
V_10 -> V_84 . V_85 [ 5 ] = ( V_63 -> V_76 . V_274 . V_147 >> 8 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 6 ] = ( V_63 -> V_76 . V_274 . V_147 >> 16 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 7 ] = ( V_63 -> V_76 . V_274 . V_147 >> 24 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 8 ] = V_63 -> V_76 . V_274 . V_148 & 0xFF ;
V_10 -> V_84 . V_85 [ 9 ] = ( V_63 -> V_76 . V_274 . V_148 >> 8 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 10 ] = ( V_63 -> V_76 . V_274 . V_148 >> 16 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 11 ] = ( V_63 -> V_76 . V_274 . V_148 >> 24 ) & 0xFF ;
V_10 -> V_84 . V_85 [ 12 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 13 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 14 ] = 0x00 ;
V_10 -> V_84 . V_85 [ 15 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_139 ,
V_154 ) ;
F_125 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_140 , V_271 ) ;
F_125 () ;
}
switch ( V_10 -> V_84 . Type . V_284 ) {
case V_287 :
V_426 = V_213 ;
break;
case V_285 :
V_426 = V_145 ;
break;
case V_289 :
V_426 = V_198 ;
break;
default:
V_426 = V_411 ;
}
F_92 ( V_8 -> V_15 , V_10 , V_407 , V_424 , V_426 ) ;
return;
}
static void T_14 * F_182 ( T_15 V_432 , T_15 V_424 )
{
T_15 V_433 = ( ( T_15 ) V_432 ) & V_434 ;
T_15 V_435 = ( ( T_15 ) V_432 ) - V_433 ;
void T_14 * V_436 = F_183 ( V_433 ,
V_435 + V_424 ) ;
return V_436 ? ( V_436 + V_435 ) : NULL ;
}
static void F_38 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
unsigned long V_49 ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
while ( ! F_41 ( & V_8 -> V_90 ) ) {
V_10 = F_184 ( V_8 -> V_90 . V_437 , struct V_9 , V_61 ) ;
if ( ( V_8 -> V_67 . V_438 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_141 ) ;
break;
}
F_39 ( V_10 ) ;
V_8 -> V_91 -- ;
F_25 ( & V_8 -> V_340 , V_10 ) ;
V_8 -> V_37 ++ ;
if ( V_8 -> V_37 > V_8 -> V_439 )
V_8 -> V_439 = V_8 -> V_37 ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
V_8 -> V_67 . V_440 ( V_8 , V_10 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
}
F_22 ( & V_8 -> V_50 , V_49 ) ;
}
static inline unsigned long F_185 ( struct V_1 * V_8 , T_4 V_62 )
{
return V_8 -> V_67 . V_68 ( V_8 , V_62 ) ;
}
static inline bool F_186 ( struct V_1 * V_8 )
{
return V_8 -> V_67 . V_441 ( V_8 ) ;
}
static inline long F_187 ( struct V_1 * V_8 )
{
return ( V_8 -> V_67 . V_441 ( V_8 ) == 0 ) ||
( V_8 -> V_442 == 0 ) ;
}
static inline int F_188 ( struct V_1 * V_8 , T_3 V_443 ,
T_3 V_444 )
{
if ( F_28 ( V_443 >= V_8 -> V_130 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_142 , V_444 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_157 ( struct V_9 * V_10 )
{
unsigned long V_49 ;
F_21 ( & V_10 -> V_8 -> V_50 , V_49 ) ;
F_39 ( V_10 ) ;
F_22 ( & V_10 -> V_8 -> V_50 , V_49 ) ;
F_35 ( V_10 -> V_8 , V_10 ) ;
if ( F_30 ( V_10 -> V_271 == V_272 ) )
F_86 ( V_10 ) ;
else if ( V_10 -> V_271 == V_410 )
F_189 ( V_10 -> V_201 ) ;
}
static inline T_3 F_190 ( T_3 V_332 )
{
return V_332 & V_276 ;
}
static inline T_3 F_191 ( T_3 V_332 )
{
return V_332 >> V_275 ;
}
static inline T_3 F_192 ( struct V_1 * V_8 , T_3 V_332 )
{
#define F_193 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_194 0x03
if ( F_28 ( ! ( V_8 -> V_38 & V_39 ) ) )
return V_332 & ~ F_194 ;
return V_332 & ~ F_193 ;
}
static inline void F_195 ( struct V_1 * V_8 ,
T_3 V_444 )
{
T_3 V_443 ;
struct V_9 * V_10 ;
V_443 = F_191 ( V_444 ) ;
if ( ! F_188 ( V_8 , V_443 , V_444 ) ) {
V_10 = V_8 -> V_356 + V_443 ;
F_157 ( V_10 ) ;
}
}
static inline void F_196 ( struct V_1 * V_8 ,
T_3 V_444 )
{
T_3 V_332 ;
struct V_9 * V_10 = NULL ;
unsigned long V_49 ;
V_332 = F_192 ( V_8 , V_444 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
F_152 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_74 & 0xFFFFFFE0 ) == ( V_332 & 0xFFFFFFE0 ) ) {
F_22 ( & V_8 -> V_50 , V_49 ) ;
F_157 ( V_10 ) ;
return;
}
}
F_22 ( & V_8 -> V_50 , V_49 ) ;
F_188 ( V_8 , V_8 -> V_130 + 1 , V_444 ) ;
}
static int F_197 ( struct V_1 * V_8 )
{
if ( F_30 ( ! V_445 ) )
return 0 ;
if ( F_30 ( V_8 -> V_442 ) )
return 0 ;
F_52 ( & V_8 -> V_15 -> V_16 , L_143
L_144 ) ;
return 1 ;
}
static struct V_1 * F_198 ( T_4 * V_446 )
{
return F_199 ( ( V_446 - * V_446 ) , struct V_1 , V_62 [ 0 ] ) ;
}
static T_16 F_200 ( int V_314 , void * V_446 )
{
struct V_1 * V_8 = F_198 ( V_446 ) ;
T_4 V_62 = * ( T_4 * ) V_446 ;
T_3 V_444 ;
if ( F_197 ( V_8 ) )
return V_447 ;
if ( F_187 ( V_8 ) )
return V_447 ;
V_8 -> V_448 = F_201 () ;
while ( F_186 ( V_8 ) ) {
V_444 = F_185 ( V_8 , V_62 ) ;
while ( V_444 != V_72 )
V_444 = F_27 ( V_8 , V_62 ) ;
}
return V_449 ;
}
static T_16 F_202 ( int V_314 , void * V_446 )
{
struct V_1 * V_8 = F_198 ( V_446 ) ;
T_3 V_444 ;
T_4 V_62 = * ( T_4 * ) V_446 ;
if ( F_197 ( V_8 ) )
return V_447 ;
V_8 -> V_448 = F_201 () ;
V_444 = F_185 ( V_8 , V_62 ) ;
while ( V_444 != V_72 )
V_444 = F_27 ( V_8 , V_62 ) ;
return V_449 ;
}
static T_16 F_203 ( int V_314 , void * V_446 )
{
struct V_1 * V_8 = F_198 ( ( T_4 * ) V_446 ) ;
T_3 V_444 ;
T_4 V_62 = * ( T_4 * ) V_446 ;
if ( F_187 ( V_8 ) )
return V_447 ;
V_8 -> V_448 = F_201 () ;
while ( F_186 ( V_8 ) ) {
V_444 = F_185 ( V_8 , V_62 ) ;
while ( V_444 != V_72 ) {
if ( F_30 ( F_190 ( V_444 ) ) )
F_195 ( V_8 , V_444 ) ;
else
F_196 ( V_8 , V_444 ) ;
V_444 = F_27 ( V_8 , V_62 ) ;
}
}
return V_449 ;
}
static T_16 F_204 ( int V_314 , void * V_446 )
{
struct V_1 * V_8 = F_198 ( V_446 ) ;
T_3 V_444 ;
T_4 V_62 = * ( T_4 * ) V_446 ;
V_8 -> V_448 = F_201 () ;
V_444 = F_185 ( V_8 , V_62 ) ;
while ( V_444 != V_72 ) {
if ( F_30 ( F_190 ( V_444 ) ) )
F_195 ( V_8 , V_444 ) ;
else
F_196 ( V_8 , V_444 ) ;
V_444 = F_27 ( V_8 , V_62 ) ;
}
return V_449 ;
}
static T_13 int F_205 ( struct V_192 * V_15 , unsigned char V_450 ,
unsigned char type )
{
struct V_451 {
struct V_452 V_453 ;
struct V_454 V_84 ;
struct V_455 V_456 ;
};
struct V_451 * V_154 ;
static const T_2 V_457 = sizeof( * V_154 ) +
sizeof( V_154 -> V_456 ) ;
V_196 V_458 ;
T_17 V_459 , V_332 ;
void T_14 * V_460 ;
int V_41 , V_367 ;
V_460 = F_206 ( V_15 , 0 ) ;
if ( V_460 == NULL )
return - V_132 ;
V_367 = F_207 ( V_15 , F_208 ( 32 ) ) ;
if ( V_367 ) {
F_209 ( V_460 ) ;
return - V_132 ;
}
V_154 = F_161 ( V_15 , V_457 , & V_458 ) ;
if ( V_154 == NULL ) {
F_209 ( V_460 ) ;
return - V_132 ;
}
V_459 = V_458 ;
V_154 -> V_453 . V_79 = 0 ;
V_154 -> V_453 . V_77 = 0 ;
V_154 -> V_453 . V_144 = 0 ;
V_154 -> V_453 . V_274 . V_147 = V_459 ;
V_154 -> V_453 . V_274 . V_148 = 0 ;
memset ( & V_154 -> V_453 . V_249 . V_273 , 0 , 8 ) ;
V_154 -> V_84 . V_279 = 16 ;
V_154 -> V_84 . Type . Type = V_215 ;
V_154 -> V_84 . Type . V_280 = V_461 ;
V_154 -> V_84 . Type . V_284 = V_289 ;
V_154 -> V_84 . V_277 = 0 ;
V_154 -> V_84 . V_85 [ 0 ] = V_450 ;
V_154 -> V_84 . V_85 [ 1 ] = type ;
memset ( & V_154 -> V_84 . V_85 [ 2 ] , 0 , 14 ) ;
V_154 -> V_456 . V_146 . V_147 = V_459 + sizeof( * V_154 ) ;
V_154 -> V_456 . V_146 . V_148 = 0 ;
V_154 -> V_456 . V_143 = sizeof( struct V_155 ) ;
F_210 ( V_459 , V_460 + V_462 ) ;
for ( V_41 = 0 ; V_41 < V_463 ; V_41 ++ ) {
V_332 = F_211 ( V_460 + V_464 ) ;
if ( ( V_332 & ~ F_194 ) == V_459 )
break;
F_98 ( V_465 ) ;
}
F_209 ( V_460 ) ;
if ( V_41 == V_463 ) {
F_51 ( & V_15 -> V_16 , L_145 ,
V_450 , type ) ;
return - V_466 ;
}
F_162 ( V_15 , V_457 , V_154 , V_458 ) ;
if ( V_332 & V_467 ) {
F_51 ( & V_15 -> V_16 , L_146 ,
V_450 , type ) ;
return - V_468 ;
}
F_52 ( & V_15 -> V_16 , L_147 ,
V_450 , type ) ;
return 0 ;
}
static int F_212 ( struct V_192 * V_15 ,
void * T_14 V_460 , T_3 V_469 )
{
V_199 V_470 ;
int V_471 ;
if ( V_469 ) {
F_52 ( & V_15 -> V_16 , L_148 ) ;
F_210 ( V_469 , V_460 + V_472 ) ;
} else {
V_471 = F_213 ( V_15 , V_473 ) ;
if ( V_471 == 0 ) {
F_51 ( & V_15 -> V_16 ,
L_149
L_150 ) ;
return - V_52 ;
}
F_52 ( & V_15 -> V_16 , L_151 ) ;
F_214 ( V_15 , V_471 + V_474 , & V_470 ) ;
V_470 &= ~ V_475 ;
V_470 |= V_476 ;
F_215 ( V_15 , V_471 + V_474 , V_470 ) ;
F_98 ( 500 ) ;
V_470 &= ~ V_475 ;
V_470 |= V_477 ;
F_215 ( V_15 , V_471 + V_474 , V_470 ) ;
F_98 ( 500 ) ;
}
return 0 ;
}
static T_13 void F_216 ( char * V_478 , int V_259 )
{
memset ( V_478 , 0 , V_259 ) ;
strncpy ( V_478 , V_17 L_152 V_405 , V_259 - 1 ) ;
}
static T_13 int F_217 (
struct V_479 T_14 * V_480 )
{
char * V_478 ;
int V_41 , V_424 = sizeof( V_480 -> V_478 ) ;
V_478 = F_81 ( V_424 , V_126 ) ;
if ( ! V_478 )
return - V_132 ;
F_216 ( V_478 , V_424 ) ;
for ( V_41 = 0 ; V_41 < V_424 ; V_41 ++ )
F_218 ( V_478 [ V_41 ] , & V_480 -> V_478 [ V_41 ] ) ;
F_59 ( V_478 ) ;
return 0 ;
}
static T_13 void F_219 (
struct V_479 T_14 * V_480 , unsigned char * V_481 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < sizeof( V_480 -> V_478 ) ; V_41 ++ )
V_481 [ V_41 ] = F_220 ( & V_480 -> V_478 [ V_41 ] ) ;
}
static T_13 int F_221 (
struct V_479 T_14 * V_480 )
{
char * V_481 , * V_482 ;
int V_209 , V_424 = sizeof( V_480 -> V_478 ) ;
V_482 = F_81 ( 2 * V_424 , V_126 ) ;
if ( ! V_482 )
return - V_132 ;
V_481 = V_482 + V_424 ;
F_216 ( V_482 , V_424 ) ;
F_219 ( V_480 , V_481 ) ;
V_209 = ! memcmp ( V_481 , V_482 , V_424 ) ;
F_59 ( V_482 ) ;
return V_209 ;
}
static T_13 int F_222 ( struct V_192 * V_15 )
{
T_5 V_483 ;
T_3 V_484 ;
T_5 V_485 ;
void T_14 * V_460 ;
unsigned long V_486 ;
T_3 V_487 ;
int V_209 ;
struct V_479 T_14 * V_480 ;
T_3 V_469 ;
T_3 V_40 ;
V_199 V_488 ;
V_209 = F_223 ( V_15 , & V_40 ) ;
if ( V_209 < 0 || ! F_16 ( V_40 ) ) {
F_5 ( & V_15 -> V_16 , L_153 ) ;
return - V_52 ;
}
if ( ! F_13 ( V_40 ) )
return - V_299 ;
F_214 ( V_15 , 4 , & V_488 ) ;
F_224 ( V_15 ) ;
F_225 ( V_15 ) ;
V_209 = F_226 ( V_15 , & V_486 ) ;
if ( V_209 )
return V_209 ;
V_460 = F_182 ( V_486 , 0x250 ) ;
if ( ! V_460 )
return - V_132 ;
V_209 = F_227 ( V_15 , V_460 , & V_484 ,
& V_485 , & V_483 ) ;
if ( V_209 )
goto V_489;
V_480 = F_182 ( F_228 ( V_15 ,
V_485 ) + V_483 , sizeof( * V_480 ) ) ;
if ( ! V_480 ) {
V_209 = - V_132 ;
goto V_489;
}
V_209 = F_217 ( V_480 ) ;
if ( V_209 )
goto V_489;
V_487 = F_211 ( & V_480 -> V_487 ) ;
V_469 = V_487 & V_490 ;
if ( V_469 ) {
V_469 = V_491 ;
} else {
V_469 = V_487 & V_492 ;
if ( V_469 ) {
F_5 ( & V_15 -> V_16 , L_154
L_155 ) ;
V_209 = - V_299 ;
goto V_493;
}
}
V_209 = F_212 ( V_15 , V_460 , V_469 ) ;
if ( V_209 )
goto V_493;
F_229 ( V_15 ) ;
V_209 = F_230 ( V_15 ) ;
if ( V_209 ) {
F_5 ( & V_15 -> V_16 , L_156 ) ;
goto V_493;
}
F_215 ( V_15 , 4 , V_488 ) ;
F_98 ( V_494 ) ;
F_52 ( & V_15 -> V_16 , L_157 ) ;
V_209 = F_231 ( V_15 , V_460 , V_495 ) ;
if ( V_209 ) {
F_5 ( & V_15 -> V_16 ,
L_158
L_159 ) ;
V_209 = - V_299 ;
goto V_493;
}
V_209 = F_231 ( V_15 , V_460 , V_496 ) ;
if ( V_209 ) {
F_5 ( & V_15 -> V_16 ,
L_160
L_161 ) ;
goto V_493;
}
V_209 = F_221 ( V_460 ) ;
if ( V_209 < 0 )
goto V_493;
if ( V_209 ) {
F_5 ( & V_15 -> V_16 , L_162
L_163 ) ;
V_209 = - V_299 ;
} else {
F_52 ( & V_15 -> V_16 , L_164 ) ;
}
V_493:
F_209 ( V_480 ) ;
V_489:
F_209 ( V_460 ) ;
return V_209 ;
}
static void F_232 ( struct V_28 * V_16 , struct V_479 * V_497 )
{
#ifdef F_233
int V_41 ;
char V_498 [ 17 ] ;
F_52 ( V_16 , L_165 ) ;
F_52 ( V_16 , L_166 ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ )
V_498 [ V_41 ] = F_220 ( & ( V_497 -> V_499 [ V_41 ] ) ) ;
V_498 [ 4 ] = '\0' ;
F_52 ( V_16 , L_167 , V_498 ) ;
F_52 ( V_16 , L_168 , F_211 ( & ( V_497 -> V_500 ) ) ) ;
F_52 ( V_16 , L_169 ,
F_211 ( & ( V_497 -> V_501 ) ) ) ;
F_52 ( V_16 , L_170 ,
F_211 ( & ( V_497 -> V_502 ) ) ) ;
F_52 ( V_16 , L_171 ,
F_211 ( & ( V_497 -> V_503 . V_504 ) ) ) ;
F_52 ( V_16 , L_172 ,
F_211 ( & ( V_497 -> V_503 . V_505 ) ) ) ;
F_52 ( V_16 , L_173 ,
F_211 ( & ( V_497 -> V_503 . V_506 ) ) ) ;
F_52 ( V_16 , L_174 ,
F_211 ( & ( V_497 -> V_507 ) ) ) ;
F_52 ( V_16 , L_175 , F_211 ( & ( V_497 -> V_508 ) ) ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
V_498 [ V_41 ] = F_220 ( & ( V_497 -> V_509 [ V_41 ] ) ) ;
V_498 [ 16 ] = '\0' ;
F_52 ( V_16 , L_176 , V_498 ) ;
F_52 ( V_16 , L_177 ,
F_211 ( & ( V_497 -> V_510 ) ) ) ;
#endif
}
static int F_234 ( struct V_192 * V_15 , unsigned long V_511 )
{
int V_41 , V_512 , V_513 , V_514 ;
if ( V_511 == V_515 )
return 0 ;
V_512 = 0 ;
for ( V_41 = 0 ; V_41 < V_516 ; V_41 ++ ) {
V_514 = F_235 ( V_15 , V_41 ) & V_517 ;
if ( V_514 == V_518 )
V_512 += 4 ;
else {
V_513 = F_235 ( V_15 , V_41 ) &
V_519 ;
switch ( V_513 ) {
case V_520 :
case V_521 :
V_512 += 4 ;
break;
case V_522 :
V_512 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_178 ) ;
return - 1 ;
break;
}
}
if ( V_512 == V_511 - V_515 )
return V_41 + 1 ;
}
return - 1 ;
}
static void T_13 F_236 ( struct V_1 * V_8 )
{
#ifdef F_237
int V_367 , V_41 ;
struct V_523 V_524 [ V_525 ] ;
for ( V_41 = 0 ; V_41 < V_525 ; V_41 ++ ) {
V_524 [ V_41 ] . V_526 = 0 ;
V_524 [ V_41 ] . V_109 = V_41 ;
}
if ( ( V_8 -> V_40 == 0x40700E11 ) || ( V_8 -> V_40 == 0x40800E11 ) ||
( V_8 -> V_40 == 0x40820E11 ) || ( V_8 -> V_40 == 0x40830E11 ) )
goto V_527;
if ( F_213 ( V_8 -> V_15 , V_528 ) ) {
F_52 ( & V_8 -> V_15 -> V_16 , L_179 ) ;
V_367 = F_238 ( V_8 -> V_15 , V_524 ,
V_525 ) ;
if ( ! V_367 ) {
for ( V_41 = 0 ; V_41 < V_525 ; V_41 ++ )
V_8 -> V_315 [ V_41 ] = V_524 [ V_41 ] . V_526 ;
V_8 -> V_78 = 1 ;
return;
}
if ( V_367 > 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_180
L_181 , V_367 ) ;
goto V_527;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_182 ,
V_367 ) ;
goto V_527;
}
}
if ( F_213 ( V_8 -> V_15 , V_529 ) ) {
F_52 ( & V_8 -> V_15 -> V_16 , L_183 ) ;
if ( ! F_239 ( V_8 -> V_15 ) )
V_8 -> V_530 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_184 ) ;
}
V_527:
#endif
V_8 -> V_315 [ V_8 -> V_316 ] = V_8 -> V_15 -> V_314 ;
}
static int T_13 F_223 ( struct V_192 * V_15 , T_3 * V_40 )
{
int V_41 ;
T_3 V_531 , V_532 ;
V_531 = V_15 -> V_533 ;
V_532 = V_15 -> V_534 ;
* V_40 = ( ( V_532 << 16 ) & 0xffff0000 ) |
V_531 ;
for ( V_41 = 0 ; V_41 < F_14 ( V_535 ) ; V_41 ++ )
if ( * V_40 == V_535 [ V_41 ] . V_40 )
return V_41 ;
if ( ( V_531 != V_536 &&
V_531 != V_537 ) ||
! V_538 ) {
F_5 ( & V_15 -> V_16 , L_185
L_186 , * V_40 ) ;
return - V_52 ;
}
return F_14 ( V_535 ) - 1 ;
}
static int T_13 F_226 ( struct V_192 * V_15 ,
unsigned long * V_539 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_516 ; V_41 ++ )
if ( F_235 ( V_15 , V_41 ) & V_540 ) {
* V_539 = F_228 ( V_15 , V_41 ) ;
F_90 ( & V_15 -> V_16 , L_187 ,
* V_539 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_188 ) ;
return - V_52 ;
}
static int T_13 F_231 ( struct V_192 * V_15 ,
void T_14 * V_460 , int V_541 )
{
int V_41 , V_542 ;
T_3 V_543 ;
if ( V_541 )
V_542 = V_544 ;
else
V_542 = V_545 ;
for ( V_41 = 0 ; V_41 < V_542 ; V_41 ++ ) {
V_543 = F_211 ( V_460 + V_546 ) ;
if ( V_541 ) {
if ( V_543 == V_547 )
return 0 ;
} else {
if ( V_543 != V_547 )
return 0 ;
}
F_98 ( V_548 ) ;
}
F_5 ( & V_15 -> V_16 , L_189 ) ;
return - V_52 ;
}
static int T_13 F_227 ( struct V_192 * V_15 ,
void T_14 * V_460 , T_3 * V_484 , T_5 * V_485 ,
T_5 * V_483 )
{
* V_484 = F_211 ( V_460 + V_549 ) ;
* V_483 = F_211 ( V_460 + V_550 ) ;
* V_484 &= ( T_3 ) 0x0000ffff ;
* V_485 = F_234 ( V_15 , * V_484 ) ;
if ( * V_485 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_190 ) ;
return - V_52 ;
}
return 0 ;
}
static int T_13 F_240 ( struct V_1 * V_8 )
{
T_5 V_483 ;
T_3 V_484 ;
T_5 V_485 ;
T_3 V_551 ;
int V_209 ;
V_209 = F_227 ( V_8 -> V_15 , V_8 -> V_460 , & V_484 ,
& V_485 , & V_483 ) ;
if ( V_209 )
return V_209 ;
V_8 -> V_480 = F_182 ( F_228 ( V_8 -> V_15 ,
V_485 ) + V_483 , sizeof( * V_8 -> V_480 ) ) ;
if ( ! V_8 -> V_480 )
return - V_132 ;
V_209 = F_217 ( V_8 -> V_480 ) ;
if ( V_209 )
return V_209 ;
V_551 = F_211 ( & V_8 -> V_480 -> V_552 ) ;
V_8 -> V_553 = F_182 ( F_228 ( V_8 -> V_15 ,
V_485 ) + V_483 + V_551 ,
sizeof( * V_8 -> V_553 ) ) ;
if ( ! V_8 -> V_553 )
return - V_132 ;
return 0 ;
}
static void T_13 F_241 ( struct V_1 * V_8 )
{
V_8 -> V_73 = F_211 ( & ( V_8 -> V_480 -> V_554 ) ) ;
if ( V_445 && V_8 -> V_73 > 32 )
V_8 -> V_73 = 32 ;
if ( V_8 -> V_73 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_191
L_192
L_193 ,
V_8 -> V_73 ) ;
V_8 -> V_73 = 16 ;
}
}
static void T_13 F_242 ( struct V_1 * V_8 )
{
F_241 ( V_8 ) ;
V_8 -> V_130 = V_8 -> V_73 - 4 ;
V_8 -> V_266 = F_211 ( & ( V_8 -> V_480 -> V_555 ) ) ;
V_8 -> V_139 = 31 ;
if ( V_8 -> V_266 > 512 ) {
V_8 -> V_139 = 32 ;
V_8 -> V_131 = V_8 -> V_266 - V_8 -> V_139 + 1 ;
V_8 -> V_266 -- ;
} else {
V_8 -> V_266 = 31 ;
V_8 -> V_131 = 0 ;
}
V_8 -> V_346 = F_211 ( & ( V_8 -> V_480 -> V_346 ) ) ;
}
static inline bool F_243 ( struct V_1 * V_8 )
{
if ( ! F_244 ( V_8 -> V_480 -> V_499 , L_194 , 4 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_195 ) ;
return false ;
}
return true ;
}
static inline void F_245 ( struct V_1 * V_8 )
{
#ifdef F_246
T_3 V_556 ;
V_556 = F_211 ( & ( V_8 -> V_480 -> V_557 ) ) ;
V_556 |= 0x100 ;
F_210 ( V_556 , & ( V_8 -> V_480 -> V_557 ) ) ;
#endif
}
static inline void F_247 ( struct V_1 * V_8 )
{
T_3 V_558 ;
if ( V_8 -> V_40 != 0x3225103C )
return;
V_558 = F_211 ( V_8 -> V_460 + V_559 ) ;
V_558 |= 0x8000 ;
F_210 ( V_558 , V_8 -> V_460 + V_559 ) ;
}
static void T_13 F_248 ( struct V_1 * V_8 )
{
int V_41 ;
T_3 V_560 ;
unsigned long V_49 ;
for ( V_41 = 0 ; V_41 < V_561 ; V_41 ++ ) {
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_560 = F_211 ( V_8 -> V_460 + V_472 ) ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
if ( ! ( V_560 & V_562 ) )
break;
F_249 ( 10000 , 20000 ) ;
}
}
static int T_13 F_250 ( struct V_1 * V_8 )
{
T_3 V_563 ;
V_563 = F_211 ( & ( V_8 -> V_480 -> V_501 ) ) ;
if ( ! ( V_563 & V_564 ) )
return - V_299 ;
V_8 -> V_73 = F_211 ( & ( V_8 -> V_480 -> V_507 ) ) ;
F_210 ( V_565 , & ( V_8 -> V_480 -> V_503 . V_504 ) ) ;
F_210 ( V_562 , V_8 -> V_460 + V_472 ) ;
F_248 ( V_8 ) ;
F_232 ( & V_8 -> V_15 -> V_16 , V_8 -> V_480 ) ;
if ( ! ( F_211 ( & ( V_8 -> V_480 -> V_502 ) ) & V_565 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_196 ) ;
return - V_52 ;
}
V_8 -> V_38 = V_565 ;
return 0 ;
}
static int T_13 F_251 ( struct V_1 * V_8 )
{
int V_566 , V_367 ;
V_566 = F_223 ( V_8 -> V_15 , & V_8 -> V_40 ) ;
if ( V_566 < 0 )
return - V_52 ;
V_8 -> V_567 = V_535 [ V_566 ] . V_567 ;
V_8 -> V_67 = * ( V_535 [ V_566 ] . V_67 ) ;
F_252 ( V_8 -> V_15 , V_568 |
V_569 | V_570 ) ;
V_367 = F_230 ( V_8 -> V_15 ) ;
if ( V_367 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_197 ) ;
return V_367 ;
}
F_253 ( V_8 -> V_15 ) ;
V_367 = F_254 ( V_8 -> V_15 , V_17 ) ;
if ( V_367 ) {
F_51 ( & V_8 -> V_15 -> V_16 ,
L_198 ) ;
return V_367 ;
}
F_236 ( V_8 ) ;
V_367 = F_226 ( V_8 -> V_15 , & V_8 -> V_486 ) ;
if ( V_367 )
goto V_571;
V_8 -> V_460 = F_182 ( V_8 -> V_486 , 0x250 ) ;
if ( ! V_8 -> V_460 ) {
V_367 = - V_132 ;
goto V_571;
}
V_367 = F_231 ( V_8 -> V_15 , V_8 -> V_460 , V_496 ) ;
if ( V_367 )
goto V_571;
V_367 = F_240 ( V_8 ) ;
if ( V_367 )
goto V_571;
F_242 ( V_8 ) ;
if ( ! F_243 ( V_8 ) ) {
V_367 = - V_52 ;
goto V_571;
}
F_245 ( V_8 ) ;
F_247 ( V_8 ) ;
V_367 = F_250 ( V_8 ) ;
if ( V_367 )
goto V_571;
return 0 ;
V_571:
if ( V_8 -> V_553 )
F_209 ( V_8 -> V_553 ) ;
if ( V_8 -> V_480 )
F_209 ( V_8 -> V_480 ) ;
if ( V_8 -> V_460 )
F_209 ( V_8 -> V_460 ) ;
F_224 ( V_8 -> V_15 ) ;
F_255 ( V_8 -> V_15 ) ;
return V_367 ;
}
static void T_13 F_256 ( struct V_1 * V_8 )
{
int V_209 ;
#define F_257 64
V_8 -> V_36 = F_81 ( F_257 , V_126 ) ;
if ( ! V_8 -> V_36 )
return;
V_209 = F_100 ( V_8 , V_92 , 0 ,
V_8 -> V_36 , F_257 ) ;
if ( V_209 != 0 ) {
F_59 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
}
}
static T_13 int F_258 ( struct V_192 * V_15 )
{
int V_209 , V_41 ;
if ( ! V_445 )
return 0 ;
V_209 = F_222 ( V_15 ) ;
if ( V_209 == - V_299 )
return V_209 ;
if ( V_209 )
return - V_52 ;
F_5 ( & V_15 -> V_16 , L_199 ) ;
for ( V_41 = 0 ; V_41 < V_572 ; V_41 ++ ) {
if ( F_259 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_200 ,
( V_41 < 11 ? L_201 : L_202 ) ) ;
}
return 0 ;
}
static T_13 int F_260 ( struct V_1 * V_8 )
{
V_8 -> V_353 = F_69 (
F_261 ( V_8 -> V_130 , V_354 ) *
sizeof( unsigned long ) , V_126 ) ;
V_8 -> V_356 = F_161 ( V_8 -> V_15 ,
V_8 -> V_130 * sizeof( * V_8 -> V_356 ) ,
& ( V_8 -> V_357 ) ) ;
V_8 -> V_358 = F_161 ( V_8 -> V_15 ,
V_8 -> V_130 * sizeof( * V_8 -> V_358 ) ,
& ( V_8 -> V_359 ) ) ;
if ( ( V_8 -> V_353 == NULL )
|| ( V_8 -> V_356 == NULL )
|| ( V_8 -> V_358 == NULL ) ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_203 , V_319 ) ;
return - V_132 ;
}
return 0 ;
}
static void F_262 ( struct V_1 * V_8 )
{
F_59 ( V_8 -> V_353 ) ;
if ( V_8 -> V_356 )
F_162 ( V_8 -> V_15 ,
V_8 -> V_130 * sizeof( struct V_9 ) ,
V_8 -> V_356 , V_8 -> V_357 ) ;
if ( V_8 -> V_358 )
F_162 ( V_8 -> V_15 ,
V_8 -> V_130 * sizeof( struct V_155 ) ,
V_8 -> V_358 ,
V_8 -> V_359 ) ;
}
static int F_263 ( struct V_1 * V_8 ,
T_16 (* F_264)( int , void * ) ,
T_16 (* F_265)( int , void * ) )
{
int V_209 , V_41 ;
for ( V_41 = 0 ; V_41 < V_525 ; V_41 ++ )
V_8 -> V_62 [ V_41 ] = ( T_4 ) V_41 ;
if ( V_8 -> V_316 == V_573 && V_8 -> V_78 ) {
for ( V_41 = 0 ; V_41 < V_525 ; V_41 ++ )
V_209 = F_266 ( V_8 -> V_315 [ V_41 ] , F_264 ,
0 , V_8 -> V_574 ,
& V_8 -> V_62 [ V_41 ] ) ;
} else {
if ( V_8 -> V_78 || V_8 -> V_530 ) {
V_209 = F_266 ( V_8 -> V_315 [ V_8 -> V_316 ] ,
F_264 , 0 , V_8 -> V_574 ,
& V_8 -> V_62 [ V_8 -> V_316 ] ) ;
} else {
V_209 = F_266 ( V_8 -> V_315 [ V_8 -> V_316 ] ,
F_265 , V_575 , V_8 -> V_574 ,
& V_8 -> V_62 [ V_8 -> V_316 ] ) ;
}
}
if ( V_209 ) {
F_51 ( & V_8 -> V_15 -> V_16 , L_204 ,
V_8 -> V_315 [ V_8 -> V_316 ] , V_8 -> V_574 ) ;
return - V_52 ;
}
return 0 ;
}
static int T_13 F_267 ( struct V_1 * V_8 )
{
if ( F_181 ( V_8 , V_92 ,
V_576 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_205 ) ;
return - V_468 ;
}
F_52 ( & V_8 -> V_15 -> V_16 , L_206 ) ;
if ( F_231 ( V_8 -> V_15 , V_8 -> V_460 , V_495 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_207 ) ;
return - 1 ;
}
F_52 ( & V_8 -> V_15 -> V_16 , L_208 ) ;
if ( F_231 ( V_8 -> V_15 , V_8 -> V_460 , V_496 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_209
L_210 ) ;
return - 1 ;
}
return 0 ;
}
static void F_268 ( struct V_1 * V_8 )
{
int V_41 ;
if ( ! V_8 -> V_78 || V_8 -> V_316 != V_573 ) {
V_41 = V_8 -> V_316 ;
F_269 ( V_8 -> V_315 [ V_41 ] , & V_8 -> V_62 [ V_41 ] ) ;
return;
}
for ( V_41 = 0 ; V_41 < V_525 ; V_41 ++ )
F_269 ( V_8 -> V_315 [ V_41 ] , & V_8 -> V_62 [ V_41 ] ) ;
}
static void F_270 ( struct V_1 * V_8 )
{
F_268 ( V_8 ) ;
#ifdef F_237
if ( V_8 -> V_78 ) {
if ( V_8 -> V_15 -> V_577 )
F_271 ( V_8 -> V_15 ) ;
} else if ( V_8 -> V_530 ) {
if ( V_8 -> V_15 -> V_578 )
F_272 ( V_8 -> V_15 ) ;
}
#endif
}
static void F_273 ( struct V_1 * V_8 )
{
F_270 ( V_8 ) ;
F_79 ( V_8 ) ;
F_262 ( V_8 ) ;
F_59 ( V_8 -> V_75 ) ;
F_162 ( V_8 -> V_15 , V_8 -> V_579 ,
V_8 -> V_64 , V_8 -> V_580 ) ;
if ( V_8 -> V_460 )
F_209 ( V_8 -> V_460 ) ;
if ( V_8 -> V_553 )
F_209 ( V_8 -> V_553 ) ;
if ( V_8 -> V_480 )
F_209 ( V_8 -> V_480 ) ;
F_255 ( V_8 -> V_15 ) ;
F_59 ( V_8 ) ;
}
static void F_274 ( struct V_1 * V_8 )
{
F_275 ( & V_581 ) ;
if ( ! V_582 )
return;
if ( V_8 -> V_202 )
return;
F_276 ( & V_8 -> V_583 ) ;
}
static void F_277 ( struct V_1 * V_8 , struct V_60 * V_61 )
{
struct V_9 * V_10 = NULL ;
F_275 ( & V_8 -> V_50 ) ;
while ( ! F_41 ( V_61 ) ) {
V_10 = F_184 ( V_61 -> V_437 , struct V_9 , V_61 ) ;
V_10 -> V_11 -> V_23 = V_183 ;
F_157 ( V_10 ) ;
}
}
static void F_278 ( struct V_1 * V_8 )
{
unsigned long V_49 ;
F_275 ( & V_581 ) ;
F_274 ( V_8 ) ;
V_8 -> V_67 . V_584 ( V_8 , V_585 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_8 -> V_202 = F_211 ( V_8 -> V_460 + V_546 ) ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_211 ,
V_8 -> V_202 ) ;
F_224 ( V_8 -> V_15 ) ;
F_21 ( & V_8 -> V_50 , V_49 ) ;
F_277 ( V_8 , & V_8 -> V_340 ) ;
F_277 ( V_8 , & V_8 -> V_90 ) ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
}
static void F_279 ( struct V_1 * V_8 )
{
T_5 V_586 ;
T_3 V_587 ;
unsigned long V_49 ;
F_275 ( & V_581 ) ;
V_586 = F_201 () ;
if ( F_280 ( V_8 -> V_448 +
( V_8 -> V_87 ) , V_586 ) )
return;
if ( F_280 ( V_8 -> V_588 +
( V_8 -> V_87 ) , V_586 ) )
return;
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_587 = F_211 ( & V_8 -> V_480 -> V_510 ) ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
if ( V_8 -> V_589 == V_587 ) {
F_278 ( V_8 ) ;
return;
}
V_8 -> V_589 = V_587 ;
V_8 -> V_588 = V_586 ;
}
static int F_281 ( void * V_590 )
{
struct V_1 * V_8 ;
unsigned long V_49 ;
while ( 1 ) {
struct V_60 * V_591 , * V_592 ;
F_282 ( V_89 ) ;
if ( F_283 () )
break;
F_21 ( & V_581 , V_49 ) ;
F_284 (this, tmp, &hpsa_ctlr_list) {
V_8 = F_184 ( V_591 , struct V_1 , V_583 ) ;
F_279 ( V_8 ) ;
}
F_22 ( & V_581 , V_49 ) ;
}
return 0 ;
}
static void F_285 ( struct V_1 * V_8 )
{
unsigned long V_49 ;
V_8 -> V_87 = V_89 ;
F_21 ( & V_581 , V_49 ) ;
F_26 ( & V_8 -> V_583 , & V_593 ) ;
F_22 ( & V_581 , V_49 ) ;
}
static void F_286 ( struct V_1 * V_8 )
{
if ( ! V_582 ) {
F_287 ( & V_581 ) ;
V_582 =
F_288 ( F_281 ,
NULL , V_17 ) ;
}
if ( ! V_582 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_212 ) ;
return;
}
F_285 ( V_8 ) ;
}
static void F_289 ( struct V_1 * V_8 )
{
unsigned long V_49 ;
F_21 ( & V_581 , V_49 ) ;
F_274 ( V_8 ) ;
if ( F_41 ( & V_593 ) ) {
F_22 ( & V_581 , V_49 ) ;
F_290 ( V_582 ) ;
F_21 ( & V_581 , V_49 ) ;
V_582 = NULL ;
}
F_22 ( & V_581 , V_49 ) ;
}
static int T_13 F_291 ( struct V_192 * V_15 ,
const struct V_594 * V_595 )
{
int V_596 , V_209 ;
struct V_1 * V_8 ;
int V_597 = 0 ;
unsigned long V_49 ;
if ( V_598 == 0 )
F_292 (KERN_INFO DRIVER_NAME L_213 ) ;
V_209 = F_258 ( V_15 ) ;
if ( V_209 ) {
if ( V_209 != - V_299 )
return V_209 ;
V_597 = 1 ;
V_209 = 0 ;
}
V_599:
#define F_293 32
F_294 ( sizeof( struct V_9 ) % F_293 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_126 ) ;
if ( ! V_8 )
return - V_132 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_316 = V_600 ? V_601 : V_573 ;
F_160 ( & V_8 -> V_340 ) ;
F_160 ( & V_8 -> V_90 ) ;
F_287 ( & V_8 -> V_50 ) ;
F_287 ( & V_8 -> V_294 ) ;
V_209 = F_251 ( V_8 ) ;
if ( V_209 != 0 )
goto V_602;
sprintf ( V_8 -> V_574 , V_17 L_214 , V_598 ) ;
V_8 -> V_18 = V_598 ;
V_598 ++ ;
V_209 = F_295 ( V_15 , F_208 ( 64 ) ) ;
if ( V_209 == 0 ) {
V_596 = 1 ;
} else {
V_209 = F_295 ( V_15 , F_208 ( 32 ) ) ;
if ( V_209 == 0 ) {
V_596 = 0 ;
} else {
F_51 ( & V_15 -> V_16 , L_215 ) ;
goto V_602;
}
}
V_8 -> V_67 . V_584 ( V_8 , V_585 ) ;
if ( F_263 ( V_8 , F_204 , F_203 ) )
goto V_603;
F_52 ( & V_15 -> V_16 , L_216 ,
V_8 -> V_574 , V_15 -> V_28 ,
V_8 -> V_315 [ V_8 -> V_316 ] , V_596 ? L_202 : L_217 ) ;
if ( F_260 ( V_8 ) )
goto V_604;
if ( F_80 ( V_8 ) )
goto V_604;
F_296 ( & V_8 -> V_605 ) ;
V_8 -> V_295 = 1 ;
F_297 ( V_15 , V_8 ) ;
V_8 -> V_99 = 0 ;
V_8 -> V_34 = NULL ;
F_287 ( & V_8 -> V_128 ) ;
F_298 ( V_8 ) ;
if ( V_597 ) {
F_21 ( & V_8 -> V_50 , V_49 ) ;
V_8 -> V_67 . V_584 ( V_8 , V_585 ) ;
F_22 ( & V_8 -> V_50 , V_49 ) ;
F_268 ( V_8 ) ;
V_209 = F_263 ( V_8 , F_202 ,
F_200 ) ;
if ( V_209 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_218
L_219 ) ;
goto V_604;
}
V_209 = F_267 ( V_8 ) ;
if ( V_209 )
goto V_604;
F_52 ( & V_8 -> V_15 -> V_16 , L_220 ) ;
F_52 ( & V_8 -> V_15 -> V_16 ,
L_221 ) ;
V_8 -> V_67 . V_584 ( V_8 , V_606 ) ;
F_98 ( 10000 ) ;
V_8 -> V_67 . V_584 ( V_8 , V_585 ) ;
V_209 = F_221 ( V_8 -> V_480 ) ;
if ( V_209 )
F_52 ( & V_8 -> V_15 -> V_16 ,
L_222 ) ;
F_273 ( V_8 ) ;
V_597 = 0 ;
if ( V_209 )
return - V_52 ;
goto V_599;
}
V_8 -> V_67 . V_584 ( V_8 , V_606 ) ;
F_256 ( V_8 ) ;
F_143 ( V_8 ) ;
F_286 ( V_8 ) ;
return 1 ;
V_604:
F_79 ( V_8 ) ;
F_262 ( V_8 ) ;
F_268 ( V_8 ) ;
V_603:
V_602:
F_59 ( V_8 ) ;
return V_209 ;
}
static void F_299 ( struct V_1 * V_8 )
{
char * V_607 ;
struct V_9 * V_10 ;
V_607 = F_69 ( 4 , V_126 ) ;
if ( ! V_607 )
return;
V_10 = F_101 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_87 ) ;
goto V_608;
}
F_102 ( V_10 , V_427 , V_8 , V_607 , 4 , 0 ,
V_92 , V_212 ) ;
F_97 ( V_8 , V_10 , V_145 ) ;
if ( V_10 -> V_11 -> V_23 != 0 )
F_5 ( & V_8 -> V_15 -> V_16 ,
L_223 ) ;
F_103 ( V_8 , V_10 ) ;
V_608:
F_59 ( V_607 ) ;
}
static void F_300 ( struct V_192 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_301 ( V_15 ) ;
F_299 ( V_8 ) ;
V_8 -> V_67 . V_584 ( V_8 , V_585 ) ;
F_270 ( V_8 ) ;
}
static void T_18 F_302 ( struct V_1 * V_8 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_8 -> V_99 ; V_41 ++ )
F_59 ( V_8 -> V_16 [ V_41 ] ) ;
}
static void T_18 F_303 ( struct V_192 * V_15 )
{
struct V_1 * V_8 ;
if ( F_301 ( V_15 ) == NULL ) {
F_51 ( & V_15 -> V_16 , L_224 ) ;
return;
}
V_8 = F_301 ( V_15 ) ;
F_289 ( V_8 ) ;
F_140 ( V_8 ) ;
F_300 ( V_15 ) ;
F_209 ( V_8 -> V_460 ) ;
F_209 ( V_8 -> V_553 ) ;
F_209 ( V_8 -> V_480 ) ;
F_302 ( V_8 ) ;
F_79 ( V_8 ) ;
F_162 ( V_8 -> V_15 ,
V_8 -> V_130 * sizeof( struct V_9 ) ,
V_8 -> V_356 , V_8 -> V_357 ) ;
F_162 ( V_8 -> V_15 ,
V_8 -> V_130 * sizeof( struct V_155 ) ,
V_8 -> V_358 , V_8 -> V_359 ) ;
F_162 ( V_8 -> V_15 , V_8 -> V_579 ,
V_8 -> V_64 , V_8 -> V_580 ) ;
F_59 ( V_8 -> V_353 ) ;
F_59 ( V_8 -> V_75 ) ;
F_59 ( V_8 -> V_36 ) ;
F_224 ( V_15 ) ;
F_255 ( V_15 ) ;
F_297 ( V_15 , NULL ) ;
F_59 ( V_8 ) ;
}
static void F_304 ( int V_609 [] , int V_610 ,
int V_611 , int * V_612 )
{
int V_41 , V_113 , V_613 , V_424 ;
#define F_305 4
#define F_306 8
for ( V_41 = 0 ; V_41 <= V_611 ; V_41 ++ ) {
V_424 = V_41 + F_305 ;
V_613 = V_610 ;
for ( V_113 = 0 ; V_113 < 8 ; V_113 ++ ) {
if ( V_609 [ V_113 ] >= V_424 ) {
V_613 = V_113 ;
break;
}
}
V_612 [ V_41 ] = V_613 ;
}
}
static T_13 void F_307 ( struct V_1 * V_8 ,
T_3 V_614 )
{
int V_41 ;
unsigned long V_615 ;
int V_616 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_420 + 4 } ;
F_294 ( 28 > V_420 + 4 ) ;
memset ( V_8 -> V_64 , 0 , V_8 -> V_579 ) ;
V_616 [ 7 ] = V_420 + 4 ;
F_304 ( V_616 , F_14 ( V_616 ) ,
V_420 , V_8 -> V_75 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
F_210 ( V_616 [ V_41 ] , & V_8 -> V_553 -> V_617 [ V_41 ] ) ;
F_210 ( V_8 -> V_73 , & V_8 -> V_553 -> V_618 ) ;
F_210 ( V_8 -> V_80 , & V_8 -> V_553 -> V_619 ) ;
F_210 ( 0 , & V_8 -> V_553 -> V_620 ) ;
F_210 ( 0 , & V_8 -> V_553 -> V_621 ) ;
for ( V_41 = 0 ; V_41 < V_8 -> V_80 ; V_41 ++ ) {
F_210 ( 0 , & V_8 -> V_553 -> V_622 [ V_41 ] . V_148 ) ;
F_210 ( V_8 -> V_580 +
( V_8 -> V_73 * sizeof( T_5 ) * V_41 ) ,
& V_8 -> V_553 -> V_622 [ V_41 ] . V_147 ) ;
}
F_210 ( V_39 | V_614 |
V_623 ,
& ( V_8 -> V_480 -> V_503 . V_504 ) ) ;
F_210 ( V_562 , V_8 -> V_460 + V_472 ) ;
F_248 ( V_8 ) ;
V_615 = F_211 ( & ( V_8 -> V_480 -> V_502 ) ) ;
if ( ! ( V_615 & V_39 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_225
L_226 ) ;
return;
}
V_8 -> V_67 = V_624 ;
V_8 -> V_38 = V_39 ;
}
static T_13 void F_298 ( struct V_1 * V_8 )
{
T_3 V_563 ;
int V_41 ;
if ( V_600 )
return;
V_563 = F_211 ( & ( V_8 -> V_480 -> V_501 ) ) ;
if ( ! ( V_563 & V_625 ) )
return;
V_8 -> V_80 = V_8 -> V_78 ? V_525 : 1 ;
F_241 ( V_8 ) ;
V_8 -> V_579 = V_8 -> V_73 * sizeof( T_5 ) * V_8 -> V_80 ;
V_8 -> V_64 = F_161 ( V_8 -> V_15 , V_8 -> V_579 ,
& ( V_8 -> V_580 ) ) ;
for ( V_41 = 0 ; V_41 < V_8 -> V_80 ; V_41 ++ ) {
V_8 -> V_66 [ V_41 ] . V_69 = & V_8 -> V_64 [ V_8 -> V_73 * V_41 ] ;
V_8 -> V_66 [ V_41 ] . V_424 = V_8 -> V_73 ;
V_8 -> V_66 [ V_41 ] . V_71 = 1 ;
V_8 -> V_66 [ V_41 ] . V_70 = 0 ;
}
V_8 -> V_75 = F_81 ( ( ( V_420 + 1 ) *
sizeof( T_3 ) ) , V_126 ) ;
if ( ( V_8 -> V_64 == NULL )
|| ( V_8 -> V_75 == NULL ) )
goto V_626;
F_307 ( V_8 ,
V_563 & V_627 ) ;
return;
V_626:
if ( V_8 -> V_64 )
F_162 ( V_8 -> V_15 , V_8 -> V_579 ,
V_8 -> V_64 , V_8 -> V_580 ) ;
F_59 ( V_8 -> V_75 ) ;
}
static int T_19 F_308 ( void )
{
return F_309 ( & V_628 ) ;
}
static void T_20 F_310 ( void )
{
F_311 ( & V_628 ) ;
}
