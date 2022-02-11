static void F_1
( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
struct V_7 * V_8 ;
int error ;
if ( V_5 -> type == V_9 ) {
switch ( V_2 -> V_10 ) {
case V_11 :
error = 0 ;
break;
case V_12 :
case V_13 :
error = - V_14 ;
break;
case V_15 :
error = - V_16 ;
break;
default:
error = - V_17 ;
break;
}
V_8 = V_5 -> V_18 ;
F_3 ( V_5 ,
V_8 , error ) ;
}
}
static T_1 F_4 ( struct V_19 * V_20 )
{
T_1 V_21 = 0 ;
for ( V_21 = 0 ; V_20 ; V_20 = F_5 ( V_20 ) )
V_21 += V_20 -> V_22 ;
return V_21 ;
}
static int
F_6 ( int V_23 , T_2 * V_24 )
{
switch ( V_23 ) {
case V_25 :
case V_26 :
case V_27 :
* V_24 = V_28 ;
break;
default:
F_7 ( L_1 ,
V_23 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_8 (
struct V_29 * V_30 ,
T_2 V_24 , const T_3 * V_31 ,
unsigned int V_32 ,
int V_33 )
{
struct V_19 V_34 , V_35 , V_36 , * V_37 [ 3 ] ;
unsigned int V_38 ;
struct V_39 * V_40 = V_30 -> V_40 ;
int V_41 = V_33 ? V_42 : V_43 ;
int V_44 ;
unsigned int V_45 = 0 , V_46 = 0 ;
T_3 * V_47 = F_9 ( V_32 , V_48 ) ;
if ( ! V_47 )
return - V_49 ;
memcpy ( V_47 , V_31 , V_32 ) ;
F_10 ( & V_40 -> V_50 ) ;
V_40 -> V_51 . V_52 . V_53 =
F_11 ( V_54 ) ;
V_40 -> V_51 . V_52 . V_55 = F_11 ( V_24 ) ;
V_40 -> V_51 . V_52 . V_56 = 0 ;
V_40 -> V_57 . V_10 = F_11 ( V_13 ) ;
V_40 -> V_51 . V_58 . V_59 . V_60 =
F_11 ( V_9 ) ;
V_40 -> V_51 . V_58 . V_59 . V_58 . V_61 . V_62 . V_55 =
V_40 -> V_51 . V_52 . V_55 ;
V_40 -> V_51 . V_58 . V_59 . V_58 . V_61 . V_62 . V_32 =
F_11 ( V_32 ) ;
V_40 -> V_51 . V_58 . V_59 . V_58 . V_61 . V_62 . V_41 =
F_11 ( V_41 ) ;
F_12 ( & V_34 , & V_40 -> V_51 , sizeof( V_40 -> V_51 ) ) ;
V_37 [ V_45 ++ ] = & V_34 ;
F_12 ( & V_35 , V_47 , V_32 ) ;
V_37 [ V_45 ++ ] = & V_35 ;
F_12 ( & V_36 , & V_40 -> V_57 , sizeof( V_40 -> V_57 ) ) ;
V_37 [ V_45 + V_46 ++ ] = & V_36 ;
V_44 = F_13 ( V_40 -> V_63 , V_37 , V_45 ,
V_46 , V_40 , V_48 ) ;
if ( V_44 < 0 ) {
F_14 ( & V_40 -> V_50 ) ;
F_15 ( V_47 ) ;
return V_44 ;
}
F_16 ( V_40 -> V_63 ) ;
while ( ! F_17 ( V_40 -> V_63 , & V_38 ) &&
! F_18 ( V_40 -> V_63 ) )
F_19 () ;
if ( F_20 ( V_40 -> V_57 . V_10 ) != V_11 ) {
F_14 ( & V_40 -> V_50 ) ;
F_7 ( L_2 ,
F_20 ( V_40 -> V_57 . V_10 ) ) ;
F_15 ( V_47 ) ;
return - V_14 ;
}
if ( V_33 )
V_30 -> V_64 . V_65 =
F_21 ( V_40 -> V_57 . V_65 ) ;
else
V_30 -> V_66 . V_65 =
F_21 ( V_40 -> V_57 . V_65 ) ;
F_14 ( & V_40 -> V_50 ) ;
F_15 ( V_47 ) ;
return 0 ;
}
static int F_22 (
struct V_29 * V_30 ,
int V_33 )
{
struct V_19 V_34 , V_67 , * V_37 [ 2 ] ;
unsigned int V_38 ;
struct V_68 * V_69 ;
struct V_39 * V_40 = V_30 -> V_40 ;
int V_44 ;
unsigned int V_45 = 0 , V_46 = 0 ;
F_10 ( & V_40 -> V_50 ) ;
V_40 -> V_70 . V_10 = V_13 ;
V_40 -> V_51 . V_52 . V_53 =
F_11 ( V_71 ) ;
V_40 -> V_51 . V_52 . V_56 = 0 ;
V_69 = & V_40 -> V_51 . V_58 . V_69 ;
if ( V_33 )
V_69 -> V_65 =
F_23 ( V_30 -> V_64 . V_65 ) ;
else
V_69 -> V_65 =
F_23 ( V_30 -> V_66 . V_65 ) ;
F_12 ( & V_34 , & V_40 -> V_51 , sizeof( V_40 -> V_51 ) ) ;
V_37 [ V_45 ++ ] = & V_34 ;
F_12 ( & V_67 , & V_40 -> V_70 . V_10 ,
sizeof( V_40 -> V_70 . V_10 ) ) ;
V_37 [ V_45 + V_46 ++ ] = & V_67 ;
V_44 = F_13 ( V_40 -> V_63 , V_37 , V_45 ,
V_46 , V_40 , V_48 ) ;
if ( V_44 < 0 ) {
F_14 ( & V_40 -> V_50 ) ;
return V_44 ;
}
F_16 ( V_40 -> V_63 ) ;
while ( ! F_17 ( V_40 -> V_63 , & V_38 ) &&
! F_18 ( V_40 -> V_63 ) )
F_19 () ;
if ( V_40 -> V_70 . V_10 != V_11 ) {
F_14 ( & V_40 -> V_50 ) ;
F_7 ( L_3 ,
V_40 -> V_70 . V_10 ,
V_69 -> V_65 ) ;
return - V_14 ;
}
F_14 ( & V_40 -> V_50 ) ;
return 0 ;
}
static int F_24 (
struct V_29 * V_30 ,
const T_3 * V_31 , unsigned int V_32 )
{
T_2 V_24 ;
int V_72 ;
struct V_39 * V_40 = V_30 -> V_40 ;
if ( V_32 > V_40 -> V_73 ) {
F_7 ( L_4 ) ;
goto V_74;
}
if ( F_6 ( V_32 , & V_24 ) )
goto V_74;
V_72 = F_8 ( V_30 ,
V_24 , V_31 , V_32 , 1 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_8 ( V_30 ,
V_24 , V_31 , V_32 , 0 ) ;
if ( V_72 ) {
F_22 ( V_30 , 1 ) ;
return V_72 ;
}
return 0 ;
V_74:
F_25 ( V_30 -> V_75 , V_76 ) ;
return - V_14 ;
}
static int F_26 ( struct V_77 * V_75 ,
const T_3 * V_31 ,
unsigned int V_32 )
{
struct V_29 * V_30 = F_27 ( V_75 ) ;
int V_72 ;
if ( ! V_30 -> V_40 ) {
int V_78 = F_28 () ;
struct V_39 * V_40 =
F_29 ( V_78 ) ;
if ( ! V_40 ) {
F_7 ( L_5 ) ;
return - V_79 ;
}
V_30 -> V_40 = V_40 ;
} else {
F_22 ( V_30 , 1 ) ;
F_22 ( V_30 , 0 ) ;
}
V_72 = F_24 ( V_30 , V_31 , V_32 ) ;
if ( V_72 ) {
F_30 ( V_30 -> V_40 ) ;
V_30 -> V_40 = NULL ;
return V_72 ;
}
return 0 ;
}
static int
F_31 ( struct V_4 * V_5 ,
struct V_7 * V_80 ,
struct V_81 * V_82 )
{
struct V_77 * V_75 = F_32 ( V_80 ) ;
struct V_29 * V_30 = V_5 -> V_83 ;
struct V_1 * V_2 = & V_5 -> V_6 ;
unsigned int V_84 = F_33 ( V_75 ) ;
struct V_39 * V_40 = V_30 -> V_40 ;
struct V_85 * V_86 ;
int V_87 , V_88 ;
int V_44 ;
unsigned long V_89 ;
struct V_19 V_34 , V_90 , V_67 , * * V_37 ;
int V_91 ;
T_1 V_92 ;
unsigned int V_45 = 0 , V_46 = 0 ;
int V_93 ;
T_3 * V_94 ;
V_87 = F_34 ( V_80 -> V_95 , V_80 -> V_96 ) ;
V_88 = F_35 ( V_80 -> V_97 ) ;
F_36 ( L_6 ,
V_87 , V_88 ) ;
V_93 = V_87 + V_88 + 3 ;
V_37 = F_37 ( V_93 * sizeof( * V_37 ) , V_48 ,
F_38 ( & V_40 -> V_98 -> V_99 ) ) ;
if ( ! V_37 )
return - V_49 ;
V_86 = F_37 ( sizeof( * V_86 ) , V_48 ,
F_38 ( & V_40 -> V_98 -> V_99 ) ) ;
if ( ! V_86 ) {
F_39 ( V_37 ) ;
return - V_49 ;
}
V_2 -> V_86 = V_86 ;
V_5 -> type = V_9 ;
if ( V_5 -> V_33 ) {
V_86 -> V_52 . V_65 =
F_23 ( V_30 -> V_64 . V_65 ) ;
V_86 -> V_52 . V_53 =
F_11 ( V_100 ) ;
} else {
V_86 -> V_52 . V_65 =
F_23 ( V_30 -> V_66 . V_65 ) ;
V_86 -> V_52 . V_53 =
F_11 ( V_101 ) ;
}
V_86 -> V_58 . V_102 . V_60 = F_11 ( V_9 ) ;
V_86 -> V_58 . V_102 . V_58 . V_61 . V_62 . V_103 = F_11 ( V_84 ) ;
V_86 -> V_58 . V_102 . V_58 . V_61 . V_62 . V_104 =
F_11 ( V_80 -> V_96 ) ;
V_92 = F_4 ( V_80 -> V_97 ) ;
if ( F_40 ( V_92 > V_105 ) ) {
F_7 ( L_7 ) ;
V_44 = - V_14 ;
goto free;
}
F_36 ( L_8 ,
V_80 -> V_96 , V_92 ) ;
if ( F_40 ( V_80 -> V_96 + V_92 + V_84 +
sizeof( V_2 -> V_10 ) > V_40 -> V_106 ) ) {
F_7 ( L_9 ) ;
V_44 = - V_14 ;
goto free;
}
V_86 -> V_58 . V_102 . V_58 . V_61 . V_62 . V_107 =
F_11 ( ( T_2 ) V_92 ) ;
F_12 ( & V_34 , V_86 , sizeof( * V_86 ) ) ;
V_37 [ V_45 ++ ] = & V_34 ;
V_94 = F_37 ( V_84 , V_48 ,
F_38 ( & V_40 -> V_98 -> V_99 ) ) ;
if ( ! V_94 ) {
V_44 = - V_49 ;
goto free;
}
memcpy ( V_94 , V_80 -> V_108 , V_84 ) ;
F_12 ( & V_90 , V_94 , V_84 ) ;
V_37 [ V_45 ++ ] = & V_90 ;
V_5 -> V_94 = V_94 ;
for ( V_91 = 0 ; V_91 < V_87 ; V_91 ++ )
V_37 [ V_45 ++ ] = & V_80 -> V_95 [ V_91 ] ;
for ( V_91 = 0 ; V_91 < V_88 ; V_91 ++ )
V_37 [ V_45 + V_46 ++ ] = & V_80 -> V_97 [ V_91 ] ;
F_12 ( & V_67 , & V_2 -> V_10 , sizeof( V_2 -> V_10 ) ) ;
V_37 [ V_45 + V_46 ++ ] = & V_67 ;
V_2 -> V_37 = V_37 ;
F_41 ( & V_82 -> V_109 , V_89 ) ;
V_44 = F_13 ( V_82 -> V_110 , V_37 , V_45 ,
V_46 , V_2 , V_48 ) ;
F_16 ( V_82 -> V_110 ) ;
F_42 ( & V_82 -> V_109 , V_89 ) ;
if ( F_40 ( V_44 < 0 ) )
goto V_111;
return 0 ;
V_111:
F_15 ( V_94 ) ;
free:
F_15 ( V_86 ) ;
F_39 ( V_37 ) ;
return V_44 ;
}
static int F_43 ( struct V_7 * V_80 )
{
struct V_77 * V_112 = F_32 ( V_80 ) ;
struct V_29 * V_30 = F_27 ( V_112 ) ;
struct V_4 * V_5 =
F_44 ( V_80 ) ;
struct V_1 * V_2 = & V_5 -> V_6 ;
struct V_39 * V_40 = V_30 -> V_40 ;
struct V_81 * V_82 = & V_40 -> V_82 [ 0 ] ;
V_2 -> V_113 = V_82 ;
V_2 -> V_114 = F_1 ;
V_5 -> V_83 = V_30 ;
V_5 -> V_18 = V_80 ;
V_5 -> V_33 = true ;
return F_45 ( V_82 -> V_115 , V_80 ) ;
}
static int F_46 ( struct V_7 * V_80 )
{
struct V_77 * V_112 = F_32 ( V_80 ) ;
struct V_29 * V_30 = F_27 ( V_112 ) ;
struct V_4 * V_5 =
F_44 ( V_80 ) ;
struct V_1 * V_2 = & V_5 -> V_6 ;
struct V_39 * V_40 = V_30 -> V_40 ;
struct V_81 * V_82 = & V_40 -> V_82 [ 0 ] ;
V_2 -> V_113 = V_82 ;
V_2 -> V_114 = F_1 ;
V_5 -> V_83 = V_30 ;
V_5 -> V_18 = V_80 ;
V_5 -> V_33 = false ;
return F_45 ( V_82 -> V_115 , V_80 ) ;
}
static int F_47 ( struct V_116 * V_75 )
{
struct V_29 * V_30 = F_48 ( V_75 ) ;
V_75 -> V_117 . V_118 = sizeof( struct V_4 ) ;
V_30 -> V_75 = V_75 ;
return 0 ;
}
static void F_49 ( struct V_116 * V_75 )
{
struct V_29 * V_30 = F_48 ( V_75 ) ;
if ( ! V_30 -> V_40 )
return;
F_22 ( V_30 , 1 ) ;
F_22 ( V_30 , 0 ) ;
F_30 ( V_30 -> V_40 ) ;
V_30 -> V_40 = NULL ;
}
int F_50 (
struct V_119 * V_115 ,
struct V_7 * V_80 )
{
struct V_4 * V_5 =
F_44 ( V_80 ) ;
struct V_1 * V_2 = & V_5 -> V_6 ;
struct V_81 * V_82 = V_2 -> V_113 ;
int V_72 ;
V_72 = F_31 ( V_5 , V_80 , V_82 ) ;
if ( V_72 < 0 )
return V_72 ;
F_16 ( V_82 -> V_110 ) ;
return 0 ;
}
static void F_3 (
struct V_4 * V_5 ,
struct V_7 * V_80 ,
int V_44 )
{
F_51 ( V_5 -> V_6 . V_113 -> V_115 ,
V_80 , V_44 ) ;
F_15 ( V_5 -> V_94 ) ;
F_52 ( & V_5 -> V_6 ) ;
}
int F_53 ( void )
{
int V_72 = 0 ;
F_54 ( & V_120 ) ;
if ( ++ V_121 != 1 )
goto V_122;
V_72 = F_55 ( V_123 ,
F_56 ( V_123 ) ) ;
if ( V_72 )
V_121 -- ;
V_122:
F_57 ( & V_120 ) ;
return V_72 ;
}
void F_58 ( void )
{
F_54 ( & V_120 ) ;
if ( -- V_121 != 0 )
goto V_122;
F_59 ( V_123 ,
F_56 ( V_123 ) ) ;
V_122:
F_57 ( & V_120 ) ;
}
