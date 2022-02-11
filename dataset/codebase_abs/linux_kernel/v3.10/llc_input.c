void F_1 ( int type , void (* F_2)( struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
F_3 () ;
if ( type == V_5 || type == V_6 )
V_7 [ type - 1 ] = F_2 ;
}
void F_4 ( int type )
{
if ( type == V_5 || type == V_6 )
V_7 [ type - 1 ] = NULL ;
F_5 () ;
}
void F_6 ( void (* F_2)( struct V_3 * V_4 ) )
{
if ( F_2 )
F_3 () ;
V_8 = F_2 ;
if ( ! F_2 )
F_5 () ;
}
static T_1 int F_7 ( struct V_3 * V_4 )
{
int type = V_6 ;
struct V_9 * V_10 = F_8 ( V_4 ) ;
if ( ( V_10 -> V_11 & V_12 ) != V_13 )
goto V_14;
switch ( F_9 ( V_10 ) ) {
case V_15 :
case V_16 :
case V_17 :
type = V_5 ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
break;
default:
type = V_23 ;
break;
}
V_14:
return type ;
}
static inline int F_10 ( struct V_3 * V_4 )
{
T_2 V_24 = 2 ;
struct V_25 * V_10 ;
if ( F_11 ( ! F_12 ( V_4 , sizeof( * V_10 ) ) ) )
return 0 ;
V_10 = (struct V_25 * ) V_4 -> V_26 ;
if ( ( V_10 -> V_11 & V_12 ) == V_13 )
V_24 = 1 ;
V_24 += 2 ;
if ( F_11 ( ! F_12 ( V_4 , V_24 ) ) )
return 0 ;
V_4 -> V_27 += V_24 ;
F_13 ( V_4 , V_24 ) ;
if ( V_4 -> V_28 == F_14 ( V_29 ) ) {
T_3 V_30 = F_15 ( V_4 ) -> V_31 ;
T_4 V_32 = F_16 ( V_30 ) - V_24 ;
if ( V_32 < 0 ||
! F_12 ( V_4 , V_32 ) )
return 0 ;
if ( F_11 ( F_17 ( V_4 , V_32 ) ) )
return 0 ;
}
return 1 ;
}
int F_18 ( struct V_3 * V_4 , struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_33 * V_37 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_38 ;
int (* F_19)( struct V_3 * , struct V_33 * ,
struct V_35 * , struct V_33 * );
void (* F_20)( struct V_3 * V_4 );
void (* F_21)( struct V_1 * V_2 , struct V_3 * V_4 );
if ( ! F_22 ( F_23 ( V_34 ) , & V_39 ) )
goto V_40;
if ( F_11 ( V_4 -> V_41 == V_42 ) ) {
F_24 ( L_1 , V_43 ) ;
goto V_40;
}
V_4 = F_25 ( V_4 , V_44 ) ;
if ( F_11 ( ! V_4 ) )
goto V_14;
if ( F_11 ( ! F_10 ( V_4 ) ) )
goto V_40;
V_10 = F_8 ( V_4 ) ;
if ( F_11 ( ! V_10 -> V_45 ) )
goto V_46;
V_2 = F_26 ( V_10 -> V_45 ) ;
if ( F_11 ( ! V_2 ) ) {
F_24 ( L_2 , V_43 ,
V_10 -> V_45 ) ;
goto V_40;
}
F_19 = F_27 ( V_2 -> V_47 ) ;
V_38 = F_7 ( V_4 ) ;
F_21 = V_38 ? F_28 ( V_7 [ V_38 - 1 ] ) : NULL ;
if ( F_11 ( ! F_21 ) ) {
if ( F_19 )
F_19 ( V_4 , V_34 , V_36 , V_37 ) ;
else
F_29 ( V_4 ) ;
} else {
if ( F_19 ) {
struct V_3 * V_48 = F_30 ( V_4 , V_44 ) ;
if ( V_48 )
F_19 ( V_48 , V_34 , V_36 , V_37 ) ;
}
F_21 ( V_2 , V_4 ) ;
}
F_31 ( V_2 ) ;
V_14:
return 0 ;
V_40:
F_29 ( V_4 ) ;
goto V_14;
V_46:
F_20 = F_28 ( V_8 ) ;
if ( ! F_20 )
goto V_40;
F_20 ( V_4 ) ;
goto V_14;
}
