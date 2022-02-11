static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_7 [ V_8 ] ;
if ( ! F_3 ( V_7 , V_3 ) &&
( V_2 -> V_9 & V_10 ) ) {
V_2 -> V_9 |= V_11 ;
return - V_12 ;
}
memcpy ( V_6 -> V_3 , V_3 , V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_13 , const T_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_15 , V_6 -> V_3 , V_13 , V_14 , V_16 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_13 , const T_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_15 | V_17 ,
V_6 -> V_3 , V_13 , V_14 , V_16 ) ;
}
static int F_7 ( struct V_18 * V_19 , unsigned long V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_19 -> V_2 ) ;
unsigned int V_23 , V_24 ;
int V_25 ;
V_25 = F_9 ( V_19 , V_22 ) ;
while ( ( V_23 = V_22 -> V_23 ) >= V_16 ) {
V_24 = V_23 & ~ ( V_16 - 1 ) ;
F_5 ( V_20 , V_6 -> V_3 , V_22 -> V_26 . V_27 . V_28 ,
V_22 -> V_29 . V_27 . V_28 , V_24 ) ;
V_25 = F_10 ( V_19 , V_22 , V_23 - V_24 ) ;
}
return V_25 ;
}
static int F_11 ( struct V_18 * V_19 , unsigned long V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_19 -> V_2 ) ;
unsigned int V_23 , V_24 ;
int V_25 ;
struct {
T_1 V_30 [ V_16 ] ;
T_1 V_3 [ V_31 ] ;
} V_32 ;
V_25 = F_9 ( V_19 , V_22 ) ;
memcpy ( V_32 . V_30 , V_22 -> V_30 , V_16 ) ;
memcpy ( V_32 . V_3 , V_6 -> V_3 , V_31 ) ;
while ( ( V_23 = V_22 -> V_23 ) >= V_16 ) {
V_24 = V_23 & ~ ( V_16 - 1 ) ;
F_12 ( V_20 , & V_32 , V_22 -> V_26 . V_27 . V_28 ,
V_22 -> V_29 . V_27 . V_28 , V_24 ) ;
V_25 = F_10 ( V_19 , V_22 , V_23 - V_24 ) ;
}
memcpy ( V_22 -> V_30 , V_32 . V_30 , V_16 ) ;
return V_25 ;
}
static int F_13 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_7 ( V_19 , V_15 , & V_22 ) ;
}
static int F_15 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_7 ( V_19 , V_15 | V_17 , & V_22 ) ;
}
static int F_16 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_11 ( V_19 , V_34 , & V_22 ) ;
}
static int F_17 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_11 ( V_19 , V_34 | V_17 , & V_22 ) ;
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( F_19 ( V_3 , & V_3 [ V_35 ] , V_35 ) &&
F_19 ( & V_3 [ V_35 ] , & V_3 [ V_35 * 2 ] ,
V_35 ) ) &&
( V_2 -> V_9 & V_10 ) ) {
V_2 -> V_9 |= V_11 ;
return - V_12 ;
}
memcpy ( V_6 -> V_3 , V_3 , V_4 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_1 * V_26 , const T_1 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_36 , V_6 -> V_3 , V_26 , V_29 , V_16 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 * V_26 , const T_1 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_36 | V_17 ,
V_6 -> V_3 , V_26 , V_29 , V_16 ) ;
}
static int F_22 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_7 ( V_19 , V_36 , & V_22 ) ;
}
static int F_23 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_7 ( V_19 , V_36 | V_17 ,
& V_22 ) ;
}
static int F_24 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_11 ( V_19 , V_37 , & V_22 ) ;
}
static int F_25 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_11 ( V_19 , V_37 | V_17 ,
& V_22 ) ;
}
static unsigned int F_26 ( T_1 * V_38 , T_1 * V_30 , unsigned int V_23 )
{
unsigned int V_39 , V_24 ;
V_24 = ( V_23 > V_40 ) ? V_40 : V_23 & ~ ( V_16 - 1 ) ;
memcpy ( V_38 , V_30 , V_16 ) ;
for ( V_39 = ( V_24 / V_16 ) - 1 ; V_39 > 0 ; V_39 -- ) {
memcpy ( V_38 + V_16 , V_38 , V_16 ) ;
F_27 ( V_38 + V_16 , V_16 ) ;
V_38 += V_16 ;
}
return V_24 ;
}
static int F_28 ( struct V_18 * V_19 , unsigned long V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_19 -> V_2 ) ;
T_1 V_41 [ V_16 ] , * V_38 ;
unsigned int V_24 , V_23 ;
int V_25 , V_42 ;
V_42 = F_29 ( & V_43 ) ;
V_25 = F_30 ( V_19 , V_22 , V_16 ) ;
while ( ( V_23 = V_22 -> V_23 ) >= V_16 ) {
V_24 = V_16 ;
if ( V_23 >= 2 * V_16 && V_42 )
V_24 = F_26 ( V_44 , V_22 -> V_30 , V_23 ) ;
V_38 = ( V_24 > V_16 ) ? V_44 : V_22 -> V_30 ;
F_31 ( V_20 , V_6 -> V_3 , V_22 -> V_26 . V_27 . V_28 ,
V_22 -> V_29 . V_27 . V_28 , V_24 , V_38 ) ;
if ( V_38 == V_44 )
memcpy ( V_22 -> V_30 , V_38 + V_24 - V_16 ,
V_16 ) ;
F_27 ( V_22 -> V_30 , V_16 ) ;
V_25 = F_10 ( V_19 , V_22 , V_23 - V_24 ) ;
}
if ( V_42 )
F_32 ( & V_43 ) ;
if ( V_23 ) {
F_31 ( V_20 , V_6 -> V_3 , V_41 , V_22 -> V_29 . V_27 . V_28 ,
V_16 , V_22 -> V_30 ) ;
memcpy ( V_22 -> V_26 . V_27 . V_28 , V_41 , V_23 ) ;
F_27 ( V_22 -> V_30 , V_16 ) ;
V_25 = F_10 ( V_19 , V_22 , 0 ) ;
}
return V_25 ;
}
static int F_33 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_28 ( V_19 , V_45 , & V_22 ) ;
}
static int F_34 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_28 ( V_19 , V_45 | V_17 , & V_22 ) ;
}
static int F_35 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_28 ( V_19 , V_46 , & V_22 ) ;
}
static int F_36 ( struct V_18 * V_19 ,
struct V_33 * V_26 , struct V_33 * V_29 ,
unsigned int V_23 )
{
struct V_21 V_22 ;
F_14 ( & V_22 , V_26 , V_29 , V_23 ) ;
return F_28 ( V_19 , V_46 | V_17 ,
& V_22 ) ;
}
static int F_37 ( struct V_47 * V_48 )
{
int V_25 ;
V_25 = F_38 ( V_48 ) ;
if ( ! V_25 )
V_49 [ V_50 ++ ] = V_48 ;
return V_25 ;
}
static void F_39 ( void )
{
while ( V_50 -- )
F_40 ( V_49 [ V_50 ] ) ;
if ( V_44 )
F_41 ( ( unsigned long ) V_44 ) ;
}
static int T_3 F_42 ( void )
{
int V_25 ;
F_43 ( V_51 , & V_52 ) ;
F_43 ( V_53 , & V_54 ) ;
F_43 ( V_55 , & V_56 ) ;
if ( F_44 ( & V_52 , V_15 ) ) {
V_25 = F_37 ( & V_57 ) ;
if ( V_25 )
goto V_58;
V_25 = F_37 ( & V_59 ) ;
if ( V_25 )
goto V_58;
}
if ( F_44 ( & V_54 , V_34 ) ) {
V_25 = F_37 ( & V_60 ) ;
if ( V_25 )
goto V_58;
}
if ( F_44 ( & V_52 , V_36 ) ) {
V_25 = F_37 ( & V_61 ) ;
if ( V_25 )
goto V_58;
V_25 = F_37 ( & V_62 ) ;
if ( V_25 )
goto V_58;
}
if ( F_44 ( & V_54 , V_37 ) ) {
V_25 = F_37 ( & V_63 ) ;
if ( V_25 )
goto V_58;
}
if ( F_44 ( & V_56 , V_45 ) ||
F_44 ( & V_56 , V_46 ) ) {
V_44 = ( T_1 * ) F_45 ( V_64 ) ;
if ( ! V_44 ) {
V_25 = - V_65 ;
goto V_58;
}
}
if ( F_44 ( & V_56 , V_45 ) ) {
V_25 = F_37 ( & V_66 ) ;
if ( V_25 )
goto V_58;
}
if ( F_44 ( & V_56 , V_46 ) ) {
V_25 = F_37 ( & V_67 ) ;
if ( V_25 )
goto V_58;
}
return 0 ;
V_58:
F_39 () ;
return V_25 ;
}
