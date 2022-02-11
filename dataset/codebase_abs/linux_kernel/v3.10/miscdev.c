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
V_20 = F_8 ( & V_4 ) ;
if ( ! V_20 ) {
V_20 = - V_22 ;
goto V_23;
}
V_20 = F_9 ( & V_4 , V_1 ) ;
if ( V_20 ) {
F_3 ( V_24 L_3
L_4 , V_11 , V_20 ) ;
goto V_23;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 & V_25 ) {
V_20 = - V_26 ;
goto V_12;
}
V_4 -> V_8 |= V_25 ;
V_1 -> V_5 = V_4 ;
F_10 ( & V_27 ) ;
V_12:
F_4 ( & V_4 -> V_7 ) ;
V_23:
F_4 ( & V_21 ) ;
return V_20 ;
}
static int
F_11 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_20 ;
F_2 ( & V_4 -> V_7 ) ;
F_12 ( ! ( V_4 -> V_8 & V_25 ) ) ;
V_4 -> V_8 &= ~ V_25 ;
F_13 ( & V_27 ) ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_21 ) ;
V_20 = F_14 ( V_4 ) ;
F_4 ( & V_21 ) ;
if ( V_20 ) {
F_3 ( V_28 L_5
L_6
L_7 , V_11 , V_20 ) ;
F_15 () ;
}
return V_20 ;
}
int F_16 ( char * V_29 , T_2 V_30 ,
struct V_31 * V_32 , T_3 V_33 ,
T_4 V_34 , struct V_3 * V_4 )
{
struct V_35 * V_36 ;
V_36 = F_17 ( ( sizeof( * V_36 ) + V_30 ) , V_37 ) ;
if ( ! V_36 ) {
F_3 ( V_24 L_8
L_9 , V_11 ,
( sizeof( * V_36 ) + V_30 ) ) ;
return - V_38 ;
}
F_2 ( & V_32 -> V_7 ) ;
V_32 -> V_36 = V_36 ;
V_32 -> V_36 -> V_39 = V_32 -> V_39 ;
V_32 -> V_36 -> V_40 = V_30 ;
V_32 -> type = V_33 ;
memcpy ( V_32 -> V_36 -> V_29 , V_29 , V_30 ) ;
V_32 -> V_41 = ( sizeof( * V_32 -> V_36 ) + V_30 ) ;
F_18 ( & V_32 -> V_42 , & V_4 -> V_16 ) ;
F_4 ( & V_32 -> V_7 ) ;
F_2 ( & V_4 -> V_7 ) ;
V_4 -> V_43 ++ ;
F_19 ( & V_4 -> V_15 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
static T_5
F_20 ( struct V_1 * V_1 , char T_6 * V_44 , T_2 V_45 ,
T_7 * V_46 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_31 * V_32 ;
T_2 V_47 ;
char V_48 [ V_49 ] ;
T_2 V_50 ;
T_2 V_51 ;
int V_20 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 & V_9 ) {
V_20 = 0 ;
F_3 ( V_10 L_10
L_2 , V_11 ) ;
goto V_12;
}
if ( V_4 -> V_8 & V_13 ) {
V_20 = 0 ;
goto V_12;
}
V_4 -> V_8 |= V_13 ;
V_52:
if ( F_6 ( & V_4 -> V_16 ) ) {
F_4 ( & V_4 -> V_7 ) ;
V_20 = F_21 (
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
goto V_52;
}
V_32 = F_22 ( & V_4 -> V_16 ,
struct V_31 , V_42 ) ;
F_12 ( ! V_32 ) ;
F_2 ( & V_32 -> V_7 ) ;
if ( V_32 -> V_36 ) {
V_20 = F_23 ( V_48 ,
V_32 -> V_41 ,
& V_47 ) ;
if ( V_20 ) {
V_20 = 0 ;
F_3 ( V_10 L_11
L_4 , V_11 , V_20 ) ;
goto V_53;
}
} else {
V_47 = 0 ;
V_32 -> V_41 = 0 ;
}
V_51 = ( V_54 + V_55 + V_47
+ V_32 -> V_41 ) ;
if ( V_45 < V_51 ) {
V_20 = 0 ;
F_3 ( V_10 L_12
L_13
L_14 , V_11 , V_45 , V_51 ) ;
goto V_53;
}
V_20 = - V_56 ;
if ( F_24 ( V_32 -> type , V_44 ) )
goto V_53;
if ( F_24 ( F_25 ( V_32 -> V_57 ) ,
( V_58 T_6 * ) ( & V_44 [ V_59 ] ) ) )
goto V_53;
V_50 = V_54 + V_55 ;
if ( V_32 -> V_36 ) {
if ( F_26 ( & V_44 [ V_50 ] , V_48 , V_47 ) )
goto V_53;
V_50 += V_47 ;
if ( F_26 ( & V_44 [ V_50 ] , V_32 -> V_36 , V_32 -> V_41 ) )
goto V_53;
V_50 += V_32 -> V_41 ;
}
V_20 = V_50 ;
F_27 ( & V_32 -> V_42 ) ;
F_28 ( V_32 -> V_36 ) ;
V_32 -> V_36 = NULL ;
if ( V_32 -> type != V_60 )
F_29 ( V_32 ) ;
V_53:
F_4 ( & V_32 -> V_7 ) ;
V_12:
V_4 -> V_8 &= ~ V_13 ;
F_4 ( & V_4 -> V_7 ) ;
return V_20 ;
}
static int F_30 ( struct V_3 * V_4 , char * V_29 ,
T_2 V_30 , T_8 V_61 )
{
struct V_35 * V_36 = (struct V_35 * ) V_29 ;
int V_20 ;
if ( ( sizeof( * V_36 ) + V_36 -> V_40 ) != V_30 ) {
F_3 ( V_10 L_15
L_16 , V_11 ,
( sizeof( * V_36 ) + V_36 -> V_40 ) , V_30 ) ;
V_20 = - V_22 ;
goto V_62;
}
V_20 = F_31 ( V_4 , V_36 , V_61 ) ;
if ( V_20 )
F_3 ( V_24
L_17 , V_20 ) ;
V_62:
return V_20 ;
}
static T_5
F_32 ( struct V_1 * V_1 , const char T_6 * V_44 ,
T_2 V_45 , T_7 * V_46 )
{
V_58 V_63 ;
T_8 V_61 ;
T_2 V_64 , V_65 ;
char * V_29 ;
unsigned char V_66 [ V_49 ] ;
T_5 V_20 ;
if ( V_45 == 0 ) {
return 0 ;
} else if ( V_45 == V_67 ) {
goto V_68;
} else if ( V_45 < V_69 || V_45 > V_70 ) {
F_3 ( V_10 L_18
L_19 ,
V_11 , V_69 , V_70 , V_45 ) ;
return - V_22 ;
}
if ( F_33 ( V_66 , & V_44 [ V_71 ] ,
sizeof( V_66 ) ) ) {
F_3 ( V_10 L_20 ,
V_11 ) ;
return - V_56 ;
}
V_20 = F_34 ( V_66 , & V_64 ,
& V_65 ) ;
if ( V_20 ) {
F_3 ( V_10 L_21
L_22 , V_11 , V_20 ) ;
return V_20 ;
}
if ( ( V_54 + V_55 + V_65 + V_64 )
!= V_45 ) {
F_3 ( V_10 L_23 , V_11 ,
V_64 ) ;
return - V_22 ;
}
V_68:
V_29 = F_35 ( V_44 , V_45 ) ;
if ( F_36 ( V_29 ) ) {
F_3 ( V_24 L_24 ,
V_11 , F_37 ( V_29 ) ) ;
return F_37 ( V_29 ) ;
}
switch ( V_29 [ V_72 ] ) {
case V_73 :
if ( V_45 < ( V_69
+ sizeof( struct V_35 ) ) ) {
F_3 ( V_10 L_25
L_26
L_27 ,
V_11 ,
( V_69
+ sizeof( struct V_35 ) ) , V_45 ) ;
V_20 = - V_22 ;
goto V_74;
}
memcpy ( & V_63 , & V_29 [ V_59 ] , V_55 ) ;
V_61 = F_38 ( V_63 ) ;
V_20 = F_30 ( V_1 -> V_5 ,
& V_29 [ V_71 + V_65 ] ,
V_64 , V_61 ) ;
if ( V_20 ) {
F_3 ( V_10 L_28
L_29 ,
V_11 , V_20 ) ;
goto V_74;
}
break;
case V_75 :
case V_76 :
break;
default:
F_39 ( V_10 , L_30
L_31 ,
V_29 [ 0 ] ) ;
V_20 = - V_22 ;
goto V_74;
}
V_20 = V_45 ;
V_74:
F_28 ( V_29 ) ;
return V_20 ;
}
int T_9 F_40 ( void )
{
int V_20 ;
F_41 ( & V_27 , 0 ) ;
V_20 = F_42 ( & V_77 ) ;
if ( V_20 )
F_3 ( V_24 L_32
L_33 ,
V_11 , V_20 ) ;
return V_20 ;
}
void F_43 ( void )
{
F_12 ( F_44 ( & V_27 ) != 0 ) ;
F_45 ( & V_77 ) ;
}
