T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
strncpy ( V_5 , V_7 -> V_9 , V_7 -> V_10 ) ;
return V_7 -> V_10 ;
}
struct V_11 * F_3 ( struct V_12 * V_13 )
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
void F_9 ( struct V_12 * V_13 )
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
V_67 = V_62 -> V_79 ( V_62 , F_16 ( V_13 , V_46 , V_47 , V_48 ) , & V_65 ) ;
if ( V_67 != 0 && ! F_24 ( V_67 ) ) {
F_25 ( L_2 ,
V_47 , V_46 , V_67 ) ;
goto V_76;
}
if ( V_39 -> V_80 != 0xFFFFFFFF && ! F_13 ( ~ V_39 -> V_80 ) )
goto V_76;
F_15 ( V_65 . V_81 != V_42 ) ;
F_15 ( V_56 && V_65 . V_82 != V_49 ) ;
if ( ! V_56 )
return 0 ;
if ( ! F_26 ( V_39 ) ) {
F_25 ( L_3
L_4 , V_47 , V_46 ) ;
goto V_76;
}
if ( F_27 ( V_67 ) ||
( V_13 -> V_69 && F_19 ( V_56 , V_39 ) ) ) {
F_25 ( L_5 ,
V_47 , V_46 ) ;
goto V_76;
}
return 0 ;
}
static int F_28 ( struct V_12 * V_13 ,
int V_46 , int V_47 , int V_48 ,
T_2 * V_56 , struct V_38 * V_39 )
{
struct V_64 V_65 ;
struct V_61 * V_62 = V_13 -> V_63 -> V_62 ;
int V_67 ;
F_29 ( V_13 -> V_83 ) ;
if ( V_46 == 0 && ( V_47 == V_13 -> V_77 || V_47 == 0 ) ) {
F_25 ( L_6 ) ;
return - V_59 ;
}
if ( V_13 -> V_84 )
return - V_59 ;
V_65 . V_27 = V_13 -> V_69 ? V_70 : V_71 ;
V_65 . V_10 = V_49 ;
V_65 . V_75 = V_56 ;
V_65 . V_72 = 0 ;
V_65 . V_73 = V_42 ;
V_65 . V_74 = ( void * ) V_39 ;
V_67 = V_62 -> V_85 ( V_62 , F_16 ( V_13 , V_46 , V_47 , V_48 ) , & V_65 ) ;
if ( V_67 ) {
F_25 ( L_7 ,
V_47 , V_46 , V_67 ) ;
F_23 ( V_13 ) ;
return V_67 ;
}
F_15 ( V_65 . V_81 != V_42 ) ;
F_15 ( V_56 && V_65 . V_82 != V_49 ) ;
return 0 ;
}
static int F_30 ( struct V_12 * V_13 , T_2 * V_5 ,
int V_46 , int V_47 , int V_36 ,
unsigned long V_86 )
{
struct V_38 V_39 ;
int V_48 ;
int V_87 = 0 ;
memset ( & V_39 , 0xFF , V_42 ) ;
F_14 ( & V_39 , V_36 ) ;
V_88:
if ( V_13 -> V_84 )
return - V_59 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ;
V_48 += V_49 ) {
V_39 . V_89 = 0xFF ;
if ( F_31 ( V_48 / V_49 , & V_86 ) ) {
F_32 ( L_8
L_9 ,
V_48 / V_49 , V_36 , V_46 ) ;
V_39 . V_89 = 0 ;
}
if ( V_13 -> V_69 ) {
F_20 ( V_5 + V_48 ,
V_21 , V_39 . V_58 ) ;
F_20 ( V_5 + V_48 + V_21 ,
V_21 , V_39 . V_60 ) ;
}
if ( ! F_28 ( V_13 , V_46 , V_47 , V_48 ,
V_5 + V_48 , & V_39 ) )
continue;
if ( ! V_87 ) {
if ( F_33 ( V_13 , V_46 , V_47 , 0 ) )
return - V_59 ;
V_87 = 1 ;
goto V_88;
} else {
F_34 ( V_13 , V_46 , V_47 ) ;
return - V_59 ;
}
}
return 0 ;
}
static void F_34 ( struct V_12 * V_13 , int V_46 , int V_47 )
{
struct V_38 V_39 ;
int V_48 ;
memset ( & V_39 , 0xFF , V_42 ) ;
V_39 . V_90 = 0xF0 ;
if ( V_13 -> V_84 )
return;
if ( F_23 ( V_13 ) )
return;
F_32 ( L_10 , V_47 , V_46 ) ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ; V_48 += V_49 )
F_28 ( V_13 , V_46 , V_47 , V_48 , NULL , & V_39 ) ;
}
static int F_33 ( struct V_12 * V_13 , int V_91 , V_37 V_47 ,
int V_92 )
{
struct V_93 * V_46 = & V_13 -> V_94 [ V_91 ] ;
struct V_61 * V_62 = V_13 -> V_63 -> V_62 ;
struct V_95 V_96 ;
V_96 . V_62 = V_62 ;
V_96 . V_97 = V_98 ;
V_96 . V_99 = F_16 ( V_13 , V_91 , V_47 , 0 ) ;
V_96 . V_10 = V_13 -> V_52 ;
V_96 . V_100 = ( V_101 ) V_13 ;
if ( V_13 -> V_84 )
return - V_59 ;
F_29 ( V_13 -> V_83 ) ;
if ( V_91 == 0 && ( V_47 == V_13 -> V_77 || V_47 == 0 ) ) {
F_32 ( L_11 ) ;
return - V_59 ;
}
if ( V_62 -> V_96 ( V_62 , & V_96 ) ) {
F_32 ( L_12 ,
V_47 , V_91 ) ;
goto error;
}
if ( V_96 . V_102 == V_103 )
F_35 ( & V_13 -> V_104 ) ;
if ( V_96 . V_102 != V_105 ) {
F_32 ( L_13 ,
V_47 , V_91 ) ;
goto error;
}
if ( V_92 )
F_36 ( & V_46 -> V_106 ,
( const unsigned char * ) & V_47 , sizeof( V_47 ) ) ;
return 0 ;
error:
F_34 ( V_13 , V_91 , V_47 ) ;
return - V_59 ;
}
static void V_98 ( struct V_95 * V_107 )
{
struct V_12 * V_13 = (struct V_12 * ) V_107 -> V_100 ;
F_37 ( & V_13 -> V_104 ) ;
}
static int F_38 ( struct V_12 * V_13 , int V_46 , int V_47 )
{
int V_48 ;
struct V_38 V_39 ;
int V_108 [] = { - 3 , 0 , 0 , 0 } ;
int V_35 = 0 ;
int V_109 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ;
V_48 += V_49 ) {
if ( F_22 ( V_13 , V_46 , V_47 , V_48 , NULL , & V_39 ) )
return - 2 ;
V_109 = F_12 ( & V_39 ) ;
if ( V_108 [ V_35 ] != V_109 )
V_108 [ ++ V_35 ] = V_109 ;
if ( V_35 == 3 )
return - V_59 ;
}
if ( V_35 == 2 ) {
F_33 ( V_13 , V_46 , V_47 , 1 ) ;
return 1 ;
}
return 0 ;
}
int F_39 ( struct V_12 * V_13 , struct V_61 * V_62 )
{
int V_35 ;
int V_110 = V_62 -> V_111 / ( 1024 * 1024 ) ;
V_13 -> V_83 = V_62 -> type == V_112 ;
V_13 -> V_50 = 1 ;
V_13 -> V_69 = 0 ;
switch ( V_110 ) {
case 1 :
V_13 -> V_51 = 256 ;
V_13 -> V_55 = 250 ;
V_13 -> V_52 = 8 * V_49 ;
V_13 -> V_69 = 1 ;
break;
case 2 :
if ( V_62 -> V_113 == V_21 ) {
V_13 -> V_51 = 512 ;
V_13 -> V_55 = 500 ;
V_13 -> V_52 = 8 * V_49 ;
V_13 -> V_69 = 1 ;
} else {
if ( ! V_13 -> V_83 )
return - V_114 ;
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
if ( V_110 >= 16 ) {
V_13 -> V_50 = V_110 / 16 ;
V_13 -> V_51 = 1024 ;
V_13 -> V_55 = 1000 ;
V_13 -> V_52 = 32 * V_49 ;
}
if ( V_62 -> V_115 > V_13 -> V_52 )
return - V_114 ;
if ( V_62 -> V_113 > V_49 )
return - V_114 ;
if ( V_13 -> V_69 && V_62 -> V_116 < V_117 )
return - V_114 ;
if ( ! V_13 -> V_69 && V_62 -> V_116 < V_42 )
return - V_114 ;
if ( ! V_62 -> V_79 || ! V_62 -> V_85 )
return - V_114 ;
for ( V_35 = 0 ; V_35 < F_40 ( V_118 ) ; V_35 ++ ) {
if ( V_118 [ V_35 ] . V_111 == V_110 ) {
V_13 -> V_119 = V_118 [ V_35 ] . V_120 ;
V_13 -> V_121 = V_118 [ V_35 ] . V_122 ;
V_13 -> V_123 = V_118 [ V_35 ] . V_124 ;
return 0 ;
}
}
F_32 ( L_14 , V_110 ) ;
V_13 -> V_119 = 985 ;
V_13 -> V_121 = 33 ;
V_13 -> V_123 = 63 ;
return 0 ;
}
static int F_41 ( struct V_12 * V_13 )
{
struct V_38 V_39 ;
if ( F_22 ( V_13 ,
0 , V_13 -> V_77 , V_13 -> V_78 , V_13 -> V_19 , & V_39 ) )
return - V_59 ;
if ( ! F_26 ( & V_39 ) || ! F_42 ( & V_39 ) )
return - V_59 ;
if ( ! memcmp ( V_13 -> V_19 + V_13 -> V_125 ,
V_126 , sizeof( V_126 ) ) ) {
return 0 ;
}
return - V_59 ;
}
static int F_43 ( struct V_12 * V_13 )
{
struct V_38 V_39 ;
int V_47 , V_48 ;
int V_127 = 0 ;
int V_128 = 0 ;
for ( V_47 = 0 ; V_47 < V_13 -> V_51 - V_13 -> V_55 ; V_47 ++ ) {
if ( F_22 ( V_13 , 0 , V_47 , 0 , NULL , & V_39 ) )
continue;
if ( ! F_42 ( & V_39 ) )
continue;
V_127 = 1 ;
break;
}
if ( ! V_127 )
return - V_59 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_52 ;
V_48 += V_49 ) {
if ( F_22 ( V_13 , 0 , V_47 , V_48 , NULL , & V_39 ) )
continue;
if ( ! F_26 ( & V_39 ) )
continue;
break;
}
if ( V_48 == V_13 -> V_52 )
return - V_59 ;
V_13 -> V_77 = V_47 ;
V_13 -> V_78 = V_48 ;
V_13 -> V_125 = 0 ;
V_128 = ! F_41 ( V_13 ) ;
if ( ! V_128 ) {
V_13 -> V_125 = V_21 ;
V_128 = ! F_41 ( V_13 ) ;
}
if ( V_128 ) {
F_25 ( L_15 ,
V_47 * V_13 -> V_52 +
V_48 + V_13 -> V_125 ) ;
return 0 ;
}
return - V_59 ;
}
static int F_23 ( struct V_12 * V_13 )
{
if ( F_41 ( V_13 ) ) {
if ( ! V_13 -> V_84 ) {
F_32 ( L_16 ) ;
V_13 -> V_84 = 1 ;
}
return - V_59 ;
}
return 0 ;
}
static int F_44 ( struct V_12 * V_13 , int V_91 )
{
struct V_93 * V_46 = & V_13 -> V_94 [ V_91 ] ;
struct V_38 V_39 ;
V_37 V_47 ;
int V_36 ;
int V_35 = 0 ;
int V_10 ;
F_25 ( L_17 , V_91 ) ;
V_46 -> V_129 = F_5 ( V_13 -> V_55 * 2 , V_23 ) ;
if ( ! V_46 -> V_129 )
return - V_130 ;
memset ( V_46 -> V_129 , - 1 , V_13 -> V_55 * 2 ) ;
if ( F_45 ( & V_46 -> V_106 , V_13 -> V_51 * 2 , V_23 ) ) {
F_8 ( V_46 -> V_129 ) ;
return - V_130 ;
}
for ( V_47 = 0 ; V_47 < V_13 -> V_51 ; V_47 ++ ) {
if ( V_91 == 0 && V_47 <= V_13 -> V_77 )
continue;
if ( F_22 ( V_13 , V_91 , V_47 , 0 , NULL , & V_39 ) )
return - V_59 ;
if ( F_46 ( & V_39 ) ) {
F_36 ( & V_46 -> V_106 ,
( unsigned char * ) & V_47 , 2 ) ;
continue;
}
if ( ! F_42 ( & V_39 ) ) {
F_25 ( L_18 , V_47 ) ;
continue;
}
V_36 = F_12 ( & V_39 ) ;
if ( V_36 == - 2 || V_36 >= V_13 -> V_55 ) {
F_25 ( L_19 , V_47 , V_36 ) ;
continue;
}
if ( V_46 -> V_129 [ V_36 ] < 0 ) {
F_47 ( L_20 , V_47 , V_36 ) ;
V_46 -> V_129 [ V_36 ] = V_47 ;
continue;
}
F_32 ( L_21
L_22 ,
V_36 , V_46 -> V_129 [ V_36 ] , V_47 , V_91 ) ;
if ( F_38 ( V_13 , V_91 , V_47 ) )
continue;
if ( F_38 ( V_13 , V_91 ,
V_46 -> V_129 [ V_36 ] ) ) {
V_46 -> V_129 [ V_36 ] = V_47 ;
continue;
}
F_32 ( L_23 ) ;
F_33 ( V_13 , V_91 , V_47 , 1 ) ;
}
F_25 ( L_24 ) ;
V_46 -> V_131 = 1 ;
if ( ! F_48 ( & V_46 -> V_106 ) ) {
F_32 ( L_25 , V_91 ) ;
return 0 ;
}
F_49 ( & V_35 , 2 ) ;
V_35 %= ( F_48 ( & V_46 -> V_106 ) / 2 ) ;
while ( V_35 -- ) {
V_10 = F_50 ( & V_46 -> V_106 ,
( unsigned char * ) & V_47 , 2 ) ;
F_15 ( V_10 != 2 ) ;
F_36 ( & V_46 -> V_106 , ( const unsigned char * ) & V_47 , 2 ) ;
}
return 0 ;
}
struct V_93 * F_51 ( struct V_12 * V_13 , int V_91 )
{
struct V_93 * V_46 ;
int error ;
F_29 ( V_91 >= V_13 -> V_50 ) ;
V_46 = & V_13 -> V_94 [ V_91 ] ;
if ( ! V_46 -> V_131 ) {
error = F_44 ( V_13 , V_91 ) ;
if ( error )
return F_52 ( error ) ;
}
return V_46 ;
}
void F_53 ( struct V_12 * V_13 )
{
V_13 -> V_132 = 0xFFFFFFFF ;
V_13 -> V_133 = 1 ;
V_13 -> V_134 = - 1 ;
V_13 -> V_135 = - 1 ;
}
void F_54 ( struct V_12 * V_13 , char * V_56 , int V_48 )
{
memcpy ( V_13 -> V_136 + V_48 , V_56 , V_49 ) ;
F_55 ( V_48 / V_49 , & V_13 -> V_132 ) ;
V_13 -> V_133 = 0 ;
}
int F_56 ( struct V_12 * V_13 , char * V_56 , int V_48 )
{
if ( F_31 ( V_48 / V_49 ,
& V_13 -> V_132 ) )
return - 1 ;
memcpy ( V_56 , V_13 -> V_136 + V_48 , V_49 ) ;
return 0 ;
}
int F_57 ( struct V_12 * V_13 )
{
struct V_93 * V_46 ;
int V_137 ;
V_37 V_138 ;
int V_91 = V_13 -> V_134 ;
int V_139 ;
if ( V_13 -> V_133 )
return 0 ;
if ( V_13 -> V_84 )
return - V_59 ;
F_29 ( V_91 < 0 ) ;
V_46 = & V_13 -> V_94 [ V_91 ] ;
V_139 = V_46 -> V_129 [ V_13 -> V_135 ] ;
F_58 (sector_num, &ftl->cache_data_invalid_bitmap,
ftl->block_size / SM_SECTOR_SIZE) {
if ( ! F_22 ( V_13 ,
V_91 , V_139 , V_137 * V_49 ,
V_13 -> V_136 + V_137 * V_49 , NULL ) )
F_55 ( V_137 ,
& V_13 -> V_132 ) ;
}
V_88:
if ( V_13 -> V_84 )
return - V_59 ;
if ( F_50 ( & V_46 -> V_106 ,
( unsigned char * ) & V_138 , 2 ) != 2 ) {
F_25 ( L_26 ) ;
return - V_59 ;
}
if ( F_30 ( V_13 , V_13 -> V_136 , V_91 , V_138 ,
V_13 -> V_135 , V_13 -> V_132 ) )
goto V_88;
V_46 -> V_129 [ V_13 -> V_135 ] = V_138 ;
if ( V_139 > 0 )
F_33 ( V_13 , V_91 , V_139 , 1 ) ;
F_53 ( V_13 ) ;
return 0 ;
}
static void F_59 ( unsigned long V_9 )
{
struct V_12 * V_13 = (struct V_12 * ) V_9 ;
F_60 ( V_140 , & V_13 -> V_141 ) ;
}
static void F_61 ( struct V_142 * V_143 )
{
struct V_12 * V_13 = F_2 ( V_143 , struct V_12 , V_141 ) ;
F_62 ( & V_13 -> V_144 ) ;
F_57 ( V_13 ) ;
F_63 ( & V_13 -> V_144 ) ;
return;
}
static int F_64 ( struct V_145 * V_2 ,
unsigned long V_146 , char * V_5 )
{
struct V_12 * V_13 = V_2 -> V_100 ;
struct V_93 * V_46 ;
int error = 0 , V_147 = 0 ;
int V_91 , V_47 , V_48 ;
F_17 ( V_13 , V_146 << 9 , & V_91 , & V_47 , & V_48 ) ;
F_62 ( & V_13 -> V_144 ) ;
V_46 = F_51 ( V_13 , V_91 ) ;
if ( F_65 ( V_46 ) ) {
error = F_66 ( V_46 ) ;
goto V_148;
}
if ( V_13 -> V_134 == V_91 && V_13 -> V_135 == V_47 ) {
V_147 = 1 ;
if ( ! F_56 ( V_13 , V_5 , V_48 ) )
goto V_148;
}
V_47 = V_46 -> V_129 [ V_47 ] ;
if ( V_47 == - 1 ) {
memset ( V_5 , 0xFF , V_49 ) ;
goto V_148;
}
if ( F_22 ( V_13 , V_91 , V_47 , V_48 , V_5 , NULL ) ) {
error = - V_59 ;
goto V_148;
}
if ( V_147 )
F_54 ( V_13 , V_5 , V_48 ) ;
V_148:
F_63 ( & V_13 -> V_144 ) ;
return error ;
}
static int F_67 ( struct V_145 * V_2 ,
unsigned long V_149 , char * V_5 )
{
struct V_12 * V_13 = V_2 -> V_100 ;
struct V_93 * V_46 ;
int error , V_91 , V_47 , V_48 ;
F_29 ( V_13 -> V_83 ) ;
F_17 ( V_13 , V_149 << 9 , & V_91 , & V_47 , & V_48 ) ;
F_68 ( & V_13 -> V_150 ) ;
F_62 ( & V_13 -> V_144 ) ;
V_46 = F_51 ( V_13 , V_91 ) ;
if ( F_65 ( V_46 ) ) {
error = F_66 ( V_46 ) ;
goto V_148;
}
if ( V_13 -> V_135 != V_47 || V_13 -> V_134 != V_91 ) {
error = F_57 ( V_13 ) ;
if ( error )
goto V_148;
V_13 -> V_135 = V_47 ;
V_13 -> V_134 = V_91 ;
}
F_54 ( V_13 , V_5 , V_48 ) ;
V_148:
F_69 ( & V_13 -> V_150 , V_151 + F_70 ( V_152 ) ) ;
F_63 ( & V_13 -> V_144 ) ;
return error ;
}
static int F_71 ( struct V_145 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_100 ;
int V_153 ;
F_62 ( & V_13 -> V_144 ) ;
V_153 = F_57 ( V_13 ) ;
F_63 ( & V_13 -> V_144 ) ;
return V_153 ;
}
static int F_72 ( struct V_145 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_100 ;
F_62 ( & V_13 -> V_144 ) ;
F_73 ( & V_13 -> V_150 ) ;
F_74 ( & V_13 -> V_141 ) ;
F_57 ( V_13 ) ;
F_63 ( & V_13 -> V_144 ) ;
return 0 ;
}
static int F_75 ( struct V_145 * V_2 , struct V_154 * V_155 )
{
struct V_12 * V_13 = V_2 -> V_100 ;
V_155 -> V_121 = V_13 -> V_121 ;
V_155 -> V_123 = V_13 -> V_123 ;
V_155 -> V_119 = V_13 -> V_119 ;
return 0 ;
}
static void F_76 ( struct V_156 * V_157 , struct V_61 * V_62 )
{
struct V_145 * V_63 ;
struct V_12 * V_13 ;
V_13 = F_6 ( sizeof( struct V_12 ) , V_23 ) ;
if ( ! V_13 )
goto V_24;
F_77 ( & V_13 -> V_144 ) ;
F_78 ( & V_13 -> V_150 , F_59 , ( unsigned long ) V_13 ) ;
F_79 ( & V_13 -> V_141 , F_61 ) ;
F_80 ( & V_13 -> V_104 ) ;
if ( F_39 ( V_13 , V_62 ) ) {
F_25 ( L_27 ) ;
goto V_25;
}
V_13 -> V_19 = F_6 ( V_49 , V_23 ) ;
if ( ! V_13 -> V_19 )
goto V_25;
V_13 -> V_94 = F_6 ( sizeof( struct V_93 ) * V_13 -> V_50 ,
V_23 ) ;
if ( ! V_13 -> V_94 )
goto V_31;
V_13 -> V_136 = F_6 ( V_13 -> V_52 , V_23 ) ;
if ( ! V_13 -> V_136 )
goto V_32;
F_53 ( V_13 ) ;
V_63 = F_6 ( sizeof( struct V_145 ) , V_23 ) ;
if ( ! V_63 )
goto V_158;
V_13 -> V_63 = V_63 ;
V_63 -> V_100 = V_13 ;
V_63 -> V_157 = V_157 ;
V_63 -> V_62 = V_62 ;
V_63 -> V_159 = - 1 ;
V_63 -> V_111 = ( V_13 -> V_52 * V_13 -> V_55 * V_13 -> V_50 ) >> 9 ;
V_63 -> V_83 = V_13 -> V_83 ;
if ( F_43 ( V_13 ) ) {
F_25 ( L_28 ) ;
goto V_160;
}
V_13 -> V_34 = F_3 ( V_13 ) ;
if ( ! V_13 -> V_34 )
goto V_160;
V_63 -> V_34 = V_13 -> V_34 ;
F_32 ( L_29 ,
( int ) ( V_62 -> V_111 / ( 1024 * 1024 ) ) , V_62 -> V_161 ) ;
F_25 ( L_30 ) ;
F_25 ( L_31 ,
V_13 -> V_50 , V_13 -> V_55 ,
V_13 -> V_51 - V_13 -> V_55 ) ;
F_25 ( L_32 ,
V_13 -> V_52 ) ;
if ( F_81 ( V_63 ) ) {
F_25 ( L_33 ) ;
goto V_160;
}
return;
V_160:
F_8 ( V_63 ) ;
V_158:
F_8 ( V_13 -> V_136 ) ;
V_32:
F_8 ( V_13 -> V_94 ) ;
V_31:
F_8 ( V_13 -> V_19 ) ;
V_25:
F_8 ( V_13 ) ;
V_24:
return;
}
static void F_82 ( struct V_145 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_100 ;
int V_35 ;
F_83 ( V_2 ) ;
V_13 -> V_63 = NULL ;
for ( V_35 = 0 ; V_35 < V_13 -> V_50 ; V_35 ++ ) {
if ( ! V_13 -> V_94 [ V_35 ] . V_131 )
continue;
F_8 ( V_13 -> V_94 [ V_35 ] . V_129 ) ;
F_84 ( & V_13 -> V_94 [ V_35 ] . V_106 ) ;
}
F_9 ( V_13 ) ;
F_8 ( V_13 -> V_19 ) ;
F_8 ( V_13 -> V_94 ) ;
F_8 ( V_13 -> V_136 ) ;
F_8 ( V_13 ) ;
}
static T_5 int F_85 ( void )
{
int error = 0 ;
V_140 = F_86 ( L_34 ) ;
if ( F_65 ( V_140 ) )
return F_66 ( V_140 ) ;
error = F_87 ( & V_162 ) ;
if ( error )
F_88 ( V_140 ) ;
return error ;
}
static void T_6 F_89 ( void )
{
F_88 ( V_140 ) ;
F_90 ( & V_162 ) ;
}
