static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_10 ;
unsigned int V_11 ;
int V_12 ;
if ( ! V_4 || ( V_5 > 64 - 4 ) || ( V_6 > 64 - 4 ) ) {
F_2 ( L_1 , V_13 ) ;
return - V_14 ;
}
F_3 ( & V_8 -> V_15 ) ;
V_10 = V_8 -> V_16 ++ ;
V_8 -> V_4 [ 0 ] = V_17 ;
V_8 -> V_4 [ 1 ] = V_10 ;
V_8 -> V_4 [ 2 ] = V_3 ;
V_8 -> V_4 [ 3 ] = V_5 ;
memcpy ( V_8 -> V_4 + 4 , V_4 , V_5 ) ;
V_11 = ( V_6 > 0 ) ? 64 : 0 ;
V_12 = F_4 ( V_2 , V_8 -> V_4 , 4 + V_5 ,
V_8 -> V_4 , V_11 , 0 ) ;
if ( 0 != V_12 )
goto V_18;
V_12 = - V_14 ;
if ( V_19 != V_8 -> V_4 [ 0 ] || V_10 != V_8 -> V_4 [ 1 ] )
goto V_18;
memcpy ( V_4 , V_8 -> V_4 + 4 , V_6 ) ;
F_5 ( & V_8 -> V_15 ) ;
return 0 ;
V_18:
F_2 ( L_2 ,
V_12 , V_17 , V_10 , V_3 , 3 , V_8 -> V_4 ) ;
F_5 ( & V_8 -> V_15 ) ;
return V_12 ;
}
static int F_6 ( struct V_20 * V_21 ,
T_1 V_3 , T_1 * V_4 , unsigned int V_5 ,
unsigned int V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_21 -> V_4 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
int V_12 ;
F_3 ( & V_8 -> V_15 ) ;
V_12 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_5 ( & V_8 -> V_15 ) ;
return V_12 ;
}
static int F_7 ( struct V_20 * V_21 ,
int V_22 , int V_23 )
{
T_1 V_24 [ 3 ] ;
int V_12 ;
if ( 0 != V_22 )
return - V_25 ;
V_24 [ 0 ] = ( V_23 >> 8 ) & 0x0F ;
V_24 [ 1 ] = V_23 ;
V_12 = F_6 ( V_21 , V_26 , V_24 , 2 , 3 ) ;
F_8 ( L_3 ,
V_13 , V_23 , V_12 , V_24 [ 2 ] ) ;
if ( V_12 < 0 )
return V_12 ;
return V_24 [ 2 ] ;
}
static int F_9 ( struct V_20 * V_21 ,
int V_22 , int V_23 , T_1 V_27 )
{
T_1 V_24 [ 3 ] ;
F_8 ( L_4 ,
V_13 , V_22 , V_23 , V_27 ) ;
if ( 0 != V_22 )
return - V_25 ;
V_24 [ 0 ] = ( V_23 >> 8 ) & 0x0F ;
V_24 [ 1 ] = V_23 ;
V_24 [ 2 ] = V_27 ;
return F_6 ( V_21 , V_28 , V_24 , 3 , 3 ) ;
}
static int F_10 ( struct V_20 * V_21 ,
int V_22 ,
T_1 V_23 )
{
T_1 V_24 [ 2 ] ;
int V_12 ;
if ( 0 != V_22 )
return - V_25 ;
V_24 [ 0 ] = V_23 & 3 ;
V_12 = F_6 ( V_21 , V_29 , V_24 , 1 , 2 ) ;
F_8 ( L_5 ,
V_13 , V_23 , V_12 , V_24 [ 1 ] ) ;
if ( V_12 < 0 )
return V_12 ;
return V_24 [ 1 ] ;
}
static int F_11 ( struct V_20 * V_21 ,
int V_22 ,
T_1 V_23 ,
T_1 V_27 )
{
T_1 V_24 [ 2 ] ;
F_8 ( L_6 ,
V_13 , V_22 , V_23 , V_27 ) ;
if ( 0 != V_22 )
return - V_25 ;
V_24 [ 0 ] = V_23 ;
V_24 [ 1 ] = V_27 ;
return F_6 ( V_21 , V_30 , V_24 , 2 , 2 ) ;
}
static int F_12 ( struct V_20 * V_21 ,
int V_22 ,
int V_31 )
{
T_1 V_24 [ 1 ] ;
int V_12 ;
F_8 ( L_7 , V_13 , V_22 , V_31 ) ;
if ( 0 != V_22 )
return - V_25 ;
V_31 = ! ! V_31 ;
V_24 [ 0 ] = V_31 ;
V_12 = F_6 ( V_21 , V_32 , V_24 , 1 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_31 != V_24 [ 0 ] ) {
F_2 ( L_8 , V_31 ? L_9 : L_10 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_13 ( struct V_20 * V_21 , int V_22 )
{
return F_12 ( V_21 , V_22 , 0 ) ;
}
static int F_14 ( struct V_20 * V_21 , int V_22 )
{
return F_12 ( V_21 , V_22 , 1 ) ;
}
static int F_15 ( struct V_20 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_21 -> V_4 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_24 [ 1 ] ;
int V_12 ;
F_8 ( L_11 , V_13 , V_22 ) ;
if ( 0 != V_22 )
return - V_25 ;
V_24 [ 0 ] = 0 ;
F_3 ( & V_8 -> V_15 ) ;
V_12 = F_1 ( V_2 , V_33 , V_24 , 1 , 1 ) ;
if ( 0 != V_12 )
goto V_18;
F_16 ( 500 ) ;
V_24 [ 0 ] = 1 ;
V_12 = F_1 ( V_2 , V_33 , V_24 , 1 , 1 ) ;
if ( 0 != V_12 )
goto V_18;
F_16 ( 500 ) ;
V_24 [ 0 ] = 0 ;
V_12 = F_1 ( V_2 , V_32 , V_24 , 1 , 1 ) ;
V_18:
F_5 ( & V_8 -> V_15 ) ;
return V_12 ;
}
static int F_17 ( struct V_20 * V_21 ,
int V_22 ,
int V_34 )
{
T_1 V_24 [ 1 ] ;
int V_12 ;
if ( 0 != V_22 )
return - V_25 ;
V_12 = F_6 ( V_21 , V_35 , V_24 , 0 , 1 ) ;
if ( 0 != V_12 )
return V_12 ;
if ( 1 == V_24 [ 0 ] )
return V_36 |
V_37 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_8 ( L_12 , V_13 ) ;
if ( NULL == V_2 )
return;
V_8 = (struct V_7 * ) V_2 -> V_9 ;
if ( NULL == V_8 )
return;
if ( NULL == V_8 -> V_21 . V_4 )
return;
F_12 ( & V_8 -> V_21 , 0 , 0 ) ;
F_19 ( & V_8 -> V_21 ) ;
memset ( & V_8 -> V_21 , 0 , sizeof( V_8 -> V_21 ) ) ;
}
static int F_20 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
int V_12 ;
F_8 ( L_12 , V_13 ) ;
F_21 ( & V_8 -> V_15 ) ;
V_8 -> V_21 . V_41 = V_42 ;
V_8 -> V_21 . V_43 = F_7 ;
V_8 -> V_21 . V_44 = F_9 ;
V_8 -> V_21 . V_45 = F_10 ;
V_8 -> V_21 . V_46 = F_11 ;
V_8 -> V_21 . V_47 = F_15 ;
V_8 -> V_21 . V_48 = F_13 ;
V_8 -> V_21 . V_49 = F_14 ;
V_8 -> V_21 . V_50 = F_17 ;
V_8 -> V_21 . V_4 = V_2 ;
V_12 = F_22 ( & V_39 -> V_51 ,
& V_8 -> V_21 ,
0 ,
1 ) ;
if ( 0 != V_12 ) {
F_2 ( L_13 , V_12 ) ;
memset ( & V_8 -> V_21 , 0 , sizeof( V_8 -> V_21 ) ) ;
return V_12 ;
}
F_23 ( L_14 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_52 ,
const T_1 * V_53 , T_1 V_54 ,
T_1 * V_55 , T_1 V_56 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 V_10 ;
int V_12 ;
F_3 ( & V_8 -> V_15 ) ;
V_10 = V_8 -> V_16 ++ ;
V_12 = - V_25 ;
if ( V_54 > 64 - 7 || V_56 > 64 - 7 )
goto V_18;
V_8 -> V_4 [ 0 ] = V_17 ;
V_8 -> V_4 [ 1 ] = V_10 ;
V_8 -> V_4 [ 2 ] = V_57 ;
V_8 -> V_4 [ 3 ] = V_54 + 3 ;
V_8 -> V_4 [ 4 ] = V_52 << 1 ;
V_8 -> V_4 [ 5 ] = V_54 ;
V_8 -> V_4 [ 6 ] = V_56 ;
memcpy ( V_8 -> V_4 + 7 , V_53 , V_54 ) ;
V_12 = F_4 ( V_2 , V_8 -> V_4 , 7 + V_54 ,
V_8 -> V_4 , 64 ,
0 ) ;
if ( V_12 < 0 )
goto V_18;
V_12 = - V_14 ;
if ( V_19 != V_8 -> V_4 [ 0 ] || V_10 != V_8 -> V_4 [ 1 ] )
goto V_18;
V_12 = - V_58 ;
if ( V_8 -> V_4 [ 5 ] < V_54 || V_8 -> V_4 [ 6 ] < V_56 )
goto V_18;
memcpy ( V_55 , V_8 -> V_4 + 7 , V_56 ) ;
F_5 ( & V_8 -> V_15 ) ;
return V_56 ;
V_18:
F_2 ( L_15 ,
V_12 , V_17 , V_10 , V_52 << 1 , V_54 , V_56 ,
7 , V_8 -> V_4 ) ;
F_5 ( & V_8 -> V_15 ) ;
return V_12 ;
}
static int F_25 ( struct V_59 * V_60 , struct V_61 * V_62 ,
int V_63 )
{
struct V_1 * V_2 = F_26 ( V_60 ) ;
int V_64 ;
if ( F_27 ( & V_2 -> V_65 ) < 0 )
return - V_66 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
T_1 V_52 , V_54 , V_56 , * V_53 , * V_55 ;
int V_12 ;
if ( V_62 [ V_64 ] . V_67 & V_68 ) {
V_52 = V_62 [ V_64 ] . V_52 ;
V_53 = NULL ;
V_54 = 0 ;
V_55 = V_62 [ V_64 ] . V_24 ;
V_56 = V_62 [ V_64 ] . V_69 ;
} else {
V_52 = V_62 [ V_64 ] . V_52 ;
V_53 = V_62 [ V_64 ] . V_24 ;
V_54 = V_62 [ V_64 ] . V_69 ;
V_55 = NULL ;
V_56 = 0 ;
}
V_12 = F_24 ( V_2 , V_52 , V_53 , V_54 , V_55 ,
V_56 ) ;
if ( V_12 < V_56 )
break;
}
F_5 ( & V_2 -> V_65 ) ;
return V_64 ;
}
static T_2 F_28 ( struct V_59 * V_60 )
{
return V_70 ;
}
static int F_29 ( struct V_1 * V_2 , int V_64 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
T_1 * V_71 ;
int V_12 ;
F_23 ( L_16 , V_13 , V_64 ) ;
if ( ! V_64 )
return 0 ;
if ( V_8 -> V_72 )
return 0 ;
V_71 = F_30 ( V_73 , V_74 ) ;
if ( ! V_71 )
return - V_75 ;
F_3 ( & V_8 -> V_15 ) ;
V_12 = F_31 ( V_2 -> V_76 , 0 , V_77 ) ;
if ( V_12 != 0 )
F_23 ( L_17 ,
V_13 , V_12 ) ;
V_8 -> V_4 [ 0 ] = 0xaa ;
V_8 -> V_4 [ 1 ] = V_8 -> V_16 ++ ;
V_8 -> V_4 [ 2 ] = V_78 ;
V_8 -> V_4 [ 3 ] = 1 ;
V_8 -> V_4 [ 4 ] = 0 ;
V_12 = F_4 ( V_2 , V_8 -> V_4 , 5 , V_71 , V_73 , 0 ) ;
if ( V_12 )
goto V_12;
V_8 -> V_4 [ 1 ] = V_8 -> V_16 ++ ;
V_8 -> V_4 [ 4 ] = 1 ;
V_12 = F_4 ( V_2 , V_8 -> V_4 , 5 , V_71 , V_73 , 0 ) ;
if ( V_12 )
goto V_12;
V_8 -> V_72 = 1 ;
V_12:
F_5 ( & V_8 -> V_15 ) ;
F_32 ( V_71 ) ;
return V_12 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
int V_12 , V_64 ;
T_1 V_10 ;
F_3 ( & V_8 -> V_15 ) ;
V_10 = V_8 -> V_16 ++ ;
V_8 -> V_4 [ 0 ] = V_17 ;
V_8 -> V_4 [ 1 ] = V_10 ;
V_8 -> V_4 [ 2 ] = V_79 ;
V_8 -> V_4 [ 3 ] = 0 ;
V_12 = F_4 ( V_2 , V_8 -> V_4 , 4 ,
V_8 -> V_4 , V_73 , 0 ) ;
if ( V_12 != 0 )
goto V_12;
if ( V_80 > 3 ) {
F_23 ( L_18 , V_13 , V_12 , 3 , V_8 -> V_4 ) ;
for ( V_64 = 0 ; ( V_64 < V_8 -> V_4 [ 3 ] ) && ( ( V_64 + 3 ) < V_73 ) ; V_64 ++ )
F_23 ( L_19 , V_8 -> V_4 [ V_64 + 3 ] ) ;
F_23 ( L_20 ) ;
}
if ( ( V_8 -> V_4 [ 3 ] == 9 ) && ( V_8 -> V_4 [ 12 ] & 0x01 ) ) {
V_8 -> V_81 = F_34 ( V_8 -> V_4 [ 7 ] , V_8 -> V_4 [ 6 ] ) ;
if ( V_80 > 2 )
F_23 ( L_21 ,
V_13 , V_8 -> V_4 [ 6 ] , V_8 -> V_4 [ 7 ] ) ;
F_35 ( V_2 -> V_82 , V_83 , V_8 -> V_81 , 0 ) ;
} else if ( V_8 -> V_81 ) {
F_36 ( V_2 -> V_82 ) ;
V_8 -> V_81 = 0 ;
}
V_12:
F_5 ( & V_8 -> V_15 ) ;
return V_12 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_84 [ 6 ] )
{
const T_1 V_85 [] = { 0x1f , 0xcc } ;
T_1 V_86 [ 20 ] ;
int V_12 ;
V_12 = - V_66 ;
if ( F_27 ( & V_2 -> V_65 ) < 0 )
goto V_18;
V_12 = F_24 ( V_2 , V_87 ,
V_85 + 1 , 1 ,
V_86 , 20 ) ;
if ( - V_58 == V_12 )
V_12 = F_24 ( V_2 , V_88 ,
V_85 , 2 ,
V_86 , 20 ) ;
F_5 ( & V_2 -> V_65 ) ;
if ( 20 != V_12 )
goto V_18;
V_12 = F_38 ( V_84 , V_86 ) ;
if ( 0 != V_12 )
goto V_18;
return 0 ;
V_18:
F_39 ( V_84 ) ;
return V_12 ;
}
static int F_40 ( struct V_38 * V_39 )
{
struct V_89 * V_10 ;
V_39 -> V_90 [ 0 ] . V_91 = F_41 ( V_92 , & V_93 ,
& V_39 -> V_40 -> V_94 ) ;
if ( ! V_39 -> V_90 [ 0 ] . V_91 )
return - V_95 ;
if ( ( F_41 ( V_96 , V_39 -> V_90 [ 0 ] . V_91 ,
& V_39 -> V_40 -> V_94 ) ) == NULL )
F_2 ( L_22 ) ;
V_10 = V_39 -> V_40 -> V_97 -> V_98 [ 0 ] ;
if ( V_99 == V_10 -> V_100
&& V_101 == V_10 -> V_102 )
F_20 ( V_39 ) ;
return 0 ;
}
static int F_42 ( struct V_38 * V_39 )
{
if ( ! V_39 -> V_90 [ 0 ] . V_91 )
return - V_95 ;
if ( F_41 ( V_103 , V_39 -> V_90 [ 0 ] . V_91 , & V_104 ,
& V_39 -> V_40 -> V_94 ) == NULL ) {
F_2 ( L_23 , V_13 ) ;
return - V_95 ;
}
return 0 ;
}
static void F_43 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = F_44 ( V_106 ) ;
F_18 ( V_2 ) ;
F_45 ( V_106 ) ;
}
static int F_46 ( struct V_105 * V_106 ,
const struct V_89 * V_10 )
{
if ( 0 == F_47 ( V_106 , & V_107 ,
V_42 , NULL , V_108 ) ||
0 == F_47 ( V_106 , & V_109 ,
V_42 , NULL , V_108 ) )
return 0 ;
return - V_95 ;
}
