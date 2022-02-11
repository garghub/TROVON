static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
if ( V_6 -> V_9 -> V_10 ) {
struct V_11 V_12 ;
char V_13 [ 2 ] ;
V_12 . V_14 = V_2 -> V_14 ;
V_12 . V_15 = 0 ;
V_12 . V_16 = 2 ;
V_13 [ 0 ] = V_3 ;
V_13 [ 1 ] = V_4 ;
V_12 . V_13 = V_13 ;
V_8 = V_6 -> V_9 -> V_10 ( V_6 , & V_12 , 1 ) ;
} else {
union V_17 V_18 ;
V_18 . V_19 = V_4 ;
V_8 = V_6 -> V_9 -> V_20 ( V_6 , V_2 -> V_14 ,
V_2 -> V_15 ,
V_21 ,
V_3 ,
V_22 , & V_18 ) ;
}
return V_8 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
T_1 V_4 ;
if ( V_6 -> V_9 -> V_10 ) {
struct V_11 V_12 [ 2 ] = {
{
. V_14 = V_2 -> V_14 ,
. V_15 = 0 ,
. V_16 = 1 ,
. V_13 = & V_3
} ,
{
. V_14 = V_2 -> V_14 ,
. V_15 = V_23 ,
. V_16 = 1 ,
. V_13 = & V_4
}
} ;
V_8 = V_6 -> V_9 -> V_10 ( V_6 , V_12 , 2 ) ;
if ( V_8 == 2 )
V_8 = V_4 ;
else if ( V_8 >= 0 )
V_8 = - V_24 ;
} else {
union V_17 V_18 ;
V_8 = V_6 -> V_9 -> V_20 ( V_6 , V_2 -> V_14 ,
V_2 -> V_15 ,
V_25 ,
V_3 ,
V_22 , & V_18 ) ;
if ( ! V_8 )
V_8 = V_18 . V_19 ;
}
return V_8 ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_2 ( V_2 , V_27 ) ;
if ( V_26 >= 0 && ! F_4 ( V_26 ) && F_5 ( V_26 ) )
F_1 ( V_2 , V_27 ,
( V_26 & V_28 ) >> 1 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_29 * V_18 = F_7 ( V_2 ) ;
int V_26 ;
V_26 = F_2 ( V_2 , V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( F_4 ( V_26 ) ) {
int V_30 ;
V_30 = F_2 ( V_2 , V_31 ) ;
if ( ! ( V_30 & V_32 )
|| F_8 ( V_18 -> V_33 ) ) {
F_1 ( V_2 ,
V_27 ,
V_34 [ V_26 & 0x0f ]
| V_35 ) ;
V_18 -> V_36 = V_37 ;
} else {
V_18 -> V_36 = V_38 * 2 ;
}
} else if ( F_5 ( V_26 ) ) {
if ( V_26 & ( V_35 | V_39 ) )
F_1 ( V_2 ,
V_27 ,
V_26 & ~ ( V_35
| V_39 ) ) ;
return 1 ;
} else {
V_18 -> V_36 = V_38 ;
if ( F_8 ( V_18 -> V_33 ) ) {
F_1 ( V_2 ,
V_27 ,
V_34 [ V_26 & 0x0f ]
| V_39
| V_35 ) ;
} else {
if ( ! ( V_26 & V_35 ) )
F_1 ( V_2 ,
V_27 ,
V_26 | V_35 ) ;
}
}
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , void * V_2 , T_2 V_40 )
{
struct V_29 * V_18 = F_7 ( V_2 ) ;
int V_8 ;
unsigned long V_41 = V_42 + V_43 ;
V_18 -> V_33 = V_42 + V_44 ;
do {
V_8 = F_6 ( V_2 ) ;
if ( V_8 )
return V_8 < 0 ? V_8 : 0 ;
if ( V_18 -> V_36 == V_37 )
F_10 ( V_18 -> V_36 ) ;
else
F_11 ( V_18 -> V_36 / 1000 ) ;
} while ( F_12 ( V_41 ) );
return - V_45 ;
}
static int F_13 ( struct V_5 * V_6 ,
void * V_2 , T_2 V_40 )
{
F_3 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_48 * V_49 = V_2 -> V_50 . V_51 ;
struct V_29 * V_18 ;
int V_52 ;
int V_8 = - V_53 ;
if ( ! F_15 ( V_6 , V_54 ) )
goto V_55;
V_18 = F_16 ( sizeof( struct V_29 ) , V_56 ) ;
if ( ! V_18 ) {
V_8 = - V_57 ;
goto V_55;
}
F_17 ( V_2 , V_18 ) ;
F_18 ( V_6 ) ;
F_3 ( V_2 ) ;
F_19 ( V_6 ) ;
V_52 = 0 ;
if ( V_49 )
V_52 = V_49 -> V_58 [ 0 ] . V_59 ;
V_18 -> V_60 = F_20 ( V_6 , V_2 , V_52 , 0 ,
F_9 ,
F_13 ) ;
if ( V_18 -> V_60 == NULL ) {
F_21 ( & V_2 -> V_50 , L_1 ) ;
goto V_61;
}
F_22 ( & V_2 -> V_50 , L_2 ,
V_2 -> V_62 ) ;
return 0 ;
V_61:
F_23 ( V_18 ) ;
V_55:
return V_8 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_29 * V_18 = F_7 ( V_2 ) ;
F_25 ( V_18 -> V_60 ) ;
F_23 ( V_18 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_63 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_63 ) ;
}
