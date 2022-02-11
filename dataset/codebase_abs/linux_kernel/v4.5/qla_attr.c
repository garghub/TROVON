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
if ( ! V_14 -> V_35 || ! V_14 -> V_36 )
return 0 ;
F_21 ( V_32 , V_11 , 0x70e2 ,
L_7 , V_8 , V_9 ) ;
return F_6 ( V_7 , V_9 , & V_8 ,
V_14 -> V_35 , V_14 -> V_36 ) ;
}
static T_1
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_37 ;
if ( V_8 == 0 ) {
if ( V_14 -> V_26 )
F_25 ( V_14 -> V_26 ) ;
if ( V_14 -> V_35 )
F_25 ( V_14 -> V_35 ) ;
V_14 -> V_26 = NULL ;
V_14 -> V_27 = 0 ;
V_14 -> V_35 = NULL ;
V_14 -> V_36 = 0 ;
V_37 = F_26 ( V_7 ) ;
F_21 ( V_32 , V_11 , 0x70d1 ,
L_8 , V_37 ) ;
V_14 -> V_35 = F_27 ( V_37 ) ;
if ( ! V_14 -> V_35 ) {
F_9 ( V_38 , V_11 , 0x70d2 ,
L_9 , V_37 ) ;
return - V_39 ;
}
V_14 -> V_36 = V_37 ;
}
if ( V_8 + V_9 > V_14 -> V_36 ) {
V_9 = V_14 -> V_36 - V_8 ;
F_21 ( V_32 , V_11 , 0x70d3 ,
L_10 , V_9 ) ;
}
F_21 ( V_32 , V_11 , 0x70d4 ,
L_11 , V_8 , V_9 ) ;
memcpy ( V_14 -> V_35 + V_8 , V_7 , V_9 ) ;
if ( V_8 + V_9 == V_14 -> V_36 ) {
V_37 = F_28 ( V_11 ) ;
F_21 ( V_32 , V_11 , 0x70d5 ,
L_12 , V_37 ) ;
V_14 -> V_26 = F_27 ( V_37 ) ;
if ( ! V_14 -> V_26 ) {
F_9 ( V_38 , V_11 , 0x70d6 ,
L_13 , V_37 ) ;
return - V_39 ;
}
V_14 -> V_27 = V_37 ;
}
return V_9 ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_30 ( V_40 ) )
return 0 ;
if ( F_31 ( V_14 ) )
V_14 -> V_41 -> V_42 ( V_11 , V_14 -> V_43 , V_14 -> V_44 << 2 ,
V_14 -> V_45 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_43 ,
V_14 -> V_45 ) ;
}
static T_1
F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_46 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 != V_14 -> V_45 ||
! V_14 -> V_41 -> V_47 )
return - V_48 ;
if ( F_33 ( V_14 ) ) {
T_4 * V_49 ;
T_4 V_50 ;
V_49 = ( T_4 * ) V_7 ;
V_50 = 0 ;
for ( V_46 = 0 ; V_46 < ( ( V_9 >> 2 ) - 1 ) ; V_46 ++ )
V_50 += F_34 ( * V_49 ++ ) ;
V_50 = ~ V_50 + 1 ;
* V_49 = F_35 ( V_50 ) ;
} else {
T_6 * V_49 ;
T_6 V_50 ;
V_49 = ( T_6 * ) V_7 ;
V_50 = 0 ;
for ( V_46 = 0 ; V_46 < V_9 - 1 ; V_46 ++ )
V_50 += * V_49 ++ ;
V_50 = ~ V_50 + 1 ;
* V_49 = V_50 ;
}
if ( F_36 ( V_11 ) != V_51 ) {
F_9 ( V_38 , V_11 , 0x705f ,
L_14 ) ;
return - V_52 ;
}
V_14 -> V_41 -> V_47 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_53 , V_9 ) ;
V_14 -> V_41 -> V_54 ( V_11 , ( T_6 * ) V_14 -> V_43 , V_14 -> V_53 ,
V_9 ) ;
F_21 ( V_32 , V_11 , 0x7060 ,
L_15 ) ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_37 ( V_11 ) ;
F_38 ( V_11 ) ;
return V_9 ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_1 V_16 = 0 ;
if ( V_14 -> V_55 != V_56 )
return 0 ;
F_40 ( & V_14 -> V_57 ) ;
V_16 = F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_58 ,
V_14 -> V_59 ) ;
F_41 ( & V_14 -> V_57 ) ;
return V_16 ;
}
static T_1
F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 -> V_55 != V_60 )
return - V_48 ;
if ( V_8 > V_14 -> V_59 )
return - V_61 ;
if ( V_8 + V_9 > V_14 -> V_59 )
V_9 = V_14 -> V_59 - V_8 ;
F_40 ( & V_14 -> V_57 ) ;
memcpy ( & V_14 -> V_58 [ V_8 ] , V_7 , V_9 ) ;
F_41 ( & V_14 -> V_57 ) ;
return V_9 ;
}
static T_1
F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_62 = 0 ;
T_4 V_37 = V_14 -> V_63 ;
int V_64 , V_65 ;
T_1 V_16 = V_9 ;
if ( V_8 )
return - V_48 ;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
return - V_52 ;
if ( sscanf ( V_7 , L_16 , & V_64 , & V_62 , & V_37 ) < 1 )
return - V_48 ;
if ( V_62 > V_14 -> V_63 )
return - V_48 ;
F_40 ( & V_14 -> V_57 ) ;
switch ( V_64 ) {
case 0 :
if ( V_14 -> V_55 != V_56 &&
V_14 -> V_55 != V_60 ) {
V_16 = - V_48 ;
goto V_67;
}
V_14 -> V_55 = V_68 ;
F_21 ( V_32 , V_11 , 0x7061 ,
L_17 ,
V_14 -> V_59 ) ;
F_25 ( V_14 -> V_58 ) ;
V_14 -> V_58 = NULL ;
break;
case 1 :
if ( V_14 -> V_55 != V_68 ) {
V_16 = - V_48 ;
goto V_67;
}
V_14 -> V_69 = V_62 ;
V_14 -> V_59 = V_62 + V_37 > V_14 -> V_63 ?
V_14 -> V_63 - V_62 : V_37 ;
V_14 -> V_55 = V_56 ;
V_14 -> V_58 = F_27 ( V_14 -> V_59 ) ;
if ( V_14 -> V_58 == NULL ) {
F_9 ( V_38 , V_11 , 0x7062 ,
L_18
L_19 , V_14 -> V_59 ) ;
V_14 -> V_55 = V_68 ;
V_16 = - V_39 ;
goto V_67;
}
if ( F_36 ( V_11 ) != V_51 ) {
F_9 ( V_38 , V_11 , 0x7063 ,
L_14 ) ;
V_16 = - V_52 ;
goto V_67;
}
F_21 ( V_32 , V_11 , 0x7064 ,
L_20 ,
V_14 -> V_69 , V_14 -> V_59 ) ;
memset ( V_14 -> V_58 , 0 , V_14 -> V_59 ) ;
V_14 -> V_41 -> V_42 ( V_11 , V_14 -> V_58 ,
V_14 -> V_69 , V_14 -> V_59 ) ;
break;
case 2 :
if ( V_14 -> V_55 != V_68 ) {
V_16 = - V_48 ;
goto V_67;
}
V_65 = 0 ;
if ( V_14 -> V_63 == V_70 && V_62 == 0 )
V_65 = 1 ;
else if ( V_62 == ( V_14 -> V_71 * 4 ) ||
V_62 == ( V_14 -> V_72 * 4 ) )
V_65 = 1 ;
else if ( F_46 ( V_14 ) || F_47 ( V_14 )
|| F_48 ( V_14 ) || F_49 ( V_14 )
|| F_50 ( V_14 ) )
V_65 = 1 ;
if ( ! V_65 ) {
F_9 ( V_38 , V_11 , 0x7065 ,
L_21 , V_62 , V_37 ) ;
V_16 = - V_48 ;
goto V_67;
}
V_14 -> V_69 = V_62 ;
V_14 -> V_59 = V_62 + V_37 > V_14 -> V_63 ?
V_14 -> V_63 - V_62 : V_37 ;
V_14 -> V_55 = V_60 ;
V_14 -> V_58 = F_27 ( V_14 -> V_59 ) ;
if ( V_14 -> V_58 == NULL ) {
F_9 ( V_38 , V_11 , 0x7066 ,
L_22
L_23 , V_14 -> V_59 ) ;
V_14 -> V_55 = V_68 ;
V_16 = - V_39 ;
goto V_67;
}
F_21 ( V_32 , V_11 , 0x7067 ,
L_24 ,
V_14 -> V_69 , V_14 -> V_59 ) ;
memset ( V_14 -> V_58 , 0 , V_14 -> V_59 ) ;
break;
case 3 :
if ( V_14 -> V_55 != V_60 ) {
V_16 = - V_48 ;
goto V_67;
}
if ( F_36 ( V_11 ) != V_51 ) {
F_9 ( V_38 , V_11 , 0x7068 ,
L_25 ) ;
V_16 = - V_52 ;
goto V_67;
}
F_21 ( V_32 , V_11 , 0x7069 ,
L_26 ,
V_14 -> V_69 , V_14 -> V_59 ) ;
V_14 -> V_41 -> V_73 ( V_11 , V_14 -> V_58 ,
V_14 -> V_69 , V_14 -> V_59 ) ;
break;
default:
V_16 = - V_48 ;
}
V_67:
F_41 ( & V_14 -> V_57 ) ;
return V_16 ;
}
static T_1
F_51 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
return - V_52 ;
if ( ! F_30 ( V_40 ) )
return - V_48 ;
if ( F_31 ( V_14 ) )
V_14 -> V_41 -> V_42 ( V_11 , V_14 -> V_74 , V_14 -> V_75 << 2 ,
V_14 -> V_76 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_74 , V_14 -> V_76 ) ;
}
static T_1
F_52 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_77 ;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
return 0 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 != V_14 -> V_76 ||
! V_14 -> V_41 -> V_47 )
return 0 ;
if ( F_36 ( V_11 ) != V_51 ) {
F_9 ( V_38 , V_11 , 0x706a ,
L_27 ) ;
return - V_52 ;
}
V_14 -> V_41 -> V_47 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_78 , V_9 ) ;
V_14 -> V_41 -> V_54 ( V_11 , ( T_6 * ) V_14 -> V_74 , V_14 -> V_78 , V_9 ) ;
if ( ! F_33 ( V_14 ) )
return - V_48 ;
V_77 = F_27 ( 256 ) ;
if ( ! V_77 ) {
F_9 ( V_38 , V_11 , 0x706b ,
L_28 ) ;
return - V_39 ;
}
V_14 -> V_41 -> V_79 ( V_11 , V_77 ) ;
F_25 ( V_77 ) ;
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
T_5 V_49 , V_80 , V_81 ;
int V_16 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 != V_82 * 2 )
return 0 ;
if ( V_14 -> V_83 )
goto V_84;
V_14 -> V_83 = F_54 ( V_14 -> V_85 , V_86 ,
& V_14 -> V_87 ) ;
if ( ! V_14 -> V_83 ) {
F_9 ( V_38 , V_11 , 0x706c ,
L_29 ) ;
return 0 ;
}
V_84:
memset ( V_14 -> V_83 , 0 , V_88 ) ;
V_80 = 0xa0 ;
for ( V_49 = 0 , V_81 = 0 ; V_49 < ( V_82 * 2 ) / V_88 ;
V_49 ++ , V_81 += V_88 ) {
if ( V_49 == 4 ) {
V_80 = 0xa2 ;
V_81 = 0 ;
}
V_16 = F_55 ( V_11 , V_14 -> V_87 , V_14 -> V_83 ,
V_80 , V_81 , V_88 , V_89 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x706d ,
L_30 , V_16 ,
V_80 , V_81 ) ;
return - V_90 ;
}
memcpy ( V_7 , V_14 -> V_83 , V_88 ) ;
V_7 += V_88 ;
}
return V_9 ;
}
static T_1
F_56 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_91 = F_57 ( V_14 -> V_66 ) ;
int type ;
T_4 V_92 ;
T_6 * V_77 = NULL ;
if ( V_8 != 0 )
return - V_48 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_29 , V_11 , 0x706e ,
L_31 ) ;
F_58 ( V_11 -> V_93 ) ;
if ( F_13 ( V_14 ) ) {
V_14 -> V_94 . V_95 = 1 ;
F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
F_16 ( V_14 ) ;
} else if ( F_17 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_92 = F_59 ( V_14 ,
V_96 ) ;
F_60 ( V_14 , V_96 ,
( V_92 | V_97 ) ) ;
F_15 ( V_11 ) ;
F_19 ( V_14 ) ;
} else {
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_37 ( V_11 ) ;
}
F_38 ( V_11 ) ;
F_61 ( V_11 -> V_93 ) ;
break;
case 0x2025d :
if ( ! F_62 ( V_14 ) && ! F_63 ( V_14 ) )
return - V_98 ;
F_9 ( V_29 , V_11 , 0x706f ,
L_32 ) ;
if ( F_63 ( V_14 ) || F_50 ( V_14 ) ) {
T_4 V_92 ;
F_64 ( V_11 , 0 ) ;
F_65 ( V_11 , & V_92 ) ;
V_92 |= V_99 ;
F_66 ( V_11 , V_92 ) ;
F_67 ( V_11 , V_100 ,
V_101 ) ;
F_68 ( V_11 , V_102 ) ;
F_69 ( V_11 , 0 ) ;
break;
} else {
F_36 ( V_11 ) ;
F_58 ( V_11 -> V_93 ) ;
if ( F_70 ( V_11 ) != V_51 )
F_9 ( V_38 , V_11 , 0x7070 ,
L_33 ) ;
F_61 ( V_11 -> V_93 ) ;
break;
}
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_91 ) {
F_9 ( V_29 , V_11 , 0x7071 ,
L_34 ) ;
return - V_98 ;
}
F_9 ( V_29 , V_11 , 0x7072 ,
L_35 ) ;
F_22 ( V_103 , & V_11 -> V_34 ) ;
F_37 ( V_11 ) ;
F_71 ( V_11 ) ;
break;
case 0x2025f :
if ( ! F_72 ( V_14 ) )
return - V_98 ;
F_9 ( V_29 , V_11 , 0x70bc ,
L_36 ) ;
F_64 ( V_11 , 0 ) ;
F_65 ( V_11 , & V_92 ) ;
V_92 |= V_104 ;
F_66 ( V_11 , V_92 ) ;
F_69 ( V_11 , 0 ) ;
break;
case 0x20260 :
if ( ! F_72 ( V_14 ) )
return - V_98 ;
F_9 ( V_29 , V_11 , 0x70bd ,
L_37 ) ;
F_64 ( V_11 , 0 ) ;
F_65 ( V_11 , & V_92 ) ;
V_92 &= ~ V_104 ;
F_66 ( V_11 , V_92 ) ;
F_69 ( V_11 , 0 ) ;
break;
case 0x20261 :
F_21 ( V_32 , V_11 , 0x70e0 ,
L_38 ) ;
V_77 = F_27 ( 256 ) ;
if ( ! V_77 ) {
F_9 ( V_38 , V_11 , 0x70e1 ,
L_28 ) ;
return - V_39 ;
}
V_14 -> V_41 -> V_79 ( V_11 , V_77 ) ;
F_25 ( V_77 ) ;
break;
}
return V_9 ;
}
static T_1
F_73 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
int type ;
int V_16 = 0 ;
T_7 V_105 ;
type = F_8 ( V_7 , NULL , 10 ) ;
V_105 . V_106 . V_107 = ( type & 0x00ff0000 ) >> 16 ;
V_105 . V_106 . V_108 = ( type & 0x0000ff00 ) >> 8 ;
V_105 . V_106 . V_109 = ( type & 0x000000ff ) ;
F_9 ( V_29 , V_11 , 0x70e3 , L_39 ,
V_105 . V_106 . V_107 , V_105 . V_106 . V_108 , V_105 . V_106 . V_109 ) ;
F_9 ( V_29 , V_11 , 0x70e4 , L_40 , V_110 , type ) ;
V_16 = F_74 ( V_11 , V_111 , V_105 ) ;
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
T_5 V_112 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 > V_113 )
return 0 ;
if ( V_14 -> V_114 )
goto V_84;
V_14 -> V_114 = F_76 ( & V_14 -> V_66 -> V_115 , V_113 ,
& V_14 -> V_116 , V_86 ) ;
if ( ! V_14 -> V_114 ) {
F_9 ( V_38 , V_11 , 0x7076 ,
L_41 ) ;
return 0 ;
}
V_84:
V_112 = 0 ;
memset ( V_14 -> V_114 , 0 , V_113 ) ;
V_16 = F_77 ( V_11 , V_14 -> V_116 ,
V_113 , & V_112 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x7077 ,
L_42 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_112 > V_9 ? V_9 : V_112 ;
memcpy ( V_7 , V_14 -> V_114 , V_9 ) ;
return V_9 ;
}
static T_1
F_78 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 > V_117 )
return 0 ;
if ( V_14 -> V_118 )
goto V_84;
V_14 -> V_118 = F_76 ( & V_14 -> V_66 -> V_115 , V_117 ,
& V_14 -> V_119 , V_86 ) ;
if ( ! V_14 -> V_118 ) {
F_9 ( V_38 , V_11 , 0x7078 ,
L_43 ) ;
return - V_39 ;
}
V_84:
memset ( V_14 -> V_118 , 0 , V_117 ) ;
V_16 = F_79 ( V_11 , V_14 -> V_119 ,
V_117 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x7079 ,
L_44 , V_16 ) ;
return - V_90 ;
}
memcpy ( V_7 , V_14 -> V_118 , V_9 ) ;
return V_9 ;
}
void
F_80 ( T_8 * V_11 )
{
struct V_120 * V_93 = V_11 -> V_93 ;
struct V_121 * V_49 ;
int V_122 ;
for ( V_49 = V_123 ; V_49 -> V_124 ; V_49 ++ ) {
if ( V_49 -> V_125 && ! F_33 ( V_11 -> V_15 ) )
continue;
if ( V_49 -> V_125 == 2 && ! F_47 ( V_11 -> V_15 ) )
continue;
if ( V_49 -> V_125 == 3 && ! ( F_48 ( V_11 -> V_15 ) ) )
continue;
if ( V_49 -> V_125 == 0x27 && ! F_50 ( V_11 -> V_15 ) )
continue;
V_122 = F_81 ( & V_93 -> V_126 . V_4 ,
V_49 -> V_127 ) ;
if ( V_122 )
F_9 ( V_38 , V_11 , 0x00f3 ,
L_45 ,
V_49 -> V_124 , V_122 ) ;
else
F_21 ( V_128 , V_11 , 0x00f4 ,
L_46 ,
V_49 -> V_124 ) ;
}
}
void
F_82 ( T_8 * V_11 , bool V_129 )
{
struct V_120 * V_93 = V_11 -> V_93 ;
struct V_121 * V_49 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_49 = V_123 ; V_49 -> V_124 ; V_49 ++ ) {
if ( V_49 -> V_125 && ! F_33 ( V_14 ) )
continue;
if ( V_49 -> V_125 == 2 && ! F_47 ( V_14 ) )
continue;
if ( V_49 -> V_125 == 3 && ! ( F_48 ( V_11 -> V_15 ) ) )
continue;
if ( V_49 -> V_125 == 0x27 && ! F_50 ( V_11 -> V_15 ) )
continue;
F_83 ( & V_93 -> V_126 . V_4 ,
V_49 -> V_127 ) ;
}
if ( V_129 && V_14 -> V_130 == 1 )
V_14 -> V_41 -> V_131 ( V_11 ) ;
}
static T_1
F_84 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
return F_85 ( V_7 , V_133 , L_47 , V_134 ) ;
}
static T_1
F_86 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_135 [ 128 ] ;
return F_85 ( V_7 , V_133 , L_47 ,
V_14 -> V_41 -> V_136 ( V_11 , V_135 , sizeof( V_135 ) ) ) ;
}
static T_1
F_88 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_137 ;
if ( F_89 ( V_11 -> V_15 ) ) {
return F_85 ( V_7 , V_133 , L_47 ,
V_11 -> V_15 -> V_138 . V_139 ) ;
} else if ( F_33 ( V_14 ) ) {
F_90 ( V_11 , L_48 , V_7 , V_133 - 1 ) ;
return strlen ( strcat ( V_7 , L_49 ) ) ;
}
V_137 = ( ( V_14 -> V_140 & 0x1f ) << 16 ) | ( V_14 -> V_141 << 8 ) | V_14 -> V_142 ;
return F_85 ( V_7 , V_133 , L_50 , 'A' + V_137 / 100000 ,
V_137 % 100000 ) ;
}
static T_1
F_91 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
return F_85 ( V_7 , V_133 , L_51 , V_11 -> V_15 -> V_66 -> V_12 ) ;
}
static T_1
F_92 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_89 ( V_11 -> V_15 ) )
return F_85 ( V_7 , V_133 , L_47 ,
V_11 -> V_15 -> V_138 . V_143 ) ;
return F_85 ( V_7 , V_133 , L_52 ,
V_14 -> V_144 [ 0 ] , V_14 -> V_144 [ 1 ] , V_14 -> V_144 [ 2 ] ,
V_14 -> V_144 [ 3 ] ) ;
}
static T_1
F_93 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
return F_85 ( V_7 , V_133 , L_47 , V_11 -> V_15 -> V_145 ) ;
}
static T_1
F_94 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
return F_85 ( V_7 , V_133 , L_47 , V_11 -> V_15 -> V_146 ) ;
}
static T_1
F_95 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
char V_147 [ 30 ] ;
return F_85 ( V_7 , V_133 , L_47 ,
V_11 -> V_15 -> V_41 -> V_148 ( V_11 , V_147 ) ) ;
}
static T_1
F_96 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_149 = 0 ;
if ( F_97 ( & V_11 -> V_150 ) == V_151 ||
F_97 ( & V_11 -> V_150 ) == V_152 ||
V_11 -> V_153 & V_154 )
V_149 = F_85 ( V_7 , V_133 , L_53 ) ;
else if ( F_97 ( & V_11 -> V_150 ) != V_155 ||
F_98 ( V_11 ) )
V_149 = F_85 ( V_7 , V_133 , L_54 ) ;
else {
V_149 = F_85 ( V_7 , V_133 , L_55 ) ;
switch ( V_14 -> V_156 ) {
case V_157 :
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_56 ) ;
break;
case V_158 :
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_57 ) ;
break;
case V_159 :
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 ,
L_58 ) ;
break;
case V_160 :
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_59 ) ;
break;
default:
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_56 ) ;
break;
}
}
return V_149 ;
}
static T_1
F_99 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
int V_149 = 0 ;
switch ( V_11 -> V_15 -> V_161 ) {
case V_162 :
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_60 ) ;
break;
case V_163 :
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_61 ) ;
break;
}
return V_149 ;
}
static T_1
F_100 ( struct V_12 * V_115 , struct V_132 * V_127 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_64 = 0 ;
T_5 V_161 ;
if ( ! F_101 ( V_14 ) )
return - V_164 ;
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 )
V_161 = V_162 ;
else
V_161 = V_163 ;
if ( V_161 != V_163 || V_14 -> V_161 != V_163 ) {
V_14 -> V_161 = V_161 ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_102 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
return F_85 ( V_7 , V_133 , L_63 , V_11 -> V_15 -> V_165 * 100 ) ;
}
static T_1
F_103 ( struct V_12 * V_115 , struct V_132 * V_127 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
int V_64 = 0 ;
T_5 V_165 ;
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 > 25500 || V_64 < 100 )
return - V_61 ;
V_165 = ( T_5 ) ( V_64 / 100 ) ;
V_11 -> V_15 -> V_165 = V_165 ;
return strlen ( V_7 ) ;
}
static T_1
F_104 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
int V_149 = 0 ;
if ( V_11 -> V_15 -> V_130 )
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_64 ) ;
else
V_149 += F_85 ( V_7 + V_149 , V_133 - V_149 , L_61 ) ;
return V_149 ;
}
static T_1
F_105 ( struct V_12 * V_115 , struct V_132 * V_127 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_64 = 0 ;
int V_16 ;
if ( F_106 ( V_14 ) || F_107 ( V_14 ) )
return - V_98 ;
if ( F_108 ( V_166 , & V_11 -> V_34 ) ) {
F_9 ( V_38 , V_11 , 0x707a ,
L_65 ) ;
return - V_167 ;
}
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 )
V_16 = V_14 -> V_41 -> V_168 ( V_11 ) ;
else
V_16 = V_14 -> V_41 -> V_131 ( V_11 ) ;
if ( V_16 != V_51 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_109 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_85 ( V_7 , V_133 , L_66 , V_14 -> V_169 [ 1 ] ,
V_14 -> V_169 [ 0 ] ) ;
}
static T_1
F_110 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_85 ( V_7 , V_133 , L_66 , V_14 -> V_170 [ 1 ] ,
V_14 -> V_170 [ 0 ] ) ;
}
static T_1
F_111 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_85 ( V_7 , V_133 , L_66 , V_14 -> V_171 [ 1 ] ,
V_14 -> V_171 [ 0 ] ) ;
}
static T_1
F_112 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_85 ( V_7 , V_133 , L_67 ,
V_14 -> V_172 [ 0 ] , V_14 -> V_172 [ 1 ] , V_14 -> V_172 [ 2 ] ,
V_14 -> V_172 [ 3 ] ) ;
}
static T_1
F_113 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_62 ( V_14 ) && ! F_63 ( V_14 ) && ! F_50 ( V_14 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_68 ,
V_14 -> V_173 [ 0 ] , V_14 -> V_173 [ 1 ] ,
V_14 -> V_173 [ 2 ] , V_14 -> V_173 [ 3 ] ) ;
}
static T_1
F_114 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
return F_85 ( V_7 , V_133 , L_69 ,
V_11 -> V_174 . V_175 ) ;
}
static T_1
F_115 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
int V_16 = V_51 ;
T_5 V_176 [ 2 ] = { 0 , 0 } ;
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_116 ( V_14 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
if ( V_14 -> V_177 -> V_178 == 0 )
V_16 = F_117 ( V_11 , V_176 ) ;
if ( ( V_16 == V_51 ) && ( V_176 [ 0 ] == 0 ) )
return F_85 ( V_7 , V_133 , L_70 ,
( T_4 ) V_14 -> V_177 -> V_178 ) ;
return F_85 ( V_7 , V_133 , L_49 ) ;
}
static T_1
F_118 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_62 ( V_14 ) && ! F_72 ( V_14 ) && ! F_17 ( V_14 ) &&
! F_50 ( V_14 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_71 ,
V_14 -> V_179 [ 0 ] , V_14 -> V_179 [ 1 ] , V_14 -> V_179 [ 2 ] ,
V_14 -> V_180 ) ;
}
static T_1
F_119 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_62 ( V_14 ) && ! F_72 ( V_14 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_72 ,
V_14 -> V_181 [ 0 ] , V_14 -> V_181 [ 1 ] , V_14 -> V_181 [ 2 ] ) ;
}
static T_1
F_120 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_85 ( V_7 , V_133 , L_73 , V_14 -> V_182 ) ;
}
static T_1
F_121 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
if ( ! F_48 ( V_11 -> V_15 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_69 , V_11 -> V_183 ) ;
}
static T_1
F_122 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
if ( ! F_48 ( V_11 -> V_15 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_74 , V_11 -> V_184 ) ;
}
static T_1
F_123 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
return F_85 ( V_7 , V_133 , L_69 , V_11 -> V_15 -> V_185 ) ;
}
static T_1
F_124 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
T_5 V_186 = 0 ;
if ( F_98 ( V_11 ) ) {
F_9 ( V_38 , V_11 , 0x70dc , L_75 ) ;
goto V_187;
}
if ( V_11 -> V_15 -> V_94 . V_188 ) {
F_9 ( V_38 , V_11 , 0x70dd , L_76 ) ;
goto V_187;
}
if ( F_125 ( V_11 , & V_186 ) == V_51 )
return F_85 ( V_7 , V_133 , L_69 , V_186 ) ;
V_187:
return F_85 ( V_7 , V_133 , L_49 ) ;
}
static T_1
F_126 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
int V_16 = V_189 ;
T_5 V_190 [ 6 ] ;
T_4 V_191 ;
if ( F_89 ( V_11 -> V_15 ) ) {
V_191 = F_127 ( V_115 , V_127 , V_7 ) ;
return F_85 ( V_7 , V_133 , L_73 , V_191 ) ;
}
if ( F_98 ( V_11 ) )
F_9 ( V_38 , V_11 , 0x707c ,
L_75 ) ;
else if ( ! V_11 -> V_15 -> V_94 . V_188 )
V_16 = F_128 ( V_11 , V_190 ) ;
if ( V_16 != V_51 )
memset ( V_190 , - 1 , sizeof( V_190 ) ) ;
return F_85 ( V_7 , V_133 , L_77 ,
V_190 [ 0 ] , V_190 [ 1 ] , V_190 [ 2 ] , V_190 [ 3 ] , V_190 [ 4 ] , V_190 [ 5 ] ) ;
}
static T_1
F_129 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
if ( ! F_130 ( V_11 -> V_15 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_78 , V_11 -> V_192 . V_193 ) ;
}
static T_1
F_131 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
if ( ! F_130 ( V_11 -> V_15 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_78 ,
V_11 -> V_192 . V_194 >> 20 ) ;
}
static T_1
F_132 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_37 ;
if ( ! V_14 -> V_31 )
V_37 = 0 ;
else if ( F_5 ( V_14 ) )
V_37 = V_14 -> V_19 + V_14 -> V_22 ;
else
V_37 = V_14 -> V_27 ;
return F_85 ( V_7 , V_133 , L_69 , V_37 ) ;
}
static T_1
F_133 ( struct V_12 * V_115 ,
struct V_132 * V_127 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
if ( ! F_5 ( V_11 -> V_15 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
else
return F_85 ( V_7 , V_133 , L_47 ,
V_11 -> V_15 -> V_195 ? L_79 : L_80 ) ;
}
static T_1
F_134 ( struct V_12 * V_115 ,
struct V_132 * V_127 , const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
int V_64 = 0 ;
if ( ! F_5 ( V_11 -> V_15 ) )
return - V_48 ;
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
V_11 -> V_15 -> V_195 = V_64 != 0 ;
return strlen ( V_7 ) ;
}
static T_1
F_135 ( struct V_12 * V_115 , struct V_132 * V_127 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_87 ( V_115 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_50 ( V_14 ) )
return F_85 ( V_7 , V_133 , L_49 ) ;
return F_85 ( V_7 , V_133 , L_72 ,
V_14 -> V_196 [ 0 ] , V_14 -> V_196 [ 1 ] , V_14 -> V_196 [ 2 ] ) ;
}
static void
F_136 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
F_137 ( V_197 ) = V_11 -> V_198 . V_106 . V_107 << 16 |
V_11 -> V_198 . V_106 . V_108 << 8 | V_11 -> V_198 . V_106 . V_109 ;
}
static void
F_138 ( struct V_120 * V_197 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_197 ) ) ) -> V_15 ;
T_9 V_199 = V_200 ;
if ( F_89 ( V_14 ) ) {
F_139 ( V_197 ) ;
return;
}
switch ( V_14 -> V_201 ) {
case V_202 :
V_199 = V_203 ;
break;
case V_204 :
V_199 = V_205 ;
break;
case V_206 :
V_199 = V_207 ;
break;
case V_208 :
V_199 = V_209 ;
break;
case V_210 :
V_199 = V_211 ;
break;
case V_212 :
V_199 = V_213 ;
break;
case V_214 :
V_199 = V_215 ;
break;
}
F_140 ( V_197 ) = V_199 ;
}
static void
F_141 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
T_4 V_216 = V_217 ;
if ( V_11 -> V_218 ) {
F_142 ( V_197 ) = V_219 ;
return;
}
switch ( V_11 -> V_15 -> V_156 ) {
case V_157 :
V_216 = V_220 ;
break;
case V_158 :
V_216 = V_221 ;
break;
case V_159 :
V_216 = V_222 ;
break;
case V_160 :
V_216 = V_223 ;
break;
}
F_142 ( V_197 ) = V_216 ;
}
static void
F_143 ( struct V_224 * V_225 )
{
struct V_120 * V_93 = F_3 ( V_225 -> V_115 . V_226 ) ;
T_8 * V_11 = F_2 ( V_93 ) ;
T_10 * V_227 ;
T_11 V_228 = 0 ;
F_144 (fcport, &vha->vp_fcports, list) {
if ( V_227 -> V_229 &&
V_225 -> V_230 == V_227 -> V_229 -> V_231 ) {
V_228 = F_145 ( V_227 -> V_228 ) ;
break;
}
}
F_146 ( V_225 ) = V_228 ;
}
static void
F_147 ( struct V_224 * V_225 )
{
struct V_120 * V_93 = F_3 ( V_225 -> V_115 . V_226 ) ;
T_8 * V_11 = F_2 ( V_93 ) ;
T_10 * V_227 ;
T_11 V_232 = 0 ;
F_144 (fcport, &vha->vp_fcports, list) {
if ( V_227 -> V_229 &&
V_225 -> V_230 == V_227 -> V_229 -> V_231 ) {
V_232 = F_145 ( V_227 -> V_232 ) ;
break;
}
}
F_148 ( V_225 ) = V_232 ;
}
static void
F_149 ( struct V_224 * V_225 )
{
struct V_120 * V_93 = F_3 ( V_225 -> V_115 . V_226 ) ;
T_8 * V_11 = F_2 ( V_93 ) ;
T_10 * V_227 ;
T_4 V_233 = ~ 0U ;
F_144 (fcport, &vha->vp_fcports, list) {
if ( V_227 -> V_229 &&
V_225 -> V_230 == V_227 -> V_229 -> V_231 ) {
V_233 = V_227 -> V_198 . V_106 . V_107 << 16 |
V_227 -> V_198 . V_106 . V_108 << 8 | V_227 -> V_198 . V_106 . V_109 ;
break;
}
}
F_150 ( V_225 ) = V_233 ;
}
static void
F_151 ( struct V_234 * V_229 , T_4 V_235 )
{
if ( V_235 )
V_229 -> V_236 = V_235 ;
else
V_229 -> V_236 = 1 ;
}
static void
F_152 ( struct V_234 * V_229 )
{
struct V_120 * V_93 = F_153 ( V_229 ) ;
T_10 * V_227 = * ( T_10 * * ) V_229 -> V_237 ;
unsigned long V_94 ;
if ( ! V_227 )
return;
F_154 ( V_227 , V_238 ) ;
F_155 ( V_93 -> V_239 , V_94 ) ;
V_227 -> V_229 = V_227 -> V_240 = NULL ;
* ( ( T_10 * * ) V_229 -> V_237 ) = NULL ;
F_156 ( V_93 -> V_239 , V_94 ) ;
if ( F_108 ( V_166 , & V_227 -> V_11 -> V_34 ) )
return;
if ( F_44 ( F_45 ( V_227 -> V_11 -> V_15 -> V_66 ) ) ) {
F_157 ( V_227 -> V_11 , V_241 << 16 ) ;
return;
}
}
static void
F_158 ( struct V_234 * V_229 )
{
T_10 * V_227 = * ( T_10 * * ) V_229 -> V_237 ;
if ( ! V_227 )
return;
if ( F_108 ( V_166 , & V_227 -> V_11 -> V_34 ) )
return;
if ( F_44 ( F_45 ( V_227 -> V_11 -> V_15 -> V_66 ) ) ) {
F_157 ( V_227 -> V_11 , V_241 << 16 ) ;
return;
}
if ( V_227 -> V_242 != V_243 ) {
if ( F_33 ( V_227 -> V_11 -> V_15 ) )
V_227 -> V_11 -> V_15 -> V_41 -> V_244 ( V_227 -> V_11 ,
V_227 -> V_242 , V_227 -> V_198 . V_106 . V_107 ,
V_227 -> V_198 . V_106 . V_108 , V_227 -> V_198 . V_106 . V_109 ) ;
else
F_159 ( V_227 -> V_11 , V_227 ) ;
}
}
static int
F_160 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
if ( F_89 ( V_11 -> V_15 ) )
return 0 ;
F_161 ( V_11 ) ;
return 0 ;
}
static struct V_245 *
F_162 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_91 = F_57 ( V_14 -> V_66 ) ;
int V_16 ;
struct V_246 * V_247 ;
T_12 V_248 ;
struct V_245 * V_249 ;
V_249 = & V_11 -> V_250 ;
memset ( V_249 , - 1 , sizeof( struct V_245 ) ) ;
if ( F_89 ( V_11 -> V_15 ) )
goto V_187;
if ( F_108 ( V_251 , & V_11 -> V_34 ) )
goto V_187;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
goto V_187;
if ( F_98 ( V_11 ) )
goto V_187;
V_247 = F_54 ( V_14 -> V_85 , V_86 , & V_248 ) ;
if ( V_247 == NULL ) {
F_9 ( V_38 , V_11 , 0x707d ,
L_81 ) ;
goto V_187;
}
memset ( V_247 , 0 , V_252 ) ;
V_16 = V_189 ;
if ( F_33 ( V_14 ) ) {
V_16 = F_163 ( V_91 , V_247 , V_248 ) ;
} else if ( F_97 ( & V_91 -> V_150 ) == V_155 &&
! V_14 -> V_253 ) {
V_16 = F_164 ( V_91 , V_91 -> V_242 ,
V_247 , V_248 ) ;
}
if ( V_16 != V_51 )
goto V_254;
V_249 -> V_255 = V_247 -> V_256 ;
V_249 -> V_257 = V_247 -> V_258 ;
V_249 -> V_259 = V_247 -> V_260 ;
V_249 -> V_261 = V_247 -> V_262 ;
V_249 -> V_263 = V_247 -> V_264 ;
V_249 -> V_265 = V_247 -> V_266 ;
if ( F_33 ( V_14 ) ) {
V_249 -> V_267 = V_247 -> V_268 ;
V_249 -> V_269 = V_247 -> V_269 ;
V_249 -> V_270 = V_247 -> V_270 ;
V_249 -> V_271 = V_247 -> V_272 ;
V_249 -> V_273 = V_247 -> V_274 ;
V_249 -> V_275 =
V_247 -> V_276 + V_247 -> V_272 ;
V_249 -> V_277 = V_11 -> V_174 . V_278 ;
V_249 -> V_279 = V_11 -> V_174 . V_280 ;
}
V_249 -> V_281 = V_11 -> V_174 . V_282 ;
V_249 -> V_283 = V_11 -> V_174 . V_284 ;
V_249 -> V_285 = V_11 -> V_174 . V_286 ;
V_249 -> V_287 = V_11 -> V_174 . V_278 >> 20 ;
V_249 -> V_288 = V_11 -> V_174 . V_280 >> 20 ;
V_249 -> V_289 =
F_165 () - V_11 -> V_174 . V_290 ;
F_166 ( V_249 -> V_289 , V_291 ) ;
V_254:
F_167 ( V_14 -> V_85 , V_247 , V_248 ) ;
V_187:
return V_249 ;
}
static void
F_168 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
memset ( & V_11 -> V_250 , 0 , sizeof( V_11 -> V_250 ) ) ;
V_11 -> V_174 . V_290 = F_165 () ;
}
static void
F_169 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
F_170 ( V_11 , F_171 ( V_197 ) ,
sizeof( F_171 ( V_197 ) ) ) ;
}
static void
F_172 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
F_22 ( V_292 , & V_11 -> V_34 ) ;
}
static void
F_173 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
T_6 V_228 [ V_293 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_11 V_294 = F_145 ( V_228 ) ;
if ( V_11 -> V_153 & V_295 )
V_294 = F_145 ( V_11 -> V_296 ) ;
F_174 ( V_197 ) = V_294 ;
}
static void
F_175 ( struct V_120 * V_197 )
{
T_8 * V_11 = F_2 ( V_197 ) ;
struct V_10 * V_91 = F_57 ( V_11 -> V_15 -> V_66 ) ;
if ( ! V_91 -> V_94 . V_297 ) {
F_176 ( V_197 ) = V_298 ;
return;
}
switch ( F_97 ( & V_91 -> V_150 ) ) {
case V_299 :
F_176 ( V_197 ) = V_300 ;
break;
case V_151 :
if ( F_108 ( V_301 , & V_91 -> V_34 ) )
F_176 ( V_197 ) = V_300 ;
else
F_176 ( V_197 ) = V_302 ;
break;
case V_152 :
F_176 ( V_197 ) = V_302 ;
break;
case V_155 :
F_176 ( V_197 ) = V_303 ;
break;
default:
F_176 ( V_197 ) = V_304 ;
break;
}
}
static int
F_177 ( struct V_305 * V_305 , bool V_306 )
{
int V_122 = 0 ;
T_6 V_307 = 0 ;
T_8 * V_91 = F_2 ( V_305 -> V_197 ) ;
T_8 * V_11 = NULL ;
struct V_13 * V_14 = V_91 -> V_15 ;
T_5 V_308 = 0 ;
int V_46 ;
struct V_309 * V_310 = V_14 -> V_311 [ 0 ] ;
V_122 = F_178 ( V_305 ) ;
if ( V_122 ) {
F_9 ( V_38 , V_11 , 0x707e ,
L_82 , V_122 ) ;
return ( V_122 ) ;
}
V_11 = F_179 ( V_305 ) ;
if ( V_11 == NULL ) {
F_9 ( V_38 , V_11 , 0x707f , L_83 ) ;
return V_312 ;
}
if ( V_306 ) {
F_180 ( & V_11 -> V_313 , V_314 ) ;
F_181 ( V_305 , V_315 ) ;
} else
F_180 ( & V_11 -> V_313 , V_316 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_84 , V_11 -> V_218 ) ;
F_180 ( & V_11 -> V_150 , V_151 ) ;
V_11 -> V_317 = V_318 ;
V_11 -> V_319 = V_320 ;
if ( F_97 ( & V_91 -> V_150 ) == V_151 ||
F_97 ( & V_91 -> V_150 ) == V_152 ) {
F_21 ( V_32 , V_11 , 0x7081 ,
L_85 ) ;
F_180 ( & V_11 -> V_150 , V_152 ) ;
if ( ! V_306 )
F_181 ( V_305 , V_321 ) ;
}
if ( F_182 ( V_14 ) && V_322 ) {
if ( V_14 -> V_323 & V_324 ) {
int V_325 = 0 , V_326 ;
V_11 -> V_94 . V_327 = 1 ;
F_21 ( V_32 , V_11 , 0x7082 ,
L_86 ) ;
if ( V_322 == 1 )
V_325 = V_328 ;
F_183 ( V_11 -> V_93 ,
V_325 | V_329
| V_330
| V_331
| V_332
| V_333
| V_334 ) ;
V_326 = V_335 ;
if ( F_184 ( V_14 ) &&
( V_322 > 1 || F_185 ( V_14 ) ) )
V_326 |= V_336 ;
F_186 ( V_11 -> V_93 , V_326 ) ;
} else
V_11 -> V_94 . V_327 = 0 ;
}
if ( F_187 ( V_11 -> V_93 , & V_305 -> V_115 ,
& V_14 -> V_66 -> V_115 ) ) {
F_21 ( V_32 , V_11 , 0x7083 ,
L_87 , V_11 -> V_218 ) ;
goto V_337;
}
F_188 ( V_11 -> V_93 ) = V_14 -> V_338 ;
F_189 ( V_11 -> V_93 ) = F_145 ( V_11 -> V_228 ) ;
F_190 ( V_11 -> V_93 ) = F_145 ( V_11 -> V_232 ) ;
F_191 ( V_11 -> V_93 ) =
F_191 ( V_91 -> V_93 ) ;
F_192 ( V_11 -> V_93 ) =
F_192 ( V_91 -> V_93 ) ;
F_193 ( V_11 , V_14 ) ;
F_194 ( V_305 , V_306 ) ;
if ( V_14 -> V_94 . V_339 ) {
V_310 = V_14 -> V_311 [ 1 ] ;
F_21 ( V_340 , V_11 , 0xc000 ,
L_88
L_89 ,
V_310 , V_11 -> V_218 , V_14 -> V_94 . V_339 ) ;
goto V_341;
} else if ( V_342 == 1 || ! V_14 -> V_343 )
goto V_341;
for ( V_46 = 0 ; V_46 < V_14 -> V_344 ; V_46 ++ ) {
if ( memcmp ( V_14 -> V_343 [ V_46 ] . V_232 , V_11 -> V_232 , 8 ) == 0
&& memcmp ( V_14 -> V_343 [ V_46 ] . V_228 , V_11 -> V_228 ,
8 ) == 0 ) {
V_307 = V_14 -> V_343 [ V_46 ] . V_345 ;
break;
}
}
if ( V_307 ) {
V_122 = F_195 ( V_14 , V_308 , V_11 -> V_218 , 0 , 0 ,
V_307 ) ;
if ( ! V_122 )
F_9 ( V_38 , V_11 , 0x7084 ,
L_90 ,
V_11 -> V_218 ) ;
else {
F_21 ( V_340 , V_11 , 0xc001 ,
L_91 ,
V_122 , V_307 , V_11 -> V_218 ) ;
F_21 ( V_32 , V_11 , 0x7085 ,
L_91 ,
V_122 , V_307 , V_11 -> V_218 ) ;
V_310 = V_14 -> V_311 [ V_122 ] ;
}
}
V_341:
V_11 -> V_310 = V_310 ;
return 0 ;
V_337:
F_196 ( V_11 ) ;
F_197 ( V_11 ) ;
F_198 ( V_11 -> V_93 ) ;
return V_312 ;
}
static int
F_199 ( struct V_305 * V_305 )
{
T_8 * V_11 = V_305 -> V_237 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_230 = V_11 -> V_218 ;
while ( F_108 ( V_346 , & V_11 -> V_34 ) ||
F_108 ( V_347 , & V_11 -> V_34 ) )
F_200 ( 1000 ) ;
F_196 ( V_11 ) ;
V_11 -> V_94 . V_348 = 1 ;
F_201 ( V_14 , V_11 ) ;
F_202 ( V_11 -> V_93 ) ;
F_203 ( V_11 -> V_93 ) ;
F_197 ( V_11 ) ;
if ( V_11 -> V_349 ) {
F_204 ( V_11 ) ;
F_21 ( V_32 , V_11 , 0x7086 ,
L_92 , V_11 -> V_218 ) ;
}
F_205 ( F_97 ( & V_11 -> V_350 ) ) ;
F_206 ( V_11 ) ;
F_40 ( & V_14 -> V_351 ) ;
V_14 -> V_352 -- ;
F_207 ( V_11 -> V_218 , V_14 -> V_353 ) ;
F_41 ( & V_14 -> V_351 ) ;
if ( V_11 -> V_310 -> V_230 && ! V_14 -> V_94 . V_339 ) {
if ( F_208 ( V_11 , V_11 -> V_310 ) != V_51 )
F_9 ( V_38 , V_11 , 0x7087 ,
L_93 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_94 , V_230 ) ;
F_198 ( V_11 -> V_93 ) ;
return 0 ;
}
static int
F_194 ( struct V_305 * V_305 , bool V_306 )
{
T_8 * V_11 = V_305 -> V_237 ;
if ( V_306 )
F_196 ( V_11 ) ;
else
F_209 ( V_11 ) ;
return 0 ;
}
void
F_210 ( T_8 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_9 V_199 = V_200 ;
F_188 ( V_11 -> V_93 ) = V_14 -> V_338 ;
F_189 ( V_11 -> V_93 ) = F_145 ( V_11 -> V_228 ) ;
F_190 ( V_11 -> V_93 ) = F_145 ( V_11 -> V_232 ) ;
F_191 ( V_11 -> V_93 ) = V_14 -> V_354 . V_355 ?
( V_356 | V_357 ) : V_357 ;
F_211 ( V_11 -> V_93 ) = V_14 -> V_358 ;
F_212 ( V_11 -> V_93 ) = V_14 -> V_352 ;
if ( F_48 ( V_14 ) )
V_199 = V_211 ;
else if ( F_49 ( V_14 ) )
V_199 = V_213 | V_209 |
V_207 ;
else if ( F_47 ( V_14 ) )
V_199 = V_209 | V_207 |
V_205 | V_203 ;
else if ( F_46 ( V_14 ) )
V_199 = V_207 | V_205 |
V_203 ;
else if ( F_213 ( V_14 ) )
V_199 = V_205 | V_203 ;
else if ( F_89 ( V_14 ) )
V_199 = V_209 | V_207 |
V_205 | V_203 ;
else if ( F_50 ( V_14 ) )
V_199 = V_215 | V_213 |
V_209 ;
else
V_199 = V_203 ;
F_192 ( V_11 -> V_93 ) = V_199 ;
}
