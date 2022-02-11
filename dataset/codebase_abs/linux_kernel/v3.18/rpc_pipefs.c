static void
F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
int V_4 ;
* V_1 ++ = F_2 ( 1 ) ;
* V_1 ++ = F_2 ( V_3 -> type ) ;
* V_1 ++ = F_2 ( V_3 -> V_5 . V_6 ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 . V_6 ; V_4 ++ ) {
V_1 = F_3 ( V_1 , V_3 -> V_5 . V_7 [ V_4 ] . V_8 ) ;
V_1 = F_4 ( V_1 , V_3 -> V_5 . V_7 [ V_4 ] . V_9 ,
V_3 -> V_5 . V_7 [ V_4 ] . V_10 ) ;
}
}
T_2
F_5 ( struct V_11 * V_12 , struct V_2 * V_3 ,
T_3 V_13 )
{
struct V_14 * V_14 = V_12 -> V_15 -> V_16 ;
struct V_17 * V_18 = F_6 ( V_14 , V_19 ) ;
struct V_20 * V_21 = & V_18 -> V_22 ;
struct V_23 V_23 ;
struct V_24 * V_25 = & V_23 . V_25 ;
struct V_26 * V_27 ;
F_7 ( V_28 , V_29 ) ;
T_2 V_30 = 0 ;
int V_31 ;
F_8 ( L_1 , V_32 ) ;
F_9 ( & V_18 -> V_33 ) ;
V_23 . V_34 = & V_18 -> V_34 ;
V_3 -> V_5 . V_35 += 4 ;
if ( V_3 -> V_5 . V_35 > V_36 )
goto V_37;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_35 = sizeof( * V_27 ) + V_3 -> V_5 . V_35 ;
V_25 -> V_38 = F_10 ( V_25 -> V_35 , V_13 ) ;
if ( ! V_25 -> V_38 )
goto V_39;
V_27 = V_25 -> V_38 ;
V_27 -> type = V_40 ,
V_27 -> V_41 = V_3 -> V_5 . V_35 ;
F_1 ( V_25 -> V_38 + sizeof( * V_27 ) , V_3 ) ;
F_8 ( L_2 , V_32 ) ;
F_11 ( & V_18 -> V_34 , & V_28 ) ;
V_31 = F_12 ( V_18 -> V_42 , V_25 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_18 -> V_34 , & V_28 ) ;
goto V_39;
}
F_14 ( V_43 ) ;
F_15 () ;
F_13 ( & V_18 -> V_34 , & V_28 ) ;
if ( V_21 -> V_44 != V_45 ) {
F_16 ( V_46 L_3 ,
V_32 , V_21 -> V_44 ) ;
goto V_39;
}
V_30 = F_17 ( V_21 -> V_47 , V_21 -> V_48 ) ;
V_39:
F_18 ( V_25 -> V_38 ) ;
V_37:
F_19 ( & V_18 -> V_33 ) ;
return V_30 ;
}
static T_4 F_20 ( struct V_49 * V_50 , const char T_5 * V_51 ,
T_6 V_52 )
{
struct V_17 * V_18 = F_6 ( V_50 -> V_53 -> V_54 -> V_55 ,
V_19 ) ;
if ( V_52 != sizeof ( struct V_20 ) )
return - V_56 ;
if ( F_21 ( & V_18 -> V_22 , V_51 , V_52 ) != 0 )
return - V_57 ;
F_22 ( & V_18 -> V_34 ) ;
return V_52 ;
}
static void F_23 ( struct V_24 * V_25 )
{
struct V_23 * V_23 =
F_24 ( V_25 , struct V_23 , V_25 ) ;
if ( V_25 -> V_58 >= 0 )
return;
F_22 ( V_23 -> V_34 ) ;
}
static struct V_59 * F_25 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_59 * V_64 , * V_59 ;
V_64 = F_26 ( V_61 , V_65 ) ;
if ( V_64 == NULL )
return F_27 ( - V_66 ) ;
V_59 = F_28 ( V_64 , L_4 , NULL , V_63 ) ;
F_29 ( V_64 ) ;
return V_59 ;
}
static void F_30 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
if ( V_63 -> V_59 )
F_31 ( V_63 -> V_59 ) ;
}
static int F_32 ( struct V_67 * V_68 , unsigned long V_69 ,
void * V_70 )
{
struct V_60 * V_61 = V_70 ;
struct V_14 * V_14 = V_61 -> V_55 ;
struct V_17 * V_18 = F_6 ( V_14 , V_19 ) ;
struct V_59 * V_59 ;
int V_71 = 0 ;
if ( ! F_33 ( V_72 ) )
return 0 ;
if ( V_18 -> V_42 == NULL ) {
F_34 ( V_72 ) ;
return 0 ;
}
switch ( V_69 ) {
case V_73 :
V_59 = F_25 ( V_61 , V_18 -> V_42 ) ;
if ( F_35 ( V_59 ) ) {
V_71 = F_36 ( V_59 ) ;
break;
}
V_18 -> V_42 -> V_59 = V_59 ;
break;
case V_74 :
if ( V_18 -> V_42 -> V_59 )
F_30 ( V_61 , V_18 -> V_42 ) ;
break;
default:
V_71 = - V_75 ;
break;
}
F_34 ( V_72 ) ;
return V_71 ;
}
static struct V_59 * F_37 ( struct V_14 * V_14 ,
struct V_62 * V_63 )
{
struct V_60 * V_76 ;
struct V_59 * V_59 ;
V_76 = F_38 ( V_14 ) ;
if ( ! V_76 )
return NULL ;
V_59 = F_25 ( V_76 , V_63 ) ;
F_39 ( V_14 ) ;
return V_59 ;
}
static void F_40 ( struct V_14 * V_14 ,
struct V_62 * V_63 )
{
struct V_60 * V_76 ;
V_76 = F_38 ( V_14 ) ;
if ( V_76 ) {
F_30 ( V_76 , V_63 ) ;
F_39 ( V_14 ) ;
}
}
static int F_41 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = F_6 ( V_14 , V_19 ) ;
struct V_59 * V_59 ;
F_42 ( & V_18 -> V_33 ) ;
F_43 ( & V_18 -> V_34 ) ;
V_18 -> V_42 = F_44 ( & V_77 , 0 ) ;
if ( F_35 ( V_18 -> V_42 ) )
return F_36 ( V_18 -> V_42 ) ;
V_59 = F_37 ( V_14 , V_18 -> V_42 ) ;
if ( F_35 ( V_59 ) ) {
F_45 ( V_18 -> V_42 ) ;
return F_36 ( V_59 ) ;
}
V_18 -> V_42 -> V_59 = V_59 ;
return 0 ;
}
static void F_46 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = F_6 ( V_14 , V_19 ) ;
F_40 ( V_14 , V_18 -> V_42 ) ;
F_45 ( V_18 -> V_42 ) ;
V_18 -> V_42 = NULL ;
}
int T_7 F_47 ( void )
{
int V_71 ;
V_71 = F_48 ( & V_78 ) ;
if ( V_71 )
goto V_79;
V_71 = F_49 ( & V_80 ) ;
if ( V_71 )
goto V_81;
return 0 ;
V_81:
F_50 ( & V_78 ) ;
V_79:
return V_71 ;
}
void T_8 F_51 ( void )
{
F_50 ( & V_78 ) ;
F_52 ( & V_80 ) ;
}
