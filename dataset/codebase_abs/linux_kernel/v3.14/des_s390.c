static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_7 = & V_2 -> V_8 ;
T_2 V_9 [ V_10 ] ;
if ( ! F_3 ( V_9 , V_3 ) && ( * V_7 & V_11 ) ) {
* V_7 |= V_12 ;
return - V_13 ;
}
memcpy ( V_6 -> V_3 , V_3 , V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_14 , const T_1 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_16 , V_6 -> V_3 , V_14 , V_15 , V_17 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_14 , const T_1 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_18 , V_6 -> V_3 , V_14 , V_15 , V_17 ) ;
}
static int F_7 ( struct V_19 * V_20 , long V_21 ,
T_1 * V_3 , struct V_22 * V_23 )
{
int V_24 = F_8 ( V_20 , V_23 ) ;
unsigned int V_25 ;
while ( ( V_25 = V_23 -> V_25 ) ) {
unsigned int V_26 = V_25 & ~ ( V_17 - 1 ) ;
T_1 * V_14 = V_23 -> V_27 . V_28 . V_29 ;
T_1 * V_15 = V_23 -> V_30 . V_28 . V_29 ;
V_24 = F_5 ( V_21 , V_3 , V_14 , V_15 , V_26 ) ;
if ( V_24 < 0 || V_24 != V_26 )
return - V_31 ;
V_25 &= V_17 - 1 ;
V_24 = F_9 ( V_20 , V_23 , V_25 ) ;
}
return V_24 ;
}
static int F_10 ( struct V_19 * V_20 , long V_21 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
int V_24 = F_8 ( V_20 , V_23 ) ;
unsigned int V_25 = V_23 -> V_25 ;
struct {
T_1 V_32 [ V_17 ] ;
T_1 V_3 [ V_33 ] ;
} V_34 ;
if ( ! V_25 )
goto V_14;
memcpy ( V_34 . V_32 , V_23 -> V_32 , V_17 ) ;
memcpy ( V_34 . V_3 , V_6 -> V_3 , V_33 ) ;
do {
unsigned int V_26 = V_25 & ~ ( V_17 - 1 ) ;
T_1 * V_14 = V_23 -> V_27 . V_28 . V_29 ;
T_1 * V_15 = V_23 -> V_30 . V_28 . V_29 ;
V_24 = F_12 ( V_21 , & V_34 , V_14 , V_15 , V_26 ) ;
if ( V_24 < 0 || V_24 != V_26 )
return - V_31 ;
V_25 &= V_17 - 1 ;
V_24 = F_9 ( V_20 , V_23 , V_25 ) ;
} while ( ( V_25 = V_23 -> V_25 ) );
memcpy ( V_23 -> V_32 , V_34 . V_32 , V_17 ) ;
V_14:
return V_24 ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_16 , V_6 -> V_3 , & V_23 ) ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_18 , V_6 -> V_3 , & V_23 ) ;
}
static int F_16 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_36 , & V_23 ) ;
}
static int F_17 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_37 , & V_23 ) ;
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_7 = & V_2 -> V_8 ;
if ( ! ( F_19 ( V_3 , & V_3 [ V_38 ] , V_38 ) &&
F_19 ( & V_3 [ V_38 ] , & V_3 [ V_38 * 2 ] ,
V_38 ) ) &&
( * V_7 & V_11 ) ) {
* V_7 |= V_12 ;
return - V_13 ;
}
memcpy ( V_6 -> V_3 , V_3 , V_4 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_1 * V_27 , const T_1 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_39 , V_6 -> V_3 , V_27 , V_30 , V_17 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 * V_27 , const T_1 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_40 , V_6 -> V_3 , V_27 , V_30 , V_17 ) ;
}
static int F_22 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_39 , V_6 -> V_3 , & V_23 ) ;
}
static int F_23 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_40 , V_6 -> V_3 , & V_23 ) ;
}
static int F_24 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_41 , & V_23 ) ;
}
static int F_25 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_42 , & V_23 ) ;
}
static unsigned int F_26 ( T_1 * V_43 , unsigned int V_25 )
{
unsigned int V_44 , V_26 ;
V_26 = ( V_25 > V_45 ) ? V_45 : V_25 & ~ ( V_17 - 1 ) ;
for ( V_44 = V_17 ; V_44 < V_26 ; V_44 += V_17 ) {
memcpy ( V_43 + V_44 , V_43 + V_44 - V_17 , V_17 ) ;
F_27 ( V_43 + V_44 , V_17 ) ;
}
return V_26 ;
}
static int F_28 ( struct V_19 * V_20 , long V_21 ,
struct V_5 * V_6 ,
struct V_22 * V_23 )
{
int V_24 = F_29 ( V_20 , V_23 , V_17 ) ;
unsigned int V_26 , V_25 ;
T_1 V_46 [ V_17 ] , V_47 [ V_17 ] ;
T_1 * V_14 , * V_15 , * V_43 = V_47 ;
if ( ! V_23 -> V_25 )
return V_24 ;
if ( F_30 ( & V_48 ) )
V_43 = V_49 ;
memcpy ( V_43 , V_23 -> V_32 , V_17 ) ;
while ( ( V_25 = V_23 -> V_25 ) >= V_17 ) {
V_14 = V_23 -> V_27 . V_28 . V_29 ;
V_15 = V_23 -> V_30 . V_28 . V_29 ;
while ( V_25 >= V_17 ) {
if ( V_43 == V_49 )
V_26 = F_26 ( V_43 , V_25 ) ;
else
V_26 = V_17 ;
V_24 = F_31 ( V_21 , V_6 -> V_3 , V_14 , V_15 ,
V_26 , V_43 ) ;
if ( V_24 < 0 || V_24 != V_26 ) {
if ( V_43 == V_49 )
F_32 ( & V_48 ) ;
return - V_31 ;
}
if ( V_26 > V_17 )
memcpy ( V_43 , V_43 + V_26 - V_17 ,
V_17 ) ;
F_27 ( V_43 , V_17 ) ;
V_14 += V_26 ;
V_15 += V_26 ;
V_25 -= V_26 ;
}
V_24 = F_9 ( V_20 , V_23 , V_25 ) ;
}
if ( V_43 == V_49 ) {
if ( V_25 )
memcpy ( V_47 , V_43 , V_17 ) ;
else
memcpy ( V_23 -> V_32 , V_43 , V_17 ) ;
F_32 ( & V_48 ) ;
}
if ( V_25 ) {
V_14 = V_23 -> V_27 . V_28 . V_29 ;
V_15 = V_23 -> V_30 . V_28 . V_29 ;
V_24 = F_31 ( V_21 , V_6 -> V_3 , V_46 , V_15 ,
V_17 , V_47 ) ;
if ( V_24 < 0 || V_24 != V_17 )
return - V_31 ;
memcpy ( V_14 , V_46 , V_25 ) ;
F_27 ( V_47 , V_17 ) ;
V_24 = F_9 ( V_20 , V_23 , 0 ) ;
memcpy ( V_23 -> V_32 , V_47 , V_17 ) ;
}
return V_24 ;
}
static int F_33 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_28 ( V_20 , V_50 , V_6 , & V_23 ) ;
}
static int F_34 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_28 ( V_20 , V_51 , V_6 , & V_23 ) ;
}
static int F_35 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_28 ( V_20 , V_52 , V_6 , & V_23 ) ;
}
static int F_36 ( struct V_19 * V_20 ,
struct V_35 * V_27 , struct V_35 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_11 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_28 ( V_20 , V_53 , V_6 , & V_23 ) ;
}
static int T_3 F_37 ( void )
{
int V_24 ;
if ( ! F_38 ( V_16 , V_54 ) ||
! F_38 ( V_39 , V_54 ) )
return - V_55 ;
V_24 = F_39 ( & V_56 ) ;
if ( V_24 )
goto V_57;
V_24 = F_39 ( & V_58 ) ;
if ( V_24 )
goto V_59;
V_24 = F_39 ( & V_60 ) ;
if ( V_24 )
goto V_61;
V_24 = F_39 ( & V_62 ) ;
if ( V_24 )
goto V_63;
V_24 = F_39 ( & V_64 ) ;
if ( V_24 )
goto V_65;
V_24 = F_39 ( & V_66 ) ;
if ( V_24 )
goto V_67;
if ( F_38 ( V_50 ,
V_54 | V_68 ) &&
F_38 ( V_52 ,
V_54 | V_68 ) ) {
V_24 = F_39 ( & V_69 ) ;
if ( V_24 )
goto V_70;
V_24 = F_39 ( & V_71 ) ;
if ( V_24 )
goto V_72;
V_49 = ( T_1 * ) F_40 ( V_73 ) ;
if ( ! V_49 ) {
V_24 = - V_74 ;
goto V_75;
}
}
V_14:
return V_24 ;
V_75:
F_41 ( & V_71 ) ;
V_72:
F_41 ( & V_69 ) ;
V_70:
F_41 ( & V_66 ) ;
V_67:
F_41 ( & V_64 ) ;
V_65:
F_41 ( & V_62 ) ;
V_63:
F_41 ( & V_60 ) ;
V_61:
F_41 ( & V_58 ) ;
V_59:
F_41 ( & V_56 ) ;
V_57:
goto V_14;
}
static void T_4 F_42 ( void )
{
if ( V_49 ) {
F_41 ( & V_69 ) ;
F_41 ( & V_71 ) ;
F_43 ( ( unsigned long ) V_49 ) ;
}
F_41 ( & V_66 ) ;
F_41 ( & V_64 ) ;
F_41 ( & V_62 ) ;
F_41 ( & V_60 ) ;
F_41 ( & V_58 ) ;
F_41 ( & V_56 ) ;
}
