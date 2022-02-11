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
struct V_1 * V_25 , * V_26 ;
F_15 ( & V_18 -> V_27 ) ;
if ( V_21 == NULL ) {
F_15 ( & V_22 -> V_28 ) ;
V_21 = F_16 ( V_22 ) ;
V_24 = V_21 -> V_29 . V_24 ;
V_25 = V_21 ;
goto V_30;
}
V_25 = V_21 ;
F_15 ( & V_25 -> V_28 ) ;
V_31:
V_24 = V_25 -> V_32 . V_33 . V_24 ;
V_30:
if ( V_24 == & V_22 -> V_29 ) {
F_17 ( & V_25 -> V_28 ) ;
F_17 ( & V_18 -> V_27 ) ;
F_18 ( V_21 ) ;
return NULL ;
}
V_26 = F_19 ( V_24 , struct V_1 , V_32 . V_33 ) ;
F_20 ( & V_26 -> V_28 , V_34 ) ;
if ( ! F_21 ( V_26 ) ) {
F_17 ( & V_25 -> V_28 ) ;
V_25 = V_26 ;
goto V_31;
}
F_16 ( V_26 ) ;
F_17 ( & V_26 -> V_28 ) ;
F_17 ( & V_25 -> V_28 ) ;
F_17 ( & V_18 -> V_27 ) ;
F_18 ( V_21 ) ;
return V_26 ;
}
static struct V_1 * F_22 ( struct V_1 * V_21 ,
struct V_1 * V_22 )
{
struct V_17 * V_18 = F_9 ( V_22 -> V_19 ) ;
struct V_23 * V_24 ;
struct V_1 * V_25 , * V_35 ;
if ( V_21 == NULL )
return F_23 ( V_22 ) ;
F_15 ( & V_18 -> V_27 ) ;
V_36:
V_25 = V_21 ;
F_15 ( & V_25 -> V_28 ) ;
V_31:
V_24 = V_25 -> V_29 . V_24 ;
if ( V_24 == & V_25 -> V_29 ) {
while ( 1 ) {
struct V_1 * V_37 ;
if ( V_25 == V_22 ) {
F_17 ( & V_25 -> V_28 ) ;
F_17 ( & V_18 -> V_27 ) ;
F_18 ( V_21 ) ;
return NULL ;
}
V_37 = V_25 -> V_38 ;
if ( ! F_24 ( & V_37 -> V_28 ) ) {
F_17 ( & V_25 -> V_28 ) ;
F_25 () ;
goto V_36;
}
F_17 ( & V_25 -> V_28 ) ;
V_24 = V_25 -> V_32 . V_33 . V_24 ;
V_25 = V_37 ;
if ( V_24 != & V_37 -> V_29 )
break;
}
}
V_35 = F_19 ( V_24 , struct V_1 , V_32 . V_33 ) ;
F_20 ( & V_35 -> V_28 , V_34 ) ;
if ( ! F_21 ( V_35 ) ) {
F_17 ( & V_25 -> V_28 ) ;
V_25 = V_35 ;
goto V_31;
}
F_16 ( V_35 ) ;
F_17 ( & V_35 -> V_28 ) ;
F_17 ( & V_25 -> V_28 ) ;
F_17 ( & V_18 -> V_27 ) ;
F_18 ( V_21 ) ;
return V_35 ;
}
static int F_26 ( struct V_8 * V_9 ,
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
static int F_27 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
unsigned long V_2 ,
int V_3 )
{
struct V_4 * V_39 = F_2 ( V_10 ) ;
struct V_1 * V_25 ;
F_5 ( L_3 ,
V_10 , ( int ) V_10 -> V_13 . V_14 , V_10 -> V_13 . V_15 ) ;
if ( ! F_21 ( V_10 ) )
return 1 ;
V_25 = NULL ;
while ( ( V_25 = F_22 ( V_25 , V_10 ) ) ) {
F_5 ( L_1 ,
V_25 , ( int ) V_25 -> V_13 . V_14 , V_25 -> V_13 . V_15 ) ;
if ( F_11 ( V_25 ) ) {
if ( F_4 ( V_9 , V_25 ) ) {
V_39 -> V_6 = V_20 ;
F_18 ( V_25 ) ;
return 1 ;
}
} else {
struct V_4 * V_5 = F_2 ( V_25 ) ;
unsigned int V_40 = F_28 ( & V_5 -> V_41 ) ;
F_29 ( V_25 ) ;
if ( V_25 == V_10 )
V_40 += 2 ;
else
V_40 ++ ;
if ( V_25 -> V_42 > V_40 ) {
V_39 -> V_6 = V_20 ;
F_18 ( V_25 ) ;
return 1 ;
}
}
}
if ( ! F_1 ( V_10 , V_2 , V_3 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_30 ( struct V_8 * V_9 ,
struct V_1 * V_37 ,
unsigned long V_2 ,
int V_3 )
{
struct V_1 * V_25 ;
F_5 ( L_4 ,
V_37 , ( int ) V_37 -> V_13 . V_14 , V_37 -> V_13 . V_15 ) ;
V_25 = NULL ;
while ( ( V_25 = F_22 ( V_25 , V_37 ) ) ) {
F_5 ( L_1 ,
V_25 , ( int ) V_25 -> V_13 . V_14 , V_25 -> V_13 . V_15 ) ;
if ( F_11 ( V_25 ) ) {
if ( F_4 ( V_9 , V_25 ) )
continue;
if ( F_1 ( V_25 , V_2 , V_3 ) )
return V_25 ;
}
}
return NULL ;
}
struct V_1 * F_31 ( struct V_43 * V_44 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
int V_45 )
{
unsigned long V_2 ;
struct V_1 * V_22 = F_23 ( V_44 -> V_46 ) ;
int V_3 = V_45 & V_47 ;
struct V_4 * V_5 ;
if ( ! V_22 )
return NULL ;
V_7 = V_20 ;
V_2 = V_18 -> V_48 ;
F_15 ( & V_18 -> V_49 ) ;
V_5 = F_2 ( V_22 ) ;
if ( V_5 -> V_50 & V_51 )
goto V_52;
if ( ! F_26 ( V_9 , V_22 , V_2 , V_3 ) ) {
struct V_4 * V_5 = F_2 ( V_22 ) ;
V_5 -> V_50 |= V_53 ;
F_32 ( & V_5 -> V_54 ) ;
F_17 ( & V_18 -> V_49 ) ;
return V_22 ;
}
V_52:
F_17 ( & V_18 -> V_49 ) ;
F_18 ( V_22 ) ;
return NULL ;
}
struct V_1 * F_33 ( struct V_43 * V_44 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
int V_45 )
{
unsigned long V_2 ;
struct V_1 * V_22 = V_44 -> V_46 ;
struct V_1 * V_1 ;
struct V_1 * V_55 = NULL ;
int V_3 = V_45 & V_47 ;
int V_56 = V_45 & V_57 ;
struct V_4 * V_5 ;
unsigned int V_40 ;
if ( ! V_22 )
return NULL ;
V_7 = V_20 ;
V_2 = V_18 -> V_48 ;
V_1 = NULL ;
while ( ( V_1 = F_14 ( V_1 , V_22 ) ) ) {
F_15 ( & V_18 -> V_49 ) ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 -> V_50 & V_51 )
goto V_24;
if ( F_11 ( V_1 ) ) {
F_5 ( L_5 ,
V_1 , ( int ) V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
V_40 = F_28 ( & V_5 -> V_41 ) + 2 ;
if ( V_1 -> V_42 > V_40 )
goto V_24;
if ( F_4 ( V_9 , V_1 ) )
goto V_24;
if ( F_1 ( V_1 , V_2 , V_3 ) ) {
V_55 = V_1 ;
goto V_58;
}
goto V_24;
}
if ( F_34 ( V_1 ) )
goto V_24;
if ( ! V_56 ) {
V_40 = F_28 ( & V_5 -> V_41 ) + 1 ;
if ( V_1 -> V_42 > V_40 )
goto V_24;
if ( ! F_27 ( V_9 , V_1 , V_2 , V_3 ) ) {
V_55 = V_1 ;
goto V_58;
}
} else {
V_40 = F_28 ( & V_5 -> V_41 ) + 1 ;
if ( V_1 -> V_42 > V_40 )
goto V_24;
V_55 = F_30 ( V_9 , V_1 , V_2 , V_3 ) ;
if ( V_55 ) {
F_18 ( V_1 ) ;
goto V_58;
}
}
V_24:
F_17 ( & V_18 -> V_49 ) ;
}
return NULL ;
V_58:
F_5 ( L_6 ,
V_55 , ( int ) V_55 -> V_13 . V_14 , V_55 -> V_13 . V_15 ) ;
V_5 = F_2 ( V_55 ) ;
V_5 -> V_50 |= V_53 ;
F_32 ( & V_5 -> V_54 ) ;
F_17 ( & V_18 -> V_49 ) ;
F_15 ( & V_18 -> V_27 ) ;
F_15 ( & V_55 -> V_38 -> V_28 ) ;
F_20 ( & V_55 -> V_28 , V_34 ) ;
F_35 ( & V_55 -> V_38 -> V_29 , & V_55 -> V_32 . V_33 ) ;
F_17 ( & V_55 -> V_28 ) ;
F_17 ( & V_55 -> V_38 -> V_28 ) ;
F_17 ( & V_18 -> V_27 ) ;
return V_55 ;
}
int F_36 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = F_9 ( V_1 -> V_19 ) ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
int V_12 ;
F_15 ( & V_18 -> V_49 ) ;
if ( V_5 -> V_50 & V_53 ) {
F_17 ( & V_18 -> V_49 ) ;
F_5 ( L_7 ,
V_1 , V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;
V_12 = F_37 ( V_18 , V_1 , V_59 ) ;
F_38 ( & V_5 -> V_54 ) ;
F_5 ( L_8 , V_12 ) ;
if ( F_39 ( V_1 ) )
return - V_60 ;
return V_12 ;
}
F_17 ( & V_18 -> V_49 ) ;
return 0 ;
}
int F_40 ( struct V_43 * V_44 ,
struct V_8 * V_9 ,
struct V_17 * V_18 ,
struct V_61 T_1 * V_62 )
{
struct V_61 V_63 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_35 = 0 ;
memset ( & V_63 , 0 , sizeof V_63 ) ;
V_63 . V_64 . V_65 = V_18 -> V_66 ;
V_63 . V_64 . type = V_67 ;
if ( ( V_1 = F_33 ( V_44 , V_9 , V_18 , 0 ) ) == NULL )
return - V_60 ;
V_63 . V_14 = V_1 -> V_13 . V_14 ;
memcpy ( V_63 . V_15 , V_1 -> V_13 . V_15 , V_63 . V_14 ) ;
V_63 . V_15 [ V_63 . V_14 ] = '\0' ;
F_18 ( V_1 ) ;
if ( F_41 ( V_62 , & V_63 , sizeof( struct V_61 ) ) )
V_35 = - V_68 ;
F_15 ( & V_18 -> V_49 ) ;
V_5 = F_2 ( V_1 ) ;
V_5 -> V_50 &= ~ V_53 ;
F_42 ( & V_5 -> V_54 ) ;
F_17 ( & V_18 -> V_49 ) ;
return V_35 ;
}
int F_43 ( struct V_43 * V_44 , struct V_8 * V_9 ,
struct V_17 * V_18 , int V_69 )
{
struct V_1 * V_1 ;
int V_35 = - V_60 ;
if ( F_44 ( V_18 -> type ) )
V_1 = F_31 ( V_44 , V_9 , V_18 , V_69 ) ;
else
V_1 = F_33 ( V_44 , V_9 , V_18 , V_69 ) ;
if ( V_1 ) {
struct V_4 * V_5 = F_2 ( V_1 ) ;
V_35 = F_37 ( V_18 , V_1 , V_70 ) ;
F_15 ( & V_18 -> V_49 ) ;
V_5 -> V_50 &= ~ V_53 ;
F_15 ( & V_1 -> V_28 ) ;
if ( ! V_35 ) {
if ( ( F_45 ( V_1 ) ||
( F_10 ( V_18 -> type ) &&
F_45 ( V_1 -> V_38 ) ) ) &&
! ( V_1 -> V_71 & V_72 ) )
F_46 ( V_1 ) ;
}
F_17 ( & V_1 -> V_28 ) ;
F_42 ( & V_5 -> V_54 ) ;
F_17 ( & V_18 -> V_49 ) ;
F_18 ( V_1 ) ;
}
return V_35 ;
}
int F_47 ( struct V_43 * V_44 , struct V_8 * V_9 ,
struct V_17 * V_18 , int T_1 * V_73 )
{
int V_3 = 0 ;
if ( V_73 && F_48 ( V_3 , V_73 ) )
return - V_68 ;
return F_43 ( V_44 , V_9 , V_18 , V_3 ) ;
}
