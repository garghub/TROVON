int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 =
(struct V_8 * ) V_3 ;
struct V_10 * V_11 = V_10 ( V_5 ) ;
switch ( V_9 -> V_9 ) {
case V_12 :
V_9 -> V_13 = F_3 ( V_7 ) ;
break;
case V_14 :
V_9 -> V_13 = F_4 ( V_7 ) ;
break;
case V_15 :
V_9 -> V_13 = F_5 ( V_7 ) ? 1 : 0 ;
break;
case V_16 :
V_9 -> V_13 = V_7 -> V_17 ;
break;
case V_18 :
V_9 -> V_13 = V_7 -> V_19 . V_17 ;
break;
case V_20 :
V_9 -> V_13 = V_7 -> V_21 ;
break;
case V_22 :
{
T_1 T_2 * V_23 = V_7 -> V_24 ;
const struct V_25 * V_19 = & V_7 -> V_19 ;
if ( ( V_7 -> V_17 & V_26 ) ) {
V_9 -> V_13 = V_27 ;
break;
}
V_9 -> V_13 =
F_6 ( V_23 +
( ( V_19 -> V_17 &
V_28 ) ?
V_29 :
V_30 ) ) ;
break;
}
case V_31 :
if ( ( V_7 -> V_17 & V_26 ) &&
! V_11 -> V_32 )
V_9 -> V_13 = V_7 -> V_33 * V_34 / 2 ;
else
V_9 -> V_13 = V_7 -> V_35 ;
break;
case V_36 :
if ( ( V_7 -> V_17 & V_26 ) &&
V_11 -> V_32 )
V_9 -> V_13 = V_37 * sizeof( V_38 ) ;
else if ( V_7 -> V_17 & V_26 )
V_9 -> V_13 = sizeof( struct V_39 ) +
sizeof( V_38 ) ;
else
V_9 -> V_13 = ( V_40 -
V_41 + 1 ) *
sizeof( V_38 ) ;
break;
case V_42 :
V_11 -> V_32 = true ;
V_9 -> V_13 = V_7 -> V_33 * V_34 ;
break;
case V_43 :
V_9 -> V_13 = V_7 -> V_44 ;
break;
case V_45 :
V_9 -> V_13 =
( V_7 -> V_46 == V_47 ) ;
break;
case V_48 :
V_9 -> V_13 = V_7 -> V_49 ;
break;
default:
F_7 ( L_1 ,
V_9 -> V_9 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , void * V_51 ,
T_3 V_52 )
{
struct V_39 * V_53 =
(struct V_39 * ) V_51 ;
unsigned int V_54 ;
T_3 V_55 = F_9 ( struct V_39 , V_56 ) ;
unsigned int V_57 ;
if ( V_52 < V_55 )
return - V_50 ;
V_57 = ( V_52 - V_55 ) / sizeof( V_58 ) ;
if ( V_57 > V_37 )
V_57 = V_37 ;
V_53 -> V_59 . V_60 =
( V_55 + V_57 * sizeof( V_58 ) ) / sizeof( T_1 ) ;
V_53 -> V_59 . type = V_61 ;
F_10 ( & V_7 -> V_62 ) ;
for ( V_54 = 0 ; V_54 < V_57 ; ++ V_54 ) {
F_11 ( V_7 , V_63 , V_54 ) ;
V_53 -> V_56 [ V_54 ] [ 0 ] = V_54 ;
V_53 -> V_56 [ V_54 ] [ 1 ] = F_12 ( V_7 , V_63 ) ;
}
F_13 ( & V_7 -> V_62 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_64 * V_65 =
(struct V_64 * ) V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_38 V_52 ;
T_1 T_2 * V_23 ;
void T_4 * V_66 = ( void T_4 * ) ( ( unsigned long ) ( V_65 -> V_66 ) ) ;
void * V_51 ;
int V_67 ;
bool V_68 = ! ! ( V_7 -> V_17 & V_26 ) ;
struct V_10 * V_11 = V_10 ( V_5 ) ;
if ( F_15 ( V_65 -> V_69 != 0 ) ) {
F_7 ( L_2 ) ;
return - V_50 ;
}
if ( V_68 && V_11 -> V_32 )
V_52 = V_37 * sizeof( V_38 ) ;
else if ( V_68 )
V_52 = sizeof( struct V_39 ) + sizeof( V_38 ) ;
else
V_52 = ( V_40 - V_41 + 1 ) *
sizeof( V_38 ) ;
if ( V_65 -> V_57 < V_52 )
V_52 = V_65 -> V_57 ;
V_51 = F_16 ( V_52 ) ;
if ( F_15 ( V_51 == NULL ) ) {
F_7 ( L_3 ) ;
return - V_70 ;
}
if ( V_68 && V_11 -> V_32 ) {
int V_54 , V_71 ;
V_38 * V_72 = ( V_38 * ) V_51 ;
V_71 = V_52 / sizeof( V_38 ) ;
if ( V_71 > V_37 )
V_71 = V_37 ;
F_10 ( & V_7 -> V_62 ) ;
for ( V_54 = 0 ; V_54 < V_71 ; ++ V_54 ) {
F_11 ( V_7 , V_63 , V_54 ) ;
* V_72 ++ = F_12 ( V_7 , V_63 ) ;
}
F_13 ( & V_7 -> V_62 ) ;
} else if ( V_68 ) {
V_67 = F_8 ( V_7 , V_51 , V_52 ) ;
if ( F_15 ( V_67 != 0 ) )
goto V_73;
} else {
V_23 = V_7 -> V_24 ;
F_17 ( V_51 , & V_23 [ V_41 ] , V_52 ) ;
}
V_67 = F_18 ( V_66 , V_51 , V_52 ) ;
if ( V_67 )
V_67 = - V_74 ;
V_73:
F_19 ( V_51 ) ;
if ( F_15 ( V_67 != 0 ) )
F_7 ( L_4 ) ;
return V_67 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_75 * V_76 = V_10 ( V_5 ) -> V_76 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_77 * V_65 =
(struct V_77 * ) V_3 ;
struct V_78 * V_79 ;
struct V_80 T_4 * V_81 ;
struct V_80 * V_82 = NULL ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
V_38 V_89 ;
int V_67 ;
V_89 = V_65 -> V_89 ;
V_81 = (struct V_80 T_4 * ) ( unsigned long ) V_65 -> V_81 ;
if ( F_15 ( V_89 == 0 ) )
return 0 ;
if ( V_81 == NULL ) {
F_7 ( L_5 ) ;
V_67 = - V_50 ;
goto V_90;
}
V_82 = F_21 ( V_89 , sizeof( * V_82 ) , V_91 ) ;
if ( V_82 == NULL ) {
F_7 ( L_6 ) ;
V_67 = - V_70 ;
goto V_90;
}
V_67 = F_22 ( V_82 , V_81 , V_89 * sizeof( * V_82 ) ) ;
if ( V_67 ) {
F_7 ( L_7 ) ;
V_67 = - V_74 ;
goto V_92;
}
F_23 ( V_2 ) ;
V_84 = F_24 ( V_2 , V_65 -> V_93 ) ;
if ( ! V_84 ) {
F_7 ( L_8 ) ;
V_67 = - V_94 ;
goto V_95;
}
V_86 = F_25 ( V_84 ) ;
V_67 = F_26 ( & V_7 -> V_96 , true ) ;
if ( F_15 ( V_67 != 0 ) )
goto V_97;
V_67 = F_27 ( V_7 , V_76 , V_65 -> V_98 ,
V_99 ,
& V_88 ) ;
if ( V_67 )
goto V_100;
V_79 = F_28 ( V_88 ) ;
V_67 = F_29 ( V_7 , V_5 ,
V_86 , V_79 , V_65 -> V_98 ,
V_65 -> V_101 , V_65 -> V_102 ,
V_82 , V_89 ) ;
F_30 ( & V_79 ) ;
V_100:
F_31 ( & V_7 -> V_96 ) ;
V_97:
F_32 ( V_84 ) ;
V_95:
F_33 ( V_2 ) ;
V_92:
F_34 ( V_82 ) ;
V_90:
return V_67 ;
}
int F_35 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_103 * V_65 =
(struct V_103 * ) V_3 ;
struct V_104 T_4 * V_105 =
(struct V_104 T_4 * )
( unsigned long ) V_65 -> V_106 ;
struct V_80 T_4 * V_81 ;
struct V_80 * V_82 = NULL ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
V_38 V_89 ;
int V_67 ;
V_89 = V_65 -> V_89 ;
V_81 = (struct V_80 T_4 * ) ( unsigned long ) V_65 -> V_81 ;
if ( F_15 ( V_89 == 0 ) )
return 0 ;
if ( V_81 == NULL ) {
F_7 ( L_9 ) ;
V_67 = - V_50 ;
goto V_90;
}
V_82 = F_21 ( V_89 , sizeof( * V_82 ) , V_91 ) ;
if ( V_82 == NULL ) {
F_7 ( L_6 ) ;
V_67 = - V_70 ;
goto V_90;
}
V_67 = F_22 ( V_82 , V_81 , V_89 * sizeof( * V_82 ) ) ;
if ( V_67 ) {
F_7 ( L_7 ) ;
V_67 = - V_74 ;
goto V_92;
}
F_23 ( V_2 ) ;
V_84 = F_24 ( V_2 , V_65 -> V_93 ) ;
if ( ! V_84 ) {
F_7 ( L_8 ) ;
V_67 = - V_94 ;
goto V_95;
}
V_86 = F_25 ( V_84 ) ;
if ( ! V_86 -> V_107 ) {
F_7 ( L_10 ) ;
V_67 = - V_50 ;
goto V_97;
}
V_67 = F_26 ( & V_7 -> V_96 , true ) ;
if ( F_15 ( V_67 != 0 ) )
goto V_97;
V_67 = F_36 ( V_7 , V_5 ,
V_86 , V_105 ,
V_82 , V_89 ) ;
F_31 ( & V_7 -> V_96 ) ;
V_97:
F_32 ( V_84 ) ;
V_95:
F_33 ( V_2 ) ;
V_92:
F_34 ( V_82 ) ;
V_90:
return V_67 ;
}
unsigned int F_37 ( struct V_108 * V_109 , struct V_110 * V_111 )
{
struct V_4 * V_5 = V_109 -> V_112 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_113 -> V_2 ) ;
F_38 ( V_7 , V_114 ) ;
return F_39 ( V_109 , V_111 ) ;
}
T_5 F_40 ( struct V_108 * V_109 , char T_4 * V_66 ,
T_3 V_115 , T_6 * V_116 )
{
struct V_4 * V_5 = V_109 -> V_112 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_113 -> V_2 ) ;
F_38 ( V_7 , V_114 ) ;
return F_41 ( V_109 , V_66 , V_115 , V_116 ) ;
}
