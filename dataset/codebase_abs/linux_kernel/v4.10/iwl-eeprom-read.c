static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
F_2 ( V_2 , V_6 ,
V_7 ) ;
V_4 = F_3 ( V_2 , V_6 ,
V_7 ,
V_7 ,
V_8 ) ;
if ( V_4 >= 0 ) {
F_4 ( V_2 -> V_9 ,
L_1 ,
V_3 + 1 ) ;
return V_4 ;
}
}
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_6 ,
V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_10 )
{
T_2 V_11 = F_8 ( V_2 , V_12 ) & V_13 ;
F_4 ( V_2 -> V_9 , L_2 , V_11 ) ;
switch ( V_11 ) {
case V_14 :
if ( ! V_10 ) {
F_9 ( V_2 , L_3 ,
V_11 ) ;
return - V_15 ;
}
return 0 ;
case V_16 :
case V_17 :
if ( V_10 ) {
F_9 ( V_2 , L_4 , V_11 ) ;
return - V_15 ;
}
return 0 ;
case V_18 :
default:
F_9 ( V_2 ,
L_5 ,
V_10 ? L_6 : L_7 , V_11 ) ;
return - V_15 ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_19 ) ;
F_6 ( V_2 , V_19 ,
V_20 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 V_21 ;
switch ( V_2 -> V_22 & V_23 ) {
case V_24 :
F_9 ( V_2 , L_8 ) ;
return - V_25 ;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
return 0 ;
default:
V_21 = F_8 ( V_2 , V_19 ) ;
if ( V_21 & V_30 )
return 1 ;
return 0 ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
int V_4 ;
F_13 ( V_2 , V_31 ,
F_8 ( V_2 , V_31 ) |
V_32 ) ;
V_4 = F_3 ( V_2 , V_31 ,
V_33 ,
V_33 ,
25000 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 , L_9 ) ;
} else {
F_14 ( V_2 , V_34 ,
V_35 ) ;
F_15 ( 5 ) ;
F_16 ( V_2 , V_34 ,
V_35 ) ;
if ( V_2 -> V_36 -> V_37 -> V_38 )
F_2 ( V_2 , V_39 ,
V_40 ) ;
}
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_41 ,
T_3 * V_42 )
{
int V_4 = 0 ;
T_2 V_43 ;
T_2 V_21 ;
F_13 ( V_2 , V_44 ,
V_45 & ( V_41 << 1 ) ) ;
V_4 = F_3 ( V_2 , V_44 ,
V_46 ,
V_46 ,
V_47 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 , L_10 , V_41 ) ;
return V_4 ;
}
V_43 = F_8 ( V_2 , V_44 ) ;
V_21 = F_8 ( V_2 , V_19 ) ;
if ( V_21 & V_48 ) {
F_2 ( V_2 , V_19 ,
V_48 ) ;
F_9 ( V_2 , L_11 ) ;
return - V_49 ;
}
if ( V_21 & V_50 ) {
F_2 ( V_2 , V_19 ,
V_50 ) ;
F_9 ( V_2 , L_12 ) ;
}
* V_42 = F_18 ( V_43 >> 16 ) ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
T_1 V_51 = 0 ;
T_3 V_52 ;
bool V_53 = false ;
if ( ! F_17 ( V_2 , V_51 , & V_52 ) ) {
if ( ! V_52 ) {
F_9 ( V_2 , L_13 ) ;
V_53 = true ;
}
} else {
F_9 ( V_2 , L_14 ) ;
V_53 = true ;
}
return V_53 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 * V_54 )
{
T_1 V_51 = 0 , V_55 ;
T_3 V_52 = 0 ;
int V_56 = 0 ;
F_10 ( V_2 ) ;
if ( F_19 ( V_2 ) )
return - V_49 ;
do {
V_55 = V_51 ;
V_51 = F_21 ( V_52 ) * sizeof( T_1 ) ;
F_4 ( V_2 -> V_9 , L_15 ,
V_56 , V_51 ) ;
if ( F_17 ( V_2 , V_51 , & V_52 ) )
return - V_49 ;
if ( ! V_52 ) {
* V_54 = V_55 ;
* V_54 += 2 ;
return 0 ;
}
V_56 ++ ;
} while ( V_56 <= V_2 -> V_36 -> V_37 -> V_57 );
F_4 ( V_2 -> V_9 , L_16 ) ;
return - V_49 ;
}
int F_22 ( struct V_1 * V_2 , T_4 * * V_58 , T_5 * V_59 )
{
T_3 * V_60 ;
T_2 V_11 = F_8 ( V_2 , V_12 ) ;
int V_61 ;
int V_4 ;
T_1 V_41 ;
T_1 V_54 = 0 ;
T_1 V_62 = 0 ;
int V_10 ;
if ( ! V_58 || ! V_59 )
return - V_49 ;
V_10 = F_11 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_61 = V_2 -> V_36 -> V_37 -> V_59 ;
F_4 ( V_2 -> V_9 , L_17 , V_61 ) ;
V_60 = F_23 ( V_61 , V_63 ) ;
if ( ! V_60 )
return - V_64 ;
V_4 = F_7 ( V_2 , V_10 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 , L_18 , V_11 ) ;
goto V_65;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 , L_19 ) ;
goto V_65;
}
if ( V_10 ) {
V_4 = F_12 ( V_2 ) ;
if ( V_4 ) {
F_9 ( V_2 , L_20 ) ;
goto V_66;
}
F_13 ( V_2 , V_12 ,
F_8 ( V_2 , V_12 ) &
~ V_67 ) ;
F_2 ( V_2 , V_19 ,
V_50 |
V_48 ) ;
if ( ! V_2 -> V_36 -> V_37 -> V_38 ) {
V_4 = F_20 ( V_2 , & V_54 ) ;
if ( V_4 )
goto V_66;
}
for ( V_41 = V_54 ; V_41 < V_54 + V_61 ;
V_41 += sizeof( T_1 ) ) {
T_3 V_42 ;
V_4 = F_17 ( V_2 , V_41 , & V_42 ) ;
if ( V_4 )
goto V_66;
V_60 [ V_62 / 2 ] = V_42 ;
V_62 += sizeof( T_1 ) ;
}
} else {
for ( V_41 = 0 ; V_41 < V_61 ; V_41 += sizeof( T_1 ) ) {
T_2 V_43 ;
F_13 ( V_2 , V_44 ,
V_45 & ( V_41 << 1 ) ) ;
V_4 = F_3 ( V_2 , V_44 ,
V_46 ,
V_46 ,
V_47 ) ;
if ( V_4 < 0 ) {
F_9 ( V_2 ,
L_21 , V_41 ) ;
goto V_66;
}
V_43 = F_8 ( V_2 , V_44 ) ;
V_60 [ V_41 / 2 ] = F_18 ( V_43 >> 16 ) ;
}
}
F_4 ( V_2 -> V_9 , L_22 ,
V_10 ? L_6 : L_7 ) ;
F_5 ( V_2 ) ;
* V_59 = V_61 ;
* V_58 = ( T_4 * ) V_60 ;
return 0 ;
V_66:
F_5 ( V_2 ) ;
V_65:
F_24 ( V_60 ) ;
return V_4 ;
}
