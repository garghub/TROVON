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
int V_10 = F_7 ( V_7 -> V_11 ) ;
T_2 * V_12 = & V_5 -> V_13 [ V_9 -> V_14 ] ;
const struct V_15 * V_16 = NULL ;
struct V_17 * V_18 , V_19 ;
T_1 V_1 ;
if ( V_9 -> V_20 & V_21 )
V_16 = F_8 ( V_7 ) ;
else if ( V_9 -> V_20 & V_22 )
V_16 = F_9 ( V_7 ) ;
V_18 = F_10 ( V_7 -> V_11 , V_10 , sizeof( V_19 ) , & V_19 ) ;
if ( ! V_18 ) {
V_5 -> V_23 . V_24 = V_25 ;
return;
}
if ( V_9 -> V_20 & V_26 )
V_1 = V_18 -> V_27 ;
else
V_1 = V_18 -> V_28 ;
* V_12 = F_11 ( F_12 ( V_7 ) , V_16 , V_1 ) ;
}
static int F_13 ( const struct V_15 * V_16 )
{
return V_16 ? V_16 -> V_29 : 0 ;
}
void F_14 ( const struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_6 ( V_3 ) ;
int V_10 = F_7 ( V_7 -> V_11 ) ;
T_2 * V_30 = & V_5 -> V_13 [ V_9 -> V_14 ] ;
struct V_17 * V_18 , V_19 ;
struct V_31 V_32 ;
struct V_33 V_34 = {
. V_35 = V_36 ,
. V_37 = V_38 ,
} ;
const struct V_15 * V_39 ;
struct V_15 * V_40 ;
#ifdef F_15
int V_41 ;
#endif
if ( V_9 -> V_20 & V_22 )
V_39 = F_9 ( V_7 ) ;
else if ( V_9 -> V_20 & V_21 )
V_39 = F_8 ( V_7 ) ;
else
V_39 = NULL ;
if ( F_16 ( V_7 ) == V_42 &&
F_17 ( V_7 -> V_11 , F_8 ( V_7 ) ) ) {
F_18 ( V_30 , V_9 , V_7 ,
F_8 ( V_7 ) -> V_29 ) ;
return;
}
V_18 = F_10 ( V_7 -> V_11 , V_10 , sizeof( V_19 ) , & V_19 ) ;
if ( ! V_18 ) {
V_5 -> V_23 . V_24 = V_25 ;
return;
}
if ( F_4 ( V_18 -> V_28 ) ) {
if ( F_3 ( V_18 -> V_27 ) ||
F_19 ( V_18 -> V_27 ) ) {
F_18 ( V_30 , V_9 , V_7 ,
F_13 ( V_7 -> V_11 -> V_16 ) ) ;
return;
}
}
if ( V_9 -> V_20 & V_43 )
V_34 . V_44 = V_7 -> V_11 -> V_45 ;
V_34 . V_46 = V_18 -> V_47 & V_48 ;
if ( V_9 -> V_20 & V_26 ) {
V_34 . V_27 = V_18 -> V_27 ;
V_34 . V_28 = F_1 ( V_18 -> V_28 ) ;
} else {
V_34 . V_27 = V_18 -> V_28 ;
V_34 . V_28 = F_1 ( V_18 -> V_27 ) ;
}
* V_30 = 0 ;
if ( F_20 ( F_12 ( V_7 ) , & V_34 , & V_32 , V_49 ) )
return;
switch ( V_32 . type ) {
case V_50 :
break;
case V_51 :
return;
default:
break;
}
if ( ! V_39 ) {
V_40 = F_21 ( V_32 ) ;
goto V_52;
}
#ifdef F_15
for ( V_41 = 0 ; V_41 < V_32 . V_53 -> V_54 ; V_41 ++ ) {
struct V_55 * V_56 = & V_32 . V_53 -> V_55 [ V_41 ] ;
if ( V_56 -> V_57 == V_39 ) {
V_40 = V_56 -> V_57 ;
goto V_52;
}
}
return;
#else
V_40 = F_21 ( V_32 ) ;
if ( V_40 != V_39 )
return;
#endif
V_52:
switch ( V_9 -> V_58 ) {
case V_59 :
* V_30 = V_40 -> V_29 ;
break;
case V_60 :
strncpy ( ( char * ) V_30 , V_40 -> V_61 , V_62 ) ;
break;
default:
F_22 ( 1 ) ;
break;
}
}
static const struct V_63 *
F_23 ( const struct V_64 * V_65 ,
const struct V_66 * const V_67 [] )
{
enum V_68 V_58 ;
if ( ! V_67 [ V_69 ] )
return F_24 ( - V_70 ) ;
V_58 = F_25 ( F_26 ( V_67 [ V_69 ] ) ) ;
switch ( V_58 ) {
case V_59 :
return & V_71 ;
case V_60 :
return & V_71 ;
case V_72 :
return & V_73 ;
default:
return F_24 ( - V_74 ) ;
}
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_75 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_75 ) ;
}
