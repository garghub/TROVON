int F_1 ( void )
{
return F_2 ( V_1 ) ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_6 ( V_3 != NULL ) ;
F_7 ( & V_3 -> V_4 ) ;
V_3 -> V_5 |= V_6 ;
}
static int F_8 ( struct V_7 * V_8 ,
const char * V_9 ,
struct V_10 * * V_11 )
{
struct V_10 * V_12 ;
F_9 (entry, cache, xe_list) {
if ( V_9 == NULL ||
strcmp ( V_9 , V_12 -> V_13 ) == 0 ) {
* V_11 = V_12 ;
F_10 ( V_14 , L_1 ,
V_12 -> V_13 , V_12 -> V_15 ,
V_12 -> V_16 ) ;
return 0 ;
}
}
return - V_17 ;
}
static int F_11 ( struct V_7 * V_8 ,
const char * V_9 ,
const char * V_18 ,
unsigned V_19 )
{
struct V_10 * V_11 ;
if ( F_8 ( V_8 , V_9 , & V_11 ) == 0 ) {
F_10 ( V_14 , L_2 , V_9 ) ;
return - V_20 ;
}
V_11 = F_12 ( V_21 , V_22 | V_23 ) ;
if ( V_11 == NULL ) {
F_10 ( V_14 , L_3 ) ;
return - V_24 ;
}
V_11 -> V_13 = F_13 ( V_9 , V_22 ) ;
if ( ! V_11 -> V_13 ) {
F_10 ( V_14 , L_4 ,
V_11 -> V_25 ) ;
goto V_26;
}
V_11 -> V_16 = F_14 ( V_18 , V_19 , V_22 ) ;
if ( ! V_11 -> V_16 )
goto V_27;
V_11 -> V_15 = V_19 ;
F_15 ( & V_11 -> V_28 , V_8 ) ;
F_10 ( V_14 , L_5 , V_9 ,
V_19 , V_18 ) ;
return 0 ;
V_27:
F_16 ( V_11 -> V_13 ) ;
V_26:
F_17 ( V_21 , V_11 ) ;
return - V_24 ;
}
static int F_18 ( struct V_7 * V_8 ,
const char * V_9 )
{
struct V_10 * V_11 ;
F_10 ( V_14 , L_6 , V_9 ) ;
if ( F_8 ( V_8 , V_9 , & V_11 ) == 0 ) {
F_19 ( & V_11 -> V_28 ) ;
F_16 ( V_11 -> V_13 ) ;
F_16 ( V_11 -> V_16 ) ;
F_17 ( V_21 , V_11 ) ;
return 0 ;
}
return - V_17 ;
}
static int F_20 ( struct V_7 * V_8 ,
char * V_29 ,
int V_30 )
{
struct V_10 * V_11 , * V_31 ;
int V_32 = 0 ;
F_21 (xattr, tmp, cache, xe_list) {
F_10 ( V_14 , L_7 ,
V_29 , V_32 , V_11 -> V_13 ) ;
if ( V_29 ) {
V_30 -= V_11 -> V_25 ;
if ( V_30 < 0 )
break;
memcpy ( & V_29 [ V_32 ] ,
V_11 -> V_13 , V_11 -> V_25 ) ;
}
V_32 += V_11 -> V_25 ;
}
if ( V_30 < 0 )
return - V_33 ;
return V_32 ;
}
static int F_22 ( struct V_2 * V_3 )
{
return ! ! ( V_3 -> V_5 & V_6 ) ;
}
static int F_23 ( struct V_2 * V_3 )
{
if ( ! F_22 ( V_3 ) )
return 0 ;
while ( F_18 ( & V_3 -> V_4 , NULL ) == 0 )
;
V_3 -> V_5 &= ~ V_6 ;
return 0 ;
}
int F_24 ( struct V_34 * V_34 )
{
struct V_2 * V_3 = F_25 ( V_34 ) ;
int V_35 ;
F_26 ( & V_3 -> V_36 ) ;
V_35 = F_23 ( V_3 ) ;
F_27 ( & V_3 -> V_36 ) ;
return V_35 ;
}
static int F_28 ( struct V_34 * V_34 ,
struct V_37 * V_38 ,
struct V_39 * * V_40 )
{
T_1 V_41 ;
struct V_42 V_43 = { 0 } ;
struct V_44 * V_45 ;
struct V_2 * V_3 = F_25 ( V_34 ) ;
struct V_46 V_47 = { . V_48 = V_49 ,
. V_50 = F_29 ( V_38 ) ,
. V_51 = V_52 ,
. V_53 = V_54 } ;
struct V_55 * V_56 = F_30 ( V_34 ) ;
struct V_57 * exp = V_56 -> V_58 ;
int V_35 ;
F_31 ( & V_3 -> V_59 ) ;
if ( F_22 ( V_3 ) ) {
V_41 = F_32 ( V_34 , V_60 , & V_43 , 0 ,
V_61 ) ;
if ( V_41 != 0 ) {
V_38 -> V_62 . V_63 . V_64 = V_43 . V_65 ;
V_38 -> V_62 . V_63 . V_66 = V_41 ;
goto V_67;
}
}
V_45 = F_33 ( NULL , V_34 , NULL , NULL , 0 , 0 ,
V_68 , NULL ) ;
if ( F_34 ( V_45 ) ) {
F_35 ( & V_3 -> V_59 ) ;
return F_36 ( V_45 ) ;
}
V_45 -> V_69 = V_70 | V_71 ;
V_35 = F_37 ( exp , & V_47 , V_38 , V_45 , & V_43 , NULL , 0 , NULL , 0 ) ;
F_38 ( V_45 ) ;
if ( V_35 < 0 ) {
F_10 ( V_14 ,
L_8 V_72 L_9 ,
V_35 , F_39 ( F_40 ( V_34 ) ) ) ;
F_35 ( & V_3 -> V_59 ) ;
return V_35 ;
}
* V_40 = (struct V_39 * ) V_38 -> V_62 . V_63 . V_73 ;
V_67:
F_26 ( & V_3 -> V_36 ) ;
F_35 ( & V_3 -> V_59 ) ;
return 0 ;
}
static int F_41 ( struct V_34 * V_34 , struct V_37 * V_38 )
{
struct V_55 * V_56 = F_30 ( V_34 ) ;
struct V_39 * V_40 = NULL ;
const char * V_74 , * V_75 , * V_76 , * V_77 ;
struct V_2 * V_3 = F_25 ( V_34 ) ;
struct V_78 * V_79 ;
T_2 * V_80 ;
int V_35 , V_81 ;
V_35 = F_28 ( V_34 , V_38 , & V_40 ) ;
if ( V_35 )
goto V_82;
if ( F_22 ( V_3 ) ) {
F_42 ( V_56 , V_83 , 1 ) ;
V_35 = 0 ;
goto V_84;
}
if ( F_43 ( V_40 == NULL ) ) {
F_10 ( V_14 , L_10 ) ;
V_35 = - V_85 ;
goto V_84;
}
if ( V_38 -> V_62 . V_63 . V_86 < 0 ) {
F_10 ( V_14 , L_11 V_72 L_9 ,
V_38 -> V_62 . V_63 . V_86 , F_39 ( F_40 ( V_34 ) ) ) ;
V_35 = V_38 -> V_62 . V_63 . V_86 ;
if ( V_35 == - V_33 )
V_35 = - V_87 ;
goto V_88;
}
V_79 = F_44 ( & V_40 -> V_89 , & V_90 ) ;
if ( V_79 == NULL ) {
F_45 ( L_12 ) ;
V_35 = - V_20 ;
goto V_88;
}
V_74 = F_46 ( & V_40 -> V_89 , & V_91 ,
V_79 -> V_92 ) ;
V_75 = F_46 ( & V_40 -> V_89 , & V_93 ,
V_79 -> V_94 ) ;
V_80 = F_46 ( & V_40 -> V_89 , & V_95 ,
V_79 -> V_96 * sizeof( T_2 ) ) ;
if ( V_74 == NULL || V_75 == NULL || V_80 == NULL ) {
F_45 ( L_13 ) ;
V_35 = - V_20 ;
goto V_88;
}
V_76 = V_74 + V_79 -> V_92 ;
V_77 = V_75 + V_79 -> V_94 ;
F_10 ( V_14 , L_14 , V_74 , V_76 ) ;
F_5 ( V_3 ) ;
for ( V_81 = 0 ; V_81 < V_79 -> V_96 ; V_81 ++ ) {
F_10 ( V_14 , L_15 , V_74 , * V_80 , V_75 ) ;
if ( memchr ( V_74 , 0 , V_76 - V_74 ) == NULL ) {
F_45 ( L_16 ) ;
V_35 = - V_20 ;
} else if ( V_75 + * V_80 > V_77 ) {
F_45 ( L_17 ) ;
V_35 = - V_20 ;
} else if ( F_47 ( V_97 ) ) {
V_35 = - V_24 ;
} else if ( ! strcmp ( V_74 , V_98 ) ) {
F_10 ( V_14 , L_18 ,
V_98 ) ;
V_35 = 0 ;
} else {
V_35 = F_11 ( & V_3 -> V_4 , V_74 , V_75 ,
* V_80 ) ;
}
if ( V_35 < 0 ) {
F_23 ( V_3 ) ;
goto V_88;
}
V_74 += strlen ( V_74 ) + 1 ;
V_75 += * V_80 ;
V_80 ++ ;
}
if ( V_74 != V_76 || V_75 != V_77 )
F_45 ( L_19 ) ;
F_48 ( V_56 -> V_58 , V_34 , V_38 , NULL ) ;
goto V_84;
V_84:
F_49 ( V_38 ) ;
if ( V_35 != 0 )
F_27 ( & V_3 -> V_36 ) ;
V_82:
F_50 ( V_40 ) ;
return V_35 ;
V_88:
F_27 ( & V_3 -> V_36 ) ;
F_51 ( (struct V_42 * )
& V_38 -> V_62 . V_63 . V_64 ,
V_38 -> V_62 . V_63 . V_66 ) ;
goto V_82;
}
int F_52 ( struct V_34 * V_34 ,
const char * V_99 ,
char * V_100 ,
T_3 V_101 ,
T_4 V_102 )
{
struct V_37 V_38 = { . V_103 = V_104 } ;
struct V_2 * V_3 = F_25 ( V_34 ) ;
int V_35 = 0 ;
F_6 ( ! ! ( V_102 & V_70 ) ^ ! ! ( V_102 & V_71 ) ) ;
F_53 ( & V_3 -> V_36 ) ;
if ( ! F_22 ( V_3 ) ) {
F_54 ( & V_3 -> V_36 ) ;
V_35 = F_41 ( V_34 , & V_38 ) ;
if ( V_35 )
return V_35 ;
F_55 ( & V_3 -> V_36 ) ;
} else {
F_42 ( F_30 ( V_34 ) , V_83 , 1 ) ;
}
if ( V_102 & V_70 ) {
struct V_10 * V_11 ;
V_35 = F_8 ( & V_3 -> V_4 , V_99 , & V_11 ) ;
if ( V_35 == 0 ) {
V_35 = V_11 -> V_15 ;
if ( V_101 != 0 ) {
if ( V_101 >= V_11 -> V_15 )
memcpy ( V_100 , V_11 -> V_16 ,
V_11 -> V_15 ) ;
else
V_35 = - V_33 ;
}
}
} else if ( V_102 & V_71 ) {
V_35 = F_20 ( & V_3 -> V_4 ,
V_101 ? V_100 : NULL , V_101 ) ;
}
goto V_67;
V_67:
F_54 ( & V_3 -> V_36 ) ;
return V_35 ;
}
