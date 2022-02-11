static inline void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
#ifdef F_2
V_2 -> V_3 = V_3 ;
#endif
}
static int F_3 ( const struct V_1 * V_4 )
{
return V_4 - & V_4 -> V_5 -> V_4 [ 0 ] ;
}
static struct V_1 * F_4 ( unsigned V_6 )
{
if ( F_5 ( ! F_6 ( V_6 ) , L_1 , V_6 ) )
return NULL ;
else
return & V_1 [ V_6 ] ;
}
static int F_7 ( const struct V_1 * V_4 )
{
return V_4 - & V_1 [ 0 ] ;
}
static int F_8 ( struct V_1 * V_4 )
{
const struct V_7 * V_5 = V_4 -> V_5 ;
const int V_6 = F_7 ( V_4 ) ;
if ( F_5 ( F_9 ( V_8 , & V_4 -> V_9 ) == 0 ,
L_2 , V_6 ) ) {
if ( ! F_10 ( V_5 -> V_10 ) ) {
F_11 ( L_3 , V_6 ) ;
F_12 ( V_8 , & V_4 -> V_9 ) ;
return - V_11 ;
}
F_1 ( V_4 , L_4 ) ;
if ( V_5 -> V_12 )
return 1 ;
}
return 0 ;
}
static struct V_7 * F_13 ( const struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_5 : NULL ;
}
struct V_7 * F_14 ( unsigned V_6 )
{
return F_13 ( F_4 ( V_6 ) ) ;
}
static int F_15 ( int V_13 )
{
struct V_7 * V_5 ;
int V_14 = V_15 - V_13 ;
F_16 (chip, &gpio_chips, list) {
if ( V_5 -> V_14 + V_5 -> V_13 <= V_14 )
break;
else
V_14 = V_5 -> V_14 - V_13 ;
}
if ( F_6 ( V_14 ) ) {
F_17 ( L_5 , V_16 , V_14 ) ;
return V_14 ;
} else {
F_11 ( L_6 , V_16 ) ;
return - V_17 ;
}
}
static int F_18 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
unsigned V_18 ;
int V_19 = - V_20 ;
V_5 = F_13 ( V_4 ) ;
V_18 = F_3 ( V_4 ) ;
if ( ! V_5 -> V_21 )
return V_19 ;
V_19 = V_5 -> V_21 ( V_5 , V_18 ) ;
if ( V_19 > 0 ) {
V_19 = 1 ;
F_12 ( V_22 , & ( (struct V_1 * ) V_4 ) -> V_9 ) ;
}
if ( V_19 == 0 ) {
F_19 ( V_22 , & ( (struct V_1 * ) V_4 ) -> V_9 ) ;
}
return V_19 ;
}
static T_1 F_20 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) ) {
V_19 = - V_11 ;
} else {
F_18 ( V_4 ) ;
V_19 = sprintf ( V_27 , L_7 ,
F_23 ( V_22 , & V_4 -> V_9 )
? L_8 : L_9 ) ;
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_25 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) )
V_19 = - V_11 ;
else if ( F_26 ( V_27 , L_10 ) )
V_19 = F_27 ( V_4 , 1 ) ;
else if ( F_26 ( V_27 , L_8 ) || F_26 ( V_27 , L_11 ) )
V_19 = F_27 ( V_4 , 0 ) ;
else if ( F_26 ( V_27 , L_9 ) )
V_19 = F_28 ( V_4 ) ;
else
V_19 = - V_20 ;
F_24 ( & V_28 ) ;
return V_19 ? : V_30 ;
}
static T_1 F_29 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) ) {
V_19 = - V_11 ;
} else {
int V_31 ;
V_31 = ! ! F_30 ( V_4 ) ;
if ( F_23 ( V_32 , & V_4 -> V_9 ) )
V_31 = ! V_31 ;
V_19 = sprintf ( V_27 , L_12 , V_31 ) ;
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_31 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) )
V_19 = - V_11 ;
else if ( ! F_23 ( V_22 , & V_4 -> V_9 ) )
V_19 = - V_33 ;
else {
long V_31 ;
V_19 = F_32 ( V_27 , 0 , & V_31 ) ;
if ( V_19 == 0 ) {
if ( F_23 ( V_32 , & V_4 -> V_9 ) )
V_31 = ! V_31 ;
F_33 ( V_4 , V_31 != 0 ) ;
V_19 = V_30 ;
}
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_3 F_34 ( int V_34 , void * V_35 )
{
struct V_36 * V_37 = V_35 ;
F_35 ( V_37 ) ;
return V_38 ;
}
static int F_36 ( struct V_1 * V_4 , struct V_23 * V_24 ,
unsigned long V_39 )
{
struct V_36 * V_37 ;
unsigned long V_40 ;
int V_41 , V_34 , V_42 ;
if ( ( V_4 -> V_9 & V_43 ) == V_39 )
return 0 ;
V_34 = F_37 ( V_4 ) ;
if ( V_34 < 0 )
return - V_11 ;
V_42 = V_4 -> V_9 >> V_44 ;
V_37 = F_38 ( & V_45 , V_42 ) ;
if ( V_37 )
F_39 ( V_34 , V_37 ) ;
V_4 -> V_9 &= ~ V_43 ;
if ( ! V_39 ) {
V_41 = 0 ;
goto V_46;
}
V_40 = V_47 ;
if ( F_23 ( V_48 , & V_39 ) )
V_40 |= F_23 ( V_32 , & V_4 -> V_9 ) ?
V_49 : V_50 ;
if ( F_23 ( V_51 , & V_39 ) )
V_40 |= F_23 ( V_32 , & V_4 -> V_9 ) ?
V_50 : V_49 ;
if ( ! V_37 ) {
V_37 = F_40 ( V_24 -> V_52 . V_53 , NULL , L_13 ) ;
if ( ! V_37 ) {
V_41 = - V_54 ;
goto V_55;
}
V_41 = F_41 ( & V_45 , V_37 , 1 , 0 , V_56 ) ;
if ( V_41 < 0 )
goto V_57;
V_42 = V_41 ;
V_4 -> V_9 &= V_58 ;
V_4 -> V_9 |= ( unsigned long ) V_42 << V_44 ;
if ( V_4 -> V_9 >> V_44 != V_42 ) {
V_41 = - V_59 ;
goto V_46;
}
}
V_41 = F_42 ( V_34 , F_34 , V_40 ,
L_14 , V_37 ) ;
if ( V_41 < 0 )
goto V_46;
V_4 -> V_9 |= V_39 ;
return 0 ;
V_46:
F_43 ( & V_45 , V_42 ) ;
V_4 -> V_9 &= V_58 ;
V_57:
if ( V_37 )
F_44 ( V_37 ) ;
V_55:
return V_41 ;
}
static T_1 F_45 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) )
V_19 = - V_11 ;
else {
int V_60 ;
V_19 = 0 ;
for ( V_60 = 0 ; V_60 < F_46 ( V_61 ) ; V_60 ++ )
if ( ( V_4 -> V_9 & V_43 )
== V_61 [ V_60 ] . V_9 ) {
V_19 = sprintf ( V_27 , L_7 ,
V_61 [ V_60 ] . V_62 ) ;
break;
}
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_47 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < F_46 ( V_61 ) ; V_60 ++ )
if ( F_26 ( V_61 [ V_60 ] . V_62 , V_27 ) )
goto V_63;
return - V_20 ;
V_63:
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) )
V_19 = - V_11 ;
else {
V_19 = F_36 ( V_4 , V_24 , V_61 [ V_60 ] . V_9 ) ;
if ( ! V_19 )
V_19 = V_30 ;
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static int F_48 ( struct V_1 * V_4 , struct V_23 * V_24 ,
int V_31 )
{
int V_19 = 0 ;
if ( ! ! F_23 ( V_32 , & V_4 -> V_9 ) == ! ! V_31 )
return 0 ;
if ( V_31 )
F_19 ( V_32 , & V_4 -> V_9 ) ;
else
F_12 ( V_32 , & V_4 -> V_9 ) ;
if ( V_24 != NULL && ( ! ! F_23 ( V_51 , & V_4 -> V_9 ) ^
! ! F_23 ( V_48 , & V_4 -> V_9 ) ) ) {
unsigned long V_64 = V_4 -> V_9 & V_43 ;
F_36 ( V_4 , V_24 , 0 ) ;
V_19 = F_36 ( V_4 , V_24 , V_64 ) ;
}
return V_19 ;
}
static T_1 F_49 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) )
V_19 = - V_11 ;
else
V_19 = sprintf ( V_27 , L_12 ,
! ! F_23 ( V_32 , & V_4 -> V_9 ) ) ;
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_50 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_9 ) ) {
V_19 = - V_11 ;
} else {
long V_31 ;
V_19 = F_32 ( V_27 , 0 , & V_31 ) ;
if ( V_19 == 0 )
V_19 = F_48 ( V_4 , V_24 , V_31 != 0 ) ;
}
F_24 ( & V_28 ) ;
return V_19 ? : V_30 ;
}
static T_1 F_51 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_21 ( V_24 ) ;
return sprintf ( V_27 , L_12 , V_5 -> V_14 ) ;
}
static T_1 F_52 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_21 ( V_24 ) ;
return sprintf ( V_27 , L_7 , V_5 -> V_3 ? : L_15 ) ;
}
static T_1 F_53 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_21 ( V_24 ) ;
return sprintf ( V_27 , L_16 , V_5 -> V_13 ) ;
}
static T_1 F_54 ( struct V_65 * V_65 ,
struct V_66 * V_26 ,
const char * V_27 , T_2 V_67 )
{
long V_6 ;
struct V_1 * V_4 ;
int V_19 ;
V_19 = F_32 ( V_27 , 0 , & V_6 ) ;
if ( V_19 < 0 )
goto V_68;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
F_55 ( L_17 , V_16 , V_6 ) ;
return - V_20 ;
}
V_19 = F_56 ( V_4 , L_18 ) ;
if ( V_19 < 0 ) {
if ( V_19 == - V_69 )
V_19 = - V_54 ;
goto V_68;
}
V_19 = F_57 ( V_4 , true ) ;
if ( V_19 < 0 )
F_58 ( V_4 ) ;
else
F_19 ( V_70 , & V_4 -> V_9 ) ;
V_68:
if ( V_19 )
F_17 ( L_19 , V_16 , V_19 ) ;
return V_19 ? : V_67 ;
}
static T_1 F_59 ( struct V_65 * V_65 ,
struct V_66 * V_26 ,
const char * V_27 , T_2 V_67 )
{
long V_6 ;
struct V_1 * V_4 ;
int V_19 ;
V_19 = F_32 ( V_27 , 0 , & V_6 ) ;
if ( V_19 < 0 )
goto V_68;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
F_55 ( L_17 , V_16 , V_6 ) ;
return - V_20 ;
}
V_19 = - V_20 ;
if ( F_60 ( V_70 , & V_4 -> V_9 ) ) {
V_19 = 0 ;
F_58 ( V_4 ) ;
}
V_68:
if ( V_19 )
F_17 ( L_19 , V_16 , V_19 ) ;
return V_19 ? : V_67 ;
}
static int F_57 ( struct V_1 * V_4 , bool V_71 )
{
unsigned long V_9 ;
int V_19 ;
const char * V_72 = NULL ;
struct V_23 * V_24 ;
int V_18 ;
if ( ! V_73 . V_74 ) {
F_17 ( L_20 , V_16 ) ;
return - V_75 ;
}
if ( ! V_4 ) {
F_17 ( L_21 , V_16 ) ;
return - V_20 ;
}
F_22 ( & V_28 ) ;
F_61 ( & V_76 , V_9 ) ;
if ( ! F_23 ( V_8 , & V_4 -> V_9 ) ||
F_23 ( V_29 , & V_4 -> V_9 ) ) {
F_62 ( & V_76 , V_9 ) ;
F_17 ( L_22 ,
V_16 , F_7 ( V_4 ) ,
F_23 ( V_8 , & V_4 -> V_9 ) ,
F_23 ( V_29 , & V_4 -> V_9 ) ) ;
V_19 = - V_33 ;
goto V_77;
}
if ( ! V_4 -> V_5 -> V_78 || ! V_4 -> V_5 -> V_79 )
V_71 = false ;
F_62 ( & V_76 , V_9 ) ;
V_18 = F_3 ( V_4 ) ;
if ( V_4 -> V_5 -> V_80 && V_4 -> V_5 -> V_80 [ V_18 ] )
V_72 = V_4 -> V_5 -> V_80 [ V_18 ] ;
V_24 = F_63 ( & V_73 , V_4 -> V_5 -> V_24 , F_64 ( 0 , 0 ) ,
V_4 , V_72 ? V_72 : L_23 ,
F_7 ( V_4 ) ) ;
if ( F_65 ( V_24 ) ) {
V_19 = F_66 ( V_24 ) ;
goto V_77;
}
V_19 = F_67 ( & V_24 -> V_52 , & V_81 ) ;
if ( V_19 )
goto V_82;
if ( V_71 ) {
V_19 = F_68 ( V_24 , & V_83 ) ;
if ( V_19 )
goto V_82;
}
if ( F_37 ( V_4 ) >= 0 && ( V_71 ||
! F_23 ( V_22 , & V_4 -> V_9 ) ) ) {
V_19 = F_68 ( V_24 , & V_84 ) ;
if ( V_19 )
goto V_82;
}
F_19 ( V_29 , & V_4 -> V_9 ) ;
F_24 ( & V_28 ) ;
return 0 ;
V_82:
F_69 ( V_24 ) ;
V_77:
F_24 ( & V_28 ) ;
F_17 ( L_24 , V_16 , F_7 ( V_4 ) ,
V_19 ) ;
return V_19 ;
}
int F_70 ( unsigned V_6 , bool V_71 )
{
return F_57 ( F_4 ( V_6 ) , V_71 ) ;
}
static int F_71 ( struct V_23 * V_24 , const void * V_85 )
{
return F_21 ( V_24 ) == V_85 ;
}
static int F_72 ( struct V_23 * V_24 , const char * V_62 ,
struct V_1 * V_4 )
{
int V_19 = - V_20 ;
if ( ! V_4 ) {
F_55 ( L_25 , V_16 ) ;
return - V_20 ;
}
F_22 ( & V_28 ) ;
if ( F_23 ( V_29 , & V_4 -> V_9 ) ) {
struct V_23 * V_86 ;
V_86 = F_73 ( & V_73 , NULL , V_4 , F_71 ) ;
if ( V_86 != NULL ) {
V_19 = F_74 ( & V_24 -> V_52 , & V_86 -> V_52 ,
V_62 ) ;
} else {
V_19 = - V_54 ;
}
}
F_24 ( & V_28 ) ;
if ( V_19 )
F_17 ( L_24 , V_16 , F_7 ( V_4 ) ,
V_19 ) ;
return V_19 ;
}
int F_75 ( struct V_23 * V_24 , const char * V_62 , unsigned V_6 )
{
return F_72 ( V_24 , V_62 , F_4 ( V_6 ) ) ;
}
static int F_76 ( struct V_1 * V_4 , int V_31 )
{
struct V_23 * V_24 = NULL ;
int V_19 = - V_20 ;
if ( ! V_4 ) {
F_55 ( L_25 , V_16 ) ;
return - V_20 ;
}
F_22 ( & V_28 ) ;
if ( F_23 ( V_29 , & V_4 -> V_9 ) ) {
V_24 = F_73 ( & V_73 , NULL , V_4 , F_71 ) ;
if ( V_24 == NULL ) {
V_19 = - V_54 ;
goto V_87;
}
}
V_19 = F_48 ( V_4 , V_24 , V_31 ) ;
V_87:
F_24 ( & V_28 ) ;
if ( V_19 )
F_17 ( L_24 , V_16 , F_7 ( V_4 ) ,
V_19 ) ;
return V_19 ;
}
int F_77 ( unsigned V_6 , int V_31 )
{
return F_76 ( F_4 ( V_6 ) , V_31 ) ;
}
static void F_78 ( struct V_1 * V_4 )
{
int V_19 = 0 ;
struct V_23 * V_24 = NULL ;
if ( ! V_4 ) {
F_55 ( L_25 , V_16 ) ;
return;
}
F_22 ( & V_28 ) ;
if ( F_23 ( V_29 , & V_4 -> V_9 ) ) {
V_24 = F_73 ( & V_73 , NULL , V_4 , F_71 ) ;
if ( V_24 ) {
F_36 ( V_4 , V_24 , 0 ) ;
F_12 ( V_29 , & V_4 -> V_9 ) ;
} else
V_19 = - V_54 ;
}
F_24 ( & V_28 ) ;
if ( V_24 ) {
F_69 ( V_24 ) ;
F_79 ( V_24 ) ;
}
if ( V_19 )
F_17 ( L_24 , V_16 , F_7 ( V_4 ) ,
V_19 ) ;
}
void F_80 ( unsigned V_6 )
{
F_78 ( F_4 ( V_6 ) ) ;
}
static int F_81 ( struct V_7 * V_5 )
{
int V_19 ;
struct V_23 * V_24 ;
if ( ! V_73 . V_74 )
return 0 ;
F_22 ( & V_28 ) ;
V_24 = F_63 ( & V_73 , V_5 -> V_24 , F_64 ( 0 , 0 ) , V_5 ,
L_26 , V_5 -> V_14 ) ;
if ( ! F_65 ( V_24 ) ) {
V_19 = F_67 ( & V_24 -> V_52 ,
& V_88 ) ;
} else
V_19 = F_66 ( V_24 ) ;
V_5 -> V_89 = ( V_19 == 0 ) ;
F_24 ( & V_28 ) ;
if ( V_19 ) {
unsigned long V_9 ;
unsigned V_6 ;
F_61 ( & V_76 , V_9 ) ;
V_6 = 0 ;
while ( V_6 < V_5 -> V_13 )
V_5 -> V_4 [ V_6 ++ ] . V_5 = NULL ;
F_62 ( & V_76 , V_9 ) ;
F_17 ( L_27 , V_16 ,
V_5 -> V_3 , V_19 ) ;
}
return V_19 ;
}
static void F_82 ( struct V_7 * V_5 )
{
int V_19 ;
struct V_23 * V_24 ;
F_22 ( & V_28 ) ;
V_24 = F_73 ( & V_73 , NULL , V_5 , F_71 ) ;
if ( V_24 ) {
F_79 ( V_24 ) ;
F_69 ( V_24 ) ;
V_5 -> V_89 = 0 ;
V_19 = 0 ;
} else
V_19 = - V_54 ;
F_24 ( & V_28 ) ;
if ( V_19 )
F_17 ( L_27 , V_16 ,
V_5 -> V_3 , V_19 ) ;
}
static int T_4 F_83 ( void )
{
int V_19 ;
unsigned long V_9 ;
struct V_7 * V_5 ;
V_19 = F_84 ( & V_73 ) ;
if ( V_19 < 0 )
return V_19 ;
F_61 ( & V_76 , V_9 ) ;
F_85 (chip, &gpio_chips, list) {
if ( ! V_5 || V_5 -> V_89 )
continue;
F_62 ( & V_76 , V_9 ) ;
V_19 = F_81 ( V_5 ) ;
F_61 ( & V_76 , V_9 ) ;
}
F_62 ( & V_76 , V_9 ) ;
return V_19 ;
}
static inline int F_81 ( struct V_7 * V_5 )
{
return 0 ;
}
static inline void F_82 ( struct V_7 * V_5 )
{
}
static inline int F_57 ( struct V_1 * V_4 ,
bool V_71 )
{
return - V_90 ;
}
static inline int F_72 ( struct V_23 * V_24 , const char * V_62 ,
struct V_1 * V_4 )
{
return - V_90 ;
}
static inline int F_76 ( struct V_1 * V_4 , int V_31 )
{
return - V_90 ;
}
static inline void F_78 ( struct V_1 * V_4 )
{
}
static int F_86 ( struct V_7 * V_5 )
{
struct V_91 * V_92 = & V_93 ;
struct V_7 * V_94 ;
int V_95 = 0 ;
F_87 (pos, &gpio_chips) {
V_94 = F_88 ( V_92 , struct V_7 , V_96 ) ;
if ( V_94 -> V_14 >= V_5 -> V_14 + V_5 -> V_13 )
break;
}
if ( V_92 != & V_93 && V_92 -> V_97 != & V_93 ) {
V_94 = F_88 ( V_92 -> V_97 , struct V_7 , V_96 ) ;
if ( V_94 -> V_14 + V_94 -> V_13 > V_5 -> V_14 ) {
F_89 ( V_5 -> V_24 ,
L_28 ) ;
V_95 = - V_98 ;
}
}
if ( ! V_95 )
F_90 ( & V_5 -> V_96 , V_92 ) ;
return V_95 ;
}
int F_91 ( struct V_7 * V_5 )
{
unsigned long V_9 ;
int V_19 = 0 ;
unsigned V_42 ;
int V_14 = V_5 -> V_14 ;
if ( ( ! F_6 ( V_14 ) || ! F_6 ( V_14 + V_5 -> V_13 - 1 ) )
&& V_14 >= 0 ) {
V_19 = - V_20 ;
goto V_99;
}
F_61 ( & V_76 , V_9 ) ;
if ( V_14 < 0 ) {
V_14 = F_15 ( V_5 -> V_13 ) ;
if ( V_14 < 0 ) {
V_19 = V_14 ;
goto V_87;
}
V_5 -> V_14 = V_14 ;
}
V_19 = F_86 ( V_5 ) ;
if ( V_19 == 0 ) {
V_5 -> V_4 = & V_1 [ V_5 -> V_14 ] ;
for ( V_42 = 0 ; V_42 < V_5 -> V_13 ; V_42 ++ ) {
struct V_1 * V_4 = & V_5 -> V_4 [ V_42 ] ;
V_4 -> V_5 = V_5 ;
V_4 -> V_9 = ! V_5 -> V_78
? ( 1 << V_22 )
: 0 ;
}
}
F_62 ( & V_76 , V_9 ) ;
#ifdef F_92
F_93 ( & V_5 -> V_100 ) ;
#endif
F_94 ( V_5 ) ;
if ( V_19 )
goto V_99;
V_19 = F_81 ( V_5 ) ;
if ( V_19 )
goto V_99;
F_17 ( L_29 ,
V_5 -> V_14 , V_5 -> V_14 + V_5 -> V_13 - 1 ,
V_5 -> V_3 ? : L_30 ) ;
return 0 ;
V_87:
F_62 ( & V_76 , V_9 ) ;
V_99:
F_11 ( L_31 ,
V_5 -> V_14 , V_5 -> V_14 + V_5 -> V_13 - 1 ,
V_5 -> V_3 ? : L_30 ) ;
return V_19 ;
}
int F_95 ( struct V_7 * V_5 )
{
unsigned long V_9 ;
int V_19 = 0 ;
unsigned V_42 ;
F_61 ( & V_76 , V_9 ) ;
F_96 ( V_5 ) ;
F_97 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_13 ; V_42 ++ ) {
if ( F_23 ( V_8 , & V_5 -> V_4 [ V_42 ] . V_9 ) ) {
V_19 = - V_98 ;
break;
}
}
if ( V_19 == 0 ) {
for ( V_42 = 0 ; V_42 < V_5 -> V_13 ; V_42 ++ )
V_5 -> V_4 [ V_42 ] . V_5 = NULL ;
F_98 ( & V_5 -> V_96 ) ;
}
F_62 ( & V_76 , V_9 ) ;
if ( V_19 == 0 )
F_82 ( V_5 ) ;
return V_19 ;
}
struct V_7 * F_99 ( void * V_85 ,
int (* F_100)( struct V_7 * V_5 ,
void * V_85 ) )
{
struct V_7 * V_5 ;
unsigned long V_9 ;
F_61 ( & V_76 , V_9 ) ;
F_85 (chip, &gpio_chips, list)
if ( F_100 ( V_5 , V_85 ) )
break;
if ( & V_5 -> V_96 == & V_93 )
V_5 = NULL ;
F_62 ( & V_76 , V_9 ) ;
return V_5 ;
}
int F_101 ( struct V_7 * V_5 , const char * V_101 ,
unsigned int V_102 , unsigned int V_103 ,
unsigned int V_104 )
{
struct V_105 * V_106 ;
int V_41 ;
V_106 = F_102 ( sizeof( * V_106 ) , V_56 ) ;
if ( ! V_106 ) {
F_11 ( L_32 ,
V_5 -> V_3 ) ;
return - V_107 ;
}
V_106 -> V_108 . V_42 = V_102 ;
V_106 -> V_108 . V_109 = V_5 ;
V_106 -> V_108 . V_62 = V_5 -> V_3 ;
V_106 -> V_108 . V_14 = V_5 -> V_14 + V_102 ;
V_106 -> V_108 . V_110 = V_103 ;
V_106 -> V_108 . V_104 = V_104 ;
V_106 -> V_111 = F_103 ( V_101 ,
& V_106 -> V_108 ) ;
if ( F_65 ( V_106 -> V_111 ) ) {
V_41 = F_66 ( V_106 -> V_111 ) ;
F_11 ( L_33 ,
V_5 -> V_3 ) ;
F_104 ( V_106 ) ;
return V_41 ;
}
F_17 ( L_34 ,
V_5 -> V_3 , V_102 , V_102 + V_104 - 1 ,
V_101 ,
V_103 , V_103 + V_104 - 1 ) ;
F_90 ( & V_106 -> V_112 , & V_5 -> V_100 ) ;
return 0 ;
}
void F_96 ( struct V_7 * V_5 )
{
struct V_105 * V_106 , * V_113 ;
F_105 (pin_range, tmp, &chip->pin_ranges, node) {
F_98 ( & V_106 -> V_112 ) ;
F_106 ( V_106 -> V_111 ,
& V_106 -> V_108 ) ;
F_104 ( V_106 ) ;
}
}
static int F_56 ( struct V_1 * V_4 , const char * V_3 )
{
struct V_7 * V_5 ;
int V_19 = - V_69 ;
unsigned long V_9 ;
if ( ! V_4 ) {
F_55 ( L_25 , V_16 ) ;
return - V_20 ;
}
F_61 ( & V_76 , V_9 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 == NULL )
goto V_68;
if ( ! F_10 ( V_5 -> V_10 ) )
goto V_68;
if ( F_9 ( V_8 , & V_4 -> V_9 ) == 0 ) {
F_1 ( V_4 , V_3 ? : L_35 ) ;
V_19 = 0 ;
} else {
V_19 = - V_98 ;
F_107 ( V_5 -> V_10 ) ;
goto V_68;
}
if ( V_5 -> V_12 ) {
F_62 ( & V_76 , V_9 ) ;
V_19 = V_5 -> V_12 ( V_5 , F_3 ( V_4 ) ) ;
F_61 ( & V_76 , V_9 ) ;
if ( V_19 < 0 ) {
F_1 ( V_4 , NULL ) ;
F_107 ( V_5 -> V_10 ) ;
F_12 ( V_8 , & V_4 -> V_9 ) ;
goto V_68;
}
}
if ( V_5 -> V_21 ) {
F_62 ( & V_76 , V_9 ) ;
F_18 ( V_4 ) ;
F_61 ( & V_76 , V_9 ) ;
}
V_68:
if ( V_19 )
F_17 ( L_36 ,
F_7 ( V_4 ) , V_3 ? : L_35 , V_19 ) ;
F_62 ( & V_76 , V_9 ) ;
return V_19 ;
}
int F_108 ( unsigned V_6 , const char * V_3 )
{
return F_56 ( F_4 ( V_6 ) , V_3 ) ;
}
static void F_58 ( struct V_1 * V_4 )
{
unsigned long V_9 ;
struct V_7 * V_5 ;
F_109 () ;
if ( ! V_4 ) {
F_110 ( V_114 ) ;
return;
}
F_78 ( V_4 ) ;
F_61 ( & V_76 , V_9 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 && F_23 ( V_8 , & V_4 -> V_9 ) ) {
if ( V_5 -> free ) {
F_62 ( & V_76 , V_9 ) ;
F_111 ( V_5 -> V_115 ) ;
V_5 -> free ( V_5 , F_3 ( V_4 ) ) ;
F_61 ( & V_76 , V_9 ) ;
}
F_1 ( V_4 , NULL ) ;
F_107 ( V_4 -> V_5 -> V_10 ) ;
F_12 ( V_32 , & V_4 -> V_9 ) ;
F_12 ( V_8 , & V_4 -> V_9 ) ;
F_12 ( V_116 , & V_4 -> V_9 ) ;
F_12 ( V_117 , & V_4 -> V_9 ) ;
} else
F_110 ( V_114 ) ;
F_62 ( & V_76 , V_9 ) ;
}
void F_112 ( unsigned V_6 )
{
F_58 ( F_4 ( V_6 ) ) ;
}
int F_113 ( unsigned V_6 , unsigned long V_9 , const char * V_3 )
{
struct V_1 * V_4 ;
int V_95 ;
V_4 = F_4 ( V_6 ) ;
V_95 = F_56 ( V_4 , V_3 ) ;
if ( V_95 )
return V_95 ;
if ( V_9 & V_118 )
F_19 ( V_116 , & V_4 -> V_9 ) ;
if ( V_9 & V_119 )
F_19 ( V_117 , & V_4 -> V_9 ) ;
if ( V_9 & V_120 )
V_95 = F_28 ( V_4 ) ;
else
V_95 = F_27 ( V_4 ,
( V_9 & V_121 ) ? 1 : 0 ) ;
if ( V_95 )
goto V_122;
if ( V_9 & V_123 ) {
V_95 = F_57 ( V_4 , V_9 & V_124 ) ;
if ( V_95 )
goto V_122;
}
return 0 ;
V_122:
F_58 ( V_4 ) ;
return V_95 ;
}
int F_114 ( const struct V_6 * V_125 , T_2 V_126 )
{
int V_60 , V_95 ;
for ( V_60 = 0 ; V_60 < V_126 ; V_60 ++ , V_125 ++ ) {
V_95 = F_113 ( V_125 -> V_6 , V_125 -> V_9 , V_125 -> V_3 ) ;
if ( V_95 )
goto V_127;
}
return 0 ;
V_127:
while ( V_60 -- )
F_112 ( ( -- V_125 ) -> V_6 ) ;
return V_95 ;
}
void F_115 ( const struct V_6 * V_125 , T_2 V_126 )
{
while ( V_126 -- )
F_112 ( ( V_125 ++ ) -> V_6 ) ;
}
const char * F_116 ( struct V_7 * V_5 , unsigned V_18 )
{
struct V_1 * V_4 ;
if ( ! F_117 ( V_5 , V_18 ) )
return NULL ;
V_4 = & V_5 -> V_4 [ V_18 ] ;
if ( F_23 ( V_8 , & V_4 -> V_9 ) == 0 )
return NULL ;
#ifdef F_2
return V_4 -> V_3 ;
#else
return L_35 ;
#endif
}
static int F_28 ( struct V_1 * V_4 )
{
unsigned long V_9 ;
struct V_7 * V_5 ;
int V_19 = - V_20 ;
int V_18 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_55 ( L_25 , V_16 ) ;
return - V_20 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_128 || ! V_5 -> V_78 ) {
F_55 ( L_37 ,
V_16 ) ;
return - V_11 ;
}
F_61 ( & V_76 , V_9 ) ;
V_19 = F_8 ( V_4 ) ;
if ( V_19 < 0 )
goto V_99;
F_62 ( & V_76 , V_9 ) ;
F_111 ( V_5 -> V_115 ) ;
V_18 = F_3 ( V_4 ) ;
if ( V_19 ) {
V_19 = V_5 -> V_12 ( V_5 , V_18 ) ;
if ( V_19 < 0 ) {
F_17 ( L_38 ,
F_7 ( V_4 ) , V_19 ) ;
goto V_129;
}
}
V_19 = V_5 -> V_78 ( V_5 , V_18 ) ;
if ( V_19 == 0 )
F_12 ( V_22 , & V_4 -> V_9 ) ;
F_118 ( F_7 ( V_4 ) , 1 , V_19 ) ;
V_129:
return V_19 ;
V_99:
F_62 ( & V_76 , V_9 ) ;
if ( V_19 )
F_17 ( L_39 , V_16 ,
F_7 ( V_4 ) , V_19 ) ;
return V_19 ;
}
int F_119 ( unsigned V_6 )
{
return F_28 ( F_4 ( V_6 ) ) ;
}
static int F_27 ( struct V_1 * V_4 , int V_31 )
{
unsigned long V_9 ;
struct V_7 * V_5 ;
int V_19 = - V_20 ;
int V_18 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_55 ( L_25 , V_16 ) ;
return - V_20 ;
}
if ( V_31 && F_23 ( V_116 , & V_4 -> V_9 ) )
return F_28 ( V_4 ) ;
if ( ! V_31 && F_23 ( V_117 , & V_4 -> V_9 ) )
return F_28 ( V_4 ) ;
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_130 || ! V_5 -> V_79 ) {
F_55 ( L_40 ,
V_16 ) ;
return - V_11 ;
}
F_61 ( & V_76 , V_9 ) ;
V_19 = F_8 ( V_4 ) ;
if ( V_19 < 0 )
goto V_99;
F_62 ( & V_76 , V_9 ) ;
F_111 ( V_5 -> V_115 ) ;
V_18 = F_3 ( V_4 ) ;
if ( V_19 ) {
V_19 = V_5 -> V_12 ( V_5 , V_18 ) ;
if ( V_19 < 0 ) {
F_17 ( L_38 ,
F_7 ( V_4 ) , V_19 ) ;
goto V_129;
}
}
V_19 = V_5 -> V_79 ( V_5 , V_18 , V_31 ) ;
if ( V_19 == 0 )
F_19 ( V_22 , & V_4 -> V_9 ) ;
F_120 ( F_7 ( V_4 ) , 0 , V_31 ) ;
F_118 ( F_7 ( V_4 ) , 0 , V_19 ) ;
V_129:
return V_19 ;
V_99:
F_62 ( & V_76 , V_9 ) ;
if ( V_19 )
F_17 ( L_39 , V_16 ,
F_7 ( V_4 ) , V_19 ) ;
return V_19 ;
}
int F_121 ( unsigned V_6 , int V_31 )
{
return F_27 ( F_4 ( V_6 ) , V_31 ) ;
}
static int F_122 ( struct V_1 * V_4 , unsigned V_131 )
{
unsigned long V_9 ;
struct V_7 * V_5 ;
int V_19 = - V_20 ;
int V_18 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_55 ( L_25 , V_16 ) ;
return - V_20 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_130 || ! V_5 -> V_132 ) {
F_17 ( L_41 ,
V_16 ) ;
return - V_133 ;
}
F_61 ( & V_76 , V_9 ) ;
V_19 = F_8 ( V_4 ) ;
if ( V_19 < 0 )
goto V_99;
F_62 ( & V_76 , V_9 ) ;
F_111 ( V_5 -> V_115 ) ;
V_18 = F_3 ( V_4 ) ;
return V_5 -> V_132 ( V_5 , V_18 , V_131 ) ;
V_99:
F_62 ( & V_76 , V_9 ) ;
if ( V_19 )
F_17 ( L_39 , V_16 ,
F_7 ( V_4 ) , V_19 ) ;
return V_19 ;
}
int F_123 ( unsigned V_6 , unsigned V_131 )
{
return F_122 ( F_4 ( V_6 ) , V_131 ) ;
}
static int F_124 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_31 ;
int V_18 ;
if ( ! V_4 )
return 0 ;
V_5 = V_4 -> V_5 ;
V_18 = F_3 ( V_4 ) ;
F_110 ( V_5 -> V_115 ) ;
V_31 = V_5 -> V_128 ? V_5 -> V_128 ( V_5 , V_18 ) : 0 ;
F_120 ( F_7 ( V_4 ) , 1 , V_31 ) ;
return V_31 ;
}
int F_125 ( unsigned V_6 )
{
return F_124 ( F_4 ( V_6 ) ) ;
}
static void F_126 ( struct V_1 * V_4 , int V_31 )
{
int V_95 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_18 = F_3 ( V_4 ) ;
if ( V_31 ) {
V_95 = V_5 -> V_78 ( V_5 , V_18 ) ;
if ( ! V_95 )
F_12 ( V_22 , & V_4 -> V_9 ) ;
} else {
V_95 = V_5 -> V_79 ( V_5 , V_18 , 0 ) ;
if ( ! V_95 )
F_19 ( V_22 , & V_4 -> V_9 ) ;
}
F_118 ( F_7 ( V_4 ) , V_31 , V_95 ) ;
if ( V_95 < 0 )
F_11 ( L_42 ,
V_16 , F_7 ( V_4 ) , V_95 ) ;
}
static void F_127 ( struct V_1 * V_4 , int V_31 )
{
int V_95 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_18 = F_3 ( V_4 ) ;
if ( V_31 ) {
V_95 = V_5 -> V_79 ( V_5 , V_18 , 1 ) ;
if ( ! V_95 )
F_19 ( V_22 , & V_4 -> V_9 ) ;
} else {
V_95 = V_5 -> V_78 ( V_5 , V_18 ) ;
if ( ! V_95 )
F_12 ( V_22 , & V_4 -> V_9 ) ;
}
F_118 ( F_7 ( V_4 ) , ! V_31 , V_95 ) ;
if ( V_95 < 0 )
F_11 ( L_43 ,
V_16 , F_7 ( V_4 ) , V_95 ) ;
}
static void F_128 ( struct V_1 * V_4 , int V_31 )
{
struct V_7 * V_5 ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_110 ( V_5 -> V_115 ) ;
F_120 ( F_7 ( V_4 ) , 0 , V_31 ) ;
if ( F_23 ( V_116 , & V_4 -> V_9 ) )
F_126 ( V_4 , V_31 ) ;
else if ( F_23 ( V_117 , & V_4 -> V_9 ) )
F_127 ( V_4 , V_31 ) ;
else
V_5 -> V_130 ( V_5 , F_3 ( V_4 ) , V_31 ) ;
}
void F_129 ( unsigned V_6 , int V_31 )
{
return F_128 ( F_4 ( V_6 ) , V_31 ) ;
}
static int F_130 ( const struct V_1 * V_4 )
{
if ( ! V_4 )
return 0 ;
return V_4 -> V_5 -> V_115 ;
}
int F_131 ( unsigned V_6 )
{
return F_130 ( F_4 ( V_6 ) ) ;
}
static int F_37 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_18 ;
if ( ! V_4 )
return - V_20 ;
V_5 = V_4 -> V_5 ;
V_18 = F_3 ( V_4 ) ;
return V_5 -> V_134 ? V_5 -> V_134 ( V_5 , V_18 ) : - V_135 ;
}
int F_132 ( unsigned V_6 )
{
return F_37 ( F_4 ( V_6 ) ) ;
}
static int F_30 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_31 ;
int V_18 ;
F_111 ( V_114 ) ;
if ( ! V_4 )
return 0 ;
V_5 = V_4 -> V_5 ;
V_18 = F_3 ( V_4 ) ;
V_31 = V_5 -> V_128 ? V_5 -> V_128 ( V_5 , V_18 ) : 0 ;
F_120 ( F_7 ( V_4 ) , 1 , V_31 ) ;
return V_31 ;
}
int F_133 ( unsigned V_6 )
{
return F_30 ( F_4 ( V_6 ) ) ;
}
static void F_33 ( struct V_1 * V_4 , int V_31 )
{
struct V_7 * V_5 ;
F_111 ( V_114 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_120 ( F_7 ( V_4 ) , 0 , V_31 ) ;
if ( F_23 ( V_116 , & V_4 -> V_9 ) )
F_126 ( V_4 , V_31 ) ;
else if ( F_23 ( V_117 , & V_4 -> V_9 ) )
F_127 ( V_4 , V_31 ) ;
else
V_5 -> V_130 ( V_5 , F_3 ( V_4 ) , V_31 ) ;
}
void F_134 ( unsigned V_6 , int V_31 )
{
return F_33 ( F_4 ( V_6 ) , V_31 ) ;
}
static void F_135 ( struct V_136 * V_137 , struct V_7 * V_5 )
{
unsigned V_60 ;
unsigned V_6 = V_5 -> V_14 ;
struct V_1 * V_138 = & V_5 -> V_4 [ 0 ] ;
int V_139 ;
for ( V_60 = 0 ; V_60 < V_5 -> V_13 ; V_60 ++ , V_6 ++ , V_138 ++ ) {
if ( ! F_23 ( V_8 , & V_138 -> V_9 ) )
continue;
F_18 ( V_138 ) ;
V_139 = F_23 ( V_22 , & V_138 -> V_9 ) ;
F_136 ( V_137 , L_44 ,
V_6 , V_138 -> V_3 ,
V_139 ? L_8 : L_45 ,
V_5 -> V_128
? ( V_5 -> V_128 ( V_5 , V_60 ) ? L_46 : L_47 )
: L_48 ) ;
F_136 ( V_137 , L_49 ) ;
}
}
static void * F_137 ( struct V_136 * V_137 , T_5 * V_92 )
{
unsigned long V_9 ;
struct V_7 * V_5 = NULL ;
T_5 V_140 = * V_92 ;
V_137 -> V_141 = L_15 ;
F_61 ( & V_76 , V_9 ) ;
F_85 (chip, &gpio_chips, list)
if ( V_140 -- == 0 ) {
F_62 ( & V_76 , V_9 ) ;
return V_5 ;
}
F_62 ( & V_76 , V_9 ) ;
return NULL ;
}
static void * F_138 ( struct V_136 * V_137 , void * V_142 , T_5 * V_92 )
{
unsigned long V_9 ;
struct V_7 * V_5 = V_142 ;
void * V_41 = NULL ;
F_61 ( & V_76 , V_9 ) ;
if ( F_139 ( & V_5 -> V_96 , & V_93 ) )
V_41 = NULL ;
else
V_41 = F_88 ( V_5 -> V_96 . V_143 , struct V_7 , V_96 ) ;
F_62 ( & V_76 , V_9 ) ;
V_137 -> V_141 = L_49 ;
++ * V_92 ;
return V_41 ;
}
static void F_140 ( struct V_136 * V_137 , void * V_142 )
{
}
static int F_141 ( struct V_136 * V_137 , void * V_142 )
{
struct V_7 * V_5 = V_142 ;
struct V_23 * V_24 ;
F_136 ( V_137 , L_50 , ( char * ) V_137 -> V_141 ,
V_5 -> V_14 , V_5 -> V_14 + V_5 -> V_13 - 1 ) ;
V_24 = V_5 -> V_24 ;
if ( V_24 )
F_136 ( V_137 , L_51 , V_24 -> V_144 ? V_24 -> V_144 -> V_62 : L_52 ,
F_142 ( V_24 ) ) ;
if ( V_5 -> V_3 )
F_136 ( V_137 , L_53 , V_5 -> V_3 ) ;
if ( V_5 -> V_115 )
F_136 ( V_137 , L_54 ) ;
F_136 ( V_137 , L_55 ) ;
if ( V_5 -> V_145 )
V_5 -> V_145 ( V_137 , V_5 ) ;
else
F_135 ( V_137 , V_5 ) ;
return 0 ;
}
static int F_143 ( struct V_146 * V_146 , struct V_147 * V_147 )
{
return F_144 ( V_147 , & V_148 ) ;
}
static int T_4 F_145 ( void )
{
( void ) F_146 ( L_56 , V_149 | V_150 ,
NULL , NULL , & V_151 ) ;
return 0 ;
}
