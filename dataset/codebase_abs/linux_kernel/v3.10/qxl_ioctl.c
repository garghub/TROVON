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
F_6 ( struct V_6 * V_7 , struct V_12 * V_25 , T_3 V_26 ,
struct V_12 * V_27 , T_3 V_28 )
{
void * V_29 ;
V_29 = F_7 ( V_7 , V_25 , V_26 & V_30 ) ;
* ( T_3 * ) ( V_29 + ( V_26 & ~ V_30 ) ) = F_8 ( V_7 ,
V_27 , V_28 ) ;
F_9 ( V_7 , V_25 , V_29 ) ;
}
static void
F_10 ( struct V_6 * V_7 , struct V_12 * V_25 , T_3 V_26 ,
struct V_12 * V_27 )
{
T_1 V_31 = 0 ;
void * V_29 ;
if ( V_27 && ! V_27 -> V_32 )
V_31 = V_27 -> V_33 ;
V_29 = F_7 ( V_7 , V_25 , V_26 & V_30 ) ;
* ( T_1 * ) ( V_29 + ( V_26 & ~ V_30 ) ) = V_31 ;
F_9 ( V_7 , V_25 , V_29 ) ;
}
static struct V_12 * F_11 ( struct V_6 * V_7 ,
struct V_4 * V_5 , T_3 V_14 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 ;
struct V_12 * V_13 ;
int V_11 ;
V_37 = F_12 ( V_7 -> V_23 , V_5 , V_14 ) ;
if ( ! V_37 ) {
F_2 ( L_3 , V_14 ) ;
return NULL ;
}
V_13 = F_13 ( V_37 ) ;
V_11 = F_14 ( V_35 , V_13 ) ;
if ( V_11 )
return NULL ;
return V_13 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_38 * V_39 = V_3 ;
struct V_40 V_41 ;
int V_42 ;
struct V_12 * V_43 ;
struct V_12 * V_44 ;
struct V_45 V_46 ;
void * V_47 ;
int V_48 , V_11 ;
struct V_34 V_35 ;
int V_49 ;
T_1 V_50 ;
F_16 ( & V_35 . V_51 ) ;
for ( V_42 = 0 ; V_42 < V_39 -> V_52 ; ++ V_42 ) {
struct V_53 * V_54 ;
struct V_12 * V_55 ;
int V_56 ;
struct V_40 * V_57 =
(struct V_40 * ) ( V_58 ) V_39 -> V_57 ;
if ( F_17 ( & V_41 , & V_57 [ V_42 ] ,
sizeof( V_41 ) ) )
return - V_59 ;
switch ( V_41 . type ) {
case V_60 :
V_56 = V_61 ;
break;
case V_62 :
case V_63 :
default:
F_18 ( L_4 ) ;
return - V_18 ;
break;
}
if ( V_41 . V_64 > V_65 - sizeof( union V_66 ) )
return - V_18 ;
if ( ! F_19 ( V_67 ,
( void * ) ( unsigned long ) V_41 . V_68 ,
V_41 . V_64 ) )
return - V_59 ;
V_11 = F_20 ( V_7 ,
sizeof( union V_66 ) +
V_41 . V_64 ,
V_56 ,
& V_54 ,
& V_55 ) ;
if ( V_11 )
return V_11 ;
V_47 = F_7 ( V_7 , V_55 , ( V_54 -> V_69 & V_65 ) ) ;
V_49 = F_21 ( V_47 + sizeof( union V_66 ) + ( V_54 -> V_69 & ~ V_65 ) , ( void * ) ( unsigned long ) V_41 . V_68 , V_41 . V_64 ) ;
F_9 ( V_7 , V_55 , V_47 ) ;
if ( V_49 ) {
F_2 ( L_5 , V_49 ) ;
F_22 ( V_7 , V_54 ) ;
F_23 ( V_7 , V_54 ) ;
return - V_59 ;
}
for ( V_48 = 0 ; V_48 < V_41 . V_70 ; ++ V_48 ) {
if ( F_17 ( & V_46 ,
& ( (struct V_45 * ) ( V_58 ) V_41 . V_71 ) [ V_48 ] ,
sizeof( V_46 ) ) ) {
F_24 ( & V_35 , true ) ;
F_22 ( V_7 , V_54 ) ;
F_23 ( V_7 , V_54 ) ;
return - V_59 ;
}
if ( V_46 . V_72 ) {
V_44 = F_11 ( V_7 , V_5 ,
V_46 . V_72 , & V_35 ) ;
if ( ! V_44 ) {
F_24 ( & V_35 , true ) ;
F_22 ( V_7 , V_54 ) ;
F_23 ( V_7 , V_54 ) ;
return - V_18 ;
}
V_50 = 0 ;
} else {
V_44 = V_55 ;
V_50 = V_54 -> V_69 ;
}
if ( V_46 . V_73 == V_74 || V_46 . V_75 > 0 ) {
V_43 =
F_11 ( V_7 , V_5 ,
V_46 . V_75 , & V_35 ) ;
if ( ! V_43 ) {
if ( V_44 != V_55 )
F_25 ( & V_44 -> V_76 ) ;
F_24 ( & V_35 , true ) ;
F_22 ( V_7 , V_54 ) ;
F_23 ( V_7 , V_54 ) ;
return - V_18 ;
}
} else
V_43 = NULL ;
if ( V_46 . V_73 == V_74 ) {
F_6 ( V_7 , V_44 , V_50 + V_46 . V_77 ,
V_43 , V_46 . V_78 ) ;
} else if ( V_46 . V_73 == V_79 ) {
F_10 ( V_7 , V_44 , V_50 + V_46 . V_77 , V_43 ) ;
} else {
F_2 ( L_6 , V_46 . V_73 ) ;
return - V_18 ;
}
if ( V_43 && V_43 != V_55 ) {
F_26 ( V_7 , V_54 , V_43 ) ;
F_25 ( & V_43 -> V_76 ) ;
}
if ( V_44 != V_55 )
F_25 ( & V_44 -> V_76 ) ;
}
F_27 ( V_7 , V_54 ) ;
V_11 = F_28 ( V_7 , V_54 , V_41 . type , true ) ;
if ( V_11 == - V_80 ) {
F_22 ( V_7 , V_54 ) ;
F_23 ( V_7 , V_54 ) ;
F_24 ( & V_35 , true ) ;
return V_11 ;
}
F_22 ( V_7 , V_54 ) ;
}
F_24 ( & V_35 , 0 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_81 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_82 * V_83 = V_3 ;
struct V_84 V_85 = { . V_86 = V_83 -> V_86 ,
. V_87 = V_83 -> V_87 ,
. V_88 = V_83 -> V_88 ,
. V_89 = V_83 -> V_89 } ;
int V_11 ;
struct V_36 * V_37 = NULL ;
struct V_12 * V_13 = NULL ;
if ( V_83 -> V_86 >= V_83 -> V_88 ||
V_83 -> V_87 >= V_83 -> V_89 )
return - V_18 ;
V_37 = F_12 ( V_2 , V_81 , V_83 -> V_14 ) ;
if ( V_37 == NULL )
return - V_90 ;
V_13 = F_13 ( V_37 ) ;
V_11 = F_30 ( V_13 , false ) ;
if ( V_11 )
goto V_91;
if ( ! V_13 -> V_92 ) {
F_31 ( V_13 , V_13 -> type ) ;
V_11 = F_32 ( & V_13 -> V_93 , & V_13 -> V_94 ,
true , false ) ;
if ( F_33 ( V_11 ) )
goto V_91;
}
V_11 = F_34 ( V_7 , V_13 ) ;
if ( V_11 )
goto V_95;
if ( ! V_13 -> V_33 )
F_2 ( L_7 , V_83 -> V_14 ) ;
V_11 = F_35 ( V_7 , V_13 , & V_85 ) ;
V_95:
F_36 ( V_13 ) ;
V_91:
F_25 ( V_37 ) ;
return V_11 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_96 * V_97 = V_3 ;
switch ( V_97 -> V_97 ) {
case V_98 :
V_97 -> V_99 = V_7 -> V_100 -> V_101 ;
break;
case V_102 :
V_97 -> V_99 = V_103 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_104 * V_97 = V_3 ;
int V_105 , V_106 ;
V_105 = V_97 -> V_107 / 8 ;
V_106 = V_97 -> V_107 % 8 ;
if ( V_7 -> V_108 -> V_109 < 4 )
return - V_110 ;
if ( V_105 >= 58 )
return - V_110 ;
if ( V_7 -> V_100 -> V_111 [ V_105 ] & ( 1 << V_106 ) )
return 0 ;
return - V_110 ;
}
static int F_39 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_81 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_112 * V_97 = V_3 ;
struct V_12 * V_13 ;
int V_14 ;
int V_11 ;
int V_17 , V_113 ;
struct V_114 V_115 ;
V_113 = V_97 -> V_116 < 0 ? - V_97 -> V_116 : V_97 -> V_116 ;
V_17 = V_113 * V_97 -> V_117 + V_113 ;
V_115 . V_118 = V_97 -> V_118 ;
V_115 . V_119 = V_97 -> V_119 ;
V_115 . V_117 = V_97 -> V_117 ;
V_115 . V_116 = V_97 -> V_116 ;
V_115 . V_3 = 0 ;
V_11 = F_3 ( V_7 , V_81 ,
V_120 ,
V_17 ,
& V_115 ,
& V_13 , & V_14 ) ;
if ( V_11 ) {
F_2 ( L_2 ,
V_19 , V_11 ) ;
return - V_20 ;
} else
V_97 -> V_14 = V_14 ;
return V_11 ;
}
