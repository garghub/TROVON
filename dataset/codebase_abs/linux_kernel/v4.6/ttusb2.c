static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 * V_11 , * V_12 = NULL ;
int V_13 = 0 ;
V_11 = F_2 ( V_5 + 4 , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_12 = F_2 ( 64 , V_14 ) ;
if ( ! V_12 ) {
F_3 ( V_11 ) ;
return - V_15 ;
}
V_11 [ 0 ] = 0xaa ;
V_11 [ 1 ] = ++ V_9 -> V_16 ;
V_11 [ 2 ] = V_3 ;
V_11 [ 3 ] = V_5 ;
memcpy ( & V_11 [ 4 ] , V_4 , V_5 ) ;
V_13 = F_4 ( V_2 , V_11 , V_5 + 4 , V_12 , 64 , 0 ) ;
if ( V_13 != 0 ||
V_12 [ 0 ] != 0x55 ||
V_12 [ 1 ] != V_11 [ 1 ] ||
V_12 [ 2 ] != V_3 ||
( V_7 > 0 && V_12 [ 3 ] != V_7 ) ) {
F_5 ( L_1 , V_7 , V_12 [ 3 ] ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
return - V_17 ;
}
if ( V_7 > 0 )
memcpy ( V_6 , & V_12 [ 4 ] , V_7 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_18 , unsigned int V_19 , unsigned int V_20 )
{
int V_13 ;
T_1 V_21 [ 60 ] ;
V_13 = F_1 ( V_2 , V_3 , V_18 , V_19 , V_21 , V_20 ) ;
if ( ! V_13 )
memcpy ( V_18 , V_21 , V_20 ) ;
return V_13 ;
}
static int F_7 ( struct V_22 * V_23 , T_1 V_3 , T_1 * V_18 , unsigned int V_19 , unsigned int V_20 )
{
struct V_1 * V_2 = V_23 -> V_18 ;
struct V_8 * V_24 = V_2 -> V_10 ;
int V_13 ;
F_8 ( & V_24 -> V_25 ) ;
V_13 = F_6 ( V_2 , V_3 , V_18 , V_19 , V_20 ) ;
F_9 ( & V_24 -> V_25 ) ;
return V_13 ;
}
static int F_10 ( struct V_22 * V_23 , int V_26 , int V_27 )
{
T_1 V_28 [ 3 ] ;
int V_13 = 0 ;
if ( V_26 )
return - V_29 ;
V_28 [ 0 ] = ( V_27 >> 8 ) & 0x0F ;
V_28 [ 1 ] = V_27 ;
V_13 = F_7 ( V_23 , V_30 , V_28 , 2 , 3 ) ;
F_11 ( L_2 , V_27 , V_13 , V_28 [ 2 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_28 [ 2 ] ;
}
static int F_12 ( struct V_22 * V_23 , int V_26 , int V_27 , T_1 V_31 )
{
T_1 V_28 [ 3 ] ;
F_11 ( L_3 , V_26 , V_27 , V_31 ) ;
if ( V_26 )
return - V_29 ;
V_28 [ 0 ] = ( V_27 >> 8 ) & 0x0F ;
V_28 [ 1 ] = V_27 ;
V_28 [ 2 ] = V_31 ;
return F_7 ( V_23 , V_32 , V_28 , 3 , 3 ) ;
}
static int F_13 ( struct V_22 * V_23 , int V_26 , T_1 V_27 )
{
T_1 V_28 [ 2 ] ;
int V_13 ;
if ( V_26 )
return - V_29 ;
V_28 [ 0 ] = V_27 & 3 ;
V_13 = F_7 ( V_23 , V_33 , V_28 , 1 , 2 ) ;
F_11 ( L_4 , V_27 , V_13 , V_28 [ 1 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_28 [ 1 ] ;
}
static int F_14 ( struct V_22 * V_23 , int V_26 , T_1 V_27 , T_1 V_31 )
{
T_1 V_28 [ 2 ] ;
F_11 ( L_5 , V_26 , V_27 , V_31 ) ;
if ( V_26 )
return - V_29 ;
V_28 [ 0 ] = V_27 ;
V_28 [ 1 ] = V_31 ;
return F_7 ( V_23 , V_34 , V_28 , 2 , 2 ) ;
}
static int F_15 ( struct V_22 * V_23 , int V_26 , int V_35 )
{
T_1 V_28 [ 1 ] ;
int V_13 ;
F_11 ( L_6 , V_26 , V_35 ) ;
if ( V_26 )
return - V_29 ;
V_28 [ 0 ] = V_35 ;
V_13 = F_7 ( V_23 , V_36 , V_28 , 1 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_35 != V_28 [ 0 ] ) {
F_16 ( L_7 , V_35 ? L_8 : L_9 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_17 ( struct V_22 * V_23 , int V_26 )
{
return F_15 ( V_23 , V_26 , 0 ) ;
}
static int F_18 ( struct V_22 * V_23 , int V_26 )
{
return F_15 ( V_23 , V_26 , 1 ) ;
}
static int F_19 ( struct V_22 * V_23 , int V_26 )
{
struct V_1 * V_2 = V_23 -> V_18 ;
struct V_8 * V_24 = V_2 -> V_10 ;
T_1 V_28 [ 1 ] ;
int V_13 ;
F_11 ( L_10 , V_26 ) ;
if ( V_26 )
return - V_29 ;
V_28 [ 0 ] = 0 ;
F_8 ( & V_24 -> V_25 ) ;
V_13 = F_6 ( V_2 , V_37 , V_28 , 1 , 1 ) ;
if ( V_13 )
goto V_38;
F_20 ( 500 ) ;
V_28 [ 0 ] = 1 ;
V_13 = F_6 ( V_2 , V_37 , V_28 , 1 , 1 ) ;
if ( V_13 )
goto V_38;
F_20 ( 500 ) ;
V_28 [ 0 ] = 0 ;
V_13 = F_6 ( V_2 , V_36 , V_28 , 1 , 1 ) ;
F_20 ( 1100 ) ;
V_38:
F_9 ( & V_24 -> V_25 ) ;
return V_13 ;
}
static int F_21 ( struct V_22 * V_23 , int V_26 , int V_39 )
{
T_1 V_28 [ 1 ] ;
int V_13 ;
if ( V_26 )
return - V_29 ;
V_13 = F_7 ( V_23 , V_40 , V_28 , 0 , 1 ) ;
if ( V_13 )
return V_13 ;
if ( 1 == V_28 [ 0 ] ) {
return V_41 |
V_42 ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_24 ;
F_11 ( L_11 ) ;
if ( NULL == V_2 )
return;
V_24 = V_2 -> V_10 ;
if ( NULL == V_24 )
return;
if ( NULL == V_24 -> V_23 . V_18 )
return;
F_23 ( & V_24 -> V_23 ) ;
memset ( & V_24 -> V_23 , 0 , sizeof( V_24 -> V_23 ) ) ;
}
static int F_24 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_8 * V_24 = V_2 -> V_10 ;
int V_13 ;
F_11 ( L_11 ) ;
F_25 ( & V_24 -> V_25 ) ;
V_24 -> V_23 . V_46 = V_47 ;
V_24 -> V_23 . V_48 = F_10 ;
V_24 -> V_23 . V_49 = F_12 ;
V_24 -> V_23 . V_50 = F_13 ;
V_24 -> V_23 . V_51 = F_14 ;
V_24 -> V_23 . V_52 = F_19 ;
V_24 -> V_23 . V_53 = F_17 ;
V_24 -> V_23 . V_54 = F_18 ;
V_24 -> V_23 . V_55 = F_21 ;
V_24 -> V_23 . V_18 = V_2 ;
V_13 = F_26 ( & V_44 -> V_56 ,
& V_24 -> V_23 ,
0 ,
1 ) ;
if ( V_13 ) {
F_16 ( L_12 , V_13 ) ;
memset ( & V_24 -> V_23 , 0 , sizeof( V_24 -> V_23 ) ) ;
return V_13 ;
}
F_27 ( L_13 ) ;
return 0 ;
}
static int F_28 ( struct V_57 * V_58 , struct V_59 V_60 [] , int V_61 )
{
struct V_1 * V_2 = F_29 ( V_58 ) ;
static T_1 V_62 [ 60 ] , V_63 [ 60 ] ;
int V_64 , V_65 , V_66 ;
if ( F_30 ( & V_2 -> V_67 ) < 0 )
return - V_68 ;
if ( V_61 > 2 )
F_5 ( L_14 ) ;
for ( V_64 = 0 ; V_64 < V_61 ; V_64 ++ ) {
V_65 = V_64 + 1 < V_61 && ( V_60 [ V_64 + 1 ] . V_69 & V_70 ) ;
V_66 = V_60 [ V_64 ] . V_69 & V_70 ;
V_62 [ 0 ] = ( V_60 [ V_64 ] . V_71 << 1 ) | ( V_65 | V_66 ) ;
if ( V_66 )
V_62 [ 1 ] = 0 ;
else
V_62 [ 1 ] = V_60 [ V_64 ] . V_72 ;
if ( V_65 )
V_62 [ 2 ] = V_60 [ V_64 + 1 ] . V_72 ;
else if ( V_66 )
V_62 [ 2 ] = V_60 [ V_64 ] . V_72 ;
else
V_62 [ 2 ] = 0 ;
memcpy ( & V_62 [ 3 ] , V_60 [ V_64 ] . V_28 , V_60 [ V_64 ] . V_72 ) ;
if ( F_1 ( V_2 , V_73 , V_62 , V_62 [ 1 ] + 3 , V_63 , V_62 [ 2 ] + 3 ) < 0 ) {
F_16 ( L_15 ) ;
break;
}
if ( V_65 ) {
memcpy ( V_60 [ V_64 + 1 ] . V_28 , & V_63 [ 3 ] , V_60 [ V_64 + 1 ] . V_72 ) ;
V_64 ++ ;
} else if ( V_66 )
memcpy ( V_60 [ V_64 ] . V_28 , & V_63 [ 3 ] , V_60 [ V_64 ] . V_72 ) ;
}
F_9 ( & V_2 -> V_67 ) ;
return V_64 ;
}
static T_2 F_31 ( struct V_57 * V_74 )
{
return V_75 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_21 [ 9 ] ;
struct V_8 * V_9 = V_2 -> V_10 ;
V_13 = F_1 ( V_2 , V_76 , NULL , 0 , V_21 , sizeof( V_21 ) ) ;
if ( V_13 != 0 )
return V_13 ;
if ( V_21 [ 8 ] & 0x01 ) {
V_9 -> V_77 = F_33 ( V_21 [ 3 ] , V_21 [ 2 ] ) ;
F_34 ( L_16 , V_78 , V_21 [ 2 ] , V_21 [ 3 ] ) ;
F_35 ( V_2 -> V_79 , V_80 , V_9 -> V_77 , V_21 [ 1 ] ) ;
} else if ( V_9 -> V_77 ) {
F_36 ( V_2 -> V_79 ) ;
V_9 -> V_77 = 0 ;
}
return 0 ;
}
static int F_37 ( struct V_81 * V_82 , struct
V_83 * V_84 , struct V_85 * * V_86 ,
int * V_87 )
{
* V_87 = V_82 -> V_88 . V_89 == 0 && V_82 -> V_88 . V_90 == 0 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_91 )
{
T_1 V_92 = V_91 ;
F_1 ( V_2 , V_93 , & V_92 , 0 , NULL , 0 ) ;
return F_1 ( V_2 , V_93 , & V_92 , 1 , NULL , 0 ) ;
}
static int F_39 ( struct V_43 * V_58 )
{
if ( F_40 ( V_58 -> V_45 -> V_82 , 0 , 3 ) < 0 )
F_16 ( L_17 ) ;
if ( ( V_58 -> V_94 [ 0 ] . V_95 = F_41 ( V_96 , & V_97 , & V_58 -> V_45 -> V_98 ) ) == NULL ) {
F_34 ( L_18 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_42 ( struct V_100 * V_95 , int V_35 )
{
struct V_43 * V_58 = V_95 -> V_101 -> V_10 ;
return V_58 -> V_94 [ 0 ] . V_95 -> V_102 . V_103 ( V_58 -> V_94 [ 0 ] . V_95 , V_35 ) ;
}
static int F_43 ( struct V_43 * V_58 )
{
if ( F_40 ( V_58 -> V_45 -> V_82 , 0 , 3 ) < 0 )
F_16 ( L_17 ) ;
if ( V_58 -> V_94 [ 0 ] . V_95 == NULL ) {
V_58 -> V_94 [ 0 ] . V_95 = F_41 ( V_104 ,
& V_105 , & V_58 -> V_45 -> V_98 , 0x48 ) ;
if ( V_58 -> V_94 [ 0 ] . V_95 == NULL ) {
F_34 ( L_19 ) ;
return - V_99 ;
}
F_24 ( V_58 ) ;
} else {
V_58 -> V_94 [ 1 ] . V_95 = F_41 ( V_106 ,
& V_107 , & V_58 -> V_45 -> V_98 ) ;
if ( V_58 -> V_94 [ 1 ] . V_95 == NULL ) {
F_34 ( L_20 ) ;
return - V_99 ;
}
V_58 -> V_94 [ 1 ] . V_95 -> V_102 . V_103 = F_42 ;
}
return 0 ;
}
static int F_44 ( struct V_43 * V_58 )
{
struct V_100 * V_95 ;
if ( V_58 -> V_94 [ 1 ] . V_95 == NULL )
V_95 = V_58 -> V_94 [ 0 ] . V_95 ;
else
V_95 = V_58 -> V_94 [ 1 ] . V_95 ;
if ( F_41 ( V_108 , V_95 , 0x61 , & V_58 -> V_45 -> V_98 , & V_109 ) == NULL ) {
F_45 ( V_110 L_21 , V_78 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_46 ( struct V_43 * V_58 )
{
if ( F_41 ( V_111 , V_58 -> V_94 [ 0 ] . V_95 , 0x60 , & V_58 -> V_45 -> V_98 , 0 ) == NULL ) {
F_34 ( L_22 ) ;
return - V_99 ;
}
if ( F_41 ( V_112 , V_58 -> V_94 [ 0 ] . V_95 , & V_58 -> V_45 -> V_98 , 0 , 0 ) == NULL ) {
F_34 ( L_23 ) ;
return - V_99 ;
}
return 0 ;
}
static void F_47 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = F_48 ( V_114 ) ;
F_22 ( V_2 ) ;
F_49 ( V_114 ) ;
}
static int F_50 ( struct V_113 * V_114 ,
const struct V_115 * V_16 )
{
if ( 0 == F_51 ( V_114 , & V_116 ,
V_47 , NULL , V_117 ) ||
0 == F_51 ( V_114 , & V_118 ,
V_47 , NULL , V_117 ) ||
0 == F_51 ( V_114 , & V_119 ,
V_47 , NULL , V_117 ) )
return 0 ;
return - V_99 ;
}
