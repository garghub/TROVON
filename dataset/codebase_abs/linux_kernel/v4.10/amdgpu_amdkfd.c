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
int F_18 ( struct V_17 * V_34 , T_1 V_35 ,
void * * V_36 , T_2 * V_37 ,
void * * V_38 )
{
struct V_9 * V_10 = (struct V_9 * ) V_34 ;
struct V_39 * * V_40 = (struct V_39 * * ) V_36 ;
int V_32 ;
F_19 ( V_34 == NULL ) ;
F_19 ( V_37 == NULL ) ;
F_19 ( V_38 == NULL ) ;
* V_40 = F_20 ( sizeof( struct V_39 ) , V_41 ) ;
if ( ( * V_40 ) == NULL )
return - V_42 ;
V_32 = F_21 ( V_10 , V_35 , V_43 , true , V_44 ,
V_45 , NULL , NULL , & ( * V_40 ) -> V_46 ) ;
if ( V_32 ) {
F_22 ( V_10 -> V_47 ,
L_1 , V_32 ) ;
return V_32 ;
}
V_32 = F_23 ( ( * V_40 ) -> V_46 , true ) ;
if ( V_32 ) {
F_22 ( V_10 -> V_47 , L_2 , V_32 ) ;
goto V_48;
}
V_32 = F_24 ( ( * V_40 ) -> V_46 , V_44 ,
& ( * V_40 ) -> V_37 ) ;
if ( V_32 ) {
F_22 ( V_10 -> V_47 , L_3 , V_32 ) ;
goto V_49;
}
* V_37 = ( * V_40 ) -> V_37 ;
V_32 = F_25 ( ( * V_40 ) -> V_46 , & ( * V_40 ) -> V_38 ) ;
if ( V_32 ) {
F_22 ( V_10 -> V_47 ,
L_4 , V_32 ) ;
goto V_50;
}
* V_38 = ( * V_40 ) -> V_38 ;
F_26 ( ( * V_40 ) -> V_46 ) ;
return 0 ;
V_50:
F_27 ( ( * V_40 ) -> V_46 ) ;
V_49:
F_26 ( ( * V_40 ) -> V_46 ) ;
V_48:
F_28 ( & ( * V_40 ) -> V_46 ) ;
return V_32 ;
}
void F_29 ( struct V_17 * V_34 , void * V_36 )
{
struct V_39 * V_40 = (struct V_39 * ) V_36 ;
F_19 ( V_40 == NULL ) ;
F_23 ( V_40 -> V_46 , true ) ;
F_30 ( V_40 -> V_46 ) ;
F_27 ( V_40 -> V_46 ) ;
F_26 ( V_40 -> V_46 ) ;
F_28 ( & ( V_40 -> V_46 ) ) ;
F_31 ( V_40 ) ;
}
T_2 F_32 ( struct V_17 * V_34 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_34 ;
F_19 ( V_34 == NULL ) ;
return V_10 -> V_51 . V_52 ;
}
T_2 F_33 ( struct V_17 * V_34 )
{
struct V_9 * V_10 = (struct V_9 * ) V_34 ;
if ( V_10 -> V_53 . V_54 -> F_33 )
return V_10 -> V_53 . V_54 -> F_33 ( V_10 ) ;
return 0 ;
}
T_3 F_34 ( struct V_17 * V_34 )
{
struct V_9 * V_10 = (struct V_9 * ) V_34 ;
return V_10 -> V_55 . V_56 . V_57 . V_58 . V_59 / 100 ;
}
