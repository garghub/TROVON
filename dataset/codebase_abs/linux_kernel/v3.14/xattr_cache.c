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
if ( V_19 != V_11 -> V_15 ) {
char * V_20 ;
F_12 ( V_20 , V_19 ) ;
if ( V_20 == NULL ) {
F_10 ( V_14 ,
L_2 ,
V_19 , V_9 ) ;
return - V_21 ;
}
F_13 ( V_11 -> V_16 , V_11 -> V_15 ) ;
V_11 -> V_16 = V_20 ;
V_11 -> V_15 = V_19 ;
}
memcpy ( V_11 -> V_16 , V_18 , V_19 ) ;
F_10 ( V_14 , L_3 , V_9 ,
V_19 , V_18 ) ;
return 0 ;
}
F_14 ( V_11 , V_22 , V_23 ) ;
if ( V_11 == NULL ) {
F_10 ( V_14 , L_4 ) ;
return - V_21 ;
}
V_11 -> V_24 = strlen ( V_9 ) + 1 ;
F_12 ( V_11 -> V_13 , V_11 -> V_24 ) ;
if ( ! V_11 -> V_13 ) {
F_10 ( V_14 , L_5 ,
V_11 -> V_24 ) ;
goto V_25;
}
F_12 ( V_11 -> V_16 , V_19 ) ;
if ( ! V_11 -> V_16 ) {
F_10 ( V_14 , L_6 ,
V_19 ) ;
goto V_26;
}
memcpy ( V_11 -> V_13 , V_9 , V_11 -> V_24 ) ;
memcpy ( V_11 -> V_16 , V_18 , V_19 ) ;
V_11 -> V_15 = V_19 ;
F_15 ( & V_11 -> V_27 , V_8 ) ;
F_10 ( V_14 , L_7 , V_9 ,
V_19 , V_18 ) ;
return 0 ;
V_26:
F_13 ( V_11 -> V_13 , V_11 -> V_24 ) ;
V_25:
F_16 ( V_11 , V_22 ) ;
return - V_21 ;
}
static int F_17 ( struct V_7 * V_8 ,
const char * V_9 )
{
struct V_10 * V_11 ;
F_10 ( V_14 , L_8 , V_9 ) ;
if ( F_8 ( V_8 , V_9 , & V_11 ) == 0 ) {
F_18 ( & V_11 -> V_27 ) ;
F_13 ( V_11 -> V_13 , V_11 -> V_24 ) ;
F_13 ( V_11 -> V_16 , V_11 -> V_15 ) ;
F_16 ( V_11 , V_22 ) ;
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
F_10 ( V_14 , L_9 ,
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
int F_21 ( struct V_2 * V_3 )
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
T_1 V_40 ;
struct V_41 V_42 = { 0 } ;
struct V_43 * V_44 ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
struct V_45 V_46 = { . V_47 = V_48 ,
. V_49 = F_28 ( V_37 ) ,
. V_50 = V_51 ,
. V_52 = V_53 } ;
struct V_54 * V_55 = F_29 ( V_33 ) ;
struct V_56 * exp = V_55 -> V_57 ;
int V_34 ;
F_30 ( & V_3 -> V_58 ) ;
V_40 = F_31 ( V_33 , V_59 , & V_42 , 0 ,
V_37 -> V_60 == V_61 ? V_62 :
( V_63 | V_62 ) ) ;
if ( V_40 != 0 ) {
V_37 -> V_64 . V_65 . V_66 = V_42 . V_67 ;
V_37 -> V_64 . V_65 . V_68 = V_40 ;
goto V_69;
}
V_44 = F_32 ( NULL , V_33 , NULL , NULL , 0 , 0 ,
V_70 , NULL ) ;
if ( F_33 ( V_44 ) ) {
F_34 ( & V_3 -> V_58 ) ;
return F_35 ( V_44 ) ;
}
V_44 -> V_71 = V_72 | V_73 |
V_74 ;
#ifdef F_36
if ( V_55 -> V_75 & V_76 )
V_44 -> V_71 |= V_77 ;
#endif
V_34 = F_37 ( exp , & V_46 , V_37 , V_44 , & V_42 , NULL , 0 , NULL , 0 ) ;
F_38 ( V_44 ) ;
if ( V_34 < 0 ) {
F_10 ( V_14 ,
L_10 V_78 L_11 ,
V_34 , F_39 ( F_40 ( V_33 ) ) ) ;
F_34 ( & V_3 -> V_58 ) ;
return V_34 ;
}
* V_39 = (struct V_38 * ) V_37 -> V_64 . V_65 . V_79 ;
V_69:
F_25 ( & V_3 -> V_35 ) ;
F_34 ( & V_3 -> V_58 ) ;
return 0 ;
}
static int F_41 ( struct V_33 * V_33 , struct V_36 * V_37 )
{
struct V_54 * V_55 = F_29 ( V_33 ) ;
struct V_38 * V_39 = NULL ;
const char * V_80 , * V_81 , * V_82 , * V_83 ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
struct V_84 * V_85 ;
T_2 * V_86 ;
int V_34 = 0 , V_87 ;
V_34 = F_27 ( V_33 , V_37 , & V_39 ) ;
if ( V_34 )
GOTO ( V_88 , V_34 ) ;
if ( F_21 ( V_3 ) ) {
F_42 ( V_55 , V_89 , 1 ) ;
GOTO ( V_90 , V_34 = 0 ) ;
}
if ( F_43 ( V_39 == NULL ) ) {
F_10 ( V_14 , L_12 ) ;
GOTO ( V_90 , V_34 = - V_91 ) ;
}
if ( V_37 -> V_64 . V_65 . V_92 < 0 ) {
F_10 ( V_14 , L_13 V_78 L_11 ,
V_37 -> V_64 . V_65 . V_92 , F_39 ( F_40 ( V_33 ) ) ) ;
GOTO ( V_93 , V_34 = V_37 -> V_64 . V_65 . V_92 ) ;
}
V_85 = F_44 ( & V_39 -> V_94 , & V_95 ) ;
if ( V_85 == NULL ) {
F_45 ( L_14 ) ;
GOTO ( V_93 , V_34 = - V_96 ) ;
}
V_80 = F_46 ( & V_39 -> V_94 , & V_97 ,
V_85 -> V_98 ) ;
V_81 = F_46 ( & V_39 -> V_94 , & V_99 ,
V_85 -> V_100 ) ;
V_86 = F_46 ( & V_39 -> V_94 , & V_101 ,
V_85 -> V_102 * sizeof( T_2 ) ) ;
if ( V_80 == NULL || V_81 == NULL || V_86 == NULL ) {
F_45 ( L_15 ) ;
GOTO ( V_93 , V_34 = - V_96 ) ;
}
V_82 = V_80 + V_85 -> V_98 ;
V_83 = V_81 + V_85 -> V_100 ;
F_10 ( V_14 , L_16 , V_80 , V_82 ) ;
F_5 ( V_3 ) ;
for ( V_87 = 0 ; V_87 < V_85 -> V_102 ; V_87 ++ ) {
F_10 ( V_14 , L_17 , V_80 , * V_86 , V_81 ) ;
if ( memchr ( V_80 , 0 , V_82 - V_80 ) == NULL ) {
F_45 ( L_18 ) ;
V_34 = - V_96 ;
} else if ( V_81 + * V_86 > V_83 ) {
F_45 ( L_19 ) ;
V_34 = - V_96 ;
} else if ( F_47 ( V_103 ) ) {
V_34 = - V_21 ;
} else {
V_34 = F_11 ( & V_3 -> V_4 , V_80 , V_81 ,
* V_86 ) ;
}
if ( V_34 < 0 ) {
F_22 ( V_3 ) ;
GOTO ( V_93 , V_34 ) ;
}
V_80 += strlen ( V_80 ) + 1 ;
V_81 += * V_86 ;
V_86 ++ ;
}
if ( V_80 != V_82 || V_81 != V_83 )
F_45 ( L_20 ) ;
F_48 ( V_55 -> V_57 , V_33 , V_37 , NULL ) ;
GOTO ( V_90 , V_34 ) ;
V_90:
if ( V_34 != 0 || V_37 -> V_60 != V_61 )
F_49 ( V_37 ) ;
if ( V_34 != 0 )
F_26 ( & V_3 -> V_35 ) ;
V_88:
F_50 ( V_39 ) ;
return V_34 ;
V_93:
F_26 ( & V_3 -> V_35 ) ;
F_51 ( (struct V_41 * )
& V_37 -> V_64 . V_65 . V_66 ,
V_37 -> V_64 . V_65 . V_68 ) ;
goto V_88;
}
int F_52 ( struct V_33 * V_33 ,
const char * V_104 ,
char * V_105 ,
T_3 V_106 ,
T_4 V_107 )
{
struct V_36 V_37 = { . V_60 = V_108 } ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
int V_34 = 0 ;
F_6 ( ! ! ( V_107 & V_72 ) ^ ! ! ( V_107 & V_73 ) ) ;
F_53 ( & V_3 -> V_35 ) ;
if ( ! F_21 ( V_3 ) ) {
F_54 ( & V_3 -> V_35 ) ;
V_34 = F_41 ( V_33 , & V_37 ) ;
if ( V_34 )
return V_34 ;
F_55 ( & V_3 -> V_35 ) ;
} else {
F_42 ( F_29 ( V_33 ) , V_89 , 1 ) ;
}
if ( V_107 & V_72 ) {
struct V_10 * V_11 ;
V_34 = F_8 ( & V_3 -> V_4 , V_104 , & V_11 ) ;
if ( V_34 == 0 ) {
V_34 = V_11 -> V_15 ;
if ( V_106 != 0 ) {
if ( V_106 >= V_11 -> V_15 )
memcpy ( V_105 , V_11 -> V_16 ,
V_11 -> V_15 ) ;
else
V_34 = - V_32 ;
}
}
} else if ( V_107 & V_73 ) {
V_34 = F_19 ( & V_3 -> V_4 ,
V_106 ? V_105 : NULL , V_106 ) ;
}
GOTO ( V_69 , V_34 ) ;
V_69:
F_54 ( & V_3 -> V_35 ) ;
return V_34 ;
}
int F_56 ( struct V_33 * V_33 ,
const char * V_104 ,
const char * V_109 ,
T_3 V_106 ,
T_4 V_107 ,
int V_110 )
{
struct V_36 V_37 = { . V_60 = V_61 } ;
struct V_54 * V_55 = F_29 ( V_33 ) ;
struct V_38 * V_39 = NULL ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
struct V_111 * V_112 ;
int V_34 ;
F_6 ( ! ! ( V_107 & V_72 ) ^ ! ! ( V_107 & V_113 ) ) ;
V_34 = F_41 ( V_33 , & V_37 ) ;
if ( V_34 )
return V_34 ;
V_112 = F_57 ( V_33 ) ;
V_34 = F_58 ( V_55 -> V_57 , F_40 ( V_33 ) , V_112 ,
V_107 | V_74 , V_104 , V_109 ,
V_106 , 0 , V_110 , F_59 ( V_33 ) , & V_39 ) ;
F_60 ( V_112 ) ;
if ( V_34 ) {
F_49 ( & V_37 ) ;
GOTO ( V_69 , V_34 ) ;
}
if ( V_107 & V_72 )
V_34 = F_11 ( & V_3 -> V_4 , V_104 , V_109 , V_106 ) ;
else if ( V_107 & V_113 )
V_34 = F_17 ( & V_3 -> V_4 , V_104 ) ;
F_49 ( & V_37 ) ;
GOTO ( V_69 , V_34 ) ;
V_69:
F_26 ( & V_3 -> V_35 ) ;
F_50 ( V_39 ) ;
return V_34 ;
}
