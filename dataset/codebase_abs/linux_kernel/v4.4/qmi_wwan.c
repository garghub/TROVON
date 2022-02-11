static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_4 -> V_6 < V_2 -> V_7 -> V_8 )
return 0 ;
switch ( V_4 -> V_9 [ 0 ] & 0xf0 ) {
case 0x40 :
V_5 = F_2 ( V_10 ) ;
break;
case 0x60 :
V_5 = F_2 ( V_11 ) ;
break;
case 0x00 :
if ( F_3 ( V_4 -> V_9 ) )
return 1 ;
F_4 ( V_4 ) ;
goto V_12;
default:
return 1 ;
}
if ( F_5 ( V_4 ) < V_13 )
return 0 ;
F_6 ( V_4 , V_13 ) ;
F_4 ( V_4 ) ;
F_7 ( V_4 ) -> V_14 = V_5 ;
F_8 ( F_7 ( V_4 ) -> V_15 ) ;
V_12:
memcpy ( F_7 ( V_4 ) -> V_16 , V_2 -> V_7 -> V_17 , V_18 ) ;
return 1 ;
}
static bool F_9 ( const char * V_9 )
{
return ( V_9 [ 0 ] & 0xd0 ) == 0x40 ;
}
static int F_10 ( struct V_19 * V_2 , void * V_20 )
{
int V_21 ;
struct V_22 * V_23 = V_20 ;
V_21 = F_11 ( V_2 , V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( F_9 ( V_23 -> V_24 ) )
return - V_25 ;
F_12 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_26 )
{
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
int V_29 ;
F_14 ( & V_2 -> V_30 -> V_2 , L_1 , V_31 ,
F_15 ( & V_28 -> V_32 ) , V_26 ) ;
if ( ( V_26 && F_16 ( 1 , & V_28 -> V_32 ) == 1 ) ||
( ! V_26 && F_17 ( & V_28 -> V_32 ) ) ) {
V_29 = F_18 ( V_2 -> V_30 ) ;
V_2 -> V_30 -> V_33 = V_26 ;
if ( ! V_29 )
F_19 ( V_2 -> V_30 ) ;
}
return 0 ;
}
static int F_20 ( struct V_34 * V_30 , int V_26 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
if ( ! V_2 )
return 0 ;
return F_13 ( V_2 , V_26 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_35 * V_36 = NULL ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
V_29 = F_23 ( V_2 , V_28 -> V_9 ) ;
if ( V_29 < 0 )
goto V_37;
if ( V_28 -> V_38 != V_28 -> V_9 )
V_2 -> V_39 = & V_28 -> V_38 -> V_40 -> V_41 [ 0 ] ;
if ( ! V_2 -> V_39 ) {
V_29 = - V_42 ;
goto V_37;
}
F_24 ( & V_28 -> V_32 , 0 ) ;
V_36 = F_25 ( V_28 -> V_38 , & V_2 -> V_39 -> V_43 ,
4096 , & F_20 ) ;
if ( F_26 ( V_36 ) ) {
F_27 ( & V_28 -> V_38 -> V_2 , L_2 ) ;
V_29 = F_28 ( V_36 ) ;
goto V_37;
}
V_2 -> V_39 = NULL ;
V_28 -> V_36 = V_36 ;
V_37:
return V_29 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_34 * V_30 )
{
int V_39 = - 1 ;
T_2 * V_44 = V_30 -> V_40 -> V_45 ;
int V_6 = V_30 -> V_40 -> V_46 ;
struct V_47 * V_43 = & V_30 -> V_40 -> V_43 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_35 * V_52 = F_30 ( V_30 ) ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
struct V_53 V_54 ;
F_31 ( ( sizeof( ( (struct V_1 * ) 0 ) -> V_9 ) <
sizeof( struct V_27 ) ) ) ;
V_28 -> V_38 = V_30 ;
V_28 -> V_9 = V_30 ;
F_32 ( & V_54 , V_30 , V_44 , V_6 ) ;
V_49 = V_54 . V_48 ;
V_51 = V_54 . V_50 ;
if ( V_49 ) {
V_28 -> V_9 = F_33 ( V_2 -> V_55 ,
V_49 -> V_56 ) ;
if ( V_43 -> V_57 != V_49 -> V_58 ||
! V_28 -> V_9 ) {
F_27 ( & V_30 -> V_2 ,
L_3 ,
V_49 -> V_58 ,
V_49 -> V_56 ) ;
goto V_37;
}
}
if ( V_51 ) {
V_2 -> V_59 = F_34 ( V_51 -> V_60 ) ;
F_35 ( V_2 , V_51 -> V_61 ) ;
}
if ( V_28 -> V_38 != V_28 -> V_9 ) {
V_39 = F_36 ( V_52 , V_28 -> V_9 , V_2 ) ;
if ( V_39 < 0 )
goto V_37;
}
V_39 = F_22 ( V_2 ) ;
if ( V_39 < 0 && V_28 -> V_38 != V_28 -> V_9 ) {
F_37 ( V_28 -> V_9 , NULL ) ;
F_38 ( V_52 , V_28 -> V_9 ) ;
}
if ( F_39 ( V_2 -> V_7 -> V_17 , V_62 ) ||
F_39 ( V_2 -> V_7 -> V_17 , V_63 ) )
F_40 ( V_2 -> V_7 ) ;
if ( F_9 ( V_2 -> V_7 -> V_17 ) ) {
V_2 -> V_7 -> V_17 [ 0 ] |= 0x02 ;
V_2 -> V_7 -> V_17 [ 0 ] &= 0xbf ;
}
V_2 -> V_7 -> V_64 = & V_65 ;
V_37:
return V_39 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_34 * V_30 )
{
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
struct V_35 * V_52 = F_30 ( V_30 ) ;
struct V_34 * V_66 ;
if ( V_28 -> V_36 && V_28 -> V_36 -> V_67 )
V_28 -> V_36 -> V_67 ( V_28 -> V_38 ) ;
if ( V_30 == V_28 -> V_38 )
V_66 = V_28 -> V_9 ;
else
V_66 = V_28 -> V_38 ;
if ( V_66 && V_30 != V_66 ) {
F_37 ( V_66 , NULL ) ;
F_38 ( V_52 , V_66 ) ;
}
V_28 -> V_36 = NULL ;
V_28 -> V_9 = NULL ;
V_28 -> V_38 = NULL ;
}
static int F_42 ( struct V_34 * V_30 , T_3 V_68 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
int V_21 ;
V_21 = F_43 ( V_30 , V_68 ) ;
if ( V_21 < 0 )
goto V_37;
if ( V_30 == V_28 -> V_38 && V_28 -> V_36 &&
V_28 -> V_36 -> V_69 )
V_21 = V_28 -> V_36 -> V_69 ( V_30 , V_68 ) ;
if ( V_21 < 0 )
F_44 ( V_30 ) ;
V_37:
return V_21 ;
}
static int F_45 ( struct V_34 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
int V_21 = 0 ;
bool V_70 = ( V_30 == V_28 -> V_38 && V_28 -> V_36 &&
V_28 -> V_36 -> V_71 ) ;
if ( V_70 )
V_21 = V_28 -> V_36 -> V_71 ( V_30 ) ;
if ( V_21 < 0 )
goto V_37;
V_21 = F_44 ( V_30 ) ;
if ( V_21 < 0 && V_70 )
V_28 -> V_36 -> V_69 ( V_30 , V_72 ) ;
V_37:
return V_21 ;
}
static bool F_46 ( struct V_34 * V_30 )
{
struct V_73 * V_2 = F_47 ( V_30 ) ;
if ( V_2 -> V_74 &&
F_34 ( V_2 -> V_75 . V_76 ) == 0x05c6 &&
F_34 ( V_2 -> V_75 . V_77 ) == 0x9215 &&
V_2 -> V_74 -> V_43 . V_78 == 5 )
return true ;
return false ;
}
static int F_48 ( struct V_34 * V_30 ,
const struct V_79 * V_80 )
{
struct V_79 * V_81 = (struct V_79 * ) V_80 ;
struct V_47 * V_43 = & V_30 -> V_40 -> V_43 ;
if ( ! V_81 -> V_82 ) {
F_14 ( & V_30 -> V_2 , L_4 ) ;
V_81 -> V_82 = ( unsigned long ) & V_83 ;
}
if ( F_46 ( V_30 ) && V_43 -> V_57 == 0 ) {
F_14 ( & V_30 -> V_2 , L_5 ) ;
return - V_84 ;
}
return F_49 ( V_30 , V_81 ) ;
}
