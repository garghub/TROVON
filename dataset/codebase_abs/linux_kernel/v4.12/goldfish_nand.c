static T_1 F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_2 V_5 , T_1 V_6 ,
void * V_7 , T_1 * V_8 )
{
T_1 V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_13 ;
unsigned char T_3 * V_15 = V_11 -> V_15 ;
if ( ! V_14 )
return - 1 ;
switch ( V_4 ) {
case V_16 :
V_9 = V_17 ;
break;
case V_18 :
V_9 = V_19 ;
break;
case V_20 :
V_9 = V_21 ;
break;
default:
return - 1 ;
}
V_14 -> V_22 = V_2 - V_11 -> V_2 ;
V_14 -> V_23 = ( T_1 ) ( V_5 >> 32 ) ;
V_14 -> V_24 = ( T_1 ) V_5 ;
V_14 -> V_25 = V_6 ;
V_14 -> V_26 = ( unsigned long ) V_7 ;
F_2 ( V_9 , V_15 + V_27 ) ;
* V_8 = V_14 -> V_28 ;
return 0 ;
}
static T_1 F_3 ( struct V_1 * V_2 , enum V_3 V_4 ,
T_2 V_5 , T_1 V_6 , void * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
T_1 V_8 ;
unsigned char T_3 * V_15 = V_11 -> V_15 ;
F_4 ( & V_11 -> V_29 ) ;
if ( F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 , & V_8 ) ) {
F_2 ( V_2 - V_11 -> V_2 , V_15 + V_30 ) ;
F_2 ( ( T_1 ) ( V_5 >> 32 ) , V_15 + V_31 ) ;
F_2 ( ( T_1 ) V_5 , V_15 + V_32 ) ;
F_2 ( V_6 , V_15 + V_33 ) ;
F_5 ( V_7 , V_15 + V_34 , V_15 + V_35 ) ;
F_2 ( V_4 , V_15 + V_27 ) ;
V_8 = F_6 ( V_15 + V_36 ) ;
}
F_7 ( & V_11 -> V_29 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
T_4 V_39 = V_38 -> V_5 ;
T_1 V_6 = V_38 -> V_6 ;
T_5 V_40 ;
if ( V_39 + V_6 > V_2 -> V_41 )
goto V_42;
V_39 = F_9 ( V_39 , V_2 -> V_43 , & V_40 ) ;
if ( V_40 )
goto V_42;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( V_6 % V_2 -> V_43 )
goto V_42;
V_6 = V_6 / V_2 -> V_43 * ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( F_3 ( V_2 , V_16 , V_39 , V_6 , NULL ) != V_6 ) {
F_10 ( L_1 ,
V_45 , V_39 , V_6 , V_2 -> V_41 , V_2 -> V_46 ) ;
return - V_47 ;
}
V_38 -> V_48 = V_49 ;
F_11 ( V_38 ) ;
return 0 ;
V_42:
F_10 ( L_2 ,
V_45 , V_39 , V_6 , V_2 -> V_41 , V_2 -> V_46 ) ;
return - V_50 ;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_39 ,
struct V_51 * V_52 )
{
T_5 V_40 ;
if ( V_39 + V_52 -> V_6 > V_2 -> V_41 )
goto V_42;
if ( V_52 -> V_53 && V_52 -> V_6 && V_52 -> V_6 != V_2 -> V_43 )
goto V_42;
if ( V_52 -> V_54 + V_52 -> V_55 > V_2 -> V_44 )
goto V_42;
V_39 = F_9 ( V_39 , V_2 -> V_43 , & V_40 ) ;
if ( V_40 )
goto V_42;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( V_52 -> V_53 )
V_52 -> V_56 = F_3 ( V_2 , V_18 , V_39 ,
V_52 -> V_6 , V_52 -> V_53 ) ;
V_39 += V_2 -> V_43 + V_52 -> V_55 ;
if ( V_52 -> V_57 )
V_52 -> V_58 = F_3 ( V_2 , V_18 , V_39 ,
V_52 -> V_54 , V_52 -> V_57 ) ;
return 0 ;
V_42:
F_10 ( L_3 ,
V_39 , V_52 -> V_6 , V_52 -> V_54 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_50 ;
}
static int F_13 ( struct V_1 * V_2 , T_4 V_39 ,
struct V_51 * V_52 )
{
T_5 V_40 ;
if ( V_39 + V_52 -> V_6 > V_2 -> V_41 )
goto V_42;
if ( V_52 -> V_6 && V_52 -> V_6 != V_2 -> V_43 )
goto V_42;
if ( V_52 -> V_54 + V_52 -> V_55 > V_2 -> V_44 )
goto V_42;
V_39 = F_9 ( V_39 , V_2 -> V_43 , & V_40 ) ;
if ( V_40 )
goto V_42;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( V_52 -> V_53 )
V_52 -> V_56 = F_3 ( V_2 , V_20 , V_39 ,
V_52 -> V_6 , V_52 -> V_53 ) ;
V_39 += V_2 -> V_43 + V_52 -> V_55 ;
if ( V_52 -> V_57 )
V_52 -> V_58 = F_3 ( V_2 , V_20 , V_39 ,
V_52 -> V_54 , V_52 -> V_57 ) ;
return 0 ;
V_42:
F_10 ( L_4 ,
V_39 , V_52 -> V_6 , V_52 -> V_54 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_50 ;
}
static int F_14 ( struct V_1 * V_2 , T_4 V_59 , T_6 V_6 ,
T_6 * V_56 , T_7 * V_60 )
{
T_5 V_40 ;
if ( V_59 + V_6 > V_2 -> V_41 )
goto V_42;
V_59 = F_9 ( V_59 , V_2 -> V_43 , & V_40 ) ;
if ( V_40 )
goto V_42;
V_59 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
* V_56 = F_3 ( V_2 , V_18 , V_59 , V_6 , V_60 ) ;
return 0 ;
V_42:
F_10 ( L_5 ,
V_59 , V_6 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_50 ;
}
static int F_15 ( struct V_1 * V_2 , T_4 V_61 , T_6 V_6 ,
T_6 * V_56 , const T_7 * V_60 )
{
T_5 V_40 ;
if ( V_61 + V_6 > V_2 -> V_41 )
goto V_42;
V_61 = F_9 ( V_61 , V_2 -> V_43 , & V_40 ) ;
if ( V_40 )
goto V_42;
V_61 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
* V_56 = F_3 ( V_2 , V_20 , V_61 , V_6 , ( void * ) V_60 ) ;
return 0 ;
V_42:
F_10 ( L_6 ,
V_61 , V_6 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_50 ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_39 )
{
T_5 V_40 ;
if ( V_39 >= V_2 -> V_41 )
goto V_42;
V_39 = F_9 ( V_39 , V_2 -> V_43 , & V_40 ) ;
if ( V_40 )
goto V_42;
V_39 *= V_2 -> V_46 / V_2 -> V_43 ;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
return F_3 ( V_2 , V_62 , V_39 , 0 , NULL ) ;
V_42:
F_10 ( L_7 ,
V_45 , V_39 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_50 ;
}
static int F_17 ( struct V_1 * V_2 , T_4 V_39 )
{
T_5 V_40 ;
if ( V_39 >= V_2 -> V_41 )
goto V_42;
V_39 = F_9 ( V_39 , V_2 -> V_43 , & V_40 ) ;
if ( V_40 )
goto V_42;
V_39 *= V_2 -> V_46 / V_2 -> V_43 ;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( F_3 ( V_2 , V_63 , V_39 , 0 , NULL ) != 1 )
return - V_47 ;
return 0 ;
V_42:
F_10 ( L_7 ,
V_45 , V_39 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_50 ;
}
static int F_18 ( struct V_64 * V_65 ,
struct V_10 * V_11 )
{
T_8 V_66 ;
unsigned char T_3 * V_15 = V_11 -> V_15 ;
V_11 -> V_13 = F_19 ( & V_65 -> V_22 ,
sizeof( struct V_13 ) ,
& V_66 , V_67 ) ;
if ( ! V_11 -> V_13 ) {
F_20 ( & V_65 -> V_22 , L_8 ) ;
return - V_68 ;
}
F_2 ( ( T_1 ) ( ( T_2 ) V_66 >> 32 ) , V_15 + V_69 ) ;
F_2 ( ( T_1 ) V_66 , V_15 + V_70 ) ;
return 0 ;
}
static int F_21 ( struct V_64 * V_65 ,
struct V_10 * V_11 , int V_71 )
{
T_1 V_72 ;
T_1 V_28 ;
T_1 V_73 ;
unsigned char T_3 * V_15 = V_11 -> V_15 ;
struct V_1 * V_2 = & V_11 -> V_2 [ V_71 ] ;
char * V_74 ;
F_4 ( & V_11 -> V_29 ) ;
F_2 ( V_71 , V_15 + V_30 ) ;
V_73 = F_6 ( V_15 + V_75 ) ;
V_72 = F_6 ( V_15 + V_76 ) ;
V_2 -> V_43 = F_6 ( V_15 + V_77 ) ;
V_2 -> V_41 = F_6 ( V_15 + V_78 ) ;
V_2 -> V_41 |= ( T_2 ) F_6 ( V_15 + V_79 ) << 32 ;
V_2 -> V_44 = F_6 ( V_15 + V_80 ) ;
V_2 -> V_81 = V_2 -> V_44 ;
V_2 -> V_46 = F_6 ( V_15 + V_82 ) /
( V_2 -> V_43 + V_2 -> V_44 ) * V_2 -> V_43 ;
V_2 -> V_41 = F_22 ( V_2 -> V_41 , V_2 -> V_43 + V_2 -> V_44 ) ;
V_2 -> V_41 *= V_2 -> V_43 ;
F_23 ( & V_65 -> V_22 ,
L_9 ,
V_71 , V_2 -> V_41 , V_2 -> V_43 ,
V_2 -> V_44 , V_2 -> V_46 ) ;
F_7 ( & V_11 -> V_29 ) ;
V_2 -> V_12 = V_11 ;
V_74 = F_24 ( & V_65 -> V_22 , V_72 + 1 , V_67 ) ;
if ( ! V_74 )
return - V_68 ;
V_2 -> V_74 = V_74 ;
V_28 = F_3 ( V_2 , V_83 , 0 , V_72 ,
V_74 ) ;
if ( V_28 != V_72 ) {
F_20 ( & V_65 -> V_22 ,
L_10 ,
V_28 , V_72 ) ;
return - V_84 ;
}
( ( char * ) V_2 -> V_74 ) [ V_72 ] = '\0' ;
V_2 -> type = V_85 ;
V_2 -> V_73 = V_86 ;
if ( V_73 & V_87 )
V_2 -> V_73 &= ~ V_88 ;
if ( V_73 & V_89 )
F_18 ( V_65 , V_11 ) ;
V_2 -> V_90 = V_91 ;
V_2 -> V_92 = F_8 ;
V_2 -> V_93 = F_14 ;
V_2 -> V_94 = F_15 ;
V_2 -> V_95 = F_12 ;
V_2 -> V_96 = F_13 ;
V_2 -> V_97 = F_16 ;
V_2 -> V_98 = F_17 ;
if ( F_25 ( V_2 , NULL , 0 ) )
return - V_47 ;
return 0 ;
}
static int F_26 ( struct V_64 * V_65 )
{
T_1 V_99 ;
int V_100 ;
int V_101 ;
T_1 V_102 ;
T_1 V_103 ;
struct V_104 * V_105 ;
struct V_10 * V_11 ;
unsigned char T_3 * V_15 ;
V_105 = F_27 ( V_65 , V_106 , 0 ) ;
if ( ! V_105 )
return - V_84 ;
V_15 = F_28 ( & V_65 -> V_22 , V_105 -> V_107 , V_108 ) ;
if ( ! V_15 )
return - V_68 ;
V_103 = F_6 ( V_15 + V_109 ) ;
if ( V_103 != V_110 ) {
F_20 ( & V_65 -> V_22 ,
L_11 ,
V_103 , V_110 ) ;
return - V_84 ;
}
V_99 = F_6 ( V_15 + V_111 ) ;
if ( V_99 == 0 )
return - V_84 ;
V_11 = F_24 ( & V_65 -> V_22 , sizeof( * V_11 ) +
sizeof( struct V_1 ) * V_99 , V_67 ) ;
if ( ! V_11 )
return - V_68 ;
F_29 ( & V_11 -> V_29 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_112 = V_99 ;
F_30 ( V_65 , V_11 ) ;
V_102 = 0 ;
for ( V_100 = 0 ; V_100 < V_99 ; V_100 ++ ) {
V_101 = F_21 ( V_65 , V_11 , V_100 ) ;
if ( V_101 == 0 )
V_102 ++ ;
}
if ( V_102 == 0 )
return - V_84 ;
return 0 ;
}
static int F_31 ( struct V_64 * V_65 )
{
struct V_10 * V_11 = F_32 ( V_65 ) ;
int V_100 ;
for ( V_100 = 0 ; V_100 < V_11 -> V_112 ; V_100 ++ ) {
if ( V_11 -> V_2 [ V_100 ] . V_74 )
F_33 ( & V_11 -> V_2 [ V_100 ] ) ;
}
return 0 ;
}
