int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 == NULL )
return - V_5 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_9 ) ;
F_6 ( & V_4 -> V_10 ) ;
F_7 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
if ( V_2 == NULL ) {
if ( F_8 ( ! V_4 -> V_11 [ 0 ] ) )
return - V_5 ;
return 0 ;
}
if ( ! V_4 -> V_11 [ 0 ] )
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) , L_1 ,
V_2 -> V_12 -> V_11 , F_9 ( V_2 ) ) ;
if ( ! F_10 ( V_2 ) )
F_11 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_12 ( struct V_13 * V_10 )
{
struct V_3 * V_4 =
F_13 ( V_10 , struct V_3 , V_10 ) ;
if ( V_4 -> V_14 )
V_4 -> V_14 ( V_4 ) ;
}
int F_14 ( struct V_3 * V_4 )
{
return F_15 ( & V_4 -> V_10 , F_12 ) ;
}
int F_16 ( struct V_3 * V_4 , const char * V_15 ,
T_1 * V_16 )
{
int V_17 = F_17 ( V_16 ) - 1 ;
int V_18 = strlen ( V_15 ) ;
if ( V_15 [ V_18 - 1 ] >= '0' && V_15 [ V_18 - 1 ] <= '9' )
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_2 , V_15 , V_17 ) ;
else
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_3 , V_15 , V_17 ) ;
return V_17 ;
}
void F_18 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 == NULL )
return;
if ( F_10 ( V_4 -> V_2 ) == V_4 )
F_11 ( V_4 -> V_2 , NULL ) ;
F_19 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
}
void F_20 ( struct V_3 * V_4 )
{
struct V_19 * V_20 , * V_21 ;
if ( V_4 == NULL || ! V_4 -> V_11 [ 0 ] )
return;
F_18 ( V_4 ) ;
F_21 (sd, next, &v4l2_dev->subdevs, list) {
F_22 ( V_20 ) ;
#if F_23 ( V_22 )
if ( V_20 -> V_23 & V_24 ) {
struct V_25 * V_26 = F_24 ( V_20 ) ;
if ( V_26 )
F_25 ( V_26 ) ;
continue;
}
#endif
#if F_26 ( V_27 )
if ( V_20 -> V_23 & V_28 ) {
struct V_29 * V_30 = F_24 ( V_20 ) ;
if ( V_30 )
F_27 ( V_30 ) ;
continue;
}
#endif
}
V_4 -> V_11 [ 0 ] = '\0' ;
}
int F_28 ( struct V_3 * V_4 ,
struct V_19 * V_20 )
{
#if F_26 ( V_31 )
struct V_32 * V_33 = & V_20 -> V_33 ;
#endif
int V_34 ;
if ( V_4 == NULL || V_20 == NULL || ! V_20 -> V_11 [ 0 ] )
return - V_5 ;
F_8 ( V_20 -> V_4 != NULL ) ;
if ( ! F_29 ( V_20 -> V_35 ) )
return - V_36 ;
V_20 -> V_4 = V_4 ;
if ( V_20 -> V_37 && V_20 -> V_37 -> V_38 ) {
V_34 = V_20 -> V_37 -> V_38 ( V_20 ) ;
if ( V_34 )
goto V_39;
}
V_34 = F_30 ( V_4 -> V_40 , V_20 -> V_40 , NULL ) ;
if ( V_34 )
goto V_41;
#if F_26 ( V_31 )
if ( V_4 -> V_42 ) {
V_34 = F_31 ( V_4 -> V_42 , V_33 ) ;
if ( V_34 < 0 )
goto V_41;
}
#endif
F_32 ( & V_4 -> V_7 ) ;
F_33 ( & V_20 -> V_43 , & V_4 -> V_6 ) ;
F_34 ( & V_4 -> V_7 ) ;
return 0 ;
V_41:
if ( V_20 -> V_37 && V_20 -> V_37 -> V_44 )
V_20 -> V_37 -> V_44 ( V_20 ) ;
V_39:
F_35 ( V_20 -> V_35 ) ;
V_20 -> V_4 = NULL ;
return V_34 ;
}
static void F_36 ( struct V_45 * V_46 )
{
struct V_19 * V_20 = F_37 ( V_46 ) ;
V_20 -> V_47 = NULL ;
F_38 ( V_46 ) ;
}
int F_39 ( struct V_3 * V_4 )
{
struct V_45 * V_46 ;
struct V_19 * V_20 ;
int V_34 ;
F_40 (sd, &v4l2_dev->subdevs, list) {
if ( ! ( V_20 -> V_23 & V_48 ) )
continue;
V_46 = F_41 ( sizeof( * V_46 ) , V_49 ) ;
if ( ! V_46 ) {
V_34 = - V_50 ;
goto V_51;
}
F_42 ( V_46 , V_20 ) ;
F_43 ( V_46 -> V_11 , V_20 -> V_11 , sizeof( V_46 -> V_11 ) ) ;
V_46 -> V_4 = V_4 ;
V_46 -> V_52 = & V_53 ;
V_46 -> V_14 = F_36 ;
V_46 -> V_40 = V_20 -> V_40 ;
V_34 = F_44 ( V_46 , V_54 , - 1 , 1 ,
V_20 -> V_35 ) ;
if ( V_34 < 0 ) {
F_38 ( V_46 ) ;
goto V_51;
}
#if F_26 ( V_31 )
V_20 -> V_33 . V_55 . V_56 . V_57 = V_58 ;
V_20 -> V_33 . V_55 . V_56 . V_59 = V_46 -> V_59 ;
#endif
V_20 -> V_47 = V_46 ;
}
return 0 ;
V_51:
F_40 (sd, &v4l2_dev->subdevs, list) {
if ( ! V_20 -> V_47 )
break;
F_45 ( V_20 -> V_47 ) ;
}
return V_34 ;
}
void F_22 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
if ( V_20 == NULL || V_20 -> V_4 == NULL )
return;
V_4 = V_20 -> V_4 ;
F_32 ( & V_4 -> V_7 ) ;
F_46 ( & V_20 -> V_43 ) ;
F_34 ( & V_4 -> V_7 ) ;
if ( V_20 -> V_37 && V_20 -> V_37 -> V_44 )
V_20 -> V_37 -> V_44 ( V_20 ) ;
V_20 -> V_4 = NULL ;
#if F_26 ( V_31 )
if ( V_4 -> V_42 ) {
F_47 ( & V_20 -> V_33 ) ;
F_48 ( & V_20 -> V_33 ) ;
}
#endif
F_45 ( V_20 -> V_47 ) ;
F_35 ( V_20 -> V_35 ) ;
}
