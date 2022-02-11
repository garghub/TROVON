static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
F_2 ( L_1 , V_6 ) ;
switch ( V_3 ) {
case V_7 :
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
memcpy ( V_4 , V_9 [ V_5 ] . V_10 ,
V_11 ) ;
V_4 += V_11 ;
}
break;
}
F_2 ( L_2 , V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
T_2 * V_16 ;
int V_5 ;
F_2 ( L_1 , V_6 ) ;
V_15 -> V_17 . V_18 ( V_15 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
V_16 = ( T_2 * ) V_15 + V_9 [ V_5 ] . V_19 ;
* V_4 ++ = * ( T_3 * ) V_16 ;
}
F_2 ( L_2 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_20 ;
F_2 ( L_1 , V_6 ) ;
switch ( V_3 ) {
case V_7 :
V_20 = V_8 ;
break;
default:
V_20 = - V_21 ;
}
F_2 ( L_2 , V_6 ) ;
return V_20 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
F_2 ( L_3 ) ;
V_23 -> V_24 = V_15 -> V_25 ;
V_23 -> V_26 = V_15 -> V_26 ;
V_23 -> V_27 = V_15 -> V_27 ;
F_2 ( L_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
int V_20 = 0 ;
F_2 ( L_5 ) ;
F_2 ( L_6 ,
V_23 -> V_24 , V_23 -> V_26 , V_23 -> V_27 ) ;
V_15 -> V_25 = V_23 -> V_24 ;
if ( V_23 -> V_24 ) {
V_29 -> V_30 |= V_31 ;
V_29 -> V_30 |= V_32 ;
} else {
V_29 -> V_30 &= ~ V_31 ;
V_29 -> V_30 &= ~ V_32 ;
V_15 -> V_26 = V_23 -> V_26 ;
V_15 -> V_27 = V_23 -> V_27 ;
}
if ( F_8 ( V_2 ) )
V_20 = F_9 ( V_29 ) ;
F_2 ( L_7 ) ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
int V_20 ;
F_2 ( L_8 ) ;
if ( ! V_15 -> V_29 )
return - V_35 ;
F_11 ( & V_15 -> V_36 ) ;
V_20 = F_12 ( V_15 -> V_29 , V_34 ) ;
V_34 -> V_37 = V_38 ;
F_13 ( & V_15 -> V_36 ) ;
F_2 ( L_9 ) ;
return V_20 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
T_1 V_39 ;
int V_20 ;
F_2 ( L_10 ) ;
if ( ! V_15 -> V_29 )
return - V_35 ;
F_11 ( & V_15 -> V_36 ) ;
V_39 = F_15 ( V_34 ) ;
V_20 = - V_40 ;
if ( V_34 -> V_41 != V_29 -> V_42 )
goto V_43;
if ( ( V_34 -> V_24 != V_44 ) &&
( V_34 -> V_24 != V_45 ) )
goto V_43;
if ( ( V_34 -> V_24 == V_45 ) &&
( ( ( V_39 != V_46 ) && ( V_39 != V_47 ) ) ||
( V_34 -> V_48 != V_49 ) ) )
goto V_43;
if ( V_34 -> V_24 == V_44 ) {
V_29 -> V_50 &= ~ V_51 ;
V_29 -> V_50 &= ~ V_52 ;
} else {
V_29 -> V_50 |= V_51 ;
V_29 -> V_50 |= V_52 ;
}
V_34 -> V_30 &= V_29 -> V_50 ;
if ( ( V_34 -> V_24 == V_44 ) && ! V_34 -> V_30 )
goto V_43;
V_20 = 0 ;
V_29 -> V_24 = V_34 -> V_24 ;
V_29 -> V_39 = V_39 ;
V_29 -> V_48 = V_34 -> V_48 ;
V_29 -> V_30 = V_34 -> V_30 ;
if ( V_34 -> V_24 == V_44 )
V_29 -> V_30 |= V_53 ;
else
V_29 -> V_30 &= ~ V_53 ;
if ( F_8 ( V_2 ) )
V_20 = F_9 ( V_29 ) ;
V_43:
F_13 ( & V_15 -> V_36 ) ;
F_2 ( L_11 ) ;
return V_20 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
F_17 ( V_55 -> V_56 , V_57 , sizeof( V_55 -> V_56 ) ) ;
F_17 ( V_55 -> V_58 , V_59 , sizeof( V_55 -> V_58 ) ) ;
F_17 ( V_55 -> V_60 , F_18 ( V_15 -> V_61 ) ,
sizeof( V_55 -> V_60 ) ) ;
snprintf ( V_55 -> V_62 , sizeof( V_55 -> V_62 ) , L_12 ,
F_19 ( V_15 , V_63 , V_64 ) ,
F_19 ( V_15 , V_63 , V_65 ) ,
F_19 ( V_15 , V_63 , V_66 ) ) ;
V_55 -> V_67 = V_8 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_70 * V_17 = & V_15 -> V_17 ;
unsigned int V_71 ;
F_2 ( L_13 ) ;
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
V_71 = V_15 -> V_72 ;
V_69 -> V_73 = V_17 -> V_74 ( V_15 , V_71 ) ;
V_69 -> V_75 = V_15 -> V_76 ;
V_69 -> V_77 = V_15 -> V_78 ;
V_69 -> V_79 = V_15 -> V_80 ;
F_2 ( L_14 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_70 * V_17 = & V_15 -> V_17 ;
unsigned int V_76 , V_72 , V_81 ;
unsigned int V_80 , V_78 ;
F_2 ( L_15 ) ;
if ( ( V_69 -> V_82 ) ||
( V_69 -> V_83 ) ||
( V_69 -> V_84 ) ||
( V_69 -> V_85 ) ||
( V_69 -> V_86 ) ||
( V_69 -> V_87 ) ||
( V_69 -> V_88 ) ||
( V_69 -> V_89 ) ||
( V_69 -> V_90 ) ||
( V_69 -> V_91 ) ||
( V_69 -> V_92 ) ||
( V_69 -> V_93 ) ||
( V_69 -> V_94 ) ||
( V_69 -> V_95 ) ||
( V_69 -> V_96 ) ||
( V_69 -> V_97 ) ||
( V_69 -> V_98 ) ||
( V_69 -> V_99 ) )
return - V_21 ;
V_76 = V_15 -> V_76 ;
if ( V_76 != V_69 -> V_75 && F_8 ( V_2 ) ) {
F_22 ( V_2 ,
L_16 ) ;
return - V_40 ;
}
V_72 = V_17 -> V_100 ( V_15 , V_69 -> V_73 ) ;
V_76 = V_69 -> V_75 ;
if ( V_69 -> V_73 && ! V_72 )
V_72 = 1 ;
if ( V_72 > V_101 ) {
V_81 = V_17 -> V_74 ( V_15 , V_101 ) ;
F_22 ( V_2 , L_17 ,
V_81 ) ;
return - V_40 ;
}
if ( V_76 > V_15 -> V_102 -> V_103 -> V_104 ) {
F_22 ( V_2 , L_18 ,
V_15 -> V_102 -> V_103 -> V_104 ) ;
return - V_40 ;
}
V_78 = V_69 -> V_77 ;
V_80 = V_69 -> V_79 ;
if ( V_80 > V_15 -> V_102 -> V_105 -> V_104 ) {
F_22 ( V_2 , L_19 ,
V_15 -> V_102 -> V_105 -> V_104 ) ;
return - V_40 ;
}
V_15 -> V_72 = V_72 ;
V_15 -> V_76 = V_76 ;
V_17 -> V_106 ( V_15 ) ;
V_15 -> V_78 = V_78 ;
V_15 -> V_80 = V_80 ;
V_17 -> V_107 ( V_15 ) ;
F_2 ( L_20 ) ;
return 0 ;
}
struct V_108 * F_23 ( void )
{
return (struct V_108 * ) & V_109 ;
}
