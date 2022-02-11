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
char V_53 [ 3 ] ;
T_3 V_54 ;
T_3 V_55 ;
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
V_56:
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
goto V_56;
}
F_6 ( V_6 != V_4 -> V_6 ) ;
F_6 ( F_5 () != V_4 -> V_57 ) ;
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
goto V_58;
}
} else {
V_52 = 0 ;
V_37 -> V_46 = 0 ;
}
V_55 = ( 1 + 4 + V_52 + V_37 -> V_46 ) ;
if ( V_50 < V_55 ) {
V_7 = 0 ;
F_8 ( V_12 L_20
L_21
L_22 , V_13 , V_50 , V_55 ) ;
goto V_58;
}
V_7 = - V_59 ;
if ( F_29 ( V_37 -> type , V_49 ) )
goto V_58;
if ( F_29 ( F_30 ( V_37 -> V_60 ) , ( V_61 T_7 * ) ( V_49 + 1 ) ) )
goto V_58;
V_54 = 5 ;
if ( V_37 -> V_40 ) {
if ( F_31 ( & V_49 [ V_54 ] , V_53 , V_52 ) )
goto V_58;
V_54 += V_52 ;
if ( F_31 ( & V_49 [ V_54 ] , V_37 -> V_40 , V_37 -> V_46 ) )
goto V_58;
V_54 += V_37 -> V_46 ;
}
V_7 = V_54 ;
F_32 ( & V_37 -> V_47 ) ;
F_33 ( V_37 -> V_40 ) ;
V_37 -> V_40 = NULL ;
if ( V_37 -> type != V_62 )
F_34 ( V_37 ) ;
V_58:
F_7 ( & V_37 -> V_9 ) ;
V_14:
V_4 -> V_10 &= ~ V_15 ;
F_7 ( & V_4 -> V_9 ) ;
return V_7 ;
}
static int F_35 ( char * V_34 , T_3 V_35 ,
T_2 V_6 , struct V_63 * V_57 ,
struct V_28 * V_28 , T_9 V_64 )
{
struct V_65 * V_40 = (struct V_65 * ) V_34 ;
int V_7 ;
if ( ( sizeof( * V_40 ) + V_40 -> V_45 ) != V_35 ) {
F_8 ( V_12 L_23
L_24 , V_13 ,
( sizeof( * V_40 ) + V_40 -> V_45 ) , V_35 ) ;
V_7 = - V_29 ;
goto V_66;
}
V_7 = F_36 ( V_40 , V_6 , V_57 , V_28 , V_64 ) ;
if ( V_7 )
F_8 ( V_24
L_25 , V_7 ) ;
V_66:
return V_7 ;
}
static T_6
F_37 ( struct V_1 * V_1 , const char T_7 * V_49 ,
T_3 V_50 , T_8 * V_51 )
{
V_61 V_67 ;
T_9 V_64 ;
T_3 V_68 , V_69 , V_54 ;
T_6 V_70 = 0 ;
char * V_34 ;
T_2 V_6 = F_2 () ;
int V_7 ;
if ( V_50 == 0 )
goto V_66;
V_34 = F_38 ( V_49 , V_50 ) ;
if ( F_39 ( V_34 ) ) {
F_8 ( V_24 L_26 ,
V_13 , F_40 ( V_34 ) ) ;
goto V_66;
}
V_70 = V_50 ;
V_54 = 0 ;
switch ( V_34 [ V_54 ++ ] ) {
case V_71 :
if ( V_50 < ( 1 + 4 + 1 + sizeof( struct V_65 ) ) ) {
F_8 ( V_12 L_27
L_28
L_29 ,
V_13 ,
( 1 + 4 + 1 + sizeof( struct V_65 ) ) ,
V_50 ) ;
goto V_72;
}
memcpy ( & V_67 , & V_34 [ V_54 ] , 4 ) ;
V_64 = F_41 ( V_67 ) ;
V_54 += 4 ;
V_7 = F_42 ( & V_34 [ V_54 ] , & V_68 ,
& V_69 ) ;
if ( V_7 ) {
F_8 ( V_12 L_30
L_6 , V_13 , V_7 ) ;
goto V_72;
}
V_54 += V_69 ;
if ( ( 1 + 4 + V_69 + V_68 ) != V_50 ) {
F_8 ( V_12 L_31
L_32
L_33 ,
V_13 , V_69 , V_68 ,
( 1 + V_69 + V_68 ) , V_50 ) ;
goto V_72;
}
V_7 = F_35 ( & V_34 [ V_54 ] , V_68 ,
V_6 , F_5 () ,
F_14 ( V_26 ) , V_64 ) ;
if ( V_7 )
F_8 ( V_12 L_34
L_35 ,
V_13 , V_7 ) ;
break;
case V_73 :
case V_74 :
break;
default:
F_43 ( V_12 , L_36
L_37 ,
V_34 [ 0 ] ) ;
break;
}
V_72:
F_33 ( V_34 ) ;
V_66:
return V_70 ;
}
int T_10 F_44 ( void )
{
int V_7 ;
F_45 ( & V_32 , 0 ) ;
V_7 = F_46 ( & V_75 ) ;
if ( V_7 )
F_8 ( V_24 L_38
L_39 ,
V_13 , V_7 ) ;
return V_7 ;
}
void F_47 ( void )
{
F_6 ( F_48 ( & V_32 ) != 0 ) ;
F_49 ( & V_75 ) ;
}
