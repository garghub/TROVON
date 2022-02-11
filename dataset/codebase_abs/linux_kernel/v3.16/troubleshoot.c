static T_1 void F_1 ( long * V_1 , int V_2 )
{
unsigned int V_3 ;
char V_4 [ 512 ] ;
int V_5 = 0 , V_6 = sizeof( V_4 ) ;
for ( V_3 = V_2 ; V_3 < V_2 + 13 ; V_3 ++ ) {
V_5 += F_2 ( V_4 + V_5 , V_6 - V_5 , L_1 ,
V_3 , ( unsigned long ) * V_1 ) ;
if ( ( ( V_3 + 1 ) % 3 ) == 0 )
V_5 += F_2 ( V_4 + V_5 , V_6 - V_5 , L_2 ) ;
V_1 -- ;
}
if ( V_2 != 0 )
V_5 += F_2 ( V_4 + V_5 , V_6 - V_5 , L_3 ) ;
if ( V_2 == 0 )
F_3 ( L_4 , V_4 ) ;
else
F_4 ( L_5 , V_4 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_1 ( & ( V_8 -> V_9 ) , 13 ) ;
}
void F_6 ( struct V_10 * V_11 , char * V_4 )
{
struct V_12 V_12 ;
char * V_13 = NULL ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_7 ( V_11 ) ;
if ( ! V_15 )
goto V_18;
V_17 = F_8 ( V_15 ) ;
F_9 ( V_15 ) ;
if ( V_17 ) {
V_12 = V_17 -> V_19 ;
F_10 ( & V_17 -> V_19 ) ;
F_11 ( V_17 ) ;
V_13 = F_12 ( & V_12 , V_4 , 255 ) ;
F_13 ( & V_12 ) ;
}
V_18:
F_3 ( L_6 , V_13 ) ;
}
static void F_14 ( unsigned long V_20 , char * V_4 )
{
struct V_21 * V_22 ;
struct V_23 * V_23 ;
unsigned long V_24 = 0 ;
T_2 V_25 = 0 ;
char * V_26 = V_4 ;
struct V_14 * V_27 = V_28 -> V_27 ;
F_15 ( & V_27 -> V_29 ) ;
V_22 = F_16 ( V_27 , V_20 ) ;
if ( V_22 && ( V_22 -> V_30 <= V_20 ) ) {
struct V_16 * V_16 = V_22 -> V_31 ;
if ( V_16 ) {
struct V_12 * V_12 = & V_16 -> V_19 ;
V_26 = F_12 ( V_12 , V_4 , V_32 - 1 ) ;
V_23 = F_17 ( V_22 -> V_31 ) ;
V_25 = V_23 -> V_33 -> V_34 ;
V_24 = V_23 -> V_35 ;
}
F_3 ( L_7
L_8 ,
V_22 -> V_30 < V_36 ?
V_20 : V_20 - V_22 -> V_30 ,
V_26 , V_22 -> V_30 , V_22 -> V_37 ) ;
} else
F_3 ( L_9 ) ;
F_18 ( & V_27 -> V_29 ) ;
}
static void F_19 ( struct V_38 * V_39 )
{
unsigned int V_40 , V_41 ;
unsigned long V_20 ;
F_3 ( L_10 , V_39 -> V_42 ) ;
V_20 = V_28 -> V_43 . V_44 ;
V_40 = V_39 -> V_45 ;
V_41 = V_39 -> V_46 ;
if ( V_40 == V_47 ) {
F_4 ( L_11 ,
( V_41 == 0x01 ) ? L_12 :
( ( V_41 == 0x02 ) ? L_13 : L_14 ) ,
V_20 , V_39 -> V_48 ) ;
} else if ( V_40 == V_49 ) {
F_4 ( L_15 ) ;
} else if ( V_40 == V_50 ) {
F_4 ( L_5 , ( V_41 == 0x0 ) ?
L_16 : L_17 ) ;
} else if ( V_40 == V_51 ) {
if ( V_41 == V_52 )
F_4 ( L_18 ) ;
else if ( V_41 == V_53 )
F_4 ( L_19 , V_20 ) ;
else
F_4 ( L_20 ,
( V_41 == 0x01 ) ? L_12 :
( ( V_41 == 0x02 ) ? L_13 : L_14 ) ) ;
} else if ( V_40 == V_54 ) {
F_4 ( L_21 ) ;
} else {
F_4 ( L_22 ) ;
}
}
void F_20 ( struct V_38 * V_39 )
{
struct V_10 * V_11 = V_28 ;
struct V_7 * V_8 ;
char * V_4 ;
V_4 = ( char * ) F_21 ( V_55 ) ;
if ( ! V_4 )
return;
F_6 ( V_11 , V_4 ) ;
F_22 ( V_56 ) ;
F_19 ( V_39 ) ;
F_3 ( L_23 ,
V_28 -> V_43 . V_44 ,
( void * ) V_39 -> V_57 , ( void * ) V_39 -> V_48 ) ;
if ( F_23 ( V_39 ) )
F_14 ( V_39 -> V_48 , V_4 ) ;
F_3 ( L_24 , V_39 -> V_58 ) ;
#define F_24 ( T_3 , T_4 ) r->status32 & STATUS_##bit##_MASK ? #bit : ""
if ( ! F_23 ( V_39 ) )
F_4 ( L_25 ,
F_24 ( V_39 , V_59 ) , F_24 ( V_39 , V_60 ) , F_24 ( V_39 , V_61 ) ,
F_24 ( V_39 , V_62 ) , F_24 ( V_39 , V_63 ) ) ;
F_3 ( L_26 ,
V_39 -> V_64 , V_39 -> V_65 , V_39 -> V_66 ) ;
F_3 ( L_27 ,
V_39 -> V_67 , V_39 -> V_68 , V_39 -> V_69 ) ;
F_1 ( & ( V_39 -> V_70 ) , 0 ) ;
V_8 = (struct V_7 * ) V_28 -> V_43 . V_71 ;
if ( V_8 )
F_5 ( V_8 ) ;
F_25 ( ( unsigned long ) V_4 ) ;
}
void F_26 ( const char * V_72 , struct V_38 * V_39 ,
unsigned long V_20 )
{
V_28 -> V_43 . V_44 = V_20 ;
F_20 ( V_39 ) ;
if ( ! F_23 ( V_39 ) )
F_27 ( V_28 , V_39 ) ;
}
static int F_28 ( char * V_73 )
{
T_5 V_74 = 0 ;
V_74 += sprintf ( V_73 + V_74 , L_28 , V_75 ) ;
V_74 += sprintf ( V_73 + V_74 , L_29 , V_76 ) ;
V_74 += sprintf ( V_73 + V_74 , L_30 , V_77 ) ;
if ( V_78 )
V_75 = V_76 = V_77 = 0 ;
return V_74 ;
}
static int F_29 ( struct V_23 * V_23 , struct V_16 * V_16 )
{
V_16 -> V_79 = ( void * ) F_21 ( V_80 ) ;
return 0 ;
}
static T_6 F_30 ( struct V_16 * V_16 ,
char T_7 * V_81 ,
T_5 V_6 ,
T_8 * V_82 )
{
T_5 V_74 ;
char * V_73 = ( char * ) V_16 -> V_79 ;
if ( * V_82 != 0 )
return 0 ;
V_74 = F_28 ( V_73 ) ;
return F_31 ( V_81 , V_74 , V_82 , V_73 , V_6 ) ;
}
static T_6 F_32 ( struct V_16 * V_16 , const char T_7 * V_81 ,
T_5 V_83 , T_8 * V_82 )
{
V_75 = V_76 = V_77 = 0 ;
return V_83 ;
}
static int F_33 ( struct V_23 * V_23 , struct V_16 * V_16 )
{
F_25 ( ( unsigned long ) ( V_16 -> V_79 ) ) ;
return 0 ;
}
static int T_9 F_34 ( void )
{
V_84 = F_35 ( L_31 , NULL ) ;
#ifdef F_36
V_85 = F_37 ( L_32 , 0444 , V_84 , NULL ,
& V_86 ) ;
#endif
V_87 =
F_38 ( L_33 , 0444 , V_84 , & V_78 ) ;
return 0 ;
}
static void T_10 F_39 ( void )
{
F_40 ( V_87 ) ;
F_40 ( V_85 ) ;
F_40 ( V_84 ) ;
}
