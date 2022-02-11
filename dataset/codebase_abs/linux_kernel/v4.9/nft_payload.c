static bool
F_1 ( T_1 * V_1 , const struct V_2 * V_3 , T_2 V_4 , T_2 V_5 )
{
int V_6 = F_2 ( V_3 ) - V_3 -> V_7 ;
T_2 V_8 , * V_9 , * V_10 = ( T_2 * ) V_1 ;
struct V_11 V_12 ;
V_9 = ( T_2 * ) & V_12 ;
if ( V_4 < V_13 ) {
T_2 V_14 = F_3 ( T_2 , V_5 , V_13 - V_4 ) ;
if ( F_4 ( V_3 , V_6 , & V_12 , V_13 ) )
return false ;
V_12 . V_15 = V_3 -> V_16 ;
memcpy ( V_10 , V_9 + V_4 , V_14 ) ;
V_5 -= V_14 ;
if ( V_5 == 0 )
return true ;
V_10 += V_14 ;
V_4 = V_13 ;
} else if ( V_4 >= V_17 ) {
V_4 -= V_18 ;
goto V_19;
}
V_12 . V_20 = F_5 ( F_6 ( V_3 ) ) ;
V_12 . V_21 = V_3 -> V_22 ;
V_9 += V_4 ;
V_8 = F_3 ( T_2 , V_5 , V_17 - V_4 ) ;
memcpy ( V_10 , V_9 , V_8 ) ;
V_5 -= V_8 ;
if ( ! V_5 )
return true ;
V_10 += V_8 ;
V_19:
return F_4 ( V_3 , V_4 + V_6 , V_10 , V_5 ) == 0 ;
}
static void F_7 ( const struct V_23 * V_24 ,
struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
const struct V_29 * V_30 = F_8 ( V_24 ) ;
const struct V_2 * V_3 = V_28 -> V_3 ;
T_1 * V_31 = & V_26 -> V_7 [ V_30 -> V_32 ] ;
int V_4 ;
V_31 [ V_30 -> V_5 / V_33 ] = 0 ;
switch ( V_30 -> V_34 ) {
case V_35 :
if ( ! F_9 ( V_3 ) )
goto V_36;
if ( F_10 ( V_3 ) ) {
if ( ! F_1 ( V_31 , V_3 ,
V_30 -> V_4 , V_30 -> V_5 ) )
goto V_36;
return;
}
V_4 = F_2 ( V_3 ) - V_3 -> V_7 ;
break;
case V_37 :
V_4 = F_11 ( V_3 ) ;
break;
case V_38 :
if ( ! V_28 -> V_39 )
goto V_36;
V_4 = V_28 -> V_40 . V_41 ;
break;
default:
F_12 () ;
}
V_4 += V_30 -> V_4 ;
if ( F_4 ( V_3 , V_4 , V_31 , V_30 -> V_5 ) < 0 )
goto V_36;
return;
V_36:
V_26 -> V_42 . V_43 = V_44 ;
}
static int F_13 ( const struct V_45 * V_46 ,
const struct V_23 * V_24 ,
const struct V_47 * const V_48 [] )
{
struct V_29 * V_30 = F_8 ( V_24 ) ;
V_30 -> V_34 = F_14 ( F_15 ( V_48 [ V_49 ] ) ) ;
V_30 -> V_4 = F_14 ( F_15 ( V_48 [ V_50 ] ) ) ;
V_30 -> V_5 = F_14 ( F_15 ( V_48 [ V_51 ] ) ) ;
V_30 -> V_32 = F_16 ( V_48 [ V_52 ] ) ;
return F_17 ( V_46 , V_30 -> V_32 , NULL ,
V_53 , V_30 -> V_5 ) ;
}
static int F_18 ( struct V_2 * V_3 , const struct V_23 * V_24 )
{
const struct V_29 * V_30 = F_8 ( V_24 ) ;
if ( F_19 ( V_3 , V_52 , V_30 -> V_32 ) ||
F_20 ( V_3 , V_49 , F_21 ( V_30 -> V_34 ) ) ||
F_20 ( V_3 , V_50 , F_21 ( V_30 -> V_4 ) ) ||
F_20 ( V_3 , V_51 , F_21 ( V_30 -> V_5 ) ) )
goto V_54;
return 0 ;
V_54:
return - 1 ;
}
static void F_22 ( const struct V_23 * V_24 ,
struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
const struct V_55 * V_30 = F_8 ( V_24 ) ;
struct V_2 * V_3 = V_28 -> V_3 ;
const T_1 * V_56 = & V_26 -> V_7 [ V_30 -> V_57 ] ;
int V_4 , V_58 ;
T_3 V_59 , V_60 ;
T_4 V_61 ;
switch ( V_30 -> V_34 ) {
case V_35 :
if ( ! F_9 ( V_3 ) )
goto V_36;
V_4 = F_2 ( V_3 ) - V_3 -> V_7 ;
break;
case V_37 :
V_4 = F_11 ( V_3 ) ;
break;
case V_38 :
if ( ! V_28 -> V_39 )
goto V_36;
V_4 = V_28 -> V_40 . V_41 ;
break;
default:
F_12 () ;
}
V_58 = V_4 + V_30 -> V_58 ;
V_4 += V_30 -> V_4 ;
if ( V_30 -> V_62 == V_63 &&
( V_30 -> V_34 != V_38 ||
V_3 -> V_64 != V_65 ) ) {
if ( F_4 ( V_3 , V_58 , & V_61 , sizeof( V_61 ) ) < 0 )
goto V_36;
V_59 = F_23 ( V_3 , V_4 , V_30 -> V_5 , 0 ) ;
V_60 = F_24 ( V_56 , V_30 -> V_5 , 0 ) ;
V_61 = F_25 ( F_26 ( F_27 ( ~ F_28 ( V_61 ) , V_59 ) ,
V_60 ) ) ;
if ( V_61 == 0 )
V_61 = V_66 ;
if ( ! F_29 ( V_3 , V_58 + sizeof( V_61 ) ) ||
F_30 ( V_3 , V_58 , & V_61 , sizeof( V_61 ) ) < 0 )
goto V_36;
}
if ( ! F_29 ( V_3 , F_31 ( V_4 + V_30 -> V_5 , 0 ) ) ||
F_30 ( V_3 , V_4 , V_56 , V_30 -> V_5 ) < 0 )
goto V_36;
return;
V_36:
V_26 -> V_42 . V_43 = V_44 ;
}
static int F_32 ( const struct V_45 * V_46 ,
const struct V_23 * V_24 ,
const struct V_47 * const V_48 [] )
{
struct V_55 * V_30 = F_8 ( V_24 ) ;
V_30 -> V_34 = F_14 ( F_15 ( V_48 [ V_49 ] ) ) ;
V_30 -> V_4 = F_14 ( F_15 ( V_48 [ V_50 ] ) ) ;
V_30 -> V_5 = F_14 ( F_15 ( V_48 [ V_51 ] ) ) ;
V_30 -> V_57 = F_16 ( V_48 [ V_67 ] ) ;
if ( V_48 [ V_68 ] )
V_30 -> V_62 =
F_14 ( F_15 ( V_48 [ V_68 ] ) ) ;
if ( V_48 [ V_69 ] )
V_30 -> V_58 =
F_14 ( F_15 ( V_48 [ V_69 ] ) ) ;
switch ( V_30 -> V_62 ) {
case V_70 :
case V_63 :
break;
default:
return - V_71 ;
}
return F_33 ( V_30 -> V_57 , V_30 -> V_5 ) ;
}
static int F_34 ( struct V_2 * V_3 , const struct V_23 * V_24 )
{
const struct V_55 * V_30 = F_8 ( V_24 ) ;
if ( F_19 ( V_3 , V_67 , V_30 -> V_57 ) ||
F_20 ( V_3 , V_49 , F_21 ( V_30 -> V_34 ) ) ||
F_20 ( V_3 , V_50 , F_21 ( V_30 -> V_4 ) ) ||
F_20 ( V_3 , V_51 , F_21 ( V_30 -> V_5 ) ) ||
F_20 ( V_3 , V_68 , F_21 ( V_30 -> V_62 ) ) ||
F_20 ( V_3 , V_69 ,
F_21 ( V_30 -> V_58 ) ) )
goto V_54;
return 0 ;
V_54:
return - 1 ;
}
static const struct V_72 *
F_35 ( const struct V_45 * V_46 ,
const struct V_47 * const V_48 [] )
{
enum V_73 V_34 ;
unsigned int V_4 , V_5 ;
if ( V_48 [ V_49 ] == NULL ||
V_48 [ V_50 ] == NULL ||
V_48 [ V_51 ] == NULL )
return F_36 ( - V_74 ) ;
V_34 = F_14 ( F_15 ( V_48 [ V_49 ] ) ) ;
switch ( V_34 ) {
case V_35 :
case V_37 :
case V_38 :
break;
default:
return F_36 ( - V_71 ) ;
}
if ( V_48 [ V_67 ] != NULL ) {
if ( V_48 [ V_52 ] != NULL )
return F_36 ( - V_74 ) ;
return & V_75 ;
}
if ( V_48 [ V_52 ] == NULL )
return F_36 ( - V_74 ) ;
V_4 = F_14 ( F_15 ( V_48 [ V_50 ] ) ) ;
V_5 = F_14 ( F_15 ( V_48 [ V_51 ] ) ) ;
if ( V_5 <= 4 && F_37 ( V_5 ) && F_38 ( V_4 , V_5 ) &&
V_34 != V_35 )
return & V_76 ;
else
return & V_77 ;
}
int T_5 F_39 ( void )
{
return F_40 ( & V_78 ) ;
}
void F_41 ( void )
{
F_42 ( & V_78 ) ;
}
