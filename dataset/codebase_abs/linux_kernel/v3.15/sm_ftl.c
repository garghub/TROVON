static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
strncpy ( V_5 , V_7 -> V_9 , V_7 -> V_10 ) ;
return V_7 -> V_10 ;
}
static struct V_11 * F_3 ( struct V_12 * V_13 )
{
struct V_11 * V_14 ;
struct V_15 * * V_16 ;
struct V_6 * V_17 ;
char * V_18 ;
V_18 = F_4 ( V_13 -> V_19 + V_20 ,
V_21 - V_20 , V_22 ) ;
if ( ! V_18 )
goto V_23;
V_17 =
F_5 ( sizeof( struct V_6 ) , V_22 ) ;
if ( ! V_17 )
goto V_24;
F_6 ( & V_17 -> V_8 . V_4 ) ;
V_17 -> V_9 = V_18 ;
V_17 -> V_10 = strlen ( V_18 ) ;
V_17 -> V_8 . V_4 . V_25 = L_1 ;
V_17 -> V_8 . V_4 . V_26 = V_27 ;
V_17 -> V_8 . V_28 = F_1 ;
V_16 = F_5 ( sizeof( struct V_15 * ) * ( V_29 + 1 ) ,
V_22 ) ;
if ( ! V_16 )
goto V_30;
V_16 [ 0 ] = & V_17 -> V_8 . V_4 ;
V_14 = F_5 ( sizeof( struct V_11 ) , V_22 ) ;
if ( ! V_14 )
goto V_31;
V_14 -> V_32 = V_16 ;
return V_14 ;
V_31:
F_7 ( V_16 ) ;
V_30:
F_7 ( V_17 ) ;
V_24:
F_7 ( V_18 ) ;
V_23:
return NULL ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_15 * * V_16 = V_13 -> V_33 -> V_32 ;
int V_34 ;
for ( V_34 = 0 ; V_16 [ V_34 ] ; V_34 ++ ) {
struct V_3 * V_8 = F_2 ( V_16 [ V_34 ] ,
struct V_3 , V_4 ) ;
struct V_6 * V_7 =
F_2 ( V_8 ,
struct V_6 , V_8 ) ;
F_7 ( V_7 -> V_9 ) ;
F_7 ( V_7 ) ;
}
F_7 ( V_13 -> V_33 -> V_32 ) ;
F_7 ( V_13 -> V_33 ) ;
}
static int F_9 ( T_2 * V_35 )
{
if ( ( V_35 [ 0 ] & 0xF8 ) != 0x10 )
return - 2 ;
if ( F_10 ( * ( V_36 * ) V_35 ) & 1 )
return - 2 ;
return ( V_35 [ 1 ] >> 1 ) | ( ( V_35 [ 0 ] & 0x07 ) << 7 ) ;
}
static int F_11 ( struct V_37 * V_38 )
{
static const T_3 V_39 [ 4 ] = {
0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF } ;
V_36 V_40 ;
int V_35 ;
if ( ! memcmp ( V_38 , V_39 , V_41 ) )
return - 1 ;
V_40 = * ( V_36 * ) V_38 -> V_42 ^ * ( V_36 * ) V_38 -> V_43 ;
if ( V_40 && ! F_12 ( V_40 ) )
return - 2 ;
V_35 = F_9 ( V_38 -> V_42 ) ;
if ( V_35 == - 2 )
V_35 = F_9 ( V_38 -> V_43 ) ;
return V_35 ;
}
static void F_13 ( struct V_37 * V_38 , V_36 V_35 )
{
T_2 V_44 [ 2 ] ;
F_14 ( V_35 >= 1000 ) ;
V_44 [ 0 ] = 0x10 | ( ( V_35 >> 7 ) & 0x07 ) ;
V_44 [ 1 ] = ( V_35 << 1 ) & 0xFF ;
if ( F_10 ( * ( V_36 * ) V_44 ) & 0x01 )
V_44 [ 1 ] |= 1 ;
V_38 -> V_42 [ 0 ] = V_38 -> V_43 [ 0 ] = V_44 [ 0 ] ;
V_38 -> V_42 [ 1 ] = V_38 -> V_43 [ 1 ] = V_44 [ 1 ] ;
}
static T_4 F_15 ( struct V_12 * V_13 , int V_45 , int V_46 , int V_47 )
{
F_14 ( V_47 & ( V_48 - 1 ) ) ;
F_14 ( V_45 < 0 || V_45 >= V_13 -> V_49 ) ;
F_14 ( V_46 >= V_13 -> V_50 ) ;
F_14 ( V_47 >= V_13 -> V_51 ) ;
if ( V_46 == - 1 )
return - 1 ;
return ( V_45 * V_52 + V_46 ) * V_13 -> V_51 + V_47 ;
}
static void F_16 ( struct V_12 * V_13 , T_4 V_53 ,
int * V_45 , int * V_46 , int * V_47 )
{
* V_47 = F_17 ( V_53 , V_13 -> V_51 ) ;
* V_46 = F_17 ( V_53 , V_13 -> V_54 ) ;
* V_45 = V_53 >= V_13 -> V_49 ? - 1 : V_53 ;
}
static int F_18 ( T_2 * V_55 , struct V_37 * V_38 )
{
T_2 V_56 [ 3 ] ;
F_19 ( V_55 , V_21 , V_56 ) ;
if ( F_20 ( V_55 , V_56 , V_38 -> V_57 , V_21 ) < 0 )
return - V_58 ;
V_55 += V_21 ;
F_19 ( V_55 , V_21 , V_56 ) ;
if ( F_20 ( V_55 , V_56 , V_38 -> V_59 , V_21 ) < 0 )
return - V_58 ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 ,
int V_45 , int V_46 , int V_47 ,
T_2 * V_55 , struct V_37 * V_38 )
{
struct V_60 * V_61 = V_13 -> V_62 -> V_61 ;
struct V_63 V_64 ;
struct V_37 V_65 ;
int V_66 = - V_58 ;
int V_67 = 0 ;
if ( V_46 == - 1 ) {
memset ( V_55 , 0xFF , V_48 ) ;
return 0 ;
}
if ( ! V_38 )
V_38 = & V_65 ;
V_64 . V_26 = V_13 -> V_68 ? V_69 : V_70 ;
V_64 . V_71 = 0 ;
V_64 . V_72 = V_41 ;
V_64 . V_73 = ( void * ) V_38 ;
V_64 . V_10 = V_48 ;
V_64 . V_74 = V_55 ;
V_75:
if ( V_67 ++ ) {
if ( V_45 == 0 && V_46 == V_13 -> V_76 && V_47 ==
V_13 -> V_77 )
return V_66 ;
if ( V_67 == 3 || F_22 ( V_13 ) )
return V_66 ;
}
V_66 = F_23 ( V_61 , F_15 ( V_13 , V_45 , V_46 , V_47 ) , & V_64 ) ;
if ( V_66 != 0 && ! F_24 ( V_66 ) ) {
F_25 ( L_2 ,
V_46 , V_45 , V_66 ) ;
goto V_75;
}
if ( V_38 -> V_78 != 0xFFFFFFFF && ! F_12 ( ~ V_38 -> V_78 ) )
goto V_75;
F_14 ( V_64 . V_79 != V_41 ) ;
F_14 ( V_55 && V_64 . V_80 != V_48 ) ;
if ( ! V_55 )
return 0 ;
if ( ! F_26 ( V_38 ) ) {
F_25 ( L_3
L_4 , V_46 , V_45 ) ;
goto V_75;
}
if ( F_27 ( V_66 ) ||
( V_13 -> V_68 && F_18 ( V_55 , V_38 ) ) ) {
F_25 ( L_5 ,
V_46 , V_45 ) ;
goto V_75;
}
return 0 ;
}
static int F_28 ( struct V_12 * V_13 ,
int V_45 , int V_46 , int V_47 ,
T_2 * V_55 , struct V_37 * V_38 )
{
struct V_63 V_64 ;
struct V_60 * V_61 = V_13 -> V_62 -> V_61 ;
int V_66 ;
F_29 ( V_13 -> V_81 ) ;
if ( V_45 == 0 && ( V_46 == V_13 -> V_76 || V_46 == 0 ) ) {
F_25 ( L_6 ) ;
return - V_58 ;
}
if ( V_13 -> V_82 )
return - V_58 ;
V_64 . V_26 = V_13 -> V_68 ? V_69 : V_70 ;
V_64 . V_10 = V_48 ;
V_64 . V_74 = V_55 ;
V_64 . V_71 = 0 ;
V_64 . V_72 = V_41 ;
V_64 . V_73 = ( void * ) V_38 ;
V_66 = F_30 ( V_61 , F_15 ( V_13 , V_45 , V_46 , V_47 ) , & V_64 ) ;
if ( V_66 ) {
F_25 ( L_7 ,
V_46 , V_45 , V_66 ) ;
F_22 ( V_13 ) ;
return V_66 ;
}
F_14 ( V_64 . V_79 != V_41 ) ;
F_14 ( V_55 && V_64 . V_80 != V_48 ) ;
return 0 ;
}
static int F_31 ( struct V_12 * V_13 , T_2 * V_5 ,
int V_45 , int V_46 , int V_35 ,
unsigned long V_83 )
{
struct V_37 V_38 ;
int V_47 ;
int V_84 = 0 ;
memset ( & V_38 , 0xFF , V_41 ) ;
F_13 ( & V_38 , V_35 ) ;
V_85:
if ( V_13 -> V_82 )
return - V_58 ;
for ( V_47 = 0 ; V_47 < V_13 -> V_51 ;
V_47 += V_48 ) {
V_38 . V_86 = 0xFF ;
if ( F_32 ( V_47 / V_48 , & V_83 ) ) {
F_33 ( L_8
L_9 ,
V_47 / V_48 , V_35 , V_45 ) ;
V_38 . V_86 = 0 ;
}
if ( V_13 -> V_68 ) {
F_19 ( V_5 + V_47 ,
V_21 , V_38 . V_57 ) ;
F_19 ( V_5 + V_47 + V_21 ,
V_21 , V_38 . V_59 ) ;
}
if ( ! F_28 ( V_13 , V_45 , V_46 , V_47 ,
V_5 + V_47 , & V_38 ) )
continue;
if ( ! V_84 ) {
if ( F_34 ( V_13 , V_45 , V_46 , 0 ) )
return - V_58 ;
V_84 = 1 ;
goto V_85;
} else {
F_35 ( V_13 , V_45 , V_46 ) ;
return - V_58 ;
}
}
return 0 ;
}
static void F_35 ( struct V_12 * V_13 , int V_45 , int V_46 )
{
struct V_37 V_38 ;
int V_47 ;
memset ( & V_38 , 0xFF , V_41 ) ;
V_38 . V_87 = 0xF0 ;
if ( V_13 -> V_82 )
return;
if ( F_22 ( V_13 ) )
return;
F_33 ( L_10 , V_46 , V_45 ) ;
for ( V_47 = 0 ; V_47 < V_13 -> V_51 ; V_47 += V_48 )
F_28 ( V_13 , V_45 , V_46 , V_47 , NULL , & V_38 ) ;
}
static int F_34 ( struct V_12 * V_13 , int V_88 , V_36 V_46 ,
int V_89 )
{
struct V_90 * V_45 = & V_13 -> V_91 [ V_88 ] ;
struct V_60 * V_61 = V_13 -> V_62 -> V_61 ;
struct V_92 V_93 ;
V_93 . V_61 = V_61 ;
V_93 . V_94 = V_95 ;
V_93 . V_96 = F_15 ( V_13 , V_88 , V_46 , 0 ) ;
V_93 . V_10 = V_13 -> V_51 ;
V_93 . V_97 = ( V_98 ) V_13 ;
if ( V_13 -> V_82 )
return - V_58 ;
F_29 ( V_13 -> V_81 ) ;
if ( V_88 == 0 && ( V_46 == V_13 -> V_76 || V_46 == 0 ) ) {
F_33 ( L_11 ) ;
return - V_58 ;
}
if ( F_36 ( V_61 , & V_93 ) ) {
F_33 ( L_12 ,
V_46 , V_88 ) ;
goto error;
}
if ( V_93 . V_99 == V_100 )
F_37 ( & V_13 -> V_101 ) ;
if ( V_93 . V_99 != V_102 ) {
F_33 ( L_13 ,
V_46 , V_88 ) ;
goto error;
}
if ( V_89 )
F_38 ( & V_45 -> V_103 ,
( const unsigned char * ) & V_46 , sizeof( V_46 ) ) ;
return 0 ;
error:
F_35 ( V_13 , V_88 , V_46 ) ;
return - V_58 ;
}
static void V_95 ( struct V_92 * V_104 )
{
struct V_12 * V_13 = (struct V_12 * ) V_104 -> V_97 ;
F_39 ( & V_13 -> V_101 ) ;
}
static int F_40 ( struct V_12 * V_13 , int V_45 , int V_46 )
{
int V_47 ;
struct V_37 V_38 ;
int V_105 [] = { - 3 , 0 , 0 , 0 } ;
int V_34 = 0 ;
int V_106 ;
for ( V_47 = 0 ; V_47 < V_13 -> V_51 ;
V_47 += V_48 ) {
if ( F_21 ( V_13 , V_45 , V_46 , V_47 , NULL , & V_38 ) )
return - 2 ;
V_106 = F_11 ( & V_38 ) ;
if ( V_105 [ V_34 ] != V_106 )
V_105 [ ++ V_34 ] = V_106 ;
if ( V_34 == 3 )
return - V_58 ;
}
if ( V_34 == 2 ) {
F_34 ( V_13 , V_45 , V_46 , 1 ) ;
return 1 ;
}
return 0 ;
}
static int F_41 ( struct V_12 * V_13 , struct V_60 * V_61 )
{
int V_34 ;
int V_107 = V_61 -> V_108 / ( 1024 * 1024 ) ;
V_13 -> V_81 = V_61 -> type == V_109 ;
V_13 -> V_49 = 1 ;
V_13 -> V_68 = 0 ;
switch ( V_107 ) {
case 1 :
V_13 -> V_50 = 256 ;
V_13 -> V_54 = 250 ;
V_13 -> V_51 = 8 * V_48 ;
V_13 -> V_68 = 1 ;
break;
case 2 :
if ( V_61 -> V_110 == V_21 ) {
V_13 -> V_50 = 512 ;
V_13 -> V_54 = 500 ;
V_13 -> V_51 = 8 * V_48 ;
V_13 -> V_68 = 1 ;
} else {
if ( ! V_13 -> V_81 )
return - V_111 ;
V_13 -> V_50 = 256 ;
V_13 -> V_54 = 250 ;
V_13 -> V_51 = 16 * V_48 ;
}
break;
case 4 :
V_13 -> V_50 = 512 ;
V_13 -> V_54 = 500 ;
V_13 -> V_51 = 16 * V_48 ;
break;
case 8 :
V_13 -> V_50 = 1024 ;
V_13 -> V_54 = 1000 ;
V_13 -> V_51 = 16 * V_48 ;
}
if ( V_107 >= 16 ) {
V_13 -> V_49 = V_107 / 16 ;
V_13 -> V_50 = 1024 ;
V_13 -> V_54 = 1000 ;
V_13 -> V_51 = 32 * V_48 ;
}
if ( V_61 -> V_112 > V_13 -> V_51 )
return - V_111 ;
if ( V_61 -> V_110 > V_48 )
return - V_111 ;
if ( V_13 -> V_68 && V_61 -> V_113 < V_114 )
return - V_111 ;
if ( ! V_13 -> V_68 && V_61 -> V_113 < V_41 )
return - V_111 ;
if ( ! F_42 ( V_61 ) )
return - V_111 ;
for ( V_34 = 0 ; V_34 < F_43 ( V_115 ) ; V_34 ++ ) {
if ( V_115 [ V_34 ] . V_108 == V_107 ) {
V_13 -> V_116 = V_115 [ V_34 ] . V_117 ;
V_13 -> V_118 = V_115 [ V_34 ] . V_119 ;
V_13 -> V_120 = V_115 [ V_34 ] . V_121 ;
return 0 ;
}
}
F_33 ( L_14 , V_107 ) ;
V_13 -> V_116 = 985 ;
V_13 -> V_118 = 33 ;
V_13 -> V_120 = 63 ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 )
{
struct V_37 V_38 ;
if ( F_21 ( V_13 ,
0 , V_13 -> V_76 , V_13 -> V_77 , V_13 -> V_19 , & V_38 ) )
return - V_58 ;
if ( ! F_26 ( & V_38 ) || ! F_45 ( & V_38 ) )
return - V_58 ;
if ( ! memcmp ( V_13 -> V_19 + V_13 -> V_122 ,
V_123 , sizeof( V_123 ) ) ) {
return 0 ;
}
return - V_58 ;
}
static int F_46 ( struct V_12 * V_13 )
{
struct V_37 V_38 ;
int V_46 , V_47 ;
int V_124 = 0 ;
int V_125 = 0 ;
for ( V_46 = 0 ; V_46 < V_13 -> V_50 - V_13 -> V_54 ; V_46 ++ ) {
if ( F_21 ( V_13 , 0 , V_46 , 0 , NULL , & V_38 ) )
continue;
if ( ! F_45 ( & V_38 ) )
continue;
V_124 = 1 ;
break;
}
if ( ! V_124 )
return - V_58 ;
for ( V_47 = 0 ; V_47 < V_13 -> V_51 ;
V_47 += V_48 ) {
if ( F_21 ( V_13 , 0 , V_46 , V_47 , NULL , & V_38 ) )
continue;
if ( ! F_26 ( & V_38 ) )
continue;
break;
}
if ( V_47 == V_13 -> V_51 )
return - V_58 ;
V_13 -> V_76 = V_46 ;
V_13 -> V_77 = V_47 ;
V_13 -> V_122 = 0 ;
V_125 = ! F_44 ( V_13 ) ;
if ( ! V_125 ) {
V_13 -> V_122 = V_21 ;
V_125 = ! F_44 ( V_13 ) ;
}
if ( V_125 ) {
F_25 ( L_15 ,
V_46 * V_13 -> V_51 +
V_47 + V_13 -> V_122 ) ;
return 0 ;
}
return - V_58 ;
}
static int F_22 ( struct V_12 * V_13 )
{
if ( F_44 ( V_13 ) ) {
if ( ! V_13 -> V_82 ) {
F_33 ( L_16 ) ;
V_13 -> V_82 = 1 ;
}
return - V_58 ;
}
return 0 ;
}
static int F_47 ( struct V_12 * V_13 , int V_88 )
{
struct V_90 * V_45 = & V_13 -> V_91 [ V_88 ] ;
struct V_37 V_38 ;
V_36 V_46 ;
int V_35 ;
int V_34 = 0 ;
int V_10 ;
F_25 ( L_17 , V_88 ) ;
V_45 -> V_126 = F_48 ( V_13 -> V_54 * 2 , V_22 ) ;
if ( ! V_45 -> V_126 )
return - V_127 ;
memset ( V_45 -> V_126 , - 1 , V_13 -> V_54 * 2 ) ;
if ( F_49 ( & V_45 -> V_103 , V_13 -> V_50 * 2 , V_22 ) ) {
F_7 ( V_45 -> V_126 ) ;
return - V_127 ;
}
for ( V_46 = 0 ; V_46 < V_13 -> V_50 ; V_46 ++ ) {
if ( V_88 == 0 && V_46 <= V_13 -> V_76 )
continue;
if ( F_21 ( V_13 , V_88 , V_46 , 0 , NULL , & V_38 ) )
return - V_58 ;
if ( F_50 ( & V_38 ) ) {
F_38 ( & V_45 -> V_103 ,
( unsigned char * ) & V_46 , 2 ) ;
continue;
}
if ( ! F_45 ( & V_38 ) ) {
F_25 ( L_18 , V_46 ) ;
continue;
}
V_35 = F_11 ( & V_38 ) ;
if ( V_35 == - 2 || V_35 >= V_13 -> V_54 ) {
F_25 ( L_19 , V_46 , V_35 ) ;
continue;
}
if ( V_45 -> V_126 [ V_35 ] < 0 ) {
F_51 ( L_20 , V_46 , V_35 ) ;
V_45 -> V_126 [ V_35 ] = V_46 ;
continue;
}
F_33 ( L_21
L_22 ,
V_35 , V_45 -> V_126 [ V_35 ] , V_46 , V_88 ) ;
if ( F_40 ( V_13 , V_88 , V_46 ) )
continue;
if ( F_40 ( V_13 , V_88 ,
V_45 -> V_126 [ V_35 ] ) ) {
V_45 -> V_126 [ V_35 ] = V_46 ;
continue;
}
F_33 ( L_23 ) ;
F_34 ( V_13 , V_88 , V_46 , 1 ) ;
}
F_25 ( L_24 ) ;
V_45 -> V_128 = 1 ;
if ( ! F_52 ( & V_45 -> V_103 ) ) {
F_33 ( L_25 , V_88 ) ;
return 0 ;
}
F_53 ( & V_34 , 2 ) ;
V_34 %= ( F_52 ( & V_45 -> V_103 ) / 2 ) ;
while ( V_34 -- ) {
V_10 = F_54 ( & V_45 -> V_103 ,
( unsigned char * ) & V_46 , 2 ) ;
F_14 ( V_10 != 2 ) ;
F_38 ( & V_45 -> V_103 , ( const unsigned char * ) & V_46 , 2 ) ;
}
return 0 ;
}
static struct V_90 * F_55 ( struct V_12 * V_13 , int V_88 )
{
struct V_90 * V_45 ;
int error ;
F_29 ( V_88 >= V_13 -> V_49 ) ;
V_45 = & V_13 -> V_91 [ V_88 ] ;
if ( ! V_45 -> V_128 ) {
error = F_47 ( V_13 , V_88 ) ;
if ( error )
return F_56 ( error ) ;
}
return V_45 ;
}
static void F_57 ( struct V_12 * V_13 )
{
V_13 -> V_129 = 0xFFFFFFFF ;
V_13 -> V_130 = 1 ;
V_13 -> V_131 = - 1 ;
V_13 -> V_132 = - 1 ;
}
static void F_58 ( struct V_12 * V_13 , char * V_55 , int V_47 )
{
memcpy ( V_13 -> V_133 + V_47 , V_55 , V_48 ) ;
F_59 ( V_47 / V_48 , & V_13 -> V_129 ) ;
V_13 -> V_130 = 0 ;
}
static int F_60 ( struct V_12 * V_13 , char * V_55 , int V_47 )
{
if ( F_32 ( V_47 / V_48 ,
& V_13 -> V_129 ) )
return - 1 ;
memcpy ( V_55 , V_13 -> V_133 + V_47 , V_48 ) ;
return 0 ;
}
static int F_61 ( struct V_12 * V_13 )
{
struct V_90 * V_45 ;
int V_134 ;
V_36 V_135 ;
int V_88 = V_13 -> V_131 ;
int V_136 ;
if ( V_13 -> V_130 )
return 0 ;
if ( V_13 -> V_82 )
return - V_58 ;
F_29 ( V_88 < 0 ) ;
V_45 = & V_13 -> V_91 [ V_88 ] ;
V_136 = V_45 -> V_126 [ V_13 -> V_132 ] ;
F_62 (sector_num, &ftl->cache_data_invalid_bitmap,
ftl->block_size / SM_SECTOR_SIZE) {
if ( ! F_21 ( V_13 ,
V_88 , V_136 , V_134 * V_48 ,
V_13 -> V_133 + V_134 * V_48 , NULL ) )
F_59 ( V_134 ,
& V_13 -> V_129 ) ;
}
V_85:
if ( V_13 -> V_82 )
return - V_58 ;
if ( F_54 ( & V_45 -> V_103 ,
( unsigned char * ) & V_135 , 2 ) != 2 ) {
F_25 ( L_26 ) ;
return - V_58 ;
}
if ( F_31 ( V_13 , V_13 -> V_133 , V_88 , V_135 ,
V_13 -> V_132 , V_13 -> V_129 ) )
goto V_85;
V_45 -> V_126 [ V_13 -> V_132 ] = V_135 ;
if ( V_136 > 0 )
F_34 ( V_13 , V_88 , V_136 , 1 ) ;
F_57 ( V_13 ) ;
return 0 ;
}
static void F_63 ( unsigned long V_9 )
{
struct V_12 * V_13 = (struct V_12 * ) V_9 ;
F_64 ( V_137 , & V_13 -> V_138 ) ;
}
static void F_65 ( struct V_139 * V_140 )
{
struct V_12 * V_13 = F_2 ( V_140 , struct V_12 , V_138 ) ;
F_66 ( & V_13 -> V_141 ) ;
F_61 ( V_13 ) ;
F_67 ( & V_13 -> V_141 ) ;
return;
}
static int F_68 ( struct V_142 * V_2 ,
unsigned long V_143 , char * V_5 )
{
struct V_12 * V_13 = V_2 -> V_97 ;
struct V_90 * V_45 ;
int error = 0 , V_144 = 0 ;
int V_88 , V_46 , V_47 ;
F_16 ( V_13 , V_143 << 9 , & V_88 , & V_46 , & V_47 ) ;
F_66 ( & V_13 -> V_141 ) ;
V_45 = F_55 ( V_13 , V_88 ) ;
if ( F_69 ( V_45 ) ) {
error = F_70 ( V_45 ) ;
goto V_145;
}
if ( V_13 -> V_131 == V_88 && V_13 -> V_132 == V_46 ) {
V_144 = 1 ;
if ( ! F_60 ( V_13 , V_5 , V_47 ) )
goto V_145;
}
V_46 = V_45 -> V_126 [ V_46 ] ;
if ( V_46 == - 1 ) {
memset ( V_5 , 0xFF , V_48 ) ;
goto V_145;
}
if ( F_21 ( V_13 , V_88 , V_46 , V_47 , V_5 , NULL ) ) {
error = - V_58 ;
goto V_145;
}
if ( V_144 )
F_58 ( V_13 , V_5 , V_47 ) ;
V_145:
F_67 ( & V_13 -> V_141 ) ;
return error ;
}
static int F_71 ( struct V_142 * V_2 ,
unsigned long V_146 , char * V_5 )
{
struct V_12 * V_13 = V_2 -> V_97 ;
struct V_90 * V_45 ;
int error , V_88 , V_46 , V_47 ;
F_29 ( V_13 -> V_81 ) ;
F_16 ( V_13 , V_146 << 9 , & V_88 , & V_46 , & V_47 ) ;
F_72 ( & V_13 -> V_147 ) ;
F_66 ( & V_13 -> V_141 ) ;
V_45 = F_55 ( V_13 , V_88 ) ;
if ( F_69 ( V_45 ) ) {
error = F_70 ( V_45 ) ;
goto V_145;
}
if ( V_13 -> V_132 != V_46 || V_13 -> V_131 != V_88 ) {
error = F_61 ( V_13 ) ;
if ( error )
goto V_145;
V_13 -> V_132 = V_46 ;
V_13 -> V_131 = V_88 ;
}
F_58 ( V_13 , V_5 , V_47 ) ;
V_145:
F_73 ( & V_13 -> V_147 , V_148 + F_74 ( V_149 ) ) ;
F_67 ( & V_13 -> V_141 ) ;
return error ;
}
static int F_75 ( struct V_142 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_97 ;
int V_150 ;
F_66 ( & V_13 -> V_141 ) ;
V_150 = F_61 ( V_13 ) ;
F_67 ( & V_13 -> V_141 ) ;
return V_150 ;
}
static void F_76 ( struct V_142 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_97 ;
F_66 ( & V_13 -> V_141 ) ;
F_77 ( & V_13 -> V_147 ) ;
F_78 ( & V_13 -> V_138 ) ;
F_61 ( V_13 ) ;
F_67 ( & V_13 -> V_141 ) ;
}
static int F_79 ( struct V_142 * V_2 , struct V_151 * V_152 )
{
struct V_12 * V_13 = V_2 -> V_97 ;
V_152 -> V_118 = V_13 -> V_118 ;
V_152 -> V_120 = V_13 -> V_120 ;
V_152 -> V_116 = V_13 -> V_116 ;
return 0 ;
}
static void F_80 ( struct V_153 * V_154 , struct V_60 * V_61 )
{
struct V_142 * V_62 ;
struct V_12 * V_13 ;
V_13 = F_5 ( sizeof( struct V_12 ) , V_22 ) ;
if ( ! V_13 )
goto V_23;
F_81 ( & V_13 -> V_141 ) ;
F_82 ( & V_13 -> V_147 , F_63 , ( unsigned long ) V_13 ) ;
F_83 ( & V_13 -> V_138 , F_65 ) ;
F_84 ( & V_13 -> V_101 ) ;
if ( F_41 ( V_13 , V_61 ) ) {
F_25 ( L_27 ) ;
goto V_24;
}
V_13 -> V_19 = F_5 ( V_48 , V_22 ) ;
if ( ! V_13 -> V_19 )
goto V_24;
V_13 -> V_91 = F_5 ( sizeof( struct V_90 ) * V_13 -> V_49 ,
V_22 ) ;
if ( ! V_13 -> V_91 )
goto V_30;
V_13 -> V_133 = F_5 ( V_13 -> V_51 , V_22 ) ;
if ( ! V_13 -> V_133 )
goto V_31;
F_57 ( V_13 ) ;
V_62 = F_5 ( sizeof( struct V_142 ) , V_22 ) ;
if ( ! V_62 )
goto V_155;
V_13 -> V_62 = V_62 ;
V_62 -> V_97 = V_13 ;
V_62 -> V_154 = V_154 ;
V_62 -> V_61 = V_61 ;
V_62 -> V_156 = - 1 ;
V_62 -> V_108 = ( V_13 -> V_51 * V_13 -> V_54 * V_13 -> V_49 ) >> 9 ;
V_62 -> V_81 = V_13 -> V_81 ;
if ( F_46 ( V_13 ) ) {
F_25 ( L_28 ) ;
goto V_157;
}
V_13 -> V_33 = F_3 ( V_13 ) ;
if ( ! V_13 -> V_33 )
goto V_157;
V_62 -> V_33 = V_13 -> V_33 ;
F_33 ( L_29 ,
( int ) ( V_61 -> V_108 / ( 1024 * 1024 ) ) , V_61 -> V_158 ) ;
F_25 ( L_30 ) ;
F_25 ( L_31 ,
V_13 -> V_49 , V_13 -> V_54 ,
V_13 -> V_50 - V_13 -> V_54 ) ;
F_25 ( L_32 ,
V_13 -> V_51 ) ;
if ( F_85 ( V_62 ) ) {
F_25 ( L_33 ) ;
goto V_157;
}
return;
V_157:
F_7 ( V_62 ) ;
V_155:
F_7 ( V_13 -> V_133 ) ;
V_31:
F_7 ( V_13 -> V_91 ) ;
V_30:
F_7 ( V_13 -> V_19 ) ;
V_24:
F_7 ( V_13 ) ;
V_23:
return;
}
static void F_86 ( struct V_142 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_97 ;
int V_34 ;
F_87 ( V_2 ) ;
V_13 -> V_62 = NULL ;
for ( V_34 = 0 ; V_34 < V_13 -> V_49 ; V_34 ++ ) {
if ( ! V_13 -> V_91 [ V_34 ] . V_128 )
continue;
F_7 ( V_13 -> V_91 [ V_34 ] . V_126 ) ;
F_88 ( & V_13 -> V_91 [ V_34 ] . V_103 ) ;
}
F_8 ( V_13 ) ;
F_7 ( V_13 -> V_19 ) ;
F_7 ( V_13 -> V_91 ) ;
F_7 ( V_13 -> V_133 ) ;
F_7 ( V_13 ) ;
}
static T_5 int F_89 ( void )
{
int error = 0 ;
V_137 = F_90 ( L_34 ) ;
if ( ! V_137 )
return - V_127 ;
error = F_91 ( & V_159 ) ;
if ( error )
F_92 ( V_137 ) ;
return error ;
}
static void T_6 F_93 ( void )
{
F_92 ( V_137 ) ;
F_94 ( & V_159 ) ;
}
