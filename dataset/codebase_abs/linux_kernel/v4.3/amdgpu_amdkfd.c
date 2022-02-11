bool F_1 ( void )
{
#if F_2 ( V_1 )
bool (* F_3)( unsigned , const struct V_2 * * );
F_3 = F_4 ( V_3 ) ;
if ( F_3 == NULL )
return false ;
#endif
return true ;
}
bool F_5 ( struct V_4 * V_5 )
{
#if F_2 ( V_1 )
bool (* F_3)( unsigned , const struct V_2 * * );
#endif
switch ( V_5 -> V_6 ) {
#ifdef F_6
case V_7 :
V_8 = F_7 () ;
break;
#endif
case V_9 :
V_8 = F_8 () ;
break;
default:
return false ;
}
#if F_2 ( V_1 )
F_3 = F_4 ( V_3 ) ;
if ( F_3 == NULL ) {
V_8 = NULL ;
return false ;
}
if ( ! F_3 ( V_10 , & V_11 ) ) {
F_9 ( V_3 ) ;
V_8 = NULL ;
V_11 = NULL ;
return false ;
}
return true ;
#elif F_2 ( V_12 )
if ( ! V_3 ( V_10 , & V_11 ) ) {
V_8 = NULL ;
V_11 = NULL ;
return false ;
}
return true ;
#else
V_8 = NULL ;
return false ;
#endif
}
void F_10 ( void )
{
if ( V_11 ) {
V_11 -> exit () ;
F_9 ( V_3 ) ;
}
}
void F_11 ( struct V_4 * V_5 )
{
if ( V_11 )
V_5 -> V_13 = V_11 -> V_14 ( (struct V_15 * ) V_5 ,
V_5 -> V_16 , V_8 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 ) {
struct V_17 V_18 = {
. V_19 = 0xFF00 ,
. V_20 = 1 ,
. V_21 = 4 - 1 ,
} ;
F_13 ( V_5 ,
& V_18 . V_22 ,
& V_18 . V_23 ,
& V_18 . V_24 ) ;
V_11 -> V_25 ( V_5 -> V_13 , & V_18 ) ;
}
}
void F_14 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 ) {
V_11 -> V_26 ( V_5 -> V_13 ) ;
V_5 -> V_13 = NULL ;
}
}
void F_15 ( struct V_4 * V_5 ,
const void * V_27 )
{
if ( V_5 -> V_13 )
V_11 -> V_28 ( V_5 -> V_13 , V_27 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 )
V_11 -> V_29 ( V_5 -> V_13 ) ;
}
int F_17 ( struct V_4 * V_5 )
{
int V_30 = 0 ;
if ( V_5 -> V_13 )
V_30 = V_11 -> V_31 ( V_5 -> V_13 ) ;
return V_30 ;
}
T_1 F_18 ( enum V_32 V_33 )
{
switch ( V_33 ) {
case V_34 : return V_35 ;
default: return V_36 ;
}
}
int F_19 ( struct V_15 * V_37 , T_2 V_38 ,
void * * V_39 , T_3 * V_40 ,
void * * V_41 )
{
struct V_4 * V_5 = (struct V_4 * ) V_37 ;
struct V_42 * * V_43 = (struct V_42 * * ) V_39 ;
int V_30 ;
F_20 ( V_37 == NULL ) ;
F_20 ( V_40 == NULL ) ;
F_20 ( V_41 == NULL ) ;
* V_43 = F_21 ( sizeof( struct V_42 ) , V_44 ) ;
if ( ( * V_43 ) == NULL )
return - V_45 ;
V_30 = F_22 ( V_5 , V_38 , V_46 , true , V_36 ,
V_47 , NULL , NULL , & ( * V_43 ) -> V_48 ) ;
if ( V_30 ) {
F_23 ( V_5 -> V_49 ,
L_1 , V_30 ) ;
return V_30 ;
}
V_30 = F_24 ( ( * V_43 ) -> V_48 , true ) ;
if ( V_30 ) {
F_23 ( V_5 -> V_49 , L_2 , V_30 ) ;
goto V_50;
}
V_30 = F_25 ( ( * V_43 ) -> V_48 , V_36 ,
& ( * V_43 ) -> V_40 ) ;
if ( V_30 ) {
F_23 ( V_5 -> V_49 , L_3 , V_30 ) ;
goto V_51;
}
* V_40 = ( * V_43 ) -> V_40 ;
V_30 = F_26 ( ( * V_43 ) -> V_48 , & ( * V_43 ) -> V_41 ) ;
if ( V_30 ) {
F_23 ( V_5 -> V_49 ,
L_4 , V_30 ) ;
goto V_52;
}
* V_41 = ( * V_43 ) -> V_41 ;
F_27 ( ( * V_43 ) -> V_48 ) ;
return 0 ;
V_52:
F_28 ( ( * V_43 ) -> V_48 ) ;
V_51:
F_27 ( ( * V_43 ) -> V_48 ) ;
V_50:
F_29 ( & ( * V_43 ) -> V_48 ) ;
return V_30 ;
}
void F_30 ( struct V_15 * V_37 , void * V_39 )
{
struct V_42 * V_43 = (struct V_42 * ) V_39 ;
F_20 ( V_43 == NULL ) ;
F_24 ( V_43 -> V_48 , true ) ;
F_31 ( V_43 -> V_48 ) ;
F_28 ( V_43 -> V_48 ) ;
F_27 ( V_43 -> V_48 ) ;
F_29 ( & ( V_43 -> V_48 ) ) ;
F_32 ( V_43 ) ;
}
T_3 F_33 ( struct V_15 * V_37 )
{
struct V_4 * V_5 =
(struct V_4 * ) V_37 ;
F_20 ( V_37 == NULL ) ;
return V_5 -> V_53 . V_54 ;
}
T_3 F_34 ( struct V_15 * V_37 )
{
struct V_4 * V_5 = (struct V_4 * ) V_37 ;
if ( V_5 -> V_55 -> F_34 )
return V_5 -> V_55 -> F_34 ( V_5 ) ;
return 0 ;
}
T_4 F_35 ( struct V_15 * V_37 )
{
struct V_4 * V_5 = (struct V_4 * ) V_37 ;
return V_5 -> V_56 . V_57 . V_58 . V_59 . V_60 / 100 ;
}
