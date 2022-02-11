int F_1 ( void )
{
int V_1 ;
#if F_2 ( V_2 )
int (* F_3)( unsigned int , const struct V_3 * * );
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
void F_6 ( void )
{
if ( V_7 ) {
V_7 -> exit () ;
F_5 ( V_4 ) ;
}
}
void F_7 ( struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
if ( ! V_7 )
return;
switch ( V_10 -> V_13 ) {
#ifdef F_8
case V_14 :
V_12 = F_9 () ;
break;
#endif
case V_15 :
V_12 = F_10 () ;
break;
default:
F_11 ( V_10 -> V_16 , L_1 ) ;
return;
}
V_10 -> V_17 = V_7 -> V_18 ( (struct V_19 * ) V_10 ,
V_10 -> V_20 , V_12 ) ;
}
void F_12 ( struct V_9 * V_10 )
{
int V_21 ;
int V_22 ;
if ( V_10 -> V_17 ) {
struct V_23 V_24 = {
. V_25 = 0xFF00 ,
. V_26 = V_10 -> V_27 . V_28 . V_26 ,
. V_29 = V_10 -> V_27 . V_28 . V_29
} ;
F_13 ( V_24 . V_30 ,
V_10 -> V_27 . V_28 . V_30 ,
V_31 ) ;
if ( V_10 -> V_27 . V_32 . V_33 . V_34 )
F_14 ( F_15 ( V_10 ,
V_10 -> V_27 . V_32 . V_33 . V_35 - 1 ,
V_10 -> V_27 . V_32 . V_33 . V_36 ,
V_10 -> V_27 . V_32 . V_33 . V_37 ) ,
V_24 . V_30 ) ;
V_22 = 1
* V_10 -> V_27 . V_28 . V_26
* V_10 -> V_27 . V_28 . V_29 ;
for ( V_21 = V_22 ; V_21 < V_31 ; ++ V_21 )
F_14 ( V_21 , V_24 . V_30 ) ;
F_16 ( V_10 ,
& V_24 . V_38 ,
& V_24 . V_39 ,
& V_24 . V_40 ) ;
V_7 -> V_41 ( V_10 -> V_17 , & V_24 ) ;
}
}
void F_17 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 ) {
V_7 -> V_42 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
void F_18 ( struct V_9 * V_10 ,
const void * V_43 )
{
if ( V_10 -> V_17 )
V_7 -> V_44 ( V_10 -> V_17 , V_43 ) ;
}
void F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 )
V_7 -> V_45 ( V_10 -> V_17 ) ;
}
int F_20 ( struct V_9 * V_10 )
{
int V_46 = 0 ;
if ( V_10 -> V_17 )
V_46 = V_7 -> V_47 ( V_10 -> V_17 ) ;
return V_46 ;
}
int F_21 ( struct V_19 * V_48 , T_1 V_49 ,
void * * V_50 , T_2 * V_51 ,
void * * V_52 )
{
struct V_9 * V_10 = (struct V_9 * ) V_48 ;
struct V_53 * * V_54 = (struct V_53 * * ) V_50 ;
int V_46 ;
F_22 ( V_48 == NULL ) ;
F_22 ( V_51 == NULL ) ;
F_22 ( V_52 == NULL ) ;
* V_54 = F_23 ( sizeof( struct V_53 ) , V_55 ) ;
if ( ( * V_54 ) == NULL )
return - V_56 ;
V_46 = F_24 ( V_10 , V_49 , V_57 , true , V_58 ,
V_59 , NULL , NULL , 0 ,
& ( * V_54 ) -> V_60 ) ;
if ( V_46 ) {
F_25 ( V_10 -> V_16 ,
L_2 , V_46 ) ;
return V_46 ;
}
V_46 = F_26 ( ( * V_54 ) -> V_60 , true ) ;
if ( V_46 ) {
F_25 ( V_10 -> V_16 , L_3 , V_46 ) ;
goto V_61;
}
V_46 = F_27 ( ( * V_54 ) -> V_60 , V_58 ,
& ( * V_54 ) -> V_51 ) ;
if ( V_46 ) {
F_25 ( V_10 -> V_16 , L_4 , V_46 ) ;
goto V_62;
}
* V_51 = ( * V_54 ) -> V_51 ;
V_46 = F_28 ( ( * V_54 ) -> V_60 , & ( * V_54 ) -> V_52 ) ;
if ( V_46 ) {
F_25 ( V_10 -> V_16 ,
L_5 , V_46 ) ;
goto V_63;
}
* V_52 = ( * V_54 ) -> V_52 ;
F_29 ( ( * V_54 ) -> V_60 ) ;
return 0 ;
V_63:
F_30 ( ( * V_54 ) -> V_60 ) ;
V_62:
F_29 ( ( * V_54 ) -> V_60 ) ;
V_61:
F_31 ( & ( * V_54 ) -> V_60 ) ;
return V_46 ;
}
void F_32 ( struct V_19 * V_48 , void * V_50 )
{
struct V_53 * V_54 = (struct V_53 * ) V_50 ;
F_22 ( V_54 == NULL ) ;
F_26 ( V_54 -> V_60 , true ) ;
F_33 ( V_54 -> V_60 ) ;
F_30 ( V_54 -> V_60 ) ;
F_29 ( V_54 -> V_60 ) ;
F_31 ( & ( V_54 -> V_60 ) ) ;
F_34 ( V_54 ) ;
}
T_2 F_35 ( struct V_19 * V_48 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_48 ;
F_22 ( V_48 == NULL ) ;
return V_10 -> V_64 . V_65 ;
}
T_2 F_36 ( struct V_19 * V_48 )
{
struct V_9 * V_10 = (struct V_9 * ) V_48 ;
if ( V_10 -> V_27 . V_66 -> F_36 )
return V_10 -> V_27 . V_66 -> F_36 ( V_10 ) ;
return 0 ;
}
T_3 F_37 ( struct V_19 * V_48 )
{
struct V_9 * V_10 = (struct V_9 * ) V_48 ;
return V_10 -> V_67 . V_68 . V_69 . V_70 . V_71 / 100 ;
}
