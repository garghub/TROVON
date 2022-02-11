int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 -> V_7 && ! V_4 -> V_8 ) {
F_2 ( V_2 -> V_9 ,
L_1 ) ;
return - V_10 ;
}
if ( ! V_4 -> V_11 && ! V_4 -> V_12 ) {
F_2 ( V_2 -> V_9 ,
L_2 ) ;
return - V_10 ;
}
return 0 ;
}
int F_3 ( struct V_13 const * V_14 , int V_15 )
{
if ( ! V_14 -> V_16 . V_17 . V_18 ) {
F_4 ( L_3 ,
V_14 -> V_19 , V_15 ) ;
return - V_10 ;
}
if ( ! V_14 -> V_16 . V_17 . V_20 ||
! V_14 -> V_16 . V_17 . V_17 ) {
F_4 ( L_4 ,
V_14 -> V_19 , V_15 ) ;
return - V_10 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned V_21 ,
unsigned long * V_22 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_7 ) {
F_2 ( V_2 -> V_9 , L_5
L_6 ) ;
return - V_10 ;
}
return V_4 -> V_7 ( V_2 , V_21 , V_22 ) ;
}
int V_7 ( const char * V_23 , const char * V_19 ,
unsigned long * V_22 )
{
struct V_1 * V_2 ;
int V_21 ;
V_2 = F_6 ( V_23 ) ;
if ( ! V_2 ) {
V_21 = - V_10 ;
return V_21 ;
}
F_7 ( & V_2 -> V_24 ) ;
V_21 = F_8 ( V_2 , V_19 ) ;
if ( V_21 < 0 )
goto V_25;
V_21 = F_5 ( V_2 , V_21 , V_22 ) ;
V_25:
F_9 ( & V_2 -> V_24 ) ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_21 ,
unsigned long V_22 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_26 ;
if ( ! V_4 || ! V_4 -> V_11 ) {
F_2 ( V_2 -> V_9 , L_7
L_8 ) ;
return - V_10 ;
}
V_26 = V_4 -> V_11 ( V_2 , V_21 , V_22 ) ;
if ( V_26 ) {
F_2 ( V_2 -> V_9 ,
L_9 , V_21 ) ;
return V_26 ;
}
return 0 ;
}
int V_11 ( const char * V_23 , const char * V_19 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
int V_21 , V_26 ;
V_2 = F_6 ( V_23 ) ;
if ( ! V_2 ) {
V_26 = - V_10 ;
return V_26 ;
}
F_7 ( & V_2 -> V_24 ) ;
V_21 = F_8 ( V_2 , V_19 ) ;
if ( V_21 < 0 ) {
V_26 = V_21 ;
goto V_25;
}
V_26 = F_10 ( V_2 , V_21 , V_22 ) ;
V_25:
F_9 ( & V_2 -> V_24 ) ;
return V_26 ;
}
int V_8 ( const char * V_23 , const char * V_27 ,
unsigned long * V_22 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
int V_28 , V_26 ;
V_2 = F_6 ( V_23 ) ;
if ( ! V_2 ) {
V_26 = - V_10 ;
return V_26 ;
}
F_7 ( & V_2 -> V_24 ) ;
V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_8 ) {
F_2 ( V_2 -> V_9 , L_10
L_11
L_12 ) ;
V_26 = - V_10 ;
goto V_25;
}
V_28 = F_11 ( V_2 , V_27 ) ;
if ( V_28 < 0 ) {
V_26 = V_28 ;
goto V_25;
}
V_26 = V_4 -> V_8 ( V_2 , V_28 , V_22 ) ;
V_25:
F_9 ( & V_2 -> V_24 ) ;
return V_26 ;
}
int V_12 ( const char * V_23 , const char * V_27 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
const struct V_29 * V_30 ;
int V_28 ;
const unsigned * V_31 ;
unsigned V_32 ;
int V_26 ;
int V_15 ;
V_2 = F_6 ( V_23 ) ;
if ( ! V_2 ) {
V_26 = - V_10 ;
return V_26 ;
}
F_7 ( & V_2 -> V_24 ) ;
V_4 = V_2 -> V_5 -> V_6 ;
V_30 = V_2 -> V_5 -> V_30 ;
if ( ! V_4 || ( ! V_4 -> V_12 && ! V_4 -> V_11 ) ) {
F_2 ( V_2 -> V_9 , L_13
L_8 ) ;
V_26 = - V_10 ;
goto V_25;
}
V_28 = F_11 ( V_2 , V_27 ) ;
if ( V_28 < 0 ) {
V_26 = V_28 ;
goto V_25;
}
V_26 = V_30 -> V_33 ( V_2 , V_28 , & V_31 , & V_32 ) ;
if ( V_26 ) {
F_2 ( V_2 -> V_9 , L_14
L_15 ) ;
goto V_25;
}
if ( V_4 -> V_12 ) {
V_26 = V_4 -> V_12 ( V_2 , V_28 , V_22 ) ;
if ( V_26 != - V_34 )
goto V_25;
}
if ( ! V_4 -> V_11 ) {
V_26 = 0 ;
goto V_25;
}
for ( V_15 = 0 ; V_15 < V_32 ; V_15 ++ ) {
V_26 = V_4 -> V_11 ( V_2 , V_31 [ V_15 ] , V_22 ) ;
if ( V_26 < 0 )
goto V_25;
}
V_26 = 0 ;
V_25:
F_9 ( & V_2 -> V_24 ) ;
return V_26 ;
}
int F_12 ( struct V_13 const * V_14 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
int V_21 ;
switch ( V_36 -> type ) {
case V_37 :
V_21 = F_8 ( V_2 ,
V_14 -> V_16 . V_17 . V_18 ) ;
if ( V_21 < 0 ) {
F_2 ( V_2 -> V_9 , L_16 ,
V_14 -> V_16 . V_17 . V_18 ) ;
return V_21 ;
}
V_36 -> V_16 . V_17 . V_18 = V_21 ;
break;
case V_38 :
V_21 = F_11 ( V_2 ,
V_14 -> V_16 . V_17 . V_18 ) ;
if ( V_21 < 0 ) {
F_2 ( V_2 -> V_9 , L_17 ,
V_14 -> V_16 . V_17 . V_18 ) ;
return V_21 ;
}
V_36 -> V_16 . V_17 . V_18 = V_21 ;
break;
default:
return - V_10 ;
}
V_36 -> V_16 . V_17 . V_20 = V_14 -> V_16 . V_17 . V_20 ;
V_36 -> V_16 . V_17 . V_17 = V_14 -> V_16 . V_17 . V_17 ;
return 0 ;
}
void F_13 ( struct V_35 const * V_36 )
{
}
int F_14 ( struct V_35 const * V_36 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_15 , V_26 ;
if ( ! V_4 ) {
F_2 ( V_2 -> V_9 , L_18 ) ;
return - V_10 ;
}
switch ( V_36 -> type ) {
case V_37 :
if ( ! V_4 -> V_11 ) {
F_2 ( V_2 -> V_9 , L_19 ) ;
return - V_10 ;
}
for ( V_15 = 0 ; V_15 < V_36 -> V_16 . V_17 . V_20 ; V_15 ++ ) {
V_26 = V_4 -> V_11 ( V_2 ,
V_36 -> V_16 . V_17 . V_18 ,
V_36 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
if ( V_26 < 0 ) {
F_2 ( V_2 -> V_9 ,
L_20 ,
V_36 -> V_16 . V_17 . V_18 ,
V_36 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
return V_26 ;
}
}
break;
case V_38 :
if ( ! V_4 -> V_12 ) {
F_2 ( V_2 -> V_9 ,
L_21 ) ;
return - V_10 ;
}
for ( V_15 = 0 ; V_15 < V_36 -> V_16 . V_17 . V_20 ; V_15 ++ ) {
V_26 = V_4 -> V_12 ( V_2 ,
V_36 -> V_16 . V_17 . V_18 ,
V_36 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
if ( V_26 < 0 ) {
F_2 ( V_2 -> V_9 ,
L_22 ,
V_36 -> V_16 . V_17 . V_18 ,
V_36 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
return V_26 ;
}
}
break;
default:
return - V_10 ;
}
return 0 ;
}
void F_15 ( struct V_39 * V_40 , struct V_13 const * V_14 )
{
struct V_1 * V_2 ;
const struct V_3 * V_6 ;
int V_15 ;
V_2 = F_6 ( V_14 -> V_41 ) ;
if ( V_2 )
V_6 = V_2 -> V_5 -> V_6 ;
else
V_6 = NULL ;
switch ( V_14 -> type ) {
case V_37 :
F_16 ( V_40 , L_23 ) ;
break;
case V_38 :
F_16 ( V_40 , L_24 ) ;
break;
default:
break;
}
F_16 ( V_40 , L_25 , V_14 -> V_16 . V_17 . V_18 ) ;
for ( V_15 = 0 ; V_15 < V_14 -> V_16 . V_17 . V_20 ; V_15 ++ ) {
F_16 ( V_40 , L_26 ) ;
if ( V_6 && V_6 -> V_42 )
V_6 -> V_42 ( V_2 , V_40 ,
V_14 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
else
F_16 ( V_40 , L_27 , V_14 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
F_16 ( V_40 , L_28 ) ;
}
}
void F_17 ( struct V_39 * V_40 ,
struct V_35 const * V_36 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
const struct V_29 * V_30 = V_2 -> V_5 -> V_30 ;
const struct V_3 * V_6 = V_2 -> V_5 -> V_6 ;
struct V_43 * V_5 ;
int V_15 ;
switch ( V_36 -> type ) {
case V_37 :
V_5 = F_18 ( V_36 -> V_2 ,
V_36 -> V_16 . V_17 . V_18 ) ;
F_16 ( V_40 , L_29 ,
V_5 -> V_19 ? V_5 -> V_19 : L_30 ,
V_36 -> V_16 . V_17 . V_18 ) ;
break;
case V_38 :
F_16 ( V_40 , L_31 ,
V_30 -> V_44 ( V_2 ,
V_36 -> V_16 . V_17 . V_18 ) ,
V_36 -> V_16 . V_17 . V_18 ) ;
break;
default:
break;
}
for ( V_15 = 0 ; V_15 < V_36 -> V_16 . V_17 . V_20 ; V_15 ++ ) {
F_16 ( V_40 , L_32 ) ;
if ( V_6 && V_6 -> V_42 )
V_6 -> V_42 ( V_2 , V_40 ,
V_36 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
else
F_16 ( V_40 , L_27 ,
V_36 -> V_16 . V_17 . V_17 [ V_15 ] ) ;
}
F_16 ( V_40 , L_28 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_39 * V_40 , int V_21 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_20 ( V_2 , V_40 , V_21 ) ;
if ( V_4 && V_4 -> V_45 )
V_4 -> V_45 ( V_2 , V_40 , V_21 ) ;
}
static int F_21 ( struct V_39 * V_40 , void * V_46 )
{
struct V_1 * V_2 = V_40 -> V_47 ;
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned V_15 , V_21 ;
if ( ! V_4 || ! V_4 -> V_7 )
return 0 ;
F_22 ( V_40 , L_33 ) ;
F_22 ( V_40 , L_34 ) ;
F_7 ( & V_2 -> V_24 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_5 -> V_48 ; V_15 ++ ) {
struct V_43 * V_5 ;
V_21 = V_2 -> V_5 -> V_31 [ V_15 ] . V_49 ;
V_5 = F_18 ( V_2 , V_21 ) ;
if ( V_5 == NULL )
continue;
F_16 ( V_40 , L_35 , V_21 ,
V_5 -> V_19 ? V_5 -> V_19 : L_30 ) ;
F_19 ( V_2 , V_40 , V_21 ) ;
F_16 ( V_40 , L_28 ) ;
}
F_9 ( & V_2 -> V_24 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_39 * V_40 , unsigned V_28 ,
const char * V_50 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_24 ( V_2 , V_40 , V_50 ) ;
if ( V_4 && V_4 -> V_51 )
V_4 -> V_51 ( V_2 , V_40 , V_28 ) ;
}
static int F_25 ( struct V_39 * V_40 , void * V_46 )
{
struct V_1 * V_2 = V_40 -> V_47 ;
const struct V_29 * V_30 = V_2 -> V_5 -> V_30 ;
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned V_52 = V_30 -> V_53 ( V_2 ) ;
unsigned V_28 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 )
return 0 ;
F_22 ( V_40 , L_36 ) ;
F_22 ( V_40 , L_37 ) ;
while ( V_28 < V_52 ) {
const char * V_50 = V_30 -> V_44 ( V_2 , V_28 ) ;
F_16 ( V_40 , L_38 , V_28 , V_50 ) ;
F_23 ( V_2 , V_40 , V_28 , V_50 ) ;
F_16 ( V_40 , L_28 ) ;
V_28 ++ ;
}
return 0 ;
}
static int F_26 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_27 ( V_55 , F_21 , V_54 -> V_56 ) ;
}
static int F_28 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_27 ( V_55 , F_25 , V_54 -> V_56 ) ;
}
static int F_29 ( struct V_39 * V_40 , void * V_57 )
{
struct V_58 * V_59 ;
const struct V_13 * V_14 ;
struct V_1 * V_2 = NULL ;
const struct V_3 * V_6 = NULL ;
const struct V_60 * V_17 ;
struct V_61 * V_62 = & V_63 ;
int V_15 , V_64 ;
bool V_65 = false ;
unsigned long V_22 ;
F_7 ( & V_66 ) ;
F_30 (maps_node, i, map) {
if ( V_14 -> type != V_62 -> V_67 )
continue;
if ( strcmp ( V_14 -> V_23 , V_62 -> V_23 ) )
continue;
if ( strcmp ( V_14 -> V_19 , V_62 -> V_68 ) )
continue;
for ( V_64 = 0 ; V_64 < V_14 -> V_16 . V_17 . V_20 ; V_64 ++ ) {
if ( ! strcmp ( V_14 -> V_16 . V_17 . V_18 ,
V_62 -> V_69 ) ) {
V_17 = & V_14 -> V_16 . V_17 ;
V_2 = F_6
( V_14 -> V_41 ) ;
V_65 = true ;
break;
}
}
}
if ( ! V_65 ) {
F_16 ( V_40 , L_39 ) ;
F_16 ( V_40 , L_40 , V_62 -> V_23 ) ;
F_16 ( V_40 , L_41 , V_62 -> V_68 ) ;
F_16 ( V_40 , L_42 , V_62 -> V_69 ) ;
F_16 ( V_40 , L_43\
L_44 ) ;
goto exit;
}
V_22 = * ( V_17 -> V_17 ) ;
F_16 ( V_40 , L_45 ,
V_62 -> V_23 , V_62 -> V_69 ,
V_62 -> V_68 , V_22 ) ;
if ( V_2 )
V_6 = V_2 -> V_5 -> V_6 ;
if ( V_6 && V_6 -> V_42 )
V_6 -> V_42 ( V_2 , V_40 , V_22 ) ;
exit:
F_9 ( & V_66 ) ;
return 0 ;
}
static int F_31 ( struct V_55 * V_55 ,
const char T_1 * V_70 , T_2 V_71 , T_3 * V_72 )
{
struct V_58 * V_59 ;
const struct V_13 * V_14 ;
struct V_1 * V_2 = NULL ;
const struct V_3 * V_6 = NULL ;
struct V_61 * V_62 = & V_63 ;
const struct V_60 * V_17 ;
char V_22 [ V_73 + 1 ] ;
bool V_65 = false ;
char V_74 [ 128 ] ;
char * V_75 = & V_74 [ 0 ] ;
int V_76 ;
char * V_77 ;
int V_15 ;
V_76 = F_32 ( V_71 , ( sizeof( V_74 ) - 1 ) ) ;
if ( F_33 ( V_74 , V_70 , V_76 ) )
return - V_78 ;
V_74 [ V_76 ] = 0 ;
V_77 = F_34 ( & V_75 , L_32 ) ;
if ( ! V_77 )
return - V_10 ;
if ( strcmp ( V_77 , L_46 ) )
return - V_10 ;
V_77 = F_34 ( & V_75 , L_32 ) ;
if ( ! V_77 )
return - V_10 ;
if ( strcmp ( V_77 , L_47 ) )
return - V_10 ;
V_62 -> V_67 = V_37 ;
V_77 = F_34 ( & V_75 , L_32 ) ;
if ( V_77 == NULL )
return - V_10 ;
if ( strlen ( V_77 ) >= V_73 )
return - V_10 ;
strncpy ( V_62 -> V_23 , V_77 , V_73 ) ;
V_77 = F_34 ( & V_75 , L_32 ) ;
if ( V_77 == NULL )
return - V_10 ;
if ( strlen ( V_77 ) >= V_73 )
return - V_10 ;
strncpy ( V_62 -> V_68 , V_77 , V_73 ) ;
V_77 = F_34 ( & V_75 , L_32 ) ;
if ( V_77 == NULL )
return - V_10 ;
if ( strlen ( V_77 ) >= V_73 )
return - V_10 ;
strncpy ( V_62 -> V_69 , V_77 , V_73 ) ;
V_77 = F_34 ( & V_75 , L_32 ) ;
if ( V_77 == NULL )
return - V_10 ;
if ( strlen ( V_77 ) >= V_73 )
return - V_10 ;
strncpy ( V_22 , V_77 , V_73 ) ;
F_7 ( & V_66 ) ;
F_30 (maps_node, i, map) {
if ( strcmp ( V_14 -> V_23 , V_62 -> V_23 ) )
continue;
if ( V_14 -> type != V_62 -> V_67 )
continue;
if ( strcmp ( V_14 -> V_19 , V_62 -> V_68 ) )
continue;
if ( ! strcmp ( V_14 -> V_16 . V_17 . V_18 , V_62 -> V_69 ) ) {
V_65 = true ;
V_2 = F_6 (
V_14 -> V_41 ) ;
V_17 = & V_14 -> V_16 . V_17 ;
break;
}
}
if ( ! V_65 ) {
V_71 = - V_10 ;
goto exit;
}
if ( V_2 )
V_6 = V_2 -> V_5 -> V_6 ;
if ( V_6 && V_6 -> V_79 ) {
for ( V_15 = 0 ; V_15 < V_17 -> V_20 ; V_15 ++ ) {
V_6 -> V_79 ( V_2 ,
V_22 ,
& V_17 -> V_17 [ V_15 ] ) ;
}
}
exit:
F_9 ( & V_66 ) ;
return V_71 ;
}
static int F_35 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_27 ( V_55 , F_29 , V_54 -> V_56 ) ;
}
void F_36 ( struct V_80 * V_81 ,
struct V_1 * V_2 )
{
F_37 ( L_48 , V_82 | V_83 ,
V_81 , V_2 , & V_84 ) ;
F_37 ( L_49 , V_82 | V_83 ,
V_81 , V_2 , & V_85 ) ;
F_37 ( L_50 , ( V_83 | V_86 | V_87 ) ,
V_81 , V_2 , & V_88 ) ;
}
