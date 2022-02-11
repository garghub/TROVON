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
if ( F_7 ( & V_9 -> V_20 ) ) {
for ( V_26 = V_22 ; V_26 <= V_9 -> V_27 ; V_26 += V_9 -> V_28 ) {
if ( ! F_11 ( V_9 , V_26 ) ||
F_12 ( V_9 , V_26 ) ) {
if ( V_19 ) {
V_19 -> V_29 = V_25 - 1 ;
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
V_19 -> V_30 = V_25 ;
V_19 -> V_31 = V_26 ;
}
V_25 += V_9 -> V_32 ;
}
}
if ( V_19 ) {
V_19 -> V_29 = V_25 - 1 ;
F_13 ( & V_19 -> V_21 ,
& V_9 -> V_20 ) ;
}
if ( F_7 ( & V_9 -> V_20 ) ) {
F_15 ( F_7 ( & V_9 -> V_20 ) ) ;
return V_22 ;
}
F_16 (c, &map->debugfs_off_cache, list) {
if ( V_23 >= V_19 -> V_30 && V_23 <= V_19 -> V_29 ) {
* V_24 = V_19 -> V_30 ;
return V_19 -> V_31 ;
}
* V_24 = V_19 -> V_30 ;
V_11 = V_19 -> V_31 ;
}
return V_11 ;
}
static T_2 F_17 ( struct V_8 * V_9 , unsigned int V_23 ,
unsigned int V_33 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
T_1 V_34 = 0 ;
T_4 V_25 = * V_7 ;
T_2 V_11 ;
int V_26 ;
char * V_2 ;
unsigned int V_35 , V_36 ;
if ( * V_7 < 0 || ! V_6 )
return - V_37 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
if ( ! V_9 -> V_32 ) {
V_9 -> V_38 = F_1 ( V_9 -> V_27 ,
V_2 , V_6 ) ;
V_9 -> V_39 = 2 * V_9 -> V_40 . V_41 ;
V_9 -> V_32 = V_9 -> V_38 +
V_9 -> V_39 + 3 ;
}
V_36 = F_10 ( V_9 , V_23 , * V_7 , & V_25 ) ;
for ( V_26 = V_36 ; V_26 <= V_33 ; V_26 += V_9 -> V_28 ) {
if ( ! F_11 ( V_9 , V_26 ) )
continue;
if ( F_12 ( V_9 , V_26 ) )
continue;
if ( V_25 >= * V_7 ) {
if ( V_34 + 1 + V_9 -> V_32 >= V_6 )
break;
snprintf ( V_2 + V_34 , V_6 - V_34 , L_3 ,
V_9 -> V_38 , V_26 - V_23 ) ;
V_34 += V_9 -> V_38 + 2 ;
V_11 = F_18 ( V_9 , V_26 , & V_35 ) ;
if ( V_11 == 0 )
snprintf ( V_2 + V_34 , V_6 - V_34 ,
L_4 , V_9 -> V_39 , V_35 ) ;
else
memset ( V_2 + V_34 , 'X' ,
V_9 -> V_39 ) ;
V_34 += 2 * V_9 -> V_40 . V_41 ;
V_2 [ V_34 ++ ] = '\n' ;
}
V_25 += V_9 -> V_32 ;
}
V_11 = V_34 ;
if ( F_19 ( V_5 , V_2 , V_34 ) ) {
V_11 = - V_42 ;
goto V_43;
}
* V_7 += V_34 ;
V_43:
F_4 ( V_2 ) ;
return V_11 ;
}
static T_2 F_20 ( struct V_4 * V_4 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
return F_17 ( V_9 , 0 , V_9 -> V_27 , V_5 ,
V_6 , V_7 ) ;
}
static T_2 F_21 ( struct V_4 * V_4 ,
const char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
char V_2 [ 32 ] ;
T_1 V_3 ;
char * V_44 = V_2 ;
unsigned long V_45 , V_46 ;
struct V_8 * V_9 = V_4 -> V_10 ;
V_3 = V_30 ( V_6 , ( sizeof( V_2 ) - 1 ) ) ;
if ( F_22 ( V_2 , V_5 , V_3 ) )
return - V_42 ;
V_2 [ V_3 ] = 0 ;
while ( * V_44 == ' ' )
V_44 ++ ;
V_45 = F_23 ( V_44 , & V_44 , 16 ) ;
while ( * V_44 == ' ' )
V_44 ++ ;
if ( F_24 ( V_44 , 16 , & V_46 ) )
return - V_37 ;
F_25 ( V_47 ) ;
F_26 ( V_9 , V_45 , V_46 ) ;
return V_3 ;
}
static T_2 F_27 ( struct V_4 * V_4 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
struct V_48 * V_49 = V_4 -> V_10 ;
struct V_8 * V_9 = V_49 -> V_9 ;
return F_17 ( V_9 , V_49 -> V_50 , V_49 -> V_51 ,
V_5 , V_6 , V_7 ) ;
}
static T_2 F_28 ( struct V_4 * V_4 ,
char T_3 * V_5 , T_1 V_6 ,
T_4 * V_7 )
{
int V_52 , V_53 ;
T_1 V_34 = 0 ;
T_4 V_25 = 0 ;
T_2 V_11 ;
int V_26 ;
struct V_8 * V_9 = V_4 -> V_10 ;
char * V_2 ;
if ( * V_7 < 0 || ! V_6 )
return - V_37 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_52 = F_1 ( V_9 -> V_27 , V_2 , V_6 ) ;
V_53 = V_52 + 10 ;
for ( V_26 = 0 ; V_26 <= V_9 -> V_27 ; V_26 += V_9 -> V_28 ) {
if ( ! F_11 ( V_9 , V_26 ) && ! F_29 ( V_9 , V_26 ) )
continue;
if ( V_25 >= * V_7 ) {
if ( V_34 >= V_6 - 1 - V_53 )
break;
snprintf ( V_2 + V_34 , V_6 - V_34 ,
L_5 ,
V_52 , V_26 ,
F_11 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_29 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_30 ( V_9 , V_26 ) ? 'y' : 'n' ,
F_12 ( V_9 , V_26 ) ? 'y' : 'n' ) ;
V_34 += V_53 ;
}
V_25 += V_53 ;
}
V_11 = V_34 ;
if ( F_19 ( V_5 , V_2 , V_34 ) ) {
V_11 = - V_42 ;
goto V_43;
}
* V_7 += V_34 ;
V_43:
F_4 ( V_2 ) ;
return V_11 ;
}
void F_31 ( struct V_8 * V_9 , const char * V_17 )
{
struct V_54 * V_55 ;
struct V_48 * V_56 ;
F_32 ( & V_9 -> V_20 ) ;
if ( V_17 ) {
V_9 -> V_57 = F_33 ( V_13 , L_6 ,
F_34 ( V_9 -> V_15 ) , V_17 ) ;
V_17 = V_9 -> V_57 ;
} else {
V_17 = F_34 ( V_9 -> V_15 ) ;
}
V_9 -> V_58 = F_35 ( V_17 , V_59 ) ;
if ( ! V_9 -> V_58 ) {
F_36 ( V_9 -> V_15 , L_7 ) ;
return;
}
F_37 ( L_8 , 0400 , V_9 -> V_58 ,
V_9 , & V_60 ) ;
if ( V_9 -> V_27 ) {
F_37 ( L_9 , 0400 , V_9 -> V_58 ,
V_9 , & V_61 ) ;
F_37 ( L_10 , 0400 , V_9 -> V_58 ,
V_9 , & V_62 ) ;
}
if ( V_9 -> V_63 ) {
F_38 ( L_11 , 0400 , V_9 -> V_58 ,
& V_9 -> V_64 ) ;
F_38 ( L_12 , 0400 , V_9 -> V_58 ,
& V_9 -> V_65 ) ;
F_38 ( L_13 , 0400 , V_9 -> V_58 ,
& V_9 -> V_66 ) ;
}
V_55 = F_39 ( & V_9 -> V_67 ) ;
while ( V_55 ) {
V_56 = F_40 ( V_55 , struct V_48 , V_68 ) ;
if ( V_56 -> V_17 )
F_37 ( V_56 -> V_17 , 0400 ,
V_9 -> V_58 , V_56 ,
& V_69 ) ;
V_55 = F_41 ( & V_56 -> V_68 ) ;
}
}
void F_42 ( struct V_8 * V_9 )
{
F_43 ( V_9 -> V_58 ) ;
F_6 ( V_9 ) ;
F_4 ( V_9 -> V_57 ) ;
}
void F_44 ( void )
{
V_59 = F_35 ( L_14 , NULL ) ;
if ( ! V_59 ) {
F_45 ( L_15 ) ;
return;
}
}
