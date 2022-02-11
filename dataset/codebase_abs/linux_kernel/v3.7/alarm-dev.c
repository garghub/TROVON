static int F_1 ( enum V_1 type )
{
return ( type == V_2 ||
type == V_3 ) ;
}
static void F_2 ( struct V_4 * V_5 , T_1 exp )
{
if ( F_1 ( V_5 -> type ) )
F_3 ( & V_5 -> V_6 . V_5 , exp ) ;
else
F_4 ( & V_5 -> V_6 . V_7 , exp , V_8 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
if ( F_1 ( V_5 -> type ) )
return F_6 ( & V_5 -> V_6 . V_5 ) ;
return F_7 ( & V_5 -> V_6 . V_7 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
if ( F_1 ( V_5 -> type ) )
F_9 ( & V_5 -> V_6 . V_5 ) ;
else
F_10 ( & V_5 -> V_6 . V_7 ) ;
}
static long F_11 ( struct V_9 * V_9 , unsigned int V_10 , unsigned long V_11 )
{
int V_12 = 0 ;
unsigned long V_13 ;
struct V_14 V_15 ;
struct V_14 V_16 ;
struct V_14 V_17 ;
struct V_18 V_19 ;
struct V_20 * V_21 ;
enum V_1 V_22 = F_12 ( V_10 ) ;
T_2 V_23 = 1U << V_22 ;
if ( V_22 >= V_24 )
return - V_25 ;
if ( F_13 ( V_10 ) != F_14 ( 0 ) ) {
if ( ( V_9 -> V_26 & V_27 ) == V_28 )
return - V_29 ;
if ( V_9 -> V_30 == NULL &&
V_10 != V_31 ) {
F_15 ( & V_32 , V_13 ) ;
if ( V_33 ) {
F_16 ( & V_32 , V_13 ) ;
return - V_34 ;
}
V_33 = 1 ;
V_9 -> V_30 = ( void * ) 1 ;
F_16 ( & V_32 , V_13 ) ;
}
}
switch ( F_13 ( V_10 ) ) {
case F_17 ( 0 ) :
F_15 ( & V_32 , V_13 ) ;
F_18 ( V_35 , L_1 , V_22 ) ;
F_5 ( & V_36 [ V_22 ] ) ;
if ( V_37 ) {
V_37 &= ~ V_23 ;
if ( ! V_37 && ! V_38 )
F_19 ( & V_39 ) ;
}
V_40 &= ~ V_23 ;
F_16 ( & V_32 , V_13 ) ;
break;
case V_41 :
case V_42 :
if ( F_20 ( V_15 . V_43 , ( int V_44 * ) V_11 ) ) {
V_12 = - V_45 ;
goto V_46;
}
V_15 . V_47 = 0 ;
goto V_48;
case F_21 ( 0 ) :
case F_22 ( 0 ) :
if ( F_23 ( & V_15 , ( void V_44 * ) V_11 ,
sizeof( V_15 ) ) ) {
V_12 = - V_45 ;
goto V_46;
}
V_48:
F_15 ( & V_32 , V_13 ) ;
F_18 ( V_35 , L_2 ,
V_22 ,
V_15 . V_43 , V_15 . V_47 ) ;
V_40 |= V_23 ;
F_2 ( & V_36 [ V_22 ] ,
F_24 ( V_15 ) ) ;
F_16 ( & V_32 , V_13 ) ;
if ( F_13 ( V_10 ) != F_21 ( 0 )
&& V_10 != V_42 )
break;
case V_49 :
F_15 ( & V_32 , V_13 ) ;
F_18 ( V_35 , L_3 ) ;
if ( ! V_37 && V_38 ) {
F_19 ( & V_39 ) ;
V_38 = 0 ;
}
F_16 ( & V_32 , V_13 ) ;
V_12 = F_25 ( V_50 , V_37 ) ;
if ( V_12 )
goto V_46;
F_15 ( & V_32 , V_13 ) ;
V_12 = V_37 ;
V_38 = 1 ;
V_37 = 0 ;
F_16 ( & V_32 , V_13 ) ;
break;
case V_31 :
if ( F_23 ( & V_16 , ( void V_44 * ) V_11 ,
sizeof( V_16 ) ) ) {
V_12 = - V_45 ;
goto V_46;
}
F_26 ( V_16 . V_43 , & V_19 ) ;
V_21 = F_27 () ;
V_12 = F_28 ( & V_16 ) ;
if ( V_12 < 0 )
goto V_46;
if ( V_21 )
V_12 = F_29 ( V_21 , & V_19 ) ;
F_15 ( & V_32 , V_13 ) ;
V_37 |= V_51 ;
F_30 ( & V_50 ) ;
F_16 ( & V_32 , V_13 ) ;
if ( V_12 < 0 )
goto V_46;
break;
case F_14 ( 0 ) :
switch ( V_22 ) {
case V_2 :
case V_52 :
F_31 ( & V_17 ) ;
break;
case V_3 :
case V_53 :
F_32 ( & V_17 ) ;
break;
case V_54 :
F_33 ( & V_17 ) ;
break;
default:
V_12 = - V_25 ;
goto V_46;
}
if ( F_34 ( ( void V_44 * ) V_11 , & V_17 ,
sizeof( V_17 ) ) ) {
V_12 = - V_45 ;
goto V_46;
}
break;
default:
V_12 = - V_25 ;
}
V_46:
return V_12 ;
}
static int F_35 ( struct V_55 * V_55 , struct V_9 * V_9 )
{
V_9 -> V_30 = NULL ;
return 0 ;
}
static int F_36 ( struct V_55 * V_55 , struct V_9 * V_9 )
{
int V_56 ;
unsigned long V_13 ;
F_15 ( & V_32 , V_13 ) ;
if ( V_9 -> V_30 ) {
for ( V_56 = 0 ; V_56 < V_24 ; V_56 ++ ) {
T_2 V_23 = 1U << V_56 ;
if ( V_40 & V_23 ) {
F_18 ( V_57 ,
L_4 ,
V_58 ,
! ! ( V_37 & V_23 ) ) ;
V_40 &= ~ V_23 ;
}
F_16 ( & V_32 , V_13 ) ;
F_8 ( & V_36 [ V_56 ] ) ;
F_15 ( & V_32 , V_13 ) ;
}
if ( V_37 | V_38 ) {
if ( V_37 )
F_18 ( V_57 , L_5 ,
V_58 , V_37 ) ;
F_19 ( & V_39 ) ;
V_38 = 0 ;
V_37 = 0 ;
}
V_33 = 0 ;
}
F_16 ( & V_32 , V_13 ) ;
return 0 ;
}
static void F_37 ( struct V_4 * V_59 )
{
unsigned long V_13 ;
T_2 V_23 = 1U << V_59 -> type ;
F_18 ( INT , L_6 , V_58 , V_59 -> type ) ;
F_15 ( & V_32 , V_13 ) ;
if ( V_40 & V_23 ) {
F_38 ( & V_39 , 5000 ) ;
V_40 &= ~ V_23 ;
V_37 |= V_23 ;
F_30 ( & V_50 ) ;
}
F_16 ( & V_32 , V_13 ) ;
}
static enum V_60 F_39 ( struct V_61 * V_7 )
{
struct V_4 * V_62 = F_40 ( V_7 , struct V_4 , V_6 . V_7 ) ;
F_37 ( V_62 ) ;
return V_63 ;
}
static enum V_64 F_41 ( struct V_59 * V_5 ,
T_1 V_65 )
{
struct V_4 * V_62 = F_40 ( V_5 , struct V_4 , V_6 . V_5 ) ;
F_37 ( V_62 ) ;
return V_66 ;
}
static int T_3 F_42 ( void )
{
int V_67 ;
int V_56 ;
V_67 = F_43 ( & V_68 ) ;
if ( V_67 )
return V_67 ;
F_44 ( & V_36 [ V_2 ] . V_6 . V_5 ,
V_69 , F_41 ) ;
F_45 ( & V_36 [ V_52 ] . V_6 . V_7 ,
V_70 , V_8 ) ;
F_44 ( & V_36 [ V_3 ] . V_6 . V_5 ,
V_71 , F_41 ) ;
F_45 ( & V_36 [ V_53 ] . V_6 . V_7 ,
V_72 , V_8 ) ;
F_45 ( & V_36 [ V_54 ] . V_6 . V_7 ,
V_73 , V_8 ) ;
for ( V_56 = 0 ; V_56 < V_24 ; V_56 ++ ) {
V_36 [ V_56 ] . type = V_56 ;
if ( ! F_1 ( V_56 ) )
V_36 [ V_56 ] . V_6 . V_7 . V_74 = F_39 ;
}
F_46 ( & V_39 , L_7 ) ;
return 0 ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_68 ) ;
F_49 ( & V_39 ) ;
}
