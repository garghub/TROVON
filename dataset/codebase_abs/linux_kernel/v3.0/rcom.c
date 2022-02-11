static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_5 , int type , int V_6 ,
struct V_7 * * V_8 , struct V_9 * * V_10 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
char * V_13 ;
int V_14 = sizeof( struct V_7 ) + V_6 ;
V_12 = F_4 ( V_5 , V_14 , V_15 , & V_13 ) ;
if ( ! V_12 ) {
F_5 ( L_1 ,
V_5 , type , V_6 ) ;
return - V_16 ;
}
memset ( V_13 , 0 , V_14 ) ;
V_11 = (struct V_7 * ) V_13 ;
V_11 -> V_17 . V_18 = ( V_19 | V_20 ) ;
V_11 -> V_17 . V_21 = V_2 -> V_22 ;
V_11 -> V_17 . V_23 = F_6 () ;
V_11 -> V_17 . V_24 = V_14 ;
V_11 -> V_17 . V_25 = V_26 ;
V_11 -> V_27 = type ;
F_7 ( & V_2 -> V_28 ) ;
V_11 -> V_29 = V_2 -> V_30 ;
F_8 ( & V_2 -> V_28 ) ;
* V_10 = V_12 ;
* V_8 = V_11 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_9 * V_12 ,
struct V_7 * V_11 )
{
F_10 ( V_11 ) ;
F_11 ( V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
V_32 -> V_33 = F_13 ( V_2 -> V_34 ) ;
V_32 -> V_35 = F_13 ( V_2 -> V_36 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_37 )
{
struct V_31 * V_32 = (struct V_31 * ) V_11 -> V_38 ;
T_1 V_39 = sizeof( struct V_7 ) + sizeof( struct V_31 ) ;
if ( ( V_11 -> V_17 . V_18 & 0xFFFF0000 ) != V_19 ) {
F_15 ( V_2 , L_2 ,
V_19 | V_20 , V_37 ,
V_11 -> V_17 . V_18 ) ;
return - V_40 ;
}
if ( V_11 -> V_17 . V_24 < V_39 ) {
F_15 ( V_2 , L_3 ,
V_11 -> V_17 . V_24 , V_37 ) ;
return - V_40 ;
}
if ( F_16 ( V_32 -> V_33 ) != V_2 -> V_34 ||
F_16 ( V_32 -> V_35 ) != V_2 -> V_36 ) {
F_15 ( V_2 , L_4 ,
V_2 -> V_34 , V_2 -> V_36 , V_37 ,
F_16 ( V_32 -> V_33 ) ,
F_16 ( V_32 -> V_35 ) ) ;
return - V_40 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , T_2 * V_41 )
{
F_7 ( & V_2 -> V_42 ) ;
* V_41 = ++ V_2 -> V_43 ;
F_18 ( V_44 , & V_2 -> V_4 ) ;
F_8 ( & V_2 -> V_42 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_42 ) ;
F_20 ( V_44 , & V_2 -> V_4 ) ;
F_20 ( V_3 , & V_2 -> V_4 ) ;
F_8 ( & V_2 -> V_42 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_37 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error = 0 ;
V_2 -> V_45 = V_37 ;
if ( V_37 == F_6 () ) {
V_11 = V_2 -> V_46 ;
V_11 -> V_47 = F_22 ( V_2 ) ;
goto V_48;
}
error = F_3 ( V_2 , V_37 , V_49 , 0 , & V_11 , & V_12 ) ;
if ( error )
goto V_48;
F_17 ( V_2 , & V_11 -> V_50 ) ;
memset ( V_2 -> V_46 , 0 , V_51 . V_52 ) ;
F_9 ( V_2 , V_12 , V_11 ) ;
error = F_23 ( V_2 , & F_1 ) ;
F_19 ( V_2 ) ;
if ( error )
goto V_48;
V_11 = V_2 -> V_46 ;
if ( V_11 -> V_47 == - V_53 ) {
F_24 ( V_2 , L_5 , V_37 ) ;
V_11 -> V_47 = 0 ;
} else
error = F_14 ( V_2 , V_11 , V_37 ) ;
V_48:
return error ;
}
static void F_25 ( struct V_1 * V_2 , struct V_7 * V_54 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error , V_37 = V_54 -> V_17 . V_23 ;
error = F_3 ( V_2 , V_37 , V_55 ,
sizeof( struct V_31 ) , & V_11 , & V_12 ) ;
if ( error )
return;
V_11 -> V_50 = V_54 -> V_50 ;
V_11 -> V_56 = V_54 -> V_29 ;
V_11 -> V_47 = F_22 ( V_2 ) ;
F_12 ( V_2 , (struct V_31 * ) V_11 -> V_38 ) ;
F_9 ( V_2 , V_12 , V_11 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_7 * V_54 )
{
F_7 ( & V_2 -> V_42 ) ;
if ( ! F_2 ( V_44 , & V_2 -> V_4 ) ||
V_54 -> V_50 != V_2 -> V_43 ) {
F_24 ( V_2 , L_6 ,
V_54 -> V_27 , V_54 -> V_17 . V_23 ,
( unsigned long long ) V_54 -> V_50 ,
( unsigned long long ) V_2 -> V_43 ) ;
goto V_48;
}
memcpy ( V_2 -> V_46 , V_54 , V_54 -> V_17 . V_24 ) ;
F_18 ( V_3 , & V_2 -> V_4 ) ;
F_20 ( V_44 , & V_2 -> V_4 ) ;
F_27 ( & V_2 -> V_57 ) ;
V_48:
F_8 ( & V_2 -> V_42 ) ;
}
int F_28 ( struct V_1 * V_2 , int V_37 , char * V_58 , int V_59 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error = 0 ;
int V_60 = V_51 . V_52 - sizeof( struct V_7 ) ;
V_2 -> V_45 = V_37 ;
if ( V_37 == F_6 () ) {
V_2 -> V_46 -> V_17 . V_24 =
V_51 . V_52 ;
F_29 ( V_2 , V_58 , V_59 ,
V_2 -> V_46 -> V_38 ,
V_60 , V_37 ) ;
goto V_48;
}
error = F_3 ( V_2 , V_37 , V_61 , V_59 , & V_11 , & V_12 ) ;
if ( error )
goto V_48;
memcpy ( V_11 -> V_38 , V_58 , V_59 ) ;
F_17 ( V_2 , & V_11 -> V_50 ) ;
memset ( V_2 -> V_46 , 0 , V_51 . V_52 ) ;
F_9 ( V_2 , V_12 , V_11 ) ;
error = F_23 ( V_2 , & F_1 ) ;
F_19 ( V_2 ) ;
V_48:
return error ;
}
static void F_30 ( struct V_1 * V_2 , struct V_7 * V_54 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error , V_62 , V_63 , V_37 ;
V_37 = V_54 -> V_17 . V_23 ;
V_62 = V_54 -> V_17 . V_24 - sizeof( struct V_7 ) ;
V_63 = V_51 . V_52 - sizeof( struct V_7 ) ;
error = F_3 ( V_2 , V_37 , V_64 , V_63 , & V_11 , & V_12 ) ;
if ( error )
return;
V_11 -> V_50 = V_54 -> V_50 ;
V_11 -> V_56 = V_54 -> V_29 ;
F_29 ( V_2 , V_54 -> V_38 , V_62 , V_11 -> V_38 , V_63 ,
V_37 ) ;
F_9 ( V_2 , V_12 , V_11 ) ;
}
int F_31 ( struct V_65 * V_66 , int V_67 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
struct V_1 * V_2 = V_66 -> V_68 ;
int error ;
error = F_3 ( V_2 , V_67 , V_69 , V_66 -> V_70 ,
& V_11 , & V_12 ) ;
if ( error )
goto V_48;
memcpy ( V_11 -> V_38 , V_66 -> V_71 , V_66 -> V_70 ) ;
V_11 -> V_50 = ( unsigned long ) V_66 ;
F_9 ( V_2 , V_12 , V_11 ) ;
V_48:
return error ;
}
static void F_32 ( struct V_1 * V_2 , struct V_7 * V_54 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error , V_72 , V_37 = V_54 -> V_17 . V_23 ;
int V_6 = V_54 -> V_17 . V_24 - sizeof( struct V_7 ) ;
error = F_3 ( V_2 , V_37 , V_73 , 0 , & V_11 , & V_12 ) ;
if ( error )
return;
error = F_33 ( V_2 , V_37 , V_54 -> V_38 , V_6 , & V_72 ) ;
if ( error )
V_72 = error ;
V_11 -> V_47 = V_72 ;
V_11 -> V_50 = V_54 -> V_50 ;
V_11 -> V_56 = V_54 -> V_29 ;
F_9 ( V_2 , V_12 , V_11 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_7 * V_54 )
{
F_35 ( V_2 , V_54 ) ;
}
static void F_36 ( struct V_65 * V_66 , struct V_74 * V_75 ,
struct V_76 * V_77 )
{
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_77 -> V_78 = F_13 ( V_75 -> V_79 ) ;
V_77 -> V_80 = F_13 ( V_75 -> V_81 ) ;
V_77 -> V_82 = F_13 ( V_75 -> V_83 ) ;
V_77 -> V_84 = F_13 ( V_75 -> V_85 ) ;
V_77 -> V_86 = F_13 ( V_75 -> V_87 ) ;
V_77 -> V_88 = V_75 -> V_89 ;
V_77 -> V_90 = V_75 -> V_91 ;
V_77 -> V_92 = V_75 -> V_93 ;
V_77 -> V_94 = F_37 ( V_75 -> V_95 ) ;
if ( V_75 -> V_96 )
V_77 -> V_97 |= V_98 ;
if ( V_75 -> V_99 )
V_77 -> V_97 |= V_100 ;
V_77 -> V_101 = F_37 ( V_66 -> V_70 ) ;
memcpy ( V_77 -> V_102 , V_66 -> V_71 , V_66 -> V_70 ) ;
if ( V_75 -> V_103 )
memcpy ( V_77 -> V_104 , V_75 -> V_103 , V_66 -> V_68 -> V_34 ) ;
}
int F_38 ( struct V_65 * V_66 , struct V_74 * V_75 )
{
struct V_1 * V_2 = V_66 -> V_68 ;
struct V_7 * V_11 ;
struct V_9 * V_12 ;
struct V_76 * V_77 ;
int error , V_6 = sizeof( struct V_76 ) ;
if ( V_75 -> V_103 )
V_6 += V_2 -> V_34 ;
error = F_3 ( V_2 , V_66 -> V_105 , V_106 , V_6 , & V_11 , & V_12 ) ;
if ( error )
goto V_48;
V_77 = (struct V_76 * ) V_11 -> V_38 ;
F_36 ( V_66 , V_75 , V_77 ) ;
V_11 -> V_50 = ( unsigned long ) V_66 ;
F_9 ( V_2 , V_12 , V_11 ) ;
V_48:
return error ;
}
static void F_39 ( struct V_1 * V_2 , struct V_7 * V_54 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error , V_37 = V_54 -> V_17 . V_23 ;
F_40 ( V_2 , V_54 ) ;
error = F_3 ( V_2 , V_37 , V_107 ,
sizeof( struct V_76 ) , & V_11 , & V_12 ) ;
if ( error )
return;
memcpy ( V_11 -> V_38 , V_54 -> V_38 , sizeof( struct V_76 ) ) ;
V_11 -> V_50 = V_54 -> V_50 ;
V_11 -> V_56 = V_54 -> V_29 ;
F_9 ( V_2 , V_12 , V_11 ) ;
}
int F_41 ( int V_37 , struct V_7 * V_54 )
{
struct V_7 * V_11 ;
struct V_31 * V_32 ;
struct V_9 * V_12 ;
char * V_13 ;
int V_14 = sizeof( struct V_7 ) + sizeof( struct V_31 ) ;
V_12 = F_4 ( V_37 , V_14 , V_15 , & V_13 ) ;
if ( ! V_12 )
return - V_16 ;
memset ( V_13 , 0 , V_14 ) ;
V_11 = (struct V_7 * ) V_13 ;
V_11 -> V_17 . V_18 = ( V_19 | V_20 ) ;
V_11 -> V_17 . V_21 = V_54 -> V_17 . V_21 ;
V_11 -> V_17 . V_23 = F_6 () ;
V_11 -> V_17 . V_24 = V_14 ;
V_11 -> V_17 . V_25 = V_26 ;
V_11 -> V_27 = V_55 ;
V_11 -> V_50 = V_54 -> V_50 ;
V_11 -> V_56 = V_54 -> V_29 ;
V_11 -> V_47 = - V_53 ;
V_32 = (struct V_31 * ) V_11 -> V_38 ;
V_32 -> V_33 = F_13 ( ~ 0U ) ;
F_10 ( V_11 ) ;
F_11 ( V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_7 * V_11 )
{
T_2 V_108 ;
int V_109 = 0 ;
switch ( V_11 -> V_27 ) {
case V_55 :
case V_64 :
case V_73 :
case V_107 :
F_7 ( & V_2 -> V_28 ) ;
V_108 = V_2 -> V_30 ;
F_8 ( & V_2 -> V_28 ) ;
if ( V_11 -> V_56 != V_108 ) {
F_24 ( V_2 , L_7
L_8 ,
V_11 -> V_27 , V_11 -> V_17 . V_23 ,
( unsigned long long ) V_11 -> V_56 ,
( unsigned long long ) V_108 ) ;
V_109 = 1 ;
}
}
return V_109 ;
}
void F_43 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_37 )
{
int V_110 = sizeof( struct V_7 ) + sizeof( struct V_76 ) ;
if ( F_44 ( V_2 ) && ( V_11 -> V_27 != V_49 ) ) {
F_24 ( V_2 , L_9 ,
V_11 -> V_27 , V_37 ) ;
goto V_48;
}
if ( F_42 ( V_2 , V_11 ) )
goto V_48;
switch ( V_11 -> V_27 ) {
case V_49 :
F_25 ( V_2 , V_11 ) ;
break;
case V_61 :
F_30 ( V_2 , V_11 ) ;
break;
case V_69 :
F_32 ( V_2 , V_11 ) ;
break;
case V_106 :
if ( V_11 -> V_17 . V_24 < V_110 )
goto V_111;
F_39 ( V_2 , V_11 ) ;
break;
case V_55 :
F_26 ( V_2 , V_11 ) ;
break;
case V_64 :
F_26 ( V_2 , V_11 ) ;
break;
case V_73 :
F_34 ( V_2 , V_11 ) ;
break;
case V_107 :
if ( V_11 -> V_17 . V_24 < V_110 )
goto V_111;
F_45 ( V_2 , V_11 ) ;
break;
default:
F_15 ( V_2 , L_10 , V_11 -> V_27 ) ;
}
V_48:
return;
V_111:
F_15 ( V_2 , L_11 ,
V_11 -> V_27 , V_37 ) ;
}
