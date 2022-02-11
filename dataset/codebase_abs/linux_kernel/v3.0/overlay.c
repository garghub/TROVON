static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_6 ? V_2 -> V_6 -> V_5 : L_2 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_7 )
{
int V_8 , V_9 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_12 ;
int V_13 = V_7 ;
if ( V_3 [ V_7 - 1 ] == '\n' )
-- V_13 ;
if ( V_13 > 0 ) {
for ( V_8 = 0 ; V_8 < F_4 () ; ++ V_8 ) {
V_11 = F_5 ( V_8 ) ;
if ( F_6 ( V_3 , V_11 -> V_5 ) )
break;
V_11 = NULL ;
}
}
if ( V_13 > 0 && V_11 == NULL )
return - V_14 ;
if ( V_11 )
F_7 ( L_3 , V_11 -> V_5 ) ;
if ( V_11 == V_2 -> V_6 )
return V_7 ;
V_12 = V_2 -> V_6 ;
if ( V_12 ) {
V_9 = V_2 -> V_15 ( V_2 ) ;
if ( V_9 ) {
F_8 ( L_4 ) ;
return V_9 ;
}
V_9 = V_12 -> V_16 ( V_12 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_11 ) {
V_9 = V_2 -> V_17 ( V_2 , V_11 ) ;
if ( V_9 ) {
F_8 ( L_5 ) ;
return V_9 ;
}
V_9 = V_11 -> V_16 ( V_11 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_9 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_6 ,
V_2 -> V_18 . V_19 , V_2 -> V_18 . V_20 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 , V_2 -> V_18 . V_21 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_6 ,
V_2 -> V_18 . V_22 , V_2 -> V_18 . V_23 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_24 ;
struct V_25 V_18 ;
V_2 -> V_26 ( V_2 , & V_18 ) ;
V_18 . V_22 = F_13 ( V_3 , & V_24 , 10 ) ;
++ V_24 ;
if ( V_24 - V_3 >= V_7 )
return - V_14 ;
V_18 . V_23 = F_13 ( V_24 , & V_24 , 10 ) ;
V_9 = V_2 -> V_27 ( V_2 , & V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_16 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_14 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_6 ,
V_2 -> V_18 . V_28 , V_2 -> V_18 . V_29 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_24 ;
struct V_25 V_18 ;
V_2 -> V_26 ( V_2 , & V_18 ) ;
V_18 . V_28 = F_13 ( V_3 , & V_24 , 10 ) ;
++ V_24 ;
if ( V_24 - V_3 >= V_7 )
return - V_14 ;
V_18 . V_29 = F_13 ( V_24 , & V_24 , 10 ) ;
V_9 = V_2 -> V_27 ( V_2 , & V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_16 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_16 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 , V_2 -> V_18 . V_30 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_7 )
{
int V_9 , V_31 ;
struct V_25 V_18 ;
V_2 -> V_26 ( V_2 , & V_18 ) ;
V_9 = F_18 ( V_3 , 0 , & V_31 ) ;
if ( V_9 )
return V_9 ;
V_18 . V_30 = ! ! V_31 ;
V_9 = V_2 -> V_27 ( V_2 , & V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_16 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_19 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 ,
V_2 -> V_18 . V_32 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_33 ;
struct V_25 V_18 ;
V_9 = F_21 ( V_3 , 0 , & V_33 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_26 ( V_2 , & V_18 ) ;
if ( ! F_22 ( V_34 ) &&
V_2 -> V_35 == V_36 )
V_18 . V_32 = 255 ;
else
V_18 . V_32 = V_33 ;
V_9 = V_2 -> V_27 ( V_2 , & V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_16 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 ,
V_2 -> V_18 . V_37 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_33 ;
struct V_25 V_18 ;
V_9 = F_21 ( V_3 , 0 , & V_33 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_26 ( V_2 , & V_18 ) ;
if ( ! F_22 ( V_34 ) &&
V_2 -> V_35 == V_36 )
V_18 . V_37 = 0 ;
else
V_18 . V_37 = V_33 ;
V_9 = V_2 -> V_27 ( V_2 , & V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_16 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_25 ( struct V_38 * V_39 , struct V_40 * V_41 ,
char * V_3 )
{
struct V_1 * V_42 ;
struct V_43 * V_44 ;
V_42 = F_26 ( V_39 , struct V_1 , V_39 ) ;
V_44 = F_26 ( V_41 , struct V_43 , V_41 ) ;
if ( ! V_44 -> V_45 )
return - V_46 ;
return V_44 -> V_45 ( V_42 , V_3 ) ;
}
static T_1 F_27 ( struct V_38 * V_39 , struct V_40 * V_41 ,
const char * V_3 , T_2 V_7 )
{
struct V_1 * V_42 ;
struct V_43 * V_44 ;
V_42 = F_26 ( V_39 , struct V_1 , V_39 ) ;
V_44 = F_26 ( V_41 , struct V_43 , V_41 ) ;
if ( ! V_44 -> V_47 )
return - V_46 ;
return V_44 -> V_47 ( V_42 , V_3 , V_7 ) ;
}
int F_28 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_25 * V_18 ;
T_4 V_50 , V_51 ;
T_4 V_52 , V_53 ;
if ( ! V_49 )
return 0 ;
if ( ! V_2 -> V_18 . V_30 )
return 0 ;
V_18 = & V_2 -> V_18 ;
if ( V_18 -> V_54 == 0 ) {
F_7 ( L_8 ) ;
return - V_14 ;
}
V_49 -> V_55 -> V_56 ( V_49 , & V_52 , & V_53 ) ;
F_7 ( L_9 ,
V_2 -> V_35 ,
V_18 -> V_22 , V_18 -> V_23 ,
V_18 -> V_19 , V_18 -> V_20 ,
V_18 -> V_28 , V_18 -> V_29 ,
V_52 , V_53 ) ;
if ( ( V_2 -> V_57 & V_58 ) == 0 ) {
V_50 = V_18 -> V_19 ;
V_51 = V_18 -> V_20 ;
} else {
if ( V_18 -> V_28 == 0 )
V_50 = V_18 -> V_19 ;
else
V_50 = V_18 -> V_28 ;
if ( V_18 -> V_29 == 0 )
V_51 = V_18 -> V_20 ;
else
V_51 = V_18 -> V_29 ;
}
if ( V_52 < V_18 -> V_22 + V_50 ) {
F_7 ( L_10 ,
V_52 , V_18 -> V_22 , V_50 ) ;
return - V_14 ;
}
if ( V_53 < V_18 -> V_23 + V_51 ) {
F_7 ( L_11 ,
V_53 , V_18 -> V_23 , V_51 ) ;
return - V_14 ;
}
if ( ( V_2 -> V_59 & V_18 -> V_60 ) == 0 ) {
F_8 ( L_12 , V_18 -> V_60 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_25 * V_18 )
{
int V_9 ;
struct V_25 V_61 ;
V_61 = V_2 -> V_18 ;
V_2 -> V_18 = * V_18 ;
if ( V_2 -> V_6 ) {
V_9 = F_28 ( V_2 , V_2 -> V_6 -> V_62 ) ;
if ( V_9 ) {
V_2 -> V_18 = V_61 ;
return V_9 ;
}
}
V_2 -> V_63 = true ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_25 * V_18 )
{
* V_18 = V_2 -> V_18 ;
}
static int F_31 ( struct V_1 * V_2 )
{
return F_32 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_14 ;
if ( V_2 -> V_6 ) {
F_8 ( L_13 ,
V_2 -> V_5 , V_2 -> V_6 -> V_5 ) ;
return - V_14 ;
}
if ( V_2 -> V_18 . V_30 ) {
F_8 ( L_14 ) ;
return - V_14 ;
}
V_2 -> V_6 = V_11 ;
F_34 ( V_64 | V_65 ) ;
F_35 ( V_2 -> V_35 , V_11 -> V_35 ) ;
F_36 ( V_64 | V_65 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_9 ;
if ( ! V_2 -> V_6 ) {
F_8 ( L_15 ) ;
return - V_14 ;
}
if ( V_2 -> V_18 . V_30 ) {
F_8 ( L_16 ) ;
return - V_14 ;
}
V_9 = V_2 -> V_66 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_6 = NULL ;
return 0 ;
}
int F_38 ( void )
{
return V_67 ;
}
struct V_1 * F_39 ( int V_68 )
{
int V_8 = 0 ;
struct V_1 * V_2 ;
F_40 (ovl, &overlay_list, list) {
if ( V_8 ++ == V_68 )
return V_2 ;
}
return NULL ;
}
static void F_41 ( struct V_1 * V_42 )
{
++ V_67 ;
F_42 ( & V_42 -> V_69 , & V_70 ) ;
}
void F_43 ( struct V_10 * V_11 )
{
V_11 -> V_67 = F_44 () ;
V_11 -> V_71 = V_72 ;
}
void F_45 ( struct V_10 * V_11 )
{
V_11 -> V_67 = 1 ;
V_11 -> V_71 = V_73 ;
}
void F_46 ( struct V_74 * V_75 )
{
int V_8 , V_9 ;
F_47 ( & V_70 ) ;
V_67 = 0 ;
for ( V_8 = 0 ; V_8 < F_44 () ; ++ V_8 ) {
struct V_1 * V_2 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_76 ) ;
F_49 ( V_2 == NULL ) ;
switch ( V_8 ) {
case 0 :
V_2 -> V_5 = L_17 ;
V_2 -> V_35 = V_77 ;
V_2 -> V_57 = V_78 ;
V_2 -> V_18 . V_32 = 255 ;
break;
case 1 :
V_2 -> V_5 = L_18 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_57 = V_58 |
V_78 ;
V_2 -> V_18 . V_32 = 255 ;
break;
case 2 :
V_2 -> V_5 = L_19 ;
V_2 -> V_35 = V_79 ;
V_2 -> V_57 = V_58 |
V_78 ;
V_2 -> V_18 . V_32 = 255 ;
break;
}
V_2 -> V_17 = & F_33 ;
V_2 -> V_15 = & F_37 ;
V_2 -> V_27 = & F_29 ;
V_2 -> V_26 = & F_30 ;
V_2 -> V_66 = & F_31 ;
V_2 -> V_59 =
F_50 ( V_2 -> V_35 ) ;
F_41 ( V_2 ) ;
V_9 = F_51 ( & V_2 -> V_39 , & V_80 ,
& V_75 -> V_81 . V_39 , L_20 , V_8 ) ;
if ( V_9 ) {
F_8 ( L_21 ) ;
continue;
}
V_72 [ V_8 ] = V_2 ;
}
#ifdef F_52
{
struct V_1 * V_2 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_76 ) ;
F_49 ( V_2 == NULL ) ;
V_2 -> V_5 = L_22 ;
V_2 -> V_59 = V_82 ;
V_2 -> V_17 = & F_33 ;
V_2 -> V_15 = & F_37 ;
V_2 -> V_27 = & F_29 ;
V_2 -> V_26 = & F_30 ;
F_41 ( V_2 ) ;
V_9 = F_51 ( & V_2 -> V_39 , & V_80 ,
& V_75 -> V_81 . V_39 , L_23 ) ;
if ( V_9 )
F_8 ( L_21 ) ;
V_73 [ 0 ] = V_2 ;
}
#endif
}
void F_53 ( struct V_48 * V_49 , bool V_83 )
{
int V_8 ;
struct V_10 * V_84 ;
struct V_10 * V_85 ;
struct V_10 * V_86 = NULL ;
struct V_10 * V_11 = NULL ;
V_84 = F_5 ( V_87 ) ;
V_85 = F_5 ( V_88 ) ;
if ( F_22 ( V_89 ) )
V_86 = F_5 ( V_90 ) ;
if ( V_49 -> V_91 == V_92 ) {
if ( ! V_86 -> V_62 || V_83 ) {
if ( V_86 -> V_62 )
V_86 -> V_93 ( V_86 ) ;
V_86 -> V_94 ( V_86 , V_49 ) ;
V_11 = V_86 ;
}
} else if ( V_49 -> type != V_95
&& V_49 -> type != V_96 ) {
if ( ! V_84 -> V_62 || V_83 ) {
if ( V_84 -> V_62 )
V_84 -> V_93 ( V_84 ) ;
V_84 -> V_94 ( V_84 , V_49 ) ;
V_11 = V_84 ;
}
}
if ( V_49 -> type == V_95
|| V_49 -> type == V_96 ) {
if ( ! V_85 -> V_62 || V_83 ) {
if ( V_85 -> V_62 )
V_85 -> V_93 ( V_85 ) ;
V_85 -> V_94 ( V_85 , V_49 ) ;
V_11 = V_85 ;
}
}
if ( V_11 ) {
for ( V_8 = 0 ; V_8 < F_44 () ; V_8 ++ ) {
struct V_1 * V_2 ;
V_2 = F_39 ( V_8 ) ;
if ( ! V_2 -> V_6 || V_83 ) {
if ( V_2 -> V_6 )
F_37 ( V_2 ) ;
F_33 ( V_2 , V_11 ) ;
}
}
}
}
void F_54 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
while ( ! F_55 ( & V_70 ) ) {
V_2 = F_56 ( & V_70 ,
struct V_1 , V_69 ) ;
F_57 ( & V_2 -> V_69 ) ;
F_58 ( & V_2 -> V_39 ) ;
F_59 ( & V_2 -> V_39 ) ;
F_60 ( V_2 ) ;
}
V_67 = 0 ;
}
