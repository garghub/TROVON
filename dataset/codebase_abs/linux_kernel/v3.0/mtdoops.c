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
V_20 = V_11 -> V_17 ( V_11 , & V_17 ) ;
if ( V_20 ) {
F_13 ( V_26 ) ;
F_15 ( & V_7 , & V_18 ) ;
F_16 ( V_27 L_1 ,
( unsigned long long ) V_17 . V_22 ,
( unsigned long long ) V_17 . V_23 , V_28 ) ;
return V_20 ;
}
F_17 () ;
F_15 ( & V_7 , & V_18 ) ;
for ( V_3 = V_14 ; V_3 < V_14 + V_16 ; V_3 ++ )
F_3 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_29 ++ ;
if ( V_2 -> V_29 >= V_2 -> V_30 )
V_2 -> V_29 = 0 ;
V_2 -> V_31 ++ ;
if ( V_2 -> V_31 == 0xffffffff )
V_2 -> V_31 = 0 ;
if ( F_5 ( V_2 , V_2 -> V_29 ) ) {
F_19 ( & V_2 -> V_32 ) ;
return;
}
F_16 ( V_33 L_2 ,
V_2 -> V_29 , V_2 -> V_31 ) ;
}
static void F_20 ( struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_21 ( V_35 , struct V_1 , V_32 ) ;
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
while ( V_11 -> V_39 ) {
V_20 = V_11 -> V_39 ( V_11 , V_2 -> V_29 * V_15 ) ;
if ( ! V_20 )
break;
if ( V_20 < 0 ) {
F_16 ( V_40 L_3 ) ;
return;
}
V_41:
F_16 ( V_27 L_4 ,
V_2 -> V_29 * V_15 ) ;
V_36 ++ ;
V_2 -> V_29 = V_2 -> V_29 + ( V_11 -> V_13 / V_15 ) ;
if ( V_2 -> V_29 >= V_2 -> V_30 )
V_2 -> V_29 = 0 ;
if ( V_36 == V_2 -> V_30 / ( V_11 -> V_13 / V_15 ) ) {
F_16 ( V_40 L_5 ) ;
return;
}
}
for ( V_37 = 0 , V_20 = - 1 ; ( V_37 < 3 ) && ( V_20 < 0 ) ; V_37 ++ )
V_20 = F_9 ( V_2 , V_2 -> V_29 * V_15 ) ;
if ( V_20 >= 0 ) {
F_16 ( V_33 L_6 ,
V_2 -> V_29 , V_2 -> V_31 ) ;
return;
}
if ( V_11 -> V_42 && V_20 == - V_43 ) {
V_20 = V_11 -> V_42 ( V_11 , V_2 -> V_29 * V_15 ) ;
if ( V_20 < 0 ) {
F_16 ( V_40 L_7 ) ;
return;
}
}
goto V_41;
}
static void F_22 ( struct V_1 * V_2 , int V_44 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_3 V_45 ;
T_2 * V_46 ;
int V_20 ;
V_46 = V_2 -> V_47 ;
V_46 [ 0 ] = V_2 -> V_31 ;
V_46 [ 1 ] = V_48 ;
if ( V_44 )
V_20 = V_11 -> V_49 ( V_11 , V_2 -> V_29 * V_15 ,
V_15 , & V_45 , V_2 -> V_47 ) ;
else
V_20 = V_11 -> V_50 ( V_11 , V_2 -> V_29 * V_15 ,
V_15 , & V_45 , V_2 -> V_47 ) ;
if ( V_45 != V_15 || V_20 < 0 )
F_16 ( V_40 L_8 ,
V_2 -> V_29 * V_15 , V_45 , V_15 , V_20 ) ;
F_1 ( V_2 , V_2 -> V_29 ) ;
memset ( V_2 -> V_47 , 0xff , V_15 ) ;
F_18 ( V_2 ) ;
}
static void F_23 ( struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_21 ( V_35 , struct V_1 , V_51 ) ;
F_22 ( V_2 , 0 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_20 , V_3 , V_52 = 0 ;
T_2 V_53 [ 2 ] , V_54 = 0xffffffff ;
T_3 V_45 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_30 ; V_3 ++ ) {
F_1 ( V_2 , V_3 ) ;
V_20 = V_11 -> V_55 ( V_11 , V_3 * V_15 , V_56 ,
& V_45 , ( V_57 * ) & V_53 [ 0 ] ) ;
if ( V_45 != V_56 ||
( V_20 < 0 && V_20 != - V_58 ) ) {
F_16 ( V_40 L_9 ,
V_3 * V_15 , V_45 ,
V_56 , V_20 ) ;
continue;
}
if ( V_53 [ 0 ] == 0xffffffff && V_53 [ 1 ] == 0xffffffff )
F_3 ( V_2 , V_3 ) ;
if ( V_53 [ 0 ] == 0xffffffff )
continue;
if ( V_54 == 0xffffffff ) {
V_54 = V_53 [ 0 ] ;
V_52 = V_3 ;
} else if ( V_53 [ 0 ] < 0x40000000 && V_54 > 0xc0000000 ) {
V_54 = V_53 [ 0 ] ;
V_52 = V_3 ;
} else if ( V_53 [ 0 ] > V_54 && V_53 [ 0 ] < 0xc0000000 ) {
V_54 = V_53 [ 0 ] ;
V_52 = V_3 ;
} else if ( V_53 [ 0 ] > V_54 && V_53 [ 0 ] > 0xc0000000
&& V_54 > 0x80000000 ) {
V_54 = V_53 [ 0 ] ;
V_52 = V_3 ;
}
}
if ( V_54 == 0xffffffff ) {
V_2 -> V_29 = 0 ;
V_2 -> V_31 = 1 ;
F_19 ( & V_2 -> V_32 ) ;
return;
}
V_2 -> V_29 = V_52 ;
V_2 -> V_31 = V_54 ;
F_18 ( V_2 ) ;
}
static void F_25 ( struct V_59 * V_60 ,
enum V_61 V_62 , const char * V_63 , unsigned long V_64 ,
const char * V_65 , unsigned long V_66 )
{
struct V_1 * V_2 = F_21 ( V_60 ,
struct V_1 , V_67 ) ;
unsigned long V_68 , V_69 ;
unsigned long V_70 , V_71 ;
char * V_72 ;
if ( V_62 != V_73 &&
V_62 != V_74 &&
V_62 != V_75 )
return;
if ( V_62 == V_73 && ! V_76 )
return;
V_72 = V_2 -> V_47 + V_56 ;
V_71 = F_26 ( V_66 , V_15 - V_56 ) ;
V_70 = F_26 ( V_64 , V_15 - V_56 - V_71 ) ;
V_69 = V_66 - V_71 ;
V_68 = V_64 - V_70 ;
memcpy ( V_72 , V_63 + V_68 , V_70 ) ;
memcpy ( V_72 + V_70 , V_65 + V_69 , V_71 ) ;
if ( V_62 != V_73 ) {
if ( ! V_2 -> V_11 -> V_49 )
F_16 ( V_40 L_10 ) ;
else
F_22 ( V_2 , 1 ) ;
return;
}
F_19 ( & V_2 -> V_51 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_77 ;
T_4 V_78 = F_28 ( V_11 -> V_79 , V_15 ) ;
int V_80 ;
if ( ! strcmp ( V_11 -> V_81 , V_28 ) )
V_2 -> V_82 = V_11 -> V_83 ;
if ( V_11 -> V_83 != V_2 -> V_82 || V_2 -> V_82 < 0 )
return;
if ( V_11 -> V_79 < V_11 -> V_13 * 2 ) {
F_16 ( V_40 L_11 ,
V_11 -> V_83 ) ;
return;
}
if ( V_11 -> V_13 < V_15 ) {
F_16 ( V_40 L_12 ,
V_11 -> V_83 ) ;
return;
}
if ( V_11 -> V_79 > V_84 ) {
F_16 ( V_40 L_13 ,
V_11 -> V_83 , V_84 / 1024 / 1024 ) ;
return;
}
V_2 -> V_4 = F_29 ( F_30 ( V_78 ,
V_85 ) ) ;
if ( ! V_2 -> V_4 ) {
F_16 ( V_40 L_14 ) ;
return;
}
V_2 -> V_67 . V_67 = F_25 ;
V_80 = F_31 ( & V_2 -> V_67 ) ;
if ( V_80 ) {
F_16 ( V_40 L_15 , V_80 ) ;
F_32 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
return;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_30 = ( int ) V_11 -> V_79 / V_15 ;
F_24 ( V_2 ) ;
F_16 ( V_86 L_16 , V_11 -> V_83 ) ;
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_77 ;
if ( V_11 -> V_83 != V_2 -> V_82 || V_2 -> V_82 < 0 )
return;
if ( F_34 ( & V_2 -> V_67 ) < 0 )
F_16 ( V_27 L_17 ) ;
V_2 -> V_11 = NULL ;
F_35 ( & V_2 -> V_32 ) ;
F_35 ( & V_2 -> V_51 ) ;
}
static int T_5 F_36 ( void )
{
struct V_1 * V_2 = & V_77 ;
int V_82 ;
char * V_87 ;
if ( strlen ( V_28 ) == 0 ) {
F_16 ( V_40 L_18 ) ;
return - V_88 ;
}
if ( ( V_15 & 4095 ) != 0 ) {
F_16 ( V_40 L_19 ) ;
return - V_88 ;
}
if ( V_15 < 4096 ) {
F_16 ( V_40 L_20 ) ;
return - V_88 ;
}
V_2 -> V_82 = - 1 ;
V_82 = F_37 ( V_28 , & V_87 , 0 ) ;
if ( * V_87 == '\0' )
V_2 -> V_82 = V_82 ;
V_2 -> V_47 = F_29 ( V_15 ) ;
if ( ! V_2 -> V_47 ) {
F_16 ( V_40 L_21 ) ;
return - V_89 ;
}
memset ( V_2 -> V_47 , 0xff , V_15 ) ;
F_38 ( & V_2 -> V_32 , F_20 ) ;
F_38 ( & V_2 -> V_51 , F_23 ) ;
F_39 ( & V_90 ) ;
return 0 ;
}
static void T_6 F_40 ( void )
{
struct V_1 * V_2 = & V_77 ;
F_41 ( & V_90 ) ;
F_32 ( V_2 -> V_47 ) ;
F_32 ( V_2 -> V_4 ) ;
}
