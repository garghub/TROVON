static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
enum V_8 V_9 ;
struct V_10 * V_11 = F_3 ( V_4 , & V_9 ) ;
struct V_12 * V_13 ;
enum V_14 V_15 = F_4 ( V_2 -> V_16 ) ;
struct V_17 V_18 ;
unsigned int V_19 ;
if ( V_11 == NULL || F_5 ( V_11 ) )
return V_20 ;
F_6 ( ! ( F_7 ( V_4 ) -> V_21 & F_8 ( V_22 | V_23 ) ) ) ;
V_13 = F_9 ( V_11 ) ;
if ( V_13 == NULL ) {
if ( F_10 ( V_11 ) )
return V_20 ;
V_13 = F_11 ( V_11 , V_24 , V_25 ) ;
if ( V_13 == NULL )
return V_20 ;
}
switch ( V_9 ) {
case V_26 :
case V_26 + V_27 :
if ( F_7 ( V_4 ) -> V_28 == V_29 ) {
if ( ! F_12 ( V_4 , V_11 , V_9 ,
V_2 -> V_16 ) )
return V_30 ;
else
return V_20 ;
}
case V_31 :
if ( F_13 ( V_11 , V_15 ) )
break;
F_14 ( & V_18 , V_2 , V_4 , V_6 , V_7 ) ;
V_19 = F_15 ( & V_18 , V_2 ) ;
if ( V_19 != V_20 )
return V_19 ;
if ( ! F_13 ( V_11 , V_15 ) ) {
V_19 = F_16 ( V_11 , V_2 -> V_16 ) ;
if ( V_19 != V_20 )
return V_19 ;
}
default:
break;
}
return F_17 ( V_11 , V_9 , V_2 -> V_16 , V_4 ) ;
}
static unsigned int F_18 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
T_1 V_32 = F_7 ( V_4 ) -> V_32 ;
unsigned int V_19 ;
V_19 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
if ( V_19 != V_30 && V_19 != V_33 &&
F_7 ( V_4 ) -> V_32 != V_32 ) {
F_19 ( V_4 ) ;
}
return V_19 ;
}
static unsigned int F_20 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
enum V_8 V_9 V_34 ;
const struct V_10 * V_11 V_34 ;
unsigned int V_19 ;
V_19 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
#ifdef F_21
if ( V_19 != V_30 && V_19 != V_33 &&
( V_11 = F_3 ( V_4 , & V_9 ) ) != NULL ) {
enum V_35 V_36 = F_22 ( V_9 ) ;
if ( V_11 -> V_37 [ V_36 ] . V_38 . V_39 . V_40 . V_41 !=
V_11 -> V_37 [ ! V_36 ] . V_38 . V_42 . V_40 . V_41 ||
V_11 -> V_37 [ V_36 ] . V_38 . V_39 . V_43 . V_44 !=
V_11 -> V_37 [ ! V_36 ] . V_38 . V_42 . V_43 . V_44 )
return F_23 ( V_4 , V_45 ) == 0 ?
V_19 : V_30 ;
}
#endif
return V_19 ;
}
static unsigned int F_24 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
enum V_8 V_9 ;
const struct V_10 * V_11 ;
unsigned int V_19 ;
V_19 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
if ( V_19 != V_30 && V_19 != V_33 &&
( V_11 = F_3 ( V_4 , & V_9 ) ) != NULL ) {
enum V_35 V_36 = F_22 ( V_9 ) ;
if ( V_11 -> V_37 [ V_36 ] . V_38 . V_42 . V_40 . V_41 !=
V_11 -> V_37 [ ! V_36 ] . V_38 . V_39 . V_40 . V_41 ) {
if ( F_25 ( V_4 , V_46 ) )
V_19 = V_30 ;
}
#ifdef F_21
else if ( V_11 -> V_37 [ V_36 ] . V_38 . V_42 . V_43 . V_44 !=
V_11 -> V_37 [ ! V_36 ] . V_38 . V_39 . V_43 . V_44 )
if ( F_23 ( V_4 , V_45 ) )
V_19 = V_30 ;
#endif
}
return V_19 ;
}
static int T_2 F_26 ( void )
{
int V_47 ;
V_47 = F_27 ( & V_48 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_48 ) ;
}
