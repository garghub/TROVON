static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = F_5 ( V_3 -> V_8 ) ;
unsigned long V_9 = V_10 ;
struct V_1 * V_1 = F_1 ( V_5 ) ;
V_1 -> V_11 = F_6 ( V_3 -> V_12 ) ;
if ( ! V_1 -> V_11 )
return - V_13 ;
V_3 -> V_14 [ 0 ] = F_7 ( V_3 -> V_12 , V_9 ) ;
if ( ! V_3 -> V_14 [ 0 ] ) {
F_8 ( V_1 -> V_11 ) ;
return - V_13 ;
}
return F_9 ( V_7 , V_5 ) ;
}
static int F_10 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = F_5 ( V_3 -> V_8 ) ;
struct V_1 * V_1 = F_1 ( V_5 ) ;
int V_15 ;
V_15 = F_11 ( V_7 , V_5 ) ;
if ( V_15 < 0 )
return V_15 ;
F_12 ( V_3 -> V_14 [ 0 ] ) ;
F_8 ( V_1 -> V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_17 -> V_11 = F_14 ( V_1 -> V_11 ) ;
if ( ! V_17 -> V_11 )
return - V_13 ;
return 0 ;
}
static void F_15 ( struct V_16 * V_17 )
{
F_16 ( V_17 -> V_11 ) ;
}
static int F_17 ( struct V_18 * V_12 , T_1 V_19 , T_1 V_20 )
{
struct V_1 * V_1 = F_5 ( V_12 ) ;
switch ( V_19 ) {
case V_21 :
if ( V_20 == 0x2b )
return 1 ;
break;
case V_22 :
if ( V_20 >= V_23 )
break;
if ( F_18 ( V_20 , V_1 -> V_24 ) )
return 1 ;
break;
}
return 0 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_12 . V_29 ;
struct V_30 * * V_14 ;
struct V_1 * V_1 ;
unsigned int V_31 ;
int V_15 ;
V_1 = F_20 ( & V_26 -> V_12 , sizeof( * V_1 ) , V_32 ) ;
if ( ! V_1 )
return - V_13 ;
V_14 = F_20 ( & V_26 -> V_12 , sizeof( * V_14 ) , V_32 ) ;
if ( ! V_14 )
return - V_13 ;
V_1 -> V_33 = F_21 ( & V_26 -> V_12 , NULL ) ;
if ( F_22 ( V_1 -> V_33 ) ) {
F_23 ( & V_26 -> V_12 , L_1 ) ;
return F_24 ( V_1 -> V_33 ) ;
}
if ( F_25 ( V_28 , L_2 ) ) {
V_1 -> V_34 = F_21 ( & V_26 -> V_12 , L_3 ) ;
if ( F_22 ( V_1 -> V_33 ) ) {
F_23 ( & V_26 -> V_12 , L_4 ) ;
return F_24 ( V_1 -> V_33 ) ;
}
}
V_15 = F_26 ( V_35 , V_1 -> V_33 ) ;
if ( V_15 < 0 ) {
F_23 ( & V_26 -> V_12 , L_5 ) ;
return V_15 ;
}
if ( V_1 -> V_34 ) {
V_15 = F_26 ( V_36 ,
V_1 -> V_34 ) ;
if ( V_15 < 0 ) {
F_23 ( & V_26 -> V_12 ,
L_6 ) ;
return V_15 ;
}
}
F_27 ( & V_1 -> V_3 . V_37 . V_38 ) ;
V_1 -> V_3 . V_37 . V_39 = & V_40 ;
V_1 -> V_3 . V_37 . V_12 = & V_26 -> V_12 ;
V_1 -> V_3 . V_37 . V_19 = V_22 ;
V_1 -> V_3 . V_37 . V_14 = V_14 ;
V_1 -> V_3 . V_37 . V_41 = 1 ;
F_27 ( & V_1 -> V_3 . V_38 ) ;
V_1 -> V_3 . V_39 = & V_42 ;
V_15 = F_28 ( & V_1 -> V_3 . V_37 ) ;
if ( V_15 < 0 ) {
F_23 ( & V_26 -> V_12 , L_7 ,
V_15 ) ;
return V_15 ;
}
for ( V_31 = 0 ; V_31 < F_29 ( V_43 ) ; V_31 ++ )
F_30 ( V_43 [ V_31 ] , V_1 -> V_24 ) ;
F_31 ( V_26 , V_1 ) ;
return 0 ;
}
static int F_32 ( struct V_25 * V_26 )
{
struct V_1 * V_1 = F_33 ( V_26 ) ;
int V_15 ;
V_15 = F_34 ( & V_1 -> V_3 . V_37 ) ;
if ( V_15 < 0 ) {
F_23 ( & V_26 -> V_12 , L_8 ,
V_15 ) ;
return V_15 ;
}
if ( V_1 -> V_34 ) {
F_35 ( V_36 ) ;
F_36 ( V_1 -> V_34 ) ;
}
F_35 ( V_35 ) ;
F_36 ( V_1 -> V_33 ) ;
return 0 ;
}
