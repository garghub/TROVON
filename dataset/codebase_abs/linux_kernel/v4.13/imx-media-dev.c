static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
struct V_5 *
F_3 ( struct V_1 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 )
{
struct V_10 * V_11 = V_8 ? F_4 ( V_8 ) : NULL ;
struct V_5 * V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_4 . V_14 ; V_13 ++ ) {
V_12 = & V_6 -> V_15 [ V_13 ] ;
switch ( V_12 -> V_16 . V_17 ) {
case V_18 :
if ( V_11 && V_12 -> V_16 . V_19 . V_11 . V_11 == V_11 )
return V_12 ;
break;
case V_20 :
if ( V_9 &&
! strcmp ( V_12 -> V_16 . V_19 . V_21 . V_22 , V_9 ) )
return V_12 ;
break;
default:
break;
}
}
return NULL ;
}
struct V_5 *
F_5 ( struct V_1 * V_6 ,
struct V_7 * V_8 ,
struct V_23 * V_24 )
{
struct V_5 * V_12 ;
struct V_25 * V_16 ;
const char * V_9 = NULL ;
int V_26 ;
F_6 ( & V_6 -> V_27 ) ;
if ( V_24 )
V_9 = F_7 ( & V_24 -> V_28 ) ;
if ( F_3 ( V_6 , V_8 , V_9 ) ) {
F_8 ( V_6 -> V_29 . V_28 , L_1 ,
V_30 , V_8 ? V_8 -> V_22 : V_9 ) ;
V_12 = NULL ;
goto V_31;
}
V_26 = V_6 -> V_4 . V_14 ;
if ( V_26 >= V_32 ) {
F_9 ( V_6 -> V_29 . V_28 , L_2 ,
V_30 , V_8 ? V_8 -> V_22 : V_9 ) ;
V_12 = F_10 ( - V_33 ) ;
goto V_31;
}
V_12 = & V_6 -> V_15 [ V_26 ] ;
V_16 = & V_12 -> V_16 ;
if ( V_8 ) {
V_16 -> V_17 = V_18 ;
V_16 -> V_19 . V_11 . V_11 = F_4 ( V_8 ) ;
} else {
V_16 -> V_17 = V_20 ;
strncpy ( V_12 -> V_9 , V_9 , sizeof( V_12 -> V_9 ) ) ;
V_16 -> V_19 . V_21 . V_22 = V_12 -> V_9 ;
V_12 -> V_24 = V_24 ;
}
V_6 -> V_34 [ V_26 ] = V_16 ;
V_6 -> V_4 . V_14 ++ ;
F_8 ( V_6 -> V_29 . V_28 , L_3 ,
V_30 , V_8 ? V_8 -> V_22 : V_9 , V_8 ? L_4 : L_5 ) ;
V_31:
F_11 ( & V_6 -> V_27 ) ;
return V_12 ;
}
int F_12 ( struct V_1 * V_6 ,
struct V_35 * V_36 ,
struct V_7 * V_37 ,
const char * V_38 ,
int V_39 , int V_40 )
{
struct V_41 * V_42 ;
int V_43 , V_44 = 0 ;
F_6 ( & V_6 -> V_27 ) ;
V_43 = V_36 -> V_45 ;
if ( V_43 >= V_46 ) {
F_9 ( V_6 -> V_29 . V_28 , L_6 , V_30 ) ;
V_44 = - V_33 ;
goto V_31;
}
V_42 = & V_36 -> V_42 [ V_43 ] ;
V_42 -> V_47 = V_37 ;
if ( V_38 )
strncpy ( V_42 -> V_38 , V_38 ,
sizeof( V_42 -> V_38 ) ) ;
V_42 -> V_39 = V_39 ;
V_42 -> V_40 = V_40 ;
V_36 -> V_45 ++ ;
V_31:
F_11 ( & V_6 -> V_27 ) ;
return V_44 ;
}
static int F_13 ( struct V_1 * V_6 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
int V_52 ;
V_51 = F_14 ( V_49 -> V_28 -> V_53 ) ;
if ( ! V_51 ) {
F_15 ( & V_6 -> V_54 ,
L_7 , V_49 -> V_22 ) ;
return - V_55 ;
}
V_52 = F_16 ( V_51 ) ;
if ( V_52 > 1 ) {
F_15 ( & V_6 -> V_54 , L_8 , V_52 ) ;
return - V_55 ;
}
if ( ! V_6 -> V_51 [ V_52 ] )
V_6 -> V_51 [ V_52 ] = V_51 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_56 ,
struct V_48 * V_57 ,
struct V_25 * V_16 )
{
struct V_1 * V_6 = F_1 ( V_56 ) ;
struct V_7 * V_8 = F_18 ( V_57 -> V_11 ) ;
struct V_5 * V_12 ;
int V_44 = 0 ;
F_6 ( & V_6 -> V_27 ) ;
V_12 = F_3 ( V_6 , V_8 , F_7 ( V_57 -> V_28 ) ) ;
if ( ! V_12 ) {
V_44 = - V_58 ;
goto V_31;
}
if ( V_57 -> V_59 & V_60 ) {
V_44 = F_13 ( V_6 , V_57 ) ;
if ( V_44 )
goto V_61;
} else if ( V_57 -> V_62 . V_63 == V_64 ) {
V_57 -> V_59 = V_65 ;
} else if ( V_12 -> V_66 == 0 ) {
V_57 -> V_59 = V_67 ;
}
V_12 -> V_57 = V_57 ;
V_31:
if ( V_44 )
F_19 ( & V_6 -> V_54 ,
L_9 , V_57 -> V_22 ) ;
else
F_20 ( & V_6 -> V_54 ,
L_10 , V_57 -> V_22 ) ;
V_61:
F_11 ( & V_6 -> V_27 ) ;
return V_44 ;
}
static int F_21 ( struct V_1 * V_6 ,
struct V_5 * V_68 ,
struct V_41 * V_42 )
{
struct V_5 * V_69 ;
T_1 V_70 , V_71 ;
int V_44 ;
V_69 = F_3 ( V_6 , V_42 -> V_47 ,
V_42 -> V_38 ) ;
if ( ! V_69 ) {
F_19 ( & V_6 -> V_54 , L_11 ,
V_30 , V_68 -> V_57 -> V_22 , V_42 -> V_39 ) ;
return 0 ;
}
V_70 = V_42 -> V_39 ;
V_71 = V_42 -> V_40 ;
F_20 ( & V_6 -> V_54 , L_12 , V_30 ,
V_68 -> V_57 -> V_22 , V_70 , V_69 -> V_57 -> V_22 , V_71 ) ;
V_44 = F_22 ( & V_68 -> V_57 -> V_62 , V_70 ,
& V_69 -> V_57 -> V_62 , V_71 , 0 ) ;
if ( V_44 )
F_15 ( & V_6 -> V_54 ,
L_13 , V_44 ) ;
return V_44 ;
}
static int F_23 ( struct V_1 * V_6 )
{
struct V_5 * V_12 ;
struct V_41 * V_42 ;
struct V_35 * V_36 ;
int V_72 , V_13 , V_73 , V_74 ;
int V_44 = 0 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ ) {
V_12 = & V_6 -> V_15 [ V_13 ] ;
V_72 = V_12 -> V_66 + V_12 -> V_75 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
V_36 = & V_12 -> V_36 [ V_73 ] ;
if ( ! ( V_36 -> V_36 . V_76 & V_77 ) )
continue;
for ( V_74 = 0 ; V_74 < V_36 -> V_45 ; V_74 ++ ) {
V_42 = & V_36 -> V_42 [ V_74 ] ;
V_44 = F_21 ( V_6 , V_12 , V_42 ) ;
if ( V_44 )
goto V_31;
}
}
}
V_31:
return V_44 ;
}
static int F_24 ( struct V_1 * V_6 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_82 * V_62 = V_81 -> V_62 ;
struct V_5 * V_12 ;
struct V_35 * V_83 ;
struct V_84 * V_42 ;
struct V_48 * V_57 ;
int V_13 , V_85 , V_44 ;
if ( ! F_25 ( V_62 ) )
return 0 ;
V_57 = F_26 ( V_62 ) ;
V_12 = F_27 ( V_6 , V_57 ) ;
if ( F_28 ( V_12 ) )
return F_29 ( V_12 ) ;
V_83 = & V_12 -> V_36 [ V_81 -> V_86 ] ;
V_85 = V_83 -> V_87 ;
for ( V_13 = 0 ; V_13 < V_85 ; V_13 ++ )
if ( V_79 == V_83 -> V_79 [ V_13 ] )
return 0 ;
if ( V_85 >= V_88 ) {
F_9 ( V_6 -> V_29 . V_28 , L_14 ,
V_79 -> V_89 -> V_62 . V_22 , V_62 -> V_22 , V_81 -> V_86 ) ;
return - V_33 ;
}
F_8 ( V_6 -> V_29 . V_28 , L_15 ,
V_79 -> V_89 -> V_62 . V_22 , V_62 -> V_22 , V_81 -> V_86 ) ;
V_83 -> V_79 [ V_85 ] = V_79 ;
V_83 -> V_87 ++ ;
for ( V_13 = 0 ; V_13 < V_62 -> V_72 ; V_13 ++ ) {
struct V_80 * V_36 = & V_62 -> V_90 [ V_13 ] ;
if ( ! ( V_36 -> V_76 & V_91 ) )
continue;
F_30 (link, &entity->links, list) {
if ( V_42 -> V_69 != V_36 )
continue;
V_44 = F_24 ( V_6 , V_79 ,
V_42 -> V_92 ) ;
if ( V_44 )
return V_44 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_6 )
{
struct V_78 * V_79 ;
struct V_84 * V_42 ;
int V_13 , V_44 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_87 ; V_13 ++ ) {
V_79 = V_6 -> V_79 [ V_13 ] ;
V_42 = F_32 ( & V_79 -> V_89 -> V_62 . V_93 ,
struct V_84 , V_94 ) ;
V_44 = F_24 ( V_6 , V_79 , V_42 -> V_92 ) ;
if ( V_44 )
break;
}
return V_44 ;
}
static int F_33 ( struct V_2 * V_56 )
{
struct V_1 * V_6 = F_1 ( V_56 ) ;
int V_13 , V_44 ;
F_6 ( & V_6 -> V_27 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ ) {
if ( ! V_6 -> V_15 [ V_13 ] . V_57 ) {
F_15 ( & V_6 -> V_54 , L_16 ) ;
V_44 = - V_55 ;
goto V_95;
}
}
V_44 = F_23 ( V_6 ) ;
if ( V_44 )
goto V_95;
V_44 = F_31 ( V_6 ) ;
if ( V_44 )
goto V_95;
V_44 = F_34 ( & V_6 -> V_54 ) ;
V_95:
F_11 ( & V_6 -> V_27 ) ;
if ( V_44 )
return V_44 ;
return F_35 ( & V_6 -> V_29 ) ;
}
static int F_36 ( struct V_1 * V_6 ,
struct V_96 * V_89 ,
struct V_82 * V_62 )
{
int V_13 , V_44 = 0 ;
if ( F_25 ( V_62 ) ) {
struct V_48 * V_57 = F_26 ( V_62 ) ;
F_8 ( V_6 -> V_29 . V_28 ,
L_17 ,
V_89 -> V_62 . V_22 , V_57 -> V_62 . V_22 ) ;
V_44 = F_37 ( V_89 -> V_97 ,
V_57 -> V_97 ,
NULL ) ;
if ( V_44 )
return V_44 ;
}
for ( V_13 = 0 ; V_13 < V_62 -> V_72 ; V_13 ++ ) {
struct V_80 * V_36 , * V_98 = & V_62 -> V_90 [ V_13 ] ;
if ( ! ( V_98 -> V_76 & V_91 ) )
continue;
V_36 = F_38 ( V_98 ) ;
if ( ! V_36 || ! F_25 ( V_36 -> V_62 ) )
continue;
V_44 = F_36 ( V_6 , V_89 , V_36 -> V_62 ) ;
if ( V_44 )
break;
}
return V_44 ;
}
static int F_39 ( struct V_84 * V_42 , T_2 V_76 ,
unsigned int V_99 )
{
struct V_82 * V_92 = V_42 -> V_92 -> V_62 ;
struct V_5 * V_12 ;
struct V_35 * V_83 ;
struct V_1 * V_6 ;
struct V_96 * V_89 ;
struct V_48 * V_57 ;
int V_13 , V_100 , V_44 ;
V_44 = F_40 ( V_42 , V_76 , V_99 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_25 ( V_92 ) )
return 0 ;
V_57 = F_26 ( V_92 ) ;
V_100 = V_42 -> V_92 -> V_86 ;
V_6 = F_14 ( V_57 -> V_54 -> V_28 ) ;
V_12 = F_27 ( V_6 , V_57 ) ;
if ( F_28 ( V_12 ) )
return F_29 ( V_12 ) ;
V_83 = & V_12 -> V_36 [ V_100 ] ;
if ( V_99 == V_101 &&
! ( V_76 & V_102 ) ) {
for ( V_13 = 0 ; V_13 < V_83 -> V_87 ; V_13 ++ ) {
V_89 = V_83 -> V_79 [ V_13 ] -> V_89 ;
F_8 ( V_6 -> V_29 . V_28 ,
L_18 ,
V_89 -> V_62 . V_22 ) ;
F_41 ( V_89 -> V_97 ) ;
F_42 ( V_89 -> V_97 , 0 ) ;
}
} else if ( V_99 == V_103 &&
( V_42 -> V_76 & V_102 ) ) {
for ( V_13 = 0 ; V_13 < V_83 -> V_87 ; V_13 ++ ) {
V_89 = V_83 -> V_79 [ V_13 ] -> V_89 ;
F_8 ( V_6 -> V_29 . V_28 ,
L_19 ,
V_89 -> V_62 . V_22 ) ;
V_44 = F_36 ( V_6 , V_89 ,
& V_89 -> V_62 ) ;
if ( V_44 )
break;
}
}
return V_44 ;
}
static int F_43 ( struct V_23 * V_24 )
{
struct V_104 * V_28 = & V_24 -> V_28 ;
struct V_7 * V_105 = V_28 -> V_106 ;
struct V_5 * V_107 [ 4 ] = { 0 } ;
struct V_1 * V_6 ;
int V_44 ;
V_6 = F_44 ( V_28 , sizeof( * V_6 ) , V_108 ) ;
if ( ! V_6 )
return - V_109 ;
F_45 ( V_28 , V_6 ) ;
F_46 ( V_6 -> V_29 . V_110 , L_20 , sizeof( V_6 -> V_29 . V_110 ) ) ;
V_6 -> V_29 . V_111 = & V_112 ;
V_6 -> V_29 . V_28 = V_28 ;
F_47 ( & V_6 -> V_27 ) ;
V_6 -> V_54 . V_113 = & V_6 -> V_29 ;
F_46 ( V_6 -> V_54 . V_22 , L_20 ,
sizeof( V_6 -> V_54 . V_22 ) ) ;
F_48 ( & V_6 -> V_29 ) ;
V_44 = F_49 ( V_28 , & V_6 -> V_54 ) ;
if ( V_44 < 0 ) {
F_15 ( & V_6 -> V_54 ,
L_21 , V_44 ) ;
goto V_114;
}
F_45 ( V_6 -> V_54 . V_28 , V_6 ) ;
V_44 = F_50 ( V_6 , & V_107 , V_105 ) ;
if ( V_44 ) {
F_15 ( & V_6 -> V_54 ,
L_22 , V_44 ) ;
goto V_115;
}
V_44 = F_51 ( V_6 , V_107 ) ;
if ( V_44 ) {
F_15 ( & V_6 -> V_54 ,
L_23 , V_44 ) ;
goto V_115;
}
V_6 -> V_14 = V_6 -> V_4 . V_14 ;
if ( V_6 -> V_14 == 0 ) {
V_44 = - V_55 ;
goto V_115;
}
V_6 -> V_4 . V_116 = V_6 -> V_34 ;
V_6 -> V_4 . V_117 = F_17 ;
V_6 -> V_4 . V_118 = F_33 ;
V_44 = F_52 ( & V_6 -> V_54 ,
& V_6 -> V_4 ) ;
if ( V_44 ) {
F_15 ( & V_6 -> V_54 ,
L_24 , V_44 ) ;
goto V_119;
}
return 0 ;
V_119:
F_53 ( V_6 ) ;
V_115:
F_54 ( & V_6 -> V_54 ) ;
V_114:
F_55 ( & V_6 -> V_29 ) ;
return V_44 ;
}
static int F_56 ( struct V_23 * V_24 )
{
struct V_1 * V_6 =
(struct V_1 * ) F_57 ( V_24 ) ;
F_20 ( & V_6 -> V_54 , L_25 ) ;
F_58 ( & V_6 -> V_4 ) ;
F_53 ( V_6 ) ;
F_54 ( & V_6 -> V_54 ) ;
F_59 ( & V_6 -> V_29 ) ;
F_55 ( & V_6 -> V_29 ) ;
return 0 ;
}
