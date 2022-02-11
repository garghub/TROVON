static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = - 1 ;
struct V_3 * V_6 = NULL ;
T_1 * V_7 = V_4 -> V_8 -> V_9 ;
int V_10 = V_4 -> V_8 -> V_11 ;
struct V_12 * V_13 = & V_4 -> V_8 -> V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 = NULL ;
T_2 V_18 = 1 << V_19 | 1 << V_20 ;
T_2 V_21 = 0 ;
T_3 * V_22 = ( void * ) & V_2 -> V_23 [ 1 ] ;
F_2 ( V_22 , 0 ) ;
if ( V_10 == 0 && V_13 -> V_24 > 0 ) {
V_6 = F_3 ( V_2 -> V_25 , V_13 -> V_24 - 1 ) ;
if ( ! V_6 )
goto V_26;
V_7 = V_6 -> V_8 -> V_9 ;
V_10 = V_6 -> V_8 -> V_11 ;
F_4 ( & V_4 -> V_2 , L_1 ,
F_5 ( & V_6 -> V_2 ) ) ;
}
while ( V_10 > 3 ) {
struct V_27 * V_28 = ( void * ) V_7 ;
if ( V_28 -> V_29 != V_30 )
goto V_31;
switch ( V_7 [ 2 ] ) {
case V_19 :
if ( V_21 & 1 << V_19 ) {
F_4 ( & V_4 -> V_2 , L_2 ) ;
goto V_26;
}
if ( V_28 -> V_32 != sizeof( struct V_33 ) ) {
F_4 ( & V_4 -> V_2 , L_3 , V_28 -> V_32 ) ;
goto V_26;
}
break;
case V_20 :
if ( V_21 & 1 << V_20 ) {
F_4 ( & V_4 -> V_2 , L_4 ) ;
goto V_26;
}
if ( V_28 -> V_32 != sizeof( struct V_14 ) ) {
F_4 ( & V_4 -> V_2 , L_5 , V_28 -> V_32 ) ;
goto V_26;
}
V_15 = (struct V_14 * ) V_7 ;
break;
case V_34 :
if ( V_21 & 1 << V_34 ) {
F_4 ( & V_4 -> V_2 , L_6 ) ;
goto V_26;
}
if ( V_28 -> V_32 != sizeof( struct V_16 ) ) {
F_4 ( & V_4 -> V_2 , L_7 , V_28 -> V_32 ) ;
goto V_26;
}
V_17 = (struct V_16 * ) V_7 ;
break;
}
if ( V_7 [ 2 ] < 32 )
V_21 |= 1 << V_7 [ 2 ] ;
V_31:
V_10 -= V_28 -> V_32 ;
V_7 += V_28 -> V_32 ;
}
if ( ( V_21 & V_18 ) != V_18 ) {
F_6 ( & V_4 -> V_2 , L_8 ) ;
goto V_26;
}
if ( V_15 && V_13 -> V_24 == V_15 -> V_35 ) {
F_6 ( & V_4 -> V_2 , L_9 V_36 L_10 ,
F_5 ( & F_3 ( V_2 -> V_25 , V_15 -> V_37 ) -> V_2 ) ) ;
goto V_26;
}
if ( V_17 ) {
V_2 -> V_38 = F_7 ( V_17 -> V_39 ) ;
F_8 ( V_2 , V_17 -> V_40 ) ;
}
if ( V_6 )
F_9 ( & V_4 -> V_2 , L_11 V_36 L_12 ,
F_5 ( & V_6 -> V_2 ) ) ;
V_5 = F_10 ( V_2 , V_4 ) ;
V_26:
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 , int V_41 )
{
T_3 * V_22 = ( void * ) & V_2 -> V_23 [ 1 ] ;
int V_42 = 0 ;
F_4 ( & V_2 -> V_4 -> V_2 , L_13 , V_43 , F_12 ( V_22 ) , V_41 ) ;
if ( ( V_41 && F_13 ( 1 , V_22 ) == 1 ) || ( ! V_41 && F_14 ( V_22 ) ) ) {
V_42 = F_15 ( V_2 -> V_4 ) ;
if ( V_42 < 0 )
goto V_26;
V_2 -> V_4 -> V_44 = V_41 ;
F_16 ( V_2 -> V_4 ) ;
}
V_26:
return V_42 ;
}
static int F_17 ( struct V_3 * V_4 , int V_41 )
{
struct V_1 * V_2 = F_18 ( V_4 ) ;
if ( ! V_2 )
return 0 ;
return F_11 ( V_2 , V_41 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_42 ;
struct V_45 * V_46 = NULL ;
T_3 * V_22 = ( void * ) & V_2 -> V_23 [ 1 ] ;
if ( V_2 -> V_47 -> V_23 &&
! F_20 ( V_4 -> V_8 -> V_13 . V_24 , & V_2 -> V_47 -> V_23 ) ) {
F_9 ( & V_4 -> V_2 , L_14 ) ;
V_42 = - V_48 ;
goto V_26;
}
F_2 ( V_22 , 0 ) ;
V_42 = F_10 ( V_2 , V_4 ) ;
if ( V_42 < 0 )
goto V_26;
if ( ! V_2 -> V_5 ) {
V_42 = - V_49 ;
goto V_26;
}
V_46 = F_21 ( V_4 , & V_2 -> V_5 -> V_13 , 512 , & F_17 ) ;
if ( F_22 ( V_46 ) ) {
V_42 = F_23 ( V_46 ) ;
goto V_26;
}
V_2 -> V_5 = NULL ;
V_2 -> V_23 [ 0 ] = ( unsigned long ) V_46 ;
V_26:
return V_42 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_45 * V_46 = ( void * ) V_2 -> V_23 [ 0 ] ;
if ( V_46 && V_46 -> V_50 )
V_46 -> V_50 ( V_4 ) ;
V_2 -> V_23 [ 0 ] = ( unsigned long ) NULL ;
}
static int F_25 ( struct V_3 * V_4 , T_4 V_51 )
{
struct V_1 * V_2 = F_18 ( V_4 ) ;
struct V_45 * V_46 = ( void * ) V_2 -> V_23 [ 0 ] ;
int V_52 ;
V_52 = F_26 ( V_4 , V_51 ) ;
if ( V_52 < 0 )
goto V_26;
if ( V_46 && V_46 -> V_53 )
V_52 = V_46 -> V_53 ( V_4 , V_51 ) ;
if ( V_52 < 0 )
F_27 ( V_4 ) ;
V_26:
return V_52 ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_18 ( V_4 ) ;
struct V_45 * V_46 = ( void * ) V_2 -> V_23 [ 0 ] ;
int V_52 = 0 ;
if ( V_46 && V_46 -> V_54 )
V_52 = V_46 -> V_54 ( V_4 ) ;
if ( V_52 < 0 )
goto V_26;
V_52 = F_27 ( V_4 ) ;
if ( V_52 < 0 && V_46 && V_46 -> V_54 && V_46 -> V_53 )
V_46 -> V_53 ( V_4 , V_55 ) ;
V_26:
return V_52 ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_56 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_56 ) ;
}
