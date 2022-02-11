static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
if ( ! V_8 -> V_13 || F_3 ( & V_8 -> V_14 ) )
return 0 ;
V_12 = F_4 ( V_2 , V_15 ) ;
if ( V_12 == NULL )
return - V_16 ;
F_5 (p, &br->router_list, rlist) {
if ( V_10 && F_6 ( V_2 , V_17 , V_10 -> V_6 -> V_18 ) )
goto V_19;
}
F_7 ( V_2 , V_12 ) ;
return 0 ;
V_19:
F_8 ( V_2 , V_12 ) ;
return - V_16 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
struct V_11 * V_12 , * V_22 ;
int V_23 , V_24 = 0 ;
int V_25 = 0 , V_26 = V_4 -> args [ 1 ] ;
if ( V_8 -> V_27 )
return 0 ;
V_21 = F_10 ( V_8 -> V_21 ) ;
if ( ! V_21 )
return 0 ;
V_12 = F_4 ( V_2 , V_28 ) ;
if ( V_12 == NULL )
return - V_16 ;
for ( V_23 = 0 ; V_23 < V_21 -> V_29 ; V_23 ++ ) {
struct V_30 * V_31 ;
struct V_32 * V_10 ;
struct V_32 T_1 * * V_33 ;
struct V_9 * V_34 ;
F_5 (mp, &mdb->mhash[i], hlist[mdb->ver]) {
if ( V_25 < V_26 )
goto V_35;
V_22 = F_4 ( V_2 , V_36 ) ;
if ( V_22 == NULL ) {
V_24 = - V_16 ;
goto V_37;
}
for ( V_33 = & V_31 -> V_38 ;
( V_10 = F_10 ( * V_33 ) ) != NULL ;
V_33 = & V_10 -> V_39 ) {
V_34 = V_10 -> V_34 ;
if ( V_34 ) {
struct V_40 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_18 = V_34 -> V_6 -> V_18 ;
V_41 . V_42 = V_10 -> V_42 ;
V_41 . V_43 = V_10 -> V_44 . V_43 ;
if ( V_10 -> V_44 . V_45 == F_11 ( V_46 ) )
V_41 . V_44 . V_47 . V_48 = V_10 -> V_44 . V_47 . V_48 ;
#if F_12 ( V_49 )
if ( V_10 -> V_44 . V_45 == F_11 ( V_50 ) )
V_41 . V_44 . V_47 . V_51 = V_10 -> V_44 . V_47 . V_51 ;
#endif
V_41 . V_44 . V_45 = V_10 -> V_44 . V_45 ;
if ( F_13 ( V_2 , V_52 , sizeof( V_41 ) , & V_41 ) ) {
F_8 ( V_2 , V_22 ) ;
V_24 = - V_16 ;
goto V_37;
}
}
}
F_7 ( V_2 , V_22 ) ;
V_35:
V_25 ++ ;
}
}
V_37:
V_4 -> args [ 1 ] = V_25 ;
F_7 ( V_2 , V_12 ) ;
return V_24 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_53 * V_53 = F_15 ( V_2 -> V_54 ) ;
struct V_55 * V_56 = NULL ;
int V_25 = 0 , V_26 ;
V_26 = V_4 -> args [ 0 ] ;
F_16 () ;
V_4 -> V_57 = V_53 -> V_58 + V_59 ;
F_17 (net, dev) {
if ( V_6 -> V_60 & V_61 ) {
struct V_62 * V_63 ;
if ( V_25 < V_26 )
goto V_35;
V_56 = F_18 ( V_2 , F_19 ( V_4 -> V_2 ) . V_64 ,
V_4 -> V_56 -> V_65 , V_66 ,
sizeof( * V_63 ) , V_67 ) ;
if ( V_56 == NULL )
break;
V_63 = F_20 ( V_56 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_18 = V_6 -> V_18 ;
if ( F_9 ( V_2 , V_4 , V_6 ) < 0 )
goto V_37;
if ( F_1 ( V_2 , V_4 , V_6 ) < 0 )
goto V_37;
V_4 -> args [ 1 ] = 0 ;
F_21 ( V_2 , V_56 ) ;
V_35:
V_25 ++ ;
}
}
V_37:
if ( V_56 )
F_21 ( V_2 , V_56 ) ;
F_22 () ;
V_4 -> args [ 0 ] = V_25 ;
return V_2 -> V_68 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_40 * V_69 , T_2 V_70 ,
T_2 V_57 , int type , unsigned int V_71 )
{
struct V_55 * V_56 ;
struct V_62 * V_63 ;
struct V_11 * V_12 , * V_22 ;
V_56 = F_18 ( V_2 , V_70 , V_57 , type , sizeof( * V_63 ) , 0 ) ;
if ( ! V_56 )
return - V_16 ;
V_63 = F_20 ( V_56 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_72 = V_73 ;
V_63 -> V_18 = V_6 -> V_18 ;
V_12 = F_4 ( V_2 , V_28 ) ;
if ( V_12 == NULL )
goto V_74;
V_22 = F_4 ( V_2 , V_36 ) ;
if ( V_22 == NULL )
goto V_75;
if ( F_13 ( V_2 , V_52 , sizeof( * V_69 ) , V_69 ) )
goto V_75;
F_7 ( V_2 , V_22 ) ;
F_7 ( V_2 , V_12 ) ;
F_21 ( V_2 , V_56 ) ;
return 0 ;
V_75:
F_7 ( V_2 , V_12 ) ;
V_74:
F_24 ( V_2 , V_56 ) ;
return - V_16 ;
}
static inline T_3 F_25 ( void )
{
return F_26 ( sizeof( struct V_62 ) )
+ F_27 ( sizeof( struct V_40 ) ) ;
}
static void F_28 ( struct V_5 * V_6 , struct V_40 * V_69 ,
int type )
{
struct V_76 V_21 = {
. V_77 = {
. V_78 = V_79 ,
. V_71 = V_80 ,
} ,
. V_43 = V_69 -> V_43 ,
} ;
struct V_5 * V_81 ;
struct V_53 * V_53 = F_29 ( V_6 ) ;
struct V_1 * V_2 ;
int V_24 = - V_82 ;
V_81 = F_30 ( V_53 , V_69 -> V_18 ) ;
if ( V_69 -> V_44 . V_45 == F_11 ( V_46 ) )
F_31 ( V_69 -> V_44 . V_47 . V_48 , V_21 . V_44 ) ;
#if F_12 ( V_49 )
else
F_32 ( & V_69 -> V_44 . V_47 . V_51 , V_21 . V_44 ) ;
#endif
V_21 . V_77 . V_83 = V_81 ;
if ( V_81 && type == V_84 )
F_33 ( V_81 , & V_21 . V_77 ) ;
else if ( V_81 && type == V_85 )
F_34 ( V_81 , & V_21 . V_77 ) ;
V_2 = F_35 ( F_25 () , V_86 ) ;
if ( ! V_2 )
goto V_87;
V_24 = F_23 ( V_2 , V_6 , V_69 , 0 , 0 , type , V_88 ) ;
if ( V_24 < 0 ) {
F_36 ( V_2 ) ;
goto V_87;
}
F_37 ( V_2 , V_53 , 0 , V_89 , NULL , V_86 ) ;
return;
V_87:
F_38 ( V_53 , V_89 , V_24 ) ;
}
void F_39 ( struct V_5 * V_6 , struct V_9 * V_34 ,
struct V_90 * V_91 , int type , T_4 V_42 )
{
struct V_40 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_18 = V_34 -> V_6 -> V_18 ;
V_69 . V_44 . V_45 = V_91 -> V_45 ;
V_69 . V_44 . V_47 . V_48 = V_91 -> V_47 . V_48 ;
#if F_12 ( V_49 )
V_69 . V_44 . V_47 . V_51 = V_91 -> V_47 . V_51 ;
#endif
V_69 . V_42 = V_42 ;
V_69 . V_43 = V_91 -> V_43 ;
F_28 ( V_6 , & V_69 , type ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int V_18 , T_2 V_70 ,
T_2 V_57 , int type , unsigned int V_71 )
{
struct V_62 * V_63 ;
struct V_55 * V_56 ;
struct V_11 * V_12 ;
V_56 = F_18 ( V_2 , V_70 , V_57 , type , sizeof( * V_63 ) , V_67 ) ;
if ( ! V_56 )
return - V_16 ;
V_63 = F_20 ( V_56 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_72 = V_73 ;
V_63 -> V_18 = V_6 -> V_18 ;
V_12 = F_4 ( V_2 , V_15 ) ;
if ( ! V_12 )
goto V_74;
if ( F_6 ( V_2 , V_17 , V_18 ) )
goto V_75;
F_7 ( V_2 , V_12 ) ;
F_21 ( V_2 , V_56 ) ;
return 0 ;
V_75:
F_7 ( V_2 , V_12 ) ;
V_74:
F_24 ( V_2 , V_56 ) ;
return - V_16 ;
}
static inline T_3 F_41 ( void )
{
return F_26 ( sizeof( struct V_62 ) )
+ F_27 ( sizeof( V_92 ) ) ;
}
void F_42 ( struct V_5 * V_6 , struct V_9 * V_34 ,
int type )
{
struct V_53 * V_53 = F_29 ( V_6 ) ;
struct V_1 * V_2 ;
int V_24 = - V_82 ;
int V_18 ;
V_18 = V_34 ? V_34 -> V_6 -> V_18 : 0 ;
V_2 = F_35 ( F_41 () , V_86 ) ;
if ( ! V_2 )
goto V_87;
V_24 = F_40 ( V_2 , V_6 , V_18 , 0 , 0 , type , V_88 ) ;
if ( V_24 < 0 ) {
F_36 ( V_2 ) ;
goto V_87;
}
F_37 ( V_2 , V_53 , 0 , V_89 , NULL , V_86 ) ;
return;
V_87:
F_38 ( V_53 , V_89 , V_24 ) ;
}
static bool F_43 ( struct V_40 * V_69 )
{
if ( V_69 -> V_18 == 0 )
return false ;
if ( V_69 -> V_44 . V_45 == F_11 ( V_46 ) ) {
if ( ! F_44 ( V_69 -> V_44 . V_47 . V_48 ) )
return false ;
if ( F_45 ( V_69 -> V_44 . V_47 . V_48 ) )
return false ;
#if F_12 ( V_49 )
} else if ( V_69 -> V_44 . V_45 == F_11 ( V_50 ) ) {
if ( F_46 ( & V_69 -> V_44 . V_47 . V_51 ) )
return false ;
#endif
} else
return false ;
if ( V_69 -> V_42 != V_93 && V_69 -> V_42 != V_94 )
return false ;
if ( V_69 -> V_43 >= V_95 )
return false ;
return true ;
}
static int F_47 ( struct V_1 * V_2 , struct V_55 * V_56 ,
struct V_5 * * V_96 , struct V_40 * * V_97 )
{
struct V_53 * V_53 = F_15 ( V_2 -> V_54 ) ;
struct V_40 * V_69 ;
struct V_62 * V_63 ;
struct V_11 * V_98 [ V_99 + 1 ] ;
struct V_5 * V_6 ;
int V_24 ;
V_24 = F_48 ( V_56 , sizeof( * V_63 ) , V_98 , V_99 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
V_63 = F_20 ( V_56 ) ;
if ( V_63 -> V_18 == 0 ) {
F_49 ( L_1 ) ;
return - V_100 ;
}
V_6 = F_30 ( V_53 , V_63 -> V_18 ) ;
if ( V_6 == NULL ) {
F_49 ( L_2 ) ;
return - V_101 ;
}
if ( ! ( V_6 -> V_60 & V_61 ) ) {
F_49 ( L_3 ) ;
return - V_102 ;
}
* V_96 = V_6 ;
if ( ! V_98 [ V_103 ] ||
F_50 ( V_98 [ V_103 ] ) != sizeof( struct V_40 ) ) {
F_49 ( L_4 ) ;
return - V_100 ;
}
V_69 = F_51 ( V_98 [ V_103 ] ) ;
if ( ! F_43 ( V_69 ) ) {
F_49 ( L_5 ) ;
return - V_100 ;
}
* V_97 = V_69 ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 , struct V_9 * V_34 ,
struct V_90 * V_91 , unsigned char V_42 )
{
struct V_30 * V_31 ;
struct V_32 * V_10 ;
struct V_32 T_1 * * V_33 ;
struct V_20 * V_21 ;
unsigned long V_104 = V_105 ;
int V_24 ;
V_21 = F_53 ( V_8 -> V_21 , V_8 ) ;
V_31 = F_54 ( V_21 , V_91 ) ;
if ( ! V_31 ) {
V_31 = F_55 ( V_8 , V_34 , V_91 ) ;
V_24 = F_56 ( V_31 ) ;
if ( V_24 )
return V_24 ;
}
for ( V_33 = & V_31 -> V_38 ;
( V_10 = F_53 ( * V_33 , V_8 ) ) != NULL ;
V_33 = & V_10 -> V_39 ) {
if ( V_10 -> V_34 == V_34 )
return - V_106 ;
if ( ( unsigned long ) V_10 -> V_34 < ( unsigned long ) V_34 )
break;
}
V_10 = F_57 ( V_34 , V_91 , * V_33 , V_42 ) ;
if ( F_58 ( ! V_10 ) )
return - V_107 ;
F_59 ( * V_33 , V_10 ) ;
if ( V_42 == V_94 )
F_60 ( & V_10 -> V_108 , V_104 + V_8 -> V_109 ) ;
return 0 ;
}
static int F_61 ( struct V_53 * V_53 , struct V_7 * V_8 ,
struct V_40 * V_69 )
{
struct V_90 V_110 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
int V_111 ;
if ( ! F_62 ( V_8 -> V_6 ) || V_8 -> V_27 )
return - V_100 ;
V_6 = F_30 ( V_53 , V_69 -> V_18 ) ;
if ( ! V_6 )
return - V_101 ;
V_10 = F_63 ( V_6 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_42 == V_112 )
return - V_100 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_43 = V_69 -> V_43 ;
V_110 . V_45 = V_69 -> V_44 . V_45 ;
if ( V_110 . V_45 == F_11 ( V_46 ) )
V_110 . V_47 . V_48 = V_69 -> V_44 . V_47 . V_48 ;
#if F_12 ( V_49 )
else
V_110 . V_47 . V_51 = V_69 -> V_44 . V_47 . V_51 ;
#endif
F_64 ( & V_8 -> V_113 ) ;
V_111 = F_52 ( V_8 , V_10 , & V_110 , V_69 -> V_42 ) ;
F_65 ( & V_8 -> V_113 ) ;
return V_111 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_53 * V_53 = F_15 ( V_2 -> V_54 ) ;
struct V_114 * V_115 ;
struct V_5 * V_6 , * V_96 ;
struct V_40 * V_69 ;
struct V_9 * V_10 ;
struct V_116 * V_117 ;
struct V_7 * V_8 ;
int V_24 ;
V_24 = F_47 ( V_2 , V_56 , & V_6 , & V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = F_2 ( V_6 ) ;
V_96 = F_30 ( V_53 , V_69 -> V_18 ) ;
if ( ! V_96 )
return - V_101 ;
V_10 = F_63 ( V_96 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_42 == V_112 )
return - V_100 ;
V_115 = F_67 ( V_10 ) ;
if ( F_68 ( V_8 ) && V_115 && V_69 -> V_43 == 0 ) {
F_69 (v, &vg->vlan_list, vlist) {
V_69 -> V_43 = V_117 -> V_43 ;
V_24 = F_61 ( V_53 , V_8 , V_69 ) ;
if ( V_24 )
break;
F_28 ( V_6 , V_69 , V_84 ) ;
}
} else {
V_24 = F_61 ( V_53 , V_8 , V_69 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_69 , V_84 ) ;
}
return V_24 ;
}
static int F_70 ( struct V_7 * V_8 , struct V_40 * V_69 )
{
struct V_20 * V_21 ;
struct V_30 * V_31 ;
struct V_32 * V_10 ;
struct V_32 T_1 * * V_33 ;
struct V_90 V_110 ;
int V_24 = - V_100 ;
if ( ! F_62 ( V_8 -> V_6 ) || V_8 -> V_27 )
return - V_100 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_43 = V_69 -> V_43 ;
V_110 . V_45 = V_69 -> V_44 . V_45 ;
if ( V_110 . V_45 == F_11 ( V_46 ) )
V_110 . V_47 . V_48 = V_69 -> V_44 . V_47 . V_48 ;
#if F_12 ( V_49 )
else
V_110 . V_47 . V_51 = V_69 -> V_44 . V_47 . V_51 ;
#endif
F_64 ( & V_8 -> V_113 ) ;
V_21 = F_53 ( V_8 -> V_21 , V_8 ) ;
V_31 = F_54 ( V_21 , & V_110 ) ;
if ( ! V_31 )
goto V_118;
for ( V_33 = & V_31 -> V_38 ;
( V_10 = F_53 ( * V_33 , V_8 ) ) != NULL ;
V_33 = & V_10 -> V_39 ) {
if ( ! V_10 -> V_34 || V_10 -> V_34 -> V_6 -> V_18 != V_69 -> V_18 )
continue;
if ( V_10 -> V_34 -> V_42 == V_112 )
goto V_118;
V_69 -> V_42 = V_10 -> V_42 ;
F_59 ( * V_33 , V_10 -> V_39 ) ;
F_71 ( & V_10 -> V_119 ) ;
F_72 ( & V_10 -> V_108 ) ;
F_73 ( & V_10 -> V_120 , V_121 ) ;
V_24 = 0 ;
if ( ! V_31 -> V_38 && ! V_31 -> V_119 &&
F_62 ( V_8 -> V_6 ) )
F_60 ( & V_31 -> V_108 , V_105 ) ;
break;
}
V_118:
F_65 ( & V_8 -> V_113 ) ;
return V_24 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_53 * V_53 = F_15 ( V_2 -> V_54 ) ;
struct V_114 * V_115 ;
struct V_5 * V_6 , * V_96 ;
struct V_40 * V_69 ;
struct V_9 * V_10 ;
struct V_116 * V_117 ;
struct V_7 * V_8 ;
int V_24 ;
V_24 = F_47 ( V_2 , V_56 , & V_6 , & V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = F_2 ( V_6 ) ;
V_96 = F_30 ( V_53 , V_69 -> V_18 ) ;
if ( ! V_96 )
return - V_101 ;
V_10 = F_63 ( V_96 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_42 == V_112 )
return - V_100 ;
V_115 = F_67 ( V_10 ) ;
if ( F_68 ( V_8 ) && V_115 && V_69 -> V_43 == 0 ) {
F_69 (v, &vg->vlan_list, vlist) {
V_69 -> V_43 = V_117 -> V_43 ;
V_24 = F_70 ( V_8 , V_69 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_69 , V_85 ) ;
}
} else {
V_24 = F_70 ( V_8 , V_69 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_69 , V_85 ) ;
}
return V_24 ;
}
void F_75 ( void )
{
F_76 ( V_122 , V_66 , NULL , F_14 , NULL ) ;
F_76 ( V_122 , V_84 , F_66 , NULL , NULL ) ;
F_76 ( V_122 , V_85 , F_74 , NULL , NULL ) ;
}
void F_77 ( void )
{
F_78 ( V_122 , V_66 ) ;
F_78 ( V_122 , V_84 ) ;
F_78 ( V_122 , V_85 ) ;
}
