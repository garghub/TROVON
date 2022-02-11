static unsigned int
F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 = 0 ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
if ( V_7 || ! V_4 ) {
F_6 ( & V_8 ) ;
return - V_9 ;
}
F_3 ( & V_4 -> V_10 ) ;
F_6 ( & V_8 ) ;
if ( V_4 -> V_11 & V_12 ) {
F_7 ( V_13 L_1
L_2 , V_14 ) ;
goto V_15;
}
if ( V_4 -> V_11 & V_16 )
goto V_15;
if ( V_4 -> V_11 & V_17 )
goto V_15;
V_4 -> V_11 |= V_17 ;
F_6 ( & V_4 -> V_10 ) ;
F_8 ( V_1 , & V_4 -> V_18 , V_2 ) ;
F_3 ( & V_4 -> V_10 ) ;
if ( ! F_9 ( & V_4 -> V_19 ) )
V_5 |= V_20 | V_21 ;
V_15:
V_4 -> V_11 &= ~ V_17 ;
F_6 ( & V_4 -> V_10 ) ;
return V_5 ;
}
static int
F_10 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
struct V_3 * V_4 = NULL ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_11 ( V_23 ) ;
if ( V_7 == 0 ) {
V_7 = - V_24 ;
F_7 ( V_25 L_3
L_4 , V_14 , V_7 ) ;
goto V_26;
}
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
if ( V_7 || ! V_4 ) {
V_7 = F_12 ( & V_4 , V_6 , F_5 () ,
F_13 ( V_27 ) ) ;
if ( V_7 ) {
F_7 ( V_25 L_5
L_6 , V_14 , V_7 ) ;
goto V_28;
}
}
F_3 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_29 != F_13 ( V_27 ) ) {
V_7 = - V_9 ;
F_7 ( V_25 L_7
L_8
L_9 , V_14 , V_4 -> V_29 , V_4 -> V_6 ,
F_13 ( V_27 ) ) ;
goto V_15;
}
if ( V_4 -> V_11 & V_30 ) {
V_7 = - V_31 ;
F_7 ( V_25 L_10
L_11
L_12 , V_14 , V_4 -> V_29 ) ;
goto V_15;
}
V_4 -> V_11 |= V_30 ;
V_1 -> V_32 = V_4 ;
F_14 ( & V_33 ) ;
V_15:
F_6 ( & V_4 -> V_10 ) ;
V_28:
if ( V_7 )
F_15 ( V_23 ) ;
V_26:
F_6 ( & V_8 ) ;
return V_7 ;
}
static int
F_16 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
struct V_3 * V_4 = NULL ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
if ( V_7 || ! V_4 )
V_4 = V_1 -> V_32 ;
F_3 ( & V_4 -> V_10 ) ;
F_17 ( ! ( V_4 -> V_11 & V_30 ) ) ;
V_4 -> V_11 &= ~ V_30 ;
F_18 ( & V_33 ) ;
F_6 ( & V_4 -> V_10 ) ;
V_7 = F_19 ( V_4 ) ;
if ( V_7 ) {
F_7 ( V_34 L_13
L_14
L_15 , V_14 , V_7 ) ;
F_20 () ;
}
F_15 ( V_23 ) ;
F_6 ( & V_8 ) ;
return V_7 ;
}
int F_21 ( char * V_35 , T_3 V_36 ,
struct V_37 * V_38 , T_4 V_39 ,
T_5 V_40 , struct V_3 * V_4 )
{
struct V_41 * V_42 ;
V_42 = F_22 ( ( sizeof( * V_42 ) + V_36 ) , V_43 ) ;
if ( ! V_42 ) {
F_7 ( V_25 L_16
L_17 , V_14 ,
( sizeof( * V_42 ) + V_36 ) ) ;
return - V_44 ;
}
F_3 ( & V_38 -> V_10 ) ;
V_38 -> V_42 = V_42 ;
V_38 -> V_42 -> V_45 = V_38 -> V_45 ;
V_38 -> V_42 -> V_46 = V_36 ;
V_38 -> type = V_39 ;
memcpy ( V_38 -> V_42 -> V_35 , V_35 , V_36 ) ;
V_38 -> V_47 = ( sizeof( * V_38 -> V_42 ) + V_36 ) ;
F_23 ( & V_38 -> V_48 , & V_4 -> V_19 ) ;
F_6 ( & V_38 -> V_10 ) ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_49 ++ ;
F_24 ( & V_4 -> V_18 ) ;
F_6 ( & V_4 -> V_10 ) ;
return 0 ;
}
static T_6
F_25 ( struct V_1 * V_1 , char T_7 * V_50 , T_3 V_51 ,
T_8 * V_52 )
{
struct V_3 * V_4 ;
struct V_37 * V_38 ;
T_3 V_53 ;
char V_54 [ V_55 ] ;
T_3 V_56 ;
T_3 V_57 ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
if ( V_7 || ! V_4 ) {
F_6 ( & V_8 ) ;
return - V_9 ;
}
F_3 ( & V_4 -> V_10 ) ;
if ( F_13 ( V_27 ) != V_4 -> V_29 ) {
F_6 ( & V_4 -> V_10 ) ;
F_6 ( & V_8 ) ;
return - V_58 ;
}
if ( V_4 -> V_11 & V_12 ) {
V_7 = 0 ;
F_6 ( & V_8 ) ;
F_7 ( V_13 L_18
L_2 , V_14 ) ;
goto V_15;
}
if ( V_4 -> V_11 & V_16 ) {
V_7 = 0 ;
F_6 ( & V_8 ) ;
goto V_15;
}
V_4 -> V_11 |= V_16 ;
F_6 ( & V_8 ) ;
V_59:
if ( F_9 ( & V_4 -> V_19 ) ) {
F_6 ( & V_4 -> V_10 ) ;
V_7 = F_26 (
V_4 -> V_18 , ! F_9 ( & V_4 -> V_19 ) ) ;
F_3 ( & V_4 -> V_10 ) ;
if ( V_7 < 0 ) {
V_7 = 0 ;
goto V_15;
}
}
if ( V_4 -> V_11 & V_12 ) {
V_7 = 0 ;
goto V_15;
}
if ( F_9 ( & V_4 -> V_19 ) ) {
goto V_59;
}
V_38 = F_27 ( & V_4 -> V_19 ,
struct V_37 , V_48 ) ;
F_17 ( ! V_38 ) ;
F_3 ( & V_38 -> V_10 ) ;
if ( V_38 -> V_42 ) {
V_7 = F_28 ( V_54 ,
V_38 -> V_47 ,
& V_53 ) ;
if ( V_7 ) {
V_7 = 0 ;
F_7 ( V_13 L_19
L_6 , V_14 , V_7 ) ;
goto V_60;
}
} else {
V_53 = 0 ;
V_38 -> V_47 = 0 ;
}
V_57 = ( V_61 + V_62 + V_53
+ V_38 -> V_47 ) ;
if ( V_51 < V_57 ) {
V_7 = 0 ;
F_7 ( V_13 L_20
L_21
L_22 , V_14 , V_51 , V_57 ) ;
goto V_60;
}
V_7 = - V_63 ;
if ( F_29 ( V_38 -> type , V_50 ) )
goto V_60;
if ( F_29 ( F_30 ( V_38 -> V_64 ) ,
( V_65 T_7 * ) ( & V_50 [ V_66 ] ) ) )
goto V_60;
V_56 = V_61 + V_62 ;
if ( V_38 -> V_42 ) {
if ( F_31 ( & V_50 [ V_56 ] , V_54 , V_53 ) )
goto V_60;
V_56 += V_53 ;
if ( F_31 ( & V_50 [ V_56 ] , V_38 -> V_42 , V_38 -> V_47 ) )
goto V_60;
V_56 += V_38 -> V_47 ;
}
V_7 = V_56 ;
F_32 ( & V_38 -> V_48 ) ;
F_33 ( V_38 -> V_42 ) ;
V_38 -> V_42 = NULL ;
if ( V_38 -> type != V_67 )
F_34 ( V_38 ) ;
V_60:
F_6 ( & V_38 -> V_10 ) ;
V_15:
V_4 -> V_11 &= ~ V_16 ;
F_6 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static int F_35 ( char * V_35 , T_3 V_36 ,
T_2 V_6 , struct V_68 * V_69 ,
struct V_29 * V_29 , T_9 V_70 )
{
struct V_41 * V_42 = (struct V_41 * ) V_35 ;
int V_7 ;
if ( ( sizeof( * V_42 ) + V_42 -> V_46 ) != V_36 ) {
F_7 ( V_13 L_23
L_24 , V_14 ,
( sizeof( * V_42 ) + V_42 -> V_46 ) , V_36 ) ;
V_7 = - V_9 ;
goto V_71;
}
V_7 = F_36 ( V_42 , V_6 , V_69 , V_29 , V_70 ) ;
if ( V_7 )
F_7 ( V_25
L_25 , V_7 ) ;
V_71:
return V_7 ;
}
static T_6
F_37 ( struct V_1 * V_1 , const char T_7 * V_50 ,
T_3 V_51 , T_8 * V_52 )
{
V_65 V_72 ;
T_9 V_70 ;
T_3 V_73 , V_74 ;
char * V_35 ;
T_2 V_6 = F_2 () ;
unsigned char V_75 [ V_55 ] ;
T_6 V_7 ;
if ( V_51 == 0 ) {
return 0 ;
} else if ( V_51 == V_76 ) {
goto V_77;
} else if ( V_51 < V_78 || V_51 > V_79 ) {
F_7 ( V_13 L_26
L_27 ,
V_14 , V_78 , V_79 , V_51 ) ;
return - V_9 ;
}
if ( F_38 ( V_75 , & V_50 [ V_80 ] ,
sizeof( V_75 ) ) ) {
F_7 ( V_13 L_28 ,
V_14 ) ;
return - V_63 ;
}
V_7 = F_39 ( V_75 , & V_73 ,
& V_74 ) ;
if ( V_7 ) {
F_7 ( V_13 L_29
L_30 , V_14 , V_7 ) ;
return V_7 ;
}
if ( ( V_61 + V_62 + V_74 + V_73 )
!= V_51 ) {
F_7 ( V_13 L_31 , V_14 ,
V_73 ) ;
return - V_9 ;
}
V_77:
V_35 = F_40 ( V_50 , V_51 ) ;
if ( F_41 ( V_35 ) ) {
F_7 ( V_25 L_32 ,
V_14 , F_42 ( V_35 ) ) ;
return F_42 ( V_35 ) ;
}
switch ( V_35 [ V_81 ] ) {
case V_82 :
if ( V_51 < ( V_78
+ sizeof( struct V_41 ) ) ) {
F_7 ( V_13 L_33
L_34
L_35 ,
V_14 ,
( V_78
+ sizeof( struct V_41 ) ) , V_51 ) ;
V_7 = - V_9 ;
goto V_83;
}
memcpy ( & V_72 , & V_35 [ V_66 ] , V_62 ) ;
V_70 = F_43 ( V_72 ) ;
V_7 = F_35 (
& V_35 [ V_80 + V_74 ] ,
V_73 , V_6 , F_5 () ,
F_13 ( V_27 ) , V_70 ) ;
if ( V_7 ) {
F_7 ( V_13 L_36
L_37 ,
V_14 , V_7 ) ;
goto V_83;
}
break;
case V_84 :
case V_85 :
break;
default:
F_44 ( V_13 , L_38
L_39 ,
V_35 [ 0 ] ) ;
V_7 = - V_9 ;
goto V_83;
}
V_7 = V_51 ;
V_83:
F_33 ( V_35 ) ;
return V_7 ;
}
int T_10 F_45 ( void )
{
int V_7 ;
F_46 ( & V_33 , 0 ) ;
V_7 = F_47 ( & V_86 ) ;
if ( V_7 )
F_7 ( V_25 L_40
L_41 ,
V_14 , V_7 ) ;
return V_7 ;
}
void F_48 ( void )
{
F_17 ( F_49 ( & V_33 ) != 0 ) ;
F_50 ( & V_86 ) ;
}
