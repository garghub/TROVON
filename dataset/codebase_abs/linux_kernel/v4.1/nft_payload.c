static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
T_1 * V_11 = & V_4 -> V_12 [ V_8 -> V_13 ] ;
int V_14 ;
switch ( V_8 -> V_15 ) {
case V_16 :
if ( ! F_3 ( V_10 ) )
goto V_17;
V_14 = F_4 ( V_10 ) - V_10 -> V_12 ;
break;
case V_18 :
V_14 = F_5 ( V_10 ) ;
break;
case V_19 :
V_14 = V_6 -> V_20 . V_21 ;
break;
default:
F_6 () ;
}
V_14 += V_8 -> V_14 ;
V_11 [ V_8 -> V_22 / V_23 ] = 0 ;
if ( F_7 ( V_10 , V_14 , V_11 , V_8 -> V_22 ) < 0 )
goto V_17;
return;
V_17:
V_4 -> V_24 . V_25 = V_26 ;
}
static int F_8 ( const struct V_27 * V_28 ,
const struct V_1 * V_2 ,
const struct V_29 * const V_30 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_15 = F_9 ( F_10 ( V_30 [ V_31 ] ) ) ;
V_8 -> V_14 = F_9 ( F_10 ( V_30 [ V_32 ] ) ) ;
V_8 -> V_22 = F_9 ( F_10 ( V_30 [ V_33 ] ) ) ;
V_8 -> V_13 = F_11 ( V_30 [ V_34 ] ) ;
return F_12 ( V_28 , V_8 -> V_13 , NULL ,
V_35 , V_8 -> V_22 ) ;
}
static int F_13 ( struct V_9 * V_10 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_14 ( V_10 , V_34 , V_8 -> V_13 ) ||
F_15 ( V_10 , V_31 , F_16 ( V_8 -> V_15 ) ) ||
F_15 ( V_10 , V_32 , F_16 ( V_8 -> V_14 ) ) ||
F_15 ( V_10 , V_33 , F_16 ( V_8 -> V_22 ) ) )
goto V_36;
return 0 ;
V_36:
return - 1 ;
}
static const struct V_37 *
F_17 ( const struct V_27 * V_28 ,
const struct V_29 * const V_30 [] )
{
enum V_38 V_15 ;
unsigned int V_14 , V_22 ;
if ( V_30 [ V_34 ] == NULL ||
V_30 [ V_31 ] == NULL ||
V_30 [ V_32 ] == NULL ||
V_30 [ V_33 ] == NULL )
return F_18 ( - V_39 ) ;
V_15 = F_9 ( F_10 ( V_30 [ V_31 ] ) ) ;
switch ( V_15 ) {
case V_16 :
case V_18 :
case V_19 :
break;
default:
return F_18 ( - V_40 ) ;
}
V_14 = F_9 ( F_10 ( V_30 [ V_32 ] ) ) ;
V_22 = F_9 ( F_10 ( V_30 [ V_33 ] ) ) ;
if ( V_22 <= 4 && F_19 ( V_22 ) && F_20 ( V_14 , V_22 ) &&
V_15 != V_16 )
return & V_41 ;
else
return & V_42 ;
}
int T_2 F_21 ( void )
{
return F_22 ( & V_43 ) ;
}
void F_23 ( void )
{
F_24 ( & V_43 ) ;
}
