void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_4 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_4 ( V_4 ) ;
}
static void F_5 ( unsigned long V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
struct V_6 * V_7 = NULL ;
V_7 = (struct V_6 * ) V_2 -> V_8 -> V_9 . V_10 ;
if ( ( V_7 ) && ( V_7 -> V_11 == NULL ) )
return;
F_6 ( & V_2 -> V_12 ) ;
V_2 -> V_12 . V_13 = F_5 ;
V_2 -> V_12 . V_5 = V_5 ;
V_2 -> V_12 . V_14 =
V_15 + V_2 -> V_16 . V_17 . V_18 ;
F_7 ( & V_2 -> V_12 ) ;
if ( ( V_2 -> V_16 . V_17 . V_19 ) && ( V_2 -> V_20 )
&& ( ! V_2 -> V_21 ) ) {
V_2 -> V_21 = TRUE ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
F_9
( L_1 ) ;
}
} else {
F_10
( L_2 ,
V_2 -> V_16 . V_17 . V_19 , V_2 -> V_20 ,
V_2 -> V_21 ) ;
}
}
static void F_11 ( void * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
if ( V_2 -> V_3 ) {
#ifdef F_12
if ( V_2 -> V_20 )
F_13 ( V_24 + V_25 , V_26 ) ;
F_14 ( V_27 , V_28 , TRUE ) ;
#endif
} else {
V_2 -> V_29 = F_15 () ;
}
V_2 -> V_21 = FALSE ;
}
T_1 F_16 ( int V_30 , void * V_5 )
{
F_11 ( V_5 ) ;
return V_31 ;
}
static void F_17 ( struct V_1 * V_2 , int V_32 )
{
unsigned long V_33 ;
V_33 = V_2 -> V_34 - 1 ;
V_33 <<= V_35 ;
if ( V_2 -> V_16 . V_17 . V_36 )
V_33 |= V_37 ;
V_33 |= ( V_38 | V_32 ) ;
F_13 ( V_24 + V_39 , V_33 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_40 != V_41 ) || ( V_2 -> V_16 . V_42 != V_43 )
|| ( ! V_44 ) ) {
goto V_45;
}
if ( V_2 -> V_16 . V_17 . V_19 ) {
V_2 -> V_46 = V_2 -> V_16 . V_17 . V_47 +
V_2 -> V_16 . V_17 . V_48 +
V_2 -> V_16 . V_17 . V_49 ;
V_2 -> V_34 =
V_2 -> V_16 . V_50 + V_2 -> V_46 ;
V_2 -> V_51 =
100000000 / V_2 -> V_16 . V_17 . V_52 ;
V_2 -> V_21 = FALSE ;
V_2 -> V_29 . V_53 . V_54 = 0 ;
V_2 -> V_29 . V_53 . V_55 = 0 ;
#ifdef F_12
if ( V_4 == NULL )
V_4 = F_19 ( NULL , L_3 ) ;
if ( F_20 ( V_4 ) ) {
F_21 ( V_56 L_4 ) ;
V_2 -> V_3 = 0 ;
} else
V_2 -> V_3 = 1 ;
if ( V_2 -> V_3 ) {
T_2 V_57 , V_58 ;
T_2 V_59 ;
V_59 = F_22 ( V_4 ) ;
if ( V_59 == 0 ) {
V_2 -> V_3 = 0 ;
} else {
V_58 =
( V_2 -> V_16 . V_17 . V_52 *
V_2 -> V_34 ) / 100 ;
V_57 =
( V_59 ) /
V_58 ;
F_14 ( V_27 , V_60 ,
FALSE ) ;
F_1 ( V_2 ) ;
F_17 ( V_2 , V_57 ) ;
V_26 = V_2 -> V_16 . V_50 ;
F_13 ( V_24 + V_61 ,
V_26 ) ;
F_13 ( V_24 + V_62 ,
F_23 ( 30 ) | F_23 ( 0 ) ) ;
F_13 ( V_24 + 0x200 ,
( V_63 << 16 ) |
( V_64 ) ) ;
F_3 ( V_2 ) ;
F_14 ( V_27 ,
V_28 , FALSE ) ;
}
}
#else
V_2 -> V_3 = 0 ;
F_24 ( & V_2 -> V_65 , V_66 ,
V_67 ) ;
V_2 -> V_65 . V_13 = V_68 ;
V_2 -> V_69 = F_25 ( V_2 -> V_16 . V_70 * 4 ) ;
#endif
V_2 -> V_71 = 0 ;
if ( V_2 -> V_16 . V_17 . V_36 ) {
T_3 V_72 = V_2 -> V_72 ;
T_3 V_73 ;
if ( V_72 == - 1 ) {
F_9 ( L_5 ) ;
goto V_45;
}
V_73 = F_26 ( F_27
( V_72 ,
( V_2 -> V_3 ) ? 1 : 0 ,
V_74 ,
V_75 ,
V_76 ) ,
V_77 ) ;
if ( V_73 )
goto V_45;
if ( ! V_2 -> V_3 ) {
V_2 -> V_71 = F_28 ( V_72 ) ;
if ( F_29
( V_2 -> V_71 ,
& F_16 ,
V_78 , L_6 ,
( void * ) V_2 ) ) {
F_9
( L_7 ,
V_2 -> V_71 ,
V_72 ) ;
goto V_45;
}
}
}
F_5 ( ( unsigned long ) V_2 ) ;
}
return;
V_45:
if ( V_2 -> V_69 )
F_30 ( V_2 -> V_69 ) ;
V_2 -> V_16 . V_17 . V_19 = FALSE ;
F_21 ( V_56 L_8 , V_79 ) ;
}
void F_31 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = NULL ;
int V_82 = FALSE ;
struct V_6 * V_7 = NULL ;
V_2 = F_32 ( V_81 , struct V_1 , V_23 ) ;
if ( V_2 ) {
if ( V_2 -> V_20 ) {
V_7 =
(struct V_6 * ) V_2 -> V_8 -> V_9 .
V_10 ;
if ( ( ! V_2 -> V_16 . V_17 . V_36 ) &&
( V_2 -> V_3 ) &&
( V_7 ) && ( V_7 -> V_11 != NULL ) ) {
F_14 ( V_27 , V_60 ,
FALSE ) ;
}
if ( V_7 -> V_11 != NULL ) {
V_82 = TRUE ;
V_7 -> V_11 ( F_11 ,
( void * ) V_2 ) ;
}
}
}
if ( ( V_2 ) && ( ! V_82 ) )
V_2 -> V_21 = FALSE ;
}
boolean F_33 ( T_4 V_83 , void * V_5 )
{
return TRUE ;
}
T_2 F_34 ( struct V_1 * V_2 )
{
T_2 V_84 ;
T_2 V_85 ;
T_5 V_86 ;
T_5 V_87 ;
unsigned long V_88 ;
if ( ( ! V_2 -> V_16 . V_17 . V_19 ) || ( ! V_44 ) )
return 0 ;
F_35 ( & V_89 , V_88 ) ;
V_86 = V_2 -> V_29 ;
F_36 ( & V_89 , V_88 ) ;
V_87 = F_15 () ;
V_84 =
( ( V_87 . V_53 . V_54 - V_86 . V_53 . V_54 ) * 1000000 ) +
( ( V_87 . V_53 . V_55 - V_86 . V_53 . V_55 ) / 1000 ) ;
V_84 = V_84 % V_2 -> V_51 ;
V_85 =
( V_84 * V_2 -> V_34 ) / V_2 -> V_51 ;
V_85 =
( V_2 -> V_34 - V_2 -> V_16 . V_17 . V_47 +
V_85 ) % ( V_2 -> V_34 + 1 ) ;
if ( V_85 > V_2 -> V_34 ) {
F_9
( L_9 ) ;
}
return V_85 ;
}
