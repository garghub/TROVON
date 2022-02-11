void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
F_3 ( & V_4 -> V_5 ) ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_11 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned int V_12 ;
F_2 ( & V_11 -> V_5 ) ;
do {
V_12 = F_5 ( & V_4 -> V_5 ) ;
V_11 -> V_6 = V_4 -> V_6 ;
V_11 -> V_7 = V_4 -> V_7 ;
V_11 -> V_8 = V_4 -> V_8 ;
V_11 -> V_9 = V_4 -> V_9 ;
V_11 -> V_10 = V_4 -> V_10 ;
} while ( F_6 ( & V_4 -> V_5 , V_12 ) );
F_3 ( & V_11 -> V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_8 ( & V_4 -> V_5 ) ;
F_1 ( V_2 ) ;
}
static int F_9 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
struct V_23 * V_24 = V_22 -> V_24 ;
struct V_25 * V_26 ;
T_1 V_27 ;
int V_28 , V_29 ;
V_27 = F_10 ( & V_24 -> V_30 , V_16 -> V_31 , F_11 ( V_16 ) ,
V_32 ) ;
if ( F_12 ( & V_24 -> V_30 , V_27 ) ) {
F_13 ( & V_24 -> V_30 , L_1 ) ;
return - V_33 ;
}
F_14 ( & V_18 [ 0 ] , V_27 , F_11 ( V_16 ) ) ;
for ( V_28 = 0 ; V_28 < F_15 ( V_16 ) -> V_34 ; V_28 ++ ) {
V_26 = & F_15 ( V_16 ) -> V_35 [ V_28 ] ;
V_27 = F_16 ( & V_24 -> V_30 , V_26 , 0 ,
F_17 ( V_26 ) ,
V_32 ) ;
if ( F_12 ( & V_24 -> V_30 , V_27 ) ) {
F_13 ( & V_24 -> V_30 , L_2 ) ;
goto V_36;
}
F_14 ( & V_18 [ V_28 + 1 ] , V_27 , F_17 ( V_26 ) ) ;
}
return 0 ;
V_36:
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
F_18 ( & V_24 -> V_30 , F_19 ( & V_18 [ V_29 + 1 ] ) ,
V_18 [ V_29 + 1 ] . V_37 , V_32 ) ;
F_20 ( & V_24 -> V_30 , F_19 ( & V_18 [ 0 ] ) , V_18 [ 0 ] . V_37 ,
V_32 ) ;
return - V_33 ;
}
static void F_21 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
struct V_23 * V_24 = V_22 -> V_24 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_15 ( V_16 ) -> V_34 ; V_28 ++ )
F_18 ( & V_24 -> V_30 , F_19 ( & V_18 [ V_28 + 1 ] ) ,
V_18 [ V_28 + 1 ] . V_37 , V_32 ) ;
F_20 ( & V_24 -> V_30 , F_19 ( & V_18 [ 0 ] ) , V_18 [ 0 ] . V_37 ,
V_32 ) ;
}
T_2 F_22 ( struct V_15 * V_16 , struct V_38 * V_39 )
{
struct V_13 * V_14 = F_23 ( V_39 ) ;
struct V_40 * V_41 ;
int V_42 , V_43 = V_44 ;
struct V_45 * V_46 ;
unsigned int V_47 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
T_3 V_50 ;
V_2 = & V_14 -> V_51 [ V_16 -> V_52 ] ;
V_49 = F_24 ( V_2 -> V_53 , struct V_48 , V_53 ) ;
if ( V_16 -> V_37 < V_54 ) {
if ( F_25 ( V_16 , V_54 - V_16 -> V_37 ) ) {
F_26 ( V_39 , L_3 ) ;
goto V_55;
}
V_16 -> V_37 = V_54 ;
}
V_42 = F_15 ( V_16 ) -> V_34 + 1 ;
if ( V_42 > V_2 -> V_56 ) {
F_26 ( V_39 , L_4 ) ;
goto V_57;
}
V_43 = F_9 ( V_14 , V_16 , V_2 -> V_18 ) ;
if ( V_43 )
goto V_57;
V_47 = F_27 ( V_42 ) ;
V_46 = F_28 ( V_2 -> V_53 , V_47 , & V_50 ) ;
if ( ! V_46 ) {
F_21 ( V_14 , V_16 , V_2 -> V_18 ) ;
F_29 ( V_39 , V_49 -> V_58 ) ;
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_8 ++ ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
V_43 = V_59 ;
goto V_60;
}
F_30 ( V_2 -> V_53 , V_50 , V_46 , V_2 -> V_18 , V_42 ) ;
F_31 ( V_2 -> V_53 , V_50 , V_46 , V_16 , V_47 ) ;
V_60:
V_41 = F_32 ( V_39 , V_16 -> V_52 ) ;
if ( ( ! V_16 -> V_61 ) || ( F_33 ( V_41 ) ) )
F_34 ( V_2 -> V_53 , V_50 , V_47 , 0 ) ;
return V_43 ;
V_57:
F_35 ( V_16 ) ;
V_55:
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_10 ++ ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
return V_43 ;
}
static void F_36 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
F_21 ( V_14 , V_16 , V_18 ) ;
F_35 ( V_16 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_23 ( V_2 -> V_39 ) ;
struct V_62 * V_53 = V_2 -> V_53 ;
struct V_45 * V_46 ;
unsigned int V_47 ;
struct V_15 * V_16 ;
int V_42 ;
T_3 V_63 ;
while ( ( V_46 = F_38 ( V_53 , & V_16 , & V_47 , & V_63 ) ) ) {
V_42 = F_15 ( V_16 ) -> V_34 + 1 ;
F_39 ( V_46 , V_2 -> V_64 , V_42 ) ;
F_40 ( V_53 , V_47 ) ;
F_36 ( V_14 , V_16 , V_2 -> V_64 ) ;
}
}
static int F_41 ( struct V_65 * V_66 , int V_67 )
{
struct V_1 * V_2 = F_24 ( V_66 , struct V_1 , V_66 ) ;
struct V_48 * V_49 = F_24 ( V_2 -> V_53 , struct V_48 , V_53 ) ;
struct V_13 * V_14 = F_23 ( V_2 -> V_39 ) ;
struct V_40 * V_41 ;
struct V_62 * V_53 = V_2 -> V_53 ;
struct V_68 * V_69 = V_53 -> V_69 ;
struct V_45 * V_46 ;
unsigned int V_47 ;
int V_42 , V_6 = 0 ;
struct V_15 * V_16 ;
T_4 V_70 = 0 ;
T_3 V_71 , V_72 ;
do {
V_71 = F_42 ( V_53 ) & V_69 -> V_73 ;
V_46 = F_38 ( V_53 , & V_16 , & V_47 , & V_72 ) ;
if ( ( ! V_46 ) ||
( ( ( V_71 - V_72 ) & V_69 -> V_73 ) * V_69 -> V_74 < V_47 ) )
break;
V_70 += V_16 -> V_37 ;
V_6 ++ ;
V_42 = F_15 ( V_16 ) -> V_34 + 1 ;
F_39 ( V_46 , V_2 -> V_64 , V_42 ) ;
F_40 ( V_53 , V_47 ) ;
F_36 ( V_14 , V_16 , V_2 -> V_64 ) ;
} while ( V_6 < V_67 );
if ( F_43 ( V_14 -> V_39 , V_49 -> V_58 ) &&
F_44 ( V_53 ) >= F_45 ( V_53 ) ) {
V_41 = F_32 ( V_2 -> V_39 , V_49 -> V_58 ) ;
F_46 ( V_41 , F_47 () ) ;
F_48 ( V_14 -> V_39 , V_49 -> V_58 ) ;
F_49 ( V_41 ) ;
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_9 ++ ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
}
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_7 += V_70 ;
V_2 -> V_4 . V_6 += V_6 ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
if ( V_6 < V_67 ) {
F_50 ( V_66 ) ;
F_51 ( V_53 -> V_75 ) ;
return V_6 ;
}
return V_67 ;
}
static void F_52 ( struct V_1 * V_2 , int V_76 )
{
F_53 ( V_2 -> V_39 , & V_2 -> V_66 , F_41 , V_76 ) ;
F_54 ( & V_2 -> V_66 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_66 ) ;
F_57 ( & V_2 -> V_66 ) ;
}
static T_5 F_58 ( int V_75 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_13 * V_14 ;
V_14 = F_23 ( V_2 -> V_39 ) ;
F_59 ( V_2 -> V_53 -> V_75 ) ;
F_60 ( V_14 -> V_20 , V_2 -> V_53 -> V_77 ) ;
F_61 ( & V_2 -> V_66 ) ;
return V_78 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_23 ( V_2 -> V_39 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
struct V_23 * V_24 = V_22 -> V_24 ;
struct V_62 * V_53 = V_2 -> V_53 ;
int V_43 ;
F_52 ( V_2 , V_14 -> V_79 ) ;
F_63 ( V_14 -> V_20 , V_53 -> V_77 ,
V_80 , V_81 ,
V_82 , V_83 ,
V_84 ) ;
V_43 = F_64 ( V_53 -> V_75 , F_58 , 0 , V_2 -> V_85 , V_2 ) ;
if ( V_43 ) {
F_13 ( & V_24 -> V_30 , L_5 ) ;
F_55 ( V_2 ) ;
return V_43 ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_62 * V_53 = V_2 -> V_53 ;
F_66 ( V_53 -> V_75 , V_2 ) ;
F_55 ( V_2 ) ;
}
int F_67 ( struct V_1 * V_2 , struct V_62 * V_53 ,
struct V_38 * V_39 )
{
struct V_48 * V_49 = F_24 ( V_53 , struct V_48 , V_53 ) ;
struct V_13 * V_14 = F_23 ( V_39 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
int V_43 , V_86 ;
T_6 V_87 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_53 = V_53 ;
F_7 ( V_2 ) ;
V_2 -> V_56 = V_88 ;
V_87 = V_2 -> V_56 * sizeof( * V_2 -> V_18 ) ;
V_2 -> V_18 = F_68 ( & V_39 -> V_30 , V_87 , V_89 ) ;
if ( ! V_2 -> V_18 )
return - V_90 ;
V_87 = V_2 -> V_56 * sizeof( * V_2 -> V_64 ) ;
V_2 -> V_64 = F_68 ( & V_39 -> V_30 , V_87 , V_89 ) ;
if ( ! V_2 -> V_64 ) {
V_43 = - V_90 ;
goto V_91;
}
V_86 = snprintf ( NULL , 0 , L_6 , V_49 -> V_58 ) + 1 ;
V_2 -> V_85 = F_68 ( & V_39 -> V_30 , V_86 , V_89 ) ;
if ( ! V_2 -> V_85 ) {
V_43 = - V_90 ;
goto V_92;
}
sprintf ( V_2 -> V_85 , L_6 , V_49 -> V_58 ) ;
V_43 = F_69 ( V_20 , V_53 , V_93 ,
V_94 ) ;
if ( V_43 )
goto V_95;
V_43 = F_62 ( V_2 ) ;
if ( V_43 ) {
F_26 ( V_39 , L_5 ) ;
goto V_96;
}
return 0 ;
V_96:
V_95:
F_70 ( & V_39 -> V_30 , V_2 -> V_85 ) ;
V_92:
F_70 ( & V_39 -> V_30 , V_2 -> V_64 ) ;
V_91:
F_70 ( & V_39 -> V_30 , V_2 -> V_18 ) ;
return V_43 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_65 ( V_2 ) ;
F_37 ( V_2 ) ;
F_70 ( & V_39 -> V_30 , V_2 -> V_85 ) ;
F_70 ( & V_39 -> V_30 , V_2 -> V_64 ) ;
F_70 ( & V_39 -> V_30 , V_2 -> V_18 ) ;
}
