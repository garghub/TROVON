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
F_12 ( V_11 , V_21 , V_22 ) ;
if ( V_11 == NULL ) {
F_10 ( V_14 , L_3 ) ;
return - V_23 ;
}
V_11 -> V_24 = strlen ( V_9 ) + 1 ;
F_13 ( V_11 -> V_13 , V_11 -> V_24 ) ;
if ( ! V_11 -> V_13 ) {
F_10 ( V_14 , L_4 ,
V_11 -> V_24 ) ;
goto V_25;
}
F_13 ( V_11 -> V_16 , V_19 ) ;
if ( ! V_11 -> V_16 ) {
F_10 ( V_14 , L_5 ,
V_19 ) ;
goto V_26;
}
memcpy ( V_11 -> V_13 , V_9 , V_11 -> V_24 ) ;
memcpy ( V_11 -> V_16 , V_18 , V_19 ) ;
V_11 -> V_15 = V_19 ;
F_14 ( & V_11 -> V_27 , V_8 ) ;
F_10 ( V_14 , L_6 , V_9 ,
V_19 , V_18 ) ;
return 0 ;
V_26:
F_15 ( V_11 -> V_13 , V_11 -> V_24 ) ;
V_25:
F_16 ( V_11 , V_21 ) ;
return - V_23 ;
}
static int F_17 ( struct V_7 * V_8 ,
const char * V_9 )
{
struct V_10 * V_11 ;
F_10 ( V_14 , L_7 , V_9 ) ;
if ( F_8 ( V_8 , V_9 , & V_11 ) == 0 ) {
F_18 ( & V_11 -> V_27 ) ;
F_15 ( V_11 -> V_13 , V_11 -> V_24 ) ;
F_15 ( V_11 -> V_16 , V_11 -> V_15 ) ;
F_16 ( V_11 , V_21 ) ;
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
F_10 ( V_14 , L_8 ,
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
V_40 = F_31 ( V_33 , V_59 , & V_42 , 0 , V_60 ) ;
if ( V_40 != 0 ) {
V_37 -> V_61 . V_62 . V_63 = V_42 . V_64 ;
V_37 -> V_61 . V_62 . V_65 = V_40 ;
goto V_66;
}
V_44 = F_32 ( NULL , V_33 , NULL , NULL , 0 , 0 ,
V_67 , NULL ) ;
if ( F_33 ( V_44 ) ) {
F_34 ( & V_3 -> V_58 ) ;
return F_35 ( V_44 ) ;
}
V_44 -> V_68 = V_69 | V_70 ;
V_34 = F_36 ( exp , & V_46 , V_37 , V_44 , & V_42 , NULL , 0 , NULL , 0 ) ;
F_37 ( V_44 ) ;
if ( V_34 < 0 ) {
F_10 ( V_14 ,
L_9 V_71 L_10 ,
V_34 , F_38 ( F_39 ( V_33 ) ) ) ;
F_34 ( & V_3 -> V_58 ) ;
return V_34 ;
}
* V_39 = (struct V_38 * ) V_37 -> V_61 . V_62 . V_72 ;
V_66:
F_25 ( & V_3 -> V_35 ) ;
F_34 ( & V_3 -> V_58 ) ;
return 0 ;
}
static int F_40 ( struct V_33 * V_33 , struct V_36 * V_37 )
{
struct V_54 * V_55 = F_29 ( V_33 ) ;
struct V_38 * V_39 = NULL ;
const char * V_73 , * V_74 , * V_75 , * V_76 ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
struct V_77 * V_78 ;
T_2 * V_79 ;
int V_34 = 0 , V_80 ;
V_34 = F_27 ( V_33 , V_37 , & V_39 ) ;
if ( V_34 )
GOTO ( V_81 , V_34 ) ;
if ( F_21 ( V_3 ) ) {
F_41 ( V_55 , V_82 , 1 ) ;
GOTO ( V_83 , V_34 = 0 ) ;
}
if ( F_42 ( V_39 == NULL ) ) {
F_10 ( V_14 , L_11 ) ;
GOTO ( V_83 , V_34 = - V_84 ) ;
}
if ( V_37 -> V_61 . V_62 . V_85 < 0 ) {
F_10 ( V_14 , L_12 V_71 L_10 ,
V_37 -> V_61 . V_62 . V_85 , F_38 ( F_39 ( V_33 ) ) ) ;
V_34 = V_37 -> V_61 . V_62 . V_85 ;
if ( V_34 == - V_32 )
V_34 = - V_86 ;
GOTO ( V_87 , V_34 ) ;
}
V_78 = F_43 ( & V_39 -> V_88 , & V_89 ) ;
if ( V_78 == NULL ) {
F_44 ( L_13 ) ;
GOTO ( V_87 , V_34 = - V_20 ) ;
}
V_73 = F_45 ( & V_39 -> V_88 , & V_90 ,
V_78 -> V_91 ) ;
V_74 = F_45 ( & V_39 -> V_88 , & V_92 ,
V_78 -> V_93 ) ;
V_79 = F_45 ( & V_39 -> V_88 , & V_94 ,
V_78 -> V_95 * sizeof( T_2 ) ) ;
if ( V_73 == NULL || V_74 == NULL || V_79 == NULL ) {
F_44 ( L_14 ) ;
GOTO ( V_87 , V_34 = - V_20 ) ;
}
V_75 = V_73 + V_78 -> V_91 ;
V_76 = V_74 + V_78 -> V_93 ;
F_10 ( V_14 , L_15 , V_73 , V_75 ) ;
F_5 ( V_3 ) ;
for ( V_80 = 0 ; V_80 < V_78 -> V_95 ; V_80 ++ ) {
F_10 ( V_14 , L_16 , V_73 , * V_79 , V_74 ) ;
if ( memchr ( V_73 , 0 , V_75 - V_73 ) == NULL ) {
F_44 ( L_17 ) ;
V_34 = - V_20 ;
} else if ( V_74 + * V_79 > V_76 ) {
F_44 ( L_18 ) ;
V_34 = - V_20 ;
} else if ( F_46 ( V_96 ) ) {
V_34 = - V_23 ;
} else if ( ! strcmp ( V_73 , V_97 ) ) {
F_10 ( V_14 , L_19 ,
V_97 ) ;
V_34 = 0 ;
} else {
V_34 = F_11 ( & V_3 -> V_4 , V_73 , V_74 ,
* V_79 ) ;
}
if ( V_34 < 0 ) {
F_22 ( V_3 ) ;
GOTO ( V_87 , V_34 ) ;
}
V_73 += strlen ( V_73 ) + 1 ;
V_74 += * V_79 ;
V_79 ++ ;
}
if ( V_73 != V_75 || V_74 != V_76 )
F_44 ( L_20 ) ;
F_47 ( V_55 -> V_57 , V_33 , V_37 , NULL ) ;
GOTO ( V_83 , V_34 ) ;
V_83:
F_48 ( V_37 ) ;
if ( V_34 != 0 )
F_26 ( & V_3 -> V_35 ) ;
V_81:
F_49 ( V_39 ) ;
return V_34 ;
V_87:
F_26 ( & V_3 -> V_35 ) ;
F_50 ( (struct V_41 * )
& V_37 -> V_61 . V_62 . V_63 ,
V_37 -> V_61 . V_62 . V_65 ) ;
goto V_81;
}
int F_51 ( struct V_33 * V_33 ,
const char * V_98 ,
char * V_99 ,
T_3 V_100 ,
T_4 V_101 )
{
struct V_36 V_37 = { . V_102 = V_103 } ;
struct V_2 * V_3 = F_24 ( V_33 ) ;
int V_34 = 0 ;
F_6 ( ! ! ( V_101 & V_69 ) ^ ! ! ( V_101 & V_70 ) ) ;
F_52 ( & V_3 -> V_35 ) ;
if ( ! F_21 ( V_3 ) ) {
F_53 ( & V_3 -> V_35 ) ;
V_34 = F_40 ( V_33 , & V_37 ) ;
if ( V_34 )
return V_34 ;
F_54 ( & V_3 -> V_35 ) ;
} else {
F_41 ( F_29 ( V_33 ) , V_82 , 1 ) ;
}
if ( V_101 & V_69 ) {
struct V_10 * V_11 ;
V_34 = F_8 ( & V_3 -> V_4 , V_98 , & V_11 ) ;
if ( V_34 == 0 ) {
V_34 = V_11 -> V_15 ;
if ( V_100 != 0 ) {
if ( V_100 >= V_11 -> V_15 )
memcpy ( V_99 , V_11 -> V_16 ,
V_11 -> V_15 ) ;
else
V_34 = - V_32 ;
}
}
} else if ( V_101 & V_70 ) {
V_34 = F_19 ( & V_3 -> V_4 ,
V_100 ? V_99 : NULL , V_100 ) ;
}
GOTO ( V_66 , V_34 ) ;
V_66:
F_53 ( & V_3 -> V_35 ) ;
return V_34 ;
}
