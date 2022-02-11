void F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 V_6 ;
F_2 ( & V_6 , & V_4 -> V_7 ) ;
F_3 ( V_1 , L_1 V_8 L_2 ,
F_4 ( & V_6 ) , F_5 ( V_4 -> V_9 ) ,
F_5 ( V_4 -> V_10 ) ) ;
F_3 ( V_1 , L_3 ,
F_5 ( V_4 -> V_11 ) ,
F_6 ( V_4 -> V_12 ) ,
F_6 ( V_4 -> V_13 ) ) ;
}
static void F_7 ( int V_1 , struct V_14 * V_15 ,
int V_16 )
{
int V_17 ;
if ( V_16 > V_18 ) {
F_3 ( V_1 , L_4 ,
V_16 , V_18 ) ;
return;
}
for ( V_17 = 0 ; V_17 < V_16 ; ++ V_17 , ++ V_15 ) {
struct V_5 V_6 ;
F_8 ( & V_15 -> V_19 , & V_6 ) ;
F_3 ( V_1 , L_5 V_8 L_6 , V_17 ,
F_5 ( V_15 -> V_20 ) , F_4 ( & V_6 ) ) ;
}
}
void F_9 ( int V_1 , struct V_21 * V_4 )
{
F_1 ( V_1 , V_4 ) ;
F_7 ( V_1 , V_4 -> V_22 ,
F_6 ( V_4 -> V_12 ) ) ;
}
void F_10 ( int V_1 , struct V_23 * V_4 )
{
F_1 ( V_1 , V_4 ) ;
F_3 ( V_1 , L_7 V_24 L_6 , V_4 -> V_25 ) ;
F_7 ( V_1 , V_4 -> V_22 ,
F_6 ( V_4 -> V_12 ) ) ;
}
void F_11 ( int V_1 , void * V_4 )
{
int V_26 ;
V_26 = ( (struct V_21 * ) ( V_4 ) ) -> V_9 ;
switch ( V_26 ) {
case V_27 :
return F_9 ( V_1 , (struct V_21 * ) ( V_4 ) ) ;
case V_28 :
return F_10 ( V_1 , (struct V_23 * ) ( V_4 ) ) ;
default:
F_12 ( L_8 , V_26 ) ;
}
return;
}
int F_13 ( struct V_29 * exp , struct V_3 * * V_2 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = F_14 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
struct V_21 * V_37 ;
struct V_23 * V_38 ;
T_1 V_16 ;
struct V_39 * V_22 ;
int V_40 , V_9 ;
int V_17 ;
int V_41 = 0 ;
V_42 ;
if ( V_31 ) {
V_9 = V_31 -> V_43 ;
} else {
if ( V_2 && * V_2 )
V_9 = F_5 ( ( * V_2 ) -> V_9 ) ;
else
V_9 = V_44 ;
}
if ( ( V_9 != V_27 ) &&
( V_9 != V_28 ) ) {
F_12 ( L_9 ,
V_9 , V_27 , V_28 ) ;
RETURN ( - V_45 ) ;
}
if ( V_31 ) {
if ( ! V_2 ) {
V_16 = F_15 ( V_35 , V_9 ,
V_31 -> V_46 ) ;
V_31 -> V_46 = V_16 ;
} else {
V_16 = V_31 -> V_46 ;
}
} else {
V_16 = F_16 ( V_35 -> V_47 . V_48 ,
V_9 ) ;
if ( V_16 > V_35 -> V_49 . V_50 )
V_16 = V_35 -> V_49 . V_50 ;
}
V_40 = F_17 ( V_16 , V_9 ) ;
if ( ! V_2 )
RETURN ( V_40 ) ;
if ( * V_2 && ! V_31 ) {
V_16 = F_6 ( ( * V_2 ) -> V_12 ) ;
V_40 = F_17 ( V_16 , V_9 ) ;
F_18 ( * V_2 , V_40 ) ;
* V_2 = NULL ;
RETURN ( 0 ) ;
}
if ( ! * V_2 ) {
F_19 ( * V_2 , V_40 ) ;
if ( ! * V_2 )
RETURN ( - V_51 ) ;
}
F_3 ( V_52 , L_10 ,
V_9 , V_40 ) ;
V_37 = * V_2 ;
V_38 = (struct V_23 * ) * V_2 ;
if ( V_9 == V_28 )
V_38 -> V_9 = F_20 ( V_28 ) ;
else
V_37 -> V_9 = F_20 ( V_27 ) ;
if ( ! V_31 )
RETURN ( V_40 ) ;
F_21 ( & V_37 -> V_7 , & V_31 -> V_53 ) ;
V_37 -> V_11 = F_20 ( V_31 -> V_54 ) ;
V_37 -> V_12 = F_22 ( V_16 ) ;
V_37 -> V_10 = F_20 ( V_31 -> V_55 ) ;
V_37 -> V_13 = F_22 ( V_31 -> V_56 ) ;
if ( V_31 -> V_43 == V_28 ) {
V_41 = F_23 ( V_38 -> V_25 , V_31 -> V_57 ,
sizeof( V_38 -> V_25 ) ) ;
if ( V_41 >= sizeof( V_38 -> V_25 ) )
RETURN ( - V_58 ) ;
V_22 = V_38 -> V_22 ;
} else {
V_22 = V_37 -> V_22 ;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
struct V_59 * V_60 = V_31 -> V_61 [ V_17 ] ;
F_24 ( F_25 ( & V_60 -> V_62 ) != 0 , L_11 V_8
L_12 , F_4 ( & V_37 -> V_7 ) ,
V_17 , V_16 , V_60 -> V_63 ) ;
F_26 ( & V_60 -> V_62 , & V_22 [ V_17 ] . V_19 ) ;
V_22 [ V_17 ] . V_64 = F_20 ( V_60 -> V_65 ) ;
V_22 [ V_17 ] . V_20 = F_20 ( V_60 -> V_63 ) ;
}
RETURN ( V_40 ) ;
}
T_1 F_15 ( struct V_34 * V_35 , T_2 V_26 , T_1 V_16 )
{
T_2 V_66 = V_67 ;
if ( ! V_16 )
V_16 = V_35 -> V_49 . V_68 ;
if ( V_16 > V_35 -> V_49 . V_69 )
V_16 = V_35 -> V_49 . V_69 ;
if ( ! V_16 )
V_16 = 1 ;
if ( V_35 -> V_47 . V_70 & V_71 &&
V_35 -> V_47 . V_48 )
V_66 = F_16 ( V_35 -> V_47 . V_48 ,
V_26 ) ;
if ( V_16 > V_66 )
V_16 = V_66 ;
return V_16 ;
}
static int F_27 ( void * V_4 , int V_72 , T_1 * V_16 )
{
int V_73 ;
if ( F_28 ( F_5 ( * ( T_2 * ) V_4 ) ) == NULL ) {
char * V_74 ;
int V_75 ;
F_12 ( L_13 ,
F_5 ( * ( T_2 * ) V_4 ) , V_72 ) ;
V_75 = V_72 * 2 + 1 ;
F_19 ( V_74 , V_75 ) ;
if ( V_74 != NULL ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_72 ; V_17 ++ )
sprintf ( V_74 + 2 * V_17 , L_14 , ( ( char * ) V_4 ) [ V_17 ] ) ;
V_74 [ V_75 - 1 ] = '\0' ;
F_12 ( L_15 , V_74 ) ;
F_18 ( V_74 , V_75 ) ;
}
return - V_45 ;
}
V_73 = F_28 ( F_5 ( * ( T_2 * ) V_4 ) ) -> F_29 ( V_4 ,
V_72 , V_16 ) ;
return V_73 ;
}
int F_30 ( struct V_30 * * V_76 , T_1 V_16 ,
int V_77 , int V_26 )
{
int V_17 , V_78 ;
V_42 ;
F_3 ( V_52 , L_16 , V_16 ) ;
* V_76 = F_31 ( V_16 , & V_78 ) ;
if ( ! * V_76 ) {
F_12 ( L_17 , V_16 ) ;
RETURN ( - V_51 ) ;
}
F_32 ( & ( * V_76 ) -> V_79 , 1 ) ;
F_33 ( & ( * V_76 ) -> V_80 ) ;
( * V_76 ) -> V_43 = V_26 ;
( * V_76 ) -> V_46 = V_16 ;
( * V_76 ) -> V_81 = V_82 * V_16 ;
( * V_76 ) -> V_55 = V_77 ;
( * V_76 ) -> V_57 [ 0 ] = '\0' ;
( * V_76 ) -> V_56 = 0 ;
( * V_76 ) -> V_61 [ 0 ] -> V_63 = ~ 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_34 ( ( * V_76 ) -> V_61 [ V_17 ] ) ;
RETURN ( V_78 ) ;
}
int F_35 ( struct V_30 * * V_76 )
{
struct V_30 * V_31 = * V_76 ;
int V_83 ;
* V_76 = NULL ;
F_36 ( F_37 ( & V_31 -> V_79 ) > 0 ) ;
if ( ( V_83 = F_38 ( & V_31 -> V_79 ) ) == 0 ) {
F_36 ( F_28 ( V_31 -> V_43 ) != NULL ) ;
F_28 ( V_31 -> V_43 ) -> F_39 ( V_31 ) ;
}
return V_83 ;
}
int F_40 ( struct V_29 * exp , struct V_30 * * V_76 ,
struct V_3 * V_4 , int V_72 )
{
struct V_32 * V_33 = F_14 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
int V_73 = 0 , V_78 ;
T_1 V_16 ;
T_2 V_26 ;
V_42 ;
if ( V_4 ) {
V_73 = F_27 ( V_4 , V_72 , & V_16 ) ;
if ( V_73 )
RETURN ( V_73 ) ;
V_26 = F_5 ( V_4 -> V_9 ) ;
} else {
V_26 = V_44 ;
V_16 = F_15 ( V_35 , V_26 , 0 ) ;
}
if ( ! V_76 ) {
F_41 () ;
RETURN ( F_42 ( V_16 ) ) ;
}
if ( * V_76 && ! V_4 ) {
F_35 ( V_76 ) ;
RETURN ( 0 ) ;
}
V_78 = F_30 ( V_76 , V_16 , V_84 ,
V_26 ) ;
if ( V_78 < 0 )
RETURN ( V_78 ) ;
if ( ! V_4 )
RETURN ( V_78 ) ;
F_36 ( F_28 ( V_26 ) != NULL ) ;
V_73 = F_28 ( V_26 ) -> F_43 ( V_35 , * V_76 , V_4 ) ;
if ( V_73 ) {
F_35 ( V_76 ) ;
RETURN ( V_73 ) ;
}
RETURN ( V_78 ) ;
}
static int F_44 ( struct V_29 * exp , int V_85 ,
struct V_30 * * V_76 ,
struct V_86 * V_87 )
{
struct V_32 * V_33 = F_14 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
char V_74 [ sizeof( struct V_88 ) ] ;
struct V_88 * V_89 = (struct V_88 * ) & V_74 [ 0 ] ;
struct V_90 * V_91 = (struct V_90 * ) & V_74 [ 0 ] ;
int V_9 ;
T_1 V_16 ;
int V_73 ;
int V_41 = 0 ;
V_42 ;
V_73 = F_45 ( V_89 , & V_9 , V_87 ) ;
if ( V_73 )
RETURN ( V_73 ) ;
if ( V_91 -> V_10 == 0 ) {
V_91 -> V_10 = V_35 -> V_49 . V_92 ?
V_35 -> V_49 . V_92 : V_84 ;
}
if ( V_91 -> V_10 != V_84 ) {
F_3 ( V_93 , L_18 ,
V_91 -> V_10 ) ;
RETURN ( - V_45 ) ;
}
if ( V_91 -> V_11 & ( V_94 - 1 ) ) {
F_3 ( V_93 , L_19 ,
V_91 -> V_11 , V_94 ) ;
V_91 -> V_11 = V_94 ;
}
if ( ( V_91 -> V_95 >= V_35 -> V_49 . V_50 ) &&
( V_91 -> V_95 !=
( F_46 ( V_91 -> V_95 ) ) ( - 1 ) ) ) {
F_3 ( V_93 , L_20 ,
V_91 -> V_95 , V_35 -> V_49 . V_50 ) ;
RETURN ( - V_45 ) ;
}
V_16 = F_15 ( V_35 , V_9 ,
V_91 -> V_12 ) ;
if ( V_85 ) {
int V_66 = ( V_85 -
F_17 ( 0 , V_9 ) ) /
sizeof( struct V_39 ) ;
if ( F_47 ( V_66 < V_16 ) ) {
F_3 ( V_93 , L_21 ,
V_16 , V_66 ) ;
V_16 = V_66 ;
}
}
if ( V_9 == V_96 ) {
struct V_97 * V_98 ;
V_98 = F_48 ( V_35 , V_89 -> V_25 ) ;
if ( V_98 != NULL ) {
if ( V_89 -> V_95 !=
( F_46 ( V_89 -> V_95 ) ) ( - 1 ) ) {
V_73 = F_49 (
V_89 -> V_95 , V_98 ) ;
if ( V_73 < 0 ) {
F_50 ( V_98 ) ;
RETURN ( - V_45 ) ;
}
}
if ( V_16 > F_51 ( V_98 ) )
V_16 = F_51 ( V_98 ) ;
F_50 ( V_98 ) ;
}
}
V_73 = F_30 ( V_76 , V_16 , V_91 -> V_10 , V_9 ) ;
if ( V_73 >= 0 ) {
( * V_76 ) -> V_61 [ 0 ] -> V_63 = V_91 -> V_95 ;
( * V_76 ) -> V_54 = V_91 -> V_11 ;
if ( V_9 == V_96 ) {
V_41 = F_23 ( ( * V_76 ) -> V_57 ,
V_89 -> V_25 ,
sizeof( ( * V_76 ) -> V_57 ) ) ;
if ( V_41 >= sizeof( ( * V_76 ) -> V_57 ) )
V_73 = - V_58 ;
}
V_73 = 0 ;
}
RETURN ( V_73 ) ;
}
int F_52 ( struct V_29 * exp , int V_85 ,
struct V_30 * * V_76 , struct V_86 * V_87 )
{
int V_73 ;
T_3 V_99 ;
V_99 = F_53 () ;
F_54 ( V_100 ) ;
V_73 = F_44 ( exp , V_85 , V_76 , V_87 ) ;
F_54 ( V_99 ) ;
RETURN ( V_73 ) ;
}
int F_55 ( struct V_29 * exp , struct V_30 * * V_76 ,
struct V_86 * V_87 )
{
int V_17 ;
int V_73 ;
struct V_29 * V_101 ;
struct V_34 * V_35 = & exp -> V_102 -> V_36 . V_35 ;
T_4 V_103 = 0 ;
struct V_104 * V_22 ;
V_42 ;
if ( V_87 -> V_9 == V_96 )
V_22 = ( (struct V_88 * ) V_87 ) -> V_22 ;
else
V_22 = V_87 -> V_22 ;
for ( V_17 = 0 ; V_17 < V_87 -> V_12 ; V_17 ++ ) {
T_2 V_105 = sizeof( V_103 ) ;
V_101 = V_35 -> V_106 [ V_22 [ V_17 ] . V_20 ] -> V_107 ;
V_73 = F_56 ( NULL , V_101 , sizeof( V_108 ) , V_108 ,
& V_105 , & V_103 , NULL ) ;
if ( V_73 )
RETURN ( V_73 ) ;
if ( F_25 ( & V_22 [ V_17 ] . V_19 ) > V_103 ) {
F_12 ( L_22
L_23 V_8 L_24 V_109 L_25 ,
V_22 [ V_17 ] . V_20 ,
F_4 ( & V_22 [ V_17 ] . V_19 ) , V_103 ) ;
RETURN ( - V_45 ) ;
}
}
V_73 = F_52 ( exp , 0 , V_76 , V_87 ) ;
if ( V_73 )
RETURN ( V_73 ) ;
for ( V_17 = 0 ; V_17 < V_87 -> V_12 ; V_17 ++ ) {
( * V_76 ) -> V_61 [ V_17 ] -> V_63 =
V_22 [ V_17 ] . V_20 ;
( * V_76 ) -> V_61 [ V_17 ] -> V_62 = V_22 [ V_17 ] . V_19 ;
}
RETURN ( 0 ) ;
}
int F_57 ( struct V_29 * exp , struct V_30 * V_31 ,
struct V_86 * V_87 )
{
struct V_88 V_110 ;
struct V_3 * V_111 = NULL ;
int V_73 , V_40 ;
int V_112 ;
T_3 V_99 ;
V_42 ;
if ( ! V_31 )
RETURN ( - V_113 ) ;
V_99 = F_53 () ;
F_54 ( V_100 ) ;
V_112 = sizeof( struct V_90 ) ;
if ( F_58 ( & V_110 , V_87 , V_112 ) )
GOTO ( V_114 , V_73 = - V_115 ) ;
else if ( ( V_110 . V_9 != V_116 ) &&
( V_110 . V_9 != V_96 ) )
GOTO ( V_114 , V_73 = - V_45 ) ;
if ( V_110 . V_12 &&
( V_110 . V_12 < V_31 -> V_46 ) ) {
V_110 . V_12 = V_31 -> V_46 ;
V_73 = F_59 ( V_87 , & V_110 , V_112 ) ;
GOTO ( V_114 , V_73 = - V_117 ) ;
}
V_73 = F_13 ( exp , & V_111 , V_31 ) ;
if ( V_73 < 0 )
GOTO ( V_114 , V_73 ) ;
V_40 = V_73 ;
V_73 = 0 ;
F_60 ( sizeof( V_110 ) == sizeof( struct V_23 ) ) ;
F_60 ( sizeof V_110 . V_22 [ 0 ] == sizeof V_111 -> V_22 [ 0 ] ) ;
if ( ( F_20 ( V_44 ) != V_44 ) &&
( ( V_111 -> V_9 == F_20 ( V_27 ) ) ||
( V_111 -> V_9 == F_20 ( V_28 ) ) ) ) {
F_61 ( V_111 ) ;
F_62 (
(struct V_118 * ) V_111 -> V_22 ,
V_111 -> V_12 ) ;
}
if ( V_110 . V_9 == V_116 ) {
if ( V_111 -> V_9 == V_28 ) {
memmove ( ( char * ) ( & V_111 -> V_12 ) +
sizeof( V_111 -> V_12 ) ,
( (struct V_23 * ) V_111 ) -> V_22 ,
V_111 -> V_12 *
sizeof( struct V_39 ) ) ;
V_40 -= V_119 ;
}
} else {
V_112 = sizeof( struct V_88 ) ;
}
if ( V_110 . V_12 == 0 )
V_40 = V_112 ;
else if ( V_110 . V_12 < V_111 -> V_12 )
GOTO ( V_114 , V_73 = - V_117 ) ;
V_110 . V_12 = V_111 -> V_12 ;
V_110 . V_13 = V_111 -> V_13 ;
( (struct V_86 * ) V_111 ) -> V_13 = V_110 . V_13 ;
( (struct V_86 * ) V_111 ) -> V_12 = V_110 . V_12 ;
if ( F_59 ( V_87 , V_111 , V_40 ) )
V_73 = - V_115 ;
F_63 ( exp , & V_111 ) ;
V_114:
F_54 ( V_99 ) ;
RETURN ( V_73 ) ;
}
