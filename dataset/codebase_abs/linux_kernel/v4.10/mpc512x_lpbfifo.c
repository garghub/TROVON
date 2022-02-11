static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = NULL ;
unsigned long V_7 ;
T_2 V_8 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
if ( ! V_9 . V_11 )
goto V_12;
V_6 = V_9 . V_6 ;
if ( ! V_6 || V_6 -> V_13 == V_14 ) {
F_3 ( V_4 , L_1 ) ;
goto V_12;
}
V_8 = F_4 ( & V_9 . V_11 -> V_8 ) ;
if ( V_8 != V_15 ) {
F_3 ( V_4 , L_2 ) ;
F_5 ( & V_9 . V_11 -> V_16 ,
V_17 | V_18 ) ;
goto V_12;
}
F_5 ( & V_9 . V_11 -> V_8 , V_15 ) ;
V_9 . V_19 = false ;
if ( V_9 . V_20 )
goto V_12;
V_9 . V_6 = NULL ;
F_6 ( & V_9 . V_10 , V_7 ) ;
if ( V_6 -> V_21 )
V_6 -> V_21 ( V_6 ) ;
return V_22 ;
V_12:
F_6 ( & V_9 . V_10 , V_7 ) ;
return V_22 ;
}
static void F_7 ( void * V_2 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
enum V_23 V_13 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
if ( ! V_9 . V_11 ) {
F_6 ( & V_9 . V_10 , V_7 ) ;
return;
}
V_6 = V_9 . V_6 ;
if ( ! V_6 ) {
F_8 ( L_3 ) ;
F_6 ( & V_9 . V_10 , V_7 ) ;
return;
}
if ( V_6 -> V_13 == V_24 )
V_13 = V_25 ;
else
V_13 = V_26 ;
F_9 ( V_9 . V_27 -> V_3 -> V_4 ,
V_9 . V_28 , V_6 -> V_29 , V_13 ) ;
V_9 . V_20 = false ;
if ( ! V_9 . V_19 ) {
V_9 . V_6 = NULL ;
F_6 ( & V_9 . V_10 , V_7 ) ;
if ( V_6 -> V_21 )
V_6 -> V_21 ( V_6 ) ;
} else {
F_6 ( & V_9 . V_10 , V_7 ) ;
}
}
static int F_10 ( void )
{
T_2 V_30 ;
bool V_31 = false ;
T_2 V_32 = 32 ;
T_2 V_33 = 0 ;
T_3 V_34 ;
struct V_35 * V_36 = NULL ;
struct V_37 V_38 ;
enum V_23 V_13 ;
struct V_39 V_40 = {} ;
struct V_41 * V_42 = NULL ;
T_4 V_43 ;
int V_44 ;
if ( V_9 . V_6 -> V_29 == 0 || ! F_11 ( V_9 . V_6 -> V_29 , 4 ) )
return - V_45 ;
if ( V_9 . V_6 -> V_46 != V_47 ) {
V_32 = V_9 . V_6 -> V_46 ;
V_31 = true ;
}
while ( V_32 > 1 ) {
if ( F_11 ( V_9 . V_6 -> V_48 , F_12 ( V_32 , 0x8u ) ) &&
F_11 ( V_9 . V_6 -> V_29 , V_32 ) ) {
break;
}
if ( V_31 )
return - V_45 ;
V_32 >>= 1 ;
}
V_40 . V_49 = F_13 ( V_32 , 0x4u ) / 4 ;
V_40 . V_50 = F_13 ( V_32 , 0x4u ) / 4 ;
for ( V_34 = 0 ; V_34 < V_9 . V_51 ; V_34 ++ ) {
T_5 V_52 = V_9 . V_53 [ V_34 ] . V_54 ;
T_5 V_55 = V_52 + V_9 . V_53 [ V_34 ] . V_29 ;
T_5 V_56 = V_9 . V_6 -> V_48 ;
T_5 V_57 = V_56 + V_9 . V_6 -> V_29 ;
if ( V_56 >= V_52 && V_57 <= V_55 ) {
V_33 = V_9 . V_53 [ V_34 ] . V_58 ;
break;
}
}
if ( V_34 == V_9 . V_51 )
return - V_59 ;
V_36 = V_9 . V_27 -> V_3 ;
if ( V_9 . V_6 -> V_13 == V_24 ) {
V_13 = V_25 ;
V_40 . V_60 = V_61 ;
V_40 . V_62 = V_9 . V_63 +
F_14 ( struct V_64 , V_65 ) ;
} else {
V_13 = V_26 ;
V_40 . V_60 = V_66 ;
V_40 . V_67 = V_9 . V_63 +
F_14 ( struct V_64 , V_65 ) ;
}
V_40 . V_68 = V_69 ;
V_40 . V_70 = V_69 ;
if ( V_36 -> V_71 ( V_9 . V_27 , & V_40 ) ) {
V_44 = - V_45 ;
goto V_72;
}
F_15 ( & V_38 , 1 ) ;
F_16 ( & V_38 ) = F_17 ( V_36 -> V_4 ,
V_9 . V_6 -> V_73 , V_9 . V_6 -> V_29 , V_13 ) ;
if ( F_18 ( V_36 -> V_4 , F_16 ( & V_38 ) ) )
return - V_59 ;
V_9 . V_28 = F_16 ( & V_38 ) ;
F_19 ( & V_38 ) = V_9 . V_6 -> V_29 ;
V_42 = F_20 ( V_9 . V_27 , & V_38 ,
1 , V_40 . V_60 , 0 ) ;
if ( ! V_42 ) {
V_44 = - V_74 ;
goto V_72;
}
V_42 -> V_21 = F_7 ;
V_42 -> V_75 = NULL ;
F_5 ( & V_9 . V_11 -> V_16 ,
V_17 | V_18 ) ;
F_5 ( & V_9 . V_11 -> V_16 , 0x0 ) ;
F_5 ( & V_9 . V_11 -> V_76 , F_21 ( 0x7 ) ) ;
F_5 ( & V_9 . V_11 -> V_77 , F_22 ( 0x200 ) ) ;
F_5 ( & V_9 . V_11 -> V_78 , V_9 . V_6 -> V_48 ) ;
V_30 = F_23 ( V_33 ) ;
if ( V_9 . V_6 -> V_13 == V_14 )
V_30 |= V_79 | V_80 ;
if ( V_31 )
V_30 |= V_81 ;
V_30 |= F_24 ( V_32 ) ;
F_5 ( & V_9 . V_11 -> V_82 , V_30 ) ;
V_30 = V_83 | V_84 ;
if ( V_9 . V_6 -> V_13 == V_24 )
V_30 |= V_85 ;
else
V_9 . V_19 = false ;
F_5 ( & V_9 . V_11 -> V_16 , V_30 ) ;
V_30 = V_9 . V_6 -> V_29 | V_86 ;
F_5 ( & V_9 . V_11 -> V_87 , V_30 ) ;
V_43 = V_42 -> V_88 ( V_42 ) ;
if ( F_25 ( V_43 ) ) {
V_44 = - V_74 ;
goto V_89;
}
return 0 ;
V_89:
F_5 ( & V_9 . V_11 -> V_16 ,
V_17 | V_18 ) ;
V_72:
F_9 ( V_36 -> V_4 , F_16 ( & V_38 ) ,
V_9 . V_6 -> V_29 , V_13 ) ;
return V_44 ;
}
static int F_26 ( struct V_5 * V_6 )
{
int V_44 = 0 ;
if ( ! V_9 . V_11 )
return - V_90 ;
if ( V_9 . V_6 )
return - V_91 ;
V_9 . V_19 = true ;
V_9 . V_20 = true ;
V_9 . V_6 = V_6 ;
V_44 = F_10 () ;
if ( V_44 != 0 )
V_9 . V_6 = NULL ;
return V_44 ;
}
int F_27 ( struct V_5 * V_6 )
{
unsigned long V_7 ;
int V_44 = 0 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
V_44 = F_26 ( V_6 ) ;
F_6 ( & V_9 . V_10 , V_7 ) ;
return V_44 ;
}
static int F_28 ( struct V_3 * V_4 )
{
int V_44 = - V_90 ;
struct V_92 * V_93 ;
const T_2 * V_94 ;
const T_2 * V_95 ;
int V_96 ;
T_3 V_34 ;
V_93 = F_29 ( NULL , NULL , L_4 ) ;
if ( ! V_93 )
return V_44 ;
V_94 = F_30 ( V_93 , L_5 , NULL ) ;
V_95 = F_30 ( V_93 , L_6 , NULL ) ;
if ( V_94 == NULL || * V_94 != 2 ||
V_95 == NULL || * V_95 != 1 ) {
goto V_12;
}
V_96 = F_31 ( V_93 , L_7 ) ;
if ( V_96 <= 0 || V_96 % 4 != 0 )
goto V_12;
V_9 . V_51 = V_96 / 4 ;
V_9 . V_53 = F_32 ( V_4 , V_9 . V_51 ,
sizeof( struct V_97 ) , V_98 ) ;
if ( ! V_9 . V_53 )
goto V_12;
if ( F_33 ( V_93 , L_7 ,
( T_2 * ) V_9 . V_53 , V_96 ) != 0 ) {
goto V_12;
}
for ( V_34 = 0 ; V_34 < V_9 . V_51 ; V_34 ++ ) {
if ( V_9 . V_53 [ V_34 ] . V_99 != 0 )
goto V_12;
}
V_44 = 0 ;
V_12:
F_34 ( V_93 ) ;
return V_44 ;
}
static int F_35 ( struct V_100 * V_101 )
{
struct V_102 V_103 ;
int V_44 = 0 ;
memset ( & V_9 , 0 , sizeof( struct V_104 ) ) ;
F_36 ( & V_9 . V_10 ) ;
V_9 . V_27 = F_37 ( & V_101 -> V_4 , L_8 ) ;
if ( V_9 . V_27 == NULL )
return - V_105 ;
if ( F_38 ( V_101 -> V_4 . V_106 , 0 , & V_103 ) != 0 ) {
F_3 ( & V_101 -> V_4 , L_9 ) ;
V_44 = - V_90 ;
goto V_107;
}
V_9 . V_63 = V_103 . V_108 ;
V_9 . V_109 = F_39 ( & V_103 ) ;
if ( ! F_40 ( & V_101 -> V_4 , V_9 . V_63 ,
V_9 . V_109 , V_110 ) ) {
F_3 ( & V_101 -> V_4 , L_10 ) ;
V_44 = - V_91 ;
goto V_107;
}
V_9 . V_11 = F_41 ( & V_101 -> V_4 ,
V_9 . V_63 , V_9 . V_109 ) ;
if ( ! V_9 . V_11 ) {
F_3 ( & V_101 -> V_4 , L_11 ) ;
V_44 = - V_111 ;
goto V_107;
}
F_5 ( & V_9 . V_11 -> V_16 ,
V_17 | V_18 ) ;
if ( F_28 ( & V_101 -> V_4 ) != 0 ) {
F_3 ( & V_101 -> V_4 , L_12 ) ;
V_44 = - V_90 ;
goto V_107;
}
V_9 . V_1 = F_42 ( V_101 -> V_4 . V_106 , 0 ) ;
if ( ! V_9 . V_1 ) {
F_3 ( & V_101 -> V_4 , L_13 ) ;
V_44 = - V_90 ;
goto V_107;
}
if ( F_43 ( V_9 . V_1 , F_1 , 0 ,
V_110 , & V_101 -> V_4 ) != 0 ) {
F_3 ( & V_101 -> V_4 , L_14 ) ;
V_44 = - V_90 ;
goto V_112;
}
F_44 ( & V_101 -> V_4 , L_15 ) ;
return 0 ;
V_112:
F_45 ( V_9 . V_1 ) ;
V_107:
F_46 ( V_9 . V_27 ) ;
return V_44 ;
}
static int F_47 ( struct V_100 * V_101 )
{
unsigned long V_7 ;
struct V_35 * V_36 = V_9 . V_27 -> V_3 ;
struct V_64 T_6 * V_11 = NULL ;
F_2 ( & V_9 . V_10 , V_7 ) ;
V_11 = V_9 . V_11 ;
V_9 . V_11 = NULL ;
F_6 ( & V_9 . V_10 , V_7 ) ;
V_36 -> V_113 ( V_9 . V_27 ) ;
F_5 ( & V_11 -> V_16 , V_17 | V_18 ) ;
F_48 ( V_9 . V_1 , & V_101 -> V_4 ) ;
F_45 ( V_9 . V_1 ) ;
F_46 ( V_9 . V_27 ) ;
return 0 ;
}
