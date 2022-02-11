static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_10 [ 64 ] ;
T_1 V_11 ;
unsigned int V_12 ;
int V_13 ;
F_2 ( NULL == V_4 && 0 != ( V_5 | V_6 ) ) ;
F_2 ( V_5 > 64 - 4 ) ;
F_2 ( V_6 > 64 - 4 ) ;
V_11 = V_8 -> V_14 ++ ;
V_10 [ 0 ] = V_15 ;
V_10 [ 1 ] = V_11 ;
V_10 [ 2 ] = V_3 ;
V_10 [ 3 ] = V_5 ;
memcpy ( V_10 + 4 , V_4 , V_5 ) ;
V_12 = ( V_6 > 0 ) ? 64 : 0 ;
V_13 = F_3 ( V_2 , V_10 , 4 + V_5 ,
V_10 , V_12 , 0 ) ;
if ( 0 != V_13 )
goto V_16;
V_13 = - V_17 ;
if ( V_18 != V_10 [ 0 ] || V_11 != V_10 [ 1 ] )
goto V_16;
memcpy ( V_4 , V_10 + 4 , V_6 ) ;
return 0 ;
V_16:
F_4 ( L_1 ,
V_13 , V_15 , V_11 , V_3 , V_10 [ 0 ] , V_10 [ 1 ] , V_10 [ 2 ] ) ;
return V_13 ;
}
static int F_5 ( struct V_19 * V_20 ,
T_1 V_3 , T_1 * V_4 , unsigned int V_5 ,
unsigned int V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 -> V_4 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
int V_13 ;
F_6 ( & V_8 -> V_21 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_7 ( & V_8 -> V_21 ) ;
return V_13 ;
}
static int F_8 ( struct V_19 * V_20 ,
int V_22 , int V_23 )
{
T_1 V_10 [ 3 ] ;
int V_13 ;
if ( 0 != V_22 )
return - V_24 ;
V_10 [ 0 ] = ( V_23 >> 8 ) & 0x0F ;
V_10 [ 1 ] = V_23 ;
V_13 = F_5 ( V_20 , V_25 , V_10 , 2 , 3 ) ;
F_9 ( L_2 ,
V_26 , V_23 , V_13 , V_10 [ 2 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_10 [ 2 ] ;
}
static int F_10 ( struct V_19 * V_20 ,
int V_22 , int V_23 , T_1 V_27 )
{
T_1 V_10 [ 3 ] ;
F_9 ( L_3 ,
V_26 , V_22 , V_23 , V_27 ) ;
if ( 0 != V_22 )
return - V_24 ;
V_10 [ 0 ] = ( V_23 >> 8 ) & 0x0F ;
V_10 [ 1 ] = V_23 ;
V_10 [ 2 ] = V_27 ;
return F_5 ( V_20 , V_28 , V_10 , 3 , 3 ) ;
}
static int F_11 ( struct V_19 * V_20 ,
int V_22 ,
T_1 V_23 )
{
T_1 V_10 [ 2 ] ;
int V_13 ;
if ( 0 != V_22 )
return - V_24 ;
V_10 [ 0 ] = V_23 & 3 ;
V_13 = F_5 ( V_20 , V_29 , V_10 , 1 , 2 ) ;
F_9 ( L_4 ,
V_26 , V_23 , V_13 , V_10 [ 1 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_10 [ 1 ] ;
}
static int F_12 ( struct V_19 * V_20 ,
int V_22 ,
T_1 V_23 ,
T_1 V_27 )
{
T_1 V_10 [ 2 ] ;
F_9 ( L_5 ,
V_26 , V_22 , V_23 , V_27 ) ;
if ( 0 != V_22 )
return - V_24 ;
V_10 [ 0 ] = V_23 ;
V_10 [ 1 ] = V_27 ;
return F_5 ( V_20 , V_30 , V_10 , 2 , 2 ) ;
}
static int F_13 ( struct V_19 * V_20 ,
int V_22 ,
int V_31 )
{
T_1 V_10 [ 1 ] ;
int V_13 ;
F_9 ( L_6 , V_26 , V_22 , V_31 ) ;
if ( 0 != V_22 )
return - V_24 ;
V_31 = ! ! V_31 ;
V_10 [ 0 ] = V_31 ;
V_13 = F_5 ( V_20 , V_32 , V_10 , 1 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_31 != V_10 [ 0 ] ) {
F_4 ( L_7 , V_31 ? L_8 : L_9 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_14 ( struct V_19 * V_20 , int V_22 )
{
return F_13 ( V_20 , V_22 , 0 ) ;
}
static int F_15 ( struct V_19 * V_20 , int V_22 )
{
return F_13 ( V_20 , V_22 , 1 ) ;
}
static int F_16 ( struct V_19 * V_20 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 -> V_4 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_10 [ 1 ] ;
int V_13 ;
F_9 ( L_10 , V_26 , V_22 ) ;
if ( 0 != V_22 )
return - V_24 ;
V_10 [ 0 ] = 0 ;
F_6 ( & V_8 -> V_21 ) ;
V_13 = F_1 ( V_2 , V_33 , V_10 , 1 , 1 ) ;
if ( 0 != V_13 )
goto V_16;
F_17 ( 500 ) ;
V_10 [ 0 ] = 1 ;
V_13 = F_1 ( V_2 , V_33 , V_10 , 1 , 1 ) ;
if ( 0 != V_13 )
goto V_16;
F_17 ( 500 ) ;
V_10 [ 0 ] = 0 ;
V_13 = F_1 ( V_2 , V_32 , V_10 , 1 , 1 ) ;
V_16:
F_7 ( & V_8 -> V_21 ) ;
return V_13 ;
}
static int F_18 ( struct V_19 * V_20 ,
int V_22 ,
int V_34 )
{
T_1 V_10 [ 1 ] ;
int V_13 ;
if ( 0 != V_22 )
return - V_24 ;
V_13 = F_5 ( V_20 , V_35 , V_10 , 0 , 1 ) ;
if ( 0 != V_13 )
return V_13 ;
if ( 1 == V_10 [ 0 ] )
return V_36 |
V_37 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_9 ( L_11 , V_26 ) ;
if ( NULL == V_2 )
return;
V_8 = (struct V_7 * ) V_2 -> V_9 ;
if ( NULL == V_8 )
return;
if ( NULL == V_8 -> V_20 . V_4 )
return;
F_13 ( & V_8 -> V_20 , 0 , 0 ) ;
F_20 ( & V_8 -> V_20 ) ;
memset ( & V_8 -> V_20 , 0 , sizeof( V_8 -> V_20 ) ) ;
}
static int F_21 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
int V_13 ;
F_9 ( L_11 , V_26 ) ;
F_22 ( & V_8 -> V_21 ) ;
V_8 -> V_20 . V_41 = V_42 ;
V_8 -> V_20 . V_43 = F_8 ;
V_8 -> V_20 . V_44 = F_10 ;
V_8 -> V_20 . V_45 = F_11 ;
V_8 -> V_20 . V_46 = F_12 ;
V_8 -> V_20 . V_47 = F_16 ;
V_8 -> V_20 . V_48 = F_14 ;
V_8 -> V_20 . V_49 = F_15 ;
V_8 -> V_20 . V_50 = F_18 ;
V_8 -> V_20 . V_4 = V_2 ;
V_13 = F_23 ( & V_39 -> V_51 ,
& V_8 -> V_20 ,
0 ,
1 ) ;
if ( 0 != V_13 ) {
F_4 ( L_12 , V_13 ) ;
memset ( & V_8 -> V_20 , 0 , sizeof( V_8 -> V_20 ) ) ;
return V_13 ;
}
F_24 ( L_13 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_52 ,
const T_1 * V_53 , T_1 V_54 ,
T_1 * V_55 , T_1 V_56 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_10 [ 64 ] ;
T_1 V_11 ;
int V_13 ;
V_11 = V_8 -> V_14 ++ ;
V_13 = - V_24 ;
if ( V_54 > 64 - 7 || V_56 > 64 - 7 )
goto V_16;
V_10 [ 0 ] = V_15 ;
V_10 [ 1 ] = V_11 ;
V_10 [ 2 ] = V_57 ;
V_10 [ 3 ] = V_54 + 3 ;
V_10 [ 4 ] = V_52 << 1 ;
V_10 [ 5 ] = V_54 ;
V_10 [ 6 ] = V_56 ;
memcpy ( V_10 + 7 , V_53 , V_54 ) ;
V_13 = F_3 ( V_2 , V_10 , 7 + V_54 ,
V_10 , 64 ,
0 ) ;
if ( V_13 < 0 )
goto V_16;
V_13 = - V_17 ;
if ( V_18 != V_10 [ 0 ] || V_11 != V_10 [ 1 ] )
goto V_16;
V_13 = - V_58 ;
if ( V_10 [ 5 ] < V_54 || V_10 [ 6 ] < V_56 )
goto V_16;
memcpy ( V_55 , V_10 + 7 , V_56 ) ;
return V_56 ;
V_16:
F_4 ( L_14
L_15 ,
V_13 , V_15 , V_11 , V_52 << 1 , V_54 , V_56 ,
V_10 [ 0 ] , V_10 [ 1 ] , V_10 [ 4 ] , V_10 [ 5 ] , V_10 [ 6 ] ) ;
return V_13 ;
}
static int F_26 ( struct V_59 * V_60 , struct V_61 * V_62 ,
int V_63 )
{
struct V_1 * V_2 = F_27 ( V_60 ) ;
int V_64 ;
if ( F_28 ( & V_2 -> V_65 ) < 0 )
return - V_66 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
T_1 V_52 , V_54 , V_56 , * V_53 , * V_55 ;
int V_13 ;
if ( V_62 [ V_64 ] . V_67 & V_68 ) {
V_52 = V_62 [ V_64 ] . V_52 ;
V_53 = NULL ;
V_54 = 0 ;
V_55 = V_62 [ V_64 ] . V_10 ;
V_56 = V_62 [ V_64 ] . V_69 ;
} else {
V_52 = V_62 [ V_64 ] . V_52 ;
V_53 = V_62 [ V_64 ] . V_10 ;
V_54 = V_62 [ V_64 ] . V_69 ;
V_55 = NULL ;
V_56 = 0 ;
}
V_13 = F_25 ( V_2 , V_52 , V_53 , V_54 , V_55 ,
V_56 ) ;
if ( V_13 < V_56 )
break;
}
F_7 ( & V_2 -> V_65 ) ;
return V_64 ;
}
static T_2 F_29 ( struct V_59 * V_60 )
{
return V_70 ;
}
static int F_30 ( struct V_1 * V_2 , int V_64 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_71 [] = { 0xaa , 0 , V_72 , 1 , 0 } ;
T_1 V_73 [ V_74 ] ;
int V_13 ;
F_24 ( L_16 , V_26 , V_64 ) ;
if ( ! V_64 )
return 0 ;
if ( V_8 -> V_75 )
return 0 ;
V_13 = F_31 ( V_2 -> V_76 , 0 , V_77 ) ;
if ( V_13 != 0 )
F_24 ( L_17 ,
V_26 , V_13 ) ;
V_71 [ 1 ] = V_8 -> V_14 ++ ;
V_13 = F_3 ( V_2 , V_71 , sizeof( V_71 ) , V_73 , V_74 , 0 ) ;
if ( V_13 )
return V_13 ;
V_71 [ 1 ] = V_8 -> V_14 ++ ;
V_71 [ 4 ] = 1 ;
V_13 = F_3 ( V_2 , V_71 , sizeof( V_71 ) , V_73 , V_74 , 0 ) ;
if ( V_13 )
return V_13 ;
V_8 -> V_75 = 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_78 [ V_79 ] ;
T_1 V_73 [ V_74 ] ;
int V_13 , V_64 ;
T_1 V_11 = V_8 -> V_14 ++ ;
V_78 [ 0 ] = V_15 ;
V_78 [ 1 ] = V_11 ;
V_78 [ 2 ] = V_80 ;
V_78 [ 3 ] = 0 ;
V_13 = F_3 ( V_2 , V_78 , 4 , V_73 , V_74 , 0 ) ;
if ( V_13 != 0 )
return V_13 ;
if ( V_81 > 3 ) {
F_24 ( L_18 , V_26 ,
V_13 , V_73 [ 0 ] , V_73 [ 1 ] , V_73 [ 2 ] ) ;
for ( V_64 = 0 ; ( V_64 < V_73 [ 3 ] ) && ( ( V_64 + 3 ) < V_74 ) ; V_64 ++ )
F_24 ( L_19 , V_73 [ V_64 + 3 ] ) ;
F_24 ( L_20 ) ;
}
if ( ( V_73 [ 3 ] == 9 ) && ( V_73 [ 12 ] & 0x01 ) ) {
V_8 -> V_82 = ( V_73 [ 7 ] << 8 ) | V_73 [ 6 ] ;
if ( V_81 > 2 )
F_24 ( L_21 ,
V_26 , V_73 [ 6 ] , V_73 [ 7 ] ) ;
F_33 ( V_2 -> V_83 , V_8 -> V_82 , 0 ) ;
} else if ( V_8 -> V_82 ) {
F_34 ( V_2 -> V_83 ) ;
V_8 -> V_82 = 0 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_84 [ 6 ] )
{
const T_1 V_85 [] = { 0x1f , 0xcc } ;
T_1 V_86 [ 20 ] ;
int V_13 ;
V_13 = - V_66 ;
if ( F_28 ( & V_2 -> V_65 ) < 0 )
goto V_16;
V_13 = F_25 ( V_2 , V_87 ,
V_85 + 1 , 1 ,
V_86 , 20 ) ;
if ( - V_58 == V_13 )
V_13 = F_25 ( V_2 , V_88 ,
V_85 , 2 ,
V_86 , 20 ) ;
F_7 ( & V_2 -> V_65 ) ;
if ( 20 != V_13 )
goto V_16;
V_13 = F_36 ( V_84 , V_86 ) ;
if ( 0 != V_13 )
goto V_16;
return 0 ;
V_16:
memset ( V_84 , 0 , 6 ) ;
return V_13 ;
}
static int F_37 ( struct V_38 * V_39 )
{
struct V_89 * V_11 ;
V_39 -> V_90 [ 0 ] . V_91 = F_38 ( V_92 , & V_93 ,
& V_39 -> V_40 -> V_94 ) ;
if ( ! V_39 -> V_90 [ 0 ] . V_91 )
return - V_95 ;
if ( ( F_38 ( V_96 , V_39 -> V_90 [ 0 ] . V_91 ,
& V_39 -> V_40 -> V_94 ) ) == 0 )
F_4 ( L_22 ) ;
V_11 = V_39 -> V_40 -> V_97 -> V_98 [ 0 ] ;
if ( V_99 == V_11 -> V_100
&& V_101 == V_11 -> V_102 )
F_21 ( V_39 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_39 )
{
if ( ! V_39 -> V_90 [ 0 ] . V_91 )
return - V_95 ;
if ( F_38 ( V_103 , V_39 -> V_90 [ 0 ] . V_91 , & V_104 ,
& V_39 -> V_40 -> V_94 ) == 0 ) {
F_4 ( L_23 , V_26 ) ;
return - V_95 ;
}
return 0 ;
}
static void F_40 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = F_41 ( V_106 ) ;
F_19 ( V_2 ) ;
F_42 ( V_106 ) ;
}
static int F_43 ( struct V_105 * V_106 ,
const struct V_89 * V_11 )
{
if ( 0 == F_44 ( V_106 , & V_107 ,
V_42 , NULL , V_108 ) ||
0 == F_44 ( V_106 , & V_109 ,
V_42 , NULL , V_108 ) )
return 0 ;
return - V_95 ;
}
