static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_11 [ V_5 + 4 ] , V_12 [ 64 ] = { 0 } ;
int V_13 = 0 ;
memset ( V_11 , 0 , V_5 + 4 ) ;
V_11 [ 0 ] = 0xaa ;
V_11 [ 1 ] = ++ V_9 -> V_14 ;
V_11 [ 2 ] = V_3 ;
V_11 [ 3 ] = V_5 ;
memcpy ( & V_11 [ 4 ] , V_4 , V_5 ) ;
V_13 = F_2 ( V_2 , V_11 , V_5 + 4 , V_12 , 64 , 0 ) ;
if ( V_13 != 0 ||
V_12 [ 0 ] != 0x55 ||
V_12 [ 1 ] != V_11 [ 1 ] ||
V_12 [ 2 ] != V_3 ||
( V_7 > 0 && V_12 [ 3 ] != V_7 ) ) {
F_3 ( L_1 , V_7 , V_12 [ 3 ] ) ;
return - V_15 ;
}
if ( V_7 > 0 )
memcpy ( V_6 , & V_12 [ 4 ] , V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_16 , unsigned int V_17 , unsigned int V_18 )
{
int V_13 ;
T_1 V_19 [ 60 ] ;
V_13 = F_1 ( V_2 , V_3 , V_16 , V_17 , V_19 , V_18 ) ;
if ( ! V_13 )
memcpy ( V_16 , V_19 , V_18 ) ;
return V_13 ;
}
static int F_5 ( struct V_20 * V_21 , T_1 V_3 , T_1 * V_16 , unsigned int V_17 , unsigned int V_18 )
{
struct V_1 * V_2 = V_21 -> V_16 ;
struct V_8 * V_22 = V_2 -> V_10 ;
int V_13 ;
F_6 ( & V_22 -> V_23 ) ;
V_13 = F_4 ( V_2 , V_3 , V_16 , V_17 , V_18 ) ;
F_7 ( & V_22 -> V_23 ) ;
return V_13 ;
}
static int F_8 ( struct V_20 * V_21 , int V_24 , int V_25 )
{
T_1 V_26 [ 3 ] ;
int V_13 = 0 ;
if ( V_24 )
return - V_27 ;
V_26 [ 0 ] = ( V_25 >> 8 ) & 0x0F ;
V_26 [ 1 ] = V_25 ;
V_13 = F_5 ( V_21 , V_28 , V_26 , 2 , 3 ) ;
F_9 ( L_2 , V_25 , V_13 , V_26 [ 2 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_26 [ 2 ] ;
}
static int F_10 ( struct V_20 * V_21 , int V_24 , int V_25 , T_1 V_29 )
{
T_1 V_26 [ 3 ] ;
F_9 ( L_3 , V_24 , V_25 , V_29 ) ;
if ( V_24 )
return - V_27 ;
V_26 [ 0 ] = ( V_25 >> 8 ) & 0x0F ;
V_26 [ 1 ] = V_25 ;
V_26 [ 2 ] = V_29 ;
return F_5 ( V_21 , V_30 , V_26 , 3 , 3 ) ;
}
static int F_11 ( struct V_20 * V_21 , int V_24 , T_1 V_25 )
{
T_1 V_26 [ 2 ] ;
int V_13 ;
if ( V_24 )
return - V_27 ;
V_26 [ 0 ] = V_25 & 3 ;
V_13 = F_5 ( V_21 , V_31 , V_26 , 1 , 2 ) ;
F_9 ( L_4 , V_25 , V_13 , V_26 [ 1 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_26 [ 1 ] ;
}
static int F_12 ( struct V_20 * V_21 , int V_24 , T_1 V_25 , T_1 V_29 )
{
T_1 V_26 [ 2 ] ;
F_9 ( L_5 , V_24 , V_25 , V_29 ) ;
if ( V_24 )
return - V_27 ;
V_26 [ 0 ] = V_25 ;
V_26 [ 1 ] = V_29 ;
return F_5 ( V_21 , V_32 , V_26 , 2 , 2 ) ;
}
static int F_13 ( struct V_20 * V_21 , int V_24 , int V_33 )
{
T_1 V_26 [ 1 ] ;
int V_13 ;
F_9 ( L_6 , V_24 , V_33 ) ;
if ( V_24 )
return - V_27 ;
V_26 [ 0 ] = V_33 ;
V_13 = F_5 ( V_21 , V_34 , V_26 , 1 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_33 != V_26 [ 0 ] ) {
F_14 ( L_7 , V_33 ? L_8 : L_9 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , int V_24 )
{
return F_13 ( V_21 , V_24 , 0 ) ;
}
static int F_16 ( struct V_20 * V_21 , int V_24 )
{
return F_13 ( V_21 , V_24 , 1 ) ;
}
static int F_17 ( struct V_20 * V_21 , int V_24 )
{
struct V_1 * V_2 = V_21 -> V_16 ;
struct V_8 * V_22 = V_2 -> V_10 ;
T_1 V_26 [ 1 ] ;
int V_13 ;
F_9 ( L_10 , V_24 ) ;
if ( V_24 )
return - V_27 ;
V_26 [ 0 ] = 0 ;
F_6 ( & V_22 -> V_23 ) ;
V_13 = F_4 ( V_2 , V_35 , V_26 , 1 , 1 ) ;
if ( V_13 )
goto V_36;
F_18 ( 500 ) ;
V_26 [ 0 ] = 1 ;
V_13 = F_4 ( V_2 , V_35 , V_26 , 1 , 1 ) ;
if ( V_13 )
goto V_36;
F_18 ( 500 ) ;
V_26 [ 0 ] = 0 ;
V_13 = F_4 ( V_2 , V_34 , V_26 , 1 , 1 ) ;
F_18 ( 1100 ) ;
V_36:
F_7 ( & V_22 -> V_23 ) ;
return V_13 ;
}
static int F_19 ( struct V_20 * V_21 , int V_24 , int V_37 )
{
T_1 V_26 [ 1 ] ;
int V_13 ;
if ( V_24 )
return - V_27 ;
V_13 = F_5 ( V_21 , V_38 , V_26 , 0 , 1 ) ;
if ( V_13 )
return V_13 ;
if ( 1 == V_26 [ 0 ] ) {
return V_39 |
V_40 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_22 ;
F_9 ( L_11 ) ;
if ( NULL == V_2 )
return;
V_22 = V_2 -> V_10 ;
if ( NULL == V_22 )
return;
if ( NULL == V_22 -> V_21 . V_16 )
return;
F_21 ( & V_22 -> V_21 ) ;
memset ( & V_22 -> V_21 , 0 , sizeof( V_22 -> V_21 ) ) ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_8 * V_22 = V_2 -> V_10 ;
int V_13 ;
F_9 ( L_11 ) ;
F_23 ( & V_22 -> V_23 ) ;
V_22 -> V_21 . V_44 = V_45 ;
V_22 -> V_21 . V_46 = F_8 ;
V_22 -> V_21 . V_47 = F_10 ;
V_22 -> V_21 . V_48 = F_11 ;
V_22 -> V_21 . V_49 = F_12 ;
V_22 -> V_21 . V_50 = F_17 ;
V_22 -> V_21 . V_51 = F_15 ;
V_22 -> V_21 . V_52 = F_16 ;
V_22 -> V_21 . V_53 = F_19 ;
V_22 -> V_21 . V_16 = V_2 ;
V_13 = F_24 ( & V_42 -> V_54 ,
& V_22 -> V_21 ,
0 ,
1 ) ;
if ( V_13 ) {
F_14 ( L_12 , V_13 ) ;
memset ( & V_22 -> V_21 , 0 , sizeof( V_22 -> V_21 ) ) ;
return V_13 ;
}
F_25 ( L_13 ) ;
return 0 ;
}
static int F_26 ( struct V_55 * V_56 , struct V_57 V_58 [] , int V_59 )
{
struct V_1 * V_2 = F_27 ( V_56 ) ;
static T_1 V_60 [ 60 ] , V_61 [ 60 ] ;
int V_62 , V_63 , V_64 ;
if ( F_28 ( & V_2 -> V_65 ) < 0 )
return - V_66 ;
if ( V_59 > 2 )
F_3 ( L_14 ) ;
for ( V_62 = 0 ; V_62 < V_59 ; V_62 ++ ) {
V_63 = V_62 + 1 < V_59 && ( V_58 [ V_62 + 1 ] . V_67 & V_68 ) ;
V_64 = V_58 [ V_62 ] . V_67 & V_68 ;
V_60 [ 0 ] = ( V_58 [ V_62 ] . V_69 << 1 ) | ( V_63 | V_64 ) ;
if ( V_64 )
V_60 [ 1 ] = 0 ;
else
V_60 [ 1 ] = V_58 [ V_62 ] . V_70 ;
if ( V_63 )
V_60 [ 2 ] = V_58 [ V_62 + 1 ] . V_70 ;
else if ( V_64 )
V_60 [ 2 ] = V_58 [ V_62 ] . V_70 ;
else
V_60 [ 2 ] = 0 ;
memcpy ( & V_60 [ 3 ] , V_58 [ V_62 ] . V_26 , V_58 [ V_62 ] . V_70 ) ;
if ( F_1 ( V_2 , V_71 , V_60 , V_58 [ V_62 ] . V_70 + 3 , V_61 , V_60 [ 2 ] + 3 ) < 0 ) {
F_14 ( L_15 ) ;
break;
}
if ( V_63 ) {
memcpy ( V_58 [ V_62 + 1 ] . V_26 , & V_61 [ 3 ] , V_58 [ V_62 + 1 ] . V_70 ) ;
V_62 ++ ;
} else if ( V_64 )
memcpy ( V_58 [ V_62 ] . V_26 , & V_61 [ 3 ] , V_58 [ V_62 ] . V_70 ) ;
}
F_7 ( & V_2 -> V_65 ) ;
return V_62 ;
}
static T_2 F_29 ( struct V_55 * V_72 )
{
return V_73 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_19 [ 9 ] ;
struct V_8 * V_9 = V_2 -> V_10 ;
V_13 = F_1 ( V_2 , V_74 , NULL , 0 , V_19 , sizeof( V_19 ) ) ;
if ( V_13 != 0 )
return V_13 ;
if ( V_19 [ 8 ] & 0x01 ) {
V_9 -> V_75 = ( V_19 [ 3 ] << 8 ) | V_19 [ 2 ] ;
F_31 ( L_16 , V_76 , V_19 [ 2 ] , V_19 [ 3 ] ) ;
F_32 ( V_2 -> V_77 , V_9 -> V_75 , 0 ) ;
} else if ( V_9 -> V_75 ) {
F_33 ( V_2 -> V_77 ) ;
V_9 -> V_75 = 0 ;
}
return 0 ;
}
static int F_34 ( struct V_78 * V_79 , struct
V_80 * V_81 , struct V_82 * * V_83 ,
int * V_84 )
{
* V_84 = V_79 -> V_85 . V_86 == 0 && V_79 -> V_85 . V_87 == 0 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_88 )
{
T_1 V_89 = V_88 ;
F_1 ( V_2 , V_90 , & V_89 , 0 , NULL , 0 ) ;
return F_1 ( V_2 , V_90 , & V_89 , 1 , NULL , 0 ) ;
}
static int F_36 ( struct V_41 * V_56 )
{
if ( F_37 ( V_56 -> V_43 -> V_79 , 0 , 3 ) < 0 )
F_14 ( L_17 ) ;
if ( ( V_56 -> V_91 [ 0 ] . V_92 = F_38 ( V_93 , & V_94 , & V_56 -> V_43 -> V_95 ) ) == NULL ) {
F_31 ( L_18 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_39 ( struct V_97 * V_92 , int V_33 )
{
struct V_41 * V_56 = V_92 -> V_98 -> V_10 ;
return V_56 -> V_91 [ 0 ] . V_92 -> V_99 . V_100 ( V_56 -> V_91 [ 0 ] . V_92 , V_33 ) ;
}
static int F_40 ( struct V_41 * V_56 )
{
if ( F_37 ( V_56 -> V_43 -> V_79 , 0 , 3 ) < 0 )
F_14 ( L_17 ) ;
if ( V_56 -> V_91 [ 0 ] . V_92 == NULL ) {
V_56 -> V_91 [ 0 ] . V_92 = F_38 ( V_101 ,
& V_102 , & V_56 -> V_43 -> V_95 , 0x48 ) ;
if ( V_56 -> V_91 [ 0 ] . V_92 == NULL ) {
F_31 ( L_19 ) ;
return - V_96 ;
}
F_22 ( V_56 ) ;
} else {
V_56 -> V_91 [ 1 ] . V_92 = F_38 ( V_103 ,
& V_104 , & V_56 -> V_43 -> V_95 ) ;
if ( V_56 -> V_91 [ 1 ] . V_92 == NULL ) {
F_31 ( L_20 ) ;
return - V_96 ;
}
V_56 -> V_91 [ 1 ] . V_92 -> V_99 . V_100 = F_39 ;
}
return 0 ;
}
static int F_41 ( struct V_41 * V_56 )
{
struct V_97 * V_92 ;
if ( V_56 -> V_91 [ 1 ] . V_92 == NULL )
V_92 = V_56 -> V_91 [ 0 ] . V_92 ;
else
V_92 = V_56 -> V_91 [ 1 ] . V_92 ;
if ( F_38 ( V_105 , V_92 , 0x61 , & V_56 -> V_43 -> V_95 , & V_106 ) == NULL ) {
F_42 ( V_107 L_21 , V_76 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_43 ( struct V_41 * V_56 )
{
if ( F_38 ( V_108 , V_56 -> V_91 [ 0 ] . V_92 , 0x60 , & V_56 -> V_43 -> V_95 , 0 ) == NULL ) {
F_31 ( L_22 ) ;
return - V_96 ;
}
if ( F_38 ( V_109 , V_56 -> V_91 [ 0 ] . V_92 , & V_56 -> V_43 -> V_95 , 0 , 0 ) == NULL ) {
F_31 ( L_23 ) ;
return - V_96 ;
}
return 0 ;
}
static void F_44 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_45 ( V_111 ) ;
F_20 ( V_2 ) ;
F_46 ( V_111 ) ;
}
static int F_47 ( struct V_110 * V_111 ,
const struct V_112 * V_14 )
{
if ( 0 == F_48 ( V_111 , & V_113 ,
V_45 , NULL , V_114 ) ||
0 == F_48 ( V_111 , & V_115 ,
V_45 , NULL , V_114 ) ||
0 == F_48 ( V_111 , & V_116 ,
V_45 , NULL , V_114 ) )
return 0 ;
return - V_96 ;
}
static int T_3 F_49 ( void )
{
int V_117 ;
if ( ( V_117 = F_50 ( & V_118 ) ) ) {
F_14 ( L_24 , V_117 ) ;
return V_117 ;
}
return 0 ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_118 ) ;
}
