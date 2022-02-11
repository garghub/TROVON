int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 == NULL )
return - V_5 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_9 ) ;
F_6 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
if ( V_2 == NULL ) {
if ( F_7 ( ! V_4 -> V_10 [ 0 ] ) )
return - V_5 ;
return 0 ;
}
if ( ! V_4 -> V_10 [ 0 ] )
snprintf ( V_4 -> V_10 , sizeof( V_4 -> V_10 ) , L_1 ,
V_2 -> V_11 -> V_10 , F_8 ( V_2 ) ) ;
if ( ! F_9 ( V_2 ) )
F_10 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_12 * V_9 )
{
struct V_3 * V_4 =
F_12 ( V_9 , struct V_3 , V_9 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_4 ) ;
}
int F_13 ( struct V_3 * V_4 )
{
return F_14 ( & V_4 -> V_9 , F_11 ) ;
}
int F_15 ( struct V_3 * V_4 , const char * V_14 ,
T_1 * V_15 )
{
int V_16 = F_16 ( V_15 ) - 1 ;
int V_17 = strlen ( V_14 ) ;
if ( V_14 [ V_17 - 1 ] >= '0' && V_14 [ V_17 - 1 ] <= '9' )
snprintf ( V_4 -> V_10 , sizeof( V_4 -> V_10 ) ,
L_2 , V_14 , V_16 ) ;
else
snprintf ( V_4 -> V_10 , sizeof( V_4 -> V_10 ) ,
L_3 , V_14 , V_16 ) ;
return V_16 ;
}
void F_17 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 == NULL )
return;
if ( F_9 ( V_4 -> V_2 ) == V_4 )
F_10 ( V_4 -> V_2 , NULL ) ;
F_18 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
}
void F_19 ( struct V_3 * V_4 )
{
struct V_18 * V_19 , * V_20 ;
if ( V_4 == NULL || ! V_4 -> V_10 [ 0 ] )
return;
F_17 ( V_4 ) ;
F_20 (sd, next, &v4l2_dev->subdevs, list) {
F_21 ( V_19 ) ;
#if F_22 ( V_21 )
if ( V_19 -> V_22 & V_23 ) {
struct V_24 * V_25 = F_23 ( V_19 ) ;
if ( V_25 &&
! V_25 -> V_2 . V_26 && ! V_25 -> V_2 . V_27 )
F_24 ( V_25 ) ;
continue;
}
#endif
#if F_25 ( V_28 )
if ( V_19 -> V_22 & V_29 ) {
struct V_30 * V_31 = F_23 ( V_19 ) ;
if ( V_31 && ! V_31 -> V_2 . V_26 && ! V_31 -> V_2 . V_27 )
F_26 ( V_31 ) ;
continue;
}
#endif
}
V_4 -> V_10 [ 0 ] = '\0' ;
}
int F_27 ( struct V_3 * V_4 ,
struct V_18 * V_19 )
{
#if F_25 ( V_32 )
struct V_33 * V_34 = & V_19 -> V_34 ;
#endif
int V_35 ;
if ( V_4 == NULL || V_19 == NULL || ! V_19 -> V_10 [ 0 ] )
return - V_5 ;
F_7 ( V_19 -> V_4 != NULL ) ;
V_19 -> V_36 = V_4 -> V_2 && V_4 -> V_2 -> V_11 &&
V_19 -> V_37 == V_4 -> V_2 -> V_11 -> V_37 ;
if ( ! V_19 -> V_36 && ! F_28 ( V_19 -> V_37 ) )
return - V_38 ;
V_19 -> V_4 = V_4 ;
V_35 = F_29 ( V_4 -> V_39 , V_19 -> V_39 , NULL ) ;
if ( V_35 )
goto V_40;
#if F_25 ( V_32 )
if ( V_4 -> V_41 ) {
V_35 = F_30 ( V_4 -> V_41 , V_34 ) ;
if ( V_35 < 0 )
goto V_40;
}
#endif
if ( V_19 -> V_42 && V_19 -> V_42 -> V_43 ) {
V_35 = V_19 -> V_42 -> V_43 ( V_19 ) ;
if ( V_35 )
goto V_44;
}
F_31 ( & V_4 -> V_7 ) ;
F_32 ( & V_19 -> V_45 , & V_4 -> V_6 ) ;
F_33 ( & V_4 -> V_7 ) ;
return 0 ;
V_44:
#if F_25 ( V_32 )
F_34 ( V_34 ) ;
#endif
V_40:
if ( ! V_19 -> V_36 )
F_35 ( V_19 -> V_37 ) ;
V_19 -> V_4 = NULL ;
return V_35 ;
}
static void F_36 ( struct V_46 * V_47 )
{
struct V_18 * V_19 = F_37 ( V_47 ) ;
V_19 -> V_48 = NULL ;
F_38 ( V_47 ) ;
}
int F_39 ( struct V_3 * V_4 )
{
struct V_46 * V_47 ;
struct V_18 * V_19 ;
int V_35 ;
F_40 (sd, &v4l2_dev->subdevs, list) {
if ( ! ( V_19 -> V_22 & V_49 ) )
continue;
V_47 = F_41 ( sizeof( * V_47 ) , V_50 ) ;
if ( ! V_47 ) {
V_35 = - V_51 ;
goto V_52;
}
F_42 ( V_47 , V_19 ) ;
F_43 ( V_47 -> V_10 , V_19 -> V_10 , sizeof( V_47 -> V_10 ) ) ;
V_47 -> V_4 = V_4 ;
V_47 -> V_53 = & V_54 ;
V_47 -> V_13 = F_36 ;
V_47 -> V_39 = V_19 -> V_39 ;
V_35 = F_44 ( V_47 , V_55 , - 1 , 1 ,
V_19 -> V_37 ) ;
if ( V_35 < 0 ) {
F_38 ( V_47 ) ;
goto V_52;
}
#if F_25 ( V_32 )
V_19 -> V_34 . V_56 . V_2 . V_57 = V_58 ;
V_19 -> V_34 . V_56 . V_2 . V_59 = V_47 -> V_59 ;
if ( V_47 -> V_4 -> V_41 ) {
struct V_60 * V_61 ;
V_61 = F_45 ( & V_19 -> V_34 ,
& V_47 -> V_62 -> V_63 ,
V_64 ) ;
if ( ! V_61 ) {
V_35 = - V_51 ;
goto V_52;
}
}
#endif
V_19 -> V_48 = V_47 ;
}
return 0 ;
V_52:
F_40 (sd, &v4l2_dev->subdevs, list) {
if ( ! V_19 -> V_48 )
break;
F_46 ( V_19 -> V_48 ) ;
}
return V_35 ;
}
void F_21 ( struct V_18 * V_19 )
{
struct V_3 * V_4 ;
if ( V_19 == NULL || V_19 -> V_4 == NULL )
return;
V_4 = V_19 -> V_4 ;
F_31 ( & V_4 -> V_7 ) ;
F_47 ( & V_19 -> V_45 ) ;
F_33 ( & V_4 -> V_7 ) ;
if ( V_19 -> V_42 && V_19 -> V_42 -> V_65 )
V_19 -> V_42 -> V_65 ( V_19 ) ;
V_19 -> V_4 = NULL ;
#if F_25 ( V_32 )
if ( V_4 -> V_41 ) {
F_34 ( & V_19 -> V_34 ) ;
}
#endif
F_46 ( V_19 -> V_48 ) ;
if ( ! V_19 -> V_36 )
F_35 ( V_19 -> V_37 ) ;
}
