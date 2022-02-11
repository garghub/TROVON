static inline unsigned char F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_2 -> V_6 )
return ( unsigned char ) F_2 ( V_2 , V_4 -> V_7 + V_5 , 0 ) ;
else
return F_3 ( V_2 -> V_7 + V_4 -> V_7 + V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 , int V_5 )
{
if ( V_2 -> V_6 )
F_5 ( V_2 , V_4 -> V_7 + V_5 , 0 , V_8 ) ;
else
F_6 ( V_8 , V_2 -> V_7 + V_4 -> V_7 + V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_9 = 100000 ;
for (; V_9 > 0 && F_8 ( V_2 , V_4 ) ; V_9 -- )
F_9 ( V_2 , V_4 ) ;
#ifdef F_10
if ( V_9 <= 0 )
F_11 ( V_10 L_1 , F_12 ( V_2 , V_4 ) ) ;
#endif
}
static void F_13 ( struct V_1 * V_2 , struct V_3 * V_11 , unsigned int V_12 )
{
unsigned char V_13 ;
if ( V_11 -> V_14 == NULL ) {
F_14 ( V_2 , V_11 -> V_15 | V_11 -> V_16 ) ;
return;
}
F_15 ( & V_11 -> V_17 ) ;
if ( ( V_12 & V_11 -> V_18 ) && F_8 ( V_2 , V_11 ) ) {
if ( ! ( V_11 -> V_19 & V_20 ) ) {
F_7 ( V_2 , V_11 ) ;
} else {
V_13 = F_9 ( V_2 , V_11 ) ;
if ( V_11 -> V_21 )
F_16 ( V_11 -> V_21 , & V_13 , 1 ) ;
}
}
F_17 ( & V_11 -> V_17 ) ;
F_15 ( & V_11 -> V_22 ) ;
if ( ( V_12 & V_11 -> V_23 ) && F_18 ( V_2 , V_11 ) ) {
if ( V_11 -> V_24 &&
F_19 ( V_11 -> V_24 , & V_13 , 1 ) == 1 ) {
F_20 ( V_2 , V_11 , V_13 ) ;
} else {
F_14 ( V_2 , V_11 -> V_15 ) ;
}
}
F_17 ( & V_11 -> V_22 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_12 )
{
F_13 ( V_2 , & V_2 -> V_11 , V_12 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_12 )
{
F_13 ( V_2 , & V_2 -> V_25 , V_12 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_11 , unsigned char V_26 , int V_27 )
{
unsigned long V_28 ;
int V_9 , V_29 ;
F_24 ( & V_11 -> V_17 , V_28 ) ;
F_20 ( V_2 , V_11 , 0x00 ) ;
F_25 ( V_2 , V_11 , V_26 ) ;
if ( V_27 ) {
V_29 = 0 ;
V_9 = 10000 ;
while ( ! V_29 && V_9 -- > 0 ) {
if ( F_8 ( V_2 , V_11 ) ) {
if ( F_9 ( V_2 , V_11 ) == V_30 )
V_29 = 1 ;
}
}
if ( ! V_29 && F_9 ( V_2 , V_11 ) == V_30 )
V_29 = 1 ;
} else {
V_29 = 1 ;
}
F_26 ( & V_11 -> V_17 , V_28 ) ;
if ( ! V_29 ) {
F_11 ( V_10 L_2 ,
V_26 , V_2 -> V_7 ,
F_12 ( V_2 , V_11 ) ,
F_9 ( V_2 , V_11 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_27 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_11 = (struct V_3 * ) V_32 -> V_14 -> V_33 ;
unsigned long V_28 ;
V_2 = V_11 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_34 ;
F_24 ( & V_11 -> V_35 , V_28 ) ;
V_11 -> V_19 |= V_20 ;
V_11 -> V_21 = V_32 ;
if ( ! ( V_11 -> V_19 & V_36 ) ) {
F_26 ( & V_11 -> V_35 , V_28 ) ;
if ( F_23 ( V_2 , V_11 , V_37 , 1 ) )
goto V_38;
if ( F_23 ( V_2 , V_11 , V_39 , 1 ) )
goto V_38;
} else {
F_26 ( & V_11 -> V_35 , V_28 ) ;
}
return 0 ;
V_38:
return - V_40 ;
}
static int F_29 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_11 = (struct V_3 * ) V_32 -> V_14 -> V_33 ;
unsigned long V_28 ;
V_2 = V_11 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_34 ;
F_24 ( & V_11 -> V_35 , V_28 ) ;
V_11 -> V_19 |= V_36 ;
V_11 -> V_24 = V_32 ;
if ( ! ( V_11 -> V_19 & V_20 ) ) {
F_26 ( & V_11 -> V_35 , V_28 ) ;
if ( F_23 ( V_2 , V_11 , V_37 , 1 ) )
goto V_38;
if ( F_23 ( V_2 , V_11 , V_39 , 1 ) )
goto V_38;
} else {
F_26 ( & V_11 -> V_35 , V_28 ) ;
}
return 0 ;
V_38:
return - V_40 ;
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_11 = (struct V_3 * ) V_32 -> V_14 -> V_33 ;
unsigned long V_28 ;
int V_41 = 0 ;
V_2 = V_11 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_34 ;
F_24 ( & V_11 -> V_35 , V_28 ) ;
F_14 ( V_2 , V_11 -> V_16 ) ;
V_11 -> V_19 &= ~ V_20 ;
V_11 -> V_21 = NULL ;
if ( ! ( V_11 -> V_19 & V_36 ) ) {
F_26 ( & V_11 -> V_35 , V_28 ) ;
V_41 = F_23 ( V_2 , V_11 , V_37 , 0 ) ;
} else {
F_26 ( & V_11 -> V_35 , V_28 ) ;
}
return V_41 ;
}
static int F_31 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_11 = (struct V_3 * ) V_32 -> V_14 -> V_33 ;
unsigned long V_28 ;
int V_41 = 0 ;
V_2 = V_11 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_34 ;
F_24 ( & V_11 -> V_35 , V_28 ) ;
F_14 ( V_2 , V_11 -> V_15 ) ;
V_11 -> V_19 &= ~ V_36 ;
V_11 -> V_24 = NULL ;
if ( ! ( V_11 -> V_19 & V_20 ) ) {
F_26 ( & V_11 -> V_35 , V_28 ) ;
V_41 = F_23 ( V_2 , V_11 , V_37 , 0 ) ;
} else {
F_26 ( & V_11 -> V_35 , V_28 ) ;
}
return V_41 ;
}
static void F_32 ( struct V_31 * V_32 , int V_42 )
{
struct V_1 * V_2 ;
struct V_3 * V_11 = (struct V_3 * ) V_32 -> V_14 -> V_33 ;
V_2 = V_11 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return;
if ( V_42 )
F_33 ( V_2 , V_11 -> V_16 ) ;
else
F_14 ( V_2 , V_11 -> V_16 ) ;
}
static void F_34 ( struct V_31 * V_32 , int V_42 )
{
struct V_1 * V_2 ;
struct V_3 * V_11 = (struct V_3 * ) V_32 -> V_14 -> V_33 ;
unsigned long V_28 ;
V_2 = V_11 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return;
if ( V_42 ) {
int V_43 = 4 ;
unsigned char V_13 ;
F_24 ( & V_11 -> V_22 , V_28 ) ;
while ( V_43 > 0 ) {
if ( F_18 ( V_2 , V_11 ) ) {
if ( ! ( V_11 -> V_19 & V_36 ) ||
F_19 ( V_32 , & V_13 , 1 ) != 1 ) {
F_26 ( & V_11 -> V_22 , V_28 ) ;
return;
}
F_20 ( V_2 , V_11 , V_13 ) ;
V_43 -- ;
} else {
break;
}
}
F_26 ( & V_11 -> V_22 , V_28 ) ;
F_33 ( V_2 , V_11 -> V_15 ) ;
} else {
F_14 ( V_2 , V_11 -> V_15 ) ;
}
}
static void F_35 ( struct V_44 * V_14 )
{
struct V_3 * V_11 = V_14 -> V_33 ;
V_11 -> V_45 = NULL ;
V_11 -> V_14 = NULL ;
}
static int T_1 F_36 ( struct V_1 * V_2 , struct V_3 * V_11 , int V_46 , char * V_47 )
{
struct V_44 * V_14 ;
int V_41 ;
if ( ( V_41 = F_37 ( V_2 -> V_48 , V_47 , V_46 , 1 , 1 , & V_14 ) ) < 0 )
return V_41 ;
V_11 -> V_2 = V_2 ;
F_38 ( & V_11 -> V_35 ) ;
F_38 ( & V_11 -> V_17 ) ;
F_38 ( & V_11 -> V_22 ) ;
strcpy ( V_14 -> V_47 , V_47 ) ;
F_39 ( V_14 , V_49 , & V_50 ) ;
F_39 ( V_14 , V_51 , & V_52 ) ;
V_14 -> V_53 |= V_54 |
V_55 |
V_56 ;
V_14 -> V_33 = V_11 ;
V_14 -> V_57 = F_35 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
int T_1 V_3 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = & V_2 -> V_11 ;
int V_41 ;
if ( ( V_41 = F_36 ( V_2 , V_11 , 0 , L_3 ) ) < 0 )
return V_41 ;
V_11 -> V_15 = V_58 ;
V_11 -> V_16 = V_59 ;
V_11 -> V_7 = V_60 ;
V_11 -> V_23 = V_61 ;
V_11 -> V_18 = V_62 ;
V_11 -> V_45 = F_21 ;
return 0 ;
}
int T_1 F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_11 ;
int V_41 ;
V_11 = & V_2 -> V_11 ;
if ( ( V_41 = F_36 ( V_2 , V_11 , 0 , L_4 ) ) < 0 )
return V_41 ;
V_11 -> V_15 = V_58 ;
V_11 -> V_16 = V_59 ;
V_11 -> V_7 = V_63 ;
V_11 -> V_23 = V_61 ;
V_11 -> V_18 = V_62 ;
V_11 -> V_45 = F_21 ;
V_11 = & V_2 -> V_25 ;
if ( ( V_41 = F_36 ( V_2 , V_11 , 1 , L_5 ) ) < 0 )
return V_41 ;
V_11 -> V_15 = V_64 ;
V_11 -> V_16 = V_65 ;
V_11 -> V_7 = V_66 ;
V_11 -> V_23 = V_67 ;
V_11 -> V_18 = V_68 ;
V_11 -> V_45 = F_22 ;
return 0 ;
}
