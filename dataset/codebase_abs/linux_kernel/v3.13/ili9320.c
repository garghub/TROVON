static inline int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_6 ;
unsigned char * V_8 = V_6 -> V_9 ;
unsigned char * V_10 = V_6 -> V_11 ;
V_8 [ 0 ] = V_6 -> V_12 | V_13 | V_14 ;
V_8 [ 1 ] = V_3 >> 8 ;
V_8 [ 2 ] = V_3 ;
V_10 [ 0 ] = V_6 -> V_12 | V_15 | V_14 ;
V_10 [ 1 ] = V_4 >> 8 ;
V_10 [ 2 ] = V_4 ;
return F_2 ( V_6 -> V_16 , & V_6 -> V_17 ) ;
}
int F_3 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
F_4 ( V_2 -> V_16 , L_1 , V_3 , V_4 ) ;
return V_2 -> V_18 ( V_2 , V_3 , V_4 ) ;
}
int F_5 ( struct V_1 * V_2 ,
const struct V_19 * V_20 ,
int V_21 )
{
int V_22 ;
int V_23 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ , V_20 ++ ) {
V_23 = F_3 ( V_2 , V_20 -> V_24 , V_20 -> V_4 ) ;
if ( V_23 != 0 )
return V_23 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
V_27 -> V_29 ( 1 ) ;
F_7 ( 50 ) ;
V_27 -> V_29 ( 0 ) ;
F_7 ( 50 ) ;
V_27 -> V_29 ( 1 ) ;
F_7 ( 100 ) ;
}
static inline int F_8 ( struct V_1 * V_25 )
{
int V_23 ;
F_6 ( V_25 ) ;
V_23 = V_25 -> V_30 -> V_31 ( V_25 , V_25 -> V_28 ) ;
if ( V_23 != 0 ) {
F_9 ( V_25 -> V_16 , L_2 ) ;
return V_23 ;
}
V_25 -> V_32 = 1 ;
return 0 ;
}
static inline int F_10 ( struct V_1 * V_25 )
{
if ( ! V_25 -> V_32 )
F_8 ( V_25 ) ;
V_25 -> V_33 |= ( F_11 ( 3 ) | V_34 ) ;
F_3 ( V_25 , V_35 , V_25 -> V_33 ) ;
return 0 ;
}
static inline int F_12 ( struct V_1 * V_25 )
{
V_25 -> V_33 &= ~ ( F_11 ( 3 ) | V_34 ) ;
F_3 ( V_25 , V_35 , V_25 -> V_33 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_25 , int V_36 )
{
int V_23 = 0 ;
F_4 ( V_25 -> V_16 , L_3 , V_25 -> V_36 , V_36 ) ;
if ( F_14 ( V_36 ) && ! F_14 ( V_25 -> V_36 ) )
V_23 = F_10 ( V_25 ) ;
else if ( ! F_14 ( V_36 ) && F_14 ( V_25 -> V_36 ) )
V_23 = F_12 ( V_25 ) ;
if ( V_23 == 0 )
V_25 -> V_36 = V_36 ;
else
F_15 ( V_25 -> V_16 , L_4 , V_36 ) ;
return V_23 ;
}
static inline struct V_1 * F_16 ( struct V_37 * V_25 )
{
return F_17 ( V_25 ) ;
}
static int F_18 ( struct V_37 * V_38 , int V_36 )
{
struct V_1 * V_25 = F_16 ( V_38 ) ;
return F_13 ( V_25 , V_36 ) ;
}
static int F_19 ( struct V_37 * V_38 )
{
struct V_1 * V_25 = F_16 ( V_38 ) ;
return V_25 -> V_36 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_39 * V_16 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_6 ;
V_2 -> V_18 = F_1 ;
V_6 -> V_16 = V_16 ;
V_6 -> V_40 [ 0 ] . V_41 = V_6 -> V_9 ;
V_6 -> V_40 [ 1 ] . V_41 = V_6 -> V_11 ;
V_6 -> V_40 [ 0 ] . V_42 = 3 ;
V_6 -> V_40 [ 1 ] . V_42 = 3 ;
V_6 -> V_40 [ 0 ] . V_43 = 8 ;
V_6 -> V_40 [ 1 ] . V_43 = 8 ;
V_6 -> V_40 [ 0 ] . V_44 = 1 ;
F_21 ( & V_6 -> V_17 ) ;
F_22 ( & V_6 -> V_40 [ 0 ] , & V_6 -> V_17 ) ;
F_22 ( & V_6 -> V_40 [ 1 ] , & V_6 -> V_17 ) ;
}
int F_23 ( struct V_39 * V_6 ,
struct V_45 * V_30 )
{
struct V_26 * V_27 = F_24 ( & V_6 -> V_16 ) ;
struct V_46 * V_16 = & V_6 -> V_16 ;
struct V_1 * V_2 ;
struct V_37 * V_25 ;
int V_23 = 0 ;
if ( V_27 == NULL ) {
F_9 ( V_16 , L_5 ) ;
return - V_47 ;
}
if ( V_27 -> V_48 <= 0 || V_27 -> V_49 <= 0 || V_27 -> V_29 == NULL ) {
F_9 ( V_16 , L_6 ) ;
return - V_47 ;
}
V_2 = F_25 ( & V_6 -> V_16 , sizeof( struct V_1 ) , V_50 ) ;
if ( V_2 == NULL ) {
F_9 ( V_16 , L_7 ) ;
return - V_51 ;
}
V_2 -> V_7 . V_6 . V_12 = V_52 | F_26 ( 1 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_36 = V_53 ;
V_2 -> V_28 = V_27 ;
F_27 ( V_6 , V_2 ) ;
F_20 ( V_2 , V_6 ) ;
V_25 = F_28 ( & V_6 -> V_16 , L_8 , V_16 , V_2 ,
& V_54 ) ;
if ( F_29 ( V_25 ) ) {
F_9 ( V_16 , L_9 ) ;
return F_30 ( V_25 ) ;
}
V_2 -> V_25 = V_25 ;
F_31 ( V_16 , L_10 , V_30 -> V_55 ) ;
V_23 = F_13 ( V_2 , V_56 ) ;
if ( V_23 != 0 ) {
F_9 ( V_16 , L_11 ) ;
return V_23 ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_53 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_25 )
{
int V_23 ;
V_23 = F_13 ( V_25 , V_53 ) ;
if ( V_25 -> V_28 -> V_57 == V_58 ) {
F_3 ( V_25 , V_59 , V_25 -> V_60 |
V_61 |
V_62 ) ;
V_25 -> V_32 = 0 ;
}
return V_23 ;
}
int F_34 ( struct V_1 * V_25 )
{
F_31 ( V_25 -> V_16 , L_12 , V_25 -> V_36 ) ;
if ( V_25 -> V_28 -> V_57 == V_58 )
F_3 ( V_25 , V_59 , 0x00 ) ;
return F_13 ( V_25 , V_56 ) ;
}
void F_35 ( struct V_1 * V_25 )
{
F_13 ( V_25 , V_53 ) ;
}
