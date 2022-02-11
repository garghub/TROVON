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
V_27 = F_15 ( & V_20 -> V_38 ) ;
if ( V_27 )
goto V_37;
F_16 ( & V_20 -> V_39 ) ;
V_20 -> V_25 = V_25 ;
V_20 -> V_40 = F_17 ( V_24 ) ;
V_20 -> V_23 = F_18 ( V_23 ) ;
V_20 -> V_41 = V_42 ;
F_19 ( & V_20 -> V_21 , F_9 ) ;
F_20 ( 0 , V_20 -> V_32 [ 0 ] . V_33 ) ;
F_21 ( & V_20 -> V_32 [ 0 ] . V_43 , V_44 - 1 ) ;
for ( V_26 = 1 ; V_26 < V_45 ; V_26 ++ )
F_21 ( & V_20 -> V_32 [ V_26 ] . V_43 , V_44 ) ;
return V_20 ;
V_37:
F_8 ( V_20 -> V_32 [ 0 ] . V_33 ) ;
V_35:
F_22 ( V_31 , V_20 ) ;
V_7:
return F_23 ( V_27 ) ;
}
static void F_24 ( struct V_46 * V_47 )
{
F_22 ( V_31 ,
F_10 ( V_47 , struct V_19 , V_48 ) ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
int V_26 ;
F_26 ( V_20 -> V_38 ) ;
for ( V_26 = 0 ; V_26 < V_45 ; V_26 ++ )
F_8 ( V_20 -> V_32 [ V_26 ] . V_33 ) ;
F_27 ( V_20 -> V_23 ) ;
F_28 ( & V_20 -> V_48 , F_24 ) ;
}
struct V_19 * F_29 ( unsigned long V_49 ,
struct V_22 * V_23 , struct V_19 * V_50 )
{
if ( ! ( V_49 & V_51 ) )
return F_17 ( V_50 ) ;
if ( F_30 ( V_52 ) != V_50 )
return F_23 ( - V_29 ) ;
return F_12 ( V_23 , V_50 ) ;
}
static void F_31 ( struct V_39 * V_39 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( V_39 , struct V_19 , V_39 ) ;
F_25 ( V_20 ) ;
}
void F_32 ( struct V_19 * V_20 )
{
struct V_19 * V_40 ;
while ( V_20 != & V_53 ) {
V_40 = V_20 -> V_40 ;
if ( ! F_33 ( & V_20 -> V_39 , F_31 ) )
break;
V_20 = V_40 ;
}
}
void F_34 ( struct V_19 * V_54 )
{
int V_55 ;
int V_56 ;
struct V_57 * V_58 , * V_59 = V_52 ;
int V_60 = F_35 ( V_59 ) ? 1 : 2 ;
F_36 ( V_54 ) ;
F_37 ( & V_59 -> V_61 -> V_62 ) ;
V_59 -> V_61 -> V_63 [ V_64 - 1 ] . V_65 . V_66 = V_67 ;
F_38 ( & V_59 -> V_61 -> V_62 ) ;
F_39 ( & V_68 ) ;
V_55 = F_40 ( V_54 , 1 ) ;
while ( V_55 > 0 ) {
F_41 () ;
V_58 = F_42 ( F_43 ( V_55 ) , V_69 ) ;
if ( V_58 && ! F_44 ( V_58 ) )
F_45 ( V_70 , V_71 , V_58 ) ;
F_46 () ;
V_55 = F_40 ( V_54 , V_55 ) ;
}
F_47 ( & V_68 ) ;
do {
F_48 ( V_72 ) ;
V_56 = F_49 ( - 1 , NULL , V_73 , NULL ) ;
} while ( V_56 != - V_74 );
for (; ; ) {
F_50 ( V_75 ) ;
if ( V_54 -> V_41 == V_60 )
break;
F_51 () ;
}
F_52 ( V_76 ) ;
if ( V_54 -> V_77 )
V_52 -> signal -> V_78 = V_54 -> V_77 ;
F_53 ( V_54 ) ;
return;
}
static int F_54 ( struct V_79 * V_80 , int V_81 ,
void T_1 * V_82 , T_2 * V_83 , T_3 * V_84 )
{
struct V_19 * V_54 = F_30 ( V_52 ) ;
struct V_79 V_85 = * V_80 ;
if ( V_81 && ! F_55 ( V_54 -> V_23 , V_86 ) )
return - V_87 ;
V_85 . V_88 = & V_54 -> V_89 ;
return F_56 ( & V_85 , V_81 , V_82 , V_83 , V_84 ) ;
}
int F_57 ( struct V_19 * V_54 , int V_90 )
{
if ( V_54 == & V_53 )
return 0 ;
switch ( V_90 ) {
case V_91 :
case V_92 :
V_54 -> V_77 = V_93 ;
break;
case V_94 :
case V_95 :
V_54 -> V_77 = V_96 ;
break;
default:
return - V_29 ;
}
F_39 ( & V_68 ) ;
F_58 ( V_70 , V_54 -> V_97 ) ;
F_47 ( & V_68 ) ;
F_59 ( 0 ) ;
return 0 ;
}
static void * F_60 ( struct V_57 * V_58 )
{
struct V_19 * V_20 ;
F_41 () ;
V_20 = F_17 ( F_30 ( V_58 ) ) ;
F_46 () ;
return V_20 ;
}
static void F_61 ( void * V_20 )
{
F_32 ( V_20 ) ;
}
static int F_62 ( struct V_98 * V_98 , void * V_20 )
{
struct V_19 * V_99 = F_30 ( V_52 ) ;
struct V_19 * V_100 , * V_101 = V_20 ;
if ( ! F_55 ( V_101 -> V_23 , V_86 ) ||
! F_55 ( F_63 () , V_86 ) )
return - V_87 ;
if ( V_101 -> V_25 < V_99 -> V_25 )
return - V_29 ;
V_100 = V_101 ;
while ( V_100 -> V_25 > V_99 -> V_25 )
V_100 = V_100 -> V_40 ;
if ( V_100 != V_99 )
return - V_29 ;
F_32 ( V_98 -> V_102 ) ;
V_98 -> V_102 = F_17 ( V_101 ) ;
return 0 ;
}
static unsigned int F_64 ( void * V_20 )
{
struct V_19 * V_54 = V_20 ;
return V_54 -> V_38 ;
}
static T_4 int F_65 ( void )
{
V_31 = F_66 ( V_19 , V_103 ) ;
#ifdef F_67
F_68 ( V_104 , V_105 ) ;
#endif
return 0 ;
}
