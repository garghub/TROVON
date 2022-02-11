static int T_1 F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_2 V_5 ,
T_2 V_6 , unsigned long V_7 ,
T_3 V_8 , int V_9 )
{
const T_4 * V_10 , * V_11 ;
T_5 clock = V_12 * 16 ;
int V_13 ;
V_10 = F_2 ( V_2 , L_1 , NULL ) ;
if ( V_10 && * V_10 )
clock = F_3 ( V_10 ) ;
V_11 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_3 >= 0 && V_3 < V_14 )
V_13 = V_3 ;
else
V_13 = V_15 ;
if ( V_13 >= V_14 )
return - 1 ;
if ( V_13 >= V_15 )
V_15 = V_13 + 1 ;
if ( V_16 [ V_13 ] . V_2 != 0 ) {
if ( V_15 < V_14 ) {
F_4 ( V_17 L_3 ,
V_13 , V_15 ) ;
V_18 [ V_15 ] =
V_18 [ V_13 ] ;
V_16 [ V_15 ] =
V_16 [ V_13 ] ;
V_15 ++ ;
} else {
F_4 ( V_17 L_4 , V_13 ) ;
}
}
memset ( & V_18 [ V_13 ] , 0 ,
sizeof( struct V_19 ) ) ;
if ( V_4 == V_20 )
V_18 [ V_13 ] . V_21 = V_5 ;
else
V_18 [ V_13 ] . V_22 = V_5 ;
V_18 [ V_13 ] . V_4 = V_4 ;
V_18 [ V_13 ] . V_23 = clock ;
V_18 [ V_13 ] . V_7 = V_7 ;
V_18 [ V_13 ] . V_8 = V_8 ;
V_16 [ V_13 ] . V_6 = V_6 ;
V_16 [ V_13 ] . V_2 = F_5 ( V_2 ) ;
V_16 [ V_13 ] . clock = clock ;
V_16 [ V_13 ] . V_24 = V_11 ? F_3 ( V_11 ) : 0 ;
V_16 [ V_13 ] . V_9 = V_9 ;
F_4 ( V_17 L_5 ,
V_13 , V_2 -> V_25 ) ;
F_4 ( V_17 L_6 ,
( V_4 == V_20 ) ? L_7 : L_8 ,
( unsigned long long ) V_5 , ( unsigned long long ) V_6 , V_7 ,
V_18 [ V_13 ] . V_23 ,
V_16 [ V_13 ] . V_24 ) ;
return V_13 ;
}
static int T_1 F_6 ( struct V_1 * V_2 ,
struct V_1 * V_26 )
{
T_6 V_27 ;
const T_5 * V_28 ;
T_3 V_8 = V_29 | V_30 | V_31
| V_32 ;
struct V_1 * V_33 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 , L_1 , NULL ) == NULL )
return - 1 ;
if ( ( F_2 ( V_2 , L_9 , NULL ) != NULL ) ||
( F_2 ( V_2 , L_10 , NULL ) != NULL ) )
return - 1 ;
if ( F_2 ( V_2 , L_11 , NULL ) != NULL )
return - 1 ;
V_28 = F_8 ( V_26 , 0 , NULL , NULL ) ;
if ( V_28 == NULL )
return - 1 ;
V_27 = F_9 ( V_26 , V_28 ) ;
if ( V_27 == V_34 )
return - 1 ;
if ( V_33 && ! strcmp ( V_33 -> type , L_12 ) )
return F_1 ( V_2 , - 1 , V_35 , V_27 , V_27 , V_36 , V_8 , 0 ) ;
else
return F_1 ( V_2 , - 1 , V_37 , V_27 , V_27 , V_36 , V_8 , 0 ) ;
}
static int T_1 F_10 ( struct V_1 * V_2 ,
struct V_1 * V_38 )
{
const T_4 * V_39 ;
const char * V_40 ;
int V_13 = - 1 ;
T_6 V_6 ;
F_11 ( L_13 , V_2 -> V_25 ) ;
V_39 = F_2 ( V_2 , L_14 , NULL ) ;
if ( V_39 == NULL )
return - 1 ;
if ( ! ( F_12 ( V_39 [ 0 ] ) & 0x00000001 ) )
return - 1 ;
V_40 = F_2 ( V_2 , L_15 , NULL ) ;
if ( V_40 && * V_40 == 'S' )
V_13 = F_13 ( V_40 + 1 , NULL , 0 ) - 1 ;
V_6 = F_9 ( V_2 , V_39 ) ;
if ( V_6 == V_34 )
V_6 = 0 ;
return F_1 ( V_2 , V_13 , V_20 , F_12 ( V_39 [ 1 ] ) , V_6 ,
V_36 , V_29 , 0 ) ;
}
static int T_1 F_14 ( struct V_1 * V_2 ,
struct V_1 * V_41 )
{
T_6 V_27 , V_5 ;
const T_5 * V_28 ;
unsigned int V_8 ;
int V_4 , V_13 = - 1 , V_42 = 0 ;
F_11 ( L_16 , V_2 -> V_25 ) ;
if ( F_2 ( V_2 , L_1 , NULL ) == NULL )
return - 1 ;
V_28 = F_15 ( V_41 , 0 , NULL , & V_8 ) ;
if ( V_28 == NULL )
return - 1 ;
V_4 = ( V_8 & V_43 ) ? V_37 : V_20 ;
V_27 = F_9 ( V_41 , V_28 ) ;
if ( V_27 == V_34 )
return - 1 ;
if ( V_4 == V_37 )
V_5 = V_27 ;
else
V_5 = V_28 [ 2 ] ;
if ( V_2 != V_41 ) {
const T_4 * V_39 = F_2 ( V_2 , L_14 , NULL ) ;
if ( V_39 && ( F_3 ( V_39 ) < 4 ) )
V_13 = V_42 = F_3 ( V_39 ) ;
}
if ( F_16 ( V_41 , L_17 ) ||
F_16 ( V_41 , L_18 ) ||
F_16 ( V_41 , L_19 ) ) {
V_27 += 0x200 * V_42 ;
V_5 += 0x200 * V_42 ;
} else {
V_27 += 8 * V_42 ;
V_5 += 8 * V_42 ;
}
return F_1 ( V_2 , V_13 , V_4 , V_5 , V_27 , V_36 ,
V_29 , V_2 != V_41 ) ;
}
static void T_1 F_17 ( int V_44 )
{
struct V_45 * V_46 =
& V_16 [ V_44 ] ;
void T_7 * V_27 ;
if ( V_46 -> V_6 == 0 )
return;
V_27 = F_18 ( V_46 -> V_6 , 0x1000 ) ;
if ( V_27 == NULL )
return;
if ( V_46 -> V_24 == 0 )
V_46 -> V_24 = F_19 ( V_27 , V_46 -> clock ) ;
F_11 ( L_20 , V_46 -> V_24 ) ;
F_20 ( V_27 , V_46 -> V_24 , V_46 -> clock ) ;
}
void T_1 F_21 ( void )
{
struct V_1 * V_2 , * stdout = NULL ;
const char * V_47 ;
int V_13 ;
F_11 ( L_21 ) ;
V_47 = F_2 ( V_48 , L_22 , NULL ) ;
if ( V_47 != NULL ) {
stdout = F_22 ( V_47 ) ;
if ( stdout )
F_11 ( L_23 , stdout -> V_25 ) ;
} else {
F_11 ( L_24 ) ;
}
F_23 (np, L_25 , L_26 ) {
struct V_1 * V_49 = F_7 ( V_2 ) ;
if ( ! V_49 )
continue;
if ( F_24 ( V_50 , V_49 ) != NULL ) {
if ( F_25 ( V_2 ) ) {
V_13 = F_6 ( V_2 , V_2 ) ;
if ( V_13 >= 0 && V_2 == stdout )
V_51 = V_13 ;
}
}
F_26 ( V_49 ) ;
}
F_27 (np, L_25 ) {
struct V_1 * V_52 = F_7 ( V_2 ) ;
if ( V_52 && ! strcmp ( V_52 -> V_53 , L_27 ) ) {
V_13 = F_10 ( V_2 , V_52 ) ;
if ( V_13 >= 0 && V_2 == stdout )
V_51 = V_13 ;
}
F_26 ( V_52 ) ;
}
#ifdef F_28
for ( V_2 = NULL ; ( V_2 = F_29 ( V_2 ) ) ; ) {
struct V_1 * V_54 , * V_49 = F_7 ( V_2 ) ;
if ( V_49 && ! strcmp ( V_49 -> V_53 , L_27 ) ) {
F_26 ( V_49 ) ;
continue;
}
if ( strcmp ( V_2 -> V_53 , L_25 ) && strcmp ( V_2 -> type , L_25 ) ) {
F_26 ( V_49 ) ;
continue;
}
if ( F_16 ( V_2 , L_28 ) ||
F_16 ( V_2 , L_29 ) )
V_54 = V_2 ;
else if ( F_16 ( V_49 , L_28 ) ||
F_16 ( V_49 , L_29 ) )
V_54 = V_49 ;
else {
F_26 ( V_49 ) ;
continue;
}
V_13 = F_14 ( V_2 , V_54 ) ;
if ( V_13 >= 0 && V_2 == stdout )
V_51 = V_13 ;
F_26 ( V_49 ) ;
}
#endif
F_11 ( L_30 , V_51 ) ;
if ( V_51 >= 0 )
F_17 ( V_51 ) ;
F_11 ( L_31 ) ;
}
static void T_1 F_30 ( int V_13 ,
struct V_1 * V_2 ,
struct V_19 * V_55 )
{
unsigned int V_56 ;
F_11 ( L_32 , V_13 ) ;
V_56 = F_31 ( V_2 , 0 ) ;
if ( V_56 == V_36 && V_16 [ V_13 ] . V_9 ) {
V_2 = F_7 ( V_2 ) ;
if ( V_2 == NULL )
return;
V_56 = F_31 ( V_2 , 0 ) ;
F_26 ( V_2 ) ;
}
if ( V_56 == V_36 )
return;
V_55 -> V_7 = V_56 ;
}
static void T_1 F_32 ( int V_13 ,
struct V_1 * V_2 ,
struct V_19 * V_55 )
{
#ifdef F_28
struct V_57 * V_58 ;
F_11 ( L_33 , V_13 ) ;
V_58 = F_33 ( V_2 ) ;
if ( V_58 ) {
unsigned long V_59 = ( unsigned long ) V_58 -> V_60 -
#ifdef F_34
V_61 ;
#else
V_62 ;
#endif
F_11 ( L_34 ,
V_13 , V_55 -> V_21 , V_55 -> V_21 + V_59 ) ;
V_55 -> V_21 += V_59 ;
}
#endif
}
static void T_1 F_35 ( int V_13 ,
struct V_1 * V_2 ,
struct V_19 * V_55 )
{
F_11 ( L_35 , V_13 ) ;
V_55 -> V_63 = F_18 ( V_55 -> V_22 , 0x100 ) ;
}
static int T_1 F_36 ( void )
{
int V_64 ;
if ( V_15 == 0 )
return - V_65 ;
F_11 ( L_36 ) ;
for ( V_64 = 0 ; V_64 < V_15 ; V_64 ++ ) {
struct V_19 * V_55 = & V_18 [ V_64 ] ;
struct V_1 * V_2 = V_16 [ V_64 ] . V_2 ;
if ( V_55 -> V_7 == V_36 )
F_30 ( V_64 , V_2 , V_55 ) ;
if ( V_55 -> V_4 == V_20 )
F_32 ( V_64 , V_2 , V_55 ) ;
if ( ( V_55 -> V_4 == V_37 ) || ( V_55 -> V_4 == V_35 ) )
F_35 ( V_64 , V_2 , V_55 ) ;
}
F_11 ( L_37 ) ;
return F_37 ( & V_66 ) ;
}
static int T_1 F_38 ( void )
{
struct V_1 * V_67 = NULL ;
int V_64 , V_24 = 0 , V_59 = 0 ;
const char * V_53 ;
const T_4 * V_11 ;
F_11 ( L_38 ) ;
if ( strstr ( V_68 , L_39 ) ) {
F_11 ( L_40 ) ;
return - V_69 ;
}
if ( ! V_48 ) {
F_11 ( L_41 ) ;
return - V_65 ;
}
if ( V_51 < 0 ) {
F_11 ( L_42 ) ;
return - V_65 ;
}
V_53 = F_2 ( V_48 , L_22 , NULL ) ;
if ( V_53 == NULL ) {
F_11 ( L_24 ) ;
return - V_65 ;
}
V_67 = F_22 ( V_53 ) ;
if ( ! V_67 ) {
F_11 ( L_43 , V_53 ) ;
return - V_65 ;
}
F_11 ( L_23 , V_67 -> V_25 ) ;
V_53 = F_2 ( V_67 , L_44 , NULL ) ;
if ( ! V_53 ) {
F_11 ( L_45 ) ;
goto V_70;
}
V_11 = F_2 ( V_67 , L_2 , NULL ) ;
if ( V_11 )
V_24 = F_3 ( V_11 ) ;
if ( strcmp ( V_53 , L_25 ) != 0 )
goto V_70;
for ( V_64 = 0 ; V_64 < V_15 ; V_64 ++ ) {
if ( V_67 != V_16 [ V_64 ] . V_2 )
continue;
V_59 = V_64 ;
V_24 = V_16 [ V_64 ] . V_24 ;
break;
}
if ( V_64 >= V_15 )
goto V_70;
F_26 ( V_67 ) ;
F_11 ( L_46 , V_59 ) ;
if ( V_24 ) {
static char T_8 V_71 [ 16 ] ;
sprintf ( V_71 , L_47 , V_24 ) ;
return F_39 ( L_48 , V_59 , V_71 ) ;
} else
return F_39 ( L_48 , V_59 , NULL ) ;
V_70:
F_11 ( L_49 ) ;
F_26 ( V_67 ) ;
return - V_65 ;
}
