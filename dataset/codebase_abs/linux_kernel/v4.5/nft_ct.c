static T_1 F_1 ( const struct V_1 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 )
{
if ( V_6 < V_7 )
return V_4 == V_8 ? F_2 ( & V_2 [ V_6 ] . V_9 ) :
F_2 ( & V_2 [ V_6 ] . V_10 ) ;
return F_1 ( V_2 , V_4 , V_11 ) +
F_1 ( V_2 , V_4 , V_12 ) ;
}
static void F_3 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
T_2 * V_21 = & V_16 -> V_22 [ V_20 -> V_23 ] ;
enum V_24 V_25 ;
const struct V_26 * V_27 ;
const struct V_28 * V_29 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
long V_34 ;
unsigned int V_35 ;
V_27 = F_5 ( V_18 -> V_36 , & V_25 ) ;
switch ( V_20 -> V_37 ) {
case V_38 :
if ( V_27 == NULL )
V_35 = V_39 ;
else if ( F_6 ( V_27 ) )
V_35 = V_40 ;
else
V_35 = F_7 ( V_25 ) ;
* V_21 = V_35 ;
return;
default:
break;
}
if ( V_27 == NULL )
goto V_41;
switch ( V_20 -> V_37 ) {
case V_42 :
* V_21 = F_8 ( V_25 ) ;
return;
case V_43 :
* V_21 = V_27 -> V_44 ;
return;
#ifdef F_9
case V_45 :
* V_21 = V_27 -> V_46 ;
return;
#endif
#ifdef F_10
case V_47 :
* V_21 = V_27 -> V_48 ;
return;
#endif
case V_49 :
V_34 = ( long ) V_50 - ( long ) V_27 -> V_51 . V_52 ;
if ( V_34 < 0 )
V_34 = 0 ;
* V_21 = F_11 ( V_34 ) ;
return;
case V_53 :
if ( V_27 -> V_54 == NULL )
goto V_41;
V_29 = F_12 ( V_27 -> V_54 ) ;
if ( V_29 == NULL )
goto V_41;
V_33 = F_13 ( V_29 -> V_33 ) ;
if ( V_33 == NULL )
goto V_41;
strncpy ( ( char * ) V_21 , V_33 -> V_55 , V_56 ) ;
return;
#ifdef F_14
case V_57 : {
struct V_58 * V_59 = F_15 ( V_27 ) ;
unsigned int V_60 ;
if ( ! V_59 ) {
memset ( V_21 , 0 , V_61 ) ;
return;
}
V_60 = V_59 -> V_62 * sizeof( long ) ;
memcpy ( V_21 , V_59 -> V_63 , V_60 ) ;
if ( V_60 < V_61 )
memset ( ( ( char * ) V_21 ) + V_60 , 0 ,
V_61 - V_60 ) ;
return;
}
#endif
case V_8 :
case V_64 : {
const struct V_65 * V_66 = F_16 ( V_27 ) ;
T_1 V_67 = 0 ;
if ( V_66 )
V_67 = F_1 ( V_66 -> V_68 ,
V_20 -> V_37 , V_20 -> V_69 ) ;
memcpy ( V_21 , & V_67 , sizeof( V_67 ) ) ;
return;
}
default:
break;
}
V_31 = & V_27 -> V_70 [ V_20 -> V_69 ] . V_31 ;
switch ( V_20 -> V_37 ) {
case V_71 :
* V_21 = F_17 ( V_27 ) ;
return;
case V_72 :
memcpy ( V_21 , V_31 -> V_73 . V_74 . V_75 ,
F_17 ( V_27 ) == V_76 ? 4 : 16 ) ;
return;
case V_77 :
memcpy ( V_21 , V_31 -> V_78 . V_74 . V_75 ,
F_17 ( V_27 ) == V_76 ? 4 : 16 ) ;
return;
case V_79 :
* V_21 = F_18 ( V_27 ) ;
return;
case V_80 :
* V_21 = ( V_81 V_82 ) V_31 -> V_73 . V_83 . V_75 ;
return;
case V_84 :
* V_21 = ( V_81 V_82 ) V_31 -> V_78 . V_83 . V_75 ;
return;
default:
break;
}
return;
V_41:
V_16 -> V_85 . V_86 = V_87 ;
}
static void F_19 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
struct V_88 * V_36 = V_18 -> V_36 ;
#ifdef F_9
T_2 V_89 = V_16 -> V_22 [ V_20 -> V_90 ] ;
#endif
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_36 , & V_25 ) ;
if ( V_27 == NULL )
return;
switch ( V_20 -> V_37 ) {
#ifdef F_9
case V_45 :
if ( V_27 -> V_46 != V_89 ) {
V_27 -> V_46 = V_89 ;
F_20 ( V_91 , V_27 ) ;
}
break;
#endif
default:
break;
}
}
static int F_21 ( T_3 V_92 )
{
int V_41 ;
if ( V_92 == V_93 ) {
V_41 = F_22 ( V_76 ) ;
if ( V_41 < 0 )
goto V_94;
V_41 = F_22 ( V_95 ) ;
if ( V_41 < 0 )
goto V_96;
} else {
V_41 = F_22 ( V_92 ) ;
if ( V_41 < 0 )
goto V_94;
}
return 0 ;
V_96:
F_23 ( V_76 ) ;
V_94:
return V_41 ;
}
static void F_24 ( T_3 V_92 )
{
if ( V_92 == V_93 ) {
F_23 ( V_76 ) ;
F_23 ( V_95 ) ;
} else
F_23 ( V_92 ) ;
}
static int F_25 ( const struct V_97 * V_98 ,
const struct V_13 * V_14 ,
const struct V_99 * const V_100 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_101 ;
int V_41 ;
V_20 -> V_37 = F_26 ( F_27 ( V_100 [ V_102 ] ) ) ;
switch ( V_20 -> V_37 ) {
case V_42 :
if ( V_100 [ V_103 ] != NULL )
return - V_104 ;
V_101 = sizeof( V_105 ) ;
break;
case V_38 :
case V_43 :
#ifdef F_9
case V_45 :
#endif
#ifdef F_10
case V_47 :
#endif
case V_49 :
if ( V_100 [ V_103 ] != NULL )
return - V_104 ;
V_101 = sizeof( T_2 ) ;
break;
#ifdef F_14
case V_57 :
if ( V_100 [ V_103 ] != NULL )
return - V_104 ;
V_101 = V_61 ;
break;
#endif
case V_53 :
if ( V_100 [ V_103 ] != NULL )
return - V_104 ;
V_101 = V_56 ;
break;
case V_71 :
case V_79 :
if ( V_100 [ V_103 ] == NULL )
return - V_104 ;
V_101 = sizeof( V_105 ) ;
break;
case V_72 :
case V_77 :
if ( V_100 [ V_103 ] == NULL )
return - V_104 ;
switch ( V_98 -> V_106 -> V_92 ) {
case V_76 :
V_101 = F_28 ( struct V_30 ,
V_73 . V_74 . V_107 ) ;
break;
case V_95 :
case V_93 :
V_101 = F_28 ( struct V_30 ,
V_73 . V_74 . V_108 ) ;
break;
default:
return - V_109 ;
}
break;
case V_80 :
case V_84 :
if ( V_100 [ V_103 ] == NULL )
return - V_104 ;
V_101 = F_28 ( struct V_30 , V_73 . V_83 . V_75 ) ;
break;
case V_8 :
case V_64 :
if ( V_100 [ V_103 ] == NULL )
V_20 -> V_69 = V_7 ;
V_101 = sizeof( T_1 ) ;
break;
default:
return - V_110 ;
}
if ( V_100 [ V_103 ] != NULL ) {
V_20 -> V_69 = F_29 ( V_100 [ V_103 ] ) ;
switch ( V_20 -> V_69 ) {
case V_11 :
case V_12 :
break;
default:
return - V_104 ;
}
}
V_20 -> V_23 = F_30 ( V_100 [ V_111 ] ) ;
V_41 = F_31 ( V_98 , V_20 -> V_23 , NULL ,
V_112 , V_101 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_21 ( V_98 -> V_106 -> V_92 ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
static int F_32 ( const struct V_97 * V_98 ,
const struct V_13 * V_14 ,
const struct V_99 * const V_100 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_101 ;
int V_41 ;
V_20 -> V_37 = F_26 ( F_27 ( V_100 [ V_102 ] ) ) ;
switch ( V_20 -> V_37 ) {
#ifdef F_9
case V_45 :
V_101 = F_28 ( struct V_26 , V_46 ) ;
break;
#endif
default:
return - V_110 ;
}
V_20 -> V_90 = F_30 ( V_100 [ V_113 ] ) ;
V_41 = F_33 ( V_20 -> V_90 , V_101 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_21 ( V_98 -> V_106 -> V_92 ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
static void F_34 ( const struct V_97 * V_98 ,
const struct V_13 * V_14 )
{
F_24 ( V_98 -> V_106 -> V_92 ) ;
}
static int F_35 ( struct V_88 * V_36 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_36 ( V_36 , V_111 , V_20 -> V_23 ) )
goto V_114;
if ( F_37 ( V_36 , V_102 , F_38 ( V_20 -> V_37 ) ) )
goto V_114;
switch ( V_20 -> V_37 ) {
case V_71 :
case V_79 :
case V_72 :
case V_77 :
case V_80 :
case V_84 :
if ( F_39 ( V_36 , V_103 , V_20 -> V_69 ) )
goto V_114;
break;
case V_8 :
case V_64 :
if ( V_20 -> V_69 < V_7 &&
F_39 ( V_36 , V_103 , V_20 -> V_69 ) )
goto V_114;
break;
default:
break;
}
return 0 ;
V_114:
return - 1 ;
}
static int F_40 ( struct V_88 * V_36 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_36 ( V_36 , V_113 , V_20 -> V_90 ) )
goto V_114;
if ( F_37 ( V_36 , V_102 , F_38 ( V_20 -> V_37 ) ) )
goto V_114;
return 0 ;
V_114:
return - 1 ;
}
static const struct V_115 *
F_41 ( const struct V_97 * V_98 ,
const struct V_99 * const V_100 [] )
{
if ( V_100 [ V_102 ] == NULL )
return F_42 ( - V_104 ) ;
if ( V_100 [ V_111 ] && V_100 [ V_113 ] )
return F_42 ( - V_104 ) ;
if ( V_100 [ V_111 ] )
return & V_116 ;
if ( V_100 [ V_113 ] )
return & V_117 ;
return F_42 ( - V_104 ) ;
}
static int T_4 F_43 ( void )
{
return F_44 ( & V_118 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_118 ) ;
}
