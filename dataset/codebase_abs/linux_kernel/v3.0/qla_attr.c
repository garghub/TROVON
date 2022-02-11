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
F_8 ( F_9 ( V_20 , V_14 ,
L_1 ) ) ;
return V_9 ;
}
if ( V_8 != 0 )
return ( 0 ) ;
V_19 = F_10 ( V_7 , NULL , 10 ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_14 -> V_16 )
break;
F_9 ( V_20 , V_14 ,
L_2 , V_11 -> V_21 ) ;
V_14 -> V_16 = 0 ;
V_14 -> V_22 = 0 ;
break;
case 1 :
if ( V_14 -> V_22 && ! V_14 -> V_16 ) {
V_14 -> V_16 = 1 ;
F_9 ( V_20 , V_14 ,
L_3 ,
V_11 -> V_21 ) ;
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
if ( ! F_14 ( V_23 ) )
return 0 ;
if ( F_15 ( V_14 ) )
V_14 -> V_24 -> V_25 ( V_11 , V_14 -> V_26 , V_14 -> V_27 << 2 ,
V_14 -> V_28 ) ;
return F_5 ( V_7 , V_9 , & V_8 , V_14 -> V_26 ,
V_14 -> V_28 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_29 ;
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 != V_14 -> V_28 ||
! V_14 -> V_24 -> V_30 )
return 0 ;
if ( F_17 ( V_14 ) ) {
T_5 * V_31 ;
T_5 V_32 ;
V_31 = ( T_5 * ) V_7 ;
V_32 = 0 ;
for ( V_29 = 0 ; V_29 < ( ( V_9 >> 2 ) - 1 ) ; V_29 ++ )
V_32 += F_18 ( * V_31 ++ ) ;
V_32 = ~ V_32 + 1 ;
* V_31 = F_19 ( V_32 ) ;
} else {
T_6 * V_31 ;
T_6 V_32 ;
V_31 = ( T_6 * ) V_7 ;
V_32 = 0 ;
for ( V_29 = 0 ; V_29 < V_9 - 1 ; V_29 ++ )
V_32 += * V_31 ++ ;
V_32 = ~ V_32 + 1 ;
* V_31 = V_32 ;
}
if ( F_20 ( V_11 ) != V_33 ) {
F_9 ( V_34 , V_14 ,
L_4 ) ;
return - V_35 ;
}
V_14 -> V_24 -> V_30 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_36 , V_9 ) ;
V_14 -> V_24 -> V_37 ( V_11 , ( T_6 * ) V_14 -> V_26 , V_14 -> V_36 ,
V_9 ) ;
F_21 ( V_38 , & V_11 -> V_39 ) ;
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
if ( V_14 -> V_40 != V_41 )
return 0 ;
return F_5 ( V_7 , V_9 , & V_8 , V_14 -> V_42 ,
V_14 -> V_43 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 -> V_40 != V_44 )
return - V_45 ;
if ( V_8 > V_14 -> V_43 )
return - V_46 ;
if ( V_8 + V_9 > V_14 -> V_43 )
V_9 = V_14 -> V_43 - V_8 ;
memcpy ( & V_14 -> V_42 [ V_8 ] , V_7 , V_9 ) ;
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
T_5 V_47 = 0 ;
T_5 V_48 = V_14 -> V_49 ;
int V_50 , V_51 ;
if ( V_8 )
return 0 ;
if ( F_27 ( F_28 ( V_14 -> V_52 ) ) )
return 0 ;
if ( sscanf ( V_7 , L_5 , & V_50 , & V_47 , & V_48 ) < 1 )
return - V_45 ;
if ( V_47 > V_14 -> V_49 )
return - V_45 ;
switch ( V_50 ) {
case 0 :
if ( V_14 -> V_40 != V_41 &&
V_14 -> V_40 != V_44 )
break;
V_14 -> V_40 = V_53 ;
F_8 ( F_9 ( V_20 , V_14 ,
L_6 ,
V_14 -> V_43 ) ) ;
F_29 ( V_14 -> V_42 ) ;
V_14 -> V_42 = NULL ;
break;
case 1 :
if ( V_14 -> V_40 != V_53 )
break;
V_14 -> V_54 = V_47 ;
V_14 -> V_43 = V_47 + V_48 > V_14 -> V_49 ?
V_14 -> V_49 - V_47 : V_48 ;
V_14 -> V_40 = V_41 ;
V_14 -> V_42 = F_30 ( V_14 -> V_43 ) ;
if ( V_14 -> V_42 == NULL ) {
F_9 ( V_34 , V_14 ,
L_7
L_8 , V_14 -> V_43 ) ;
V_14 -> V_40 = V_53 ;
return V_9 ;
}
if ( F_20 ( V_11 ) != V_33 ) {
F_9 ( V_34 , V_14 ,
L_4 ) ;
return - V_35 ;
}
F_8 ( F_9 ( V_20 , V_14 ,
L_9 ,
V_14 -> V_54 , V_14 -> V_43 ) ) ;
memset ( V_14 -> V_42 , 0 , V_14 -> V_43 ) ;
V_14 -> V_24 -> V_25 ( V_11 , V_14 -> V_42 ,
V_14 -> V_54 , V_14 -> V_43 ) ;
break;
case 2 :
if ( V_14 -> V_40 != V_53 )
break;
V_51 = 0 ;
if ( V_14 -> V_49 == V_55 && V_47 == 0 )
V_51 = 1 ;
else if ( V_47 == ( V_14 -> V_56 * 4 ) ||
V_47 == ( V_14 -> V_57 * 4 ) )
V_51 = 1 ;
else if ( F_31 ( V_14 ) || F_32 ( V_14 ) )
V_51 = 1 ;
if ( ! V_51 ) {
F_9 ( V_34 , V_14 ,
L_10 , V_47 , V_48 ) ;
return - V_45 ;
}
V_14 -> V_54 = V_47 ;
V_14 -> V_43 = V_47 + V_48 > V_14 -> V_49 ?
V_14 -> V_49 - V_47 : V_48 ;
V_14 -> V_40 = V_44 ;
V_14 -> V_42 = F_30 ( V_14 -> V_43 ) ;
if ( V_14 -> V_42 == NULL ) {
F_9 ( V_34 , V_14 ,
L_11
L_8 , V_14 -> V_43 ) ;
V_14 -> V_40 = V_53 ;
return V_9 ;
}
F_8 ( F_9 ( V_20 , V_14 ,
L_12 ,
V_14 -> V_54 , V_14 -> V_43 ) ) ;
memset ( V_14 -> V_42 , 0 , V_14 -> V_43 ) ;
break;
case 3 :
if ( V_14 -> V_40 != V_44 )
break;
if ( F_20 ( V_11 ) != V_33 ) {
F_9 ( V_34 , V_14 ,
L_13 ) ;
return - V_35 ;
}
F_8 ( F_9 ( V_20 , V_14 ,
L_14 ,
V_14 -> V_54 , V_14 -> V_43 ) ) ;
V_14 -> V_24 -> V_58 ( V_11 , V_14 -> V_42 ,
V_14 -> V_54 , V_14 -> V_43 ) ;
break;
default:
V_9 = - V_45 ;
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
if ( F_27 ( F_28 ( V_14 -> V_52 ) ) )
return 0 ;
if ( ! F_14 ( V_23 ) )
return 0 ;
if ( F_15 ( V_14 ) )
V_14 -> V_24 -> V_25 ( V_11 , V_14 -> V_59 , V_14 -> V_60 << 2 ,
V_14 -> V_61 ) ;
return F_5 ( V_7 , V_9 , & V_8 , V_14 -> V_59 , V_14 -> V_61 ) ;
}
static T_1
F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_62 ;
if ( F_27 ( F_28 ( V_14 -> V_52 ) ) )
return 0 ;
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 != V_14 -> V_61 ||
! V_14 -> V_24 -> V_30 )
return 0 ;
if ( F_20 ( V_11 ) != V_33 ) {
F_9 ( V_34 , V_14 ,
L_15 ) ;
return - V_35 ;
}
V_14 -> V_24 -> V_30 ( V_11 , ( T_6 * ) V_7 , V_14 -> V_63 , V_9 ) ;
V_14 -> V_24 -> V_37 ( V_11 , ( T_6 * ) V_14 -> V_59 , V_14 -> V_63 , V_9 ) ;
if ( ! F_17 ( V_14 ) )
goto V_64;
V_62 = F_30 ( 256 ) ;
if ( ! V_62 ) {
F_9 ( V_34 , V_14 ,
L_16 ) ;
goto V_64;
}
V_14 -> V_24 -> V_65 ( V_11 , V_62 ) ;
F_29 ( V_62 ) ;
V_64:
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
T_4 V_31 , V_66 , V_67 ;
int V_68 ;
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 != V_69 * 2 )
return 0 ;
if ( V_14 -> V_70 )
goto V_71;
V_14 -> V_70 = F_36 ( V_14 -> V_72 , V_73 ,
& V_14 -> V_74 ) ;
if ( ! V_14 -> V_70 ) {
F_9 ( V_34 , V_14 ,
L_17 ) ;
return 0 ;
}
V_71:
memset ( V_14 -> V_70 , 0 , V_75 ) ;
V_66 = 0xa0 ;
for ( V_31 = 0 , V_67 = 0 ; V_31 < ( V_69 * 2 ) / V_75 ;
V_31 ++ , V_67 += V_75 ) {
if ( V_31 == 4 ) {
V_66 = 0xa2 ;
V_67 = 0 ;
}
V_68 = F_37 ( V_11 , V_14 -> V_74 , V_14 -> V_70 ,
V_66 , V_67 , V_75 , 0 ) ;
if ( V_68 != V_33 ) {
F_9 ( V_34 , V_14 ,
L_18 , V_68 ,
V_66 , V_67 ) ;
V_9 = 0 ;
break;
}
memcpy ( V_7 , V_14 -> V_70 , V_75 ) ;
V_7 += V_75 ;
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
struct V_10 * V_76 = F_39 ( V_14 -> V_52 ) ;
int type ;
if ( V_8 != 0 )
return 0 ;
type = F_10 ( V_7 , NULL , 10 ) ;
switch ( type ) {
case 0x2025c :
F_9 ( V_20 , V_14 ,
L_19 , V_11 -> V_21 ) ;
F_40 ( V_11 -> V_77 ) ;
F_21 ( V_38 , & V_11 -> V_39 ) ;
F_22 ( V_11 ) ;
F_23 ( V_11 ) ;
F_41 ( V_11 -> V_77 ) ;
break;
case 0x2025d :
if ( ! F_42 ( V_14 ) )
break;
F_9 ( V_20 , V_14 ,
L_20 , V_11 -> V_21 ) ;
F_20 ( V_11 ) ;
F_40 ( V_11 -> V_77 ) ;
if ( F_43 ( V_11 ) != V_33 )
F_9 ( V_34 , V_14 ,
L_21 , V_11 -> V_21 ) ;
F_41 ( V_11 -> V_77 ) ;
break;
case 0x2025e :
if ( ! F_7 ( V_14 ) || V_11 != V_76 ) {
F_9 ( V_20 , V_14 ,
L_22 ,
V_11 -> V_21 ) ;
return V_9 ;
}
F_9 ( V_20 , V_14 ,
L_23 , V_11 -> V_21 ) ;
F_21 ( V_78 , & V_11 -> V_39 ) ;
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
T_4 V_79 , V_80 , V_81 , V_82 ;
int V_68 ;
V_14 -> V_83 = 0 ;
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 < 8 )
return 0 ;
if ( ! V_14 -> V_84 ) {
V_14 -> V_84 = F_36 ( V_14 -> V_72 , V_73 ,
& V_14 -> V_85 ) ;
if ( ! V_14 -> V_84 ) {
F_8 ( F_9 ( V_20 , V_14 ,
L_24 ) ) ;
return 0 ;
}
}
V_79 = F_46 ( ( void * ) & V_7 [ 0 ] ) ;
V_80 = F_46 ( ( void * ) & V_7 [ 2 ] ) ;
V_81 = F_46 ( ( void * ) & V_7 [ 4 ] ) ;
V_82 = F_46 ( ( void * ) & V_7 [ 6 ] ) ;
if ( ! ( V_81 & V_86 ) )
if ( V_82 == 0 || V_82 > V_87 || V_82 > V_9 - 8 )
return - V_45 ;
memcpy ( V_14 -> V_84 , & V_7 [ 8 ] , V_82 ) ;
V_68 = F_47 ( V_11 , V_14 -> V_85 , V_14 -> V_84 ,
V_79 , V_80 , V_82 , V_81 ) ;
if ( V_68 != V_33 ) {
F_8 ( F_9 ( V_20 , V_14 ,
L_25 ,
V_68 , V_79 , V_80 , V_81 , V_82 , V_7 [ 8 ] ) ) ;
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
T_4 V_79 , V_80 , V_81 , V_82 ;
int V_68 ;
V_14 -> V_83 = 0 ;
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 < 8 )
return 0 ;
if ( ! V_14 -> V_84 ) {
V_14 -> V_84 = F_36 ( V_14 -> V_72 , V_73 ,
& V_14 -> V_85 ) ;
if ( ! V_14 -> V_84 ) {
F_8 ( F_9 ( V_20 , V_14 ,
L_26 ) ) ;
return 0 ;
}
}
V_79 = F_46 ( ( void * ) & V_7 [ 0 ] ) ;
V_80 = F_46 ( ( void * ) & V_7 [ 2 ] ) ;
V_81 = F_46 ( ( void * ) & V_7 [ 4 ] ) ;
V_82 = F_46 ( ( void * ) & V_7 [ 6 ] ) ;
if ( ! ( V_81 & V_86 ) )
if ( V_82 == 0 || V_82 > V_87 )
return - V_45 ;
memset ( V_14 -> V_84 , 0 , V_82 ) ;
V_68 = F_37 ( V_11 , V_14 -> V_85 , V_14 -> V_84 ,
V_79 , V_80 , V_82 , V_81 ) ;
if ( V_68 != V_33 ) {
F_8 ( F_9 ( V_20 , V_14 ,
L_27 ,
V_68 , V_79 , V_80 , V_81 , V_82 ) ) ;
return 0 ;
}
V_14 -> V_83 = V_82 ;
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
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 == 0 )
return 0 ;
if ( ! V_14 -> V_84 || V_14 -> V_83 == 0 || V_14 -> V_83 > V_9 )
return - V_45 ;
memcpy ( V_7 , V_14 -> V_84 , V_14 -> V_83 ) ;
return V_14 -> V_83 ;
}
static T_1
F_50 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_68 ;
T_4 V_88 ;
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 > V_89 )
return 0 ;
if ( V_14 -> V_90 )
goto V_71;
V_14 -> V_90 = F_51 ( & V_14 -> V_52 -> V_79 , V_89 ,
& V_14 -> V_91 , V_73 ) ;
if ( ! V_14 -> V_90 ) {
F_9 ( V_34 , V_14 ,
L_28 ) ;
return 0 ;
}
V_71:
V_88 = 0 ;
memset ( V_14 -> V_90 , 0 , V_89 ) ;
V_68 = F_52 ( V_11 , V_14 -> V_91 ,
V_89 , & V_88 ) ;
if ( V_68 != V_33 ) {
F_9 ( V_34 , V_14 ,
L_29 , V_68 ) ;
V_9 = 0 ;
}
V_9 = V_88 > V_9 ? V_9 : V_88 ;
memcpy ( V_7 , V_14 -> V_90 , V_9 ) ;
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
int V_68 ;
T_4 V_88 ;
if ( ! F_14 ( V_23 ) || V_8 != 0 || V_9 > V_92 )
return 0 ;
if ( V_14 -> V_93 )
goto V_71;
V_14 -> V_93 = F_51 ( & V_14 -> V_52 -> V_79 , V_92 ,
& V_14 -> V_94 , V_73 ) ;
if ( ! V_14 -> V_93 ) {
F_9 ( V_34 , V_14 ,
L_30 ) ;
return 0 ;
}
V_71:
V_88 = 0 ;
memset ( V_14 -> V_93 , 0 , V_92 ) ;
V_68 = F_54 ( V_11 , V_14 -> V_94 ,
V_92 ) ;
if ( V_68 != V_33 ) {
F_9 ( V_34 , V_14 ,
L_31 , V_68 ) ;
V_9 = 0 ;
}
memcpy ( V_7 , V_14 -> V_93 , V_9 ) ;
return V_9 ;
}
void
F_55 ( T_7 * V_11 )
{
struct V_95 * V_77 = V_11 -> V_77 ;
struct V_96 * V_31 ;
int V_97 ;
for ( V_31 = V_98 ; V_31 -> V_99 ; V_31 ++ ) {
if ( V_31 -> V_100 && ! F_17 ( V_11 -> V_15 ) )
continue;
if ( V_31 -> V_100 == 2 && ! F_31 ( V_11 -> V_15 ) )
continue;
if ( V_31 -> V_100 == 3 && ! ( F_32 ( V_11 -> V_15 ) ) )
continue;
V_97 = F_56 ( & V_77 -> V_101 . V_4 ,
V_31 -> V_102 ) ;
if ( V_97 )
F_9 ( V_20 , V_11 -> V_15 ,
L_32
L_33 , V_31 -> V_99 , V_97 ) ;
}
}
void
F_57 ( T_7 * V_11 )
{
struct V_95 * V_77 = V_11 -> V_77 ;
struct V_96 * V_31 ;
struct V_13 * V_14 = V_11 -> V_15 ;
for ( V_31 = V_98 ; V_31 -> V_99 ; V_31 ++ ) {
if ( V_31 -> V_100 && ! F_17 ( V_14 ) )
continue;
if ( V_31 -> V_100 == 2 && ! F_31 ( V_14 ) )
continue;
if ( V_31 -> V_100 == 3 && ! ! ( F_32 ( V_11 -> V_15 ) ) )
continue;
F_58 ( & V_77 -> V_101 . V_4 ,
V_31 -> V_102 ) ;
}
if ( V_14 -> V_103 == 1 )
V_14 -> V_24 -> V_104 ( V_11 ) ;
}
static T_1
F_59 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
return snprintf ( V_7 , V_106 , L_34 , V_107 ) ;
}
static T_1
F_60 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
char V_108 [ 128 ] ;
return snprintf ( V_7 , V_106 , L_34 ,
V_14 -> V_24 -> V_109 ( V_11 , V_108 ) ) ;
}
static T_1
F_62 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_5 V_110 ;
if ( F_17 ( V_14 ) ) {
F_63 ( V_11 , L_35 , V_7 , V_106 ) ;
return snprintf ( V_7 , V_106 , L_34 , V_7 ) ;
}
V_110 = ( ( V_14 -> V_111 & 0x1f ) << 16 ) | ( V_14 -> V_112 << 8 ) | V_14 -> V_113 ;
return snprintf ( V_7 , V_106 , L_36 , 'A' + V_110 / 100000 ,
V_110 % 100000 ) ;
}
static T_1
F_64 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
return snprintf ( V_7 , V_106 , L_37 , V_11 -> V_15 -> V_52 -> V_12 ) ;
}
static T_1
F_65 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_38 ,
V_14 -> V_114 [ 0 ] , V_14 -> V_114 [ 1 ] , V_14 -> V_114 [ 2 ] ,
V_14 -> V_114 [ 3 ] ) ;
}
static T_1
F_66 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
return snprintf ( V_7 , V_106 , L_34 , V_11 -> V_15 -> V_115 ) ;
}
static T_1
F_67 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
return snprintf ( V_7 , V_106 , L_34 ,
V_11 -> V_15 -> V_116 ? V_11 -> V_15 -> V_116 : L_39 ) ;
}
static T_1
F_68 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
char V_117 [ 30 ] ;
return snprintf ( V_7 , V_106 , L_34 ,
V_11 -> V_15 -> V_24 -> V_118 ( V_11 , V_117 ) ) ;
}
static T_1
F_69 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_82 = 0 ;
if ( F_70 ( & V_11 -> V_119 ) == V_120 ||
F_70 ( & V_11 -> V_119 ) == V_121 ||
V_11 -> V_122 & V_123 )
V_82 = snprintf ( V_7 , V_106 , L_40 ) ;
else if ( F_70 ( & V_11 -> V_119 ) != V_124 ||
F_71 ( V_125 , & V_11 -> V_39 ) ||
F_71 ( V_38 , & V_11 -> V_39 ) )
V_82 = snprintf ( V_7 , V_106 , L_41 ) ;
else {
V_82 = snprintf ( V_7 , V_106 , L_42 ) ;
switch ( V_14 -> V_126 ) {
case V_127 :
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_43 ) ;
break;
case V_128 :
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_44 ) ;
break;
case V_129 :
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 ,
L_45 ) ;
break;
case V_130 :
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_46 ) ;
break;
default:
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_43 ) ;
break;
}
}
return V_82 ;
}
static T_1
F_72 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
int V_82 = 0 ;
switch ( V_11 -> V_15 -> V_131 ) {
case V_132 :
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_47 ) ;
break;
case V_133 :
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_48 ) ;
break;
}
return V_82 ;
}
static T_1
F_73 ( struct V_12 * V_79 , struct V_105 * V_102 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_50 = 0 ;
T_4 V_131 ;
if ( ! F_74 ( V_14 ) )
return - V_134 ;
if ( sscanf ( V_7 , L_49 , & V_50 ) != 1 )
return - V_45 ;
if ( V_50 )
V_131 = V_132 ;
else
V_131 = V_133 ;
if ( V_131 != V_133 || V_14 -> V_131 != V_133 ) {
V_14 -> V_131 = V_131 ;
F_21 ( V_38 , & V_11 -> V_39 ) ;
}
return strlen ( V_7 ) ;
}
static T_1
F_75 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
return snprintf ( V_7 , V_106 , L_50 , V_11 -> V_15 -> V_135 * 100 ) ;
}
static T_1
F_76 ( struct V_12 * V_79 , struct V_105 * V_102 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
int V_50 = 0 ;
T_4 V_135 ;
if ( sscanf ( V_7 , L_49 , & V_50 ) != 1 )
return - V_45 ;
if ( V_50 > 25500 || V_50 < 100 )
return - V_46 ;
V_135 = ( T_4 ) ( V_50 / 100 ) ;
V_11 -> V_15 -> V_135 = V_135 ;
return strlen ( V_7 ) ;
}
static T_1
F_77 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
int V_82 = 0 ;
if ( V_11 -> V_15 -> V_103 )
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_51 ) ;
else
V_82 += snprintf ( V_7 + V_82 , V_106 - V_82 , L_48 ) ;
return V_82 ;
}
static T_1
F_78 ( struct V_12 * V_79 , struct V_105 * V_102 ,
const char * V_7 , T_3 V_9 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_50 = 0 ;
int V_68 ;
if ( F_79 ( V_14 ) || F_80 ( V_14 ) )
return - V_136 ;
if ( F_71 ( V_125 , & V_11 -> V_39 ) ) {
F_9 ( V_34 , V_14 ,
L_52 ) ;
return - V_137 ;
}
if ( sscanf ( V_7 , L_49 , & V_50 ) != 1 )
return - V_45 ;
if ( V_50 )
V_68 = V_14 -> V_24 -> V_138 ( V_11 ) ;
else
V_68 = V_14 -> V_24 -> V_104 ( V_11 ) ;
if ( V_68 != V_33 )
V_9 = 0 ;
return V_9 ;
}
static T_1
F_81 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_53 , V_14 -> V_139 [ 1 ] ,
V_14 -> V_139 [ 0 ] ) ;
}
static T_1
F_82 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_53 , V_14 -> V_140 [ 1 ] ,
V_14 -> V_140 [ 0 ] ) ;
}
static T_1
F_83 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_53 , V_14 -> V_141 [ 1 ] ,
V_14 -> V_141 [ 0 ] ) ;
}
static T_1
F_84 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_54 ,
V_14 -> V_142 [ 0 ] , V_14 -> V_142 [ 1 ] , V_14 -> V_142 [ 2 ] ,
V_14 -> V_142 [ 3 ] ) ;
}
static T_1
F_85 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_42 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_55 ) ;
return snprintf ( V_7 , V_106 , L_56 ,
V_14 -> V_143 [ 0 ] , V_14 -> V_143 [ 1 ] ,
V_14 -> V_143 [ 2 ] , V_14 -> V_143 [ 3 ] ) ;
}
static T_1
F_86 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_57 ,
V_14 -> V_144 . V_145 ) ;
}
static T_1
F_87 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
int V_68 = V_33 ;
T_4 V_146 [ 2 ] = { 0 , 0 } ;
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_88 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_55 ) ;
if ( V_14 -> V_147 -> V_148 == 0 )
V_68 = F_89 ( V_11 , V_146 ) ;
if ( ( V_68 == V_33 ) && ( V_146 [ 0 ] == 0 ) )
return snprintf ( V_7 , V_106 , L_58 ,
( T_5 ) V_14 -> V_147 -> V_148 ) ;
return snprintf ( V_7 , V_106 , L_55 ) ;
}
static T_1
F_90 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_42 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_55 ) ;
return snprintf ( V_7 , V_106 , L_59 ,
V_14 -> V_149 [ 0 ] , V_14 -> V_149 [ 1 ] , V_14 -> V_149 [ 2 ] ,
V_14 -> V_150 ) ;
}
static T_1
F_91 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
if ( ! F_42 ( V_14 ) )
return snprintf ( V_7 , V_106 , L_55 ) ;
return snprintf ( V_7 , V_106 , L_60 ,
V_14 -> V_151 [ 0 ] , V_14 -> V_151 [ 1 ] , V_14 -> V_151 [ 2 ] ) ;
}
static T_1
F_92 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
return snprintf ( V_7 , V_106 , L_61 , V_14 -> V_152 ) ;
}
static T_1
F_93 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
if ( ! F_32 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_106 , L_55 ) ;
return snprintf ( V_7 , V_106 , L_57 , V_11 -> V_153 ) ;
}
static T_1
F_94 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
if ( ! F_32 ( V_11 -> V_15 ) )
return snprintf ( V_7 , V_106 , L_55 ) ;
return snprintf ( V_7 , V_106 , L_62 ,
V_11 -> V_154 [ 5 ] , V_11 -> V_154 [ 4 ] ,
V_11 -> V_154 [ 3 ] , V_11 -> V_154 [ 2 ] ,
V_11 -> V_154 [ 1 ] , V_11 -> V_154 [ 0 ] ) ;
}
static T_1
F_95 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
return snprintf ( V_7 , V_106 , L_57 , V_11 -> V_15 -> V_155 ) ;
}
static T_1
F_96 ( struct V_12 * V_79 ,
struct V_105 * V_102 , char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
int V_68 = V_156 ;
T_4 V_157 , V_158 ;
if ( ! V_11 -> V_15 -> V_159 . V_160 )
return snprintf ( V_7 , V_106 , L_55 ) ;
V_157 = V_158 = 0 ;
if ( F_71 ( V_125 , & V_11 -> V_39 ) ||
F_71 ( V_38 , & V_11 -> V_39 ) )
F_97 ( F_98 ( V_34
L_63 ,
V_161 , V_11 -> V_21 ) ) ;
else if ( ! V_11 -> V_15 -> V_159 . V_162 )
V_68 = F_99 ( V_11 , & V_157 , & V_158 ) ;
if ( V_68 != V_33 )
V_157 = V_158 = 0 ;
return snprintf ( V_7 , V_106 , L_53 , V_157 , V_158 ) ;
}
static T_1
F_100 ( struct V_12 * V_79 , struct V_105 * V_102 ,
char * V_7 )
{
T_7 * V_11 = F_2 ( F_61 ( V_79 ) ) ;
int V_68 = V_156 ;
T_4 V_163 [ 5 ] ;
if ( F_71 ( V_125 , & V_11 -> V_39 ) ||
F_71 ( V_38 , & V_11 -> V_39 ) )
F_97 ( F_98 ( L_63 ,
V_161 , V_11 -> V_21 ) ) ;
else if ( ! V_11 -> V_15 -> V_159 . V_162 )
V_68 = F_101 ( V_11 , V_163 ) ;
if ( V_68 != V_33 )
memset ( V_163 , - 1 , sizeof( V_163 ) ) ;
return snprintf ( V_7 , V_106 , L_64 , V_163 [ 0 ] ,
V_163 [ 1 ] , V_163 [ 2 ] , V_163 [ 3 ] , V_163 [ 4 ] ) ;
}
static void
F_102 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_103 ( V_164 ) = V_11 -> V_165 . V_166 . V_167 << 16 |
V_11 -> V_165 . V_166 . V_168 << 8 | V_11 -> V_165 . V_166 . V_169 ;
}
static void
F_104 ( struct V_95 * V_164 )
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
}
F_105 ( V_164 ) = V_170 ;
}
static void
F_106 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
T_5 V_183 = V_184 ;
if ( V_11 -> V_185 ) {
F_107 ( V_164 ) = V_186 ;
return;
}
switch ( V_11 -> V_15 -> V_126 ) {
case V_127 :
V_183 = V_187 ;
break;
case V_128 :
V_183 = V_188 ;
break;
case V_129 :
V_183 = V_189 ;
break;
case V_130 :
V_183 = V_190 ;
break;
}
F_107 ( V_164 ) = V_183 ;
}
static void
F_108 ( struct V_191 * V_192 )
{
struct V_95 * V_77 = F_3 ( V_192 -> V_79 . V_193 ) ;
T_7 * V_11 = F_2 ( V_77 ) ;
T_9 * V_194 ;
T_10 V_195 = 0 ;
F_109 (fcport, &vha->vp_fcports, list) {
if ( V_194 -> V_196 &&
V_192 -> V_197 == V_194 -> V_196 -> V_198 ) {
V_195 = F_110 ( V_194 -> V_195 ) ;
break;
}
}
F_111 ( V_192 ) = V_195 ;
}
static void
F_112 ( struct V_191 * V_192 )
{
struct V_95 * V_77 = F_3 ( V_192 -> V_79 . V_193 ) ;
T_7 * V_11 = F_2 ( V_77 ) ;
T_9 * V_194 ;
T_10 V_199 = 0 ;
F_109 (fcport, &vha->vp_fcports, list) {
if ( V_194 -> V_196 &&
V_192 -> V_197 == V_194 -> V_196 -> V_198 ) {
V_199 = F_110 ( V_194 -> V_199 ) ;
break;
}
}
F_113 ( V_192 ) = V_199 ;
}
static void
F_114 ( struct V_191 * V_192 )
{
struct V_95 * V_77 = F_3 ( V_192 -> V_79 . V_193 ) ;
T_7 * V_11 = F_2 ( V_77 ) ;
T_9 * V_194 ;
T_5 V_200 = ~ 0U ;
F_109 (fcport, &vha->vp_fcports, list) {
if ( V_194 -> V_196 &&
V_192 -> V_197 == V_194 -> V_196 -> V_198 ) {
V_200 = V_194 -> V_165 . V_166 . V_167 << 16 |
V_194 -> V_165 . V_166 . V_168 << 8 | V_194 -> V_165 . V_166 . V_169 ;
break;
}
}
F_115 ( V_192 ) = V_200 ;
}
static void
F_116 ( struct V_201 * V_196 , T_5 V_202 )
{
if ( V_202 )
V_196 -> V_203 = V_202 ;
else
V_196 -> V_203 = 1 ;
}
static void
F_117 ( struct V_201 * V_196 )
{
struct V_95 * V_77 = F_118 ( V_196 ) ;
T_9 * V_194 = * ( T_9 * * ) V_196 -> V_204 ;
unsigned long V_159 ;
if ( ! V_194 )
return;
F_119 ( V_194 , V_205 ) ;
F_120 ( V_77 -> V_206 , V_159 ) ;
V_194 -> V_196 = V_194 -> V_207 = NULL ;
* ( ( T_9 * * ) V_196 -> V_204 ) = NULL ;
F_121 ( V_77 -> V_206 , V_159 ) ;
if ( F_71 ( V_125 , & V_194 -> V_11 -> V_39 ) )
return;
if ( F_27 ( F_28 ( V_194 -> V_11 -> V_15 -> V_52 ) ) ) {
F_122 ( V_194 -> V_11 , V_208 << 16 ) ;
return;
}
}
static void
F_123 ( struct V_201 * V_196 )
{
T_9 * V_194 = * ( T_9 * * ) V_196 -> V_204 ;
if ( ! V_194 )
return;
if ( F_71 ( V_125 , & V_194 -> V_11 -> V_39 ) )
return;
if ( F_27 ( F_28 ( V_194 -> V_11 -> V_15 -> V_52 ) ) ) {
F_122 ( V_194 -> V_11 , V_208 << 16 ) ;
return;
}
if ( V_194 -> V_209 != V_210 &&
! F_71 ( V_211 , & V_194 -> V_11 -> V_39 ) )
V_194 -> V_11 -> V_15 -> V_24 -> V_212 ( V_194 -> V_11 ,
V_194 -> V_209 , V_194 -> V_165 . V_166 . V_167 ,
V_194 -> V_165 . V_166 . V_168 , V_194 -> V_165 . V_166 . V_169 ) ;
}
static int
F_124 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_125 ( V_11 ) ;
return 0 ;
}
static struct V_213 *
F_126 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_10 * V_76 = F_39 ( V_14 -> V_52 ) ;
int V_68 ;
struct V_214 * V_215 ;
T_11 V_216 ;
struct V_213 * V_217 ;
V_217 = & V_14 -> V_218 ;
memset ( V_217 , - 1 , sizeof( struct V_213 ) ) ;
if ( F_71 ( V_211 , & V_11 -> V_39 ) )
goto V_64;
if ( F_27 ( F_28 ( V_14 -> V_52 ) ) )
goto V_64;
V_215 = F_36 ( V_14 -> V_72 , V_73 , & V_216 ) ;
if ( V_215 == NULL ) {
F_97 ( F_98 ( L_65 ,
V_161 , V_76 -> V_21 ) ) ;
goto V_64;
}
memset ( V_215 , 0 , V_87 ) ;
V_68 = V_156 ;
if ( F_17 ( V_14 ) ) {
V_68 = F_127 ( V_76 , V_215 , V_216 ) ;
} else if ( F_70 ( & V_76 -> V_119 ) == V_124 &&
! F_71 ( V_125 , & V_76 -> V_39 ) &&
! F_71 ( V_38 , & V_76 -> V_39 ) &&
! V_14 -> V_219 ) {
V_68 = F_128 ( V_76 , V_76 -> V_209 ,
V_215 , V_216 ) ;
}
if ( V_68 != V_33 )
goto V_220;
V_217 -> V_221 = V_215 -> V_222 ;
V_217 -> V_223 = V_215 -> V_224 ;
V_217 -> V_225 = V_215 -> V_226 ;
V_217 -> V_227 = V_215 -> V_228 ;
V_217 -> V_229 = V_215 -> V_230 ;
V_217 -> V_231 = V_215 -> V_232 ;
if ( F_17 ( V_14 ) ) {
V_217 -> V_233 = V_215 -> V_234 ;
V_217 -> V_235 = V_215 -> V_235 ;
V_217 -> V_236 = V_215 -> V_236 ;
V_217 -> V_237 = V_215 -> V_237 ;
V_217 -> V_238 = V_215 -> V_239 ;
}
V_217 -> V_240 = V_14 -> V_144 . V_241 >> 20 ;
V_217 -> V_242 = V_14 -> V_144 . V_243 >> 20 ;
V_220:
F_129 ( V_14 -> V_72 , V_215 , V_216 ) ;
V_64:
return V_217 ;
}
static void
F_130 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_131 ( V_11 , F_132 ( V_164 ) ) ;
}
static void
F_133 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
F_21 ( V_244 , & V_11 -> V_39 ) ;
}
static void
F_134 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
T_6 V_195 [ V_245 ] = { 0xFF , 0xFF , 0xFF , 0xFF , \
0xFF , 0xFF , 0xFF , 0xFF } ;
T_10 V_246 = F_110 ( V_195 ) ;
if ( V_11 -> V_122 & V_247 )
V_246 = F_110 ( V_11 -> V_248 ) ;
F_135 ( V_164 ) = V_246 ;
}
static void
F_136 ( struct V_95 * V_164 )
{
T_7 * V_11 = F_2 ( V_164 ) ;
struct V_10 * V_76 = F_39 ( V_11 -> V_15 -> V_52 ) ;
if ( ! V_76 -> V_159 . V_249 )
F_137 ( V_164 ) = V_250 ;
else if ( F_70 ( & V_76 -> V_119 ) == V_251 )
F_137 ( V_164 ) = V_252 ;
else
F_137 ( V_164 ) = V_253 ;
}
static int
F_138 ( struct V_254 * V_254 , bool V_255 )
{
int V_97 = 0 ;
T_6 V_256 = 0 ;
T_7 * V_76 = F_2 ( V_254 -> V_164 ) ;
T_7 * V_11 = NULL ;
struct V_13 * V_14 = V_76 -> V_15 ;
T_4 V_257 = 0 ;
int V_29 ;
struct V_258 * V_259 = V_14 -> V_260 [ 0 ] ;
V_97 = F_139 ( V_254 ) ;
if ( V_97 ) {
F_140 ( F_98 ( L_66
L_67 , V_97 ) ) ;
return ( V_97 ) ;
}
V_11 = F_141 ( V_254 ) ;
if ( V_11 == NULL ) {
F_140 ( F_98 ( L_68 ,
V_11 ) ) ;
return V_261 ;
}
if ( V_255 ) {
F_142 ( & V_11 -> V_262 , V_263 ) ;
F_143 ( V_254 , V_264 ) ;
} else
F_142 ( & V_11 -> V_262 , V_265 ) ;
F_9 ( V_20 , V_11 -> V_15 , L_69 ,
V_11 -> V_185 ) ;
F_142 ( & V_11 -> V_119 , V_120 ) ;
V_11 -> V_266 = V_267 ;
V_11 -> V_268 = V_269 ;
if ( F_70 ( & V_76 -> V_119 ) == V_120 ||
F_70 ( & V_76 -> V_119 ) == V_121 ) {
F_140 ( F_98 ( L_70 ,
V_76 -> V_21 ) ) ;
F_142 ( & V_11 -> V_119 , V_121 ) ;
if ( ! V_255 )
F_143 ( V_254 , V_270 ) ;
}
if ( ( F_31 ( V_14 ) || F_42 ( V_14 ) ) && V_271 ) {
if ( V_14 -> V_272 & V_273 ) {
V_11 -> V_159 . V_274 = 1 ;
F_144 ( F_9 ( V_20 , V_14 ,
L_71
L_72 ) ) ;
F_145 ( V_11 -> V_77 ,
V_275
| V_276
| V_277
| V_278
| V_279
| V_280 ) ;
F_146 ( V_11 -> V_77 , V_281 ) ;
} else
V_11 -> V_159 . V_274 = 0 ;
}
if ( F_147 ( V_11 -> V_77 , & V_254 -> V_79 ,
& V_14 -> V_52 -> V_79 ) ) {
F_140 ( F_98 ( L_73 ,
V_11 -> V_21 , V_11 -> V_185 ) ) ;
goto V_282;
}
F_148 ( V_11 -> V_77 ) = V_14 -> V_283 ;
F_149 ( V_11 -> V_77 ) = F_110 ( V_11 -> V_195 ) ;
F_150 ( V_11 -> V_77 ) = F_110 ( V_11 -> V_199 ) ;
F_151 ( V_11 -> V_77 ) =
F_151 ( V_76 -> V_77 ) ;
F_152 ( V_11 -> V_77 ) =
F_152 ( V_76 -> V_77 ) ;
F_153 ( V_254 , V_255 ) ;
if ( V_14 -> V_159 . V_284 ) {
V_259 = V_14 -> V_260 [ 1 ] ;
goto V_285;
} else if ( V_286 == 1 || ! V_14 -> V_287 )
goto V_285;
for ( V_29 = 0 ; V_29 < V_14 -> V_288 ; V_29 ++ ) {
if ( memcmp ( V_14 -> V_287 [ V_29 ] . V_199 , V_11 -> V_199 , 8 ) == 0
&& memcmp ( V_14 -> V_287 [ V_29 ] . V_195 , V_11 -> V_195 ,
8 ) == 0 ) {
V_256 = V_14 -> V_287 [ V_29 ] . V_289 ;
break;
}
}
if ( V_256 ) {
V_97 = F_154 ( V_14 , V_257 , V_11 -> V_185 , 0 , 0 ,
V_256 ) ;
if ( ! V_97 )
F_9 ( V_34 , V_14 ,
L_74 ,
V_11 -> V_185 ) ;
else {
F_8 ( F_9 ( V_20 , V_14 ,
L_75 ,
V_97 , V_256 , V_11 -> V_185 ) ) ;
V_259 = V_14 -> V_260 [ V_97 ] ;
}
}
V_285:
V_11 -> V_259 = V_259 ;
return 0 ;
V_282:
F_155 ( V_11 ) ;
F_156 ( V_11 ) ;
F_157 ( V_11 -> V_77 ) ;
return V_261 ;
}
static int
F_158 ( struct V_254 * V_254 )
{
T_7 * V_11 = V_254 -> V_204 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 V_197 = V_11 -> V_185 ;
while ( F_71 ( V_290 , & V_11 -> V_39 ) ||
F_71 ( V_291 , & V_11 -> V_39 ) )
F_159 ( 1000 ) ;
F_155 ( V_11 ) ;
V_11 -> V_159 . V_292 = 1 ;
F_160 ( V_11 -> V_77 ) ;
F_161 ( V_11 -> V_77 ) ;
F_156 ( V_11 ) ;
if ( V_11 -> V_293 ) {
F_162 ( V_11 ) ;
F_140 ( F_98 ( V_20 L_76
L_77 , V_11 -> V_21 , V_11 -> V_185 , V_11 ) ) ;
}
F_163 ( F_159 ( F_164 () % 10 ) ) ;
F_165 ( F_70 ( & V_11 -> V_294 ) ) ;
F_166 ( V_11 ) ;
F_167 ( & V_14 -> V_295 ) ;
V_14 -> V_296 -- ;
F_168 ( V_11 -> V_185 , V_14 -> V_297 ) ;
F_169 ( & V_14 -> V_295 ) ;
if ( V_11 -> V_259 -> V_197 && ! V_14 -> V_159 . V_284 ) {
if ( F_170 ( V_11 , V_11 -> V_259 ) != V_33 )
F_9 ( V_34 , V_14 ,
L_78 ) ;
}
F_157 ( V_11 -> V_77 ) ;
F_9 ( V_20 , V_14 , L_79 , V_197 ) ;
return 0 ;
}
static int
F_153 ( struct V_254 * V_254 , bool V_255 )
{
T_7 * V_11 = V_254 -> V_204 ;
if ( V_255 )
F_155 ( V_11 ) ;
else
F_171 ( V_11 ) ;
return 0 ;
}
void
F_172 ( T_7 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_8 V_170 = V_171 ;
F_148 ( V_11 -> V_77 ) = V_14 -> V_283 ;
F_149 ( V_11 -> V_77 ) = F_110 ( V_11 -> V_195 ) ;
F_150 ( V_11 -> V_77 ) = F_110 ( V_11 -> V_199 ) ;
F_151 ( V_11 -> V_77 ) = V_298 ;
F_173 ( V_11 -> V_77 ) = V_14 -> V_299 ;
F_174 ( V_11 -> V_77 ) = V_14 -> V_296 ;
if ( F_32 ( V_14 ) )
V_170 = V_182 ;
else if ( F_31 ( V_14 ) )
V_170 = V_180 | V_178 |
V_176 | V_174 ;
else if ( F_175 ( V_14 ) )
V_170 = V_178 | V_176 |
V_174 ;
else if ( F_176 ( V_14 ) )
V_170 = V_176 | V_174 ;
else
V_170 = V_174 ;
F_152 ( V_11 -> V_77 ) = V_170 ;
}
