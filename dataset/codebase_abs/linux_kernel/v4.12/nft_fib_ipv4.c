static T_1 F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 ) || F_3 ( V_1 ) ||
F_4 ( V_1 ) )
return 0 ;
return V_1 ;
}
void F_5 ( const struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_6 ( V_3 ) ;
T_2 * V_10 = & V_5 -> V_11 [ V_9 -> V_12 ] ;
const struct V_13 * V_14 = NULL ;
const struct V_15 * V_16 ;
T_1 V_1 ;
if ( V_9 -> V_17 & V_18 )
V_14 = F_7 ( V_7 ) ;
else if ( V_9 -> V_17 & V_19 )
V_14 = F_8 ( V_7 ) ;
V_16 = F_9 ( V_7 -> V_20 ) ;
if ( V_9 -> V_17 & V_21 )
V_1 = V_16 -> V_22 ;
else
V_1 = V_16 -> V_23 ;
* V_10 = F_10 ( F_11 ( V_7 ) , V_14 , V_1 ) ;
}
static int F_12 ( const struct V_13 * V_14 )
{
return V_14 ? V_14 -> V_24 : 0 ;
}
void F_13 ( const struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_6 ( V_3 ) ;
T_2 * V_25 = & V_5 -> V_11 [ V_9 -> V_12 ] ;
const struct V_15 * V_16 ;
struct V_26 V_27 ;
struct V_28 V_29 = {
. V_30 = V_31 ,
. V_32 = V_33 ,
} ;
const struct V_13 * V_34 ;
struct V_13 * V_35 ;
#ifdef F_14
int V_36 ;
#endif
if ( V_9 -> V_17 & V_19 )
V_34 = F_8 ( V_7 ) ;
else if ( V_9 -> V_17 & V_18 )
V_34 = F_7 ( V_7 ) ;
else
V_34 = NULL ;
if ( F_15 ( V_7 ) == V_37 &&
F_16 ( V_7 -> V_20 , F_7 ( V_7 ) ) ) {
F_17 ( V_25 , V_9 , V_7 ,
F_7 ( V_7 ) -> V_24 ) ;
return;
}
V_16 = F_9 ( V_7 -> V_20 ) ;
if ( F_4 ( V_16 -> V_23 ) ) {
if ( F_3 ( V_16 -> V_22 ) ||
F_18 ( V_16 -> V_22 ) ) {
F_17 ( V_25 , V_9 , V_7 ,
F_12 ( V_7 -> V_20 -> V_14 ) ) ;
return;
}
}
if ( V_9 -> V_17 & V_38 )
V_29 . V_39 = V_7 -> V_20 -> V_40 ;
V_29 . V_41 = V_16 -> V_42 & V_43 ;
if ( V_9 -> V_17 & V_21 ) {
V_29 . V_22 = V_16 -> V_22 ;
V_29 . V_23 = F_1 ( V_16 -> V_23 ) ;
} else {
V_29 . V_22 = V_16 -> V_23 ;
V_29 . V_23 = F_1 ( V_16 -> V_22 ) ;
}
* V_25 = 0 ;
if ( F_19 ( F_11 ( V_7 ) , & V_29 , & V_27 , V_44 ) )
return;
switch ( V_27 . type ) {
case V_45 :
break;
case V_46 :
return;
default:
break;
}
if ( ! V_34 ) {
V_35 = F_20 ( V_27 ) ;
goto V_47;
}
#ifdef F_14
for ( V_36 = 0 ; V_36 < V_27 . V_48 -> V_49 ; V_36 ++ ) {
struct V_50 * V_51 = & V_27 . V_48 -> V_50 [ V_36 ] ;
if ( V_51 -> V_52 == V_34 ) {
V_35 = V_51 -> V_52 ;
goto V_47;
}
}
return;
#else
V_35 = F_20 ( V_27 ) ;
if ( V_35 != V_34 )
return;
#endif
V_47:
switch ( V_9 -> V_53 ) {
case V_54 :
* V_25 = V_35 -> V_24 ;
break;
case V_55 :
strncpy ( ( char * ) V_25 , V_35 -> V_56 , V_57 ) ;
break;
default:
F_21 ( 1 ) ;
break;
}
}
static const struct V_58 *
F_22 ( const struct V_59 * V_60 ,
const struct V_61 * const V_62 [] )
{
enum V_63 V_53 ;
if ( ! V_62 [ V_64 ] )
return F_23 ( - V_65 ) ;
V_53 = F_24 ( F_25 ( V_62 [ V_64 ] ) ) ;
switch ( V_53 ) {
case V_54 :
return & V_66 ;
case V_55 :
return & V_66 ;
case V_67 :
return & V_68 ;
default:
return F_23 ( - V_69 ) ;
}
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_70 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_70 ) ;
}
