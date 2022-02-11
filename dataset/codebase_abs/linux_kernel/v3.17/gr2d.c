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
V_1 -> V_11 = F_6 ( V_3 -> V_7 ) ;
if ( ! V_1 -> V_11 )
return - V_12 ;
V_3 -> V_13 [ 0 ] = F_7 ( V_3 -> V_7 , V_9 ) ;
if ( ! V_3 -> V_13 [ 0 ] ) {
F_8 ( V_1 -> V_11 ) ;
return - V_12 ;
}
return F_9 ( V_7 -> V_14 , V_5 ) ;
}
static int F_10 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = F_5 ( V_3 -> V_8 ) ;
struct V_1 * V_1 = F_1 ( V_5 ) ;
int V_15 ;
V_15 = F_11 ( V_7 -> V_14 , V_5 ) ;
if ( V_15 < 0 )
return V_15 ;
F_12 ( V_3 -> V_13 [ 0 ] ) ;
F_8 ( V_1 -> V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_17 -> V_11 = F_14 ( V_1 -> V_11 ) ;
if ( ! V_17 -> V_11 )
return - V_12 ;
return 0 ;
}
static void F_15 ( struct V_16 * V_17 )
{
F_16 ( V_17 -> V_11 ) ;
}
static int F_17 ( struct V_18 * V_7 , T_1 V_19 , T_1 V_20 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
switch ( V_19 ) {
case V_21 :
if ( V_20 == 0x2b )
return 1 ;
break;
case V_22 :
case V_23 :
if ( V_20 >= V_24 )
break;
if ( F_18 ( V_20 , V_1 -> V_25 ) )
return 1 ;
break;
}
return 0 ;
}
static int F_19 ( struct V_26 * V_27 )
{
struct V_18 * V_7 = & V_27 -> V_7 ;
struct V_28 * * V_13 ;
struct V_1 * V_1 ;
unsigned int V_29 ;
int V_15 ;
V_1 = F_20 ( V_7 , sizeof( * V_1 ) , V_30 ) ;
if ( ! V_1 )
return - V_12 ;
V_13 = F_20 ( V_7 , sizeof( * V_13 ) , V_30 ) ;
if ( ! V_13 )
return - V_12 ;
V_1 -> V_31 = F_21 ( V_7 , NULL ) ;
if ( F_22 ( V_1 -> V_31 ) ) {
F_23 ( V_7 , L_1 ) ;
return F_24 ( V_1 -> V_31 ) ;
}
V_15 = F_25 ( V_1 -> V_31 ) ;
if ( V_15 ) {
F_23 ( V_7 , L_2 ) ;
return V_15 ;
}
F_26 ( & V_1 -> V_3 . V_32 . V_33 ) ;
V_1 -> V_3 . V_32 . V_34 = & V_35 ;
V_1 -> V_3 . V_32 . V_7 = V_7 ;
V_1 -> V_3 . V_32 . V_19 = V_22 ;
V_1 -> V_3 . V_32 . V_13 = V_13 ;
V_1 -> V_3 . V_32 . V_36 = 1 ;
F_26 ( & V_1 -> V_3 . V_33 ) ;
V_1 -> V_3 . V_34 = & V_37 ;
V_15 = F_27 ( & V_1 -> V_3 . V_32 ) ;
if ( V_15 < 0 ) {
F_23 ( V_7 , L_3 , V_15 ) ;
F_28 ( V_1 -> V_31 ) ;
return V_15 ;
}
for ( V_29 = 0 ; V_29 < F_29 ( V_38 ) ; V_29 ++ )
F_30 ( V_38 [ V_29 ] , V_1 -> V_25 ) ;
F_31 ( V_27 , V_1 ) ;
return 0 ;
}
static int F_32 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_33 ( V_27 ) ;
int V_15 ;
V_15 = F_34 ( & V_1 -> V_3 . V_32 ) ;
if ( V_15 < 0 ) {
F_23 ( & V_27 -> V_7 , L_4 ,
V_15 ) ;
return V_15 ;
}
F_28 ( V_1 -> V_31 ) ;
return 0 ;
}
