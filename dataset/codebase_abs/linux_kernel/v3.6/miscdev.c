static unsigned int
F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned int V_6 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 & V_9 ) {
F_3 ( V_10 L_1
L_2 , V_11 ) ;
goto V_12;
}
if ( V_4 -> V_8 & V_13 )
goto V_12;
if ( V_4 -> V_8 & V_14 )
goto V_12;
V_4 -> V_8 |= V_14 ;
F_4 ( & V_4 -> V_7 ) ;
F_5 ( V_1 , & V_4 -> V_15 , V_2 ) ;
F_2 ( & V_4 -> V_7 ) ;
if ( ! F_6 ( & V_4 -> V_16 ) )
V_6 |= V_17 | V_18 ;
V_12:
V_4 -> V_8 &= ~ V_14 ;
F_4 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static int
F_7 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
struct V_3 * V_4 = NULL ;
int V_20 ;
F_2 ( & V_21 ) ;
V_20 = F_8 ( V_22 ) ;
if ( V_20 == 0 ) {
V_20 = - V_23 ;
F_3 ( V_24 L_3
L_4 , V_11 , V_20 ) ;
goto V_25;
}
V_20 = F_9 ( & V_4 ) ;
if ( ! V_20 ) {
V_20 = - V_26 ;
goto V_25;
}
V_20 = F_10 ( & V_4 , V_1 ) ;
if ( V_20 ) {
F_3 ( V_24 L_5
L_6 , V_11 , V_20 ) ;
goto V_27;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 & V_28 ) {
V_20 = - V_29 ;
goto V_12;
}
V_4 -> V_8 |= V_28 ;
V_1 -> V_5 = V_4 ;
F_11 ( & V_30 ) ;
V_12:
F_4 ( & V_4 -> V_7 ) ;
V_27:
if ( V_20 )
F_12 ( V_22 ) ;
V_25:
F_4 ( & V_21 ) ;
return V_20 ;
}
static int
F_13 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_20 ;
F_2 ( & V_4 -> V_7 ) ;
F_14 ( ! ( V_4 -> V_8 & V_28 ) ) ;
V_4 -> V_8 &= ~ V_28 ;
F_15 ( & V_30 ) ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_21 ) ;
V_20 = F_16 ( V_4 ) ;
F_4 ( & V_21 ) ;
if ( V_20 ) {
F_3 ( V_31 L_7
L_8
L_9 , V_11 , V_20 ) ;
F_17 () ;
}
F_12 ( V_22 ) ;
return V_20 ;
}
int F_18 ( char * V_32 , T_2 V_33 ,
struct V_34 * V_35 , T_3 V_36 ,
T_4 V_37 , struct V_3 * V_4 )
{
struct V_38 * V_39 ;
V_39 = F_19 ( ( sizeof( * V_39 ) + V_33 ) , V_40 ) ;
if ( ! V_39 ) {
F_3 ( V_24 L_10
L_11 , V_11 ,
( sizeof( * V_39 ) + V_33 ) ) ;
return - V_41 ;
}
F_2 ( & V_35 -> V_7 ) ;
V_35 -> V_39 = V_39 ;
V_35 -> V_39 -> V_42 = V_35 -> V_42 ;
V_35 -> V_39 -> V_43 = V_33 ;
V_35 -> type = V_36 ;
memcpy ( V_35 -> V_39 -> V_32 , V_32 , V_33 ) ;
V_35 -> V_44 = ( sizeof( * V_35 -> V_39 ) + V_33 ) ;
F_20 ( & V_35 -> V_45 , & V_4 -> V_16 ) ;
F_4 ( & V_35 -> V_7 ) ;
F_2 ( & V_4 -> V_7 ) ;
V_4 -> V_46 ++ ;
F_21 ( & V_4 -> V_15 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
static T_5
F_22 ( struct V_1 * V_1 , char T_6 * V_47 , T_2 V_48 ,
T_7 * V_49 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_34 * V_35 ;
T_2 V_50 ;
char V_51 [ V_52 ] ;
T_2 V_53 ;
T_2 V_54 ;
int V_20 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 & V_9 ) {
V_20 = 0 ;
F_3 ( V_10 L_12
L_2 , V_11 ) ;
goto V_12;
}
if ( V_4 -> V_8 & V_13 ) {
V_20 = 0 ;
goto V_12;
}
V_4 -> V_8 |= V_13 ;
V_55:
if ( F_6 ( & V_4 -> V_16 ) ) {
F_4 ( & V_4 -> V_7 ) ;
V_20 = F_23 (
V_4 -> V_15 , ! F_6 ( & V_4 -> V_16 ) ) ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_20 < 0 ) {
V_20 = 0 ;
goto V_12;
}
}
if ( V_4 -> V_8 & V_9 ) {
V_20 = 0 ;
goto V_12;
}
if ( F_6 ( & V_4 -> V_16 ) ) {
goto V_55;
}
V_35 = F_24 ( & V_4 -> V_16 ,
struct V_34 , V_45 ) ;
F_14 ( ! V_35 ) ;
F_2 ( & V_35 -> V_7 ) ;
if ( V_35 -> V_39 ) {
V_20 = F_25 ( V_51 ,
V_35 -> V_44 ,
& V_50 ) ;
if ( V_20 ) {
V_20 = 0 ;
F_3 ( V_10 L_13
L_6 , V_11 , V_20 ) ;
goto V_56;
}
} else {
V_50 = 0 ;
V_35 -> V_44 = 0 ;
}
V_54 = ( V_57 + V_58 + V_50
+ V_35 -> V_44 ) ;
if ( V_48 < V_54 ) {
V_20 = 0 ;
F_3 ( V_10 L_14
L_15
L_16 , V_11 , V_48 , V_54 ) ;
goto V_56;
}
V_20 = - V_59 ;
if ( F_26 ( V_35 -> type , V_47 ) )
goto V_56;
if ( F_26 ( F_27 ( V_35 -> V_60 ) ,
( V_61 T_6 * ) ( & V_47 [ V_62 ] ) ) )
goto V_56;
V_53 = V_57 + V_58 ;
if ( V_35 -> V_39 ) {
if ( F_28 ( & V_47 [ V_53 ] , V_51 , V_50 ) )
goto V_56;
V_53 += V_50 ;
if ( F_28 ( & V_47 [ V_53 ] , V_35 -> V_39 , V_35 -> V_44 ) )
goto V_56;
V_53 += V_35 -> V_44 ;
}
V_20 = V_53 ;
F_29 ( & V_35 -> V_45 ) ;
F_30 ( V_35 -> V_39 ) ;
V_35 -> V_39 = NULL ;
if ( V_35 -> type != V_63 )
F_31 ( V_35 ) ;
V_56:
F_4 ( & V_35 -> V_7 ) ;
V_12:
V_4 -> V_8 &= ~ V_13 ;
F_4 ( & V_4 -> V_7 ) ;
return V_20 ;
}
static int F_32 ( struct V_3 * V_4 , char * V_32 ,
T_2 V_33 , T_8 V_64 )
{
struct V_38 * V_39 = (struct V_38 * ) V_32 ;
int V_20 ;
if ( ( sizeof( * V_39 ) + V_39 -> V_43 ) != V_33 ) {
F_3 ( V_10 L_17
L_18 , V_11 ,
( sizeof( * V_39 ) + V_39 -> V_43 ) , V_33 ) ;
V_20 = - V_26 ;
goto V_65;
}
V_20 = F_33 ( V_4 , V_39 , V_64 ) ;
if ( V_20 )
F_3 ( V_24
L_19 , V_20 ) ;
V_65:
return V_20 ;
}
static T_5
F_34 ( struct V_1 * V_1 , const char T_6 * V_47 ,
T_2 V_48 , T_7 * V_49 )
{
V_61 V_66 ;
T_8 V_64 ;
T_2 V_67 , V_68 ;
char * V_32 ;
unsigned char V_69 [ V_52 ] ;
T_5 V_20 ;
if ( V_48 == 0 ) {
return 0 ;
} else if ( V_48 == V_70 ) {
goto V_71;
} else if ( V_48 < V_72 || V_48 > V_73 ) {
F_3 ( V_10 L_20
L_21 ,
V_11 , V_72 , V_73 , V_48 ) ;
return - V_26 ;
}
if ( F_35 ( V_69 , & V_47 [ V_74 ] ,
sizeof( V_69 ) ) ) {
F_3 ( V_10 L_22 ,
V_11 ) ;
return - V_59 ;
}
V_20 = F_36 ( V_69 , & V_67 ,
& V_68 ) ;
if ( V_20 ) {
F_3 ( V_10 L_23
L_24 , V_11 , V_20 ) ;
return V_20 ;
}
if ( ( V_57 + V_58 + V_68 + V_67 )
!= V_48 ) {
F_3 ( V_10 L_25 , V_11 ,
V_67 ) ;
return - V_26 ;
}
V_71:
V_32 = F_37 ( V_47 , V_48 ) ;
if ( F_38 ( V_32 ) ) {
F_3 ( V_24 L_26 ,
V_11 , F_39 ( V_32 ) ) ;
return F_39 ( V_32 ) ;
}
switch ( V_32 [ V_75 ] ) {
case V_76 :
if ( V_48 < ( V_72
+ sizeof( struct V_38 ) ) ) {
F_3 ( V_10 L_27
L_28
L_29 ,
V_11 ,
( V_72
+ sizeof( struct V_38 ) ) , V_48 ) ;
V_20 = - V_26 ;
goto V_77;
}
memcpy ( & V_66 , & V_32 [ V_62 ] , V_58 ) ;
V_64 = F_40 ( V_66 ) ;
V_20 = F_32 ( V_1 -> V_5 ,
& V_32 [ V_74 + V_68 ] ,
V_67 , V_64 ) ;
if ( V_20 ) {
F_3 ( V_10 L_30
L_31 ,
V_11 , V_20 ) ;
goto V_77;
}
break;
case V_78 :
case V_79 :
break;
default:
F_41 ( V_10 , L_32
L_33 ,
V_32 [ 0 ] ) ;
V_20 = - V_26 ;
goto V_77;
}
V_20 = V_48 ;
V_77:
F_30 ( V_32 ) ;
return V_20 ;
}
int T_9 F_42 ( void )
{
int V_20 ;
F_43 ( & V_30 , 0 ) ;
V_20 = F_44 ( & V_80 ) ;
if ( V_20 )
F_3 ( V_24 L_34
L_35 ,
V_11 , V_20 ) ;
return V_20 ;
}
void F_45 ( void )
{
F_14 ( F_46 ( & V_30 ) != 0 ) ;
F_47 ( & V_80 ) ;
}
