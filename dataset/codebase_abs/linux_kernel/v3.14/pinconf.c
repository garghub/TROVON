int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 -> V_7 && ! V_4 -> V_8 ) {
F_2 ( V_2 -> V_9 ,
L_1 ) ;
return - V_10 ;
}
return 0 ;
}
int F_3 ( struct V_11 const * V_12 , int V_13 )
{
if ( ! V_12 -> V_14 . V_15 . V_16 ) {
F_4 ( L_2 ,
V_12 -> V_17 , V_13 ) ;
return - V_10 ;
}
if ( ! V_12 -> V_14 . V_15 . V_18 ||
! V_12 -> V_14 . V_15 . V_15 ) {
F_4 ( L_3 ,
V_12 -> V_17 , V_13 ) ;
return - V_10 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned V_19 ,
unsigned long * V_20 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_21 ) {
F_6 ( V_2 -> V_9 , L_4
L_5 ) ;
return - V_22 ;
}
return V_4 -> V_21 ( V_2 , V_19 , V_20 ) ;
}
int F_7 ( const char * V_23 , const char * V_24 ,
unsigned long * V_20 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
int V_25 , V_26 ;
V_2 = F_8 ( V_23 ) ;
if ( ! V_2 ) {
V_26 = - V_10 ;
return V_26 ;
}
F_9 ( & V_2 -> V_27 ) ;
V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 || ! V_4 -> F_7 ) {
F_6 ( V_2 -> V_9 , L_6
L_7
L_8 ) ;
V_26 = - V_22 ;
goto V_28;
}
V_25 = F_10 ( V_2 , V_24 ) ;
if ( V_25 < 0 ) {
V_26 = V_25 ;
goto V_28;
}
V_26 = V_4 -> F_7 ( V_2 , V_25 , V_20 ) ;
V_28:
F_11 ( & V_2 -> V_27 ) ;
return V_26 ;
}
int F_12 ( struct V_11 const * V_12 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_19 ;
switch ( V_30 -> type ) {
case V_31 :
V_19 = F_13 ( V_2 ,
V_12 -> V_14 . V_15 . V_16 ) ;
if ( V_19 < 0 ) {
F_2 ( V_2 -> V_9 , L_9 ,
V_12 -> V_14 . V_15 . V_16 ) ;
return V_19 ;
}
V_30 -> V_14 . V_15 . V_16 = V_19 ;
break;
case V_32 :
V_19 = F_10 ( V_2 ,
V_12 -> V_14 . V_15 . V_16 ) ;
if ( V_19 < 0 ) {
F_2 ( V_2 -> V_9 , L_10 ,
V_12 -> V_14 . V_15 . V_16 ) ;
return V_19 ;
}
V_30 -> V_14 . V_15 . V_16 = V_19 ;
break;
default:
return - V_10 ;
}
V_30 -> V_14 . V_15 . V_18 = V_12 -> V_14 . V_15 . V_18 ;
V_30 -> V_14 . V_15 . V_15 = V_12 -> V_14 . V_15 . V_15 ;
return 0 ;
}
void F_14 ( struct V_29 const * V_30 )
{
}
int F_15 ( struct V_29 const * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_26 ;
if ( ! V_4 ) {
F_2 ( V_2 -> V_9 , L_11 ) ;
return - V_10 ;
}
switch ( V_30 -> type ) {
case V_31 :
if ( ! V_4 -> V_7 ) {
F_2 ( V_2 -> V_9 , L_12 ) ;
return - V_10 ;
}
V_26 = V_4 -> V_7 ( V_2 ,
V_30 -> V_14 . V_15 . V_16 ,
V_30 -> V_14 . V_15 . V_15 ,
V_30 -> V_14 . V_15 . V_18 ) ;
if ( V_26 < 0 ) {
F_2 ( V_2 -> V_9 ,
L_13 ,
V_30 -> V_14 . V_15 . V_16 ) ;
return V_26 ;
}
break;
case V_32 :
if ( ! V_4 -> V_8 ) {
F_2 ( V_2 -> V_9 ,
L_14 ) ;
return - V_10 ;
}
V_26 = V_4 -> V_8 ( V_2 ,
V_30 -> V_14 . V_15 . V_16 ,
V_30 -> V_14 . V_15 . V_15 ,
V_30 -> V_14 . V_15 . V_18 ) ;
if ( V_26 < 0 ) {
F_2 ( V_2 -> V_9 ,
L_15 ,
V_30 -> V_14 . V_15 . V_16 ) ;
return V_26 ;
}
break;
default:
return - V_10 ;
}
return 0 ;
}
void F_16 ( struct V_33 * V_34 , struct V_11 const * V_12 )
{
struct V_1 * V_2 ;
const struct V_3 * V_6 ;
int V_13 ;
V_2 = F_8 ( V_12 -> V_35 ) ;
if ( V_2 )
V_6 = V_2 -> V_5 -> V_6 ;
else
V_6 = NULL ;
switch ( V_12 -> type ) {
case V_31 :
F_17 ( V_34 , L_16 ) ;
break;
case V_32 :
F_17 ( V_34 , L_17 ) ;
break;
default:
break;
}
F_17 ( V_34 , L_18 , V_12 -> V_14 . V_15 . V_16 ) ;
for ( V_13 = 0 ; V_13 < V_12 -> V_14 . V_15 . V_18 ; V_13 ++ ) {
F_17 ( V_34 , L_19 ) ;
if ( V_6 && V_6 -> V_36 )
V_6 -> V_36 ( V_2 , V_34 ,
V_12 -> V_14 . V_15 . V_15 [ V_13 ] ) ;
else
F_17 ( V_34 , L_20 , V_12 -> V_14 . V_15 . V_15 [ V_13 ] ) ;
F_17 ( V_34 , L_21 ) ;
}
}
void F_18 ( struct V_33 * V_34 ,
struct V_29 const * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
const struct V_37 * V_38 = V_2 -> V_5 -> V_38 ;
const struct V_3 * V_6 = V_2 -> V_5 -> V_6 ;
struct V_39 * V_5 ;
int V_13 ;
switch ( V_30 -> type ) {
case V_31 :
V_5 = F_19 ( V_30 -> V_2 ,
V_30 -> V_14 . V_15 . V_16 ) ;
F_17 ( V_34 , L_22 ,
V_5 -> V_17 ? V_5 -> V_17 : L_23 ,
V_30 -> V_14 . V_15 . V_16 ) ;
break;
case V_32 :
F_17 ( V_34 , L_24 ,
V_38 -> V_40 ( V_2 ,
V_30 -> V_14 . V_15 . V_16 ) ,
V_30 -> V_14 . V_15 . V_16 ) ;
break;
default:
break;
}
for ( V_13 = 0 ; V_13 < V_30 -> V_14 . V_15 . V_18 ; V_13 ++ ) {
F_17 ( V_34 , L_25 ) ;
if ( V_6 && V_6 -> V_36 )
V_6 -> V_36 ( V_2 , V_34 ,
V_30 -> V_14 . V_15 . V_15 [ V_13 ] ) ;
else
F_17 ( V_34 , L_20 ,
V_30 -> V_14 . V_15 . V_15 [ V_13 ] ) ;
}
F_17 ( V_34 , L_21 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_33 * V_34 , int V_19 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_21 ( V_2 , V_34 , V_19 ) ;
if ( V_4 && V_4 -> V_41 )
V_4 -> V_41 ( V_2 , V_34 , V_19 ) ;
}
static int F_22 ( struct V_33 * V_34 , void * V_42 )
{
struct V_1 * V_2 = V_34 -> V_43 ;
unsigned V_13 , V_19 ;
F_23 ( V_34 , L_26 ) ;
F_23 ( V_34 , L_27 ) ;
F_9 ( & V_2 -> V_27 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_5 -> V_44 ; V_13 ++ ) {
struct V_39 * V_5 ;
V_19 = V_2 -> V_5 -> V_45 [ V_13 ] . V_46 ;
V_5 = F_19 ( V_2 , V_19 ) ;
if ( V_5 == NULL )
continue;
F_17 ( V_34 , L_28 , V_19 ,
V_5 -> V_17 ? V_5 -> V_17 : L_23 ) ;
F_20 ( V_2 , V_34 , V_19 ) ;
F_17 ( V_34 , L_21 ) ;
}
F_11 ( & V_2 -> V_27 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_33 * V_34 , unsigned V_25 ,
const char * V_47 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_25 ( V_2 , V_34 , V_47 ) ;
if ( V_4 && V_4 -> V_48 )
V_4 -> V_48 ( V_2 , V_34 , V_25 ) ;
}
static int F_26 ( struct V_33 * V_34 , void * V_42 )
{
struct V_1 * V_2 = V_34 -> V_43 ;
const struct V_37 * V_38 = V_2 -> V_5 -> V_38 ;
unsigned V_49 = V_38 -> V_50 ( V_2 ) ;
unsigned V_25 = 0 ;
F_23 ( V_34 , L_29 ) ;
F_23 ( V_34 , L_30 ) ;
while ( V_25 < V_49 ) {
const char * V_47 = V_38 -> V_40 ( V_2 , V_25 ) ;
F_17 ( V_34 , L_31 , V_25 , V_47 ) ;
F_24 ( V_2 , V_34 , V_25 , V_47 ) ;
F_17 ( V_34 , L_21 ) ;
V_25 ++ ;
}
return 0 ;
}
static int F_27 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_28 ( V_52 , F_22 , V_51 -> V_53 ) ;
}
static int F_29 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_28 ( V_52 , F_26 , V_51 -> V_53 ) ;
}
static int F_30 ( struct V_33 * V_34 , void * V_54 )
{
struct V_55 * V_56 ;
const struct V_11 * V_12 ;
const struct V_11 * V_57 = NULL ;
struct V_1 * V_2 ;
const struct V_3 * V_6 = NULL ;
struct V_58 * V_59 = & V_60 ;
int V_13 , V_61 ;
unsigned long V_20 ;
F_9 ( & V_62 ) ;
F_31 (maps_node, i, map) {
if ( V_12 -> type != V_59 -> V_63 )
continue;
if ( strcmp ( V_12 -> V_23 , V_59 -> V_23 ) )
continue;
if ( strcmp ( V_12 -> V_17 , V_59 -> V_64 ) )
continue;
for ( V_61 = 0 ; V_61 < V_12 -> V_14 . V_15 . V_18 ; V_61 ++ ) {
if ( ! strcmp ( V_12 -> V_14 . V_15 . V_16 ,
V_59 -> V_65 ) ) {
V_57 = V_12 ;
break;
}
}
}
if ( ! V_57 ) {
F_17 ( V_34 , L_32 ) ;
F_17 ( V_34 , L_33 , V_59 -> V_23 ) ;
F_17 ( V_34 , L_34 , V_59 -> V_64 ) ;
F_17 ( V_34 , L_35 , V_59 -> V_65 ) ;
F_17 ( V_34 , L_36\
L_37 ) ;
goto exit;
}
V_2 = F_8 ( V_57 -> V_35 ) ;
V_20 = * V_57 -> V_14 . V_15 . V_15 ;
F_17 ( V_34 , L_38 ,
V_59 -> V_23 , V_59 -> V_65 ,
V_59 -> V_64 , V_20 ) ;
if ( V_2 )
V_6 = V_2 -> V_5 -> V_6 ;
if ( V_6 && V_6 -> V_36 )
V_6 -> V_36 ( V_2 , V_34 , V_20 ) ;
exit:
F_11 ( & V_62 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_52 * V_52 ,
const char T_2 * V_66 , T_3 V_67 , T_4 * V_68 )
{
struct V_55 * V_56 ;
const struct V_11 * V_12 ;
const struct V_11 * V_57 = NULL ;
struct V_1 * V_2 ;
const struct V_3 * V_6 = NULL ;
struct V_58 * V_59 = & V_60 ;
const struct V_69 * V_15 ;
char V_20 [ V_70 + 1 ] ;
char V_71 [ 128 ] ;
char * V_72 = & V_71 [ 0 ] ;
int V_73 ;
char * V_74 ;
int V_13 ;
V_73 = F_33 ( V_67 , sizeof( V_71 ) - 1 ) ;
if ( F_34 ( V_71 , V_66 , V_73 ) )
return - V_75 ;
V_71 [ V_73 ] = 0 ;
V_74 = F_35 ( & V_72 , L_25 ) ;
if ( ! V_74 )
return - V_10 ;
if ( strcmp ( V_74 , L_39 ) )
return - V_10 ;
V_74 = F_35 ( & V_72 , L_25 ) ;
if ( ! V_74 )
return - V_10 ;
if ( strcmp ( V_74 , L_40 ) )
return - V_10 ;
V_59 -> V_63 = V_31 ;
V_74 = F_35 ( & V_72 , L_25 ) ;
if ( V_74 == NULL )
return - V_10 ;
if ( strlen ( V_74 ) >= V_70 )
return - V_10 ;
strncpy ( V_59 -> V_23 , V_74 , V_70 ) ;
V_74 = F_35 ( & V_72 , L_25 ) ;
if ( V_74 == NULL )
return - V_10 ;
if ( strlen ( V_74 ) >= V_70 )
return - V_10 ;
strncpy ( V_59 -> V_64 , V_74 , V_70 ) ;
V_74 = F_35 ( & V_72 , L_25 ) ;
if ( V_74 == NULL )
return - V_10 ;
if ( strlen ( V_74 ) >= V_70 )
return - V_10 ;
strncpy ( V_59 -> V_65 , V_74 , V_70 ) ;
V_74 = F_35 ( & V_72 , L_25 ) ;
if ( V_74 == NULL )
return - V_10 ;
if ( strlen ( V_74 ) >= V_70 )
return - V_10 ;
strncpy ( V_20 , V_74 , V_70 ) ;
F_9 ( & V_62 ) ;
F_31 (maps_node, i, map) {
if ( strcmp ( V_12 -> V_23 , V_59 -> V_23 ) )
continue;
if ( V_12 -> type != V_59 -> V_63 )
continue;
if ( strcmp ( V_12 -> V_17 , V_59 -> V_64 ) )
continue;
if ( ! strcmp ( V_12 -> V_14 . V_15 . V_16 , V_59 -> V_65 ) ) {
V_57 = V_12 ;
break;
}
}
if ( ! V_57 ) {
V_67 = - V_10 ;
goto exit;
}
V_2 = F_8 ( V_57 -> V_35 ) ;
if ( V_2 )
V_6 = V_2 -> V_5 -> V_6 ;
if ( V_6 && V_6 -> V_76 ) {
V_15 = & V_57 -> V_14 . V_15 ;
for ( V_13 = 0 ; V_13 < V_15 -> V_18 ; V_13 ++ ) {
V_6 -> V_76 ( V_2 ,
V_20 ,
& V_15 -> V_15 [ V_13 ] ) ;
}
}
exit:
F_11 ( & V_62 ) ;
return V_67 ;
}
static int F_36 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_28 ( V_52 , F_30 , V_51 -> V_53 ) ;
}
void F_37 ( struct V_77 * V_78 ,
struct V_1 * V_2 )
{
F_38 ( L_41 , V_79 | V_80 ,
V_78 , V_2 , & V_81 ) ;
F_38 ( L_42 , V_79 | V_80 ,
V_78 , V_2 , & V_82 ) ;
F_38 ( L_43 , ( V_80 | V_83 | V_84 ) ,
V_78 , V_2 , & V_85 ) ;
}
