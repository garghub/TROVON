static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_8 [ V_7 ] . V_9 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_7 ,
const unsigned * * V_10 , unsigned * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
* V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_12 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_13 * V_14 ,
unsigned V_15 )
{
F_6 ( V_14 , L_1 , F_7 ( V_2 -> V_16 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_19 * * V_20 , unsigned * V_21 )
{
struct V_19 * V_22 ;
char * V_7 = NULL ;
unsigned V_23 = 1 ;
unsigned long V_24 = 0 ;
unsigned long * V_25 ;
int V_26 = strlen ( V_18 -> V_9 ) + V_27 ;
bool V_28 = false ;
T_1 V_29 , V_30 ;
int V_31 , V_32 = 0 ;
if ( F_9 ( V_18 , L_2 , & V_30 ) )
V_28 = true ;
V_31 = F_9 ( V_18 , L_3 , & V_29 ) ;
if ( ! V_31 )
V_24 = V_29 | V_33 ;
V_31 = F_9 ( V_18 , L_4 , & V_29 ) ;
if ( ! V_31 )
V_24 |= V_29 << V_34 | V_35 ;
V_31 = F_9 ( V_18 , L_5 , & V_29 ) ;
if ( ! V_31 )
V_24 |= V_29 << V_36 | V_37 ;
if ( ! V_28 && V_24 )
V_23 = 2 ;
V_22 = F_10 ( sizeof( * V_22 ) * V_23 , V_38 ) ;
if ( ! V_22 )
return - V_39 ;
if ( ! V_28 ) {
V_22 [ V_32 ] . type = V_40 ;
V_22 [ V_32 ] . V_41 . V_42 . V_43 = V_18 -> V_9 ;
V_7 = F_10 ( V_26 , V_38 ) ;
if ( ! V_7 ) {
V_31 = - V_39 ;
goto free;
}
snprintf ( V_7 , V_26 , L_6 , V_18 -> V_9 , V_30 ) ;
V_22 [ V_32 ] . V_41 . V_42 . V_7 = V_7 ;
V_32 ++ ;
}
if ( V_24 ) {
V_25 = F_11 ( & V_24 , sizeof( V_24 ) , V_38 ) ;
if ( ! V_25 ) {
V_31 = - V_39 ;
goto V_44;
}
V_22 [ V_32 ] . type = V_45 ;
V_22 [ V_32 ] . V_41 . V_46 . V_47 = V_28 ? V_18 -> V_9 :
V_7 ;
V_22 [ V_32 ] . V_41 . V_46 . V_46 = V_25 ;
V_22 [ V_32 ] . V_41 . V_46 . V_48 = 1 ;
}
* V_20 = V_22 ;
* V_21 = V_23 ;
return 0 ;
V_44:
if ( ! V_28 )
F_12 ( V_7 ) ;
free:
F_12 ( V_22 ) ;
return V_31 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_19 * V_20 , unsigned V_21 )
{
T_1 V_32 ;
for ( V_32 = 0 ; V_32 < V_21 ; V_32 ++ ) {
if ( V_20 [ V_32 ] . type == V_40 )
F_12 ( V_20 [ V_32 ] . V_41 . V_42 . V_7 ) ;
if ( V_20 [ V_32 ] . type == V_45 )
F_12 ( V_20 [ V_32 ] . V_41 . V_46 . V_46 ) ;
}
F_12 ( V_20 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_49 ;
}
static const char * F_15 ( struct V_1 * V_2 ,
unsigned V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_50 [ V_43 ] . V_9 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_7 ,
const char * const * * V_8 ,
unsigned * const V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_8 = V_4 -> V_5 -> V_50 [ V_7 ] . V_8 ;
* V_51 = V_4 -> V_5 -> V_50 [ V_7 ] . V_6 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned V_52 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_53 * V_54 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
void T_2 * V_30 ;
T_3 V_55 , V_56 ;
T_4 V_57 ;
T_1 V_32 ;
for ( V_32 = 0 ; V_32 < V_54 -> V_12 ; V_32 ++ ) {
V_55 = F_18 ( V_54 -> V_10 [ V_32 ] ) ;
V_57 = F_19 ( V_54 -> V_10 [ V_32 ] ) ;
V_30 = V_4 -> V_58 + V_4 -> V_5 -> V_59 -> V_60 ;
V_30 += V_55 * 0x20 + V_57 / 16 * 0x10 ;
V_56 = V_57 % 16 * 2 ;
F_20 ( 0x3 << V_56 , V_30 + V_61 ) ;
F_20 ( V_54 -> V_60 [ V_32 ] << V_56 , V_30 + V_62 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned V_57 , unsigned long * V_24 )
{
return - V_63 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned V_57 , unsigned long V_24 )
{
return - V_63 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned V_7 , unsigned long * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_24 = V_4 -> V_5 -> V_8 [ V_7 ] . V_24 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned V_7 , unsigned long V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_53 * V_54 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
void T_2 * V_30 ;
T_3 V_64 , V_65 , V_66 , V_55 , V_56 ;
T_4 V_57 ;
T_1 V_32 ;
V_64 = F_25 ( V_24 ) ;
V_65 = F_26 ( V_24 ) ;
V_66 = F_27 ( V_24 ) ;
for ( V_32 = 0 ; V_32 < V_54 -> V_12 ; V_32 ++ ) {
V_55 = F_18 ( V_54 -> V_10 [ V_32 ] ) ;
V_57 = F_19 ( V_54 -> V_10 [ V_32 ] ) ;
V_30 = V_4 -> V_58 + V_4 -> V_5 -> V_59 -> V_67 ;
V_30 += V_55 * 0x40 + V_57 / 8 * 0x10 ;
if ( V_24 & V_33 ) {
V_56 = V_57 % 8 * 4 ;
F_20 ( 0x3 << V_56 , V_30 + V_61 ) ;
F_20 ( V_64 << V_56 , V_30 + V_62 ) ;
}
if ( V_24 & V_35 ) {
V_56 = V_57 % 8 * 4 + 2 ;
if ( V_65 )
F_20 ( 1 << V_56 , V_30 + V_62 ) ;
else
F_20 ( 1 << V_56 , V_30 + V_61 ) ;
}
if ( V_24 & V_37 ) {
V_30 = V_4 -> V_58 + V_4 -> V_5 -> V_59 -> V_66 ;
V_30 += V_55 * 0x10 ;
V_56 = V_57 ;
if ( V_66 )
F_20 ( 1 << V_56 , V_30 + V_62 ) ;
else
F_20 ( 1 << V_56 , V_30 + V_61 ) ;
}
}
V_54 -> V_24 = V_24 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_57 )
{
}
static void F_29 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_7 )
{
unsigned long V_24 ;
if ( ! F_23 ( V_2 , V_7 , & V_24 ) )
F_6 ( V_14 , L_7 , V_24 ) ;
}
static int F_30 ( struct V_68 * V_69 ,
struct V_17 * V_18 , int V_70 ,
const char * * V_71 )
{
struct V_3 * V_4 = F_31 ( V_69 ) ;
struct V_53 * V_54 = & V_4 -> V_5 -> V_8 [ V_70 ] ;
struct V_72 * V_73 ;
const char * V_74 = L_8 ;
char * V_7 ;
int V_26 = strlen ( V_18 -> V_9 ) + V_27 ;
T_1 V_29 , V_32 ;
V_7 = F_32 ( & V_69 -> V_16 , V_26 , V_38 ) ;
if ( ! V_7 )
return - V_39 ;
if ( F_9 ( V_18 , L_2 , & V_29 ) )
snprintf ( V_7 , V_26 , L_9 , V_18 -> V_9 ) ;
else
snprintf ( V_7 , V_26 , L_6 , V_18 -> V_9 , V_29 ) ;
V_54 -> V_9 = V_7 ;
V_73 = F_33 ( V_18 , V_74 , & V_26 ) ;
if ( ! V_73 )
return - V_75 ;
V_54 -> V_12 = V_26 / sizeof( T_1 ) ;
V_54 -> V_10 = F_32 ( & V_69 -> V_16 , V_54 -> V_12 * sizeof( * V_54 -> V_10 ) ,
V_38 ) ;
if ( ! V_54 -> V_10 )
return - V_39 ;
V_54 -> V_60 = F_32 ( & V_69 -> V_16 , V_54 -> V_12 * sizeof( * V_54 -> V_60 ) ,
V_38 ) ;
if ( ! V_54 -> V_60 )
return - V_39 ;
F_34 ( V_18 , V_74 , V_54 -> V_10 , V_54 -> V_12 ) ;
for ( V_32 = 0 ; V_32 < V_54 -> V_12 ; V_32 ++ ) {
V_54 -> V_60 [ V_32 ] = F_35 ( V_54 -> V_10 [ V_32 ] ) ;
V_54 -> V_10 [ V_32 ] = F_36 ( V_54 -> V_10 [ V_32 ] ) ;
}
if ( V_71 )
* V_71 = V_54 -> V_9 ;
return 0 ;
}
static int F_37 ( struct V_68 * V_69 ,
struct V_3 * V_4 )
{
struct V_76 * V_5 = V_4 -> V_5 ;
struct V_17 * V_18 = V_69 -> V_16 . V_77 ;
struct V_17 * V_78 ;
struct V_79 * V_80 ;
const char * V_81 = L_10 ;
const char * V_82 , * V_83 = L_11 ;
int V_32 = 0 , V_84 = 0 , V_85 = 0 ;
int V_31 ;
T_1 V_29 ;
V_78 = F_38 ( V_18 , NULL ) ;
if ( ! V_78 ) {
F_39 ( & V_69 -> V_16 , L_12 ) ;
return - V_86 ;
}
V_82 = V_83 ;
F_40 (np, child) {
if ( F_41 ( V_78 , V_81 ) )
continue;
V_5 -> V_6 ++ ;
if ( F_9 ( V_78 , L_2 , & V_29 ) )
continue;
if ( strcmp ( V_82 , V_78 -> V_9 ) ) {
V_82 = V_78 -> V_9 ;
V_5 -> V_49 ++ ;
}
}
V_5 -> V_50 = F_32 ( & V_69 -> V_16 , V_5 -> V_49 *
sizeof( * V_5 -> V_50 ) , V_38 ) ;
if ( ! V_5 -> V_50 )
return - V_39 ;
V_5 -> V_8 = F_32 ( & V_69 -> V_16 , V_5 -> V_6 *
sizeof( * V_5 -> V_8 ) , V_38 ) ;
if ( ! V_5 -> V_8 )
return - V_39 ;
V_82 = V_83 ;
V_80 = & V_5 -> V_50 [ V_84 ] ;
F_40 (np, child) {
if ( F_41 ( V_78 , V_81 ) )
continue;
if ( F_9 ( V_78 , L_2 , & V_29 ) )
continue;
if ( strcmp ( V_82 , V_78 -> V_9 ) ) {
V_80 = & V_5 -> V_50 [ V_84 ++ ] ;
V_80 -> V_9 = V_82 = V_78 -> V_9 ;
}
V_80 -> V_6 ++ ;
} ;
V_84 = 0 ;
V_82 = V_83 ;
F_40 (np, child) {
if ( F_41 ( V_78 , V_81 ) )
continue;
if ( F_9 ( V_78 , L_2 , & V_29 ) ) {
V_31 = F_30 ( V_69 , V_78 ,
V_85 ++ , NULL ) ;
if ( V_31 )
return V_31 ;
continue;
}
if ( strcmp ( V_82 , V_78 -> V_9 ) ) {
V_80 = & V_5 -> V_50 [ V_84 ++ ] ;
V_80 -> V_8 = F_32 ( & V_69 -> V_16 , V_80 -> V_6 *
sizeof( * V_80 -> V_8 ) ,
V_38 ) ;
if ( ! V_80 -> V_8 )
return - V_39 ;
V_82 = V_78 -> V_9 ;
V_32 = 0 ;
}
V_31 = F_30 ( V_69 , V_78 , V_85 ++ ,
& V_80 -> V_8 [ V_32 ++ ] ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
int F_42 ( struct V_68 * V_69 ,
struct V_76 * V_5 )
{
struct V_17 * V_18 = V_69 -> V_16 . V_77 ;
struct V_3 * V_4 ;
int V_31 ;
V_4 = F_32 ( & V_69 -> V_16 , sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_39 ;
V_4 -> V_16 = & V_69 -> V_16 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_58 = F_43 ( V_18 , 0 ) ;
if ( ! V_4 -> V_58 )
return - V_87 ;
V_88 . V_10 = V_4 -> V_5 -> V_10 ;
V_88 . V_12 = V_4 -> V_5 -> V_12 ;
V_88 . V_9 = F_7 ( & V_69 -> V_16 ) ;
F_44 ( V_69 , V_4 ) ;
V_31 = F_37 ( V_69 , V_4 ) ;
if ( V_31 ) {
F_39 ( & V_69 -> V_16 , L_13 , V_31 ) ;
goto V_89;
}
V_4 -> V_90 = F_45 ( & V_88 , & V_69 -> V_16 , V_4 ) ;
if ( ! V_4 -> V_90 ) {
F_39 ( & V_69 -> V_16 , L_14 ) ;
V_31 = - V_75 ;
goto V_89;
}
return 0 ;
V_89:
F_44 ( V_69 , NULL ) ;
F_46 ( V_4 -> V_58 ) ;
return V_31 ;
}
int F_47 ( struct V_68 * V_69 )
{
struct V_3 * V_4 = F_31 ( V_69 ) ;
F_44 ( V_69 , NULL ) ;
F_48 ( V_4 -> V_90 ) ;
F_46 ( V_4 -> V_58 ) ;
return 0 ;
}
