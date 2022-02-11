static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_5 , 0xff ) ;
F_2 ( V_6 , V_3 ) ;
F_2 ( V_7 , V_8 ) ;
F_2 ( V_7 , V_9 ) ;
F_2 ( V_6 , V_4 & 0xff ) ;
F_2 ( V_7 , V_10 ) ;
F_2 ( V_7 , V_9 ) ;
F_2 ( V_6 , V_4 >> 8 ) ;
F_2 ( V_7 , V_10 ) ;
F_2 ( V_7 , V_9 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
F_2 ( V_5 , 0xff ) ;
F_2 ( V_6 , V_3 ) ;
F_2 ( V_7 , V_8 ) ;
F_2 ( V_7 , V_9 ) ;
F_2 ( V_5 , 0x00 ) ;
F_2 ( V_7 , V_11 ) ;
F_4 ( V_12 , V_13 ) ;
F_5 ( V_12 , V_13 ) ;
* V_4 = F_6 ( V_6 ) ;
F_2 ( V_7 , V_9 ) ;
F_2 ( V_7 , V_11 ) ;
F_4 ( V_12 , V_13 ) ;
F_5 ( V_12 , V_13 ) ;
* V_4 |= F_6 ( V_6 ) << 8 ;
F_2 ( V_7 , V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = V_17 -> V_2 ;
T_3 V_19 ;
T_2 V_20 , V_21 ;
int V_22 = 20 ;
F_4 ( V_23 , 0x80 ) ;
F_2 ( V_24 , 0xa4 ) ;
F_2 ( V_5 , 0xff ) ;
F_2 ( V_7 , V_25 ) ;
F_2 ( V_7 , V_26 ) ;
F_8 ( 1 ) ;
F_2 ( V_7 , V_25 ) ;
F_2 ( V_7 , V_27 ) ;
F_8 ( 10 ) ;
F_4 ( V_12 , V_13 ) ;
F_5 ( V_12 , V_13 ) ;
V_19 = F_6 ( V_7 ) ;
F_2 ( V_7 , V_25 ) ;
F_2 ( V_7 , V_27 ) ;
do {
F_4 ( V_12 , V_13 ) ;
F_5 ( V_12 , V_13 ) ;
V_19 = F_6 ( V_7 ) ;
} while ( -- V_22 > 0 );
if ( F_9 ( V_15 , & V_20 , & V_21 ) < 0 ||
( V_20 & ~ 0x1 ) != 0x55aa ) {
F_10 ( V_28
L_1 ) ;
return - 1 ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , int V_3 , int V_4 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = V_17 -> V_2 ;
int V_29 ;
T_2 V_30 ;
#ifdef F_12
F_10 ( V_31
L_2 , V_3 , V_4 ) ;
#endif
for ( V_29 = 0 ; V_29 < 100 ; ++ V_29 ) {
F_3 ( V_2 , V_32 , & V_30 ) ;
if ( ! ( V_30 & 0x0010 ) )
break;
F_8 ( 10 ) ;
}
if ( V_29 == 100 ) {
F_10 ( V_28
L_3 ,
V_30 ) ;
return - 1 ;
}
F_1 ( V_2 , V_33 , V_4 ) ;
F_1 ( V_2 , V_34 , V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = V_17 -> V_2 ;
V_15 -> V_35 = 1 ;
F_3 ( V_2 , V_36 , & V_15 -> V_37 ) ;
F_3 ( V_2 , V_38 , & V_15 -> V_39 ) ;
#ifdef F_12
F_10 ( V_31 L_4 ,
V_15 -> V_37 , V_15 -> V_39 ) ;
#endif
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
struct V_14 * V_15 = F_15 ( V_2 -> V_40 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
if ( ! V_15 -> V_41 )
return;
if ( 0 != ( V_19 & 0x000f0000 ) )
F_10 ( V_31 L_5 ,
( V_19 >> 16 ) & 0x0f ) ;
if ( V_19 & 0x100000 ) {
F_16 ( & V_2 -> V_42 -> V_2 ,
V_17 -> V_43 , V_44 , V_45 ) ;
F_17 ( V_15 , V_17 -> V_46 , V_44 ) ;
F_18 ( F_19 ( 5 ) , F_20 ( V_17 -> V_43 ) ) ;
} else {
F_16 ( & V_2 -> V_42 -> V_2 ,
V_17 -> V_47 , V_44 , V_45 ) ;
F_17 ( V_15 , V_17 -> V_48 , V_44 ) ;
F_18 ( F_21 ( 5 ) , F_20 ( V_17 -> V_47 ) ) ;
}
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = V_17 -> V_2 ;
V_17 -> V_47 = F_23 ( & V_2 -> V_42 -> V_2 , F_24 ( V_17 -> V_48 ) ,
0 , V_44 , V_45 ) ;
if ( ! V_17 -> V_47 )
return - V_49 ;
V_17 -> V_43 = F_23 ( & V_2 -> V_42 -> V_2 ,
F_24 ( V_17 -> V_46 ) ,
0 , V_44 , V_45 ) ;
if ( ! V_17 -> V_43 ) {
F_25 ( & V_2 -> V_42 -> V_2 , V_17 -> V_47 , V_44 ,
V_45 ) ;
return - V_49 ;
}
F_18 ( V_50 >> 2 , 0xA300B000 ) ;
F_18 ( V_51 >> 2 , 0x40000200 ) ;
F_2 ( V_5 , 0xff ) ;
F_2 ( V_6 , V_52 ) ;
F_2 ( V_7 , V_8 ) ;
F_2 ( V_5 , 0x00 ) ;
F_2 ( V_23 , 0xe6 ) ;
F_5 ( V_53 , 0x01 ) ;
F_4 ( V_53 , 0x01 ) ;
F_2 ( V_54 , 128 - 1 ) ;
F_2 ( V_55 , ( V_44 >> 7 ) - 1 ) ;
F_2 ( V_56 , 0 ) ;
F_2 ( V_57 , 0 ) ;
F_2 ( V_7 , V_58 ) ;
F_18 ( F_21 ( 5 ) , F_20 ( V_17 -> V_47 ) ) ;
F_18 ( F_19 ( 5 ) , F_20 ( V_17 -> V_43 ) ) ;
F_18 ( F_26 ( 5 ) , 128 ) ;
F_18 ( F_27 ( 5 ) , V_59 ) ;
F_28 ( V_60 , V_61 ) ;
F_28 ( V_62 ,
V_63 | V_64 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 ;
if ( ! V_17 )
return - V_65 ;
V_2 = V_17 -> V_2 ;
if ( ! V_2 )
return - V_65 ;
F_30 ( V_60 , V_61 ) ;
F_30 ( V_62 ,
V_63 | V_64 ) ;
F_4 ( V_23 , 0x80 ) ;
F_25 ( & V_2 -> V_42 -> V_2 , V_17 -> V_47 , V_44 ,
V_45 ) ;
F_25 ( & V_2 -> V_42 -> V_2 , V_17 -> V_43 , V_44 ,
V_45 ) ;
return 0 ;
}
static int F_31 ( struct V_14 * V_15 , T_1 * V_4 , int V_66 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = V_17 -> V_2 ;
T_2 V_30 ;
int V_29 ;
#ifdef F_12
F_10 ( V_31 L_6
L_7 , V_66 ) ;
#endif
while ( V_66 > 0 ) {
V_29 = V_66 > 64 ? 64 : V_66 ;
F_2 ( V_5 , 0xff ) ;
F_2 ( V_6 , V_67 ) ;
F_2 ( V_7 , V_8 ) ;
F_2 ( V_7 , V_9 ) ;
while ( V_29 -- > 0 ) {
F_2 ( V_6 , * V_4 ) ;
F_2 ( V_7 , V_10 ) ;
F_2 ( V_7 , V_9 ) ;
++ V_4 ;
-- V_66 ;
}
for ( V_29 = 0 ; V_29 < 100 ; ++ V_29 ) {
F_3 ( V_2 , V_32 , & V_30 ) ;
if ( ! ( V_30 & 0x0002 ) )
break;
}
if ( V_29 == 100 ) {
F_10 ( V_28 L_8
L_9 , V_30 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_32 ( struct V_14 * V_15 , unsigned int V_68 ,
void * V_69 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = V_17 -> V_2 ;
switch ( V_68 ) {
case V_70 :
{
T_4 * V_71 = V_69 ;
return F_33 ( V_2 , NULL , V_71 ) ;
}
case V_72 :
{
T_4 * V_71 = V_69 ;
* V_71 = V_2 -> V_73 -> V_74 ;
return 0 ;
}
case V_75 :
{
struct V_76 * V_77 = V_69 ;
if ( F_34 ( V_77 -> V_74 ) == V_78 )
return F_35 ( NULL , NULL , V_77 ) ;
}
case V_79 :
{
struct V_80 * V_77 = V_69 ;
if ( F_34 ( V_77 -> V_74 ) == V_78 )
return F_36 ( V_2 , NULL , V_77 ) ;
}
case V_81 :
{
struct V_80 * V_77 = V_69 ;
if ( F_34 ( V_77 -> V_74 ) == V_78 )
return F_37 ( V_2 , NULL , V_77 ) ;
}
}
return - V_65 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_10 ( V_31 L_10 ) ;
V_17 = F_39 ( sizeof( struct V_16 ) , V_82 ) ;
if ( V_17 == NULL )
return - V_49 ;
V_17 -> V_48 = ( T_1 * ) F_40 ( V_82 ) ;
if ( ! V_17 -> V_48 )
goto V_83;
V_17 -> V_46 = ( T_1 * ) F_40 ( V_82 ) ;
if ( ! V_17 -> V_46 )
goto V_83;
V_15 = F_41 ( & V_84 , & V_2 -> V_42 -> V_2 ) ;
if ( V_15 == NULL )
goto V_83;
V_15 -> V_85 = V_86 ;
strncpy ( V_15 -> V_87 , V_88 [ V_2 -> V_89 ] . V_87 , sizeof( V_15 -> V_87 ) ) ;
V_15 -> V_90 = & V_91 ;
V_15 -> V_18 = V_17 ;
V_17 -> V_2 = V_2 ;
if ( F_42 ( V_15 , V_15 -> V_92 -> V_93 &
V_94 ) < 0 )
goto V_95;
if ( F_43 ( V_15 ) < 0 )
goto V_95;
V_2 -> V_40 = V_15 -> V_96 ;
F_44 ( V_2 -> V_40 , V_15 ) ;
V_15 -> V_19 = V_97 ;
return 0 ;
V_95:
V_15 -> V_19 = V_98 ;
return 0 ;
V_83:
if ( V_17 -> V_48 )
F_45 ( ( unsigned long ) V_17 -> V_48 ) ;
if ( V_17 -> V_46 )
F_45 ( ( unsigned long ) V_17 -> V_46 ) ;
F_46 ( V_17 ) ;
return - V_49 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
if ( NULL == V_2 -> V_40 )
return 0 ;
V_15 = F_15 ( V_2 -> V_40 ) ;
V_17 = V_15 -> V_18 ;
V_15 -> V_19 = V_98 ;
F_45 ( ( unsigned long ) V_17 -> V_48 ) ;
F_45 ( ( unsigned long ) V_17 -> V_46 ) ;
F_46 ( V_17 ) ;
F_48 ( V_15 ) ;
V_2 -> V_40 = NULL ;
return 0 ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_99 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_99 ) ;
}
