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
static T_2 F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
const struct V_1 * V_4 = F_19 ( V_29 ) ;
T_2 V_33 ;
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) )
V_33 = - V_13 ;
else
V_33 = sprintf ( V_32 , L_6 ,
F_11 ( V_36 , & V_4 -> V_11 )
? L_7 : L_8 ) ;
F_21 ( & V_34 ) ;
return V_33 ;
}
static T_2 F_22 ( struct V_28 * V_29 ,
struct V_30 * V_31 , const char * V_32 , T_3 V_37 )
{
const struct V_1 * V_4 = F_19 ( V_29 ) ;
unsigned V_8 = V_4 - V_1 ;
T_2 V_33 ;
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) )
V_33 = - V_13 ;
else if ( F_23 ( V_32 , L_9 ) )
V_33 = F_24 ( V_8 , 1 ) ;
else if ( F_23 ( V_32 , L_7 ) || F_23 ( V_32 , L_10 ) )
V_33 = F_24 ( V_8 , 0 ) ;
else if ( F_23 ( V_32 , L_8 ) )
V_33 = F_25 ( V_8 ) ;
else
V_33 = - V_24 ;
F_21 ( & V_34 ) ;
return V_33 ? : V_37 ;
}
static T_2 F_26 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
const struct V_1 * V_4 = F_19 ( V_29 ) ;
unsigned V_8 = V_4 - V_1 ;
T_2 V_33 ;
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) ) {
V_33 = - V_13 ;
} else {
int V_38 ;
V_38 = ! ! F_27 ( V_8 ) ;
if ( F_11 ( V_39 , & V_4 -> V_11 ) )
V_38 = ! V_38 ;
V_33 = sprintf ( V_32 , L_11 , V_38 ) ;
}
F_21 ( & V_34 ) ;
return V_33 ;
}
static T_2 F_28 ( struct V_28 * V_29 ,
struct V_30 * V_31 , const char * V_32 , T_3 V_37 )
{
const struct V_1 * V_4 = F_19 ( V_29 ) ;
unsigned V_8 = V_4 - V_1 ;
T_2 V_33 ;
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) )
V_33 = - V_13 ;
else if ( ! F_11 ( V_36 , & V_4 -> V_11 ) )
V_33 = - V_40 ;
else {
long V_38 ;
V_33 = F_29 ( V_32 , 0 , & V_38 ) ;
if ( V_33 == 0 ) {
if ( F_11 ( V_39 , & V_4 -> V_11 ) )
V_38 = ! V_38 ;
F_30 ( V_8 , V_38 != 0 ) ;
V_33 = V_37 ;
}
}
F_21 ( & V_34 ) ;
return V_33 ;
}
static T_4 F_31 ( int V_41 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
F_32 ( V_44 ) ;
return V_45 ;
}
static int F_33 ( struct V_1 * V_4 , struct V_28 * V_29 ,
unsigned long V_46 )
{
struct V_43 * V_44 ;
unsigned long V_47 ;
int V_23 , V_41 , V_48 ;
if ( ( V_4 -> V_11 & V_49 ) == V_46 )
return 0 ;
V_41 = F_34 ( V_4 - V_1 ) ;
if ( V_41 < 0 )
return - V_13 ;
V_48 = V_4 -> V_11 >> V_50 ;
V_44 = F_35 ( & V_51 , V_48 ) ;
if ( V_44 )
F_36 ( V_41 , V_44 ) ;
V_4 -> V_11 &= ~ V_49 ;
if ( ! V_46 ) {
V_23 = 0 ;
goto V_52;
}
V_47 = V_53 ;
if ( F_11 ( V_54 , & V_46 ) )
V_47 |= F_11 ( V_39 , & V_4 -> V_11 ) ?
V_55 : V_56 ;
if ( F_11 ( V_57 , & V_46 ) )
V_47 |= F_11 ( V_39 , & V_4 -> V_11 ) ?
V_56 : V_55 ;
if ( ! V_44 ) {
V_44 = F_37 ( V_29 -> V_58 . V_59 , NULL , L_12 ) ;
if ( ! V_44 ) {
V_23 = - V_60 ;
goto V_61;
}
do {
V_23 = - V_62 ;
if ( F_38 ( & V_51 , V_63 ) )
V_23 = F_39 ( & V_51 , V_44 ,
1 , & V_48 ) ;
} while ( V_23 == - V_64 );
if ( V_23 )
goto V_65;
V_4 -> V_11 &= V_66 ;
V_4 -> V_11 |= ( unsigned long ) V_48 << V_50 ;
if ( V_4 -> V_11 >> V_50 != V_48 ) {
V_23 = - V_67 ;
goto V_52;
}
}
V_23 = F_40 ( V_41 , F_31 , V_47 ,
L_13 , V_44 ) ;
if ( V_23 < 0 )
goto V_52;
V_4 -> V_11 |= V_46 ;
return 0 ;
V_52:
F_41 ( & V_51 , V_48 ) ;
V_4 -> V_11 &= V_66 ;
V_65:
if ( V_44 )
F_42 ( V_44 ) ;
V_61:
return V_23 ;
}
static T_2 F_43 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
const struct V_1 * V_4 = F_19 ( V_29 ) ;
T_2 V_33 ;
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) )
V_33 = - V_13 ;
else {
int V_16 ;
V_33 = 0 ;
for ( V_16 = 0 ; V_16 < F_44 ( V_68 ) ; V_16 ++ )
if ( ( V_4 -> V_11 & V_49 )
== V_68 [ V_16 ] . V_11 ) {
V_33 = sprintf ( V_32 , L_6 ,
V_68 [ V_16 ] . V_69 ) ;
break;
}
}
F_21 ( & V_34 ) ;
return V_33 ;
}
static T_2 F_45 ( struct V_28 * V_29 ,
struct V_30 * V_31 , const char * V_32 , T_3 V_37 )
{
struct V_1 * V_4 = F_19 ( V_29 ) ;
T_2 V_33 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_44 ( V_68 ) ; V_16 ++ )
if ( F_23 ( V_68 [ V_16 ] . V_69 , V_32 ) )
goto V_70;
return - V_24 ;
V_70:
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) )
V_33 = - V_13 ;
else {
V_33 = F_33 ( V_4 , V_29 , V_68 [ V_16 ] . V_11 ) ;
if ( ! V_33 )
V_33 = V_37 ;
}
F_21 ( & V_34 ) ;
return V_33 ;
}
static int F_46 ( struct V_1 * V_4 , struct V_28 * V_29 ,
int V_38 )
{
int V_33 = 0 ;
if ( ! ! F_11 ( V_39 , & V_4 -> V_11 ) == ! ! V_38 )
return 0 ;
if ( V_38 )
F_16 ( V_39 , & V_4 -> V_11 ) ;
else
F_8 ( V_39 , & V_4 -> V_11 ) ;
if ( V_29 != NULL && ( ! ! F_11 ( V_57 , & V_4 -> V_11 ) ^
! ! F_11 ( V_54 , & V_4 -> V_11 ) ) ) {
unsigned long V_71 = V_4 -> V_11 & V_49 ;
F_33 ( V_4 , V_29 , 0 ) ;
V_33 = F_33 ( V_4 , V_29 , V_71 ) ;
}
return V_33 ;
}
static T_2 F_47 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
const struct V_1 * V_4 = F_19 ( V_29 ) ;
T_2 V_33 ;
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) )
V_33 = - V_13 ;
else
V_33 = sprintf ( V_32 , L_11 ,
! ! F_11 ( V_39 , & V_4 -> V_11 ) ) ;
F_21 ( & V_34 ) ;
return V_33 ;
}
static T_2 F_48 ( struct V_28 * V_29 ,
struct V_30 * V_31 , const char * V_32 , T_3 V_37 )
{
struct V_1 * V_4 = F_19 ( V_29 ) ;
T_2 V_33 ;
F_20 ( & V_34 ) ;
if ( ! F_11 ( V_35 , & V_4 -> V_11 ) ) {
V_33 = - V_13 ;
} else {
long V_38 ;
V_33 = F_29 ( V_32 , 0 , & V_38 ) ;
if ( V_33 == 0 )
V_33 = F_46 ( V_4 , V_29 , V_38 != 0 ) ;
}
F_21 ( & V_34 ) ;
return V_33 ? : V_37 ;
}
static T_2 F_49 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
const struct V_6 * V_7 = F_19 ( V_29 ) ;
return sprintf ( V_32 , L_11 , V_7 -> V_9 ) ;
}
static T_2 F_50 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
const struct V_6 * V_7 = F_19 ( V_29 ) ;
return sprintf ( V_32 , L_6 , V_7 -> V_3 ? : L_14 ) ;
}
static T_2 F_51 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
const struct V_6 * V_7 = F_19 ( V_29 ) ;
return sprintf ( V_32 , L_15 , V_7 -> V_15 ) ;
}
static T_2 F_52 ( struct V_72 * V_72 ,
struct V_73 * V_31 ,
const char * V_32 , T_3 V_74 )
{
long V_8 ;
int V_33 ;
V_33 = F_29 ( V_32 , 0 , & V_8 ) ;
if ( V_33 < 0 )
goto V_75;
V_33 = F_53 ( V_8 , L_16 ) ;
if ( V_33 < 0 )
goto V_75;
V_33 = F_54 ( V_8 , true ) ;
if ( V_33 < 0 )
F_55 ( V_8 ) ;
else
F_16 ( V_76 , & V_1 [ V_8 ] . V_11 ) ;
V_75:
if ( V_33 )
F_13 ( L_17 , V_21 , V_33 ) ;
return V_33 ? : V_74 ;
}
static T_2 F_56 ( struct V_72 * V_72 ,
struct V_73 * V_31 ,
const char * V_32 , T_3 V_74 )
{
long V_8 ;
int V_33 ;
V_33 = F_29 ( V_32 , 0 , & V_8 ) ;
if ( V_33 < 0 )
goto V_75;
V_33 = - V_24 ;
if ( ! F_12 ( V_8 ) )
goto V_75;
if ( F_57 ( V_76 , & V_1 [ V_8 ] . V_11 ) ) {
V_33 = 0 ;
F_55 ( V_8 ) ;
}
V_75:
if ( V_33 )
F_13 ( L_17 , V_21 , V_33 ) ;
return V_33 ? : V_74 ;
}
int F_54 ( unsigned V_8 , bool V_77 )
{
unsigned long V_11 ;
struct V_1 * V_4 ;
int V_33 = - V_24 ;
const char * V_78 = NULL ;
if ( ! V_79 . V_80 ) {
F_13 ( L_18 , V_21 ) ;
return - V_81 ;
}
if ( ! F_12 ( V_8 ) )
goto V_75;
F_20 ( & V_34 ) ;
F_15 ( & V_25 , V_11 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( F_11 ( V_10 , & V_4 -> V_11 )
&& ! F_11 ( V_35 , & V_4 -> V_11 ) ) {
V_33 = 0 ;
if ( ! V_4 -> V_7 -> V_82
|| ! V_4 -> V_7 -> V_83 )
V_77 = false ;
}
F_17 ( & V_25 , V_11 ) ;
if ( V_4 -> V_7 -> V_84 && V_4 -> V_7 -> V_84 [ V_8 - V_4 -> V_7 -> V_9 ] )
V_78 = V_4 -> V_7 -> V_84 [ V_8 - V_4 -> V_7 -> V_9 ] ;
if ( V_33 == 0 ) {
struct V_28 * V_29 ;
V_29 = F_58 ( & V_79 , V_4 -> V_7 -> V_29 , F_59 ( 0 , 0 ) ,
V_4 , V_78 ? V_78 : L_19 , V_8 ) ;
if ( ! F_60 ( V_29 ) ) {
V_33 = F_61 ( & V_29 -> V_58 ,
& V_85 ) ;
if ( ! V_33 && V_77 )
V_33 = F_62 ( V_29 ,
& V_86 ) ;
if ( ! V_33 && F_34 ( V_8 ) >= 0
&& ( V_77
|| ! F_11 ( V_36 ,
& V_4 -> V_11 ) ) )
V_33 = F_62 ( V_29 ,
& V_87 ) ;
if ( V_33 != 0 )
F_63 ( V_29 ) ;
} else
V_33 = F_64 ( V_29 ) ;
if ( V_33 == 0 )
F_16 ( V_35 , & V_4 -> V_11 ) ;
}
F_21 ( & V_34 ) ;
V_75:
if ( V_33 )
F_13 ( L_20 , V_21 , V_8 , V_33 ) ;
return V_33 ;
}
static int F_65 ( struct V_28 * V_29 , void * V_88 )
{
return F_19 ( V_29 ) == V_88 ;
}
int F_66 ( struct V_28 * V_29 , const char * V_69 , unsigned V_8 )
{
struct V_1 * V_4 ;
int V_33 = - V_24 ;
if ( ! F_12 ( V_8 ) )
goto V_75;
F_20 ( & V_34 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( F_11 ( V_35 , & V_4 -> V_11 ) ) {
struct V_28 * V_89 ;
V_89 = F_67 ( & V_79 , NULL , V_4 , F_65 ) ;
if ( V_89 != NULL ) {
V_33 = F_68 ( & V_29 -> V_58 , & V_89 -> V_58 ,
V_69 ) ;
} else {
V_33 = - V_60 ;
}
}
F_21 ( & V_34 ) ;
V_75:
if ( V_33 )
F_13 ( L_20 , V_21 , V_8 , V_33 ) ;
return V_33 ;
}
int F_69 ( unsigned V_8 , int V_38 )
{
struct V_1 * V_4 ;
struct V_28 * V_29 = NULL ;
int V_33 = - V_24 ;
if ( ! F_12 ( V_8 ) )
goto V_75;
F_20 ( & V_34 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( F_11 ( V_35 , & V_4 -> V_11 ) ) {
V_29 = F_67 ( & V_79 , NULL , V_4 , F_65 ) ;
if ( V_29 == NULL ) {
V_33 = - V_60 ;
goto V_90;
}
}
V_33 = F_46 ( V_4 , V_29 , V_38 ) ;
V_90:
F_21 ( & V_34 ) ;
V_75:
if ( V_33 )
F_13 ( L_20 , V_21 , V_8 , V_33 ) ;
return V_33 ;
}
void F_70 ( unsigned V_8 )
{
struct V_1 * V_4 ;
int V_33 = 0 ;
struct V_28 * V_29 = NULL ;
if ( ! F_12 ( V_8 ) ) {
V_33 = - V_24 ;
goto V_75;
}
F_20 ( & V_34 ) ;
V_4 = & V_1 [ V_8 ] ;
if ( F_11 ( V_35 , & V_4 -> V_11 ) ) {
V_29 = F_67 ( & V_79 , NULL , V_4 , F_65 ) ;
if ( V_29 ) {
F_33 ( V_4 , V_29 , 0 ) ;
F_8 ( V_35 , & V_4 -> V_11 ) ;
} else
V_33 = - V_60 ;
}
F_21 ( & V_34 ) ;
if ( V_29 ) {
F_63 ( V_29 ) ;
F_71 ( V_29 ) ;
}
V_75:
if ( V_33 )
F_13 ( L_20 , V_21 , V_8 , V_33 ) ;
}
static int F_72 ( struct V_6 * V_7 )
{
int V_33 ;
struct V_28 * V_29 ;
if ( ! V_79 . V_80 )
return 0 ;
F_20 ( & V_34 ) ;
V_29 = F_58 ( & V_79 , V_7 -> V_29 , F_59 ( 0 , 0 ) , V_7 ,
L_21 , V_7 -> V_9 ) ;
if ( ! F_60 ( V_29 ) ) {
V_33 = F_61 ( & V_29 -> V_58 ,
& V_91 ) ;
} else
V_33 = F_64 ( V_29 ) ;
V_7 -> V_92 = ( V_33 == 0 ) ;
F_21 ( & V_34 ) ;
if ( V_33 ) {
unsigned long V_11 ;
unsigned V_8 ;
F_15 ( & V_25 , V_11 ) ;
V_8 = V_7 -> V_9 ;
while ( V_1 [ V_8 ] . V_7 == V_7 )
V_1 [ V_8 ++ ] . V_7 = NULL ;
F_17 ( & V_25 , V_11 ) ;
F_13 ( L_22 , V_21 ,
V_7 -> V_3 , V_33 ) ;
}
return V_33 ;
}
static void F_73 ( struct V_6 * V_7 )
{
int V_33 ;
struct V_28 * V_29 ;
F_20 ( & V_34 ) ;
V_29 = F_67 ( & V_79 , NULL , V_7 , F_65 ) ;
if ( V_29 ) {
F_71 ( V_29 ) ;
F_63 ( V_29 ) ;
V_7 -> V_92 = 0 ;
V_33 = 0 ;
} else
V_33 = - V_60 ;
F_21 ( & V_34 ) ;
if ( V_33 )
F_13 ( L_22 , V_21 ,
V_7 -> V_3 , V_33 ) ;
}
static int T_1 F_74 ( void )
{
int V_33 ;
unsigned long V_11 ;
unsigned V_8 ;
V_33 = F_75 ( & V_79 ) ;
if ( V_33 < 0 )
return V_33 ;
F_15 ( & V_25 , V_11 ) ;
for ( V_8 = 0 ; V_8 < V_19 ; V_8 ++ ) {
struct V_6 * V_7 ;
V_7 = V_1 [ V_8 ] . V_7 ;
if ( ! V_7 || V_7 -> V_92 )
continue;
F_17 ( & V_25 , V_11 ) ;
V_33 = F_72 ( V_7 ) ;
F_15 ( & V_25 , V_11 ) ;
}
F_17 ( & V_25 , V_11 ) ;
return V_33 ;
}
static inline int F_72 ( struct V_6 * V_7 )
{
return 0 ;
}
static inline void F_73 ( struct V_6 * V_7 )
{
}
int F_76 ( struct V_6 * V_7 )
{
unsigned long V_11 ;
int V_33 = 0 ;
unsigned V_48 ;
int V_9 = V_7 -> V_9 ;
if ( ( ! F_12 ( V_9 ) || ! F_12 ( V_9 + V_7 -> V_15 - 1 ) )
&& V_9 >= 0 ) {
V_33 = - V_24 ;
goto V_93;
}
F_15 ( & V_25 , V_11 ) ;
if ( V_9 < 0 ) {
V_9 = F_10 ( V_7 -> V_15 ) ;
if ( V_9 < 0 ) {
V_33 = V_9 ;
goto V_90;
}
V_7 -> V_9 = V_9 ;
}
for ( V_48 = V_9 ; V_48 < V_9 + V_7 -> V_15 ; V_48 ++ ) {
if ( V_1 [ V_48 ] . V_7 != NULL ) {
V_33 = - V_26 ;
break;
}
}
if ( V_33 == 0 ) {
for ( V_48 = V_9 ; V_48 < V_9 + V_7 -> V_15 ; V_48 ++ ) {
V_1 [ V_48 ] . V_7 = V_7 ;
V_1 [ V_48 ] . V_11 = ! V_7 -> V_82
? ( 1 << V_36 )
: 0 ;
}
}
F_77 ( V_7 ) ;
V_90:
F_17 ( & V_25 , V_11 ) ;
if ( V_33 )
goto V_93;
V_33 = F_72 ( V_7 ) ;
if ( V_33 )
goto V_93;
F_13 ( L_23 ,
V_7 -> V_9 , V_7 -> V_9 + V_7 -> V_15 - 1 ,
V_7 -> V_3 ? : L_24 ) ;
return 0 ;
V_93:
F_7 ( L_25 ,
V_7 -> V_9 , V_7 -> V_9 + V_7 -> V_15 - 1 ,
V_7 -> V_3 ? : L_24 ) ;
return V_33 ;
}
int F_78 ( struct V_6 * V_7 )
{
unsigned long V_11 ;
int V_33 = 0 ;
unsigned V_48 ;
F_15 ( & V_25 , V_11 ) ;
F_79 ( V_7 ) ;
for ( V_48 = V_7 -> V_9 ; V_48 < V_7 -> V_9 + V_7 -> V_15 ; V_48 ++ ) {
if ( F_11 ( V_10 , & V_1 [ V_48 ] . V_11 ) ) {
V_33 = - V_26 ;
break;
}
}
if ( V_33 == 0 ) {
for ( V_48 = V_7 -> V_9 ; V_48 < V_7 -> V_9 + V_7 -> V_15 ; V_48 ++ )
V_1 [ V_48 ] . V_7 = NULL ;
}
F_17 ( & V_25 , V_11 ) ;
if ( V_33 == 0 )
F_73 ( V_7 ) ;
return V_33 ;
}
struct V_6 * F_80 ( void * V_88 ,
int (* F_81)( struct V_6 * V_7 ,
void * V_88 ) )
{
struct V_6 * V_7 = NULL ;
unsigned long V_11 ;
int V_16 ;
F_15 ( & V_25 , V_11 ) ;
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ ) {
if ( ! V_1 [ V_16 ] . V_7 )
continue;
if ( F_81 ( V_1 [ V_16 ] . V_7 , V_88 ) ) {
V_7 = V_1 [ V_16 ] . V_7 ;
break;
}
}
F_17 ( & V_25 , V_11 ) ;
return V_7 ;
}
int F_53 ( unsigned V_8 , const char * V_3 )
{
struct V_1 * V_4 ;
struct V_6 * V_7 ;
int V_33 = - V_24 ;
unsigned long V_11 ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) )
goto V_75;
V_4 = & V_1 [ V_8 ] ;
V_7 = V_4 -> V_7 ;
if ( V_7 == NULL )
goto V_75;
if ( ! F_6 ( V_7 -> V_12 ) )
goto V_75;
if ( F_5 ( V_10 , & V_4 -> V_11 ) == 0 ) {
F_1 ( V_4 , V_3 ? : L_26 ) ;
V_33 = 0 ;
} else {
V_33 = - V_26 ;
F_82 ( V_7 -> V_12 ) ;
goto V_75;
}
if ( V_7 -> V_14 ) {
F_17 ( & V_25 , V_11 ) ;
V_33 = V_7 -> V_14 ( V_7 , V_8 - V_7 -> V_9 ) ;
F_15 ( & V_25 , V_11 ) ;
if ( V_33 < 0 ) {
F_1 ( V_4 , NULL ) ;
F_82 ( V_7 -> V_12 ) ;
F_8 ( V_10 , & V_4 -> V_11 ) ;
}
}
V_75:
if ( V_33 )
F_13 ( L_27 ,
V_8 , V_3 ? : L_26 , V_33 ) ;
F_17 ( & V_25 , V_11 ) ;
return V_33 ;
}
void F_55 ( unsigned V_8 )
{
unsigned long V_11 ;
struct V_1 * V_4 ;
struct V_6 * V_7 ;
F_83 () ;
if ( ! F_12 ( V_8 ) ) {
F_84 ( V_94 ) ;
return;
}
F_70 ( V_8 ) ;
F_15 ( & V_25 , V_11 ) ;
V_4 = & V_1 [ V_8 ] ;
V_7 = V_4 -> V_7 ;
if ( V_7 && F_11 ( V_10 , & V_4 -> V_11 ) ) {
if ( V_7 -> free ) {
F_17 ( & V_25 , V_11 ) ;
F_85 ( V_7 -> V_95 ) ;
V_7 -> free ( V_7 , V_8 - V_7 -> V_9 ) ;
F_15 ( & V_25 , V_11 ) ;
}
F_1 ( V_4 , NULL ) ;
F_82 ( V_4 -> V_7 -> V_12 ) ;
F_8 ( V_39 , & V_4 -> V_11 ) ;
F_8 ( V_10 , & V_4 -> V_11 ) ;
F_8 ( V_96 , & V_4 -> V_11 ) ;
F_8 ( V_97 , & V_4 -> V_11 ) ;
} else
F_84 ( V_94 ) ;
F_17 ( & V_25 , V_11 ) ;
}
int F_86 ( unsigned V_8 , unsigned long V_11 , const char * V_3 )
{
int V_27 ;
V_27 = F_53 ( V_8 , V_3 ) ;
if ( V_27 )
return V_27 ;
if ( V_11 & V_98 )
F_16 ( V_96 , & V_1 [ V_8 ] . V_11 ) ;
if ( V_11 & V_99 )
F_16 ( V_97 , & V_1 [ V_8 ] . V_11 ) ;
if ( V_11 & V_100 )
V_27 = F_25 ( V_8 ) ;
else
V_27 = F_24 ( V_8 ,
( V_11 & V_101 ) ? 1 : 0 ) ;
if ( V_27 )
goto V_102;
if ( V_11 & V_103 ) {
V_27 = F_54 ( V_8 , V_11 & V_104 ) ;
if ( V_27 )
goto V_102;
}
return 0 ;
V_102:
F_55 ( V_8 ) ;
return V_27 ;
}
int F_87 ( const struct V_8 * V_105 , T_3 V_106 )
{
int V_16 , V_27 ;
for ( V_16 = 0 ; V_16 < V_106 ; V_16 ++ , V_105 ++ ) {
V_27 = F_86 ( V_105 -> V_8 , V_105 -> V_11 , V_105 -> V_3 ) ;
if ( V_27 )
goto V_107;
}
return 0 ;
V_107:
while ( V_16 -- )
F_55 ( ( -- V_105 ) -> V_8 ) ;
return V_27 ;
}
void F_88 ( const struct V_8 * V_105 , T_3 V_106 )
{
while ( V_106 -- )
F_55 ( ( V_105 ++ ) -> V_8 ) ;
}
const char * F_89 ( struct V_6 * V_7 , unsigned V_5 )
{
unsigned V_8 = V_7 -> V_9 + V_5 ;
if ( ! F_12 ( V_8 ) || V_1 [ V_8 ] . V_7 != V_7 )
return NULL ;
if ( F_11 ( V_10 , & V_1 [ V_8 ] . V_11 ) == 0 )
return NULL ;
#ifdef F_2
return V_1 [ V_8 ] . V_3 ;
#else
return L_26 ;
#endif
}
int F_25 ( unsigned V_8 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_1 * V_4 = & V_1 [ V_8 ] ;
int V_33 = - V_24 ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) )
goto V_93;
V_7 = V_4 -> V_7 ;
if ( ! V_7 || ! V_7 -> V_108 || ! V_7 -> V_82 )
goto V_93;
V_8 -= V_7 -> V_9 ;
if ( V_8 >= V_7 -> V_15 )
goto V_93;
V_33 = F_3 ( V_4 , V_8 ) ;
if ( V_33 < 0 )
goto V_93;
F_17 ( & V_25 , V_11 ) ;
F_85 ( V_7 -> V_95 ) ;
if ( V_33 ) {
V_33 = V_7 -> V_14 ( V_7 , V_8 ) ;
if ( V_33 < 0 ) {
F_13 ( L_28 ,
V_7 -> V_9 + V_8 , V_33 ) ;
goto V_109;
}
}
V_33 = V_7 -> V_82 ( V_7 , V_8 ) ;
if ( V_33 == 0 )
F_8 ( V_36 , & V_4 -> V_11 ) ;
F_90 ( V_7 -> V_9 + V_8 , 1 , V_33 ) ;
V_109:
return V_33 ;
V_93:
F_17 ( & V_25 , V_11 ) ;
if ( V_33 )
F_13 ( L_29 ,
V_21 , V_8 , V_33 ) ;
return V_33 ;
}
int F_24 ( unsigned V_8 , int V_38 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_1 * V_4 = & V_1 [ V_8 ] ;
int V_33 = - V_24 ;
if ( V_38 && F_11 ( V_96 , & V_4 -> V_11 ) )
return F_25 ( V_8 ) ;
if ( ! V_38 && F_11 ( V_97 , & V_4 -> V_11 ) )
return F_25 ( V_8 ) ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) )
goto V_93;
V_7 = V_4 -> V_7 ;
if ( ! V_7 || ! V_7 -> V_110 || ! V_7 -> V_83 )
goto V_93;
V_8 -= V_7 -> V_9 ;
if ( V_8 >= V_7 -> V_15 )
goto V_93;
V_33 = F_3 ( V_4 , V_8 ) ;
if ( V_33 < 0 )
goto V_93;
F_17 ( & V_25 , V_11 ) ;
F_85 ( V_7 -> V_95 ) ;
if ( V_33 ) {
V_33 = V_7 -> V_14 ( V_7 , V_8 ) ;
if ( V_33 < 0 ) {
F_13 ( L_28 ,
V_7 -> V_9 + V_8 , V_33 ) ;
goto V_109;
}
}
V_33 = V_7 -> V_83 ( V_7 , V_8 , V_38 ) ;
if ( V_33 == 0 )
F_16 ( V_36 , & V_4 -> V_11 ) ;
F_91 ( V_7 -> V_9 + V_8 , 0 , V_38 ) ;
F_90 ( V_7 -> V_9 + V_8 , 0 , V_33 ) ;
V_109:
return V_33 ;
V_93:
F_17 ( & V_25 , V_11 ) ;
if ( V_33 )
F_13 ( L_29 ,
V_21 , V_8 , V_33 ) ;
return V_33 ;
}
int F_92 ( unsigned V_8 , unsigned V_111 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_1 * V_4 = & V_1 [ V_8 ] ;
int V_33 = - V_24 ;
F_15 ( & V_25 , V_11 ) ;
if ( ! F_12 ( V_8 ) )
goto V_93;
V_7 = V_4 -> V_7 ;
if ( ! V_7 || ! V_7 -> V_110 || ! V_7 -> V_112 )
goto V_93;
V_8 -= V_7 -> V_9 ;
if ( V_8 >= V_7 -> V_15 )
goto V_93;
V_33 = F_3 ( V_4 , V_8 ) ;
if ( V_33 < 0 )
goto V_93;
F_17 ( & V_25 , V_11 ) ;
F_85 ( V_7 -> V_95 ) ;
return V_7 -> V_112 ( V_7 , V_8 , V_111 ) ;
V_93:
F_17 ( & V_25 , V_11 ) ;
if ( V_33 )
F_13 ( L_29 ,
V_21 , V_8 , V_33 ) ;
return V_33 ;
}
int F_93 ( unsigned V_8 )
{
struct V_6 * V_7 ;
int V_38 ;
V_7 = F_9 ( V_8 ) ;
F_84 ( V_7 -> V_95 ) ;
V_38 = V_7 -> V_108 ? V_7 -> V_108 ( V_7 , V_8 - V_7 -> V_9 ) : 0 ;
F_91 ( V_8 , 1 , V_38 ) ;
return V_38 ;
}
static void F_94 ( unsigned V_8 ,
struct V_6 * V_7 , int V_38 )
{
int V_27 = 0 ;
if ( V_38 ) {
V_27 = V_7 -> V_82 ( V_7 , V_8 - V_7 -> V_9 ) ;
if ( ! V_27 )
F_8 ( V_36 , & V_1 [ V_8 ] . V_11 ) ;
} else {
V_27 = V_7 -> V_83 ( V_7 , V_8 - V_7 -> V_9 , 0 ) ;
if ( ! V_27 )
F_16 ( V_36 , & V_1 [ V_8 ] . V_11 ) ;
}
F_90 ( V_8 , V_38 , V_27 ) ;
if ( V_27 < 0 )
F_7 ( L_30 ,
V_21 , V_8 , V_27 ) ;
}
static void F_95 ( unsigned V_8 ,
struct V_6 * V_7 , int V_38 )
{
int V_27 = 0 ;
if ( V_38 ) {
V_27 = V_7 -> V_83 ( V_7 , V_8 - V_7 -> V_9 , 1 ) ;
if ( ! V_27 )
F_16 ( V_36 , & V_1 [ V_8 ] . V_11 ) ;
} else {
V_27 = V_7 -> V_82 ( V_7 , V_8 - V_7 -> V_9 ) ;
if ( ! V_27 )
F_8 ( V_36 , & V_1 [ V_8 ] . V_11 ) ;
}
F_90 ( V_8 , ! V_38 , V_27 ) ;
if ( V_27 < 0 )
F_7 ( L_31 ,
V_21 , V_8 , V_27 ) ;
}
void F_96 ( unsigned V_8 , int V_38 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_8 ) ;
F_84 ( V_7 -> V_95 ) ;
F_91 ( V_8 , 0 , V_38 ) ;
if ( F_11 ( V_96 , & V_1 [ V_8 ] . V_11 ) )
F_94 ( V_8 , V_7 , V_38 ) ;
else if ( F_11 ( V_97 , & V_1 [ V_8 ] . V_11 ) )
F_95 ( V_8 , V_7 , V_38 ) ;
else
V_7 -> V_110 ( V_7 , V_8 - V_7 -> V_9 , V_38 ) ;
}
int F_97 ( unsigned V_8 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_8 ) ;
return V_7 -> V_95 ;
}
int F_98 ( unsigned V_8 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_8 ) ;
return V_7 -> V_113 ? V_7 -> V_113 ( V_7 , V_8 - V_7 -> V_9 ) : - V_114 ;
}
int F_27 ( unsigned V_8 )
{
struct V_6 * V_7 ;
int V_38 ;
F_85 ( V_94 ) ;
V_7 = F_9 ( V_8 ) ;
V_38 = V_7 -> V_108 ? V_7 -> V_108 ( V_7 , V_8 - V_7 -> V_9 ) : 0 ;
F_91 ( V_8 , 1 , V_38 ) ;
return V_38 ;
}
void F_30 ( unsigned V_8 , int V_38 )
{
struct V_6 * V_7 ;
F_85 ( V_94 ) ;
V_7 = F_9 ( V_8 ) ;
F_91 ( V_8 , 0 , V_38 ) ;
if ( F_11 ( V_96 , & V_1 [ V_8 ] . V_11 ) )
F_94 ( V_8 , V_7 , V_38 ) ;
else if ( F_11 ( V_97 , & V_1 [ V_8 ] . V_11 ) )
F_95 ( V_8 , V_7 , V_38 ) ;
else
V_7 -> V_110 ( V_7 , V_8 - V_7 -> V_9 , V_38 ) ;
}
static void F_99 ( struct V_115 * V_116 , struct V_6 * V_7 )
{
unsigned V_16 ;
unsigned V_8 = V_7 -> V_9 ;
struct V_1 * V_117 = & V_1 [ V_8 ] ;
int V_118 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_15 ; V_16 ++ , V_8 ++ , V_117 ++ ) {
if ( ! F_11 ( V_10 , & V_117 -> V_11 ) )
continue;
V_118 = F_11 ( V_36 , & V_117 -> V_11 ) ;
F_100 ( V_116 , L_32 ,
V_8 , V_117 -> V_3 ,
V_118 ? L_7 : L_33 ,
V_7 -> V_108
? ( V_7 -> V_108 ( V_7 , V_16 ) ? L_34 : L_35 )
: L_36 ) ;
F_100 ( V_116 , L_37 ) ;
}
}
static int F_101 ( struct V_115 * V_116 , void * V_119 )
{
struct V_6 * V_7 = NULL ;
unsigned V_8 ;
int V_120 = 0 ;
for ( V_8 = 0 ; F_12 ( V_8 ) ; V_8 ++ ) {
struct V_28 * V_29 ;
if ( V_7 == V_1 [ V_8 ] . V_7 )
continue;
V_7 = V_1 [ V_8 ] . V_7 ;
if ( ! V_7 )
continue;
F_100 ( V_116 , L_38 ,
V_120 ? L_37 : L_14 ,
V_7 -> V_9 , V_7 -> V_9 + V_7 -> V_15 - 1 ) ;
V_29 = V_7 -> V_29 ;
if ( V_29 )
F_100 ( V_116 , L_39 ,
V_29 -> V_121 ? V_29 -> V_121 -> V_69 : L_40 ,
F_102 ( V_29 ) ) ;
if ( V_7 -> V_3 )
F_100 ( V_116 , L_41 , V_7 -> V_3 ) ;
if ( V_7 -> V_95 )
F_100 ( V_116 , L_42 ) ;
F_100 ( V_116 , L_43 ) ;
V_120 = 1 ;
if ( V_7 -> V_122 )
V_7 -> V_122 ( V_116 , V_7 ) ;
else
F_99 ( V_116 , V_7 ) ;
}
return 0 ;
}
static int F_103 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
return F_104 ( V_124 , F_101 , NULL ) ;
}
static int T_1 F_105 ( void )
{
( void ) F_106 ( L_44 , V_125 | V_126 ,
NULL , NULL , & V_127 ) ;
return 0 ;
}
