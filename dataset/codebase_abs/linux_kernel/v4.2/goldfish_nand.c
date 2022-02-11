static T_1 F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_2 V_5 , T_1 V_6 ,
void * V_7 , T_1 * V_8 )
{
T_1 V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_13 ;
unsigned char T_3 * V_15 = V_11 -> V_15 ;
if ( V_14 == NULL )
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
T_1 V_40 ;
if ( V_39 + V_6 > V_2 -> V_41 )
goto V_42;
V_40 = F_9 ( V_39 , V_2 -> V_43 ) ;
if ( V_40 )
goto V_42;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( V_6 % V_2 -> V_43 )
goto V_42;
V_6 = V_6 / V_2 -> V_43 * ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( F_3 ( V_2 , V_16 , V_39 , V_6 , NULL ) != V_6 ) {
F_10 ( L_1 ,
V_39 , V_6 , V_2 -> V_41 , V_2 -> V_45 ) ;
return - V_46 ;
}
V_38 -> V_47 = V_48 ;
F_11 ( V_38 ) ;
return 0 ;
V_42:
F_10 ( L_2 ,
V_39 , V_6 , V_2 -> V_41 , V_2 -> V_45 ) ;
return - V_49 ;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_39 ,
struct V_50 * V_51 )
{
T_1 V_40 ;
if ( V_39 + V_51 -> V_6 > V_2 -> V_41 )
goto V_42;
if ( V_51 -> V_52 && V_51 -> V_6 && V_51 -> V_6 != V_2 -> V_43 )
goto V_42;
if ( V_51 -> V_53 + V_51 -> V_54 > V_2 -> V_44 )
goto V_42;
V_40 = F_9 ( V_39 , V_2 -> V_43 ) ;
if ( V_40 )
goto V_42;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( V_51 -> V_52 )
V_51 -> V_55 = F_3 ( V_2 , V_18 , V_39 ,
V_51 -> V_6 , V_51 -> V_52 ) ;
V_39 += V_2 -> V_43 + V_51 -> V_54 ;
if ( V_51 -> V_56 )
V_51 -> V_57 = F_3 ( V_2 , V_18 , V_39 ,
V_51 -> V_53 , V_51 -> V_56 ) ;
return 0 ;
V_42:
F_10 ( L_3 ,
V_39 , V_51 -> V_6 , V_51 -> V_53 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_49 ;
}
static int F_13 ( struct V_1 * V_2 , T_4 V_39 ,
struct V_50 * V_51 )
{
T_1 V_40 ;
if ( V_39 + V_51 -> V_6 > V_2 -> V_41 )
goto V_42;
if ( V_51 -> V_6 && V_51 -> V_6 != V_2 -> V_43 )
goto V_42;
if ( V_51 -> V_53 + V_51 -> V_54 > V_2 -> V_44 )
goto V_42;
V_40 = F_9 ( V_39 , V_2 -> V_43 ) ;
if ( V_40 )
goto V_42;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( V_51 -> V_52 )
V_51 -> V_55 = F_3 ( V_2 , V_20 , V_39 ,
V_51 -> V_6 , V_51 -> V_52 ) ;
V_39 += V_2 -> V_43 + V_51 -> V_54 ;
if ( V_51 -> V_56 )
V_51 -> V_57 = F_3 ( V_2 , V_20 , V_39 ,
V_51 -> V_53 , V_51 -> V_56 ) ;
return 0 ;
V_42:
F_10 ( L_4 ,
V_39 , V_51 -> V_6 , V_51 -> V_53 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_49 ;
}
static int F_14 ( struct V_1 * V_2 , T_4 V_58 , T_5 V_6 ,
T_5 * V_55 , T_6 * V_59 )
{
T_1 V_40 ;
if ( V_58 + V_6 > V_2 -> V_41 )
goto V_42;
V_40 = F_9 ( V_58 , V_2 -> V_43 ) ;
if ( V_40 )
goto V_42;
V_58 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
* V_55 = F_3 ( V_2 , V_18 , V_58 , V_6 , V_59 ) ;
return 0 ;
V_42:
F_10 ( L_5 ,
V_58 , V_6 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_49 ;
}
static int F_15 ( struct V_1 * V_2 , T_4 V_60 , T_5 V_6 ,
T_5 * V_55 , const T_6 * V_59 )
{
T_1 V_40 ;
if ( V_60 + V_6 > V_2 -> V_41 )
goto V_42;
V_40 = F_9 ( V_60 , V_2 -> V_43 ) ;
if ( V_40 )
goto V_42;
V_60 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
* V_55 = F_3 ( V_2 , V_20 , V_60 , V_6 , ( void * ) V_59 ) ;
return 0 ;
V_42:
F_10 ( L_6 ,
V_60 , V_6 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_49 ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_39 )
{
T_1 V_40 ;
if ( V_39 >= V_2 -> V_41 )
goto V_42;
V_40 = F_9 ( V_39 , V_2 -> V_45 ) ;
if ( V_40 )
goto V_42;
V_39 *= V_2 -> V_45 / V_2 -> V_43 ;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
return F_3 ( V_2 , V_61 , V_39 , 0 , NULL ) ;
V_42:
F_10 ( L_7 ,
V_39 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_49 ;
}
static int F_17 ( struct V_1 * V_2 , T_4 V_39 )
{
T_1 V_40 ;
if ( V_39 >= V_2 -> V_41 )
goto V_42;
V_40 = F_9 ( V_39 , V_2 -> V_45 ) ;
if ( V_40 )
goto V_42;
V_39 *= V_2 -> V_45 / V_2 -> V_43 ;
V_39 *= ( V_2 -> V_43 + V_2 -> V_44 ) ;
if ( F_3 ( V_2 , V_62 , V_39 , 0 , NULL ) != 1 )
return - V_46 ;
return 0 ;
V_42:
F_10 ( L_8 ,
V_39 , V_2 -> V_41 , V_2 -> V_43 ) ;
return - V_49 ;
}
static int F_18 ( struct V_63 * V_64 ,
struct V_10 * V_11 )
{
T_2 V_65 ;
unsigned char T_3 * V_15 = V_11 -> V_15 ;
V_11 -> V_13 = F_19 ( & V_64 -> V_22 ,
sizeof( struct V_13 ) , V_66 ) ;
if ( ! V_11 -> V_13 )
return - 1 ;
V_65 = F_20 ( V_11 -> V_13 ) ;
F_2 ( ( T_1 ) ( V_65 >> 32 ) , V_15 + V_67 ) ;
F_2 ( ( T_1 ) V_65 , V_15 + V_68 ) ;
return 0 ;
}
static int F_21 ( struct V_63 * V_64 ,
struct V_10 * V_11 , int V_69 )
{
T_1 V_70 ;
T_1 V_28 ;
T_1 V_71 ;
unsigned char T_3 * V_15 = V_11 -> V_15 ;
struct V_1 * V_2 = & V_11 -> V_2 [ V_69 ] ;
char * V_72 ;
F_4 ( & V_11 -> V_29 ) ;
F_2 ( V_69 , V_15 + V_30 ) ;
V_71 = F_6 ( V_15 + V_73 ) ;
V_70 = F_6 ( V_15 + V_74 ) ;
V_2 -> V_43 = F_6 ( V_15 + V_75 ) ;
V_2 -> V_41 = F_6 ( V_15 + V_76 ) ;
V_2 -> V_41 |= ( T_2 ) F_6 ( V_15 + V_77 ) << 32 ;
V_2 -> V_44 = F_6 ( V_15 + V_78 ) ;
V_2 -> V_79 = V_2 -> V_44 ;
V_2 -> V_45 = F_6 ( V_15 + V_80 ) /
( V_2 -> V_43 + V_2 -> V_44 ) * V_2 -> V_43 ;
F_9 ( V_2 -> V_41 , V_2 -> V_43 + V_2 -> V_44 ) ;
V_2 -> V_41 *= V_2 -> V_43 ;
F_22 ( & V_64 -> V_22 ,
L_9 ,
V_69 , V_2 -> V_41 , V_2 -> V_43 ,
V_2 -> V_44 , V_2 -> V_45 ) ;
F_7 ( & V_11 -> V_29 ) ;
V_2 -> V_12 = V_11 ;
V_72 = F_19 ( & V_64 -> V_22 , V_70 + 1 , V_66 ) ;
if ( ! V_72 )
return - V_81 ;
V_2 -> V_72 = V_72 ;
V_28 = F_3 ( V_2 , V_82 , 0 , V_70 ,
V_72 ) ;
if ( V_28 != V_70 ) {
F_23 ( & V_64 -> V_22 ,
L_10 ,
V_28 , V_70 ) ;
return - V_83 ;
}
( ( char * ) V_2 -> V_72 ) [ V_70 ] = '\0' ;
V_2 -> type = V_84 ;
V_2 -> V_71 = V_85 ;
if ( V_71 & V_86 )
V_2 -> V_71 &= ~ V_87 ;
if ( V_71 & V_88 )
F_18 ( V_64 , V_11 ) ;
V_2 -> V_89 = V_90 ;
V_2 -> V_91 = F_8 ;
V_2 -> V_92 = F_14 ;
V_2 -> V_93 = F_15 ;
V_2 -> V_94 = F_12 ;
V_2 -> V_95 = F_13 ;
V_2 -> V_96 = F_16 ;
V_2 -> V_97 = F_17 ;
if ( F_24 ( V_2 , NULL , 0 ) )
return - V_46 ;
return 0 ;
}
static int F_25 ( struct V_63 * V_64 )
{
T_1 V_98 ;
int V_99 ;
int V_100 ;
T_1 V_101 ;
T_1 V_102 ;
struct V_103 * V_104 ;
struct V_10 * V_11 ;
unsigned char T_3 * V_15 ;
V_104 = F_26 ( V_64 , V_105 , 0 ) ;
if ( V_104 == NULL )
return - V_83 ;
V_15 = F_27 ( & V_64 -> V_22 , V_104 -> V_106 , V_107 ) ;
if ( ! V_15 )
return - V_81 ;
V_102 = F_6 ( V_15 + V_108 ) ;
if ( V_102 != V_109 ) {
F_23 ( & V_64 -> V_22 ,
L_11 ,
V_102 , V_109 ) ;
return - V_83 ;
}
V_98 = F_6 ( V_15 + V_110 ) ;
if ( V_98 == 0 )
return - V_83 ;
V_11 = F_19 ( & V_64 -> V_22 , sizeof( * V_11 ) +
sizeof( struct V_1 ) * V_98 , V_66 ) ;
if ( ! V_11 )
return - V_81 ;
F_28 ( & V_11 -> V_29 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_111 = V_98 ;
F_29 ( V_64 , V_11 ) ;
V_101 = 0 ;
for ( V_99 = 0 ; V_99 < V_98 ; V_99 ++ ) {
V_100 = F_21 ( V_64 , V_11 , V_99 ) ;
if ( V_100 == 0 )
V_101 ++ ;
}
if ( V_101 == 0 )
return - V_83 ;
return 0 ;
}
static int F_30 ( struct V_63 * V_64 )
{
struct V_10 * V_11 = F_31 ( V_64 ) ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_11 -> V_111 ; V_99 ++ ) {
if ( V_11 -> V_2 [ V_99 ] . V_72 )
F_32 ( & V_11 -> V_2 [ V_99 ] ) ;
}
return 0 ;
}
