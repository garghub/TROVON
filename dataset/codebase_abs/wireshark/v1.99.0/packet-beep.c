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
F_11 ( V_13 , V_16 , & V_21 ) ;
V_17 = - 1 ;
break;
}
return V_17 ;
}
static int F_12 ( T_4 * V_12 , int V_14 )
{
unsigned int V_22 = 0 ;
while ( isdigit ( F_8 ( V_12 , V_14 + V_22 ) ) ) V_22 ++ ;
return V_22 ;
}
static int
F_13 ( T_4 * V_12 , T_5 * V_13 , int V_14 , T_6 * V_15 )
{
if ( ( F_8 ( V_12 , V_14 ) == 0x0d &&
F_8 ( V_12 , V_14 + 1 ) == 0x0a ) ) {
F_9 ( V_15 , V_23 , V_12 , V_14 , 2 , V_20 ) ;
return 2 ;
}
if ( ( F_8 ( V_12 , V_14 ) == 0x0d ) && ! V_24 ) {
F_14 ( V_15 , V_13 , & V_25 , V_12 , V_14 , 1 ) ;
return 1 ;
}
if ( ( F_8 ( V_12 , V_14 ) == 0x0a ) && ! V_24 ) {
F_14 ( V_15 , V_13 , & V_26 , V_12 , V_14 , 1 ) ;
return 1 ;
}
F_15 ( V_15 , V_13 , & V_27 , V_12 ,
V_14 , 1 , L_4 , F_16 ( V_12 , V_14 , 2 ) ) ;
return - 1 ;
}
static int F_17 ( T_4 * V_12 , int V_14 )
{
int V_22 = 0 ;
T_8 V_28 ;
while ( 1 ) {
if ( ( V_28 = F_8 ( V_12 , V_14 + V_22 ) ) == 0x0d
&& F_8 ( V_12 , V_14 + V_22 + 1 ) == 0x0a )
return V_22 ;
if ( ! V_24 && ( V_28 == 0x0d || V_28 == 0x0a ) )
return V_22 ;
V_22 ++ ;
}
}
static int
F_18 ( T_4 * V_12 , T_5 * V_13 , int V_14 ,
struct V_29 * V_30 ,
T_6 * V_15 )
{
T_6 * V_31 = NULL , * V_32 = NULL ;
int V_33 = F_17 ( V_12 , V_14 ) , V_34 = 0 ;
if ( V_30 && ! V_30 -> V_35 ) return 0 ;
if ( V_15 ) {
V_31 = F_9 ( V_15 , V_36 , V_12 , V_14 , V_33 , V_20 | V_37 ) ;
V_32 = F_19 ( V_31 , V_38 ) ;
}
if ( V_33 == 0 ) {
if ( V_15 ) {
F_20 ( V_32 , V_39 , V_12 , V_14 , 0 , L_5 , L_6 ) ;
}
if ( ( V_34 = F_13 ( V_12 , V_13 , V_14 , V_32 ) ) <= 0 ) {
}
}
else {
if ( V_15 ) {
F_9 ( V_32 , V_39 , V_12 , V_14 , V_33 , V_20 | V_37 ) ;
}
if ( ( V_34 = F_13 ( V_12 , V_13 , V_14 + V_33 , V_32 ) ) <= 0 ) {
}
}
return V_33 + V_34 ;
}
static int
F_21 ( T_4 * V_12 , int V_14 ,
T_6 * V_15 , int V_40 , int * V_9 , int * V_41 [] )
{
T_7 * V_16 ;
int V_42 , V_43 = 0 ;
unsigned int V_22 = F_12 ( V_12 , V_14 ) ;
T_8 V_44 [ 100 ] ;
memset ( V_44 , '\0' , sizeof( V_44 ) ) ;
F_22 ( V_12 , V_44 , V_14 , F_23 ( sizeof( V_44 ) - 1 , V_22 ) ) ;
if ( sscanf ( ( V_45 * ) V_44 , L_7 , & V_42 ) != 1 )
V_42 = 0 ;
if ( V_15 ) {
F_24 ( V_15 , V_40 , V_12 , V_14 , V_22 , V_42 ) ;
}
while ( V_41 [ V_43 ] ) {
V_16 = F_24 ( V_15 , * V_41 [ V_43 ] , V_12 , V_14 , V_22 , V_42 ) ;
F_10 ( V_16 ) ;
V_43 ++ ;
}
* V_9 = V_42 ;
return V_22 ;
}
static void
F_25 ( int V_18 , struct V_46 * V_47 ,
struct V_29 * V_30 , T_5 * V_13 )
{
if ( ! V_47 ) return;
if ( V_13 -> V_48 == V_49 ) {
if ( V_47 -> V_50 ) {
V_30 -> V_35 = 0 ;
if ( ! V_18 ) V_47 -> V_50 = 0 ;
}
else {
V_30 -> V_35 = 1 ;
if ( V_18 ) V_47 -> V_50 = 1 ;
}
}
else {
if ( V_47 -> V_51 ) {
V_30 -> V_35 = 0 ;
if ( ! V_18 ) V_47 -> V_51 = 0 ;
}
else {
V_30 -> V_35 = 1 ;
if ( V_18 ) V_47 -> V_51 = 1 ;
}
}
}
static int
F_26 ( T_4 * V_12 , int V_14 , T_5 * V_13 ,
T_6 * V_15 , struct V_46 * V_47 ,
struct V_29 * V_30 )
{
T_6 * V_31 = NULL , * V_52 = NULL ;
int V_53 , V_54 , V_55 , V_56 , V_57 , V_58 , V_59 , V_60 , V_34 ,
V_18 ;
const char * V_61 = NULL ;
int V_62 = 0 ;
V_53 = V_14 ;
if ( F_27 ( V_12 , V_14 , L_8 , 4 ) == 0 )
V_61 = L_9 ;
if ( F_27 ( V_12 , V_14 , L_10 , 4 ) == 0 )
V_61 = L_11 ;
if ( F_27 ( V_12 , V_14 , L_12 , 4 ) == 0 )
V_61 = L_13 ;
if ( F_27 ( V_12 , V_14 , L_14 , 4 ) == 0 )
V_61 = L_15 ;
if ( F_27 ( V_12 , V_14 , L_16 , 4 ) == 0 ) {
V_61 = L_17 ;
V_62 = 1 ;
}
if ( V_61 != NULL ) {
if ( V_15 ) {
V_52 = F_28 ( V_15 , V_12 , V_14 , F_17 ( V_12 , V_14 ) + 2 ,
V_63 , NULL , L_18 ) ;
V_31 = F_9 ( V_52 , V_64 , V_12 , V_14 , 3 , V_20 | V_37 ) ;
F_29 ( V_31 , 4 ) ;
F_30 ( V_52 , V_65 , V_12 , V_14 , 3 , TRUE ) ;
}
V_14 += 4 ;
V_14 += F_21 ( V_12 , V_14 , V_52 , V_66 , & V_58 , V_67 ) ;
V_14 += 1 ;
V_14 += F_21 ( V_12 , V_14 , V_52 , V_68 , & V_54 , V_69 ) ;
V_14 += 1 ;
if ( ( V_18 = F_7 ( V_12 , V_13 , V_14 , V_52 ) ) >= 0 ) {
F_25 ( V_18 , V_47 , V_30 , V_13 ) ;
}
else {
if ( V_15 && ( F_31 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_70 , V_12 , V_14 ,
F_31 ( V_12 , V_14 ) , V_20 | V_37 ) ;
}
return - 1 ;
}
V_14 += 2 ;
V_14 += F_21 ( V_12 , V_14 , V_52 , V_71 , & V_56 , V_72 ) ;
V_14 += 1 ;
V_14 += F_21 ( V_12 , V_14 , V_52 , V_73 , & V_57 , V_74 ) ;
if ( V_47 )
V_47 -> V_57 = V_57 ;
else if ( V_30 ) {
V_30 -> V_75 = V_57 ;
if ( V_30 -> V_75 < 0 ) V_30 -> V_75 = 0 ;
}
if ( V_62 ) {
V_14 += 1 ;
V_14 += F_21 ( V_12 , V_14 , V_52 , V_76 , & V_55 , V_77 ) ;
}
if ( ( V_34 = F_13 ( V_12 , V_13 , V_14 , V_52 ) ) <= 0 ) {
if ( V_15 && ( F_31 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_70 , V_12 , V_14 ,
F_31 ( V_12 , V_14 ) , V_20 | V_37 ) ;
}
return - 1 ;
}
V_14 += V_34 ;
if ( V_30 && V_30 -> V_35 )
V_14 += F_18 ( V_12 , V_13 , V_14 , V_30 , V_52 ) ;
if ( F_31 ( V_12 , V_14 ) > 0 ) {
int V_75 = F_23 ( V_57 , F_31 ( V_12 , V_14 ) ) ;
if ( V_15 ) {
F_9 ( V_15 , V_78 , V_12 , V_14 , V_75 , V_20 | V_37 ) ;
}
V_14 += V_75 ;
if ( V_47 ) {
V_47 -> V_57 -= V_75 ;
if ( V_47 -> V_57 < 0 ) V_47 -> V_57 = 0 ;
}
else if ( V_30 ) {
V_30 -> V_75 -= V_75 ;
if ( V_30 -> V_75 < 0 ) V_30 -> V_75 = 0 ;
}
}
if ( F_31 ( V_12 , V_14 ) > 0 )
V_14 += F_26 ( V_12 , V_14 , V_13 , V_15 , V_47 , V_30 ) ;
} else if ( F_27 ( V_12 , V_14 , L_19 , 4 ) == 0 ) {
if ( V_15 ) {
V_31 = F_9 ( V_52 , V_64 , V_12 , V_14 , 3 , V_20 | V_37 ) ;
F_29 ( V_31 , 4 ) ;
}
V_14 += 3 ;
V_14 += 1 ;
V_14 += F_21 ( V_12 , V_14 , V_15 , V_66 , & V_58 , V_79 ) ;
V_14 += 1 ;
V_14 += F_21 ( V_12 , V_14 , V_15 , V_80 , & V_59 , V_81 ) ;
V_14 += 1 ;
V_14 += F_21 ( V_12 , V_14 , V_15 , V_82 , & V_60 , V_83 ) ;
if ( ( V_34 = F_13 ( V_12 , V_13 , V_14 , V_15 ) ) <= 0 ) {
if ( V_15 && ( F_31 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_70 , V_12 , V_14 ,
F_31 ( V_12 , V_14 ) , V_20 | V_37 ) ;
}
return - 1 ;
}
V_14 += V_34 ;
} else if ( F_27 ( V_12 , V_14 , L_20 , 3 ) == 0 ) {
T_6 * V_84 = NULL ;
if ( V_15 ) {
V_84 = F_28 ( V_15 , V_12 , V_14 , F_23 ( 5 , F_32 ( 0 , F_31 ( V_12 , V_14 ) ) ) ,
V_85 , NULL , L_21 ) ;
F_9 ( V_52 , V_64 , V_12 , V_14 , 3 , V_20 | V_37 ) ;
}
V_14 += 3 ;
if ( ( V_34 = F_13 ( V_12 , V_13 , V_14 , V_84 ) ) <= 0 ) {
if ( V_15 && ( F_31 ( V_12 , V_14 ) > 0 ) ) {
F_9 ( V_15 , V_70 , V_12 , V_14 ,
F_31 ( V_12 , V_14 ) , V_20 | V_37 ) ;
}
return - 1 ;
}
V_14 += V_34 ;
}
if ( F_31 ( V_12 , V_14 ) > 0 ) {
int V_75 = 0 ;
if ( V_47 ) {
V_75 = F_23 ( V_47 -> V_57 , F_31 ( V_12 , V_14 ) ) ;
if ( V_75 == 0 ) {
V_75 = F_31 ( V_12 , V_14 ) ;
}
} else if ( V_30 ) {
V_75 = F_23 ( V_30 -> V_75 , F_31 ( V_12 , V_14 ) ) ;
} else {
V_75 = F_31 ( V_12 , V_14 ) ;
}
if ( V_75 == 0 && V_14 == V_53 )
V_75 = F_31 ( V_12 , V_14 ) ;
if ( V_75 > 0 ) {
if ( V_15 ) {
F_9 ( V_15 , V_78 , V_12 , V_14 , V_75 , V_20 | V_37 ) ;
}
V_14 += V_75 ;
if ( V_47 ) {
V_47 -> V_57 -= V_75 ;
if ( V_47 -> V_57 < 0 ) V_47 -> V_57 = 0 ;
}
else if ( V_30 ) {
V_30 -> V_75 -= V_75 ;
if ( V_30 -> V_75 < 0 ) V_30 -> V_75 = 0 ;
}
}
if ( F_31 ( V_12 , V_14 ) > 0 ) {
V_14 += F_26 ( V_12 , V_14 , V_13 , V_15 , V_47 , V_30 ) ;
}
}
return V_14 - V_53 ;
}
static void
F_33 ( T_4 * V_12 , T_5 * V_13 , T_6 * V_15 )
{
int V_14 ;
struct V_29 * V_30 ;
T_6 * V_86 = NULL , * V_31 = NULL ;
T_9 * V_7 = NULL ;
struct V_3 V_87 , * V_88 ;
struct V_46 * V_47 = NULL ;
V_14 = 0 ;
V_30 = (struct V_29 * ) F_34 ( F_35 () , V_13 , V_89 , 0 ) ;
if ( ! V_30 ) {
V_7 = F_36 ( V_13 ) ;
V_87 . V_7 = V_7 -> V_90 ;
V_47 = (struct V_46 * ) F_37 ( V_11 , & V_87 ) ;
if ( ! V_47 ) {
V_88 = F_38 ( F_35 () , struct V_3 ) ;
V_88 -> V_7 = V_7 -> V_90 ;
V_47 = F_38 ( F_35 () , struct V_46 ) ;
V_47 -> V_91 = 0 ;
V_47 -> V_57 = 0 ;
F_39 ( V_11 , V_88 , V_47 ) ;
}
}
F_40 ( V_13 -> V_92 , V_93 , L_22 ) ;
if ( F_31 ( V_12 , V_14 ) > 0 )
F_41 ( V_13 -> V_92 , V_94 , F_16 ( V_12 , V_14 , F_31 ( V_12 , V_14 ) ) ) ;
if ( V_15 ) {
V_31 = F_9 ( V_15 , V_89 , V_12 , V_14 , - 1 , V_20 ) ;
V_86 = F_19 ( V_31 , V_95 ) ;
}
if ( V_30 != NULL && V_30 -> V_96 > 0 ) {
int V_96 = V_30 -> V_96 ;
V_96 = F_23 ( V_96 , F_32 ( 0 , F_31 ( V_12 , V_14 ) ) ) ;
if ( V_15 && ( V_96 > 0 ) ) {
F_9 ( V_15 , V_78 , V_12 , V_14 , V_96 , V_20 | V_37 ) ;
}
V_14 += V_96 ;
}
else if ( V_47 && V_47 -> V_57 > 0 ) {
int V_96 = V_47 -> V_57 ;
V_47 -> V_57 = 0 ;
V_30 = F_38 ( F_35 () , struct V_29 ) ;
V_30 -> V_96 = V_96 ;
V_30 -> V_75 = 0 ;
V_30 -> V_35 = 0 ;
F_42 ( F_35 () , V_13 , V_89 , 0 , V_30 ) ;
}
if ( V_30 == NULL ) {
V_30 = F_38 ( F_35 () , struct V_29 ) ;
V_30 -> V_96 = 0 ;
V_30 -> V_75 = 0 ;
V_30 -> V_35 = 0 ;
F_42 ( F_35 () , V_13 , V_89 , 0 , V_30 ) ;
}
if ( F_31 ( V_12 , V_14 ) > 0 ) {
F_26 ( V_12 , V_14 , V_13 , V_86 , V_47 , V_30 ) ;
}
}
void
F_43 ( void )
{
static T_10 V_40 [] = {
{ & V_65 ,
{ L_23 , L_24 , V_97 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_64 ,
{ L_25 , L_26 , V_100 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_101 ,
{ L_27 , L_28 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
#if 0
{ &hf_beep_rsp,
{ "Response", "beep.rsp", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_rsp_chan,
{ "Response Channel Number", "beep.rsp.channel", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ & V_104 ,
{ L_29 , L_30 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_19 ,
{ L_31 , L_32 , V_105 , V_106 , F_44 ( V_107 ) , 0x0 , NULL , V_99 } } ,
{ & V_68 ,
{ L_33 , L_34 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_76 ,
{ L_35 , L_36 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_71 ,
{ L_37 , L_38 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_73 ,
{ L_39 , L_40 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_66 ,
{ L_41 , L_42 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_36 ,
{ L_43 , L_44 , V_100 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_39 ,
{ L_18 , L_45 , V_100 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
#if 0
{ &hf_beep_status,
{ "Status", "beep.status", FT_UINT8, BASE_HEX, VALS(beep_status_vals), 0x0, NULL, HFILL }},
#endif
{ & V_80 ,
{ L_46 , L_47 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_82 ,
{ L_48 , L_49 , V_102 , V_103 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_78 ,
{ L_50 , L_51 , V_100 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_70 ,
{ L_52 , L_53 , V_100 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_23 ,
{ L_54 , L_55 , V_108 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
} ;
static T_1 * V_109 [] = {
& V_95 ,
& V_38 ,
& V_63 ,
& V_85 ,
} ;
static T_11 V_110 [] = {
{ & V_21 , { L_56 , V_111 , V_112 , L_57 , V_113 } } ,
{ & V_25 , { L_58 , V_111 , V_112 , L_59 , V_113 } } ,
{ & V_26 , { L_60 , V_111 , V_112 , L_61 , V_113 } } ,
{ & V_27 , { L_62 , V_111 , V_112 , L_63 , V_113 } } ,
} ;
T_12 * V_114 ;
T_13 * V_115 ;
V_89 = F_45 ( L_64 ,
L_22 , L_65 ) ;
F_46 ( V_89 , V_40 , F_47 ( V_40 ) ) ;
F_48 ( V_109 , F_47 ( V_109 ) ) ;
V_115 = F_49 ( V_89 ) ;
F_50 ( V_115 , V_110 , F_47 ( V_110 ) ) ;
F_51 ( & F_4 ) ;
V_114 = F_52 ( V_89 , V_116 ) ;
F_53 ( V_114 , L_66 , L_67 ,
L_68
L_69 ,
10 , & V_49 ) ;
F_54 ( V_114 , L_70 ,
L_71 ,
L_72
L_73 ,
& V_24 ) ;
}
void
V_116 ( void )
{
static T_14 V_117 = FALSE ;
static T_15 V_118 ;
static T_3 V_119 ;
if ( ! V_117 ) {
V_118 = F_55 ( F_33 , V_89 ) ;
V_117 = TRUE ;
}
else {
F_56 ( L_66 , V_119 , V_118 ) ;
}
V_119 = V_49 ;
F_57 ( L_66 , V_49 , V_118 ) ;
}
