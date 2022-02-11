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
V_23 = F_15 ( struct V_29 , V_30 ) ;
} else {
V_23 = V_7 -> V_28 -> V_31 +
( ( V_3 -> V_32 == & V_33 ) ?
sizeof( struct V_34 ) : sizeof( struct V_29 ) ) ;
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
V_23 = F_15 ( struct V_29 , V_30 ) ;
else
V_23 = V_7 -> V_28 -> V_31 + sizeof( struct V_29 ) ;
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
if ( V_42 == V_56 || V_42 == V_57 ||
( V_56 < V_42 && V_42 < V_57 ) ) {
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
F_34 ( struct V_2 * V_3 , struct V_65 * V_66 )
{
struct V_67 * V_68 = V_3 -> V_69 ;
struct V_34 * V_70 ;
struct V_71 * V_72 ;
int V_46 ;
int V_73 ;
F_35 ( sizeof( struct V_71 ) != F_15 ( struct V_34 , V_74 ) ) ;
F_36 ( V_70 , sizeof( * V_70 ) ) ;
if ( ! V_70 ) {
F_16 ( L_3 ) ;
return - V_54 ;
}
V_72 = (struct V_71 * ) & V_70 -> V_75 ;
V_72 -> V_76 = F_37 ( V_77 ) ;
V_72 -> V_78 = F_38 ( V_79 ) ;
V_72 -> V_80 = F_38 ( V_81 ) ;
if ( V_82 . V_83 ) {
F_39 () ;
if ( V_82 . V_83 & 1 ) {
V_72 -> V_78 ++ ;
V_82 . V_83 &= ~ 1 ;
}
if ( V_82 . V_83 & 2 ) {
V_72 -> V_76 = V_84 ;
V_82 . V_83 &= ~ 2 ;
}
F_40 () ;
}
V_70 -> V_74 = F_41 ( V_66 -> V_85 ) ;
V_70 -> V_86 = F_37 ( V_66 -> V_87 ) ;
V_70 -> type = F_37 ( V_88 ) ;
V_70 -> V_89 = F_37 ( V_66 -> V_90 * sizeof( V_91 ) ) ;
V_70 -> V_92 . V_66 . type = F_37 ( V_66 -> V_93 ) ;
V_70 -> V_92 . V_66 . V_94 = F_41 ( V_66 -> V_95 ) ;
V_46 = F_42 ( V_68 , V_70 , sizeof( * V_70 ) , F_43 () ) ;
if ( V_46 ) {
F_44 ( L_4 ,
V_46 , & V_3 -> V_96 , V_3 -> V_97 ) ;
goto V_98;
}
if ( ! V_66 -> V_90 )
goto V_98;
for ( V_73 = 0 ; V_73 < ( int ) V_66 -> V_90 ; V_73 ++ )
V_66 -> V_99 [ V_73 ] = F_45 ( V_66 -> V_99 [ V_73 ] ) ;
V_46 = F_42 ( V_68 , V_66 -> V_99 ,
V_66 -> V_90 * sizeof( V_91 ) ,
F_43 () ) ;
if ( V_46 ) {
F_44 ( L_5 ,
V_46 , V_66 -> V_90 ,
& V_3 -> V_96 , V_3 -> V_97 ) ;
}
V_98:
F_46 ( V_70 , sizeof( * V_70 ) ) ;
return V_46 ;
}
static int
F_47 ( struct V_2 * V_3 , struct V_65 * V_66 )
{
struct V_67 * V_68 = V_3 -> V_69 ;
int V_46 ;
V_66 -> V_100 = V_84 ;
V_66 -> V_101 = V_3 -> V_32 -> V_102 ;
if ( V_82 . V_83 ) {
F_39 () ;
if ( V_82 . V_83 & 1 ) {
V_66 -> V_101 ++ ;
V_82 . V_83 &= ~ 1 ;
}
F_40 () ;
}
V_46 = F_42 ( V_68 , V_66 , F_15 ( struct V_65 , V_99 ) ,
F_43 () ) ;
if ( V_46 ) {
F_44 ( L_4 ,
V_46 , & V_3 -> V_96 , V_3 -> V_97 ) ;
return V_46 ;
}
if ( ! V_66 -> V_90 )
return 0 ;
V_46 = F_42 ( V_68 , V_66 -> V_99 ,
V_66 -> V_90 * sizeof( V_91 ) ,
F_43 () ) ;
if ( V_46 ) {
F_44 ( L_5 ,
V_46 , V_66 -> V_90 ,
& V_3 -> V_96 , V_3 -> V_97 ) ;
}
return V_46 ;
}
static int
F_48 ( struct V_2 * V_3 , struct V_65 * V_66 ,
int V_103 )
{
struct V_67 * V_68 = V_3 -> V_69 ;
struct V_34 * V_70 ;
int V_46 ;
int V_73 ;
F_36 ( V_70 , sizeof( * V_70 ) ) ;
if ( ! V_70 ) {
F_16 ( L_3 ) ;
return - V_54 ;
}
V_46 = F_49 ( V_68 , & V_70 -> V_74 ,
sizeof( * V_70 ) - F_15 ( struct V_34 , V_74 ) ,
V_103 ) ;
if ( V_46 ) {
F_16 ( L_6 ,
V_46 , & V_3 -> V_96 ) ;
F_4 ( V_46 < 0 && V_46 != - V_104 ) ;
goto V_98;
}
if ( V_70 -> type != F_37 ( V_88 ) ) {
F_16 ( L_7 ,
F_50 ( V_70 -> type ) ,
& V_3 -> V_96 ) ;
V_46 = - V_62 ;
goto V_98;
}
V_66 -> V_85 = F_51 ( V_70 -> V_74 ) ;
V_66 -> V_87 = F_50 ( V_70 -> V_86 ) ;
V_66 -> V_95 = F_51 ( V_70 -> V_92 . V_66 . V_94 ) ;
V_66 -> V_93 = F_50 ( V_70 -> V_92 . V_66 . type ) ;
V_66 -> V_90 = F_50 ( V_70 -> V_89 ) /
sizeof( V_91 ) ;
if ( V_66 -> V_90 > V_105 ) {
F_16 ( L_8 ,
V_66 -> V_90 , & V_3 -> V_96 ) ;
V_46 = - V_62 ;
goto V_98;
}
if ( ! V_66 -> V_90 )
goto V_98;
V_46 = F_49 ( V_68 , V_66 -> V_99 ,
V_66 -> V_90 * sizeof( V_91 ) , V_103 ) ;
if ( V_46 ) {
F_16 ( L_9 ,
V_46 , & V_3 -> V_96 ) ;
F_4 ( V_46 < 0 && V_46 != - V_104 ) ;
goto V_98;
}
for ( V_73 = 0 ; V_73 < ( int ) V_66 -> V_90 ; V_73 ++ ) {
V_66 -> V_99 [ V_73 ] = F_52 ( V_66 -> V_99 [ V_73 ] ) ;
if ( ! V_66 -> V_99 [ V_73 ] ) {
F_16 ( L_10 ,
V_73 , & V_3 -> V_96 ) ;
V_46 = - V_62 ;
break;
}
}
V_98:
F_46 ( V_70 , sizeof( * V_70 ) ) ;
return V_46 ;
}
static int
F_53 ( struct V_2 * V_3 , struct V_65 * V_66 ,
int V_103 )
{
struct V_67 * V_68 = V_3 -> V_69 ;
int V_46 ;
int V_73 ;
if ( V_66 -> V_100 == V_84 )
V_3 -> V_106 = 0 ;
else
V_3 -> V_106 = 1 ;
V_46 = F_49 ( V_68 , & V_66 -> V_85 ,
F_15 ( struct V_65 , V_99 ) -
F_15 ( struct V_65 , V_85 ) ,
V_103 ) ;
if ( V_46 ) {
F_16 ( L_11 ,
V_46 , & V_3 -> V_96 ) ;
F_4 ( V_46 < 0 && V_46 != - V_104 ) ;
return V_46 ;
}
if ( V_3 -> V_106 ) {
F_54 ( & V_66 -> V_87 ) ;
F_55 ( & V_66 -> V_85 ) ;
F_54 ( & V_66 -> V_107 ) ;
F_55 ( & V_66 -> V_108 ) ;
F_55 ( & V_66 -> V_95 ) ;
F_55 ( & V_66 -> V_109 ) ;
F_54 ( & V_66 -> V_93 ) ;
F_54 ( & V_66 -> V_90 ) ;
}
if ( V_66 -> V_90 > V_105 ) {
F_16 ( L_8 ,
V_66 -> V_90 , & V_3 -> V_96 ) ;
return - V_62 ;
}
if ( ! V_66 -> V_90 )
return 0 ;
V_46 = F_49 ( V_68 , V_66 -> V_99 ,
V_66 -> V_90 * sizeof( V_91 ) , V_103 ) ;
if ( V_46 ) {
F_16 ( L_9 ,
V_46 , & V_3 -> V_96 ) ;
F_4 ( V_46 < 0 && V_46 != - V_104 ) ;
return V_46 ;
}
for ( V_73 = 0 ; V_73 < ( int ) V_66 -> V_90 ; V_73 ++ ) {
if ( V_3 -> V_106 )
F_54 ( & V_66 -> V_99 [ V_73 ] ) ;
if ( ! V_66 -> V_99 [ V_73 ] ) {
F_16 ( L_10 ,
V_73 , & V_3 -> V_96 ) ;
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
V_7 -> V_110 [ 0 ] . V_111 = & V_7 -> V_28 -> V_112 ;
V_7 -> V_110 [ 0 ] . V_113 = sizeof( struct V_34 ) ;
V_7 -> V_114 = V_7 -> V_28 -> V_31 + sizeof( struct V_34 ) ;
V_7 -> V_115 = V_7 -> V_28 -> V_31 + sizeof( struct V_34 ) ;
}
static void
F_57 ( struct V_1 * V_7 )
{
V_7 -> V_110 [ 0 ] . V_111 = & V_7 -> V_4 ;
if ( V_7 -> V_28 ) {
F_4 ( V_7 -> V_4 . V_10 != V_13 ) ;
V_7 -> V_4 . V_30 . V_116 . V_117 = V_7 -> V_28 -> V_112 ;
V_7 -> V_110 [ 0 ] . V_113 = sizeof( struct V_29 ) ;
V_7 -> V_114 = sizeof( struct V_29 ) + V_7 -> V_28 -> V_31 ;
V_7 -> V_115 = sizeof( struct V_29 ) + V_7 -> V_28 -> V_31 ;
} else {
F_4 ( V_7 -> V_4 . V_10 == V_13 ) ;
V_7 -> V_110 [ 0 ] . V_113 = F_15 ( struct V_29 , V_30 . V_116 . V_117 ) ;
V_7 -> V_114 = F_15 ( struct V_29 , V_30 . V_116 . V_117 ) ;
V_7 -> V_115 = F_15 ( struct V_29 , V_30 . V_116 . V_117 ) ;
}
}
static void
F_58 ( struct V_29 * V_92 )
{
V_92 -> V_118 = 0 ;
V_92 -> V_10 = V_14 ;
V_92 -> V_15 [ 0 ] = 0 ;
V_92 -> V_15 [ 1 ] = 0 ;
}
static void
F_59 ( struct V_29 * V_92 )
{
return;
}
