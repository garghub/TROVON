static inline const
struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
return & V_3 -> V_5 -> V_6 [ V_4 ] ;
}
static void F_2 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
F_4 ( & V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 , V_13 ;
T_1 V_14 ;
T_1 V_15 ;
if ( V_8 -> V_5 -> V_16 ) {
V_13 = F_6 ( V_11 -> V_17 ) ;
if ( V_13 < 0 )
F_7 ( V_11 -> V_17 , L_1 ,
V_13 ) ;
}
for ( V_12 = 0 ; V_12 < V_8 -> V_5 -> V_18 ; V_12 ++ ) {
V_14 = V_8 -> V_5 -> V_19 +
( V_12 * V_11 -> V_20 * V_8 -> V_21 ) ;
if ( V_8 -> V_5 -> V_22 ) {
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] , ~ V_8 -> V_24 [ V_12 ] ) ;
} else if ( V_8 -> V_5 -> V_25 ) {
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] , ~ V_8 -> V_24 [ V_12 ] ) ;
if ( V_13 < 0 )
F_7 ( V_8 -> V_11 -> V_17 ,
L_2 ,
V_14 ) ;
V_15 = V_8 -> V_5 -> V_25 -
V_8 -> V_5 -> V_19 ;
V_13 = F_8 ( V_8 -> V_11 ,
V_14 + V_15 ,
V_8 -> V_23 [ V_12 ] ,
V_8 -> V_24 [ V_12 ] ) ;
} else {
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] , V_8 -> V_24 [ V_12 ] ) ;
}
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_17 , L_3 ,
V_14 ) ;
V_14 = V_8 -> V_5 -> V_26 +
( V_12 * V_11 -> V_20 * V_8 -> V_21 ) ;
if ( V_8 -> V_27 ) {
if ( V_8 -> V_5 -> V_28 )
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] ,
~ V_8 -> V_27 [ V_12 ] ) ;
else
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] ,
V_8 -> V_27 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_17 ,
L_4 ,
V_14 , V_13 ) ;
}
if ( ! V_8 -> V_5 -> V_29 )
continue;
if ( V_8 -> V_24 [ V_12 ] && ( V_8 -> V_5 -> V_30 || V_8 -> V_5 -> V_31 ) ) {
V_14 = V_8 -> V_5 -> V_30 +
( V_12 * V_11 -> V_20 * V_8 -> V_21 ) ;
if ( V_8 -> V_5 -> V_32 )
V_13 = F_9 ( V_11 , V_14 , ~ V_8 -> V_24 [ V_12 ] ) ;
else
V_13 = F_9 ( V_11 , V_14 , V_8 -> V_24 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_17 , L_5 ,
V_14 , V_13 ) ;
}
}
for ( V_12 = 0 ; V_12 < V_8 -> V_5 -> V_33 ; V_12 ++ ) {
if ( ! V_8 -> V_34 [ V_12 ] )
continue;
V_14 = V_8 -> V_5 -> V_35 +
( V_12 * V_11 -> V_20 * V_8 -> V_36 ) ;
if ( V_8 -> V_5 -> V_37 )
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_34 [ V_12 ] , ~ V_8 -> V_38 [ V_12 ] ) ;
else
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_34 [ V_12 ] , V_8 -> V_38 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_17 , L_6 ,
V_14 ) ;
}
if ( V_8 -> V_5 -> V_16 )
F_10 ( V_11 -> V_17 ) ;
if ( V_8 -> V_39 < 0 )
for ( V_12 = V_8 -> V_39 ; V_12 < 0 ; V_12 ++ )
F_11 ( V_8 -> V_4 , 0 ) ;
else if ( V_8 -> V_39 > 0 )
for ( V_12 = 0 ; V_12 < V_8 -> V_39 ; V_12 ++ )
F_11 ( V_8 -> V_4 , 1 ) ;
V_8 -> V_39 = 0 ;
F_12 ( & V_8 -> V_9 ) ;
}
static void F_13 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_40 ) ;
V_8 -> V_24 [ V_7 -> V_41 / V_11 -> V_20 ] &= ~ V_7 -> V_42 ;
}
static void F_14 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_40 ) ;
V_8 -> V_24 [ V_7 -> V_41 / V_11 -> V_20 ] |= V_7 -> V_42 ;
}
static int F_15 ( struct V_7 * V_3 , unsigned int type )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_40 ) ;
int V_14 = V_7 -> V_43 / V_11 -> V_20 ;
if ( ! ( V_7 -> V_44 | V_7 -> V_45 ) )
return 0 ;
V_8 -> V_38 [ V_14 ] &= ~ ( V_7 -> V_45 |
V_7 -> V_44 ) ;
switch ( type ) {
case V_46 :
V_8 -> V_38 [ V_14 ] |= V_7 -> V_45 ;
break;
case V_47 :
V_8 -> V_38 [ V_14 ] |= V_7 -> V_44 ;
break;
case V_48 :
V_8 -> V_38 [ V_14 ] |= ( V_7 -> V_45 |
V_7 -> V_44 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_16 ( struct V_7 * V_3 , unsigned int V_50 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_40 ) ;
if ( V_50 ) {
if ( V_8 -> V_27 )
V_8 -> V_27 [ V_7 -> V_41 / V_11 -> V_20 ]
&= ~ V_7 -> V_42 ;
V_8 -> V_39 ++ ;
} else {
if ( V_8 -> V_27 )
V_8 -> V_27 [ V_7 -> V_41 / V_11 -> V_20 ]
|= V_7 -> V_42 ;
V_8 -> V_39 -- ;
}
return 0 ;
}
static T_2 F_17 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
const struct V_51 * V_5 = V_3 -> V_5 ;
struct V_10 * V_11 = V_3 -> V_11 ;
int V_13 , V_12 ;
bool V_52 = false ;
T_1 V_14 ;
if ( V_5 -> V_53 )
V_5 -> V_53 ( V_5 -> V_54 ) ;
if ( V_5 -> V_16 ) {
V_13 = F_6 ( V_11 -> V_17 ) ;
if ( V_13 < 0 ) {
F_7 ( V_11 -> V_17 , L_7 ,
V_13 ) ;
F_10 ( V_11 -> V_17 ) ;
goto exit;
}
}
if ( ! V_11 -> V_55 && V_11 -> V_20 == 1 &&
V_3 -> V_21 == 1 ) {
T_3 * V_56 = V_3 -> V_57 ;
T_4 * V_58 = V_3 -> V_57 ;
T_1 * V_59 = V_3 -> V_57 ;
F_18 ( ! V_3 -> V_57 ) ;
V_13 = F_19 ( V_11 , V_5 -> V_60 ,
V_3 -> V_57 ,
V_5 -> V_18 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 , L_8 ,
V_13 ) ;
goto exit;
}
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_18 ; V_12 ++ ) {
switch ( V_11 -> V_61 . V_62 ) {
case 1 :
V_3 -> V_63 [ V_12 ] = V_56 [ V_12 ] ;
break;
case 2 :
V_3 -> V_63 [ V_12 ] = V_58 [ V_12 ] ;
break;
case 4 :
V_3 -> V_63 [ V_12 ] = V_59 [ V_12 ] ;
break;
default:
F_20 () ;
goto exit;
}
}
} else {
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_18 ; V_12 ++ ) {
V_13 = F_21 ( V_11 , V_5 -> V_60 +
( V_12 * V_11 -> V_20
* V_3 -> V_21 ) ,
& V_3 -> V_63 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 ,
L_8 ,
V_13 ) ;
if ( V_5 -> V_16 )
F_10 ( V_11 -> V_17 ) ;
goto exit;
}
}
}
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_18 ; V_12 ++ ) {
V_3 -> V_63 [ V_12 ] &= ~ V_3 -> V_24 [ V_12 ] ;
if ( V_3 -> V_63 [ V_12 ] && ( V_5 -> V_30 || V_5 -> V_31 ) ) {
V_14 = V_5 -> V_30 +
( V_12 * V_11 -> V_20 * V_3 -> V_21 ) ;
V_13 = F_9 ( V_11 , V_14 , V_3 -> V_63 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_11 -> V_17 , L_5 ,
V_14 , V_13 ) ;
}
}
for ( V_12 = 0 ; V_12 < V_5 -> V_64 ; V_12 ++ ) {
if ( V_3 -> V_63 [ V_5 -> V_6 [ V_12 ] . V_41 /
V_11 -> V_20 ] & V_5 -> V_6 [ V_12 ] . V_42 ) {
F_22 ( F_23 ( V_3 -> V_65 , V_12 ) ) ;
V_52 = true ;
}
}
if ( V_5 -> V_16 )
F_10 ( V_11 -> V_17 ) ;
exit:
if ( V_5 -> V_66 )
V_5 -> V_66 ( V_5 -> V_54 ) ;
if ( V_52 )
return V_67 ;
else
return V_68 ;
}
static int F_24 ( struct V_69 * V_70 , unsigned int V_71 ,
T_5 V_72 )
{
struct V_2 * V_3 = V_70 -> V_73 ;
F_25 ( V_71 , V_3 ) ;
F_26 ( V_71 , & V_3 -> V_74 ) ;
F_27 ( V_71 , 1 ) ;
F_28 ( V_71 , V_3 -> V_4 ) ;
F_29 ( V_71 ) ;
return 0 ;
}
int F_30 ( struct V_10 * V_11 , int V_4 , int V_75 ,
int V_76 , const struct V_51 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * V_8 ;
int V_12 ;
int V_13 = - V_77 ;
T_1 V_14 ;
T_1 V_15 ;
if ( V_5 -> V_18 <= 0 )
return - V_49 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_64 ; V_12 ++ ) {
if ( V_5 -> V_6 [ V_12 ] . V_41 % V_11 -> V_20 )
return - V_49 ;
if ( V_5 -> V_6 [ V_12 ] . V_41 / V_11 -> V_20 >=
V_5 -> V_18 )
return - V_49 ;
}
if ( V_76 ) {
V_76 = F_31 ( V_76 , 0 , V_5 -> V_64 , 0 ) ;
if ( V_76 < 0 ) {
F_32 ( V_11 -> V_17 , L_9 ,
V_76 ) ;
return V_76 ;
}
}
V_8 = F_33 ( sizeof( * V_8 ) , V_78 ) ;
if ( ! V_8 )
return - V_77 ;
V_8 -> V_63 = F_34 ( V_5 -> V_18 , sizeof( unsigned int ) ,
V_78 ) ;
if ( ! V_8 -> V_63 )
goto V_79;
V_8 -> V_24 = F_34 ( V_5 -> V_18 , sizeof( unsigned int ) ,
V_78 ) ;
if ( ! V_8 -> V_24 )
goto V_79;
V_8 -> V_23 = F_34 ( V_5 -> V_18 , sizeof( unsigned int ) ,
V_78 ) ;
if ( ! V_8 -> V_23 )
goto V_79;
if ( V_5 -> V_26 ) {
V_8 -> V_27 = F_34 ( V_5 -> V_18 , sizeof( unsigned int ) ,
V_78 ) ;
if ( ! V_8 -> V_27 )
goto V_79;
}
if ( V_5 -> V_33 ) {
V_8 -> V_34 = F_34 ( V_5 -> V_33 ,
sizeof( unsigned int ) , V_78 ) ;
if ( ! V_8 -> V_34 )
goto V_79;
V_8 -> V_38 = F_34 ( V_5 -> V_33 , sizeof( unsigned int ) ,
V_78 ) ;
if ( ! V_8 -> V_38 )
goto V_79;
}
V_8 -> V_74 = V_51 ;
V_8 -> V_74 . V_80 = V_5 -> V_80 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_76 = V_76 ;
if ( V_5 -> V_21 )
V_8 -> V_21 = V_5 -> V_21 ;
else
V_8 -> V_21 = 1 ;
if ( V_5 -> V_36 )
V_8 -> V_36 = V_5 -> V_36 ;
else
V_8 -> V_36 = 1 ;
if ( ! V_11 -> V_55 && V_11 -> V_20 == 1 &&
V_8 -> V_21 == 1 ) {
V_8 -> V_57 = F_35 ( V_5 -> V_18 ,
V_11 -> V_61 . V_62 ,
V_78 ) ;
if ( ! V_8 -> V_57 )
goto V_79;
}
F_36 ( & V_8 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_5 -> V_64 ; V_12 ++ )
V_8 -> V_23 [ V_5 -> V_6 [ V_12 ] . V_41 / V_11 -> V_20 ]
|= V_5 -> V_6 [ V_12 ] . V_42 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_18 ; V_12 ++ ) {
V_8 -> V_24 [ V_12 ] = V_8 -> V_23 [ V_12 ] ;
V_14 = V_5 -> V_19 +
( V_12 * V_11 -> V_20 * V_8 -> V_21 ) ;
if ( V_5 -> V_22 )
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_24 [ V_12 ] , ~ V_8 -> V_24 [ V_12 ] ) ;
else if ( V_8 -> V_5 -> V_25 ) {
V_15 = V_8 -> V_5 -> V_25 -
V_8 -> V_5 -> V_19 ;
V_13 = F_8 ( V_8 -> V_11 ,
V_14 + V_15 ,
V_8 -> V_24 [ V_12 ] ,
V_8 -> V_24 [ V_12 ] ) ;
} else
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_24 [ V_12 ] , V_8 -> V_24 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 , L_10 ,
V_14 , V_13 ) ;
goto V_79;
}
if ( ! V_5 -> V_29 )
continue;
V_14 = V_5 -> V_60 +
( V_12 * V_11 -> V_20 * V_8 -> V_21 ) ;
V_13 = F_21 ( V_11 , V_14 , & V_8 -> V_63 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 , L_8 ,
V_13 ) ;
goto V_79;
}
if ( V_8 -> V_63 [ V_12 ] && ( V_5 -> V_30 || V_5 -> V_31 ) ) {
V_14 = V_5 -> V_30 +
( V_12 * V_11 -> V_20 * V_8 -> V_21 ) ;
if ( V_5 -> V_32 )
V_13 = F_9 ( V_11 , V_14 ,
~ ( V_8 -> V_63 [ V_12 ] & V_8 -> V_24 [ V_12 ] ) ) ;
else
V_13 = F_9 ( V_11 , V_14 ,
V_8 -> V_63 [ V_12 ] & V_8 -> V_24 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 , L_5 ,
V_14 , V_13 ) ;
goto V_79;
}
}
}
if ( V_8 -> V_27 ) {
for ( V_12 = 0 ; V_12 < V_5 -> V_18 ; V_12 ++ ) {
V_8 -> V_27 [ V_12 ] = V_8 -> V_23 [ V_12 ] ;
V_14 = V_5 -> V_26 +
( V_12 * V_11 -> V_20 * V_8 -> V_21 ) ;
if ( V_5 -> V_28 )
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] ,
0 ) ;
else
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] ,
V_8 -> V_27 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 , L_10 ,
V_14 , V_13 ) ;
goto V_79;
}
}
}
if ( V_5 -> V_33 ) {
for ( V_12 = 0 ; V_12 < V_5 -> V_64 ; V_12 ++ ) {
V_14 = V_5 -> V_6 [ V_12 ] . V_43 / V_11 -> V_20 ;
V_8 -> V_34 [ V_14 ] |= V_5 -> V_6 [ V_12 ] . V_44 |
V_5 -> V_6 [ V_12 ] . V_45 ;
}
for ( V_12 = 0 ; V_12 < V_5 -> V_33 ; ++ V_12 ) {
if ( ! V_8 -> V_34 [ V_12 ] )
continue;
V_14 = V_5 -> V_35 +
( V_12 * V_11 -> V_20 * V_8 -> V_36 ) ;
if ( V_5 -> V_37 )
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_34 [ V_12 ] , 0xFF ) ;
else
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_34 [ V_12 ] , 0x0 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 ,
L_11 ,
V_14 , V_13 ) ;
goto V_79;
}
}
}
if ( V_76 )
V_8 -> V_65 = F_37 ( V_11 -> V_17 -> V_81 ,
V_5 -> V_64 , V_76 , 0 ,
& V_82 , V_8 ) ;
else
V_8 -> V_65 = F_38 ( V_11 -> V_17 -> V_81 ,
V_5 -> V_64 ,
& V_82 , V_8 ) ;
if ( ! V_8 -> V_65 ) {
F_7 ( V_11 -> V_17 , L_12 ) ;
V_13 = - V_77 ;
goto V_79;
}
V_13 = F_39 ( V_4 , NULL , F_17 ,
V_75 | V_83 ,
V_5 -> V_80 , V_8 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_17 , L_13 ,
V_4 , V_5 -> V_80 , V_13 ) ;
goto V_84;
}
* V_3 = V_8 ;
return 0 ;
V_84:
V_79:
F_40 ( V_8 -> V_38 ) ;
F_40 ( V_8 -> V_34 ) ;
F_40 ( V_8 -> V_27 ) ;
F_40 ( V_8 -> V_23 ) ;
F_40 ( V_8 -> V_24 ) ;
F_40 ( V_8 -> V_63 ) ;
F_40 ( V_8 -> V_57 ) ;
F_40 ( V_8 ) ;
return V_13 ;
}
void F_41 ( int V_4 , struct V_2 * V_8 )
{
unsigned int V_71 ;
int V_40 ;
if ( ! V_8 )
return;
F_42 ( V_4 , V_8 ) ;
for ( V_40 = 0 ; V_40 < V_8 -> V_5 -> V_64 ; V_40 ++ ) {
if ( ! V_8 -> V_5 -> V_6 [ V_40 ] . V_42 )
continue;
V_71 = F_23 ( V_8 -> V_65 , V_40 ) ;
if ( V_71 )
F_43 ( V_71 ) ;
}
F_44 ( V_8 -> V_65 ) ;
F_40 ( V_8 -> V_38 ) ;
F_40 ( V_8 -> V_34 ) ;
F_40 ( V_8 -> V_27 ) ;
F_40 ( V_8 -> V_23 ) ;
F_40 ( V_8 -> V_24 ) ;
F_40 ( V_8 -> V_57 ) ;
F_40 ( V_8 -> V_63 ) ;
F_40 ( V_8 ) ;
}
static void F_45 ( struct V_85 * V_17 , void * V_86 )
{
struct V_2 * V_8 = * (struct V_2 * * ) V_86 ;
F_41 ( V_8 -> V_4 , V_8 ) ;
}
static int F_46 ( struct V_85 * V_17 , void * V_86 , void * V_3 )
{
struct V_2 * * V_87 = V_86 ;
if ( ! V_87 || ! * V_87 ) {
F_47 ( ! V_87 || ! * V_87 ) ;
return 0 ;
}
return * V_87 == V_3 ;
}
int F_48 ( struct V_85 * V_17 , struct V_10 * V_11 , int V_4 ,
int V_75 , int V_76 ,
const struct V_51 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * * V_88 , * V_8 ;
int V_13 ;
V_88 = F_49 ( F_45 , sizeof( * V_88 ) ,
V_78 ) ;
if ( ! V_88 )
return - V_77 ;
V_13 = F_30 ( V_11 , V_4 , V_75 , V_76 ,
V_5 , & V_8 ) ;
if ( V_13 < 0 ) {
F_50 ( V_88 ) ;
return V_13 ;
}
* V_88 = V_8 ;
F_51 ( V_17 , V_88 ) ;
* V_3 = V_8 ;
return 0 ;
}
void F_52 ( struct V_85 * V_17 , int V_4 ,
struct V_2 * V_3 )
{
int V_89 ;
F_47 ( V_4 != V_3 -> V_4 ) ;
V_89 = F_53 ( V_17 , F_45 ,
F_46 , V_3 ) ;
if ( V_89 != 0 )
F_47 ( V_89 ) ;
}
int F_54 ( struct V_2 * V_3 )
{
F_47 ( ! V_3 -> V_76 ) ;
return V_3 -> V_76 ;
}
int F_55 ( struct V_2 * V_3 , int V_4 )
{
if ( ! V_3 -> V_5 -> V_6 [ V_4 ] . V_42 )
return - V_49 ;
return F_56 ( V_3 -> V_65 , V_4 ) ;
}
struct V_69 * F_57 ( struct V_2 * V_3 )
{
if ( V_3 )
return V_3 -> V_65 ;
else
return NULL ;
}
