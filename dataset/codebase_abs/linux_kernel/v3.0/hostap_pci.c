static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 * V_9 ;
unsigned long V_10 ;
V_6 = F_2 ( V_2 ) ;
V_9 = V_6 -> V_9 ;
V_8 = V_9 -> V_8 ;
F_3 ( & V_9 -> V_11 , V_10 ) ;
F_4 ( V_2 , V_12 , V_3 , V_4 ) ;
F_5 ( V_4 , V_8 -> V_13 + V_3 ) ;
F_6 ( & V_9 -> V_11 , V_10 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 * V_9 ;
unsigned long V_10 ;
T_1 V_4 ;
V_6 = F_2 ( V_2 ) ;
V_9 = V_6 -> V_9 ;
V_8 = V_9 -> V_8 ;
F_3 ( & V_9 -> V_11 , V_10 ) ;
V_4 = F_8 ( V_8 -> V_13 + V_3 ) ;
F_4 ( V_2 , V_14 , V_3 , V_4 ) ;
F_6 ( & V_9 -> V_11 , V_10 ) ;
return V_4 ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_3 , T_3 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 * V_9 ;
unsigned long V_10 ;
V_6 = F_2 ( V_2 ) ;
V_9 = V_6 -> V_9 ;
V_8 = V_9 -> V_8 ;
F_3 ( & V_9 -> V_11 , V_10 ) ;
F_4 ( V_2 , V_15 , V_3 , V_4 ) ;
F_10 ( V_4 , V_8 -> V_13 + V_3 ) ;
F_6 ( & V_9 -> V_11 , V_10 ) ;
}
static inline T_3 F_11 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 * V_9 ;
unsigned long V_10 ;
T_3 V_4 ;
V_6 = F_2 ( V_2 ) ;
V_9 = V_6 -> V_9 ;
V_8 = V_9 -> V_8 ;
F_3 ( & V_9 -> V_11 , V_10 ) ;
V_4 = F_12 ( V_8 -> V_13 + V_3 ) ;
F_4 ( V_2 , V_16 , V_3 , V_4 ) ;
F_6 ( & V_9 -> V_11 , V_10 ) ;
return V_4 ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_2 ) ;
V_8 = V_6 -> V_9 -> V_8 ;
F_5 ( V_4 , V_8 -> V_13 + V_3 ) ;
}
static inline T_1 F_14 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_2 ) ;
V_8 = V_6 -> V_9 -> V_8 ;
return F_8 ( V_8 -> V_13 + V_3 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , int V_3 , T_3 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_2 ) ;
V_8 = V_6 -> V_9 -> V_8 ;
F_10 ( V_4 , V_8 -> V_13 + V_3 ) ;
}
static inline T_3 F_16 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_2 ) ;
V_8 = V_6 -> V_9 -> V_8 ;
return F_12 ( V_8 -> V_13 + V_3 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_17 , void * V_18 ,
int V_19 )
{
T_3 V_20 ;
T_4 * V_21 ;
V_20 = ( V_17 == 1 ) ? V_22 : V_23 ;
V_21 = ( T_4 * ) V_18 ;
for ( ; V_19 > 1 ; V_19 -= 2 )
* V_21 ++ = F_18 ( V_20 ) ;
if ( V_19 & 1 )
* ( ( char * ) V_21 ) = F_19 ( V_20 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_17 , void * V_18 , int V_19 )
{
T_3 V_20 ;
T_4 * V_21 ;
V_20 = ( V_17 == 1 ) ? V_22 : V_23 ;
V_21 = ( T_4 * ) V_18 ;
for ( ; V_19 > 1 ; V_19 -= 2 )
F_21 ( * V_21 ++ , V_20 ) ;
if ( V_19 & 1 )
F_22 ( * ( ( char * ) V_21 ) , V_20 ) ;
return 0 ;
}
static void F_23 ( T_2 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_3 V_24 ;
V_24 = F_19 ( V_25 ) ;
F_24 ( V_26 L_1 , V_2 -> V_27 , V_24 ) ;
#ifdef F_25
int V_28 ;
F_26 ( V_24 | 0x0080 , V_25 ) ;
F_27 ( 250 ) ;
F_26 ( V_24 & ~ 0x0080 , V_25 ) ;
F_27 ( 500 ) ;
V_28 = 2000000 / 10 ;
while ( ( F_28 ( V_29 ) & V_30 ) && -- V_28 )
F_29 ( 10 ) ;
#else
F_26 ( V_24 | 0x0080 , V_25 ) ;
F_27 ( 2 ) ;
F_26 ( V_24 & ~ 0x0080 , V_25 ) ;
F_27 ( 2 ) ;
#endif
if ( F_28 ( V_29 ) & V_30 ) {
F_24 ( V_26 L_2 , V_2 -> V_27 ) ;
}
}
static void F_30 ( T_2 * V_9 , int V_31 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
F_26 ( 0x00C5 , V_25 ) ;
F_27 ( 10 ) ;
F_26 ( V_31 , V_32 ) ;
F_27 ( 10 ) ;
F_26 ( 0x0045 , V_25 ) ;
F_27 ( 10 ) ;
}
static int F_31 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
unsigned long V_37 ;
void T_5 * V_38 = NULL ;
T_2 * V_9 = NULL ;
struct V_1 * V_2 = NULL ;
static int V_39 ;
int V_40 = 0 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_8 = F_32 ( sizeof( * V_8 ) , V_41 ) ;
if ( V_8 == NULL )
return - V_42 ;
if ( F_33 ( V_34 ) )
goto V_43;
V_37 = F_34 ( V_34 , 0 ) ;
if ( ! F_35 ( V_37 , F_36 ( V_34 , 0 ) , L_3 ) ) {
F_24 ( V_44 L_4 ) ;
goto V_45;
}
V_38 = F_37 ( V_34 , 0 ) ;
if ( V_38 == NULL ) {
F_24 ( V_44 L_5 ) ;
goto V_46;
}
V_2 = F_38 ( & V_47 , V_39 ,
& V_34 -> V_2 ) ;
if ( V_2 == NULL )
goto V_46;
V_6 = F_2 ( V_2 ) ;
V_9 = V_6 -> V_9 ;
V_9 -> V_8 = V_8 ;
V_39 ++ ;
V_2 -> V_48 = V_34 -> V_48 ;
V_8 -> V_13 = V_38 ;
V_2 -> V_49 = ( unsigned long ) V_38 ;
F_23 ( V_9 ) ;
F_39 ( V_34 , V_2 ) ;
if ( F_40 ( V_2 -> V_48 , V_50 , V_51 , V_2 -> V_27 ,
V_2 ) ) {
F_24 ( V_52 L_6 , V_2 -> V_27 ) ;
goto V_46;
} else
V_40 = 1 ;
if ( ! V_9 -> V_53 && F_41 ( V_2 , 1 ) ) {
F_24 ( V_26 L_7 ,
V_54 ) ;
goto V_46;
}
F_24 ( V_55 L_8
L_9 , V_2 -> V_27 , V_37 , V_2 -> V_48 ) ;
return F_42 ( V_2 ) ;
V_46:
if ( V_40 && V_2 )
F_43 ( V_2 -> V_48 , V_2 ) ;
if ( V_38 )
F_44 ( V_38 ) ;
F_45 ( V_37 , F_36 ( V_34 , 0 ) ) ;
V_45:
F_46 ( V_34 ) ;
F_47 ( V_2 ) ;
V_43:
F_48 ( V_8 ) ;
return - V_56 ;
}
static void F_49 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
void T_5 * V_13 ;
struct V_7 * V_8 ;
V_2 = F_50 ( V_34 ) ;
V_6 = F_2 ( V_2 ) ;
V_8 = V_6 -> V_9 -> V_8 ;
F_23 ( V_6 -> V_9 ) ;
F_51 ( V_2 ) ;
if ( V_2 -> V_48 )
F_43 ( V_2 -> V_48 , V_2 ) ;
V_13 = V_8 -> V_13 ;
F_47 ( V_2 ) ;
F_48 ( V_8 ) ;
F_44 ( V_13 ) ;
F_45 ( F_34 ( V_34 , 0 ) ,
F_36 ( V_34 , 0 ) ) ;
F_46 ( V_34 ) ;
}
static int F_52 ( struct V_33 * V_34 , T_6 V_57 )
{
struct V_1 * V_2 = F_50 ( V_34 ) ;
if ( F_53 ( V_2 ) ) {
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
}
F_56 ( V_2 ) ;
F_57 ( V_34 ) ;
F_46 ( V_34 ) ;
F_58 ( V_34 , V_58 ) ;
return 0 ;
}
static int F_59 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_50 ( V_34 ) ;
int V_59 ;
V_59 = F_33 ( V_34 ) ;
if ( V_59 ) {
F_24 ( V_44 L_10 ,
V_2 -> V_27 ) ;
return V_59 ;
}
F_60 ( V_34 ) ;
F_41 ( V_2 , 0 ) ;
if ( F_53 ( V_2 ) ) {
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
}
return 0 ;
}
static int T_7 F_63 ( void )
{
return F_64 ( & V_60 ) ;
}
static void T_8 F_65 ( void )
{
F_66 ( & V_60 ) ;
}
