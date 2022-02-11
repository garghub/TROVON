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
|| F_48 ( V_14 ) || F_49 ( V_14 ) )
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
F_50 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_51 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_52 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
V_14 -> V_83 = F_53 ( V_14 -> V_85 , V_86 ,
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
V_16 = F_54 ( V_11 , V_14 -> V_87 , V_14 -> V_83 ,
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
F_55 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_91 = F_56 ( V_14 -> V_66 ) ;
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
F_57 ( V_11 -> V_93 ) ;
if ( F_13 ( V_14 ) ) {
V_14 -> V_94 . V_95 = 1 ;
F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
F_16 ( V_14 ) ;
} else if ( F_17 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_92 = F_58 ( V_14 ,
V_96 ) ;
F_59 ( V_14 , V_96 ,
( V_92 | V_97 ) ) ;
F_15 ( V_11 ) ;
F_19 ( V_14 ) ;
} else {
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_37 ( V_11 ) ;
}
F_38 ( V_11 ) ;
F_60 ( V_11 -> V_93 ) ;
break;
case 0x2025d :
if ( ! F_61 ( V_14 ) && ! F_62 ( V_14 ) )
return - V_98 ;
F_9 ( V_29 , V_11 , 0x706f ,
L_32 ) ;
if ( F_62 ( V_14 ) ) {
T_4 V_92 ;
F_63 ( V_11 , 0 ) ;
F_64 ( V_11 , & V_92 ) ;
V_92 |= V_99 ;
F_65 ( V_11 , V_92 ) ;
F_66 ( V_11 , V_100 ,
V_101 ) ;
F_67 ( V_11 , V_102 ) ;
F_68 ( V_11 , 0 ) ;
break;
} else {
F_36 ( V_11 ) ;
F_57 ( V_11 -> V_93 ) ;
if ( F_69 ( V_11 ) != V_51 )
F_9 ( V_38 , V_11 , 0x7070 ,
L_33 ) ;
F_60 ( V_11 -> V_93 ) ;
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
F_70 ( V_11 ) ;
break;
case 0x2025f :
if ( ! F_71 ( V_14 ) )
return - V_98 ;
F_9 ( V_29 , V_11 , 0x70bc ,
L_36 ) ;
F_63 ( V_11 , 0 ) ;
F_64 ( V_11 , & V_92 ) ;
V_92 |= V_104 ;
F_65 ( V_11 , V_92 ) ;
F_68 ( V_11 , 0 ) ;
break;
case 0x20260 :
if ( ! F_71 ( V_14 ) )
return - V_98 ;
F_9 ( V_29 , V_11 , 0x70bd ,
L_37 ) ;
F_63 ( V_11 , 0 ) ;
F_64 ( V_11 , & V_92 ) ;
V_92 &= ~ V_104 ;
F_65 ( V_11 , V_92 ) ;
F_68 ( V_11 , 0 ) ;
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
F_72 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_5 V_105 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 > V_106 )
return 0 ;
if ( V_14 -> V_107 )
goto V_84;
V_14 -> V_107 = F_73 ( & V_14 -> V_66 -> V_108 , V_106 ,
& V_14 -> V_109 , V_86 ) ;
if ( ! V_14 -> V_107 ) {
F_9 ( V_38 , V_11 , 0x7076 ,
L_39 ) ;
return 0 ;
}
V_84:
V_105 = 0 ;
memset ( V_14 -> V_107 , 0 , V_106 ) ;
V_16 = F_74 ( V_11 , V_14 -> V_109 ,
V_106 , & V_105 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x7077 ,
L_40 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_105 > V_9 ? V_9 : V_105 ;
memcpy ( V_7 , V_14 -> V_107 , V_9 ) ;
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
T_5 V_105 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 > V_110 )
return 0 ;
if ( V_14 -> V_111 )
goto V_84;
V_14 -> V_111 = F_73 ( & V_14 -> V_66 -> V_108 , V_110 ,
& V_14 -> V_112 , V_86 ) ;
if ( ! V_14 -> V_111 ) {
F_9 ( V_38 , V_11 , 0x7078 ,
L_41 ) ;
return - V_39 ;
}
V_84:
V_105 = 0 ;
memset ( V_14 -> V_111 , 0 , V_110 ) ;
V_16 = F_76 ( V_11 , V_14 -> V_112 ,
V_110 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x7079 ,
L_42 , V_16 ) ;
return - V_90 ;
}
memcpy ( V_7 , V_14 -> V_111 , V_9 ) ;
return V_9 ;
}
void
F_77 ( T_7 * V_11 )
{
struct V_113 * V_93 = V_11 -> V_93 ;
struct V_114 * V_49 ;
int V_115 ;
for ( V_49 = V_116 ; V_49 -> V_117 ; V_49 ++ ) {
if ( V_49 -> V_118 && ! F_33 ( V_11 -> V_15 ) )
continue;
if ( V_49 -> V_118 == 2 && ! F_47 ( V_11 -> V_15 ) )
continue;
if ( V_49 -> V_118 == 3 && ! ( F_48 ( V_11 -> V_15 ) ) )
continue;
if ( V_49 -> V_118 == 0x27 && ! F_78 ( V_11 -> V_15 ) )
continue;
V_115 = F_79 ( & V_93 -> V_119 . V_4 ,
V_49 -> V_120 ) ;
if ( V_115 )
F_9 ( V_38 , V_11 , 0x00f3 ,
L_43 ,
V_49 -> V_117 , V_115 ) ;
else
F_21 ( V_121 , V_11 , 0x00f4 ,
L_44 ,
V_49 -> V_117 ) ;
}
}
void
F_80 ( T_7 * V_11 , bool V_122 )
{
struct V_113 * V_93 = V_11 -> V_93 ;
struct V_114 * V_49 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_49 = V_116 ; V_49 -> V_117 ; V_49 ++ ) {
if ( V_49 -> V_118 && ! F_33 ( V_14 ) )
continue;
if ( V_49 -> V_118 == 2 && ! F_47 ( V_14 ) )
continue;
if ( V_49 -> V_118 == 3 && ! ( F_48 ( V_11 -> V_15 ) ) )
continue;
F_81 ( & V_93 -> V_119 . V_4 ,
V_49 -> V_120 ) ;
}
if ( V_122 && V_14 -> V_123 == 1 )
V_14 -> V_41 -> V_124 ( V_11 ) ;
}
static T_1
F_82 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
return F_83 ( V_7 , V_126 , L_45 , V_127 ) ;
}
static T_1
F_84 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_128 [ 128 ] ;
return F_83 ( V_7 , V_126 , L_45 ,
V_14 -> V_41 -> V_129 ( V_11 , V_128 ) ) ;
}
static T_1
F_86 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_130 ;
if ( F_87 ( V_11 -> V_15 ) ) {
return F_83 ( V_7 , V_126 , L_45 ,
V_11 -> V_15 -> V_131 . V_132 ) ;
} else if ( F_33 ( V_14 ) ) {
F_88 ( V_11 , L_46 , V_7 , V_126 - 1 ) ;
return strlen ( strcat ( V_7 , L_47 ) ) ;
}
V_130 = ( ( V_14 -> V_133 & 0x1f ) << 16 ) | ( V_14 -> V_134 << 8 ) | V_14 -> V_135 ;
return F_83 ( V_7 , V_126 , L_48 , 'A' + V_130 / 100000 ,
V_130 % 100000 ) ;
}
static T_1
F_89 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
return F_83 ( V_7 , V_126 , L_49 , V_11 -> V_15 -> V_66 -> V_12 ) ;
}
static T_1
F_90 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_87 ( V_11 -> V_15 ) )
return F_83 ( V_7 , V_126 , L_45 ,
V_11 -> V_15 -> V_131 . V_136 ) ;
return F_83 ( V_7 , V_126 , L_50 ,
V_14 -> V_137 [ 0 ] , V_14 -> V_137 [ 1 ] , V_14 -> V_137 [ 2 ] ,
V_14 -> V_137 [ 3 ] ) ;
}
static T_1
F_91 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
return F_83 ( V_7 , V_126 , L_45 , V_11 -> V_15 -> V_138 ) ;
}
static T_1
F_92 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
return F_83 ( V_7 , V_126 , L_45 ,
V_11 -> V_15 -> V_139 ? V_11 -> V_15 -> V_139 : L_51 ) ;
}
static T_1
F_93 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
char V_140 [ 30 ] ;
return F_83 ( V_7 , V_126 , L_45 ,
V_11 -> V_15 -> V_41 -> V_141 ( V_11 , V_140 ) ) ;
}
static T_1
F_94 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_142 = 0 ;
if ( F_95 ( & V_11 -> V_143 ) == V_144 ||
F_95 ( & V_11 -> V_143 ) == V_145 ||
V_11 -> V_146 & V_147 )
V_142 = F_83 ( V_7 , V_126 , L_52 ) ;
else if ( F_95 ( & V_11 -> V_143 ) != V_148 ||
F_96 ( V_11 ) )
V_142 = F_83 ( V_7 , V_126 , L_53 ) ;
else {
V_142 = F_83 ( V_7 , V_126 , L_54 ) ;
switch ( V_14 -> V_149 ) {
case V_150 :
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_55 ) ;
break;
case V_151 :
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_56 ) ;
break;
case V_152 :
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 ,
L_57 ) ;
break;
case V_153 :
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_58 ) ;
break;
default:
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_55 ) ;
break;
}
}
return V_142 ;
}
static T_1
F_97 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
int V_142 = 0 ;
switch ( V_11 -> V_15 -> V_154 ) {
case V_155 :
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_59 ) ;
break;
case V_156 :
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_60 ) ;
break;
}
return V_142 ;
}
static T_1
F_98 ( struct V_12 * V_108 , struct V_125 * V_120 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_64 = 0 ;
T_5 V_154 ;
if ( ! F_99 ( V_14 ) )
return - V_157 ;
if ( sscanf ( V_7 , L_61 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 )
V_154 = V_155 ;
else
V_154 = V_156 ;
if ( V_154 != V_156 || V_14 -> V_154 != V_156 ) {
V_14 -> V_154 = V_154 ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_100 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
return F_83 ( V_7 , V_126 , L_62 , V_11 -> V_15 -> V_158 * 100 ) ;
}
static T_1
F_101 ( struct V_12 * V_108 , struct V_125 * V_120 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
int V_64 = 0 ;
T_5 V_158 ;
if ( sscanf ( V_7 , L_61 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 > 25500 || V_64 < 100 )
return - V_61 ;
V_158 = ( T_5 ) ( V_64 / 100 ) ;
V_11 -> V_15 -> V_158 = V_158 ;
return strlen ( V_7 ) ;
}
static T_1
F_102 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
int V_142 = 0 ;
if ( V_11 -> V_15 -> V_123 )
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_63 ) ;
else
V_142 += F_83 ( V_7 + V_142 , V_126 - V_142 , L_60 ) ;
return V_142 ;
}
static T_1
F_103 ( struct V_12 * V_108 , struct V_125 * V_120 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_64 = 0 ;
int V_16 ;
if ( F_104 ( V_14 ) || F_105 ( V_14 ) )
return - V_98 ;
if ( F_106 ( V_159 , & V_11 -> V_34 ) ) {
F_9 ( V_38 , V_11 , 0x707a ,
L_64 ) ;
return - V_160 ;
}
if ( sscanf ( V_7 , L_61 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 )
V_16 = V_14 -> V_41 -> V_161 ( V_11 ) ;
else
V_16 = V_14 -> V_41 -> V_124 ( V_11 ) ;
if ( V_16 != V_51 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_107 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_83 ( V_7 , V_126 , L_65 , V_14 -> V_162 [ 1 ] ,
V_14 -> V_162 [ 0 ] ) ;
}
static T_1
F_108 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_83 ( V_7 , V_126 , L_65 , V_14 -> V_163 [ 1 ] ,
V_14 -> V_163 [ 0 ] ) ;
}
static T_1
F_109 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_83 ( V_7 , V_126 , L_65 , V_14 -> V_164 [ 1 ] ,
V_14 -> V_164 [ 0 ] ) ;
}
static T_1
F_110 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_83 ( V_7 , V_126 , L_66 ,
V_14 -> V_165 [ 0 ] , V_14 -> V_165 [ 1 ] , V_14 -> V_165 [ 2 ] ,
V_14 -> V_165 [ 3 ] ) ;
}
static T_1
F_111 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_61 ( V_14 ) && ! F_62 ( V_14 ) && ! F_78 ( V_14 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
return F_83 ( V_7 , V_126 , L_67 ,
V_14 -> V_166 [ 0 ] , V_14 -> V_166 [ 1 ] ,
V_14 -> V_166 [ 2 ] , V_14 -> V_166 [ 3 ] ) ;
}
static T_1
F_112 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
return F_83 ( V_7 , V_126 , L_68 ,
V_11 -> V_167 . V_168 ) ;
}
static T_1
F_113 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
int V_16 = V_51 ;
T_5 V_169 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_114 ( V_14 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
if ( V_14 -> V_170 -> V_171 == 0 )
V_16 = F_115 ( V_11 , V_169 ) ;
if ( ( V_16 == V_51 ) && ( V_169 [ 0 ] == 0 ) )
return F_83 ( V_7 , V_126 , L_69 ,
( T_4 ) V_14 -> V_170 -> V_171 ) ;
return F_83 ( V_7 , V_126 , L_47 ) ;
}
static T_1
F_116 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_61 ( V_14 ) && ! F_71 ( V_14 ) && ! F_17 ( V_14 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
return F_83 ( V_7 , V_126 , L_70 ,
V_14 -> V_172 [ 0 ] , V_14 -> V_172 [ 1 ] , V_14 -> V_172 [ 2 ] ,
V_14 -> V_173 ) ;
}
static T_1
F_117 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_61 ( V_14 ) && ! F_71 ( V_14 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
return F_83 ( V_7 , V_126 , L_71 ,
V_14 -> V_174 [ 0 ] , V_14 -> V_174 [ 1 ] , V_14 -> V_174 [ 2 ] ) ;
}
static T_1
F_118 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_83 ( V_7 , V_126 , L_72 , V_14 -> V_175 ) ;
}
static T_1
F_119 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
if ( ! F_48 ( V_11 -> V_15 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
return F_83 ( V_7 , V_126 , L_68 , V_11 -> V_176 ) ;
}
static T_1
F_120 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
if ( ! F_48 ( V_11 -> V_15 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
return F_83 ( V_7 , V_126 , L_73 , V_11 -> V_177 ) ;
}
static T_1
F_121 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
return F_83 ( V_7 , V_126 , L_68 , V_11 -> V_15 -> V_178 ) ;
}
static T_1
F_122 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
T_5 V_179 = 0 ;
if ( F_96 ( V_11 ) ) {
F_9 ( V_38 , V_11 , 0x70dc , L_74 ) ;
goto V_180;
}
if ( V_11 -> V_15 -> V_94 . V_181 ) {
F_9 ( V_38 , V_11 , 0x70dd , L_75 ) ;
goto V_180;
}
if ( F_123 ( V_11 , & V_179 ) == V_51 )
return F_83 ( V_7 , V_126 , L_68 , V_179 ) ;
V_180:
return F_83 ( V_7 , V_126 , L_47 ) ;
}
static T_1
F_124 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
int V_16 = V_182 ;
T_5 V_183 [ 5 ] ;
T_4 V_184 ;
if ( F_87 ( V_11 -> V_15 ) ) {
V_184 = F_125 ( V_108 , V_120 , V_7 ) ;
return F_83 ( V_7 , V_126 , L_72 , V_184 ) ;
}
if ( F_96 ( V_11 ) )
F_9 ( V_38 , V_11 , 0x707c ,
L_74 ) ;
else if ( ! V_11 -> V_15 -> V_94 . V_181 )
V_16 = F_126 ( V_11 , V_183 ) ;
if ( V_16 != V_51 )
memset ( V_183 , - 1 , sizeof( V_183 ) ) ;
return F_83 ( V_7 , V_126 , L_76 , V_183 [ 0 ] ,
V_183 [ 1 ] , V_183 [ 2 ] , V_183 [ 3 ] , V_183 [ 4 ] ) ;
}
static T_1
F_127 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
if ( ! F_128 ( V_11 -> V_15 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
return F_83 ( V_7 , V_126 , L_77 , V_11 -> V_185 . V_186 ) ;
}
static T_1
F_129 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
if ( ! F_128 ( V_11 -> V_15 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
return F_83 ( V_7 , V_126 , L_77 ,
V_11 -> V_185 . V_187 >> 20 ) ;
}
static T_1
F_130 ( struct V_12 * V_108 , struct V_125 * V_120 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_37 ;
if ( ! V_14 -> V_31 )
V_37 = 0 ;
else if ( F_5 ( V_14 ) )
V_37 = V_14 -> V_19 + V_14 -> V_22 ;
else
V_37 = V_14 -> V_27 ;
return F_83 ( V_7 , V_126 , L_68 , V_37 ) ;
}
static T_1
F_131 ( struct V_12 * V_108 ,
struct V_125 * V_120 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
if ( ! F_5 ( V_11 -> V_15 ) )
return F_83 ( V_7 , V_126 , L_47 ) ;
else
return F_83 ( V_7 , V_126 , L_45 ,
V_11 -> V_15 -> V_188 ? L_78 : L_79 ) ;
}
static T_1
F_132 ( struct V_12 * V_108 ,
struct V_125 * V_120 , const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_85 ( V_108 ) ) ;
int V_64 = 0 ;
if ( ! F_5 ( V_11 -> V_15 ) )
return - V_48 ;
if ( sscanf ( V_7 , L_61 , & V_64 ) != 1 )
return - V_48 ;
V_11 -> V_15 -> V_188 = V_64 != 0 ;
return strlen ( V_7 ) ;
}
static void
F_133 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
F_134 ( V_189 ) = V_11 -> V_190 . V_191 . V_192 << 16 |
V_11 -> V_190 . V_191 . V_193 << 8 | V_11 -> V_190 . V_191 . V_194 ;
}
static void
F_135 ( struct V_113 * V_189 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_189 ) ) ) -> V_15 ;
T_8 V_195 = V_196 ;
if ( F_87 ( V_14 ) ) {
F_136 ( V_189 ) ;
return;
}
switch ( V_14 -> V_197 ) {
case V_198 :
V_195 = V_199 ;
break;
case V_200 :
V_195 = V_201 ;
break;
case V_202 :
V_195 = V_203 ;
break;
case V_204 :
V_195 = V_205 ;
break;
case V_206 :
V_195 = V_207 ;
break;
case V_208 :
V_195 = V_209 ;
break;
case V_210 :
V_195 = V_211 ;
break;
}
F_137 ( V_189 ) = V_195 ;
}
static void
F_138 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
T_4 V_212 = V_213 ;
if ( V_11 -> V_214 ) {
F_139 ( V_189 ) = V_215 ;
return;
}
switch ( V_11 -> V_15 -> V_149 ) {
case V_150 :
V_212 = V_216 ;
break;
case V_151 :
V_212 = V_217 ;
break;
case V_152 :
V_212 = V_218 ;
break;
case V_153 :
V_212 = V_219 ;
break;
}
F_139 ( V_189 ) = V_212 ;
}
static void
F_140 ( struct V_220 * V_221 )
{
struct V_113 * V_93 = F_3 ( V_221 -> V_108 . V_222 ) ;
T_7 * V_11 = F_2 ( V_93 ) ;
T_9 * V_223 ;
T_10 V_224 = 0 ;
F_141 (fcport, &vha->vp_fcports, list) {
if ( V_223 -> V_225 &&
V_221 -> V_226 == V_223 -> V_225 -> V_227 ) {
V_224 = F_142 ( V_223 -> V_224 ) ;
break;
}
}
F_143 ( V_221 ) = V_224 ;
}
static void
F_144 ( struct V_220 * V_221 )
{
struct V_113 * V_93 = F_3 ( V_221 -> V_108 . V_222 ) ;
T_7 * V_11 = F_2 ( V_93 ) ;
T_9 * V_223 ;
T_10 V_228 = 0 ;
F_141 (fcport, &vha->vp_fcports, list) {
if ( V_223 -> V_225 &&
V_221 -> V_226 == V_223 -> V_225 -> V_227 ) {
V_228 = F_142 ( V_223 -> V_228 ) ;
break;
}
}
F_145 ( V_221 ) = V_228 ;
}
static void
F_146 ( struct V_220 * V_221 )
{
struct V_113 * V_93 = F_3 ( V_221 -> V_108 . V_222 ) ;
T_7 * V_11 = F_2 ( V_93 ) ;
T_9 * V_223 ;
T_4 V_229 = ~ 0U ;
F_141 (fcport, &vha->vp_fcports, list) {
if ( V_223 -> V_225 &&
V_221 -> V_226 == V_223 -> V_225 -> V_227 ) {
V_229 = V_223 -> V_190 . V_191 . V_192 << 16 |
V_223 -> V_190 . V_191 . V_193 << 8 | V_223 -> V_190 . V_191 . V_194 ;
break;
}
}
F_147 ( V_221 ) = V_229 ;
}
static void
F_148 ( struct V_230 * V_225 , T_4 V_231 )
{
if ( V_231 )
V_225 -> V_232 = V_231 ;
else
V_225 -> V_232 = 1 ;
}
static void
F_149 ( struct V_230 * V_225 )
{
struct V_113 * V_93 = F_150 ( V_225 ) ;
T_9 * V_223 = * ( T_9 * * ) V_225 -> V_233 ;
unsigned long V_94 ;
if ( ! V_223 )
return;
F_151 ( V_223 , V_234 ) ;
F_152 ( V_93 -> V_235 , V_94 ) ;
V_223 -> V_225 = V_223 -> V_236 = NULL ;
* ( ( T_9 * * ) V_225 -> V_233 ) = NULL ;
F_153 ( V_93 -> V_235 , V_94 ) ;
if ( F_106 ( V_159 , & V_223 -> V_11 -> V_34 ) )
return;
if ( F_44 ( F_45 ( V_223 -> V_11 -> V_15 -> V_66 ) ) ) {
F_154 ( V_223 -> V_11 , V_237 << 16 ) ;
return;
}
}
static void
F_155 ( struct V_230 * V_225 )
{
T_9 * V_223 = * ( T_9 * * ) V_225 -> V_233 ;
if ( ! V_223 )
return;
if ( F_106 ( V_159 , & V_223 -> V_11 -> V_34 ) )
return;
if ( F_44 ( F_45 ( V_223 -> V_11 -> V_15 -> V_66 ) ) ) {
F_154 ( V_223 -> V_11 , V_237 << 16 ) ;
return;
}
if ( V_223 -> V_238 != V_239 ) {
if ( F_33 ( V_223 -> V_11 -> V_15 ) )
V_223 -> V_11 -> V_15 -> V_41 -> V_240 ( V_223 -> V_11 ,
V_223 -> V_238 , V_223 -> V_190 . V_191 . V_192 ,
V_223 -> V_190 . V_191 . V_193 , V_223 -> V_190 . V_191 . V_194 ) ;
else
F_156 ( V_223 -> V_11 , V_223 ) ;
}
}
static int
F_157 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
if ( F_87 ( V_11 -> V_15 ) )
return 0 ;
F_158 ( V_11 ) ;
return 0 ;
}
static struct V_241 *
F_159 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_91 = F_56 ( V_14 -> V_66 ) ;
int V_16 ;
struct V_242 * V_243 ;
T_11 V_244 ;
struct V_241 * V_245 ;
V_245 = & V_11 -> V_246 ;
memset ( V_245 , - 1 , sizeof( struct V_241 ) ) ;
if ( F_87 ( V_11 -> V_15 ) )
goto V_180;
if ( F_106 ( V_247 , & V_11 -> V_34 ) )
goto V_180;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
goto V_180;
if ( F_96 ( V_11 ) )
goto V_180;
V_243 = F_53 ( V_14 -> V_85 , V_86 , & V_244 ) ;
if ( V_243 == NULL ) {
F_9 ( V_38 , V_11 , 0x707d ,
L_80 ) ;
goto V_180;
}
memset ( V_243 , 0 , V_248 ) ;
V_16 = V_182 ;
if ( F_33 ( V_14 ) ) {
V_16 = F_160 ( V_91 , V_243 , V_244 ) ;
} else if ( F_95 ( & V_91 -> V_143 ) == V_148 &&
! V_14 -> V_249 ) {
V_16 = F_161 ( V_91 , V_91 -> V_238 ,
V_243 , V_244 ) ;
}
if ( V_16 != V_51 )
goto V_250;
V_245 -> V_251 = V_243 -> V_252 ;
V_245 -> V_253 = V_243 -> V_254 ;
V_245 -> V_255 = V_243 -> V_256 ;
V_245 -> V_257 = V_243 -> V_258 ;
V_245 -> V_259 = V_243 -> V_260 ;
V_245 -> V_261 = V_243 -> V_262 ;
if ( F_33 ( V_14 ) ) {
V_245 -> V_263 = V_243 -> V_264 ;
V_245 -> V_265 = V_243 -> V_265 ;
V_245 -> V_266 = V_243 -> V_266 ;
V_245 -> V_267 = V_243 -> V_268 ;
V_245 -> V_269 = V_243 -> V_270 ;
V_245 -> V_271 =
V_243 -> V_272 + V_243 -> V_268 ;
V_245 -> V_273 = V_11 -> V_167 . V_274 ;
V_245 -> V_275 = V_11 -> V_167 . V_276 ;
}
V_245 -> V_277 = V_11 -> V_167 . V_278 ;
V_245 -> V_279 = V_11 -> V_167 . V_280 ;
V_245 -> V_281 = V_11 -> V_167 . V_282 ;
V_245 -> V_283 = V_11 -> V_167 . V_274 >> 20 ;
V_245 -> V_284 = V_11 -> V_167 . V_276 >> 20 ;
V_245 -> V_285 =
F_162 () - V_11 -> V_167 . V_286 ;
F_163 ( V_245 -> V_285 , V_287 ) ;
V_250:
F_164 ( V_14 -> V_85 , V_243 , V_244 ) ;
V_180:
return V_245 ;
}
static void
F_165 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
memset ( & V_11 -> V_246 , 0 , sizeof( V_11 -> V_246 ) ) ;
V_11 -> V_167 . V_286 = F_162 () ;
}
static void
F_166 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
F_167 ( V_11 , F_168 ( V_189 ) ) ;
}
static void
F_169 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
F_22 ( V_288 , & V_11 -> V_34 ) ;
}
static void
F_170 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
T_6 V_224 [ V_289 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_290 = F_142 ( V_224 ) ;
if ( V_11 -> V_146 & V_291 )
V_290 = F_142 ( V_11 -> V_292 ) ;
F_171 ( V_189 ) = V_290 ;
}
static void
F_172 ( struct V_113 * V_189 )
{
T_7 * V_11 = F_2 ( V_189 ) ;
struct V_10 * V_91 = F_56 ( V_11 -> V_15 -> V_66 ) ;
if ( ! V_91 -> V_94 . V_293 ) {
F_173 ( V_189 ) = V_294 ;
return;
}
switch ( F_95 ( & V_91 -> V_143 ) ) {
case V_295 :
F_173 ( V_189 ) = V_296 ;
break;
case V_144 :
if ( F_106 ( V_297 , & V_91 -> V_34 ) )
F_173 ( V_189 ) = V_296 ;
else
F_173 ( V_189 ) = V_298 ;
break;
case V_145 :
F_173 ( V_189 ) = V_298 ;
break;
case V_148 :
F_173 ( V_189 ) = V_299 ;
break;
default:
F_173 ( V_189 ) = V_300 ;
break;
}
}
static int
F_174 ( struct V_301 * V_301 , bool V_302 )
{
int V_115 = 0 ;
T_6 V_303 = 0 ;
T_7 * V_91 = F_2 ( V_301 -> V_189 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_91 -> V_15 ;
T_5 V_304 = 0 ;
int V_46 ;
struct V_305 * V_306 = V_14 -> V_307 [ 0 ] ;
V_115 = F_175 ( V_301 ) ;
if ( V_115 ) {
F_9 ( V_38 , V_11 , 0x707e ,
L_81 , V_115 ) ;
return ( V_115 ) ;
}
V_11 = F_176 ( V_301 ) ;
if ( V_11 == NULL ) {
F_9 ( V_38 , V_11 , 0x707f , L_82 ) ;
return V_308 ;
}
if ( V_302 ) {
F_177 ( & V_11 -> V_309 , V_310 ) ;
F_178 ( V_301 , V_311 ) ;
} else
F_177 ( & V_11 -> V_309 , V_312 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_83 , V_11 -> V_214 ) ;
F_177 ( & V_11 -> V_143 , V_144 ) ;
V_11 -> V_313 = V_314 ;
V_11 -> V_315 = V_316 ;
if ( F_95 ( & V_91 -> V_143 ) == V_144 ||
F_95 ( & V_91 -> V_143 ) == V_145 ) {
F_21 ( V_32 , V_11 , 0x7081 ,
L_84 ) ;
F_177 ( & V_11 -> V_143 , V_145 ) ;
if ( ! V_302 )
F_178 ( V_301 , V_317 ) ;
}
if ( F_179 ( V_14 ) && V_318 ) {
if ( V_14 -> V_319 & V_320 ) {
int V_321 = 0 , V_322 ;
V_11 -> V_94 . V_323 = 1 ;
F_21 ( V_32 , V_11 , 0x7082 ,
L_85 ) ;
if ( V_318 == 1 )
V_321 = V_324 ;
F_180 ( V_11 -> V_93 ,
V_321 | V_325
| V_326
| V_327
| V_328
| V_329
| V_330 ) ;
V_322 = V_331 ;
if ( F_181 ( V_14 ) &&
( V_318 > 1 || F_182 ( V_14 ) ) )
V_322 |= V_332 ;
F_183 ( V_11 -> V_93 , V_322 ) ;
} else
V_11 -> V_94 . V_323 = 0 ;
}
if ( F_184 ( V_11 -> V_93 , & V_301 -> V_108 ,
& V_14 -> V_66 -> V_108 ) ) {
F_21 ( V_32 , V_11 , 0x7083 ,
L_86 , V_11 -> V_214 ) ;
goto V_333;
}
F_185 ( V_11 -> V_93 ) = V_14 -> V_334 ;
F_186 ( V_11 -> V_93 ) = F_142 ( V_11 -> V_224 ) ;
F_187 ( V_11 -> V_93 ) = F_142 ( V_11 -> V_228 ) ;
F_188 ( V_11 -> V_93 ) =
F_188 ( V_91 -> V_93 ) ;
F_189 ( V_11 -> V_93 ) =
F_189 ( V_91 -> V_93 ) ;
F_190 ( V_11 , V_14 ) ;
F_191 ( V_301 , V_302 ) ;
if ( V_14 -> V_94 . V_335 ) {
V_306 = V_14 -> V_307 [ 1 ] ;
F_21 ( V_336 , V_11 , 0xc000 ,
L_87
L_88 ,
V_306 , V_11 -> V_214 , V_14 -> V_94 . V_335 ) ;
goto V_337;
} else if ( V_338 == 1 || ! V_14 -> V_339 )
goto V_337;
for ( V_46 = 0 ; V_46 < V_14 -> V_340 ; V_46 ++ ) {
if ( memcmp ( V_14 -> V_339 [ V_46 ] . V_228 , V_11 -> V_228 , 8 ) == 0
&& memcmp ( V_14 -> V_339 [ V_46 ] . V_224 , V_11 -> V_224 ,
8 ) == 0 ) {
V_303 = V_14 -> V_339 [ V_46 ] . V_341 ;
break;
}
}
if ( V_303 ) {
V_115 = F_192 ( V_14 , V_304 , V_11 -> V_214 , 0 , 0 ,
V_303 ) ;
if ( ! V_115 )
F_9 ( V_38 , V_11 , 0x7084 ,
L_89 ,
V_11 -> V_214 ) ;
else {
F_21 ( V_336 , V_11 , 0xc001 ,
L_90 ,
V_115 , V_303 , V_11 -> V_214 ) ;
F_21 ( V_32 , V_11 , 0x7085 ,
L_90 ,
V_115 , V_303 , V_11 -> V_214 ) ;
V_306 = V_14 -> V_307 [ V_115 ] ;
}
}
V_337:
V_11 -> V_306 = V_306 ;
return 0 ;
V_333:
F_193 ( V_11 ) ;
F_194 ( V_11 ) ;
F_195 ( V_11 -> V_93 ) ;
return V_308 ;
}
static int
F_196 ( struct V_301 * V_301 )
{
T_7 * V_11 = V_301 -> V_233 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_226 = V_11 -> V_214 ;
while ( F_106 ( V_342 , & V_11 -> V_34 ) ||
F_106 ( V_343 , & V_11 -> V_34 ) )
F_197 ( 1000 ) ;
F_193 ( V_11 ) ;
V_11 -> V_94 . V_344 = 1 ;
F_198 ( V_14 , V_11 ) ;
F_199 ( V_11 -> V_93 ) ;
F_200 ( V_11 -> V_93 ) ;
F_194 ( V_11 ) ;
if ( V_11 -> V_345 ) {
F_201 ( V_11 ) ;
F_21 ( V_32 , V_11 , 0x7086 ,
L_91 , V_11 -> V_214 ) ;
}
F_202 ( F_95 ( & V_11 -> V_346 ) ) ;
F_203 ( V_11 ) ;
F_40 ( & V_14 -> V_347 ) ;
V_14 -> V_348 -- ;
F_204 ( V_11 -> V_214 , V_14 -> V_349 ) ;
F_41 ( & V_14 -> V_347 ) ;
if ( V_11 -> V_306 -> V_226 && ! V_14 -> V_94 . V_335 ) {
if ( F_205 ( V_11 , V_11 -> V_306 ) != V_51 )
F_9 ( V_38 , V_11 , 0x7087 ,
L_92 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_93 , V_226 ) ;
F_195 ( V_11 -> V_93 ) ;
return 0 ;
}
static int
F_191 ( struct V_301 * V_301 , bool V_302 )
{
T_7 * V_11 = V_301 -> V_233 ;
if ( V_302 )
F_193 ( V_11 ) ;
else
F_206 ( V_11 ) ;
return 0 ;
}
void
F_207 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_195 = V_196 ;
F_185 ( V_11 -> V_93 ) = V_14 -> V_334 ;
F_186 ( V_11 -> V_93 ) = F_142 ( V_11 -> V_224 ) ;
F_187 ( V_11 -> V_93 ) = F_142 ( V_11 -> V_228 ) ;
F_188 ( V_11 -> V_93 ) = V_14 -> V_350 . V_351 ?
( V_352 | V_353 ) : V_353 ;
F_208 ( V_11 -> V_93 ) = V_14 -> V_354 ;
F_209 ( V_11 -> V_93 ) = V_14 -> V_348 ;
if ( F_48 ( V_14 ) )
V_195 = V_207 ;
else if ( F_49 ( V_14 ) )
V_195 = V_209 | V_205 |
V_203 ;
else if ( F_47 ( V_14 ) )
V_195 = V_205 | V_203 |
V_201 | V_199 ;
else if ( F_46 ( V_14 ) )
V_195 = V_203 | V_201 |
V_199 ;
else if ( F_210 ( V_14 ) )
V_195 = V_201 | V_199 ;
else if ( F_87 ( V_14 ) )
V_195 = V_205 | V_203 |
V_201 | V_199 ;
else if ( F_78 ( V_14 ) )
V_195 = V_211 | V_209 |
V_205 ;
else
V_195 = V_199 ;
F_189 ( V_11 -> V_93 ) = V_195 ;
}
