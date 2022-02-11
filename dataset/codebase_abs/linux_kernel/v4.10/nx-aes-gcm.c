static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_7 * V_9 = V_6 -> V_9 ;
F_3 ( V_6 , V_10 ) ;
switch ( V_4 ) {
case V_11 :
F_4 ( V_8 , V_12 ) ;
F_4 ( V_9 , V_12 ) ;
V_6 -> V_13 = & V_6 -> V_14 [ V_15 ] ;
break;
case V_16 :
F_4 ( V_8 , V_17 ) ;
F_4 ( V_9 , V_17 ) ;
V_6 -> V_13 = & V_6 -> V_14 [ V_18 ] ;
break;
case V_19 :
F_4 ( V_8 , V_20 ) ;
F_4 ( V_9 , V_20 ) ;
V_6 -> V_13 = & V_6 -> V_14 [ V_21 ] ;
break;
default:
return - V_22 ;
}
V_8 -> V_23 . V_24 . V_25 = V_26 ;
memcpy ( V_8 -> V_23 . V_27 . V_28 , V_3 , V_4 ) ;
V_9 -> V_23 . V_24 . V_25 = V_29 ;
memcpy ( V_9 -> V_23 . V_30 . V_28 , V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char * V_31 = V_6 -> V_32 . V_33 . V_31 ;
int V_34 ;
if ( V_4 < 4 )
return - V_22 ;
V_4 -= 4 ;
V_34 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_34 )
goto V_35;
memcpy ( V_31 , V_3 + V_4 , 4 ) ;
V_35:
return V_34 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
switch ( V_36 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_22 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_37 * V_38 ,
T_1 * V_35 ,
unsigned int V_39 )
{
int V_34 ;
struct V_7 * V_9 = V_6 -> V_9 ;
struct V_40 V_41 ;
struct V_42 * V_42 = V_6 -> V_43 ;
unsigned int V_44 = V_39 ;
unsigned int V_45 = 0 , V_46 ;
unsigned int V_47 ;
if ( V_44 <= V_48 ) {
F_8 ( & V_41 , V_38 -> V_49 ) ;
F_9 ( V_35 , & V_41 , V_44 , V_50 ) ;
F_10 ( & V_41 , V_50 , 0 ) ;
return 0 ;
}
F_11 ( V_9 ) &= ~ V_51 ;
V_47 = F_12 ( V_52 , V_53 . V_54 . V_47 / sizeof( struct V_42 ) ,
V_6 -> V_13 -> V_55 ) ;
V_47 = F_12 ( V_52 , V_47 ,
V_6 -> V_13 -> V_56 / V_57 ) ;
do {
V_46 = F_12 ( V_52 , V_44 - V_45 ,
V_6 -> V_13 -> V_56 ) ;
V_46 = F_12 ( V_52 , V_46 ,
V_57 * ( V_47 - 1 ) ) ;
V_42 = F_13 ( V_6 -> V_43 , V_47 ,
V_38 -> V_49 , V_45 , & V_46 ) ;
if ( ( V_46 + V_45 ) < V_44 )
F_11 ( V_9 ) |= V_58 ;
else
F_11 ( V_9 ) &= ~ V_58 ;
V_6 -> V_59 . V_60 = ( V_6 -> V_43 - V_42 )
* sizeof( struct V_42 ) ;
V_34 = F_14 ( V_6 , & V_6 -> V_59 ,
V_38 -> V_61 . V_62 & V_63 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_9 -> V_23 . V_30 . V_64 ,
V_9 -> V_23 . V_30 . V_65 ,
V_48 ) ;
F_11 ( V_9 ) |= V_51 ;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
F_16 ( V_39 , & ( V_6 -> V_66 -> V_68 ) ) ;
V_45 += V_46 ;
} while ( V_45 < V_44 );
memcpy ( V_35 , V_9 -> V_23 . V_30 . V_65 , V_48 ) ;
return V_34 ;
}
static int F_17 ( struct V_37 * V_38 , struct V_69 * V_70 ,
unsigned int V_39 )
{
int V_34 ;
struct V_5 * V_6 =
F_2 ( F_18 ( V_38 ) ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_42 * V_42 ;
unsigned int V_44 = V_39 ;
unsigned int V_45 = 0 , V_46 ;
unsigned int V_47 ;
V_8 -> V_23 . V_24 . V_25 = V_71 ;
F_11 ( V_8 ) &= ~ V_51 ;
V_47 = F_12 ( V_52 , V_53 . V_54 . V_47 / sizeof( struct V_42 ) ,
V_6 -> V_13 -> V_55 ) ;
V_47 = F_12 ( V_52 , V_47 ,
V_6 -> V_13 -> V_56 / V_57 ) ;
memcpy ( V_8 -> V_23 . V_27 . V_72 , V_70 -> V_73 , V_48 ) ;
do {
V_46 = F_12 ( V_52 , V_44 - V_45 ,
V_6 -> V_13 -> V_56 ) ;
V_46 = F_12 ( V_52 , V_46 ,
V_57 * ( V_47 - 1 ) ) ;
V_42 = F_13 ( V_6 -> V_43 , V_47 ,
V_38 -> V_49 , V_45 , & V_46 ) ;
if ( ( V_46 + V_45 ) < V_44 )
F_11 ( V_8 ) |= V_58 ;
else
F_11 ( V_8 ) &= ~ V_58 ;
V_6 -> V_74 . V_60 = ( V_6 -> V_43 - V_42 )
* sizeof( struct V_42 ) ;
V_8 -> V_23 . V_27 . V_75 = 0 ;
V_8 -> V_23 . V_27 . V_76 = 8 * V_44 ;
V_34 = F_14 ( V_6 , & V_6 -> V_74 ,
V_38 -> V_61 . V_62 & V_63 ) ;
if ( V_34 )
goto V_35;
memcpy ( V_8 -> V_23 . V_27 . V_77 ,
V_8 -> V_23 . V_27 . V_78 , V_48 ) ;
memcpy ( V_8 -> V_23 . V_27 . V_79 ,
V_8 -> V_23 . V_27 . V_80 , V_48 ) ;
F_11 ( V_8 ) |= V_51 ;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
F_16 ( V_39 , & ( V_6 -> V_66 -> V_68 ) ) ;
V_45 += V_46 ;
} while ( V_45 < V_44 );
V_35:
V_8 -> V_23 . V_24 . V_25 = V_26 ;
return V_34 ;
}
static int F_19 ( struct V_37 * V_38 , struct V_69 * V_70 ,
int V_81 )
{
int V_34 ;
struct V_5 * V_6 =
F_2 ( F_18 ( V_38 ) ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_35 [ V_48 ] ;
struct V_42 * V_43 , * V_82 ;
int V_83 ;
V_8 -> V_23 . V_24 . V_25 = V_84 ;
memcpy ( V_8 -> V_23 . V_85 . V_28 , V_8 -> V_23 . V_27 . V_28 ,
sizeof( V_8 -> V_23 . V_85 . V_28 ) ) ;
if ( V_81 )
F_11 ( V_8 ) |= V_86 ;
else
F_11 ( V_8 ) &= ~ V_86 ;
V_83 = V_48 ;
V_43 = F_20 ( V_6 -> V_43 , ( T_1 * ) V_70 -> V_73 ,
& V_83 , V_6 -> V_13 -> V_55 ) ;
if ( V_83 != V_48 )
return - V_22 ;
V_83 = sizeof( V_35 ) ;
V_82 = F_20 ( V_6 -> V_82 , ( T_1 * ) V_35 , & V_83 ,
V_6 -> V_13 -> V_55 ) ;
if ( V_83 != sizeof( V_35 ) )
return - V_22 ;
V_6 -> V_74 . V_60 = ( V_6 -> V_43 - V_43 ) * sizeof( struct V_42 ) ;
V_6 -> V_74 . V_87 = ( V_6 -> V_82 - V_82 ) * sizeof( struct V_42 ) ;
V_34 = F_14 ( V_6 , & V_6 -> V_74 ,
V_70 -> V_62 & V_63 ) ;
if ( V_34 )
goto V_35;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
memcpy ( V_8 -> V_23 . V_27 . V_78 , V_35 ,
F_21 ( F_18 ( V_38 ) ) ) ;
V_35:
V_8 -> V_23 . V_24 . V_25 = V_26 ;
memset ( V_8 -> V_23 . V_85 . V_28 , 0 , sizeof( V_8 -> V_23 . V_85 . V_28 ) ) ;
return V_34 ;
}
static int F_22 ( struct V_37 * V_38 , int V_81 ,
unsigned int V_39 )
{
struct V_5 * V_6 =
F_2 ( F_18 ( V_38 ) ) ;
struct V_88 * V_89 = F_23 ( V_38 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 V_70 ;
unsigned int V_44 = V_38 -> V_90 ;
unsigned int V_45 = 0 , V_46 ;
unsigned long V_91 ;
int V_34 = - V_22 ;
F_24 ( & V_6 -> V_92 , V_91 ) ;
V_70 . V_73 = V_89 -> V_93 ;
* ( V_94 * ) ( V_70 . V_73 + V_95 ) = 1 ;
if ( V_44 == 0 ) {
if ( V_39 == 0 )
V_34 = F_19 ( V_38 , & V_70 , V_81 ) ;
else
V_34 = F_17 ( V_38 , & V_70 , V_39 ) ;
if ( V_34 )
goto V_35;
else
goto V_96;
}
V_8 -> V_23 . V_27 . V_76 = V_39 * 8 ;
if ( V_39 ) {
V_34 = F_7 ( V_6 , V_38 , V_8 -> V_23 . V_27 . V_77 ,
V_39 ) ;
if ( V_34 )
goto V_35;
}
F_11 ( V_8 ) &= ~ V_51 ;
if ( V_81 ) {
F_11 ( V_8 ) |= V_86 ;
} else {
F_11 ( V_8 ) &= ~ V_86 ;
V_44 -= F_21 ( F_18 ( V_38 ) ) ;
}
do {
V_46 = V_44 - V_45 ;
V_8 -> V_23 . V_27 . V_75 = V_44 * 8 ;
V_34 = F_25 ( V_6 , & V_70 , V_38 -> V_97 ,
V_38 -> V_49 , & V_46 ,
V_45 + V_38 -> V_39 ,
V_8 -> V_23 . V_27 . V_72 ) ;
if ( V_34 )
goto V_35;
if ( ( V_46 + V_45 ) < V_44 )
F_11 ( V_8 ) |= V_58 ;
else
F_11 ( V_8 ) &= ~ V_58 ;
V_34 = F_14 ( V_6 , & V_6 -> V_74 ,
V_38 -> V_61 . V_62 & V_63 ) ;
if ( V_34 )
goto V_35;
memcpy ( V_70 . V_73 , V_8 -> V_23 . V_27 . V_98 , V_48 ) ;
memcpy ( V_8 -> V_23 . V_27 . V_77 ,
V_8 -> V_23 . V_27 . V_78 , V_48 ) ;
memcpy ( V_8 -> V_23 . V_27 . V_79 ,
V_8 -> V_23 . V_27 . V_80 , V_48 ) ;
F_11 ( V_8 ) |= V_51 ;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
F_16 ( V_8 -> V_99 . V_100 ,
& ( V_6 -> V_66 -> V_68 ) ) ;
V_45 += V_46 ;
} while ( V_45 < V_44 );
V_96:
if ( V_81 ) {
F_26 (
V_8 -> V_23 . V_27 . V_78 ,
V_38 -> V_97 , V_38 -> V_39 + V_44 ,
F_21 ( F_18 ( V_38 ) ) ,
V_101 ) ;
} else {
T_1 * V_102 = V_6 -> V_32 . V_33 . V_103 ;
T_1 * V_104 = V_8 -> V_23 . V_27 . V_78 ;
F_26 (
V_102 , V_38 -> V_49 , V_38 -> V_39 + V_44 ,
F_21 ( F_18 ( V_38 ) ) ,
V_50 ) ;
V_34 = F_27 ( V_102 , V_104 ,
F_21 ( F_18 ( V_38 ) ) ) ?
- V_105 : 0 ;
}
V_35:
F_28 ( & V_6 -> V_92 , V_91 ) ;
return V_34 ;
}
static int F_29 ( struct V_37 * V_38 )
{
struct V_88 * V_89 = F_23 ( V_38 ) ;
char * V_93 = V_89 -> V_93 ;
memcpy ( V_93 , V_38 -> V_93 , 12 ) ;
return F_22 ( V_38 , 1 , V_38 -> V_39 ) ;
}
static int F_30 ( struct V_37 * V_38 )
{
struct V_88 * V_89 = F_23 ( V_38 ) ;
char * V_93 = V_89 -> V_93 ;
memcpy ( V_93 , V_38 -> V_93 , 12 ) ;
return F_22 ( V_38 , 0 , V_38 -> V_39 ) ;
}
static int F_31 ( struct V_37 * V_38 )
{
struct V_5 * V_6 =
F_2 ( F_18 ( V_38 ) ) ;
struct V_88 * V_89 = F_23 ( V_38 ) ;
char * V_93 = V_89 -> V_93 ;
char * V_31 = V_6 -> V_32 . V_33 . V_31 ;
memcpy ( V_93 , V_31 , V_106 ) ;
memcpy ( V_93 + V_106 , V_38 -> V_93 , 8 ) ;
if ( V_38 -> V_39 < 8 )
return - V_22 ;
return F_22 ( V_38 , 1 , V_38 -> V_39 - 8 ) ;
}
static int F_32 ( struct V_37 * V_38 )
{
struct V_5 * V_6 =
F_2 ( F_18 ( V_38 ) ) ;
struct V_88 * V_89 = F_23 ( V_38 ) ;
char * V_93 = V_89 -> V_93 ;
char * V_31 = V_6 -> V_32 . V_33 . V_31 ;
memcpy ( V_93 , V_31 , V_106 ) ;
memcpy ( V_93 + V_106 , V_38 -> V_93 , 8 ) ;
if ( V_38 -> V_39 < 8 )
return - V_22 ;
return F_22 ( V_38 , 0 , V_38 -> V_39 - 8 ) ;
}
