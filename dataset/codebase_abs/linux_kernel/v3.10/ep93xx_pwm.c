static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_1 ( V_2 , V_6 , V_7 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_7 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_6 )
{
F_1 ( V_2 , V_6 , V_8 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x1 , V_9 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x0 , V_9 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_9 ) & 0x1 ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x1 , V_10 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x0 , V_10 ) ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_10 ) & 0x1 ;
}
static T_2 F_14 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
unsigned long V_18 = F_17 ( V_2 -> V_19 ) ;
return sprintf ( V_15 , L_1 , V_18 / ( V_20 + 1 ) ) ;
}
static T_2 F_18 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
unsigned long V_18 = F_17 ( V_2 -> V_19 ) ;
return sprintf ( V_15 , L_1 , V_18 / 2 ) ;
}
static T_2 F_19 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
if ( F_10 ( V_2 ) ) {
unsigned long V_18 = F_17 ( V_2 -> V_19 ) ;
T_1 V_21 = F_6 ( V_2 ) ;
return sprintf ( V_15 , L_1 , V_18 / ( V_21 + 1 ) ) ;
} else {
return sprintf ( V_15 , L_2 ) ;
}
}
static T_2 F_20 ( struct V_11 * V_12 ,
struct V_13 * V_14 , const char * V_15 , T_3 V_22 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
long V_3 ;
int V_23 ;
V_23 = F_21 ( V_15 , 10 , & V_3 ) ;
if ( V_23 )
return - V_24 ;
if ( V_3 == 0 ) {
F_9 ( V_2 ) ;
} else if ( V_3 <= ( F_17 ( V_2 -> V_19 ) / 2 ) ) {
T_4 V_21 , V_25 ;
V_3 = ( F_17 ( V_2 -> V_19 ) / V_3 ) - 1 ;
if ( V_3 > V_20 )
V_3 = V_20 ;
if ( V_3 < 1 )
V_3 = 1 ;
V_21 = F_6 ( V_2 ) ;
V_25 = ( ( V_3 + 1 ) * V_2 -> V_26 / 100 ) - 1 ;
if ( V_3 > V_21 ) {
F_5 ( V_2 , V_3 ) ;
F_7 ( V_2 , V_25 ) ;
} else {
F_7 ( V_2 , V_25 ) ;
F_5 ( V_2 , V_3 ) ;
}
if ( ! F_10 ( V_2 ) )
F_8 ( V_2 ) ;
} else {
return - V_24 ;
}
return V_22 ;
}
static T_2 F_22 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
return sprintf ( V_15 , L_3 , V_2 -> V_26 ) ;
}
static T_2 F_23 ( struct V_11 * V_12 ,
struct V_13 * V_14 , const char * V_15 , T_3 V_22 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
long V_3 ;
int V_23 ;
V_23 = F_21 ( V_15 , 10 , & V_3 ) ;
if ( V_23 )
return - V_24 ;
if ( V_3 > 0 && V_3 < 100 ) {
T_4 V_21 = F_6 ( V_2 ) ;
F_7 ( V_2 , ( ( V_21 + 1 ) * V_3 / 100 ) - 1 ) ;
V_2 -> V_26 = V_3 ;
return V_22 ;
}
return - V_24 ;
}
static T_2 F_24 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
return sprintf ( V_15 , L_3 , F_13 ( V_2 ) ) ;
}
static T_2 F_25 ( struct V_11 * V_12 ,
struct V_13 * V_14 , const char * V_15 , T_3 V_22 )
{
struct V_16 * V_17 = F_15 ( V_12 ) ;
struct V_1 * V_2 = F_16 ( V_17 ) ;
long V_3 ;
int V_23 ;
V_23 = F_21 ( V_15 , 10 , & V_3 ) ;
if ( V_23 )
return - V_24 ;
if ( V_3 == 0 )
F_12 ( V_2 ) ;
else if ( V_3 == 1 )
F_11 ( V_2 ) ;
else
return - V_24 ;
return V_22 ;
}
static int T_5 F_26 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 ;
int V_23 ;
V_23 = F_27 ( V_17 ) ;
if ( V_23 )
return V_23 ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_29 ) ;
if ( ! V_2 ) {
V_23 = - V_30 ;
goto V_31;
}
V_28 = F_29 ( V_17 , V_32 , 0 ) ;
if ( V_28 == NULL ) {
V_23 = - V_33 ;
goto V_34;
}
V_28 = F_30 ( V_28 -> V_35 , F_31 ( V_28 ) , V_17 -> V_36 ) ;
if ( V_28 == NULL ) {
V_23 = - V_37 ;
goto V_34;
}
V_2 -> V_5 = F_32 ( V_28 -> V_35 , F_31 ( V_28 ) ) ;
if ( V_2 -> V_5 == NULL ) {
V_23 = - V_33 ;
goto V_38;
}
V_23 = F_33 ( & V_17 -> V_12 . V_39 , & V_40 ) ;
if ( V_23 )
goto V_41;
V_2 -> V_19 = F_34 ( & V_17 -> V_12 , L_4 ) ;
if ( F_35 ( V_2 -> V_19 ) ) {
V_23 = F_36 ( V_2 -> V_19 ) ;
goto V_42;
}
V_2 -> V_26 = 50 ;
F_37 ( V_17 , V_2 ) ;
F_9 ( V_2 ) ;
F_5 ( V_2 , V_20 ) ;
F_7 ( V_2 , V_20 / 2 ) ;
F_38 ( V_2 -> V_19 ) ;
return 0 ;
V_42:
F_39 ( & V_17 -> V_12 . V_39 , & V_40 ) ;
V_41:
F_40 ( V_2 -> V_5 ) ;
V_38:
F_41 ( V_28 -> V_35 , F_31 ( V_28 ) ) ;
V_34:
F_42 ( V_2 ) ;
V_31:
F_43 ( V_17 ) ;
return V_23 ;
}
static int T_6 F_44 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_17 ) ;
struct V_27 * V_28 = F_29 ( V_17 , V_32 , 0 ) ;
F_9 ( V_2 ) ;
F_45 ( V_2 -> V_19 ) ;
F_46 ( V_2 -> V_19 ) ;
F_37 ( V_17 , NULL ) ;
F_39 ( & V_17 -> V_12 . V_39 , & V_40 ) ;
F_40 ( V_2 -> V_5 ) ;
F_41 ( V_28 -> V_35 , F_31 ( V_28 ) ) ;
F_42 ( V_2 ) ;
F_43 ( V_17 ) ;
return 0 ;
}
