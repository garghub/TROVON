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
return F_5 ( V_5 , V_7 -> V_23 , V_22 -> V_14 ,
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
static struct V_12 * F_11 ( struct V_6 * V_7 ,
struct V_4 * V_5 , V_31 V_14 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 ;
struct V_12 * V_13 ;
int V_11 ;
V_40 = F_12 ( V_7 -> V_23 , V_5 , V_14 ) ;
if ( ! V_40 )
return NULL ;
V_13 = F_13 ( V_40 ) ;
V_11 = F_14 ( V_38 , V_13 ) ;
if ( V_11 )
return NULL ;
return V_13 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_41 * V_42 ,
struct V_4 * V_5 )
{
struct V_25 * V_43 ;
int V_44 ;
struct V_37 * V_38 ;
struct V_12 * V_45 ;
void * V_46 ;
int V_47 , V_48 , V_11 , V_49 ;
int V_50 ;
switch ( V_42 -> type ) {
case V_51 :
V_44 = V_52 ;
break;
case V_53 :
case V_54 :
default:
F_16 ( L_3 ) ;
return - V_18 ;
break;
}
if ( V_42 -> V_55 > V_56 - sizeof( union V_57 ) )
return - V_18 ;
if ( ! F_17 ( V_58 ,
( void * ) ( unsigned long ) V_42 -> V_59 ,
V_42 -> V_55 ) )
return - V_60 ;
V_43 = F_18 ( sizeof( struct V_25 ) * V_42 -> V_61 , V_62 ) ;
if ( ! V_43 )
return - V_20 ;
V_11 = F_19 ( V_7 ,
sizeof( union V_57 ) +
V_42 -> V_55 ,
V_44 ,
& V_38 ,
& V_45 ) ;
if ( V_11 )
goto V_63;
V_46 = F_7 ( V_7 , V_45 , ( V_38 -> V_64 & V_56 ) ) ;
V_50 = F_20 ( V_46 + sizeof( union V_57 ) + ( V_38 -> V_64 & ~ V_56 ) , ( void * ) ( unsigned long ) V_42 -> V_59 , V_42 -> V_55 ) ;
{
struct V_65 * V_66 = V_46 ;
V_66 -> V_67 = V_7 -> V_68 -> V_69 ;
}
F_9 ( V_7 , V_45 , V_46 ) ;
if ( V_50 ) {
F_2 ( L_4 , V_50 ) ;
V_11 = - V_60 ;
goto V_70;
}
V_49 = 0 ;
for ( V_47 = 0 ; V_47 < V_42 -> V_61 ; ++ V_47 ) {
struct V_71 V_72 ;
if ( F_21 ( & V_72 ,
& ( (struct V_71 * ) ( V_73 ) V_42 -> V_74 ) [ V_47 ] ,
sizeof( V_72 ) ) ) {
V_11 = - V_60 ;
goto V_75;
}
if ( V_72 . V_76 != V_77 && V_72 . V_76 != V_78 ) {
F_16 ( L_5 , V_43 [ V_47 ] . type ) ;
V_11 = - V_18 ;
goto V_75;
}
V_43 [ V_47 ] . type = V_72 . V_76 ;
if ( V_72 . V_79 ) {
V_43 [ V_47 ] . V_28 = F_11 ( V_7 , V_5 ,
V_72 . V_79 , V_38 ) ;
if ( ! V_43 [ V_47 ] . V_28 ) {
V_11 = - V_18 ;
V_43 [ V_47 ] . V_32 = NULL ;
goto V_75;
}
V_43 [ V_47 ] . V_29 = V_72 . V_29 ;
} else {
V_43 [ V_47 ] . V_28 = V_45 ;
V_43 [ V_47 ] . V_29 = V_72 . V_29 + V_38 -> V_64 ;
}
V_49 ++ ;
if ( V_72 . V_76 == V_77 || V_72 . V_80 > 0 ) {
V_43 [ V_47 ] . V_32 =
F_11 ( V_7 , V_5 ,
V_72 . V_80 , V_38 ) ;
if ( ! V_43 [ V_47 ] . V_32 ) {
if ( V_43 [ V_47 ] . V_28 != V_45 )
F_22 ( & V_43 [ V_47 ] . V_28 -> V_81 ) ;
V_11 = - V_18 ;
goto V_75;
}
V_43 [ V_47 ] . V_33 = V_72 . V_33 ;
} else {
V_43 [ V_47 ] . V_32 = NULL ;
V_43 [ V_47 ] . V_33 = 0 ;
}
}
V_11 = F_23 ( V_38 , false ) ;
if ( V_11 )
goto V_75;
for ( V_47 = 0 ; V_47 < V_42 -> V_61 ; ++ V_47 ) {
if ( V_43 [ V_47 ] . type == V_77 )
F_6 ( V_7 , & V_43 [ V_47 ] ) ;
else if ( V_43 [ V_47 ] . type == V_78 )
F_10 ( V_7 , & V_43 [ V_47 ] ) ;
}
V_11 = F_24 ( V_7 , V_38 , V_42 -> type , true ) ;
if ( V_11 )
F_25 ( V_38 ) ;
else
F_26 ( V_38 ) ;
V_75:
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
if ( V_43 [ V_48 ] . V_28 != V_45 )
F_22 ( & V_43 [ V_48 ] . V_28 -> V_81 ) ;
if ( V_43 [ V_48 ] . V_32 && V_43 [ V_48 ] . V_32 != V_45 )
F_22 ( & V_43 [ V_48 ] . V_32 -> V_81 ) ;
}
V_70:
if ( V_11 )
F_27 ( V_7 , V_38 ) ;
V_63:
F_28 ( V_43 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_82 * V_83 = V_3 ;
struct V_41 V_84 ;
int V_85 ;
int V_11 ;
for ( V_85 = 0 ; V_85 < V_83 -> V_86 ; ++ V_85 ) {
struct V_41 * V_87 =
(struct V_41 * ) ( V_73 ) V_83 -> V_87 ;
if ( F_21 ( & V_84 , & V_87 [ V_85 ] ,
sizeof( V_84 ) ) )
return - V_60 ;
V_11 = F_15 ( V_7 , & V_84 , V_5 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_88 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_89 * V_90 = V_3 ;
struct V_91 V_92 = { . V_93 = V_90 -> V_93 ,
. V_94 = V_90 -> V_94 ,
. V_95 = V_90 -> V_95 ,
. V_96 = V_90 -> V_96 } ;
int V_11 ;
struct V_39 * V_40 = NULL ;
struct V_12 * V_13 = NULL ;
if ( V_90 -> V_93 >= V_90 -> V_95 ||
V_90 -> V_94 >= V_90 -> V_96 )
return - V_18 ;
V_40 = F_12 ( V_2 , V_88 , V_90 -> V_14 ) ;
if ( V_40 == NULL )
return - V_97 ;
V_13 = F_13 ( V_40 ) ;
V_11 = F_31 ( V_13 , false ) ;
if ( V_11 )
goto V_98;
if ( ! V_13 -> V_99 ) {
F_32 ( V_13 , V_13 -> type , false ) ;
V_11 = F_33 ( & V_13 -> V_100 , & V_13 -> V_101 ,
true , false ) ;
if ( F_34 ( V_11 ) )
goto V_98;
}
V_11 = F_35 ( V_7 , V_13 ) ;
if ( V_11 )
goto V_102;
if ( ! V_13 -> V_36 )
F_2 ( L_6 , V_90 -> V_14 ) ;
V_11 = F_36 ( V_7 , V_13 , & V_92 ) ;
V_102:
F_37 ( V_13 ) ;
V_98:
F_22 ( V_40 ) ;
return V_11 ;
}
static int F_38 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_103 * V_104 = V_3 ;
switch ( V_104 -> V_104 ) {
case V_105 :
V_104 -> V_106 = V_7 -> V_68 -> V_107 ;
break;
case V_108 :
V_104 -> V_106 = V_109 ;
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
struct V_110 * V_104 = V_3 ;
int V_111 , V_112 ;
V_111 = V_104 -> V_113 / 8 ;
V_112 = V_104 -> V_113 % 8 ;
if ( V_7 -> V_114 -> V_115 < 4 )
return - V_116 ;
if ( V_111 >= 58 )
return - V_116 ;
if ( V_7 -> V_68 -> V_117 [ V_111 ] & ( 1 << V_112 ) )
return 0 ;
return - V_116 ;
}
static int F_40 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_88 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_118 * V_104 = V_3 ;
struct V_12 * V_13 ;
int V_14 ;
int V_11 ;
int V_17 , V_119 ;
struct V_120 V_121 ;
V_119 = V_104 -> V_122 < 0 ? - V_104 -> V_122 : V_104 -> V_122 ;
V_17 = V_119 * V_104 -> V_123 + V_119 ;
V_121 . V_124 = V_104 -> V_124 ;
V_121 . V_125 = V_104 -> V_125 ;
V_121 . V_123 = V_104 -> V_123 ;
V_121 . V_122 = V_104 -> V_122 ;
V_121 . V_3 = 0 ;
V_11 = F_3 ( V_7 , V_88 ,
V_126 ,
V_17 ,
& V_121 ,
& V_13 , & V_14 ) ;
if ( V_11 ) {
F_2 ( L_2 ,
V_19 , V_11 ) ;
return - V_20 ;
} else
V_104 -> V_14 = V_14 ;
return V_11 ;
}
