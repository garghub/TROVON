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
V_26 = F_5 ( ( (struct V_3 * ) V_4 ) -> V_9 ) ;
switch ( V_26 ) {
case V_27 :
F_9 ( V_1 , (struct V_21 * ) V_4 ) ;
break;
case V_28 :
F_10 ( V_1 , (struct V_23 * ) V_4 ) ;
break;
default:
F_3 ( V_1 , L_8 ,
V_26 , V_27 ) ;
F_1 ( V_1 , V_4 ) ;
break;
}
}
int F_12 ( struct V_29 * exp , struct V_3 * * V_2 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = F_13 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
struct V_21 * V_37 ;
struct V_23 * V_38 ;
T_1 V_16 ;
struct V_39 * V_22 ;
int V_40 , V_9 ;
int V_17 ;
int V_41 = 0 ;
if ( V_31 ) {
V_9 = V_31 -> V_42 ;
} else {
if ( V_2 && * V_2 )
V_9 = F_5 ( ( * V_2 ) -> V_9 ) ;
else
V_9 = V_43 ;
}
if ( ( V_9 != V_27 ) &&
( V_9 != V_28 ) ) {
F_14 ( L_9 ,
V_9 , V_27 , V_28 ) ;
return - V_44 ;
}
if ( V_31 ) {
if ( ! V_2 ) {
V_16 = F_15 ( V_35 , V_9 ,
V_31 -> V_45 ) ;
V_31 -> V_45 = V_16 ;
} else if ( ! F_16 ( V_31 ) ) {
V_16 = V_31 -> V_45 ;
} else {
V_16 = 0 ;
}
} else {
V_16 = F_17 (
V_35 -> V_46 . V_47 , V_9 ) ;
if ( V_16 > V_35 -> V_48 . V_49 )
V_16 = V_35 -> V_48 . V_49 ;
}
V_40 = F_18 ( V_16 , V_9 ) ;
if ( ! V_2 )
return V_40 ;
if ( * V_2 && ! V_31 ) {
V_16 = F_6 ( ( * V_2 ) -> V_12 ) ;
V_40 = F_18 ( V_16 , V_9 ) ;
F_19 ( * V_2 , V_40 ) ;
* V_2 = NULL ;
return 0 ;
}
if ( ! * V_2 ) {
F_20 ( * V_2 , V_40 ) ;
if ( ! * V_2 )
return - V_50 ;
}
F_3 ( V_51 , L_10 ,
V_9 , V_40 ) ;
V_37 = * V_2 ;
V_38 = (struct V_23 * ) * V_2 ;
if ( V_9 == V_28 )
V_38 -> V_9 = F_21 ( V_28 ) ;
else
V_37 -> V_9 = F_21 ( V_27 ) ;
if ( ! V_31 )
return V_40 ;
F_22 ( & V_37 -> V_7 , & V_31 -> V_52 ) ;
V_37 -> V_11 = F_21 ( V_31 -> V_53 ) ;
V_37 -> V_12 = F_23 ( V_16 ) ;
V_37 -> V_10 = F_21 ( V_31 -> V_54 ) ;
V_37 -> V_13 = F_23 ( V_31 -> V_55 ) ;
if ( V_31 -> V_42 == V_28 ) {
V_41 = F_24 ( V_38 -> V_25 , V_31 -> V_56 ,
sizeof( V_38 -> V_25 ) ) ;
if ( V_41 >= sizeof( V_38 -> V_25 ) )
return - V_57 ;
V_22 = V_38 -> V_22 ;
} else {
V_22 = V_37 -> V_22 ;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
struct V_58 * V_59 = V_31 -> V_60 [ V_17 ] ;
F_25 ( F_26 ( & V_59 -> V_61 ) != 0 , L_11 V_8
L_12 , F_4 ( & V_37 -> V_7 ) ,
V_17 , V_16 , V_59 -> V_62 ) ;
F_27 ( & V_59 -> V_61 , & V_22 [ V_17 ] . V_19 ) ;
V_22 [ V_17 ] . V_63 = F_21 ( V_59 -> V_64 ) ;
V_22 [ V_17 ] . V_20 = F_21 ( V_59 -> V_62 ) ;
}
return V_40 ;
}
T_1 F_15 ( struct V_34 * V_35 , T_2 V_26 , T_1 V_16 )
{
T_2 V_65 = V_66 ;
if ( ! V_16 )
V_16 = V_35 -> V_48 . V_67 ;
if ( V_16 > V_35 -> V_48 . V_68 )
V_16 = V_35 -> V_48 . V_68 ;
if ( ! V_16 )
V_16 = 1 ;
if ( V_35 -> V_46 . V_69 & V_70 &&
V_35 -> V_46 . V_47 )
V_65 = F_17 (
V_35 -> V_46 . V_47 , V_26 ) ;
if ( V_16 > V_65 )
V_16 = V_65 ;
return V_16 ;
}
static int F_28 ( void * V_4 , int V_71 , T_1 * V_16 )
{
int V_72 ;
if ( F_29 ( F_5 ( * ( T_2 * ) V_4 ) ) == NULL ) {
char * V_73 ;
int V_74 ;
F_14 ( L_13 ,
F_5 ( * ( T_2 * ) V_4 ) , V_71 ) ;
V_74 = V_71 * 2 + 1 ;
F_20 ( V_73 , V_74 ) ;
if ( V_73 != NULL ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_71 ; V_17 ++ )
sprintf ( V_73 + 2 * V_17 , L_14 , ( ( char * ) V_4 ) [ V_17 ] ) ;
V_73 [ V_74 - 1 ] = '\0' ;
F_14 ( L_15 , V_73 ) ;
F_19 ( V_73 , V_74 ) ;
}
return - V_44 ;
}
V_72 = F_29 ( F_5 ( * ( T_2 * ) V_4 ) ) -> F_30 ( V_4 ,
V_71 , V_16 ) ;
return V_72 ;
}
int F_31 ( struct V_30 * * V_75 , T_1 V_16 ,
int V_76 , int V_26 )
{
int V_17 , V_77 ;
F_3 ( V_51 , L_16 , V_16 ) ;
* V_75 = F_32 ( V_16 , & V_77 ) ;
if ( ! * V_75 ) {
F_14 ( L_17 , V_16 ) ;
return - V_50 ;
}
F_33 ( & ( * V_75 ) -> V_78 , 1 ) ;
F_34 ( & ( * V_75 ) -> V_79 ) ;
( * V_75 ) -> V_42 = V_26 ;
( * V_75 ) -> V_45 = V_16 ;
( * V_75 ) -> V_80 = V_81 * V_16 ;
( * V_75 ) -> V_54 = V_76 ;
( * V_75 ) -> V_56 [ 0 ] = '\0' ;
( * V_75 ) -> V_55 = 0 ;
if ( V_16 > 0 )
( * V_75 ) -> V_60 [ 0 ] -> V_62 = ~ 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_35 ( ( * V_75 ) -> V_60 [ V_17 ] ) ;
return V_77 ;
}
int F_36 ( struct V_30 * * V_75 )
{
struct V_30 * V_31 = * V_75 ;
int V_82 ;
* V_75 = NULL ;
F_37 ( F_38 ( & V_31 -> V_78 ) > 0 ) ;
V_82 = F_39 ( & V_31 -> V_78 ) ;
if ( V_82 == 0 ) {
F_37 ( F_29 ( V_31 -> V_42 ) != NULL ) ;
F_29 ( V_31 -> V_42 ) -> F_40 ( V_31 ) ;
}
return V_82 ;
}
int F_41 ( struct V_29 * exp , struct V_30 * * V_75 ,
struct V_3 * V_4 , int V_71 )
{
struct V_32 * V_33 = F_13 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
int V_72 = 0 , V_77 ;
T_1 V_16 ;
T_2 V_26 ;
T_2 V_76 ;
if ( V_4 ) {
V_72 = F_28 ( V_4 , V_71 , & V_16 ) ;
if ( V_72 )
return V_72 ;
V_26 = F_5 ( V_4 -> V_9 ) ;
} else {
V_26 = V_43 ;
V_16 = F_15 ( V_35 , V_26 , 0 ) ;
}
if ( ! V_75 ) {
F_42 () ;
return F_43 ( V_16 ) ;
}
if ( * V_75 && ! V_4 ) {
F_36 ( V_75 ) ;
return 0 ;
}
V_76 = F_5 ( V_4 -> V_10 ) ;
V_77 = F_31 ( V_75 , V_16 , V_76 , V_26 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( ! V_4 )
return V_77 ;
F_37 ( F_29 ( V_26 ) != NULL ) ;
V_72 = F_29 ( V_26 ) -> F_44 ( V_35 , * V_75 , V_4 ) ;
if ( V_72 ) {
F_36 ( V_75 ) ;
return V_72 ;
}
return V_77 ;
}
static int F_45 ( struct V_29 * exp , int V_83 ,
struct V_30 * * V_75 ,
struct V_84 * V_85 )
{
struct V_32 * V_33 = F_13 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
char V_73 [ sizeof( struct V_86 ) ] ;
struct V_86 * V_87 = (struct V_86 * ) & V_73 [ 0 ] ;
struct V_88 * V_89 = (struct V_88 * ) & V_73 [ 0 ] ;
int V_9 ;
T_1 V_16 ;
int V_72 ;
int V_41 = 0 ;
V_72 = F_46 ( V_87 , & V_9 , V_85 ) ;
if ( V_72 )
return V_72 ;
if ( V_89 -> V_10 == 0 ) {
V_89 -> V_10 = V_35 -> V_48 . V_90 ?
V_35 -> V_48 . V_90 : V_91 ;
}
if ( F_47 ( V_89 -> V_10 ) != V_91 ) {
F_3 ( V_92 , L_18 ,
V_89 -> V_10 ) ;
return - V_44 ;
}
if ( V_89 -> V_11 & ( V_93 - 1 ) ) {
F_3 ( V_92 , L_19 ,
V_89 -> V_11 , V_93 ) ;
V_89 -> V_11 = V_93 ;
}
if ( ( V_89 -> V_94 >= V_35 -> V_48 . V_49 ) &&
( V_89 -> V_94 !=
( F_48 ( V_89 -> V_94 ) ) ( - 1 ) ) ) {
F_3 ( V_92 , L_20 ,
V_89 -> V_94 , V_35 -> V_48 . V_49 ) ;
return - V_44 ;
}
V_16 = F_15 ( V_35 , V_9 ,
V_89 -> V_12 ) ;
if ( V_83 ) {
int V_65 = ( V_83 -
F_18 ( 0 , V_9 ) ) /
sizeof( struct V_39 ) ;
if ( F_49 ( V_65 < V_16 ) ) {
F_3 ( V_92 , L_21 ,
V_16 , V_65 ) ;
V_16 = V_65 ;
}
}
if ( V_9 == V_95 ) {
struct V_96 * V_97 ;
V_97 = F_50 ( V_35 , V_87 -> V_25 ) ;
if ( V_97 != NULL ) {
if ( V_87 -> V_94 !=
( F_48 ( V_87 -> V_94 ) ) ( - 1 ) ) {
V_72 = F_51 (
V_87 -> V_94 , V_97 ) ;
if ( V_72 < 0 ) {
F_52 ( V_97 ) ;
return - V_44 ;
}
}
if ( V_16 > F_53 ( V_97 ) )
V_16 = F_53 ( V_97 ) ;
F_52 ( V_97 ) ;
}
}
if ( V_89 -> V_10 & V_98 )
V_16 = 0 ;
V_72 = F_31 ( V_75 , V_16 , V_89 -> V_10 , V_9 ) ;
if ( V_72 >= 0 ) {
( * V_75 ) -> V_60 [ 0 ] -> V_62 = V_89 -> V_94 ;
( * V_75 ) -> V_53 = V_89 -> V_11 ;
if ( V_9 == V_95 ) {
V_41 = F_24 ( ( * V_75 ) -> V_56 ,
V_87 -> V_25 ,
sizeof( ( * V_75 ) -> V_56 ) ) ;
if ( V_41 >= sizeof( ( * V_75 ) -> V_56 ) )
V_72 = - V_57 ;
}
V_72 = 0 ;
}
return V_72 ;
}
int F_54 ( struct V_29 * exp , int V_83 ,
struct V_30 * * V_75 , struct V_84 * V_85 )
{
int V_72 ;
T_3 V_99 ;
V_99 = F_55 () ;
F_56 ( V_100 ) ;
V_72 = F_45 ( exp , V_83 , V_75 , V_85 ) ;
F_56 ( V_99 ) ;
return V_72 ;
}
int F_57 ( struct V_29 * exp , struct V_30 * * V_75 ,
struct V_84 * V_85 )
{
int V_17 ;
int V_72 ;
struct V_29 * V_101 ;
struct V_34 * V_35 = & exp -> V_102 -> V_36 . V_35 ;
T_4 V_103 = 0 ;
struct V_104 * V_22 ;
if ( V_85 -> V_9 == V_95 )
V_22 = ( (struct V_86 * ) V_85 ) -> V_22 ;
else
V_22 = V_85 -> V_22 ;
for ( V_17 = 0 ; V_17 < V_85 -> V_12 ; V_17 ++ ) {
T_2 V_105 = sizeof( V_103 ) ;
V_101 = V_35 -> V_106 [ V_22 [ V_17 ] . V_20 ] -> V_107 ;
V_72 = F_58 ( NULL , V_101 , sizeof( V_108 ) , V_108 ,
& V_105 , & V_103 , NULL ) ;
if ( V_72 )
return V_72 ;
if ( F_26 ( & V_22 [ V_17 ] . V_19 ) > V_103 ) {
F_14 ( L_22
L_23 V_8 L_24 V_109 L_25 ,
V_22 [ V_17 ] . V_20 ,
F_4 ( & V_22 [ V_17 ] . V_19 ) , V_103 ) ;
return - V_44 ;
}
}
V_72 = F_54 ( exp , 0 , V_75 , V_85 ) ;
if ( V_72 )
return V_72 ;
for ( V_17 = 0 ; V_17 < V_85 -> V_12 ; V_17 ++ ) {
( * V_75 ) -> V_60 [ V_17 ] -> V_62 =
V_22 [ V_17 ] . V_20 ;
( * V_75 ) -> V_60 [ V_17 ] -> V_61 = V_22 [ V_17 ] . V_19 ;
}
return 0 ;
}
int F_59 ( struct V_29 * exp , struct V_30 * V_31 ,
struct V_84 * V_85 )
{
struct V_86 V_110 ;
struct V_3 * V_111 = NULL ;
int V_72 , V_40 ;
int V_112 ;
T_3 V_99 ;
if ( ! V_31 )
return - V_113 ;
V_99 = F_55 () ;
F_56 ( V_100 ) ;
V_112 = sizeof( struct V_88 ) ;
if ( F_60 ( & V_110 , V_85 , V_112 ) )
GOTO ( V_114 , V_72 = - V_115 ) ;
else if ( ( V_110 . V_9 != V_116 ) &&
( V_110 . V_9 != V_95 ) )
GOTO ( V_114 , V_72 = - V_44 ) ;
if ( V_110 . V_12 &&
( V_110 . V_12 < V_31 -> V_45 ) ) {
V_110 . V_12 = V_31 -> V_45 ;
V_72 = F_61 ( V_85 , & V_110 , V_112 ) ;
GOTO ( V_114 , V_72 = - V_117 ) ;
}
V_72 = F_12 ( exp , & V_111 , V_31 ) ;
if ( V_72 < 0 )
GOTO ( V_114 , V_72 ) ;
V_40 = V_72 ;
V_72 = 0 ;
F_62 ( sizeof( V_110 ) == sizeof( struct V_23 ) ) ;
F_62 ( sizeof( V_110 . V_22 [ 0 ] ) == sizeof( V_111 -> V_22 [ 0 ] ) ) ;
if ( ( F_21 ( V_43 ) != V_43 ) &&
( ( V_111 -> V_9 == F_21 ( V_27 ) ) ||
( V_111 -> V_9 == F_21 ( V_28 ) ) ) ) {
F_63 ( V_111 ) ;
F_64 (
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
V_112 = sizeof( struct V_86 ) ;
}
if ( V_110 . V_12 == 0 )
V_40 = V_112 ;
else if ( V_110 . V_12 < V_111 -> V_12 )
GOTO ( V_114 , V_72 = - V_117 ) ;
V_110 . V_12 = V_111 -> V_12 ;
V_110 . V_13 = V_111 -> V_13 ;
( (struct V_84 * ) V_111 ) -> V_13 = V_110 . V_13 ;
( (struct V_84 * ) V_111 ) -> V_12 = V_110 . V_12 ;
if ( F_61 ( V_85 , V_111 , V_40 ) )
V_72 = - V_115 ;
F_65 ( exp , & V_111 ) ;
V_114:
F_56 ( V_99 ) ;
return V_72 ;
}
