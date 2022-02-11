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
T_1 * V_32 , struct V_22 * V_23 )
{
int V_24 = F_8 ( V_20 , V_23 ) ;
unsigned int V_25 = V_23 -> V_25 ;
if ( ! V_25 )
goto V_14;
memcpy ( V_32 , V_23 -> V_32 , V_17 ) ;
do {
unsigned int V_26 = V_25 & ~ ( V_17 - 1 ) ;
T_1 * V_14 = V_23 -> V_27 . V_28 . V_29 ;
T_1 * V_15 = V_23 -> V_30 . V_28 . V_29 ;
V_24 = F_11 ( V_21 , V_32 , V_14 , V_15 , V_26 ) ;
if ( V_24 < 0 || V_24 != V_26 )
return - V_31 ;
V_25 &= V_17 - 1 ;
V_24 = F_9 ( V_20 , V_23 , V_25 ) ;
} while ( ( V_25 = V_23 -> V_25 ) );
memcpy ( V_23 -> V_32 , V_32 , V_17 ) ;
V_14:
return V_24 ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_16 , V_6 -> V_3 , & V_23 ) ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_18 , V_6 -> V_3 , & V_23 ) ;
}
static int F_16 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_34 , V_6 -> V_32 , & V_23 ) ;
}
static int F_17 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_35 , V_6 -> V_32 , & V_23 ) ;
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_7 = & V_2 -> V_8 ;
if ( ! ( memcmp ( V_3 , & V_3 [ V_36 ] , V_36 ) &&
memcmp ( & V_3 [ V_36 ] , & V_3 [ V_36 * 2 ] ,
V_36 ) ) &&
( * V_7 & V_11 ) ) {
* V_7 |= V_12 ;
return - V_13 ;
}
memcpy ( V_6 -> V_3 , V_3 , V_4 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 * V_27 , const T_1 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_37 , V_6 -> V_3 , V_27 , V_30 , V_17 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 * V_27 , const T_1 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_38 , V_6 -> V_3 , V_27 , V_30 , V_17 ) ;
}
static int F_21 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_37 , V_6 -> V_3 , & V_23 ) ;
}
static int F_22 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_7 ( V_20 , V_38 , V_6 -> V_3 , & V_23 ) ;
}
static int F_23 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_39 , V_6 -> V_32 , & V_23 ) ;
}
static int F_24 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_10 ( V_20 , V_40 , V_6 -> V_32 , & V_23 ) ;
}
static int F_25 ( struct V_19 * V_20 , long V_21 ,
struct V_5 * V_6 , struct V_22 * V_23 )
{
int V_24 = F_26 ( V_20 , V_23 , V_17 ) ;
unsigned int V_41 , V_26 , V_25 ;
T_1 V_42 [ V_17 ] ;
T_1 * V_14 , * V_15 ;
memcpy ( V_43 , V_23 -> V_32 , V_17 ) ;
while ( ( V_25 = V_23 -> V_25 ) >= V_17 ) {
V_14 = V_23 -> V_27 . V_28 . V_29 ;
V_15 = V_23 -> V_30 . V_28 . V_29 ;
while ( V_25 >= V_17 ) {
V_26 = ( V_25 > V_44 ) ? V_44 :
V_25 & ~ ( V_17 - 1 ) ;
for ( V_41 = V_17 ; V_41 < V_26 ; V_41 += V_17 ) {
memcpy ( V_43 + V_41 , V_43 + V_41 - V_17 ,
V_17 ) ;
F_27 ( V_43 + V_41 , V_17 ) ;
}
V_24 = F_28 ( V_21 , V_6 -> V_3 , V_14 , V_15 , V_26 , V_43 ) ;
if ( V_24 < 0 || V_24 != V_26 )
return - V_31 ;
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
if ( V_25 ) {
V_14 = V_23 -> V_27 . V_28 . V_29 ;
V_15 = V_23 -> V_30 . V_28 . V_29 ;
V_24 = F_28 ( V_21 , V_6 -> V_3 , V_42 , V_15 ,
V_17 , V_43 ) ;
if ( V_24 < 0 || V_24 != V_17 )
return - V_31 ;
memcpy ( V_14 , V_42 , V_25 ) ;
F_27 ( V_43 , V_17 ) ;
V_24 = F_9 ( V_20 , V_23 , 0 ) ;
}
memcpy ( V_23 -> V_32 , V_43 , V_17 ) ;
return V_24 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_25 ( V_20 , V_45 , V_6 , & V_23 ) ;
}
static int F_30 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_25 ( V_20 , V_46 , V_6 , & V_23 ) ;
}
static int F_31 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_25 ( V_20 , V_47 , V_6 , & V_23 ) ;
}
static int F_32 ( struct V_19 * V_20 ,
struct V_33 * V_27 , struct V_33 * V_30 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_13 ( V_20 -> V_2 ) ;
struct V_22 V_23 ;
F_14 ( & V_23 , V_27 , V_30 , V_25 ) ;
return F_25 ( V_20 , V_48 , V_6 , & V_23 ) ;
}
static int T_3 F_33 ( void )
{
int V_24 ;
if ( ! F_34 ( V_16 , V_49 ) ||
! F_34 ( V_37 , V_49 ) )
return - V_50 ;
V_24 = F_35 ( & V_51 ) ;
if ( V_24 )
goto V_52;
V_24 = F_35 ( & V_53 ) ;
if ( V_24 )
goto V_54;
V_24 = F_35 ( & V_55 ) ;
if ( V_24 )
goto V_56;
V_24 = F_35 ( & V_57 ) ;
if ( V_24 )
goto V_58;
V_24 = F_35 ( & V_59 ) ;
if ( V_24 )
goto V_60;
V_24 = F_35 ( & V_61 ) ;
if ( V_24 )
goto V_62;
if ( F_34 ( V_45 ,
V_49 | V_63 ) &&
F_34 ( V_47 ,
V_49 | V_63 ) ) {
V_24 = F_35 ( & V_64 ) ;
if ( V_24 )
goto V_65;
V_24 = F_35 ( & V_66 ) ;
if ( V_24 )
goto V_67;
V_43 = ( T_1 * ) F_36 ( V_68 ) ;
if ( ! V_43 ) {
V_24 = - V_69 ;
goto V_70;
}
}
V_14:
return V_24 ;
V_70:
F_37 ( & V_66 ) ;
V_67:
F_37 ( & V_64 ) ;
V_65:
F_37 ( & V_61 ) ;
V_62:
F_37 ( & V_59 ) ;
V_60:
F_37 ( & V_57 ) ;
V_58:
F_37 ( & V_55 ) ;
V_56:
F_37 ( & V_53 ) ;
V_54:
F_37 ( & V_51 ) ;
V_52:
goto V_14;
}
static void T_4 F_38 ( void )
{
if ( V_43 ) {
F_37 ( & V_64 ) ;
F_37 ( & V_66 ) ;
F_39 ( ( unsigned long ) V_43 ) ;
}
F_37 ( & V_61 ) ;
F_37 ( & V_59 ) ;
F_37 ( & V_57 ) ;
F_37 ( & V_55 ) ;
F_37 ( & V_53 ) ;
F_37 ( & V_51 ) ;
}
