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
T_1 V_17 ;
int V_18 ;
T_2 V_19 ;
struct V_20 V_21 ;
unsigned int V_22 ;
if ( V_11 == NULL || F_5 ( V_11 ) )
return V_23 ;
V_13 = F_6 ( V_11 ) ;
if ( V_13 == NULL ) {
if ( F_7 ( V_11 ) )
return V_23 ;
V_13 = F_8 ( V_11 , V_24 , V_25 ) ;
if ( V_13 == NULL )
return V_23 ;
}
switch ( V_9 ) {
case V_26 :
case V_26 + V_27 :
V_19 = F_9 ( V_4 ) -> V_19 ;
V_18 = F_10 ( V_4 , sizeof( struct V_28 ) ,
& V_19 , & V_17 ) ;
if ( V_18 >= 0 && V_19 == V_29 ) {
if ( ! F_11 ( V_4 , V_11 , V_9 ,
V_2 -> V_16 ,
V_18 ) )
return V_30 ;
else
return V_23 ;
}
case V_31 :
if ( F_12 ( V_11 , V_15 ) )
break;
F_13 ( & V_21 , V_2 , V_4 , V_6 , V_7 ) ;
V_22 = F_14 ( & V_21 , V_2 ) ;
if ( V_22 != V_23 )
return V_22 ;
if ( ! F_12 ( V_11 , V_15 ) ) {
V_22 = F_15 ( V_11 , V_2 -> V_16 ) ;
if ( V_22 != V_23 )
return V_22 ;
}
default:
break;
}
return F_16 ( V_11 , V_9 , V_2 -> V_16 , V_4 ) ;
}
static unsigned int F_17 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
struct V_32 V_33 = F_9 ( V_4 ) -> V_33 ;
unsigned int V_22 ;
V_22 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
if ( V_22 != V_30 && V_22 != V_34 &&
F_18 ( & V_33 , & F_9 ( V_4 ) -> V_33 ) )
F_19 ( V_4 ) ;
return V_22 ;
}
static unsigned int F_20 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
enum V_8 V_9 V_35 ;
const struct V_10 * V_11 V_35 ;
unsigned int V_22 ;
V_22 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
#ifdef F_21
if ( V_22 != V_30 && V_22 != V_34 &&
! ( F_22 ( V_4 ) -> V_36 & V_37 ) &&
( V_11 = F_3 ( V_4 , & V_9 ) ) != NULL ) {
enum V_38 V_39 = F_23 ( V_9 ) ;
if ( ! F_24 ( & V_11 -> V_40 [ V_39 ] . V_41 . V_42 . V_43 ,
& V_11 -> V_40 [ ! V_39 ] . V_41 . V_44 . V_43 ) ||
( V_11 -> V_40 [ V_39 ] . V_41 . V_42 . V_45 . V_46 !=
V_11 -> V_40 [ ! V_39 ] . V_41 . V_44 . V_45 . V_46 ) )
if ( F_25 ( V_4 , V_47 ) < 0 )
V_22 = V_30 ;
}
#endif
return V_22 ;
}
static unsigned int F_26 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
enum V_8 V_9 ;
const struct V_10 * V_11 ;
unsigned int V_22 ;
V_22 = F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
if ( V_22 != V_30 && V_22 != V_34 &&
( V_11 = F_3 ( V_4 , & V_9 ) ) != NULL ) {
enum V_38 V_39 = F_23 ( V_9 ) ;
if ( ! F_24 ( & V_11 -> V_40 [ V_39 ] . V_41 . V_44 . V_43 ,
& V_11 -> V_40 [ ! V_39 ] . V_41 . V_42 . V_43 ) ) {
if ( F_27 ( V_4 ) )
V_22 = V_30 ;
}
#ifdef F_21
else if ( ! ( F_22 ( V_4 ) -> V_36 & V_37 ) &&
V_11 -> V_40 [ V_39 ] . V_41 . V_44 . V_45 . V_46 !=
V_11 -> V_40 [ ! V_39 ] . V_41 . V_42 . V_45 . V_46 )
if ( F_25 ( V_4 , V_47 ) )
V_22 = V_30 ;
#endif
}
return V_22 ;
}
static int T_3 F_28 ( void )
{
int V_48 ;
V_48 = F_29 ( & V_49 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_49 ) ;
}
