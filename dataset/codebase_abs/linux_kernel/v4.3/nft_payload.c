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
V_4 = V_28 -> V_39 . V_40 ;
break;
default:
F_12 () ;
}
V_4 += V_30 -> V_4 ;
if ( F_4 ( V_3 , V_4 , V_31 , V_30 -> V_5 ) < 0 )
goto V_36;
return;
V_36:
V_26 -> V_41 . V_42 = V_43 ;
}
static int F_13 ( const struct V_44 * V_45 ,
const struct V_23 * V_24 ,
const struct V_46 * const V_47 [] )
{
struct V_29 * V_30 = F_8 ( V_24 ) ;
V_30 -> V_34 = F_14 ( F_15 ( V_47 [ V_48 ] ) ) ;
V_30 -> V_4 = F_14 ( F_15 ( V_47 [ V_49 ] ) ) ;
V_30 -> V_5 = F_14 ( F_15 ( V_47 [ V_50 ] ) ) ;
V_30 -> V_32 = F_16 ( V_47 [ V_51 ] ) ;
return F_17 ( V_45 , V_30 -> V_32 , NULL ,
V_52 , V_30 -> V_5 ) ;
}
static int F_18 ( struct V_2 * V_3 , const struct V_23 * V_24 )
{
const struct V_29 * V_30 = F_8 ( V_24 ) ;
if ( F_19 ( V_3 , V_51 , V_30 -> V_32 ) ||
F_20 ( V_3 , V_48 , F_21 ( V_30 -> V_34 ) ) ||
F_20 ( V_3 , V_49 , F_21 ( V_30 -> V_4 ) ) ||
F_20 ( V_3 , V_50 , F_21 ( V_30 -> V_5 ) ) )
goto V_53;
return 0 ;
V_53:
return - 1 ;
}
static const struct V_54 *
F_22 ( const struct V_44 * V_45 ,
const struct V_46 * const V_47 [] )
{
enum V_55 V_34 ;
unsigned int V_4 , V_5 ;
if ( V_47 [ V_51 ] == NULL ||
V_47 [ V_48 ] == NULL ||
V_47 [ V_49 ] == NULL ||
V_47 [ V_50 ] == NULL )
return F_23 ( - V_56 ) ;
V_34 = F_14 ( F_15 ( V_47 [ V_48 ] ) ) ;
switch ( V_34 ) {
case V_35 :
case V_37 :
case V_38 :
break;
default:
return F_23 ( - V_57 ) ;
}
V_4 = F_14 ( F_15 ( V_47 [ V_49 ] ) ) ;
V_5 = F_14 ( F_15 ( V_47 [ V_50 ] ) ) ;
if ( V_5 <= 4 && F_24 ( V_5 ) && F_25 ( V_4 , V_5 ) &&
V_34 != V_35 )
return & V_58 ;
else
return & V_59 ;
}
int T_3 F_26 ( void )
{
return F_27 ( & V_60 ) ;
}
void F_28 ( void )
{
F_29 ( & V_60 ) ;
}
