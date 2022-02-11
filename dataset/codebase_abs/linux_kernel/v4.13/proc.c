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
V_7 = V_4 -> V_10 . V_16 ;
break;
#else
return - V_17 ;
#endif
} ;
switch ( type ) {
case V_9 :
case V_15 :
F_6 ( V_2 , L_1 , F_7 ( V_7 ) ) ;
break;
case V_8 :
case V_14 :
F_6 ( V_2 , L_2 , F_7 ( V_7 ) ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_18 )
{
struct V_3 * V_4 = F_2 ( ( long ) V_2 -> V_5 ) ;
unsigned long V_19 ;
T_1 V_7 ;
if ( ! F_9 ( & V_7 , V_20 ) )
return - V_21 ;
F_10 ( & V_4 -> V_22 , V_19 ) ;
if ( V_4 -> V_23 )
F_11 ( V_7 , V_4 -> V_23 ) ;
F_12 ( & V_4 -> V_22 , V_19 ) ;
F_6 ( V_2 , L_2 , F_7 ( V_7 ) ) ;
F_13 ( V_7 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_18 )
{
return F_1 ( V_8 , V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_18 )
{
return F_1 ( V_9 , V_2 ) ;
}
static T_2 F_16 ( int type , struct V_24 * V_24 ,
const char T_3 * V_25 , T_4 V_26 , T_5 * V_27 )
{
unsigned int V_28 = ( int ) ( long ) F_17 ( F_18 ( V_24 ) ) ;
T_1 V_29 ;
int V_30 ;
if ( ! F_19 ( V_28 ) || V_31 )
return - V_32 ;
if ( ! F_20 ( & V_29 , V_20 ) )
return - V_21 ;
if ( type )
V_30 = F_21 ( V_25 , V_26 , V_29 ) ;
else
V_30 = F_22 ( V_25 , V_26 , V_29 ) ;
if ( V_30 )
goto V_33;
if ( ! F_23 ( V_29 ) ) {
V_30 = - V_17 ;
goto V_33;
}
if ( ! F_24 ( V_29 , V_34 ) ) {
V_30 = F_25 ( V_28 ) ? - V_17 : V_26 ;
} else {
F_26 ( V_28 , V_29 ) ;
V_30 = V_26 ;
}
V_33:
F_13 ( V_29 ) ;
return V_30 ;
}
static T_2 F_27 ( struct V_24 * V_24 ,
const char T_3 * V_25 , T_4 V_26 , T_5 * V_27 )
{
return F_16 ( 0 , V_24 , V_25 , V_26 , V_27 ) ;
}
static T_2 F_28 ( struct V_24 * V_24 ,
const char T_3 * V_25 , T_4 V_26 , T_5 * V_27 )
{
return F_16 ( 1 , V_24 , V_25 , V_26 , V_27 ) ;
}
static int F_29 ( struct V_35 * V_35 , struct V_24 * V_24 )
{
return F_30 ( V_24 , F_14 , F_17 ( V_35 ) ) ;
}
static int F_31 ( struct V_35 * V_35 , struct V_24 * V_24 )
{
return F_30 ( V_24 , F_15 , F_17 ( V_35 ) ) ;
}
static int F_32 ( struct V_35 * V_35 , struct V_24 * V_24 )
{
return F_30 ( V_24 , F_8 , F_17 ( V_35 ) ) ;
}
static int F_33 ( struct V_1 * V_2 , void * V_18 )
{
return F_1 ( V_14 , V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 , void * V_18 )
{
return F_1 ( V_15 , V_2 ) ;
}
static int F_35 ( struct V_35 * V_35 , struct V_24 * V_24 )
{
return F_30 ( V_24 , F_33 , F_17 ( V_35 ) ) ;
}
static int F_36 ( struct V_35 * V_35 ,
struct V_24 * V_24 )
{
return F_30 ( V_24 , F_34 ,
F_17 ( V_35 ) ) ;
}
static int F_37 ( struct V_1 * V_2 , void * V_18 )
{
F_6 ( V_2 , L_2 , F_7 ( V_36 ) ) ;
return 0 ;
}
static T_2 F_38 ( struct V_24 * V_24 ,
const char T_3 * V_25 , T_4 V_26 , T_5 * V_37 )
{
T_1 V_29 ;
int V_30 ;
if ( ! F_20 ( & V_29 , V_20 ) )
return - V_21 ;
V_30 = F_22 ( V_25 , V_26 , V_29 ) ;
if ( V_30 )
goto V_38;
if ( ! F_23 ( V_29 ) ) {
V_30 = - V_17 ;
goto V_38;
}
if ( ! F_24 ( V_29 , V_34 ) ) {
V_30 = - V_17 ;
goto V_38;
}
F_11 ( V_36 , V_29 ) ;
V_30 = V_26 ;
V_38:
F_13 ( V_29 ) ;
return V_30 ;
}
static int F_39 ( struct V_35 * V_35 , struct V_24 * V_24 )
{
return F_30 ( V_24 , F_37 , F_17 ( V_35 ) ) ;
}
static int F_40 ( struct V_1 * V_2 , void * V_18 )
{
struct V_3 * V_4 = F_2 ( ( long ) V_2 -> V_5 ) ;
F_6 ( V_2 , L_3 , F_41 ( V_4 ) ) ;
return 0 ;
}
static int F_42 ( struct V_35 * V_35 , struct V_24 * V_24 )
{
return F_30 ( V_24 , F_40 , F_17 ( V_35 ) ) ;
}
static int F_43 ( struct V_1 * V_2 , void * V_18 )
{
struct V_3 * V_4 = F_2 ( ( long ) V_2 -> V_5 ) ;
F_6 ( V_2 , L_4 L_5 L_6 ,
V_4 -> V_39 , V_4 -> V_40 ,
F_44 ( V_4 -> V_41 ) ) ;
return 0 ;
}
static int F_45 ( struct V_35 * V_35 , struct V_24 * V_24 )
{
return F_30 ( V_24 , F_43 , F_17 ( V_35 ) ) ;
}
static int F_46 ( unsigned int V_28 , struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_28 ) ;
struct V_42 * V_44 ;
unsigned long V_19 ;
int V_45 = 1 ;
F_10 ( & V_4 -> V_22 , V_19 ) ;
F_47 (desc, action) {
if ( ( V_44 != V_43 ) && V_44 -> V_46 &&
! strcmp ( V_43 -> V_46 , V_44 -> V_46 ) ) {
V_45 = 0 ;
break;
}
}
F_12 ( & V_4 -> V_22 , V_19 ) ;
return V_45 ;
}
void F_48 ( unsigned int V_28 , struct V_42 * V_44 )
{
char V_46 [ V_47 ] ;
struct V_3 * V_4 = F_2 ( V_28 ) ;
if ( ! V_4 -> V_48 || V_44 -> V_48 || ! V_44 -> V_46 ||
! F_46 ( V_28 , V_44 ) )
return;
snprintf ( V_46 , V_47 , L_7 , V_44 -> V_46 ) ;
V_44 -> V_48 = F_49 ( V_46 , V_4 -> V_48 ) ;
}
void F_50 ( unsigned int V_28 , struct V_3 * V_4 )
{
static F_51 ( V_49 ) ;
void T_6 * V_50 = ( void * ) ( unsigned long ) V_28 ;
char V_46 [ V_47 ] ;
if ( ! V_51 || ( V_4 -> V_12 . V_52 == & V_53 ) )
return;
F_52 ( & V_49 ) ;
if ( V_4 -> V_48 )
goto V_54;
sprintf ( V_46 , L_8 , V_28 ) ;
V_4 -> V_48 = F_49 ( V_46 , V_51 ) ;
if ( ! V_4 -> V_48 )
goto V_54;
#ifdef F_53
F_54 ( L_9 , 0644 , V_4 -> V_48 ,
& V_55 , V_50 ) ;
F_54 ( L_10 , 0444 , V_4 -> V_48 ,
& V_56 , V_50 ) ;
F_54 ( L_11 , 0644 , V_4 -> V_48 ,
& V_57 , V_50 ) ;
F_54 ( L_12 , 0444 , V_4 -> V_48 ,
& V_58 , V_50 ) ;
# ifdef F_5
F_54 ( L_13 , 0444 , V_4 -> V_48 ,
& V_59 , V_50 ) ;
F_54 ( L_14 , 0444 , V_4 -> V_48 ,
& V_60 , V_50 ) ;
# endif
#endif
F_54 ( L_15 , 0444 , V_4 -> V_48 ,
& V_61 , ( void * ) ( long ) V_28 ) ;
V_54:
F_55 ( & V_49 ) ;
}
void F_56 ( unsigned int V_28 , struct V_3 * V_4 )
{
char V_46 [ V_47 ] ;
if ( ! V_51 || ! V_4 -> V_48 )
return;
#ifdef F_53
F_57 ( L_9 , V_4 -> V_48 ) ;
F_57 ( L_10 , V_4 -> V_48 ) ;
F_57 ( L_11 , V_4 -> V_48 ) ;
F_57 ( L_12 , V_4 -> V_48 ) ;
# ifdef F_5
F_57 ( L_13 , V_4 -> V_48 ) ;
F_57 ( L_14 , V_4 -> V_48 ) ;
# endif
#endif
F_57 ( L_15 , V_4 -> V_48 ) ;
sprintf ( V_46 , L_16 , V_28 ) ;
F_57 ( V_46 , V_51 ) ;
}
void F_58 ( unsigned int V_28 , struct V_42 * V_44 )
{
F_59 ( V_44 -> V_48 ) ;
}
static void F_60 ( void )
{
#ifdef F_53
F_61 ( L_17 , 0644 , NULL ,
& V_62 ) ;
#endif
}
void F_62 ( void )
{
unsigned int V_28 ;
struct V_3 * V_4 ;
V_51 = F_49 ( L_18 , NULL ) ;
if ( ! V_51 )
return;
F_60 () ;
F_63 (irq, desc)
F_50 ( V_28 , V_4 ) ;
}
int __weak F_64 ( struct V_1 * V_63 , int V_64 )
{
return 0 ;
}
int F_65 ( struct V_1 * V_63 , void * V_18 )
{
static int V_64 ;
unsigned long V_19 , V_65 = 0 ;
int V_66 = * ( T_5 * ) V_18 , V_67 ;
struct V_42 * V_44 ;
struct V_3 * V_4 ;
if ( V_66 > V_68 )
return 0 ;
if ( V_66 == V_68 )
return F_64 ( V_63 , V_64 ) ;
if ( V_66 == 0 ) {
for ( V_64 = 3 , V_67 = 1000 ; V_64 < 10 && V_67 <= V_69 ; ++ V_64 )
V_67 *= 10 ;
F_6 ( V_63 , L_19 , V_64 + 8 , L_20 ) ;
F_66 (j)
F_6 ( V_63 , L_21 , V_67 ) ;
F_67 ( V_63 , '\n' ) ;
}
F_68 () ;
V_4 = F_2 ( V_66 ) ;
if ( ! V_4 )
goto V_70;
F_10 ( & V_4 -> V_22 , V_19 ) ;
F_66 (j)
V_65 |= F_69 ( V_66 , V_67 ) ;
V_44 = V_4 -> V_44 ;
if ( ( ! V_44 || F_70 ( V_4 ) ) && ! V_65 )
goto V_38;
F_6 ( V_63 , L_22 , V_64 , V_66 ) ;
F_66 (j)
F_6 ( V_63 , L_23 , F_69 ( V_66 , V_67 ) ) ;
if ( V_4 -> V_12 . V_52 ) {
if ( V_4 -> V_12 . V_52 -> V_71 )
V_4 -> V_12 . V_52 -> V_71 ( & V_4 -> V_12 , V_63 ) ;
else if ( V_4 -> V_12 . V_52 -> V_46 )
F_6 ( V_63 , L_24 , V_4 -> V_12 . V_52 -> V_46 ) ;
else
F_6 ( V_63 , L_24 , L_25 ) ;
} else {
F_6 ( V_63 , L_24 , L_26 ) ;
}
if ( V_4 -> V_12 . V_72 )
F_6 ( V_63 , L_27 , V_64 , ( int ) V_4 -> V_12 . V_73 ) ;
else
F_6 ( V_63 , L_28 , V_64 , L_20 ) ;
#ifdef F_71
F_6 ( V_63 , L_29 , F_72 ( & V_4 -> V_12 ) ? L_30 : L_31 ) ;
#endif
if ( V_4 -> V_46 )
F_6 ( V_63 , L_32 , V_4 -> V_46 ) ;
if ( V_44 ) {
F_6 ( V_63 , L_33 , V_44 -> V_46 ) ;
while ( ( V_44 = V_44 -> V_74 ) != NULL )
F_6 ( V_63 , L_34 , V_44 -> V_46 ) ;
}
F_67 ( V_63 , '\n' ) ;
V_38:
F_12 ( & V_4 -> V_22 , V_19 ) ;
V_70:
F_73 () ;
return 0 ;
}
