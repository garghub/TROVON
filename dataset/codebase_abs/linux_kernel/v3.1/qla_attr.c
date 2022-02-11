static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 -> V_16 == 0 )
return 0 ;
return F_5 ( V_7 , V_9 , & V_8 , V_14 -> V_17 ,
V_14 -> V_18 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_19 ;
if ( F_7 ( V_14 ) ) {
F_8 ( V_20 , V_11 , 0x705b ,
L_1 ) ;
return V_9 ;
}
if ( V_8 != 0 )
return ( 0 ) ;
V_19 = F_9 ( V_7 , NULL , 10 ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_14 -> V_16 )
break;
F_10 ( V_21 , V_11 , 0x705d ,
L_2 , V_11 -> V_22 ) ;
V_14 -> V_16 = 0 ;
V_14 -> V_23 = 0 ;
break;
case 1 :
if ( V_14 -> V_23 && ! V_14 -> V_16 ) {
V_14 -> V_16 = 1 ;
F_10 ( V_21 , V_11 , 0x705e ,
L_3 ,
V_11 -> V_22 ) ;
}
break;
case 2 :
F_11 ( V_11 ) ;
break;
case 3 :
F_12 ( V_11 ) ;
break;
}
return ( V_9 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_14 ( V_24 ) )
return 0 ;
if ( F_15 ( V_14 ) )
V_14 -> V_25 -> V_26 ( V_11 , V_14 -> V_27 , V_14 -> V_28 << 2 ,
V_14 -> V_29 ) ;
return F_5 ( V_7 , V_9 , & V_8 , V_14 -> V_27 ,
V_14 -> V_29 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_30 ;
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 != V_14 -> V_29 ||
! V_14 -> V_25 -> V_31 )
return 0 ;
if ( F_17 ( V_14 ) ) {
T_5 * V_32 ;
T_5 V_33 ;
V_32 = ( T_5 * ) V_7 ;
V_33 = 0 ;
for ( V_30 = 0 ; V_30 < ( ( V_9 >> 2 ) - 1 ) ; V_30 ++ )
V_33 += F_18 ( * V_32 ++ ) ;
V_33 = ~ V_33 + 1 ;
* V_32 = F_19 ( V_33 ) ;
} else {
T_6 * V_32 ;
T_6 V_33 ;
V_32 = ( T_6 * ) V_7 ;
V_33 = 0 ;
for ( V_30 = 0 ; V_30 < V_9 - 1 ; V_30 ++ )
V_33 += * V_32 ++ ;
V_33 = ~ V_33 + 1 ;
* V_32 = V_33 ;
}
if ( F_20 ( V_11 ) != V_34 ) {
F_10 ( V_35 , V_11 , 0x705f ,
L_4 ) ;
return - V_36 ;
}
V_14 -> V_25 -> V_31 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_37 , V_9 ) ;
V_14 -> V_25 -> V_38 ( V_11 , ( T_6 * ) V_14 -> V_27 , V_14 -> V_37 ,
V_9 ) ;
F_8 ( V_20 , V_11 , 0x7060 ,
L_5 ) ;
F_21 ( V_39 , & V_11 -> V_40 ) ;
F_22 ( V_11 ) ;
F_23 ( V_11 ) ;
return ( V_9 ) ;
}
static T_1
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 -> V_41 != V_42 )
return 0 ;
return F_5 ( V_7 , V_9 , & V_8 , V_14 -> V_43 ,
V_14 -> V_44 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 -> V_41 != V_45 )
return - V_46 ;
if ( V_8 > V_14 -> V_44 )
return - V_47 ;
if ( V_8 + V_9 > V_14 -> V_44 )
V_9 = V_14 -> V_44 - V_8 ;
memcpy ( & V_14 -> V_43 [ V_8 ] , V_7 , V_9 ) ;
return V_9 ;
}
static T_1
F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_48 = 0 ;
T_5 V_49 = V_14 -> V_50 ;
int V_51 , V_52 ;
if ( V_8 )
return 0 ;
if ( F_27 ( F_28 ( V_14 -> V_53 ) ) )
return 0 ;
if ( sscanf ( V_7 , L_6 , & V_51 , & V_48 , & V_49 ) < 1 )
return - V_46 ;
if ( V_48 > V_14 -> V_50 )
return - V_46 ;
switch ( V_51 ) {
case 0 :
if ( V_14 -> V_41 != V_42 &&
V_14 -> V_41 != V_45 )
break;
V_14 -> V_41 = V_54 ;
F_8 ( V_20 , V_11 , 0x7061 ,
L_7 ,
V_14 -> V_44 ) ;
F_29 ( V_14 -> V_43 ) ;
V_14 -> V_43 = NULL ;
break;
case 1 :
if ( V_14 -> V_41 != V_54 )
break;
V_14 -> V_55 = V_48 ;
V_14 -> V_44 = V_48 + V_49 > V_14 -> V_50 ?
V_14 -> V_50 - V_48 : V_49 ;
V_14 -> V_41 = V_42 ;
V_14 -> V_43 = F_30 ( V_14 -> V_44 ) ;
if ( V_14 -> V_43 == NULL ) {
F_10 ( V_35 , V_11 , 0x7062 ,
L_8
L_9 , V_14 -> V_44 ) ;
V_14 -> V_41 = V_54 ;
return V_9 ;
}
if ( F_20 ( V_11 ) != V_34 ) {
F_10 ( V_35 , V_11 , 0x7063 ,
L_4 ) ;
return - V_36 ;
}
F_8 ( V_20 , V_11 , 0x7064 ,
L_10 ,
V_14 -> V_55 , V_14 -> V_44 ) ;
memset ( V_14 -> V_43 , 0 , V_14 -> V_44 ) ;
V_14 -> V_25 -> V_26 ( V_11 , V_14 -> V_43 ,
V_14 -> V_55 , V_14 -> V_44 ) ;
break;
case 2 :
if ( V_14 -> V_41 != V_54 )
break;
V_52 = 0 ;
if ( V_14 -> V_50 == V_56 && V_48 == 0 )
V_52 = 1 ;
else if ( V_48 == ( V_14 -> V_57 * 4 ) ||
V_48 == ( V_14 -> V_58 * 4 ) )
V_52 = 1 ;
else if ( F_31 ( V_14 ) || F_32 ( V_14 ) )
V_52 = 1 ;
if ( ! V_52 ) {
F_10 ( V_35 , V_11 , 0x7065 ,
L_11 , V_48 , V_49 ) ;
return - V_46 ;
}
V_14 -> V_55 = V_48 ;
V_14 -> V_44 = V_48 + V_49 > V_14 -> V_50 ?
V_14 -> V_50 - V_48 : V_49 ;
V_14 -> V_41 = V_45 ;
V_14 -> V_43 = F_30 ( V_14 -> V_44 ) ;
if ( V_14 -> V_43 == NULL ) {
F_10 ( V_35 , V_11 , 0x7066 ,
L_12
L_13 , V_14 -> V_44 ) ;
V_14 -> V_41 = V_54 ;
return V_9 ;
}
F_8 ( V_20 , V_11 , 0x7067 ,
L_14 ,
V_14 -> V_55 , V_14 -> V_44 ) ;
memset ( V_14 -> V_43 , 0 , V_14 -> V_44 ) ;
break;
case 3 :
if ( V_14 -> V_41 != V_45 )
break;
if ( F_20 ( V_11 ) != V_34 ) {
F_10 ( V_35 , V_11 , 0x7068 ,
L_15 ) ;
return - V_36 ;
}
F_8 ( V_20 , V_11 , 0x7069 ,
L_16 ,
V_14 -> V_55 , V_14 -> V_44 ) ;
V_14 -> V_25 -> V_59 ( V_11 , V_14 -> V_43 ,
V_14 -> V_55 , V_14 -> V_44 ) ;
break;
default:
V_9 = - V_46 ;
}
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
if ( F_27 ( F_28 ( V_14 -> V_53 ) ) )
return 0 ;
if ( ! F_14 ( V_24 ) )
return 0 ;
if ( F_15 ( V_14 ) )
V_14 -> V_25 -> V_26 ( V_11 , V_14 -> V_60 , V_14 -> V_61 << 2 ,
V_14 -> V_62 ) ;
return F_5 ( V_7 , V_9 , & V_8 , V_14 -> V_60 , V_14 -> V_62 ) ;
}
static T_1
F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_63 ;
if ( F_27 ( F_28 ( V_14 -> V_53 ) ) )
return 0 ;
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 != V_14 -> V_62 ||
! V_14 -> V_25 -> V_31 )
return 0 ;
if ( F_20 ( V_11 ) != V_34 ) {
F_10 ( V_35 , V_11 , 0x706a ,
L_17 ) ;
return - V_36 ;
}
V_14 -> V_25 -> V_31 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_64 , V_9 ) ;
V_14 -> V_25 -> V_38 ( V_11 , ( T_6 * ) V_14 -> V_60 , V_14 -> V_64 , V_9 ) ;
if ( ! F_17 ( V_14 ) )
goto V_65;
V_63 = F_30 ( 256 ) ;
if ( ! V_63 ) {
F_10 ( V_35 , V_11 , 0x706b ,
L_18 ) ;
goto V_65;
}
V_14 -> V_25 -> V_66 ( V_11 , V_63 ) ;
F_29 ( V_63 ) ;
V_65:
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
T_4 V_32 , V_67 , V_68 ;
int V_69 ;
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 != V_70 * 2 )
return 0 ;
if ( V_14 -> V_71 )
goto V_72;
V_14 -> V_71 = F_36 ( V_14 -> V_73 , V_74 ,
& V_14 -> V_75 ) ;
if ( ! V_14 -> V_71 ) {
F_10 ( V_35 , V_11 , 0x706c ,
L_19 ) ;
return 0 ;
}
V_72:
memset ( V_14 -> V_71 , 0 , V_76 ) ;
V_67 = 0xa0 ;
for ( V_32 = 0 , V_68 = 0 ; V_32 < ( V_70 * 2 ) / V_76 ;
V_32 ++ , V_68 += V_76 ) {
if ( V_32 == 4 ) {
V_67 = 0xa2 ;
V_68 = 0 ;
}
V_69 = F_37 ( V_11 , V_14 -> V_75 , V_14 -> V_71 ,
V_67 , V_68 , V_76 , 0 ) ;
if ( V_69 != V_34 ) {
F_10 ( V_35 , V_11 , 0x706d ,
L_20 , V_69 ,
V_67 , V_68 ) ;
V_9 = 0 ;
break;
}
memcpy ( V_7 , V_14 -> V_71 , V_76 ) ;
V_7 += V_76 ;
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
struct V_10 * V_77 = F_39 ( V_14 -> V_53 ) ;
int type ;
if ( V_8 != 0 )
return 0 ;
type = F_9 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_10 ( V_21 , V_11 , 0x706e ,
L_21 ) ;
F_40 ( V_11 -> V_78 ) ;
F_21 ( V_39 , & V_11 -> V_40 ) ;
F_22 ( V_11 ) ;
F_23 ( V_11 ) ;
F_41 ( V_11 -> V_78 ) ;
break;
case 0x2025d :
if ( ! F_42 ( V_14 ) )
break;
F_10 ( V_21 , V_11 , 0x706f ,
L_22 ) ;
F_20 ( V_11 ) ;
F_40 ( V_11 -> V_78 ) ;
if ( F_43 ( V_11 ) != V_34 )
F_10 ( V_35 , V_11 , 0x7070 ,
L_23 ) ;
F_41 ( V_11 -> V_78 ) ;
break;
case 0x2025e :
if ( ! F_7 ( V_14 ) || V_11 != V_77 ) {
F_10 ( V_21 , V_11 , 0x7071 ,
L_24 ) ;
return V_9 ;
}
F_10 ( V_21 , V_11 , 0x7072 ,
L_25 ) ;
F_21 ( V_79 , & V_11 -> V_40 ) ;
F_22 ( V_11 ) ;
F_44 ( V_11 ) ;
break;
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
T_4 V_80 , V_81 , V_82 , V_83 ;
int V_69 ;
V_14 -> V_84 = 0 ;
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 < 8 )
return 0 ;
if ( ! V_14 -> V_85 ) {
V_14 -> V_85 = F_36 ( V_14 -> V_73 , V_74 ,
& V_14 -> V_86 ) ;
if ( ! V_14 -> V_85 ) {
F_10 ( V_35 , V_11 , 0x7073 ,
L_26 ) ;
return 0 ;
}
}
V_80 = F_46 ( ( void * ) & V_7 [ 0 ] ) ;
V_81 = F_46 ( ( void * ) & V_7 [ 2 ] ) ;
V_82 = F_46 ( ( void * ) & V_7 [ 4 ] ) ;
V_83 = F_46 ( ( void * ) & V_7 [ 6 ] ) ;
if ( ! ( V_82 & V_87 ) )
if ( V_83 == 0 || V_83 > V_88 || V_83 > V_9 - 8 )
return - V_46 ;
memcpy ( V_14 -> V_85 , & V_7 [ 8 ] , V_83 ) ;
V_69 = F_47 ( V_11 , V_14 -> V_86 , V_14 -> V_85 ,
V_80 , V_81 , V_83 , V_82 ) ;
if ( V_69 != V_34 ) {
F_10 ( V_35 , V_11 , 0x7074 ,
L_27 ,
V_69 , V_80 , V_81 , V_82 , V_83 , V_7 [ 8 ] ) ;
return 0 ;
}
return V_9 ;
}
static T_1
F_48 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_80 , V_81 , V_82 , V_83 ;
int V_69 ;
V_14 -> V_84 = 0 ;
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 < 8 )
return 0 ;
if ( ! V_14 -> V_85 ) {
V_14 -> V_85 = F_36 ( V_14 -> V_73 , V_74 ,
& V_14 -> V_86 ) ;
if ( ! V_14 -> V_85 ) {
F_10 ( V_35 , V_11 , 0x708c ,
L_28 ) ;
return 0 ;
}
}
V_80 = F_46 ( ( void * ) & V_7 [ 0 ] ) ;
V_81 = F_46 ( ( void * ) & V_7 [ 2 ] ) ;
V_82 = F_46 ( ( void * ) & V_7 [ 4 ] ) ;
V_83 = F_46 ( ( void * ) & V_7 [ 6 ] ) ;
if ( ! ( V_82 & V_87 ) )
if ( V_83 == 0 || V_83 > V_88 )
return - V_46 ;
memset ( V_14 -> V_85 , 0 , V_83 ) ;
V_69 = F_37 ( V_11 , V_14 -> V_86 , V_14 -> V_85 ,
V_80 , V_81 , V_83 , V_82 ) ;
if ( V_69 != V_34 ) {
F_10 ( V_21 , V_11 , 0x7075 ,
L_29 ,
V_69 , V_80 , V_81 , V_82 , V_83 ) ;
return 0 ;
}
V_14 -> V_84 = V_83 ;
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
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 == 0 )
return 0 ;
if ( ! V_14 -> V_85 || V_14 -> V_84 == 0 || V_14 -> V_84 > V_9 )
return - V_46 ;
memcpy ( V_7 , V_14 -> V_85 , V_14 -> V_84 ) ;
return V_14 -> V_84 ;
}
static T_1
F_50 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_69 ;
T_4 V_89 ;
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 > V_90 )
return 0 ;
if ( V_14 -> V_91 )
goto V_72;
V_14 -> V_91 = F_51 ( & V_14 -> V_53 -> V_80 , V_90 ,
& V_14 -> V_92 , V_74 ) ;
if ( ! V_14 -> V_91 ) {
F_10 ( V_35 , V_11 , 0x7076 ,
L_30 ) ;
return 0 ;
}
V_72:
V_89 = 0 ;
memset ( V_14 -> V_91 , 0 , V_90 ) ;
V_69 = F_52 ( V_11 , V_14 -> V_92 ,
V_90 , & V_89 ) ;
if ( V_69 != V_34 ) {
F_10 ( V_35 , V_11 , 0x7077 ,
L_31 , V_69 ) ;
V_9 = 0 ;
}
V_9 = V_89 > V_9 ? V_9 : V_89 ;
memcpy ( V_7 , V_14 -> V_91 , V_9 ) ;
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
int V_69 ;
T_4 V_89 ;
if ( ! F_14 ( V_24 ) || V_8 != 0 || V_9 > V_93 )
return 0 ;
if ( V_14 -> V_94 )
goto V_72;
V_14 -> V_94 = F_51 ( & V_14 -> V_53 -> V_80 , V_93 ,
& V_14 -> V_95 , V_74 ) ;
if ( ! V_14 -> V_94 ) {
F_10 ( V_35 , V_11 , 0x7078 ,
L_32 ) ;
return 0 ;
}
V_72:
V_89 = 0 ;
memset ( V_14 -> V_94 , 0 , V_93 ) ;
V_69 = F_54 ( V_11 , V_14 -> V_95 ,
V_93 ) ;
if ( V_69 != V_34 ) {
F_10 ( V_35 , V_11 , 0x7079 ,
L_33 , V_69 ) ;
V_9 = 0 ;
}
memcpy ( V_7 , V_14 -> V_94 , V_9 ) ;
return V_9 ;
}
void
F_55 ( T_7 * V_11 )
{
struct V_96 * V_78 = V_11 -> V_78 ;
struct V_97 * V_32 ;
int V_98 ;
for ( V_32 = V_99 ; V_32 -> V_100 ; V_32 ++ ) {
if ( V_32 -> V_101 && ! F_17 ( V_11 -> V_15 ) )
continue;
if ( V_32 -> V_101 == 2 && ! F_31 ( V_11 -> V_15 ) )
continue;
if ( V_32 -> V_101 == 3 && ! ( F_32 ( V_11 -> V_15 ) ) )
continue;
V_98 = F_56 ( & V_78 -> V_102 . V_4 ,
V_32 -> V_103 ) ;
if ( V_98 )
F_10 ( V_35 , V_11 , 0x00f3 ,
L_34 ,
V_32 -> V_100 , V_98 ) ;
else
F_8 ( V_104 , V_11 , 0x00f4 ,
L_35 ,
V_32 -> V_100 ) ;
}
}
void
F_57 ( T_7 * V_11 )
{
struct V_96 * V_78 = V_11 -> V_78 ;
struct V_97 * V_32 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_32 = V_99 ; V_32 -> V_100 ; V_32 ++ ) {
if ( V_32 -> V_101 && ! F_17 ( V_14 ) )
continue;
if ( V_32 -> V_101 == 2 && ! F_31 ( V_14 ) )
continue;
if ( V_32 -> V_101 == 3 && ! ! ( F_32 ( V_11 -> V_15 ) ) )
continue;
F_58 ( & V_78 -> V_102 . V_4 ,
V_32 -> V_103 ) ;
}
if ( V_14 -> V_105 == 1 )
V_14 -> V_25 -> V_106 ( V_11 ) ;
}
static T_1
F_59 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
return snprintf ( V_7 , V_108 , L_36 , V_109 ) ;
}
static T_1
F_60 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_110 [ 128 ] ;
return snprintf ( V_7 , V_108 , L_36 ,
V_14 -> V_25 -> V_111 ( V_11 , V_110 ) ) ;
}
static T_1
F_62 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_112 ;
if ( F_17 ( V_14 ) ) {
F_63 ( V_11 , L_37 , V_7 , V_108 ) ;
return snprintf ( V_7 , V_108 , L_36 , V_7 ) ;
}
V_112 = ( ( V_14 -> V_113 & 0x1f ) << 16 ) | ( V_14 -> V_114 << 8 ) | V_14 -> V_115 ;
return snprintf ( V_7 , V_108 , L_38 , 'A' + V_112 / 100000 ,
V_112 % 100000 ) ;
}
static T_1
F_64 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
return snprintf ( V_7 , V_108 , L_39 , V_11 -> V_15 -> V_53 -> V_12 ) ;
}
static T_1
F_65 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_40 ,
V_14 -> V_116 [ 0 ] , V_14 -> V_116 [ 1 ] , V_14 -> V_116 [ 2 ] ,
V_14 -> V_116 [ 3 ] ) ;
}
static T_1
F_66 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
return snprintf ( V_7 , V_108 , L_36 , V_11 -> V_15 -> V_117 ) ;
}
static T_1
F_67 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
return snprintf ( V_7 , V_108 , L_36 ,
V_11 -> V_15 -> V_118 ? V_11 -> V_15 -> V_118 : L_41 ) ;
}
static T_1
F_68 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
char V_119 [ 30 ] ;
return snprintf ( V_7 , V_108 , L_36 ,
V_11 -> V_15 -> V_25 -> V_120 ( V_11 , V_119 ) ) ;
}
static T_1
F_69 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_83 = 0 ;
if ( F_70 ( & V_11 -> V_121 ) == V_122 ||
F_70 ( & V_11 -> V_121 ) == V_123 ||
V_11 -> V_124 & V_125 )
V_83 = snprintf ( V_7 , V_108 , L_42 ) ;
else if ( F_70 ( & V_11 -> V_121 ) != V_126 ||
F_71 ( V_127 , & V_11 -> V_40 ) ||
F_71 ( V_39 , & V_11 -> V_40 ) )
V_83 = snprintf ( V_7 , V_108 , L_43 ) ;
else {
V_83 = snprintf ( V_7 , V_108 , L_44 ) ;
switch ( V_14 -> V_128 ) {
case V_129 :
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_45 ) ;
break;
case V_130 :
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_46 ) ;
break;
case V_131 :
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 ,
L_47 ) ;
break;
case V_132 :
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_48 ) ;
break;
default:
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_45 ) ;
break;
}
}
return V_83 ;
}
static T_1
F_72 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
int V_83 = 0 ;
switch ( V_11 -> V_15 -> V_133 ) {
case V_134 :
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_49 ) ;
break;
case V_135 :
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_50 ) ;
break;
}
return V_83 ;
}
static T_1
F_73 ( struct V_12 * V_80 , struct V_107 * V_103 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_51 = 0 ;
T_4 V_133 ;
if ( ! F_74 ( V_14 ) )
return - V_136 ;
if ( sscanf ( V_7 , L_51 , & V_51 ) != 1 )
return - V_46 ;
if ( V_51 )
V_133 = V_134 ;
else
V_133 = V_135 ;
if ( V_133 != V_135 || V_14 -> V_133 != V_135 ) {
V_14 -> V_133 = V_133 ;
F_21 ( V_39 , & V_11 -> V_40 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_75 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
return snprintf ( V_7 , V_108 , L_52 , V_11 -> V_15 -> V_137 * 100 ) ;
}
static T_1
F_76 ( struct V_12 * V_80 , struct V_107 * V_103 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
int V_51 = 0 ;
T_4 V_137 ;
if ( sscanf ( V_7 , L_51 , & V_51 ) != 1 )
return - V_46 ;
if ( V_51 > 25500 || V_51 < 100 )
return - V_47 ;
V_137 = ( T_4 ) ( V_51 / 100 ) ;
V_11 -> V_15 -> V_137 = V_137 ;
return strlen ( V_7 ) ;
}
static T_1
F_77 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
int V_83 = 0 ;
if ( V_11 -> V_15 -> V_105 )
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_53 ) ;
else
V_83 += snprintf ( V_7 + V_83 , V_108 - V_83 , L_50 ) ;
return V_83 ;
}
static T_1
F_78 ( struct V_12 * V_80 , struct V_107 * V_103 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_51 = 0 ;
int V_69 ;
if ( F_79 ( V_14 ) || F_80 ( V_14 ) )
return - V_138 ;
if ( F_71 ( V_127 , & V_11 -> V_40 ) ) {
F_10 ( V_35 , V_11 , 0x707a ,
L_54 ) ;
return - V_139 ;
}
if ( sscanf ( V_7 , L_51 , & V_51 ) != 1 )
return - V_46 ;
if ( V_51 )
V_69 = V_14 -> V_25 -> V_140 ( V_11 ) ;
else
V_69 = V_14 -> V_25 -> V_106 ( V_11 ) ;
if ( V_69 != V_34 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_81 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_55 , V_14 -> V_141 [ 1 ] ,
V_14 -> V_141 [ 0 ] ) ;
}
static T_1
F_82 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_55 , V_14 -> V_142 [ 1 ] ,
V_14 -> V_142 [ 0 ] ) ;
}
static T_1
F_83 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_55 , V_14 -> V_143 [ 1 ] ,
V_14 -> V_143 [ 0 ] ) ;
}
static T_1
F_84 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_56 ,
V_14 -> V_144 [ 0 ] , V_14 -> V_144 [ 1 ] , V_14 -> V_144 [ 2 ] ,
V_14 -> V_144 [ 3 ] ) ;
}
static T_1
F_85 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_42 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_57 ) ;
return snprintf ( V_7 , V_108 , L_58 ,
V_14 -> V_145 [ 0 ] , V_14 -> V_145 [ 1 ] ,
V_14 -> V_145 [ 2 ] , V_14 -> V_145 [ 3 ] ) ;
}
static T_1
F_86 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_59 ,
V_14 -> V_146 . V_147 ) ;
}
static T_1
F_87 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
int V_69 = V_34 ;
T_4 V_148 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_88 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_57 ) ;
if ( V_14 -> V_149 -> V_150 == 0 )
V_69 = F_89 ( V_11 , V_148 ) ;
if ( ( V_69 == V_34 ) && ( V_148 [ 0 ] == 0 ) )
return snprintf ( V_7 , V_108 , L_60 ,
( T_5 ) V_14 -> V_149 -> V_150 ) ;
return snprintf ( V_7 , V_108 , L_57 ) ;
}
static T_1
F_90 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_42 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_57 ) ;
return snprintf ( V_7 , V_108 , L_61 ,
V_14 -> V_151 [ 0 ] , V_14 -> V_151 [ 1 ] , V_14 -> V_151 [ 2 ] ,
V_14 -> V_152 ) ;
}
static T_1
F_91 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_42 ( V_14 ) )
return snprintf ( V_7 , V_108 , L_57 ) ;
return snprintf ( V_7 , V_108 , L_62 ,
V_14 -> V_153 [ 0 ] , V_14 -> V_153 [ 1 ] , V_14 -> V_153 [ 2 ] ) ;
}
static T_1
F_92 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_108 , L_63 , V_14 -> V_154 ) ;
}
static T_1
F_93 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
if ( ! F_32 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_108 , L_57 ) ;
return snprintf ( V_7 , V_108 , L_59 , V_11 -> V_155 ) ;
}
static T_1
F_94 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
if ( ! F_32 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_108 , L_57 ) ;
return snprintf ( V_7 , V_108 , L_64 ,
V_11 -> V_156 [ 5 ] , V_11 -> V_156 [ 4 ] ,
V_11 -> V_156 [ 3 ] , V_11 -> V_156 [ 2 ] ,
V_11 -> V_156 [ 1 ] , V_11 -> V_156 [ 0 ] ) ;
}
static T_1
F_95 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
return snprintf ( V_7 , V_108 , L_59 , V_11 -> V_15 -> V_157 ) ;
}
static T_1
F_96 ( struct V_12 * V_80 ,
struct V_107 * V_103 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
int V_69 = V_158 ;
T_4 V_159 , V_160 ;
if ( ! V_11 -> V_15 -> V_161 . V_162 )
return snprintf ( V_7 , V_108 , L_57 ) ;
V_159 = V_160 = 0 ;
if ( F_71 ( V_127 , & V_11 -> V_40 ) ||
F_71 ( V_39 , & V_11 -> V_40 ) )
F_10 ( V_35 , V_11 , 0x707b ,
L_65 ) ;
else if ( ! V_11 -> V_15 -> V_161 . V_163 )
V_69 = F_97 ( V_11 , & V_159 , & V_160 ) ;
if ( V_69 != V_34 )
V_159 = V_160 = 0 ;
return snprintf ( V_7 , V_108 , L_55 , V_159 , V_160 ) ;
}
static T_1
F_98 ( struct V_12 * V_80 , struct V_107 * V_103 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_80 ) ) ;
int V_69 = V_158 ;
T_4 V_164 [ 5 ] ;
if ( F_71 ( V_127 , & V_11 -> V_40 ) ||
F_71 ( V_39 , & V_11 -> V_40 ) )
F_10 ( V_35 , V_11 , 0x707c ,
L_65 ) ;
else if ( ! V_11 -> V_15 -> V_161 . V_163 )
V_69 = F_99 ( V_11 , V_164 ) ;
if ( V_69 != V_34 )
memset ( V_164 , - 1 , sizeof( V_164 ) ) ;
return snprintf ( V_7 , V_108 , L_66 , V_164 [ 0 ] ,
V_164 [ 1 ] , V_164 [ 2 ] , V_164 [ 3 ] , V_164 [ 4 ] ) ;
}
static void
F_100 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
F_101 ( V_165 ) = V_11 -> V_166 . V_167 . V_168 << 16 |
V_11 -> V_166 . V_167 . V_169 << 8 | V_11 -> V_166 . V_167 . V_170 ;
}
static void
F_102 ( struct V_96 * V_165 )
{
struct V_13 * V_14 = ( (struct V_10 * )
( F_2 ( V_165 ) ) ) -> V_15 ;
T_8 V_171 = V_172 ;
switch ( V_14 -> V_173 ) {
case V_174 :
V_171 = V_175 ;
break;
case V_176 :
V_171 = V_177 ;
break;
case V_178 :
V_171 = V_179 ;
break;
case V_180 :
V_171 = V_181 ;
break;
case V_182 :
V_171 = V_183 ;
break;
}
F_103 ( V_165 ) = V_171 ;
}
static void
F_104 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
T_5 V_184 = V_185 ;
if ( V_11 -> V_186 ) {
F_105 ( V_165 ) = V_187 ;
return;
}
switch ( V_11 -> V_15 -> V_128 ) {
case V_129 :
V_184 = V_188 ;
break;
case V_130 :
V_184 = V_189 ;
break;
case V_131 :
V_184 = V_190 ;
break;
case V_132 :
V_184 = V_191 ;
break;
}
F_105 ( V_165 ) = V_184 ;
}
static void
F_106 ( struct V_192 * V_193 )
{
struct V_96 * V_78 = F_3 ( V_193 -> V_80 . V_194 ) ;
T_7 * V_11 = F_2 ( V_78 ) ;
T_9 * V_195 ;
T_10 V_196 = 0 ;
F_107 (fcport, &vha->vp_fcports, list) {
if ( V_195 -> V_197 &&
V_193 -> V_198 == V_195 -> V_197 -> V_199 ) {
V_196 = F_108 ( V_195 -> V_196 ) ;
break;
}
}
F_109 ( V_193 ) = V_196 ;
}
static void
F_110 ( struct V_192 * V_193 )
{
struct V_96 * V_78 = F_3 ( V_193 -> V_80 . V_194 ) ;
T_7 * V_11 = F_2 ( V_78 ) ;
T_9 * V_195 ;
T_10 V_200 = 0 ;
F_107 (fcport, &vha->vp_fcports, list) {
if ( V_195 -> V_197 &&
V_193 -> V_198 == V_195 -> V_197 -> V_199 ) {
V_200 = F_108 ( V_195 -> V_200 ) ;
break;
}
}
F_111 ( V_193 ) = V_200 ;
}
static void
F_112 ( struct V_192 * V_193 )
{
struct V_96 * V_78 = F_3 ( V_193 -> V_80 . V_194 ) ;
T_7 * V_11 = F_2 ( V_78 ) ;
T_9 * V_195 ;
T_5 V_201 = ~ 0U ;
F_107 (fcport, &vha->vp_fcports, list) {
if ( V_195 -> V_197 &&
V_193 -> V_198 == V_195 -> V_197 -> V_199 ) {
V_201 = V_195 -> V_166 . V_167 . V_168 << 16 |
V_195 -> V_166 . V_167 . V_169 << 8 | V_195 -> V_166 . V_167 . V_170 ;
break;
}
}
F_113 ( V_193 ) = V_201 ;
}
static void
F_114 ( struct V_202 * V_197 , T_5 V_203 )
{
if ( V_203 )
V_197 -> V_204 = V_203 ;
else
V_197 -> V_204 = 1 ;
}
static void
F_115 ( struct V_202 * V_197 )
{
struct V_96 * V_78 = F_116 ( V_197 ) ;
T_9 * V_195 = * ( T_9 * * ) V_197 -> V_205 ;
unsigned long V_161 ;
if ( ! V_195 )
return;
F_117 ( V_195 , V_206 ) ;
F_118 ( V_78 -> V_207 , V_161 ) ;
V_195 -> V_197 = V_195 -> V_208 = NULL ;
* ( ( T_9 * * ) V_197 -> V_205 ) = NULL ;
F_119 ( V_78 -> V_207 , V_161 ) ;
if ( F_71 ( V_127 , & V_195 -> V_11 -> V_40 ) )
return;
if ( F_27 ( F_28 ( V_195 -> V_11 -> V_15 -> V_53 ) ) ) {
F_120 ( V_195 -> V_11 , V_209 << 16 ) ;
return;
}
}
static void
F_121 ( struct V_202 * V_197 )
{
T_9 * V_195 = * ( T_9 * * ) V_197 -> V_205 ;
if ( ! V_195 )
return;
if ( F_71 ( V_127 , & V_195 -> V_11 -> V_40 ) )
return;
if ( F_27 ( F_28 ( V_195 -> V_11 -> V_15 -> V_53 ) ) ) {
F_120 ( V_195 -> V_11 , V_209 << 16 ) ;
return;
}
if ( V_195 -> V_210 != V_211 &&
! F_71 ( V_212 , & V_195 -> V_11 -> V_40 ) )
V_195 -> V_11 -> V_15 -> V_25 -> V_213 ( V_195 -> V_11 ,
V_195 -> V_210 , V_195 -> V_166 . V_167 . V_168 ,
V_195 -> V_166 . V_167 . V_169 , V_195 -> V_166 . V_167 . V_170 ) ;
}
static int
F_122 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
F_123 ( V_11 ) ;
return 0 ;
}
static struct V_214 *
F_124 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_77 = F_39 ( V_14 -> V_53 ) ;
int V_69 ;
struct V_215 * V_216 ;
T_11 V_217 ;
struct V_214 * V_218 ;
V_218 = & V_14 -> V_219 ;
memset ( V_218 , - 1 , sizeof( struct V_214 ) ) ;
if ( F_71 ( V_212 , & V_11 -> V_40 ) )
goto V_65;
if ( F_27 ( F_28 ( V_14 -> V_53 ) ) )
goto V_65;
V_216 = F_36 ( V_14 -> V_73 , V_74 , & V_217 ) ;
if ( V_216 == NULL ) {
F_10 ( V_35 , V_11 , 0x707d ,
L_67 ) ;
goto V_65;
}
memset ( V_216 , 0 , V_88 ) ;
V_69 = V_158 ;
if ( F_17 ( V_14 ) ) {
V_69 = F_125 ( V_77 , V_216 , V_217 ) ;
} else if ( F_70 ( & V_77 -> V_121 ) == V_126 &&
! F_71 ( V_127 , & V_77 -> V_40 ) &&
! F_71 ( V_39 , & V_77 -> V_40 ) &&
! V_14 -> V_220 ) {
V_69 = F_126 ( V_77 , V_77 -> V_210 ,
V_216 , V_217 ) ;
}
if ( V_69 != V_34 )
goto V_221;
V_218 -> V_222 = V_216 -> V_223 ;
V_218 -> V_224 = V_216 -> V_225 ;
V_218 -> V_226 = V_216 -> V_227 ;
V_218 -> V_228 = V_216 -> V_229 ;
V_218 -> V_230 = V_216 -> V_231 ;
V_218 -> V_232 = V_216 -> V_233 ;
if ( F_17 ( V_14 ) ) {
V_218 -> V_234 = V_216 -> V_235 ;
V_218 -> V_236 = V_216 -> V_236 ;
V_218 -> V_237 = V_216 -> V_237 ;
V_218 -> V_238 = V_216 -> V_238 ;
V_218 -> V_239 = V_216 -> V_240 ;
}
V_218 -> V_241 = V_14 -> V_146 . V_242 >> 20 ;
V_218 -> V_243 = V_14 -> V_146 . V_244 >> 20 ;
V_221:
F_127 ( V_14 -> V_73 , V_216 , V_217 ) ;
V_65:
return V_218 ;
}
static void
F_128 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
F_129 ( V_11 , F_130 ( V_165 ) ) ;
}
static void
F_131 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
F_21 ( V_245 , & V_11 -> V_40 ) ;
}
static void
F_132 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
T_6 V_196 [ V_246 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_247 = F_108 ( V_196 ) ;
if ( V_11 -> V_124 & V_248 )
V_247 = F_108 ( V_11 -> V_249 ) ;
F_133 ( V_165 ) = V_247 ;
}
static void
F_134 ( struct V_96 * V_165 )
{
T_7 * V_11 = F_2 ( V_165 ) ;
struct V_10 * V_77 = F_39 ( V_11 -> V_15 -> V_53 ) ;
if ( ! V_77 -> V_161 . V_250 )
F_135 ( V_165 ) = V_251 ;
else if ( F_70 ( & V_77 -> V_121 ) == V_252 )
F_135 ( V_165 ) = V_253 ;
else
F_135 ( V_165 ) = V_254 ;
}
static int
F_136 ( struct V_255 * V_255 , bool V_256 )
{
int V_98 = 0 ;
T_6 V_257 = 0 ;
T_7 * V_77 = F_2 ( V_255 -> V_165 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_77 -> V_15 ;
T_4 V_258 = 0 ;
int V_30 ;
struct V_259 * V_260 = V_14 -> V_261 [ 0 ] ;
V_98 = F_137 ( V_255 ) ;
if ( V_98 ) {
F_10 ( V_35 , V_11 , 0x707e ,
L_68 , V_98 ) ;
return ( V_98 ) ;
}
V_11 = F_138 ( V_255 ) ;
if ( V_11 == NULL ) {
F_10 ( V_35 , V_11 , 0x707f , L_69 ) ;
return V_262 ;
}
if ( V_256 ) {
F_139 ( & V_11 -> V_263 , V_264 ) ;
F_140 ( V_255 , V_265 ) ;
} else
F_139 ( & V_11 -> V_263 , V_266 ) ;
F_10 ( V_21 , V_11 , 0x7080 ,
L_70 , V_11 -> V_186 ) ;
F_139 ( & V_11 -> V_121 , V_122 ) ;
V_11 -> V_267 = V_268 ;
V_11 -> V_269 = V_270 ;
if ( F_70 ( & V_77 -> V_121 ) == V_122 ||
F_70 ( & V_77 -> V_121 ) == V_123 ) {
F_8 ( V_20 , V_11 , 0x7081 ,
L_71 ) ;
F_139 ( & V_11 -> V_121 , V_123 ) ;
if ( ! V_256 )
F_140 ( V_255 , V_271 ) ;
}
if ( F_141 ( V_14 ) && V_272 ) {
if ( V_14 -> V_273 & V_274 ) {
int V_275 = 0 ;
V_11 -> V_161 . V_276 = 1 ;
F_8 ( V_20 , V_11 , 0x7082 ,
L_72 ) ;
if ( V_272 == 1 )
V_275 = V_277 ;
F_142 ( V_11 -> V_78 ,
V_275 | V_278
| V_279
| V_280
| V_281
| V_282
| V_283 ) ;
F_143 ( V_11 -> V_78 , V_284 ) ;
} else
V_11 -> V_161 . V_276 = 0 ;
}
if ( F_144 ( V_11 -> V_78 , & V_255 -> V_80 ,
& V_14 -> V_53 -> V_80 ) ) {
F_8 ( V_20 , V_11 , 0x7083 ,
L_73 , V_11 -> V_186 ) ;
goto V_285;
}
F_145 ( V_11 -> V_78 ) = V_14 -> V_286 ;
F_146 ( V_11 -> V_78 ) = F_108 ( V_11 -> V_196 ) ;
F_147 ( V_11 -> V_78 ) = F_108 ( V_11 -> V_200 ) ;
F_148 ( V_11 -> V_78 ) =
F_148 ( V_77 -> V_78 ) ;
F_149 ( V_11 -> V_78 ) =
F_149 ( V_77 -> V_78 ) ;
F_150 ( V_255 , V_256 ) ;
if ( V_14 -> V_161 . V_287 ) {
V_260 = V_14 -> V_261 [ 1 ] ;
F_8 ( V_288 , V_11 , 0xc000 ,
L_74
L_75 ,
V_260 , V_11 -> V_186 , V_14 -> V_161 . V_287 ) ;
goto V_289;
} else if ( V_290 == 1 || ! V_14 -> V_291 )
goto V_289;
for ( V_30 = 0 ; V_30 < V_14 -> V_292 ; V_30 ++ ) {
if ( memcmp ( V_14 -> V_291 [ V_30 ] . V_200 , V_11 -> V_200 , 8 ) == 0
&& memcmp ( V_14 -> V_291 [ V_30 ] . V_196 , V_11 -> V_196 ,
8 ) == 0 ) {
V_257 = V_14 -> V_291 [ V_30 ] . V_293 ;
break;
}
}
if ( V_257 ) {
V_98 = F_151 ( V_14 , V_258 , V_11 -> V_186 , 0 , 0 ,
V_257 ) ;
if ( ! V_98 )
F_10 ( V_35 , V_11 , 0x7084 ,
L_76 ,
V_11 -> V_186 ) ;
else {
F_8 ( V_288 , V_11 , 0xc001 ,
L_77 ,
V_98 , V_257 , V_11 -> V_186 ) ;
F_8 ( V_20 , V_11 , 0x7085 ,
L_77 ,
V_98 , V_257 , V_11 -> V_186 ) ;
V_260 = V_14 -> V_261 [ V_98 ] ;
}
}
V_289:
V_11 -> V_260 = V_260 ;
return 0 ;
V_285:
F_152 ( V_11 ) ;
F_153 ( V_11 ) ;
F_154 ( V_11 -> V_78 ) ;
return V_262 ;
}
static int
F_155 ( struct V_255 * V_255 )
{
T_7 * V_11 = V_255 -> V_205 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_198 = V_11 -> V_186 ;
while ( F_71 ( V_294 , & V_11 -> V_40 ) ||
F_71 ( V_295 , & V_11 -> V_40 ) )
F_156 ( 1000 ) ;
F_152 ( V_11 ) ;
V_11 -> V_161 . V_296 = 1 ;
F_157 ( V_11 -> V_78 ) ;
F_158 ( V_11 -> V_78 ) ;
F_153 ( V_11 ) ;
if ( V_11 -> V_297 ) {
F_159 ( V_11 ) ;
F_8 ( V_20 , V_11 , 0x7086 ,
L_78 , V_11 -> V_186 ) ;
}
if ( V_298 & V_20 )
F_156 ( F_160 () % 10 ) ;
F_161 ( F_70 ( & V_11 -> V_299 ) ) ;
F_162 ( V_11 ) ;
F_163 ( & V_14 -> V_300 ) ;
V_14 -> V_301 -- ;
F_164 ( V_11 -> V_186 , V_14 -> V_302 ) ;
F_165 ( & V_14 -> V_300 ) ;
if ( V_11 -> V_260 -> V_198 && ! V_14 -> V_161 . V_287 ) {
if ( F_166 ( V_11 , V_11 -> V_260 ) != V_34 )
F_10 ( V_35 , V_11 , 0x7087 ,
L_79 ) ;
}
F_154 ( V_11 -> V_78 ) ;
F_10 ( V_21 , V_11 , 0x7088 , L_80 , V_198 ) ;
return 0 ;
}
static int
F_150 ( struct V_255 * V_255 , bool V_256 )
{
T_7 * V_11 = V_255 -> V_205 ;
if ( V_256 )
F_152 ( V_11 ) ;
else
F_167 ( V_11 ) ;
return 0 ;
}
void
F_168 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_171 = V_172 ;
F_145 ( V_11 -> V_78 ) = V_14 -> V_286 ;
F_146 ( V_11 -> V_78 ) = F_108 ( V_11 -> V_196 ) ;
F_147 ( V_11 -> V_78 ) = F_108 ( V_11 -> V_200 ) ;
F_148 ( V_11 -> V_78 ) = V_303 ;
F_169 ( V_11 -> V_78 ) = V_14 -> V_304 ;
F_170 ( V_11 -> V_78 ) = V_14 -> V_301 ;
if ( F_32 ( V_14 ) )
V_171 = V_183 ;
else if ( F_31 ( V_14 ) )
V_171 = V_181 | V_179 |
V_177 | V_175 ;
else if ( F_171 ( V_14 ) )
V_171 = V_179 | V_177 |
V_175 ;
else if ( F_172 ( V_14 ) )
V_171 = V_177 | V_175 ;
else
V_171 = V_175 ;
F_149 ( V_11 -> V_78 ) = V_171 ;
}
