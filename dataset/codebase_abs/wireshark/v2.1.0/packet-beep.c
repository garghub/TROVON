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
V_10 = F_5 ( F_3 , F_1 ) ;
}
static void
F_6 ( void )
{
F_7 ( V_10 ) ;
}
static int
F_8 ( T_4 * V_11 , T_5 * V_12 , int V_13 ,
T_6 * V_14 )
{
T_7 * V_15 ;
int V_16 = 0 ;
T_8 V_17 = F_9 ( V_11 , V_13 ) ;
V_15 = F_10 ( V_14 , V_18 , V_11 , V_13 , 1 , V_19 ) ;
F_11 ( V_15 ) ;
switch( V_17 ) {
case '.' :
V_16 = 0 ;
break;
case '*' :
V_16 = 1 ;
break;
default:
F_12 ( V_12 , V_15 , & V_20 ) ;
V_16 = - 1 ;
break;
}
return V_16 ;
}
static int F_13 ( T_4 * V_11 , int V_13 )
{
unsigned int V_21 = 0 ;
while ( F_14 ( F_9 ( V_11 , V_13 + V_21 ) ) ) V_21 ++ ;
return V_21 ;
}
static int
F_15 ( T_4 * V_11 , T_5 * V_12 , int V_13 , T_6 * V_14 )
{
if ( ( F_9 ( V_11 , V_13 ) == 0x0d &&
F_9 ( V_11 , V_13 + 1 ) == 0x0a ) ) {
F_10 ( V_14 , V_22 , V_11 , V_13 , 2 , V_23 ) ;
return 2 ;
}
if ( ( F_9 ( V_11 , V_13 ) == 0x0d ) && ! V_24 ) {
F_16 ( V_14 , V_12 , & V_25 , V_11 , V_13 , 1 ) ;
return 1 ;
}
if ( ( F_9 ( V_11 , V_13 ) == 0x0a ) && ! V_24 ) {
F_16 ( V_14 , V_12 , & V_26 , V_11 , V_13 , 1 ) ;
return 1 ;
}
F_17 ( V_14 , V_12 , & V_27 , V_11 ,
V_13 , 1 , L_3 , F_18 ( V_11 , V_13 , 2 ) ) ;
return - 1 ;
}
static int F_19 ( T_4 * V_11 , int V_13 )
{
int V_21 = 0 ;
T_8 V_28 ;
while ( 1 ) {
if ( ( V_28 = F_9 ( V_11 , V_13 + V_21 ) ) == 0x0d
&& F_9 ( V_11 , V_13 + V_21 + 1 ) == 0x0a )
return V_21 ;
if ( ! V_24 && ( V_28 == 0x0d || V_28 == 0x0a ) )
return V_21 ;
V_21 ++ ;
}
}
static int
F_20 ( T_4 * V_11 , T_5 * V_12 , int V_13 ,
struct V_29 * V_30 ,
T_6 * V_14 )
{
T_6 * V_31 = NULL , * V_32 = NULL ;
int V_33 = F_19 ( V_11 , V_13 ) , V_34 = 0 ;
if ( V_30 && ! V_30 -> V_35 ) return 0 ;
if ( V_14 ) {
V_31 = F_10 ( V_14 , V_36 , V_11 , V_13 , V_33 , V_23 | V_37 ) ;
V_32 = F_21 ( V_31 , V_38 ) ;
}
if ( V_33 == 0 ) {
if ( V_14 ) {
F_22 ( V_32 , V_39 , V_11 , V_13 , 0 , L_4 , L_5 ) ;
}
if ( ( V_34 = F_15 ( V_11 , V_12 , V_13 , V_32 ) ) <= 0 ) {
}
}
else {
if ( V_14 ) {
F_10 ( V_32 , V_39 , V_11 , V_13 , V_33 , V_23 | V_37 ) ;
}
if ( ( V_34 = F_15 ( V_11 , V_12 , V_13 + V_33 , V_32 ) ) <= 0 ) {
}
}
return V_33 + V_34 ;
}
static int
F_23 ( T_4 * V_11 , int V_13 ,
T_6 * V_14 , int V_40 , int * V_9 , int * V_41 [] )
{
T_7 * V_15 ;
int V_42 , V_43 = 0 ;
unsigned int V_21 = F_13 ( V_11 , V_13 ) ;
T_8 V_44 [ 100 ] ;
memset ( V_44 , '\0' , sizeof( V_44 ) ) ;
F_24 ( V_11 , V_44 , V_13 , F_25 ( sizeof( V_44 ) - 1 , V_21 ) ) ;
if ( sscanf ( ( V_45 * ) V_44 , L_6 , & V_42 ) != 1 )
V_42 = 0 ;
if ( V_14 ) {
F_26 ( V_14 , V_40 , V_11 , V_13 , V_21 , V_42 ) ;
}
while ( V_41 [ V_43 ] ) {
V_15 = F_26 ( V_14 , * V_41 [ V_43 ] , V_11 , V_13 , V_21 , V_42 ) ;
F_11 ( V_15 ) ;
V_43 ++ ;
}
* V_9 = V_42 ;
return V_21 ;
}
static void
F_27 ( int V_17 , struct V_46 * V_47 ,
struct V_29 * V_30 , T_5 * V_12 )
{
if ( ! V_47 ) return;
if ( V_12 -> V_48 == V_49 ) {
if ( V_47 -> V_50 ) {
V_30 -> V_35 = 0 ;
if ( ! V_17 ) V_47 -> V_50 = 0 ;
}
else {
V_30 -> V_35 = 1 ;
if ( V_17 ) V_47 -> V_50 = 1 ;
}
}
else {
if ( V_47 -> V_51 ) {
V_30 -> V_35 = 0 ;
if ( ! V_17 ) V_47 -> V_51 = 0 ;
}
else {
V_30 -> V_35 = 1 ;
if ( V_17 ) V_47 -> V_51 = 1 ;
}
}
}
static int
F_28 ( T_4 * V_11 , int V_13 , T_5 * V_12 ,
T_6 * V_14 , struct V_46 * V_47 ,
struct V_29 * V_30 )
{
T_6 * V_31 = NULL , * V_52 = NULL ;
int V_53 , V_54 , V_55 , V_56 , V_57 , V_58 , V_59 , V_60 , V_34 ,
V_17 ;
const char * V_61 = NULL ;
int V_62 = 0 ;
V_53 = V_13 ;
if ( F_29 ( V_11 , V_13 , L_7 , 4 ) == 0 )
V_61 = L_8 ;
if ( F_29 ( V_11 , V_13 , L_9 , 4 ) == 0 )
V_61 = L_10 ;
if ( F_29 ( V_11 , V_13 , L_11 , 4 ) == 0 )
V_61 = L_12 ;
if ( F_29 ( V_11 , V_13 , L_13 , 4 ) == 0 )
V_61 = L_14 ;
if ( F_29 ( V_11 , V_13 , L_15 , 4 ) == 0 ) {
V_61 = L_16 ;
V_62 = 1 ;
}
if ( V_61 != NULL ) {
if ( V_14 ) {
V_52 = F_30 ( V_14 , V_11 , V_13 , F_19 ( V_11 , V_13 ) + 2 ,
V_63 , NULL , L_17 ) ;
V_31 = F_10 ( V_52 , V_64 , V_11 , V_13 , 3 , V_23 | V_37 ) ;
F_31 ( V_31 , 4 ) ;
F_32 ( V_52 , V_65 , V_11 , V_13 , 3 , TRUE ) ;
}
V_13 += 4 ;
V_13 += F_23 ( V_11 , V_13 , V_52 , V_66 , & V_58 , V_67 ) ;
V_13 += 1 ;
V_13 += F_23 ( V_11 , V_13 , V_52 , V_68 , & V_54 , V_69 ) ;
V_13 += 1 ;
if ( ( V_17 = F_8 ( V_11 , V_12 , V_13 , V_52 ) ) >= 0 ) {
F_27 ( V_17 , V_47 , V_30 , V_12 ) ;
}
else {
if ( V_14 && ( F_33 ( V_11 , V_13 ) > 0 ) ) {
F_10 ( V_14 , V_70 , V_11 , V_13 ,
F_33 ( V_11 , V_13 ) , V_23 | V_37 ) ;
}
return - 1 ;
}
V_13 += 2 ;
V_13 += F_23 ( V_11 , V_13 , V_52 , V_71 , & V_56 , V_72 ) ;
V_13 += 1 ;
V_13 += F_23 ( V_11 , V_13 , V_52 , V_73 , & V_57 , V_74 ) ;
if ( V_47 )
V_47 -> V_57 = V_57 ;
else if ( V_30 ) {
V_30 -> V_75 = V_57 ;
if ( V_30 -> V_75 < 0 ) V_30 -> V_75 = 0 ;
}
if ( V_62 ) {
V_13 += 1 ;
V_13 += F_23 ( V_11 , V_13 , V_52 , V_76 , & V_55 , V_77 ) ;
}
if ( ( V_34 = F_15 ( V_11 , V_12 , V_13 , V_52 ) ) <= 0 ) {
if ( V_14 && ( F_33 ( V_11 , V_13 ) > 0 ) ) {
F_10 ( V_14 , V_70 , V_11 , V_13 ,
F_33 ( V_11 , V_13 ) , V_23 | V_37 ) ;
}
return - 1 ;
}
V_13 += V_34 ;
if ( V_30 && V_30 -> V_35 )
V_13 += F_20 ( V_11 , V_12 , V_13 , V_30 , V_52 ) ;
if ( F_33 ( V_11 , V_13 ) > 0 ) {
int V_75 = F_25 ( V_57 , F_33 ( V_11 , V_13 ) ) ;
if ( V_14 ) {
F_10 ( V_14 , V_78 , V_11 , V_13 , V_75 , V_23 | V_37 ) ;
}
V_13 += V_75 ;
if ( V_47 ) {
V_47 -> V_57 -= V_75 ;
if ( V_47 -> V_57 < 0 ) V_47 -> V_57 = 0 ;
}
else if ( V_30 ) {
V_30 -> V_75 -= V_75 ;
if ( V_30 -> V_75 < 0 ) V_30 -> V_75 = 0 ;
}
}
if ( F_33 ( V_11 , V_13 ) > 0 )
V_13 += F_28 ( V_11 , V_13 , V_12 , V_14 , V_47 , V_30 ) ;
} else if ( F_29 ( V_11 , V_13 , L_18 , 4 ) == 0 ) {
if ( V_14 ) {
V_31 = F_10 ( V_52 , V_64 , V_11 , V_13 , 3 , V_23 | V_37 ) ;
F_31 ( V_31 , 4 ) ;
}
V_13 += 3 ;
V_13 += 1 ;
V_13 += F_23 ( V_11 , V_13 , V_14 , V_66 , & V_58 , V_79 ) ;
V_13 += 1 ;
V_13 += F_23 ( V_11 , V_13 , V_14 , V_80 , & V_59 , V_81 ) ;
V_13 += 1 ;
V_13 += F_23 ( V_11 , V_13 , V_14 , V_82 , & V_60 , V_83 ) ;
if ( ( V_34 = F_15 ( V_11 , V_12 , V_13 , V_14 ) ) <= 0 ) {
if ( V_14 && ( F_33 ( V_11 , V_13 ) > 0 ) ) {
F_10 ( V_14 , V_70 , V_11 , V_13 ,
F_33 ( V_11 , V_13 ) , V_23 | V_37 ) ;
}
return - 1 ;
}
V_13 += V_34 ;
} else if ( F_29 ( V_11 , V_13 , L_19 , 3 ) == 0 ) {
T_6 * V_84 = NULL ;
if ( V_14 ) {
V_84 = F_30 ( V_14 , V_11 , V_13 , F_25 ( 5 , F_34 ( 0 , F_33 ( V_11 , V_13 ) ) ) ,
V_85 , NULL , L_20 ) ;
F_10 ( V_52 , V_64 , V_11 , V_13 , 3 , V_23 | V_37 ) ;
}
V_13 += 3 ;
if ( ( V_34 = F_15 ( V_11 , V_12 , V_13 , V_84 ) ) <= 0 ) {
if ( V_14 && ( F_33 ( V_11 , V_13 ) > 0 ) ) {
F_10 ( V_14 , V_70 , V_11 , V_13 ,
F_33 ( V_11 , V_13 ) , V_23 | V_37 ) ;
}
return - 1 ;
}
V_13 += V_34 ;
}
if ( F_33 ( V_11 , V_13 ) > 0 ) {
int V_75 = 0 ;
if ( V_47 ) {
V_75 = F_25 ( V_47 -> V_57 , F_33 ( V_11 , V_13 ) ) ;
if ( V_75 == 0 ) {
V_75 = F_33 ( V_11 , V_13 ) ;
}
} else if ( V_30 ) {
V_75 = F_25 ( V_30 -> V_75 , F_33 ( V_11 , V_13 ) ) ;
} else {
V_75 = F_33 ( V_11 , V_13 ) ;
}
if ( V_75 == 0 && V_13 == V_53 )
V_75 = F_33 ( V_11 , V_13 ) ;
if ( V_75 > 0 ) {
if ( V_14 ) {
F_10 ( V_14 , V_78 , V_11 , V_13 , V_75 , V_23 | V_37 ) ;
}
V_13 += V_75 ;
if ( V_47 ) {
V_47 -> V_57 -= V_75 ;
if ( V_47 -> V_57 < 0 ) V_47 -> V_57 = 0 ;
}
else if ( V_30 ) {
V_30 -> V_75 -= V_75 ;
if ( V_30 -> V_75 < 0 ) V_30 -> V_75 = 0 ;
}
}
if ( F_33 ( V_11 , V_13 ) > 0 ) {
V_13 += F_28 ( V_11 , V_13 , V_12 , V_14 , V_47 , V_30 ) ;
}
}
return V_13 - V_53 ;
}
static int
F_35 ( T_4 * V_11 , T_5 * V_12 , T_6 * V_14 , void * T_9 V_86 )
{
int V_13 ;
struct V_29 * V_30 ;
T_6 * V_87 = NULL , * V_31 = NULL ;
T_10 * V_7 = NULL ;
struct V_3 V_88 , * V_89 ;
struct V_46 * V_47 = NULL ;
V_13 = 0 ;
V_30 = (struct V_29 * ) F_36 ( F_37 () , V_12 , V_90 , 0 ) ;
if ( ! V_30 ) {
V_7 = F_38 ( V_12 ) ;
V_88 . V_7 = V_7 -> V_91 ;
V_47 = (struct V_46 * ) F_39 ( V_10 , & V_88 ) ;
if ( ! V_47 ) {
V_89 = F_40 ( F_37 () , struct V_3 ) ;
V_89 -> V_7 = V_7 -> V_91 ;
V_47 = F_40 ( F_37 () , struct V_46 ) ;
V_47 -> V_92 = 0 ;
V_47 -> V_57 = 0 ;
F_41 ( V_10 , V_89 , V_47 ) ;
}
}
F_42 ( V_12 -> V_93 , V_94 , L_21 ) ;
if ( F_33 ( V_11 , V_13 ) > 0 )
F_43 ( V_12 -> V_93 , V_95 , F_18 ( V_11 , V_13 , F_33 ( V_11 , V_13 ) ) ) ;
if ( V_14 ) {
V_31 = F_10 ( V_14 , V_90 , V_11 , V_13 , - 1 , V_23 ) ;
V_87 = F_21 ( V_31 , V_96 ) ;
}
if ( V_30 != NULL && V_30 -> V_97 > 0 ) {
int V_97 = V_30 -> V_97 ;
V_97 = F_25 ( V_97 , F_34 ( 0 , F_33 ( V_11 , V_13 ) ) ) ;
if ( V_14 && ( V_97 > 0 ) ) {
F_10 ( V_14 , V_78 , V_11 , V_13 , V_97 , V_23 | V_37 ) ;
}
V_13 += V_97 ;
}
else if ( V_47 && V_47 -> V_57 > 0 ) {
int V_97 = V_47 -> V_57 ;
V_47 -> V_57 = 0 ;
V_30 = F_40 ( F_37 () , struct V_29 ) ;
V_30 -> V_97 = V_97 ;
V_30 -> V_75 = 0 ;
V_30 -> V_35 = 0 ;
F_44 ( F_37 () , V_12 , V_90 , 0 , V_30 ) ;
}
if ( V_30 == NULL ) {
V_30 = F_40 ( F_37 () , struct V_29 ) ;
V_30 -> V_97 = 0 ;
V_30 -> V_75 = 0 ;
V_30 -> V_35 = 0 ;
F_44 ( F_37 () , V_12 , V_90 , 0 , V_30 ) ;
}
if ( F_33 ( V_11 , V_13 ) > 0 ) {
F_28 ( V_11 , V_13 , V_12 , V_87 , V_47 , V_30 ) ;
}
return F_45 ( V_11 ) ;
}
void
F_46 ( void )
{
static T_11 V_40 [] = {
{ & V_65 ,
{ L_22 , L_23 , V_98 , V_99 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_64 ,
{ L_24 , L_25 , V_101 , V_99 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_102 ,
{ L_26 , L_27 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
#if 0
{ &hf_beep_rsp,
{ "Response", "beep.rsp", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_rsp_chan,
{ "Response Channel Number", "beep.rsp.channel", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ & V_105 ,
{ L_28 , L_29 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_18 ,
{ L_30 , L_31 , V_106 , V_107 , F_47 ( V_108 ) , 0x0 , NULL , V_100 } } ,
{ & V_68 ,
{ L_32 , L_33 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_76 ,
{ L_34 , L_35 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_71 ,
{ L_36 , L_37 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_73 ,
{ L_38 , L_39 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_66 ,
{ L_40 , L_41 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_36 ,
{ L_42 , L_43 , V_101 , V_99 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_39 ,
{ L_17 , L_44 , V_101 , V_99 , NULL , 0x0 , NULL , V_100 } } ,
#if 0
{ &hf_beep_status,
{ "Status", "beep.status", FT_UINT8, BASE_HEX, VALS(beep_status_vals), 0x0, NULL, HFILL }},
#endif
{ & V_80 ,
{ L_45 , L_46 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_82 ,
{ L_47 , L_48 , V_103 , V_104 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_78 ,
{ L_49 , L_50 , V_101 , V_99 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_70 ,
{ L_51 , L_52 , V_101 , V_99 , NULL , 0x0 , NULL , V_100 } } ,
{ & V_22 ,
{ L_53 , L_54 , V_109 , V_99 , NULL , 0x0 , NULL , V_100 } } ,
} ;
static T_1 * V_110 [] = {
& V_96 ,
& V_38 ,
& V_63 ,
& V_85 ,
} ;
static T_12 V_111 [] = {
{ & V_20 , { L_55 , V_112 , V_113 , L_56 , V_114 } } ,
{ & V_25 , { L_57 , V_112 , V_113 , L_58 , V_114 } } ,
{ & V_26 , { L_59 , V_112 , V_113 , L_60 , V_114 } } ,
{ & V_27 , { L_61 , V_112 , V_113 , L_62 , V_114 } } ,
} ;
T_13 * V_115 ;
T_14 * V_116 ;
V_90 = F_48 ( L_63 ,
L_21 , L_64 ) ;
F_49 ( V_90 , V_40 , F_50 ( V_40 ) ) ;
F_51 ( V_110 , F_50 ( V_110 ) ) ;
V_116 = F_52 ( V_90 ) ;
F_53 ( V_116 , V_111 , F_50 ( V_111 ) ) ;
F_54 ( & F_4 ) ;
F_55 ( & F_6 ) ;
V_115 = F_56 ( V_90 , V_117 ) ;
F_57 ( V_115 , L_65 , L_66 ,
L_67
L_68 ,
10 , & V_49 ) ;
F_58 ( V_115 , L_69 ,
L_70 ,
L_71
L_72 ,
& V_24 ) ;
}
void
V_117 ( void )
{
static T_15 V_118 = FALSE ;
static T_16 V_119 ;
static T_3 V_120 ;
if ( ! V_118 ) {
V_119 = F_59 ( F_35 , V_90 ) ;
V_118 = TRUE ;
}
else {
F_60 ( L_65 , V_120 , V_119 ) ;
}
V_120 = V_49 ;
F_61 ( L_65 , V_49 , V_119 ) ;
}
