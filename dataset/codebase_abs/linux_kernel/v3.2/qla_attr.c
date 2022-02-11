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
return - V_31 ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_20 ( V_32 ) )
return 0 ;
if ( F_21 ( V_14 ) )
V_14 -> V_33 -> V_34 ( V_11 , V_14 -> V_35 , V_14 -> V_36 << 2 ,
V_14 -> V_37 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_35 ,
V_14 -> V_37 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_38 ;
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 != V_14 -> V_37 ||
! V_14 -> V_33 -> V_39 )
return - V_31 ;
if ( F_23 ( V_14 ) ) {
T_5 * V_40 ;
T_5 V_41 ;
V_40 = ( T_5 * ) V_7 ;
V_41 = 0 ;
for ( V_38 = 0 ; V_38 < ( ( V_9 >> 2 ) - 1 ) ; V_38 ++ )
V_41 += F_24 ( * V_40 ++ ) ;
V_41 = ~ V_41 + 1 ;
* V_40 = F_25 ( V_41 ) ;
} else {
T_6 * V_40 ;
T_6 V_41 ;
V_40 = ( T_6 * ) V_7 ;
V_41 = 0 ;
for ( V_38 = 0 ; V_38 < V_9 - 1 ; V_38 ++ )
V_41 += * V_40 ++ ;
V_41 = ~ V_41 + 1 ;
* V_40 = V_41 ;
}
if ( F_26 ( V_11 ) != V_42 ) {
F_9 ( V_43 , V_11 , 0x705f ,
L_5 ) ;
return - V_44 ;
}
V_14 -> V_33 -> V_39 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_45 , V_9 ) ;
V_14 -> V_33 -> V_46 ( V_11 , ( T_6 * ) V_14 -> V_35 , V_14 -> V_45 ,
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
return - V_31 ;
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
return - V_31 ;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
return - V_44 ;
if ( sscanf ( V_7 , L_7 , & V_56 , & V_53 , & V_54 ) < 1 )
return - V_31 ;
if ( V_53 > V_14 -> V_55 )
return - V_31 ;
switch ( V_56 ) {
case 0 :
if ( V_14 -> V_47 != V_48 &&
V_14 -> V_47 != V_51 )
return - V_31 ;
V_14 -> V_47 = V_59 ;
F_17 ( V_28 , V_11 , 0x7061 ,
L_8 ,
V_14 -> V_50 ) ;
F_34 ( V_14 -> V_49 ) ;
V_14 -> V_49 = NULL ;
break;
case 1 :
if ( V_14 -> V_47 != V_59 )
return - V_31 ;
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
V_14 -> V_33 -> V_34 ( V_11 , V_14 -> V_49 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
break;
case 2 :
if ( V_14 -> V_47 != V_59 )
return - V_31 ;
V_57 = 0 ;
if ( V_14 -> V_55 == V_62 && V_53 == 0 )
V_57 = 1 ;
else if ( V_53 == ( V_14 -> V_63 * 4 ) ||
V_53 == ( V_14 -> V_64 * 4 ) )
V_57 = 1 ;
else if ( F_36 ( V_14 ) || F_37 ( V_14 ) )
V_57 = 1 ;
if ( ! V_57 ) {
F_9 ( V_43 , V_11 , 0x7065 ,
L_12 , V_53 , V_54 ) ;
return - V_31 ;
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
return - V_61 ;
if ( F_26 ( V_11 ) != V_42 ) {
F_9 ( V_43 , V_11 , 0x7068 ,
L_16 ) ;
return - V_44 ;
}
F_17 ( V_28 , V_11 , 0x7069 ,
L_17 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
V_14 -> V_33 -> V_65 ( V_11 , V_14 -> V_49 ,
V_14 -> V_60 , V_14 -> V_50 ) ;
break;
default:
return - V_31 ;
}
return V_9 ;
}
static T_1
F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
return - V_44 ;
if ( ! F_20 ( V_32 ) )
return - V_31 ;
if ( F_21 ( V_14 ) )
V_14 -> V_33 -> V_34 ( V_11 , V_14 -> V_66 , V_14 -> V_67 << 2 ,
V_14 -> V_68 ) ;
return F_6 ( V_7 , V_9 , & V_8 , V_14 -> V_66 , V_14 -> V_68 ) ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_69 ;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
return 0 ;
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 != V_14 -> V_68 ||
! V_14 -> V_33 -> V_39 )
return 0 ;
if ( F_26 ( V_11 ) != V_42 ) {
F_9 ( V_43 , V_11 , 0x706a ,
L_18 ) ;
return - V_44 ;
}
V_14 -> V_33 -> V_39 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_70 , V_9 ) ;
V_14 -> V_33 -> V_46 ( V_11 , ( T_6 * ) V_14 -> V_66 , V_14 -> V_70 , V_9 ) ;
if ( ! F_23 ( V_14 ) )
return - V_31 ;
V_69 = F_35 ( 256 ) ;
if ( ! V_69 ) {
F_9 ( V_43 , V_11 , 0x706b ,
L_19 ) ;
return - V_61 ;
}
V_14 -> V_33 -> V_71 ( V_11 , V_69 ) ;
F_34 ( V_69 ) ;
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
T_4 V_40 , V_72 , V_73 ;
int V_16 ;
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 != V_74 * 2 )
return 0 ;
if ( V_14 -> V_75 )
goto V_76;
V_14 -> V_75 = F_41 ( V_14 -> V_77 , V_78 ,
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
V_16 = F_42 ( V_11 , V_14 -> V_79 , V_14 -> V_75 ,
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
F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_82 = F_44 ( V_14 -> V_58 ) ;
int type ;
if ( V_8 != 0 )
return - V_31 ;
type = F_8 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_25 , V_11 , 0x706e ,
L_22 ) ;
F_45 ( V_11 -> V_83 ) ;
F_18 ( V_29 , & V_11 -> V_30 ) ;
if ( F_5 ( V_14 ) ) {
F_13 ( V_14 ) ;
F_14 ( V_11 ) ;
F_15 ( V_14 ) ;
}
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_46 ( V_11 -> V_83 ) ;
break;
case 0x2025d :
if ( ! F_47 ( V_14 ) )
return - V_84 ;
F_9 ( V_25 , V_11 , 0x706f ,
L_23 ) ;
F_26 ( V_11 ) ;
F_45 ( V_11 -> V_83 ) ;
if ( F_48 ( V_11 ) != V_42 )
F_9 ( V_43 , V_11 , 0x7070 ,
L_24 ) ;
F_46 ( V_11 -> V_83 ) ;
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
F_49 ( V_11 ) ;
break;
}
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
T_4 V_86 , V_87 , V_88 , V_89 ;
int V_16 ;
V_14 -> V_90 = 0 ;
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 < 8 )
return - V_31 ;
if ( ! V_14 -> V_91 ) {
V_14 -> V_91 = F_41 ( V_14 -> V_77 , V_78 ,
& V_14 -> V_92 ) ;
if ( ! V_14 -> V_91 ) {
F_9 ( V_43 , V_11 , 0x7073 ,
L_27 ) ;
return - V_61 ;
}
}
V_86 = F_51 ( ( void * ) & V_7 [ 0 ] ) ;
V_87 = F_51 ( ( void * ) & V_7 [ 2 ] ) ;
V_88 = F_51 ( ( void * ) & V_7 [ 4 ] ) ;
V_89 = F_51 ( ( void * ) & V_7 [ 6 ] ) ;
if ( ! ( V_88 & V_93 ) )
if ( V_89 == 0 || V_89 > V_94 || V_89 > V_9 - 8 )
return - V_31 ;
memcpy ( V_14 -> V_91 , & V_7 [ 8 ] , V_89 ) ;
V_16 = F_52 ( V_11 , V_14 -> V_92 , V_14 -> V_91 ,
V_86 , V_87 , V_89 , V_88 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x7074 ,
L_28 ,
V_16 , V_86 , V_87 , V_88 , V_89 , V_7 [ 8 ] ) ;
return - V_81 ;
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
T_4 V_86 , V_87 , V_88 , V_89 ;
int V_16 ;
V_14 -> V_90 = 0 ;
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 < 8 )
return - V_31 ;
if ( ! V_14 -> V_91 ) {
V_14 -> V_91 = F_41 ( V_14 -> V_77 , V_78 ,
& V_14 -> V_92 ) ;
if ( ! V_14 -> V_91 ) {
F_9 ( V_43 , V_11 , 0x708c ,
L_29 ) ;
return - V_61 ;
}
}
V_86 = F_51 ( ( void * ) & V_7 [ 0 ] ) ;
V_87 = F_51 ( ( void * ) & V_7 [ 2 ] ) ;
V_88 = F_51 ( ( void * ) & V_7 [ 4 ] ) ;
V_89 = F_51 ( ( void * ) & V_7 [ 6 ] ) ;
if ( ! ( V_88 & V_93 ) )
if ( V_89 == 0 || V_89 > V_94 )
return - V_31 ;
memset ( V_14 -> V_91 , 0 , V_89 ) ;
V_16 = F_42 ( V_11 , V_14 -> V_92 , V_14 -> V_91 ,
V_86 , V_87 , V_89 , V_88 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_25 , V_11 , 0x7075 ,
L_30 ,
V_16 , V_86 , V_87 , V_88 , V_89 ) ;
return - V_81 ;
}
V_14 -> V_90 = V_89 ;
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
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 == 0 )
return 0 ;
if ( ! V_14 -> V_91 || V_14 -> V_90 == 0 || V_14 -> V_90 > V_9 )
return - V_31 ;
memcpy ( V_7 , V_14 -> V_91 , V_14 -> V_90 ) ;
return V_14 -> V_90 ;
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
T_4 V_95 ;
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 > V_96 )
return 0 ;
if ( V_14 -> V_97 )
goto V_76;
V_14 -> V_97 = F_56 ( & V_14 -> V_58 -> V_86 , V_96 ,
& V_14 -> V_98 , V_78 ) ;
if ( ! V_14 -> V_97 ) {
F_9 ( V_43 , V_11 , 0x7076 ,
L_31 ) ;
return 0 ;
}
V_76:
V_95 = 0 ;
memset ( V_14 -> V_97 , 0 , V_96 ) ;
V_16 = F_57 ( V_11 , V_14 -> V_98 ,
V_96 , & V_95 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x7077 ,
L_32 , V_16 ) ;
V_9 = 0 ;
}
V_9 = V_95 > V_9 ? V_9 : V_95 ;
memcpy ( V_7 , V_14 -> V_97 , V_9 ) ;
return V_9 ;
}
static T_1
F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
T_4 V_95 ;
if ( ! F_20 ( V_32 ) || V_8 != 0 || V_9 > V_99 )
return 0 ;
if ( V_14 -> V_100 )
goto V_76;
V_14 -> V_100 = F_56 ( & V_14 -> V_58 -> V_86 , V_99 ,
& V_14 -> V_101 , V_78 ) ;
if ( ! V_14 -> V_100 ) {
F_9 ( V_43 , V_11 , 0x7078 ,
L_33 ) ;
return - V_61 ;
}
V_76:
V_95 = 0 ;
memset ( V_14 -> V_100 , 0 , V_99 ) ;
V_16 = F_59 ( V_11 , V_14 -> V_101 ,
V_99 ) ;
if ( V_16 != V_42 ) {
F_9 ( V_43 , V_11 , 0x7079 ,
L_34 , V_16 ) ;
return - V_81 ;
}
memcpy ( V_7 , V_14 -> V_100 , V_9 ) ;
return V_9 ;
}
void
F_60 ( T_7 * V_11 )
{
struct V_102 * V_83 = V_11 -> V_83 ;
struct V_103 * V_40 ;
int V_104 ;
for ( V_40 = V_105 ; V_40 -> V_106 ; V_40 ++ ) {
if ( V_40 -> V_107 && ! F_23 ( V_11 -> V_15 ) )
continue;
if ( V_40 -> V_107 == 2 && ! F_36 ( V_11 -> V_15 ) )
continue;
if ( V_40 -> V_107 == 3 && ! ( F_37 ( V_11 -> V_15 ) ) )
continue;
V_104 = F_61 ( & V_83 -> V_108 . V_4 ,
V_40 -> V_109 ) ;
if ( V_104 )
F_9 ( V_43 , V_11 , 0x00f3 ,
L_35 ,
V_40 -> V_106 , V_104 ) ;
else
F_17 ( V_110 , V_11 , 0x00f4 ,
L_36 ,
V_40 -> V_106 ) ;
}
}
void
F_62 ( T_7 * V_11 )
{
struct V_102 * V_83 = V_11 -> V_83 ;
struct V_103 * V_40 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_40 = V_105 ; V_40 -> V_106 ; V_40 ++ ) {
if ( V_40 -> V_107 && ! F_23 ( V_14 ) )
continue;
if ( V_40 -> V_107 == 2 && ! F_36 ( V_14 ) )
continue;
if ( V_40 -> V_107 == 3 && ! ! ( F_37 ( V_11 -> V_15 ) ) )
continue;
F_63 ( & V_83 -> V_108 . V_4 ,
V_40 -> V_109 ) ;
}
if ( V_14 -> V_111 == 1 )
V_14 -> V_33 -> V_112 ( V_11 ) ;
}
static T_1
F_64 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
return snprintf ( V_7 , V_114 , L_37 , V_115 ) ;
}
static T_1
F_65 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_116 [ 128 ] ;
return snprintf ( V_7 , V_114 , L_37 ,
V_14 -> V_33 -> V_117 ( V_11 , V_116 ) ) ;
}
static T_1
F_67 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_118 ;
if ( F_23 ( V_14 ) ) {
F_68 ( V_11 , L_38 , V_7 , V_114 ) ;
return snprintf ( V_7 , V_114 , L_37 , V_7 ) ;
}
V_118 = ( ( V_14 -> V_119 & 0x1f ) << 16 ) | ( V_14 -> V_120 << 8 ) | V_14 -> V_121 ;
return snprintf ( V_7 , V_114 , L_39 , 'A' + V_118 / 100000 ,
V_118 % 100000 ) ;
}
static T_1
F_69 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
return snprintf ( V_7 , V_114 , L_40 , V_11 -> V_15 -> V_58 -> V_12 ) ;
}
static T_1
F_70 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_114 , L_41 ,
V_14 -> V_122 [ 0 ] , V_14 -> V_122 [ 1 ] , V_14 -> V_122 [ 2 ] ,
V_14 -> V_122 [ 3 ] ) ;
}
static T_1
F_71 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
return snprintf ( V_7 , V_114 , L_37 , V_11 -> V_15 -> V_123 ) ;
}
static T_1
F_72 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
return snprintf ( V_7 , V_114 , L_37 ,
V_11 -> V_15 -> V_124 ? V_11 -> V_15 -> V_124 : L_42 ) ;
}
static T_1
F_73 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
char V_125 [ 30 ] ;
return snprintf ( V_7 , V_114 , L_37 ,
V_11 -> V_15 -> V_33 -> V_126 ( V_11 , V_125 ) ) ;
}
static T_1
F_74 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_89 = 0 ;
if ( F_75 ( & V_11 -> V_127 ) == V_128 ||
F_75 ( & V_11 -> V_127 ) == V_129 ||
V_11 -> V_130 & V_131 )
V_89 = snprintf ( V_7 , V_114 , L_43 ) ;
else if ( F_75 ( & V_11 -> V_127 ) != V_132 ||
F_76 ( V_133 , & V_11 -> V_30 ) ||
F_76 ( V_29 , & V_11 -> V_30 ) )
V_89 = snprintf ( V_7 , V_114 , L_44 ) ;
else {
V_89 = snprintf ( V_7 , V_114 , L_45 ) ;
switch ( V_14 -> V_134 ) {
case V_135 :
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_46 ) ;
break;
case V_136 :
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_47 ) ;
break;
case V_137 :
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 ,
L_48 ) ;
break;
case V_138 :
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_49 ) ;
break;
default:
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_46 ) ;
break;
}
}
return V_89 ;
}
static T_1
F_77 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
int V_89 = 0 ;
switch ( V_11 -> V_15 -> V_139 ) {
case V_140 :
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_50 ) ;
break;
case V_141 :
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_51 ) ;
break;
}
return V_89 ;
}
static T_1
F_78 ( struct V_12 * V_86 , struct V_113 * V_109 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_56 = 0 ;
T_4 V_139 ;
if ( ! F_79 ( V_14 ) )
return - V_142 ;
if ( sscanf ( V_7 , L_52 , & V_56 ) != 1 )
return - V_31 ;
if ( V_56 )
V_139 = V_140 ;
else
V_139 = V_141 ;
if ( V_139 != V_141 || V_14 -> V_139 != V_141 ) {
V_14 -> V_139 = V_139 ;
F_18 ( V_29 , & V_11 -> V_30 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_80 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
return snprintf ( V_7 , V_114 , L_53 , V_11 -> V_15 -> V_143 * 100 ) ;
}
static T_1
F_81 ( struct V_12 * V_86 , struct V_113 * V_109 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
int V_56 = 0 ;
T_4 V_143 ;
if ( sscanf ( V_7 , L_52 , & V_56 ) != 1 )
return - V_31 ;
if ( V_56 > 25500 || V_56 < 100 )
return - V_52 ;
V_143 = ( T_4 ) ( V_56 / 100 ) ;
V_11 -> V_15 -> V_143 = V_143 ;
return strlen ( V_7 ) ;
}
static T_1
F_82 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
int V_89 = 0 ;
if ( V_11 -> V_15 -> V_111 )
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_54 ) ;
else
V_89 += snprintf ( V_7 + V_89 , V_114 - V_89 , L_51 ) ;
return V_89 ;
}
static T_1
F_83 ( struct V_12 * V_86 , struct V_113 * V_109 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_56 = 0 ;
int V_16 ;
if ( F_84 ( V_14 ) || F_85 ( V_14 ) )
return - V_84 ;
if ( F_76 ( V_133 , & V_11 -> V_30 ) ) {
F_9 ( V_43 , V_11 , 0x707a ,
L_55 ) ;
return - V_144 ;
}
if ( sscanf ( V_7 , L_52 , & V_56 ) != 1 )
return - V_31 ;
if ( V_56 )
V_16 = V_14 -> V_33 -> V_145 ( V_11 ) ;
else
V_16 = V_14 -> V_33 -> V_112 ( V_11 ) ;
if ( V_16 != V_42 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_86 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_114 , L_56 , V_14 -> V_146 [ 1 ] ,
V_14 -> V_146 [ 0 ] ) ;
}
static T_1
F_87 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_114 , L_56 , V_14 -> V_147 [ 1 ] ,
V_14 -> V_147 [ 0 ] ) ;
}
static T_1
F_88 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_114 , L_56 , V_14 -> V_148 [ 1 ] ,
V_14 -> V_148 [ 0 ] ) ;
}
static T_1
F_89 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_114 , L_57 ,
V_14 -> V_149 [ 0 ] , V_14 -> V_149 [ 1 ] , V_14 -> V_149 [ 2 ] ,
V_14 -> V_149 [ 3 ] ) ;
}
static T_1
F_90 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_47 ( V_14 ) )
return snprintf ( V_7 , V_114 , L_58 ) ;
return snprintf ( V_7 , V_114 , L_59 ,
V_14 -> V_150 [ 0 ] , V_14 -> V_150 [ 1 ] ,
V_14 -> V_150 [ 2 ] , V_14 -> V_150 [ 3 ] ) ;
}
static T_1
F_91 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_114 , L_60 ,
V_14 -> V_151 . V_152 ) ;
}
static T_1
F_92 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
int V_16 = V_42 ;
T_4 V_153 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_93 ( V_14 ) )
return snprintf ( V_7 , V_114 , L_58 ) ;
if ( V_14 -> V_154 -> V_155 == 0 )
V_16 = F_94 ( V_11 , V_153 ) ;
if ( ( V_16 == V_42 ) && ( V_153 [ 0 ] == 0 ) )
return snprintf ( V_7 , V_114 , L_61 ,
( T_5 ) V_14 -> V_154 -> V_155 ) ;
return snprintf ( V_7 , V_114 , L_58 ) ;
}
static T_1
F_95 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_47 ( V_14 ) )
return snprintf ( V_7 , V_114 , L_58 ) ;
return snprintf ( V_7 , V_114 , L_62 ,
V_14 -> V_156 [ 0 ] , V_14 -> V_156 [ 1 ] , V_14 -> V_156 [ 2 ] ,
V_14 -> V_157 ) ;
}
static T_1
F_96 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_47 ( V_14 ) )
return snprintf ( V_7 , V_114 , L_58 ) ;
return snprintf ( V_7 , V_114 , L_63 ,
V_14 -> V_158 [ 0 ] , V_14 -> V_158 [ 1 ] , V_14 -> V_158 [ 2 ] ) ;
}
static T_1
F_97 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_114 , L_64 , V_14 -> V_159 ) ;
}
static T_1
F_98 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
if ( ! F_37 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_114 , L_58 ) ;
return snprintf ( V_7 , V_114 , L_60 , V_11 -> V_160 ) ;
}
static T_1
F_99 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
if ( ! F_37 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_114 , L_58 ) ;
return snprintf ( V_7 , V_114 , L_65 ,
V_11 -> V_161 [ 5 ] , V_11 -> V_161 [ 4 ] ,
V_11 -> V_161 [ 3 ] , V_11 -> V_161 [ 2 ] ,
V_11 -> V_161 [ 1 ] , V_11 -> V_161 [ 0 ] ) ;
}
static T_1
F_100 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
return snprintf ( V_7 , V_114 , L_60 , V_11 -> V_15 -> V_162 ) ;
}
static T_1
F_101 ( struct V_12 * V_86 ,
struct V_113 * V_109 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
int V_16 = V_163 ;
T_4 V_164 , V_165 ;
if ( ! V_11 -> V_15 -> V_166 . V_167 )
return snprintf ( V_7 , V_114 , L_58 ) ;
V_164 = V_165 = 0 ;
if ( F_76 ( V_133 , & V_11 -> V_30 ) ||
F_76 ( V_29 , & V_11 -> V_30 ) )
F_9 ( V_43 , V_11 , 0x707b ,
L_66 ) ;
else if ( ! V_11 -> V_15 -> V_166 . V_168 )
V_16 = F_102 ( V_11 , & V_164 , & V_165 ) ;
if ( V_16 != V_42 )
V_164 = V_165 = 0 ;
return snprintf ( V_7 , V_114 , L_56 , V_164 , V_165 ) ;
}
static T_1
F_103 ( struct V_12 * V_86 , struct V_113 * V_109 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_66 ( V_86 ) ) ;
int V_16 = V_163 ;
T_4 V_169 [ 5 ] ;
if ( F_76 ( V_133 , & V_11 -> V_30 ) ||
F_76 ( V_29 , & V_11 -> V_30 ) )
F_9 ( V_43 , V_11 , 0x707c ,
L_66 ) ;
else if ( ! V_11 -> V_15 -> V_166 . V_168 )
V_16 = F_104 ( V_11 , V_169 ) ;
if ( V_16 != V_42 )
memset ( V_169 , - 1 , sizeof( V_169 ) ) ;
return snprintf ( V_7 , V_114 , L_67 , V_169 [ 0 ] ,
V_169 [ 1 ] , V_169 [ 2 ] , V_169 [ 3 ] , V_169 [ 4 ] ) ;
}
static void
F_105 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
F_106 ( V_170 ) = V_11 -> V_171 . V_172 . V_173 << 16 |
V_11 -> V_171 . V_172 . V_174 << 8 | V_11 -> V_171 . V_172 . V_175 ;
}
static void
F_107 ( struct V_102 * V_170 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_170 ) ) ) -> V_15 ;
T_8 V_176 = V_177 ;
switch ( V_14 -> V_178 ) {
case V_179 :
V_176 = V_180 ;
break;
case V_181 :
V_176 = V_182 ;
break;
case V_183 :
V_176 = V_184 ;
break;
case V_185 :
V_176 = V_186 ;
break;
case V_187 :
V_176 = V_188 ;
break;
}
F_108 ( V_170 ) = V_176 ;
}
static void
F_109 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
T_5 V_189 = V_190 ;
if ( V_11 -> V_191 ) {
F_110 ( V_170 ) = V_192 ;
return;
}
switch ( V_11 -> V_15 -> V_134 ) {
case V_135 :
V_189 = V_193 ;
break;
case V_136 :
V_189 = V_194 ;
break;
case V_137 :
V_189 = V_195 ;
break;
case V_138 :
V_189 = V_196 ;
break;
}
F_110 ( V_170 ) = V_189 ;
}
static void
F_111 ( struct V_197 * V_198 )
{
struct V_102 * V_83 = F_3 ( V_198 -> V_86 . V_199 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_200 ;
T_10 V_201 = 0 ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_200 -> V_202 &&
V_198 -> V_203 == V_200 -> V_202 -> V_204 ) {
V_201 = F_113 ( V_200 -> V_201 ) ;
break;
}
}
F_114 ( V_198 ) = V_201 ;
}
static void
F_115 ( struct V_197 * V_198 )
{
struct V_102 * V_83 = F_3 ( V_198 -> V_86 . V_199 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_200 ;
T_10 V_205 = 0 ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_200 -> V_202 &&
V_198 -> V_203 == V_200 -> V_202 -> V_204 ) {
V_205 = F_113 ( V_200 -> V_205 ) ;
break;
}
}
F_116 ( V_198 ) = V_205 ;
}
static void
F_117 ( struct V_197 * V_198 )
{
struct V_102 * V_83 = F_3 ( V_198 -> V_86 . V_199 ) ;
T_7 * V_11 = F_2 ( V_83 ) ;
T_9 * V_200 ;
T_5 V_206 = ~ 0U ;
F_112 (fcport, &vha->vp_fcports, list) {
if ( V_200 -> V_202 &&
V_198 -> V_203 == V_200 -> V_202 -> V_204 ) {
V_206 = V_200 -> V_171 . V_172 . V_173 << 16 |
V_200 -> V_171 . V_172 . V_174 << 8 | V_200 -> V_171 . V_172 . V_175 ;
break;
}
}
F_118 ( V_198 ) = V_206 ;
}
static void
F_119 ( struct V_207 * V_202 , T_5 V_208 )
{
if ( V_208 )
V_202 -> V_209 = V_208 ;
else
V_202 -> V_209 = 1 ;
}
static void
F_120 ( struct V_207 * V_202 )
{
struct V_102 * V_83 = F_121 ( V_202 ) ;
T_9 * V_200 = * ( T_9 * * ) V_202 -> V_210 ;
unsigned long V_166 ;
if ( ! V_200 )
return;
F_122 ( V_200 , V_211 ) ;
F_123 ( V_83 -> V_212 , V_166 ) ;
V_200 -> V_202 = V_200 -> V_213 = NULL ;
* ( ( T_9 * * ) V_202 -> V_210 ) = NULL ;
F_124 ( V_83 -> V_212 , V_166 ) ;
if ( F_76 ( V_133 , & V_200 -> V_11 -> V_30 ) )
return;
if ( F_32 ( F_33 ( V_200 -> V_11 -> V_15 -> V_58 ) ) ) {
F_125 ( V_200 -> V_11 , V_214 << 16 ) ;
return;
}
}
static void
F_126 ( struct V_207 * V_202 )
{
T_9 * V_200 = * ( T_9 * * ) V_202 -> V_210 ;
if ( ! V_200 )
return;
if ( F_76 ( V_133 , & V_200 -> V_11 -> V_30 ) )
return;
if ( F_32 ( F_33 ( V_200 -> V_11 -> V_15 -> V_58 ) ) ) {
F_125 ( V_200 -> V_11 , V_214 << 16 ) ;
return;
}
if ( V_200 -> V_215 != V_216 &&
! F_76 ( V_217 , & V_200 -> V_11 -> V_30 ) )
V_200 -> V_11 -> V_15 -> V_33 -> V_218 ( V_200 -> V_11 ,
V_200 -> V_215 , V_200 -> V_171 . V_172 . V_173 ,
V_200 -> V_171 . V_172 . V_174 , V_200 -> V_171 . V_172 . V_175 ) ;
}
static int
F_127 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
F_128 ( V_11 ) ;
return 0 ;
}
static struct V_219 *
F_129 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_82 = F_44 ( V_14 -> V_58 ) ;
int V_16 ;
struct V_220 * V_221 ;
T_11 V_222 ;
struct V_219 * V_223 ;
V_223 = & V_14 -> V_224 ;
memset ( V_223 , - 1 , sizeof( struct V_219 ) ) ;
if ( F_76 ( V_217 , & V_11 -> V_30 ) )
goto V_225;
if ( F_32 ( F_33 ( V_14 -> V_58 ) ) )
goto V_225;
V_221 = F_41 ( V_14 -> V_77 , V_78 , & V_222 ) ;
if ( V_221 == NULL ) {
F_9 ( V_43 , V_11 , 0x707d ,
L_68 ) ;
goto V_225;
}
memset ( V_221 , 0 , V_94 ) ;
V_16 = V_163 ;
if ( F_23 ( V_14 ) ) {
V_16 = F_130 ( V_82 , V_221 , V_222 ) ;
} else if ( F_75 ( & V_82 -> V_127 ) == V_132 &&
! F_76 ( V_133 , & V_82 -> V_30 ) &&
! F_76 ( V_29 , & V_82 -> V_30 ) &&
! V_14 -> V_226 ) {
V_16 = F_131 ( V_82 , V_82 -> V_215 ,
V_221 , V_222 ) ;
}
if ( V_16 != V_42 )
goto V_227;
V_223 -> V_228 = V_221 -> V_229 ;
V_223 -> V_230 = V_221 -> V_231 ;
V_223 -> V_232 = V_221 -> V_233 ;
V_223 -> V_234 = V_221 -> V_235 ;
V_223 -> V_236 = V_221 -> V_237 ;
V_223 -> V_238 = V_221 -> V_239 ;
if ( F_23 ( V_14 ) ) {
V_223 -> V_240 = V_221 -> V_241 ;
V_223 -> V_242 = V_221 -> V_242 ;
V_223 -> V_243 = V_221 -> V_243 ;
V_223 -> V_244 = V_221 -> V_244 ;
V_223 -> V_245 = V_221 -> V_246 ;
}
V_223 -> V_247 = V_14 -> V_151 . V_248 >> 20 ;
V_223 -> V_249 = V_14 -> V_151 . V_250 >> 20 ;
V_227:
F_132 ( V_14 -> V_77 , V_221 , V_222 ) ;
V_225:
return V_223 ;
}
static void
F_133 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
F_134 ( V_11 , F_135 ( V_170 ) ) ;
}
static void
F_136 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
F_18 ( V_251 , & V_11 -> V_30 ) ;
}
static void
F_137 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
T_6 V_201 [ V_252 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_253 = F_113 ( V_201 ) ;
if ( V_11 -> V_130 & V_254 )
V_253 = F_113 ( V_11 -> V_255 ) ;
F_138 ( V_170 ) = V_253 ;
}
static void
F_139 ( struct V_102 * V_170 )
{
T_7 * V_11 = F_2 ( V_170 ) ;
struct V_10 * V_82 = F_44 ( V_11 -> V_15 -> V_58 ) ;
if ( ! V_82 -> V_166 . V_256 ) {
F_140 ( V_170 ) = V_257 ;
return;
}
switch ( F_75 ( & V_82 -> V_127 ) ) {
case V_258 :
F_140 ( V_170 ) = V_259 ;
break;
case V_128 :
if ( F_76 ( V_260 , & V_82 -> V_30 ) )
F_140 ( V_170 ) = V_259 ;
else
F_140 ( V_170 ) = V_261 ;
break;
case V_129 :
F_140 ( V_170 ) = V_261 ;
break;
case V_132 :
F_140 ( V_170 ) = V_262 ;
break;
default:
F_140 ( V_170 ) = V_263 ;
break;
}
}
static int
F_141 ( struct V_264 * V_264 , bool V_265 )
{
int V_104 = 0 ;
T_6 V_266 = 0 ;
T_7 * V_82 = F_2 ( V_264 -> V_170 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_82 -> V_15 ;
T_4 V_267 = 0 ;
int V_38 ;
struct V_268 * V_269 = V_14 -> V_270 [ 0 ] ;
V_104 = F_142 ( V_264 ) ;
if ( V_104 ) {
F_9 ( V_43 , V_11 , 0x707e ,
L_69 , V_104 ) ;
return ( V_104 ) ;
}
V_11 = F_143 ( V_264 ) ;
if ( V_11 == NULL ) {
F_9 ( V_43 , V_11 , 0x707f , L_70 ) ;
return V_271 ;
}
if ( V_265 ) {
F_144 ( & V_11 -> V_272 , V_273 ) ;
F_145 ( V_264 , V_274 ) ;
} else
F_144 ( & V_11 -> V_272 , V_275 ) ;
F_9 ( V_25 , V_11 , 0x7080 ,
L_71 , V_11 -> V_191 ) ;
F_144 ( & V_11 -> V_127 , V_128 ) ;
V_11 -> V_276 = V_277 ;
V_11 -> V_278 = V_279 ;
if ( F_75 ( & V_82 -> V_127 ) == V_128 ||
F_75 ( & V_82 -> V_127 ) == V_129 ) {
F_17 ( V_28 , V_11 , 0x7081 ,
L_72 ) ;
F_144 ( & V_11 -> V_127 , V_129 ) ;
if ( ! V_265 )
F_145 ( V_264 , V_280 ) ;
}
if ( F_146 ( V_14 ) && V_281 ) {
if ( V_14 -> V_282 & V_283 ) {
int V_284 = 0 ;
V_11 -> V_166 . V_285 = 1 ;
F_17 ( V_28 , V_11 , 0x7082 ,
L_73 ) ;
if ( V_281 == 1 )
V_284 = V_286 ;
F_147 ( V_11 -> V_83 ,
V_284 | V_287
| V_288
| V_289
| V_290
| V_291
| V_292 ) ;
F_148 ( V_11 -> V_83 , V_293 ) ;
} else
V_11 -> V_166 . V_285 = 0 ;
}
if ( F_149 ( V_11 -> V_83 , & V_264 -> V_86 ,
& V_14 -> V_58 -> V_86 ) ) {
F_17 ( V_28 , V_11 , 0x7083 ,
L_74 , V_11 -> V_191 ) ;
goto V_294;
}
F_150 ( V_11 -> V_83 ) = V_14 -> V_295 ;
F_151 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_201 ) ;
F_152 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_205 ) ;
F_153 ( V_11 -> V_83 ) =
F_153 ( V_82 -> V_83 ) ;
F_154 ( V_11 -> V_83 ) =
F_154 ( V_82 -> V_83 ) ;
F_155 ( V_264 , V_265 ) ;
if ( V_14 -> V_166 . V_296 ) {
V_269 = V_14 -> V_270 [ 1 ] ;
F_17 ( V_297 , V_11 , 0xc000 ,
L_75
L_76 ,
V_269 , V_11 -> V_191 , V_14 -> V_166 . V_296 ) ;
goto V_298;
} else if ( V_299 == 1 || ! V_14 -> V_300 )
goto V_298;
for ( V_38 = 0 ; V_38 < V_14 -> V_301 ; V_38 ++ ) {
if ( memcmp ( V_14 -> V_300 [ V_38 ] . V_205 , V_11 -> V_205 , 8 ) == 0
&& memcmp ( V_14 -> V_300 [ V_38 ] . V_201 , V_11 -> V_201 ,
8 ) == 0 ) {
V_266 = V_14 -> V_300 [ V_38 ] . V_302 ;
break;
}
}
if ( V_266 ) {
V_104 = F_156 ( V_14 , V_267 , V_11 -> V_191 , 0 , 0 ,
V_266 ) ;
if ( ! V_104 )
F_9 ( V_43 , V_11 , 0x7084 ,
L_77 ,
V_11 -> V_191 ) ;
else {
F_17 ( V_297 , V_11 , 0xc001 ,
L_78 ,
V_104 , V_266 , V_11 -> V_191 ) ;
F_17 ( V_28 , V_11 , 0x7085 ,
L_78 ,
V_104 , V_266 , V_11 -> V_191 ) ;
V_269 = V_14 -> V_270 [ V_104 ] ;
}
}
V_298:
V_11 -> V_269 = V_269 ;
return 0 ;
V_294:
F_157 ( V_11 ) ;
F_158 ( V_11 ) ;
F_159 ( V_11 -> V_83 ) ;
return V_271 ;
}
static int
F_160 ( struct V_264 * V_264 )
{
T_7 * V_11 = V_264 -> V_210 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_203 = V_11 -> V_191 ;
while ( F_76 ( V_303 , & V_11 -> V_30 ) ||
F_76 ( V_304 , & V_11 -> V_30 ) )
F_161 ( 1000 ) ;
F_157 ( V_11 ) ;
V_11 -> V_166 . V_305 = 1 ;
F_162 ( V_11 -> V_83 ) ;
F_163 ( V_11 -> V_83 ) ;
F_158 ( V_11 ) ;
if ( V_11 -> V_306 ) {
F_164 ( V_11 ) ;
F_17 ( V_28 , V_11 , 0x7086 ,
L_79 , V_11 -> V_191 ) ;
}
if ( V_307 & V_28 )
F_161 ( F_165 () % 10 ) ;
F_166 ( F_75 ( & V_11 -> V_308 ) ) ;
F_167 ( V_11 ) ;
F_168 ( & V_14 -> V_309 ) ;
V_14 -> V_310 -- ;
F_169 ( V_11 -> V_191 , V_14 -> V_311 ) ;
F_170 ( & V_14 -> V_309 ) ;
if ( V_11 -> V_269 -> V_203 && ! V_14 -> V_166 . V_296 ) {
if ( F_171 ( V_11 , V_11 -> V_269 ) != V_42 )
F_9 ( V_43 , V_11 , 0x7087 ,
L_80 ) ;
}
F_159 ( V_11 -> V_83 ) ;
F_9 ( V_25 , V_11 , 0x7088 , L_81 , V_203 ) ;
return 0 ;
}
static int
F_155 ( struct V_264 * V_264 , bool V_265 )
{
T_7 * V_11 = V_264 -> V_210 ;
if ( V_265 )
F_157 ( V_11 ) ;
else
F_172 ( V_11 ) ;
return 0 ;
}
void
F_173 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_176 = V_177 ;
F_150 ( V_11 -> V_83 ) = V_14 -> V_295 ;
F_151 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_201 ) ;
F_152 ( V_11 -> V_83 ) = F_113 ( V_11 -> V_205 ) ;
F_153 ( V_11 -> V_83 ) = V_312 ;
F_174 ( V_11 -> V_83 ) = V_14 -> V_313 ;
F_175 ( V_11 -> V_83 ) = V_14 -> V_310 ;
if ( F_37 ( V_14 ) )
V_176 = V_188 ;
else if ( F_36 ( V_14 ) )
V_176 = V_186 | V_184 |
V_182 | V_180 ;
else if ( F_176 ( V_14 ) )
V_176 = V_184 | V_182 |
V_180 ;
else if ( F_177 ( V_14 ) )
V_176 = V_182 | V_180 ;
else
V_176 = V_180 ;
F_154 ( V_11 -> V_83 ) = V_176 ;
}
