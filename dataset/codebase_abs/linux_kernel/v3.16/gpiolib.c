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
struct V_1 * F_7 ( struct V_7 * V_5 ,
T_1 V_8 )
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
unsigned V_20 ;
int V_21 = - V_10 ;
V_5 = F_15 ( V_4 ) ;
V_20 = F_3 ( V_4 ) ;
if ( ! V_5 -> V_22 )
return V_21 ;
V_21 = V_5 -> V_22 ( V_5 , V_20 ) ;
if ( V_21 > 0 ) {
V_21 = 1 ;
F_14 ( V_23 , & ( (struct V_1 * ) V_4 ) -> V_12 ) ;
}
if ( V_21 == 0 ) {
F_21 ( V_23 , & ( (struct V_1 * ) V_4 ) -> V_12 ) ;
}
return V_21 ;
}
static T_2 F_22 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
const struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) ) {
V_21 = - V_15 ;
} else {
F_20 ( V_4 ) ;
V_21 = sprintf ( V_28 , L_7 ,
F_25 ( V_23 , & V_4 -> V_12 )
? L_8 : L_9 ) ;
}
F_26 ( & V_29 ) ;
return V_21 ;
}
static T_2 F_27 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_3 V_31 )
{
struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) )
V_21 = - V_15 ;
else if ( F_28 ( V_28 , L_10 ) )
V_21 = F_29 ( V_4 , 1 ) ;
else if ( F_28 ( V_28 , L_8 ) || F_28 ( V_28 , L_11 ) )
V_21 = F_29 ( V_4 , 0 ) ;
else if ( F_28 ( V_28 , L_9 ) )
V_21 = F_30 ( V_4 ) ;
else
V_21 = - V_10 ;
F_26 ( & V_29 ) ;
return V_21 ? : V_31 ;
}
static T_2 F_31 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) )
V_21 = - V_15 ;
else
V_21 = sprintf ( V_28 , L_12 , F_32 ( V_4 ) ) ;
F_26 ( & V_29 ) ;
return V_21 ;
}
static T_2 F_33 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_3 V_31 )
{
struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) )
V_21 = - V_15 ;
else if ( ! F_25 ( V_23 , & V_4 -> V_12 ) )
V_21 = - V_32 ;
else {
long V_33 ;
V_21 = F_34 ( V_28 , 0 , & V_33 ) ;
if ( V_21 == 0 ) {
F_35 ( V_4 , V_33 ) ;
V_21 = V_31 ;
}
}
F_26 ( & V_29 ) ;
return V_21 ;
}
static T_4 F_36 ( int V_34 , void * V_35 )
{
struct V_36 * V_37 = V_35 ;
F_37 ( V_37 ) ;
return V_38 ;
}
static int F_38 ( struct V_1 * V_4 , struct V_24 * V_25 ,
unsigned long V_39 )
{
struct V_36 * V_37 ;
unsigned long V_40 ;
int V_41 , V_34 , V_42 ;
if ( ( V_4 -> V_12 & V_43 ) == V_39 )
return 0 ;
V_34 = F_39 ( V_4 ) ;
if ( V_34 < 0 )
return - V_15 ;
V_42 = V_4 -> V_12 >> V_44 ;
V_37 = F_40 ( & V_45 , V_42 ) ;
if ( V_37 )
F_41 ( V_34 , V_37 ) ;
V_4 -> V_12 &= ~ V_43 ;
if ( ! V_39 ) {
F_42 ( V_4 ) ;
V_41 = 0 ;
goto V_46;
}
V_40 = V_47 ;
if ( F_25 ( V_48 , & V_39 ) )
V_40 |= F_25 ( V_49 , & V_4 -> V_12 ) ?
V_50 : V_51 ;
if ( F_25 ( V_52 , & V_39 ) )
V_40 |= F_25 ( V_49 , & V_4 -> V_12 ) ?
V_51 : V_50 ;
if ( ! V_37 ) {
V_37 = F_43 ( V_25 -> V_53 . V_54 , L_13 ) ;
if ( ! V_37 ) {
V_41 = - V_55 ;
goto V_56;
}
V_41 = F_44 ( & V_45 , V_37 , 1 , 0 , V_57 ) ;
if ( V_41 < 0 )
goto V_58;
V_42 = V_41 ;
V_4 -> V_12 &= V_59 ;
V_4 -> V_12 |= ( unsigned long ) V_42 << V_44 ;
if ( V_4 -> V_12 >> V_44 != V_42 ) {
V_41 = - V_60 ;
goto V_46;
}
}
V_41 = F_45 ( V_34 , F_36 , V_40 ,
L_14 , V_37 ) ;
if ( V_41 < 0 )
goto V_46;
V_41 = F_46 ( V_4 ) ;
if ( V_41 < 0 ) {
F_47 ( V_4 , L_15 ) ;
goto V_46;
}
V_4 -> V_12 |= V_39 ;
return 0 ;
V_46:
F_48 ( & V_45 , V_42 ) ;
V_4 -> V_12 &= V_59 ;
V_58:
if ( V_37 )
F_49 ( V_37 ) ;
V_56:
return V_41 ;
}
static T_2 F_50 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
const struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) )
V_21 = - V_15 ;
else {
int V_61 ;
V_21 = 0 ;
for ( V_61 = 0 ; V_61 < F_51 ( V_62 ) ; V_61 ++ )
if ( ( V_4 -> V_12 & V_43 )
== V_62 [ V_61 ] . V_12 ) {
V_21 = sprintf ( V_28 , L_7 ,
V_62 [ V_61 ] . V_63 ) ;
break;
}
}
F_26 ( & V_29 ) ;
return V_21 ;
}
static T_2 F_52 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_3 V_31 )
{
struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_51 ( V_62 ) ; V_61 ++ )
if ( F_28 ( V_62 [ V_61 ] . V_63 , V_28 ) )
goto V_64;
return - V_10 ;
V_64:
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) )
V_21 = - V_15 ;
else {
V_21 = F_38 ( V_4 , V_25 , V_62 [ V_61 ] . V_12 ) ;
if ( ! V_21 )
V_21 = V_31 ;
}
F_26 ( & V_29 ) ;
return V_21 ;
}
static int F_53 ( struct V_1 * V_4 , struct V_24 * V_25 ,
int V_33 )
{
int V_21 = 0 ;
if ( ! ! F_25 ( V_49 , & V_4 -> V_12 ) == ! ! V_33 )
return 0 ;
if ( V_33 )
F_21 ( V_49 , & V_4 -> V_12 ) ;
else
F_14 ( V_49 , & V_4 -> V_12 ) ;
if ( V_25 != NULL && ( ! ! F_25 ( V_52 , & V_4 -> V_12 ) ^
! ! F_25 ( V_48 , & V_4 -> V_12 ) ) ) {
unsigned long V_65 = V_4 -> V_12 & V_43 ;
F_38 ( V_4 , V_25 , 0 ) ;
V_21 = F_38 ( V_4 , V_25 , V_65 ) ;
}
return V_21 ;
}
static T_2 F_54 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
const struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) )
V_21 = - V_15 ;
else
V_21 = sprintf ( V_28 , L_12 ,
! ! F_25 ( V_49 , & V_4 -> V_12 ) ) ;
F_26 ( & V_29 ) ;
return V_21 ;
}
static T_2 F_55 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_3 V_31 )
{
struct V_1 * V_4 = F_23 ( V_25 ) ;
T_2 V_21 ;
F_24 ( & V_29 ) ;
if ( ! F_25 ( V_30 , & V_4 -> V_12 ) ) {
V_21 = - V_15 ;
} else {
long V_33 ;
V_21 = F_34 ( V_28 , 0 , & V_33 ) ;
if ( V_21 == 0 )
V_21 = F_53 ( V_4 , V_25 , V_33 != 0 ) ;
}
F_26 ( & V_29 ) ;
return V_21 ? : V_31 ;
}
static T_2 F_56 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
const struct V_7 * V_5 = F_23 ( V_25 ) ;
return sprintf ( V_28 , L_12 , V_5 -> V_17 ) ;
}
static T_2 F_57 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
const struct V_7 * V_5 = F_23 ( V_25 ) ;
return sprintf ( V_28 , L_7 , V_5 -> V_3 ? : L_16 ) ;
}
static T_2 F_58 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
const struct V_7 * V_5 = F_23 ( V_25 ) ;
return sprintf ( V_28 , L_17 , V_5 -> V_9 ) ;
}
static T_2 F_59 ( struct V_66 * V_66 ,
struct V_67 * V_27 ,
const char * V_28 , T_3 V_68 )
{
long V_6 ;
struct V_1 * V_4 ;
int V_21 ;
V_21 = F_34 ( V_28 , 0 , & V_6 ) ;
if ( V_21 < 0 )
goto V_69;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
F_60 ( L_18 , V_14 , V_6 ) ;
return - V_10 ;
}
V_21 = F_61 ( V_4 , L_19 ) ;
if ( V_21 < 0 ) {
if ( V_21 == - V_70 )
V_21 = - V_55 ;
goto V_69;
}
V_21 = F_62 ( V_4 , true ) ;
if ( V_21 < 0 )
F_63 ( V_4 ) ;
else
F_21 ( V_71 , & V_4 -> V_12 ) ;
V_69:
if ( V_21 )
F_18 ( L_20 , V_14 , V_21 ) ;
return V_21 ? : V_68 ;
}
static T_2 F_64 ( struct V_66 * V_66 ,
struct V_67 * V_27 ,
const char * V_28 , T_3 V_68 )
{
long V_6 ;
struct V_1 * V_4 ;
int V_21 ;
V_21 = F_34 ( V_28 , 0 , & V_6 ) ;
if ( V_21 < 0 )
goto V_69;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
F_60 ( L_18 , V_14 , V_6 ) ;
return - V_10 ;
}
V_21 = - V_10 ;
if ( F_65 ( V_71 , & V_4 -> V_12 ) ) {
V_21 = 0 ;
F_63 ( V_4 ) ;
}
V_69:
if ( V_21 )
F_18 ( L_20 , V_14 , V_21 ) ;
return V_21 ? : V_68 ;
}
int F_62 ( struct V_1 * V_4 , bool V_72 )
{
unsigned long V_12 ;
int V_21 ;
const char * V_73 = NULL ;
struct V_24 * V_25 ;
int V_20 ;
if ( ! V_74 . V_75 ) {
F_18 ( L_21 , V_14 ) ;
return - V_76 ;
}
if ( ! V_4 ) {
F_18 ( L_22 , V_14 ) ;
return - V_10 ;
}
F_24 ( & V_29 ) ;
F_66 ( & V_77 , V_12 ) ;
if ( ! F_25 ( V_11 , & V_4 -> V_12 ) ||
F_25 ( V_30 , & V_4 -> V_12 ) ) {
F_67 ( & V_77 , V_12 ) ;
F_68 ( V_4 , L_23 ,
V_14 ,
F_25 ( V_11 , & V_4 -> V_12 ) ,
F_25 ( V_30 , & V_4 -> V_12 ) ) ;
V_21 = - V_32 ;
goto V_78;
}
if ( ! V_4 -> V_5 -> V_79 || ! V_4 -> V_5 -> V_80 )
V_72 = false ;
F_67 ( & V_77 , V_12 ) ;
V_20 = F_3 ( V_4 ) ;
if ( V_4 -> V_5 -> V_81 && V_4 -> V_5 -> V_81 [ V_20 ] )
V_73 = V_4 -> V_5 -> V_81 [ V_20 ] ;
V_25 = F_69 ( & V_74 , V_4 -> V_5 -> V_25 , F_70 ( 0 , 0 ) ,
V_4 , V_73 ? V_73 : L_24 ,
F_9 ( V_4 ) ) ;
if ( F_71 ( V_25 ) ) {
V_21 = F_72 ( V_25 ) ;
goto V_78;
}
V_21 = F_73 ( & V_25 -> V_53 , & V_82 ) ;
if ( V_21 )
goto V_83;
if ( V_72 ) {
V_21 = F_74 ( V_25 , & V_84 ) ;
if ( V_21 )
goto V_83;
}
if ( F_39 ( V_4 ) >= 0 && ( V_72 ||
! F_25 ( V_23 , & V_4 -> V_12 ) ) ) {
V_21 = F_74 ( V_25 , & V_85 ) ;
if ( V_21 )
goto V_83;
}
F_21 ( V_30 , & V_4 -> V_12 ) ;
F_26 ( & V_29 ) ;
return 0 ;
V_83:
F_75 ( V_25 ) ;
V_78:
F_26 ( & V_29 ) ;
F_68 ( V_4 , L_20 , V_14 , V_21 ) ;
return V_21 ;
}
static int F_76 ( struct V_24 * V_25 , const void * V_86 )
{
return F_23 ( V_25 ) == V_86 ;
}
int F_77 ( struct V_24 * V_25 , const char * V_63 ,
struct V_1 * V_4 )
{
int V_21 = - V_10 ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
F_24 ( & V_29 ) ;
if ( F_25 ( V_30 , & V_4 -> V_12 ) ) {
struct V_24 * V_87 ;
V_87 = F_78 ( & V_74 , NULL , V_4 , F_76 ) ;
if ( V_87 != NULL ) {
V_21 = F_79 ( & V_25 -> V_53 , & V_87 -> V_53 ,
V_63 ) ;
} else {
V_21 = - V_55 ;
}
}
F_26 ( & V_29 ) ;
if ( V_21 )
F_68 ( V_4 , L_20 , V_14 , V_21 ) ;
return V_21 ;
}
int F_80 ( struct V_1 * V_4 , int V_33 )
{
struct V_24 * V_25 = NULL ;
int V_21 = - V_10 ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
F_24 ( & V_29 ) ;
if ( F_25 ( V_30 , & V_4 -> V_12 ) ) {
V_25 = F_78 ( & V_74 , NULL , V_4 , F_76 ) ;
if ( V_25 == NULL ) {
V_21 = - V_55 ;
goto V_88;
}
}
V_21 = F_53 ( V_4 , V_25 , V_33 ) ;
V_88:
F_26 ( & V_29 ) ;
if ( V_21 )
F_68 ( V_4 , L_20 , V_14 , V_21 ) ;
return V_21 ;
}
void F_81 ( struct V_1 * V_4 )
{
int V_21 = 0 ;
struct V_24 * V_25 = NULL ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return;
}
F_24 ( & V_29 ) ;
if ( F_25 ( V_30 , & V_4 -> V_12 ) ) {
V_25 = F_78 ( & V_74 , NULL , V_4 , F_76 ) ;
if ( V_25 ) {
F_38 ( V_4 , V_25 , 0 ) ;
F_14 ( V_30 , & V_4 -> V_12 ) ;
} else
V_21 = - V_55 ;
}
F_26 ( & V_29 ) ;
if ( V_25 ) {
F_75 ( V_25 ) ;
F_82 ( V_25 ) ;
}
if ( V_21 )
F_68 ( V_4 , L_20 , V_14 , V_21 ) ;
}
static int F_83 ( struct V_7 * V_5 )
{
int V_21 ;
struct V_24 * V_25 ;
if ( ! V_74 . V_75 )
return 0 ;
F_24 ( & V_29 ) ;
V_25 = F_69 ( & V_74 , V_5 -> V_25 , F_70 ( 0 , 0 ) , V_5 ,
L_26 , V_5 -> V_17 ) ;
if ( ! F_71 ( V_25 ) ) {
V_21 = F_73 ( & V_25 -> V_53 ,
& V_89 ) ;
} else
V_21 = F_72 ( V_25 ) ;
V_5 -> V_90 = ( V_21 == 0 ) ;
F_26 ( & V_29 ) ;
if ( V_21 ) {
unsigned long V_12 ;
unsigned V_6 ;
F_66 ( & V_77 , V_12 ) ;
V_6 = 0 ;
while ( V_6 < V_5 -> V_9 )
V_5 -> V_4 [ V_6 ++ ] . V_5 = NULL ;
F_67 ( & V_77 , V_12 ) ;
F_84 ( V_5 , L_20 , V_14 , V_21 ) ;
}
return V_21 ;
}
static void F_85 ( struct V_7 * V_5 )
{
int V_21 ;
struct V_24 * V_25 ;
F_24 ( & V_29 ) ;
V_25 = F_78 ( & V_74 , NULL , V_5 , F_76 ) ;
if ( V_25 ) {
F_82 ( V_25 ) ;
F_75 ( V_25 ) ;
V_5 -> V_90 = false ;
V_21 = 0 ;
} else
V_21 = - V_55 ;
F_26 ( & V_29 ) ;
if ( V_21 )
F_84 ( V_5 , L_20 , V_14 , V_21 ) ;
}
static int T_5 F_86 ( void )
{
int V_21 ;
unsigned long V_12 ;
struct V_7 * V_5 ;
V_21 = F_87 ( & V_74 ) ;
if ( V_21 < 0 )
return V_21 ;
F_66 ( & V_77 , V_12 ) ;
F_88 (chip, &gpio_chips, list) {
if ( ! V_5 || V_5 -> V_90 )
continue;
F_67 ( & V_77 , V_12 ) ;
V_21 = F_83 ( V_5 ) ;
F_66 ( & V_77 , V_12 ) ;
}
F_67 ( & V_77 , V_12 ) ;
return V_21 ;
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
struct V_91 * V_92 = & V_93 ;
struct V_7 * V_94 ;
int V_95 = 0 ;
F_90 (pos, &gpio_chips) {
V_94 = F_91 ( V_92 , struct V_7 , V_96 ) ;
if ( V_94 -> V_17 >= V_5 -> V_17 + V_5 -> V_9 )
break;
}
if ( V_92 != & V_93 && V_92 -> V_97 != & V_93 ) {
V_94 = F_91 ( V_92 -> V_97 , struct V_7 , V_96 ) ;
if ( V_94 -> V_17 + V_94 -> V_9 > V_5 -> V_17 ) {
F_92 ( V_5 -> V_25 ,
L_27 ) ;
V_95 = - V_98 ;
}
}
if ( ! V_95 )
F_93 ( & V_5 -> V_96 , V_92 ) ;
return V_95 ;
}
int F_94 ( struct V_7 * V_5 )
{
unsigned long V_12 ;
int V_21 = 0 ;
unsigned V_42 ;
int V_17 = V_5 -> V_17 ;
if ( ( ! F_6 ( V_17 ) || ! F_6 ( V_17 + V_5 -> V_9 - 1 ) )
&& V_17 >= 0 ) {
V_21 = - V_10 ;
goto V_99;
}
F_66 ( & V_77 , V_12 ) ;
if ( V_17 < 0 ) {
V_17 = F_16 ( V_5 -> V_9 ) ;
if ( V_17 < 0 ) {
V_21 = V_17 ;
goto V_88;
}
V_5 -> V_17 = V_17 ;
}
V_21 = F_89 ( V_5 ) ;
if ( V_21 == 0 ) {
V_5 -> V_4 = & V_1 [ V_5 -> V_17 ] ;
for ( V_42 = 0 ; V_42 < V_5 -> V_9 ; V_42 ++ ) {
struct V_1 * V_4 = & V_5 -> V_4 [ V_42 ] ;
V_4 -> V_5 = V_5 ;
V_4 -> V_12 = ! V_5 -> V_79
? ( 1 << V_23 )
: 0 ;
}
}
F_67 ( & V_77 , V_12 ) ;
#ifdef F_95
F_96 ( & V_5 -> V_100 ) ;
#endif
F_97 ( V_5 ) ;
F_98 ( V_5 ) ;
if ( V_21 )
goto V_99;
V_21 = F_83 ( V_5 ) ;
if ( V_21 )
goto V_99;
F_18 ( L_28 , V_14 ,
V_5 -> V_17 , V_5 -> V_17 + V_5 -> V_9 - 1 ,
V_5 -> V_3 ? : L_29 ) ;
return 0 ;
V_88:
F_67 ( & V_77 , V_12 ) ;
V_99:
F_19 ( L_30 , V_14 ,
V_5 -> V_17 , V_5 -> V_17 + V_5 -> V_9 - 1 ,
V_5 -> V_3 ? : L_29 ) ;
return V_21 ;
}
int F_99 ( struct V_7 * V_5 )
{
unsigned long V_12 ;
int V_21 = 0 ;
unsigned V_42 ;
F_100 ( V_5 ) ;
F_66 ( & V_77 , V_12 ) ;
F_101 ( V_5 ) ;
F_102 ( V_5 ) ;
F_103 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_9 ; V_42 ++ ) {
if ( F_25 ( V_11 , & V_5 -> V_4 [ V_42 ] . V_12 ) ) {
V_21 = - V_98 ;
break;
}
}
if ( V_21 == 0 ) {
for ( V_42 = 0 ; V_42 < V_5 -> V_9 ; V_42 ++ )
V_5 -> V_4 [ V_42 ] . V_5 = NULL ;
F_104 ( & V_5 -> V_96 ) ;
}
F_67 ( & V_77 , V_12 ) ;
if ( V_21 == 0 )
F_85 ( V_5 ) ;
return V_21 ;
}
struct V_7 * F_105 ( void * V_86 ,
int (* F_106)( struct V_7 * V_5 ,
void * V_86 ) )
{
struct V_7 * V_5 ;
unsigned long V_12 ;
F_66 ( & V_77 , V_12 ) ;
F_88 (chip, &gpio_chips, list)
if ( F_106 ( V_5 , V_86 ) )
break;
if ( & V_5 -> V_96 == & V_93 )
V_5 = NULL ;
F_67 ( & V_77 , V_12 ) ;
return V_5 ;
}
static int F_107 ( struct V_7 * V_5 , void * V_86 )
{
const char * V_63 = V_86 ;
return ! strcmp ( V_5 -> V_3 , V_63 ) ;
}
static struct V_7 * F_108 ( const char * V_63 )
{
return F_105 ( ( void * ) V_63 , F_107 ) ;
}
void F_109 ( struct V_7 * V_101 ,
struct V_102 * V_103 ,
int V_104 ,
T_6 V_105 )
{
if ( V_101 -> V_106 ) {
F_110 ( V_101 , L_31 ) ;
return;
}
F_111 ( V_104 , V_105 ) ;
F_112 ( V_104 , V_101 ) ;
}
static int F_113 ( struct V_107 * V_2 , unsigned int V_34 ,
T_7 V_108 )
{
struct V_7 * V_5 = V_2 -> V_109 ;
F_114 ( V_34 , V_5 ) ;
F_115 ( V_34 , & V_110 ) ;
F_116 ( V_34 , V_5 -> V_103 , V_5 -> V_111 ) ;
if ( V_5 -> V_106 )
F_117 ( V_34 , 1 ) ;
#ifdef F_118
F_119 ( V_34 , V_112 ) ;
#else
F_120 ( V_34 ) ;
#endif
if ( V_5 -> V_113 != V_114 )
F_121 ( V_34 , V_5 -> V_113 ) ;
return 0 ;
}
static void F_122 ( struct V_107 * V_2 , unsigned int V_34 )
{
struct V_7 * V_5 = V_2 -> V_109 ;
#ifdef F_118
F_119 ( V_34 , 0 ) ;
#endif
if ( V_5 -> V_106 )
F_117 ( V_34 , 0 ) ;
F_116 ( V_34 , NULL , NULL ) ;
F_114 ( V_34 , NULL ) ;
}
static int F_123 ( struct V_115 * V_2 )
{
struct V_7 * V_5 = F_124 ( V_2 ) ;
if ( F_125 ( V_5 , V_2 -> V_108 ) ) {
F_110 ( V_5 ,
L_32 ,
V_2 -> V_108 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_126 ( struct V_115 * V_2 )
{
struct V_7 * V_5 = F_124 ( V_2 ) ;
F_127 ( V_5 , V_2 -> V_108 ) ;
}
static int F_128 ( struct V_7 * V_5 , unsigned V_20 )
{
return F_129 ( V_5 -> V_116 , V_20 ) ;
}
static void F_101 ( struct V_7 * V_101 )
{
unsigned int V_20 ;
if ( V_101 -> V_116 ) {
for ( V_20 = 0 ; V_20 < V_101 -> V_9 ; V_20 ++ )
F_130 ( V_101 -> V_117 + V_20 ) ;
F_131 ( V_101 -> V_116 ) ;
}
if ( V_101 -> V_103 ) {
V_101 -> V_103 -> V_118 = NULL ;
V_101 -> V_103 -> V_119 = NULL ;
V_101 -> V_103 = NULL ;
}
}
int F_132 ( struct V_7 * V_101 ,
struct V_102 * V_103 ,
unsigned int V_120 ,
T_6 V_121 ,
unsigned int type )
{
struct V_122 * V_123 ;
unsigned int V_20 ;
unsigned V_117 = 0 ;
if ( ! V_101 || ! V_103 )
return - V_10 ;
if ( ! V_101 -> V_25 ) {
F_19 ( L_33 ) ;
return - V_10 ;
}
V_123 = V_101 -> V_25 -> V_123 ;
#ifdef F_133
if ( V_101 -> V_123 )
V_123 = V_101 -> V_123 ;
#endif
V_101 -> V_103 = V_103 ;
V_101 -> V_111 = V_121 ;
V_101 -> V_113 = type ;
V_101 -> V_124 = F_128 ;
V_101 -> V_116 = F_134 ( V_123 ,
V_101 -> V_9 , V_120 ,
& V_125 , V_101 ) ;
if ( ! V_101 -> V_116 ) {
V_101 -> V_103 = NULL ;
return - V_10 ;
}
V_103 -> V_118 = F_123 ;
V_103 -> V_119 = F_126 ;
for ( V_20 = 0 ; V_20 < V_101 -> V_9 ; V_20 ++ ) {
V_117 = F_135 ( V_101 -> V_116 , V_20 ) ;
if ( V_20 == 0 )
V_101 -> V_117 = V_117 ;
}
return 0 ;
}
static void F_101 ( struct V_7 * V_101 ) {}
int F_136 ( struct V_7 * V_5 ,
struct V_126 * V_127 ,
unsigned int V_128 , const char * V_129 )
{
struct V_130 * V_131 ;
int V_41 ;
V_131 = F_137 ( sizeof( * V_131 ) , V_57 ) ;
if ( ! V_131 ) {
F_110 ( V_5 , L_34 ) ;
return - V_132 ;
}
V_131 -> V_133 . V_42 = V_128 ;
V_131 -> V_133 . V_134 = V_5 ;
V_131 -> V_133 . V_63 = V_5 -> V_3 ;
V_131 -> V_133 . V_17 = V_5 -> V_17 + V_128 ;
V_131 -> V_127 = V_127 ;
V_41 = F_138 ( V_127 , V_129 ,
& V_131 -> V_133 . V_135 ,
& V_131 -> V_133 . V_136 ) ;
if ( V_41 < 0 ) {
F_139 ( V_131 ) ;
return V_41 ;
}
F_140 ( V_127 , & V_131 -> V_133 ) ;
F_84 ( V_5 , L_35 ,
V_128 , V_128 + V_131 -> V_133 . V_136 - 1 ,
F_141 ( V_127 ) , V_129 ) ;
F_93 ( & V_131 -> V_137 , & V_5 -> V_100 ) ;
return 0 ;
}
int F_142 ( struct V_7 * V_5 , const char * V_138 ,
unsigned int V_128 , unsigned int V_139 ,
unsigned int V_136 )
{
struct V_130 * V_131 ;
int V_41 ;
V_131 = F_137 ( sizeof( * V_131 ) , V_57 ) ;
if ( ! V_131 ) {
F_110 ( V_5 , L_34 ) ;
return - V_132 ;
}
V_131 -> V_133 . V_42 = V_128 ;
V_131 -> V_133 . V_134 = V_5 ;
V_131 -> V_133 . V_63 = V_5 -> V_3 ;
V_131 -> V_133 . V_17 = V_5 -> V_17 + V_128 ;
V_131 -> V_133 . V_140 = V_139 ;
V_131 -> V_133 . V_136 = V_136 ;
V_131 -> V_127 = F_143 ( V_138 ,
& V_131 -> V_133 ) ;
if ( F_71 ( V_131 -> V_127 ) ) {
V_41 = F_72 ( V_131 -> V_127 ) ;
F_110 ( V_5 , L_36 ) ;
F_139 ( V_131 ) ;
return V_41 ;
}
F_84 ( V_5 , L_37 ,
V_128 , V_128 + V_136 - 1 ,
V_138 ,
V_139 , V_139 + V_136 - 1 ) ;
F_93 ( & V_131 -> V_137 , & V_5 -> V_100 ) ;
return 0 ;
}
void F_102 ( struct V_7 * V_5 )
{
struct V_130 * V_131 , * V_141 ;
F_144 (pin_range, tmp, &chip->pin_ranges, node) {
F_104 ( & V_131 -> V_137 ) ;
F_145 ( V_131 -> V_127 ,
& V_131 -> V_133 ) ;
F_139 ( V_131 ) ;
}
}
static int F_146 ( struct V_1 * V_4 , const char * V_3 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
int V_21 ;
unsigned long V_12 ;
F_66 ( & V_77 , V_12 ) ;
if ( F_11 ( V_11 , & V_4 -> V_12 ) == 0 ) {
F_1 ( V_4 , V_3 ? : L_38 ) ;
V_21 = 0 ;
} else {
V_21 = - V_98 ;
goto V_69;
}
if ( V_5 -> V_16 ) {
F_67 ( & V_77 , V_12 ) ;
V_21 = V_5 -> V_16 ( V_5 , F_3 ( V_4 ) ) ;
F_66 ( & V_77 , V_12 ) ;
if ( V_21 < 0 ) {
F_1 ( V_4 , NULL ) ;
F_14 ( V_11 , & V_4 -> V_12 ) ;
goto V_69;
}
}
if ( V_5 -> V_22 ) {
F_67 ( & V_77 , V_12 ) ;
F_20 ( V_4 ) ;
F_66 ( & V_77 , V_12 ) ;
}
V_69:
F_67 ( & V_77 , V_12 ) ;
return V_21 ;
}
static int F_61 ( struct V_1 * V_4 , const char * V_3 )
{
int V_21 = - V_70 ;
struct V_7 * V_5 ;
if ( ! V_4 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 )
goto V_69;
if ( F_12 ( V_5 -> V_13 ) ) {
V_21 = F_146 ( V_4 , V_3 ) ;
if ( V_21 < 0 )
F_147 ( V_5 -> V_13 ) ;
}
V_69:
if ( V_21 )
F_68 ( V_4 , L_20 , V_14 , V_21 ) ;
return V_21 ;
}
int F_148 ( unsigned V_6 , const char * V_3 )
{
return F_61 ( F_4 ( V_6 ) , V_3 ) ;
}
static bool F_149 ( struct V_1 * V_4 )
{
bool V_41 = false ;
unsigned long V_12 ;
struct V_7 * V_5 ;
F_150 () ;
F_81 ( V_4 ) ;
F_66 ( & V_77 , V_12 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 && F_25 ( V_11 , & V_4 -> V_12 ) ) {
if ( V_5 -> free ) {
F_67 ( & V_77 , V_12 ) ;
F_151 ( V_5 -> V_106 ) ;
V_5 -> free ( V_5 , F_3 ( V_4 ) ) ;
F_66 ( & V_77 , V_12 ) ;
}
F_1 ( V_4 , NULL ) ;
F_14 ( V_49 , & V_4 -> V_12 ) ;
F_14 ( V_11 , & V_4 -> V_12 ) ;
F_14 ( V_142 , & V_4 -> V_12 ) ;
F_14 ( V_143 , & V_4 -> V_12 ) ;
V_41 = true ;
}
F_67 ( & V_77 , V_12 ) ;
return V_41 ;
}
static void F_63 ( struct V_1 * V_4 )
{
if ( V_4 && F_149 ( V_4 ) )
F_147 ( V_4 -> V_5 -> V_13 ) ;
else
F_152 ( V_144 ) ;
}
void F_153 ( unsigned V_6 )
{
F_63 ( F_4 ( V_6 ) ) ;
}
int F_154 ( unsigned V_6 , unsigned long V_12 , const char * V_3 )
{
struct V_1 * V_4 ;
int V_95 ;
V_4 = F_4 ( V_6 ) ;
V_95 = F_61 ( V_4 , V_3 ) ;
if ( V_95 )
return V_95 ;
if ( V_12 & V_145 )
F_21 ( V_142 , & V_4 -> V_12 ) ;
if ( V_12 & V_146 )
F_21 ( V_143 , & V_4 -> V_12 ) ;
if ( V_12 & V_147 )
V_95 = F_30 ( V_4 ) ;
else
V_95 = F_29 ( V_4 ,
( V_12 & V_148 ) ? 1 : 0 ) ;
if ( V_95 )
goto V_149;
if ( V_12 & V_150 ) {
V_95 = F_62 ( V_4 , V_12 & V_151 ) ;
if ( V_95 )
goto V_149;
}
return 0 ;
V_149:
F_63 ( V_4 ) ;
return V_95 ;
}
int F_155 ( const struct V_6 * V_152 , T_3 V_153 )
{
int V_61 , V_95 ;
for ( V_61 = 0 ; V_61 < V_153 ; V_61 ++ , V_152 ++ ) {
V_95 = F_154 ( V_152 -> V_6 , V_152 -> V_12 , V_152 -> V_3 ) ;
if ( V_95 )
goto V_154;
}
return 0 ;
V_154:
while ( V_61 -- )
F_153 ( ( -- V_152 ) -> V_6 ) ;
return V_95 ;
}
void F_156 ( const struct V_6 * V_152 , T_3 V_153 )
{
while ( V_153 -- )
F_153 ( ( V_152 ++ ) -> V_6 ) ;
}
const char * F_157 ( struct V_7 * V_5 , unsigned V_20 )
{
struct V_1 * V_4 ;
if ( ! F_158 ( V_5 , V_20 ) )
return NULL ;
V_4 = & V_5 -> V_4 [ V_20 ] ;
if ( F_25 ( V_11 , & V_4 -> V_12 ) == 0 )
return NULL ;
#ifdef F_2
return V_4 -> V_3 ;
#else
return L_38 ;
#endif
}
int F_159 ( struct V_1 * V_4 , const char * V_3 )
{
if ( ! V_4 || ! V_4 -> V_5 )
return - V_10 ;
return F_146 ( V_4 , V_3 ) ;
}
void F_160 ( struct V_1 * V_4 )
{
if ( V_4 )
F_149 ( V_4 ) ;
}
int F_30 ( struct V_1 * V_4 )
{
unsigned long V_12 ;
struct V_7 * V_5 ;
int V_21 = - V_10 ;
int V_20 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_155 || ! V_5 -> V_79 ) {
F_47 ( V_4 ,
L_39 ,
V_14 ) ;
return - V_15 ;
}
F_66 ( & V_77 , V_12 ) ;
V_21 = F_10 ( V_4 ) ;
if ( V_21 < 0 )
goto V_99;
F_67 ( & V_77 , V_12 ) ;
F_151 ( V_5 -> V_106 ) ;
V_20 = F_3 ( V_4 ) ;
if ( V_21 ) {
V_21 = V_5 -> V_16 ( V_5 , V_20 ) ;
if ( V_21 < 0 ) {
F_68 ( V_4 , L_40 ,
V_14 , V_21 ) ;
goto V_156;
}
}
V_21 = V_5 -> V_79 ( V_5 , V_20 ) ;
if ( V_21 == 0 )
F_14 ( V_23 , & V_4 -> V_12 ) ;
F_161 ( F_9 ( V_4 ) , 1 , V_21 ) ;
V_156:
return V_21 ;
V_99:
F_67 ( & V_77 , V_12 ) ;
if ( V_21 )
F_68 ( V_4 , L_20 , V_14 , V_21 ) ;
return V_21 ;
}
static int F_162 ( struct V_1 * V_4 , int V_33 )
{
unsigned long V_12 ;
struct V_7 * V_5 ;
int V_21 = - V_10 ;
int V_20 ;
if ( F_25 ( V_157 , & V_4 -> V_12 ) ) {
F_13 ( V_4 ,
L_41 ,
V_14 ) ;
return - V_15 ;
}
if ( V_33 && F_25 ( V_142 , & V_4 -> V_12 ) )
return F_30 ( V_4 ) ;
if ( ! V_33 && F_25 ( V_143 , & V_4 -> V_12 ) )
return F_30 ( V_4 ) ;
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_158 || ! V_5 -> V_80 ) {
F_47 ( V_4 ,
L_42 ,
V_14 ) ;
return - V_15 ;
}
F_66 ( & V_77 , V_12 ) ;
V_21 = F_10 ( V_4 ) ;
if ( V_21 < 0 )
goto V_99;
F_67 ( & V_77 , V_12 ) ;
F_151 ( V_5 -> V_106 ) ;
V_20 = F_3 ( V_4 ) ;
if ( V_21 ) {
V_21 = V_5 -> V_16 ( V_5 , V_20 ) ;
if ( V_21 < 0 ) {
F_68 ( V_4 , L_40 ,
V_14 , V_21 ) ;
goto V_156;
}
}
V_21 = V_5 -> V_80 ( V_5 , V_20 , V_33 ) ;
if ( V_21 == 0 )
F_21 ( V_23 , & V_4 -> V_12 ) ;
F_163 ( F_9 ( V_4 ) , 0 , V_33 ) ;
F_161 ( F_9 ( V_4 ) , 0 , V_21 ) ;
V_156:
return V_21 ;
V_99:
F_67 ( & V_77 , V_12 ) ;
if ( V_21 )
F_68 ( V_4 , L_43 , V_14 , V_21 ) ;
return V_21 ;
}
int F_29 ( struct V_1 * V_4 , int V_33 )
{
if ( ! V_4 || ! V_4 -> V_5 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
return F_162 ( V_4 , V_33 ) ;
}
int F_164 ( struct V_1 * V_4 , int V_33 )
{
if ( ! V_4 || ! V_4 -> V_5 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
if ( F_25 ( V_49 , & V_4 -> V_12 ) )
V_33 = ! V_33 ;
return F_162 ( V_4 , V_33 ) ;
}
int F_165 ( struct V_1 * V_4 , unsigned V_159 )
{
unsigned long V_12 ;
struct V_7 * V_5 ;
int V_21 = - V_10 ;
int V_20 ;
if ( ! V_4 || ! V_4 -> V_5 ) {
F_60 ( L_25 , V_14 ) ;
return - V_10 ;
}
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_158 || ! V_5 -> V_160 ) {
F_68 ( V_4 ,
L_44 ,
V_14 ) ;
return - V_161 ;
}
F_66 ( & V_77 , V_12 ) ;
V_21 = F_10 ( V_4 ) ;
if ( V_21 < 0 )
goto V_99;
F_67 ( & V_77 , V_12 ) ;
F_151 ( V_5 -> V_106 ) ;
V_20 = F_3 ( V_4 ) ;
return V_5 -> V_160 ( V_5 , V_20 , V_159 ) ;
V_99:
F_67 ( & V_77 , V_12 ) ;
if ( V_21 )
F_68 ( V_4 , L_20 , V_14 , V_21 ) ;
return V_21 ;
}
int F_166 ( const struct V_1 * V_4 )
{
return F_25 ( V_49 , & V_4 -> V_12 ) ;
}
static bool F_167 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
bool V_33 ;
int V_20 ;
V_5 = V_4 -> V_5 ;
V_20 = F_3 ( V_4 ) ;
V_33 = V_5 -> V_155 ? V_5 -> V_155 ( V_5 , V_20 ) : false ;
F_163 ( F_9 ( V_4 ) , 1 , V_33 ) ;
return V_33 ;
}
int F_168 ( const struct V_1 * V_4 )
{
if ( ! V_4 )
return 0 ;
F_152 ( V_4 -> V_5 -> V_106 ) ;
return F_167 ( V_4 ) ;
}
int F_169 ( const struct V_1 * V_4 )
{
int V_33 ;
if ( ! V_4 )
return 0 ;
F_152 ( V_4 -> V_5 -> V_106 ) ;
V_33 = F_167 ( V_4 ) ;
if ( F_25 ( V_49 , & V_4 -> V_12 ) )
V_33 = ! V_33 ;
return V_33 ;
}
static void F_170 ( struct V_1 * V_4 , bool V_33 )
{
int V_95 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_20 = F_3 ( V_4 ) ;
if ( V_33 ) {
V_95 = V_5 -> V_79 ( V_5 , V_20 ) ;
if ( ! V_95 )
F_14 ( V_23 , & V_4 -> V_12 ) ;
} else {
V_95 = V_5 -> V_80 ( V_5 , V_20 , 0 ) ;
if ( ! V_95 )
F_21 ( V_23 , & V_4 -> V_12 ) ;
}
F_161 ( F_9 ( V_4 ) , V_33 , V_95 ) ;
if ( V_95 < 0 )
F_13 ( V_4 ,
L_45 ,
V_14 , V_95 ) ;
}
static void F_171 ( struct V_1 * V_4 , bool V_33 )
{
int V_95 = 0 ;
struct V_7 * V_5 = V_4 -> V_5 ;
int V_20 = F_3 ( V_4 ) ;
if ( V_33 ) {
V_95 = V_5 -> V_80 ( V_5 , V_20 , 1 ) ;
if ( ! V_95 )
F_21 ( V_23 , & V_4 -> V_12 ) ;
} else {
V_95 = V_5 -> V_79 ( V_5 , V_20 ) ;
if ( ! V_95 )
F_14 ( V_23 , & V_4 -> V_12 ) ;
}
F_161 ( F_9 ( V_4 ) , ! V_33 , V_95 ) ;
if ( V_95 < 0 )
F_13 ( V_4 ,
L_46 ,
V_14 , V_95 ) ;
}
static void F_172 ( struct V_1 * V_4 , bool V_33 )
{
struct V_7 * V_5 ;
V_5 = V_4 -> V_5 ;
F_163 ( F_9 ( V_4 ) , 0 , V_33 ) ;
if ( F_25 ( V_142 , & V_4 -> V_12 ) )
F_170 ( V_4 , V_33 ) ;
else if ( F_25 ( V_143 , & V_4 -> V_12 ) )
F_171 ( V_4 , V_33 ) ;
else
V_5 -> V_158 ( V_5 , F_3 ( V_4 ) , V_33 ) ;
}
void F_173 ( struct V_1 * V_4 , int V_33 )
{
if ( ! V_4 )
return;
F_152 ( V_4 -> V_5 -> V_106 ) ;
F_172 ( V_4 , V_33 ) ;
}
void F_174 ( struct V_1 * V_4 , int V_33 )
{
if ( ! V_4 )
return;
F_152 ( V_4 -> V_5 -> V_106 ) ;
if ( F_25 ( V_49 , & V_4 -> V_12 ) )
V_33 = ! V_33 ;
F_172 ( V_4 , V_33 ) ;
}
int F_175 ( const struct V_1 * V_4 )
{
if ( ! V_4 )
return 0 ;
return V_4 -> V_5 -> V_106 ;
}
int F_39 ( const struct V_1 * V_4 )
{
struct V_7 * V_5 ;
int V_20 ;
if ( ! V_4 )
return - V_10 ;
V_5 = V_4 -> V_5 ;
V_20 = F_3 ( V_4 ) ;
return V_5 -> V_124 ? V_5 -> V_124 ( V_5 , V_20 ) : - V_162 ;
}
int F_46 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return - V_10 ;
if ( F_25 ( V_23 , & V_4 -> V_12 ) ) {
F_13 ( V_4 ,
L_47 ,
V_14 ) ;
return - V_15 ;
}
F_21 ( V_157 , & V_4 -> V_12 ) ;
return 0 ;
}
int F_125 ( struct V_7 * V_5 , unsigned int V_20 )
{
return F_46 ( F_7 ( V_5 , V_20 ) ) ;
}
void F_42 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_14 ( V_157 , & V_4 -> V_12 ) ;
}
void F_127 ( struct V_7 * V_5 , unsigned int V_20 )
{
return F_42 ( F_7 ( V_5 , V_20 ) ) ;
}
int F_176 ( const struct V_1 * V_4 )
{
F_151 ( V_144 ) ;
if ( ! V_4 )
return 0 ;
return F_167 ( V_4 ) ;
}
int F_32 ( const struct V_1 * V_4 )
{
int V_33 ;
F_151 ( V_144 ) ;
if ( ! V_4 )
return 0 ;
V_33 = F_167 ( V_4 ) ;
if ( F_25 ( V_49 , & V_4 -> V_12 ) )
V_33 = ! V_33 ;
return V_33 ;
}
void F_177 ( struct V_1 * V_4 , int V_33 )
{
F_151 ( V_144 ) ;
if ( ! V_4 )
return;
F_172 ( V_4 , V_33 ) ;
}
void F_35 ( struct V_1 * V_4 , int V_33 )
{
F_151 ( V_144 ) ;
if ( ! V_4 )
return;
if ( F_25 ( V_49 , & V_4 -> V_12 ) )
V_33 = ! V_33 ;
F_172 ( V_4 , V_33 ) ;
}
void F_178 ( struct V_163 * V_164 )
{
F_24 ( & V_165 ) ;
F_93 ( & V_164 -> V_96 , & V_166 ) ;
F_26 ( & V_165 ) ;
}
static struct V_1 * F_179 ( struct V_24 * V_25 , const char * V_167 ,
unsigned int V_168 ,
enum V_169 * V_12 )
{
static const char * V_170 [] = { L_48 , L_49 } ;
char V_171 [ 32 ] ;
enum V_172 V_173 ;
struct V_1 * V_4 ;
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < F_51 ( V_170 ) ; V_61 ++ ) {
if ( V_167 )
snprintf ( V_171 , 32 , L_50 , V_167 , V_170 [ V_61 ] ) ;
else
snprintf ( V_171 , 32 , L_51 , V_170 [ V_61 ] ) ;
V_4 = F_180 ( V_25 -> V_123 , V_171 , V_168 ,
& V_173 ) ;
if ( ! F_71 ( V_4 ) || ( F_72 ( V_4 ) == - V_70 ) )
break;
}
if ( F_71 ( V_4 ) )
return V_4 ;
if ( V_173 & V_174 )
* V_12 |= V_175 ;
return V_4 ;
}
static struct V_1 * F_181 ( struct V_24 * V_25 , const char * V_167 ,
unsigned int V_168 ,
enum V_169 * V_12 )
{
struct V_176 V_177 ;
struct V_1 * V_4 ;
V_4 = F_182 ( V_25 , V_168 , & V_177 ) ;
if ( F_71 ( V_4 ) )
return V_4 ;
if ( V_177 . V_178 && V_177 . V_179 )
* V_12 |= V_175 ;
return V_4 ;
}
static struct V_163 * F_183 ( struct V_24 * V_25 )
{
const char * V_180 = V_25 ? F_184 ( V_25 ) : NULL ;
struct V_163 * V_164 ;
F_24 ( & V_165 ) ;
F_88 (table, &gpio_lookup_list, list) {
if ( V_164 -> V_180 && V_180 ) {
if ( ! strcmp ( V_164 -> V_180 , V_180 ) )
goto V_64;
} else {
if ( V_180 == V_164 -> V_180 )
goto V_64;
}
}
V_164 = NULL ;
V_64:
F_26 ( & V_165 ) ;
return V_164 ;
}
static struct V_1 * F_185 ( struct V_24 * V_25 , const char * V_167 ,
unsigned int V_168 ,
enum V_169 * V_12 )
{
struct V_1 * V_4 = F_8 ( - V_76 ) ;
struct V_163 * V_164 ;
struct V_181 * V_75 ;
V_164 = F_183 ( V_25 ) ;
if ( ! V_164 )
return V_4 ;
for ( V_75 = & V_164 -> V_164 [ 0 ] ; V_75 -> V_182 ; V_75 ++ ) {
struct V_7 * V_5 ;
if ( V_75 -> V_168 != V_168 )
continue;
if ( V_75 -> V_167 && ( ! V_167 || strcmp ( V_75 -> V_167 , V_167 ) ) )
continue;
V_5 = F_108 ( V_75 -> V_182 ) ;
if ( ! V_5 ) {
F_92 ( V_25 , L_52 ,
V_75 -> V_182 ) ;
return F_8 ( - V_55 ) ;
}
if ( V_5 -> V_9 <= V_75 -> V_183 ) {
F_92 ( V_25 ,
L_53 ,
V_168 , V_5 -> V_9 , V_5 -> V_3 ) ;
return F_8 ( - V_10 ) ;
}
V_4 = F_7 ( V_5 , V_75 -> V_183 ) ;
* V_12 = V_75 -> V_12 ;
return V_4 ;
}
return V_4 ;
}
struct V_1 * T_8 F_186 ( struct V_24 * V_25 , const char * V_167 )
{
return F_187 ( V_25 , V_167 , 0 ) ;
}
struct V_1 * T_8 F_188 ( struct V_24 * V_25 ,
const char * V_167 )
{
return F_189 ( V_25 , V_167 , 0 ) ;
}
struct V_1 * T_8 F_187 ( struct V_24 * V_25 ,
const char * V_167 ,
unsigned int V_168 )
{
struct V_1 * V_4 = NULL ;
int V_21 ;
enum V_169 V_12 = 0 ;
F_190 ( V_25 , L_54 , V_167 ) ;
if ( F_191 ( V_184 ) && V_25 && V_25 -> V_123 ) {
F_190 ( V_25 , L_55 ) ;
V_4 = F_179 ( V_25 , V_167 , V_168 , & V_12 ) ;
} else if ( F_191 ( V_185 ) && V_25 && F_192 ( V_25 ) ) {
F_190 ( V_25 , L_56 ) ;
V_4 = F_181 ( V_25 , V_167 , V_168 , & V_12 ) ;
}
if ( ! V_4 || V_4 == F_8 ( - V_76 ) ) {
F_190 ( V_25 , L_57 ) ;
V_4 = F_185 ( V_25 , V_167 , V_168 , & V_12 ) ;
}
if ( F_71 ( V_4 ) ) {
F_190 ( V_25 , L_58 , V_167 ) ;
return V_4 ;
}
V_21 = F_61 ( V_4 , V_167 ) ;
if ( V_21 < 0 )
return F_8 ( V_21 ) ;
if ( V_12 & V_175 )
F_21 ( V_49 , & V_4 -> V_12 ) ;
if ( V_12 & V_186 )
F_21 ( V_142 , & V_4 -> V_12 ) ;
if ( V_12 & V_187 )
F_21 ( V_143 , & V_4 -> V_12 ) ;
return V_4 ;
}
struct V_1 * T_8 F_189 ( struct V_24 * V_25 ,
const char * V_167 ,
unsigned int V_188 )
{
struct V_1 * V_4 ;
V_4 = F_187 ( V_25 , V_167 , V_188 ) ;
if ( F_71 ( V_4 ) ) {
if ( F_72 ( V_4 ) == - V_76 )
return NULL ;
}
return V_4 ;
}
void F_193 ( struct V_1 * V_4 )
{
F_63 ( V_4 ) ;
}
static void F_194 ( struct V_189 * V_190 , struct V_7 * V_5 )
{
unsigned V_61 ;
unsigned V_6 = V_5 -> V_17 ;
struct V_1 * V_191 = & V_5 -> V_4 [ 0 ] ;
int V_192 ;
int V_193 ;
for ( V_61 = 0 ; V_61 < V_5 -> V_9 ; V_61 ++ , V_6 ++ , V_191 ++ ) {
if ( ! F_25 ( V_11 , & V_191 -> V_12 ) )
continue;
F_20 ( V_191 ) ;
V_192 = F_25 ( V_23 , & V_191 -> V_12 ) ;
V_193 = F_25 ( V_157 , & V_191 -> V_12 ) ;
F_195 ( V_190 , L_59 ,
V_6 , V_191 -> V_3 ,
V_192 ? L_8 : L_60 ,
V_5 -> V_155
? ( V_5 -> V_155 ( V_5 , V_61 ) ? L_61 : L_62 )
: L_63 ,
V_193 ? L_64 : L_65 ) ;
F_195 ( V_190 , L_66 ) ;
}
}
static void * F_196 ( struct V_189 * V_190 , T_9 * V_92 )
{
unsigned long V_12 ;
struct V_7 * V_5 = NULL ;
T_9 V_188 = * V_92 ;
V_190 -> V_194 = L_16 ;
F_66 ( & V_77 , V_12 ) ;
F_88 (chip, &gpio_chips, list)
if ( V_188 -- == 0 ) {
F_67 ( & V_77 , V_12 ) ;
return V_5 ;
}
F_67 ( & V_77 , V_12 ) ;
return NULL ;
}
static void * F_197 ( struct V_189 * V_190 , void * V_195 , T_9 * V_92 )
{
unsigned long V_12 ;
struct V_7 * V_5 = V_195 ;
void * V_41 = NULL ;
F_66 ( & V_77 , V_12 ) ;
if ( F_198 ( & V_5 -> V_96 , & V_93 ) )
V_41 = NULL ;
else
V_41 = F_91 ( V_5 -> V_96 . V_196 , struct V_7 , V_96 ) ;
F_67 ( & V_77 , V_12 ) ;
V_190 -> V_194 = L_66 ;
++ * V_92 ;
return V_41 ;
}
static void F_199 ( struct V_189 * V_190 , void * V_195 )
{
}
static int F_200 ( struct V_189 * V_190 , void * V_195 )
{
struct V_7 * V_5 = V_195 ;
struct V_24 * V_25 ;
F_195 ( V_190 , L_67 , ( char * ) V_190 -> V_194 ,
V_5 -> V_17 , V_5 -> V_17 + V_5 -> V_9 - 1 ) ;
V_25 = V_5 -> V_25 ;
if ( V_25 )
F_195 ( V_190 , L_68 , V_25 -> V_197 ? V_25 -> V_197 -> V_63 : L_69 ,
F_184 ( V_25 ) ) ;
if ( V_5 -> V_3 )
F_195 ( V_190 , L_70 , V_5 -> V_3 ) ;
if ( V_5 -> V_106 )
F_195 ( V_190 , L_71 ) ;
F_195 ( V_190 , L_72 ) ;
if ( V_5 -> V_198 )
V_5 -> V_198 ( V_190 , V_5 ) ;
else
F_194 ( V_190 , V_5 ) ;
return 0 ;
}
static int F_201 ( struct V_199 * V_199 , struct V_200 * V_200 )
{
return F_202 ( V_200 , & V_201 ) ;
}
static int T_5 F_203 ( void )
{
( void ) F_204 ( L_49 , V_202 | V_203 ,
NULL , NULL , & V_204 ) ;
return 0 ;
}
