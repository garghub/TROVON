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
T_2 V_7 ;
if ( ! V_2 -> V_11 )
return - V_12 ;
V_7 = F_3 ( V_2 , V_13 ) ;
* V_9 = F_7 ( V_7 ) ;
return 0 ;
}
static int F_9 ( void * V_9 , T_3 * V_6 )
{
struct V_1 * V_2 = V_9 ;
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_13 ) ;
* V_6 = F_7 ( V_7 ) ;
return 0 ;
}
static int F_10 ( void )
{
struct V_1 * V_2 = & V_10 ;
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_14 ) ;
return V_7 & F_11 ( V_15 ) ;
}
static void F_12 ( struct V_16 * V_17 , int V_18 ,
T_1 V_19 , const struct V_20 * V_21 )
{
F_13 ( V_17 , L_1 ,
V_18 , V_21 [ V_18 ] . V_22 ,
V_21 [ V_18 ] . V_23 & V_19 ? L_2 : L_3 ) ;
}
static int F_14 ( struct V_16 * V_17 , void * V_24 )
{
struct V_1 * V_2 = V_17 -> V_25 ;
const struct V_20 * V_26 = V_2 -> V_26 -> V_27 ;
T_1 V_28 [ V_29 ] ;
int V_18 , V_30 ;
V_30 = V_31 ;
for ( V_18 = 0 ; V_18 < V_29 ; V_18 ++ , V_30 ++ )
V_28 [ V_18 ] = F_1 ( V_2 , V_30 ) ;
for ( V_18 = 0 ; V_26 [ V_18 ] . V_22 ; V_18 ++ )
F_12 ( V_17 , V_18 , V_28 [ V_18 / 8 ] , V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
return F_16 ( V_33 , F_14 , V_32 -> V_34 ) ;
}
static int F_17 ( void )
{
struct V_1 * V_2 = & V_10 ;
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_35 ) ;
return V_7 & F_11 ( V_36 ) ;
}
static int F_18 ( T_2 * V_37 )
{
struct V_1 * V_2 = & V_10 ;
T_2 V_38 ;
int V_39 ;
for ( V_39 = V_40 ; V_39 > 0 ; V_39 -- ) {
if ( F_17 () == 0 )
break;
F_19 ( 5 ) ;
}
if ( V_39 <= 0 && F_17 () )
return - V_41 ;
V_38 = ( * V_37 & V_42 ) | ( 1U << 1 ) ;
F_5 ( V_2 , V_43 , V_38 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 , void * V_24 )
{
struct V_1 * V_2 = V_17 -> V_25 ;
const struct V_20 * V_26 = V_2 -> V_26 -> V_44 ;
T_2 V_45 , V_46 ;
T_2 V_47 , V_48 ;
int V_18 , V_49 = 0 ;
if ( V_2 -> V_50 ) {
F_21 ( V_17 , L_4 ) ;
return 0 ;
}
V_45 = ( V_51 << 16 ) ;
V_46 = ( V_52 << 16 ) ;
F_22 ( & V_2 -> V_53 ) ;
if ( F_18 ( & V_45 ) != 0 ) {
V_49 = - V_41 ;
goto V_54;
}
F_19 ( 10 ) ;
V_47 = F_3 ( V_2 , V_55 ) ;
if ( F_18 ( & V_46 ) != 0 ) {
V_49 = - V_41 ;
goto V_54;
}
F_19 ( 10 ) ;
V_48 = F_3 ( V_2 , V_55 ) ;
for ( V_18 = 0 ; V_26 [ V_18 ] . V_22 && V_18 < 8 ; V_18 ++ ) {
F_13 ( V_17 , L_5 ,
V_26 [ V_18 ] . V_22 ,
V_26 [ V_18 ] . V_23 & V_47 ? L_6 :
L_7 ) ;
}
for ( V_18 = 8 ; V_26 [ V_18 ] . V_22 ; V_18 ++ ) {
F_13 ( V_17 , L_5 ,
V_26 [ V_18 ] . V_22 ,
V_26 [ V_18 ] . V_23 & V_48 ? L_6 :
L_7 ) ;
}
V_54:
F_23 ( & V_2 -> V_53 ) ;
return V_49 ;
}
static int F_24 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
return F_16 ( V_33 , F_20 , V_32 -> V_34 ) ;
}
static int F_25 ( struct V_16 * V_17 , void * V_24 )
{
struct V_1 * V_2 = V_17 -> V_25 ;
const struct V_20 * V_26 = V_2 -> V_26 -> V_56 ;
T_2 V_57 , V_6 ;
int V_18 , V_49 = 0 ;
if ( V_2 -> V_50 ) {
F_21 ( V_17 , L_4 ) ;
return 0 ;
}
V_57 = ( V_58 << 16 ) ;
F_22 ( & V_2 -> V_53 ) ;
if ( F_18 ( & V_57 ) != 0 ) {
V_49 = - V_41 ;
goto V_54;
}
F_19 ( 10 ) ;
V_6 = F_3 ( V_2 , V_55 ) ;
for ( V_18 = 0 ; V_26 [ V_18 ] . V_22 ; V_18 ++ ) {
F_13 ( V_17 , L_5 ,
V_26 [ V_18 ] . V_22 ,
V_26 [ V_18 ] . V_23 & V_6 ? L_8 : L_9 ) ;
}
V_54:
F_23 ( & V_2 -> V_53 ) ;
return V_49 ;
}
static int F_26 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
return F_16 ( V_33 , F_25 , V_32 -> V_34 ) ;
}
static T_4 F_27 ( struct V_33 * V_33 , const char T_5
* V_59 , T_6 V_60 , T_7 * V_61 )
{
struct V_1 * V_2 = & V_10 ;
T_2 V_6 , V_62 , V_63 ;
int V_49 = 0 ;
V_62 = V_60 < 64 ? V_60 : 64 ;
F_22 ( & V_2 -> V_53 ) ;
if ( F_28 ( V_59 , V_62 , 10 , & V_6 ) ) {
V_49 = - V_64 ;
goto V_54;
}
if ( V_6 > V_65 ) {
V_49 = - V_66 ;
goto V_54;
}
V_63 = F_3 ( V_2 , V_67 ) ;
V_63 |= ( 1U << V_6 ) ;
F_5 ( V_2 , V_67 , V_63 ) ;
V_54:
F_23 ( & V_2 -> V_53 ) ;
return V_49 == 0 ? V_60 : V_49 ;
}
static int F_29 ( struct V_16 * V_17 , void * V_24 )
{
return 0 ;
}
static int F_30 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
return F_16 ( V_33 , F_29 , V_32 -> V_34 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 -> V_68 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_69 * V_70 , * V_33 ;
V_70 = F_34 ( L_10 , NULL ) ;
if ( ! V_70 )
return - V_71 ;
V_2 -> V_68 = V_70 ;
V_33 = F_35 ( L_11 , V_72 | V_73 ,
V_70 , V_2 , & V_74 ) ;
if ( ! V_33 )
goto V_49;
V_33 = F_35 ( L_12 ,
V_72 | V_73 , V_70 , V_2 ,
& V_75 ) ;
if ( ! V_33 )
goto V_49;
V_33 = F_35 ( L_13 ,
V_72 | V_73 , V_70 , V_2 ,
& V_76 ) ;
if ( ! V_33 )
goto V_49;
V_33 = F_35 ( L_14 ,
V_72 | V_73 , V_70 , V_2 ,
& V_77 ) ;
if ( ! V_33 )
goto V_49;
V_33 = F_35 ( L_15 ,
V_72 | V_73 , V_70 , V_2 ,
& V_78 ) ;
if ( ! V_33 )
goto V_49;
return 0 ;
V_49:
F_31 ( V_2 ) ;
return - V_79 ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
}
static int F_36 ( struct V_80 * V_81 , const struct V_82 * V_83 )
{
struct V_84 * V_85 = & V_81 -> V_81 ;
struct V_1 * V_2 = & V_10 ;
const struct V_86 * V_87 ;
const struct V_88 * V_26 = (struct V_88 * ) V_83 -> V_89 ;
int V_49 ;
V_87 = F_37 ( V_90 ) ;
if ( ! V_87 ) {
F_38 ( & V_81 -> V_81 , L_16 ) ;
return - V_66 ;
}
V_49 = F_39 ( V_81 ) ;
if ( V_49 < 0 ) {
F_38 ( & V_81 -> V_81 , L_17 ) ;
return V_49 ;
}
V_49 = F_40 ( V_81 ,
V_91 ,
& V_2 -> V_92 ) ;
if ( V_49 < 0 ) {
F_38 ( & V_81 -> V_81 , L_18 ) ;
return V_49 ;
}
V_2 -> V_92 &= V_93 ;
F_38 ( & V_81 -> V_81 , L_19 , V_2 -> V_92 ) ;
V_2 -> V_4 = F_41 ( V_85 ,
V_2 -> V_92 ,
V_94 ) ;
if ( ! V_2 -> V_4 ) {
F_38 ( & V_81 -> V_81 , L_20 ) ;
return - V_71 ;
}
F_42 ( & V_2 -> V_53 ) ;
V_2 -> V_50 = F_10 () ;
V_2 -> V_26 = V_26 ;
V_49 = F_33 ( V_2 ) ;
if ( V_49 < 0 )
F_43 ( & V_81 -> V_81 , L_21 ) ;
V_10 . V_11 = true ;
return 0 ;
}
