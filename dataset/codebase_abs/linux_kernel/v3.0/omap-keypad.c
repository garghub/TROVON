static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ )
F_2 ( V_5 [ V_3 ] , V_2 & ( 1 << V_3 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_1 )
{
int V_6 ;
T_1 V_2 = 0 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_7 ; V_6 ++ ) {
if ( F_4 ( V_8 [ V_6 ] ) )
V_2 |= ( 1 << V_6 ) ;
}
return V_2 ;
}
static T_2 F_5 ( int V_9 , void * V_10 )
{
struct V_1 * V_1 = V_10 ;
if ( F_6 () ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_7 ; V_11 ++ ) {
int V_12 = F_7 ( V_8 [ V_11 ] ) ;
if ( V_12 == V_9 )
F_8 ( V_12 ) ;
else
F_9 ( V_12 ) ;
}
} else
F_10 ( 1 , V_13 + V_14 ) ;
F_11 ( & V_15 ) ;
return V_16 ;
}
static void F_12 ( unsigned long V_17 )
{
F_11 ( & V_15 ) ;
}
static void F_13 ( struct V_1 * V_1 , unsigned char * V_18 )
{
int V_3 = 0 ;
if ( F_6 () ) {
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ ) {
F_1 ( V_1 , ~ ( 1 << V_3 ) ) ;
V_18 [ V_3 ] = ~ ( F_3 ( V_1 ) ) & 0xff ;
}
F_1 ( V_1 , 0 ) ;
} else {
F_10 ( 1 , V_13 + V_14 ) ;
F_10 ( 0xff , V_13 + V_19 ) ;
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ ) {
F_10 ( ~ ( 1 << V_3 ) & 0xff ,
V_13 + V_19 ) ;
F_14 ( V_1 -> V_20 ) ;
V_18 [ V_3 ] = ~ F_15 ( V_13 +
V_21 ) & 0xff ;
}
F_10 ( 0x00 , V_13 + V_19 ) ;
F_14 ( 2 ) ;
}
}
static void F_16 ( unsigned long V_17 )
{
struct V_1 * V_22 = (struct V_1 * ) V_17 ;
unsigned short * V_23 = V_22 -> V_24 -> V_25 ;
unsigned int V_26 = F_17 ( V_22 -> V_4 ) ;
unsigned char V_27 [ 8 ] , V_28 , V_29 = 0 ;
int V_3 , V_6 ;
int V_30 = 0 ;
F_13 ( V_22 , V_27 ) ;
for ( V_3 = 0 ; V_3 < V_22 -> V_4 ; V_3 ++ ) {
V_28 = V_27 [ V_3 ] ^ V_31 [ V_3 ] ;
V_29 |= V_27 [ V_3 ] ;
if ( V_28 == 0 )
continue;
for ( V_6 = 0 ; V_6 < V_22 -> V_7 ; V_6 ++ ) {
int V_32 ;
if ( ! ( V_28 & ( 1 << V_6 ) ) )
continue;
#ifdef F_18
F_19 ( V_33 L_1 , V_3 ,
V_6 , ( V_27 [ V_3 ] & ( 1 << V_6 ) ) ?
L_2 : L_3 ) ;
#else
V_32 = V_23 [ F_20 ( V_6 , V_3 , V_26 ) ] ;
if ( V_32 < 0 ) {
F_19 ( V_34
L_4 ,
V_3 , V_6 ) ;
V_30 = 1 ;
continue;
}
if ( ! ( V_35 == ( V_32 & V_36 ) ||
V_35 == - 1 ) )
continue;
V_35 = V_32 & V_36 ;
F_21 ( V_22 -> V_24 , V_32 & ~ V_36 ,
V_27 [ V_3 ] & ( 1 << V_6 ) ) ;
#endif
}
}
F_22 ( V_22 -> V_24 ) ;
memcpy ( V_31 , V_27 , sizeof( V_31 ) ) ;
if ( V_29 ) {
int V_20 = V_37 / 20 ;
if ( V_30 )
V_20 = 2 * V_37 ;
F_23 ( & V_22 -> V_38 , V_39 + V_20 ) ;
} else {
if ( F_6 () ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < V_22 -> V_7 ; V_11 ++ )
F_24 ( F_7 ( V_8 [ V_11 ] ) ) ;
} else {
F_10 ( 0 , V_13 + V_14 ) ;
V_35 = - 1 ;
}
}
}
static T_3 F_25 ( struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_44 )
{
return sprintf ( V_44 , L_5 , V_45 ) ;
}
static T_3 F_26 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const char * V_44 , T_4 V_46 )
{
int V_18 ;
if ( sscanf ( V_44 , L_6 , & V_18 ) != 1 )
return - V_47 ;
if ( ( V_18 != 1 ) && ( V_18 != 0 ) )
return - V_47 ;
F_27 ( & V_48 ) ;
if ( V_18 != V_45 ) {
if ( V_18 )
F_24 ( V_49 ) ;
else
F_9 ( V_49 ) ;
V_45 = V_18 ;
}
F_28 ( & V_48 ) ;
return F_29 ( V_44 , V_46 ) ;
}
static int F_30 ( struct V_50 * V_41 , T_5 V_18 )
{
return 0 ;
}
static int F_31 ( struct V_50 * V_41 )
{
return 0 ;
}
static int T_6 F_32 ( struct V_50 * V_51 )
{
struct V_1 * V_1 ;
struct V_52 * V_52 ;
struct V_53 * V_54 = V_51 -> V_41 . V_55 ;
int V_11 , V_56 , V_57 , V_58 , V_59 ;
unsigned int V_26 , V_60 ;
if ( ! V_54 -> V_7 || ! V_54 -> V_4 || ! V_54 -> V_61 ) {
F_19 ( V_62 L_7 ) ;
return - V_47 ;
}
V_26 = F_17 ( V_54 -> V_4 ) ;
V_60 = V_54 -> V_7 << V_26 ;
V_1 = F_33 ( sizeof( struct V_1 ) +
V_60 * sizeof( unsigned short ) , V_63 ) ;
V_52 = F_34 () ;
if ( ! V_1 || ! V_52 ) {
F_35 ( V_1 ) ;
F_36 ( V_52 ) ;
return - V_64 ;
}
F_37 ( V_51 , V_1 ) ;
V_1 -> V_24 = V_52 ;
if ( ! F_6 () )
F_10 ( 1 , V_13 + V_14 ) ;
V_52 -> V_25 = & V_1 [ 1 ] ;
V_52 -> V_65 = sizeof( unsigned short ) ;
V_52 -> V_60 = V_60 ;
if ( V_54 -> V_66 )
F_38 ( V_67 , V_52 -> V_68 ) ;
if ( V_54 -> V_20 )
V_1 -> V_20 = V_54 -> V_20 ;
if ( V_54 -> V_8 && V_54 -> V_5 ) {
V_8 = V_54 -> V_8 ;
V_5 = V_54 -> V_5 ;
}
V_1 -> V_7 = V_54 -> V_7 ;
V_1 -> V_4 = V_54 -> V_4 ;
if ( F_6 () ) {
for ( V_56 = 0 ; V_56 < V_1 -> V_4 ; V_56 ++ ) {
if ( F_39 ( V_5 [ V_56 ] , L_8 ) < 0 ) {
F_19 ( V_62 L_9
L_10 ,
V_5 [ V_56 ] ) ;
goto V_69;
}
F_40 ( V_5 [ V_56 ] , 0 ) ;
}
for ( V_57 = 0 ; V_57 < V_1 -> V_7 ; V_57 ++ ) {
if ( F_39 ( V_8 [ V_57 ] , L_11 ) < 0 ) {
F_19 ( V_62 L_9
L_10 ,
V_8 [ V_57 ] ) ;
goto V_70;
}
F_41 ( V_8 [ V_57 ] ) ;
}
} else {
V_56 = 0 ;
V_57 = 0 ;
}
F_42 ( & V_1 -> V_38 , F_12 , ( unsigned long ) V_1 ) ;
F_43 ( & V_15 ) ;
V_15 . V_17 = ( unsigned long ) V_1 ;
V_59 = F_44 ( & V_51 -> V_41 , & V_71 ) ;
if ( V_59 < 0 )
goto V_70;
F_38 ( V_72 , V_52 -> V_68 ) ;
F_45 ( V_54 -> V_61 , V_26 ,
V_52 -> V_25 , V_52 -> V_73 ) ;
V_52 -> V_74 = L_12 ;
V_52 -> V_75 = L_13 ;
V_52 -> V_41 . V_76 = & V_51 -> V_41 ;
V_52 -> V_77 . V_78 = V_79 ;
V_52 -> V_77 . V_80 = 0x0001 ;
V_52 -> V_77 . V_81 = 0x0001 ;
V_52 -> V_77 . V_82 = 0x0100 ;
V_59 = F_46 ( V_1 -> V_24 ) ;
if ( V_59 < 0 ) {
F_19 ( V_62 L_14 ) ;
goto V_83;
}
if ( V_54 -> V_84 )
F_10 ( 0xff , V_13 + V_85 ) ;
F_13 ( V_1 , V_31 ) ;
if ( ! F_6 () ) {
V_1 -> V_9 = F_47 ( V_51 , 0 ) ;
if ( V_1 -> V_9 >= 0 ) {
if ( F_48 ( V_1 -> V_9 , F_5 , 0 ,
L_12 , V_1 ) < 0 )
goto V_86;
}
F_10 ( 0 , V_13 + V_14 ) ;
} else {
for ( V_58 = 0 ; V_58 < V_1 -> V_7 ; V_58 ++ ) {
if ( F_48 ( F_7 ( V_8 [ V_58 ] ) ,
F_5 ,
V_87 ,
L_12 , V_1 ) < 0 )
goto V_88;
}
}
return 0 ;
V_88:
for ( V_11 = V_58 - 1 ; V_11 >= 0 ; V_11 -- )
F_49 ( V_8 [ V_11 ] , V_1 ) ;
V_86:
F_50 ( V_1 -> V_24 ) ;
V_52 = NULL ;
V_83:
F_51 ( & V_51 -> V_41 , & V_71 ) ;
V_70:
for ( V_11 = V_57 - 1 ; V_11 >= 0 ; V_11 -- )
F_52 ( V_8 [ V_11 ] ) ;
V_69:
for ( V_11 = V_56 - 1 ; V_11 >= 0 ; V_11 -- )
F_52 ( V_5 [ V_11 ] ) ;
F_35 ( V_1 ) ;
F_36 ( V_52 ) ;
return - V_47 ;
}
static int T_7 F_53 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_54 ( V_51 ) ;
F_55 ( & V_15 ) ;
if ( F_6 () ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_4 ; V_11 ++ )
F_52 ( V_5 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_1 -> V_7 ; V_11 ++ ) {
F_52 ( V_8 [ V_11 ] ) ;
F_49 ( F_7 ( V_8 [ V_11 ] ) , V_1 ) ;
}
} else {
F_10 ( 1 , V_13 + V_14 ) ;
F_49 ( V_1 -> V_9 , V_1 ) ;
}
F_56 ( & V_1 -> V_38 ) ;
F_57 ( & V_15 ) ;
F_50 ( V_1 -> V_24 ) ;
F_35 ( V_1 ) ;
return 0 ;
}
static int T_8 F_58 ( void )
{
F_19 ( V_33 L_15 ) ;
return F_59 ( & V_89 ) ;
}
static void T_9 F_60 ( void )
{
F_61 ( & V_89 ) ;
}
