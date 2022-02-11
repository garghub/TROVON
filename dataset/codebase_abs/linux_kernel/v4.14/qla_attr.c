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
if ( V_60 > V_14 -> V_61 - V_59 )
V_60 = V_14 -> V_61 - V_59 ;
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
V_14 -> V_56 = V_59 + V_60 ;
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
V_14 -> V_56 = V_59 + V_60 ;
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
int V_16 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 < V_81 )
return 0 ;
if ( F_51 ( V_11 ) )
return 0 ;
V_16 = F_52 ( V_11 , V_7 , V_9 ) ;
if ( V_16 )
return - V_82 ;
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
struct V_10 * V_83 = F_54 ( V_14 -> V_64 ) ;
int type ;
T_5 V_84 ;
T_6 * V_78 = NULL ;
if ( V_8 != 0 )
return - V_43 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_29 , V_11 , 0x706e ,
L_22 ) ;
F_55 ( V_11 -> V_85 ) ;
if ( F_13 ( V_14 ) ) {
V_14 -> V_86 . V_87 = 1 ;
F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
F_16 ( V_14 ) ;
} else if ( F_17 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_84 = F_56 ( V_14 ,
V_88 ) ;
F_57 ( V_14 , V_88 ,
( V_84 | V_89 ) ) ;
F_15 ( V_11 ) ;
F_19 ( V_14 ) ;
} else {
F_22 ( V_33 , & V_11 -> V_34 ) ;
F_31 ( V_11 ) ;
}
F_32 ( V_11 ) ;
F_58 ( V_11 -> V_85 ) ;
break;
case 0x2025d :
if ( ! F_59 ( V_14 ) && ! F_60 ( V_14 ) )
return - V_90 ;
F_9 ( V_29 , V_11 , 0x706f ,
L_23 ) ;
if ( F_60 ( V_14 ) || F_46 ( V_14 ) ) {
T_5 V_84 ;
F_61 ( V_11 , 0 ) ;
F_62 ( V_11 , & V_84 ) ;
V_84 |= V_91 ;
F_63 ( V_11 , V_84 ) ;
F_64 ( V_11 , V_92 ,
V_93 ) ;
F_65 ( V_11 , V_94 ) ;
F_66 ( V_11 , 0 ) ;
break;
} else {
F_30 ( V_11 ) ;
F_55 ( V_11 -> V_85 ) ;
if ( F_67 ( V_11 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7070 ,
L_24 ) ;
F_58 ( V_11 -> V_85 ) ;
break;
}
case 0x2025e :
if ( ! F_5 ( V_14 ) || V_11 != V_83 ) {
F_9 ( V_29 , V_11 , 0x7071 ,
L_25 ) ;
return - V_90 ;
}
F_9 ( V_29 , V_11 , 0x7072 ,
L_26 ) ;
F_22 ( V_95 , & V_11 -> V_34 ) ;
F_31 ( V_11 ) ;
F_68 ( V_11 ) ;
break;
case 0x2025f :
if ( ! F_69 ( V_14 ) )
return - V_90 ;
F_9 ( V_29 , V_11 , 0x70bc ,
L_27 ) ;
F_61 ( V_11 , 0 ) ;
F_62 ( V_11 , & V_84 ) ;
V_84 |= V_96 ;
F_63 ( V_11 , V_84 ) ;
F_66 ( V_11 , 0 ) ;
break;
case 0x20260 :
if ( ! F_69 ( V_14 ) )
return - V_90 ;
F_9 ( V_29 , V_11 , 0x70bd ,
L_28 ) ;
F_61 ( V_11 , 0 ) ;
F_62 ( V_11 , & V_84 ) ;
V_84 &= ~ V_96 ;
F_63 ( V_11 , V_84 ) ;
F_66 ( V_11 , 0 ) ;
break;
case 0x20261 :
F_21 ( V_32 , V_11 , 0x70e0 ,
L_29 ) ;
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
T_7 V_97 ;
type = F_8 ( V_7 , NULL , 10 ) ;
V_97 . V_98 . V_99 = ( type & 0x00ff0000 ) >> 16 ;
V_97 . V_98 . V_100 = ( type & 0x0000ff00 ) >> 8 ;
V_97 . V_98 . V_101 = ( type & 0x000000ff ) ;
F_9 ( V_29 , V_11 , 0xd04d , L_30 ,
V_97 . V_98 . V_99 , V_97 . V_98 . V_100 , V_97 . V_98 . V_101 ) ;
F_9 ( V_29 , V_11 , 0x70e4 , L_31 , V_102 , type ) ;
F_71 ( V_11 , V_103 , V_97 ) ;
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
T_4 V_104 ;
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 > V_105 )
return 0 ;
if ( V_14 -> V_106 )
goto V_107;
V_14 -> V_106 = F_73 ( & V_14 -> V_64 -> V_108 , V_105 ,
& V_14 -> V_109 , V_110 ) ;
if ( ! V_14 -> V_106 ) {
F_9 ( V_47 , V_11 , 0x7076 ,
L_32 ) ;
return 0 ;
}
V_107:
V_104 = 0 ;
memset ( V_14 -> V_106 , 0 , V_105 ) ;
V_16 = F_74 ( V_11 , V_14 -> V_109 ,
V_105 , & V_104 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7077 ,
L_33 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_104 > V_9 ? V_9 : V_104 ;
memcpy ( V_7 , V_14 -> V_106 , V_9 ) ;
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
if ( ! F_24 ( V_35 ) || V_8 != 0 || V_9 > V_111 )
return 0 ;
if ( V_14 -> V_112 )
goto V_107;
V_14 -> V_112 = F_73 ( & V_14 -> V_64 -> V_108 , V_111 ,
& V_14 -> V_113 , V_110 ) ;
if ( ! V_14 -> V_112 ) {
F_9 ( V_47 , V_11 , 0x7078 ,
L_34 ) ;
return - V_67 ;
}
V_107:
memset ( V_14 -> V_112 , 0 , V_111 ) ;
V_16 = F_76 ( V_11 , V_14 -> V_113 ,
V_111 ) ;
if ( V_16 != V_46 ) {
F_9 ( V_47 , V_11 , 0x7079 ,
L_35 , V_16 ) ;
return - V_82 ;
}
memcpy ( V_7 , V_14 -> V_112 , V_9 ) ;
return V_9 ;
}
void
F_77 ( T_8 * V_11 )
{
struct V_114 * V_85 = V_11 -> V_85 ;
struct V_115 * V_44 ;
int V_116 ;
for ( V_44 = V_117 ; V_44 -> V_118 ; V_44 ++ ) {
if ( V_44 -> V_119 && ! F_27 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_119 == 2 && ! F_43 ( V_11 -> V_15 ) )
continue;
if ( V_44 -> V_119 == 3 && ! ( F_44 ( V_11 -> V_15 ) ) )
continue;
V_116 = F_78 ( & V_85 -> V_120 . V_4 ,
V_44 -> V_121 ) ;
if ( V_116 )
F_9 ( V_47 , V_11 , 0x00f3 ,
L_36 ,
V_44 -> V_118 , V_116 ) ;
else
F_21 ( V_122 , V_11 , 0x00f4 ,
L_37 ,
V_44 -> V_118 ) ;
}
}
void
F_79 ( T_8 * V_11 , bool V_123 )
{
struct V_114 * V_85 = V_11 -> V_85 ;
struct V_115 * V_44 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_44 = V_117 ; V_44 -> V_118 ; V_44 ++ ) {
if ( V_44 -> V_119 && ! F_27 ( V_14 ) )
continue;
if ( V_44 -> V_119 == 2 && ! F_43 ( V_14 ) )
continue;
if ( V_44 -> V_119 == 3 && ! ( F_44 ( V_11 -> V_15 ) ) )
continue;
if ( V_44 -> V_119 == 0x27 && ! F_46 ( V_11 -> V_15 ) )
continue;
F_80 ( & V_85 -> V_120 . V_4 ,
V_44 -> V_121 ) ;
}
if ( V_123 && V_14 -> V_124 == 1 )
V_14 -> V_36 -> V_125 ( V_11 ) ;
}
static T_1
F_81 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
return F_82 ( V_7 , V_127 , L_38 , V_128 ) ;
}
static T_1
F_83 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_129 [ 128 ] ;
return F_82 ( V_7 , V_127 , L_38 ,
V_14 -> V_36 -> V_130 ( V_11 , V_129 , sizeof( V_129 ) ) ) ;
}
static T_1
F_85 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_131 ;
if ( F_86 ( V_11 -> V_15 ) ) {
return F_82 ( V_7 , V_127 , L_38 ,
V_11 -> V_15 -> V_132 . V_133 ) ;
} else if ( F_27 ( V_14 ) ) {
F_87 ( V_11 , L_39 , V_7 , V_127 - 1 ) ;
return strlen ( strcat ( V_7 , L_40 ) ) ;
}
V_131 = ( ( V_14 -> V_134 & 0x1f ) << 16 ) | ( V_14 -> V_135 << 8 ) | V_14 -> V_136 ;
return F_82 ( V_7 , V_127 , L_41 , 'A' + V_131 / 100000 ,
V_131 % 100000 ) ;
}
static T_1
F_88 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
return F_82 ( V_7 , V_127 , L_42 , V_11 -> V_15 -> V_64 -> V_12 ) ;
}
static T_1
F_89 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_86 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_127 , L_38 ,
V_11 -> V_15 -> V_132 . V_137 ) ;
return F_82 ( V_7 , V_127 , L_43 ,
V_14 -> V_138 [ 0 ] , V_14 -> V_138 [ 1 ] , V_14 -> V_138 [ 2 ] ,
V_14 -> V_138 [ 3 ] ) ;
}
static T_1
F_90 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
return F_82 ( V_7 , V_127 , L_38 , V_11 -> V_15 -> V_139 ) ;
}
static T_1
F_91 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
return F_82 ( V_7 , V_127 , L_38 , V_11 -> V_15 -> V_140 ) ;
}
static T_1
F_92 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
char V_141 [ 30 ] ;
return F_82 ( V_7 , V_127 , L_38 ,
V_11 -> V_15 -> V_36 -> V_142 ( V_11 , V_141 ) ) ;
}
static T_1
F_93 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_143 = 0 ;
if ( F_94 ( & V_11 -> V_144 ) == V_145 ||
F_94 ( & V_11 -> V_144 ) == V_146 ||
V_11 -> V_147 & V_148 )
V_143 = F_82 ( V_7 , V_127 , L_44 ) ;
else if ( F_94 ( & V_11 -> V_144 ) != V_149 ||
F_51 ( V_11 ) )
V_143 = F_82 ( V_7 , V_127 , L_45 ) ;
else {
V_143 = F_82 ( V_7 , V_127 , L_46 ) ;
switch ( V_14 -> V_150 ) {
case V_151 :
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_47 ) ;
break;
case V_152 :
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_48 ) ;
break;
case V_153 :
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 ,
L_49 ) ;
break;
case V_154 :
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_50 ) ;
break;
default:
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_47 ) ;
break;
}
}
return V_143 ;
}
static T_1
F_95 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
int V_143 = 0 ;
switch ( V_11 -> V_15 -> V_155 ) {
case V_156 :
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_51 ) ;
break;
case V_157 :
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_52 ) ;
break;
}
return V_143 ;
}
static T_1
F_96 ( struct V_12 * V_108 , struct V_126 * V_121 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_62 = 0 ;
T_4 V_155 ;
if ( ! F_97 ( V_14 ) )
return - V_158 ;
if ( sscanf ( V_7 , L_53 , & V_62 ) != 1 )
return - V_43 ;
if ( V_62 )
V_155 = V_156 ;
else
V_155 = V_157 ;
if ( V_155 != V_157 || V_14 -> V_155 != V_157 ) {
V_14 -> V_155 = V_155 ;
F_22 ( V_33 , & V_11 -> V_34 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_98 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
return F_82 ( V_7 , V_127 , L_54 , V_11 -> V_15 -> V_159 * 100 ) ;
}
static T_1
F_99 ( struct V_12 * V_108 , struct V_126 * V_121 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
int V_62 = 0 ;
T_4 V_159 ;
if ( sscanf ( V_7 , L_53 , & V_62 ) != 1 )
return - V_43 ;
if ( V_62 > 25500 || V_62 < 100 )
return - V_58 ;
V_159 = ( T_4 ) ( V_62 / 100 ) ;
V_11 -> V_15 -> V_159 = V_159 ;
return strlen ( V_7 ) ;
}
static T_1
F_100 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
int V_143 = 0 ;
if ( V_11 -> V_15 -> V_124 )
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_55 ) ;
else
V_143 += F_82 ( V_7 + V_143 , V_127 - V_143 , L_52 ) ;
return V_143 ;
}
static T_1
F_101 ( struct V_12 * V_108 , struct V_126 * V_121 ,
const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_62 = 0 ;
int V_16 ;
if ( F_102 ( V_14 ) || F_103 ( V_14 ) )
return - V_90 ;
if ( F_104 ( V_160 , & V_11 -> V_34 ) ) {
F_9 ( V_47 , V_11 , 0x707a ,
L_56 ) ;
return - V_161 ;
}
if ( sscanf ( V_7 , L_53 , & V_62 ) != 1 )
return - V_43 ;
if ( V_62 )
V_16 = V_14 -> V_36 -> V_162 ( V_11 ) ;
else
V_16 = V_14 -> V_36 -> V_125 ( V_11 ) ;
if ( V_16 != V_46 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_105 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_127 , L_57 , V_14 -> V_163 [ 1 ] ,
V_14 -> V_163 [ 0 ] ) ;
}
static T_1
F_106 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_127 , L_57 , V_14 -> V_164 [ 1 ] ,
V_14 -> V_164 [ 0 ] ) ;
}
static T_1
F_107 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_127 , L_57 , V_14 -> V_165 [ 1 ] ,
V_14 -> V_165 [ 0 ] ) ;
}
static T_1
F_108 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_127 , L_58 ,
V_14 -> V_166 [ 0 ] , V_14 -> V_166 [ 1 ] , V_14 -> V_166 [ 2 ] ,
V_14 -> V_166 [ 3 ] ) ;
}
static T_1
F_109 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_59 ( V_14 ) && ! F_60 ( V_14 ) && ! F_46 ( V_14 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_59 ,
V_14 -> V_167 [ 0 ] , V_14 -> V_167 [ 1 ] ,
V_14 -> V_167 [ 2 ] , V_14 -> V_167 [ 3 ] ) ;
}
static T_1
F_110 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
return F_82 ( V_7 , V_127 , L_60 ,
V_11 -> V_168 . V_169 ) ;
}
static T_1
F_111 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
int V_16 = V_46 ;
T_4 V_170 [ 2 ] = { 0 , 0 } ;
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_112 ( V_14 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
if ( V_14 -> V_171 -> V_172 == 0 )
V_16 = F_113 ( V_11 , V_170 ) ;
if ( ( V_16 == V_46 ) && ( V_170 [ 0 ] == 0 ) )
return F_82 ( V_7 , V_127 , L_61 ,
( T_5 ) V_14 -> V_171 -> V_172 ) ;
return F_82 ( V_7 , V_127 , L_40 ) ;
}
static T_1
F_114 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_59 ( V_14 ) && ! F_69 ( V_14 ) && ! F_17 ( V_14 ) &&
! F_46 ( V_14 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_62 ,
V_14 -> V_173 [ 0 ] , V_14 -> V_173 [ 1 ] , V_14 -> V_173 [ 2 ] ,
V_14 -> V_174 ) ;
}
static T_1
F_115 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_59 ( V_14 ) && ! F_69 ( V_14 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_63 ,
V_14 -> V_175 [ 0 ] , V_14 -> V_175 [ 1 ] , V_14 -> V_175 [ 2 ] ) ;
}
static T_1
F_116 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return F_82 ( V_7 , V_127 , L_64 , V_14 -> V_176 ) ;
}
static T_1
F_117 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
if ( ! F_44 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_60 , V_11 -> V_177 ) ;
}
static T_1
F_118 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
if ( ! F_44 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_65 , V_11 -> V_178 ) ;
}
static T_1
F_119 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
return F_82 ( V_7 , V_127 , L_60 , V_11 -> V_15 -> V_179 ) ;
}
static T_1
F_120 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
T_4 V_180 = 0 ;
if ( F_51 ( V_11 ) ) {
F_9 ( V_47 , V_11 , 0x70dc , L_66 ) ;
goto V_181;
}
if ( V_11 -> V_15 -> V_86 . V_182 ) {
F_9 ( V_47 , V_11 , 0x70dd , L_67 ) ;
goto V_181;
}
if ( F_121 ( V_11 , & V_180 ) == V_46 )
return F_82 ( V_7 , V_127 , L_60 , V_180 ) ;
V_181:
return F_82 ( V_7 , V_127 , L_40 ) ;
}
static T_1
F_122 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
int V_16 = V_183 ;
T_4 V_184 [ 6 ] ;
T_5 V_185 ;
if ( F_86 ( V_11 -> V_15 ) ) {
V_185 = F_123 ( V_108 , V_121 , V_7 ) ;
return F_82 ( V_7 , V_127 , L_64 , V_185 ) ;
}
if ( F_51 ( V_11 ) )
F_9 ( V_47 , V_11 , 0x707c ,
L_66 ) ;
else if ( ! V_11 -> V_15 -> V_86 . V_182 )
V_16 = F_124 ( V_11 , V_184 ) ;
if ( V_16 != V_46 )
memset ( V_184 , - 1 , sizeof( V_184 ) ) ;
return F_82 ( V_7 , V_127 , L_68 ,
V_184 [ 0 ] , V_184 [ 1 ] , V_184 [ 2 ] , V_184 [ 3 ] , V_184 [ 4 ] , V_184 [ 5 ] ) ;
}
static T_1
F_125 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
if ( ! F_126 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_69 , V_11 -> V_186 . V_187 ) ;
}
static T_1
F_127 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
if ( ! F_126 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_69 ,
V_11 -> V_186 . V_188 >> 20 ) ;
}
static T_1
F_128 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_60 ;
if ( ! V_14 -> V_31 )
V_60 = 0 ;
else if ( F_5 ( V_14 ) )
V_60 = V_14 -> V_19 + V_14 -> V_22 ;
else
V_60 = V_14 -> V_27 ;
return F_82 ( V_7 , V_127 , L_60 , V_60 ) ;
}
static T_1
F_129 ( struct V_12 * V_108 ,
struct V_126 * V_121 , char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
if ( ! F_5 ( V_11 -> V_15 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
else
return F_82 ( V_7 , V_127 , L_38 ,
V_11 -> V_15 -> V_189 ? L_70 : L_71 ) ;
}
static T_1
F_130 ( struct V_12 * V_108 ,
struct V_126 * V_121 , const char * V_7 , T_3 V_9 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
int V_62 = 0 ;
if ( ! F_5 ( V_11 -> V_15 ) )
return - V_43 ;
if ( sscanf ( V_7 , L_53 , & V_62 ) != 1 )
return - V_43 ;
V_11 -> V_15 -> V_189 = V_62 != 0 ;
return strlen ( V_7 ) ;
}
static T_1
F_131 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_46 ( V_14 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_63 ,
V_14 -> V_190 [ 0 ] , V_14 -> V_190 [ 1 ] , V_14 -> V_190 [ 2 ] ) ;
}
static T_1
F_132 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_46 ( V_14 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_38 ,
V_14 -> V_191 == 5 ? L_72 :
V_14 -> V_191 == 4 ? L_73 :
V_14 -> V_191 == 3 ? L_74 :
V_14 -> V_191 == 2 ? L_75 :
V_14 -> V_191 != 0 ? L_76 : L_77 ) ;
}
static T_1
F_133 ( struct V_12 * V_108 , struct V_126 * V_121 ,
char * V_7 )
{
T_8 * V_11 = F_2 ( F_84 ( V_108 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_46 ( V_14 ) )
return F_82 ( V_7 , V_127 , L_40 ) ;
return F_82 ( V_7 , V_127 , L_38 ,
V_14 -> V_192 ? L_72 : L_73 ) ;
}
static void
F_134 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
F_135 ( V_193 ) = V_11 -> V_194 . V_98 . V_99 << 16 |
V_11 -> V_194 . V_98 . V_100 << 8 | V_11 -> V_194 . V_98 . V_101 ;
}
static void
F_136 ( struct V_114 * V_193 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_193 ) ) ) -> V_15 ;
T_9 V_195 = V_196 ;
if ( F_86 ( V_14 ) ) {
F_137 ( V_193 ) ;
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
F_138 ( V_193 ) = V_195 ;
}
static void
F_139 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
T_5 V_212 = V_213 ;
if ( V_11 -> V_214 ) {
F_140 ( V_193 ) = V_215 ;
return;
}
switch ( V_11 -> V_15 -> V_150 ) {
case V_151 :
V_212 = V_216 ;
break;
case V_152 :
V_212 = V_217 ;
break;
case V_153 :
V_212 = V_218 ;
break;
case V_154 :
V_212 = V_219 ;
break;
}
F_140 ( V_193 ) = V_212 ;
}
static void
F_141 ( struct V_220 * V_221 )
{
struct V_114 * V_85 = F_3 ( V_221 -> V_108 . V_222 ) ;
T_8 * V_11 = F_2 ( V_85 ) ;
T_10 * V_223 ;
T_11 V_224 = 0 ;
F_142 (fcport, &vha->vp_fcports, list) {
if ( V_223 -> V_225 &&
V_221 -> V_226 == V_223 -> V_225 -> V_227 ) {
V_224 = F_143 ( V_223 -> V_224 ) ;
break;
}
}
F_144 ( V_221 ) = V_224 ;
}
static void
F_145 ( struct V_220 * V_221 )
{
struct V_114 * V_85 = F_3 ( V_221 -> V_108 . V_222 ) ;
T_8 * V_11 = F_2 ( V_85 ) ;
T_10 * V_223 ;
T_11 V_228 = 0 ;
F_142 (fcport, &vha->vp_fcports, list) {
if ( V_223 -> V_225 &&
V_221 -> V_226 == V_223 -> V_225 -> V_227 ) {
V_228 = F_143 ( V_223 -> V_228 ) ;
break;
}
}
F_146 ( V_221 ) = V_228 ;
}
static void
F_147 ( struct V_220 * V_221 )
{
struct V_114 * V_85 = F_3 ( V_221 -> V_108 . V_222 ) ;
T_8 * V_11 = F_2 ( V_85 ) ;
T_10 * V_223 ;
T_5 V_229 = ~ 0U ;
F_142 (fcport, &vha->vp_fcports, list) {
if ( V_223 -> V_225 &&
V_221 -> V_226 == V_223 -> V_225 -> V_227 ) {
V_229 = V_223 -> V_194 . V_98 . V_99 << 16 |
V_223 -> V_194 . V_98 . V_100 << 8 | V_223 -> V_194 . V_98 . V_101 ;
break;
}
}
F_148 ( V_221 ) = V_229 ;
}
static void
F_149 ( struct V_230 * V_225 , T_5 V_231 )
{
if ( V_231 )
V_225 -> V_232 = V_231 ;
else
V_225 -> V_232 = 1 ;
}
static void
F_150 ( struct V_230 * V_225 )
{
struct V_114 * V_85 = F_151 ( V_225 ) ;
T_10 * V_223 = * ( T_10 * * ) V_225 -> V_233 ;
unsigned long V_86 ;
if ( ! V_223 )
return;
F_152 ( V_223 , V_234 ) ;
F_153 ( V_85 -> V_235 , V_86 ) ;
V_223 -> V_225 = V_223 -> V_236 = NULL ;
* ( ( T_10 * * ) V_225 -> V_233 ) = NULL ;
F_154 ( V_85 -> V_235 , V_86 ) ;
if ( F_104 ( V_160 , & V_223 -> V_11 -> V_34 ) )
return;
if ( F_38 ( F_39 ( V_223 -> V_11 -> V_15 -> V_64 ) ) ) {
F_155 ( V_223 -> V_11 , V_237 << 16 ) ;
return;
}
}
static void
F_156 ( struct V_230 * V_225 )
{
T_10 * V_223 = * ( T_10 * * ) V_225 -> V_233 ;
if ( ! V_223 )
return;
if ( F_104 ( V_238 , & V_223 -> V_11 -> V_34 ) )
return;
if ( F_104 ( V_160 , & V_223 -> V_11 -> V_34 ) )
return;
if ( F_38 ( F_39 ( V_223 -> V_11 -> V_15 -> V_64 ) ) ) {
F_155 ( V_223 -> V_11 , V_237 << 16 ) ;
return;
}
if ( V_223 -> V_239 != V_240 ) {
if ( F_27 ( V_223 -> V_11 -> V_15 ) )
V_223 -> V_11 -> V_15 -> V_36 -> V_241 ( V_223 -> V_11 ,
V_223 -> V_239 , V_223 -> V_194 . V_98 . V_99 ,
V_223 -> V_194 . V_98 . V_100 , V_223 -> V_194 . V_98 . V_101 ) ;
else
F_157 ( V_223 -> V_11 , V_223 ) ;
}
}
static int
F_158 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
if ( F_86 ( V_11 -> V_15 ) )
return 0 ;
F_159 ( V_11 ) ;
return 0 ;
}
static struct V_242 *
F_160 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_83 = F_54 ( V_14 -> V_64 ) ;
int V_16 ;
struct V_243 * V_244 ;
T_12 V_245 ;
struct V_242 * V_246 = & V_11 -> V_247 ;
memset ( V_246 , - 1 , sizeof( * V_246 ) ) ;
if ( F_86 ( V_11 -> V_15 ) )
goto V_181;
if ( F_104 ( V_238 , & V_11 -> V_34 ) )
goto V_181;
if ( F_38 ( F_39 ( V_14 -> V_64 ) ) )
goto V_181;
if ( F_51 ( V_11 ) )
goto V_181;
V_244 = F_73 ( & V_14 -> V_64 -> V_108 ,
sizeof( * V_244 ) , & V_245 , V_110 ) ;
if ( ! V_244 ) {
F_9 ( V_47 , V_11 , 0x707d ,
L_78 ) ;
goto V_181;
}
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
V_16 = V_183 ;
if ( F_27 ( V_14 ) ) {
V_16 = F_161 ( V_83 , V_244 , V_245 , 0 ) ;
} else if ( F_94 ( & V_83 -> V_144 ) == V_149 &&
! V_14 -> V_248 ) {
V_16 = F_162 ( V_83 , V_83 -> V_239 ,
V_244 , V_245 ) ;
}
if ( V_16 != V_46 )
goto V_249;
V_246 -> V_250 = V_244 -> V_251 ;
V_246 -> V_252 = V_244 -> V_253 ;
V_246 -> V_254 = V_244 -> V_255 ;
V_246 -> V_256 = V_244 -> V_257 ;
V_246 -> V_258 = V_244 -> V_259 ;
V_246 -> V_260 = V_244 -> V_261 ;
if ( F_27 ( V_14 ) ) {
V_246 -> V_262 = V_244 -> V_263 ;
V_246 -> V_264 = V_244 -> V_264 ;
V_246 -> V_265 = V_244 -> V_265 ;
V_246 -> V_266 = V_244 -> V_267 ;
V_246 -> V_268 = V_244 -> V_269 ;
V_246 -> V_270 =
V_244 -> V_271 + V_244 -> V_267 ;
V_246 -> V_272 = V_11 -> V_168 . V_273 ;
V_246 -> V_274 = V_11 -> V_168 . V_275 ;
}
V_246 -> V_276 = V_11 -> V_168 . V_277 ;
V_246 -> V_278 = V_11 -> V_168 . V_279 ;
V_246 -> V_280 = V_11 -> V_168 . V_281 ;
V_246 -> V_282 = V_11 -> V_168 . V_273 >> 20 ;
V_246 -> V_283 = V_11 -> V_168 . V_275 >> 20 ;
V_246 -> V_284 =
F_163 () - V_11 -> V_168 . V_285 ;
F_164 ( V_246 -> V_284 , V_286 ) ;
V_249:
F_165 ( & V_14 -> V_64 -> V_108 , sizeof( struct V_243 ) ,
V_244 , V_245 ) ;
V_181:
return V_246 ;
}
static void
F_166 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_83 = F_54 ( V_14 -> V_64 ) ;
struct V_243 * V_244 ;
T_12 V_245 ;
memset ( & V_11 -> V_168 , 0 , sizeof( V_11 -> V_168 ) ) ;
memset ( & V_11 -> V_247 , 0 , sizeof( V_11 -> V_247 ) ) ;
V_11 -> V_168 . V_285 = F_163 () ;
if ( F_27 ( V_14 ) ) {
V_244 = F_73 ( & V_14 -> V_64 -> V_108 ,
sizeof( * V_244 ) , & V_245 , V_110 ) ;
if ( ! V_244 ) {
F_9 ( V_47 , V_11 , 0x70d7 ,
L_78 ) ;
return;
}
F_161 ( V_83 , V_244 , V_245 , V_287 ) ;
F_165 ( & V_14 -> V_64 -> V_108 , sizeof( * V_244 ) ,
V_244 , V_245 ) ;
}
}
static void
F_167 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
F_168 ( V_11 , F_169 ( V_193 ) ,
sizeof( F_169 ( V_193 ) ) ) ;
}
static void
F_170 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
F_22 ( V_288 , & V_11 -> V_34 ) ;
}
static void
F_171 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
T_6 V_224 [ V_289 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_11 V_290 = F_143 ( V_224 ) ;
if ( V_11 -> V_147 & V_291 )
V_290 = F_143 ( V_11 -> V_292 ) ;
F_172 ( V_193 ) = V_290 ;
}
static void
F_173 ( struct V_114 * V_193 )
{
T_8 * V_11 = F_2 ( V_193 ) ;
struct V_10 * V_83 = F_54 ( V_11 -> V_15 -> V_64 ) ;
if ( ! V_83 -> V_86 . V_293 ) {
F_174 ( V_193 ) = V_294 ;
return;
}
switch ( F_94 ( & V_83 -> V_144 ) ) {
case V_295 :
F_174 ( V_193 ) = V_296 ;
break;
case V_145 :
if ( F_104 ( V_297 , & V_83 -> V_34 ) )
F_174 ( V_193 ) = V_296 ;
else
F_174 ( V_193 ) = V_298 ;
break;
case V_146 :
F_174 ( V_193 ) = V_298 ;
break;
case V_149 :
F_174 ( V_193 ) = V_299 ;
break;
default:
F_174 ( V_193 ) = V_300 ;
break;
}
}
static int
F_175 ( struct V_301 * V_301 , bool V_302 )
{
int V_116 = 0 ;
T_6 V_303 = 0 ;
T_8 * V_83 = F_2 ( V_301 -> V_193 ) ;
T_8 * V_11 = NULL ;
struct V_13 * V_14 = V_83 -> V_15 ;
int V_41 ;
struct V_304 * V_305 = V_14 -> V_306 [ 0 ] ;
struct V_307 * V_308 ;
V_116 = F_176 ( V_301 ) ;
if ( V_116 ) {
F_9 ( V_47 , V_11 , 0x707e ,
L_79 , V_116 ) ;
return ( V_116 ) ;
}
V_11 = F_177 ( V_301 ) ;
if ( V_11 == NULL ) {
F_9 ( V_47 , V_11 , 0x707f , L_80 ) ;
return V_309 ;
}
if ( V_302 ) {
F_178 ( & V_11 -> V_310 , V_311 ) ;
F_179 ( V_301 , V_312 ) ;
} else
F_178 ( & V_11 -> V_310 , V_313 ) ;
F_9 ( V_29 , V_11 , 0x7080 ,
L_81 , V_11 -> V_214 ) ;
F_178 ( & V_11 -> V_144 , V_145 ) ;
V_11 -> V_314 = V_315 ;
V_11 -> V_316 = V_317 ;
if ( F_94 ( & V_83 -> V_144 ) == V_145 ||
F_94 ( & V_83 -> V_144 ) == V_146 ) {
F_21 ( V_32 , V_11 , 0x7081 ,
L_82 ) ;
F_178 ( & V_11 -> V_144 , V_146 ) ;
if ( ! V_302 )
F_179 ( V_301 , V_318 ) ;
}
if ( F_180 ( V_14 ) && V_319 ) {
if ( V_14 -> V_320 & V_321 ) {
int V_322 = 0 , V_323 ;
V_11 -> V_86 . V_324 = 1 ;
F_21 ( V_32 , V_11 , 0x7082 ,
L_83 ) ;
if ( V_319 == 1 )
V_322 = V_325 ;
F_181 ( V_11 -> V_85 ,
V_322 | V_326
| V_327
| V_328
| V_329
| V_330
| V_331 ) ;
V_323 = V_332 ;
if ( F_182 ( V_14 ) &&
( V_319 > 1 || F_183 ( V_14 ) ) )
V_323 |= V_333 ;
F_184 ( V_11 -> V_85 , V_323 ) ;
} else
V_11 -> V_86 . V_324 = 0 ;
}
if ( F_185 ( V_11 -> V_85 , & V_301 -> V_108 ,
& V_14 -> V_64 -> V_108 ) ) {
F_21 ( V_32 , V_11 , 0x7083 ,
L_84 , V_11 -> V_214 ) ;
goto V_334;
}
F_186 ( V_11 -> V_85 ) = V_14 -> V_335 ;
F_187 ( V_11 -> V_85 ) = F_143 ( V_11 -> V_224 ) ;
F_188 ( V_11 -> V_85 ) = F_143 ( V_11 -> V_228 ) ;
F_189 ( V_11 -> V_85 ) =
F_189 ( V_83 -> V_85 ) ;
F_190 ( V_11 -> V_85 ) =
F_190 ( V_83 -> V_85 ) ;
F_191 ( V_11 , V_14 ) ;
F_192 ( V_301 , V_302 ) ;
if ( ! V_336 || ! V_14 -> V_337 )
goto V_338;
for ( V_41 = 0 ; V_41 < V_14 -> V_339 ; V_41 ++ ) {
if ( memcmp ( V_14 -> V_337 [ V_41 ] . V_228 , V_11 -> V_228 , 8 ) == 0
&& memcmp ( V_14 -> V_337 [ V_41 ] . V_224 , V_11 -> V_224 ,
8 ) == 0 ) {
V_303 = V_14 -> V_337 [ V_41 ] . V_340 ;
break;
}
}
if ( V_303 ) {
V_308 = F_193 ( V_11 , V_303 , V_11 -> V_214 , true ) ;
if ( ! V_308 )
F_9 ( V_47 , V_11 , 0x7084 ,
L_85 ,
V_11 -> V_214 ) ;
else {
F_21 ( V_341 , V_11 , 0xc001 ,
L_86 ,
V_308 -> V_226 , V_303 , V_11 -> V_214 ) ;
F_21 ( V_32 , V_11 , 0x7085 ,
L_87 ,
V_308 -> V_226 , V_303 , V_11 -> V_214 ) ;
V_305 = V_308 -> V_305 ;
V_11 -> V_308 = V_308 ;
}
}
V_338:
V_11 -> V_305 = V_305 ;
return 0 ;
V_334:
F_194 ( V_11 ) ;
F_195 ( V_11 ) ;
F_196 ( V_11 -> V_85 ) ;
return V_309 ;
}
static int
F_197 ( struct V_301 * V_301 )
{
T_8 * V_11 = V_301 -> V_233 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_226 = V_11 -> V_214 ;
while ( F_104 ( V_342 , & V_11 -> V_34 ) ||
F_104 ( V_343 , & V_11 -> V_34 ) )
F_198 ( 1000 ) ;
F_194 ( V_11 ) ;
V_11 -> V_86 . V_344 = 1 ;
F_199 ( V_14 , V_11 ) ;
F_200 ( V_11 -> V_85 ) ;
F_201 ( V_11 -> V_85 ) ;
F_195 ( V_11 ) ;
if ( V_11 -> V_345 ) {
F_202 ( V_11 ) ;
F_21 ( V_32 , V_11 , 0x7086 ,
L_88 , V_11 -> V_214 ) ;
}
F_203 ( V_11 ) ;
F_34 ( & V_14 -> V_346 ) ;
V_14 -> V_347 -- ;
F_204 ( V_11 -> V_214 , V_14 -> V_348 ) ;
F_35 ( & V_14 -> V_346 ) ;
F_165 ( & V_14 -> V_64 -> V_108 , V_11 -> V_349 . V_60 , V_11 -> V_349 . V_350 ,
V_11 -> V_349 . V_351 ) ;
if ( V_11 -> V_308 && V_11 -> V_308 -> V_214 == V_11 -> V_214 ) {
if ( F_205 ( V_11 , V_11 -> V_308 ) != V_46 )
F_9 ( V_47 , V_11 , 0x7087 ,
L_89 ) ;
}
F_9 ( V_29 , V_11 , 0x7088 , L_90 , V_226 ) ;
F_196 ( V_11 -> V_85 ) ;
return 0 ;
}
static int
F_192 ( struct V_301 * V_301 , bool V_302 )
{
T_8 * V_11 = V_301 -> V_233 ;
if ( V_302 )
F_194 ( V_11 ) ;
else
F_206 ( V_11 ) ;
return 0 ;
}
void
F_207 ( T_8 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_9 V_195 = V_196 ;
F_186 ( V_11 -> V_85 ) = V_14 -> V_335 ;
F_187 ( V_11 -> V_85 ) = F_143 ( V_11 -> V_224 ) ;
F_188 ( V_11 -> V_85 ) = F_143 ( V_11 -> V_228 ) ;
F_189 ( V_11 -> V_85 ) = V_14 -> V_352 -> V_353 ?
( V_354 | V_355 ) : V_355 ;
F_208 ( V_11 -> V_85 ) = V_14 -> V_356 ;
F_209 ( V_11 -> V_85 ) = V_14 -> V_347 ;
if ( F_44 ( V_14 ) )
V_195 = V_207 ;
else if ( F_45 ( V_14 ) )
V_195 = V_209 | V_205 |
V_203 ;
else if ( F_43 ( V_14 ) )
V_195 = V_205 | V_203 |
V_201 | V_199 ;
else if ( F_42 ( V_14 ) )
V_195 = V_203 | V_201 |
V_199 ;
else if ( F_210 ( V_14 ) )
V_195 = V_201 | V_199 ;
else if ( F_86 ( V_14 ) )
V_195 = V_205 | V_203 |
V_201 | V_199 ;
else if ( F_46 ( V_14 ) )
V_195 = V_211 | V_209 |
V_205 ;
else
V_195 = V_199 ;
F_190 ( V_11 -> V_85 ) = V_195 ;
}
