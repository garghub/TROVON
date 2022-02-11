static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 * V_10 ;
T_1 V_11 ;
unsigned int V_12 ;
int V_13 ;
if ( ! V_4 || ( V_5 > 64 - 4 ) || ( V_6 > 64 - 4 ) ) {
F_2 ( L_1 , V_14 ) ;
return - V_15 ;
}
V_10 = F_3 ( 64 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_11 = V_8 -> V_18 ++ ;
V_10 [ 0 ] = V_19 ;
V_10 [ 1 ] = V_11 ;
V_10 [ 2 ] = V_3 ;
V_10 [ 3 ] = V_5 ;
memcpy ( V_10 + 4 , V_4 , V_5 ) ;
V_12 = ( V_6 > 0 ) ? 64 : 0 ;
V_13 = F_4 ( V_2 , V_10 , 4 + V_5 ,
V_10 , V_12 , 0 ) ;
if ( 0 != V_13 )
goto V_20;
V_13 = - V_15 ;
if ( V_21 != V_10 [ 0 ] || V_11 != V_10 [ 1 ] )
goto V_20;
memcpy ( V_4 , V_10 + 4 , V_6 ) ;
F_5 ( V_10 ) ;
return 0 ;
V_20:
F_2 ( L_2 ,
V_13 , V_19 , V_11 , V_3 , 3 , V_10 ) ;
F_5 ( V_10 ) ;
return V_13 ;
}
static int F_6 ( struct V_22 * V_23 ,
T_1 V_3 , T_1 * V_4 , unsigned int V_5 ,
unsigned int V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_23 -> V_4 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
int V_13 ;
F_7 ( & V_8 -> V_24 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_8 ( & V_8 -> V_24 ) ;
return V_13 ;
}
static int F_9 ( struct V_22 * V_23 ,
int V_25 , int V_26 )
{
T_1 V_10 [ 3 ] ;
int V_13 ;
if ( 0 != V_25 )
return - V_27 ;
V_10 [ 0 ] = ( V_26 >> 8 ) & 0x0F ;
V_10 [ 1 ] = V_26 ;
V_13 = F_6 ( V_23 , V_28 , V_10 , 2 , 3 ) ;
F_10 ( L_3 ,
V_14 , V_26 , V_13 , V_10 [ 2 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_10 [ 2 ] ;
}
static int F_11 ( struct V_22 * V_23 ,
int V_25 , int V_26 , T_1 V_29 )
{
T_1 V_10 [ 3 ] ;
F_10 ( L_4 ,
V_14 , V_25 , V_26 , V_29 ) ;
if ( 0 != V_25 )
return - V_27 ;
V_10 [ 0 ] = ( V_26 >> 8 ) & 0x0F ;
V_10 [ 1 ] = V_26 ;
V_10 [ 2 ] = V_29 ;
return F_6 ( V_23 , V_30 , V_10 , 3 , 3 ) ;
}
static int F_12 ( struct V_22 * V_23 ,
int V_25 ,
T_1 V_26 )
{
T_1 V_10 [ 2 ] ;
int V_13 ;
if ( 0 != V_25 )
return - V_27 ;
V_10 [ 0 ] = V_26 & 3 ;
V_13 = F_6 ( V_23 , V_31 , V_10 , 1 , 2 ) ;
F_10 ( L_5 ,
V_14 , V_26 , V_13 , V_10 [ 1 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return V_10 [ 1 ] ;
}
static int F_13 ( struct V_22 * V_23 ,
int V_25 ,
T_1 V_26 ,
T_1 V_29 )
{
T_1 V_10 [ 2 ] ;
F_10 ( L_6 ,
V_14 , V_25 , V_26 , V_29 ) ;
if ( 0 != V_25 )
return - V_27 ;
V_10 [ 0 ] = V_26 ;
V_10 [ 1 ] = V_29 ;
return F_6 ( V_23 , V_32 , V_10 , 2 , 2 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
int V_25 ,
int V_33 )
{
T_1 V_10 [ 1 ] ;
int V_13 ;
F_10 ( L_7 , V_14 , V_25 , V_33 ) ;
if ( 0 != V_25 )
return - V_27 ;
V_33 = ! ! V_33 ;
V_10 [ 0 ] = V_33 ;
V_13 = F_6 ( V_23 , V_34 , V_10 , 1 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_33 != V_10 [ 0 ] ) {
F_2 ( L_8 , V_33 ? L_9 : L_10 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_15 ( struct V_22 * V_23 , int V_25 )
{
return F_14 ( V_23 , V_25 , 0 ) ;
}
static int F_16 ( struct V_22 * V_23 , int V_25 )
{
return F_14 ( V_23 , V_25 , 1 ) ;
}
static int F_17 ( struct V_22 * V_23 , int V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_23 -> V_4 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_10 [ 1 ] ;
int V_13 ;
F_10 ( L_11 , V_14 , V_25 ) ;
if ( 0 != V_25 )
return - V_27 ;
V_10 [ 0 ] = 0 ;
F_7 ( & V_8 -> V_24 ) ;
V_13 = F_1 ( V_2 , V_35 , V_10 , 1 , 1 ) ;
if ( 0 != V_13 )
goto V_20;
F_18 ( 500 ) ;
V_10 [ 0 ] = 1 ;
V_13 = F_1 ( V_2 , V_35 , V_10 , 1 , 1 ) ;
if ( 0 != V_13 )
goto V_20;
F_18 ( 500 ) ;
V_10 [ 0 ] = 0 ;
V_13 = F_1 ( V_2 , V_34 , V_10 , 1 , 1 ) ;
V_20:
F_8 ( & V_8 -> V_24 ) ;
return V_13 ;
}
static int F_19 ( struct V_22 * V_23 ,
int V_25 ,
int V_36 )
{
T_1 V_10 [ 1 ] ;
int V_13 ;
if ( 0 != V_25 )
return - V_27 ;
V_13 = F_6 ( V_23 , V_37 , V_10 , 0 , 1 ) ;
if ( 0 != V_13 )
return V_13 ;
if ( 1 == V_10 [ 0 ] )
return V_38 |
V_39 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_10 ( L_12 , V_14 ) ;
if ( NULL == V_2 )
return;
V_8 = (struct V_7 * ) V_2 -> V_9 ;
if ( NULL == V_8 )
return;
if ( NULL == V_8 -> V_23 . V_4 )
return;
F_14 ( & V_8 -> V_23 , 0 , 0 ) ;
F_21 ( & V_8 -> V_23 ) ;
memset ( & V_8 -> V_23 , 0 , sizeof( V_8 -> V_23 ) ) ;
}
static int F_22 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
int V_13 ;
F_10 ( L_12 , V_14 ) ;
F_23 ( & V_8 -> V_24 ) ;
V_8 -> V_23 . V_43 = V_44 ;
V_8 -> V_23 . V_45 = F_9 ;
V_8 -> V_23 . V_46 = F_11 ;
V_8 -> V_23 . V_47 = F_12 ;
V_8 -> V_23 . V_48 = F_13 ;
V_8 -> V_23 . V_49 = F_17 ;
V_8 -> V_23 . V_50 = F_15 ;
V_8 -> V_23 . V_51 = F_16 ;
V_8 -> V_23 . V_52 = F_19 ;
V_8 -> V_23 . V_4 = V_2 ;
V_13 = F_24 ( & V_41 -> V_53 ,
& V_8 -> V_23 ,
0 ,
1 ) ;
if ( 0 != V_13 ) {
F_2 ( L_13 , V_13 ) ;
memset ( & V_8 -> V_23 , 0 , sizeof( V_8 -> V_23 ) ) ;
return V_13 ;
}
F_25 ( L_14 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_54 ,
const T_1 * V_55 , T_1 V_56 ,
T_1 * V_57 , T_1 V_58 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 * V_10 ;
T_1 V_11 ;
int V_13 ;
V_10 = F_3 ( 64 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_11 = V_8 -> V_18 ++ ;
V_13 = - V_27 ;
if ( V_56 > 64 - 7 || V_58 > 64 - 7 )
goto V_20;
V_10 [ 0 ] = V_19 ;
V_10 [ 1 ] = V_11 ;
V_10 [ 2 ] = V_59 ;
V_10 [ 3 ] = V_56 + 3 ;
V_10 [ 4 ] = V_54 << 1 ;
V_10 [ 5 ] = V_56 ;
V_10 [ 6 ] = V_58 ;
memcpy ( V_10 + 7 , V_55 , V_56 ) ;
V_13 = F_4 ( V_2 , V_10 , 7 + V_56 ,
V_10 , 64 ,
0 ) ;
if ( V_13 < 0 )
goto V_20;
V_13 = - V_15 ;
if ( V_21 != V_10 [ 0 ] || V_11 != V_10 [ 1 ] )
goto V_20;
V_13 = - V_60 ;
if ( V_10 [ 5 ] < V_56 || V_10 [ 6 ] < V_58 )
goto V_20;
memcpy ( V_57 , V_10 + 7 , V_58 ) ;
F_5 ( V_10 ) ;
return V_58 ;
V_20:
F_2 ( L_15 ,
V_13 , V_19 , V_11 , V_54 << 1 , V_56 , V_58 ,
7 , V_10 ) ;
F_5 ( V_10 ) ;
return V_13 ;
}
static int F_27 ( struct V_61 * V_62 , struct V_63 * V_64 ,
int V_65 )
{
struct V_1 * V_2 = F_28 ( V_62 ) ;
int V_66 ;
if ( F_29 ( & V_2 -> V_67 ) < 0 )
return - V_68 ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
T_1 V_54 , V_56 , V_58 , * V_55 , * V_57 ;
int V_13 ;
if ( V_64 [ V_66 ] . V_69 & V_70 ) {
V_54 = V_64 [ V_66 ] . V_54 ;
V_55 = NULL ;
V_56 = 0 ;
V_57 = V_64 [ V_66 ] . V_10 ;
V_58 = V_64 [ V_66 ] . V_71 ;
} else {
V_54 = V_64 [ V_66 ] . V_54 ;
V_55 = V_64 [ V_66 ] . V_10 ;
V_56 = V_64 [ V_66 ] . V_71 ;
V_57 = NULL ;
V_58 = 0 ;
}
V_13 = F_26 ( V_2 , V_54 , V_55 , V_56 , V_57 ,
V_58 ) ;
if ( V_13 < V_58 )
break;
}
F_8 ( & V_2 -> V_67 ) ;
return V_66 ;
}
static T_2 F_30 ( struct V_61 * V_62 )
{
return V_72 ;
}
static int F_31 ( struct V_1 * V_2 , int V_66 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 * V_73 , * V_74 ;
int V_13 ;
F_25 ( L_16 , V_14 , V_66 ) ;
if ( ! V_66 )
return 0 ;
if ( V_8 -> V_75 )
return 0 ;
V_73 = F_3 ( 5 + V_76 , V_16 ) ;
if ( ! V_73 )
return - V_17 ;
V_74 = V_73 + 5 ;
V_13 = F_32 ( V_2 -> V_77 , 0 , V_78 ) ;
if ( V_13 != 0 )
F_25 ( L_17 ,
V_14 , V_13 ) ;
V_73 [ 0 ] = 0xaa ;
V_73 [ 1 ] = V_8 -> V_18 ++ ;
V_73 [ 2 ] = V_79 ;
V_73 [ 3 ] = 1 ;
V_73 [ 4 ] = 0 ;
V_13 = F_4 ( V_2 , V_73 , 5 , V_74 , V_76 , 0 ) ;
if ( V_13 )
goto V_13;
V_73 [ 1 ] = V_8 -> V_18 ++ ;
V_73 [ 4 ] = 1 ;
V_13 = F_4 ( V_2 , V_73 , 5 , V_74 , V_76 , 0 ) ;
if ( V_13 )
goto V_13;
V_8 -> V_75 = 1 ;
V_13:
F_5 ( V_73 ) ;
return V_13 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 * V_80 , * V_74 ;
int V_13 , V_66 ;
T_1 V_11 ;
V_80 = F_3 ( V_81 + V_76 , V_16 ) ;
if ( ! V_80 )
return - V_17 ;
V_74 = V_80 + V_81 ;
V_11 = V_8 -> V_18 ++ ;
V_80 [ 0 ] = V_19 ;
V_80 [ 1 ] = V_11 ;
V_80 [ 2 ] = V_82 ;
V_80 [ 3 ] = 0 ;
V_13 = F_4 ( V_2 , V_80 , 4 , V_74 , V_76 , 0 ) ;
if ( V_13 != 0 )
goto V_13;
if ( V_83 > 3 ) {
F_25 ( L_18 , V_14 , V_13 , 3 , V_74 ) ;
for ( V_66 = 0 ; ( V_66 < V_74 [ 3 ] ) && ( ( V_66 + 3 ) < V_76 ) ; V_66 ++ )
F_25 ( L_19 , V_74 [ V_66 + 3 ] ) ;
F_25 ( L_20 ) ;
}
if ( ( V_74 [ 3 ] == 9 ) && ( V_74 [ 12 ] & 0x01 ) ) {
V_8 -> V_84 = F_34 ( V_74 [ 7 ] , V_74 [ 6 ] ) ;
if ( V_83 > 2 )
F_25 ( L_21 ,
V_14 , V_74 [ 6 ] , V_74 [ 7 ] ) ;
F_35 ( V_2 -> V_85 , V_86 , V_8 -> V_84 , 0 ) ;
} else if ( V_8 -> V_84 ) {
F_36 ( V_2 -> V_85 ) ;
V_8 -> V_84 = 0 ;
}
V_13:
F_5 ( V_80 ) ;
return V_13 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_87 [ 6 ] )
{
const T_1 V_88 [] = { 0x1f , 0xcc } ;
T_1 V_89 [ 20 ] ;
int V_13 ;
V_13 = - V_68 ;
if ( F_29 ( & V_2 -> V_67 ) < 0 )
goto V_20;
V_13 = F_26 ( V_2 , V_90 ,
V_88 + 1 , 1 ,
V_89 , 20 ) ;
if ( - V_60 == V_13 )
V_13 = F_26 ( V_2 , V_91 ,
V_88 , 2 ,
V_89 , 20 ) ;
F_8 ( & V_2 -> V_67 ) ;
if ( 20 != V_13 )
goto V_20;
V_13 = F_38 ( V_87 , V_89 ) ;
if ( 0 != V_13 )
goto V_20;
return 0 ;
V_20:
F_39 ( V_87 ) ;
return V_13 ;
}
static int F_40 ( struct V_40 * V_41 )
{
struct V_92 * V_11 ;
V_41 -> V_93 [ 0 ] . V_94 = F_41 ( V_95 , & V_96 ,
& V_41 -> V_42 -> V_97 ) ;
if ( ! V_41 -> V_93 [ 0 ] . V_94 )
return - V_98 ;
if ( ( F_41 ( V_99 , V_41 -> V_93 [ 0 ] . V_94 ,
& V_41 -> V_42 -> V_97 ) ) == NULL )
F_2 ( L_22 ) ;
V_11 = V_41 -> V_42 -> V_100 -> V_101 [ 0 ] ;
if ( V_102 == V_11 -> V_103
&& V_104 == V_11 -> V_105 )
F_22 ( V_41 ) ;
return 0 ;
}
static int F_42 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_93 [ 0 ] . V_94 )
return - V_98 ;
if ( F_41 ( V_106 , V_41 -> V_93 [ 0 ] . V_94 , & V_107 ,
& V_41 -> V_42 -> V_97 ) == NULL ) {
F_2 ( L_23 , V_14 ) ;
return - V_98 ;
}
return 0 ;
}
static void F_43 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_44 ( V_109 ) ;
F_20 ( V_2 ) ;
F_45 ( V_109 ) ;
}
static int F_46 ( struct V_108 * V_109 ,
const struct V_92 * V_11 )
{
if ( 0 == F_47 ( V_109 , & V_110 ,
V_44 , NULL , V_111 ) ||
0 == F_47 ( V_109 , & V_112 ,
V_44 , NULL , V_111 ) )
return 0 ;
return - V_98 ;
}
