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
F_9 ( L_1 ) ;
}
static int F_10 ( int V_1 )
{
unsigned long V_20 ;
int V_21 ;
if ( V_1 < V_22 )
F_11 ( V_1 ) ;
F_12 ( V_20 ) ;
F_13 ( V_23 , 0 ) ;
F_13 ( V_23 , V_24 | 0 ) ;
F_13 ( V_23 , V_24 |
V_25 [ V_1 ] ) ;
for ( V_21 = 0 ; V_21 < 10 ; V_21 ++ ) {
unsigned long V_26 = F_14 ( V_27 ) ;
if ( ( V_26 & V_28 ) == 0 &&
( ( ( V_26 >> V_29 ) ^
( V_25 [ V_1 ] >> V_30 ) ) & 0x3 )
== 0 )
break;
if ( V_26 & V_31 )
break;
F_15 ( 100 ) ;
}
F_16 ( V_20 ) ;
if ( V_1 > V_22 )
F_11 ( V_1 ) ;
V_22 = V_1 ;
V_32 = V_33 [ V_1 ] . V_34 * 1000ul ;
return 0 ;
}
static int F_17 ( void )
{
unsigned long V_26 = F_14 ( V_27 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 <= V_36 ; V_35 ++ )
if ( ( ( ( V_26 >> V_29 ) ^
( V_25 [ V_35 ] >> V_30 ) ) & 0x3 ) == 0 )
break;
return V_35 ;
}
static void F_18 ( int V_1 )
{
}
static void F_19 ( int V_1 )
{
if ( V_1 == V_37 ) {
if ( V_38 )
F_6 ( V_38 , NULL ) ;
if ( V_39 )
F_6 ( V_39 , NULL ) ;
} else {
if ( V_40 )
F_6 ( V_40 , NULL ) ;
if ( V_41 )
F_6 ( V_41 , NULL ) ;
}
F_8 ( 10000 , 10000 ) ;
}
static int F_20 ( int V_1 )
{
struct V_8 args ;
T_1 V_10 = 0 ;
unsigned long V_11 ;
int V_42 ;
F_21 ( L_2 , V_1 ) ;
if ( V_1 < V_22 )
F_11 ( V_1 ) ;
if ( V_1 == V_37 )
V_42 = F_6 ( V_43 , NULL ) ;
else
V_42 = F_6 ( V_44 , NULL ) ;
if ( V_42 )
F_9 ( L_3 , V_42 ) ;
V_11 = V_17 + V_18 / 10 ;
while( ! F_7 ( V_17 , V_11 ) ) {
args . V_13 = 1 ;
args . V_14 [ 0 ] . V_15 = & V_10 ;
F_6 ( V_45 , & args ) ;
if ( V_10 )
break;
F_8 ( 500 , 500 ) ;
}
if ( V_10 == 0 )
F_9 ( L_1 ) ;
if ( V_1 > V_22 )
F_11 ( V_1 ) ;
V_22 = V_1 ;
V_32 = V_33 [ V_1 ] . V_34 * 1000ul ;
return 0 ;
}
static int F_22 ( void )
{
struct V_8 args ;
T_1 V_46 = 0 ;
args . V_13 = 1 ;
args . V_14 [ 0 ] . V_15 = & V_46 ;
F_6 ( V_47 , & args ) ;
return V_46 ? V_37 : V_12 ;
}
static int F_23 ( struct V_48 * V_49 , unsigned int V_50 )
{
return F_24 ( V_50 ) ;
}
static unsigned int F_25 ( unsigned int V_51 )
{
return V_33 [ V_22 ] . V_34 ;
}
static int F_26 ( struct V_48 * V_49 )
{
return F_27 ( V_49 , V_33 , V_52 ) ;
}
static int T_2 F_28 ( struct V_53 * V_54 )
{
unsigned int V_55 , V_56 ;
unsigned long V_57 ;
char * V_58 , * V_59 ;
const T_1 * V_60 ;
T_1 V_61 ;
int V_62 = 0 ;
int V_63 = 0 ;
int V_42 = - V_64 ;
if ( F_29 ( L_4 ) ||
F_29 ( L_5 ) ||
F_29 ( L_6 ) ||
F_29 ( L_7 ) )
V_63 = 1 ;
else if ( F_29 ( L_8 ) )
V_62 = 1 ;
else
return - V_64 ;
V_60 = F_30 ( V_54 , L_9 , NULL ) ;
if ( ! V_60 ) {
F_21 ( L_10 ) ;
goto V_65;
}
V_61 = ( * V_60 ) >> 16 ;
if ( V_61 != 0x3c && V_61 != 0x44 ) {
F_31 ( L_11 ) ;
goto V_65;
}
V_25 = F_30 ( V_54 , L_12 , & V_55 ) ;
if ( ! V_25 ) {
F_21 ( L_13 ) ;
goto V_65;
}
V_36 = V_55 / sizeof( T_1 ) - 1 ;
if ( V_63 ) {
const struct V_66 * V_67 ;
V_67 = F_32 ( V_68 , NULL ) ;
if ( ! V_67 )
goto V_65;
V_69 = (struct V_70 * ) & V_67 [ 1 ] ;
V_56 = ( V_67 -> V_71 * sizeof( T_1 ) ) - sizeof( * V_67 ) ;
V_72 = V_56 / sizeof( * V_69 ) ;
V_7 = 0 ;
if ( V_72 < 1 || V_36 < 1 )
goto V_65;
F_11 = F_1 ;
V_59 = L_14 ;
} else if ( V_62 ) {
struct V_53 * V_73 ;
V_73 = F_33 ( L_15 ) ;
if ( V_73 == NULL ) {
F_31 ( L_16 ) ;
goto V_65;
}
V_16 = F_34 ( V_73 , L_17 ) ;
V_19 =
F_34 ( V_73 , L_18 ) ;
if ( V_16 == NULL ||
V_19 == NULL ) {
F_31 ( L_19 ) ;
goto V_65;
}
F_11 = F_5 ;
V_59 = L_20 ;
} else {
F_11 = F_18 ;
V_59 = L_21 ;
}
V_60 = F_30 ( V_54 , L_22 , NULL ) ;
if ( ! V_60 )
return - V_64 ;
V_57 = ( * V_60 ) / 1000 ;
V_33 [ 0 ] . V_34 = V_57 ;
V_33 [ 1 ] . V_34 = V_57 / 2 ;
V_52 = 12000 ;
F_24 = F_10 ;
V_74 = F_17 ;
V_58 = L_23 ;
F_11 ( V_37 ) ;
F_35 ( 10 ) ;
V_22 = - 1 ;
F_24 ( V_74 () ) ;
F_36 ( L_24 ) ;
F_36 ( L_25 ,
V_58 , V_59 ) ;
F_36 ( L_26 ,
V_33 [ 1 ] . V_34 / 1000 ,
V_33 [ 0 ] . V_34 / 1000 ,
V_33 [ V_22 ] . V_34 / 1000 ) ;
V_42 = F_37 ( & V_75 ) ;
return V_42 ;
V_65:
F_38 ( V_54 ) ;
return V_42 ;
}
static int T_2 F_39 ( struct V_53 * V_54 )
{
struct V_53 * V_76 = NULL , * V_77 = NULL ;
const T_3 * V_78 = NULL ;
const T_1 * V_60 ;
T_4 V_57 , V_79 , V_80 , V_81 ;
int V_82 = 1 , V_42 = 0 ;
F_21 ( L_27
L_28 ) ;
V_76 = F_33 ( L_29 ) ;
if ( V_76 != NULL )
V_78 = F_30 ( V_76 , L_30 , NULL ) ;
if ( V_78 == NULL ) {
F_31 ( L_31 ) ;
V_42 = - V_64 ;
goto V_83;
}
F_40 (hwclock, L_32 ) {
const char * V_84 = F_30 ( V_77 ,
L_33 , NULL ) ;
if ( V_84 == NULL )
continue;
if ( strcmp ( V_84 , L_34 ) )
continue;
if ( ! F_30 ( V_77 , L_35 , NULL ) )
continue;
break;
}
if ( V_77 == NULL ) {
F_31 ( L_36 ) ;
V_42 = - V_64 ;
goto V_83;
}
F_21 ( L_37 , V_77 -> V_85 ) ;
V_47 =
F_34 ( V_77 , L_38 ) ;
V_43 =
F_34 ( V_77 , L_39 ) ;
V_44 =
F_34 ( V_77 , L_40 ) ;
V_45 =
F_34 ( V_77 , L_18 ) ;
V_38 =
F_34 ( V_77 , L_41 ) ;
V_40 =
F_34 ( V_77 , L_42 ) ;
V_39 =
F_34 ( V_77 , L_43 ) ;
V_41 =
F_34 ( V_77 , L_44 ) ;
if ( V_47 == NULL || V_43 == NULL ||
V_44 == NULL || V_45 == NULL ) {
F_31 ( L_45 ) ;
V_42 = - V_64 ;
goto V_83;
}
if ( V_38 == NULL || V_40 == NULL ) {
F_41 ( V_38 ) ;
F_41 ( V_40 ) ;
V_38 = V_40 = NULL ;
V_82 = 0 ;
}
if ( ! V_82 ||
V_39 == NULL || V_41 == NULL ) {
F_41 ( V_39 ) ;
F_41 ( V_41 ) ;
V_39 = V_41 = NULL ;
}
V_60 = F_30 ( V_54 , L_22 , NULL ) ;
if ( ! V_60 ) {
F_31 ( L_46 ) ;
V_42 = - V_64 ;
goto V_83;
}
V_57 = ( * V_60 ) / 1000 ;
V_80 = * ( ( T_1 * ) ( V_78 + 0x10 ) ) ;
V_81 = * ( ( T_1 * ) ( V_78 + 0x20 ) ) ;
if ( V_81 == V_80 ) {
F_9 ( L_47 ) ;
V_42 = - V_64 ;
goto V_83;
}
V_79 = 0 ;
if ( V_80 != 0 && V_81 != 0 )
V_79 = ( V_57 * V_81 ) / V_80 ;
if ( V_79 >= V_57 || V_79 < 1000 ) {
F_31 ( L_48 ) ;
V_42 = - V_86 ;
goto V_83;
}
V_33 [ 0 ] . V_34 = V_57 ;
V_33 [ 1 ] . V_34 = V_79 ;
V_52 = 10 * V_87 ;
F_11 = F_19 ;
F_24 = F_20 ;
V_74 = F_22 ;
F_11 ( V_37 ) ;
F_35 ( 10 ) ;
V_22 = - 1 ;
F_24 ( V_74 () ) ;
F_36 ( L_24 ) ;
F_36 ( L_49 ,
V_82 ? L_50 : L_21 ) ;
F_36 ( L_26 ,
V_33 [ 1 ] . V_34 / 1000 ,
V_33 [ 0 ] . V_34 / 1000 ,
V_33 [ V_22 ] . V_34 / 1000 ) ;
V_42 = F_37 ( & V_75 ) ;
V_83:
if ( V_42 != 0 ) {
F_41 ( V_47 ) ;
F_41 ( V_43 ) ;
F_41 ( V_44 ) ;
F_41 ( V_45 ) ;
F_41 ( V_38 ) ;
F_41 ( V_40 ) ;
F_41 ( V_39 ) ;
F_41 ( V_41 ) ;
}
F_38 ( V_77 ) ;
F_38 ( V_76 ) ;
F_38 ( V_54 ) ;
return V_42 ;
}
static int T_2 F_42 ( void )
{
struct V_53 * V_54 ;
int V_42 = 0 ;
V_54 = F_43 ( 0 ) ;
if ( V_54 == NULL ) {
F_31 ( L_51 ) ;
return - V_64 ;
}
if ( F_29 ( L_52 ) ||
F_29 ( L_53 ) ||
F_29 ( L_54 ) )
V_42 = F_39 ( V_54 ) ;
#ifdef F_44
else
V_42 = F_28 ( V_54 ) ;
#endif
return V_42 ;
}
