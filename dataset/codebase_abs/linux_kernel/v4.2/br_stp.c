void F_1 ( const struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ,
V_7 [ V_2 -> V_8 ] ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_8 )
{
struct V_9 V_10 = {
. V_11 = V_12 ,
. V_13 . V_14 = V_8 ,
} ;
int V_15 ;
V_2 -> V_8 = V_8 ;
V_15 = F_4 ( V_2 -> V_5 , & V_10 ) ;
if ( V_15 && V_15 != - V_16 )
F_5 ( V_2 -> V_3 , L_2 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
}
struct V_1 * F_6 ( struct V_17 * V_3 , T_1 V_4 )
{
struct V_1 * V_2 ;
F_7 (p, &br->port_list, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static int F_8 ( const struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_17 * V_3 ;
struct V_1 * V_19 ;
int V_20 ;
V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 == V_21 ||
F_9 ( V_2 ) )
return 0 ;
if ( memcmp ( & V_3 -> V_22 , & V_2 -> V_23 , 8 ) <= 0 )
return 0 ;
if ( ! V_18 )
return 1 ;
V_19 = F_6 ( V_3 , V_18 ) ;
V_20 = memcmp ( & V_2 -> V_23 , & V_19 -> V_23 , 8 ) ;
if ( V_20 < 0 )
return 1 ;
else if ( V_20 > 0 )
return 0 ;
if ( V_2 -> V_24 + V_2 -> V_25 <
V_19 -> V_24 + V_19 -> V_25 )
return 1 ;
else if ( V_2 -> V_24 + V_2 -> V_25 >
V_19 -> V_24 + V_19 -> V_25 )
return 0 ;
V_20 = memcmp ( & V_2 -> V_26 , & V_19 -> V_26 , 8 ) ;
if ( V_20 < 0 )
return 1 ;
else if ( V_20 > 0 )
return 0 ;
if ( V_2 -> V_27 < V_19 -> V_27 )
return 1 ;
else if ( V_2 -> V_27 > V_19 -> V_27 )
return 0 ;
if ( V_2 -> V_28 < V_19 -> V_28 )
return 1 ;
return 0 ;
}
static void F_10 ( const struct V_17 * V_3 ,
struct V_1 * V_2 )
{
F_11 ( V_3 , L_3 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_3 ( V_2 , V_29 ) ;
F_1 ( V_2 ) ;
F_12 ( V_30 , V_2 ) ;
if ( V_3 -> V_31 > 0 )
F_13 ( & V_2 -> V_32 , V_33 + V_3 -> V_31 ) ;
}
static void F_14 ( struct V_17 * V_3 )
{
struct V_1 * V_2 ;
T_1 V_18 = 0 ;
F_15 (p, &br->port_list, list) {
if ( ! F_8 ( V_2 , V_18 ) )
continue;
if ( V_2 -> V_34 & V_35 )
F_10 ( V_3 , V_2 ) ;
else
V_18 = V_2 -> V_4 ;
}
V_3 -> V_18 = V_18 ;
if ( ! V_18 ) {
V_3 -> V_23 = V_3 -> V_22 ;
V_3 -> V_36 = 0 ;
} else {
V_2 = F_6 ( V_3 , V_18 ) ;
V_3 -> V_23 = V_2 -> V_23 ;
V_3 -> V_36 = V_2 -> V_24 + V_2 -> V_25 ;
}
}
void F_16 ( struct V_17 * V_3 )
{
V_3 -> V_37 = V_3 -> V_38 ;
V_3 -> V_39 = V_3 -> V_40 ;
V_3 -> V_31 = V_3 -> V_41 ;
F_17 ( V_3 ) ;
F_18 ( & V_3 -> V_42 ) ;
if ( V_3 -> V_5 -> V_34 & V_43 ) {
F_19 ( V_3 ) ;
F_13 ( & V_3 -> V_44 , V_33 + V_3 -> V_39 ) ;
}
}
void F_20 ( struct V_1 * V_2 )
{
struct V_45 V_46 ;
struct V_17 * V_3 ;
if ( F_21 ( & V_2 -> V_47 ) ) {
V_2 -> V_48 = 1 ;
return;
}
V_3 = V_2 -> V_3 ;
V_46 . V_49 = V_3 -> V_49 ;
V_46 . V_50 = V_2 -> V_50 ;
V_46 . V_51 = V_3 -> V_23 ;
V_46 . V_36 = V_3 -> V_36 ;
V_46 . V_22 = V_3 -> V_22 ;
V_46 . V_28 = V_2 -> V_28 ;
if ( F_22 ( V_3 ) )
V_46 . V_52 = 0 ;
else {
struct V_1 * V_51
= F_6 ( V_3 , V_3 -> V_18 ) ;
V_46 . V_52 = ( V_33 - V_51 -> V_53 )
+ V_54 ;
}
V_46 . V_37 = V_3 -> V_37 ;
V_46 . V_39 = V_3 -> V_39 ;
V_46 . V_31 = V_3 -> V_31 ;
if ( V_46 . V_52 < V_3 -> V_37 ) {
F_23 ( V_2 , & V_46 ) ;
V_2 -> V_50 = 0 ;
V_2 -> V_48 = 0 ;
if ( V_2 -> V_3 -> V_55 == V_56 )
F_13 ( & V_2 -> V_47 ,
F_24 ( V_33 + V_57 ) ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
V_2 -> V_23 = V_46 -> V_51 ;
V_2 -> V_24 = V_46 -> V_36 ;
V_2 -> V_26 = V_46 -> V_22 ;
V_2 -> V_27 = V_46 -> V_28 ;
V_2 -> V_53 = V_33 - V_46 -> V_52 ;
F_13 ( & V_2 -> V_58 , V_33
+ ( V_46 -> V_37 - V_46 -> V_52 ) ) ;
}
static void F_26 ( struct V_17 * V_3 ,
const struct V_45 * V_46 )
{
V_3 -> V_37 = V_46 -> V_37 ;
V_3 -> V_39 = V_46 -> V_39 ;
V_3 -> V_31 = V_46 -> V_31 ;
V_3 -> V_49 = V_46 -> V_49 ;
}
void F_27 ( struct V_17 * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_3 , V_3 -> V_18 ) ;
if ( V_2 )
F_28 ( V_2 ) ;
else
F_11 ( V_3 , L_4 ,
V_3 -> V_18 ) ;
}
static int F_29 ( const struct V_1 * V_2 )
{
struct V_17 * V_3 ;
int V_20 ;
V_3 = V_2 -> V_3 ;
if ( F_9 ( V_2 ) )
return 1 ;
if ( memcmp ( & V_2 -> V_23 , & V_3 -> V_23 , 8 ) )
return 1 ;
if ( V_3 -> V_36 < V_2 -> V_24 )
return 1 ;
else if ( V_3 -> V_36 > V_2 -> V_24 )
return 0 ;
V_20 = memcmp ( & V_3 -> V_22 , & V_2 -> V_26 , 8 ) ;
if ( V_20 < 0 )
return 1 ;
else if ( V_20 > 0 )
return 0 ;
if ( V_2 -> V_28 < V_2 -> V_27 )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_17 * V_3 )
{
struct V_1 * V_2 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_21 &&
F_29 ( V_2 ) )
F_31 ( V_2 ) ;
}
}
static int F_32 ( const struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
int V_20 ;
V_20 = memcmp ( & V_46 -> V_51 , & V_2 -> V_23 , 8 ) ;
if ( V_20 < 0 )
return 1 ;
else if ( V_20 > 0 )
return 0 ;
if ( V_46 -> V_36 < V_2 -> V_24 )
return 1 ;
else if ( V_46 -> V_36 > V_2 -> V_24 )
return 0 ;
V_20 = memcmp ( & V_46 -> V_22 , & V_2 -> V_26 , 8 ) ;
if ( V_20 < 0 )
return 1 ;
else if ( V_20 > 0 )
return 0 ;
if ( memcmp ( & V_46 -> V_22 , & V_2 -> V_3 -> V_22 , 8 ) )
return 1 ;
if ( V_46 -> V_28 <= V_2 -> V_27 )
return 1 ;
return 0 ;
}
static void F_33 ( struct V_17 * V_3 )
{
V_3 -> V_59 = 0 ;
F_18 ( & V_3 -> V_42 ) ;
}
void F_17 ( struct V_17 * V_3 )
{
int V_60 = F_22 ( V_3 ) ;
if ( V_3 -> V_55 != V_56 )
return;
F_2 ( V_3 , L_5 ,
V_60 ? L_6 : L_7 ) ;
if ( V_60 ) {
V_3 -> V_49 = 1 ;
F_13 ( & V_3 -> V_61 , V_33
+ V_3 -> V_41 + V_3 -> V_38 ) ;
} else if ( ! V_3 -> V_59 ) {
F_27 ( V_3 ) ;
F_13 ( & V_3 -> V_42 , V_33 + V_3 -> V_40 ) ;
}
V_3 -> V_59 = 1 ;
}
void F_19 ( struct V_17 * V_3 )
{
struct V_1 * V_2 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_21 &&
F_9 ( V_2 ) )
F_20 ( V_2 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
void F_35 ( struct V_17 * V_3 )
{
F_14 ( V_3 ) ;
F_30 ( V_3 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_17 * V_3 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_23 = V_3 -> V_23 ;
V_2 -> V_24 = V_3 -> V_36 ;
V_2 -> V_26 = V_3 -> V_22 ;
V_2 -> V_27 = V_2 -> V_28 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_21 &&
V_2 -> V_8 != V_62 ) {
if ( V_2 -> V_8 == V_63 ||
V_2 -> V_8 == V_64 )
F_17 ( V_2 -> V_3 ) ;
F_3 ( V_2 , V_62 ) ;
F_1 ( V_2 ) ;
F_12 ( V_30 , V_2 ) ;
F_18 ( & V_2 -> V_32 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_17 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 != V_62 )
return;
if ( V_3 -> V_55 == V_65 || V_3 -> V_31 == 0 ) {
F_3 ( V_2 , V_63 ) ;
F_17 ( V_3 ) ;
F_18 ( & V_2 -> V_32 ) ;
} else if ( V_3 -> V_55 == V_56 )
F_3 ( V_2 , V_29 ) ;
else
F_3 ( V_2 , V_64 ) ;
F_1 ( V_2 ) ;
F_12 ( V_30 , V_2 ) ;
if ( V_3 -> V_31 != 0 )
F_13 ( & V_2 -> V_32 , V_33 + V_3 -> V_31 ) ;
}
void F_38 ( struct V_17 * V_3 )
{
struct V_1 * V_2 ;
unsigned int V_66 = 0 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 == V_21 )
continue;
if ( V_3 -> V_55 != V_67 ) {
if ( V_2 -> V_4 == V_3 -> V_18 ) {
V_2 -> V_48 = 0 ;
V_2 -> V_50 = 0 ;
F_37 ( V_2 ) ;
} else if ( F_9 ( V_2 ) ) {
F_18 ( & V_2 -> V_58 ) ;
F_37 ( V_2 ) ;
} else {
V_2 -> V_48 = 0 ;
V_2 -> V_50 = 0 ;
F_36 ( V_2 ) ;
}
}
if ( V_2 -> V_8 != V_62 )
F_39 ( V_2 ) ;
if ( V_2 -> V_8 == V_63 )
++ V_66 ;
}
if ( V_66 == 0 )
F_40 ( V_3 -> V_5 ) ;
else
F_41 ( V_3 -> V_5 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_50 = 1 ;
F_20 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_17 * V_3 ;
int V_68 ;
V_3 = V_2 -> V_3 ;
V_68 = F_22 ( V_3 ) ;
if ( F_32 ( V_2 , V_46 ) ) {
F_25 ( V_2 , V_46 ) ;
F_35 ( V_3 ) ;
F_38 ( V_3 ) ;
if ( ! F_22 ( V_3 ) && V_68 ) {
F_18 ( & V_3 -> V_44 ) ;
if ( V_3 -> V_59 ) {
F_18 ( & V_3 -> V_61 ) ;
F_27 ( V_3 ) ;
F_13 ( & V_3 -> V_42 ,
V_33 + V_3 -> V_40 ) ;
}
}
if ( V_2 -> V_4 == V_3 -> V_18 ) {
F_26 ( V_3 , V_46 ) ;
F_19 ( V_3 ) ;
if ( V_46 -> V_50 )
F_33 ( V_3 ) ;
}
} else if ( F_9 ( V_2 ) ) {
F_34 ( V_2 ) ;
}
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) ) {
F_2 ( V_2 -> V_3 , L_8 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_17 ( V_2 -> V_3 ) ;
F_42 ( V_2 ) ;
}
}
int F_45 ( struct V_17 * V_3 , unsigned long V_69 )
{
unsigned long V_20 = F_46 ( V_69 ) ;
if ( V_20 < V_70 || V_20 > V_71 )
return - V_72 ;
F_47 ( & V_3 -> V_73 ) ;
V_3 -> V_40 = V_20 ;
if ( F_22 ( V_3 ) )
V_3 -> V_39 = V_3 -> V_40 ;
F_48 ( & V_3 -> V_73 ) ;
return 0 ;
}
int F_49 ( struct V_17 * V_3 , unsigned long V_69 )
{
unsigned long V_20 = F_46 ( V_69 ) ;
if ( V_20 < V_74 || V_20 > V_75 )
return - V_72 ;
F_47 ( & V_3 -> V_73 ) ;
V_3 -> V_38 = V_20 ;
if ( F_22 ( V_3 ) )
V_3 -> V_37 = V_3 -> V_38 ;
F_48 ( & V_3 -> V_73 ) ;
return 0 ;
}
void F_50 ( struct V_17 * V_3 , unsigned long V_20 )
{
V_3 -> V_41 = V_20 ;
if ( F_22 ( V_3 ) )
V_3 -> V_31 = V_3 -> V_41 ;
}
int F_51 ( struct V_17 * V_3 , unsigned long V_69 )
{
unsigned long V_20 = F_46 ( V_69 ) ;
int V_15 = - V_72 ;
F_47 ( & V_3 -> V_73 ) ;
if ( V_3 -> V_55 != V_65 &&
( V_20 < V_76 || V_20 > V_77 ) )
goto V_78;
F_50 ( V_3 , V_20 ) ;
V_15 = 0 ;
V_78:
F_48 ( & V_3 -> V_73 ) ;
return V_15 ;
}
