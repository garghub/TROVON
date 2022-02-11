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
for ( V_41 = 0 ; V_41 < ( ( V_9 >> 2 ) - 1 ) ; V_41 ++ )
V_45 += F_28 ( * V_44 ++ ) ;
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
if ( V_14 -> V_51 != V_52 )
return 0 ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_53 ,
V_14 -> V_54 ) ;
}
static T_1
F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
if ( F_36 ( F_37 ( V_14 -> V_62 ) ) )
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
F_21 ( V_32 , V_11 , 0x7061 ,
L_10 ,
V_14 -> V_54 ) ;
F_38 ( V_14 -> V_53 ) ;
V_14 -> V_53 = NULL ;
break;
case 1 :
if ( V_14 -> V_51 != V_63 )
return - V_43 ;
V_14 -> V_64 = V_57 ;
V_14 -> V_54 = V_57 + V_58 > V_14 -> V_59 ?
V_14 -> V_59 - V_57 : V_58 ;
V_14 -> V_51 = V_52 ;
V_14 -> V_53 = F_39 ( V_14 -> V_54 ) ;
if ( V_14 -> V_53 == NULL ) {
F_9 ( V_47 , V_11 , 0x7062 ,
L_11
L_12 , V_14 -> V_54 ) ;
V_14 -> V_51 = V_63 ;
return - V_65 ;
}
if ( F_30 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x7063 ,
L_7 ) ;
return - V_48 ;
}
F_21 ( V_32 , V_11 , 0x7064 ,
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
else if ( F_40 ( V_14 ) || F_41 ( V_14 )
|| F_42 ( V_14 ) || F_43 ( V_14 ) )
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
V_14 -> V_53 = F_39 ( V_14 -> V_54 ) ;
if ( V_14 -> V_53 == NULL ) {
F_9 ( V_47 , V_11 , 0x7066 ,
L_15
L_16 , V_14 -> V_54 ) ;
V_14 -> V_51 = V_63 ;
return - V_65 ;
}
F_21 ( V_32 , V_11 , 0x7067 ,
L_17 ,
V_14 -> V_64 , V_14 -> V_54 ) ;
memset ( V_14 -> V_53 , 0 , V_14 -> V_54 ) ;
break;
case 3 :
if ( V_14 -> V_51 != V_55 )
return - V_43 ;
if ( F_30 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x7068 ,
L_18 ) ;
return - V_48 ;
}
F_21 ( V_32 , V_11 , 0x7069 ,
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
F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_36 ( F_37 ( V_14 -> V_62 ) ) )
return - V_48 ;
if ( ! F_24 ( V_35 ) )
return - V_43 ;
if ( F_25 ( V_14 ) )
V_14 -> V_36 -> V_37 ( V_11 , V_14 -> V_70 , V_14 -> V_71 << 2 ,
V_14 -> V_72 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_70 , V_14 -> V_72 ) ;
}
static T_1
F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_73 ;
if ( F_36 ( F_37 ( V_14 -> V_62 ) ) )
return 0 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 != V_14 -> V_72 ||
! V_14 -> V_36 -> V_42 )
return 0 ;
if ( F_30 ( V_11 ) != V_46 ) {
F_9 ( V_47 , V_11 , 0x706a ,
L_20 ) ;
return - V_48 ;
}
V_14 -> V_36 -> V_42 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_74 , V_9 ) ;
V_14 -> V_36 -> V_50 ( V_11 , ( T_6 * ) V_14 -> V_70 , V_14 -> V_74 , V_9 ) ;
if ( ! F_27 ( V_14 ) )
return - V_43 ;
V_73 = F_39 ( 256 ) ;
if ( ! V_73 ) {
F_9 ( V_47 , V_11 , 0x706b ,
L_21 ) ;
return - V_65 ;
}
V_14 -> V_36 -> V_75 ( V_11 , V_73 ) ;
F_38 ( V_73 ) ;
return V_9 ;
}
static T_1
F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_44 , V_76 , V_77 ;
int V_16 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 != V_78 * 2 )
return 0 ;
if ( V_14 -> V_79 )
goto V_80;
V_14 -> V_79 = F_47 ( V_14 -> V_81 , V_82 ,
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
V_16 = F_48 ( V_11 , V_14 -> V_83 , V_14 -> V_79 ,
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
F_49 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_86 = F_50 ( V_14 -> V_62 ) ;
int type ;
T_5 V_87 ;
T_6 * V_73 = NULL ;
if ( V_8 != 0 )
return - V_43 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_29 , V_11 , 0x706e ,
L_24 ) ;
F_51 ( V_11 -> V_88 ) ;
if ( F_13 ( V_14 ) ) {
V_14 -> V_89 . V_90 = 1 ;
F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
F_16 ( V_14 ) ;
} else if ( F_17 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_87 = F_52 ( V_14 ,
V_91 ) ;
F_53 ( V_14 , V_91 ,
( V_87 | V_92 ) ) ;
F_15 ( V_11 ) ;
F_19 ( V_14 ) ;
} else {
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_31 ( V_11 ) ;
}
F_32 ( V_11 ) ;
F_54 ( V_11 -> V_88 ) ;
break;
case 0x2025d :
if ( ! F_55 ( V_14 ) && ! F_56 ( V_14 ) )
return - V_93 ;
F_9 ( V_29 , V_11 , 0x706f ,
L_25 ) ;
if ( F_56 ( V_14 ) ) {
T_5 V_87 ;
F_57 ( V_11 , 0 ) ;
F_58 ( V_11 , & V_87 ) ;
V_87 |= V_94 ;
F_59 ( V_11 , V_87 ) ;
F_60 ( V_11 , V_95 ,
V_96 ) ;
F_61 ( V_11 , V_97 ) ;
F_62 ( V_11 , 0 ) ;
break;
} else {
F_30 ( V_11 ) ;
F_51 ( V_11 -> V_88 ) ;
if ( F_63 ( V_11 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7070 ,
L_26 ) ;
F_54 ( V_11 -> V_88 ) ;
break;
}
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_86 ) {
F_9 ( V_29 , V_11 , 0x7071 ,
L_27 ) ;
return - V_93 ;
}
F_9 ( V_29 , V_11 , 0x7072 ,
L_28 ) ;
F_22 ( V_98 , & V_11 -> V_34 ) ;
F_31 ( V_11 ) ;
F_64 ( V_11 ) ;
break;
case 0x2025f :
if ( ! F_65 ( V_14 ) )
return - V_93 ;
F_9 ( V_29 , V_11 , 0x70bc ,
L_29 ) ;
F_57 ( V_11 , 0 ) ;
F_58 ( V_11 , & V_87 ) ;
V_87 |= V_99 ;
F_59 ( V_11 , V_87 ) ;
F_62 ( V_11 , 0 ) ;
break;
case 0x20260 :
if ( ! F_65 ( V_14 ) )
return - V_93 ;
F_9 ( V_29 , V_11 , 0x70bd ,
L_30 ) ;
F_57 ( V_11 , 0 ) ;
F_58 ( V_11 , & V_87 ) ;
V_87 &= ~ V_99 ;
F_59 ( V_11 , V_87 ) ;
F_62 ( V_11 , 0 ) ;
break;
case 0x20261 :
F_21 ( V_32 , V_11 , 0x70e0 ,
L_31 ) ;
V_73 = F_39 ( 256 ) ;
if ( ! V_73 ) {
F_9 ( V_47 , V_11 , 0x70e1 ,
L_21 ) ;
return - V_65 ;
}
V_14 -> V_36 -> V_75 ( V_11 , V_73 ) ;
F_38 ( V_73 ) ;
break;
}
return V_9 ;
}
static T_1
F_66 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_4 V_100 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 > V_101 )
return 0 ;
if ( V_14 -> V_102 )
goto V_80;
V_14 -> V_102 = F_67 ( & V_14 -> V_62 -> V_103 , V_101 ,
& V_14 -> V_104 , V_82 ) ;
if ( ! V_14 -> V_102 ) {
F_9 ( V_47 , V_11 , 0x7076 ,
L_32 ) ;
return 0 ;
}
V_80:
V_100 = 0 ;
memset ( V_14 -> V_102 , 0 , V_101 ) ;
V_16 = F_68 ( V_11 , V_14 -> V_104 ,
V_101 , & V_100 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7077 ,
L_33 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_100 > V_9 ? V_9 : V_100 ;
memcpy ( V_7 , V_14 -> V_102 , V_9 ) ;
return V_9 ;
}
static T_1
F_69 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_4 V_100 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 > V_105 )
return 0 ;
if ( V_14 -> V_106 )
goto V_80;
V_14 -> V_106 = F_67 ( & V_14 -> V_62 -> V_103 , V_105 ,
& V_14 -> V_107 , V_82 ) ;
if ( ! V_14 -> V_106 ) {
F_9 ( V_47 , V_11 , 0x7078 ,
L_34 ) ;
return - V_65 ;
}
V_80:
V_100 = 0 ;
memset ( V_14 -> V_106 , 0 , V_105 ) ;
V_16 = F_70 ( V_11 , V_14 -> V_107 ,
V_105 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7079 ,
L_35 , V_16 ) ;
return - V_85 ;
}
memcpy ( V_7 , V_14 -> V_106 , V_9 ) ;
return V_9 ;
}
void
F_71 ( T_7 * V_11 )
{
struct V_108 * V_88 = V_11 -> V_88 ;
struct V_109 * V_44 ;
int V_110 ;
for ( V_44 = V_111 ; V_44 -> V_112 ; V_44 ++ ) {
if ( V_44 -> V_113 && ! F_27 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_113 == 2 && ! F_41 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_113 == 3 && ! ( F_42 ( V_11 -> V_15 ) ) )
continue;
V_110 = F_72 ( & V_88 -> V_114 . V_4 ,
V_44 -> V_115 ) ;
if ( V_110 )
F_9 ( V_47 , V_11 , 0x00f3 ,
L_36 ,
V_44 -> V_112 , V_110 ) ;
else
F_21 ( V_116 , V_11 , 0x00f4 ,
L_37 ,
V_44 -> V_112 ) ;
}
}
void
F_73 ( T_7 * V_11 , bool V_117 )
{
struct V_108 * V_88 = V_11 -> V_88 ;
struct V_109 * V_44 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_44 = V_111 ; V_44 -> V_112 ; V_44 ++ ) {
if ( V_44 -> V_113 && ! F_27 ( V_14 ) )
continue;
if ( V_44 -> V_113 == 2 && ! F_41 ( V_14 ) )
continue;
if ( V_44 -> V_113 == 3 && ! ( F_42 ( V_11 -> V_15 ) ) )
continue;
F_74 ( & V_88 -> V_114 . V_4 ,
V_44 -> V_115 ) ;
}
if ( V_117 && V_14 -> V_118 == 1 )
V_14 -> V_36 -> V_119 ( V_11 ) ;
}
static T_1
F_75 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
return F_76 ( V_7 , V_121 , L_38 , V_122 ) ;
}
static T_1
F_77 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_123 [ 128 ] ;
return F_76 ( V_7 , V_121 , L_38 ,
V_14 -> V_36 -> V_124 ( V_11 , V_123 ) ) ;
}
static T_1
F_79 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_125 ;
if ( F_80 ( V_11 -> V_15 ) ) {
return F_76 ( V_7 , V_121 , L_38 ,
V_11 -> V_15 -> V_126 . V_127 ) ;
} else if ( F_27 ( V_14 ) ) {
F_81 ( V_11 , L_39 , V_7 , V_121 - 1 ) ;
return strlen ( strcat ( V_7 , L_40 ) ) ;
}
V_125 = ( ( V_14 -> V_128 & 0x1f ) << 16 ) | ( V_14 -> V_129 << 8 ) | V_14 -> V_130 ;
return F_76 ( V_7 , V_121 , L_41 , 'A' + V_125 / 100000 ,
V_125 % 100000 ) ;
}
static T_1
F_82 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
return F_76 ( V_7 , V_121 , L_42 , V_11 -> V_15 -> V_62 -> V_12 ) ;
}
static T_1
F_83 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_80 ( V_11 -> V_15 ) )
return F_76 ( V_7 , V_121 , L_38 ,
V_11 -> V_15 -> V_126 . V_131 ) ;
return F_76 ( V_7 , V_121 , L_43 ,
V_14 -> V_132 [ 0 ] , V_14 -> V_132 [ 1 ] , V_14 -> V_132 [ 2 ] ,
V_14 -> V_132 [ 3 ] ) ;
}
static T_1
F_84 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
return F_76 ( V_7 , V_121 , L_38 , V_11 -> V_15 -> V_133 ) ;
}
static T_1
F_85 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
return F_76 ( V_7 , V_121 , L_38 ,
V_11 -> V_15 -> V_134 ? V_11 -> V_15 -> V_134 : L_44 ) ;
}
static T_1
F_86 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
char V_135 [ 30 ] ;
return F_76 ( V_7 , V_121 , L_38 ,
V_11 -> V_15 -> V_36 -> V_136 ( V_11 , V_135 ) ) ;
}
static T_1
F_87 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_137 = 0 ;
if ( F_88 ( & V_11 -> V_138 ) == V_139 ||
F_88 ( & V_11 -> V_138 ) == V_140 ||
V_11 -> V_141 & V_142 )
V_137 = F_76 ( V_7 , V_121 , L_45 ) ;
else if ( F_88 ( & V_11 -> V_138 ) != V_143 ||
F_89 ( V_11 ) )
V_137 = F_76 ( V_7 , V_121 , L_46 ) ;
else {
V_137 = F_76 ( V_7 , V_121 , L_47 ) ;
switch ( V_14 -> V_144 ) {
case V_145 :
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_48 ) ;
break;
case V_146 :
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_49 ) ;
break;
case V_147 :
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 ,
L_50 ) ;
break;
case V_148 :
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_51 ) ;
break;
default:
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_48 ) ;
break;
}
}
return V_137 ;
}
static T_1
F_90 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
int V_137 = 0 ;
switch ( V_11 -> V_15 -> V_149 ) {
case V_150 :
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_52 ) ;
break;
case V_151 :
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_53 ) ;
break;
}
return V_137 ;
}
static T_1
F_91 ( struct V_12 * V_103 , struct V_120 * V_115 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_60 = 0 ;
T_4 V_149 ;
if ( ! F_92 ( V_14 ) )
return - V_152 ;
if ( sscanf ( V_7 , L_54 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 )
V_149 = V_150 ;
else
V_149 = V_151 ;
if ( V_149 != V_151 || V_14 -> V_149 != V_151 ) {
V_14 -> V_149 = V_149 ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_93 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
return F_76 ( V_7 , V_121 , L_55 , V_11 -> V_15 -> V_153 * 100 ) ;
}
static T_1
F_94 ( struct V_12 * V_103 , struct V_120 * V_115 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
int V_60 = 0 ;
T_4 V_153 ;
if ( sscanf ( V_7 , L_54 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 > 25500 || V_60 < 100 )
return - V_56 ;
V_153 = ( T_4 ) ( V_60 / 100 ) ;
V_11 -> V_15 -> V_153 = V_153 ;
return strlen ( V_7 ) ;
}
static T_1
F_95 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
int V_137 = 0 ;
if ( V_11 -> V_15 -> V_118 )
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_56 ) ;
else
V_137 += F_76 ( V_7 + V_137 , V_121 - V_137 , L_53 ) ;
return V_137 ;
}
static T_1
F_96 ( struct V_12 * V_103 , struct V_120 * V_115 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_60 = 0 ;
int V_16 ;
if ( F_97 ( V_14 ) || F_98 ( V_14 ) )
return - V_93 ;
if ( F_99 ( V_154 , & V_11 -> V_34 ) ) {
F_9 ( V_47 , V_11 , 0x707a ,
L_57 ) ;
return - V_155 ;
}
if ( sscanf ( V_7 , L_54 , & V_60 ) != 1 )
return - V_43 ;
if ( V_60 )
V_16 = V_14 -> V_36 -> V_156 ( V_11 ) ;
else
V_16 = V_14 -> V_36 -> V_119 ( V_11 ) ;
if ( V_16 != V_46 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_100 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_76 ( V_7 , V_121 , L_58 , V_14 -> V_157 [ 1 ] ,
V_14 -> V_157 [ 0 ] ) ;
}
static T_1
F_101 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_76 ( V_7 , V_121 , L_58 , V_14 -> V_158 [ 1 ] ,
V_14 -> V_158 [ 0 ] ) ;
}
static T_1
F_102 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_76 ( V_7 , V_121 , L_58 , V_14 -> V_159 [ 1 ] ,
V_14 -> V_159 [ 0 ] ) ;
}
static T_1
F_103 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_76 ( V_7 , V_121 , L_59 ,
V_14 -> V_160 [ 0 ] , V_14 -> V_160 [ 1 ] , V_14 -> V_160 [ 2 ] ,
V_14 -> V_160 [ 3 ] ) ;
}
static T_1
F_104 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_55 ( V_14 ) && ! F_56 ( V_14 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
return F_76 ( V_7 , V_121 , L_60 ,
V_14 -> V_161 [ 0 ] , V_14 -> V_161 [ 1 ] ,
V_14 -> V_161 [ 2 ] , V_14 -> V_161 [ 3 ] ) ;
}
static T_1
F_105 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
return F_76 ( V_7 , V_121 , L_61 ,
V_11 -> V_162 . V_163 ) ;
}
static T_1
F_106 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
int V_16 = V_46 ;
T_4 V_164 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_107 ( V_14 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
if ( V_14 -> V_165 -> V_166 == 0 )
V_16 = F_108 ( V_11 , V_164 ) ;
if ( ( V_16 == V_46 ) && ( V_164 [ 0 ] == 0 ) )
return F_76 ( V_7 , V_121 , L_62 ,
( T_5 ) V_14 -> V_165 -> V_166 ) ;
return F_76 ( V_7 , V_121 , L_40 ) ;
}
static T_1
F_109 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_55 ( V_14 ) && ! F_65 ( V_14 ) && ! F_17 ( V_14 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
return F_76 ( V_7 , V_121 , L_63 ,
V_14 -> V_167 [ 0 ] , V_14 -> V_167 [ 1 ] , V_14 -> V_167 [ 2 ] ,
V_14 -> V_168 ) ;
}
static T_1
F_110 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_55 ( V_14 ) && ! F_65 ( V_14 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
return F_76 ( V_7 , V_121 , L_64 ,
V_14 -> V_169 [ 0 ] , V_14 -> V_169 [ 1 ] , V_14 -> V_169 [ 2 ] ) ;
}
static T_1
F_111 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_76 ( V_7 , V_121 , L_65 , V_14 -> V_170 ) ;
}
static T_1
F_112 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
if ( ! F_42 ( V_11 -> V_15 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
return F_76 ( V_7 , V_121 , L_61 , V_11 -> V_171 ) ;
}
static T_1
F_113 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
if ( ! F_42 ( V_11 -> V_15 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
return F_76 ( V_7 , V_121 , L_66 , V_11 -> V_172 ) ;
}
static T_1
F_114 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
return F_76 ( V_7 , V_121 , L_61 , V_11 -> V_15 -> V_173 ) ;
}
static T_1
F_115 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
T_4 V_174 = 0 ;
if ( F_89 ( V_11 ) ) {
F_9 ( V_47 , V_11 , 0x70dc , L_67 ) ;
goto V_175;
}
if ( V_11 -> V_15 -> V_89 . V_176 ) {
F_9 ( V_47 , V_11 , 0x70dd , L_68 ) ;
goto V_175;
}
if ( F_116 ( V_11 , & V_174 ) == V_46 )
return F_76 ( V_7 , V_121 , L_61 , V_174 ) ;
V_175:
return F_76 ( V_7 , V_121 , L_40 ) ;
}
static T_1
F_117 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
int V_16 = V_177 ;
T_4 V_178 [ 5 ] ;
T_5 V_179 ;
if ( F_80 ( V_11 -> V_15 ) ) {
V_179 = F_118 ( V_103 , V_115 , V_7 ) ;
return F_76 ( V_7 , V_121 , L_65 , V_179 ) ;
}
if ( F_89 ( V_11 ) )
F_9 ( V_47 , V_11 , 0x707c ,
L_67 ) ;
else if ( ! V_11 -> V_15 -> V_89 . V_176 )
V_16 = F_119 ( V_11 , V_178 ) ;
if ( V_16 != V_46 )
memset ( V_178 , - 1 , sizeof( V_178 ) ) ;
return F_76 ( V_7 , V_121 , L_69 , V_178 [ 0 ] ,
V_178 [ 1 ] , V_178 [ 2 ] , V_178 [ 3 ] , V_178 [ 4 ] ) ;
}
static T_1
F_120 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
if ( ! F_121 ( V_11 -> V_15 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
return F_76 ( V_7 , V_121 , L_70 , V_11 -> V_180 . V_181 ) ;
}
static T_1
F_122 ( struct V_12 * V_103 ,
struct V_120 * V_115 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
if ( ! F_121 ( V_11 -> V_15 ) )
return F_76 ( V_7 , V_121 , L_40 ) ;
return F_76 ( V_7 , V_121 , L_70 ,
V_11 -> V_180 . V_182 >> 20 ) ;
}
static T_1
F_123 ( struct V_12 * V_103 , struct V_120 * V_115 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_78 ( V_103 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_58 ;
if ( ! V_14 -> V_31 )
V_58 = 0 ;
else if ( F_13 ( V_14 ) )
V_58 = V_14 -> V_19 + V_14 -> V_22 ;
else
V_58 = V_14 -> V_27 ;
return F_76 ( V_7 , V_121 , L_61 , V_58 ) ;
}
static void
F_124 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
F_125 ( V_183 ) = V_11 -> V_184 . V_185 . V_186 << 16 |
V_11 -> V_184 . V_185 . V_187 << 8 | V_11 -> V_184 . V_185 . V_188 ;
}
static void
F_126 ( struct V_108 * V_183 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_183 ) ) ) -> V_15 ;
T_8 V_189 = V_190 ;
if ( F_80 ( V_14 ) ) {
F_127 ( V_183 ) ;
return;
}
switch ( V_14 -> V_191 ) {
case V_192 :
V_189 = V_193 ;
break;
case V_194 :
V_189 = V_195 ;
break;
case V_196 :
V_189 = V_197 ;
break;
case V_198 :
V_189 = V_199 ;
break;
case V_200 :
V_189 = V_201 ;
break;
case V_202 :
V_189 = V_203 ;
break;
}
F_128 ( V_183 ) = V_189 ;
}
static void
F_129 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
T_5 V_204 = V_205 ;
if ( V_11 -> V_206 ) {
F_130 ( V_183 ) = V_207 ;
return;
}
switch ( V_11 -> V_15 -> V_144 ) {
case V_145 :
V_204 = V_208 ;
break;
case V_146 :
V_204 = V_209 ;
break;
case V_147 :
V_204 = V_210 ;
break;
case V_148 :
V_204 = V_211 ;
break;
}
F_130 ( V_183 ) = V_204 ;
}
static void
F_131 ( struct V_212 * V_213 )
{
struct V_108 * V_88 = F_3 ( V_213 -> V_103 . V_214 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_215 ;
T_10 V_216 = 0 ;
F_132 (fcport, &vha->vp_fcports, list) {
if ( V_215 -> V_217 &&
V_213 -> V_218 == V_215 -> V_217 -> V_219 ) {
V_216 = F_133 ( V_215 -> V_216 ) ;
break;
}
}
F_134 ( V_213 ) = V_216 ;
}
static void
F_135 ( struct V_212 * V_213 )
{
struct V_108 * V_88 = F_3 ( V_213 -> V_103 . V_214 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_215 ;
T_10 V_220 = 0 ;
F_132 (fcport, &vha->vp_fcports, list) {
if ( V_215 -> V_217 &&
V_213 -> V_218 == V_215 -> V_217 -> V_219 ) {
V_220 = F_133 ( V_215 -> V_220 ) ;
break;
}
}
F_136 ( V_213 ) = V_220 ;
}
static void
F_137 ( struct V_212 * V_213 )
{
struct V_108 * V_88 = F_3 ( V_213 -> V_103 . V_214 ) ;
T_7 * V_11 = F_2 ( V_88 ) ;
T_9 * V_215 ;
T_5 V_221 = ~ 0U ;
F_132 (fcport, &vha->vp_fcports, list) {
if ( V_215 -> V_217 &&
V_213 -> V_218 == V_215 -> V_217 -> V_219 ) {
V_221 = V_215 -> V_184 . V_185 . V_186 << 16 |
V_215 -> V_184 . V_185 . V_187 << 8 | V_215 -> V_184 . V_185 . V_188 ;
break;
}
}
F_138 ( V_213 ) = V_221 ;
}
static void
F_139 ( struct V_222 * V_217 , T_5 V_223 )
{
if ( V_223 )
V_217 -> V_224 = V_223 ;
else
V_217 -> V_224 = 1 ;
}
static void
F_140 ( struct V_222 * V_217 )
{
struct V_108 * V_88 = F_141 ( V_217 ) ;
T_9 * V_215 = * ( T_9 * * ) V_217 -> V_225 ;
unsigned long V_89 ;
if ( ! V_215 )
return;
F_142 ( V_215 , V_226 ) ;
F_143 ( V_88 -> V_227 , V_89 ) ;
V_215 -> V_217 = V_215 -> V_228 = NULL ;
* ( ( T_9 * * ) V_217 -> V_225 ) = NULL ;
F_144 ( V_88 -> V_227 , V_89 ) ;
if ( F_99 ( V_154 , & V_215 -> V_11 -> V_34 ) )
return;
if ( F_36 ( F_37 ( V_215 -> V_11 -> V_15 -> V_62 ) ) ) {
F_145 ( V_215 -> V_11 , V_229 << 16 ) ;
return;
}
}
static void
F_146 ( struct V_222 * V_217 )
{
T_9 * V_215 = * ( T_9 * * ) V_217 -> V_225 ;
if ( ! V_215 )
return;
if ( F_99 ( V_154 , & V_215 -> V_11 -> V_34 ) )
return;
if ( F_36 ( F_37 ( V_215 -> V_11 -> V_15 -> V_62 ) ) ) {
F_145 ( V_215 -> V_11 , V_229 << 16 ) ;
return;
}
if ( V_215 -> V_230 != V_231 ) {
if ( F_27 ( V_215 -> V_11 -> V_15 ) )
V_215 -> V_11 -> V_15 -> V_36 -> V_232 ( V_215 -> V_11 ,
V_215 -> V_230 , V_215 -> V_184 . V_185 . V_186 ,
V_215 -> V_184 . V_185 . V_187 , V_215 -> V_184 . V_185 . V_188 ) ;
else
F_147 ( V_215 -> V_11 , V_215 ) ;
}
}
static int
F_148 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
if ( F_80 ( V_11 -> V_15 ) )
return 0 ;
F_149 ( V_11 ) ;
return 0 ;
}
static struct V_233 *
F_150 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_86 = F_50 ( V_14 -> V_62 ) ;
int V_16 ;
struct V_234 * V_235 ;
T_11 V_236 ;
struct V_233 * V_237 ;
V_237 = & V_11 -> V_238 ;
memset ( V_237 , - 1 , sizeof( struct V_233 ) ) ;
if ( F_80 ( V_11 -> V_15 ) )
goto V_175;
if ( F_99 ( V_239 , & V_11 -> V_34 ) )
goto V_175;
if ( F_36 ( F_37 ( V_14 -> V_62 ) ) )
goto V_175;
if ( F_89 ( V_11 ) )
goto V_175;
V_235 = F_47 ( V_14 -> V_81 , V_82 , & V_236 ) ;
if ( V_235 == NULL ) {
F_9 ( V_47 , V_11 , 0x707d ,
L_71 ) ;
goto V_175;
}
memset ( V_235 , 0 , V_240 ) ;
V_16 = V_177 ;
if ( F_27 ( V_14 ) ) {
V_16 = F_151 ( V_86 , V_235 , V_236 ) ;
} else if ( F_88 ( & V_86 -> V_138 ) == V_143 &&
! V_14 -> V_241 ) {
V_16 = F_152 ( V_86 , V_86 -> V_230 ,
V_235 , V_236 ) ;
}
if ( V_16 != V_46 )
goto V_242;
V_237 -> V_243 = V_235 -> V_244 ;
V_237 -> V_245 = V_235 -> V_246 ;
V_237 -> V_247 = V_235 -> V_248 ;
V_237 -> V_249 = V_235 -> V_250 ;
V_237 -> V_251 = V_235 -> V_252 ;
V_237 -> V_253 = V_235 -> V_254 ;
if ( F_27 ( V_14 ) ) {
V_237 -> V_255 = V_235 -> V_256 ;
V_237 -> V_257 = V_235 -> V_257 ;
V_237 -> V_258 = V_235 -> V_258 ;
V_237 -> V_259 = V_235 -> V_260 ;
V_237 -> V_261 = V_235 -> V_262 ;
V_237 -> V_263 =
V_235 -> V_264 + V_235 -> V_260 ;
V_237 -> V_265 = V_11 -> V_162 . V_266 ;
V_237 -> V_267 = V_11 -> V_162 . V_268 ;
}
V_237 -> V_269 = V_11 -> V_162 . V_270 ;
V_237 -> V_271 = V_11 -> V_162 . V_272 ;
V_237 -> V_273 = V_11 -> V_162 . V_274 ;
V_237 -> V_275 = V_11 -> V_162 . V_266 >> 20 ;
V_237 -> V_276 = V_11 -> V_162 . V_268 >> 20 ;
V_237 -> V_277 =
F_153 () - V_11 -> V_162 . V_278 ;
F_154 ( V_237 -> V_277 , V_279 ) ;
V_242:
F_155 ( V_14 -> V_81 , V_235 , V_236 ) ;
V_175:
return V_237 ;
}
static void
F_156 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
memset ( & V_11 -> V_238 , 0 , sizeof( V_11 -> V_238 ) ) ;
V_11 -> V_162 . V_278 = F_153 () ;
}
static void
F_157 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
F_158 ( V_11 , F_159 ( V_183 ) ) ;
}
static void
F_160 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
F_22 ( V_280 , & V_11 -> V_34 ) ;
}
static void
F_161 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
T_6 V_216 [ V_281 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_282 = F_133 ( V_216 ) ;
if ( V_11 -> V_141 & V_283 )
V_282 = F_133 ( V_11 -> V_284 ) ;
F_162 ( V_183 ) = V_282 ;
}
static void
F_163 ( struct V_108 * V_183 )
{
T_7 * V_11 = F_2 ( V_183 ) ;
struct V_10 * V_86 = F_50 ( V_11 -> V_15 -> V_62 ) ;
if ( ! V_86 -> V_89 . V_285 ) {
F_164 ( V_183 ) = V_286 ;
return;
}
switch ( F_88 ( & V_86 -> V_138 ) ) {
case V_287 :
F_164 ( V_183 ) = V_288 ;
break;
case V_139 :
if ( F_99 ( V_289 , & V_86 -> V_34 ) )
F_164 ( V_183 ) = V_288 ;
else
F_164 ( V_183 ) = V_290 ;
break;
case V_140 :
F_164 ( V_183 ) = V_290 ;
break;
case V_143 :
F_164 ( V_183 ) = V_291 ;
break;
default:
F_164 ( V_183 ) = V_292 ;
break;
}
}
static int
F_165 ( struct V_293 * V_293 , bool V_294 )
{
int V_110 = 0 ;
T_6 V_295 = 0 ;
T_7 * V_86 = F_2 ( V_293 -> V_183 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_86 -> V_15 ;
T_4 V_296 = 0 ;
int V_41 ;
struct V_297 * V_298 = V_14 -> V_299 [ 0 ] ;
V_110 = F_166 ( V_293 ) ;
if ( V_110 ) {
F_9 ( V_47 , V_11 , 0x707e ,
L_72 , V_110 ) ;
return ( V_110 ) ;
}
V_11 = F_167 ( V_293 ) ;
if ( V_11 == NULL ) {
F_9 ( V_47 , V_11 , 0x707f , L_73 ) ;
return V_300 ;
}
if ( V_294 ) {
F_168 ( & V_11 -> V_301 , V_302 ) ;
F_169 ( V_293 , V_303 ) ;
} else
F_168 ( & V_11 -> V_301 , V_304 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_74 , V_11 -> V_206 ) ;
F_168 ( & V_11 -> V_138 , V_139 ) ;
V_11 -> V_305 = V_306 ;
V_11 -> V_307 = V_308 ;
if ( F_88 ( & V_86 -> V_138 ) == V_139 ||
F_88 ( & V_86 -> V_138 ) == V_140 ) {
F_21 ( V_32 , V_11 , 0x7081 ,
L_75 ) ;
F_168 ( & V_11 -> V_138 , V_140 ) ;
if ( ! V_294 )
F_169 ( V_293 , V_309 ) ;
}
if ( F_170 ( V_14 ) && V_310 ) {
if ( V_14 -> V_311 & V_312 ) {
int V_313 = 0 , V_314 ;
V_11 -> V_89 . V_315 = 1 ;
F_21 ( V_32 , V_11 , 0x7082 ,
L_76 ) ;
if ( V_310 == 1 )
V_313 = V_316 ;
F_171 ( V_11 -> V_88 ,
V_313 | V_317
| V_318
| V_319
| V_320
| V_321
| V_322 ) ;
V_314 = V_323 ;
if ( F_172 ( V_14 ) &&
( V_310 > 1 || F_173 ( V_14 ) ) )
V_314 |= V_324 ;
F_174 ( V_11 -> V_88 , V_314 ) ;
} else
V_11 -> V_89 . V_315 = 0 ;
}
if ( F_175 ( V_11 -> V_88 , & V_293 -> V_103 ,
& V_14 -> V_62 -> V_103 ) ) {
F_21 ( V_32 , V_11 , 0x7083 ,
L_77 , V_11 -> V_206 ) ;
goto V_325;
}
F_176 ( V_11 -> V_88 ) = V_14 -> V_326 ;
F_177 ( V_11 -> V_88 ) = F_133 ( V_11 -> V_216 ) ;
F_178 ( V_11 -> V_88 ) = F_133 ( V_11 -> V_220 ) ;
F_179 ( V_11 -> V_88 ) =
F_179 ( V_86 -> V_88 ) ;
F_180 ( V_11 -> V_88 ) =
F_180 ( V_86 -> V_88 ) ;
F_181 ( V_11 , V_14 ) ;
F_182 ( V_293 , V_294 ) ;
if ( V_14 -> V_89 . V_327 ) {
V_298 = V_14 -> V_299 [ 1 ] ;
F_21 ( V_328 , V_11 , 0xc000 ,
L_78
L_79 ,
V_298 , V_11 -> V_206 , V_14 -> V_89 . V_327 ) ;
goto V_329;
} else if ( V_330 == 1 || ! V_14 -> V_331 )
goto V_329;
for ( V_41 = 0 ; V_41 < V_14 -> V_332 ; V_41 ++ ) {
if ( memcmp ( V_14 -> V_331 [ V_41 ] . V_220 , V_11 -> V_220 , 8 ) == 0
&& memcmp ( V_14 -> V_331 [ V_41 ] . V_216 , V_11 -> V_216 ,
8 ) == 0 ) {
V_295 = V_14 -> V_331 [ V_41 ] . V_333 ;
break;
}
}
if ( V_295 ) {
V_110 = F_183 ( V_14 , V_296 , V_11 -> V_206 , 0 , 0 ,
V_295 ) ;
if ( ! V_110 )
F_9 ( V_47 , V_11 , 0x7084 ,
L_80 ,
V_11 -> V_206 ) ;
else {
F_21 ( V_328 , V_11 , 0xc001 ,
L_81 ,
V_110 , V_295 , V_11 -> V_206 ) ;
F_21 ( V_32 , V_11 , 0x7085 ,
L_81 ,
V_110 , V_295 , V_11 -> V_206 ) ;
V_298 = V_14 -> V_299 [ V_110 ] ;
}
}
V_329:
V_11 -> V_298 = V_298 ;
return 0 ;
V_325:
F_184 ( V_11 ) ;
F_185 ( V_11 ) ;
F_186 ( V_11 -> V_88 ) ;
return V_300 ;
}
static int
F_187 ( struct V_293 * V_293 )
{
T_7 * V_11 = V_293 -> V_225 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_218 = V_11 -> V_206 ;
while ( F_99 ( V_334 , & V_11 -> V_34 ) ||
F_99 ( V_335 , & V_11 -> V_34 ) )
F_188 ( 1000 ) ;
F_184 ( V_11 ) ;
V_11 -> V_89 . V_336 = 1 ;
F_189 ( V_14 , V_11 ) ;
F_190 ( V_11 -> V_88 ) ;
F_191 ( V_11 -> V_88 ) ;
F_185 ( V_11 ) ;
if ( V_11 -> V_337 ) {
F_192 ( V_11 ) ;
F_21 ( V_32 , V_11 , 0x7086 ,
L_82 , V_11 -> V_206 ) ;
}
F_193 ( F_88 ( & V_11 -> V_338 ) ) ;
F_194 ( V_11 ) ;
F_195 ( & V_14 -> V_339 ) ;
V_14 -> V_340 -- ;
F_196 ( V_11 -> V_206 , V_14 -> V_341 ) ;
F_197 ( & V_14 -> V_339 ) ;
if ( V_11 -> V_298 -> V_218 && ! V_14 -> V_89 . V_327 ) {
if ( F_198 ( V_11 , V_11 -> V_298 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7087 ,
L_83 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_84 , V_218 ) ;
F_186 ( V_11 -> V_88 ) ;
return 0 ;
}
static int
F_182 ( struct V_293 * V_293 , bool V_294 )
{
T_7 * V_11 = V_293 -> V_225 ;
if ( V_294 )
F_184 ( V_11 ) ;
else
F_199 ( V_11 ) ;
return 0 ;
}
void
F_200 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_189 = V_190 ;
F_176 ( V_11 -> V_88 ) = V_14 -> V_326 ;
F_177 ( V_11 -> V_88 ) = F_133 ( V_11 -> V_216 ) ;
F_178 ( V_11 -> V_88 ) = F_133 ( V_11 -> V_220 ) ;
F_179 ( V_11 -> V_88 ) = V_14 -> V_342 . V_343 ?
( V_344 | V_345 ) : V_345 ;
F_201 ( V_11 -> V_88 ) = V_14 -> V_346 ;
F_202 ( V_11 -> V_88 ) = V_14 -> V_340 ;
if ( F_42 ( V_14 ) )
V_189 = V_201 ;
else if ( F_43 ( V_14 ) )
V_189 = V_203 | V_199 |
V_197 ;
else if ( F_41 ( V_14 ) )
V_189 = V_199 | V_197 |
V_195 | V_193 ;
else if ( F_40 ( V_14 ) )
V_189 = V_197 | V_195 |
V_193 ;
else if ( F_203 ( V_14 ) )
V_189 = V_195 | V_193 ;
else if ( F_80 ( V_14 ) )
V_189 = V_199 | V_197 |
V_195 | V_193 ;
else
V_189 = V_193 ;
F_180 ( V_11 -> V_88 ) = V_189 ;
}
