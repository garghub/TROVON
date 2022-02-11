static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 = 0 ;
if ( V_14 -> V_17 == 0 )
return 0 ;
if ( F_5 ( V_14 ) ) {
if ( V_8 < V_14 -> V_18 ) {
V_16 = F_6 ( V_7 , V_9 ,
& V_8 , V_14 -> V_19 , V_14 -> V_18 ) ;
return V_16 ;
}
V_8 -= V_14 -> V_18 ;
V_16 = F_6 ( V_7 , V_9 ,
& V_8 , V_14 -> V_20 , V_14 -> V_21 ) ;
return V_16 ;
} else
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_22 ,
V_14 -> V_23 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_24 ;
if ( V_8 != 0 )
return ( 0 ) ;
V_24 = F_8 ( V_7 , NULL , 10 ) ;
switch ( V_24 ) {
case 0 :
if ( ! V_14 -> V_17 )
break;
F_9 ( V_25 , V_11 , 0x705d ,
L_1 , V_11 -> V_26 ) ;
if ( F_5 ( V_11 -> V_15 ) ) {
F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
}
V_14 -> V_17 = 0 ;
V_14 -> V_27 = 0 ;
break;
case 1 :
if ( V_14 -> V_27 && ! V_14 -> V_17 ) {
V_14 -> V_17 = 1 ;
F_9 ( V_25 , V_11 , 0x705e ,
L_2 ,
V_11 -> V_26 ) ;
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
if ( V_14 -> V_19 )
F_17 ( V_28 , V_11 , 0x705b ,
L_3 ) ;
else
F_17 ( V_28 , V_11 , 0x709d ,
L_4 ) ;
}
break;
case 5 :
if ( F_5 ( V_14 ) )
F_18 ( V_29 , & V_11 -> V_30 ) ;
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
if ( ! F_20 ( V_31 ) )
return 0 ;
if ( F_21 ( V_14 ) )
V_14 -> V_32 -> V_33 ( V_11 , V_14 -> V_34 , V_14 -> V_35 << 2 ,
V_14 -> V_36 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_34 ,
V_14 -> V_36 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_37 ;
if ( ! F_20 ( V_31 ) || V_8 != 0 || V_9 != V_14 -> V_36 ||
! V_14 -> V_32 -> V_38 )
return - V_39 ;
if ( F_23 ( V_14 ) ) {
T_5 * V_40 ;
T_5 V_41 ;
V_40 = ( T_5 * ) V_7 ;
V_41 = 0 ;
for ( V_37 = 0 ; V_37 < ( ( V_9 >> 2 ) - 1 ) ; V_37 ++ )
V_41 += F_24 ( * V_40 ++ ) ;
V_41 = ~ V_41 + 1 ;
* V_40 = F_25 ( V_41 ) ;
} else {
T_6 * V_40 ;
T_6 V_41 ;
V_40 = ( T_6 * ) V_7 ;
V_41 = 0 ;
for ( V_37 = 0 ; V_37 < V_9 - 1 ; V_37 ++ )
V_41 += * V_40 ++ ;
V_41 = ~ V_41 + 1 ;
* V_40 = V_41 ;
}
if ( F_26 ( V_11 ) != V_42 ) {
F_9 ( V_43 , V_11 , 0x705f ,
L_5 ) ;
return - V_44 ;
}
V_14 -> V_32 -> V_38 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_45 , V_9 ) ;
V_14 -> V_32 -> V_46 ( V_11 , ( T_6 * ) V_14 -> V_34 , V_14 -> V_45 ,
V_9 ) ;
F_17 ( V_28 , V_11 , 0x7060 ,
L_6 ) ;
F_18 ( V_29 , & V_11 -> V_30 ) ;
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
if ( V_14 -> V_47 != V_48 )
return 0 ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_49 ,
V_14 -> V_50 ) ;
}
static T_1
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 -> V_47 != V_51 )
return - V_39 ;
if ( V_8 > V_14 -> V_50 )
return - V_52 ;
if ( V_8 + V_9 > V_14 -> V_50 )
V_9 = V_14 -> V_50 - V_8 ;
memcpy ( & V_14 -> V_49 [ V_8 ] , V_7 , V_9 ) ;
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
T_5 V_53 = 0 ;
T_5 V_54 = V_14 -> V_55 ;
int V_56 , V_57 ;
if ( V_8 )
return - V_39 ;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
return - V_44 ;
if ( sscanf ( V_7 , L_7 , & V_56 , & V_53 , & V_54 ) < 1 )
return - V_39 ;
if ( V_53 > V_14 -> V_55 )
return - V_39 ;
switch ( V_56 ) {
case 0 :
if ( V_14 -> V_47 != V_48 &&
V_14 -> V_47 != V_51 )
return - V_39 ;
V_14 -> V_47 = V_59 ;
F_17 ( V_28 , V_11 , 0x7061 ,
L_8 ,
V_14 -> V_50 ) ;
F_34 ( V_14 -> V_49 ) ;
V_14 -> V_49 = NULL ;
break;
case 1 :
if ( V_14 -> V_47 != V_59 )
return - V_39 ;
V_14 -> V_60 = V_53 ;
V_14 -> V_50 = V_53 + V_54 > V_14 -> V_55 ?
V_14 -> V_55 - V_53 : V_54 ;
V_14 -> V_47 = V_48 ;
V_14 -> V_49 = F_35 ( V_14 -> V_50 ) ;
if ( V_14 -> V_49 == NULL ) {
F_9 ( V_43 , V_11 , 0x7062 ,
L_9
L_10 , V_14 -> V_50 ) ;
V_14 -> V_47 = V_59 ;
return - V_61 ;
}
if ( F_26 ( V_11 ) != V_42 ) {
F_9 ( V_43 , V_11 , 0x7063 ,
L_5 ) ;
return - V_44 ;
}
F_17 ( V_28 , V_11 , 0x7064 ,
L_11 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
memset ( V_14 -> V_49 , 0 , V_14 -> V_50 ) ;
V_14 -> V_32 -> V_33 ( V_11 , V_14 -> V_49 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
break;
case 2 :
if ( V_14 -> V_47 != V_59 )
return - V_39 ;
V_57 = 0 ;
if ( V_14 -> V_55 == V_62 && V_53 == 0 )
V_57 = 1 ;
else if ( V_53 == ( V_14 -> V_63 * 4 ) ||
V_53 == ( V_14 -> V_64 * 4 ) )
V_57 = 1 ;
else if ( F_36 ( V_14 ) || F_37 ( V_14 )
|| F_38 ( V_14 ) || F_39 ( V_14 ) )
V_57 = 1 ;
if ( ! V_57 ) {
F_9 ( V_43 , V_11 , 0x7065 ,
L_12 , V_53 , V_54 ) ;
return - V_39 ;
}
V_14 -> V_60 = V_53 ;
V_14 -> V_50 = V_53 + V_54 > V_14 -> V_55 ?
V_14 -> V_55 - V_53 : V_54 ;
V_14 -> V_47 = V_51 ;
V_14 -> V_49 = F_35 ( V_14 -> V_50 ) ;
if ( V_14 -> V_49 == NULL ) {
F_9 ( V_43 , V_11 , 0x7066 ,
L_13
L_14 , V_14 -> V_50 ) ;
V_14 -> V_47 = V_59 ;
return - V_61 ;
}
F_17 ( V_28 , V_11 , 0x7067 ,
L_15 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
memset ( V_14 -> V_49 , 0 , V_14 -> V_50 ) ;
break;
case 3 :
if ( V_14 -> V_47 != V_51 )
return - V_39 ;
if ( F_26 ( V_11 ) != V_42 ) {
F_9 ( V_43 , V_11 , 0x7068 ,
L_16 ) ;
return - V_44 ;
}
F_17 ( V_28 , V_11 , 0x7069 ,
L_17 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
V_14 -> V_32 -> V_65 ( V_11 , V_14 -> V_49 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
break;
default:
return - V_39 ;
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
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
return - V_44 ;
if ( ! F_20 ( V_31 ) )
return - V_39 ;
if ( F_21 ( V_14 ) )
V_14 -> V_32 -> V_33 ( V_11 , V_14 -> V_66 , V_14 -> V_67 << 2 ,
V_14 -> V_68 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_66 , V_14 -> V_68 ) ;
}
static T_1
F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_69 ;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
return 0 ;
if ( ! F_20 ( V_31 ) || V_8 != 0 || V_9 != V_14 -> V_68 ||
! V_14 -> V_32 -> V_38 )
return 0 ;
if ( F_26 ( V_11 ) != V_42 ) {
F_9 ( V_43 , V_11 , 0x706a ,
L_18 ) ;
return - V_44 ;
}
V_14 -> V_32 -> V_38 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_70 , V_9 ) ;
V_14 -> V_32 -> V_46 ( V_11 , ( T_6 * ) V_14 -> V_66 , V_14 -> V_70 , V_9 ) ;
if ( ! F_23 ( V_14 ) )
return - V_39 ;
V_69 = F_35 ( 256 ) ;
if ( ! V_69 ) {
F_9 ( V_43 , V_11 , 0x706b ,
L_19 ) ;
return - V_61 ;
}
V_14 -> V_32 -> V_71 ( V_11 , V_69 ) ;
F_34 ( V_69 ) ;
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
T_4 V_40 , V_72 , V_73 ;
int V_16 ;
if ( ! F_20 ( V_31 ) || V_8 != 0 || V_9 != V_74 * 2 )
return 0 ;
if ( V_14 -> V_75 )
goto V_76;
V_14 -> V_75 = F_43 ( V_14 -> V_77 , V_78 ,
& V_14 -> V_79 ) ;
if ( ! V_14 -> V_75 ) {
F_9 ( V_43 , V_11 , 0x706c ,
L_20 ) ;
return 0 ;
}
V_76:
memset ( V_14 -> V_75 , 0 , V_80 ) ;
V_72 = 0xa0 ;
for ( V_40 = 0 , V_73 = 0 ; V_40 < ( V_74 * 2 ) / V_80 ;
V_40 ++ , V_73 += V_80 ) {
if ( V_40 == 4 ) {
V_72 = 0xa2 ;
V_73 = 0 ;
}
V_16 = F_44 ( V_11 , V_14 -> V_79 , V_14 -> V_75 ,
V_72 , V_73 , V_80 , 0 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x706d ,
L_21 , V_16 ,
V_72 , V_73 ) ;
return - V_81 ;
}
memcpy ( V_7 , V_14 -> V_75 , V_80 ) ;
V_7 += V_80 ;
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
struct V_10 * V_82 = F_46 ( V_14 -> V_58 ) ;
int type ;
if ( V_8 != 0 )
return - V_39 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_25 , V_11 , 0x706e ,
L_22 ) ;
F_47 ( V_11 -> V_83 ) ;
F_18 ( V_29 , & V_11 -> V_30 ) ;
if ( F_5 ( V_14 ) ) {
V_14 -> V_84 . V_85 = 1 ;
F_13 ( V_14 ) ;
F_14 ( V_11 ) ;
F_15 ( V_14 ) ;
}
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_48 ( V_11 -> V_83 ) ;
break;
case 0x2025d :
if ( ! F_49 ( V_14 ) || ! F_50 ( V_14 ) )
return - V_86 ;
F_9 ( V_25 , V_11 , 0x706f ,
L_23 ) ;
F_26 ( V_11 ) ;
F_47 ( V_11 -> V_83 ) ;
if ( F_51 ( V_11 ) != V_42 )
F_9 ( V_43 , V_11 , 0x7070 ,
L_24 ) ;
F_48 ( V_11 -> V_83 ) ;
break;
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_82 ) {
F_9 ( V_25 , V_11 , 0x7071 ,
L_25 ) ;
return - V_86 ;
}
F_9 ( V_25 , V_11 , 0x7072 ,
L_26 ) ;
F_18 ( V_87 , & V_11 -> V_30 ) ;
F_27 ( V_11 ) ;
F_52 ( V_11 ) ;
break;
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
int V_16 ;
T_4 V_88 ;
if ( ! F_20 ( V_31 ) || V_8 != 0 || V_9 > V_89 )
return 0 ;
if ( V_14 -> V_90 )
goto V_76;
V_14 -> V_90 = F_54 ( & V_14 -> V_58 -> V_91 , V_89 ,
& V_14 -> V_92 , V_78 ) ;
if ( ! V_14 -> V_90 ) {
F_9 ( V_43 , V_11 , 0x7076 ,
L_27 ) ;
return 0 ;
}
V_76:
V_88 = 0 ;
memset ( V_14 -> V_90 , 0 , V_89 ) ;
V_16 = F_55 ( V_11 , V_14 -> V_92 ,
V_89 , & V_88 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x7077 ,
L_28 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_88 > V_9 ? V_9 : V_88 ;
memcpy ( V_7 , V_14 -> V_90 , V_9 ) ;
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
int V_16 ;
T_4 V_88 ;
if ( ! F_20 ( V_31 ) || V_8 != 0 || V_9 > V_93 )
return 0 ;
if ( V_14 -> V_94 )
goto V_76;
V_14 -> V_94 = F_54 ( & V_14 -> V_58 -> V_91 , V_93 ,
& V_14 -> V_95 , V_78 ) ;
if ( ! V_14 -> V_94 ) {
F_9 ( V_43 , V_11 , 0x7078 ,
L_29 ) ;
return - V_61 ;
}
V_76:
V_88 = 0 ;
memset ( V_14 -> V_94 , 0 , V_93 ) ;
V_16 = F_57 ( V_11 , V_14 -> V_95 ,
V_93 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x7079 ,
L_30 , V_16 ) ;
return - V_81 ;
}
memcpy ( V_7 , V_14 -> V_94 , V_9 ) ;
return V_9 ;
}
void
F_58 ( T_7 * V_11 )
{
struct V_96 * V_83 = V_11 -> V_83 ;
struct V_97 * V_40 ;
int V_98 ;
for ( V_40 = V_99 ; V_40 -> V_100 ; V_40 ++ ) {
if ( V_40 -> V_101 && ! F_23 ( V_11 -> V_15 ) )
continue;
if ( V_40 -> V_101 == 2 && ! F_37 ( V_11 -> V_15 ) )
continue;
if ( V_40 -> V_101 == 3 && ! ( F_38 ( V_11 -> V_15 ) ) )
continue;
V_98 = F_59 ( & V_83 -> V_102 . V_4 ,
V_40 -> V_103 ) ;
if ( V_98 )
F_9 ( V_43 , V_11 , 0x00f3 ,
L_31 ,
V_40 -> V_100 , V_98 ) ;
else
F_17 ( V_104 , V_11 , 0x00f4 ,
L_32 ,
V_40 -> V_100 ) ;
}
}
void
F_60 ( T_7 * V_11 )
{
struct V_96 * V_83 = V_11 -> V_83 ;
struct V_97 * V_40 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_40 = V_99 ; V_40 -> V_100 ; V_40 ++ ) {
if ( V_40 -> V_101 && ! F_23 ( V_14 ) )
continue;
if ( V_40 -> V_101 == 2 && ! F_37 ( V_14 ) )
continue;
if ( V_40 -> V_101 == 3 && ! ( F_38 ( V_11 -> V_15 ) ) )
continue;
F_61 ( & V_83 -> V_102 . V_4 ,
V_40 -> V_103 ) ;
}
if ( V_14 -> V_105 == 1 )
V_14 -> V_32 -> V_106 ( V_11 ) ;
}
static T_1
F_62 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
return snprintf ( V_7 , V_108 , L_33 , V_109 ) ;
}
static T_1
F_63 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_110 [ 128 ] ;
return snprintf ( V_7 , V_108 , L_33 ,
V_14 -> V_32 -> V_111 ( V_11 , V_110 ) ) ;
}
static T_1
F_65 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_112 ;
if ( F_23 ( V_14 ) ) {
F_66 ( V_11 , L_34 , V_7 , V_108 ) ;
return snprintf ( V_7 , V_108 , L_33 , V_7 ) ;
}
V_112 = ( ( V_14 -> V_113 & 0x1f ) << 16 ) | ( V_14 -> V_114 << 8 ) | V_14 -> V_115 ;
return snprintf ( V_7 , V_108 , L_35 , 'A' + V_112 / 100000 ,
V_112 % 100000 ) ;
}
static T_1
F_67 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
return snprintf ( V_7 , V_108 , L_36 , V_11 -> V_15 -> V_58 -> V_12 ) ;
}
static T_1
F_68 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_37 ,
V_14 -> V_116 [ 0 ] , V_14 -> V_116 [ 1 ] , V_14 -> V_116 [ 2 ] ,
V_14 -> V_116 [ 3 ] ) ;
}
static T_1
F_69 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
return snprintf ( V_7 , V_108 , L_33 , V_11 -> V_15 -> V_117 ) ;
}
static T_1
F_70 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
return snprintf ( V_7 , V_108 , L_33 ,
V_11 -> V_15 -> V_118 ? V_11 -> V_15 -> V_118 : L_38 ) ;
}
static T_1
F_71 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
char V_119 [ 30 ] ;
return snprintf ( V_7 , V_108 , L_33 ,
V_11 -> V_15 -> V_32 -> V_120 ( V_11 , V_119 ) ) ;
}
static T_1
F_72 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_121 = 0 ;
if ( F_73 ( & V_11 -> V_122 ) == V_123 ||
F_73 ( & V_11 -> V_122 ) == V_124 ||
V_11 -> V_125 & V_126 )
V_121 = snprintf ( V_7 , V_108 , L_39 ) ;
else if ( F_73 ( & V_11 -> V_122 ) != V_127 ||
F_74 ( V_11 ) )
V_121 = snprintf ( V_7 , V_108 , L_40 ) ;
else {
V_121 = snprintf ( V_7 , V_108 , L_41 ) ;
switch ( V_14 -> V_128 ) {
case V_129 :
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_42 ) ;
break;
case V_130 :
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_43 ) ;
break;
case V_131 :
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 ,
L_44 ) ;
break;
case V_132 :
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_45 ) ;
break;
default:
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_42 ) ;
break;
}
}
return V_121 ;
}
static T_1
F_75 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
int V_121 = 0 ;
switch ( V_11 -> V_15 -> V_133 ) {
case V_134 :
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_46 ) ;
break;
case V_135 :
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_47 ) ;
break;
}
return V_121 ;
}
static T_1
F_76 ( struct V_12 * V_91 , struct V_107 * V_103 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_56 = 0 ;
T_4 V_133 ;
if ( ! F_77 ( V_14 ) )
return - V_136 ;
if ( sscanf ( V_7 , L_48 , & V_56 ) != 1 )
return - V_39 ;
if ( V_56 )
V_133 = V_134 ;
else
V_133 = V_135 ;
if ( V_133 != V_135 || V_14 -> V_133 != V_135 ) {
V_14 -> V_133 = V_133 ;
F_18 ( V_29 , & V_11 -> V_30 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_78 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
return snprintf ( V_7 , V_108 , L_49 , V_11 -> V_15 -> V_137 * 100 ) ;
}
static T_1
F_79 ( struct V_12 * V_91 , struct V_107 * V_103 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
int V_56 = 0 ;
T_4 V_137 ;
if ( sscanf ( V_7 , L_48 , & V_56 ) != 1 )
return - V_39 ;
if ( V_56 > 25500 || V_56 < 100 )
return - V_52 ;
V_137 = ( T_4 ) ( V_56 / 100 ) ;
V_11 -> V_15 -> V_137 = V_137 ;
return strlen ( V_7 ) ;
}
static T_1
F_80 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
int V_121 = 0 ;
if ( V_11 -> V_15 -> V_105 )
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_50 ) ;
else
V_121 += snprintf ( V_7 + V_121 , V_108 - V_121 , L_47 ) ;
return V_121 ;
}
static T_1
F_81 ( struct V_12 * V_91 , struct V_107 * V_103 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_56 = 0 ;
int V_16 ;
if ( F_82 ( V_14 ) || F_83 ( V_14 ) )
return - V_86 ;
if ( F_84 ( V_138 , & V_11 -> V_30 ) ) {
F_9 ( V_43 , V_11 , 0x707a ,
L_51 ) ;
return - V_139 ;
}
if ( sscanf ( V_7 , L_48 , & V_56 ) != 1 )
return - V_39 ;
if ( V_56 )
V_16 = V_14 -> V_32 -> V_140 ( V_11 ) ;
else
V_16 = V_14 -> V_32 -> V_106 ( V_11 ) ;
if ( V_16 != V_42 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_85 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_52 , V_14 -> V_141 [ 1 ] ,
V_14 -> V_141 [ 0 ] ) ;
}
static T_1
F_86 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_52 , V_14 -> V_142 [ 1 ] ,
V_14 -> V_142 [ 0 ] ) ;
}
static T_1
F_87 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_52 , V_14 -> V_143 [ 1 ] ,
V_14 -> V_143 [ 0 ] ) ;
}
static T_1
F_88 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_53 ,
V_14 -> V_144 [ 0 ] , V_14 -> V_144 [ 1 ] , V_14 -> V_144 [ 2 ] ,
V_14 -> V_144 [ 3 ] ) ;
}
static T_1
F_89 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_90 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_54 ) ;
return snprintf ( V_7 , V_108 , L_55 ,
V_14 -> V_145 [ 0 ] , V_14 -> V_145 [ 1 ] ,
V_14 -> V_145 [ 2 ] , V_14 -> V_145 [ 3 ] ) ;
}
static T_1
F_91 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
return snprintf ( V_7 , V_108 , L_56 ,
V_11 -> V_146 . V_147 ) ;
}
static T_1
F_92 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
int V_16 = V_42 ;
T_4 V_148 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_93 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_54 ) ;
if ( V_14 -> V_149 -> V_150 == 0 )
V_16 = F_94 ( V_11 , V_148 ) ;
if ( ( V_16 == V_42 ) && ( V_148 [ 0 ] == 0 ) )
return snprintf ( V_7 , V_108 , L_57 ,
( T_5 ) V_14 -> V_149 -> V_150 ) ;
return snprintf ( V_7 , V_108 , L_54 ) ;
}
static T_1
F_95 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_50 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_54 ) ;
return snprintf ( V_7 , V_108 , L_58 ,
V_14 -> V_151 [ 0 ] , V_14 -> V_151 [ 1 ] , V_14 -> V_151 [ 2 ] ,
V_14 -> V_152 ) ;
}
static T_1
F_96 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_50 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_54 ) ;
return snprintf ( V_7 , V_108 , L_59 ,
V_14 -> V_153 [ 0 ] , V_14 -> V_153 [ 1 ] , V_14 -> V_153 [ 2 ] ) ;
}
static T_1
F_97 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_60 , V_14 -> V_154 ) ;
}
static T_1
F_98 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_108 , L_54 ) ;
return snprintf ( V_7 , V_108 , L_56 , V_11 -> V_155 ) ;
}
static T_1
F_99 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_108 , L_54 ) ;
return snprintf ( V_7 , V_108 , L_61 ,
V_11 -> V_156 [ 5 ] , V_11 -> V_156 [ 4 ] ,
V_11 -> V_156 [ 3 ] , V_11 -> V_156 [ 2 ] ,
V_11 -> V_156 [ 1 ] , V_11 -> V_156 [ 0 ] ) ;
}
static T_1
F_100 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
return snprintf ( V_7 , V_108 , L_56 , V_11 -> V_15 -> V_157 ) ;
}
static T_1
F_101 ( struct V_12 * V_91 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
int V_16 = V_158 ;
T_4 V_159 , V_160 ;
if ( ! V_11 -> V_15 -> V_84 . V_161 )
return snprintf ( V_7 , V_108 , L_54 ) ;
V_159 = V_160 = 0 ;
if ( F_74 ( V_11 ) )
F_9 ( V_43 , V_11 , 0x707b ,
L_62 ) ;
else if ( ! V_11 -> V_15 -> V_84 . V_162 )
V_16 = F_102 ( V_11 , & V_159 , & V_160 ) ;
if ( V_16 != V_42 )
return snprintf ( V_7 , V_108 , L_54 ) ;
return snprintf ( V_7 , V_108 , L_52 , V_159 , V_160 ) ;
}
static T_1
F_103 ( struct V_12 * V_91 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_64 ( V_91 ) ) ;
int V_16 = V_158 ;
T_4 V_163 [ 5 ] ;
if ( F_74 ( V_11 ) )
F_9 ( V_43 , V_11 , 0x707c ,
L_62 ) ;
else if ( ! V_11 -> V_15 -> V_84 . V_162 )
V_16 = F_104 ( V_11 , V_163 ) ;
if ( V_16 != V_42 )
memset ( V_163 , - 1 , sizeof( V_163 ) ) ;
return snprintf ( V_7 , V_108 , L_63 , V_163 [ 0 ] ,
V_163 [ 1 ] , V_163 [ 2 ] , V_163 [ 3 ] , V_163 [ 4 ] ) ;
}
static void
F_105 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_106 ( V_164 ) = V_11 -> V_165 . V_166 . V_167 << 16 |
V_11 -> V_165 . V_166 . V_168 << 8 | V_11 -> V_165 . V_166 . V_169 ;
}
static void
F_107 ( struct V_96 * V_164 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_164 ) ) ) -> V_15 ;
T_8 V_170 = V_171 ;
switch ( V_14 -> V_172 ) {
case V_173 :
V_170 = V_174 ;
break;
case V_175 :
V_170 = V_176 ;
break;
case V_177 :
V_170 = V_178 ;
break;
case V_179 :
V_170 = V_180 ;
break;
case V_181 :
V_170 = V_182 ;
break;
case V_183 :
V_170 = V_184 ;
break;
}
F_108 ( V_164 ) = V_170 ;
}
static void
F_109 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
T_5 V_185 = V_186 ;
if ( V_11 -> V_187 ) {
F_110 ( V_164 ) = V_188 ;
return;
}
switch ( V_11 -> V_15 -> V_128 ) {
case V_129 :
V_185 = V_189 ;
break;
case V_130 :
V_185 = V_190 ;
break;
case V_131 :
V_185 = V_191 ;
break;
case V_132 :
V_185 = V_192 ;
break;
}
F_110 ( V_164 ) = V_185 ;
}
static void
F_111 ( struct V_193 * V_194 )
{
struct V_96 * V_83 = F_3 ( V_194 -> V_91 . V_195 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_196 ;
T_10 V_197 = 0 ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_196 -> V_198 &&
V_194 -> V_199 == V_196 -> V_198 -> V_200 ) {
V_197 = F_113 ( V_196 -> V_197 ) ;
break;
}
}
F_114 ( V_194 ) = V_197 ;
}
static void
F_115 ( struct V_193 * V_194 )
{
struct V_96 * V_83 = F_3 ( V_194 -> V_91 . V_195 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_196 ;
T_10 V_201 = 0 ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_196 -> V_198 &&
V_194 -> V_199 == V_196 -> V_198 -> V_200 ) {
V_201 = F_113 ( V_196 -> V_201 ) ;
break;
}
}
F_116 ( V_194 ) = V_201 ;
}
static void
F_117 ( struct V_193 * V_194 )
{
struct V_96 * V_83 = F_3 ( V_194 -> V_91 . V_195 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_196 ;
T_5 V_202 = ~ 0U ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_196 -> V_198 &&
V_194 -> V_199 == V_196 -> V_198 -> V_200 ) {
V_202 = V_196 -> V_165 . V_166 . V_167 << 16 |
V_196 -> V_165 . V_166 . V_168 << 8 | V_196 -> V_165 . V_166 . V_169 ;
break;
}
}
F_118 ( V_194 ) = V_202 ;
}
static void
F_119 ( struct V_203 * V_198 , T_5 V_204 )
{
if ( V_204 )
V_198 -> V_205 = V_204 ;
else
V_198 -> V_205 = 1 ;
}
static void
F_120 ( struct V_203 * V_198 )
{
struct V_96 * V_83 = F_121 ( V_198 ) ;
T_9 * V_196 = * ( T_9 * * ) V_198 -> V_206 ;
unsigned long V_84 ;
if ( ! V_196 )
return;
F_122 ( V_196 , V_207 ) ;
F_123 ( V_83 -> V_208 , V_84 ) ;
V_196 -> V_198 = V_196 -> V_209 = NULL ;
* ( ( T_9 * * ) V_198 -> V_206 ) = NULL ;
F_124 ( V_83 -> V_208 , V_84 ) ;
if ( F_84 ( V_138 , & V_196 -> V_11 -> V_30 ) )
return;
if ( F_32 ( F_33 ( V_196 -> V_11 -> V_15 -> V_58 ) ) ) {
F_125 ( V_196 -> V_11 , V_210 << 16 ) ;
return;
}
}
static void
F_126 ( struct V_203 * V_198 )
{
T_9 * V_196 = * ( T_9 * * ) V_198 -> V_206 ;
if ( ! V_196 )
return;
if ( F_84 ( V_138 , & V_196 -> V_11 -> V_30 ) )
return;
if ( F_32 ( F_33 ( V_196 -> V_11 -> V_15 -> V_58 ) ) ) {
F_125 ( V_196 -> V_11 , V_210 << 16 ) ;
return;
}
if ( V_196 -> V_211 != V_212 &&
! F_84 ( V_213 , & V_196 -> V_11 -> V_30 ) ) {
if ( F_23 ( V_196 -> V_11 -> V_15 ) )
V_196 -> V_11 -> V_15 -> V_32 -> V_214 ( V_196 -> V_11 ,
V_196 -> V_211 , V_196 -> V_165 . V_166 . V_167 ,
V_196 -> V_165 . V_166 . V_168 , V_196 -> V_165 . V_166 . V_169 ) ;
else
F_127 ( V_196 -> V_11 , V_196 ) ;
}
}
static int
F_128 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_129 ( V_11 ) ;
return 0 ;
}
static struct V_215 *
F_130 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_82 = F_46 ( V_14 -> V_58 ) ;
int V_16 ;
struct V_216 * V_217 ;
T_11 V_218 ;
struct V_215 * V_219 ;
V_219 = & V_11 -> V_220 ;
memset ( V_219 , - 1 , sizeof( struct V_215 ) ) ;
if ( F_84 ( V_213 , & V_11 -> V_30 ) )
goto V_221;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
goto V_221;
V_217 = F_43 ( V_14 -> V_77 , V_78 , & V_218 ) ;
if ( V_217 == NULL ) {
F_9 ( V_43 , V_11 , 0x707d ,
L_64 ) ;
goto V_221;
}
memset ( V_217 , 0 , V_222 ) ;
V_16 = V_158 ;
if ( F_23 ( V_14 ) ) {
V_16 = F_131 ( V_82 , V_217 , V_218 ) ;
} else if ( F_73 ( & V_82 -> V_122 ) == V_127 &&
! F_74 ( V_11 ) && ! V_14 -> V_223 ) {
V_16 = F_132 ( V_82 , V_82 -> V_211 ,
V_217 , V_218 ) ;
}
if ( V_16 != V_42 )
goto V_224;
V_219 -> V_225 = V_217 -> V_226 ;
V_219 -> V_227 = V_217 -> V_228 ;
V_219 -> V_229 = V_217 -> V_230 ;
V_219 -> V_231 = V_217 -> V_232 ;
V_219 -> V_233 = V_217 -> V_234 ;
V_219 -> V_235 = V_217 -> V_236 ;
if ( F_23 ( V_14 ) ) {
V_219 -> V_237 = V_217 -> V_238 ;
V_219 -> V_239 = V_217 -> V_239 ;
V_219 -> V_240 = V_217 -> V_240 ;
V_219 -> V_241 = V_217 -> V_241 ;
V_219 -> V_242 = V_217 -> V_243 ;
}
V_219 -> V_244 = V_11 -> V_146 . V_245 >> 20 ;
V_219 -> V_246 = V_11 -> V_146 . V_247 >> 20 ;
V_224:
F_133 ( V_14 -> V_77 , V_217 , V_218 ) ;
V_221:
return V_219 ;
}
static void
F_134 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_135 ( V_11 , F_136 ( V_164 ) ) ;
}
static void
F_137 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_18 ( V_248 , & V_11 -> V_30 ) ;
}
static void
F_138 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
T_6 V_197 [ V_249 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_250 = F_113 ( V_197 ) ;
if ( V_11 -> V_125 & V_251 )
V_250 = F_113 ( V_11 -> V_252 ) ;
F_139 ( V_164 ) = V_250 ;
}
static void
F_140 ( struct V_96 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
struct V_10 * V_82 = F_46 ( V_11 -> V_15 -> V_58 ) ;
if ( ! V_82 -> V_84 . V_253 ) {
F_141 ( V_164 ) = V_254 ;
return;
}
switch ( F_73 ( & V_82 -> V_122 ) ) {
case V_255 :
F_141 ( V_164 ) = V_256 ;
break;
case V_123 :
if ( F_84 ( V_257 , & V_82 -> V_30 ) )
F_141 ( V_164 ) = V_256 ;
else
F_141 ( V_164 ) = V_258 ;
break;
case V_124 :
F_141 ( V_164 ) = V_258 ;
break;
case V_127 :
F_141 ( V_164 ) = V_259 ;
break;
default:
F_141 ( V_164 ) = V_260 ;
break;
}
}
static int
F_142 ( struct V_261 * V_261 , bool V_262 )
{
int V_98 = 0 ;
T_6 V_263 = 0 ;
T_7 * V_82 = F_2 ( V_261 -> V_164 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_82 -> V_15 ;
T_4 V_264 = 0 ;
int V_37 ;
struct V_265 * V_266 = V_14 -> V_267 [ 0 ] ;
V_98 = F_143 ( V_261 ) ;
if ( V_98 ) {
F_9 ( V_43 , V_11 , 0x707e ,
L_65 , V_98 ) ;
return ( V_98 ) ;
}
V_11 = F_144 ( V_261 ) ;
if ( V_11 == NULL ) {
F_9 ( V_43 , V_11 , 0x707f , L_66 ) ;
return V_268 ;
}
if ( V_262 ) {
F_145 ( & V_11 -> V_269 , V_270 ) ;
F_146 ( V_261 , V_271 ) ;
} else
F_145 ( & V_11 -> V_269 , V_272 ) ;
F_9 ( V_25 , V_11 , 0x7080 ,
L_67 , V_11 -> V_187 ) ;
F_145 ( & V_11 -> V_122 , V_123 ) ;
V_11 -> V_273 = V_274 ;
V_11 -> V_275 = V_276 ;
if ( F_73 ( & V_82 -> V_122 ) == V_123 ||
F_73 ( & V_82 -> V_122 ) == V_124 ) {
F_17 ( V_28 , V_11 , 0x7081 ,
L_68 ) ;
F_145 ( & V_11 -> V_122 , V_124 ) ;
if ( ! V_262 )
F_146 ( V_261 , V_277 ) ;
}
if ( F_147 ( V_14 ) && V_278 ) {
if ( V_14 -> V_279 & V_280 ) {
int V_281 = 0 ;
V_11 -> V_84 . V_282 = 1 ;
F_17 ( V_28 , V_11 , 0x7082 ,
L_69 ) ;
if ( V_278 == 1 )
V_281 = V_283 ;
F_148 ( V_11 -> V_83 ,
V_281 | V_284
| V_285
| V_286
| V_287
| V_288
| V_289 ) ;
F_149 ( V_11 -> V_83 , V_290 ) ;
} else
V_11 -> V_84 . V_282 = 0 ;
}
if ( F_150 ( V_11 -> V_83 , & V_261 -> V_91 ,
& V_14 -> V_58 -> V_91 ) ) {
F_17 ( V_28 , V_11 , 0x7083 ,
L_70 , V_11 -> V_187 ) ;
goto V_291;
}
F_151 ( V_11 -> V_83 ) = V_14 -> V_292 ;
F_152 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_197 ) ;
F_153 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_201 ) ;
F_154 ( V_11 -> V_83 ) =
F_154 ( V_82 -> V_83 ) ;
F_155 ( V_11 -> V_83 ) =
F_155 ( V_82 -> V_83 ) ;
F_156 ( V_11 , V_14 ) ;
F_157 ( V_261 , V_262 ) ;
if ( V_14 -> V_84 . V_293 ) {
V_266 = V_14 -> V_267 [ 1 ] ;
F_17 ( V_294 , V_11 , 0xc000 ,
L_71
L_72 ,
V_266 , V_11 -> V_187 , V_14 -> V_84 . V_293 ) ;
goto V_295;
} else if ( V_296 == 1 || ! V_14 -> V_297 )
goto V_295;
for ( V_37 = 0 ; V_37 < V_14 -> V_298 ; V_37 ++ ) {
if ( memcmp ( V_14 -> V_297 [ V_37 ] . V_201 , V_11 -> V_201 , 8 ) == 0
&& memcmp ( V_14 -> V_297 [ V_37 ] . V_197 , V_11 -> V_197 ,
8 ) == 0 ) {
V_263 = V_14 -> V_297 [ V_37 ] . V_299 ;
break;
}
}
if ( V_263 ) {
V_98 = F_158 ( V_14 , V_264 , V_11 -> V_187 , 0 , 0 ,
V_263 ) ;
if ( ! V_98 )
F_9 ( V_43 , V_11 , 0x7084 ,
L_73 ,
V_11 -> V_187 ) ;
else {
F_17 ( V_294 , V_11 , 0xc001 ,
L_74 ,
V_98 , V_263 , V_11 -> V_187 ) ;
F_17 ( V_28 , V_11 , 0x7085 ,
L_74 ,
V_98 , V_263 , V_11 -> V_187 ) ;
V_266 = V_14 -> V_267 [ V_98 ] ;
}
}
V_295:
V_11 -> V_266 = V_266 ;
return 0 ;
V_291:
F_159 ( V_11 ) ;
F_160 ( V_11 ) ;
F_161 ( V_11 -> V_83 ) ;
return V_268 ;
}
static int
F_162 ( struct V_261 * V_261 )
{
T_7 * V_11 = V_261 -> V_206 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_199 = V_11 -> V_187 ;
while ( F_84 ( V_300 , & V_11 -> V_30 ) ||
F_84 ( V_301 , & V_11 -> V_30 ) )
F_163 ( 1000 ) ;
F_159 ( V_11 ) ;
V_11 -> V_84 . V_302 = 1 ;
F_164 ( V_11 -> V_83 ) ;
F_165 ( V_11 -> V_83 ) ;
F_160 ( V_11 ) ;
if ( V_11 -> V_303 ) {
F_166 ( V_11 ) ;
F_17 ( V_28 , V_11 , 0x7086 ,
L_75 , V_11 -> V_187 ) ;
}
if ( V_304 & V_28 )
F_163 ( F_167 () % 10 ) ;
F_168 ( F_73 ( & V_11 -> V_305 ) ) ;
F_169 ( V_11 ) ;
F_170 ( & V_14 -> V_306 ) ;
V_14 -> V_307 -- ;
F_171 ( V_11 -> V_187 , V_14 -> V_308 ) ;
F_172 ( & V_14 -> V_306 ) ;
if ( V_11 -> V_266 -> V_199 && ! V_14 -> V_84 . V_293 ) {
if ( F_173 ( V_11 , V_11 -> V_266 ) != V_42 )
F_9 ( V_43 , V_11 , 0x7087 ,
L_76 ) ;
}
F_9 ( V_25 , V_11 , 0x7088 , L_77 , V_199 ) ;
F_161 ( V_11 -> V_83 ) ;
return 0 ;
}
static int
F_157 ( struct V_261 * V_261 , bool V_262 )
{
T_7 * V_11 = V_261 -> V_206 ;
if ( V_262 )
F_159 ( V_11 ) ;
else
F_174 ( V_11 ) ;
return 0 ;
}
void
F_175 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_170 = V_171 ;
F_151 ( V_11 -> V_83 ) = V_14 -> V_292 ;
F_152 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_197 ) ;
F_153 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_201 ) ;
F_154 ( V_11 -> V_83 ) = V_14 -> V_309 . V_310 ?
( V_311 | V_312 ) : V_312 ;
F_176 ( V_11 -> V_83 ) = V_14 -> V_313 ;
F_177 ( V_11 -> V_83 ) = V_14 -> V_307 ;
if ( F_38 ( V_14 ) )
V_170 = V_182 ;
else if ( F_39 ( V_14 ) )
V_170 = V_184 | V_180 |
V_178 ;
else if ( F_37 ( V_14 ) )
V_170 = V_180 | V_178 |
V_176 | V_174 ;
else if ( F_36 ( V_14 ) )
V_170 = V_178 | V_176 |
V_174 ;
else if ( F_178 ( V_14 ) )
V_170 = V_176 | V_174 ;
else
V_170 = V_174 ;
F_155 ( V_11 -> V_83 ) = V_170 ;
}
