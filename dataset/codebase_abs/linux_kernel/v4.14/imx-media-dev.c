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
V_12 = F_9 ( - V_31 ) ;
goto V_32;
}
V_26 = V_6 -> V_4 . V_14 ;
if ( V_26 >= V_33 ) {
F_10 ( V_6 -> V_29 . V_28 , L_2 ,
V_30 , V_8 ? V_8 -> V_22 : V_9 ) ;
V_12 = F_9 ( - V_34 ) ;
goto V_32;
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
V_6 -> V_35 [ V_26 ] = V_16 ;
V_6 -> V_4 . V_14 ++ ;
F_8 ( V_6 -> V_29 . V_28 , L_3 ,
V_30 , V_8 ? V_8 -> V_22 : V_9 , V_8 ? L_4 : L_5 ) ;
V_32:
F_11 ( & V_6 -> V_27 ) ;
return V_12 ;
}
int F_12 ( struct V_1 * V_6 ,
struct V_36 * V_37 ,
struct V_7 * V_38 ,
const char * V_39 ,
int V_40 , int V_41 )
{
struct V_42 * V_43 ;
int V_44 , V_45 = 0 ;
F_6 ( & V_6 -> V_27 ) ;
V_44 = V_37 -> V_46 ;
if ( V_44 >= V_47 ) {
F_10 ( V_6 -> V_29 . V_28 , L_6 , V_30 ) ;
V_45 = - V_34 ;
goto V_32;
}
V_43 = & V_37 -> V_43 [ V_44 ] ;
V_43 -> V_48 = V_38 ;
if ( V_39 )
strncpy ( V_43 -> V_39 , V_39 ,
sizeof( V_43 -> V_39 ) ) ;
V_43 -> V_40 = V_40 ;
V_43 -> V_41 = V_41 ;
V_37 -> V_46 ++ ;
V_32:
F_11 ( & V_6 -> V_27 ) ;
return V_45 ;
}
static int F_13 ( struct V_1 * V_6 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 ;
int V_53 ;
V_52 = F_14 ( V_50 -> V_28 -> V_54 ) ;
if ( ! V_52 ) {
F_15 ( & V_6 -> V_55 ,
L_7 , V_50 -> V_22 ) ;
return - V_56 ;
}
V_53 = F_16 ( V_52 ) ;
if ( V_53 > 1 ) {
F_15 ( & V_6 -> V_55 , L_8 , V_53 ) ;
return - V_56 ;
}
if ( ! V_6 -> V_52 [ V_53 ] )
V_6 -> V_52 [ V_53 ] = V_52 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_57 ,
struct V_49 * V_58 ,
struct V_25 * V_16 )
{
struct V_1 * V_6 = F_1 ( V_57 ) ;
struct V_7 * V_8 = F_18 ( V_58 -> V_11 ) ;
struct V_5 * V_12 ;
int V_45 = 0 ;
F_6 ( & V_6 -> V_27 ) ;
V_12 = F_3 ( V_6 , V_8 , F_7 ( V_58 -> V_28 ) ) ;
if ( ! V_12 ) {
V_45 = - V_59 ;
goto V_32;
}
if ( V_58 -> V_60 & V_61 ) {
V_45 = F_13 ( V_6 , V_58 ) ;
if ( V_45 )
goto V_62;
} else if ( V_58 -> V_63 . V_64 == V_65 ) {
V_58 -> V_60 = V_66 ;
} else if ( V_12 -> V_67 == 0 ) {
V_58 -> V_60 = V_68 ;
}
V_12 -> V_58 = V_58 ;
V_32:
if ( V_45 )
F_19 ( & V_6 -> V_55 ,
L_9 , V_58 -> V_22 ) ;
else
F_20 ( & V_6 -> V_55 ,
L_10 , V_58 -> V_22 ) ;
V_62:
F_11 ( & V_6 -> V_27 ) ;
return V_45 ;
}
static int F_21 ( struct V_1 * V_6 ,
struct V_5 * V_69 ,
struct V_42 * V_43 )
{
struct V_5 * V_70 ;
T_1 V_71 , V_72 ;
int V_45 ;
V_70 = F_3 ( V_6 , V_43 -> V_48 ,
V_43 -> V_39 ) ;
if ( ! V_70 ) {
F_19 ( & V_6 -> V_55 , L_11 ,
V_30 , V_69 -> V_58 -> V_22 , V_43 -> V_40 ) ;
return 0 ;
}
V_71 = V_43 -> V_40 ;
V_72 = V_43 -> V_41 ;
F_20 ( & V_6 -> V_55 , L_12 , V_30 ,
V_69 -> V_58 -> V_22 , V_71 , V_70 -> V_58 -> V_22 , V_72 ) ;
V_45 = F_22 ( & V_69 -> V_58 -> V_63 , V_71 ,
& V_70 -> V_58 -> V_63 , V_72 , 0 ) ;
if ( V_45 )
F_15 ( & V_6 -> V_55 ,
L_13 , V_45 ) ;
return V_45 ;
}
static int F_23 ( struct V_1 * V_6 )
{
struct V_5 * V_12 ;
struct V_42 * V_43 ;
struct V_36 * V_37 ;
int V_73 , V_13 , V_74 , V_75 ;
int V_45 = 0 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ ) {
V_12 = & V_6 -> V_15 [ V_13 ] ;
V_73 = V_12 -> V_67 + V_12 -> V_76 ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
V_37 = & V_12 -> V_37 [ V_74 ] ;
if ( ! ( V_37 -> V_37 . V_77 & V_78 ) )
continue;
for ( V_75 = 0 ; V_75 < V_37 -> V_46 ; V_75 ++ ) {
V_43 = & V_37 -> V_43 [ V_75 ] ;
V_45 = F_21 ( V_6 , V_12 , V_43 ) ;
if ( V_45 )
goto V_32;
}
}
}
V_32:
return V_45 ;
}
static int F_24 ( struct V_1 * V_6 ,
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
struct V_83 * V_63 = V_82 -> V_63 ;
struct V_5 * V_12 ;
struct V_36 * V_84 ;
struct V_85 * V_43 ;
struct V_49 * V_58 ;
int V_13 , V_86 , V_45 ;
if ( ! F_25 ( V_63 ) )
return 0 ;
V_58 = F_26 ( V_63 ) ;
V_12 = F_27 ( V_6 , V_58 ) ;
if ( F_28 ( V_12 ) )
return F_29 ( V_12 ) ;
V_84 = & V_12 -> V_37 [ V_82 -> V_87 ] ;
V_86 = V_84 -> V_88 ;
for ( V_13 = 0 ; V_13 < V_86 ; V_13 ++ )
if ( V_80 == V_84 -> V_80 [ V_13 ] )
return 0 ;
if ( V_86 >= V_89 ) {
F_10 ( V_6 -> V_29 . V_28 , L_14 ,
V_80 -> V_90 -> V_63 . V_22 , V_63 -> V_22 , V_82 -> V_87 ) ;
return - V_34 ;
}
F_8 ( V_6 -> V_29 . V_28 , L_15 ,
V_80 -> V_90 -> V_63 . V_22 , V_63 -> V_22 , V_82 -> V_87 ) ;
V_84 -> V_80 [ V_86 ] = V_80 ;
V_84 -> V_88 ++ ;
for ( V_13 = 0 ; V_13 < V_63 -> V_73 ; V_13 ++ ) {
struct V_81 * V_37 = & V_63 -> V_91 [ V_13 ] ;
if ( ! ( V_37 -> V_77 & V_92 ) )
continue;
F_30 (link, &entity->links, list) {
if ( V_43 -> V_70 != V_37 )
continue;
V_45 = F_24 ( V_6 , V_80 ,
V_43 -> V_93 ) ;
if ( V_45 )
return V_45 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_6 )
{
struct V_79 * V_80 ;
struct V_85 * V_43 ;
int V_13 , V_45 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_88 ; V_13 ++ ) {
V_80 = V_6 -> V_80 [ V_13 ] ;
V_43 = F_32 ( & V_80 -> V_90 -> V_63 . V_94 ,
struct V_85 , V_95 ) ;
V_45 = F_24 ( V_6 , V_80 , V_43 -> V_93 ) ;
if ( V_45 )
return V_45 ;
}
return 0 ;
}
static int F_33 ( struct V_2 * V_57 )
{
struct V_1 * V_6 = F_1 ( V_57 ) ;
int V_13 , V_45 ;
F_6 ( & V_6 -> V_27 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ ) {
if ( ! V_6 -> V_15 [ V_13 ] . V_58 ) {
F_15 ( & V_6 -> V_55 , L_16 ) ;
V_45 = - V_56 ;
goto V_96;
}
}
V_45 = F_23 ( V_6 ) ;
if ( V_45 )
goto V_96;
V_45 = F_31 ( V_6 ) ;
if ( V_45 )
goto V_96;
V_45 = F_34 ( & V_6 -> V_55 ) ;
V_96:
F_11 ( & V_6 -> V_27 ) ;
if ( V_45 )
return V_45 ;
return F_35 ( & V_6 -> V_29 ) ;
}
static int F_36 ( struct V_1 * V_6 ,
struct V_97 * V_90 ,
struct V_83 * V_63 )
{
int V_13 , V_45 = 0 ;
if ( F_25 ( V_63 ) ) {
struct V_49 * V_58 = F_26 ( V_63 ) ;
F_8 ( V_6 -> V_29 . V_28 ,
L_17 ,
V_90 -> V_63 . V_22 , V_58 -> V_63 . V_22 ) ;
V_45 = F_37 ( V_90 -> V_98 ,
V_58 -> V_98 ,
NULL ) ;
if ( V_45 )
return V_45 ;
}
for ( V_13 = 0 ; V_13 < V_63 -> V_73 ; V_13 ++ ) {
struct V_81 * V_37 , * V_99 = & V_63 -> V_91 [ V_13 ] ;
if ( ! ( V_99 -> V_77 & V_92 ) )
continue;
V_37 = F_38 ( V_99 ) ;
if ( ! V_37 || ! F_25 ( V_37 -> V_63 ) )
continue;
V_45 = F_36 ( V_6 , V_90 , V_37 -> V_63 ) ;
if ( V_45 )
break;
}
return V_45 ;
}
static int F_39 ( struct V_85 * V_43 , T_2 V_77 ,
unsigned int V_100 )
{
struct V_83 * V_93 = V_43 -> V_93 -> V_63 ;
struct V_5 * V_12 ;
struct V_36 * V_84 ;
struct V_1 * V_6 ;
struct V_97 * V_90 ;
struct V_49 * V_58 ;
int V_13 , V_101 , V_45 ;
V_45 = F_40 ( V_43 , V_77 , V_100 ) ;
if ( V_45 )
return V_45 ;
if ( ! F_25 ( V_93 ) )
return 0 ;
V_58 = F_26 ( V_93 ) ;
V_101 = V_43 -> V_93 -> V_87 ;
V_6 = F_14 ( V_58 -> V_55 -> V_28 ) ;
V_12 = F_27 ( V_6 , V_58 ) ;
if ( F_28 ( V_12 ) )
return F_29 ( V_12 ) ;
V_84 = & V_12 -> V_37 [ V_101 ] ;
if ( V_100 == V_102 &&
! ( V_77 & V_103 ) ) {
for ( V_13 = 0 ; V_13 < V_84 -> V_88 ; V_13 ++ ) {
V_90 = V_84 -> V_80 [ V_13 ] -> V_90 ;
F_8 ( V_6 -> V_29 . V_28 ,
L_18 ,
V_90 -> V_63 . V_22 ) ;
F_41 ( V_90 -> V_98 ) ;
F_42 ( V_90 -> V_98 , 0 ) ;
}
} else if ( V_100 == V_104 &&
( V_43 -> V_77 & V_103 ) ) {
for ( V_13 = 0 ; V_13 < V_84 -> V_88 ; V_13 ++ ) {
V_90 = V_84 -> V_80 [ V_13 ] -> V_90 ;
F_8 ( V_6 -> V_29 . V_28 ,
L_19 ,
V_90 -> V_63 . V_22 ) ;
V_45 = F_36 ( V_6 , V_90 ,
& V_90 -> V_63 ) ;
if ( V_45 )
break;
}
}
return V_45 ;
}
static int F_43 ( struct V_23 * V_24 )
{
struct V_105 * V_28 = & V_24 -> V_28 ;
struct V_7 * V_106 = V_28 -> V_107 ;
struct V_5 * V_108 [ 4 ] = { 0 } ;
struct V_1 * V_6 ;
int V_45 ;
V_6 = F_44 ( V_28 , sizeof( * V_6 ) , V_109 ) ;
if ( ! V_6 )
return - V_110 ;
F_45 ( V_28 , V_6 ) ;
F_46 ( V_6 -> V_29 . V_111 , L_20 , sizeof( V_6 -> V_29 . V_111 ) ) ;
V_6 -> V_29 . V_112 = & V_113 ;
V_6 -> V_29 . V_28 = V_28 ;
F_47 ( & V_6 -> V_27 ) ;
V_6 -> V_55 . V_114 = & V_6 -> V_29 ;
F_46 ( V_6 -> V_55 . V_22 , L_20 ,
sizeof( V_6 -> V_55 . V_22 ) ) ;
F_48 ( & V_6 -> V_29 ) ;
V_45 = F_49 ( V_28 , & V_6 -> V_55 ) ;
if ( V_45 < 0 ) {
F_15 ( & V_6 -> V_55 ,
L_21 , V_45 ) ;
goto V_115;
}
F_45 ( V_6 -> V_55 . V_28 , V_6 ) ;
V_45 = F_50 ( V_6 , & V_108 , V_106 ) ;
if ( V_45 ) {
F_15 ( & V_6 -> V_55 ,
L_22 , V_45 ) ;
goto V_116;
}
V_45 = F_51 ( V_6 , V_108 ) ;
if ( V_45 ) {
F_15 ( & V_6 -> V_55 ,
L_23 , V_45 ) ;
goto V_116;
}
V_6 -> V_14 = V_6 -> V_4 . V_14 ;
if ( V_6 -> V_14 == 0 ) {
V_45 = - V_56 ;
goto V_116;
}
V_6 -> V_4 . V_117 = V_6 -> V_35 ;
V_6 -> V_4 . V_118 = F_17 ;
V_6 -> V_4 . V_119 = F_33 ;
V_45 = F_52 ( & V_6 -> V_55 ,
& V_6 -> V_4 ) ;
if ( V_45 ) {
F_15 ( & V_6 -> V_55 ,
L_24 , V_45 ) ;
goto V_120;
}
return 0 ;
V_120:
F_53 ( V_6 ) ;
V_116:
F_54 ( & V_6 -> V_55 ) ;
V_115:
F_55 ( & V_6 -> V_29 ) ;
return V_45 ;
}
static int F_56 ( struct V_23 * V_24 )
{
struct V_1 * V_6 =
(struct V_1 * ) F_57 ( V_24 ) ;
F_20 ( & V_6 -> V_55 , L_25 ) ;
F_58 ( & V_6 -> V_4 ) ;
F_53 ( V_6 ) ;
F_54 ( & V_6 -> V_55 ) ;
F_59 ( & V_6 -> V_29 ) ;
F_55 ( & V_6 -> V_29 ) ;
return 0 ;
}
