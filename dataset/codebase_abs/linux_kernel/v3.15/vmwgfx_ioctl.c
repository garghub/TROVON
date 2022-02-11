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
default:
F_7 ( L_1 ,
V_9 -> V_9 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , void * V_46 ,
T_3 V_47 )
{
struct V_39 * V_48 =
(struct V_39 * ) V_46 ;
unsigned int V_49 ;
T_3 V_50 = F_9 ( struct V_39 , V_51 ) ;
unsigned int V_52 ;
if ( V_47 < V_50 )
return - V_45 ;
V_52 = ( V_47 - V_50 ) / sizeof( V_53 ) ;
if ( V_52 > V_37 )
V_52 = V_37 ;
V_48 -> V_54 . V_55 =
( V_50 + V_52 * sizeof( V_53 ) ) / sizeof( V_56 ) ;
V_48 -> V_54 . type = V_57 ;
F_10 ( & V_7 -> V_58 ) ;
for ( V_49 = 0 ; V_49 < V_52 ; ++ V_49 ) {
F_11 ( V_7 , V_59 , V_49 ) ;
V_48 -> V_51 [ V_49 ] [ 0 ] = V_49 ;
V_48 -> V_51 [ V_49 ] [ 1 ] = F_12 ( V_7 , V_59 ) ;
}
F_13 ( & V_7 -> V_58 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_60 * V_61 =
(struct V_60 * ) V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_38 V_47 ;
T_1 T_2 * V_23 ;
void T_4 * V_62 = ( void T_4 * ) ( ( unsigned long ) ( V_61 -> V_62 ) ) ;
void * V_46 ;
int V_63 ;
bool V_64 = ! ! ( V_7 -> V_17 & V_26 ) ;
struct V_10 * V_11 = V_10 ( V_5 ) ;
if ( F_15 ( V_61 -> V_65 != 0 ) ) {
F_7 ( L_2 ) ;
return - V_45 ;
}
if ( V_64 && V_11 -> V_32 )
V_47 = V_37 * sizeof( V_38 ) ;
else if ( V_64 )
V_47 = sizeof( struct V_39 ) + sizeof( V_38 ) ;
else
V_47 = ( V_40 - V_41 + 1 ) *
sizeof( V_38 ) ;
if ( V_61 -> V_52 < V_47 )
V_47 = V_61 -> V_52 ;
V_46 = F_16 ( V_47 ) ;
if ( F_15 ( V_46 == NULL ) ) {
F_7 ( L_3 ) ;
return - V_66 ;
}
if ( V_64 && V_11 -> V_32 ) {
int V_49 , V_67 ;
V_38 * V_68 = ( V_38 * ) V_46 ;
V_67 = V_47 / sizeof( V_38 ) ;
if ( V_67 > V_37 )
V_67 = V_37 ;
F_10 ( & V_7 -> V_58 ) ;
for ( V_49 = 0 ; V_49 < V_67 ; ++ V_49 ) {
F_11 ( V_7 , V_59 , V_49 ) ;
* V_68 ++ = F_12 ( V_7 , V_59 ) ;
}
F_13 ( & V_7 -> V_58 ) ;
} else if ( V_64 ) {
V_63 = F_8 ( V_7 , V_46 , V_47 ) ;
if ( F_15 ( V_63 != 0 ) )
goto V_69;
} else {
V_23 = V_7 -> V_24 ;
F_17 ( V_46 , & V_23 [ V_41 ] , V_47 ) ;
}
V_63 = F_18 ( V_62 , V_46 , V_47 ) ;
if ( V_63 )
V_63 = - V_70 ;
V_69:
F_19 ( V_46 ) ;
if ( F_15 ( V_63 != 0 ) )
F_7 ( L_4 ) ;
return V_63 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_71 * V_72 = V_10 ( V_5 ) -> V_72 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_73 * V_61 =
(struct V_73 * ) V_3 ;
struct V_74 * V_75 ;
struct V_76 T_4 * V_77 ;
struct V_76 * V_78 = NULL ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
V_38 V_85 ;
int V_63 ;
V_85 = V_61 -> V_85 ;
V_77 = (struct V_76 * ) ( unsigned long ) V_61 -> V_77 ;
if ( F_15 ( V_85 == 0 ) )
return 0 ;
if ( V_77 == NULL ) {
F_7 ( L_5 ) ;
V_63 = - V_45 ;
goto V_86;
}
V_78 = F_21 ( V_85 , sizeof( * V_78 ) , V_87 ) ;
if ( V_78 == NULL ) {
F_7 ( L_6 ) ;
V_63 = - V_66 ;
goto V_86;
}
V_63 = F_22 ( V_78 , V_77 , V_85 * sizeof( * V_78 ) ) ;
if ( V_63 ) {
F_7 ( L_7 ) ;
V_63 = - V_70 ;
goto V_88;
}
F_23 ( V_2 ) ;
V_80 = F_24 ( V_2 , V_61 -> V_89 ) ;
if ( ! V_80 ) {
F_7 ( L_8 ) ;
V_63 = - V_90 ;
goto V_91;
}
V_82 = F_25 ( V_80 ) ;
V_63 = F_26 ( & V_7 -> V_92 , true ) ;
if ( F_15 ( V_63 != 0 ) )
goto V_93;
V_63 = F_27 ( V_7 , V_72 , V_61 -> V_94 ,
V_95 ,
& V_84 ) ;
if ( V_63 )
goto V_96;
V_75 = F_28 ( V_84 ) ;
V_63 = F_29 ( V_7 , V_5 ,
V_82 , V_75 , V_61 -> V_94 ,
V_61 -> V_97 , V_61 -> V_98 ,
V_78 , V_85 ) ;
F_30 ( & V_75 ) ;
V_96:
F_31 ( & V_7 -> V_92 ) ;
V_93:
F_32 ( V_80 ) ;
V_91:
F_33 ( V_2 ) ;
V_88:
F_34 ( V_78 ) ;
V_86:
return V_63 ;
}
int F_35 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_99 * V_61 =
(struct V_99 * ) V_3 ;
struct V_100 T_4 * V_101 =
(struct V_100 T_4 * )
( unsigned long ) V_61 -> V_102 ;
struct V_76 T_4 * V_77 ;
struct V_76 * V_78 = NULL ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
V_38 V_85 ;
int V_63 ;
V_85 = V_61 -> V_85 ;
V_77 = (struct V_76 * ) ( unsigned long ) V_61 -> V_77 ;
if ( F_15 ( V_85 == 0 ) )
return 0 ;
if ( V_77 == NULL ) {
F_7 ( L_9 ) ;
V_63 = - V_45 ;
goto V_86;
}
V_78 = F_21 ( V_85 , sizeof( * V_78 ) , V_87 ) ;
if ( V_78 == NULL ) {
F_7 ( L_6 ) ;
V_63 = - V_66 ;
goto V_86;
}
V_63 = F_22 ( V_78 , V_77 , V_85 * sizeof( * V_78 ) ) ;
if ( V_63 ) {
F_7 ( L_7 ) ;
V_63 = - V_70 ;
goto V_88;
}
F_23 ( V_2 ) ;
V_80 = F_24 ( V_2 , V_61 -> V_89 ) ;
if ( ! V_80 ) {
F_7 ( L_8 ) ;
V_63 = - V_90 ;
goto V_91;
}
V_82 = F_25 ( V_80 ) ;
if ( ! V_82 -> V_103 ) {
F_7 ( L_10 ) ;
V_63 = - V_45 ;
goto V_93;
}
V_63 = F_26 ( & V_7 -> V_92 , true ) ;
if ( F_15 ( V_63 != 0 ) )
goto V_93;
V_63 = F_36 ( V_7 , V_5 ,
V_82 , V_101 ,
V_78 , V_85 ) ;
F_31 ( & V_7 -> V_92 ) ;
V_93:
F_32 ( V_80 ) ;
V_91:
F_33 ( V_2 ) ;
V_88:
F_34 ( V_78 ) ;
V_86:
return V_63 ;
}
unsigned int F_37 ( struct V_104 * V_105 , struct V_106 * V_107 )
{
struct V_4 * V_5 = V_105 -> V_108 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_109 -> V_2 ) ;
F_38 ( V_7 , V_110 ) ;
return F_39 ( V_105 , V_107 ) ;
}
T_5 F_40 ( struct V_104 * V_105 , char T_4 * V_62 ,
T_3 V_111 , T_6 * V_112 )
{
struct V_4 * V_5 = V_105 -> V_108 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_109 -> V_2 ) ;
F_38 ( V_7 , V_110 ) ;
return F_41 ( V_105 , V_62 , V_111 , V_112 ) ;
}
