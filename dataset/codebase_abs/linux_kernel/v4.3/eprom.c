static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
F_3 ( V_2 , V_3 ) | V_4 ) ;
F_2 ( V_2 , V_5 ,
F_3 ( V_2 , V_5 ) | V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
F_3 ( V_2 , V_3 ) & ~ V_4 ) ;
F_2 ( V_2 , V_5 ,
F_3 ( V_2 , V_5 ) & ~ V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned long V_6 = 0 ;
T_1 V_7 ;
int V_8 = 0 ;
F_2 ( V_2 , V_9 , V_10 ) ;
while ( 1 ) {
F_6 ( V_11 ) ;
F_7 ( V_11 - 5 , V_11 + 5 ) ;
V_6 ++ ;
V_7 = F_3 ( V_2 , V_12 ) ;
if ( ( V_7 & V_13 ) == 0 )
break;
if ( V_6 > F_8 ( 200 ) ) {
F_9 ( V_2 , L_1 ) ;
V_8 = - V_14 ;
break;
}
}
F_2 ( V_2 , V_9 , V_15 ) ;
return V_8 ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_9 , V_16 ) ;
return ( T_2 ) F_3 ( V_2 , V_12 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_8 ;
F_1 ( V_2 ) ;
F_2 ( V_2 , V_9 , V_17 ) ;
F_2 ( V_2 , V_9 , V_18 ) ;
V_8 = F_5 ( V_2 ) ;
F_4 ( V_2 ) ;
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_20 )
{
int V_8 = 0 ;
if ( V_20 < V_19 )
return - V_21 ;
if ( ( V_19 & V_22 ) || ( V_20 & V_22 ) ) {
F_9 ( V_2 ,
L_2 ,
V_23 , V_19 , V_20 ) ;
return - V_21 ;
}
F_1 ( V_2 ) ;
for (; V_19 < V_20 ; V_19 += V_24 ) {
F_2 ( V_2 , V_9 , V_17 ) ;
F_2 ( V_2 , V_9 ,
F_13 ( V_19 ) ) ;
V_8 = F_5 ( V_2 ) ;
if ( V_8 )
goto V_25;
}
V_25:
F_4 ( V_2 ) ;
return V_8 ;
}
static void F_14 ( struct V_1 * V_2 , T_2 V_26 , T_2 * V_27 )
{
int V_28 ;
F_2 ( V_2 , V_9 , F_15 ( V_26 ) ) ;
for ( V_28 = 0 ; V_28 < V_29 / sizeof( T_2 ) ; V_28 ++ )
V_27 [ V_28 ] = ( T_2 ) F_3 ( V_2 , V_12 ) ;
F_2 ( V_2 , V_9 , V_15 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_30 , T_1 V_31 )
{
T_2 V_26 ;
T_2 V_32 [ V_29 / sizeof( T_2 ) ] ;
int V_8 = 0 ;
if ( ( V_19 & V_33 ) || ( V_30 & V_33 ) )
return - V_21 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 += V_29 ) {
F_14 ( V_2 , V_19 + V_26 , V_32 ) ;
if ( F_17 ( ( void V_34 * ) ( V_31 + V_26 ) ,
V_32 , V_29 ) ) {
V_8 = - V_35 ;
goto V_25;
}
}
V_25:
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_26 , T_2 * V_36 )
{
int V_28 ;
F_2 ( V_2 , V_9 , V_17 ) ;
F_2 ( V_2 , V_12 , V_36 [ 0 ] ) ;
F_2 ( V_2 , V_9 , F_19 ( V_26 ) ) ;
for ( V_28 = 1 ; V_28 < V_29 / sizeof( T_2 ) ; V_28 ++ )
F_2 ( V_2 , V_12 , V_36 [ V_28 ] ) ;
return F_5 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_30 , T_1 V_31 )
{
T_2 V_26 ;
T_2 V_32 [ V_29 / sizeof( T_2 ) ] ;
int V_8 = 0 ;
if ( ( V_19 & V_33 ) || ( V_30 & V_33 ) )
return - V_21 ;
F_1 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 += V_29 ) {
if ( F_21 ( V_32 , ( void V_34 * ) ( V_31 + V_26 ) ,
V_29 ) ) {
V_8 = - V_35 ;
goto V_25;
}
V_8 = F_18 ( V_2 , V_19 + V_26 , V_32 ) ;
if ( V_8 )
goto V_25;
}
V_25:
F_4 ( V_2 ) ;
return V_8 ;
}
int F_22 ( const struct V_37 * V_38 )
{
struct V_1 * V_2 ;
T_2 V_39 ;
int V_8 = 0 ;
V_2 = F_23 ( 0 ) ;
if ( ! V_2 ) {
F_24 ( L_3 , V_23 ) ;
return - V_21 ;
}
F_25 ( & V_40 ) ;
if ( ! V_41 ) {
V_8 = - V_42 ;
goto V_43;
}
V_8 = F_26 ( V_2 ) ;
if ( V_8 ) {
F_9 ( V_2 ,
L_4 ,
V_23 ) ;
goto V_43;
}
F_27 ( V_2 , L_5 ,
V_23 , V_38 -> type , V_38 -> V_30 , V_38 -> V_31 ) ;
switch ( V_38 -> type ) {
case V_44 :
if ( V_38 -> V_30 != sizeof( T_2 ) ) {
V_8 = - V_45 ;
break;
}
V_39 = F_10 ( V_2 ) ;
if ( F_17 ( ( void V_34 * ) V_38 -> V_31 , & V_39 ,
sizeof( T_2 ) ) )
V_8 = - V_35 ;
break;
case V_46 :
V_8 = F_11 ( V_2 ) ;
break;
case V_47 :
if ( V_38 -> V_30 != V_48 ) {
V_8 = - V_45 ;
break;
}
V_8 = F_12 ( V_2 , 0 , V_38 -> V_30 ) ;
break;
case V_49 :
if ( V_50 + V_38 -> V_30 > V_51 ) {
V_8 = - V_45 ;
break;
}
V_8 = F_12 ( V_2 , V_50 , V_50 + V_38 -> V_30 ) ;
break;
case V_52 :
if ( V_38 -> V_30 != V_48 ) {
V_8 = - V_45 ;
break;
}
V_8 = F_16 ( V_2 , 0 , V_38 -> V_30 , V_38 -> V_31 ) ;
break;
case V_53 :
if ( V_50 + V_38 -> V_30 > V_51 ) {
V_8 = - V_45 ;
break;
}
V_8 = F_16 ( V_2 , V_50 , V_38 -> V_30 , V_38 -> V_31 ) ;
break;
case V_54 :
if ( V_38 -> V_30 > V_48 ) {
V_8 = - V_45 ;
break;
}
V_8 = F_20 ( V_2 , 0 , V_38 -> V_30 , V_38 -> V_31 ) ;
break;
case V_55 :
if ( V_50 + V_38 -> V_30 > V_51 ) {
V_8 = - V_45 ;
break;
}
V_8 = F_20 ( V_2 , V_50 , V_38 -> V_30 , V_38 -> V_31 ) ;
break;
default:
F_9 ( V_2 , L_6 ,
V_23 , V_38 -> type ) ;
V_8 = - V_21 ;
break;
}
F_28 ( V_2 ) ;
V_43:
F_29 ( & V_40 ) ;
return V_8 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( V_2 -> V_56 -> V_57 != V_58 )
return 0 ;
F_25 ( & V_40 ) ;
if ( V_41 )
goto V_43;
V_8 = F_26 ( V_2 ) ;
if ( V_8 ) {
F_9 ( V_2 ,
L_4 ,
V_23 ) ;
goto V_43;
}
F_2 ( V_2 , V_59 ,
V_60 ) ;
F_2 ( V_2 , V_59 ,
V_61 << V_62 ) ;
F_2 ( V_2 , V_9 , V_63 ) ;
V_41 = 1 ;
F_28 ( V_2 ) ;
V_43:
F_29 ( & V_40 ) ;
return V_8 ;
}
