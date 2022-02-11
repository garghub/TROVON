static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
if ( F_4 ( V_4 ) ) {
struct V_9 * V_10 = F_5 ( V_4 ) ;
if ( V_6 -> V_11 -> V_12 != V_10 -> V_13 -> V_14 )
return 0 ;
return V_6 -> V_11 -> V_15 ( V_4 ) ;
}
#endif
return 0 ;
}
static int F_6 ( struct V_16 * V_17 , struct V_3 * V_4 ,
struct V_3 * V_18 )
{
struct V_19 * V_20 ;
F_7 ( F_8 ( V_18 ) ) ;
V_20 = F_9 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
F_10 ( & V_20 -> V_23 ) ;
F_11 ( V_18 , V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , struct V_3 * V_4 ,
struct V_3 * V_18 )
{
struct V_19 * V_20 = F_8 ( V_18 ) ;
struct V_24 * V_25 , * V_26 ;
F_13 ( V_27 , V_4 , L_1 ) ;
F_11 ( V_18 , NULL ) ;
F_14 (rc, next, &rd->component_list, node) {
F_15 ( & V_25 -> V_28 ) ;
F_13 ( V_27 , V_25 -> V_4 . V_29 , L_2 ) ;
F_16 ( & V_25 -> V_4 ) ;
}
F_13 ( V_27 , V_4 , L_3 ) ;
F_17 ( V_20 ) ;
return 0 ;
}
static const char * F_18 ( enum V_30 V_31 )
{
int V_6 ;
char * V_32 = NULL ;
for ( V_6 = 0 ; V_6 < F_19 ( V_33 ) ; V_6 ++ ) {
if ( V_33 [ V_6 ] . V_34 == V_31 ) {
V_32 = V_33 [ V_6 ] . V_32 ;
break;
}
}
return V_32 ;
}
static const char * F_20 ( enum V_35 V_36 )
{
int V_6 ;
char * V_32 = NULL ;
for ( V_6 = 0 ; V_6 < F_19 ( V_37 ) ; V_6 ++ ) {
if ( V_37 [ V_6 ] . V_34 == V_36 ) {
V_32 = V_37 [ V_6 ] . V_32 ;
break;
}
}
return V_32 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_24 * V_25 =
F_22 ( V_4 , struct V_24 , V_4 ) ;
F_13 ( V_27 , V_25 -> V_4 . V_29 , L_4 ) ;
F_23 ( V_25 -> V_4 . V_29 ) ;
F_17 ( V_25 ) ;
}
int F_24 ( struct V_38 * V_39 , struct V_3 * V_40 ,
struct V_3 * V_41 )
{
struct V_3 * V_18 =
F_25 ( & V_39 -> V_42 . V_43 ,
V_40 ) ;
struct V_24 * V_25 ;
struct V_19 * V_20 = F_8 ( V_18 ) ;
int V_44 ;
V_25 = F_9 ( sizeof( * V_25 ) , V_21 ) ;
if ( ! V_25 )
return - V_22 ;
F_10 ( & V_25 -> V_28 ) ;
F_26 ( & V_25 -> V_4 ) ;
V_25 -> V_4 . V_45 = F_21 ;
V_25 -> V_4 . V_29 = F_27 ( V_41 ) ;
V_25 -> V_46 = V_20 -> V_47 ++ ;
F_28 ( & V_25 -> V_4 , L_5 , V_25 -> V_46 ) ;
F_29 ( & V_25 -> V_28 , & V_20 -> V_23 ) ;
V_25 -> V_4 . V_48 = & V_49 . V_48 ;
V_44 = F_30 ( & V_25 -> V_4 ) ;
if ( V_44 )
goto V_50;
return 0 ;
V_50:
F_15 ( & V_25 -> V_28 ) ;
V_20 -> V_47 -- ;
F_23 ( V_41 ) ;
F_17 ( V_25 ) ;
return V_44 ;
}
struct V_38 *
F_31 ( struct V_51 * V_52 )
{
struct V_5 * V_6 = F_9 ( sizeof( struct V_5 ) ,
V_21 ) ;
int V_53 = 0 ;
if ( F_32 ( ! V_6 ) )
return NULL ;
V_6 -> V_11 = V_52 ;
V_6 -> V_39 . V_42 . V_43 . V_48 = & V_49 . V_48 ;
V_6 -> V_39 . V_42 . V_43 . V_54 = F_1 ;
V_6 -> V_39 . V_42 . V_43 . V_55 = & V_6 -> V_55 [ 0 ] ;
F_33 ( & V_6 -> V_39 . V_42 . V_43 ) ;
V_6 -> V_55 [ V_53 ++ ] = & V_56 ;
V_6 -> V_55 [ V_53 ++ ] = & V_57 ;
V_6 -> V_55 [ V_53 ++ ] = & V_58 ;
V_6 -> V_55 [ V_53 ] = NULL ;
F_7 ( V_53 > V_59 ) ;
return & V_6 -> V_39 ;
}
void
F_34 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_35 ( V_39 ) ;
F_7 ( F_36 ( & V_6 -> V_39 . V_42 . V_43 ) ) ;
F_17 ( V_6 ) ;
}
static T_1 int F_37 ( void )
{
return F_38 ( & V_49 ) ;
}
static T_2 void F_39 ( void )
{
F_40 ( & V_49 ) ;
}
