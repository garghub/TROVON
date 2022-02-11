static struct V_1 * F_1 ( int V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
F_2 ( & V_6 ) ;
F_3 (pcache, &pid_caches_lh, list)
if ( V_4 -> V_2 == V_2 )
goto V_7;
V_4 = F_4 ( sizeof( struct V_3 ) , V_8 ) ;
if ( V_4 == NULL )
goto V_9;
snprintf ( V_4 -> V_10 , sizeof( V_4 -> V_10 ) , L_1 , V_2 ) ;
V_5 = F_5 ( V_4 -> V_10 ,
sizeof( struct V_11 ) + ( V_2 - 1 ) * sizeof( struct V_12 ) ,
0 , V_13 , NULL ) ;
if ( V_5 == NULL )
goto V_14;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_5 ;
F_6 ( & V_4 -> V_15 , & V_16 ) ;
V_7:
F_7 ( & V_6 ) ;
return V_4 -> V_5 ;
V_14:
F_8 ( V_4 ) ;
V_9:
F_7 ( & V_6 ) ;
return NULL ;
}
static void F_9 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_10 ( V_18 , struct V_19 , V_21 ) ;
F_11 ( V_20 ) ;
}
static struct V_19 * F_12 ( struct V_22 * V_23 ,
struct V_19 * V_24 )
{
struct V_19 * V_20 ;
unsigned int V_25 = V_24 -> V_25 + 1 ;
int V_26 ;
int V_27 ;
if ( V_25 > V_28 ) {
V_27 = - V_29 ;
goto V_7;
}
V_27 = - V_30 ;
V_20 = F_13 ( V_31 , V_8 ) ;
if ( V_20 == NULL )
goto V_7;
V_20 -> V_32 [ 0 ] . V_33 = F_14 ( V_34 , V_8 ) ;
if ( ! V_20 -> V_32 [ 0 ] . V_33 )
goto V_35;
V_20 -> V_36 = F_1 ( V_25 + 1 ) ;
if ( V_20 -> V_36 == NULL )
goto V_37;
V_27 = F_15 ( & V_20 -> V_20 ) ;
if ( V_27 )
goto V_37;
V_20 -> V_20 . V_38 = & V_39 ;
F_16 ( & V_20 -> V_40 ) ;
V_20 -> V_25 = V_25 ;
V_20 -> V_41 = F_17 ( V_24 ) ;
V_20 -> V_23 = F_18 ( V_23 ) ;
V_20 -> V_42 = V_43 ;
F_19 ( & V_20 -> V_21 , F_9 ) ;
F_20 ( 0 , V_20 -> V_32 [ 0 ] . V_33 ) ;
F_21 ( & V_20 -> V_32 [ 0 ] . V_44 , V_45 - 1 ) ;
for ( V_26 = 1 ; V_26 < V_46 ; V_26 ++ )
F_21 ( & V_20 -> V_32 [ V_26 ] . V_44 , V_45 ) ;
return V_20 ;
V_37:
F_8 ( V_20 -> V_32 [ 0 ] . V_33 ) ;
V_35:
F_22 ( V_31 , V_20 ) ;
V_7:
return F_23 ( V_27 ) ;
}
static void F_24 ( struct V_47 * V_48 )
{
F_22 ( V_31 ,
F_10 ( V_48 , struct V_19 , V_49 ) ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
int V_26 ;
F_26 ( & V_20 -> V_20 ) ;
for ( V_26 = 0 ; V_26 < V_46 ; V_26 ++ )
F_8 ( V_20 -> V_32 [ V_26 ] . V_33 ) ;
F_27 ( V_20 -> V_23 ) ;
F_28 ( & V_20 -> V_49 , F_24 ) ;
}
struct V_19 * F_29 ( unsigned long V_50 ,
struct V_22 * V_23 , struct V_19 * V_51 )
{
if ( ! ( V_50 & V_52 ) )
return F_17 ( V_51 ) ;
if ( F_30 ( V_53 ) != V_51 )
return F_23 ( - V_29 ) ;
return F_12 ( V_23 , V_51 ) ;
}
static void F_31 ( struct V_40 * V_40 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( V_40 , struct V_19 , V_40 ) ;
F_25 ( V_20 ) ;
}
void F_32 ( struct V_19 * V_20 )
{
struct V_19 * V_41 ;
while ( V_20 != & V_54 ) {
V_41 = V_20 -> V_41 ;
if ( ! F_33 ( & V_20 -> V_40 , F_31 ) )
break;
V_20 = V_41 ;
}
}
void F_34 ( struct V_19 * V_55 )
{
int V_56 ;
int V_57 ;
struct V_58 * V_59 , * V_60 = V_53 ;
int V_61 = F_35 ( V_60 ) ? 1 : 2 ;
F_36 ( V_55 ) ;
F_37 ( & V_60 -> V_62 -> V_63 ) ;
V_60 -> V_62 -> V_64 [ V_65 - 1 ] . V_66 . V_67 = V_68 ;
F_38 ( & V_60 -> V_62 -> V_63 ) ;
F_39 ( & V_69 ) ;
V_56 = F_40 ( V_55 , 1 ) ;
while ( V_56 > 0 ) {
F_41 () ;
V_59 = F_42 ( F_43 ( V_56 ) , V_70 ) ;
if ( V_59 && ! F_44 ( V_59 ) )
F_45 ( V_71 , V_72 , V_59 ) ;
F_46 () ;
V_56 = F_40 ( V_55 , V_56 ) ;
}
F_47 ( & V_69 ) ;
do {
F_48 ( V_73 ) ;
V_57 = F_49 ( - 1 , NULL , V_74 , NULL ) ;
} while ( V_57 != - V_75 );
for (; ; ) {
F_50 ( V_76 ) ;
if ( V_55 -> V_42 == V_61 )
break;
F_51 () ;
}
F_52 ( V_77 ) ;
if ( V_55 -> V_78 )
V_53 -> signal -> V_79 = V_55 -> V_78 ;
F_53 ( V_55 ) ;
return;
}
static int F_54 ( struct V_80 * V_81 , int V_82 ,
void T_1 * V_83 , T_2 * V_84 , T_3 * V_85 )
{
struct V_19 * V_55 = F_30 ( V_53 ) ;
struct V_80 V_86 = * V_81 ;
if ( V_82 && ! F_55 ( V_55 -> V_23 , V_87 ) )
return - V_88 ;
V_86 . V_89 = & V_55 -> V_90 ;
return F_56 ( & V_86 , V_82 , V_83 , V_84 , V_85 ) ;
}
int F_57 ( struct V_19 * V_55 , int V_91 )
{
if ( V_55 == & V_54 )
return 0 ;
switch ( V_91 ) {
case V_92 :
case V_93 :
V_55 -> V_78 = V_94 ;
break;
case V_95 :
case V_96 :
V_55 -> V_78 = V_97 ;
break;
default:
return - V_29 ;
}
F_39 ( & V_69 ) ;
F_58 ( V_71 , V_55 -> V_98 ) ;
F_47 ( & V_69 ) ;
F_59 ( 0 ) ;
return 0 ;
}
static inline struct V_19 * F_60 ( struct V_99 * V_20 )
{
return F_10 ( V_20 , struct V_19 , V_20 ) ;
}
static struct V_99 * F_61 ( struct V_58 * V_59 )
{
struct V_19 * V_20 ;
F_41 () ;
V_20 = F_30 ( V_59 ) ;
if ( V_20 )
F_17 ( V_20 ) ;
F_46 () ;
return V_20 ? & V_20 -> V_20 : NULL ;
}
static void F_62 ( struct V_99 * V_20 )
{
F_32 ( F_60 ( V_20 ) ) ;
}
static int F_63 ( struct V_100 * V_100 , struct V_99 * V_20 )
{
struct V_19 * V_101 = F_30 ( V_53 ) ;
struct V_19 * V_102 , * V_103 = F_60 ( V_20 ) ;
if ( ! F_55 ( V_103 -> V_23 , V_87 ) ||
! F_55 ( F_64 () , V_87 ) )
return - V_88 ;
if ( V_103 -> V_25 < V_101 -> V_25 )
return - V_29 ;
V_102 = V_103 ;
while ( V_102 -> V_25 > V_101 -> V_25 )
V_102 = V_102 -> V_41 ;
if ( V_102 != V_101 )
return - V_29 ;
F_32 ( V_100 -> V_104 ) ;
V_100 -> V_104 = F_17 ( V_103 ) ;
return 0 ;
}
static T_4 int F_65 ( void )
{
V_31 = F_66 ( V_19 , V_105 ) ;
#ifdef F_67
F_68 ( V_106 , V_107 ) ;
#endif
return 0 ;
}
