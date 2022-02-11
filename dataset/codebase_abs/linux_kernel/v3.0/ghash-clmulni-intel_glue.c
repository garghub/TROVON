static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 ,
const T_1 * V_7 , unsigned int V_8 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
if ( V_8 != V_11 ) {
F_5 ( V_6 , V_12 ) ;
return - V_13 ;
}
F_6 ( & V_10 -> V_14 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const T_1 * V_15 , unsigned int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_17 = V_4 -> V_18 ;
F_8 () ;
if ( V_4 -> V_19 ) {
int V_20 = F_9 ( V_16 , V_4 -> V_19 ) ;
T_1 * V_21 = V_17 + ( V_11 - V_4 -> V_19 ) ;
V_4 -> V_19 -= V_20 ;
V_16 -= V_20 ;
while ( V_20 -- )
* V_21 ++ ^= * V_15 ++ ;
if ( ! V_4 -> V_19 )
F_10 ( V_17 , & V_10 -> V_14 ) ;
}
F_11 ( V_17 , V_15 , V_16 , & V_10 -> V_14 ) ;
F_12 () ;
if ( V_16 & 0xf ) {
V_15 += V_16 - ( V_16 & 0xf ) ;
V_16 &= 0xf ;
V_4 -> V_19 = V_11 - V_16 ;
while ( V_16 -- )
* V_17 ++ ^= * V_15 ++ ;
}
return 0 ;
}
static void F_13 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
T_1 * V_17 = V_4 -> V_18 ;
if ( V_4 -> V_19 ) {
T_1 * V_22 = V_17 + ( V_11 - V_4 -> V_19 ) ;
while ( V_4 -> V_19 -- )
* V_22 ++ ^= 0 ;
F_8 () ;
F_10 ( V_17 , & V_10 -> V_14 ) ;
F_12 () ;
}
V_4 -> V_19 = 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_23 = V_4 -> V_18 ;
F_13 ( V_10 , V_4 ) ;
memcpy ( V_17 , V_23 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_26 * V_6 = F_16 ( V_25 ) ;
struct V_27 * V_10 = F_17 ( V_6 ) ;
struct V_24 * V_28 = F_18 ( V_25 ) ;
struct V_29 * V_30 = V_10 -> V_30 ;
if ( ! F_19 () ) {
memcpy ( V_28 , V_25 , sizeof( * V_25 ) ) ;
F_20 ( V_28 , & V_30 -> V_31 ) ;
return F_21 ( V_28 ) ;
} else {
struct V_1 * V_2 = F_22 ( V_28 ) ;
struct V_5 * V_32 = F_23 ( V_30 ) ;
V_2 -> V_6 = V_32 ;
V_2 -> V_33 = V_25 -> V_31 . V_33 ;
return F_24 ( V_2 ) ;
}
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_24 * V_28 = F_18 ( V_25 ) ;
if ( ! F_19 () ) {
struct V_26 * V_6 = F_16 ( V_25 ) ;
struct V_27 * V_10 = F_17 ( V_6 ) ;
struct V_29 * V_30 = V_10 -> V_30 ;
memcpy ( V_28 , V_25 , sizeof( * V_25 ) ) ;
F_20 ( V_28 , & V_30 -> V_31 ) ;
return F_26 ( V_28 ) ;
} else {
struct V_1 * V_2 = F_22 ( V_28 ) ;
return F_27 ( V_25 , V_2 ) ;
}
}
static int F_28 ( struct V_24 * V_25 )
{
struct V_24 * V_28 = F_18 ( V_25 ) ;
if ( ! F_19 () ) {
struct V_26 * V_6 = F_16 ( V_25 ) ;
struct V_27 * V_10 = F_17 ( V_6 ) ;
struct V_29 * V_30 = V_10 -> V_30 ;
memcpy ( V_28 , V_25 , sizeof( * V_25 ) ) ;
F_20 ( V_28 , & V_30 -> V_31 ) ;
return F_29 ( V_28 ) ;
} else {
struct V_1 * V_2 = F_22 ( V_28 ) ;
return F_30 ( V_2 , V_25 -> V_34 ) ;
}
}
static int F_31 ( struct V_24 * V_25 )
{
struct V_26 * V_6 = F_16 ( V_25 ) ;
struct V_27 * V_10 = F_17 ( V_6 ) ;
struct V_24 * V_28 = F_18 ( V_25 ) ;
struct V_29 * V_30 = V_10 -> V_30 ;
if ( ! F_19 () ) {
memcpy ( V_28 , V_25 , sizeof( * V_25 ) ) ;
F_20 ( V_28 , & V_30 -> V_31 ) ;
return F_32 ( V_28 ) ;
} else {
struct V_1 * V_2 = F_22 ( V_28 ) ;
struct V_5 * V_32 = F_23 ( V_30 ) ;
V_2 -> V_6 = V_32 ;
V_2 -> V_33 = V_25 -> V_31 . V_33 ;
return F_33 ( V_25 , V_2 ) ;
}
}
static int F_34 ( struct V_26 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
struct V_27 * V_10 = F_17 ( V_6 ) ;
struct V_26 * V_32 = & V_10 -> V_30 -> V_31 ;
int V_35 ;
F_35 ( V_32 , V_36 ) ;
F_36 ( V_32 , F_37 ( V_6 )
& V_36 ) ;
V_35 = F_38 ( V_32 , V_7 , V_8 ) ;
F_36 ( V_6 , F_37 ( V_32 )
& V_37 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_6 )
{
struct V_29 * V_30 ;
struct V_27 * V_10 = F_40 ( V_6 ) ;
V_30 = F_41 ( L_1 , 0 , 0 ) ;
if ( F_42 ( V_30 ) )
return F_43 ( V_30 ) ;
V_10 -> V_30 = V_30 ;
F_44 ( F_45 ( V_6 ) ,
sizeof( struct V_24 ) +
F_46 ( & V_30 -> V_31 ) ) ;
return 0 ;
}
static void F_47 ( struct V_38 * V_6 )
{
struct V_27 * V_10 = F_40 ( V_6 ) ;
F_48 ( V_10 -> V_30 ) ;
}
static int T_2 F_49 ( void )
{
int V_35 ;
if ( ! V_39 ) {
F_50 ( V_40 L_2
L_3 ) ;
return - V_41 ;
}
V_35 = F_51 ( & V_42 ) ;
if ( V_35 )
goto V_43;
V_35 = F_52 ( & V_44 ) ;
if ( V_35 )
goto V_45;
return 0 ;
V_45:
F_53 ( & V_42 ) ;
V_43:
return V_35 ;
}
static void T_3 F_54 ( void )
{
F_55 ( & V_44 ) ;
F_53 ( & V_42 ) ;
}
