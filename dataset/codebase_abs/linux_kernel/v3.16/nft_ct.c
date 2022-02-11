static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_3 * V_10 = & V_4 [ V_9 -> V_11 ] ;
enum V_12 V_13 ;
const struct V_14 * V_15 ;
const struct V_16 * V_17 ;
const struct V_18 * V_19 ;
const struct V_20 * V_21 ;
long V_22 ;
unsigned int V_23 ;
V_15 = F_3 ( V_7 -> V_24 , & V_13 ) ;
switch ( V_9 -> V_25 ) {
case V_26 :
if ( V_15 == NULL )
V_23 = V_27 ;
else if ( F_4 ( V_15 ) )
V_23 = V_28 ;
else
V_23 = F_5 ( V_13 ) ;
V_10 -> V_4 [ 0 ] = V_23 ;
return;
}
if ( V_15 == NULL )
goto V_29;
switch ( V_9 -> V_25 ) {
case V_30 :
V_10 -> V_4 [ 0 ] = F_6 ( V_13 ) ;
return;
case V_31 :
V_10 -> V_4 [ 0 ] = V_15 -> V_32 ;
return;
#ifdef F_7
case V_33 :
V_10 -> V_4 [ 0 ] = V_15 -> V_34 ;
return;
#endif
#ifdef F_8
case V_35 :
V_10 -> V_4 [ 0 ] = V_15 -> V_36 ;
return;
#endif
case V_37 :
V_22 = ( long ) V_38 - ( long ) V_15 -> V_39 . V_40 ;
if ( V_22 < 0 )
V_22 = 0 ;
V_10 -> V_4 [ 0 ] = F_9 ( V_22 ) ;
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
if ( strlen ( V_21 -> V_43 ) >= sizeof( V_10 -> V_4 ) )
goto V_29;
strncpy ( ( char * ) V_10 -> V_4 , V_21 -> V_43 , sizeof( V_10 -> V_4 ) ) ;
return;
#ifdef F_12
case V_44 : {
struct V_45 * V_46 = F_13 ( V_15 ) ;
unsigned int V_47 ;
if ( ! V_46 ) {
memset ( V_10 -> V_4 , 0 , sizeof( V_10 -> V_4 ) ) ;
return;
}
F_14 ( V_48 > sizeof( V_10 -> V_4 ) ) ;
V_47 = V_46 -> V_49 * sizeof( long ) ;
memcpy ( V_10 -> V_4 , V_46 -> V_50 , V_47 ) ;
if ( V_47 < sizeof( V_10 -> V_4 ) )
memset ( ( ( char * ) V_10 -> V_4 ) + V_47 , 0 ,
sizeof( V_10 -> V_4 ) - V_47 ) ;
return;
}
#endif
}
V_19 = & V_15 -> V_51 [ V_9 -> V_52 ] . V_19 ;
switch ( V_9 -> V_25 ) {
case V_53 :
V_10 -> V_4 [ 0 ] = F_15 ( V_15 ) ;
return;
case V_54 :
memcpy ( V_10 -> V_4 , V_19 -> V_55 . V_56 . V_57 ,
F_15 ( V_15 ) == V_58 ? 4 : 16 ) ;
return;
case V_59 :
memcpy ( V_10 -> V_4 , V_19 -> V_60 . V_56 . V_57 ,
F_15 ( V_15 ) == V_58 ? 4 : 16 ) ;
return;
case V_61 :
V_10 -> V_4 [ 0 ] = F_16 ( V_15 ) ;
return;
case V_62 :
V_10 -> V_4 [ 0 ] = ( V_63 V_64 ) V_19 -> V_55 . V_65 . V_57 ;
return;
case V_66 :
V_10 -> V_4 [ 0 ] = ( V_63 V_64 ) V_19 -> V_60 . V_65 . V_57 ;
return;
}
return;
V_29:
V_4 [ V_67 ] . V_68 = V_69 ;
}
static void F_17 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_70 * V_24 = V_7 -> V_24 ;
#ifdef F_7
T_1 V_71 = V_4 [ V_9 -> V_72 ] . V_4 [ 0 ] ;
#endif
enum V_12 V_13 ;
struct V_14 * V_15 ;
V_15 = F_3 ( V_24 , & V_13 ) ;
if ( V_15 == NULL )
return;
switch ( V_9 -> V_25 ) {
#ifdef F_7
case V_33 :
if ( V_15 -> V_34 != V_71 ) {
V_15 -> V_34 = V_71 ;
F_18 ( V_73 , V_15 ) ;
}
break;
#endif
}
}
static int F_19 ( T_2 V_74 )
{
int V_29 ;
if ( V_74 == V_75 ) {
V_29 = F_20 ( V_58 ) ;
if ( V_29 < 0 )
goto V_76;
V_29 = F_20 ( V_77 ) ;
if ( V_29 < 0 )
goto V_78;
} else {
V_29 = F_20 ( V_74 ) ;
if ( V_29 < 0 )
goto V_76;
}
return 0 ;
V_78:
F_21 ( V_58 ) ;
V_76:
return V_29 ;
}
static void F_22 ( T_2 V_74 )
{
if ( V_74 == V_75 ) {
F_21 ( V_58 ) ;
F_21 ( V_77 ) ;
} else
F_21 ( V_74 ) ;
}
static int F_23 ( const struct V_79 * V_80 ,
const struct V_1 * V_2 ,
const struct V_81 * const V_82 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_29 ;
V_9 -> V_25 = F_24 ( F_25 ( V_82 [ V_83 ] ) ) ;
switch ( V_9 -> V_25 ) {
case V_26 :
case V_30 :
case V_31 :
#ifdef F_7
case V_33 :
#endif
#ifdef F_8
case V_35 :
#endif
#ifdef F_12
case V_44 :
#endif
case V_37 :
case V_41 :
if ( V_82 [ V_84 ] != NULL )
return - V_85 ;
break;
case V_53 :
case V_61 :
case V_54 :
case V_59 :
case V_62 :
case V_66 :
if ( V_82 [ V_84 ] == NULL )
return - V_85 ;
break;
default:
return - V_86 ;
}
if ( V_82 [ V_84 ] != NULL ) {
V_9 -> V_52 = F_26 ( V_82 [ V_84 ] ) ;
switch ( V_9 -> V_52 ) {
case V_87 :
case V_88 :
break;
default:
return - V_85 ;
}
}
V_9 -> V_11 = F_24 ( F_25 ( V_82 [ V_89 ] ) ) ;
V_29 = F_27 ( V_9 -> V_11 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_28 ( V_80 , V_9 -> V_11 , NULL , V_90 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_19 ( V_80 -> V_91 -> V_74 ) ;
if ( V_29 < 0 )
return V_29 ;
return 0 ;
}
static int F_29 ( const struct V_79 * V_80 ,
const struct V_1 * V_2 ,
const struct V_81 * const V_82 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_29 ;
V_9 -> V_25 = F_24 ( F_25 ( V_82 [ V_83 ] ) ) ;
switch ( V_9 -> V_25 ) {
#ifdef F_7
case V_33 :
break;
#endif
default:
return - V_86 ;
}
V_9 -> V_72 = F_24 ( F_25 ( V_82 [ V_92 ] ) ) ;
V_29 = F_30 ( V_9 -> V_72 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_19 ( V_80 -> V_91 -> V_74 ) ;
if ( V_29 < 0 )
return V_29 ;
return 0 ;
}
static void F_31 ( const struct V_79 * V_80 ,
const struct V_1 * V_2 )
{
F_22 ( V_80 -> V_91 -> V_74 ) ;
}
static int F_32 ( struct V_70 * V_24 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_33 ( V_24 , V_89 , F_34 ( V_9 -> V_11 ) ) )
goto V_93;
if ( F_33 ( V_24 , V_83 , F_34 ( V_9 -> V_25 ) ) )
goto V_93;
switch ( V_9 -> V_25 ) {
case V_61 :
case V_54 :
case V_59 :
case V_62 :
case V_66 :
if ( F_35 ( V_24 , V_84 , V_9 -> V_52 ) )
goto V_93;
default:
break;
}
return 0 ;
V_93:
return - 1 ;
}
static int F_36 ( struct V_70 * V_24 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_33 ( V_24 , V_92 , F_34 ( V_9 -> V_72 ) ) )
goto V_93;
if ( F_33 ( V_24 , V_83 , F_34 ( V_9 -> V_25 ) ) )
goto V_93;
return 0 ;
V_93:
return - 1 ;
}
static const struct V_94 *
F_37 ( const struct V_79 * V_80 ,
const struct V_81 * const V_82 [] )
{
if ( V_82 [ V_83 ] == NULL )
return F_38 ( - V_85 ) ;
if ( V_82 [ V_89 ] && V_82 [ V_92 ] )
return F_38 ( - V_85 ) ;
if ( V_82 [ V_89 ] )
return & V_95 ;
if ( V_82 [ V_92 ] )
return & V_96 ;
return F_38 ( - V_85 ) ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_97 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_97 ) ;
}
