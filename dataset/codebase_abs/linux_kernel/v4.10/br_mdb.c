static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 , * V_13 ;
if ( ! V_8 -> V_14 || F_3 ( & V_8 -> V_15 ) )
return 0 ;
V_12 = F_4 ( V_2 , V_16 ) ;
if ( V_12 == NULL )
return - V_17 ;
F_5 (p, &br->router_list, rlist) {
if ( ! V_10 )
continue;
V_13 = F_4 ( V_2 , V_18 ) ;
if ( ! V_13 )
goto V_19;
if ( F_6 ( V_2 , sizeof( V_20 ) , & V_10 -> V_6 -> V_21 ) ||
F_7 ( V_2 , V_22 ,
F_8 ( & V_10 -> V_23 ) ) ||
F_9 ( V_2 , V_24 ,
V_10 -> V_14 ) ) {
F_10 ( V_2 , V_13 ) ;
goto V_19;
}
F_11 ( V_2 , V_13 ) ;
}
F_11 ( V_2 , V_12 ) ;
return 0 ;
V_19:
F_10 ( V_2 , V_12 ) ;
return - V_17 ;
}
static void F_12 ( struct V_25 * V_26 , unsigned char V_27 )
{
V_26 -> V_28 = V_27 & V_29 ;
V_26 -> V_27 = 0 ;
if ( V_27 & V_30 )
V_26 -> V_27 |= V_31 ;
}
static void F_13 ( struct V_25 * V_32 , struct V_33 * V_34 )
{
memset ( V_34 , 0 , sizeof( struct V_33 ) ) ;
V_34 -> V_35 = V_32 -> V_35 ;
V_34 -> V_36 = V_32 -> V_37 . V_36 ;
if ( V_34 -> V_36 == F_14 ( V_38 ) )
V_34 -> V_39 . V_40 = V_32 -> V_37 . V_39 . V_40 ;
#if F_15 ( V_41 )
else
V_34 -> V_39 . V_42 = V_32 -> V_37 . V_39 . V_42 ;
#endif
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_43 * V_44 ;
struct V_11 * V_12 , * V_45 ;
int V_46 , V_47 = 0 ;
int V_48 = 0 , V_49 = V_4 -> args [ 1 ] ;
if ( V_8 -> V_50 )
return 0 ;
V_44 = F_17 ( V_8 -> V_44 ) ;
if ( ! V_44 )
return 0 ;
V_12 = F_4 ( V_2 , V_51 ) ;
if ( V_12 == NULL )
return - V_17 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_52 ; V_46 ++ ) {
struct V_53 * V_54 ;
struct V_55 * V_10 ;
struct V_55 T_1 * * V_56 ;
struct V_9 * V_57 ;
F_5 (mp, &mdb->mhash[i], hlist[mdb->ver]) {
if ( V_48 < V_49 )
goto V_58;
V_45 = F_4 ( V_2 , V_59 ) ;
if ( V_45 == NULL ) {
V_47 = - V_17 ;
goto V_60;
}
for ( V_56 = & V_54 -> V_61 ;
( V_10 = F_17 ( * V_56 ) ) != NULL ;
V_56 = & V_10 -> V_62 ) {
struct V_11 * V_63 ;
struct V_25 V_26 ;
V_57 = V_10 -> V_57 ;
if ( ! V_57 )
continue;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_21 = V_57 -> V_6 -> V_21 ;
V_26 . V_35 = V_10 -> V_37 . V_35 ;
F_12 ( & V_26 , V_10 -> V_27 ) ;
if ( V_10 -> V_37 . V_36 == F_14 ( V_38 ) )
V_26 . V_37 . V_39 . V_40 = V_10 -> V_37 . V_39 . V_40 ;
#if F_15 ( V_41 )
if ( V_10 -> V_37 . V_36 == F_14 ( V_64 ) )
V_26 . V_37 . V_39 . V_42 = V_10 -> V_37 . V_39 . V_42 ;
#endif
V_26 . V_37 . V_36 = V_10 -> V_37 . V_36 ;
V_63 = F_4 ( V_2 ,
V_65 ) ;
if ( ! V_63 ) {
F_10 ( V_2 , V_45 ) ;
V_47 = - V_17 ;
goto V_60;
}
if ( F_6 ( V_2 , sizeof( V_26 ) , & V_26 ) ||
F_7 ( V_2 ,
V_66 ,
F_8 ( & V_10 -> V_67 ) ) ) {
F_10 ( V_2 , V_63 ) ;
F_10 ( V_2 , V_45 ) ;
V_47 = - V_17 ;
goto V_60;
}
F_11 ( V_2 , V_63 ) ;
}
F_11 ( V_2 , V_45 ) ;
V_58:
V_48 ++ ;
}
}
V_60:
V_4 -> args [ 1 ] = V_48 ;
F_11 ( V_2 , V_12 ) ;
return V_47 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_68 * V_68 = F_19 ( V_2 -> V_69 ) ;
struct V_70 * V_71 = NULL ;
int V_48 = 0 , V_49 ;
V_49 = V_4 -> args [ 0 ] ;
F_20 () ;
V_4 -> V_72 = V_68 -> V_73 + V_74 ;
F_21 (net, dev) {
if ( V_6 -> V_75 & V_76 ) {
struct V_77 * V_78 ;
if ( V_48 < V_49 )
goto V_58;
V_71 = F_22 ( V_2 , F_23 ( V_4 -> V_2 ) . V_79 ,
V_4 -> V_71 -> V_80 , V_81 ,
sizeof( * V_78 ) , V_82 ) ;
if ( V_71 == NULL )
break;
V_78 = F_24 ( V_71 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_21 = V_6 -> V_21 ;
if ( F_16 ( V_2 , V_4 , V_6 ) < 0 )
goto V_60;
if ( F_1 ( V_2 , V_4 , V_6 ) < 0 )
goto V_60;
V_4 -> args [ 1 ] = 0 ;
F_25 ( V_2 , V_71 ) ;
V_58:
V_48 ++ ;
}
}
V_60:
if ( V_71 )
F_25 ( V_2 , V_71 ) ;
F_26 () ;
V_4 -> args [ 0 ] = V_48 ;
return V_2 -> V_83 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_25 * V_32 , V_20 V_84 ,
V_20 V_72 , int type , unsigned int V_27 )
{
struct V_70 * V_71 ;
struct V_77 * V_78 ;
struct V_11 * V_12 , * V_45 ;
V_71 = F_22 ( V_2 , V_84 , V_72 , type , sizeof( * V_78 ) , 0 ) ;
if ( ! V_71 )
return - V_17 ;
V_78 = F_24 ( V_71 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_85 = V_86 ;
V_78 -> V_21 = V_6 -> V_21 ;
V_12 = F_4 ( V_2 , V_51 ) ;
if ( V_12 == NULL )
goto V_87;
V_45 = F_4 ( V_2 , V_59 ) ;
if ( V_45 == NULL )
goto V_88;
if ( F_28 ( V_2 , V_65 , sizeof( * V_32 ) , V_32 ) )
goto V_88;
F_11 ( V_2 , V_45 ) ;
F_11 ( V_2 , V_12 ) ;
F_25 ( V_2 , V_71 ) ;
return 0 ;
V_88:
F_11 ( V_2 , V_12 ) ;
V_87:
F_29 ( V_2 , V_71 ) ;
return - V_17 ;
}
static inline T_2 F_30 ( void )
{
return F_31 ( sizeof( struct V_77 ) )
+ F_32 ( sizeof( struct V_25 ) ) ;
}
static void F_33 ( struct V_5 * V_6 , int V_47 , void * V_89 )
{
struct V_90 * V_91 = V_89 ;
struct V_55 T_1 * * V_56 ;
struct V_55 * V_10 ;
struct V_43 * V_44 ;
struct V_53 * V_54 ;
struct V_9 * V_57 = V_91 -> V_57 ;
struct V_7 * V_8 = V_57 -> V_8 ;
if ( V_47 )
goto V_47;
F_34 ( & V_8 -> V_92 ) ;
V_44 = F_35 ( V_8 -> V_44 , V_8 ) ;
V_54 = F_36 ( V_44 , & V_91 -> V_34 ) ;
if ( ! V_54 )
goto V_60;
for ( V_56 = & V_54 -> V_61 ; ( V_10 = F_35 ( * V_56 , V_8 ) ) != NULL ;
V_56 = & V_10 -> V_62 ) {
if ( V_10 -> V_57 != V_57 )
continue;
V_10 -> V_27 |= V_30 ;
}
V_60:
F_37 ( & V_8 -> V_92 ) ;
V_47:
F_38 ( V_89 ) ;
}
static void F_39 ( struct V_5 * V_6 , struct V_9 * V_10 ,
struct V_25 * V_32 , int type )
{
struct V_90 * V_93 ;
struct V_94 V_44 = {
. V_95 = {
. V_96 = V_97 ,
. V_27 = V_98 ,
} ,
. V_35 = V_32 -> V_35 ,
} ;
struct V_5 * V_99 ;
struct V_68 * V_68 = F_40 ( V_6 ) ;
struct V_1 * V_2 ;
int V_47 = - V_100 ;
V_99 = F_41 ( V_68 , V_32 -> V_21 ) ;
if ( V_32 -> V_37 . V_36 == F_14 ( V_38 ) )
F_42 ( V_32 -> V_37 . V_39 . V_40 , V_44 . V_37 ) ;
#if F_15 ( V_41 )
else
F_43 ( & V_32 -> V_37 . V_39 . V_42 , V_44 . V_37 ) ;
#endif
V_44 . V_95 . V_101 = V_99 ;
if ( V_99 && type == V_102 ) {
V_93 = F_44 ( sizeof( * V_93 ) , V_103 ) ;
if ( V_93 ) {
V_93 -> V_57 = V_10 ;
F_13 ( V_32 , & V_93 -> V_34 ) ;
V_44 . V_95 . V_104 = V_93 ;
V_44 . V_95 . V_105 = F_33 ;
F_45 ( V_99 , & V_44 . V_95 ) ;
}
} else if ( V_99 && type == V_106 ) {
F_46 ( V_99 , & V_44 . V_95 ) ;
}
V_2 = F_47 ( F_30 () , V_103 ) ;
if ( ! V_2 )
goto V_107;
V_47 = F_27 ( V_2 , V_6 , V_32 , 0 , 0 , type , V_108 ) ;
if ( V_47 < 0 ) {
F_48 ( V_2 ) ;
goto V_107;
}
F_49 ( V_2 , V_68 , 0 , V_109 , NULL , V_103 ) ;
return;
V_107:
F_50 ( V_68 , V_109 , V_47 ) ;
}
void F_51 ( struct V_5 * V_6 , struct V_9 * V_57 ,
struct V_33 * V_110 , int type , T_3 V_27 )
{
struct V_25 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_21 = V_57 -> V_6 -> V_21 ;
V_32 . V_37 . V_36 = V_110 -> V_36 ;
V_32 . V_37 . V_39 . V_40 = V_110 -> V_39 . V_40 ;
#if F_15 ( V_41 )
V_32 . V_37 . V_39 . V_42 = V_110 -> V_39 . V_42 ;
#endif
V_32 . V_35 = V_110 -> V_35 ;
F_12 ( & V_32 , V_27 ) ;
F_39 ( V_6 , V_57 , & V_32 , type ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int V_21 , V_20 V_84 ,
V_20 V_72 , int type , unsigned int V_27 )
{
struct V_77 * V_78 ;
struct V_70 * V_71 ;
struct V_11 * V_12 ;
V_71 = F_22 ( V_2 , V_84 , V_72 , type , sizeof( * V_78 ) , V_82 ) ;
if ( ! V_71 )
return - V_17 ;
V_78 = F_24 ( V_71 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_85 = V_86 ;
V_78 -> V_21 = V_6 -> V_21 ;
V_12 = F_4 ( V_2 , V_16 ) ;
if ( ! V_12 )
goto V_87;
if ( F_7 ( V_2 , V_18 , V_21 ) )
goto V_88;
F_11 ( V_2 , V_12 ) ;
F_25 ( V_2 , V_71 ) ;
return 0 ;
V_88:
F_11 ( V_2 , V_12 ) ;
V_87:
F_29 ( V_2 , V_71 ) ;
return - V_17 ;
}
static inline T_2 F_53 ( void )
{
return F_31 ( sizeof( struct V_77 ) )
+ F_32 ( sizeof( V_111 ) ) ;
}
void F_54 ( struct V_5 * V_6 , struct V_9 * V_57 ,
int type )
{
struct V_68 * V_68 = F_40 ( V_6 ) ;
struct V_1 * V_2 ;
int V_47 = - V_100 ;
int V_21 ;
V_21 = V_57 ? V_57 -> V_6 -> V_21 : 0 ;
V_2 = F_47 ( F_53 () , V_103 ) ;
if ( ! V_2 )
goto V_107;
V_47 = F_52 ( V_2 , V_6 , V_21 , 0 , 0 , type , V_108 ) ;
if ( V_47 < 0 ) {
F_48 ( V_2 ) ;
goto V_107;
}
F_49 ( V_2 , V_68 , 0 , V_109 , NULL , V_103 ) ;
return;
V_107:
F_50 ( V_68 , V_109 , V_47 ) ;
}
static bool F_55 ( struct V_25 * V_32 )
{
if ( V_32 -> V_21 == 0 )
return false ;
if ( V_32 -> V_37 . V_36 == F_14 ( V_38 ) ) {
if ( ! F_56 ( V_32 -> V_37 . V_39 . V_40 ) )
return false ;
if ( F_57 ( V_32 -> V_37 . V_39 . V_40 ) )
return false ;
#if F_15 ( V_41 )
} else if ( V_32 -> V_37 . V_36 == F_14 ( V_64 ) ) {
if ( F_58 ( & V_32 -> V_37 . V_39 . V_42 ) )
return false ;
#endif
} else
return false ;
if ( V_32 -> V_28 != V_112 && V_32 -> V_28 != V_113 )
return false ;
if ( V_32 -> V_35 >= V_114 )
return false ;
return true ;
}
static int F_59 ( struct V_1 * V_2 , struct V_70 * V_71 ,
struct V_5 * * V_115 , struct V_25 * * V_116 )
{
struct V_68 * V_68 = F_19 ( V_2 -> V_69 ) ;
struct V_25 * V_32 ;
struct V_77 * V_78 ;
struct V_11 * V_117 [ V_118 + 1 ] ;
struct V_5 * V_6 ;
int V_47 ;
V_47 = F_60 ( V_71 , sizeof( * V_78 ) , V_117 , V_118 , NULL ) ;
if ( V_47 < 0 )
return V_47 ;
V_78 = F_24 ( V_71 ) ;
if ( V_78 -> V_21 == 0 ) {
F_61 ( L_1 ) ;
return - V_119 ;
}
V_6 = F_41 ( V_68 , V_78 -> V_21 ) ;
if ( V_6 == NULL ) {
F_61 ( L_2 ) ;
return - V_120 ;
}
if ( ! ( V_6 -> V_75 & V_76 ) ) {
F_61 ( L_3 ) ;
return - V_121 ;
}
* V_115 = V_6 ;
if ( ! V_117 [ V_122 ] ||
F_62 ( V_117 [ V_122 ] ) != sizeof( struct V_25 ) ) {
F_61 ( L_4 ) ;
return - V_119 ;
}
V_32 = F_63 ( V_117 [ V_122 ] ) ;
if ( ! F_55 ( V_32 ) ) {
F_61 ( L_5 ) ;
return - V_119 ;
}
* V_116 = V_32 ;
return 0 ;
}
static int F_64 ( struct V_7 * V_8 , struct V_9 * V_57 ,
struct V_33 * V_110 , unsigned char V_28 )
{
struct V_53 * V_54 ;
struct V_55 * V_10 ;
struct V_55 T_1 * * V_56 ;
struct V_43 * V_44 ;
unsigned long V_123 = V_124 ;
int V_47 ;
V_44 = F_35 ( V_8 -> V_44 , V_8 ) ;
V_54 = F_36 ( V_44 , V_110 ) ;
if ( ! V_54 ) {
V_54 = F_65 ( V_8 , V_57 , V_110 ) ;
V_47 = F_66 ( V_54 ) ;
if ( V_47 )
return V_47 ;
}
for ( V_56 = & V_54 -> V_61 ;
( V_10 = F_35 ( * V_56 , V_8 ) ) != NULL ;
V_56 = & V_10 -> V_62 ) {
if ( V_10 -> V_57 == V_57 )
return - V_125 ;
if ( ( unsigned long ) V_10 -> V_57 < ( unsigned long ) V_57 )
break;
}
V_10 = F_67 ( V_57 , V_110 , * V_56 , V_28 ) ;
if ( F_68 ( ! V_10 ) )
return - V_126 ;
F_69 ( * V_56 , V_10 ) ;
if ( V_28 == V_113 )
F_70 ( & V_10 -> V_67 , V_123 + V_8 -> V_127 ) ;
return 0 ;
}
static int F_71 ( struct V_68 * V_68 , struct V_7 * V_8 ,
struct V_25 * V_32 )
{
struct V_33 V_34 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
int V_128 ;
if ( ! F_72 ( V_8 -> V_6 ) || V_8 -> V_50 )
return - V_119 ;
V_6 = F_41 ( V_68 , V_32 -> V_21 ) ;
if ( ! V_6 )
return - V_120 ;
V_10 = F_73 ( V_6 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_28 == V_129 )
return - V_119 ;
F_13 ( V_32 , & V_34 ) ;
F_34 ( & V_8 -> V_92 ) ;
V_128 = F_64 ( V_8 , V_10 , & V_34 , V_32 -> V_28 ) ;
F_37 ( & V_8 -> V_92 ) ;
return V_128 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
struct V_68 * V_68 = F_19 ( V_2 -> V_69 ) ;
struct V_130 * V_131 ;
struct V_5 * V_6 , * V_115 ;
struct V_25 * V_32 ;
struct V_9 * V_10 ;
struct V_132 * V_133 ;
struct V_7 * V_8 ;
int V_47 ;
V_47 = F_59 ( V_2 , V_71 , & V_6 , & V_32 ) ;
if ( V_47 < 0 )
return V_47 ;
V_8 = F_2 ( V_6 ) ;
V_115 = F_41 ( V_68 , V_32 -> V_21 ) ;
if ( ! V_115 )
return - V_120 ;
V_10 = F_73 ( V_115 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_28 == V_129 )
return - V_119 ;
V_131 = F_75 ( V_10 ) ;
if ( F_76 ( V_8 ) && V_131 && V_32 -> V_35 == 0 ) {
F_77 (v, &vg->vlan_list, vlist) {
V_32 -> V_35 = V_133 -> V_35 ;
V_47 = F_71 ( V_68 , V_8 , V_32 ) ;
if ( V_47 )
break;
F_39 ( V_6 , V_10 , V_32 , V_102 ) ;
}
} else {
V_47 = F_71 ( V_68 , V_8 , V_32 ) ;
if ( ! V_47 )
F_39 ( V_6 , V_10 , V_32 , V_102 ) ;
}
return V_47 ;
}
static int F_78 ( struct V_7 * V_8 , struct V_25 * V_32 )
{
struct V_43 * V_44 ;
struct V_53 * V_54 ;
struct V_55 * V_10 ;
struct V_55 T_1 * * V_56 ;
struct V_33 V_34 ;
int V_47 = - V_119 ;
if ( ! F_72 ( V_8 -> V_6 ) || V_8 -> V_50 )
return - V_119 ;
F_13 ( V_32 , & V_34 ) ;
F_34 ( & V_8 -> V_92 ) ;
V_44 = F_35 ( V_8 -> V_44 , V_8 ) ;
V_54 = F_36 ( V_44 , & V_34 ) ;
if ( ! V_54 )
goto V_134;
for ( V_56 = & V_54 -> V_61 ;
( V_10 = F_35 ( * V_56 , V_8 ) ) != NULL ;
V_56 = & V_10 -> V_62 ) {
if ( ! V_10 -> V_57 || V_10 -> V_57 -> V_6 -> V_21 != V_32 -> V_21 )
continue;
if ( V_10 -> V_57 -> V_28 == V_129 )
goto V_134;
F_12 ( V_32 , V_10 -> V_27 ) ;
F_69 ( * V_56 , V_10 -> V_62 ) ;
F_79 ( & V_10 -> V_135 ) ;
F_80 ( & V_10 -> V_67 ) ;
F_81 ( & V_10 -> V_136 , V_137 ) ;
V_47 = 0 ;
if ( ! V_54 -> V_61 && ! V_54 -> V_135 &&
F_72 ( V_8 -> V_6 ) )
F_70 ( & V_54 -> V_67 , V_124 ) ;
break;
}
V_134:
F_37 ( & V_8 -> V_92 ) ;
return V_47 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
struct V_68 * V_68 = F_19 ( V_2 -> V_69 ) ;
struct V_130 * V_131 ;
struct V_5 * V_6 , * V_115 ;
struct V_25 * V_32 ;
struct V_9 * V_10 ;
struct V_132 * V_133 ;
struct V_7 * V_8 ;
int V_47 ;
V_47 = F_59 ( V_2 , V_71 , & V_6 , & V_32 ) ;
if ( V_47 < 0 )
return V_47 ;
V_8 = F_2 ( V_6 ) ;
V_115 = F_41 ( V_68 , V_32 -> V_21 ) ;
if ( ! V_115 )
return - V_120 ;
V_10 = F_73 ( V_115 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_28 == V_129 )
return - V_119 ;
V_131 = F_75 ( V_10 ) ;
if ( F_76 ( V_8 ) && V_131 && V_32 -> V_35 == 0 ) {
F_77 (v, &vg->vlan_list, vlist) {
V_32 -> V_35 = V_133 -> V_35 ;
V_47 = F_78 ( V_8 , V_32 ) ;
if ( ! V_47 )
F_39 ( V_6 , V_10 , V_32 , V_106 ) ;
}
} else {
V_47 = F_78 ( V_8 , V_32 ) ;
if ( ! V_47 )
F_39 ( V_6 , V_10 , V_32 , V_106 ) ;
}
return V_47 ;
}
void F_83 ( void )
{
F_84 ( V_138 , V_81 , NULL , F_18 , NULL ) ;
F_84 ( V_138 , V_102 , F_74 , NULL , NULL ) ;
F_84 ( V_138 , V_106 , F_82 , NULL , NULL ) ;
}
void F_85 ( void )
{
F_86 ( V_138 , V_81 ) ;
F_86 ( V_138 , V_102 ) ;
F_86 ( V_138 , V_106 ) ;
}
