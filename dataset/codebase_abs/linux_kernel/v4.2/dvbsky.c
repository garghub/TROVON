static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 , T_1 * V_5 , T_2 V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_10 ) ;
if ( V_4 != 0 )
memcpy ( V_9 -> V_11 , V_3 , V_4 ) ;
V_7 = F_4 ( V_2 , V_9 -> V_11 , V_4 ,
V_9 -> V_12 , V_6 ) ;
if ( ! V_7 && ( V_6 != 0 ) )
memcpy ( V_5 , V_9 -> V_12 , V_6 ) ;
F_5 ( & V_2 -> V_10 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_7 ;
T_1 V_14 [ 3 ] = { 0x37 , 0 , 0 } ;
T_1 V_15 [ 3 ] = { 0x36 , 3 , 0 } ;
F_3 ( & V_9 -> V_16 ) ;
V_7 = F_1 ( V_2 , V_14 , 3 , NULL , 0 ) ;
if ( ! V_7 && V_13 ) {
F_7 ( 20 ) ;
V_7 = F_1 ( V_2 , V_15 , 3 , NULL , 0 ) ;
}
F_5 ( & V_9 -> V_16 ) ;
return V_7 ;
}
static int F_8 ( struct V_17 * V_18 , int V_13 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
return F_6 ( V_2 , ( V_13 == 0 ) ? 0 : 1 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 )
{
int V_7 ;
T_1 V_11 [ 3 ] , V_12 [ 2 ] ;
V_11 [ 0 ] = 0x0e ;
V_11 [ 1 ] = V_19 ;
V_11 [ 2 ] = V_20 ;
V_7 = F_1 ( V_2 , V_11 , 3 , V_12 , 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_23 * V_24 , struct V_25 V_26 [] ,
int V_27 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
int V_7 = 0 ;
T_1 V_12 [ 64 ] , V_11 [ 64 ] ;
if ( F_14 ( & V_2 -> V_28 ) < 0 )
return - V_29 ;
if ( V_27 > 2 ) {
F_11 ( & V_2 -> V_21 -> V_22 ,
L_2 , V_27 ) ;
V_7 = - V_30 ;
goto V_31;
}
if ( V_27 == 1 ) {
if ( V_26 [ 0 ] . V_32 > 60 ) {
F_11 ( & V_2 -> V_21 -> V_22 ,
L_3 ,
V_26 [ 0 ] . V_32 ) ;
V_7 = - V_30 ;
goto V_31;
}
if ( V_26 [ 0 ] . V_33 & V_34 ) {
V_11 [ 0 ] = 0x09 ;
V_11 [ 1 ] = 0 ;
V_11 [ 2 ] = V_26 [ 0 ] . V_32 ;
V_11 [ 3 ] = V_26 [ 0 ] . V_35 ;
V_7 = F_1 ( V_2 , V_11 , 4 ,
V_12 , V_26 [ 0 ] . V_32 + 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 , V_7 ) ;
if ( ! V_7 )
memcpy ( V_26 [ 0 ] . V_36 , & V_12 [ 1 ] , V_26 [ 0 ] . V_32 ) ;
} else {
V_11 [ 0 ] = 0x08 ;
V_11 [ 1 ] = V_26 [ 0 ] . V_35 ;
V_11 [ 2 ] = V_26 [ 0 ] . V_32 ;
memcpy ( & V_11 [ 3 ] , V_26 [ 0 ] . V_36 , V_26 [ 0 ] . V_32 ) ;
V_7 = F_1 ( V_2 , V_11 ,
V_26 [ 0 ] . V_32 + 3 , V_12 , 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 , V_7 ) ;
}
} else {
if ( ( V_26 [ 0 ] . V_32 > 60 ) || ( V_26 [ 1 ] . V_32 > 60 ) ) {
F_11 ( & V_2 -> V_21 -> V_22 ,
L_4 ,
V_26 [ 0 ] . V_32 , V_26 [ 1 ] . V_32 ) ;
V_7 = - V_30 ;
goto V_31;
}
V_11 [ 0 ] = 0x09 ;
V_11 [ 1 ] = V_26 [ 0 ] . V_32 ;
V_11 [ 2 ] = V_26 [ 1 ] . V_32 ;
V_11 [ 3 ] = V_26 [ 0 ] . V_35 ;
memcpy ( & V_11 [ 4 ] , V_26 [ 0 ] . V_36 , V_26 [ 0 ] . V_32 ) ;
V_7 = F_1 ( V_2 , V_11 ,
V_26 [ 0 ] . V_32 + 4 , V_12 , V_26 [ 1 ] . V_32 + 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 , V_7 ) ;
if ( ! V_7 )
memcpy ( V_26 [ 1 ] . V_36 , & V_12 [ 1 ] , V_26 [ 1 ] . V_32 ) ;
}
V_31:
F_5 ( & V_2 -> V_28 ) ;
return ( V_7 ) ? V_7 : V_27 ;
}
static T_3 F_15 ( struct V_23 * V_37 )
{
return V_38 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_3 V_39 = 0xffff , V_40 ;
T_1 V_41 , V_42 ;
T_1 V_11 [ 2 ] , V_12 [ 2 ] , V_43 ;
int V_7 ;
V_11 [ 0 ] = 0x10 ;
V_7 = F_1 ( V_2 , V_11 , 1 , V_12 , 2 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 , V_7 ) ;
if ( V_7 == 0 )
V_39 = ( V_12 [ 0 ] << 8 ) | V_12 [ 1 ] ;
if ( V_39 != 0xffff ) {
F_17 ( & V_2 -> V_21 -> V_22 , L_5 , V_39 ) ;
V_41 = V_39 & 0x3F ;
V_42 = ( V_39 & 0x7C0 ) >> 6 ;
V_43 = ( V_39 & 0x800 ) ? 1 : 0 ;
V_40 = V_42 << 8 | V_41 ;
F_18 ( V_2 -> V_44 , V_45 , V_40 , V_43 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( V_48 ) {
V_47 -> V_49 = NULL ;
return 0 ;
}
V_47 -> V_50 = V_51 ;
V_47 -> V_52 = F_16 ;
V_47 -> V_53 = 300 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 ,
enum V_54 V_55 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_20 ;
if ( V_55 == V_56 )
V_20 = 0 ;
else
V_20 = 1 ;
F_10 ( V_2 , 0x80 , V_20 ) ;
return V_9 -> V_57 ( V_18 , V_55 ) ;
}
static int F_21 ( struct V_58 * V_24 , T_1 V_59 [ 6 ] )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
T_1 V_11 [] = { 0x1e , 0x00 } ;
T_1 V_12 [ 6 ] = { 0 } ;
struct V_25 V_26 [] = {
{
. V_35 = 0x51 ,
. V_33 = 0 ,
. V_36 = V_11 ,
. V_32 = 2 ,
} , {
. V_35 = 0x51 ,
. V_33 = V_34 ,
. V_36 = V_12 ,
. V_32 = 6 ,
}
} ;
if ( F_23 ( & V_2 -> V_60 , V_26 , 2 ) == 2 )
memcpy ( V_59 , V_12 , 6 ) ;
return 0 ;
}
static int F_24 ( struct V_17 * V_18 ,
enum V_61 * V_62 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = V_9 -> V_63 ( V_18 , V_62 ) ;
if ( ( * V_62 & V_64 ) && ( ! V_9 -> V_65 ) )
F_6 ( V_2 , 1 ) ;
V_9 -> V_65 = ( * V_62 & V_64 ) ? 1 : 0 ;
return V_7 ;
}
static int F_25 ( struct V_58 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_66 * V_67 ;
struct V_68 V_69 ;
struct V_70 V_70 = {} ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_24 -> V_18 [ 0 ] = F_27 ( V_71 ,
& V_72 ,
& V_2 -> V_60 ,
& V_23 ) ;
if ( ! V_24 -> V_18 [ 0 ] ) {
F_11 ( & V_2 -> V_21 -> V_22 , L_6 ) ;
V_7 = - V_73 ;
goto V_74;
}
V_70 . V_18 = V_24 -> V_18 [ 0 ] ;
V_70 . V_75 = V_76 ;
F_28 ( V_69 . type , L_7 , V_77 ) ;
V_69 . V_35 = 0x60 ;
V_69 . V_78 = & V_70 ;
F_29 ( L_7 ) ;
V_67 = F_30 ( V_23 , & V_69 ) ;
if ( V_67 == NULL || V_67 -> V_22 . V_79 == NULL ) {
F_31 ( V_24 -> V_18 [ 0 ] ) ;
V_7 = - V_73 ;
goto V_74;
}
if ( ! F_32 ( V_67 -> V_22 . V_79 -> V_80 ) ) {
F_33 ( V_67 ) ;
F_31 ( V_24 -> V_18 [ 0 ] ) ;
V_7 = - V_73 ;
goto V_74;
}
V_24 -> V_18 [ 0 ] -> V_81 . V_82 =
V_24 -> V_18 [ 0 ] -> V_81 . V_83 . V_84 ;
V_9 -> V_63 = V_24 -> V_18 [ 0 ] -> V_81 . V_85 ;
V_24 -> V_18 [ 0 ] -> V_81 . V_85 = F_24 ;
V_9 -> V_57 = V_24 -> V_18 [ 0 ] -> V_81 . V_86 ;
V_24 -> V_18 [ 0 ] -> V_81 . V_86 = F_20 ;
V_9 -> V_87 = V_67 ;
V_74:
return V_7 ;
}
static int F_34 ( struct V_17 * V_18 ,
enum V_54 V_55 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_20 ;
if ( V_55 == V_56 )
V_20 = 0 ;
else
V_20 = 1 ;
F_10 ( V_2 , 0x00 , V_20 ) ;
return V_9 -> V_57 ( V_18 , V_55 ) ;
}
static int F_35 ( void * V_88 , T_1 V_89 , int V_35 ,
T_1 V_90 , int * V_91 )
{
struct V_1 * V_2 = V_88 ;
int V_7 = 0 ;
T_1 V_92 [ 4 ] , V_93 [ 2 ] , V_94 , V_95 ;
V_92 [ 1 ] = ( T_1 ) ( ( V_35 >> 8 ) & 0xff ) ;
V_92 [ 2 ] = ( T_1 ) ( V_35 & 0xff ) ;
if ( V_89 ) {
V_92 [ 0 ] = 0x71 ;
V_94 = 3 ;
V_95 = 2 ;
} else {
V_92 [ 0 ] = 0x70 ;
V_92 [ 3 ] = V_90 ;
V_94 = 4 ;
V_95 = 1 ;
}
V_7 = F_1 ( V_2 , V_92 , V_94 ,
V_93 , V_95 ) ;
if ( V_7 )
goto V_96;
if ( V_89 )
* V_91 = V_93 [ 1 ] ;
return V_7 ;
V_96:
F_11 ( & V_2 -> V_21 -> V_22 , L_8 , V_7 ) ;
return V_7 ;
}
static int F_36 ( struct V_58 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_66 * V_97 , * V_98 ;
struct V_68 V_69 ;
struct V_99 V_99 ;
struct V_70 V_70 = {} ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_24 -> V_18 [ 0 ] = F_27 ( V_71 ,
& V_100 ,
& V_2 -> V_60 ,
& V_23 ) ;
if ( ! V_24 -> V_18 [ 0 ] ) {
F_11 ( & V_2 -> V_21 -> V_22 , L_9 ) ;
V_7 = - V_73 ;
goto V_74;
}
V_70 . V_18 = V_24 -> V_18 [ 0 ] ;
V_70 . V_75 = V_76 ;
F_28 ( V_69 . type , L_7 , V_77 ) ;
V_69 . V_35 = 0x60 ;
V_69 . V_78 = & V_70 ;
F_29 ( L_7 ) ;
V_97 = F_30 ( V_23 , & V_69 ) ;
if ( V_97 == NULL || V_97 -> V_22 . V_79 == NULL ) {
V_7 = - V_73 ;
goto V_101;
}
if ( ! F_32 ( V_97 -> V_22 . V_79 -> V_80 ) ) {
V_7 = - V_73 ;
goto V_102;
}
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_103 = & V_24 -> V_103 ;
V_99 . V_88 = V_2 ;
V_99 . V_104 = F_35 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_28 ( V_69 . type , L_10 , V_77 ) ;
V_69 . V_35 = 0x40 ;
V_69 . V_78 = & V_99 ;
F_29 ( L_10 ) ;
V_98 = F_30 ( & V_2 -> V_60 , & V_69 ) ;
if ( V_98 == NULL || V_98 -> V_22 . V_79 == NULL ) {
V_7 = - V_73 ;
goto V_105;
}
if ( ! F_32 ( V_98 -> V_22 . V_79 -> V_80 ) ) {
V_7 = - V_73 ;
goto V_106;
}
V_24 -> V_18 [ 0 ] -> V_81 . V_82 =
V_24 -> V_18 [ 0 ] -> V_81 . V_83 . V_84 ;
V_9 -> V_63 = V_24 -> V_18 [ 0 ] -> V_81 . V_85 ;
V_24 -> V_18 [ 0 ] -> V_81 . V_85 = F_24 ;
V_9 -> V_57 = V_24 -> V_18 [ 0 ] -> V_81 . V_86 ;
V_24 -> V_18 [ 0 ] -> V_81 . V_86 = F_34 ;
V_9 -> V_87 = V_97 ;
V_9 -> V_107 = V_98 ;
return V_7 ;
V_106:
F_33 ( V_98 ) ;
V_105:
F_37 ( V_97 -> V_22 . V_79 -> V_80 ) ;
V_102:
F_33 ( V_97 ) ;
V_101:
F_31 ( V_24 -> V_18 [ 0 ] ) ;
V_74:
return V_7 ;
}
static int F_38 ( struct V_58 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_66 * V_108 , * V_97 , * V_98 ;
struct V_68 V_69 ;
struct V_109 V_109 ;
struct V_110 V_110 ;
struct V_99 V_99 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_23 = & V_23 ;
V_109 . V_18 = & V_24 -> V_18 [ 0 ] ;
V_109 . V_111 = V_112 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_28 ( V_69 . type , L_11 , V_77 ) ;
V_69 . V_35 = 0x64 ;
V_69 . V_78 = & V_109 ;
F_29 ( V_69 . type ) ;
V_108 = F_30 ( & V_2 -> V_60 , & V_69 ) ;
if ( V_108 == NULL ||
V_108 -> V_22 . V_79 == NULL )
goto V_113;
if ( ! F_32 ( V_108 -> V_22 . V_79 -> V_80 ) )
goto V_114;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_18 = V_24 -> V_18 [ 0 ] ;
V_110 . V_115 = 1 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_28 ( V_69 . type , L_12 , V_77 ) ;
V_69 . V_35 = 0x60 ;
V_69 . V_78 = & V_110 ;
F_29 ( V_69 . type ) ;
V_97 = F_30 ( V_23 , & V_69 ) ;
if ( V_97 == NULL ||
V_97 -> V_22 . V_79 == NULL )
goto V_101;
if ( ! F_32 ( V_97 -> V_22 . V_79 -> V_80 ) )
goto V_102;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_103 = & V_24 -> V_103 ;
V_99 . V_88 = V_2 ;
V_99 . V_104 = F_35 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_28 ( V_69 . type , L_10 , V_77 ) ;
V_69 . V_35 = 0x40 ;
V_69 . V_78 = & V_99 ;
F_29 ( V_69 . type ) ;
V_98 = F_30 ( & V_2 -> V_60 , & V_69 ) ;
if ( V_98 == NULL || V_98 -> V_22 . V_79 == NULL )
goto V_105;
if ( ! F_32 ( V_98 -> V_22 . V_79 -> V_80 ) )
goto V_106;
V_9 -> V_116 = V_108 ;
V_9 -> V_87 = V_97 ;
V_9 -> V_107 = V_98 ;
return V_7 ;
V_106:
F_33 ( V_98 ) ;
V_105:
F_37 ( V_97 -> V_22 . V_79 -> V_80 ) ;
V_102:
F_33 ( V_97 ) ;
V_101:
F_37 ( V_108 -> V_22 . V_79 -> V_80 ) ;
V_114:
F_33 ( V_108 ) ;
V_113:
V_7 = - V_73 ;
return V_7 ;
}
static int F_39 ( struct V_58 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_66 * V_108 , * V_97 ;
struct V_68 V_69 ;
struct V_109 V_109 ;
struct V_110 V_110 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_23 = & V_23 ;
V_109 . V_18 = & V_24 -> V_18 [ 0 ] ;
V_109 . V_111 = V_112 ;
V_109 . V_117 = true ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_28 ( V_69 . type , L_11 , V_77 ) ;
V_69 . V_35 = 0x64 ;
V_69 . V_78 = & V_109 ;
F_29 ( V_69 . type ) ;
V_108 = F_30 ( & V_2 -> V_60 , & V_69 ) ;
if ( V_108 == NULL ||
V_108 -> V_22 . V_79 == NULL )
goto V_113;
if ( ! F_32 ( V_108 -> V_22 . V_79 -> V_80 ) )
goto V_114;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_18 = V_24 -> V_18 [ 0 ] ;
V_110 . V_115 = 1 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_28 ( V_69 . type , L_12 , V_77 ) ;
V_69 . V_35 = 0x60 ;
V_69 . V_78 = & V_110 ;
F_29 ( V_69 . type ) ;
V_97 = F_30 ( V_23 , & V_69 ) ;
if ( V_97 == NULL ||
V_97 -> V_22 . V_79 == NULL )
goto V_101;
if ( ! F_32 ( V_97 -> V_22 . V_79 -> V_80 ) )
goto V_102;
V_9 -> V_116 = V_108 ;
V_9 -> V_87 = V_97 ;
return V_7 ;
V_102:
F_33 ( V_97 ) ;
V_101:
F_37 ( V_108 -> V_22 . V_79 -> V_80 ) ;
V_114:
F_33 ( V_108 ) ;
V_113:
V_7 = - V_73 ;
return V_7 ;
}
static int F_40 ( struct V_1 * V_2 , const char * * V_118 )
{
F_10 ( V_2 , 0x04 , 1 ) ;
F_7 ( 20 ) ;
F_10 ( V_2 , 0x83 , 0 ) ;
F_10 ( V_2 , 0xc0 , 1 ) ;
F_7 ( 100 ) ;
F_10 ( V_2 , 0x83 , 1 ) ;
F_10 ( V_2 , 0xc0 , 0 ) ;
F_7 ( 50 ) ;
return V_119 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_42 ( & V_9 -> V_16 ) ;
V_9 -> V_65 = 0 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_66 * V_67 ;
V_67 = V_9 -> V_87 ;
if ( V_67 ) {
F_37 ( V_67 -> V_22 . V_79 -> V_80 ) ;
F_33 ( V_67 ) ;
}
V_67 = V_9 -> V_116 ;
if ( V_67 ) {
F_37 ( V_67 -> V_22 . V_79 -> V_80 ) ;
F_33 ( V_67 ) ;
}
V_67 = V_9 -> V_107 ;
if ( V_67 ) {
F_37 ( V_67 -> V_22 . V_79 -> V_80 ) ;
F_33 ( V_67 ) ;
}
}
