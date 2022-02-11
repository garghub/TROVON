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
F_11 ( V_2 -> V_10 -> V_11 ,
L_1 ,
F_12 ( V_2 , V_4 ) ) ;
#endif
}
static void F_13 ( struct V_1 * V_2 , struct V_3 * V_12 , unsigned int V_13 )
{
unsigned char V_14 ;
if ( V_12 -> V_15 == NULL ) {
F_14 ( V_2 , V_12 -> V_16 | V_12 -> V_17 ) ;
return;
}
F_15 ( & V_12 -> V_18 ) ;
if ( ( V_13 & V_12 -> V_19 ) && F_8 ( V_2 , V_12 ) ) {
if ( ! ( V_12 -> V_20 & V_21 ) ) {
F_7 ( V_2 , V_12 ) ;
} else {
V_14 = F_9 ( V_2 , V_12 ) ;
if ( V_12 -> V_22 )
F_16 ( V_12 -> V_22 , & V_14 , 1 ) ;
}
}
F_17 ( & V_12 -> V_18 ) ;
F_15 ( & V_12 -> V_23 ) ;
if ( ( V_13 & V_12 -> V_24 ) && F_18 ( V_2 , V_12 ) ) {
if ( V_12 -> V_25 &&
F_19 ( V_12 -> V_25 , & V_14 , 1 ) == 1 ) {
F_20 ( V_2 , V_12 , V_14 ) ;
} else {
F_14 ( V_2 , V_12 -> V_16 ) ;
}
}
F_17 ( & V_12 -> V_23 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_13 )
{
F_13 ( V_2 , & V_2 -> V_12 , V_13 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_13 )
{
F_13 ( V_2 , & V_2 -> V_26 , V_13 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_12 , unsigned char V_27 , int V_28 )
{
unsigned long V_29 ;
int V_9 , V_30 ;
F_24 ( & V_12 -> V_18 , V_29 ) ;
F_20 ( V_2 , V_12 , 0x00 ) ;
F_25 ( V_2 , V_12 , V_27 ) ;
if ( V_28 ) {
V_30 = 0 ;
V_9 = 10000 ;
while ( ! V_30 && V_9 -- > 0 ) {
if ( F_8 ( V_2 , V_12 ) ) {
if ( F_9 ( V_2 , V_12 ) == V_31 )
V_30 = 1 ;
}
}
if ( ! V_30 && F_9 ( V_2 , V_12 ) == V_31 )
V_30 = 1 ;
} else {
V_30 = 1 ;
}
F_26 ( & V_12 -> V_18 , V_29 ) ;
if ( ! V_30 ) {
F_11 ( V_2 -> V_10 -> V_11 ,
L_2 ,
V_27 , V_2 -> V_7 ,
F_12 ( V_2 , V_12 ) ,
F_9 ( V_2 , V_12 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_27 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_3 * V_12 = (struct V_3 * ) V_33 -> V_15 -> V_34 ;
unsigned long V_29 ;
V_2 = V_12 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_35 ;
F_24 ( & V_12 -> V_36 , V_29 ) ;
V_12 -> V_20 |= V_21 ;
V_12 -> V_22 = V_33 ;
if ( ! ( V_12 -> V_20 & V_37 ) ) {
F_26 ( & V_12 -> V_36 , V_29 ) ;
if ( F_23 ( V_2 , V_12 , V_38 , 1 ) )
goto V_39;
if ( F_23 ( V_2 , V_12 , V_40 , 1 ) )
goto V_39;
} else {
F_26 ( & V_12 -> V_36 , V_29 ) ;
}
return 0 ;
V_39:
return - V_41 ;
}
static int F_29 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_3 * V_12 = (struct V_3 * ) V_33 -> V_15 -> V_34 ;
unsigned long V_29 ;
V_2 = V_12 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_35 ;
F_24 ( & V_12 -> V_36 , V_29 ) ;
V_12 -> V_20 |= V_37 ;
V_12 -> V_25 = V_33 ;
if ( ! ( V_12 -> V_20 & V_21 ) ) {
F_26 ( & V_12 -> V_36 , V_29 ) ;
if ( F_23 ( V_2 , V_12 , V_38 , 1 ) )
goto V_39;
if ( F_23 ( V_2 , V_12 , V_40 , 1 ) )
goto V_39;
} else {
F_26 ( & V_12 -> V_36 , V_29 ) ;
}
return 0 ;
V_39:
return - V_41 ;
}
static int F_30 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_3 * V_12 = (struct V_3 * ) V_33 -> V_15 -> V_34 ;
unsigned long V_29 ;
int V_42 = 0 ;
V_2 = V_12 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_35 ;
F_24 ( & V_12 -> V_36 , V_29 ) ;
F_14 ( V_2 , V_12 -> V_17 ) ;
V_12 -> V_20 &= ~ V_21 ;
V_12 -> V_22 = NULL ;
if ( ! ( V_12 -> V_20 & V_37 ) ) {
F_26 ( & V_12 -> V_36 , V_29 ) ;
V_42 = F_23 ( V_2 , V_12 , V_38 , 0 ) ;
} else {
F_26 ( & V_12 -> V_36 , V_29 ) ;
}
return V_42 ;
}
static int F_31 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_3 * V_12 = (struct V_3 * ) V_33 -> V_15 -> V_34 ;
unsigned long V_29 ;
int V_42 = 0 ;
V_2 = V_12 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return - V_35 ;
F_24 ( & V_12 -> V_36 , V_29 ) ;
F_14 ( V_2 , V_12 -> V_16 ) ;
V_12 -> V_20 &= ~ V_37 ;
V_12 -> V_25 = NULL ;
if ( ! ( V_12 -> V_20 & V_21 ) ) {
F_26 ( & V_12 -> V_36 , V_29 ) ;
V_42 = F_23 ( V_2 , V_12 , V_38 , 0 ) ;
} else {
F_26 ( & V_12 -> V_36 , V_29 ) ;
}
return V_42 ;
}
static void F_32 ( struct V_32 * V_33 , int V_43 )
{
struct V_1 * V_2 ;
struct V_3 * V_12 = (struct V_3 * ) V_33 -> V_15 -> V_34 ;
V_2 = V_12 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return;
if ( V_43 )
F_33 ( V_2 , V_12 -> V_17 ) ;
else
F_14 ( V_2 , V_12 -> V_17 ) ;
}
static void F_34 ( struct V_32 * V_33 , int V_43 )
{
struct V_1 * V_2 ;
struct V_3 * V_12 = (struct V_3 * ) V_33 -> V_15 -> V_34 ;
unsigned long V_29 ;
V_2 = V_12 -> V_2 ;
if ( F_28 ( ! V_2 ) )
return;
if ( V_43 ) {
int V_44 = 4 ;
unsigned char V_14 ;
F_24 ( & V_12 -> V_23 , V_29 ) ;
while ( V_44 > 0 ) {
if ( F_18 ( V_2 , V_12 ) ) {
if ( ! ( V_12 -> V_20 & V_37 ) ||
F_19 ( V_33 , & V_14 , 1 ) != 1 ) {
F_26 ( & V_12 -> V_23 , V_29 ) ;
return;
}
F_20 ( V_2 , V_12 , V_14 ) ;
V_44 -- ;
} else {
break;
}
}
F_26 ( & V_12 -> V_23 , V_29 ) ;
F_33 ( V_2 , V_12 -> V_16 ) ;
} else {
F_14 ( V_2 , V_12 -> V_16 ) ;
}
}
static void F_35 ( struct V_45 * V_15 )
{
struct V_3 * V_12 = V_15 -> V_34 ;
V_12 -> V_46 = NULL ;
V_12 -> V_15 = NULL ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_12 , int V_47 , char * V_48 )
{
struct V_45 * V_15 ;
int V_42 ;
if ( ( V_42 = F_37 ( V_2 -> V_10 , V_48 , V_47 , 1 , 1 , & V_15 ) ) < 0 )
return V_42 ;
V_12 -> V_2 = V_2 ;
F_38 ( & V_12 -> V_36 ) ;
F_38 ( & V_12 -> V_18 ) ;
F_38 ( & V_12 -> V_23 ) ;
strcpy ( V_15 -> V_48 , V_48 ) ;
F_39 ( V_15 , V_49 , & V_50 ) ;
F_39 ( V_15 , V_51 , & V_52 ) ;
V_15 -> V_53 |= V_54 |
V_55 |
V_56 ;
V_15 -> V_34 = V_12 ;
V_15 -> V_57 = F_35 ;
V_12 -> V_15 = V_15 ;
return 0 ;
}
int V_3 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = & V_2 -> V_12 ;
int V_42 ;
if ( ( V_42 = F_36 ( V_2 , V_12 , 0 , L_3 ) ) < 0 )
return V_42 ;
V_12 -> V_16 = V_58 ;
V_12 -> V_17 = V_59 ;
V_12 -> V_7 = V_60 ;
V_12 -> V_24 = V_61 ;
V_12 -> V_19 = V_62 ;
V_12 -> V_46 = F_21 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_12 ;
int V_42 ;
V_12 = & V_2 -> V_12 ;
if ( ( V_42 = F_36 ( V_2 , V_12 , 0 , L_4 ) ) < 0 )
return V_42 ;
V_12 -> V_16 = V_58 ;
V_12 -> V_17 = V_59 ;
V_12 -> V_7 = V_63 ;
V_12 -> V_24 = V_61 ;
V_12 -> V_19 = V_62 ;
V_12 -> V_46 = F_21 ;
V_12 = & V_2 -> V_26 ;
if ( ( V_42 = F_36 ( V_2 , V_12 , 1 , L_5 ) ) < 0 )
return V_42 ;
V_12 -> V_16 = V_64 ;
V_12 -> V_17 = V_65 ;
V_12 -> V_7 = V_66 ;
V_12 -> V_24 = V_67 ;
V_12 -> V_19 = V_68 ;
V_12 -> V_46 = F_22 ;
return 0 ;
}
