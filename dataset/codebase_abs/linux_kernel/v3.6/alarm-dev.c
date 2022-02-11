static int F_1 ( enum V_1 type )
{
if ( type == V_2 ||
type == V_3 )
return 1 ;
return 0 ;
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
int V_9 ;
if ( F_1 ( V_5 -> type ) )
V_9 = F_6 ( & V_5 -> V_6 . V_5 ) ;
else
V_9 = F_7 ( & V_5 -> V_6 . V_7 ) ;
return V_9 ;
}
static void F_8 ( struct V_4 * V_5 )
{
if ( F_1 ( V_5 -> type ) )
F_9 ( & V_5 -> V_6 . V_5 ) ;
else
F_10 ( & V_5 -> V_6 . V_7 ) ;
}
static long F_11 ( struct V_10 * V_10 , unsigned int V_11 , unsigned long V_12 )
{
int V_13 = 0 ;
unsigned long V_14 ;
struct V_15 V_16 ;
struct V_15 V_17 ;
struct V_15 V_18 ;
struct V_19 V_20 ;
struct V_21 * V_22 ;
enum V_1 V_23 = F_12 ( V_11 ) ;
T_2 V_24 = 1U << V_23 ;
if ( V_23 >= V_25 )
return - V_26 ;
if ( F_13 ( V_11 ) != F_14 ( 0 ) ) {
if ( ( V_10 -> V_27 & V_28 ) == V_29 )
return - V_30 ;
if ( V_10 -> V_31 == NULL &&
V_11 != V_32 ) {
F_15 ( & V_33 , V_14 ) ;
if ( V_34 ) {
F_16 ( & V_33 , V_14 ) ;
return - V_35 ;
}
V_34 = 1 ;
V_10 -> V_31 = ( void * ) 1 ;
F_16 ( & V_33 , V_14 ) ;
}
}
switch ( F_13 ( V_11 ) ) {
case F_17 ( 0 ) :
F_15 ( & V_33 , V_14 ) ;
F_18 ( V_36 , L_1 , V_23 ) ;
F_5 ( & V_37 [ V_23 ] ) ;
if ( V_38 ) {
V_38 &= ~ V_24 ;
if ( ! V_38 && ! V_39 )
F_19 ( & V_40 ) ;
}
V_41 &= ~ V_24 ;
F_16 ( & V_33 , V_14 ) ;
break;
case V_42 :
case V_43 :
if ( F_20 ( V_16 . V_44 , ( int V_45 * ) V_12 ) ) {
V_13 = - V_46 ;
goto V_47;
}
V_16 . V_48 = 0 ;
goto V_49;
case F_21 ( 0 ) :
case F_22 ( 0 ) :
if ( F_23 ( & V_16 , ( void V_45 * ) V_12 ,
sizeof( V_16 ) ) ) {
V_13 = - V_46 ;
goto V_47;
}
V_49:
F_15 ( & V_33 , V_14 ) ;
F_18 ( V_36 , L_2 ,
V_23 ,
V_16 . V_44 , V_16 . V_48 ) ;
V_41 |= V_24 ;
F_2 ( & V_37 [ V_23 ] ,
F_24 ( V_16 ) ) ;
F_16 ( & V_33 , V_14 ) ;
if ( F_13 ( V_11 ) != F_21 ( 0 )
&& V_11 != V_43 )
break;
case V_50 :
F_15 ( & V_33 , V_14 ) ;
F_18 ( V_36 , L_3 ) ;
if ( ! V_38 && V_39 ) {
F_19 ( & V_40 ) ;
V_39 = 0 ;
}
F_16 ( & V_33 , V_14 ) ;
V_13 = F_25 ( V_51 , V_38 ) ;
if ( V_13 )
goto V_47;
F_15 ( & V_33 , V_14 ) ;
V_13 = V_38 ;
V_39 = 1 ;
V_38 = 0 ;
F_16 ( & V_33 , V_14 ) ;
break;
case V_32 :
if ( F_23 ( & V_17 , ( void V_45 * ) V_12 ,
sizeof( V_17 ) ) ) {
V_13 = - V_46 ;
goto V_47;
}
F_26 ( V_17 . V_44 , & V_20 ) ;
V_22 = F_27 () ;
V_13 = F_28 ( & V_17 ) ;
if ( V_13 < 0 )
goto V_47;
if ( V_22 )
V_13 = F_29 ( V_22 , & V_20 ) ;
F_15 ( & V_33 , V_14 ) ;
V_38 |= V_52 ;
F_30 ( & V_51 ) ;
F_16 ( & V_33 , V_14 ) ;
if ( V_13 < 0 )
goto V_47;
break;
case F_14 ( 0 ) :
switch ( V_23 ) {
case V_2 :
case V_53 :
F_31 ( & V_18 ) ;
break;
case V_3 :
case V_54 :
F_32 ( & V_18 ) ;
break;
case V_25 :
case V_55 :
F_33 ( & V_18 ) ;
break;
}
if ( F_34 ( ( void V_45 * ) V_12 , & V_18 ,
sizeof( V_18 ) ) ) {
V_13 = - V_46 ;
goto V_47;
}
break;
default:
V_13 = - V_26 ;
}
V_47:
return V_13 ;
}
static int F_35 ( struct V_56 * V_56 , struct V_10 * V_10 )
{
V_10 -> V_31 = NULL ;
return 0 ;
}
static int F_36 ( struct V_56 * V_56 , struct V_10 * V_10 )
{
int V_57 ;
unsigned long V_14 ;
F_15 ( & V_33 , V_14 ) ;
if ( V_10 -> V_31 ) {
for ( V_57 = 0 ; V_57 < V_25 ; V_57 ++ ) {
T_2 V_24 = 1U << V_57 ;
if ( V_41 & V_24 ) {
F_18 ( V_58 ,
L_4 ,
V_59 ,
! ! ( V_38 & V_24 ) ) ;
V_41 &= ~ V_24 ;
}
F_16 ( & V_33 , V_14 ) ;
F_8 ( & V_37 [ V_57 ] ) ;
F_15 ( & V_33 , V_14 ) ;
}
if ( V_38 | V_39 ) {
if ( V_38 )
F_18 ( V_58 , L_5 ,
V_59 , V_38 ) ;
F_19 ( & V_40 ) ;
V_39 = 0 ;
V_38 = 0 ;
}
V_34 = 0 ;
}
F_16 ( & V_33 , V_14 ) ;
return 0 ;
}
static void F_37 ( struct V_4 * V_60 )
{
unsigned long V_14 ;
T_2 V_24 = 1U << V_60 -> type ;
F_18 ( INT , L_6 , V_59 , V_60 -> type ) ;
F_15 ( & V_33 , V_14 ) ;
if ( V_41 & V_24 ) {
F_38 ( & V_40 , 5000 ) ;
V_41 &= ~ V_24 ;
V_38 |= V_24 ;
F_30 ( & V_51 ) ;
}
F_16 ( & V_33 , V_14 ) ;
}
static enum V_61 F_39 ( struct V_62 * V_7 )
{
struct V_4 * V_63 = F_40 ( V_7 , struct V_4 , V_6 . V_7 ) ;
F_37 ( V_63 ) ;
return V_64 ;
}
static enum V_65 F_41 ( struct V_60 * V_5 ,
T_1 V_66 )
{
struct V_4 * V_63 = F_40 ( V_5 , struct V_4 , V_6 . V_5 ) ;
F_37 ( V_63 ) ;
return V_67 ;
}
static int T_3 F_42 ( void )
{
int V_68 ;
int V_57 ;
V_68 = F_43 ( & V_69 ) ;
if ( V_68 )
return V_68 ;
F_44 ( & V_37 [ V_2 ] . V_6 . V_5 ,
V_70 , F_41 ) ;
F_45 ( & V_37 [ V_53 ] . V_6 . V_7 ,
V_71 , V_8 ) ;
F_44 ( & V_37 [ V_3 ] . V_6 . V_5 ,
V_72 , F_41 ) ;
F_45 ( & V_37 [ V_54 ] . V_6 . V_7 ,
V_73 , V_8 ) ;
F_45 ( & V_37 [ V_55 ] . V_6 . V_7 ,
V_74 , V_8 ) ;
for ( V_57 = 0 ; V_57 < V_25 ; V_57 ++ ) {
V_37 [ V_57 ] . type = V_57 ;
if ( ! F_1 ( V_57 ) )
V_37 [ V_57 ] . V_6 . V_7 . V_75 = F_39 ;
}
F_46 ( & V_40 , L_7 ) ;
return 0 ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_69 ) ;
F_49 ( & V_40 ) ;
}
