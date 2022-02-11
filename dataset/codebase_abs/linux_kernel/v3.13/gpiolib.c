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
struct V_1 * F_4 ( unsigned V_6 )
{
if ( F_5 ( ! F_6 ( V_6 ) , L_1 , V_6 ) )
return NULL ;
else
return & V_1 [ V_6 ] ;
}
static struct V_1 * F_7 ( struct V_7 * V_5 ,
unsigned int V_8 )
{
unsigned int V_6 = V_5 -> V_9 + V_8 ;
return F_4 ( V_6 ) ;
}
int F_8 ( const struct V_1 * V_4 )
{
return V_4 - & V_1 [ 0 ] ;
}
static int F_9 ( struct V_1 * V_4 )
{
const struct V_7 * V_5 = V_4 -> V_5 ;
const int V_6 = F_8 ( V_4 ) ;
if ( F_5 ( F_10 ( V_10 , & V_4 -> V_11 ) == 0 ,
L_2 , V_6 ) ) {
if ( ! F_11 ( V_5 -> V_12 ) ) {
F_12 ( L_3 , V_6 ) ;
F_13 ( V_10 , & V_4 -> V_11 ) ;
return - V_13 ;
}
F_1 ( V_4 , L_4 ) ;
if ( V_5 -> V_14 )
return 1 ;
}
return 0 ;
}
struct V_7 * F_14 ( const struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_5 : NULL ;
}
static int F_15 ( int V_15 )
{
struct V_7 * V_5 ;
int V_9 = V_16 - V_15 ;
F_16 (chip, &gpio_chips, list) {
if ( V_5 -> V_9 + V_5 -> V_15 <= V_9 )
break;
else
V_9 = V_5 -> V_9 - V_15 ;
}
if ( F_6 ( V_9 ) ) {
F_17 ( L_5 , V_17 , V_9 ) ;
return V_9 ;
} else {
F_12 ( L_6 , V_17 ) ;
return - V_18 ;
}
}
int F_18 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
unsigned V_8 ;
int V_19 = - V_20 ;
V_5 = F_14 ( V_4 ) ;
V_8 = F_3 ( V_4 ) ;
if ( ! V_5 -> V_21 )
return V_19 ;
V_19 = V_5 -> V_21 ( V_5 , V_8 ) ;
if ( V_19 > 0 ) {
V_19 = 1 ;
F_13 ( V_22 , & ( (struct V_1 * ) V_4 ) -> V_11 ) ;
}
if ( V_19 == 0 ) {
F_19 ( V_22 , & ( (struct V_1 * ) V_4 ) -> V_11 ) ;
}
return V_19 ;
}
static T_1 F_20 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) ) {
V_19 = - V_13 ;
} else {
F_18 ( V_4 ) ;
V_19 = sprintf ( V_27 , L_7 ,
F_23 ( V_22 , & V_4 -> V_11 )
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
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) )
V_19 = - V_13 ;
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
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) )
V_19 = - V_13 ;
else
V_19 = sprintf ( V_27 , L_12 , F_30 ( V_4 ) ) ;
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_31 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) )
V_19 = - V_13 ;
else if ( ! F_23 ( V_22 , & V_4 -> V_11 ) )
V_19 = - V_31 ;
else {
long V_32 ;
V_19 = F_32 ( V_27 , 0 , & V_32 ) ;
if ( V_19 == 0 ) {
F_33 ( V_4 , V_32 ) ;
V_19 = V_30 ;
}
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_3 F_34 ( int V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
F_35 ( V_36 ) ;
return V_37 ;
}
static int F_36 ( struct V_1 * V_4 , struct V_23 * V_24 ,
unsigned long V_38 )
{
struct V_35 * V_36 ;
unsigned long V_39 ;
int V_40 , V_33 , V_41 ;
if ( ( V_4 -> V_11 & V_42 ) == V_38 )
return 0 ;
V_33 = F_37 ( V_4 ) ;
if ( V_33 < 0 )
return - V_13 ;
V_41 = V_4 -> V_11 >> V_43 ;
V_36 = F_38 ( & V_44 , V_41 ) ;
if ( V_36 )
F_39 ( V_33 , V_36 ) ;
V_4 -> V_11 &= ~ V_42 ;
if ( ! V_38 ) {
F_40 ( V_4 ) ;
V_40 = 0 ;
goto V_45;
}
V_39 = V_46 ;
if ( F_23 ( V_47 , & V_38 ) )
V_39 |= F_23 ( V_48 , & V_4 -> V_11 ) ?
V_49 : V_50 ;
if ( F_23 ( V_51 , & V_38 ) )
V_39 |= F_23 ( V_48 , & V_4 -> V_11 ) ?
V_50 : V_49 ;
if ( ! V_36 ) {
V_36 = F_41 ( V_24 -> V_52 . V_53 , L_13 ) ;
if ( ! V_36 ) {
V_40 = - V_54 ;
goto V_55;
}
V_40 = F_42 ( & V_44 , V_36 , 1 , 0 , V_56 ) ;
if ( V_40 < 0 )
goto V_57;
V_41 = V_40 ;
V_4 -> V_11 &= V_58 ;
V_4 -> V_11 |= ( unsigned long ) V_41 << V_43 ;
if ( V_4 -> V_11 >> V_43 != V_41 ) {
V_40 = - V_59 ;
goto V_45;
}
}
V_40 = F_43 ( V_33 , F_34 , V_39 ,
L_14 , V_36 ) ;
if ( V_40 < 0 )
goto V_45;
V_40 = F_44 ( V_4 ) ;
if ( V_40 < 0 ) {
F_45 ( V_4 , L_15 ) ;
goto V_45;
}
V_4 -> V_11 |= V_38 ;
return 0 ;
V_45:
F_46 ( & V_44 , V_41 ) ;
V_4 -> V_11 &= V_58 ;
V_57:
if ( V_36 )
F_47 ( V_36 ) ;
V_55:
return V_40 ;
}
static T_1 F_48 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) )
V_19 = - V_13 ;
else {
int V_60 ;
V_19 = 0 ;
for ( V_60 = 0 ; V_60 < F_49 ( V_61 ) ; V_60 ++ )
if ( ( V_4 -> V_11 & V_42 )
== V_61 [ V_60 ] . V_11 ) {
V_19 = sprintf ( V_27 , L_7 ,
V_61 [ V_60 ] . V_62 ) ;
break;
}
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_50 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < F_49 ( V_61 ) ; V_60 ++ )
if ( F_26 ( V_61 [ V_60 ] . V_62 , V_27 ) )
goto V_63;
return - V_20 ;
V_63:
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) )
V_19 = - V_13 ;
else {
V_19 = F_36 ( V_4 , V_24 , V_61 [ V_60 ] . V_11 ) ;
if ( ! V_19 )
V_19 = V_30 ;
}
F_24 ( & V_28 ) ;
return V_19 ;
}
static int F_51 ( struct V_1 * V_4 , struct V_23 * V_24 ,
int V_32 )
{
int V_19 = 0 ;
if ( ! ! F_23 ( V_48 , & V_4 -> V_11 ) == ! ! V_32 )
return 0 ;
if ( V_32 )
F_19 ( V_48 , & V_4 -> V_11 ) ;
else
F_13 ( V_48 , & V_4 -> V_11 ) ;
if ( V_24 != NULL && ( ! ! F_23 ( V_51 , & V_4 -> V_11 ) ^
! ! F_23 ( V_47 , & V_4 -> V_11 ) ) ) {
unsigned long V_64 = V_4 -> V_11 & V_42 ;
F_36 ( V_4 , V_24 , 0 ) ;
V_19 = F_36 ( V_4 , V_24 , V_64 ) ;
}
return V_19 ;
}
static T_1 F_52 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) )
V_19 = - V_13 ;
else
V_19 = sprintf ( V_27 , L_12 ,
! ! F_23 ( V_48 , & V_4 -> V_11 ) ) ;
F_24 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_53 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_21 ( V_24 ) ;
T_1 V_19 ;
F_22 ( & V_28 ) ;
if ( ! F_23 ( V_29 , & V_4 -> V_11 ) ) {
V_19 = - V_13 ;
} else {
long V_32 ;
V_19 = F_32 ( V_27 , 0 , & V_32 ) ;
if ( V_19 == 0 )
V_19 = F_51 ( V_4 , V_24 , V_32 != 0 ) ;
}
F_24 ( & V_28 ) ;
return V_19 ? : V_30 ;
}
static T_1 F_54 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_21 ( V_24 ) ;
return sprintf ( V_27 , L_12 , V_5 -> V_9 ) ;
}
static T_1 F_55 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_21 ( V_24 ) ;
return sprintf ( V_27 , L_7 , V_5 -> V_3 ? : L_16 ) ;
}
static T_1 F_56 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_21 ( V_24 ) ;
return sprintf ( V_27 , L_17 , V_5 -> V_15 ) ;
}
static T_1 F_57 ( struct V_65 * V_65 ,
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
F_58 ( L_18 , V_17 , V_6 ) ;
return - V_20 ;
}
V_19 = F_59 ( V_4 , L_19 ) ;
if ( V_19 < 0 ) {
if ( V_19 == - V_69 )
V_19 = - V_54 ;
goto V_68;
}
V_19 = F_60 ( V_4 , true ) ;
if ( V_19 < 0 )
F_61 ( V_4 ) ;
else
F_19 ( V_70 , & V_4 -> V_11 ) ;
V_68:
if ( V_19 )
F_17 ( L_20 , V_17 , V_19 ) ;
return V_19 ? : V_67 ;
}
static T_1 F_62 ( struct V_65 * V_65 ,
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
F_58 ( L_18 , V_17 , V_6 ) ;
return - V_20 ;
}
V_19 = - V_20 ;
if ( F_63 ( V_70 , & V_4 -> V_11 ) ) {
V_19 = 0 ;
F_61 ( V_4 ) ;
}
V_68:
if ( V_19 )
F_17 ( L_20 , V_17 , V_19 ) ;
return V_19 ? : V_67 ;
}
int F_60 ( struct V_1 * V_4 , bool V_71 )
{
unsigned long V_11 ;
int V_19 ;
const char * V_72 = NULL ;
struct V_23 * V_24 ;
int V_8 ;
if ( ! V_73 . V_74 ) {
F_17 ( L_21 , V_17 ) ;
return - V_75 ;
}
if ( ! V_4 ) {
F_17 ( L_22 , V_17 ) ;
return - V_20 ;
}
F_22 ( & V_28 ) ;
F_64 ( & V_76 , V_11 ) ;
if ( ! F_23 ( V_10 , & V_4 -> V_11 ) ||
F_23 ( V_29 , & V_4 -> V_11 ) ) {
F_65 ( & V_76 , V_11 ) ;
F_17 ( L_23 ,
V_17 , F_8 ( V_4 ) ,
F_23 ( V_10 , & V_4 -> V_11 ) ,
F_23 ( V_29 , & V_4 -> V_11 ) ) ;
V_19 = - V_31 ;
goto V_77;
}
if ( ! V_4 -> V_5 -> V_78 || ! V_4 -> V_5 -> V_79 )
V_71 = false ;
F_65 ( & V_76 , V_11 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_4 -> V_5 -> V_80 && V_4 -> V_5 -> V_80 [ V_8 ] )
V_72 = V_4 -> V_5 -> V_80 [ V_8 ] ;
V_24 = F_66 ( & V_73 , V_4 -> V_5 -> V_24 , F_67 ( 0 , 0 ) ,
V_4 , V_72 ? V_72 : L_24 ,
F_8 ( V_4 ) ) ;
if ( F_68 ( V_24 ) ) {
V_19 = F_69 ( V_24 ) ;
goto V_77;
}
V_19 = F_70 ( & V_24 -> V_52 , & V_81 ) ;
if ( V_19 )
goto V_82;
if ( V_71 ) {
V_19 = F_71 ( V_24 , & V_83 ) ;
if ( V_19 )
goto V_82;
}
if ( F_37 ( V_4 ) >= 0 && ( V_71 ||
! F_23 ( V_22 , & V_4 -> V_11 ) ) ) {
V_19 = F_71 ( V_24 , & V_84 ) ;
if ( V_19 )
goto V_82;
}
F_19 ( V_29 , & V_4 -> V_11 ) ;
F_24 ( & V_28 ) ;
return 0 ;
V_82:
F_72 ( V_24 ) ;
V_77:
F_24 ( & V_28 ) ;
F_17 ( L_25 , V_17 , F_8 ( V_4 ) ,
V_19 ) ;
return V_19 ;
}
static int F_73 ( struct V_23 * V_24 , const void * V_85 )
{
return F_21 ( V_24 ) == V_85 ;
}
int F_74 ( struct V_23 * V_24 , const char * V_62 ,
struct V_1 * V_4 )
{
int V_19 = - V_20 ;
if ( ! V_4 ) {
F_58 ( L_26 , V_17 ) ;
return - V_20 ;
}
F_22 ( & V_28 ) ;
if ( F_23 ( V_29 , & V_4 -> V_11 ) ) {
struct V_23 * V_86 ;
V_86 = F_75 ( & V_73 , NULL , V_4 , F_73 ) ;
if ( V_86 != NULL ) {
V_19 = F_76 ( & V_24 -> V_52 , & V_86 -> V_52 ,
V_62 ) ;
} else {
V_19 = - V_54 ;
}
}
F_24 ( & V_28 ) ;
if ( V_19 )
F_17 ( L_25 , V_17 , F_8 ( V_4 ) ,
V_19 ) ;
return V_19 ;
}
int F_77 ( struct V_1 * V_4 , int V_32 )
{
struct V_23 * V_24 = NULL ;
int V_19 = - V_20 ;
if ( ! V_4 ) {
F_58 ( L_26 , V_17 ) ;
return - V_20 ;
}
F_22 ( & V_28 ) ;
if ( F_23 ( V_29 , & V_4 -> V_11 ) ) {
V_24 = F_75 ( & V_73 , NULL , V_4 , F_73 ) ;
if ( V_24 == NULL ) {
V_19 = - V_54 ;
goto V_87;
}
}
V_19 = F_51 ( V_4 , V_24 , V_32 ) ;
V_87:
F_24 ( & V_28 ) ;
if ( V_19 )
F_17 ( L_25 , V_17 , F_8 ( V_4 ) ,
V_19 ) ;
return V_19 ;
}
void F_78 ( struct V_1 * V_4 )
{
int V_19 = 0 ;
struct V_23 * V_24 = NULL ;
if ( ! V_4 ) {
F_58 ( L_26 , V_17 ) ;
return;
}
F_22 ( & V_28 ) ;
if ( F_23 ( V_29 , & V_4 -> V_11 ) ) {
V_24 = F_75 ( & V_73 , NULL , V_4 , F_73 ) ;
if ( V_24 ) {
F_36 ( V_4 , V_24 , 0 ) ;
F_13 ( V_29 , & V_4 -> V_11 ) ;
} else
V_19 = - V_54 ;
}
F_24 ( & V_28 ) ;
if ( V_24 ) {
F_72 ( V_24 ) ;
F_79 ( V_24 ) ;
}
if ( V_19 )
F_17 ( L_25 , V_17 , F_8 ( V_4 ) ,
V_19 ) ;
}
static int F_80 ( struct V_7 * V_5 )
{
int V_19 ;
struct V_23 * V_24 ;
if ( ! V_73 . V_74 )
return 0 ;
F_22 ( & V_28 ) ;
V_24 = F_66 ( & V_73 , V_5 -> V_24 , F_67 ( 0 , 0 ) , V_5 ,
L_27 , V_5 -> V_9 ) ;
if ( ! F_68 ( V_24 ) ) {
V_19 = F_70 ( & V_24 -> V_52 ,
& V_88 ) ;
} else
V_19 = F_69 ( V_24 ) ;
V_5 -> V_89 = ( V_19 == 0 ) ;
F_24 ( & V_28 ) ;
if ( V_19 ) {
unsigned long V_11 ;
unsigned V_6 ;
F_64 ( & V_76 , V_11 ) ;
V_6 = 0 ;
while ( V_6 < V_5 -> V_15 )
V_5 -> V_4 [ V_6 ++ ] . V_5 = NULL ;
F_65 ( & V_76 , V_11 ) ;
F_17 ( L_28 , V_17 ,
V_5 -> V_3 , V_19 ) ;
}
return V_19 ;
}
static void F_81 ( struct V_7 * V_5 )
{
int V_19 ;
struct V_23 * V_24 ;
F_22 ( & V_28 ) ;
V_24 = F_75 ( & V_73 , NULL , V_5 , F_73 ) ;
if ( V_24 ) {
F_79 ( V_24 ) ;
F_72 ( V_24 ) ;
V_5 -> V_89 = 0 ;
V_19 = 0 ;
} else
V_19 = - V_54 ;
F_24 ( & V_28 ) ;
if ( V_19 )
F_17 ( L_28 , V_17 ,
V_5 -> V_3 , V_19 ) ;
}
static int T_4 F_82 ( void )
{
int V_19 ;
unsigned long V_11 ;
struct V_7 * V_5 ;
V_19 = F_83 ( & V_73 ) ;
if ( V_19 < 0 )
return V_19 ;
F_64 ( & V_76 , V_11 ) ;
F_84 (chip, &gpio_chips, list) {
if ( ! V_5 || V_5 -> V_89 )
continue;
F_65 ( & V_76 , V_11 ) ;
V_19 = F_80 ( V_5 ) ;
F_64 ( & V_76 , V_11 ) ;
}
F_65 ( & V_76 , V_11 ) ;
return V_19 ;
}
static inline int F_80 ( struct V_7 * V_5 )
{
return 0 ;
}
static inline void F_81 ( struct V_7 * V_5 )
{
}
static int F_85 ( struct V_7 * V_5 )
{
struct V_90 * V_91 = & V_92 ;
struct V_7 * V_93 ;
int V_94 = 0 ;
F_86 (pos, &gpio_chips) {
V_93 = F_87 ( V_91 , struct V_7 , V_95 ) ;
if ( V_93 -> V_9 >= V_5 -> V_9 + V_5 -> V_15 )
break;
}
if ( V_91 != & V_92 && V_91 -> V_96 != & V_92 ) {
V_93 = F_87 ( V_91 -> V_96 , struct V_7 , V_95 ) ;
if ( V_93 -> V_9 + V_93 -> V_15 > V_5 -> V_9 ) {
F_88 ( V_5 -> V_24 ,
L_29 ) ;
V_94 = - V_97 ;
}
}
if ( ! V_94 )
F_89 ( & V_5 -> V_95 , V_91 ) ;
return V_94 ;
}
int F_90 ( struct V_7 * V_5 )
{
unsigned long V_11 ;
int V_19 = 0 ;
unsigned V_41 ;
int V_9 = V_5 -> V_9 ;
if ( ( ! F_6 ( V_9 ) || ! F_6 ( V_9 + V_5 -> V_15 - 1 ) )
&& V_9 >= 0 ) {
V_19 = - V_20 ;
goto V_98;
}
F_64 ( & V_76 , V_11 ) ;
if ( V_9 < 0 ) {
V_9 = F_15 ( V_5 -> V_15 ) ;
if ( V_9 < 0 ) {
V_19 = V_9 ;
goto V_87;
}
V_5 -> V_9 = V_9 ;
}
V_19 = F_85 ( V_5 ) ;
if ( V_19 == 0 ) {
V_5 -> V_4 = & V_1 [ V_5 -> V_9 ] ;
for ( V_41 = 0 ; V_41 < V_5 -> V_15 ; V_41 ++ ) {
struct V_1 * V_4 = & V_5 -> V_4 [ V_41 ] ;
V_4 -> V_5 = V_5 ;
V_4 -> V_11 = ! V_5 -> V_78
? ( 1 << V_22 )
: 0 ;
}
}
F_65 ( & V_76 , V_11 ) ;
#ifdef F_91
F_92 ( & V_5 -> V_99 ) ;
#endif
F_93 ( V_5 ) ;
if ( V_19 )
goto V_98;
V_19 = F_80 ( V_5 ) ;
if ( V_19 )
goto V_98;
F_17 ( L_30 ,
V_5 -> V_9 , V_5 -> V_9 + V_5 -> V_15 - 1 ,
V_5 -> V_3 ? : L_31 ) ;
return 0 ;
V_87:
F_65 ( & V_76 , V_11 ) ;
V_98:
F_12 ( L_32 ,
V_5 -> V_9 , V_5 -> V_9 + V_5 -> V_15 - 1 ,
V_5 -> V_3 ? : L_31 ) ;
return V_19 ;
}
int F_94 ( struct V_7 * V_5 )
{
unsigned long V_11 ;
int V_19 = 0 ;
unsigned V_41 ;
F_64 ( & V_76 , V_11 ) ;
F_95 ( V_5 ) ;
F_96 ( V_5 ) ;
for ( V_41 = 0 ; V_41 < V_5 -> V_15 ; V_41 ++ ) {
if ( F_23 ( V_10 , & V_5 -> V_4 [ V_41 ] . V_11 ) ) {
V_19 = - V_97 ;
break;
}
}
if ( V_19 == 0 ) {
for ( V_41 = 0 ; V_41 < V_5 -> V_15 ; V_41 ++ )
V_5 -> V_4 [ V_41 ] . V_5 = NULL ;
F_97 ( & V_5 -> V_95 ) ;
}
F_65 ( & V_76 , V_11 ) ;
if ( V_19 == 0 )
F_81 ( V_5 ) ;
return V_19 ;
}
struct V_7 * F_98 ( void * V_85 ,
int (* F_99)( struct V_7 * V_5 ,
void * V_85 ) )
{
struct V_7 * V_5 ;
unsigned long V_11 ;
F_64 ( & V_76 , V_11 ) ;
F_84 (chip, &gpio_chips, list)
if ( F_99 ( V_5 , V_85 ) )
break;
if ( & V_5 -> V_95 == & V_92 )
V_5 = NULL ;
F_65 ( & V_76 , V_11 ) ;
return V_5 ;
}
static int F_100 ( struct V_7 * V_5 , void * V_85 )
{
const char * V_62 = V_85 ;
return ! strcmp ( V_5 -> V_3 , V_62 ) ;
}
static struct V_7 * F_101 ( const char * V_62 )
{
return F_98 ( ( void * ) V_62 , F_100 ) ;
}
int F_102 ( struct V_7 * V_5 ,
struct V_100 * V_101 ,
unsigned int V_102 , const char * V_103 )
{
struct V_104 * V_105 ;
int V_40 ;
V_105 = F_103 ( sizeof( * V_105 ) , V_56 ) ;
if ( ! V_105 ) {
F_12 ( L_33 ,
V_5 -> V_3 ) ;
return - V_106 ;
}
V_105 -> V_107 . V_41 = V_102 ;
V_105 -> V_107 . V_108 = V_5 ;
V_105 -> V_107 . V_62 = V_5 -> V_3 ;
V_105 -> V_107 . V_9 = V_5 -> V_9 + V_102 ;
V_105 -> V_101 = V_101 ;
V_40 = F_104 ( V_101 , V_103 ,
& V_105 -> V_107 . V_109 ,
& V_105 -> V_107 . V_110 ) ;
if ( V_40 < 0 ) {
F_105 ( V_105 ) ;
return V_40 ;
}
F_106 ( V_101 , & V_105 -> V_107 ) ;
F_17 ( L_34 ,
V_5 -> V_3 , V_102 ,
V_102 + V_105 -> V_107 . V_110 - 1 ,
F_107 ( V_101 ) , V_103 ) ;
F_89 ( & V_105 -> V_111 , & V_5 -> V_99 ) ;
return 0 ;
}
int F_108 ( struct V_7 * V_5 , const char * V_112 ,
unsigned int V_102 , unsigned int V_113 ,
unsigned int V_110 )
{
struct V_104 * V_105 ;
int V_40 ;
V_105 = F_103 ( sizeof( * V_105 ) , V_56 ) ;
if ( ! V_105 ) {
F_12 ( L_33 ,
V_5 -> V_3 ) ;
return - V_106 ;
}
V_105 -> V_107 . V_41 = V_102 ;
V_105 -> V_107 . V_108 = V_5 ;
V_105 -> V_107 . V_62 = V_5 -> V_3 ;
V_105 -> V_107 . V_9 = V_5 -> V_9 + V_102 ;
V_105 -> V_107 . V_114 = V_113 ;
V_105 -> V_107 . V_110 = V_110 ;
V_105 -> V_101 = F_109 ( V_112 ,
& V_105 -> V_107 ) ;
if ( F_68 ( V_105 -> V_101 ) ) {
V_40 = F_69 ( V_105 -> V_101 ) ;
F_12 ( L_35 ,
V_5 -> V_3 ) ;
F_105 ( V_105 ) ;
return V_40 ;
}
F_17 ( L_36 ,
V_5 -> V_3 , V_102 , V_102 + V_110 - 1 ,
V_112 ,
V_113 , V_113 + V_110 - 1 ) ;
F_89 ( & V_105 -> V_111 , & V_5 -> V_99 ) ;
return 0 ;
}
void F_95 ( struct V_7 * V_5 )
{
struct V_104 * V_105 , * V_115 ;
F_110 (pin_range, tmp, &chip->pin_ranges, node) {
F_97 ( & V_105 -> V_111 ) ;
F_111 ( V_105 -> V_101 ,
& V_105 -> V_107 ) ;
F_105 ( V_105 ) ;
}
}
static int F_59 ( struct V_1 * V_4 , const char * V_3 )
{
struct V_7 * V_5 ;
int V_19 = - V_69 ;
unsigned long V_11 ;
if ( ! V_4 ) {
F_58 ( L_26 , V_17 ) ;
return - V_20 ;
}
F_64 ( & V_76 , V_11 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 == NULL )
goto V_68;
if ( ! F_11 ( V_5 -> V_12 ) )
goto V_68;
if ( F_10 ( V_10 , & V_4 -> V_11 ) == 0 ) {
F_1 ( V_4 , V_3 ? : L_37 ) ;
V_19 = 0 ;
} else {
V_19 = - V_97 ;
F_112 ( V_5 -> V_12 ) ;
goto V_68;
}
if ( V_5 -> V_14 ) {
F_65 ( & V_76 , V_11 ) ;
V_19 = V_5 -> V_14 ( V_5 , F_3 ( V_4 ) ) ;
F_64 ( & V_76 , V_11 ) ;
if ( V_19 < 0 ) {
F_1 ( V_4 , NULL ) ;
F_112 ( V_5 -> V_12 ) ;
F_13 ( V_10 , & V_4 -> V_11 ) ;
goto V_68;
}
}
if ( V_5 -> V_21 ) {
F_65 ( & V_76 , V_11 ) ;
F_18 ( V_4 ) ;
F_64 ( & V_76 , V_11 ) ;
}
V_68:
if ( V_19 )
F_17 ( L_38 ,
F_8 ( V_4 ) , V_3 ? : L_37 , V_19 ) ;
F_65 ( & V_76 , V_11 ) ;
return V_19 ;
}
int F_113 ( unsigned V_6 , const char * V_3 )
{
return F_59 ( F_4 ( V_6 ) , V_3 ) ;
}
static void F_61 ( struct V_1 * V_4 )
{
unsigned long V_11 ;
struct V_7 * V_5 ;
F_114 () ;
if ( ! V_4 ) {
F_115 ( V_116 ) ;
return;
}
F_78 ( V_4 ) ;
F_64 ( & V_76 , V_11 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 && F_23 ( V_10 , & V_4 -> V_11 ) ) {
if ( V_5 -> free ) {
F_65 ( & V_76 , V_11 ) ;
F_116 ( V_5 -> V_117 ) ;
V_5 -> free ( V_5 , F_3 ( V_4 ) ) ;
F_64 ( & V_76 , V_11 ) ;
}
F_1 ( V_4 , NULL ) ;
F_112 ( V_4 -> V_5 -> V_12 ) ;
F_13 ( V_48 , & V_4 -> V_11 ) ;
F_13 ( V_10 , & V_4 -> V_11 ) ;
F_13 ( V_118 , & V_4 -> V_11 ) ;
F_13 ( V_119 , & V_4 -> V_11 ) ;
} else
F_115 ( V_116 ) ;
F_65 ( & V_76 , V_11 ) ;
}
void F_117 ( unsigned V_6 )
{
F_61 ( F_4 ( V_6 ) ) ;
}
int F_118 ( unsigned V_6 , unsigned long V_11 , const char * V_3 )
{
struct V_1 * V_4 ;
int V_94 ;
V_4 = F_4 ( V_6 ) ;
V_94 = F_59 ( V_4 , V_3 ) ;
if ( V_94 )
return V_94 ;
if ( V_11 & V_120 )
F_19 ( V_118 , & V_4 -> V_11 ) ;
if ( V_11 & V_121 )
F_19 ( V_119 , & V_4 -> V_11 ) ;
if ( V_11 & V_122 )
V_94 = F_28 ( V_4 ) ;
else
V_94 = F_27 ( V_4 ,
( V_11 & V_123 ) ? 1 : 0 ) ;
if ( V_94 )
goto V_124;
if ( V_11 & V_125 ) {
V_94 = F_60 ( V_4 , V_11 & V_126 ) ;
if ( V_94 )
goto V_124;
}
return 0 ;
V_124:
F_61 ( V_4 ) ;
return V_94 ;
}
int F_119 ( const struct V_6 * V_127 , T_2 V_128 )
{
int V_60 , V_94 ;
for ( V_60 = 0 ; V_60 < V_128 ; V_60 ++ , V_127 ++ ) {
V_94 = F_118 ( V_127 -> V_6 , V_127 -> V_11 , V_127 -> V_3 ) ;
if ( V_94 )
goto V_129;
}
return 0 ;
V_129:
while ( V_60 -- )
F_117 ( ( -- V_127 ) -> V_6 ) ;
return V_94 ;
}
void F_120 ( const struct V_6 * V_127 , T_2 V_128 )
{
while ( V_128 -- )
F_117 ( ( V_127 ++ ) -> V_6 ) ;
}
const char * F_121 ( struct V_7 * V_5 , unsigned V_8 )
{
struct V_1 * V_4 ;
if ( ! F_122 ( V_5 , V_8 ) )
return NULL ;
V_4 = & V_5 -> V_4 [ V_8 ] ;
if ( F_23 ( V_10 , & V_4 -> V_11 ) == 0 )
return NULL ;
#ifdef F_2
return V_4 -> V_3 ;
#else
return L_37 ;
#endif
}
int F_28 ( struct V_1 * V_4 )
{
unsigned long V_11 ;
struct V_7 * V_5 ;
int V_19 = - V_20 ;
int V_8 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_58 ( L_26 , V_17 ) ;
return - V_20 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_130 || ! V_5 -> V_78 ) {
F_45 ( V_4 ,
L_39 ,
V_17 ) ;
return - V_13 ;
}
F_64 ( & V_76 , V_11 ) ;
V_19 = F_9 ( V_4 ) ;
if ( V_19 < 0 )
goto V_98;
F_65 ( & V_76 , V_11 ) ;
F_116 ( V_5 -> V_117 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_19 ) {
V_19 = V_5 -> V_14 ( V_5 , V_8 ) ;
if ( V_19 < 0 ) {
F_123 ( V_4 , L_40 , V_19 ) ;
goto V_131;
}
}
V_19 = V_5 -> V_78 ( V_5 , V_8 ) ;
if ( V_19 == 0 )
F_13 ( V_22 , & V_4 -> V_11 ) ;
F_124 ( F_8 ( V_4 ) , 1 , V_19 ) ;
V_131:
return V_19 ;
V_98:
F_65 ( & V_76 , V_11 ) ;
if ( V_19 )
F_123 ( V_4 , L_41 , V_17 , V_19 ) ;
return V_19 ;
}
int F_27 ( struct V_1 * V_4 , int V_32 )
{
unsigned long V_11 ;
struct V_7 * V_5 ;
int V_19 = - V_20 ;
int V_8 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_58 ( L_26 , V_17 ) ;
return - V_20 ;
}
if ( F_23 ( V_132 , & V_4 -> V_11 ) ) {
F_125 ( V_4 ,
L_42 ,
V_17 ) ;
return - V_13 ;
}
if ( V_32 && F_23 ( V_118 , & V_4 -> V_11 ) )
return F_28 ( V_4 ) ;
if ( ! V_32 && F_23 ( V_119 , & V_4 -> V_11 ) )
return F_28 ( V_4 ) ;
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_133 || ! V_5 -> V_79 ) {
F_45 ( V_4 ,
L_43 ,
V_17 ) ;
return - V_13 ;
}
F_64 ( & V_76 , V_11 ) ;
V_19 = F_9 ( V_4 ) ;
if ( V_19 < 0 )
goto V_98;
F_65 ( & V_76 , V_11 ) ;
F_116 ( V_5 -> V_117 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_19 ) {
V_19 = V_5 -> V_14 ( V_5 , V_8 ) ;
if ( V_19 < 0 ) {
F_123 ( V_4 , L_40 , V_19 ) ;
goto V_131;
}
}
V_19 = V_5 -> V_79 ( V_5 , V_8 , V_32 ) ;
if ( V_19 == 0 )
F_19 ( V_22 , & V_4 -> V_11 ) ;
F_126 ( F_8 ( V_4 ) , 0 , V_32 ) ;
F_124 ( F_8 ( V_4 ) , 0 , V_19 ) ;
V_131:
return V_19 ;
V_98:
F_65 ( & V_76 , V_11 ) ;
if ( V_19 )
F_123 ( V_4 , L_44 , V_17 , V_19 ) ;
return V_19 ;
}
int F_127 ( struct V_1 * V_4 , unsigned V_134 )
{
unsigned long V_11 ;
struct V_7 * V_5 ;
int V_19 = - V_20 ;
int V_8 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_58 ( L_26 , V_17 ) ;
return - V_20 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_133 || ! V_5 -> V_135 ) {
F_123 ( V_4 ,
L_45 ,
V_17 ) ;
return - V_136 ;
}
F_64 ( & V_76 , V_11 ) ;
V_19 = F_9 ( V_4 ) ;
if ( V_19 < 0 )
goto V_98;
F_65 ( & V_76 , V_11 ) ;
F_116 ( V_5 -> V_117 ) ;
V_8 = F_3 ( V_4 ) ;
return V_5 -> V_135 ( V_5 , V_8 , V_134 ) ;
V_98:
F_65 ( & V_76 , V_11 ) ;
if ( V_19 )
F_123 ( V_4 , L_20 , V_17 , V_19 ) ;
return V_19 ;
}
int F_128 ( const struct V_1 * V_4 )
{
return F_23 ( V_48 , & V_4 -> V_11 ) ;
}
static int F_129 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_32 ;
int V_8 ;
V_5 = V_4 -> V_5 ;
V_8 = F_3 ( V_4 ) ;
V_32 = V_5 -> V_130 ? V_5 -> V_130 ( V_5 , V_8 ) : 0 ;
F_126 ( F_8 ( V_4 ) , 1 , V_32 ) ;
return V_32 ;
}
int F_130 ( const struct V_1 * V_4 )
{
if ( ! V_4 )
return 0 ;
F_115 ( V_4 -> V_5 -> V_117 ) ;
return F_129 ( V_4 ) ;
}
int F_131 ( const struct V_1 * V_4 )
{
int V_32 ;
if ( ! V_4 )
return 0 ;
F_115 ( V_4 -> V_5 -> V_117 ) ;
V_32 = F_129 ( V_4 ) ;
if ( F_23 ( V_48 , & V_4 -> V_11 ) )
V_32 = ! V_32 ;
return V_32 ;
}
static void F_132 ( struct V_1 * V_4 , int V_32 )
{
int V_94 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_8 = F_3 ( V_4 ) ;
if ( V_32 ) {
V_94 = V_5 -> V_78 ( V_5 , V_8 ) ;
if ( ! V_94 )
F_13 ( V_22 , & V_4 -> V_11 ) ;
} else {
V_94 = V_5 -> V_79 ( V_5 , V_8 , 0 ) ;
if ( ! V_94 )
F_19 ( V_22 , & V_4 -> V_11 ) ;
}
F_124 ( F_8 ( V_4 ) , V_32 , V_94 ) ;
if ( V_94 < 0 )
F_125 ( V_4 ,
L_46 ,
V_17 , V_94 ) ;
}
static void F_133 ( struct V_1 * V_4 , int V_32 )
{
int V_94 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_8 = F_3 ( V_4 ) ;
if ( V_32 ) {
V_94 = V_5 -> V_79 ( V_5 , V_8 , 1 ) ;
if ( ! V_94 )
F_19 ( V_22 , & V_4 -> V_11 ) ;
} else {
V_94 = V_5 -> V_78 ( V_5 , V_8 ) ;
if ( ! V_94 )
F_13 ( V_22 , & V_4 -> V_11 ) ;
}
F_124 ( F_8 ( V_4 ) , ! V_32 , V_94 ) ;
if ( V_94 < 0 )
F_125 ( V_4 ,
L_47 ,
V_17 , V_94 ) ;
}
static void F_134 ( struct V_1 * V_4 , int V_32 )
{
struct V_7 * V_5 ;
V_5 = V_4 -> V_5 ;
F_126 ( F_8 ( V_4 ) , 0 , V_32 ) ;
if ( F_23 ( V_118 , & V_4 -> V_11 ) )
F_132 ( V_4 , V_32 ) ;
else if ( F_23 ( V_119 , & V_4 -> V_11 ) )
F_133 ( V_4 , V_32 ) ;
else
V_5 -> V_133 ( V_5 , F_3 ( V_4 ) , V_32 ) ;
}
void F_135 ( struct V_1 * V_4 , int V_32 )
{
if ( ! V_4 )
return;
F_115 ( V_4 -> V_5 -> V_117 ) ;
F_134 ( V_4 , V_32 ) ;
}
void F_136 ( struct V_1 * V_4 , int V_32 )
{
if ( ! V_4 )
return;
F_115 ( V_4 -> V_5 -> V_117 ) ;
if ( F_23 ( V_48 , & V_4 -> V_11 ) )
V_32 = ! V_32 ;
F_134 ( V_4 , V_32 ) ;
}
int F_137 ( const struct V_1 * V_4 )
{
if ( ! V_4 )
return 0 ;
return V_4 -> V_5 -> V_117 ;
}
int F_37 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_8 ;
if ( ! V_4 )
return - V_20 ;
V_5 = V_4 -> V_5 ;
V_8 = F_3 ( V_4 ) ;
return V_5 -> V_137 ? V_5 -> V_137 ( V_5 , V_8 ) : - V_138 ;
}
int F_44 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return - V_20 ;
if ( F_23 ( V_22 , & V_4 -> V_11 ) ) {
F_125 ( V_4 ,
L_48 ,
V_17 ) ;
return - V_13 ;
}
F_19 ( V_132 , & V_4 -> V_11 ) ;
return 0 ;
}
int F_138 ( struct V_7 * V_5 , unsigned int V_8 )
{
return F_44 ( F_7 ( V_5 , V_8 ) ) ;
}
void F_40 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_13 ( V_132 , & V_4 -> V_11 ) ;
}
void F_139 ( struct V_7 * V_5 , unsigned int V_8 )
{
return F_40 ( F_7 ( V_5 , V_8 ) ) ;
}
int F_140 ( const struct V_1 * V_4 )
{
F_116 ( V_116 ) ;
if ( ! V_4 )
return 0 ;
return F_129 ( V_4 ) ;
}
int F_30 ( const struct V_1 * V_4 )
{
int V_32 ;
F_116 ( V_116 ) ;
if ( ! V_4 )
return 0 ;
V_32 = F_129 ( V_4 ) ;
if ( F_23 ( V_48 , & V_4 -> V_11 ) )
V_32 = ! V_32 ;
return V_32 ;
}
void F_141 ( struct V_1 * V_4 , int V_32 )
{
F_116 ( V_116 ) ;
if ( ! V_4 )
return;
F_134 ( V_4 , V_32 ) ;
}
void F_33 ( struct V_1 * V_4 , int V_32 )
{
F_116 ( V_116 ) ;
if ( ! V_4 )
return;
if ( F_23 ( V_48 , & V_4 -> V_11 ) )
V_32 = ! V_32 ;
F_134 ( V_4 , V_32 ) ;
}
void F_142 ( struct V_139 * V_140 , T_2 V_30 )
{
F_22 ( & V_141 ) ;
while ( V_30 -- ) {
F_89 ( & V_140 -> V_95 , & V_142 ) ;
V_140 ++ ;
}
F_24 ( & V_141 ) ;
}
static struct V_1 * F_143 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_11 )
{
char V_146 [ 32 ] ;
enum V_147 V_148 ;
struct V_1 * V_4 ;
if ( V_143 )
snprintf ( V_146 , 32 , L_49 , V_143 ) ;
else
snprintf ( V_146 , 32 , L_50 ) ;
V_4 = F_144 ( V_24 -> V_149 , V_146 , V_144 ,
& V_148 ) ;
if ( F_68 ( V_4 ) )
return V_4 ;
if ( V_148 & V_150 )
* V_11 |= V_151 ;
return V_4 ;
}
static struct V_1 * F_143 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_11 )
{
return F_145 ( - V_54 ) ;
}
static struct V_1 * F_146 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_11 )
{
struct V_152 V_153 ;
struct V_1 * V_4 ;
V_4 = F_147 ( V_24 , V_144 , & V_153 ) ;
if ( F_68 ( V_4 ) )
return V_4 ;
if ( V_153 . V_154 && V_153 . V_155 )
* V_11 |= V_151 ;
return V_4 ;
}
static struct V_1 * F_148 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_11 )
{
const char * V_156 = V_24 ? F_149 ( V_24 ) : NULL ;
struct V_1 * V_4 = F_145 ( - V_54 ) ;
unsigned int F_99 , V_157 = 0 ;
struct V_139 * V_74 ;
F_22 ( & V_141 ) ;
F_84 (p, &gpio_lookup_list, list) {
F_99 = 0 ;
if ( V_74 -> V_156 ) {
if ( ! V_156 || strcmp ( V_74 -> V_156 , V_156 ) )
continue;
F_99 += 2 ;
}
if ( V_74 -> V_143 ) {
if ( ! V_143 || strcmp ( V_74 -> V_143 , V_143 ) )
continue;
F_99 += 1 ;
}
if ( V_74 -> V_144 != V_144 )
continue;
if ( F_99 > V_157 ) {
struct V_7 * V_5 ;
V_5 = F_101 ( V_74 -> V_158 ) ;
if ( ! V_5 ) {
F_150 ( V_24 , L_51 ,
V_74 -> V_158 ) ;
continue;
}
if ( V_5 -> V_15 <= V_74 -> V_159 ) {
F_150 ( V_24 , L_52 ,
V_5 -> V_3 , V_5 -> V_15 ) ;
continue;
}
V_4 = F_4 ( V_5 -> V_9 + V_74 -> V_159 ) ;
* V_11 = V_74 -> V_11 ;
if ( F_99 != 3 )
V_157 = F_99 ;
else
break;
}
}
F_24 ( & V_141 ) ;
return V_4 ;
}
struct V_1 * T_5 F_151 ( struct V_23 * V_24 , const char * V_143 )
{
return F_152 ( V_24 , V_143 , 0 ) ;
}
struct V_1 * T_5 F_152 ( struct V_23 * V_24 ,
const char * V_143 ,
unsigned int V_144 )
{
struct V_1 * V_4 = NULL ;
int V_19 ;
enum V_145 V_11 = 0 ;
F_153 ( V_24 , L_53 , V_143 ) ;
if ( F_154 ( V_160 ) && V_24 && V_24 -> V_149 ) {
F_153 ( V_24 , L_54 ) ;
V_4 = F_143 ( V_24 , V_143 , V_144 , & V_11 ) ;
} else if ( F_154 ( V_161 ) && V_24 && F_155 ( V_24 ) ) {
F_153 ( V_24 , L_55 ) ;
V_4 = F_146 ( V_24 , V_143 , V_144 , & V_11 ) ;
}
if ( ! V_4 || F_68 ( V_4 ) ) {
struct V_1 * V_162 ;
F_153 ( V_24 , L_56 ) ;
V_162 = F_148 ( V_24 , V_143 , V_144 , & V_11 ) ;
if ( ! F_68 ( V_162 ) || ! V_4 )
V_4 = V_162 ;
}
if ( F_68 ( V_4 ) ) {
F_153 ( V_24 , L_57 , V_143 ) ;
return V_4 ;
}
V_19 = F_59 ( V_4 , V_143 ) ;
if ( V_19 < 0 )
return F_145 ( V_19 ) ;
if ( V_11 & V_151 )
F_19 ( V_48 , & V_4 -> V_11 ) ;
if ( V_11 & V_163 )
F_19 ( V_118 , & V_4 -> V_11 ) ;
if ( V_11 & V_164 )
F_19 ( V_119 , & V_4 -> V_11 ) ;
return V_4 ;
}
void F_156 ( struct V_1 * V_4 )
{
F_61 ( V_4 ) ;
}
static void F_157 ( struct V_165 * V_166 , struct V_7 * V_5 )
{
unsigned V_60 ;
unsigned V_6 = V_5 -> V_9 ;
struct V_1 * V_167 = & V_5 -> V_4 [ 0 ] ;
int V_168 ;
int V_169 ;
for ( V_60 = 0 ; V_60 < V_5 -> V_15 ; V_60 ++ , V_6 ++ , V_167 ++ ) {
if ( ! F_23 ( V_10 , & V_167 -> V_11 ) )
continue;
F_18 ( V_167 ) ;
V_168 = F_23 ( V_22 , & V_167 -> V_11 ) ;
V_169 = F_23 ( V_132 , & V_167 -> V_11 ) ;
F_158 ( V_166 , L_58 ,
V_6 , V_167 -> V_3 ,
V_168 ? L_8 : L_59 ,
V_5 -> V_130
? ( V_5 -> V_130 ( V_5 , V_60 ) ? L_60 : L_61 )
: L_62 ,
V_169 ? L_63 : L_64 ) ;
F_158 ( V_166 , L_65 ) ;
}
}
static void * F_159 ( struct V_165 * V_166 , T_6 * V_91 )
{
unsigned long V_11 ;
struct V_7 * V_5 = NULL ;
T_6 V_170 = * V_91 ;
V_166 -> V_171 = L_16 ;
F_64 ( & V_76 , V_11 ) ;
F_84 (chip, &gpio_chips, list)
if ( V_170 -- == 0 ) {
F_65 ( & V_76 , V_11 ) ;
return V_5 ;
}
F_65 ( & V_76 , V_11 ) ;
return NULL ;
}
static void * F_160 ( struct V_165 * V_166 , void * V_172 , T_6 * V_91 )
{
unsigned long V_11 ;
struct V_7 * V_5 = V_172 ;
void * V_40 = NULL ;
F_64 ( & V_76 , V_11 ) ;
if ( F_161 ( & V_5 -> V_95 , & V_92 ) )
V_40 = NULL ;
else
V_40 = F_87 ( V_5 -> V_95 . V_173 , struct V_7 , V_95 ) ;
F_65 ( & V_76 , V_11 ) ;
V_166 -> V_171 = L_65 ;
++ * V_91 ;
return V_40 ;
}
static void F_162 ( struct V_165 * V_166 , void * V_172 )
{
}
static int F_163 ( struct V_165 * V_166 , void * V_172 )
{
struct V_7 * V_5 = V_172 ;
struct V_23 * V_24 ;
F_158 ( V_166 , L_66 , ( char * ) V_166 -> V_171 ,
V_5 -> V_9 , V_5 -> V_9 + V_5 -> V_15 - 1 ) ;
V_24 = V_5 -> V_24 ;
if ( V_24 )
F_158 ( V_166 , L_67 , V_24 -> V_174 ? V_24 -> V_174 -> V_62 : L_68 ,
F_149 ( V_24 ) ) ;
if ( V_5 -> V_3 )
F_158 ( V_166 , L_69 , V_5 -> V_3 ) ;
if ( V_5 -> V_117 )
F_158 ( V_166 , L_70 ) ;
F_158 ( V_166 , L_71 ) ;
if ( V_5 -> V_175 )
V_5 -> V_175 ( V_166 , V_5 ) ;
else
F_157 ( V_166 , V_5 ) ;
return 0 ;
}
static int F_164 ( struct V_176 * V_176 , struct V_177 * V_177 )
{
return F_165 ( V_177 , & V_178 ) ;
}
static int T_4 F_166 ( void )
{
( void ) F_167 ( L_72 , V_179 | V_180 ,
NULL , NULL , & V_181 ) ;
return 0 ;
}
