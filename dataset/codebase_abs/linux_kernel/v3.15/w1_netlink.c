void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_5 [ sizeof( struct V_6 ) + sizeof( struct V_3 ) ] ;
struct V_6 * V_7 = (struct V_6 * ) V_5 ;
struct V_3 * V_8 = (struct V_3 * ) ( V_7 + 1 ) ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_7 -> V_9 . V_10 = V_11 ;
V_7 -> V_9 . V_12 = V_13 ;
V_7 -> V_14 = V_2 -> V_14 ++ ;
V_7 -> V_15 = sizeof( struct V_3 ) ;
memcpy ( V_8 , V_4 , sizeof( struct V_3 ) ) ;
F_2 ( V_7 , V_2 -> V_16 , 0 , V_17 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_6 * V_4 = V_2 -> V_19 ;
struct V_3 * V_20 = (struct V_3 * ) ( V_4 + 1 ) ;
struct V_21 * V_22 = (struct V_21 * ) ( V_20 + 1 ) ;
int V_23 ;
T_1 * V_24 ;
V_23 = V_2 -> V_25 - V_22 -> V_15 ;
if ( V_23 < 8 ) {
V_4 -> V_26 ++ ;
F_2 ( V_4 , V_2 -> V_16 , 0 , V_17 ) ;
V_4 -> V_15 = sizeof( struct V_3 ) +
sizeof( struct V_21 ) ;
V_20 -> V_15 = sizeof( struct V_21 ) ;
V_22 -> V_15 = 0 ;
}
V_24 = ( void * ) ( V_22 + 1 ) + V_22 -> V_15 ;
* V_24 = V_18 ;
V_22 -> V_15 += 8 ;
V_20 -> V_15 += 8 ;
V_4 -> V_15 += 8 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_18 )
{
F_5 ( V_2 , V_18 ) ;
F_3 ( V_2 , V_18 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_6 * V_27 , struct V_3 * V_28 ,
struct V_21 * V_29 )
{
struct V_6 * V_4 ;
struct V_3 * V_20 ;
struct V_21 * V_22 ;
struct V_30 * V_31 ;
V_4 = F_7 ( V_32 , V_17 ) ;
if ( ! V_4 )
return - V_33 ;
V_4 -> V_9 = V_27 -> V_9 ;
V_4 -> V_14 = V_27 -> V_14 ;
V_4 -> V_26 = 0 ;
V_4 -> V_15 = sizeof( struct V_3 ) +
sizeof( struct V_21 ) ;
V_20 = (struct V_3 * ) ( V_4 + 1 ) ;
V_22 = (struct V_21 * ) ( V_20 + 1 ) ;
V_20 -> type = V_34 ;
V_20 -> V_9 = V_28 -> V_9 ;
V_20 -> V_15 = sizeof( struct V_21 ) ;
V_22 -> V_22 = V_29 -> V_22 ;
V_22 -> V_15 = 0 ;
V_2 -> V_19 = V_4 ;
V_2 -> V_25 = V_32 - V_4 -> V_15 - sizeof( struct V_6 ) ;
if ( V_29 -> V_22 == V_35 ) {
T_2 V_18 ;
F_8 ( & V_2 -> V_36 ) ;
F_9 (sl, &dev->slist, w1_slave_entry) {
memcpy ( & V_18 , & V_31 -> V_37 , sizeof( V_18 ) ) ;
F_3 ( V_2 , V_18 ) ;
}
F_10 ( & V_2 -> V_36 ) ;
} else {
F_11 ( V_2 , V_22 -> V_22 == V_38 ?
V_39 : V_40 , F_4 ) ;
}
V_4 -> V_26 = 0 ;
F_2 ( V_4 , V_2 -> V_16 , 0 , V_17 ) ;
V_2 -> V_19 = NULL ;
V_2 -> V_25 = 0 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_4 , struct V_3 * V_20 ,
struct V_21 * V_22 , T_3 V_16 )
{
void * V_24 ;
struct V_3 * V_41 ;
struct V_21 * V_42 ;
struct V_6 * V_43 ;
int V_44 ;
V_24 = F_7 ( sizeof( struct V_6 ) +
sizeof( struct V_3 ) +
sizeof( struct V_21 ) +
V_22 -> V_15 , V_17 ) ;
if ( ! V_24 )
return - V_33 ;
V_43 = (struct V_6 * ) ( V_24 ) ;
V_41 = (struct V_3 * ) ( V_43 + 1 ) ;
V_42 = (struct V_21 * ) ( V_41 + 1 ) ;
memcpy ( V_43 , V_4 , sizeof( struct V_6 ) ) ;
memcpy ( V_41 , V_20 , sizeof( struct V_3 ) ) ;
memcpy ( V_42 , V_22 , sizeof( struct V_21 ) ) ;
V_43 -> V_26 = V_4 -> V_14 + 1 ;
V_43 -> V_15 = sizeof( struct V_3 ) +
sizeof( struct V_21 ) + V_22 -> V_15 ;
V_41 -> V_15 = sizeof( struct V_21 ) + V_22 -> V_15 ;
memcpy ( V_42 -> V_24 , V_22 -> V_24 , V_42 -> V_15 ) ;
V_44 = F_2 ( V_43 , V_16 , 0 , V_17 ) ;
F_12 ( V_24 ) ;
return V_44 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_6 * V_4 ,
struct V_3 * V_20 , struct V_21 * V_22 )
{
int V_44 = 0 ;
switch ( V_22 -> V_22 ) {
case V_45 :
F_15 ( V_2 , V_22 -> V_24 , V_22 -> V_15 ) ;
F_13 ( V_4 , V_20 , V_22 , V_2 -> V_16 ) ;
break;
case V_46 :
F_16 ( V_2 , V_22 -> V_24 , V_22 -> V_15 ) ;
F_13 ( V_4 , V_20 , V_22 , V_2 -> V_16 ) ;
break;
case V_47 :
F_17 ( V_2 , V_22 -> V_24 , V_22 -> V_15 ) ;
break;
default:
V_44 = - V_48 ;
break;
}
return V_44 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_6 * V_4 , struct V_3 * V_20 ,
struct V_21 * V_22 )
{
struct V_30 * V_31 ;
int V_44 = 0 ;
struct V_49 * V_9 ;
if ( V_22 -> V_15 != 8 )
return - V_48 ;
V_9 = (struct V_49 * ) V_22 -> V_24 ;
V_31 = F_19 ( V_2 , V_9 ) ;
switch ( V_22 -> V_22 ) {
case V_50 :
if ( V_31 )
V_44 = - V_48 ;
else
V_44 = F_20 ( V_2 , V_9 ) ;
break;
case V_51 :
if ( V_31 )
F_21 ( V_31 ) ;
else
V_44 = - V_48 ;
break;
default:
V_44 = - V_48 ;
break;
}
return V_44 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_6 * V_27 , struct V_3 * V_28 ,
struct V_21 * V_29 )
{
int V_44 = - V_48 ;
switch ( V_29 -> V_22 ) {
case V_52 :
case V_38 :
case V_35 :
F_10 ( & V_2 -> V_53 ) ;
V_44 = F_6 ( V_2 , V_27 , V_28 , V_29 ) ;
F_8 ( & V_2 -> V_53 ) ;
break;
case V_46 :
case V_47 :
case V_45 :
V_44 = F_14 ( V_2 , V_27 , V_28 , V_29 ) ;
break;
case V_54 :
V_44 = F_23 ( V_2 ) ;
break;
case V_50 :
case V_51 :
F_10 ( & V_2 -> V_53 ) ;
F_8 ( & V_2 -> V_55 ) ;
V_44 = F_18 ( V_2 , V_27 , V_28 ,
V_29 ) ;
F_10 ( & V_2 -> V_55 ) ;
F_8 ( & V_2 -> V_53 ) ;
break;
default:
V_44 = - V_48 ;
break;
}
return V_44 ;
}
static int F_24 ( struct V_30 * V_31 , struct V_6 * V_4 ,
struct V_3 * V_20 , struct V_21 * V_22 )
{
F_25 ( & V_31 -> V_56 -> V_2 , L_1 ,
V_57 , V_31 -> V_37 . V_58 , ( unsigned long long ) V_31 -> V_37 . V_9 ,
V_31 -> V_37 . V_59 , V_22 -> V_22 , V_22 -> V_15 ) ;
return F_14 ( V_31 -> V_56 , V_4 , V_20 , V_22 ) ;
}
static int F_26 ( struct V_6 * V_4 ,
struct V_3 * V_60 , T_3 V_16 )
{
struct V_1 * V_7 ;
struct V_6 * V_61 ;
struct V_3 * V_8 ;
T_3 * V_9 ;
V_61 = F_27 ( V_32 , V_17 ) ;
if ( ! V_61 )
return - V_33 ;
V_61 -> V_9 . V_10 = V_11 ;
V_61 -> V_9 . V_12 = V_13 ;
V_61 -> V_14 = V_4 -> V_14 ;
V_61 -> V_26 = 1 ;
V_61 -> V_15 = sizeof( struct V_3 ) ;
V_8 = (struct V_3 * ) ( V_61 + 1 ) ;
V_8 -> type = V_62 ;
V_8 -> V_63 = 0 ;
V_8 -> V_15 = 0 ;
V_9 = ( T_3 * ) ( V_8 + 1 ) ;
F_8 ( & V_64 ) ;
F_9 (m, &w1_masters, w1_master_entry) {
if ( V_61 -> V_15 + sizeof( * V_9 ) > V_32 - sizeof( struct V_6 ) ) {
F_2 ( V_61 , V_16 , 0 , V_17 ) ;
V_61 -> V_26 ++ ;
V_61 -> V_15 = sizeof( struct V_3 ) ;
V_8 -> V_15 = 0 ;
V_9 = ( T_3 * ) ( V_8 + 1 ) ;
}
* V_9 = V_7 -> V_9 ;
V_8 -> V_15 += sizeof( * V_9 ) ;
V_61 -> V_15 += sizeof( * V_9 ) ;
V_9 ++ ;
}
V_61 -> V_26 = 0 ;
F_2 ( V_61 , V_16 , 0 , V_17 ) ;
F_10 ( & V_64 ) ;
F_12 ( V_61 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_65 , struct V_3 * V_66 ,
struct V_21 * V_67 , int V_16 , int error )
{
struct V_6 * V_68 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
V_68 = F_7 ( sizeof( * V_4 ) + sizeof( * V_22 ) + sizeof( * V_68 ) , V_17 ) ;
if ( ! V_68 )
return - V_33 ;
V_4 = (struct V_3 * ) ( V_68 + 1 ) ;
V_22 = (struct V_21 * ) ( V_4 + 1 ) ;
memcpy ( V_68 , V_65 , sizeof( * V_68 ) ) ;
V_68 -> V_15 = sizeof( * V_4 ) ;
memcpy ( V_4 , V_66 , sizeof( * V_4 ) ) ;
V_4 -> V_15 = 0 ;
V_4 -> V_63 = ( short ) - error ;
if ( V_67 ) {
memcpy ( V_22 , V_67 , sizeof( * V_22 ) ) ;
V_22 -> V_15 = 0 ;
V_4 -> V_15 += sizeof( * V_22 ) ;
V_68 -> V_15 += sizeof( * V_22 ) ;
}
error = F_2 ( V_68 , V_16 , 0 , V_17 ) ;
F_12 ( V_68 ) ;
return error ;
}
static void F_29 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_71 * V_72 = F_30 ( V_70 , struct V_71 ,
V_73 ) ;
T_4 V_74 = V_72 -> V_7 -> V_15 ;
T_5 * V_75 = V_72 -> V_7 -> V_24 ;
int V_44 = 0 ;
struct V_30 * V_31 = V_72 -> V_31 ;
struct V_21 * V_22 = NULL ;
F_8 ( & V_2 -> V_53 ) ;
V_2 -> V_16 = V_72 -> V_76 -> V_16 ;
if ( V_31 && F_31 ( V_31 ) )
V_44 = - V_77 ;
while ( V_74 && ! V_44 ) {
V_22 = (struct V_21 * ) V_75 ;
if ( V_22 -> V_15 + sizeof( struct V_21 ) > V_74 ) {
V_44 = - V_78 ;
break;
}
if ( V_31 )
V_44 = F_24 ( V_31 , & V_72 -> V_76 -> V_4 ,
V_72 -> V_7 , V_22 ) ;
else
V_44 = F_22 ( V_2 , & V_72 -> V_76 -> V_4 ,
V_72 -> V_7 , V_22 ) ;
F_28 ( & V_72 -> V_76 -> V_4 , V_72 -> V_7 , V_22 ,
V_72 -> V_76 -> V_16 , V_44 ) ;
V_44 = 0 ;
V_75 += V_22 -> V_15 + sizeof( struct V_21 ) ;
V_74 -= V_22 -> V_15 + sizeof( struct V_21 ) ;
}
if ( ! V_22 || V_44 )
F_28 ( & V_72 -> V_76 -> V_4 , V_72 -> V_7 , V_22 ,
V_72 -> V_76 -> V_16 , V_44 ) ;
if ( V_31 )
F_32 ( V_31 ) ;
else
F_33 ( & V_2 -> V_79 ) ;
V_2 -> V_16 = 0 ;
F_10 ( & V_2 -> V_53 ) ;
F_8 ( & V_2 -> V_36 ) ;
F_34 ( & V_70 -> V_80 ) ;
F_10 ( & V_2 -> V_36 ) ;
if ( F_35 ( 1 , & V_72 -> V_76 -> V_79 ) == 0 )
F_12 ( V_72 -> V_76 ) ;
}
static void F_36 ( struct V_6 * V_4 , struct V_81 * V_82 )
{
struct V_3 * V_7 = (struct V_3 * ) ( V_4 + 1 ) ;
struct V_30 * V_31 ;
struct V_1 * V_2 ;
T_4 V_83 ;
int V_44 = 0 ;
struct V_84 * V_76 = NULL ;
struct V_71 * V_72 = NULL ;
int V_85 = 0 ;
V_83 = V_4 -> V_15 ;
while ( V_83 && ! V_44 ) {
if ( V_7 -> V_15 + sizeof( struct V_3 ) > V_83 ) {
V_44 = - V_78 ;
break;
}
if ( V_7 -> type == V_34 || V_7 -> type == V_86 )
++ V_85 ;
V_83 -= sizeof( struct V_3 ) + V_7 -> V_15 ;
V_7 = (struct V_3 * ) ( ( ( T_5 * ) V_7 ) +
sizeof( struct V_3 ) + V_7 -> V_15 ) ;
}
V_7 = (struct V_3 * ) ( V_4 + 1 ) ;
if ( V_85 ) {
long V_87 = sizeof( struct V_84 ) + V_4 -> V_15 +
V_85 * sizeof( struct V_71 ) ;
V_76 = F_27 ( V_87 , V_17 ) ;
if ( ! V_76 ) {
F_28 ( V_4 , V_7 , NULL , V_82 -> V_16 ,
- V_33 ) ;
return;
}
F_37 ( & V_76 -> V_79 , 1 ) ;
V_76 -> V_16 = V_82 -> V_16 ;
memcpy ( & V_76 -> V_4 , V_4 , sizeof( * V_4 ) + V_4 -> V_15 ) ;
V_72 = (struct V_71 * ) ( ( T_5 * ) V_76 -> V_4 . V_24 + V_4 -> V_15 ) ;
}
V_83 = V_4 -> V_15 ;
while ( V_83 && ! V_44 ) {
V_2 = NULL ;
V_31 = NULL ;
if ( V_7 -> V_15 + sizeof( struct V_3 ) > V_83 ) {
V_44 = - V_78 ;
break;
}
if ( V_7 -> type == V_62 ) {
V_44 = F_26 ( V_4 , V_7 , V_82 -> V_16 ) ;
goto V_88;
}
if ( ! V_7 -> V_15 ) {
V_44 = - V_89 ;
goto V_88;
}
if ( V_7 -> type == V_34 ) {
V_2 = F_38 ( V_7 -> V_9 . V_90 . V_9 ) ;
} else if ( V_7 -> type == V_86 ) {
V_31 = F_39 ( (struct V_49 * ) V_7 -> V_9 . V_9 ) ;
if ( V_31 )
V_2 = V_31 -> V_56 ;
} else {
F_40 ( V_91
L_2 ,
V_57 , V_4 -> V_9 . V_10 , V_4 -> V_9 . V_12 ,
V_7 -> type , V_7 -> V_15 ) ;
V_44 = - V_89 ;
goto V_88;
}
if ( ! V_2 ) {
V_44 = - V_77 ;
goto V_88;
}
V_44 = 0 ;
F_41 ( & V_76 -> V_79 ) ;
V_72 -> V_73 . V_92 = F_29 ;
V_72 -> V_76 = V_76 ;
V_72 -> V_7 = (struct V_3 * ) ( ( T_5 * ) & V_76 -> V_4 +
( V_93 ) ( ( T_5 * ) V_7 - ( T_5 * ) V_4 ) ) ;
V_72 -> V_31 = V_31 ;
V_72 -> V_2 = V_2 ;
F_8 ( & V_2 -> V_36 ) ;
F_42 ( & V_72 -> V_73 . V_80 , & V_2 -> V_94 ) ;
F_43 ( V_2 -> V_95 ) ;
F_10 ( & V_2 -> V_36 ) ;
++ V_72 ;
V_88:
if ( V_44 )
F_28 ( V_4 , V_7 , NULL , V_82 -> V_16 , V_44 ) ;
V_83 -= sizeof( struct V_3 ) + V_7 -> V_15 ;
V_7 = (struct V_3 * ) ( ( ( T_5 * ) V_7 ) +
sizeof( struct V_3 ) + V_7 -> V_15 ) ;
if ( V_44 == - V_77 )
V_44 = 0 ;
}
if ( V_76 && F_35 ( 1 , & V_76 -> V_79 ) == 0 )
F_12 ( V_76 ) ;
}
int F_44 ( void )
{
struct V_96 V_97 = { . V_10 = V_11 , . V_12 = V_13 } ;
return F_45 ( & V_97 , L_3 , & F_36 ) ;
}
void F_46 ( void )
{
struct V_96 V_97 = { . V_10 = V_11 , . V_12 = V_13 } ;
F_47 ( & V_97 ) ;
}
void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
int F_44 ( void )
{
return 0 ;
}
void F_46 ( void )
{
}
