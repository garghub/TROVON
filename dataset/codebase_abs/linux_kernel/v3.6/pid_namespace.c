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
static struct V_17 * F_9 ( struct V_17 * V_18 )
{
struct V_17 * V_19 ;
unsigned int V_20 = V_18 -> V_20 + 1 ;
int V_21 , V_22 = - V_23 ;
V_19 = F_10 ( V_24 , V_8 ) ;
if ( V_19 == NULL )
goto V_7;
V_19 -> V_25 [ 0 ] . V_26 = F_11 ( V_27 , V_8 ) ;
if ( ! V_19 -> V_25 [ 0 ] . V_26 )
goto V_28;
V_19 -> V_29 = F_1 ( V_20 + 1 ) ;
if ( V_19 -> V_29 == NULL )
goto V_30;
F_12 ( & V_19 -> V_31 ) ;
V_19 -> V_20 = V_20 ;
V_19 -> V_32 = F_13 ( V_18 ) ;
F_14 ( 0 , V_19 -> V_25 [ 0 ] . V_26 ) ;
F_15 ( & V_19 -> V_25 [ 0 ] . V_33 , V_34 - 1 ) ;
for ( V_21 = 1 ; V_21 < V_35 ; V_21 ++ )
F_15 ( & V_19 -> V_25 [ V_21 ] . V_33 , V_34 ) ;
V_22 = F_16 ( V_19 ) ;
if ( V_22 )
goto V_36;
return V_19 ;
V_36:
F_17 ( V_18 ) ;
V_30:
F_8 ( V_19 -> V_25 [ 0 ] . V_26 ) ;
V_28:
F_18 ( V_24 , V_19 ) ;
V_7:
return F_19 ( V_22 ) ;
}
static void F_20 ( struct V_17 * V_19 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_35 ; V_21 ++ )
F_8 ( V_19 -> V_25 [ V_21 ] . V_26 ) ;
F_18 ( V_24 , V_19 ) ;
}
struct V_17 * F_21 ( unsigned long V_37 , struct V_17 * V_38 )
{
if ( ! ( V_37 & V_39 ) )
return F_13 ( V_38 ) ;
if ( V_37 & ( V_40 | V_41 ) )
return F_19 ( - V_42 ) ;
return F_9 ( V_38 ) ;
}
void F_22 ( struct V_31 * V_31 )
{
struct V_17 * V_19 , * V_32 ;
V_19 = F_23 ( V_31 , struct V_17 , V_31 ) ;
V_32 = V_19 -> V_32 ;
F_20 ( V_19 ) ;
if ( V_32 != NULL )
F_17 ( V_32 ) ;
}
void F_24 ( struct V_17 * V_43 )
{
int V_44 ;
int V_45 ;
struct V_46 * V_47 , * V_48 = V_49 ;
F_25 ( & V_48 -> V_50 -> V_51 ) ;
V_48 -> V_50 -> V_52 [ V_53 - 1 ] . V_54 . V_55 = V_56 ;
F_26 ( & V_48 -> V_50 -> V_51 ) ;
F_27 ( & V_57 ) ;
V_44 = F_28 ( V_43 , 1 ) ;
while ( V_44 > 0 ) {
F_29 () ;
V_47 = F_30 ( F_31 ( V_44 ) , V_58 ) ;
if ( V_47 && ! F_32 ( V_47 ) )
F_33 ( V_59 , V_60 , V_47 ) ;
F_34 () ;
V_44 = F_28 ( V_43 , V_44 ) ;
}
F_35 ( & V_57 ) ;
do {
F_36 ( V_61 ) ;
V_45 = F_37 ( - 1 , NULL , V_62 , NULL ) ;
} while ( V_45 != - V_63 );
for (; ; ) {
bool V_64 = false ;
F_27 ( & V_57 ) ;
if ( ! F_38 ( & V_49 -> V_65 ) ) {
F_39 ( V_66 ) ;
V_64 = true ;
}
F_35 ( & V_57 ) ;
if ( ! V_64 )
break;
F_40 () ;
}
if ( V_43 -> V_67 )
V_49 -> signal -> V_68 = V_43 -> V_67 ;
F_41 ( V_43 ) ;
return;
}
static int F_42 ( struct V_69 * V_70 , int V_71 ,
void T_1 * V_72 , T_2 * V_73 , T_3 * V_74 )
{
struct V_69 V_75 = * V_70 ;
if ( V_71 && ! F_43 ( V_76 ) )
return - V_77 ;
V_75 . V_78 = & V_49 -> V_79 -> V_43 -> V_80 ;
return F_44 ( & V_75 , V_71 , V_72 , V_73 , V_74 ) ;
}
int F_45 ( struct V_17 * V_43 , int V_81 )
{
if ( V_43 == & V_82 )
return 0 ;
switch ( V_81 ) {
case V_83 :
case V_84 :
V_43 -> V_67 = V_85 ;
break;
case V_86 :
case V_87 :
V_43 -> V_67 = V_88 ;
break;
default:
return - V_42 ;
}
F_27 ( & V_57 ) ;
F_46 ( V_59 , V_43 -> V_89 ) ;
F_35 ( & V_57 ) ;
F_47 ( 0 ) ;
return 0 ;
}
static T_4 int F_48 ( void )
{
V_24 = F_49 ( V_17 , V_90 ) ;
#ifdef F_50
F_51 ( V_91 , V_92 ) ;
#endif
return 0 ;
}
