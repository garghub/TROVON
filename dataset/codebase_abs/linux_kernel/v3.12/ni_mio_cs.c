static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
F_2 ( & V_6 -> V_9 , V_8 ) ;
if ( V_4 < 8 ) {
F_3 ( V_3 , V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_10 ) ;
F_3 ( V_3 , V_11 ) ;
}
F_4 ( & V_6 -> V_9 , V_8 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
T_1 V_12 ;
F_2 ( & V_6 -> V_9 , V_8 ) ;
if ( V_4 < 8 ) {
V_12 = F_6 ( V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_10 ) ;
V_12 = F_6 ( V_11 ) ;
}
F_4 ( & V_6 -> V_9 , V_8 ) ;
return V_12 ;
}
static const void * F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
static const struct V_15 * V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_8 ( V_18 ) ; V_17 ++ ) {
V_16 = & V_18 [ V_17 ] ;
if ( V_16 -> V_19 == V_14 -> V_20 )
return V_16 ;
}
return NULL ;
}
static int F_9 ( struct V_13 * V_21 , void * V_22 )
{
int V_23 , V_12 ;
V_21 -> V_24 [ 0 ] -> V_8 &= ~ V_25 ;
V_21 -> V_24 [ 0 ] -> V_8 |= V_26 ;
for ( V_23 = 0x000 ; V_23 < 0x400 ; V_23 += 0x20 ) {
V_21 -> V_24 [ 0 ] -> V_27 = V_23 ;
V_12 = F_10 ( V_21 ) ;
if ( ! V_12 )
return 0 ;
}
return - V_28 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
struct V_13 * V_14 = F_12 ( V_2 ) ;
static const struct V_15 * V_16 ;
struct V_5 * V_6 ;
int V_12 ;
V_16 = F_7 ( V_2 , V_14 ) ;
if ( ! V_16 )
return - V_28 ;
V_2 -> V_30 = V_16 ;
V_2 -> V_31 = V_16 -> V_32 ;
V_14 -> V_33 |= V_34 | V_35 ;
V_12 = F_13 ( V_2 , F_9 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_36 = V_14 -> V_24 [ 0 ] -> V_27 ;
V_14 -> V_37 = V_2 ;
V_12 = F_14 ( V_14 , V_38 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_39 = V_14 -> V_39 ;
V_12 = F_15 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_40 = F_1 ;
V_6 -> V_41 = F_5 ;
V_6 -> V_42 = V_43 ;
V_6 -> V_44 = V_45 ;
return F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_13 * V_14 )
{
return F_21 ( V_14 , & V_46 ) ;
}
