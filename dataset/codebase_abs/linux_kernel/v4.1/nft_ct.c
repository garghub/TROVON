static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 * V_9 = & V_4 -> V_10 [ V_8 -> V_11 ] ;
enum V_12 V_13 ;
const struct V_14 * V_15 ;
const struct V_16 * V_17 ;
const struct V_18 * V_19 ;
const struct V_20 * V_21 ;
long V_22 ;
unsigned int V_23 ;
V_15 = F_3 ( V_6 -> V_24 , & V_13 ) ;
switch ( V_8 -> V_25 ) {
case V_26 :
if ( V_15 == NULL )
V_23 = V_27 ;
else if ( F_4 ( V_15 ) )
V_23 = V_28 ;
else
V_23 = F_5 ( V_13 ) ;
* V_9 = V_23 ;
return;
default:
break;
}
if ( V_15 == NULL )
goto V_29;
switch ( V_8 -> V_25 ) {
case V_30 :
* V_9 = F_6 ( V_13 ) ;
return;
case V_31 :
* V_9 = V_15 -> V_32 ;
return;
#ifdef F_7
case V_33 :
* V_9 = V_15 -> V_34 ;
return;
#endif
#ifdef F_8
case V_35 :
* V_9 = V_15 -> V_36 ;
return;
#endif
case V_37 :
V_22 = ( long ) V_38 - ( long ) V_15 -> V_39 . V_40 ;
if ( V_22 < 0 )
V_22 = 0 ;
* V_9 = F_9 ( V_22 ) ;
return;
case V_41 :
if ( V_15 -> V_42 == NULL )
goto V_29;
V_17 = F_10 ( V_15 -> V_42 ) ;
if ( V_17 == NULL )
goto V_29;
V_21 = F_11 ( V_17 -> V_21 ) ;
if ( V_21 == NULL )
goto V_29;
strncpy ( ( char * ) V_9 , V_21 -> V_43 , V_44 ) ;
return;
#ifdef F_12
case V_45 : {
struct V_46 * V_47 = F_13 ( V_15 ) ;
unsigned int V_48 ;
if ( ! V_47 ) {
memset ( V_9 , 0 , V_49 ) ;
return;
}
V_48 = V_47 -> V_50 * sizeof( long ) ;
memcpy ( V_9 , V_47 -> V_51 , V_48 ) ;
if ( V_48 < V_49 )
memset ( ( ( char * ) V_9 ) + V_48 , 0 ,
V_49 - V_48 ) ;
return;
}
#endif
default:
break;
}
V_19 = & V_15 -> V_52 [ V_8 -> V_53 ] . V_19 ;
switch ( V_8 -> V_25 ) {
case V_54 :
* V_9 = F_14 ( V_15 ) ;
return;
case V_55 :
memcpy ( V_9 , V_19 -> V_56 . V_57 . V_58 ,
F_14 ( V_15 ) == V_59 ? 4 : 16 ) ;
return;
case V_60 :
memcpy ( V_9 , V_19 -> V_61 . V_57 . V_58 ,
F_14 ( V_15 ) == V_59 ? 4 : 16 ) ;
return;
case V_62 :
* V_9 = F_15 ( V_15 ) ;
return;
case V_63 :
* V_9 = ( V_64 V_65 ) V_19 -> V_56 . V_66 . V_58 ;
return;
case V_67 :
* V_9 = ( V_64 V_65 ) V_19 -> V_61 . V_66 . V_58 ;
return;
default:
break;
}
return;
V_29:
V_4 -> V_68 . V_69 = V_70 ;
}
static void F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_71 * V_24 = V_6 -> V_24 ;
#ifdef F_7
T_1 V_72 = V_4 -> V_10 [ V_8 -> V_73 ] ;
#endif
enum V_12 V_13 ;
struct V_14 * V_15 ;
V_15 = F_3 ( V_24 , & V_13 ) ;
if ( V_15 == NULL )
return;
switch ( V_8 -> V_25 ) {
#ifdef F_7
case V_33 :
if ( V_15 -> V_34 != V_72 ) {
V_15 -> V_34 = V_72 ;
F_17 ( V_74 , V_15 ) ;
}
break;
#endif
default:
break;
}
}
static int F_18 ( T_2 V_75 )
{
int V_29 ;
if ( V_75 == V_76 ) {
V_29 = F_19 ( V_59 ) ;
if ( V_29 < 0 )
goto V_77;
V_29 = F_19 ( V_78 ) ;
if ( V_29 < 0 )
goto V_79;
} else {
V_29 = F_19 ( V_75 ) ;
if ( V_29 < 0 )
goto V_77;
}
return 0 ;
V_79:
F_20 ( V_59 ) ;
V_77:
return V_29 ;
}
static void F_21 ( T_2 V_75 )
{
if ( V_75 == V_76 ) {
F_20 ( V_59 ) ;
F_20 ( V_78 ) ;
} else
F_20 ( V_75 ) ;
}
static int F_22 ( const struct V_80 * V_81 ,
const struct V_1 * V_2 ,
const struct V_82 * const V_83 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_84 ;
int V_29 ;
V_8 -> V_25 = F_23 ( F_24 ( V_83 [ V_85 ] ) ) ;
switch ( V_8 -> V_25 ) {
case V_30 :
if ( V_83 [ V_86 ] != NULL )
return - V_87 ;
V_84 = sizeof( V_88 ) ;
break;
case V_26 :
case V_31 :
#ifdef F_7
case V_33 :
#endif
#ifdef F_8
case V_35 :
#endif
case V_37 :
if ( V_83 [ V_86 ] != NULL )
return - V_87 ;
V_84 = sizeof( T_1 ) ;
break;
#ifdef F_12
case V_45 :
if ( V_83 [ V_86 ] != NULL )
return - V_87 ;
V_84 = V_49 ;
break;
#endif
case V_41 :
if ( V_83 [ V_86 ] != NULL )
return - V_87 ;
V_84 = V_44 ;
break;
case V_54 :
case V_62 :
if ( V_83 [ V_86 ] == NULL )
return - V_87 ;
V_84 = sizeof( V_88 ) ;
break;
case V_55 :
case V_60 :
if ( V_83 [ V_86 ] == NULL )
return - V_87 ;
switch ( V_81 -> V_89 -> V_75 ) {
case V_59 :
V_84 = F_25 ( struct V_18 ,
V_56 . V_57 . V_90 ) ;
break;
case V_78 :
case V_76 :
V_84 = F_25 ( struct V_18 ,
V_56 . V_57 . V_91 ) ;
break;
default:
return - V_92 ;
}
break;
case V_63 :
case V_67 :
if ( V_83 [ V_86 ] == NULL )
return - V_87 ;
V_84 = F_25 ( struct V_18 , V_56 . V_66 . V_58 ) ;
break;
default:
return - V_93 ;
}
if ( V_83 [ V_86 ] != NULL ) {
V_8 -> V_53 = F_26 ( V_83 [ V_86 ] ) ;
switch ( V_8 -> V_53 ) {
case V_94 :
case V_95 :
break;
default:
return - V_87 ;
}
}
V_8 -> V_11 = F_27 ( V_83 [ V_96 ] ) ;
V_29 = F_28 ( V_81 , V_8 -> V_11 , NULL ,
V_97 , V_84 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_18 ( V_81 -> V_89 -> V_75 ) ;
if ( V_29 < 0 )
return V_29 ;
return 0 ;
}
static int F_29 ( const struct V_80 * V_81 ,
const struct V_1 * V_2 ,
const struct V_82 * const V_83 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_84 ;
int V_29 ;
V_8 -> V_25 = F_23 ( F_24 ( V_83 [ V_85 ] ) ) ;
switch ( V_8 -> V_25 ) {
#ifdef F_7
case V_33 :
V_84 = F_25 ( struct V_14 , V_34 ) ;
break;
#endif
default:
return - V_93 ;
}
V_8 -> V_73 = F_27 ( V_83 [ V_98 ] ) ;
V_29 = F_30 ( V_8 -> V_73 , V_84 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_18 ( V_81 -> V_89 -> V_75 ) ;
if ( V_29 < 0 )
return V_29 ;
return 0 ;
}
static void F_31 ( const struct V_80 * V_81 ,
const struct V_1 * V_2 )
{
F_21 ( V_81 -> V_89 -> V_75 ) ;
}
static int F_32 ( struct V_71 * V_24 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_33 ( V_24 , V_96 , V_8 -> V_11 ) )
goto V_99;
if ( F_34 ( V_24 , V_85 , F_35 ( V_8 -> V_25 ) ) )
goto V_99;
switch ( V_8 -> V_25 ) {
case V_62 :
case V_55 :
case V_60 :
case V_63 :
case V_67 :
if ( F_36 ( V_24 , V_86 , V_8 -> V_53 ) )
goto V_99;
default:
break;
}
return 0 ;
V_99:
return - 1 ;
}
static int F_37 ( struct V_71 * V_24 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_33 ( V_24 , V_98 , V_8 -> V_73 ) )
goto V_99;
if ( F_34 ( V_24 , V_85 , F_35 ( V_8 -> V_25 ) ) )
goto V_99;
return 0 ;
V_99:
return - 1 ;
}
static const struct V_100 *
F_38 ( const struct V_80 * V_81 ,
const struct V_82 * const V_83 [] )
{
if ( V_83 [ V_85 ] == NULL )
return F_39 ( - V_87 ) ;
if ( V_83 [ V_96 ] && V_83 [ V_98 ] )
return F_39 ( - V_87 ) ;
if ( V_83 [ V_96 ] )
return & V_101 ;
if ( V_83 [ V_98 ] )
return & V_102 ;
return F_39 ( - V_87 ) ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_103 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_103 ) ;
}
