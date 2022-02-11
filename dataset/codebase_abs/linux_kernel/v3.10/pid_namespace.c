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
static void F_24 ( struct V_19 * V_20 )
{
int V_26 ;
F_25 ( V_20 -> V_38 ) ;
for ( V_26 = 0 ; V_26 < V_45 ; V_26 ++ )
F_8 ( V_20 -> V_32 [ V_26 ] . V_33 ) ;
F_26 ( V_20 -> V_23 ) ;
F_22 ( V_31 , V_20 ) ;
}
struct V_19 * F_27 ( unsigned long V_46 ,
struct V_22 * V_23 , struct V_19 * V_47 )
{
if ( ! ( V_46 & V_48 ) )
return F_17 ( V_47 ) ;
if ( F_28 ( V_49 ) != V_47 )
return F_23 ( - V_29 ) ;
return F_12 ( V_23 , V_47 ) ;
}
static void F_29 ( struct V_39 * V_39 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( V_39 , struct V_19 , V_39 ) ;
F_24 ( V_20 ) ;
}
void F_30 ( struct V_19 * V_20 )
{
struct V_19 * V_40 ;
while ( V_20 != & V_50 ) {
V_40 = V_20 -> V_40 ;
if ( ! F_31 ( & V_20 -> V_39 , F_29 ) )
break;
V_20 = V_40 ;
}
}
void F_32 ( struct V_19 * V_51 )
{
int V_52 ;
int V_53 ;
struct V_54 * V_55 , * V_56 = V_49 ;
int V_57 = F_33 ( V_56 ) ? 1 : 2 ;
F_34 ( V_51 ) ;
F_35 ( & V_56 -> V_58 -> V_59 ) ;
V_56 -> V_58 -> V_60 [ V_61 - 1 ] . V_62 . V_63 = V_64 ;
F_36 ( & V_56 -> V_58 -> V_59 ) ;
F_37 ( & V_65 ) ;
V_52 = F_38 ( V_51 , 1 ) ;
while ( V_52 > 0 ) {
F_39 () ;
V_55 = F_40 ( F_41 ( V_52 ) , V_66 ) ;
if ( V_55 && ! F_42 ( V_55 ) )
F_43 ( V_67 , V_68 , V_55 ) ;
F_44 () ;
V_52 = F_38 ( V_51 , V_52 ) ;
}
F_45 ( & V_65 ) ;
do {
F_46 ( V_69 ) ;
V_53 = F_47 ( - 1 , NULL , V_70 , NULL ) ;
} while ( V_53 != - V_71 );
for (; ; ) {
F_48 ( V_72 ) ;
if ( V_51 -> V_41 == V_57 )
break;
F_49 () ;
}
F_50 ( V_73 ) ;
if ( V_51 -> V_74 )
V_49 -> signal -> V_75 = V_51 -> V_74 ;
F_51 ( V_51 ) ;
return;
}
static int F_52 ( struct V_76 * V_77 , int V_78 ,
void T_1 * V_79 , T_2 * V_80 , T_3 * V_81 )
{
struct V_19 * V_51 = F_28 ( V_49 ) ;
struct V_76 V_82 = * V_77 ;
if ( V_78 && ! F_53 ( V_51 -> V_23 , V_83 ) )
return - V_84 ;
V_82 . V_85 = & V_51 -> V_86 ;
return F_54 ( & V_82 , V_78 , V_79 , V_80 , V_81 ) ;
}
int F_55 ( struct V_19 * V_51 , int V_87 )
{
if ( V_51 == & V_50 )
return 0 ;
switch ( V_87 ) {
case V_88 :
case V_89 :
V_51 -> V_74 = V_90 ;
break;
case V_91 :
case V_92 :
V_51 -> V_74 = V_93 ;
break;
default:
return - V_29 ;
}
F_37 ( & V_65 ) ;
F_56 ( V_67 , V_51 -> V_94 ) ;
F_45 ( & V_65 ) ;
F_57 ( 0 ) ;
return 0 ;
}
static void * F_58 ( struct V_54 * V_55 )
{
struct V_19 * V_20 ;
F_39 () ;
V_20 = F_17 ( F_28 ( V_55 ) ) ;
F_44 () ;
return V_20 ;
}
static void F_59 ( void * V_20 )
{
F_30 ( V_20 ) ;
}
static int F_60 ( struct V_95 * V_95 , void * V_20 )
{
struct V_19 * V_96 = F_28 ( V_49 ) ;
struct V_19 * V_97 , * V_98 = V_20 ;
if ( ! F_53 ( V_98 -> V_23 , V_83 ) ||
! F_61 ( V_83 ) )
return - V_84 ;
if ( V_98 -> V_25 < V_96 -> V_25 )
return - V_29 ;
V_97 = V_98 ;
while ( V_97 -> V_25 > V_96 -> V_25 )
V_97 = V_97 -> V_40 ;
if ( V_97 != V_96 )
return - V_29 ;
F_30 ( V_95 -> V_51 ) ;
V_95 -> V_51 = F_17 ( V_98 ) ;
return 0 ;
}
static unsigned int F_62 ( void * V_20 )
{
struct V_19 * V_51 = V_20 ;
return V_51 -> V_38 ;
}
static T_4 int F_63 ( void )
{
V_31 = F_64 ( V_19 , V_99 ) ;
#ifdef F_65
F_66 ( V_100 , V_101 ) ;
#endif
return 0 ;
}
