static T_1 *
F_1 ( T_2 * V_1 , T_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , & V_1 -> V_4 ) ;
return NULL ;
}
void
F_3 ( T_2 * V_1 )
{
T_1 * V_5 = V_1 -> V_6 ;
F_4 ( ! F_5 ( & V_1 -> V_4 ) ) ;
F_4 ( V_5 ) ;
if ( V_5 -> V_3 . V_7 == & V_1 -> V_4 ) {
V_1 -> V_6 = NULL ;
} else {
V_1 -> V_6 = F_6 ( V_5 , V_3 ) ;
F_4 ( V_1 -> V_6 -> V_2 . V_8 == V_5 -> V_2 . V_8 ) ;
}
}
static int
F_7 ( T_2 * V_1 ,
T_1 * V_9 , T_3 V_10 )
{
T_1 * V_5 = V_1 -> V_6 ;
F_4 ( ! V_9 ||
V_9 -> V_2 . V_8 == V_11 ) ;
if ( ! V_5 ) {
if ( V_9 ) {
F_2 ( & V_9 -> V_3 ,
& V_1 -> V_4 ) ;
V_1 -> V_6 = V_9 ;
}
return 0 ;
}
if ( V_5 -> V_2 . V_8 == V_11 ) {
if ( V_9 )
F_2 ( & V_9 -> V_3 ,
& V_1 -> V_4 ) ;
return 0 ;
}
F_4 ( V_5 -> V_2 . V_8 == V_12 ) ;
F_4 ( ! V_5 -> V_2 . V_13 [ 1 ] ) ;
if ( V_9 )
V_10 = V_9 -> V_2 . V_13 [ 1 ] ;
V_5 -> V_2 . V_13 [ 1 ] = V_10 ;
F_3 ( V_1 ) ;
return 1 ;
}
static T_1 *
F_8 ( T_2 * V_1 , T_1 * V_2 )
{
T_1 * V_5 = V_1 -> V_6 ;
if ( ! V_5 ) {
F_2 ( & V_2 -> V_3 , & V_1 -> V_4 ) ;
V_1 -> V_6 = V_2 ;
return NULL ;
}
if ( V_5 -> V_2 . V_8 == V_12 ) {
F_2 ( & V_2 -> V_3 , & V_1 -> V_4 ) ;
return NULL ;
}
F_4 ( V_5 -> V_2 . V_8 == V_11 ) ;
V_2 -> V_2 . V_13 [ 1 ] = V_5 -> V_2 . V_13 [ 1 ] ;
F_3 ( V_1 ) ;
F_9 ( & V_2 -> V_3 , & V_5 -> V_3 ) ;
F_10 ( & V_5 -> V_3 ) ;
return V_5 ;
}
static int
F_11 ( T_2 * V_1 ,
T_1 * V_9 , T_3 V_10 )
{
T_1 * V_5 ;
if ( V_1 -> V_14 != V_15 )
return F_7 ( V_1 , V_9 , V_10 ) ;
F_4 ( ! V_9 ||
V_9 -> V_2 . V_8 == V_11 ) ;
V_5 = V_1 -> V_6 ;
if ( ! V_5 ) {
if ( V_9 ) {
F_2 ( & V_9 -> V_3 ,
& V_1 -> V_4 ) ;
V_1 -> V_6 = V_9 ;
}
return 0 ;
}
if ( V_9 )
V_10 = V_9 -> V_2 . V_13 [ 1 ] ;
if ( V_10 == V_16 )
return 1 ;
if ( V_5 -> V_2 . V_13 [ 1 ] == V_16 ) {
F_4 ( ! V_5 -> V_2 . V_13 [ 0 ] ) ;
V_5 -> V_2 . V_13 [ 1 ] = V_10 ;
return 1 ;
}
if ( V_10 == V_5 -> V_2 . V_13 [ 0 ] ||
V_10 == V_5 -> V_2 . V_13 [ 1 ] ) {
F_12 ( L_1 ,
F_13 ( V_1 -> V_17 -> V_18 ) , V_10 ) ;
return 1 ;
}
if ( ! V_5 -> V_2 . V_13 [ 0 ] ) {
if ( V_5 -> V_2 . V_13 [ 1 ] > V_10 ) {
V_5 -> V_2 . V_13 [ 0 ] = V_5 -> V_2 . V_13 [ 1 ] ;
V_5 -> V_2 . V_13 [ 1 ] = V_10 ;
} else {
V_5 -> V_2 . V_13 [ 0 ] = V_10 ;
}
if ( V_5 -> V_2 . V_13 [ 0 ] - V_5 -> V_2 . V_13 [ 1 ] > 2 ) {
F_3 ( V_1 ) ;
}
return 1 ;
}
if ( V_5 -> V_2 . V_13 [ 0 ] > V_5 -> V_2 . V_13 [ 1 ] ) {
T_3 V_19 = 0 ;
F_4 ( V_5 -> V_2 . V_13 [ 0 ] -
V_5 -> V_2 . V_13 [ 1 ] <= 2 ) ;
if ( V_5 -> V_2 . V_13 [ 0 ] -
V_5 -> V_2 . V_13 [ 1 ] == 2 ) {
if ( V_10 == V_5 -> V_2 . V_13 [ 1 ] + 1 )
V_19 = V_10 ;
} else if ( V_10 == V_5 -> V_2 . V_13 [ 1 ] - 1 ) {
V_19 = V_5 -> V_2 . V_13 [ 1 ] ;
} else if ( V_10 == V_5 -> V_2 . V_13 [ 0 ] + 1 ) {
V_19 = V_5 -> V_2 . V_13 [ 0 ] ;
}
if ( V_19 ) {
V_5 -> V_2 . V_13 [ 0 ] = V_19 - 1 ;
V_5 -> V_2 . V_13 [ 1 ] = V_19 + 1 ;
return 1 ;
}
} else {
if ( V_10 >= V_5 -> V_2 . V_13 [ 0 ] &&
V_10 <= V_5 -> V_2 . V_13 [ 1 ] ) {
F_12 ( L_1 ,
F_13 ( V_1 -> V_17 -> V_18 ) , V_10 ) ;
return 1 ;
}
if ( V_10 == V_5 -> V_2 . V_13 [ 1 ] + 1 ) {
V_5 -> V_2 . V_13 [ 1 ] = V_10 ;
return 1 ;
}
if ( V_10 == V_5 -> V_2 . V_13 [ 0 ] - 1 ) {
V_5 -> V_2 . V_13 [ 0 ] = V_10 ;
return 1 ;
}
}
if ( V_9 ) {
F_2 ( & V_9 -> V_3 , & V_1 -> V_4 ) ;
F_3 ( V_1 ) ;
}
return 0 ;
}
static int
F_14 ( T_2 * V_1 , T_1 * V_5 , int V_20 )
{
int V_21 ;
#if V_22
if ( ! * V_23 . V_24 )
return V_25 ;
#endif
if ( ! V_5 || ! V_5 -> V_26 ) {
V_21 = F_15 ( V_27 , V_28 ) ;
} else {
V_21 = V_5 -> V_26 -> V_29 +
( ( V_1 -> V_30 == & V_31 ) ?
sizeof( V_32 ) : sizeof( V_27 ) ) ;
}
switch ( V_1 -> V_14 ) {
default:
F_16 ( L_2 , V_1 -> V_14 ) ;
F_17 () ;
case V_33 :
return V_25 ;
case V_34 :
return V_35 ;
case V_36 :
if ( V_21 < * V_23 . V_37 )
return V_35 ;
else
return V_25 ;
case V_38 :
if ( V_21 >= * V_23 . V_37 )
return V_35 ;
else
return V_25 ;
}
}
static int
F_18 ( T_2 * V_1 , T_1 * V_5 , int V_20 )
{
int V_21 ;
if ( ! V_5 || ! V_5 -> V_26 )
V_21 = F_15 ( V_27 , V_28 ) ;
else
V_21 = V_5 -> V_26 -> V_29 + sizeof( V_27 ) ;
switch ( V_1 -> V_14 ) {
default:
F_16 ( L_2 , V_1 -> V_14 ) ;
F_17 () ;
case V_33 :
return V_39 ;
case V_15 :
if ( V_20 )
return V_25 ;
else if ( ! V_5 || ! V_5 -> V_26 )
return V_35 ;
else
return V_39 ;
case V_36 :
if ( V_20 )
return V_39 ;
else if ( V_21 < * V_23 . V_37 )
return V_35 ;
else
return V_25 ;
case V_38 :
if ( V_20 )
return V_39 ;
else if ( V_21 >= * V_23 . V_37 )
return V_35 ;
else
return V_25 ;
}
}
static int
F_19 ( T_2 * V_40 , T_3 V_10 , int V_41 )
{
T_4 * V_42 = V_40 -> V_17 ;
T_2 * V_1 ;
T_1 * V_5 ;
int V_43 ;
F_20 ( & V_44 . V_45 ) ;
V_1 = F_21 ( V_42 , NULL , ! ! V_41 ) ;
if ( V_1 ) {
T_5 * V_46 = V_1 -> V_47 ;
F_4 ( V_1 -> V_30 -> V_48 ) ;
F_22 ( & V_46 -> V_49 ) ;
V_43 = V_1 -> V_30 -> V_48 ( V_1 , NULL , V_10 ) ;
F_23 ( & V_46 -> V_49 ) ;
if ( V_43 ) {
F_24 ( & V_44 . V_45 ) ;
return 0 ;
}
}
F_24 ( & V_44 . V_45 ) ;
V_5 = F_25 ( V_10 , ! ! V_41 ) ;
if ( ! V_5 )
return - V_50 ;
V_43 = F_26 ( V_42 -> V_51 , V_5 , V_42 -> V_18 ) ;
if ( ! V_43 )
return 0 ;
F_27 ( V_5 ) ;
return V_43 ;
}
static int
F_28 ( T_2 * V_1 , T_3 V_52 , T_3 V_53 )
{
T_4 * V_42 = V_1 -> V_17 ;
T_1 * V_5 ;
T_1 * V_54 ;
T_1 * V_19 ;
F_29 ( V_55 ) ;
int V_56 ;
if ( ! V_52 )
V_52 = V_53 ;
V_56 = ( V_52 > V_53 ) ? 2 : ( V_53 - V_52 + 1 ) ;
if ( V_53 == V_16 &&
V_1 -> V_30 == & V_57 ) {
return V_56 == 1 ? 0 : - V_58 ;
}
F_30 ( & V_42 -> V_59 ) ;
F_31 (tx, tmp, &peer->ksnp_zc_req_list,
tx_zc_list) {
T_3 V_40 = V_5 -> V_2 . V_13 [ 0 ] ;
if ( V_40 == V_52 || V_40 == V_53 || ( V_52 < V_40 && V_40 < V_53 ) ) {
V_5 -> V_2 . V_13 [ 0 ] = 0 ;
F_10 ( & V_5 -> V_60 ) ;
F_9 ( & V_5 -> V_60 , & V_55 ) ;
if ( ! -- V_56 )
break;
}
}
F_32 ( & V_42 -> V_59 ) ;
F_31 (tx, temp, &zlist, tx_zc_list) {
F_10 ( & V_5 -> V_60 ) ;
F_33 ( V_5 ) ;
}
return ! V_56 ? 0 : - V_58 ;
}
static int
F_34 ( T_2 * V_1 , T_6 * V_61 )
{
struct V_62 * V_63 = V_1 -> V_64 ;
V_32 * V_65 ;
T_7 * V_66 ;
int V_43 ;
int V_67 ;
F_35 ( sizeof( T_7 ) == F_15 ( V_32 , V_68 ) ) ;
F_36 ( V_65 , sizeof( * V_65 ) ) ;
if ( ! V_65 ) {
F_16 ( L_3 ) ;
return - V_50 ;
}
V_66 = ( T_7 * ) & V_65 -> V_69 ;
V_66 -> V_70 = F_37 ( V_71 ) ;
V_66 -> V_72 = F_38 ( V_73 ) ;
V_66 -> V_74 = F_38 ( V_75 ) ;
if ( V_76 . V_77 ) {
F_39 () ;
if ( V_76 . V_77 & 1 ) {
V_66 -> V_72 ++ ;
V_76 . V_77 &= ~ 1 ;
}
if ( V_76 . V_77 & 2 ) {
V_66 -> V_70 = V_78 ;
V_76 . V_77 &= ~ 2 ;
}
F_40 () ;
}
V_65 -> V_68 = F_41 ( V_61 -> V_79 ) ;
V_65 -> V_80 = F_37 ( V_61 -> V_81 ) ;
V_65 -> type = F_37 ( V_82 ) ;
V_65 -> V_83 = F_37 ( V_61 -> V_84 * sizeof( V_85 ) ) ;
V_65 -> V_86 . V_61 . type = F_37 ( V_61 -> V_87 ) ;
V_65 -> V_86 . V_61 . V_88 = F_41 ( V_61 -> V_89 ) ;
V_43 = F_42 ( V_63 , V_65 , sizeof( * V_65 ) , F_43 () ) ;
if ( V_43 ) {
F_44 ( L_4 ,
V_43 , & V_1 -> V_90 , V_1 -> V_91 ) ;
goto V_92;
}
if ( ! V_61 -> V_84 )
goto V_92;
for ( V_67 = 0 ; V_67 < ( int ) V_61 -> V_84 ; V_67 ++ )
V_61 -> V_93 [ V_67 ] = F_45 ( V_61 -> V_93 [ V_67 ] ) ;
V_43 = F_42 ( V_63 , V_61 -> V_93 ,
V_61 -> V_84 * sizeof( V_85 ) ,
F_43 () ) ;
if ( V_43 ) {
F_44 ( L_5 ,
V_43 , V_61 -> V_84 ,
& V_1 -> V_90 , V_1 -> V_91 ) ;
}
V_92:
F_46 ( V_65 , sizeof( * V_65 ) ) ;
return V_43 ;
}
static int
F_47 ( T_2 * V_1 , T_6 * V_61 )
{
struct V_62 * V_63 = V_1 -> V_64 ;
int V_43 ;
V_61 -> V_94 = V_78 ;
V_61 -> V_95 = V_1 -> V_30 -> V_96 ;
if ( V_76 . V_77 ) {
F_39 () ;
if ( V_76 . V_77 & 1 ) {
V_61 -> V_95 ++ ;
V_76 . V_77 &= ~ 1 ;
}
F_40 () ;
}
V_43 = F_42 ( V_63 , V_61 , F_15 ( T_6 , V_93 ) ,
F_43 () ) ;
if ( V_43 ) {
F_44 ( L_4 ,
V_43 , & V_1 -> V_90 , V_1 -> V_91 ) ;
return V_43 ;
}
if ( ! V_61 -> V_84 )
return 0 ;
V_43 = F_42 ( V_63 , V_61 -> V_93 ,
V_61 -> V_84 * sizeof( V_85 ) ,
F_43 () ) ;
if ( V_43 ) {
F_44 ( L_5 ,
V_43 , V_61 -> V_84 ,
& V_1 -> V_90 , V_1 -> V_91 ) ;
}
return V_43 ;
}
static int
F_48 ( T_2 * V_1 , T_6 * V_61 ,
int V_97 )
{
struct V_62 * V_63 = V_1 -> V_64 ;
V_32 * V_65 ;
int V_43 ;
int V_67 ;
F_36 ( V_65 , sizeof( * V_65 ) ) ;
if ( ! V_65 ) {
F_16 ( L_3 ) ;
return - V_50 ;
}
V_43 = F_49 ( V_63 , & V_65 -> V_68 ,
sizeof( * V_65 ) - F_15 ( V_32 , V_68 ) ,
V_97 ) ;
if ( V_43 ) {
F_16 ( L_6 ,
V_43 , & V_1 -> V_90 ) ;
F_4 ( V_43 < 0 && V_43 != - V_98 ) ;
goto V_92;
}
if ( V_65 -> type != F_37 ( V_82 ) ) {
F_16 ( L_7 ,
F_50 ( V_65 -> type ) ,
& V_1 -> V_90 ) ;
V_43 = - V_58 ;
goto V_92;
}
V_61 -> V_79 = F_51 ( V_65 -> V_68 ) ;
V_61 -> V_81 = F_50 ( V_65 -> V_80 ) ;
V_61 -> V_89 = F_51 ( V_65 -> V_86 . V_61 . V_88 ) ;
V_61 -> V_87 = F_50 ( V_65 -> V_86 . V_61 . type ) ;
V_61 -> V_84 = F_50 ( V_65 -> V_83 ) /
sizeof( V_85 ) ;
if ( V_61 -> V_84 > V_99 ) {
F_16 ( L_8 ,
V_61 -> V_84 , & V_1 -> V_90 ) ;
V_43 = - V_58 ;
goto V_92;
}
if ( ! V_61 -> V_84 )
goto V_92;
V_43 = F_49 ( V_63 , V_61 -> V_93 ,
V_61 -> V_84 * sizeof( V_85 ) , V_97 ) ;
if ( V_43 ) {
F_16 ( L_9 ,
V_43 , & V_1 -> V_90 ) ;
F_4 ( V_43 < 0 && V_43 != - V_98 ) ;
goto V_92;
}
for ( V_67 = 0 ; V_67 < ( int ) V_61 -> V_84 ; V_67 ++ ) {
V_61 -> V_93 [ V_67 ] = F_52 ( V_61 -> V_93 [ V_67 ] ) ;
if ( ! V_61 -> V_93 [ V_67 ] ) {
F_16 ( L_10 ,
V_67 , & V_1 -> V_90 ) ;
V_43 = - V_58 ;
break;
}
}
V_92:
F_46 ( V_65 , sizeof( * V_65 ) ) ;
return V_43 ;
}
static int
F_53 ( T_2 * V_1 , T_6 * V_61 , int V_97 )
{
struct V_62 * V_63 = V_1 -> V_64 ;
int V_43 ;
int V_67 ;
if ( V_61 -> V_94 == V_78 )
V_1 -> V_100 = 0 ;
else
V_1 -> V_100 = 1 ;
V_43 = F_49 ( V_63 , & V_61 -> V_79 ,
F_15 ( T_6 , V_93 ) -
F_15 ( T_6 , V_79 ) ,
V_97 ) ;
if ( V_43 ) {
F_16 ( L_11 ,
V_43 , & V_1 -> V_90 ) ;
F_4 ( V_43 < 0 && V_43 != - V_98 ) ;
return V_43 ;
}
if ( V_1 -> V_100 ) {
F_54 ( & V_61 -> V_81 ) ;
F_55 ( & V_61 -> V_79 ) ;
F_54 ( & V_61 -> V_101 ) ;
F_55 ( & V_61 -> V_102 ) ;
F_55 ( & V_61 -> V_89 ) ;
F_55 ( & V_61 -> V_103 ) ;
F_54 ( & V_61 -> V_87 ) ;
F_54 ( & V_61 -> V_84 ) ;
}
if ( V_61 -> V_84 > V_99 ) {
F_16 ( L_8 ,
V_61 -> V_84 , & V_1 -> V_90 ) ;
return - V_58 ;
}
if ( ! V_61 -> V_84 )
return 0 ;
V_43 = F_49 ( V_63 , V_61 -> V_93 ,
V_61 -> V_84 * sizeof( V_85 ) , V_97 ) ;
if ( V_43 ) {
F_16 ( L_9 ,
V_43 , & V_1 -> V_90 ) ;
F_4 ( V_43 < 0 && V_43 != - V_98 ) ;
return V_43 ;
}
for ( V_67 = 0 ; V_67 < ( int ) V_61 -> V_84 ; V_67 ++ ) {
if ( V_1 -> V_100 )
F_54 ( & V_61 -> V_93 [ V_67 ] ) ;
if ( ! V_61 -> V_93 [ V_67 ] ) {
F_16 ( L_10 ,
V_67 , & V_1 -> V_90 ) ;
return - V_58 ;
}
}
return 0 ;
}
static void
F_56 ( T_1 * V_5 )
{
F_4 ( V_5 -> V_2 . V_8 != V_11 ) ;
F_4 ( V_5 -> V_26 ) ;
V_5 -> V_104 [ 0 ] . V_105 = & V_5 -> V_26 -> V_106 ;
V_5 -> V_104 [ 0 ] . V_107 = sizeof( V_32 ) ;
V_5 -> V_108 = V_5 -> V_26 -> V_29 + sizeof( V_32 ) ;
V_5 -> V_109 = V_5 -> V_26 -> V_29 + sizeof( V_32 ) ;
}
static void
F_57 ( T_1 * V_5 )
{
V_5 -> V_104 [ 0 ] . V_105 = & V_5 -> V_2 ;
if ( V_5 -> V_26 ) {
F_4 ( V_5 -> V_2 . V_8 != V_11 ) ;
V_5 -> V_2 . V_28 . V_110 . V_111 = V_5 -> V_26 -> V_106 ;
V_5 -> V_104 [ 0 ] . V_107 = sizeof( V_27 ) ;
V_5 -> V_108 = sizeof( V_27 ) + V_5 -> V_26 -> V_29 ;
V_5 -> V_109 = sizeof( V_27 ) + V_5 -> V_26 -> V_29 ;
} else {
F_4 ( V_5 -> V_2 . V_8 == V_11 ) ;
V_5 -> V_104 [ 0 ] . V_107 = F_15 ( V_27 , V_28 . V_110 . V_111 ) ;
V_5 -> V_108 = F_15 ( V_27 , V_28 . V_110 . V_111 ) ;
V_5 -> V_109 = F_15 ( V_27 , V_28 . V_110 . V_111 ) ;
}
}
static void
F_58 ( V_27 * V_86 )
{
V_86 -> V_112 = 0 ;
V_86 -> V_8 = V_12 ;
V_86 -> V_13 [ 0 ] = 0 ;
V_86 -> V_13 [ 1 ] = 0 ;
}
static void
F_59 ( V_27 * V_86 )
{
return;
}
