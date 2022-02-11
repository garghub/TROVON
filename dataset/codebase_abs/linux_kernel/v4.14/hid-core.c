static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( & V_6 -> V_8 , V_3 ) ;
if ( F_3 ( V_9 , & V_6 -> V_10 ) &&
! F_3 ( V_11 , & V_6 -> V_10 ) &&
! F_3 ( V_12 , & V_6 -> V_10 ) &&
! F_4 ( V_13 , & V_6 -> V_10 ) ) {
V_4 = F_5 ( V_6 -> V_14 , V_15 ) ;
if ( V_4 != 0 ) {
F_6 ( V_13 , & V_6 -> V_10 ) ;
if ( V_4 == - V_16 )
F_7 ( V_17 , & V_6 -> V_10 ) ;
} else {
F_6 ( V_17 , & V_6 -> V_10 ) ;
}
}
F_8 ( & V_6 -> V_8 , V_3 ) ;
return V_4 ;
}
static void F_9 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_10 ( & V_6 -> V_19 -> V_20 , L_1 ) ;
if ( F_1 ( V_2 ) )
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_21 * V_22 )
{
struct V_5 * V_6 =
F_13 ( V_22 , struct V_5 , V_23 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_4 ;
if ( F_3 ( V_24 , & V_6 -> V_10 ) ) {
F_10 ( & V_6 -> V_19 -> V_20 , L_2 ) ;
V_4 = F_14 ( F_15 ( V_2 ) , V_6 -> V_14 -> V_25 ) ;
F_6 ( V_24 , & V_6 -> V_10 ) ;
if ( V_4 == 0 ) {
F_1 ( V_2 ) ;
} else {
F_10 ( & V_6 -> V_19 -> V_20 ,
L_3 , V_4 ) ;
F_7 ( V_26 , & V_6 -> V_10 ) ;
}
}
if ( F_3 ( V_26 , & V_6 -> V_10 ) ) {
F_10 ( & V_6 -> V_19 -> V_20 , L_4 ) ;
F_16 ( V_6 -> V_19 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( & V_6 -> V_8 , V_3 ) ;
if ( F_3 ( V_11 , & V_6 -> V_10 ) )
goto V_27;
if ( F_17 ( V_28 , V_6 -> V_29 + V_30 / 2 ) )
V_6 -> V_31 = 0 ;
if ( V_6 -> V_31 == 0 ) {
V_6 -> V_31 = 13 ;
V_6 -> V_29 = V_28 + F_18 ( 1000 ) ;
} else if ( V_6 -> V_31 < 100 )
V_6 -> V_31 *= 2 ;
if ( F_17 ( V_28 , V_6 -> V_29 ) ) {
if ( ! F_3 ( V_17 , & V_6 -> V_10 )
&& ! F_4 ( V_26 , & V_6 -> V_10 ) ) {
F_19 ( & V_6 -> V_23 ) ;
goto V_27;
}
}
F_20 ( & V_6 -> V_32 ,
V_28 + F_18 ( V_6 -> V_31 ) ) ;
V_27:
F_8 ( & V_6 -> V_8 , V_3 ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_33 * V_19 = V_6 -> V_19 ;
F_22 ( F_23 ( V_19 ) ) ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_25 ( V_6 -> V_19 ) ;
int V_34 ;
int V_35 ;
if ( ! V_2 || F_3 ( V_26 , & V_6 -> V_10 ) ||
F_3 ( V_12 , & V_6 -> V_10 ) )
return 0 ;
if ( ( V_34 = ( V_6 -> V_36 != V_6 -> V_37 ) ) ) {
F_26 ( V_2 , L_5 , V_6 -> V_36 , V_6 -> V_37 ) ;
V_35 = F_27 ( V_6 -> V_19 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_3 ( V_12 , & V_6 -> V_10 ) ) {
F_28 ( V_6 -> V_19 ) ;
return V_35 ;
}
F_7 ( V_38 , & V_6 -> V_10 ) ;
if ( F_29 ( V_2 ) ) {
F_6 ( V_38 , & V_6 -> V_10 ) ;
F_30 ( V_6 -> V_19 ) ;
}
F_31 ( & V_6 -> V_39 ) ;
}
return V_34 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_25 ( V_6 -> V_19 ) ;
int V_34 ;
int V_35 ;
F_33 ( V_2 == NULL ) ;
if ( ! V_2 || F_3 ( V_26 , & V_6 -> V_10 ) ||
F_3 ( V_12 , & V_6 -> V_10 ) )
return 0 ;
if ( ( V_34 = ( V_6 -> V_40 != V_6 -> V_41 ) ) ) {
F_26 ( V_2 , L_5 , V_6 -> V_40 , V_6 -> V_41 ) ;
V_35 = F_27 ( V_6 -> V_19 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_3 ( V_12 , & V_6 -> V_10 ) ) {
F_28 ( V_6 -> V_19 ) ;
return V_35 ;
}
F_7 ( V_42 , & V_6 -> V_10 ) ;
if ( F_34 ( V_2 ) ) {
F_6 ( V_42 , & V_6 -> V_10 ) ;
F_30 ( V_6 -> V_19 ) ;
}
F_31 ( & V_6 -> V_39 ) ;
}
return V_34 ;
}
static void F_35 ( struct V_43 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_45 ;
switch ( V_43 -> V_45 ) {
case 0 :
V_6 -> V_31 = 0 ;
if ( ! F_3 ( V_46 , & V_6 -> V_10 ) )
break;
F_21 ( V_6 ) ;
if ( ! F_3 ( V_47 , & V_6 -> V_10 ) ) {
F_36 ( V_43 -> V_44 , V_48 ,
V_43 -> V_49 ,
V_43 -> V_50 , 1 ) ;
if ( F_37 ( V_2 ) )
F_7 ( V_51 , & V_6 -> V_10 ) ;
else
F_6 ( V_51 , & V_6 -> V_10 ) ;
}
break;
case - V_52 :
F_21 ( V_6 ) ;
F_6 ( V_13 , & V_6 -> V_10 ) ;
F_7 ( V_24 , & V_6 -> V_10 ) ;
F_19 ( & V_6 -> V_23 ) ;
return;
case - V_53 :
case - V_54 :
case - V_55 :
F_6 ( V_13 , & V_6 -> V_10 ) ;
return;
case - V_56 :
case - V_57 :
case - V_58 :
case - V_59 :
F_21 ( V_6 ) ;
F_6 ( V_13 , & V_6 -> V_10 ) ;
F_11 ( V_2 ) ;
return;
default:
F_38 ( V_43 -> V_20 , L_6 ,
V_43 -> V_45 ) ;
}
V_45 = F_5 ( V_43 , V_15 ) ;
if ( V_45 ) {
F_6 ( V_13 , & V_6 -> V_10 ) ;
if ( V_45 != - V_60 ) {
F_39 ( V_2 , L_7 ,
F_15 ( V_2 ) -> V_61 -> V_62 ,
F_15 ( V_2 ) -> V_63 ,
V_6 -> V_64 , V_45 ) ;
F_11 ( V_2 ) ;
}
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
char * V_67 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_35 ;
V_66 = V_6 -> V_68 [ V_6 -> V_37 ] . V_66 ;
V_67 = V_6 -> V_68 [ V_6 -> V_37 ] . V_67 ;
V_6 -> V_69 -> V_70 = F_40 ( V_66 ) ;
V_6 -> V_69 -> V_20 = F_15 ( V_2 ) ;
if ( V_67 ) {
memcpy ( V_6 -> V_71 , V_67 ,
V_6 -> V_69 -> V_70 ) ;
F_41 ( V_67 ) ;
V_6 -> V_68 [ V_6 -> V_37 ] . V_67 = NULL ;
}
F_42 ( L_8 ) ;
V_35 = F_5 ( V_6 -> V_69 , V_15 ) ;
if ( V_35 < 0 ) {
F_39 ( V_2 , L_9 , V_35 ) ;
return V_35 ;
}
V_6 -> V_72 = V_28 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
unsigned char V_73 ;
char * V_67 ;
int V_74 , V_35 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_66 = V_6 -> V_75 [ V_6 -> V_41 ] . V_66 ;
V_67 = V_6 -> V_75 [ V_6 -> V_41 ] . V_67 ;
V_73 = V_6 -> V_75 [ V_6 -> V_41 ] . V_73 ;
V_74 = ( ( V_66 -> V_76 - 1 ) >> 3 ) + 1 + ( V_66 -> V_77 > 0 ) ;
if ( V_73 == V_78 ) {
V_6 -> V_79 -> V_25 = F_43 ( F_15 ( V_2 ) , 0 ) ;
V_6 -> V_79 -> V_70 = V_74 ;
if ( V_67 ) {
memcpy ( V_6 -> V_80 , V_67 , V_74 ) ;
F_41 ( V_67 ) ;
V_6 -> V_75 [ V_6 -> V_41 ] . V_67 = NULL ;
}
} else {
int V_81 , V_82 ;
V_6 -> V_79 -> V_25 = F_44 ( F_15 ( V_2 ) , 0 ) ;
V_81 = F_45 ( F_15 ( V_2 ) ,
V_6 -> V_79 -> V_25 , 0 ) ;
if ( V_81 > 0 ) {
V_82 = F_46 ( V_74 , V_81 ) ;
V_82 *= V_81 ;
if ( V_82 > V_6 -> V_83 )
V_82 = V_6 -> V_83 ;
} else
V_82 = 0 ;
V_6 -> V_79 -> V_70 = V_82 ;
}
V_6 -> V_79 -> V_20 = F_15 ( V_2 ) ;
V_6 -> V_84 -> V_85 = V_86 | V_87 | V_73 ;
V_6 -> V_84 -> V_88 = ( V_73 == V_78 ) ? V_89 :
V_90 ;
V_6 -> V_84 -> V_91 = F_47 ( ( ( V_66 -> type + 1 ) << 8 ) |
V_66 -> V_77 ) ;
V_6 -> V_84 -> V_92 = F_47 ( V_6 -> V_64 ) ;
V_6 -> V_84 -> V_93 = F_47 ( V_74 ) ;
F_42 ( L_10 ,
V_6 -> V_84 -> V_88 == V_89 ? L_11 :
L_12 ,
V_6 -> V_84 -> V_91 , V_6 -> V_84 -> V_92 , V_6 -> V_84 -> V_93 ) ;
V_35 = F_5 ( V_6 -> V_79 , V_15 ) ;
if ( V_35 < 0 ) {
F_39 ( V_2 , L_13 , V_35 ) ;
return V_35 ;
}
V_6 -> V_94 = V_28 ;
return 0 ;
}
static void F_48 ( struct V_43 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_3 ;
int V_95 = 0 ;
switch ( V_43 -> V_45 ) {
case 0 :
break;
case - V_55 :
V_95 = 1 ;
case - V_56 :
case - V_57 :
case - V_53 :
case - V_54 :
break;
default:
F_38 ( V_43 -> V_20 , L_14 ,
V_43 -> V_45 ) ;
}
F_2 ( & V_6 -> V_8 , V_3 ) ;
if ( V_95 ) {
V_6 -> V_37 = V_6 -> V_36 ;
} else {
V_6 -> V_37 = ( V_6 -> V_37 + 1 ) & ( V_96 - 1 ) ;
if ( V_6 -> V_36 != V_6 -> V_37 &&
F_29 ( V_2 ) == 0 ) {
F_8 ( & V_6 -> V_8 , V_3 ) ;
return;
}
}
F_6 ( V_38 , & V_6 -> V_10 ) ;
F_8 ( & V_6 -> V_8 , V_3 ) ;
F_30 ( V_6 -> V_19 ) ;
F_31 ( & V_6 -> V_39 ) ;
}
static void F_49 ( struct V_43 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_95 = 0 , V_45 = V_43 -> V_45 ;
switch ( V_45 ) {
case 0 :
if ( V_6 -> V_75 [ V_6 -> V_41 ] . V_73 == V_97 )
F_36 ( V_43 -> V_44 ,
V_6 -> V_75 [ V_6 -> V_41 ] . V_66 -> type ,
V_43 -> V_49 , V_43 -> V_50 , 0 ) ;
break;
case - V_55 :
V_95 = 1 ;
case - V_56 :
case - V_57 :
case - V_53 :
case - V_54 :
case - V_52 :
break;
default:
F_38 ( V_43 -> V_20 , L_15 , V_45 ) ;
}
F_50 ( & V_6 -> V_8 ) ;
if ( V_95 ) {
V_6 -> V_41 = V_6 -> V_40 ;
} else {
V_6 -> V_41 = ( V_6 -> V_41 + 1 ) & ( V_98 - 1 ) ;
if ( V_6 -> V_40 != V_6 -> V_41 &&
F_34 ( V_2 ) == 0 ) {
F_51 ( & V_6 -> V_8 ) ;
return;
}
}
F_6 ( V_42 , & V_6 -> V_10 ) ;
F_51 ( & V_6 -> V_8 ) ;
F_30 ( V_6 -> V_19 ) ;
F_31 ( & V_6 -> V_39 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_65 * V_66 ,
unsigned char V_73 )
{
int V_99 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ( ( V_2 -> V_100 & V_101 ) && V_73 == V_97 ) ||
F_3 ( V_11 , & V_6 -> V_10 ) )
return;
if ( V_6 -> V_69 && V_73 == V_78 && V_66 -> type == V_102 ) {
if ( ( V_99 = ( V_6 -> V_36 + 1 ) & ( V_96 - 1 ) ) == V_6 -> V_37 ) {
F_38 ( V_2 , L_16 ) ;
return;
}
V_6 -> V_68 [ V_6 -> V_36 ] . V_67 = F_53 ( V_66 , V_15 ) ;
if ( ! V_6 -> V_68 [ V_6 -> V_36 ] . V_67 ) {
F_38 ( V_2 , L_17 ) ;
return;
}
F_54 ( V_66 , V_6 -> V_68 [ V_6 -> V_36 ] . V_67 ) ;
V_6 -> V_68 [ V_6 -> V_36 ] . V_66 = V_66 ;
V_6 -> V_36 = V_99 ;
if ( ! F_3 ( V_38 , & V_6 -> V_10 ) ) {
F_24 ( V_6 ) ;
} else if ( F_17 ( V_28 , V_6 -> V_72 + V_30 * 5 ) ) {
F_55 ( V_6 -> V_19 ) ;
F_56 ( V_6 -> V_69 ) ;
F_51 ( & V_6 -> V_8 ) ;
F_57 ( V_6 -> V_69 ) ;
F_50 ( & V_6 -> V_8 ) ;
F_58 ( V_6 -> V_69 ) ;
if ( ! F_3 ( V_38 , & V_6 -> V_10 ) )
F_24 ( V_6 ) ;
F_30 ( V_6 -> V_19 ) ;
}
return;
}
if ( ( V_99 = ( V_6 -> V_40 + 1 ) & ( V_98 - 1 ) ) == V_6 -> V_41 ) {
F_38 ( V_2 , L_18 ) ;
return;
}
if ( V_73 == V_78 ) {
V_6 -> V_75 [ V_6 -> V_40 ] . V_67 = F_53 ( V_66 , V_15 ) ;
if ( ! V_6 -> V_75 [ V_6 -> V_40 ] . V_67 ) {
F_38 ( V_2 , L_19 ) ;
return;
}
F_54 ( V_66 , V_6 -> V_75 [ V_6 -> V_40 ] . V_67 ) ;
}
V_6 -> V_75 [ V_6 -> V_40 ] . V_66 = V_66 ;
V_6 -> V_75 [ V_6 -> V_40 ] . V_73 = V_73 ;
V_6 -> V_40 = V_99 ;
if ( ! F_3 ( V_42 , & V_6 -> V_10 ) ) {
F_32 ( V_6 ) ;
} else if ( F_17 ( V_28 , V_6 -> V_94 + V_30 * 5 ) ) {
F_55 ( V_6 -> V_19 ) ;
F_56 ( V_6 -> V_79 ) ;
F_51 ( & V_6 -> V_8 ) ;
F_57 ( V_6 -> V_79 ) ;
F_50 ( & V_6 -> V_8 ) ;
F_58 ( V_6 -> V_79 ) ;
if ( ! F_3 ( V_42 , & V_6 -> V_10 ) )
F_32 ( V_6 ) ;
F_30 ( V_6 -> V_19 ) ;
}
}
static void F_59 ( struct V_1 * V_2 , struct V_65 * V_66 , unsigned char V_73 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_3 ;
F_2 ( & V_6 -> V_8 , V_3 ) ;
F_52 ( V_2 , V_66 , V_73 ) ;
F_8 ( & V_6 -> V_8 , V_3 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! F_61 ( V_6 -> V_39 ,
( ! F_3 ( V_42 , & V_6 -> V_10 ) &&
! F_3 ( V_38 , & V_6 -> V_10 ) ) ,
10 * V_30 ) ) {
F_42 ( L_20 ) ;
return - 1 ;
}
return 0 ;
}
static int F_62 ( struct V_103 * V_20 , int V_64 , int V_66 , int V_104 )
{
return F_63 ( V_20 , F_43 ( V_20 , 0 ) ,
V_105 , V_86 | V_87 , ( V_104 << 8 ) | V_66 ,
V_64 , NULL , 0 , V_106 ) ;
}
static int F_64 ( struct V_103 * V_20 , int V_64 ,
unsigned char type , void * V_107 , int V_76 )
{
int V_108 , V_109 = 4 ;
memset ( V_107 , 0 , V_76 ) ;
do {
V_108 = F_63 ( V_20 , F_44 ( V_20 , 0 ) ,
V_110 , V_87 | V_97 ,
( type << 8 ) , V_64 , V_107 , V_76 , V_111 ) ;
V_109 -- ;
} while ( V_108 < V_76 && V_109 );
return V_108 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_112 ;
F_7 ( V_46 , & V_6 -> V_10 ) ;
if ( V_2 -> V_100 & V_113 )
return 0 ;
V_112 = F_66 ( V_6 -> V_19 ) ;
if ( V_112 < 0 ) {
F_6 ( V_46 , & V_6 -> V_10 ) ;
return - V_114 ;
}
V_6 -> V_19 -> V_115 = 1 ;
F_7 ( V_47 , & V_6 -> V_10 ) ;
F_7 ( V_9 , & V_6 -> V_10 ) ;
V_112 = F_1 ( V_2 ) ;
if ( V_112 ) {
if ( V_112 != - V_16 ) {
F_11 ( V_2 ) ;
V_112 = 0 ;
} else {
V_112 = - V_116 ;
F_6 ( V_46 , & V_6 -> V_10 ) ;
F_6 ( V_9 , & V_6 -> V_10 ) ;
V_6 -> V_19 -> V_115 = 0 ;
}
}
F_67 ( V_6 -> V_19 ) ;
if ( V_112 == 0 )
F_68 ( 50 ) ;
F_6 ( V_47 , & V_6 -> V_10 ) ;
return V_112 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_70 ( & V_6 -> V_8 ) ;
F_6 ( V_46 , & V_6 -> V_10 ) ;
if ( ! ( V_2 -> V_100 & V_113 ) )
F_6 ( V_9 , & V_6 -> V_10 ) ;
F_71 ( & V_6 -> V_8 ) ;
if ( V_2 -> V_100 & V_113 )
return;
F_72 ( V_6 ) ;
F_73 ( V_6 -> V_14 ) ;
V_6 -> V_19 -> V_115 = 0 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_117 * V_118 ;
int V_119 , V_120 ;
V_118 = & V_2 -> V_118 [ V_48 ] ;
F_75 (report, &report_enum->report_list, list)
F_59 ( V_2 , V_66 , V_97 ) ;
V_118 = & V_2 -> V_118 [ V_121 ] ;
F_75 (report, &report_enum->report_list, list)
F_59 ( V_2 , V_66 , V_97 ) ;
V_119 = 0 ;
V_120 = F_60 ( V_2 ) ;
while ( V_120 ) {
V_119 |= V_120 ;
if ( F_3 ( V_42 , & V_6 -> V_10 ) )
F_73 ( V_6 -> V_79 ) ;
if ( F_3 ( V_38 , & V_6 -> V_10 ) )
F_73 ( V_6 -> V_69 ) ;
V_120 = F_60 ( V_2 ) ;
}
if ( V_119 )
F_38 ( V_2 , L_21 ) ;
}
static int F_76 ( struct V_1 * V_2 , unsigned int V_122 ,
unsigned int V_123 , struct V_124 * * V_125 )
{
struct V_65 * V_66 ;
struct V_124 * V_126 ;
struct V_127 * V_128 ;
int V_129 , V_130 ;
F_75 (report, &hid->report_enum[HID_OUTPUT_REPORT].report_list, list) {
for ( V_129 = 0 ; V_129 < V_66 -> V_131 ; V_129 ++ ) {
V_126 = V_66 -> V_126 [ V_129 ] ;
for ( V_130 = 0 ; V_130 < V_126 -> V_132 ; V_130 ++ ) {
V_128 = & V_126 -> V_128 [ V_130 ] ;
if ( ( V_128 -> V_2 & V_133 ) == V_122 &&
( V_128 -> V_2 & 0xFFFF ) == V_123 ) {
* V_125 = V_126 ;
return V_130 ;
}
}
}
}
return - 1 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_124 * V_126 ;
int V_134 ;
if ( ( V_134 = F_76 ( V_2 , V_135 , 0x01 , & V_126 ) ) != - 1 ) {
F_78 ( V_126 , V_134 , 0 ) ;
F_59 ( V_2 , V_126 -> V_66 , V_78 ) ;
}
}
static void F_79 ( struct V_1 * V_2 , unsigned int type ,
unsigned int * V_136 )
{
struct V_65 * V_66 ;
unsigned int V_76 ;
F_75 (report, &hid->report_enum[type].report_list, list) {
V_76 = ( ( V_66 -> V_76 - 1 ) >> 3 ) + 1 + V_2 -> V_118 [ type ] . V_137 ;
if ( * V_136 < V_76 )
* V_136 = V_76 ;
}
}
static int F_80 ( struct V_103 * V_20 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_138 = F_81 ( V_20 , V_6 -> V_83 , V_139 ,
& V_6 -> V_140 ) ;
V_6 -> V_71 = F_81 ( V_20 , V_6 -> V_83 , V_139 ,
& V_6 -> V_141 ) ;
V_6 -> V_84 = F_82 ( sizeof( * V_6 -> V_84 ) , V_139 ) ;
V_6 -> V_80 = F_81 ( V_20 , V_6 -> V_83 , V_139 ,
& V_6 -> V_142 ) ;
if ( ! V_6 -> V_138 || ! V_6 -> V_71 || ! V_6 -> V_84 ||
! V_6 -> V_80 )
return - 1 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
unsigned char V_143 , T_1 * V_107 , T_2 V_144 ,
unsigned char V_145 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_103 * V_20 = F_15 ( V_2 ) ;
struct V_33 * V_19 = V_6 -> V_19 ;
struct V_146 * V_147 = V_19 -> V_148 ;
int V_149 = 0 ;
int V_120 ;
V_107 [ 0 ] = V_143 ;
if ( V_143 == 0x0 ) {
V_107 ++ ;
V_144 -- ;
V_149 = 1 ;
}
V_120 = F_63 ( V_20 , F_44 ( V_20 , 0 ) ,
V_90 ,
V_97 | V_86 | V_87 ,
( ( V_145 + 1 ) << 8 ) | V_143 ,
V_147 -> V_150 . V_151 , V_107 , V_144 ,
V_106 ) ;
if ( V_120 > 0 && V_149 )
V_120 ++ ;
return V_120 ;
}
static int F_84 ( struct V_1 * V_2 , unsigned int V_152 ,
T_1 * V_107 , T_2 V_144 , unsigned char V_153 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_103 * V_20 = F_15 ( V_2 ) ;
struct V_33 * V_19 = V_6 -> V_19 ;
struct V_146 * V_147 = V_19 -> V_148 ;
int V_120 , V_149 = 0 ;
if ( ( V_153 == V_102 ) &&
( V_2 -> V_100 & V_154 ) )
V_107 [ 0 ] = 0 ;
else
V_107 [ 0 ] = V_152 ;
if ( V_107 [ 0 ] == 0x0 ) {
V_107 ++ ;
V_144 -- ;
V_149 = 1 ;
}
V_120 = F_63 ( V_20 , F_43 ( V_20 , 0 ) ,
V_89 ,
V_78 | V_86 | V_87 ,
( ( V_153 + 1 ) << 8 ) | V_152 ,
V_147 -> V_150 . V_151 , V_107 , V_144 ,
V_106 ) ;
if ( V_120 > 0 && V_149 )
V_120 ++ ;
return V_120 ;
}
static int F_85 ( struct V_1 * V_2 , T_1 * V_107 , T_2 V_144 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_103 * V_20 = F_15 ( V_2 ) ;
int V_50 , V_149 = 0 , V_120 ;
if ( ! V_6 -> V_69 )
return - V_155 ;
if ( V_107 [ 0 ] == 0x0 ) {
V_107 ++ ;
V_144 -- ;
V_149 = 1 ;
}
V_120 = F_86 ( V_20 , V_6 -> V_69 -> V_25 ,
V_107 , V_144 , & V_50 ,
V_106 ) ;
if ( V_120 == 0 ) {
V_120 = V_50 ;
if ( V_149 )
V_120 ++ ;
}
return V_120 ;
}
static void F_87 ( struct V_103 * V_20 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_88 ( V_20 , V_6 -> V_83 , V_6 -> V_138 , V_6 -> V_140 ) ;
F_88 ( V_20 , V_6 -> V_83 , V_6 -> V_71 , V_6 -> V_141 ) ;
F_41 ( V_6 -> V_84 ) ;
F_88 ( V_20 , V_6 -> V_83 , V_6 -> V_80 , V_6 -> V_142 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_33 * V_19 = F_90 ( V_2 -> V_20 . V_156 ) ;
struct V_146 * V_147 = V_19 -> V_148 ;
struct V_103 * V_20 = F_23 ( V_19 ) ;
struct V_157 * V_158 ;
T_3 V_100 = 0 ;
unsigned int V_159 = 0 ;
char * V_160 ;
int V_120 , V_161 ;
int V_162 ;
T_2 V_134 = F_91 ( struct V_157 , V_150 ) ;
V_100 = F_92 ( F_93 ( V_20 -> V_163 . V_164 ) ,
F_93 ( V_20 -> V_163 . V_165 ) ) ;
if ( V_100 & V_166 )
return - V_167 ;
if ( V_147 -> V_150 . V_168 == V_169 ) {
if ( V_147 -> V_150 . V_170 == V_171 ||
V_147 -> V_150 . V_170 == V_172 )
V_100 |= V_101 ;
}
if ( F_94 ( V_147 , V_173 , & V_158 ) &&
( ! V_147 -> V_150 . V_174 ||
F_94 ( & V_147 -> V_175 [ 0 ] , V_173 , & V_158 ) ) ) {
F_42 ( L_22 ) ;
return - V_167 ;
}
if ( V_158 -> V_176 < sizeof( struct V_157 ) ) {
F_42 ( L_23 ) ;
return - V_177 ;
}
V_2 -> V_178 = F_93 ( V_158 -> V_179 ) ;
V_2 -> V_180 = V_158 -> V_181 ;
V_162 = F_95 ( int , V_158 -> V_182 ,
( V_158 -> V_176 - V_134 ) / sizeof( struct V_183 ) ) ;
for ( V_161 = 0 ; V_161 < V_162 ; V_161 ++ )
if ( V_158 -> V_150 [ V_161 ] . V_184 == V_185 )
V_159 = F_93 ( V_158 -> V_150 [ V_161 ] . V_186 ) ;
if ( ! V_159 || V_159 > V_187 ) {
F_42 ( L_24 , V_159 ) ;
return - V_177 ;
}
V_160 = F_82 ( V_159 , V_139 ) ;
if ( ! V_160 )
return - V_188 ;
F_62 ( V_20 , V_147 -> V_150 . V_151 , 0 , 0 ) ;
V_120 = F_64 ( V_20 , V_147 -> V_150 . V_151 ,
V_185 , V_160 , V_159 ) ;
if ( V_120 < 0 ) {
F_42 ( L_25 ) ;
F_41 ( V_160 ) ;
goto V_119;
}
V_120 = F_96 ( V_2 , V_160 , V_159 ) ;
F_41 ( V_160 ) ;
if ( V_120 ) {
F_42 ( L_26 ) ;
goto V_119;
}
V_2 -> V_100 |= V_100 ;
return 0 ;
V_119:
return V_120 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_33 * V_19 = F_90 ( V_2 -> V_20 . V_156 ) ;
struct V_146 * V_147 = V_19 -> V_148 ;
struct V_103 * V_20 = F_23 ( V_19 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_161 , V_189 = 0 ;
int V_120 ;
F_6 ( V_11 , & V_6 -> V_10 ) ;
V_6 -> V_83 = V_190 ;
F_79 ( V_2 , V_48 , & V_6 -> V_83 ) ;
F_79 ( V_2 , V_102 , & V_6 -> V_83 ) ;
F_79 ( V_2 , V_121 , & V_6 -> V_83 ) ;
if ( V_6 -> V_83 > V_191 )
V_6 -> V_83 = V_191 ;
F_79 ( V_2 , V_48 , & V_189 ) ;
if ( V_189 > V_191 )
V_189 = V_191 ;
if ( F_80 ( V_20 , V_2 ) ) {
V_120 = - V_188 ;
goto V_192;
}
for ( V_161 = 0 ; V_161 < V_147 -> V_150 . V_174 ; V_161 ++ ) {
struct V_193 * V_175 ;
int V_25 ;
int V_194 ;
V_175 = & V_147 -> V_175 [ V_161 ] . V_150 ;
if ( ! F_98 ( V_175 ) )
continue;
V_194 = V_175 -> V_195 ;
if ( V_2 -> V_100 & V_196 &&
V_20 -> V_197 == V_198 ) {
V_194 = F_99 ( V_175 -> V_195 * 8 ) ;
F_100 ( L_27 ,
V_2 -> V_199 , V_175 -> V_195 , V_194 ) ;
}
switch ( V_2 -> V_200 -> V_128 ) {
case V_201 :
if ( V_202 > 0 )
V_194 = V_202 ;
break;
case V_203 :
if ( V_204 > 0 )
V_194 = V_204 ;
break;
}
V_120 = - V_188 ;
if ( F_101 ( V_175 ) ) {
if ( V_6 -> V_14 )
continue;
if ( ! ( V_6 -> V_14 = F_102 ( 0 , V_139 ) ) )
goto V_192;
V_25 = F_103 ( V_20 , V_175 -> V_205 ) ;
F_104 ( V_6 -> V_14 , V_20 , V_25 , V_6 -> V_138 , V_189 ,
F_35 , V_2 , V_194 ) ;
V_6 -> V_14 -> V_206 = V_6 -> V_140 ;
V_6 -> V_14 -> V_207 |= V_208 ;
} else {
if ( V_6 -> V_69 )
continue;
if ( ! ( V_6 -> V_69 = F_102 ( 0 , V_139 ) ) )
goto V_192;
V_25 = F_105 ( V_20 , V_175 -> V_205 ) ;
F_104 ( V_6 -> V_69 , V_20 , V_25 , V_6 -> V_71 , 0 ,
F_48 , V_2 , V_194 ) ;
V_6 -> V_69 -> V_206 = V_6 -> V_141 ;
V_6 -> V_69 -> V_207 |= V_208 ;
}
}
V_6 -> V_79 = F_102 ( 0 , V_139 ) ;
if ( ! V_6 -> V_79 ) {
V_120 = - V_188 ;
goto V_192;
}
F_106 ( V_6 -> V_79 , V_20 , 0 , ( void * ) V_6 -> V_84 ,
V_6 -> V_80 , 1 , F_49 , V_2 ) ;
V_6 -> V_79 -> V_206 = V_6 -> V_142 ;
V_6 -> V_79 -> V_207 |= V_208 ;
F_7 ( V_209 , & V_6 -> V_10 ) ;
if ( V_2 -> V_100 & V_113 ) {
V_120 = F_66 ( V_6 -> V_19 ) ;
if ( V_120 )
goto V_192;
F_7 ( V_9 , & V_6 -> V_10 ) ;
V_6 -> V_19 -> V_115 = 1 ;
V_120 = F_1 ( V_2 ) ;
if ( V_120 ) {
F_107 ( & V_2 -> V_20 ,
L_28 , V_120 ) ;
}
F_67 ( V_6 -> V_19 ) ;
}
if ( V_147 -> V_150 . V_168 == V_169 &&
V_147 -> V_150 . V_170 ==
V_171 ) {
F_77 ( V_2 ) ;
F_108 ( & V_20 -> V_20 , 1 ) ;
}
return 0 ;
V_192:
F_109 ( V_6 -> V_14 ) ;
F_109 ( V_6 -> V_69 ) ;
F_109 ( V_6 -> V_79 ) ;
V_6 -> V_14 = NULL ;
V_6 -> V_69 = NULL ;
V_6 -> V_79 = NULL ;
F_87 ( V_20 , V_2 ) ;
return V_120 ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_33 ( ! V_6 ) )
return;
if ( V_2 -> V_100 & V_113 ) {
F_6 ( V_9 , & V_6 -> V_10 ) ;
V_6 -> V_19 -> V_115 = 0 ;
}
F_6 ( V_209 , & V_6 -> V_10 ) ;
F_70 ( & V_6 -> V_8 ) ;
F_7 ( V_11 , & V_6 -> V_10 ) ;
F_71 ( & V_6 -> V_8 ) ;
F_73 ( V_6 -> V_14 ) ;
F_73 ( V_6 -> V_69 ) ;
F_73 ( V_6 -> V_79 ) ;
F_72 ( V_6 ) ;
V_2 -> V_210 = 0 ;
F_109 ( V_6 -> V_14 ) ;
F_109 ( V_6 -> V_79 ) ;
F_109 ( V_6 -> V_69 ) ;
V_6 -> V_14 = NULL ;
V_6 -> V_79 = NULL ;
V_6 -> V_69 = NULL ;
F_87 ( F_15 ( V_2 ) , V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 , int V_211 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_35 = 0 ;
switch ( V_211 ) {
case V_212 :
V_35 = F_66 ( V_6 -> V_19 ) ;
break;
case V_213 :
F_67 ( V_6 -> V_19 ) ;
break;
}
return V_35 ;
}
static void F_112 ( struct V_1 * V_2 , struct V_65 * V_214 , int V_215 )
{
switch ( V_215 ) {
case V_90 :
F_59 ( V_2 , V_214 , V_97 ) ;
break;
case V_89 :
F_59 ( V_2 , V_214 , V_78 ) ;
break;
}
}
static int F_113 ( struct V_1 * V_2 , unsigned char V_152 ,
T_1 * V_107 , T_2 V_74 , unsigned char V_153 ,
int V_215 )
{
switch ( V_215 ) {
case V_90 :
return F_83 ( V_2 , V_152 , V_107 , V_74 , V_153 ) ;
case V_89 :
return F_84 ( V_2 , V_152 , V_107 , V_74 , V_153 ) ;
default:
return - V_114 ;
}
}
static int F_114 ( struct V_1 * V_2 , int V_66 , int V_104 ,
int V_215 )
{
struct V_103 * V_20 = F_15 ( V_2 ) ;
struct V_33 * V_19 = F_90 ( V_2 -> V_20 . V_156 ) ;
struct V_146 * V_147 = V_19 -> V_148 ;
int V_64 = V_147 -> V_150 . V_151 ;
if ( V_215 != V_105 )
return - V_177 ;
return F_62 ( V_20 , V_64 , V_66 , V_104 ) ;
}
static int F_115 ( struct V_33 * V_19 , const struct V_216 * V_77 )
{
struct V_146 * V_147 = V_19 -> V_148 ;
struct V_103 * V_20 = F_23 ( V_19 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned int V_161 , V_217 = 0 ;
T_2 V_74 ;
int V_120 ;
F_42 ( L_29 ,
V_19 -> V_218 -> V_150 . V_151 ) ;
for ( V_161 = 0 ; V_161 < V_147 -> V_150 . V_174 ; V_161 ++ )
if ( F_116 ( & V_147 -> V_175 [ V_161 ] . V_150 ) )
V_217 ++ ;
if ( ! V_217 ) {
F_39 ( V_19 , L_30 ) ;
return - V_167 ;
}
V_2 = F_117 () ;
if ( F_118 ( V_2 ) )
return F_119 ( V_2 ) ;
F_120 ( V_19 , V_2 ) ;
V_2 -> V_219 = & V_220 ;
V_2 -> V_221 = V_222 ;
#ifdef F_121
V_2 -> V_223 = V_223 ;
V_2 -> V_224 = V_224 ;
V_2 -> V_225 = V_225 ;
V_2 -> V_226 = V_226 ;
#endif
V_2 -> V_20 . V_156 = & V_19 -> V_20 ;
V_2 -> V_61 = V_227 ;
V_2 -> V_228 = F_93 ( V_20 -> V_163 . V_164 ) ;
V_2 -> V_229 = F_93 ( V_20 -> V_163 . V_165 ) ;
V_2 -> V_199 [ 0 ] = 0 ;
V_2 -> V_100 = F_92 ( V_2 -> V_228 , V_2 -> V_229 ) ;
if ( V_19 -> V_148 -> V_150 . V_170 ==
V_172 )
V_2 -> type = V_230 ;
else if ( V_19 -> V_148 -> V_150 . V_170 == 0 )
V_2 -> type = V_231 ;
if ( V_20 -> V_232 )
F_122 ( V_2 -> V_199 , V_20 -> V_232 , sizeof( V_2 -> V_199 ) ) ;
if ( V_20 -> V_229 ) {
if ( V_20 -> V_232 )
F_123 ( V_2 -> V_199 , L_31 , sizeof( V_2 -> V_199 ) ) ;
F_123 ( V_2 -> V_199 , V_20 -> V_229 , sizeof( V_2 -> V_199 ) ) ;
}
if ( ! strlen ( V_2 -> V_199 ) )
snprintf ( V_2 -> V_199 , sizeof( V_2 -> V_199 ) , L_32 ,
F_93 ( V_20 -> V_163 . V_164 ) ,
F_93 ( V_20 -> V_163 . V_165 ) ) ;
F_124 ( V_20 , V_2 -> V_233 , sizeof( V_2 -> V_233 ) ) ;
F_123 ( V_2 -> V_233 , L_33 , sizeof( V_2 -> V_233 ) ) ;
V_74 = strlen ( V_2 -> V_233 ) ;
if ( V_74 < sizeof( V_2 -> V_233 ) - 1 )
snprintf ( V_2 -> V_233 + V_74 , sizeof( V_2 -> V_233 ) - V_74 ,
L_34 , V_19 -> V_218 [ 0 ] . V_150 . V_151 ) ;
if ( F_125 ( V_20 , V_20 -> V_163 . V_234 , V_2 -> V_235 , 64 ) <= 0 )
V_2 -> V_235 [ 0 ] = 0 ;
V_6 = F_126 ( sizeof( * V_6 ) , V_139 ) ;
if ( V_6 == NULL ) {
V_120 = - V_188 ;
goto V_119;
}
V_2 -> V_7 = V_6 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_64 = V_147 -> V_150 . V_151 ;
F_127 ( & V_6 -> V_39 ) ;
F_128 ( & V_6 -> V_23 , F_12 ) ;
F_129 ( & V_6 -> V_32 , F_9 , ( unsigned long ) V_2 ) ;
F_130 ( & V_6 -> V_8 ) ;
V_120 = F_131 ( V_2 ) ;
if ( V_120 ) {
if ( V_120 != - V_167 )
F_39 ( V_19 , L_35 , V_120 ) ;
goto V_236;
}
return 0 ;
V_236:
F_41 ( V_6 ) ;
V_119:
F_132 ( V_2 ) ;
return V_120 ;
}
static void F_133 ( struct V_33 * V_19 )
{
struct V_1 * V_2 = F_25 ( V_19 ) ;
struct V_5 * V_6 ;
if ( F_33 ( ! V_2 ) )
return;
V_6 = V_2 -> V_7 ;
F_70 ( & V_6 -> V_8 ) ;
F_7 ( V_11 , & V_6 -> V_10 ) ;
F_71 ( & V_6 -> V_8 ) ;
F_132 ( V_2 ) ;
F_41 ( V_6 ) ;
}
static void F_72 ( struct V_5 * V_6 )
{
F_134 ( & V_6 -> V_32 ) ;
F_135 ( & V_6 -> V_23 ) ;
}
static void F_136 ( struct V_5 * V_6 )
{
F_134 ( & V_6 -> V_32 ) ;
F_73 ( V_6 -> V_14 ) ;
F_73 ( V_6 -> V_79 ) ;
F_73 ( V_6 -> V_69 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_237 = F_3 ( V_24 , & V_6 -> V_10 ) ;
int V_238 = F_3 ( V_26 , & V_6 -> V_10 ) ;
F_70 ( & V_6 -> V_8 ) ;
F_6 ( V_12 , & V_6 -> V_10 ) ;
F_21 ( V_6 ) ;
if ( V_237 || V_238 )
F_19 ( & V_6 -> V_23 ) ;
V_6 -> V_31 = 0 ;
F_71 ( & V_6 -> V_8 ) ;
if ( V_238 || ! F_3 ( V_209 , & V_6 -> V_10 ) )
return;
if ( ! V_237 ) {
if ( F_1 ( V_2 ) < 0 )
F_11 ( V_2 ) ;
}
F_70 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_69 && ! F_3 ( V_38 , & V_6 -> V_10 ) )
F_24 ( V_6 ) ;
if ( ! F_3 ( V_42 , & V_6 -> V_10 ) )
F_32 ( V_6 ) ;
F_71 ( & V_6 -> V_8 ) ;
}
static int F_138 ( struct V_33 * V_19 )
{
struct V_1 * V_2 = F_25 ( V_19 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_70 ( & V_6 -> V_8 ) ;
F_7 ( V_26 , & V_6 -> V_10 ) ;
F_71 ( & V_6 -> V_8 ) ;
F_136 ( V_6 ) ;
return 0 ;
}
static int F_139 ( struct V_33 * V_19 )
{
struct V_103 * V_20 = F_23 ( V_19 ) ;
struct V_1 * V_2 = F_25 ( V_19 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_146 * V_147 = V_19 -> V_148 ;
int V_45 ;
char * V_160 ;
V_160 = F_82 ( V_2 -> V_239 , V_139 ) ;
if ( ! V_160 )
return - V_188 ;
V_45 = F_64 ( V_20 ,
V_147 -> V_150 . V_151 ,
V_185 , V_160 , V_2 -> V_239 ) ;
if ( V_45 < 0 ) {
F_42 ( L_36 ) ;
F_41 ( V_160 ) ;
return V_45 ;
}
V_45 = memcmp ( V_160 , V_2 -> V_240 , V_2 -> V_239 ) ;
F_41 ( V_160 ) ;
if ( V_45 != 0 ) {
F_42 ( L_37 ) ;
return - V_60 ;
}
F_70 ( & V_6 -> V_8 ) ;
F_6 ( V_26 , & V_6 -> V_10 ) ;
F_6 ( V_24 , & V_6 -> V_10 ) ;
F_71 ( & V_6 -> V_8 ) ;
F_62 ( V_20 , V_19 -> V_148 -> V_150 . V_151 , 0 , 0 ) ;
F_137 ( V_2 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , bool V_241 )
{
int V_45 = 0 ;
F_137 ( V_2 ) ;
if ( V_241 && V_2 -> V_242 && V_2 -> V_242 -> V_243 )
V_45 = V_2 -> V_242 -> V_243 ( V_2 ) ;
return V_45 ;
}
static int F_141 ( struct V_33 * V_19 , T_4 V_244 )
{
struct V_1 * V_2 = F_25 ( V_19 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_45 = 0 ;
bool V_241 = false ;
unsigned int V_245 ;
if ( F_142 ( V_244 ) ) {
V_245 = F_143 ( V_2 ) ;
F_70 ( & V_6 -> V_8 ) ;
if ( ! F_3 ( V_26 , & V_6 -> V_10 )
&& ! F_3 ( V_24 , & V_6 -> V_10 )
&& ! F_3 ( V_38 , & V_6 -> V_10 )
&& ! F_3 ( V_42 , & V_6 -> V_10 )
&& ! F_3 ( V_51 , & V_6 -> V_10 )
&& ( ! V_245 || V_246 ) )
{
F_7 ( V_12 , & V_6 -> V_10 ) ;
F_71 ( & V_6 -> V_8 ) ;
if ( V_2 -> V_242 && V_2 -> V_242 -> V_247 ) {
V_45 = V_2 -> V_242 -> V_247 ( V_2 , V_244 ) ;
if ( V_45 < 0 )
goto V_248;
}
V_241 = true ;
} else {
F_21 ( V_6 ) ;
F_71 ( & V_6 -> V_8 ) ;
return - V_116 ;
}
} else {
if ( V_2 -> V_242 && V_2 -> V_242 -> V_247 )
V_45 = V_2 -> V_242 -> V_247 ( V_2 , V_244 ) ;
V_241 = true ;
F_70 ( & V_6 -> V_8 ) ;
F_7 ( V_12 , & V_6 -> V_10 ) ;
F_71 ( & V_6 -> V_8 ) ;
if ( F_60 ( V_2 ) < 0 )
V_45 = - V_114 ;
}
F_72 ( V_6 ) ;
F_136 ( V_6 ) ;
if ( F_142 ( V_244 ) && F_3 ( V_51 , & V_6 -> V_10 ) ) {
V_45 = - V_116 ;
goto V_248;
}
F_10 ( & V_19 -> V_20 , L_38 ) ;
return V_45 ;
V_248:
F_140 ( V_2 , V_241 ) ;
return V_45 ;
}
static int F_144 ( struct V_33 * V_19 )
{
struct V_1 * V_2 = F_25 ( V_19 ) ;
int V_45 ;
V_45 = F_140 ( V_2 , true ) ;
F_10 ( & V_19 -> V_20 , L_39 , V_45 ) ;
return 0 ;
}
static int F_145 ( struct V_33 * V_19 )
{
struct V_1 * V_2 = F_25 ( V_19 ) ;
int V_45 ;
V_45 = F_139 ( V_19 ) ;
if ( V_45 >= 0 && V_2 -> V_242 && V_2 -> V_242 -> V_249 ) {
int V_120 = V_2 -> V_242 -> V_249 ( V_2 ) ;
if ( V_120 < 0 )
V_45 = V_120 ;
}
return V_45 ;
}
struct V_33 * F_146 ( int V_250 )
{
return F_147 ( & V_251 , V_250 ) ;
}
static int T_5 F_148 ( void )
{
int V_252 = - V_188 ;
V_252 = F_149 ( V_253 ) ;
if ( V_252 )
goto V_254;
V_252 = F_150 ( & V_251 ) ;
if ( V_252 )
goto V_255;
F_100 ( V_256 L_40 V_257 L_41 ) ;
return 0 ;
V_255:
F_151 () ;
V_254:
return V_252 ;
}
static void T_6 F_152 ( void )
{
F_153 ( & V_251 ) ;
F_151 () ;
}
