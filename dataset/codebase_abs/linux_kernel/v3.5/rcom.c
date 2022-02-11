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
static void F_12 ( struct V_1 * V_2 , struct V_31 * V_32 ,
T_1 V_33 )
{
V_32 -> V_34 = F_13 ( V_33 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_35 * V_36 ,
T_1 V_37 )
{
V_36 -> V_38 = F_13 ( V_2 -> V_39 ) ;
V_36 -> V_40 = F_13 ( V_2 -> V_41 ) ;
V_36 -> V_42 = F_15 ( V_2 -> V_43 ) ;
V_36 -> V_44 = F_15 ( V_37 ) ;
V_36 -> V_45 = F_13 ( V_2 -> V_46 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_47 )
{
struct V_35 * V_36 = (struct V_35 * ) V_11 -> V_48 ;
if ( ( V_11 -> V_17 . V_18 & 0xFFFF0000 ) != V_19 ) {
F_17 ( V_2 , L_2 ,
V_19 | V_20 , V_47 ,
V_11 -> V_17 . V_18 ) ;
return - V_49 ;
}
if ( F_18 ( V_36 -> V_38 ) != V_2 -> V_39 ||
F_18 ( V_36 -> V_40 ) != V_2 -> V_41 ) {
F_17 ( V_2 , L_3 ,
V_2 -> V_39 , V_2 -> V_41 , V_47 ,
F_18 ( V_36 -> V_38 ) ,
F_18 ( V_36 -> V_40 ) ) ;
return - V_49 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , T_2 * V_50 )
{
F_7 ( & V_2 -> V_51 ) ;
* V_50 = ++ V_2 -> V_52 ;
F_20 ( V_53 , & V_2 -> V_4 ) ;
F_8 ( & V_2 -> V_51 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_51 ) ;
F_22 ( V_53 , & V_2 -> V_4 ) ;
F_22 ( V_3 , & V_2 -> V_4 ) ;
F_8 ( & V_2 -> V_51 ) ;
}
int F_23 ( struct V_1 * V_2 , int V_47 , T_1 V_54 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error = 0 ;
V_2 -> V_55 = V_47 ;
if ( V_47 == F_6 () ) {
V_11 = V_2 -> V_56 ;
V_11 -> V_57 = F_24 ( V_2 ) ;
goto V_58;
}
error = F_3 ( V_2 , V_47 , V_59 ,
sizeof( struct V_31 ) , & V_11 , & V_12 ) ;
if ( error )
goto V_58;
F_12 ( V_2 , (struct V_31 * ) V_11 -> V_48 , V_54 ) ;
F_19 ( V_2 , & V_11 -> V_60 ) ;
memset ( V_2 -> V_56 , 0 , V_61 . V_62 ) ;
F_9 ( V_2 , V_12 , V_11 ) ;
error = F_25 ( V_2 , & F_1 ) ;
F_21 ( V_2 ) ;
if ( error )
goto V_58;
V_11 = V_2 -> V_56 ;
if ( V_11 -> V_57 == - V_63 ) {
F_26 ( V_2 , L_4 , V_47 ) ;
V_11 -> V_57 = 0 ;
error = 0 ;
} else {
error = F_16 ( V_2 , V_11 , V_47 ) ;
}
V_58:
return error ;
}
static void F_27 ( struct V_1 * V_2 , struct V_7 * V_64 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
struct V_31 * V_32 ;
T_1 V_65 ;
int V_47 = V_64 -> V_17 . V_23 ;
int V_6 = sizeof( struct V_35 ) ;
int V_37 = 0 ;
int error ;
if ( ! F_28 ( & V_64 -> V_17 ) ) {
V_65 = F_24 ( V_2 ) ;
goto V_66;
}
V_32 = (struct V_31 * ) V_64 -> V_48 ;
if ( ! ( V_32 -> V_34 & V_67 ) ) {
V_65 = F_24 ( V_2 ) ;
goto V_66;
}
F_7 ( & V_2 -> V_28 ) ;
V_65 = V_2 -> V_68 ;
V_37 = V_2 -> V_69 ;
F_8 ( & V_2 -> V_28 ) ;
V_6 += V_37 * sizeof( struct V_70 ) ;
V_66:
error = F_3 ( V_2 , V_47 , V_71 ,
V_6 , & V_11 , & V_12 ) ;
if ( error )
return;
V_11 -> V_60 = V_64 -> V_60 ;
V_11 -> V_72 = V_64 -> V_29 ;
V_11 -> V_57 = V_65 ;
F_14 ( V_2 , (struct V_35 * ) V_11 -> V_48 , V_37 ) ;
if ( ! V_37 )
goto V_73;
F_7 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_69 != V_37 ) {
F_8 ( & V_2 -> V_28 ) ;
F_26 ( V_2 , L_5 ,
V_37 , V_2 -> V_69 ) ;
V_11 -> V_57 = 0 ;
F_14 ( V_2 , (struct V_35 * ) V_11 -> V_48 , 0 ) ;
goto V_73;
}
F_29 ( V_2 , V_11 ) ;
F_8 ( & V_2 -> V_28 ) ;
V_73:
F_9 ( V_2 , V_12 , V_11 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_7 * V_64 )
{
F_7 ( & V_2 -> V_51 ) ;
if ( ! F_2 ( V_53 , & V_2 -> V_4 ) ||
V_64 -> V_60 != V_2 -> V_52 ) {
F_26 ( V_2 , L_6 ,
V_64 -> V_27 , V_64 -> V_17 . V_23 ,
( unsigned long long ) V_64 -> V_60 ,
( unsigned long long ) V_2 -> V_52 ) ;
goto V_58;
}
memcpy ( V_2 -> V_56 , V_64 , V_64 -> V_17 . V_24 ) ;
F_20 ( V_3 , & V_2 -> V_4 ) ;
F_22 ( V_53 , & V_2 -> V_4 ) ;
F_31 ( & V_2 -> V_74 ) ;
V_58:
F_8 ( & V_2 -> V_51 ) ;
}
int F_32 ( struct V_1 * V_2 , int V_47 , char * V_75 , int V_76 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error = 0 ;
int V_77 = V_61 . V_62 - sizeof( struct V_7 ) ;
V_2 -> V_55 = V_47 ;
if ( V_47 == F_6 () ) {
V_2 -> V_56 -> V_17 . V_24 =
V_61 . V_62 ;
F_33 ( V_2 , V_75 , V_76 ,
V_2 -> V_56 -> V_48 ,
V_77 , V_47 ) ;
goto V_58;
}
error = F_3 ( V_2 , V_47 , V_78 , V_76 , & V_11 , & V_12 ) ;
if ( error )
goto V_58;
memcpy ( V_11 -> V_48 , V_75 , V_76 ) ;
F_19 ( V_2 , & V_11 -> V_60 ) ;
memset ( V_2 -> V_56 , 0 , V_61 . V_62 ) ;
F_9 ( V_2 , V_12 , V_11 ) ;
error = F_25 ( V_2 , & F_1 ) ;
F_21 ( V_2 ) ;
V_58:
return error ;
}
static void F_34 ( struct V_1 * V_2 , struct V_7 * V_64 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error , V_79 , V_80 , V_47 ;
V_47 = V_64 -> V_17 . V_23 ;
V_79 = V_64 -> V_17 . V_24 - sizeof( struct V_7 ) ;
V_80 = V_61 . V_62 - sizeof( struct V_7 ) ;
error = F_3 ( V_2 , V_47 , V_81 , V_80 , & V_11 , & V_12 ) ;
if ( error )
return;
V_11 -> V_60 = V_64 -> V_60 ;
V_11 -> V_72 = V_64 -> V_29 ;
F_33 ( V_2 , V_64 -> V_48 , V_79 , V_11 -> V_48 , V_80 ,
V_47 ) ;
F_9 ( V_2 , V_12 , V_11 ) ;
}
int F_35 ( struct V_82 * V_83 , int V_84 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
struct V_1 * V_2 = V_83 -> V_85 ;
int error ;
error = F_3 ( V_2 , V_84 , V_86 , V_83 -> V_87 ,
& V_11 , & V_12 ) ;
if ( error )
goto V_58;
memcpy ( V_11 -> V_48 , V_83 -> V_88 , V_83 -> V_87 ) ;
V_11 -> V_60 = ( unsigned long ) V_83 ;
F_9 ( V_2 , V_12 , V_11 ) ;
V_58:
return error ;
}
static void F_36 ( struct V_1 * V_2 , struct V_7 * V_64 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error , V_89 , V_47 = V_64 -> V_17 . V_23 ;
int V_6 = V_64 -> V_17 . V_24 - sizeof( struct V_7 ) ;
error = F_3 ( V_2 , V_47 , V_90 , 0 , & V_11 , & V_12 ) ;
if ( error )
return;
error = F_37 ( V_2 , V_47 , V_64 -> V_48 , V_6 , & V_89 ) ;
if ( error )
V_89 = error ;
V_11 -> V_57 = V_89 ;
V_11 -> V_60 = V_64 -> V_60 ;
V_11 -> V_72 = V_64 -> V_29 ;
F_9 ( V_2 , V_12 , V_11 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_7 * V_64 )
{
F_39 ( V_2 , V_64 ) ;
}
static void F_40 ( struct V_82 * V_83 , struct V_91 * V_92 ,
struct V_93 * V_94 )
{
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_95 = F_13 ( V_92 -> V_96 ) ;
V_94 -> V_97 = F_13 ( V_92 -> V_98 ) ;
V_94 -> V_99 = F_13 ( V_92 -> V_100 ) ;
V_94 -> V_101 = F_13 ( V_92 -> V_102 ) ;
V_94 -> V_103 = F_13 ( V_92 -> V_104 ) ;
V_94 -> V_105 = V_92 -> V_106 ;
V_94 -> V_107 = V_92 -> V_108 ;
V_94 -> V_109 = V_92 -> V_110 ;
V_94 -> V_111 = F_15 ( V_92 -> V_112 ) ;
if ( V_92 -> V_113 )
V_94 -> V_114 |= V_115 ;
if ( V_92 -> V_116 )
V_94 -> V_114 |= V_117 ;
V_94 -> V_118 = F_15 ( V_83 -> V_87 ) ;
memcpy ( V_94 -> V_119 , V_83 -> V_88 , V_83 -> V_87 ) ;
if ( V_92 -> V_120 )
memcpy ( V_94 -> V_121 , V_92 -> V_120 , V_83 -> V_85 -> V_39 ) ;
}
int F_41 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = V_83 -> V_85 ;
struct V_7 * V_11 ;
struct V_9 * V_12 ;
struct V_93 * V_94 ;
int error , V_6 = sizeof( struct V_93 ) ;
if ( V_92 -> V_120 )
V_6 += V_2 -> V_39 ;
error = F_3 ( V_2 , V_83 -> V_122 , V_123 , V_6 , & V_11 , & V_12 ) ;
if ( error )
goto V_58;
V_94 = (struct V_93 * ) V_11 -> V_48 ;
F_40 ( V_83 , V_92 , V_94 ) ;
V_11 -> V_60 = ( unsigned long ) V_83 ;
F_9 ( V_2 , V_12 , V_11 ) ;
V_58:
return error ;
}
static void F_42 ( struct V_1 * V_2 , struct V_7 * V_64 )
{
struct V_7 * V_11 ;
struct V_9 * V_12 ;
int error , V_47 = V_64 -> V_17 . V_23 ;
F_43 ( V_2 , V_64 ) ;
error = F_3 ( V_2 , V_47 , V_124 ,
sizeof( struct V_93 ) , & V_11 , & V_12 ) ;
if ( error )
return;
memcpy ( V_11 -> V_48 , V_64 -> V_48 , sizeof( struct V_93 ) ) ;
V_11 -> V_60 = V_64 -> V_60 ;
V_11 -> V_72 = V_64 -> V_29 ;
F_9 ( V_2 , V_12 , V_11 ) ;
}
int F_44 ( int V_47 , struct V_7 * V_64 )
{
struct V_7 * V_11 ;
struct V_35 * V_36 ;
struct V_9 * V_12 ;
char * V_13 ;
int V_14 = sizeof( struct V_7 ) + sizeof( struct V_35 ) ;
V_12 = F_4 ( V_47 , V_14 , V_15 , & V_13 ) ;
if ( ! V_12 )
return - V_16 ;
memset ( V_13 , 0 , V_14 ) ;
V_11 = (struct V_7 * ) V_13 ;
V_11 -> V_17 . V_18 = ( V_19 | V_20 ) ;
V_11 -> V_17 . V_21 = V_64 -> V_17 . V_21 ;
V_11 -> V_17 . V_23 = F_6 () ;
V_11 -> V_17 . V_24 = V_14 ;
V_11 -> V_17 . V_25 = V_26 ;
V_11 -> V_27 = V_71 ;
V_11 -> V_60 = V_64 -> V_60 ;
V_11 -> V_72 = V_64 -> V_29 ;
V_11 -> V_57 = - V_63 ;
V_36 = (struct V_35 * ) V_11 -> V_48 ;
V_36 -> V_38 = F_13 ( ~ 0U ) ;
F_10 ( V_11 ) ;
F_11 ( V_12 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_47 )
{
int V_125 = sizeof( struct V_7 ) + sizeof( struct V_93 ) ;
int V_126 , V_127 = 0 , V_128 = 0 ;
T_1 V_65 ;
T_2 V_129 ;
switch ( V_11 -> V_27 ) {
case V_123 :
V_128 = 1 ;
break;
case V_124 :
V_128 = 1 ;
V_127 = 1 ;
break;
case V_71 :
case V_81 :
case V_90 :
V_127 = 1 ;
} ;
F_7 ( & V_2 -> V_28 ) ;
V_65 = V_2 -> V_68 ;
V_126 = F_2 ( V_130 , & V_2 -> V_4 ) ;
V_129 = V_2 -> V_30 ;
F_8 ( & V_2 -> V_28 ) ;
if ( ( V_126 && ( V_11 -> V_27 != V_59 ) ) ||
( V_127 && ( V_11 -> V_72 != V_129 ) ) ||
( V_128 && ! ( V_65 & V_131 ) ) ) {
F_46 ( V_2 , L_7
L_8 ,
V_11 -> V_27 ,
V_47 ,
( unsigned long long ) V_11 -> V_29 ,
( unsigned long long ) V_11 -> V_72 ,
( unsigned long long ) V_129 ,
V_65 , V_2 -> V_46 ) ;
goto V_58;
}
switch ( V_11 -> V_27 ) {
case V_59 :
F_27 ( V_2 , V_11 ) ;
break;
case V_78 :
F_34 ( V_2 , V_11 ) ;
break;
case V_86 :
F_36 ( V_2 , V_11 ) ;
break;
case V_123 :
if ( V_11 -> V_17 . V_24 < V_125 )
goto V_132;
F_42 ( V_2 , V_11 ) ;
break;
case V_71 :
F_30 ( V_2 , V_11 ) ;
break;
case V_81 :
F_30 ( V_2 , V_11 ) ;
break;
case V_90 :
F_38 ( V_2 , V_11 ) ;
break;
case V_124 :
if ( V_11 -> V_17 . V_24 < V_125 )
goto V_132;
F_47 ( V_2 , V_11 ) ;
break;
default:
F_17 ( V_2 , L_9 , V_11 -> V_27 ) ;
}
V_58:
return;
V_132:
F_17 ( V_2 , L_10 ,
V_11 -> V_27 , V_47 ) ;
}
