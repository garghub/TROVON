int F_1 ( void )
{
int V_1 ;
#if F_2 ( V_2 )
int (* F_3)( unsigned , const struct V_3 * * );
F_3 = F_4 ( V_4 ) ;
if ( F_3 == NULL )
return - V_5 ;
V_1 = F_3 ( V_6 , & V_7 ) ;
if ( V_1 ) {
F_5 ( V_4 ) ;
V_7 = NULL ;
}
#elif F_2 ( V_8 )
V_1 = V_4 ( V_6 , & V_7 ) ;
if ( V_1 )
V_7 = NULL ;
#else
V_1 = - V_5 ;
#endif
return V_1 ;
}
bool F_6 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
#ifdef F_7
case V_12 :
V_13 = F_8 () ;
break;
#endif
case V_14 :
V_13 = F_9 () ;
break;
default:
return false ;
}
return true ;
}
void F_10 ( void )
{
if ( V_7 ) {
V_7 -> exit () ;
F_5 ( V_4 ) ;
}
}
void F_11 ( struct V_9 * V_10 )
{
if ( V_7 )
V_10 -> V_15 = V_7 -> V_16 ( (struct V_17 * ) V_10 ,
V_10 -> V_18 , V_13 ) ;
}
void F_12 ( struct V_9 * V_10 )
{
if ( V_10 -> V_15 ) {
struct V_19 V_20 = {
. V_21 = 0xFF00 ,
. V_22 = 1 ,
. V_23 = 4 - 1 ,
} ;
F_13 ( V_10 ,
& V_20 . V_24 ,
& V_20 . V_25 ,
& V_20 . V_26 ) ;
V_7 -> V_27 ( V_10 -> V_15 , & V_20 ) ;
}
}
void F_14 ( struct V_9 * V_10 )
{
if ( V_10 -> V_15 ) {
V_7 -> V_28 ( V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
}
}
void F_15 ( struct V_9 * V_10 ,
const void * V_29 )
{
if ( V_10 -> V_15 )
V_7 -> V_30 ( V_10 -> V_15 , V_29 ) ;
}
void F_16 ( struct V_9 * V_10 )
{
if ( V_10 -> V_15 )
V_7 -> V_31 ( V_10 -> V_15 ) ;
}
int F_17 ( struct V_9 * V_10 )
{
int V_32 = 0 ;
if ( V_10 -> V_15 )
V_32 = V_7 -> V_33 ( V_10 -> V_15 ) ;
return V_32 ;
}
T_1 F_18 ( enum V_34 V_35 )
{
switch ( V_35 ) {
case V_36 : return V_37 ;
default: return V_38 ;
}
}
int F_19 ( struct V_17 * V_39 , T_2 V_40 ,
void * * V_41 , T_3 * V_42 ,
void * * V_43 )
{
struct V_9 * V_10 = (struct V_9 * ) V_39 ;
struct V_44 * * V_45 = (struct V_44 * * ) V_41 ;
int V_32 ;
F_20 ( V_39 == NULL ) ;
F_20 ( V_42 == NULL ) ;
F_20 ( V_43 == NULL ) ;
* V_45 = F_21 ( sizeof( struct V_44 ) , V_46 ) ;
if ( ( * V_45 ) == NULL )
return - V_47 ;
V_32 = F_22 ( V_10 , V_40 , V_48 , true , V_38 ,
V_49 , NULL , NULL , & ( * V_45 ) -> V_50 ) ;
if ( V_32 ) {
F_23 ( V_10 -> V_51 ,
L_1 , V_32 ) ;
return V_32 ;
}
V_32 = F_24 ( ( * V_45 ) -> V_50 , true ) ;
if ( V_32 ) {
F_23 ( V_10 -> V_51 , L_2 , V_32 ) ;
goto V_52;
}
V_32 = F_25 ( ( * V_45 ) -> V_50 , V_38 ,
& ( * V_45 ) -> V_42 ) ;
if ( V_32 ) {
F_23 ( V_10 -> V_51 , L_3 , V_32 ) ;
goto V_53;
}
* V_42 = ( * V_45 ) -> V_42 ;
V_32 = F_26 ( ( * V_45 ) -> V_50 , & ( * V_45 ) -> V_43 ) ;
if ( V_32 ) {
F_23 ( V_10 -> V_51 ,
L_4 , V_32 ) ;
goto V_54;
}
* V_43 = ( * V_45 ) -> V_43 ;
F_27 ( ( * V_45 ) -> V_50 ) ;
return 0 ;
V_54:
F_28 ( ( * V_45 ) -> V_50 ) ;
V_53:
F_27 ( ( * V_45 ) -> V_50 ) ;
V_52:
F_29 ( & ( * V_45 ) -> V_50 ) ;
return V_32 ;
}
void F_30 ( struct V_17 * V_39 , void * V_41 )
{
struct V_44 * V_45 = (struct V_44 * ) V_41 ;
F_20 ( V_45 == NULL ) ;
F_24 ( V_45 -> V_50 , true ) ;
F_31 ( V_45 -> V_50 ) ;
F_28 ( V_45 -> V_50 ) ;
F_27 ( V_45 -> V_50 ) ;
F_29 ( & ( V_45 -> V_50 ) ) ;
F_32 ( V_45 ) ;
}
T_3 F_33 ( struct V_17 * V_39 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_39 ;
F_20 ( V_39 == NULL ) ;
return V_10 -> V_55 . V_56 ;
}
T_3 F_34 ( struct V_17 * V_39 )
{
struct V_9 * V_10 = (struct V_9 * ) V_39 ;
if ( V_10 -> V_57 . V_58 -> F_34 )
return V_10 -> V_57 . V_58 -> F_34 ( V_10 ) ;
return 0 ;
}
T_4 F_35 ( struct V_17 * V_39 )
{
struct V_9 * V_10 = (struct V_9 * ) V_39 ;
return V_10 -> V_59 . V_60 . V_61 . V_62 . V_63 / 100 ;
}
