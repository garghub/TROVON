static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_7 ;
struct V_3 * V_8 ;
unsigned int V_9 = F_2 ( V_2 -> V_10 ) ;
V_7 = NULL ;
F_3 (companion) {
if ( V_7 -> V_11 != V_2 -> V_11 ||
F_2 ( V_7 -> V_10 ) != V_9 )
continue;
V_8 = F_4 ( V_7 ) ;
if ( ! V_8 )
continue;
if ( ( V_2 -> V_12 == V_13 || V_2 -> V_12 == V_14 ) &&
V_7 -> V_12 == V_15 ) {
F_5 ( & V_7 -> V_16 , L_1 ,
F_6 ( & V_2 -> V_16 ) ) ;
V_4 -> V_17 . V_18 = & V_8 -> V_17 ;
} else if ( V_2 -> V_12 == V_15 &&
( V_7 -> V_12 == V_13 ||
V_7 -> V_12 == V_14 ) ) {
switch ( V_6 ) {
case V_19 :
F_5 ( & V_2 -> V_16 , L_1 ,
F_6 ( & V_7 -> V_16 ) ) ;
V_8 -> V_17 . V_18 = & V_4 -> V_17 ;
break;
case V_20 :
V_8 -> V_17 . V_18 = NULL ;
break;
case V_21 :
F_7 ( & V_2 -> V_16 ,
& V_7 -> V_16 ) ;
break;
}
}
}
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_9 ( & V_22 ) ;
F_10 ( & V_2 -> V_16 , V_4 ) ;
F_1 ( V_2 , V_4 , V_19 ) ;
F_11 ( & V_22 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_9 ( & V_22 ) ;
F_10 ( & V_2 -> V_16 , NULL ) ;
if ( V_2 -> V_12 == V_13 || V_2 -> V_12 == V_14 )
V_4 -> V_17 . V_18 = NULL ;
else
F_1 ( V_2 , V_4 , V_20 ) ;
F_11 ( & V_22 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_12 == V_15 )
F_1 ( V_2 , V_4 , V_21 ) ;
}
static inline void F_8 ( struct V_1 * V_23 , struct V_3 * V_24 ) {}
static inline void F_12 ( struct V_1 * V_23 , struct V_3 * V_24 ) {}
static inline void F_13 ( struct V_1 * V_23 , struct V_3 * V_24 ) {}
int F_14 ( struct V_1 * V_16 , const struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_3 * V_4 ;
int V_29 ;
if ( F_15 () )
return - V_30 ;
if ( ! V_26 )
return - V_31 ;
V_28 = (struct V_27 * ) V_26 -> V_32 ;
if ( ! V_28 )
return - V_31 ;
if ( F_16 ( V_16 ) < 0 )
return - V_30 ;
V_16 -> V_33 = V_34 ;
if ( ! V_16 -> V_35 && ( V_28 -> V_36 & V_37 ) != V_38 ) {
F_17 ( & V_16 -> V_16 ,
L_2 ,
F_18 ( V_16 ) ) ;
V_29 = - V_30 ;
goto V_39;
}
V_4 = F_19 ( V_28 , & V_16 -> V_16 , F_18 ( V_16 ) ) ;
if ( ! V_4 ) {
V_29 = - V_40 ;
goto V_39;
}
if ( V_28 -> V_36 & V_41 ) {
V_4 -> V_42 = F_20 ( V_16 , 0 ) ;
V_4 -> V_43 = F_21 ( V_16 , 0 ) ;
if ( ! F_22 ( V_4 -> V_42 , V_4 -> V_43 ,
V_28 -> V_44 ) ) {
F_5 ( & V_16 -> V_16 , L_3 ) ;
V_29 = - V_45 ;
goto V_46;
}
V_4 -> V_47 = F_23 ( V_4 -> V_42 , V_4 -> V_43 ) ;
if ( V_4 -> V_47 == NULL ) {
F_5 ( & V_16 -> V_16 , L_4 ) ;
V_29 = - V_48 ;
goto V_49;
}
} else {
int V_50 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
if ( ! ( F_24 ( V_16 , V_50 ) &
V_52 ) )
continue;
V_4 -> V_42 = F_20 ( V_16 , V_50 ) ;
V_4 -> V_43 = F_21 ( V_16 , V_50 ) ;
if ( F_25 ( V_4 -> V_42 , V_4 -> V_43 ,
V_28 -> V_44 ) )
break;
}
if ( V_50 == V_51 ) {
F_5 ( & V_16 -> V_16 , L_5 ) ;
V_29 = - V_45 ;
goto V_46;
}
}
F_26 ( V_16 ) ;
V_29 = F_27 ( V_4 , V_16 -> V_35 , V_53 ) ;
if ( V_29 != 0 )
goto V_54;
F_8 ( V_16 , V_4 ) ;
if ( F_28 ( V_16 ) )
F_29 ( & V_16 -> V_16 ) ;
return V_29 ;
V_54:
if ( V_28 -> V_36 & V_41 ) {
F_30 ( V_4 -> V_47 ) ;
V_49:
V_49 ( V_4 -> V_42 , V_4 -> V_43 ) ;
} else
F_31 ( V_4 -> V_42 , V_4 -> V_43 ) ;
V_46:
F_12 ( V_16 , V_4 ) ;
F_32 ( V_4 ) ;
V_39:
F_33 ( V_16 ) ;
F_17 ( & V_16 -> V_16 , L_6 , F_18 ( V_16 ) , V_29 ) ;
return V_29 ;
}
void F_34 ( struct V_1 * V_16 )
{
struct V_3 * V_4 ;
V_4 = F_4 ( V_16 ) ;
if ( ! V_4 )
return;
if ( F_28 ( V_16 ) )
F_35 ( & V_16 -> V_16 ) ;
F_36 () ;
F_37 ( 0 , V_4 ) ;
F_38 () ;
F_39 ( V_4 ) ;
if ( V_4 -> V_28 -> V_36 & V_41 ) {
F_30 ( V_4 -> V_47 ) ;
V_49 ( V_4 -> V_42 , V_4 -> V_43 ) ;
} else {
F_31 ( V_4 -> V_42 , V_4 -> V_43 ) ;
}
F_12 ( V_16 , V_4 ) ;
F_32 ( V_4 ) ;
F_33 ( V_16 ) ;
}
void F_40 ( struct V_1 * V_16 )
{
struct V_3 * V_4 ;
V_4 = F_4 ( V_16 ) ;
if ( ! V_4 )
return;
if ( F_41 ( V_55 , & V_4 -> V_36 ) &&
V_4 -> V_28 -> V_56 ) {
V_4 -> V_28 -> V_56 ( V_4 ) ;
F_33 ( V_16 ) ;
}
}
static void F_42 ( struct V_1 * V_1 , int V_57 )
{
if ( F_43 ( V_58 ) ) {
struct V_59 * V_60 ;
V_60 = F_44 ( V_1 ) ;
if ( V_60 )
F_45 ( V_61 ,
V_60 , 0 , V_57 ) ;
}
}
static inline void F_42 ( struct V_1 * V_1 , int V_57 )
{}
static int F_46 ( struct V_62 * V_16 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
if ( F_48 ( V_4 ) ) {
F_49 ( V_16 , L_7 ) ;
return - V_45 ;
}
if ( V_4 -> V_63 ) {
V_4 = V_4 -> V_63 ;
if ( F_48 ( V_4 ) ) {
F_49 ( V_16 , L_8 ) ;
return - V_45 ;
}
}
return 0 ;
}
static int F_50 ( struct V_62 * V_16 , bool V_64 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
int V_29 ;
V_29 = F_46 ( V_16 ) ;
if ( V_29 )
return V_29 ;
if ( V_4 -> V_28 -> V_65 && ! F_51 ( V_4 ) ) {
if ( V_64 && F_52 ( V_4 ) )
return - V_45 ;
if ( V_64 && V_4 -> V_63 &&
F_52 ( V_4 -> V_63 ) )
return - V_45 ;
V_29 = V_4 -> V_28 -> V_65 ( V_4 , V_64 ) ;
F_53 ( V_4 -> V_28 -> V_65 , V_29 ) ;
if ( ( V_29 == 0 && V_64 && F_52 ( V_4 ) ) ||
( V_29 == 0 && V_64 && V_4 -> V_63 &&
F_52 ( V_4 -> V_63 ) ) ) {
if ( V_4 -> V_28 -> V_66 )
V_4 -> V_28 -> V_66 ( V_4 , false ) ;
V_29 = - V_45 ;
}
if ( V_29 )
return V_29 ;
}
if ( ! V_4 -> V_67 )
F_54 ( V_1 -> V_35 ) ;
F_33 ( V_1 ) ;
return V_29 ;
}
static int F_55 ( struct V_62 * V_16 , int V_68 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
int V_29 ;
if ( F_48 ( V_4 ) ||
( V_4 -> V_63 &&
F_48 ( V_4 -> V_63 ) ) ) {
F_5 ( V_16 , L_9 ) ;
return 0 ;
}
V_29 = F_16 ( V_1 ) ;
if ( V_29 < 0 ) {
F_17 ( V_16 , L_10 , V_29 ) ;
return V_29 ;
}
F_26 ( V_1 ) ;
if ( V_4 -> V_28 -> V_66 && ! F_51 ( V_4 ) ) {
if ( V_68 != V_69 )
F_13 ( V_1 , V_4 ) ;
V_29 = V_4 -> V_28 -> V_66 ( V_4 ,
V_68 == V_70 ) ;
if ( V_29 ) {
F_17 ( V_16 , L_11 , V_29 ) ;
if ( V_4 -> V_63 )
F_56 ( V_4 -> V_63 ) ;
F_56 ( V_4 ) ;
}
}
return V_29 ;
}
static int F_57 ( struct V_62 * V_16 )
{
return F_50 ( V_16 , F_58 ( V_16 ) ) ;
}
static int F_59 ( struct V_62 * V_16 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
int V_29 ;
V_29 = F_46 ( V_16 ) ;
if ( V_29 )
return V_29 ;
F_60 ( V_1 ) ;
if ( V_4 -> V_71 ) {
F_5 ( V_16 , L_12 ) ;
return V_29 ;
}
if ( F_51 ( V_4 ) )
F_61 ( V_16 , 0 ) ;
F_5 ( V_16 , L_13 , F_58 ( V_16 ) ) ;
V_29 = F_62 ( V_1 ) ;
if ( V_29 == - V_72 ) {
F_5 ( V_16 , L_14 ) ;
V_29 = 0 ;
} else if ( V_29 == 0 ) {
F_5 ( V_16 , L_15 ,
F_63 ( V_1 -> V_33 ) ) ;
} else {
F_53 ( F_62 , V_29 ) ;
return V_29 ;
}
F_42 ( V_1 , 0 ) ;
return V_29 ;
}
static int F_64 ( struct V_62 * V_16 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
F_42 ( V_1 , 1 ) ;
F_65 ( V_1 ) ;
return 0 ;
}
static int F_66 ( struct V_62 * V_16 )
{
return F_55 ( V_16 , V_73 ) ;
}
static int F_67 ( struct V_62 * V_16 )
{
return F_55 ( V_16 , V_70 ) ;
}
static int F_68 ( struct V_62 * V_16 )
{
int V_29 ;
V_29 = F_50 ( V_16 , true ) ;
if ( V_29 == 0 )
F_42 ( F_47 ( V_16 ) , 0 ) ;
F_5 ( V_16 , L_16 , V_29 ) ;
return V_29 ;
}
static int F_69 ( struct V_62 * V_16 )
{
int V_29 ;
F_42 ( F_47 ( V_16 ) , 1 ) ;
V_29 = F_55 ( V_16 , V_69 ) ;
F_5 ( V_16 , L_17 , V_29 ) ;
return V_29 ;
}
