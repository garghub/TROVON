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
T_1 * V_23 = V_7 -> V_24 ;
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
return - V_50 ;
}
return 0 ;
}
static T_1 F_7 ( unsigned int V_51 , T_1 V_52 )
{
F_8 ( V_53 + 1 != V_37 ) ;
if ( V_51 >= V_54 &&
V_51 <= V_53 )
V_52 &= ~ ( V_55 |
V_56 |
V_57 ) ;
else if ( V_51 == V_58 )
return 0 ;
return V_52 ;
}
static int F_9 ( struct V_6 * V_7 , void * V_59 ,
T_2 V_60 )
{
struct V_39 * V_61 =
(struct V_39 * ) V_59 ;
unsigned int V_62 ;
T_2 V_63 = F_10 ( struct V_39 , V_64 ) ;
unsigned int V_65 ;
if ( V_60 < V_63 )
return - V_50 ;
V_65 = ( V_60 - V_63 ) / sizeof( V_66 ) ;
if ( V_65 > V_37 )
V_65 = V_37 ;
V_61 -> V_67 . V_68 =
( V_63 + V_65 * sizeof( V_66 ) ) / sizeof( T_1 ) ;
V_61 -> V_67 . type = V_69 ;
F_11 ( & V_7 -> V_70 ) ;
for ( V_62 = 0 ; V_62 < V_65 ; ++ V_62 ) {
F_12 ( V_7 , V_71 , V_62 ) ;
V_61 -> V_64 [ V_62 ] [ 0 ] = V_62 ;
V_61 -> V_64 [ V_62 ] [ 1 ] = F_7
( V_62 , F_13 ( V_7 , V_71 ) ) ;
}
F_14 ( & V_7 -> V_70 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_72 * V_73 =
(struct V_72 * ) V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_38 V_60 ;
T_1 * V_23 ;
void T_3 * V_74 = ( void T_3 * ) ( ( unsigned long ) ( V_73 -> V_74 ) ) ;
void * V_59 ;
int V_75 ;
bool V_76 = ! ! ( V_7 -> V_17 & V_26 ) ;
struct V_10 * V_11 = V_10 ( V_5 ) ;
if ( F_16 ( V_73 -> V_77 != 0 || V_73 -> V_65 == 0 ) ) {
F_17 ( L_1 ) ;
return - V_50 ;
}
if ( V_76 && V_11 -> V_32 )
V_60 = V_37 * sizeof( V_38 ) ;
else if ( V_76 )
V_60 = sizeof( struct V_39 ) + sizeof( V_38 ) ;
else
V_60 = ( V_40 - V_41 + 1 ) *
sizeof( V_38 ) ;
if ( V_73 -> V_65 < V_60 )
V_60 = V_73 -> V_65 ;
V_59 = F_18 ( V_60 ) ;
if ( F_16 ( V_59 == NULL ) ) {
F_17 ( L_2 ) ;
return - V_78 ;
}
if ( V_76 && V_11 -> V_32 ) {
int V_62 , V_79 ;
V_38 * V_80 = ( V_38 * ) V_59 ;
V_79 = V_60 / sizeof( V_38 ) ;
if ( V_79 > V_37 )
V_79 = V_37 ;
F_11 ( & V_7 -> V_70 ) ;
for ( V_62 = 0 ; V_62 < V_79 ; ++ V_62 ) {
F_12 ( V_7 , V_71 , V_62 ) ;
* V_80 ++ = F_7
( V_62 , F_13 ( V_7 , V_71 ) ) ;
}
F_14 ( & V_7 -> V_70 ) ;
} else if ( V_76 ) {
V_75 = F_9 ( V_7 , V_59 , V_60 ) ;
if ( F_16 ( V_75 != 0 ) )
goto V_81;
} else {
V_23 = V_7 -> V_24 ;
memcpy ( V_59 , & V_23 [ V_41 ] , V_60 ) ;
}
V_75 = F_19 ( V_74 , V_59 , V_60 ) ;
if ( V_75 )
V_75 = - V_82 ;
V_81:
F_20 ( V_59 ) ;
if ( F_16 ( V_75 != 0 ) )
F_17 ( L_3 ) ;
return V_75 ;
}
int F_21 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_83 * V_84 = V_10 ( V_5 ) -> V_84 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_85 * V_73 =
(struct V_85 * ) V_3 ;
struct V_86 * V_87 ;
struct V_88 T_3 * V_89 ;
struct V_88 * V_90 = NULL ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
V_38 V_97 ;
int V_75 ;
V_97 = V_73 -> V_97 ;
V_89 = (struct V_88 T_3 * ) ( unsigned long ) V_73 -> V_89 ;
if ( F_16 ( V_97 == 0 ) )
return 0 ;
if ( V_89 == NULL ) {
F_17 ( L_4 ) ;
V_75 = - V_50 ;
goto V_98;
}
V_90 = F_22 ( V_97 , sizeof( * V_90 ) , V_99 ) ;
if ( V_90 == NULL ) {
F_17 ( L_5 ) ;
V_75 = - V_78 ;
goto V_98;
}
V_75 = F_23 ( V_90 , V_89 , V_97 * sizeof( * V_90 ) ) ;
if ( V_75 ) {
F_17 ( L_6 ) ;
V_75 = - V_82 ;
goto V_100;
}
F_24 ( V_2 ) ;
V_92 = F_25 ( V_2 , V_73 -> V_101 ) ;
if ( ! V_92 ) {
F_17 ( L_7 ) ;
V_75 = - V_102 ;
goto V_103;
}
V_94 = F_26 ( V_92 ) ;
V_75 = F_27 ( & V_7 -> V_104 , true ) ;
if ( F_16 ( V_75 != 0 ) )
goto V_105;
V_75 = F_28 ( V_7 , V_84 , V_73 -> V_106 ,
V_107 ,
& V_96 ) ;
if ( V_75 )
goto V_108;
V_87 = F_29 ( V_96 ) ;
V_75 = F_30 ( V_7 , V_5 ,
V_94 , V_87 , V_73 -> V_106 ,
V_73 -> V_109 , V_73 -> V_110 ,
V_90 , V_97 ) ;
F_31 ( & V_87 ) ;
V_108:
F_32 ( & V_7 -> V_104 ) ;
V_105:
F_33 ( V_92 ) ;
V_103:
F_34 ( V_2 ) ;
V_100:
F_35 ( V_90 ) ;
V_98:
return V_75 ;
}
int F_36 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_111 * V_73 =
(struct V_111 * ) V_3 ;
struct V_112 T_3 * V_113 =
(struct V_112 T_3 * )
( unsigned long ) V_73 -> V_114 ;
struct V_88 T_3 * V_89 ;
struct V_88 * V_90 = NULL ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
V_38 V_97 ;
int V_75 ;
V_97 = V_73 -> V_97 ;
V_89 = (struct V_88 T_3 * ) ( unsigned long ) V_73 -> V_89 ;
if ( F_16 ( V_97 == 0 ) )
return 0 ;
if ( V_89 == NULL ) {
F_17 ( L_8 ) ;
V_75 = - V_50 ;
goto V_98;
}
V_90 = F_22 ( V_97 , sizeof( * V_90 ) , V_99 ) ;
if ( V_90 == NULL ) {
F_17 ( L_5 ) ;
V_75 = - V_78 ;
goto V_98;
}
V_75 = F_23 ( V_90 , V_89 , V_97 * sizeof( * V_90 ) ) ;
if ( V_75 ) {
F_17 ( L_6 ) ;
V_75 = - V_82 ;
goto V_100;
}
F_24 ( V_2 ) ;
V_92 = F_25 ( V_2 , V_73 -> V_101 ) ;
if ( ! V_92 ) {
F_17 ( L_7 ) ;
V_75 = - V_102 ;
goto V_103;
}
V_94 = F_26 ( V_92 ) ;
if ( ! V_94 -> V_115 ) {
F_17 ( L_9 ) ;
V_75 = - V_50 ;
goto V_105;
}
V_75 = F_27 ( & V_7 -> V_104 , true ) ;
if ( F_16 ( V_75 != 0 ) )
goto V_105;
V_75 = F_37 ( V_7 , V_5 ,
V_94 , V_113 ,
V_90 , V_97 ) ;
F_32 ( & V_7 -> V_104 ) ;
V_105:
F_33 ( V_92 ) ;
V_103:
F_34 ( V_2 ) ;
V_100:
F_35 ( V_90 ) ;
V_98:
return V_75 ;
}
unsigned int F_38 ( struct V_116 * V_117 , struct V_118 * V_119 )
{
struct V_4 * V_5 = V_117 -> V_120 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_121 -> V_2 ) ;
F_39 ( V_7 , V_122 ) ;
return F_40 ( V_117 , V_119 ) ;
}
T_4 F_41 ( struct V_116 * V_117 , char T_3 * V_74 ,
T_2 V_123 , T_5 * V_124 )
{
struct V_4 * V_5 = V_117 -> V_120 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_121 -> V_2 ) ;
F_39 ( V_7 , V_122 ) ;
return F_42 ( V_117 , V_74 , V_123 , V_124 ) ;
}
