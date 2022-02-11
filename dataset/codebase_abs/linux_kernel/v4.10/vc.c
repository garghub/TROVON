static void F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , int V_5 , bool V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ , V_4 ++ ) {
if ( V_6 )
F_2 ( V_2 , V_3 + ( V_7 * 4 ) , V_4 ) ;
else
F_3 ( V_2 , V_3 + ( V_7 * 4 ) , * V_4 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_8 ;
F_5 ( V_2 , V_3 + V_9 , & V_8 ) ;
F_6 ( V_2 , V_3 + V_9 ,
V_8 | V_10 ) ;
if ( F_7 ( V_2 , V_3 + V_11 ,
V_12 ) )
return;
F_8 ( & V_2 -> V_2 , L_1 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 , int V_13 )
{
int V_14 , V_15 ;
T_1 V_8 ;
V_14 = V_3 + V_16 + ( V_13 * V_17 ) ;
V_15 = V_3 + V_18 + ( V_13 * V_17 ) ;
F_2 ( V_2 , V_14 , & V_8 ) ;
F_3 ( V_2 , V_14 ,
V_8 | V_19 ) ;
if ( F_7 ( V_2 , V_15 , V_20 ) )
return;
F_8 ( & V_2 -> V_2 , L_2 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_3 , int V_13 )
{
int V_14 , V_15 , V_21 , V_22 , V_23 , V_7 , V_24 , V_25 ;
T_1 V_8 , V_26 , V_27 , V_28 ;
struct V_1 * V_29 = NULL ;
if ( ! V_2 -> V_30 )
return;
V_14 = V_3 + V_16 + ( V_13 * V_17 ) ;
V_15 = V_3 + V_18 + ( V_13 * V_17 ) ;
F_2 ( V_2 , V_14 , & V_8 ) ;
V_21 = V_8 & V_31 ;
F_2 ( V_2 , V_3 , & V_26 ) ;
if ( F_11 ( V_26 ) == V_32 ||
F_12 ( V_2 -> V_33 ) )
goto V_34;
V_22 = F_13 ( V_2 -> V_33 -> V_35 , V_36 ) ;
if ( ! V_22 )
goto V_34;
F_2 ( V_2 -> V_33 -> V_35 , V_22 + V_37 , & V_27 ) ;
V_23 = V_27 & V_38 ;
for ( V_7 = 1 ; V_7 < V_23 + 1 ; V_7 ++ ) {
V_24 = V_22 + V_16 +
( V_7 * V_17 ) ;
V_25 = V_22 + V_18 +
( V_7 * V_17 ) ;
F_2 ( V_2 -> V_33 -> V_35 , V_24 , & V_28 ) ;
if ( ( V_28 & V_31 ) == V_21 ) {
V_29 = V_2 -> V_33 -> V_35 ;
break;
}
}
if ( ! V_29 )
goto V_34;
if ( V_28 & V_39 ) {
V_28 &= ~ V_39 ;
F_3 ( V_29 , V_24 , V_28 ) ;
}
V_28 |= V_39 ;
F_3 ( V_29 , V_24 , V_28 ) ;
V_34:
V_8 |= V_39 ;
F_3 ( V_2 , V_14 , V_8 ) ;
if ( ! F_7 ( V_2 , V_15 , V_40 ) )
F_8 ( & V_2 -> V_2 , L_3 , V_21 ) ;
if ( V_29 && ! F_7 ( V_29 , V_25 ,
V_40 ) )
F_8 ( & V_29 -> V_2 , L_3 , V_21 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_3 ,
struct V_41 * V_42 ,
bool V_6 )
{
T_1 V_27 ;
char V_23 , V_43 , V_44 ;
int V_7 , V_45 = 0 ;
T_3 * V_4 = V_42 ? ( T_3 * ) V_42 -> V_46 . V_47 : NULL ;
if ( V_4 && V_42 -> V_46 . V_48 !=
F_14 ( V_2 , V_3 , NULL , V_6 ) ) {
F_8 ( & V_2 -> V_2 ,
L_4 , V_3 ) ;
return - V_49 ;
}
F_2 ( V_2 , V_3 + V_37 , & V_27 ) ;
V_23 = V_27 & V_38 ;
V_43 = ( V_27 & V_50 ) >> 4 ;
V_44 = 1 << ( ( V_27 & V_51 ) >> 10 ) ;
if ( V_4 ) {
if ( V_6 )
F_5 ( V_2 , V_3 + V_9 ,
( T_2 * ) V_4 ) ;
else
F_6 ( V_2 , V_3 + V_9 ,
* ( T_2 * ) V_4 ) ;
V_4 += 4 ;
}
V_45 += 4 ;
if ( V_43 ) {
T_1 V_52 ;
int V_53 ;
F_2 ( V_2 , V_3 + V_54 , & V_52 ) ;
V_53 = ( ( V_52 & V_55 ) >> 24 ) * 16 ;
if ( V_53 ) {
int V_48 , V_56 = 0 ;
if ( V_52 & V_57 )
V_56 = 128 ;
else if ( V_52 & V_58 )
V_56 = 64 ;
else if ( V_52 & V_59 )
V_56 = 32 ;
V_48 = ( ( V_43 + 1 ) * V_56 * 4 ) / 8 ;
if ( V_48 && V_4 ) {
F_1 ( V_2 ,
V_3 + V_53 ,
( T_1 * ) V_4 ,
V_48 / 4 , V_6 ) ;
if ( ! V_6 )
F_4 ( V_2 , V_3 ) ;
V_4 += V_48 ;
}
V_45 += V_48 ;
}
}
for ( V_7 = 0 ; V_7 < V_23 + 1 ; V_7 ++ ) {
T_1 V_46 ;
int V_60 ;
F_2 ( V_2 , V_3 + V_61 +
( V_7 * V_17 ) , & V_46 ) ;
V_60 = ( ( V_46 & V_62 ) >> 24 ) * 16 ;
if ( V_60 ) {
int V_48 , V_63 = 0 ;
if ( V_46 & V_64 )
V_63 = 256 ;
else if ( V_46 & ( V_65 |
V_66 ) )
V_63 = 128 ;
else if ( V_46 & V_67 )
V_63 = 64 ;
else if ( V_46 & V_68 )
V_63 = 32 ;
V_48 = ( V_44 * V_63 ) / 8 ;
if ( V_48 && V_4 ) {
F_1 ( V_2 ,
V_3 + V_60 ,
( T_1 * ) V_4 ,
V_48 / 4 , V_6 ) ;
V_4 += V_48 ;
}
V_45 += V_48 ;
}
if ( V_4 ) {
int V_14 = V_3 + V_16 +
( V_7 * V_17 ) ;
if ( V_6 )
F_2 ( V_2 , V_14 ,
( T_1 * ) V_4 ) ;
else {
T_1 V_69 , V_8 = * ( T_1 * ) V_4 ;
F_2 ( V_2 , V_14 , & V_69 ) ;
V_69 &= V_39 ;
V_69 |= V_8 & ~ V_39 ;
F_3 ( V_2 , V_14 , V_69 ) ;
if ( V_8 & V_70 )
F_9 ( V_2 , V_3 , V_7 ) ;
if ( ( V_8 ^ V_69 ) & V_39 )
F_10 ( V_2 , V_3 , V_7 ) ;
}
V_4 += 4 ;
}
V_45 += 4 ;
}
return V_4 ? 0 : V_45 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_16 ( V_71 ) ; V_7 ++ ) {
int V_3 , V_72 ;
struct V_41 * V_42 ;
V_3 = F_13 ( V_2 , V_71 [ V_7 ] . V_21 ) ;
if ( ! V_3 )
continue;
V_42 = F_17 ( V_2 , V_71 [ V_7 ] . V_21 ) ;
if ( ! V_42 ) {
F_8 ( & V_2 -> V_2 , L_5 ,
V_71 [ V_7 ] . V_73 , V_74 ) ;
return - V_49 ;
}
V_72 = F_14 ( V_2 , V_3 , V_42 , true ) ;
if ( V_72 ) {
F_8 ( & V_2 -> V_2 , L_6 ,
V_71 [ V_7 ] . V_73 , V_74 ) ;
return V_72 ;
}
}
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_16 ( V_71 ) ; V_7 ++ ) {
int V_3 ;
struct V_41 * V_42 ;
V_3 = F_13 ( V_2 , V_71 [ V_7 ] . V_21 ) ;
V_42 = F_17 ( V_2 , V_71 [ V_7 ] . V_21 ) ;
if ( ! V_42 || ! V_3 )
continue;
F_14 ( V_2 , V_3 , V_42 , false ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_16 ( V_71 ) ; V_7 ++ ) {
int V_45 , V_3 = F_13 ( V_2 , V_71 [ V_7 ] . V_21 ) ;
if ( ! V_3 )
continue;
V_45 = F_14 ( V_2 , V_3 , NULL , false ) ;
if ( F_20 ( V_2 , V_71 [ V_7 ] . V_21 , V_45 ) )
F_8 ( & V_2 -> V_2 ,
L_7 ,
V_71 [ V_7 ] . V_73 ) ;
}
}
