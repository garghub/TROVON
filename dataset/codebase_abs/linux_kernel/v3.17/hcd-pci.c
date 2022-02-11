static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 || V_2 -> V_3 == V_5 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_1 * V_9 ;
struct V_6 * V_10 ;
unsigned int V_11 = F_3 ( V_2 -> V_12 ) ;
V_9 = NULL ;
F_4 (companion) {
if ( V_9 -> V_13 != V_2 -> V_13 ||
F_3 ( V_9 -> V_12 ) != V_11 )
continue;
V_10 = F_5 ( V_9 ) ;
if ( ! V_10 || ! V_10 -> V_14 . V_15 )
continue;
V_8 ( V_2 , V_7 , V_9 , V_10 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_9 , struct V_6 * V_10 )
{
struct V_16 * V_17 ;
if ( F_1 ( V_9 ) ) {
V_17 = V_10 -> V_14 . V_15 ;
F_7 ( V_17 ) ;
F_8 ( V_17 , 0 ) ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_9 , struct V_6 * V_10 )
{
struct V_16 * V_17 ;
if ( F_1 ( V_9 ) ) {
if ( F_10 ( & V_2 -> V_18 ) ) {
F_11 ( & V_2 -> V_18 , L_1 ,
F_12 ( & V_9 -> V_18 ) ) ;
V_10 -> V_14 . V_19 = & V_7 -> V_14 ;
}
V_17 = V_10 -> V_14 . V_15 ;
F_8 ( V_17 , 1 ) ;
F_13 ( V_17 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_9 , struct V_6 * V_10 )
{
if ( F_1 ( V_2 ) && V_9 -> V_3 == V_20 ) {
F_11 ( & V_2 -> V_18 , L_2 ,
F_12 ( & V_9 -> V_18 ) ) ;
V_7 -> V_14 . V_19 = & V_10 -> V_14 ;
}
}
static void F_15 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_9 , struct V_6 * V_10 )
{
if ( F_1 ( V_9 ) )
V_10 -> V_14 . V_19 = NULL ;
}
static void F_16 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_9 , struct V_6 * V_10 )
{
if ( F_1 ( V_9 ) )
F_17 ( & V_2 -> V_18 , & V_9 -> V_18 ) ;
}
int F_18 ( struct V_1 * V_18 , const struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_6 * V_7 ;
int V_25 ;
int V_26 = 0 ;
if ( F_19 () )
return - V_27 ;
if ( ! V_22 )
return - V_28 ;
V_24 = (struct V_23 * ) V_22 -> V_29 ;
if ( ! V_24 )
return - V_28 ;
if ( F_20 ( V_18 ) < 0 )
return - V_27 ;
if ( ( V_24 -> V_30 & V_31 ) != V_32 ) {
if ( ! V_18 -> V_33 ) {
F_21 ( & V_18 -> V_18 ,
L_3 ,
F_22 ( V_18 ) ) ;
V_25 = - V_27 ;
goto V_34;
}
V_26 = V_18 -> V_33 ;
}
V_7 = F_23 ( V_24 , & V_18 -> V_18 , F_22 ( V_18 ) ) ;
if ( ! V_7 ) {
V_25 = - V_35 ;
goto V_34;
}
V_7 -> V_36 = ( F_24 ( V_18 ) &&
V_24 -> V_30 & ( V_37 | V_32 ) ) ? 1 : 0 ;
if ( V_24 -> V_30 & V_38 ) {
V_7 -> V_39 = F_25 ( V_18 , 0 ) ;
V_7 -> V_40 = F_26 ( V_18 , 0 ) ;
if ( ! F_27 ( V_7 -> V_39 , V_7 -> V_40 ,
V_24 -> V_41 ) ) {
F_11 ( & V_18 -> V_18 , L_4 ) ;
V_25 = - V_42 ;
goto V_43;
}
V_7 -> V_44 = F_28 ( V_7 -> V_39 , V_7 -> V_40 ) ;
if ( V_7 -> V_44 == NULL ) {
F_11 ( & V_18 -> V_18 , L_5 ) ;
V_25 = - V_45 ;
goto V_46;
}
} else {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
if ( ! ( F_29 ( V_18 , V_47 ) &
V_49 ) )
continue;
V_7 -> V_39 = F_25 ( V_18 , V_47 ) ;
V_7 -> V_40 = F_26 ( V_18 , V_47 ) ;
if ( F_30 ( V_7 -> V_39 , V_7 -> V_40 ,
V_24 -> V_41 ) )
break;
}
if ( V_47 == V_48 ) {
F_11 ( & V_18 -> V_18 , L_6 ) ;
V_25 = - V_42 ;
goto V_43;
}
}
F_31 ( V_18 ) ;
if ( V_18 -> V_3 == V_20 ) {
F_32 ( & V_50 ) ;
F_33 ( & V_18 -> V_18 , V_7 ) ;
F_2 ( V_18 , V_7 , F_6 ) ;
V_25 = F_34 ( V_7 , V_26 , V_51 ) ;
if ( V_25 != 0 )
F_33 ( & V_18 -> V_18 , NULL ) ;
F_2 ( V_18 , V_7 , F_9 ) ;
F_35 ( & V_50 ) ;
} else {
F_36 ( & V_50 ) ;
F_33 ( & V_18 -> V_18 , V_7 ) ;
V_25 = F_34 ( V_7 , V_26 , V_51 ) ;
if ( V_25 != 0 )
F_33 ( & V_18 -> V_18 , NULL ) ;
else
F_2 ( V_18 , V_7 , F_14 ) ;
F_37 ( & V_50 ) ;
}
if ( V_25 != 0 )
goto V_52;
F_38 ( V_7 -> V_14 . V_53 ) ;
if ( F_39 ( V_18 ) )
F_40 ( & V_18 -> V_18 ) ;
return V_25 ;
V_52:
if ( V_24 -> V_30 & V_38 ) {
F_41 ( V_7 -> V_44 ) ;
V_46:
V_46 ( V_7 -> V_39 , V_7 -> V_40 ) ;
} else
F_42 ( V_7 -> V_39 , V_7 -> V_40 ) ;
V_43:
F_43 ( V_7 ) ;
V_34:
F_44 ( V_18 ) ;
F_21 ( & V_18 -> V_18 , L_7 , F_22 ( V_18 ) , V_25 ) ;
return V_25 ;
}
void F_45 ( struct V_1 * V_18 )
{
struct V_6 * V_7 ;
V_7 = F_5 ( V_18 ) ;
if ( ! V_7 )
return;
if ( F_39 ( V_18 ) )
F_46 ( & V_18 -> V_18 ) ;
F_47 () ;
F_48 ( 0 , V_7 ) ;
F_49 () ;
if ( V_18 -> V_3 == V_20 ) {
F_32 ( & V_50 ) ;
F_2 ( V_18 , V_7 , F_15 ) ;
F_50 ( V_7 ) ;
F_33 ( & V_18 -> V_18 , NULL ) ;
F_35 ( & V_50 ) ;
} else {
F_36 ( & V_50 ) ;
V_7 -> V_14 . V_19 = NULL ;
F_50 ( V_7 ) ;
F_33 ( & V_18 -> V_18 , NULL ) ;
F_37 ( & V_50 ) ;
}
if ( V_7 -> V_24 -> V_30 & V_38 ) {
F_41 ( V_7 -> V_44 ) ;
V_46 ( V_7 -> V_39 , V_7 -> V_40 ) ;
} else {
F_42 ( V_7 -> V_39 , V_7 -> V_40 ) ;
}
F_43 ( V_7 ) ;
F_44 ( V_18 ) ;
}
void F_51 ( struct V_1 * V_18 )
{
struct V_6 * V_7 ;
V_7 = F_5 ( V_18 ) ;
if ( ! V_7 )
return;
if ( F_52 ( V_54 , & V_7 -> V_30 ) &&
V_7 -> V_24 -> V_55 ) {
V_7 -> V_24 -> V_55 ( V_7 ) ;
if ( F_53 ( V_7 ) && V_7 -> V_33 > 0 )
F_54 ( V_7 -> V_33 , V_7 ) ;
F_44 ( V_18 ) ;
}
}
static void F_55 ( struct V_1 * V_1 , int V_56 )
{
if ( F_56 ( V_57 ) ) {
struct V_58 * V_59 ;
V_59 = F_57 ( V_1 ) ;
if ( V_59 )
F_58 ( V_60 ,
V_59 , 0 , V_56 ) ;
}
}
static inline void F_55 ( struct V_1 * V_1 , int V_56 )
{}
static int F_59 ( struct V_61 * V_18 )
{
struct V_1 * V_1 = F_60 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_61 ( V_7 ) ) {
F_62 ( V_18 , L_8 ) ;
return - V_42 ;
}
if ( V_7 -> V_62 ) {
V_7 = V_7 -> V_62 ;
if ( F_61 ( V_7 ) ) {
F_62 ( V_18 , L_9 ) ;
return - V_42 ;
}
}
return 0 ;
}
static int F_63 ( struct V_61 * V_18 , bool V_63 )
{
struct V_1 * V_1 = F_60 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
int V_25 ;
V_25 = F_59 ( V_18 ) ;
if ( V_25 )
return V_25 ;
if ( V_7 -> V_24 -> V_64 && ! F_64 ( V_7 ) ) {
if ( V_63 && F_65 ( V_7 ) )
return - V_42 ;
if ( V_63 && V_7 -> V_62 &&
F_65 ( V_7 -> V_62 ) )
return - V_42 ;
V_25 = V_7 -> V_24 -> V_64 ( V_7 , V_63 ) ;
F_66 ( V_7 -> V_24 -> V_64 , V_25 ) ;
if ( ( V_25 == 0 && V_63 && F_65 ( V_7 ) ) ||
( V_25 == 0 && V_63 && V_7 -> V_62 &&
F_65 ( V_7 -> V_62 ) ) ) {
if ( V_7 -> V_24 -> V_65 )
V_7 -> V_24 -> V_65 ( V_7 , false ) ;
V_25 = - V_42 ;
}
if ( V_25 )
return V_25 ;
}
if ( ! V_7 -> V_66 )
F_67 ( V_1 -> V_33 ) ;
F_44 ( V_1 ) ;
return V_25 ;
}
static int F_68 ( struct V_61 * V_18 , int V_67 )
{
struct V_1 * V_1 = F_60 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
int V_25 ;
if ( F_61 ( V_7 ) ||
( V_7 -> V_62 &&
F_61 ( V_7 -> V_62 ) ) ) {
F_11 ( V_18 , L_10 ) ;
return 0 ;
}
V_25 = F_20 ( V_1 ) ;
if ( V_25 < 0 ) {
F_21 ( V_18 , L_11 , V_25 ) ;
return V_25 ;
}
F_31 ( V_1 ) ;
if ( V_7 -> V_24 -> V_65 && ! F_64 ( V_7 ) ) {
if ( V_1 -> V_3 == V_20 && V_67 != V_68 )
F_2 ( V_1 , V_7 ,
F_16 ) ;
V_25 = V_7 -> V_24 -> V_65 ( V_7 ,
V_67 == V_69 ) ;
if ( V_25 ) {
F_21 ( V_18 , L_12 , V_25 ) ;
if ( V_7 -> V_62 )
F_69 ( V_7 -> V_62 ) ;
F_69 ( V_7 ) ;
}
}
return V_25 ;
}
static int F_70 ( struct V_61 * V_18 )
{
return F_63 ( V_18 , F_71 ( V_18 ) ) ;
}
static int F_72 ( struct V_61 * V_18 )
{
struct V_1 * V_1 = F_60 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
int V_25 ;
V_25 = F_59 ( V_18 ) ;
if ( V_25 )
return V_25 ;
F_73 ( V_1 ) ;
if ( F_64 ( V_7 ) )
F_74 ( V_18 , 0 ) ;
F_11 ( V_18 , L_13 , F_71 ( V_18 ) ) ;
V_25 = F_75 ( V_1 ) ;
if ( V_25 == - V_70 ) {
F_11 ( V_18 , L_14 ) ;
V_25 = 0 ;
} else if ( V_25 == 0 ) {
F_11 ( V_18 , L_15 ,
F_76 ( V_1 -> V_71 ) ) ;
} else {
F_66 ( F_75 , V_25 ) ;
return V_25 ;
}
F_55 ( V_1 , 0 ) ;
return V_25 ;
}
static int F_77 ( struct V_61 * V_18 )
{
struct V_1 * V_1 = F_60 ( V_18 ) ;
F_55 ( V_1 , 1 ) ;
F_78 ( V_1 ) ;
return 0 ;
}
static int F_79 ( struct V_61 * V_18 )
{
return F_68 ( V_18 , V_72 ) ;
}
static int F_80 ( struct V_61 * V_18 )
{
return F_68 ( V_18 , V_69 ) ;
}
static int F_81 ( struct V_61 * V_18 )
{
int V_25 ;
V_25 = F_63 ( V_18 , true ) ;
if ( V_25 == 0 )
F_55 ( F_60 ( V_18 ) , 0 ) ;
F_11 ( V_18 , L_16 , V_25 ) ;
return V_25 ;
}
static int F_82 ( struct V_61 * V_18 )
{
int V_25 ;
F_55 ( F_60 ( V_18 ) , 1 ) ;
V_25 = F_68 ( V_18 , V_68 ) ;
F_11 ( V_18 , L_17 , V_25 ) ;
return V_25 ;
}
