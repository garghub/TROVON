static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_3 , V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_3 , V_2 -> V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_3 , V_2 -> V_4 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
T_1 * V_7 = ( T_1 * ) V_6 -> V_8 ;
F_8 ( V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_9 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 V_12 = F_10 ( V_9 , V_11 ) * V_11 -> V_13 ;
T_2 V_14 = V_12 / V_15 ;
T_2 V_16 = V_11 -> V_13 / V_15 ;
struct V_5 V_17 ;
F_11 ( V_18 , V_19 ) ;
T_1 V_7 ;
int V_20 ;
int V_3 ;
F_12 ( & V_7 ) ;
V_17 . V_11 = V_11 ;
V_17 . V_21 = F_7 ;
V_17 . V_22 = V_9 ;
V_17 . V_23 = V_11 -> V_13 ;
V_17 . V_8 = ( V_24 ) & V_7 ;
F_13 ( V_25 ) ;
F_14 ( & V_7 , & V_18 ) ;
V_20 = F_15 ( V_11 , & V_17 ) ;
if ( V_20 ) {
F_13 ( V_26 ) ;
F_16 ( & V_7 , & V_18 ) ;
F_17 ( V_27 L_1 ,
( unsigned long long ) V_17 . V_22 ,
( unsigned long long ) V_17 . V_23 , V_28 ) ;
return V_20 ;
}
F_18 () ;
F_16 ( & V_7 , & V_18 ) ;
for ( V_3 = V_14 ; V_3 < V_14 + V_16 ; V_3 ++ )
F_3 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_29 ++ ;
if ( V_2 -> V_29 >= V_2 -> V_30 )
V_2 -> V_29 = 0 ;
V_2 -> V_31 ++ ;
if ( V_2 -> V_31 == 0xffffffff )
V_2 -> V_31 = 0 ;
if ( F_5 ( V_2 , V_2 -> V_29 ) ) {
F_20 ( & V_2 -> V_32 ) ;
return;
}
F_17 ( V_33 L_2 ,
V_2 -> V_29 , V_2 -> V_31 ) ;
}
static void F_21 ( struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_22 ( V_35 , struct V_1 , V_32 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 = 0 , V_37 , V_20 , V_38 ;
if ( ! V_11 )
return;
V_38 = ( V_2 -> V_29 * V_15 ) % V_11 -> V_13 ;
if ( V_38 != 0 ) {
V_2 -> V_29 = V_2 -> V_29 + ( ( V_11 -> V_13 - V_38 ) / V_15 ) ;
if ( V_2 -> V_29 >= V_2 -> V_30 )
V_2 -> V_29 = 0 ;
}
while ( 1 ) {
V_20 = F_23 ( V_11 , V_2 -> V_29 * V_15 ) ;
if ( ! V_20 )
break;
if ( V_20 < 0 ) {
F_17 ( V_39 L_3 ) ;
return;
}
V_40:
F_17 ( V_27 L_4 ,
V_2 -> V_29 * V_15 ) ;
V_36 ++ ;
V_2 -> V_29 = V_2 -> V_29 + ( V_11 -> V_13 / V_15 ) ;
if ( V_2 -> V_29 >= V_2 -> V_30 )
V_2 -> V_29 = 0 ;
if ( V_36 == V_2 -> V_30 / ( V_11 -> V_13 / V_15 ) ) {
F_17 ( V_39 L_5 ) ;
return;
}
}
for ( V_37 = 0 , V_20 = - 1 ; ( V_37 < 3 ) && ( V_20 < 0 ) ; V_37 ++ )
V_20 = F_9 ( V_2 , V_2 -> V_29 * V_15 ) ;
if ( V_20 >= 0 ) {
F_17 ( V_33 L_6 ,
V_2 -> V_29 , V_2 -> V_31 ) ;
return;
}
if ( V_20 == - V_41 ) {
V_20 = F_24 ( V_11 , V_2 -> V_29 * V_15 ) ;
if ( V_20 < 0 && V_20 != - V_42 ) {
F_17 ( V_39 L_7 ) ;
return;
}
}
goto V_40;
}
static void F_25 ( struct V_1 * V_2 , int V_43 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_3 V_44 ;
T_2 * V_45 ;
int V_20 ;
V_45 = V_2 -> V_46 ;
V_45 [ 0 ] = V_2 -> V_31 ;
V_45 [ 1 ] = V_47 ;
if ( V_43 ) {
V_20 = F_26 ( V_11 , V_2 -> V_29 * V_15 ,
V_15 , & V_44 , V_2 -> V_46 ) ;
if ( V_20 == - V_42 ) {
F_17 ( V_39 L_8 ) ;
return;
}
} else
V_20 = F_27 ( V_11 , V_2 -> V_29 * V_15 ,
V_15 , & V_44 , V_2 -> V_46 ) ;
if ( V_44 != V_15 || V_20 < 0 )
F_17 ( V_39 L_9 ,
V_2 -> V_29 * V_15 , V_44 , V_15 , V_20 ) ;
F_1 ( V_2 , V_2 -> V_29 ) ;
memset ( V_2 -> V_46 , 0xff , V_15 ) ;
F_19 ( V_2 ) ;
}
static void F_28 ( struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_22 ( V_35 , struct V_1 , V_48 ) ;
F_25 ( V_2 , 0 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_20 , V_3 , V_49 = 0 ;
T_2 V_50 [ 2 ] , V_51 = 0xffffffff ;
T_3 V_44 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_30 ; V_3 ++ ) {
if ( F_23 ( V_11 , V_3 * V_15 ) )
continue;
F_1 ( V_2 , V_3 ) ;
V_20 = F_30 ( V_11 , V_3 * V_15 , V_52 ,
& V_44 , ( V_53 * ) & V_50 [ 0 ] ) ;
if ( V_44 != V_52 ||
( V_20 < 0 && ! F_31 ( V_20 ) ) ) {
F_17 ( V_39 L_10 ,
V_3 * V_15 , V_44 ,
V_52 , V_20 ) ;
continue;
}
if ( V_50 [ 0 ] == 0xffffffff && V_50 [ 1 ] == 0xffffffff )
F_3 ( V_2 , V_3 ) ;
if ( V_50 [ 0 ] == 0xffffffff )
continue;
if ( V_51 == 0xffffffff ) {
V_51 = V_50 [ 0 ] ;
V_49 = V_3 ;
} else if ( V_50 [ 0 ] < 0x40000000 && V_51 > 0xc0000000 ) {
V_51 = V_50 [ 0 ] ;
V_49 = V_3 ;
} else if ( V_50 [ 0 ] > V_51 && V_50 [ 0 ] < 0xc0000000 ) {
V_51 = V_50 [ 0 ] ;
V_49 = V_3 ;
} else if ( V_50 [ 0 ] > V_51 && V_50 [ 0 ] > 0xc0000000
&& V_51 > 0x80000000 ) {
V_51 = V_50 [ 0 ] ;
V_49 = V_3 ;
}
}
if ( V_51 == 0xffffffff ) {
V_2 -> V_29 = 0 ;
V_2 -> V_31 = 1 ;
F_20 ( & V_2 -> V_32 ) ;
return;
}
V_2 -> V_29 = V_49 ;
V_2 -> V_31 = V_51 ;
F_19 ( V_2 ) ;
}
static void F_32 ( struct V_54 * V_55 ,
enum V_56 V_57 , const char * V_58 , unsigned long V_59 ,
const char * V_60 , unsigned long V_61 )
{
struct V_1 * V_2 = F_22 ( V_55 ,
struct V_1 , V_62 ) ;
unsigned long V_63 , V_64 ;
unsigned long V_65 , V_66 ;
char * V_67 ;
if ( V_57 != V_68 &&
V_57 != V_69 )
return;
if ( V_57 == V_68 && ! V_70 )
return;
V_67 = V_2 -> V_46 + V_52 ;
V_66 = F_33 ( V_61 , V_15 - V_52 ) ;
V_65 = F_33 ( V_59 , V_15 - V_52 - V_66 ) ;
V_64 = V_61 - V_66 ;
V_63 = V_59 - V_65 ;
memcpy ( V_67 , V_58 + V_63 , V_65 ) ;
memcpy ( V_67 + V_65 , V_60 + V_64 , V_66 ) ;
if ( V_57 != V_68 )
F_25 ( V_2 , 1 ) ;
F_20 ( & V_2 -> V_48 ) ;
}
static void F_34 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_71 ;
T_4 V_72 = F_35 ( V_11 -> V_73 , V_15 ) ;
int V_74 ;
if ( ! strcmp ( V_11 -> V_75 , V_28 ) )
V_2 -> V_76 = V_11 -> V_77 ;
if ( V_11 -> V_77 != V_2 -> V_76 || V_2 -> V_76 < 0 )
return;
if ( V_11 -> V_73 < V_11 -> V_13 * 2 ) {
F_17 ( V_39 L_11 ,
V_11 -> V_77 ) ;
return;
}
if ( V_11 -> V_13 < V_15 ) {
F_17 ( V_39 L_12 ,
V_11 -> V_77 ) ;
return;
}
if ( V_11 -> V_73 > V_78 ) {
F_17 ( V_39 L_13 ,
V_11 -> V_77 , V_78 / 1024 / 1024 ) ;
return;
}
V_2 -> V_4 = F_36 ( F_37 ( V_72 ,
V_79 ) * sizeof( unsigned long ) ) ;
if ( ! V_2 -> V_4 ) {
F_17 ( V_39 L_14 ) ;
return;
}
V_2 -> V_62 . V_62 = F_32 ;
V_74 = F_38 ( & V_2 -> V_62 ) ;
if ( V_74 ) {
F_17 ( V_39 L_15 , V_74 ) ;
F_39 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
return;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_30 = ( int ) V_11 -> V_73 / V_15 ;
F_29 ( V_2 ) ;
F_17 ( V_80 L_16 , V_11 -> V_77 ) ;
}
static void F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_71 ;
if ( V_11 -> V_77 != V_2 -> V_76 || V_2 -> V_76 < 0 )
return;
if ( F_41 ( & V_2 -> V_62 ) < 0 )
F_17 ( V_27 L_17 ) ;
V_2 -> V_11 = NULL ;
F_42 ( & V_2 -> V_32 ) ;
F_42 ( & V_2 -> V_48 ) ;
}
static int T_5 F_43 ( void )
{
struct V_1 * V_2 = & V_71 ;
int V_76 ;
char * V_81 ;
if ( strlen ( V_28 ) == 0 ) {
F_17 ( V_39 L_18 ) ;
return - V_82 ;
}
if ( ( V_15 & 4095 ) != 0 ) {
F_17 ( V_39 L_19 ) ;
return - V_82 ;
}
if ( V_15 < 4096 ) {
F_17 ( V_39 L_20 ) ;
return - V_82 ;
}
V_2 -> V_76 = - 1 ;
V_76 = F_44 ( V_28 , & V_81 , 0 ) ;
if ( * V_81 == '\0' )
V_2 -> V_76 = V_76 ;
V_2 -> V_46 = F_36 ( V_15 ) ;
if ( ! V_2 -> V_46 ) {
F_17 ( V_39 L_21 ) ;
return - V_83 ;
}
memset ( V_2 -> V_46 , 0xff , V_15 ) ;
F_45 ( & V_2 -> V_32 , F_21 ) ;
F_45 ( & V_2 -> V_48 , F_28 ) ;
F_46 ( & V_84 ) ;
return 0 ;
}
static void T_6 F_47 ( void )
{
struct V_1 * V_2 = & V_71 ;
F_48 ( & V_84 ) ;
F_39 ( V_2 -> V_46 ) ;
F_39 ( V_2 -> V_4 ) ;
}
