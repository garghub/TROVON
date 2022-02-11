static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = memcmp ( & V_4 -> V_10 [ V_8 -> V_11 ] , & V_8 -> V_10 , V_8 -> V_12 ) ;
switch ( V_8 -> V_13 ) {
case V_14 :
if ( V_9 != 0 )
goto V_15;
break;
case V_16 :
if ( V_9 == 0 )
goto V_15;
break;
case V_17 :
if ( V_9 == 0 )
goto V_15;
case V_18 :
if ( V_9 > 0 )
goto V_15;
break;
case V_19 :
if ( V_9 == 0 )
goto V_15;
case V_20 :
if ( V_9 < 0 )
goto V_15;
break;
}
return;
V_15:
V_4 -> V_21 . V_22 = V_23 ;
}
static int F_3 ( const struct V_24 * V_25 , const struct V_1 * V_2 ,
const struct V_26 * const V_27 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_28 V_29 ;
int V_30 ;
V_30 = F_4 ( NULL , & V_8 -> V_10 , sizeof( V_8 -> V_10 ) , & V_29 ,
V_27 [ V_31 ] ) ;
F_5 ( V_30 < 0 ) ;
V_8 -> V_11 = F_6 ( V_27 [ V_32 ] ) ;
V_30 = F_7 ( V_8 -> V_11 , V_29 . V_12 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 -> V_13 = F_8 ( F_9 ( V_27 [ V_33 ] ) ) ;
V_8 -> V_12 = V_29 . V_12 ;
return 0 ;
}
static int F_10 ( struct V_34 * V_35 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_11 ( V_35 , V_32 , V_8 -> V_11 ) )
goto V_36;
if ( F_12 ( V_35 , V_33 , F_13 ( V_8 -> V_13 ) ) )
goto V_36;
if ( F_14 ( V_35 , V_31 , & V_8 -> V_10 ,
V_37 , V_8 -> V_12 ) < 0 )
goto V_36;
return 0 ;
V_36:
return - 1 ;
}
static int F_15 ( const struct V_24 * V_25 ,
const struct V_1 * V_2 ,
const struct V_26 * const V_27 [] )
{
struct V_38 * V_8 = F_2 ( V_2 ) ;
struct V_28 V_29 ;
struct V_39 V_10 ;
T_1 V_40 ;
int V_30 ;
V_30 = F_4 ( NULL , & V_10 , sizeof( V_10 ) , & V_29 ,
V_27 [ V_31 ] ) ;
F_5 ( V_30 < 0 ) ;
V_8 -> V_11 = F_6 ( V_27 [ V_32 ] ) ;
V_30 = F_7 ( V_8 -> V_11 , V_29 . V_12 ) ;
if ( V_30 < 0 )
return V_30 ;
V_29 . V_12 *= V_41 ;
V_40 = F_16 ( V_29 . V_12 ) ;
V_8 -> V_10 = V_10 . V_10 [ 0 ] & V_40 ;
V_8 -> V_12 = V_29 . V_12 ;
return 0 ;
}
static int F_17 ( struct V_34 * V_35 , const struct V_1 * V_2 )
{
const struct V_38 * V_8 = F_2 ( V_2 ) ;
struct V_39 V_10 ;
if ( F_11 ( V_35 , V_32 , V_8 -> V_11 ) )
goto V_36;
if ( F_12 ( V_35 , V_33 , F_13 ( V_14 ) ) )
goto V_36;
V_10 . V_10 [ 0 ] = V_8 -> V_10 ;
if ( F_14 ( V_35 , V_31 , & V_10 ,
V_37 , V_8 -> V_12 / V_41 ) < 0 )
goto V_36;
return 0 ;
V_36:
return - 1 ;
}
static const struct V_42 *
F_18 ( const struct V_24 * V_25 , const struct V_26 * const V_27 [] )
{
struct V_28 V_29 ;
struct V_39 V_10 ;
enum V_43 V_13 ;
int V_30 ;
if ( V_27 [ V_32 ] == NULL ||
V_27 [ V_33 ] == NULL ||
V_27 [ V_31 ] == NULL )
return F_19 ( - V_44 ) ;
V_13 = F_8 ( F_9 ( V_27 [ V_33 ] ) ) ;
switch ( V_13 ) {
case V_14 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
break;
default:
return F_19 ( - V_44 ) ;
}
V_30 = F_4 ( NULL , & V_10 , sizeof( V_10 ) , & V_29 ,
V_27 [ V_31 ] ) ;
if ( V_30 < 0 )
return F_19 ( V_30 ) ;
if ( V_29 . V_12 <= sizeof( T_1 ) && V_13 == V_14 )
return & V_45 ;
else
return & V_43 ;
}
int T_2 F_20 ( void )
{
return F_21 ( & V_46 ) ;
}
void F_22 ( void )
{
F_23 ( & V_46 ) ;
}
