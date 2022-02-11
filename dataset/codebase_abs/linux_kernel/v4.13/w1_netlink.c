static T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return 0 ;
return ( V_4 * ) V_2 -> V_3 - ( V_4 * ) V_2 -> V_5 + V_2 -> V_3 -> V_6 ;
}
static void F_2 ( struct V_1 * V_2 )
{
if ( F_3 ( 1 , & V_2 -> V_7 ) == 0 ) {
T_1 V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_5 , V_6 ,
V_2 -> V_8 , 0 , V_9 ) ;
}
F_5 ( V_2 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_6 = F_1 ( V_2 ) ;
if ( V_6 + V_10 >= V_2 -> V_11 ) {
F_4 ( V_2 -> V_5 , V_6 , V_2 -> V_8 , 0 , V_9 ) ;
V_2 -> V_5 -> V_6 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = NULL ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_14 . V_15 & V_16 ) && V_2 -> V_3 )
F_6 ( V_2 , V_2 -> V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_17 )
{
if ( V_2 -> V_3 && V_2 -> V_3 -> V_17 == V_17 ) {
V_2 -> V_12 = (struct V_18 * ) ( V_2 -> V_3 -> V_19 + V_2 -> V_3 -> V_6 ) ;
} else {
if ( V_2 -> V_3 )
V_2 -> V_3 = (struct V_20 * ) ( V_2 -> V_3 -> V_19 +
V_2 -> V_3 -> V_6 ) ;
else
V_2 -> V_3 = V_2 -> V_5 ;
memcpy ( V_2 -> V_3 , & V_2 -> V_14 , sizeof( * V_2 -> V_3 ) ) ;
V_2 -> V_3 -> V_6 = 0 ;
V_2 -> V_3 -> V_17 = V_17 ;
V_2 -> V_12 = (struct V_18 * ) V_2 -> V_3 -> V_19 ;
}
}
static void F_9 ( struct V_1 * V_2 ,
struct V_21 * V_13 )
{
T_2 V_10 ;
F_6 ( V_2 , sizeof( struct V_20 ) +
sizeof( struct V_18 ) + sizeof( * V_13 ) + V_13 -> V_6 ) ;
F_8 ( V_2 , V_2 -> V_14 . V_22 + 1 ) ;
memcpy ( V_2 -> V_12 , V_2 -> V_23 , sizeof( * V_2 -> V_12 ) ) ;
V_2 -> V_3 -> V_6 += sizeof( * V_2 -> V_12 ) ;
V_2 -> V_12 -> V_6 = 0 ;
V_2 -> V_13 = (struct V_21 * ) ( V_2 -> V_12 -> V_19 ) ;
V_10 = sizeof( * V_13 ) + V_13 -> V_6 ;
if ( V_2 -> V_13 != V_13 )
memcpy ( V_2 -> V_13 , V_13 , V_10 ) ;
V_2 -> V_3 -> V_6 += V_10 ;
V_2 -> V_12 -> V_6 += V_10 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_18 * V_24 , struct V_21 * V_25 ,
int error )
{
T_1 V_10 = sizeof( struct V_20 ) + sizeof( * V_24 ) + sizeof( * V_25 ) ;
F_6 ( V_2 , V_10 ) ;
F_8 ( V_2 , V_2 -> V_14 . V_17 ) ;
memcpy ( V_2 -> V_12 , V_24 , sizeof( * V_24 ) ) ;
V_2 -> V_3 -> V_6 += sizeof( * V_24 ) ;
V_2 -> V_12 -> V_6 = 0 ;
V_2 -> V_12 -> V_26 = ( V_4 ) - error ;
if ( V_25 ) {
struct V_21 * V_13 = (struct V_21 * ) V_2 -> V_12 -> V_19 ;
memcpy ( V_13 , V_25 , sizeof( * V_13 ) ) ;
V_2 -> V_3 -> V_6 += sizeof( * V_13 ) ;
V_2 -> V_12 -> V_6 += sizeof( * V_13 ) ;
V_13 -> V_6 = 0 ;
}
F_7 ( V_2 ) ;
}
static void F_11 ( struct V_20 * V_3 , struct V_18 * V_12 ,
int V_8 , int error )
{
struct {
struct V_20 V_3 ;
struct V_18 V_12 ;
} V_27 ;
memcpy ( & V_27 . V_3 , V_3 , sizeof( V_27 . V_3 ) ) ;
memcpy ( & V_27 . V_12 , V_12 , sizeof( V_27 . V_12 ) ) ;
V_27 . V_3 . V_6 = sizeof( V_27 . V_12 ) ;
V_27 . V_12 . V_6 = 0 ;
V_27 . V_12 . V_26 = ( V_4 ) - error ;
F_12 ( & V_27 . V_3 , V_8 , 0 , V_9 ) ;
}
void F_13 ( struct V_28 * V_29 , struct V_18 * V_12 )
{
struct {
struct V_20 V_3 ;
struct V_18 V_12 ;
} V_27 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_3 . V_30 . V_31 = V_32 ;
V_27 . V_3 . V_30 . V_33 = V_34 ;
V_27 . V_3 . V_22 = V_29 -> V_22 ++ ;
V_27 . V_3 . V_6 = sizeof( * V_12 ) ;
memcpy ( & V_27 . V_12 , V_12 , sizeof( * V_12 ) ) ;
V_27 . V_12 . V_6 = 0 ;
F_12 ( & V_27 . V_3 , 0 , 0 , V_9 ) ;
}
static void F_14 ( struct V_28 * V_29 , T_3 V_35 )
{
struct V_1 * V_2 = V_29 -> V_36 ;
struct V_21 * V_37 = V_2 -> V_13 ;
T_3 * V_19 ;
F_6 ( V_2 , sizeof( * V_19 ) ) ;
if ( ! V_2 -> V_13 ) {
V_37 -> V_6 = 0 ;
F_9 ( V_2 , V_37 ) ;
}
V_19 = ( T_3 * ) ( V_2 -> V_13 -> V_19 + V_2 -> V_13 -> V_6 ) ;
* V_19 = V_35 ;
V_2 -> V_3 -> V_6 += sizeof( * V_19 ) ;
V_2 -> V_12 -> V_6 += sizeof( * V_19 ) ;
V_2 -> V_13 -> V_6 += sizeof( * V_19 ) ;
}
static void F_15 ( struct V_28 * V_29 , T_3 V_35 )
{
F_16 ( V_29 , V_35 ) ;
F_14 ( V_29 , V_35 ) ;
}
static int F_17 ( struct V_28 * V_29 , struct V_21 * V_25 )
{
struct V_38 * V_39 ;
V_25 -> V_6 = 0 ;
F_9 ( V_29 -> V_36 , V_25 ) ;
if ( V_25 -> V_13 == V_40 ) {
T_3 V_35 ;
F_18 ( & V_29 -> V_41 ) ;
F_19 (sl, &dev->slist, w1_slave_entry) {
memcpy ( & V_35 , & V_39 -> V_42 , sizeof( V_35 ) ) ;
F_14 ( V_29 , V_35 ) ;
}
F_20 ( & V_29 -> V_41 ) ;
} else {
F_21 ( V_29 , V_25 -> V_13 == V_43 ?
V_44 : V_45 , F_15 ) ;
}
return 0 ;
}
static int F_22 ( struct V_28 * V_29 ,
struct V_21 * V_13 )
{
int V_46 = 0 ;
switch ( V_13 -> V_13 ) {
case V_47 :
F_23 ( V_29 , V_13 -> V_19 , V_13 -> V_6 ) ;
F_9 ( V_29 -> V_36 , V_13 ) ;
break;
case V_48 :
F_24 ( V_29 , V_13 -> V_19 , V_13 -> V_6 ) ;
F_9 ( V_29 -> V_36 , V_13 ) ;
break;
case V_49 :
F_25 ( V_29 , V_13 -> V_19 , V_13 -> V_6 ) ;
break;
default:
V_46 = - V_50 ;
break;
}
return V_46 ;
}
static int F_26 ( struct V_28 * V_29 ,
struct V_21 * V_13 )
{
struct V_38 * V_39 ;
int V_46 = 0 ;
struct V_51 * V_30 ;
if ( V_13 -> V_6 != sizeof( * V_30 ) )
return - V_50 ;
V_30 = (struct V_51 * ) V_13 -> V_19 ;
V_39 = F_27 ( V_29 , V_30 ) ;
switch ( V_13 -> V_13 ) {
case V_52 :
if ( V_39 )
V_46 = - V_50 ;
else
V_46 = F_28 ( V_29 , V_30 ) ;
break;
case V_53 :
if ( V_39 )
F_29 ( V_39 ) ;
else
V_46 = - V_50 ;
break;
default:
V_46 = - V_50 ;
break;
}
return V_46 ;
}
static int F_30 ( struct V_28 * V_29 ,
struct V_21 * V_25 )
{
int V_46 = - V_50 ;
switch ( V_25 -> V_13 ) {
case V_54 :
case V_43 :
case V_40 :
F_20 ( & V_29 -> V_55 ) ;
V_46 = F_17 ( V_29 , V_25 ) ;
F_18 ( & V_29 -> V_55 ) ;
break;
case V_48 :
case V_49 :
case V_47 :
V_46 = F_22 ( V_29 , V_25 ) ;
break;
case V_56 :
V_46 = F_31 ( V_29 ) ;
break;
case V_52 :
case V_53 :
F_20 ( & V_29 -> V_55 ) ;
F_18 ( & V_29 -> V_57 ) ;
V_46 = F_26 ( V_29 , V_25 ) ;
F_20 ( & V_29 -> V_57 ) ;
F_18 ( & V_29 -> V_55 ) ;
break;
default:
V_46 = - V_50 ;
break;
}
return V_46 ;
}
static int F_32 ( struct V_38 * V_39 ,
struct V_21 * V_13 )
{
F_33 ( & V_39 -> V_58 -> V_29 , L_1 ,
V_59 , V_39 -> V_42 . V_60 , ( unsigned long long ) V_39 -> V_42 . V_30 ,
V_39 -> V_42 . V_61 , V_13 -> V_13 , V_13 -> V_6 ) ;
return F_22 ( V_39 -> V_58 , V_13 ) ;
}
static int F_34 ( struct V_20 * V_62 , T_2 V_8 )
{
struct V_28 * V_29 ;
struct V_20 * V_3 ;
struct V_18 * V_12 ;
T_2 * V_30 ;
V_3 = F_35 ( V_63 , V_9 ) ;
if ( ! V_3 )
return - V_64 ;
V_3 -> V_30 . V_31 = V_32 ;
V_3 -> V_30 . V_33 = V_34 ;
V_3 -> V_22 = V_62 -> V_22 ;
V_3 -> V_17 = V_62 -> V_22 + 1 ;
V_3 -> V_6 = sizeof( struct V_18 ) ;
V_12 = (struct V_18 * ) V_3 -> V_19 ;
V_12 -> type = V_65 ;
V_12 -> V_26 = 0 ;
V_12 -> V_6 = 0 ;
V_30 = ( T_2 * ) V_12 -> V_19 ;
F_18 ( & V_66 ) ;
F_19 (dev, &w1_masters, w1_master_entry) {
if ( V_3 -> V_6 + sizeof( * V_30 ) > V_63 - sizeof( struct V_20 ) ) {
F_12 ( V_3 , V_8 , 0 , V_9 ) ;
V_3 -> V_6 = sizeof( struct V_18 ) ;
V_12 -> V_6 = 0 ;
V_30 = ( T_2 * ) V_12 -> V_19 ;
}
* V_30 = V_29 -> V_30 ;
V_12 -> V_6 += sizeof( * V_30 ) ;
V_3 -> V_6 += sizeof( * V_30 ) ;
V_30 ++ ;
}
F_12 ( V_3 , V_8 , 0 , V_9 ) ;
F_20 ( & V_66 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static void F_36 ( struct V_28 * V_29 , struct V_67 * V_68 )
{
struct V_69 * V_70 = F_37 ( V_68 , struct V_69 ,
V_71 ) ;
T_1 V_72 = V_70 -> V_12 -> V_6 ;
T_1 V_6 ;
int V_46 = 0 ;
struct V_38 * V_39 = V_70 -> V_39 ;
struct V_21 * V_13 = (struct V_21 * ) V_70 -> V_12 -> V_19 ;
F_18 ( & V_29 -> V_55 ) ;
V_29 -> V_36 = V_70 -> V_2 ;
if ( V_39 && F_38 ( V_39 ) )
V_46 = - V_73 ;
V_70 -> V_2 -> V_23 = V_70 -> V_12 ;
while ( V_72 && ! V_46 ) {
if ( V_13 -> V_6 + sizeof( struct V_21 ) > V_72 ) {
V_46 = - V_74 ;
break;
}
if ( V_39 )
V_46 = F_32 ( V_39 , V_13 ) ;
else
V_46 = F_30 ( V_29 , V_13 ) ;
F_7 ( V_70 -> V_2 ) ;
F_10 ( V_70 -> V_2 , V_70 -> V_12 , V_13 , V_46 ) ;
V_46 = 0 ;
V_6 = sizeof( * V_13 ) + V_13 -> V_6 ;
V_13 = (struct V_21 * ) ( ( V_4 * ) V_13 + V_6 ) ;
V_72 -= V_6 ;
}
if ( ! V_13 || V_46 )
F_10 ( V_70 -> V_2 , V_70 -> V_12 , V_13 , V_46 ) ;
if ( V_39 )
F_39 ( V_39 ) ;
else
F_40 ( & V_29 -> V_7 ) ;
V_29 -> V_36 = NULL ;
F_20 ( & V_29 -> V_55 ) ;
F_18 ( & V_29 -> V_41 ) ;
F_41 ( & V_68 -> V_75 ) ;
F_20 ( & V_29 -> V_41 ) ;
F_2 ( V_70 -> V_2 ) ;
}
static void F_42 ( struct V_18 * V_12 , int * V_76 ,
T_1 * V_77 )
{
struct V_21 * V_13 = (struct V_21 * ) V_12 -> V_19 ;
T_1 V_72 = V_12 -> V_6 ;
T_1 V_6 ;
int V_78 = 0 ;
while ( V_72 ) {
if ( V_13 -> V_6 + sizeof( struct V_21 ) > V_72 )
break;
switch ( V_13 -> V_13 ) {
case V_54 :
case V_43 :
case V_40 :
++ V_78 ;
}
++ * V_76 ;
V_6 = sizeof( * V_13 ) + V_13 -> V_6 ;
V_13 = (struct V_21 * ) ( ( V_4 * ) V_13 + V_6 ) ;
V_72 -= V_6 ;
}
if ( V_78 ) {
struct V_28 * V_29 = F_43 ( V_12 -> V_30 . V_79 . V_30 ) ;
if ( V_29 ) {
* V_77 += sizeof( struct V_51 ) * V_78 *
( V_29 -> V_80 + V_29 -> V_81 ) ;
F_40 ( & V_29 -> V_7 ) ;
}
}
}
static void F_44 ( struct V_20 * V_3 , struct V_82 * V_83 )
{
struct V_18 * V_12 = (struct V_18 * ) ( V_3 + 1 ) ;
struct V_38 * V_39 ;
struct V_28 * V_29 ;
T_1 V_84 ;
T_1 V_77 = 0 ;
int V_46 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_69 * V_70 = NULL ;
int V_85 = 0 ;
int V_76 = 0 ;
if ( V_3 -> V_15 & ~ ( V_16 ) ) {
F_11 ( V_3 , V_12 , V_83 -> V_8 , - V_50 ) ;
return;
}
V_84 = V_3 -> V_6 ;
while ( V_84 && ! V_46 ) {
if ( V_12 -> V_6 + sizeof( struct V_18 ) > V_84 ) {
V_46 = - V_74 ;
break;
}
if ( V_12 -> type == V_86 || V_12 -> type == V_87 ) {
++ V_85 ;
F_42 ( V_12 , & V_76 , & V_77 ) ;
}
V_84 -= sizeof( struct V_18 ) + V_12 -> V_6 ;
V_12 = (struct V_18 * ) ( ( ( V_4 * ) V_12 ) +
sizeof( struct V_18 ) + V_12 -> V_6 ) ;
}
V_12 = (struct V_18 * ) ( V_3 + 1 ) ;
if ( V_85 ) {
int V_88 ;
int V_89 = sizeof( * V_3 ) + V_3 -> V_6 + V_77 ;
if ( V_3 -> V_15 & V_16 ) {
V_89 += 2 * V_76 * ( sizeof( struct V_20 ) +
sizeof( struct V_18 ) +
sizeof( struct V_21 ) ) ;
}
V_89 = F_45 ( V_90 , V_89 ) ;
V_88 =
sizeof( struct V_1 ) + sizeof( * V_3 ) + V_3 -> V_6 +
V_85 * sizeof( struct V_69 ) +
sizeof( struct V_20 ) + V_89 ;
V_2 = F_46 ( V_88 , V_9 ) ;
if ( ! V_2 ) {
F_11 ( V_3 , V_12 , V_83 -> V_8 , - V_64 ) ;
return;
}
F_47 ( & V_2 -> V_7 , 1 ) ;
V_2 -> V_8 = V_83 -> V_8 ;
memcpy ( & V_2 -> V_14 , V_3 , sizeof( * V_3 ) + V_3 -> V_6 ) ;
V_70 = (struct V_69 * ) ( V_2 -> V_14 . V_19 + V_3 -> V_6 ) ;
V_2 -> V_11 = V_89 ;
V_2 -> V_5 = (struct V_20 * ) ( V_70 + V_85 ) ;
memset ( V_2 -> V_5 , 0 , sizeof( * V_2 -> V_5 ) ) ;
}
V_84 = V_3 -> V_6 ;
while ( V_84 && ! V_46 ) {
V_29 = NULL ;
V_39 = NULL ;
if ( V_12 -> V_6 + sizeof( struct V_18 ) > V_84 ) {
V_46 = - V_74 ;
break;
}
if ( V_12 -> type == V_65 ) {
V_46 = F_34 ( V_3 , V_83 -> V_8 ) ;
goto V_91;
}
if ( ! V_12 -> V_6 ) {
V_46 = - V_92 ;
goto V_91;
}
if ( V_12 -> type == V_86 ) {
V_29 = F_43 ( V_12 -> V_30 . V_79 . V_30 ) ;
} else if ( V_12 -> type == V_87 ) {
V_39 = F_48 ( (struct V_51 * ) V_12 -> V_30 . V_30 ) ;
if ( V_39 )
V_29 = V_39 -> V_58 ;
} else {
F_49 ( L_2 ,
V_59 , V_3 -> V_30 . V_31 , V_3 -> V_30 . V_33 ,
V_12 -> type , V_12 -> V_6 ) ;
V_46 = - V_92 ;
goto V_91;
}
if ( ! V_29 ) {
V_46 = - V_73 ;
goto V_91;
}
V_46 = 0 ;
F_50 ( & V_2 -> V_7 ) ;
V_70 -> V_71 . V_93 = F_36 ;
V_70 -> V_2 = V_2 ;
V_70 -> V_12 = (struct V_18 * ) ( ( V_4 * ) & V_2 -> V_14 +
( V_94 ) ( ( V_4 * ) V_12 - ( V_4 * ) V_3 ) ) ;
V_70 -> V_39 = V_39 ;
V_70 -> V_29 = V_29 ;
F_18 ( & V_29 -> V_41 ) ;
F_51 ( & V_70 -> V_71 . V_75 , & V_29 -> V_95 ) ;
F_52 ( V_29 -> V_96 ) ;
F_20 ( & V_29 -> V_41 ) ;
++ V_70 ;
V_91:
if ( V_46 )
F_11 ( V_3 , V_12 , V_83 -> V_8 , V_46 ) ;
V_84 -= sizeof( struct V_18 ) + V_12 -> V_6 ;
V_12 = (struct V_18 * ) ( ( ( V_4 * ) V_12 ) +
sizeof( struct V_18 ) + V_12 -> V_6 ) ;
if ( V_46 == - V_73 )
V_46 = 0 ;
}
if ( V_2 )
F_2 ( V_2 ) ;
}
int F_53 ( void )
{
struct V_97 V_98 = { . V_31 = V_32 , . V_33 = V_34 } ;
return F_54 ( & V_98 , L_3 , & F_44 ) ;
}
void F_55 ( void )
{
struct V_97 V_98 = { . V_31 = V_32 , . V_33 = V_34 } ;
F_56 ( & V_98 ) ;
}
void F_13 ( struct V_28 * V_29 , struct V_18 * V_3 )
{
}
int F_53 ( void )
{
return 0 ;
}
void F_55 ( void )
{
}
