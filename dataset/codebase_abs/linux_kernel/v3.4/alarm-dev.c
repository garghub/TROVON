static long F_1 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
int V_4 = 0 ;
unsigned long V_5 ;
struct V_6 V_7 ;
struct V_6 V_8 ;
struct V_6 V_9 ;
enum V_10 V_11 = F_2 ( V_2 ) ;
T_1 V_12 = 1U << V_11 ;
if ( V_11 >= V_13 )
return - V_14 ;
if ( F_3 ( V_2 ) != F_4 ( 0 ) ) {
if ( ( V_1 -> V_15 & V_16 ) == V_17 )
return - V_18 ;
if ( V_1 -> V_19 == NULL &&
V_2 != V_20 ) {
F_5 ( & V_21 , V_5 ) ;
if ( V_22 ) {
F_6 ( & V_21 , V_5 ) ;
return - V_23 ;
}
V_22 = 1 ;
V_1 -> V_19 = ( void * ) 1 ;
F_6 ( & V_21 , V_5 ) ;
}
}
switch ( F_3 ( V_2 ) ) {
case F_7 ( 0 ) :
F_5 ( & V_21 , V_5 ) ;
F_8 ( V_24 , L_1 , V_11 ) ;
F_9 ( & V_25 [ V_11 ] ) ;
if ( V_26 ) {
V_26 &= ~ V_12 ;
if ( ! V_26 && ! V_27 )
F_10 ( & V_28 ) ;
}
V_29 &= ~ V_12 ;
F_6 ( & V_21 , V_5 ) ;
break;
case V_30 :
case V_31 :
if ( F_11 ( V_7 . V_32 , ( int V_33 * ) V_3 ) ) {
V_4 = - V_34 ;
goto V_35;
}
V_7 . V_36 = 0 ;
goto V_37;
case F_12 ( 0 ) :
case F_13 ( 0 ) :
if ( F_14 ( & V_7 , ( void V_33 * ) V_3 ,
sizeof( V_7 ) ) ) {
V_4 = - V_34 ;
goto V_35;
}
V_37:
F_5 ( & V_21 , V_5 ) ;
F_8 ( V_24 , L_2 , V_11 ,
V_7 . V_32 , V_7 . V_36 ) ;
V_29 |= V_12 ;
F_15 ( & V_25 [ V_11 ] ,
F_16 ( V_7 ) ,
F_16 ( V_7 ) ) ;
F_6 ( & V_21 , V_5 ) ;
if ( F_3 ( V_2 ) != F_12 ( 0 )
&& V_2 != V_31 )
break;
case V_38 :
F_5 ( & V_21 , V_5 ) ;
F_8 ( V_24 , L_3 ) ;
if ( ! V_26 && V_27 ) {
F_10 ( & V_28 ) ;
V_27 = 0 ;
}
F_6 ( & V_21 , V_5 ) ;
V_4 = F_17 ( V_39 , V_26 ) ;
if ( V_4 )
goto V_35;
F_5 ( & V_21 , V_5 ) ;
V_4 = V_26 ;
V_27 = 1 ;
V_26 = 0 ;
F_6 ( & V_21 , V_5 ) ;
break;
case V_20 :
if ( F_14 ( & V_8 , ( void V_33 * ) V_3 ,
sizeof( V_8 ) ) ) {
V_4 = - V_34 ;
goto V_35;
}
V_4 = F_18 ( V_8 ) ;
F_5 ( & V_21 , V_5 ) ;
V_26 |= V_40 ;
F_19 ( & V_39 ) ;
F_6 ( & V_21 , V_5 ) ;
if ( V_4 < 0 )
goto V_35;
break;
case F_4 ( 0 ) :
switch ( V_11 ) {
case V_41 :
case V_42 :
F_20 ( & V_9 ) ;
break;
case V_43 :
case V_44 :
V_9 =
F_21 ( F_22 () ) ;
break;
case V_13 :
case V_45 :
F_23 ( & V_9 ) ;
break;
}
if ( F_24 ( ( void V_33 * ) V_3 , & V_9 ,
sizeof( V_9 ) ) ) {
V_4 = - V_34 ;
goto V_35;
}
break;
default:
V_4 = - V_14 ;
goto V_35;
}
V_35:
return V_4 ;
}
static int F_25 ( struct V_46 * V_46 , struct V_1 * V_1 )
{
V_1 -> V_19 = NULL ;
return 0 ;
}
static int F_26 ( struct V_46 * V_46 , struct V_1 * V_1 )
{
int V_47 ;
unsigned long V_5 ;
F_5 ( & V_21 , V_5 ) ;
if ( V_1 -> V_19 != 0 ) {
for ( V_47 = 0 ; V_47 < V_13 ; V_47 ++ ) {
T_1 V_12 = 1U << V_47 ;
if ( V_29 & V_12 ) {
F_8 ( V_48 , L_4
L_5 ,
! ! ( V_26 & V_12 ) ) ;
V_29 &= ~ V_12 ;
}
F_6 ( & V_21 , V_5 ) ;
F_27 ( & V_25 [ V_47 ] ) ;
F_5 ( & V_21 , V_5 ) ;
}
if ( V_26 | V_27 ) {
if ( V_26 )
F_8 ( V_48 , L_6
L_7 , V_26 ) ;
F_10 ( & V_28 ) ;
V_27 = 0 ;
V_26 = 0 ;
}
V_22 = 0 ;
}
F_6 ( & V_21 , V_5 ) ;
return 0 ;
}
static void F_28 ( struct V_49 * V_50 )
{
unsigned long V_5 ;
T_1 V_12 = 1U << V_50 -> type ;
F_8 ( INT , L_8 , V_50 -> type ) ;
F_5 ( & V_21 , V_5 ) ;
if ( V_29 & V_12 ) {
F_29 ( & V_28 , 5 * V_51 ) ;
V_29 &= ~ V_12 ;
V_26 |= V_12 ;
F_19 ( & V_39 ) ;
}
F_6 ( & V_21 , V_5 ) ;
}
static int T_2 F_30 ( void )
{
int V_52 ;
int V_47 ;
V_52 = F_31 ( & V_53 ) ;
if ( V_52 )
return V_52 ;
for ( V_47 = 0 ; V_47 < V_13 ; V_47 ++ )
F_32 ( & V_25 [ V_47 ] , V_47 , F_28 ) ;
F_33 ( & V_28 , V_54 , L_9 ) ;
return 0 ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_53 ) ;
F_36 ( & V_28 ) ;
}
