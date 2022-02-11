static inline bool F_1 ( const struct V_1 * V_2 )
{
return V_3 && V_2 -> V_4 == V_5 ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return V_6 && V_2 -> V_4 == V_7 ;
}
static const struct V_1 * F_3 ( struct V_8 * V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ )
if ( F_2 ( & V_10 [ V_9 ] ) &&
V_8 -> V_11 == V_10 [ V_9 ] . V_12 )
return & V_10 [ V_9 ] ;
return NULL ;
}
static struct V_8 * F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_8 * V_8 = NULL ;
int V_18 = V_16 -> V_19 [ 0 ] ;
int V_20 = V_16 -> V_19 [ 1 ] ;
F_7 (pci_dev) {
if ( V_18 || V_20 ) {
if ( V_18 != V_8 -> V_18 -> V_21 ||
V_20 != F_8 ( V_8 -> V_22 ) )
continue;
}
if ( V_8 -> V_23 != V_24 )
continue;
if ( V_17 -> V_25 == V_26 ) {
const struct V_1 * V_27 ;
V_27 = F_3 ( V_8 ) ;
if ( V_27 == NULL )
continue;
V_14 -> V_28 = V_17 = V_27 ;
} else {
if ( V_8 -> V_11 != V_17 -> V_12 )
continue;
}
return V_8 ;
}
F_9 ( V_14 -> V_29 ,
L_1 ,
V_18 , V_20 ) ;
return NULL ;
}
static int F_10 ( struct V_13 * V_14 , unsigned long V_30 ,
unsigned long V_31 )
{
if ( ! V_30 || ! F_11 ( V_30 , V_31 , V_32 ) ) {
F_9 ( V_14 -> V_29 , L_2 ,
V_30 , V_31 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
if ( V_38 [ 0 ] ) {
V_35 -> V_39 &= ~ V_38 [ 0 ] ;
V_35 -> V_39 |= V_38 [ 0 ] & V_38 [ 1 ] ;
F_13 ( V_35 -> V_39 & 0xFF , V_14 -> V_40 ) ;
F_13 ( V_35 -> V_39 >> 8 , V_14 -> V_40 + 1 ) ;
}
return V_37 -> V_41 ;
}
static void F_14 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_8 * V_42 = F_15 ( V_14 ) ;
char V_43 [ 40 ] ;
if ( F_1 ( V_17 ) )
snprintf ( V_43 , sizeof( V_43 ) , L_3 , V_14 -> V_40 ) ;
else if ( F_2 ( V_17 ) )
snprintf ( V_43 , sizeof( V_43 ) , L_4 ,
F_16 ( V_42 ) ) ;
else
V_43 [ 0 ] = '\0' ;
F_17 ( V_14 -> V_29 , L_5 , V_14 -> V_44 , V_43 ) ;
}
static int F_18 ( struct V_13 * V_14 , unsigned long V_40 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_34 * V_35 ;
int V_45 ;
V_14 -> V_44 = V_17 -> V_46 ;
V_14 -> V_40 = V_40 ;
V_45 = F_19 ( V_14 , 1 ) ;
if ( V_45 )
return V_45 ;
V_35 = & V_14 -> V_47 [ 0 ] ;
V_35 -> type = V_48 ;
V_35 -> V_49 = V_50 | V_51 ;
V_35 -> V_52 = 16 ;
V_35 -> V_53 = 1 ;
V_35 -> V_54 = & V_55 ;
V_35 -> V_56 = F_12 ;
V_35 -> V_39 = F_20 ( V_14 -> V_40 ) | ( F_20 ( V_14 -> V_40 + 1 ) << 8 ) ;
F_14 ( V_14 ) ;
return 1 ;
}
static int F_21 ( struct V_13 * V_14 ,
struct V_8 * V_8 )
{
unsigned long V_40 ;
int V_45 ;
F_22 ( V_14 , & V_8 -> V_14 ) ;
V_45 = F_23 ( V_8 , V_32 ) ;
if ( V_45 < 0 ) {
F_9 ( V_14 -> V_29 ,
L_6 ) ;
return V_45 ;
}
V_40 = F_24 ( V_8 , 2 ) ;
return F_18 ( V_14 , V_40 ) ;
}
static int F_25 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
int V_45 ;
F_17 ( V_14 -> V_29 , V_32 L_7 ) ;
if ( F_1 ( V_17 ) ) {
unsigned long V_40 = V_16 -> V_19 [ 0 ] ;
V_45 = F_10 ( V_14 , V_40 , V_57 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_18 ( V_14 , V_40 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_8 ;
V_8 = F_5 ( V_14 , V_16 ) ;
if ( ! V_8 )
return - V_33 ;
return F_21 ( V_14 , V_8 ) ;
} else {
F_9 ( V_14 -> V_29 , V_32
L_8 ) ;
return - V_58 ;
}
}
static int F_26 ( struct V_13 * V_14 ,
unsigned long V_59 )
{
struct V_8 * V_8 ;
if ( ! V_6 )
return - V_58 ;
V_8 = F_15 ( V_14 ) ;
F_17 ( V_14 -> V_29 , V_32 L_9 ,
F_16 ( V_8 ) ) ;
V_14 -> V_28 = F_3 ( V_8 ) ;
if ( V_14 -> V_28 == NULL ) {
F_9 ( V_14 -> V_29 , L_10 ) ;
return - V_58 ;
}
F_27 ( V_8 ) ;
return F_21 ( V_14 , V_8 ) ;
}
static void F_28 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
if ( ! V_17 )
return;
if ( F_1 ( V_17 ) ) {
if ( V_14 -> V_40 )
F_29 ( V_14 -> V_40 , V_57 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_42 = F_15 ( V_14 ) ;
if ( V_42 ) {
if ( V_14 -> V_40 )
F_30 ( V_42 ) ;
F_31 ( V_42 ) ;
}
}
}
static int F_32 ( struct V_8 * V_14 ,
const struct V_60
* V_61 )
{
return F_33 ( V_14 , & V_62 ) ;
}
