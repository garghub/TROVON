static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_2 . V_13 ;
return snprintf ( V_5 , V_14 , L_1 , V_12 -> V_15 () ) ;
}
static int F_3 ( struct V_6 * V_7 , int V_16 )
{
struct V_11 * V_12 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_17 ;
V_17 = F_4 ( F_5 ( V_7 -> V_18 ) , V_7 -> V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_12 = V_9 -> V_2 . V_13 ;
V_7 -> V_19 = V_20 ;
if ( V_12 -> V_21 )
V_12 -> V_21 ( V_16 ) ;
if ( V_16 ) {
V_7 -> V_22 = V_23 ;
F_6 ( & V_9 -> V_2 , L_2 ) ;
} else {
V_7 -> V_22 = V_24 ;
F_6 ( & V_9 -> V_2 , L_3 ) ;
}
F_7 ( 10000 , 15000 ) ;
return 0 ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
struct V_8 * V_9 = V_7 -> V_10 ;
V_12 = V_9 -> V_2 . V_13 ;
if ( V_12 -> V_25 )
V_12 -> V_25 () ;
V_7 -> V_22 = V_26 ;
F_6 ( & V_9 -> V_2 , L_4 ) ;
F_9 ( V_27 ) ;
V_7 -> V_19 = V_20 ;
F_10 ( F_5 ( V_7 -> V_18 ) , V_7 -> V_18 ) ;
}
static int F_11 ( T_2 * V_5 , int V_28 )
{
T_2 V_29 ;
T_3 V_30 ;
V_29 = V_5 [ 0 ] + 1 ;
if ( V_29 < 4 || V_29 != V_28 || V_29 > V_31 ) {
F_12 ( V_32
L_5 , V_29 , V_28 ) ;
F_13 ( V_33 , L_6 , V_34 ,
16 , 2 , V_5 , V_28 , false ) ;
return - V_35 ;
}
V_30 = F_14 ( 0xffff , V_5 , V_29 - 2 ) ;
V_30 = ~ V_30 ;
if ( V_5 [ V_29 - 2 ] != ( V_30 & 0xff ) || V_5 [ V_29 - 1 ] != ( V_30 >> 8 ) ) {
F_12 ( V_32 L_7 ,
V_30 , V_5 [ V_29 - 1 ] , V_5 [ V_29 - 2 ] ) ;
F_13 ( V_33 , L_6 , V_34 ,
16 , 2 , V_5 , V_28 , false ) ;
return - V_35 ;
}
return 0 ;
}
static int F_15 ( struct V_8 * V_9 , T_2 * V_5 , int V_29 )
{
int V_17 ;
if ( V_29 < 4 || V_29 != ( V_5 [ 0 ] + 1 ) ) {
F_16 ( & V_9 -> V_2 , L_8 ,
V_36 , V_29 ) ;
return - V_37 ;
}
if ( F_11 ( V_5 , V_29 ) )
return - V_37 ;
F_7 ( 3000 , 6000 ) ;
V_17 = F_17 ( V_9 , V_5 , V_29 ) ;
F_6 ( & V_9 -> V_2 , L_9 , V_17 ) ;
if ( V_17 == - V_38 ) {
F_7 ( 6000 , 10000 ) ;
V_17 = F_17 ( V_9 , V_5 , V_29 ) ;
F_6 ( & V_9 -> V_2 , L_10 , V_17 ) ;
}
if ( V_17 != V_29 )
return - V_38 ;
return V_17 ;
}
static int F_18 ( struct V_8 * V_9 , T_2 * V_5 , int V_28 )
{
int V_17 ;
T_2 V_29 ;
V_17 = F_19 ( V_9 , & V_29 , 1 ) ;
F_6 ( & V_9 -> V_2 , L_11 , V_17 ) ;
if ( V_17 != 1 )
return - V_38 ;
if ( V_29 < V_39 )
V_29 = V_39 ;
else if ( V_29 > ( V_31 - 1 ) )
V_29 = V_31 - 1 ;
if ( 1 + V_29 > V_28 )
return - V_40 ;
V_5 [ 0 ] = V_29 ;
V_17 = F_19 ( V_9 , V_5 + 1 , V_29 ) ;
F_6 ( & V_9 -> V_2 , L_12 , V_17 ) ;
if ( V_17 != V_29 )
return - V_38 ;
F_7 ( 3000 , 6000 ) ;
return V_17 + 1 ;
}
static int F_20 ( struct V_8 * V_9 , T_2 * V_5 , int V_29 )
{
int V_17 ;
F_6 ( & V_9 -> V_2 , L_13 , V_36 ) ;
if ( V_29 < V_41 ||
( V_41 + ( V_5 [ 1 ] << 8 ) + V_5 [ 2 ] ) != V_29 )
return - V_37 ;
V_17 = F_17 ( V_9 , V_5 , V_29 ) ;
F_6 ( & V_9 -> V_2 , L_14 , V_17 ) ;
if ( V_17 == - V_38 ) {
F_7 ( 6000 , 10000 ) ;
V_17 = F_17 ( V_9 , V_5 , V_29 ) ;
F_6 ( & V_9 -> V_2 , L_15 , V_17 ) ;
}
if ( V_17 != V_29 )
return - V_38 ;
return V_17 ;
}
static int F_21 ( struct V_8 * V_9 , T_2 * V_5 , int V_28 )
{
int V_17 , V_29 ;
if ( V_28 < V_41 )
return - V_37 ;
V_17 = F_19 ( V_9 , V_5 , V_41 ) ;
F_6 ( & V_9 -> V_2 , L_16 , V_17 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 < V_41 )
return - V_37 ;
V_29 = ( V_5 [ 1 ] << 8 ) + V_5 [ 2 ] ;
if ( V_29 == 0 )
return V_17 ;
if ( V_29 > V_28 - V_41 )
return - V_40 ;
V_17 = F_19 ( V_9 , V_5 + V_41 , V_29 ) ;
F_6 ( & V_9 -> V_2 , L_17 , V_17 ) ;
if ( V_17 != V_29 )
return - V_37 ;
return V_17 + V_41 ;
}
static T_4 F_22 ( int V_42 , void * V_43 )
{
struct V_6 * V_7 = V_43 ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_23 ( ! V_7 ) ;
F_23 ( V_42 != V_7 -> V_10 -> V_42 ) ;
F_6 ( & V_9 -> V_2 , L_18 ) ;
F_24 ( & V_7 -> V_44 ) ;
V_7 -> V_19 = V_45 ;
F_25 ( & V_7 -> V_44 ) ;
F_26 ( & V_7 -> V_46 ) ;
return V_47 ;
}
static enum V_48 F_27 ( struct V_6 * V_7 )
{
enum V_48 V_42 ;
F_24 ( & V_7 -> V_44 ) ;
V_42 = V_7 -> V_19 ;
F_25 ( & V_7 -> V_44 ) ;
return V_42 ;
}
static T_1 F_28 ( struct V_49 * V_49 , char T_5 * V_5 ,
T_6 V_50 , T_7 * V_51 )
{
struct V_6 * V_7 = F_29 ( V_49 -> V_52 ,
struct V_6 , V_53 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
enum V_48 V_42 ;
T_6 V_29 ;
int V_17 = 0 ;
F_6 ( & V_9 -> V_2 , L_19 , V_36 ,
V_7 , V_50 ) ;
F_24 ( & V_7 -> V_54 ) ;
if ( V_7 -> V_22 == V_26 ) {
V_17 = - V_55 ;
goto V_56;
}
V_42 = F_27 ( V_7 ) ;
if ( V_42 == V_20 ) {
if ( V_49 -> V_57 & V_58 ) {
V_17 = - V_59 ;
goto V_56;
}
if ( F_30 ( V_7 -> V_46 ,
( V_7 -> V_19 == V_45 ) ) ) {
V_17 = - V_60 ;
goto V_56;
}
}
if ( V_7 -> V_22 == V_23 ) {
V_29 = F_31 ( V_50 , V_7 -> V_28 ) ;
F_24 ( & V_7 -> V_44 ) ;
V_17 = F_21 ( V_7 -> V_10 , V_7 -> V_5 , V_29 ) ;
V_7 -> V_19 = V_20 ;
F_25 ( & V_7 -> V_44 ) ;
if ( V_17 < 0 ) {
F_16 ( & V_7 -> V_10 -> V_2 , L_20 , V_17 ) ;
goto V_56;
}
F_13 ( V_33 , L_21 , V_34 ,
16 , 2 , V_7 -> V_5 , V_17 , false ) ;
* V_51 += V_17 ;
if ( F_32 ( V_5 , V_7 -> V_5 , V_17 ) ) {
V_17 = - V_61 ;
goto V_56;
}
} else {
V_29 = F_31 ( V_50 , V_7 -> V_28 ) ;
F_24 ( & V_7 -> V_44 ) ;
V_17 = F_18 ( V_7 -> V_10 , V_7 -> V_5 , V_29 ) ;
V_7 -> V_19 = V_20 ;
F_25 ( & V_7 -> V_44 ) ;
if ( V_17 < 0 ) {
F_16 ( & V_7 -> V_10 -> V_2 , L_22 , V_17 ) ;
goto V_56;
}
F_13 ( V_33 , L_23 , V_34 ,
16 , 2 , V_7 -> V_5 , V_17 , false ) ;
* V_51 += V_17 ;
if ( F_32 ( V_5 , V_7 -> V_5 , V_17 ) ) {
V_17 = - V_61 ;
goto V_56;
}
}
V_56:
F_25 ( & V_7 -> V_54 ) ;
return V_17 ;
}
static unsigned int F_33 ( struct V_49 * V_49 , T_8 * V_62 )
{
struct V_6 * V_7 = F_29 ( V_49 -> V_52 ,
struct V_6 , V_53 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_17 = 0 ;
F_6 ( & V_9 -> V_2 , L_24 , V_36 , V_7 ) ;
F_24 ( & V_7 -> V_54 ) ;
if ( V_7 -> V_22 == V_26 ) {
V_17 = - V_55 ;
goto V_56;
}
F_34 ( V_49 , & V_7 -> V_46 , V_62 ) ;
if ( F_27 ( V_7 ) == V_45 ) {
V_17 = V_63 | V_64 ;
goto V_56;
}
V_56:
F_25 ( & V_7 -> V_54 ) ;
return V_17 ;
}
static T_1 F_35 ( struct V_49 * V_49 , const char T_5 * V_5 ,
T_6 V_50 , T_7 * V_65 )
{
struct V_6 * V_7 = F_29 ( V_49 -> V_52 ,
struct V_6 , V_53 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_29 ;
int V_17 ;
F_6 ( & V_9 -> V_2 , L_25 , V_36 ,
V_7 , V_50 ) ;
F_24 ( & V_7 -> V_54 ) ;
if ( V_7 -> V_22 == V_26 ) {
V_17 = - V_55 ;
goto V_56;
}
if ( V_7 -> V_22 == V_23 ) {
T_6 V_66 ;
if ( V_50 < V_41 ) {
V_17 = - V_37 ;
goto V_56;
}
V_29 = F_31 ( V_50 , V_7 -> V_28 ) ;
if ( F_36 ( V_7 -> V_5 , V_5 , V_29 ) ) {
V_17 = - V_61 ;
goto V_56;
}
F_13 ( V_33 , L_26 , V_34 ,
16 , 2 , V_7 -> V_5 , V_29 , false ) ;
V_66 = V_41 + ( V_7 -> V_5 [ 1 ] << 8 ) +
V_7 -> V_5 [ 2 ] ;
if ( V_29 > V_66 )
V_29 = V_66 ;
V_17 = F_20 ( V_7 -> V_10 , V_7 -> V_5 , V_29 ) ;
} else {
if ( V_50 < V_67 ) {
V_17 = - V_37 ;
goto V_56;
}
V_29 = F_31 ( V_50 , V_7 -> V_28 ) ;
if ( F_36 ( V_7 -> V_5 , V_5 , V_29 ) ) {
V_17 = - V_61 ;
goto V_56;
}
F_13 ( V_33 , L_27 , V_34 ,
16 , 2 , V_7 -> V_5 , V_29 , false ) ;
if ( V_29 > ( V_7 -> V_5 [ 0 ] + 1 ) )
V_29 = V_7 -> V_5 [ 0 ] + 1 ;
V_17 = F_15 ( V_7 -> V_10 , V_7 -> V_5 , V_29 ) ;
}
V_56:
F_25 ( & V_7 -> V_54 ) ;
return V_17 ;
}
static long F_37 ( struct V_49 * V_49 , unsigned int V_68 , unsigned long V_69 )
{
struct V_6 * V_7 = F_29 ( V_49 -> V_52 ,
struct V_6 , V_53 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 ;
unsigned int V_70 ;
int V_17 = 0 ;
F_6 ( & V_9 -> V_2 , L_28 , V_36 , V_7 , V_68 ) ;
F_24 ( & V_7 -> V_54 ) ;
if ( V_7 -> V_22 == V_26 ) {
V_17 = - V_55 ;
goto V_56;
}
V_12 = V_7 -> V_10 -> V_2 . V_13 ;
switch ( V_68 ) {
case V_71 :
F_6 ( & V_9 -> V_2 , L_29 , V_36 ) ;
V_70 = ( V_7 -> V_22 == V_23 ) ;
if ( F_32 ( ( void T_5 * ) V_69 , & V_70 , sizeof( V_70 ) ) ) {
V_17 = - V_61 ;
goto V_56;
}
break;
case V_72 :
F_6 ( & V_9 -> V_2 , L_30 , V_36 ) ;
if ( F_36 ( & V_70 , ( void T_5 * ) V_69 , sizeof( V_70 ) ) ) {
V_17 = - V_61 ;
goto V_56;
}
if ( V_70 ) {
if ( V_7 -> V_22 == V_23 )
break;
F_8 ( V_7 ) ;
V_17 = F_3 ( V_7 , V_73 ) ;
if ( V_17 < 0 )
goto V_56;
} else {
if ( V_7 -> V_22 == V_24 )
break;
F_8 ( V_7 ) ;
V_17 = F_3 ( V_7 , V_74 ) ;
if ( V_17 < 0 )
goto V_56;
}
V_49 -> V_75 = V_7 -> V_76 ;
break;
case V_77 :
F_6 ( & V_9 -> V_2 , L_31 , V_36 ) ;
V_17 = - V_78 ;
break;
default:
F_16 ( & V_9 -> V_2 , L_32 , V_68 ) ;
V_17 = - V_78 ;
break;
}
V_56:
F_25 ( & V_7 -> V_54 ) ;
return V_17 ;
}
static int F_38 ( struct V_79 * V_79 , struct V_49 * V_49 )
{
struct V_6 * V_7 = F_29 ( V_49 -> V_52 ,
struct V_6 , V_53 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_17 = 0 ;
F_6 ( & V_9 -> V_2 , L_33 , V_36 ,
V_7 , V_7 -> V_10 ) ;
F_24 ( & V_7 -> V_54 ) ;
if ( V_7 -> V_22 != V_26 ) {
V_17 = - V_80 ;
goto V_56;
}
V_49 -> V_75 = V_7 -> V_76 ;
V_17 = F_3 ( V_7 , V_74 ) ;
V_56:
F_25 ( & V_7 -> V_54 ) ;
return V_17 ;
}
static int F_39 ( struct V_79 * V_79 , struct V_49 * V_49 )
{
struct V_6 * V_7 = F_29 ( V_49 -> V_52 ,
struct V_6 , V_53 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_6 ( & V_9 -> V_2 , L_33 ,
V_36 , V_7 , V_7 -> V_10 ) ;
F_24 ( & V_7 -> V_54 ) ;
F_8 ( V_7 ) ;
F_25 ( & V_7 -> V_54 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_41 ( V_2 ) ;
struct V_6 * V_7 ;
int V_17 = 0 ;
F_42 ( & V_9 -> V_2 , L_34 , V_36 , V_9 ) ;
V_7 = F_43 ( V_9 ) ;
F_42 ( & V_9 -> V_2 , L_33 , V_36 ,
V_7 , V_9 ) ;
F_24 ( & V_7 -> V_54 ) ;
switch ( V_7 -> V_22 ) {
case V_23 :
V_17 = - V_35 ;
break;
case V_24 :
break;
case V_26 :
break;
} ;
F_25 ( & V_7 -> V_54 ) ;
return V_17 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_41 ( V_2 ) ;
struct V_6 * V_7 = F_43 ( V_9 ) ;
int V_17 = 0 ;
F_6 ( & V_9 -> V_2 , L_33 , V_36 ,
V_7 , V_9 ) ;
F_24 ( & V_7 -> V_54 ) ;
switch ( V_7 -> V_22 ) {
case V_24 :
break;
case V_26 :
break;
case V_23 :
break;
} ;
F_25 ( & V_7 -> V_54 ) ;
return V_17 ;
}
static int T_9 F_45 ( struct V_8 * V_9 ,
const struct V_81 * V_82 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
int V_17 = 0 ;
F_6 ( & V_9 -> V_2 , L_13 , V_36 ) ;
F_6 ( & V_9 -> V_2 , L_35 , V_9 -> V_42 ) ;
V_7 = F_46 ( sizeof( struct V_6 ) , V_83 ) ;
if ( ! V_7 ) {
F_16 ( & V_9 -> V_2 ,
L_36 ) ;
V_17 = - V_84 ;
goto V_85;
}
V_7 -> V_28 = F_47 ( V_31 , V_86 ) ;
V_7 -> V_5 = F_46 ( V_7 -> V_28 , V_83 ) ;
if ( ! V_7 -> V_5 ) {
F_16 ( & V_9 -> V_2 ,
L_37 ) ;
V_17 = - V_84 ;
goto V_87;
}
V_7 -> V_18 [ 0 ] . V_88 = V_89 ;
V_7 -> V_18 [ 1 ] . V_88 = V_90 ;
V_7 -> V_18 [ 2 ] . V_88 = V_91 ;
V_17 = F_48 ( & V_9 -> V_2 , F_5 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
if ( V_17 < 0 )
goto V_92;
V_7 -> V_10 = V_9 ;
V_7 -> V_22 = V_26 ;
V_7 -> V_19 = V_20 ;
F_49 ( & V_7 -> V_44 ) ;
F_49 ( & V_7 -> V_54 ) ;
F_50 ( & V_7 -> V_46 ) ;
F_51 ( V_9 , V_7 ) ;
V_12 = V_9 -> V_2 . V_13 ;
if ( ! V_12 ) {
F_16 ( & V_9 -> V_2 , L_38 ) ;
V_17 = - V_37 ;
goto V_93;
}
if ( ! V_12 -> V_94 ) {
F_16 ( & V_9 -> V_2 , L_39 ) ;
V_17 = - V_37 ;
goto V_93;
}
V_17 = V_12 -> V_94 ( V_9 ) ;
if ( V_17 ) {
F_16 ( & V_9 -> V_2 , L_40 ) ;
goto V_93;
}
V_17 = F_52 ( V_9 -> V_42 , NULL , F_22 ,
V_95 , V_32 ,
V_7 ) ;
if ( V_17 < 0 ) {
F_16 ( & V_9 -> V_2 , L_41 ) ;
goto V_96;
}
if ( V_12 -> V_15 ) {
V_17 = F_53 ( & V_9 -> V_2 , & V_97 ) ;
if ( V_17 ) {
F_16 ( & V_9 -> V_2 ,
L_42 , V_17 ) ;
goto V_98;
}
}
V_7 -> V_53 . V_99 = V_100 ;
V_7 -> V_53 . V_101 = V_32 ;
V_7 -> V_53 . V_102 = & V_103 ;
V_7 -> V_53 . V_104 = & V_9 -> V_2 ;
V_17 = F_54 ( & V_7 -> V_53 ) ;
if ( V_17 < 0 ) {
F_16 ( & V_9 -> V_2 , L_43 ) ;
goto V_105;
}
F_6 ( & V_9 -> V_2 , L_44 ,
V_36 , V_7 , V_12 , V_9 ) ;
return 0 ;
V_105:
if ( V_12 -> V_15 )
F_55 ( & V_9 -> V_2 , & V_97 ) ;
V_98:
F_56 ( V_9 -> V_42 , V_7 ) ;
V_96:
if ( V_12 -> V_106 )
V_12 -> V_106 () ;
V_93:
F_57 ( F_5 ( V_7 -> V_18 ) , V_7 -> V_18 ) ;
V_92:
F_58 ( V_7 -> V_5 ) ;
V_87:
F_58 ( V_7 ) ;
V_85:
return V_17 ;
}
static T_10 int F_59 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_43 ( V_9 ) ;
struct V_11 * V_12 = V_9 -> V_2 . V_13 ;
F_6 ( & V_9 -> V_2 , L_13 , V_36 ) ;
F_60 ( & V_7 -> V_53 ) ;
if ( V_12 -> V_15 )
F_55 ( & V_9 -> V_2 , & V_97 ) ;
if ( V_7 -> V_22 != V_26 ) {
if ( V_12 -> V_25 )
V_12 -> V_25 () ;
V_7 -> V_19 = V_20 ;
}
F_56 ( V_9 -> V_42 , V_7 ) ;
if ( V_12 -> V_106 )
V_12 -> V_106 () ;
F_57 ( F_5 ( V_7 -> V_18 ) , V_7 -> V_18 ) ;
F_58 ( V_7 -> V_5 ) ;
F_58 ( V_7 ) ;
return 0 ;
}
static int T_11 F_61 ( void )
{
int V_17 ;
F_62 ( V_107 L_45 , V_36 ) ;
V_17 = F_63 ( & V_108 ) ;
if ( V_17 ) {
F_12 ( V_32 L_46 ) ;
return V_17 ;
}
return 0 ;
}
static void T_12 F_64 ( void )
{
F_65 ( & V_108 ) ;
F_66 ( V_107 L_47 ) ;
}
