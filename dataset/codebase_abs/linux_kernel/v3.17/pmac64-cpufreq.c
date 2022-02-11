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
F_8 ( 1000 , 1000 ) ;
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
F_8 ( 10000 , 10000 ) ;
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
F_8 ( 500 , 500 ) ;
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
static int F_23 ( struct V_49 * V_50 , unsigned int V_51 )
{
return F_24 ( V_51 ) ;
}
static unsigned int F_25 ( unsigned int V_52 )
{
return V_34 [ V_23 ] . V_35 ;
}
static int F_26 ( struct V_49 * V_50 )
{
return F_27 ( V_50 , V_34 , V_53 ) ;
}
static int T_2 F_28 ( struct V_54 * V_55 )
{
unsigned int V_56 , V_57 ;
unsigned long V_58 ;
char * V_59 , * V_60 ;
const T_1 * V_61 ;
T_1 V_62 ;
int V_63 = 0 ;
int V_64 = 0 ;
int V_43 = - V_65 ;
if ( F_29 ( L_4 ) ||
F_29 ( L_5 ) ||
F_29 ( L_6 ) ||
F_29 ( L_7 ) )
V_64 = 1 ;
else if ( F_29 ( L_8 ) )
V_63 = 1 ;
else
return - V_65 ;
V_61 = F_30 ( V_55 , L_9 , NULL ) ;
if ( ! V_61 ) {
F_21 ( L_10 ) ;
goto V_66;
}
V_62 = ( * V_61 ) >> 16 ;
if ( V_62 != 0x3c && V_62 != 0x44 ) {
F_9 ( V_67 L_11 ) ;
goto V_66;
}
V_26 = F_30 ( V_55 , L_12 , & V_56 ) ;
if ( ! V_26 ) {
F_21 ( L_13 ) ;
goto V_66;
}
V_37 = V_56 / sizeof( T_1 ) - 1 ;
if ( V_64 ) {
const struct V_68 * V_69 ;
V_69 = F_31 ( V_70 , NULL ) ;
if ( ! V_69 )
goto V_66;
V_71 = (struct V_72 * ) & V_69 [ 1 ] ;
V_57 = ( V_69 -> V_73 * sizeof( T_1 ) ) - sizeof( * V_69 ) ;
V_74 = V_57 / sizeof( * V_71 ) ;
V_7 = 0 ;
if ( V_74 < 1 || V_37 < 1 )
goto V_66;
F_11 = F_1 ;
V_60 = L_14 ;
} else if ( V_63 ) {
struct V_54 * V_75 ;
V_75 = F_32 ( L_15 ) ;
if ( V_75 == NULL ) {
F_9 ( V_67 L_16
L_17 ) ;
goto V_66;
}
V_16 = F_33 ( V_75 , L_18 ) ;
V_19 =
F_33 ( V_75 , L_19 ) ;
if ( V_16 == NULL ||
V_19 == NULL ) {
F_9 ( V_67 L_20
L_21 ) ;
goto V_66;
}
F_11 = F_5 ;
V_60 = L_22 ;
} else {
F_11 = F_18 ;
V_60 = L_23 ;
}
V_61 = F_30 ( V_55 , L_24 , NULL ) ;
if ( ! V_61 )
return - V_65 ;
V_58 = ( * V_61 ) / 1000 ;
V_34 [ 0 ] . V_35 = V_58 ;
V_34 [ 1 ] . V_35 = V_58 / 2 ;
V_53 = 12000 ;
F_24 = F_10 ;
V_76 = F_17 ;
V_59 = L_25 ;
F_11 ( V_38 ) ;
F_34 ( 10 ) ;
V_23 = - 1 ;
F_24 ( V_76 () ) ;
F_9 ( V_77 L_26 ) ;
F_9 ( V_77 L_27 ,
V_59 , V_60 ) ;
F_9 ( V_77 L_28 ,
V_34 [ 1 ] . V_35 / 1000 ,
V_34 [ 0 ] . V_35 / 1000 ,
V_34 [ V_23 ] . V_35 / 1000 ) ;
V_43 = F_35 ( & V_78 ) ;
return V_43 ;
V_66:
F_36 ( V_55 ) ;
return V_43 ;
}
static int T_2 F_37 ( struct V_54 * V_55 )
{
struct V_54 * V_79 = NULL , * V_80 = NULL ;
const T_3 * V_81 = NULL ;
const T_1 * V_61 ;
T_4 V_58 , V_82 , V_83 , V_84 ;
int V_85 = 1 , V_43 = 0 ;
F_21 ( L_29
L_30 ) ;
V_79 = F_32 ( L_31 ) ;
if ( V_79 != NULL )
V_81 = F_30 ( V_79 , L_32 , NULL ) ;
if ( V_81 == NULL ) {
F_9 ( V_67 L_33 ) ;
V_43 = - V_65 ;
goto V_86;
}
F_38 (hwclock, L_34 ) {
const char * V_87 = F_30 ( V_80 ,
L_35 , NULL ) ;
if ( V_87 == NULL )
continue;
if ( strcmp ( V_87 , L_36 ) )
continue;
if ( ! F_30 ( V_80 , L_37 , NULL ) )
continue;
break;
}
if ( V_80 == NULL ) {
F_9 ( V_67 L_38 ) ;
V_43 = - V_65 ;
goto V_86;
}
F_21 ( L_39 , V_80 -> V_88 ) ;
V_48 =
F_33 ( V_80 , L_40 ) ;
V_44 =
F_33 ( V_80 , L_41 ) ;
V_45 =
F_33 ( V_80 , L_42 ) ;
V_46 =
F_33 ( V_80 , L_19 ) ;
V_39 =
F_33 ( V_80 , L_43 ) ;
V_41 =
F_33 ( V_80 , L_44 ) ;
V_40 =
F_33 ( V_80 , L_45 ) ;
V_42 =
F_33 ( V_80 , L_46 ) ;
if ( V_48 == NULL || V_44 == NULL ||
V_45 == NULL || V_46 == NULL ) {
F_9 ( V_67 L_47 ) ;
V_43 = - V_65 ;
goto V_86;
}
if ( V_39 == NULL || V_41 == NULL ) {
F_39 ( V_39 ) ;
F_39 ( V_41 ) ;
V_39 = V_41 = NULL ;
V_85 = 0 ;
}
if ( ! V_85 ||
V_40 == NULL || V_42 == NULL ) {
F_39 ( V_40 ) ;
F_39 ( V_42 ) ;
V_40 = V_42 = NULL ;
}
V_61 = F_30 ( V_55 , L_24 , NULL ) ;
if ( ! V_61 ) {
F_9 ( V_67 L_48 ) ;
V_43 = - V_65 ;
goto V_86;
}
V_58 = ( * V_61 ) / 1000 ;
V_83 = * ( ( T_1 * ) ( V_81 + 0x10 ) ) ;
V_84 = * ( ( T_1 * ) ( V_81 + 0x20 ) ) ;
if ( V_84 == V_83 ) {
F_9 ( V_20 L_49
L_50 ) ;
V_43 = - V_65 ;
goto V_86;
}
V_82 = 0 ;
if ( V_83 != 0 && V_84 != 0 )
V_82 = ( V_58 * V_84 ) / V_83 ;
if ( V_82 >= V_58 || V_82 < 1000 ) {
F_9 ( V_67 L_51 ) ;
V_43 = - V_89 ;
goto V_86;
}
V_34 [ 0 ] . V_35 = V_58 ;
V_34 [ 1 ] . V_35 = V_82 ;
V_53 = 10 * V_90 ;
F_11 = F_19 ;
F_24 = F_20 ;
V_76 = F_22 ;
F_11 ( V_38 ) ;
F_34 ( 10 ) ;
V_23 = - 1 ;
F_24 ( V_76 () ) ;
F_9 ( V_77 L_26 ) ;
F_9 ( V_77 L_52
L_53 , V_85 ? L_54 : L_23 ) ;
F_9 ( V_77 L_28 ,
V_34 [ 1 ] . V_35 / 1000 ,
V_34 [ 0 ] . V_35 / 1000 ,
V_34 [ V_23 ] . V_35 / 1000 ) ;
V_43 = F_35 ( & V_78 ) ;
V_86:
if ( V_43 != 0 ) {
F_39 ( V_48 ) ;
F_39 ( V_44 ) ;
F_39 ( V_45 ) ;
F_39 ( V_46 ) ;
F_39 ( V_39 ) ;
F_39 ( V_41 ) ;
F_39 ( V_40 ) ;
F_39 ( V_42 ) ;
}
F_36 ( V_80 ) ;
F_36 ( V_79 ) ;
F_36 ( V_55 ) ;
return V_43 ;
}
static int T_2 F_40 ( void )
{
struct V_54 * V_55 ;
int V_43 = 0 ;
V_55 = F_41 ( 0 ) ;
if ( V_55 == NULL ) {
F_42 ( L_55 ) ;
return - V_65 ;
}
if ( F_29 ( L_56 ) ||
F_29 ( L_57 ) ||
F_29 ( L_58 ) )
V_43 = F_37 ( V_55 ) ;
#ifdef F_43
else
V_43 = F_28 ( V_55 ) ;
#endif
return V_43 ;
}
