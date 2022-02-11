static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_3 ( & V_4 [ V_9 -> V_11 ] , & V_9 -> V_4 , V_9 -> V_12 ) ;
switch ( V_9 -> V_13 ) {
case V_14 :
if ( V_10 != 0 )
goto V_15;
break;
case V_16 :
if ( V_10 == 0 )
goto V_15;
break;
case V_17 :
if ( V_10 == 0 )
goto V_15;
case V_18 :
if ( V_10 > 0 )
goto V_15;
break;
case V_19 :
if ( V_10 == 0 )
goto V_15;
case V_20 :
if ( V_10 < 0 )
goto V_15;
break;
}
return;
V_15:
V_4 [ V_21 ] . V_22 = V_23 ;
}
static int F_4 ( const struct V_24 * V_25 , const struct V_1 * V_2 ,
const struct V_26 * const V_27 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_28 V_29 ;
int V_30 ;
V_9 -> V_11 = F_5 ( F_6 ( V_27 [ V_31 ] ) ) ;
V_9 -> V_13 = F_5 ( F_6 ( V_27 [ V_32 ] ) ) ;
V_30 = F_7 ( NULL , & V_9 -> V_4 , & V_29 , V_27 [ V_33 ] ) ;
F_8 ( V_30 < 0 ) ;
V_9 -> V_12 = V_29 . V_12 ;
return 0 ;
}
static int F_9 ( struct V_34 * V_35 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_10 ( V_35 , V_31 , F_11 ( V_9 -> V_11 ) ) )
goto V_36;
if ( F_10 ( V_35 , V_32 , F_11 ( V_9 -> V_13 ) ) )
goto V_36;
if ( F_12 ( V_35 , V_33 , & V_9 -> V_4 ,
V_37 , V_9 -> V_12 ) < 0 )
goto V_36;
return 0 ;
V_36:
return - 1 ;
}
static int F_13 ( const struct V_24 * V_25 ,
const struct V_1 * V_2 ,
const struct V_26 * const V_27 [] )
{
struct V_38 * V_9 = F_2 ( V_2 ) ;
struct V_28 V_29 ;
struct V_3 V_4 ;
T_1 V_39 ;
int V_30 ;
V_9 -> V_11 = F_5 ( F_6 ( V_27 [ V_31 ] ) ) ;
V_30 = F_7 ( NULL , & V_4 , & V_29 , V_27 [ V_33 ] ) ;
F_8 ( V_30 < 0 ) ;
V_29 . V_12 *= V_40 ;
V_39 = ~ 0U >> ( sizeof( V_9 -> V_4 ) * V_40 - V_29 . V_12 ) ;
V_9 -> V_4 = V_4 . V_4 [ 0 ] & V_39 ;
V_9 -> V_12 = V_29 . V_12 ;
return 0 ;
}
static int F_14 ( struct V_34 * V_35 , const struct V_1 * V_2 )
{
const struct V_38 * V_9 = F_2 ( V_2 ) ;
struct V_3 V_4 ;
if ( F_10 ( V_35 , V_31 , F_11 ( V_9 -> V_11 ) ) )
goto V_36;
if ( F_10 ( V_35 , V_32 , F_11 ( V_14 ) ) )
goto V_36;
V_4 . V_4 [ 0 ] = V_9 -> V_4 ;
if ( F_12 ( V_35 , V_33 , & V_4 ,
V_37 , V_9 -> V_12 / V_40 ) < 0 )
goto V_36;
return 0 ;
V_36:
return - 1 ;
}
static const struct V_41 *
F_15 ( const struct V_24 * V_25 , const struct V_26 * const V_27 [] )
{
struct V_28 V_29 ;
struct V_3 V_4 ;
enum V_42 V_11 ;
enum V_43 V_13 ;
int V_30 ;
if ( V_27 [ V_31 ] == NULL ||
V_27 [ V_32 ] == NULL ||
V_27 [ V_33 ] == NULL )
return F_16 ( - V_44 ) ;
V_11 = F_5 ( F_6 ( V_27 [ V_31 ] ) ) ;
V_30 = F_17 ( V_11 ) ;
if ( V_30 < 0 )
return F_16 ( V_30 ) ;
V_13 = F_5 ( F_6 ( V_27 [ V_32 ] ) ) ;
switch ( V_13 ) {
case V_14 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
break;
default:
return F_16 ( - V_44 ) ;
}
V_30 = F_7 ( NULL , & V_4 , & V_29 , V_27 [ V_33 ] ) ;
if ( V_30 < 0 )
return F_16 ( V_30 ) ;
if ( V_29 . V_12 <= sizeof( T_1 ) && V_13 == V_14 )
return & V_45 ;
else
return & V_43 ;
}
int T_2 F_18 ( void )
{
return F_19 ( & V_46 ) ;
}
void F_20 ( void )
{
F_21 ( & V_46 ) ;
}
