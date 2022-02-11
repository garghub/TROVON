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
int V_19 ;
int V_20 ;
if ( V_10 -> V_15 ) {
struct V_21 V_22 = {
. V_23 = 0xFF00 ,
. V_24 = V_10 -> V_25 . V_26 . V_24 ,
. V_27 = V_10 -> V_25 . V_26 . V_27
} ;
F_13 ( V_22 . V_28 ,
V_10 -> V_25 . V_26 . V_28 ,
V_29 ) ;
if ( V_10 -> V_25 . V_30 . V_31 . V_32 )
F_14 ( F_15 ( V_10 ,
V_10 -> V_25 . V_30 . V_31 . V_33 - 1 ,
V_10 -> V_25 . V_30 . V_31 . V_34 ,
V_10 -> V_25 . V_30 . V_31 . V_35 ) ,
V_22 . V_28 ) ;
V_20 = 1
* V_10 -> V_25 . V_26 . V_24
* V_10 -> V_25 . V_26 . V_27 ;
for ( V_19 = V_20 ; V_19 < V_29 ; ++ V_19 )
F_14 ( V_19 , V_22 . V_28 ) ;
F_16 ( V_10 ,
& V_22 . V_36 ,
& V_22 . V_37 ,
& V_22 . V_38 ) ;
V_7 -> V_39 ( V_10 -> V_15 , & V_22 ) ;
}
}
void F_17 ( struct V_9 * V_10 )
{
if ( V_10 -> V_15 ) {
V_7 -> V_40 ( V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
}
}
void F_18 ( struct V_9 * V_10 ,
const void * V_41 )
{
if ( V_10 -> V_15 )
V_7 -> V_42 ( V_10 -> V_15 , V_41 ) ;
}
void F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_15 )
V_7 -> V_43 ( V_10 -> V_15 ) ;
}
int F_20 ( struct V_9 * V_10 )
{
int V_44 = 0 ;
if ( V_10 -> V_15 )
V_44 = V_7 -> V_45 ( V_10 -> V_15 ) ;
return V_44 ;
}
int F_21 ( struct V_17 * V_46 , T_1 V_47 ,
void * * V_48 , T_2 * V_49 ,
void * * V_50 )
{
struct V_9 * V_10 = (struct V_9 * ) V_46 ;
struct V_51 * * V_52 = (struct V_51 * * ) V_48 ;
int V_44 ;
F_22 ( V_46 == NULL ) ;
F_22 ( V_49 == NULL ) ;
F_22 ( V_50 == NULL ) ;
* V_52 = F_23 ( sizeof( struct V_51 ) , V_53 ) ;
if ( ( * V_52 ) == NULL )
return - V_54 ;
V_44 = F_24 ( V_10 , V_47 , V_55 , true , V_56 ,
V_57 , NULL , NULL , & ( * V_52 ) -> V_58 ) ;
if ( V_44 ) {
F_25 ( V_10 -> V_59 ,
L_1 , V_44 ) ;
return V_44 ;
}
V_44 = F_26 ( ( * V_52 ) -> V_58 , true ) ;
if ( V_44 ) {
F_25 ( V_10 -> V_59 , L_2 , V_44 ) ;
goto V_60;
}
V_44 = F_27 ( ( * V_52 ) -> V_58 , V_56 ,
& ( * V_52 ) -> V_49 ) ;
if ( V_44 ) {
F_25 ( V_10 -> V_59 , L_3 , V_44 ) ;
goto V_61;
}
* V_49 = ( * V_52 ) -> V_49 ;
V_44 = F_28 ( ( * V_52 ) -> V_58 , & ( * V_52 ) -> V_50 ) ;
if ( V_44 ) {
F_25 ( V_10 -> V_59 ,
L_4 , V_44 ) ;
goto V_62;
}
* V_50 = ( * V_52 ) -> V_50 ;
F_29 ( ( * V_52 ) -> V_58 ) ;
return 0 ;
V_62:
F_30 ( ( * V_52 ) -> V_58 ) ;
V_61:
F_29 ( ( * V_52 ) -> V_58 ) ;
V_60:
F_31 ( & ( * V_52 ) -> V_58 ) ;
return V_44 ;
}
void F_32 ( struct V_17 * V_46 , void * V_48 )
{
struct V_51 * V_52 = (struct V_51 * ) V_48 ;
F_22 ( V_52 == NULL ) ;
F_26 ( V_52 -> V_58 , true ) ;
F_33 ( V_52 -> V_58 ) ;
F_30 ( V_52 -> V_58 ) ;
F_29 ( V_52 -> V_58 ) ;
F_31 ( & ( V_52 -> V_58 ) ) ;
F_34 ( V_52 ) ;
}
T_2 F_35 ( struct V_17 * V_46 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_46 ;
F_22 ( V_46 == NULL ) ;
return V_10 -> V_63 . V_64 ;
}
T_2 F_36 ( struct V_17 * V_46 )
{
struct V_9 * V_10 = (struct V_9 * ) V_46 ;
if ( V_10 -> V_25 . V_65 -> F_36 )
return V_10 -> V_25 . V_65 -> F_36 ( V_10 ) ;
return 0 ;
}
T_3 F_37 ( struct V_17 * V_46 )
{
struct V_9 * V_10 = (struct V_9 * ) V_46 ;
return V_10 -> V_66 . V_67 . V_68 . V_69 . V_70 / 100 ;
}
