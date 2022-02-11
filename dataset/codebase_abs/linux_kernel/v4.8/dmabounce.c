static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
return sprintf ( V_5 , L_1 ,
V_7 -> V_10 . V_11 ,
V_7 -> V_12 . V_11 ,
V_7 -> V_13 - V_7 -> V_10 . V_11 -
V_7 -> V_12 . V_11 ,
V_7 -> V_13 ,
V_7 -> V_14 ,
V_7 -> V_15 ) ;
}
static inline struct V_16 *
F_2 ( struct V_6 * V_7 , void * V_17 ,
T_2 V_18 , enum V_19 V_20 )
{
struct V_16 * V_5 ;
struct V_21 * V_22 ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned long V_23 ;
F_3 ( V_2 , L_2 ,
V_24 , V_17 , V_18 , V_20 ) ;
if ( V_18 <= V_7 -> V_10 . V_18 ) {
V_22 = & V_7 -> V_10 ;
} else if ( V_18 <= V_7 -> V_12 . V_18 ) {
V_22 = & V_7 -> V_12 ;
} else {
V_22 = NULL ;
}
V_5 = F_4 ( sizeof( struct V_16 ) , V_25 ) ;
if ( V_5 == NULL ) {
F_5 ( V_2 , L_3 , V_24 ) ;
return NULL ;
}
V_5 -> V_17 = V_17 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_26 = V_20 ;
V_5 -> V_22 = V_22 ;
if ( V_22 ) {
V_5 -> V_27 = F_6 ( V_22 -> V_22 , V_25 ,
& V_5 -> V_28 ) ;
} else {
V_5 -> V_27 = F_7 ( V_2 , V_18 , & V_5 -> V_28 ,
V_25 ) ;
}
if ( V_5 -> V_27 == NULL ) {
F_5 ( V_2 ,
L_4 ,
V_24 , V_18 ) ;
F_8 ( V_5 ) ;
return NULL ;
}
#ifdef F_9
if ( V_22 )
V_22 -> V_11 ++ ;
V_7 -> V_13 ++ ;
#endif
F_10 ( & V_7 -> V_29 , V_23 ) ;
F_11 ( & V_5 -> V_30 , & V_7 -> V_31 ) ;
F_12 ( & V_7 -> V_29 , V_23 ) ;
return V_5 ;
}
static inline struct V_16 *
F_13 ( struct V_6 * V_7 , T_3 V_28 )
{
struct V_16 * V_32 , * V_33 = NULL ;
unsigned long V_23 ;
F_14 ( & V_7 -> V_29 , V_23 ) ;
F_15 (b, &device_info->safe_buffers, node)
if ( V_32 -> V_28 <= V_28 &&
V_32 -> V_28 + V_32 -> V_18 > V_28 ) {
V_33 = V_32 ;
break;
}
F_16 ( & V_7 -> V_29 , V_23 ) ;
return V_33 ;
}
static inline void
F_17 ( struct V_6 * V_7 , struct V_16 * V_5 )
{
unsigned long V_23 ;
F_3 ( V_7 -> V_2 , L_5 , V_24 , V_5 ) ;
F_10 ( & V_7 -> V_29 , V_23 ) ;
F_18 ( & V_5 -> V_30 ) ;
F_12 ( & V_7 -> V_29 , V_23 ) ;
if ( V_5 -> V_22 )
F_19 ( V_5 -> V_22 -> V_22 , V_5 -> V_27 , V_5 -> V_28 ) ;
else
F_20 ( V_7 -> V_2 , V_5 -> V_18 , V_5 -> V_27 ,
V_5 -> V_28 ) ;
F_8 ( V_5 ) ;
}
static struct V_16 * F_21 ( struct V_1 * V_2 ,
T_3 V_34 , const char * V_35 )
{
if ( ! V_2 || ! V_2 -> V_8 . V_9 )
return NULL ;
if ( F_22 ( V_2 , V_34 ) ) {
F_23 ( V_2 , L_6 , V_35 ) ;
return NULL ;
}
return F_13 ( V_2 -> V_8 . V_9 , V_34 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_3 V_34 , T_2 V_18 )
{
if ( ! V_2 || ! V_2 -> V_8 . V_9 )
return 0 ;
if ( V_2 -> V_36 ) {
unsigned long V_37 , V_38 = * V_2 -> V_36 ;
V_37 = ( V_38 + 1 ) & ~ V_38 ;
if ( V_37 && V_18 > V_37 ) {
F_23 ( V_2 , L_7
L_8 , V_18 , * V_2 -> V_36 ) ;
return - V_39 ;
}
if ( ( V_34 | ( V_34 + V_18 - 1 ) ) & ~ V_38 )
return 1 ;
}
return ! ! V_2 -> V_8 . V_9 -> F_24 ( V_2 , V_34 , V_18 ) ;
}
static inline T_3 F_25 ( struct V_1 * V_2 , void * V_17 , T_2 V_18 ,
enum V_19 V_20 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
struct V_16 * V_5 ;
if ( V_7 )
F_26 ( V_7 -> V_14 ++ ) ;
V_5 = F_2 ( V_7 , V_17 , V_18 , V_20 ) ;
if ( V_5 == NULL ) {
F_23 ( V_2 , L_9 ,
V_24 , V_17 ) ;
return V_40 ;
}
F_3 ( V_2 , L_10 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) ,
V_5 -> V_27 , V_5 -> V_28 ) ;
if ( V_20 == V_41 || V_20 == V_42 ) {
F_3 ( V_2 , L_11 ,
V_24 , V_17 , V_5 -> V_27 , V_18 ) ;
memcpy ( V_5 -> V_27 , V_17 , V_18 ) ;
}
return V_5 -> V_28 ;
}
static inline void F_28 ( struct V_1 * V_2 , struct V_16 * V_5 ,
T_2 V_18 , enum V_19 V_20 )
{
F_29 ( V_5 -> V_18 != V_18 ) ;
F_29 ( V_5 -> V_26 != V_20 ) ;
F_3 ( V_2 , L_10 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_26 ( V_2 -> V_8 . V_9 -> V_15 ++ ) ;
if ( V_20 == V_43 || V_20 == V_42 ) {
void * V_17 = V_5 -> V_17 ;
F_3 ( V_2 , L_12 ,
V_24 , V_5 -> V_27 , V_17 , V_18 ) ;
memcpy ( V_17 , V_5 -> V_27 , V_18 ) ;
F_30 ( V_17 , V_18 ) ;
}
F_17 ( V_2 -> V_8 . V_9 , V_5 ) ;
}
static T_3 F_31 ( struct V_1 * V_2 , struct V_44 * V_44 ,
unsigned long V_45 , T_2 V_18 , enum V_19 V_20 ,
unsigned long V_46 )
{
T_3 V_34 ;
int V_47 ;
F_3 ( V_2 , L_13 ,
V_24 , V_44 , V_45 , V_18 , V_20 ) ;
V_34 = F_32 ( V_2 , F_33 ( V_44 ) ) + V_45 ;
V_47 = F_24 ( V_2 , V_34 , V_18 ) ;
if ( V_47 < 0 )
return V_40 ;
if ( V_47 == 0 ) {
V_48 . V_49 ( V_2 , V_34 , V_18 , V_20 ) ;
return V_34 ;
}
if ( F_34 ( V_44 ) ) {
F_23 ( V_2 , L_14 ) ;
return V_40 ;
}
return F_25 ( V_2 , F_35 ( V_44 ) + V_45 , V_18 , V_20 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_3 V_34 , T_2 V_18 ,
enum V_19 V_20 , unsigned long V_46 )
{
struct V_16 * V_5 ;
F_3 ( V_2 , L_15 ,
V_24 , V_34 , V_18 , V_20 ) ;
V_5 = F_21 ( V_2 , V_34 , V_24 ) ;
if ( ! V_5 ) {
V_48 . V_50 ( V_2 , V_34 , V_18 , V_20 ) ;
return;
}
F_28 ( V_2 , V_5 , V_18 , V_20 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_3 V_51 ,
T_2 V_52 , enum V_19 V_20 )
{
struct V_16 * V_5 ;
unsigned long V_53 ;
F_3 ( V_2 , L_16 ,
V_24 , V_51 , V_52 , V_20 ) ;
V_5 = F_21 ( V_2 , V_51 , V_24 ) ;
if ( ! V_5 )
return 1 ;
V_53 = V_51 - V_5 -> V_28 ;
F_29 ( V_5 -> V_26 != V_20 ) ;
F_3 ( V_2 , L_17 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) , V_53 ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_26 ( V_2 -> V_8 . V_9 -> V_15 ++ ) ;
if ( V_20 == V_43 || V_20 == V_42 ) {
F_3 ( V_2 , L_12 ,
V_24 , V_5 -> V_27 + V_53 , V_5 -> V_17 + V_53 , V_52 ) ;
memcpy ( V_5 -> V_17 + V_53 , V_5 -> V_27 + V_53 , V_52 ) ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
T_3 V_54 , T_2 V_18 , enum V_19 V_20 )
{
if ( ! F_37 ( V_2 , V_54 , V_18 , V_20 ) )
return;
V_48 . V_50 ( V_2 , V_54 , V_18 , V_20 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_3 V_51 ,
T_2 V_52 , enum V_19 V_20 )
{
struct V_16 * V_5 ;
unsigned long V_53 ;
F_3 ( V_2 , L_16 ,
V_24 , V_51 , V_52 , V_20 ) ;
V_5 = F_21 ( V_2 , V_51 , V_24 ) ;
if ( ! V_5 )
return 1 ;
V_53 = V_51 - V_5 -> V_28 ;
F_29 ( V_5 -> V_26 != V_20 ) ;
F_3 ( V_2 , L_17 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) , V_53 ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_26 ( V_2 -> V_8 . V_9 -> V_15 ++ ) ;
if ( V_20 == V_41 || V_20 == V_42 ) {
F_3 ( V_2 , L_18 ,
V_24 , V_5 -> V_17 + V_53 , V_5 -> V_27 + V_53 , V_52 ) ;
memcpy ( V_5 -> V_27 + V_53 , V_5 -> V_17 + V_53 , V_52 ) ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
T_3 V_54 , T_2 V_18 , enum V_19 V_20 )
{
if ( ! F_39 ( V_2 , V_54 , V_18 , V_20 ) )
return;
V_48 . V_49 ( V_2 , V_54 , V_18 , V_20 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_4 V_36 )
{
if ( V_2 -> V_8 . V_9 )
return 0 ;
return V_48 . V_55 ( V_2 , V_36 ) ;
}
static int F_42 ( struct V_21 * V_22 , struct V_1 * V_2 ,
const char * V_56 , unsigned long V_18 )
{
V_22 -> V_18 = V_18 ;
F_26 ( V_22 -> V_11 = 0 ) ;
V_22 -> V_22 = F_43 ( V_56 , V_2 , V_18 ,
0 ,
0 ) ;
return V_22 -> V_22 ? 0 : - V_57 ;
}
int F_44 ( struct V_1 * V_2 , unsigned long V_58 ,
unsigned long V_59 ,
int (* F_45)( struct V_1 * , T_3 , T_2 ) )
{
struct V_6 * V_7 ;
int V_47 ;
V_7 = F_4 ( sizeof( struct V_6 ) , V_25 ) ;
if ( ! V_7 ) {
F_23 ( V_2 ,
L_19 ) ;
return - V_57 ;
}
V_47 = F_42 ( & V_7 -> V_10 , V_2 ,
L_20 , V_58 ) ;
if ( V_47 ) {
F_23 ( V_2 ,
L_21 ,
V_58 ) ;
goto V_60;
}
if ( V_59 ) {
V_47 = F_42 ( & V_7 -> V_12 , V_2 ,
L_22 ,
V_59 ) ;
if ( V_47 ) {
F_23 ( V_2 ,
L_21 ,
V_59 ) ;
goto V_61;
}
}
V_7 -> V_2 = V_2 ;
F_46 ( & V_7 -> V_31 ) ;
F_47 ( & V_7 -> V_29 ) ;
V_7 -> F_24 = F_45 ;
#ifdef F_9
V_7 -> V_13 = 0 ;
V_7 -> V_14 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_62 = F_48 ( V_2 , & V_63 ) ;
#endif
V_2 -> V_8 . V_9 = V_7 ;
F_49 ( V_2 , & V_64 ) ;
F_50 ( V_2 , L_23 ) ;
return 0 ;
V_61:
F_51 ( V_7 -> V_10 . V_22 ) ;
V_60:
F_8 ( V_7 ) ;
return V_47 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
V_2 -> V_8 . V_9 = NULL ;
F_49 ( V_2 , NULL ) ;
if ( ! V_7 ) {
F_5 ( V_2 ,
L_24
L_25 ) ;
return;
}
if ( ! F_53 ( & V_7 -> V_31 ) ) {
F_23 ( V_2 ,
L_26 ) ;
F_54 () ;
}
if ( V_7 -> V_10 . V_22 )
F_51 ( V_7 -> V_10 . V_22 ) ;
if ( V_7 -> V_12 . V_22 )
F_51 ( V_7 -> V_12 . V_22 ) ;
#ifdef F_9
if ( V_7 -> V_62 == 0 )
F_55 ( V_2 , & V_63 ) ;
#endif
F_8 ( V_7 ) ;
F_50 ( V_2 , L_27 ) ;
}
