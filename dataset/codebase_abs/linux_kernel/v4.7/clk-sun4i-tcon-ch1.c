static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_6 ) ;
V_6 &= ~ ( V_8 | V_9 ) ;
F_5 ( V_6 , V_4 -> V_6 ) ;
F_6 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_6 ) ;
V_6 |= V_8 | V_9 ;
F_5 ( V_6 , V_4 -> V_6 ) ;
F_6 ( & V_4 -> V_7 , V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_6 ;
V_6 = F_4 ( V_4 -> V_6 ) ;
return V_6 & ( V_8 | V_9 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_6 ;
V_6 = F_4 ( V_4 -> V_6 ) >> V_10 ;
V_6 &= V_6 >> V_11 ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_6 ) ;
V_6 &= ~ ( V_11 << V_10 ) ;
V_6 |= V_12 << V_10 ;
F_5 ( V_6 , V_4 -> V_6 ) ;
F_6 ( & V_4 -> V_7 , V_5 ) ;
return 0 ;
}
static unsigned long F_11 ( unsigned long V_13 ,
unsigned long V_14 ,
T_2 * div ,
bool * V_15 )
{
unsigned long V_16 = 0 ;
T_2 V_17 = 0 , V_18 ;
bool V_19 ;
for ( V_18 = 1 ; V_18 < 16 ; V_18 ++ ) {
T_2 V_20 ;
for ( V_20 = 1 ; V_20 < 3 ; V_20 ++ ) {
unsigned long V_21 ;
V_21 = V_14 / V_18 / V_20 ;
if ( V_21 > V_13 )
continue;
if ( ! V_16 ||
( V_13 - V_21 ) < ( V_13 - V_16 ) ) {
V_16 = V_21 ;
V_17 = V_18 ;
V_19 = V_20 ;
}
}
}
if ( div && V_15 ) {
* div = V_17 ;
* V_15 = V_19 ;
}
return V_16 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
long V_16 = - V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_13 ( V_2 ) ; V_25 ++ ) {
unsigned long V_14 ;
unsigned long V_21 ;
struct V_1 * V_26 ;
V_26 = F_14 ( V_2 , V_25 ) ;
if ( ! V_26 )
continue;
V_14 = F_15 ( V_26 ) ;
V_21 = F_11 ( V_23 -> V_13 , V_14 ,
NULL , NULL ) ;
if ( V_16 < 0 ||
( V_23 -> V_13 - V_21 ) < ( V_23 -> V_13 - V_16 ) ) {
V_16 = V_21 ;
V_23 -> V_27 = V_14 ;
V_23 -> V_28 = V_26 ;
}
}
if ( V_16 < 0 )
return V_16 ;
V_23 -> V_13 = V_16 ;
return 0 ;
}
static unsigned long F_16 ( struct V_1 * V_2 ,
unsigned long V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_6 ;
V_6 = F_4 ( V_4 -> V_6 ) ;
V_14 /= ( V_6 & V_29 ) + 1 ;
if ( V_6 & V_30 )
V_14 /= 2 ;
return V_14 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
bool V_15 ;
T_2 V_31 ;
T_1 V_6 ;
F_11 ( V_13 , V_14 , & V_31 , & V_15 ) ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_6 ) ;
V_6 &= ~ ( V_29 | V_30 ) ;
V_6 |= ( V_31 - 1 ) & V_29 ;
if ( V_15 )
V_6 |= V_30 ;
F_5 ( V_6 , V_4 -> V_6 ) ;
F_6 ( & V_4 -> V_7 , V_5 ) ;
return 0 ;
}
static void T_3 F_18 ( struct V_32 * V_33 )
{
const char * V_34 [ V_35 ] ;
const char * V_36 = V_33 -> V_37 ;
struct V_38 V_39 ;
struct V_3 * V_4 ;
struct V_40 V_41 ;
struct V_42 * V_42 ;
void T_4 * V_6 ;
int V_43 ;
F_19 ( V_33 , L_1 , & V_36 ) ;
V_6 = F_20 ( V_33 , 0 , F_21 ( V_33 ) ) ;
if ( F_22 ( V_6 ) ) {
F_23 ( L_2 , V_36 ) ;
return;
}
V_43 = F_24 ( V_33 , V_34 , V_35 ) ;
if ( V_43 != V_35 ) {
F_23 ( L_3 , V_36 ) ;
goto V_44;
}
V_4 = F_25 ( sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
goto V_44;
V_39 . V_37 = V_36 ;
V_39 . V_46 = & V_47 ;
V_39 . V_48 = V_34 ;
V_39 . V_49 = V_35 ;
V_39 . V_5 = V_50 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_2 . V_39 = & V_39 ;
F_26 ( & V_4 -> V_7 ) ;
V_42 = F_27 ( NULL , & V_4 -> V_2 ) ;
if ( F_22 ( V_42 ) ) {
F_23 ( L_4 , V_36 ) ;
goto V_51;
}
V_43 = F_28 ( V_33 , V_52 , V_42 ) ;
if ( V_43 ) {
F_23 ( L_5 , V_36 ) ;
goto V_53;
}
return;
V_53:
F_29 ( V_42 ) ;
V_51:
F_30 ( V_4 ) ;
V_44:
F_31 ( V_6 ) ;
F_32 ( V_33 , 0 , & V_41 ) ;
F_33 ( V_41 . V_54 , F_34 ( & V_41 ) ) ;
}
