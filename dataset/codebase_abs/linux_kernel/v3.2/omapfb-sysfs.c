static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_5 , V_10 , L_1 , V_9 -> V_11 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_13 * V_14 ;
int V_15 ;
int V_16 ;
V_16 = F_5 ( V_5 , 0 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 != V_17 && V_15 != V_18 )
return - V_19 ;
if ( ! F_6 ( V_7 ) )
return - V_20 ;
V_16 = 0 ;
if ( V_15 == V_9 -> V_11 )
goto V_21;
V_14 = F_7 ( V_9 -> V_22 ) ;
if ( V_14 -> V_23 ) {
V_16 = - V_24 ;
goto V_25;
}
V_9 -> V_11 = V_15 ;
V_25:
F_8 ( V_14 ) ;
V_21:
F_9 ( V_7 ) ;
return V_16 ? V_16 : V_12 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_5 , V_10 , L_1 , V_9 -> V_26 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
bool V_26 ;
int V_16 ;
struct V_27 V_28 ;
V_16 = F_12 ( V_5 , & V_26 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_6 ( V_7 ) )
return - V_20 ;
V_9 -> V_26 = V_26 ;
F_7 ( V_9 -> V_22 ) ;
memcpy ( & V_28 , & V_7 -> V_29 , sizeof( V_28 ) ) ;
V_16 = F_13 ( V_7 , & V_28 ) ;
if ( V_16 )
goto V_21;
memcpy ( & V_7 -> V_29 , & V_28 , sizeof( V_7 -> V_29 ) ) ;
F_14 ( V_7 ) ;
V_16 = F_15 ( V_7 , 0 ) ;
if ( V_16 )
goto V_21;
V_16 = V_12 ;
V_21:
F_8 ( V_9 -> V_22 ) ;
F_9 ( V_7 ) ;
return V_16 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_30 * V_31 = V_9 -> V_31 ;
T_1 V_32 = 0 ;
int V_33 ;
if ( ! F_6 ( V_7 ) )
return - V_20 ;
F_17 ( V_31 ) ;
for ( V_33 = 0 ; V_33 < V_9 -> V_34 ; V_33 ++ ) {
struct V_35 * V_36 = V_9 -> V_37 [ V_33 ] ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_31 -> V_34 ; ++ V_38 )
if ( V_36 == V_31 -> V_37 [ V_38 ] )
break;
V_32 += snprintf ( V_5 + V_32 , V_10 - V_32 , L_2 ,
V_33 == 0 ? L_3 : L_4 , V_38 ) ;
}
V_32 += snprintf ( V_5 + V_32 , V_10 - V_32 , L_5 ) ;
F_18 ( V_31 ) ;
F_9 ( V_7 ) ;
return V_32 ;
}
static struct V_8 * F_19 ( struct V_30 * V_31 ,
struct V_35 * V_36 )
{
int V_39 , V_33 ;
for ( V_39 = 0 ; V_39 < V_31 -> V_40 ; V_39 ++ ) {
struct V_8 * V_9 = F_3 ( V_31 -> V_41 [ V_39 ] ) ;
for ( V_33 = 0 ; V_33 < V_9 -> V_34 ; V_33 ++ ) {
if ( V_9 -> V_37 [ V_33 ] == V_36 )
return V_9 ;
}
}
return NULL ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_30 * V_31 = V_9 -> V_31 ;
struct V_35 * V_42 [ V_43 ] ;
struct V_35 * V_36 ;
int V_44 , V_16 , V_39 ;
int V_45 ;
bool V_46 = false ;
V_44 = 0 ;
V_45 = strlen ( V_5 ) ;
if ( V_5 [ V_45 - 1 ] == '\n' )
V_45 = V_45 - 1 ;
if ( ! F_6 ( V_7 ) )
return - V_20 ;
F_17 ( V_31 ) ;
if ( V_45 > 0 ) {
char * V_47 = ( char * ) V_5 ;
int V_38 ;
while ( V_47 < V_5 + V_45 ) {
int V_48 ;
if ( V_44 == V_43 ) {
V_16 = - V_19 ;
goto V_21;
}
V_38 = F_21 ( V_47 , & V_47 , 0 ) ;
if ( V_38 > V_31 -> V_34 ) {
V_16 = - V_19 ;
goto V_21;
}
V_48 = 0 ;
for ( V_39 = 0 ; V_39 < V_44 ; ++ V_39 ) {
if ( V_42 [ V_39 ] == V_31 -> V_37 [ V_38 ] ) {
V_48 = 1 ;
break;
}
}
if ( ! V_48 )
V_42 [ V_44 ++ ] = V_31 -> V_37 [ V_38 ] ;
V_47 ++ ;
}
}
for ( V_39 = 0 ; V_39 < V_44 ; ++ V_39 ) {
struct V_8 * V_49 = F_19 ( V_31 , V_42 [ V_39 ] ) ;
if ( V_49 && V_49 != V_9 ) {
F_22 ( V_31 -> V_2 , L_6 ) ;
V_16 = - V_19 ;
goto V_21;
}
}
for ( V_39 = 0 ; V_39 < V_9 -> V_34 ; ++ V_39 ) {
int V_33 , V_48 ;
V_36 = V_9 -> V_37 [ V_39 ] ;
V_48 = 0 ;
for ( V_33 = 0 ; V_33 < V_44 ; ++ V_33 ) {
if ( V_36 == V_42 [ V_33 ] ) {
V_48 = 1 ;
break;
}
}
if ( V_48 )
continue;
F_23 ( L_7 , V_9 -> V_37 [ V_39 ] -> V_50 ) ;
F_7 ( V_9 -> V_22 ) ;
F_24 ( V_36 , 0 ) ;
if ( V_36 -> V_51 )
V_36 -> V_51 -> V_52 ( V_36 -> V_51 ) ;
F_8 ( V_9 -> V_22 ) ;
for ( V_33 = V_39 + 1 ; V_33 < V_9 -> V_34 ; V_33 ++ ) {
V_9 -> V_53 [ V_33 - 1 ] = V_9 -> V_53 [ V_33 ] ;
V_9 -> V_37 [ V_33 - 1 ] = V_9 -> V_37 [ V_33 ] ;
}
V_9 -> V_34 -- ;
V_39 -- ;
}
for ( V_39 = 0 ; V_39 < V_44 ; ++ V_39 ) {
int V_33 , V_48 ;
V_36 = V_42 [ V_39 ] ;
V_48 = 0 ;
for ( V_33 = 0 ; V_33 < V_9 -> V_34 ; ++ V_33 ) {
if ( V_36 == V_9 -> V_37 [ V_33 ] ) {
V_48 = 1 ;
break;
}
}
if ( V_48 )
continue;
V_9 -> V_53 [ V_9 -> V_34 ] = 0 ;
V_9 -> V_37 [ V_9 -> V_34 ++ ] = V_36 ;
V_46 = true ;
}
if ( V_46 ) {
F_7 ( V_9 -> V_22 ) ;
V_16 = F_15 ( V_7 , 0 ) ;
F_8 ( V_9 -> V_22 ) ;
if ( V_16 )
goto V_21;
}
V_16 = V_12 ;
V_21:
F_18 ( V_31 ) ;
F_9 ( V_7 ) ;
return V_16 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_1 V_32 = 0 ;
int V_33 ;
if ( ! F_6 ( V_7 ) )
return - V_20 ;
for ( V_33 = 0 ; V_33 < V_9 -> V_34 ; V_33 ++ ) {
V_32 += snprintf ( V_5 + V_32 , V_10 - V_32 , L_2 ,
V_33 == 0 ? L_3 : L_4 , V_9 -> V_53 [ V_33 ] ) ;
}
V_32 += snprintf ( V_5 + V_32 , V_10 - V_32 , L_5 ) ;
F_9 ( V_7 ) ;
return V_32 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_44 = 0 , V_16 , V_39 ;
int V_45 ;
bool V_54 = false ;
T_3 V_53 [ V_43 ] ;
V_45 = strlen ( V_5 ) ;
if ( V_5 [ V_45 - 1 ] == '\n' )
V_45 = V_45 - 1 ;
if ( ! F_6 ( V_7 ) )
return - V_20 ;
if ( V_45 > 0 ) {
char * V_47 = ( char * ) V_5 ;
while ( V_47 < V_5 + V_45 ) {
int V_55 ;
if ( V_44 == V_9 -> V_34 ) {
V_16 = - V_19 ;
goto V_21;
}
V_55 = F_21 ( V_47 , & V_47 , 0 ) ;
if ( V_55 < 0 || V_55 > 3 ) {
V_16 = - V_19 ;
goto V_21;
}
if ( V_9 -> V_53 [ V_44 ] != V_55 )
V_54 = true ;
V_53 [ V_44 ++ ] = V_55 ;
V_47 ++ ;
}
}
if ( V_44 != V_9 -> V_34 ) {
V_16 = - V_19 ;
goto V_21;
}
if ( V_54 ) {
for ( V_39 = 0 ; V_39 < V_44 ; ++ V_39 )
V_9 -> V_53 [ V_39 ] = V_53 [ V_39 ] ;
F_7 ( V_9 -> V_22 ) ;
V_16 = F_15 ( V_7 , 0 ) ;
F_8 ( V_9 -> V_22 ) ;
if ( V_16 )
goto V_21;
}
V_16 = V_12 ;
V_21:
F_9 ( V_7 ) ;
return V_16 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_5 , V_10 , L_8 , V_9 -> V_22 -> V_23 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_30 * V_31 = V_9 -> V_31 ;
struct V_13 * V_14 ;
unsigned long V_23 ;
int V_16 ;
int V_39 ;
V_16 = F_29 ( V_5 , 0 , & V_23 ) ;
if ( V_16 )
return V_16 ;
V_23 = F_30 ( V_23 ) ;
if ( ! F_6 ( V_7 ) )
return - V_20 ;
V_14 = V_9 -> V_22 ;
F_31 ( & V_14 -> V_56 , V_14 -> V_50 ) ;
F_32 ( & V_14 -> V_57 ) ;
if ( F_33 ( & V_14 -> V_58 ) ) {
V_16 = - V_24 ;
goto V_21;
}
for ( V_39 = 0 ; V_39 < V_31 -> V_40 ; V_39 ++ ) {
struct V_8 * V_49 = F_3 ( V_31 -> V_41 [ V_39 ] ) ;
int V_59 ;
if ( V_49 -> V_22 != V_14 )
continue;
for ( V_59 = 0 ; V_59 < V_49 -> V_34 ; V_59 ++ ) {
if ( V_49 -> V_37 [ V_59 ] -> V_60 . V_61 ) {
V_16 = - V_24 ;
goto V_21;
}
}
}
if ( V_23 != V_9 -> V_22 -> V_23 ) {
V_16 = F_34 ( V_7 , V_23 , V_9 -> V_22 -> type ) ;
if ( V_16 ) {
F_22 ( V_2 , L_9 ) ;
goto V_21;
}
}
V_16 = V_12 ;
V_21:
F_35 ( & V_14 -> V_57 ) ;
F_36 ( & V_14 -> V_56 ) ;
F_9 ( V_7 ) ;
return V_16 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_5 , V_10 , L_10 , V_9 -> V_22 -> V_62 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_5 , V_10 , L_11 , V_9 -> V_22 -> V_63 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_64 V_65 ;
int V_16 ;
V_16 = F_40 ( V_7 , & V_65 ) ;
if ( V_16 )
return V_16 ;
return snprintf ( V_5 , V_10 , L_12 , ( unsigned ) V_65 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned V_65 ;
int V_16 ;
V_16 = F_42 ( V_5 , 0 , & V_65 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_43 ( V_7 , V_65 ) ;
if ( V_16 )
return V_16 ;
return V_12 ;
}
int F_44 ( struct V_30 * V_31 )
{
int V_39 ;
int V_16 ;
F_23 ( L_13 ) ;
for ( V_39 = 0 ; V_39 < V_31 -> V_40 ; V_39 ++ ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < F_45 ( V_66 ) ; V_33 ++ ) {
V_16 = F_46 ( V_31 -> V_41 [ V_39 ] -> V_2 ,
& V_66 [ V_33 ] ) ;
if ( V_16 ) {
F_22 ( V_31 -> V_2 , L_14
L_15 ) ;
return V_16 ;
}
}
}
return 0 ;
}
void F_47 ( struct V_30 * V_31 )
{
int V_39 , V_33 ;
F_23 ( L_16 ) ;
for ( V_39 = 0 ; V_39 < V_31 -> V_40 ; V_39 ++ ) {
for ( V_33 = 0 ; V_33 < F_45 ( V_66 ) ; V_33 ++ )
F_48 ( V_31 -> V_41 [ V_39 ] -> V_2 ,
& V_66 [ V_33 ] ) ;
}
}
