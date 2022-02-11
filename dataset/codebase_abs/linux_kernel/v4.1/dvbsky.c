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
T_4 V_54 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_20 ;
if ( V_54 == V_55 )
V_20 = 0 ;
else
V_20 = 1 ;
F_10 ( V_2 , 0x80 , V_20 ) ;
return V_9 -> V_56 ( V_18 , V_54 ) ;
}
static int F_21 ( struct V_57 * V_24 , T_1 V_58 [ 6 ] )
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
if ( F_23 ( & V_2 -> V_59 , V_26 , 2 ) == 2 )
memcpy ( V_58 , V_12 , 6 ) ;
return 0 ;
}
static int F_24 ( struct V_17 * V_18 , T_5 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = V_9 -> V_61 ( V_18 , V_60 ) ;
if ( ( * V_60 & V_62 ) && ( ! V_9 -> V_63 ) )
F_6 ( V_2 , 1 ) ;
V_9 -> V_63 = ( * V_60 & V_62 ) ? 1 : 0 ;
return V_7 ;
}
static int F_25 ( struct V_57 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_64 * V_65 ;
struct V_66 V_67 ;
struct V_68 V_68 = {} ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_24 -> V_18 [ 0 ] = F_27 ( V_69 ,
& V_70 ,
& V_2 -> V_59 ,
& V_23 ) ;
if ( ! V_24 -> V_18 [ 0 ] ) {
F_11 ( & V_2 -> V_21 -> V_22 , L_6 ) ;
V_7 = - V_71 ;
goto V_72;
}
V_68 . V_18 = V_24 -> V_18 [ 0 ] ;
F_28 ( V_67 . type , L_7 , V_73 ) ;
V_67 . V_35 = 0x60 ;
V_67 . V_74 = & V_68 ;
F_29 ( L_7 ) ;
V_65 = F_30 ( V_23 , & V_67 ) ;
if ( V_65 == NULL || V_65 -> V_22 . V_75 == NULL ) {
F_31 ( V_24 -> V_18 [ 0 ] ) ;
V_7 = - V_71 ;
goto V_72;
}
if ( ! F_32 ( V_65 -> V_22 . V_75 -> V_76 ) ) {
F_33 ( V_65 ) ;
F_31 ( V_24 -> V_18 [ 0 ] ) ;
V_7 = - V_71 ;
goto V_72;
}
V_24 -> V_18 [ 0 ] -> V_77 . V_78 =
V_24 -> V_18 [ 0 ] -> V_77 . V_79 . V_80 ;
V_9 -> V_61 = V_24 -> V_18 [ 0 ] -> V_77 . V_81 ;
V_24 -> V_18 [ 0 ] -> V_77 . V_81 = F_24 ;
V_9 -> V_56 = V_24 -> V_18 [ 0 ] -> V_77 . V_82 ;
V_24 -> V_18 [ 0 ] -> V_77 . V_82 = F_20 ;
V_9 -> V_83 = V_65 ;
V_72:
return V_7 ;
}
static int F_34 ( struct V_17 * V_18 ,
T_4 V_54 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_20 ;
if ( V_54 == V_55 )
V_20 = 0 ;
else
V_20 = 1 ;
F_10 ( V_2 , 0x00 , V_20 ) ;
return V_9 -> V_56 ( V_18 , V_54 ) ;
}
static int F_35 ( void * V_84 , T_1 V_85 , int V_35 ,
T_1 V_86 , int * V_87 )
{
struct V_1 * V_2 = V_84 ;
int V_7 = 0 ;
T_1 V_88 [ 4 ] , V_89 [ 2 ] , V_90 , V_91 ;
V_88 [ 1 ] = ( T_1 ) ( ( V_35 >> 8 ) & 0xff ) ;
V_88 [ 2 ] = ( T_1 ) ( V_35 & 0xff ) ;
if ( V_85 ) {
V_88 [ 0 ] = 0x71 ;
V_90 = 3 ;
V_91 = 2 ;
} else {
V_88 [ 0 ] = 0x70 ;
V_88 [ 3 ] = V_86 ;
V_90 = 4 ;
V_91 = 1 ;
}
V_7 = F_1 ( V_2 , V_88 , V_90 ,
V_89 , V_91 ) ;
if ( V_7 )
goto V_92;
if ( V_85 )
* V_87 = V_89 [ 1 ] ;
return V_7 ;
V_92:
F_11 ( & V_2 -> V_21 -> V_22 , L_8 , V_7 ) ;
return V_7 ;
}
static int F_36 ( struct V_57 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_64 * V_93 , * V_94 ;
struct V_66 V_67 ;
struct V_95 V_95 ;
struct V_68 V_68 = {} ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_24 -> V_18 [ 0 ] = F_27 ( V_69 ,
& V_96 ,
& V_2 -> V_59 ,
& V_23 ) ;
if ( ! V_24 -> V_18 [ 0 ] ) {
F_11 ( & V_2 -> V_21 -> V_22 , L_9 ) ;
V_7 = - V_71 ;
goto V_72;
}
V_68 . V_18 = V_24 -> V_18 [ 0 ] ;
F_28 ( V_67 . type , L_7 , V_73 ) ;
V_67 . V_35 = 0x60 ;
V_67 . V_74 = & V_68 ;
F_29 ( L_7 ) ;
V_93 = F_30 ( V_23 , & V_67 ) ;
if ( V_93 == NULL || V_93 -> V_22 . V_75 == NULL ) {
V_7 = - V_71 ;
goto V_97;
}
if ( ! F_32 ( V_93 -> V_22 . V_75 -> V_76 ) ) {
V_7 = - V_71 ;
goto V_98;
}
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_99 = & V_24 -> V_99 ;
V_95 . V_84 = V_2 ;
V_95 . V_100 = F_35 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
F_28 ( V_67 . type , L_10 , V_73 ) ;
V_67 . V_35 = 0x40 ;
V_67 . V_74 = & V_95 ;
F_29 ( L_10 ) ;
V_94 = F_30 ( & V_2 -> V_59 , & V_67 ) ;
if ( V_94 == NULL || V_94 -> V_22 . V_75 == NULL ) {
V_7 = - V_71 ;
goto V_101;
}
if ( ! F_32 ( V_94 -> V_22 . V_75 -> V_76 ) ) {
V_7 = - V_71 ;
goto V_102;
}
V_24 -> V_18 [ 0 ] -> V_77 . V_78 =
V_24 -> V_18 [ 0 ] -> V_77 . V_79 . V_80 ;
V_9 -> V_61 = V_24 -> V_18 [ 0 ] -> V_77 . V_81 ;
V_24 -> V_18 [ 0 ] -> V_77 . V_81 = F_24 ;
V_9 -> V_56 = V_24 -> V_18 [ 0 ] -> V_77 . V_82 ;
V_24 -> V_18 [ 0 ] -> V_77 . V_82 = F_34 ;
V_9 -> V_83 = V_93 ;
V_9 -> V_103 = V_94 ;
return V_7 ;
V_102:
F_33 ( V_94 ) ;
V_101:
F_37 ( V_93 -> V_22 . V_75 -> V_76 ) ;
V_98:
F_33 ( V_93 ) ;
V_97:
F_31 ( V_24 -> V_18 [ 0 ] ) ;
V_72:
return V_7 ;
}
static int F_38 ( struct V_57 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_64 * V_104 , * V_93 , * V_94 ;
struct V_66 V_67 ;
struct V_105 V_105 ;
struct V_106 V_106 ;
struct V_95 V_95 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_23 = & V_23 ;
V_105 . V_18 = & V_24 -> V_18 [ 0 ] ;
V_105 . V_107 = V_108 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
F_28 ( V_67 . type , L_11 , V_73 ) ;
V_67 . V_35 = 0x64 ;
V_67 . V_74 = & V_105 ;
F_29 ( V_67 . type ) ;
V_104 = F_30 ( & V_2 -> V_59 , & V_67 ) ;
if ( V_104 == NULL ||
V_104 -> V_22 . V_75 == NULL )
goto V_109;
if ( ! F_32 ( V_104 -> V_22 . V_75 -> V_76 ) )
goto V_110;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_18 = V_24 -> V_18 [ 0 ] ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
F_28 ( V_67 . type , L_12 , V_73 ) ;
V_67 . V_35 = 0x60 ;
V_67 . V_74 = & V_106 ;
F_29 ( V_67 . type ) ;
V_93 = F_30 ( V_23 , & V_67 ) ;
if ( V_93 == NULL ||
V_93 -> V_22 . V_75 == NULL )
goto V_97;
if ( ! F_32 ( V_93 -> V_22 . V_75 -> V_76 ) )
goto V_98;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_99 = & V_24 -> V_99 ;
V_95 . V_84 = V_2 ;
V_95 . V_100 = F_35 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
F_28 ( V_67 . type , L_10 , V_73 ) ;
V_67 . V_35 = 0x40 ;
V_67 . V_74 = & V_95 ;
F_29 ( V_67 . type ) ;
V_94 = F_30 ( & V_2 -> V_59 , & V_67 ) ;
if ( V_94 == NULL || V_94 -> V_22 . V_75 == NULL )
goto V_101;
if ( ! F_32 ( V_94 -> V_22 . V_75 -> V_76 ) )
goto V_102;
V_9 -> V_111 = V_104 ;
V_9 -> V_83 = V_93 ;
V_9 -> V_103 = V_94 ;
return V_7 ;
V_102:
F_33 ( V_94 ) ;
V_101:
F_37 ( V_93 -> V_22 . V_75 -> V_76 ) ;
V_98:
F_33 ( V_93 ) ;
V_97:
F_37 ( V_104 -> V_22 . V_75 -> V_76 ) ;
V_110:
F_33 ( V_104 ) ;
V_109:
V_7 = - V_71 ;
return V_7 ;
}
static int F_39 ( struct V_57 * V_24 )
{
struct V_8 * V_9 = F_26 ( V_24 ) ;
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_7 = 0 ;
struct V_23 * V_23 ;
struct V_64 * V_104 , * V_93 ;
struct V_66 V_67 ;
struct V_105 V_105 ;
struct V_106 V_106 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_23 = & V_23 ;
V_105 . V_18 = & V_24 -> V_18 [ 0 ] ;
V_105 . V_107 = V_108 | 0x40 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
F_28 ( V_67 . type , L_11 , V_73 ) ;
V_67 . V_35 = 0x64 ;
V_67 . V_74 = & V_105 ;
F_29 ( V_67 . type ) ;
V_104 = F_30 ( & V_2 -> V_59 , & V_67 ) ;
if ( V_104 == NULL ||
V_104 -> V_22 . V_75 == NULL )
goto V_109;
if ( ! F_32 ( V_104 -> V_22 . V_75 -> V_76 ) )
goto V_110;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_18 = V_24 -> V_18 [ 0 ] ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
F_28 ( V_67 . type , L_12 , V_73 ) ;
V_67 . V_35 = 0x60 ;
V_67 . V_74 = & V_106 ;
F_29 ( V_67 . type ) ;
V_93 = F_30 ( V_23 , & V_67 ) ;
if ( V_93 == NULL ||
V_93 -> V_22 . V_75 == NULL )
goto V_97;
if ( ! F_32 ( V_93 -> V_22 . V_75 -> V_76 ) )
goto V_98;
V_9 -> V_111 = V_104 ;
V_9 -> V_83 = V_93 ;
return V_7 ;
V_98:
F_33 ( V_93 ) ;
V_97:
F_37 ( V_104 -> V_22 . V_75 -> V_76 ) ;
V_110:
F_33 ( V_104 ) ;
V_109:
V_7 = - V_71 ;
return V_7 ;
}
static int F_40 ( struct V_1 * V_2 , const char * * V_112 )
{
F_10 ( V_2 , 0x04 , 1 ) ;
F_7 ( 20 ) ;
F_10 ( V_2 , 0x83 , 0 ) ;
F_10 ( V_2 , 0xc0 , 1 ) ;
F_7 ( 100 ) ;
F_10 ( V_2 , 0x83 , 1 ) ;
F_10 ( V_2 , 0xc0 , 0 ) ;
F_7 ( 50 ) ;
return V_113 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_42 ( & V_9 -> V_16 ) ;
V_9 -> V_63 = 0 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_64 * V_65 ;
V_65 = V_9 -> V_83 ;
if ( V_65 ) {
F_37 ( V_65 -> V_22 . V_75 -> V_76 ) ;
F_33 ( V_65 ) ;
}
V_65 = V_9 -> V_111 ;
if ( V_65 ) {
F_37 ( V_65 -> V_22 . V_75 -> V_76 ) ;
F_33 ( V_65 ) ;
}
V_65 = V_9 -> V_103 ;
if ( V_65 ) {
F_37 ( V_65 -> V_22 . V_75 -> V_76 ) ;
F_33 ( V_65 ) ;
}
}
