static inline void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
#ifdef F_2
V_2 -> V_3 = V_3 ;
#endif
}
static int F_3 ( struct V_1 * V_4 , unsigned V_5 )
{
const struct V_6 * V_7 = V_4 -> V_7 ;
const int V_8 = V_7 -> V_9 + V_5 ;
if ( F_4 ( F_5 ( V_10 , & V_4 -> V_11 ) == 0 ,
L_1 , V_8 ) ) {
if ( ! F_6 ( V_7 -> V_12 ) ) {
F_7 ( L_2 , V_8 ) ;
F_8 ( V_10 , & V_4 -> V_11 ) ;
return - V_13 ;
}
F_1 ( V_4 , L_3 ) ;
if ( V_7 -> V_14 )
return 1 ;
}
return 0 ;
}
struct V_6 * F_9 ( unsigned V_8 )
{
return V_1 [ V_8 ] . V_7 ;
}
static int F_10 ( int V_15 )
{
int V_16 ;
int V_17 = 0 ;
int V_9 = - V_18 ;
for ( V_16 = V_19 - 1 ; V_16 >= 0 ; V_16 -- ) {
struct V_1 * V_4 = & V_1 [ V_16 ] ;
struct V_6 * V_7 = V_4 -> V_7 ;
if ( ! V_7 && ! F_11 ( V_20 , & V_4 -> V_11 ) ) {
V_17 ++ ;
if ( V_17 == V_15 ) {
V_9 = V_16 ;
break;
}
} else {
V_17 = 0 ;
if ( V_7 )
V_16 -= V_7 -> V_15 - 1 ;
}
}
if ( F_12 ( V_9 ) )
F_13 ( L_4 , V_21 , V_9 ) ;
return V_9 ;
}
int T_1 F_14 ( int V_22 , int V_15 )
{
int V_23 = 0 ;
unsigned long V_11 ;
int V_16 ;
if ( ! F_12 ( V_22 ) || ! F_12 ( V_22 + V_15 - 1 ) )
return - V_24 ;
F_15 ( & V_25 , V_11 ) ;
for ( V_16 = V_22 ; V_16 < V_22 + V_15 ; V_16 ++ ) {
struct V_1 * V_4 = & V_1 [ V_16 ] ;
if ( V_4 -> V_7 || F_11 ( V_20 , & V_4 -> V_11 ) ) {
V_23 = - V_26 ;
goto V_27;
}
F_16 ( V_20 , & V_4 -> V_11 ) ;
}
F_13 ( L_5 ,
V_21 , V_22 , V_22 + V_15 - 1 ) ;
V_27:
F_17 ( & V_25 , V_11 ) ;
return V_23 ;
}
static int F_18 ( unsigned V_8 )
{
struct V_6 * V_7 ;
struct V_1 * V_4 = & V_1 [ V_8 ] ;
int V_28 = - V_24 ;
V_7 = F_9 ( V_8 ) ;
V_8 -= V_7 -> V_9 ;
if ( ! V_7 -> V_29 )
return V_28 ;
V_28 = V_7 -> V_29 ( V_7 , V_8 ) ;
if ( V_28 > 0 ) {
V_28 = 1 ;
F_8 ( V_30 , & V_4 -> V_11 ) ;
}
if ( V_28 == 0 ) {
F_16 ( V_30 , & V_4 -> V_11 ) ;
}
return V_28 ;
}
static T_2 F_19 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
const struct V_1 * V_4 = F_20 ( V_32 ) ;
unsigned V_8 = V_4 - V_1 ;
T_2 V_28 ;
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) )
V_28 = - V_13 ;
else
F_18 ( V_8 ) ;
V_28 = sprintf ( V_35 , L_6 ,
F_11 ( V_30 , & V_4 -> V_11 )
? L_7 : L_8 ) ;
F_22 ( & V_36 ) ;
return V_28 ;
}
static T_2 F_23 ( struct V_31 * V_32 ,
struct V_33 * V_34 , const char * V_35 , T_3 V_38 )
{
const struct V_1 * V_4 = F_20 ( V_32 ) ;
unsigned V_8 = V_4 - V_1 ;
T_2 V_28 ;
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) )
V_28 = - V_13 ;
else if ( F_24 ( V_35 , L_9 ) )
V_28 = F_25 ( V_8 , 1 ) ;
else if ( F_24 ( V_35 , L_7 ) || F_24 ( V_35 , L_10 ) )
V_28 = F_25 ( V_8 , 0 ) ;
else if ( F_24 ( V_35 , L_8 ) )
V_28 = F_26 ( V_8 ) ;
else
V_28 = - V_24 ;
F_22 ( & V_36 ) ;
return V_28 ? : V_38 ;
}
static T_2 F_27 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
const struct V_1 * V_4 = F_20 ( V_32 ) ;
unsigned V_8 = V_4 - V_1 ;
T_2 V_28 ;
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) ) {
V_28 = - V_13 ;
} else {
int V_39 ;
V_39 = ! ! F_28 ( V_8 ) ;
if ( F_11 ( V_40 , & V_4 -> V_11 ) )
V_39 = ! V_39 ;
V_28 = sprintf ( V_35 , L_11 , V_39 ) ;
}
F_22 ( & V_36 ) ;
return V_28 ;
}
static T_2 F_29 ( struct V_31 * V_32 ,
struct V_33 * V_34 , const char * V_35 , T_3 V_38 )
{
const struct V_1 * V_4 = F_20 ( V_32 ) ;
unsigned V_8 = V_4 - V_1 ;
T_2 V_28 ;
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) )
V_28 = - V_13 ;
else if ( ! F_11 ( V_30 , & V_4 -> V_11 ) )
V_28 = - V_41 ;
else {
long V_39 ;
V_28 = F_30 ( V_35 , 0 , & V_39 ) ;
if ( V_28 == 0 ) {
if ( F_11 ( V_40 , & V_4 -> V_11 ) )
V_39 = ! V_39 ;
F_31 ( V_8 , V_39 != 0 ) ;
V_28 = V_38 ;
}
}
F_22 ( & V_36 ) ;
return V_28 ;
}
static T_4 F_32 ( int V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
F_33 ( V_45 ) ;
return V_46 ;
}
static int F_34 ( struct V_1 * V_4 , struct V_31 * V_32 ,
unsigned long V_47 )
{
struct V_44 * V_45 ;
unsigned long V_48 ;
int V_23 , V_42 , V_49 ;
if ( ( V_4 -> V_11 & V_50 ) == V_47 )
return 0 ;
V_42 = F_35 ( V_4 - V_1 ) ;
if ( V_42 < 0 )
return - V_13 ;
V_49 = V_4 -> V_11 >> V_51 ;
V_45 = F_36 ( & V_52 , V_49 ) ;
if ( V_45 )
F_37 ( V_42 , V_45 ) ;
V_4 -> V_11 &= ~ V_50 ;
if ( ! V_47 ) {
V_23 = 0 ;
goto V_53;
}
V_48 = V_54 ;
if ( F_11 ( V_55 , & V_47 ) )
V_48 |= F_11 ( V_40 , & V_4 -> V_11 ) ?
V_56 : V_57 ;
if ( F_11 ( V_58 , & V_47 ) )
V_48 |= F_11 ( V_40 , & V_4 -> V_11 ) ?
V_57 : V_56 ;
if ( ! V_45 ) {
V_45 = F_38 ( V_32 -> V_59 . V_60 , NULL , L_12 ) ;
if ( ! V_45 ) {
V_23 = - V_61 ;
goto V_62;
}
do {
V_23 = - V_63 ;
if ( F_39 ( & V_52 , V_64 ) )
V_23 = F_40 ( & V_52 , V_45 ,
1 , & V_49 ) ;
} while ( V_23 == - V_65 );
if ( V_23 )
goto V_66;
V_4 -> V_11 &= V_67 ;
V_4 -> V_11 |= ( unsigned long ) V_49 << V_51 ;
if ( V_4 -> V_11 >> V_51 != V_49 ) {
V_23 = - V_68 ;
goto V_53;
}
}
V_23 = F_41 ( V_42 , F_32 , V_48 ,
L_13 , V_45 ) ;
if ( V_23 < 0 )
goto V_53;
V_4 -> V_11 |= V_47 ;
return 0 ;
V_53:
F_42 ( & V_52 , V_49 ) ;
V_4 -> V_11 &= V_67 ;
V_66:
if ( V_45 )
F_43 ( V_45 ) ;
V_62:
return V_23 ;
}
static T_2 F_44 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
const struct V_1 * V_4 = F_20 ( V_32 ) ;
T_2 V_28 ;
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) )
V_28 = - V_13 ;
else {
int V_16 ;
V_28 = 0 ;
for ( V_16 = 0 ; V_16 < F_45 ( V_69 ) ; V_16 ++ )
if ( ( V_4 -> V_11 & V_50 )
== V_69 [ V_16 ] . V_11 ) {
V_28 = sprintf ( V_35 , L_6 ,
V_69 [ V_16 ] . V_70 ) ;
break;
}
}
F_22 ( & V_36 ) ;
return V_28 ;
}
static T_2 F_46 ( struct V_31 * V_32 ,
struct V_33 * V_34 , const char * V_35 , T_3 V_38 )
{
struct V_1 * V_4 = F_20 ( V_32 ) ;
T_2 V_28 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_45 ( V_69 ) ; V_16 ++ )
if ( F_24 ( V_69 [ V_16 ] . V_70 , V_35 ) )
goto V_71;
return - V_24 ;
V_71:
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) )
V_28 = - V_13 ;
else {
V_28 = F_34 ( V_4 , V_32 , V_69 [ V_16 ] . V_11 ) ;
if ( ! V_28 )
V_28 = V_38 ;
}
F_22 ( & V_36 ) ;
return V_28 ;
}
static int F_47 ( struct V_1 * V_4 , struct V_31 * V_32 ,
int V_39 )
{
int V_28 = 0 ;
if ( ! ! F_11 ( V_40 , & V_4 -> V_11 ) == ! ! V_39 )
return 0 ;
if ( V_39 )
F_16 ( V_40 , & V_4 -> V_11 ) ;
else
F_8 ( V_40 , & V_4 -> V_11 ) ;
if ( V_32 != NULL && ( ! ! F_11 ( V_58 , & V_4 -> V_11 ) ^
! ! F_11 ( V_55 , & V_4 -> V_11 ) ) ) {
unsigned long V_72 = V_4 -> V_11 & V_50 ;
F_34 ( V_4 , V_32 , 0 ) ;
V_28 = F_34 ( V_4 , V_32 , V_72 ) ;
}
return V_28 ;
}
static T_2 F_48 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
const struct V_1 * V_4 = F_20 ( V_32 ) ;
T_2 V_28 ;
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) )
V_28 = - V_13 ;
else
V_28 = sprintf ( V_35 , L_11 ,
! ! F_11 ( V_40 , & V_4 -> V_11 ) ) ;
F_22 ( & V_36 ) ;
return V_28 ;
}
static T_2 F_49 ( struct V_31 * V_32 ,
struct V_33 * V_34 , const char * V_35 , T_3 V_38 )
{
struct V_1 * V_4 = F_20 ( V_32 ) ;
T_2 V_28 ;
F_21 ( & V_36 ) ;
if ( ! F_11 ( V_37 , & V_4 -> V_11 ) ) {
V_28 = - V_13 ;
} else {
long V_39 ;
V_28 = F_30 ( V_35 , 0 , & V_39 ) ;
if ( V_28 == 0 )
V_28 = F_47 ( V_4 , V_32 , V_39 != 0 ) ;
}
F_22 ( & V_36 ) ;
return V_28 ? : V_38 ;
}
static T_2 F_50 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
const struct V_6 * V_7 = F_20 ( V_32 ) ;
return sprintf ( V_35 , L_11 , V_7 -> V_9 ) ;
}
static T_2 F_51 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
const struct V_6 * V_7 = F_20 ( V_32 ) ;
return sprintf ( V_35 , L_6 , V_7 -> V_3 ? : L_14 ) ;
}
static T_2 F_52 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
const struct V_6 * V_7 = F_20 ( V_32 ) ;
return sprintf ( V_35 , L_15 , V_7 -> V_15 ) ;
}
static T_2 F_53 ( struct V_73 * V_73 ,
struct V_74 * V_34 ,
const char * V_35 , T_3 V_75 )
{
long V_8 ;
int V_28 ;
V_28 = F_30 ( V_35 , 0 , & V_8 ) ;
if ( V_28 < 0 )
goto V_76;
V_28 = F_54 ( V_8 , L_16 ) ;
if ( V_28 < 0 ) {
if ( V_28 == - V_77 )
V_28 = - V_61 ;
goto V_76;
}
V_28 = F_55 ( V_8 , true ) ;
if ( V_28 < 0 )
F_56 ( V_8 ) ;
else
F_16 ( V_78 , & V_1 [ V_8 ] . V_11 ) ;
V_76:
if ( V_28 )
F_13 ( L_17 , V_21 , V_28 ) ;
return V_28 ? : V_75 ;
}
static T_2 F_57 ( struct V_73 * V_73 ,
struct V_74 * V_34 ,
const char * V_35 , T_3 V_75 )
{
long V_8 ;
int V_28 ;
V_28 = F_30 ( V_35 , 0 , & V_8 ) ;
if ( V_28 < 0 )
goto V_76;
V_28 = - V_24 ;
if ( ! F_12 ( V_8 ) )
goto V_76;
if ( F_58 ( V_78 , & V_1 [ V_8 ] . V_11 ) ) {
V_28 = 0 ;
F_56 ( V_8 ) ;
}
V_76:
if ( V_28 )
F_13 ( L_17 , V_21 , V_28 ) ;
return V_28 ? : V_75 ;
}
int F_55 ( unsigned V_8 , bool V_79 )
{
unsigned long V_11 ;
struct V_1 * V_4 ;
int V_28 ;
const char * V_80 = NULL ;
struct V_31 * V_32 ;
if ( ! V_81 . V_82 ) {
F_13 ( L_18 , V_21 ) ;
return - V_83 ;
}
if ( ! F_12 ( V_8 ) ) {
F_13 ( L_19 , V_21 , V_8 ) ;
return - V_24 ;
}
F_21 ( & V_36 ) ;
F_15 ( & V_25 , V_11 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( ! F_11 ( V_10 , & V_4 -> V_11 ) ||
F_11 ( V_37 , & V_4 -> V_11 ) ) {
F_17 ( & V_25 , V_11 ) ;
F_13 ( L_20 ,
V_21 , V_8 ,
F_11 ( V_10 , & V_4 -> V_11 ) ,
F_11 ( V_37 , & V_4 -> V_11 ) ) ;
V_28 = - V_41 ;
goto V_84;
}
if ( ! V_4 -> V_7 -> V_85 || ! V_4 -> V_7 -> V_86 )
V_79 = false ;
F_17 ( & V_25 , V_11 ) ;
if ( V_4 -> V_7 -> V_87 && V_4 -> V_7 -> V_87 [ V_8 - V_4 -> V_7 -> V_9 ] )
V_80 = V_4 -> V_7 -> V_87 [ V_8 - V_4 -> V_7 -> V_9 ] ;
V_32 = F_59 ( & V_81 , V_4 -> V_7 -> V_32 , F_60 ( 0 , 0 ) ,
V_4 , V_80 ? V_80 : L_21 , V_8 ) ;
if ( F_61 ( V_32 ) ) {
V_28 = F_62 ( V_32 ) ;
goto V_84;
}
V_28 = F_63 ( & V_32 -> V_59 , & V_88 ) ;
if ( V_28 )
goto V_89;
if ( V_79 ) {
V_28 = F_64 ( V_32 , & V_90 ) ;
if ( V_28 )
goto V_89;
}
if ( F_35 ( V_8 ) >= 0 && ( V_79 ||
! F_11 ( V_30 , & V_4 -> V_11 ) ) ) {
V_28 = F_64 ( V_32 , & V_91 ) ;
if ( V_28 )
goto V_89;
}
F_16 ( V_37 , & V_4 -> V_11 ) ;
F_22 ( & V_36 ) ;
return 0 ;
V_89:
F_65 ( V_32 ) ;
V_84:
F_22 ( & V_36 ) ;
F_13 ( L_22 , V_21 , V_8 , V_28 ) ;
return V_28 ;
}
static int F_66 ( struct V_31 * V_32 , void * V_92 )
{
return F_20 ( V_32 ) == V_92 ;
}
int F_67 ( struct V_31 * V_32 , const char * V_70 , unsigned V_8 )
{
struct V_1 * V_4 ;
int V_28 = - V_24 ;
if ( ! F_12 ( V_8 ) )
goto V_76;
F_21 ( & V_36 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( F_11 ( V_37 , & V_4 -> V_11 ) ) {
struct V_31 * V_93 ;
V_93 = F_68 ( & V_81 , NULL , V_4 , F_66 ) ;
if ( V_93 != NULL ) {
V_28 = F_69 ( & V_32 -> V_59 , & V_93 -> V_59 ,
V_70 ) ;
} else {
V_28 = - V_61 ;
}
}
F_22 ( & V_36 ) ;
V_76:
if ( V_28 )
F_13 ( L_22 , V_21 , V_8 , V_28 ) ;
return V_28 ;
}
int F_70 ( unsigned V_8 , int V_39 )
{
struct V_1 * V_4 ;
struct V_31 * V_32 = NULL ;
int V_28 = - V_24 ;
if ( ! F_12 ( V_8 ) )
goto V_76;
F_21 ( & V_36 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( F_11 ( V_37 , & V_4 -> V_11 ) ) {
V_32 = F_68 ( & V_81 , NULL , V_4 , F_66 ) ;
if ( V_32 == NULL ) {
V_28 = - V_61 ;
goto V_94;
}
}
V_28 = F_47 ( V_4 , V_32 , V_39 ) ;
V_94:
F_22 ( & V_36 ) ;
V_76:
if ( V_28 )
F_13 ( L_22 , V_21 , V_8 , V_28 ) ;
return V_28 ;
}
void F_71 ( unsigned V_8 )
{
struct V_1 * V_4 ;
int V_28 = 0 ;
struct V_31 * V_32 = NULL ;
if ( ! F_12 ( V_8 ) ) {
V_28 = - V_24 ;
goto V_76;
}
F_21 ( & V_36 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( F_11 ( V_37 , & V_4 -> V_11 ) ) {
V_32 = F_68 ( & V_81 , NULL , V_4 , F_66 ) ;
if ( V_32 ) {
F_34 ( V_4 , V_32 , 0 ) ;
F_8 ( V_37 , & V_4 -> V_11 ) ;
} else
V_28 = - V_61 ;
}
F_22 ( & V_36 ) ;
if ( V_32 ) {
F_65 ( V_32 ) ;
F_72 ( V_32 ) ;
}
V_76:
if ( V_28 )
F_13 ( L_22 , V_21 , V_8 , V_28 ) ;
}
static int F_73 ( struct V_6 * V_7 )
{
int V_28 ;
struct V_31 * V_32 ;
if ( ! V_81 . V_82 )
return 0 ;
F_21 ( & V_36 ) ;
V_32 = F_59 ( & V_81 , V_7 -> V_32 , F_60 ( 0 , 0 ) , V_7 ,
L_23 , V_7 -> V_9 ) ;
if ( ! F_61 ( V_32 ) ) {
V_28 = F_63 ( & V_32 -> V_59 ,
& V_95 ) ;
} else
V_28 = F_62 ( V_32 ) ;
V_7 -> V_96 = ( V_28 == 0 ) ;
F_22 ( & V_36 ) ;
if ( V_28 ) {
unsigned long V_11 ;
unsigned V_8 ;
F_15 ( & V_25 , V_11 ) ;
V_8 = V_7 -> V_9 ;
while ( V_1 [ V_8 ] . V_7 == V_7 )
V_1 [ V_8 ++ ] . V_7 = NULL ;
F_17 ( & V_25 , V_11 ) ;
F_13 ( L_24 , V_21 ,
V_7 -> V_3 , V_28 ) ;
}
return V_28 ;
}
static void F_74 ( struct V_6 * V_7 )
{
int V_28 ;
struct V_31 * V_32 ;
F_21 ( & V_36 ) ;
V_32 = F_68 ( & V_81 , NULL , V_7 , F_66 ) ;
if ( V_32 ) {
F_72 ( V_32 ) ;
F_65 ( V_32 ) ;
V_7 -> V_96 = 0 ;
V_28 = 0 ;
} else
V_28 = - V_61 ;
F_22 ( & V_36 ) ;
if ( V_28 )
F_13 ( L_24 , V_21 ,
V_7 -> V_3 , V_28 ) ;
}
static int T_1 F_75 ( void )
{
int V_28 ;
unsigned long V_11 ;
unsigned V_8 ;
V_28 = F_76 ( & V_81 ) ;
if ( V_28 < 0 )
return V_28 ;
F_15 ( & V_25 , V_11 ) ;
for ( V_8 = 0 ; V_8 < V_19 ; V_8 ++ ) {
struct V_6 * V_7 ;
V_7 = V_1 [ V_8 ] . V_7 ;
if ( ! V_7 || V_7 -> V_96 )
continue;
F_17 ( & V_25 , V_11 ) ;
V_28 = F_73 ( V_7 ) ;
F_15 ( & V_25 , V_11 ) ;
}
F_17 ( & V_25 , V_11 ) ;
return V_28 ;
}
static inline int F_73 ( struct V_6 * V_7 )
{
return 0 ;
}
static inline void F_74 ( struct V_6 * V_7 )
{
}
int F_77 ( struct V_6 * V_7 )
{
unsigned long V_11 ;
int V_28 = 0 ;
unsigned V_49 ;
int V_9 = V_7 -> V_9 ;
if ( ( ! F_12 ( V_9 ) || ! F_12 ( V_9 + V_7 -> V_15 - 1 ) )
&& V_9 >= 0 ) {
V_28 = - V_24 ;
goto V_97;
}
F_15 ( & V_25 , V_11 ) ;
if ( V_9 < 0 ) {
V_9 = F_10 ( V_7 -> V_15 ) ;
if ( V_9 < 0 ) {
V_28 = V_9 ;
goto V_94;
}
V_7 -> V_9 = V_9 ;
}
for ( V_49 = V_9 ; V_49 < V_9 + V_7 -> V_15 ; V_49 ++ ) {
if ( V_1 [ V_49 ] . V_7 != NULL ) {
V_28 = - V_26 ;
break;
}
}
if ( V_28 == 0 ) {
for ( V_49 = V_9 ; V_49 < V_9 + V_7 -> V_15 ; V_49 ++ ) {
V_1 [ V_49 ] . V_7 = V_7 ;
V_1 [ V_49 ] . V_11 = ! V_7 -> V_85
? ( 1 << V_30 )
: 0 ;
}
}
#ifdef F_78
F_79 ( & V_7 -> V_98 ) ;
#endif
F_80 ( V_7 ) ;
V_94:
F_17 ( & V_25 , V_11 ) ;
if ( V_28 )
goto V_97;
V_28 = F_73 ( V_7 ) ;
if ( V_28 )
goto V_97;
F_13 ( L_25 ,
V_7 -> V_9 , V_7 -> V_9 + V_7 -> V_15 - 1 ,
V_7 -> V_3 ? : L_26 ) ;
return 0 ;
V_97:
F_7 ( L_27 ,
V_7 -> V_9 , V_7 -> V_9 + V_7 -> V_15 - 1 ,
V_7 -> V_3 ? : L_26 ) ;
return V_28 ;
}
int F_81 ( struct V_6 * V_7 )
{
unsigned long V_11 ;
int V_28 = 0 ;
unsigned V_49 ;
F_15 ( & V_25 , V_11 ) ;
F_82 ( V_7 ) ;
F_83 ( V_7 ) ;
for ( V_49 = V_7 -> V_9 ; V_49 < V_7 -> V_9 + V_7 -> V_15 ; V_49 ++ ) {
if ( F_11 ( V_10 , & V_1 [ V_49 ] . V_11 ) ) {
V_28 = - V_26 ;
break;
}
}
if ( V_28 == 0 ) {
for ( V_49 = V_7 -> V_9 ; V_49 < V_7 -> V_9 + V_7 -> V_15 ; V_49 ++ )
V_1 [ V_49 ] . V_7 = NULL ;
}
F_17 ( & V_25 , V_11 ) ;
if ( V_28 == 0 )
F_74 ( V_7 ) ;
return V_28 ;
}
struct V_6 * F_84 ( void * V_92 ,
int (* F_85)( struct V_6 * V_7 ,
void * V_92 ) )
{
struct V_6 * V_7 = NULL ;
unsigned long V_11 ;
int V_16 ;
F_15 ( & V_25 , V_11 ) ;
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ ) {
if ( ! V_1 [ V_16 ] . V_7 )
continue;
if ( F_85 ( V_1 [ V_16 ] . V_7 , V_92 ) ) {
V_7 = V_1 [ V_16 ] . V_7 ;
break;
}
}
F_17 ( & V_25 , V_11 ) ;
return V_7 ;
}
int F_86 ( struct V_6 * V_7 , const char * V_99 ,
unsigned int V_100 , unsigned int V_101 ,
unsigned int V_102 )
{
struct V_103 * V_104 ;
int V_23 ;
V_104 = F_87 ( sizeof( * V_104 ) , V_64 ) ;
if ( ! V_104 ) {
F_7 ( L_28 ,
V_7 -> V_3 ) ;
return - V_63 ;
}
V_104 -> V_105 . V_49 = V_100 ;
V_104 -> V_105 . V_106 = V_7 ;
V_104 -> V_105 . V_70 = V_7 -> V_3 ;
V_104 -> V_105 . V_9 = V_7 -> V_9 + V_100 ;
V_104 -> V_105 . V_107 = V_101 ;
V_104 -> V_105 . V_102 = V_102 ;
V_104 -> V_108 = F_88 ( V_99 ,
& V_104 -> V_105 ) ;
if ( F_61 ( V_104 -> V_108 ) ) {
V_23 = F_62 ( V_104 -> V_108 ) ;
F_7 ( L_29 ,
V_7 -> V_3 ) ;
F_89 ( V_104 ) ;
return V_23 ;
}
F_13 ( L_30 ,
V_7 -> V_3 , V_100 , V_100 + V_102 - 1 ,
V_99 ,
V_101 , V_101 + V_102 - 1 ) ;
F_90 ( & V_104 -> V_109 , & V_7 -> V_98 ) ;
return 0 ;
}
void F_82 ( struct V_6 * V_7 )
{
struct V_103 * V_104 , * V_110 ;
F_91 (pin_range, tmp, &chip->pin_ranges, node) {
F_92 ( & V_104 -> V_109 ) ;
F_93 ( V_104 -> V_108 ,
& V_104 -> V_105 ) ;
F_89 ( V_104 ) ;
}
}
int F_54 ( unsigned V_8 , const char * V_3 )
{
struct V_1 * V_4 ;
struct V_6 * V_7 ;
int V_28 = - V_77 ;
unsigned long V_11 ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) ) {
V_28 = - V_24 ;
goto V_76;
}
V_4 = & V_1 [ V_8 ] ;
V_7 = V_4 -> V_7 ;
if ( V_7 == NULL )
goto V_76;
if ( ! F_6 ( V_7 -> V_12 ) )
goto V_76;
if ( F_5 ( V_10 , & V_4 -> V_11 ) == 0 ) {
F_1 ( V_4 , V_3 ? : L_31 ) ;
V_28 = 0 ;
} else {
V_28 = - V_26 ;
F_94 ( V_7 -> V_12 ) ;
goto V_76;
}
if ( V_7 -> V_14 ) {
F_17 ( & V_25 , V_11 ) ;
V_28 = V_7 -> V_14 ( V_7 , V_8 - V_7 -> V_9 ) ;
F_15 ( & V_25 , V_11 ) ;
if ( V_28 < 0 ) {
F_1 ( V_4 , NULL ) ;
F_94 ( V_7 -> V_12 ) ;
F_8 ( V_10 , & V_4 -> V_11 ) ;
goto V_76;
}
}
if ( V_7 -> V_29 ) {
F_17 ( & V_25 , V_11 ) ;
F_18 ( V_8 ) ;
F_15 ( & V_25 , V_11 ) ;
}
V_76:
if ( V_28 )
F_13 ( L_32 ,
V_8 , V_3 ? : L_31 , V_28 ) ;
F_17 ( & V_25 , V_11 ) ;
return V_28 ;
}
void F_56 ( unsigned V_8 )
{
unsigned long V_11 ;
struct V_1 * V_4 ;
struct V_6 * V_7 ;
F_95 () ;
if ( ! F_12 ( V_8 ) ) {
F_96 ( V_111 ) ;
return;
}
F_71 ( V_8 ) ;
F_15 ( & V_25 , V_11 ) ;
V_4 = & V_1 [ V_8 ] ;
V_7 = V_4 -> V_7 ;
if ( V_7 && F_11 ( V_10 , & V_4 -> V_11 ) ) {
if ( V_7 -> free ) {
F_17 ( & V_25 , V_11 ) ;
F_97 ( V_7 -> V_112 ) ;
V_7 -> free ( V_7 , V_8 - V_7 -> V_9 ) ;
F_15 ( & V_25 , V_11 ) ;
}
F_1 ( V_4 , NULL ) ;
F_94 ( V_4 -> V_7 -> V_12 ) ;
F_8 ( V_40 , & V_4 -> V_11 ) ;
F_8 ( V_10 , & V_4 -> V_11 ) ;
F_8 ( V_113 , & V_4 -> V_11 ) ;
F_8 ( V_114 , & V_4 -> V_11 ) ;
} else
F_96 ( V_111 ) ;
F_17 ( & V_25 , V_11 ) ;
}
int F_98 ( unsigned V_8 , unsigned long V_11 , const char * V_3 )
{
int V_27 ;
V_27 = F_54 ( V_8 , V_3 ) ;
if ( V_27 )
return V_27 ;
if ( V_11 & V_115 )
F_16 ( V_113 , & V_1 [ V_8 ] . V_11 ) ;
if ( V_11 & V_116 )
F_16 ( V_114 , & V_1 [ V_8 ] . V_11 ) ;
if ( V_11 & V_117 )
V_27 = F_26 ( V_8 ) ;
else
V_27 = F_25 ( V_8 ,
( V_11 & V_118 ) ? 1 : 0 ) ;
if ( V_27 )
goto V_119;
if ( V_11 & V_120 ) {
V_27 = F_55 ( V_8 , V_11 & V_121 ) ;
if ( V_27 )
goto V_119;
}
return 0 ;
V_119:
F_56 ( V_8 ) ;
return V_27 ;
}
int F_99 ( const struct V_8 * V_122 , T_3 V_123 )
{
int V_16 , V_27 ;
for ( V_16 = 0 ; V_16 < V_123 ; V_16 ++ , V_122 ++ ) {
V_27 = F_98 ( V_122 -> V_8 , V_122 -> V_11 , V_122 -> V_3 ) ;
if ( V_27 )
goto V_124;
}
return 0 ;
V_124:
while ( V_16 -- )
F_56 ( ( -- V_122 ) -> V_8 ) ;
return V_27 ;
}
void F_100 ( const struct V_8 * V_122 , T_3 V_123 )
{
while ( V_123 -- )
F_56 ( ( V_122 ++ ) -> V_8 ) ;
}
const char * F_101 ( struct V_6 * V_7 , unsigned V_5 )
{
unsigned V_8 = V_7 -> V_9 + V_5 ;
if ( ! F_12 ( V_8 ) || V_1 [ V_8 ] . V_7 != V_7 )
return NULL ;
if ( F_11 ( V_10 , & V_1 [ V_8 ] . V_11 ) == 0 )
return NULL ;
#ifdef F_2
return V_1 [ V_8 ] . V_3 ;
#else
return L_31 ;
#endif
}
int F_26 ( unsigned V_8 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_1 * V_4 = & V_1 [ V_8 ] ;
int V_28 = - V_24 ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) )
goto V_97;
V_7 = V_4 -> V_7 ;
if ( ! V_7 || ! V_7 -> V_125 || ! V_7 -> V_85 )
goto V_97;
V_8 -= V_7 -> V_9 ;
if ( V_8 >= V_7 -> V_15 )
goto V_97;
V_28 = F_3 ( V_4 , V_8 ) ;
if ( V_28 < 0 )
goto V_97;
F_17 ( & V_25 , V_11 ) ;
F_97 ( V_7 -> V_112 ) ;
if ( V_28 ) {
V_28 = V_7 -> V_14 ( V_7 , V_8 ) ;
if ( V_28 < 0 ) {
F_13 ( L_33 ,
V_7 -> V_9 + V_8 , V_28 ) ;
goto V_126;
}
}
V_28 = V_7 -> V_85 ( V_7 , V_8 ) ;
if ( V_28 == 0 )
F_8 ( V_30 , & V_4 -> V_11 ) ;
F_102 ( V_7 -> V_9 + V_8 , 1 , V_28 ) ;
V_126:
return V_28 ;
V_97:
F_17 ( & V_25 , V_11 ) ;
if ( V_28 )
F_13 ( L_34 ,
V_21 , V_8 , V_28 ) ;
return V_28 ;
}
int F_25 ( unsigned V_8 , int V_39 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_1 * V_4 = & V_1 [ V_8 ] ;
int V_28 = - V_24 ;
if ( V_39 && F_11 ( V_113 , & V_4 -> V_11 ) )
return F_26 ( V_8 ) ;
if ( ! V_39 && F_11 ( V_114 , & V_4 -> V_11 ) )
return F_26 ( V_8 ) ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) )
goto V_97;
V_7 = V_4 -> V_7 ;
if ( ! V_7 || ! V_7 -> V_127 || ! V_7 -> V_86 )
goto V_97;
V_8 -= V_7 -> V_9 ;
if ( V_8 >= V_7 -> V_15 )
goto V_97;
V_28 = F_3 ( V_4 , V_8 ) ;
if ( V_28 < 0 )
goto V_97;
F_17 ( & V_25 , V_11 ) ;
F_97 ( V_7 -> V_112 ) ;
if ( V_28 ) {
V_28 = V_7 -> V_14 ( V_7 , V_8 ) ;
if ( V_28 < 0 ) {
F_13 ( L_33 ,
V_7 -> V_9 + V_8 , V_28 ) ;
goto V_126;
}
}
V_28 = V_7 -> V_86 ( V_7 , V_8 , V_39 ) ;
if ( V_28 == 0 )
F_16 ( V_30 , & V_4 -> V_11 ) ;
F_103 ( V_7 -> V_9 + V_8 , 0 , V_39 ) ;
F_102 ( V_7 -> V_9 + V_8 , 0 , V_28 ) ;
V_126:
return V_28 ;
V_97:
F_17 ( & V_25 , V_11 ) ;
if ( V_28 )
F_13 ( L_34 ,
V_21 , V_8 , V_28 ) ;
return V_28 ;
}
int F_104 ( unsigned V_8 , unsigned V_128 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_1 * V_4 = & V_1 [ V_8 ] ;
int V_28 = - V_24 ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) )
goto V_97;
V_7 = V_4 -> V_7 ;
if ( ! V_7 || ! V_7 -> V_127 || ! V_7 -> V_129 )
goto V_97;
V_8 -= V_7 -> V_9 ;
if ( V_8 >= V_7 -> V_15 )
goto V_97;
V_28 = F_3 ( V_4 , V_8 ) ;
if ( V_28 < 0 )
goto V_97;
F_17 ( & V_25 , V_11 ) ;
F_97 ( V_7 -> V_112 ) ;
return V_7 -> V_129 ( V_7 , V_8 , V_128 ) ;
V_97:
F_17 ( & V_25 , V_11 ) ;
if ( V_28 )
F_13 ( L_34 ,
V_21 , V_8 , V_28 ) ;
return V_28 ;
}
int F_105 ( unsigned V_8 )
{
struct V_6 * V_7 ;
int V_39 ;
V_7 = F_9 ( V_8 ) ;
F_96 ( V_7 -> V_112 ) ;
V_39 = V_7 -> V_125 ? V_7 -> V_125 ( V_7 , V_8 - V_7 -> V_9 ) : 0 ;
F_103 ( V_8 , 1 , V_39 ) ;
return V_39 ;
}
static void F_106 ( unsigned V_8 ,
struct V_6 * V_7 , int V_39 )
{
int V_27 = 0 ;
if ( V_39 ) {
V_27 = V_7 -> V_85 ( V_7 , V_8 - V_7 -> V_9 ) ;
if ( ! V_27 )
F_8 ( V_30 , & V_1 [ V_8 ] . V_11 ) ;
} else {
V_27 = V_7 -> V_86 ( V_7 , V_8 - V_7 -> V_9 , 0 ) ;
if ( ! V_27 )
F_16 ( V_30 , & V_1 [ V_8 ] . V_11 ) ;
}
F_102 ( V_8 , V_39 , V_27 ) ;
if ( V_27 < 0 )
F_7 ( L_35 ,
V_21 , V_8 , V_27 ) ;
}
static void F_107 ( unsigned V_8 ,
struct V_6 * V_7 , int V_39 )
{
int V_27 = 0 ;
if ( V_39 ) {
V_27 = V_7 -> V_86 ( V_7 , V_8 - V_7 -> V_9 , 1 ) ;
if ( ! V_27 )
F_16 ( V_30 , & V_1 [ V_8 ] . V_11 ) ;
} else {
V_27 = V_7 -> V_85 ( V_7 , V_8 - V_7 -> V_9 ) ;
if ( ! V_27 )
F_8 ( V_30 , & V_1 [ V_8 ] . V_11 ) ;
}
F_102 ( V_8 , ! V_39 , V_27 ) ;
if ( V_27 < 0 )
F_7 ( L_36 ,
V_21 , V_8 , V_27 ) ;
}
void F_108 ( unsigned V_8 , int V_39 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_8 ) ;
F_96 ( V_7 -> V_112 ) ;
F_103 ( V_8 , 0 , V_39 ) ;
if ( F_11 ( V_113 , & V_1 [ V_8 ] . V_11 ) )
F_106 ( V_8 , V_7 , V_39 ) ;
else if ( F_11 ( V_114 , & V_1 [ V_8 ] . V_11 ) )
F_107 ( V_8 , V_7 , V_39 ) ;
else
V_7 -> V_127 ( V_7 , V_8 - V_7 -> V_9 , V_39 ) ;
}
int F_109 ( unsigned V_8 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_8 ) ;
return V_7 -> V_112 ;
}
int F_110 ( unsigned V_8 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_8 ) ;
return V_7 -> V_130 ? V_7 -> V_130 ( V_7 , V_8 - V_7 -> V_9 ) : - V_131 ;
}
int F_28 ( unsigned V_8 )
{
struct V_6 * V_7 ;
int V_39 ;
F_97 ( V_111 ) ;
V_7 = F_9 ( V_8 ) ;
V_39 = V_7 -> V_125 ? V_7 -> V_125 ( V_7 , V_8 - V_7 -> V_9 ) : 0 ;
F_103 ( V_8 , 1 , V_39 ) ;
return V_39 ;
}
void F_31 ( unsigned V_8 , int V_39 )
{
struct V_6 * V_7 ;
F_97 ( V_111 ) ;
V_7 = F_9 ( V_8 ) ;
F_103 ( V_8 , 0 , V_39 ) ;
if ( F_11 ( V_113 , & V_1 [ V_8 ] . V_11 ) )
F_106 ( V_8 , V_7 , V_39 ) ;
else if ( F_11 ( V_114 , & V_1 [ V_8 ] . V_11 ) )
F_107 ( V_8 , V_7 , V_39 ) ;
else
V_7 -> V_127 ( V_7 , V_8 - V_7 -> V_9 , V_39 ) ;
}
static void F_111 ( struct V_132 * V_133 , struct V_6 * V_7 )
{
unsigned V_16 ;
unsigned V_8 = V_7 -> V_9 ;
struct V_1 * V_134 = & V_1 [ V_8 ] ;
int V_135 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_15 ; V_16 ++ , V_8 ++ , V_134 ++ ) {
if ( ! F_11 ( V_10 , & V_134 -> V_11 ) )
continue;
F_18 ( V_8 ) ;
V_135 = F_11 ( V_30 , & V_134 -> V_11 ) ;
F_112 ( V_133 , L_37 ,
V_8 , V_134 -> V_3 ,
V_135 ? L_7 : L_38 ,
V_7 -> V_125
? ( V_7 -> V_125 ( V_7 , V_16 ) ? L_39 : L_40 )
: L_41 ) ;
F_112 ( V_133 , L_42 ) ;
}
}
static void * F_113 ( struct V_132 * V_133 , T_5 * V_136 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_8 ;
void * V_23 = NULL ;
T_5 V_137 = 0 ;
for ( V_8 = 0 ; F_12 ( V_8 ) ; V_8 ++ ) {
if ( V_1 [ V_8 ] . V_7 == V_7 )
continue;
V_7 = V_1 [ V_8 ] . V_7 ;
if ( ! V_7 )
continue;
if ( V_137 ++ >= * V_136 ) {
V_23 = V_7 ;
break;
}
}
V_133 -> V_138 = L_14 ;
return V_23 ;
}
static void * F_114 ( struct V_132 * V_133 , void * V_139 , T_5 * V_136 )
{
struct V_6 * V_7 = V_139 ;
unsigned int V_8 ;
void * V_23 = NULL ;
for ( V_8 = V_7 -> V_9 + V_7 -> V_15 ; F_12 ( V_8 ) ; V_8 ++ ) {
V_7 = V_1 [ V_8 ] . V_7 ;
if ( V_7 ) {
V_23 = V_7 ;
break;
}
}
V_133 -> V_138 = L_42 ;
++ * V_136 ;
return V_23 ;
}
static void F_115 ( struct V_132 * V_133 , void * V_139 )
{
}
static int F_116 ( struct V_132 * V_133 , void * V_139 )
{
struct V_6 * V_7 = V_139 ;
struct V_31 * V_32 ;
F_112 ( V_133 , L_43 , ( char * ) V_133 -> V_138 ,
V_7 -> V_9 , V_7 -> V_9 + V_7 -> V_15 - 1 ) ;
V_32 = V_7 -> V_32 ;
if ( V_32 )
F_112 ( V_133 , L_44 , V_32 -> V_140 ? V_32 -> V_140 -> V_70 : L_45 ,
F_117 ( V_32 ) ) ;
if ( V_7 -> V_3 )
F_112 ( V_133 , L_46 , V_7 -> V_3 ) ;
if ( V_7 -> V_112 )
F_112 ( V_133 , L_47 ) ;
F_112 ( V_133 , L_48 ) ;
if ( V_7 -> V_141 )
V_7 -> V_141 ( V_133 , V_7 ) ;
else
F_111 ( V_133 , V_7 ) ;
return 0 ;
}
static int F_118 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
return F_119 ( V_143 , & V_144 ) ;
}
static int T_1 F_120 ( void )
{
( void ) F_121 ( L_49 , V_145 | V_146 ,
NULL , NULL , & V_147 ) ;
return 0 ;
}
