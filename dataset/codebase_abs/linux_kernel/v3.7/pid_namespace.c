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
int V_21 ;
int V_22 ;
if ( V_20 > V_23 ) {
V_22 = - V_24 ;
goto V_7;
}
V_22 = - V_25 ;
V_19 = F_10 ( V_26 , V_8 ) ;
if ( V_19 == NULL )
goto V_7;
V_19 -> V_27 [ 0 ] . V_28 = F_11 ( V_29 , V_8 ) ;
if ( ! V_19 -> V_27 [ 0 ] . V_28 )
goto V_30;
V_19 -> V_31 = F_1 ( V_20 + 1 ) ;
if ( V_19 -> V_31 == NULL )
goto V_32;
F_12 ( & V_19 -> V_33 ) ;
V_19 -> V_20 = V_20 ;
V_19 -> V_34 = F_13 ( V_18 ) ;
F_14 ( 0 , V_19 -> V_27 [ 0 ] . V_28 ) ;
F_15 ( & V_19 -> V_27 [ 0 ] . V_35 , V_36 - 1 ) ;
for ( V_21 = 1 ; V_21 < V_37 ; V_21 ++ )
F_15 ( & V_19 -> V_27 [ V_21 ] . V_35 , V_36 ) ;
V_22 = F_16 ( V_19 ) ;
if ( V_22 )
goto V_38;
return V_19 ;
V_38:
F_17 ( V_18 ) ;
V_32:
F_8 ( V_19 -> V_27 [ 0 ] . V_28 ) ;
V_30:
F_18 ( V_26 , V_19 ) ;
V_7:
return F_19 ( V_22 ) ;
}
static void F_20 ( struct V_17 * V_19 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_37 ; V_21 ++ )
F_8 ( V_19 -> V_27 [ V_21 ] . V_28 ) ;
F_18 ( V_26 , V_19 ) ;
}
struct V_17 * F_21 ( unsigned long V_39 , struct V_17 * V_40 )
{
if ( ! ( V_39 & V_41 ) )
return F_13 ( V_40 ) ;
if ( V_39 & ( V_42 | V_43 ) )
return F_19 ( - V_24 ) ;
return F_9 ( V_40 ) ;
}
static void F_22 ( struct V_33 * V_33 )
{
struct V_17 * V_19 ;
V_19 = F_23 ( V_33 , struct V_17 , V_33 ) ;
F_20 ( V_19 ) ;
}
void F_17 ( struct V_17 * V_19 )
{
struct V_17 * V_34 ;
while ( V_19 != & V_44 ) {
V_34 = V_19 -> V_34 ;
if ( ! F_24 ( & V_19 -> V_33 , F_22 ) )
break;
V_19 = V_34 ;
}
}
void F_25 ( struct V_17 * V_45 )
{
int V_46 ;
int V_47 ;
struct V_48 * V_49 , * V_50 = V_51 ;
F_26 ( & V_50 -> V_52 -> V_53 ) ;
V_50 -> V_52 -> V_54 [ V_55 - 1 ] . V_56 . V_57 = V_58 ;
F_27 ( & V_50 -> V_52 -> V_53 ) ;
F_28 ( & V_59 ) ;
V_46 = F_29 ( V_45 , 1 ) ;
while ( V_46 > 0 ) {
F_30 () ;
V_49 = F_31 ( F_32 ( V_46 ) , V_60 ) ;
if ( V_49 && ! F_33 ( V_49 ) )
F_34 ( V_61 , V_62 , V_49 ) ;
F_35 () ;
V_46 = F_29 ( V_45 , V_46 ) ;
}
F_36 ( & V_59 ) ;
do {
F_37 ( V_63 ) ;
V_47 = F_38 ( - 1 , NULL , V_64 , NULL ) ;
} while ( V_47 != - V_65 );
for (; ; ) {
bool V_66 = false ;
F_28 ( & V_59 ) ;
if ( ! F_39 ( & V_51 -> V_67 ) ) {
F_40 ( V_68 ) ;
V_66 = true ;
}
F_36 ( & V_59 ) ;
if ( ! V_66 )
break;
F_41 () ;
}
if ( V_45 -> V_69 )
V_51 -> signal -> V_70 = V_45 -> V_69 ;
F_42 ( V_45 ) ;
return;
}
static int F_43 ( struct V_71 * V_72 , int V_73 ,
void T_1 * V_74 , T_2 * V_75 , T_3 * V_76 )
{
struct V_71 V_77 = * V_72 ;
if ( V_73 && ! F_44 ( V_78 ) )
return - V_79 ;
V_77 . V_80 = & V_51 -> V_81 -> V_45 -> V_82 ;
return F_45 ( & V_77 , V_73 , V_74 , V_75 , V_76 ) ;
}
int F_46 ( struct V_17 * V_45 , int V_83 )
{
if ( V_45 == & V_44 )
return 0 ;
switch ( V_83 ) {
case V_84 :
case V_85 :
V_45 -> V_69 = V_86 ;
break;
case V_87 :
case V_88 :
V_45 -> V_69 = V_89 ;
break;
default:
return - V_24 ;
}
F_28 ( & V_59 ) ;
F_47 ( V_61 , V_45 -> V_90 ) ;
F_36 ( & V_59 ) ;
F_48 ( 0 ) ;
return 0 ;
}
static T_4 int F_49 ( void )
{
V_26 = F_50 ( V_17 , V_91 ) ;
#ifdef F_51
F_52 ( V_92 , V_93 ) ;
#endif
return 0 ;
}
