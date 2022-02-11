static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 () ;
if ( ! V_5 )
return - V_6 ;
V_3 -> V_7 = V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_7 ;
return F_4 ( V_5 ) ;
}
static int F_5 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_4 * V_9 = V_3 -> V_7 ;
F_6 ( & V_9 -> V_10 ) ;
if ( V_9 -> V_11 == V_8 )
F_7 ( V_9 ) ;
F_8 ( & V_9 -> V_10 ) ;
return 0 ;
}
static T_2 void F_9 ( int V_12 , const char * V_13 )
{
if ( V_12 < 0 && V_12 != - V_14 )
F_10 ( V_15 . V_16 . V_17 , L_1 , V_13 , V_12 ) ;
}
static long F_11 ( struct V_2 * V_3 , unsigned int V_18 , unsigned long V_19 )
{
struct V_4 * V_5 = V_3 -> V_7 ;
void T_3 * V_20 = ( void T_3 * ) V_19 ;
int V_12 = 0 ;
struct V_21 V_22 ;
bool V_23 = false ;
V_23 = ! ! ( V_3 -> V_24 & V_25 ) ;
switch ( V_18 ) {
case V_26 :
{
int V_27 ;
if ( F_12 ( & V_27 , V_20 , sizeof( V_27 ) ) )
return - V_28 ;
V_27 = F_13 ( V_5 , V_27 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( F_14 ( V_20 , & V_27 , sizeof( V_27 ) ) )
return - V_28 ;
return 0 ;
}
case V_29 :
return F_15 ( V_5 , V_19 ) ;
case V_30 :
{
struct V_31 V_32 ;
struct V_4 * V_9 = (struct V_4 * ) V_5 ;
if ( F_12 ( & V_32 , V_20 , sizeof( V_32 ) ) )
return - V_28 ;
V_12 = F_16 ( V_5 , & V_32 . V_33 , V_23 ) ;
if ( V_12 < 0 )
return V_12 ;
V_32 . V_34 . V_35 = V_9 -> V_36 . V_35 ;
V_32 . V_34 . V_36 = V_9 -> V_36 . V_36 ;
if ( F_14 ( V_20 , & V_32 , sizeof( V_32 ) ) )
return - V_28 ;
return 0 ;
}
case V_37 :
{
struct V_38 V_22 ;
T_4 * V_9 = ( T_4 * ) & V_22 . V_39 ;
if ( F_12 ( & V_22 , V_20 , sizeof( V_22 ) ) )
return - V_28 ;
V_12 = F_17 ( V_5 , & V_22 . V_33 , V_9 , V_22 . V_40 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_14 ( V_20 , & V_22 , sizeof( V_22 ) ) ) {
F_4 ( * V_9 ) ;
return - V_28 ;
}
F_6 ( & V_15 . V_41 ) ;
F_18 ( & ( ( * V_9 ) -> V_42 ) , & V_15 . V_43 ) ;
F_18 ( & ( ( * V_9 ) -> V_44 ) , & V_5 -> V_45 ) ;
( * V_9 ) -> V_46 = V_5 ;
V_5 -> V_47 ++ ;
F_8 ( & V_15 . V_41 ) ;
return 0 ;
}
case V_48 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_4 * V_49 ;
struct V_4 * V_50 ;
struct V_4 * V_51 = NULL ;
struct V_4 * V_52 ;
struct V_53 * V_54 , * V_55 ;
if ( F_12 ( & V_49 , V_20 , sizeof( void * ) ) )
return - V_28 ;
F_6 ( & V_15 . V_41 ) ;
F_19 (pos, tmpq, &scif_info.uaccept) {
V_52 = F_20 ( V_54 ,
struct V_4 , V_42 ) ;
if ( V_52 == V_49 ) {
F_21 ( V_54 ) ;
V_51 = V_52 ;
break;
}
}
if ( ! V_51 ) {
F_8 ( & V_15 . V_41 ) ;
return - V_56 ;
}
V_50 = V_49 -> V_46 ;
F_19 (pos, tmpq, &lisep->li_accept) {
V_52 = F_20 ( V_54 ,
struct V_4 , V_44 ) ;
if ( V_52 == V_49 ) {
F_21 ( V_54 ) ;
V_50 -> V_47 -- ;
break;
}
}
F_8 ( & V_15 . V_41 ) ;
F_22 ( V_5 ) ;
F_23 ( V_5 , ! V_57 ) ;
V_3 -> V_7 = V_49 ;
return 0 ;
}
case V_58 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
if ( F_12 ( & V_22 , V_20 ,
sizeof( struct V_21 ) ) ) {
V_12 = - V_28 ;
goto V_59;
}
V_12 = F_24 ( V_5 , ( void T_3 * ) V_22 . V_60 ,
V_22 . V_61 , V_22 . V_40 ) ;
if ( V_12 < 0 )
goto V_59;
if ( F_14 ( &
( (struct V_21 T_3 * ) V_20 ) -> V_62 ,
& V_12 , sizeof( V_12 ) ) ) {
V_12 = - V_28 ;
goto V_59;
}
V_12 = 0 ;
V_59:
F_9 ( V_12 , L_2 ) ;
return V_12 ;
}
case V_63 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
if ( F_12 ( & V_22 , V_20 ,
sizeof( struct V_21 ) ) ) {
V_12 = - V_28 ;
goto V_64;
}
V_12 = F_25 ( V_5 , ( void T_3 * ) V_22 . V_60 ,
V_22 . V_61 , V_22 . V_40 ) ;
if ( V_12 < 0 )
goto V_64;
if ( F_14 ( &
( (struct V_21 T_3 * ) V_20 ) -> V_62 ,
& V_12 , sizeof( V_12 ) ) ) {
V_12 = - V_28 ;
goto V_64;
}
V_12 = 0 ;
V_64:
F_9 ( V_12 , L_3 ) ;
return V_12 ;
}
case V_65 :
{
struct V_66 V_67 ;
int V_68 ;
T_5 * V_69 ;
void T_3 * V_70 , * V_71 ;
T_5 V_34 ;
if ( F_12 ( & V_67 , V_20 , sizeof( V_67 ) ) ) {
V_12 = - V_28 ;
goto V_72;
}
V_68 = F_26 ( int , V_15 . V_73 , V_67 . V_61 ) ;
V_69 = F_27 ( V_68 , sizeof( T_5 ) , V_74 ) ;
if ( V_68 && ! V_69 ) {
V_12 = - V_6 ;
goto V_72;
}
V_67 . V_61 = F_28 ( V_69 , V_68 , & V_34 ) ;
V_70 = ( void T_3 * ) V_67 . V_69 ;
if ( F_14 ( V_70 , V_69 , sizeof( T_5 ) * V_68 ) ) {
V_12 = - V_28 ;
goto V_75;
}
V_71 = ( void T_3 * ) V_67 . V_34 ;
if ( F_14 ( V_71 , & V_34 , sizeof( T_5 ) ) ) {
V_12 = - V_28 ;
goto V_75;
}
if ( F_14 ( V_20 , & V_67 , sizeof( V_67 ) ) ) {
V_12 = - V_28 ;
goto V_75;
}
V_75:
F_29 ( V_69 ) ;
V_72:
return V_12 ;
}
}
return - V_76 ;
}
