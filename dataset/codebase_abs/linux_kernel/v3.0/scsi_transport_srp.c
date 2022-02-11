static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 , 0 ) ;
return 0 ;
}
static T_1
F_5 ( struct V_3 * V_4 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_6 ( V_4 ) ;
return sprintf ( V_13 , V_16 L_1 , F_7 ( V_15 ) ) ;
}
static T_1
F_8 ( struct V_3 * V_4 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_6 ( V_4 ) ;
int V_17 ;
char * V_18 = NULL ;
for ( V_17 = 0 ; V_17 < F_9 ( V_19 ) ; V_17 ++ )
if ( V_19 [ V_17 ] . V_20 == V_15 -> V_21 ) {
V_18 = V_19 [ V_17 ] . V_18 ;
break;
}
return sprintf ( V_13 , L_2 , V_18 ? : L_3 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_11 ( V_4 ) ;
F_12 ( V_4 -> V_22 ) ;
F_13 ( V_15 ) ;
}
static int F_14 ( const struct V_3 * V_4 )
{
return V_4 -> V_23 == F_10 ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_26 * V_17 ;
if ( ! F_14 ( V_4 ) )
return 0 ;
V_7 = F_2 ( V_4 -> V_22 ) ;
if ( ! V_7 -> V_27 )
return 0 ;
if ( V_7 -> V_27 -> V_28 . V_29 . V_30 != & V_31 . V_30 )
return 0 ;
V_17 = F_16 ( V_7 -> V_27 ) ;
return & V_17 -> V_32 . V_29 == V_25 ;
}
static int F_17 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_26 * V_17 ;
if ( ! F_18 ( V_4 ) )
return 0 ;
V_7 = F_2 ( V_4 ) ;
if ( ! V_7 -> V_27 )
return 0 ;
if ( V_7 -> V_27 -> V_28 . V_29 . V_30 != & V_31 . V_30 )
return 0 ;
V_17 = F_16 ( V_7 -> V_27 ) ;
return & V_17 -> V_33 . V_28 . V_29 == V_25 ;
}
struct V_14 * F_19 ( struct V_6 * V_7 ,
struct V_34 * V_35 )
{
struct V_14 * V_15 ;
struct V_3 * V_22 = & V_7 -> V_36 ;
int V_37 , V_38 ;
V_15 = F_20 ( sizeof( * V_15 ) , V_39 ) ;
if ( ! V_15 )
return F_21 ( - V_40 ) ;
F_22 ( & V_15 -> V_4 ) ;
V_15 -> V_4 . V_22 = F_23 ( V_22 ) ;
V_15 -> V_4 . V_23 = F_10 ;
memcpy ( V_15 -> V_41 , V_35 -> V_41 , sizeof( V_15 -> V_41 ) ) ;
V_15 -> V_21 = V_35 -> V_21 ;
V_37 = F_24 ( & F_3 ( V_7 ) -> V_10 ) ;
F_25 ( & V_15 -> V_4 , L_4 , V_7 -> V_42 , V_37 ) ;
F_26 ( & V_15 -> V_4 ) ;
V_38 = F_27 ( & V_15 -> V_4 ) ;
if ( V_38 ) {
F_28 ( & V_15 -> V_4 ) ;
F_12 ( & V_15 -> V_4 ) ;
return F_21 ( V_38 ) ;
}
if ( V_7 -> V_43 & V_44 &&
V_35 -> V_21 == V_45 ) {
V_38 = F_29 ( V_7 , ( unsigned long ) V_15 ,
V_15 -> V_41 ) ;
if ( V_38 ) {
F_30 ( & V_15 -> V_4 ) ;
F_28 ( & V_15 -> V_4 ) ;
F_12 ( & V_15 -> V_4 ) ;
return F_21 ( V_38 ) ;
}
}
F_31 ( & V_15 -> V_4 ) ;
F_32 ( & V_15 -> V_4 ) ;
return V_15 ;
}
void F_33 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = & V_15 -> V_4 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_22 ) ;
if ( V_7 -> V_43 & V_44 &&
V_15 -> V_21 == V_45 )
F_34 ( V_7 , ( unsigned long ) V_15 ) ;
F_35 ( V_4 ) ;
F_30 ( V_4 ) ;
F_28 ( V_4 ) ;
F_12 ( V_4 ) ;
}
static int F_36 ( struct V_3 * V_4 , void * V_46 )
{
if ( F_14 ( V_4 ) )
F_33 ( F_11 ( V_4 ) ) ;
return 0 ;
}
void F_37 ( struct V_6 * V_7 )
{
F_38 ( & V_7 -> V_36 , NULL , F_36 ) ;
}
static int F_39 ( struct V_6 * V_7 , T_2 V_47 , T_2 V_48 ,
int V_49 )
{
struct V_26 * V_17 = F_16 ( V_7 -> V_27 ) ;
return V_17 -> V_50 -> V_51 ( V_7 , V_47 , V_48 , V_49 ) ;
}
static int F_40 ( struct V_6 * V_7 , T_2 V_47 , int V_49 )
{
struct V_26 * V_17 = F_16 ( V_7 -> V_27 ) ;
return V_17 -> V_50 -> V_52 ( V_7 , V_47 , V_49 ) ;
}
struct V_53 *
F_41 ( struct V_54 * V_55 )
{
int V_56 ;
struct V_26 * V_17 ;
V_17 = F_20 ( sizeof( * V_17 ) , V_39 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_33 . V_51 = F_39 ;
V_17 -> V_33 . V_52 = F_40 ;
V_17 -> V_33 . V_57 = sizeof( struct V_8 ) ;
V_17 -> V_33 . V_28 . V_29 . V_58 = & V_17 -> V_28 [ 0 ] ;
V_17 -> V_33 . V_28 . V_29 . V_30 = & V_31 . V_30 ;
V_17 -> V_33 . V_28 . V_29 . V_59 = F_17 ;
V_17 -> V_28 [ 0 ] = NULL ;
F_42 ( & V_17 -> V_33 . V_28 ) ;
V_17 -> V_32 . V_29 . V_58 = & V_17 -> V_60 [ 0 ] ;
V_17 -> V_32 . V_29 . V_30 = & V_61 . V_30 ;
V_17 -> V_32 . V_29 . V_59 = F_15 ;
F_42 ( & V_17 -> V_32 ) ;
V_56 = 0 ;
F_43 ( V_41 ) ;
F_43 ( V_21 ) ;
V_17 -> V_60 [ V_56 ] = NULL ;
V_17 -> V_50 = V_55 ;
return & V_17 -> V_33 ;
}
void F_44 ( struct V_53 * V_33 )
{
struct V_26 * V_17 = F_16 ( V_33 ) ;
F_45 ( & V_17 -> V_33 . V_28 ) ;
F_45 ( & V_17 -> V_32 ) ;
F_13 ( V_17 ) ;
}
static T_3 int F_46 ( void )
{
int V_38 ;
V_38 = F_47 ( & V_31 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_47 ( & V_61 ) ;
if ( V_38 )
goto V_62;
return 0 ;
V_62:
F_48 ( & V_31 ) ;
return V_38 ;
}
static void T_4 F_49 ( void )
{
F_48 ( & V_31 ) ;
F_48 ( & V_61 ) ;
}
