static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , F_3 ( V_2 , V_3 ) | V_4 ) ;
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) | V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , F_3 ( V_2 , V_3 ) & ~ V_4 ) ;
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) & ~ V_4 ) ;
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
T_2 V_21 = V_19 + V_20 ;
int V_8 = 0 ;
if ( V_21 < V_19 )
return - V_22 ;
if ( ( V_19 & V_23 ) || ( V_21 & V_23 ) ) {
F_9 ( V_2 ,
L_2 ,
V_24 , V_19 , V_21 ) ;
return - V_22 ;
}
F_1 ( V_2 ) ;
while ( V_19 < V_21 ) {
F_2 ( V_2 , V_9 , V_17 ) ;
if ( ( ( V_19 & V_25 ) == 0 ) && ( V_19 + V_26 <= V_21 ) ) {
F_2 ( V_2 , V_9 ,
F_13 ( V_19 ) ) ;
V_19 += V_26 ;
} else if ( ( ( V_19 & V_27 ) == 0 ) &&
( V_19 + V_28 <= V_21 ) ) {
F_2 ( V_2 , V_9 ,
F_14 ( V_19 ) ) ;
V_19 += V_28 ;
} else {
F_2 ( V_2 , V_9 ,
F_15 ( V_19 ) ) ;
V_19 += V_29 ;
}
V_8 = F_5 ( V_2 ) ;
if ( V_8 )
goto V_30;
}
V_30:
F_4 ( V_2 ) ;
return V_8 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_31 , T_2 * V_32 )
{
int V_33 ;
F_2 ( V_2 , V_9 , F_17 ( V_31 ) ) ;
for ( V_33 = 0 ; V_33 < V_34 / sizeof( T_2 ) ; V_33 ++ )
V_32 [ V_33 ] = ( T_2 ) F_3 ( V_2 , V_12 ) ;
F_2 ( V_2 , V_9 , V_15 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_20 , T_1 V_35 )
{
T_2 V_31 ;
T_2 V_36 [ V_34 / sizeof( T_2 ) ] ;
int V_8 = 0 ;
if ( ( V_19 & V_37 ) || ( V_20 & V_37 ) )
return - V_22 ;
for ( V_31 = 0 ; V_31 < V_20 ; V_31 += V_34 ) {
F_16 ( V_2 , V_19 + V_31 , V_36 ) ;
if ( F_19 ( ( void V_38 * ) ( V_35 + V_31 ) ,
V_36 , V_34 ) ) {
V_8 = - V_39 ;
goto V_30;
}
}
V_30:
return V_8 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_31 , T_2 * V_40 )
{
int V_33 ;
F_2 ( V_2 , V_9 , V_17 ) ;
F_2 ( V_2 , V_12 , V_40 [ 0 ] ) ;
F_2 ( V_2 , V_9 , F_21 ( V_31 ) ) ;
for ( V_33 = 1 ; V_33 < V_34 / sizeof( T_2 ) ; V_33 ++ )
F_2 ( V_2 , V_12 , V_40 [ V_33 ] ) ;
return F_5 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_20 , T_1 V_35 )
{
T_2 V_31 ;
T_2 V_36 [ V_34 / sizeof( T_2 ) ] ;
int V_8 = 0 ;
if ( ( V_19 & V_37 ) || ( V_20 & V_37 ) )
return - V_22 ;
F_1 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_20 ; V_31 += V_34 ) {
if ( F_23 ( V_36 , ( void V_38 * ) ( V_35 + V_31 ) ,
V_34 ) ) {
V_8 = - V_39 ;
goto V_30;
}
V_8 = F_20 ( V_2 , V_19 + V_31 , V_36 ) ;
if ( V_8 )
goto V_30;
}
V_30:
F_4 ( V_2 ) ;
return V_8 ;
}
static inline T_2 F_24 ( T_2 V_41 )
{
return ( V_41 & 0xffff ) * V_34 ;
}
static inline T_2 F_25 ( T_2 V_41 )
{
return ( V_41 >> 16 ) * V_34 ;
}
int F_26 ( struct V_42 * V_43 , const struct V_44 * V_45 )
{
struct V_1 * V_2 ;
T_2 V_46 ;
T_2 V_47 ;
T_2 V_48 ;
int V_49 ;
int V_8 = 0 ;
V_49 = F_27 ( F_28 ( V_43 ) ) - V_50 ;
if ( V_49 <= 0 )
return - V_22 ;
V_2 = F_29 ( V_49 - 1 ) ;
if ( ! V_2 ) {
F_30 ( L_3 , V_24 , V_49 ) ;
return - V_22 ;
}
if ( ! V_2 -> V_51 )
return - V_52 ;
V_8 = F_31 ( V_2 , V_53 , V_54 ) ;
if ( V_8 ) {
F_9 ( V_2 , L_4 ,
V_24 ) ;
goto V_55;
}
F_32 ( V_2 , L_5 ,
V_24 , V_45 -> type , V_45 -> V_20 , V_45 -> V_35 ) ;
switch ( V_45 -> type ) {
case V_56 :
if ( V_45 -> V_20 != sizeof( T_2 ) ) {
V_8 = - V_57 ;
break;
}
V_46 = F_10 ( V_2 ) ;
if ( F_19 ( ( void V_38 * ) V_45 -> V_35 , & V_46 ,
sizeof( T_2 ) ) )
V_8 = - V_39 ;
break;
case V_58 :
V_8 = F_11 ( V_2 ) ;
break;
case V_59 :
V_47 = F_24 ( V_45 -> V_20 ) ;
V_48 = F_25 ( V_45 -> V_20 ) ;
V_8 = F_12 ( V_2 , V_48 , V_47 ) ;
break;
case V_60 :
V_47 = F_24 ( V_45 -> V_20 ) ;
V_48 = F_25 ( V_45 -> V_20 ) ;
V_8 = F_18 ( V_2 , V_48 , V_47 , V_45 -> V_35 ) ;
break;
case V_61 :
V_47 = F_24 ( V_45 -> V_20 ) ;
V_48 = F_25 ( V_45 -> V_20 ) ;
V_8 = F_22 ( V_2 , V_48 , V_47 , V_45 -> V_35 ) ;
break;
default:
F_9 ( V_2 , L_6 ,
V_24 , V_45 -> type ) ;
V_8 = - V_22 ;
break;
}
F_33 ( V_2 , V_53 ) ;
V_55:
return V_8 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( V_2 -> V_62 -> V_63 != V_64 )
return 0 ;
V_8 = F_31 ( V_2 , V_53 , V_54 ) ;
if ( V_8 ) {
F_9 ( V_2 ,
L_7 ,
V_24 ) ;
goto V_55;
}
F_2 ( V_2 , V_65 , V_66 ) ;
F_2 ( V_2 , V_65 ,
V_67 << V_68 ) ;
F_2 ( V_2 , V_9 , V_69 ) ;
V_2 -> V_51 = true ;
F_33 ( V_2 , V_53 ) ;
V_55:
return V_8 ;
}
