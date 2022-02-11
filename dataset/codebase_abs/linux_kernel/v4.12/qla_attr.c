static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 = 0 ;
if ( ! ( V_14 -> V_17 || V_14 -> V_18 ) )
return 0 ;
if ( F_5 ( V_14 ) ) {
if ( V_8 < V_14 -> V_19 ) {
V_16 = F_6 ( V_7 , V_9 ,
& V_8 , V_14 -> V_20 , V_14 -> V_19 ) ;
return V_16 ;
}
V_8 -= V_14 -> V_19 ;
V_16 = F_6 ( V_7 , V_9 ,
& V_8 , V_14 -> V_21 , V_14 -> V_22 ) ;
return V_16 ;
} else if ( V_14 -> V_23 && V_14 -> V_18 )
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_24 ,
V_25 ) ;
else if ( V_14 -> V_17 )
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_26 ,
V_14 -> V_27 ) ;
else
return 0 ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_28 ;
if ( V_8 != 0 )
return ( 0 ) ;
V_28 = F_8 ( V_7 , NULL , 10 ) ;
switch ( V_28 ) {
case 0 :
if ( ! V_14 -> V_17 )
break;
F_9 ( V_29 , V_11 , 0x705d ,
L_1 , V_11 -> V_30 ) ;
if ( F_5 ( V_14 ) ) {
F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
}
V_14 -> V_17 = 0 ;
V_14 -> V_31 = 0 ;
break;
case 1 :
if ( V_14 -> V_31 && ! V_14 -> V_17 ) {
V_14 -> V_17 = 1 ;
F_9 ( V_29 , V_11 , 0x705e ,
L_2 ,
V_11 -> V_30 ) ;
}
break;
case 2 :
F_12 ( V_11 ) ;
break;
case 3 :
if ( F_13 ( V_14 ) ) {
F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
F_16 ( V_14 ) ;
} else if ( F_17 ( V_14 ) ) {
F_18 ( V_14 ) ;
F_15 ( V_11 ) ;
F_19 ( V_14 ) ;
} else
F_20 ( V_11 ) ;
break;
case 4 :
if ( F_5 ( V_14 ) ) {
if ( V_14 -> V_20 )
F_21 ( V_32 , V_11 , 0x705b ,
L_3 ) ;
else
F_21 ( V_32 , V_11 , 0x709d ,
L_4 ) ;
}
break;
case 5 :
if ( F_5 ( V_14 ) )
F_22 ( V_33 , & V_11 -> V_34 ) ;
break;
case 6 :
if ( ! V_14 -> V_18 )
break;
F_9 ( V_29 , V_11 , 0x70c1 ,
L_5 , V_11 -> V_30 ) ;
V_14 -> V_18 = 0 ;
V_14 -> V_23 = 0 ;
break;
case 7 :
if ( V_14 -> V_23 && ! V_14 -> V_18 ) {
V_14 -> V_18 = 1 ;
F_9 ( V_29 , V_11 , 0x70c2 ,
L_6 ,
V_11 -> V_30 ) ;
}
break;
}
return V_9 ;
}
static T_1
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_24 ( V_35 ) )
return 0 ;
if ( F_25 ( V_14 ) )
V_14 -> V_36 -> V_37 ( V_11 , V_14 -> V_38 , V_14 -> V_39 << 2 ,
V_14 -> V_40 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_38 ,
V_14 -> V_40 ) ;
}
static T_1
F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_41 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 != V_14 -> V_40 ||
! V_14 -> V_36 -> V_42 )
return - V_43 ;
if ( F_27 ( V_14 ) ) {
T_5 * V_44 ;
T_5 V_45 ;
V_44 = ( T_5 * ) V_7 ;
V_45 = 0 ;
for ( V_41 = 0 ; V_41 < ( ( V_9 >> 2 ) - 1 ) ; V_41 ++ , V_44 ++ )
V_45 += F_28 ( * V_44 ) ;
V_45 = ~ V_45 + 1 ;
* V_44 = F_29 ( V_45 ) ;
} else {
T_6 * V_44 ;
T_6 V_45 ;
V_44 = ( T_6 * ) V_7 ;
V_45 = 0 ;
for ( V_41 = 0 ; V_41 < V_9 - 1 ; V_41 ++ )
V_45 += * V_44 ++ ;
V_45 = ~ V_45 + 1 ;
* V_44 = V_45 ;
}
if ( F_30 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x705f ,
L_7 ) ;
return - V_48 ;
}
V_14 -> V_36 -> V_42 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_49 , V_9 ) ;
V_14 -> V_36 -> V_50 ( V_11 , ( T_6 * ) V_14 -> V_38 , V_14 -> V_49 ,
V_9 ) ;
F_21 ( V_32 , V_11 , 0x7060 ,
L_8 ) ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
return V_9 ;
}
static T_1
F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_1 V_16 = 0 ;
F_34 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_52 != V_53 )
goto V_54;
V_16 = F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_55 ,
V_14 -> V_56 ) ;
V_54:
F_35 ( & V_14 -> V_51 ) ;
return V_16 ;
}
static T_1
F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
F_34 ( & V_14 -> V_51 ) ;
if ( V_14 -> V_52 != V_57 ) {
F_35 ( & V_14 -> V_51 ) ;
return - V_43 ;
}
if ( V_8 > V_14 -> V_56 ) {
F_35 ( & V_14 -> V_51 ) ;
return - V_58 ;
}
if ( V_8 + V_9 > V_14 -> V_56 )
V_9 = V_14 -> V_56 - V_8 ;
memcpy ( & V_14 -> V_55 [ V_8 ] , V_7 , V_9 ) ;
F_35 ( & V_14 -> V_51 ) ;
return V_9 ;
}
static T_1
F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_59 = 0 ;
T_5 V_60 = V_14 -> V_61 ;
int V_62 , V_63 ;
T_1 V_16 = V_9 ;
if ( V_8 )
return - V_43 ;
if ( F_38 ( F_39 ( V_14 -> V_64 ) ) )
return - V_48 ;
if ( sscanf ( V_7 , L_9 , & V_62 , & V_59 , & V_60 ) < 1 )
return - V_43 ;
if ( V_59 > V_14 -> V_61 )
return - V_43 ;
F_34 ( & V_14 -> V_51 ) ;
switch ( V_62 ) {
case 0 :
if ( V_14 -> V_52 != V_53 &&
V_14 -> V_52 != V_57 ) {
V_16 = - V_43 ;
goto V_54;
}
V_14 -> V_52 = V_65 ;
F_21 ( V_32 , V_11 , 0x7061 ,
L_10 ,
V_14 -> V_56 ) ;
F_40 ( V_14 -> V_55 ) ;
V_14 -> V_55 = NULL ;
break;
case 1 :
if ( V_14 -> V_52 != V_65 ) {
V_16 = - V_43 ;
goto V_54;
}
V_14 -> V_66 = V_59 ;
V_14 -> V_56 = V_59 + V_60 > V_14 -> V_61 ?
V_14 -> V_61 - V_59 : V_60 ;
V_14 -> V_52 = V_53 ;
V_14 -> V_55 = F_41 ( V_14 -> V_56 ) ;
if ( V_14 -> V_55 == NULL ) {
F_9 ( V_47 , V_11 , 0x7062 ,
L_11
L_12 , V_14 -> V_56 ) ;
V_14 -> V_52 = V_65 ;
V_16 = - V_67 ;
goto V_54;
}
if ( F_30 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x7063 ,
L_7 ) ;
V_16 = - V_48 ;
goto V_54;
}
F_21 ( V_32 , V_11 , 0x7064 ,
L_13 ,
V_14 -> V_66 , V_14 -> V_56 ) ;
memset ( V_14 -> V_55 , 0 , V_14 -> V_56 ) ;
V_14 -> V_36 -> V_37 ( V_11 , V_14 -> V_55 ,
V_14 -> V_66 , V_14 -> V_56 ) ;
break;
case 2 :
if ( V_14 -> V_52 != V_65 ) {
V_16 = - V_43 ;
goto V_54;
}
V_63 = 0 ;
if ( V_14 -> V_61 == V_68 && V_59 == 0 )
V_63 = 1 ;
else if ( V_59 == ( V_14 -> V_69 * 4 ) ||
V_59 == ( V_14 -> V_70 * 4 ) )
V_63 = 1 ;
else if ( F_42 ( V_14 ) || F_43 ( V_14 )
|| F_44 ( V_14 ) || F_45 ( V_14 )
|| F_46 ( V_14 ) )
V_63 = 1 ;
if ( ! V_63 ) {
F_9 ( V_47 , V_11 , 0x7065 ,
L_14 , V_59 , V_60 ) ;
V_16 = - V_43 ;
goto V_54;
}
V_14 -> V_66 = V_59 ;
V_14 -> V_56 = V_59 + V_60 > V_14 -> V_61 ?
V_14 -> V_61 - V_59 : V_60 ;
V_14 -> V_52 = V_57 ;
V_14 -> V_55 = F_41 ( V_14 -> V_56 ) ;
if ( V_14 -> V_55 == NULL ) {
F_9 ( V_47 , V_11 , 0x7066 ,
L_15
L_16 , V_14 -> V_56 ) ;
V_14 -> V_52 = V_65 ;
V_16 = - V_67 ;
goto V_54;
}
F_21 ( V_32 , V_11 , 0x7067 ,
L_17 ,
V_14 -> V_66 , V_14 -> V_56 ) ;
memset ( V_14 -> V_55 , 0 , V_14 -> V_56 ) ;
break;
case 3 :
if ( V_14 -> V_52 != V_57 ) {
V_16 = - V_43 ;
goto V_54;
}
if ( F_30 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x7068 ,
L_18 ) ;
V_16 = - V_48 ;
goto V_54;
}
F_21 ( V_32 , V_11 , 0x7069 ,
L_19 ,
V_14 -> V_66 , V_14 -> V_56 ) ;
V_14 -> V_36 -> V_71 ( V_11 , V_14 -> V_55 ,
V_14 -> V_66 , V_14 -> V_56 ) ;
break;
default:
V_16 = - V_43 ;
}
V_54:
F_35 ( & V_14 -> V_51 ) ;
return V_16 ;
}
static T_1
F_47 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_72 ;
if ( F_38 ( F_39 ( V_14 -> V_64 ) ) )
return - V_48 ;
if ( ! F_24 ( V_35 ) )
return - V_43 ;
if ( F_25 ( V_14 ) ) {
V_72 = V_14 -> V_73 << 2 ;
if ( F_46 ( V_14 ) &&
F_48 ( V_11 ) == V_74 )
V_72 = V_14 -> V_75 << 2 ;
V_14 -> V_36 -> V_37 ( V_11 , V_14 -> V_76 , V_72 ,
V_14 -> V_77 ) ;
}
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_76 , V_14 -> V_77 ) ;
}
static T_1
F_49 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_78 ;
if ( F_38 ( F_39 ( V_14 -> V_64 ) ) )
return 0 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 != V_14 -> V_77 ||
! V_14 -> V_36 -> V_42 )
return 0 ;
if ( F_30 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x706a ,
L_20 ) ;
return - V_48 ;
}
V_14 -> V_36 -> V_42 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_79 , V_9 ) ;
V_14 -> V_36 -> V_50 ( V_11 , ( T_6 * ) V_14 -> V_76 , V_14 -> V_79 , V_9 ) ;
if ( ! F_27 ( V_14 ) )
return - V_43 ;
V_78 = F_41 ( 256 ) ;
if ( ! V_78 ) {
F_9 ( V_47 , V_11 , 0x706b ,
L_21 ) ;
return - V_67 ;
}
V_14 -> V_36 -> V_80 ( V_11 , V_78 ) ;
F_40 ( V_78 ) ;
return V_9 ;
}
static T_1
F_50 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_44 , V_81 , V_82 ;
int V_16 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 != V_83 * 2 )
return 0 ;
if ( V_14 -> V_84 )
goto V_85;
V_14 -> V_84 = F_51 ( V_14 -> V_86 , V_87 ,
& V_14 -> V_88 ) ;
if ( ! V_14 -> V_84 ) {
F_9 ( V_47 , V_11 , 0x706c ,
L_22 ) ;
return 0 ;
}
V_85:
memset ( V_14 -> V_84 , 0 , V_89 ) ;
V_81 = 0xa0 ;
for ( V_44 = 0 , V_82 = 0 ; V_44 < ( V_83 * 2 ) / V_89 ;
V_44 ++ , V_82 += V_89 ) {
if ( V_44 == 4 ) {
V_81 = 0xa2 ;
V_82 = 0 ;
}
V_16 = F_52 ( V_11 , V_14 -> V_88 , V_14 -> V_84 ,
V_81 , V_82 , V_89 , V_90 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x706d ,
L_23 , V_16 ,
V_81 , V_82 ) ;
return - V_91 ;
}
memcpy ( V_7 , V_14 -> V_84 , V_89 ) ;
V_7 += V_89 ;
}
return V_9 ;
}
static T_1
F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_92 = F_54 ( V_14 -> V_64 ) ;
int type ;
T_5 V_93 ;
T_6 * V_78 = NULL ;
if ( V_8 != 0 )
return - V_43 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_29 , V_11 , 0x706e ,
L_24 ) ;
F_55 ( V_11 -> V_94 ) ;
if ( F_13 ( V_14 ) ) {
V_14 -> V_95 . V_96 = 1 ;
F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
F_16 ( V_14 ) ;
} else if ( F_17 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_93 = F_56 ( V_14 ,
V_97 ) ;
F_57 ( V_14 , V_97 ,
( V_93 | V_98 ) ) ;
F_15 ( V_11 ) ;
F_19 ( V_14 ) ;
} else {
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_31 ( V_11 ) ;
}
F_32 ( V_11 ) ;
F_58 ( V_11 -> V_94 ) ;
break;
case 0x2025d :
if ( ! F_59 ( V_14 ) && ! F_60 ( V_14 ) )
return - V_99 ;
F_9 ( V_29 , V_11 , 0x706f ,
L_25 ) ;
if ( F_60 ( V_14 ) || F_46 ( V_14 ) ) {
T_5 V_93 ;
F_61 ( V_11 , 0 ) ;
F_62 ( V_11 , & V_93 ) ;
V_93 |= V_100 ;
F_63 ( V_11 , V_93 ) ;
F_64 ( V_11 , V_101 ,
V_102 ) ;
F_65 ( V_11 , V_103 ) ;
F_66 ( V_11 , 0 ) ;
break;
} else {
F_30 ( V_11 ) ;
F_55 ( V_11 -> V_94 ) ;
if ( F_67 ( V_11 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7070 ,
L_26 ) ;
F_58 ( V_11 -> V_94 ) ;
break;
}
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_92 ) {
F_9 ( V_29 , V_11 , 0x7071 ,
L_27 ) ;
return - V_99 ;
}
F_9 ( V_29 , V_11 , 0x7072 ,
L_28 ) ;
F_22 ( V_104 , & V_11 -> V_34 ) ;
F_31 ( V_11 ) ;
F_68 ( V_11 ) ;
break;
case 0x2025f :
if ( ! F_69 ( V_14 ) )
return - V_99 ;
F_9 ( V_29 , V_11 , 0x70bc ,
L_29 ) ;
F_61 ( V_11 , 0 ) ;
F_62 ( V_11 , & V_93 ) ;
V_93 |= V_105 ;
F_63 ( V_11 , V_93 ) ;
F_66 ( V_11 , 0 ) ;
break;
case 0x20260 :
if ( ! F_69 ( V_14 ) )
return - V_99 ;
F_9 ( V_29 , V_11 , 0x70bd ,
L_30 ) ;
F_61 ( V_11 , 0 ) ;
F_62 ( V_11 , & V_93 ) ;
V_93 &= ~ V_105 ;
F_63 ( V_11 , V_93 ) ;
F_66 ( V_11 , 0 ) ;
break;
case 0x20261 :
F_21 ( V_32 , V_11 , 0x70e0 ,
L_31 ) ;
V_78 = F_41 ( 256 ) ;
if ( ! V_78 ) {
F_9 ( V_47 , V_11 , 0x70e1 ,
L_21 ) ;
return - V_67 ;
}
V_14 -> V_36 -> V_80 ( V_11 , V_78 ) ;
F_40 ( V_78 ) ;
break;
}
return V_9 ;
}
static T_1
F_70 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
int type ;
T_7 V_106 ;
type = F_8 ( V_7 , NULL , 10 ) ;
V_106 . V_107 . V_108 = ( type & 0x00ff0000 ) >> 16 ;
V_106 . V_107 . V_109 = ( type & 0x0000ff00 ) >> 8 ;
V_106 . V_107 . V_110 = ( type & 0x000000ff ) ;
F_9 ( V_29 , V_11 , 0x70e3 , L_32 ,
V_106 . V_107 . V_108 , V_106 . V_107 . V_109 , V_106 . V_107 . V_110 ) ;
F_9 ( V_29 , V_11 , 0x70e4 , L_33 , V_111 , type ) ;
F_71 ( V_11 , V_112 , V_106 ) ;
return V_9 ;
}
static T_1
F_72 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_4 V_113 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 > V_114 )
return 0 ;
if ( V_14 -> V_115 )
goto V_85;
V_14 -> V_115 = F_73 ( & V_14 -> V_64 -> V_116 , V_114 ,
& V_14 -> V_117 , V_87 ) ;
if ( ! V_14 -> V_115 ) {
F_9 ( V_47 , V_11 , 0x7076 ,
L_34 ) ;
return 0 ;
}
V_85:
V_113 = 0 ;
memset ( V_14 -> V_115 , 0 , V_114 ) ;
V_16 = F_74 ( V_11 , V_14 -> V_117 ,
V_114 , & V_113 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7077 ,
L_35 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_113 > V_9 ? V_9 : V_113 ;
memcpy ( V_7 , V_14 -> V_115 , V_9 ) ;
return V_9 ;
}
static T_1
F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 > V_118 )
return 0 ;
if ( V_14 -> V_119 )
goto V_85;
V_14 -> V_119 = F_73 ( & V_14 -> V_64 -> V_116 , V_118 ,
& V_14 -> V_120 , V_87 ) ;
if ( ! V_14 -> V_119 ) {
F_9 ( V_47 , V_11 , 0x7078 ,
L_36 ) ;
return - V_67 ;
}
V_85:
memset ( V_14 -> V_119 , 0 , V_118 ) ;
V_16 = F_76 ( V_11 , V_14 -> V_120 ,
V_118 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7079 ,
L_37 , V_16 ) ;
return - V_91 ;
}
memcpy ( V_7 , V_14 -> V_119 , V_9 ) ;
return V_9 ;
}
void
F_77 ( T_8 * V_11 )
{
struct V_121 * V_94 = V_11 -> V_94 ;
struct V_122 * V_44 ;
int V_123 ;
for ( V_44 = V_124 ; V_44 -> V_125 ; V_44 ++ ) {
if ( V_44 -> V_126 && ! F_27 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_126 == 2 && ! F_43 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_126 == 3 && ! ( F_44 ( V_11 -> V_15 ) ) )
continue;
V_123 = F_78 ( & V_94 -> V_127 . V_4 ,
V_44 -> V_128 ) ;
if ( V_123 )
F_9 ( V_47 , V_11 , 0x00f3 ,
L_38 ,
V_44 -> V_125 , V_123 ) ;
else
F_21 ( V_129 , V_11 , 0x00f4 ,
L_39 ,
V_44 -> V_125 ) ;
}
}
void
F_79 ( T_8 * V_11 , bool V_130 )
{
struct V_121 * V_94 = V_11 -> V_94 ;
struct V_122 * V_44 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_44 = V_124 ; V_44 -> V_125 ; V_44 ++ ) {
if ( V_44 -> V_126 && ! F_27 ( V_14 ) )
continue;
if ( V_44 -> V_126 == 2 && ! F_43 ( V_14 ) )
continue;
if ( V_44 -> V_126 == 3 && ! ( F_44 ( V_11 -> V_15 ) ) )
continue;
if ( V_44 -> V_126 == 0x27 && ! F_46 ( V_11 -> V_15 ) )
continue;
F_80 ( & V_94 -> V_127 . V_4 ,
V_44 -> V_128 ) ;
}
if ( V_130 && V_14 -> V_131 == 1 )
V_14 -> V_36 -> V_132 ( V_11 ) ;
}
static T_1
F_81 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
return F_82 ( V_7 , V_134 , L_40 , V_135 ) ;
}
static T_1
F_83 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_136 [ 128 ] ;
return F_82 ( V_7 , V_134 , L_40 ,
V_14 -> V_36 -> V_137 ( V_11 , V_136 , sizeof( V_136 ) ) ) ;
}
static T_1
F_85 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_138 ;
if ( F_86 ( V_11 -> V_15 ) ) {
return F_82 ( V_7 , V_134 , L_40 ,
V_11 -> V_15 -> V_139 . V_140 ) ;
} else if ( F_27 ( V_14 ) ) {
F_87 ( V_11 , L_41 , V_7 , V_134 - 1 ) ;
return strlen ( strcat ( V_7 , L_42 ) ) ;
}
V_138 = ( ( V_14 -> V_141 & 0x1f ) << 16 ) | ( V_14 -> V_142 << 8 ) | V_14 -> V_143 ;
return F_82 ( V_7 , V_134 , L_43 , 'A' + V_138 / 100000 ,
V_138 % 100000 ) ;
}
static T_1
F_88 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
return F_82 ( V_7 , V_134 , L_44 , V_11 -> V_15 -> V_64 -> V_12 ) ;
}
static T_1
F_89 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_86 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_134 , L_40 ,
V_11 -> V_15 -> V_139 . V_144 ) ;
return F_82 ( V_7 , V_134 , L_45 ,
V_14 -> V_145 [ 0 ] , V_14 -> V_145 [ 1 ] , V_14 -> V_145 [ 2 ] ,
V_14 -> V_145 [ 3 ] ) ;
}
static T_1
F_90 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
return F_82 ( V_7 , V_134 , L_40 , V_11 -> V_15 -> V_146 ) ;
}
static T_1
F_91 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
return F_82 ( V_7 , V_134 , L_40 , V_11 -> V_15 -> V_147 ) ;
}
static T_1
F_92 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
char V_148 [ 30 ] ;
return F_82 ( V_7 , V_134 , L_40 ,
V_11 -> V_15 -> V_36 -> V_149 ( V_11 , V_148 ) ) ;
}
static T_1
F_93 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_150 = 0 ;
if ( F_94 ( & V_11 -> V_151 ) == V_152 ||
F_94 ( & V_11 -> V_151 ) == V_153 ||
V_11 -> V_154 & V_155 )
V_150 = F_82 ( V_7 , V_134 , L_46 ) ;
else if ( F_94 ( & V_11 -> V_151 ) != V_156 ||
F_95 ( V_11 ) )
V_150 = F_82 ( V_7 , V_134 , L_47 ) ;
else {
V_150 = F_82 ( V_7 , V_134 , L_48 ) ;
switch ( V_14 -> V_157 ) {
case V_158 :
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_49 ) ;
break;
case V_159 :
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_50 ) ;
break;
case V_160 :
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 ,
L_51 ) ;
break;
case V_161 :
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_52 ) ;
break;
default:
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_49 ) ;
break;
}
}
return V_150 ;
}
static T_1
F_96 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
int V_150 = 0 ;
switch ( V_11 -> V_15 -> V_162 ) {
case V_163 :
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_53 ) ;
break;
case V_164 :
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_54 ) ;
break;
}
return V_150 ;
}
static T_1
F_97 ( struct V_12 * V_116 , struct V_133 * V_128 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_62 = 0 ;
T_4 V_162 ;
if ( ! F_98 ( V_14 ) )
return - V_165 ;
if ( sscanf ( V_7 , L_55 , & V_62 ) != 1 )
return - V_43 ;
if ( V_62 )
V_162 = V_163 ;
else
V_162 = V_164 ;
if ( V_162 != V_164 || V_14 -> V_162 != V_164 ) {
V_14 -> V_162 = V_162 ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_99 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
return F_82 ( V_7 , V_134 , L_56 , V_11 -> V_15 -> V_166 * 100 ) ;
}
static T_1
F_100 ( struct V_12 * V_116 , struct V_133 * V_128 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
int V_62 = 0 ;
T_4 V_166 ;
if ( sscanf ( V_7 , L_55 , & V_62 ) != 1 )
return - V_43 ;
if ( V_62 > 25500 || V_62 < 100 )
return - V_58 ;
V_166 = ( T_4 ) ( V_62 / 100 ) ;
V_11 -> V_15 -> V_166 = V_166 ;
return strlen ( V_7 ) ;
}
static T_1
F_101 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
int V_150 = 0 ;
if ( V_11 -> V_15 -> V_131 )
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_57 ) ;
else
V_150 += F_82 ( V_7 + V_150 , V_134 - V_150 , L_54 ) ;
return V_150 ;
}
static T_1
F_102 ( struct V_12 * V_116 , struct V_133 * V_128 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_62 = 0 ;
int V_16 ;
if ( F_103 ( V_14 ) || F_104 ( V_14 ) )
return - V_99 ;
if ( F_105 ( V_167 , & V_11 -> V_34 ) ) {
F_9 ( V_47 , V_11 , 0x707a ,
L_58 ) ;
return - V_168 ;
}
if ( sscanf ( V_7 , L_55 , & V_62 ) != 1 )
return - V_43 ;
if ( V_62 )
V_16 = V_14 -> V_36 -> V_169 ( V_11 ) ;
else
V_16 = V_14 -> V_36 -> V_132 ( V_11 ) ;
if ( V_16 != V_46 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_106 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_134 , L_59 , V_14 -> V_170 [ 1 ] ,
V_14 -> V_170 [ 0 ] ) ;
}
static T_1
F_107 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_134 , L_59 , V_14 -> V_171 [ 1 ] ,
V_14 -> V_171 [ 0 ] ) ;
}
static T_1
F_108 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_134 , L_59 , V_14 -> V_172 [ 1 ] ,
V_14 -> V_172 [ 0 ] ) ;
}
static T_1
F_109 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_134 , L_60 ,
V_14 -> V_173 [ 0 ] , V_14 -> V_173 [ 1 ] , V_14 -> V_173 [ 2 ] ,
V_14 -> V_173 [ 3 ] ) ;
}
static T_1
F_110 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_59 ( V_14 ) && ! F_60 ( V_14 ) && ! F_46 ( V_14 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_61 ,
V_14 -> V_174 [ 0 ] , V_14 -> V_174 [ 1 ] ,
V_14 -> V_174 [ 2 ] , V_14 -> V_174 [ 3 ] ) ;
}
static T_1
F_111 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
return F_82 ( V_7 , V_134 , L_62 ,
V_11 -> V_175 . V_176 ) ;
}
static T_1
F_112 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
int V_16 = V_46 ;
T_4 V_177 [ 2 ] = { 0 , 0 } ;
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_113 ( V_14 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
if ( V_14 -> V_178 -> V_179 == 0 )
V_16 = F_114 ( V_11 , V_177 ) ;
if ( ( V_16 == V_46 ) && ( V_177 [ 0 ] == 0 ) )
return F_82 ( V_7 , V_134 , L_63 ,
( T_5 ) V_14 -> V_178 -> V_179 ) ;
return F_82 ( V_7 , V_134 , L_42 ) ;
}
static T_1
F_115 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_59 ( V_14 ) && ! F_69 ( V_14 ) && ! F_17 ( V_14 ) &&
! F_46 ( V_14 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_64 ,
V_14 -> V_180 [ 0 ] , V_14 -> V_180 [ 1 ] , V_14 -> V_180 [ 2 ] ,
V_14 -> V_181 ) ;
}
static T_1
F_116 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_59 ( V_14 ) && ! F_69 ( V_14 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_65 ,
V_14 -> V_182 [ 0 ] , V_14 -> V_182 [ 1 ] , V_14 -> V_182 [ 2 ] ) ;
}
static T_1
F_117 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_134 , L_66 , V_14 -> V_183 ) ;
}
static T_1
F_118 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
if ( ! F_44 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_62 , V_11 -> V_184 ) ;
}
static T_1
F_119 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
if ( ! F_44 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_67 , V_11 -> V_185 ) ;
}
static T_1
F_120 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
return F_82 ( V_7 , V_134 , L_62 , V_11 -> V_15 -> V_186 ) ;
}
static T_1
F_121 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
T_4 V_187 = 0 ;
if ( F_95 ( V_11 ) ) {
F_9 ( V_47 , V_11 , 0x70dc , L_68 ) ;
goto V_188;
}
if ( V_11 -> V_15 -> V_95 . V_189 ) {
F_9 ( V_47 , V_11 , 0x70dd , L_69 ) ;
goto V_188;
}
if ( F_122 ( V_11 , & V_187 ) == V_46 )
return F_82 ( V_7 , V_134 , L_62 , V_187 ) ;
V_188:
return F_82 ( V_7 , V_134 , L_42 ) ;
}
static T_1
F_123 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
int V_16 = V_190 ;
T_4 V_191 [ 6 ] ;
T_5 V_192 ;
if ( F_86 ( V_11 -> V_15 ) ) {
V_192 = F_124 ( V_116 , V_128 , V_7 ) ;
return F_82 ( V_7 , V_134 , L_66 , V_192 ) ;
}
if ( F_95 ( V_11 ) )
F_9 ( V_47 , V_11 , 0x707c ,
L_68 ) ;
else if ( ! V_11 -> V_15 -> V_95 . V_189 )
V_16 = F_125 ( V_11 , V_191 ) ;
if ( V_16 != V_46 )
memset ( V_191 , - 1 , sizeof( V_191 ) ) ;
return F_82 ( V_7 , V_134 , L_70 ,
V_191 [ 0 ] , V_191 [ 1 ] , V_191 [ 2 ] , V_191 [ 3 ] , V_191 [ 4 ] , V_191 [ 5 ] ) ;
}
static T_1
F_126 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
if ( ! F_127 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_71 , V_11 -> V_193 . V_194 ) ;
}
static T_1
F_128 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
if ( ! F_127 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_71 ,
V_11 -> V_193 . V_195 >> 20 ) ;
}
static T_1
F_129 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_60 ;
if ( ! V_14 -> V_31 )
V_60 = 0 ;
else if ( F_5 ( V_14 ) )
V_60 = V_14 -> V_19 + V_14 -> V_22 ;
else
V_60 = V_14 -> V_27 ;
return F_82 ( V_7 , V_134 , L_62 , V_60 ) ;
}
static T_1
F_130 ( struct V_12 * V_116 ,
struct V_133 * V_128 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
if ( ! F_5 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
else
return F_82 ( V_7 , V_134 , L_40 ,
V_11 -> V_15 -> V_196 ? L_72 : L_73 ) ;
}
static T_1
F_131 ( struct V_12 * V_116 ,
struct V_133 * V_128 , const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
int V_62 = 0 ;
if ( ! F_5 ( V_11 -> V_15 ) )
return - V_43 ;
if ( sscanf ( V_7 , L_55 , & V_62 ) != 1 )
return - V_43 ;
V_11 -> V_15 -> V_196 = V_62 != 0 ;
return strlen ( V_7 ) ;
}
static T_1
F_132 ( struct V_12 * V_116 , struct V_133 * V_128 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_116 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_46 ( V_14 ) )
return F_82 ( V_7 , V_134 , L_42 ) ;
return F_82 ( V_7 , V_134 , L_65 ,
V_14 -> V_197 [ 0 ] , V_14 -> V_197 [ 1 ] , V_14 -> V_197 [ 2 ] ) ;
}
static void
F_133 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
F_134 ( V_198 ) = V_11 -> V_199 . V_107 . V_108 << 16 |
V_11 -> V_199 . V_107 . V_109 << 8 | V_11 -> V_199 . V_107 . V_110 ;
}
static void
F_135 ( struct V_121 * V_198 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_198 ) ) ) -> V_15 ;
T_9 V_200 = V_201 ;
if ( F_86 ( V_14 ) ) {
F_136 ( V_198 ) ;
return;
}
switch ( V_14 -> V_202 ) {
case V_203 :
V_200 = V_204 ;
break;
case V_205 :
V_200 = V_206 ;
break;
case V_207 :
V_200 = V_208 ;
break;
case V_209 :
V_200 = V_210 ;
break;
case V_211 :
V_200 = V_212 ;
break;
case V_213 :
V_200 = V_214 ;
break;
case V_215 :
V_200 = V_216 ;
break;
}
F_137 ( V_198 ) = V_200 ;
}
static void
F_138 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
T_5 V_217 = V_218 ;
if ( V_11 -> V_219 ) {
F_139 ( V_198 ) = V_220 ;
return;
}
switch ( V_11 -> V_15 -> V_157 ) {
case V_158 :
V_217 = V_221 ;
break;
case V_159 :
V_217 = V_222 ;
break;
case V_160 :
V_217 = V_223 ;
break;
case V_161 :
V_217 = V_224 ;
break;
}
F_139 ( V_198 ) = V_217 ;
}
static void
F_140 ( struct V_225 * V_226 )
{
struct V_121 * V_94 = F_3 ( V_226 -> V_116 . V_227 ) ;
T_8 * V_11 = F_2 ( V_94 ) ;
T_10 * V_228 ;
T_11 V_229 = 0 ;
F_141 (fcport, &vha->vp_fcports, list) {
if ( V_228 -> V_230 &&
V_226 -> V_231 == V_228 -> V_230 -> V_232 ) {
V_229 = F_142 ( V_228 -> V_229 ) ;
break;
}
}
F_143 ( V_226 ) = V_229 ;
}
static void
F_144 ( struct V_225 * V_226 )
{
struct V_121 * V_94 = F_3 ( V_226 -> V_116 . V_227 ) ;
T_8 * V_11 = F_2 ( V_94 ) ;
T_10 * V_228 ;
T_11 V_233 = 0 ;
F_141 (fcport, &vha->vp_fcports, list) {
if ( V_228 -> V_230 &&
V_226 -> V_231 == V_228 -> V_230 -> V_232 ) {
V_233 = F_142 ( V_228 -> V_233 ) ;
break;
}
}
F_145 ( V_226 ) = V_233 ;
}
static void
F_146 ( struct V_225 * V_226 )
{
struct V_121 * V_94 = F_3 ( V_226 -> V_116 . V_227 ) ;
T_8 * V_11 = F_2 ( V_94 ) ;
T_10 * V_228 ;
T_5 V_234 = ~ 0U ;
F_141 (fcport, &vha->vp_fcports, list) {
if ( V_228 -> V_230 &&
V_226 -> V_231 == V_228 -> V_230 -> V_232 ) {
V_234 = V_228 -> V_199 . V_107 . V_108 << 16 |
V_228 -> V_199 . V_107 . V_109 << 8 | V_228 -> V_199 . V_107 . V_110 ;
break;
}
}
F_147 ( V_226 ) = V_234 ;
}
static void
F_148 ( struct V_235 * V_230 , T_5 V_236 )
{
if ( V_236 )
V_230 -> V_237 = V_236 ;
else
V_230 -> V_237 = 1 ;
}
static void
F_149 ( struct V_235 * V_230 )
{
struct V_121 * V_94 = F_150 ( V_230 ) ;
T_10 * V_228 = * ( T_10 * * ) V_230 -> V_238 ;
unsigned long V_95 ;
if ( ! V_228 )
return;
F_151 ( V_228 , V_239 ) ;
F_152 ( V_94 -> V_240 , V_95 ) ;
V_228 -> V_230 = V_228 -> V_241 = NULL ;
* ( ( T_10 * * ) V_230 -> V_238 ) = NULL ;
F_153 ( V_94 -> V_240 , V_95 ) ;
if ( F_105 ( V_167 , & V_228 -> V_11 -> V_34 ) )
return;
if ( F_38 ( F_39 ( V_228 -> V_11 -> V_15 -> V_64 ) ) ) {
F_154 ( V_228 -> V_11 , V_242 << 16 ) ;
return;
}
}
static void
F_155 ( struct V_235 * V_230 )
{
T_10 * V_228 = * ( T_10 * * ) V_230 -> V_238 ;
if ( ! V_228 )
return;
if ( F_105 ( V_243 , & V_228 -> V_11 -> V_34 ) )
return;
if ( F_105 ( V_167 , & V_228 -> V_11 -> V_34 ) )
return;
if ( F_38 ( F_39 ( V_228 -> V_11 -> V_15 -> V_64 ) ) ) {
F_154 ( V_228 -> V_11 , V_242 << 16 ) ;
return;
}
if ( V_228 -> V_244 != V_245 ) {
if ( F_27 ( V_228 -> V_11 -> V_15 ) )
V_228 -> V_11 -> V_15 -> V_36 -> V_246 ( V_228 -> V_11 ,
V_228 -> V_244 , V_228 -> V_199 . V_107 . V_108 ,
V_228 -> V_199 . V_107 . V_109 , V_228 -> V_199 . V_107 . V_110 ) ;
else
F_156 ( V_228 -> V_11 , V_228 ) ;
}
}
static int
F_157 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
if ( F_86 ( V_11 -> V_15 ) )
return 0 ;
F_158 ( V_11 ) ;
return 0 ;
}
static struct V_247 *
F_159 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_92 = F_54 ( V_14 -> V_64 ) ;
int V_16 ;
struct V_248 * V_249 ;
T_12 V_250 ;
struct V_247 * V_251 = & V_11 -> V_252 ;
memset ( V_251 , - 1 , sizeof( * V_251 ) ) ;
if ( F_86 ( V_11 -> V_15 ) )
goto V_188;
if ( F_105 ( V_243 , & V_11 -> V_34 ) )
goto V_188;
if ( F_38 ( F_39 ( V_14 -> V_64 ) ) )
goto V_188;
if ( F_95 ( V_11 ) )
goto V_188;
V_249 = F_73 ( & V_14 -> V_64 -> V_116 ,
sizeof( * V_249 ) , & V_250 , V_87 ) ;
if ( ! V_249 ) {
F_9 ( V_47 , V_11 , 0x707d ,
L_74 ) ;
goto V_188;
}
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
V_16 = V_190 ;
if ( F_27 ( V_14 ) ) {
V_16 = F_160 ( V_92 , V_249 , V_250 , 0 ) ;
} else if ( F_94 ( & V_92 -> V_151 ) == V_156 &&
! V_14 -> V_253 ) {
V_16 = F_161 ( V_92 , V_92 -> V_244 ,
V_249 , V_250 ) ;
}
if ( V_16 != V_46 )
goto V_254;
V_251 -> V_255 = V_249 -> V_256 ;
V_251 -> V_257 = V_249 -> V_258 ;
V_251 -> V_259 = V_249 -> V_260 ;
V_251 -> V_261 = V_249 -> V_262 ;
V_251 -> V_263 = V_249 -> V_264 ;
V_251 -> V_265 = V_249 -> V_266 ;
if ( F_27 ( V_14 ) ) {
V_251 -> V_267 = V_249 -> V_268 ;
V_251 -> V_269 = V_249 -> V_269 ;
V_251 -> V_270 = V_249 -> V_270 ;
V_251 -> V_271 = V_249 -> V_272 ;
V_251 -> V_273 = V_249 -> V_274 ;
V_251 -> V_275 =
V_249 -> V_276 + V_249 -> V_272 ;
V_251 -> V_277 = V_11 -> V_175 . V_278 ;
V_251 -> V_279 = V_11 -> V_175 . V_280 ;
}
V_251 -> V_281 = V_11 -> V_175 . V_282 ;
V_251 -> V_283 = V_11 -> V_175 . V_284 ;
V_251 -> V_285 = V_11 -> V_175 . V_286 ;
V_251 -> V_287 = V_11 -> V_175 . V_278 >> 20 ;
V_251 -> V_288 = V_11 -> V_175 . V_280 >> 20 ;
V_251 -> V_289 =
F_162 () - V_11 -> V_175 . V_290 ;
F_163 ( V_251 -> V_289 , V_291 ) ;
V_254:
F_164 ( & V_14 -> V_64 -> V_116 , sizeof( struct V_248 ) ,
V_249 , V_250 ) ;
V_188:
return V_251 ;
}
static void
F_165 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_92 = F_54 ( V_14 -> V_64 ) ;
struct V_248 * V_249 ;
T_12 V_250 ;
memset ( & V_11 -> V_175 , 0 , sizeof( V_11 -> V_175 ) ) ;
memset ( & V_11 -> V_252 , 0 , sizeof( V_11 -> V_252 ) ) ;
V_11 -> V_175 . V_290 = F_162 () ;
if ( F_27 ( V_14 ) ) {
V_249 = F_73 ( & V_14 -> V_64 -> V_116 ,
sizeof( * V_249 ) , & V_250 , V_87 ) ;
if ( ! V_249 ) {
F_9 ( V_47 , V_11 , 0x70d7 ,
L_74 ) ;
return;
}
F_160 ( V_92 , V_249 , V_250 , V_292 ) ;
F_164 ( & V_14 -> V_64 -> V_116 , sizeof( * V_249 ) ,
V_249 , V_250 ) ;
}
}
static void
F_166 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
F_167 ( V_11 , F_168 ( V_198 ) ,
sizeof( F_168 ( V_198 ) ) ) ;
}
static void
F_169 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
F_22 ( V_293 , & V_11 -> V_34 ) ;
}
static void
F_170 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
T_6 V_229 [ V_294 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_11 V_295 = F_142 ( V_229 ) ;
if ( V_11 -> V_154 & V_296 )
V_295 = F_142 ( V_11 -> V_297 ) ;
F_171 ( V_198 ) = V_295 ;
}
static void
F_172 ( struct V_121 * V_198 )
{
T_8 * V_11 = F_2 ( V_198 ) ;
struct V_10 * V_92 = F_54 ( V_11 -> V_15 -> V_64 ) ;
if ( ! V_92 -> V_95 . V_298 ) {
F_173 ( V_198 ) = V_299 ;
return;
}
switch ( F_94 ( & V_92 -> V_151 ) ) {
case V_300 :
F_173 ( V_198 ) = V_301 ;
break;
case V_152 :
if ( F_105 ( V_302 , & V_92 -> V_34 ) )
F_173 ( V_198 ) = V_301 ;
else
F_173 ( V_198 ) = V_303 ;
break;
case V_153 :
F_173 ( V_198 ) = V_303 ;
break;
case V_156 :
F_173 ( V_198 ) = V_304 ;
break;
default:
F_173 ( V_198 ) = V_305 ;
break;
}
}
static int
F_174 ( struct V_306 * V_306 , bool V_307 )
{
int V_123 = 0 ;
T_6 V_308 = 0 ;
T_8 * V_92 = F_2 ( V_306 -> V_198 ) ;
T_8 * V_11 = NULL ;
struct V_13 * V_14 = V_92 -> V_15 ;
int V_41 ;
struct V_309 * V_310 = V_14 -> V_311 [ 0 ] ;
struct V_312 * V_313 ;
V_123 = F_175 ( V_306 ) ;
if ( V_123 ) {
F_9 ( V_47 , V_11 , 0x707e ,
L_75 , V_123 ) ;
return ( V_123 ) ;
}
V_11 = F_176 ( V_306 ) ;
if ( V_11 == NULL ) {
F_9 ( V_47 , V_11 , 0x707f , L_76 ) ;
return V_314 ;
}
if ( V_307 ) {
F_177 ( & V_11 -> V_315 , V_316 ) ;
F_178 ( V_306 , V_317 ) ;
} else
F_177 ( & V_11 -> V_315 , V_318 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_77 , V_11 -> V_219 ) ;
F_177 ( & V_11 -> V_151 , V_152 ) ;
V_11 -> V_319 = V_320 ;
V_11 -> V_321 = V_322 ;
if ( F_94 ( & V_92 -> V_151 ) == V_152 ||
F_94 ( & V_92 -> V_151 ) == V_153 ) {
F_21 ( V_32 , V_11 , 0x7081 ,
L_78 ) ;
F_177 ( & V_11 -> V_151 , V_153 ) ;
if ( ! V_307 )
F_178 ( V_306 , V_323 ) ;
}
if ( F_179 ( V_14 ) && V_324 ) {
if ( V_14 -> V_325 & V_326 ) {
int V_327 = 0 , V_328 ;
V_11 -> V_95 . V_329 = 1 ;
F_21 ( V_32 , V_11 , 0x7082 ,
L_79 ) ;
if ( V_324 == 1 )
V_327 = V_330 ;
F_180 ( V_11 -> V_94 ,
V_327 | V_331
| V_332
| V_333
| V_334
| V_335
| V_336 ) ;
V_328 = V_337 ;
if ( F_181 ( V_14 ) &&
( V_324 > 1 || F_182 ( V_14 ) ) )
V_328 |= V_338 ;
F_183 ( V_11 -> V_94 , V_328 ) ;
} else
V_11 -> V_95 . V_329 = 0 ;
}
if ( F_184 ( V_11 -> V_94 , & V_306 -> V_116 ,
& V_14 -> V_64 -> V_116 ) ) {
F_21 ( V_32 , V_11 , 0x7083 ,
L_80 , V_11 -> V_219 ) ;
goto V_339;
}
F_185 ( V_11 -> V_94 ) = V_14 -> V_340 ;
F_186 ( V_11 -> V_94 ) = F_142 ( V_11 -> V_229 ) ;
F_187 ( V_11 -> V_94 ) = F_142 ( V_11 -> V_233 ) ;
F_188 ( V_11 -> V_94 ) =
F_188 ( V_92 -> V_94 ) ;
F_189 ( V_11 -> V_94 ) =
F_189 ( V_92 -> V_94 ) ;
F_190 ( V_11 , V_14 ) ;
F_191 ( V_306 , V_307 ) ;
if ( ! V_341 || ! V_14 -> V_342 )
goto V_343;
for ( V_41 = 0 ; V_41 < V_14 -> V_344 ; V_41 ++ ) {
if ( memcmp ( V_14 -> V_342 [ V_41 ] . V_233 , V_11 -> V_233 , 8 ) == 0
&& memcmp ( V_14 -> V_342 [ V_41 ] . V_229 , V_11 -> V_229 ,
8 ) == 0 ) {
V_308 = V_14 -> V_342 [ V_41 ] . V_345 ;
break;
}
}
if ( V_308 ) {
V_313 = F_192 ( V_11 , V_308 , V_11 -> V_219 ) ;
if ( ! V_313 )
F_9 ( V_47 , V_11 , 0x7084 ,
L_81 ,
V_11 -> V_219 ) ;
else {
F_21 ( V_346 , V_11 , 0xc001 ,
L_82 ,
V_313 -> V_231 , V_308 , V_11 -> V_219 ) ;
F_21 ( V_32 , V_11 , 0x7085 ,
L_83 ,
V_313 -> V_231 , V_308 , V_11 -> V_219 ) ;
V_310 = V_313 -> V_310 ;
V_11 -> V_313 = V_313 ;
}
}
V_343:
V_11 -> V_310 = V_310 ;
return 0 ;
V_339:
F_193 ( V_11 ) ;
F_194 ( V_11 ) ;
F_195 ( V_11 -> V_94 ) ;
return V_314 ;
}
static int
F_196 ( struct V_306 * V_306 )
{
T_8 * V_11 = V_306 -> V_238 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_231 = V_11 -> V_219 ;
while ( F_105 ( V_347 , & V_11 -> V_34 ) ||
F_105 ( V_348 , & V_11 -> V_34 ) )
F_197 ( 1000 ) ;
F_193 ( V_11 ) ;
V_11 -> V_95 . V_349 = 1 ;
F_198 ( V_14 , V_11 ) ;
F_199 ( V_11 -> V_94 ) ;
F_200 ( V_11 -> V_94 ) ;
F_194 ( V_11 ) ;
if ( V_11 -> V_350 ) {
F_201 ( V_11 ) ;
F_21 ( V_32 , V_11 , 0x7086 ,
L_84 , V_11 -> V_219 ) ;
}
F_202 ( V_11 ) ;
F_34 ( & V_14 -> V_351 ) ;
V_14 -> V_352 -- ;
F_203 ( V_11 -> V_219 , V_14 -> V_353 ) ;
F_35 ( & V_14 -> V_351 ) ;
F_164 ( & V_14 -> V_64 -> V_116 , V_11 -> V_354 . V_60 , V_11 -> V_354 . V_355 ,
V_11 -> V_354 . V_356 ) ;
if ( V_11 -> V_313 && V_11 -> V_313 -> V_219 == V_11 -> V_219 ) {
if ( F_204 ( V_11 , V_11 -> V_313 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7087 ,
L_85 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_86 , V_231 ) ;
F_195 ( V_11 -> V_94 ) ;
return 0 ;
}
static int
F_191 ( struct V_306 * V_306 , bool V_307 )
{
T_8 * V_11 = V_306 -> V_238 ;
if ( V_307 )
F_193 ( V_11 ) ;
else
F_205 ( V_11 ) ;
return 0 ;
}
void
F_206 ( T_8 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_9 V_200 = V_201 ;
F_185 ( V_11 -> V_94 ) = V_14 -> V_340 ;
F_186 ( V_11 -> V_94 ) = F_142 ( V_11 -> V_229 ) ;
F_187 ( V_11 -> V_94 ) = F_142 ( V_11 -> V_233 ) ;
F_188 ( V_11 -> V_94 ) = V_14 -> V_357 . V_358 ?
( V_359 | V_360 ) : V_360 ;
F_207 ( V_11 -> V_94 ) = V_14 -> V_361 ;
F_208 ( V_11 -> V_94 ) = V_14 -> V_352 ;
if ( F_44 ( V_14 ) )
V_200 = V_212 ;
else if ( F_45 ( V_14 ) )
V_200 = V_214 | V_210 |
V_208 ;
else if ( F_43 ( V_14 ) )
V_200 = V_210 | V_208 |
V_206 | V_204 ;
else if ( F_42 ( V_14 ) )
V_200 = V_208 | V_206 |
V_204 ;
else if ( F_209 ( V_14 ) )
V_200 = V_206 | V_204 ;
else if ( F_86 ( V_14 ) )
V_200 = V_210 | V_208 |
V_206 | V_204 ;
else if ( F_46 ( V_14 ) )
V_200 = V_216 | V_214 |
V_210 ;
else
V_200 = V_204 ;
F_189 ( V_11 -> V_94 ) = V_200 ;
}
