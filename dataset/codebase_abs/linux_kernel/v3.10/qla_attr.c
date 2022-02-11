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
if ( F_5 ( V_11 -> V_15 ) ) {
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
if ( F_5 ( V_14 ) ) {
F_13 ( V_14 ) ;
F_14 ( V_11 ) ;
F_15 ( V_14 ) ;
} else
F_16 ( V_11 ) ;
break;
case 4 :
if ( F_5 ( V_14 ) ) {
if ( V_14 -> V_20 )
F_17 ( V_32 , V_11 , 0x705b ,
L_3 ) ;
else
F_17 ( V_32 , V_11 , 0x709d ,
L_4 ) ;
}
break;
case 5 :
if ( F_5 ( V_14 ) )
F_18 ( V_33 , & V_11 -> V_34 ) ;
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
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_20 ( V_35 ) )
return 0 ;
if ( F_21 ( V_14 ) )
V_14 -> V_36 -> V_37 ( V_11 , V_14 -> V_38 , V_14 -> V_39 << 2 ,
V_14 -> V_40 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_38 ,
V_14 -> V_40 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_41 ;
if ( ! F_20 ( V_35 ) || V_8 != 0 || V_9 != V_14 -> V_40 ||
! V_14 -> V_36 -> V_42 )
return - V_43 ;
if ( F_23 ( V_14 ) ) {
T_5 * V_44 ;
T_5 V_45 ;
V_44 = ( T_5 * ) V_7 ;
V_45 = 0 ;
for ( V_41 = 0 ; V_41 < ( ( V_9 >> 2 ) - 1 ) ; V_41 ++ )
V_45 += F_24 ( * V_44 ++ ) ;
V_45 = ~ V_45 + 1 ;
* V_44 = F_25 ( V_45 ) ;
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
if ( F_26 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x705f ,
L_7 ) ;
return - V_48 ;
}
V_14 -> V_36 -> V_42 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_49 , V_9 ) ;
V_14 -> V_36 -> V_50 ( V_11 , ( T_6 * ) V_14 -> V_38 , V_14 -> V_49 ,
V_9 ) ;
F_17 ( V_32 , V_11 , 0x7060 ,
L_8 ) ;
F_18 ( V_33 , & V_11 -> V_34 ) ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
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
if ( V_14 -> V_51 != V_52 )
return 0 ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_53 ,
V_14 -> V_54 ) ;
}
static T_1
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 -> V_51 != V_55 )
return - V_43 ;
if ( V_8 > V_14 -> V_54 )
return - V_56 ;
if ( V_8 + V_9 > V_14 -> V_54 )
V_9 = V_14 -> V_54 - V_8 ;
memcpy ( & V_14 -> V_53 [ V_8 ] , V_7 , V_9 ) ;
return V_9 ;
}
static T_1
F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_57 = 0 ;
T_5 V_58 = V_14 -> V_59 ;
int V_60 , V_61 ;
if ( V_8 )
return - V_43 ;
if ( F_32 ( F_33 ( V_14 -> V_62 ) ) )
return - V_48 ;
if ( sscanf ( V_7 , L_9 , & V_60 , & V_57 , & V_58 ) < 1 )
return - V_43 ;
if ( V_57 > V_14 -> V_59 )
return - V_43 ;
switch ( V_60 ) {
case 0 :
if ( V_14 -> V_51 != V_52 &&
V_14 -> V_51 != V_55 )
return - V_43 ;
V_14 -> V_51 = V_63 ;
F_17 ( V_32 , V_11 , 0x7061 ,
L_10 ,
V_14 -> V_54 ) ;
F_34 ( V_14 -> V_53 ) ;
V_14 -> V_53 = NULL ;
break;
case 1 :
if ( V_14 -> V_51 != V_63 )
return - V_43 ;
V_14 -> V_64 = V_57 ;
V_14 -> V_54 = V_57 + V_58 > V_14 -> V_59 ?
V_14 -> V_59 - V_57 : V_58 ;
V_14 -> V_51 = V_52 ;
V_14 -> V_53 = F_35 ( V_14 -> V_54 ) ;
if ( V_14 -> V_53 == NULL ) {
F_9 ( V_47 , V_11 , 0x7062 ,
L_11
L_12 , V_14 -> V_54 ) ;
V_14 -> V_51 = V_63 ;
return - V_65 ;
}
if ( F_26 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x7063 ,
L_7 ) ;
return - V_48 ;
}
F_17 ( V_32 , V_11 , 0x7064 ,
L_13 ,
V_14 -> V_64 , V_14 -> V_54 ) ;
memset ( V_14 -> V_53 , 0 , V_14 -> V_54 ) ;
V_14 -> V_36 -> V_37 ( V_11 , V_14 -> V_53 ,
V_14 -> V_64 , V_14 -> V_54 ) ;
break;
case 2 :
if ( V_14 -> V_51 != V_63 )
return - V_43 ;
V_61 = 0 ;
if ( V_14 -> V_59 == V_66 && V_57 == 0 )
V_61 = 1 ;
else if ( V_57 == ( V_14 -> V_67 * 4 ) ||
V_57 == ( V_14 -> V_68 * 4 ) )
V_61 = 1 ;
else if ( F_36 ( V_14 ) || F_37 ( V_14 )
|| F_38 ( V_14 ) || F_39 ( V_14 ) )
V_61 = 1 ;
if ( ! V_61 ) {
F_9 ( V_47 , V_11 , 0x7065 ,
L_14 , V_57 , V_58 ) ;
return - V_43 ;
}
V_14 -> V_64 = V_57 ;
V_14 -> V_54 = V_57 + V_58 > V_14 -> V_59 ?
V_14 -> V_59 - V_57 : V_58 ;
V_14 -> V_51 = V_55 ;
V_14 -> V_53 = F_35 ( V_14 -> V_54 ) ;
if ( V_14 -> V_53 == NULL ) {
F_9 ( V_47 , V_11 , 0x7066 ,
L_15
L_16 , V_14 -> V_54 ) ;
V_14 -> V_51 = V_63 ;
return - V_65 ;
}
F_17 ( V_32 , V_11 , 0x7067 ,
L_17 ,
V_14 -> V_64 , V_14 -> V_54 ) ;
memset ( V_14 -> V_53 , 0 , V_14 -> V_54 ) ;
break;
case 3 :
if ( V_14 -> V_51 != V_55 )
return - V_43 ;
if ( F_26 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x7068 ,
L_18 ) ;
return - V_48 ;
}
F_17 ( V_32 , V_11 , 0x7069 ,
L_19 ,
V_14 -> V_64 , V_14 -> V_54 ) ;
V_14 -> V_36 -> V_69 ( V_11 , V_14 -> V_53 ,
V_14 -> V_64 , V_14 -> V_54 ) ;
break;
default:
return - V_43 ;
}
return V_9 ;
}
static T_1
F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_32 ( F_33 ( V_14 -> V_62 ) ) )
return - V_48 ;
if ( ! F_20 ( V_35 ) )
return - V_43 ;
if ( F_21 ( V_14 ) )
V_14 -> V_36 -> V_37 ( V_11 , V_14 -> V_70 , V_14 -> V_71 << 2 ,
V_14 -> V_72 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_70 , V_14 -> V_72 ) ;
}
static T_1
F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_73 ;
if ( F_32 ( F_33 ( V_14 -> V_62 ) ) )
return 0 ;
if ( ! F_20 ( V_35 ) || V_8 != 0 || V_9 != V_14 -> V_72 ||
! V_14 -> V_36 -> V_42 )
return 0 ;
if ( F_26 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x706a ,
L_20 ) ;
return - V_48 ;
}
V_14 -> V_36 -> V_42 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_74 , V_9 ) ;
V_14 -> V_36 -> V_50 ( V_11 , ( T_6 * ) V_14 -> V_70 , V_14 -> V_74 , V_9 ) ;
if ( ! F_23 ( V_14 ) )
return - V_43 ;
V_73 = F_35 ( 256 ) ;
if ( ! V_73 ) {
F_9 ( V_47 , V_11 , 0x706b ,
L_21 ) ;
return - V_65 ;
}
V_14 -> V_36 -> V_75 ( V_11 , V_73 ) ;
F_34 ( V_73 ) ;
return V_9 ;
}
static T_1
F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_44 , V_76 , V_77 ;
int V_16 ;
if ( ! F_20 ( V_35 ) || V_8 != 0 || V_9 != V_78 * 2 )
return 0 ;
if ( V_14 -> V_79 )
goto V_80;
V_14 -> V_79 = F_43 ( V_14 -> V_81 , V_82 ,
& V_14 -> V_83 ) ;
if ( ! V_14 -> V_79 ) {
F_9 ( V_47 , V_11 , 0x706c ,
L_22 ) ;
return 0 ;
}
V_80:
memset ( V_14 -> V_79 , 0 , V_84 ) ;
V_76 = 0xa0 ;
for ( V_44 = 0 , V_77 = 0 ; V_44 < ( V_78 * 2 ) / V_84 ;
V_44 ++ , V_77 += V_84 ) {
if ( V_44 == 4 ) {
V_76 = 0xa2 ;
V_77 = 0 ;
}
V_16 = F_44 ( V_11 , V_14 -> V_83 , V_14 -> V_79 ,
V_76 , V_77 , V_84 , 0 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x706d ,
L_23 , V_16 ,
V_76 , V_77 ) ;
return - V_85 ;
}
memcpy ( V_7 , V_14 -> V_79 , V_84 ) ;
V_7 += V_84 ;
}
return V_9 ;
}
static T_1
F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_86 = F_46 ( V_14 -> V_62 ) ;
int type ;
T_5 V_87 ;
if ( V_8 != 0 )
return - V_43 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_29 , V_11 , 0x706e ,
L_24 ) ;
F_47 ( V_11 -> V_88 ) ;
F_18 ( V_33 , & V_11 -> V_34 ) ;
if ( F_5 ( V_14 ) ) {
V_14 -> V_89 . V_90 = 1 ;
F_13 ( V_14 ) ;
F_14 ( V_11 ) ;
F_15 ( V_14 ) ;
}
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_48 ( V_11 -> V_88 ) ;
break;
case 0x2025d :
if ( ! F_49 ( V_14 ) && ! F_50 ( V_14 ) )
return - V_91 ;
F_9 ( V_29 , V_11 , 0x706f ,
L_25 ) ;
if ( F_50 ( V_14 ) ) {
T_5 V_87 ;
F_51 ( V_11 , 0 ) ;
F_52 ( V_11 , & V_87 ) ;
V_87 |= V_92 ;
F_53 ( V_11 , V_87 ) ;
F_54 ( V_11 , V_93 ,
V_94 ) ;
F_55 ( V_11 , V_95 ) ;
F_56 ( V_11 , 0 ) ;
break;
} else {
F_26 ( V_11 ) ;
F_47 ( V_11 -> V_88 ) ;
if ( F_57 ( V_11 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7070 ,
L_26 ) ;
F_48 ( V_11 -> V_88 ) ;
break;
}
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_86 ) {
F_9 ( V_29 , V_11 , 0x7071 ,
L_27 ) ;
return - V_91 ;
}
F_9 ( V_29 , V_11 , 0x7072 ,
L_28 ) ;
F_18 ( V_96 , & V_11 -> V_34 ) ;
F_27 ( V_11 ) ;
F_58 ( V_11 ) ;
break;
case 0x2025f :
if ( ! F_59 ( V_14 ) )
return - V_91 ;
F_9 ( V_29 , V_11 , 0x70bc ,
L_29 ) ;
F_51 ( V_11 , 0 ) ;
F_52 ( V_11 , & V_87 ) ;
V_87 |= V_97 ;
F_53 ( V_11 , V_87 ) ;
F_56 ( V_11 , 0 ) ;
break;
case 0x20260 :
if ( ! F_59 ( V_14 ) )
return - V_91 ;
F_9 ( V_29 , V_11 , 0x70bd ,
L_30 ) ;
F_51 ( V_11 , 0 ) ;
F_52 ( V_11 , & V_87 ) ;
V_87 &= ~ V_97 ;
F_53 ( V_11 , V_87 ) ;
F_56 ( V_11 , 0 ) ;
break;
}
return V_9 ;
}
static T_1
F_60 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_4 V_98 ;
if ( ! F_20 ( V_35 ) || V_8 != 0 || V_9 > V_99 )
return 0 ;
if ( V_14 -> V_100 )
goto V_80;
V_14 -> V_100 = F_61 ( & V_14 -> V_62 -> V_101 , V_99 ,
& V_14 -> V_102 , V_82 ) ;
if ( ! V_14 -> V_100 ) {
F_9 ( V_47 , V_11 , 0x7076 ,
L_31 ) ;
return 0 ;
}
V_80:
V_98 = 0 ;
memset ( V_14 -> V_100 , 0 , V_99 ) ;
V_16 = F_62 ( V_11 , V_14 -> V_102 ,
V_99 , & V_98 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7077 ,
L_32 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_98 > V_9 ? V_9 : V_98 ;
memcpy ( V_7 , V_14 -> V_100 , V_9 ) ;
return V_9 ;
}
static T_1
F_63 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_4 V_98 ;
if ( ! F_20 ( V_35 ) || V_8 != 0 || V_9 > V_103 )
return 0 ;
if ( V_14 -> V_104 )
goto V_80;
V_14 -> V_104 = F_61 ( & V_14 -> V_62 -> V_101 , V_103 ,
& V_14 -> V_105 , V_82 ) ;
if ( ! V_14 -> V_104 ) {
F_9 ( V_47 , V_11 , 0x7078 ,
L_33 ) ;
return - V_65 ;
}
V_80:
V_98 = 0 ;
memset ( V_14 -> V_104 , 0 , V_103 ) ;
V_16 = F_64 ( V_11 , V_14 -> V_105 ,
V_103 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7079 ,
L_34 , V_16 ) ;
return - V_85 ;
}
memcpy ( V_7 , V_14 -> V_104 , V_9 ) ;
return V_9 ;
}
void
F_65 ( T_7 * V_11 )
{
struct V_106 * V_88 = V_11 -> V_88 ;
struct V_107 * V_44 ;
int V_108 ;
for ( V_44 = V_109 ; V_44 -> V_110 ; V_44 ++ ) {
if ( V_44 -> V_111 && ! F_23 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_111 == 2 && ! F_37 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_111 == 3 && ! ( F_38 ( V_11 -> V_15 ) ) )
continue;
V_108 = F_66 ( & V_88 -> V_112 . V_4 ,
V_44 -> V_113 ) ;
if ( V_108 )
F_9 ( V_47 , V_11 , 0x00f3 ,
L_35 ,
V_44 -> V_110 , V_108 ) ;
else
F_17 ( V_114 , V_11 , 0x00f4 ,
L_36 ,
V_44 -> V_110 ) ;
}
}
void
F_67 ( T_7 * V_11 )
{
struct V_106 * V_88 = V_11 -> V_88 ;
struct V_107 * V_44 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_44 = V_109 ; V_44 -> V_110 ; V_44 ++ ) {
if ( V_44 -> V_111 && ! F_23 ( V_14 ) )
continue;
if ( V_44 -> V_111 == 2 && ! F_37 ( V_14 ) )
continue;
if ( V_44 -> V_111 == 3 && ! ( F_38 ( V_11 -> V_15 ) ) )
continue;
F_68 ( & V_88 -> V_112 . V_4 ,
V_44 -> V_113 ) ;
}
if ( V_14 -> V_115 == 1 )
V_14 -> V_36 -> V_116 ( V_11 ) ;
}
static T_1
F_69 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
return snprintf ( V_7 , V_118 , L_37 , V_119 ) ;
}
static T_1
F_70 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_120 [ 128 ] ;
return snprintf ( V_7 , V_118 , L_37 ,
V_14 -> V_36 -> V_121 ( V_11 , V_120 ) ) ;
}
static T_1
F_72 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_122 ;
if ( F_73 ( V_11 -> V_15 ) ) {
return snprintf ( V_7 , V_118 , L_37 ,
V_11 -> V_15 -> V_123 . V_124 ) ;
} else if ( F_23 ( V_14 ) ) {
F_74 ( V_11 , L_38 , V_7 , V_118 ) ;
return snprintf ( V_7 , V_118 , L_37 , V_7 ) ;
}
V_122 = ( ( V_14 -> V_125 & 0x1f ) << 16 ) | ( V_14 -> V_126 << 8 ) | V_14 -> V_127 ;
return snprintf ( V_7 , V_118 , L_39 , 'A' + V_122 / 100000 ,
V_122 % 100000 ) ;
}
static T_1
F_75 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_40 , V_11 -> V_15 -> V_62 -> V_12 ) ;
}
static T_1
F_76 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_73 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_37 ,
V_11 -> V_15 -> V_123 . V_128 ) ;
return snprintf ( V_7 , V_118 , L_41 ,
V_14 -> V_129 [ 0 ] , V_14 -> V_129 [ 1 ] , V_14 -> V_129 [ 2 ] ,
V_14 -> V_129 [ 3 ] ) ;
}
static T_1
F_77 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( F_73 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_37 ,
V_11 -> V_15 -> V_123 . V_130 ) ;
return snprintf ( V_7 , V_118 , L_37 , V_11 -> V_15 -> V_131 ) ;
}
static T_1
F_78 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_37 ,
V_11 -> V_15 -> V_132 ? V_11 -> V_15 -> V_132 : L_42 ) ;
}
static T_1
F_79 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
char V_133 [ 30 ] ;
return snprintf ( V_7 , V_118 , L_37 ,
V_11 -> V_15 -> V_36 -> V_134 ( V_11 , V_133 ) ) ;
}
static T_1
F_80 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_135 = 0 ;
if ( F_81 ( & V_11 -> V_136 ) == V_137 ||
F_81 ( & V_11 -> V_136 ) == V_138 ||
V_11 -> V_139 & V_140 )
V_135 = snprintf ( V_7 , V_118 , L_43 ) ;
else if ( F_81 ( & V_11 -> V_136 ) != V_141 ||
F_82 ( V_11 ) )
V_135 = snprintf ( V_7 , V_118 , L_44 ) ;
else {
V_135 = snprintf ( V_7 , V_118 , L_45 ) ;
switch ( V_14 -> V_142 ) {
case V_143 :
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_46 ) ;
break;
case V_144 :
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_47 ) ;
break;
case V_145 :
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 ,
L_48 ) ;
break;
case V_146 :
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_49 ) ;
break;
default:
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_46 ) ;
break;
}
}
return V_135 ;
}
static T_1
F_83 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_135 = 0 ;
switch ( V_11 -> V_15 -> V_147 ) {
case V_148 :
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_50 ) ;
break;
case V_149 :
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_51 ) ;
break;
}
return V_135 ;
}
static T_1
F_84 ( struct V_12 * V_101 , struct V_117 * V_113 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_60 = 0 ;
T_4 V_147 ;
if ( ! F_85 ( V_14 ) )
return - V_150 ;
if ( sscanf ( V_7 , L_52 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 )
V_147 = V_148 ;
else
V_147 = V_149 ;
if ( V_147 != V_149 || V_14 -> V_147 != V_149 ) {
V_14 -> V_147 = V_147 ;
F_18 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_86 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_53 , V_11 -> V_15 -> V_151 * 100 ) ;
}
static T_1
F_87 ( struct V_12 * V_101 , struct V_117 * V_113 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_60 = 0 ;
T_4 V_151 ;
if ( sscanf ( V_7 , L_52 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 > 25500 || V_60 < 100 )
return - V_56 ;
V_151 = ( T_4 ) ( V_60 / 100 ) ;
V_11 -> V_15 -> V_151 = V_151 ;
return strlen ( V_7 ) ;
}
static T_1
F_88 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_135 = 0 ;
if ( V_11 -> V_15 -> V_115 )
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_54 ) ;
else
V_135 += snprintf ( V_7 + V_135 , V_118 - V_135 , L_51 ) ;
return V_135 ;
}
static T_1
F_89 ( struct V_12 * V_101 , struct V_117 * V_113 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_60 = 0 ;
int V_16 ;
if ( F_90 ( V_14 ) || F_91 ( V_14 ) )
return - V_91 ;
if ( F_92 ( V_152 , & V_11 -> V_34 ) ) {
F_9 ( V_47 , V_11 , 0x707a ,
L_55 ) ;
return - V_153 ;
}
if ( sscanf ( V_7 , L_52 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 )
V_16 = V_14 -> V_36 -> V_154 ( V_11 ) ;
else
V_16 = V_14 -> V_36 -> V_116 ( V_11 ) ;
if ( V_16 != V_46 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_93 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_56 , V_14 -> V_155 [ 1 ] ,
V_14 -> V_155 [ 0 ] ) ;
}
static T_1
F_94 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_56 , V_14 -> V_156 [ 1 ] ,
V_14 -> V_156 [ 0 ] ) ;
}
static T_1
F_95 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_56 , V_14 -> V_157 [ 1 ] ,
V_14 -> V_157 [ 0 ] ) ;
}
static T_1
F_96 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_57 ,
V_14 -> V_158 [ 0 ] , V_14 -> V_158 [ 1 ] , V_14 -> V_158 [ 2 ] ,
V_14 -> V_158 [ 3 ] ) ;
}
static T_1
F_97 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_50 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_59 ,
V_14 -> V_159 [ 0 ] , V_14 -> V_159 [ 1 ] ,
V_14 -> V_159 [ 2 ] , V_14 -> V_159 [ 3 ] ) ;
}
static T_1
F_98 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_60 ,
V_11 -> V_160 . V_161 ) ;
}
static T_1
F_99 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
int V_16 = V_46 ;
T_4 V_162 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_100 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
if ( V_14 -> V_163 -> V_164 == 0 )
V_16 = F_101 ( V_11 , V_162 ) ;
if ( ( V_16 == V_46 ) && ( V_162 [ 0 ] == 0 ) )
return snprintf ( V_7 , V_118 , L_61 ,
( T_5 ) V_14 -> V_163 -> V_164 ) ;
return snprintf ( V_7 , V_118 , L_58 ) ;
}
static T_1
F_102 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_59 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_62 ,
V_14 -> V_165 [ 0 ] , V_14 -> V_165 [ 1 ] , V_14 -> V_165 [ 2 ] ,
V_14 -> V_166 ) ;
}
static T_1
F_103 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_59 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_63 ,
V_14 -> V_167 [ 0 ] , V_14 -> V_167 [ 1 ] , V_14 -> V_167 [ 2 ] ) ;
}
static T_1
F_104 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_64 , V_14 -> V_168 ) ;
}
static T_1
F_105 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_60 , V_11 -> V_169 ) ;
}
static T_1
F_106 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_65 ,
V_11 -> V_170 [ 5 ] , V_11 -> V_170 [ 4 ] ,
V_11 -> V_170 [ 3 ] , V_11 -> V_170 [ 2 ] ,
V_11 -> V_170 [ 1 ] , V_11 -> V_170 [ 0 ] ) ;
}
static T_1
F_107 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_60 , V_11 -> V_15 -> V_171 ) ;
}
static T_1
F_108 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
T_4 V_172 = 0 ;
if ( ! V_11 -> V_15 -> V_173 ) {
F_9 ( V_47 , V_11 , 0x70db ,
L_66 ) ;
goto V_174;
}
if ( F_82 ( V_11 ) ) {
F_9 ( V_47 , V_11 , 0x70dc , L_67 ) ;
goto V_174;
}
if ( V_11 -> V_15 -> V_89 . V_175 ) {
F_9 ( V_47 , V_11 , 0x70dd , L_68 ) ;
goto V_174;
}
if ( F_109 ( V_11 , & V_172 ) == V_46 )
return snprintf ( V_7 , V_118 , L_60 , V_172 ) ;
V_174:
return snprintf ( V_7 , V_118 , L_58 ) ;
}
static T_1
F_110 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_16 = V_176 ;
T_4 V_177 [ 5 ] ;
T_5 V_178 ;
if ( F_73 ( V_11 -> V_15 ) ) {
V_178 = F_111 ( V_101 , V_113 , V_7 ) ;
return snprintf ( V_7 , V_118 , L_64 , V_178 ) ;
}
if ( F_82 ( V_11 ) )
F_9 ( V_47 , V_11 , 0x707c ,
L_67 ) ;
else if ( ! V_11 -> V_15 -> V_89 . V_175 )
V_16 = F_112 ( V_11 , V_177 ) ;
if ( V_16 != V_46 )
memset ( V_177 , - 1 , sizeof( V_177 ) ) ;
return snprintf ( V_7 , V_118 , L_69 , V_177 [ 0 ] ,
V_177 [ 1 ] , V_177 [ 2 ] , V_177 [ 3 ] , V_177 [ 4 ] ) ;
}
static T_1
F_113 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_114 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_70 , V_11 -> V_179 . V_180 ) ;
}
static T_1
F_115 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_114 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_70 ,
V_11 -> V_179 . V_181 >> 20 ) ;
}
static T_1
F_116 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_58 ;
if ( ! V_14 -> V_31 )
V_58 = 0 ;
else if ( F_5 ( V_14 ) )
V_58 = V_14 -> V_19 + V_14 -> V_22 ;
else
V_58 = V_14 -> V_27 ;
return snprintf ( V_7 , V_118 , L_60 , V_58 ) ;
}
static void
F_117 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
F_118 ( V_182 ) = V_11 -> V_183 . V_184 . V_185 << 16 |
V_11 -> V_183 . V_184 . V_186 << 8 | V_11 -> V_183 . V_184 . V_187 ;
}
static void
F_119 ( struct V_106 * V_182 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_182 ) ) ) -> V_15 ;
T_8 V_188 = V_189 ;
if ( F_73 ( V_14 ) ) {
F_120 ( V_182 ) ;
return;
}
switch ( V_14 -> V_190 ) {
case V_191 :
V_188 = V_192 ;
break;
case V_193 :
V_188 = V_194 ;
break;
case V_195 :
V_188 = V_196 ;
break;
case V_197 :
V_188 = V_198 ;
break;
case V_199 :
V_188 = V_200 ;
break;
case V_201 :
V_188 = V_202 ;
break;
}
F_121 ( V_182 ) = V_188 ;
}
static void
F_122 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
T_5 V_203 = V_204 ;
if ( V_11 -> V_205 ) {
F_123 ( V_182 ) = V_206 ;
return;
}
switch ( V_11 -> V_15 -> V_142 ) {
case V_143 :
V_203 = V_207 ;
break;
case V_144 :
V_203 = V_208 ;
break;
case V_145 :
V_203 = V_209 ;
break;
case V_146 :
V_203 = V_210 ;
break;
}
F_123 ( V_182 ) = V_203 ;
}
static void
F_124 ( struct V_211 * V_212 )
{
struct V_106 * V_88 = F_3 ( V_212 -> V_101 . V_213 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_214 ;
T_10 V_215 = 0 ;
F_125 (fcport, &vha->vp_fcports, list) {
if ( V_214 -> V_216 &&
V_212 -> V_217 == V_214 -> V_216 -> V_218 ) {
V_215 = F_126 ( V_214 -> V_215 ) ;
break;
}
}
F_127 ( V_212 ) = V_215 ;
}
static void
F_128 ( struct V_211 * V_212 )
{
struct V_106 * V_88 = F_3 ( V_212 -> V_101 . V_213 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_214 ;
T_10 V_219 = 0 ;
F_125 (fcport, &vha->vp_fcports, list) {
if ( V_214 -> V_216 &&
V_212 -> V_217 == V_214 -> V_216 -> V_218 ) {
V_219 = F_126 ( V_214 -> V_219 ) ;
break;
}
}
F_129 ( V_212 ) = V_219 ;
}
static void
F_130 ( struct V_211 * V_212 )
{
struct V_106 * V_88 = F_3 ( V_212 -> V_101 . V_213 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_214 ;
T_5 V_220 = ~ 0U ;
F_125 (fcport, &vha->vp_fcports, list) {
if ( V_214 -> V_216 &&
V_212 -> V_217 == V_214 -> V_216 -> V_218 ) {
V_220 = V_214 -> V_183 . V_184 . V_185 << 16 |
V_214 -> V_183 . V_184 . V_186 << 8 | V_214 -> V_183 . V_184 . V_187 ;
break;
}
}
F_131 ( V_212 ) = V_220 ;
}
static void
F_132 ( struct V_221 * V_216 , T_5 V_222 )
{
if ( V_222 )
V_216 -> V_223 = V_222 ;
else
V_216 -> V_223 = 1 ;
}
static void
F_133 ( struct V_221 * V_216 )
{
struct V_106 * V_88 = F_134 ( V_216 ) ;
T_9 * V_214 = * ( T_9 * * ) V_216 -> V_224 ;
unsigned long V_89 ;
if ( ! V_214 )
return;
F_135 ( V_214 , V_225 ) ;
F_136 ( V_88 -> V_226 , V_89 ) ;
V_214 -> V_216 = V_214 -> V_227 = NULL ;
* ( ( T_9 * * ) V_216 -> V_224 ) = NULL ;
F_137 ( V_88 -> V_226 , V_89 ) ;
if ( F_92 ( V_152 , & V_214 -> V_11 -> V_34 ) )
return;
if ( F_32 ( F_33 ( V_214 -> V_11 -> V_15 -> V_62 ) ) ) {
F_138 ( V_214 -> V_11 , V_228 << 16 ) ;
return;
}
}
static void
F_139 ( struct V_221 * V_216 )
{
T_9 * V_214 = * ( T_9 * * ) V_216 -> V_224 ;
if ( ! V_214 )
return;
if ( F_92 ( V_152 , & V_214 -> V_11 -> V_34 ) )
return;
if ( F_32 ( F_33 ( V_214 -> V_11 -> V_15 -> V_62 ) ) ) {
F_138 ( V_214 -> V_11 , V_228 << 16 ) ;
return;
}
if ( V_214 -> V_229 != V_230 ) {
if ( F_23 ( V_214 -> V_11 -> V_15 ) )
V_214 -> V_11 -> V_15 -> V_36 -> V_231 ( V_214 -> V_11 ,
V_214 -> V_229 , V_214 -> V_183 . V_184 . V_185 ,
V_214 -> V_183 . V_184 . V_186 , V_214 -> V_183 . V_184 . V_187 ) ;
else
F_140 ( V_214 -> V_11 , V_214 ) ;
}
}
static int
F_141 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
if ( F_73 ( V_11 -> V_15 ) )
return 0 ;
F_142 ( V_11 ) ;
return 0 ;
}
static struct V_232 *
F_143 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_86 = F_46 ( V_14 -> V_62 ) ;
int V_16 ;
struct V_233 * V_234 ;
T_11 V_235 ;
struct V_232 * V_236 ;
V_236 = & V_11 -> V_237 ;
memset ( V_236 , - 1 , sizeof( struct V_232 ) ) ;
if ( F_73 ( V_11 -> V_15 ) )
goto V_174;
if ( F_92 ( V_238 , & V_11 -> V_34 ) )
goto V_174;
if ( F_32 ( F_33 ( V_14 -> V_62 ) ) )
goto V_174;
V_234 = F_43 ( V_14 -> V_81 , V_82 , & V_235 ) ;
if ( V_234 == NULL ) {
F_9 ( V_47 , V_11 , 0x707d ,
L_71 ) ;
goto V_174;
}
memset ( V_234 , 0 , V_239 ) ;
V_16 = V_176 ;
if ( F_23 ( V_14 ) ) {
V_16 = F_144 ( V_86 , V_234 , V_235 ) ;
} else if ( F_81 ( & V_86 -> V_136 ) == V_141 &&
! F_82 ( V_11 ) && ! V_14 -> V_240 ) {
V_16 = F_145 ( V_86 , V_86 -> V_229 ,
V_234 , V_235 ) ;
}
if ( V_16 != V_46 )
goto V_241;
V_236 -> V_242 = V_234 -> V_243 ;
V_236 -> V_244 = V_234 -> V_245 ;
V_236 -> V_246 = V_234 -> V_247 ;
V_236 -> V_248 = V_234 -> V_249 ;
V_236 -> V_250 = V_234 -> V_251 ;
V_236 -> V_252 = V_234 -> V_253 ;
if ( F_23 ( V_14 ) ) {
V_236 -> V_254 = V_234 -> V_255 ;
V_236 -> V_256 = V_234 -> V_256 ;
V_236 -> V_257 = V_234 -> V_257 ;
V_236 -> V_258 = V_234 -> V_258 ;
V_236 -> V_259 = V_234 -> V_260 ;
}
V_236 -> V_261 = V_11 -> V_160 . V_262 >> 20 ;
V_236 -> V_263 = V_11 -> V_160 . V_264 >> 20 ;
V_241:
F_146 ( V_14 -> V_81 , V_234 , V_235 ) ;
V_174:
return V_236 ;
}
static void
F_147 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
F_148 ( V_11 , F_149 ( V_182 ) ) ;
}
static void
F_150 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
F_18 ( V_265 , & V_11 -> V_34 ) ;
}
static void
F_151 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
T_6 V_215 [ V_266 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_267 = F_126 ( V_215 ) ;
if ( V_11 -> V_139 & V_268 )
V_267 = F_126 ( V_11 -> V_269 ) ;
F_152 ( V_182 ) = V_267 ;
}
static void
F_153 ( struct V_106 * V_182 )
{
T_7 * V_11 = F_2 ( V_182 ) ;
struct V_10 * V_86 = F_46 ( V_11 -> V_15 -> V_62 ) ;
if ( ! V_86 -> V_89 . V_270 ) {
F_154 ( V_182 ) = V_271 ;
return;
}
switch ( F_81 ( & V_86 -> V_136 ) ) {
case V_272 :
F_154 ( V_182 ) = V_273 ;
break;
case V_137 :
if ( F_92 ( V_274 , & V_86 -> V_34 ) )
F_154 ( V_182 ) = V_273 ;
else
F_154 ( V_182 ) = V_275 ;
break;
case V_138 :
F_154 ( V_182 ) = V_275 ;
break;
case V_141 :
F_154 ( V_182 ) = V_276 ;
break;
default:
F_154 ( V_182 ) = V_277 ;
break;
}
}
static int
F_155 ( struct V_278 * V_278 , bool V_279 )
{
int V_108 = 0 ;
T_6 V_280 = 0 ;
T_7 * V_86 = F_2 ( V_278 -> V_182 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_86 -> V_15 ;
T_4 V_281 = 0 ;
int V_41 ;
struct V_282 * V_283 = V_14 -> V_284 [ 0 ] ;
V_108 = F_156 ( V_278 ) ;
if ( V_108 ) {
F_9 ( V_47 , V_11 , 0x707e ,
L_72 , V_108 ) ;
return ( V_108 ) ;
}
V_11 = F_157 ( V_278 ) ;
if ( V_11 == NULL ) {
F_9 ( V_47 , V_11 , 0x707f , L_73 ) ;
return V_285 ;
}
if ( V_279 ) {
F_158 ( & V_11 -> V_286 , V_287 ) ;
F_159 ( V_278 , V_288 ) ;
} else
F_158 ( & V_11 -> V_286 , V_289 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_74 , V_11 -> V_205 ) ;
F_158 ( & V_11 -> V_136 , V_137 ) ;
V_11 -> V_290 = V_291 ;
V_11 -> V_292 = V_293 ;
if ( F_81 ( & V_86 -> V_136 ) == V_137 ||
F_81 ( & V_86 -> V_136 ) == V_138 ) {
F_17 ( V_32 , V_11 , 0x7081 ,
L_75 ) ;
F_158 ( & V_11 -> V_136 , V_138 ) ;
if ( ! V_279 )
F_159 ( V_278 , V_294 ) ;
}
if ( F_160 ( V_14 ) && V_295 ) {
if ( V_14 -> V_296 & V_297 ) {
int V_298 = 0 , V_299 ;
V_11 -> V_89 . V_300 = 1 ;
F_17 ( V_32 , V_11 , 0x7082 ,
L_76 ) ;
if ( V_295 == 1 )
V_298 = V_301 ;
F_161 ( V_11 -> V_88 ,
V_298 | V_302
| V_303
| V_304
| V_305
| V_306
| V_307 ) ;
V_299 = V_308 ;
if ( F_162 ( V_14 ) &&
( V_295 > 1 || F_163 ( V_14 ) ) )
V_299 |= V_309 ;
F_164 ( V_11 -> V_88 , V_299 ) ;
} else
V_11 -> V_89 . V_300 = 0 ;
}
if ( F_165 ( V_11 -> V_88 , & V_278 -> V_101 ,
& V_14 -> V_62 -> V_101 ) ) {
F_17 ( V_32 , V_11 , 0x7083 ,
L_77 , V_11 -> V_205 ) ;
goto V_310;
}
F_166 ( V_11 -> V_88 ) = V_14 -> V_311 ;
F_167 ( V_11 -> V_88 ) = F_126 ( V_11 -> V_215 ) ;
F_168 ( V_11 -> V_88 ) = F_126 ( V_11 -> V_219 ) ;
F_169 ( V_11 -> V_88 ) =
F_169 ( V_86 -> V_88 ) ;
F_170 ( V_11 -> V_88 ) =
F_170 ( V_86 -> V_88 ) ;
F_171 ( V_11 , V_14 ) ;
F_172 ( V_278 , V_279 ) ;
if ( V_14 -> V_89 . V_312 ) {
V_283 = V_14 -> V_284 [ 1 ] ;
F_17 ( V_313 , V_11 , 0xc000 ,
L_78
L_79 ,
V_283 , V_11 -> V_205 , V_14 -> V_89 . V_312 ) ;
goto V_314;
} else if ( V_315 == 1 || ! V_14 -> V_316 )
goto V_314;
for ( V_41 = 0 ; V_41 < V_14 -> V_317 ; V_41 ++ ) {
if ( memcmp ( V_14 -> V_316 [ V_41 ] . V_219 , V_11 -> V_219 , 8 ) == 0
&& memcmp ( V_14 -> V_316 [ V_41 ] . V_215 , V_11 -> V_215 ,
8 ) == 0 ) {
V_280 = V_14 -> V_316 [ V_41 ] . V_318 ;
break;
}
}
if ( V_280 ) {
V_108 = F_173 ( V_14 , V_281 , V_11 -> V_205 , 0 , 0 ,
V_280 ) ;
if ( ! V_108 )
F_9 ( V_47 , V_11 , 0x7084 ,
L_80 ,
V_11 -> V_205 ) ;
else {
F_17 ( V_313 , V_11 , 0xc001 ,
L_81 ,
V_108 , V_280 , V_11 -> V_205 ) ;
F_17 ( V_32 , V_11 , 0x7085 ,
L_81 ,
V_108 , V_280 , V_11 -> V_205 ) ;
V_283 = V_14 -> V_284 [ V_108 ] ;
}
}
V_314:
V_11 -> V_283 = V_283 ;
return 0 ;
V_310:
F_174 ( V_11 ) ;
F_175 ( V_11 ) ;
F_176 ( V_11 -> V_88 ) ;
return V_285 ;
}
static int
F_177 ( struct V_278 * V_278 )
{
T_7 * V_11 = V_278 -> V_224 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_217 = V_11 -> V_205 ;
while ( F_92 ( V_319 , & V_11 -> V_34 ) ||
F_92 ( V_320 , & V_11 -> V_34 ) )
F_178 ( 1000 ) ;
F_174 ( V_11 ) ;
V_11 -> V_89 . V_321 = 1 ;
F_179 ( V_11 -> V_88 ) ;
F_180 ( V_11 -> V_88 ) ;
F_175 ( V_11 ) ;
if ( V_11 -> V_322 ) {
F_181 ( V_11 ) ;
F_17 ( V_32 , V_11 , 0x7086 ,
L_82 , V_11 -> V_205 ) ;
}
F_182 ( F_81 ( & V_11 -> V_323 ) ) ;
F_183 ( V_11 ) ;
F_184 ( & V_14 -> V_324 ) ;
V_14 -> V_325 -- ;
F_185 ( V_11 -> V_205 , V_14 -> V_326 ) ;
F_186 ( & V_14 -> V_324 ) ;
if ( V_11 -> V_283 -> V_217 && ! V_14 -> V_89 . V_312 ) {
if ( F_187 ( V_11 , V_11 -> V_283 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7087 ,
L_83 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_84 , V_217 ) ;
F_176 ( V_11 -> V_88 ) ;
return 0 ;
}
static int
F_172 ( struct V_278 * V_278 , bool V_279 )
{
T_7 * V_11 = V_278 -> V_224 ;
if ( V_279 )
F_174 ( V_11 ) ;
else
F_188 ( V_11 ) ;
return 0 ;
}
void
F_189 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_188 = V_189 ;
F_166 ( V_11 -> V_88 ) = V_14 -> V_311 ;
F_167 ( V_11 -> V_88 ) = F_126 ( V_11 -> V_215 ) ;
F_168 ( V_11 -> V_88 ) = F_126 ( V_11 -> V_219 ) ;
F_169 ( V_11 -> V_88 ) = V_14 -> V_327 . V_328 ?
( V_329 | V_330 ) : V_330 ;
F_190 ( V_11 -> V_88 ) = V_14 -> V_331 ;
F_191 ( V_11 -> V_88 ) = V_14 -> V_325 ;
if ( F_38 ( V_14 ) )
V_188 = V_200 ;
else if ( F_39 ( V_14 ) )
V_188 = V_202 | V_198 |
V_196 ;
else if ( F_37 ( V_14 ) )
V_188 = V_198 | V_196 |
V_194 | V_192 ;
else if ( F_36 ( V_14 ) )
V_188 = V_196 | V_194 |
V_192 ;
else if ( F_192 ( V_14 ) )
V_188 = V_194 | V_192 ;
else if ( F_73 ( V_14 ) )
V_188 = V_198 | V_196 |
V_194 | V_192 ;
else
V_188 = V_192 ;
F_170 ( V_11 -> V_88 ) = V_188 ;
}
