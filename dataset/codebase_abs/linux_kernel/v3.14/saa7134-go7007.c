static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 , T_2 V_7 )
{
F_4 ( V_8 , 0xff ) ;
F_4 ( V_9 , V_6 ) ;
F_4 ( V_10 , V_11 ) ;
F_4 ( V_10 , V_12 ) ;
F_4 ( V_9 , V_7 & 0xff ) ;
F_4 ( V_10 , V_13 ) ;
F_4 ( V_10 , V_12 ) ;
F_4 ( V_9 , V_7 >> 8 ) ;
F_4 ( V_10 , V_13 ) ;
F_4 ( V_10 , V_12 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , T_1 V_6 , T_2 * V_7 )
{
F_4 ( V_8 , 0xff ) ;
F_4 ( V_9 , V_6 ) ;
F_4 ( V_10 , V_11 ) ;
F_4 ( V_10 , V_12 ) ;
F_4 ( V_8 , 0x00 ) ;
F_4 ( V_10 , V_14 ) ;
F_6 ( V_15 , V_16 ) ;
F_7 ( V_15 , V_16 ) ;
* V_7 = F_8 ( V_9 ) ;
F_4 ( V_10 , V_12 ) ;
F_4 ( V_10 , V_14 ) ;
F_6 ( V_15 , V_16 ) ;
F_7 ( V_15 , V_16 ) ;
* V_7 |= F_8 ( V_9 ) << 8 ;
F_4 ( V_10 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
T_3 V_21 ;
T_2 V_22 , V_23 ;
int V_24 = 20 ;
F_6 ( V_25 , 0x80 ) ;
F_4 ( V_26 , 0xa4 ) ;
F_4 ( V_8 , 0xff ) ;
F_4 ( V_10 , V_27 ) ;
F_4 ( V_10 , V_28 ) ;
F_10 ( 1 ) ;
F_4 ( V_10 , V_27 ) ;
F_4 ( V_10 , V_29 ) ;
F_10 ( 10 ) ;
F_6 ( V_15 , V_16 ) ;
F_7 ( V_15 , V_16 ) ;
V_21 = F_8 ( V_10 ) ;
F_4 ( V_10 , V_27 ) ;
F_4 ( V_10 , V_29 ) ;
do {
F_6 ( V_15 , V_16 ) ;
F_7 ( V_15 , V_16 ) ;
V_21 = F_8 ( V_10 ) ;
} while ( -- V_24 > 0 );
if ( F_11 ( V_18 , & V_22 , & V_23 ) < 0 ||
( V_22 & ~ 0x1 ) != 0x55aa ) {
F_12 ( V_30
L_1 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , int V_6 , int V_7 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
int V_31 ;
T_2 V_32 ;
#ifdef F_14
F_12 ( V_33
L_2 , V_6 , V_7 ) ;
#endif
for ( V_31 = 0 ; V_31 < 100 ; ++ V_31 ) {
F_5 ( V_5 , V_34 , & V_32 ) ;
if ( ! ( V_32 & 0x0010 ) )
break;
F_10 ( 10 ) ;
}
if ( V_31 == 100 ) {
F_12 ( V_30
L_3 ,
V_32 ) ;
return - 1 ;
}
F_3 ( V_5 , V_35 , V_7 ) ;
F_3 ( V_5 , V_36 , V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
V_18 -> V_37 = 1 ;
F_5 ( V_5 , V_38 , & V_18 -> V_39 ) ;
F_5 ( V_5 , V_40 , & V_18 -> V_41 ) ;
#ifdef F_14
F_12 ( V_33 L_4 ,
V_18 -> V_39 , V_18 -> V_41 ) ;
#endif
return 0 ;
}
static void F_16 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_17 * V_18 = F_17 ( V_5 -> V_42 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
if ( ! F_18 ( & V_18 -> V_43 ) )
return;
if ( 0 != ( V_21 & 0x000f0000 ) )
F_12 ( V_33 L_5 ,
( V_21 >> 16 ) & 0x0f ) ;
if ( V_21 & 0x100000 ) {
F_19 ( & V_5 -> V_44 -> V_5 ,
V_19 -> V_45 , V_46 , V_47 ) ;
F_20 ( V_18 , V_19 -> V_48 , V_46 ) ;
F_21 ( F_22 ( 5 ) , F_23 ( V_19 -> V_45 ) ) ;
} else {
F_19 ( & V_5 -> V_44 -> V_5 ,
V_19 -> V_49 , V_46 , V_47 ) ;
F_20 ( V_18 , V_19 -> V_50 , V_46 ) ;
F_21 ( F_24 ( 5 ) , F_23 ( V_19 -> V_49 ) ) ;
}
}
static int F_25 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
V_19 -> V_49 = F_26 ( & V_5 -> V_44 -> V_5 , F_27 ( V_19 -> V_50 ) ,
0 , V_46 , V_47 ) ;
if ( F_28 ( & V_5 -> V_44 -> V_5 , V_19 -> V_49 ) )
return - V_51 ;
V_19 -> V_45 = F_26 ( & V_5 -> V_44 -> V_5 ,
F_27 ( V_19 -> V_48 ) ,
0 , V_46 , V_47 ) ;
if ( F_28 ( & V_5 -> V_44 -> V_5 , V_19 -> V_45 ) ) {
F_29 ( & V_5 -> V_44 -> V_5 , V_19 -> V_49 , V_46 ,
V_47 ) ;
return - V_51 ;
}
F_21 ( V_52 >> 2 , 0xA300B000 ) ;
F_21 ( V_53 >> 2 , 0x40000200 ) ;
F_4 ( V_8 , 0xff ) ;
F_4 ( V_9 , V_54 ) ;
F_4 ( V_10 , V_11 ) ;
F_4 ( V_8 , 0x00 ) ;
F_4 ( V_25 , 0xe6 ) ;
F_7 ( V_55 , 0x01 ) ;
F_6 ( V_55 , 0x01 ) ;
F_4 ( V_56 , 128 - 1 ) ;
F_4 ( V_57 , ( V_46 >> 7 ) - 1 ) ;
F_4 ( V_58 , 0 ) ;
F_4 ( V_59 , 0 ) ;
F_4 ( V_10 , V_60 ) ;
F_21 ( F_24 ( 5 ) , F_23 ( V_19 -> V_49 ) ) ;
F_21 ( F_22 ( 5 ) , F_23 ( V_19 -> V_45 ) ) ;
F_21 ( F_30 ( 5 ) , 128 ) ;
F_21 ( F_31 ( 5 ) , V_61 ) ;
F_32 ( V_62 , V_63 ) ;
F_32 ( V_64 ,
V_65 | V_66 ) ;
return 0 ;
}
static int F_33 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 ;
if ( ! V_19 )
return - V_67 ;
V_5 = V_19 -> V_5 ;
if ( ! V_5 )
return - V_67 ;
F_34 ( V_62 , V_63 ) ;
F_34 ( V_64 ,
V_65 | V_66 ) ;
F_6 ( V_25 , 0x80 ) ;
F_29 ( & V_5 -> V_44 -> V_5 , V_19 -> V_49 , V_46 ,
V_47 ) ;
F_29 ( & V_5 -> V_44 -> V_5 , V_19 -> V_45 , V_46 ,
V_47 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_18 , T_1 * V_7 , int V_68 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
T_2 V_32 ;
int V_31 ;
#ifdef F_14
F_12 ( V_33 L_6
L_7 , V_68 ) ;
#endif
while ( V_68 > 0 ) {
V_31 = V_68 > 64 ? 64 : V_68 ;
F_4 ( V_8 , 0xff ) ;
F_4 ( V_9 , V_69 ) ;
F_4 ( V_10 , V_11 ) ;
F_4 ( V_10 , V_12 ) ;
while ( V_31 -- > 0 ) {
F_4 ( V_9 , * V_7 ) ;
F_4 ( V_10 , V_13 ) ;
F_4 ( V_10 , V_12 ) ;
++ V_7 ;
-- V_68 ;
}
for ( V_31 = 0 ; V_31 < 100 ; ++ V_31 ) {
F_5 ( V_5 , V_34 , & V_32 ) ;
if ( ! ( V_32 & 0x0002 ) )
break;
}
if ( V_31 == 100 ) {
F_12 ( V_30 L_8
L_9 , V_32 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , T_4 V_70 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_19 -> V_5 ;
return F_37 ( V_5 , NULL , V_70 ) ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
return F_39 ( NULL , NULL , V_72 ) ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_19 -> V_5 ;
return F_41 ( V_5 , NULL , V_74 ) ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_19 -> V_5 ;
return F_43 ( V_5 , NULL , V_74 ) ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
struct V_1 * V_19 ;
struct V_2 * V_3 ;
F_12 ( V_33 L_10 ) ;
V_18 = F_45 ( & V_75 , & V_5 -> V_44 -> V_5 ) ;
if ( V_18 == NULL )
return - V_51 ;
V_19 = F_46 ( sizeof( struct V_1 ) , V_76 ) ;
if ( V_19 == NULL ) {
F_47 ( V_18 ) ;
return - V_51 ;
}
V_18 -> V_77 = V_78 ;
snprintf ( V_18 -> V_79 , sizeof( V_18 -> V_79 ) , L_11 , F_48 ( V_5 -> V_44 ) ) ;
F_49 ( V_18 -> V_80 , V_81 [ V_5 -> V_82 ] . V_80 , sizeof( V_18 -> V_80 ) ) ;
V_18 -> V_83 = & V_84 ;
V_18 -> V_20 = V_19 ;
V_19 -> V_5 = V_5 ;
V_3 = & V_19 -> V_3 ;
F_50 ( V_3 , & V_85 ) ;
F_51 ( V_3 , V_19 ) ;
strncpy ( V_3 -> V_80 , L_12 , sizeof( V_3 -> V_80 ) ) ;
V_19 -> V_50 = ( T_1 * ) F_52 ( V_76 ) ;
if ( ! V_19 -> V_50 )
goto V_86;
V_19 -> V_48 = ( T_1 * ) F_52 ( V_76 ) ;
if ( ! V_19 -> V_48 )
goto V_86;
if ( F_53 ( V_18 , V_18 -> V_87 -> V_88 &
V_89 ) < 0 )
goto V_86;
if ( F_54 ( V_18 , V_18 -> V_87 -> V_90 ) < 0 )
goto V_86;
if ( F_55 ( & V_18 -> V_91 , V_3 ) < 0 )
F_12 ( V_92 L_13 ) ;
V_5 -> V_42 = & V_18 -> V_93 ;
V_18 -> V_21 = V_94 ;
return 0 ;
V_86:
if ( V_19 -> V_50 )
F_56 ( ( unsigned long ) V_19 -> V_50 ) ;
if ( V_19 -> V_48 )
F_56 ( ( unsigned long ) V_19 -> V_48 ) ;
F_47 ( V_19 ) ;
F_47 ( V_18 ) ;
return - V_51 ;
}
static int F_57 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
struct V_1 * V_19 ;
if ( NULL == V_5 -> V_42 )
return 0 ;
V_18 = F_17 ( V_5 -> V_42 ) ;
if ( V_18 -> V_95 )
F_58 ( V_18 ) ;
V_19 = V_18 -> V_20 ;
V_18 -> V_21 = V_96 ;
F_56 ( ( unsigned long ) V_19 -> V_50 ) ;
F_56 ( ( unsigned long ) V_19 -> V_48 ) ;
F_59 ( & V_19 -> V_3 ) ;
F_47 ( V_19 ) ;
F_60 ( & V_18 -> V_93 ) ;
F_61 ( & V_18 -> V_91 ) ;
V_5 -> V_42 = NULL ;
return 0 ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_97 ) ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_97 ) ;
}
