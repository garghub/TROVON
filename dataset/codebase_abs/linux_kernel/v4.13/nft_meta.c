void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
const struct V_11 * V_12 = F_3 ( V_6 ) , * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 ;
T_1 * V_16 = & V_4 -> V_17 [ V_8 -> V_18 ] ;
switch ( V_8 -> V_19 ) {
case V_20 :
* V_16 = V_10 -> V_21 ;
break;
case V_22 :
F_5 ( V_16 , ( V_23 V_24 ) V_10 -> V_25 ) ;
break;
case V_26 :
F_6 ( V_16 , F_7 ( V_6 ) ) ;
break;
case V_27 :
if ( ! V_6 -> V_28 )
goto V_29;
F_6 ( V_16 , V_6 -> V_30 ) ;
break;
case V_31 :
* V_16 = V_10 -> V_32 ;
break;
case V_33 :
* V_16 = V_10 -> V_34 ;
break;
case V_35 :
if ( V_12 == NULL )
goto V_29;
* V_16 = V_12 -> V_36 ;
break;
case V_37 :
if ( V_13 == NULL )
goto V_29;
* V_16 = V_13 -> V_36 ;
break;
case V_38 :
if ( V_12 == NULL )
goto V_29;
strncpy ( ( char * ) V_16 , V_12 -> V_39 , V_40 ) ;
break;
case V_41 :
if ( V_13 == NULL )
goto V_29;
strncpy ( ( char * ) V_16 , V_13 -> V_39 , V_40 ) ;
break;
case V_42 :
if ( V_12 == NULL )
goto V_29;
F_5 ( V_16 , V_12 -> type ) ;
break;
case V_43 :
if ( V_13 == NULL )
goto V_29;
F_5 ( V_16 , V_13 -> type ) ;
break;
case V_44 :
V_15 = F_8 ( V_10 ) ;
if ( ! V_15 || ! F_9 ( V_15 ) )
goto V_29;
F_10 ( & V_15 -> V_45 ) ;
if ( V_15 -> V_46 == NULL ||
V_15 -> V_46 -> V_47 == NULL ) {
F_11 ( & V_15 -> V_45 ) ;
goto V_29;
}
* V_16 = F_12 ( & V_48 ,
V_15 -> V_46 -> V_47 -> V_49 -> V_50 ) ;
F_11 ( & V_15 -> V_45 ) ;
break;
case V_51 :
V_15 = F_8 ( V_10 ) ;
if ( ! V_15 || ! F_9 ( V_15 ) )
goto V_29;
F_10 ( & V_15 -> V_45 ) ;
if ( V_15 -> V_46 == NULL ||
V_15 -> V_46 -> V_47 == NULL ) {
F_11 ( & V_15 -> V_45 ) ;
goto V_29;
}
* V_16 = F_13 ( & V_48 ,
V_15 -> V_46 -> V_47 -> V_49 -> V_52 ) ;
F_11 ( & V_15 -> V_45 ) ;
break;
#ifdef F_14
case V_53 : {
const struct V_54 * V_55 = F_15 ( V_10 ) ;
if ( V_55 == NULL )
goto V_29;
* V_16 = V_55 -> V_56 ;
break;
}
#endif
#ifdef F_16
case V_57 :
* V_16 = V_10 -> V_58 ;
break;
#endif
case V_59 :
if ( V_10 -> V_60 != V_61 ) {
F_6 ( V_16 , V_10 -> V_60 ) ;
break;
}
switch ( F_7 ( V_6 ) ) {
case V_62 :
if ( F_17 ( F_18 ( V_10 ) -> V_63 ) )
F_6 ( V_16 , V_64 ) ;
else
F_6 ( V_16 , V_65 ) ;
break;
case V_66 :
F_6 ( V_16 , V_64 ) ;
break;
case V_67 :
switch ( V_10 -> V_25 ) {
case F_19 ( V_68 ) : {
int V_69 = F_20 ( V_10 ) ;
struct V_70 * V_71 , V_72 ;
V_71 = F_21 ( V_10 , V_69 ,
sizeof( V_72 ) , & V_72 ) ;
if ( ! V_71 )
goto V_29;
if ( F_17 ( V_71 -> V_63 ) )
F_6 ( V_16 , V_64 ) ;
else
F_6 ( V_16 , V_65 ) ;
break;
}
case F_19 ( V_73 ) :
F_6 ( V_16 , V_64 ) ;
break;
default:
F_22 ( 1 ) ;
goto V_29;
}
break;
default:
F_22 ( 1 ) ;
goto V_29;
}
break;
case V_74 :
* V_16 = F_23 () ;
break;
case V_75 :
if ( V_12 == NULL )
goto V_29;
* V_16 = V_12 -> V_76 ;
break;
case V_77 :
if ( V_13 == NULL )
goto V_29;
* V_16 = V_13 -> V_76 ;
break;
#ifdef F_24
case V_78 :
V_15 = F_8 ( V_10 ) ;
if ( ! V_15 || ! F_9 ( V_15 ) )
goto V_29;
* V_16 = F_25 ( & V_15 -> V_79 ) ;
break;
#endif
case V_80 : {
struct V_81 * V_82 = F_26 ( & V_83 ) ;
* V_16 = F_27 ( V_82 ) ;
break;
}
default:
F_28 ( 1 ) ;
goto V_29;
}
return;
V_29:
V_4 -> V_84 . V_85 = V_86 ;
}
void F_29 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_87 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
T_1 * V_88 = & V_4 -> V_17 [ V_87 -> V_88 ] ;
T_1 V_89 = * V_88 ;
T_2 V_60 ;
switch ( V_87 -> V_19 ) {
case V_33 :
V_10 -> V_34 = V_89 ;
break;
case V_31 :
V_10 -> V_32 = V_89 ;
break;
case V_59 :
V_60 = F_30 ( V_88 ) ;
if ( V_10 -> V_60 != V_60 &&
F_31 ( V_60 ) &&
F_31 ( V_10 -> V_60 ) )
V_10 -> V_60 = V_60 ;
break;
case V_90 :
V_10 -> V_91 = ! ! V_89 ;
break;
default:
F_28 ( 1 ) ;
}
}
int F_32 ( const struct V_92 * V_93 ,
const struct V_1 * V_2 ,
const struct V_94 * const V_95 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
V_8 -> V_19 = F_33 ( F_34 ( V_95 [ V_96 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_22 :
case V_42 :
case V_43 :
V_21 = sizeof( V_24 ) ;
break;
case V_26 :
case V_27 :
case V_20 :
case V_31 :
case V_33 :
case V_35 :
case V_37 :
case V_44 :
case V_51 :
#ifdef F_14
case V_53 :
#endif
#ifdef F_16
case V_57 :
#endif
case V_59 :
case V_74 :
case V_75 :
case V_77 :
#ifdef F_24
case V_78 :
#endif
V_21 = sizeof( T_1 ) ;
break;
case V_38 :
case V_41 :
V_21 = V_40 ;
break;
case V_80 :
F_35 ( & V_83 ) ;
V_21 = sizeof( T_1 ) ;
break;
default:
return - V_97 ;
}
V_8 -> V_18 = F_36 ( V_95 [ V_98 ] ) ;
return F_37 ( V_93 , V_8 -> V_18 , NULL ,
V_99 , V_21 ) ;
}
int F_38 ( const struct V_92 * V_93 ,
const struct V_1 * V_2 ,
const struct V_100 * * V_17 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_101 ;
if ( V_8 -> V_19 != V_59 )
return 0 ;
switch ( V_93 -> V_102 -> V_103 ) {
case V_104 :
V_101 = 1 << V_105 ;
break;
case V_67 :
V_101 = 1 << V_106 ;
break;
case V_62 :
case V_66 :
case V_107 :
V_101 = 1 << V_108 ;
break;
default:
return - V_97 ;
}
return F_39 ( V_93 -> V_109 , V_101 ) ;
}
int F_40 ( const struct V_92 * V_93 ,
const struct V_1 * V_2 ,
const struct V_94 * const V_95 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_29 ;
V_8 -> V_19 = F_33 ( F_34 ( V_95 [ V_96 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_33 :
case V_31 :
V_21 = sizeof( T_1 ) ;
break;
case V_90 :
V_21 = sizeof( T_2 ) ;
break;
case V_59 :
V_21 = sizeof( T_2 ) ;
break;
default:
return - V_97 ;
}
V_8 -> V_88 = F_36 ( V_95 [ V_110 ] ) ;
V_29 = F_41 ( V_8 -> V_88 , V_21 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_8 -> V_19 == V_90 )
F_42 ( & V_111 ) ;
return 0 ;
}
int F_43 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_44 ( V_10 , V_96 , F_45 ( V_8 -> V_19 ) ) )
goto V_112;
if ( F_46 ( V_10 , V_98 , V_8 -> V_18 ) )
goto V_112;
return 0 ;
V_112:
return - 1 ;
}
int F_47 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_44 ( V_10 , V_96 , F_45 ( V_8 -> V_19 ) ) )
goto V_112;
if ( F_46 ( V_10 , V_110 , V_8 -> V_88 ) )
goto V_112;
return 0 ;
V_112:
return - 1 ;
}
void F_48 ( const struct V_92 * V_93 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_19 == V_90 )
F_49 ( & V_111 ) ;
}
static const struct V_113 *
F_50 ( const struct V_92 * V_93 ,
const struct V_94 * const V_95 [] )
{
if ( V_95 [ V_96 ] == NULL )
return F_51 ( - V_114 ) ;
if ( V_95 [ V_98 ] && V_95 [ V_110 ] )
return F_51 ( - V_114 ) ;
if ( V_95 [ V_98 ] )
return & V_115 ;
if ( V_95 [ V_110 ] )
return & V_116 ;
return F_51 ( - V_114 ) ;
}
static int T_3 F_52 ( void )
{
return F_53 ( & V_117 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_117 ) ;
}
