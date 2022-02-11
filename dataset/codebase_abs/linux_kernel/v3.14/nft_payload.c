static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = V_7 -> V_11 ;
struct V_3 * V_12 = & V_4 [ V_9 -> V_13 ] ;
int V_14 ;
switch ( V_9 -> V_15 ) {
case V_16 :
if ( ! F_3 ( V_11 ) )
goto V_17;
V_14 = F_4 ( V_11 ) - V_11 -> V_4 ;
break;
case V_18 :
V_14 = F_5 ( V_11 ) ;
break;
case V_19 :
V_14 = V_7 -> V_20 . V_21 ;
break;
default:
F_6 () ;
}
V_14 += V_9 -> V_14 ;
if ( F_7 ( V_11 , V_14 , V_12 -> V_4 , V_9 -> V_22 ) < 0 )
goto V_17;
return;
V_17:
V_4 [ V_23 ] . V_24 = V_25 ;
}
static int F_8 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 ,
const struct V_28 * const V_29 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_17 ;
V_9 -> V_15 = F_9 ( F_10 ( V_29 [ V_30 ] ) ) ;
V_9 -> V_14 = F_9 ( F_10 ( V_29 [ V_31 ] ) ) ;
V_9 -> V_22 = F_9 ( F_10 ( V_29 [ V_32 ] ) ) ;
V_9 -> V_13 = F_9 ( F_10 ( V_29 [ V_33 ] ) ) ;
V_17 = F_11 ( V_9 -> V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_12 ( V_27 , V_9 -> V_13 , NULL , V_34 ) ;
}
static int F_13 ( struct V_10 * V_11 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_14 ( V_11 , V_33 , F_15 ( V_9 -> V_13 ) ) ||
F_14 ( V_11 , V_30 , F_15 ( V_9 -> V_15 ) ) ||
F_14 ( V_11 , V_31 , F_15 ( V_9 -> V_14 ) ) ||
F_14 ( V_11 , V_32 , F_15 ( V_9 -> V_22 ) ) )
goto V_35;
return 0 ;
V_35:
return - 1 ;
}
static const struct V_36 *
F_16 ( const struct V_26 * V_27 ,
const struct V_28 * const V_29 [] )
{
enum V_37 V_15 ;
unsigned int V_14 , V_22 ;
if ( V_29 [ V_33 ] == NULL ||
V_29 [ V_30 ] == NULL ||
V_29 [ V_31 ] == NULL ||
V_29 [ V_32 ] == NULL )
return F_17 ( - V_38 ) ;
V_15 = F_9 ( F_10 ( V_29 [ V_30 ] ) ) ;
switch ( V_15 ) {
case V_16 :
case V_18 :
case V_19 :
break;
default:
return F_17 ( - V_39 ) ;
}
V_14 = F_9 ( F_10 ( V_29 [ V_31 ] ) ) ;
V_22 = F_9 ( F_10 ( V_29 [ V_32 ] ) ) ;
if ( V_22 == 0 || V_22 > F_18 ( struct V_3 , V_4 ) )
return F_17 ( - V_38 ) ;
if ( V_22 <= 4 && F_19 ( V_22 ) && F_20 ( V_14 , V_22 ) &&
V_15 != V_16 )
return & V_40 ;
else
return & V_41 ;
}
int T_1 F_21 ( void )
{
return F_22 ( & V_42 ) ;
}
void F_23 ( void )
{
F_24 ( & V_42 ) ;
}
