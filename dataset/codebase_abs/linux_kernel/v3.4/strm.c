int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * * V_4 , T_1 V_5 ,
struct V_6 * V_7 )
{
int V_8 = 0 ;
T_1 V_9 = 0 ;
T_1 V_10 ;
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_12 ) {
if ( V_3 == 0 )
V_8 = - V_14 ;
} else {
V_8 = - V_15 ;
}
if ( V_8 )
goto V_16;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
( void ) F_2 ( V_12 -> V_17 , & V_4 [ V_10 ] ,
V_3 ) ;
if ( V_4 [ V_10 ] == NULL ) {
V_8 = - V_18 ;
V_9 = V_10 ;
break;
}
}
if ( V_8 )
F_3 ( V_2 , V_4 , V_9 , V_7 ) ;
if ( V_8 )
goto V_16;
F_4 ( V_5 , V_2 ) ;
V_16:
return V_8 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_19 * V_20 ;
struct V_21 V_22 ;
int V_8 = 0 ;
struct V_11 * V_12 = V_2 -> V_13 ;
if ( ! V_12 ) {
V_8 = - V_15 ;
} else {
V_20 = V_12 -> V_23 -> V_20 ;
V_8 =
(* V_20 -> V_24 ) ( V_12 -> V_25 ,
& V_22 ) ;
if ( V_22 . V_26 > 0 || V_22 . V_27 > 0 )
V_8 = - V_28 ;
else
V_8 = F_6 ( V_12 ) ;
}
if ( V_8 )
goto V_16;
F_7 ( V_7 -> V_29 , V_2 -> V_30 ) ;
V_16:
F_8 ( V_31 , L_1 , V_32 ,
V_12 , V_8 ) ;
return V_8 ;
}
int F_9 ( struct V_33 * * V_34 ,
struct V_35 * V_36 )
{
struct V_33 * V_23 ;
int V_8 = 0 ;
* V_34 = NULL ;
V_23 = F_10 ( sizeof( struct V_33 ) , V_37 ) ;
if ( V_23 == NULL )
V_8 = - V_18 ;
else
V_23 -> V_36 = V_36 ;
if ( ! V_8 ) {
V_8 = F_11 ( V_36 , & ( V_23 -> V_38 ) ) ;
if ( ! V_8 ) {
( void ) F_12 ( V_36 ,
& ( V_23 -> V_20 ) ) ;
}
}
if ( ! V_8 )
* V_34 = V_23 ;
else
F_13 ( V_23 ) ;
return V_8 ;
}
void F_14 ( struct V_33 * V_23 )
{
F_13 ( V_23 ) ;
}
int F_3 ( struct V_1 * V_2 , T_2 * * V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
int V_8 = 0 ;
T_1 V_10 = 0 ;
struct V_11 * V_12 = V_2 -> V_13 ;
if ( ! V_12 )
V_8 = - V_15 ;
if ( ! V_8 ) {
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
V_8 =
F_15 ( V_12 -> V_17 ,
V_4 [ V_10 ] ) ;
if ( V_8 )
break;
V_4 [ V_10 ] = NULL ;
}
}
F_4 ( V_5 - V_10 , V_2 ) ;
return V_8 ;
}
int F_16 ( struct V_11 * V_12 ,
struct V_39 * V_39 ,
T_1 V_40 )
{
struct V_19 * V_20 ;
struct V_21 V_22 ;
int V_8 = 0 ;
void * V_41 = NULL ;
if ( ! V_12 ) {
V_8 = - V_15 ;
} else {
if ( V_40 < sizeof( struct V_39 ) ) {
V_8 = - V_14 ;
}
}
if ( V_8 )
goto V_16;
V_20 = V_12 -> V_23 -> V_20 ;
V_8 =
(* V_20 -> V_24 ) ( V_12 -> V_25 ,
& V_22 ) ;
if ( V_8 )
goto V_16;
if ( V_12 -> V_17 ) {
F_17 ( V_12 -> V_17 , ( T_2 * * ) & V_41 , 0 ,
V_12 -> V_42 , false ) ;
}
V_39 -> V_42 = V_12 -> V_42 ;
V_39 -> V_43 = V_12 -> V_43 ;
V_39 -> V_41 = V_41 ;
V_39 -> V_44 -> V_45 = V_12 -> V_5 ;
V_39 -> V_44 -> V_46 = V_22 . V_26 +
V_22 . V_27 ;
V_39 -> V_44 -> V_47 = V_22 . V_48 ;
V_39 -> V_44 -> V_49 = V_22 . V_50 ;
if ( V_22 . V_51 & V_52 ) {
V_39 -> V_44 -> V_53 = V_54 ;
} else {
if ( V_22 . V_26 > 0 )
V_39 -> V_44 -> V_53 = V_55 ;
else if ( V_22 . V_27 > 0 )
V_39 -> V_44 -> V_53 =
V_56 ;
else
V_39 -> V_44 -> V_53 = V_57 ;
}
V_16:
return V_8 ;
}
int F_18 ( struct V_11 * V_12 , bool V_58 )
{
struct V_19 * V_20 ;
int V_8 = 0 ;
if ( ! V_12 ) {
V_8 = - V_15 ;
} else {
V_20 = V_12 -> V_23 -> V_20 ;
V_8 = (* V_20 -> V_59 ) ( V_12 -> V_25 ,
V_12 -> V_60 ,
V_58 ) ;
}
F_8 ( V_31 , L_2 ,
V_32 , V_12 , V_58 , V_8 ) ;
return V_8 ;
}
int F_19 ( struct V_11 * V_12 , T_2 * V_61 , T_1 V_62 ,
T_1 V_63 , T_1 V_64 )
{
struct V_19 * V_20 ;
int V_8 = 0 ;
void * V_65 = NULL ;
if ( ! V_12 ) {
V_8 = - V_15 ;
} else {
V_20 = V_12 -> V_23 -> V_20 ;
if ( V_12 -> V_42 != 0 ) {
V_65 = F_20 ( V_12 -> V_17 ,
( void * ) V_61 ,
V_66 ) ;
if ( V_65 == NULL )
V_8 = - V_67 ;
}
if ( ! V_8 ) {
V_8 = (* V_20 -> V_68 )
( V_12 -> V_25 , V_61 , V_62 , V_63 ,
( T_1 ) V_65 , V_64 ) ;
}
if ( V_8 == - V_69 )
V_8 = - V_70 ;
}
F_8 ( V_31 , L_3
L_4 , V_32 , V_12 , V_61 ,
V_62 , V_64 , V_8 ) ;
return V_8 ;
}
int F_21 ( struct V_71 * V_72 , T_1 V_73 , T_1 V_74 ,
struct V_75 * V_76 ,
struct V_1 * * V_2 ,
struct V_6 * V_7 )
{
struct V_33 * V_23 ;
struct V_19 * V_20 ;
T_1 V_77 ;
struct V_11 * V_78 = NULL ;
T_3 V_79 ;
struct V_80 V_81 ;
int V_8 = 0 ;
struct V_82 * V_83 = NULL ;
void * V_84 ;
* V_2 = NULL ;
if ( V_73 != V_85 && V_73 != V_86 ) {
V_8 = - V_87 ;
} else {
V_8 = F_22 ( V_72 , V_73 , V_74 , & V_77 ) ;
}
if ( ! V_8 )
V_8 = F_23 ( V_72 , & V_23 ) ;
if ( ! V_8 ) {
V_78 = F_10 ( sizeof( struct V_11 ) , V_37 ) ;
if ( V_78 == NULL ) {
V_8 = - V_18 ;
} else {
V_78 -> V_23 = V_23 ;
V_78 -> V_73 = V_73 ;
V_78 -> V_88 = V_57 ;
V_78 -> V_89 = V_76 -> V_89 ;
if ( V_76 -> V_90 != NULL ) {
V_78 -> V_60 =
V_76 -> V_90 -> V_60 ;
V_78 -> V_5 =
V_76 -> V_90 -> V_5 ;
V_78 -> V_43 =
V_76 -> V_90 -> V_43 ;
V_78 -> V_42 =
V_76 -> V_90 -> V_42 ;
V_78 -> V_91 =
V_76 -> V_90 -> V_91 ;
V_78 -> V_92 =
V_76 -> V_90 -> V_92 ;
V_78 -> V_93 =
V_76 -> V_90 -> V_93 ;
V_81 . V_94 =
V_76 -> V_90 -> V_5 ;
} else {
V_78 -> V_60 = V_95 ;
V_78 -> V_5 = V_96 ;
V_78 -> V_43 = V_97 ;
V_78 -> V_42 = 0 ;
V_78 -> V_91 = 0 ;
V_78 -> V_92 = 0 ;
V_78 -> V_93 = 0 ;
V_81 . V_94 = V_96 ;
}
V_81 . V_98 = NULL ;
V_81 . V_99 = V_78 -> V_60 ;
V_81 . V_50 = NULL ;
if ( V_76 -> V_89 != NULL )
V_81 . V_50 = V_76 -> V_89 ;
}
}
if ( V_8 )
goto V_100;
if ( ( V_76 -> V_41 == NULL ) || ! ( V_76 -> V_101 > 0 ) )
goto V_100;
V_8 = F_24 ( V_23 -> V_36 , & V_83 ) ;
if ( ! V_8 ) {
V_8 = F_25 ( & V_78 -> V_17 , V_83 , NULL ) ;
if ( ! V_8 ) {
V_8 = F_17 ( V_78 -> V_17 ,
( T_2 * * ) & V_76 -> V_41 ,
V_76 -> V_101 ,
V_78 -> V_42 , true ) ;
}
}
V_100:
if ( ! V_8 ) {
V_79 = ( V_73 == V_85 ) ?
V_102 : V_103 ;
V_20 = V_23 -> V_20 ;
V_8 = (* V_20 -> V_104 ) ( & ( V_78 -> V_25 ) ,
V_23 -> V_38 ,
V_79 , V_77 ,
& V_81 ) ;
if ( V_8 ) {
if ( V_8 != - V_18 && V_8 !=
- V_14 && V_8 != - V_87 ) {
V_8 = - V_87 ;
}
}
}
if ( ! V_8 ) {
V_8 = F_26 ( V_78 ,
& V_84 , V_7 ) ;
if ( V_8 )
F_6 ( V_78 ) ;
else
* V_2 = (struct V_1 * ) V_84 ;
} else {
( void ) F_6 ( V_78 ) ;
}
F_8 ( V_31 , L_5
L_6 , V_32 ,
V_72 , V_73 , V_74 , V_76 , V_2 , V_8 ) ;
return V_8 ;
}
int F_27 ( struct V_11 * V_12 , T_2 * * V_105 ,
T_1 * V_106 , T_1 * V_107 , T_1 * V_108 )
{
struct V_19 * V_20 ;
struct V_109 V_110 ;
int V_8 = 0 ;
void * V_65 = NULL ;
if ( ! V_12 ) {
V_8 = - V_15 ;
goto V_16;
}
V_20 = V_12 -> V_23 -> V_20 ;
V_8 =
(* V_20 -> V_111 ) ( V_12 -> V_25 ,
V_12 -> V_60 ,
& V_110 ) ;
if ( ! V_8 ) {
* V_106 = V_110 . V_112 ;
if ( V_107 )
* V_107 = V_110 . V_113 ;
* V_108 = V_110 . V_114 ;
if ( ! F_28 ( V_110 ) ) {
if ( F_29 ( V_110 ) ) {
V_8 = - V_115 ;
} else {
if ( ! F_30 ( V_110 ) )
V_8 = - V_87 ;
}
}
if ( ! V_8
&& ( ! F_30 ( V_110 ) )
&& ( V_12 -> V_43 == V_116 ) ) {
V_65 = F_20 ( V_12 -> V_17 ,
V_110 . V_117 ,
V_118 ) ;
if ( V_65 != NULL ) {
V_65 = F_20 ( V_12 ->
V_17 ,
V_65 ,
V_119 ) ;
}
if ( V_65 == NULL )
V_8 = - V_67 ;
V_110 . V_117 = V_65 ;
}
* V_105 = V_110 . V_117 ;
}
V_16:
F_8 ( V_31 , L_7
L_8 , V_32 , V_12 ,
V_105 , V_106 , V_108 , V_8 ) ;
return V_8 ;
}
int F_31 ( struct V_11 * V_12 , T_1 V_120 ,
T_1 V_121 , struct V_122
* V_123 )
{
struct V_19 * V_20 ;
int V_8 = 0 ;
if ( ! V_12 ) {
V_8 = - V_15 ;
} else if ( ( V_120 & ~ ( ( V_124 ) |
V_125 ) ) != 0 ) {
V_8 = - V_14 ;
} else {
if ( V_121 != V_126 )
V_8 = - V_127 ;
}
if ( ! V_8 ) {
V_20 = V_12 -> V_23 -> V_20 ;
V_8 =
(* V_20 -> V_128 ) ( V_12 ->
V_25 ,
V_120 ,
V_121 ,
V_123 ) ;
}
return V_8 ;
}
int F_32 ( struct V_11 * * V_129 , T_1 V_130 ,
T_1 * V_131 , T_1 V_132 )
{
T_1 V_74 ;
struct V_21 V_22 ;
struct V_19 * V_20 ;
struct V_133 * * V_134 = NULL ;
T_1 V_10 ;
int V_8 = 0 ;
* V_131 = 0 ;
for ( V_10 = 0 ; V_10 < V_130 ; V_10 ++ ) {
if ( ! V_129 [ V_10 ] ) {
V_8 = - V_15 ;
break;
}
}
if ( V_8 )
goto V_16;
for ( V_10 = 0 ; V_10 < V_130 ; V_10 ++ ) {
V_20 = V_129 [ V_10 ] -> V_23 -> V_20 ;
V_8 = (* V_20 -> V_24 ) ( V_129 [ V_10 ] -> V_25 ,
& V_22 ) ;
if ( V_8 ) {
break;
} else {
if ( V_22 . V_26 > 0 )
* V_131 |= ( 1 << V_10 ) ;
}
}
if ( ! V_8 && V_132 > 0 && * V_131 == 0 ) {
V_134 = F_33 ( V_130 * sizeof( struct V_133 * ) ,
V_37 ) ;
if ( V_134 == NULL ) {
V_8 = - V_18 ;
} else {
for ( V_10 = 0 ; V_10 < V_130 ; V_10 ++ ) {
V_20 =
V_129 [ V_10 ] -> V_23 -> V_20 ;
V_8 = (* V_20 -> V_24 )
( V_129 [ V_10 ] -> V_25 , & V_22 ) ;
if ( V_8 )
break;
else
V_134 [ V_10 ] =
V_22 . V_135 ;
}
}
if ( ! V_8 ) {
V_8 =
F_34 ( V_134 , V_130 ,
V_132 , & V_74 ) ;
if ( ! V_8 ) {
F_35 ( V_134 [ V_74 ] ) ;
* V_131 = 1 << V_74 ;
}
}
}
V_16:
F_13 ( V_134 ) ;
return V_8 ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_19 * V_20 ;
int V_8 = 0 ;
if ( V_12 ) {
if ( V_12 -> V_25 ) {
V_20 = V_12 -> V_23 -> V_20 ;
V_8 = (* V_20 -> V_136 )
( V_12 -> V_25 ) ;
}
F_13 ( V_12 -> V_17 ) ;
F_13 ( V_12 ) ;
} else {
V_8 = - V_15 ;
}
return V_8 ;
}
