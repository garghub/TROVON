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
for ( V_46 = 0 ; V_46 < ( ( V_9 >> 2 ) - 1 ) ; V_46 ++ , V_49 ++ )
V_50 += F_34 ( * V_49 ) ;
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
T_4 V_74 ;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
return - V_52 ;
if ( ! F_30 ( V_40 ) )
return - V_48 ;
if ( F_31 ( V_14 ) ) {
V_74 = V_14 -> V_75 << 2 ;
if ( F_50 ( V_14 ) &&
F_52 ( V_11 ) == V_76 )
V_74 = V_14 -> V_77 << 2 ;
V_14 -> V_41 -> V_42 ( V_11 , V_14 -> V_78 , V_74 ,
V_14 -> V_79 ) ;
}
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_78 , V_14 -> V_79 ) ;
}
static T_1
F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_80 ;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
return 0 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 != V_14 -> V_79 ||
! V_14 -> V_41 -> V_47 )
return 0 ;
if ( F_36 ( V_11 ) != V_51 ) {
F_9 ( V_38 , V_11 , 0x706a ,
L_27 ) ;
return - V_52 ;
}
V_14 -> V_41 -> V_47 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_81 , V_9 ) ;
V_14 -> V_41 -> V_54 ( V_11 , ( T_6 * ) V_14 -> V_78 , V_14 -> V_81 , V_9 ) ;
if ( ! F_33 ( V_14 ) )
return - V_48 ;
V_80 = F_27 ( 256 ) ;
if ( ! V_80 ) {
F_9 ( V_38 , V_11 , 0x706b ,
L_28 ) ;
return - V_39 ;
}
V_14 -> V_41 -> V_82 ( V_11 , V_80 ) ;
F_25 ( V_80 ) ;
return V_9 ;
}
static T_1
F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_49 , V_83 , V_84 ;
int V_16 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 != V_85 * 2 )
return 0 ;
if ( V_14 -> V_86 )
goto V_87;
V_14 -> V_86 = F_55 ( V_14 -> V_88 , V_89 ,
& V_14 -> V_90 ) ;
if ( ! V_14 -> V_86 ) {
F_9 ( V_38 , V_11 , 0x706c ,
L_29 ) ;
return 0 ;
}
V_87:
memset ( V_14 -> V_86 , 0 , V_91 ) ;
V_83 = 0xa0 ;
for ( V_49 = 0 , V_84 = 0 ; V_49 < ( V_85 * 2 ) / V_91 ;
V_49 ++ , V_84 += V_91 ) {
if ( V_49 == 4 ) {
V_83 = 0xa2 ;
V_84 = 0 ;
}
V_16 = F_56 ( V_11 , V_14 -> V_90 , V_14 -> V_86 ,
V_83 , V_84 , V_91 , V_92 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x706d ,
L_30 , V_16 ,
V_83 , V_84 ) ;
return - V_93 ;
}
memcpy ( V_7 , V_14 -> V_86 , V_91 ) ;
V_7 += V_91 ;
}
return V_9 ;
}
static T_1
F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_94 = F_58 ( V_14 -> V_66 ) ;
int type ;
T_4 V_95 ;
T_6 * V_80 = NULL ;
if ( V_8 != 0 )
return - V_48 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_29 , V_11 , 0x706e ,
L_31 ) ;
F_59 ( V_11 -> V_96 ) ;
if ( F_13 ( V_14 ) ) {
V_14 -> V_97 . V_98 = 1 ;
F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
F_16 ( V_14 ) ;
} else if ( F_17 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_95 = F_60 ( V_14 ,
V_99 ) ;
F_61 ( V_14 , V_99 ,
( V_95 | V_100 ) ) ;
F_15 ( V_11 ) ;
F_19 ( V_14 ) ;
} else {
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_37 ( V_11 ) ;
}
F_38 ( V_11 ) ;
F_62 ( V_11 -> V_96 ) ;
break;
case 0x2025d :
if ( ! F_63 ( V_14 ) && ! F_64 ( V_14 ) )
return - V_101 ;
F_9 ( V_29 , V_11 , 0x706f ,
L_32 ) ;
if ( F_64 ( V_14 ) || F_50 ( V_14 ) ) {
T_4 V_95 ;
F_65 ( V_11 , 0 ) ;
F_66 ( V_11 , & V_95 ) ;
V_95 |= V_102 ;
F_67 ( V_11 , V_95 ) ;
F_68 ( V_11 , V_103 ,
V_104 ) ;
F_69 ( V_11 , V_105 ) ;
F_70 ( V_11 , 0 ) ;
break;
} else {
F_36 ( V_11 ) ;
F_59 ( V_11 -> V_96 ) ;
if ( F_71 ( V_11 ) != V_51 )
F_9 ( V_38 , V_11 , 0x7070 ,
L_33 ) ;
F_62 ( V_11 -> V_96 ) ;
break;
}
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_94 ) {
F_9 ( V_29 , V_11 , 0x7071 ,
L_34 ) ;
return - V_101 ;
}
F_9 ( V_29 , V_11 , 0x7072 ,
L_35 ) ;
F_22 ( V_106 , & V_11 -> V_34 ) ;
F_37 ( V_11 ) ;
F_72 ( V_11 ) ;
break;
case 0x2025f :
if ( ! F_73 ( V_14 ) )
return - V_101 ;
F_9 ( V_29 , V_11 , 0x70bc ,
L_36 ) ;
F_65 ( V_11 , 0 ) ;
F_66 ( V_11 , & V_95 ) ;
V_95 |= V_107 ;
F_67 ( V_11 , V_95 ) ;
F_70 ( V_11 , 0 ) ;
break;
case 0x20260 :
if ( ! F_73 ( V_14 ) )
return - V_101 ;
F_9 ( V_29 , V_11 , 0x70bd ,
L_37 ) ;
F_65 ( V_11 , 0 ) ;
F_66 ( V_11 , & V_95 ) ;
V_95 &= ~ V_107 ;
F_67 ( V_11 , V_95 ) ;
F_70 ( V_11 , 0 ) ;
break;
case 0x20261 :
F_21 ( V_32 , V_11 , 0x70e0 ,
L_38 ) ;
V_80 = F_27 ( 256 ) ;
if ( ! V_80 ) {
F_9 ( V_38 , V_11 , 0x70e1 ,
L_28 ) ;
return - V_39 ;
}
V_14 -> V_41 -> V_82 ( V_11 , V_80 ) ;
F_25 ( V_80 ) ;
break;
}
return V_9 ;
}
static T_1
F_74 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
int type ;
int V_16 = 0 ;
T_7 V_108 ;
type = F_8 ( V_7 , NULL , 10 ) ;
V_108 . V_109 . V_110 = ( type & 0x00ff0000 ) >> 16 ;
V_108 . V_109 . V_111 = ( type & 0x0000ff00 ) >> 8 ;
V_108 . V_109 . V_112 = ( type & 0x000000ff ) ;
F_9 ( V_29 , V_11 , 0x70e3 , L_39 ,
V_108 . V_109 . V_110 , V_108 . V_109 . V_111 , V_108 . V_109 . V_112 ) ;
F_9 ( V_29 , V_11 , 0x70e4 , L_40 , V_113 , type ) ;
V_16 = F_75 ( V_11 , V_114 , V_108 ) ;
return V_9 ;
}
static T_1
F_76 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_5 V_115 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 > V_116 )
return 0 ;
if ( V_14 -> V_117 )
goto V_87;
V_14 -> V_117 = F_77 ( & V_14 -> V_66 -> V_118 , V_116 ,
& V_14 -> V_119 , V_89 ) ;
if ( ! V_14 -> V_117 ) {
F_9 ( V_38 , V_11 , 0x7076 ,
L_41 ) ;
return 0 ;
}
V_87:
V_115 = 0 ;
memset ( V_14 -> V_117 , 0 , V_116 ) ;
V_16 = F_78 ( V_11 , V_14 -> V_119 ,
V_116 , & V_115 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x7077 ,
L_42 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_115 > V_9 ? V_9 : V_115 ;
memcpy ( V_7 , V_14 -> V_117 , V_9 ) ;
return V_9 ;
}
static T_1
F_79 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
if ( ! F_30 ( V_40 ) || V_8 != 0 || V_9 > V_120 )
return 0 ;
if ( V_14 -> V_121 )
goto V_87;
V_14 -> V_121 = F_77 ( & V_14 -> V_66 -> V_118 , V_120 ,
& V_14 -> V_122 , V_89 ) ;
if ( ! V_14 -> V_121 ) {
F_9 ( V_38 , V_11 , 0x7078 ,
L_43 ) ;
return - V_39 ;
}
V_87:
memset ( V_14 -> V_121 , 0 , V_120 ) ;
V_16 = F_80 ( V_11 , V_14 -> V_122 ,
V_120 ) ;
if ( V_16 != V_51 ) {
F_9 ( V_38 , V_11 , 0x7079 ,
L_44 , V_16 ) ;
return - V_93 ;
}
memcpy ( V_7 , V_14 -> V_121 , V_9 ) ;
return V_9 ;
}
void
F_81 ( T_8 * V_11 )
{
struct V_123 * V_96 = V_11 -> V_96 ;
struct V_124 * V_49 ;
int V_125 ;
for ( V_49 = V_126 ; V_49 -> V_127 ; V_49 ++ ) {
if ( V_49 -> V_128 && ! F_33 ( V_11 -> V_15 ) )
continue;
if ( V_49 -> V_128 == 2 && ! F_47 ( V_11 -> V_15 ) )
continue;
if ( V_49 -> V_128 == 3 && ! ( F_48 ( V_11 -> V_15 ) ) )
continue;
if ( V_49 -> V_128 == 0x27 && ! F_50 ( V_11 -> V_15 ) )
continue;
V_125 = F_82 ( & V_96 -> V_129 . V_4 ,
V_49 -> V_130 ) ;
if ( V_125 )
F_9 ( V_38 , V_11 , 0x00f3 ,
L_45 ,
V_49 -> V_127 , V_125 ) ;
else
F_21 ( V_131 , V_11 , 0x00f4 ,
L_46 ,
V_49 -> V_127 ) ;
}
}
void
F_83 ( T_8 * V_11 , bool V_132 )
{
struct V_123 * V_96 = V_11 -> V_96 ;
struct V_124 * V_49 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_49 = V_126 ; V_49 -> V_127 ; V_49 ++ ) {
if ( V_49 -> V_128 && ! F_33 ( V_14 ) )
continue;
if ( V_49 -> V_128 == 2 && ! F_47 ( V_14 ) )
continue;
if ( V_49 -> V_128 == 3 && ! ( F_48 ( V_11 -> V_15 ) ) )
continue;
if ( V_49 -> V_128 == 0x27 && ! F_50 ( V_11 -> V_15 ) )
continue;
F_84 ( & V_96 -> V_129 . V_4 ,
V_49 -> V_130 ) ;
}
if ( V_132 && V_14 -> V_133 == 1 )
V_14 -> V_41 -> V_134 ( V_11 ) ;
}
static T_1
F_85 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
return F_86 ( V_7 , V_136 , L_47 , V_137 ) ;
}
static T_1
F_87 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_138 [ 128 ] ;
return F_86 ( V_7 , V_136 , L_47 ,
V_14 -> V_41 -> V_139 ( V_11 , V_138 , sizeof( V_138 ) ) ) ;
}
static T_1
F_89 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_140 ;
if ( F_90 ( V_11 -> V_15 ) ) {
return F_86 ( V_7 , V_136 , L_47 ,
V_11 -> V_15 -> V_141 . V_142 ) ;
} else if ( F_33 ( V_14 ) ) {
F_91 ( V_11 , L_48 , V_7 , V_136 - 1 ) ;
return strlen ( strcat ( V_7 , L_49 ) ) ;
}
V_140 = ( ( V_14 -> V_143 & 0x1f ) << 16 ) | ( V_14 -> V_144 << 8 ) | V_14 -> V_145 ;
return F_86 ( V_7 , V_136 , L_50 , 'A' + V_140 / 100000 ,
V_140 % 100000 ) ;
}
static T_1
F_92 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
return F_86 ( V_7 , V_136 , L_51 , V_11 -> V_15 -> V_66 -> V_12 ) ;
}
static T_1
F_93 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_90 ( V_11 -> V_15 ) )
return F_86 ( V_7 , V_136 , L_47 ,
V_11 -> V_15 -> V_141 . V_146 ) ;
return F_86 ( V_7 , V_136 , L_52 ,
V_14 -> V_147 [ 0 ] , V_14 -> V_147 [ 1 ] , V_14 -> V_147 [ 2 ] ,
V_14 -> V_147 [ 3 ] ) ;
}
static T_1
F_94 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
return F_86 ( V_7 , V_136 , L_47 , V_11 -> V_15 -> V_148 ) ;
}
static T_1
F_95 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
return F_86 ( V_7 , V_136 , L_47 , V_11 -> V_15 -> V_149 ) ;
}
static T_1
F_96 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
char V_150 [ 30 ] ;
return F_86 ( V_7 , V_136 , L_47 ,
V_11 -> V_15 -> V_41 -> V_151 ( V_11 , V_150 ) ) ;
}
static T_1
F_97 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_152 = 0 ;
if ( F_98 ( & V_11 -> V_153 ) == V_154 ||
F_98 ( & V_11 -> V_153 ) == V_155 ||
V_11 -> V_156 & V_157 )
V_152 = F_86 ( V_7 , V_136 , L_53 ) ;
else if ( F_98 ( & V_11 -> V_153 ) != V_158 ||
F_99 ( V_11 ) )
V_152 = F_86 ( V_7 , V_136 , L_54 ) ;
else {
V_152 = F_86 ( V_7 , V_136 , L_55 ) ;
switch ( V_14 -> V_159 ) {
case V_160 :
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_56 ) ;
break;
case V_161 :
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_57 ) ;
break;
case V_162 :
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 ,
L_58 ) ;
break;
case V_163 :
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_59 ) ;
break;
default:
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_56 ) ;
break;
}
}
return V_152 ;
}
static T_1
F_100 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
int V_152 = 0 ;
switch ( V_11 -> V_15 -> V_164 ) {
case V_165 :
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_60 ) ;
break;
case V_166 :
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_61 ) ;
break;
}
return V_152 ;
}
static T_1
F_101 ( struct V_12 * V_118 , struct V_135 * V_130 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_64 = 0 ;
T_5 V_164 ;
if ( ! F_102 ( V_14 ) )
return - V_167 ;
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 )
V_164 = V_165 ;
else
V_164 = V_166 ;
if ( V_164 != V_166 || V_14 -> V_164 != V_166 ) {
V_14 -> V_164 = V_164 ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_103 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
return F_86 ( V_7 , V_136 , L_63 , V_11 -> V_15 -> V_168 * 100 ) ;
}
static T_1
F_104 ( struct V_12 * V_118 , struct V_135 * V_130 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
int V_64 = 0 ;
T_5 V_168 ;
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 > 25500 || V_64 < 100 )
return - V_61 ;
V_168 = ( T_5 ) ( V_64 / 100 ) ;
V_11 -> V_15 -> V_168 = V_168 ;
return strlen ( V_7 ) ;
}
static T_1
F_105 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
int V_152 = 0 ;
if ( V_11 -> V_15 -> V_133 )
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_64 ) ;
else
V_152 += F_86 ( V_7 + V_152 , V_136 - V_152 , L_61 ) ;
return V_152 ;
}
static T_1
F_106 ( struct V_12 * V_118 , struct V_135 * V_130 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_64 = 0 ;
int V_16 ;
if ( F_107 ( V_14 ) || F_108 ( V_14 ) )
return - V_101 ;
if ( F_109 ( V_169 , & V_11 -> V_34 ) ) {
F_9 ( V_38 , V_11 , 0x707a ,
L_65 ) ;
return - V_170 ;
}
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
if ( V_64 )
V_16 = V_14 -> V_41 -> V_171 ( V_11 ) ;
else
V_16 = V_14 -> V_41 -> V_134 ( V_11 ) ;
if ( V_16 != V_51 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_110 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_86 ( V_7 , V_136 , L_66 , V_14 -> V_172 [ 1 ] ,
V_14 -> V_172 [ 0 ] ) ;
}
static T_1
F_111 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_86 ( V_7 , V_136 , L_66 , V_14 -> V_173 [ 1 ] ,
V_14 -> V_173 [ 0 ] ) ;
}
static T_1
F_112 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_86 ( V_7 , V_136 , L_66 , V_14 -> V_174 [ 1 ] ,
V_14 -> V_174 [ 0 ] ) ;
}
static T_1
F_113 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_86 ( V_7 , V_136 , L_67 ,
V_14 -> V_175 [ 0 ] , V_14 -> V_175 [ 1 ] , V_14 -> V_175 [ 2 ] ,
V_14 -> V_175 [ 3 ] ) ;
}
static T_1
F_114 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_63 ( V_14 ) && ! F_64 ( V_14 ) && ! F_50 ( V_14 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_68 ,
V_14 -> V_176 [ 0 ] , V_14 -> V_176 [ 1 ] ,
V_14 -> V_176 [ 2 ] , V_14 -> V_176 [ 3 ] ) ;
}
static T_1
F_115 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
return F_86 ( V_7 , V_136 , L_69 ,
V_11 -> V_177 . V_178 ) ;
}
static T_1
F_116 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
int V_16 = V_51 ;
T_5 V_179 [ 2 ] = { 0 , 0 } ;
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_117 ( V_14 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
if ( V_14 -> V_180 -> V_181 == 0 )
V_16 = F_118 ( V_11 , V_179 ) ;
if ( ( V_16 == V_51 ) && ( V_179 [ 0 ] == 0 ) )
return F_86 ( V_7 , V_136 , L_70 ,
( T_4 ) V_14 -> V_180 -> V_181 ) ;
return F_86 ( V_7 , V_136 , L_49 ) ;
}
static T_1
F_119 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_63 ( V_14 ) && ! F_73 ( V_14 ) && ! F_17 ( V_14 ) &&
! F_50 ( V_14 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_71 ,
V_14 -> V_182 [ 0 ] , V_14 -> V_182 [ 1 ] , V_14 -> V_182 [ 2 ] ,
V_14 -> V_183 ) ;
}
static T_1
F_120 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_63 ( V_14 ) && ! F_73 ( V_14 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_72 ,
V_14 -> V_184 [ 0 ] , V_14 -> V_184 [ 1 ] , V_14 -> V_184 [ 2 ] ) ;
}
static T_1
F_121 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_86 ( V_7 , V_136 , L_73 , V_14 -> V_185 ) ;
}
static T_1
F_122 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
if ( ! F_48 ( V_11 -> V_15 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_69 , V_11 -> V_186 ) ;
}
static T_1
F_123 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
if ( ! F_48 ( V_11 -> V_15 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_74 , V_11 -> V_187 ) ;
}
static T_1
F_124 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
return F_86 ( V_7 , V_136 , L_69 , V_11 -> V_15 -> V_188 ) ;
}
static T_1
F_125 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
T_5 V_189 = 0 ;
if ( F_99 ( V_11 ) ) {
F_9 ( V_38 , V_11 , 0x70dc , L_75 ) ;
goto V_190;
}
if ( V_11 -> V_15 -> V_97 . V_191 ) {
F_9 ( V_38 , V_11 , 0x70dd , L_76 ) ;
goto V_190;
}
if ( F_126 ( V_11 , & V_189 ) == V_51 )
return F_86 ( V_7 , V_136 , L_69 , V_189 ) ;
V_190:
return F_86 ( V_7 , V_136 , L_49 ) ;
}
static T_1
F_127 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
int V_16 = V_192 ;
T_5 V_193 [ 6 ] ;
T_4 V_194 ;
if ( F_90 ( V_11 -> V_15 ) ) {
V_194 = F_128 ( V_118 , V_130 , V_7 ) ;
return F_86 ( V_7 , V_136 , L_73 , V_194 ) ;
}
if ( F_99 ( V_11 ) )
F_9 ( V_38 , V_11 , 0x707c ,
L_75 ) ;
else if ( ! V_11 -> V_15 -> V_97 . V_191 )
V_16 = F_129 ( V_11 , V_193 ) ;
if ( V_16 != V_51 )
memset ( V_193 , - 1 , sizeof( V_193 ) ) ;
return F_86 ( V_7 , V_136 , L_77 ,
V_193 [ 0 ] , V_193 [ 1 ] , V_193 [ 2 ] , V_193 [ 3 ] , V_193 [ 4 ] , V_193 [ 5 ] ) ;
}
static T_1
F_130 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
if ( ! F_131 ( V_11 -> V_15 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_78 , V_11 -> V_195 . V_196 ) ;
}
static T_1
F_132 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
if ( ! F_131 ( V_11 -> V_15 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_78 ,
V_11 -> V_195 . V_197 >> 20 ) ;
}
static T_1
F_133 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_37 ;
if ( ! V_14 -> V_31 )
V_37 = 0 ;
else if ( F_5 ( V_14 ) )
V_37 = V_14 -> V_19 + V_14 -> V_22 ;
else
V_37 = V_14 -> V_27 ;
return F_86 ( V_7 , V_136 , L_69 , V_37 ) ;
}
static T_1
F_134 ( struct V_12 * V_118 ,
struct V_135 * V_130 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
if ( ! F_5 ( V_11 -> V_15 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
else
return F_86 ( V_7 , V_136 , L_47 ,
V_11 -> V_15 -> V_198 ? L_79 : L_80 ) ;
}
static T_1
F_135 ( struct V_12 * V_118 ,
struct V_135 * V_130 , const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
int V_64 = 0 ;
if ( ! F_5 ( V_11 -> V_15 ) )
return - V_48 ;
if ( sscanf ( V_7 , L_62 , & V_64 ) != 1 )
return - V_48 ;
V_11 -> V_15 -> V_198 = V_64 != 0 ;
return strlen ( V_7 ) ;
}
static T_1
F_136 ( struct V_12 * V_118 , struct V_135 * V_130 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_88 ( V_118 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_50 ( V_14 ) )
return F_86 ( V_7 , V_136 , L_49 ) ;
return F_86 ( V_7 , V_136 , L_72 ,
V_14 -> V_199 [ 0 ] , V_14 -> V_199 [ 1 ] , V_14 -> V_199 [ 2 ] ) ;
}
static void
F_137 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
F_138 ( V_200 ) = V_11 -> V_201 . V_109 . V_110 << 16 |
V_11 -> V_201 . V_109 . V_111 << 8 | V_11 -> V_201 . V_109 . V_112 ;
}
static void
F_139 ( struct V_123 * V_200 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_200 ) ) ) -> V_15 ;
T_9 V_202 = V_203 ;
if ( F_90 ( V_14 ) ) {
F_140 ( V_200 ) ;
return;
}
switch ( V_14 -> V_204 ) {
case V_205 :
V_202 = V_206 ;
break;
case V_207 :
V_202 = V_208 ;
break;
case V_209 :
V_202 = V_210 ;
break;
case V_211 :
V_202 = V_212 ;
break;
case V_213 :
V_202 = V_214 ;
break;
case V_215 :
V_202 = V_216 ;
break;
case V_217 :
V_202 = V_218 ;
break;
}
F_141 ( V_200 ) = V_202 ;
}
static void
F_142 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
T_4 V_219 = V_220 ;
if ( V_11 -> V_221 ) {
F_143 ( V_200 ) = V_222 ;
return;
}
switch ( V_11 -> V_15 -> V_159 ) {
case V_160 :
V_219 = V_223 ;
break;
case V_161 :
V_219 = V_224 ;
break;
case V_162 :
V_219 = V_225 ;
break;
case V_163 :
V_219 = V_226 ;
break;
}
F_143 ( V_200 ) = V_219 ;
}
static void
F_144 ( struct V_227 * V_228 )
{
struct V_123 * V_96 = F_3 ( V_228 -> V_118 . V_229 ) ;
T_8 * V_11 = F_2 ( V_96 ) ;
T_10 * V_230 ;
T_11 V_231 = 0 ;
F_145 (fcport, &vha->vp_fcports, list) {
if ( V_230 -> V_232 &&
V_228 -> V_233 == V_230 -> V_232 -> V_234 ) {
V_231 = F_146 ( V_230 -> V_231 ) ;
break;
}
}
F_147 ( V_228 ) = V_231 ;
}
static void
F_148 ( struct V_227 * V_228 )
{
struct V_123 * V_96 = F_3 ( V_228 -> V_118 . V_229 ) ;
T_8 * V_11 = F_2 ( V_96 ) ;
T_10 * V_230 ;
T_11 V_235 = 0 ;
F_145 (fcport, &vha->vp_fcports, list) {
if ( V_230 -> V_232 &&
V_228 -> V_233 == V_230 -> V_232 -> V_234 ) {
V_235 = F_146 ( V_230 -> V_235 ) ;
break;
}
}
F_149 ( V_228 ) = V_235 ;
}
static void
F_150 ( struct V_227 * V_228 )
{
struct V_123 * V_96 = F_3 ( V_228 -> V_118 . V_229 ) ;
T_8 * V_11 = F_2 ( V_96 ) ;
T_10 * V_230 ;
T_4 V_236 = ~ 0U ;
F_145 (fcport, &vha->vp_fcports, list) {
if ( V_230 -> V_232 &&
V_228 -> V_233 == V_230 -> V_232 -> V_234 ) {
V_236 = V_230 -> V_201 . V_109 . V_110 << 16 |
V_230 -> V_201 . V_109 . V_111 << 8 | V_230 -> V_201 . V_109 . V_112 ;
break;
}
}
F_151 ( V_228 ) = V_236 ;
}
static void
F_152 ( struct V_237 * V_232 , T_4 V_238 )
{
if ( V_238 )
V_232 -> V_239 = V_238 ;
else
V_232 -> V_239 = 1 ;
}
static void
F_153 ( struct V_237 * V_232 )
{
struct V_123 * V_96 = F_154 ( V_232 ) ;
T_10 * V_230 = * ( T_10 * * ) V_232 -> V_240 ;
unsigned long V_97 ;
if ( ! V_230 )
return;
F_155 ( V_230 , V_241 ) ;
F_156 ( V_96 -> V_242 , V_97 ) ;
V_230 -> V_232 = V_230 -> V_243 = NULL ;
* ( ( T_10 * * ) V_232 -> V_240 ) = NULL ;
F_157 ( V_96 -> V_242 , V_97 ) ;
if ( F_109 ( V_169 , & V_230 -> V_11 -> V_34 ) )
return;
if ( F_44 ( F_45 ( V_230 -> V_11 -> V_15 -> V_66 ) ) ) {
F_158 ( V_230 -> V_11 , V_244 << 16 ) ;
return;
}
}
static void
F_159 ( struct V_237 * V_232 )
{
T_10 * V_230 = * ( T_10 * * ) V_232 -> V_240 ;
if ( ! V_230 )
return;
if ( F_109 ( V_169 , & V_230 -> V_11 -> V_34 ) )
return;
if ( F_44 ( F_45 ( V_230 -> V_11 -> V_15 -> V_66 ) ) ) {
F_158 ( V_230 -> V_11 , V_244 << 16 ) ;
return;
}
if ( V_230 -> V_245 != V_246 ) {
if ( F_33 ( V_230 -> V_11 -> V_15 ) )
V_230 -> V_11 -> V_15 -> V_41 -> V_247 ( V_230 -> V_11 ,
V_230 -> V_245 , V_230 -> V_201 . V_109 . V_110 ,
V_230 -> V_201 . V_109 . V_111 , V_230 -> V_201 . V_109 . V_112 ) ;
else
F_160 ( V_230 -> V_11 , V_230 ) ;
}
}
static int
F_161 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
if ( F_90 ( V_11 -> V_15 ) )
return 0 ;
F_162 ( V_11 ) ;
return 0 ;
}
static struct V_248 *
F_163 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_94 = F_58 ( V_14 -> V_66 ) ;
int V_16 ;
struct V_249 * V_250 ;
T_12 V_251 ;
struct V_248 * V_252 ;
V_252 = & V_11 -> V_253 ;
memset ( V_252 , - 1 , sizeof( struct V_248 ) ) ;
if ( F_90 ( V_11 -> V_15 ) )
goto V_190;
if ( F_109 ( V_254 , & V_11 -> V_34 ) )
goto V_190;
if ( F_44 ( F_45 ( V_14 -> V_66 ) ) )
goto V_190;
if ( F_99 ( V_11 ) )
goto V_190;
V_250 = F_77 ( & V_14 -> V_66 -> V_118 ,
sizeof( struct V_249 ) , & V_251 , V_89 ) ;
if ( V_250 == NULL ) {
F_9 ( V_38 , V_11 , 0x707d ,
L_81 ) ;
goto V_190;
}
memset ( V_250 , 0 , V_255 ) ;
V_16 = V_192 ;
if ( F_33 ( V_14 ) ) {
V_16 = F_164 ( V_94 , V_250 , V_251 ) ;
} else if ( F_98 ( & V_94 -> V_153 ) == V_158 &&
! V_14 -> V_256 ) {
V_16 = F_165 ( V_94 , V_94 -> V_245 ,
V_250 , V_251 ) ;
}
if ( V_16 != V_51 )
goto V_257;
V_252 -> V_258 = V_250 -> V_259 ;
V_252 -> V_260 = V_250 -> V_261 ;
V_252 -> V_262 = V_250 -> V_263 ;
V_252 -> V_264 = V_250 -> V_265 ;
V_252 -> V_266 = V_250 -> V_267 ;
V_252 -> V_268 = V_250 -> V_269 ;
if ( F_33 ( V_14 ) ) {
V_252 -> V_270 = V_250 -> V_271 ;
V_252 -> V_272 = V_250 -> V_272 ;
V_252 -> V_273 = V_250 -> V_273 ;
V_252 -> V_274 = V_250 -> V_275 ;
V_252 -> V_276 = V_250 -> V_277 ;
V_252 -> V_278 =
V_250 -> V_279 + V_250 -> V_275 ;
V_252 -> V_280 = V_11 -> V_177 . V_281 ;
V_252 -> V_282 = V_11 -> V_177 . V_283 ;
}
V_252 -> V_284 = V_11 -> V_177 . V_285 ;
V_252 -> V_286 = V_11 -> V_177 . V_287 ;
V_252 -> V_288 = V_11 -> V_177 . V_289 ;
V_252 -> V_290 = V_11 -> V_177 . V_281 >> 20 ;
V_252 -> V_291 = V_11 -> V_177 . V_283 >> 20 ;
V_252 -> V_292 =
F_166 () - V_11 -> V_177 . V_293 ;
F_167 ( V_252 -> V_292 , V_294 ) ;
V_257:
F_168 ( & V_14 -> V_66 -> V_118 , sizeof( struct V_249 ) ,
V_250 , V_251 ) ;
V_190:
return V_252 ;
}
static void
F_169 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
memset ( & V_11 -> V_253 , 0 , sizeof( V_11 -> V_253 ) ) ;
V_11 -> V_177 . V_293 = F_166 () ;
}
static void
F_170 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
F_171 ( V_11 , F_172 ( V_200 ) ,
sizeof( F_172 ( V_200 ) ) ) ;
}
static void
F_173 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
F_22 ( V_295 , & V_11 -> V_34 ) ;
}
static void
F_174 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
T_6 V_231 [ V_296 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_11 V_297 = F_146 ( V_231 ) ;
if ( V_11 -> V_156 & V_298 )
V_297 = F_146 ( V_11 -> V_299 ) ;
F_175 ( V_200 ) = V_297 ;
}
static void
F_176 ( struct V_123 * V_200 )
{
T_8 * V_11 = F_2 ( V_200 ) ;
struct V_10 * V_94 = F_58 ( V_11 -> V_15 -> V_66 ) ;
if ( ! V_94 -> V_97 . V_300 ) {
F_177 ( V_200 ) = V_301 ;
return;
}
switch ( F_98 ( & V_94 -> V_153 ) ) {
case V_302 :
F_177 ( V_200 ) = V_303 ;
break;
case V_154 :
if ( F_109 ( V_304 , & V_94 -> V_34 ) )
F_177 ( V_200 ) = V_303 ;
else
F_177 ( V_200 ) = V_305 ;
break;
case V_155 :
F_177 ( V_200 ) = V_305 ;
break;
case V_158 :
F_177 ( V_200 ) = V_306 ;
break;
default:
F_177 ( V_200 ) = V_307 ;
break;
}
}
static int
F_178 ( struct V_308 * V_308 , bool V_309 )
{
int V_125 = 0 ;
T_6 V_310 = 0 ;
T_8 * V_94 = F_2 ( V_308 -> V_200 ) ;
T_8 * V_11 = NULL ;
struct V_13 * V_14 = V_94 -> V_15 ;
T_5 V_311 = 0 ;
int V_46 ;
struct V_312 * V_313 = V_14 -> V_314 [ 0 ] ;
V_125 = F_179 ( V_308 ) ;
if ( V_125 ) {
F_9 ( V_38 , V_11 , 0x707e ,
L_82 , V_125 ) ;
return ( V_125 ) ;
}
V_11 = F_180 ( V_308 ) ;
if ( V_11 == NULL ) {
F_9 ( V_38 , V_11 , 0x707f , L_83 ) ;
return V_315 ;
}
if ( V_309 ) {
F_181 ( & V_11 -> V_316 , V_317 ) ;
F_182 ( V_308 , V_318 ) ;
} else
F_181 ( & V_11 -> V_316 , V_319 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_84 , V_11 -> V_221 ) ;
F_181 ( & V_11 -> V_153 , V_154 ) ;
V_11 -> V_320 = V_321 ;
V_11 -> V_322 = V_323 ;
if ( F_98 ( & V_94 -> V_153 ) == V_154 ||
F_98 ( & V_94 -> V_153 ) == V_155 ) {
F_21 ( V_32 , V_11 , 0x7081 ,
L_85 ) ;
F_181 ( & V_11 -> V_153 , V_155 ) ;
if ( ! V_309 )
F_182 ( V_308 , V_324 ) ;
}
if ( F_183 ( V_14 ) && V_325 ) {
if ( V_14 -> V_326 & V_327 ) {
int V_328 = 0 , V_329 ;
V_11 -> V_97 . V_330 = 1 ;
F_21 ( V_32 , V_11 , 0x7082 ,
L_86 ) ;
if ( V_325 == 1 )
V_328 = V_331 ;
F_184 ( V_11 -> V_96 ,
V_328 | V_332
| V_333
| V_334
| V_335
| V_336
| V_337 ) ;
V_329 = V_338 ;
if ( F_185 ( V_14 ) &&
( V_325 > 1 || F_186 ( V_14 ) ) )
V_329 |= V_339 ;
F_187 ( V_11 -> V_96 , V_329 ) ;
} else
V_11 -> V_97 . V_330 = 0 ;
}
if ( F_188 ( V_11 -> V_96 , & V_308 -> V_118 ,
& V_14 -> V_66 -> V_118 ) ) {
F_21 ( V_32 , V_11 , 0x7083 ,
L_87 , V_11 -> V_221 ) ;
goto V_340;
}
F_189 ( V_11 -> V_96 ) = V_14 -> V_341 ;
F_190 ( V_11 -> V_96 ) = F_146 ( V_11 -> V_231 ) ;
F_191 ( V_11 -> V_96 ) = F_146 ( V_11 -> V_235 ) ;
F_192 ( V_11 -> V_96 ) =
F_192 ( V_94 -> V_96 ) ;
F_193 ( V_11 -> V_96 ) =
F_193 ( V_94 -> V_96 ) ;
F_194 ( V_11 , V_14 ) ;
F_195 ( V_308 , V_309 ) ;
if ( V_14 -> V_97 . V_342 ) {
V_313 = V_14 -> V_314 [ 1 ] ;
F_21 ( V_343 , V_11 , 0xc000 ,
L_88
L_89 ,
V_313 , V_11 -> V_221 , V_14 -> V_97 . V_342 ) ;
goto V_344;
} else if ( V_345 == 1 || ! V_14 -> V_346 )
goto V_344;
for ( V_46 = 0 ; V_46 < V_14 -> V_347 ; V_46 ++ ) {
if ( memcmp ( V_14 -> V_346 [ V_46 ] . V_235 , V_11 -> V_235 , 8 ) == 0
&& memcmp ( V_14 -> V_346 [ V_46 ] . V_231 , V_11 -> V_231 ,
8 ) == 0 ) {
V_310 = V_14 -> V_346 [ V_46 ] . V_348 ;
break;
}
}
if ( V_310 ) {
V_125 = F_196 ( V_14 , V_311 , V_11 -> V_221 , 0 , 0 ,
V_310 ) ;
if ( ! V_125 )
F_9 ( V_38 , V_11 , 0x7084 ,
L_90 ,
V_11 -> V_221 ) ;
else {
F_21 ( V_343 , V_11 , 0xc001 ,
L_91 ,
V_125 , V_310 , V_11 -> V_221 ) ;
F_21 ( V_32 , V_11 , 0x7085 ,
L_91 ,
V_125 , V_310 , V_11 -> V_221 ) ;
V_313 = V_14 -> V_314 [ V_125 ] ;
}
}
V_344:
V_11 -> V_313 = V_313 ;
return 0 ;
V_340:
F_197 ( V_11 ) ;
F_198 ( V_11 ) ;
F_199 ( V_11 -> V_96 ) ;
return V_315 ;
}
static int
F_200 ( struct V_308 * V_308 )
{
T_8 * V_11 = V_308 -> V_240 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_233 = V_11 -> V_221 ;
while ( F_109 ( V_349 , & V_11 -> V_34 ) ||
F_109 ( V_350 , & V_11 -> V_34 ) )
F_201 ( 1000 ) ;
F_197 ( V_11 ) ;
V_11 -> V_97 . V_351 = 1 ;
F_202 ( V_14 , V_11 ) ;
F_203 ( V_11 -> V_96 ) ;
F_204 ( V_11 -> V_96 ) ;
F_198 ( V_11 ) ;
if ( V_11 -> V_352 ) {
F_205 ( V_11 ) ;
F_21 ( V_32 , V_11 , 0x7086 ,
L_92 , V_11 -> V_221 ) ;
}
F_206 ( F_98 ( & V_11 -> V_353 ) ) ;
F_207 ( V_11 ) ;
F_40 ( & V_14 -> V_354 ) ;
V_14 -> V_355 -- ;
F_208 ( V_11 -> V_221 , V_14 -> V_356 ) ;
F_41 ( & V_14 -> V_354 ) ;
if ( V_11 -> V_313 -> V_233 && ! V_14 -> V_97 . V_342 ) {
if ( F_209 ( V_11 , V_11 -> V_313 ) != V_51 )
F_9 ( V_38 , V_11 , 0x7087 ,
L_93 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_94 , V_233 ) ;
F_199 ( V_11 -> V_96 ) ;
return 0 ;
}
static int
F_195 ( struct V_308 * V_308 , bool V_309 )
{
T_8 * V_11 = V_308 -> V_240 ;
if ( V_309 )
F_197 ( V_11 ) ;
else
F_210 ( V_11 ) ;
return 0 ;
}
void
F_211 ( T_8 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_9 V_202 = V_203 ;
F_189 ( V_11 -> V_96 ) = V_14 -> V_341 ;
F_190 ( V_11 -> V_96 ) = F_146 ( V_11 -> V_231 ) ;
F_191 ( V_11 -> V_96 ) = F_146 ( V_11 -> V_235 ) ;
F_192 ( V_11 -> V_96 ) = V_14 -> V_357 . V_358 ?
( V_359 | V_360 ) : V_360 ;
F_212 ( V_11 -> V_96 ) = V_14 -> V_361 ;
F_213 ( V_11 -> V_96 ) = V_14 -> V_355 ;
if ( F_48 ( V_14 ) )
V_202 = V_214 ;
else if ( F_49 ( V_14 ) )
V_202 = V_216 | V_212 |
V_210 ;
else if ( F_47 ( V_14 ) )
V_202 = V_212 | V_210 |
V_208 | V_206 ;
else if ( F_46 ( V_14 ) )
V_202 = V_210 | V_208 |
V_206 ;
else if ( F_214 ( V_14 ) )
V_202 = V_208 | V_206 ;
else if ( F_90 ( V_14 ) )
V_202 = V_212 | V_210 |
V_208 | V_206 ;
else if ( F_50 ( V_14 ) )
V_202 = V_218 | V_216 |
V_212 ;
else
V_202 = V_206 ;
F_193 ( V_11 -> V_96 ) = V_202 ;
}
