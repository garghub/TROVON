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
static struct V_22 * F_12 ( struct V_23 * V_20 )
{
return F_13 ( V_20 , F_14 () , V_24 ) ;
}
static void F_15 ( struct V_22 * V_22 )
{
F_16 ( V_22 , V_24 ) ;
}
static struct V_19 * F_17 ( struct V_23 * V_25 ,
struct V_19 * V_26 )
{
struct V_19 * V_20 ;
unsigned int V_27 = V_26 -> V_27 + 1 ;
struct V_22 * V_22 ;
int V_28 ;
int V_29 ;
V_29 = - V_30 ;
if ( ! F_18 ( V_26 -> V_25 , V_25 ) )
goto V_7;
V_29 = - V_31 ;
if ( V_27 > V_32 )
goto V_7;
V_22 = F_12 ( V_25 ) ;
if ( ! V_22 )
goto V_7;
V_29 = - V_33 ;
V_20 = F_19 ( V_34 , V_8 ) ;
if ( V_20 == NULL )
goto V_35;
V_20 -> V_36 [ 0 ] . V_37 = F_20 ( V_38 , V_8 ) ;
if ( ! V_20 -> V_36 [ 0 ] . V_37 )
goto V_39;
V_20 -> V_40 = F_1 ( V_27 + 1 ) ;
if ( V_20 -> V_40 == NULL )
goto V_41;
V_29 = F_21 ( & V_20 -> V_20 ) ;
if ( V_29 )
goto V_41;
V_20 -> V_20 . V_42 = & V_43 ;
F_22 ( & V_20 -> V_44 ) ;
V_20 -> V_27 = V_27 ;
V_20 -> V_45 = F_23 ( V_26 ) ;
V_20 -> V_25 = F_24 ( V_25 ) ;
V_20 -> V_22 = V_22 ;
V_20 -> V_46 = V_47 ;
F_25 ( & V_20 -> V_21 , F_9 ) ;
F_26 ( 0 , V_20 -> V_36 [ 0 ] . V_37 ) ;
F_27 ( & V_20 -> V_36 [ 0 ] . V_48 , V_49 - 1 ) ;
for ( V_28 = 1 ; V_28 < V_50 ; V_28 ++ )
F_27 ( & V_20 -> V_36 [ V_28 ] . V_48 , V_49 ) ;
return V_20 ;
V_41:
F_8 ( V_20 -> V_36 [ 0 ] . V_37 ) ;
V_39:
F_28 ( V_34 , V_20 ) ;
V_35:
F_15 ( V_22 ) ;
V_7:
return F_29 ( V_29 ) ;
}
static void F_30 ( struct V_51 * V_52 )
{
struct V_19 * V_20 = F_10 ( V_52 , struct V_19 , V_53 ) ;
F_15 ( V_20 -> V_22 ) ;
F_31 ( V_20 -> V_25 ) ;
F_28 ( V_34 , V_20 ) ;
}
static void F_32 ( struct V_19 * V_20 )
{
int V_28 ;
F_33 ( & V_20 -> V_20 ) ;
for ( V_28 = 0 ; V_28 < V_50 ; V_28 ++ )
F_8 ( V_20 -> V_36 [ V_28 ] . V_37 ) ;
F_34 ( & V_20 -> V_53 , F_30 ) ;
}
struct V_19 * F_35 ( unsigned long V_54 ,
struct V_23 * V_25 , struct V_19 * V_55 )
{
if ( ! ( V_54 & V_56 ) )
return F_23 ( V_55 ) ;
if ( F_36 ( V_57 ) != V_55 )
return F_29 ( - V_30 ) ;
return F_17 ( V_25 , V_55 ) ;
}
static void F_37 ( struct V_44 * V_44 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( V_44 , struct V_19 , V_44 ) ;
F_32 ( V_20 ) ;
}
void F_38 ( struct V_19 * V_20 )
{
struct V_19 * V_45 ;
while ( V_20 != & V_58 ) {
V_45 = V_20 -> V_45 ;
if ( ! F_39 ( & V_20 -> V_44 , F_37 ) )
break;
V_20 = V_45 ;
}
}
void F_40 ( struct V_19 * V_59 )
{
int V_60 ;
int V_61 ;
struct V_62 * V_63 , * V_64 = V_57 ;
int V_65 = F_41 ( V_64 ) ? 1 : 2 ;
F_42 ( V_59 ) ;
F_43 ( & V_64 -> V_66 -> V_67 ) ;
V_64 -> V_66 -> V_68 [ V_69 - 1 ] . V_70 . V_71 = V_72 ;
F_44 ( & V_64 -> V_66 -> V_67 ) ;
F_45 ( & V_73 ) ;
V_60 = F_46 ( V_59 , 1 ) ;
while ( V_60 > 0 ) {
F_47 () ;
V_63 = F_48 ( F_49 ( V_60 ) , V_74 ) ;
if ( V_63 && ! F_50 ( V_63 ) )
F_51 ( V_75 , V_76 , V_63 ) ;
F_52 () ;
V_60 = F_46 ( V_59 , V_60 ) ;
}
F_53 ( & V_73 ) ;
do {
F_54 ( V_77 ) ;
V_61 = F_55 ( - 1 , NULL , V_78 , NULL ) ;
} while ( V_61 != - V_79 );
for (; ; ) {
F_56 ( V_80 ) ;
if ( V_59 -> V_46 == V_65 )
break;
F_57 () ;
}
F_58 ( V_81 ) ;
if ( V_59 -> V_82 )
V_57 -> signal -> V_83 = V_59 -> V_82 ;
F_59 ( V_59 ) ;
return;
}
static int F_60 ( struct V_84 * V_85 , int V_86 ,
void T_1 * V_87 , T_2 * V_88 , T_3 * V_89 )
{
struct V_19 * V_59 = F_36 ( V_57 ) ;
struct V_84 V_90 = * V_85 ;
if ( V_86 && ! F_61 ( V_59 -> V_25 , V_91 ) )
return - V_92 ;
V_90 . V_93 = & V_59 -> V_94 ;
return F_62 ( & V_90 , V_86 , V_87 , V_88 , V_89 ) ;
}
int F_63 ( struct V_19 * V_59 , int V_95 )
{
if ( V_59 == & V_58 )
return 0 ;
switch ( V_95 ) {
case V_96 :
case V_97 :
V_59 -> V_82 = V_98 ;
break;
case V_99 :
case V_100 :
V_59 -> V_82 = V_101 ;
break;
default:
return - V_30 ;
}
F_45 ( & V_73 ) ;
F_64 ( V_75 , V_59 -> V_102 ) ;
F_53 ( & V_73 ) ;
F_65 ( 0 ) ;
return 0 ;
}
static inline struct V_19 * F_66 ( struct V_103 * V_20 )
{
return F_10 ( V_20 , struct V_19 , V_20 ) ;
}
static struct V_103 * F_67 ( struct V_62 * V_63 )
{
struct V_19 * V_20 ;
F_47 () ;
V_20 = F_36 ( V_63 ) ;
if ( V_20 )
F_23 ( V_20 ) ;
F_52 () ;
return V_20 ? & V_20 -> V_20 : NULL ;
}
static struct V_103 * F_68 ( struct V_62 * V_63 )
{
struct V_19 * V_20 = NULL ;
F_69 ( V_63 ) ;
if ( V_63 -> V_104 ) {
V_20 = V_63 -> V_104 -> V_105 ;
F_23 ( V_20 ) ;
}
F_70 ( V_63 ) ;
if ( V_20 ) {
F_45 ( & V_73 ) ;
if ( ! V_20 -> V_102 ) {
F_38 ( V_20 ) ;
V_20 = NULL ;
}
F_53 ( & V_73 ) ;
}
return V_20 ? & V_20 -> V_20 : NULL ;
}
static void F_71 ( struct V_103 * V_20 )
{
F_38 ( F_66 ( V_20 ) ) ;
}
static int F_72 ( struct V_104 * V_104 , struct V_103 * V_20 )
{
struct V_19 * V_106 = F_36 ( V_57 ) ;
struct V_19 * V_107 , * V_108 = F_66 ( V_20 ) ;
if ( ! F_61 ( V_108 -> V_25 , V_91 ) ||
! F_61 ( F_73 () , V_91 ) )
return - V_92 ;
if ( V_108 -> V_27 < V_106 -> V_27 )
return - V_30 ;
V_107 = V_108 ;
while ( V_107 -> V_27 > V_106 -> V_27 )
V_107 = V_107 -> V_45 ;
if ( V_107 != V_106 )
return - V_30 ;
F_38 ( V_104 -> V_105 ) ;
V_104 -> V_105 = F_23 ( V_108 ) ;
return 0 ;
}
static struct V_103 * F_74 ( struct V_103 * V_20 )
{
struct V_19 * V_106 = F_36 ( V_57 ) ;
struct V_19 * V_59 , * V_52 ;
V_59 = V_52 = F_66 ( V_20 ) -> V_45 ;
for (; ; ) {
if ( ! V_52 )
return F_29 ( - V_92 ) ;
if ( V_52 == V_106 )
break;
V_52 = V_52 -> V_45 ;
}
return & F_23 ( V_59 ) -> V_20 ;
}
static struct V_23 * F_75 ( struct V_103 * V_20 )
{
return F_66 ( V_20 ) -> V_25 ;
}
static T_4 int F_76 ( void )
{
V_34 = F_77 ( V_19 , V_109 ) ;
#ifdef F_78
F_79 ( V_110 , V_111 ) ;
#endif
return 0 ;
}
