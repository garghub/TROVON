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
if ( V_10 -> V_43 . V_44 == F_11 ( V_45 ) )
V_41 . V_43 . V_46 . V_47 = V_10 -> V_43 . V_46 . V_47 ;
#if F_12 ( V_48 )
if ( V_10 -> V_43 . V_44 == F_11 ( V_49 ) )
V_41 . V_43 . V_46 . V_50 = V_10 -> V_43 . V_46 . V_50 ;
#endif
V_41 . V_43 . V_44 = V_10 -> V_43 . V_44 ;
if ( F_13 ( V_2 , V_51 , sizeof( V_41 ) , & V_41 ) ) {
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
struct V_52 * V_52 = F_15 ( V_2 -> V_53 ) ;
struct V_54 * V_55 = NULL ;
int V_25 = 0 , V_26 ;
V_26 = V_4 -> args [ 0 ] ;
F_16 () ;
V_4 -> V_56 = V_52 -> V_57 + V_58 ;
F_17 (net, dev) {
if ( V_6 -> V_59 & V_60 ) {
struct V_61 * V_62 ;
if ( V_25 < V_26 )
goto V_35;
V_55 = F_18 ( V_2 , F_19 ( V_4 -> V_2 ) . V_63 ,
V_4 -> V_55 -> V_64 , V_65 ,
sizeof( * V_62 ) , V_66 ) ;
if ( V_55 == NULL )
break;
V_62 = F_20 ( V_55 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_18 = V_6 -> V_18 ;
if ( F_9 ( V_2 , V_4 , V_6 ) < 0 )
goto V_37;
if ( F_1 ( V_2 , V_4 , V_6 ) < 0 )
goto V_37;
V_4 -> args [ 1 ] = 0 ;
F_21 ( V_2 , V_55 ) ;
V_35:
V_25 ++ ;
}
}
V_37:
if ( V_55 )
F_21 ( V_2 , V_55 ) ;
F_22 () ;
V_4 -> args [ 0 ] = V_25 ;
return V_2 -> V_67 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_40 * V_68 , T_2 V_69 ,
T_2 V_56 , int type , unsigned int V_70 )
{
struct V_54 * V_55 ;
struct V_61 * V_62 ;
struct V_11 * V_12 , * V_22 ;
V_55 = F_18 ( V_2 , V_69 , V_56 , type , sizeof( * V_62 ) , 0 ) ;
if ( ! V_55 )
return - V_16 ;
V_62 = F_20 ( V_55 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_71 = V_72 ;
V_62 -> V_18 = V_6 -> V_18 ;
V_12 = F_4 ( V_2 , V_28 ) ;
if ( V_12 == NULL )
goto V_73;
V_22 = F_4 ( V_2 , V_36 ) ;
if ( V_22 == NULL )
goto V_74;
if ( F_13 ( V_2 , V_51 , sizeof( * V_68 ) , V_68 ) )
goto V_74;
F_7 ( V_2 , V_22 ) ;
F_7 ( V_2 , V_12 ) ;
F_21 ( V_2 , V_55 ) ;
return 0 ;
V_74:
F_7 ( V_2 , V_12 ) ;
V_73:
F_24 ( V_2 , V_55 ) ;
return - V_16 ;
}
static inline T_3 F_25 ( void )
{
return F_26 ( sizeof( struct V_61 ) )
+ F_27 ( sizeof( struct V_40 ) ) ;
}
static void F_28 ( struct V_5 * V_6 , struct V_40 * V_68 ,
int type )
{
struct V_52 * V_52 = F_29 ( V_6 ) ;
struct V_1 * V_2 ;
int V_24 = - V_75 ;
V_2 = F_30 ( F_25 () , V_76 ) ;
if ( ! V_2 )
goto V_77;
V_24 = F_23 ( V_2 , V_6 , V_68 , 0 , 0 , type , V_78 ) ;
if ( V_24 < 0 ) {
F_31 ( V_2 ) ;
goto V_77;
}
F_32 ( V_2 , V_52 , 0 , V_79 , NULL , V_76 ) ;
return;
V_77:
F_33 ( V_52 , V_79 , V_24 ) ;
}
void F_34 ( struct V_5 * V_6 , struct V_9 * V_34 ,
struct V_80 * V_81 , int type )
{
struct V_40 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_18 = V_34 -> V_6 -> V_18 ;
V_68 . V_43 . V_44 = V_81 -> V_44 ;
V_68 . V_43 . V_46 . V_47 = V_81 -> V_46 . V_47 ;
#if F_12 ( V_48 )
V_68 . V_43 . V_46 . V_50 = V_81 -> V_46 . V_50 ;
#endif
F_28 ( V_6 , & V_68 , type ) ;
}
static bool F_35 ( struct V_40 * V_68 )
{
if ( V_68 -> V_18 == 0 )
return false ;
if ( V_68 -> V_43 . V_44 == F_11 ( V_45 ) ) {
if ( ! F_36 ( V_68 -> V_43 . V_46 . V_47 ) )
return false ;
if ( F_37 ( V_68 -> V_43 . V_46 . V_47 ) )
return false ;
#if F_12 ( V_48 )
} else if ( V_68 -> V_43 . V_44 == F_11 ( V_49 ) ) {
if ( F_38 ( & V_68 -> V_43 . V_46 . V_50 ) )
return false ;
#endif
} else
return false ;
if ( V_68 -> V_42 != V_82 && V_68 -> V_42 != V_83 )
return false ;
return true ;
}
static int F_39 ( struct V_1 * V_2 , struct V_54 * V_55 ,
struct V_5 * * V_84 , struct V_40 * * V_85 )
{
struct V_52 * V_52 = F_15 ( V_2 -> V_53 ) ;
struct V_40 * V_68 ;
struct V_61 * V_62 ;
struct V_11 * V_86 [ V_87 + 1 ] ;
struct V_5 * V_6 ;
int V_24 ;
V_24 = F_40 ( V_55 , sizeof( * V_62 ) , V_86 , V_87 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
V_62 = F_20 ( V_55 ) ;
if ( V_62 -> V_18 == 0 ) {
F_41 ( L_1 ) ;
return - V_88 ;
}
V_6 = F_42 ( V_52 , V_62 -> V_18 ) ;
if ( V_6 == NULL ) {
F_41 ( L_2 ) ;
return - V_89 ;
}
if ( ! ( V_6 -> V_59 & V_60 ) ) {
F_41 ( L_3 ) ;
return - V_90 ;
}
* V_84 = V_6 ;
if ( ! V_86 [ V_91 ] ||
F_43 ( V_86 [ V_91 ] ) != sizeof( struct V_40 ) ) {
F_41 ( L_4 ) ;
return - V_88 ;
}
V_68 = F_44 ( V_86 [ V_91 ] ) ;
if ( ! F_35 ( V_68 ) ) {
F_41 ( L_5 ) ;
return - V_88 ;
}
* V_85 = V_68 ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 , struct V_9 * V_34 ,
struct V_80 * V_81 , unsigned char V_42 )
{
struct V_30 * V_31 ;
struct V_32 * V_10 ;
struct V_32 T_1 * * V_33 ;
struct V_20 * V_21 ;
int V_24 ;
V_21 = F_46 ( V_8 -> V_21 , V_8 ) ;
V_31 = F_47 ( V_21 , V_81 ) ;
if ( ! V_31 ) {
V_31 = F_48 ( V_8 , V_34 , V_81 ) ;
V_24 = F_49 ( V_31 ) ;
if ( F_50 ( V_31 ) )
return V_24 ;
}
for ( V_33 = & V_31 -> V_38 ;
( V_10 = F_46 ( * V_33 , V_8 ) ) != NULL ;
V_33 = & V_10 -> V_39 ) {
if ( V_10 -> V_34 == V_34 )
return - V_92 ;
if ( ( unsigned long ) V_10 -> V_34 < ( unsigned long ) V_34 )
break;
}
V_10 = F_51 ( V_34 , V_81 , * V_33 , V_42 ) ;
if ( F_52 ( ! V_10 ) )
return - V_93 ;
F_53 ( * V_33 , V_10 ) ;
F_34 ( V_8 -> V_6 , V_34 , V_81 , V_94 ) ;
return 0 ;
}
static int F_54 ( struct V_52 * V_52 , struct V_7 * V_8 ,
struct V_40 * V_68 )
{
struct V_80 V_95 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
int V_96 ;
if ( ! F_55 ( V_8 -> V_6 ) || V_8 -> V_27 )
return - V_88 ;
V_6 = F_42 ( V_52 , V_68 -> V_18 ) ;
if ( ! V_6 )
return - V_89 ;
V_10 = F_56 ( V_6 ) ;
if ( ! V_10 || V_10 -> V_8 != V_8 || V_10 -> V_42 == V_97 )
return - V_88 ;
V_95 . V_44 = V_68 -> V_43 . V_44 ;
if ( V_95 . V_44 == F_11 ( V_45 ) )
V_95 . V_46 . V_47 = V_68 -> V_43 . V_46 . V_47 ;
#if F_12 ( V_48 )
else
V_95 . V_46 . V_50 = V_68 -> V_43 . V_46 . V_50 ;
#endif
F_57 ( & V_8 -> V_98 ) ;
V_96 = F_45 ( V_8 , V_10 , & V_95 , V_68 -> V_42 ) ;
F_58 ( & V_8 -> V_98 ) ;
return V_96 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_52 * V_52 = F_15 ( V_2 -> V_53 ) ;
struct V_40 * V_68 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_24 ;
V_24 = F_39 ( V_2 , V_55 , & V_6 , & V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = F_2 ( V_6 ) ;
V_24 = F_54 ( V_52 , V_8 , V_68 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_68 , V_94 ) ;
return V_24 ;
}
static int F_60 ( struct V_7 * V_8 , struct V_40 * V_68 )
{
struct V_20 * V_21 ;
struct V_30 * V_31 ;
struct V_32 * V_10 ;
struct V_32 T_1 * * V_33 ;
struct V_80 V_95 ;
int V_24 = - V_88 ;
if ( ! F_55 ( V_8 -> V_6 ) || V_8 -> V_27 )
return - V_88 ;
V_95 . V_44 = V_68 -> V_43 . V_44 ;
if ( V_95 . V_44 == F_11 ( V_45 ) ) {
if ( F_61 ( & V_8 -> V_99 . V_100 ) )
return - V_101 ;
V_95 . V_46 . V_47 = V_68 -> V_43 . V_46 . V_47 ;
#if F_12 ( V_48 )
} else {
if ( F_61 ( & V_8 -> V_102 . V_100 ) )
return - V_101 ;
V_95 . V_46 . V_50 = V_68 -> V_43 . V_46 . V_50 ;
#endif
}
F_57 ( & V_8 -> V_98 ) ;
V_21 = F_46 ( V_8 -> V_21 , V_8 ) ;
V_31 = F_47 ( V_21 , & V_95 ) ;
if ( ! V_31 )
goto V_103;
for ( V_33 = & V_31 -> V_38 ;
( V_10 = F_46 ( * V_33 , V_8 ) ) != NULL ;
V_33 = & V_10 -> V_39 ) {
if ( ! V_10 -> V_34 || V_10 -> V_34 -> V_6 -> V_18 != V_68 -> V_18 )
continue;
if ( V_10 -> V_34 -> V_42 == V_97 )
goto V_103;
F_53 ( * V_33 , V_10 -> V_39 ) ;
F_62 ( & V_10 -> V_104 ) ;
F_63 ( & V_10 -> V_100 ) ;
F_64 ( & V_10 -> V_105 , V_106 ) ;
V_24 = 0 ;
if ( ! V_31 -> V_38 && ! V_31 -> V_104 &&
F_55 ( V_8 -> V_6 ) )
F_65 ( & V_31 -> V_100 , V_107 ) ;
break;
}
V_103:
F_58 ( & V_8 -> V_98 ) ;
return V_24 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_5 * V_6 ;
struct V_40 * V_68 ;
struct V_7 * V_8 ;
int V_24 ;
V_24 = F_39 ( V_2 , V_55 , & V_6 , & V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = F_2 ( V_6 ) ;
V_24 = F_60 ( V_8 , V_68 ) ;
if ( ! V_24 )
F_28 ( V_6 , V_68 , V_108 ) ;
return V_24 ;
}
void F_67 ( void )
{
F_68 ( V_109 , V_65 , NULL , F_14 , NULL ) ;
F_68 ( V_109 , V_94 , F_59 , NULL , NULL ) ;
F_68 ( V_109 , V_108 , F_66 , NULL , NULL ) ;
}
void F_69 ( void )
{
F_70 ( V_109 , V_65 ) ;
F_70 ( V_109 , V_94 ) ;
F_70 ( V_109 , V_108 ) ;
}
