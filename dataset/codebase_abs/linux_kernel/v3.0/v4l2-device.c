int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 == NULL )
return - V_5 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_9 ) ;
F_6 ( & V_4 -> V_10 ) ;
V_4 -> V_2 = V_2 ;
if ( V_2 == NULL ) {
F_7 ( ! V_4 -> V_11 [ 0 ] ) ;
return 0 ;
}
if ( ! V_4 -> V_11 [ 0 ] )
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) , L_1 ,
V_2 -> V_12 -> V_11 , F_8 ( V_2 ) ) ;
if ( ! F_9 ( V_2 ) )
F_10 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_13 * V_10 )
{
struct V_3 * V_4 =
F_12 ( V_10 , struct V_3 , V_10 ) ;
if ( V_4 -> V_14 )
V_4 -> V_14 ( V_4 ) ;
}
int F_13 ( struct V_3 * V_4 )
{
return F_14 ( & V_4 -> V_10 , F_11 ) ;
}
int F_15 ( struct V_3 * V_4 , const char * V_15 ,
T_1 * V_16 )
{
int V_17 = F_16 ( V_16 ) - 1 ;
int V_18 = strlen ( V_15 ) ;
if ( V_15 [ V_18 - 1 ] >= '0' && V_15 [ V_18 - 1 ] <= '9' )
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_2 , V_15 , V_17 ) ;
else
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_3 , V_15 , V_17 ) ;
return V_17 ;
}
void F_17 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 == NULL )
return;
if ( F_9 ( V_4 -> V_2 ) == V_4 )
F_10 ( V_4 -> V_2 , NULL ) ;
V_4 -> V_2 = NULL ;
}
void F_18 ( struct V_3 * V_4 )
{
struct V_19 * V_20 , * V_21 ;
if ( V_4 == NULL )
return;
F_17 ( V_4 ) ;
F_19 (sd, next, &v4l2_dev->subdevs, list) {
F_20 ( V_20 ) ;
#if F_21 ( V_22 ) || ( F_21 ( V_23 ) && F_21 ( V_24 ) )
if ( V_20 -> V_25 & V_26 ) {
struct V_27 * V_28 = F_22 ( V_20 ) ;
if ( V_28 )
F_23 ( V_28 ) ;
continue;
}
#endif
#if F_21 ( V_29 )
if ( V_20 -> V_25 & V_30 ) {
struct V_31 * V_32 = F_22 ( V_20 ) ;
if ( V_32 )
F_24 ( V_32 ) ;
continue;
}
#endif
}
}
int F_25 ( struct V_3 * V_4 ,
struct V_19 * V_20 )
{
#if F_21 ( V_33 )
struct V_34 * V_35 = & V_20 -> V_35 ;
#endif
int V_36 ;
if ( V_4 == NULL || V_20 == NULL || ! V_20 -> V_11 [ 0 ] )
return - V_5 ;
F_7 ( V_20 -> V_4 != NULL ) ;
if ( ! F_26 ( V_20 -> V_37 ) )
return - V_38 ;
V_20 -> V_4 = V_4 ;
if ( V_20 -> V_39 && V_20 -> V_39 -> V_40 ) {
V_36 = V_20 -> V_39 -> V_40 ( V_20 ) ;
if ( V_36 ) {
F_27 ( V_20 -> V_37 ) ;
return V_36 ;
}
}
V_36 = F_28 ( V_4 -> V_41 , V_20 -> V_41 ) ;
if ( V_36 ) {
if ( V_20 -> V_39 && V_20 -> V_39 -> V_42 )
V_20 -> V_39 -> V_42 ( V_20 ) ;
F_27 ( V_20 -> V_37 ) ;
return V_36 ;
}
#if F_21 ( V_33 )
if ( V_4 -> V_43 ) {
V_36 = F_29 ( V_4 -> V_43 , V_35 ) ;
if ( V_36 < 0 ) {
if ( V_20 -> V_39 && V_20 -> V_39 -> V_42 )
V_20 -> V_39 -> V_42 ( V_20 ) ;
F_27 ( V_20 -> V_37 ) ;
return V_36 ;
}
}
#endif
F_30 ( & V_4 -> V_7 ) ;
F_31 ( & V_20 -> V_44 , & V_4 -> V_6 ) ;
F_32 ( & V_4 -> V_7 ) ;
return 0 ;
}
int F_33 ( struct V_3 * V_4 )
{
struct V_45 * V_46 ;
struct V_19 * V_20 ;
int V_36 ;
F_34 (sd, &v4l2_dev->subdevs, list) {
if ( ! ( V_20 -> V_25 & V_47 ) )
continue;
V_46 = & V_20 -> V_48 ;
F_35 ( V_46 -> V_11 , V_20 -> V_11 , sizeof( V_46 -> V_11 ) ) ;
V_46 -> V_4 = V_4 ;
V_46 -> V_49 = & V_50 ;
V_46 -> V_14 = V_51 ;
V_36 = F_36 ( V_46 , V_52 , - 1 , 1 ,
V_20 -> V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
#if F_21 ( V_33 )
V_20 -> V_35 . V_53 . V_54 = V_55 ;
V_20 -> V_35 . V_53 . V_56 = V_46 -> V_56 ;
#endif
}
return 0 ;
}
void F_20 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
if ( V_20 == NULL || V_20 -> V_4 == NULL )
return;
V_4 = V_20 -> V_4 ;
F_30 ( & V_4 -> V_7 ) ;
F_37 ( & V_20 -> V_44 ) ;
F_32 ( & V_4 -> V_7 ) ;
if ( V_20 -> V_39 && V_20 -> V_39 -> V_42 )
V_20 -> V_39 -> V_42 ( V_20 ) ;
V_20 -> V_4 = NULL ;
#if F_21 ( V_33 )
if ( V_4 -> V_43 )
F_38 ( & V_20 -> V_35 ) ;
#endif
F_39 ( & V_20 -> V_48 ) ;
F_27 ( V_20 -> V_37 ) ;
}
