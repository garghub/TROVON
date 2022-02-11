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
F_6 ( & V_3 -> V_4 ) ;
V_3 -> V_5 |= V_6 ;
}
static int F_7 ( struct V_7 * V_8 ,
const char * V_9 ,
struct V_10 * * V_11 )
{
struct V_10 * V_12 ;
F_8 (entry, cache, xe_list) {
if ( ! V_9 || strcmp ( V_9 , V_12 -> V_13 ) == 0 ) {
* V_11 = V_12 ;
F_9 ( V_14 , L_1 ,
V_12 -> V_13 , V_12 -> V_15 ,
V_12 -> V_16 ) ;
return 0 ;
}
}
return - V_17 ;
}
static int F_10 ( struct V_7 * V_8 ,
const char * V_9 ,
const char * V_18 ,
unsigned V_19 )
{
struct V_10 * V_11 ;
if ( F_7 ( V_8 , V_9 , & V_11 ) == 0 ) {
F_9 ( V_14 , L_2 , V_9 ) ;
return - V_20 ;
}
V_11 = F_11 ( V_21 , V_22 ) ;
if ( ! V_11 ) {
F_9 ( V_14 , L_3 ) ;
return - V_23 ;
}
V_11 -> V_13 = F_12 ( V_9 , V_22 ) ;
if ( ! V_11 -> V_13 ) {
F_9 ( V_14 , L_4 ,
V_11 -> V_24 ) ;
goto V_25;
}
V_11 -> V_16 = F_13 ( V_18 , V_19 , V_22 ) ;
if ( ! V_11 -> V_16 )
goto V_26;
V_11 -> V_15 = V_19 ;
F_14 ( & V_11 -> V_27 , V_8 ) ;
F_9 ( V_14 , L_5 , V_9 , V_19 ,
V_18 ) ;
return 0 ;
V_26:
F_15 ( V_11 -> V_13 ) ;
V_25:
F_16 ( V_21 , V_11 ) ;
return - V_23 ;
}
static int F_17 ( struct V_7 * V_8 ,
const char * V_9 )
{
struct V_10 * V_11 ;
F_9 ( V_14 , L_6 , V_9 ) ;
if ( F_7 ( V_8 , V_9 , & V_11 ) == 0 ) {
F_18 ( & V_11 -> V_27 ) ;
F_15 ( V_11 -> V_13 ) ;
F_15 ( V_11 -> V_16 ) ;
F_16 ( V_21 , V_11 ) ;
return 0 ;
}
return - V_17 ;
}
static int F_19 ( struct V_7 * V_8 ,
char * V_28 ,
int V_29 )
{
struct V_10 * V_11 , * V_30 ;
int V_31 = 0 ;
F_20 (xattr, tmp, cache, xe_list) {
F_9 ( V_14 , L_7 ,
V_28 , V_31 , V_11 -> V_13 ) ;
if ( V_28 ) {
V_29 -= V_11 -> V_24 ;
if ( V_29 < 0 )
break;
memcpy ( & V_28 [ V_31 ] ,
V_11 -> V_13 , V_11 -> V_24 ) ;
}
V_31 += V_11 -> V_24 ;
}
if ( V_29 < 0 )
return - V_32 ;
return V_31 ;
}
static int F_21 ( struct V_2 * V_3 )
{
return ! ! ( V_3 -> V_5 & V_6 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
if ( ! F_21 ( V_3 ) )
return 0 ;
while ( F_17 ( & V_3 -> V_4 , NULL ) == 0 )
;
V_3 -> V_5 &= ~ V_6 ;
return 0 ;
}
int F_23 ( struct V_33 * V_33 )
{
struct V_2 * V_3 = F_24 ( V_33 ) ;
int V_34 ;
F_25 ( & V_3 -> V_35 ) ;
V_34 = F_22 ( V_3 ) ;
F_26 ( & V_3 -> V_35 ) ;
return V_34 ;
}
static int F_27 ( struct V_33 * V_33 ,
struct V_36 * V_37 ,
struct V_38 * * V_39 )
{
enum V_40 V_41 ;
struct V_42 V_43 = { 0 } ;
struct V_44 * V_45 ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
struct V_46 V_47 = { . V_48 = V_49 ,
. V_50 = F_28 ( V_37 ) ,
. V_51 = V_52 ,
. V_53 = V_54 } ;
struct V_55 * V_56 = F_29 ( V_33 ) ;
struct V_57 * exp = V_56 -> V_58 ;
int V_34 ;
F_30 ( & V_3 -> V_59 ) ;
if ( F_21 ( V_3 ) ) {
V_41 = F_31 ( V_33 , V_60 , & V_43 , 0 ,
V_61 ) ;
if ( V_41 != 0 ) {
V_37 -> V_62 = V_43 . V_63 ;
V_37 -> V_64 = V_41 ;
goto V_65;
}
}
V_45 = F_32 ( NULL , V_33 , NULL , NULL , 0 , 0 ,
V_66 , NULL ) ;
if ( F_33 ( V_45 ) ) {
F_34 ( & V_3 -> V_59 ) ;
return F_35 ( V_45 ) ;
}
V_45 -> V_67 = V_68 | V_69 ;
V_34 = F_36 ( exp , & V_47 , V_37 , V_45 , & V_43 , NULL , 0 , NULL , 0 ) ;
F_37 ( V_45 ) ;
if ( V_34 < 0 ) {
F_9 ( V_14 ,
L_8 V_70 L_9 ,
V_34 , F_38 ( F_39 ( V_33 ) ) ) ;
F_34 ( & V_3 -> V_59 ) ;
return V_34 ;
}
* V_39 = V_37 -> V_71 ;
V_65:
F_25 ( & V_3 -> V_35 ) ;
F_34 ( & V_3 -> V_59 ) ;
return 0 ;
}
static int F_40 ( struct V_33 * V_33 , struct V_36 * V_37 )
{
struct V_55 * V_56 = F_29 ( V_33 ) ;
struct V_38 * V_39 = NULL ;
const char * V_72 , * V_73 , * V_74 , * V_75 ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
struct V_76 * V_77 ;
T_1 * V_78 ;
int V_34 , V_79 ;
V_34 = F_27 ( V_33 , V_37 , & V_39 ) ;
if ( V_34 )
goto V_80;
if ( F_21 ( V_3 ) ) {
F_41 ( V_56 , V_81 , 1 ) ;
V_34 = 0 ;
goto V_82;
}
if ( F_42 ( ! V_39 ) ) {
F_9 ( V_14 , L_10 ) ;
V_34 = - V_83 ;
goto V_82;
}
if ( V_37 -> V_84 < 0 ) {
F_9 ( V_14 , L_11 V_70 L_9 ,
V_37 -> V_84 , F_38 ( F_39 ( V_33 ) ) ) ;
V_34 = V_37 -> V_84 ;
if ( V_34 == - V_32 )
V_34 = - V_85 ;
goto V_86;
}
V_77 = F_43 ( & V_39 -> V_87 , & V_88 ) ;
if ( ! V_77 ) {
F_44 ( L_12 ) ;
V_34 = - V_20 ;
goto V_86;
}
V_72 = F_45 ( & V_39 -> V_87 , & V_89 ,
V_77 -> V_90 ) ;
V_73 = F_45 ( & V_39 -> V_87 , & V_91 ,
V_77 -> V_92 ) ;
V_78 = F_45 ( & V_39 -> V_87 , & V_93 ,
V_77 -> V_94 * sizeof( T_1 ) ) ;
if ( ! V_72 || ! V_73 || ! V_78 ) {
F_44 ( L_13 ) ;
V_34 = - V_20 ;
goto V_86;
}
V_74 = V_72 + V_77 -> V_90 ;
V_75 = V_73 + V_77 -> V_92 ;
F_9 ( V_14 , L_14 , V_72 , V_74 ) ;
F_5 ( V_3 ) ;
for ( V_79 = 0 ; V_79 < V_77 -> V_94 ; V_79 ++ ) {
F_9 ( V_14 , L_15 , V_72 , * V_78 , V_73 ) ;
if ( ! memchr ( V_72 , 0 , V_74 - V_72 ) ) {
F_44 ( L_16 ) ;
V_34 = - V_20 ;
} else if ( V_73 + * V_78 > V_75 ) {
F_44 ( L_17 ) ;
V_34 = - V_20 ;
} else if ( F_46 ( V_95 ) ) {
V_34 = - V_23 ;
} else if ( ! strcmp ( V_72 , V_96 ) ) {
F_9 ( V_14 , L_18 ,
V_96 ) ;
V_34 = 0 ;
} else {
V_34 = F_10 ( & V_3 -> V_4 , V_72 , V_73 ,
* V_78 ) ;
}
if ( V_34 < 0 ) {
F_22 ( V_3 ) ;
goto V_86;
}
V_72 += strlen ( V_72 ) + 1 ;
V_73 += * V_78 ;
V_78 ++ ;
}
if ( V_72 != V_74 || V_73 != V_75 )
F_44 ( L_19 ) ;
F_47 ( V_56 -> V_58 , V_33 , V_37 , NULL ) ;
goto V_82;
V_82:
F_48 ( V_37 ) ;
if ( V_34 != 0 )
F_26 ( & V_3 -> V_35 ) ;
V_80:
F_49 ( V_39 ) ;
return V_34 ;
V_86:
F_26 ( & V_3 -> V_35 ) ;
F_50 ( (struct V_42 * )
& V_37 -> V_62 ,
V_37 -> V_64 ) ;
goto V_80;
}
int F_51 ( struct V_33 * V_33 , const char * V_97 , char * V_98 ,
T_2 V_99 , T_3 V_100 )
{
struct V_36 V_37 = { . V_101 = V_102 } ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
int V_34 = 0 ;
F_52 ( ! ! ( V_100 & V_68 ) ^ ! ! ( V_100 & V_69 ) ) ;
F_53 ( & V_3 -> V_35 ) ;
if ( ! F_21 ( V_3 ) ) {
F_54 ( & V_3 -> V_35 ) ;
V_34 = F_40 ( V_33 , & V_37 ) ;
if ( V_34 )
return V_34 ;
F_55 ( & V_3 -> V_35 ) ;
} else {
F_41 ( F_29 ( V_33 ) , V_81 , 1 ) ;
}
if ( V_100 & V_68 ) {
struct V_10 * V_11 ;
V_34 = F_7 ( & V_3 -> V_4 , V_97 , & V_11 ) ;
if ( V_34 == 0 ) {
V_34 = V_11 -> V_15 ;
if ( V_99 != 0 ) {
if ( V_99 >= V_11 -> V_15 )
memcpy ( V_98 , V_11 -> V_16 ,
V_11 -> V_15 ) ;
else
V_34 = - V_32 ;
}
}
} else if ( V_100 & V_69 ) {
V_34 = F_19 ( & V_3 -> V_4 ,
V_99 ? V_98 : NULL , V_99 ) ;
}
goto V_65;
V_65:
F_54 ( & V_3 -> V_35 ) ;
return V_34 ;
}
