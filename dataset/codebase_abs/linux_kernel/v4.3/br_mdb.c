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
struct V_53 * V_53 = F_29 ( V_6 ) ;
struct V_1 * V_2 ;
int V_24 = - V_76 ;
V_2 = F_30 ( F_25 () , V_77 ) ;
if ( ! V_2 )
goto V_78;
V_24 = F_23 ( V_2 , V_6 , V_69 , 0 , 0 , type , V_79 ) ;
if ( V_24 < 0 ) {
F_31 ( V_2 ) ;
goto V_78;
}
F_32 ( V_2 , V_53 , 0 , V_80 , NULL , V_77 ) ;
return;
V_78:
F_33 ( V_53 , V_80 , V_24 ) ;
}
void F_34 ( struct V_5 * V_6 , struct V_9 * V_34 ,
struct V_81 * V_82 , int type , T_4 V_42 )
{
struct V_40 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_18 = V_34 -> V_6 -> V_18 ;
V_69 . V_44 . V_45 = V_82 -> V_45 ;
V_69 . V_44 . V_47 . V_48 = V_82 -> V_47 . V_48 ;
#if F_12 ( V_49 )
V_69 . V_44 . V_47 . V_51 = V_82 -> V_47 . V_51 ;
#endif
V_69 . V_42 = V_42 ;
V_69 . V_43 = V_82 -> V_43 ;
F_28 ( V_6 , & V_69 , type ) ;
}
static int F_35 ( struct V_1 * V_2 ,
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
static inline T_3 F_36 ( void )
{
return F_26 ( sizeof( struct V_62 ) )
+ F_27 ( sizeof( V_83 ) ) ;
}
void F_37 ( struct V_5 * V_6 , struct V_9 * V_34 ,
int type )
{
struct V_53 * V_53 = F_29 ( V_6 ) ;
struct V_1 * V_2 ;
int V_24 = - V_76 ;
int V_18 ;
V_18 = V_34 ? V_34 -> V_6 -> V_18 : 0 ;
V_2 = F_30 ( F_36 () , V_77 ) ;
if ( ! V_2 )
goto V_78;
V_24 = F_35 ( V_2 , V_6 , V_18 , 0 , 0 , type , V_79 ) ;
if ( V_24 < 0 ) {
F_31 ( V_2 ) ;
goto V_78;
}
F_32 ( V_2 , V_53 , 0 , V_80 , NULL , V_77 ) ;
return;
V_78:
F_33 ( V_53 , V_80 , V_24 ) ;
}
static bool F_38 ( struct V_40 * V_69 )
{
if ( V_69 -> V_18 == 0 )
return false ;
if ( V_69 -> V_44 . V_45 == F_11 ( V_46 ) ) {
if ( ! F_39 ( V_69 -> V_44 . V_47 . V_48 ) )
return false ;
if ( F_40 ( V_69 -> V_44 . V_47 . V_48 ) )
return false ;
#if F_12 ( V_49 )
} else if ( V_69 -> V_44 . V_45 == F_11 ( V_50 ) ) {
if ( F_41 ( & V_69 -> V_44 . V_47 . V_51 ) )
return false ;
#endif
} else
return false ;
if ( V_69 -> V_42 != V_84 && V_69 -> V_42 != V_85 )
return false ;
if ( V_69 -> V_43 >= V_86 )
return false ;
return true ;
}
static int F_42 ( struct V_1 * V_2 , struct V_55 * V_56 ,
struct V_5 * * V_87 , struct V_40 * * V_88 )
{
struct V_53 * V_53 = F_15 ( V_2 -> V_54 ) ;
struct V_40 * V_69 ;
struct V_62 * V_63 ;
struct V_11 * V_89 [ V_90 + 1 ] ;
struct V_5 * V_6 ;
int V_24 ;
V_24 = F_43 ( V_56 , sizeof( * V_63 ) , V_89 , V_90 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
V_63 = F_20 ( V_56 ) ;
if ( V_63 -> V_18 == 0 ) {
F_44 ( L_1 ) ;
return - V_91 ;
}
V_6 = F_45 ( V_53 , V_63 -> V_18 ) ;
if ( V_6 == NULL ) {
F_44 ( L_2 ) ;
return - V_92 ;
}
if ( ! ( V_6 -> V_60 & V_61 ) ) {
F_44 ( L_3 ) ;
return - V_93 ;
}
* V_87 = V_6 ;
if ( ! V_89 [ V_94 ] ||
F_46 ( V_89 [ V_94 ] ) != sizeof( struct V_40 ) ) {
F_44 ( L_4 ) ;
return - V_91 ;
}
V_69 = F_47 ( V_89 [ V_94 ] ) ;
if ( ! F_38 ( V_69 ) ) {
F_44 ( L_5 ) ;
return - V_91 ;
}
* V_88 = V_69 ;
return 0 ;
}
static int F_48 ( struct V_7 * V_8 , struct V_9 * V_34 ,
struct V_81 * V_82 , unsigned char V_42 )
{
struct V_30 * V_31 ;
struct V_32 * V_10 ;
struct V_32 T_1 * * V_33 ;
struct V_20 * V_21 ;
unsigned long V_95 = V_96 ;
int V_24 ;
V_21 = F_49 ( V_8 -> V_21 , V_8 ) ;
V_31 = F_50 ( V_21 , V_82 ) ;
if ( ! V_31 ) {
V_31 = F_51 ( V_8 , V_34 , V_82 ) ;
V_24 = F_52 ( V_31 ) ;
if ( F_53 ( V_31 ) )
return V_24 ;
}
for ( V_33 = & V_31 -> V_38 ;
( V_10 = F_49 ( * V_33 , V_8 ) ) != NULL ;
V_33 = & V_10 -> V_39 ) {
if ( V_10 -> V_34 == V_34 )
return - V_97 ;
if ( ( unsigned long ) V_10 -> V_34 < ( unsigned long ) V_34 )
break;
}
V_10 = F_54 ( V_34 , V_82 , * V_33 , V_42 ) ;
if ( F_55 ( ! V_10 ) )
return - V_98 ;
F_56 ( * V_33 , V_10 ) ;
if ( V_42 == V_85 )
F_57 ( & V_10 -> V_99 , V_95 + V_8 -> V_100 ) ;
return 0 ;
}
static int F_58 ( struct V_53 * V_53 , struct V_7 * V_8 ,
struct V_40 * V_69 )
{
struct V_81 V_101 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
int V_102 ;
if ( ! F_59 ( V_8 -> V_6 ) || V_8 -> V_27 )
return - V_91 ;
V_6 = F_45 ( V_53 , V_69 -> V_18 ) ;
if ( ! V_6 )
return - V_92 ;
V_10 = F_60 ( V_6 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_42 == V_103 )
return - V_91 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_43 = V_69 -> V_43 ;
V_101 . V_45 = V_69 -> V_44 . V_45 ;
if ( V_101 . V_45 == F_11 ( V_46 ) )
V_101 . V_47 . V_48 = V_69 -> V_44 . V_47 . V_48 ;
#if F_12 ( V_49 )
else
V_101 . V_47 . V_51 = V_69 -> V_44 . V_47 . V_51 ;
#endif
F_61 ( & V_8 -> V_104 ) ;
V_102 = F_48 ( V_8 , V_10 , & V_101 , V_69 -> V_42 ) ;
F_62 ( & V_8 -> V_104 ) ;
return V_102 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_53 * V_53 = F_15 ( V_2 -> V_54 ) ;
unsigned short V_43 = V_105 ;
struct V_5 * V_6 , * V_87 ;
struct V_40 * V_69 ;
struct V_9 * V_10 ;
struct V_106 * V_107 ;
struct V_7 * V_8 ;
int V_24 ;
V_24 = F_42 ( V_2 , V_56 , & V_6 , & V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = F_2 ( V_6 ) ;
V_87 = F_45 ( V_53 , V_69 -> V_18 ) ;
if ( ! V_87 )
return - V_92 ;
V_10 = F_60 ( V_87 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_42 == V_103 )
return - V_91 ;
V_107 = F_64 ( V_10 ) ;
if ( F_65 ( V_8 ) && V_107 && V_69 -> V_43 == 0 ) {
F_66 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_69 -> V_43 = V_43 ;
V_24 = F_58 ( V_53 , V_8 , V_69 ) ;
if ( V_24 )
break;
F_28 ( V_6 , V_69 , V_108 ) ;
}
} else {
V_24 = F_58 ( V_53 , V_8 , V_69 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_69 , V_108 ) ;
}
return V_24 ;
}
static int F_67 ( struct V_7 * V_8 , struct V_40 * V_69 )
{
struct V_20 * V_21 ;
struct V_30 * V_31 ;
struct V_32 * V_10 ;
struct V_32 T_1 * * V_33 ;
struct V_81 V_101 ;
int V_24 = - V_91 ;
if ( ! F_59 ( V_8 -> V_6 ) || V_8 -> V_27 )
return - V_91 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_43 = V_69 -> V_43 ;
V_101 . V_45 = V_69 -> V_44 . V_45 ;
if ( V_101 . V_45 == F_11 ( V_46 ) )
V_101 . V_47 . V_48 = V_69 -> V_44 . V_47 . V_48 ;
#if F_12 ( V_49 )
else
V_101 . V_47 . V_51 = V_69 -> V_44 . V_47 . V_51 ;
#endif
F_61 ( & V_8 -> V_104 ) ;
V_21 = F_49 ( V_8 -> V_21 , V_8 ) ;
V_31 = F_50 ( V_21 , & V_101 ) ;
if ( ! V_31 )
goto V_109;
for ( V_33 = & V_31 -> V_38 ;
( V_10 = F_49 ( * V_33 , V_8 ) ) != NULL ;
V_33 = & V_10 -> V_39 ) {
if ( ! V_10 -> V_34 || V_10 -> V_34 -> V_6 -> V_18 != V_69 -> V_18 )
continue;
if ( V_10 -> V_34 -> V_42 == V_103 )
goto V_109;
V_69 -> V_42 = V_10 -> V_42 ;
F_56 ( * V_33 , V_10 -> V_39 ) ;
F_68 ( & V_10 -> V_110 ) ;
F_69 ( & V_10 -> V_99 ) ;
F_70 ( & V_10 -> V_111 , V_112 ) ;
V_24 = 0 ;
if ( ! V_31 -> V_38 && ! V_31 -> V_110 &&
F_59 ( V_8 -> V_6 ) )
F_57 ( & V_31 -> V_99 , V_96 ) ;
break;
}
V_109:
F_62 ( & V_8 -> V_104 ) ;
return V_24 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_53 * V_53 = F_15 ( V_2 -> V_54 ) ;
unsigned short V_43 = V_105 ;
struct V_5 * V_6 , * V_87 ;
struct V_40 * V_69 ;
struct V_9 * V_10 ;
struct V_106 * V_107 ;
struct V_7 * V_8 ;
int V_24 ;
V_24 = F_42 ( V_2 , V_56 , & V_6 , & V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = F_2 ( V_6 ) ;
V_87 = F_45 ( V_53 , V_69 -> V_18 ) ;
if ( ! V_87 )
return - V_92 ;
V_10 = F_60 ( V_87 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_42 == V_103 )
return - V_91 ;
V_107 = F_64 ( V_10 ) ;
if ( F_65 ( V_8 ) && V_107 && V_69 -> V_43 == 0 ) {
F_66 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_69 -> V_43 = V_43 ;
V_24 = F_67 ( V_8 , V_69 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_69 , V_113 ) ;
}
} else {
V_24 = F_67 ( V_8 , V_69 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_69 , V_113 ) ;
}
return V_24 ;
}
void F_72 ( void )
{
F_73 ( V_114 , V_66 , NULL , F_14 , NULL ) ;
F_73 ( V_114 , V_108 , F_63 , NULL , NULL ) ;
F_73 ( V_114 , V_113 , F_71 , NULL , NULL ) ;
}
void F_74 ( void )
{
F_75 ( V_114 , V_66 ) ;
F_75 ( V_114 , V_108 ) ;
F_75 ( V_114 , V_113 ) ;
}
