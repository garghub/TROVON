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
}
V_19 = & V_15 -> V_44 [ V_9 -> V_45 ] . V_19 ;
switch ( V_9 -> V_25 ) {
case V_46 :
V_10 -> V_4 [ 0 ] = F_12 ( V_15 ) ;
return;
case V_47 :
memcpy ( V_10 -> V_4 , V_19 -> V_48 . V_49 . V_50 ,
F_12 ( V_15 ) == V_51 ? 4 : 16 ) ;
return;
case V_52 :
memcpy ( V_10 -> V_4 , V_19 -> V_53 . V_49 . V_50 ,
F_12 ( V_15 ) == V_51 ? 4 : 16 ) ;
return;
case V_54 :
V_10 -> V_4 [ 0 ] = F_13 ( V_15 ) ;
return;
case V_55 :
V_10 -> V_4 [ 0 ] = ( V_56 V_57 ) V_19 -> V_48 . V_58 . V_50 ;
return;
case V_59 :
V_10 -> V_4 [ 0 ] = ( V_56 V_57 ) V_19 -> V_53 . V_58 . V_50 ;
return;
}
return;
V_29:
V_4 [ V_60 ] . V_61 = V_62 ;
}
static int F_14 ( const struct V_63 * V_64 ,
const struct V_1 * V_2 ,
const struct V_65 * const V_66 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_29 ;
if ( V_66 [ V_67 ] == NULL ||
V_66 [ V_68 ] == NULL )
return - V_69 ;
V_9 -> V_25 = F_15 ( F_16 ( V_66 [ V_68 ] ) ) ;
if ( V_66 [ V_70 ] != NULL ) {
V_9 -> V_45 = F_17 ( V_66 [ V_70 ] ) ;
switch ( V_9 -> V_45 ) {
case V_71 :
case V_72 :
break;
default:
return - V_69 ;
}
}
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
case V_37 :
case V_41 :
if ( V_66 [ V_70 ] != NULL )
return - V_69 ;
break;
case V_54 :
case V_47 :
case V_52 :
case V_55 :
case V_59 :
if ( V_66 [ V_70 ] == NULL )
return - V_69 ;
break;
default:
return - V_73 ;
}
V_29 = F_18 ( V_64 -> V_74 -> V_75 ) ;
if ( V_29 < 0 )
return V_29 ;
V_9 -> V_75 = V_64 -> V_74 -> V_75 ;
V_9 -> V_11 = F_15 ( F_16 ( V_66 [ V_67 ] ) ) ;
V_29 = F_19 ( V_9 -> V_11 ) ;
if ( V_29 < 0 )
goto V_76;
V_29 = F_20 ( V_64 , V_9 -> V_11 , NULL , V_77 ) ;
if ( V_29 < 0 )
goto V_76;
return 0 ;
V_76:
F_21 ( V_64 -> V_74 -> V_75 ) ;
return V_29 ;
}
static void F_22 ( const struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_21 ( V_9 -> V_75 ) ;
}
static int F_23 ( struct V_78 * V_24 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_24 ( V_24 , V_67 , F_25 ( V_9 -> V_11 ) ) )
goto V_79;
if ( F_24 ( V_24 , V_68 , F_25 ( V_9 -> V_25 ) ) )
goto V_79;
if ( F_26 ( V_24 , V_70 , V_9 -> V_45 ) )
goto V_79;
return 0 ;
V_79:
return - 1 ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_80 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_80 ) ;
}
