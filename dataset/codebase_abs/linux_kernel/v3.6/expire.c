static inline int F_1 ( struct V_1 * V_1 ,
unsigned long V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
if ( V_5 == NULL )
return 0 ;
if ( ! V_3 ) {
if ( ! V_2 || F_3 ( V_5 -> V_6 + V_2 , V_7 ) )
return 0 ;
V_5 -> V_6 = V_7 ;
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
if ( ! F_11 ( V_11 . V_1 ) ) {
V_12 = 0 ;
goto V_16;
}
}
if ( ! F_12 ( V_11 . V_9 ) ) {
struct V_4 * V_5 = F_2 ( V_10 ) ;
V_5 -> V_6 = V_20 ;
goto V_16;
}
V_12 = 0 ;
V_16:
F_5 ( L_2 , V_12 ) ;
F_13 ( & V_11 ) ;
return V_12 ;
}
static struct V_1 * F_14 ( struct V_1 * V_21 ,
struct V_1 * V_22 )
{
struct V_17 * V_18 = F_9 ( V_22 -> V_19 ) ;
struct V_23 * V_24 ;
struct V_1 * V_25 ;
F_15 ( & V_18 -> V_26 ) ;
F_15 ( & V_22 -> V_27 ) ;
if ( V_21 )
V_24 = V_21 -> V_28 . V_29 . V_24 ;
else {
V_21 = F_16 ( V_22 ) ;
V_24 = V_21 -> V_30 . V_24 ;
}
V_31:
if ( V_24 == & V_22 -> V_30 ) {
F_17 ( & V_22 -> V_27 ) ;
F_17 ( & V_18 -> V_26 ) ;
F_18 ( V_21 ) ;
return NULL ;
}
V_25 = F_19 ( V_24 , struct V_1 , V_28 . V_29 ) ;
F_20 ( & V_25 -> V_27 , V_32 ) ;
if ( V_25 -> V_33 == 0 || ! F_21 ( V_25 ) ) {
F_17 ( & V_25 -> V_27 ) ;
V_24 = V_25 -> V_28 . V_29 . V_24 ;
goto V_31;
}
F_16 ( V_25 ) ;
F_17 ( & V_25 -> V_27 ) ;
F_17 ( & V_22 -> V_27 ) ;
F_17 ( & V_18 -> V_26 ) ;
F_18 ( V_21 ) ;
return V_25 ;
}
static struct V_1 * F_22 ( struct V_1 * V_21 ,
struct V_1 * V_22 )
{
struct V_17 * V_18 = F_9 ( V_22 -> V_19 ) ;
struct V_23 * V_24 ;
struct V_1 * V_34 , * V_35 ;
if ( V_21 == NULL )
return F_23 ( V_22 ) ;
F_15 ( & V_18 -> V_26 ) ;
V_36:
V_34 = V_21 ;
F_15 ( & V_34 -> V_27 ) ;
V_37:
V_24 = V_34 -> V_30 . V_24 ;
if ( V_24 == & V_34 -> V_30 ) {
while ( 1 ) {
struct V_1 * V_38 ;
if ( V_34 == V_22 ) {
F_17 ( & V_34 -> V_27 ) ;
F_17 ( & V_18 -> V_26 ) ;
F_18 ( V_21 ) ;
return NULL ;
}
V_38 = V_34 -> V_39 ;
if ( ! F_24 ( & V_38 -> V_27 ) ) {
F_17 ( & V_34 -> V_27 ) ;
F_25 () ;
goto V_36;
}
F_17 ( & V_34 -> V_27 ) ;
V_24 = V_34 -> V_28 . V_29 . V_24 ;
V_34 = V_38 ;
if ( V_24 != & V_38 -> V_30 )
break;
}
}
V_35 = F_19 ( V_24 , struct V_1 , V_28 . V_29 ) ;
F_20 ( & V_35 -> V_27 , V_32 ) ;
if ( ! F_21 ( V_35 ) ) {
F_17 ( & V_34 -> V_27 ) ;
F_26 ( & V_35 -> V_27 . V_40 , 0 , V_41 ) ;
V_34 = V_35 ;
goto V_37;
}
F_16 ( V_35 ) ;
F_17 ( & V_35 -> V_27 ) ;
F_17 ( & V_34 -> V_27 ) ;
F_17 ( & V_18 -> V_26 ) ;
F_18 ( V_21 ) ;
return V_35 ;
}
static int F_27 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
unsigned long V_2 ,
int V_3 )
{
F_5 ( L_3 ,
V_10 , ( int ) V_10 -> V_13 . V_14 , V_10 -> V_13 . V_15 ) ;
if ( ! F_12 ( V_9 ) ) {
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
struct V_4 * V_42 = F_2 ( V_10 ) ;
struct V_1 * V_34 ;
F_5 ( L_3 ,
V_10 , ( int ) V_10 -> V_13 . V_14 , V_10 -> V_13 . V_15 ) ;
if ( ! F_21 ( V_10 ) )
return 1 ;
V_34 = NULL ;
while ( ( V_34 = F_22 ( V_34 , V_10 ) ) ) {
F_5 ( L_1 ,
V_34 , ( int ) V_34 -> V_13 . V_14 , V_34 -> V_13 . V_15 ) ;
if ( F_11 ( V_34 ) ) {
if ( F_4 ( V_9 , V_34 ) ) {
V_42 -> V_6 = V_20 ;
F_18 ( V_34 ) ;
return 1 ;
}
} else {
struct V_4 * V_5 = F_2 ( V_34 ) ;
unsigned int V_43 = F_29 ( & V_5 -> V_44 ) ;
F_30 ( V_34 ) ;
if ( V_34 == V_10 )
V_43 += 2 ;
else
V_43 ++ ;
if ( V_34 -> V_33 > V_43 ) {
V_42 -> V_6 = V_20 ;
F_18 ( V_34 ) ;
return 1 ;
}
}
}
if ( ! F_1 ( V_10 , V_2 , V_3 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_31 ( struct V_8 * V_9 ,
struct V_1 * V_38 ,
unsigned long V_2 ,
int V_3 )
{
struct V_1 * V_34 ;
F_5 ( L_4 ,
V_38 , ( int ) V_38 -> V_13 . V_14 , V_38 -> V_13 . V_15 ) ;
V_34 = NULL ;
while ( ( V_34 = F_22 ( V_34 , V_38 ) ) ) {
F_5 ( L_1 ,
V_34 , ( int ) V_34 -> V_13 . V_14 , V_34 -> V_13 . V_15 ) ;
if ( F_11 ( V_34 ) ) {
if ( F_4 ( V_9 , V_34 ) )
continue;
if ( F_1 ( V_34 , V_2 , V_3 ) )
return V_34 ;
}
}
return NULL ;
}
struct V_1 * F_32 ( struct V_45 * V_46 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
int V_47 )
{
unsigned long V_2 ;
struct V_1 * V_22 = F_23 ( V_46 -> V_48 ) ;
int V_3 = V_47 & V_49 ;
struct V_4 * V_5 ;
if ( ! V_22 )
return NULL ;
V_7 = V_20 ;
V_2 = V_18 -> V_50 ;
F_15 ( & V_18 -> V_51 ) ;
V_5 = F_2 ( V_22 ) ;
if ( V_5 -> V_52 & V_53 )
goto V_54;
if ( ! F_27 ( V_9 , V_22 , V_2 , V_3 ) ) {
struct V_4 * V_5 = F_2 ( V_22 ) ;
V_5 -> V_52 |= V_55 ;
F_33 ( & V_5 -> V_56 ) ;
F_17 ( & V_18 -> V_51 ) ;
return V_22 ;
}
V_54:
F_17 ( & V_18 -> V_51 ) ;
F_18 ( V_22 ) ;
return NULL ;
}
struct V_1 * F_34 ( struct V_45 * V_46 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
int V_47 )
{
unsigned long V_2 ;
struct V_1 * V_22 = V_46 -> V_48 ;
struct V_1 * V_1 ;
struct V_1 * V_57 = NULL ;
int V_3 = V_47 & V_49 ;
int V_58 = V_47 & V_59 ;
struct V_4 * V_5 ;
unsigned int V_43 ;
if ( ! V_22 )
return NULL ;
V_7 = V_20 ;
V_2 = V_18 -> V_50 ;
V_1 = NULL ;
while ( ( V_1 = F_14 ( V_1 , V_22 ) ) ) {
F_15 ( & V_18 -> V_51 ) ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 -> V_52 & V_53 )
goto V_24;
if ( F_11 ( V_1 ) ) {
F_5 ( L_5 ,
V_1 , ( int ) V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
if ( F_4 ( V_9 , V_1 ) )
goto V_24;
if ( F_1 ( V_1 , V_2 , V_3 ) ) {
V_57 = V_1 ;
goto V_60;
}
goto V_24;
}
if ( F_35 ( V_1 ) )
goto V_24;
if ( ! V_58 ) {
V_43 = F_29 ( & V_5 -> V_44 ) + 1 ;
if ( V_1 -> V_33 > V_43 )
goto V_24;
if ( ! F_28 ( V_9 , V_1 , V_2 , V_3 ) ) {
V_57 = V_1 ;
goto V_60;
}
} else {
V_43 = F_29 ( & V_5 -> V_44 ) + 1 ;
if ( V_1 -> V_33 > V_43 )
goto V_24;
V_57 = F_31 ( V_9 , V_1 , V_2 , V_3 ) ;
if ( V_57 ) {
F_18 ( V_1 ) ;
goto V_60;
}
}
V_24:
F_17 ( & V_18 -> V_51 ) ;
}
return NULL ;
V_60:
F_5 ( L_6 ,
V_57 , ( int ) V_57 -> V_13 . V_14 , V_57 -> V_13 . V_15 ) ;
V_5 = F_2 ( V_57 ) ;
V_5 -> V_52 |= V_55 ;
F_33 ( & V_5 -> V_56 ) ;
F_17 ( & V_18 -> V_51 ) ;
F_15 ( & V_18 -> V_26 ) ;
F_15 ( & V_57 -> V_39 -> V_27 ) ;
F_20 ( & V_57 -> V_27 , V_32 ) ;
F_36 ( & V_57 -> V_39 -> V_30 , & V_57 -> V_28 . V_29 ) ;
F_17 ( & V_57 -> V_27 ) ;
F_17 ( & V_57 -> V_39 -> V_27 ) ;
F_17 ( & V_18 -> V_26 ) ;
return V_57 ;
}
int F_37 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = F_9 ( V_1 -> V_19 ) ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
int V_12 ;
F_15 ( & V_18 -> V_51 ) ;
if ( V_5 -> V_52 & V_55 ) {
F_17 ( & V_18 -> V_51 ) ;
F_5 ( L_7 ,
V_1 , V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
V_12 = F_38 ( V_18 , V_1 , V_61 ) ;
F_39 ( & V_5 -> V_56 ) ;
F_5 ( L_8 , V_12 ) ;
if ( F_40 ( V_1 ) )
return - V_62 ;
return V_12 ;
}
F_17 ( & V_18 -> V_51 ) ;
return 0 ;
}
int F_41 ( struct V_45 * V_46 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
struct V_63 T_1 * V_64 )
{
struct V_63 V_65 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_35 = 0 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_66 . V_67 = V_18 -> V_68 ;
V_65 . V_66 . type = V_69 ;
if ( ( V_1 = F_34 ( V_46 , V_9 , V_18 , 0 ) ) == NULL )
return - V_62 ;
V_65 . V_14 = V_1 -> V_13 . V_14 ;
memcpy ( V_65 . V_15 , V_1 -> V_13 . V_15 , V_65 . V_14 ) ;
V_65 . V_15 [ V_65 . V_14 ] = '\0' ;
F_18 ( V_1 ) ;
if ( F_42 ( V_64 , & V_65 , sizeof( struct V_63 ) ) )
V_35 = - V_70 ;
F_15 ( & V_18 -> V_51 ) ;
V_5 = F_2 ( V_1 ) ;
V_5 -> V_52 &= ~ V_55 ;
F_43 ( & V_5 -> V_56 ) ;
F_17 ( & V_18 -> V_51 ) ;
return V_35 ;
}
int F_44 ( struct V_45 * V_46 , struct V_8 * V_9 ,
struct V_17 * V_18 , int V_71 )
{
struct V_1 * V_1 ;
int V_35 = - V_62 ;
if ( F_45 ( V_18 -> type ) )
V_1 = F_32 ( V_46 , V_9 , V_18 , V_71 ) ;
else
V_1 = F_34 ( V_46 , V_9 , V_18 , V_71 ) ;
if ( V_1 ) {
struct V_4 * V_5 = F_2 ( V_1 ) ;
V_35 = F_38 ( V_18 , V_1 , V_72 ) ;
F_15 ( & V_18 -> V_51 ) ;
V_5 -> V_52 &= ~ V_55 ;
F_15 ( & V_1 -> V_27 ) ;
if ( ! V_35 ) {
if ( ( F_46 ( V_1 ) ||
( F_10 ( V_18 -> type ) &&
F_46 ( V_1 -> V_39 ) ) ) &&
! ( V_1 -> V_73 & V_74 ) )
F_47 ( V_1 ) ;
}
F_17 ( & V_1 -> V_27 ) ;
F_43 ( & V_5 -> V_56 ) ;
F_17 ( & V_18 -> V_51 ) ;
F_18 ( V_1 ) ;
}
return V_35 ;
}
int F_48 ( struct V_45 * V_46 , struct V_8 * V_9 ,
struct V_17 * V_18 , int T_1 * V_75 )
{
int V_3 = 0 ;
if ( V_75 && F_49 ( V_3 , V_75 ) )
return - V_70 ;
return F_44 ( V_46 , V_9 , V_18 , V_3 ) ;
}
