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
if ( V_8 >= V_5 -> V_9 )
return F_8 ( - V_10 ) ;
return & V_5 -> V_4 [ V_8 ] ;
}
int F_9 ( const struct V_1 * V_4 )
{
return V_4 - & V_1 [ 0 ] ;
}
static int F_10 ( struct V_1 * V_4 )
{
const struct V_7 * V_5 = V_4 -> V_5 ;
const int V_6 = F_9 ( V_4 ) ;
if ( F_5 ( F_11 ( V_11 , & V_4 -> V_12 ) == 0 ,
L_2 , V_6 ) ) {
if ( ! F_12 ( V_5 -> V_13 ) ) {
F_13 ( V_4 , L_3 ,
V_14 ) ;
F_14 ( V_11 , & V_4 -> V_12 ) ;
return - V_15 ;
}
F_1 ( V_4 , L_4 ) ;
if ( V_5 -> V_16 )
return 1 ;
}
return 0 ;
}
struct V_7 * F_15 ( const struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_5 : NULL ;
}
static int F_16 ( int V_9 )
{
struct V_7 * V_5 ;
int V_17 = V_18 - V_9 ;
F_17 (chip, &gpio_chips, list) {
if ( V_5 -> V_17 + V_5 -> V_9 <= V_17 )
break;
else
V_17 = V_5 -> V_17 - V_9 ;
}
if ( F_6 ( V_17 ) ) {
F_18 ( L_5 , V_14 , V_17 ) ;
return V_17 ;
} else {
F_19 ( L_6 , V_14 ) ;
return - V_19 ;
}
}
int F_20 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
unsigned V_8 ;
int V_20 = - V_10 ;
V_5 = F_15 ( V_4 ) ;
V_8 = F_3 ( V_4 ) ;
if ( ! V_5 -> V_21 )
return V_20 ;
V_20 = V_5 -> V_21 ( V_5 , V_8 ) ;
if ( V_20 > 0 ) {
V_20 = 1 ;
F_14 ( V_22 , & ( (struct V_1 * ) V_4 ) -> V_12 ) ;
}
if ( V_20 == 0 ) {
F_21 ( V_22 , & ( (struct V_1 * ) V_4 ) -> V_12 ) ;
}
return V_20 ;
}
static T_1 F_22 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) ) {
V_20 = - V_15 ;
} else {
F_20 ( V_4 ) ;
V_20 = sprintf ( V_27 , L_7 ,
F_25 ( V_22 , & V_4 -> V_12 )
? L_8 : L_9 ) ;
}
F_26 ( & V_28 ) ;
return V_20 ;
}
static T_1 F_27 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) )
V_20 = - V_15 ;
else if ( F_28 ( V_27 , L_10 ) )
V_20 = F_29 ( V_4 , 1 ) ;
else if ( F_28 ( V_27 , L_8 ) || F_28 ( V_27 , L_11 ) )
V_20 = F_29 ( V_4 , 0 ) ;
else if ( F_28 ( V_27 , L_9 ) )
V_20 = F_30 ( V_4 ) ;
else
V_20 = - V_10 ;
F_26 ( & V_28 ) ;
return V_20 ? : V_30 ;
}
static T_1 F_31 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) )
V_20 = - V_15 ;
else
V_20 = sprintf ( V_27 , L_12 , F_32 ( V_4 ) ) ;
F_26 ( & V_28 ) ;
return V_20 ;
}
static T_1 F_33 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) )
V_20 = - V_15 ;
else if ( ! F_25 ( V_22 , & V_4 -> V_12 ) )
V_20 = - V_31 ;
else {
long V_32 ;
V_20 = F_34 ( V_27 , 0 , & V_32 ) ;
if ( V_20 == 0 ) {
F_35 ( V_4 , V_32 ) ;
V_20 = V_30 ;
}
}
F_26 ( & V_28 ) ;
return V_20 ;
}
static T_3 F_36 ( int V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
F_37 ( V_36 ) ;
return V_37 ;
}
static int F_38 ( struct V_1 * V_4 , struct V_23 * V_24 ,
unsigned long V_38 )
{
struct V_35 * V_36 ;
unsigned long V_39 ;
int V_40 , V_33 , V_41 ;
if ( ( V_4 -> V_12 & V_42 ) == V_38 )
return 0 ;
V_33 = F_39 ( V_4 ) ;
if ( V_33 < 0 )
return - V_15 ;
V_41 = V_4 -> V_12 >> V_43 ;
V_36 = F_40 ( & V_44 , V_41 ) ;
if ( V_36 )
F_41 ( V_33 , V_36 ) ;
V_4 -> V_12 &= ~ V_42 ;
if ( ! V_38 ) {
F_42 ( V_4 ) ;
V_40 = 0 ;
goto V_45;
}
V_39 = V_46 ;
if ( F_25 ( V_47 , & V_38 ) )
V_39 |= F_25 ( V_48 , & V_4 -> V_12 ) ?
V_49 : V_50 ;
if ( F_25 ( V_51 , & V_38 ) )
V_39 |= F_25 ( V_48 , & V_4 -> V_12 ) ?
V_50 : V_49 ;
if ( ! V_36 ) {
V_36 = F_43 ( V_24 -> V_52 . V_53 , L_13 ) ;
if ( ! V_36 ) {
V_40 = - V_54 ;
goto V_55;
}
V_40 = F_44 ( & V_44 , V_36 , 1 , 0 , V_56 ) ;
if ( V_40 < 0 )
goto V_57;
V_41 = V_40 ;
V_4 -> V_12 &= V_58 ;
V_4 -> V_12 |= ( unsigned long ) V_41 << V_43 ;
if ( V_4 -> V_12 >> V_43 != V_41 ) {
V_40 = - V_59 ;
goto V_45;
}
}
V_40 = F_45 ( V_33 , F_36 , V_39 ,
L_14 , V_36 ) ;
if ( V_40 < 0 )
goto V_45;
V_40 = F_46 ( V_4 ) ;
if ( V_40 < 0 ) {
F_47 ( V_4 , L_15 ) ;
goto V_45;
}
V_4 -> V_12 |= V_38 ;
return 0 ;
V_45:
F_48 ( & V_44 , V_41 ) ;
V_4 -> V_12 &= V_58 ;
V_57:
if ( V_36 )
F_49 ( V_36 ) ;
V_55:
return V_40 ;
}
static T_1 F_50 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) )
V_20 = - V_15 ;
else {
int V_60 ;
V_20 = 0 ;
for ( V_60 = 0 ; V_60 < F_51 ( V_61 ) ; V_60 ++ )
if ( ( V_4 -> V_12 & V_42 )
== V_61 [ V_60 ] . V_12 ) {
V_20 = sprintf ( V_27 , L_7 ,
V_61 [ V_60 ] . V_62 ) ;
break;
}
}
F_26 ( & V_28 ) ;
return V_20 ;
}
static T_1 F_52 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < F_51 ( V_61 ) ; V_60 ++ )
if ( F_28 ( V_61 [ V_60 ] . V_62 , V_27 ) )
goto V_63;
return - V_10 ;
V_63:
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) )
V_20 = - V_15 ;
else {
V_20 = F_38 ( V_4 , V_24 , V_61 [ V_60 ] . V_12 ) ;
if ( ! V_20 )
V_20 = V_30 ;
}
F_26 ( & V_28 ) ;
return V_20 ;
}
static int F_53 ( struct V_1 * V_4 , struct V_23 * V_24 ,
int V_32 )
{
int V_20 = 0 ;
if ( ! ! F_25 ( V_48 , & V_4 -> V_12 ) == ! ! V_32 )
return 0 ;
if ( V_32 )
F_21 ( V_48 , & V_4 -> V_12 ) ;
else
F_14 ( V_48 , & V_4 -> V_12 ) ;
if ( V_24 != NULL && ( ! ! F_25 ( V_51 , & V_4 -> V_12 ) ^
! ! F_25 ( V_47 , & V_4 -> V_12 ) ) ) {
unsigned long V_64 = V_4 -> V_12 & V_42 ;
F_38 ( V_4 , V_24 , 0 ) ;
V_20 = F_38 ( V_4 , V_24 , V_64 ) ;
}
return V_20 ;
}
static T_1 F_54 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) )
V_20 = - V_15 ;
else
V_20 = sprintf ( V_27 , L_12 ,
! ! F_25 ( V_48 , & V_4 -> V_12 ) ) ;
F_26 ( & V_28 ) ;
return V_20 ;
}
static T_1 F_55 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_2 V_30 )
{
struct V_1 * V_4 = F_23 ( V_24 ) ;
T_1 V_20 ;
F_24 ( & V_28 ) ;
if ( ! F_25 ( V_29 , & V_4 -> V_12 ) ) {
V_20 = - V_15 ;
} else {
long V_32 ;
V_20 = F_34 ( V_27 , 0 , & V_32 ) ;
if ( V_20 == 0 )
V_20 = F_53 ( V_4 , V_24 , V_32 != 0 ) ;
}
F_26 ( & V_28 ) ;
return V_20 ? : V_30 ;
}
static T_1 F_56 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_23 ( V_24 ) ;
return sprintf ( V_27 , L_12 , V_5 -> V_17 ) ;
}
static T_1 F_57 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_23 ( V_24 ) ;
return sprintf ( V_27 , L_7 , V_5 -> V_3 ? : L_16 ) ;
}
static T_1 F_58 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
const struct V_7 * V_5 = F_23 ( V_24 ) ;
return sprintf ( V_27 , L_17 , V_5 -> V_9 ) ;
}
static T_1 F_59 ( struct V_65 * V_65 ,
struct V_66 * V_26 ,
const char * V_27 , T_2 V_67 )
{
long V_6 ;
struct V_1 * V_4 ;
int V_20 ;
V_20 = F_34 ( V_27 , 0 , & V_6 ) ;
if ( V_20 < 0 )
goto V_68;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
F_60 ( L_18 , V_14 , V_6 ) ;
return - V_10 ;
}
V_20 = F_61 ( V_4 , L_19 ) ;
if ( V_20 < 0 ) {
if ( V_20 == - V_69 )
V_20 = - V_54 ;
goto V_68;
}
V_20 = F_62 ( V_4 , true ) ;
if ( V_20 < 0 )
F_63 ( V_4 ) ;
else
F_21 ( V_70 , & V_4 -> V_12 ) ;
V_68:
if ( V_20 )
F_18 ( L_20 , V_14 , V_20 ) ;
return V_20 ? : V_67 ;
}
static T_1 F_64 ( struct V_65 * V_65 ,
struct V_66 * V_26 ,
const char * V_27 , T_2 V_67 )
{
long V_6 ;
struct V_1 * V_4 ;
int V_20 ;
V_20 = F_34 ( V_27 , 0 , & V_6 ) ;
if ( V_20 < 0 )
goto V_68;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
F_60 ( L_18 , V_14 , V_6 ) ;
return - V_10 ;
}
V_20 = - V_10 ;
if ( F_65 ( V_70 , & V_4 -> V_12 ) ) {
V_20 = 0 ;
F_63 ( V_4 ) ;
}
V_68:
if ( V_20 )
F_18 ( L_20 , V_14 , V_20 ) ;
return V_20 ? : V_67 ;
}
int F_62 ( struct V_1 * V_4 , bool V_71 )
{
unsigned long V_12 ;
int V_20 ;
const char * V_72 = NULL ;
struct V_23 * V_24 ;
int V_8 ;
if ( ! V_73 . V_74 ) {
F_18 ( L_21 , V_14 ) ;
return - V_75 ;
}
if ( ! V_4 ) {
F_18 ( L_22 , V_14 ) ;
return - V_10 ;
}
F_24 ( & V_28 ) ;
F_66 ( & V_76 , V_12 ) ;
if ( ! F_25 ( V_11 , & V_4 -> V_12 ) ||
F_25 ( V_29 , & V_4 -> V_12 ) ) {
F_67 ( & V_76 , V_12 ) ;
F_68 ( V_4 , L_23 ,
V_14 ,
F_25 ( V_11 , & V_4 -> V_12 ) ,
F_25 ( V_29 , & V_4 -> V_12 ) ) ;
V_20 = - V_31 ;
goto V_77;
}
if ( ! V_4 -> V_5 -> V_78 || ! V_4 -> V_5 -> V_79 )
V_71 = false ;
F_67 ( & V_76 , V_12 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_4 -> V_5 -> V_80 && V_4 -> V_5 -> V_80 [ V_8 ] )
V_72 = V_4 -> V_5 -> V_80 [ V_8 ] ;
V_24 = F_69 ( & V_73 , V_4 -> V_5 -> V_24 , F_70 ( 0 , 0 ) ,
V_4 , V_72 ? V_72 : L_24 ,
F_9 ( V_4 ) ) ;
if ( F_71 ( V_24 ) ) {
V_20 = F_72 ( V_24 ) ;
goto V_77;
}
V_20 = F_73 ( & V_24 -> V_52 , & V_81 ) ;
if ( V_20 )
goto V_82;
if ( V_71 ) {
V_20 = F_74 ( V_24 , & V_83 ) ;
if ( V_20 )
goto V_82;
}
if ( F_39 ( V_4 ) >= 0 && ( V_71 ||
! F_25 ( V_22 , & V_4 -> V_12 ) ) ) {
V_20 = F_74 ( V_24 , & V_84 ) ;
if ( V_20 )
goto V_82;
}
F_21 ( V_29 , & V_4 -> V_12 ) ;
F_26 ( & V_28 ) ;
return 0 ;
V_82:
F_75 ( V_24 ) ;
V_77:
F_26 ( & V_28 ) ;
F_68 ( V_4 , L_20 , V_14 , V_20 ) ;
return V_20 ;
}
static int F_76 ( struct V_23 * V_24 , const void * V_85 )
{
return F_23 ( V_24 ) == V_85 ;
}
int F_77 ( struct V_23 * V_24 , const char * V_62 ,
struct V_1 * V_4 )
{
int V_20 = - V_10 ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
F_24 ( & V_28 ) ;
if ( F_25 ( V_29 , & V_4 -> V_12 ) ) {
struct V_23 * V_86 ;
V_86 = F_78 ( & V_73 , NULL , V_4 , F_76 ) ;
if ( V_86 != NULL ) {
V_20 = F_79 ( & V_24 -> V_52 , & V_86 -> V_52 ,
V_62 ) ;
} else {
V_20 = - V_54 ;
}
}
F_26 ( & V_28 ) ;
if ( V_20 )
F_68 ( V_4 , L_20 , V_14 , V_20 ) ;
return V_20 ;
}
int F_80 ( struct V_1 * V_4 , int V_32 )
{
struct V_23 * V_24 = NULL ;
int V_20 = - V_10 ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
F_24 ( & V_28 ) ;
if ( F_25 ( V_29 , & V_4 -> V_12 ) ) {
V_24 = F_78 ( & V_73 , NULL , V_4 , F_76 ) ;
if ( V_24 == NULL ) {
V_20 = - V_54 ;
goto V_87;
}
}
V_20 = F_53 ( V_4 , V_24 , V_32 ) ;
V_87:
F_26 ( & V_28 ) ;
if ( V_20 )
F_68 ( V_4 , L_20 , V_14 , V_20 ) ;
return V_20 ;
}
void F_81 ( struct V_1 * V_4 )
{
int V_20 = 0 ;
struct V_23 * V_24 = NULL ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return;
}
F_24 ( & V_28 ) ;
if ( F_25 ( V_29 , & V_4 -> V_12 ) ) {
V_24 = F_78 ( & V_73 , NULL , V_4 , F_76 ) ;
if ( V_24 ) {
F_38 ( V_4 , V_24 , 0 ) ;
F_14 ( V_29 , & V_4 -> V_12 ) ;
} else
V_20 = - V_54 ;
}
F_26 ( & V_28 ) ;
if ( V_24 ) {
F_75 ( V_24 ) ;
F_82 ( V_24 ) ;
}
if ( V_20 )
F_68 ( V_4 , L_20 , V_14 , V_20 ) ;
}
static int F_83 ( struct V_7 * V_5 )
{
int V_20 ;
struct V_23 * V_24 ;
if ( ! V_73 . V_74 )
return 0 ;
F_24 ( & V_28 ) ;
V_24 = F_69 ( & V_73 , V_5 -> V_24 , F_70 ( 0 , 0 ) , V_5 ,
L_26 , V_5 -> V_17 ) ;
if ( ! F_71 ( V_24 ) ) {
V_20 = F_73 ( & V_24 -> V_52 ,
& V_88 ) ;
} else
V_20 = F_72 ( V_24 ) ;
V_5 -> V_89 = ( V_20 == 0 ) ;
F_26 ( & V_28 ) ;
if ( V_20 ) {
unsigned long V_12 ;
unsigned V_6 ;
F_66 ( & V_76 , V_12 ) ;
V_6 = 0 ;
while ( V_6 < V_5 -> V_9 )
V_5 -> V_4 [ V_6 ++ ] . V_5 = NULL ;
F_67 ( & V_76 , V_12 ) ;
F_84 ( V_5 , L_20 , V_14 , V_20 ) ;
}
return V_20 ;
}
static void F_85 ( struct V_7 * V_5 )
{
int V_20 ;
struct V_23 * V_24 ;
F_24 ( & V_28 ) ;
V_24 = F_78 ( & V_73 , NULL , V_5 , F_76 ) ;
if ( V_24 ) {
F_82 ( V_24 ) ;
F_75 ( V_24 ) ;
V_5 -> V_89 = false ;
V_20 = 0 ;
} else
V_20 = - V_54 ;
F_26 ( & V_28 ) ;
if ( V_20 )
F_84 ( V_5 , L_20 , V_14 , V_20 ) ;
}
static int T_4 F_86 ( void )
{
int V_20 ;
unsigned long V_12 ;
struct V_7 * V_5 ;
V_20 = F_87 ( & V_73 ) ;
if ( V_20 < 0 )
return V_20 ;
F_66 ( & V_76 , V_12 ) ;
F_88 (chip, &gpio_chips, list) {
if ( ! V_5 || V_5 -> V_89 )
continue;
F_67 ( & V_76 , V_12 ) ;
V_20 = F_83 ( V_5 ) ;
F_66 ( & V_76 , V_12 ) ;
}
F_67 ( & V_76 , V_12 ) ;
return V_20 ;
}
static inline int F_83 ( struct V_7 * V_5 )
{
return 0 ;
}
static inline void F_85 ( struct V_7 * V_5 )
{
}
static int F_89 ( struct V_7 * V_5 )
{
struct V_90 * V_91 = & V_92 ;
struct V_7 * V_93 ;
int V_94 = 0 ;
F_90 (pos, &gpio_chips) {
V_93 = F_91 ( V_91 , struct V_7 , V_95 ) ;
if ( V_93 -> V_17 >= V_5 -> V_17 + V_5 -> V_9 )
break;
}
if ( V_91 != & V_92 && V_91 -> V_96 != & V_92 ) {
V_93 = F_91 ( V_91 -> V_96 , struct V_7 , V_95 ) ;
if ( V_93 -> V_17 + V_93 -> V_9 > V_5 -> V_17 ) {
F_92 ( V_5 -> V_24 ,
L_27 ) ;
V_94 = - V_97 ;
}
}
if ( ! V_94 )
F_93 ( & V_5 -> V_95 , V_91 ) ;
return V_94 ;
}
int F_94 ( struct V_7 * V_5 )
{
unsigned long V_12 ;
int V_20 = 0 ;
unsigned V_41 ;
int V_17 = V_5 -> V_17 ;
if ( ( ! F_6 ( V_17 ) || ! F_6 ( V_17 + V_5 -> V_9 - 1 ) )
&& V_17 >= 0 ) {
V_20 = - V_10 ;
goto V_98;
}
F_66 ( & V_76 , V_12 ) ;
if ( V_17 < 0 ) {
V_17 = F_16 ( V_5 -> V_9 ) ;
if ( V_17 < 0 ) {
V_20 = V_17 ;
goto V_87;
}
V_5 -> V_17 = V_17 ;
}
V_20 = F_89 ( V_5 ) ;
if ( V_20 == 0 ) {
V_5 -> V_4 = & V_1 [ V_5 -> V_17 ] ;
for ( V_41 = 0 ; V_41 < V_5 -> V_9 ; V_41 ++ ) {
struct V_1 * V_4 = & V_5 -> V_4 [ V_41 ] ;
V_4 -> V_5 = V_5 ;
V_4 -> V_12 = ! V_5 -> V_78
? ( 1 << V_22 )
: 0 ;
}
}
F_67 ( & V_76 , V_12 ) ;
#ifdef F_95
F_96 ( & V_5 -> V_99 ) ;
#endif
F_97 ( V_5 ) ;
F_98 ( V_5 ) ;
if ( V_20 )
goto V_98;
V_20 = F_83 ( V_5 ) ;
if ( V_20 )
goto V_98;
F_18 ( L_28 , V_14 ,
V_5 -> V_17 , V_5 -> V_17 + V_5 -> V_9 - 1 ,
V_5 -> V_3 ? : L_29 ) ;
return 0 ;
V_87:
F_67 ( & V_76 , V_12 ) ;
V_98:
F_19 ( L_30 , V_14 ,
V_5 -> V_17 , V_5 -> V_17 + V_5 -> V_9 - 1 ,
V_5 -> V_3 ? : L_29 ) ;
return V_20 ;
}
int F_99 ( struct V_7 * V_5 )
{
unsigned long V_12 ;
int V_20 = 0 ;
unsigned V_41 ;
F_66 ( & V_76 , V_12 ) ;
F_100 ( V_5 ) ;
F_101 ( V_5 ) ;
F_102 ( V_5 ) ;
for ( V_41 = 0 ; V_41 < V_5 -> V_9 ; V_41 ++ ) {
if ( F_25 ( V_11 , & V_5 -> V_4 [ V_41 ] . V_12 ) ) {
V_20 = - V_97 ;
break;
}
}
if ( V_20 == 0 ) {
for ( V_41 = 0 ; V_41 < V_5 -> V_9 ; V_41 ++ )
V_5 -> V_4 [ V_41 ] . V_5 = NULL ;
F_103 ( & V_5 -> V_95 ) ;
}
F_67 ( & V_76 , V_12 ) ;
if ( V_20 == 0 )
F_85 ( V_5 ) ;
return V_20 ;
}
struct V_7 * F_104 ( void * V_85 ,
int (* F_105)( struct V_7 * V_5 ,
void * V_85 ) )
{
struct V_7 * V_5 ;
unsigned long V_12 ;
F_66 ( & V_76 , V_12 ) ;
F_88 (chip, &gpio_chips, list)
if ( F_105 ( V_5 , V_85 ) )
break;
if ( & V_5 -> V_95 == & V_92 )
V_5 = NULL ;
F_67 ( & V_76 , V_12 ) ;
return V_5 ;
}
static int F_106 ( struct V_7 * V_5 , void * V_85 )
{
const char * V_62 = V_85 ;
return ! strcmp ( V_5 -> V_3 , V_62 ) ;
}
static struct V_7 * F_107 ( const char * V_62 )
{
return F_104 ( ( void * ) V_62 , F_106 ) ;
}
int F_108 ( struct V_7 * V_5 ,
struct V_100 * V_101 ,
unsigned int V_102 , const char * V_103 )
{
struct V_104 * V_105 ;
int V_40 ;
V_105 = F_109 ( sizeof( * V_105 ) , V_56 ) ;
if ( ! V_105 ) {
F_110 ( V_5 , L_31 ) ;
return - V_106 ;
}
V_105 -> V_107 . V_41 = V_102 ;
V_105 -> V_107 . V_108 = V_5 ;
V_105 -> V_107 . V_62 = V_5 -> V_3 ;
V_105 -> V_107 . V_17 = V_5 -> V_17 + V_102 ;
V_105 -> V_101 = V_101 ;
V_40 = F_111 ( V_101 , V_103 ,
& V_105 -> V_107 . V_109 ,
& V_105 -> V_107 . V_110 ) ;
if ( V_40 < 0 ) {
F_112 ( V_105 ) ;
return V_40 ;
}
F_113 ( V_101 , & V_105 -> V_107 ) ;
F_84 ( V_5 , L_32 ,
V_102 , V_102 + V_105 -> V_107 . V_110 - 1 ,
F_114 ( V_101 ) , V_103 ) ;
F_93 ( & V_105 -> V_111 , & V_5 -> V_99 ) ;
return 0 ;
}
int F_115 ( struct V_7 * V_5 , const char * V_112 ,
unsigned int V_102 , unsigned int V_113 ,
unsigned int V_110 )
{
struct V_104 * V_105 ;
int V_40 ;
V_105 = F_109 ( sizeof( * V_105 ) , V_56 ) ;
if ( ! V_105 ) {
F_110 ( V_5 , L_31 ) ;
return - V_106 ;
}
V_105 -> V_107 . V_41 = V_102 ;
V_105 -> V_107 . V_108 = V_5 ;
V_105 -> V_107 . V_62 = V_5 -> V_3 ;
V_105 -> V_107 . V_17 = V_5 -> V_17 + V_102 ;
V_105 -> V_107 . V_114 = V_113 ;
V_105 -> V_107 . V_110 = V_110 ;
V_105 -> V_101 = F_116 ( V_112 ,
& V_105 -> V_107 ) ;
if ( F_71 ( V_105 -> V_101 ) ) {
V_40 = F_72 ( V_105 -> V_101 ) ;
F_110 ( V_5 , L_33 ) ;
F_112 ( V_105 ) ;
return V_40 ;
}
F_84 ( V_5 , L_34 ,
V_102 , V_102 + V_110 - 1 ,
V_112 ,
V_113 , V_113 + V_110 - 1 ) ;
F_93 ( & V_105 -> V_111 , & V_5 -> V_99 ) ;
return 0 ;
}
void F_100 ( struct V_7 * V_5 )
{
struct V_104 * V_105 , * V_115 ;
F_117 (pin_range, tmp, &chip->pin_ranges, node) {
F_103 ( & V_105 -> V_111 ) ;
F_118 ( V_105 -> V_101 ,
& V_105 -> V_107 ) ;
F_112 ( V_105 ) ;
}
}
static int F_61 ( struct V_1 * V_4 , const char * V_3 )
{
struct V_7 * V_5 ;
int V_20 = - V_69 ;
unsigned long V_12 ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
F_66 ( & V_76 , V_12 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 == NULL )
goto V_68;
if ( ! F_12 ( V_5 -> V_13 ) )
goto V_68;
if ( F_11 ( V_11 , & V_4 -> V_12 ) == 0 ) {
F_1 ( V_4 , V_3 ? : L_35 ) ;
V_20 = 0 ;
} else {
V_20 = - V_97 ;
F_119 ( V_5 -> V_13 ) ;
goto V_68;
}
if ( V_5 -> V_16 ) {
F_67 ( & V_76 , V_12 ) ;
V_20 = V_5 -> V_16 ( V_5 , F_3 ( V_4 ) ) ;
F_66 ( & V_76 , V_12 ) ;
if ( V_20 < 0 ) {
F_1 ( V_4 , NULL ) ;
F_119 ( V_5 -> V_13 ) ;
F_14 ( V_11 , & V_4 -> V_12 ) ;
goto V_68;
}
}
if ( V_5 -> V_21 ) {
F_67 ( & V_76 , V_12 ) ;
F_20 ( V_4 ) ;
F_66 ( & V_76 , V_12 ) ;
}
V_68:
if ( V_20 )
F_68 ( V_4 , L_20 , V_14 , V_20 ) ;
F_67 ( & V_76 , V_12 ) ;
return V_20 ;
}
int F_120 ( unsigned V_6 , const char * V_3 )
{
return F_61 ( F_4 ( V_6 ) , V_3 ) ;
}
static void F_63 ( struct V_1 * V_4 )
{
unsigned long V_12 ;
struct V_7 * V_5 ;
F_121 () ;
if ( ! V_4 ) {
F_122 ( V_116 ) ;
return;
}
F_81 ( V_4 ) ;
F_66 ( & V_76 , V_12 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 && F_25 ( V_11 , & V_4 -> V_12 ) ) {
if ( V_5 -> free ) {
F_67 ( & V_76 , V_12 ) ;
F_123 ( V_5 -> V_117 ) ;
V_5 -> free ( V_5 , F_3 ( V_4 ) ) ;
F_66 ( & V_76 , V_12 ) ;
}
F_1 ( V_4 , NULL ) ;
F_119 ( V_4 -> V_5 -> V_13 ) ;
F_14 ( V_48 , & V_4 -> V_12 ) ;
F_14 ( V_11 , & V_4 -> V_12 ) ;
F_14 ( V_118 , & V_4 -> V_12 ) ;
F_14 ( V_119 , & V_4 -> V_12 ) ;
} else
F_122 ( V_116 ) ;
F_67 ( & V_76 , V_12 ) ;
}
void F_124 ( unsigned V_6 )
{
F_63 ( F_4 ( V_6 ) ) ;
}
int F_125 ( unsigned V_6 , unsigned long V_12 , const char * V_3 )
{
struct V_1 * V_4 ;
int V_94 ;
V_4 = F_4 ( V_6 ) ;
V_94 = F_61 ( V_4 , V_3 ) ;
if ( V_94 )
return V_94 ;
if ( V_12 & V_120 )
F_21 ( V_118 , & V_4 -> V_12 ) ;
if ( V_12 & V_121 )
F_21 ( V_119 , & V_4 -> V_12 ) ;
if ( V_12 & V_122 )
V_94 = F_30 ( V_4 ) ;
else
V_94 = F_29 ( V_4 ,
( V_12 & V_123 ) ? 1 : 0 ) ;
if ( V_94 )
goto V_124;
if ( V_12 & V_125 ) {
V_94 = F_62 ( V_4 , V_12 & V_126 ) ;
if ( V_94 )
goto V_124;
}
return 0 ;
V_124:
F_63 ( V_4 ) ;
return V_94 ;
}
int F_126 ( const struct V_6 * V_127 , T_2 V_128 )
{
int V_60 , V_94 ;
for ( V_60 = 0 ; V_60 < V_128 ; V_60 ++ , V_127 ++ ) {
V_94 = F_125 ( V_127 -> V_6 , V_127 -> V_12 , V_127 -> V_3 ) ;
if ( V_94 )
goto V_129;
}
return 0 ;
V_129:
while ( V_60 -- )
F_124 ( ( -- V_127 ) -> V_6 ) ;
return V_94 ;
}
void F_127 ( const struct V_6 * V_127 , T_2 V_128 )
{
while ( V_128 -- )
F_124 ( ( V_127 ++ ) -> V_6 ) ;
}
const char * F_128 ( struct V_7 * V_5 , unsigned V_8 )
{
struct V_1 * V_4 ;
if ( ! F_129 ( V_5 , V_8 ) )
return NULL ;
V_4 = & V_5 -> V_4 [ V_8 ] ;
if ( F_25 ( V_11 , & V_4 -> V_12 ) == 0 )
return NULL ;
#ifdef F_2
return V_4 -> V_3 ;
#else
return L_35 ;
#endif
}
int F_30 ( struct V_1 * V_4 )
{
unsigned long V_12 ;
struct V_7 * V_5 ;
int V_20 = - V_10 ;
int V_8 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_130 || ! V_5 -> V_78 ) {
F_47 ( V_4 ,
L_36 ,
V_14 ) ;
return - V_15 ;
}
F_66 ( & V_76 , V_12 ) ;
V_20 = F_10 ( V_4 ) ;
if ( V_20 < 0 )
goto V_98;
F_67 ( & V_76 , V_12 ) ;
F_123 ( V_5 -> V_117 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_20 ) {
V_20 = V_5 -> V_16 ( V_5 , V_8 ) ;
if ( V_20 < 0 ) {
F_68 ( V_4 , L_37 ,
V_14 , V_20 ) ;
goto V_131;
}
}
V_20 = V_5 -> V_78 ( V_5 , V_8 ) ;
if ( V_20 == 0 )
F_14 ( V_22 , & V_4 -> V_12 ) ;
F_130 ( F_9 ( V_4 ) , 1 , V_20 ) ;
V_131:
return V_20 ;
V_98:
F_67 ( & V_76 , V_12 ) ;
if ( V_20 )
F_68 ( V_4 , L_20 , V_14 , V_20 ) ;
return V_20 ;
}
int F_29 ( struct V_1 * V_4 , int V_32 )
{
unsigned long V_12 ;
struct V_7 * V_5 ;
int V_20 = - V_10 ;
int V_8 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
if ( F_25 ( V_132 , & V_4 -> V_12 ) ) {
F_13 ( V_4 ,
L_38 ,
V_14 ) ;
return - V_15 ;
}
if ( V_32 && F_25 ( V_118 , & V_4 -> V_12 ) )
return F_30 ( V_4 ) ;
if ( ! V_32 && F_25 ( V_119 , & V_4 -> V_12 ) )
return F_30 ( V_4 ) ;
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_133 || ! V_5 -> V_79 ) {
F_47 ( V_4 ,
L_39 ,
V_14 ) ;
return - V_15 ;
}
F_66 ( & V_76 , V_12 ) ;
V_20 = F_10 ( V_4 ) ;
if ( V_20 < 0 )
goto V_98;
F_67 ( & V_76 , V_12 ) ;
F_123 ( V_5 -> V_117 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_20 ) {
V_20 = V_5 -> V_16 ( V_5 , V_8 ) ;
if ( V_20 < 0 ) {
F_68 ( V_4 , L_37 ,
V_14 , V_20 ) ;
goto V_131;
}
}
V_20 = V_5 -> V_79 ( V_5 , V_8 , V_32 ) ;
if ( V_20 == 0 )
F_21 ( V_22 , & V_4 -> V_12 ) ;
F_131 ( F_9 ( V_4 ) , 0 , V_32 ) ;
F_130 ( F_9 ( V_4 ) , 0 , V_20 ) ;
V_131:
return V_20 ;
V_98:
F_67 ( & V_76 , V_12 ) ;
if ( V_20 )
F_68 ( V_4 , L_40 , V_14 , V_20 ) ;
return V_20 ;
}
int F_132 ( struct V_1 * V_4 , unsigned V_134 )
{
unsigned long V_12 ;
struct V_7 * V_5 ;
int V_20 = - V_10 ;
int V_8 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_133 || ! V_5 -> V_135 ) {
F_68 ( V_4 ,
L_41 ,
V_14 ) ;
return - V_136 ;
}
F_66 ( & V_76 , V_12 ) ;
V_20 = F_10 ( V_4 ) ;
if ( V_20 < 0 )
goto V_98;
F_67 ( & V_76 , V_12 ) ;
F_123 ( V_5 -> V_117 ) ;
V_8 = F_3 ( V_4 ) ;
return V_5 -> V_135 ( V_5 , V_8 , V_134 ) ;
V_98:
F_67 ( & V_76 , V_12 ) ;
if ( V_20 )
F_68 ( V_4 , L_20 , V_14 , V_20 ) ;
return V_20 ;
}
int F_133 ( const struct V_1 * V_4 )
{
return F_25 ( V_48 , & V_4 -> V_12 ) ;
}
static int F_134 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_32 ;
int V_8 ;
V_5 = V_4 -> V_5 ;
V_8 = F_3 ( V_4 ) ;
V_32 = V_5 -> V_130 ? V_5 -> V_130 ( V_5 , V_8 ) : 0 ;
F_131 ( F_9 ( V_4 ) , 1 , V_32 ) ;
return V_32 ;
}
int F_135 ( const struct V_1 * V_4 )
{
if ( ! V_4 )
return 0 ;
F_122 ( V_4 -> V_5 -> V_117 ) ;
return F_134 ( V_4 ) ;
}
int F_136 ( const struct V_1 * V_4 )
{
int V_32 ;
if ( ! V_4 )
return 0 ;
F_122 ( V_4 -> V_5 -> V_117 ) ;
V_32 = F_134 ( V_4 ) ;
if ( F_25 ( V_48 , & V_4 -> V_12 ) )
V_32 = ! V_32 ;
return V_32 ;
}
static void F_137 ( struct V_1 * V_4 , int V_32 )
{
int V_94 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_8 = F_3 ( V_4 ) ;
if ( V_32 ) {
V_94 = V_5 -> V_78 ( V_5 , V_8 ) ;
if ( ! V_94 )
F_14 ( V_22 , & V_4 -> V_12 ) ;
} else {
V_94 = V_5 -> V_79 ( V_5 , V_8 , 0 ) ;
if ( ! V_94 )
F_21 ( V_22 , & V_4 -> V_12 ) ;
}
F_130 ( F_9 ( V_4 ) , V_32 , V_94 ) ;
if ( V_94 < 0 )
F_13 ( V_4 ,
L_42 ,
V_14 , V_94 ) ;
}
static void F_138 ( struct V_1 * V_4 , int V_32 )
{
int V_94 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_8 = F_3 ( V_4 ) ;
if ( V_32 ) {
V_94 = V_5 -> V_79 ( V_5 , V_8 , 1 ) ;
if ( ! V_94 )
F_21 ( V_22 , & V_4 -> V_12 ) ;
} else {
V_94 = V_5 -> V_78 ( V_5 , V_8 ) ;
if ( ! V_94 )
F_14 ( V_22 , & V_4 -> V_12 ) ;
}
F_130 ( F_9 ( V_4 ) , ! V_32 , V_94 ) ;
if ( V_94 < 0 )
F_13 ( V_4 ,
L_43 ,
V_14 , V_94 ) ;
}
static void F_139 ( struct V_1 * V_4 , int V_32 )
{
struct V_7 * V_5 ;
V_5 = V_4 -> V_5 ;
F_131 ( F_9 ( V_4 ) , 0 , V_32 ) ;
if ( F_25 ( V_118 , & V_4 -> V_12 ) )
F_137 ( V_4 , V_32 ) ;
else if ( F_25 ( V_119 , & V_4 -> V_12 ) )
F_138 ( V_4 , V_32 ) ;
else
V_5 -> V_133 ( V_5 , F_3 ( V_4 ) , V_32 ) ;
}
void F_140 ( struct V_1 * V_4 , int V_32 )
{
if ( ! V_4 )
return;
F_122 ( V_4 -> V_5 -> V_117 ) ;
F_139 ( V_4 , V_32 ) ;
}
void F_141 ( struct V_1 * V_4 , int V_32 )
{
if ( ! V_4 )
return;
F_122 ( V_4 -> V_5 -> V_117 ) ;
if ( F_25 ( V_48 , & V_4 -> V_12 ) )
V_32 = ! V_32 ;
F_139 ( V_4 , V_32 ) ;
}
int F_142 ( const struct V_1 * V_4 )
{
if ( ! V_4 )
return 0 ;
return V_4 -> V_5 -> V_117 ;
}
int F_39 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_8 ;
if ( ! V_4 )
return - V_10 ;
V_5 = V_4 -> V_5 ;
V_8 = F_3 ( V_4 ) ;
return V_5 -> V_137 ? V_5 -> V_137 ( V_5 , V_8 ) : - V_138 ;
}
int F_46 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return - V_10 ;
if ( F_25 ( V_22 , & V_4 -> V_12 ) ) {
F_13 ( V_4 ,
L_44 ,
V_14 ) ;
return - V_15 ;
}
F_21 ( V_132 , & V_4 -> V_12 ) ;
return 0 ;
}
int F_143 ( struct V_7 * V_5 , unsigned int V_8 )
{
return F_46 ( F_7 ( V_5 , V_8 ) ) ;
}
void F_42 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_14 ( V_132 , & V_4 -> V_12 ) ;
}
void F_144 ( struct V_7 * V_5 , unsigned int V_8 )
{
return F_42 ( F_7 ( V_5 , V_8 ) ) ;
}
int F_145 ( const struct V_1 * V_4 )
{
F_123 ( V_116 ) ;
if ( ! V_4 )
return 0 ;
return F_134 ( V_4 ) ;
}
int F_32 ( const struct V_1 * V_4 )
{
int V_32 ;
F_123 ( V_116 ) ;
if ( ! V_4 )
return 0 ;
V_32 = F_134 ( V_4 ) ;
if ( F_25 ( V_48 , & V_4 -> V_12 ) )
V_32 = ! V_32 ;
return V_32 ;
}
void F_146 ( struct V_1 * V_4 , int V_32 )
{
F_123 ( V_116 ) ;
if ( ! V_4 )
return;
F_139 ( V_4 , V_32 ) ;
}
void F_35 ( struct V_1 * V_4 , int V_32 )
{
F_123 ( V_116 ) ;
if ( ! V_4 )
return;
if ( F_25 ( V_48 , & V_4 -> V_12 ) )
V_32 = ! V_32 ;
F_139 ( V_4 , V_32 ) ;
}
void F_147 ( struct V_139 * V_140 )
{
F_24 ( & V_141 ) ;
F_93 ( & V_140 -> V_95 , & V_142 ) ;
F_26 ( & V_141 ) ;
}
static struct V_1 * F_148 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_12 )
{
char V_146 [ 32 ] ;
enum V_147 V_148 ;
struct V_1 * V_4 ;
if ( V_143 )
snprintf ( V_146 , 32 , L_45 , V_143 ) ;
else
snprintf ( V_146 , 32 , L_46 ) ;
V_4 = F_149 ( V_24 -> V_149 , V_146 , V_144 ,
& V_148 ) ;
if ( F_71 ( V_4 ) )
return V_4 ;
if ( V_148 & V_150 )
* V_12 |= V_151 ;
return V_4 ;
}
static struct V_1 * F_148 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_12 )
{
return F_8 ( - V_54 ) ;
}
static struct V_1 * F_150 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_12 )
{
struct V_152 V_153 ;
struct V_1 * V_4 ;
V_4 = F_151 ( V_24 , V_144 , & V_153 ) ;
if ( F_71 ( V_4 ) )
return V_4 ;
if ( V_153 . V_154 && V_153 . V_155 )
* V_12 |= V_151 ;
return V_4 ;
}
static struct V_139 * F_152 ( struct V_23 * V_24 )
{
const char * V_156 = V_24 ? F_153 ( V_24 ) : NULL ;
struct V_139 * V_140 ;
F_24 ( & V_141 ) ;
F_88 (table, &gpio_lookup_list, list) {
if ( V_140 -> V_156 && V_156 ) {
if ( ! strcmp ( V_140 -> V_156 , V_156 ) )
goto V_63;
} else {
if ( V_156 == V_140 -> V_156 )
goto V_63;
}
}
V_140 = NULL ;
V_63:
F_26 ( & V_141 ) ;
return V_140 ;
}
static struct V_1 * F_154 ( struct V_23 * V_24 , const char * V_143 ,
unsigned int V_144 ,
enum V_145 * V_12 )
{
struct V_1 * V_4 = F_8 ( - V_75 ) ;
struct V_139 * V_140 ;
struct V_157 * V_74 ;
V_140 = F_152 ( V_24 ) ;
if ( ! V_140 )
return V_4 ;
for ( V_74 = & V_140 -> V_140 [ 0 ] ; V_74 -> V_158 ; V_74 ++ ) {
struct V_7 * V_5 ;
if ( V_74 -> V_144 != V_144 )
continue;
if ( V_74 -> V_143 && ( ! V_143 || strcmp ( V_74 -> V_143 , V_143 ) ) )
continue;
V_5 = F_107 ( V_74 -> V_158 ) ;
if ( ! V_5 ) {
F_92 ( V_24 , L_47 ,
V_74 -> V_158 ) ;
return F_8 ( - V_54 ) ;
}
if ( V_5 -> V_9 <= V_74 -> V_159 ) {
F_92 ( V_24 ,
L_48 ,
V_144 , V_5 -> V_9 , V_5 -> V_3 ) ;
return F_8 ( - V_10 ) ;
}
V_4 = F_7 ( V_5 , V_74 -> V_159 ) ;
* V_12 = V_74 -> V_12 ;
return V_4 ;
}
return V_4 ;
}
struct V_1 * T_5 F_155 ( struct V_23 * V_24 , const char * V_143 )
{
return F_156 ( V_24 , V_143 , 0 ) ;
}
struct V_1 * T_5 F_156 ( struct V_23 * V_24 ,
const char * V_143 ,
unsigned int V_144 )
{
struct V_1 * V_4 = NULL ;
int V_20 ;
enum V_145 V_12 = 0 ;
F_157 ( V_24 , L_49 , V_143 ) ;
if ( F_158 ( V_160 ) && V_24 && V_24 -> V_149 ) {
F_157 ( V_24 , L_50 ) ;
V_4 = F_148 ( V_24 , V_143 , V_144 , & V_12 ) ;
} else if ( F_158 ( V_161 ) && V_24 && F_159 ( V_24 ) ) {
F_157 ( V_24 , L_51 ) ;
V_4 = F_150 ( V_24 , V_143 , V_144 , & V_12 ) ;
}
if ( ! V_4 || V_4 == F_8 ( - V_75 ) ) {
F_157 ( V_24 , L_52 ) ;
V_4 = F_154 ( V_24 , V_143 , V_144 , & V_12 ) ;
}
if ( F_71 ( V_4 ) ) {
F_157 ( V_24 , L_53 , V_143 ) ;
return V_4 ;
}
V_20 = F_61 ( V_4 , V_143 ) ;
if ( V_20 < 0 )
return F_8 ( V_20 ) ;
if ( V_12 & V_151 )
F_21 ( V_48 , & V_4 -> V_12 ) ;
if ( V_12 & V_162 )
F_21 ( V_118 , & V_4 -> V_12 ) ;
if ( V_12 & V_163 )
F_21 ( V_119 , & V_4 -> V_12 ) ;
return V_4 ;
}
void F_160 ( struct V_1 * V_4 )
{
F_63 ( V_4 ) ;
}
static void F_161 ( struct V_164 * V_165 , struct V_7 * V_5 )
{
unsigned V_60 ;
unsigned V_6 = V_5 -> V_17 ;
struct V_1 * V_166 = & V_5 -> V_4 [ 0 ] ;
int V_167 ;
int V_168 ;
for ( V_60 = 0 ; V_60 < V_5 -> V_9 ; V_60 ++ , V_6 ++ , V_166 ++ ) {
if ( ! F_25 ( V_11 , & V_166 -> V_12 ) )
continue;
F_20 ( V_166 ) ;
V_167 = F_25 ( V_22 , & V_166 -> V_12 ) ;
V_168 = F_25 ( V_132 , & V_166 -> V_12 ) ;
F_162 ( V_165 , L_54 ,
V_6 , V_166 -> V_3 ,
V_167 ? L_8 : L_55 ,
V_5 -> V_130
? ( V_5 -> V_130 ( V_5 , V_60 ) ? L_56 : L_57 )
: L_58 ,
V_168 ? L_59 : L_60 ) ;
F_162 ( V_165 , L_61 ) ;
}
}
static void * F_163 ( struct V_164 * V_165 , T_6 * V_91 )
{
unsigned long V_12 ;
struct V_7 * V_5 = NULL ;
T_6 V_169 = * V_91 ;
V_165 -> V_170 = L_16 ;
F_66 ( & V_76 , V_12 ) ;
F_88 (chip, &gpio_chips, list)
if ( V_169 -- == 0 ) {
F_67 ( & V_76 , V_12 ) ;
return V_5 ;
}
F_67 ( & V_76 , V_12 ) ;
return NULL ;
}
static void * F_164 ( struct V_164 * V_165 , void * V_171 , T_6 * V_91 )
{
unsigned long V_12 ;
struct V_7 * V_5 = V_171 ;
void * V_40 = NULL ;
F_66 ( & V_76 , V_12 ) ;
if ( F_165 ( & V_5 -> V_95 , & V_92 ) )
V_40 = NULL ;
else
V_40 = F_91 ( V_5 -> V_95 . V_172 , struct V_7 , V_95 ) ;
F_67 ( & V_76 , V_12 ) ;
V_165 -> V_170 = L_61 ;
++ * V_91 ;
return V_40 ;
}
static void F_166 ( struct V_164 * V_165 , void * V_171 )
{
}
static int F_167 ( struct V_164 * V_165 , void * V_171 )
{
struct V_7 * V_5 = V_171 ;
struct V_23 * V_24 ;
F_162 ( V_165 , L_62 , ( char * ) V_165 -> V_170 ,
V_5 -> V_17 , V_5 -> V_17 + V_5 -> V_9 - 1 ) ;
V_24 = V_5 -> V_24 ;
if ( V_24 )
F_162 ( V_165 , L_63 , V_24 -> V_173 ? V_24 -> V_173 -> V_62 : L_64 ,
F_153 ( V_24 ) ) ;
if ( V_5 -> V_3 )
F_162 ( V_165 , L_65 , V_5 -> V_3 ) ;
if ( V_5 -> V_117 )
F_162 ( V_165 , L_66 ) ;
F_162 ( V_165 , L_67 ) ;
if ( V_5 -> V_174 )
V_5 -> V_174 ( V_165 , V_5 ) ;
else
F_161 ( V_165 , V_5 ) ;
return 0 ;
}
static int F_168 ( struct V_175 * V_175 , struct V_176 * V_176 )
{
return F_169 ( V_176 , & V_177 ) ;
}
static int T_4 F_170 ( void )
{
( void ) F_171 ( L_68 , V_178 | V_179 ,
NULL , NULL , & V_180 ) ;
return 0 ;
}
