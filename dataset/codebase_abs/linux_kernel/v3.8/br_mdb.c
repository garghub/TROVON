static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
if ( ! V_8 -> V_15 || F_3 ( & V_8 -> V_16 ) )
return 0 ;
V_14 = F_4 ( V_2 , V_17 ) ;
if ( V_14 == NULL )
return - V_18 ;
F_5 (p, n, &br->router_list, rlist) {
if ( V_10 && F_6 ( V_2 , V_19 , V_10 -> V_6 -> V_20 ) )
goto V_21;
}
F_7 ( V_2 , V_14 ) ;
return 0 ;
V_21:
F_8 ( V_2 , V_14 ) ;
return - V_18 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_22 * V_23 ;
struct V_13 * V_14 , * V_24 ;
int V_25 , V_26 = 0 ;
int V_27 = 0 , V_28 = V_4 -> args [ 1 ] ;
if ( V_8 -> V_29 )
return 0 ;
V_23 = F_10 ( V_8 -> V_23 ) ;
if ( ! V_23 )
return 0 ;
V_14 = F_4 ( V_2 , V_30 ) ;
if ( V_14 == NULL )
return - V_18 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_31 ; V_25 ++ ) {
struct V_11 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_10 , * * V_36 ;
struct V_9 * V_37 ;
F_5 (mp, h, &mdb->mhash[i], hlist[mdb->ver]) {
if ( V_27 < V_28 )
goto V_38;
V_24 = F_4 ( V_2 , V_39 ) ;
if ( V_24 == NULL ) {
V_26 = - V_18 ;
goto V_40;
}
for ( V_36 = & V_34 -> V_41 ;
( V_10 = F_10 ( * V_36 ) ) != NULL ;
V_36 = & V_10 -> V_42 ) {
V_37 = V_10 -> V_37 ;
if ( V_37 ) {
struct V_43 V_44 ;
V_44 . V_20 = V_37 -> V_6 -> V_20 ;
V_44 . V_45 = V_10 -> V_45 ;
if ( V_10 -> V_46 . V_47 == F_11 ( V_48 ) )
V_44 . V_46 . V_49 . V_50 = V_10 -> V_46 . V_49 . V_50 ;
#if F_12 ( V_51 )
if ( V_10 -> V_46 . V_47 == F_11 ( V_52 ) )
V_44 . V_46 . V_49 . V_53 = V_10 -> V_46 . V_49 . V_53 ;
#endif
V_44 . V_46 . V_47 = V_10 -> V_46 . V_47 ;
if ( F_13 ( V_2 , V_54 , sizeof( V_44 ) , & V_44 ) ) {
F_8 ( V_2 , V_24 ) ;
V_26 = - V_18 ;
goto V_40;
}
}
}
F_7 ( V_2 , V_24 ) ;
V_38:
V_27 ++ ;
}
}
V_40:
V_4 -> args [ 1 ] = V_27 ;
F_7 ( V_2 , V_14 ) ;
return V_26 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_55 * V_55 = F_15 ( V_2 -> V_56 ) ;
struct V_57 * V_58 = NULL ;
int V_27 = 0 , V_28 ;
V_28 = V_4 -> args [ 0 ] ;
F_16 () ;
V_4 -> V_59 = V_55 -> V_60 + V_61 ;
F_17 (net, dev) {
if ( V_6 -> V_62 & V_63 ) {
struct V_64 * V_65 ;
if ( V_27 < V_28 )
goto V_38;
V_58 = F_18 ( V_2 , F_19 ( V_4 -> V_2 ) . V_66 ,
V_4 -> V_58 -> V_67 , V_68 ,
sizeof( * V_65 ) , V_69 ) ;
if ( V_58 == NULL )
break;
V_65 = F_20 ( V_58 ) ;
V_65 -> V_20 = V_6 -> V_20 ;
if ( F_9 ( V_2 , V_4 , V_6 ) < 0 )
goto V_40;
if ( F_1 ( V_2 , V_4 , V_6 ) < 0 )
goto V_40;
V_4 -> args [ 1 ] = 0 ;
F_21 ( V_2 , V_58 ) ;
V_38:
V_27 ++ ;
}
}
V_40:
if ( V_58 )
F_21 ( V_2 , V_58 ) ;
F_22 () ;
V_4 -> args [ 0 ] = V_27 ;
return V_2 -> V_70 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_43 * V_71 , T_1 V_72 ,
T_1 V_59 , int type , unsigned int V_73 )
{
struct V_57 * V_58 ;
struct V_64 * V_65 ;
struct V_13 * V_14 , * V_24 ;
V_58 = F_18 ( V_2 , V_72 , V_59 , type , sizeof( * V_65 ) , V_69 ) ;
if ( ! V_58 )
return - V_18 ;
V_65 = F_20 ( V_58 ) ;
V_65 -> V_74 = V_75 ;
V_65 -> V_20 = V_6 -> V_20 ;
V_14 = F_4 ( V_2 , V_30 ) ;
if ( V_14 == NULL )
goto V_76;
V_24 = F_4 ( V_2 , V_39 ) ;
if ( V_24 == NULL )
goto V_77;
if ( F_13 ( V_2 , V_54 , sizeof( * V_71 ) , V_71 ) )
goto V_77;
F_7 ( V_2 , V_24 ) ;
F_7 ( V_2 , V_14 ) ;
return F_21 ( V_2 , V_58 ) ;
V_77:
F_7 ( V_2 , V_14 ) ;
V_76:
F_24 ( V_2 , V_58 ) ;
return - V_18 ;
}
static inline T_2 F_25 ( void )
{
return F_26 ( sizeof( struct V_64 ) )
+ F_27 ( sizeof( struct V_43 ) ) ;
}
static void F_28 ( struct V_5 * V_6 , struct V_43 * V_71 ,
int type )
{
struct V_55 * V_55 = F_29 ( V_6 ) ;
struct V_1 * V_2 ;
int V_26 = - V_78 ;
V_2 = F_30 ( F_25 () , V_79 ) ;
if ( ! V_2 )
goto V_80;
V_26 = F_23 ( V_2 , V_6 , V_71 , 0 , 0 , type , V_81 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 ) ;
goto V_80;
}
F_32 ( V_2 , V_55 , 0 , V_82 , NULL , V_79 ) ;
return;
V_80:
F_33 ( V_55 , V_82 , V_26 ) ;
}
void F_34 ( struct V_5 * V_6 , struct V_9 * V_37 ,
struct V_83 * V_84 , int type )
{
struct V_43 V_71 ;
V_71 . V_20 = V_37 -> V_6 -> V_20 ;
V_71 . V_46 . V_47 = V_84 -> V_47 ;
V_71 . V_46 . V_49 . V_50 = V_84 -> V_49 . V_50 ;
#if F_12 ( V_51 )
V_71 . V_46 . V_49 . V_53 = V_84 -> V_49 . V_53 ;
#endif
F_28 ( V_6 , & V_71 , type ) ;
}
static bool F_35 ( struct V_43 * V_71 )
{
if ( V_71 -> V_20 == 0 )
return false ;
if ( V_71 -> V_46 . V_47 == F_11 ( V_48 ) ) {
if ( ! F_36 ( V_71 -> V_46 . V_49 . V_50 ) )
return false ;
if ( F_37 ( V_71 -> V_46 . V_49 . V_50 ) )
return false ;
#if F_12 ( V_51 )
} else if ( V_71 -> V_46 . V_47 == F_11 ( V_52 ) ) {
if ( ! F_38 ( & V_71 -> V_46 . V_49 . V_53 ) )
return false ;
#endif
} else
return false ;
if ( V_71 -> V_45 != V_85 && V_71 -> V_45 != V_86 )
return false ;
return true ;
}
static int F_39 ( struct V_1 * V_2 , struct V_57 * V_58 ,
struct V_5 * * V_87 , struct V_43 * * V_88 )
{
struct V_55 * V_55 = F_15 ( V_2 -> V_56 ) ;
struct V_43 * V_71 ;
struct V_64 * V_65 ;
struct V_13 * V_89 [ V_90 + 1 ] ;
struct V_5 * V_6 ;
int V_26 ;
if ( ! F_40 ( V_91 ) )
return - V_92 ;
V_26 = F_41 ( V_58 , sizeof( * V_65 ) , V_89 , V_93 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_65 = F_20 ( V_58 ) ;
if ( V_65 -> V_20 == 0 ) {
F_42 ( L_1 ) ;
return - V_94 ;
}
V_6 = F_43 ( V_55 , V_65 -> V_20 ) ;
if ( V_6 == NULL ) {
F_42 ( L_2 ) ;
return - V_95 ;
}
if ( ! ( V_6 -> V_62 & V_63 ) ) {
F_42 ( L_3 ) ;
return - V_96 ;
}
* V_87 = V_6 ;
if ( ! V_89 [ V_93 ] ||
F_44 ( V_89 [ V_93 ] ) != sizeof( struct V_43 ) ) {
F_42 ( L_4 ) ;
return - V_94 ;
}
V_71 = F_45 ( V_89 [ V_93 ] ) ;
if ( ! F_35 ( V_71 ) ) {
F_42 ( L_5 ) ;
return - V_94 ;
}
* V_88 = V_71 ;
return 0 ;
}
static int F_46 ( struct V_7 * V_8 , struct V_9 * V_37 ,
struct V_83 * V_84 , unsigned char V_45 )
{
struct V_33 * V_34 ;
struct V_35 * V_10 ;
struct V_35 T_3 * * V_36 ;
struct V_22 * V_23 ;
int V_26 ;
V_23 = F_47 ( V_8 -> V_23 , V_8 ) ;
V_34 = F_48 ( V_23 , V_84 ) ;
if ( ! V_34 ) {
V_34 = F_49 ( V_8 , V_37 , V_84 ) ;
V_26 = F_50 ( V_34 ) ;
if ( F_51 ( V_34 ) )
return V_26 ;
}
for ( V_36 = & V_34 -> V_41 ;
( V_10 = F_47 ( * V_36 , V_8 ) ) != NULL ;
V_36 = & V_10 -> V_42 ) {
if ( V_10 -> V_37 == V_37 )
return - V_97 ;
if ( ( unsigned long ) V_10 -> V_37 < ( unsigned long ) V_37 )
break;
}
V_10 = F_52 ( V_37 , V_84 , * V_36 , V_45 ) ;
if ( F_53 ( ! V_10 ) )
return - V_98 ;
F_54 ( * V_36 , V_10 ) ;
F_34 ( V_8 -> V_6 , V_37 , V_84 , V_99 ) ;
return 0 ;
}
static int F_55 ( struct V_55 * V_55 , struct V_7 * V_8 ,
struct V_43 * V_71 )
{
struct V_83 V_100 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
int V_101 ;
if ( ! F_56 ( V_8 -> V_6 ) || V_8 -> V_29 )
return - V_94 ;
V_6 = F_43 ( V_55 , V_71 -> V_20 ) ;
if ( ! V_6 )
return - V_95 ;
V_10 = F_57 ( V_6 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_45 == V_102 )
return - V_94 ;
V_100 . V_47 = V_71 -> V_46 . V_47 ;
if ( V_100 . V_47 == F_11 ( V_48 ) )
V_100 . V_49 . V_50 = V_71 -> V_46 . V_49 . V_50 ;
#if F_12 ( V_51 )
else
V_100 . V_49 . V_53 = V_71 -> V_46 . V_49 . V_53 ;
#endif
F_58 ( & V_8 -> V_103 ) ;
V_101 = F_46 ( V_8 , V_10 , & V_100 , V_71 -> V_45 ) ;
F_59 ( & V_8 -> V_103 ) ;
return V_101 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_57 * V_58 , void * V_104 )
{
struct V_55 * V_55 = F_15 ( V_2 -> V_56 ) ;
struct V_43 * V_71 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_26 ;
V_26 = F_39 ( V_2 , V_58 , & V_6 , & V_71 ) ;
if ( V_26 < 0 )
return V_26 ;
V_8 = F_2 ( V_6 ) ;
V_26 = F_55 ( V_55 , V_8 , V_71 ) ;
if ( ! V_26 )
F_28 ( V_6 , V_71 , V_99 ) ;
return V_26 ;
}
static int F_61 ( struct V_7 * V_8 , struct V_43 * V_71 )
{
struct V_22 * V_23 ;
struct V_33 * V_34 ;
struct V_35 * V_10 ;
struct V_35 T_3 * * V_36 ;
struct V_83 V_100 ;
int V_26 = - V_94 ;
if ( ! F_56 ( V_8 -> V_6 ) || V_8 -> V_29 )
return - V_94 ;
if ( F_62 ( & V_8 -> V_105 ) )
return - V_106 ;
V_100 . V_47 = V_71 -> V_46 . V_47 ;
if ( V_100 . V_47 == F_11 ( V_48 ) )
V_100 . V_49 . V_50 = V_71 -> V_46 . V_49 . V_50 ;
#if F_12 ( V_51 )
else
V_100 . V_49 . V_53 = V_71 -> V_46 . V_49 . V_53 ;
#endif
F_58 ( & V_8 -> V_103 ) ;
V_23 = F_47 ( V_8 -> V_23 , V_8 ) ;
V_34 = F_48 ( V_23 , & V_100 ) ;
if ( ! V_34 )
goto V_107;
for ( V_36 = & V_34 -> V_41 ;
( V_10 = F_47 ( * V_36 , V_8 ) ) != NULL ;
V_36 = & V_10 -> V_42 ) {
if ( ! V_10 -> V_37 || V_10 -> V_37 -> V_6 -> V_20 != V_71 -> V_20 )
continue;
if ( V_10 -> V_37 -> V_45 == V_102 )
goto V_107;
F_54 ( * V_36 , V_10 -> V_42 ) ;
F_63 ( & V_10 -> V_108 ) ;
F_64 ( & V_10 -> V_109 ) ;
F_65 ( & V_10 -> V_110 , V_111 ) ;
V_26 = 0 ;
if ( ! V_34 -> V_41 && ! V_34 -> V_108 &&
F_56 ( V_8 -> V_6 ) )
F_66 ( & V_34 -> V_109 , V_112 ) ;
break;
}
V_107:
F_59 ( & V_8 -> V_103 ) ;
return V_26 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_57 * V_58 , void * V_104 )
{
struct V_5 * V_6 ;
struct V_43 * V_71 ;
struct V_7 * V_8 ;
int V_26 ;
V_26 = F_39 ( V_2 , V_58 , & V_6 , & V_71 ) ;
if ( V_26 < 0 )
return V_26 ;
V_8 = F_2 ( V_6 ) ;
V_26 = F_61 ( V_8 , V_71 ) ;
if ( ! V_26 )
F_28 ( V_6 , V_71 , V_113 ) ;
return V_26 ;
}
void F_68 ( void )
{
F_69 ( V_114 , V_68 , NULL , F_14 , NULL ) ;
F_69 ( V_114 , V_99 , F_60 , NULL , NULL ) ;
F_69 ( V_114 , V_113 , F_67 , NULL , NULL ) ;
}
void F_70 ( void )
{
F_71 ( V_114 , V_68 ) ;
F_71 ( V_114 , V_99 ) ;
F_71 ( V_114 , V_113 ) ;
}
