void F_1 ( int type , void (* F_2)( struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
if ( type == V_5 || type == V_6 )
V_7 [ type - 1 ] = F_2 ;
}
void F_3 ( int type )
{
if ( type == V_5 || type == V_6 )
V_7 [ type - 1 ] = NULL ;
}
void F_4 ( void (* F_2)( struct V_3 * V_4 ) )
{
V_8 = F_2 ;
}
static T_1 int F_5 ( struct V_3 * V_4 )
{
int type = V_6 ;
struct V_9 * V_10 = F_6 ( V_4 ) ;
if ( ( V_10 -> V_11 & V_12 ) != V_13 )
goto V_14;
switch ( F_7 ( V_10 ) ) {
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
static inline int F_8 ( struct V_3 * V_4 )
{
T_2 V_24 = 2 ;
struct V_25 * V_10 ;
if ( F_9 ( ! F_10 ( V_4 , sizeof( * V_10 ) ) ) )
return 0 ;
V_10 = (struct V_25 * ) V_4 -> V_26 ;
if ( ( V_10 -> V_11 & V_12 ) == V_13 )
V_24 = 1 ;
V_24 += 2 ;
if ( F_9 ( ! F_10 ( V_4 , V_24 ) ) )
return 0 ;
V_4 -> V_27 += V_24 ;
F_11 ( V_4 , V_24 ) ;
if ( V_4 -> V_28 == F_12 ( V_29 ) ) {
T_3 V_30 = F_13 ( V_4 ) -> V_31 ;
T_4 V_32 = F_14 ( V_30 ) - V_24 ;
if ( V_32 < 0 ||
! F_10 ( V_4 , V_32 ) )
return 0 ;
if ( F_9 ( F_15 ( V_4 , V_32 ) ) )
return 0 ;
}
return 1 ;
}
int F_16 ( struct V_3 * V_4 , struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_33 * V_37 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_38 ;
int (* F_17)( struct V_3 * , struct V_33 * ,
struct V_35 * , struct V_33 * );
if ( ! F_18 ( F_19 ( V_34 ) , & V_39 ) )
goto V_40;
if ( F_9 ( V_4 -> V_41 == V_42 ) ) {
F_20 ( L_1 , V_43 ) ;
goto V_40;
}
V_4 = F_21 ( V_4 , V_44 ) ;
if ( F_9 ( ! V_4 ) )
goto V_14;
if ( F_9 ( ! F_8 ( V_4 ) ) )
goto V_40;
V_10 = F_6 ( V_4 ) ;
if ( F_9 ( ! V_10 -> V_45 ) )
goto V_46;
V_2 = F_22 ( V_10 -> V_45 ) ;
if ( F_9 ( ! V_2 ) ) {
F_20 ( L_2 , V_43 ,
V_10 -> V_45 ) ;
goto V_40;
}
F_17 = F_23 ( V_2 -> V_47 ) ;
V_38 = F_5 ( V_4 ) ;
if ( F_9 ( ! V_38 || ! V_7 [ V_38 - 1 ] ) ) {
if ( F_17 )
F_17 ( V_4 , V_34 , V_36 , V_37 ) ;
else
F_24 ( V_4 ) ;
} else {
if ( F_17 ) {
struct V_3 * V_48 = F_25 ( V_4 , V_44 ) ;
if ( V_48 )
F_17 ( V_48 , V_34 , V_36 , V_37 ) ;
}
V_7 [ V_38 - 1 ] ( V_2 , V_4 ) ;
}
F_26 ( V_2 ) ;
V_14:
return 0 ;
V_40:
F_24 ( V_4 ) ;
goto V_14;
V_46:
if ( ! V_8 )
goto V_40;
V_8 ( V_4 ) ;
goto V_14;
}
