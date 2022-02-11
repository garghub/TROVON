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
T_2 * V_11 = ( T_2 * ) V_7 ;
T_3 V_12 , V_13 ;
if ( V_8 != V_14 ) {
F_5 ( V_6 , V_15 ) ;
return - V_16 ;
}
V_12 = F_6 ( V_11 -> V_12 ) ;
V_13 = F_6 ( V_11 -> V_13 ) ;
V_10 -> V_17 . V_12 = ( V_18 ) ( ( V_13 << 1 ) | ( V_12 >> 63 ) ) ;
V_10 -> V_17 . V_13 = ( V_18 ) ( ( V_12 << 1 ) | ( V_13 >> 63 ) ) ;
if ( V_12 >> 63 )
V_10 -> V_17 . V_13 ^= F_7 ( 0xc2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const T_1 * V_19 , unsigned int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_21 = V_4 -> V_22 ;
F_9 () ;
if ( V_4 -> V_23 ) {
int V_24 = F_10 ( V_20 , V_4 -> V_23 ) ;
T_1 * V_25 = V_21 + ( V_14 - V_4 -> V_23 ) ;
V_4 -> V_23 -= V_24 ;
V_20 -= V_24 ;
while ( V_24 -- )
* V_25 ++ ^= * V_19 ++ ;
if ( ! V_4 -> V_23 )
F_11 ( V_21 , & V_10 -> V_17 ) ;
}
F_12 ( V_21 , V_19 , V_20 , & V_10 -> V_17 ) ;
F_13 () ;
if ( V_20 & 0xf ) {
V_19 += V_20 - ( V_20 & 0xf ) ;
V_20 &= 0xf ;
V_4 -> V_23 = V_14 - V_20 ;
while ( V_20 -- )
* V_21 ++ ^= * V_19 ++ ;
}
return 0 ;
}
static void F_14 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
T_1 * V_21 = V_4 -> V_22 ;
if ( V_4 -> V_23 ) {
T_1 * V_26 = V_21 + ( V_14 - V_4 -> V_23 ) ;
while ( V_4 -> V_23 -- )
* V_26 ++ ^= 0 ;
F_9 () ;
F_11 ( V_21 , & V_10 -> V_17 ) ;
F_13 () ;
}
V_4 -> V_23 = 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_27 = V_4 -> V_22 ;
F_14 ( V_10 , V_4 ) ;
memcpy ( V_21 , V_27 , V_14 ) ;
return 0 ;
}
static int F_16 ( struct V_28 * V_29 )
{
struct V_30 * V_6 = F_17 ( V_29 ) ;
struct V_31 * V_10 = F_18 ( V_6 ) ;
struct V_28 * V_32 = F_19 ( V_29 ) ;
struct V_33 * V_34 = V_10 -> V_34 ;
if ( ! F_20 () ) {
memcpy ( V_32 , V_29 , sizeof( * V_29 ) ) ;
F_21 ( V_32 , & V_34 -> V_35 ) ;
return F_22 ( V_32 ) ;
} else {
struct V_1 * V_2 = F_23 ( V_32 ) ;
struct V_5 * V_36 = F_24 ( V_34 ) ;
V_2 -> V_6 = V_36 ;
V_2 -> V_37 = V_29 -> V_35 . V_37 ;
return F_25 ( V_2 ) ;
}
}
static int F_26 ( struct V_28 * V_29 )
{
struct V_28 * V_32 = F_19 ( V_29 ) ;
if ( ! F_20 () ) {
struct V_30 * V_6 = F_17 ( V_29 ) ;
struct V_31 * V_10 = F_18 ( V_6 ) ;
struct V_33 * V_34 = V_10 -> V_34 ;
memcpy ( V_32 , V_29 , sizeof( * V_29 ) ) ;
F_21 ( V_32 , & V_34 -> V_35 ) ;
return F_27 ( V_32 ) ;
} else {
struct V_1 * V_2 = F_23 ( V_32 ) ;
return F_28 ( V_29 , V_2 ) ;
}
}
static int F_29 ( struct V_28 * V_29 )
{
struct V_28 * V_32 = F_19 ( V_29 ) ;
if ( ! F_20 () ) {
struct V_30 * V_6 = F_17 ( V_29 ) ;
struct V_31 * V_10 = F_18 ( V_6 ) ;
struct V_33 * V_34 = V_10 -> V_34 ;
memcpy ( V_32 , V_29 , sizeof( * V_29 ) ) ;
F_21 ( V_32 , & V_34 -> V_35 ) ;
return F_30 ( V_32 ) ;
} else {
struct V_1 * V_2 = F_23 ( V_32 ) ;
return F_31 ( V_2 , V_29 -> V_38 ) ;
}
}
static int F_32 ( struct V_28 * V_29 )
{
struct V_30 * V_6 = F_17 ( V_29 ) ;
struct V_31 * V_10 = F_18 ( V_6 ) ;
struct V_28 * V_32 = F_19 ( V_29 ) ;
struct V_33 * V_34 = V_10 -> V_34 ;
if ( ! F_20 () ) {
memcpy ( V_32 , V_29 , sizeof( * V_29 ) ) ;
F_21 ( V_32 , & V_34 -> V_35 ) ;
return F_33 ( V_32 ) ;
} else {
struct V_1 * V_2 = F_23 ( V_32 ) ;
struct V_5 * V_36 = F_24 ( V_34 ) ;
V_2 -> V_6 = V_36 ;
V_2 -> V_37 = V_29 -> V_35 . V_37 ;
return F_34 ( V_29 , V_2 ) ;
}
}
static int F_35 ( struct V_30 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
struct V_31 * V_10 = F_18 ( V_6 ) ;
struct V_30 * V_36 = & V_10 -> V_34 -> V_35 ;
int V_39 ;
F_36 ( V_36 , V_40 ) ;
F_37 ( V_36 , F_38 ( V_6 )
& V_40 ) ;
V_39 = F_39 ( V_36 , V_7 , V_8 ) ;
F_37 ( V_6 , F_38 ( V_36 )
& V_41 ) ;
return V_39 ;
}
static int F_40 ( struct V_42 * V_6 )
{
struct V_33 * V_34 ;
struct V_31 * V_10 = F_41 ( V_6 ) ;
V_34 = F_42 ( L_1 , 0 , 0 ) ;
if ( F_43 ( V_34 ) )
return F_44 ( V_34 ) ;
V_10 -> V_34 = V_34 ;
F_45 ( F_46 ( V_6 ) ,
sizeof( struct V_28 ) +
F_47 ( & V_34 -> V_35 ) ) ;
return 0 ;
}
static void F_48 ( struct V_42 * V_6 )
{
struct V_31 * V_10 = F_41 ( V_6 ) ;
F_49 ( V_10 -> V_34 ) ;
}
static int T_4 F_50 ( void )
{
int V_39 ;
if ( ! F_51 ( V_43 ) )
return - V_44 ;
V_39 = F_52 ( & V_45 ) ;
if ( V_39 )
goto V_46;
V_39 = F_53 ( & V_47 ) ;
if ( V_39 )
goto V_48;
return 0 ;
V_48:
F_54 ( & V_45 ) ;
V_46:
return V_39 ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_47 ) ;
F_54 ( & V_45 ) ;
}
