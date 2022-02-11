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
int V_18 = F_4 ( V_13 -> V_19 + V_20 ,
V_21 - V_20 ) ;
char * V_22 = F_5 ( V_18 , V_23 ) ;
if ( ! V_22 )
goto V_24;
memcpy ( V_22 , V_13 -> V_19 + V_20 , V_18 ) ;
V_22 [ V_18 ] = 0 ;
V_17 =
F_6 ( sizeof( struct V_6 ) , V_23 ) ;
if ( ! V_17 )
goto V_25;
F_7 ( & V_17 -> V_8 . V_4 ) ;
V_17 -> V_9 = V_22 ;
V_17 -> V_10 = V_18 ;
V_17 -> V_8 . V_4 . V_26 = L_1 ;
V_17 -> V_8 . V_4 . V_27 = V_28 ;
V_17 -> V_8 . V_29 = F_1 ;
V_16 = F_6 ( sizeof( struct V_15 * ) * ( V_30 + 1 ) ,
V_23 ) ;
if ( ! V_16 )
goto V_31;
V_16 [ 0 ] = & V_17 -> V_8 . V_4 ;
V_14 = F_6 ( sizeof( struct V_11 ) , V_23 ) ;
if ( ! V_14 )
goto V_32;
V_14 -> V_33 = V_16 ;
return V_14 ;
V_32:
F_8 ( V_16 ) ;
V_31:
F_8 ( V_17 ) ;
V_25:
F_8 ( V_22 ) ;
V_24:
return NULL ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_15 * * V_16 = V_13 -> V_34 -> V_33 ;
int V_35 ;
for ( V_35 = 0 ; V_16 [ V_35 ] ; V_35 ++ ) {
struct V_3 * V_8 = F_2 ( V_16 [ V_35 ] ,
struct V_3 , V_4 ) ;
struct V_6 * V_7 =
F_2 ( V_8 ,
struct V_6 , V_8 ) ;
F_8 ( V_7 -> V_9 ) ;
F_8 ( V_7 ) ;
}
F_8 ( V_13 -> V_34 -> V_33 ) ;
F_8 ( V_13 -> V_34 ) ;
}
static int F_10 ( T_2 * V_36 )
{
if ( ( V_36 [ 0 ] & 0xF8 ) != 0x10 )
return - 2 ;
if ( F_11 ( * ( V_37 * ) V_36 ) & 1 )
return - 2 ;
return ( V_36 [ 1 ] >> 1 ) | ( ( V_36 [ 0 ] & 0x07 ) << 7 ) ;
}
static int F_12 ( struct V_38 * V_39 )
{
static const T_3 V_40 [ 4 ] = {
0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF } ;
V_37 V_41 ;
int V_36 ;
if ( ! memcmp ( V_39 , V_40 , V_42 ) )
return - 1 ;
V_41 = * ( V_37 * ) V_39 -> V_43 ^ * ( V_37 * ) V_39 -> V_44 ;
if ( V_41 && ! F_13 ( V_41 ) )
return - 2 ;
V_36 = F_10 ( V_39 -> V_43 ) ;
if ( V_36 == - 2 )
V_36 = F_10 ( V_39 -> V_44 ) ;
return V_36 ;
}
static void F_14 ( struct V_38 * V_39 , V_37 V_36 )
{
T_2 V_45 [ 2 ] ;
F_15 ( V_36 >= 1000 ) ;
V_45 [ 0 ] = 0x10 | ( ( V_36 >> 7 ) & 0x07 ) ;
V_45 [ 1 ] = ( V_36 << 1 ) & 0xFF ;
if ( F_11 ( * ( V_37 * ) V_45 ) & 0x01 )
V_45 [ 1 ] |= 1 ;
V_39 -> V_43 [ 0 ] = V_39 -> V_44 [ 0 ] = V_45 [ 0 ] ;
V_39 -> V_43 [ 1 ] = V_39 -> V_44 [ 1 ] = V_45 [ 1 ] ;
}
static T_4 F_16 ( struct V_12 * V_13 , int V_46 , int V_47 , int V_48 )
{
F_15 ( V_48 & ( V_49 - 1 ) ) ;
F_15 ( V_46 < 0 || V_46 >= V_13 -> V_50 ) ;
F_15 ( V_47 >= V_13 -> V_51 ) ;
F_15 ( V_48 >= V_13 -> V_52 ) ;
if ( V_47 == - 1 )
return - 1 ;
return ( V_46 * V_53 + V_47 ) * V_13 -> V_52 + V_48 ;
}
static void F_17 ( struct V_12 * V_13 , T_4 V_54 ,
int * V_46 , int * V_47 , int * V_48 )
{
* V_48 = F_18 ( V_54 , V_13 -> V_52 ) ;
* V_47 = F_18 ( V_54 , V_13 -> V_55 ) ;
* V_46 = V_54 >= V_13 -> V_50 ? - 1 : V_54 ;
}
static int F_19 ( T_2 * V_56 , struct V_38 * V_39 )
{
T_2 V_57 [ 3 ] ;
F_20 ( V_56 , V_21 , V_57 ) ;
if ( F_21 ( V_56 , V_57 , V_39 -> V_58 , V_21 ) < 0 )
return - V_59 ;
V_56 += V_21 ;
F_20 ( V_56 , V_21 , V_57 ) ;
if ( F_21 ( V_56 , V_57 , V_39 -> V_60 , V_21 ) < 0 )
return - V_59 ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 ,
int V_46 , int V_47 , int V_48 ,
T_2 * V_56 , struct V_38 * V_39 )
{
struct V_61 * V_62 = V_13 -> V_63 -> V_62 ;
struct V_64 V_65 ;
struct V_38 V_66 ;
int V_67 = - V_59 ;
int V_68 = 0 ;
if ( V_47 == - 1 ) {
memset ( V_56 , 0xFF , V_49 ) ;
return 0 ;
}
if ( ! V_39 )
V_39 = & V_66 ;
V_65 . V_27 = V_13 -> V_69 ? V_70 : V_71 ;
V_65 . V_72 = 0 ;
V_65 . V_73 = V_42 ;
V_65 . V_74 = ( void * ) V_39 ;
V_65 . V_10 = V_49 ;
V_65 . V_75 = V_56 ;
V_76:
if ( V_68 ++ ) {
if ( V_46 == 0 && V_47 == V_13 -> V_77 && V_48 ==
V_13 -> V_78 )
return V_67 ;
if ( V_68 == 3 || F_23 ( V_13 ) )
return V_67 ;
}
V_67 = F_24 ( V_62 , F_16 ( V_13 , V_46 , V_47 , V_48 ) , & V_65 ) ;
if ( V_67 != 0 && ! F_25 ( V_67 ) ) {
F_26 ( L_2 ,
V_47 , V_46 , V_67 ) ;
goto V_76;
}
if ( V_39 -> V_79 != 0xFFFFFFFF && ! F_13 ( ~ V_39 -> V_79 ) )
goto V_76;
F_15 ( V_65 . V_80 != V_42 ) ;
F_15 ( V_56 && V_65 . V_81 != V_49 ) ;
if ( ! V_56 )
return 0 ;
if ( ! F_27 ( V_39 ) ) {
F_26 ( L_3
L_4 , V_47 , V_46 ) ;
goto V_76;
}
if ( F_28 ( V_67 ) ||
( V_13 -> V_69 && F_19 ( V_56 , V_39 ) ) ) {
F_26 ( L_5 ,
V_47 , V_46 ) ;
goto V_76;
}
return 0 ;
}
static int F_29 ( struct V_12 * V_13 ,
int V_46 , int V_47 , int V_48 ,
T_2 * V_56 , struct V_38 * V_39 )
{
struct V_64 V_65 ;
struct V_61 * V_62 = V_13 -> V_63 -> V_62 ;
int V_67 ;
F_30 ( V_13 -> V_82 ) ;
if ( V_46 == 0 && ( V_47 == V_13 -> V_77 || V_47 == 0 ) ) {
F_26 ( L_6 ) ;
return - V_59 ;
}
if ( V_13 -> V_83 )
return - V_59 ;
V_65 . V_27 = V_13 -> V_69 ? V_70 : V_71 ;
V_65 . V_10 = V_49 ;
V_65 . V_75 = V_56 ;
V_65 . V_72 = 0 ;
V_65 . V_73 = V_42 ;
V_65 . V_74 = ( void * ) V_39 ;
V_67 = F_31 ( V_62 , F_16 ( V_13 , V_46 , V_47 , V_48 ) , & V_65 ) ;
if ( V_67 ) {
F_26 ( L_7 ,
V_47 , V_46 , V_67 ) ;
F_23 ( V_13 ) ;
return V_67 ;
}
F_15 ( V_65 . V_80 != V_42 ) ;
F_15 ( V_56 && V_65 . V_81 != V_49 ) ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 , T_2 * V_5 ,
int V_46 , int V_47 , int V_36 ,
unsigned long V_84 )
{
struct V_38 V_39 ;
int V_48 ;
int V_85 = 0 ;
memset ( & V_39 , 0xFF , V_42 ) ;
F_14 ( & V_39 , V_36 ) ;
V_86:
if ( V_13 -> V_83 )
return - V_59 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ;
V_48 += V_49 ) {
V_39 . V_87 = 0xFF ;
if ( F_33 ( V_48 / V_49 , & V_84 ) ) {
F_34 ( L_8
L_9 ,
V_48 / V_49 , V_36 , V_46 ) ;
V_39 . V_87 = 0 ;
}
if ( V_13 -> V_69 ) {
F_20 ( V_5 + V_48 ,
V_21 , V_39 . V_58 ) ;
F_20 ( V_5 + V_48 + V_21 ,
V_21 , V_39 . V_60 ) ;
}
if ( ! F_29 ( V_13 , V_46 , V_47 , V_48 ,
V_5 + V_48 , & V_39 ) )
continue;
if ( ! V_85 ) {
if ( F_35 ( V_13 , V_46 , V_47 , 0 ) )
return - V_59 ;
V_85 = 1 ;
goto V_86;
} else {
F_36 ( V_13 , V_46 , V_47 ) ;
return - V_59 ;
}
}
return 0 ;
}
static void F_36 ( struct V_12 * V_13 , int V_46 , int V_47 )
{
struct V_38 V_39 ;
int V_48 ;
memset ( & V_39 , 0xFF , V_42 ) ;
V_39 . V_88 = 0xF0 ;
if ( V_13 -> V_83 )
return;
if ( F_23 ( V_13 ) )
return;
F_34 ( L_10 , V_47 , V_46 ) ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ; V_48 += V_49 )
F_29 ( V_13 , V_46 , V_47 , V_48 , NULL , & V_39 ) ;
}
static int F_35 ( struct V_12 * V_13 , int V_89 , V_37 V_47 ,
int V_90 )
{
struct V_91 * V_46 = & V_13 -> V_92 [ V_89 ] ;
struct V_61 * V_62 = V_13 -> V_63 -> V_62 ;
struct V_93 V_94 ;
V_94 . V_62 = V_62 ;
V_94 . V_95 = V_96 ;
V_94 . V_97 = F_16 ( V_13 , V_89 , V_47 , 0 ) ;
V_94 . V_10 = V_13 -> V_52 ;
V_94 . V_98 = ( V_99 ) V_13 ;
if ( V_13 -> V_83 )
return - V_59 ;
F_30 ( V_13 -> V_82 ) ;
if ( V_89 == 0 && ( V_47 == V_13 -> V_77 || V_47 == 0 ) ) {
F_34 ( L_11 ) ;
return - V_59 ;
}
if ( F_37 ( V_62 , & V_94 ) ) {
F_34 ( L_12 ,
V_47 , V_89 ) ;
goto error;
}
if ( V_94 . V_100 == V_101 )
F_38 ( & V_13 -> V_102 ) ;
if ( V_94 . V_100 != V_103 ) {
F_34 ( L_13 ,
V_47 , V_89 ) ;
goto error;
}
if ( V_90 )
F_39 ( & V_46 -> V_104 ,
( const unsigned char * ) & V_47 , sizeof( V_47 ) ) ;
return 0 ;
error:
F_36 ( V_13 , V_89 , V_47 ) ;
return - V_59 ;
}
static void V_96 ( struct V_93 * V_105 )
{
struct V_12 * V_13 = (struct V_12 * ) V_105 -> V_98 ;
F_40 ( & V_13 -> V_102 ) ;
}
static int F_41 ( struct V_12 * V_13 , int V_46 , int V_47 )
{
int V_48 ;
struct V_38 V_39 ;
int V_106 [] = { - 3 , 0 , 0 , 0 } ;
int V_35 = 0 ;
int V_107 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ;
V_48 += V_49 ) {
if ( F_22 ( V_13 , V_46 , V_47 , V_48 , NULL , & V_39 ) )
return - 2 ;
V_107 = F_12 ( & V_39 ) ;
if ( V_106 [ V_35 ] != V_107 )
V_106 [ ++ V_35 ] = V_107 ;
if ( V_35 == 3 )
return - V_59 ;
}
if ( V_35 == 2 ) {
F_35 ( V_13 , V_46 , V_47 , 1 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_12 * V_13 , struct V_61 * V_62 )
{
int V_35 ;
int V_108 = V_62 -> V_109 / ( 1024 * 1024 ) ;
V_13 -> V_82 = V_62 -> type == V_110 ;
V_13 -> V_50 = 1 ;
V_13 -> V_69 = 0 ;
switch ( V_108 ) {
case 1 :
V_13 -> V_51 = 256 ;
V_13 -> V_55 = 250 ;
V_13 -> V_52 = 8 * V_49 ;
V_13 -> V_69 = 1 ;
break;
case 2 :
if ( V_62 -> V_111 == V_21 ) {
V_13 -> V_51 = 512 ;
V_13 -> V_55 = 500 ;
V_13 -> V_52 = 8 * V_49 ;
V_13 -> V_69 = 1 ;
} else {
if ( ! V_13 -> V_82 )
return - V_112 ;
V_13 -> V_51 = 256 ;
V_13 -> V_55 = 250 ;
V_13 -> V_52 = 16 * V_49 ;
}
break;
case 4 :
V_13 -> V_51 = 512 ;
V_13 -> V_55 = 500 ;
V_13 -> V_52 = 16 * V_49 ;
break;
case 8 :
V_13 -> V_51 = 1024 ;
V_13 -> V_55 = 1000 ;
V_13 -> V_52 = 16 * V_49 ;
}
if ( V_108 >= 16 ) {
V_13 -> V_50 = V_108 / 16 ;
V_13 -> V_51 = 1024 ;
V_13 -> V_55 = 1000 ;
V_13 -> V_52 = 32 * V_49 ;
}
if ( V_62 -> V_113 > V_13 -> V_52 )
return - V_112 ;
if ( V_62 -> V_111 > V_49 )
return - V_112 ;
if ( V_13 -> V_69 && V_62 -> V_114 < V_115 )
return - V_112 ;
if ( ! V_13 -> V_69 && V_62 -> V_114 < V_42 )
return - V_112 ;
if ( ! F_43 ( V_62 ) )
return - V_112 ;
for ( V_35 = 0 ; V_35 < F_44 ( V_116 ) ; V_35 ++ ) {
if ( V_116 [ V_35 ] . V_109 == V_108 ) {
V_13 -> V_117 = V_116 [ V_35 ] . V_118 ;
V_13 -> V_119 = V_116 [ V_35 ] . V_120 ;
V_13 -> V_121 = V_116 [ V_35 ] . V_122 ;
return 0 ;
}
}
F_34 ( L_14 , V_108 ) ;
V_13 -> V_117 = 985 ;
V_13 -> V_119 = 33 ;
V_13 -> V_121 = 63 ;
return 0 ;
}
static int F_45 ( struct V_12 * V_13 )
{
struct V_38 V_39 ;
if ( F_22 ( V_13 ,
0 , V_13 -> V_77 , V_13 -> V_78 , V_13 -> V_19 , & V_39 ) )
return - V_59 ;
if ( ! F_27 ( & V_39 ) || ! F_46 ( & V_39 ) )
return - V_59 ;
if ( ! memcmp ( V_13 -> V_19 + V_13 -> V_123 ,
V_124 , sizeof( V_124 ) ) ) {
return 0 ;
}
return - V_59 ;
}
static int F_47 ( struct V_12 * V_13 )
{
struct V_38 V_39 ;
int V_47 , V_48 ;
int V_125 = 0 ;
int V_126 = 0 ;
for ( V_47 = 0 ; V_47 < V_13 -> V_51 - V_13 -> V_55 ; V_47 ++ ) {
if ( F_22 ( V_13 , 0 , V_47 , 0 , NULL , & V_39 ) )
continue;
if ( ! F_46 ( & V_39 ) )
continue;
V_125 = 1 ;
break;
}
if ( ! V_125 )
return - V_59 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ;
V_48 += V_49 ) {
if ( F_22 ( V_13 , 0 , V_47 , V_48 , NULL , & V_39 ) )
continue;
if ( ! F_27 ( & V_39 ) )
continue;
break;
}
if ( V_48 == V_13 -> V_52 )
return - V_59 ;
V_13 -> V_77 = V_47 ;
V_13 -> V_78 = V_48 ;
V_13 -> V_123 = 0 ;
V_126 = ! F_45 ( V_13 ) ;
if ( ! V_126 ) {
V_13 -> V_123 = V_21 ;
V_126 = ! F_45 ( V_13 ) ;
}
if ( V_126 ) {
F_26 ( L_15 ,
V_47 * V_13 -> V_52 +
V_48 + V_13 -> V_123 ) ;
return 0 ;
}
return - V_59 ;
}
static int F_23 ( struct V_12 * V_13 )
{
if ( F_45 ( V_13 ) ) {
if ( ! V_13 -> V_83 ) {
F_34 ( L_16 ) ;
V_13 -> V_83 = 1 ;
}
return - V_59 ;
}
return 0 ;
}
static int F_48 ( struct V_12 * V_13 , int V_89 )
{
struct V_91 * V_46 = & V_13 -> V_92 [ V_89 ] ;
struct V_38 V_39 ;
V_37 V_47 ;
int V_36 ;
int V_35 = 0 ;
int V_10 ;
F_26 ( L_17 , V_89 ) ;
V_46 -> V_127 = F_5 ( V_13 -> V_55 * 2 , V_23 ) ;
if ( ! V_46 -> V_127 )
return - V_128 ;
memset ( V_46 -> V_127 , - 1 , V_13 -> V_55 * 2 ) ;
if ( F_49 ( & V_46 -> V_104 , V_13 -> V_51 * 2 , V_23 ) ) {
F_8 ( V_46 -> V_127 ) ;
return - V_128 ;
}
for ( V_47 = 0 ; V_47 < V_13 -> V_51 ; V_47 ++ ) {
if ( V_89 == 0 && V_47 <= V_13 -> V_77 )
continue;
if ( F_22 ( V_13 , V_89 , V_47 , 0 , NULL , & V_39 ) )
return - V_59 ;
if ( F_50 ( & V_39 ) ) {
F_39 ( & V_46 -> V_104 ,
( unsigned char * ) & V_47 , 2 ) ;
continue;
}
if ( ! F_46 ( & V_39 ) ) {
F_26 ( L_18 , V_47 ) ;
continue;
}
V_36 = F_12 ( & V_39 ) ;
if ( V_36 == - 2 || V_36 >= V_13 -> V_55 ) {
F_26 ( L_19 , V_47 , V_36 ) ;
continue;
}
if ( V_46 -> V_127 [ V_36 ] < 0 ) {
F_51 ( L_20 , V_47 , V_36 ) ;
V_46 -> V_127 [ V_36 ] = V_47 ;
continue;
}
F_34 ( L_21
L_22 ,
V_36 , V_46 -> V_127 [ V_36 ] , V_47 , V_89 ) ;
if ( F_41 ( V_13 , V_89 , V_47 ) )
continue;
if ( F_41 ( V_13 , V_89 ,
V_46 -> V_127 [ V_36 ] ) ) {
V_46 -> V_127 [ V_36 ] = V_47 ;
continue;
}
F_34 ( L_23 ) ;
F_35 ( V_13 , V_89 , V_47 , 1 ) ;
}
F_26 ( L_24 ) ;
V_46 -> V_129 = 1 ;
if ( ! F_52 ( & V_46 -> V_104 ) ) {
F_34 ( L_25 , V_89 ) ;
return 0 ;
}
F_53 ( & V_35 , 2 ) ;
V_35 %= ( F_52 ( & V_46 -> V_104 ) / 2 ) ;
while ( V_35 -- ) {
V_10 = F_54 ( & V_46 -> V_104 ,
( unsigned char * ) & V_47 , 2 ) ;
F_15 ( V_10 != 2 ) ;
F_39 ( & V_46 -> V_104 , ( const unsigned char * ) & V_47 , 2 ) ;
}
return 0 ;
}
static struct V_91 * F_55 ( struct V_12 * V_13 , int V_89 )
{
struct V_91 * V_46 ;
int error ;
F_30 ( V_89 >= V_13 -> V_50 ) ;
V_46 = & V_13 -> V_92 [ V_89 ] ;
if ( ! V_46 -> V_129 ) {
error = F_48 ( V_13 , V_89 ) ;
if ( error )
return F_56 ( error ) ;
}
return V_46 ;
}
static void F_57 ( struct V_12 * V_13 )
{
V_13 -> V_130 = 0xFFFFFFFF ;
V_13 -> V_131 = 1 ;
V_13 -> V_132 = - 1 ;
V_13 -> V_133 = - 1 ;
}
static void F_58 ( struct V_12 * V_13 , char * V_56 , int V_48 )
{
memcpy ( V_13 -> V_134 + V_48 , V_56 , V_49 ) ;
F_59 ( V_48 / V_49 , & V_13 -> V_130 ) ;
V_13 -> V_131 = 0 ;
}
static int F_60 ( struct V_12 * V_13 , char * V_56 , int V_48 )
{
if ( F_33 ( V_48 / V_49 ,
& V_13 -> V_130 ) )
return - 1 ;
memcpy ( V_56 , V_13 -> V_134 + V_48 , V_49 ) ;
return 0 ;
}
static int F_61 ( struct V_12 * V_13 )
{
struct V_91 * V_46 ;
int V_135 ;
V_37 V_136 ;
int V_89 = V_13 -> V_132 ;
int V_137 ;
if ( V_13 -> V_131 )
return 0 ;
if ( V_13 -> V_83 )
return - V_59 ;
F_30 ( V_89 < 0 ) ;
V_46 = & V_13 -> V_92 [ V_89 ] ;
V_137 = V_46 -> V_127 [ V_13 -> V_133 ] ;
F_62 (sector_num, &ftl->cache_data_invalid_bitmap,
ftl->block_size / SM_SECTOR_SIZE) {
if ( ! F_22 ( V_13 ,
V_89 , V_137 , V_135 * V_49 ,
V_13 -> V_134 + V_135 * V_49 , NULL ) )
F_59 ( V_135 ,
& V_13 -> V_130 ) ;
}
V_86:
if ( V_13 -> V_83 )
return - V_59 ;
if ( F_54 ( & V_46 -> V_104 ,
( unsigned char * ) & V_136 , 2 ) != 2 ) {
F_26 ( L_26 ) ;
return - V_59 ;
}
if ( F_32 ( V_13 , V_13 -> V_134 , V_89 , V_136 ,
V_13 -> V_133 , V_13 -> V_130 ) )
goto V_86;
V_46 -> V_127 [ V_13 -> V_133 ] = V_136 ;
if ( V_137 > 0 )
F_35 ( V_13 , V_89 , V_137 , 1 ) ;
F_57 ( V_13 ) ;
return 0 ;
}
static void F_63 ( unsigned long V_9 )
{
struct V_12 * V_13 = (struct V_12 * ) V_9 ;
F_64 ( V_138 , & V_13 -> V_139 ) ;
}
static void F_65 ( struct V_140 * V_141 )
{
struct V_12 * V_13 = F_2 ( V_141 , struct V_12 , V_139 ) ;
F_66 ( & V_13 -> V_142 ) ;
F_61 ( V_13 ) ;
F_67 ( & V_13 -> V_142 ) ;
return;
}
static int F_68 ( struct V_143 * V_2 ,
unsigned long V_144 , char * V_5 )
{
struct V_12 * V_13 = V_2 -> V_98 ;
struct V_91 * V_46 ;
int error = 0 , V_145 = 0 ;
int V_89 , V_47 , V_48 ;
F_17 ( V_13 , V_144 << 9 , & V_89 , & V_47 , & V_48 ) ;
F_66 ( & V_13 -> V_142 ) ;
V_46 = F_55 ( V_13 , V_89 ) ;
if ( F_69 ( V_46 ) ) {
error = F_70 ( V_46 ) ;
goto V_146;
}
if ( V_13 -> V_132 == V_89 && V_13 -> V_133 == V_47 ) {
V_145 = 1 ;
if ( ! F_60 ( V_13 , V_5 , V_48 ) )
goto V_146;
}
V_47 = V_46 -> V_127 [ V_47 ] ;
if ( V_47 == - 1 ) {
memset ( V_5 , 0xFF , V_49 ) ;
goto V_146;
}
if ( F_22 ( V_13 , V_89 , V_47 , V_48 , V_5 , NULL ) ) {
error = - V_59 ;
goto V_146;
}
if ( V_145 )
F_58 ( V_13 , V_5 , V_48 ) ;
V_146:
F_67 ( & V_13 -> V_142 ) ;
return error ;
}
static int F_71 ( struct V_143 * V_2 ,
unsigned long V_147 , char * V_5 )
{
struct V_12 * V_13 = V_2 -> V_98 ;
struct V_91 * V_46 ;
int error , V_89 , V_47 , V_48 ;
F_30 ( V_13 -> V_82 ) ;
F_17 ( V_13 , V_147 << 9 , & V_89 , & V_47 , & V_48 ) ;
F_72 ( & V_13 -> V_148 ) ;
F_66 ( & V_13 -> V_142 ) ;
V_46 = F_55 ( V_13 , V_89 ) ;
if ( F_69 ( V_46 ) ) {
error = F_70 ( V_46 ) ;
goto V_146;
}
if ( V_13 -> V_133 != V_47 || V_13 -> V_132 != V_89 ) {
error = F_61 ( V_13 ) ;
if ( error )
goto V_146;
V_13 -> V_133 = V_47 ;
V_13 -> V_132 = V_89 ;
}
F_58 ( V_13 , V_5 , V_48 ) ;
V_146:
F_73 ( & V_13 -> V_148 , V_149 + F_74 ( V_150 ) ) ;
F_67 ( & V_13 -> V_142 ) ;
return error ;
}
static int F_75 ( struct V_143 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_98 ;
int V_151 ;
F_66 ( & V_13 -> V_142 ) ;
V_151 = F_61 ( V_13 ) ;
F_67 ( & V_13 -> V_142 ) ;
return V_151 ;
}
static void F_76 ( struct V_143 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_98 ;
F_66 ( & V_13 -> V_142 ) ;
F_77 ( & V_13 -> V_148 ) ;
F_78 ( & V_13 -> V_139 ) ;
F_61 ( V_13 ) ;
F_67 ( & V_13 -> V_142 ) ;
}
static int F_79 ( struct V_143 * V_2 , struct V_152 * V_153 )
{
struct V_12 * V_13 = V_2 -> V_98 ;
V_153 -> V_119 = V_13 -> V_119 ;
V_153 -> V_121 = V_13 -> V_121 ;
V_153 -> V_117 = V_13 -> V_117 ;
return 0 ;
}
static void F_80 ( struct V_154 * V_155 , struct V_61 * V_62 )
{
struct V_143 * V_63 ;
struct V_12 * V_13 ;
V_13 = F_6 ( sizeof( struct V_12 ) , V_23 ) ;
if ( ! V_13 )
goto V_24;
F_81 ( & V_13 -> V_142 ) ;
F_82 ( & V_13 -> V_148 , F_63 , ( unsigned long ) V_13 ) ;
F_83 ( & V_13 -> V_139 , F_65 ) ;
F_84 ( & V_13 -> V_102 ) ;
if ( F_42 ( V_13 , V_62 ) ) {
F_26 ( L_27 ) ;
goto V_25;
}
V_13 -> V_19 = F_6 ( V_49 , V_23 ) ;
if ( ! V_13 -> V_19 )
goto V_25;
V_13 -> V_92 = F_6 ( sizeof( struct V_91 ) * V_13 -> V_50 ,
V_23 ) ;
if ( ! V_13 -> V_92 )
goto V_31;
V_13 -> V_134 = F_6 ( V_13 -> V_52 , V_23 ) ;
if ( ! V_13 -> V_134 )
goto V_32;
F_57 ( V_13 ) ;
V_63 = F_6 ( sizeof( struct V_143 ) , V_23 ) ;
if ( ! V_63 )
goto V_156;
V_13 -> V_63 = V_63 ;
V_63 -> V_98 = V_13 ;
V_63 -> V_155 = V_155 ;
V_63 -> V_62 = V_62 ;
V_63 -> V_157 = - 1 ;
V_63 -> V_109 = ( V_13 -> V_52 * V_13 -> V_55 * V_13 -> V_50 ) >> 9 ;
V_63 -> V_82 = V_13 -> V_82 ;
if ( F_47 ( V_13 ) ) {
F_26 ( L_28 ) ;
goto V_158;
}
V_13 -> V_34 = F_3 ( V_13 ) ;
if ( ! V_13 -> V_34 )
goto V_158;
V_63 -> V_34 = V_13 -> V_34 ;
F_34 ( L_29 ,
( int ) ( V_62 -> V_109 / ( 1024 * 1024 ) ) , V_62 -> V_159 ) ;
F_26 ( L_30 ) ;
F_26 ( L_31 ,
V_13 -> V_50 , V_13 -> V_55 ,
V_13 -> V_51 - V_13 -> V_55 ) ;
F_26 ( L_32 ,
V_13 -> V_52 ) ;
if ( F_85 ( V_63 ) ) {
F_26 ( L_33 ) ;
goto V_158;
}
return;
V_158:
F_8 ( V_63 ) ;
V_156:
F_8 ( V_13 -> V_134 ) ;
V_32:
F_8 ( V_13 -> V_92 ) ;
V_31:
F_8 ( V_13 -> V_19 ) ;
V_25:
F_8 ( V_13 ) ;
V_24:
return;
}
static void F_86 ( struct V_143 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_98 ;
int V_35 ;
F_87 ( V_2 ) ;
V_13 -> V_63 = NULL ;
for ( V_35 = 0 ; V_35 < V_13 -> V_50 ; V_35 ++ ) {
if ( ! V_13 -> V_92 [ V_35 ] . V_129 )
continue;
F_8 ( V_13 -> V_92 [ V_35 ] . V_127 ) ;
F_88 ( & V_13 -> V_92 [ V_35 ] . V_104 ) ;
}
F_9 ( V_13 ) ;
F_8 ( V_13 -> V_19 ) ;
F_8 ( V_13 -> V_92 ) ;
F_8 ( V_13 -> V_134 ) ;
F_8 ( V_13 ) ;
}
static T_5 int F_89 ( void )
{
int error = 0 ;
V_138 = F_90 ( L_34 ) ;
if ( ! V_138 )
return - V_128 ;
error = F_91 ( & V_160 ) ;
if ( error )
F_92 ( V_138 ) ;
return error ;
}
static void T_6 F_93 ( void )
{
F_92 ( V_138 ) ;
F_94 ( & V_160 ) ;
}
