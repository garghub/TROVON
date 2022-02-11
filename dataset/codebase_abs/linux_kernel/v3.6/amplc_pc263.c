static const struct V_1 * F_1 ( struct V_2 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_5 == V_6 &&
V_2 -> V_7 == V_4 [ V_3 ] . V_8 )
return & V_4 [ V_3 ] ;
return NULL ;
}
static struct V_2 * F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_2 * V_2 = NULL ;
int V_14 = V_12 -> V_15 [ 0 ] ;
int V_16 = V_12 -> V_15 [ 1 ] ;
F_5 (pci_dev) {
if ( V_14 || V_16 ) {
if ( V_14 != V_2 -> V_14 -> V_17 ||
V_16 != F_6 ( V_2 -> V_18 ) )
continue;
}
if ( V_2 -> V_19 != V_20 )
continue;
if ( V_13 -> V_21 == V_22 ) {
const struct V_1 * V_23 ;
V_23 = F_1 ( V_2 ) ;
if ( V_23 == NULL )
continue;
V_10 -> V_24 = V_13 = V_23 ;
} else {
if ( V_2 -> V_7 != V_13 -> V_8 )
continue;
}
return V_2 ;
}
F_7 ( V_10 -> V_25 ,
L_1 ,
V_14 , V_16 ) ;
return NULL ;
}
static int F_8 ( struct V_9 * V_10 , unsigned long V_26 ,
unsigned long V_27 )
{
if ( ! V_26 || ! F_9 ( V_26 , V_27 , V_28 ) ) {
F_7 ( V_10 -> V_25 , L_2 ,
V_26 , V_27 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_34 )
{
if ( V_34 [ 0 ] ) {
V_31 -> V_35 &= ~ V_34 [ 0 ] ;
V_31 -> V_35 |= V_34 [ 0 ] & V_34 [ 1 ] ;
F_11 ( V_31 -> V_35 & 0xFF , V_10 -> V_36 ) ;
F_11 ( V_31 -> V_35 >> 8 , V_10 -> V_36 + 1 ) ;
}
return V_33 -> V_37 ;
}
static void F_12 ( struct V_9 * V_10 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_2 * V_38 = F_13 ( V_10 ) ;
char V_39 [ 40 ] ;
if ( F_14 ( V_40 ) &&
V_13 -> V_5 == V_41 )
snprintf ( V_39 , sizeof( V_39 ) , L_3 , V_10 -> V_36 ) ;
else if ( F_14 ( V_42 ) &&
V_13 -> V_5 == V_6 )
snprintf ( V_39 , sizeof( V_39 ) , L_4 ,
F_15 ( V_38 ) ) ;
else
V_39 [ 0 ] = '\0' ;
F_16 ( V_10 -> V_25 , L_5 , V_10 -> V_43 , V_39 ) ;
}
static int F_17 ( struct V_9 * V_10 , unsigned long V_36 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_30 * V_31 ;
int V_44 ;
V_10 -> V_43 = V_13 -> V_45 ;
V_10 -> V_36 = V_36 ;
V_44 = F_18 ( V_10 , 1 ) ;
if ( V_44 )
return V_44 ;
V_31 = V_10 -> V_46 + 0 ;
V_31 -> type = V_47 ;
V_31 -> V_48 = V_49 | V_50 ;
V_31 -> V_51 = 16 ;
V_31 -> V_52 = 1 ;
V_31 -> V_53 = & V_54 ;
V_31 -> V_55 = F_10 ;
V_31 -> V_35 = F_19 ( V_10 -> V_36 ) | ( F_19 ( V_10 -> V_36 + 1 ) << 8 ) ;
F_12 ( V_10 ) ;
return 1 ;
}
static int F_20 ( struct V_9 * V_10 ,
struct V_2 * V_2 )
{
unsigned long V_36 ;
int V_44 ;
F_21 ( V_10 , & V_2 -> V_10 ) ;
V_44 = F_22 ( V_2 , V_28 ) ;
if ( V_44 < 0 ) {
F_7 ( V_10 -> V_25 ,
L_6 ) ;
return V_44 ;
}
V_36 = F_23 ( V_2 , 2 ) ;
return F_17 ( V_10 , V_36 ) ;
}
static int F_24 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
int V_44 ;
F_16 ( V_10 -> V_25 , V_28 L_7 ) ;
if ( F_14 ( V_40 ) &&
V_13 -> V_5 == V_41 ) {
unsigned long V_36 = V_12 -> V_15 [ 0 ] ;
V_44 = F_8 ( V_10 , V_36 , V_56 ) ;
if ( V_44 < 0 )
return V_44 ;
return F_17 ( V_10 , V_36 ) ;
} else if ( F_14 ( V_42 ) &&
V_13 -> V_5 == V_6 ) {
struct V_2 * V_2 ;
V_2 = F_3 ( V_10 , V_12 ) ;
if ( ! V_2 )
return - V_29 ;
return F_20 ( V_10 , V_2 ) ;
} else {
F_7 ( V_10 -> V_25 , V_28
L_8 ) ;
return - V_57 ;
}
}
static int T_1 F_25 ( struct V_9 * V_10 ,
struct V_2 * V_2 )
{
if ( ! F_14 ( V_42 ) )
return - V_57 ;
F_16 ( V_10 -> V_25 , V_28 L_9 ,
F_15 ( V_2 ) ) ;
V_10 -> V_24 = F_1 ( V_2 ) ;
if ( V_10 -> V_24 == NULL ) {
F_7 ( V_10 -> V_25 , L_10 ) ;
return - V_57 ;
}
F_26 ( V_2 ) ;
return F_20 ( V_10 , V_2 ) ;
}
static void F_27 ( struct V_9 * V_10 )
{
struct V_2 * V_38 = F_13 ( V_10 ) ;
if ( V_38 ) {
if ( V_10 -> V_36 )
F_28 ( V_38 ) ;
F_29 ( V_38 ) ;
} else {
if ( V_10 -> V_36 )
F_30 ( V_10 -> V_36 , V_56 ) ;
}
}
static int T_1 F_31 ( struct V_2 * V_10 ,
const struct V_58
* V_59 )
{
return F_32 ( V_10 , & V_60 ) ;
}
static void T_2 F_33 ( struct V_2 * V_10 )
{
F_34 ( V_10 ) ;
}
