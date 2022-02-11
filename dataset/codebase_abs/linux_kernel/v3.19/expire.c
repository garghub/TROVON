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
F_5 ( L_1 , V_1 , V_1 ) ;
F_6 ( & V_11 ) ;
if ( ! F_7 ( & V_11 ) )
goto V_13;
if ( F_8 ( V_11 . V_1 ) ) {
struct V_14 * V_15 = F_9 ( V_11 . V_1 -> V_16 ) ;
if ( F_10 ( V_15 -> type ) )
goto V_13;
}
if ( ! F_11 ( V_11 . V_9 ) ) {
struct V_4 * V_5 = F_2 ( V_10 ) ;
V_5 -> V_6 = V_17 ;
goto V_13;
}
V_12 = 0 ;
V_13:
F_5 ( L_2 , V_12 ) ;
F_12 ( & V_11 ) ;
return V_12 ;
}
static struct V_1 * F_13 ( struct V_1 * V_18 ,
struct V_1 * V_19 )
{
struct V_14 * V_15 = F_9 ( V_19 -> V_16 ) ;
struct V_20 * V_21 ;
struct V_1 * V_22 ;
F_14 ( & V_15 -> V_23 ) ;
F_14 ( & V_19 -> V_24 ) ;
if ( V_18 )
V_21 = V_18 -> V_25 . V_21 ;
else {
V_18 = F_15 ( V_19 ) ;
V_21 = V_18 -> V_26 . V_21 ;
}
V_27:
if ( V_21 == & V_19 -> V_26 ) {
F_16 ( & V_19 -> V_24 ) ;
F_16 ( & V_15 -> V_23 ) ;
F_17 ( V_18 ) ;
return NULL ;
}
V_22 = F_18 ( V_21 , struct V_1 , V_25 ) ;
F_19 ( & V_22 -> V_24 , V_28 ) ;
if ( ! F_20 ( V_22 ) || ! F_21 ( V_22 ) ) {
F_16 ( & V_22 -> V_24 ) ;
V_21 = V_22 -> V_25 . V_21 ;
goto V_27;
}
F_15 ( V_22 ) ;
F_16 ( & V_22 -> V_24 ) ;
F_16 ( & V_19 -> V_24 ) ;
F_16 ( & V_15 -> V_23 ) ;
F_17 ( V_18 ) ;
return V_22 ;
}
static struct V_1 * F_22 ( struct V_1 * V_18 ,
struct V_1 * V_19 )
{
struct V_14 * V_15 = F_9 ( V_19 -> V_16 ) ;
struct V_20 * V_21 ;
struct V_1 * V_29 , * V_30 ;
if ( V_18 == NULL )
return F_23 ( V_19 ) ;
F_14 ( & V_15 -> V_23 ) ;
V_31:
V_29 = V_18 ;
F_14 ( & V_29 -> V_24 ) ;
V_32:
V_21 = V_29 -> V_26 . V_21 ;
if ( V_21 == & V_29 -> V_26 ) {
while ( 1 ) {
struct V_1 * V_33 ;
if ( V_29 == V_19 ) {
F_16 ( & V_29 -> V_24 ) ;
F_16 ( & V_15 -> V_23 ) ;
F_17 ( V_18 ) ;
return NULL ;
}
V_33 = V_29 -> V_34 ;
if ( ! F_24 ( & V_33 -> V_24 ) ) {
F_16 ( & V_29 -> V_24 ) ;
F_25 () ;
goto V_31;
}
F_16 ( & V_29 -> V_24 ) ;
V_21 = V_29 -> V_25 . V_21 ;
V_29 = V_33 ;
if ( V_21 != & V_33 -> V_26 )
break;
}
}
V_30 = F_18 ( V_21 , struct V_1 , V_25 ) ;
F_19 ( & V_30 -> V_24 , V_28 ) ;
if ( ! F_21 ( V_30 ) ) {
F_16 ( & V_29 -> V_24 ) ;
F_26 ( & V_30 -> V_24 . V_35 , 0 , V_36 ) ;
V_29 = V_30 ;
goto V_32;
}
F_15 ( V_30 ) ;
F_16 ( & V_30 -> V_24 ) ;
F_16 ( & V_29 -> V_24 ) ;
F_16 ( & V_15 -> V_23 ) ;
F_17 ( V_18 ) ;
return V_30 ;
}
static int F_27 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
unsigned long V_2 ,
int V_3 )
{
F_5 ( L_3 , V_10 , V_10 ) ;
if ( ! F_11 ( V_9 ) ) {
struct V_4 * V_5 = F_2 ( V_10 ) ;
if ( V_5 )
V_5 -> V_6 = V_17 ;
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
struct V_4 * V_37 = F_2 ( V_10 ) ;
struct V_1 * V_29 ;
F_5 ( L_3 , V_10 , V_10 ) ;
if ( ! F_21 ( V_10 ) )
return 1 ;
V_29 = NULL ;
while ( ( V_29 = F_22 ( V_29 , V_10 ) ) ) {
F_5 ( L_1 , V_29 , V_29 ) ;
if ( F_29 ( V_29 ) ) {
if ( F_4 ( V_9 , V_29 ) ) {
V_37 -> V_6 = V_17 ;
F_17 ( V_29 ) ;
return 1 ;
}
} else {
struct V_4 * V_5 = F_2 ( V_29 ) ;
unsigned int V_38 = F_30 ( & V_5 -> V_39 ) ;
if ( V_29 == V_10 )
V_38 += 2 ;
else
V_38 ++ ;
if ( F_20 ( V_29 ) > V_38 ) {
V_37 -> V_6 = V_17 ;
F_17 ( V_29 ) ;
return 1 ;
}
}
}
if ( ! F_1 ( V_10 , V_2 , V_3 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_31 ( struct V_8 * V_9 ,
struct V_1 * V_33 ,
unsigned long V_2 ,
int V_3 )
{
struct V_1 * V_29 ;
F_5 ( L_4 , V_33 , V_33 ) ;
V_29 = NULL ;
while ( ( V_29 = F_22 ( V_29 , V_33 ) ) ) {
F_5 ( L_1 , V_29 , V_29 ) ;
if ( F_29 ( V_29 ) ) {
if ( F_4 ( V_9 , V_29 ) )
continue;
if ( F_1 ( V_29 , V_2 , V_3 ) )
return V_29 ;
}
}
return NULL ;
}
struct V_1 * F_32 ( struct V_40 * V_41 ,
struct V_8 * V_9 ,
struct V_14 * V_15 ,
int V_42 )
{
unsigned long V_2 ;
struct V_1 * V_19 = F_23 ( V_41 -> V_43 ) ;
int V_3 = V_42 & V_44 ;
struct V_4 * V_5 ;
if ( ! V_19 )
return NULL ;
V_7 = V_17 ;
V_2 = V_15 -> V_45 ;
F_14 ( & V_15 -> V_46 ) ;
V_5 = F_2 ( V_19 ) ;
if ( V_5 -> V_47 & V_48 )
goto V_49;
if ( ! F_27 ( V_9 , V_19 , V_2 , V_3 ) ) {
V_5 -> V_47 |= V_50 ;
F_16 ( & V_15 -> V_46 ) ;
F_33 () ;
F_14 ( & V_15 -> V_46 ) ;
if ( ! F_27 ( V_9 , V_19 , V_2 , V_3 ) ) {
V_5 -> V_47 |= V_51 ;
F_34 () ;
V_5 -> V_47 &= ~ V_50 ;
F_35 ( & V_5 -> V_52 ) ;
F_16 ( & V_15 -> V_46 ) ;
return V_19 ;
}
V_5 -> V_47 &= ~ V_50 ;
}
V_49:
F_16 ( & V_15 -> V_46 ) ;
F_17 ( V_19 ) ;
return NULL ;
}
static struct V_1 * F_36 ( struct V_1 * V_1 ,
struct V_8 * V_9 ,
unsigned long V_2 ,
int V_42 )
{
int V_3 = V_42 & V_44 ;
int V_53 = V_42 & V_54 ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned int V_38 ;
if ( V_5 -> V_47 & V_48 )
return NULL ;
if ( F_29 ( V_1 ) ) {
F_5 ( L_5 , V_1 , V_1 ) ;
if ( F_4 ( V_9 , V_1 ) )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) )
return V_1 ;
return NULL ;
}
if ( V_1 -> V_55 && F_37 ( V_1 -> V_55 -> V_56 ) ) {
F_5 ( L_6 , V_1 , V_1 ) ;
if ( F_1 ( V_1 , V_2 , V_3 ) )
return V_1 ;
return NULL ;
}
if ( F_38 ( V_1 ) )
return NULL ;
if ( ! V_53 ) {
V_38 = F_30 ( & V_5 -> V_39 ) + 1 ;
if ( F_20 ( V_1 ) > V_38 )
return NULL ;
if ( ! F_28 ( V_9 , V_1 , V_2 , V_3 ) )
return V_1 ;
} else {
struct V_1 * V_57 ;
V_38 = F_30 ( & V_5 -> V_39 ) + 1 ;
if ( F_20 ( V_1 ) > V_38 )
return NULL ;
V_57 = F_31 ( V_9 , V_1 , V_2 , V_3 ) ;
if ( V_57 ) {
if ( V_57 == V_1 )
F_17 ( V_1 ) ;
return V_57 ;
}
}
return NULL ;
}
struct V_1 * F_39 ( struct V_40 * V_41 ,
struct V_8 * V_9 ,
struct V_14 * V_15 ,
int V_42 )
{
unsigned long V_2 ;
struct V_1 * V_19 = V_41 -> V_43 ;
struct V_1 * V_1 ;
struct V_1 * V_57 ;
struct V_4 * V_5 ;
if ( ! V_19 )
return NULL ;
V_7 = V_17 ;
V_2 = V_15 -> V_45 ;
V_1 = NULL ;
while ( ( V_1 = F_13 ( V_1 , V_19 ) ) ) {
F_14 ( & V_15 -> V_46 ) ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 -> V_47 & V_50 )
V_57 = NULL ;
else
V_57 = F_36 ( V_1 , V_9 , V_2 , V_42 ) ;
if ( ! V_57 ) {
F_16 ( & V_15 -> V_46 ) ;
continue;
}
V_5 = F_2 ( V_57 ) ;
V_5 -> V_47 |= V_50 ;
F_16 ( & V_15 -> V_46 ) ;
F_33 () ;
F_14 ( & V_15 -> V_46 ) ;
if ( F_36 ( V_57 , V_9 , V_2 , V_42 ) ) {
if ( V_57 != V_1 )
F_17 ( V_1 ) ;
goto V_58;
}
V_5 -> V_47 &= ~ V_50 ;
if ( V_57 != V_1 )
F_17 ( V_57 ) ;
F_16 ( & V_15 -> V_46 ) ;
}
return NULL ;
V_58:
F_5 ( L_7 , V_57 , V_57 ) ;
V_5 -> V_47 |= V_51 ;
F_34 () ;
V_5 -> V_47 &= ~ V_50 ;
F_35 ( & V_5 -> V_52 ) ;
F_16 ( & V_15 -> V_46 ) ;
F_14 ( & V_15 -> V_23 ) ;
F_14 ( & V_57 -> V_34 -> V_24 ) ;
F_19 ( & V_57 -> V_24 , V_28 ) ;
F_40 ( & V_57 -> V_34 -> V_26 , & V_57 -> V_25 ) ;
F_16 ( & V_57 -> V_24 ) ;
F_16 ( & V_57 -> V_34 -> V_24 ) ;
F_16 ( & V_15 -> V_23 ) ;
return V_57 ;
}
int F_41 ( struct V_1 * V_1 , int V_59 )
{
struct V_14 * V_15 = F_9 ( V_1 -> V_16 ) ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
int V_12 ;
if ( ! ( V_5 -> V_47 & ( V_51 | V_50 ) ) )
return 0 ;
if ( V_59 )
return - V_60 ;
F_14 ( & V_15 -> V_46 ) ;
if ( V_5 -> V_47 & V_51 ) {
F_16 ( & V_15 -> V_46 ) ;
F_5 ( L_8 , V_1 , V_1 ) ;
V_12 = F_42 ( V_15 , V_1 , V_61 ) ;
F_43 ( & V_5 -> V_52 ) ;
F_5 ( L_9 , V_12 ) ;
if ( F_44 ( V_1 ) )
return - V_62 ;
return V_12 ;
}
F_16 ( & V_15 -> V_46 ) ;
return 0 ;
}
int F_45 ( struct V_40 * V_41 ,
struct V_8 * V_9 ,
struct V_14 * V_15 ,
struct V_63 T_1 * V_64 )
{
struct V_63 V_65 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_30 = 0 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_66 . V_67 = V_15 -> V_68 ;
V_65 . V_66 . type = V_69 ;
if ( ( V_1 = F_39 ( V_41 , V_9 , V_15 , 0 ) ) == NULL )
return - V_62 ;
V_65 . V_70 = V_1 -> V_71 . V_70 ;
memcpy ( V_65 . V_72 , V_1 -> V_71 . V_72 , V_65 . V_70 ) ;
V_65 . V_72 [ V_65 . V_70 ] = '\0' ;
F_17 ( V_1 ) ;
if ( F_46 ( V_64 , & V_65 , sizeof( struct V_63 ) ) )
V_30 = - V_73 ;
F_14 ( & V_15 -> V_46 ) ;
V_5 = F_2 ( V_1 ) ;
V_5 -> V_6 = V_7 ;
V_5 -> V_47 &= ~ V_51 ;
F_47 ( & V_5 -> V_52 ) ;
F_16 ( & V_15 -> V_46 ) ;
return V_30 ;
}
int F_48 ( struct V_40 * V_41 , struct V_8 * V_9 ,
struct V_14 * V_15 , int V_74 )
{
struct V_1 * V_1 ;
int V_30 = - V_62 ;
if ( F_49 ( V_15 -> type ) )
V_1 = F_32 ( V_41 , V_9 , V_15 , V_74 ) ;
else
V_1 = F_39 ( V_41 , V_9 , V_15 , V_74 ) ;
if ( V_1 ) {
struct V_4 * V_5 = F_2 ( V_1 ) ;
V_30 = F_42 ( V_15 , V_1 , V_75 ) ;
F_14 ( & V_15 -> V_46 ) ;
V_5 -> V_6 = V_7 ;
V_5 -> V_47 &= ~ V_51 ;
F_47 ( & V_5 -> V_52 ) ;
F_16 ( & V_15 -> V_46 ) ;
F_17 ( V_1 ) ;
}
return V_30 ;
}
int F_50 ( struct V_40 * V_41 , struct V_8 * V_9 ,
struct V_14 * V_15 , int T_1 * V_76 )
{
int V_3 = 0 ;
if ( V_76 && F_51 ( V_3 , V_76 ) )
return - V_73 ;
return F_48 ( V_41 , V_9 , V_15 , V_3 ) ;
}
