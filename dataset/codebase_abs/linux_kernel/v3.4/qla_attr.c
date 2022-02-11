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
F_13 ( V_14 ) ;
F_14 ( V_11 ) ;
F_15 ( V_14 ) ;
}
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_48 ( V_11 -> V_83 ) ;
break;
case 0x2025d :
if ( ! F_49 ( V_14 ) )
return - V_84 ;
F_9 ( V_25 , V_11 , 0x706f ,
L_23 ) ;
F_26 ( V_11 ) ;
F_47 ( V_11 -> V_83 ) ;
if ( F_50 ( V_11 ) != V_42 )
F_9 ( V_43 , V_11 , 0x7070 ,
L_24 ) ;
F_48 ( V_11 -> V_83 ) ;
break;
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_82 ) {
F_9 ( V_25 , V_11 , 0x7071 ,
L_25 ) ;
return - V_84 ;
}
F_9 ( V_25 , V_11 , 0x7072 ,
L_26 ) ;
F_18 ( V_85 , & V_11 -> V_30 ) ;
F_27 ( V_11 ) ;
F_51 ( V_11 ) ;
break;
}
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
int V_16 ;
T_4 V_86 ;
if ( ! F_20 ( V_31 ) || V_8 != 0 || V_9 > V_87 )
return 0 ;
if ( V_14 -> V_88 )
goto V_76;
V_14 -> V_88 = F_53 ( & V_14 -> V_58 -> V_89 , V_87 ,
& V_14 -> V_90 , V_78 ) ;
if ( ! V_14 -> V_88 ) {
F_9 ( V_43 , V_11 , 0x7076 ,
L_27 ) ;
return 0 ;
}
V_76:
V_86 = 0 ;
memset ( V_14 -> V_88 , 0 , V_87 ) ;
V_16 = F_54 ( V_11 , V_14 -> V_90 ,
V_87 , & V_86 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x7077 ,
L_28 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_86 > V_9 ? V_9 : V_86 ;
memcpy ( V_7 , V_14 -> V_88 , V_9 ) ;
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
int V_16 ;
T_4 V_86 ;
if ( ! F_20 ( V_31 ) || V_8 != 0 || V_9 > V_91 )
return 0 ;
if ( V_14 -> V_92 )
goto V_76;
V_14 -> V_92 = F_53 ( & V_14 -> V_58 -> V_89 , V_91 ,
& V_14 -> V_93 , V_78 ) ;
if ( ! V_14 -> V_92 ) {
F_9 ( V_43 , V_11 , 0x7078 ,
L_29 ) ;
return - V_61 ;
}
V_76:
V_86 = 0 ;
memset ( V_14 -> V_92 , 0 , V_91 ) ;
V_16 = F_56 ( V_11 , V_14 -> V_93 ,
V_91 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x7079 ,
L_30 , V_16 ) ;
return - V_81 ;
}
memcpy ( V_7 , V_14 -> V_92 , V_9 ) ;
return V_9 ;
}
void
F_57 ( T_7 * V_11 )
{
struct V_94 * V_83 = V_11 -> V_83 ;
struct V_95 * V_40 ;
int V_96 ;
for ( V_40 = V_97 ; V_40 -> V_98 ; V_40 ++ ) {
if ( V_40 -> V_99 && ! F_23 ( V_11 -> V_15 ) )
continue;
if ( V_40 -> V_99 == 2 && ! F_37 ( V_11 -> V_15 ) )
continue;
if ( V_40 -> V_99 == 3 && ! ( F_38 ( V_11 -> V_15 ) ) )
continue;
V_96 = F_58 ( & V_83 -> V_100 . V_4 ,
V_40 -> V_101 ) ;
if ( V_96 )
F_9 ( V_43 , V_11 , 0x00f3 ,
L_31 ,
V_40 -> V_98 , V_96 ) ;
else
F_17 ( V_102 , V_11 , 0x00f4 ,
L_32 ,
V_40 -> V_98 ) ;
}
}
void
F_59 ( T_7 * V_11 )
{
struct V_94 * V_83 = V_11 -> V_83 ;
struct V_95 * V_40 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_40 = V_97 ; V_40 -> V_98 ; V_40 ++ ) {
if ( V_40 -> V_99 && ! F_23 ( V_14 ) )
continue;
if ( V_40 -> V_99 == 2 && ! F_37 ( V_14 ) )
continue;
if ( V_40 -> V_99 == 3 && ! ( F_38 ( V_11 -> V_15 ) ) )
continue;
F_60 ( & V_83 -> V_100 . V_4 ,
V_40 -> V_101 ) ;
}
if ( V_14 -> V_103 == 1 )
V_14 -> V_32 -> V_104 ( V_11 ) ;
}
static T_1
F_61 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
return snprintf ( V_7 , V_106 , L_33 , V_107 ) ;
}
static T_1
F_62 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_108 [ 128 ] ;
return snprintf ( V_7 , V_106 , L_33 ,
V_14 -> V_32 -> V_109 ( V_11 , V_108 ) ) ;
}
static T_1
F_64 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_110 ;
if ( F_23 ( V_14 ) ) {
F_65 ( V_11 , L_34 , V_7 , V_106 ) ;
return snprintf ( V_7 , V_106 , L_33 , V_7 ) ;
}
V_110 = ( ( V_14 -> V_111 & 0x1f ) << 16 ) | ( V_14 -> V_112 << 8 ) | V_14 -> V_113 ;
return snprintf ( V_7 , V_106 , L_35 , 'A' + V_110 / 100000 ,
V_110 % 100000 ) ;
}
static T_1
F_66 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
return snprintf ( V_7 , V_106 , L_36 , V_11 -> V_15 -> V_58 -> V_12 ) ;
}
static T_1
F_67 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_37 ,
V_14 -> V_114 [ 0 ] , V_14 -> V_114 [ 1 ] , V_14 -> V_114 [ 2 ] ,
V_14 -> V_114 [ 3 ] ) ;
}
static T_1
F_68 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
return snprintf ( V_7 , V_106 , L_33 , V_11 -> V_15 -> V_115 ) ;
}
static T_1
F_69 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
return snprintf ( V_7 , V_106 , L_33 ,
V_11 -> V_15 -> V_116 ? V_11 -> V_15 -> V_116 : L_38 ) ;
}
static T_1
F_70 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
char V_117 [ 30 ] ;
return snprintf ( V_7 , V_106 , L_33 ,
V_11 -> V_15 -> V_32 -> V_118 ( V_11 , V_117 ) ) ;
}
static T_1
F_71 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_119 = 0 ;
if ( F_72 ( & V_11 -> V_120 ) == V_121 ||
F_72 ( & V_11 -> V_120 ) == V_122 ||
V_11 -> V_123 & V_124 )
V_119 = snprintf ( V_7 , V_106 , L_39 ) ;
else if ( F_72 ( & V_11 -> V_120 ) != V_125 ||
F_73 ( V_11 ) )
V_119 = snprintf ( V_7 , V_106 , L_40 ) ;
else {
V_119 = snprintf ( V_7 , V_106 , L_41 ) ;
switch ( V_14 -> V_126 ) {
case V_127 :
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_42 ) ;
break;
case V_128 :
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_43 ) ;
break;
case V_129 :
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 ,
L_44 ) ;
break;
case V_130 :
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_45 ) ;
break;
default:
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_42 ) ;
break;
}
}
return V_119 ;
}
static T_1
F_74 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
int V_119 = 0 ;
switch ( V_11 -> V_15 -> V_131 ) {
case V_132 :
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_46 ) ;
break;
case V_133 :
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_47 ) ;
break;
}
return V_119 ;
}
static T_1
F_75 ( struct V_12 * V_89 , struct V_105 * V_101 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_56 = 0 ;
T_4 V_131 ;
if ( ! F_76 ( V_14 ) )
return - V_134 ;
if ( sscanf ( V_7 , L_48 , & V_56 ) != 1 )
return - V_39 ;
if ( V_56 )
V_131 = V_132 ;
else
V_131 = V_133 ;
if ( V_131 != V_133 || V_14 -> V_131 != V_133 ) {
V_14 -> V_131 = V_131 ;
F_18 ( V_29 , & V_11 -> V_30 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_77 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
return snprintf ( V_7 , V_106 , L_49 , V_11 -> V_15 -> V_135 * 100 ) ;
}
static T_1
F_78 ( struct V_12 * V_89 , struct V_105 * V_101 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
int V_56 = 0 ;
T_4 V_135 ;
if ( sscanf ( V_7 , L_48 , & V_56 ) != 1 )
return - V_39 ;
if ( V_56 > 25500 || V_56 < 100 )
return - V_52 ;
V_135 = ( T_4 ) ( V_56 / 100 ) ;
V_11 -> V_15 -> V_135 = V_135 ;
return strlen ( V_7 ) ;
}
static T_1
F_79 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
int V_119 = 0 ;
if ( V_11 -> V_15 -> V_103 )
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_50 ) ;
else
V_119 += snprintf ( V_7 + V_119 , V_106 - V_119 , L_47 ) ;
return V_119 ;
}
static T_1
F_80 ( struct V_12 * V_89 , struct V_105 * V_101 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_56 = 0 ;
int V_16 ;
if ( F_81 ( V_14 ) || F_82 ( V_14 ) )
return - V_84 ;
if ( F_83 ( V_136 , & V_11 -> V_30 ) ) {
F_9 ( V_43 , V_11 , 0x707a ,
L_51 ) ;
return - V_137 ;
}
if ( sscanf ( V_7 , L_48 , & V_56 ) != 1 )
return - V_39 ;
if ( V_56 )
V_16 = V_14 -> V_32 -> V_138 ( V_11 ) ;
else
V_16 = V_14 -> V_32 -> V_104 ( V_11 ) ;
if ( V_16 != V_42 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_84 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_52 , V_14 -> V_139 [ 1 ] ,
V_14 -> V_139 [ 0 ] ) ;
}
static T_1
F_85 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_52 , V_14 -> V_140 [ 1 ] ,
V_14 -> V_140 [ 0 ] ) ;
}
static T_1
F_86 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_52 , V_14 -> V_141 [ 1 ] ,
V_14 -> V_141 [ 0 ] ) ;
}
static T_1
F_87 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_53 ,
V_14 -> V_142 [ 0 ] , V_14 -> V_142 [ 1 ] , V_14 -> V_142 [ 2 ] ,
V_14 -> V_142 [ 3 ] ) ;
}
static T_1
F_88 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_89 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_54 ) ;
return snprintf ( V_7 , V_106 , L_55 ,
V_14 -> V_143 [ 0 ] , V_14 -> V_143 [ 1 ] ,
V_14 -> V_143 [ 2 ] , V_14 -> V_143 [ 3 ] ) ;
}
static T_1
F_90 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_56 ,
V_14 -> V_144 . V_145 ) ;
}
static T_1
F_91 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
int V_16 = V_42 ;
T_4 V_146 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_92 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_54 ) ;
if ( V_14 -> V_147 -> V_148 == 0 )
V_16 = F_93 ( V_11 , V_146 ) ;
if ( ( V_16 == V_42 ) && ( V_146 [ 0 ] == 0 ) )
return snprintf ( V_7 , V_106 , L_57 ,
( T_5 ) V_14 -> V_147 -> V_148 ) ;
return snprintf ( V_7 , V_106 , L_54 ) ;
}
static T_1
F_94 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_95 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_54 ) ;
return snprintf ( V_7 , V_106 , L_58 ,
V_14 -> V_149 [ 0 ] , V_14 -> V_149 [ 1 ] , V_14 -> V_149 [ 2 ] ,
V_14 -> V_150 ) ;
}
static T_1
F_96 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_49 ( V_14 ) && ! F_89 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_54 ) ;
return snprintf ( V_7 , V_106 , L_59 ,
V_14 -> V_151 [ 0 ] , V_14 -> V_151 [ 1 ] , V_14 -> V_151 [ 2 ] ) ;
}
static T_1
F_97 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_60 , V_14 -> V_152 ) ;
}
static T_1
F_98 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_106 , L_54 ) ;
return snprintf ( V_7 , V_106 , L_56 , V_11 -> V_153 ) ;
}
static T_1
F_99 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
if ( ! F_38 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_106 , L_54 ) ;
return snprintf ( V_7 , V_106 , L_61 ,
V_11 -> V_154 [ 5 ] , V_11 -> V_154 [ 4 ] ,
V_11 -> V_154 [ 3 ] , V_11 -> V_154 [ 2 ] ,
V_11 -> V_154 [ 1 ] , V_11 -> V_154 [ 0 ] ) ;
}
static T_1
F_100 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
return snprintf ( V_7 , V_106 , L_56 , V_11 -> V_15 -> V_155 ) ;
}
static T_1
F_101 ( struct V_12 * V_89 ,
struct V_105 * V_101 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
int V_16 = V_156 ;
T_4 V_157 , V_158 ;
if ( ! V_11 -> V_15 -> V_159 . V_160 )
return snprintf ( V_7 , V_106 , L_54 ) ;
V_157 = V_158 = 0 ;
if ( F_73 ( V_11 ) )
F_9 ( V_43 , V_11 , 0x707b ,
L_62 ) ;
else if ( ! V_11 -> V_15 -> V_159 . V_161 )
V_16 = F_102 ( V_11 , & V_157 , & V_158 ) ;
if ( V_16 != V_42 )
return snprintf ( V_7 , V_106 , L_54 ) ;
return snprintf ( V_7 , V_106 , L_52 , V_157 , V_158 ) ;
}
static T_1
F_103 ( struct V_12 * V_89 , struct V_105 * V_101 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_63 ( V_89 ) ) ;
int V_16 = V_156 ;
T_4 V_162 [ 5 ] ;
if ( F_73 ( V_11 ) )
F_9 ( V_43 , V_11 , 0x707c ,
L_62 ) ;
else if ( ! V_11 -> V_15 -> V_159 . V_161 )
V_16 = F_104 ( V_11 , V_162 ) ;
if ( V_16 != V_42 )
memset ( V_162 , - 1 , sizeof( V_162 ) ) ;
return snprintf ( V_7 , V_106 , L_63 , V_162 [ 0 ] ,
V_162 [ 1 ] , V_162 [ 2 ] , V_162 [ 3 ] , V_162 [ 4 ] ) ;
}
static void
F_105 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
F_106 ( V_163 ) = V_11 -> V_164 . V_165 . V_166 << 16 |
V_11 -> V_164 . V_165 . V_167 << 8 | V_11 -> V_164 . V_165 . V_168 ;
}
static void
F_107 ( struct V_94 * V_163 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_163 ) ) ) -> V_15 ;
T_8 V_169 = V_170 ;
switch ( V_14 -> V_171 ) {
case V_172 :
V_169 = V_173 ;
break;
case V_174 :
V_169 = V_175 ;
break;
case V_176 :
V_169 = V_177 ;
break;
case V_178 :
V_169 = V_179 ;
break;
case V_180 :
V_169 = V_181 ;
break;
case V_182 :
V_169 = V_183 ;
break;
}
F_108 ( V_163 ) = V_169 ;
}
static void
F_109 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
T_5 V_184 = V_185 ;
if ( V_11 -> V_186 ) {
F_110 ( V_163 ) = V_187 ;
return;
}
switch ( V_11 -> V_15 -> V_126 ) {
case V_127 :
V_184 = V_188 ;
break;
case V_128 :
V_184 = V_189 ;
break;
case V_129 :
V_184 = V_190 ;
break;
case V_130 :
V_184 = V_191 ;
break;
}
F_110 ( V_163 ) = V_184 ;
}
static void
F_111 ( struct V_192 * V_193 )
{
struct V_94 * V_83 = F_3 ( V_193 -> V_89 . V_194 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_195 ;
T_10 V_196 = 0 ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_195 -> V_197 &&
V_193 -> V_198 == V_195 -> V_197 -> V_199 ) {
V_196 = F_113 ( V_195 -> V_196 ) ;
break;
}
}
F_114 ( V_193 ) = V_196 ;
}
static void
F_115 ( struct V_192 * V_193 )
{
struct V_94 * V_83 = F_3 ( V_193 -> V_89 . V_194 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_195 ;
T_10 V_200 = 0 ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_195 -> V_197 &&
V_193 -> V_198 == V_195 -> V_197 -> V_199 ) {
V_200 = F_113 ( V_195 -> V_200 ) ;
break;
}
}
F_116 ( V_193 ) = V_200 ;
}
static void
F_117 ( struct V_192 * V_193 )
{
struct V_94 * V_83 = F_3 ( V_193 -> V_89 . V_194 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_195 ;
T_5 V_201 = ~ 0U ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_195 -> V_197 &&
V_193 -> V_198 == V_195 -> V_197 -> V_199 ) {
V_201 = V_195 -> V_164 . V_165 . V_166 << 16 |
V_195 -> V_164 . V_165 . V_167 << 8 | V_195 -> V_164 . V_165 . V_168 ;
break;
}
}
F_118 ( V_193 ) = V_201 ;
}
static void
F_119 ( struct V_202 * V_197 , T_5 V_203 )
{
if ( V_203 )
V_197 -> V_204 = V_203 ;
else
V_197 -> V_204 = 1 ;
}
static void
F_120 ( struct V_202 * V_197 )
{
struct V_94 * V_83 = F_121 ( V_197 ) ;
T_9 * V_195 = * ( T_9 * * ) V_197 -> V_205 ;
unsigned long V_159 ;
if ( ! V_195 )
return;
F_122 ( V_195 , V_206 ) ;
F_123 ( V_83 -> V_207 , V_159 ) ;
V_195 -> V_197 = V_195 -> V_208 = NULL ;
* ( ( T_9 * * ) V_197 -> V_205 ) = NULL ;
F_124 ( V_83 -> V_207 , V_159 ) ;
if ( F_83 ( V_136 , & V_195 -> V_11 -> V_30 ) )
return;
if ( F_32 ( F_33 ( V_195 -> V_11 -> V_15 -> V_58 ) ) ) {
F_125 ( V_195 -> V_11 , V_209 << 16 ) ;
return;
}
}
static void
F_126 ( struct V_202 * V_197 )
{
T_9 * V_195 = * ( T_9 * * ) V_197 -> V_205 ;
if ( ! V_195 )
return;
if ( F_83 ( V_136 , & V_195 -> V_11 -> V_30 ) )
return;
if ( F_32 ( F_33 ( V_195 -> V_11 -> V_15 -> V_58 ) ) ) {
F_125 ( V_195 -> V_11 , V_209 << 16 ) ;
return;
}
if ( V_195 -> V_210 != V_211 &&
! F_83 ( V_212 , & V_195 -> V_11 -> V_30 ) ) {
if ( F_23 ( V_195 -> V_11 -> V_15 ) )
V_195 -> V_11 -> V_15 -> V_32 -> V_213 ( V_195 -> V_11 ,
V_195 -> V_210 , V_195 -> V_164 . V_165 . V_166 ,
V_195 -> V_164 . V_165 . V_167 , V_195 -> V_164 . V_165 . V_168 ) ;
else
F_127 ( V_195 -> V_11 , V_195 ) ;
}
}
static int
F_128 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
F_129 ( V_11 ) ;
return 0 ;
}
static struct V_214 *
F_130 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_82 = F_46 ( V_14 -> V_58 ) ;
int V_16 ;
struct V_215 * V_216 ;
T_11 V_217 ;
struct V_214 * V_218 ;
V_218 = & V_14 -> V_219 ;
memset ( V_218 , - 1 , sizeof( struct V_214 ) ) ;
if ( F_83 ( V_212 , & V_11 -> V_30 ) )
goto V_220;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
goto V_220;
V_216 = F_43 ( V_14 -> V_77 , V_78 , & V_217 ) ;
if ( V_216 == NULL ) {
F_9 ( V_43 , V_11 , 0x707d ,
L_64 ) ;
goto V_220;
}
memset ( V_216 , 0 , V_221 ) ;
V_16 = V_156 ;
if ( F_23 ( V_14 ) ) {
V_16 = F_131 ( V_82 , V_216 , V_217 ) ;
} else if ( F_72 ( & V_82 -> V_120 ) == V_125 &&
! F_73 ( V_11 ) && ! V_14 -> V_222 ) {
V_16 = F_132 ( V_82 , V_82 -> V_210 ,
V_216 , V_217 ) ;
}
if ( V_16 != V_42 )
goto V_223;
V_218 -> V_224 = V_216 -> V_225 ;
V_218 -> V_226 = V_216 -> V_227 ;
V_218 -> V_228 = V_216 -> V_229 ;
V_218 -> V_230 = V_216 -> V_231 ;
V_218 -> V_232 = V_216 -> V_233 ;
V_218 -> V_234 = V_216 -> V_235 ;
if ( F_23 ( V_14 ) ) {
V_218 -> V_236 = V_216 -> V_237 ;
V_218 -> V_238 = V_216 -> V_238 ;
V_218 -> V_239 = V_216 -> V_239 ;
V_218 -> V_240 = V_216 -> V_240 ;
V_218 -> V_241 = V_216 -> V_242 ;
}
V_218 -> V_243 = V_14 -> V_144 . V_244 >> 20 ;
V_218 -> V_245 = V_14 -> V_144 . V_246 >> 20 ;
V_223:
F_133 ( V_14 -> V_77 , V_216 , V_217 ) ;
V_220:
return V_218 ;
}
static void
F_134 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
F_135 ( V_11 , F_136 ( V_163 ) ) ;
}
static void
F_137 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
F_18 ( V_247 , & V_11 -> V_30 ) ;
}
static void
F_138 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
T_6 V_196 [ V_248 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_249 = F_113 ( V_196 ) ;
if ( V_11 -> V_123 & V_250 )
V_249 = F_113 ( V_11 -> V_251 ) ;
F_139 ( V_163 ) = V_249 ;
}
static void
F_140 ( struct V_94 * V_163 )
{
T_7 * V_11 = F_2 ( V_163 ) ;
struct V_10 * V_82 = F_46 ( V_11 -> V_15 -> V_58 ) ;
if ( ! V_82 -> V_159 . V_252 ) {
F_141 ( V_163 ) = V_253 ;
return;
}
switch ( F_72 ( & V_82 -> V_120 ) ) {
case V_254 :
F_141 ( V_163 ) = V_255 ;
break;
case V_121 :
if ( F_83 ( V_256 , & V_82 -> V_30 ) )
F_141 ( V_163 ) = V_255 ;
else
F_141 ( V_163 ) = V_257 ;
break;
case V_122 :
F_141 ( V_163 ) = V_257 ;
break;
case V_125 :
F_141 ( V_163 ) = V_258 ;
break;
default:
F_141 ( V_163 ) = V_259 ;
break;
}
}
static int
F_142 ( struct V_260 * V_260 , bool V_261 )
{
int V_96 = 0 ;
T_6 V_262 = 0 ;
T_7 * V_82 = F_2 ( V_260 -> V_163 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_82 -> V_15 ;
T_4 V_263 = 0 ;
int V_37 ;
struct V_264 * V_265 = V_14 -> V_266 [ 0 ] ;
V_96 = F_143 ( V_260 ) ;
if ( V_96 ) {
F_9 ( V_43 , V_11 , 0x707e ,
L_65 , V_96 ) ;
return ( V_96 ) ;
}
V_11 = F_144 ( V_260 ) ;
if ( V_11 == NULL ) {
F_9 ( V_43 , V_11 , 0x707f , L_66 ) ;
return V_267 ;
}
if ( V_261 ) {
F_145 ( & V_11 -> V_268 , V_269 ) ;
F_146 ( V_260 , V_270 ) ;
} else
F_145 ( & V_11 -> V_268 , V_271 ) ;
F_9 ( V_25 , V_11 , 0x7080 ,
L_67 , V_11 -> V_186 ) ;
F_145 ( & V_11 -> V_120 , V_121 ) ;
V_11 -> V_272 = V_273 ;
V_11 -> V_274 = V_275 ;
if ( F_72 ( & V_82 -> V_120 ) == V_121 ||
F_72 ( & V_82 -> V_120 ) == V_122 ) {
F_17 ( V_28 , V_11 , 0x7081 ,
L_68 ) ;
F_145 ( & V_11 -> V_120 , V_122 ) ;
if ( ! V_261 )
F_146 ( V_260 , V_276 ) ;
}
if ( F_147 ( V_14 ) && V_277 ) {
if ( V_14 -> V_278 & V_279 ) {
int V_280 = 0 ;
V_11 -> V_159 . V_281 = 1 ;
F_17 ( V_28 , V_11 , 0x7082 ,
L_69 ) ;
if ( V_277 == 1 )
V_280 = V_282 ;
F_148 ( V_11 -> V_83 ,
V_280 | V_283
| V_284
| V_285
| V_286
| V_287
| V_288 ) ;
F_149 ( V_11 -> V_83 , V_289 ) ;
} else
V_11 -> V_159 . V_281 = 0 ;
}
if ( F_150 ( V_11 -> V_83 , & V_260 -> V_89 ,
& V_14 -> V_58 -> V_89 ) ) {
F_17 ( V_28 , V_11 , 0x7083 ,
L_70 , V_11 -> V_186 ) ;
goto V_290;
}
F_151 ( V_11 -> V_83 ) = V_14 -> V_291 ;
F_152 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_196 ) ;
F_153 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_200 ) ;
F_154 ( V_11 -> V_83 ) =
F_154 ( V_82 -> V_83 ) ;
F_155 ( V_11 -> V_83 ) =
F_155 ( V_82 -> V_83 ) ;
F_156 ( V_260 , V_261 ) ;
if ( V_14 -> V_159 . V_292 ) {
V_265 = V_14 -> V_266 [ 1 ] ;
F_17 ( V_293 , V_11 , 0xc000 ,
L_71
L_72 ,
V_265 , V_11 -> V_186 , V_14 -> V_159 . V_292 ) ;
goto V_294;
} else if ( V_295 == 1 || ! V_14 -> V_296 )
goto V_294;
for ( V_37 = 0 ; V_37 < V_14 -> V_297 ; V_37 ++ ) {
if ( memcmp ( V_14 -> V_296 [ V_37 ] . V_200 , V_11 -> V_200 , 8 ) == 0
&& memcmp ( V_14 -> V_296 [ V_37 ] . V_196 , V_11 -> V_196 ,
8 ) == 0 ) {
V_262 = V_14 -> V_296 [ V_37 ] . V_298 ;
break;
}
}
if ( V_262 ) {
V_96 = F_157 ( V_14 , V_263 , V_11 -> V_186 , 0 , 0 ,
V_262 ) ;
if ( ! V_96 )
F_9 ( V_43 , V_11 , 0x7084 ,
L_73 ,
V_11 -> V_186 ) ;
else {
F_17 ( V_293 , V_11 , 0xc001 ,
L_74 ,
V_96 , V_262 , V_11 -> V_186 ) ;
F_17 ( V_28 , V_11 , 0x7085 ,
L_74 ,
V_96 , V_262 , V_11 -> V_186 ) ;
V_265 = V_14 -> V_266 [ V_96 ] ;
}
}
V_294:
V_11 -> V_265 = V_265 ;
return 0 ;
V_290:
F_158 ( V_11 ) ;
F_159 ( V_11 ) ;
F_160 ( V_11 -> V_83 ) ;
return V_267 ;
}
static int
F_161 ( struct V_260 * V_260 )
{
T_7 * V_11 = V_260 -> V_205 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_198 = V_11 -> V_186 ;
while ( F_83 ( V_299 , & V_11 -> V_30 ) ||
F_83 ( V_300 , & V_11 -> V_30 ) )
F_162 ( 1000 ) ;
F_158 ( V_11 ) ;
V_11 -> V_159 . V_301 = 1 ;
F_163 ( V_11 -> V_83 ) ;
F_164 ( V_11 -> V_83 ) ;
F_159 ( V_11 ) ;
if ( V_11 -> V_302 ) {
F_165 ( V_11 ) ;
F_17 ( V_28 , V_11 , 0x7086 ,
L_75 , V_11 -> V_186 ) ;
}
if ( V_303 & V_28 )
F_162 ( F_166 () % 10 ) ;
F_167 ( F_72 ( & V_11 -> V_304 ) ) ;
F_168 ( V_11 ) ;
F_169 ( & V_14 -> V_305 ) ;
V_14 -> V_306 -- ;
F_170 ( V_11 -> V_186 , V_14 -> V_307 ) ;
F_171 ( & V_14 -> V_305 ) ;
if ( V_11 -> V_265 -> V_198 && ! V_14 -> V_159 . V_292 ) {
if ( F_172 ( V_11 , V_11 -> V_265 ) != V_42 )
F_9 ( V_43 , V_11 , 0x7087 ,
L_76 ) ;
}
F_9 ( V_25 , V_11 , 0x7088 , L_77 , V_198 ) ;
F_160 ( V_11 -> V_83 ) ;
return 0 ;
}
static int
F_156 ( struct V_260 * V_260 , bool V_261 )
{
T_7 * V_11 = V_260 -> V_205 ;
if ( V_261 )
F_158 ( V_11 ) ;
else
F_173 ( V_11 ) ;
return 0 ;
}
void
F_174 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_169 = V_170 ;
F_151 ( V_11 -> V_83 ) = V_14 -> V_291 ;
F_152 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_196 ) ;
F_153 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_200 ) ;
F_154 ( V_11 -> V_83 ) = V_308 ;
F_175 ( V_11 -> V_83 ) = V_14 -> V_309 ;
F_176 ( V_11 -> V_83 ) = V_14 -> V_306 ;
if ( F_38 ( V_14 ) )
V_169 = V_181 ;
else if ( F_37 ( V_14 ) )
V_169 = V_179 | V_177 |
V_175 | V_173 ;
else if ( F_36 ( V_14 ) )
V_169 = V_177 | V_175 |
V_173 ;
else if ( F_177 ( V_14 ) )
V_169 = V_175 | V_173 ;
else
V_169 = V_173 ;
F_155 ( V_11 -> V_83 ) = V_169 ;
}
