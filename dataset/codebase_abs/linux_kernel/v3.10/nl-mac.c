int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
F_2 ( L_1 , V_8 ) ;
if ( V_4 -> V_9 != V_10 ) {
F_3 ( L_2 , V_8 ) ;
return - V_11 ;
}
V_7 = F_4 ( 0 , V_12 ) ;
if ( ! V_7 )
return - V_13 ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) ||
F_7 ( V_7 , V_21 , V_19 ,
V_4 -> V_22 ) ||
F_8 ( V_7 , V_23 , V_5 ) )
goto V_24;
return F_9 ( V_7 , V_25 . V_26 ) ;
V_24:
F_10 ( V_7 ) ;
return - V_13 ;
}
int F_11 ( struct V_1 * V_2 , T_2 V_27 ,
T_1 V_28 )
{
struct V_6 * V_7 ;
F_2 ( L_1 , V_8 ) ;
V_7 = F_4 ( 0 , V_29 ) ;
if ( ! V_7 )
return - V_13 ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) ||
F_12 ( V_7 , V_30 , V_27 ) ||
F_8 ( V_7 , V_31 , V_28 ) )
goto V_24;
return F_9 ( V_7 , V_25 . V_26 ) ;
V_24:
F_10 ( V_7 ) ;
return - V_13 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_32 )
{
struct V_6 * V_7 ;
F_2 ( L_1 , V_8 ) ;
V_7 = F_4 ( 0 , V_33 ) ;
if ( ! V_7 )
return - V_13 ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) )
goto V_24;
if ( V_4 -> V_9 == V_10 ) {
if ( F_7 ( V_7 , V_21 , V_19 ,
V_4 -> V_22 ) )
goto V_24;
} else {
if ( F_12 ( V_7 , V_34 ,
V_4 -> V_27 ) )
goto V_24;
}
if ( F_8 ( V_7 , V_35 , V_32 ) )
goto V_24;
return F_9 ( V_7 , V_25 . V_26 ) ;
V_24:
F_10 ( V_7 ) ;
return - V_13 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_6 * V_7 ;
F_2 ( L_1 , V_8 ) ;
V_7 = F_4 ( 0 , V_36 ) ;
if ( ! V_7 )
return - V_13 ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) ||
F_8 ( V_7 , V_31 , V_28 ) )
goto V_24;
return F_9 ( V_7 , V_25 . V_26 ) ;
V_24:
F_10 ( V_7 ) ;
return - V_13 ;
}
int F_15 ( struct V_1 * V_2 ,
T_2 V_37 , T_2 V_38 )
{
struct V_6 * V_7 ;
F_2 ( L_1 , V_8 ) ;
V_7 = F_4 ( 0 , V_39 ) ;
if ( ! V_7 )
return - V_13 ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) ||
F_12 ( V_7 , V_40 , V_38 ) ||
F_12 ( V_7 , V_41 , V_37 ) )
goto V_24;
return F_9 ( V_7 , V_25 . V_26 ) ;
V_24:
F_10 ( V_7 ) ;
return - V_13 ;
}
int F_16 ( struct V_1 * V_2 ,
T_1 V_28 , T_1 V_42 , T_3 V_43 , T_1 V_44 ,
T_1 * V_45 )
{
struct V_6 * V_7 ;
F_2 ( L_1 , V_8 ) ;
V_7 = F_4 ( 0 , V_46 ) ;
if ( ! V_7 )
return - V_13 ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) ||
F_8 ( V_7 , V_31 , V_28 ) ||
F_8 ( V_7 , V_47 , V_42 ) ||
F_6 ( V_7 , V_48 , V_43 ) ||
F_8 ( V_7 , V_49 , V_44 ) ||
( V_45 &&
F_7 ( V_7 , V_50 , 27 , V_45 ) ) )
goto V_24;
return F_9 ( V_7 , V_25 . V_26 ) ;
V_24:
F_10 ( V_7 ) ;
return - V_13 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_6 * V_7 ;
F_2 ( L_1 , V_8 ) ;
V_7 = F_4 ( 0 , V_51 ) ;
if ( ! V_7 )
return - V_13 ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) ||
F_8 ( V_7 , V_31 , V_28 ) )
goto V_24;
return F_9 ( V_7 , V_25 . V_26 ) ;
V_24:
F_10 ( V_7 ) ;
return - V_13 ;
}
static int F_18 ( struct V_6 * V_7 , T_3 V_52 ,
T_3 V_53 , int V_54 , struct V_1 * V_2 )
{
void * V_55 ;
struct V_56 * V_57 ;
F_2 ( L_1 , V_8 ) ;
V_55 = F_19 ( V_7 , 0 , V_53 , & V_58 , V_54 ,
V_59 ) ;
if ( ! V_55 )
goto V_60;
V_57 = F_20 ( V_2 ) -> F_21 ( V_2 ) ;
F_22 ( ! V_57 ) ;
if ( F_5 ( V_7 , V_14 , V_2 -> V_15 ) ||
F_5 ( V_7 , V_61 , F_23 ( V_57 ) ) ||
F_6 ( V_7 , V_16 , V_2 -> V_17 ) ||
F_7 ( V_7 , V_18 , V_19 ,
V_2 -> V_20 ) ||
F_12 ( V_7 , V_30 ,
F_20 ( V_2 ) -> F_24 ( V_2 ) ) ||
F_12 ( V_7 , V_62 ,
F_20 ( V_2 ) -> F_25 ( V_2 ) ) )
goto V_24;
F_26 ( V_57 ) ;
return F_27 ( V_7 , V_55 ) ;
V_24:
F_26 ( V_57 ) ;
F_28 ( V_7 , V_55 ) ;
V_60:
return - V_63 ;
}
static struct V_1 * F_29 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
if ( V_65 -> V_66 [ V_14 ] ) {
char V_15 [ V_67 + 1 ] ;
F_30 ( V_15 , V_65 -> V_66 [ V_14 ] ,
sizeof( V_15 ) ) ;
V_2 = F_31 ( & V_68 , V_15 ) ;
} else if ( V_65 -> V_66 [ V_16 ] )
V_2 = F_32 ( & V_68 ,
F_33 ( V_65 -> V_66 [ V_16 ] ) ) ;
else
return NULL ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> type != V_69 ) {
F_34 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static int F_35 ( struct V_6 * V_70 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
T_1 V_44 ;
int V_71 = - V_72 ;
if ( ! V_65 -> V_66 [ V_73 ] ||
! V_65 -> V_66 [ V_41 ] ||
( ! V_65 -> V_66 [ V_74 ] &&
! V_65 -> V_66 [ V_40 ] ) ||
! V_65 -> V_66 [ V_23 ] )
return - V_11 ;
V_2 = F_29 ( V_65 ) ;
if ( ! V_2 )
return - V_75 ;
if ( ! F_20 ( V_2 ) -> V_76 )
goto V_60;
if ( V_65 -> V_66 [ V_74 ] ) {
V_4 . V_9 = V_10 ;
F_36 ( V_4 . V_22 ,
V_65 -> V_66 [ V_74 ] ,
V_19 ) ;
} else {
V_4 . V_9 = V_77 ;
V_4 . V_27 = F_37 (
V_65 -> V_66 [ V_40 ] ) ;
}
V_4 . V_78 = F_37 ( V_65 -> V_66 [ V_41 ] ) ;
if ( V_65 -> V_66 [ V_49 ] )
V_44 = F_38 ( V_65 -> V_66 [ V_49 ] ) ;
else
V_44 = 0 ;
V_71 = F_20 ( V_2 ) -> V_76 ( V_2 , & V_4 ,
F_38 ( V_65 -> V_66 [ V_73 ] ) ,
V_44 ,
F_38 ( V_65 -> V_66 [ V_23 ] ) ) ;
V_60:
F_34 ( V_2 ) ;
return V_71 ;
}
static int F_39 ( struct V_6 * V_70 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_71 = - V_72 ;
if ( ! V_65 -> V_66 [ V_31 ] ||
! V_65 -> V_66 [ V_79 ] ||
! V_65 -> V_66 [ V_80 ] )
return - V_11 ;
V_2 = F_29 ( V_65 ) ;
if ( ! V_2 )
return - V_75 ;
if ( ! F_20 ( V_2 ) -> V_81 )
goto V_60;
V_4 . V_9 = V_10 ;
F_36 ( V_4 . V_22 , V_65 -> V_66 [ V_79 ] ,
V_19 ) ;
V_4 . V_78 = F_20 ( V_2 ) -> F_25 ( V_2 ) ;
V_71 = F_20 ( V_2 ) -> V_81 ( V_2 , & V_4 ,
F_37 ( V_65 -> V_66 [ V_80 ] ) ,
F_38 ( V_65 -> V_66 [ V_31 ] ) ) ;
V_60:
F_34 ( V_2 ) ;
return V_71 ;
}
static int F_40 ( struct V_6 * V_70 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_71 = - V_72 ;
if ( ( ! V_65 -> V_66 [ V_79 ] &&
! V_65 -> V_66 [ V_80 ] ) ||
! V_65 -> V_66 [ V_35 ] )
return - V_11 ;
V_2 = F_29 ( V_65 ) ;
if ( ! V_2 )
return - V_75 ;
if ( ! F_20 ( V_2 ) -> V_82 )
goto V_60;
if ( V_65 -> V_66 [ V_79 ] ) {
V_4 . V_9 = V_10 ;
F_36 ( V_4 . V_22 ,
V_65 -> V_66 [ V_79 ] ,
V_19 ) ;
} else {
V_4 . V_9 = V_77 ;
V_4 . V_27 = F_37 (
V_65 -> V_66 [ V_80 ] ) ;
}
V_4 . V_78 = F_20 ( V_2 ) -> F_25 ( V_2 ) ;
V_71 = F_20 ( V_2 ) -> V_82 ( V_2 , & V_4 ,
F_38 ( V_65 -> V_66 [ V_35 ] ) ) ;
V_60:
F_34 ( V_2 ) ;
return V_71 ;
}
static int F_41 ( struct V_6 * V_70 , struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
T_1 V_83 , V_84 , V_85 ;
T_1 V_44 ;
int V_86 , V_87 , V_88 ;
int V_71 = - V_72 ;
if ( ! V_65 -> V_66 [ V_41 ] ||
! V_65 -> V_66 [ V_40 ] ||
! V_65 -> V_66 [ V_73 ] ||
! V_65 -> V_66 [ V_89 ] ||
! V_65 -> V_66 [ V_90 ] ||
! V_65 -> V_66 [ V_91 ] ||
! V_65 -> V_66 [ V_92 ] ||
! V_65 -> V_66 [ V_93 ]
)
return - V_11 ;
V_2 = F_29 ( V_65 ) ;
if ( ! V_2 )
return - V_75 ;
if ( ! F_20 ( V_2 ) -> V_94 )
goto V_60;
V_4 . V_9 = V_77 ;
V_4 . V_27 = F_37 (
V_65 -> V_66 [ V_40 ] ) ;
V_4 . V_78 = F_37 ( V_65 -> V_66 [ V_41 ] ) ;
V_83 = F_38 ( V_65 -> V_66 [ V_73 ] ) ;
V_84 = F_38 ( V_65 -> V_66 [ V_89 ] ) ;
V_85 = F_38 ( V_65 -> V_66 [ V_90 ] ) ;
V_86 = F_38 ( V_65 -> V_66 [ V_91 ] ) ;
V_87 = F_38 ( V_65 -> V_66 [ V_92 ] ) ;
V_88 = F_38 ( V_65 -> V_66 [ V_93 ] ) ;
if ( V_65 -> V_66 [ V_49 ] )
V_44 = F_38 ( V_65 -> V_66 [ V_49 ] ) ;
else
V_44 = 0 ;
if ( V_4 . V_27 == V_95 ) {
F_17 ( V_2 , V_96 ) ;
F_34 ( V_2 ) ;
return - V_11 ;
}
V_71 = F_20 ( V_2 ) -> V_94 ( V_2 , & V_4 , V_83 , V_44 ,
V_84 , V_85 , V_86 , V_87 , V_88 ) ;
V_60:
F_34 ( V_2 ) ;
return V_71 ;
}
static int F_42 ( struct V_6 * V_70 , struct V_64 * V_65 )
{
struct V_1 * V_2 ;
int V_71 = - V_72 ;
T_1 type ;
T_3 V_97 ;
T_1 V_98 ;
T_1 V_44 ;
if ( ! V_65 -> V_66 [ V_47 ] ||
! V_65 -> V_66 [ V_48 ] ||
! V_65 -> V_66 [ V_99 ] )
return - V_11 ;
V_2 = F_29 ( V_65 ) ;
if ( ! V_2 )
return - V_75 ;
if ( ! F_20 ( V_2 ) -> V_100 )
goto V_60;
type = F_38 ( V_65 -> V_66 [ V_47 ] ) ;
V_97 = F_33 ( V_65 -> V_66 [ V_48 ] ) ;
V_98 = F_38 ( V_65 -> V_66 [ V_99 ] ) ;
if ( V_65 -> V_66 [ V_49 ] )
V_44 = F_38 ( V_65 -> V_66 [ V_49 ] ) ;
else
V_44 = 0 ;
V_71 = F_20 ( V_2 ) -> V_100 ( V_2 , type , V_97 , V_44 ,
V_98 ) ;
V_60:
F_34 ( V_2 ) ;
return V_71 ;
}
static int F_43 ( struct V_6 * V_70 ,
struct V_64 * V_65 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = NULL ;
int V_101 = - V_13 ;
F_2 ( L_1 , V_8 ) ;
V_2 = F_29 ( V_65 ) ;
if ( ! V_2 )
return - V_75 ;
V_7 = F_44 ( V_102 , V_103 ) ;
if ( ! V_7 )
goto V_104;
V_101 = F_18 ( V_7 , V_65 -> V_105 , V_65 -> V_106 ,
0 , V_2 ) ;
if ( V_101 < 0 )
goto V_107;
F_34 ( V_2 ) ;
return F_45 ( V_7 , V_65 ) ;
V_107:
F_10 ( V_7 ) ;
V_104:
F_34 ( V_2 ) ;
return V_101 ;
}
static int F_46 ( struct V_6 * V_70 ,
struct V_108 * V_109 )
{
struct V_110 * V_110 = F_47 ( V_70 -> V_111 ) ;
struct V_1 * V_2 ;
int V_112 ;
int V_113 = V_109 -> args [ 0 ] ;
F_2 ( L_1 , V_8 ) ;
V_112 = 0 ;
F_48 (net, dev) {
if ( V_112 < V_113 || ( V_2 -> type != V_69 ) )
goto V_114;
if ( F_18 ( V_70 , F_49 ( V_109 -> V_70 ) . V_52 ,
V_109 -> V_115 -> V_116 , V_117 , V_2 ) < 0 )
break;
V_114:
V_112 ++ ;
}
V_109 -> args [ 0 ] = V_112 ;
return V_70 -> V_118 ;
}
int F_50 ( void )
{
int V_119 ;
int V_101 ;
V_101 = F_51 ( & V_58 ,
& V_25 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_51 ( & V_58 ,
& V_120 ) ;
if ( V_101 )
return V_101 ;
for ( V_119 = 0 ; V_119 < F_52 ( V_121 ) ; V_119 ++ ) {
V_101 = F_53 ( & V_58 ,
& V_121 [ V_119 ] ) ;
if ( V_101 )
return V_101 ;
}
return 0 ;
}
