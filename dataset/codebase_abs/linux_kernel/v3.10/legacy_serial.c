static unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_3 = V_3 << V_2 -> V_5 ;
if ( V_3 == V_6 ) {
V_4 = F_2 ( V_2 -> V_7 + ( V_6 & ~ 3 ) ) ;
return ( V_4 >> 16 ) & 0xff ;
} else
return F_3 ( V_2 -> V_7 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , int V_8 )
{
V_3 = V_3 << V_2 -> V_5 ;
if ( ! ( ( V_3 == V_9 ) && ( V_8 & V_10 ) ) )
F_5 ( V_8 , V_2 -> V_7 + V_3 ) ;
}
static int T_1 F_6 ( struct V_11 * V_12 , int V_13 ,
int V_14 , T_2 V_15 ,
T_2 V_16 , unsigned long V_17 ,
T_3 V_18 , int V_19 )
{
const T_4 * V_20 , * V_21 ;
T_5 clock = V_22 * 16 ;
int V_23 ;
V_20 = F_7 ( V_12 , L_1 , NULL ) ;
if ( V_20 && * V_20 )
clock = F_8 ( V_20 ) ;
V_21 = F_7 ( V_12 , L_2 , NULL ) ;
if ( V_13 >= 0 && V_13 < V_24 )
V_23 = V_13 ;
else
V_23 = V_25 ;
if ( V_23 >= V_24 )
return - 1 ;
if ( V_23 >= V_25 )
V_25 = V_23 + 1 ;
if ( V_26 [ V_23 ] . V_12 != 0 ) {
if ( V_25 < V_24 ) {
F_9 ( V_27 L_3 ,
V_23 , V_25 ) ;
V_28 [ V_25 ] =
V_28 [ V_23 ] ;
V_26 [ V_25 ] =
V_26 [ V_23 ] ;
V_25 ++ ;
} else {
F_9 ( V_27 L_4 , V_23 ) ;
}
}
memset ( & V_28 [ V_23 ] , 0 ,
sizeof( struct V_29 ) ) ;
if ( V_14 == V_30 )
V_28 [ V_23 ] . V_31 = V_15 ;
else
V_28 [ V_23 ] . V_32 = V_15 ;
V_28 [ V_23 ] . V_14 = V_14 ;
V_28 [ V_23 ] . V_33 = clock ;
V_28 [ V_23 ] . V_17 = V_17 ;
V_28 [ V_23 ] . V_18 = V_18 ;
V_26 [ V_23 ] . V_16 = V_16 ;
V_26 [ V_23 ] . V_12 = F_10 ( V_12 ) ;
V_26 [ V_23 ] . clock = clock ;
V_26 [ V_23 ] . V_34 = V_21 ? F_8 ( V_21 ) : 0 ;
V_26 [ V_23 ] . V_19 = V_19 ;
if ( V_14 == V_35 ) {
V_28 [ V_23 ] . V_36 = F_1 ;
V_28 [ V_23 ] . V_37 = F_4 ;
}
F_9 ( V_27 L_5 ,
V_23 , V_12 -> V_38 ) ;
F_9 ( V_27 L_6 ,
( V_14 == V_30 ) ? L_7 : L_8 ,
( unsigned long long ) V_15 , ( unsigned long long ) V_16 , V_17 ,
V_28 [ V_23 ] . V_33 ,
V_26 [ V_23 ] . V_34 ) ;
return V_23 ;
}
static int T_1 F_11 ( struct V_11 * V_12 ,
struct V_11 * V_39 )
{
T_6 V_40 ;
const T_5 * V_41 ;
T_3 V_18 = V_42 | V_43 | V_44
| V_45 ;
struct V_11 * V_46 = F_12 ( V_12 ) ;
if ( F_7 ( V_12 , L_1 , NULL ) == NULL )
return - 1 ;
if ( ( F_7 ( V_12 , L_9 , NULL ) != NULL ) ||
( F_7 ( V_12 , L_10 , NULL ) != NULL ) )
return - 1 ;
if ( F_7 ( V_12 , L_11 , NULL ) != NULL )
return - 1 ;
V_41 = F_13 ( V_39 , 0 , NULL , NULL ) ;
if ( V_41 == NULL )
return - 1 ;
V_40 = F_14 ( V_39 , V_41 ) ;
if ( V_40 == V_47 )
return - 1 ;
if ( V_46 && ! strcmp ( V_46 -> type , L_12 ) )
return F_6 ( V_12 , - 1 , V_35 , V_40 , V_40 , V_48 , V_18 , 0 ) ;
else
return F_6 ( V_12 , - 1 , V_49 , V_40 , V_40 , V_48 , V_18 , 0 ) ;
}
static int T_1 F_15 ( struct V_11 * V_12 ,
struct V_11 * V_50 )
{
const T_4 * V_51 ;
const char * V_52 ;
int V_23 = - 1 ;
T_6 V_16 ;
F_16 ( L_13 , V_12 -> V_38 ) ;
V_51 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_51 == NULL )
return - 1 ;
if ( ! ( F_17 ( V_51 [ 0 ] ) & 0x00000001 ) )
return - 1 ;
V_52 = F_7 ( V_12 , L_15 , NULL ) ;
if ( V_52 && * V_52 == 'S' )
V_23 = F_18 ( V_52 + 1 , NULL , 0 ) - 1 ;
V_16 = F_14 ( V_12 , V_51 ) ;
if ( V_16 == V_47 )
V_16 = 0 ;
return F_6 ( V_12 , V_23 , V_30 , F_17 ( V_51 [ 1 ] ) , V_16 ,
V_48 , V_42 , 0 ) ;
}
static int T_1 F_19 ( struct V_11 * V_12 ,
struct V_11 * V_53 )
{
T_6 V_40 , V_15 ;
const T_5 * V_41 ;
unsigned int V_18 ;
int V_14 , V_23 = - 1 , V_54 = 0 ;
F_16 ( L_16 , V_12 -> V_38 ) ;
if ( F_7 ( V_12 , L_1 , NULL ) == NULL )
return - 1 ;
V_41 = F_20 ( V_53 , 0 , NULL , & V_18 ) ;
if ( V_41 == NULL )
return - 1 ;
V_14 = ( V_18 & V_55 ) ? V_49 : V_30 ;
V_40 = F_14 ( V_53 , V_41 ) ;
if ( V_40 == V_47 )
return - 1 ;
if ( V_14 == V_49 )
V_15 = V_40 ;
else
V_15 = V_41 [ 2 ] ;
if ( V_12 != V_53 ) {
const T_4 * V_51 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_51 && ( F_8 ( V_51 ) < 4 ) )
V_23 = V_54 = F_8 ( V_51 ) ;
}
if ( F_21 ( V_53 , L_17 ) ||
F_21 ( V_53 , L_18 ) ||
F_21 ( V_53 , L_19 ) ) {
V_40 += 0x200 * V_54 ;
V_15 += 0x200 * V_54 ;
} else {
V_40 += 8 * V_54 ;
V_15 += 8 * V_54 ;
}
return F_6 ( V_12 , V_23 , V_14 , V_15 , V_40 , V_48 ,
V_42 , V_12 != V_53 ) ;
}
static void T_1 F_22 ( int V_56 )
{
struct V_57 * V_58 =
& V_26 [ V_56 ] ;
void T_7 * V_40 ;
if ( V_58 -> V_16 == 0 )
return;
V_40 = F_23 ( V_58 -> V_16 , 0x1000 ) ;
if ( V_40 == NULL )
return;
if ( V_58 -> V_34 == 0 )
V_58 -> V_34 = F_24 ( V_40 , V_58 -> clock ) ;
F_16 ( L_20 , V_58 -> V_34 ) ;
F_25 ( V_40 , V_58 -> V_34 , V_58 -> clock ) ;
}
void T_1 F_26 ( void )
{
struct V_11 * V_12 , * stdout = NULL ;
const char * V_59 ;
int V_23 ;
F_16 ( L_21 ) ;
V_59 = F_7 ( V_60 , L_22 , NULL ) ;
if ( V_59 != NULL ) {
stdout = F_27 ( V_59 ) ;
if ( stdout )
F_16 ( L_23 , stdout -> V_38 ) ;
} else {
F_16 ( L_24 ) ;
}
F_28 (np, L_25 , L_26 ) {
struct V_11 * V_61 = F_12 ( V_12 ) ;
if ( ! V_61 )
continue;
if ( F_29 ( V_62 , V_61 ) != NULL ) {
if ( F_30 ( V_12 ) ) {
V_23 = F_11 ( V_12 , V_12 ) ;
if ( V_23 >= 0 && V_12 == stdout )
V_63 = V_23 ;
}
}
F_31 ( V_61 ) ;
}
F_32 (np, L_25 ) {
struct V_11 * V_64 = F_12 ( V_12 ) ;
if ( V_64 && ! strcmp ( V_64 -> V_65 , L_27 ) ) {
V_23 = F_15 ( V_12 , V_64 ) ;
if ( V_23 >= 0 && V_12 == stdout )
V_63 = V_23 ;
}
F_31 ( V_64 ) ;
}
#ifdef F_33
for ( V_12 = NULL ; ( V_12 = F_34 ( V_12 ) ) ; ) {
struct V_11 * V_66 , * V_61 = F_12 ( V_12 ) ;
if ( V_61 && ! strcmp ( V_61 -> V_65 , L_27 ) ) {
F_31 ( V_61 ) ;
continue;
}
if ( strcmp ( V_12 -> V_65 , L_25 ) && strcmp ( V_12 -> type , L_25 ) ) {
F_31 ( V_61 ) ;
continue;
}
if ( F_21 ( V_12 , L_28 ) ||
F_21 ( V_12 , L_29 ) )
V_66 = V_12 ;
else if ( F_21 ( V_61 , L_28 ) ||
F_21 ( V_61 , L_29 ) )
V_66 = V_61 ;
else {
F_31 ( V_61 ) ;
continue;
}
V_23 = F_19 ( V_12 , V_66 ) ;
if ( V_23 >= 0 && V_12 == stdout )
V_63 = V_23 ;
F_31 ( V_61 ) ;
}
#endif
F_16 ( L_30 , V_63 ) ;
if ( V_63 >= 0 )
F_22 ( V_63 ) ;
F_16 ( L_31 ) ;
}
static void T_1 F_35 ( int V_23 ,
struct V_11 * V_12 ,
struct V_29 * V_67 )
{
unsigned int V_68 ;
F_16 ( L_32 , V_23 ) ;
V_68 = F_36 ( V_12 , 0 ) ;
if ( V_68 == V_48 && V_26 [ V_23 ] . V_19 ) {
V_12 = F_12 ( V_12 ) ;
if ( V_12 == NULL )
return;
V_68 = F_36 ( V_12 , 0 ) ;
F_31 ( V_12 ) ;
}
if ( V_68 == V_48 )
return;
V_67 -> V_17 = V_68 ;
#ifdef F_37
if ( F_21 ( V_12 , L_33 ) )
V_67 -> V_69 = V_70 ;
#endif
}
static void T_1 F_38 ( int V_23 ,
struct V_11 * V_12 ,
struct V_29 * V_67 )
{
#ifdef F_33
struct V_71 * V_72 ;
F_16 ( L_34 , V_23 ) ;
V_72 = F_39 ( V_12 ) ;
if ( V_72 ) {
unsigned long V_3 = ( unsigned long ) V_72 -> V_73 -
#ifdef F_40
V_74 ;
#else
V_75 ;
#endif
F_16 ( L_35 ,
V_23 , V_67 -> V_31 , V_67 -> V_31 + V_3 ) ;
V_67 -> V_31 += V_3 ;
}
#endif
}
static void T_1 F_41 ( int V_23 ,
struct V_11 * V_12 ,
struct V_29 * V_67 )
{
F_16 ( L_36 , V_23 ) ;
V_67 -> V_7 = F_23 ( V_67 -> V_32 , 0x100 ) ;
}
static int T_1 F_42 ( void )
{
int V_76 ;
if ( V_25 == 0 )
return - V_77 ;
F_16 ( L_37 ) ;
for ( V_76 = 0 ; V_76 < V_25 ; V_76 ++ ) {
struct V_29 * V_67 = & V_28 [ V_76 ] ;
struct V_11 * V_12 = V_26 [ V_76 ] . V_12 ;
if ( V_67 -> V_17 == V_48 )
F_35 ( V_76 , V_12 , V_67 ) ;
if ( V_67 -> V_14 == V_30 )
F_38 ( V_76 , V_12 , V_67 ) ;
if ( ( V_67 -> V_14 == V_49 ) || ( V_67 -> V_14 == V_35 ) )
F_41 ( V_76 , V_12 , V_67 ) ;
}
F_16 ( L_38 ) ;
return F_43 ( & V_78 ) ;
}
static int T_1 F_44 ( void )
{
struct V_11 * V_79 = NULL ;
int V_76 , V_34 = 0 , V_3 = 0 ;
const char * V_65 ;
const T_4 * V_21 ;
F_16 ( L_39 ) ;
if ( strstr ( V_80 , L_40 ) ) {
F_16 ( L_41 ) ;
return - V_81 ;
}
if ( ! V_60 ) {
F_16 ( L_42 ) ;
return - V_77 ;
}
if ( V_63 < 0 ) {
F_16 ( L_43 ) ;
return - V_77 ;
}
V_65 = F_7 ( V_60 , L_22 , NULL ) ;
if ( V_65 == NULL ) {
F_16 ( L_24 ) ;
return - V_77 ;
}
V_79 = F_27 ( V_65 ) ;
if ( ! V_79 ) {
F_16 ( L_44 , V_65 ) ;
return - V_77 ;
}
F_16 ( L_23 , V_79 -> V_38 ) ;
V_65 = F_7 ( V_79 , L_45 , NULL ) ;
if ( ! V_65 ) {
F_16 ( L_46 ) ;
goto V_82;
}
V_21 = F_7 ( V_79 , L_2 , NULL ) ;
if ( V_21 )
V_34 = F_8 ( V_21 ) ;
if ( strcmp ( V_65 , L_25 ) != 0 )
goto V_82;
for ( V_76 = 0 ; V_76 < V_25 ; V_76 ++ ) {
if ( V_79 != V_26 [ V_76 ] . V_12 )
continue;
V_3 = V_76 ;
V_34 = V_26 [ V_76 ] . V_34 ;
break;
}
if ( V_76 >= V_25 )
goto V_82;
F_31 ( V_79 ) ;
F_16 ( L_47 , V_3 ) ;
if ( V_34 ) {
static char T_8 V_83 [ 16 ] ;
sprintf ( V_83 , L_48 , V_34 ) ;
return F_45 ( L_49 , V_3 , V_83 ) ;
} else
return F_45 ( L_49 , V_3 , NULL ) ;
V_82:
F_16 ( L_50 ) ;
F_31 ( V_79 ) ;
return - V_77 ;
}
