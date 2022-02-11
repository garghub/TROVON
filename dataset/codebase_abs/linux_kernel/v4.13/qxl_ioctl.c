static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_3 ;
int V_11 ;
struct V_12 * V_13 ;
T_1 V_14 ;
T_2 V_15 = V_16 ;
if ( V_10 -> V_17 == 0 ) {
F_2 ( L_1 , V_10 -> V_17 ) ;
return - V_18 ;
}
V_11 = F_3 ( V_7 , V_5 ,
V_15 ,
V_10 -> V_17 ,
NULL ,
& V_13 , & V_14 ) ;
if ( V_11 ) {
F_2 ( L_2 ,
V_19 , V_11 ) ;
return - V_20 ;
}
V_10 -> V_14 = V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_21 * V_22 = V_3 ;
return F_5 ( V_5 , & V_7 -> V_23 , V_22 -> V_14 ,
& V_22 -> V_24 ) ;
}
static void
F_6 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
void * V_27 ;
V_27 = F_7 ( V_7 , V_26 -> V_28 , V_26 -> V_29 & V_30 ) ;
* ( V_31 * ) ( V_27 + ( V_26 -> V_29 & ~ V_30 ) ) = F_8 ( V_7 ,
V_26 -> V_32 ,
V_26 -> V_33 ) ;
F_9 ( V_7 , V_26 -> V_28 , V_27 ) ;
}
static void
F_10 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
T_1 V_34 = 0 ;
void * V_27 ;
if ( V_26 -> V_32 && ! V_26 -> V_32 -> V_35 )
V_34 = V_26 -> V_32 -> V_36 ;
V_27 = F_7 ( V_7 , V_26 -> V_28 , V_26 -> V_29 & V_30 ) ;
* ( T_1 * ) ( V_27 + ( V_26 -> V_29 & ~ V_30 ) ) = V_34 ;
F_9 ( V_7 , V_26 -> V_28 , V_27 ) ;
}
static int F_11 ( struct V_4 * V_5 , V_31 V_14 ,
struct V_37 * V_38 , struct V_12 * * V_39 )
{
struct V_40 * V_41 ;
struct V_12 * V_13 ;
int V_11 ;
V_41 = F_12 ( V_5 , V_14 ) ;
if ( ! V_41 )
return - V_18 ;
V_13 = F_13 ( V_41 ) ;
V_11 = F_14 ( V_38 , V_13 ) ;
F_15 ( V_41 ) ;
if ( V_11 )
return V_11 ;
* V_39 = V_13 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_42 * V_43 ,
struct V_4 * V_5 )
{
struct V_25 * V_44 ;
int V_45 ;
struct V_37 * V_38 ;
struct V_12 * V_46 ;
void * V_47 ;
int V_48 , V_11 , V_49 ;
int V_50 ;
switch ( V_43 -> type ) {
case V_51 :
V_45 = V_52 ;
break;
case V_53 :
case V_54 :
default:
F_17 ( L_3 ) ;
return - V_18 ;
break;
}
if ( V_43 -> V_55 > V_56 - sizeof( union V_57 ) )
return - V_18 ;
if ( ! F_18 ( V_58 ,
( void * ) ( unsigned long ) V_43 -> V_59 ,
V_43 -> V_55 ) )
return - V_60 ;
V_44 = F_19 ( V_43 -> V_61 ,
sizeof( struct V_25 ) , V_62 ) ;
if ( ! V_44 )
return - V_20 ;
V_11 = F_20 ( V_7 ,
sizeof( union V_57 ) +
V_43 -> V_55 ,
V_45 ,
& V_38 ,
& V_46 ) ;
if ( V_11 )
goto V_63;
V_47 = F_7 ( V_7 , V_46 , ( V_38 -> V_64 & V_56 ) ) ;
V_50 = F_21 ( V_47 + sizeof( union V_57 ) + ( V_38 -> V_64 & ~ V_56 ) , ( void * ) ( unsigned long ) V_43 -> V_59 , V_43 -> V_55 ) ;
{
struct V_65 * V_66 = V_47 ;
V_66 -> V_67 = V_7 -> V_68 -> V_69 ;
}
F_9 ( V_7 , V_46 , V_47 ) ;
if ( V_50 ) {
F_2 ( L_4 , V_50 ) ;
V_11 = - V_60 ;
goto V_70;
}
V_49 = 0 ;
for ( V_48 = 0 ; V_48 < V_43 -> V_61 ; ++ V_48 ) {
struct V_71 V_72 ;
if ( F_22 ( & V_72 ,
& ( (struct V_71 * ) ( V_73 ) V_43 -> V_74 ) [ V_48 ] ,
sizeof( V_72 ) ) ) {
V_11 = - V_60 ;
goto V_75;
}
if ( V_72 . V_76 != V_77 && V_72 . V_76 != V_78 ) {
F_17 ( L_5 , V_72 . V_76 ) ;
V_11 = - V_18 ;
goto V_75;
}
V_44 [ V_48 ] . type = V_72 . V_76 ;
if ( V_72 . V_79 ) {
V_11 = F_11 ( V_5 , V_72 . V_79 , V_38 ,
& V_44 [ V_48 ] . V_28 ) ;
if ( V_11 )
goto V_75;
V_44 [ V_48 ] . V_29 = V_72 . V_29 ;
} else {
V_44 [ V_48 ] . V_28 = V_46 ;
V_44 [ V_48 ] . V_29 = V_72 . V_29 + V_38 -> V_64 ;
}
V_49 ++ ;
if ( V_72 . V_76 == V_77 || V_72 . V_80 ) {
V_11 = F_11 ( V_5 , V_72 . V_80 , V_38 ,
& V_44 [ V_48 ] . V_32 ) ;
if ( V_11 )
goto V_75;
V_44 [ V_48 ] . V_33 = V_72 . V_33 ;
} else {
V_44 [ V_48 ] . V_32 = NULL ;
V_44 [ V_48 ] . V_33 = 0 ;
}
}
V_11 = F_23 ( V_38 , false ) ;
if ( V_11 )
goto V_75;
for ( V_48 = 0 ; V_48 < V_43 -> V_61 ; ++ V_48 ) {
if ( V_44 [ V_48 ] . type == V_77 )
F_6 ( V_7 , & V_44 [ V_48 ] ) ;
else if ( V_44 [ V_48 ] . type == V_78 )
F_10 ( V_7 , & V_44 [ V_48 ] ) ;
}
V_11 = F_24 ( V_7 , V_38 , V_43 -> type , true ) ;
if ( V_11 )
F_25 ( V_38 ) ;
else
F_26 ( V_38 ) ;
V_75:
V_70:
if ( V_11 )
F_27 ( V_7 , V_38 ) ;
V_63:
F_28 ( V_44 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_81 * V_82 = V_3 ;
struct V_42 V_83 ;
int V_84 ;
int V_11 ;
for ( V_84 = 0 ; V_84 < V_82 -> V_85 ; ++ V_84 ) {
struct V_42 * V_86 =
(struct V_42 * ) ( V_73 ) V_82 -> V_86 ;
if ( F_22 ( & V_83 , & V_86 [ V_84 ] ,
sizeof( V_83 ) ) )
return - V_60 ;
V_11 = F_16 ( V_7 , & V_83 , V_5 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_87 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_88 * V_89 = V_3 ;
struct V_90 V_91 = { . V_92 = V_89 -> V_92 ,
. V_93 = V_89 -> V_93 ,
. V_94 = V_89 -> V_94 ,
. V_95 = V_89 -> V_95 } ;
int V_11 ;
struct V_40 * V_41 = NULL ;
struct V_12 * V_13 = NULL ;
if ( V_89 -> V_92 >= V_89 -> V_94 ||
V_89 -> V_93 >= V_89 -> V_95 )
return - V_18 ;
V_41 = F_12 ( V_87 , V_89 -> V_14 ) ;
if ( V_41 == NULL )
return - V_96 ;
V_13 = F_13 ( V_41 ) ;
V_11 = F_31 ( V_13 , false ) ;
if ( V_11 )
goto V_97;
if ( ! V_13 -> V_98 ) {
F_32 ( V_13 , V_13 -> type , false ) ;
V_11 = F_33 ( & V_13 -> V_99 , & V_13 -> V_100 ,
true , false ) ;
if ( F_34 ( V_11 ) )
goto V_97;
}
V_11 = F_35 ( V_7 , V_13 ) ;
if ( V_11 )
goto V_101;
if ( ! V_13 -> V_36 )
F_2 ( L_6 , V_89 -> V_14 ) ;
V_11 = F_36 ( V_7 , V_13 , & V_91 ) ;
V_101:
F_37 ( V_13 ) ;
V_97:
F_15 ( V_41 ) ;
return V_11 ;
}
static int F_38 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_102 * V_103 = V_3 ;
switch ( V_103 -> V_103 ) {
case V_104 :
V_103 -> V_105 = V_7 -> V_68 -> V_106 ;
break;
case V_107 :
V_103 -> V_105 = V_108 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_109 * V_103 = V_3 ;
int V_110 , V_111 ;
V_110 = V_103 -> V_112 / 8 ;
V_111 = V_103 -> V_112 % 8 ;
if ( V_2 -> V_113 -> V_114 < 4 )
return - V_115 ;
if ( V_110 >= 58 )
return - V_115 ;
if ( V_7 -> V_68 -> V_116 [ V_110 ] & ( 1 << V_111 ) )
return 0 ;
return - V_115 ;
}
static int F_40 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_87 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_117 * V_103 = V_3 ;
struct V_12 * V_13 ;
int V_14 ;
int V_11 ;
int V_17 , V_118 ;
struct V_119 V_120 ;
V_118 = V_103 -> V_121 < 0 ? - V_103 -> V_121 : V_103 -> V_121 ;
V_17 = V_118 * V_103 -> V_122 + V_118 ;
V_120 . V_123 = V_103 -> V_123 ;
V_120 . V_124 = V_103 -> V_124 ;
V_120 . V_122 = V_103 -> V_122 ;
V_120 . V_121 = V_103 -> V_121 ;
V_120 . V_3 = 0 ;
V_11 = F_3 ( V_7 , V_87 ,
V_125 ,
V_17 ,
& V_120 ,
& V_13 , & V_14 ) ;
if ( V_11 ) {
F_2 ( L_2 ,
V_19 , V_11 ) ;
return - V_20 ;
} else
V_103 -> V_14 = V_14 ;
return V_11 ;
}
