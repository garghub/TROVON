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
T_2 V_21 , V_22 ;
int V_23 = 20 ;
F_6 ( V_24 , 0x80 ) ;
F_4 ( V_25 , 0xa4 ) ;
F_4 ( V_8 , 0xff ) ;
F_4 ( V_10 , V_26 ) ;
F_4 ( V_10 , V_27 ) ;
F_10 ( 1 ) ;
F_4 ( V_10 , V_26 ) ;
F_4 ( V_10 , V_28 ) ;
F_10 ( 10 ) ;
F_6 ( V_15 , V_16 ) ;
F_7 ( V_15 , V_16 ) ;
F_8 ( V_10 ) ;
F_4 ( V_10 , V_26 ) ;
F_4 ( V_10 , V_28 ) ;
do {
F_6 ( V_15 , V_16 ) ;
F_7 ( V_15 , V_16 ) ;
F_8 ( V_10 ) ;
} while ( -- V_23 > 0 );
if ( F_11 ( V_18 , & V_21 , & V_22 ) < 0 ||
( V_21 & ~ 0x1 ) != 0x55aa ) {
F_12 ( L_1 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , int V_6 , int V_7 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
int V_29 ;
T_2 V_30 ;
#ifdef F_14
F_15 ( L_2 , V_6 , V_7 ) ;
#endif
for ( V_29 = 0 ; V_29 < 100 ; ++ V_29 ) {
F_5 ( V_5 , V_31 , & V_30 ) ;
if ( ! ( V_30 & 0x0010 ) )
break;
F_10 ( 10 ) ;
}
if ( V_29 == 100 ) {
F_12 ( L_3 ,
V_30 ) ;
return - 1 ;
}
F_3 ( V_5 , V_32 , V_7 ) ;
F_3 ( V_5 , V_33 , V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
V_18 -> V_34 = 1 ;
F_5 ( V_5 , V_35 , & V_18 -> V_36 ) ;
F_5 ( V_5 , V_37 , & V_18 -> V_38 ) ;
#ifdef F_14
F_15 ( L_4 ,
V_18 -> V_36 , V_18 -> V_38 ) ;
#endif
return 0 ;
}
static void F_17 ( struct V_4 * V_5 ,
unsigned long V_39 )
{
struct V_17 * V_18 = F_18 ( V_5 -> V_40 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
if ( ! F_19 ( & V_18 -> V_41 ) )
return;
if ( 0 != ( V_39 & 0x000f0000 ) )
F_15 ( L_5 ,
( V_39 >> 16 ) & 0x0f ) ;
if ( V_39 & 0x100000 ) {
F_20 ( & V_5 -> V_42 -> V_5 ,
V_19 -> V_43 , V_44 , V_45 ) ;
F_21 ( V_18 , V_19 -> V_46 , V_44 ) ;
F_22 ( F_23 ( 5 ) , V_19 -> V_43 ) ;
} else {
F_20 ( & V_5 -> V_42 -> V_5 ,
V_19 -> V_47 , V_44 , V_45 ) ;
F_21 ( V_18 , V_19 -> V_48 , V_44 ) ;
F_22 ( F_24 ( 5 ) , V_19 -> V_47 ) ;
}
}
static int F_25 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
V_19 -> V_47 = F_26 ( & V_5 -> V_42 -> V_5 , F_27 ( V_19 -> V_48 ) ,
0 , V_44 , V_45 ) ;
if ( F_28 ( & V_5 -> V_42 -> V_5 , V_19 -> V_47 ) )
return - V_49 ;
V_19 -> V_43 = F_26 ( & V_5 -> V_42 -> V_5 ,
F_27 ( V_19 -> V_46 ) ,
0 , V_44 , V_45 ) ;
if ( F_28 ( & V_5 -> V_42 -> V_5 , V_19 -> V_43 ) ) {
F_29 ( & V_5 -> V_42 -> V_5 , V_19 -> V_47 , V_44 ,
V_45 ) ;
return - V_49 ;
}
F_22 ( V_50 >> 2 , 0xA300B000 ) ;
F_22 ( V_51 >> 2 , 0x40000200 ) ;
F_4 ( V_8 , 0xff ) ;
F_4 ( V_9 , V_52 ) ;
F_4 ( V_10 , V_11 ) ;
F_4 ( V_8 , 0x00 ) ;
F_4 ( V_24 , 0xe6 ) ;
F_7 ( V_53 , 0x01 ) ;
F_6 ( V_53 , 0x01 ) ;
F_4 ( V_54 , 128 - 1 ) ;
F_4 ( V_55 , ( V_44 >> 7 ) - 1 ) ;
F_4 ( V_56 , 0 ) ;
F_4 ( V_57 , 0 ) ;
F_4 ( V_10 , V_58 ) ;
F_22 ( F_24 ( 5 ) , V_19 -> V_47 ) ;
F_22 ( F_23 ( 5 ) , V_19 -> V_43 ) ;
F_22 ( F_30 ( 5 ) , 128 ) ;
F_22 ( F_31 ( 5 ) , V_59 ) ;
F_32 ( V_60 , V_61 ) ;
F_32 ( V_62 ,
V_63 | V_64 ) ;
return 0 ;
}
static int F_33 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 ;
if ( ! V_19 )
return - V_65 ;
V_5 = V_19 -> V_5 ;
if ( ! V_5 )
return - V_65 ;
F_34 ( V_60 , V_61 ) ;
F_34 ( V_62 ,
V_63 | V_64 ) ;
F_6 ( V_24 , 0x80 ) ;
F_29 ( & V_5 -> V_42 -> V_5 , V_19 -> V_47 , V_44 ,
V_45 ) ;
F_29 ( & V_5 -> V_42 -> V_5 , V_19 -> V_43 , V_44 ,
V_45 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_18 , T_1 * V_7 , int V_66 )
{
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_4 * V_5 = V_19 -> V_5 ;
T_2 V_30 ;
int V_29 ;
#ifdef F_14
F_15 ( L_6 , V_66 ) ;
#endif
while ( V_66 > 0 ) {
V_29 = V_66 > 64 ? 64 : V_66 ;
F_4 ( V_8 , 0xff ) ;
F_4 ( V_9 , V_67 ) ;
F_4 ( V_10 , V_11 ) ;
F_4 ( V_10 , V_12 ) ;
while ( V_29 -- > 0 ) {
F_4 ( V_9 , * V_7 ) ;
F_4 ( V_10 , V_13 ) ;
F_4 ( V_10 , V_12 ) ;
++ V_7 ;
-- V_66 ;
}
for ( V_29 = 0 ; V_29 < 100 ; ++ V_29 ) {
F_5 ( V_5 , V_31 , & V_30 ) ;
if ( ! ( V_30 & 0x0002 ) )
break;
}
if ( V_29 == 100 ) {
F_12 ( L_3 ,
V_30 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , T_3 V_68 )
{
#if 0
struct saa7134_go7007 *saa = to_state(sd);
struct saa7134_dev *dev = saa->dev;
return saa7134_s_std_internal(dev, NULL, norm);
#else
return 0 ;
#endif
}
static int F_37 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
struct V_1 * V_19 ;
struct V_2 * V_3 ;
F_15 ( L_7 ) ;
V_18 = F_38 ( & V_69 , & V_5 -> V_42 -> V_5 ) ;
if ( V_18 == NULL )
return - V_49 ;
V_19 = F_39 ( sizeof( struct V_1 ) , V_70 ) ;
if ( V_19 == NULL ) {
F_40 ( V_18 ) ;
return - V_49 ;
}
V_18 -> V_71 = V_72 ;
snprintf ( V_18 -> V_73 , sizeof( V_18 -> V_73 ) , L_8 , F_41 ( V_5 -> V_42 ) ) ;
F_42 ( V_18 -> V_74 , V_75 [ V_5 -> V_76 ] . V_74 , sizeof( V_18 -> V_74 ) ) ;
V_18 -> V_77 = & V_78 ;
V_18 -> V_20 = V_19 ;
V_19 -> V_5 = V_5 ;
V_3 = & V_19 -> V_3 ;
F_43 ( V_3 , & V_79 ) ;
F_44 ( V_3 , V_19 ) ;
strncpy ( V_3 -> V_74 , L_9 , sizeof( V_3 -> V_74 ) ) ;
V_19 -> V_48 = ( T_1 * ) F_45 ( V_70 ) ;
if ( ! V_19 -> V_48 )
goto V_80;
V_19 -> V_46 = ( T_1 * ) F_45 ( V_70 ) ;
if ( ! V_19 -> V_46 )
goto V_80;
if ( F_46 ( V_18 , V_18 -> V_81 -> V_82 &
V_83 ) < 0 )
goto V_80;
if ( F_47 ( V_18 , V_18 -> V_81 -> V_84 ) < 0 )
goto V_80;
if ( F_48 ( & V_18 -> V_85 , V_3 ) < 0 )
F_49 ( L_10 ) ;
V_5 -> V_40 = & V_18 -> V_86 ;
V_18 -> V_39 = V_87 ;
return 0 ;
V_80:
if ( V_19 -> V_48 )
F_50 ( ( unsigned long ) V_19 -> V_48 ) ;
if ( V_19 -> V_46 )
F_50 ( ( unsigned long ) V_19 -> V_46 ) ;
F_40 ( V_19 ) ;
F_40 ( V_18 ) ;
return - V_49 ;
}
static int F_51 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
struct V_1 * V_19 ;
if ( NULL == V_5 -> V_40 )
return 0 ;
V_18 = F_18 ( V_5 -> V_40 ) ;
if ( V_18 -> V_88 )
F_52 ( V_18 ) ;
V_19 = V_18 -> V_20 ;
V_18 -> V_39 = V_89 ;
F_50 ( ( unsigned long ) V_19 -> V_48 ) ;
F_50 ( ( unsigned long ) V_19 -> V_46 ) ;
F_53 ( & V_19 -> V_3 ) ;
F_40 ( V_19 ) ;
F_54 ( & V_18 -> V_86 ) ;
F_55 ( & V_18 -> V_85 ) ;
V_5 -> V_40 = NULL ;
return 0 ;
}
static int T_4 F_56 ( void )
{
return F_57 ( & V_90 ) ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_90 ) ;
}
