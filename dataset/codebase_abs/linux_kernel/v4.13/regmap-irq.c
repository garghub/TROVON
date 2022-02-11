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
static int F_5 ( struct V_2 * V_8 ,
unsigned int V_10 , unsigned int V_11 ,
unsigned int V_12 )
{
if ( V_8 -> V_5 -> V_13 )
return F_6 ( V_8 -> V_14 , V_10 , V_11 , V_12 ) ;
else
return F_7 ( V_8 -> V_14 , V_10 , V_11 , V_12 ) ;
}
static void F_8 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_15 * V_14 = V_8 -> V_14 ;
int V_16 , V_17 ;
T_1 V_10 ;
T_1 V_18 ;
if ( V_8 -> V_5 -> V_19 ) {
V_17 = F_9 ( V_14 -> V_20 ) ;
if ( V_17 < 0 )
F_10 ( V_14 -> V_20 , L_1 ,
V_17 ) ;
}
for ( V_16 = 0 ; V_16 < V_8 -> V_5 -> V_21 ; V_16 ++ ) {
V_10 = V_8 -> V_5 -> V_22 +
( V_16 * V_14 -> V_23 * V_8 -> V_24 ) ;
if ( V_8 -> V_5 -> V_25 ) {
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_26 [ V_16 ] , ~ V_8 -> V_27 [ V_16 ] ) ;
} else if ( V_8 -> V_5 -> V_28 ) {
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_26 [ V_16 ] , ~ V_8 -> V_27 [ V_16 ] ) ;
if ( V_17 < 0 )
F_10 ( V_8 -> V_14 -> V_20 ,
L_2 ,
V_10 ) ;
V_18 = V_8 -> V_5 -> V_28 -
V_8 -> V_5 -> V_22 ;
V_17 = F_5 ( V_8 ,
V_10 + V_18 ,
V_8 -> V_26 [ V_16 ] ,
V_8 -> V_27 [ V_16 ] ) ;
} else {
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_26 [ V_16 ] , V_8 -> V_27 [ V_16 ] ) ;
}
if ( V_17 != 0 )
F_10 ( V_8 -> V_14 -> V_20 , L_3 ,
V_10 ) ;
V_10 = V_8 -> V_5 -> V_29 +
( V_16 * V_14 -> V_23 * V_8 -> V_24 ) ;
if ( V_8 -> V_30 ) {
if ( V_8 -> V_5 -> V_31 )
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_26 [ V_16 ] ,
~ V_8 -> V_30 [ V_16 ] ) ;
else
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_26 [ V_16 ] ,
V_8 -> V_30 [ V_16 ] ) ;
if ( V_17 != 0 )
F_10 ( V_8 -> V_14 -> V_20 ,
L_4 ,
V_10 , V_17 ) ;
}
if ( ! V_8 -> V_5 -> V_32 )
continue;
if ( V_8 -> V_27 [ V_16 ] && ( V_8 -> V_5 -> V_33 || V_8 -> V_5 -> V_34 ) ) {
V_10 = V_8 -> V_5 -> V_33 +
( V_16 * V_14 -> V_23 * V_8 -> V_24 ) ;
if ( V_8 -> V_5 -> V_35 )
V_17 = F_11 ( V_14 , V_10 , ~ V_8 -> V_27 [ V_16 ] ) ;
else
V_17 = F_11 ( V_14 , V_10 , V_8 -> V_27 [ V_16 ] ) ;
if ( V_17 != 0 )
F_10 ( V_8 -> V_14 -> V_20 , L_5 ,
V_10 , V_17 ) ;
}
}
for ( V_16 = 0 ; V_16 < V_8 -> V_5 -> V_36 ; V_16 ++ ) {
if ( ! V_8 -> V_37 [ V_16 ] )
continue;
V_10 = V_8 -> V_5 -> V_38 +
( V_16 * V_14 -> V_23 * V_8 -> V_39 ) ;
if ( V_8 -> V_5 -> V_40 )
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_37 [ V_16 ] , ~ V_8 -> V_41 [ V_16 ] ) ;
else
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_37 [ V_16 ] , V_8 -> V_41 [ V_16 ] ) ;
if ( V_17 != 0 )
F_10 ( V_8 -> V_14 -> V_20 , L_6 ,
V_10 ) ;
}
if ( V_8 -> V_5 -> V_19 )
F_12 ( V_14 -> V_20 ) ;
if ( V_8 -> V_42 < 0 )
for ( V_16 = V_8 -> V_42 ; V_16 < 0 ; V_16 ++ )
F_13 ( V_8 -> V_4 , 0 ) ;
else if ( V_8 -> V_42 > 0 )
for ( V_16 = 0 ; V_16 < V_8 -> V_42 ; V_16 ++ )
F_13 ( V_8 -> V_4 , 1 ) ;
V_8 -> V_42 = 0 ;
F_14 ( & V_8 -> V_9 ) ;
}
static void F_15 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_15 * V_14 = V_8 -> V_14 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_43 ) ;
V_8 -> V_27 [ V_7 -> V_44 / V_14 -> V_23 ] &= ~ V_7 -> V_11 ;
}
static void F_16 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_15 * V_14 = V_8 -> V_14 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_43 ) ;
V_8 -> V_27 [ V_7 -> V_44 / V_14 -> V_23 ] |= V_7 -> V_11 ;
}
static int F_17 ( struct V_7 * V_3 , unsigned int type )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_15 * V_14 = V_8 -> V_14 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_43 ) ;
int V_10 = V_7 -> V_45 / V_14 -> V_23 ;
if ( ! ( V_7 -> V_46 | V_7 -> V_47 ) )
return 0 ;
V_8 -> V_41 [ V_10 ] &= ~ ( V_7 -> V_47 |
V_7 -> V_46 ) ;
switch ( type ) {
case V_48 :
V_8 -> V_41 [ V_10 ] |= V_7 -> V_47 ;
break;
case V_49 :
V_8 -> V_41 [ V_10 ] |= V_7 -> V_46 ;
break;
case V_50 :
V_8 -> V_41 [ V_10 ] |= ( V_7 -> V_47 |
V_7 -> V_46 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_18 ( struct V_7 * V_3 , unsigned int V_52 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_15 * V_14 = V_8 -> V_14 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_43 ) ;
if ( V_52 ) {
if ( V_8 -> V_30 )
V_8 -> V_30 [ V_7 -> V_44 / V_14 -> V_23 ]
&= ~ V_7 -> V_11 ;
V_8 -> V_42 ++ ;
} else {
if ( V_8 -> V_30 )
V_8 -> V_30 [ V_7 -> V_44 / V_14 -> V_23 ]
|= V_7 -> V_11 ;
V_8 -> V_42 -- ;
}
return 0 ;
}
static T_2 F_19 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
const struct V_53 * V_5 = V_3 -> V_5 ;
struct V_15 * V_14 = V_3 -> V_14 ;
int V_17 , V_16 ;
bool V_54 = false ;
T_1 V_10 ;
if ( V_5 -> V_55 )
V_5 -> V_55 ( V_5 -> V_56 ) ;
if ( V_5 -> V_19 ) {
V_17 = F_9 ( V_14 -> V_20 ) ;
if ( V_17 < 0 ) {
F_10 ( V_14 -> V_20 , L_7 ,
V_17 ) ;
F_12 ( V_14 -> V_20 ) ;
goto exit;
}
}
if ( ! V_14 -> V_57 && V_14 -> V_23 == 1 &&
V_3 -> V_24 == 1 ) {
T_3 * V_58 = V_3 -> V_59 ;
T_4 * V_60 = V_3 -> V_59 ;
T_1 * V_61 = V_3 -> V_59 ;
F_20 ( ! V_3 -> V_59 ) ;
V_17 = F_21 ( V_14 , V_5 -> V_62 ,
V_3 -> V_59 ,
V_5 -> V_21 ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 , L_8 ,
V_17 ) ;
goto exit;
}
for ( V_16 = 0 ; V_16 < V_3 -> V_5 -> V_21 ; V_16 ++ ) {
switch ( V_14 -> V_63 . V_64 ) {
case 1 :
V_3 -> V_65 [ V_16 ] = V_58 [ V_16 ] ;
break;
case 2 :
V_3 -> V_65 [ V_16 ] = V_60 [ V_16 ] ;
break;
case 4 :
V_3 -> V_65 [ V_16 ] = V_61 [ V_16 ] ;
break;
default:
F_22 () ;
goto exit;
}
}
} else {
for ( V_16 = 0 ; V_16 < V_3 -> V_5 -> V_21 ; V_16 ++ ) {
V_17 = F_23 ( V_14 , V_5 -> V_62 +
( V_16 * V_14 -> V_23
* V_3 -> V_24 ) ,
& V_3 -> V_65 [ V_16 ] ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 ,
L_8 ,
V_17 ) ;
if ( V_5 -> V_19 )
F_12 ( V_14 -> V_20 ) ;
goto exit;
}
}
}
for ( V_16 = 0 ; V_16 < V_3 -> V_5 -> V_21 ; V_16 ++ ) {
V_3 -> V_65 [ V_16 ] &= ~ V_3 -> V_27 [ V_16 ] ;
if ( V_3 -> V_65 [ V_16 ] && ( V_5 -> V_33 || V_5 -> V_34 ) ) {
V_10 = V_5 -> V_33 +
( V_16 * V_14 -> V_23 * V_3 -> V_24 ) ;
V_17 = F_11 ( V_14 , V_10 , V_3 -> V_65 [ V_16 ] ) ;
if ( V_17 != 0 )
F_10 ( V_14 -> V_20 , L_5 ,
V_10 , V_17 ) ;
}
}
for ( V_16 = 0 ; V_16 < V_5 -> V_66 ; V_16 ++ ) {
if ( V_3 -> V_65 [ V_5 -> V_6 [ V_16 ] . V_44 /
V_14 -> V_23 ] & V_5 -> V_6 [ V_16 ] . V_11 ) {
F_24 ( F_25 ( V_3 -> V_67 , V_16 ) ) ;
V_54 = true ;
}
}
if ( V_5 -> V_19 )
F_12 ( V_14 -> V_20 ) ;
exit:
if ( V_5 -> V_68 )
V_5 -> V_68 ( V_5 -> V_56 ) ;
if ( V_54 )
return V_69 ;
else
return V_70 ;
}
static int F_26 ( struct V_71 * V_72 , unsigned int V_73 ,
T_5 V_74 )
{
struct V_2 * V_3 = V_72 -> V_75 ;
F_27 ( V_73 , V_3 ) ;
F_28 ( V_73 , & V_3 -> V_76 ) ;
F_29 ( V_73 , 1 ) ;
F_30 ( V_73 , V_3 -> V_4 ) ;
F_31 ( V_73 ) ;
return 0 ;
}
int F_32 ( struct V_15 * V_14 , int V_4 , int V_77 ,
int V_78 , const struct V_53 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * V_8 ;
int V_16 ;
int V_17 = - V_79 ;
T_1 V_10 ;
T_1 V_18 ;
if ( V_5 -> V_21 <= 0 )
return - V_51 ;
for ( V_16 = 0 ; V_16 < V_5 -> V_66 ; V_16 ++ ) {
if ( V_5 -> V_6 [ V_16 ] . V_44 % V_14 -> V_23 )
return - V_51 ;
if ( V_5 -> V_6 [ V_16 ] . V_44 / V_14 -> V_23 >=
V_5 -> V_21 )
return - V_51 ;
}
if ( V_78 ) {
V_78 = F_33 ( V_78 , 0 , V_5 -> V_66 , 0 ) ;
if ( V_78 < 0 ) {
F_34 ( V_14 -> V_20 , L_9 ,
V_78 ) ;
return V_78 ;
}
}
V_8 = F_35 ( sizeof( * V_8 ) , V_80 ) ;
if ( ! V_8 )
return - V_79 ;
V_8 -> V_65 = F_36 ( V_5 -> V_21 , sizeof( unsigned int ) ,
V_80 ) ;
if ( ! V_8 -> V_65 )
goto V_81;
V_8 -> V_27 = F_36 ( V_5 -> V_21 , sizeof( unsigned int ) ,
V_80 ) ;
if ( ! V_8 -> V_27 )
goto V_81;
V_8 -> V_26 = F_36 ( V_5 -> V_21 , sizeof( unsigned int ) ,
V_80 ) ;
if ( ! V_8 -> V_26 )
goto V_81;
if ( V_5 -> V_29 ) {
V_8 -> V_30 = F_36 ( V_5 -> V_21 , sizeof( unsigned int ) ,
V_80 ) ;
if ( ! V_8 -> V_30 )
goto V_81;
}
if ( V_5 -> V_36 ) {
V_8 -> V_37 = F_36 ( V_5 -> V_36 ,
sizeof( unsigned int ) , V_80 ) ;
if ( ! V_8 -> V_37 )
goto V_81;
V_8 -> V_41 = F_36 ( V_5 -> V_36 , sizeof( unsigned int ) ,
V_80 ) ;
if ( ! V_8 -> V_41 )
goto V_81;
}
V_8 -> V_76 = V_53 ;
V_8 -> V_76 . V_82 = V_5 -> V_82 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_78 = V_78 ;
if ( V_5 -> V_24 )
V_8 -> V_24 = V_5 -> V_24 ;
else
V_8 -> V_24 = 1 ;
if ( V_5 -> V_39 )
V_8 -> V_39 = V_5 -> V_39 ;
else
V_8 -> V_39 = 1 ;
if ( ! V_14 -> V_57 && V_14 -> V_23 == 1 &&
V_8 -> V_24 == 1 ) {
V_8 -> V_59 = F_37 ( V_5 -> V_21 ,
V_14 -> V_63 . V_64 ,
V_80 ) ;
if ( ! V_8 -> V_59 )
goto V_81;
}
F_38 ( & V_8 -> V_9 ) ;
for ( V_16 = 0 ; V_16 < V_5 -> V_66 ; V_16 ++ )
V_8 -> V_26 [ V_5 -> V_6 [ V_16 ] . V_44 / V_14 -> V_23 ]
|= V_5 -> V_6 [ V_16 ] . V_11 ;
for ( V_16 = 0 ; V_16 < V_5 -> V_21 ; V_16 ++ ) {
V_8 -> V_27 [ V_16 ] = V_8 -> V_26 [ V_16 ] ;
V_10 = V_5 -> V_22 +
( V_16 * V_14 -> V_23 * V_8 -> V_24 ) ;
if ( V_5 -> V_25 )
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_27 [ V_16 ] , ~ V_8 -> V_27 [ V_16 ] ) ;
else if ( V_8 -> V_5 -> V_28 ) {
V_18 = V_8 -> V_5 -> V_28 -
V_8 -> V_5 -> V_22 ;
V_17 = F_5 ( V_8 ,
V_10 + V_18 ,
V_8 -> V_27 [ V_16 ] ,
V_8 -> V_27 [ V_16 ] ) ;
} else
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_27 [ V_16 ] , V_8 -> V_27 [ V_16 ] ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 , L_10 ,
V_10 , V_17 ) ;
goto V_81;
}
if ( ! V_5 -> V_32 )
continue;
V_10 = V_5 -> V_62 +
( V_16 * V_14 -> V_23 * V_8 -> V_24 ) ;
V_17 = F_23 ( V_14 , V_10 , & V_8 -> V_65 [ V_16 ] ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 , L_8 ,
V_17 ) ;
goto V_81;
}
if ( V_8 -> V_65 [ V_16 ] && ( V_5 -> V_33 || V_5 -> V_34 ) ) {
V_10 = V_5 -> V_33 +
( V_16 * V_14 -> V_23 * V_8 -> V_24 ) ;
if ( V_5 -> V_35 )
V_17 = F_11 ( V_14 , V_10 ,
~ ( V_8 -> V_65 [ V_16 ] & V_8 -> V_27 [ V_16 ] ) ) ;
else
V_17 = F_11 ( V_14 , V_10 ,
V_8 -> V_65 [ V_16 ] & V_8 -> V_27 [ V_16 ] ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 , L_5 ,
V_10 , V_17 ) ;
goto V_81;
}
}
}
if ( V_8 -> V_30 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_21 ; V_16 ++ ) {
V_8 -> V_30 [ V_16 ] = V_8 -> V_26 [ V_16 ] ;
V_10 = V_5 -> V_29 +
( V_16 * V_14 -> V_23 * V_8 -> V_24 ) ;
if ( V_5 -> V_31 )
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_26 [ V_16 ] ,
0 ) ;
else
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_26 [ V_16 ] ,
V_8 -> V_30 [ V_16 ] ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 , L_10 ,
V_10 , V_17 ) ;
goto V_81;
}
}
}
if ( V_5 -> V_36 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_66 ; V_16 ++ ) {
V_10 = V_5 -> V_6 [ V_16 ] . V_45 / V_14 -> V_23 ;
V_8 -> V_37 [ V_10 ] |= V_5 -> V_6 [ V_16 ] . V_46 |
V_5 -> V_6 [ V_16 ] . V_47 ;
}
for ( V_16 = 0 ; V_16 < V_5 -> V_36 ; ++ V_16 ) {
if ( ! V_8 -> V_37 [ V_16 ] )
continue;
V_10 = V_5 -> V_38 +
( V_16 * V_14 -> V_23 * V_8 -> V_39 ) ;
if ( V_5 -> V_40 )
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_37 [ V_16 ] , 0xFF ) ;
else
V_17 = F_5 ( V_8 , V_10 ,
V_8 -> V_37 [ V_16 ] , 0x0 ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 ,
L_11 ,
V_10 , V_17 ) ;
goto V_81;
}
}
}
if ( V_78 )
V_8 -> V_67 = F_39 ( V_14 -> V_20 -> V_83 ,
V_5 -> V_66 , V_78 , 0 ,
& V_84 , V_8 ) ;
else
V_8 -> V_67 = F_40 ( V_14 -> V_20 -> V_83 ,
V_5 -> V_66 ,
& V_84 , V_8 ) ;
if ( ! V_8 -> V_67 ) {
F_10 ( V_14 -> V_20 , L_12 ) ;
V_17 = - V_79 ;
goto V_81;
}
V_17 = F_41 ( V_4 , NULL , F_19 ,
V_77 | V_85 ,
V_5 -> V_82 , V_8 ) ;
if ( V_17 != 0 ) {
F_10 ( V_14 -> V_20 , L_13 ,
V_4 , V_5 -> V_82 , V_17 ) ;
goto V_86;
}
* V_3 = V_8 ;
return 0 ;
V_86:
V_81:
F_42 ( V_8 -> V_41 ) ;
F_42 ( V_8 -> V_37 ) ;
F_42 ( V_8 -> V_30 ) ;
F_42 ( V_8 -> V_26 ) ;
F_42 ( V_8 -> V_27 ) ;
F_42 ( V_8 -> V_65 ) ;
F_42 ( V_8 -> V_59 ) ;
F_42 ( V_8 ) ;
return V_17 ;
}
void F_43 ( int V_4 , struct V_2 * V_8 )
{
unsigned int V_73 ;
int V_43 ;
if ( ! V_8 )
return;
F_44 ( V_4 , V_8 ) ;
for ( V_43 = 0 ; V_43 < V_8 -> V_5 -> V_66 ; V_43 ++ ) {
if ( ! V_8 -> V_5 -> V_6 [ V_43 ] . V_11 )
continue;
V_73 = F_25 ( V_8 -> V_67 , V_43 ) ;
if ( V_73 )
F_45 ( V_73 ) ;
}
F_46 ( V_8 -> V_67 ) ;
F_42 ( V_8 -> V_41 ) ;
F_42 ( V_8 -> V_37 ) ;
F_42 ( V_8 -> V_30 ) ;
F_42 ( V_8 -> V_26 ) ;
F_42 ( V_8 -> V_27 ) ;
F_42 ( V_8 -> V_59 ) ;
F_42 ( V_8 -> V_65 ) ;
F_42 ( V_8 ) ;
}
static void F_47 ( struct V_87 * V_20 , void * V_88 )
{
struct V_2 * V_8 = * (struct V_2 * * ) V_88 ;
F_43 ( V_8 -> V_4 , V_8 ) ;
}
static int F_48 ( struct V_87 * V_20 , void * V_88 , void * V_3 )
{
struct V_2 * * V_89 = V_88 ;
if ( ! V_89 || ! * V_89 ) {
F_49 ( ! V_89 || ! * V_89 ) ;
return 0 ;
}
return * V_89 == V_3 ;
}
int F_50 ( struct V_87 * V_20 , struct V_15 * V_14 , int V_4 ,
int V_77 , int V_78 ,
const struct V_53 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * * V_90 , * V_8 ;
int V_17 ;
V_90 = F_51 ( F_47 , sizeof( * V_90 ) ,
V_80 ) ;
if ( ! V_90 )
return - V_79 ;
V_17 = F_32 ( V_14 , V_4 , V_77 , V_78 ,
V_5 , & V_8 ) ;
if ( V_17 < 0 ) {
F_52 ( V_90 ) ;
return V_17 ;
}
* V_90 = V_8 ;
F_53 ( V_20 , V_90 ) ;
* V_3 = V_8 ;
return 0 ;
}
void F_54 ( struct V_87 * V_20 , int V_4 ,
struct V_2 * V_3 )
{
int V_91 ;
F_49 ( V_4 != V_3 -> V_4 ) ;
V_91 = F_55 ( V_20 , F_47 ,
F_48 , V_3 ) ;
if ( V_91 != 0 )
F_49 ( V_91 ) ;
}
int F_56 ( struct V_2 * V_3 )
{
F_49 ( ! V_3 -> V_78 ) ;
return V_3 -> V_78 ;
}
int F_57 ( struct V_2 * V_3 , int V_4 )
{
if ( ! V_3 -> V_5 -> V_6 [ V_4 ] . V_11 )
return - V_51 ;
return F_58 ( V_3 -> V_67 , V_4 ) ;
}
struct V_71 * F_59 ( struct V_2 * V_3 )
{
if ( V_3 )
return V_3 -> V_67 ;
else
return NULL ;
}
