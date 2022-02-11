static T_1 F_1 ( int V_1 , char * V_2 , T_1 V_3 )
{
return snprintf ( NULL , 0 , L_1 , V_1 ) ;
}
static T_2 F_2 ( struct V_4 * V_4 ,
char T_3 * V_5 , T_1 V_6 ,
T_4 * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
int V_11 ;
char * V_2 ;
V_2 = F_3 ( V_12 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_11 = snprintf ( V_2 , V_12 , L_2 , V_9 -> V_15 -> V_16 -> V_17 ) ;
if ( V_11 < 0 ) {
F_4 ( V_2 ) ;
return V_11 ;
}
V_11 = F_5 ( V_5 , V_6 , V_7 , V_2 , V_11 ) ;
F_4 ( V_2 ) ;
return V_11 ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_18 * V_19 ;
while ( ! F_7 ( & V_9 -> V_20 ) ) {
V_19 = F_8 ( & V_9 -> V_20 ,
struct V_18 ,
V_21 ) ;
F_9 ( & V_19 -> V_21 ) ;
F_4 ( V_19 ) ;
}
}
static unsigned int F_10 ( struct V_8 * V_9 ,
unsigned int V_22 ,
T_4 V_23 ,
T_4 * V_24 )
{
struct V_18 * V_19 = NULL ;
T_4 V_25 = 0 ;
unsigned int V_26 , V_11 ;
unsigned int V_27 ;
unsigned int V_28 ;
if ( V_22 )
return V_22 ;
F_11 ( & V_9 -> V_29 ) ;
V_26 = V_22 ;
if ( F_7 ( & V_9 -> V_20 ) ) {
for (; V_26 <= V_9 -> V_30 ; V_26 += V_9 -> V_31 ) {
if ( ! F_12 ( V_9 , V_26 ) ||
F_13 ( V_9 , V_26 ) ) {
if ( V_19 ) {
V_19 -> V_32 = V_25 - 1 ;
V_19 -> V_33 = V_26 - V_9 -> V_31 ;
F_14 ( & V_19 -> V_21 ,
& V_9 -> V_20 ) ;
V_19 = NULL ;
}
continue;
}
if ( ! V_19 ) {
V_19 = F_15 ( sizeof( * V_19 ) , V_13 ) ;
if ( ! V_19 ) {
F_6 ( V_9 ) ;
F_16 ( & V_9 -> V_29 ) ;
return V_22 ;
}
V_19 -> V_34 = V_25 ;
V_19 -> V_35 = V_26 ;
}
V_25 += V_9 -> V_36 ;
}
}
if ( V_19 ) {
V_19 -> V_32 = V_25 - 1 ;
V_19 -> V_33 = V_26 - V_9 -> V_31 ;
F_14 ( & V_19 -> V_21 ,
& V_9 -> V_20 ) ;
}
F_17 ( F_7 ( & V_9 -> V_20 ) ) ;
V_11 = V_22 ;
F_18 (c, &map->debugfs_off_cache, list) {
if ( V_23 >= V_19 -> V_34 && V_23 <= V_19 -> V_32 ) {
V_27 = V_23 - V_19 -> V_34 ;
V_28 = V_27 / V_9 -> V_36 ;
* V_24 = V_19 -> V_34 + ( V_28 * V_9 -> V_36 ) ;
F_16 ( & V_9 -> V_29 ) ;
return V_19 -> V_35 + ( V_28 * V_9 -> V_31 ) ;
}
* V_24 = V_19 -> V_32 ;
V_11 = V_19 -> V_33 ;
}
F_16 ( & V_9 -> V_29 ) ;
return V_11 ;
}
static inline void F_19 ( struct V_8 * V_9 ,
void * V_2 , T_1 V_6 )
{
if ( ! V_9 -> V_36 ) {
V_9 -> V_37 = F_1 ( V_9 -> V_30 ,
V_2 , V_6 ) ;
V_9 -> V_38 = 2 * V_9 -> V_39 . V_40 ;
V_9 -> V_36 = V_9 -> V_37 +
V_9 -> V_38 + 3 ;
}
}
static T_2 F_20 ( struct V_8 * V_9 , unsigned int V_23 ,
unsigned int V_41 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
T_1 V_42 = 0 ;
T_4 V_25 = * V_7 ;
T_2 V_11 ;
int V_26 ;
char * V_2 ;
unsigned int V_43 , V_44 ;
if ( * V_7 < 0 || ! V_6 )
return - V_45 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
F_19 ( V_9 , V_2 , V_6 ) ;
V_44 = F_10 ( V_9 , V_23 , * V_7 , & V_25 ) ;
for ( V_26 = V_44 ; V_26 <= V_41 ; V_26 += V_9 -> V_31 ) {
if ( ! F_12 ( V_9 , V_26 ) )
continue;
if ( F_13 ( V_9 , V_26 ) )
continue;
if ( V_25 >= * V_7 ) {
if ( V_42 + V_9 -> V_36 > V_6 )
break;
snprintf ( V_2 + V_42 , V_6 - V_42 , L_3 ,
V_9 -> V_37 , V_26 - V_23 ) ;
V_42 += V_9 -> V_37 + 2 ;
V_11 = F_21 ( V_9 , V_26 , & V_43 ) ;
if ( V_11 == 0 )
snprintf ( V_2 + V_42 , V_6 - V_42 ,
L_4 , V_9 -> V_38 , V_43 ) ;
else
memset ( V_2 + V_42 , 'X' ,
V_9 -> V_38 ) ;
V_42 += 2 * V_9 -> V_39 . V_40 ;
V_2 [ V_42 ++ ] = '\n' ;
}
V_25 += V_9 -> V_36 ;
}
V_11 = V_42 ;
if ( F_22 ( V_5 , V_2 , V_42 ) ) {
V_11 = - V_46 ;
goto V_47;
}
* V_7 += V_42 ;
V_47:
F_4 ( V_2 ) ;
return V_11 ;
}
static T_2 F_23 ( struct V_4 * V_4 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
return F_20 ( V_9 , 0 , V_9 -> V_30 , V_5 ,
V_6 , V_7 ) ;
}
static T_2 F_24 ( struct V_4 * V_4 ,
const char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
char V_2 [ 32 ] ;
T_1 V_3 ;
char * V_48 = V_2 ;
unsigned long V_49 , V_50 ;
struct V_8 * V_9 = V_4 -> V_10 ;
int V_11 ;
V_3 = V_34 ( V_6 , ( sizeof( V_2 ) - 1 ) ) ;
if ( F_25 ( V_2 , V_5 , V_3 ) )
return - V_46 ;
V_2 [ V_3 ] = 0 ;
while ( * V_48 == ' ' )
V_48 ++ ;
V_49 = F_26 ( V_48 , & V_48 , 16 ) ;
while ( * V_48 == ' ' )
V_48 ++ ;
if ( F_27 ( V_48 , 16 , & V_50 ) )
return - V_45 ;
F_28 ( V_51 , V_52 ) ;
V_11 = F_29 ( V_9 , V_49 , V_50 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_3 ;
}
static T_2 F_30 ( struct V_4 * V_4 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_53 * V_54 = V_4 -> V_10 ;
struct V_8 * V_9 = V_54 -> V_9 ;
return F_20 ( V_9 , V_54 -> V_55 , V_54 -> V_56 ,
V_5 , V_6 , V_7 ) ;
}
static T_2 F_31 ( struct V_4 * V_4 ,
char T_3 * V_5 , T_1 V_6 ,
T_4 * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_18 * V_19 ;
T_4 V_25 = 0 ;
T_1 V_42 = 0 ;
char * V_2 ;
char * V_57 ;
int V_11 ;
if ( * V_7 < 0 || ! V_6 )
return - V_45 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_57 = F_3 ( V_12 , V_13 ) ;
if ( ! V_57 ) {
F_4 ( V_2 ) ;
return - V_14 ;
}
F_19 ( V_9 , V_2 , V_6 ) ;
F_10 ( V_9 , 0 , * V_7 , & V_25 ) ;
V_25 = 0 ;
F_11 ( & V_9 -> V_29 ) ;
F_18 (c, &map->debugfs_off_cache, list) {
snprintf ( V_57 , V_12 , L_5 ,
V_19 -> V_35 , V_19 -> V_33 ) ;
if ( V_25 >= * V_7 ) {
if ( V_42 + 1 + strlen ( V_57 ) > V_6 )
break;
snprintf ( V_2 + V_42 , V_6 - V_42 ,
L_6 , V_57 ) ;
V_42 += strlen ( V_57 ) ;
V_2 [ V_42 ] = '\n' ;
V_42 ++ ;
}
V_25 += strlen ( V_57 ) + 1 ;
}
F_16 ( & V_9 -> V_29 ) ;
F_4 ( V_57 ) ;
V_11 = V_42 ;
if ( F_22 ( V_5 , V_2 , V_42 ) ) {
V_11 = - V_46 ;
goto V_58;
}
* V_7 += V_42 ;
V_58:
F_4 ( V_2 ) ;
return V_11 ;
}
static T_2 F_32 ( struct V_4 * V_4 ,
char T_3 * V_5 , T_1 V_6 ,
T_4 * V_7 )
{
int V_59 , V_60 ;
T_1 V_42 = 0 ;
T_4 V_25 = 0 ;
T_2 V_11 ;
int V_26 ;
struct V_8 * V_9 = V_4 -> V_10 ;
char * V_2 ;
if ( * V_7 < 0 || ! V_6 )
return - V_45 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_59 = F_1 ( V_9 -> V_30 , V_2 , V_6 ) ;
V_60 = V_59 + 10 ;
for ( V_26 = 0 ; V_26 <= V_9 -> V_30 ; V_26 += V_9 -> V_31 ) {
if ( ! F_12 ( V_9 , V_26 ) && ! F_33 ( V_9 , V_26 ) )
continue;
if ( V_25 >= * V_7 ) {
if ( V_42 + V_60 + 1 >= V_6 )
break;
snprintf ( V_2 + V_42 , V_6 - V_42 ,
L_7 ,
V_59 , V_26 ,
F_12 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_33 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_34 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_13 ( V_9 , V_26 ) ? 'y' : 'n' ) ;
V_42 += V_60 ;
}
V_25 += V_60 ;
}
V_11 = V_42 ;
if ( F_22 ( V_5 , V_2 , V_42 ) ) {
V_11 = - V_46 ;
goto V_47;
}
* V_7 += V_42 ;
V_47:
F_4 ( V_2 ) ;
return V_11 ;
}
static T_2 F_35 ( struct V_4 * V_4 ,
const char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_8 * V_9 = F_36 ( V_4 -> V_10 ,
struct V_8 , V_61 ) ;
T_2 V_62 ;
bool V_63 , V_64 = false ;
int V_65 ;
V_9 -> V_66 ( V_9 -> V_67 ) ;
V_63 = V_9 -> V_61 ;
V_62 = F_37 ( V_4 , V_5 , V_6 , V_7 ) ;
if ( V_62 < 0 ) {
V_9 -> V_68 ( V_9 -> V_67 ) ;
return V_62 ;
}
if ( V_9 -> V_61 && ! V_63 ) {
F_38 ( V_9 -> V_15 , L_8 ) ;
F_28 ( V_51 , V_52 ) ;
} else if ( ! V_9 -> V_61 && V_63 ) {
F_38 ( V_9 -> V_15 , L_9 ) ;
V_64 = true ;
}
V_9 -> V_68 ( V_9 -> V_67 ) ;
if ( V_64 ) {
V_65 = F_39 ( V_9 ) ;
if ( V_65 )
F_40 ( V_9 -> V_15 , L_10 , V_65 ) ;
}
return V_62 ;
}
static T_2 F_41 ( struct V_4 * V_4 ,
const char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_8 * V_9 = F_36 ( V_4 -> V_10 ,
struct V_8 , V_69 ) ;
T_2 V_62 ;
bool V_63 ;
V_9 -> V_66 ( V_9 -> V_67 ) ;
V_63 = V_9 -> V_69 ;
V_62 = F_37 ( V_4 , V_5 , V_6 , V_7 ) ;
if ( V_62 < 0 )
goto V_47;
if ( V_9 -> V_69 && ! V_63 ) {
F_38 ( V_9 -> V_15 , L_11 ) ;
F_28 ( V_51 , V_52 ) ;
} else if ( ! V_9 -> V_69 && V_63 ) {
F_38 ( V_9 -> V_15 , L_12 ) ;
}
V_47:
V_9 -> V_68 ( V_9 -> V_67 ) ;
return V_62 ;
}
void F_42 ( struct V_8 * V_9 , const char * V_17 )
{
struct V_70 * V_71 ;
struct V_53 * V_72 ;
const char * V_73 = L_13 ;
if ( ! V_74 ) {
struct V_75 * V_76 ;
V_76 = F_15 ( sizeof( * V_76 ) , V_13 ) ;
if ( ! V_76 )
return;
V_76 -> V_9 = V_9 ;
V_76 -> V_17 = V_17 ;
F_11 ( & V_77 ) ;
F_43 ( & V_76 -> V_78 , & V_79 ) ;
F_16 ( & V_77 ) ;
return;
}
F_44 ( & V_9 -> V_20 ) ;
F_45 ( & V_9 -> V_29 ) ;
if ( V_9 -> V_15 )
V_73 = F_46 ( V_9 -> V_15 ) ;
if ( V_17 ) {
V_9 -> V_80 = F_47 ( V_13 , L_14 ,
V_73 , V_17 ) ;
V_17 = V_9 -> V_80 ;
} else {
V_17 = V_73 ;
}
V_9 -> V_81 = F_48 ( V_17 , V_74 ) ;
if ( ! V_9 -> V_81 ) {
F_38 ( V_9 -> V_15 , L_15 ) ;
return;
}
F_49 ( L_16 , 0400 , V_9 -> V_81 ,
V_9 , & V_82 ) ;
F_49 ( L_17 , 0400 , V_9 -> V_81 ,
V_9 , & V_83 ) ;
if ( V_9 -> V_30 || F_12 ( V_9 , 0 ) ) {
T_5 V_84 ;
#if F_50 ( V_85 )
V_84 = 0600 ;
#else
V_84 = 0400 ;
#endif
F_49 ( L_18 , V_84 , V_9 -> V_81 ,
V_9 , & V_86 ) ;
F_49 ( L_19 , 0400 , V_9 -> V_81 ,
V_9 , & V_87 ) ;
}
if ( V_9 -> V_88 ) {
F_49 ( L_20 , 0600 , V_9 -> V_81 ,
& V_9 -> V_61 , & V_89 ) ;
F_51 ( L_21 , 0400 , V_9 -> V_81 ,
& V_9 -> V_90 ) ;
F_49 ( L_22 , 0600 , V_9 -> V_81 ,
& V_9 -> V_69 ,
& V_91 ) ;
}
V_71 = F_52 ( & V_9 -> V_92 ) ;
while ( V_71 ) {
V_72 = F_53 ( V_71 , struct V_53 , V_76 ) ;
if ( V_72 -> V_17 )
F_49 ( V_72 -> V_17 , 0400 ,
V_9 -> V_81 , V_72 ,
& V_93 ) ;
V_71 = F_54 ( & V_72 -> V_76 ) ;
}
if ( V_9 -> V_94 && V_9 -> V_94 -> V_95 )
V_9 -> V_94 -> V_95 ( V_9 ) ;
}
void F_55 ( struct V_8 * V_9 )
{
if ( V_9 -> V_81 ) {
F_56 ( V_9 -> V_81 ) ;
F_11 ( & V_9 -> V_29 ) ;
F_6 ( V_9 ) ;
F_16 ( & V_9 -> V_29 ) ;
F_4 ( V_9 -> V_80 ) ;
} else {
struct V_75 * V_76 , * V_96 ;
F_11 ( & V_77 ) ;
F_57 (node, tmp, &regmap_debugfs_early_list,
link) {
if ( V_76 -> V_9 == V_9 ) {
F_9 ( & V_76 -> V_78 ) ;
F_4 ( V_76 ) ;
}
}
F_16 ( & V_77 ) ;
}
}
void F_58 ( void )
{
struct V_75 * V_76 , * V_96 ;
V_74 = F_48 ( L_23 , NULL ) ;
if ( ! V_74 ) {
F_59 ( L_24 ) ;
return;
}
F_11 ( & V_77 ) ;
F_57 (node, tmp, &regmap_debugfs_early_list, link) {
F_42 ( V_76 -> V_9 , V_76 -> V_17 ) ;
F_9 ( & V_76 -> V_78 ) ;
F_4 ( V_76 ) ;
}
F_16 ( & V_77 ) ;
}
