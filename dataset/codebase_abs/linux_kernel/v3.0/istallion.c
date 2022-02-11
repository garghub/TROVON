static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
struct V_6 * V_7 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
V_4 = V_2 -> V_9 [ V_5 ] ;
if ( V_4 != NULL ) {
V_7 = F_2 ( & V_4 -> V_10 ) ;
if ( V_7 != NULL ) {
F_3 ( V_7 ) ;
F_4 ( V_7 ) ;
}
F_5 ( V_4 ) ;
}
}
}
static int F_6 ( struct V_11 * V_12 , char * * V_13 )
{
unsigned int V_14 ;
char * V_15 ;
if ( V_13 [ 0 ] == NULL || * V_13 [ 0 ] == 0 )
return 0 ;
for ( V_15 = V_13 [ 0 ] , V_14 = 0 ; ( ( * V_15 != 0 ) && ( V_14 < 25 ) ) ; V_15 ++ , V_14 ++ )
* V_15 = tolower ( * V_15 ) ;
for ( V_14 = 0 ; V_14 < F_7 ( V_16 ) ; V_14 ++ ) {
if ( strcmp ( V_16 [ V_14 ] . V_17 , V_13 [ 0 ] ) == 0 )
break;
}
if ( V_14 == F_7 ( V_16 ) ) {
F_8 ( V_18 L_1 , V_13 [ 0 ] ) ;
return 0 ;
}
V_12 -> V_19 = V_16 [ V_14 ] . type ;
if ( V_13 [ 1 ] != NULL && * V_13 [ 1 ] != 0 )
V_12 -> V_20 = F_9 ( V_13 [ 1 ] , NULL , 0 ) ;
if ( V_13 [ 2 ] != NULL && * V_13 [ 2 ] != 0 )
V_12 -> V_21 = F_9 ( V_13 [ 2 ] , NULL , 0 ) ;
return ( 1 ) ;
}
static int F_10 ( struct V_22 * V_10 , struct V_6 * V_7 )
{
struct V_3 * V_4 = F_11 ( V_10 , struct V_3 , V_10 ) ;
struct V_1 * V_2 = V_23 [ V_4 -> V_24 ] ;
int V_25 ;
if ( ( V_25 = F_12 ( V_7 , V_2 , V_4 ) ) >= 0 )
F_13 ( V_26 , & V_7 -> V_27 ) ;
F_14 ( & V_4 -> V_28 ) ;
return V_25 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned int V_31 , V_24 , V_32 ;
V_31 = V_7 -> V_33 ;
V_24 = F_16 ( V_31 ) ;
if ( V_24 >= V_34 )
return - V_35 ;
V_2 = V_23 [ V_24 ] ;
if ( V_2 == NULL )
return - V_35 ;
if ( ! F_17 ( V_36 , & V_2 -> V_37 ) )
return - V_35 ;
V_32 = F_18 ( V_31 ) ;
if ( V_32 > V_2 -> V_38 )
return - V_35 ;
V_4 = V_2 -> V_9 [ V_32 ] ;
if ( V_4 == NULL )
return - V_35 ;
if ( V_4 -> V_39 < 1 )
return - V_35 ;
V_7 -> V_40 = V_4 ;
return F_19 ( & V_4 -> V_10 , V_7 , V_30 ) ;
}
static void F_20 ( struct V_22 * V_10 )
{
struct V_1 * V_2 ;
unsigned long V_41 ;
unsigned long V_27 ;
struct V_3 * V_4 = F_11 ( V_10 , struct V_3 , V_10 ) ;
if ( V_4 -> V_24 >= V_34 )
return;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return;
if ( ! F_17 ( V_42 , & V_4 -> V_37 ) )
F_21 ( V_2 , V_4 , 0 , 0 ) ;
F_22 ( & V_43 , V_27 ) ;
F_13 ( V_44 , & V_4 -> V_37 ) ;
F_13 ( V_45 , & V_4 -> V_37 ) ;
F_23 ( & V_43 , V_27 ) ;
V_41 = V_46 | V_47 ;
F_24 ( V_2 , V_4 , V_48 , & V_41 , sizeof( V_49 ) , 0 ) ;
}
static void F_25 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_3 * V_4 = V_7 -> V_40 ;
unsigned long V_27 ;
if ( V_4 == NULL )
return;
F_22 ( & V_43 , V_27 ) ;
if ( V_7 == V_50 )
F_26 ( V_7 ) ;
F_23 ( & V_43 , V_27 ) ;
F_27 ( & V_4 -> V_10 , V_7 , V_30 ) ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_51 ;
T_2 V_52 ;
int V_25 ;
if ( ( V_25 = F_28 ( V_2 , V_4 , 0 , 1 ) ) < 0 )
return V_25 ;
memset ( & V_51 , 0 , sizeof( T_1 ) ) ;
V_51 . V_53 = ( V_54 | V_55 | V_56 | V_57 ) ;
V_51 . signal = V_58 ;
if ( ( V_25 = F_24 ( V_2 , V_4 , V_59 , & V_51 ,
sizeof( T_1 ) , 0 ) ) < 0 )
return V_25 ;
F_29 ( V_7 , V_4 , & V_52 , V_7 -> V_60 ) ;
if ( ( V_25 = F_24 ( V_2 , V_4 , V_61 , & V_52 ,
sizeof( T_2 ) , 0 ) ) < 0 )
return V_25 ;
F_30 ( V_62 , & V_4 -> V_37 ) ;
if ( ( V_25 = F_24 ( V_2 , V_4 , V_63 , & V_4 -> V_64 ,
sizeof( V_65 ) , 1 ) ) < 0 )
return V_25 ;
if ( F_31 ( V_62 , & V_4 -> V_37 ) )
V_4 -> V_66 = F_32 ( V_4 -> V_64 . V_67 ) ;
F_33 ( & V_4 -> V_64 , 1 , 1 ) ;
if ( ( V_25 = F_24 ( V_2 , V_4 , V_68 , & V_4 -> V_64 ,
sizeof( V_65 ) , 0 ) ) < 0 )
return V_25 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned long V_69 , int V_70 )
{
T_3 T_4 * V_71 ;
T_5 T_4 * V_72 ;
unsigned char T_4 * V_73 ;
unsigned long V_27 ;
int V_25 ;
F_34 ( V_4 -> V_28 ,
! F_17 ( V_42 , & V_4 -> V_37 ) ) ;
if ( F_35 ( V_74 ) ) {
return - V_75 ;
}
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_72 = & ( ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ) -> V_79 ;
F_38 ( V_69 , & V_72 -> V_80 ) ;
F_39 ( 1 , & V_72 -> V_81 ) ;
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
V_73 = ( ( unsigned char T_4 * ) V_71 ) + V_2 -> V_83 +
V_4 -> V_84 ;
F_39 ( F_40 ( V_73 ) | V_4 -> V_85 , V_73 ) ;
F_41 ( V_2 ) ;
if ( V_70 == 0 ) {
F_23 ( & V_76 , V_27 ) ;
return 0 ;
}
V_25 = 0 ;
F_30 ( V_86 , & V_4 -> V_37 ) ;
F_23 ( & V_76 , V_27 ) ;
F_34 ( V_4 -> V_28 ,
! F_17 ( V_86 , & V_4 -> V_37 ) ) ;
if ( F_35 ( V_74 ) )
V_25 = - V_75 ;
if ( ( V_25 == 0 ) && ( V_4 -> V_25 != 0 ) )
V_25 = - V_87 ;
return V_25 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned long V_69 , int V_70 )
{
T_3 T_4 * V_71 ;
T_5 T_4 * V_72 ;
unsigned char T_4 * V_73 ;
unsigned long V_27 ;
int V_25 ;
if ( V_70 ) {
F_34 ( V_4 -> V_28 ,
! F_17 ( V_42 , & V_4 -> V_37 ) ) ;
if ( F_35 ( V_74 ) ) {
return - V_75 ;
}
}
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_72 = & ( ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ) -> V_79 ;
F_38 ( V_69 , & V_72 -> V_88 ) ;
F_39 ( 1 , & V_72 -> V_89 ) ;
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
V_73 = ( ( unsigned char T_4 * ) V_71 ) + V_2 -> V_83 +
V_4 -> V_84 ;
F_39 ( F_40 ( V_73 ) | V_4 -> V_85 , V_73 ) ;
F_41 ( V_2 ) ;
F_30 ( V_42 , & V_4 -> V_37 ) ;
F_23 ( & V_76 , V_27 ) ;
if ( V_70 == 0 )
return 0 ;
V_25 = 0 ;
F_34 ( V_4 -> V_28 ,
! F_17 ( V_42 , & V_4 -> V_37 ) ) ;
if ( F_35 ( V_74 ) )
V_25 = - V_75 ;
if ( ( V_25 == 0 ) && ( V_4 -> V_25 != 0 ) )
V_25 = - V_87 ;
return V_25 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned long V_90 , void * V_69 , int V_91 , int V_92 )
{
F_42 ( V_4 -> V_28 ,
! F_17 ( V_93 , & V_4 -> V_37 ) ) ;
if ( F_35 ( V_74 ) )
return - V_75 ;
F_43 ( V_2 , V_4 , V_90 , V_69 , V_91 , V_92 ) ;
F_42 ( V_4 -> V_28 ,
! F_17 ( V_93 , & V_4 -> V_37 ) ) ;
if ( F_35 ( V_74 ) )
return - V_75 ;
if ( V_4 -> V_25 != 0 )
return - V_87 ;
return 0 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_40 ;
struct V_1 * V_2 ;
T_2 V_52 ;
if ( V_4 == NULL )
return - V_35 ;
if ( V_4 -> V_24 >= V_34 )
return - V_35 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return - V_35 ;
F_29 ( V_7 , V_4 , & V_52 , V_7 -> V_60 ) ;
return ( F_24 ( V_2 , V_4 , V_61 , & V_52 , sizeof( T_2 ) , 0 ) ) ;
}
static int F_45 ( struct V_22 * V_10 )
{
struct V_3 * V_4 = F_11 ( V_10 , struct V_3 , V_10 ) ;
return ( V_4 -> V_66 & V_94 ) ? 1 : 0 ;
}
static void F_46 ( struct V_22 * V_10 , int V_95 )
{
struct V_3 * V_4 = F_11 ( V_10 , struct V_3 , V_10 ) ;
struct V_1 * V_2 = V_23 [ V_4 -> V_24 ] ;
F_33 ( & V_4 -> V_64 , V_95 , V_95 ) ;
if ( F_24 ( V_2 , V_4 , V_68 , & V_4 -> V_64 ,
sizeof( V_65 ) , 0 ) < 0 )
F_8 ( V_18 L_2 ) ;
}
static int F_47 ( struct V_6 * V_7 , const unsigned char * V_96 , int V_97 )
{
V_77 T_4 * V_98 ;
T_3 T_4 * V_71 ;
unsigned char T_4 * V_73 ;
unsigned char T_4 * V_99 ;
unsigned char * V_100 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_101 , V_102 , V_103 , V_104 , V_91 ;
unsigned long V_27 ;
if ( V_7 == V_50 )
F_26 ( V_7 ) ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_24 >= V_34 )
return 0 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return 0 ;
V_100 = ( unsigned char * ) V_96 ;
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_98 = ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ;
V_103 = ( unsigned int ) F_48 ( & V_98 -> V_105 . V_103 ) ;
V_104 = ( unsigned int ) F_48 ( & V_98 -> V_105 . V_104 ) ;
if ( V_104 != ( ( unsigned int ) F_48 ( & V_98 -> V_105 . V_104 ) ) )
V_104 = ( unsigned int ) F_48 ( & V_98 -> V_105 . V_104 ) ;
V_91 = V_4 -> V_106 ;
if ( V_103 >= V_104 ) {
V_101 = V_91 - ( V_103 - V_104 ) - 1 ;
V_102 = V_91 - V_103 ;
} else {
V_101 = V_104 - V_103 - 1 ;
V_102 = V_101 ;
}
V_101 = F_49 ( V_101 , ( unsigned int ) V_97 ) ;
V_97 = 0 ;
V_99 = ( char T_4 * ) F_37 ( V_2 , V_4 -> V_107 ) ;
while ( V_101 > 0 ) {
V_102 = F_49 ( V_101 , V_102 ) ;
F_50 ( V_99 + V_103 , V_100 , V_102 ) ;
V_100 += V_102 ;
V_101 -= V_102 ;
V_97 += V_102 ;
V_103 += V_102 ;
if ( V_103 >= V_91 ) {
V_103 = 0 ;
V_102 = V_104 ;
}
}
V_98 = ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ;
F_51 ( V_103 , & V_98 -> V_105 . V_103 ) ;
if ( F_17 ( V_44 , & V_4 -> V_37 ) ) {
if ( F_52 ( & V_98 -> V_108 . V_53 ) & V_55 )
F_38 ( F_52 ( & V_98 -> V_108 . V_53 ) & ~ V_55 , & V_98 -> V_108 . V_53 ) ;
}
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
V_73 = ( ( unsigned char T_4 * ) V_71 ) + V_2 -> V_83 +
V_4 -> V_84 ;
F_39 ( F_40 ( V_73 ) | V_4 -> V_85 , V_73 ) ;
F_30 ( V_44 , & V_4 -> V_37 ) ;
F_41 ( V_2 ) ;
F_23 ( & V_76 , V_27 ) ;
return ( V_97 ) ;
}
static int F_53 ( struct V_6 * V_7 , unsigned char V_109 )
{
if ( V_7 != V_50 ) {
if ( V_50 != NULL )
F_26 ( V_50 ) ;
V_50 = V_7 ;
}
V_110 [ V_111 ++ ] = V_109 ;
return 0 ;
}
static void F_26 ( struct V_6 * V_7 )
{
T_3 T_4 * V_71 ;
unsigned char T_4 * V_73 ;
V_77 T_4 * V_98 ;
struct V_6 * V_112 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_101 , V_102 , V_103 , V_104 , V_91 , V_97 , V_113 ;
unsigned char * V_96 ;
unsigned char T_4 * V_99 ;
unsigned long V_27 ;
V_113 = V_111 ;
V_112 = V_50 ;
V_111 = 0 ;
V_114 = 0 ;
V_50 = NULL ;
if ( V_112 == NULL )
return;
if ( V_7 != V_112 )
V_7 = V_112 ;
if ( V_113 == 0 )
return;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_24 >= V_34 )
return;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return;
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_98 = ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ;
V_103 = ( unsigned int ) F_48 ( & V_98 -> V_105 . V_103 ) ;
V_104 = ( unsigned int ) F_48 ( & V_98 -> V_105 . V_104 ) ;
if ( V_104 != ( ( unsigned int ) F_48 ( & V_98 -> V_105 . V_104 ) ) )
V_104 = ( unsigned int ) F_48 ( & V_98 -> V_105 . V_104 ) ;
V_91 = V_4 -> V_106 ;
if ( V_103 >= V_104 ) {
V_101 = V_91 - ( V_103 - V_104 ) - 1 ;
V_102 = V_91 - V_103 ;
} else {
V_101 = V_104 - V_103 - 1 ;
V_102 = V_101 ;
}
V_101 = F_49 ( V_101 , V_113 ) ;
V_97 = 0 ;
V_99 = F_37 ( V_2 , V_4 -> V_107 ) ;
V_96 = V_110 ;
while ( V_101 > 0 ) {
V_102 = F_49 ( V_101 , V_102 ) ;
F_50 ( V_99 + V_103 , V_96 , V_102 ) ;
V_96 += V_102 ;
V_101 -= V_102 ;
V_97 += V_102 ;
V_103 += V_102 ;
if ( V_103 >= V_91 ) {
V_103 = 0 ;
V_102 = V_104 ;
}
}
V_98 = ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ;
F_51 ( V_103 , & V_98 -> V_105 . V_103 ) ;
if ( F_17 ( V_44 , & V_4 -> V_37 ) ) {
if ( F_52 ( & V_98 -> V_108 . V_53 ) & V_55 )
F_38 ( F_52 ( & V_98 -> V_108 . V_53 ) & ~ V_55 , & V_98 -> V_108 . V_53 ) ;
}
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
V_73 = ( ( unsigned char T_4 * ) V_71 ) + V_2 -> V_83 +
V_4 -> V_84 ;
F_39 ( F_40 ( V_73 ) | V_4 -> V_85 , V_73 ) ;
F_30 ( V_44 , & V_4 -> V_37 ) ;
F_41 ( V_2 ) ;
F_23 ( & V_76 , V_27 ) ;
}
static int F_54 ( struct V_6 * V_7 )
{
T_6 T_4 * V_115 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_103 , V_104 , V_101 ;
unsigned long V_27 ;
if ( V_7 == V_50 ) {
if ( V_114 != 0 ) {
V_101 = V_114 - V_111 ;
return V_101 ;
}
}
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_24 >= V_34 )
return 0 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return 0 ;
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_115 = & ( ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ) -> V_105 ;
V_103 = ( unsigned int ) F_48 ( & V_115 -> V_103 ) ;
V_104 = ( unsigned int ) F_48 ( & V_115 -> V_104 ) ;
if ( V_104 != ( ( unsigned int ) F_48 ( & V_115 -> V_104 ) ) )
V_104 = ( unsigned int ) F_48 ( & V_115 -> V_104 ) ;
V_101 = ( V_103 >= V_104 ) ? ( V_4 -> V_106 - ( V_103 - V_104 ) ) : ( V_104 - V_103 ) ;
V_101 -- ;
F_41 ( V_2 ) ;
F_23 ( & V_76 , V_27 ) ;
if ( V_7 == V_50 ) {
V_114 = V_101 ;
V_101 -= V_111 ;
}
return V_101 ;
}
static int F_55 ( struct V_6 * V_7 )
{
T_6 T_4 * V_115 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_103 , V_104 , V_101 ;
unsigned long V_27 ;
if ( V_7 == V_50 )
F_26 ( V_7 ) ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_24 >= V_34 )
return 0 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return 0 ;
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_115 = & ( ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ) -> V_105 ;
V_103 = ( unsigned int ) F_48 ( & V_115 -> V_103 ) ;
V_104 = ( unsigned int ) F_48 ( & V_115 -> V_104 ) ;
if ( V_104 != ( ( unsigned int ) F_48 ( & V_115 -> V_104 ) ) )
V_104 = ( unsigned int ) F_48 ( & V_115 -> V_104 ) ;
V_101 = ( V_103 >= V_104 ) ? ( V_103 - V_104 ) : ( V_4 -> V_106 - ( V_104 - V_103 ) ) ;
if ( ( V_101 == 0 ) && F_17 ( V_44 , & V_4 -> V_37 ) )
V_101 = 1 ;
F_41 ( V_2 ) ;
F_23 ( & V_76 , V_27 ) ;
return V_101 ;
}
static int F_56 ( struct V_3 * V_4 , struct V_116 T_7 * V_15 )
{
struct V_116 V_117 ;
struct V_1 * V_2 ;
memset ( & V_117 , 0 , sizeof( struct V_116 ) ) ;
V_117 . type = V_118 ;
V_117 . line = V_4 -> V_32 ;
V_117 . V_119 = 0 ;
V_117 . V_27 = V_4 -> V_10 . V_27 ;
V_117 . V_120 = V_4 -> V_120 ;
V_117 . V_121 = V_4 -> V_10 . V_121 ;
V_117 . V_122 = V_4 -> V_122 ;
V_117 . V_123 = V_4 -> V_123 ;
V_117 . V_124 = 0 ;
V_117 . V_125 = 0 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 != NULL )
V_117 . V_10 = V_2 -> V_126 ;
return F_57 ( V_15 , & V_117 , sizeof( struct V_116 ) ) ?
- V_127 : 0 ;
}
static int F_58 ( struct V_6 * V_7 , struct V_116 T_7 * V_15 )
{
struct V_116 V_117 ;
int V_25 ;
struct V_3 * V_4 = V_7 -> V_40 ;
if ( F_59 ( & V_117 , V_15 , sizeof( struct V_116 ) ) )
return - V_127 ;
if ( ! F_60 ( V_128 ) ) {
if ( ( V_117 . V_120 != V_4 -> V_120 ) ||
( V_117 . V_121 != V_4 -> V_10 . V_121 ) ||
( ( V_117 . V_27 & ~ V_129 ) !=
( V_4 -> V_10 . V_27 & ~ V_129 ) ) )
return - V_130 ;
}
V_4 -> V_10 . V_27 = ( V_4 -> V_10 . V_27 & ~ V_129 ) |
( V_117 . V_27 & V_129 ) ;
V_4 -> V_120 = V_117 . V_120 ;
V_4 -> V_10 . V_121 = V_117 . V_121 ;
V_4 -> V_122 = V_117 . V_122 ;
V_4 -> V_123 = V_117 . V_123 ;
if ( ( V_25 = F_44 ( V_7 ) ) < 0 )
return V_25 ;
return 0 ;
}
static int F_61 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_40 ;
struct V_1 * V_2 ;
int V_25 ;
if ( V_4 == NULL )
return - V_35 ;
if ( V_4 -> V_24 >= V_34 )
return 0 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return 0 ;
if ( V_7 -> V_27 & ( 1 << V_26 ) )
return - V_87 ;
if ( ( V_25 = F_24 ( V_2 , V_4 , V_63 ,
& V_4 -> V_64 , sizeof( V_65 ) , 1 ) ) < 0 )
return V_25 ;
return F_32 ( V_4 -> V_64 . V_67 ) ;
}
static int F_62 ( struct V_6 * V_7 ,
unsigned int V_131 , unsigned int V_132 )
{
struct V_3 * V_4 = V_7 -> V_40 ;
struct V_1 * V_2 ;
int V_133 = - 1 , V_134 = - 1 ;
if ( V_4 == NULL )
return - V_35 ;
if ( V_4 -> V_24 >= V_34 )
return 0 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return 0 ;
if ( V_7 -> V_27 & ( 1 << V_26 ) )
return - V_87 ;
if ( V_131 & V_135 )
V_133 = 1 ;
if ( V_131 & V_136 )
V_134 = 1 ;
if ( V_132 & V_135 )
V_133 = 0 ;
if ( V_132 & V_136 )
V_134 = 0 ;
F_33 ( & V_4 -> V_64 , V_134 , V_133 ) ;
return F_24 ( V_2 , V_4 , V_68 , & V_4 -> V_64 ,
sizeof( V_65 ) , 0 ) ;
}
static int F_63 ( struct V_6 * V_7 , unsigned int V_90 , unsigned long V_69 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_25 ;
void T_7 * V_13 = ( void T_7 * ) V_69 ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return - V_35 ;
if ( V_4 -> V_24 >= V_34 )
return 0 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return 0 ;
if ( ( V_90 != V_137 ) && ( V_90 != V_138 ) &&
( V_90 != V_139 ) && ( V_90 != V_140 ) ) {
if ( V_7 -> V_27 & ( 1 << V_26 ) )
return - V_87 ;
}
V_25 = 0 ;
switch ( V_90 ) {
case V_137 :
V_25 = F_56 ( V_4 , V_13 ) ;
break;
case V_138 :
V_25 = F_58 ( V_7 , V_13 ) ;
break;
case V_141 :
V_25 = F_64 ( V_4 -> V_142 , ( unsigned T_7 * ) V_13 ) ;
break;
case V_143 :
if ( ( V_25 = F_65 ( V_4 -> V_142 , ( unsigned T_7 * ) V_13 ) ) == 0 )
F_44 ( V_7 ) ;
break;
case V_139 :
V_25 = F_66 ( V_7 , V_4 , V_13 ) ;
break;
case V_140 :
V_25 = F_67 ( V_4 , V_13 ) ;
break;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
default:
V_25 = - V_151 ;
break;
}
return V_25 ;
}
static void F_68 ( struct V_6 * V_7 , struct V_152 * V_153 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_152 * V_154 ;
T_2 V_52 ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_24 >= V_34 )
return;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return;
V_154 = V_7 -> V_60 ;
F_29 ( V_7 , V_4 , & V_52 , V_154 ) ;
F_24 ( V_2 , V_4 , V_61 , & V_52 , sizeof( T_2 ) , 0 ) ;
F_33 ( & V_4 -> V_64 , ( ( V_154 -> V_155 & V_156 ) ? 1 : 0 ) , - 1 ) ;
F_24 ( V_2 , V_4 , V_68 , & V_4 -> V_64 ,
sizeof( V_65 ) , 0 ) ;
if ( ( V_153 -> V_155 & V_157 ) && ( ( V_154 -> V_155 & V_157 ) == 0 ) )
V_7 -> V_158 = 0 ;
if ( ( ( V_153 -> V_155 & V_159 ) == 0 ) && ( V_154 -> V_155 & V_159 ) )
F_14 ( & V_4 -> V_10 . V_160 ) ;
}
static void F_69 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return;
F_30 ( V_45 , & V_4 -> V_37 ) ;
}
static void F_70 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return;
F_13 ( V_45 , & V_4 -> V_37 ) ;
}
static void F_71 ( struct V_6 * V_7 )
{
}
static void F_72 ( struct V_6 * V_7 )
{
}
static void F_73 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_40 ;
F_74 ( & V_4 -> V_10 ) ;
}
static void F_75 ( struct V_6 * V_7 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned long V_41 , V_27 ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_24 >= V_34 )
return;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return;
F_22 ( & V_76 , V_27 ) ;
if ( V_7 == V_50 ) {
V_50 = NULL ;
V_111 = 0 ;
V_114 = 0 ;
}
if ( F_17 ( V_93 , & V_4 -> V_37 ) ) {
F_30 ( V_161 , & V_4 -> V_37 ) ;
} else {
V_41 = V_46 ;
if ( F_17 ( V_162 , & V_4 -> V_37 ) ) {
V_41 |= V_47 ;
F_13 ( V_162 , & V_4 -> V_37 ) ;
}
F_76 ( V_2 , V_4 , V_48 , & V_41 , sizeof( V_49 ) , 0 ) ;
}
F_23 ( & V_76 , V_27 ) ;
F_77 ( V_7 ) ;
}
static int F_78 ( struct V_6 * V_7 , int V_37 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
long V_69 ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return - V_163 ;
if ( V_4 -> V_24 >= V_34 )
return - V_163 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return - V_163 ;
V_69 = ( V_37 == - 1 ) ? V_164 : V_165 ;
F_24 ( V_2 , V_4 , V_166 , & V_69 , sizeof( long ) , 0 ) ;
return 0 ;
}
static void F_79 ( struct V_6 * V_7 , int V_167 )
{
struct V_3 * V_4 ;
unsigned long V_168 ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return;
if ( V_167 == 0 )
V_167 = V_169 ;
V_168 = V_170 + V_167 ;
while ( F_17 ( V_44 , & V_4 -> V_37 ) ) {
if ( F_35 ( V_74 ) )
break;
F_80 ( 20 ) ;
if ( F_81 ( V_170 , V_168 ) )
break;
}
}
static void F_82 ( struct V_6 * V_7 , char V_109 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_171 ;
V_4 = V_7 -> V_40 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_24 >= V_34 )
return;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return;
memset ( & V_171 , 0 , sizeof( T_8 ) ) ;
if ( V_109 == F_83 ( V_7 ) ) {
V_171 . V_172 = V_173 ;
} else if ( V_109 == F_84 ( V_7 ) ) {
V_171 . V_172 = V_174 ;
} else {
V_171 . V_175 = V_176 ;
V_171 . V_177 = V_109 ;
}
F_24 ( V_2 , V_4 , V_178 , & V_171 , sizeof( T_8 ) , 0 ) ;
}
static void F_85 ( struct V_179 * V_180 , struct V_1 * V_2 , struct V_3 * V_4 , int V_32 )
{
char * V_181 ;
int V_25 ;
V_25 = F_86 ( NULL , V_4 ) ;
V_181 = L_3 ;
if ( F_17 ( V_36 , & V_2 -> V_37 ) ) {
switch ( V_182 . V_183 ) {
case 0 : V_181 = L_4 ; break;
case 1 : V_181 = L_5 ; break;
default: V_181 = L_6 ; break;
}
}
F_87 ( V_180 , L_7 , V_32 , V_181 ) ;
if ( F_17 ( V_36 , & V_2 -> V_37 ) && V_25 >= 0 ) {
char V_184 ;
F_87 ( V_180 , L_8 , ( int ) V_182 . V_185 ,
( int ) V_182 . V_186 ) ;
if ( V_182 . V_187 )
F_87 ( V_180 , L_9 ,
( int ) V_182 . V_187 ) ;
if ( V_182 . V_188 )
F_87 ( V_180 , L_10 ,
( int ) V_182 . V_188 ) ;
if ( V_182 . V_189 )
F_87 ( V_180 , L_11 ,
( int ) V_182 . V_189 ) ;
if ( V_182 . V_190 )
F_87 ( V_180 , L_12 ,
( int ) V_182 . V_190 ) ;
V_184 = ' ' ;
if ( V_182 . V_191 & V_135 ) {
F_87 ( V_180 , L_13 , V_184 , L_14 ) ;
V_184 = '|' ;
}
if ( V_182 . V_191 & V_192 ) {
F_87 ( V_180 , L_13 , V_184 , L_15 ) ;
V_184 = '|' ;
}
if ( V_182 . V_191 & V_136 ) {
F_87 ( V_180 , L_13 , V_184 , L_16 ) ;
V_184 = '|' ;
}
if ( V_182 . V_191 & V_94 ) {
F_87 ( V_180 , L_13 , V_184 , L_17 ) ;
V_184 = '|' ;
}
if ( V_182 . V_191 & V_193 ) {
F_87 ( V_180 , L_13 , V_184 , L_18 ) ;
V_184 = '|' ;
}
}
F_88 ( V_180 , '\n' ) ;
}
static int F_89 ( struct V_179 * V_180 , void * V_194 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned int V_24 , V_32 , V_195 ;
V_195 = 0 ;
F_87 ( V_180 , L_19 , V_196 , V_197 ) ;
for ( V_24 = 0 ; ( V_24 < V_34 ) ; V_24 ++ ) {
V_2 = V_23 [ V_24 ] ;
if ( V_2 == NULL )
continue;
if ( V_2 -> V_37 == 0 )
continue;
V_195 = V_24 * V_8 ;
for ( V_32 = 0 ; ( V_32 < V_2 -> V_38 ) ; V_32 ++ ,
V_195 ++ ) {
V_4 = V_2 -> V_9 [ V_32 ] ;
if ( V_4 == NULL )
continue;
F_85 ( V_180 , V_2 , V_4 , V_195 ) ;
}
}
return 0 ;
}
static int F_90 ( struct V_198 * V_198 , struct V_29 * V_29 )
{
return F_91 ( V_29 , F_89 , NULL ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned long V_90 , void * V_69 , int V_91 , int V_92 )
{
T_3 T_4 * V_71 ;
T_5 T_4 * V_72 ;
unsigned char T_4 * V_73 ;
if ( F_17 ( V_93 , & V_4 -> V_37 ) ) {
F_8 ( V_199 L_20 ,
( int ) V_90 ) ;
return;
}
F_36 ( V_2 ) ;
V_72 = & ( ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ) -> V_79 ;
if ( V_91 > 0 ) {
F_50 ( ( void T_4 * ) & ( V_72 -> args [ 0 ] ) , V_69 , V_91 ) ;
if ( V_92 ) {
V_4 -> V_13 = V_69 ;
V_4 -> V_200 = V_91 ;
}
}
F_38 ( 0 , & V_72 -> V_201 ) ;
F_38 ( V_90 , & V_72 -> V_90 ) ;
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
V_73 = ( ( unsigned char T_4 * ) V_71 ) + V_2 -> V_83 +
V_4 -> V_84 ;
F_39 ( F_40 ( V_73 ) | V_4 -> V_85 , V_73 ) ;
F_30 ( V_93 , & V_4 -> V_37 ) ;
F_41 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned long V_90 , void * V_69 , int V_91 , int V_92 )
{
unsigned long V_27 ;
F_22 ( & V_76 , V_27 ) ;
F_76 ( V_2 , V_4 , V_90 , V_69 , V_91 , V_92 ) ;
F_23 ( & V_76 , V_27 ) ;
}
static void F_92 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_6 T_4 * V_115 ;
char T_4 * V_99 ;
struct V_6 * V_7 ;
unsigned int V_103 , V_104 , V_91 ;
unsigned int V_101 , V_102 ;
if ( F_17 ( V_45 , & V_4 -> V_37 ) )
return;
V_7 = F_2 ( & V_4 -> V_10 ) ;
if ( V_7 == NULL )
return;
V_115 = & ( ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ) -> V_202 ;
V_103 = ( unsigned int ) F_48 ( & V_115 -> V_103 ) ;
if ( V_103 != ( ( unsigned int ) F_48 ( & V_115 -> V_103 ) ) )
V_103 = ( unsigned int ) F_48 ( & V_115 -> V_103 ) ;
V_104 = ( unsigned int ) F_48 ( & V_115 -> V_104 ) ;
V_91 = V_4 -> V_203 ;
if ( V_103 >= V_104 ) {
V_101 = V_103 - V_104 ;
V_102 = V_101 ;
} else {
V_101 = V_91 - ( V_104 - V_103 ) ;
V_102 = V_91 - V_104 ;
}
V_101 = F_93 ( V_7 , V_101 ) ;
V_99 = ( char T_4 * ) F_37 ( V_2 , V_4 -> V_204 ) ;
while ( V_101 > 0 ) {
unsigned char * V_205 ;
V_102 = F_49 ( V_101 , V_102 ) ;
F_94 ( V_7 , & V_205 , V_102 ) ;
F_95 ( V_205 , V_99 + V_104 , V_102 ) ;
V_101 -= V_102 ;
V_104 += V_102 ;
if ( V_104 >= V_91 ) {
V_104 = 0 ;
V_102 = V_103 ;
}
}
V_115 = & ( ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ) -> V_202 ;
F_51 ( V_104 , & V_115 -> V_104 ) ;
if ( V_103 != V_104 )
F_30 ( V_206 , & V_4 -> V_37 ) ;
F_96 ( V_7 ) ;
F_4 ( V_7 ) ;
}
static void F_97 ( struct V_3 * V_4 , T_5 T_4 * V_72 )
{
int V_90 ;
if ( F_17 ( V_207 , & V_4 -> V_37 ) ) {
if ( F_17 ( V_161 , & V_4 -> V_37 ) &&
F_17 ( V_162 , & V_4 -> V_37 ) )
V_90 = V_208 ;
else if ( F_17 ( V_161 , & V_4 -> V_37 ) )
V_90 = V_209 ;
else if ( F_17 ( V_162 , & V_4 -> V_37 ) )
V_90 = V_210 ;
else
V_90 = V_68 ;
F_13 ( V_161 , & V_4 -> V_37 ) ;
F_13 ( V_162 , & V_4 -> V_37 ) ;
F_13 ( V_207 , & V_4 -> V_37 ) ;
F_50 ( ( void T_4 * ) & ( V_72 -> args [ 0 ] ) , ( void * ) & V_4 -> V_64 ,
sizeof( V_65 ) ) ;
F_38 ( 0 , & V_72 -> V_201 ) ;
F_38 ( V_90 , & V_72 -> V_90 ) ;
F_30 ( V_93 , & V_4 -> V_37 ) ;
} else if ( F_17 ( V_161 , & V_4 -> V_37 ) ||
F_17 ( V_162 , & V_4 -> V_37 ) ) {
V_90 = ( ( F_17 ( V_161 , & V_4 -> V_37 ) ) ? V_46 : 0 ) ;
V_90 |= ( ( F_17 ( V_162 , & V_4 -> V_37 ) ) ? V_47 : 0 ) ;
F_13 ( V_161 , & V_4 -> V_37 ) ;
F_13 ( V_162 , & V_4 -> V_37 ) ;
F_50 ( ( void T_4 * ) & ( V_72 -> args [ 0 ] ) , ( void * ) & V_90 , sizeof( int ) ) ;
F_38 ( 0 , & V_72 -> V_201 ) ;
F_38 ( V_48 , & V_72 -> V_90 ) ;
F_30 ( V_93 , & V_4 -> V_37 ) ;
}
}
static int F_98 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_77 T_4 * V_98 ;
T_5 T_4 * V_72 ;
struct V_6 * V_7 ;
T_1 V_51 ;
unsigned long V_211 ;
int V_25 , V_212 ;
V_98 = ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ;
V_72 = & V_98 -> V_79 ;
if ( F_17 ( V_86 , & V_4 -> V_37 ) ) {
V_25 = F_52 ( & V_72 -> V_80 ) ;
if ( F_40 ( & V_72 -> V_81 ) == 0 && V_25 != 0 ) {
if ( V_25 > 0 )
V_25 -- ;
F_38 ( 0 , & V_72 -> V_80 ) ;
V_4 -> V_25 = V_25 ;
F_13 ( V_86 , & V_4 -> V_37 ) ;
F_14 ( & V_4 -> V_28 ) ;
}
}
if ( F_17 ( V_42 , & V_4 -> V_37 ) ) {
V_25 = ( int ) F_52 ( & V_72 -> V_88 ) ;
if ( F_40 ( & V_72 -> V_89 ) == 0 && V_25 != 0 ) {
if ( V_25 > 0 )
V_25 -- ;
F_38 ( 0 , & V_72 -> V_88 ) ;
V_4 -> V_25 = V_25 ;
F_13 ( V_42 , & V_4 -> V_37 ) ;
F_14 ( & V_4 -> V_28 ) ;
}
}
if ( F_17 ( V_93 , & V_4 -> V_37 ) ) {
V_25 = F_52 ( & V_72 -> V_201 ) ;
if ( F_52 ( & V_72 -> V_90 ) == 0 && V_25 != 0 ) {
if ( V_25 > 0 )
V_25 -- ;
if ( V_4 -> V_13 != NULL ) {
F_95 ( V_4 -> V_13 , ( void T_4 * ) & ( V_72 -> args [ 0 ] ) ,
V_4 -> V_200 ) ;
V_4 -> V_13 = NULL ;
}
F_38 ( 0 , & V_72 -> V_201 ) ;
V_4 -> V_25 = V_25 ;
F_13 ( V_93 , & V_4 -> V_37 ) ;
F_97 ( V_4 , V_72 ) ;
F_14 ( & V_4 -> V_28 ) ;
}
}
V_212 = 0 ;
if ( V_98 -> V_213 ) {
V_51 = V_98 -> V_108 ;
V_98 -> V_213 = 0 ;
V_7 = F_2 ( & V_4 -> V_10 ) ;
if ( V_51 . signal & V_58 ) {
V_211 = V_4 -> V_66 ;
V_4 -> V_66 = F_32 ( V_51 . V_67 ) ;
F_13 ( V_62 , & V_4 -> V_37 ) ;
if ( ( V_4 -> V_66 & V_94 ) &&
( ( V_211 & V_94 ) == 0 ) )
F_14 ( & V_4 -> V_10 . V_160 ) ;
if ( ( V_211 & V_94 ) &&
( ( V_4 -> V_66 & V_94 ) == 0 ) ) {
if ( V_4 -> V_10 . V_27 & V_214 ) {
if ( V_7 )
F_3 ( V_7 ) ;
}
}
}
if ( V_51 . V_53 & V_55 )
F_13 ( V_44 , & V_4 -> V_37 ) ;
if ( V_51 . V_53 & ( V_55 | V_54 ) ) {
if ( V_7 != NULL ) {
F_77 ( V_7 ) ;
F_36 ( V_2 ) ;
}
}
if ( ( V_51 . V_53 & V_57 ) && ( V_4 -> V_215 & V_216 ) ) {
if ( V_7 != NULL ) {
F_99 ( V_7 , 0 , V_217 ) ;
if ( V_4 -> V_10 . V_27 & V_218 ) {
F_100 ( V_7 ) ;
F_36 ( V_2 ) ;
}
F_96 ( V_7 ) ;
}
}
F_4 ( V_7 ) ;
if ( V_51 . V_53 & V_56 ) {
V_212 ++ ;
F_92 ( V_2 , V_4 ) ;
}
}
if ( ( ! V_212 ) && F_17 ( V_206 , & V_4 -> V_37 ) ) {
F_13 ( V_206 , & V_4 -> V_37 ) ;
F_92 ( V_2 , V_4 ) ;
}
return ( ( F_17 ( V_86 , & V_4 -> V_37 ) ||
F_17 ( V_42 , & V_4 -> V_37 ) ||
F_17 ( V_93 , & V_4 -> V_37 ) ||
F_17 ( V_44 , & V_4 -> V_37 ) ||
F_17 ( V_206 , & V_4 -> V_37 ) ) ? 0 : 1 ) ;
}
static void F_101 ( struct V_1 * V_2 , T_3 T_4 * V_71 )
{
struct V_3 * V_4 ;
unsigned char V_219 [ ( V_220 / 8 ) + 1 ] ;
unsigned char V_221 [ ( V_220 / 8 ) + 1 ] ;
unsigned char T_4 * V_222 ;
int V_223 , V_224 , V_225 ;
int V_226 , V_227 , V_228 ;
V_225 = V_2 -> V_225 ;
V_227 = V_2 -> V_227 ;
F_95 ( & V_219 [ 0 ] , ( ( ( unsigned char T_4 * ) V_71 ) + V_2 -> V_229 ) ,
V_225 ) ;
memset ( & V_221 [ 0 ] , 0 , V_225 ) ;
V_228 = 0 ;
for ( V_223 = 0 ; ( V_223 < V_225 ) ; V_223 ++ ) {
if ( V_219 [ V_223 ] == 0 )
continue;
V_226 = V_223 * 8 ;
for ( V_224 = 0x1 ; ( V_226 < V_227 ) ; V_226 ++ , V_224 <<= 1 ) {
if ( V_219 [ V_223 ] & V_224 ) {
V_4 = V_2 -> V_9 [ ( V_226 - 1 ) ] ;
if ( F_98 ( V_2 , V_4 ) ) {
V_228 ++ ;
V_221 [ V_223 ] |= V_224 ;
}
}
}
}
if ( V_228 ) {
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
V_222 = ( ( unsigned char T_4 * ) V_71 ) + V_2 -> V_83 ;
for ( V_223 = 0 ; ( V_223 < V_225 ) ; V_223 ++ ) {
if ( F_40 ( V_221 + V_223 ) )
F_39 ( F_40 ( V_222 + V_223 ) & ~ V_221 [ V_223 ] , V_221 + V_223 ) ;
}
}
}
static void F_102 ( unsigned long V_69 )
{
T_3 T_4 * V_71 ;
struct V_1 * V_2 ;
unsigned int V_24 ;
F_103 ( & V_230 , V_231 ) ;
for ( V_24 = 0 ; ( V_24 < V_34 ) ; V_24 ++ ) {
V_2 = V_23 [ V_24 ] ;
if ( V_2 == NULL )
continue;
if ( ! F_17 ( V_36 , & V_2 -> V_37 ) )
continue;
F_104 ( & V_76 ) ;
F_36 ( V_2 ) ;
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
if ( F_40 ( & V_71 -> V_232 ) )
F_101 ( V_2 , V_71 ) ;
F_41 ( V_2 ) ;
F_105 ( & V_76 ) ;
}
}
static void F_29 ( struct V_6 * V_7 , struct V_3 * V_4 ,
T_2 * V_233 , struct V_152 * V_154 )
{
memset ( V_233 , 0 , sizeof( T_2 ) ) ;
V_233 -> V_234 = F_106 ( V_7 ) ;
if ( ( V_154 -> V_155 & V_156 ) == V_235 ) {
if ( ( V_4 -> V_10 . V_27 & V_236 ) == V_237 )
V_233 -> V_234 = 57600 ;
else if ( ( V_4 -> V_10 . V_27 & V_236 ) == V_238 )
V_233 -> V_234 = 115200 ;
else if ( ( V_4 -> V_10 . V_27 & V_236 ) == V_239 )
V_233 -> V_234 = 230400 ;
else if ( ( V_4 -> V_10 . V_27 & V_236 ) == V_240 )
V_233 -> V_234 = 460800 ;
else if ( ( V_4 -> V_10 . V_27 & V_236 ) == V_241 )
V_233 -> V_234 = ( V_4 -> V_120 / V_4 -> V_123 ) ;
}
if ( V_233 -> V_234 > V_242 )
V_233 -> V_234 = V_242 ;
V_233 -> V_243 = V_233 -> V_234 ;
switch ( V_154 -> V_155 & V_244 ) {
case V_245 :
V_233 -> V_246 = 5 ;
break;
case V_247 :
V_233 -> V_246 = 6 ;
break;
case V_248 :
V_233 -> V_246 = 7 ;
break;
default:
V_233 -> V_246 = 8 ;
break;
}
if ( V_154 -> V_155 & V_249 )
V_233 -> V_250 = V_251 ;
else
V_233 -> V_250 = V_252 ;
if ( V_154 -> V_155 & V_253 ) {
if ( V_154 -> V_155 & V_254 )
V_233 -> V_255 = V_256 ;
else
V_233 -> V_255 = V_257 ;
} else {
V_233 -> V_255 = V_258 ;
}
if ( V_154 -> V_259 & V_260 ) {
V_233 -> V_261 |= V_262 ;
if ( V_154 -> V_259 & V_263 )
V_233 -> V_261 |= V_264 ;
}
if ( V_154 -> V_155 & V_157 )
V_233 -> V_261 |= ( V_265 | V_266 ) ;
V_233 -> V_267 = V_154 -> V_268 [ V_269 ] ;
V_233 -> V_270 = V_154 -> V_268 [ V_271 ] ;
V_233 -> V_272 = V_154 -> V_268 [ V_269 ] ;
V_233 -> V_273 = V_154 -> V_268 [ V_271 ] ;
if ( V_154 -> V_259 & V_274 )
V_233 -> V_275 |= V_276 ;
if ( V_154 -> V_259 & V_277 )
V_233 -> V_275 |= V_278 ;
V_4 -> V_215 = 0 ;
if ( V_154 -> V_259 & ( V_279 | V_280 ) )
V_233 -> V_275 |= V_281 ;
if ( V_154 -> V_259 & V_216 )
V_4 -> V_215 |= V_216 ;
if ( V_154 -> V_155 & V_159 )
V_4 -> V_10 . V_27 &= ~ V_214 ;
else
V_4 -> V_10 . V_27 |= V_214 ;
V_233 -> V_142 = ( V_4 -> V_142 & 0xffff ) ;
V_233 -> V_282 = ( V_4 -> V_142 & V_283 ) ? 1 : 0 ;
V_233 -> V_284 = ( V_4 -> V_142 & V_285 ) ? 1 : 0 ;
V_233 -> V_286 [ 1 ] = ( V_4 -> V_142 & V_287 ) ? 1 : 0 ;
}
static void F_33 ( V_65 * V_15 , int V_134 , int V_133 )
{
memset ( V_15 , 0 , sizeof( V_65 ) ) ;
if ( V_134 >= 0 ) {
V_15 -> signal |= V_288 ;
V_15 -> V_67 |= ( ( V_134 > 0 ) ? V_288 : 0 ) ;
}
if ( V_133 >= 0 ) {
V_15 -> signal |= V_289 ;
V_15 -> V_67 |= ( ( V_133 > 0 ) ? V_289 : 0 ) ;
}
}
static long F_32 ( unsigned long V_67 )
{
long V_290 = 0 ;
V_290 |= ( ( V_67 & V_58 ) ? V_94 : 0 ) ;
V_290 |= ( ( V_67 & V_291 ) ? V_192 : 0 ) ;
V_290 |= ( ( V_67 & V_292 ) ? V_293 : 0 ) ;
V_290 |= ( ( V_67 & V_294 ) ? V_193 : 0 ) ;
V_290 |= ( ( V_67 & V_288 ) ? V_136 : 0 ) ;
V_290 |= ( ( V_67 & V_289 ) ? V_135 : 0 ) ;
return ( V_290 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_14 , V_295 , V_296 ;
for ( V_14 = 0 , V_295 = 0 , V_296 = 0 ; ( V_14 < V_2 -> V_38 ) ; V_14 ++ ) {
V_4 = F_108 ( sizeof( struct V_3 ) , V_297 ) ;
if ( ! V_4 ) {
F_8 ( V_18 L_21 ) ;
continue;
}
F_109 ( & V_4 -> V_10 ) ;
V_4 -> V_10 . V_298 = & V_299 ;
V_4 -> V_300 = V_301 ;
V_4 -> V_32 = V_14 ;
V_4 -> V_24 = V_2 -> V_24 ;
V_4 -> V_295 = V_295 ;
V_4 -> V_120 = V_302 ;
V_4 -> V_10 . V_121 = V_303 ;
V_4 -> V_122 = 30 * V_169 ;
F_110 ( & V_4 -> V_10 . V_160 ) ;
F_110 ( & V_4 -> V_10 . V_304 ) ;
F_110 ( & V_4 -> V_28 ) ;
V_296 ++ ;
if ( V_296 >= V_2 -> V_305 [ V_295 ] ) {
V_296 = 0 ;
V_295 ++ ;
}
V_2 -> V_9 [ V_14 ] = V_4 ;
}
return 0 ;
}
static void F_111 ( struct V_1 * V_2 )
{
unsigned long V_306 ;
F_112 ( V_307 , ( V_2 -> V_126 + V_308 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_309 , ( V_2 -> V_126 + V_308 ) ) ;
F_113 ( 100 ) ;
V_306 = ( V_2 -> V_21 & V_310 ) >> V_311 ;
F_112 ( V_306 , ( V_2 -> V_126 + V_312 ) ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_112 ( V_313 , ( V_2 -> V_126 + V_308 ) ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_112 ( V_309 , ( V_2 -> V_126 + V_308 ) ) ;
}
static void T_4 * F_116 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
void T_4 * V_315 ;
unsigned char V_316 ;
if ( V_314 > V_2 -> V_317 ) {
F_8 ( V_199 L_22
L_23 ,
( int ) V_314 , line , __LINE__ , V_2 -> V_24 ) ;
V_315 = NULL ;
V_316 = 0 ;
} else {
V_315 = V_2 -> V_318 + ( V_314 % V_319 ) ;
V_316 = ( unsigned char ) ( V_314 / V_319 ) ;
}
F_112 ( V_316 , ( V_2 -> V_126 + V_320 ) ) ;
return ( V_315 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_112 ( V_307 , ( V_2 -> V_126 + V_308 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_309 , ( V_2 -> V_126 + V_308 ) ) ;
F_113 ( 500 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_112 ( 0x1 , V_2 -> V_126 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
unsigned long V_306 ;
F_112 ( 0x1 , ( V_2 -> V_126 + V_321 ) ) ;
F_112 ( V_322 , ( V_2 -> V_126 + V_323 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_324 , ( V_2 -> V_126 + V_323 ) ) ;
F_113 ( 500 ) ;
V_306 = ( V_2 -> V_21 & V_325 ) >> V_326 ;
F_112 ( V_306 , ( V_2 -> V_126 + V_327 ) ) ;
V_306 = ( V_2 -> V_21 & V_328 ) >> V_329 ;
F_112 ( V_306 , ( V_2 -> V_126 + V_330 ) ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_112 ( V_331 , ( V_2 -> V_126 + V_323 ) ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_112 ( V_324 , ( V_2 -> V_126 + V_323 ) ) ;
}
static void T_4 * F_122 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
void T_4 * V_315 ;
unsigned char V_316 ;
if ( V_314 > V_2 -> V_317 ) {
F_8 ( V_199 L_22
L_23 ,
( int ) V_314 , line , __LINE__ , V_2 -> V_24 ) ;
V_315 = NULL ;
V_316 = 0 ;
} else {
V_315 = V_2 -> V_318 + ( V_314 % V_332 ) ;
if ( V_314 < V_332 )
V_316 = V_331 ;
else
V_316 = V_331 | 0x40 ;
}
F_112 ( V_316 , ( V_2 -> V_126 + V_323 ) ) ;
return ( V_315 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_112 ( V_322 , ( V_2 -> V_126 + V_323 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_324 , ( V_2 -> V_126 + V_323 ) ) ;
F_113 ( 500 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_112 ( V_333 , ( V_2 -> V_126 + V_334 ) ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_112 ( V_335 , ( V_2 -> V_126 + V_334 ) ) ;
}
static void T_4 * F_126 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
void T_4 * V_315 ;
unsigned char V_316 ;
if ( V_314 > V_2 -> V_317 ) {
F_8 ( V_199 L_22
L_23 ,
( int ) V_314 , line , __LINE__ , V_2 -> V_24 ) ;
V_315 = NULL ;
V_316 = 0 ;
} else {
V_315 = V_2 -> V_318 + ( V_314 % V_336 ) ;
V_316 = ( ( unsigned char ) ( V_314 / V_336 ) ) | V_333 ;
}
F_112 ( V_316 , ( V_2 -> V_126 + V_334 ) ) ;
return ( V_315 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_112 ( V_337 , ( V_2 -> V_126 + V_334 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_335 , ( V_2 -> V_126 + V_334 ) ) ;
F_113 ( 500 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_112 ( V_338 , ( V_2 -> V_126 + V_339 ) ) ;
F_113 ( 10 ) ;
F_112 ( 0 , ( V_2 -> V_126 + V_339 ) ) ;
F_113 ( 500 ) ;
}
static void T_4 * F_129 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
void T_4 * V_315 ;
unsigned char V_316 ;
if ( V_314 > V_2 -> V_317 ) {
F_8 ( V_199 L_22
L_24 ,
( int ) V_314 , line , __LINE__ , V_2 -> V_24 ) ;
V_315 = NULL ;
V_316 = 0 ;
} else {
V_315 = V_2 -> V_318 + ( V_314 % V_340 ) ;
V_316 = ( V_314 / V_340 ) << 1 ;
}
F_112 ( V_316 , ( V_2 -> V_126 + V_339 ) ) ;
return ( V_315 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_112 ( V_338 , ( V_2 -> V_126 + V_339 ) ) ;
F_113 ( 10 ) ;
F_112 ( 0 , ( V_2 -> V_126 + V_339 ) ) ;
F_113 ( 500 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
unsigned long V_306 ;
F_112 ( V_341 , ( V_2 -> V_126 + V_342 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_343 , ( V_2 -> V_126 + V_342 ) ) ;
F_132 ( 1000 ) ;
V_306 = ( V_2 -> V_21 & V_344 ) >> V_345 ;
F_112 ( V_306 , ( V_2 -> V_126 + V_346 ) ) ;
F_112 ( 0x1 , V_2 -> V_126 ) ;
F_132 ( 1 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_112 ( ( V_2 -> V_347 | V_348 ) , ( V_2 -> V_126 + V_342 ) ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
F_112 ( ( V_2 -> V_347 | V_343 ) , ( V_2 -> V_126 + V_342 ) ) ;
}
static void T_4 * F_135 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
void T_4 * V_315 ;
if ( V_314 > V_2 -> V_317 ) {
F_8 ( V_199 L_22
L_23 ,
( int ) V_314 , line , __LINE__ , V_2 -> V_24 ) ;
V_315 = NULL ;
} else {
V_315 = V_2 -> V_318 + ( V_314 % V_349 ) ;
}
return ( V_315 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_112 ( V_341 , ( V_2 -> V_126 + V_342 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_343 , ( V_2 -> V_126 + V_342 ) ) ;
F_132 ( 1000 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned long V_306 ;
F_112 ( 0x1 , ( V_2 -> V_126 + V_350 ) ) ;
F_112 ( V_351 , ( V_2 -> V_126 + V_352 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_353 , ( V_2 -> V_126 + V_352 ) ) ;
F_132 ( 1000 ) ;
V_306 = ( V_2 -> V_21 & V_354 ) >> V_355 ;
F_112 ( V_306 , ( V_2 -> V_126 + V_356 ) ) ;
V_306 = ( V_2 -> V_21 & V_357 ) >> V_358 ;
F_112 ( V_306 , ( V_2 -> V_126 + V_359 ) ) ;
F_112 ( 0x1 , V_2 -> V_126 ) ;
F_132 ( 1 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
F_112 ( V_360 , ( V_2 -> V_126 + V_352 ) ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_112 ( V_353 , ( V_2 -> V_126 + V_352 ) ) ;
}
static void T_4 * F_140 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
void T_4 * V_315 ;
unsigned char V_316 ;
if ( V_314 > V_2 -> V_317 ) {
F_8 ( V_199 L_22
L_23 ,
( int ) V_314 , line , __LINE__ , V_2 -> V_24 ) ;
V_315 = NULL ;
V_316 = 0 ;
} else {
V_315 = V_2 -> V_318 + ( V_314 % V_361 ) ;
if ( V_314 < V_361 )
V_316 = V_360 ;
else
V_316 = V_360 | 0x40 ;
}
F_112 ( V_316 , ( V_2 -> V_126 + V_352 ) ) ;
return ( V_315 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
F_112 ( V_351 , ( V_2 -> V_126 + V_352 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_353 , ( V_2 -> V_126 + V_352 ) ) ;
F_132 ( 1000 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
F_112 ( V_362 , ( V_2 -> V_126 + V_363 ) ) ;
F_113 ( 10 ) ;
F_112 ( 0 , ( V_2 -> V_126 + V_363 ) ) ;
F_132 ( 1000 ) ;
F_112 ( 0x1 , V_2 -> V_126 ) ;
F_132 ( 1 ) ;
}
static void T_4 * F_143 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
void T_4 * V_315 ;
unsigned char V_316 ;
F_144 ( V_314 > V_2 -> V_317 ) ;
V_315 = V_2 -> V_318 + ( V_314 % V_364 ) ;
V_316 = ( unsigned char ) ( V_314 / V_364 ) ;
F_112 ( V_316 , ( V_2 -> V_126 + V_363 ) ) ;
return ( V_315 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_112 ( V_362 , ( V_2 -> V_126 + V_363 ) ) ;
F_113 ( 10 ) ;
F_112 ( 0 , ( V_2 -> V_126 + V_363 ) ) ;
F_132 ( 1000 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
F_112 ( 0x1 , V_2 -> V_126 ) ;
F_132 ( 1000 ) ;
}
static void T_4 * F_147 ( struct V_1 * V_2 , unsigned long V_314 , int line )
{
F_144 ( V_314 > V_2 -> V_317 ) ;
return V_2 -> V_318 + ( V_314 % V_365 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
V_49 T_4 * V_366 ;
V_366 = ( V_49 T_4 * ) ( V_2 -> V_318 + 0x30 ) ;
F_38 ( 0xffff0000 , V_366 ) ;
F_112 ( 0 , V_2 -> V_126 ) ;
F_132 ( 1000 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
T_9 V_367 ;
T_9 T_4 * V_368 ;
unsigned int V_201 , V_369 ;
char * V_17 ;
int V_370 , V_295 , V_38 ;
if ( ( V_2 -> V_126 == 0 ) || ( V_2 -> V_21 == 0 ) ) {
V_370 = - V_35 ;
goto V_371;
}
V_2 -> V_372 = V_373 ;
if ( ! F_150 ( V_2 -> V_126 , V_2 -> V_372 , L_25 ) ) {
V_370 = - V_87 ;
goto V_371;
}
switch ( V_2 -> V_19 ) {
case V_374 :
V_2 -> V_317 = V_375 ;
V_2 -> V_376 = V_319 ;
V_2 -> V_377 = F_111 ;
V_2 -> V_378 = F_114 ;
V_2 -> V_379 = F_114 ;
V_2 -> V_380 = F_115 ;
V_2 -> V_381 = F_116 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_117 ;
V_17 = L_26 ;
break;
case V_384 :
V_2 -> V_317 = V_375 ;
V_2 -> V_376 = V_332 ;
V_2 -> V_377 = F_119 ;
V_2 -> V_378 = F_120 ;
V_2 -> V_379 = F_120 ;
V_2 -> V_380 = F_121 ;
V_2 -> V_381 = F_122 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_123 ;
V_17 = L_27 ;
break;
case V_385 :
V_2 -> V_317 = V_375 ;
V_2 -> V_376 = V_336 ;
V_2 -> V_377 = NULL ;
V_2 -> V_378 = F_124 ;
V_2 -> V_379 = F_124 ;
V_2 -> V_380 = F_125 ;
V_2 -> V_381 = F_126 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_127 ;
V_17 = L_28 ;
break;
case V_386 :
V_2 -> V_317 = V_387 ;
V_2 -> V_376 = V_340 ;
V_2 -> V_377 = F_128 ;
V_2 -> V_378 = NULL ;
V_2 -> V_379 = NULL ;
V_2 -> V_380 = NULL ;
V_2 -> V_381 = F_129 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_130 ;
V_17 = L_29 ;
break;
default:
V_370 = - V_163 ;
goto V_388;
}
F_151 ( V_2 ) ;
V_2 -> V_318 = F_152 ( V_2 -> V_21 , V_2 -> V_317 ) ;
if ( V_2 -> V_318 == NULL ) {
V_370 = - V_389 ;
goto V_388;
}
F_36 ( V_2 ) ;
V_368 = ( T_9 T_4 * ) F_37 ( V_2 , V_390 ) ;
F_95 ( & V_367 , V_368 , sizeof( T_9 ) ) ;
F_41 ( V_2 ) ;
if ( V_367 . V_300 != F_153 ( V_391 ) ) {
V_370 = - V_35 ;
goto V_392;
}
for ( V_295 = 0 , V_369 = 0 ; ( V_295 < V_393 ) ; V_295 ++ ) {
V_201 = V_367 . V_394 [ V_369 ] ;
if ( ( V_201 & V_395 ) != V_369 )
break;
V_2 -> V_396 [ V_295 ] = V_201 ;
V_38 = ( V_201 & V_397 ) ? 16 : 8 ;
if ( ( V_38 == 16 ) && ( ( V_201 & V_398 ) == 0 ) )
V_369 ++ ;
V_2 -> V_305 [ V_295 ] = V_38 ;
V_2 -> V_38 += V_38 ;
V_369 ++ ;
V_2 -> V_399 ++ ;
}
F_30 ( V_400 , & V_2 -> V_37 ) ;
return 0 ;
V_392:
F_154 ( V_2 -> V_318 ) ;
V_2 -> V_318 = NULL ;
V_388:
F_155 ( V_2 -> V_126 , V_2 -> V_372 ) ;
V_371:
return V_370 ;
}
static int F_156 ( struct V_1 * V_2 )
{
T_10 V_367 ;
T_10 T_4 * V_368 ;
char * V_17 ;
int V_14 , V_370 ;
if ( V_2 -> V_126 == 0 || V_2 -> V_21 == 0 ) {
V_370 = - V_35 ;
goto V_371;
}
V_2 -> V_372 = V_401 ;
if ( ! F_150 ( V_2 -> V_126 , V_2 -> V_372 , L_25 ) ) {
V_370 = - V_87 ;
goto V_371;
}
switch ( V_2 -> V_19 ) {
case V_402 :
case V_403 :
V_2 -> V_317 = V_404 ;
V_2 -> V_376 = V_349 ;
V_2 -> V_377 = F_131 ;
V_2 -> V_378 = F_133 ;
V_2 -> V_379 = F_133 ;
V_2 -> V_380 = F_134 ;
V_2 -> V_381 = F_135 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_136 ;
if ( V_2 -> V_21 > 0x100000 )
V_2 -> V_347 = V_405 ;
else
V_2 -> V_347 = V_406 ;
V_17 = L_30 ;
break;
case V_407 :
V_2 -> V_317 = V_408 ;
V_2 -> V_376 = V_361 ;
V_2 -> V_377 = F_137 ;
V_2 -> V_378 = F_138 ;
V_2 -> V_379 = F_138 ;
V_2 -> V_380 = F_139 ;
V_2 -> V_381 = F_140 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_141 ;
V_17 = L_31 ;
break;
case V_409 :
V_2 -> V_317 = V_410 ;
V_2 -> V_376 = V_364 ;
V_2 -> V_377 = F_142 ;
V_2 -> V_378 = NULL ;
V_2 -> V_379 = NULL ;
V_2 -> V_380 = NULL ;
V_2 -> V_381 = F_143 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_145 ;
V_17 = L_32 ;
break;
case V_411 :
V_2 -> V_317 = V_412 ;
V_2 -> V_376 = V_365 ;
V_2 -> V_377 = F_146 ;
V_2 -> V_378 = NULL ;
V_2 -> V_379 = NULL ;
V_2 -> V_380 = NULL ;
V_2 -> V_381 = F_147 ;
V_2 -> V_382 = F_118 ;
V_2 -> V_383 = F_148 ;
V_17 = L_33 ;
break;
default:
V_370 = - V_163 ;
goto V_388;
}
F_151 ( V_2 ) ;
V_2 -> V_318 = F_152 ( V_2 -> V_21 , V_2 -> V_317 ) ;
if ( V_2 -> V_318 == NULL ) {
V_370 = - V_389 ;
goto V_388;
}
F_36 ( V_2 ) ;
V_368 = ( T_10 T_4 * ) F_37 ( V_2 , V_390 ) ;
F_95 ( & V_367 , V_368 , sizeof( T_10 ) ) ;
F_41 ( V_2 ) ;
if ( V_367 . V_413 != F_157 ( V_414 ) ||
V_367 . V_415 != F_157 ( V_416 ) ||
V_367 . V_417 != F_157 ( V_418 ) ||
V_367 . V_419 != F_157 ( V_420 ) ) {
V_370 = - V_35 ;
goto V_392;
}
V_2 -> V_399 = 1 ;
if ( V_367 . V_421 ) {
V_2 -> V_38 = 32 ;
} else {
for ( V_14 = 0 ; ( V_14 < 16 ) ; V_14 ++ ) {
if ( ( ( V_367 . V_422 << V_14 ) & 0x8000 ) == 0 )
break;
}
V_2 -> V_38 = V_14 ;
}
V_2 -> V_305 [ 0 ] = V_2 -> V_38 ;
F_30 ( V_400 , & V_2 -> V_37 ) ;
return 0 ;
V_392:
F_154 ( V_2 -> V_318 ) ;
V_2 -> V_318 = NULL ;
V_388:
F_155 ( V_2 -> V_126 , V_2 -> V_372 ) ;
V_371:
return V_370 ;
}
static int F_158 ( struct V_1 * V_2 )
{
T_3 T_4 * V_71 ;
T_11 T_4 * V_423 ;
V_77 T_4 * V_98 ;
unsigned long V_27 ;
unsigned int V_32 , V_227 , V_14 ;
struct V_3 * V_4 ;
int V_25 = 0 ;
V_49 V_424 ;
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_71 = ( T_3 T_4 * ) F_37 ( V_2 , V_82 ) ;
V_227 = V_71 -> V_227 ;
#if 0
printk("%s(%d): CDK version %d.%d.%d --> "
"nrdevs=%d memp=%x hostp=%x slavep=%x\n",
__FILE__, __LINE__, readb(&hdrp->ver_release), readb(&hdrp->ver_modification),
readb(&hdrp->ver_fix), nrdevs, (int) readl(&hdrp->memp), readl(&hdrp->hostp),
readl(&hdrp->slavep));
#endif
if ( V_227 < ( V_2 -> V_38 + 1 ) ) {
F_8 ( V_199 L_34
L_35 , V_227 ) ;
V_2 -> V_38 = V_227 - 1 ;
}
V_2 -> V_227 = V_227 ;
V_2 -> V_229 = V_71 -> V_425 - V_82 ;
V_2 -> V_83 = V_71 -> V_222 - V_82 ;
V_2 -> V_225 = ( V_227 + 7 ) / 8 ;
V_424 = F_52 ( & V_71 -> V_423 ) ;
if ( V_424 > V_2 -> V_317 ) {
F_8 ( V_199 L_36 ) ;
V_25 = - V_87 ;
goto V_426;
}
V_423 = ( T_11 T_4 * ) F_37 ( V_2 , V_424 ) ;
if ( F_48 ( & V_423 -> V_427 ) != V_428 ) {
F_8 ( V_199 L_37 ) ;
goto V_426;
}
V_423 ++ ;
for ( V_14 = 1 , V_32 = 0 ; ( V_14 < V_227 ) ; V_14 ++ , V_32 ++ , V_423 ++ ) {
if ( F_48 ( & V_423 -> V_427 ) != V_429 )
break;
V_4 = V_2 -> V_9 [ V_32 ] ;
if ( V_4 == NULL )
break;
V_4 -> V_39 = V_14 ;
V_4 -> V_78 = F_52 ( & V_423 -> V_314 ) ;
V_4 -> V_430 = ( unsigned char ) ( 0x1 << ( V_14 * 8 / V_227 ) ) ;
V_4 -> V_84 = ( unsigned char ) ( V_14 / 8 ) ;
V_4 -> V_85 = ( unsigned char ) ( 0x1 << ( V_14 % 8 ) ) ;
}
F_39 ( 0xff , & V_71 -> V_431 ) ;
for ( V_14 = 1 , V_32 = 0 ; ( V_14 < V_227 ) ; V_14 ++ , V_32 ++ ) {
V_4 = V_2 -> V_9 [ V_32 ] ;
if ( V_4 == NULL )
break;
if ( V_4 -> V_78 == 0 )
break;
V_98 = ( V_77 T_4 * ) F_37 ( V_2 , V_4 -> V_78 ) ;
if ( V_98 != NULL ) {
V_4 -> V_203 = F_48 ( & V_98 -> V_202 . V_91 ) ;
V_4 -> V_106 = F_48 ( & V_98 -> V_105 . V_91 ) ;
V_4 -> V_204 = F_52 ( & V_98 -> V_202 . V_314 ) ;
V_4 -> V_107 = F_52 ( & V_98 -> V_105 . V_314 ) ;
}
}
V_426:
F_41 ( V_2 ) ;
F_23 ( & V_76 , V_27 ) ;
if ( V_25 == 0 )
F_30 ( V_36 , & V_2 -> V_37 ) ;
if ( ! V_432 ) {
V_432 ++ ;
F_103 ( & V_230 , V_231 ) ;
}
return V_25 ;
}
static int T_12 F_159 ( struct V_1 * V_2 )
{
int V_370 ;
switch ( V_2 -> V_19 ) {
case V_374 :
case V_384 :
case V_385 :
case V_386 :
V_370 = F_149 ( V_2 ) ;
break;
case V_402 :
case V_407 :
case V_403 :
case V_409 :
case V_411 :
V_370 = F_156 ( V_2 ) ;
break;
default:
F_8 ( V_199 L_38
L_39 , V_2 -> V_24 , V_2 -> V_19 ) ;
V_370 = - V_35 ;
}
if ( V_370 )
return V_370 ;
F_107 ( V_2 ) ;
F_8 ( V_433 L_40
L_41 , V_434 [ V_2 -> V_19 ] ,
V_2 -> V_24 , V_2 -> V_126 , ( int ) V_2 -> V_21 ,
V_2 -> V_399 , V_2 -> V_38 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
T_9 V_435 , T_4 * V_436 ;
T_10 V_437 , T_4 * V_438 ;
int V_14 , V_439 ;
if ( V_2 -> V_19 == V_384 ) {
F_112 ( 0x1 , ( V_2 -> V_126 + V_321 ) ) ;
F_112 ( V_322 , ( V_2 -> V_126 + V_323 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_324 , ( V_2 -> V_126 + V_323 ) ) ;
F_113 ( 500 ) ;
F_120 ( V_2 ) ;
} else if ( V_2 -> V_19 == V_407 ) {
F_112 ( 0x1 , ( V_2 -> V_126 + V_350 ) ) ;
F_112 ( V_351 , ( V_2 -> V_126 + V_352 ) ) ;
F_113 ( 10 ) ;
F_112 ( V_353 , ( V_2 -> V_126 + V_352 ) ) ;
F_132 ( 100 ) ;
F_112 ( 0x1 , V_2 -> V_126 ) ;
F_132 ( 1 ) ;
F_138 ( V_2 ) ;
} else {
return - V_35 ;
}
V_439 = 0 ;
V_2 -> V_317 = V_375 ;
for ( V_14 = 0 ; ( V_14 < V_440 ) ; V_14 ++ ) {
V_2 -> V_21 = V_441 [ V_14 ] ;
V_2 -> V_318 = F_152 ( V_2 -> V_21 , V_2 -> V_317 ) ;
if ( V_2 -> V_318 == NULL )
continue;
if ( V_2 -> V_19 == V_384 ) {
V_436 = F_122 ( V_2 ,
V_390 , __LINE__ ) ;
F_95 ( & V_435 , V_436 , sizeof( T_9 ) ) ;
if ( V_435 . V_300 == F_153 ( V_391 ) )
V_439 = 1 ;
} else {
V_438 = ( T_10 T_4 * ) F_140 ( V_2 ,
V_390 , __LINE__ ) ;
F_95 ( & V_437 , V_438 , sizeof( T_10 ) ) ;
if ( ( V_437 . V_413 == F_157 ( V_414 ) ) &&
( V_437 . V_415 == F_157 ( V_416 ) ) &&
( V_437 . V_417 == F_157 ( V_418 ) ) &&
( V_437 . V_419 == F_157 ( V_420 ) ) )
V_439 = 1 ;
}
F_154 ( V_2 -> V_318 ) ;
if ( V_439 )
break;
}
if ( V_2 -> V_19 == V_384 )
F_121 ( V_2 ) ;
else
F_139 ( V_2 ) ;
if ( ! V_439 ) {
V_2 -> V_21 = 0 ;
V_2 -> V_318 = NULL ;
F_8 ( V_199 L_42
L_43 ,
V_434 [ V_2 -> V_19 ] , ( V_2 -> V_126 >> 12 ) ) ;
return - V_35 ;
}
return 0 ;
}
static int F_161 ( void )
{
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_442 ; V_14 ++ ) {
if ( ! V_23 [ V_14 ] ) {
if ( V_14 >= V_34 )
V_34 = V_14 + 1 ;
return V_14 ;
}
}
return - 1 ;
}
static int T_13 F_162 ( void )
{
struct V_1 * V_2 ;
unsigned int V_126 , V_443 , V_14 ;
int V_24 , V_444 = 0 ;
if ( V_445 )
return 0 ;
for ( V_126 = 0x1000 ; ( V_126 <= 0xc000 ) ; V_126 += 0x1000 ) {
F_112 ( 0xff , ( V_126 + 0xc80 ) ) ;
V_443 = F_163 ( V_126 + 0xc80 ) ;
V_443 |= F_163 ( V_126 + 0xc81 ) << 8 ;
if ( V_443 != V_446 )
continue;
for ( V_14 = 0 ; ( V_14 < V_442 ) ; V_14 ++ ) {
V_2 = V_23 [ V_14 ] ;
if ( V_2 == NULL )
continue;
if ( V_2 -> V_126 == V_126 )
break;
}
if ( V_14 < V_442 )
continue;
if ( ( V_2 = F_164 () ) == NULL )
return V_444 ? : - V_389 ;
V_24 = F_161 () ;
if ( V_24 < 0 )
return V_444 ? : - V_389 ;
V_2 -> V_24 = ( unsigned int ) V_24 ;
V_443 = F_163 ( V_126 + 0xc82 ) ;
if ( V_443 == V_447 )
V_2 -> V_19 = V_384 ;
else if ( V_443 == V_448 )
V_2 -> V_19 = V_407 ;
else
V_2 -> V_19 = V_449 ;
V_2 -> V_126 = V_126 ;
F_112 ( 0x1 , ( V_126 + 0xc84 ) ) ;
if ( F_160 ( V_2 ) )
F_112 ( 0 , ( V_126 + 0xc84 ) ) ;
if ( F_159 ( V_2 ) < 0 ) {
F_5 ( V_2 ) ;
continue;
}
V_23 [ V_2 -> V_24 ] = V_2 ;
V_444 ++ ;
for ( V_14 = 0 ; V_14 < V_2 -> V_38 ; V_14 ++ )
F_165 ( V_450 ,
V_2 -> V_24 * V_8 + V_14 , NULL ) ;
}
return V_444 ;
}
static inline int F_162 ( void ) { return 0 ; }
static int T_12 F_166 ( struct V_451 * V_452 ,
const struct V_453 * V_454 )
{
struct V_1 * V_2 ;
unsigned int V_14 ;
int V_24 , V_370 = - V_87 ;
V_370 = F_167 ( V_452 ) ;
if ( V_370 )
goto V_371;
V_2 = F_164 () ;
if ( V_2 == NULL ) {
V_370 = - V_389 ;
goto V_371;
}
F_168 ( & V_455 ) ;
V_24 = F_161 () ;
if ( V_24 < 0 ) {
F_8 ( V_433 L_44
L_45 , V_442 ) ;
F_169 ( & V_455 ) ;
V_370 = - V_87 ;
goto V_456;
}
V_2 -> V_24 = ( unsigned int ) V_24 ;
V_23 [ V_2 -> V_24 ] = V_2 ;
F_169 ( & V_455 ) ;
V_2 -> V_19 = V_386 ;
V_2 -> V_126 = F_170 ( V_452 , 3 ) ;
V_2 -> V_21 = F_170 ( V_452 , 2 ) ;
V_370 = F_159 ( V_2 ) ;
if ( V_370 )
goto V_457;
F_30 ( V_458 , & V_2 -> V_37 ) ;
F_171 ( V_452 , V_2 ) ;
F_36 ( V_2 ) ;
V_2 -> V_378 = NULL ;
V_2 -> V_380 = NULL ;
for ( V_14 = 0 ; V_14 < V_2 -> V_38 ; V_14 ++ )
F_165 ( V_450 , V_2 -> V_24 * V_8 + V_14 ,
& V_452 -> V_459 ) ;
return 0 ;
V_457:
V_23 [ V_2 -> V_24 ] = NULL ;
V_456:
F_5 ( V_2 ) ;
V_371:
return V_370 ;
}
static void T_14 F_172 ( struct V_451 * V_452 )
{
struct V_1 * V_2 = F_173 ( V_452 ) ;
F_1 ( V_2 ) ;
F_154 ( V_2 -> V_318 ) ;
if ( V_2 -> V_372 > 0 )
F_155 ( V_2 -> V_126 , V_2 -> V_372 ) ;
V_23 [ V_2 -> V_24 ] = NULL ;
F_5 ( V_2 ) ;
}
static struct V_1 * F_164 ( void )
{
struct V_1 * V_2 ;
V_2 = F_108 ( sizeof( struct V_1 ) , V_297 ) ;
if ( ! V_2 ) {
F_8 ( V_199 L_46
L_47 , sizeof( struct V_1 ) ) ;
return NULL ;
}
V_2 -> V_300 = V_460 ;
return V_2 ;
}
static int T_13 F_174 ( void )
{
struct V_1 * V_2 , * V_461 ;
struct V_11 V_462 ;
unsigned int V_14 , V_5 , V_444 = 0 ;
int V_370 ;
for ( V_34 = 0 ; V_34 < F_7 ( V_463 ) ;
V_34 ++ ) {
memset ( & V_462 , 0 , sizeof( V_462 ) ) ;
if ( F_6 ( & V_462 , V_463 [ V_34 ] ) == 0 )
continue;
if ( ( V_2 = F_164 () ) == NULL )
continue;
V_2 -> V_24 = V_34 ;
V_2 -> V_19 = V_462 . V_19 ;
V_2 -> V_126 = V_462 . V_20 ;
V_2 -> V_21 = V_462 . V_21 ;
if ( F_159 ( V_2 ) < 0 ) {
F_5 ( V_2 ) ;
continue;
}
V_23 [ V_2 -> V_24 ] = V_2 ;
V_444 ++ ;
for ( V_14 = 0 ; V_14 < V_2 -> V_38 ; V_14 ++ )
F_165 ( V_450 ,
V_2 -> V_24 * V_8 + V_14 , NULL ) ;
}
V_370 = F_162 () ;
if ( V_370 > 0 )
V_444 += V_370 ;
V_464 = 0 ;
if ( V_34 > 1 ) {
for ( V_14 = 0 ; ( V_14 < V_34 ) ; V_14 ++ ) {
V_2 = V_23 [ V_14 ] ;
if ( V_2 == NULL )
continue;
for ( V_5 = V_14 + 1 ; ( V_5 < V_34 ) ; V_5 ++ ) {
V_461 = V_23 [ V_5 ] ;
if ( V_461 == NULL )
continue;
if ( ( V_2 -> V_318 >= V_461 -> V_318 ) &&
( V_2 -> V_318 <= ( V_461 -> V_318 +
V_461 -> V_317 - 1 ) ) ) {
V_464 ++ ;
break;
}
}
}
}
if ( V_464 == 0 ) {
for ( V_14 = 0 ; ( V_14 < V_34 ) ; V_14 ++ ) {
V_2 = V_23 [ V_14 ] ;
if ( V_2 == NULL )
continue;
if ( F_17 ( V_400 , & V_2 -> V_37 ) ) {
F_36 ( V_2 ) ;
V_2 -> V_378 = NULL ;
V_2 -> V_380 = NULL ;
}
}
}
V_370 = F_175 ( & V_465 ) ;
if ( V_370 && V_444 == 0 ) {
F_8 ( V_199 L_48
L_49 ) ;
goto V_371;
}
return 0 ;
V_371:
return V_370 ;
}
static T_15 F_176 ( struct V_29 * V_466 , char T_7 * V_96 , T_16 V_97 , T_17 * V_467 )
{
unsigned long V_27 ;
void T_4 * V_468 ;
struct V_1 * V_2 ;
unsigned int V_24 ;
int V_91 , V_469 ;
void * V_470 ;
T_17 V_471 = * V_467 ;
V_24 = F_177 ( V_466 -> V_472 . V_473 -> V_474 ) ;
if ( V_24 >= V_34 )
return - V_35 ;
V_2 = V_23 [ V_24 ] ;
if ( V_2 == NULL )
return - V_35 ;
if ( V_2 -> V_37 == 0 )
return - V_35 ;
if ( V_471 >= V_2 -> V_317 || V_471 + V_97 < V_471 )
return 0 ;
V_91 = F_49 ( V_97 , ( T_16 ) ( V_2 -> V_317 - V_471 ) ) ;
V_470 = ( void * ) F_178 ( V_297 ) ;
if( V_470 == NULL )
return - V_389 ;
while ( V_91 > 0 ) {
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_468 = F_37 ( V_2 , V_471 ) ;
V_469 = F_49 ( V_91 , ( int ) ( V_2 -> V_376 - ( ( ( unsigned long ) V_471 ) % V_2 -> V_376 ) ) ) ;
V_469 = F_49 ( V_469 , ( int ) V_475 ) ;
F_95 ( V_470 , V_468 , V_469 ) ;
F_41 ( V_2 ) ;
F_23 ( & V_76 , V_27 ) ;
if ( F_57 ( V_96 , V_470 , V_469 ) ) {
V_97 = - V_127 ;
goto V_476;
}
V_471 += V_469 ;
V_96 += V_469 ;
V_91 -= V_469 ;
}
V_476:
* V_467 = V_471 ;
F_179 ( ( unsigned long ) V_470 ) ;
return V_97 ;
}
static T_15 F_180 ( struct V_29 * V_466 , const char T_7 * V_96 , T_16 V_97 , T_17 * V_467 )
{
unsigned long V_27 ;
void T_4 * V_468 ;
struct V_1 * V_2 ;
char T_7 * V_100 ;
unsigned int V_24 ;
int V_91 , V_469 ;
void * V_470 ;
T_17 V_471 = * V_467 ;
V_24 = F_177 ( V_466 -> V_472 . V_473 -> V_474 ) ;
if ( V_24 >= V_34 )
return - V_35 ;
V_2 = V_23 [ V_24 ] ;
if ( V_2 == NULL )
return - V_35 ;
if ( V_2 -> V_37 == 0 )
return - V_35 ;
if ( V_471 >= V_2 -> V_317 || V_471 + V_97 < V_471 )
return 0 ;
V_100 = ( char T_7 * ) V_96 ;
V_91 = F_49 ( V_97 , ( T_16 ) ( V_2 -> V_317 - V_471 ) ) ;
V_470 = ( void * ) F_178 ( V_297 ) ;
if( V_470 == NULL )
return - V_389 ;
while ( V_91 > 0 ) {
V_469 = F_49 ( V_91 , ( int ) ( V_2 -> V_376 - ( ( ( unsigned long ) V_471 ) % V_2 -> V_376 ) ) ) ;
V_469 = F_49 ( V_469 , ( int ) V_475 ) ;
if ( F_59 ( V_470 , V_100 , V_469 ) ) {
if ( V_97 == 0 )
V_97 = - V_127 ;
goto V_476;
}
F_22 ( & V_76 , V_27 ) ;
F_36 ( V_2 ) ;
V_468 = F_37 ( V_2 , V_471 ) ;
F_50 ( V_468 , V_470 , V_469 ) ;
F_41 ( V_2 ) ;
F_23 ( & V_76 , V_27 ) ;
V_471 += V_469 ;
V_100 += V_469 ;
V_91 -= V_469 ;
}
V_476:
F_179 ( ( unsigned long ) V_470 ) ;
* V_467 = V_471 ;
return V_97 ;
}
static int F_181 ( T_18 T_7 * V_477 )
{
struct V_1 * V_2 ;
unsigned int V_14 ;
T_18 V_478 ;
if ( F_59 ( & V_478 , V_477 , sizeof( T_18 ) ) )
return - V_127 ;
if ( V_478 . V_479 >= V_442 )
return - V_35 ;
V_2 = V_23 [ V_478 . V_479 ] ;
if ( V_2 == NULL )
return - V_35 ;
memset ( & V_478 , 0 , sizeof( T_18 ) ) ;
V_478 . V_479 = V_2 -> V_24 ;
V_478 . type = V_2 -> V_19 ;
V_478 . V_183 = 0 ;
V_478 . V_37 = V_2 -> V_37 ;
V_478 . V_480 = V_2 -> V_126 ;
V_478 . V_21 = V_2 -> V_21 ;
V_478 . V_399 = V_2 -> V_399 ;
V_478 . V_38 = V_2 -> V_38 ;
for ( V_14 = 0 ; ( V_14 < V_2 -> V_399 ) ; V_14 ++ ) {
V_478 . V_305 [ V_14 ] . V_481 = V_14 ;
V_478 . V_305 [ V_14 ] . V_183 = V_2 -> V_396 [ V_14 ] ;
V_478 . V_305 [ V_14 ] . V_38 = V_2 -> V_305 [ V_14 ] ;
}
if ( F_57 ( V_477 , & V_478 , sizeof( T_18 ) ) )
return - V_127 ;
return 0 ;
}
static struct V_3 * F_182 ( unsigned int V_24 , unsigned int V_295 ,
unsigned int V_32 )
{
struct V_1 * V_2 ;
unsigned int V_14 ;
if ( V_24 >= V_442 )
return NULL ;
V_2 = V_23 [ V_24 ] ;
if ( V_2 == NULL )
return NULL ;
for ( V_14 = 0 ; ( V_14 < V_295 ) ; V_14 ++ )
V_32 += V_2 -> V_305 [ V_14 ] ;
if ( V_32 >= V_2 -> V_38 )
return NULL ;
return V_2 -> V_9 [ V_32 ] ;
}
static int F_86 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
unsigned long V_27 ;
struct V_1 * V_2 ;
int V_25 ;
memset ( & V_182 , 0 , sizeof( V_482 ) ) ;
if ( V_4 == NULL )
return - V_35 ;
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( V_2 == NULL )
return - V_35 ;
F_168 ( & V_4 -> V_10 . V_483 ) ;
if ( F_17 ( V_36 , & V_2 -> V_37 ) ) {
if ( ( V_25 = F_24 ( V_2 , V_4 , V_484 ,
& V_485 , sizeof( V_486 ) , 1 ) ) < 0 ) {
F_169 ( & V_4 -> V_10 . V_483 ) ;
return V_25 ;
}
} else {
memset ( & V_485 , 0 , sizeof( V_486 ) ) ;
}
V_182 . V_479 = V_4 -> V_24 ;
V_182 . V_481 = V_4 -> V_295 ;
V_182 . V_10 = V_4 -> V_32 ;
V_182 . V_37 = V_4 -> V_37 ;
V_182 . V_27 = V_4 -> V_10 . V_27 ;
F_22 ( & V_76 , V_27 ) ;
if ( V_7 != NULL ) {
if ( V_4 -> V_10 . V_7 == V_7 ) {
V_182 . V_487 = V_7 -> V_27 ;
V_182 . V_488 = - 1 ;
if ( V_7 -> V_60 != NULL ) {
V_182 . V_489 = V_7 -> V_60 -> V_155 ;
V_182 . V_490 = V_7 -> V_60 -> V_259 ;
V_182 . V_491 = V_7 -> V_60 -> V_492 ;
V_182 . V_493 = V_7 -> V_60 -> V_494 ;
}
}
}
F_23 ( & V_76 , V_27 ) ;
V_182 . V_185 = V_485 . V_495 ;
V_182 . V_186 = V_485 . V_496 + V_485 . V_497 ;
V_182 . V_498 = V_485 . V_499 ;
V_182 . V_488 += V_485 . V_500 ;
V_182 . V_190 = V_485 . V_501 ;
V_182 . V_188 = V_485 . V_255 ;
V_182 . V_187 = V_485 . V_502 ;
V_182 . V_503 = V_485 . V_497 ;
V_182 . V_189 = V_485 . V_189 ;
V_182 . V_504 = V_485 . V_504 ;
V_182 . V_505 = V_485 . V_506 ;
V_182 . V_507 = V_485 . V_508 ;
V_182 . V_509 = V_485 . V_510 ;
V_182 . V_511 = V_485 . V_512 ;
V_182 . V_513 = V_485 . V_514 / 2 ;
V_182 . V_515 = V_485 . V_514 - V_182 . V_513 ;
V_182 . V_516 = V_485 . V_517 ;
V_182 . V_183 = V_485 . V_183 ;
V_182 . V_191 = F_32 ( V_485 . V_191 ) ;
F_169 ( & V_4 -> V_10 . V_483 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 , struct V_3 * V_4 ,
V_482 T_7 * V_72 )
{
struct V_1 * V_2 ;
int V_25 ;
if ( ! V_4 ) {
if ( F_59 ( & V_182 , V_72 , sizeof( V_482 ) ) )
return - V_127 ;
V_4 = F_182 ( V_182 . V_479 , V_182 . V_481 ,
V_182 . V_10 ) ;
if ( ! V_4 )
return - V_35 ;
}
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( ! V_2 )
return - V_35 ;
if ( ( V_25 = F_86 ( V_7 , V_4 ) ) < 0 )
return V_25 ;
return F_57 ( V_72 , & V_182 , sizeof( V_482 ) ) ?
- V_127 : 0 ;
}
static int F_67 ( struct V_3 * V_4 , V_482 T_7 * V_72 )
{
struct V_1 * V_2 ;
int V_25 ;
if ( ! V_4 ) {
if ( F_59 ( & V_182 , V_72 , sizeof( V_482 ) ) )
return - V_127 ;
V_4 = F_182 ( V_182 . V_479 , V_182 . V_481 ,
V_182 . V_10 ) ;
if ( ! V_4 )
return - V_35 ;
}
V_2 = V_23 [ V_4 -> V_24 ] ;
if ( ! V_2 )
return - V_35 ;
F_168 ( & V_4 -> V_10 . V_483 ) ;
if ( F_17 ( V_36 , & V_2 -> V_37 ) ) {
if ( ( V_25 = F_24 ( V_2 , V_4 , V_518 , NULL , 0 , 0 ) ) < 0 ) {
F_169 ( & V_4 -> V_10 . V_483 ) ;
return V_25 ;
}
}
memset ( & V_182 , 0 , sizeof( V_482 ) ) ;
V_182 . V_479 = V_4 -> V_24 ;
V_182 . V_481 = V_4 -> V_295 ;
V_182 . V_10 = V_4 -> V_32 ;
F_169 ( & V_4 -> V_10 . V_483 ) ;
if ( F_57 ( V_72 , & V_182 , sizeof( V_482 ) ) )
return - V_127 ;
return 0 ;
}
static int F_183 ( struct V_3 T_7 * V_69 )
{
struct V_3 V_519 ;
struct V_3 * V_4 ;
if ( F_59 ( & V_519 , V_69 , sizeof( struct V_3 ) ) )
return - V_127 ;
V_4 = F_182 ( V_519 . V_24 , V_519 . V_295 ,
V_519 . V_32 ) ;
if ( ! V_4 )
return - V_35 ;
if ( F_57 ( V_69 , V_4 , sizeof( struct V_3 ) ) )
return - V_127 ;
return 0 ;
}
static int F_184 ( struct V_1 T_7 * V_69 )
{
struct V_1 V_520 ;
struct V_1 * V_2 ;
if ( F_59 ( & V_520 , V_69 , sizeof( struct V_1 ) ) )
return - V_127 ;
if ( V_520 . V_24 >= V_442 )
return - V_35 ;
V_2 = V_23 [ V_520 . V_24 ] ;
if ( ! V_2 )
return - V_35 ;
if ( F_57 ( V_69 , V_2 , sizeof( struct V_1 ) ) )
return - V_127 ;
return 0 ;
}
static long F_185 ( struct V_29 * V_466 , unsigned int V_90 , unsigned long V_69 )
{
struct V_1 * V_2 ;
int V_24 , V_25 , V_521 ;
void T_7 * V_13 = ( void T_7 * ) V_69 ;
V_521 = 0 ;
V_25 = 0 ;
switch ( V_90 ) {
case V_139 :
V_25 = F_66 ( NULL , NULL , V_13 ) ;
V_521 ++ ;
break;
case V_140 :
V_25 = F_67 ( NULL , V_13 ) ;
V_521 ++ ;
break;
case V_522 :
V_25 = F_181 ( V_13 ) ;
V_521 ++ ;
break;
case V_523 :
V_25 = F_183 ( V_13 ) ;
V_521 ++ ;
break;
case V_524 :
V_25 = F_184 ( V_13 ) ;
V_521 ++ ;
break;
}
if ( V_521 )
return V_25 ;
V_24 = F_177 ( V_466 -> V_525 -> V_474 ) ;
if ( V_24 >= V_442 )
return - V_35 ;
V_2 = V_23 [ V_24 ] ;
if ( ! V_2 )
return - V_35 ;
if ( V_2 -> V_37 == 0 )
return - V_35 ;
switch ( V_90 ) {
case V_526 :
F_186 ( V_2 ) ;
break;
case V_527 :
V_25 = F_158 ( V_2 ) ;
break;
case V_528 :
F_13 ( V_36 , & V_2 -> V_37 ) ;
break;
case V_529 :
F_13 ( V_36 , & V_2 -> V_37 ) ;
F_187 ( V_2 ) ;
if ( V_464 == 0 ) {
if ( V_2 -> V_379 != NULL )
(* V_2 -> V_379 )( V_2 ) ;
}
break;
default:
V_25 = - V_151 ;
break;
}
return V_25 ;
}
static void F_188 ( void )
{
struct V_1 * V_2 ;
unsigned int V_5 ;
for ( V_5 = 0 ; ( V_5 < V_34 ) ; V_5 ++ ) {
if ( ( V_2 = V_23 [ V_5 ] ) == NULL ||
F_17 ( V_458 , & V_2 -> V_37 ) )
continue;
F_1 ( V_2 ) ;
F_154 ( V_2 -> V_318 ) ;
if ( V_2 -> V_372 > 0 )
F_155 ( V_2 -> V_126 , V_2 -> V_372 ) ;
F_5 ( V_2 ) ;
V_23 [ V_5 ] = NULL ;
}
}
static int T_13 F_189 ( void )
{
unsigned int V_14 ;
int V_370 ;
F_8 ( V_433 L_19 , V_196 , V_197 ) ;
F_190 ( & V_43 ) ;
F_190 ( & V_76 ) ;
V_110 = F_191 ( V_530 , V_297 ) ;
if ( ! V_110 ) {
F_8 ( V_199 L_46
L_50 , V_530 ) ;
V_370 = - V_389 ;
goto V_371;
}
V_450 = F_192 ( V_442 * V_8 ) ;
if ( ! V_450 ) {
V_370 = - V_389 ;
goto V_531;
}
V_450 -> V_532 = V_533 ;
V_450 -> V_534 = V_535 ;
V_450 -> V_17 = V_536 ;
V_450 -> V_537 = V_538 ;
V_450 -> V_539 = 0 ;
V_450 -> type = V_540 ;
V_450 -> V_541 = V_542 ;
V_450 -> V_543 = V_544 ;
V_450 -> V_27 = V_545 | V_546 ;
F_193 ( V_450 , & V_547 ) ;
V_370 = F_194 ( V_450 ) ;
if ( V_370 ) {
F_8 ( V_199 L_51 ) ;
goto V_548;
}
V_370 = F_174 () ;
if ( V_370 )
goto V_549;
V_370 = F_195 ( V_550 , L_52 , & V_551 ) ;
if ( V_370 ) {
F_8 ( V_199 L_53
L_54 ) ;
goto V_552;
}
V_553 = F_196 ( V_533 , L_52 ) ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ )
F_197 ( V_553 , NULL , F_198 ( V_550 , V_14 ) ,
NULL , L_55 , V_14 ) ;
return 0 ;
V_552:
F_199 ( & V_465 ) ;
F_188 () ;
V_549:
F_200 ( V_450 ) ;
V_548:
F_201 ( V_450 ) ;
V_531:
F_5 ( V_110 ) ;
V_371:
return V_370 ;
}
static void T_19 F_202 ( void )
{
unsigned int V_5 ;
F_8 ( V_433 L_56 , V_196 ,
V_197 ) ;
if ( V_432 ) {
V_432 = 0 ;
F_203 ( & V_230 ) ;
}
F_204 ( V_550 , L_52 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ )
F_205 ( V_553 , F_198 ( V_550 , V_5 ) ) ;
F_206 ( V_553 ) ;
F_199 ( & V_465 ) ;
F_188 () ;
F_200 ( V_450 ) ;
F_201 ( V_450 ) ;
F_5 ( V_110 ) ;
}
