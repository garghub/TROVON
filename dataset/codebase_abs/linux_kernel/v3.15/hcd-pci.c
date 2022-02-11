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
V_18 -> V_30 = V_31 ;
if ( ( V_24 -> V_32 & V_33 ) != V_34 ) {
if ( ! V_18 -> V_35 ) {
F_21 ( & V_18 -> V_18 ,
L_3 ,
F_22 ( V_18 ) ) ;
V_25 = - V_27 ;
goto V_36;
}
V_26 = V_18 -> V_35 ;
}
V_7 = F_23 ( V_24 , & V_18 -> V_18 , F_22 ( V_18 ) ) ;
if ( ! V_7 ) {
V_25 = - V_37 ;
goto V_36;
}
V_7 -> V_38 = ( F_24 ( V_18 ) &&
V_24 -> V_32 & ( V_39 | V_34 ) ) ? 1 : 0 ;
if ( V_24 -> V_32 & V_40 ) {
V_7 -> V_41 = F_25 ( V_18 , 0 ) ;
V_7 -> V_42 = F_26 ( V_18 , 0 ) ;
if ( ! F_27 ( V_7 -> V_41 , V_7 -> V_42 ,
V_24 -> V_43 ) ) {
F_11 ( & V_18 -> V_18 , L_4 ) ;
V_25 = - V_44 ;
goto V_45;
}
V_7 -> V_46 = F_28 ( V_7 -> V_41 , V_7 -> V_42 ) ;
if ( V_7 -> V_46 == NULL ) {
F_11 ( & V_18 -> V_18 , L_5 ) ;
V_25 = - V_47 ;
goto V_48;
}
} else {
int V_49 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( ! ( F_29 ( V_18 , V_49 ) &
V_51 ) )
continue;
V_7 -> V_41 = F_25 ( V_18 , V_49 ) ;
V_7 -> V_42 = F_26 ( V_18 , V_49 ) ;
if ( F_30 ( V_7 -> V_41 , V_7 -> V_42 ,
V_24 -> V_43 ) )
break;
}
if ( V_49 == V_50 ) {
F_11 ( & V_18 -> V_18 , L_6 ) ;
V_25 = - V_44 ;
goto V_45;
}
}
F_31 ( V_18 ) ;
if ( V_18 -> V_3 == V_20 ) {
F_32 ( & V_52 ) ;
F_33 ( & V_18 -> V_18 , V_7 ) ;
F_2 ( V_18 , V_7 , F_6 ) ;
V_25 = F_34 ( V_7 , V_26 , V_53 ) ;
if ( V_25 != 0 )
F_33 ( & V_18 -> V_18 , NULL ) ;
F_2 ( V_18 , V_7 , F_9 ) ;
F_35 ( & V_52 ) ;
} else {
F_36 ( & V_52 ) ;
F_33 ( & V_18 -> V_18 , V_7 ) ;
V_25 = F_34 ( V_7 , V_26 , V_53 ) ;
if ( V_25 != 0 )
F_33 ( & V_18 -> V_18 , NULL ) ;
else
F_2 ( V_18 , V_7 , F_14 ) ;
F_37 ( & V_52 ) ;
}
if ( V_25 != 0 )
goto V_54;
F_38 ( V_7 -> V_14 . V_55 ) ;
if ( F_39 ( V_18 ) )
F_40 ( & V_18 -> V_18 ) ;
return V_25 ;
V_54:
if ( V_24 -> V_32 & V_40 ) {
F_41 ( V_7 -> V_46 ) ;
V_48:
V_48 ( V_7 -> V_41 , V_7 -> V_42 ) ;
} else
F_42 ( V_7 -> V_41 , V_7 -> V_42 ) ;
V_45:
F_43 ( V_7 ) ;
V_36:
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
F_32 ( & V_52 ) ;
F_2 ( V_18 , V_7 , F_15 ) ;
F_50 ( V_7 ) ;
F_33 ( & V_18 -> V_18 , NULL ) ;
F_35 ( & V_52 ) ;
} else {
F_36 ( & V_52 ) ;
V_7 -> V_14 . V_19 = NULL ;
F_50 ( V_7 ) ;
F_33 ( & V_18 -> V_18 , NULL ) ;
F_37 ( & V_52 ) ;
}
if ( V_7 -> V_24 -> V_32 & V_40 ) {
F_41 ( V_7 -> V_46 ) ;
V_48 ( V_7 -> V_41 , V_7 -> V_42 ) ;
} else {
F_42 ( V_7 -> V_41 , V_7 -> V_42 ) ;
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
if ( F_52 ( V_56 , & V_7 -> V_32 ) &&
V_7 -> V_24 -> V_57 ) {
V_7 -> V_24 -> V_57 ( V_7 ) ;
F_44 ( V_18 ) ;
}
}
static void F_53 ( struct V_1 * V_1 , int V_58 )
{
if ( F_54 ( V_59 ) ) {
struct V_60 * V_61 ;
V_61 = F_55 ( V_1 ) ;
if ( V_61 )
F_56 ( V_62 ,
V_61 , 0 , V_58 ) ;
}
}
static inline void F_53 ( struct V_1 * V_1 , int V_58 )
{}
static int F_57 ( struct V_63 * V_18 )
{
struct V_1 * V_1 = F_58 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_59 ( V_7 ) ) {
F_60 ( V_18 , L_8 ) ;
return - V_44 ;
}
if ( V_7 -> V_64 ) {
V_7 = V_7 -> V_64 ;
if ( F_59 ( V_7 ) ) {
F_60 ( V_18 , L_9 ) ;
return - V_44 ;
}
}
return 0 ;
}
static int F_61 ( struct V_63 * V_18 , bool V_65 )
{
struct V_1 * V_1 = F_58 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
int V_25 ;
V_25 = F_57 ( V_18 ) ;
if ( V_25 )
return V_25 ;
if ( V_7 -> V_24 -> V_66 && ! F_62 ( V_7 ) ) {
if ( V_65 && F_63 ( V_7 ) )
return - V_44 ;
if ( V_65 && V_7 -> V_64 &&
F_63 ( V_7 -> V_64 ) )
return - V_44 ;
V_25 = V_7 -> V_24 -> V_66 ( V_7 , V_65 ) ;
F_64 ( V_7 -> V_24 -> V_66 , V_25 ) ;
if ( ( V_25 == 0 && V_65 && F_63 ( V_7 ) ) ||
( V_25 == 0 && V_65 && V_7 -> V_64 &&
F_63 ( V_7 -> V_64 ) ) ) {
if ( V_7 -> V_24 -> V_67 )
V_7 -> V_24 -> V_67 ( V_7 , false ) ;
V_25 = - V_44 ;
}
if ( V_25 )
return V_25 ;
}
if ( ! V_7 -> V_68 )
F_65 ( V_1 -> V_35 ) ;
F_44 ( V_1 ) ;
return V_25 ;
}
static int F_66 ( struct V_63 * V_18 , int V_69 )
{
struct V_1 * V_1 = F_58 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
int V_25 ;
if ( F_59 ( V_7 ) ||
( V_7 -> V_64 &&
F_59 ( V_7 -> V_64 ) ) ) {
F_11 ( V_18 , L_10 ) ;
return 0 ;
}
V_25 = F_20 ( V_1 ) ;
if ( V_25 < 0 ) {
F_21 ( V_18 , L_11 , V_25 ) ;
return V_25 ;
}
F_31 ( V_1 ) ;
if ( V_7 -> V_24 -> V_67 && ! F_62 ( V_7 ) ) {
if ( V_1 -> V_3 == V_20 && V_69 != V_70 )
F_2 ( V_1 , V_7 ,
F_16 ) ;
V_25 = V_7 -> V_24 -> V_67 ( V_7 ,
V_69 == V_71 ) ;
if ( V_25 ) {
F_21 ( V_18 , L_12 , V_25 ) ;
if ( V_7 -> V_64 )
F_67 ( V_7 -> V_64 ) ;
F_67 ( V_7 ) ;
}
}
return V_25 ;
}
static int F_68 ( struct V_63 * V_18 )
{
return F_61 ( V_18 , F_69 ( V_18 ) ) ;
}
static int F_70 ( struct V_63 * V_18 )
{
struct V_1 * V_1 = F_58 ( V_18 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
int V_25 ;
V_25 = F_57 ( V_18 ) ;
if ( V_25 )
return V_25 ;
F_71 ( V_1 ) ;
if ( F_62 ( V_7 ) )
F_72 ( V_18 , 0 ) ;
F_11 ( V_18 , L_13 , F_69 ( V_18 ) ) ;
V_25 = F_73 ( V_1 ) ;
if ( V_25 == - V_72 ) {
F_11 ( V_18 , L_14 ) ;
V_25 = 0 ;
} else if ( V_25 == 0 ) {
F_11 ( V_18 , L_15 ,
F_74 ( V_1 -> V_30 ) ) ;
} else {
F_64 ( F_73 , V_25 ) ;
return V_25 ;
}
F_53 ( V_1 , 0 ) ;
return V_25 ;
}
static int F_75 ( struct V_63 * V_18 )
{
struct V_1 * V_1 = F_58 ( V_18 ) ;
F_53 ( V_1 , 1 ) ;
F_76 ( V_1 ) ;
return 0 ;
}
static int F_77 ( struct V_63 * V_18 )
{
return F_66 ( V_18 , V_73 ) ;
}
static int F_78 ( struct V_63 * V_18 )
{
return F_66 ( V_18 , V_71 ) ;
}
static int F_79 ( struct V_63 * V_18 )
{
int V_25 ;
V_25 = F_61 ( V_18 , true ) ;
if ( V_25 == 0 )
F_53 ( F_58 ( V_18 ) , 0 ) ;
F_11 ( V_18 , L_16 , V_25 ) ;
return V_25 ;
}
static int F_80 ( struct V_63 * V_18 )
{
int V_25 ;
F_53 ( F_58 ( V_18 ) , 1 ) ;
V_25 = F_66 ( V_18 , V_70 ) ;
F_11 ( V_18 , L_17 , V_25 ) ;
return V_25 ;
}
