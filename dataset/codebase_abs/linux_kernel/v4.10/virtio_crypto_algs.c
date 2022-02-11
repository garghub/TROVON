static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
for ( V_3 = 0 ; V_2 ; V_2 = F_2 ( V_2 ) )
V_3 += V_2 -> V_4 ;
return V_3 ;
}
static int
F_3 ( int V_5 , T_2 * V_6 )
{
switch ( V_5 ) {
case V_7 :
case V_8 :
case V_9 :
* V_6 = V_10 ;
break;
default:
F_4 ( L_1 ,
V_5 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_5 (
struct V_12 * V_13 ,
T_2 V_6 , const T_3 * V_14 ,
unsigned int V_15 ,
int V_16 )
{
struct V_1 V_17 , V_18 , V_19 , * V_20 [ 3 ] ;
unsigned int V_21 ;
struct V_22 * V_23 = V_13 -> V_23 ;
int V_24 = V_16 ? V_25 : V_26 ;
int V_27 ;
unsigned int V_28 = 0 , V_29 = 0 ;
T_3 * V_30 = F_6 ( V_15 , V_31 ) ;
if ( ! V_30 )
return - V_32 ;
memcpy ( V_30 , V_14 , V_15 ) ;
F_7 ( & V_23 -> V_33 ) ;
V_23 -> V_34 . V_35 . V_36 =
F_8 ( V_37 ) ;
V_23 -> V_34 . V_35 . V_38 = F_8 ( V_6 ) ;
V_23 -> V_34 . V_35 . V_39 = 0 ;
V_23 -> V_40 . V_41 = F_8 ( V_42 ) ;
V_23 -> V_34 . V_43 . V_44 . V_45 =
F_8 ( V_46 ) ;
V_23 -> V_34 . V_43 . V_44 . V_43 . V_47 . V_48 . V_38 =
V_23 -> V_34 . V_35 . V_38 ;
V_23 -> V_34 . V_43 . V_44 . V_43 . V_47 . V_48 . V_15 =
F_8 ( V_15 ) ;
V_23 -> V_34 . V_43 . V_44 . V_43 . V_47 . V_48 . V_24 =
F_8 ( V_24 ) ;
F_9 ( & V_17 , & V_23 -> V_34 , sizeof( V_23 -> V_34 ) ) ;
V_20 [ V_28 ++ ] = & V_17 ;
F_9 ( & V_18 , V_30 , V_15 ) ;
V_20 [ V_28 ++ ] = & V_18 ;
F_9 ( & V_19 , & V_23 -> V_40 , sizeof( V_23 -> V_40 ) ) ;
V_20 [ V_28 + V_29 ++ ] = & V_19 ;
V_27 = F_10 ( V_23 -> V_49 , V_20 , V_28 ,
V_29 , V_23 , V_31 ) ;
if ( V_27 < 0 ) {
F_11 ( & V_23 -> V_33 ) ;
F_12 ( V_30 ) ;
return V_27 ;
}
F_13 ( V_23 -> V_49 ) ;
while ( ! F_14 ( V_23 -> V_49 , & V_21 ) &&
! F_15 ( V_23 -> V_49 ) )
F_16 () ;
if ( F_17 ( V_23 -> V_40 . V_41 ) != V_50 ) {
F_11 ( & V_23 -> V_33 ) ;
F_4 ( L_2 ,
F_17 ( V_23 -> V_40 . V_41 ) ) ;
F_12 ( V_30 ) ;
return - V_11 ;
}
if ( V_16 )
V_13 -> V_51 . V_52 =
F_18 ( V_23 -> V_40 . V_52 ) ;
else
V_13 -> V_53 . V_52 =
F_18 ( V_23 -> V_40 . V_52 ) ;
F_11 ( & V_23 -> V_33 ) ;
F_12 ( V_30 ) ;
return 0 ;
}
static int F_19 (
struct V_12 * V_13 ,
int V_16 )
{
struct V_1 V_17 , V_54 , * V_20 [ 2 ] ;
unsigned int V_21 ;
struct V_55 * V_56 ;
struct V_22 * V_23 = V_13 -> V_23 ;
int V_27 ;
unsigned int V_28 = 0 , V_29 = 0 ;
F_7 ( & V_23 -> V_33 ) ;
V_23 -> V_57 . V_41 = V_42 ;
V_23 -> V_34 . V_35 . V_36 =
F_8 ( V_58 ) ;
V_23 -> V_34 . V_35 . V_39 = 0 ;
V_56 = & V_23 -> V_34 . V_43 . V_56 ;
if ( V_16 )
V_56 -> V_52 =
F_20 ( V_13 -> V_51 . V_52 ) ;
else
V_56 -> V_52 =
F_20 ( V_13 -> V_53 . V_52 ) ;
F_9 ( & V_17 , & V_23 -> V_34 , sizeof( V_23 -> V_34 ) ) ;
V_20 [ V_28 ++ ] = & V_17 ;
F_9 ( & V_54 , & V_23 -> V_57 . V_41 ,
sizeof( V_23 -> V_57 . V_41 ) ) ;
V_20 [ V_28 + V_29 ++ ] = & V_54 ;
V_27 = F_10 ( V_23 -> V_49 , V_20 , V_28 ,
V_29 , V_23 , V_31 ) ;
if ( V_27 < 0 ) {
F_11 ( & V_23 -> V_33 ) ;
return V_27 ;
}
F_13 ( V_23 -> V_49 ) ;
while ( ! F_14 ( V_23 -> V_49 , & V_21 ) &&
! F_15 ( V_23 -> V_49 ) )
F_16 () ;
if ( V_23 -> V_57 . V_41 != V_50 ) {
F_11 ( & V_23 -> V_33 ) ;
F_4 ( L_3 ,
V_23 -> V_57 . V_41 ,
V_56 -> V_52 ) ;
return - V_11 ;
}
F_11 ( & V_23 -> V_33 ) ;
return 0 ;
}
static int F_21 (
struct V_12 * V_13 ,
const T_3 * V_14 , unsigned int V_15 )
{
T_2 V_6 ;
int V_59 ;
struct V_22 * V_23 = V_13 -> V_23 ;
if ( V_15 > V_23 -> V_60 ) {
F_4 ( L_4 ) ;
goto V_61;
}
if ( F_3 ( V_15 , & V_6 ) )
goto V_61;
V_59 = F_5 ( V_13 ,
V_6 , V_14 , V_15 , 1 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_5 ( V_13 ,
V_6 , V_14 , V_15 , 0 ) ;
if ( V_59 ) {
F_19 ( V_13 , 1 ) ;
return V_59 ;
}
return 0 ;
V_61:
F_22 ( V_13 -> V_62 , V_63 ) ;
return - V_11 ;
}
static int F_23 ( struct V_64 * V_62 ,
const T_3 * V_14 ,
unsigned int V_15 )
{
struct V_12 * V_13 = F_24 ( V_62 ) ;
int V_59 ;
if ( ! V_13 -> V_23 ) {
int V_65 = F_25 () ;
struct V_22 * V_23 =
F_26 ( V_65 ) ;
if ( ! V_23 ) {
F_4 ( L_5 ) ;
return - V_66 ;
}
V_13 -> V_23 = V_23 ;
} else {
F_19 ( V_13 , 1 ) ;
F_19 ( V_13 , 0 ) ;
}
V_59 = F_21 ( V_13 , V_14 , V_15 ) ;
if ( V_59 ) {
F_27 ( V_13 -> V_23 ) ;
V_13 -> V_23 = NULL ;
return V_59 ;
}
return 0 ;
}
static int
F_28 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 ,
T_4 V_24 )
{
struct V_64 * V_62 = F_29 ( V_70 ) ;
unsigned int V_73 = F_30 ( V_62 ) ;
struct V_12 * V_13 = V_68 -> V_74 ;
struct V_22 * V_23 = V_13 -> V_23 ;
struct V_75 * V_76 ;
int V_77 , V_78 ;
int V_27 ;
unsigned long V_79 ;
struct V_1 V_17 , V_80 , V_54 , * * V_20 ;
int V_81 ;
T_1 V_82 ;
unsigned int V_28 = 0 , V_29 = 0 ;
int V_83 ;
T_3 * V_84 ;
V_77 = F_31 ( V_70 -> V_85 , V_70 -> V_86 ) ;
V_78 = F_32 ( V_70 -> V_87 ) ;
F_33 ( L_6 ,
V_77 , V_78 ) ;
V_83 = V_77 + V_78 + 3 ;
V_20 = F_34 ( V_83 * sizeof( * V_20 ) , V_31 ,
F_35 ( & V_23 -> V_88 -> V_89 ) ) ;
if ( ! V_20 )
return - V_32 ;
V_76 = F_34 ( sizeof( * V_76 ) , V_31 ,
F_35 ( & V_23 -> V_88 -> V_89 ) ) ;
if ( ! V_76 ) {
F_36 ( V_20 ) ;
return - V_32 ;
}
V_68 -> V_76 = V_76 ;
V_68 -> type = V_46 ;
if ( V_24 ) {
V_76 -> V_35 . V_52 =
F_20 ( V_13 -> V_51 . V_52 ) ;
V_76 -> V_35 . V_36 =
F_8 ( V_90 ) ;
} else {
V_76 -> V_35 . V_52 =
F_20 ( V_13 -> V_53 . V_52 ) ;
V_76 -> V_35 . V_36 =
F_8 ( V_91 ) ;
}
V_76 -> V_43 . V_92 . V_45 = F_8 ( V_46 ) ;
V_76 -> V_43 . V_92 . V_43 . V_47 . V_48 . V_93 = F_8 ( V_73 ) ;
V_76 -> V_43 . V_92 . V_43 . V_47 . V_48 . V_94 =
F_8 ( V_70 -> V_86 ) ;
V_82 = F_1 ( V_70 -> V_87 ) ;
if ( F_37 ( V_82 > V_95 ) ) {
F_4 ( L_7 ) ;
V_27 = - V_11 ;
goto free;
}
F_33 ( L_8 ,
V_70 -> V_86 , V_82 ) ;
if ( F_37 ( V_70 -> V_86 + V_82 + V_73 +
sizeof( V_68 -> V_41 ) > V_23 -> V_96 ) ) {
F_4 ( L_9 ) ;
V_27 = - V_11 ;
goto free;
}
V_76 -> V_43 . V_92 . V_43 . V_47 . V_48 . V_97 =
F_8 ( ( T_2 ) V_82 ) ;
F_9 ( & V_17 , V_76 , sizeof( * V_76 ) ) ;
V_20 [ V_28 ++ ] = & V_17 ;
V_84 = F_34 ( V_73 , V_31 ,
F_35 ( & V_23 -> V_88 -> V_89 ) ) ;
if ( ! V_84 ) {
V_27 = - V_32 ;
goto free;
}
memcpy ( V_84 , V_70 -> V_98 , V_73 ) ;
F_9 ( & V_80 , V_84 , V_73 ) ;
V_20 [ V_28 ++ ] = & V_80 ;
V_68 -> V_84 = V_84 ;
for ( V_81 = 0 ; V_81 < V_77 ; V_81 ++ )
V_20 [ V_28 ++ ] = & V_70 -> V_85 [ V_81 ] ;
for ( V_81 = 0 ; V_81 < V_78 ; V_81 ++ )
V_20 [ V_28 + V_29 ++ ] = & V_70 -> V_87 [ V_81 ] ;
F_9 ( & V_54 , & V_68 -> V_41 , sizeof( V_68 -> V_41 ) ) ;
V_20 [ V_28 + V_29 ++ ] = & V_54 ;
V_68 -> V_20 = V_20 ;
F_38 ( & V_72 -> V_99 , V_79 ) ;
V_27 = F_10 ( V_72 -> V_100 , V_20 , V_28 ,
V_29 , V_68 , V_31 ) ;
F_13 ( V_72 -> V_100 ) ;
F_39 ( & V_72 -> V_99 , V_79 ) ;
if ( F_37 ( V_27 < 0 ) )
goto V_101;
return 0 ;
V_101:
F_12 ( V_84 ) ;
free:
F_12 ( V_76 ) ;
F_36 ( V_20 ) ;
return V_27 ;
}
static int F_40 ( struct V_69 * V_70 )
{
struct V_64 * V_102 = F_29 ( V_70 ) ;
struct V_12 * V_13 = F_24 ( V_102 ) ;
struct V_67 * V_68 = F_41 ( V_70 ) ;
struct V_22 * V_23 = V_13 -> V_23 ;
int V_59 ;
struct V_71 * V_72 = & V_23 -> V_72 [ 0 ] ;
V_68 -> V_74 = V_13 ;
V_68 -> V_103 = V_70 ;
V_59 = F_28 ( V_68 , V_70 , V_72 , 1 ) ;
if ( V_59 < 0 ) {
F_4 ( L_10 ) ;
return V_59 ;
}
return - V_104 ;
}
static int F_42 ( struct V_69 * V_70 )
{
struct V_64 * V_102 = F_29 ( V_70 ) ;
struct V_12 * V_13 = F_24 ( V_102 ) ;
struct V_67 * V_68 = F_41 ( V_70 ) ;
struct V_22 * V_23 = V_13 -> V_23 ;
int V_59 ;
struct V_71 * V_72 = & V_23 -> V_72 [ 0 ] ;
V_68 -> V_74 = V_13 ;
V_68 -> V_103 = V_70 ;
V_59 = F_28 ( V_68 , V_70 , V_72 , 0 ) ;
if ( V_59 < 0 ) {
F_4 ( L_11 ) ;
return V_59 ;
}
return - V_104 ;
}
static int F_43 ( struct V_105 * V_62 )
{
struct V_12 * V_13 = F_44 ( V_62 ) ;
V_62 -> V_106 . V_107 = sizeof( struct V_67 ) ;
V_13 -> V_62 = V_62 ;
return 0 ;
}
static void F_45 ( struct V_105 * V_62 )
{
struct V_12 * V_13 = F_44 ( V_62 ) ;
if ( ! V_13 -> V_23 )
return;
F_19 ( V_13 , 1 ) ;
F_19 ( V_13 , 0 ) ;
F_27 ( V_13 -> V_23 ) ;
V_13 -> V_23 = NULL ;
}
int F_46 ( void )
{
int V_59 = 0 ;
F_47 ( & V_108 ) ;
if ( ++ V_109 != 1 )
goto V_110;
V_59 = F_48 ( V_111 ,
F_49 ( V_111 ) ) ;
if ( V_59 )
V_109 -- ;
V_110:
F_50 ( & V_108 ) ;
return V_59 ;
}
void F_51 ( void )
{
F_47 ( & V_108 ) ;
if ( -- V_109 != 0 )
goto V_110;
F_52 ( V_111 ,
F_49 ( V_111 ) ) ;
V_110:
F_50 ( & V_108 ) ;
}
