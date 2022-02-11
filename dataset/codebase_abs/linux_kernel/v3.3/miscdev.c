static unsigned int
F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 = 0 ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
F_6 ( V_7 || ! V_4 ) ;
F_3 ( & V_4 -> V_9 ) ;
F_7 ( & V_8 ) ;
if ( V_4 -> V_10 & V_11 ) {
F_8 ( V_12 L_1
L_2 , V_13 ) ;
goto V_14;
}
if ( V_4 -> V_10 & V_15 )
goto V_14;
if ( V_4 -> V_10 & V_16 )
goto V_14;
V_4 -> V_10 |= V_16 ;
F_7 ( & V_4 -> V_9 ) ;
F_9 ( V_1 , & V_4 -> V_17 , V_2 ) ;
F_3 ( & V_4 -> V_9 ) ;
if ( ! F_10 ( & V_4 -> V_18 ) )
V_5 |= V_19 | V_20 ;
V_14:
V_4 -> V_10 &= ~ V_16 ;
F_7 ( & V_4 -> V_9 ) ;
return V_5 ;
}
static int
F_11 ( struct V_21 * V_21 , struct V_1 * V_1 )
{
struct V_3 * V_4 = NULL ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_12 ( V_22 ) ;
if ( V_7 == 0 ) {
V_7 = - V_23 ;
F_8 ( V_24 L_3
L_4 , V_13 , V_7 ) ;
goto V_25;
}
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
if ( V_7 || ! V_4 ) {
V_7 = F_13 ( & V_4 , V_6 , F_5 () ,
F_14 ( V_26 ) ) ;
if ( V_7 ) {
F_8 ( V_24 L_5
L_6 , V_13 , V_7 ) ;
goto V_27;
}
}
F_3 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_28 != F_14 ( V_26 ) ) {
V_7 = - V_29 ;
F_8 ( V_24 L_7
L_8
L_9 , V_13 , V_4 -> V_28 , V_4 -> V_6 ,
F_14 ( V_26 ) ) ;
goto V_14;
}
if ( V_4 -> V_10 & V_30 ) {
V_7 = - V_31 ;
F_8 ( V_24 L_10
L_11
L_12 , V_13 , V_4 -> V_28 ) ;
goto V_14;
}
V_4 -> V_10 |= V_30 ;
F_15 ( & V_32 ) ;
V_14:
F_7 ( & V_4 -> V_9 ) ;
V_27:
if ( V_7 )
F_16 ( V_22 ) ;
V_25:
F_7 ( & V_8 ) ;
return V_7 ;
}
static int
F_17 ( struct V_21 * V_21 , struct V_1 * V_1 )
{
struct V_3 * V_4 = NULL ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
F_6 ( V_7 || ! V_4 ) ;
F_3 ( & V_4 -> V_9 ) ;
F_6 ( V_4 -> V_28 != F_14 ( V_26 ) ) ;
F_6 ( ! ( V_4 -> V_10 & V_30 ) ) ;
V_4 -> V_10 &= ~ V_30 ;
F_18 ( & V_32 ) ;
F_7 ( & V_4 -> V_9 ) ;
V_7 = F_19 ( V_4 ) ;
if ( V_7 ) {
F_8 ( V_33 L_13
L_14
L_15 , V_13 , V_7 ) ;
F_20 () ;
}
F_16 ( V_22 ) ;
F_7 ( & V_8 ) ;
return V_7 ;
}
int F_21 ( char * V_34 , T_3 V_35 ,
struct V_36 * V_37 , T_4 V_38 ,
T_5 V_39 , struct V_3 * V_4 )
{
int V_7 = 0 ;
F_3 ( & V_37 -> V_9 ) ;
V_37 -> V_40 = F_22 ( ( sizeof( * V_37 -> V_40 ) + V_35 ) ,
V_41 ) ;
if ( ! V_37 -> V_40 ) {
V_7 = - V_42 ;
F_8 ( V_24 L_16
L_17 , V_13 ,
( sizeof( * V_37 -> V_40 ) + V_35 ) ) ;
goto V_43;
}
V_37 -> V_40 -> V_44 = V_37 -> V_44 ;
V_37 -> V_40 -> V_45 = V_35 ;
V_37 -> type = V_38 ;
memcpy ( V_37 -> V_40 -> V_34 , V_34 , V_35 ) ;
V_37 -> V_46 = ( sizeof( * V_37 -> V_40 ) + V_35 ) ;
F_3 ( & V_4 -> V_9 ) ;
F_23 ( & V_37 -> V_47 , & V_4 -> V_18 ) ;
V_4 -> V_48 ++ ;
F_24 ( & V_4 -> V_17 ) ;
F_7 ( & V_4 -> V_9 ) ;
V_43:
F_7 ( & V_37 -> V_9 ) ;
return V_7 ;
}
static T_6
F_25 ( struct V_1 * V_1 , char T_7 * V_49 , T_3 V_50 ,
T_8 * V_51 )
{
struct V_3 * V_4 ;
struct V_36 * V_37 ;
T_3 V_52 ;
char V_53 [ V_54 ] ;
T_3 V_55 ;
T_3 V_56 ;
T_2 V_6 = F_2 () ;
int V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( & V_4 , V_6 , F_5 () ) ;
F_6 ( V_7 || ! V_4 ) ;
F_3 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_10 & V_11 ) {
V_7 = 0 ;
F_7 ( & V_8 ) ;
F_8 ( V_12 L_18
L_2 , V_13 ) ;
goto V_14;
}
if ( V_4 -> V_10 & V_15 ) {
V_7 = 0 ;
F_7 ( & V_8 ) ;
goto V_14;
}
V_4 -> V_10 |= V_15 ;
F_7 ( & V_8 ) ;
V_57:
if ( F_10 ( & V_4 -> V_18 ) ) {
F_7 ( & V_4 -> V_9 ) ;
V_7 = F_26 (
V_4 -> V_17 , ! F_10 ( & V_4 -> V_18 ) ) ;
F_3 ( & V_4 -> V_9 ) ;
if ( V_7 < 0 ) {
V_7 = 0 ;
goto V_14;
}
}
if ( V_4 -> V_10 & V_11 ) {
V_7 = 0 ;
goto V_14;
}
if ( F_10 ( & V_4 -> V_18 ) ) {
goto V_57;
}
F_6 ( V_6 != V_4 -> V_6 ) ;
F_6 ( F_5 () != V_4 -> V_58 ) ;
F_6 ( F_14 ( V_26 ) != V_4 -> V_28 ) ;
V_37 = F_27 ( & V_4 -> V_18 ,
struct V_36 , V_47 ) ;
F_6 ( ! V_37 ) ;
F_3 ( & V_37 -> V_9 ) ;
if ( V_37 -> V_40 ) {
V_7 = F_28 ( V_53 ,
V_37 -> V_46 ,
& V_52 ) ;
if ( V_7 ) {
V_7 = 0 ;
F_8 ( V_12 L_19
L_6 , V_13 , V_7 ) ;
goto V_59;
}
} else {
V_52 = 0 ;
V_37 -> V_46 = 0 ;
}
V_56 = ( V_60 + V_61 + V_52
+ V_37 -> V_46 ) ;
if ( V_50 < V_56 ) {
V_7 = 0 ;
F_8 ( V_12 L_20
L_21
L_22 , V_13 , V_50 , V_56 ) ;
goto V_59;
}
V_7 = - V_62 ;
if ( F_29 ( V_37 -> type , V_49 ) )
goto V_59;
if ( F_29 ( F_30 ( V_37 -> V_63 ) ,
( V_64 T_7 * ) ( & V_49 [ V_65 ] ) ) )
goto V_59;
V_55 = V_60 + V_61 ;
if ( V_37 -> V_40 ) {
if ( F_31 ( & V_49 [ V_55 ] , V_53 , V_52 ) )
goto V_59;
V_55 += V_52 ;
if ( F_31 ( & V_49 [ V_55 ] , V_37 -> V_40 , V_37 -> V_46 ) )
goto V_59;
V_55 += V_37 -> V_46 ;
}
V_7 = V_55 ;
F_32 ( & V_37 -> V_47 ) ;
F_33 ( V_37 -> V_40 ) ;
V_37 -> V_40 = NULL ;
if ( V_37 -> type != V_66 )
F_34 ( V_37 ) ;
V_59:
F_7 ( & V_37 -> V_9 ) ;
V_14:
V_4 -> V_10 &= ~ V_15 ;
F_7 ( & V_4 -> V_9 ) ;
return V_7 ;
}
static int F_35 ( char * V_34 , T_3 V_35 ,
T_2 V_6 , struct V_67 * V_58 ,
struct V_28 * V_28 , T_9 V_68 )
{
struct V_69 * V_40 = (struct V_69 * ) V_34 ;
int V_7 ;
if ( ( sizeof( * V_40 ) + V_40 -> V_45 ) != V_35 ) {
F_8 ( V_12 L_23
L_24 , V_13 ,
( sizeof( * V_40 ) + V_40 -> V_45 ) , V_35 ) ;
V_7 = - V_29 ;
goto V_70;
}
V_7 = F_36 ( V_40 , V_6 , V_58 , V_28 , V_68 ) ;
if ( V_7 )
F_8 ( V_24
L_25 , V_7 ) ;
V_70:
return V_7 ;
}
static T_6
F_37 ( struct V_1 * V_1 , const char T_7 * V_49 ,
T_3 V_50 , T_8 * V_51 )
{
V_64 V_71 ;
T_9 V_68 ;
T_3 V_72 , V_73 ;
char * V_34 ;
T_2 V_6 = F_2 () ;
unsigned char V_74 [ V_54 ] ;
T_6 V_7 ;
if ( V_50 == 0 ) {
return 0 ;
} else if ( V_50 == V_75 ) {
goto V_76;
} else if ( V_50 < V_77 || V_50 > V_78 ) {
F_8 ( V_12 L_26
L_27 ,
V_13 , V_77 , V_78 , V_50 ) ;
return - V_29 ;
}
if ( F_38 ( V_74 , & V_49 [ V_79 ] ,
sizeof( V_74 ) ) ) {
F_8 ( V_12 L_28 ,
V_13 ) ;
return - V_62 ;
}
V_7 = F_39 ( V_74 , & V_72 ,
& V_73 ) ;
if ( V_7 ) {
F_8 ( V_12 L_29
L_30 , V_13 , V_7 ) ;
return V_7 ;
}
if ( ( V_60 + V_61 + V_73 + V_72 )
!= V_50 ) {
F_8 ( V_12 L_31 , V_13 ,
V_72 ) ;
return - V_29 ;
}
V_76:
V_34 = F_40 ( V_49 , V_50 ) ;
if ( F_41 ( V_34 ) ) {
F_8 ( V_24 L_32 ,
V_13 , F_42 ( V_34 ) ) ;
return F_42 ( V_34 ) ;
}
switch ( V_34 [ V_80 ] ) {
case V_81 :
if ( V_50 < ( V_77
+ sizeof( struct V_69 ) ) ) {
F_8 ( V_12 L_33
L_34
L_35 ,
V_13 ,
( V_77
+ sizeof( struct V_69 ) ) , V_50 ) ;
V_7 = - V_29 ;
goto V_82;
}
memcpy ( & V_71 , & V_34 [ V_65 ] , V_61 ) ;
V_68 = F_43 ( V_71 ) ;
V_7 = F_35 (
& V_34 [ V_79 + V_73 ] ,
V_72 , V_6 , F_5 () ,
F_14 ( V_26 ) , V_68 ) ;
if ( V_7 ) {
F_8 ( V_12 L_36
L_37 ,
V_13 , V_7 ) ;
goto V_82;
}
break;
case V_83 :
case V_84 :
break;
default:
F_44 ( V_12 , L_38
L_39 ,
V_34 [ 0 ] ) ;
V_7 = - V_29 ;
goto V_82;
}
V_7 = V_50 ;
V_82:
F_33 ( V_34 ) ;
return V_7 ;
}
int T_10 F_45 ( void )
{
int V_7 ;
F_46 ( & V_32 , 0 ) ;
V_7 = F_47 ( & V_85 ) ;
if ( V_7 )
F_8 ( V_24 L_40
L_41 ,
V_13 , V_7 ) ;
return V_7 ;
}
void F_48 ( void )
{
F_6 ( F_49 ( & V_32 ) != 0 ) ;
F_50 ( & V_85 ) ;
}
