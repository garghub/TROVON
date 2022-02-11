static inline int F_1 ( struct V_1 * V_1 ,
unsigned long V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
if ( V_5 == NULL )
return 0 ;
if ( ! V_3 ) {
if ( ! V_2 || F_3 ( V_5 -> V_6 + V_2 , V_7 ) )
return 0 ;
}
return 1 ;
}
static int F_4 ( struct V_8 * V_9 , struct V_1 * V_1 )
{
struct V_1 * V_10 = V_1 ;
struct V_11 V_11 = { . V_9 = V_9 , . V_1 = V_1 } ;
int V_12 = 1 ;
F_5 ( L_1 ,
V_1 , ( int ) V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
F_6 ( & V_11 ) ;
if ( ! F_7 ( & V_11 ) )
goto V_16;
if ( F_8 ( V_11 . V_1 ) ) {
struct V_17 * V_18 = F_9 ( V_11 . V_1 -> V_19 ) ;
if ( F_10 ( V_18 -> type ) )
goto V_16;
}
if ( ! F_11 ( V_11 . V_9 ) ) {
struct V_4 * V_5 = F_2 ( V_10 ) ;
V_5 -> V_6 = V_20 ;
goto V_16;
}
V_12 = 0 ;
V_16:
F_5 ( L_2 , V_12 ) ;
F_12 ( & V_11 ) ;
return V_12 ;
}
static struct V_1 * F_13 ( struct V_1 * V_21 ,
struct V_1 * V_22 )
{
struct V_17 * V_18 = F_9 ( V_22 -> V_19 ) ;
struct V_23 * V_24 ;
struct V_1 * V_25 ;
F_14 ( & V_18 -> V_26 ) ;
F_14 ( & V_22 -> V_27 ) ;
if ( V_21 )
V_24 = V_21 -> V_28 . V_29 . V_24 ;
else {
V_21 = F_15 ( V_22 ) ;
V_24 = V_21 -> V_30 . V_24 ;
}
V_31:
if ( V_24 == & V_22 -> V_30 ) {
F_16 ( & V_22 -> V_27 ) ;
F_16 ( & V_18 -> V_26 ) ;
F_17 ( V_21 ) ;
return NULL ;
}
V_25 = F_18 ( V_24 , struct V_1 , V_28 . V_29 ) ;
F_19 ( & V_25 -> V_27 , V_32 ) ;
if ( ! F_20 ( V_25 ) || ! F_21 ( V_25 ) ) {
F_16 ( & V_25 -> V_27 ) ;
V_24 = V_25 -> V_28 . V_29 . V_24 ;
goto V_31;
}
F_15 ( V_25 ) ;
F_16 ( & V_25 -> V_27 ) ;
F_16 ( & V_22 -> V_27 ) ;
F_16 ( & V_18 -> V_26 ) ;
F_17 ( V_21 ) ;
return V_25 ;
}
static struct V_1 * F_22 ( struct V_1 * V_21 ,
struct V_1 * V_22 )
{
struct V_17 * V_18 = F_9 ( V_22 -> V_19 ) ;
struct V_23 * V_24 ;
struct V_1 * V_33 , * V_34 ;
if ( V_21 == NULL )
return F_23 ( V_22 ) ;
F_14 ( & V_18 -> V_26 ) ;
V_35:
V_33 = V_21 ;
F_14 ( & V_33 -> V_27 ) ;
V_36:
V_24 = V_33 -> V_30 . V_24 ;
if ( V_24 == & V_33 -> V_30 ) {
while ( 1 ) {
struct V_1 * V_37 ;
if ( V_33 == V_22 ) {
F_16 ( & V_33 -> V_27 ) ;
F_16 ( & V_18 -> V_26 ) ;
F_17 ( V_21 ) ;
return NULL ;
}
V_37 = V_33 -> V_38 ;
if ( ! F_24 ( & V_37 -> V_27 ) ) {
F_16 ( & V_33 -> V_27 ) ;
F_25 () ;
goto V_35;
}
F_16 ( & V_33 -> V_27 ) ;
V_24 = V_33 -> V_28 . V_29 . V_24 ;
V_33 = V_37 ;
if ( V_24 != & V_37 -> V_30 )
break;
}
}
V_34 = F_18 ( V_24 , struct V_1 , V_28 . V_29 ) ;
F_19 ( & V_34 -> V_27 , V_32 ) ;
if ( ! F_21 ( V_34 ) ) {
F_16 ( & V_33 -> V_27 ) ;
F_26 ( & V_34 -> V_27 . V_39 , 0 , V_40 ) ;
V_33 = V_34 ;
goto V_36;
}
F_15 ( V_34 ) ;
F_16 ( & V_34 -> V_27 ) ;
F_16 ( & V_33 -> V_27 ) ;
F_16 ( & V_18 -> V_26 ) ;
F_17 ( V_21 ) ;
return V_34 ;
}
static int F_27 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
unsigned long V_2 ,
int V_3 )
{
F_5 ( L_3 ,
V_10 , ( int ) V_10 -> V_13 . V_14 , V_10 -> V_13 . V_15 ) ;
if ( ! F_11 ( V_9 ) ) {
struct V_4 * V_5 = F_2 ( V_10 ) ;
if ( V_5 )
V_5 -> V_6 = V_20 ;
return 1 ;
}
if ( ! F_1 ( V_10 , V_2 , V_3 ) )
return 1 ;
return 0 ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
unsigned long V_2 ,
int V_3 )
{
struct V_4 * V_41 = F_2 ( V_10 ) ;
struct V_1 * V_33 ;
F_5 ( L_3 ,
V_10 , ( int ) V_10 -> V_13 . V_14 , V_10 -> V_13 . V_15 ) ;
if ( ! F_21 ( V_10 ) )
return 1 ;
V_33 = NULL ;
while ( ( V_33 = F_22 ( V_33 , V_10 ) ) ) {
F_5 ( L_1 ,
V_33 , ( int ) V_33 -> V_13 . V_14 , V_33 -> V_13 . V_15 ) ;
if ( F_29 ( V_33 ) ) {
if ( F_4 ( V_9 , V_33 ) ) {
V_41 -> V_6 = V_20 ;
F_17 ( V_33 ) ;
return 1 ;
}
} else {
struct V_4 * V_5 = F_2 ( V_33 ) ;
unsigned int V_42 = F_30 ( & V_5 -> V_43 ) ;
if ( V_33 == V_10 )
V_42 += 2 ;
else
V_42 ++ ;
if ( F_20 ( V_33 ) > V_42 ) {
V_41 -> V_6 = V_20 ;
F_17 ( V_33 ) ;
return 1 ;
}
}
}
if ( ! F_1 ( V_10 , V_2 , V_3 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_31 ( struct V_8 * V_9 ,
struct V_1 * V_37 ,
unsigned long V_2 ,
int V_3 )
{
struct V_1 * V_33 ;
F_5 ( L_4 ,
V_37 , ( int ) V_37 -> V_13 . V_14 , V_37 -> V_13 . V_15 ) ;
V_33 = NULL ;
while ( ( V_33 = F_22 ( V_33 , V_37 ) ) ) {
F_5 ( L_1 ,
V_33 , ( int ) V_33 -> V_13 . V_14 , V_33 -> V_13 . V_15 ) ;
if ( F_29 ( V_33 ) ) {
if ( F_4 ( V_9 , V_33 ) )
continue;
if ( F_1 ( V_33 , V_2 , V_3 ) )
return V_33 ;
}
}
return NULL ;
}
struct V_1 * F_32 ( struct V_44 * V_45 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
int V_46 )
{
unsigned long V_2 ;
struct V_1 * V_22 = F_23 ( V_45 -> V_47 ) ;
int V_3 = V_46 & V_48 ;
struct V_4 * V_5 ;
if ( ! V_22 )
return NULL ;
V_7 = V_20 ;
V_2 = V_18 -> V_49 ;
F_14 ( & V_18 -> V_50 ) ;
V_5 = F_2 ( V_22 ) ;
if ( V_5 -> V_51 & V_52 )
goto V_53;
if ( ! F_27 ( V_9 , V_22 , V_2 , V_3 ) ) {
V_5 -> V_51 |= V_54 ;
F_16 ( & V_18 -> V_50 ) ;
F_33 () ;
F_14 ( & V_18 -> V_50 ) ;
if ( ! F_27 ( V_9 , V_22 , V_2 , V_3 ) ) {
V_5 -> V_51 |= V_55 ;
F_34 () ;
V_5 -> V_51 &= ~ V_54 ;
F_35 ( & V_5 -> V_56 ) ;
F_16 ( & V_18 -> V_50 ) ;
return V_22 ;
}
V_5 -> V_51 &= ~ V_54 ;
}
V_53:
F_16 ( & V_18 -> V_50 ) ;
F_17 ( V_22 ) ;
return NULL ;
}
static struct V_1 * F_36 ( struct V_1 * V_1 ,
struct V_8 * V_9 ,
unsigned long V_2 ,
int V_46 )
{
int V_3 = V_46 & V_48 ;
int V_57 = V_46 & V_58 ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned int V_42 ;
if ( V_5 -> V_51 & V_52 )
return NULL ;
if ( F_29 ( V_1 ) ) {
F_5 ( L_5 ,
V_1 , ( int ) V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
if ( F_4 ( V_9 , V_1 ) )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) )
return V_1 ;
return NULL ;
}
if ( V_1 -> V_59 && F_37 ( V_1 -> V_59 -> V_60 ) ) {
F_5 ( L_6 ,
V_1 , ( int ) V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
if ( F_1 ( V_1 , V_2 , V_3 ) )
return V_1 ;
return NULL ;
}
if ( F_38 ( V_1 ) )
return NULL ;
if ( ! V_57 ) {
V_42 = F_30 ( & V_5 -> V_43 ) + 1 ;
if ( F_20 ( V_1 ) > V_42 )
return NULL ;
if ( ! F_28 ( V_9 , V_1 , V_2 , V_3 ) )
return V_1 ;
} else {
struct V_1 * V_61 ;
V_42 = F_30 ( & V_5 -> V_43 ) + 1 ;
if ( F_20 ( V_1 ) > V_42 )
return NULL ;
V_61 = F_31 ( V_9 , V_1 , V_2 , V_3 ) ;
if ( V_61 ) {
if ( V_61 == V_1 )
F_17 ( V_1 ) ;
return V_61 ;
}
}
return NULL ;
}
struct V_1 * F_39 ( struct V_44 * V_45 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
int V_46 )
{
unsigned long V_2 ;
struct V_1 * V_22 = V_45 -> V_47 ;
struct V_1 * V_1 ;
struct V_1 * V_61 ;
struct V_4 * V_5 ;
if ( ! V_22 )
return NULL ;
V_7 = V_20 ;
V_2 = V_18 -> V_49 ;
V_1 = NULL ;
while ( ( V_1 = F_13 ( V_1 , V_22 ) ) ) {
F_14 ( & V_18 -> V_50 ) ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 -> V_51 & V_54 )
V_61 = NULL ;
else
V_61 = F_36 ( V_1 , V_9 , V_2 , V_46 ) ;
if ( ! V_61 ) {
F_16 ( & V_18 -> V_50 ) ;
continue;
}
V_5 = F_2 ( V_61 ) ;
V_5 -> V_51 |= V_54 ;
F_16 ( & V_18 -> V_50 ) ;
F_33 () ;
F_14 ( & V_18 -> V_50 ) ;
if ( F_36 ( V_61 , V_9 , V_2 , V_46 ) ) {
if ( V_61 != V_1 )
F_17 ( V_1 ) ;
goto V_62;
}
V_5 -> V_51 &= ~ V_54 ;
if ( V_61 != V_1 )
F_17 ( V_61 ) ;
F_16 ( & V_18 -> V_50 ) ;
}
return NULL ;
V_62:
F_5 ( L_7 ,
V_61 , ( int ) V_61 -> V_13 . V_14 , V_61 -> V_13 . V_15 ) ;
V_5 -> V_51 |= V_55 ;
F_34 () ;
V_5 -> V_51 &= ~ V_54 ;
F_35 ( & V_5 -> V_56 ) ;
F_16 ( & V_18 -> V_50 ) ;
F_14 ( & V_18 -> V_26 ) ;
F_14 ( & V_61 -> V_38 -> V_27 ) ;
F_19 ( & V_61 -> V_27 , V_32 ) ;
F_40 ( & V_61 -> V_38 -> V_30 , & V_61 -> V_28 . V_29 ) ;
F_16 ( & V_61 -> V_27 ) ;
F_16 ( & V_61 -> V_38 -> V_27 ) ;
F_16 ( & V_18 -> V_26 ) ;
return V_61 ;
}
int F_41 ( struct V_1 * V_1 , int V_63 )
{
struct V_17 * V_18 = F_9 ( V_1 -> V_19 ) ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
int V_12 ;
if ( ! ( V_5 -> V_51 & ( V_55 | V_54 ) ) )
return 0 ;
if ( V_63 )
return - V_64 ;
F_14 ( & V_18 -> V_50 ) ;
if ( V_5 -> V_51 & V_55 ) {
F_16 ( & V_18 -> V_50 ) ;
F_5 ( L_8 ,
V_1 , V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
V_12 = F_42 ( V_18 , V_1 , V_65 ) ;
F_43 ( & V_5 -> V_56 ) ;
F_5 ( L_9 , V_12 ) ;
if ( F_44 ( V_1 ) )
return - V_66 ;
return V_12 ;
}
F_16 ( & V_18 -> V_50 ) ;
return 0 ;
}
int F_45 ( struct V_44 * V_45 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
struct V_67 T_1 * V_68 )
{
struct V_67 V_69 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_34 = 0 ;
memset ( & V_69 , 0 , sizeof V_69 ) ;
V_69 . V_70 . V_71 = V_18 -> V_72 ;
V_69 . V_70 . type = V_73 ;
if ( ( V_1 = F_39 ( V_45 , V_9 , V_18 , 0 ) ) == NULL )
return - V_66 ;
V_69 . V_14 = V_1 -> V_13 . V_14 ;
memcpy ( V_69 . V_15 , V_1 -> V_13 . V_15 , V_69 . V_14 ) ;
V_69 . V_15 [ V_69 . V_14 ] = '\0' ;
F_17 ( V_1 ) ;
if ( F_46 ( V_68 , & V_69 , sizeof( struct V_67 ) ) )
V_34 = - V_74 ;
F_14 ( & V_18 -> V_50 ) ;
V_5 = F_2 ( V_1 ) ;
V_5 -> V_6 = V_7 ;
V_5 -> V_51 &= ~ V_55 ;
F_47 ( & V_5 -> V_56 ) ;
F_16 ( & V_18 -> V_50 ) ;
return V_34 ;
}
int F_48 ( struct V_44 * V_45 , struct V_8 * V_9 ,
struct V_17 * V_18 , int V_75 )
{
struct V_1 * V_1 ;
int V_34 = - V_66 ;
if ( F_49 ( V_18 -> type ) )
V_1 = F_32 ( V_45 , V_9 , V_18 , V_75 ) ;
else
V_1 = F_39 ( V_45 , V_9 , V_18 , V_75 ) ;
if ( V_1 ) {
struct V_4 * V_5 = F_2 ( V_1 ) ;
V_34 = F_42 ( V_18 , V_1 , V_76 ) ;
F_14 ( & V_18 -> V_50 ) ;
V_5 -> V_6 = V_7 ;
V_5 -> V_51 &= ~ V_55 ;
F_47 ( & V_5 -> V_56 ) ;
F_16 ( & V_18 -> V_50 ) ;
F_17 ( V_1 ) ;
}
return V_34 ;
}
int F_50 ( struct V_44 * V_45 , struct V_8 * V_9 ,
struct V_17 * V_18 , int T_1 * V_77 )
{
int V_3 = 0 ;
if ( V_77 && F_51 ( V_3 , V_77 ) )
return - V_74 ;
return F_48 ( V_45 , V_9 , V_18 , V_3 ) ;
}
