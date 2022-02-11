static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 + 0x10 , 1 << F_3 ( V_2 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 1 << F_3 ( V_2 ) ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_3 + 0x10 , 1 << F_6 ( V_2 ) ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 1 << F_6 ( V_2 ) ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_2 ( V_3 + 0x20 , ( 1 << F_6 ( V_2 ) ) | ( 1 << F_3 ( V_2 ) ) ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_3 + 0x30 , ( 1 << F_3 ( V_2 ) ) ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
return ! ! ( F_11 ( V_3 + 0x40 ) & ( 1 << F_3 ( V_2 ) ) ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_4 )
{
if ( V_4 )
F_4 ( V_2 ) ;
else
F_1 ( V_2 ) ;
F_13 ( V_5 ) ;
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
F_5 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 ;
F_8 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < 40 ; V_9 ++ ) {
F_12 ( V_2 , 1 ) ;
}
F_12 ( V_2 , 0 ) ;
F_12 ( V_2 , 1 ) ;
F_12 ( V_2 , V_6 ) ;
F_12 ( V_2 , ! V_6 ) ;
for ( V_9 = 0 ; V_9 < 5 ; V_9 ++ ) {
F_12 ( V_2 , ( V_7 & 0x10 ) != 0 ) ;
V_7 <<= 1 ;
}
for ( V_9 = 0 ; V_9 < 5 ; V_9 ++ ) {
F_12 ( V_2 , ( V_8 & 0x10 ) != 0 ) ;
V_8 <<= 1 ;
}
}
static int F_15 ( struct V_1 * V_2 , int V_10 , int V_11 )
{
T_2 V_12 ;
int V_13 , V_9 ;
T_1 V_7 = V_10 & 0xff ;
T_1 V_8 = V_11 & 0xff ;
F_14 ( V_2 , 1 , V_7 , V_8 ) ;
F_9 ( V_2 ) ;
F_13 ( V_5 ) ;
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
F_5 ( V_2 ) ;
V_12 = 0 ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
F_5 ( V_2 ) ;
F_13 ( V_5 ) ;
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
F_5 ( V_2 ) ;
F_13 ( V_5 ) ;
V_12 <<= 1 ;
V_12 |= F_10 ( V_2 ) ;
}
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
F_5 ( V_2 ) ;
F_13 ( V_5 ) ;
V_13 = V_12 ;
return V_13 ;
}
static int F_16 ( struct V_1 * V_2 , int V_10 , int V_11 , T_2 V_14 )
{
int V_9 ;
T_1 V_7 = V_10 & 0xff ;
T_1 V_8 = V_11 & 0xff ;
T_2 V_15 = V_14 & 0xffff ;
F_14 ( V_2 , 0 , V_7 , V_8 ) ;
F_5 ( V_2 ) ;
F_4 ( V_2 ) ;
F_13 ( V_5 ) ;
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
F_13 ( V_5 ) ;
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
F_5 ( V_2 ) ;
if ( V_15 & 0x8000 )
F_4 ( V_2 ) ;
else
F_1 ( V_2 ) ;
F_13 ( V_5 ) ;
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
V_15 <<= 1 ;
}
F_9 ( V_2 ) ;
F_5 ( V_2 ) ;
F_13 ( V_5 ) ;
F_7 ( V_2 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_20 * V_21 = V_17 -> V_19 . V_22 ;
struct V_1 * V_23 ;
struct V_24 * V_25 ;
const unsigned int * V_26 ;
int V_27 ;
V_27 = - V_28 ;
V_25 = F_19 ( sizeof( struct V_24 ) , V_29 ) ;
if ( ! V_25 )
goto V_30;
V_23 = F_20 () ;
if ( ! V_23 )
goto V_31;
V_23 -> V_32 = L_1 ;
V_23 -> V_6 = & F_15 ;
V_23 -> V_33 = & F_16 ;
V_23 -> V_34 = & F_17 ;
V_26 = F_21 ( V_21 , L_2 , NULL ) ;
snprintf ( V_23 -> V_35 , V_36 , L_3 , * V_26 ) ;
V_23 -> V_25 = V_25 ;
V_26 = F_21 ( V_21 , L_4 , NULL ) ;
V_25 -> V_37 = * V_26 ;
V_26 = F_21 ( V_21 , L_5 , NULL ) ;
V_25 -> V_38 = * V_26 ;
V_23 -> V_39 = V_19 ;
F_22 ( V_19 , V_23 ) ;
V_27 = F_23 ( V_23 , V_21 ) ;
if ( V_27 != 0 ) {
F_24 ( V_40 L_6 ,
V_23 -> V_32 , V_27 ) ;
goto V_41;
}
return 0 ;
V_41:
F_25 ( V_23 ) ;
V_31:
F_25 ( V_25 ) ;
V_30:
return V_27 ;
}
static int F_26 ( struct V_16 * V_19 )
{
struct V_1 * V_2 = F_27 ( & V_19 -> V_19 ) ;
F_28 ( V_2 ) ;
F_22 ( & V_19 -> V_19 , NULL ) ;
F_25 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
F_29 ( V_2 ) ;
return 0 ;
}
int F_30 ( void )
{
struct V_20 * V_21 ;
V_21 = F_31 ( NULL , NULL , L_7 ) ;
if ( ! V_21 )
V_21 = F_31 ( NULL , NULL ,
L_8 ) ;
if ( ! V_21 )
return - V_42 ;
V_3 = F_32 ( V_21 , 0 ) ;
F_33 ( V_21 ) ;
if ( ! V_3 )
return - V_42 ;
return F_34 ( & V_43 ) ;
}
void F_35 ( void )
{
F_36 ( & V_43 ) ;
if ( V_3 )
F_37 ( V_3 ) ;
}
