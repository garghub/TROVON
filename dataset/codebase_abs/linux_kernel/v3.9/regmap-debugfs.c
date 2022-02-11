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
if ( F_7 ( & V_9 -> V_20 ) ) {
for ( V_26 = V_22 ; V_26 <= V_9 -> V_29 ; V_26 += V_9 -> V_30 ) {
if ( ! F_11 ( V_9 , V_26 ) ||
F_12 ( V_9 , V_26 ) ) {
if ( V_19 ) {
V_19 -> V_31 = V_25 - 1 ;
V_27 = V_19 -> V_31 - V_19 -> V_32 ;
V_28 = V_27 / V_9 -> V_33 ;
V_19 -> V_34 = V_19 -> V_35 + V_28 ;
F_13 ( & V_19 -> V_21 ,
& V_9 -> V_20 ) ;
V_19 = NULL ;
}
continue;
}
if ( ! V_19 ) {
V_19 = F_14 ( sizeof( * V_19 ) , V_13 ) ;
if ( ! V_19 ) {
F_6 ( V_9 ) ;
return V_22 ;
}
V_19 -> V_32 = V_25 ;
V_19 -> V_35 = V_26 ;
}
V_25 += V_9 -> V_33 ;
}
}
if ( V_19 ) {
V_19 -> V_31 = V_25 - 1 ;
V_27 = V_19 -> V_31 - V_19 -> V_32 ;
V_28 = V_27 / V_9 -> V_33 ;
V_19 -> V_34 = V_19 -> V_35 + V_28 ;
F_13 ( & V_19 -> V_21 ,
& V_9 -> V_20 ) ;
}
F_15 ( F_7 ( & V_9 -> V_20 ) ) ;
V_11 = V_22 ;
F_16 (c, &map->debugfs_off_cache, list) {
if ( V_23 >= V_19 -> V_32 && V_23 <= V_19 -> V_31 ) {
V_27 = V_23 - V_19 -> V_32 ;
V_28 = V_27 / V_9 -> V_33 ;
* V_24 = V_19 -> V_32 + ( V_28 * V_9 -> V_33 ) ;
return V_19 -> V_35 + V_28 ;
}
* V_24 = V_19 -> V_31 ;
V_11 = V_19 -> V_34 ;
}
return V_11 ;
}
static inline void F_17 ( struct V_8 * V_9 ,
void * V_2 , T_1 V_6 )
{
if ( ! V_9 -> V_33 ) {
V_9 -> V_36 = F_1 ( V_9 -> V_29 ,
V_2 , V_6 ) ;
V_9 -> V_37 = 2 * V_9 -> V_38 . V_39 ;
V_9 -> V_33 = V_9 -> V_36 +
V_9 -> V_37 + 3 ;
}
}
static T_2 F_18 ( struct V_8 * V_9 , unsigned int V_23 ,
unsigned int V_40 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
T_1 V_41 = 0 ;
T_4 V_25 = * V_7 ;
T_2 V_11 ;
int V_26 ;
char * V_2 ;
unsigned int V_42 , V_43 ;
if ( * V_7 < 0 || ! V_6 )
return - V_44 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
F_17 ( V_9 , V_2 , V_6 ) ;
V_43 = F_10 ( V_9 , V_23 , * V_7 , & V_25 ) ;
for ( V_26 = V_43 ; V_26 <= V_40 ; V_26 += V_9 -> V_30 ) {
if ( ! F_11 ( V_9 , V_26 ) )
continue;
if ( F_12 ( V_9 , V_26 ) )
continue;
if ( V_25 >= * V_7 ) {
if ( V_41 + V_9 -> V_33 > V_6 )
break;
snprintf ( V_2 + V_41 , V_6 - V_41 , L_3 ,
V_9 -> V_36 , V_26 - V_23 ) ;
V_41 += V_9 -> V_36 + 2 ;
V_11 = F_19 ( V_9 , V_26 , & V_42 ) ;
if ( V_11 == 0 )
snprintf ( V_2 + V_41 , V_6 - V_41 ,
L_4 , V_9 -> V_37 , V_42 ) ;
else
memset ( V_2 + V_41 , 'X' ,
V_9 -> V_37 ) ;
V_41 += 2 * V_9 -> V_38 . V_39 ;
V_2 [ V_41 ++ ] = '\n' ;
}
V_25 += V_9 -> V_33 ;
}
V_11 = V_41 ;
if ( F_20 ( V_5 , V_2 , V_41 ) ) {
V_11 = - V_45 ;
goto V_46;
}
* V_7 += V_41 ;
V_46:
F_4 ( V_2 ) ;
return V_11 ;
}
static T_2 F_21 ( struct V_4 * V_4 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
return F_18 ( V_9 , 0 , V_9 -> V_29 , V_5 ,
V_6 , V_7 ) ;
}
static T_2 F_22 ( struct V_4 * V_4 ,
const char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
char V_2 [ 32 ] ;
T_1 V_3 ;
char * V_47 = V_2 ;
unsigned long V_48 , V_49 ;
struct V_8 * V_9 = V_4 -> V_10 ;
V_3 = V_32 ( V_6 , ( sizeof( V_2 ) - 1 ) ) ;
if ( F_23 ( V_2 , V_5 , V_3 ) )
return - V_45 ;
V_2 [ V_3 ] = 0 ;
while ( * V_47 == ' ' )
V_47 ++ ;
V_48 = F_24 ( V_47 , & V_47 , 16 ) ;
while ( * V_47 == ' ' )
V_47 ++ ;
if ( F_25 ( V_47 , 16 , & V_49 ) )
return - V_44 ;
F_26 ( V_50 , V_51 ) ;
F_27 ( V_9 , V_48 , V_49 ) ;
return V_3 ;
}
static T_2 F_28 ( struct V_4 * V_4 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_52 * V_53 = V_4 -> V_10 ;
struct V_8 * V_9 = V_53 -> V_9 ;
return F_18 ( V_9 , V_53 -> V_54 , V_53 -> V_55 ,
V_5 , V_6 , V_7 ) ;
}
static T_2 F_29 ( struct V_4 * V_4 ,
char T_3 * V_5 , T_1 V_6 ,
T_4 * V_7 )
{
int V_56 , V_57 ;
T_1 V_41 = 0 ;
T_4 V_25 = 0 ;
T_2 V_11 ;
int V_26 ;
struct V_8 * V_9 = V_4 -> V_10 ;
char * V_2 ;
if ( * V_7 < 0 || ! V_6 )
return - V_44 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_56 = F_1 ( V_9 -> V_29 , V_2 , V_6 ) ;
V_57 = V_56 + 10 ;
for ( V_26 = 0 ; V_26 <= V_9 -> V_29 ; V_26 += V_9 -> V_30 ) {
if ( ! F_11 ( V_9 , V_26 ) && ! F_30 ( V_9 , V_26 ) )
continue;
if ( V_25 >= * V_7 ) {
if ( V_41 >= V_6 - 1 - V_57 )
break;
snprintf ( V_2 + V_41 , V_6 - V_41 ,
L_5 ,
V_56 , V_26 ,
F_11 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_30 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_31 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_12 ( V_9 , V_26 ) ? 'y' : 'n' ) ;
V_41 += V_57 ;
}
V_25 += V_57 ;
}
V_11 = V_41 ;
if ( F_20 ( V_5 , V_2 , V_41 ) ) {
V_11 = - V_45 ;
goto V_46;
}
* V_7 += V_41 ;
V_46:
F_4 ( V_2 ) ;
return V_11 ;
}
void F_32 ( struct V_8 * V_9 , const char * V_17 )
{
struct V_58 * V_59 ;
struct V_52 * V_60 ;
F_33 ( & V_9 -> V_20 ) ;
if ( V_17 ) {
V_9 -> V_61 = F_34 ( V_13 , L_6 ,
F_35 ( V_9 -> V_15 ) , V_17 ) ;
V_17 = V_9 -> V_61 ;
} else {
V_17 = F_35 ( V_9 -> V_15 ) ;
}
V_9 -> V_62 = F_36 ( V_17 , V_63 ) ;
if ( ! V_9 -> V_62 ) {
F_37 ( V_9 -> V_15 , L_7 ) ;
return;
}
F_38 ( L_8 , 0400 , V_9 -> V_62 ,
V_9 , & V_64 ) ;
if ( V_9 -> V_29 ) {
F_38 ( L_9 , 0400 , V_9 -> V_62 ,
V_9 , & V_65 ) ;
F_38 ( L_10 , 0400 , V_9 -> V_62 ,
V_9 , & V_66 ) ;
}
if ( V_9 -> V_67 ) {
F_39 ( L_11 , 0400 , V_9 -> V_62 ,
& V_9 -> V_68 ) ;
F_39 ( L_12 , 0400 , V_9 -> V_62 ,
& V_9 -> V_69 ) ;
F_39 ( L_13 , 0400 , V_9 -> V_62 ,
& V_9 -> V_70 ) ;
}
V_59 = F_40 ( & V_9 -> V_71 ) ;
while ( V_59 ) {
V_60 = F_41 ( V_59 , struct V_52 , V_72 ) ;
if ( V_60 -> V_17 )
F_38 ( V_60 -> V_17 , 0400 ,
V_9 -> V_62 , V_60 ,
& V_73 ) ;
V_59 = F_42 ( & V_60 -> V_72 ) ;
}
}
void F_43 ( struct V_8 * V_9 )
{
F_44 ( V_9 -> V_62 ) ;
F_6 ( V_9 ) ;
F_4 ( V_9 -> V_61 ) ;
}
void F_45 ( void )
{
V_63 = F_36 ( L_14 , NULL ) ;
if ( ! V_63 ) {
F_46 ( L_15 ) ;
return;
}
}
