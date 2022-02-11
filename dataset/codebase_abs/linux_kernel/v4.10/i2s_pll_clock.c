static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline struct V_1 * F_5 ( struct V_6 * V_7 )
{
return F_6 ( V_7 , struct V_1 , V_7 ) ;
}
static inline unsigned int F_7 ( unsigned int V_4 )
{
return ( V_4 & 0x3F ) + ( ( V_4 >> 6 ) & 0x3F ) ;
}
static const struct V_8 * F_8 ( unsigned long V_9 )
{
switch ( V_9 ) {
case 27000000 :
return V_10 ;
case 28224000 :
return V_11 ;
default:
return NULL ;
}
}
static unsigned long F_9 ( struct V_6 * V_7 ,
unsigned long V_12 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_13 , V_14 , V_15 ;
V_13 = F_7 ( F_3 ( V_2 , V_16 ) ) ;
V_14 = F_7 ( F_3 ( V_2 , V_17 ) ) ;
V_15 = F_7 ( F_3 ( V_2 , V_18 ) ) ;
return ( ( V_12 / V_13 ) * V_14 ) / V_15 ;
}
static long F_10 ( struct V_6 * V_7 , unsigned long V_19 ,
unsigned long * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
const struct V_8 * V_20 = F_8 ( * V_9 ) ;
int V_21 ;
if ( ! V_20 ) {
F_11 ( V_2 -> V_22 , L_1 , * V_9 ) ;
return - V_23 ;
}
for ( V_21 = 0 ; V_20 [ V_21 ] . V_19 != 0 ; V_21 ++ )
if ( V_20 [ V_21 ] . V_19 == V_19 )
return V_19 ;
return - V_23 ;
}
static int F_12 ( struct V_6 * V_7 , unsigned long V_19 ,
unsigned long V_12 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
const struct V_8 * V_20 = F_8 ( V_12 ) ;
int V_21 ;
if ( ! V_20 ) {
F_11 ( V_2 -> V_22 , L_1 , V_12 ) ;
return - V_23 ;
}
for ( V_21 = 0 ; V_20 [ V_21 ] . V_19 != 0 ; V_21 ++ ) {
if ( V_20 [ V_21 ] . V_19 == V_19 ) {
F_1 ( V_2 , V_16 , V_20 [ V_21 ] . V_13 ) ;
F_1 ( V_2 , V_17 , V_20 [ V_21 ] . V_14 ) ;
F_1 ( V_2 , V_18 , V_20 [ V_21 ] . V_24 ) ;
F_1 ( V_2 , V_25 , V_20 [ V_21 ] . V_26 ) ;
return 0 ;
}
}
F_11 ( V_2 -> V_22 , L_2 , V_19 ,
V_12 ) ;
return - V_23 ;
}
static int F_13 ( struct V_27 * V_28 )
{
struct V_29 * V_22 = & V_28 -> V_22 ;
struct V_30 * V_31 = V_22 -> V_32 ;
const char * V_33 ;
const char * V_34 ;
struct V_2 * V_2 ;
struct V_1 * V_35 ;
struct V_36 V_37 ;
struct V_38 * V_39 ;
V_35 = F_14 ( V_22 , sizeof( * V_35 ) , V_40 ) ;
if ( ! V_35 )
return - V_41 ;
V_39 = F_15 ( V_28 , V_42 , 0 ) ;
V_35 -> V_5 = F_16 ( V_22 , V_39 ) ;
if ( F_17 ( V_35 -> V_5 ) )
return F_18 ( V_35 -> V_5 ) ;
V_33 = V_31 -> V_43 ;
V_37 . V_43 = V_33 ;
V_37 . V_44 = & V_45 ;
V_34 = F_19 ( V_31 , 0 ) ;
V_37 . V_46 = & V_34 ;
V_37 . V_47 = 1 ;
V_35 -> V_7 . V_37 = & V_37 ;
V_35 -> V_22 = V_22 ;
V_2 = F_20 ( V_22 , & V_35 -> V_7 ) ;
if ( F_17 ( V_2 ) ) {
F_11 ( V_22 , L_3 ,
V_33 , F_18 ( V_2 ) ) ;
return F_18 ( V_2 ) ;
}
return F_21 ( V_31 , V_48 , V_2 ) ;
}
static int F_22 ( struct V_27 * V_28 )
{
F_23 ( V_28 -> V_22 . V_32 ) ;
return 0 ;
}
