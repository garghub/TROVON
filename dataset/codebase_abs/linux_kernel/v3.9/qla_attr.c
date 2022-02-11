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
if ( F_23 ( V_14 ) ) {
F_73 ( V_11 , L_38 , V_7 , V_118 ) ;
return snprintf ( V_7 , V_118 , L_37 , V_7 ) ;
}
V_122 = ( ( V_14 -> V_123 & 0x1f ) << 16 ) | ( V_14 -> V_124 << 8 ) | V_14 -> V_125 ;
return snprintf ( V_7 , V_118 , L_39 , 'A' + V_122 / 100000 ,
V_122 % 100000 ) ;
}
static T_1
F_74 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_40 , V_11 -> V_15 -> V_62 -> V_12 ) ;
}
static T_1
F_75 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_41 ,
V_14 -> V_126 [ 0 ] , V_14 -> V_126 [ 1 ] , V_14 -> V_126 [ 2 ] ,
V_14 -> V_126 [ 3 ] ) ;
}
static T_1
F_76 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_37 , V_11 -> V_15 -> V_127 ) ;
}
static T_1
F_77 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_37 ,
V_11 -> V_15 -> V_128 ? V_11 -> V_15 -> V_128 : L_42 ) ;
}
static T_1
F_78 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
char V_129 [ 30 ] ;
return snprintf ( V_7 , V_118 , L_37 ,
V_11 -> V_15 -> V_36 -> V_130 ( V_11 , V_129 ) ) ;
}
static T_1
F_79 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_131 = 0 ;
if ( F_80 ( & V_11 -> V_132 ) == V_133 ||
F_80 ( & V_11 -> V_132 ) == V_134 ||
V_11 -> V_135 & V_136 )
V_131 = snprintf ( V_7 , V_118 , L_43 ) ;
else if ( F_80 ( & V_11 -> V_132 ) != V_137 ||
F_81 ( V_11 ) )
V_131 = snprintf ( V_7 , V_118 , L_44 ) ;
else {
V_131 = snprintf ( V_7 , V_118 , L_45 ) ;
switch ( V_14 -> V_138 ) {
case V_139 :
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_46 ) ;
break;
case V_140 :
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_47 ) ;
break;
case V_141 :
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 ,
L_48 ) ;
break;
case V_142 :
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_49 ) ;
break;
default:
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_46 ) ;
break;
}
}
return V_131 ;
}
static T_1
F_82 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_131 = 0 ;
switch ( V_11 -> V_15 -> V_143 ) {
case V_144 :
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_50 ) ;
break;
case V_145 :
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_51 ) ;
break;
}
return V_131 ;
}
static T_1
F_83 ( struct V_12 * V_101 , struct V_117 * V_113 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_60 = 0 ;
T_4 V_143 ;
if ( ! F_84 ( V_14 ) )
return - V_146 ;
if ( sscanf ( V_7 , L_52 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 )
V_143 = V_144 ;
else
V_143 = V_145 ;
if ( V_143 != V_145 || V_14 -> V_143 != V_145 ) {
V_14 -> V_143 = V_143 ;
F_18 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_85 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_53 , V_11 -> V_15 -> V_147 * 100 ) ;
}
static T_1
F_86 ( struct V_12 * V_101 , struct V_117 * V_113 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_60 = 0 ;
T_4 V_147 ;
if ( sscanf ( V_7 , L_52 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 > 25500 || V_60 < 100 )
return - V_56 ;
V_147 = ( T_4 ) ( V_60 / 100 ) ;
V_11 -> V_15 -> V_147 = V_147 ;
return strlen ( V_7 ) ;
}
static T_1
F_87 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_131 = 0 ;
if ( V_11 -> V_15 -> V_115 )
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_54 ) ;
else
V_131 += snprintf ( V_7 + V_131 , V_118 - V_131 , L_51 ) ;
return V_131 ;
}
static T_1
F_88 ( struct V_12 * V_101 , struct V_117 * V_113 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_60 = 0 ;
int V_16 ;
if ( F_89 ( V_14 ) || F_90 ( V_14 ) )
return - V_91 ;
if ( F_91 ( V_148 , & V_11 -> V_34 ) ) {
F_9 ( V_47 , V_11 , 0x707a ,
L_55 ) ;
return - V_149 ;
}
if ( sscanf ( V_7 , L_52 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 )
V_16 = V_14 -> V_36 -> V_150 ( V_11 ) ;
else
V_16 = V_14 -> V_36 -> V_116 ( V_11 ) ;
if ( V_16 != V_46 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_92 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_56 , V_14 -> V_151 [ 1 ] ,
V_14 -> V_151 [ 0 ] ) ;
}
static T_1
F_93 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_56 , V_14 -> V_152 [ 1 ] ,
V_14 -> V_152 [ 0 ] ) ;
}
static T_1
F_94 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_56 , V_14 -> V_153 [ 1 ] ,
V_14 -> V_153 [ 0 ] ) ;
}
static T_1
F_95 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_57 ,
V_14 -> V_154 [ 0 ] , V_14 -> V_154 [ 1 ] , V_14 -> V_154 [ 2 ] ,
V_14 -> V_154 [ 3 ] ) ;
}
static T_1
F_96 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_50 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_59 ,
V_14 -> V_155 [ 0 ] , V_14 -> V_155 [ 1 ] ,
V_14 -> V_155 [ 2 ] , V_14 -> V_155 [ 3 ] ) ;
}
static T_1
F_97 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_60 ,
V_11 -> V_156 . V_157 ) ;
}
static T_1
F_98 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
int V_16 = V_46 ;
T_4 V_158 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_99 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
if ( V_14 -> V_159 -> V_160 == 0 )
V_16 = F_100 ( V_11 , V_158 ) ;
if ( ( V_16 == V_46 ) && ( V_158 [ 0 ] == 0 ) )
return snprintf ( V_7 , V_118 , L_61 ,
( T_5 ) V_14 -> V_159 -> V_160 ) ;
return snprintf ( V_7 , V_118 , L_58 ) ;
}
static T_1
F_101 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_59 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_62 ,
V_14 -> V_161 [ 0 ] , V_14 -> V_161 [ 1 ] , V_14 -> V_161 [ 2 ] ,
V_14 -> V_162 ) ;
}
static T_1
F_102 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_59 ( V_14 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_63 ,
V_14 -> V_163 [ 0 ] , V_14 -> V_163 [ 1 ] , V_14 -> V_163 [ 2 ] ) ;
}
static T_1
F_103 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_118 , L_64 , V_14 -> V_164 ) ;
}
static T_1
F_104 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_60 , V_11 -> V_165 ) ;
}
static T_1
F_105 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_65 ,
V_11 -> V_166 [ 5 ] , V_11 -> V_166 [ 4 ] ,
V_11 -> V_166 [ 3 ] , V_11 -> V_166 [ 2 ] ,
V_11 -> V_166 [ 1 ] , V_11 -> V_166 [ 0 ] ) ;
}
static T_1
F_106 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
return snprintf ( V_7 , V_118 , L_60 , V_11 -> V_15 -> V_167 ) ;
}
static T_1
F_107 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
T_4 V_168 = 0 ;
if ( ! V_11 -> V_15 -> V_169 ) {
F_9 ( V_47 , V_11 , 0x70db ,
L_66 ) ;
goto V_170;
}
if ( F_81 ( V_11 ) ) {
F_9 ( V_47 , V_11 , 0x70dc , L_67 ) ;
goto V_170;
}
if ( V_11 -> V_15 -> V_89 . V_171 ) {
F_9 ( V_47 , V_11 , 0x70dd , L_68 ) ;
goto V_170;
}
if ( F_108 ( V_11 , & V_168 ) == V_46 )
return snprintf ( V_7 , V_118 , L_60 , V_168 ) ;
V_170:
return snprintf ( V_7 , V_118 , L_58 ) ;
}
static T_1
F_109 ( struct V_12 * V_101 , struct V_117 * V_113 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
int V_16 = V_172 ;
T_4 V_173 [ 5 ] ;
if ( F_81 ( V_11 ) )
F_9 ( V_47 , V_11 , 0x707c ,
L_67 ) ;
else if ( ! V_11 -> V_15 -> V_89 . V_171 )
V_16 = F_110 ( V_11 , V_173 ) ;
if ( V_16 != V_46 )
memset ( V_173 , - 1 , sizeof( V_173 ) ) ;
return snprintf ( V_7 , V_118 , L_69 , V_173 [ 0 ] ,
V_173 [ 1 ] , V_173 [ 2 ] , V_173 [ 3 ] , V_173 [ 4 ] ) ;
}
static T_1
F_111 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_112 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_70 , V_11 -> V_174 . V_175 ) ;
}
static T_1
F_113 ( struct V_12 * V_101 ,
struct V_117 * V_113 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_71 ( V_101 ) ) ;
if ( ! F_112 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_118 , L_58 ) ;
return snprintf ( V_7 , V_118 , L_70 ,
V_11 -> V_174 . V_176 >> 20 ) ;
}
static T_1
F_114 ( struct V_12 * V_101 , struct V_117 * V_113 ,
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
F_115 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
F_116 ( V_177 ) = V_11 -> V_178 . V_179 . V_180 << 16 |
V_11 -> V_178 . V_179 . V_181 << 8 | V_11 -> V_178 . V_179 . V_182 ;
}
static void
F_117 ( struct V_106 * V_177 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_177 ) ) ) -> V_15 ;
T_8 V_183 = V_184 ;
switch ( V_14 -> V_185 ) {
case V_186 :
V_183 = V_187 ;
break;
case V_188 :
V_183 = V_189 ;
break;
case V_190 :
V_183 = V_191 ;
break;
case V_192 :
V_183 = V_193 ;
break;
case V_194 :
V_183 = V_195 ;
break;
case V_196 :
V_183 = V_197 ;
break;
}
F_118 ( V_177 ) = V_183 ;
}
static void
F_119 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
T_5 V_198 = V_199 ;
if ( V_11 -> V_200 ) {
F_120 ( V_177 ) = V_201 ;
return;
}
switch ( V_11 -> V_15 -> V_138 ) {
case V_139 :
V_198 = V_202 ;
break;
case V_140 :
V_198 = V_203 ;
break;
case V_141 :
V_198 = V_204 ;
break;
case V_142 :
V_198 = V_205 ;
break;
}
F_120 ( V_177 ) = V_198 ;
}
static void
F_121 ( struct V_206 * V_207 )
{
struct V_106 * V_88 = F_3 ( V_207 -> V_101 . V_208 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_209 ;
T_10 V_210 = 0 ;
F_122 (fcport, &vha->vp_fcports, list) {
if ( V_209 -> V_211 &&
V_207 -> V_212 == V_209 -> V_211 -> V_213 ) {
V_210 = F_123 ( V_209 -> V_210 ) ;
break;
}
}
F_124 ( V_207 ) = V_210 ;
}
static void
F_125 ( struct V_206 * V_207 )
{
struct V_106 * V_88 = F_3 ( V_207 -> V_101 . V_208 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_209 ;
T_10 V_214 = 0 ;
F_122 (fcport, &vha->vp_fcports, list) {
if ( V_209 -> V_211 &&
V_207 -> V_212 == V_209 -> V_211 -> V_213 ) {
V_214 = F_123 ( V_209 -> V_214 ) ;
break;
}
}
F_126 ( V_207 ) = V_214 ;
}
static void
F_127 ( struct V_206 * V_207 )
{
struct V_106 * V_88 = F_3 ( V_207 -> V_101 . V_208 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_209 ;
T_5 V_215 = ~ 0U ;
F_122 (fcport, &vha->vp_fcports, list) {
if ( V_209 -> V_211 &&
V_207 -> V_212 == V_209 -> V_211 -> V_213 ) {
V_215 = V_209 -> V_178 . V_179 . V_180 << 16 |
V_209 -> V_178 . V_179 . V_181 << 8 | V_209 -> V_178 . V_179 . V_182 ;
break;
}
}
F_128 ( V_207 ) = V_215 ;
}
static void
F_129 ( struct V_216 * V_211 , T_5 V_217 )
{
if ( V_217 )
V_211 -> V_218 = V_217 ;
else
V_211 -> V_218 = 1 ;
}
static void
F_130 ( struct V_216 * V_211 )
{
struct V_106 * V_88 = F_131 ( V_211 ) ;
T_9 * V_209 = * ( T_9 * * ) V_211 -> V_219 ;
unsigned long V_89 ;
if ( ! V_209 )
return;
F_132 ( V_209 , V_220 ) ;
F_133 ( V_88 -> V_221 , V_89 ) ;
V_209 -> V_211 = V_209 -> V_222 = NULL ;
* ( ( T_9 * * ) V_211 -> V_219 ) = NULL ;
F_134 ( V_88 -> V_221 , V_89 ) ;
if ( F_91 ( V_148 , & V_209 -> V_11 -> V_34 ) )
return;
if ( F_32 ( F_33 ( V_209 -> V_11 -> V_15 -> V_62 ) ) ) {
F_135 ( V_209 -> V_11 , V_223 << 16 ) ;
return;
}
}
static void
F_136 ( struct V_216 * V_211 )
{
T_9 * V_209 = * ( T_9 * * ) V_211 -> V_219 ;
if ( ! V_209 )
return;
if ( F_91 ( V_148 , & V_209 -> V_11 -> V_34 ) )
return;
if ( F_32 ( F_33 ( V_209 -> V_11 -> V_15 -> V_62 ) ) ) {
F_135 ( V_209 -> V_11 , V_223 << 16 ) ;
return;
}
if ( V_209 -> V_224 != V_225 ) {
if ( F_23 ( V_209 -> V_11 -> V_15 ) )
V_209 -> V_11 -> V_15 -> V_36 -> V_226 ( V_209 -> V_11 ,
V_209 -> V_224 , V_209 -> V_178 . V_179 . V_180 ,
V_209 -> V_178 . V_179 . V_181 , V_209 -> V_178 . V_179 . V_182 ) ;
else
F_137 ( V_209 -> V_11 , V_209 ) ;
}
}
static int
F_138 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
F_139 ( V_11 ) ;
return 0 ;
}
static struct V_227 *
F_140 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_86 = F_46 ( V_14 -> V_62 ) ;
int V_16 ;
struct V_228 * V_229 ;
T_11 V_230 ;
struct V_227 * V_231 ;
V_231 = & V_11 -> V_232 ;
memset ( V_231 , - 1 , sizeof( struct V_227 ) ) ;
if ( F_91 ( V_233 , & V_11 -> V_34 ) )
goto V_170;
if ( F_32 ( F_33 ( V_14 -> V_62 ) ) )
goto V_170;
V_229 = F_43 ( V_14 -> V_81 , V_82 , & V_230 ) ;
if ( V_229 == NULL ) {
F_9 ( V_47 , V_11 , 0x707d ,
L_71 ) ;
goto V_170;
}
memset ( V_229 , 0 , V_234 ) ;
V_16 = V_172 ;
if ( F_23 ( V_14 ) ) {
V_16 = F_141 ( V_86 , V_229 , V_230 ) ;
} else if ( F_80 ( & V_86 -> V_132 ) == V_137 &&
! F_81 ( V_11 ) && ! V_14 -> V_235 ) {
V_16 = F_142 ( V_86 , V_86 -> V_224 ,
V_229 , V_230 ) ;
}
if ( V_16 != V_46 )
goto V_236;
V_231 -> V_237 = V_229 -> V_238 ;
V_231 -> V_239 = V_229 -> V_240 ;
V_231 -> V_241 = V_229 -> V_242 ;
V_231 -> V_243 = V_229 -> V_244 ;
V_231 -> V_245 = V_229 -> V_246 ;
V_231 -> V_247 = V_229 -> V_248 ;
if ( F_23 ( V_14 ) ) {
V_231 -> V_249 = V_229 -> V_250 ;
V_231 -> V_251 = V_229 -> V_251 ;
V_231 -> V_252 = V_229 -> V_252 ;
V_231 -> V_253 = V_229 -> V_253 ;
V_231 -> V_254 = V_229 -> V_255 ;
}
V_231 -> V_256 = V_11 -> V_156 . V_257 >> 20 ;
V_231 -> V_258 = V_11 -> V_156 . V_259 >> 20 ;
V_236:
F_143 ( V_14 -> V_81 , V_229 , V_230 ) ;
V_170:
return V_231 ;
}
static void
F_144 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
F_145 ( V_11 , F_146 ( V_177 ) ) ;
}
static void
F_147 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
F_18 ( V_260 , & V_11 -> V_34 ) ;
}
static void
F_148 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
T_6 V_210 [ V_261 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_262 = F_123 ( V_210 ) ;
if ( V_11 -> V_135 & V_263 )
V_262 = F_123 ( V_11 -> V_264 ) ;
F_149 ( V_177 ) = V_262 ;
}
static void
F_150 ( struct V_106 * V_177 )
{
T_7 * V_11 = F_2 ( V_177 ) ;
struct V_10 * V_86 = F_46 ( V_11 -> V_15 -> V_62 ) ;
if ( ! V_86 -> V_89 . V_265 ) {
F_151 ( V_177 ) = V_266 ;
return;
}
switch ( F_80 ( & V_86 -> V_132 ) ) {
case V_267 :
F_151 ( V_177 ) = V_268 ;
break;
case V_133 :
if ( F_91 ( V_269 , & V_86 -> V_34 ) )
F_151 ( V_177 ) = V_268 ;
else
F_151 ( V_177 ) = V_270 ;
break;
case V_134 :
F_151 ( V_177 ) = V_270 ;
break;
case V_137 :
F_151 ( V_177 ) = V_271 ;
break;
default:
F_151 ( V_177 ) = V_272 ;
break;
}
}
static int
F_152 ( struct V_273 * V_273 , bool V_274 )
{
int V_108 = 0 ;
T_6 V_275 = 0 ;
T_7 * V_86 = F_2 ( V_273 -> V_177 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_86 -> V_15 ;
T_4 V_276 = 0 ;
int V_41 ;
struct V_277 * V_278 = V_14 -> V_279 [ 0 ] ;
V_108 = F_153 ( V_273 ) ;
if ( V_108 ) {
F_9 ( V_47 , V_11 , 0x707e ,
L_72 , V_108 ) ;
return ( V_108 ) ;
}
V_11 = F_154 ( V_273 ) ;
if ( V_11 == NULL ) {
F_9 ( V_47 , V_11 , 0x707f , L_73 ) ;
return V_280 ;
}
if ( V_274 ) {
F_155 ( & V_11 -> V_281 , V_282 ) ;
F_156 ( V_273 , V_283 ) ;
} else
F_155 ( & V_11 -> V_281 , V_284 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_74 , V_11 -> V_200 ) ;
F_155 ( & V_11 -> V_132 , V_133 ) ;
V_11 -> V_285 = V_286 ;
V_11 -> V_287 = V_288 ;
if ( F_80 ( & V_86 -> V_132 ) == V_133 ||
F_80 ( & V_86 -> V_132 ) == V_134 ) {
F_17 ( V_32 , V_11 , 0x7081 ,
L_75 ) ;
F_155 ( & V_11 -> V_132 , V_134 ) ;
if ( ! V_274 )
F_156 ( V_273 , V_289 ) ;
}
if ( F_157 ( V_14 ) && V_290 ) {
if ( V_14 -> V_291 & V_292 ) {
int V_293 = 0 , V_294 ;
V_11 -> V_89 . V_295 = 1 ;
F_17 ( V_32 , V_11 , 0x7082 ,
L_76 ) ;
if ( V_290 == 1 )
V_293 = V_296 ;
F_158 ( V_11 -> V_88 ,
V_293 | V_297
| V_298
| V_299
| V_300
| V_301
| V_302 ) ;
V_294 = V_303 ;
if ( F_159 ( V_14 ) &&
( V_290 > 1 || F_160 ( V_14 ) ) )
V_294 |= V_304 ;
F_161 ( V_11 -> V_88 , V_294 ) ;
} else
V_11 -> V_89 . V_295 = 0 ;
}
if ( F_162 ( V_11 -> V_88 , & V_273 -> V_101 ,
& V_14 -> V_62 -> V_101 ) ) {
F_17 ( V_32 , V_11 , 0x7083 ,
L_77 , V_11 -> V_200 ) ;
goto V_305;
}
F_163 ( V_11 -> V_88 ) = V_14 -> V_306 ;
F_164 ( V_11 -> V_88 ) = F_123 ( V_11 -> V_210 ) ;
F_165 ( V_11 -> V_88 ) = F_123 ( V_11 -> V_214 ) ;
F_166 ( V_11 -> V_88 ) =
F_166 ( V_86 -> V_88 ) ;
F_167 ( V_11 -> V_88 ) =
F_167 ( V_86 -> V_88 ) ;
F_168 ( V_11 , V_14 ) ;
F_169 ( V_273 , V_274 ) ;
if ( V_14 -> V_89 . V_307 ) {
V_278 = V_14 -> V_279 [ 1 ] ;
F_17 ( V_308 , V_11 , 0xc000 ,
L_78
L_79 ,
V_278 , V_11 -> V_200 , V_14 -> V_89 . V_307 ) ;
goto V_309;
} else if ( V_310 == 1 || ! V_14 -> V_311 )
goto V_309;
for ( V_41 = 0 ; V_41 < V_14 -> V_312 ; V_41 ++ ) {
if ( memcmp ( V_14 -> V_311 [ V_41 ] . V_214 , V_11 -> V_214 , 8 ) == 0
&& memcmp ( V_14 -> V_311 [ V_41 ] . V_210 , V_11 -> V_210 ,
8 ) == 0 ) {
V_275 = V_14 -> V_311 [ V_41 ] . V_313 ;
break;
}
}
if ( V_275 ) {
V_108 = F_170 ( V_14 , V_276 , V_11 -> V_200 , 0 , 0 ,
V_275 ) ;
if ( ! V_108 )
F_9 ( V_47 , V_11 , 0x7084 ,
L_80 ,
V_11 -> V_200 ) ;
else {
F_17 ( V_308 , V_11 , 0xc001 ,
L_81 ,
V_108 , V_275 , V_11 -> V_200 ) ;
F_17 ( V_32 , V_11 , 0x7085 ,
L_81 ,
V_108 , V_275 , V_11 -> V_200 ) ;
V_278 = V_14 -> V_279 [ V_108 ] ;
}
}
V_309:
V_11 -> V_278 = V_278 ;
return 0 ;
V_305:
F_171 ( V_11 ) ;
F_172 ( V_11 ) ;
F_173 ( V_11 -> V_88 ) ;
return V_280 ;
}
static int
F_174 ( struct V_273 * V_273 )
{
T_7 * V_11 = V_273 -> V_219 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_212 = V_11 -> V_200 ;
while ( F_91 ( V_314 , & V_11 -> V_34 ) ||
F_91 ( V_315 , & V_11 -> V_34 ) )
F_175 ( 1000 ) ;
F_171 ( V_11 ) ;
V_11 -> V_89 . V_316 = 1 ;
F_176 ( V_11 -> V_88 ) ;
F_177 ( V_11 -> V_88 ) ;
F_172 ( V_11 ) ;
if ( V_11 -> V_317 ) {
F_178 ( V_11 ) ;
F_17 ( V_32 , V_11 , 0x7086 ,
L_82 , V_11 -> V_200 ) ;
}
F_179 ( F_80 ( & V_11 -> V_318 ) ) ;
F_180 ( V_11 ) ;
F_181 ( & V_14 -> V_319 ) ;
V_14 -> V_320 -- ;
F_182 ( V_11 -> V_200 , V_14 -> V_321 ) ;
F_183 ( & V_14 -> V_319 ) ;
if ( V_11 -> V_278 -> V_212 && ! V_14 -> V_89 . V_307 ) {
if ( F_184 ( V_11 , V_11 -> V_278 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7087 ,
L_83 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_84 , V_212 ) ;
F_173 ( V_11 -> V_88 ) ;
return 0 ;
}
static int
F_169 ( struct V_273 * V_273 , bool V_274 )
{
T_7 * V_11 = V_273 -> V_219 ;
if ( V_274 )
F_171 ( V_11 ) ;
else
F_185 ( V_11 ) ;
return 0 ;
}
void
F_186 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_183 = V_184 ;
F_163 ( V_11 -> V_88 ) = V_14 -> V_306 ;
F_164 ( V_11 -> V_88 ) = F_123 ( V_11 -> V_210 ) ;
F_165 ( V_11 -> V_88 ) = F_123 ( V_11 -> V_214 ) ;
F_166 ( V_11 -> V_88 ) = V_14 -> V_322 . V_323 ?
( V_324 | V_325 ) : V_325 ;
F_187 ( V_11 -> V_88 ) = V_14 -> V_326 ;
F_188 ( V_11 -> V_88 ) = V_14 -> V_320 ;
if ( F_38 ( V_14 ) )
V_183 = V_195 ;
else if ( F_39 ( V_14 ) )
V_183 = V_197 | V_193 |
V_191 ;
else if ( F_37 ( V_14 ) )
V_183 = V_193 | V_191 |
V_189 | V_187 ;
else if ( F_36 ( V_14 ) )
V_183 = V_191 | V_189 |
V_187 ;
else if ( F_189 ( V_14 ) )
V_183 = V_189 | V_187 ;
else
V_183 = V_187 ;
F_167 ( V_11 -> V_88 ) = V_183 ;
}
