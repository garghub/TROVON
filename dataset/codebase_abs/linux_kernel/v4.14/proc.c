static int F_1 ( int type , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( ( long ) V_2 -> V_5 ) ;
const struct V_6 * V_7 ;
switch ( type ) {
case V_8 :
case V_9 :
V_7 = V_4 -> V_10 . V_11 ;
#ifdef F_3
if ( F_4 ( & V_4 -> V_12 ) )
V_7 = V_4 -> V_13 ;
#endif
break;
case V_14 :
case V_15 :
#ifdef F_5
V_7 = F_6 ( & V_4 -> V_12 ) ;
break;
#endif
default:
return - V_16 ;
}
switch ( type ) {
case V_9 :
case V_15 :
F_7 ( V_2 , L_1 , F_8 ( V_7 ) ) ;
break;
case V_8 :
case V_14 :
F_7 ( V_2 , L_2 , F_8 ( V_7 ) ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_17 )
{
struct V_3 * V_4 = F_2 ( ( long ) V_2 -> V_5 ) ;
unsigned long V_18 ;
T_1 V_7 ;
if ( ! F_10 ( & V_7 , V_19 ) )
return - V_20 ;
F_11 ( & V_4 -> V_21 , V_18 ) ;
if ( V_4 -> V_22 )
F_12 ( V_7 , V_4 -> V_22 ) ;
F_13 ( & V_4 -> V_21 , V_18 ) ;
F_7 ( V_2 , L_2 , F_8 ( V_7 ) ) ;
F_14 ( V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_17 )
{
return F_1 ( V_8 , V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , void * V_17 )
{
return F_1 ( V_9 , V_2 ) ;
}
static T_2 F_17 ( int type , struct V_23 * V_23 ,
const char T_3 * V_24 , T_4 V_25 , T_5 * V_26 )
{
unsigned int V_27 = ( int ) ( long ) F_18 ( F_19 ( V_23 ) ) ;
T_1 V_28 ;
int V_29 ;
if ( ! F_20 ( V_27 ) || V_30 )
return - V_31 ;
if ( ! F_21 ( & V_28 , V_19 ) )
return - V_20 ;
if ( type )
V_29 = F_22 ( V_24 , V_25 , V_28 ) ;
else
V_29 = F_23 ( V_24 , V_25 , V_28 ) ;
if ( V_29 )
goto V_32;
if ( ! F_24 ( V_28 ) ) {
V_29 = - V_16 ;
goto V_32;
}
if ( ! F_25 ( V_28 , V_33 ) ) {
V_29 = F_26 ( V_27 ) ? - V_16 : V_25 ;
} else {
F_27 ( V_27 , V_28 ) ;
V_29 = V_25 ;
}
V_32:
F_14 ( V_28 ) ;
return V_29 ;
}
static T_2 F_28 ( struct V_23 * V_23 ,
const char T_3 * V_24 , T_4 V_25 , T_5 * V_26 )
{
return F_17 ( 0 , V_23 , V_24 , V_25 , V_26 ) ;
}
static T_2 F_29 ( struct V_23 * V_23 ,
const char T_3 * V_24 , T_4 V_25 , T_5 * V_26 )
{
return F_17 ( 1 , V_23 , V_24 , V_25 , V_26 ) ;
}
static int F_30 ( struct V_34 * V_34 , struct V_23 * V_23 )
{
return F_31 ( V_23 , F_15 , F_18 ( V_34 ) ) ;
}
static int F_32 ( struct V_34 * V_34 , struct V_23 * V_23 )
{
return F_31 ( V_23 , F_16 , F_18 ( V_34 ) ) ;
}
static int F_33 ( struct V_34 * V_34 , struct V_23 * V_23 )
{
return F_31 ( V_23 , F_9 , F_18 ( V_34 ) ) ;
}
static int F_34 ( struct V_1 * V_2 , void * V_17 )
{
return F_1 ( V_14 , V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , void * V_17 )
{
return F_1 ( V_15 , V_2 ) ;
}
static int F_36 ( struct V_34 * V_34 , struct V_23 * V_23 )
{
return F_31 ( V_23 , F_34 , F_18 ( V_34 ) ) ;
}
static int F_37 ( struct V_34 * V_34 ,
struct V_23 * V_23 )
{
return F_31 ( V_23 , F_35 ,
F_18 ( V_34 ) ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_17 )
{
F_7 ( V_2 , L_2 , F_8 ( V_35 ) ) ;
return 0 ;
}
static T_2 F_39 ( struct V_23 * V_23 ,
const char T_3 * V_24 , T_4 V_25 , T_5 * V_36 )
{
T_1 V_28 ;
int V_29 ;
if ( ! F_21 ( & V_28 , V_19 ) )
return - V_20 ;
V_29 = F_23 ( V_24 , V_25 , V_28 ) ;
if ( V_29 )
goto V_37;
if ( ! F_24 ( V_28 ) ) {
V_29 = - V_16 ;
goto V_37;
}
if ( ! F_25 ( V_28 , V_33 ) ) {
V_29 = - V_16 ;
goto V_37;
}
F_12 ( V_35 , V_28 ) ;
V_29 = V_25 ;
V_37:
F_14 ( V_28 ) ;
return V_29 ;
}
static int F_40 ( struct V_34 * V_34 , struct V_23 * V_23 )
{
return F_31 ( V_23 , F_38 , F_18 ( V_34 ) ) ;
}
static int F_41 ( struct V_1 * V_2 , void * V_17 )
{
struct V_3 * V_4 = F_2 ( ( long ) V_2 -> V_5 ) ;
F_7 ( V_2 , L_3 , F_42 ( V_4 ) ) ;
return 0 ;
}
static int F_43 ( struct V_34 * V_34 , struct V_23 * V_23 )
{
return F_31 ( V_23 , F_41 , F_18 ( V_34 ) ) ;
}
static int F_44 ( struct V_1 * V_2 , void * V_17 )
{
struct V_3 * V_4 = F_2 ( ( long ) V_2 -> V_5 ) ;
F_7 ( V_2 , L_4 L_5 L_6 ,
V_4 -> V_38 , V_4 -> V_39 ,
F_45 ( V_4 -> V_40 ) ) ;
return 0 ;
}
static int F_46 ( struct V_34 * V_34 , struct V_23 * V_23 )
{
return F_31 ( V_23 , F_44 , F_18 ( V_34 ) ) ;
}
static int F_47 ( unsigned int V_27 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_41 * V_43 ;
unsigned long V_18 ;
int V_44 = 1 ;
F_11 ( & V_4 -> V_21 , V_18 ) ;
F_48 (desc, action) {
if ( ( V_43 != V_42 ) && V_43 -> V_45 &&
! strcmp ( V_42 -> V_45 , V_43 -> V_45 ) ) {
V_44 = 0 ;
break;
}
}
F_13 ( & V_4 -> V_21 , V_18 ) ;
return V_44 ;
}
void F_49 ( unsigned int V_27 , struct V_41 * V_43 )
{
char V_45 [ V_46 ] ;
struct V_3 * V_4 = F_2 ( V_27 ) ;
if ( ! V_4 -> V_47 || V_43 -> V_47 || ! V_43 -> V_45 ||
! F_47 ( V_27 , V_43 ) )
return;
snprintf ( V_45 , V_46 , L_7 , V_43 -> V_45 ) ;
V_43 -> V_47 = F_50 ( V_45 , V_4 -> V_47 ) ;
}
void F_51 ( unsigned int V_27 , struct V_3 * V_4 )
{
static F_52 ( V_48 ) ;
void T_6 * V_49 = ( void * ) ( unsigned long ) V_27 ;
char V_45 [ V_46 ] ;
if ( ! V_50 || ( V_4 -> V_12 . V_51 == & V_52 ) )
return;
F_53 ( & V_48 ) ;
if ( V_4 -> V_47 )
goto V_53;
sprintf ( V_45 , L_8 , V_27 ) ;
V_4 -> V_47 = F_50 ( V_45 , V_50 ) ;
if ( ! V_4 -> V_47 )
goto V_53;
#ifdef F_54
F_55 ( L_9 , 0644 , V_4 -> V_47 ,
& V_54 , V_49 ) ;
F_55 ( L_10 , 0444 , V_4 -> V_47 ,
& V_55 , V_49 ) ;
F_55 ( L_11 , 0644 , V_4 -> V_47 ,
& V_56 , V_49 ) ;
F_55 ( L_12 , 0444 , V_4 -> V_47 ,
& V_57 , V_49 ) ;
# ifdef F_5
F_55 ( L_13 , 0444 , V_4 -> V_47 ,
& V_58 , V_49 ) ;
F_55 ( L_14 , 0444 , V_4 -> V_47 ,
& V_59 , V_49 ) ;
# endif
#endif
F_55 ( L_15 , 0444 , V_4 -> V_47 ,
& V_60 , ( void * ) ( long ) V_27 ) ;
V_53:
F_56 ( & V_48 ) ;
}
void F_57 ( unsigned int V_27 , struct V_3 * V_4 )
{
char V_45 [ V_46 ] ;
if ( ! V_50 || ! V_4 -> V_47 )
return;
#ifdef F_54
F_58 ( L_9 , V_4 -> V_47 ) ;
F_58 ( L_10 , V_4 -> V_47 ) ;
F_58 ( L_11 , V_4 -> V_47 ) ;
F_58 ( L_12 , V_4 -> V_47 ) ;
# ifdef F_5
F_58 ( L_13 , V_4 -> V_47 ) ;
F_58 ( L_14 , V_4 -> V_47 ) ;
# endif
#endif
F_58 ( L_15 , V_4 -> V_47 ) ;
sprintf ( V_45 , L_16 , V_27 ) ;
F_58 ( V_45 , V_50 ) ;
}
void F_59 ( unsigned int V_27 , struct V_41 * V_43 )
{
F_60 ( V_43 -> V_47 ) ;
}
static void F_61 ( void )
{
#ifdef F_54
F_62 ( L_17 , 0644 , NULL ,
& V_61 ) ;
#endif
}
void F_63 ( void )
{
unsigned int V_27 ;
struct V_3 * V_4 ;
V_50 = F_50 ( L_18 , NULL ) ;
if ( ! V_50 )
return;
F_61 () ;
F_64 (irq, desc)
F_51 ( V_27 , V_4 ) ;
}
int __weak F_65 ( struct V_1 * V_62 , int V_63 )
{
return 0 ;
}
int F_66 ( struct V_1 * V_62 , void * V_17 )
{
static int V_63 ;
unsigned long V_18 , V_64 = 0 ;
int V_65 = * ( T_5 * ) V_17 , V_66 ;
struct V_41 * V_43 ;
struct V_3 * V_4 ;
if ( V_65 > V_67 )
return 0 ;
if ( V_65 == V_67 )
return F_65 ( V_62 , V_63 ) ;
if ( V_65 == 0 ) {
for ( V_63 = 3 , V_66 = 1000 ; V_63 < 10 && V_66 <= V_68 ; ++ V_63 )
V_66 *= 10 ;
F_7 ( V_62 , L_19 , V_63 + 8 , L_20 ) ;
F_67 (j)
F_7 ( V_62 , L_21 , V_66 ) ;
F_68 ( V_62 , '\n' ) ;
}
F_69 () ;
V_4 = F_2 ( V_65 ) ;
if ( ! V_4 )
goto V_69;
F_11 ( & V_4 -> V_21 , V_18 ) ;
F_67 (j)
V_64 |= F_70 ( V_65 , V_66 ) ;
V_43 = V_4 -> V_43 ;
if ( ( ! V_43 || F_71 ( V_4 ) ) && ! V_64 )
goto V_37;
F_7 ( V_62 , L_22 , V_63 , V_65 ) ;
F_67 (j)
F_7 ( V_62 , L_23 , F_70 ( V_65 , V_66 ) ) ;
if ( V_4 -> V_12 . V_51 ) {
if ( V_4 -> V_12 . V_51 -> V_70 )
V_4 -> V_12 . V_51 -> V_70 ( & V_4 -> V_12 , V_62 ) ;
else if ( V_4 -> V_12 . V_51 -> V_45 )
F_7 ( V_62 , L_24 , V_4 -> V_12 . V_51 -> V_45 ) ;
else
F_7 ( V_62 , L_24 , L_25 ) ;
} else {
F_7 ( V_62 , L_24 , L_26 ) ;
}
if ( V_4 -> V_12 . V_71 )
F_7 ( V_62 , L_27 , V_63 , ( int ) V_4 -> V_12 . V_72 ) ;
else
F_7 ( V_62 , L_28 , V_63 , L_20 ) ;
#ifdef F_72
F_7 ( V_62 , L_29 , F_73 ( & V_4 -> V_12 ) ? L_30 : L_31 ) ;
#endif
if ( V_4 -> V_45 )
F_7 ( V_62 , L_32 , V_4 -> V_45 ) ;
if ( V_43 ) {
F_7 ( V_62 , L_33 , V_43 -> V_45 ) ;
while ( ( V_43 = V_43 -> V_73 ) != NULL )
F_7 ( V_62 , L_34 , V_43 -> V_45 ) ;
}
F_68 ( V_62 , '\n' ) ;
V_37:
F_13 ( & V_4 -> V_21 , V_18 ) ;
V_69:
F_74 () ;
return 0 ;
}
