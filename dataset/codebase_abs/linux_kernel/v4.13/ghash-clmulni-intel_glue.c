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
V_10 -> V_17 . V_12 = ( V_13 << 1 ) | ( V_12 >> 63 ) ;
V_10 -> V_17 . V_13 = ( V_12 << 1 ) | ( V_13 >> 63 ) ;
if ( V_12 >> 63 )
V_10 -> V_17 . V_13 ^= ( ( T_3 ) 0xc2 ) << 56 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const T_1 * V_18 , unsigned int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_20 = V_4 -> V_21 ;
F_8 () ;
if ( V_4 -> V_22 ) {
int V_23 = F_9 ( V_19 , V_4 -> V_22 ) ;
T_1 * V_24 = V_20 + ( V_14 - V_4 -> V_22 ) ;
V_4 -> V_22 -= V_23 ;
V_19 -= V_23 ;
while ( V_23 -- )
* V_24 ++ ^= * V_18 ++ ;
if ( ! V_4 -> V_22 )
F_10 ( V_20 , & V_10 -> V_17 ) ;
}
F_11 ( V_20 , V_18 , V_19 , & V_10 -> V_17 ) ;
F_12 () ;
if ( V_19 & 0xf ) {
V_18 += V_19 - ( V_19 & 0xf ) ;
V_19 &= 0xf ;
V_4 -> V_22 = V_14 - V_19 ;
while ( V_19 -- )
* V_20 ++ ^= * V_18 ++ ;
}
return 0 ;
}
static void F_13 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
T_1 * V_20 = V_4 -> V_21 ;
if ( V_4 -> V_22 ) {
T_1 * V_25 = V_20 + ( V_14 - V_4 -> V_22 ) ;
while ( V_4 -> V_22 -- )
* V_25 ++ ^= 0 ;
F_8 () ;
F_10 ( V_20 , & V_10 -> V_17 ) ;
F_12 () ;
}
V_4 -> V_22 = 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_26 = V_4 -> V_21 ;
F_13 ( V_10 , V_4 ) ;
memcpy ( V_20 , V_26 , V_14 ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_29 * V_6 = F_16 ( V_28 ) ;
struct V_30 * V_10 = F_17 ( V_6 ) ;
struct V_27 * V_31 = F_18 ( V_28 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
struct V_1 * V_2 = F_19 ( V_31 ) ;
struct V_5 * V_34 = F_20 ( V_33 ) ;
V_2 -> V_6 = V_34 ;
V_2 -> V_35 = V_28 -> V_36 . V_35 ;
return F_21 ( V_2 ) ;
}
static int F_22 ( struct V_27 * V_28 )
{
struct V_27 * V_31 = F_18 ( V_28 ) ;
struct V_29 * V_6 = F_16 ( V_28 ) ;
struct V_30 * V_10 = F_17 ( V_6 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
if ( ! F_23 () ||
( F_24 () && F_25 ( V_33 ) ) ) {
memcpy ( V_31 , V_28 , sizeof( * V_28 ) ) ;
F_26 ( V_31 , & V_33 -> V_36 ) ;
return F_27 ( V_31 ) ;
} else {
struct V_1 * V_2 = F_19 ( V_31 ) ;
return F_28 ( V_28 , V_2 ) ;
}
}
static int F_29 ( struct V_27 * V_28 )
{
struct V_27 * V_31 = F_18 ( V_28 ) ;
struct V_29 * V_6 = F_16 ( V_28 ) ;
struct V_30 * V_10 = F_17 ( V_6 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
if ( ! F_23 () ||
( F_24 () && F_25 ( V_33 ) ) ) {
memcpy ( V_31 , V_28 , sizeof( * V_28 ) ) ;
F_26 ( V_31 , & V_33 -> V_36 ) ;
return F_30 ( V_31 ) ;
} else {
struct V_1 * V_2 = F_19 ( V_31 ) ;
return F_31 ( V_2 , V_28 -> V_37 ) ;
}
}
static int F_32 ( struct V_27 * V_28 , const void * V_38 )
{
struct V_27 * V_31 = F_18 ( V_28 ) ;
struct V_1 * V_2 = F_19 ( V_31 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_28 ) ;
memcpy ( V_4 , V_38 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_33 ( struct V_27 * V_28 , void * V_39 )
{
struct V_27 * V_31 = F_18 ( V_28 ) ;
struct V_1 * V_2 = F_19 ( V_31 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_39 , V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_29 * V_6 = F_16 ( V_28 ) ;
struct V_30 * V_10 = F_17 ( V_6 ) ;
struct V_27 * V_31 = F_18 ( V_28 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
if ( ! F_23 () ||
( F_24 () && F_25 ( V_33 ) ) ) {
memcpy ( V_31 , V_28 , sizeof( * V_28 ) ) ;
F_26 ( V_31 , & V_33 -> V_36 ) ;
return F_35 ( V_31 ) ;
} else {
struct V_1 * V_2 = F_19 ( V_31 ) ;
struct V_5 * V_34 = F_20 ( V_33 ) ;
V_2 -> V_6 = V_34 ;
V_2 -> V_35 = V_28 -> V_36 . V_35 ;
return F_36 ( V_28 , V_2 ) ;
}
}
static int F_37 ( struct V_29 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
struct V_30 * V_10 = F_17 ( V_6 ) ;
struct V_29 * V_34 = & V_10 -> V_33 -> V_36 ;
int V_40 ;
F_38 ( V_34 , V_41 ) ;
F_39 ( V_34 , F_40 ( V_6 )
& V_41 ) ;
V_40 = F_41 ( V_34 , V_7 , V_8 ) ;
F_39 ( V_6 , F_40 ( V_34 )
& V_42 ) ;
return V_40 ;
}
static int F_42 ( struct V_43 * V_6 )
{
struct V_32 * V_33 ;
struct V_30 * V_10 = F_43 ( V_6 ) ;
V_33 = F_44 ( L_1 ,
V_44 ,
V_44 ) ;
if ( F_45 ( V_33 ) )
return F_46 ( V_33 ) ;
V_10 -> V_33 = V_33 ;
F_47 ( F_48 ( V_6 ) ,
sizeof( struct V_27 ) +
F_49 ( & V_33 -> V_36 ) ) ;
return 0 ;
}
static void F_50 ( struct V_43 * V_6 )
{
struct V_30 * V_10 = F_43 ( V_6 ) ;
F_51 ( V_10 -> V_33 ) ;
}
static int T_4 F_52 ( void )
{
int V_40 ;
if ( ! F_53 ( V_45 ) )
return - V_46 ;
V_40 = F_54 ( & V_47 ) ;
if ( V_40 )
goto V_48;
V_40 = F_55 ( & V_49 ) ;
if ( V_40 )
goto V_50;
return 0 ;
V_50:
F_56 ( & V_47 ) ;
V_48:
return V_40 ;
}
static void T_5 F_57 ( void )
{
F_58 ( & V_49 ) ;
F_56 ( & V_47 ) ;
}
