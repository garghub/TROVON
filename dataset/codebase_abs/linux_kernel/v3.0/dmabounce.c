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
if ( V_32 -> V_28 == V_28 ) {
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
if ( V_2 )
F_23 ( V_2 , L_6 , V_35 ) ;
else
F_24 ( L_7 , V_35 ) ;
return NULL ;
}
return F_13 ( V_2 -> V_8 . V_9 , V_34 ) ;
}
static inline T_3 F_25 ( struct V_1 * V_2 , void * V_17 , T_2 V_18 ,
enum V_19 V_20 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
T_3 V_34 ;
int V_36 = 0 ;
if ( V_7 )
F_26 ( V_7 -> V_14 ++ ) ;
V_34 = F_27 ( V_2 , V_17 ) ;
if ( V_2 -> V_37 ) {
unsigned long V_38 = * V_2 -> V_37 ;
unsigned long V_39 ;
V_39 = ( V_38 + 1 ) & ~ V_38 ;
if ( V_39 && V_18 > V_39 ) {
F_23 ( V_2 , L_8
L_9 , V_18 , * V_2 -> V_37 ) ;
return ~ 0 ;
}
V_36 = ( V_34 | ( V_34 + V_18 - 1 ) ) & ~ V_38 ;
}
if ( V_7 && ( V_36 || F_28 ( V_2 , V_34 , V_18 ) ) ) {
struct V_16 * V_5 ;
V_5 = F_2 ( V_7 , V_17 , V_18 , V_20 ) ;
if ( V_5 == 0 ) {
F_23 ( V_2 , L_10 ,
V_24 , V_17 ) ;
return ~ 0 ;
}
F_3 ( V_2 ,
L_11 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) ,
V_5 -> V_27 , V_5 -> V_28 ) ;
if ( ( V_20 == V_40 ) ||
( V_20 == V_41 ) ) {
F_3 ( V_2 , L_12 ,
V_24 , V_17 , V_5 -> V_27 , V_18 ) ;
memcpy ( V_5 -> V_27 , V_17 , V_18 ) ;
}
V_17 = V_5 -> V_27 ;
V_34 = V_5 -> V_28 ;
} else {
F_29 ( V_17 , V_18 , V_20 ) ;
}
return V_34 ;
}
static inline void F_30 ( struct V_1 * V_2 , T_3 V_34 ,
T_2 V_18 , enum V_19 V_20 )
{
struct V_16 * V_5 = F_21 ( V_2 , V_34 , L_13 ) ;
if ( V_5 ) {
F_31 ( V_5 -> V_18 != V_18 ) ;
F_31 ( V_5 -> V_26 != V_20 ) ;
F_3 ( V_2 ,
L_11 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_26 ( V_2 -> V_8 . V_9 -> V_15 ++ ) ;
if ( V_20 == V_42 || V_20 == V_41 ) {
void * V_17 = V_5 -> V_17 ;
F_3 ( V_2 ,
L_14 ,
V_24 , V_5 -> V_27 , V_17 , V_18 ) ;
memcpy ( V_17 , V_5 -> V_27 , V_18 ) ;
F_32 ( V_17 , V_18 ) ;
}
F_17 ( V_2 -> V_8 . V_9 , V_5 ) ;
} else {
F_33 ( F_34 ( V_2 , V_34 ) , V_18 , V_20 ) ;
}
}
T_3 F_35 ( struct V_1 * V_2 , void * V_17 , T_2 V_18 ,
enum V_19 V_20 )
{
F_3 ( V_2 , L_15 ,
V_24 , V_17 , V_18 , V_20 ) ;
F_31 ( ! F_36 ( V_20 ) ) ;
return F_25 ( V_2 , V_17 , V_18 , V_20 ) ;
}
void F_37 ( struct V_1 * V_2 , T_3 V_34 , T_2 V_18 ,
enum V_19 V_20 )
{
F_3 ( V_2 , L_15 ,
V_24 , ( void * ) V_34 , V_18 , V_20 ) ;
F_30 ( V_2 , V_34 , V_18 , V_20 ) ;
}
T_3 F_38 ( struct V_1 * V_2 , struct V_43 * V_43 ,
unsigned long V_44 , T_2 V_18 , enum V_19 V_20 )
{
F_3 ( V_2 , L_16 ,
V_24 , V_43 , V_44 , V_18 , V_20 ) ;
F_31 ( ! F_36 ( V_20 ) ) ;
if ( F_39 ( V_43 ) ) {
F_23 ( V_2 , L_17
L_18 ) ;
return ~ 0 ;
}
return F_25 ( V_2 , F_40 ( V_43 ) + V_44 , V_18 , V_20 ) ;
}
void F_41 ( struct V_1 * V_2 , T_3 V_34 , T_2 V_18 ,
enum V_19 V_20 )
{
F_3 ( V_2 , L_15 ,
V_24 , ( void * ) V_34 , V_18 , V_20 ) ;
F_30 ( V_2 , V_34 , V_18 , V_20 ) ;
}
int F_42 ( struct V_1 * V_2 , T_3 V_45 ,
unsigned long V_46 , T_2 V_47 , enum V_19 V_20 )
{
struct V_16 * V_5 ;
F_3 ( V_2 , L_19 ,
V_24 , V_45 , V_46 , V_47 , V_20 ) ;
V_5 = F_21 ( V_2 , V_45 , V_24 ) ;
if ( ! V_5 )
return 1 ;
F_31 ( V_5 -> V_26 != V_20 ) ;
F_3 ( V_2 , L_11 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_26 ( V_2 -> V_8 . V_9 -> V_15 ++ ) ;
if ( V_20 == V_42 || V_20 == V_41 ) {
F_3 ( V_2 , L_14 ,
V_24 , V_5 -> V_27 + V_46 , V_5 -> V_17 + V_46 , V_47 ) ;
memcpy ( V_5 -> V_17 + V_46 , V_5 -> V_27 + V_46 , V_47 ) ;
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 , T_3 V_45 ,
unsigned long V_46 , T_2 V_47 , enum V_19 V_20 )
{
struct V_16 * V_5 ;
F_3 ( V_2 , L_19 ,
V_24 , V_45 , V_46 , V_47 , V_20 ) ;
V_5 = F_21 ( V_2 , V_45 , V_24 ) ;
if ( ! V_5 )
return 1 ;
F_31 ( V_5 -> V_26 != V_20 ) ;
F_3 ( V_2 , L_11 ,
V_24 , V_5 -> V_17 , F_27 ( V_2 , V_5 -> V_17 ) ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_26 ( V_2 -> V_8 . V_9 -> V_15 ++ ) ;
if ( V_20 == V_40 || V_20 == V_41 ) {
F_3 ( V_2 , L_20 ,
V_24 , V_5 -> V_17 + V_46 , V_5 -> V_27 + V_46 , V_47 ) ;
memcpy ( V_5 -> V_27 + V_46 , V_5 -> V_17 + V_46 , V_47 ) ;
}
return 0 ;
}
static int F_44 ( struct V_21 * V_22 , struct V_1 * V_2 ,
const char * V_48 , unsigned long V_18 )
{
V_22 -> V_18 = V_18 ;
F_26 ( V_22 -> V_11 = 0 ) ;
V_22 -> V_22 = F_45 ( V_48 , V_2 , V_18 ,
0 ,
0 ) ;
return V_22 -> V_22 ? 0 : - V_49 ;
}
int F_46 ( struct V_1 * V_2 , unsigned long V_50 ,
unsigned long V_51 )
{
struct V_6 * V_7 ;
int V_52 ;
V_7 = F_4 ( sizeof( struct V_6 ) , V_25 ) ;
if ( ! V_7 ) {
F_23 ( V_2 ,
L_21 ) ;
return - V_49 ;
}
V_52 = F_44 ( & V_7 -> V_10 , V_2 ,
L_22 , V_50 ) ;
if ( V_52 ) {
F_23 ( V_2 ,
L_23 ,
V_50 ) ;
goto V_53;
}
if ( V_51 ) {
V_52 = F_44 ( & V_7 -> V_12 , V_2 ,
L_24 ,
V_51 ) ;
if ( V_52 ) {
F_23 ( V_2 ,
L_23 ,
V_51 ) ;
goto V_54;
}
}
V_7 -> V_2 = V_2 ;
F_47 ( & V_7 -> V_31 ) ;
F_48 ( & V_7 -> V_29 ) ;
#ifdef F_9
V_7 -> V_13 = 0 ;
V_7 -> V_14 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_55 = F_49 ( V_2 , & V_56 ) ;
#endif
V_2 -> V_8 . V_9 = V_7 ;
F_50 ( V_2 , L_25 ) ;
return 0 ;
V_54:
F_51 ( V_7 -> V_10 . V_22 ) ;
V_53:
F_8 ( V_7 ) ;
return V_52 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
V_2 -> V_8 . V_9 = NULL ;
if ( ! V_7 ) {
F_5 ( V_2 ,
L_26
L_27 ) ;
return;
}
if ( ! F_53 ( & V_7 -> V_31 ) ) {
F_23 ( V_2 ,
L_28 ) ;
F_54 () ;
}
if ( V_7 -> V_10 . V_22 )
F_51 ( V_7 -> V_10 . V_22 ) ;
if ( V_7 -> V_12 . V_22 )
F_51 ( V_7 -> V_12 . V_22 ) ;
#ifdef F_9
if ( V_7 -> V_55 == 0 )
F_55 ( V_2 , & V_56 ) ;
#endif
F_8 ( V_7 ) ;
F_50 ( V_2 , L_29 ) ;
}
