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
V_22 = F_15 ( V_27 -> V_28 , V_20 ) ;
if ( V_22 && ( V_22 -> V_29 <= V_20 ) ) {
struct V_16 * V_16 = V_22 -> V_30 ;
if ( V_16 ) {
struct V_12 * V_12 = & V_16 -> V_19 ;
V_26 = F_12 ( V_12 , V_4 , V_31 - 1 ) ;
V_23 = F_16 ( V_22 -> V_30 ) ;
V_25 = V_23 -> V_32 -> V_33 ;
V_24 = V_23 -> V_34 ;
}
F_3 ( L_7
L_8 ,
V_22 -> V_29 < V_35 ?
V_20 : V_20 - V_22 -> V_29 ,
V_26 , V_22 -> V_29 , V_22 -> V_36 ) ;
} else {
F_3 ( L_9 ) ;
}
}
static void F_17 ( struct V_37 * V_38 )
{
unsigned int V_39 , V_40 ;
unsigned long V_20 ;
F_3 ( L_10 , V_38 -> V_41 ) ;
V_20 = V_27 -> V_42 . V_43 ;
V_39 = V_38 -> V_44 ;
V_40 = V_38 -> V_45 ;
if ( V_39 == V_46 ) {
F_4 ( L_11 ,
( V_40 == 0x01 ) ? L_12 :
( ( V_40 == 0x02 ) ? L_13 : L_14 ) ,
V_20 , V_38 -> V_47 ) ;
} else if ( V_39 == V_48 ) {
F_4 ( L_15 ) ;
} else if ( V_39 == V_49 ) {
F_4 ( L_5 , ( V_40 == 0x0 ) ?
L_16 : L_17 ) ;
} else if ( V_39 == V_50 ) {
if ( V_40 == V_51 )
F_4 ( L_18 ) ;
else if ( V_40 == V_52 )
F_4 ( L_19 , V_20 ) ;
else
F_4 ( L_20 ,
( V_40 == 0x01 ) ? L_12 :
( ( V_40 == 0x02 ) ? L_13 : L_14 ) ) ;
} else if ( V_39 == V_53 ) {
F_4 ( L_21 ) ;
} else {
F_4 ( L_22 ) ;
}
}
void F_18 ( struct V_37 * V_38 )
{
struct V_10 * V_11 = V_27 ;
struct V_7 * V_8 ;
char * V_4 ;
V_4 = ( char * ) F_19 ( V_54 ) ;
if ( ! V_4 )
return;
F_6 ( V_11 , V_4 ) ;
F_20 ( V_55 ) ;
F_17 ( V_38 ) ;
F_3 ( L_23 ,
V_27 -> V_42 . V_43 ,
( void * ) V_38 -> V_56 , ( void * ) V_38 -> V_47 ) ;
if ( F_21 ( V_38 ) )
F_14 ( V_38 -> V_47 , V_4 ) ;
F_3 ( L_24 , V_38 -> V_57 ) ;
#define F_22 ( T_3 , T_4 ) r->status32 & STATUS_##bit##_MASK ? #bit : ""
if ( ! F_21 ( V_38 ) )
F_4 ( L_25 ,
F_22 ( V_38 , V_58 ) , F_22 ( V_38 , V_59 ) , F_22 ( V_38 , V_60 ) ,
F_22 ( V_38 , V_61 ) , F_22 ( V_38 , V_62 ) ) ;
F_3 ( L_26 ,
V_38 -> V_63 , V_38 -> V_64 , V_38 -> V_65 ) ;
F_3 ( L_27 ,
V_38 -> V_66 , V_38 -> V_67 , V_38 -> V_68 ) ;
F_1 ( & ( V_38 -> V_69 ) , 0 ) ;
V_8 = (struct V_7 * ) V_27 -> V_42 . V_70 ;
if ( V_8 )
F_5 ( V_8 ) ;
F_23 ( ( unsigned long ) V_4 ) ;
}
void F_24 ( const char * V_71 , struct V_37 * V_38 ,
unsigned long V_20 )
{
V_27 -> V_42 . V_43 = V_20 ;
F_18 ( V_38 ) ;
if ( ! F_21 ( V_38 ) )
F_25 ( V_27 , V_38 ) ;
}
static int F_26 ( char * V_72 )
{
T_5 V_73 = 0 ;
V_73 += sprintf ( V_72 + V_73 , L_28 , V_74 ) ;
V_73 += sprintf ( V_72 + V_73 , L_29 , V_75 ) ;
V_73 += sprintf ( V_72 + V_73 , L_30 , V_76 ) ;
if ( V_77 )
V_74 = V_75 = V_76 = 0 ;
return V_73 ;
}
static int F_27 ( struct V_23 * V_23 , struct V_16 * V_16 )
{
V_16 -> V_78 = ( void * ) F_19 ( V_79 ) ;
return 0 ;
}
static T_6 F_28 ( struct V_16 * V_16 ,
char T_7 * V_80 ,
T_5 V_6 ,
T_8 * V_81 )
{
T_5 V_73 ;
char * V_72 = ( char * ) V_16 -> V_78 ;
if ( * V_81 != 0 )
return 0 ;
V_73 = F_26 ( V_72 ) ;
return F_29 ( V_80 , V_73 , V_81 , V_72 , V_6 ) ;
}
static T_6 F_30 ( struct V_16 * V_16 , const char T_7 * V_80 ,
T_5 V_82 , T_8 * V_81 )
{
V_74 = V_75 = V_76 = 0 ;
return V_82 ;
}
static int F_31 ( struct V_23 * V_23 , struct V_16 * V_16 )
{
F_23 ( ( unsigned long ) ( V_16 -> V_78 ) ) ;
return 0 ;
}
static int T_9 F_32 ( void )
{
V_83 = F_33 ( L_31 , NULL ) ;
#ifdef F_34
V_84 = F_35 ( L_32 , 0444 , V_83 , NULL ,
& V_85 ) ;
#endif
V_86 =
F_36 ( L_33 , 0444 , V_83 , & V_77 ) ;
return 0 ;
}
static void T_10 F_37 ( void )
{
F_38 ( V_86 ) ;
F_38 ( V_84 ) ;
F_38 ( V_83 ) ;
}
