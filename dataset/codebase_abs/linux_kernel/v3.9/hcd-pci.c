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
int V_30 = 0 ;
if ( F_15 () )
return - V_31 ;
if ( ! V_26 )
return - V_32 ;
V_28 = (struct V_27 * ) V_26 -> V_33 ;
if ( ! V_28 )
return - V_32 ;
if ( F_16 ( V_16 ) < 0 )
return - V_31 ;
V_16 -> V_34 = V_35 ;
if ( ( V_28 -> V_36 & V_37 ) != V_38 ) {
if ( ! V_16 -> V_39 ) {
F_17 ( & V_16 -> V_16 ,
L_2 ,
F_18 ( V_16 ) ) ;
V_29 = - V_31 ;
goto V_40;
}
V_30 = V_16 -> V_39 ;
}
V_4 = F_19 ( V_28 , & V_16 -> V_16 , F_18 ( V_16 ) ) ;
if ( ! V_4 ) {
V_29 = - V_41 ;
goto V_40;
}
if ( V_28 -> V_36 & V_42 ) {
V_4 -> V_43 = F_20 ( V_16 , 0 ) ;
V_4 -> V_44 = F_21 ( V_16 , 0 ) ;
if ( ! F_22 ( V_4 -> V_43 , V_4 -> V_44 ,
V_28 -> V_45 ) ) {
F_5 ( & V_16 -> V_16 , L_3 ) ;
V_29 = - V_46 ;
goto V_47;
}
V_4 -> V_48 = F_23 ( V_4 -> V_43 , V_4 -> V_44 ) ;
if ( V_4 -> V_48 == NULL ) {
F_5 ( & V_16 -> V_16 , L_4 ) ;
V_29 = - V_49 ;
goto V_50;
}
} else {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
if ( ! ( F_24 ( V_16 , V_51 ) &
V_53 ) )
continue;
V_4 -> V_43 = F_20 ( V_16 , V_51 ) ;
V_4 -> V_44 = F_21 ( V_16 , V_51 ) ;
if ( F_25 ( V_4 -> V_43 , V_4 -> V_44 ,
V_28 -> V_45 ) )
break;
}
if ( V_51 == V_52 ) {
F_5 ( & V_16 -> V_16 , L_5 ) ;
V_29 = - V_46 ;
goto V_47;
}
}
F_26 ( V_16 ) ;
V_29 = F_27 ( V_4 , V_30 , V_54 ) ;
if ( V_29 != 0 )
goto V_55;
F_8 ( V_16 , V_4 ) ;
if ( F_28 ( V_16 ) )
F_29 ( & V_16 -> V_16 ) ;
return V_29 ;
V_55:
if ( V_28 -> V_36 & V_42 ) {
F_30 ( V_4 -> V_48 ) ;
V_50:
V_50 ( V_4 -> V_43 , V_4 -> V_44 ) ;
} else
F_31 ( V_4 -> V_43 , V_4 -> V_44 ) ;
V_47:
F_12 ( V_16 , V_4 ) ;
F_32 ( V_4 ) ;
V_40:
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
if ( V_4 -> V_28 -> V_36 & V_42 ) {
F_30 ( V_4 -> V_48 ) ;
V_50 ( V_4 -> V_43 , V_4 -> V_44 ) ;
} else {
F_31 ( V_4 -> V_43 , V_4 -> V_44 ) ;
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
if ( F_41 ( V_56 , & V_4 -> V_36 ) &&
V_4 -> V_28 -> V_57 ) {
V_4 -> V_28 -> V_57 ( V_4 ) ;
F_33 ( V_16 ) ;
}
}
static void F_42 ( struct V_1 * V_1 , int V_58 )
{
if ( F_43 ( V_59 ) ) {
struct V_60 * V_61 ;
V_61 = F_44 ( V_1 ) ;
if ( V_61 )
F_45 ( V_62 ,
V_61 , 0 , V_58 ) ;
}
}
static inline void F_42 ( struct V_1 * V_1 , int V_58 )
{}
static int F_46 ( struct V_63 * V_16 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
if ( F_48 ( V_4 ) ) {
F_49 ( V_16 , L_7 ) ;
return - V_46 ;
}
if ( V_4 -> V_64 ) {
V_4 = V_4 -> V_64 ;
if ( F_48 ( V_4 ) ) {
F_49 ( V_16 , L_8 ) ;
return - V_46 ;
}
}
return 0 ;
}
static int F_50 ( struct V_63 * V_16 , bool V_65 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
int V_29 ;
V_29 = F_46 ( V_16 ) ;
if ( V_29 )
return V_29 ;
if ( V_4 -> V_28 -> V_66 && ! F_51 ( V_4 ) ) {
if ( V_65 && F_52 ( V_4 ) )
return - V_46 ;
if ( V_65 && V_4 -> V_64 &&
F_52 ( V_4 -> V_64 ) )
return - V_46 ;
V_29 = V_4 -> V_28 -> V_66 ( V_4 , V_65 ) ;
F_53 ( V_4 -> V_28 -> V_66 , V_29 ) ;
if ( ( V_29 == 0 && V_65 && F_52 ( V_4 ) ) ||
( V_29 == 0 && V_65 && V_4 -> V_64 &&
F_52 ( V_4 -> V_64 ) ) ) {
if ( V_4 -> V_28 -> V_67 )
V_4 -> V_28 -> V_67 ( V_4 , false ) ;
V_29 = - V_46 ;
}
if ( V_29 )
return V_29 ;
}
if ( ! V_4 -> V_68 )
F_54 ( V_1 -> V_39 ) ;
F_33 ( V_1 ) ;
return V_29 ;
}
static int F_55 ( struct V_63 * V_16 , int V_69 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
int V_29 ;
if ( F_48 ( V_4 ) ||
( V_4 -> V_64 &&
F_48 ( V_4 -> V_64 ) ) ) {
F_5 ( V_16 , L_9 ) ;
return 0 ;
}
V_29 = F_16 ( V_1 ) ;
if ( V_29 < 0 ) {
F_17 ( V_16 , L_10 , V_29 ) ;
return V_29 ;
}
F_26 ( V_1 ) ;
if ( V_4 -> V_28 -> V_67 && ! F_51 ( V_4 ) ) {
if ( V_69 != V_70 )
F_13 ( V_1 , V_4 ) ;
V_29 = V_4 -> V_28 -> V_67 ( V_4 ,
V_69 == V_71 ) ;
if ( V_29 ) {
F_17 ( V_16 , L_11 , V_29 ) ;
if ( V_4 -> V_64 )
F_56 ( V_4 -> V_64 ) ;
F_56 ( V_4 ) ;
}
}
return V_29 ;
}
static int F_57 ( struct V_63 * V_16 )
{
return F_50 ( V_16 , F_58 ( V_16 ) ) ;
}
static int F_59 ( struct V_63 * V_16 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
struct V_3 * V_4 = F_4 ( V_1 ) ;
int V_29 ;
V_29 = F_46 ( V_16 ) ;
if ( V_29 )
return V_29 ;
F_60 ( V_1 ) ;
if ( F_51 ( V_4 ) )
F_61 ( V_16 , 0 ) ;
F_5 ( V_16 , L_12 , F_58 ( V_16 ) ) ;
V_29 = F_62 ( V_1 ) ;
if ( V_29 == - V_72 ) {
F_5 ( V_16 , L_13 ) ;
V_29 = 0 ;
} else if ( V_29 == 0 ) {
F_5 ( V_16 , L_14 ,
F_63 ( V_1 -> V_34 ) ) ;
} else {
F_53 ( F_62 , V_29 ) ;
return V_29 ;
}
F_42 ( V_1 , 0 ) ;
return V_29 ;
}
static int F_64 ( struct V_63 * V_16 )
{
struct V_1 * V_1 = F_47 ( V_16 ) ;
F_42 ( V_1 , 1 ) ;
F_65 ( V_1 ) ;
return 0 ;
}
static int F_66 ( struct V_63 * V_16 )
{
return F_55 ( V_16 , V_73 ) ;
}
static int F_67 ( struct V_63 * V_16 )
{
return F_55 ( V_16 , V_71 ) ;
}
static int F_68 ( struct V_63 * V_16 )
{
int V_29 ;
V_29 = F_50 ( V_16 , true ) ;
if ( V_29 == 0 )
F_42 ( F_47 ( V_16 ) , 0 ) ;
F_5 ( V_16 , L_15 , V_29 ) ;
return V_29 ;
}
static int F_69 ( struct V_63 * V_16 )
{
int V_29 ;
F_42 ( F_47 ( V_16 ) , 1 ) ;
V_29 = F_55 ( V_16 , V_70 ) ;
F_5 ( V_16 , L_16 , V_29 ) ;
return V_29 ;
}
