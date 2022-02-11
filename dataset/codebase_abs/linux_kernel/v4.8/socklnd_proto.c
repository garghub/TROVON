static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
F_2 ( & V_4 -> V_5 , & V_3 -> V_6 ) ;
return NULL ;
}
void
F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = V_3 -> V_8 ;
F_4 ( ! F_5 ( & V_3 -> V_6 ) ) ;
F_4 ( V_7 ) ;
if ( V_7 -> V_5 . V_9 == & V_3 -> V_6 ) {
V_3 -> V_8 = NULL ;
} else {
V_3 -> V_8 = F_6 ( V_7 , V_5 ) ;
F_4 ( V_3 -> V_8 -> V_4 . V_10 == V_7 -> V_4 . V_10 ) ;
}
}
static int
F_7 ( struct V_2 * V_3 ,
struct V_1 * V_11 , T_1 V_12 )
{
struct V_1 * V_7 = V_3 -> V_8 ;
F_4 ( ! V_11 ||
V_11 -> V_4 . V_10 == V_13 ) ;
if ( ! V_7 ) {
if ( V_11 ) {
F_2 ( & V_11 -> V_5 ,
& V_3 -> V_6 ) ;
V_3 -> V_8 = V_11 ;
}
return 0 ;
}
if ( V_7 -> V_4 . V_10 == V_13 ) {
if ( V_11 )
F_2 ( & V_11 -> V_5 ,
& V_3 -> V_6 ) ;
return 0 ;
}
F_4 ( V_7 -> V_4 . V_10 == V_14 ) ;
F_4 ( ! V_7 -> V_4 . V_15 [ 1 ] ) ;
if ( V_11 )
V_12 = V_11 -> V_4 . V_15 [ 1 ] ;
V_7 -> V_4 . V_15 [ 1 ] = V_12 ;
F_3 ( V_3 ) ;
return 1 ;
}
static struct V_1 *
F_8 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_7 = V_3 -> V_8 ;
if ( ! V_7 ) {
F_2 ( & V_4 -> V_5 , & V_3 -> V_6 ) ;
V_3 -> V_8 = V_4 ;
return NULL ;
}
if ( V_7 -> V_4 . V_10 == V_14 ) {
F_2 ( & V_4 -> V_5 , & V_3 -> V_6 ) ;
return NULL ;
}
F_4 ( V_7 -> V_4 . V_10 == V_13 ) ;
V_4 -> V_4 . V_15 [ 1 ] = V_7 -> V_4 . V_15 [ 1 ] ;
F_3 ( V_3 ) ;
F_9 ( & V_4 -> V_5 , & V_7 -> V_5 ) ;
F_10 ( & V_7 -> V_5 ) ;
return V_7 ;
}
static int
F_11 ( struct V_2 * V_3 ,
struct V_1 * V_11 , T_1 V_12 )
{
struct V_1 * V_7 ;
if ( V_3 -> V_16 != V_17 )
return F_7 ( V_3 , V_11 , V_12 ) ;
F_4 ( ! V_11 ||
V_11 -> V_4 . V_10 == V_13 ) ;
V_7 = V_3 -> V_8 ;
if ( ! V_7 ) {
if ( V_11 ) {
F_2 ( & V_11 -> V_5 ,
& V_3 -> V_6 ) ;
V_3 -> V_8 = V_11 ;
}
return 0 ;
}
if ( V_11 )
V_12 = V_11 -> V_4 . V_15 [ 1 ] ;
if ( V_12 == V_18 )
return 1 ;
if ( V_7 -> V_4 . V_15 [ 1 ] == V_18 ) {
F_4 ( ! V_7 -> V_4 . V_15 [ 0 ] ) ;
V_7 -> V_4 . V_15 [ 1 ] = V_12 ;
return 1 ;
}
if ( V_12 == V_7 -> V_4 . V_15 [ 0 ] ||
V_12 == V_7 -> V_4 . V_15 [ 1 ] ) {
F_12 ( L_1 ,
F_13 ( V_3 -> V_19 -> V_20 ) , V_12 ) ;
return 1 ;
}
if ( ! V_7 -> V_4 . V_15 [ 0 ] ) {
if ( V_7 -> V_4 . V_15 [ 1 ] > V_12 ) {
V_7 -> V_4 . V_15 [ 0 ] = V_7 -> V_4 . V_15 [ 1 ] ;
V_7 -> V_4 . V_15 [ 1 ] = V_12 ;
} else {
V_7 -> V_4 . V_15 [ 0 ] = V_12 ;
}
if ( V_7 -> V_4 . V_15 [ 0 ] - V_7 -> V_4 . V_15 [ 1 ] > 2 ) {
F_3 ( V_3 ) ;
}
return 1 ;
}
if ( V_7 -> V_4 . V_15 [ 0 ] > V_7 -> V_4 . V_15 [ 1 ] ) {
T_1 V_21 = 0 ;
F_4 ( V_7 -> V_4 . V_15 [ 0 ] -
V_7 -> V_4 . V_15 [ 1 ] <= 2 ) ;
if ( V_7 -> V_4 . V_15 [ 0 ] -
V_7 -> V_4 . V_15 [ 1 ] == 2 ) {
if ( V_12 == V_7 -> V_4 . V_15 [ 1 ] + 1 )
V_21 = V_12 ;
} else if ( V_12 == V_7 -> V_4 . V_15 [ 1 ] - 1 ) {
V_21 = V_7 -> V_4 . V_15 [ 1 ] ;
} else if ( V_12 == V_7 -> V_4 . V_15 [ 0 ] + 1 ) {
V_21 = V_7 -> V_4 . V_15 [ 0 ] ;
}
if ( V_21 ) {
V_7 -> V_4 . V_15 [ 0 ] = V_21 - 1 ;
V_7 -> V_4 . V_15 [ 1 ] = V_21 + 1 ;
return 1 ;
}
} else {
if ( V_12 >= V_7 -> V_4 . V_15 [ 0 ] &&
V_12 <= V_7 -> V_4 . V_15 [ 1 ] ) {
F_12 ( L_1 ,
F_13 ( V_3 -> V_19 -> V_20 ) , V_12 ) ;
return 1 ;
}
if ( V_12 == V_7 -> V_4 . V_15 [ 1 ] + 1 ) {
V_7 -> V_4 . V_15 [ 1 ] = V_12 ;
return 1 ;
}
if ( V_12 == V_7 -> V_4 . V_15 [ 0 ] - 1 ) {
V_7 -> V_4 . V_15 [ 0 ] = V_12 ;
return 1 ;
}
}
if ( V_11 ) {
F_2 ( & V_11 -> V_5 , & V_3 -> V_6 ) ;
F_3 ( V_3 ) ;
}
return 0 ;
}
static int
F_14 ( struct V_2 * V_3 , struct V_1 * V_7 , int V_22 )
{
int V_23 ;
#if V_24
if ( ! * V_25 . V_26 )
return V_27 ;
#endif
if ( ! V_7 || ! V_7 -> V_28 ) {
V_23 = F_15 ( V_29 , V_30 ) ;
} else {
V_23 = V_7 -> V_28 -> V_31 +
( ( V_3 -> V_32 == & V_33 ) ?
sizeof( V_34 ) : sizeof( V_29 ) ) ;
}
switch ( V_3 -> V_16 ) {
default:
F_16 ( L_2 , V_3 -> V_16 ) ;
F_17 () ;
case V_35 :
return V_27 ;
case V_36 :
return V_37 ;
case V_38 :
if ( V_23 < * V_25 . V_39 )
return V_37 ;
else
return V_27 ;
case V_40 :
if ( V_23 >= * V_25 . V_39 )
return V_37 ;
else
return V_27 ;
}
}
static int
F_18 ( struct V_2 * V_3 , struct V_1 * V_7 , int V_22 )
{
int V_23 ;
if ( ! V_7 || ! V_7 -> V_28 )
V_23 = F_15 ( V_29 , V_30 ) ;
else
V_23 = V_7 -> V_28 -> V_31 + sizeof( V_29 ) ;
switch ( V_3 -> V_16 ) {
default:
F_16 ( L_2 , V_3 -> V_16 ) ;
F_17 () ;
case V_35 :
return V_41 ;
case V_17 :
if ( V_22 )
return V_27 ;
else if ( ! V_7 || ! V_7 -> V_28 )
return V_37 ;
else
return V_41 ;
case V_38 :
if ( V_22 )
return V_41 ;
else if ( V_23 < * V_25 . V_39 )
return V_37 ;
else
return V_27 ;
case V_40 :
if ( V_22 )
return V_41 ;
else if ( V_23 >= * V_25 . V_39 )
return V_37 ;
else
return V_27 ;
}
}
static int
F_19 ( struct V_2 * V_42 , T_1 V_12 , int V_43 )
{
struct V_44 * V_45 = V_42 -> V_19 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
int V_46 ;
F_20 ( & V_47 . V_48 ) ;
V_3 = F_21 ( V_45 , NULL , ! ! V_43 ) ;
if ( V_3 ) {
struct V_49 * V_50 = V_3 -> V_51 ;
F_4 ( V_3 -> V_32 -> V_52 ) ;
F_22 ( & V_50 -> V_53 ) ;
V_46 = V_3 -> V_32 -> V_52 ( V_3 , NULL , V_12 ) ;
F_23 ( & V_50 -> V_53 ) ;
if ( V_46 ) {
F_24 ( & V_47 . V_48 ) ;
return 0 ;
}
}
F_24 ( & V_47 . V_48 ) ;
V_7 = F_25 ( V_12 , ! ! V_43 ) ;
if ( ! V_7 )
return - V_54 ;
V_46 = F_26 ( V_45 -> V_55 , V_7 , V_45 -> V_20 ) ;
if ( ! V_46 )
return 0 ;
F_27 ( V_7 ) ;
return V_46 ;
}
static int
F_28 ( struct V_2 * V_3 , T_1 V_56 , T_1 V_57 )
{
struct V_44 * V_45 = V_3 -> V_19 ;
struct V_1 * V_7 ;
struct V_1 * V_58 ;
struct V_1 * V_21 ;
F_29 ( V_59 ) ;
int V_60 ;
if ( ! V_56 )
V_56 = V_57 ;
V_60 = ( V_56 > V_57 ) ? 2 : ( V_57 - V_56 + 1 ) ;
if ( V_57 == V_18 &&
V_3 -> V_32 == & V_61 ) {
return V_60 == 1 ? 0 : - V_62 ;
}
F_30 ( & V_45 -> V_63 ) ;
F_31 (tx, tmp, &peer->ksnp_zc_req_list,
tx_zc_list) {
T_1 V_42 = V_7 -> V_4 . V_15 [ 0 ] ;
if ( V_42 == V_56 || V_42 == V_57 || ( V_56 < V_42 && V_42 < V_57 ) ) {
V_7 -> V_4 . V_15 [ 0 ] = 0 ;
F_10 ( & V_7 -> V_64 ) ;
F_9 ( & V_7 -> V_64 , & V_59 ) ;
if ( ! -- V_60 )
break;
}
}
F_32 ( & V_45 -> V_63 ) ;
F_31 (tx, temp, &zlist, tx_zc_list) {
F_10 ( & V_7 -> V_64 ) ;
F_33 ( V_7 ) ;
}
return ! V_60 ? 0 : - V_62 ;
}
static int
F_34 ( struct V_2 * V_3 , T_2 * V_65 )
{
struct V_66 * V_67 = V_3 -> V_68 ;
V_34 * V_69 ;
T_3 * V_70 ;
int V_46 ;
int V_71 ;
F_35 ( sizeof( T_3 ) == F_15 ( V_34 , V_72 ) ) ;
F_36 ( V_69 , sizeof( * V_69 ) ) ;
if ( ! V_69 ) {
F_16 ( L_3 ) ;
return - V_54 ;
}
V_70 = ( T_3 * ) & V_69 -> V_73 ;
V_70 -> V_74 = F_37 ( V_75 ) ;
V_70 -> V_76 = F_38 ( V_77 ) ;
V_70 -> V_78 = F_38 ( V_79 ) ;
if ( V_80 . V_81 ) {
F_39 () ;
if ( V_80 . V_81 & 1 ) {
V_70 -> V_76 ++ ;
V_80 . V_81 &= ~ 1 ;
}
if ( V_80 . V_81 & 2 ) {
V_70 -> V_74 = V_82 ;
V_80 . V_81 &= ~ 2 ;
}
F_40 () ;
}
V_69 -> V_72 = F_41 ( V_65 -> V_83 ) ;
V_69 -> V_84 = F_37 ( V_65 -> V_85 ) ;
V_69 -> type = F_37 ( V_86 ) ;
V_69 -> V_87 = F_37 ( V_65 -> V_88 * sizeof( V_89 ) ) ;
V_69 -> V_90 . V_65 . type = F_37 ( V_65 -> V_91 ) ;
V_69 -> V_90 . V_65 . V_92 = F_41 ( V_65 -> V_93 ) ;
V_46 = F_42 ( V_67 , V_69 , sizeof( * V_69 ) , F_43 () ) ;
if ( V_46 ) {
F_44 ( L_4 ,
V_46 , & V_3 -> V_94 , V_3 -> V_95 ) ;
goto V_96;
}
if ( ! V_65 -> V_88 )
goto V_96;
for ( V_71 = 0 ; V_71 < ( int ) V_65 -> V_88 ; V_71 ++ )
V_65 -> V_97 [ V_71 ] = F_45 ( V_65 -> V_97 [ V_71 ] ) ;
V_46 = F_42 ( V_67 , V_65 -> V_97 ,
V_65 -> V_88 * sizeof( V_89 ) ,
F_43 () ) ;
if ( V_46 ) {
F_44 ( L_5 ,
V_46 , V_65 -> V_88 ,
& V_3 -> V_94 , V_3 -> V_95 ) ;
}
V_96:
F_46 ( V_69 , sizeof( * V_69 ) ) ;
return V_46 ;
}
static int
F_47 ( struct V_2 * V_3 , T_2 * V_65 )
{
struct V_66 * V_67 = V_3 -> V_68 ;
int V_46 ;
V_65 -> V_98 = V_82 ;
V_65 -> V_99 = V_3 -> V_32 -> V_100 ;
if ( V_80 . V_81 ) {
F_39 () ;
if ( V_80 . V_81 & 1 ) {
V_65 -> V_99 ++ ;
V_80 . V_81 &= ~ 1 ;
}
F_40 () ;
}
V_46 = F_42 ( V_67 , V_65 , F_15 ( T_2 , V_97 ) ,
F_43 () ) ;
if ( V_46 ) {
F_44 ( L_4 ,
V_46 , & V_3 -> V_94 , V_3 -> V_95 ) ;
return V_46 ;
}
if ( ! V_65 -> V_88 )
return 0 ;
V_46 = F_42 ( V_67 , V_65 -> V_97 ,
V_65 -> V_88 * sizeof( V_89 ) ,
F_43 () ) ;
if ( V_46 ) {
F_44 ( L_5 ,
V_46 , V_65 -> V_88 ,
& V_3 -> V_94 , V_3 -> V_95 ) ;
}
return V_46 ;
}
static int
F_48 ( struct V_2 * V_3 , T_2 * V_65 ,
int V_101 )
{
struct V_66 * V_67 = V_3 -> V_68 ;
V_34 * V_69 ;
int V_46 ;
int V_71 ;
F_36 ( V_69 , sizeof( * V_69 ) ) ;
if ( ! V_69 ) {
F_16 ( L_3 ) ;
return - V_54 ;
}
V_46 = F_49 ( V_67 , & V_69 -> V_72 ,
sizeof( * V_69 ) - F_15 ( V_34 , V_72 ) ,
V_101 ) ;
if ( V_46 ) {
F_16 ( L_6 ,
V_46 , & V_3 -> V_94 ) ;
F_4 ( V_46 < 0 && V_46 != - V_102 ) ;
goto V_96;
}
if ( V_69 -> type != F_37 ( V_86 ) ) {
F_16 ( L_7 ,
F_50 ( V_69 -> type ) ,
& V_3 -> V_94 ) ;
V_46 = - V_62 ;
goto V_96;
}
V_65 -> V_83 = F_51 ( V_69 -> V_72 ) ;
V_65 -> V_85 = F_50 ( V_69 -> V_84 ) ;
V_65 -> V_93 = F_51 ( V_69 -> V_90 . V_65 . V_92 ) ;
V_65 -> V_91 = F_50 ( V_69 -> V_90 . V_65 . type ) ;
V_65 -> V_88 = F_50 ( V_69 -> V_87 ) /
sizeof( V_89 ) ;
if ( V_65 -> V_88 > V_103 ) {
F_16 ( L_8 ,
V_65 -> V_88 , & V_3 -> V_94 ) ;
V_46 = - V_62 ;
goto V_96;
}
if ( ! V_65 -> V_88 )
goto V_96;
V_46 = F_49 ( V_67 , V_65 -> V_97 ,
V_65 -> V_88 * sizeof( V_89 ) , V_101 ) ;
if ( V_46 ) {
F_16 ( L_9 ,
V_46 , & V_3 -> V_94 ) ;
F_4 ( V_46 < 0 && V_46 != - V_102 ) ;
goto V_96;
}
for ( V_71 = 0 ; V_71 < ( int ) V_65 -> V_88 ; V_71 ++ ) {
V_65 -> V_97 [ V_71 ] = F_52 ( V_65 -> V_97 [ V_71 ] ) ;
if ( ! V_65 -> V_97 [ V_71 ] ) {
F_16 ( L_10 ,
V_71 , & V_3 -> V_94 ) ;
V_46 = - V_62 ;
break;
}
}
V_96:
F_46 ( V_69 , sizeof( * V_69 ) ) ;
return V_46 ;
}
static int
F_53 ( struct V_2 * V_3 , T_2 * V_65 , int V_101 )
{
struct V_66 * V_67 = V_3 -> V_68 ;
int V_46 ;
int V_71 ;
if ( V_65 -> V_98 == V_82 )
V_3 -> V_104 = 0 ;
else
V_3 -> V_104 = 1 ;
V_46 = F_49 ( V_67 , & V_65 -> V_83 ,
F_15 ( T_2 , V_97 ) -
F_15 ( T_2 , V_83 ) ,
V_101 ) ;
if ( V_46 ) {
F_16 ( L_11 ,
V_46 , & V_3 -> V_94 ) ;
F_4 ( V_46 < 0 && V_46 != - V_102 ) ;
return V_46 ;
}
if ( V_3 -> V_104 ) {
F_54 ( & V_65 -> V_85 ) ;
F_55 ( & V_65 -> V_83 ) ;
F_54 ( & V_65 -> V_105 ) ;
F_55 ( & V_65 -> V_106 ) ;
F_55 ( & V_65 -> V_93 ) ;
F_55 ( & V_65 -> V_107 ) ;
F_54 ( & V_65 -> V_91 ) ;
F_54 ( & V_65 -> V_88 ) ;
}
if ( V_65 -> V_88 > V_103 ) {
F_16 ( L_8 ,
V_65 -> V_88 , & V_3 -> V_94 ) ;
return - V_62 ;
}
if ( ! V_65 -> V_88 )
return 0 ;
V_46 = F_49 ( V_67 , V_65 -> V_97 ,
V_65 -> V_88 * sizeof( V_89 ) , V_101 ) ;
if ( V_46 ) {
F_16 ( L_9 ,
V_46 , & V_3 -> V_94 ) ;
F_4 ( V_46 < 0 && V_46 != - V_102 ) ;
return V_46 ;
}
for ( V_71 = 0 ; V_71 < ( int ) V_65 -> V_88 ; V_71 ++ ) {
if ( V_3 -> V_104 )
F_54 ( & V_65 -> V_97 [ V_71 ] ) ;
if ( ! V_65 -> V_97 [ V_71 ] ) {
F_16 ( L_10 ,
V_71 , & V_3 -> V_94 ) ;
return - V_62 ;
}
}
return 0 ;
}
static void
F_56 ( struct V_1 * V_7 )
{
F_4 ( V_7 -> V_4 . V_10 != V_13 ) ;
F_4 ( V_7 -> V_28 ) ;
V_7 -> V_108 [ 0 ] . V_109 = & V_7 -> V_28 -> V_110 ;
V_7 -> V_108 [ 0 ] . V_111 = sizeof( V_34 ) ;
V_7 -> V_112 = V_7 -> V_28 -> V_31 + sizeof( V_34 ) ;
V_7 -> V_113 = V_7 -> V_28 -> V_31 + sizeof( V_34 ) ;
}
static void
F_57 ( struct V_1 * V_7 )
{
V_7 -> V_108 [ 0 ] . V_109 = & V_7 -> V_4 ;
if ( V_7 -> V_28 ) {
F_4 ( V_7 -> V_4 . V_10 != V_13 ) ;
V_7 -> V_4 . V_30 . V_114 . V_115 = V_7 -> V_28 -> V_110 ;
V_7 -> V_108 [ 0 ] . V_111 = sizeof( V_29 ) ;
V_7 -> V_112 = sizeof( V_29 ) + V_7 -> V_28 -> V_31 ;
V_7 -> V_113 = sizeof( V_29 ) + V_7 -> V_28 -> V_31 ;
} else {
F_4 ( V_7 -> V_4 . V_10 == V_13 ) ;
V_7 -> V_108 [ 0 ] . V_111 = F_15 ( V_29 , V_30 . V_114 . V_115 ) ;
V_7 -> V_112 = F_15 ( V_29 , V_30 . V_114 . V_115 ) ;
V_7 -> V_113 = F_15 ( V_29 , V_30 . V_114 . V_115 ) ;
}
}
static void
F_58 ( V_29 * V_90 )
{
V_90 -> V_116 = 0 ;
V_90 -> V_10 = V_14 ;
V_90 -> V_15 [ 0 ] = 0 ;
V_90 -> V_15 [ 1 ] = 0 ;
}
static void
F_59 ( V_29 * V_90 )
{
return;
}
