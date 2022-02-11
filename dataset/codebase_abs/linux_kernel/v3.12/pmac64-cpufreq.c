static void F_1 ( int V_1 )
{
struct V_2 V_3 ;
F_2 ( V_4 ) ;
F_3 ( & V_3 , V_5 , 8 , V_6 ,
& V_4 , 'V' , 'S' , 'L' , 'E' , 'W' ,
0xff , V_7 + 1 , V_1 ) ;
F_4 ( & V_4 ) ;
}
static void F_5 ( int V_1 )
{
struct V_8 args ;
T_1 V_9 , V_10 = 0 ;
unsigned long V_11 ;
V_9 = ( V_1 == V_12 ) ? 1 : 0 ;
args . V_13 = 1 ;
args . V_14 [ 0 ] . V_15 = & V_9 ;
F_6 ( V_16 , & args ) ;
V_11 = V_17 + V_18 / 10 ;
while( ! F_7 ( V_17 , V_11 ) ) {
args . V_13 = 1 ;
args . V_14 [ 0 ] . V_15 = & V_10 ;
F_6 ( V_19 , & args ) ;
if ( V_10 )
break;
F_8 ( 1 ) ;
}
if ( V_10 == 0 )
F_9 ( V_20 L_1 ) ;
}
static int F_10 ( int V_1 )
{
unsigned long V_21 ;
int V_22 ;
if ( V_1 < V_23 )
F_11 ( V_1 ) ;
F_12 ( V_21 ) ;
F_13 ( V_24 , 0 ) ;
F_13 ( V_24 , V_25 | 0 ) ;
F_13 ( V_24 , V_25 |
V_26 [ V_1 ] ) ;
for ( V_22 = 0 ; V_22 < 10 ; V_22 ++ ) {
unsigned long V_27 = F_14 ( V_28 ) ;
if ( ( V_27 & V_29 ) == 0 &&
( ( ( V_27 >> V_30 ) ^
( V_26 [ V_1 ] >> V_31 ) ) & 0x3 )
== 0 )
break;
if ( V_27 & V_32 )
break;
F_15 ( 100 ) ;
}
F_16 ( V_21 ) ;
if ( V_1 > V_23 )
F_11 ( V_1 ) ;
V_23 = V_1 ;
V_33 = V_34 [ V_1 ] . V_35 * 1000ul ;
return 0 ;
}
static int F_17 ( void )
{
unsigned long V_27 = F_14 ( V_28 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 <= V_37 ; V_36 ++ )
if ( ( ( ( V_27 >> V_30 ) ^
( V_26 [ V_36 ] >> V_31 ) ) & 0x3 ) == 0 )
break;
return V_36 ;
}
static void F_18 ( int V_1 )
{
}
static void F_19 ( int V_1 )
{
if ( V_1 == V_38 ) {
if ( V_39 )
F_6 ( V_39 , NULL ) ;
if ( V_40 )
F_6 ( V_40 , NULL ) ;
} else {
if ( V_41 )
F_6 ( V_41 , NULL ) ;
if ( V_42 )
F_6 ( V_42 , NULL ) ;
}
F_8 ( 10 ) ;
}
static int F_20 ( int V_1 )
{
struct V_8 args ;
T_1 V_10 = 0 ;
unsigned long V_11 ;
int V_43 ;
F_21 ( L_2 , V_1 ) ;
if ( V_1 < V_23 )
F_11 ( V_1 ) ;
if ( V_1 == V_38 )
V_43 = F_6 ( V_44 , NULL ) ;
else
V_43 = F_6 ( V_45 , NULL ) ;
if ( V_43 )
F_9 ( V_20 L_3 , V_43 ) ;
V_11 = V_17 + V_18 / 10 ;
while( ! F_7 ( V_17 , V_11 ) ) {
args . V_13 = 1 ;
args . V_14 [ 0 ] . V_15 = & V_10 ;
F_6 ( V_46 , & args ) ;
if ( V_10 )
break;
F_8 ( 1 ) ;
}
if ( V_10 == 0 )
F_9 ( V_20 L_1 ) ;
if ( V_1 > V_23 )
F_11 ( V_1 ) ;
V_23 = V_1 ;
V_33 = V_34 [ V_1 ] . V_35 * 1000ul ;
return 0 ;
}
static int F_22 ( void )
{
struct V_8 args ;
T_1 V_47 = 0 ;
args . V_13 = 1 ;
args . V_14 [ 0 ] . V_15 = & V_47 ;
F_6 ( V_48 , & args ) ;
return V_47 ? V_38 : V_12 ;
}
static int F_23 ( struct V_49 * V_50 )
{
return F_24 ( V_50 , V_34 ) ;
}
static int F_25 ( struct V_49 * V_50 ,
unsigned int V_51 , unsigned int V_52 )
{
unsigned int V_53 = 0 ;
struct V_54 V_55 ;
int V_43 ;
if ( F_26 ( V_50 , V_34 ,
V_51 , V_52 , & V_53 ) )
return - V_56 ;
if ( V_23 == V_53 )
return 0 ;
F_27 ( & V_57 ) ;
V_55 . V_58 = V_34 [ V_23 ] . V_35 ;
V_55 . V_59 = V_34 [ V_53 ] . V_35 ;
F_28 ( V_50 , & V_55 , V_60 ) ;
V_43 = F_29 ( V_53 ) ;
F_28 ( V_50 , & V_55 , V_61 ) ;
F_30 ( & V_57 ) ;
return V_43 ;
}
static unsigned int F_31 ( unsigned int V_62 )
{
return V_34 [ V_23 ] . V_35 ;
}
static int F_32 ( struct V_49 * V_50 )
{
V_50 -> V_63 . V_64 = V_64 ;
V_50 -> V_65 = V_34 [ F_33 () ] . V_35 ;
F_34 ( V_50 -> V_66 , V_67 ) ;
F_35 ( V_34 , V_50 -> V_62 ) ;
return F_36 ( V_50 ,
V_34 ) ;
}
static int T_2 F_37 ( struct V_68 * V_69 )
{
unsigned int V_70 , V_71 ;
unsigned long V_72 ;
char * V_73 , * V_74 ;
const T_1 * V_75 ;
T_1 V_76 ;
int V_77 = 0 ;
int V_78 = 0 ;
int V_43 = - V_79 ;
if ( F_38 ( L_4 ) ||
F_38 ( L_5 ) ||
F_38 ( L_6 ) )
V_78 = 1 ;
else if ( F_38 ( L_7 ) )
V_77 = 1 ;
else
return - V_79 ;
V_75 = F_39 ( V_69 , L_8 , NULL ) ;
if ( ! V_75 ) {
F_21 ( L_9 ) ;
goto V_80;
}
V_76 = ( * V_75 ) >> 16 ;
if ( V_76 != 0x3c && V_76 != 0x44 ) {
F_9 ( V_81 L_10 ) ;
goto V_80;
}
V_26 = F_39 ( V_69 , L_11 , & V_70 ) ;
if ( ! V_26 ) {
F_21 ( L_12 ) ;
goto V_80;
}
V_37 = V_70 / sizeof( T_1 ) - 1 ;
if ( V_78 ) {
const struct V_82 * V_83 ;
V_83 = F_40 ( V_84 , NULL ) ;
if ( ! V_83 )
goto V_80;
V_85 = (struct V_86 * ) & V_83 [ 1 ] ;
V_71 = ( V_83 -> V_87 * sizeof( T_1 ) ) - sizeof( * V_83 ) ;
V_88 = V_71 / sizeof( * V_85 ) ;
V_7 = 0 ;
if ( V_88 < 1 || V_37 < 1 )
goto V_80;
F_11 = F_1 ;
V_74 = L_13 ;
} else if ( V_77 ) {
struct V_68 * V_89 ;
V_89 = F_41 ( L_14 ) ;
if ( V_89 == NULL ) {
F_9 ( V_81 L_15
L_16 ) ;
goto V_80;
}
V_16 = F_42 ( V_89 , L_17 ) ;
V_19 =
F_42 ( V_89 , L_18 ) ;
if ( V_16 == NULL ||
V_19 == NULL ) {
F_9 ( V_81 L_19
L_20 ) ;
goto V_80;
}
F_11 = F_5 ;
V_74 = L_21 ;
} else {
F_11 = F_18 ;
V_74 = L_22 ;
}
V_75 = F_39 ( V_69 , L_23 , NULL ) ;
if ( ! V_75 )
return - V_79 ;
V_72 = ( * V_75 ) / 1000 ;
V_34 [ 0 ] . V_35 = V_72 ;
V_34 [ 1 ] . V_35 = V_72 / 2 ;
V_64 = 12000 ;
F_29 = F_10 ;
F_33 = F_17 ;
V_73 = L_24 ;
F_11 ( V_38 ) ;
F_8 ( 10 ) ;
V_23 = - 1 ;
F_29 ( F_33 () ) ;
F_9 ( V_90 L_25 ) ;
F_9 ( V_90 L_26 ,
V_73 , V_74 ) ;
F_9 ( V_90 L_27 ,
V_34 [ 1 ] . V_35 / 1000 ,
V_34 [ 0 ] . V_35 / 1000 ,
V_34 [ V_23 ] . V_35 / 1000 ) ;
V_43 = F_43 ( & V_91 ) ;
return V_43 ;
V_80:
F_44 ( V_69 ) ;
return V_43 ;
}
static int T_2 F_45 ( struct V_68 * V_69 )
{
struct V_68 * V_92 = NULL , * V_93 = NULL ;
const T_3 * V_94 = NULL ;
const T_1 * V_75 ;
T_4 V_72 , V_95 , V_96 , V_97 ;
int V_98 = 1 , V_43 = 0 ;
F_21 ( L_28
L_29 ) ;
V_92 = F_41 ( L_30 ) ;
if ( V_92 != NULL )
V_94 = F_39 ( V_92 , L_31 , NULL ) ;
if ( V_94 == NULL ) {
F_9 ( V_81 L_32 ) ;
V_43 = - V_79 ;
goto V_99;
}
for ( V_93 = NULL ;
( V_93 = F_46 ( V_93 , L_33 ) ) != NULL ; ) {
const char * V_100 = F_39 ( V_93 ,
L_34 , NULL ) ;
if ( V_100 == NULL )
continue;
if ( strcmp ( V_100 , L_35 ) )
continue;
if ( ! F_39 ( V_93 , L_36 , NULL ) )
continue;
break;
}
if ( V_93 == NULL ) {
F_9 ( V_81 L_37 ) ;
V_43 = - V_79 ;
goto V_99;
}
F_21 ( L_38 , V_93 -> V_101 ) ;
V_48 =
F_42 ( V_93 , L_39 ) ;
V_44 =
F_42 ( V_93 , L_40 ) ;
V_45 =
F_42 ( V_93 , L_41 ) ;
V_46 =
F_42 ( V_93 , L_18 ) ;
V_39 =
F_42 ( V_93 , L_42 ) ;
V_41 =
F_42 ( V_93 , L_43 ) ;
V_40 =
F_42 ( V_93 , L_44 ) ;
V_42 =
F_42 ( V_93 , L_45 ) ;
if ( V_48 == NULL || V_44 == NULL ||
V_45 == NULL || V_46 == NULL ) {
F_9 ( V_81 L_46 ) ;
V_43 = - V_79 ;
goto V_99;
}
if ( V_39 == NULL || V_41 == NULL ) {
F_47 ( V_39 ) ;
F_47 ( V_41 ) ;
V_39 = V_41 = NULL ;
V_98 = 0 ;
}
if ( ! V_98 ||
V_40 == NULL || V_42 == NULL ) {
F_47 ( V_40 ) ;
F_47 ( V_42 ) ;
V_40 = V_42 = NULL ;
}
V_75 = F_39 ( V_69 , L_23 , NULL ) ;
if ( ! V_75 ) {
F_9 ( V_81 L_47 ) ;
V_43 = - V_79 ;
goto V_99;
}
V_72 = ( * V_75 ) / 1000 ;
V_96 = * ( ( T_1 * ) ( V_94 + 0x10 ) ) ;
V_97 = * ( ( T_1 * ) ( V_94 + 0x20 ) ) ;
if ( V_97 == V_96 ) {
F_9 ( V_20 L_48
L_49 ) ;
V_43 = - V_79 ;
goto V_99;
}
V_95 = 0 ;
if ( V_96 != 0 && V_97 != 0 )
V_95 = ( V_72 * V_97 ) / V_96 ;
if ( V_95 >= V_72 || V_95 < 1000 ) {
F_9 ( V_81 L_50 ) ;
V_43 = - V_102 ;
goto V_99;
}
V_34 [ 0 ] . V_35 = V_72 ;
V_34 [ 1 ] . V_35 = V_95 ;
V_64 = V_103 ;
F_11 = F_19 ;
F_29 = F_20 ;
F_33 = F_22 ;
F_11 ( V_38 ) ;
F_8 ( 10 ) ;
V_23 = - 1 ;
F_29 ( F_33 () ) ;
F_9 ( V_90 L_25 ) ;
F_9 ( V_90 L_51
L_52 , V_98 ? L_53 : L_22 ) ;
F_9 ( V_90 L_27 ,
V_34 [ 1 ] . V_35 / 1000 ,
V_34 [ 0 ] . V_35 / 1000 ,
V_34 [ V_23 ] . V_35 / 1000 ) ;
V_43 = F_43 ( & V_91 ) ;
V_99:
if ( V_43 != 0 ) {
F_47 ( V_48 ) ;
F_47 ( V_44 ) ;
F_47 ( V_45 ) ;
F_47 ( V_46 ) ;
F_47 ( V_39 ) ;
F_47 ( V_41 ) ;
F_47 ( V_40 ) ;
F_47 ( V_42 ) ;
}
F_44 ( V_93 ) ;
F_44 ( V_92 ) ;
F_44 ( V_69 ) ;
return V_43 ;
}
static int T_2 F_48 ( void )
{
struct V_68 * V_69 ;
int V_43 = 0 ;
V_69 = F_49 ( 0 ) ;
if ( V_69 == NULL ) {
F_50 ( L_54 ) ;
return - V_79 ;
}
if ( F_38 ( L_55 ) ||
F_38 ( L_56 ) ||
F_38 ( L_57 ) )
V_43 = F_45 ( V_69 ) ;
#ifdef F_51
else
V_43 = F_37 ( V_69 ) ;
#endif
return V_43 ;
}
