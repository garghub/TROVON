static T_1 F_1 ( int V_1 )
{
return snprintf ( NULL , 0 , L_1 , V_1 ) ;
}
static T_2 F_2 ( struct V_2 * V_2 ,
char T_3 * V_3 , T_1 V_4 ,
T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
char * V_10 ;
V_10 = F_3 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_9 = snprintf ( V_10 , V_11 , L_2 , V_7 -> V_14 -> V_15 -> V_16 ) ;
if ( V_9 < 0 ) {
F_4 ( V_10 ) ;
return V_9 ;
}
V_9 = F_5 ( V_3 , V_4 , V_5 , V_10 , V_9 ) ;
F_4 ( V_10 ) ;
return V_9 ;
}
static void F_6 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
while ( ! F_7 ( & V_7 -> V_19 ) ) {
V_18 = F_8 ( & V_7 -> V_19 ,
struct V_17 ,
V_20 ) ;
F_9 ( & V_18 -> V_20 ) ;
F_4 ( V_18 ) ;
}
}
static unsigned int F_10 ( struct V_6 * V_7 ,
unsigned int V_21 ,
T_4 V_22 ,
T_4 * V_23 )
{
struct V_17 * V_18 = NULL ;
T_4 V_24 = 0 ;
unsigned int V_25 , V_9 ;
unsigned int V_26 ;
unsigned int V_27 ;
if ( V_21 )
return V_21 ;
F_11 ( & V_7 -> V_28 ) ;
V_25 = V_21 ;
if ( F_7 ( & V_7 -> V_19 ) ) {
for (; V_25 <= V_7 -> V_29 ; V_25 += V_7 -> V_30 ) {
if ( ! F_12 ( V_7 , V_25 ) ||
F_13 ( V_7 , V_25 ) ) {
if ( V_18 ) {
V_18 -> V_31 = V_24 - 1 ;
V_18 -> V_32 = V_25 - V_7 -> V_30 ;
F_14 ( & V_18 -> V_20 ,
& V_7 -> V_19 ) ;
V_18 = NULL ;
}
continue;
}
if ( ! V_18 ) {
V_18 = F_15 ( sizeof( * V_18 ) , V_12 ) ;
if ( ! V_18 ) {
F_6 ( V_7 ) ;
F_16 ( & V_7 -> V_28 ) ;
return V_21 ;
}
V_18 -> V_33 = V_24 ;
V_18 -> V_34 = V_25 ;
}
V_24 += V_7 -> V_35 ;
}
}
if ( V_18 ) {
V_18 -> V_31 = V_24 - 1 ;
V_18 -> V_32 = V_25 - V_7 -> V_30 ;
F_14 ( & V_18 -> V_20 ,
& V_7 -> V_19 ) ;
}
F_17 ( F_7 ( & V_7 -> V_19 ) ) ;
V_9 = V_21 ;
F_18 (c, &map->debugfs_off_cache, list) {
if ( V_22 >= V_18 -> V_33 && V_22 <= V_18 -> V_31 ) {
V_26 = V_22 - V_18 -> V_33 ;
V_27 = V_26 / V_7 -> V_35 ;
* V_23 = V_18 -> V_33 + ( V_27 * V_7 -> V_35 ) ;
F_16 ( & V_7 -> V_28 ) ;
return V_18 -> V_34 + ( V_27 * V_7 -> V_30 ) ;
}
* V_23 = V_18 -> V_31 ;
V_9 = V_18 -> V_32 ;
}
F_16 ( & V_7 -> V_28 ) ;
return V_9 ;
}
static inline void F_19 ( struct V_6 * V_7 ,
void * V_10 , T_1 V_4 )
{
if ( ! V_7 -> V_35 ) {
V_7 -> V_36 = F_1 ( V_7 -> V_29 ) ,
V_7 -> V_37 = 2 * V_7 -> V_38 . V_39 ;
V_7 -> V_35 = V_7 -> V_36 +
V_7 -> V_37 + 3 ;
}
}
static T_2 F_20 ( struct V_6 * V_7 , unsigned int V_22 ,
unsigned int V_40 , char T_3 * V_3 ,
T_1 V_4 , T_4 * V_5 )
{
T_1 V_41 = 0 ;
T_4 V_24 = * V_5 ;
T_2 V_9 ;
int V_25 ;
char * V_10 ;
unsigned int V_42 , V_43 ;
if ( * V_5 < 0 || ! V_4 )
return - V_44 ;
V_10 = F_3 ( V_4 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
F_19 ( V_7 , V_10 , V_4 ) ;
V_43 = F_10 ( V_7 , V_22 , * V_5 , & V_24 ) ;
for ( V_25 = V_43 ; V_25 <= V_40 ; V_25 += V_7 -> V_30 ) {
if ( ! F_12 ( V_7 , V_25 ) )
continue;
if ( F_13 ( V_7 , V_25 ) )
continue;
if ( V_24 >= * V_5 ) {
if ( V_41 + V_7 -> V_35 > V_4 )
break;
snprintf ( V_10 + V_41 , V_4 - V_41 , L_3 ,
V_7 -> V_36 , V_25 - V_22 ) ;
V_41 += V_7 -> V_36 + 2 ;
V_9 = F_21 ( V_7 , V_25 , & V_42 ) ;
if ( V_9 == 0 )
snprintf ( V_10 + V_41 , V_4 - V_41 ,
L_4 , V_7 -> V_37 , V_42 ) ;
else
memset ( V_10 + V_41 , 'X' ,
V_7 -> V_37 ) ;
V_41 += 2 * V_7 -> V_38 . V_39 ;
V_10 [ V_41 ++ ] = '\n' ;
}
V_24 += V_7 -> V_35 ;
}
V_9 = V_41 ;
if ( F_22 ( V_3 , V_10 , V_41 ) ) {
V_9 = - V_45 ;
goto V_46;
}
* V_5 += V_41 ;
V_46:
F_4 ( V_10 ) ;
return V_9 ;
}
static T_2 F_23 ( struct V_2 * V_2 , char T_3 * V_3 ,
T_1 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
return F_20 ( V_7 , 0 , V_7 -> V_29 , V_3 ,
V_4 , V_5 ) ;
}
static T_2 F_24 ( struct V_2 * V_2 ,
const char T_3 * V_3 ,
T_1 V_4 , T_4 * V_5 )
{
char V_10 [ 32 ] ;
T_1 V_47 ;
char * V_48 = V_10 ;
unsigned long V_49 , V_50 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
V_47 = V_33 ( V_4 , ( sizeof( V_10 ) - 1 ) ) ;
if ( F_25 ( V_10 , V_3 , V_47 ) )
return - V_45 ;
V_10 [ V_47 ] = 0 ;
while ( * V_48 == ' ' )
V_48 ++ ;
V_49 = F_26 ( V_48 , & V_48 , 16 ) ;
while ( * V_48 == ' ' )
V_48 ++ ;
if ( F_27 ( V_48 , 16 , & V_50 ) )
return - V_44 ;
F_28 ( V_51 , V_52 ) ;
V_9 = F_29 ( V_7 , V_49 , V_50 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_47 ;
}
static T_2 F_30 ( struct V_2 * V_2 , char T_3 * V_3 ,
T_1 V_4 , T_4 * V_5 )
{
struct V_53 * V_54 = V_2 -> V_8 ;
struct V_6 * V_7 = V_54 -> V_7 ;
return F_20 ( V_7 , V_54 -> V_55 , V_54 -> V_56 ,
V_3 , V_4 , V_5 ) ;
}
static T_2 F_31 ( struct V_2 * V_2 ,
char T_3 * V_3 , T_1 V_4 ,
T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_17 * V_18 ;
T_4 V_24 = 0 ;
T_1 V_41 = 0 ;
char * V_10 ;
char * V_57 ;
int V_9 ;
unsigned V_58 ;
if ( * V_5 < 0 || ! V_4 )
return - V_44 ;
V_10 = F_3 ( V_4 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_57 = F_3 ( V_11 , V_12 ) ;
if ( ! V_57 ) {
F_4 ( V_10 ) ;
return - V_13 ;
}
F_19 ( V_7 , V_10 , V_4 ) ;
F_10 ( V_7 , 0 , * V_5 , & V_24 ) ;
V_24 = 0 ;
F_11 ( & V_7 -> V_28 ) ;
F_18 (c, &map->debugfs_off_cache, list) {
V_58 = snprintf ( V_57 , V_11 , L_5 ,
V_18 -> V_34 , V_18 -> V_32 ) ;
if ( V_24 >= * V_5 ) {
if ( V_41 + V_58 > V_4 )
break;
memcpy ( V_10 + V_41 , V_57 , V_58 ) ;
V_41 += V_58 ;
}
V_24 += V_58 ;
}
F_16 ( & V_7 -> V_28 ) ;
F_4 ( V_57 ) ;
V_9 = V_41 ;
if ( F_22 ( V_3 , V_10 , V_41 ) ) {
V_9 = - V_45 ;
goto V_59;
}
* V_5 += V_41 ;
V_59:
F_4 ( V_10 ) ;
return V_9 ;
}
static int F_32 ( struct V_60 * V_61 , void * V_62 )
{
struct V_6 * V_7 = V_61 -> V_63 ;
int V_25 , V_64 ;
V_64 = F_1 ( V_7 -> V_29 ) ;
for ( V_25 = 0 ; V_25 <= V_7 -> V_29 ; V_25 += V_7 -> V_30 ) {
if ( ! F_12 ( V_7 , V_25 ) && ! F_33 ( V_7 , V_25 ) )
continue;
F_34 ( V_61 , L_6 , V_64 , V_25 ,
F_12 ( V_7 , V_25 ) ? 'y' : 'n' ,
F_33 ( V_7 , V_25 ) ? 'y' : 'n' ,
F_35 ( V_7 , V_25 ) ? 'y' : 'n' ,
F_13 ( V_7 , V_25 ) ? 'y' : 'n' ) ;
}
return 0 ;
}
static int F_36 ( struct V_65 * V_65 , struct V_2 * V_2 )
{
return F_37 ( V_2 , F_32 , V_65 -> V_66 ) ;
}
static T_2 F_38 ( struct V_2 * V_2 ,
const char T_3 * V_3 ,
T_1 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = F_39 ( V_2 -> V_8 ,
struct V_6 , V_67 ) ;
T_2 V_68 ;
bool V_69 , V_70 = false ;
int V_71 ;
V_7 -> V_72 ( V_7 -> V_73 ) ;
V_69 = V_7 -> V_67 ;
V_68 = F_40 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_68 < 0 ) {
V_7 -> V_74 ( V_7 -> V_73 ) ;
return V_68 ;
}
if ( V_7 -> V_67 && ! V_69 ) {
F_41 ( V_7 -> V_14 , L_7 ) ;
F_28 ( V_51 , V_52 ) ;
} else if ( ! V_7 -> V_67 && V_69 ) {
F_41 ( V_7 -> V_14 , L_8 ) ;
V_70 = true ;
}
V_7 -> V_74 ( V_7 -> V_73 ) ;
if ( V_70 ) {
V_71 = F_42 ( V_7 ) ;
if ( V_71 )
F_43 ( V_7 -> V_14 , L_9 , V_71 ) ;
}
return V_68 ;
}
static T_2 F_44 ( struct V_2 * V_2 ,
const char T_3 * V_3 ,
T_1 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = F_39 ( V_2 -> V_8 ,
struct V_6 , V_75 ) ;
T_2 V_68 ;
bool V_69 ;
V_7 -> V_72 ( V_7 -> V_73 ) ;
V_69 = V_7 -> V_75 ;
V_68 = F_40 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_68 < 0 )
goto V_46;
if ( V_7 -> V_75 && ! V_69 ) {
F_41 ( V_7 -> V_14 , L_10 ) ;
F_28 ( V_51 , V_52 ) ;
} else if ( ! V_7 -> V_75 && V_69 ) {
F_41 ( V_7 -> V_14 , L_11 ) ;
}
V_46:
V_7 -> V_74 ( V_7 -> V_73 ) ;
return V_68 ;
}
void F_45 ( struct V_6 * V_7 , const char * V_16 )
{
struct V_76 * V_77 ;
struct V_53 * V_78 ;
const char * V_79 = L_12 ;
if ( ! V_80 ) {
struct V_81 * V_82 ;
V_82 = F_15 ( sizeof( * V_82 ) , V_12 ) ;
if ( ! V_82 )
return;
V_82 -> V_7 = V_7 ;
V_82 -> V_16 = V_16 ;
F_11 ( & V_83 ) ;
F_46 ( & V_82 -> V_84 , & V_85 ) ;
F_16 ( & V_83 ) ;
return;
}
F_47 ( & V_7 -> V_19 ) ;
F_48 ( & V_7 -> V_28 ) ;
if ( V_7 -> V_14 )
V_79 = F_49 ( V_7 -> V_14 ) ;
if ( V_16 ) {
V_7 -> V_86 = F_50 ( V_12 , L_13 ,
V_79 , V_16 ) ;
V_16 = V_7 -> V_86 ;
} else {
V_16 = V_79 ;
}
V_7 -> V_87 = F_51 ( V_16 , V_80 ) ;
if ( ! V_7 -> V_87 ) {
F_41 ( V_7 -> V_14 , L_14 ) ;
return;
}
F_52 ( L_15 , 0400 , V_7 -> V_87 ,
V_7 , & V_88 ) ;
F_52 ( L_16 , 0400 , V_7 -> V_87 ,
V_7 , & V_89 ) ;
if ( V_7 -> V_29 || F_12 ( V_7 , 0 ) ) {
T_5 V_90 ;
#if F_53 ( V_91 )
V_90 = 0600 ;
#else
V_90 = 0400 ;
#endif
F_52 ( L_17 , V_90 , V_7 -> V_87 ,
V_7 , & V_92 ) ;
F_52 ( L_18 , 0400 , V_7 -> V_87 ,
V_7 , & V_93 ) ;
}
if ( V_7 -> V_94 ) {
F_52 ( L_19 , 0600 , V_7 -> V_87 ,
& V_7 -> V_67 , & V_95 ) ;
F_54 ( L_20 , 0400 , V_7 -> V_87 ,
& V_7 -> V_96 ) ;
F_52 ( L_21 , 0600 , V_7 -> V_87 ,
& V_7 -> V_75 ,
& V_97 ) ;
}
V_77 = F_55 ( & V_7 -> V_98 ) ;
while ( V_77 ) {
V_78 = F_56 ( V_77 , struct V_53 , V_82 ) ;
if ( V_78 -> V_16 )
F_52 ( V_78 -> V_16 , 0400 ,
V_7 -> V_87 , V_78 ,
& V_99 ) ;
V_77 = F_57 ( & V_78 -> V_82 ) ;
}
if ( V_7 -> V_100 && V_7 -> V_100 -> V_101 )
V_7 -> V_100 -> V_101 ( V_7 ) ;
}
void F_58 ( struct V_6 * V_7 )
{
if ( V_7 -> V_87 ) {
F_59 ( V_7 -> V_87 ) ;
F_11 ( & V_7 -> V_28 ) ;
F_6 ( V_7 ) ;
F_16 ( & V_7 -> V_28 ) ;
F_4 ( V_7 -> V_86 ) ;
} else {
struct V_81 * V_82 , * V_102 ;
F_11 ( & V_83 ) ;
F_60 (node, tmp, &regmap_debugfs_early_list,
link) {
if ( V_82 -> V_7 == V_7 ) {
F_9 ( & V_82 -> V_84 ) ;
F_4 ( V_82 ) ;
}
}
F_16 ( & V_83 ) ;
}
}
void F_61 ( void )
{
struct V_81 * V_82 , * V_102 ;
V_80 = F_51 ( L_22 , NULL ) ;
if ( ! V_80 ) {
F_62 ( L_23 ) ;
return;
}
F_11 ( & V_83 ) ;
F_60 (node, tmp, &regmap_debugfs_early_list, link) {
F_45 ( V_82 -> V_7 , V_82 -> V_16 ) ;
F_9 ( & V_82 -> V_84 ) ;
F_4 ( V_82 ) ;
}
F_16 ( & V_83 ) ;
}
