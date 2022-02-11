static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) V_1 ;
const struct V_3 * V_5 = ( const struct V_3 * ) V_2 ;
#if F_2 ( V_6 )
printf ( L_1 ,
V_4 -> V_7 , V_5 -> V_7 ) ;
#endif
if ( V_4 -> V_7 == V_5 -> V_7 )
return 1 ;
return 0 ;
}
static T_3
F_3 ( T_2 V_1 )
{
const struct V_3 * V_8 = ( const struct V_3 * ) V_1 ;
T_3 V_9 ;
V_9 = V_8 -> V_7 ;
#if F_2 ( V_6 )
printf ( L_2 , V_9 ) ;
#endif
return V_9 ;
}
static void
F_4 ( void )
{
#if F_2 ( V_6 )
fprintf ( V_10 , L_3 ) ;
#endif
if ( V_11 )
F_5 ( V_11 ) ;
V_11 = F_6 ( F_3 , F_1 ) ;
}
static int
F_7 ( T_4 * V_12 , T_5 * V_13 , int V_14 ,
T_6 * V_15 )
{
T_7 * V_16 ;
int V_17 = 0 ;
T_8 V_18 = F_8 ( V_12 , V_14 ) ;
V_16 = F_9 ( V_15 , V_19 , V_12 , V_14 , 1 , V_20 ) ;
F_10 ( V_16 ) ;
switch( V_18 ) {
case '.' :
V_17 = 0 ;
break;
case '*' :
V_17 = 1 ;
break;
default:
F_11 ( V_13 , V_16 , V_21 , V_22 , L_4 ) ;
V_17 = - 1 ;
break;
}
return V_17 ;
}
static int F_12 ( T_4 * V_12 , int V_14 )
{
unsigned int V_23 = 0 ;
while ( isdigit ( F_8 ( V_12 , V_14 + V_23 ) ) ) V_23 ++ ;
return V_23 ;
}
static int
F_13 ( T_4 * V_12 , T_5 * V_13 , int V_14 , T_6 * V_15 )
{
T_7 * V_24 ;
if ( ( F_8 ( V_12 , V_14 ) == 0x0d &&
F_8 ( V_12 , V_14 + 1 ) == 0x0a ) ) {
F_14 ( V_15 , V_12 , V_14 , 2 , L_5 ) ;
return 2 ;
}
if ( ( F_8 ( V_12 , V_14 ) == 0x0d ) && ! V_25 ) {
V_24 = F_14 ( V_15 , V_12 , V_14 , 1 , L_6 ) ;
F_11 ( V_13 , V_24 , V_21 , V_22 , L_7 ) ;
return 1 ;
}
if ( ( F_8 ( V_12 , V_14 ) == 0x0a ) && ! V_25 ) {
V_24 = F_14 ( V_15 , V_12 , V_14 , 1 , L_8 ) ;
F_11 ( V_13 , V_24 , V_21 , V_22 , L_9 ) ;
return 1 ;
}
V_24 = F_14 ( V_15 , V_12 , V_14 , 1 , L_10 , F_15 ( V_12 , V_14 , 2 ) ) ;
F_11 ( V_13 , V_24 , V_21 , V_22 , L_11 , F_15 ( V_12 , V_14 , 2 ) ) ;
return - 1 ;
}
static int F_16 ( T_4 * V_12 , int V_14 )
{
int V_23 = 0 ;
T_8 V_26 ;
while ( 1 ) {
if ( ( V_26 = F_8 ( V_12 , V_14 + V_23 ) ) == 0x0d
&& F_8 ( V_12 , V_14 + V_23 + 1 ) == 0x0a )
return V_23 ;
if ( ! V_25 && ( V_26 == 0x0d || V_26 == 0x0a ) )
return V_23 ;
V_23 ++ ;
}
}
static int
F_17 ( T_4 * V_12 , T_5 * V_13 , int V_14 ,
struct V_27 * V_28 ,
T_6 * V_15 )
{
T_6 * V_24 = NULL , * V_29 = NULL ;
int V_30 = F_16 ( V_12 , V_14 ) , V_31 = 0 ;
if ( V_28 && ! V_28 -> V_32 ) return 0 ;
if ( V_15 ) {
V_24 = F_9 ( V_15 , V_33 , V_12 , V_14 , V_30 , V_20 | V_34 ) ;
V_29 = F_18 ( V_24 , V_35 ) ;
}
if ( V_30 == 0 ) {
if ( V_15 ) {
F_14 ( V_29 , V_12 , V_14 , 0 , L_12 ) ;
}
if ( ( V_31 = F_13 ( V_12 , V_13 , V_14 , V_29 ) ) <= 0 ) {
}
}
else {
if ( V_15 ) {
F_9 ( V_29 , V_36 , V_12 , V_14 , V_30 , V_20 | V_34 ) ;
}
if ( ( V_31 = F_13 ( V_12 , V_13 , V_14 + V_30 , V_29 ) ) <= 0 ) {
}
}
return V_30 + V_31 ;
}
static int
F_19 ( T_4 * V_12 , int V_14 ,
T_6 * V_15 , int V_37 , int * V_9 , int * V_38 [] )
{
T_7 * V_16 ;
int V_39 , V_40 = 0 ;
unsigned int V_23 = F_12 ( V_12 , V_14 ) ;
T_8 V_41 [ 100 ] ;
memset ( V_41 , '\0' , sizeof( V_41 ) ) ;
F_20 ( V_12 , V_41 , V_14 , F_21 ( sizeof( V_41 ) - 1 , V_23 ) ) ;
if ( sscanf ( ( V_42 * ) V_41 , L_13 , & V_39 ) != 1 )
V_39 = 0 ;
if ( V_15 ) {
F_22 ( V_15 , V_37 , V_12 , V_14 , V_23 , V_39 ) ;
}
while ( V_38 [ V_40 ] ) {
V_16 = F_22 ( V_15 , * V_38 [ V_40 ] , V_12 , V_14 , V_23 , V_39 ) ;
F_10 ( V_16 ) ;
V_40 ++ ;
}
* V_9 = V_39 ;
return V_23 ;
}
static void
F_23 ( int V_18 , struct V_43 * V_44 ,
struct V_27 * V_28 , T_5 * V_13 )
{
if ( ! V_44 ) return;
if ( V_13 -> V_45 == V_46 ) {
if ( V_44 -> V_47 ) {
V_28 -> V_32 = 0 ;
if ( ! V_18 ) V_44 -> V_47 = 0 ;
}
else {
V_28 -> V_32 = 1 ;
if ( V_18 ) V_44 -> V_47 = 1 ;
}
}
else {
if ( V_44 -> V_48 ) {
V_28 -> V_32 = 0 ;
if ( ! V_18 ) V_44 -> V_48 = 0 ;
}
else {
V_28 -> V_32 = 1 ;
if ( V_18 ) V_44 -> V_48 = 1 ;
}
}
}
static int
F_24 ( T_4 * V_12 , int V_14 , T_5 * V_13 ,
T_6 * V_15 , struct V_43 * V_44 ,
struct V_27 * V_28 )
{
T_6 * V_24 = NULL , * V_49 = NULL ;
int V_50 , V_51 , V_52 , V_53 , V_54 , V_55 , V_56 , V_57 , V_31 ,
V_18 ;
const char * V_58 = NULL ;
int V_59 = 0 ;
V_50 = V_14 ;
if ( F_25 ( V_12 , V_14 , L_14 , 4 ) == 0 )
V_58 = L_15 ;
if ( F_25 ( V_12 , V_14 , L_16 , 4 ) == 0 )
V_58 = L_17 ;
if ( F_25 ( V_12 , V_14 , L_18 , 4 ) == 0 )
V_58 = L_19 ;
if ( F_25 ( V_12 , V_14 , L_20 , 4 ) == 0 )
V_58 = L_21 ;
if ( F_25 ( V_12 , V_14 , L_22 , 4 ) == 0 ) {
V_58 = L_23 ;
V_59 = 1 ;
}
if ( V_58 != NULL ) {
if ( V_15 ) {
V_24 = F_14 ( V_15 , V_12 , V_14 , F_16 ( V_12 , V_14 ) + 2 , L_24 ) ;
V_49 = F_18 ( V_24 , V_60 ) ;
V_24 = F_9 ( V_49 , V_61 , V_12 , V_14 , 3 , V_20 | V_34 ) ;
F_26 ( V_24 , 4 ) ;
F_27 ( V_49 , V_62 , V_12 , V_14 , 3 , TRUE ) ;
}
V_14 += 4 ;
V_14 += F_19 ( V_12 , V_14 , V_49 , V_63 , & V_55 , V_64 ) ;
V_14 += 1 ;
V_14 += F_19 ( V_12 , V_14 , V_49 , V_65 , & V_51 , V_66 ) ;
V_14 += 1 ;
if ( ( V_18 = F_7 ( V_12 , V_13 , V_14 , V_49 ) ) >= 0 ) {
F_23 ( V_18 , V_44 , V_28 , V_13 ) ;
}
else {
if ( V_15 && ( F_28 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_67 , V_12 , V_14 ,
F_28 ( V_12 , V_14 ) , V_20 | V_34 ) ;
}
return - 1 ;
}
V_14 += 2 ;
V_14 += F_19 ( V_12 , V_14 , V_49 , V_68 , & V_53 , V_69 ) ;
V_14 += 1 ;
V_14 += F_19 ( V_12 , V_14 , V_49 , V_70 , & V_54 , V_71 ) ;
if ( V_44 )
V_44 -> V_54 = V_54 ;
else if ( V_28 ) {
V_28 -> V_72 = V_54 ;
if ( V_28 -> V_72 < 0 ) V_28 -> V_72 = 0 ;
}
if ( V_59 ) {
V_14 += 1 ;
V_14 += F_19 ( V_12 , V_14 , V_49 , V_73 , & V_52 , V_74 ) ;
}
if ( ( V_31 = F_13 ( V_12 , V_13 , V_14 , V_49 ) ) <= 0 ) {
if ( V_15 && ( F_28 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_67 , V_12 , V_14 ,
F_28 ( V_12 , V_14 ) , V_20 | V_34 ) ;
}
return - 1 ;
}
V_14 += V_31 ;
if ( V_28 && V_28 -> V_32 )
V_14 += F_17 ( V_12 , V_13 , V_14 , V_28 , V_49 ) ;
if ( F_28 ( V_12 , V_14 ) > 0 ) {
int V_72 = F_21 ( V_54 , F_28 ( V_12 , V_14 ) ) ;
if ( V_15 ) {
F_9 ( V_15 , V_75 , V_12 , V_14 , V_72 , V_20 | V_34 ) ;
}
V_14 += V_72 ;
if ( V_44 ) {
V_44 -> V_54 -= V_72 ;
if ( V_44 -> V_54 < 0 ) V_44 -> V_54 = 0 ;
}
else if ( V_28 ) {
V_28 -> V_72 -= V_72 ;
if ( V_28 -> V_72 < 0 ) V_28 -> V_72 = 0 ;
}
}
if ( F_28 ( V_12 , V_14 ) > 0 )
V_14 += F_24 ( V_12 , V_14 , V_13 , V_15 , V_44 , V_28 ) ;
} else if ( F_25 ( V_12 , V_14 , L_25 , 4 ) == 0 ) {
if ( V_15 ) {
V_24 = F_9 ( V_49 , V_61 , V_12 , V_14 , 3 , V_20 | V_34 ) ;
F_26 ( V_24 , 4 ) ;
}
V_14 += 3 ;
V_14 += 1 ;
V_14 += F_19 ( V_12 , V_14 , V_15 , V_63 , & V_55 , V_76 ) ;
V_14 += 1 ;
V_14 += F_19 ( V_12 , V_14 , V_15 , V_77 , & V_56 , V_78 ) ;
V_14 += 1 ;
V_14 += F_19 ( V_12 , V_14 , V_15 , V_79 , & V_57 , V_80 ) ;
if ( ( V_31 = F_13 ( V_12 , V_13 , V_14 , V_15 ) ) <= 0 ) {
if ( V_15 && ( F_28 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_67 , V_12 , V_14 ,
F_28 ( V_12 , V_14 ) , V_20 | V_34 ) ;
}
return - 1 ;
}
V_14 += V_31 ;
} else if ( F_25 ( V_12 , V_14 , L_26 , 3 ) == 0 ) {
T_6 * V_81 = NULL ;
if ( V_15 ) {
V_24 = F_14 ( V_15 , V_12 , V_14 , F_21 ( 5 , F_29 ( 0 , F_28 ( V_12 , V_14 ) ) ) , L_27 ) ;
V_81 = F_18 ( V_24 , V_82 ) ;
F_9 ( V_49 , V_61 , V_12 , V_14 , 3 , V_20 | V_34 ) ;
}
V_14 += 3 ;
if ( ( V_31 = F_13 ( V_12 , V_13 , V_14 , V_81 ) ) <= 0 ) {
if ( V_15 && ( F_28 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_67 , V_12 , V_14 ,
F_28 ( V_12 , V_14 ) , V_20 | V_34 ) ;
}
return - 1 ;
}
V_14 += V_31 ;
}
if ( F_28 ( V_12 , V_14 ) > 0 ) {
int V_72 = 0 ;
if ( V_44 ) {
V_72 = F_21 ( V_44 -> V_54 , F_28 ( V_12 , V_14 ) ) ;
if ( V_72 == 0 ) {
V_72 = F_28 ( V_12 , V_14 ) ;
}
} else if ( V_28 ) {
V_72 = F_21 ( V_28 -> V_72 , F_28 ( V_12 , V_14 ) ) ;
} else {
V_72 = F_28 ( V_12 , V_14 ) ;
}
if ( V_72 == 0 && V_14 == V_50 )
V_72 = F_28 ( V_12 , V_14 ) ;
if ( V_72 > 0 ) {
if ( V_15 ) {
F_9 ( V_15 , V_75 , V_12 , V_14 , V_72 , V_20 | V_34 ) ;
}
V_14 += V_72 ;
if ( V_44 ) {
V_44 -> V_54 -= V_72 ;
if ( V_44 -> V_54 < 0 ) V_44 -> V_54 = 0 ;
}
else if ( V_28 ) {
V_28 -> V_72 -= V_72 ;
if ( V_28 -> V_72 < 0 ) V_28 -> V_72 = 0 ;
}
}
if ( F_28 ( V_12 , V_14 ) > 0 ) {
V_14 += F_24 ( V_12 , V_14 , V_13 , V_15 , V_44 , V_28 ) ;
}
}
return V_14 - V_50 ;
}
static void
F_30 ( T_4 * V_12 , T_5 * V_13 , T_6 * V_15 )
{
int V_14 ;
struct V_27 * V_28 ;
T_6 * V_83 = NULL , * V_24 = NULL ;
T_9 * V_7 = NULL ;
struct V_3 V_84 , * V_85 ;
struct V_43 * V_44 = NULL ;
V_14 = 0 ;
V_28 = (struct V_27 * ) F_31 ( V_13 -> V_86 , V_87 , 0 ) ;
if ( ! V_28 ) {
V_7 = F_32 ( V_13 ) ;
V_84 . V_7 = V_7 -> V_88 ;
V_44 = (struct V_43 * ) F_33 ( V_11 , & V_84 ) ;
if ( ! V_44 ) {
V_85 = (struct V_3 * ) F_34 ( sizeof( struct V_3 ) ) ;
V_85 -> V_7 = V_7 -> V_88 ;
V_44 = (struct V_43 * ) F_34 ( sizeof( struct V_43 ) ) ;
V_44 -> V_89 = 0 ;
V_44 -> V_54 = 0 ;
F_35 ( V_11 , V_85 , V_44 ) ;
}
}
F_36 ( V_13 -> V_90 , V_91 , L_28 ) ;
if ( F_28 ( V_12 , V_14 ) > 0 )
F_37 ( V_13 -> V_90 , V_92 , F_15 ( V_12 , V_14 , F_28 ( V_12 , V_14 ) ) ) ;
if ( V_15 ) {
V_24 = F_9 ( V_15 , V_87 , V_12 , V_14 , - 1 , V_20 ) ;
V_83 = F_18 ( V_24 , V_93 ) ;
}
if ( V_28 != NULL && V_28 -> V_94 > 0 ) {
int V_94 = V_28 -> V_94 ;
V_94 = F_21 ( V_94 , F_29 ( 0 , F_28 ( V_12 , V_14 ) ) ) ;
if ( V_15 && ( V_94 > 0 ) ) {
F_9 ( V_15 , V_75 , V_12 , V_14 , V_94 , V_20 | V_34 ) ;
}
V_14 += V_94 ;
}
else if ( V_44 && V_44 -> V_54 > 0 ) {
int V_94 = V_44 -> V_54 ;
V_44 -> V_54 = 0 ;
V_28 = F_38 ( struct V_27 ) ;
V_28 -> V_94 = V_94 ;
V_28 -> V_72 = 0 ;
V_28 -> V_32 = 0 ;
F_39 ( V_13 -> V_86 , V_87 , 0 , V_28 ) ;
}
if ( V_28 == NULL ) {
V_28 = (struct V_27 * ) F_34 ( sizeof( struct V_27 ) ) ;
V_28 -> V_94 = 0 ;
V_28 -> V_72 = 0 ;
V_28 -> V_32 = 0 ;
F_39 ( V_13 -> V_86 , V_87 , 0 , V_28 ) ;
}
if ( F_28 ( V_12 , V_14 ) > 0 ) {
V_14 += F_24 ( V_12 , V_14 , V_13 , V_83 , V_44 , V_28 ) ;
}
}
void
F_40 ( void )
{
static T_10 V_37 [] = {
{ & V_62 ,
{ L_29 , L_30 , V_95 , V_96 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_61 ,
{ L_31 , L_32 , V_98 , V_96 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_99 ,
{ L_33 , L_34 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
#if 0
{ &hf_beep_rsp,
{ "Response", "beep.rsp", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_rsp_chan,
{ "Response Channel Number", "beep.rsp.channel", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ & V_102 ,
{ L_35 , L_36 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_19 ,
{ L_37 , L_38 , V_103 , V_104 , F_41 ( V_105 ) , 0x0 , NULL , V_97 } } ,
{ & V_65 ,
{ L_39 , L_40 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_73 ,
{ L_41 , L_42 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_68 ,
{ L_43 , L_44 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_70 ,
{ L_45 , L_46 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_63 ,
{ L_47 , L_48 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_33 ,
{ L_49 , L_50 , V_98 , V_96 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_36 ,
{ L_24 , L_51 , V_98 , V_96 , NULL , 0x0 , NULL , V_97 } } ,
#if 0
{ &hf_beep_status,
{ "Status", "beep.status", FT_UINT8, BASE_HEX, VALS(beep_status_vals), 0x0, NULL, HFILL }},
#endif
{ & V_77 ,
{ L_52 , L_53 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_79 ,
{ L_54 , L_55 , V_100 , V_101 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_75 ,
{ L_56 , L_57 , V_98 , V_96 , NULL , 0x0 , NULL , V_97 } } ,
{ & V_67 ,
{ L_58 , L_59 , V_98 , V_96 , NULL , 0x0 , NULL , V_97 } } ,
} ;
static T_1 * V_106 [] = {
& V_93 ,
& V_35 ,
& V_60 ,
& V_82 ,
} ;
T_11 * V_107 ;
V_87 = F_42 ( L_60 ,
L_28 , L_61 ) ;
F_43 ( V_87 , V_37 , F_44 ( V_37 ) ) ;
F_45 ( V_106 , F_44 ( V_106 ) ) ;
F_46 ( & F_4 ) ;
V_107 = F_47 ( V_87 , V_108 ) ;
F_48 ( V_107 , L_62 , L_63 ,
L_64
L_65 ,
10 , & V_46 ) ;
F_49 ( V_107 , L_66 ,
L_67 ,
L_68
L_69 ,
& V_25 ) ;
}
void
V_108 ( void )
{
static T_12 V_109 = FALSE ;
static T_13 V_110 ;
static T_3 V_111 ;
if ( ! V_109 ) {
V_110 = F_50 ( F_30 , V_87 ) ;
V_109 = TRUE ;
}
else {
F_51 ( L_62 , V_111 , V_110 ) ;
}
V_111 = V_46 ;
F_52 ( L_62 , V_46 , V_110 ) ;
}
