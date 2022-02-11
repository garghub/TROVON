static T_1 F_1 ( int V_1 , char * V_2 , T_1 V_3 )
{
snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return strlen ( V_2 ) ;
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
if ( V_42 >= V_6 - 1 - V_60 )
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
void F_35 ( struct V_8 * V_9 , const char * V_17 )
{
struct V_61 * V_62 ;
struct V_53 * V_63 ;
if ( ! V_64 ) {
struct V_65 * V_66 ;
V_66 = F_15 ( sizeof( * V_66 ) , V_13 ) ;
if ( ! V_66 )
return;
V_66 -> V_9 = V_9 ;
V_66 -> V_17 = V_17 ;
F_11 ( & V_67 ) ;
F_36 ( & V_66 -> V_68 , & V_69 ) ;
F_16 ( & V_67 ) ;
return;
}
F_37 ( & V_9 -> V_20 ) ;
F_38 ( & V_9 -> V_29 ) ;
if ( V_17 ) {
V_9 -> V_70 = F_39 ( V_13 , L_8 ,
F_40 ( V_9 -> V_15 ) , V_17 ) ;
V_17 = V_9 -> V_70 ;
} else {
V_17 = F_40 ( V_9 -> V_15 ) ;
}
V_9 -> V_71 = F_41 ( V_17 , V_64 ) ;
if ( ! V_9 -> V_71 ) {
F_42 ( V_9 -> V_15 , L_9 ) ;
return;
}
F_43 ( L_10 , 0400 , V_9 -> V_71 ,
V_9 , & V_72 ) ;
F_43 ( L_11 , 0400 , V_9 -> V_71 ,
V_9 , & V_73 ) ;
if ( V_9 -> V_30 ) {
F_43 ( L_12 , 0400 , V_9 -> V_71 ,
V_9 , & V_74 ) ;
F_43 ( L_13 , 0400 , V_9 -> V_71 ,
V_9 , & V_75 ) ;
}
if ( V_9 -> V_76 ) {
F_44 ( L_14 , 0400 , V_9 -> V_71 ,
& V_9 -> V_77 ) ;
F_44 ( L_15 , 0400 , V_9 -> V_71 ,
& V_9 -> V_78 ) ;
F_44 ( L_16 , 0400 , V_9 -> V_71 ,
& V_9 -> V_79 ) ;
}
V_62 = F_45 ( & V_9 -> V_80 ) ;
while ( V_62 ) {
V_63 = F_46 ( V_62 , struct V_53 , V_66 ) ;
if ( V_63 -> V_17 )
F_43 ( V_63 -> V_17 , 0400 ,
V_9 -> V_71 , V_63 ,
& V_81 ) ;
V_62 = F_47 ( & V_63 -> V_66 ) ;
}
}
void F_48 ( struct V_8 * V_9 )
{
if ( V_9 -> V_71 ) {
F_49 ( V_9 -> V_71 ) ;
F_11 ( & V_9 -> V_29 ) ;
F_6 ( V_9 ) ;
F_16 ( & V_9 -> V_29 ) ;
F_4 ( V_9 -> V_70 ) ;
} else {
struct V_65 * V_66 , * V_82 ;
F_11 ( & V_67 ) ;
F_50 (node, tmp, &regmap_debugfs_early_list,
link) {
if ( V_66 -> V_9 == V_9 ) {
F_9 ( & V_66 -> V_68 ) ;
F_4 ( V_66 ) ;
}
}
F_16 ( & V_67 ) ;
}
}
void F_51 ( void )
{
struct V_65 * V_66 , * V_82 ;
V_64 = F_41 ( L_17 , NULL ) ;
if ( ! V_64 ) {
F_52 ( L_18 ) ;
return;
}
F_11 ( & V_67 ) ;
F_50 (node, tmp, &regmap_debugfs_early_list, link) {
F_35 ( V_66 -> V_9 , V_66 -> V_17 ) ;
F_9 ( & V_66 -> V_68 ) ;
F_4 ( V_66 ) ;
}
F_16 ( & V_67 ) ;
}
