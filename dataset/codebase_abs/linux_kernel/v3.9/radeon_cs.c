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
if ( ! V_10 ) {
V_2 -> V_19 [ V_8 ] . V_25 = F_3 ( V_4 ,
V_2 -> V_26 ,
V_22 -> V_24 ) ;
if ( V_2 -> V_19 [ V_8 ] . V_25 == NULL ) {
F_4 ( L_1 ,
V_22 -> V_24 ) ;
return - V_27 ;
}
V_2 -> V_16 [ V_8 ] = & V_2 -> V_19 [ V_8 ] ;
V_2 -> V_19 [ V_8 ] . V_28 = F_5 ( V_2 -> V_19 [ V_8 ] . V_25 ) ;
V_2 -> V_19 [ V_8 ] . V_29 . V_30 = V_2 -> V_19 [ V_8 ] . V_28 ;
V_2 -> V_19 [ V_8 ] . V_29 . V_31 = V_22 -> V_32 ;
V_2 -> V_19 [ V_8 ] . V_29 . V_33 = V_22 -> V_34 ;
V_2 -> V_19 [ V_8 ] . V_29 . V_35 . V_30 = & V_2 -> V_19 [ V_8 ] . V_28 -> V_36 ;
V_2 -> V_19 [ V_8 ] . V_24 = V_22 -> V_24 ;
V_2 -> V_19 [ V_8 ] . V_37 = V_22 -> V_37 ;
F_6 ( & V_2 -> V_19 [ V_8 ] . V_29 ,
& V_2 -> V_38 ) ;
} else
V_2 -> V_19 [ V_8 ] . V_24 = 0 ;
}
return F_7 ( & V_2 -> V_38 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_39 , T_2 V_40 )
{
V_2 -> V_40 = V_40 ;
switch ( V_39 ) {
default:
F_4 ( L_2 , V_39 ) ;
return - V_41 ;
case V_42 :
V_2 -> V_39 = V_43 ;
break;
case V_44 :
if ( V_2 -> V_5 -> V_45 >= V_46 ) {
if ( V_2 -> V_40 > 0 )
V_2 -> V_39 = V_47 ;
else
V_2 -> V_39 = V_48 ;
} else
V_2 -> V_39 = V_43 ;
break;
case V_49 :
if ( V_2 -> V_5 -> V_45 >= V_50 ) {
if ( V_2 -> V_40 > 0 )
V_2 -> V_39 = V_51 ;
else
V_2 -> V_39 = V_52 ;
} else if ( V_2 -> V_5 -> V_45 >= V_53 ) {
V_2 -> V_39 = V_51 ;
} else {
return - V_41 ;
}
break;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_14 ; V_8 ++ ) {
if ( ! V_2 -> V_19 [ V_8 ] . V_28 )
continue;
F_10 ( & V_2 -> V_54 , V_2 -> V_19 [ V_8 ] . V_28 -> V_36 . V_55 ) ;
}
}
int F_11 ( struct V_1 * V_2 , void * V_56 )
{
struct V_57 * V_58 = V_56 ;
T_3 * V_59 ;
unsigned V_60 , V_8 ;
T_1 V_39 = V_42 ;
T_2 V_40 = 0 ;
if ( ! V_58 -> V_61 ) {
return 0 ;
}
F_12 ( & V_2 -> V_38 ) ;
V_2 -> V_62 = 0 ;
V_2 -> V_54 . V_63 = NULL ;
V_2 -> V_54 . V_64 = NULL ;
V_2 -> V_65 . V_63 = NULL ;
V_2 -> V_65 . V_64 = NULL ;
V_2 -> V_66 = - 1 ;
V_2 -> V_11 = - 1 ;
V_2 -> V_67 = - 1 ;
V_2 -> V_68 = - 1 ;
V_2 -> V_69 = F_2 ( V_58 -> V_61 , sizeof( T_3 ) , V_17 ) ;
if ( V_2 -> V_69 == NULL ) {
return - V_18 ;
}
V_59 = ( T_3 * ) ( unsigned long ) ( V_58 -> V_12 ) ;
if ( F_13 ( V_2 -> V_69 , V_59 ,
sizeof( T_3 ) * V_58 -> V_61 ) ) {
return - V_70 ;
}
V_2 -> V_71 = 0 ;
V_2 -> V_72 = V_58 -> V_61 ;
V_2 -> V_12 = F_2 ( V_2 -> V_72 , sizeof( struct V_6 ) , V_17 ) ;
if ( V_2 -> V_12 == NULL ) {
return - V_18 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_72 ; V_8 ++ ) {
struct V_73 T_4 * * V_74 = NULL ;
struct V_73 V_75 ;
T_5 T_4 * V_76 ;
V_74 = ( void T_4 * ) ( unsigned long ) V_2 -> V_69 [ V_8 ] ;
if ( F_13 ( & V_75 , V_74 ,
sizeof( struct V_73 ) ) ) {
return - V_70 ;
}
V_2 -> V_12 [ V_8 ] . V_15 = V_75 . V_15 ;
V_2 -> V_12 [ V_8 ] . V_23 = NULL ;
V_2 -> V_12 [ V_8 ] . V_77 = V_75 . V_77 ;
V_2 -> V_12 [ V_8 ] . V_78 = ( void T_4 * ) ( unsigned long ) V_75 . V_79 ;
if ( V_2 -> V_12 [ V_8 ] . V_77 == V_80 ) {
V_2 -> V_11 = V_8 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_77 == V_81 ) {
V_2 -> V_66 = V_8 ;
if ( V_2 -> V_12 [ V_8 ] . V_15 == 0 )
return - V_41 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_77 == V_82 ) {
V_2 -> V_68 = V_8 ;
if ( V_2 -> V_12 [ V_8 ] . V_15 == 0 )
return - V_41 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_77 == V_83 ) {
V_2 -> V_67 = V_8 ;
if ( V_2 -> V_12 [ V_8 ] . V_15 == 0 )
return - V_41 ;
}
V_76 = ( T_5 * ) ( unsigned long ) V_75 . V_79 ;
if ( ( V_2 -> V_12 [ V_8 ] . V_77 == V_80 ) ||
( V_2 -> V_12 [ V_8 ] . V_77 == V_83 ) ) {
V_60 = V_2 -> V_12 [ V_8 ] . V_15 * sizeof( T_5 ) ;
V_2 -> V_12 [ V_8 ] . V_23 = F_14 ( V_60 , V_17 ) ;
if ( V_2 -> V_12 [ V_8 ] . V_23 == NULL ) {
return - V_18 ;
}
if ( F_13 ( V_2 -> V_12 [ V_8 ] . V_23 ,
V_2 -> V_12 [ V_8 ] . V_78 , V_60 ) ) {
return - V_70 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_77 == V_83 ) {
V_2 -> V_71 = V_2 -> V_12 [ V_8 ] . V_23 [ 0 ] ;
if ( V_2 -> V_12 [ V_8 ] . V_15 > 1 )
V_39 = V_2 -> V_12 [ V_8 ] . V_23 [ 1 ] ;
if ( V_2 -> V_12 [ V_8 ] . V_15 > 2 )
V_40 = ( T_2 ) V_2 -> V_12 [ V_8 ] . V_23 [ 2 ] ;
}
}
}
if ( V_2 -> V_5 ) {
if ( ( V_2 -> V_71 & V_84 ) &&
! V_2 -> V_5 -> V_85 . V_86 ) {
F_4 ( L_3 ) ;
return - V_41 ;
}
if ( ( V_2 -> V_5 -> V_45 >= V_46 ) &&
( ( V_2 -> V_71 & V_84 ) == 0 ) ) {
F_4 ( L_4 ) ;
return - V_41 ;
}
if ( F_8 ( V_2 , V_39 , V_40 ) )
return - V_41 ;
}
if ( ( V_2 -> V_66 != - 1 ) &&
( ( V_2 -> V_71 & V_84 ) == 0 ) &&
( V_2 -> V_12 [ V_2 -> V_66 ] . V_77 == V_81 ) ) {
if ( V_2 -> V_12 [ V_2 -> V_66 ] . V_15 > ( 16 * 1024 ) ) {
F_4 ( L_5 ,
V_2 -> V_12 [ V_2 -> V_66 ] . V_15 ) ;
return - V_41 ;
}
if ( V_2 -> V_5 && ( V_2 -> V_5 -> V_37 & V_87 ) ) {
V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 0 ] = F_14 ( V_89 , V_17 ) ;
V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 1 ] = F_14 ( V_89 , V_17 ) ;
if ( V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 0 ] == NULL ||
V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 1 ] == NULL ) {
F_15 ( V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 0 ] ) ;
F_15 ( V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 1 ] ) ;
V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 0 ] = NULL ;
V_2 -> V_12 [ V_2 -> V_66 ] . V_88 [ 1 ] = NULL ;
return - V_18 ;
}
}
V_2 -> V_12 [ V_2 -> V_66 ] . V_90 [ 0 ] = - 1 ;
V_2 -> V_12 [ V_2 -> V_66 ] . V_90 [ 1 ] = - 1 ;
V_2 -> V_12 [ V_2 -> V_66 ] . V_91 = - 1 ;
V_2 -> V_12 [ V_2 -> V_66 ] . V_92 =
( ( V_2 -> V_12 [ V_2 -> V_66 ] . V_15 * 4 ) - 1 ) / V_89 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_93 , int error )
{
unsigned V_8 ;
if ( ! error ) {
F_17 ( & V_93 -> V_38 ,
V_93 -> V_54 . V_94 ) ;
} else {
F_18 ( & V_93 -> V_38 ) ;
}
if ( V_93 -> V_19 != NULL ) {
for ( V_8 = 0 ; V_8 < V_93 -> V_14 ; V_8 ++ ) {
if ( V_93 -> V_19 [ V_8 ] . V_25 )
F_19 ( V_93 -> V_19 [ V_8 ] . V_25 ) ;
}
}
F_15 ( V_93 -> V_95 ) ;
F_15 ( V_93 -> V_19 ) ;
F_15 ( V_93 -> V_16 ) ;
for ( V_8 = 0 ; V_8 < V_93 -> V_72 ; V_8 ++ ) {
F_15 ( V_93 -> V_12 [ V_8 ] . V_23 ) ;
if ( ( V_93 -> V_5 -> V_37 & V_87 ) ) {
F_15 ( V_93 -> V_12 [ V_8 ] . V_88 [ 0 ] ) ;
F_15 ( V_93 -> V_12 [ V_8 ] . V_88 [ 1 ] ) ;
}
}
F_15 ( V_93 -> V_12 ) ;
F_15 ( V_93 -> V_69 ) ;
F_20 ( V_93 -> V_5 , & V_93 -> V_54 ) ;
F_20 ( V_93 -> V_5 , & V_93 -> V_65 ) ;
}
static int F_21 ( struct V_96 * V_5 ,
struct V_1 * V_93 )
{
struct V_6 * V_97 ;
int V_22 ;
if ( V_93 -> V_66 == - 1 )
return 0 ;
if ( V_93 -> V_71 & V_84 )
return 0 ;
V_97 = & V_93 -> V_12 [ V_93 -> V_66 ] ;
V_22 = F_22 ( V_5 , V_93 -> V_39 , & V_93 -> V_54 ,
NULL , V_97 -> V_15 * 4 ) ;
if ( V_22 ) {
F_4 ( L_6 ) ;
return V_22 ;
}
V_93 -> V_54 . V_15 = V_97 -> V_15 ;
V_22 = F_23 ( V_5 , V_93 -> V_39 , V_93 ) ;
if ( V_22 || V_93 -> V_98 ) {
F_4 ( L_7 ) ;
return V_22 ;
}
V_22 = F_24 ( V_93 ) ;
if ( V_22 ) {
F_4 ( L_7 ) ;
return V_22 ;
}
F_9 ( V_93 ) ;
V_22 = F_25 ( V_5 , & V_93 -> V_54 , NULL ) ;
if ( V_22 ) {
F_4 ( L_8 ) ;
}
return V_22 ;
}
static int F_26 ( struct V_1 * V_93 ,
struct V_99 * V_100 )
{
struct V_96 * V_5 = V_93 -> V_5 ;
struct V_101 * V_29 ;
struct V_102 * V_30 ;
int V_22 ;
V_22 = F_27 ( V_5 , V_100 , V_5 -> V_103 . V_30 , & V_5 -> V_103 . V_30 -> V_36 . V_104 ) ;
if ( V_22 ) {
return V_22 ;
}
F_28 (lobj, &parser->validated, tv.head) {
V_30 = V_29 -> V_30 ;
V_22 = F_27 ( V_93 -> V_5 , V_100 , V_30 , & V_30 -> V_36 . V_104 ) ;
if ( V_22 ) {
return V_22 ;
}
}
return 0 ;
}
static int F_29 ( struct V_96 * V_5 ,
struct V_1 * V_93 )
{
struct V_6 * V_97 ;
struct V_105 * V_106 = V_93 -> V_26 -> V_107 ;
struct V_99 * V_100 = & V_106 -> V_100 ;
int V_22 ;
if ( V_93 -> V_66 == - 1 )
return 0 ;
if ( ( V_93 -> V_71 & V_84 ) == 0 )
return 0 ;
if ( ( V_5 -> V_45 >= V_46 ) &&
( V_93 -> V_68 != - 1 ) ) {
V_97 = & V_93 -> V_12 [ V_93 -> V_68 ] ;
if ( V_97 -> V_15 > V_108 ) {
F_4 ( L_9 , V_97 -> V_15 ) ;
return - V_41 ;
}
V_22 = F_22 ( V_5 , V_93 -> V_39 , & V_93 -> V_65 ,
V_100 , V_97 -> V_15 * 4 ) ;
if ( V_22 ) {
F_4 ( L_10 ) ;
return V_22 ;
}
V_93 -> V_65 . V_109 = true ;
V_93 -> V_65 . V_15 = V_97 -> V_15 ;
if ( F_13 ( V_93 -> V_65 . V_110 , V_97 -> V_78 ,
V_97 -> V_15 * 4 ) ) {
return - V_70 ;
}
V_22 = F_30 ( V_5 , V_93 -> V_39 , & V_93 -> V_65 ) ;
if ( V_22 ) {
return V_22 ;
}
}
V_97 = & V_93 -> V_12 [ V_93 -> V_66 ] ;
if ( V_97 -> V_15 > V_108 ) {
F_4 ( L_5 , V_97 -> V_15 ) ;
return - V_41 ;
}
V_22 = F_22 ( V_5 , V_93 -> V_39 , & V_93 -> V_54 ,
V_100 , V_97 -> V_15 * 4 ) ;
if ( V_22 ) {
F_4 ( L_6 ) ;
return V_22 ;
}
V_93 -> V_54 . V_15 = V_97 -> V_15 ;
if ( F_13 ( V_93 -> V_54 . V_110 , V_97 -> V_78 ,
V_97 -> V_15 * 4 ) ) {
return - V_70 ;
}
V_22 = F_30 ( V_5 , V_93 -> V_39 , & V_93 -> V_54 ) ;
if ( V_22 ) {
return V_22 ;
}
F_31 ( & V_5 -> V_85 . V_111 ) ;
F_31 ( & V_100 -> V_112 ) ;
V_22 = F_32 ( V_5 , V_100 ) ;
if ( V_22 ) {
goto V_113;
}
V_22 = F_26 ( V_93 , V_100 ) ;
if ( V_22 ) {
goto V_113;
}
F_9 ( V_93 ) ;
F_10 ( & V_93 -> V_54 , V_100 -> V_94 ) ;
F_10 ( & V_93 -> V_54 , F_33 (
V_5 , V_100 , V_93 -> V_39 ) ) ;
if ( ( V_5 -> V_45 >= V_46 ) &&
( V_93 -> V_68 != - 1 ) ) {
V_22 = F_25 ( V_5 , & V_93 -> V_54 , & V_93 -> V_65 ) ;
} else {
V_22 = F_25 ( V_5 , & V_93 -> V_54 , NULL ) ;
}
if ( ! V_22 ) {
F_34 ( V_5 , V_100 , V_93 -> V_54 . V_94 ) ;
}
V_113:
F_35 ( V_5 , V_100 ) ;
F_36 ( & V_100 -> V_112 ) ;
F_36 ( & V_5 -> V_85 . V_111 ) ;
return V_22 ;
}
static int F_37 ( struct V_96 * V_5 , int V_22 )
{
if ( V_22 == - V_114 ) {
V_22 = F_38 ( V_5 ) ;
if ( ! V_22 )
V_22 = - V_115 ;
}
return V_22 ;
}
int F_39 ( struct V_3 * V_116 , void * V_56 , struct V_117 * V_26 )
{
struct V_96 * V_5 = V_116 -> V_118 ;
struct V_1 V_93 ;
int V_22 ;
F_40 ( & V_5 -> V_119 ) ;
if ( ! V_5 -> V_120 ) {
F_41 ( & V_5 -> V_119 ) ;
return - V_121 ;
}
memset ( & V_93 , 0 , sizeof( struct V_1 ) ) ;
V_93 . V_26 = V_26 ;
V_93 . V_5 = V_5 ;
V_93 . V_116 = V_5 -> V_116 ;
V_93 . V_45 = V_5 -> V_45 ;
V_22 = F_11 ( & V_93 , V_56 ) ;
if ( V_22 ) {
F_4 ( L_11 ) ;
F_16 ( & V_93 , V_22 ) ;
F_41 ( & V_5 -> V_119 ) ;
V_22 = F_37 ( V_5 , V_22 ) ;
return V_22 ;
}
V_22 = F_1 ( & V_93 ) ;
if ( V_22 ) {
if ( V_22 != - V_122 )
F_4 ( L_12 , V_22 ) ;
F_16 ( & V_93 , V_22 ) ;
F_41 ( & V_5 -> V_119 ) ;
V_22 = F_37 ( V_5 , V_22 ) ;
return V_22 ;
}
V_22 = F_21 ( V_5 , & V_93 ) ;
if ( V_22 ) {
goto V_113;
}
V_22 = F_29 ( V_5 , & V_93 ) ;
if ( V_22 ) {
goto V_113;
}
V_113:
F_16 ( & V_93 , V_22 ) ;
F_41 ( & V_5 -> V_119 ) ;
V_22 = F_37 ( V_5 , V_22 ) ;
return V_22 ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_123 = & V_2 -> V_12 [ V_2 -> V_66 ] ;
int V_8 ;
int V_60 = V_89 ;
for ( V_8 = V_123 -> V_91 + 1 ; V_8 <= V_123 -> V_92 ; V_8 ++ ) {
if ( V_8 == V_123 -> V_92 ) {
V_60 = ( V_123 -> V_15 * 4 ) % V_89 ;
if ( V_60 == 0 )
V_60 = V_89 ;
}
if ( F_13 ( V_2 -> V_54 . V_110 + ( V_8 * ( V_89 / 4 ) ) ,
V_123 -> V_78 + ( V_8 * V_89 ) ,
V_60 ) )
return - V_70 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int V_124 )
{
int V_125 ;
struct V_6 * V_123 = & V_2 -> V_12 [ V_2 -> V_66 ] ;
int V_8 ;
int V_60 = V_89 ;
bool V_126 = ( V_2 -> V_5 && ( V_2 -> V_5 -> V_37 & V_87 ) ) ?
false : true ;
for ( V_8 = V_123 -> V_91 + 1 ; V_8 < V_124 ; V_8 ++ ) {
if ( F_13 ( V_2 -> V_54 . V_110 + ( V_8 * ( V_89 / 4 ) ) ,
V_123 -> V_78 + ( V_8 * V_89 ) ,
V_89 ) ) {
V_2 -> V_98 = - V_70 ;
return 0 ;
}
}
if ( V_124 == V_123 -> V_92 ) {
V_60 = ( V_123 -> V_15 * 4 ) % V_89 ;
if ( V_60 == 0 )
V_60 = V_89 ;
}
V_125 = V_123 -> V_90 [ 0 ] < V_123 -> V_90 [ 1 ] ? 0 : 1 ;
if ( V_126 )
V_123 -> V_88 [ V_125 ] = V_2 -> V_54 . V_110 + ( V_124 * ( V_89 / 4 ) ) ;
if ( F_13 ( V_123 -> V_88 [ V_125 ] ,
V_123 -> V_78 + ( V_124 * V_89 ) ,
V_60 ) ) {
V_2 -> V_98 = - V_70 ;
return 0 ;
}
if ( ! V_126 )
memcpy ( ( void * ) ( V_2 -> V_54 . V_110 + ( V_124 * ( V_89 / 4 ) ) ) , V_123 -> V_88 [ V_125 ] , V_60 ) ;
V_123 -> V_91 = V_124 ;
V_123 -> V_90 [ V_125 ] = V_124 ;
return V_125 ;
}
T_1 F_43 ( struct V_1 * V_2 , int V_62 )
{
struct V_6 * V_123 = & V_2 -> V_12 [ V_2 -> V_66 ] ;
T_1 V_124 , V_127 ;
T_1 V_128 = 0 ;
int V_125 ;
V_124 = ( V_62 * 4 ) / V_89 ;
V_127 = ( V_62 * 4 ) % V_89 ;
if ( V_123 -> V_90 [ 0 ] == V_124 )
return V_123 -> V_88 [ 0 ] [ V_127 / 4 ] ;
if ( V_123 -> V_90 [ 1 ] == V_124 )
return V_123 -> V_88 [ 1 ] [ V_127 / 4 ] ;
V_125 = F_42 ( V_2 , V_124 ) ;
if ( V_125 < 0 ) {
V_2 -> V_98 = V_125 ;
return 0 ;
}
V_128 = V_123 -> V_88 [ V_125 ] [ V_127 / 4 ] ;
return V_128 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
unsigned V_62 )
{
struct V_6 * V_97 = & V_2 -> V_12 [ V_2 -> V_66 ] ;
struct V_96 * V_5 = V_2 -> V_5 ;
T_5 V_131 ;
if ( V_62 >= V_97 -> V_15 ) {
F_4 ( L_13 ,
V_62 , V_97 -> V_15 ) ;
return - V_41 ;
}
V_131 = F_43 ( V_2 , V_62 ) ;
V_130 -> V_62 = V_62 ;
V_130 -> type = F_45 ( V_131 ) ;
V_130 -> V_132 = F_46 ( V_131 ) ;
V_130 -> V_133 = 0 ;
switch ( V_130 -> type ) {
case V_134 :
if ( V_5 -> V_45 < V_53 ) {
V_130 -> V_135 = F_47 ( V_131 ) ;
V_130 -> V_133 =
F_48 ( V_131 ) ;
} else
V_130 -> V_135 = F_49 ( V_131 ) ;
break;
case V_136 :
V_130 -> V_137 = F_50 ( V_131 ) ;
break;
case V_138 :
V_130 -> V_132 = - 1 ;
break;
default:
F_4 ( L_14 , V_130 -> type , V_62 ) ;
return - V_41 ;
}
if ( ( V_130 -> V_132 + 1 + V_130 -> V_62 ) >= V_97 -> V_15 ) {
F_4 ( L_15 ,
V_130 -> V_62 , V_130 -> type , V_130 -> V_132 , V_97 -> V_15 ) ;
return - V_41 ;
}
return 0 ;
}
bool F_51 ( struct V_1 * V_2 )
{
struct V_129 V_139 ;
int V_22 ;
V_22 = F_44 ( V_2 , & V_139 , V_2 -> V_62 ) ;
if ( V_22 )
return false ;
if ( V_139 . type != V_136 )
return false ;
if ( V_139 . V_137 != V_140 )
return false ;
return true ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
volatile T_5 * V_54 ;
unsigned V_8 ;
unsigned V_62 ;
V_54 = V_2 -> V_54 . V_110 ;
V_62 = V_130 -> V_62 ;
for ( V_8 = 0 ; V_8 <= ( V_130 -> V_132 + 1 ) ; V_8 ++ , V_62 ++ )
F_53 ( L_16 , V_62 , V_54 [ V_62 ] ) ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_20 * * V_141 ,
int V_142 )
{
struct V_6 * V_143 ;
struct V_129 V_139 ;
unsigned V_62 ;
int V_22 ;
if ( V_2 -> V_11 == - 1 ) {
F_4 ( L_17 ) ;
return - V_41 ;
}
* V_141 = NULL ;
V_143 = & V_2 -> V_12 [ V_2 -> V_11 ] ;
V_22 = F_44 ( V_2 , & V_139 , V_2 -> V_62 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_62 += V_139 . V_132 + 2 ;
if ( V_139 . type != V_136 ||
V_139 . V_137 != V_140 ) {
F_4 ( L_18 ,
V_139 . V_62 ) ;
F_52 ( V_2 , & V_139 ) ;
return - V_41 ;
}
V_62 = F_43 ( V_2 , V_139 . V_62 + 1 ) ;
if ( V_62 >= V_143 -> V_15 ) {
F_4 ( L_19 ,
V_62 , V_143 -> V_15 ) ;
F_52 ( V_2 , & V_139 ) ;
return - V_41 ;
}
if ( V_142 ) {
* V_141 = V_2 -> V_19 ;
( * V_141 ) -> V_29 . V_144 =
( V_145 ) V_143 -> V_23 [ V_62 + 3 ] << 32 ;
( * V_141 ) -> V_29 . V_144 |= V_143 -> V_23 [ V_62 + 0 ] ;
} else
* V_141 = V_2 -> V_16 [ ( V_62 / 4 ) ] ;
return 0 ;
}
