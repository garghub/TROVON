static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , int V_5 )
{
return F_4 ( V_2 -> V_4 + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int
V_5 , T_2 V_6 )
{
F_6 ( V_6 , V_2 -> V_4 + V_5 ) ;
}
static inline T_2 F_7 ( T_2 V_7 )
{
return V_7 * V_8 ;
}
int F_8 ( T_2 * V_9 )
{
struct V_1 * V_2 = & V_10 ;
const struct V_11 * V_12 = V_2 -> V_12 ;
T_2 V_7 ;
if ( ! V_2 -> V_13 )
return - V_14 ;
V_7 = F_3 ( V_2 , V_12 -> V_15 ) ;
* V_9 = F_7 ( V_7 ) ;
return 0 ;
}
static int F_9 ( void * V_9 , T_3 * V_6 )
{
struct V_1 * V_2 = V_9 ;
const struct V_11 * V_12 = V_2 -> V_12 ;
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_12 -> V_15 ) ;
* V_6 = F_7 ( V_7 ) ;
return 0 ;
}
static int F_10 ( void )
{
struct V_1 * V_2 = & V_10 ;
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_2 -> V_12 -> V_16 ) ;
return V_7 & F_11 ( V_2 -> V_12 -> V_17 ) ;
}
static void F_12 ( struct V_18 * V_19 , int V_20 ,
T_1 V_21 , const struct V_22 * V_23 )
{
F_13 ( V_19 , L_1 ,
V_20 , V_23 [ V_20 ] . V_24 ,
V_23 [ V_20 ] . V_25 & V_21 ? L_2 : L_3 ) ;
}
static int F_14 ( struct V_18 * V_19 , void * V_26 )
{
struct V_1 * V_2 = V_19 -> V_27 ;
const struct V_22 * V_12 = V_2 -> V_12 -> V_28 ;
T_1 V_29 [ V_30 ] ;
int V_20 , V_31 ;
V_31 = V_2 -> V_12 -> V_32 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_12 -> V_33 &&
V_20 < V_30 ; V_20 ++ , V_31 ++ )
V_29 [ V_20 ] = F_1 ( V_2 , V_31 ) ;
for ( V_20 = 0 ; V_12 [ V_20 ] . V_24 ; V_20 ++ )
F_12 ( V_19 , V_20 , V_29 [ V_20 / 8 ] , V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_16 ( V_35 , F_14 , V_34 -> V_36 ) ;
}
static int F_17 ( void )
{
struct V_1 * V_2 = & V_10 ;
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_37 ) ;
return V_7 & F_11 ( V_38 ) ;
}
static int F_18 ( T_2 * V_39 )
{
struct V_1 * V_2 = & V_10 ;
T_2 V_40 ;
int V_41 ;
for ( V_41 = V_42 ; V_41 > 0 ; V_41 -- ) {
if ( F_17 () == 0 )
break;
F_19 ( 5 ) ;
}
if ( V_41 <= 0 && F_17 () )
return - V_43 ;
V_40 = ( * V_39 & V_44 ) | ( 1U << 1 ) ;
F_5 ( V_2 , V_45 , V_40 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , void * V_26 )
{
struct V_1 * V_2 = V_19 -> V_27 ;
const struct V_22 * V_12 = V_2 -> V_12 -> V_46 ;
T_2 V_47 , V_48 ;
T_2 V_49 , V_50 ;
int V_20 , V_51 = 0 ;
if ( V_2 -> V_52 ) {
F_21 ( V_19 , L_4 ) ;
return 0 ;
}
V_47 = ( V_53 << 16 ) ;
V_48 = ( V_54 << 16 ) ;
F_22 ( & V_2 -> V_55 ) ;
if ( F_18 ( & V_47 ) != 0 ) {
V_51 = - V_43 ;
goto V_56;
}
F_19 ( 10 ) ;
V_49 = F_3 ( V_2 , V_57 ) ;
if ( F_18 ( & V_48 ) != 0 ) {
V_51 = - V_43 ;
goto V_56;
}
F_19 ( 10 ) ;
V_50 = F_3 ( V_2 , V_57 ) ;
for ( V_20 = 0 ; V_12 [ V_20 ] . V_24 && V_20 < 8 ; V_20 ++ ) {
F_13 ( V_19 , L_5 ,
V_12 [ V_20 ] . V_24 ,
V_12 [ V_20 ] . V_25 & V_49 ? L_6 :
L_7 ) ;
}
for ( V_20 = 8 ; V_12 [ V_20 ] . V_24 ; V_20 ++ ) {
F_13 ( V_19 , L_5 ,
V_12 [ V_20 ] . V_24 ,
V_12 [ V_20 ] . V_25 & V_50 ? L_6 :
L_7 ) ;
}
V_56:
F_23 ( & V_2 -> V_55 ) ;
return V_51 ;
}
static int F_24 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_16 ( V_35 , F_20 , V_34 -> V_36 ) ;
}
static int F_25 ( struct V_18 * V_19 , void * V_26 )
{
struct V_1 * V_2 = V_19 -> V_27 ;
const struct V_22 * V_12 = V_2 -> V_12 -> V_58 ;
T_2 V_59 , V_6 ;
int V_20 , V_51 = 0 ;
if ( V_2 -> V_52 ) {
F_21 ( V_19 , L_4 ) ;
return 0 ;
}
V_59 = ( V_60 << 16 ) ;
F_22 ( & V_2 -> V_55 ) ;
if ( F_18 ( & V_59 ) != 0 ) {
V_51 = - V_43 ;
goto V_56;
}
F_19 ( 10 ) ;
V_6 = F_3 ( V_2 , V_57 ) ;
for ( V_20 = 0 ; V_12 [ V_20 ] . V_24 ; V_20 ++ ) {
F_13 ( V_19 , L_5 ,
V_12 [ V_20 ] . V_24 ,
V_12 [ V_20 ] . V_25 & V_6 ? L_8 : L_9 ) ;
}
V_56:
F_23 ( & V_2 -> V_55 ) ;
return V_51 ;
}
static int F_26 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_16 ( V_35 , F_25 , V_34 -> V_36 ) ;
}
static T_4 F_27 ( struct V_35 * V_35 , const char T_5
* V_61 , T_6 V_62 , T_7 * V_63 )
{
struct V_1 * V_2 = & V_10 ;
const struct V_11 * V_12 = V_2 -> V_12 ;
T_2 V_6 , V_64 , V_65 ;
int V_51 = 0 ;
V_64 = V_62 < 64 ? V_62 : 64 ;
F_22 ( & V_2 -> V_55 ) ;
if ( F_28 ( V_61 , V_64 , 10 , & V_6 ) ) {
V_51 = - V_66 ;
goto V_56;
}
if ( V_6 > V_67 ) {
V_51 = - V_68 ;
goto V_56;
}
V_65 = F_3 ( V_2 , V_12 -> V_69 ) ;
V_65 |= ( 1U << V_6 ) ;
F_5 ( V_2 , V_12 -> V_69 , V_65 ) ;
V_56:
F_23 ( & V_2 -> V_55 ) ;
return V_51 == 0 ? V_62 : V_51 ;
}
static int F_29 ( struct V_18 * V_19 , void * V_26 )
{
return 0 ;
}
static int F_30 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_16 ( V_35 , F_29 , V_34 -> V_36 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 -> V_70 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_71 * V_72 , * V_35 ;
V_72 = F_34 ( L_10 , NULL ) ;
if ( ! V_72 )
return - V_73 ;
V_2 -> V_70 = V_72 ;
V_35 = F_35 ( L_11 , V_74 | V_75 ,
V_72 , V_2 , & V_76 ) ;
if ( ! V_35 )
goto V_51;
V_35 = F_35 ( L_12 ,
V_74 | V_75 , V_72 , V_2 ,
& V_77 ) ;
if ( ! V_35 )
goto V_51;
V_35 = F_35 ( L_13 ,
V_74 | V_75 , V_72 , V_2 ,
& V_78 ) ;
if ( ! V_35 )
goto V_51;
V_35 = F_35 ( L_14 ,
V_74 | V_75 , V_72 , V_2 ,
& V_79 ) ;
if ( ! V_35 )
goto V_51;
V_35 = F_35 ( L_15 ,
V_74 | V_75 , V_72 , V_2 ,
& V_80 ) ;
if ( ! V_35 )
goto V_51;
return 0 ;
V_51:
F_31 ( V_2 ) ;
return - V_81 ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
}
static int F_36 ( struct V_82 * V_83 , const struct V_84 * V_85 )
{
struct V_86 * V_87 = & V_83 -> V_83 ;
struct V_1 * V_2 = & V_10 ;
const struct V_88 * V_89 ;
const struct V_11 * V_12 = (struct V_11 * ) V_85 -> V_90 ;
int V_51 ;
V_89 = F_37 ( V_91 ) ;
if ( ! V_89 ) {
F_38 ( & V_83 -> V_83 , L_16 ) ;
return - V_68 ;
}
V_51 = F_39 ( V_83 ) ;
if ( V_51 < 0 ) {
F_38 ( & V_83 -> V_83 , L_17 ) ;
return V_51 ;
}
V_51 = F_40 ( V_83 ,
V_92 ,
& V_2 -> V_93 ) ;
if ( V_51 < 0 ) {
F_38 ( & V_83 -> V_83 , L_18 ) ;
return V_51 ;
}
V_2 -> V_93 &= V_94 ;
F_38 ( & V_83 -> V_83 , L_19 , V_2 -> V_93 ) ;
V_2 -> V_4 = F_41 ( V_87 ,
V_2 -> V_93 ,
V_95 ) ;
if ( ! V_2 -> V_4 ) {
F_38 ( & V_83 -> V_83 , L_20 ) ;
return - V_73 ;
}
F_42 ( & V_2 -> V_55 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_52 = F_10 () ;
V_51 = F_33 ( V_2 ) ;
if ( V_51 < 0 )
F_43 ( & V_83 -> V_83 , L_21 ) ;
V_10 . V_13 = true ;
return 0 ;
}
