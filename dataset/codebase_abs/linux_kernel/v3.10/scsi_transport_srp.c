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
static T_1 F_10 ( struct V_3 * V_4 ,
struct V_11 * V_12 ,
const char * V_13 , T_2 V_22 )
{
struct V_14 * V_15 = F_6 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_23 * V_17 = F_11 ( V_7 -> V_24 ) ;
if ( V_17 -> V_25 -> V_26 ) {
V_17 -> V_25 -> V_26 ( V_15 ) ;
return V_22 ;
} else {
return - V_27 ;
}
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_13 ( V_4 ) ;
F_14 ( V_4 -> V_28 ) ;
F_15 ( V_15 ) ;
}
static int F_16 ( const struct V_3 * V_4 )
{
return V_4 -> V_29 == F_12 ;
}
static int F_17 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_23 * V_17 ;
if ( ! F_16 ( V_4 ) )
return 0 ;
V_7 = F_2 ( V_4 -> V_28 ) ;
if ( ! V_7 -> V_24 )
return 0 ;
if ( V_7 -> V_24 -> V_32 . V_33 . V_34 != & V_35 . V_34 )
return 0 ;
V_17 = F_11 ( V_7 -> V_24 ) ;
return & V_17 -> V_36 . V_33 == V_31 ;
}
static int F_18 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_23 * V_17 ;
if ( ! F_19 ( V_4 ) )
return 0 ;
V_7 = F_2 ( V_4 ) ;
if ( ! V_7 -> V_24 )
return 0 ;
if ( V_7 -> V_24 -> V_32 . V_33 . V_34 != & V_35 . V_34 )
return 0 ;
V_17 = F_11 ( V_7 -> V_24 ) ;
return & V_17 -> V_37 . V_32 . V_33 == V_31 ;
}
struct V_14 * F_20 ( struct V_6 * V_7 ,
struct V_38 * V_39 )
{
struct V_14 * V_15 ;
struct V_3 * V_28 = & V_7 -> V_40 ;
int V_41 , V_42 ;
V_15 = F_21 ( sizeof( * V_15 ) , V_43 ) ;
if ( ! V_15 )
return F_22 ( - V_44 ) ;
F_23 ( & V_15 -> V_4 ) ;
V_15 -> V_4 . V_28 = F_24 ( V_28 ) ;
V_15 -> V_4 . V_29 = F_12 ;
memcpy ( V_15 -> V_45 , V_39 -> V_45 , sizeof( V_15 -> V_45 ) ) ;
V_15 -> V_21 = V_39 -> V_21 ;
V_41 = F_25 ( & F_3 ( V_7 ) -> V_10 ) ;
F_26 ( & V_15 -> V_4 , L_4 , V_7 -> V_46 , V_41 ) ;
F_27 ( & V_15 -> V_4 ) ;
V_42 = F_28 ( & V_15 -> V_4 ) ;
if ( V_42 ) {
F_29 ( & V_15 -> V_4 ) ;
F_14 ( & V_15 -> V_4 ) ;
return F_22 ( V_42 ) ;
}
if ( V_7 -> V_47 & V_48 &&
V_39 -> V_21 == V_49 ) {
V_42 = F_30 ( V_7 , ( unsigned long ) V_15 ,
V_15 -> V_45 ) ;
if ( V_42 ) {
F_31 ( & V_15 -> V_4 ) ;
F_29 ( & V_15 -> V_4 ) ;
F_14 ( & V_15 -> V_4 ) ;
return F_22 ( V_42 ) ;
}
}
F_32 ( & V_15 -> V_4 ) ;
F_33 ( & V_15 -> V_4 ) ;
return V_15 ;
}
void F_34 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = & V_15 -> V_4 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_28 ) ;
if ( V_7 -> V_47 & V_48 &&
V_15 -> V_21 == V_49 )
F_35 ( V_7 , ( unsigned long ) V_15 ) ;
F_36 ( V_4 ) ;
F_31 ( V_4 ) ;
F_29 ( V_4 ) ;
F_14 ( V_4 ) ;
}
static int F_37 ( struct V_3 * V_4 , void * V_50 )
{
if ( F_16 ( V_4 ) )
F_34 ( F_13 ( V_4 ) ) ;
return 0 ;
}
void F_38 ( struct V_6 * V_7 )
{
F_39 ( & V_7 -> V_40 , NULL , F_37 ) ;
}
static int F_40 ( struct V_6 * V_7 , T_3 V_51 , T_3 V_52 ,
int V_53 )
{
struct V_23 * V_17 = F_11 ( V_7 -> V_24 ) ;
return V_17 -> V_25 -> V_54 ( V_7 , V_51 , V_52 , V_53 ) ;
}
static int F_41 ( struct V_6 * V_7 , T_3 V_51 , int V_53 )
{
struct V_23 * V_17 = F_11 ( V_7 -> V_24 ) ;
return V_17 -> V_25 -> V_55 ( V_7 , V_51 , V_53 ) ;
}
struct V_56 *
F_42 ( struct V_57 * V_58 )
{
int V_22 ;
struct V_23 * V_17 ;
V_17 = F_21 ( sizeof( * V_17 ) , V_43 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_37 . V_54 = F_40 ;
V_17 -> V_37 . V_55 = F_41 ;
V_17 -> V_37 . V_59 = sizeof( struct V_8 ) ;
V_17 -> V_37 . V_32 . V_33 . V_60 = & V_17 -> V_32 [ 0 ] ;
V_17 -> V_37 . V_32 . V_33 . V_34 = & V_35 . V_34 ;
V_17 -> V_37 . V_32 . V_33 . V_61 = F_18 ;
V_17 -> V_32 [ 0 ] = NULL ;
F_43 ( & V_17 -> V_37 . V_32 ) ;
V_17 -> V_36 . V_33 . V_60 = & V_17 -> V_62 [ 0 ] ;
V_17 -> V_36 . V_33 . V_34 = & V_63 . V_34 ;
V_17 -> V_36 . V_33 . V_61 = F_17 ;
V_22 = 0 ;
V_17 -> V_62 [ V_22 ++ ] = & V_64 ;
V_17 -> V_62 [ V_22 ++ ] = & V_65 ;
if ( V_58 -> V_26 )
V_17 -> V_62 [ V_22 ++ ] = & V_66 ;
V_17 -> V_62 [ V_22 ++ ] = NULL ;
F_44 ( V_22 > F_9 ( V_17 -> V_62 ) ) ;
F_43 ( & V_17 -> V_36 ) ;
V_17 -> V_25 = V_58 ;
return & V_17 -> V_37 ;
}
void F_45 ( struct V_56 * V_37 )
{
struct V_23 * V_17 = F_11 ( V_37 ) ;
F_46 ( & V_17 -> V_37 . V_32 ) ;
F_46 ( & V_17 -> V_36 ) ;
F_15 ( V_17 ) ;
}
static T_4 int F_47 ( void )
{
int V_42 ;
V_42 = F_48 ( & V_35 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_48 ( & V_63 ) ;
if ( V_42 )
goto V_67;
return 0 ;
V_67:
F_49 ( & V_35 ) ;
return V_42 ;
}
static void T_5 F_50 ( void )
{
F_49 ( & V_35 ) ;
F_49 ( & V_63 ) ;
}
