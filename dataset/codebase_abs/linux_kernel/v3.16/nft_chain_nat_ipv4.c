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
if ( V_13 == NULL )
return V_20 ;
switch ( V_9 ) {
case V_24 :
case V_24 + V_25 :
if ( F_7 ( V_4 ) -> V_26 == V_27 ) {
if ( ! F_10 ( V_4 , V_11 , V_9 ,
V_2 -> V_16 ) )
return V_28 ;
else
return V_20 ;
}
case V_29 :
if ( F_11 ( V_11 , V_15 ) )
break;
F_12 ( & V_18 , V_2 , V_4 , V_6 , V_7 ) ;
V_19 = F_13 ( & V_18 , V_2 ) ;
if ( V_19 != V_20 )
return V_19 ;
if ( ! F_11 ( V_11 , V_15 ) ) {
V_19 = F_14 ( V_11 , V_2 -> V_16 ) ;
if ( V_19 != V_20 )
return V_19 ;
}
default:
break;
}
return F_15 ( V_11 , V_9 , V_2 -> V_16 , V_4 ) ;
}
static unsigned int F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
T_1 V_30 = F_7 ( V_4 ) -> V_30 ;
unsigned int V_19 ;
V_19 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
if ( V_19 != V_28 && V_19 != V_31 &&
F_7 ( V_4 ) -> V_30 != V_30 ) {
F_17 ( V_4 ) ;
}
return V_19 ;
}
static unsigned int F_18 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
enum V_8 V_9 V_32 ;
const struct V_10 * V_11 V_32 ;
unsigned int V_19 ;
V_19 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
#ifdef F_19
if ( V_19 != V_28 && V_19 != V_31 &&
( V_11 = F_3 ( V_4 , & V_9 ) ) != NULL ) {
enum V_33 V_34 = F_20 ( V_9 ) ;
if ( V_11 -> V_35 [ V_34 ] . V_36 . V_37 . V_38 . V_39 !=
V_11 -> V_35 [ ! V_34 ] . V_36 . V_40 . V_38 . V_39 ||
V_11 -> V_35 [ V_34 ] . V_36 . V_37 . V_41 . V_42 !=
V_11 -> V_35 [ ! V_34 ] . V_36 . V_40 . V_41 . V_42 )
return F_21 ( V_4 , V_43 ) == 0 ?
V_19 : V_28 ;
}
#endif
return V_19 ;
}
static unsigned int F_22 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
enum V_8 V_9 ;
const struct V_10 * V_11 ;
unsigned int V_19 ;
V_19 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
if ( V_19 != V_28 && V_19 != V_31 &&
( V_11 = F_3 ( V_4 , & V_9 ) ) != NULL ) {
enum V_33 V_34 = F_20 ( V_9 ) ;
if ( V_11 -> V_35 [ V_34 ] . V_36 . V_40 . V_38 . V_39 !=
V_11 -> V_35 [ ! V_34 ] . V_36 . V_37 . V_38 . V_39 ) {
if ( F_23 ( V_4 , V_44 ) )
V_19 = V_28 ;
}
#ifdef F_19
else if ( V_11 -> V_35 [ V_34 ] . V_36 . V_40 . V_41 . V_42 !=
V_11 -> V_35 [ ! V_34 ] . V_36 . V_37 . V_41 . V_42 )
if ( F_21 ( V_4 , V_43 ) )
V_19 = V_28 ;
#endif
}
return V_19 ;
}
static int T_2 F_24 ( void )
{
int V_45 ;
V_45 = F_25 ( & V_46 ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_46 ) ;
}
