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
if ( V_25 )
F_24 ( V_25 ) ;
continue;
}
#endif
#if F_25 ( V_26 )
if ( V_19 -> V_22 & V_27 ) {
struct V_28 * V_29 = F_23 ( V_19 ) ;
if ( V_29 )
F_26 ( V_29 ) ;
continue;
}
#endif
}
V_4 -> V_10 [ 0 ] = '\0' ;
}
int F_27 ( struct V_3 * V_4 ,
struct V_18 * V_19 )
{
#if F_25 ( V_30 )
struct V_31 * V_32 = & V_19 -> V_32 ;
#endif
int V_33 ;
if ( V_4 == NULL || V_19 == NULL || ! V_19 -> V_10 [ 0 ] )
return - V_5 ;
F_7 ( V_19 -> V_4 != NULL ) ;
V_19 -> V_34 = V_4 -> V_2 && V_4 -> V_2 -> V_11 &&
V_19 -> V_35 == V_4 -> V_2 -> V_11 -> V_35 ;
if ( ! V_19 -> V_34 && ! F_28 ( V_19 -> V_35 ) )
return - V_36 ;
V_19 -> V_4 = V_4 ;
if ( V_19 -> V_37 && V_19 -> V_37 -> V_38 ) {
V_33 = V_19 -> V_37 -> V_38 ( V_19 ) ;
if ( V_33 )
goto V_39;
}
V_33 = F_29 ( V_4 -> V_40 , V_19 -> V_40 , NULL ) ;
if ( V_33 )
goto V_41;
#if F_25 ( V_30 )
if ( V_4 -> V_42 ) {
V_33 = F_30 ( V_4 -> V_42 , V_32 ) ;
if ( V_33 < 0 )
goto V_41;
}
#endif
F_31 ( & V_4 -> V_7 ) ;
F_32 ( & V_19 -> V_43 , & V_4 -> V_6 ) ;
F_33 ( & V_4 -> V_7 ) ;
return 0 ;
V_41:
if ( V_19 -> V_37 && V_19 -> V_37 -> V_44 )
V_19 -> V_37 -> V_44 ( V_19 ) ;
V_39:
if ( ! V_19 -> V_34 )
F_34 ( V_19 -> V_35 ) ;
V_19 -> V_4 = NULL ;
return V_33 ;
}
static void F_35 ( struct V_45 * V_46 )
{
struct V_18 * V_19 = F_36 ( V_46 ) ;
V_19 -> V_47 = NULL ;
F_37 ( V_46 ) ;
}
int F_38 ( struct V_3 * V_4 )
{
struct V_45 * V_46 ;
struct V_18 * V_19 ;
int V_33 ;
F_39 (sd, &v4l2_dev->subdevs, list) {
if ( ! ( V_19 -> V_22 & V_48 ) )
continue;
V_46 = F_40 ( sizeof( * V_46 ) , V_49 ) ;
if ( ! V_46 ) {
V_33 = - V_50 ;
goto V_51;
}
F_41 ( V_46 , V_19 ) ;
F_42 ( V_46 -> V_10 , V_19 -> V_10 , sizeof( V_46 -> V_10 ) ) ;
V_46 -> V_4 = V_4 ;
V_46 -> V_52 = & V_53 ;
V_46 -> V_13 = F_35 ;
V_46 -> V_40 = V_19 -> V_40 ;
V_33 = F_43 ( V_46 , V_54 , - 1 , 1 ,
V_19 -> V_35 ) ;
if ( V_33 < 0 ) {
F_37 ( V_46 ) ;
goto V_51;
}
#if F_25 ( V_30 )
V_19 -> V_32 . V_55 . V_2 . V_56 = V_57 ;
V_19 -> V_32 . V_55 . V_2 . V_58 = V_46 -> V_58 ;
#endif
V_19 -> V_47 = V_46 ;
}
return 0 ;
V_51:
F_39 (sd, &v4l2_dev->subdevs, list) {
if ( ! V_19 -> V_47 )
break;
F_44 ( V_19 -> V_47 ) ;
}
return V_33 ;
}
void F_21 ( struct V_18 * V_19 )
{
struct V_3 * V_4 ;
if ( V_19 == NULL || V_19 -> V_4 == NULL )
return;
V_4 = V_19 -> V_4 ;
F_31 ( & V_4 -> V_7 ) ;
F_45 ( & V_19 -> V_43 ) ;
F_33 ( & V_4 -> V_7 ) ;
if ( V_19 -> V_37 && V_19 -> V_37 -> V_44 )
V_19 -> V_37 -> V_44 ( V_19 ) ;
V_19 -> V_4 = NULL ;
#if F_25 ( V_30 )
if ( V_4 -> V_42 ) {
F_46 ( & V_19 -> V_32 ) ;
F_47 ( & V_19 -> V_32 ) ;
}
#endif
F_44 ( V_19 -> V_47 ) ;
if ( ! V_19 -> V_34 )
F_34 ( V_19 -> V_35 ) ;
}
