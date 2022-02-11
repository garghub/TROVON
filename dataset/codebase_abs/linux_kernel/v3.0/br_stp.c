void F_1 ( const struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ,
( unsigned ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ,
V_7 [ V_2 -> V_8 ] ) ;
}
struct V_1 * F_3 ( struct V_9 * V_3 , T_1 V_4 )
{
struct V_1 * V_2 ;
F_4 (p, &br->port_list, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static int F_5 ( const struct V_1 * V_2 ,
T_1 V_10 )
{
struct V_9 * V_3 ;
struct V_1 * V_11 ;
int V_12 ;
V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 == V_13 ||
F_6 ( V_2 ) )
return 0 ;
if ( memcmp ( & V_3 -> V_14 , & V_2 -> V_15 , 8 ) <= 0 )
return 0 ;
if ( ! V_10 )
return 1 ;
V_11 = F_3 ( V_3 , V_10 ) ;
V_12 = memcmp ( & V_2 -> V_15 , & V_11 -> V_15 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_2 -> V_16 + V_2 -> V_17 <
V_11 -> V_16 + V_11 -> V_17 )
return 1 ;
else if ( V_2 -> V_16 + V_2 -> V_17 >
V_11 -> V_16 + V_11 -> V_17 )
return 0 ;
V_12 = memcmp ( & V_2 -> V_18 , & V_11 -> V_18 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_2 -> V_19 < V_11 -> V_19 )
return 1 ;
else if ( V_2 -> V_19 > V_11 -> V_19 )
return 0 ;
if ( V_2 -> V_20 < V_11 -> V_20 )
return 1 ;
return 0 ;
}
static void F_7 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
T_1 V_10 = 0 ;
F_8 (p, &br->port_list, list) {
if ( F_5 ( V_2 , V_10 ) )
V_10 = V_2 -> V_4 ;
}
V_3 -> V_10 = V_10 ;
if ( ! V_10 ) {
V_3 -> V_15 = V_3 -> V_14 ;
V_3 -> V_21 = 0 ;
} else {
V_2 = F_3 ( V_3 , V_10 ) ;
V_3 -> V_15 = V_2 -> V_15 ;
V_3 -> V_21 = V_2 -> V_16 + V_2 -> V_17 ;
}
}
void F_9 ( struct V_9 * V_3 )
{
V_3 -> V_22 = V_3 -> V_23 ;
V_3 -> V_24 = V_3 -> V_25 ;
V_3 -> V_26 = V_3 -> V_27 ;
F_10 ( V_3 ) ;
F_11 ( & V_3 -> V_28 ) ;
if ( V_3 -> V_5 -> V_29 & V_30 ) {
F_12 ( V_3 ) ;
F_13 ( & V_3 -> V_31 , V_32 + V_3 -> V_24 ) ;
}
}
void F_14 ( struct V_1 * V_2 )
{
struct V_33 V_34 ;
struct V_9 * V_3 ;
if ( F_15 ( & V_2 -> V_35 ) ) {
V_2 -> V_36 = 1 ;
return;
}
V_3 = V_2 -> V_3 ;
V_34 . V_37 = V_3 -> V_37 ;
V_34 . V_38 = V_2 -> V_38 ;
V_34 . V_39 = V_3 -> V_15 ;
V_34 . V_21 = V_3 -> V_21 ;
V_34 . V_14 = V_3 -> V_14 ;
V_34 . V_20 = V_2 -> V_20 ;
if ( F_16 ( V_3 ) )
V_34 . V_40 = 0 ;
else {
struct V_1 * V_39
= F_3 ( V_3 , V_3 -> V_10 ) ;
V_34 . V_40 = V_3 -> V_22
- ( V_39 -> V_41 . V_42 - V_32 )
+ V_43 ;
}
V_34 . V_22 = V_3 -> V_22 ;
V_34 . V_24 = V_3 -> V_24 ;
V_34 . V_26 = V_3 -> V_26 ;
if ( V_34 . V_40 < V_3 -> V_22 ) {
F_17 ( V_2 , & V_34 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_36 = 0 ;
F_13 ( & V_2 -> V_35 ,
F_18 ( V_32 + V_44 ) ) ;
}
}
static inline void F_19 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
V_2 -> V_15 = V_34 -> V_39 ;
V_2 -> V_16 = V_34 -> V_21 ;
V_2 -> V_18 = V_34 -> V_14 ;
V_2 -> V_19 = V_34 -> V_20 ;
F_13 ( & V_2 -> V_41 , V_32
+ ( V_2 -> V_3 -> V_22 - V_34 -> V_40 ) ) ;
}
static inline void F_20 ( struct V_9 * V_3 ,
const struct V_33 * V_34 )
{
V_3 -> V_22 = V_34 -> V_22 ;
V_3 -> V_24 = V_34 -> V_24 ;
V_3 -> V_26 = V_34 -> V_26 ;
V_3 -> V_37 = V_34 -> V_37 ;
}
void F_21 ( struct V_9 * V_3 )
{
F_22 ( F_3 ( V_3 , V_3 -> V_10 ) ) ;
}
static int F_23 ( const struct V_1 * V_2 )
{
struct V_9 * V_3 ;
int V_12 ;
V_3 = V_2 -> V_3 ;
if ( F_6 ( V_2 ) )
return 1 ;
if ( memcmp ( & V_2 -> V_15 , & V_3 -> V_15 , 8 ) )
return 1 ;
if ( V_3 -> V_21 < V_2 -> V_16 )
return 1 ;
else if ( V_3 -> V_21 > V_2 -> V_16 )
return 0 ;
V_12 = memcmp ( & V_3 -> V_14 , & V_2 -> V_18 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_2 -> V_20 < V_2 -> V_19 )
return 1 ;
return 0 ;
}
static void F_24 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
F_8 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_13 &&
F_23 ( V_2 ) )
F_25 ( V_2 ) ;
}
}
static int F_26 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
int V_12 ;
V_12 = memcmp ( & V_34 -> V_39 , & V_2 -> V_15 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_34 -> V_21 < V_2 -> V_16 )
return 1 ;
else if ( V_34 -> V_21 > V_2 -> V_16 )
return 0 ;
V_12 = memcmp ( & V_34 -> V_14 , & V_2 -> V_18 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( memcmp ( & V_34 -> V_14 , & V_2 -> V_3 -> V_14 , 8 ) )
return 1 ;
if ( V_34 -> V_20 <= V_2 -> V_19 )
return 1 ;
return 0 ;
}
static inline void F_27 ( struct V_9 * V_3 )
{
V_3 -> V_45 = 0 ;
F_11 ( & V_3 -> V_28 ) ;
}
void F_10 ( struct V_9 * V_3 )
{
int V_46 = F_16 ( V_3 ) ;
if ( V_3 -> V_47 != V_48 )
return;
F_2 ( V_3 , L_2 ,
V_46 ? L_3 : L_4 ) ;
if ( V_46 ) {
V_3 -> V_37 = 1 ;
F_13 ( & V_3 -> V_49 , V_32
+ V_3 -> V_27 + V_3 -> V_23 ) ;
} else if ( ! V_3 -> V_45 ) {
F_21 ( V_3 ) ;
F_13 ( & V_3 -> V_28 , V_32 + V_3 -> V_25 ) ;
}
V_3 -> V_45 = 1 ;
}
void F_12 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
F_8 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_13 &&
F_6 ( V_2 ) )
F_14 ( V_2 ) ;
}
}
static inline void F_28 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
}
void F_29 ( struct V_9 * V_3 )
{
F_7 ( V_3 ) ;
F_24 ( V_3 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_3 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_15 = V_3 -> V_15 ;
V_2 -> V_16 = V_3 -> V_21 ;
V_2 -> V_18 = V_3 -> V_14 ;
V_2 -> V_19 = V_2 -> V_20 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_13 &&
V_2 -> V_8 != V_50 ) {
if ( V_2 -> V_8 == V_51 ||
V_2 -> V_8 == V_52 )
F_10 ( V_2 -> V_3 ) ;
V_2 -> V_8 = V_50 ;
F_1 ( V_2 ) ;
F_11 ( & V_2 -> V_53 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 != V_50 )
return;
if ( V_3 -> V_47 == V_54 || V_3 -> V_26 == 0 ) {
V_2 -> V_8 = V_51 ;
F_10 ( V_3 ) ;
F_11 ( & V_2 -> V_53 ) ;
}
else if ( V_3 -> V_47 == V_48 )
V_2 -> V_8 = V_55 ;
else
V_2 -> V_8 = V_52 ;
F_32 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_3 -> V_26 != 0 )
F_13 ( & V_2 -> V_53 , V_32 + V_3 -> V_26 ) ;
}
void F_33 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
unsigned int V_56 = 0 ;
if ( V_3 -> V_47 == V_57 )
return;
F_8 (p, &br->port_list, list) {
if ( V_2 -> V_8 == V_13 )
continue;
if ( V_2 -> V_4 == V_3 -> V_10 ) {
V_2 -> V_36 = 0 ;
V_2 -> V_38 = 0 ;
F_31 ( V_2 ) ;
} else if ( F_6 ( V_2 ) ) {
F_11 ( & V_2 -> V_41 ) ;
F_31 ( V_2 ) ;
} else {
V_2 -> V_36 = 0 ;
V_2 -> V_38 = 0 ;
F_30 ( V_2 ) ;
}
if ( V_2 -> V_8 == V_51 )
++ V_56 ;
}
if ( V_56 == 0 )
F_34 ( V_3 -> V_5 ) ;
else
F_35 ( V_3 -> V_5 ) ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
V_2 -> V_38 = 1 ;
F_14 ( V_2 ) ;
}
void F_37 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_9 * V_3 ;
int V_58 ;
V_3 = V_2 -> V_3 ;
V_58 = F_16 ( V_3 ) ;
if ( F_26 ( V_2 , V_34 ) ) {
F_19 ( V_2 , V_34 ) ;
F_29 ( V_3 ) ;
F_33 ( V_3 ) ;
if ( ! F_16 ( V_3 ) && V_58 ) {
F_11 ( & V_3 -> V_31 ) ;
if ( V_3 -> V_45 ) {
F_11 ( & V_3 -> V_49 ) ;
F_21 ( V_3 ) ;
F_13 ( & V_3 -> V_28 ,
V_32 + V_3 -> V_25 ) ;
}
}
if ( V_2 -> V_4 == V_3 -> V_10 ) {
F_20 ( V_3 , V_34 ) ;
F_12 ( V_3 ) ;
if ( V_34 -> V_38 )
F_27 ( V_3 ) ;
}
} else if ( F_6 ( V_2 ) ) {
F_28 ( V_2 ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) ) {
F_2 ( V_2 -> V_3 , L_5 ,
( unsigned ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_10 ( V_2 -> V_3 ) ;
F_36 ( V_2 ) ;
}
}
int F_39 ( struct V_9 * V_3 , unsigned long V_59 )
{
unsigned long V_12 = F_40 ( V_59 ) ;
if ( V_12 < V_60 || V_12 > V_61 )
return - V_62 ;
F_41 ( & V_3 -> V_63 ) ;
V_3 -> V_25 = V_12 ;
if ( F_16 ( V_3 ) )
V_3 -> V_24 = V_3 -> V_25 ;
F_42 ( & V_3 -> V_63 ) ;
return 0 ;
}
int F_43 ( struct V_9 * V_3 , unsigned long V_59 )
{
unsigned long V_12 = F_40 ( V_59 ) ;
if ( V_12 < V_64 || V_12 > V_65 )
return - V_62 ;
F_41 ( & V_3 -> V_63 ) ;
V_3 -> V_23 = V_12 ;
if ( F_16 ( V_3 ) )
V_3 -> V_22 = V_3 -> V_23 ;
F_42 ( & V_3 -> V_63 ) ;
return 0 ;
}
int F_44 ( struct V_9 * V_3 , unsigned long V_59 )
{
unsigned long V_12 = F_40 ( V_59 ) ;
if ( V_3 -> V_47 != V_54 &&
( V_12 < V_66 || V_12 > V_67 ) )
return - V_62 ;
F_41 ( & V_3 -> V_63 ) ;
V_3 -> V_27 = V_12 ;
if ( F_16 ( V_3 ) )
V_3 -> V_26 = V_3 -> V_27 ;
F_42 ( & V_3 -> V_63 ) ;
return 0 ;
}
