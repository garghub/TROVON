static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 ;
unsigned V_8 , V_9 ;
bool V_10 ;
if ( V_2 -> V_11 == - 1 ) {
return 0 ;
}
V_7 = & V_2 -> V_12 [ V_2 -> V_11 ] ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = V_7 -> V_15 / 4 ;
V_2 -> V_16 = F_2 ( V_2 -> V_14 , sizeof( void * ) , V_17 ) ;
if ( V_2 -> V_16 == NULL ) {
return - V_18 ;
}
V_2 -> V_19 = F_2 ( V_2 -> V_14 , sizeof( struct V_20 ) , V_17 ) ;
if ( V_2 -> V_19 == NULL ) {
return - V_18 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_14 ; V_8 ++ ) {
struct V_21 * V_22 ;
V_10 = false ;
V_22 = (struct V_21 * ) & V_7 -> V_23 [ V_8 * 4 ] ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
if ( V_22 -> V_24 == V_2 -> V_19 [ V_9 ] . V_24 ) {
V_2 -> V_16 [ V_8 ] = & V_2 -> V_19 [ V_9 ] ;
V_10 = true ;
break;
}
}
if ( V_10 ) {
V_2 -> V_19 [ V_8 ] . V_24 = 0 ;
continue;
}
V_2 -> V_19 [ V_8 ] . V_25 = F_3 ( V_4 , V_2 -> V_26 ,
V_22 -> V_24 ) ;
if ( V_2 -> V_19 [ V_8 ] . V_25 == NULL ) {
F_4 ( L_1 ,
V_22 -> V_24 ) ;
return - V_27 ;
}
V_2 -> V_16 [ V_8 ] = & V_2 -> V_19 [ V_8 ] ;
V_2 -> V_19 [ V_8 ] . V_28 = F_5 ( V_2 -> V_19 [ V_8 ] . V_25 ) ;
V_2 -> V_19 [ V_8 ] . V_29 . V_30 = V_2 -> V_19 [ V_8 ] . V_28 ;
V_2 -> V_19 [ V_8 ] . V_29 . V_31 = ! ! V_22 -> V_32 ;
if ( V_2 -> V_33 == V_34 &&
( V_8 == 0 || F_6 ( V_2 -> V_5 -> V_4 ) ) ) {
V_2 -> V_19 [ V_8 ] . V_29 . V_35 =
V_36 ;
V_2 -> V_19 [ V_8 ] . V_29 . V_37 =
V_36 ;
} else {
T_1 V_35 = V_22 -> V_32 ?
V_22 -> V_32 : V_22 -> V_38 ;
V_2 -> V_19 [ V_8 ] . V_29 . V_35 = V_35 ;
if ( V_35 == V_36 )
V_35 |= V_39 ;
V_2 -> V_19 [ V_8 ] . V_29 . V_37 = V_35 ;
}
V_2 -> V_19 [ V_8 ] . V_29 . V_40 . V_30 = & V_2 -> V_19 [ V_8 ] . V_28 -> V_41 ;
V_2 -> V_19 [ V_8 ] . V_24 = V_22 -> V_24 ;
F_7 ( & V_2 -> V_19 [ V_8 ] . V_29 ,
& V_2 -> V_42 ) ;
}
return F_8 ( & V_2 -> V_43 , & V_2 -> V_42 , V_2 -> V_33 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_33 , T_3 V_44 )
{
V_2 -> V_44 = V_44 ;
switch ( V_33 ) {
default:
F_4 ( L_2 , V_33 ) ;
return - V_45 ;
case V_46 :
V_2 -> V_33 = V_47 ;
break;
case V_48 :
if ( V_2 -> V_5 -> V_49 >= V_50 ) {
if ( V_2 -> V_44 > 0 )
V_2 -> V_33 = V_51 ;
else
V_2 -> V_33 = V_52 ;
} else
V_2 -> V_33 = V_47 ;
break;
case V_53 :
if ( V_2 -> V_5 -> V_49 >= V_54 ) {
if ( V_2 -> V_44 > 0 )
V_2 -> V_33 = V_55 ;
else
V_2 -> V_33 = V_56 ;
} else if ( V_2 -> V_5 -> V_49 >= V_57 ) {
V_2 -> V_33 = V_55 ;
} else {
return - V_45 ;
}
break;
case V_58 :
V_2 -> V_33 = V_34 ;
break;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_14 ; V_8 ++ ) {
if ( ! V_2 -> V_19 [ V_8 ] . V_28 )
continue;
F_11 ( V_2 -> V_59 . V_60 ,
V_2 -> V_19 [ V_8 ] . V_28 -> V_41 . V_61 ) ;
}
}
int F_12 ( struct V_1 * V_2 , void * V_62 )
{
struct V_63 * V_64 = V_62 ;
T_4 * V_65 ;
unsigned V_66 , V_8 ;
T_2 V_33 = V_46 ;
T_3 V_44 = 0 ;
if ( ! V_64 -> V_67 ) {
return 0 ;
}
F_13 ( & V_2 -> V_42 ) ;
V_2 -> V_68 = 0 ;
V_2 -> V_59 . V_69 = NULL ;
V_2 -> V_59 . V_60 = NULL ;
V_2 -> V_70 . V_69 = NULL ;
V_2 -> V_70 . V_60 = NULL ;
V_2 -> V_71 = - 1 ;
V_2 -> V_11 = - 1 ;
V_2 -> V_72 = - 1 ;
V_2 -> V_73 = - 1 ;
V_2 -> V_74 = F_2 ( V_64 -> V_67 , sizeof( T_4 ) , V_17 ) ;
if ( V_2 -> V_74 == NULL ) {
return - V_18 ;
}
V_65 = ( T_4 * ) ( unsigned long ) ( V_64 -> V_12 ) ;
if ( F_14 ( V_2 -> V_74 , V_65 ,
sizeof( T_4 ) * V_64 -> V_67 ) ) {
return - V_75 ;
}
V_2 -> V_76 = 0 ;
V_2 -> V_77 = V_64 -> V_67 ;
V_2 -> V_12 = F_2 ( V_2 -> V_77 , sizeof( struct V_6 ) , V_17 ) ;
if ( V_2 -> V_12 == NULL ) {
return - V_18 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_77 ; V_8 ++ ) {
struct V_78 T_5 * * V_79 = NULL ;
struct V_78 V_80 ;
T_1 T_5 * V_81 ;
V_79 = ( void T_5 * ) ( unsigned long ) V_2 -> V_74 [ V_8 ] ;
if ( F_14 ( & V_80 , V_79 ,
sizeof( struct V_78 ) ) ) {
return - V_75 ;
}
V_2 -> V_12 [ V_8 ] . V_15 = V_80 . V_15 ;
V_2 -> V_12 [ V_8 ] . V_82 = V_80 . V_82 ;
if ( V_2 -> V_12 [ V_8 ] . V_82 == V_83 ) {
V_2 -> V_11 = V_8 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_82 == V_84 ) {
V_2 -> V_71 = V_8 ;
if ( V_2 -> V_12 [ V_8 ] . V_15 == 0 )
return - V_45 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_82 == V_85 ) {
V_2 -> V_73 = V_8 ;
if ( V_2 -> V_12 [ V_8 ] . V_15 == 0 )
return - V_45 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_82 == V_86 ) {
V_2 -> V_72 = V_8 ;
if ( V_2 -> V_12 [ V_8 ] . V_15 == 0 )
return - V_45 ;
}
V_66 = V_2 -> V_12 [ V_8 ] . V_15 ;
V_81 = ( void T_5 * ) ( unsigned long ) V_80 . V_87 ;
V_2 -> V_12 [ V_8 ] . V_88 = V_81 ;
if ( V_2 -> V_12 [ V_8 ] . V_82 == V_85 )
continue;
if ( V_2 -> V_12 [ V_8 ] . V_82 == V_84 ) {
if ( ! V_2 -> V_5 || ! ( V_2 -> V_5 -> V_89 & V_90 ) )
continue;
}
V_2 -> V_12 [ V_8 ] . V_23 = F_15 ( V_66 , sizeof( T_1 ) ) ;
V_66 *= sizeof( T_1 ) ;
if ( V_2 -> V_12 [ V_8 ] . V_23 == NULL ) {
return - V_18 ;
}
if ( F_14 ( V_2 -> V_12 [ V_8 ] . V_23 , V_81 , V_66 ) ) {
return - V_75 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_82 == V_86 ) {
V_2 -> V_76 = V_2 -> V_12 [ V_8 ] . V_23 [ 0 ] ;
if ( V_2 -> V_12 [ V_8 ] . V_15 > 1 )
V_33 = V_2 -> V_12 [ V_8 ] . V_23 [ 1 ] ;
if ( V_2 -> V_12 [ V_8 ] . V_15 > 2 )
V_44 = ( T_3 ) V_2 -> V_12 [ V_8 ] . V_23 [ 2 ] ;
}
}
if ( V_2 -> V_5 ) {
if ( ( V_2 -> V_76 & V_91 ) &&
! V_2 -> V_5 -> V_92 . V_93 ) {
F_4 ( L_3 ) ;
return - V_45 ;
}
if ( F_9 ( V_2 , V_33 , V_44 ) )
return - V_45 ;
if ( ( V_2 -> V_5 -> V_94 -> V_33 [ V_2 -> V_33 ] -> V_95 == NULL ) &&
( ( V_2 -> V_76 & V_91 ) == 0 ) ) {
F_4 ( L_4 , V_2 -> V_33 ) ;
return - V_45 ;
}
}
return 0 ;
}
static void F_16 ( struct V_1 * V_96 , int error , bool V_97 )
{
unsigned V_8 ;
if ( ! error ) {
F_17 ( & V_96 -> V_43 ,
& V_96 -> V_42 ,
V_96 -> V_59 . V_98 ) ;
} else if ( V_97 ) {
F_18 ( & V_96 -> V_43 ,
& V_96 -> V_42 ) ;
}
if ( V_96 -> V_19 != NULL ) {
for ( V_8 = 0 ; V_8 < V_96 -> V_14 ; V_8 ++ ) {
if ( V_96 -> V_19 [ V_8 ] . V_25 )
F_19 ( V_96 -> V_19 [ V_8 ] . V_25 ) ;
}
}
F_20 ( V_96 -> V_99 ) ;
F_20 ( V_96 -> V_19 ) ;
F_20 ( V_96 -> V_16 ) ;
for ( V_8 = 0 ; V_8 < V_96 -> V_77 ; V_8 ++ )
F_21 ( V_96 -> V_12 [ V_8 ] . V_23 ) ;
F_20 ( V_96 -> V_12 ) ;
F_20 ( V_96 -> V_74 ) ;
F_22 ( V_96 -> V_5 , & V_96 -> V_59 ) ;
F_22 ( V_96 -> V_5 , & V_96 -> V_70 ) ;
}
static int F_23 ( struct V_100 * V_5 ,
struct V_1 * V_96 )
{
int V_22 ;
if ( V_96 -> V_71 == - 1 )
return 0 ;
if ( V_96 -> V_76 & V_91 )
return 0 ;
V_22 = F_24 ( V_5 , V_96 -> V_33 , V_96 ) ;
if ( V_22 || V_96 -> V_101 ) {
F_4 ( L_5 ) ;
return V_22 ;
}
if ( V_96 -> V_33 == V_34 )
F_25 ( V_5 ) ;
F_10 ( V_96 ) ;
V_22 = F_26 ( V_5 , & V_96 -> V_59 , NULL ) ;
if ( V_22 ) {
F_4 ( L_6 ) ;
}
return V_22 ;
}
static int F_27 ( struct V_1 * V_96 ,
struct V_102 * V_103 )
{
struct V_100 * V_5 = V_96 -> V_5 ;
struct V_104 * V_29 ;
struct V_105 * V_30 ;
int V_22 ;
V_22 = F_28 ( V_5 , V_103 , V_5 -> V_106 . V_30 , & V_5 -> V_106 . V_30 -> V_41 . V_107 ) ;
if ( V_22 ) {
return V_22 ;
}
F_29 (lobj, &parser->validated, tv.head) {
V_30 = V_29 -> V_30 ;
V_22 = F_28 ( V_96 -> V_5 , V_103 , V_30 , & V_30 -> V_41 . V_107 ) ;
if ( V_22 ) {
return V_22 ;
}
}
return 0 ;
}
static int F_30 ( struct V_100 * V_5 ,
struct V_1 * V_96 )
{
struct V_108 * V_109 = V_96 -> V_26 -> V_110 ;
struct V_102 * V_103 = & V_109 -> V_103 ;
int V_22 ;
if ( V_96 -> V_71 == - 1 )
return 0 ;
if ( ( V_96 -> V_76 & V_91 ) == 0 )
return 0 ;
if ( V_96 -> V_70 . V_15 ) {
V_22 = F_31 ( V_5 , V_96 -> V_33 , & V_96 -> V_70 ) ;
if ( V_22 ) {
return V_22 ;
}
}
V_22 = F_31 ( V_5 , V_96 -> V_33 , & V_96 -> V_59 ) ;
if ( V_22 ) {
return V_22 ;
}
if ( V_96 -> V_33 == V_34 )
F_25 ( V_5 ) ;
F_32 ( & V_5 -> V_92 . V_111 ) ;
F_32 ( & V_103 -> V_112 ) ;
V_22 = F_33 ( V_5 , V_103 ) ;
if ( V_22 ) {
goto V_113;
}
V_22 = F_27 ( V_96 , V_103 ) ;
if ( V_22 ) {
goto V_113;
}
F_10 ( V_96 ) ;
F_11 ( V_96 -> V_59 . V_60 , V_103 -> V_98 ) ;
F_11 ( V_96 -> V_59 . V_60 ,
F_34 ( V_5 , V_103 , V_96 -> V_33 ) ) ;
if ( ( V_5 -> V_49 >= V_50 ) &&
( V_96 -> V_73 != - 1 ) ) {
V_22 = F_26 ( V_5 , & V_96 -> V_59 , & V_96 -> V_70 ) ;
} else {
V_22 = F_26 ( V_5 , & V_96 -> V_59 , NULL ) ;
}
if ( ! V_22 ) {
F_35 ( V_5 , V_103 , V_96 -> V_59 . V_98 ) ;
}
V_113:
F_36 ( V_5 , V_103 ) ;
F_37 ( & V_103 -> V_112 ) ;
F_37 ( & V_5 -> V_92 . V_111 ) ;
return V_22 ;
}
static int F_38 ( struct V_100 * V_5 , int V_22 )
{
if ( V_22 == - V_114 ) {
V_22 = F_39 ( V_5 ) ;
if ( ! V_22 )
V_22 = - V_115 ;
}
return V_22 ;
}
static int F_40 ( struct V_100 * V_5 , struct V_1 * V_96 )
{
struct V_6 * V_116 ;
struct V_102 * V_103 = NULL ;
int V_22 ;
if ( V_96 -> V_71 == - 1 )
return 0 ;
if ( V_96 -> V_76 & V_91 ) {
struct V_108 * V_109 = V_96 -> V_26 -> V_110 ;
V_103 = & V_109 -> V_103 ;
if ( ( V_5 -> V_49 >= V_50 ) &&
( V_96 -> V_73 != - 1 ) ) {
V_116 = & V_96 -> V_12 [ V_96 -> V_73 ] ;
if ( V_116 -> V_15 > V_117 ) {
F_4 ( L_7 , V_116 -> V_15 ) ;
return - V_45 ;
}
V_22 = F_41 ( V_5 , V_96 -> V_33 , & V_96 -> V_70 ,
V_103 , V_116 -> V_15 * 4 ) ;
if ( V_22 ) {
F_4 ( L_8 ) ;
return V_22 ;
}
V_96 -> V_70 . V_118 = true ;
V_96 -> V_70 . V_15 = V_116 -> V_15 ;
if ( F_14 ( V_96 -> V_70 . V_119 ,
V_116 -> V_88 ,
V_116 -> V_15 * 4 ) )
return - V_75 ;
}
V_116 = & V_96 -> V_12 [ V_96 -> V_71 ] ;
if ( V_116 -> V_15 > V_117 ) {
F_4 ( L_9 , V_116 -> V_15 ) ;
return - V_45 ;
}
}
V_116 = & V_96 -> V_12 [ V_96 -> V_71 ] ;
V_22 = F_41 ( V_5 , V_96 -> V_33 , & V_96 -> V_59 ,
V_103 , V_116 -> V_15 * 4 ) ;
if ( V_22 ) {
F_4 ( L_10 ) ;
return V_22 ;
}
V_96 -> V_59 . V_15 = V_116 -> V_15 ;
if ( V_116 -> V_23 )
memcpy ( V_96 -> V_59 . V_119 , V_116 -> V_23 , V_116 -> V_15 * 4 ) ;
else if ( F_14 ( V_96 -> V_59 . V_119 , V_116 -> V_88 , V_116 -> V_15 * 4 ) )
return - V_75 ;
return 0 ;
}
int F_42 ( struct V_3 * V_120 , void * V_62 , struct V_121 * V_26 )
{
struct V_100 * V_5 = V_120 -> V_122 ;
struct V_1 V_96 ;
int V_22 ;
F_43 ( & V_5 -> V_123 ) ;
if ( ! V_5 -> V_124 ) {
F_44 ( & V_5 -> V_123 ) ;
return - V_125 ;
}
memset ( & V_96 , 0 , sizeof( struct V_1 ) ) ;
V_96 . V_26 = V_26 ;
V_96 . V_5 = V_5 ;
V_96 . V_120 = V_5 -> V_120 ;
V_96 . V_49 = V_5 -> V_49 ;
V_22 = F_12 ( & V_96 , V_62 ) ;
if ( V_22 ) {
F_4 ( L_11 ) ;
F_16 ( & V_96 , V_22 , false ) ;
F_44 ( & V_5 -> V_123 ) ;
V_22 = F_38 ( V_5 , V_22 ) ;
return V_22 ;
}
V_22 = F_40 ( V_5 , & V_96 ) ;
if ( ! V_22 ) {
V_22 = F_1 ( & V_96 ) ;
if ( V_22 && V_22 != - V_126 )
F_4 ( L_12 , V_22 ) ;
}
if ( V_22 ) {
F_16 ( & V_96 , V_22 , false ) ;
F_44 ( & V_5 -> V_123 ) ;
V_22 = F_38 ( V_5 , V_22 ) ;
return V_22 ;
}
F_45 ( & V_96 ) ;
V_22 = F_23 ( V_5 , & V_96 ) ;
if ( V_22 ) {
goto V_113;
}
V_22 = F_30 ( V_5 , & V_96 ) ;
if ( V_22 ) {
goto V_113;
}
V_113:
F_16 ( & V_96 , V_22 , true ) ;
F_44 ( & V_5 -> V_123 ) ;
V_22 = F_38 ( V_5 , V_22 ) ;
return V_22 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_127 * V_128 ,
unsigned V_68 )
{
struct V_6 * V_116 = & V_2 -> V_12 [ V_2 -> V_71 ] ;
struct V_100 * V_5 = V_2 -> V_5 ;
T_1 V_129 ;
if ( V_68 >= V_116 -> V_15 ) {
F_4 ( L_13 ,
V_68 , V_116 -> V_15 ) ;
return - V_45 ;
}
V_129 = F_47 ( V_2 , V_68 ) ;
V_128 -> V_68 = V_68 ;
V_128 -> type = F_48 ( V_129 ) ;
V_128 -> V_130 = F_49 ( V_129 ) ;
V_128 -> V_131 = 0 ;
switch ( V_128 -> type ) {
case V_132 :
if ( V_5 -> V_49 < V_133 ) {
V_128 -> V_134 = F_50 ( V_129 ) ;
V_128 -> V_131 =
F_51 ( V_129 ) ;
} else
V_128 -> V_134 = F_52 ( V_129 ) ;
break;
case V_135 :
V_128 -> V_136 = F_53 ( V_129 ) ;
break;
case V_137 :
V_128 -> V_130 = - 1 ;
break;
default:
F_4 ( L_14 , V_128 -> type , V_68 ) ;
return - V_45 ;
}
if ( ( V_128 -> V_130 + 1 + V_128 -> V_68 ) >= V_116 -> V_15 ) {
F_4 ( L_15 ,
V_128 -> V_68 , V_128 -> type , V_128 -> V_130 , V_116 -> V_15 ) ;
return - V_45 ;
}
return 0 ;
}
bool F_54 ( struct V_1 * V_2 )
{
struct V_127 V_138 ;
int V_22 ;
V_22 = F_46 ( V_2 , & V_138 , V_2 -> V_68 ) ;
if ( V_22 )
return false ;
if ( V_138 . type != V_135 )
return false ;
if ( V_138 . V_136 != V_139 )
return false ;
return true ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
volatile T_1 * V_59 ;
unsigned V_8 ;
unsigned V_68 ;
V_59 = V_2 -> V_59 . V_119 ;
V_68 = V_128 -> V_68 ;
for ( V_8 = 0 ; V_8 <= ( V_128 -> V_130 + 1 ) ; V_8 ++ , V_68 ++ )
F_56 ( L_16 , V_68 , V_59 [ V_68 ] ) ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_20 * * V_140 ,
int V_141 )
{
struct V_6 * V_142 ;
struct V_127 V_138 ;
unsigned V_68 ;
int V_22 ;
if ( V_2 -> V_11 == - 1 ) {
F_4 ( L_17 ) ;
return - V_45 ;
}
* V_140 = NULL ;
V_142 = & V_2 -> V_12 [ V_2 -> V_11 ] ;
V_22 = F_46 ( V_2 , & V_138 , V_2 -> V_68 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_68 += V_138 . V_130 + 2 ;
if ( V_138 . type != V_135 ||
V_138 . V_136 != V_139 ) {
F_4 ( L_18 ,
V_138 . V_68 ) ;
F_55 ( V_2 , & V_138 ) ;
return - V_45 ;
}
V_68 = F_47 ( V_2 , V_138 . V_68 + 1 ) ;
if ( V_68 >= V_142 -> V_15 ) {
F_4 ( L_19 ,
V_68 , V_142 -> V_15 ) ;
F_55 ( V_2 , & V_138 ) ;
return - V_45 ;
}
if ( V_141 ) {
* V_140 = V_2 -> V_19 ;
( * V_140 ) -> V_29 . V_143 =
( V_144 ) V_142 -> V_23 [ V_68 + 3 ] << 32 ;
( * V_140 ) -> V_29 . V_143 |= V_142 -> V_23 [ V_68 + 0 ] ;
} else
* V_140 = V_2 -> V_16 [ ( V_68 / 4 ) ] ;
return 0 ;
}
